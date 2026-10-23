// Recovered Scaleform 4.1.18 Render: the drawable bundles of Render_PrimitiveBundle. Each sort key kind builds one
// kind of bundle (SortKeyInterface::UpdateBundleEntry): simple shapes sharing a fill go into one Primitive, complex
// meshes are drawn one instance run at a time, and the mask / filter / 3D view / projection keys wrap the primitive
// that changes the HAL state around their range.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVEBUNDLE_H
#define MS2_SF_RENDER_PRIMITIVEBUNDLE_H

#include "ms2/scaleform/include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_states.h"

namespace Scaleform { namespace Render {

class TreeCacheRoot;
class Renderer2DImpl;

// A bundle that is drawn by the renderer it was created for; the kind decides how a source node's mesh changes.
class DrawableBundle : public Bundle
{
public:
    DrawableBundle(TreeCacheRoot* tr, Renderer2DImpl* r) : Bundle(0), pRoot(tr), pRenderer2D(r) {}

    virtual void UpdateMesh(BundleEntry* entry) = 0;

protected:
    TreeCacheRoot*  pRoot;         // +0x38
    Renderer2DImpl* pRenderer2D;   // +0x40
};

// The simple shapes of one fill, drawn through one Primitive (0xa8 bytes).
class PrimitiveBundle : public DrawableBundle
{
    friend class SKI_Primitive;
public:
    PrimitiveBundle(TreeCacheRoot* tr, const SortKey& key, Renderer2DImpl* r);   // 0x1426bc6c0

    PrimitiveFill* GetFill() const { return Prim.GetFill(); }

    // walks every mesh's node chain up to the root; checks only (0x1426bd4d0)
    void CheckMatrixConsistency();

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);
    virtual void UpdateMesh(BundleEntry* entry);

protected:
    Primitive Prim;   // +0x48
};

// Complex meshes, each drawn with its own fills; consecutive entries of one mesh are drawn as one instanced call
// (0x58 bytes).
class ComplexPrimitiveBundle : public Bundle, public RenderQueueItem::Interface
{
public:
    struct InstanceEntry
    {
        HMatrix          M;
        Ptr<ComplexMesh> pMesh;

        InstanceEntry() {}
        InstanceEntry(const HMatrix& m, ComplexMesh* mesh) : M(m), pMesh(mesh) {}
    };

    ComplexPrimitiveBundle();    // 0x1426bc4b0
    ~ComplexPrimitiveBundle();   // 0x1426bcc40

    // queues one item per run of equal meshes; the item data is the run's first index
    void Draw(HAL* hal);

    virtual QIPrepareResult Prepare(RenderQueueItem&, RenderQueueProcessor&, bool waitForCache);
    virtual void            EmitToHAL(RenderQueueItem&, RenderQueueProcessor&);

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);
    virtual void UpdateMesh(BundleEntry* entry);

protected:
    ArrayLH<InstanceEntry> Instances;   // +0x40
};

// The mask areas of a mask start key (0x80 bytes).
class MaskBundle : public Bundle
{
    friend class SKI_MaskStart;
public:
    MaskBundle(HAL* hal, MaskPrimitive::MaskAreaType maskType);   // 0x1426bc610

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);

protected:
    MaskPrimitive Prim;   // +0x38
};

// The filtered areas of a filter start key (0x88 bytes).
class FilterBundle : public Bundle
{
    friend class SKI_Filter;
public:
    FilterBundle(HAL* hal, FilterSet* filters, bool maskPresent);   // 0x1426bc520

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);

protected:
    FilterPrimitive Prim;   // +0x38
};

// The 3D view matrix of a view start key (0xa0 bytes).
class ViewMatrix3DBundle : public Bundle
{
    friend class SKI_ViewMatrix3D;
public:
    ViewMatrix3DBundle(HAL* hal, Matrix3FRef* viewMatrix);   // 0x1426bcac0

protected:
    ViewMatrix3DPrimitive Prim;   // +0x40
};

// The 3D projection matrix of a projection start key (0xb0 bytes).
class ProjectionMatrix3DBundle : public Bundle
{
    friend class SKI_ProjectionMatrix3D;
public:
    ProjectionMatrix3DBundle(HAL* hal, Matrix4FRef* projMatrix);   // 0x1426bc750

protected:
    ProjectionMatrix3DPrimitive Prim;   // +0x40
};

}} // namespace Scaleform::Render

#endif
