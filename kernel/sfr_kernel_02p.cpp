// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_MemoryHeap (the PT
// heap front end: the global page-table/root setup, root heap creation, and every MemoryHeapPT entry point; the work
// itself is in AllocEngine and HeapRoot, queue unit sfr_kernel_03). Release build: no debug storage, no tracer.
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142641be0-0x142642f90 .text$mn
#include <new>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_stats.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_root.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocengine.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_memoryheap.h"

namespace Scaleform {

using namespace Heap;

// in-place storage of the PT root (the exe's copy is never touched by the hook DLL)
static UPInt RootMem[(sizeof(HeapPT::HeapRoot) + sizeof(UPInt) - 1) / sizeof(UPInt)];

void MemoryHeap::InitPT(SysAllocPaged* sysAlloc)
{
    if (HeapPT::GlobalPageTable || HeapPT::GlobalRoot)
        return;   // already initialised
    HeapPT::PageTable::Init();
    ::new(RootMem) HeapPT::HeapRoot(sysAlloc);
}

void MemoryHeap::CleanUpPT()
{
    if (HeapPT::GlobalPageTable == 0 || HeapPT::GlobalRoot == 0)
        return;
    HeapPT::GlobalRoot->DestroyAllArenas();
    HeapPT::GlobalPageTable->~PageTable();
    HeapPT::GlobalPageTable = 0;
    HeapPT::GlobalRoot->~HeapRoot();
    HeapPT::GlobalRoot = 0;
}

MemoryHeap* MemoryHeap::CreateRootHeapPT(const HeapDesc& desc)
{
    if (HeapPT::GlobalRoot == 0)
        return 0;
    {
        LockSafe::Locker locker(HeapPT::GlobalRoot->GetLock());
        if (Memory::pGlobalHeap)
            return 0;
        HeapDesc d2 = desc;
        d2.HeapId = HeapId_Global;
        Memory::pGlobalHeap = HeapPT::GlobalRoot->CreateHeap("Global", 0, d2);
    }
    return Memory::pGlobalHeap;
}

MemoryHeap* MemoryHeap::CreateRootHeapPT()
{
    HeapDesc desc;
    desc.Flags = Heap_Root;
    desc.MinAlign = RootHeap_MinAlign;
    desc.Granularity = RootHeap_Granularity;
    desc.Reserve = RootHeap_Reserve;
    desc.Threshold = RootHeap_Threshold;
    desc.Limit = RootHeap_Limit;
    desc.HeapId = HeapId_Global;
    return CreateRootHeapPT(desc);
}

bool MemoryHeap::ReleaseRootHeapPT()
{
    bool hasNoLeaks;
    if (HeapPT::GlobalRoot == 0)
        return true;
    LockSafe::Locker locker(HeapPT::GlobalRoot->GetLock());
    if (Memory::pGlobalHeap == 0)
        return true;
    hasNoLeaks = !Memory::pGlobalHeap->dumpMemoryLeaks();
    Memory::pGlobalHeap->destroyItself();
    Memory::pGlobalHeap = 0;
    return hasNoLeaks;
}

MemoryHeapPT::MemoryHeapPT() : MemoryHeap(), pEngine(0), pDebugStorage(0)
{
}

void MemoryHeapPT::CreateArena(UPInt arena, SysAllocPaged* sysAlloc)
{
    HeapPT::GlobalRoot->CreateArena(arena, sysAlloc);
}

void MemoryHeapPT::DestroyArena(UPInt arena)
{
    HeapPT::GlobalRoot->DestroyArena(arena);
}

bool MemoryHeapPT::ArenaIsEmpty(UPInt arena)
{
    return HeapPT::GlobalRoot->ArenaIsEmpty(arena);
}

MemoryHeap* MemoryHeapPT::CreateHeap(const char* name, const HeapDesc& desc)
{
    MemoryHeap* heap = 0;
    {
        LockSafe::Locker lock(HeapPT::GlobalRoot->GetLock());
        heap = HeapPT::GlobalRoot->CreateHeap(name, this, desc);
        if (heap)
            RefCount++;   // a child keeps its parent alive
    }
    if (heap)
    {
        Lock::Locker lock(&HeapLock);
        ChildHeaps.PushBack(heap);
    }
    return heap;
}

UPInt MemoryHeapPT::GetFootprint() const
{
    Lock::Locker lock(&HeapLock);
    return pEngine->GetFootprint();
}

UPInt MemoryHeapPT::GetTotalFootprint() const
{
    Lock::Locker lock(&HeapLock);
    UPInt footprint = 0;
    if (!(Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        footprint = pEngine->GetFootprint();
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        footprint += heap->GetTotalFootprint();
        heap = heap->pNext;
    }
    return footprint;
}

UPInt MemoryHeapPT::GetUsedSpace() const
{
    Lock::Locker lock(&HeapLock);
    return pEngine->GetUsedSpace();
}

UPInt MemoryHeapPT::GetTotalUsedSpace() const
{
    Lock::Locker lock(&HeapLock);
    UPInt space = 0;
    if (!(Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        space = pEngine->GetUsedSpace();
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        space += heap->GetTotalUsedSpace();
        heap = heap->pNext;
    }
    return space;
}

void MemoryHeapPT::SetLimitHandler(LimitHandler* handler)
{
    Lock::Locker locker(&HeapLock);
    pEngine->SetLimitHandler(handler);
}

// a lower limit never goes below what the heap already holds
void MemoryHeapPT::SetLimit(UPInt newLimit)
{
    Lock::Locker locker(&HeapLock);
    if (newLimit < Info.Desc.Limit)
    {
        if (newLimit < pEngine->GetFootprint())
            newLimit = pEngine->GetFootprint();
    }
    Info.Desc.Limit = pEngine->SetLimit(newLimit);
}

void MemoryHeapPT::AddRef()
{
    LockSafe::Locker lock(HeapPT::GlobalRoot->GetLock());
    RefCount++;
}

// The last release destroys the heap and drops the reference it held on its parent.
void MemoryHeapPT::Release()
{
    MemoryHeap* parent = Info.pParent;
    if (parent)
    {
        Lock::Locker     localLock(&parent->HeapLock);
        LockSafe::Locker globalLock(HeapPT::GlobalRoot->GetLock());
        if (--RefCount == 0)
        {
            dumpMemoryLeaks();
            parent->ChildHeaps.Remove(this);
            HeapPT::GlobalRoot->DestroyHeap(this);
        }
        else
        {
            parent = 0;
        }
    }
    else
    {
        LockSafe::Locker lock(HeapPT::GlobalRoot->GetLock());
        RefCount--;
    }
    if (parent)
        parent->Release();
}

bool MemoryHeapPT::dumpMemoryLeaks()
{
    return false;   // no debug storage in this build
}

void MemoryHeapPT::destroyItself()
{
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        MemoryHeap* next = heap->pNext;
        heap->destroyItself();
        heap = next;
    }
    HeapPT::GlobalRoot->DestroyHeap(this);
}

inline void* MemoryHeapPT::allocMem(UPInt size, const AllocInfo*)
{
    return pEngine->Alloc(size);
}

inline void* MemoryHeapPT::allocMem(UPInt size, UPInt align, const AllocInfo*)
{
    return pEngine->Alloc(size, align);
}

inline void* MemoryHeapPT::allocMem(const void*, UPInt size, const AllocInfo*)
{
    return pEngine->Alloc(size);
}

inline void* MemoryHeapPT::allocMem(const void*, UPInt size, UPInt align, const AllocInfo*)
{
    return pEngine->Alloc(size, align);
}

inline void* MemoryHeapPT::reallocMem(HeapSegment* seg, void* oldPtr, UPInt newSize)
{
    return pEngine->Realloc(seg, oldPtr, newSize);
}

void* MemoryHeapPT::Alloc(UPInt size, const AllocInfo* info)
{
    if (UseLocks)
    {
        Lock::Locker locker(&HeapLock);
        return allocMem(size, info);
    }
    return allocMem(size, info);
}

void* MemoryHeapPT::Alloc(UPInt size, UPInt align, const AllocInfo* info)
{
    if (UseLocks)
    {
        Lock::Locker locker(&HeapLock);
        return allocMem(size, align, info);
    }
    return allocMem(size, align, info);
}

// the owning heap comes from the page table, not from this
void* MemoryHeapPT::Realloc(void* oldPtr, UPInt newSize)
{
    HeapSegment*  seg  = HeapPT::GlobalPageTable->GetSegment(UPInt(oldPtr));
    MemoryHeapPT* heap = seg->pHeap;
    if (heap->UseLocks)
    {
        Lock::Locker locker(&heap->HeapLock);
        return heap->reallocMem(seg, oldPtr, newSize);
    }
    return heap->reallocMem(seg, oldPtr, newSize);
}

// freeing the heap's auto-release block releases the heap
void MemoryHeapPT::Free(void* ptr)
{
    if (ptr)
    {
        HeapSegment*  seg  = HeapPT::GlobalPageTable->GetSegment(UPInt(ptr));
        MemoryHeapPT* heap = seg->pHeap;
        if (heap->UseLocks)
        {
            {
                Lock::Locker locker(&heap->HeapLock);
                heap->pEngine->Free(seg, ptr);
            }
            if (ptr == heap->pAutoRelease)
                heap->Release();
        }
        else
        {
            heap->pEngine->Free(seg, ptr);
            if (ptr == heap->pAutoRelease)
                heap->Release();
        }
    }
}

void* MemoryHeapPT::AllocAutoHeap(const void* thisPtr, UPInt size, const AllocInfo* info)
{
    HeapSegment*  seg  = HeapPT::GlobalPageTable->GetSegment(UPInt(thisPtr));
    MemoryHeapPT* heap = seg->pHeap;
    if (heap->UseLocks)
    {
        Lock::Locker locker(&heap->HeapLock);
        return heap->allocMem(thisPtr, size, info);
    }
    return heap->allocMem(thisPtr, size, info);
}

void* MemoryHeapPT::AllocAutoHeap(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info)
{
    HeapSegment*  seg  = HeapPT::GlobalPageTable->GetSegment(UPInt(thisPtr));
    MemoryHeapPT* heap = seg->pHeap;
    if (heap->UseLocks)
    {
        Lock::Locker locker(&heap->HeapLock);
        return heap->allocMem(thisPtr, size, align, info);
    }
    return heap->allocMem(thisPtr, size, align, info);
}

MemoryHeap* MemoryHeapPT::GetAllocHeap(const void* thisPtr)
{
    HeapSegment* seg = HeapPT::GlobalPageTable->GetSegment(UPInt(thisPtr));
    return seg->pHeap;
}

UPInt MemoryHeapPT::GetUsableSize(const void* ptr)
{
    HeapSegment*  seg  = HeapPT::GlobalPageTable->GetSegment(UPInt(ptr));
    MemoryHeapPT* heap = seg->pHeap;
    if (heap->UseLocks)
    {
        Lock::Locker locker(&heap->HeapLock);
        return heap->pEngine->GetUsableSize(seg, ptr);
    }
    return heap->pEngine->GetUsableSize(seg, ptr);
}

void MemoryHeapPT::releaseCachedMem()
{
    Lock::Locker locker(&HeapLock);
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        heap->releaseCachedMem();
        heap = heap->pNext;
    }
    pEngine->ReleaseCachedMem();
}

void* MemoryHeapPT::AllocSysDirect(UPInt size)
{
    return HeapPT::GlobalRoot->AllocSysDirect(size);
}

void MemoryHeapPT::FreeSysDirect(void* ptr, UPInt size)
{
    HeapPT::GlobalRoot->FreeSysDirect(ptr, size);
}

// With the null StatBag only the engine queries and the child footprint walk are left.
bool MemoryHeapPT::GetStats(StatBag* bag)
{
    Lock::Locker locker(&HeapLock);
    UPInt footprint = pEngine->GetFootprint();
    bag->AddStat(StatHeap_LocalFootprint, CounterStat(footprint));
    bag->AddStat(StatHeap_LocalUsedSpace, CounterStat(pEngine->GetUsedSpace()));
    bag->AddStat(StatHeap_Granularity, CounterStat(Info.Desc.Granularity));
    bag->AddStat(StatHeap_Reserve, CounterStat(Info.Desc.Reserve));

    HeapPT::HeapOtherStats otherStats;
    pEngine->GetHeapOtherStats(&otherStats);
    otherStats.Bookkeeping += SelfSize;
    bag->AddStat(StatHeap_Bookkeeping, CounterStat(otherStats.Bookkeeping));
    bag->AddStat(StatHeap_Segments, CounterStat(otherStats.Segments));
    bag->AddStat(StatHeap_DynamicGranularity, CounterStat(otherStats.DynamicGranularity));
    bag->AddStat(StatHeap_SysDirectSpace, CounterStat(otherStats.SysDirectSpace));

    UPInt childHeapCount = 0;
    UPInt childFootprint = 0;
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        if (!(heap->Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        {
            childHeapCount++;
            childFootprint += heap->GetTotalFootprint();
        }
        heap = heap->pNext;
    }
    if (childHeapCount)
    {
        bag->AddStat(StatHeap_ChildHeaps, CounterStat(childHeapCount));
        bag->AddStat(StatHeap_ChildFootprint, CounterStat(childFootprint));
    }
    bag->AddStat(StatHeap_TotalFootprint, CounterStat(childFootprint + footprint));
    return true;
}

void MemoryHeapPT::ultimateCheck() { }

void MemoryHeapPT::VisitMem(Heap::MemVisitor* visitor, unsigned flags)
{
    Lock::Locker locker(&HeapLock);
    pEngine->VisitMem(visitor, flags);
}

void MemoryHeapPT::VisitHeapSegments(Heap::SegVisitor* visitor) const
{
    Lock::Locker locker(&HeapLock);
    pEngine->VisitSegments(visitor);
}

void MemoryHeapPT::VisitRootSegments(Heap::SegVisitor* visitor)
{
    HeapPT::GlobalRoot->VisitSegments(visitor);
}

void MemoryHeapPT::getUserDebugStats(RootStats* stats) const
{
    Lock::Locker lock(&HeapLock);
    if (Info.Desc.Flags & MemoryHeap::Heap_UserDebug)
    {
        stats->UserDebugFootprint += pEngine->GetFootprint();
        stats->UserDebugUsedSpace += pEngine->GetUsedSpace();
    }
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        heap->getUserDebugStats(stats);
        heap = heap->pNext;
    }
}

void MemoryHeapPT::GetRootStats(RootStats* stats)
{
    HeapPT::GlobalRoot->GetStats(stats);
    stats->UserDebugFootprint = 0;
    stats->UserDebugUsedSpace = 0;
    Memory::pGlobalHeap->getUserDebugStats(stats);
}

void MemoryHeapPT::checkIntegrity() const
{
    Lock::Locker locker(&HeapLock);
    pEngine->CheckIntegrity();
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        heap->checkIntegrity();
        heap = heap->pNext;
    }
}

void MemoryHeapPT::SetTracer(HeapTracer* tracer) { SF_UNUSED(tracer); }

// the PT engine is set up by the paged system allocator itself
bool SysAllocPaged::initHeapEngine(const void* heapDesc)
{
    MemoryHeap::InitPT(this);
    const MemoryHeap::HeapDesc& rootHeapDesc = *(const MemoryHeap::HeapDesc*)heapDesc;
    MemoryHeap* p = MemoryHeap::CreateRootHeapPT(rootHeapDesc);
    return p != 0;
}

bool SysAllocPaged::shutdownHeapEngine()
{
    bool hasNoLeaks = MemoryHeap::ReleaseRootHeapPT();
    MemoryHeap::CleanUpPT();
    return hasNoLeaks;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0MemoryHeapPT@Scaleform@@AEAA@XZ 0x142641be0
// MS2-PIN: ??_GMemoryHeapPT@Scaleform@@EEAAPEAXI@Z 0x142641c40
// MS2-PIN: ?AddRef@MemoryHeapPT@Scaleform@@UEAAXXZ 0x142641c90
// MS2-PIN: ?Alloc@MemoryHeapPT@Scaleform@@UEAAPEAX_K0PEBUAllocInfo@2@@Z 0x142641ce0
// MS2-PIN: ?Alloc@MemoryHeapPT@Scaleform@@UEAAPEAX_KPEBUAllocInfo@2@@Z 0x142641d70
// MS2-PIN: ?AllocAutoHeap@MemoryHeapPT@Scaleform@@UEAAPEAXPEBX_K1PEBUAllocInfo@2@@Z 0x142641df0
// MS2-PIN: ?AllocAutoHeap@MemoryHeapPT@Scaleform@@UEAAPEAXPEBX_KPEBUAllocInfo@2@@Z 0x142641ee0
// MS2-PIN: ?CleanUpPT@MemoryHeap@Scaleform@@SAXXZ 0x142641fe0
// MS2-PIN: ?CreateHeap@MemoryHeapPT@Scaleform@@UEAAPEAVMemoryHeap@2@PEBDAEBUHeapDesc@32@@Z 0x142642040
// MS2-PIN: ?CreateRootHeapPT@MemoryHeap@Scaleform@@SAPEAV12@AEBUHeapDesc@12@@Z 0x142642110
// MS2-PIN: ?CreateRootHeapPT@MemoryHeap@Scaleform@@SAPEAV12@XZ 0x1426421d0
// MS2-PIN: ?Free@MemoryHeapPT@Scaleform@@UEAAXPEAX@Z 0x142642230
// MS2-PIN: ?GetFootprint@MemoryHeapPT@Scaleform@@UEBA_KXZ 0x1426423a0
// MS2-PIN: ?GetRootStats@MemoryHeapPT@Scaleform@@UEAAXPEAURootStats@MemoryHeap@2@@Z 0x1426423f0
// MS2-PIN: ?GetStats@MemoryHeapPT@Scaleform@@UEAA_NPEAVStatBag@2@@Z 0x142642430
// MS2-PIN: ?GetTotalFootprint@MemoryHeapPT@Scaleform@@UEBA_KXZ 0x142642500
// MS2-PIN: ?GetTotalUsedSpace@MemoryHeapPT@Scaleform@@UEBA_KXZ 0x1426425b0
// MS2-PIN: ?GetUsableSize@MemoryHeapPT@Scaleform@@UEAA_KPEBX@Z 0x142642660
// MS2-PIN: ?GetUsedSpace@MemoryHeapPT@Scaleform@@UEBA_KXZ 0x142642750
// MS2-PIN: ?InitPT@MemoryHeap@Scaleform@@SAXPEAVSysAllocPaged@2@@Z 0x1426427a0
// MS2-PIN: ?Realloc@MemoryHeapPT@Scaleform@@UEAAPEAXPEAX_K@Z 0x1426427e0
// MS2-PIN: ?Release@MemoryHeapPT@Scaleform@@UEAAXXZ 0x1426428d0
// MS2-PIN: ?ReleaseRootHeapPT@MemoryHeap@Scaleform@@SA_NXZ 0x1426429d0
// MS2-PIN: ?SetLimit@MemoryHeapPT@Scaleform@@UEAAX_K@Z 0x142642a60
// MS2-PIN: ?SetLimitHandler@MemoryHeapPT@Scaleform@@UEAAXPEAULimitHandler@MemoryHeap@2@@Z 0x142642ae0
// MS2-PIN: ?VisitHeapSegments@MemoryHeapPT@Scaleform@@UEBAXPEAVSegVisitor@Heap@2@@Z 0x142642b40
// MS2-PIN: ?VisitMem@MemoryHeapPT@Scaleform@@UEAAXPEAVMemVisitor@Heap@2@I@Z 0x142642b90
// MS2-PIN: ?checkIntegrity@MemoryHeapPT@Scaleform@@EEBAXXZ 0x142642c00
// MS2-PIN: ?destroyItself@MemoryHeapPT@Scaleform@@EEAAXXZ 0x142642c90
// MS2-PIN: ?getUserDebugStats@MemoryHeapPT@Scaleform@@EEBAXPEAURootStats@MemoryHeap@2@@Z 0x142642d10
// MS2-PIN: ?initHeapEngine@SysAllocPaged@Scaleform@@MEAA_NPEBX@Z 0x142642dc0
// MS2-PIN: ?releaseCachedMem@MemoryHeapPT@Scaleform@@EEAAXXZ 0x142642e20
// MS2-PIN: ?shutdownHeapEngine@SysAllocPaged@Scaleform@@MEAA_NXZ 0x142642eb0
// MS2-PIN: ??_7MemoryHeap@Scaleform@@6B@ 0x143183e08
// MS2-PIN: ??1MemoryHeapPT@Scaleform@@EEAA@XZ 0x142641c20
// MS2-PIN: ??_7MemoryHeapPT@Scaleform@@6B@ 0x14318fd30
// MS2-PIN: ?AllocSysDirect@MemoryHeapPT@Scaleform@@UEAAPEAX_K@Z 0x142641fc0
// MS2-PIN: ?ArenaIsEmpty@MemoryHeapPT@Scaleform@@UEAA_N_K@Z 0x142641fd0
// MS2-PIN: ?CreateArena@MemoryHeapPT@Scaleform@@UEAAX_KPEAVSysAllocPaged@2@@Z 0x142642030
// MS2-PIN: ?DestroyArena@MemoryHeapPT@Scaleform@@UEAAX_K@Z 0x142642220
// MS2-PIN: ?FreeSysDirect@MemoryHeapPT@Scaleform@@UEAAXPEAX_K@Z 0x142642320
// MS2-PIN: ?GetAllocHeap@MemoryHeapPT@Scaleform@@UEAAPEAVMemoryHeap@2@PEBX@Z 0x142642330
// MS2-PIN: ?SetTracer@MemoryHeapPT@Scaleform@@UEAAXPEAUHeapTracer@MemoryHeap@2@@Z 0x142642b30
// MS2-PIN: ?VisitRootSegments@MemoryHeapPT@Scaleform@@UEAAXPEAVSegVisitor@Heap@2@@Z 0x142642bf0
// MS2-PIN: ?dumpMemoryLeaks@MemoryHeapPT@Scaleform@@EEAA_NXZ 0x142642d00
// MS2-PIN: ?ultimateCheck@MemoryHeapPT@Scaleform@@EEAAXXZ 0x142642f80
