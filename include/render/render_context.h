// Recovered Scaleform 4.1.18 Render: the render Context (Render_Context). The advance thread edits a tree of Entry
// nodes; every frame Capture() freezes the changes into a Snapshot that the render thread picks up with
// NextCapture(). Entries live in 4 KB pages (EntryPage); each page has one SnapshotPage of data pointers per live
// snapshot, chained older/newer, so the two threads read different copies of a node's data.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_CONTEXT_H
#define MS2_SF_RENDER_CONTEXT_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_constants.h"
#include "ms2/scaleform/include/render/render_threadcommand.h"

namespace Scaleform { namespace Render {

class TreeCacheNode;

namespace ContextImpl {

struct EntryPage;
struct SnapshotPage;
class Snapshot;
class Entry;
class EntryData;
class EntryChange;
class Context;
class RTHandle;
class RenderNotify;

// The context's lock, shared (ref-counted) with the RTHandles so they outlive the context; pContext is cleared on
// shutdown.
class ContextLock : public RefCountBase<ContextLock, StatRender_Context_Mem>
{
public:
    Lock     LockObject;
    Context* pContext;

    ContextLock(Context* context) : pContext(context) {}
};

// A render-thread reference to an entry that stays safe after the context dies (GetRenderEntry then returns 0).
class RTHandle
{
    friend class Context;
    friend class Entry;

    enum HandleState
    {
        State_PreCapture,
        State_Valid,
        State_Dead
    };

    struct HandleData : public RefCountBase<HandleData, StatRender_Context_Mem>, public ListNode<HandleData>
    {
        Ptr<ContextLock> pContextLock;
        HandleState      State;
        Entry*           pEntry;

        HandleData(Entry* entry, Context* context);
        ~HandleData();
    };

    Ptr<HandleData> pData;

public:
    RTHandle() {}
    RTHandle(Entry* entry);
    RTHandle(const RTHandle& other) : pData(other.pData) {}
    ~RTHandle();

    void operator=(const RTHandle& other)        { pData = other.pData; }
    bool operator==(const RTHandle& other) const { return pData == other.pData; }

    void     Clear() { pData.Clear(); }
    Context* GetContext_Unsafe() const { return pData ? pData->pContextLock->pContext : 0; }

    bool   NextCapture(RenderNotify* render);
    Entry* GetRenderEntry() const;
};

template<class C>
class DisplayHandle : public RTHandle
{
public:
    DisplayHandle() {}
    DisplayHandle(C* entry) : RTHandle(entry) {}
    DisplayHandle(const RTHandle& other) : RTHandle(other) {}

    void operator=(const DisplayHandle& other)           { RTHandle::operator=(other); }
    bool operator==(const DisplayHandle<C>& other) const { return RTHandle::operator==(other); }
    C*   GetRenderEntry() const                          { return (C*)RTHandle::GetRenderEntry(); }
};

// A node of the context tree (0x38 bytes). While the entry is free its first two words are free-list links; in use
// they hold the pending change record and the (single-thread) reference count. Bit 0 of pNative flags an RTHandle.
class Entry
{
protected:
    friend struct EntryListAccessor;
    friend class Context;
    friend class Snapshot;
    friend class RTHandle;
    friend struct RTHandle::HandleData;

    union {
        Entry*       pPrev;
        EntryChange* pChange;
    };
    union {
        Entry*       pNext;
        UPInt        RefCount;
    };
    EntryData*     pNative;
    TreeCacheNode* pRenderer;
    Entry*         pParent;

    struct PropagateNode : public ListNode<PropagateNode>
    {
        inline Entry* GetEntry();
        bool IsAdded() const { return pPrev != 0; }
        void Clear()         { pPrev = pNext = 0; }
    };
    PropagateNode PNode;

    void destroyHelper();
    void addToPropagateImpl();

    EntryPage* getEntryPage() const;
    Snapshot*  getSnapshot() const;
    Context*   getContext() const;

    void setHasRTHandle()    { pNative = (EntryData*)(UPInt(pNative) | 1); }
    void clearHasRTHandle()  { pNative = GetNative(); }
    bool hasRTHandle() const { return (UPInt(pNative) & 1) != 0; }

    static TreeCacheNode* badRenderData() { return (TreeCacheNode*)0xbad; }

    EntryData* getWritableData(unsigned changeBits);

public:
    inline const EntryData* GetReadOnlyDataBase() const;
    inline const EntryData* GetDisplayDataBase() const;

    void Init(EntryData* native, EntryChange* change)
    {
        RefCount  = 1;
        pNative   = native;
        pRenderer = 0;
        pChange   = change;
        pParent   = 0;
        PNode.Clear();
    }

    EntryChange* GetChange() const         { return pChange; }
    void         SetChange(EntryChange* p) { pChange = p; }
    EntryData*   GetNative() const         { return (EntryData*)(UPInt(pNative) & ~UPInt(1)); }
    void         ClearNative()             { pNative = 0; }

    TreeCacheNode* GetRenderData() const           { return pRenderer; }
    void           SetRenderData(TreeCacheNode* p) { pRenderer = p; }
    TreeCacheNode* GetRenderDataClean() const      { return pRenderer != badRenderData() ? pRenderer : 0; }
    void           SetRenderDataAsBAD()            { pRenderer = badRenderData(); }

    unsigned CalcDepth() const
    {
        unsigned depth = 0;
        for (const Entry* p = this; p->pParent != 0; p = p->pParent)
            depth++;
        return depth;
    }

    void   AddToPropagate()          { if (!PNode.IsAdded()) addToPropagateImpl(); }
    Entry* GetParent() const         { return pParent; }
    void   SetParent(Entry* parent)  { pParent = parent; }
    void   AddRef()                  { RefCount++; }
    void   Release()                 { if (--RefCount == 0) destroyHelper(); }

    Context* GetContext() const;
};

// the free/destroyed lists link entries through their first two words
struct EntryListAccessor
{
    static void         SetPrev(Entry* self, Entry* what)  { self->pPrev = what; }
    static void         SetNext(Entry* self, Entry* what)  { self->pNext = what; }
    static const Entry* GetPrev(const Entry* self)         { return self->pPrev; }
    static const Entry* GetNext(const Entry* self)         { return self->pNext; }
    static Entry*       GetPrev(Entry* self)               { return self->pPrev; }
    static Entry*       GetNext(Entry* self)               { return self->pNext; }
};
typedef List2<Entry, EntryListAccessor> EntryList;

// marks a copy made for another snapshot (mask flags are not carried over)
template<class C>
struct NonlocalCloneArg
{
    const C* pC;
    NonlocalCloneArg(const C& c) : pC(&c) {}
    NonlocalCloneArg(const NonlocalCloneArg& s) : pC(s.pC) {}
    const C* operator->() const { return pC; }
};

// Per-snapshot node data. Copies (ConstructCopy/CopyTo) and Destroy take child Entry pointers by value without
// touching their reference counts; ReleaseNodes drops them when the node itself dies.
class EntryData
{
public:
    enum EntryType
    {
        ET_Base,
        ET_Root,
        ET_Container,
        ET_Shape,
        ET_Mesh,
        ET_Text
    };

    EntryData(EntryType type = ET_Base, UInt16 flags = 0) : Type((UInt16)type), Flags(flags) {}
    EntryData(const EntryData& src) : Type(src.Type), Flags(src.Flags) {}
    EntryData(NonlocalCloneArg<EntryData> src)
        : Type(src->Type), Flags(src->Flags & ~(UInt16)(NF_HasMask | NF_MaskNode))
    {
    }
    virtual ~EntryData();

    EntryType GetType() const { return (EntryType)Type; }

    virtual EntryData* ConstructCopy(LinearHeap& heap) const = 0;
    virtual void       CopyTo(void* dest) const = 0;
    virtual void       ReleaseNodes() const {}
    virtual void       Destroy() = 0;
    virtual bool       PropagateUp(Entry*) const { return false; }

protected:
    UInt16 Type;

public:
    UInt16 Flags;
};

// One recorded change: the entry and its change bits (a free-list link while recycled).
class EntryChange
{
public:
    Entry* pNode;
    union {
        unsigned     ChangeBits;
        EntryChange* pNextFreeNode;
    };

    bool IsNewNode() const { return (ChangeBits & Change_Context_NewNode) != 0; }
};

// 63 changes per 1 KB page
typedef PagedItemBuffer<EntryChange, (0x400 - 16) / sizeof(EntryChange)> ChangeBuffer;

// The render side of a context: told about new captures, entry changes and destruction. 0x38 bytes.
class RenderNotify
{
public:
    struct ContextNode : public ListNode<ContextNode>
    {
        Context* pContext;
        ContextNode(Context* context) : pContext(context) {}
    };

    List<ContextNode>   ActiveContextSet;
    ThreadCommandQueue* pRTCommandQueue;

    // queued on the render thread so a context waiting for shutdown gets serviced
    class ServiceCommand : public ThreadCommand
    {
        RenderNotify* pNotify;
    public:
        ServiceCommand(RenderNotify* notify) : pNotify(notify) {}
        virtual void Execute() { pNotify->ServiceQueues(); }
    };
    ServiceCommand ServiceCommandInstance;

    RenderNotify(ThreadCommandQueue* queue = 0) : pRTCommandQueue(queue), ServiceCommandInstance(getThis()) {}
    virtual ~RenderNotify();

    RenderNotify* getThis() { return this; }

    virtual void NewCapture(Context* context, bool hasChanges);
    virtual void ContextReleased(Context* context);
    virtual void ServiceQueues();
    virtual void EntryChanges(Context&, ChangeBuffer&, bool = false) {}
    virtual void EntryDestroy(Entry*) {}
    virtual void EntryFlush(Entry*) {}

    void ReleaseAllContextData();
    void EndFrameContextNotify();

    void PushRTServiceQueuesCommand()
    {
        if (pRTCommandQueue)
            pRTCommandQueue->PushThreadCommand(&ServiceCommandInstance);
    }
};

// Hooks into a context's capture cycle (called with the context lock held).
class ContextCaptureNotify : public ListNode<ContextCaptureNotify>
{
    friend class Context;
    Context* pOwnedContext;

public:
    ContextCaptureNotify() : pOwnedContext(0) {}
    virtual ~ContextCaptureNotify();

    virtual void OnCapture() {}
    virtual void OnNextCapture(RenderNotify*) {}
    virtual void OnShutdown() {}               // no wait flag in 4.1.18 (the exe passes nothing)
};

// Page and index of an entry, found from its address (pages are 4 KB aligned).
class EntryRef
{
    EntryPage* pPage;
    unsigned   Index;

public:
    inline EntryRef(const Entry* entry);

    EntryPage* GetEntryPage() const { return pPage; }
    unsigned   GetIndex() const     { return Index; }

    inline Snapshot*     GetSnapshot() const;
    inline SnapshotPage* GetSnapshotPage() const;
    inline SnapshotPage* GetDisplaySnapshotPage() const;
    inline EntryData*    GetData() const;
    inline EntryData*    GetCleanData() const;
    inline void          SetData_KeepDestroyedBit(EntryData* data);
    inline EntryData*    GetDisplayData() const;
    inline EntryData*&   GetDataRef() const;
    inline bool          IsDestroyed() const;
};

struct EntryPageBase : public ListNode<EntryPageBase>
{
    unsigned      UseCount;
    Snapshot*     pSnapshot;
    SnapshotPage* pSnapshotPage;
    SnapshotPage* pDisplaySnapshotPage;
    SnapshotPage* pTempPage;               // scratch while a snapshot is destroyed
};

enum
{
    EntryPageAllocAlign = 0x1000,
    EntryPageAllocSize  = 0x1000 - sizeof(void*),
    PageEntryCount      = (EntryPageAllocSize - sizeof(EntryPageBase)) / sizeof(Entry)
};

struct EntryPage : public EntryPageBase
{
    Entry Entries[PageEntryCount];

    inline void AddEntriesToList(EntryList* list);
    inline void RemoveEntriesFromList(EntryList* list);
};

// The data pointers of one entry page as one snapshot sees them; bit 0 of a pointer marks a destroyed entry.
struct SnapshotPage : public ListNode<SnapshotPage>
{
    EntryPage*    pEntryPage;
    SnapshotPage* pOlderSnapshotPage;
    SnapshotPage* pNewerSnapshotPage;
    EntryData*    pData[PageEntryCount];

    void MarkAsDestroyed(unsigned index)   { *((UPInt*)(void*)&pData[index]) |= 1; }
    bool IsDestroyed(unsigned index) const { return (*((UPInt*)(void*)&pData[index]) & 1) != 0; }
    void SetData_KeepDestroyedBit(unsigned index, EntryData* data)
    {
        pData[index] = (EntryData*)((UPInt)data | ((UPInt)pData[index] & 1));
    }
    EntryData* GetCleanData(unsigned index) { return (EntryData*)((UPInt)pData[index] & ~(UPInt)1); }

    static SnapshotPage* Alloc(MemoryHeap* heap, EntryPage* entryPage);
    static SnapshotPage* Clone(MemoryHeap* heap, SnapshotPage* source);
    void                 Free();
    void                 ClearEntryPagePointers();
};

class EntryTable
{
    friend class Context;

    Context*                       pContext;
    MemoryHeap*                    pHeap;
    List<EntryPage, EntryPageBase> EntryPages;
    EntryList                      FreeNodes;
    Snapshot*                      pActiveSnapshot;

    bool AllocEntryPage();
    void FreeEntryPage(EntryPage* page);

public:
    EntryTable(Context* context, MemoryHeap* heap) : pContext(context), pHeap(heap) {}

    void   SetActiveSnapshot(Snapshot* p) { pActiveSnapshot = p; }
    Entry* AllocEntry(EntryData* data);
    void   FreeEntry(Entry* p);
    void   GetActiveSnapshotPages(List<SnapshotPage>* list);
    void   NextSnapshot(Snapshot* next);
};

enum SnapshotState
{
    SS_Active,
    SS_Captured,
    SS_Displaying,
    SS_Finalizing,
    SS_Total_States
};

class Context
{
    friend class Entry;
    friend class RenderNotify;
    friend class RTHandle;
    friend class EntryTable;
    friend struct RTHandle::HandleData;

public:
    typedef ContextImpl::Entry        Entry;
    typedef ContextImpl::EntryData    EntryData;
    typedef ContextImpl::EntryChange  EntryChange;
    typedef ContextImpl::ChangeBuffer ChangeBuffer;
    typedef ContextImpl::RenderNotify RenderNotify;

    Context(MemoryHeap* heap);
    ~Context();

    template<class T>
    T* CreateEntry()
    {
        EntryData* data = (EntryData*)SF_HEAP_ALLOC(pHeap, sizeof(typename T::NodeData), StatRender_NodeData_Mem);
        Construct<typename T::NodeData>(data);
        return (T*)createEntryHelper(data);
    }
    template<class T, class S>
    T* CreateEntry(const S& source)
    {
        EntryData* data = (EntryData*)SF_HEAP_ALLOC(pHeap, sizeof(typename T::NodeData), StatRender_NodeData_Mem);
        ConstructAlt<typename T::NodeData, S>(data, source);
        return (T*)createEntryHelper(data);
    }

    bool HasCapture() const     { return CaptureCalled; }
    bool HasChanges() const;
    void SetDIChangesRequired() { DIChangesRequired = true; }

    bool Capture();
    void Shutdown(bool waitFlag);
    bool IsShutdownComplete() const;
    void PropagateChangesUp();

    UInt64 GetFrameId() const          { return SnapshotFrameIds[SS_Active]; }
    UInt64 GetFinalizedFrameId() const { return FinalizedFrameId; }
    void   ForceUpdateImages();

    void SetCaptureThreadId(ThreadId captureThreadId);
    void AddCaptureNotify(ContextCaptureNotify* notify);
    void RemoveCaptureNotify(ContextCaptureNotify* notify);

    enum CaptureMode
    {
        Capture_Immediate,
        Capture_OnceAFrame
    };
    bool NextCapture(RenderNotify* notify = 0, CaptureMode mode = Capture_Immediate);
    void ShutdownRendering(RenderNotify* notify = 0);

private:
    Context* getThis()                  { return this; }
    Lock*    getLock() const            { return &pCaptureLock->LockObject; }
    void     endFrame()                 { NextCaptureCalledInFrame = false; }
    bool     needRenderShutdown() const { return pShutdownEvent != 0; }

    MemoryHeap*                pHeap;
    ThreadId                   CreateThreadId;
    EntryTable                 Table;
    Ptr<ContextLock>           pCaptureLock;
    List<ContextCaptureNotify> CaptureNotifyList;
    RenderNotify*              pRenderer;
    bool                       MultiThreadedUse;
    bool                       NextCaptureCalledInFrame;
    volatile bool              CaptureCalled;
    volatile bool              DIChangesRequired;
    volatile bool              ShutdownRequested;
    Event* volatile            pShutdownEvent;
    RenderNotify::ContextNode  RenderNode;
    List<RTHandle::HandleData> RTHandleList;
    Snapshot*                  pSnapshots[SS_Total_States];
    UInt64                     SnapshotFrameIds[SS_Total_States];
    UInt64                     FinalizedFrameId;

    Entry* createEntryHelper(EntryData* data);
    bool   nextCapture_LockScope(Snapshot** shown, RenderNotify* notify, CaptureMode mode);
    void   nextCapture_NotifyChanges(Snapshot* shown, RenderNotify* notify);
    void   handleFinalizingSnaphot();
    void   shutdownRendering_NoLock();
    void   destroySnapshot(Snapshot* p);
    void   destroyNativeNodes(EntryList& list);
    void   clearRTHandle(Entry* entry);
    void   clearRTHandleList();
};

const EntryData* Entry::GetReadOnlyDataBase() const { return EntryRef(this).GetData(); }
const EntryData* Entry::GetDisplayDataBase() const  { return EntryRef(this).GetDisplayData(); }

EntryRef::EntryRef(const Entry* entry)
{
    pPage = (EntryPage*)((UPInt)entry & ~(UPInt)(EntryPageAllocAlign - 1));
    Index = unsigned(entry - &pPage->Entries[0]);
}
EntryData* EntryRef::GetData() const        { return pPage->pSnapshotPage->pData[Index]; }
EntryData* EntryRef::GetCleanData() const   { return pPage->pSnapshotPage->GetCleanData(Index); }
EntryData* EntryRef::GetDisplayData() const { return pPage->pDisplaySnapshotPage->GetCleanData(Index); }

// (appended for the tree nodes, sfr_render_03c)
// statistics counters of the per-snapshot copies (Render_Context data: 0x143b15f78, 0x143b15f7c, 0x143b15f80)
extern unsigned ConstructCopyCalls, DestroyCalls, CopyCalls;

// Implements the EntryData copy/destroy slots for the final node data class C on top of its base B.
template<class C, class B>
class ContextData_ImplMixin : public B
{
public:
    ContextData_ImplMixin(EntryData::EntryType type = EntryData::ET_Base) : B(type) {}
    ContextData_ImplMixin(NonlocalCloneArg<ContextData_ImplMixin<C, B> > src) : B(NonlocalCloneArg<B>(*src.pC)) {}

    virtual EntryData* ConstructCopy(LinearHeap& heap) const
    {
        ConstructCopyCalls++;
        return ConstructAlt<C>(heap.Alloc(sizeof(C)), *(const C*)this);
    }
    virtual void CopyTo(void* dest) const
    {
        *(C*)dest = *(const C*)this;
        CopyCalls++;
    }
    virtual void Destroy()
    {
        DestroyCalls++;
        ((C*)this)->~C();
    }
};

// typed accessors of an Entry subclass whose data class is C
#define SF_RENDER_CONTEXT_ENTRY_INLINES(C)                                                                   \
    inline C*       GetWritableData(unsigned cb) { return (C*)Entry::getWritableData(cb); }                 \
    inline const C* GetReadOnlyData() const      { return (const C*)Entry::GetReadOnlyDataBase(); }         \
    inline const C* GetDisplayData() const       { return (const C*)Entry::GetDisplayDataBase(); }

} // namespace ContextImpl

using ContextImpl::ContextData_ImplMixin;
using ContextImpl::Context;
using ContextImpl::ContextCaptureNotify;
using ContextImpl::DisplayHandle;
using ContextImpl::NonlocalCloneArg;

}} // namespace Scaleform::Render

#endif
