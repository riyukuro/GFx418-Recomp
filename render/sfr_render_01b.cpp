// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 Render: ContextImpl (Context,
// Snapshot, EntryTable, RTHandle, RenderNotify) and the Renderer2D front end.
// Queue unit sfr_render_01 is split along its original sources (sfr_render_01 Render_Image, 01b Render_Context +
// Renderer2D).
// MS2-UNIT: sfr_render_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14257e560-0x1425822b0 .text$mn
#include <string.h>
#include "ms2/scaleform/include/render/render_context.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_glyphcache.h"

namespace Scaleform { namespace Render {

// ---------------------------------------------------------------------------------------------------------------
// Renderer2D: thin front end over Renderer2DImpl

// @0x142581fe0
Renderer2D::Renderer2D(HAL* hal)
{
    pImpl = SF_HEAP_AUTO_NEW(this) Renderer2DImpl(hal);
}

// @0x142582070
Renderer2D::~Renderer2D()
{
    delete pImpl;
}

// @0x142582210
bool Renderer2D::BeginFrame() { return pImpl->BeginFrame(); }

// @0x1425821f0
void Renderer2D::BeginDisplay(Color bg, const Viewport& vp) { pImpl->BeginDisplay(bg, vp); }

// @0x142582250
void Renderer2D::EndFrame() { pImpl->EndFrame(); }

// @0x142582230
void Renderer2D::Display(TreeRoot* root) { pImpl->Draw(root); }

// @0x142582270
Context::RenderNotify* Renderer2D::GetContextNotify() const { return pImpl; }

// @0x142582280
GlyphCacheConfig* Renderer2D::GetGlyphCacheConfig() const { return pImpl->GetGlyphCache(); }

// @0x1425822a0
HAL* Renderer2D::GetHAL() const { return pImpl->GetHAL(); }

}} // namespace Scaleform::Render

namespace Scaleform { namespace Render { namespace ContextImpl {

// ---------------------------------------------------------------------------------------------------------------
// Snapshot: one captured frame of the context's entry tree (class body is private to this file in the original)

class Snapshot : public ListNode<Snapshot>, public NewOverrideBase<StatRender_Context_Mem>
{
public:
    Context*                    pContext;
    List<SnapshotPage>          SnapshotPages;
    ChangeBuffer                Changes;
    EntryChange*                pFreeChangeNodes;           // recycled change records (singly linked)
    List<Entry::PropagateNode>  PropagateEntrys;
    EntryList                   DestroyedNodes;
    bool                        ForceUpdateImagesFlag;

    struct HeapNode : public ListNode<HeapNode>, public NewOverrideBase<StatRender_Context_Mem>
    {
        LinearHeap ChangeHeap;
        HeapNode(MemoryHeap* heap) : ChangeHeap(heap) {}
    };
    List<HeapNode>              Heaps;                      // more than one after Merge

    Snapshot(Context* context, MemoryHeap* heap);
    ~Snapshot();

    EntryChange* AddChangeItem(Entry* entry, unsigned bits);
    inline void  FreeChangeItem(EntryChange* change);

    LinearHeap& GetChangeHeap() { return Heaps.GetFirst()->ChangeHeap; }
    void AddToPropagate(Entry* e) { PropagateEntrys.PushBack(&e->PNode); }
    void RemoveFromPropagate(Entry* e)
    {
        e->PNode.RemoveNode();
        e->PNode.Clear();
    }

    void Merge(Snapshot* older);
};

inline EntryPage* Entry::getEntryPage() const
{
    return (EntryPage*)((UPInt)this & ~(UPInt)(EntryPageAllocAlign - 1));
}
inline Snapshot* Entry::getSnapshot() const { return getEntryPage()->pSnapshot; }

// @0x142580240
Context* Entry::getContext() const { return getSnapshot()->pContext; }

Entry* Entry::PropagateNode::GetEntry()
{
    return (Entry*)((UPInt)this - (UPInt) & (((Entry*)0)->PNode));
}

Snapshot*     EntryRef::GetSnapshot() const            { return pPage->pSnapshot; }
SnapshotPage* EntryRef::GetSnapshotPage() const        { return pPage->pSnapshotPage; }
SnapshotPage* EntryRef::GetDisplaySnapshotPage() const { return pPage->pDisplaySnapshotPage; }
void EntryRef::SetData_KeepDestroyedBit(EntryData* data) { pPage->pSnapshotPage->SetData_KeepDestroyedBit(Index, data); }
EntryData*& EntryRef::GetDataRef() const               { return pPage->pSnapshotPage->pData[Index]; }
bool EntryRef::IsDestroyed() const                     { return pPage->pSnapshotPage->IsDestroyed(Index); }

// @0x142581700
void Entry::destroyHelper()
{
    EntryRef     ref(this);
    Snapshot*    snap   = ref.GetSnapshot();
    EntryData*   data   = ref.GetData();
    EntryChange* change = pChange;

    data->ReleaseNodes();
    if (PNode.IsAdded())
        snap->RemoveFromPropagate(this);

    if (change)
    {
        data->Destroy();
        if (change->IsNewNode())
        {
            // created and destroyed within the same frame: nobody has seen it, free it right away
            if (hasRTHandle())
            {
                Lock::Locker guard(snap->pContext->getLock());
                snap->pContext->clearRTHandle(this);
            }
            SF_FREE(data);
            snap->pContext->Table.FreeEntry(this);
        }
        else
        {
            ref.GetSnapshotPage()->MarkAsDestroyed(ref.GetIndex());
            snap->DestroyedNodes.PushBack(this);
        }
        snap->FreeChangeItem(change);
    }
    else
    {
        // the render thread may still show it: keep it until that snapshot retires
        ref.GetSnapshotPage()->MarkAsDestroyed(ref.GetIndex());
        snap->DestroyedNodes.PushBack(this);
    }
}

// @0x142581430
void Entry::addToPropagateImpl() { getSnapshot()->AddToPropagate(this); }

// @0x142581a40
EntryData* Entry::getWritableData(unsigned bits)
{
    EntryRef    ref(this);
    EntryData*& slot = ref.GetDataRef();
    if (!pChange)
    {
        // first change this frame: copy the data into the snapshot's change heap (the slot is updated in place)
        Snapshot* snap = ref.GetSnapshot();
        slot    = slot->ConstructCopy(snap->GetChangeHeap());
        pChange = snap->AddChangeItem(this, bits);
    }
    else
    {
        pChange->ChangeBits |= bits;
    }
    return slot;
}

EntryData::~EntryData() {}

// @0x14257f3d0
void EntryPage::AddEntriesToList(EntryList* list)
{
    for (UPInt n = 0; n < PageEntryCount; n++)
        list->PushBack(&Entries[n]);
}

// @0x142580cc0
void EntryPage::RemoveEntriesFromList(EntryList* list)
{
    for (UPInt n = 0; n < PageEntryCount; n++)
        list->Remove(&Entries[n]);
}

// @0x14257f950
bool EntryTable::AllocEntryPage()
{
    EntryPage* page = (EntryPage*)SF_HEAP_MEMALIGN(pHeap, EntryPageAllocSize, EntryPageAllocAlign, StatRender_Context_Mem);
    if (!page)
        return false;
    memset(page, 0, EntryPageAllocSize);
    page->pSnapshotPage = SnapshotPage::Alloc(pHeap, page);
    if (!page->pSnapshotPage)
    {
        SF_HEAP_FREE(pHeap, page);
        return false;
    }
    page->pDisplaySnapshotPage = 0;
    page->pSnapshot            = pActiveSnapshot;
    page->UseCount             = 0;
    page->AddEntriesToList(&FreeNodes);
    EntryPages.PushBack(page);
    return true;
}

// @0x142580110
void EntryTable::FreeEntryPage(EntryPage* page)
{
    Lock::Locker guard(pContext->getLock());
    page->RemoveNode();
    page->RemoveEntriesFromList(&FreeNodes);
    // the page's snapshot page is re-read after each step (the exe reloads it)
    page->pSnapshotPage->ClearEntryPagePointers();
    if (page->pSnapshotPage->pNext)
        page->pSnapshotPage->RemoveNode();
    page->pSnapshotPage->Free();
    SF_HEAP_FREE(pHeap, page);
}

// @0x14257f800
Entry* EntryTable::AllocEntry(EntryData* data)
{
    if (FreeNodes.IsEmpty() && !AllocEntryPage())
        return 0;
    Entry* e = FreeNodes.GetFirst();
    FreeNodes.Remove(e);
    EntryRef ref(e);
    ref.GetEntryPage()->UseCount++;
    ref.GetDataRef() = data;
    return e;
}

// @0x14257ffc0
void EntryTable::FreeEntry(Context::Entry* e)
{
    FreeNodes.PushFront(e);
    EntryRef ref(e);
    ref.GetDataRef() = 0;
    if (--ref.GetEntryPage()->UseCount == 0)
        FreeEntryPage(ref.GetEntryPage());
}

void EntryTable::GetActiveSnapshotPages(List<SnapshotPage>* out)
{
    for (EntryPage* page = EntryPages.GetFirst(); !EntryPages.IsNull(page); page = (EntryPage*)page->pNext)
        out->PushBack(page->pSnapshotPage);
}

// @0x142580690
void EntryTable::NextSnapshot(Snapshot* snap)
{
    for (EntryPage* page = EntryPages.GetFirst(); !EntryPages.IsNull(page); page = (EntryPage*)page->pNext)
    {
        page->pSnapshotPage = page->pSnapshotPage->Clone(pHeap, page->pSnapshotPage);
        page->pSnapshot     = snap;
    }
    SetActiveSnapshot(snap);
}

// @0x14257f7b0
SnapshotPage* SnapshotPage::Alloc(MemoryHeap* heap, EntryPage* owner)
{
    SnapshotPage* sp = (SnapshotPage*)SF_HEAP_MEMALIGN(heap, sizeof(SnapshotPage), 16, StatRender_Context_Mem);
    if (!sp)
        return 0;
    sp->pNext = sp->pPrev = 0;
    sp->pEntryPage         = owner;
    sp->pOlderSnapshotPage = 0;
    sp->pNewerSnapshotPage = 0;
    return sp;
}

// @0x14257fdf0
SnapshotPage* SnapshotPage::Clone(MemoryHeap* heap, SnapshotPage* src)
{
    SnapshotPage* sp = (SnapshotPage*)SF_HEAP_MEMALIGN(heap, sizeof(SnapshotPage), 16, StatRender_Context_Mem);
    if (!sp)
        return 0;
    sp->pNext = sp->pPrev = 0;
    sp->pEntryPage         = src->pEntryPage;
    sp->pOlderSnapshotPage = src;
    sp->pNewerSnapshotPage = 0;
    memcpy(sp->pData, src->pData, sizeof(EntryData*) * PageEntryCount);
    src->pNewerSnapshotPage = sp;
    return sp;
}

void SnapshotPage::Free()
{
    if (pNewerSnapshotPage)
        pNewerSnapshotPage->pOlderSnapshotPage = pOlderSnapshotPage;
    if (pOlderSnapshotPage)
        pOlderSnapshotPage->pNewerSnapshotPage = pNewerSnapshotPage;
    SF_FREE(this);
}

void SnapshotPage::ClearEntryPagePointers()
{
    SnapshotPage* sp = this;
    while (sp->pNewerSnapshotPage)
        sp = sp->pNewerSnapshotPage;
    do
    {
        sp->pEntryPage = 0;
        sp = sp->pOlderSnapshotPage;
    } while (sp);
}

// @0x14257e870
Snapshot::Snapshot(Context* context, MemoryHeap* heap)
    : pContext(context), pFreeChangeNodes(0), ForceUpdateImagesFlag(false)
{
    Heaps.PushBack(SF_HEAP_NEW(heap) HeapNode(heap));
}

// @0x14257ecf0
Snapshot::~Snapshot()
{
    while (!Heaps.IsEmpty())
    {
        HeapNode* h = Heaps.GetFirst();
        h->RemoveNode();
        delete h;
    }
    while (!SnapshotPages.IsEmpty())
    {
        SnapshotPage* sp = SnapshotPages.GetFirst();
        sp->RemoveNode();
        sp->Free();
    }
}

// @0x14257f300
EntryChange* Snapshot::AddChangeItem(Entry* entry, unsigned bits)
{
    EntryChange* c;
    if (pFreeChangeNodes)
    {
        c = pFreeChangeNodes;
        pFreeChangeNodes = c->pNextFreeNode;
    }
    else
    {
        c = Changes.AddItem();
    }
    c->pNode      = entry;
    c->ChangeBits = bits;
    return c;
}

void Snapshot::FreeChangeItem(EntryChange* c)
{
    c->pNode         = 0;
    c->pNextFreeNode = pFreeChangeNodes;
    pFreeChangeNodes = c;
}

// @0x142580300
void Snapshot::Merge(Snapshot* older)
{
    for (ChangeBuffer::Page* pg = older->Changes.GetFirstPage(); pg; pg = pg->pNext)
    {
        for (unsigned n = 0; n < pg->GetSize(); n++)
        {
            EntryChange& c = pg->GetItem(n);
            if (!c.pNode)
                continue;
            EntryRef   ref(c.pNode);
            EntryData* oldData = ref.GetSnapshotPage()->pOlderSnapshotPage->pData[ref.GetIndex()];
            if (ref.GetData() == oldData)
            {
                AddChangeItem(c.pNode, c.ChangeBits);
                continue;
            }
            if (!c.IsNewNode())
            {
                if (ref.GetCleanData() == oldData)
                {
                    oldData->CopyTo(c.pNode->GetNative());
                    ref.SetData_KeepDestroyedBit(c.pNode->GetNative());
                }
                oldData->Destroy();
            }
            if (c.pNode->GetChange() && !ref.IsDestroyed())
                c.pNode->GetChange()->ChangeBits |= (c.ChangeBits & ~Change_Context_NewNode);
        }
    }
    if (older->ForceUpdateImagesFlag)
        ForceUpdateImagesFlag = older->ForceUpdateImagesFlag;
    DestroyedNodes.PushListToFront(older->DestroyedNodes);
    Heaps.PushListToFront(older->Heaps);
}

// ---------------------------------------------------------------------------------------------------------------
// RTHandle

// @0x14257e6f0
RTHandle::HandleData::HandleData(Entry* entry, Context* context)
    : pContextLock(context->pCaptureLock), State(State_PreCapture), pEntry(entry)
{
}

// @0x14257eb40
RTHandle::HandleData::~HandleData()
{
    Lock::Locker guard(&pContextLock->LockObject);
    if (pContextLock->pContext && pEntry)
    {
        pEntry->clearHasRTHandle();
        RemoveNode();
    }
}

// @0x14257e760
RTHandle::RTHandle(Entry* entry)
{
    if (!entry)
        return;
    Context* context = entry->getContext();
    pData = *SF_NEW HandleData(entry, context);
    Lock::Locker guard(context->getLock());
    entry->setHasRTHandle();
    context->RTHandleList.PushBack(pData);
}

RTHandle::~RTHandle() {}

// @0x1425805a0
bool RTHandle::NextCapture(RenderNotify* render)
{
    if (!pData)
        return false;
    Lock* lk = &pData->pContextLock->LockObject;
    lk->DoLock();
    Context* context = pData->pContextLock->pContext;
    if (!context || pData->State == State_Dead)
    {
        lk->Unlock();
        return false;
    }
    Snapshot* shown = 0;
    if (!context->nextCapture_LockScope(&shown, render, Context::Capture_OnceAFrame))
    {
        pData->pContextLock->pContext = 0;
        lk->Unlock();
        return false;
    }
    if (pData->State == State_PreCapture)
        pData->State = State_Valid;
    bool valid = (pData->State == State_Valid);
    lk->Unlock();
    if (shown)
        context->nextCapture_NotifyChanges(shown, render);
    return valid;
}

// @0x142580250
Entry* RTHandle::GetRenderEntry() const
{
    return (pData && pData->State == State_Valid) ? pData->pEntry : 0;
}

// ---------------------------------------------------------------------------------------------------------------
// RenderNotify / ContextCaptureNotify

// @0x14257ec60
RenderNotify::~RenderNotify() { ReleaseAllContextData(); }

void RenderNotify::NewCapture(Context* context, bool)
{
    if (context->pRenderer == this)
        return;
    context->pRenderer = this;
    ActiveContextSet.PushBack(&context->RenderNode);
}

void RenderNotify::ContextReleased(Context* context)
{
    context->RenderNode.RemoveNode();
    context->pRenderer = 0;
    context->NextCaptureCalledInFrame = false;
}

// @0x142581190
void RenderNotify::ServiceQueues()
{
    ContextNode* node = ActiveContextSet.GetFirst();
    while (!ActiveContextSet.IsNull(node))
    {
        ContextNode* cur = node;
        node = node->pNext;
        if (cur->pContext->needRenderShutdown())
            cur->pContext->ShutdownRendering(this);
    }
}

// @0x142580be0
void RenderNotify::ReleaseAllContextData()
{
    while (!ActiveContextSet.IsEmpty())
        ActiveContextSet.GetFirst()->pContext->ShutdownRendering(this);
}

// @0x14257ff00
void RenderNotify::EndFrameContextNotify()
{
    for (ContextNode* node = ActiveContextSet.GetFirst(); !ActiveContextSet.IsNull(node); node = node->pNext)
        node->pContext->endFrame();
}

// @0x14257eac0
ContextCaptureNotify::~ContextCaptureNotify()
{
    if (pOwnedContext)
        pOwnedContext->RemoveCaptureNotify(this);
}

// ---------------------------------------------------------------------------------------------------------------
// Context

// @0x14257e560
Context::Context(MemoryHeap* heap)
    : pHeap(heap), Table(getThis(), heap), pRenderer(0), NextCaptureCalledInFrame(false), DIChangesRequired(false),
      ShutdownRequested(false), pShutdownEvent(0), RenderNode(getThis())
{
    pCaptureLock     = *SF_NEW ContextLock(this);
    CreateThreadId   = GetCurrentThreadId();
    SetCaptureThreadId(CreateThreadId);
    MultiThreadedUse = false;

    pSnapshots[SS_Active]     = SF_HEAP_NEW(pHeap) Snapshot(this, pHeap);
    pSnapshots[SS_Captured]   = pSnapshots[SS_Displaying] = pSnapshots[SS_Finalizing] = 0;
    FinalizedFrameId                = 0;
    SnapshotFrameIds[SS_Active]     = 1;
    SnapshotFrameIds[SS_Captured]   = 0;
    SnapshotFrameIds[SS_Displaying] = 0;
    SnapshotFrameIds[SS_Finalizing] = 0;
    Table.SetActiveSnapshot(pSnapshots[SS_Active]);
    CaptureCalled = false;
}

// @0x14257e9d0
Context::~Context()
{
    Shutdown(true);
    destroySnapshot(pSnapshots[SS_Finalizing]);
    destroySnapshot(pSnapshots[SS_Displaying]);
    destroySnapshot(pSnapshots[SS_Captured]);
    if (pSnapshots[SS_Active])
    {
        Table.GetActiveSnapshotPages(&pSnapshots[SS_Active]->SnapshotPages);
        destroySnapshot(pSnapshots[SS_Active]);
    }
    while (!CaptureNotifyList.IsEmpty())
    {
        ContextCaptureNotify* n = CaptureNotifyList.GetFirst();
        n->pOwnedContext = 0;
        n->RemoveNode();
    }
}

// @0x142581520
Entry* Context::createEntryHelper(EntryData* data)
{
    if (!data)
        return 0;
    Entry* e = Table.AllocEntry(data);
    if (!e)
    {
        data->Destroy();
        SF_FREE(data);
        return 0;
    }
    EntryChange* c = pSnapshots[SS_Active]->AddChangeItem(e, (unsigned)Change_Context_NewNode);
    e->Init(data, c);
    e->AddToPropagate();
    return e;
}

// @0x142581920
void Context::destroySnapshot(Snapshot* snap)
{
    if (!snap)
        return;
    for (SnapshotPage* sp = snap->SnapshotPages.GetFirst(); !snap->SnapshotPages.IsNull(sp); sp = sp->pNext)
        if (sp->pEntryPage)
            sp->pEntryPage->pTempPage = sp;

    for (ChangeBuffer::Page* pg = snap->Changes.GetFirstPage(); pg; pg = pg->pNext)
    {
        for (unsigned n = 0; n < pg->GetSize(); n++)
        {
            EntryChange& c = pg->GetItem(n);
            if (!c.pNode || c.IsNewNode())
                continue;
            EntryRef ref(c.pNode);
            ref.GetEntryPage()->pTempPage->pData[ref.GetIndex()]->Destroy();
        }
    }
    destroyNativeNodes(snap->DestroyedNodes);
    delete snap;
}

// @0x142581880
void Context::destroyNativeNodes(EntryList& list)
{
    while (!list.IsEmpty())
    {
        Entry* e = list.GetFirst();
        EntryList::Remove(e);
        e->GetNative()->Destroy();
        SF_FREE(e->GetNative());
        e->ClearNative();
        Table.FreeEntry(e);
    }
}

// @0x142581460
void Context::clearRTHandle(Entry* entry)
{
    for (RTHandle::HandleData* d = RTHandleList.GetFirst(); !RTHandleList.IsNull(d); d = d->pNext)
    {
        if (d->pEntry != entry)
            continue;
        d->RemoveNode();
        d->State  = RTHandle::State_Dead;
        d->pEntry = 0;
        entry->clearHasRTHandle();
        return;
    }
}

// @0x1425814c0
void Context::clearRTHandleList()
{
    while (!RTHandleList.IsEmpty())
    {
        RTHandle::HandleData* d = RTHandleList.GetFirst();
        d->RemoveNode();
        d->State = RTHandle::State_Dead;
        if (d->pEntry)
            d->pEntry->clearHasRTHandle();
        d->pEntry = 0;
    }
}

// @0x142580270
bool Context::HasChanges() const
{
    Snapshot* a = pSnapshots[SS_Active];
    return !a->Changes.IsEmpty() || !a->DestroyedNodes.IsEmpty() || DIChangesRequired;
}

// @0x14257fa30
bool Context::Capture()
{
    PropagateChangesUp();
    if (ShutdownRequested)
        return false;

    Lock::Locker guard(getLock());
    handleFinalizingSnaphot();

    Snapshot* active = pSnapshots[SS_Active];
    Table.GetActiveSnapshotPages(&active->SnapshotPages);
    if (pSnapshots[SS_Captured])
    {
        // the renderer skipped the previous capture: fold it into this one
        active->Merge(pSnapshots[SS_Captured]);
        delete pSnapshots[SS_Captured];
    }
    pSnapshots[SS_Captured]       = active;
    SnapshotFrameIds[SS_Captured] = SnapshotFrameIds[SS_Active];

    for (ChangeBuffer::Page* pg = active->Changes.GetFirstPage(); pg; pg = pg->pNext)
        for (unsigned n = 0; n < pg->GetSize(); n++)
        {
            EntryChange& c = pg->GetItem(n);
            if (c.pNode)
                c.pNode->SetChange(0);
        }

    Snapshot* next = SF_HEAP_NEW(pHeap) Snapshot(this, pHeap);
    Table.NextSnapshot(next);
    pSnapshots[SS_Active] = next;
    SnapshotFrameIds[SS_Active]++;

    if (Snapshot* shown = pSnapshots[SS_Displaying])
    {
        for (ChangeBuffer::Page* pg = shown->Changes.GetFirstPage(); pg; pg = pg->pNext)
            for (unsigned n = 0; n < pg->GetSize(); n++)
            {
                EntryChange& c = pg->GetItem(n);
                Entry*       e = c.pNode;
                if (!e || c.IsNewNode())
                    continue;
                EntryRef      ref(e);
                unsigned      idx   = ref.GetIndex();
                SnapshotPage* newer = ref.GetDisplaySnapshotPage()->pNewerSnapshotPage;
                EntryData*    d     = newer->GetCleanData(idx);
                if (ref.GetDisplaySnapshotPage()->pData[idx] == d)
                {
                    d->CopyTo(e->GetNative());
                    newer->SetData_KeepDestroyedBit(idx, e->GetNative());
                }
            }
    }

    CaptureCalled = true;
    for (ContextCaptureNotify* n = CaptureNotifyList.GetFirst(); !CaptureNotifyList.IsNull(n); n = n->pNext)
        n->OnCapture();
    return true;
}

// @0x142581af0
void Context::handleFinalizingSnaphot()
{
    if (!pSnapshots[SS_Finalizing])
        return;
    Snapshot* fin = pSnapshots[SS_Finalizing];
    for (ChangeBuffer::Page* pg = pSnapshots[SS_Finalizing]->Changes.GetFirstPage(); pg; pg = pg->pNext)
    {
        for (unsigned n = 0; n < pg->GetSize(); n++)
        {
            EntryChange& c = pg->GetItem(n);
            if (!c.pNode || c.IsNewNode())
                continue;
            Entry*        e   = c.pNode;
            EntryRef      ref(e);
            unsigned      idx = ref.GetIndex();
            SnapshotPage* old = ref.GetDisplaySnapshotPage()->pOlderSnapshotPage;
            if (old->pData[idx] == ref.GetCleanData())
                ref.SetData_KeepDestroyedBit(e->GetNative());
            old->pData[idx]->Destroy();
        }
    }
    destroyNativeNodes(fin->DestroyedNodes);
    delete fin;
    pSnapshots[SS_Finalizing] = 0;
    FinalizedFrameId = SnapshotFrameIds[SS_Finalizing];
}

// @0x142581230
void Context::Shutdown(bool wait)
{
    bool mustWait;
    ContextCaptureNotify* n = CaptureNotifyList.GetFirst();
    while (!CaptureNotifyList.IsNull(n))
    {
        ContextCaptureNotify* next = n->pNext;
        n->OnShutdown();
        n = next;
    }
    DIChangesRequired = false;

    for (;;)
    {
        mustWait = false;
        {
            Lock::Locker guard(getLock());
            handleFinalizingSnaphot();
            ShutdownRequested = true;
            if (wait)
            {
                if (pRenderer)
                {
                    if (MultiThreadedUse)
                        mustWait = true;
                    else
                        shutdownRendering_NoLock();
                }
                if (!mustWait)
                {
                    clearRTHandleList();
                    pCaptureLock->pContext = 0;
                }
            }
        }
        if (!mustWait)
            break;

        // the render thread still holds our data: ask it to release and wait for the event
        Event done;
        {
            Lock::Locker guard(getLock());
            if (pRenderer)
            {
                pShutdownEvent = &done;
                pRenderer->PushRTServiceQueuesCommand();
            }
            else
            {
                mustWait = false;
            }
        }
        if (mustWait)
            done.Wait();
    }
}

// @0x1425802a0
bool Context::IsShutdownComplete() const
{
    Lock::Locker guard(getLock());
    return ShutdownRequested && pRenderer == 0;
}

// @0x142581c40
bool Context::nextCapture_LockScope(Snapshot** shownOut, RenderNotify* notify, CaptureMode mode)
{
    Lock::Locker guard(getLock());
    if (mode == Capture_OnceAFrame && NextCaptureCalledInFrame)
        return true;
    if (ShutdownRequested)
    {
        clearRTHandleList();
        shutdownRendering_NoLock();
        return false;
    }
    if (CreateThreadId != GetCurrentThreadId())
        MultiThreadedUse = true;
    if (notify && mode == Capture_OnceAFrame)
        NextCaptureCalledInFrame = true;

    if (!pSnapshots[SS_Captured])
    {
        if (notify)
            notify->NewCapture(this, false);
        return true;
    }

    List<SnapshotPage>& pages = pSnapshots[SS_Captured]->SnapshotPages;
    for (SnapshotPage* sp = pages.GetFirst(); !pages.IsNull(sp); sp = pages.GetNext(sp))
        if (sp->pEntryPage)
            sp->pEntryPage->pDisplaySnapshotPage = sp;

    pSnapshots[SS_Finalizing] = pSnapshots[SS_Displaying];
    pSnapshots[SS_Displaying] = pSnapshots[SS_Captured];
    pSnapshots[SS_Captured]   = 0;
    SnapshotFrameIds[SS_Finalizing] = SnapshotFrameIds[SS_Displaying];
    SnapshotFrameIds[SS_Displaying] = SnapshotFrameIds[SS_Captured];

    if (notify)
    {
        *shownOut = pSnapshots[SS_Displaying];
        notify->NewCapture(this, true);
    }
    ContextCaptureNotify* n = CaptureNotifyList.GetFirst();
    while (!CaptureNotifyList.IsNull(n))
    {
        ContextCaptureNotify* next = n->pNext;
        n->OnNextCapture(notify);
        n = next;
    }
    DIChangesRequired = false;
    return true;
}

// @0x142580540
bool Context::NextCapture(RenderNotify* notify, CaptureMode mode)
{
    Snapshot* shown = 0;
    bool ok = nextCapture_LockScope(&shown, notify, mode);
    if (shown)
        nextCapture_NotifyChanges(shown, notify);
    return ok;
}

// @0x142581dd0
void Context::nextCapture_NotifyChanges(Snapshot* shown, RenderNotify* notify)
{
    if (!shown)
        return;
    notify->EntryChanges(*this, shown->Changes, shown->ForceUpdateImagesFlag);
    shown->ForceUpdateImagesFlag = false;

    Entry* e = shown->DestroyedNodes.GetFirst();
    if (shown->DestroyedNodes.IsNull(e))
        return;
    do
    {
        notify->EntryDestroy(e);
        e->SetRenderDataAsBAD();
        e = EntryList::GetNext(e);
    } while (!shown->DestroyedNodes.IsNull(e));

    e = shown->DestroyedNodes.GetFirst();
    Lock::Locker guard(getLock());
    do
    {
        if (e->hasRTHandle())
            clearRTHandle(e);
        e = EntryList::GetNext(e);
    } while (!shown->DestroyedNodes.IsNull(e));
}

// @0x14257ff60
void Context::ForceUpdateImages()
{
    if (Snapshot* a = pSnapshots[SS_Active])
        a->ForceUpdateImagesFlag = true;
}

void Context::SetCaptureThreadId(ThreadId) {}

// @0x14257f2a0
void Context::AddCaptureNotify(ContextCaptureNotify* notify)
{
    Lock::Locker guard(getLock());
    notify->pOwnedContext = this;
    CaptureNotifyList.PushBack(notify);
}

// @0x142580c70
void Context::RemoveCaptureNotify(ContextCaptureNotify* notify)
{
    Lock::Locker guard(getLock());
    notify->RemoveNode();
    notify->pOwnedContext = 0;
}

// @0x1425813e0
void Context::ShutdownRendering(RenderNotify*)
{
    Lock::Locker guard(getLock());
    if (CreateThreadId != GetCurrentThreadId())
        MultiThreadedUse = true;
    shutdownRendering_NoLock();
}

// @0x142581ef0
void Context::shutdownRendering_NoLock()
{
    if (!pRenderer || !pSnapshots[SS_Displaying])
        return;
    Snapshot* shown = pSnapshots[SS_Displaying];
    for (SnapshotPage* sp = shown->SnapshotPages.GetFirst(); !shown->SnapshotPages.IsNull(sp); sp = sp->pNext)
    {
        EntryPage* page = sp->pEntryPage;
        if (!page)
            continue;
        for (unsigned n = 0; n < PageEntryCount; n++)
        {
            Entry* e = &page->Entries[n];
            if (e->GetRenderDataClean())
                pRenderer->EntryFlush(e);
        }
    }
    pRenderer->ContextReleased(this);
    if (pShutdownEvent)
    {
        pShutdownEvent->SetEvent();
        pShutdownEvent = 0;
    }
}

// @0x142580810
void Context::PropagateChangesUp()
{
    Snapshot* a = pSnapshots[SS_Active];
    DepthUpdateArrayPOD<Entry::PropagateNode*> byDepth(pHeap, 0);

    // bucket the dirty entries by tree depth, then walk deepest first so parents see their children's results
    Entry::PropagateNode* node = a->PropagateEntrys.GetFirst();
    while (!a->PropagateEntrys.IsNull(node))
    {
        Entry::PropagateNode* next = node->pNext;
        unsigned depth = node->GetEntry()->CalcDepth();
        byDepth.Link(depth, &node->pNext, node);
        node->pPrev = (Entry::PropagateNode*)1;
        node = next;
    }
    a->PropagateEntrys.Clear();

    for (unsigned d = byDepth.GetDepthUsed() - 1; d + 1 > 0; d--)
    {
        for (node = byDepth.Get(d); node; )
        {
            Entry* e = node->GetEntry();
            if (e->GetReadOnlyDataBase()->PropagateUp(e))
            {
                Entry* parent = e->pParent;
                if (parent && !parent->PNode.pNext)
                    byDepth.Link(d - 1, &parent->PNode.pNext, &parent->PNode);
            }
            node = node->pNext;
            e->PNode.Clear();
        }
    }
}

}}} // namespace Scaleform::Render::ContextImpl

// MS2-PIN: ??_7?$RefCountBase@VRenderer2D@Render@Scaleform@@$0EB@@Scaleform@@6B@ 0x143183fa0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EB@@Scaleform@@6B@ 0x143183fa8
// MS2-PIN: ??_7Renderer2D@Render@Scaleform@@6B@ 0x143183fb0
// MS2-PIN: ??_G?$RefCountBase@VRenderer2D@Render@Scaleform@@$0EB@@Scaleform@@UEAAPEAXI@Z 0x142582110
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EB@@Scaleform@@UEAAPEAXI@Z 0x1425820b0

// MS2-PINS-BEGIN covpin
// MS2-PIN: ??1?$PagedItemBuffer@VEntryChange@ContextImpl@Render@Scaleform@@$0DP@@Render@Scaleform@@QEAA@XZ 0x14257e940
// MS2-PIN: ??1LinearHeap@Render@Scaleform@@QEAA@XZ 0x14257ebc0
// MS2-PIN: ??_G?$RefCountBase@UHandleData@RTHandle@ContextImpl@Render@Scaleform@@$0EI@@Scaleform@@UEAAPEAXI@Z 0x14257ee90
// MS2-PIN: ??_G?$RefCountBase@VContextLock@ContextImpl@Render@Scaleform@@$0EI@@Scaleform@@UEAAPEAXI@Z 0x14257ee30
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EI@@Scaleform@@UEAAPEAXI@Z 0x14257edd0
// MS2-PIN: ??_GContextCaptureNotify@ContextImpl@Render@Scaleform@@UEAAPEAXI@Z 0x14257eef0
// MS2-PIN: ??_GContextLock@ContextImpl@Render@Scaleform@@UEAAPEAXI@Z 0x14257ef80
// MS2-PIN: ??_GHandleData@RTHandle@ContextImpl@Render@Scaleform@@UEAAPEAXI@Z 0x14257eff0
// MS2-PIN: ??_GRenderNotify@ContextImpl@Render@Scaleform@@UEAAPEAXI@Z 0x14257f0c0
// MS2-PIN: ??_GRenderer2D@Render@Scaleform@@UEAAPEAXI@Z 0x142582170
// MS2-PIN: ??_GSnapshot@ContextImpl@Render@Scaleform@@QEAAPEAXI@Z 0x14257f180
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EI@@Scaleform@@6B@ 0x143183f38
// MS2-PIN: ??_7?$RefCountBase@VContextLock@ContextImpl@Render@Scaleform@@$0EI@@Scaleform@@6B@ 0x143183f28
// MS2-PIN: ??_7ContextLock@ContextImpl@Render@Scaleform@@6B@ 0x143183f30
// MS2-PIN: ??_7?$RefCountBase@UHandleData@RTHandle@ContextImpl@Render@Scaleform@@$0EI@@Scaleform@@6B@ 0x143183f20
// MS2-PIN: ??_7HandleData@RTHandle@ContextImpl@Render@Scaleform@@6B@ 0x143183f40
// MS2-PIN: ??_7EntryData@ContextImpl@Render@Scaleform@@6B@ 0x14317b6d0
// MS2-PIN: ??_7RenderNotify@ContextImpl@Render@Scaleform@@6B@ 0x143183f48
// MS2-PIN: ??_7ContextCaptureNotify@ContextImpl@Render@Scaleform@@6B@ 0x143183f80
// MS2-PINS-END covpin
