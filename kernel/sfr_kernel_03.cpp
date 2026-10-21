// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_Root (the PT heap
// root: the granulating system-allocator adapter, the arena wrapper, arena bookkeeping and heap creation). Release
// build: no debug storage, no tracer. Our own source, written from the exe. Queue unit sfr_kernel_03 is split along
// its original sources.
// MS2-UNIT: sfr_kernel_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426ce850-0x1426cf7b0 .text$mn
#include <new>
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_root.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocengine.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

HeapRoot* GlobalRoot = 0;   // exe 0x143b27358

// ---- SysAllocGranulator ----

SysAllocGranulator::SysAllocGranulator()
    : pGranulator(0), SysDirectThreshold(0), MinAlign(0), MaxAlign(0), SysDirectFootprint(0)
{ }

SysAllocGranulator::SysAllocGranulator(SysAllocPaged* sysAlloc)
    : pGranulator(0), SysDirectThreshold(0), MaxHeapGranularity(0), MinAlign(0), MaxAlign(0), SysDirectFootprint(0)
{
    Init(sysAlloc);
}

void SysAllocGranulator::Init(SysAllocPaged* sysAlloc)
{
    pGranulator = ::new(PrivateData) Granulator(sysAlloc, Heap_PageSize, Heap_PageSize, 2 * Heap_PageSize);

    // ask the source for its limits; zero alignments mean "anything goes"
    Info i;
    memset(&i, 0, sizeof(Info));
    pGranulator->GetSysAlloc()->GetInfo(&i);
    SysDirectThreshold = i.SysDirectThreshold;
    MaxHeapGranularity = i.MaxHeapGranularity;
    MinAlign           = i.MinAlign;
    MaxAlign           = i.MaxAlign;
    if (MinAlign == 0)
        MinAlign = 1;
    if (MaxAlign == 0)
        MaxAlign = UPInt(1) << (8 * sizeof(UPInt) - 1);
}

void SysAllocGranulator::GetInfo(Info* i) const
{
    i->MinAlign           = 0;
    i->MaxAlign           = 0;
    i->Granularity        = 0;
    i->SysDirectThreshold = SysDirectThreshold;
    i->MaxHeapGranularity = MaxHeapGranularity;
    i->HasRealloc         = true;
}

void* SysAllocGranulator::Alloc(UPInt size, UPInt alignment)
{
    return pGranulator->Alloc(size, alignment);
}

bool SysAllocGranulator::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignment)
{
    return pGranulator->ReallocInPlace(oldPtr, oldSize, newSize, alignment);
}

bool SysAllocGranulator::Free(void* ptr, UPInt size, UPInt alignment)
{
    return pGranulator->Free(ptr, size, alignment);
}

// big blocks bypass the granulator; an alignment below a page is satisfied by over-allocating one page
void* SysAllocGranulator::AllocSysDirect(UPInt size, UPInt alignment, UPInt* actualSize, UPInt* actualAlign)
{
    UPInt pageAlign = alignment;
    if (pageAlign < Heap_PageSize)
        pageAlign = Heap_PageSize;
    if (alignment < MinAlign)
        alignment = MinAlign;
    if (alignment > MaxAlign)
        alignment = MaxAlign;
    if (alignment < pageAlign)
        size += pageAlign;

    *actualSize  = size;
    *actualAlign = alignment;
    SysDirectFootprint += size;
    return pGranulator->GetSysAlloc()->Alloc(size, alignment);
}

bool SysAllocGranulator::FreeSysDirect(void* ptr, UPInt size, UPInt alignment)
{
    SysDirectFootprint -= size;
    return pGranulator->GetSysAlloc()->Free(ptr, size, alignment);
}

void SysAllocGranulator::VisitMem(MemVisitor* visitor) const
{
    pGranulator->VisitMem(visitor, MemVisitor::Cat_SysAlloc, MemVisitor::Cat_SysAllocFree);
}

void SysAllocGranulator::VisitSegments(SegVisitor* visitor, UPInt catSeg, UPInt catUnused) const
{
    pGranulator->VisitSegments(visitor, (unsigned)catSeg, (unsigned)catUnused);
}

UPInt SysAllocGranulator::GetFootprint() const { return pGranulator->GetFootprint() + SysDirectFootprint; }
UPInt SysAllocGranulator::GetUsedSpace() const { return pGranulator->GetUsedSpace() + SysDirectFootprint; }
UPInt SysAllocGranulator::GetBase() const { return pGranulator->GetBase(); }
UPInt SysAllocGranulator::GetSize() const { return pGranulator->GetSize(); }

// ---- SysAllocWrapper ----

SysAllocWrapper::SysAllocWrapper(SysAllocPaged* sysAlloc)
    : Allocator(), pSrcAlloc(sysAlloc), pSysAlloc(sysAlloc), SysGranularity(Heap_PageSize), MinAlign(1), UsedSpace(0)
{
    Info i;
    memset(&i, 0, sizeof(Info));
    sysAlloc->GetInfo(&i);
    if (i.Granularity)
    {
        // the source has its own granularity: put a granulator in front of it
        Allocator.Init(sysAlloc);
        pSysAlloc      = &Allocator;
        SysGranularity = i.Granularity;
    }
    if (MinAlign < i.MinAlign)
        MinAlign = i.MinAlign;
}

void SysAllocWrapper::GetInfo(Info* i) const
{
    memset(i, 0, sizeof(Info));
    pSysAlloc->GetInfo(i);
}

void* SysAllocWrapper::Alloc(UPInt size, UPInt align)
{
    UsedSpace += size;
    return pSysAlloc->Alloc(size, align);
}

bool SysAllocWrapper::Free(void* ptr, UPInt size, UPInt align)
{
    UsedSpace -= size;
    return pSysAlloc->Free(ptr, size, align);
}

bool SysAllocWrapper::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align)
{
    UsedSpace -= oldSize;
    UsedSpace += newSize;
    return pSysAlloc->ReallocInPlace(oldPtr, oldSize, newSize, align);
}

void* SysAllocWrapper::AllocSysDirect(UPInt size, UPInt alignment, UPInt* actualSize, UPInt* actualAlign)
{
    UsedSpace += size;
    return pSysAlloc->AllocSysDirect(size, alignment, actualSize, actualAlign);
}

bool SysAllocWrapper::FreeSysDirect(void* ptr, UPInt size, UPInt alignment)
{
    UsedSpace -= size;
    return pSysAlloc->FreeSysDirect(ptr, size, alignment);
}

void SysAllocWrapper::VisitMem(MemVisitor* visitor) const
{
    pSysAlloc->VisitMem(visitor);
}

void SysAllocWrapper::VisitSegments(SegVisitor* visitor, UPInt catSeg, UPInt catUnused) const
{
    pSysAlloc->VisitSegments(visitor, catSeg, catUnused);
}

// whole system granules straight from the source allocator (page tables and the like)
void* SysAllocWrapper::AllocSysDirect(UPInt size)
{
    size = (size + SysGranularity - 1) / SysGranularity * SysGranularity;
    UsedSpace += size;
    return pSrcAlloc->Alloc(size, MinAlign);
}

void SysAllocWrapper::FreeSysDirect(void* ptr, UPInt size)
{
    size = (size + SysGranularity - 1) / SysGranularity * SysGranularity;
    UsedSpace -= size;
    pSrcAlloc->Free(ptr, size, MinAlign);
}

UPInt SysAllocWrapper::GetFootprint() const { return pSysAlloc->GetFootprint(); }
UPInt SysAllocWrapper::GetUsedSpace() const { return UsedSpace; }

// ---- HeapRoot ----

HeapRoot::HeapRoot(SysAllocPaged* sysAlloc)
    : AllocWrapper(sysAlloc),
      AllocStarter(&AllocWrapper, 8 * Heap_PageSize, 2 * Heap_PageSize),
      AllocBookkeeper(&AllocWrapper, 8 * Heap_PageSize),
      RootLock(),
      pArenas(0),
      NumArenas(0)
{
    GlobalPageTable->SetStarter(&AllocStarter);
    GlobalRoot = this;
}

HeapRoot::~HeapRoot()
{
}

void HeapRoot::CreateArena(UPInt arena, SysAllocPaged* sysAlloc)
{
    LockSafe::Locker lock(&RootLock);
    if (NumArenas < arena)
    {
        // grow the table in steps of 16
        UPInt           newNumArenas = (arena + 15) & ~UPInt(15);
        SysAllocPaged** newArenas    = (SysAllocPaged**)AllocBookkeeper.Alloc(newNumArenas * sizeof(void*));
        memset(newArenas, 0, newNumArenas * sizeof(void*));
        if (pArenas)
        {
            memcpy(newArenas, pArenas, NumArenas * sizeof(void*));
            AllocBookkeeper.Free(pArenas, NumArenas * sizeof(void*));
        }
        pArenas   = newArenas;
        NumArenas = newNumArenas;
    }
    pArenas[arena - 1] = (SysAllocPaged*)AllocBookkeeper.Alloc(sizeof(SysAllocWrapper));
    pArenas[arena - 1] = ::new(pArenas[arena - 1]) SysAllocWrapper(sysAlloc);
}

int HeapRoot::DestroyArena(UPInt arena)
{
    LockSafe::Locker lock(&RootLock);
    if (ArenaIsEmpty(arena))
    {
        pArenas[arena - 1]->~SysAllocPaged();
        AllocBookkeeper.Free(pArenas[arena - 1], sizeof(SysAllocWrapper));
        pArenas[arena - 1] = 0;
        return 0;
    }
    return *(int*)0;   // destroying an arena that still holds memory: crash on purpose
}

void HeapRoot::DestroyAllArenas()
{
    LockSafe::Locker lock(&RootLock);
    if (pArenas)
    {
        for (UPInt i = NumArenas; i; --i)
        {
            if (pArenas[i - 1])
                DestroyArena(i);
        }
        AllocBookkeeper.Free(pArenas, NumArenas * sizeof(void*));
        pArenas   = 0;
        NumArenas = 0;
    }
}

bool HeapRoot::ArenaIsEmpty(UPInt arena)
{
    LockSafe::Locker lock(&RootLock);
    return GetSysAlloc(arena)->GetUsedSpace() == 0;
}

SysAllocPaged* HeapRoot::GetSysAlloc(UPInt arena)
{
    LockSafe::Locker lock(&RootLock);
    if (arena)
        return pArenas[arena - 1];
    return &AllocWrapper;
}

// one bookkeeper block holds the heap object, its engine and the name
MemoryHeapPT* HeapRoot::CreateHeap(const char* name, MemoryHeapPT* parent, const MemoryHeap::HeapDesc& desc)
{
    if (GetSysAlloc(0) == 0)
    {
    }

    UPInt selfSize = sizeof(MemoryHeapPT) + sizeof(AllocEngine) + strlen(name) + 1;
    selfSize       = (selfSize + Heap_MinMask) & ~UPInt(Heap_MinMask);

    UByte* heapBuf = (UByte*)AllocBookkeeper.Alloc(selfSize);
    if (heapBuf == 0)
        return 0;

    unsigned engineFlags = 0;
    if (desc.Flags & MemoryHeap::Heap_FastTinyBlocks)
        engineFlags |= Heap_AllowTinyBlocks;
    if ((desc.Flags & MemoryHeap::Heap_FixedGranularity) == 0)
        engineFlags |= Heap_AllowDynaSize;

    MemoryHeapPT* heap   = ::new(heapBuf) MemoryHeapPT;
    AllocEngine*  engine = ::new(heapBuf + sizeof(MemoryHeapPT))
        AllocEngine(GetSysAlloc(desc.Arena), heap, engineFlags, desc.MinAlign, desc.Granularity, desc.Reserve,
                    desc.Threshold, desc.Limit);
    if (!engine->IsValid())
    {
        AllocBookkeeper.Free(heapBuf, selfSize);
        return 0;
    }

    heap->SelfSize       = selfSize;
    heap->RefCount       = 1;
    heap->pAutoRelease   = 0;
    heap->Info.Desc      = desc;
    heap->Info.pParent   = parent;
    heap->Info.pName     = (char*)heapBuf + sizeof(MemoryHeapPT) + sizeof(AllocEngine);
    heap->UseLocks       = (desc.Flags & MemoryHeap::Heap_ThreadUnsafe) == 0;
    heap->TrackDebugInfo = (desc.Flags & MemoryHeap::Heap_NoDebugInfo) == 0;
    heap->pEngine        = engine;
    memcpy(heap->Info.pName, name, strlen(name) + 1);
    return heap;
}

void HeapRoot::DestroyHeap(MemoryHeapPT* heap)
{
    heap->pEngine->FreeAll();
    heap->~MemoryHeapPT();
    AllocBookkeeper.Free(heap, heap->SelfSize);
}

void HeapRoot::VisitSegments(SegVisitor* visitor) const
{
    LockSafe::Locker lock(&RootLock);
    const SysAllocPaged* sysAlloc = &AllocWrapper;
    sysAlloc->VisitSegments(visitor, SegVisitor::Seg_SysMem, SegVisitor::Seg_SysMemUnused);
    AllocStarter.VisitSegments(visitor);
    AllocBookkeeper.VisitSegments(visitor);
}

void HeapRoot::GetStats(MemoryHeap::RootStats* stats) const
{
    LockSafe::Locker lock(&RootLock);
    const SysAllocPaged* sysAlloc = &AllocWrapper;
    stats->SysMemFootprint      = sysAlloc->GetFootprint();
    stats->SysMemUsedSpace      = sysAlloc->GetUsedSpace();
    stats->PageMapFootprint     = AllocStarter.GetFootprint();
    stats->PageMapUsedSpace     = AllocStarter.GetUsedSpace();
    stats->BookkeepingFootprint = AllocBookkeeper.GetFootprint();
    stats->BookkeepingUsedSpace = AllocBookkeeper.GetUsedSpace();
    stats->DebugInfoFootprint   = 0;
    stats->DebugInfoUsedSpace   = 0;
}

void* HeapRoot::AllocSysDirect(UPInt size)
{
    LockSafe::Locker lock(&RootLock);
    return AllocWrapper.AllocSysDirect(size);
}

void HeapRoot::FreeSysDirect(void* ptr, UPInt size)
{
    LockSafe::Locker lock(&RootLock);
    AllocWrapper.FreeSysDirect(ptr, size);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0HeapRoot@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@@Z 0x1426ce850
// MS2-PIN: ??0SysAllocGranulator@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@@Z 0x1426ce8e0
// MS2-PIN: ??0SysAllocWrapper@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@@Z 0x1426ce950
// MS2-PIN: ??1HeapRoot@HeapPT@Scaleform@@QEAA@XZ 0x1426cea50
// MS2-PIN: ??_GSysAllocGranulator@HeapPT@Scaleform@@UEAAPEAXI@Z 0x1426cea80
// MS2-PIN: ??_GSysAllocWrapper@HeapPT@Scaleform@@UEAAPEAXI@Z 0x1426ceab0
// MS2-PIN: ?AllocSysDirect@HeapRoot@HeapPT@Scaleform@@QEAAPEAX_K@Z 0x1426ceb10
// MS2-PIN: ?AllocSysDirect@SysAllocGranulator@HeapPT@Scaleform@@UEAAPEAX_K0PEA_K1@Z 0x1426ceb90
// MS2-PIN: ?ArenaIsEmpty@HeapRoot@HeapPT@Scaleform@@QEAA_N_K@Z 0x1426cec50
// MS2-PIN: ?CreateArena@HeapRoot@HeapPT@Scaleform@@QEAAX_KPEAVSysAllocPaged@3@@Z 0x1426cecd0
// MS2-PIN: ?CreateHeap@HeapRoot@HeapPT@Scaleform@@QEAAPEAVMemoryHeapPT@3@PEBDPEAV43@AEBUHeapDesc@MemoryHeap@3@@Z 0x1426cedf0
// MS2-PIN: ?DestroyAllArenas@HeapRoot@HeapPT@Scaleform@@QEAAXXZ 0x1426cf000
// MS2-PIN: ?DestroyArena@HeapRoot@HeapPT@Scaleform@@QEAAH_K@Z 0x1426cf160
// MS2-PIN: ?DestroyHeap@HeapRoot@HeapPT@Scaleform@@QEAAXPEAVMemoryHeapPT@3@@Z 0x1426cf250
// MS2-PIN: ?FreeSysDirect@HeapRoot@HeapPT@Scaleform@@QEAAXPEAX_K@Z 0x1426cf2d0
// MS2-PIN: ?GetStats@HeapRoot@HeapPT@Scaleform@@QEBAXPEAURootStats@MemoryHeap@3@@Z 0x1426cf480
// MS2-PIN: ?GetSysAlloc@HeapRoot@HeapPT@Scaleform@@QEAAPEAVSysAllocPaged@3@_K@Z 0x1426cf540
// MS2-PIN: ?Init@SysAllocGranulator@HeapPT@Scaleform@@QEAAXPEAVSysAllocPaged@3@@Z 0x1426cf5e0
// MS2-PIN: ?VisitSegments@HeapRoot@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@@Z 0x1426cf700
// MS2-PIN: ??_7SysAllocPaged@Scaleform@@6B@ 0x1431841e0
// MS2-PIN: ??0SysAllocGranulator@HeapPT@Scaleform@@QEAA@XZ 0x1426ce920
// MS2-PIN: ?Alloc@SysAllocGranulator@HeapPT@Scaleform@@UEAAPEAX_K0@Z 0x1426ceae0
// MS2-PIN: ?Alloc@SysAllocWrapper@HeapPT@Scaleform@@UEAAPEAX_K0@Z 0x1426ceaf0
// MS2-PIN: ?AllocSysDirect@SysAllocWrapper@HeapPT@Scaleform@@QEAAPEAX_K@Z 0x1426cebf0
// MS2-PIN: ?AllocSysDirect@SysAllocWrapper@HeapPT@Scaleform@@UEAAPEAX_K0PEA_K1@Z 0x1426cec30
// MS2-PIN: ?Free@SysAllocGranulator@HeapPT@Scaleform@@UEAA_NPEAX_K1@Z 0x1426cf2a0
// MS2-PIN: ?Free@SysAllocWrapper@HeapPT@Scaleform@@UEAA_NPEAX_K1@Z 0x1426cf2b0
// MS2-PIN: ?FreeSysDirect@SysAllocGranulator@HeapPT@Scaleform@@UEAA_NPEAX_K1@Z 0x1426cf360
// MS2-PIN: ?FreeSysDirect@SysAllocWrapper@HeapPT@Scaleform@@QEAAXPEAX_K@Z 0x1426cf380
// MS2-PIN: ?FreeSysDirect@SysAllocWrapper@HeapPT@Scaleform@@UEAA_NPEAX_K1@Z 0x1426cf3c0
// MS2-PIN: ?GetBase@SysAllocGranulator@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf3e0
// MS2-PIN: ?GetFootprint@SysAllocGranulator@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf3f0
// MS2-PIN: ?GetFootprint@SysAllocWrapper@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf400
// MS2-PIN: ?GetInfo@SysAllocGranulator@HeapPT@Scaleform@@UEBAXPEAUInfo@SysAllocPaged@3@@Z 0x1426cf410
// MS2-PIN: ?GetInfo@SysAllocWrapper@HeapPT@Scaleform@@UEBAXPEAUInfo@SysAllocPaged@3@@Z 0x1426cf440
// MS2-PIN: ?GetSize@SysAllocGranulator@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf470
// MS2-PIN: ?GetUsedSpace@SysAllocGranulator@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf5a0
// MS2-PIN: ?GetUsedSpace@SysAllocWrapper@HeapPT@Scaleform@@UEBA_KXZ 0x1426cf5d0
// MS2-PIN: ?ReallocInPlace@SysAllocGranulator@HeapPT@Scaleform@@UEAA_NPEAX_K11@Z 0x1426cf6a0
// MS2-PIN: ?ReallocInPlace@SysAllocWrapper@HeapPT@Scaleform@@UEAA_NPEAX_K11@Z 0x1426cf6b0
// MS2-PIN: ?VisitMem@SysAllocGranulator@HeapPT@Scaleform@@UEBAXPEAVMemVisitor@Heap@3@@Z 0x1426cf6d0
// MS2-PIN: ?VisitMem@SysAllocWrapper@HeapPT@Scaleform@@UEBAXPEAVMemVisitor@Heap@3@@Z 0x1426cf6f0
// MS2-PIN: ?VisitSegments@SysAllocGranulator@HeapPT@Scaleform@@UEBAXPEAVSegVisitor@Heap@3@_K1@Z 0x1426cf780
// MS2-PIN: ?VisitSegments@SysAllocWrapper@HeapPT@Scaleform@@UEBAXPEAVSegVisitor@Heap@3@_K1@Z 0x1426cf790
// MS2-PIN: ??_7SysAllocGranulator@HeapPT@Scaleform@@6B@ 0x143193200
// MS2-PIN: ??_7SysAllocWrapper@HeapPT@Scaleform@@6B@ 0x143193278
