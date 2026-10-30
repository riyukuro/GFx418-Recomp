// Recovered Scaleform 4.1.18 GFx: the DefineMorphShape character (GFx_MorphCharacter). Own header of sfr_gfx_08s3
// (lane sfr24); others may include it and append.
//
// sfr_gfx_04x includes it for GFx_DefineShapeMorphLoader (0x1425c4d00).
#ifndef MS2_SF_GFX_MORPHCHARACTER_H
#define MS2_SF_GFX_MORPHCHARACTER_H

#include "gfx_shapeswf.h"

namespace Scaleform { namespace GFx {

// Two shapes with the same paths and paired styles; the mesh provider blends them by the instance's ratio.
// 0x38 bytes, vftable 0x143191688.
class MorphCharacterDef : public ShapeBaseCharacterDef
{
public:
    MorphCharacterDef();
    virtual ~MorphCharacterDef();

    virtual bool  DefPointTestLocal(const PointF& pt, bool testShape = 0, const DisplayObjectBase* pinst = 0) const;
    virtual RectF GetBoundsLocal(float morphRatio = 0) const;
    virtual RectF GetRectBoundsLocal(float morphRatio = 0) const;

    virtual UInt32 ComputeGeometryHash() const;
    virtual bool   IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const;
    virtual Render::ShapeDataInterface*     GetShape();
    virtual Ptr<Render::ShapeMeshProvider> BindResourcesInStyles(const ResourceBinding& resourceBinding) const;
    virtual bool                           NeedsResolving() const;

    // Parses a DefineMorphShape / DefineMorphShape2 body after the character id.
    void Read(LoadProcess* p, const TagInfo& tagInfo, bool withStyle);

private:
    // One MORPHFILLSTYLE: the start and the end fill.
    void ReadMorphFillStyle(LoadProcess* p, TagType tagType, Render::FillStyleType& fs1, Render::FillStyleType& fs2,
                            bool* needResolve);

    Ptr<ConstShapeWithStyles> pShape1; // +0x28 the start shape
    Ptr<ConstShapeWithStyles> pShape2; // +0x30 the end shape
};

}} // namespace Scaleform::GFx

#endif
