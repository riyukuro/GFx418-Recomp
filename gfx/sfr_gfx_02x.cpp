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
// MS2-RANGE: 0x1425924e0-0x1425924e5 .text$mn
// MS2-RANGE: 0x1425924f0-0x1425924f5 .text$mn
// MS2-RANGE: 0x1425925b0-0x1425925c2 .text$mn

#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/kernel/sf_hash.h"
#include "sfr_gfx_07raw.h"

struct Sd_143184be8;
extern Sd_143184be8 DAT_143184be8;   // ??_7Audio@GFx@Scaleform@@6B@ (data_rdata_sf_b)

namespace Scaleform { namespace GFx {

#ifdef MS2_HOOK_DLL
void FUN_14015b310(void*, UPInt);    // sized delete
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" void __identifier("?__empty_global_delete@@YAXPEAX_K@Z")(void*, UPInt);    // sized delete
#define FUN_14015b310 __identifier("?__empty_global_delete@@YAXPEAX_K@Z")
#endif

// RefCountBase<T, Stat> scalar deleting destructor (folded for the 0x10-byte classes, three copies here).
// MS2-FUNCTIONAL: raw-layout COMDAT (folded identical bodies of many RefCountBase instances)
// @0x142591e10
void* FUN_142591e10(void* self, unsigned flags)
{
    RawRefCountNTSCoreDtor(self);
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
    RawRefCountNTSCoreDtor(self);
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
    RawField<void*>(self, 0) = &::DAT_143184be8;
    if (RawField<void*>(self, 0x30))
        FUN_14257dcd0(RawField<void*>(self, 0x30));
    if (RawField<void*>(self, 0x28))
        FUN_14257dcb0(RawField<void*>(self, 0x28));
    static_cast<State*>(self)->State::~State();
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
    static_cast<State*>(self)->State::~State();
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
    RawRefCountNTSCoreDtor(self);
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
// @0x142592030
template<int Stat>
void RefCountCollector<Stat>::AddRoot(BaseType* root)
{
    if (FirstFreeRootIndex != SF_MAX_UPINT)
    {
        UInt32 rootIndex = (UInt32)FirstFreeRootIndex; // SetBuffered's argument
        root->RefCount |= BaseType::Flag_Buffered;
        root->RootIndex = (UInt32)rootIndex;

        union
        {
            BaseType* Ptr;
            UPInt     UPtrValue;
            SPInt     SPtrValue;
        } u;
        u.Ptr = Roots[FirstFreeRootIndex];
        u.SPtrValue >>= 1;
        Roots[FirstFreeRootIndex] = root;
        FirstFreeRootIndex = u.UPtrValue;
    }
    else
    {
        UPInt rootIndex = Roots.GetSize(); // SetBuffered's argument
        root->RefCount |= BaseType::Flag_Buffered;
        root->RootIndex = (UInt32)rootIndex;
        Flags |= 1;
        if (!Roots.PushBackSafe(root))
        {
            Flags &= ~1;
            bool collected = Collect();
            Flags |= 1;
            if (!collected || !Roots.PushBackSafe(root))
            {
                root->ClearBuffered();
                root->SetState(BaseType::State_InUse);
            }
            Flags &= ~1;
        }
        else
            Flags &= ~1;
    }
}

// Marks the buffered roots and what they reach "in cycle" (internal references subtracted), puts back in use
// whatever is still referenced from outside together with what it reaches, and frees the rest. Survivors whose
// release was delayed are released now; roots go back to the buffer, which may start another round.
// The SDK body.
// @0x142592200
template<int Stat>
bool RefCountCollector<Stat>::Collect(Stats* pstat)
{
    if (IsCollecting() || Roots.GetSize() == 0)
    {
        if (pstat)
            memset(pstat, 0, sizeof(*pstat));
        return false;
    }

    // RefCountBaseGC::MarkInCycle and ClearInList (SDK inline members).
    auto markInCycle = [](BaseType* p, RefCountCollector* prcc) {
        if (!p->IsInState(BaseType::State_InCycle))
        {
            p->SetState(BaseType::State_InCycle);
            p->ExecuteForEachChild_GC(prcc, BaseType::Operation_MarkInCycle);
        }
    };
    auto clearInList = [](BaseType* p, RefCountCollector* prcc) {
        p->RefCount &= ~BaseType::Flag_InList;
        p->pRCC      = prcc;
        p->ClearBuffered();
    };

    // RootArray::Resize when shrinking (inline here).
    auto shrinkRoots = [](RootArray& r, UPInt newSize) {
        if (newSize >= r.Size)
            return;
        r.Size = newSize;
    };

    UPInt initialNRoots     = 0;
    UPInt totalKillListSize = 0;

    do
    {
        // The SDK's Flags_Collecting pair. The bit lies outside the UByte, so only a byte store (and its reload
        // below) is left, as in the exe.
        Flags |= 0x100;

        UPInt i, nroots = Roots.GetSize();
        initialNRoots += (unsigned)nroots;

        pLastPtr       = &ListRoot;
        ListRoot.pNext = ListRoot.pPrev = &ListRoot;
        ListRoot.SetInList();

        // 1. mark
        for (i = 0; i < nroots; ++i)
        {
            union
            {
                BaseType* Ptr;
                UPInt     PtrValue;
            } u;
            u.Ptr = Roots[i];
            if (u.PtrValue & 1)
                continue; // free root slot
            BaseType* proot = u.Ptr;
            BaseType* cur   = proot;
            if (cur->IsInState(BaseType::State_Root))
            {
                AddToList(cur);
                while (cur != &ListRoot)
                {
                    markInCycle(cur, this);
                    cur = cur->pNext;
                }
            }
            else
                cur->ClearBuffered();
        }
        FirstFreeRootIndex = SF_MAX_UPINT;
        shrinkRoots(Roots, 0);

        // 2. scan: referenced from outside means in use
        BaseType* cur = ListRoot.pNext;
        while (cur != &ListRoot)
        {
            if ((cur->RefCount & BaseType::Mask_RefCount) > 0)
            {
                cur->SetState(BaseType::State_InUse);
                pLastPtr = cur; // to perform reinserting after cur
                cur->ExecuteForEachChild_GC(this, BaseType::Operation_ScanInUse);
            }
            else
                cur->SetState(BaseType::State_Garbage);
            cur = cur->pNext;
        }

        // 3. free the garbage, hand the survivors back
        cur = ListRoot.pNext;
        while (cur != &ListRoot)
        {
            BaseType* next = cur->pNext;
            if (cur->IsInState(BaseType::State_Garbage))
            {
                cur->Finalize_GC();
                Memory::Free(cur);
                ++totalKillListSize;
            }
            else
            {
                clearInList(cur, this);
                if (cur->IsDelayedRelease())
                {
                    cur->RefCount &= ~BaseType::Flag_DelayedRelease;
                    cur->ReleaseInternal();
                }
                else
                {
                    if (cur->IsInState(BaseType::State_Root))
                        AddRoot(cur);
                    else
                        cur->ClearBuffered();
                }
            }
            cur = next;
        }
        pLastPtr = &ListRoot;
        clearInList(&ListRoot, (RefCountCollector*)0);
        Flags &= ~0x100;
        FirstFreeRootIndex = SF_MAX_UPINT;
    } while (Roots.GetSize() > 0);

    if (pstat)
    {
        pstat->RootsNumber     = (unsigned)initialNRoots;
        pstat->RootsFreedTotal = (unsigned)Alg::PMin(initialNRoots, totalKillListSize);
    }
    return true;
}

// @0x142592530
template<int Stat>
bool RefCountCollector<Stat>::RootArray::PushBackSafe(BaseType* const& val)
{
    // acquireDataPtrSafe
    BaseType** pslot;
    UPInt      page = Size >> 10;
    if (page >= NumPages && !allocatePageSafe(page))
        pslot = 0;
    else
        pslot = &Pages[page][Size & 0x3ff];
    if (!pslot)
        return false;
    *pslot = val;
    ++Size;
    return true;
}

// out-of-line copy of the header's inline RemoveFromRoots
// @0x1425927d0
template void RefCountCollector<StatMV_ActionScript_Mem>::RemoveFromRoots(BaseType* root);

// Grows by pages of 1024 slots (the page table by 5 entries at a time); shrinking only cuts the size.
// Not inlined: RemoveFromRoots calls it in the exe.
// @0x142592860
template<int Stat>
SF_NOINLINE void RefCountCollector<Stat>::RootArray::Resize(UPInt newSize)
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
SF_NOINLINE bool RefCountCollector<Stat>::RootArray::allocatePageSafe(UPInt index)
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
// The work-list head is read through a volatile pointer, so it is loaded again after the loop test, as in the exe.
// RemoveFromRoots is called through a member pointer, so it stays an out-of-line call (0x1425927d0), as in the exe.
// @0x1425925f0
template<int Stat>
void RefCountBaseGC<Stat>::ReleaseInternal()
{
    UInt32 rc = RefCount;
    if (!(rc & Mask_RefCount))
    {
        if ((UByte)(rc >> 27) & 1)
        {
            RefCount = rc | Flag_DelayedRelease;
            return;
        }
        if (!((UByte)(pRCC->ListRoot.RefCount >> 27) & 1))
        {
            pRCC->pLastPtr       = &pRCC->ListRoot;
            pRCC->ListRoot.pNext = pRCC->ListRoot.pPrev = &pRCC->ListRoot;
            pRCC->ListRoot.SetInList();
            ExecuteForEachChild_GC(pRCC, Operation_Release);
            Collector* prcc;
            while (prcc = pRCC, prcc->ListRoot.pNext != &prcc->ListRoot)
            {
                RefCountBaseGC* pchild = *(RefCountBaseGC* volatile*)&prcc->ListRoot.pNext;
                pchild->pPrev->pNext = pchild->pNext;
                pchild->pNext->pPrev = pchild->pPrev;
                UInt32 crc = pchild->RefCount & ~(Flag_Buffered | Flag_InList);
                pchild->RefCount  = crc;
                pchild->pNext     = 0;
                pchild->RootIndex = ~0u;
                pchild->pRCC      = pRCC;
                pchild->RefCount  = crc & ~Flag_DelayedRelease;
                pRCC->pLastPtr    = pRCC->ListRoot.pPrev;
                pchild->ReleaseInternal();
            }
            prcc->ListRoot.RefCount &= ~(Flag_Buffered | Flag_InList);
            prcc->ListRoot.pNext     = 0;
            prcc->ListRoot.RootIndex = ~0u;
        }
        else
            ExecuteForEachChild_GC(pRCC, Operation_Release);

        UInt32 frc = RefCount & ~(Mask_State << Shift_State);
        RefCount = frc;
        bool inlist   = (UByte)(frc >> 27) & 1;
        bool buffered = (UByte)(frc >> 31) != 0;
        // Unlinks a listed object and clears its list and buffer bits.
        auto removeFromList = [](RefCountBaseGC* p)
        {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            p->RefCount &= ~(Flag_Buffered | Flag_InList);
            p->pNext     = 0;
            p->RootIndex = ~0u;
        };
        if (!buffered)
        {
            if (inlist)
                removeFromList(this);
            Finalize_GC();
            Memory::Free(this);
        }
        else
        {
            if (!inlist)
                (pRCC->*(&Collector::RemoveFromRoots))(this);
            else
                removeFromList(this);
            Finalize_GC();
            Memory::Free(this);
        }
    }
    else
    {
        if ((rc & (Mask_State << Shift_State)) == ((UInt32)State_Root << Shift_State))
            return;
        rc = (rc & ~(Mask_State << Shift_State)) | ((UInt32)State_Root << Shift_State);
        RefCount = rc;
        if (rc & (Flag_Buffered | Flag_InList))
            return;
        pRCC->AddRoot(this);
    }
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
// The exe folds setRawCapacity's emptied newHash away: its destructor is inlined there (forceinline specialization,
// the sf_hash.h body).
template <> __forceinline MS2_GFX02X_CLASSREG_SET::~HashSetBase()
{
    if (pTable)
    {
        for (UPInt i = 0, n = pTable->SizeMask; i <= n; i++)
        {
            auto* e = &E(i);
            if (!e->IsEmpty())
                e->Free();
        }
        AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>::Free(pTable);
        pTable = NULL;
    }
}
// @0x1425921b0
template void MS2_GFX02X_CLASSREG_SET::CheckExpand(void*);
// @0x142592a10
template void MS2_GFX02X_CLASSREG_SET::setRawCapacity(void*, UPInt);
#undef MS2_GFX02X_CLASSREG_SET

} // namespace Scaleform
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1425921b0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UClassRegEntry@GlobalContext@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142592a10
// MS2-PIN: ?RemoveFromRoots@?$RefCountCollector@$0BED@@AS2@GFx@Scaleform@@QEAAXPEAV?$RefCountBaseGC@$0BED@@234@@Z 0x1425927d0

// Audio's vftable slots without .pdata (Audio is not declared here; raw layout as in its destructor above).
namespace Scaleform { namespace GFx {

void FUN_1425916c0(void* self, void* psc, void* object); // the "Sound" class registry entry (sfr_render_01e)

// The tags reader (+0x28).
// MS2-FUNCTIONAL: raw-layout getter
// @0x1425924e0
void* FUN_1425924e0(void* self)
{
    return RawField<void*>(self, 0x28);
}

// The sound renderer (+0x30).
// MS2-FUNCTIONAL: raw-layout getter
// @0x1425924f0
void* FUN_1425924f0(void* self)
{
    return RawField<void*>(self, 0x30);
}

// Registers the AS2 Sound class with the global context: forwards (context, string context, context + 0x60).
// MS2-FUNCTIONAL: raw-layout forwarder
// @0x1425925b0
void FUN_1425925b0(void* self, void* gc, void* psc)
{
    (void)self;
    FUN_1425916c0(gc, psc, RawField<void*>(gc, 0x60));
}

}} // namespace Scaleform::GFx
