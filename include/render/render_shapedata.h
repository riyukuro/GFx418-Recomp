// Recovered Scaleform 4.1.18 Render: shape data definitions (fill/stroke styles, the path reading interface) and the
// float shape builder ShapeDataFloat that DrawableImage::Draw(Image*) fills with one textured rectangle.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64): FillStyleType 0x10, ShapeDataFloatTempl: vftable +0, RefCount +8,
// Status +0x10, Fills +0x18, Strokes +0x30, Data +0x48 (the path byte stream).
// Bodies: StartLayer and PathDataEncoder::WriteChar instances in sfr_gfx_05f (linked into the 0x1425eeef0 gap); the
// ArrayLH_POD<UByte> instance (the morph shapes of ShapeMeshProvider) in sfr_render_03d.
#ifndef MS2_SF_RENDER_SHAPEDATA_H
#define MS2_SF_RENDER_SHAPEDATA_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_fillmode.h"

namespace Scaleform { namespace Render {

class ComplexFill;
struct DashArray;
class ImageBase;
class GradientData;

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

    // (appended for sfr_render_03d) a reader positioned at pos, nothing decoded yet
    ShapePosInfo(unsigned pos)
        : Pos(pos), StartX(0), StartY(0), LastX(0), LastY(0), FillBase(0), StrokeBase(0), NumFillBits(0),
          NumStrokeBits(0), Fill0(0), Fill1(0), Stroke(0), Sfactor(1.0f), Initialized(false)
    {
    }
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

    // (appended for sfr_render_03d) reads the rest of the current path, returning its edge count
    unsigned CountPathEdges(ShapePosInfo* pos) const
    {
        float    coords[Edge_MaxCoord];
        unsigned count = 0;
        while (ReadEdge(pos, coords) != Edge_EndPath)
            ++count;
        return count;
    }
};

// Appends path records to a byte container.
template<class ContainerType>
class PathDataEncoder
{
public:
    PathDataEncoder(ContainerType& data) : Data(&data) {}

    void WriteChar(char v) { Data->PushBack(UByte(v)); }

    // (appended for sfr_render_03d)
    // An unsigned of up to 30 bits: the low two bits of the first byte give the count of bytes that follow,
    // the value is stored above them, low bits first.
    unsigned WriteUInt30(unsigned v)
    {
        if (v < (1u << 6))
        {
            Data->PushBack(UByte(v << 2));
            return 1;
        }
        if (v < (1u << 14))
        {
            Data->PushBack(UByte((v << 2) | 1));
            Data->PushBack(UByte(v >> 6));
            return 2;
        }
        if (v < (1u << 22))
        {
            Data->PushBack(UByte((v << 2) | 2));
            Data->PushBack(UByte(v >> 6));
            Data->PushBack(UByte(v >> 14));
            return 3;
        }
        Data->PushBack(UByte((v << 2) | 3));
        Data->PushBack(UByte(v >> 6));
        Data->PushBack(UByte(v >> 14));
        Data->PushBack(UByte(v >> 22));
        return 4;
    }

    // the four bytes of v in memory order
    void WriteFloat(float v)
    {
        const UByte* bytes = (const UByte*)&v;
        Data->PushBack(bytes[0]);
        Data->PushBack(bytes[1]);
        Data->PushBack(bytes[2]);
        Data->PushBack(bytes[3]);
    }

private:
    ContainerType* Data;
};

// (appended for sfr_render_03d) reads back what PathDataEncoder wrote
template<class ContainerType>
class PathDataDecoder
{
public:
    PathDataDecoder(const ContainerType& data) : Data(&data) {}

    char ReadChar(unsigned pos) const { return (char)Data->ValueAt(pos); }

    // returns the number of bytes used
    unsigned ReadUInt30(unsigned pos, unsigned* v) const
    {
        unsigned lead = UByte(Data->ValueAt(pos));
        unsigned r;
        switch (lead & 3)
        {
        case 0:
            *v = lead >> 2;
            return 1;
        case 1:
            r  = lead >> 2;
            *v = r | (Data->ValueAt(pos + 1) << 6);
            return 2;
        case 2:
            r  = lead >> 2;
            r |= Data->ValueAt(pos + 1) << 6;
            *v = r | (Data->ValueAt(pos + 2) << 14);
            return 3;
        }
        r  = lead >> 2;
        r |= Data->ValueAt(pos + 1) << 6;
        r |= Data->ValueAt(pos + 2) << 14;
        *v = r | (Data->ValueAt(pos + 3) << 22);
        return 4;
    }

    float ReadFloat(unsigned pos) const
    {
        float v = 0;
        UByte* bytes = (UByte*)&v;
        bytes[0] = Data->ValueAt(pos);
        bytes[1] = Data->ValueAt(pos + 1);
        bytes[2] = Data->ValueAt(pos + 2);
        bytes[3] = Data->ValueAt(pos + 3);
        return v;
    }

private:
    const ContainerType* Data;
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

    // (appended for sfr_render_03d: the morph shapes of ShapeMeshProvider, ContainerType ArrayLH_POD<UByte>)
    ShapeDataFloatTempl(ContainerType* data, unsigned startingPos)
        : Status(Status_Clean), Data(data), StartingPos(startingPos), StartX(0), StartY(0), LastX(0), LastY(0)
    {
    }

    unsigned AddFillStyle(const FillStyleType& fill)
    {
        Fills.PushBack(fill);
        return (unsigned)Fills.GetSize();
    }
    unsigned AddStrokeStyle(const StrokeStyleType& stroke)
    {
        Strokes.PushBack(stroke);
        return (unsigned)Strokes.GetSize();
    }

    // a path record: tag, the three styles, then the MoveTo
    void StartPath(unsigned fill0, unsigned fill1, unsigned stroke)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        if (Status == Status_Clean)
            StartLayer();
        encoder.WriteChar(Tag_NewPath);
        encoder.WriteUInt30(fill0);
        encoder.WriteUInt30(fill1);
        encoder.WriteUInt30(stroke);
        Status = Status_StartPath;
    }
    void MoveTo(float x, float y)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_MoveTo);
        encoder.WriteFloat(x);
        encoder.WriteFloat(y);
        StartX = x;
        StartY = y;
        LastX  = x;
        LastY  = y;
        Status = Status_MoveTo;
    }
    void LineTo(float x, float y)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_LineTo);
        encoder.WriteFloat(x);
        encoder.WriteFloat(y);
        Status = Status_EdgeTo;
        LastX = x;
        LastY = y;
    }
    void QuadTo(float cx, float cy, float ax, float ay)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_QuadTo);
        encoder.WriteFloat(cx);
        encoder.WriteFloat(cy);
        encoder.WriteFloat(ax);
        encoder.WriteFloat(ay);
        Status = Status_EdgeTo;
        LastX = ax;
        LastY = ay;
    }
    void CubicTo(float c1x, float c1y, float c2x, float c2y, float ax, float ay)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_CubicTo);
        encoder.WriteFloat(c1x);
        encoder.WriteFloat(c1y);
        encoder.WriteFloat(c2x);
        encoder.WriteFloat(c2y);
        encoder.WriteFloat(ax);
        encoder.WriteFloat(ay);
        Status = Status_EdgeTo;
        LastX = ax;
        LastY = ay;
    }
    // drops the styles and the recorded path data (the container itself stays)
    void Clear()
    {
        Status = Status_Clean;
        Fills.Clear();
        Strokes.Clear();
        Data->Clear();
        StartX = StartY = 0;
        LastX = LastY = 0;
    }
    void EndPath()
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_EndPath);
        Status = Status_EndPath;
    }
    // closes the open path and terminates the data (once; an empty shape gets nothing)
    void EndShape()
    {
        if (Status == Status_EndShape || Status == Status_Clean)
            return;
        if (Status != Status_EndPath)
            EndPath();
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_EndShape);
        Status = Status_EndShape;
    }

    virtual unsigned GetFillStyleCount() const   { return (unsigned)Fills.GetSize(); }
    virtual unsigned GetStrokeStyleCount() const { return (unsigned)Strokes.GetSize(); }
    virtual void     GetFillStyle(unsigned idx, FillStyleType* p) const     { *p = Fills[idx - 1]; }
    virtual void     GetStrokeStyle(unsigned idx, StrokeStyleType* p) const { *p = Strokes[idx - 1]; }
    virtual unsigned GetStartingPos() const      { return StartingPos; }

    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
    {
        if (pos->Pos >= Data->GetSize())
            return Shape_EndShape;

        ShapePathType type = Shape_NewPath;
        PathDataDecoder<ContainerType> reader(*Data);
        char tag = reader.ReadChar(pos->Pos);
        pos->Pos++;
        if (tag == Tag_EndShape)
            return Shape_EndShape;
        if (tag == Tag_NewLayer)
        {
            type = Shape_NewLayer;
            tag  = reader.ReadChar(pos->Pos);   // the Tag_NewPath that follows
            pos->Pos++;
        }
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[0]);
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[1]);
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[2]);
        tag = reader.ReadChar(pos->Pos);        // Tag_MoveTo
        pos->Pos++;
        coord[0] = reader.ReadFloat(pos->Pos);
        pos->Pos += 4;
        coord[1] = reader.ReadFloat(pos->Pos);
        pos->Pos += 4;
        return type;
    }

    virtual PathEdgeType ReadEdge(ShapePosInfo* pos, float* coord) const
    {
        PathDataDecoder<ContainerType> reader(*Data);
        PathEdgeType edge = Edge_EndPath;
        char tag = reader.ReadChar(pos->Pos);
        pos->Pos++;
        if (tag != Tag_EndPath)
        {
            // the end point, then the control point(s) of a curve
            edge = Edge_LineTo;
            coord[0] = reader.ReadFloat(pos->Pos);
            pos->Pos += 4;
            coord[1] = reader.ReadFloat(pos->Pos);
            pos->Pos += 4;
            if (tag == Tag_QuadTo || tag == Tag_CubicTo)
            {
                edge = Edge_QuadTo;
                coord[2] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
                coord[3] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
            }
            if (tag == Tag_CubicTo)
            {
                edge = Edge_CubicTo;
                coord[4] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
                coord[5] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
            }
        }
        return edge;
    }

    float GetLastX() const { return LastX; }
    float GetLastY() const { return LastY; }

private:
    DataStatus               Status;        // +0x10
    ArrayLH<FillStyleType>   Fills;         // +0x18
    ArrayLH<StrokeStyleType> Strokes;       // +0x30
    ContainerType*           Data;          // +0x48
    unsigned                 StartingPos;   // +0x50
    float                    StartX, StartY;
    float                    LastX, LastY;
};

// (appended for the shape cache nodes, sfr_render_03f) StrokeStyleType::Flags
enum StrokeStyleFlags
{
    StrokeFlag_StrokeHinting = 0x01,
    StrokeScaling_Normal     = 0x00,
    StrokeScaling_Horizontal = 0x02,
    StrokeScaling_Vertical   = 0x04,
    StrokeScaling_None       = 0x06,
    StrokeScaling_Mask       = 0x06
};

// (appended for the shape cache nodes, sfr_render_03f; members from the shape mesh provider, sfr_render_03d)
// An image or gradient fill: the source, its placement and how it is sampled.
class ComplexFill : public RefCountBase<ComplexFill, Stat_Default_Mem>
{
public:
    Ptr<ImageBase>    pImage;        // +0x10
    Ptr<GradientData> pGradient;     // +0x18
    Matrix2F          ImageMatrix;   // +0x20
    ImageFillMode     FillMode;      // +0x40
    unsigned          BindIndex;     // +0x44
};
// dash and gap lengths of a dashed stroke
struct DashArray : public RefCountBase<DashArray, Stat_Default_Mem>
{
    float    Dashes[16];
    float    DashStart;
    unsigned DashCount;
};

}} // namespace Scaleform::Render

#endif
