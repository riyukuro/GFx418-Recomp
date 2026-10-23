// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the sort key kinds and
// the bundles they build (Render_PrimitiveBundle). Every key points at one static SortKeyInterface per kind; the
// interface creates the entry's bundle on its first update and queues the bundle's render items when drawn. The
// range keys (mask, blend mode, filter, 3D view / projection) open a range on their start key and close it on their
// end key; their bundles only carry the primitive that changes the HAL state.
// Queue unit sfr_render_06 is split along its original sources (06e Render_PrimitiveBundle).
// MS2-UNIT: sfr_render_06e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426bb650-0x1426bdf50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_primitivebundle.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_cacheeffect.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"
#include "ms2/scaleform/include/render/render_meshcache.h"
#include "ms2/scaleform/include/render/render_queue.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"

namespace Scaleform { namespace Render {

// ----- the key interfaces

// a key whose data is a counted object
class SortKeyInterface_RefCountImpl : public SortKeyInterface
{
public:
    SortKeyInterface_RefCountImpl(SortKeyType type, unsigned flags) : SortKeyInterface(type, flags) {}

    virtual void AddRef(SortKeyData data)
    {
        if (data)
            ((RefCountImpl*)data)->AddRef();
    }
    virtual void Release(SortKeyData data)
    {
        if (data)
            ((RefCountImpl*)data)->Release();
    }
};

// shapes of one fill, the data is the PrimitiveFill
class SKI_Primitive : public SortKeyInterface_RefCountImpl
{
public:
    SKI_Primitive() : SortKeyInterface_RefCountImpl(SortKey_PrimitiveFill, SKF_MatchNoOverlap | SKF_MatchSingleOverlap) {}

    virtual bool UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_Primitive Instance;
    static SKI_Primitive Instance3D;
};

// complex meshes of one provider, the data is the MeshProvider
class SKI_ComplexPrimitive : public SortKeyInterface
{
public:
    SKI_ComplexPrimitive() : SortKeyInterface(SortKey_MeshProvider, SKF_MatchNoOverlap) {}

    virtual void AddRef(SortKeyData data)
    {
        if (data)
            ((MeshProvider*)data)->AddRef();
    }
    virtual void Release(SortKeyData data)
    {
        if (data)
            ((MeshProvider*)data)->Release();
    }
    virtual bool UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_ComplexPrimitive Instance;
    static SKI_ComplexPrimitive Instance3D;
};

// the start of a mask; the mask end key takes its place on the range stack
class SKI_MaskStart : public SortKeyInterface
{
public:
    SKI_MaskStart(SortKeyType type, unsigned flags) : SortKeyInterface(type, flags) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual bool UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_MaskStart Instance;
    static SKI_MaskStart InstanceClipped;
};

// the end of the mask's shapes and the pop after its content; the data is the SortKeyMaskType
class SKI_MaskEnd : public SortKeyInterface
{
public:
    SKI_MaskEnd() : SortKeyInterface(SortKey_MaskEnd, SKF_MatchNoOverlap) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual void DrawBundleEntry(SortKeyData data, BundleEntry* p, Renderer2DImpl* r);

    // ends the mask submission or pops the mask, by the item data
    class RQII_EndMask : public RenderQueueItem::Interface
    {
    public:
        virtual void EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp);
    };

    static RQII_EndMask EndMaskItem;
    static SKI_MaskEnd  Instance;
};

// a blend mode change; the start data is the BlendMode, the end data ~0u
class SKI_BlendMode : public SortKeyInterface
{
public:
    SKI_BlendMode(SortKeyType type, unsigned flags) : SortKeyInterface(type, flags) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual void DrawBundleEntry(SortKeyData data, BundleEntry* p, Renderer2DImpl* r);

    // pushes the item's blend mode, or pops it for the end data
    class RQII_BlendMode : public RenderQueueItem::Interface
    {
    public:
        virtual void EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp);
    };

    static RQII_BlendMode BlendModeItem;
    static SKI_BlendMode  InstanceStart;
    static SKI_BlendMode  InstanceEnd;
};

// a filtered range; the start data is the FilterSet
class SKI_Filter : public SortKeyInterface_RefCountImpl
{
public:
    SKI_Filter(SortKeyType type, unsigned flags) : SortKeyInterface_RefCountImpl(type, flags) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual bool UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_Filter InstanceStart;
    static SKI_Filter InstanceEnd;
};

// a 3D view matrix range; the start data is the Matrix3FRef
class SKI_ViewMatrix3D : public SortKeyInterface
{
public:
    SKI_ViewMatrix3D(SortKeyType type, unsigned flags) : SortKeyInterface(type, flags) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual bool UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_ViewMatrix3D InstanceStart;
    static SKI_ViewMatrix3D InstanceEnd;
};

// a 3D projection matrix range; the start data is the Matrix4FRef
class SKI_ProjectionMatrix3D : public SortKeyInterface
{
public:
    SKI_ProjectionMatrix3D(SortKeyType type, unsigned flags) : SortKeyInterface(type, flags) {}

    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey& key);
    virtual bool UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_ProjectionMatrix3D InstanceStart;
    static SKI_ProjectionMatrix3D InstanceEnd;
};

SKI_Primitive          SKI_Primitive::Instance;
SKI_Primitive          SKI_Primitive::Instance3D;
SKI_ComplexPrimitive   SKI_ComplexPrimitive::Instance;
SKI_ComplexPrimitive   SKI_ComplexPrimitive::Instance3D;
SKI_MaskStart          SKI_MaskStart::Instance(SortKey_MaskStart, SKF_RangeStart | SKF_MatchNoOverlap);
SKI_MaskStart          SKI_MaskStart::InstanceClipped(SortKey_MaskStartClipped, SKF_RangeStart);
SKI_MaskEnd::RQII_EndMask SKI_MaskEnd::EndMaskItem;
SKI_MaskEnd            SKI_MaskEnd::Instance;

// by SortKeyMaskType: push, push clipped, end, pop
static SortKeyInterface* SKI_MaskTable[4] =
{
    &SKI_MaskStart::Instance, &SKI_MaskStart::InstanceClipped, &SKI_MaskEnd::Instance, &SKI_MaskEnd::Instance
};

SKI_BlendMode::RQII_BlendMode SKI_BlendMode::BlendModeItem;
SKI_BlendMode          SKI_BlendMode::InstanceStart(SortKey_BlendModeStart,
                                                    SKF_RangeStart | SKF_MatchNoOverlap | SKF_MatchSingleOverlap);
SKI_BlendMode          SKI_BlendMode::InstanceEnd(SortKey_BlendModeEnd, SKF_MatchNoOverlap | SKF_MatchSingleOverlap);
SKI_Filter             SKI_Filter::InstanceStart(SortKey_FilterStart, SKF_RangeStart | SKF_MatchNoOverlap);
SKI_Filter             SKI_Filter::InstanceEnd(SortKey_FilterEnd, SKF_MatchNoOverlap);
SKI_ViewMatrix3D       SKI_ViewMatrix3D::InstanceStart(SortKey_ViewMatrix3DStart, SKF_RangeStart | SKF_MatchNoOverlap);
SKI_ViewMatrix3D       SKI_ViewMatrix3D::InstanceEnd(SortKey_ViewMatrix3DEnd, SKF_MatchNoOverlap);
SKI_ProjectionMatrix3D SKI_ProjectionMatrix3D::InstanceStart(SortKey_ProjectionMatrix3DStart,
                                                             SKF_RangeStart | SKF_MatchNoOverlap);
SKI_ProjectionMatrix3D SKI_ProjectionMatrix3D::InstanceEnd(SortKey_ProjectionMatrix3DEnd, SKF_MatchNoOverlap);

// the key of nothing
static SortKeyInterface SKI_NullInterface(SortKey_None);

// ----- the bundles' constructors and drawing (inlined into the key interfaces below)

// @0x1426bc4b0
ComplexPrimitiveBundle::ComplexPrimitiveBundle() : Bundle(0)
{
}

// @0x1426bcc40
ComplexPrimitiveBundle::~ComplexPrimitiveBundle()
{
}

// @0x1426bc520
FilterBundle::FilterBundle(HAL* hal, FilterSet* filters, bool maskPresent)
    : Bundle(0), Prim(hal, filters, maskPresent)
{
}

// @0x1426bc610
MaskBundle::MaskBundle(HAL* hal, MaskPrimitive::MaskAreaType maskType) : Bundle(0), Prim(hal, maskType)
{
}

// @0x1426bc6c0
PrimitiveBundle::PrimitiveBundle(TreeCacheRoot* tr, const SortKey& key, Renderer2DImpl* r)
    : DrawableBundle(tr, r), Prim(r->GetHAL(), (PrimitiveFill*)key.GetData())
{
}

// @0x1426bc750
ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(HAL* hal, Matrix4FRef* projMatrix) : Bundle(0), Prim(hal)
{
    if (projMatrix)
        Prim.SetProjectionMatrix(*projMatrix);
}

// @0x1426bcac0
ViewMatrix3DBundle::ViewMatrix3DBundle(HAL* hal, Matrix3FRef* viewMatrix) : Bundle(0), Prim(hal)
{
    if (viewMatrix)
        Prim.SetViewMatrix(*viewMatrix);
}

// @0x1426bd6f0
void ComplexPrimitiveBundle::Draw(HAL* hal)
{
    UPInt count = Instances.GetSize();
    for (UPInt i = 0; i < count; i++)
    {
        hal->Draw(RenderQueueItem(this, (void*)i));
        // the following entries of the same mesh are drawn with it
        ComplexMesh* mesh = Instances[i].pMesh;
        while (i < Instances.GetSize() - 1 && Instances[i + 1].pMesh == mesh)
            i++;
    }
}

// ----- SKI_Primitive

// @0x1426bb650
bool SKI_Primitive::UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                      const BundleIterator&)
{
    if (!p->pBundle)
    {
        SortKey key((PrimitiveFill*)data);
        Ptr<PrimitiveBundle> bundle = *SF_HEAP_AUTO_NEW(tr) PrimitiveBundle(tr, key, r);
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bb770
void SKI_Primitive::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl*)
{
    PrimitiveBundle* bundle = (PrimitiveBundle*)p->pBundle.GetPtr();
    if (bundle)
    {
        HAL* hal = bundle->pRenderer2D->GetHAL();
        hal->Draw(RenderQueueItem(&bundle->Prim, 0));
    }
}

// ----- SKI_ComplexPrimitive

// @0x1426bb810
bool SKI_ComplexPrimitive::UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl*,
                                             const BundleIterator&)
{
    if (!p->pBundle)
    {
        Ptr<ComplexPrimitiveBundle> bundle = *SF_HEAP_AUTO_NEW(tr) ComplexPrimitiveBundle();
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bb8f0
void SKI_ComplexPrimitive::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    if (p->pBundle)
        ((ComplexPrimitiveBundle*)p->pBundle.GetPtr())->Draw(r->GetHAL());
}

// ----- SKI_MaskStart

// @0x1426bb9f0
bool SKI_MaskStart::UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                      const BundleIterator&)
{
    if (!p->pBundle)
    {
        MaskPrimitive::MaskAreaType maskType =
            (Type == SortKey_MaskStartClipped) ? MaskPrimitive::Mask_Clipped : MaskPrimitive::Mask_Combinable;
        Ptr<MaskBundle> bundle = *SF_HEAP_AUTO_NEW(tr) MaskBundle(r->GetHAL(), maskType);
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bbb20
SortKeyTransition SKI_MaskStart::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_MaskEnd) ? SKT_Replace : SKT_Skip;
}

// @0x1426bbb30
void SKI_MaskStart::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    MaskBundle* bundle = (MaskBundle*)p->pBundle.GetPtr();
    if (bundle)
    {
        HAL* hal = r->GetHAL();
        hal->Draw(RenderQueueItem(&bundle->Prim, 0));
    }
}

// ----- SKI_MaskEnd

// @0x1426bbba0
void SKI_MaskEnd::RQII_EndMask::EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
{
    if (qp.GetQueueEmitFilter() != RenderQueueProcessor::QPF_All)
        return;
    HAL* hal = qp.GetHAL();
    if ((SPInt)item.GetData() == SortKeyMask_End)
        hal->EndMaskSubmit();
    else if ((SPInt)item.GetData() == SortKeyMask_Pop)
        hal->PopMask();
}

// @0x1426bbc00
SortKeyTransition SKI_MaskEnd::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_MaskEnd) ? SKT_End : SKT_Skip;
}

// @0x1426bbc20
void SKI_MaskEnd::DrawBundleEntry(SortKeyData data, BundleEntry*, Renderer2DImpl* r)
{
    r->GetHAL()->Draw(RenderQueueItem(&EndMaskItem, data));
}

// ----- SKI_BlendMode

// @0x1426bbc80
void SKI_BlendMode::RQII_BlendMode::EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
{
    if (qp.GetQueueEmitFilter() != RenderQueueProcessor::QPF_All)
        return;
    HAL* hal = qp.GetHAL();
    if ((UPInt)item.GetData() == 0xFFFFFFFF)
        hal->PopBlendMode();
    else
        hal->PushBlendMode((BlendMode)(UPInt)item.GetData());
}

// @0x1426bbce0
SortKeyTransition SKI_BlendMode::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_BlendModeEnd && Type == SortKey_BlendModeStart) ? SKT_End : SKT_Skip;
}

// @0x1426bbd00
void SKI_BlendMode::DrawBundleEntry(SortKeyData data, BundleEntry*, Renderer2DImpl* r)
{
    r->GetHAL()->Draw(RenderQueueItem(&BlendModeItem, data));
}

// ----- SKI_Filter

// @0x1426bbd60
SortKeyTransition SKI_Filter::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_FilterEnd && Type == SortKey_FilterStart) ? SKT_End : SKT_Skip;
}

// @0x1426bbd80
bool SKI_Filter::UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles)
{
    if (!p->pBundle)
    {
        // a mask directly inside the filtered range needs the mask stencil while the filter renders
        bool           maskPresent = false;
        BundleIterator it          = ibundles;
        unsigned       depth       = 0;
        for (; it; it++)
        {
            if (depth == 1 &&
                (unsigned)(it->Key.GetType() - SortKey_MaskStart) <= (unsigned)(SortKey_MaskEnd - SortKey_MaskStart))
            {
                maskPresent = true;
                break;
            }
            SortKeyType type = it->Key.GetType();
            if (type == SortKey_FilterEnd)
            {
                if (--depth == 0)
                    break;
            }
            else if (type == SortKey_FilterStart)
                depth++;
        }

        Ptr<FilterBundle> bundle = *SF_HEAP_AUTO_NEW(tr) FilterBundle(r->GetHAL(), (FilterSet*)data, maskPresent);
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bbf50
void SKI_Filter::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    FilterBundle* bundle = (FilterBundle*)p->pBundle.GetPtr();
    if (bundle)
    {
        HAL* hal = r->GetHAL();
        hal->Draw(RenderQueueItem(&bundle->Prim, 0));
    }
}

// ----- SKI_ViewMatrix3D

// @0x1426bbfc0
SortKeyTransition SKI_ViewMatrix3D::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_ViewMatrix3DEnd && Type == SortKey_ViewMatrix3DStart) ? SKT_End : SKT_Skip;
}

// @0x1426bbfe0
bool SKI_ViewMatrix3D::UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                         const BundleIterator&)
{
    if (!p->pBundle)
    {
        Ptr<ViewMatrix3DBundle> bundle = *SF_HEAP_AUTO_NEW(tr) ViewMatrix3DBundle(r->GetHAL(), (Matrix3FRef*)data);
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bc150
void SKI_ViewMatrix3D::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    ViewMatrix3DBundle* bundle = (ViewMatrix3DBundle*)p->pBundle.GetPtr();
    if (bundle)
    {
        HAL* hal = r->GetHAL();
        hal->Draw(RenderQueueItem(&bundle->Prim, 0));
    }
}

// ----- SKI_ProjectionMatrix3D

// @0x1426bc1c0
SortKeyTransition SKI_ProjectionMatrix3D::GetRangeTransition(SortKeyData, const SortKey& key)
{
    return (key.GetType() == SortKey_ProjectionMatrix3DEnd && Type == SortKey_ProjectionMatrix3DStart) ? SKT_End
                                                                                                         : SKT_Skip;
}

// @0x1426bc1e0
bool SKI_ProjectionMatrix3D::UpdateBundleEntry(SortKeyData data, BundleEntry* p, TreeCacheRoot* tr,
                                               Renderer2DImpl* r, const BundleIterator&)
{
    if (!p->pBundle)
    {
        Ptr<ProjectionMatrix3DBundle> bundle =
            *SF_HEAP_AUTO_NEW(tr) ProjectionMatrix3DBundle(r->GetHAL(), (Matrix4FRef*)data);
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426bc370
void SKI_ProjectionMatrix3D::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    ProjectionMatrix3DBundle* bundle = (ProjectionMatrix3DBundle*)p->pBundle.GetPtr();
    if (bundle)
    {
        HAL* hal = r->GetHAL();
        hal->Draw(RenderQueueItem(&bundle->Prim, 0));
    }
}

// ----- SortKey

// @0x1426bc870
SortKey::SortKey(MeshProvider* provider, bool is3D)
{
    Data = provider;
    if (!is3D)
    {
        pImpl = &SKI_ComplexPrimitive::Instance;
        addRef();
    }
    else
    {
        pImpl = &SKI_ComplexPrimitive::Instance3D;
        addRef();
    }
}

// @0x1426bc8c0
SortKey::SortKey(PrimitiveFill* fill, bool is3D)
{
    Data = fill;
    if (!is3D)
    {
        pImpl = &SKI_Primitive::Instance;
        addRef();
    }
    else
    {
        pImpl = &SKI_Primitive::Instance3D;
        addRef();
    }
}

// @0x1426bc910
SortKey::SortKey(SortKeyMaskType maskType)
{
    pImpl = SKI_MaskTable[maskType];
    Data  = (SortKeyData)(SPInt)maskType;
    addRef();
}

// @0x1426bc940
SortKey::SortKey(SortKeyType viewKeyType, const Matrix3FRef* viewMatrix)
{
    if (viewKeyType == SortKey_ViewMatrix3DStart)
        setKey(&SKI_ViewMatrix3D::InstanceStart, (SortKeyData)viewMatrix);
    else
        setKey(&SKI_ViewMatrix3D::InstanceEnd, 0);
}

// @0x1426bc9a0
SortKey::SortKey(SortKeyType projKeyType, const Matrix4FRef* projMatrix)
{
    if (projKeyType == SortKey_ProjectionMatrix3DStart)
        setKey(&SKI_ProjectionMatrix3D::InstanceStart, (SortKeyData)projMatrix);
    else
        setKey(&SKI_ProjectionMatrix3D::InstanceEnd, 0);
}

// @0x1426bca00
SortKey::SortKey(SortKeyType filterKeyType, const FilterSet* filters)
{
    if (filterKeyType == SortKey_FilterStart)
        setKey(&SKI_Filter::InstanceStart, (SortKeyData)filters);
    else
        setKey(&SKI_Filter::InstanceEnd, 0);
}

// @0x1426bca60
SortKey::SortKey(SortKeyType blendKeyType, BlendMode mode)
{
    if (blendKeyType == SortKey_BlendModeStart)
        setKey(&SKI_BlendMode::InstanceStart, (SortKeyData)(SPInt)mode);
    else
        setKey(&SKI_BlendMode::InstanceEnd, (SortKeyData)(UPInt)0xFFFFFFFF);
}

// ----- PrimitiveBundle

// @0x1426bd4d0
void PrimitiveBundle::CheckMatrixConsistency()
{
    unsigned count = Prim.GetMeshCount();
    for (unsigned i = 0; i < count; i++)
    {
        TreeCacheNode* node = Entries[i]->pSourceNode;
        Matrix2F       m    = node->pNode ? node->GetNodeData()->M2D() : Matrix2F::Identity;
        for (TreeCacheNode* parent = node->GetParent(); parent; parent = parent->GetParent())
            m.Append(parent->GetNodeData()->M2D());
    }
}

// @0x1426bda80
void PrimitiveBundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Bundle::InsertEntry(index, entry);
    TreeCacheMeshBase* node = (TreeCacheMeshBase*)entry->pSourceNode;
    Prim.Insert((unsigned)index, (Mesh*)node->GetMesh(), node->M);
}

// @0x1426bdc80
void PrimitiveBundle::RemoveEntries(UPInt index, UPInt count)
{
    Prim.Remove((unsigned)index, (unsigned)count);
    Bundle::RemoveEntries(index, count);
}

// @0x1426bdf00
void PrimitiveBundle::UpdateMesh(BundleEntry* entry)
{
    UPInt index;
    if (findEntryIndex(&index, entry))
        Prim.SetMesh((unsigned)index, (Mesh*)((TreeCacheMeshBase*)entry->pSourceNode)->GetMesh());
}

// ----- ComplexPrimitiveBundle

// MS2-FUNCTIONAL: instanced draw loop: same calls and arguments, register allocation and block order differ
// @0x1426bd7a0
void ComplexPrimitiveBundle::EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
{
    if (qp.GetQueueEmitFilter() != RenderQueueProcessor::QPF_All)
        return;

    UPInt          index = (UPInt)item.GetData();
    InstanceEntry& e     = Instances[index];
    if (qp.GetPrepareItemBuffer()->IsProcessing(&item))
        return;
    ComplexMesh* mesh = e.pMesh;
    if (!mesh)
        return;

    UPInt last = index;
    while (last < Instances.GetSize() - 1 && Instances[last + 1].pMesh == mesh)
        last++;
    qp.GetHAL()->DrawProcessedComplexMeshes(mesh, StrideArray<HMatrix>(&e.M, last - index + 1, sizeof(InstanceEntry)));
}

// MS2-FUNCTIONAL: same logic; the exe copies this before the filter test, scheduling differs
// @0x1426bdad0
RenderQueueItem::QIPrepareResult ComplexPrimitiveBundle::Prepare(RenderQueueItem& item, RenderQueueProcessor& qp,
                                                                 bool waitForCache)
{
    if (qp.GetQueuePrepareFilter() == RenderQueueProcessor::QPF_All)
    {
        UPInt index = (UPInt)item.GetData();
        if (!qp.GetMeshCache()->PrepareComplexMesh(Instances[index].pMesh, waitForCache) &&
            !qp.GetPrepareItemBuffer()->IsProcessing(&item))
        {
            qp.GetPrepareItemBuffer()->StartProcessing(&item);
            return RenderQueueItem::QIP_NeedCache;
        }
        qp.GetPrepareItemBuffer()->ClearItem();
    }
    return RenderQueueItem::QIP_Done;
}

// @0x1426bd840
void ComplexPrimitiveBundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Bundle::InsertEntry(index, entry);
    TreeCacheMeshBase* node = (TreeCacheMeshBase*)entry->pSourceNode;
    InstanceEntry      e(node->M, (ComplexMesh*)node->GetMesh());
    Instances.InsertAt(index, e);
}

// @0x1426bdb40
void ComplexPrimitiveBundle::RemoveEntries(UPInt index, UPInt count)
{
    Instances.RemoveMultipleAt(index, count);
    Bundle::RemoveEntries(index, count);
}

// @0x1426bde90
void ComplexPrimitiveBundle::UpdateMesh(BundleEntry* entry)
{
    UPInt index;
    if (findEntryIndex(&index, entry))
    {
        TreeCacheMeshBase* node = (TreeCacheMeshBase*)entry->pSourceNode;
        InstanceEntry& e = Instances[index];
        e.pMesh = (ComplexMesh*)node->GetMesh();
    }
}

// ----- FilterBundle / MaskBundle

// @0x1426bd940
void FilterBundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Bundle::InsertEntry(index, entry);
    FilterEffect* effect = (FilterEffect*)entry->pSourceNode->Effects.GetEffect(State_Filter);
    HMatrix m = effect->BoundsMatrix;
    Prim.Insert(index, m);
}

// @0x1426bdbe0
void FilterBundle::RemoveEntries(UPInt index, UPInt count)
{
    Prim.Remove((unsigned)index, (unsigned)count);
    Bundle::RemoveEntries(index, count);
}

// @0x1426bd9e0
void MaskBundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Bundle::InsertEntry(index, entry);
    MaskEffect* effect = (MaskEffect*)entry->pSourceNode->Effects.GetEffect(State_MaskNode);
    HMatrix m = effect->BoundsMatrix;
    Prim.Insert(index, m);
}

// @0x1426bdc30
void MaskBundle::RemoveEntries(UPInt index, UPInt count)
{
    Prim.Remove((unsigned)index, (unsigned)count);
    Bundle::RemoveEntries(index, count);
}

}} // namespace Scaleform::Render

// the scalar deleting destructors (the key interfaces' are folded copies) and the vftables
// MS2-PIN: ??_GSKI_Primitive@Render@Scaleform@@UEAAPEAXI@Z 0x1426bb7c0
// MS2-PIN: ??_GSKI_ComplexPrimitive@Render@Scaleform@@UEAAPEAXI@Z 0x1426bb9c0
// MS2-PIN: ??_GSKI_MaskStart@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbb70
// MS2-PIN: ??_GRQII_EndMask@SKI_MaskEnd@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbbd0
// MS2-PIN: ??_GSKI_MaskEnd@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbc50
// MS2-PIN: ??_GRQII_BlendMode@SKI_BlendMode@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbcb0
// MS2-PIN: ??_GSKI_BlendMode@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbd30
// MS2-PIN: ??_GSKI_Filter@Render@Scaleform@@UEAAPEAXI@Z 0x1426bbf90
// MS2-PIN: ??_GSKI_ViewMatrix3D@Render@Scaleform@@UEAAPEAXI@Z 0x1426bc190
// MS2-PIN: ??_GSKI_ProjectionMatrix3D@Render@Scaleform@@UEAAPEAXI@Z 0x1426bc3c0
// MS2-PIN: ??_GSortKeyInterface@Render@Scaleform@@UEAAPEAXI@Z 0x1426bc430
// MS2-PIN: ??_GSortKeyInterface_RefCountImpl@Render@Scaleform@@UEAAPEAXI@Z 0x1426bc480
// MS2-PIN: ??_G?$RefCountBase@VMaskPrimitive@Render@Scaleform@@$0EE@@Scaleform@@UEAAPEAXI@Z 0x1426bccf0
// MS2-PIN: ??_G?$RefCountBase@VProjectionMatrix3DPrimitive@Render@Scaleform@@$0EE@@Scaleform@@UEAAPEAXI@Z 0x1426bcd50
// MS2-PIN: ??_G?$RefCountBase@VViewMatrix3DPrimitive@Render@Scaleform@@$0EE@@Scaleform@@UEAAPEAXI@Z 0x1426bcdb0
// MS2-PIN: ??_GProjectionMatrix3DBundle@Render@Scaleform@@UEAAPEAXI@Z 0x1426bd2b0
// MS2-PIN: ??_GProjectionMatrix3DPrimitive@Render@Scaleform@@UEAAPEAXI@Z 0x1426bd350
// MS2-PIN: ??_GViewMatrix3DBundle@Render@Scaleform@@UEAAPEAXI@Z 0x1426bd3c0
// MS2-PIN: ??_GViewMatrix3DPrimitive@Render@Scaleform@@UEAAPEAXI@Z 0x1426bd460
// MS2-PIN: ??_7SKI_Primitive@Render@Scaleform@@6B@ 0x143192618
// MS2-PIN: ??_7SKI_ComplexPrimitive@Render@Scaleform@@6B@ 0x143192648
// MS2-PIN: ??_7SKI_MaskStart@Render@Scaleform@@6B@ 0x143192678
// MS2-PIN: ??_7RQII_EndMask@SKI_MaskEnd@Render@Scaleform@@6B@ 0x1431926a8
// MS2-PIN: ??_7SKI_MaskEnd@Render@Scaleform@@6B@ 0x1431926c0
// MS2-PIN: ??_7RQII_BlendMode@SKI_BlendMode@Render@Scaleform@@6B@ 0x1431926f0
// MS2-PIN: ??_7SKI_BlendMode@Render@Scaleform@@6B@ 0x143192708
// MS2-PIN: ??_7SKI_Filter@Render@Scaleform@@6B@ 0x143192738
// MS2-PIN: ??_7SKI_ViewMatrix3D@Render@Scaleform@@6B@ 0x143192768
// MS2-PIN: ??_7SKI_ProjectionMatrix3D@Render@Scaleform@@6B@ 0x143192798
// MS2-PIN: ??_7SortKeyInterface@Render@Scaleform@@6B@ 0x1431927c8
// MS2-PIN: ??_7SortKeyInterface_RefCountImpl@Render@Scaleform@@6B@ 0x1431927f8
// MS2-PIN: ??_7?$RefCountBase@VMaskPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x143192880
// MS2-PIN: ??_7MaskPrimitive@Render@Scaleform@@6B?$RefCountBase@VMaskPrimitive@Render@Scaleform@@$0EE@@2@@ 0x143192888
// MS2-PIN: ??_7MaskPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143192890
// MS2-PIN: ??_7?$RefCountBase@VViewMatrix3DPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431928a8
// MS2-PIN: ??_7ViewMatrix3DPrimitive@Render@Scaleform@@6B?$RefCountBase@VViewMatrix3DPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431928b0
// MS2-PIN: ??_7ViewMatrix3DPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x1431928b8
// MS2-PIN: ??_7?$RefCountBase@VProjectionMatrix3DPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431928d0
// MS2-PIN: ??_7ProjectionMatrix3DPrimitive@Render@Scaleform@@6B?$RefCountBase@VProjectionMatrix3DPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431928d8
// MS2-PIN: ??_7ProjectionMatrix3DPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x1431928e0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0ED@@Scaleform@@6B@ 0x1431928f8
// MS2-PIN: ??_7?$RefCountBaseNTS@VBundle@Render@Scaleform@@$0ED@@Scaleform@@6B@ 0x143192900
// MS2-PIN: ??_7Bundle@Render@Scaleform@@6B@ 0x143192908
// MS2-PIN: ??_7DrawableBundle@Render@Scaleform@@6B@ 0x143192928
// MS2-PIN: ??_7PrimitiveBundle@Render@Scaleform@@6B@ 0x143192948
// MS2-PIN: ??_7ComplexPrimitiveBundle@Render@Scaleform@@6BBundle@12@@ 0x143192968
// MS2-PIN: ??_7ComplexPrimitiveBundle@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143192988
// MS2-PIN: ??_7MaskBundle@Render@Scaleform@@6B@ 0x1431929a0
// MS2-PIN: ??_7FilterBundle@Render@Scaleform@@6B@ 0x1431929c0
// MS2-PIN: ??_7ViewMatrix3DBundle@Render@Scaleform@@6B@ 0x1431929e0
// MS2-PIN: ??_7ProjectionMatrix3DBundle@Render@Scaleform@@6B@ 0x143192a00
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919b0
// MS2-PIN: ??_7?$RefCountBase@VFilterPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919f0
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6B?$RefCountBase@VFilterPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431919f8
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143191a00
