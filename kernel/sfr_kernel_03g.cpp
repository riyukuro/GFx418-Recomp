// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_Bookkeeper (the
// allocator for segment headers and heap objects: page-aligned system segments carved by an AllocBitSet1). Our own
// source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f0e80-0x1426f1520 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_bookkeeper.h"

namespace Scaleform { namespace HeapPT {

Bookkeeper::Bookkeeper(SysAllocPaged* sysAlloc, UPInt granularity)
    : pSysAlloc(sysAlloc), Granularity(granularity), Allocator(Heap_MinShift), Footprint(0)
{
    SysAllocPaged::Info i;
    memset(&i, 0, sizeof(SysAllocPaged::Info));
    pSysAlloc->GetInfo(&i);
    if (i.Granularity < Heap_PageSize)
        i.Granularity = Heap_PageSize;
    Granularity = (Granularity + i.Granularity - 1) / i.Granularity * i.Granularity;
}

// the segment header plus its bit set, rounded to the minimal block
UPInt Bookkeeper::getHeaderSize(UPInt dataSize) const
{
    UPInt headerSize;
    headerSize = sizeof(HeapSegment) + Allocator.GetBitSetBytes(dataSize);
    headerSize = (headerSize + Heap_MinMask) & ~UPInt(Heap_MinMask);
    return headerSize;
}

// the header sits at the start of the segment's own memory
HeapSegment* Bookkeeper::allocSegment(UPInt dataSize)
{
    UByte*       segMem = (UByte*)pSysAlloc->Alloc(dataSize, Heap_PageSize);
    HeapSegment* seg    = (HeapSegment*)segMem;
    UPInt        headerSize;
    if (seg)
    {
        seg->SelfSize  = dataSize;
        seg->SegType   = Heap_SegmentBookkeeper;
        seg->Alignment = Heap_PageShift;
        seg->UseCount  = 0;
        seg->pHeap     = 0;
        seg->DataSize  = 0;
        seg->pData     = 0;
        if (!GlobalPageTable->MapRange(segMem, dataSize))
        {
            pSysAlloc->Free(segMem, dataSize, Heap_PageSize);
            return 0;
        }
        GlobalPageTable->SetSegmentInRange(UPInt(segMem), dataSize, seg);
        headerSize    = getHeaderSize(dataSize);
        seg->DataSize = dataSize - headerSize;
        seg->pData    = segMem + headerSize;
        SegmentList.PushFront(seg);
        Allocator.InitSegment(seg);
        Footprint += seg->SelfSize;
        return seg;
    }
    return 0;
}

void Bookkeeper::freeSegment(HeapSegment* seg)
{
    Allocator.ReleaseSegment(seg);
    SegmentListType::Remove(seg);
    GlobalPageTable->UnmapRange(seg, seg->SelfSize);
    Footprint -= seg->SelfSize;
    pSysAlloc->Free(seg, seg->SelfSize, Heap_PageSize);
}

void* Bookkeeper::Alloc(UPInt size)
{
    size = Allocator.AlignSize((size < Heap_MinSize) ? Heap_MinSize : size);
    HeapSegment* seg;
    void*        ptr = Allocator.Alloc(size, &seg);
    if (ptr)
    {
        seg->UseCount++;
        return ptr;
    }

    // a new segment that fits the block next to its own header
    UPInt segSize = (size + Granularity - 1) / Granularity * Granularity;
    while (segSize < size + getHeaderSize(segSize))
        segSize += Granularity;
    seg = allocSegment(segSize);
    if (seg == 0)
        return 0;

    HeapSegment* t;
    ptr = Allocator.Alloc(size, &t);
    seg->UseCount++;
    return ptr;
}

void Bookkeeper::Free(void* ptr, UPInt size)
{
    HeapSegment* seg = GlobalPageTable->GetSegmentSafe(UPInt(ptr));
    size = Allocator.AlignSize((size < Heap_MinSize) ? Heap_MinSize : size);
    Allocator.Free(seg, ptr, size);
    if (--seg->UseCount == 0)
        freeSegment(seg);
}

void Bookkeeper::VisitMem(MemVisitor* visitor, unsigned flags) const
{
    if (flags & MemVisitor::VF_Bookkeeper)
    {
        const HeapSegment* seg = SegmentList.GetFirst();
        while (!SegmentList.IsNull(seg))
        {
            visitor->Visit(seg, UPInt(seg->pData), seg->DataSize, MemVisitor::Cat_Bookkeeper);
            seg = seg->pNext;
        }
        if (flags & MemVisitor::VF_BookkeeperFree)
            Allocator.VisitMem(visitor, MemVisitor::Cat_BookkeeperFree);
    }
}

void Bookkeeper::VisitSegments(SegVisitor* visitor) const
{
    const HeapSegment* seg = SegmentList.GetFirst();
    while (!SegmentList.IsNull(seg))
    {
        visitor->Visit(SegVisitor::Seg_Bookkeeper, 0, UPInt(seg), seg->SelfSize);
        seg = seg->pNext;
    }
    Allocator.VisitUnused(visitor, SegVisitor::Seg_BookkeeperUnused);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0Bookkeeper@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@_K@Z 0x1426f0e80
// MS2-PIN: ?Alloc@Bookkeeper@HeapPT@Scaleform@@QEAAPEAX_K@Z 0x1426f0f30
// MS2-PIN: ?Free@Bookkeeper@HeapPT@Scaleform@@QEAAXPEAX_K@Z 0x1426f1120
// MS2-PIN: ?VisitMem@Bookkeeper@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@I@Z 0x1426f1250
// MS2-PIN: ?VisitSegments@Bookkeeper@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@@Z 0x1426f12f0
// MS2-PIN: ?allocSegment@Bookkeeper@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@_K@Z 0x1426f1370
// MS2-PIN: ?freeSegment@Bookkeeper@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426f1480
