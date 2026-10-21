// Recovered Scaleform GFx 4.1.18 AS3: garbage-collected reference counting (RefCountBaseGC / RefCountCollector) as the
// exe has it. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// 4.1.18 layout (differs from later releases):
//   RefCountBaseGC  { vfptr; +0x08 pRCC or pNext; +0x10 UInt32 RefCount; +0x18 pPrev or UInt32 RootIndex }  0x20 bytes
//   RefCountCollector { RefCountBase; +0x10 Roots (paged, 1024 per page); +0x38 FirstFreeRootIndex; +0x48 ListRoot;
//                       +0x68 pLastPtr; +0x70 WProxyHash; +0x78 Flags; +0x80 HeadDelayedPtrRelease }  0x88 bytes
// RefCount: bits 0-21 count, 22 ToBeFinalized, 23 DelayedRelease, 24 InList, 25 HasFinalize, 26 HasWeakRef,
// 27 DeleteLast, 28-30 state, 31 in the root buffer.  The same code serves AS2 (identical template bodies are folded).
#ifndef MS2_SF_GFX_AS3_GC_H
#define MS2_SF_GFX_AS3_GC_H

#include "Kernel/SF_RefCount.h"
#include "Kernel/SF_ArrayPaged.h"
#include "Kernel/SF_Hash.h"
#include "Kernel/SF_String.h"
#include "GFx/GFx_PlayerStats.h"

namespace Scaleform { namespace GFx { namespace AS3 {

template <int Stat> class RefCountCollector;
class GASRefCountBase;

template <int Stat>
class RefCountBaseGC : public NewOverrideBase<Stat>
{
    friend class RefCountCollector<Stat>;

public:
    typedef RefCountCollector<Stat> Collector;
    typedef void (*GcOp)(Collector* prcc, const RefCountBaseGC<Stat>** pchild);

    enum
    {
        Mask_RefCount       = 0x003FFFFF,
        Flag_ToBeFinalized  = 0x00400000,
        Flag_DelayedRelease = 0x00800000,
        Flag_InList         = 0x01000000,
        Flag_HasFinalize    = 0x02000000,
        Flag_HasWeakRef     = 0x04000000,
        Flag_DeleteLast     = 0x08000000,
        Shift_State         = 28,
        Mask_State          = 0x7,
        Flag_InRootList     = 0x80000000u
    };

    enum States
    {
        State_InUse     = 0,
        State_InCycle   = 1,
        State_Garbage   = 2,
        State_Root      = 3,
        State_Removed   = 4,
        State_TempInUse = 5
    };

protected:
    union
    {
        mutable Collector*              pRCC;       // while not linked into the collector's work list
        mutable const RefCountBaseGC*   pNext;      // while Flag_InList is set
    };
    mutable UInt32 RefCount;
    union
    {
        mutable const RefCountBaseGC*   pPrev;      // while Flag_InList is set
        mutable UInt32                  RootIndex;  // while Flag_InRootList is set
    };

public:
    RefCountBaseGC(Collector* prcc) : pRCC(prcc), RefCount(1) { }

    // slot 0
    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const = 0;
    // slots 1..3: object-collector introspection
    virtual bool IsAS3Object() const;
    virtual const char* GetAS3ObjectType() const;
    virtual String GetAS3ObjectName() const;
protected:
    virtual ~RefCountBaseGC() { }       // slot 4
    virtual void Finalize_GC() { }      // slot 5
public:

    unsigned GetRefCount() const        { return RefCount & Mask_RefCount; }
    bool     IsRefCntZero() const       { return (RefCount & Mask_RefCount) == 0; }
    unsigned GetState() const           { return (RefCount >> Shift_State) & Mask_State; }
    bool     IsInState(unsigned s) const{ return GetState() == s; }
    void     SetState(unsigned s) const { RefCount = (RefCount & ~(Mask_State << Shift_State)) | (s << Shift_State); }
    bool     IsInList() const           { return (RefCount & Flag_InList) != 0; }
    bool     IsInRootList() const       { return (RefCount & Flag_InRootList) != 0; }
    bool     IsDelayedRelease() const   { return (RefCount & Flag_DelayedRelease) != 0; }
    bool     HasFinalize() const        { return (RefCount & Flag_HasFinalize) != 0; }
    bool     IsToBeFinalized() const    { return (RefCount & Flag_ToBeFinalized) != 0; }
    bool     HasWeakRef() const         { return (RefCount & Flag_HasWeakRef) != 0; }
    bool     IsDeleteLast() const       { return (RefCount & Flag_DeleteLast) != 0; }
    Collector* GetCollector() const     { return pRCC; }

    void AddRef() const
    {
        ++RefCount;
        RefCount &= ~((Mask_State << Shift_State) | Flag_ToBeFinalized);
    }
    void Release() const
    {
        if ((RefCount & Mask_RefCount) == 0)
            return;
        --RefCount;
        ReleaseInternal();
    }

    // Unlinks the object from the collector's work list.
    void RemoveFromList() const
    {
        const_cast<RefCountBaseGC*>(pPrev)->pNext = pNext;
        const_cast<RefCountBaseGC*>(pNext)->pPrev = pPrev;
        RefCount &= ~(Flag_InList | Flag_InRootList);
        pRCC = 0;
        RootIndex = ~0u;
    }

    void ReleaseInternal() const;   // out of line (shared with AS2, 0x1423dfa20)
};

// Weak reference target of a collectable object; told when the object dies.
class WeakProxy : public NewOverrideBase<StatMV_ActionScript_Mem>
{
public:
    int         RefCount;   // +0x00
    const void* pObject;    // +0x08

    void AddRef()               { ++RefCount; }
    void Release()              { if (--RefCount == 0) delete this; }
    void NotifyObjectDied()     { pObject = 0; }
};

template <int Stat>
class RefCountCollector : public RefCountBase<RefCountCollector<Stat>, Stat>
{
    friend class RefCountBaseGC<Stat>;

public:
    typedef RefCountBaseGC<Stat> BaseType;

    enum
    {
        Flags_Collecting            = 0x01,
        Flags_AddingRoot            = 0x02,
        Flags_InCollect             = 0x04,     // the whole Collect() call
        Flags_MarkInCycle           = 0x08,     // roots are being marked: AddRoot is a no-op
        Flags_RequireMoreCollect    = 0x10      // delayed Ptr releases ran: new roots may exist
    };

    // Collect() statistics; the optional observer is told the root count and the number of freed roots.
    struct StatsObserver : public RefCountBase<StatsObserver, Stat>
    {
        virtual void Begin() = 0;
        virtual void End() = 0;
        virtual void SetRootsNumber(unsigned n) = 0;
        virtual void SetRootsFreedTotal(unsigned n) = 0;
    };
    struct Stats
    {
        Ptr<StatsObserver>  pObserver;
        unsigned            RootsNumber;
        unsigned            RootsFreedTotal;
    };

    // Root of the work list; never collected.
    class Root : public RefCountBaseGC<Stat>
    {
    public:
        Root() : RefCountBaseGC<Stat>(0) { }
        virtual void ForEachChild_GC(RefCountCollector*, typename RefCountBaseGC<Stat>::GcOp) const { }
    };

    // Ptr chain released once a collection finishes (only its layout is used here).
    struct PtrReleaseProxy : public RefCountBase<PtrReleaseProxy, Stat>
    {
        Ptr<RefCountNTSImpl>    Data;       // +0x10
        const BaseType*         Data2;      // +0x18 SPtr<GASRefCountBase>
        Ptr<PtrReleaseProxy>    pNext;      // +0x20
    };

    typedef HashLH<const BaseType*, WeakProxy*, FixedSizeHash<const BaseType*>, Stat> WeakProxyHash;

    ArrayPagedLH_POD<const BaseType*, 10, 5>  Roots;                   // +0x10 free slots hold (next free << 1) | 1
    UPInt                                   FirstFreeRootIndex;         // +0x38
    UPInt                                   Reserved40;                 // +0x40
    Root                                    ListRoot;                   // +0x48
    const BaseType*                         pLastPtr;                   // +0x68
    WeakProxyHash                           WProxyHash;                 // +0x70
    UByte                                   Flags;                      // +0x78
    Ptr<PtrReleaseProxy>                    HeadDelayedPtrRelease;      // +0x80

    RefCountCollector() : FirstFreeRootIndex(SF_MAX_UPINT), Flags(0) { pLastPtr = &ListRoot; }

    bool IsCollecting() const   { return (Flags & Flags_Collecting) != 0; }
    bool IsAddingRoot() const   { return (Flags & Flags_AddingRoot) != 0; }
    UPInt GetRootsCount() const { return Roots.GetSize(); }

    void AddRoot(const BaseType* root);
    bool Collect(Stats* pstat = 0);

    // Links p into the work list right after pLastPtr, which then points at p.
    void AddToList(const BaseType* p)
    {
        p->pPrev = pLastPtr->pNext->pPrev;
        p->pNext = pLastPtr->pNext;
        const_cast<BaseType*>(pLastPtr->pNext)->pPrev = p;
        const_cast<BaseType*>(pLastPtr)->pNext = p;
        pLastPtr = p;
        p->RefCount |= BaseType::Flag_InList;
    }
    // Moves a listed p right after pLastPtr (pLastPtr stays).
    void ReinsertToList(const BaseType* p)
    {
        const_cast<BaseType*>(p->pPrev)->pNext = p->pNext;
        const_cast<BaseType*>(p->pNext)->pPrev = p->pPrev;
        p->pPrev = pLastPtr->pNext->pPrev;
        p->pNext = pLastPtr->pNext;
        const_cast<BaseType*>(pLastPtr->pNext)->pPrev = p;
        const_cast<BaseType*>(pLastPtr)->pNext = p;
    }
    // Frees p's root buffer slot (p->RootIndex).
    void RemoveFromRoots(const BaseType* p)
    {
        UInt32 idx = p->RootIndex;
        if ((UPInt)(idx + 1) == Roots.GetSize())
            Roots.Resize(idx);
        else
        {
            Roots[idx] = (const BaseType*)((FirstFreeRootIndex << 1) | 1);
            FirstFreeRootIndex = idx;
        }
    }
    // The weak proxy of a dying object forgets it.
    void RemoveWeakProxy(const BaseType* p)
    {
        WeakProxy** ppproxy = WProxyHash.Get(p);
        if (ppproxy && *ppproxy)
        {
            (*ppproxy)->NotifyObjectDied();
            (*ppproxy)->Release();
            WProxyHash.Remove(p);
        }
    }

    // Collect() passes these to ForEachChild_GC.
    static void MarkInCycleCall(RefCountCollector* prcc, const BaseType** pchild);
    static void ScanInUseCall(RefCountCollector* prcc, const BaseType** pchild);
    static void ScanTempInUseCall(RefCountCollector* prcc, const BaseType** pchild);
    static void KillChildCall(RefCountCollector* prcc, const BaseType** pchild);
};

typedef RefCountBaseGC<StatMV_ActionScript_Mem> ASRefCountBaseType;

// The collector of a movie: adds the frame-driven scheduling of collections.
class ASRefCountCollector : public RefCountCollector<StatMV_ActionScript_Mem>
{
public:
    unsigned    FrameCnt;                       // +0x88
    unsigned    MaxRootCount;                   // +0x8c
    unsigned    PeakRootCount;                  // +0x90
    unsigned    LastRootCount;                  // +0x94
    unsigned    LastCollectedRoots;             // +0x98
    unsigned    LastPeakRootCount;              // +0x9c
    unsigned    TotalFramesCount;               // +0xa0
    unsigned    LastCollectionFrameNum;         // +0xa4
    unsigned    PresetMaxRootCount;             // +0xa8
    unsigned    MaxFramesBetweenCollections;    // +0xac
    UByte       CollectionScheduledFlags;       // +0xb0
    UByte       SuspendCnt;                     // +0xb1

    ASRefCountCollector();
    void SetParams(unsigned frameBetweenCollections, unsigned maxRootCount);
};

}}} // namespace Scaleform::GFx::AS3

#endif
