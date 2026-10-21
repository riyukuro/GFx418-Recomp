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
class __declspec(novtable) ShapeBaseCharacterDef : public CharacterDef
{
public:
    virtual ~ShapeBaseCharacterDef() {}

    virtual CharacterDefType GetType() const { return Shape; }

    virtual UInt32 ComputeGeometryHash() const                                    = 0;
    virtual bool   IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const      = 0;
    virtual void*  GetShape()                                                     = 0; // ShapeDataInterface*
    // A provider whose image fills are bound through the binding (slot 13).
    virtual Ptr<Render::ShapeMeshProvider> BindResourcesInStyles(const ResourceBinding&) const
    {
        return 0;
    }
    // True when the fill styles hold images to bind (slot 14).
    virtual bool NeedsResolving() const { return false; }

    // A shape node of the render tree drawing this shape for the movie (0x142636410).
    Ptr<Render::TreeNode> CreateTreeShape(Render::Context& context, MovieDefImpl* defImpl) const;

protected:
    Render::ShapeMeshProvider* pShapeMeshProvider; // +0x20 (a Ptr in the exe)
};

}} // namespace Scaleform::GFx

#endif
