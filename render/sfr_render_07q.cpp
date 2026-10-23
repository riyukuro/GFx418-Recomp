// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text primitive bundle
// (Render_TextPrimitiveBundle): the sort key all text shares, and the bundle that merges the layers of every text
// field in a run of entries into one primitive per layer type and fill, prepared and drawn through the render queue.
// Queue unit sfr_render_07 is split along its original sources (07q Render_TextPrimitiveBundle).
// MS2-UNIT: sfr_render_07q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f2460-0x1426f3f20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_textprimitivebundle.h"
#include "ms2/scaleform/include/render/render_primitiveprocessor.h"
#include "ms2/scaleform/include/render/render_treecachetext.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"

namespace Scaleform { namespace Render {

// ----- The queue scratch buffers of a text bundle

class TextPrepareBuffer : public RQPrepareBuffer
{
    friend class TextEmitBuffer;
public:
    typedef RenderQueueItem::QIPrepareResult QIPrepareResult;

    void StartPrimitive(RenderQueueItem& item, TextPrimitiveBundle* bundle, TreeCacheText* remaining,
                        TextEmitBuffer* emitBuffer, HAL* hal);
    QIPrepareResult ProcessPrimitive(bool waitForCache);

private:
    TextEmitBuffer*        pEmitBuffer;            // +0x08
    HAL*                   pHal;                   // +0x10
    MeshCache*             pCache;                 // +0x18
    TextPrimitiveBundle*   pBundle;                // +0x20
    UPInt                  ProcessingLayer;        // +0x28, the layer being prepared
    bool                   LayersPinned;           // +0x30
    bool                   LayersFinished;         // +0x31, all layers prepared but text fields remain
    // the text fields not in the layers yet, linked through pNextNoBatch
    TreeCacheText*         pRemainingTextFields;   // +0x38
    PrimitivePrepareBuffer PPBuffer;               // +0x40

    void addTextFieldLayers(bool startFlag);
};

class TextEmitBuffer : public RQEmitBuffer
{
    friend class TextPrepareBuffer;
public:
    enum MaskStatusType
    {
        Mask_NotInUse,
        Mask_Submitting,   // the mask layers are being drawn
        Mask_InUse
    };

    void StartEmitting(void* item, TextPrimitiveBundle* bundle)
    {
        RQEmitBuffer::StartEmitting(item);
        pBundle    = bundle;
        EmitLayer  = 0;
        MaskStatus = Mask_NotInUse;
        PEBuffer.ClearItem();
    }
    void EndEmitting() { ClearItem(); }

    void EmitPrimitive(TextPrepareBuffer* prepareBuffer, HAL* hal);

private:
    TextPrimitiveBundle* pBundle;      // +0x08
    UPInt                EmitLayer;    // +0x10
    MaskStatusType       MaskStatus;   // +0x18
    PrimitiveEmitBuffer  PEBuffer;     // +0x20
};

// ----- The text sort key

class SKI_TextPrimitive : public SortKeyInterface
{
public:
    SKI_TextPrimitive() : SortKeyInterface(SortKey_Text, SKF_MatchNoOverlap) {}

    virtual bool UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r,
                                   const BundleIterator& ibundles);
    virtual void DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r);

    static SKI_TextPrimitive Instance;
    static SKI_TextPrimitive Instance3D;
};

SKI_TextPrimitive SKI_TextPrimitive::Instance;
SKI_TextPrimitive SKI_TextPrimitive::Instance3D;

// @0x1426f2460
bool SKI_TextPrimitive::UpdateBundleEntry(SortKeyData, BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl*,
                                          const BundleIterator&)
{
    if (!p->pBundle)
    {
        Ptr<TextPrimitiveBundle> bundle = *SF_HEAP_AUTO_NEW(tr) TextPrimitiveBundle();
        p->SetBundle(bundle, 0);
    }
    return p->pBundle != 0;
}

// @0x1426f2580
void SKI_TextPrimitive::DrawBundleEntry(SortKeyData, BundleEntry* p, Renderer2DImpl* r)
{
    if (p->pBundle)
        ((TextPrimitiveBundle*)p->pBundle.GetPtr())->Draw(r->GetHAL());
}

// @0x1426f25c0 is SKI_TextPrimitive's deleting destructor (folded with SortKeyInterface's).

// @0x1426f25f0
SortKey::SortKey(SortKeyTextType, bool is3D)
{
    Data = 0;
    if (!is3D)
    {
        pImpl = &SKI_TextPrimitive::Instance;
        addRef();
    }
    else
    {
        pImpl = &SKI_TextPrimitive::Instance3D;
        addRef();
    }
}

// ----- TextPrimitiveBundle

// @0x1426f2650
TextPrimitiveBundle::TextPrimitiveBundle() : Bundle(0)
{
}

// @0x1426f26c0 is the layer array's destructor, @0x1426f3a70 its allocInsertCopy (from the header).

// @0x1426f2740
TextPrimitiveBundle::~TextPrimitiveBundle()
{
}

// @0x1426f27c0 and @0x1426f2830 are the deleting destructors of TextLayerPrimitive and TextPrimitiveBundle.

// @0x1426f28e0
bool TextLayerPrimitive::AddEntry(BundleEntry* e, Mesh* mesh, const HMatrix& m)
{
    if (Insert(GetMeshCount(), mesh, m))
    {
        Entries.PushBack(e);
        return true;
    }
    return false;
}

// @0x1426f2970
void TextEmitBuffer::EmitPrimitive(TextPrepareBuffer* prepareBuffer, HAL* hal)
{
    UPInt endLayer;
    bool  finished = true;

    if (!prepareBuffer->IsProcessing(GetItem()))
        endLayer = pBundle->Layers.GetSize();
    else
    {
        endLayer = prepareBuffer->ProcessingLayer;
        if (endLayer < pBundle->Layers.GetSize())
        {
            endLayer++;
            finished = false;
        }
    }

    for (; EmitLayer < endLayer; EmitLayer++)
    {
        TextLayerPrimitive* p = pBundle->Layers[EmitLayer];
        if (p->Type >= TextLayer_Mask)
        {
            if (p->Type == TextLayer_Mask)
            {
                if (MaskStatus == Mask_NotInUse && pBundle->pMaskPrimitive)
                {
                    hal->PushMask_BeginSubmit(pBundle->pMaskPrimitive);
                    MaskStatus = Mask_Submitting;
                }
            }
            else if (MaskStatus == Mask_Submitting)
            {
                hal->EndMaskSubmit();
                MaskStatus = Mask_InUse;
            }
        }
        p->emitToHAL(p, &prepareBuffer->PPBuffer, &PEBuffer, hal);
    }

    if (finished)
    {
        if (MaskStatus != Mask_NotInUse)
        {
            hal->PopMask();
            MaskStatus = Mask_NotInUse;
        }
        EndEmitting();
    }
    else
        EmitLayer--;
}

// @0x1426f2ab0
void TextPrimitiveBundle::EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
{
    if (qp.GetQueueEmitFilter() != RenderQueueProcessor::QPF_All)
        return;

    TextEmitBuffer* emitBuffer = (TextEmitBuffer*)qp.GetEmitItemBuffer();
    if (!emitBuffer->IsEmitting(&item))
        emitBuffer->StartEmitting(&item, this);
    emitBuffer->EmitPrimitive((TextPrepareBuffer*)qp.GetPrepareItemBuffer(), qp.GetHAL());
}

void TextPrimitiveBundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Bundle::InsertEntry(index, entry);
}

// MS2-FUNCTIONAL: regalloc only (the exe loads the entry into rdx before the pSourceNode load into rcx)
// @0x1426f2c80
void TextLayerPrimitive::PinEntryBatches()
{
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        BundleEntry* e = Entries[i];
        static_cast<TreeCacheText*>(e->pSourceNode)->GetMeshProvider()->Pin();
    }
}

// @0x1426f2cd0
TextPrimitiveBundle::QIPrepareResult TextPrimitiveBundle::Prepare(RenderQueueItem& item, RenderQueueProcessor& qp,
                                                                  bool waitForCache)
{
    if (qp.GetQueuePrepareFilter() != RenderQueueProcessor::QPF_All)
        return RenderQueueItem::QIP_Done;

    TextPrepareBuffer* prepareBuffer = (TextPrepareBuffer*)qp.GetPrepareItemBuffer();
    if (!prepareBuffer->IsProcessing(&item))
        startPrimitive(item, prepareBuffer, qp);
    return prepareBuffer->ProcessPrimitive(waitForCache);
}

// @0x1426f2e00
TextPrepareBuffer::QIPrepareResult TextPrepareBuffer::ProcessPrimitive(bool waitForCache)
{
    if (LayersFinished)
    {
        // the cache ran full with text fields left over: start over with those
        PPBuffer.ClearItem();
        pBundle->clearBatchLayers();
        addTextFieldLayers(false);
        LayersFinished  = false;
        ProcessingLayer = 0;
    }

    for (; ProcessingLayer < pBundle->Layers.GetSize(); ProcessingLayer++)
    {
        TextLayerPrimitive* p = pBundle->Layers[ProcessingLayer];
        if (p->prepare(p, &PPBuffer, &pEmitBuffer->PEBuffer, pHal, pCache, waitForCache) ==
            RenderQueueItem::QIP_NeedCache)
            return RenderQueueItem::QIP_NeedCache;
    }

    if (LayersPinned)
    {
        pBundle->unpinLayerBatches();
        LayersPinned = false;
    }
    if (pRemainingTextFields)
    {
        LayersFinished = true;
        return RenderQueueItem::QIP_NeedCache;
    }
    return RenderQueueItem::QIP_Done;
}

// @0x1426f3000
void TextPrimitiveBundle::RemoveEntries(UPInt index, UPInt count)
{
    for (UPInt i = index; i < index + count; i++)
    {
        TreeCacheText*    textCache = (TreeCacheText*)Entries[i]->pSourceNode;
        TextMeshProvider* tm        = textCache->GetMeshProvider();
        if (tm && tm->GetBundle())
        {
            removeEntryFromLayers(&textCache->SorterShapeNode);
            tm->ClearBundle();
        }
    }
    Bundle::RemoveEntries(index, count);
}

// @0x1426f32f0
bool TextLayerPrimitive::RemoveEntry(BundleEntry* e)
{
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        if (Entries[i] == e)
        {
            Entries.RemoveAt(i);
            Remove((unsigned)i, 1);
            i--;
        }
    }
    return false;
}

// @0x1426f33d0
void TextPrepareBuffer::StartPrimitive(RenderQueueItem& item, TextPrimitiveBundle* bundle, TreeCacheText* remaining,
                                       TextEmitBuffer* emitBuffer, HAL* hal)
{
    StartProcessing(&item);
    pEmitBuffer          = emitBuffer;
    pHal                 = hal;
    pCache               = &hal->GetMeshCache();
    pBundle              = bundle;
    ProcessingLayer      = 0;
    LayersPinned         = false;
    LayersFinished       = false;
    pRemainingTextFields = remaining;
    PPBuffer.ClearItem();
    addTextFieldLayers(true);
}

// MS2-FUNCTIONAL: regalloc only (the exe loads the entry into rdx before the pSourceNode load into rcx)
// @0x1426f3440
void TextLayerPrimitive::UnpinEntryBatches()
{
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        BundleEntry* e = Entries[i];
        static_cast<TreeCacheText*>(e->pSourceNode)->GetMeshProvider()->Unpin();
    }
}

// @0x1426f3490
void TextPrimitiveBundle::UpdateMesh(BundleEntry* entry)
{
    UPInt index;
    if (findEntryIndex(&index, entry))
    {
        TreeCacheText*    textCache = (TreeCacheText*)entry->pSourceNode;
        TextMeshProvider* tm        = textCache->GetMeshProvider();
        if (tm && tm->GetBundle())
        {
            removeEntryFromLayers(&textCache->SorterShapeNode);
            tm->ClearBundle();
        }
    }
}

// @0x1426f3500
bool TextPrimitiveBundle::addAndPinBatchLayers(TreeCacheText* textCache, TextMeshProvider* tm)
{
    BundleEntry* entry      = &textCache->SorterShapeNode;
    unsigned     layerCount = tm->GetLayerCount();
    unsigned     i          = 0;
    UPInt        layerIndex = 0;

    for (; i < layerCount; i++)
    {
        TextMeshLayer&      layer     = tm->GetLayer(i);
        TextLayerPrimitive* primitive = 0;

        // the layers are sorted by type, then fill: find the match or the place to insert one
        for (; layerIndex < Layers.GetSize(); layerIndex++)
        {
            TextLayerPrimitive* p = Layers[layerIndex];
            if (p->Type < layer.Type)
                continue;
            if (p->Type == layer.Type && p->GetFill() == layer.pFill.GetPtr())
            {
                primitive = p;
                break;
            }
            if (p->Type > layer.Type || p->GetFill() > layer.pFill.GetPtr())
                break;
        }

        if (!primitive)
        {
            primitive = SF_HEAP_AUTO_NEW(this) TextLayerPrimitive(textCache->GetHAL(), layer.Type, layer.pFill);
            if (!primitive)
                return false;
            Layers.InsertAt(layerIndex, primitive);
            primitive->Release();
        }

        primitive->AddEntry(entry, layer.pMesh, layer.M);
        tm->Pin();
    }

    if (tm->HasMask())
    {
        if (!pMaskPrimitive)
            pMaskPrimitive = *SF_HEAP_AUTO_NEW(this) MaskPrimitive(textCache->GetHAL(), MaskPrimitive::Mask_Combinable);
        if (pMaskPrimitive)
            pMaskPrimitive->Insert(pMaskPrimitive->GetMaskCount(), tm->UpdateMaskClearBounds(textCache->M));
    }
    return true;
}

// @0x1426f3900
void TextPrepareBuffer::addTextFieldLayers(bool startFlag)
{
    TreeCacheText* first = pRemainingTextFields;

    while (pRemainingTextFields)
    {
        TreeCacheText* next = pRemainingTextFields->pNextNoBatch;
        if (!LayersPinned)
        {
            pBundle->pinLayerBatches();
            LayersPinned = true;
        }

        TextMeshProvider* tm = pRemainingTextFields->GetMeshProvider();
        if (!tm)
        {
            tm = pRemainingTextFields->CreateMeshProvider();
            if (!tm)
                break;
        }
        tm->AddToInUseList();
        if (pBundle->addAndPinBatchLayers(pRemainingTextFields, tm))
            tm->SetBundle(pBundle, &pRemainingTextFields->SorterShapeNode);

        pRemainingTextFields->pNextNoBatch = 0;
        pRemainingTextFields               = next;
    }

    // nothing fit even after a flush: give up on the rest
    if (!startFlag && first == pRemainingTextFields)
        pRemainingTextFields = 0;
}

// MS2-FUNCTIONAL: regalloc only (the exe loads the entry into rdx before the pSourceNode load into rcx)
// @0x1426f3b10
void TextPrimitiveBundle::clearBatchLayers()
{
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        TextMeshProvider* tm = ((TreeCacheText*)Entries[i]->pSourceNode)->GetMeshProvider();
        if (tm)
            tm->ClearBundle();
    }
    Layers.Clear();
    pMaskPrimitive.Clear();
}

// @0x1426f3bf0
void TextPrimitiveBundle::removeEntryFromLayers(BundleEntry* e)
{
    for (UPInt i = 0; i < Layers.GetSize(); i++)
    {
        Layers[i]->RemoveEntry(e);
        if (Layers[i]->GetMeshCount() == 0)
        {
            Layers.RemoveAt(i);
            i--;
        }
    }

    if (pMaskPrimitive)
    {
        TextMeshProvider* tm = ((TreeCacheText*)e->pSourceNode)->GetMeshProvider();
        if (tm && tm->HasMask())
        {
            HMatrix        bounds   = tm->GetMaskClearBounds();
            const HMatrix* matrices = pMaskPrimitive->GetMaskAreaMatrices();
            for (UPInt i = 0; i < pMaskPrimitive->GetMaskCount(); i++)
            {
                if (matrices[i].pHandle == bounds.pHandle)
                {
                    pMaskPrimitive->Remove(i, 1);
                    break;
                }
            }
        }
        if (pMaskPrimitive->GetMaskCount() == 0)
            pMaskPrimitive.Clear();
    }
}

// @0x1426f3e30
void TextPrimitiveBundle::startPrimitive(RenderQueueItem& item, TextPrepareBuffer* prepareBuffer,
                                         RenderQueueProcessor& qp)
{
    // the fields already in the layers only need their glyphs kept; the others are added
    TreeCacheText* remaining = 0;
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        TreeCacheText*    textCache = (TreeCacheText*)Entries[i]->pSourceNode;
        TextMeshProvider* tm        = textCache->GetMeshProvider();
        if (tm && tm->GetBundle() == this)
            tm->AddToInUseList();
        else
        {
            textCache->pNextNoBatch = remaining;
            remaining               = textCache;
        }
    }
    prepareBuffer->StartPrimitive(item, this, remaining, (TextEmitBuffer*)qp.GetEmitItemBuffer(), qp.GetHAL());
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7SKI_TextPrimitive@Render@Scaleform@@6B@ 0x143194090
// MS2-PIN: ??_7TextLayerPrimitive@Render@Scaleform@@6B?$RefCountBase@VPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431940c0
// MS2-PIN: ??_7TextLayerPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x1431940c8
// MS2-PIN: ??_7TextPrimitiveBundle@Render@Scaleform@@6BBundle@12@@ 0x1431940e0
// MS2-PIN: ??_7TextPrimitiveBundle@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143194100
// (the base vftables the unit's ctors / dtors instantiate; the template ones are folded in the exe)
// MS2-PIN: ??_7SortKeyInterface@Render@Scaleform@@6B@ 0x1431927c8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0ED@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VBundle@Render@Scaleform@@$0ED@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Bundle@Render@Scaleform@@6B@ 0x143192908
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919b0
// MS2-PIN: ??_7?$RefCountBase@VMaskPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x143192880
// MS2-PIN: ??_7MaskPrimitive@Render@Scaleform@@6B?$RefCountBase@VMaskPrimitive@Render@Scaleform@@$0EE@@2@@ 0x143192888
// MS2-PIN: ??_7MaskPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143192890
// (the deleting dtor at 0x1426f2830, slot 0 of the Bundle vftable)
// MS2-PIN: ??_GTextPrimitiveBundle@Render@Scaleform@@UEAAPEAXI@Z 0x1426f2830
