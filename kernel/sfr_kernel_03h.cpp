// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_AllocBitSet2 (the
// general PT block allocator: free runs in a FreeBin, busy runs described by the segment's 2-bit map, alignment kept
// at the run tail for realloc). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its
// original sources.
// MS2-UNIT: sfr_kernel_03h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f1520-0x1426f2460 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_heapbitset2.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocbitset2.h"

namespace Scaleform { namespace HeapPT {

AllocBitSet2::AllocBitSet2(UPInt minAlignShift)
    : MinAlignShift(minAlignShift), MinAlignMask((UPInt(1) << minAlignShift) - 1)
{ }

// a fresh segment is one free run
void AllocBitSet2::InitSegment(HeapSegment* seg)
{
    BitSet2::MarkFree(GetBitSet(seg), 0, seg->DataSize >> MinAlignShift);
    Bin.Push(seg, seg->pData, seg->DataSize >> MinAlignShift, MinAlignShift);
}

// only valid for an empty segment: its single free run leaves the bins
void AllocBitSet2::ReleaseSegment(HeapSegment* seg)
{
    Bin.Pull(seg->pData);
}

// best fit; a tail too small to be a free block stays with the allocation
void* AllocBitSet2::Alloc(UPInt bytes, HeapSegment** allocSeg)
{
    UByte* best = (UByte*)Bin.PullBest(bytes >> MinAlignShift);
    if (best)
    {
        HeapSegment* seg        = ((BinLNode*)best)->pSegment;
        UPInt        shift      = MinAlignShift;
        UPInt        blocks     = bytes >> shift;
        UInt32*      bitSet     = GetBitSet(seg);
        UByte*       base       = seg->pData;
        UPInt        tailBlocks = Bin.GetSize(best) - blocks;
        UPInt        tailBytes  = tailBlocks << shift;
        if (tailBytes >= Heap_MinSize)
        {
            Bin.Push(seg, best + bytes, tailBlocks, shift);
            BitSet2::MarkFree(bitSet, (best + bytes - base) >> shift, tailBlocks);
        }
        else
        {
            bytes += tailBytes;
        }
        BitSet2::MarkBusy(bitSet, (best - base) >> shift, bytes >> shift, 0);
        *allocSeg = seg;
    }
    return best;
}

// aligned variant: the head before the aligned address and the tail go back to the bins
void* AllocBitSet2::Alloc(UPInt bytes, UPInt alignSize, HeapSegment** allocSeg)
{
    UPInt  shift     = MinAlignShift;
    UPInt  blocks    = bytes >> shift;
    UPInt  alignMask = alignSize - 1;
    UByte* best      = (UByte*)Bin.PullBest(blocks, shift, alignMask);
    if (best)
    {
        HeapSegment* seg       = ((BinLNode*)best)->pSegment;
        UInt32*      bitSet    = GetBitSet(seg);
        UByte*       base      = seg->pData;
        UByte*       aligned   = ListBin::GetAlignedPtr(best, alignMask);
        UPInt        headBytes = aligned - best;
        UPInt        tailBytes = (best + (Bin.GetSize(best) << shift)) - (aligned + bytes);
        if (headBytes)
        {
            Bin.Push(seg, best, headBytes >> shift, shift);
            BitSet2::MarkFree(bitSet, (best - base) >> shift, headBytes >> shift);
        }
        if (tailBytes >= Heap_MinSize)
        {
            Bin.Push(seg, aligned + bytes, tailBytes >> shift, shift);
            BitSet2::MarkFree(bitSet, (aligned + bytes - base) >> shift, tailBytes >> shift);
        }
        else
        {
            bytes += tailBytes;
        }
        BitSet2::MarkBusy(bitSet, (aligned - base) >> shift, bytes >> shift, Alg::UpperBit(alignSize) - shift);
        *allocSeg = seg;
        return aligned;
    }
    return 0;
}

// free and merge with free neighbours inside the segment
void AllocBitSet2::Free(HeapSegment* seg, void* ptr)
{
    bool    left, right, tail;
    UPInt   blocks;
    UPInt   bytes;
    UByte*  base   = seg->pData;
    UByte*  end    = base + seg->DataSize;
    UInt32* bitSet = GetBitSet(seg);
    UPInt   shift  = MinAlignShift;
    UPInt   start  = ((UByte*)ptr - base) >> shift;

    blocks = BitSet2::GetBlockSize(bitSet, start);
    bytes  = blocks << shift;
    BitSet2::MarkFree(bitSet, start, blocks);

    tail  = (UByte*)ptr + bytes < end;
    left  = start && BitSet2::GetValue(bitSet, start - 1) == 0;
    right = tail && BitSet2::GetValue(bitSet, start + blocks) == 0;
    Bin.MakeNode(seg, (UByte*)ptr, blocks, shift);
    if (left | right)
        Bin.Merge((UByte*)ptr, shift, left, right);
    else
        Bin.Push((UByte*)ptr);
}

// grow into a free right neighbour or give the shrunk tail back; 0 when it cannot grow in place
void* AllocBitSet2::ReallocInPlace(HeapSegment* seg, void* oldPtr, UPInt newSize, UPInt* oldSize)
{
    UPInt    newBytes = newSize;
    UByte*   base     = seg->pData;
    UByte*   end      = base + seg->DataSize;
    UInt32*  bitSet   = GetBitSet(seg);
    UPInt    shift    = MinAlignShift;
    UPInt    start    = ((UByte*)oldPtr - base) >> shift;
    UPInt    blocks   = BitSet2::GetBlockSize(bitSet, start);
    unsigned alignSh  = BitSet2::GetAlignShift(bitSet, start, blocks);
    UPInt    alignMsk = (UPInt(1) << (alignSh + MinAlignShift)) - 1;
    UPInt    oldBytes = blocks << shift;
    UByte*   nextAdj;

    *oldSize = oldBytes;
    newBytes = (newBytes + alignMsk) & ~alignMsk;
    if (newBytes > oldBytes)
    {
        nextAdj = (UByte*)oldPtr + oldBytes;
        if (nextAdj < end && BitSet2::GetValue(bitSet, start + blocks) == 0)
        {
            UPInt nextBytes = Bin.GetSize(nextAdj) << shift;
            if (newBytes <= oldBytes + nextBytes)
            {
                Bin.Pull(nextAdj);
                UPInt tailBytes = oldBytes + nextBytes - newBytes;
                if (tailBytes >= Heap_MinSize)
                {
                    UByte* tailBlock = (UByte*)oldPtr + newBytes;
                    Bin.Push(seg, tailBlock, tailBytes >> shift, shift);
                    BitSet2::MarkFree(bitSet, (tailBlock - base) >> shift, tailBytes >> shift);
                }
                else
                {
                    newBytes += tailBytes;
                }
                BitSet2::MarkBusy(bitSet, start, newBytes >> shift, alignSh);
                return oldPtr;
            }
        }
        return 0;
    }
    if (newBytes < oldBytes)
    {
        UPInt thisTail = oldBytes - newBytes;
        UPInt nextTail = 0;
        nextAdj        = (UByte*)oldPtr + oldBytes;
        if (nextAdj < end && BitSet2::GetValue(bitSet, start + blocks) == 0)
            nextTail = Bin.GetSize(nextAdj) << shift;
        if (thisTail + nextTail >= Heap_MinSize)
        {
            if (nextTail)
                Bin.Pull(nextAdj);
            nextAdj   = (UByte*)oldPtr + newBytes;
            thisTail += nextTail;
            Bin.Push(seg, nextAdj, thisTail >> shift, shift);
            BitSet2::MarkBusy(bitSet, start, newBytes >> shift, alignSh);
            BitSet2::MarkFree(bitSet, (nextAdj - base) >> shift, thisTail >> shift);
        }
    }
    return oldPtr;
}

UPInt AllocBitSet2::GetUsableSize(const HeapSegment* seg, const void* ptr) const
{
    UPInt start = ((UByte*)ptr - seg->pData) >> MinAlignShift;
    return BitSet2::GetBlockSize(GetBitSet(seg), start) << MinAlignShift;
}

UPInt AllocBitSet2::GetAlignShift(const HeapSegment* seg, const void* ptr, UPInt size) const
{
    UPInt    start = ((UByte*)ptr - seg->pData) >> MinAlignShift;
    unsigned al    = BitSet2::GetAlignShift(GetBitSet(seg), start, size >> MinAlignShift);
    return MinAlignShift + al;
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocBitSet2@HeapPT@Scaleform@@QEAA@_K@Z 0x1426f1520
// MS2-PIN: ?Alloc@AllocBitSet2@HeapPT@Scaleform@@QEAAPEAX_K0PEAPEAUHeapSegment@Heap@3@@Z 0x1426f1550
// MS2-PIN: ?Alloc@AllocBitSet2@HeapPT@Scaleform@@QEAAPEAX_KPEAPEAUHeapSegment@Heap@3@@Z 0x1426f18a0
// MS2-PIN: ?Free@AllocBitSet2@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@PEAX@Z 0x1426f1a00
// MS2-PIN: ?GetAlignShift@AllocBitSet2@HeapPT@Scaleform@@QEBA_KPEBUHeapSegment@Heap@3@PEBX_K@Z 0x1426f1b70
// MS2-PIN: ?GetAlignShift@BitSet2@Heap@Scaleform@@SAIPEBK_K1@Z 0x1426f1bb0
// MS2-PIN: ?GetUsableSize@AllocBitSet2@HeapPT@Scaleform@@QEBA_KPEBUHeapSegment@Heap@3@PEBX@Z 0x1426f1c40
// MS2-PIN: ?InitSegment@AllocBitSet2@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@@Z 0x1426f1c70
// MS2-PIN: ?MarkBusy@BitSet2@Heap@Scaleform@@SAXPEAK_K11@Z 0x1426f1d00
// MS2-PIN: ?ReallocInPlace@AllocBitSet2@HeapPT@Scaleform@@QEAAPEAXPEAUHeapSegment@Heap@3@PEAX_KPEA_K@Z 0x1426f2110
// MS2-PIN: ?ReleaseSegment@AllocBitSet2@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@@Z 0x1426f2450
