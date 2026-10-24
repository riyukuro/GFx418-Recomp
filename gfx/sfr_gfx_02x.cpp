// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 leftovers between the loader
// and the AS2 heap: three RefCountBase deleting destructors, the Audio / AudioBase ones, the AS2 cycle collector
// (root buffer, Collect, the GC release) and the rehash of the global context's builtin class registry.
// Gap recovery of queue unit sfr_gfx_02.
// MS2-UNIT: sfr_gfx_02x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142591e10-0x142591e69 .text$mn
// MS2-RANGE: 0x142591e70-0x142591ec9 .text$mn
// MS2-RANGE: 0x142591ed0-0x142591f5c .text$mn
// MS2-RANGE: 0x142591f60-0x142591fc3 .text$mn
// MS2-RANGE: 0x142591fd0-0x142592029 .text$mn
// MS2-RANGE: 0x142592030-0x142592159 .text$mn
// MS2-RANGE: 0x1425921b0-0x1425921f3 .text$mn
// MS2-RANGE: 0x142592200-0x1425924dd .text$mn
// MS2-RANGE: 0x142592530-0x1425925a7 .text$mn
// MS2-RANGE: 0x1425925f0-0x1425927c1 .text$mn
// MS2-RANGE: 0x1425927d0-0x142592856 .text$mn
// MS2-RANGE: 0x142592860-0x142592946 .text$mn
// MS2-RANGE: 0x142592950-0x142592a07 .text$mn
// MS2-RANGE: 0x142592a10-0x142592be1 .text$mn

#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/kernel/sf_hash.h"
#include "sfr_gfx_07raw.h"

namespace Scaleform { namespace GFx {

void FUN_14257db40(void*);           // RefCountImplCore::~RefCountImplCore
void FUN_14257db50(void*);           // RefCountBase destructor body
void FUN_14257dcb0(void*);           // RefCountImpl::Release
void FUN_14257dcd0(void*);           // RefCountNTSImpl::Release
void FUN_14015b310(void*, UPInt);    // sized delete
extern "C" char DAT_143184be8[];     // ??_7Audio@GFx@Scaleform@@6B@
extern "C" char DAT_143109420[];     // ??_7State@GFx@Scaleform@@6B@

// RefCountBase<T, Stat> scalar deleting destructor (folded for the 0x10-byte classes, three copies here).
// MS2-FUNCTIONAL: raw-layout COMDAT (folded identical bodies of many RefCountBase instances)
// @0x142591e10
void* FUN_142591e10(void* self, unsigned flags)
{
    FUN_14257db50(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x10);
    }
    return self;
}

// MS2-FUNCTIONAL: raw-layout COMDAT (folded identical bodies of many RefCountBase instances)
// @0x142591e70
void* FUN_142591e70(void* self, unsigned flags)
{
    FUN_14257db50(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x10);
    }
    return self;
}

// Audio scalar deleting destructor: drops the sound renderer (+0x30) and the tags reader (+0x28). 0x38 bytes.
// MS2-FUNCTIONAL: raw-layout COMDAT (Audio is not declared here)
// @0x142591ed0
void* FUN_142591ed0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_143184be8;
    if (RawField<void*>(self, 0x30))
        FUN_14257dcd0(RawField<void*>(self, 0x30));
    if (RawField<void*>(self, 0x28))
        FUN_14257dcb0(RawField<void*>(self, 0x28));
    RawField<void*>(self, 0) = DAT_143109420;
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x38);
    }
    return self;
}

// AudioBase scalar deleting destructor. 0x28 bytes.
// MS2-FUNCTIONAL: raw-layout COMDAT (the State destructor chain is implicit in our headers)
// @0x142591f60
void* FUN_142591f60(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_143109420;
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x28);
    }
    return self;
}

// MS2-FUNCTIONAL: raw-layout COMDAT (folded identical bodies of many RefCountBase instances)
// @0x142591fd0
void* FUN_142591fd0(void* self, unsigned flags)
{
    FUN_14257db50(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x10);
    }
    return self;
}

namespace AS2 {

// A free slot of the root buffer is taken first; otherwise the root is appended, and when the buffer cannot grow
// one collection runs before a second try. A root that still does not fit is just not buffered.
// MS2-FUNCTIONAL: the exe inlines the first PushBackSafe
// @0x142592030
template<int Stat>
void RefCountCollector<Stat>::AddRoot(BaseType* root)
{
    if (FirstFreeRootIndex != SF_MAX_UPINT)
    {
        root->RefCount |= BaseType::Flag_Buffered;
        root->RootIndex = (UInt32)FirstFreeRootIndex;
        BaseType*& slot = Roots[FirstFreeRootIndex];
        SPInt next = (SPInt)slot >> 1;
        slot = root;
        FirstFreeRootIndex = (UPInt)next;
        return;
    }
    root->RefCount |= BaseType::Flag_Buffered;
    root->RootIndex = (UInt32)Roots.GetSize();
    Flags |= 1;
    bool added = Roots.PushBackSafe(root);
    Flags &= ~1;
    if (!added)
    {
        bool collected = Collect();
        Flags |= 1;
        if (!collected || !Roots.PushBackSafe(root))
        {
            UInt32 rc = root->RefCount;
            root->RefCount = rc & ~BaseType::Flag_Buffered;
            if (!root->IsInList())
                root->RootIndex = ~0u;
            root->RefCount = rc & ~(BaseType::Flag_Buffered | (BaseType::Mask_State << BaseType::Shift_State));
        }
        Flags &= ~1;
    }
}

// Marks the buffered roots and what they reach "in cycle" (internal references subtracted), puts back in use
// whatever is still referenced from outside together with what it reaches, and frees the rest. Survivors whose
// release was delayed are released now; roots go back to the buffer, which may start another round.
// MS2-FUNCTIONAL: written from the exe's control flow; register allocation and block order not checked
// @0x142592200
template<int Stat>
bool RefCountCollector<Stat>::Collect(Stats* pstats)
{
    if ((Flags & 1) || Roots.GetSize() == 0)
    {
        if (pstats)
        {
            pstats->RootsNumber     = 0;
            pstats->RootsFreedTotal = 0;
        }
        return false;
    }

    UPInt rootsNumber = 0;
    UPInt freed       = 0;
    UPInt n           = Roots.GetSize();
    do
    {
        pLastPtr       = &ListRoot;
        rootsNumber   += (unsigned)n;
        ListRoot.pPrev = &ListRoot;
        ListRoot.pNext = &ListRoot;
        ListRoot.SetInList();

        // 1. mark
        for (UPInt i = 0; i < n; ++i)
        {
            BaseType* proot = Roots[i];
            if ((UPInt)proot & 1)
                continue;
            if (proot->IsInState(BaseType::State_Root))
            {
                AddToList(proot);
                for (BaseType* p = proot; p != &ListRoot; p = p->pNext)
                {
                    if (!p->IsInState(BaseType::State_InCycle))
                    {
                        p->SetState(BaseType::State_InCycle);
                        p->ExecuteForEachChild_GC(this, BaseType::Operation_MarkInCycle);
                    }
                }
            }
            else
                proot->ClearBuffered();
        }
        FirstFreeRootIndex = SF_MAX_UPINT;
        if (Roots.Size != 0)
            Roots.Size = 0;

        BaseType* p = ListRoot.pNext;
        if (p != &ListRoot)
        {
            // 2. scan: referenced from outside means in use
            do
            {
                if (p->IsRefCntZero())
                    p->SetState(BaseType::State_Garbage);
                else
                {
                    p->SetState(BaseType::State_InUse);
                    pLastPtr = p;
                    p->ExecuteForEachChild_GC(this, BaseType::Operation_ScanInUse);
                }
                p = p->pNext;
            } while (p != &ListRoot);

            // 3. free the garbage, hand the survivors back
            p = ListRoot.pNext;
            while (p != &ListRoot)
            {
                UInt32    rc    = p->RefCount;
                BaseType* pnext = p->pNext;
                if (((rc >> BaseType::Shift_State) & BaseType::Mask_State) == BaseType::State_Garbage)
                {
                    p->Finalize_GC();
                    Memory::Free(p);
                    ++freed;
                }
                else
                {
                    UInt32 nrc  = rc & ~(BaseType::Flag_Buffered | BaseType::Flag_InList);
                    p->pRCC      = this;
                    p->RefCount  = nrc;
                    p->RootIndex = ~0u;
                    if (nrc & BaseType::Flag_DelayedRelease)
                    {
                        p->RefCount = rc & ~(BaseType::Flag_Buffered | BaseType::Flag_InList | BaseType::Flag_DelayedRelease);
                        p->ReleaseInternal();
                    }
                    else if (((rc >> BaseType::Shift_State) & BaseType::Mask_State) == BaseType::State_Root)
                        AddRoot(p);
                }
                p = pnext;
            }
        }
        pLastPtr = &ListRoot;
        ListRoot.RefCount &= ~(BaseType::Flag_Buffered | BaseType::Flag_InList);
        ListRoot.pRCC      = 0;
        ListRoot.RootIndex = ~0u;
        n                  = Roots.GetSize();
        FirstFreeRootIndex = SF_MAX_UPINT;
    } while (n != 0);

    if (pstats)
    {
        pstats->RootsNumber     = (unsigned)rootsNumber;
        pstats->RootsFreedTotal = (unsigned)(rootsNumber < freed ? rootsNumber : freed);
    }
    return true;
}

// @0x142592530
template<int Stat>
bool RefCountCollector<Stat>::RootArray::PushBackSafe(BaseType* const& val)
{
    UPInt page = Size >> 10;
    if (page >= NumPages && !allocatePageSafe(page))
        return false;
    BaseType** pslot = &Pages[page][Size & 0x3ff];
    if (!pslot)
        return false;
    *pslot = val;
    ++Size;
    return true;
}

// MS2-FUNCTIONAL: out-of-line copy of the header's inline RemoveFromRoots
// @0x1425927d0
template void RefCountCollector<StatMV_ActionScript_Mem>::RemoveFromRoots(BaseType* root);

// Grows by pages of 1024 slots (the page table by 5 entries at a time); shrinking only cuts the size.
// @0x142592860
template<int Stat>
void RefCountCollector<Stat>::RootArray::Resize(UPInt newSize)
{
    if (newSize > Size)
    {
        for (UPInt page = NumPages; page < ((newSize + 0x3ff) >> 10); ++page)
        {
            if (page >= MaxPages)
            {
                if (Pages)
                    Pages = (BaseType***)Memory::Realloc(Pages, (MaxPages + 5) * sizeof(BaseType**));
                else
                    Pages = (BaseType***)Memory::AllocAutoHeap(this, 5 * sizeof(BaseType**), AllocInfo(Stat_Default_Mem, 0, 0));
                MaxPages += 5;
            }
            Pages[page] = (BaseType**)Memory::AllocAutoHeap(this, 1024 * sizeof(BaseType*), AllocInfo(Stat_Default_Mem, 0, 0));
            ++NumPages;
        }
    }
    else if (newSize >= Size)
        return;
    Size = newSize;
}

// @0x142592950
template<int Stat>
bool RefCountCollector<Stat>::RootArray::allocatePageSafe(UPInt index)
{
    if (index >= MaxPages)
    {
        BaseType*** pages;
        if (Pages)
            pages = (BaseType***)Memory::Realloc(Pages, (MaxPages + 5) * sizeof(BaseType**));
        else
            pages = (BaseType***)Memory::AllocAutoHeap(this, 5 * sizeof(BaseType**), AllocInfo(Stat_Default_Mem, 0, 0));
        if (!pages)
            return false;
        MaxPages += 5;
        Pages     = pages;
    }
    Pages[index] = (BaseType**)Memory::AllocAutoHeap(this, 1024 * sizeof(BaseType*), AllocInfo(Stat_Default_Mem, 0, 0));
    if (!Pages[index])
        return false;
    ++NumPages;
    return true;
}

// The count is not zero: the object becomes a possible cycle root. Zero: its children are released (through the
// collector's work list unless a collection or release already owns it), then it is unbuffered, unlinked, finalized
// and freed. An object in a work list only has its release delayed.
// MS2-FUNCTIONAL: written from the exe's control flow; the release walk reloads pRCC as the exe does
// @0x1425925f0
template<int Stat>
void RefCountBaseGC<Stat>::ReleaseInternal()
{
    UInt32 rc = RefCount;
    if (rc & Mask_RefCount)
    {
        if (((rc >> Shift_State) & Mask_State) == State_Root)
            return;
        SetState(State_Root);
        if (rc & (Flag_Buffered | Flag_InList))
            return;
        pRCC->AddRoot(this);
        return;
    }
    if (rc & Flag_InList)
    {
        RefCount = rc | Flag_DelayedRelease;
        return;
    }

    if (!pRCC->ListRoot.IsInList())
    {
        Collector* prcc = pRCC;
        prcc->pLastPtr      = &prcc->ListRoot;
        pRCC->ListRoot.pPrev = &pRCC->ListRoot;
        pRCC->ListRoot.pNext = &pRCC->ListRoot;
        pRCC->ListRoot.SetInList();
        ExecuteForEachChild_GC(pRCC, Operation_Release);
        while (pRCC->ListRoot.pNext != &pRCC->ListRoot)
        {
            RefCountBaseGC* pchild = pRCC->ListRoot.pNext;
            pchild->pPrev->pNext = pchild->pNext;
            pchild->pNext->pPrev = pchild->pPrev;
            UInt32 crc = pchild->RefCount;
            pchild->pRCC      = pRCC;
            pchild->RefCount  = crc & ~(Flag_Buffered | Flag_InList | Flag_DelayedRelease);
            pchild->RootIndex = ~0u;
            pRCC->pLastPtr    = pRCC->ListRoot.pPrev;
            pchild->ReleaseInternal();
        }
        prcc = pRCC;
        prcc->ListRoot.RefCount &= ~(Flag_Buffered | Flag_InList);
        prcc->ListRoot.pRCC      = 0;
        prcc->ListRoot.RootIndex = ~0u;
    }
    else
        ExecuteForEachChild_GC(pRCC, Operation_Release);

    rc       = RefCount;
    RefCount = rc & ~(Mask_State << Shift_State);
    if (!IsInList())
    {
        if (rc & Flag_Buffered)
            pRCC->RemoveFromRoots(this);
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
        RefCount &= ~(Flag_Buffered | Flag_InList);
        pRCC      = 0;
        RootIndex = ~0u;
    }
    Finalize_GC();
    Memory::Free(this);
}

template void RefCountCollector<StatMV_ActionScript_Mem>::AddRoot(BaseType* root);
template bool RefCountCollector<StatMV_ActionScript_Mem>::Collect(Stats* pstats);
template bool RefCountCollector<StatMV_ActionScript_Mem>::RootArray::PushBackSafe(BaseType* const& val);
template void RefCountCollector<StatMV_ActionScript_Mem>::RootArray::Resize(UPInt newSize);
template bool RefCountCollector<StatMV_ActionScript_Mem>::RootArray::allocatePageSafe(UPInt index);
template void RefCountBaseGC<StatMV_ActionScript_Mem>::ReleaseInternal();

} // namespace AS2
}} // namespace Scaleform::GFx

namespace Scaleform {

// The rehash of the global context's builtin class registry (explicit instantiations of sf_hash.h, paired by the
// pins below).
#define MS2_GFX02X_CLASSREG_SET                                                                                      \
    HashSetBase<HashNode<GFx::ASString, GFx::AS2::GlobalContext::ClassRegEntry, GFx::ASStringHashFunctor>,           \
                HashNode<GFx::ASString, GFx::AS2::GlobalContext::ClassRegEntry, GFx::ASStringHashFunctor>::NodeHashF,\
                HashNode<GFx::ASString, GFx::AS2::GlobalContext::ClassRegEntry, GFx::ASStringHashFunctor>::NodeAltHashF, \
                AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,                                                \
                HashsetNodeEntry<HashNode<GFx::ASString, GFx::AS2::GlobalContext::ClassRegEntry, GFx::ASStringHashFunctor>, \
                                 HashNode<GFx::ASString, GFx::AS2::GlobalContext::ClassRegEntry, GFx::ASStringHashFunctor>::NodeHashF> >
// @0x1425921b0
template void MS2_GFX02X_CLASSREG_SET::CheckExpand(void*);
// MS2-FUNCTIONAL cl inlines the Clear / Add the exe calls out of line (paired by the pin below)
// @0x142592a10
template void MS2_GFX02X_CLASSREG_SET::setRawCapacity(void*, UPInt);
#undef MS2_GFX02X_CLASSREG_SET

} // namespace Scaleform
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1425921b0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142592a10
// MS2-PIN: ?RemoveFromRoots@?$RefCountCollector@$0BED@@AS2@GFx@Scaleform@@QEAAXPEAV?$RefCountBaseGC@$0BED@@234@@Z 0x1425927d0
