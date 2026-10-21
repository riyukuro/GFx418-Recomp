// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_Granulator (carves
// granularity-sized system segments into AllocLite blocks; segment headers live on dedicated header pages).
// Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f01d0-0x1426f0e80 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_granulator.h"

namespace Scaleform { namespace HeapPT {

Granulator::Granulator(SysAllocPaged* sysAlloc, UPInt minSize, UPInt granularity, UPInt hdrPageSize)
    : pSysAlloc(sysAlloc),
      Granularity(granularity),
      HdrPageSize(hdrPageSize),
      HdrCapacity((hdrPageSize - sizeof(HdrPage)) / sizeof(Segment)),
      MinAlign(0),
      MaxAlign(0),
      HasRealloc(false),
      HdrList(),
      FreeSeg(),
      UsedSeg(),
      Footprint(0),
      Allocator(minSize)
{
    SysAllocPaged::Info i;
    memset(&i, 0, sizeof(SysAllocPaged::Info));
    pSysAlloc->GetInfo(&i);
    if (i.Granularity < Heap_PageSize)
        i.Granularity = Heap_PageSize;
    MinAlign = i.MinAlign;
    MaxAlign = i.MaxAlign;
    if (MinAlign == 0)
        MinAlign = 1;
    if (MaxAlign == 0)
        MaxAlign = UPInt(1) << (8 * sizeof(UPInt) - 1);
    HasRealloc  = i.HasRealloc;
    Granularity = (Granularity + i.Granularity - 1) / i.Granularity * i.Granularity;
}

// get a new system segment big enough for the request; when no free segment header is left the new segment starts
// with a header page that provides HdrCapacity more
bool Granulator::allocSegment(UPInt size, UPInt alignSize)
{
    if (alignSize < MinAlign)
        alignSize = MinAlign;

    UPInt hdrPageSize = FreeSeg.IsEmpty() ? HdrPageSize : 0;
    UPInt segAlign    = alignSize;
    UPInt minSize     = Allocator.GetMinSize();
    if (segAlign < minSize)
        segAlign = minSize;
    if (segAlign > MaxAlign)
        segAlign = MaxAlign;

    // alignments the system cannot give are reached by over-allocating; an unaligned start costs one min block
    UPInt segSize;
    UPInt extraTail = (alignSize > MaxAlign) ? alignSize : 0;
    UPInt headAlign = (segAlign < minSize) ? minSize : 0;
    if (extraTail <= headAlign)
        extraTail = 0;
    segSize = (size + hdrPageSize + extraTail + alignSize - 1) & ~(alignSize - 1);
    segSize = (segSize + Granularity - 1) / Granularity * Granularity + headAlign;
    segSize = (segSize + minSize - 1) & ~(minSize - 1);

    UByte* newSpacePtr = (UByte*)pSysAlloc->Alloc(segSize, segAlign);
    if (newSpacePtr)
    {
        UByte*   newSpaceEnd = newSpacePtr + segSize;
        UByte*   alignedPtr  = (UByte*)((UPInt(newSpacePtr) + minSize - 1) & ~(minSize - 1));
        UByte*   alignedEnd  = (UByte*)((UPInt(newSpaceEnd)) & ~(minSize - 1));
        Segment* seg;
        if (hdrPageSize)
        {
            memset(alignedPtr, 0, hdrPageSize);
            HdrPage* hdr  = (HdrPage*)alignedPtr;
            hdr->UseCount = 0;
            for (UPInt i = 0; i < HdrCapacity; ++i)
            {
                seg          = (Segment*)(alignedPtr + sizeof(HdrPage) + i * sizeof(Segment));
                seg->Headers = hdr;
                FreeSeg.PushBack(seg);
            }
            HdrList.PushBack(hdr);
        }
        seg = FreeSeg.GetFirst();
        SegListType::Remove(seg);
        ++seg->Headers->UseCount;
        seg->Buffer     = alignedPtr + hdrPageSize;
        seg->Size       = alignedEnd - seg->Buffer;
        seg->UseCount   = 0;
        seg->AlignShift = Alg::UpperBit(segAlign);
        seg->HeadBytes  = UPIntHalf(alignedPtr - newSpacePtr);
        UsedSeg.Insert(seg);
        Allocator.InitSegment(seg);
        Footprint += segSize;
        return true;
    }
    return false;
}

// give an empty segment back; a header page whose only remaining user is its own segment goes with it
bool Granulator::freeSegment(Segment* seg)
{
    HdrPage* hdrPage = seg->Headers;
    bool     ret     = true;
    UPInt    segSize;
    if (!hasHeaders(seg))
    {
        UsedSeg.Remove(seg);
        FreeSeg.PushFront(seg);
        --hdrPage->UseCount;
        segSize = getSegSize(seg);
        Allocator.ReleaseSegment(seg);
        Footprint -= segSize;
        ret = pSysAlloc->Free(getSegBase(seg), segSize, UPInt(1) << UPInt(seg->AlignShift));
    }
    if (hdrPage->UseCount == 1)
    {
        Segment* hdrSeg = (Segment*)UsedSeg.FindEqual(UPInt(hdrPage) + HdrPageSize);
        if (hdrSeg->UseCount == 0)
        {
            UsedSeg.Remove(hdrSeg);
            FreeSeg.PushFront(hdrSeg);
            UByte* hptr = (UByte*)hdrPage;
            for (UPInt i = 0; i < HdrCapacity; ++i)
            {
                seg = (Segment*)(hptr + sizeof(HdrPage) + i * sizeof(Segment));
                FreeSeg.Remove(seg);
            }
            HdrList.Remove(hdrPage);
            segSize = getSegSize(hdrSeg);
            Allocator.ReleaseSegment(hdrSeg);
            Footprint -= segSize;
            ret = pSysAlloc->Free(getSegBase(hdrSeg), segSize, UPInt(1) << UPInt(hdrSeg->AlignShift));
        }
    }
    return ret;
}

// up to two new segments: the first one may be eaten by its own header page
void* Granulator::Alloc(UPInt size, UPInt alignSize)
{
    Segment* seg;
    void*    ptr = Allocator.Alloc(size, alignSize, &seg);
    if (ptr)
    {
        ++seg->UseCount;
        return ptr;
    }
    if (!allocSegment(size, alignSize))
        return 0;

    ptr = Allocator.Alloc(size, alignSize, &seg);
    if (ptr)
    {
        ++seg->UseCount;
        return ptr;
    }
    if (!allocSegment(size, alignSize))
        return 0;

    ptr = Allocator.Alloc(size, alignSize, &seg);
    if (ptr)
        ++seg->UseCount;
    return ptr;
}

bool Granulator::Free(void* ptr, UPInt size, UPInt alignSize)
{
    Segment* seg = (Segment*)UsedSeg.FindLeEq(UPInt(ptr));
    Allocator.Free(seg, ptr, size, alignSize);
    if (--seg->UseCount == 0)
        return freeSegment(seg);
    return true;
}

// in-place resize inside the segment; at the segment tail the system block itself is grown or trimmed when the
// system allocator can do that
bool Granulator::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignSize)
{
    if (alignSize < Allocator.GetMinSize())
        alignSize = Allocator.GetMinSize();

    bool     ret = false;
    Segment* seg = (Segment*)UsedSeg.FindLeEq(UPInt(oldPtr));
    AllocLite::ReallocResult res = Allocator.ReallocInPlace(seg, (UByte*)oldPtr, oldSize, newSize, alignSize);
    if (!HasRealloc)
        return res < AllocLite::ReallocFailed;
    if (res == AllocLite::ReallocSucceeded)
        return true;

    UByte* segBase    = getSegBase(seg);
    UPInt  oldSegSize = getSegSize(seg);
    UPInt  newSegSize;

    UPInt buffer = UPInt(segBase);
    UPInt oldEnd = UPInt(oldPtr) - buffer + oldSize;
    UPInt newEnd = UPInt(oldPtr) - buffer + newSize;
    oldEnd       = (oldEnd + alignSize - 1) & ~(alignSize - 1);
    newEnd       = (newEnd + alignSize - 1) & ~(alignSize - 1);
    oldEnd       = (oldEnd + Granularity - 1) / Granularity * Granularity;
    newEnd       = (newEnd + Granularity - 1) / Granularity * Granularity;

    if (res == AllocLite::ReallocShrinkedAtTail)
    {
        if (newEnd < oldEnd)
        {
            newSegSize = buffer + newEnd - UPInt(segBase);
            Allocator.TrimAt(seg, (UByte*)(buffer + newEnd));
            if (pSysAlloc->ReallocInPlace(segBase, oldSegSize, newSegSize, UPInt(1) << seg->AlignShift))
                Footprint -= oldSegSize - newSegSize;
            else
                Allocator.Extend(seg, oldSegSize - newSegSize);
        }
        return true;
    }

    if (res == AllocLite::ReallocFailedAtTail)
    {
        while (newEnd <= oldEnd)
            newEnd += Granularity;
        newSegSize = buffer + newEnd - UPInt(segBase);
        if (pSysAlloc->ReallocInPlace(segBase, oldSegSize, newSegSize, UPInt(1) << seg->AlignShift))
        {
            Footprint += newSegSize - oldSegSize;
            Allocator.Extend(seg, newSegSize - oldSegSize);
            res = Allocator.ReallocInPlace(seg, (UByte*)oldPtr, oldSize, newSize, alignSize);
            return true;
        }
    }
    return ret;
}

void Granulator::VisitMem(MemVisitor* visitor, MemVisitor::Category, MemVisitor::Category catFree) const
{
    Allocator.VisitMem(visitor, catFree);
}

// whole pages of every used segment, its header page included
void Granulator::visitSegments(const Segment* node, SegVisitor* visitor, unsigned cat) const
{
    if (node)
    {
        visitSegments(node->AddrChild[0], visitor, cat);
        UPInt hdrPage = hasHeaders(node) ? HdrPageSize : 0;
        UPInt buffer  = (UPInt(node->Buffer) - hdrPage + Heap_PageMask) & ~UPInt(Heap_PageMask);
        UPInt size    = (node->Size + hdrPage) & ~UPInt(Heap_PageMask);
        visitor->Visit(cat, 0, buffer, size);
        visitSegments(node->AddrChild[1], visitor, cat);
    }
}

void Granulator::VisitSegments(SegVisitor* visitor, unsigned catSeg, unsigned catUnused) const
{
    visitSegments(UsedSeg.Root, visitor, catSeg);
    Allocator.VisitUnused(visitor, catUnused);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0Granulator@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@_K11@Z 0x1426f01d0
// MS2-PIN: ?Alloc@Granulator@HeapPT@Scaleform@@QEAAPEAX_K0@Z 0x1426f02f0
// MS2-PIN: ?FindLeEq@?$RadixTree@UTreeSeg@HeapPT@Scaleform@@USegTreeAccessor@Granulator@23@@Scaleform@@QEBAPEBUTreeSeg@HeapPT@2@_K@Z 0x1426f03b0
// MS2-PIN: ?Free@Granulator@HeapPT@Scaleform@@QEAA_NPEAX_K1@Z 0x1426f0470
// MS2-PIN: ?ReallocInPlace@Granulator@HeapPT@Scaleform@@QEAA_NPEAX_K11@Z 0x1426f0500
// MS2-PIN: ?Remove@?$RadixTree@UTreeSeg@HeapPT@Scaleform@@USegTreeAccessor@Granulator@23@@Scaleform@@QEAAXPEAUTreeSeg@HeapPT@2@@Z 0x1426f0750
// MS2-PIN: ?VisitMem@Granulator@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@W4Category@453@1@Z 0x1426f0810
// MS2-PIN: ?VisitSegments@Granulator@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@II@Z 0x1426f0820
// MS2-PIN: ?allocSegment@Granulator@HeapPT@Scaleform@@AEAA_N_K0@Z 0x1426f0870
// MS2-PIN: ?freeSegment@Granulator@HeapPT@Scaleform@@AEAA_NPEAUTreeSeg@23@@Z 0x1426f0b80
// MS2-PIN: ?visitSegments@Granulator@HeapPT@Scaleform@@AEBAXPEBUTreeSeg@23@PEAVSegVisitor@Heap@3@I@Z 0x1426f0dd0
