// Recovered Scaleform 4.1.18 GFx: the shape character definition base (GFx_Shape). Shared header of the
// src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only what the recovered units use so far: the vftable slots up to NeedsResolving and the mesh provider member.
#ifndef MS2_SF_GFX_SHAPEDEF_H
#define MS2_SF_GFX_SHAPEDEF_H

#include "gfx_characterdef.h"
#include "gfx_rendertree.h"
#include "../render/render_meshprovider.h"

namespace Scaleform { namespace GFx {

class MovieDefImpl;
class ResourceBinding;

// A shape character (vftable slots 10..14 after the CharacterDef ones). The shape's mesh provider is shared by every
// instance; a shape with image fills gets its bound provider per movie (cached in the movie's bind data).
//
// (sfr24, GFx_ShapeSwf in sfr_gfx_08s1) Not novtable: the out-of-line destructor (0x142659e00) stores the vftable
// (0x143190fe8) before it drops the provider; the bounds are pure here (slots 7 and 8 are _purecall).
class ShapeBaseCharacterDef : public CharacterDef
{
public:
    virtual ~ShapeBaseCharacterDef();

    virtual unsigned         GetResourceTypeCode() const { return MakeTypeCode(RT_ShapeDef); }
    virtual CharacterDefType GetType() const { return Shape; }
    virtual RectF            GetBoundsLocal(float morphRatio = 0) const     = 0;
    virtual RectF            GetRectBoundsLocal(float morphRatio = 0) const = 0;

    virtual UInt32 ComputeGeometryHash() const                                    = 0;
    virtual bool   IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const      = 0;
    virtual Render::ShapeDataInterface* GetShape()                                = 0;
    // A provider whose image fills are bound through the binding (slot 13); the shared one here (exe 0x14265a2c0,
    // sfr_gfx_08s1).
    virtual Ptr<Render::ShapeMeshProvider> BindResourcesInStyles(const ResourceBinding&) const;
    // True when the fill styles hold images to bind (slot 14).
    virtual bool NeedsResolving() const { return false; }

    // A shape node of the render tree drawing this shape for the movie (0x142636410).
    Ptr<Render::TreeNode> CreateTreeShape(Render::Context& context, MovieDefImpl* defImpl) const;

protected:
    Ptr<Render::ShapeMeshProvider> pShapeMeshProvider; // +0x20
};

}} // namespace Scaleform::GFx

#endif
