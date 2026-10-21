// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_SysAllocMapper (the
// paged system allocator over a SysMemMapper: address-space segments kept sorted by address, pages committed on demand,
// one bit per page in a map at the end of each segment).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426441a0-0x142645590 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_heaptypes.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocmapper.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_bitset1.h"
#include <string.h>

namespace Scaleform {

SysAllocMapper::SysAllocMapper(SysMemMapper* mapper, UPInt segSize, UPInt granularity, bool bestFit)
    : pMapper(mapper), PageSize(0), SegmSize(segSize), Granularity(granularity ? granularity : 1), Footprint(0),
      NumSegments(0), LastSegment(~UPInt(0)), BestFit(bestFit), LastUsed(0)
{
    PageSize    = pMapper->GetPageSize();
    PageShift   = Alg::UpperBit(PageSize);
    Granularity = (Granularity + PageSize - 1) & ~(PageSize - 1);
    Footprint   = 0;
    NumSegments = 0;
    LastSegment = ~UPInt(0);
}

void SysAllocMapper::GetInfo(Info* i) const
{
    i->MinAlign    = PageSize;
    i->MaxAlign    = 0;     // any alignment
    i->Granularity = (Granularity <= Heap::Heap_PageSize) ? 0 : Granularity;
    i->HasRealloc  = true;
}

// bytes of the page map of a segment (one bit per page, whole pages)
UPInt SysAllocMapper::getBitSize(UPInt size) const
{
    return (((size + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1) & ~(PageSize - 1);
}

UInt32* SysAllocMapper::getBitSet(const UByte* start, UPInt size) const
{
    return (UInt32*)(start + size - getBitSize(size));
}

// first page of the map: marked used so that free runs stop there
UPInt SysAllocMapper::getEndBit(UPInt size) const
{
    return (size - getBitSize(size)) >> PageShift;
}

inline bool SysAllocMapper::inRange(const UByte* ptr, const Segment* seg) const
{
    return ptr >= seg->Memory && ptr < seg->Memory + SegmSize;
}

// index of the first segment starting at or above ptr
UPInt SysAllocMapper::binarySearch(const UByte* ptr) const
{
    UPInt found = 0;
    SPInt len   = NumSegments;
    SPInt half;
    SPInt middle;
    while (len > 0)
    {
        half   = len >> 1;
        middle = found + half;
        if (Segments[middle].Memory < (UByte*)ptr)
        {
            found = middle + 1;
            len   = len - half - 1;
        }
        else
        {
            len = half;
        }
    }
    return found;
}

UPInt SysAllocMapper::findSegment(const UByte* ptr) const
{
    UPInt found = binarySearch(ptr);
    if (found && inRange(ptr, &Segments[found - 1]))
        return found - 1;
    if (found < NumSegments && inRange(ptr, &Segments[found]))
        return found;
    return NumSegments;
}

// reserve a new segment big enough for size (halving the request while the address space refuses it)
bool SysAllocMapper::reserveSegment(UPInt size)
{
    if (NumSegments < MaxSegments)
    {
        UPInt segSize = SegmSize;
        if ((segSize - getBitSize(segSize)) < size)
            segSize = (size + getBitSize(size) + Granularity - 1) / Granularity * Granularity;
        while ((segSize - getBitSize(segSize)) < size)
            segSize += Granularity;

        UByte* ptr = 0;
        do
        {
            ptr = (UByte*)pMapper->ReserveAddrSpace(segSize);
            if (ptr)
                break;
            segSize = (segSize / 2 + Granularity - 1) / Granularity * Granularity;
        } while (segSize >= 2 * Granularity && (segSize - getBitSize(segSize)) >= size);

        if (ptr)
        {
            UInt32* bitSet  = getBitSet(ptr, segSize);
            UPInt   bitSize = getBitSize(segSize);
            bitSet = (UInt32*)pMapper->MapPages(bitSet, bitSize);
            if (bitSet == 0)
            {
                pMapper->ReleaseAddrSpace(ptr, segSize);
                return false;
            }
            HeapPT::BitSet1::Clear(bitSet, bitSize / 4);
            HeapPT::BitSet1::SetBit(bitSet, getEndBit(segSize));

            UPInt pos = binarySearch(ptr);
            if (pos < NumSegments)
                memmove(Segments + pos + 1, Segments + pos, sizeof(Segment) * (NumSegments - pos));
            NumSegments++;
            Segment* seg   = &Segments[pos];
            seg->Memory    = ptr;
            seg->Size      = segSize;
            seg->PageCount = 0;
            return true;
        }
    }
    return false;
}

void SysAllocMapper::releaseSegment(UPInt pos)
{
    bool     ok;
    Segment* seg     = &Segments[pos];
    UInt32*  bitSet  = getBitSet(seg->Memory, seg->Size);
    UPInt    bitSize = getBitSize(seg->Size);
    ok = pMapper->UnmapPages(bitSet, bitSize);
    ok = pMapper->ReleaseAddrSpace(seg->Memory, seg->Size);
    SF_UNUSED(ok);
    if (pos + 1 < NumSegments)
        memmove(Segments + pos, Segments + pos + 1, sizeof(Segment) * (NumSegments - pos - 1));
    NumSegments--;
    LastSegment = ~UPInt(0);
}

UByte* SysAllocMapper::getAlignedPtr(const UByte* ptr, UPInt alignment) const
{
    return (UByte*)((UPInt(ptr) + alignment - 1) & ~(alignment - 1));
}

bool SysAllocMapper::alignmentIsOK(const UByte* ptr, UPInt size, UPInt alignment, UPInt limit) const
{
    const UByte* aligned = getAlignedPtr(ptr, alignment);
    return aligned + size <= ptr + limit;
}

// scan the free runs of one segment: the best fit, or the first fit when BestFit is off
void* SysAllocMapper::allocMem(UPInt pos, UPInt size, UPInt alignment)
{
    UByte*   ptr    = 0;
    Segment* seg    = &Segments[pos];
    UInt32*  bitSet = getBitSet(seg->Memory, seg->Size);
    UPInt    pages  = size >> PageShift;
    UPInt    limit  = getEndBit(seg->Size);
    UPInt    start  = 0;
    UPInt    rest   = ~UPInt(0);
    UPInt    found  = ~UPInt(0);
    while (start < limit)
    {
        if (HeapPT::BitSet1::GetValue(bitSet, start))
        {
            start += HeapPT::BitSet1::FindUsedSize(bitSet, start, limit);
        }
        else
        {
            UPInt freeSize = HeapPT::BitSet1::FindFreeSize(bitSet, start);
            if (alignmentIsOK(seg->Memory + start * PageSize, size, alignment, freeSize * PageSize) &&
                freeSize - pages < rest)
            {
                found = start;
                rest  = freeSize - pages;
                if (!BestFit)
                    break;
            }
            start += freeSize;
        }
    }

    if (found != ~UInt32(0))
    {
        ptr = getAlignedPtr(seg->Memory + found * PageSize, alignment);
        UPInt head = (ptr - (seg->Memory + found * PageSize)) >> PageShift;
        ptr = (UByte*)pMapper->MapPages(seg->Memory + (found + head) * PageSize, size);
        if (ptr)
        {
            HeapPT::BitSet1::SetUsed(bitSet, found + head, pages);
            seg->PageCount += pages;
            Footprint      += pages << PageShift;
        }
    }
    LastSegment = ptr ? pos : ~UPInt(0);
    LastUsed    = (UByte*)ptr + size;
    return ptr;
}

// the segment that served the last request first, then the others
void* SysAllocMapper::allocMem(UPInt size, UPInt alignment)
{
    void* ptr = 0;
    if (LastSegment != ~UPInt(0))
    {
        ptr = allocMem(LastSegment, size, alignment);
        if (ptr)
            return ptr;
        LastUsed = 0;
    }
    for (UPInt i = 0; i < NumSegments; ++i)
    {
        if (i != LastSegment)
        {
            ptr = allocMem(i, size, alignment);
            if (ptr)
                return ptr;
            LastUsed = 0;
        }
    }
    return 0;
}

UPInt SysAllocMapper::freeMem(void* ptr, UPInt size)
{
    UPInt    pos = findSegment((UByte*)ptr);
    Segment* seg = &Segments[pos];
    bool     ok  = pMapper->UnmapPages(ptr, size);
    SF_UNUSED(ok);
    UPInt    start  = ((UByte*)ptr - seg->Memory) >> PageShift;
    UInt32*  bitSet = getBitSet(seg->Memory, seg->Size);
    UPInt    pages  = size >> PageShift;
    HeapPT::BitSet1::SetFree(bitSet, start, pages);
    seg->PageCount -= pages;
    Footprint      -= pages << PageShift;
    return pos;
}

void* SysAllocMapper::Alloc(UPInt size, UPInt alignment)
{
    if (alignment < PageSize)
        alignment = PageSize;
    size = (size + alignment - 1) & ~(alignment - 1);
    void* ptr = allocMem(size, alignment);
    if (ptr)
        return ptr;
    if (!reserveSegment(size))
        return 0;
    return allocMem(size, alignment);
}

bool SysAllocMapper::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignment)
{
    if (alignment < PageSize)
        alignment = PageSize;
    oldSize = (oldSize + alignment - 1) & ~(alignment - 1);
    newSize = (newSize + alignment - 1) & ~(alignment - 1);
    if (newSize == oldSize)
        return true;

    if (newSize > oldSize)
    {
        // commit the free pages right after the block
        UPInt    pos      = findSegment((UByte*)oldPtr);
        Segment* seg      = &Segments[pos];
        UPInt    start    = ((UByte*)oldPtr + oldSize - seg->Memory) >> PageShift;
        UInt32*  bitSet   = getBitSet(seg->Memory, seg->Size);
        UPInt    addPages = (newSize - oldSize) >> PageShift;
        UPInt    freeSize = HeapPT::BitSet1::FindFreeSize(bitSet, start);
        if (freeSize >= addPages)
        {
            if (pMapper->MapPages(seg->Memory + start * PageSize, newSize - oldSize))
            {
                HeapPT::BitSet1::SetUsed(bitSet, start, addPages);
                seg->PageCount += addPages;
                Footprint      += addPages << PageShift;
                return true;
            }
        }
    }
    else
    {
        return Free((UByte*)oldPtr + newSize, oldSize - newSize, alignment);
    }
    return false;
}

bool SysAllocMapper::Free(void* ptr, UPInt size, UPInt alignment)
{
    if (alignment < PageSize)
        alignment = PageSize;
    size = (size + alignment - 1) & ~(alignment - 1);
    UPInt pos = freeMem(ptr, size);
    if (Segments[pos].PageCount == 0)
        releaseSegment(pos);
    return true;
}

UPInt SysAllocMapper::GetBase() const
{
    return NumSegments ? UPInt(Segments[0].Memory) : 0;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0SysAllocMapper@Scaleform@@QEAA@PEAVSysMemMapper@1@_K1_N@Z 0x1426441a0
// MS2-PIN: ??_GSysAllocMapper@Scaleform@@UEAAPEAXI@Z 0x142644340
// MS2-PIN: ?Alloc@SysAllocMapper@Scaleform@@UEAAPEAX_K0@Z 0x142644370
// MS2-PIN: ?FindFreeSize@BitSet1@HeapPT@Scaleform@@SA_KPEBK_K@Z 0x1426443f0
// MS2-PIN: ?Free@SysAllocMapper@Scaleform@@UEAA_NPEAX_K1@Z 0x142644520
// MS2-PIN: ?ReallocInPlace@SysAllocMapper@Scaleform@@UEAA_NPEAX_K11@Z 0x142644780
// MS2-PIN: ?SetUsed@BitSet1@HeapPT@Scaleform@@SAXPEAK_K1@Z 0x1426448c0
// MS2-PIN: ?allocMem@SysAllocMapper@Scaleform@@AEAAPEAX_K00@Z 0x142644980
// MS2-PIN: ?allocMem@SysAllocMapper@Scaleform@@AEAAPEAX_K0@Z 0x142644e40
// MS2-PIN: ?binarySearch@SysAllocMapper@Scaleform@@AEBA_KPEBE@Z 0x142644ef0
// MS2-PIN: ?findSegment@SysAllocMapper@Scaleform@@AEBA_KPEBE@Z 0x142644f50
// MS2-PIN: ?freeMem@SysAllocMapper@Scaleform@@AEAA_KPEAX_K@Z 0x142645000
// MS2-PIN: ?releaseSegment@SysAllocMapper@Scaleform@@AEAAX_K@Z 0x1426451f0
// MS2-PIN: ?reserveSegment@SysAllocMapper@Scaleform@@AEAA_N_K@Z 0x1426452e0
// MS2-PIN: ??_7SysAllocPaged@Scaleform@@6B@ 0x1431841e0
// MS2-PIN: ??_7SysAllocMapper@Scaleform@@6B@ 0x14318fe48
// MS2-PIN: ?GetBase@SysAllocMapper@Scaleform@@UEBA_KXZ 0x142644710
// MS2-PIN: ?GetFootprint@SysAllocMapper@Scaleform@@UEBA_KXZ 0x142644730
// MS2-PIN: ?GetInfo@SysAllocMapper@Scaleform@@UEBAXPEAUInfo@SysAllocPaged@2@@Z 0x142644740
// MS2-PIN: ?GetUsedSpace@SysAllocMapper@Scaleform@@UEBA_KXZ 0x142644770
