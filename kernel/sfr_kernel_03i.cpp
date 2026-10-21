// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_AllocBitSet1 (the
// bookkeeper's block allocator: one bit per block marks the two ends of every busy run, the caller passes the size
// back on free). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f3f20-0x1426f42a0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocbitset1.h"

namespace Scaleform { namespace HeapPT {

AllocBitSet1::AllocBitSet1(UPInt minAlignShift)
    : MinAlignShift(minAlignShift), MinAlignMask((UPInt(1) << minAlignShift) - 1)
{ }

void AllocBitSet1::InitSegment(HeapSegment* seg)
{
    UPInt blocks = seg->DataSize >> MinAlignShift;
    markFree(GetBitSet(seg), 0, blocks);
    Bin.Push(seg, seg->pData, blocks, MinAlignShift);
}

void AllocBitSet1::ReleaseSegment(HeapSegment* seg)
{
    Bin.Pull(seg->pData);
}

// best fit; a tail too small to be a free block stays with the allocation
void* AllocBitSet1::Alloc(UPInt bytes, HeapSegment** allocSeg)
{
    UPInt  minAlignShift = MinAlignShift;
    UPInt  blocks        = bytes >> minAlignShift;
    UByte* best          = (UByte*)Bin.PullBest(blocks);
    if (best)
    {
        HeapSegment* seg        = ((BinLNode*)best)->pSegment;
        UPInt        tailBlocks = Bin.GetSize(best) - blocks;
        UPInt        tailBytes  = tailBlocks << minAlignShift;
        if (tailBytes >= Heap_MinSize)
        {
            Bin.Push(seg, best + bytes, tailBlocks, minAlignShift);
            markFree(GetBitSet(seg), (best - seg->pData + bytes) >> minAlignShift, tailBlocks);
        }
        else
        {
            bytes += tailBytes;
        }
        markBusy(GetBitSet(seg), (best - seg->pData) >> minAlignShift, bytes >> minAlignShift);
        *allocSeg = seg;
    }
    return best;
}

void AllocBitSet1::Free(HeapSegment* seg, void* ptr, UPInt bytes)
{
    bool    left, right, tail;
    UPInt   blocks;
    UByte*  base   = seg->pData;
    UByte*  end    = base + seg->DataSize;
    UInt32* bitSet = GetBitSet(seg);
    UPInt   start  = ((UByte*)ptr - base) >> MinAlignShift;

    blocks = bytes >> MinAlignShift;
    markFree(bitSet, start, blocks);

    tail  = (UByte*)ptr + bytes < end;
    left  = start && isZero(bitSet, start - 1);
    right = tail && isZero(bitSet, start + blocks);
    Bin.MakeNode(seg, (UByte*)ptr, blocks, MinAlignShift);
    if (left | right)
        Bin.Merge((UByte*)ptr, MinAlignShift, left, right);
    else
        Bin.Push((UByte*)ptr);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocBitSet1@HeapPT@Scaleform@@QEAA@_K@Z 0x1426f3f20
// MS2-PIN: ?Alloc@AllocBitSet1@HeapPT@Scaleform@@QEAAPEAX_KPEAPEAUHeapSegment@Heap@3@@Z 0x1426f3f50
// MS2-PIN: ?Free@AllocBitSet1@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@PEAX_K@Z 0x1426f40c0
// MS2-PIN: ?InitSegment@AllocBitSet1@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@@Z 0x1426f4200
// MS2-PIN: ?ReleaseSegment@AllocBitSet1@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@@Z 0x1426f4290
