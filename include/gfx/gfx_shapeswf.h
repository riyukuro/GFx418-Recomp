// Recovered Scaleform 4.1.18 GFx: the SWF shape data (GFx_ShapeSwf) and the shape character definitions built on it.
// Own header of the sfr_gfx_08s* units (lane sfr24); others may include it and append.
//
// sfr_gfx_04 declares partial local copies of ShapeDataBase, ConstShapeNoStyles, SwfShapeCharacterDef and
// ImageShapeCharacterDef (it only constructs them); it must not include this header.
#ifndef MS2_SF_GFX_SHAPESWF_H
#define MS2_SF_GFX_SHAPESWF_H

#include "gfx_shapedef.h"
#include "gfx_shape.h"
#include "gfx_stream.h"
#include "../kernel/sf_array.h"
#include "../render/render_boundbox.h"
#include "../render/render_shapedata.h"

namespace Scaleform {

namespace Render {

// The bounds of the fill paths the edge mode selects; empty (inverted 1e30) when no path qualifies.
template<class Transformer>
RectF ComputeBoundsFill(const ShapeDataInterface& shape, const Transformer& trans, BoundEdges edges)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    ExpandBoundsToFill(shape, trans, &bounds, edges);
    return bounds;
}

} // namespace Render

namespace GFx {

class LoadProcess;
class ResourceBinding;
class ImageResource;
class ImageCreator;
class DisplayObjectBase;

typedef Array<Render::FillStyleType, 0x103>   ShapeSwfFillStyleArray;
typedef Array<Render::StrokeStyleType, 0x103> ShapeSwfStrokeStyleArray;

// The stroke flags of a SWF LINESTYLE2 record in the renderer's encoding (exe 0x14265a640).
unsigned ConvertSwfLineStyles(unsigned swfFlags);

// Shape data read from a DefineShape tag: the paths live in the movie's path allocator, the styles in the subclass.
// Vftable 0x14318a3b0 (Read and Clone pure).
class ShapeDataBase : public Render::ShapeDataInterface
{
public:
    enum FlagsType
    {
        Flags_TexturedFill   = 0x01,
        Flags_Sfactor20      = 0x02,
        Flags_NeedsResolving = 0x04,
        Flags_NonZeroFill    = 0x08,
        Flags_ValidBounds    = 0x10,
        Flags_StylesSupport  = 0x40,
        Flags_S9GSupport     = 0x80
    };
    enum EmptyShape { Empty_Shape };

    ShapeDataBase() : Paths(0), Flags(0) {}
    ShapeDataBase(const ShapeDataBase& o) : Render::ShapeDataInterface(), Paths(o.Paths), Flags(o.Flags) {}
    // A shape without paths (exe 0x142659740).
    explicit ShapeDataBase(EmptyShape);

    // Bounds of the outer fill edges (exe 0x14265a4f0).
    void ComputeBound(RectF* r) const;
    // Hit test against the mesh bounds and, with testShape, the fill (exe 0x14265a790).
    bool DefPointTestLocal(Render::ShapeMeshProvider* provider, const PointF& pt, bool testShape = 0,
                           const DisplayObjectBase* pinst = 0) const;

    // Geometry comparison of shapes is not implemented: no hash, never equal (exe 0x14265ab20).
    UInt32 ComputeGeometryHash() const { return 0; }
    bool   IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const;

    virtual unsigned              GetStartingPos() const { return 0; }
    virtual Render::ShapePathType ReadPathInfo(Render::ShapePosInfo* pos, float* coord, unsigned* styles) const;
    virtual Render::PathEdgeType  ReadEdge(Render::ShapePosInfo* pos, float* coord) const;

    virtual bool           Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle) = 0;
    virtual ShapeDataBase* Clone() const                                                              = 0;
    virtual void           BindResourcesInStyles(const ResourceBinding&) {}

    unsigned GetFlags() const { return Flags; }

protected:
    friend class ShapeSwfReader;
    friend class MorphCharacterDef;

    const UByte* Paths; // +0x10 path records in the path allocator
    UByte        Flags; // +0x18
};

// A shape whose styles are not kept (fonts, masks). Vftable 0x14318b708.
class ConstShapeNoStyles : public ShapeDataBase
{
public:
    ConstShapeNoStyles() : ShapeDataBase(Empty_Shape) {}
    // Inlined into the deleting destructor (exe 0x1425ccac0, pinned in sfr_gfx_04).
    virtual ~ConstShapeNoStyles() {}

    virtual unsigned GetFillStyleCount() const { return 0; }
    virtual unsigned GetStrokeStyleCount() const { return 0; }
    virtual void     GetFillStyle(unsigned, Render::FillStyleType*) const {}
    virtual void     GetStrokeStyle(unsigned, Render::StrokeStyleType*) const {}

    virtual bool           Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle);
    virtual ShapeDataBase* Clone() const;
};

// A shape with its fill and stroke styles in one block: the fills, then the strokes. Vftable 0x14318a420.
class ConstShapeWithStyles : public ShapeDataBase
{
public:
    ConstShapeWithStyles() : Styles(0), FillStylesNum(0), StrokeStylesNum(0) {}
    explicit ConstShapeWithStyles(EmptyShape)
        : ShapeDataBase(Empty_Shape), Styles(0), FillStylesNum(0), StrokeStylesNum(0) {}
    ConstShapeWithStyles(const ConstShapeWithStyles& o); // exe 0x142658ea0
    virtual ~ConstShapeWithStyles();                    // exe 0x142659d50

    virtual unsigned GetFillStyleCount() const { return FillStylesNum; }
    virtual unsigned GetStrokeStyleCount() const { return StrokeStylesNum; }
    virtual void     GetFillStyle(unsigned idx, Render::FillStyleType* p) const;
    virtual void     GetStrokeStyle(unsigned idx, Render::StrokeStyleType* p) const { *p = GetStrokes()[idx - 1]; }

    virtual bool           Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle);
    virtual ShapeDataBase* Clone() const;
    virtual void           BindResourcesInStyles(const ResourceBinding& resourceBinding);

    // Copies the styles into a block of its own (exe 0x14265d6a0).
    void SetStyles(unsigned fillStyleCount, const Render::FillStyleType* fillStyles, unsigned strokeStyleCount,
                   const Render::StrokeStyleType* strokeStyles);

protected:
    Render::FillStyleType*   GetFills() const { return (Render::FillStyleType*)Styles; }
    Render::StrokeStyleType* GetStrokes() const
    {
        return (Render::StrokeStyleType*)((UByte*)Styles + sizeof(Render::FillStyleType) * FillStylesNum);
    }

    void*    Styles;          // +0x20
    unsigned FillStylesNum;   // +0x28
    unsigned StrokeStylesNum; // +0x2c
};

// Parser of one DefineShape record: the styles go to the arrays, the paths to the allocator (exe 0x14265b620).
class ShapeSwfReader
{
    ShapeDataBase&           Shape;        // +0
    PathAllocator*           pAllocator;   // +8 the movie's when null
    ShapeSwfFillStyleArray   FillStyles;   // +0x10
    ShapeSwfStrokeStyleArray StrokeStyles; // +0x28

    int ReadFillStyles(LoadProcess* p, TagType tagType);
    int ReadStrokeStyles(LoadProcess* p, TagType tagType);

public:
    ShapeSwfReader(ShapeDataBase& shape, PathAllocator* allocator) : Shape(shape), pAllocator(allocator) {}

    bool Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle);

    unsigned GetFillStyleCount() const { return (unsigned)FillStyles.GetSize(); }
    unsigned GetStrokeStyleCount() const { return (unsigned)StrokeStyles.GetSize(); }
    const Render::FillStyleType*   GetFillStyle(UPInt i) const { return &FillStyles[i]; }
    const Render::StrokeStyleType* GetStrokeStyle(UPInt i) const { return &StrokeStyles[i]; }

private:
    ShapeSwfReader& operator=(const ShapeSwfReader&);
};

// A DefineShape character. Vftable 0x143191060.
class SwfShapeCharacterDef : public ShapeBaseCharacterDef
{
public:
    // Builds the mesh provider of the shape (exe 0x1426597e0).
    SwfShapeCharacterDef(ShapeDataBase* shp);

    virtual bool DefPointTestLocal(const PointF& pt, bool testShape = 0, const DisplayObjectBase* pinst = 0) const;
    virtual RectF GetBoundsLocal(float) const { return pShapeMeshProvider->GetIdentityBounds(); }
    virtual RectF GetRectBoundsLocal(float morphRatio) const { return GetBoundsLocal(morphRatio); }

    virtual UInt32 ComputeGeometryHash() const { return pShape->ComputeGeometryHash(); }
    virtual bool   IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const { return pShape->IsEqualGeometry(cmpWith); }
    virtual Render::ShapeDataInterface* GetShape() { return pShape; }
    virtual Ptr<Render::ShapeMeshProvider> BindResourcesInStyles(const ResourceBinding& resourceBinding) const;
    virtual bool NeedsResolving() const { return (pShape->GetFlags() & ShapeDataBase::Flags_NeedsResolving) != 0; }

protected:
    Ptr<ShapeDataBase> pShape; // +0x28
};

// The shape that shows a bitmap as a filled rectangle. Vftable 0x1431910d8.
class ImageShapeCharacterDef : public ShapeBaseCharacterDef
{
public:
    // exe 0x142658f20
    ImageShapeCharacterDef(ImageResource* pimage, ImageCreator* imgCreator, bool bilinear);

    virtual bool DefPointTestLocal(const PointF& pt, bool testShape = 0, const DisplayObjectBase* pinst = 0) const;
    virtual RectF GetBoundsLocal(float) const { return pShapeMeshProvider->GetIdentityBounds(); }
    virtual RectF GetRectBoundsLocal(float morphRatio) const { return GetBoundsLocal(morphRatio); }

    virtual UInt32 ComputeGeometryHash() const { return 0; }
    virtual bool   IsEqualGeometry(const ShapeBaseCharacterDef&) const { return false; }
    virtual Render::ShapeDataInterface* GetShape() { return pShape; }

protected:
    Ptr<Render::ShapeDataInterface> pShape; // +0x28
};

}} // namespace Scaleform::GFx

#endif
