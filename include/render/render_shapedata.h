// Recovered Scaleform 4.1.18 Render: shape data definitions (fill/stroke styles, the path reading interface) and the
// float shape builder ShapeDataFloat that DrawableImage::Draw(Image*) fills with one textured rectangle.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64): FillStyleType 0x10, ShapeDataFloatTempl: vftable +0, RefCount +8,
// Status +0x10, Fills +0x18, Strokes +0x30, Data +0x48 (the path byte stream).
// Bodies: StartLayer and PathDataEncoder::WriteChar instances in sfr_gfx_05f (linked into the 0x1425eeef0 gap).
#ifndef MS2_SF_RENDER_SHAPEDATA_H
#define MS2_SF_RENDER_SHAPEDATA_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_array.h"

namespace Scaleform { namespace Render {

class ComplexFill;
struct DashArray;

// Reader state while walking the paths of a shape.
struct ShapePosInfo
{
    unsigned Pos;
    int      StartX, StartY;
    int      LastX, LastY;
    unsigned FillBase, StrokeBase;
    unsigned NumFillBits, NumStrokeBits;
    unsigned Fill0, Fill1, Stroke;
    float    Sfactor;
    bool     Initialized;
};

enum ShapePathType
{
    Shape_EndShape = 0,
    Shape_NewPath  = 1,
    Shape_NewLayer = 2   // a new path that also starts a layer
};

enum PathEdgeType
{
    Edge_EndPath  = 0,
    Edge_LineTo   = 1,
    Edge_QuadTo   = 2,
    Edge_CubicTo  = 3,
    Edge_MaxCoord = 6    // coordinates one ReadEdge may return
};

struct FillStyleType
{
    UInt32           Color;
    Ptr<ComplexFill> pFill;
};

struct StrokeStyleType
{
    float            Width;
    float            Units;   // 1 for pixels, 1/20 for twips
    unsigned         Flags;
    float            Miter;
    UInt32           Color;
    Ptr<ComplexFill> pFill;
    Ptr<DashArray>   pDashes;
};

// Source of fill/stroke styles and path data for the tessellator.
class ShapeDataInterface : public RefCountBase<ShapeDataInterface, Stat_Default_Mem>
{
public:
    virtual bool          IsEmpty() const { return false; }
    virtual unsigned      GetFillStyleCount() const                                       = 0;
    virtual unsigned      GetStrokeStyleCount() const                                     = 0;
    virtual void          GetFillStyle(unsigned idx, FillStyleType* p) const              = 0;   // idx 1-based
    virtual void          GetStrokeStyle(unsigned idx, StrokeStyleType* p) const          = 0;   // idx 1-based
    virtual unsigned      GetStartingPos() const                                          = 0;
    virtual void          Rewind() const {}
    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const = 0;
    virtual PathEdgeType  ReadEdge(ShapePosInfo* pos, float* coord) const                 = 0;
    virtual void          SkipPathData(ShapePosInfo* pos) const
    {
        float coords[Edge_MaxCoord];
        while (ReadEdge(pos, coords) != Edge_EndPath)
            ;
    }
};

// Appends path records to a byte container.
template<class ContainerType>
class PathDataEncoder
{
public:
    PathDataEncoder(ContainerType& data) : Data(&data) {}

    void WriteChar(char v) { Data->PushBack(UByte(v)); }

private:
    ContainerType* Data;
};

// Shape built from float coordinates: layers of paths, each a tag byte followed by its data.
template<class ContainerType>
class ShapeDataFloatTempl : public ShapeDataInterface
{
    enum DataStatus
    {
        Status_Clean,
        Status_StartLayer,
        Status_StartPath,
        Status_MoveTo,
        Status_EdgeTo,
        Status_EndPath,
        Status_EndShape
    };
    enum DataTags
    {
        Tag_NewLayer,
        Tag_NewPath,
        Tag_MoveTo,
        Tag_LineTo,
        Tag_QuadTo,
        Tag_CubicTo,
        Tag_EndPath,
        Tag_EndShape
    };

public:
    void StartLayer()
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_NewLayer);
        Status = Status_StartLayer;
    }

private:
    DataStatus               Status;        // +0x10
    ArrayLH<FillStyleType>   Fills;         // +0x18
    ArrayLH<StrokeStyleType> Strokes;       // +0x30
    ContainerType*           Data;          // +0x48
    unsigned                 StartingPos;   // +0x50
    float                    StartX, StartY;
    float                    LastX, LastY;
};

}} // namespace Scaleform::Render

#endif
