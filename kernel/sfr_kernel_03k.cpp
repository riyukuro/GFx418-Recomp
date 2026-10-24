// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapMH_AllocBitSet2 (the MH
// in-page allocator: 16-byte units, a 2-bit busy map stored next to the page's magic headers, free runs in a
// ListBinMH). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426cba50-0x1426cc8f0 .text$mn
// MS2-RANGE: 0x1426cba30-0x1426cba47 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_heapbitset2.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_root.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_allocbitset2.h"

namespace Scaleform { namespace HeapMH {

using namespace Heap;

// @0x1426cba30
AllocBitSet2MH::AllocBitSet2MH()
{ }

// stamp the magic headers and bin the usable space on either side of them (minus the bit set, which sits in one of
// the two halves); the map starts out "all busy"
void AllocBitSet2MH::InitPage(PageMH* page, UInt32 index)
{
    MagicHeadersInfo headers;
    GetMagicHeaders(UPInt(page->Start), &headers);
    memset(headers.BitSet, 0x55, PageMH::BitSetBytes);
    if (headers.Header1)
    {
        headers.Header1->Magic       = (UInt16)MagicHeader::MagicValue;
        headers.Header1->UseCount    = 0;
        headers.Header1->Index       = index;
        headers.Header1->DebugHeader = 0;
    }
    if (headers.Header2)
    {
        headers.Header2->Magic       = (UInt16)MagicHeader::MagicValue;
        headers.Header2->UseCount    = 0;
        headers.Header2->Index       = index;
        headers.Header2->DebugHeader = 0;
    }

    UByte* start1 = 0;
    UByte* end1   = 0;
    UByte* start2 = 0;
    UByte* end2   = 0;
    if (headers.Header1)
    {
        start1 = headers.AlignedStart;
        end1   = (UByte*)headers.Header1;
    }
    if (headers.Header2)
    {
        start2 = ((UByte*)headers.Header2) + sizeof(MagicHeader);
        end2   = headers.AlignedEnd;
    }
    if ((UByte*)headers.BitSet < headers.Bound)
        end1 -= PageMH::BitSetBytes;
    else
        start2 += PageMH::BitSetBytes;

    if (start1)
    {
        BinNodeMH::MakeNode(start1, end1 - start1, page);
        Bin.Push(start1);
        BitSet2::MarkFree(headers.BitSet, (start1 - headers.AlignedStart) >> PageMH::UnitShift,
                          (end1 - start1) >> PageMH::UnitShift);
    }
    if (start2)
    {
        BinNodeMH::MakeNode(start2, end2 - start2, page);
        Bin.Push(start2);
        BitSet2::MarkFree(headers.BitSet, (start2 - headers.AlignedStart) >> PageMH::UnitShift,
                          (end2 - start2) >> PageMH::UnitShift);
    }
}

// an empty page: its (at most two) free runs leave the bins
void AllocBitSet2MH::ReleasePage(UByte* start)
{
    MagicHeadersInfo headers;
    GetMagicHeaders(UPInt(start), &headers);
    UByte* start1 = 0;
    UByte* start2 = 0;
    if (headers.Header1)
    {
        start1 = headers.AlignedStart;
        Bin.Pull(start1);
    }
    if (headers.Header2)
    {
        start2 = ((UByte*)headers.Header2) + sizeof(MagicHeader);
        if ((UByte*)headers.BitSet > headers.Bound)
            start2 += PageMH::BitSetBytes;
        Bin.Pull(start2);
    }
}

// best fit; 2-unit nodes have no page pointer, so their page is looked up in the root
void* AllocBitSet2MH::Alloc(UPInt bytes, MagicHeadersInfo* headers)
{
    UPInt      blocks = bytes >> PageMH::UnitShift;
    BinNodeMH* node   = Bin.PullBest(blocks);
    UByte*     best   = 0;
    if (node)
    {
        PageMH* page = node->GetPage();
        if (page == 0)
            page = GlobalRootMH->ResolveAddress(UPInt(node));
        best = (UByte*)node;
        GetMagicHeaders(UPInt(page->Start), headers);
        headers->Page   = page;
        UPInt tailBytes = node->GetBytes() - bytes;
        if (tailBytes)
        {
            BinNodeMH::MakeNode(best + bytes, tailBytes, page);
            Bin.Push(best + bytes);
            BitSet2::MarkFree(headers->BitSet, (best + bytes - headers->AlignedStart) >> PageMH::UnitShift,
                              tailBytes >> PageMH::UnitShift);
        }
        BitSet2::MarkBusy(headers->BitSet, (best - headers->AlignedStart) >> PageMH::UnitShift,
                          bytes >> PageMH::UnitShift);
    }
    return best;
}

void AllocBitSet2MH::Free(PageMH* page, void* ptr, MagicHeadersInfo* headers, UPInt* oldSize)
{
    GetMagicHeaders(UPInt(page->Start), headers);
    headers->Page = page;

    bool  left, right, tail;
    UPInt blocks, bytes, start;
    start  = ((UByte*)ptr - headers->AlignedStart) >> PageMH::UnitShift;
    blocks = BitSet2::GetBlockSize(headers->BitSet, start);
    bytes = *oldSize = blocks << PageMH::UnitShift;
    BitSet2::MarkFree(headers->BitSet, start, blocks);

    tail  = (UByte*)ptr + bytes < headers->AlignedEnd;
    left  = start && BitSet2::GetValue(headers->BitSet, start - 1) == 0;
    right = tail && BitSet2::GetValue(headers->BitSet, start + blocks) == 0;
    if (left | right)
    {
        Bin.Merge((UByte*)ptr, bytes, left, right, page);
    }
    else
    {
        BinNodeMH::MakeNode((UByte*)ptr, bytes, page);
        Bin.Push((UByte*)ptr);
    }
}

UPInt AllocBitSet2MH::GetUsableSize(const PageMH* page, const void* ptr) const
{
    MagicHeadersInfo headers;
    GetMagicHeaders(UPInt(page->Start), &headers);
    UPInt start, blocks;
    start  = ((const UByte*)ptr - headers.AlignedStart) >> PageMH::UnitShift;
    blocks = BitSet2::GetBlockSize(headers.BitSet, start);
    return blocks << PageMH::UnitShift;
}

void* AllocBitSet2MH::Alloc(UPInt bytes, UPInt alignSize, MagicHeadersInfo* headers)
{
    UPInt      blocks    = bytes >> PageMH::UnitShift;
    UPInt      alignMask = alignSize - 1;
    BinNodeMH* node      = Bin.PullBest(blocks, alignMask);
    UByte*     best      = 0;
    if (node)
    {
        PageMH* page = node->GetPage();
        if (page == 0)
            page = GlobalRootMH->ResolveAddress(UPInt(node));
        best           = (UByte*)node;
        UByte* aligned = ListBinMH::GetAlignedPtr(best, alignMask);
        GetMagicHeaders(UPInt(page->Start), headers);
        headers->Page   = page;
        UPInt headBytes = aligned - best;
        UPInt tailBytes = (best + node->GetBytes()) - (aligned + bytes);
        if (headBytes)
        {
            BinNodeMH::MakeNode(best, headBytes, page);
            Bin.Push(best);
            BitSet2::MarkFree(headers->BitSet, (best - headers->AlignedStart) >> PageMH::UnitShift,
                              headBytes >> PageMH::UnitShift);
        }
        if (tailBytes)
        {
            BinNodeMH::MakeNode(aligned + bytes, tailBytes, page);
            Bin.Push(aligned + bytes);
            BitSet2::MarkFree(headers->BitSet, (aligned + bytes - headers->AlignedStart) >> PageMH::UnitShift,
                              tailBytes >> PageMH::UnitShift);
        }
        BitSet2::MarkBusy(headers->BitSet, (aligned - headers->AlignedStart) >> PageMH::UnitShift,
                          bytes >> PageMH::UnitShift);
        return aligned;
    }
    return 0;
}

// grow into a free right neighbour inside the same half of the page, or give the shrunk tail back
void* AllocBitSet2MH::ReallocInPlace(PageMH* page, void* oldPtr, UPInt newSize, UPInt* oldSize,
                                     MagicHeadersInfo* headers)
{
    GetMagicHeaders(UPInt(page->Start), headers);
    headers->Page = page;

    UPInt  newBytes = newSize;
    UByte* base     = headers->AlignedStart;
    UByte* end      = headers->AlignedEnd;
    if ((UByte*)oldPtr < headers->Bound)
    {
        end = headers->Bound - sizeof(MagicHeader);
        if ((UByte*)headers->BitSet < headers->Bound)
            end -= PageMH::BitSetBytes;
    }
    UInt32*    bitSet   = headers->BitSet;
    UPInt      start    = ((UByte*)oldPtr - base) >> PageMH::UnitShift;
    UPInt      blocks   = BitSet2::GetBlockSize(bitSet, start);
    UPInt      oldBytes = blocks << PageMH::UnitShift;
    UByte*     nextAdj;
    BinNodeMH* nextNode;
    UPInt      nextBytes;

    *oldSize = oldBytes;
    if (newBytes > oldBytes)
    {
        nextAdj = (UByte*)oldPtr + oldBytes;
        if (nextAdj < end && BitSet2::GetValue(bitSet, start + blocks) == 0)
        {
            nextNode  = (BinNodeMH*)nextAdj;
            nextBytes = nextNode->GetBytes();
            if (newBytes <= oldBytes + nextBytes)
            {
                Bin.Pull(nextAdj);
                UPInt tailBytes = oldBytes + nextBytes - newBytes;
                if (tailBytes)
                {
                    UByte* tailBlock = (UByte*)oldPtr + newBytes;
                    BinNodeMH::MakeNode(tailBlock, tailBytes, page);
                    Bin.Push(tailBlock);
                    BitSet2::MarkFree(bitSet, (tailBlock - base) >> PageMH::UnitShift,
                                      tailBytes >> PageMH::UnitShift);
                }
                BitSet2::MarkBusy(bitSet, start, newBytes >> PageMH::UnitShift);
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
        {
            nextNode = (BinNodeMH*)nextAdj;
            nextTail = nextNode->GetBytes();
        }
        if (thisTail + nextTail)
        {
            if (nextTail)
                Bin.Pull(nextAdj);
            nextAdj   = (UByte*)oldPtr + newBytes;
            thisTail += nextTail;
            BinNodeMH::MakeNode(nextAdj, thisTail, page);
            Bin.Push(nextAdj);
            BitSet2::MarkBusy(bitSet, start, newBytes >> PageMH::UnitShift);
            BitSet2::MarkFree(bitSet, (nextAdj - base) >> PageMH::UnitShift, thisTail >> PageMH::UnitShift);
        }
    }
    return oldPtr;
}

}}  // namespace Scaleform::HeapMH
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?Alloc@AllocBitSet2MH@HeapMH@Scaleform@@QEAAPEAX_K0PEAUMagicHeadersInfo@23@@Z 0x1426cba50
// MS2-PIN: ?Alloc@AllocBitSet2MH@HeapMH@Scaleform@@QEAAPEAX_KPEAUMagicHeadersInfo@23@@Z 0x1426cbc50
// MS2-PIN: ?Free@AllocBitSet2MH@HeapMH@Scaleform@@QEAAXPEAUPageMH@23@PEAXPEAUMagicHeadersInfo@23@PEA_K@Z 0x1426cbdb0
// MS2-PIN: ?GetBlockSize@BitSet2@Heap@Scaleform@@SA_KPEBK_K@Z 0x1426cbf50
// MS2-PIN: ?GetUsableSize@AllocBitSet2MH@HeapMH@Scaleform@@QEBA_KPEBUPageMH@23@PEBX@Z 0x1426cc040
// MS2-PIN: ?InitPage@AllocBitSet2MH@HeapMH@Scaleform@@QEAAXPEAUPageMH@23@K@Z 0x1426cc080
// MS2-PIN: ?MakeNode@BinNodeMH@HeapMH@Scaleform@@SAPEAU123@PEAE_KPEAUPageMH@23@@Z 0x1426cc330
// MS2-PIN: ?MarkBusy@BitSet2@Heap@Scaleform@@SAXPEAK_K1@Z 0x1426cc390
// MS2-PIN: ?ReallocInPlace@AllocBitSet2MH@HeapMH@Scaleform@@QEAAPEAXPEAUPageMH@23@PEAX_KPEA_KPEAUMagicHeadersInfo@23@@Z 0x1426cc5c0
// MS2-PIN: ?ReleasePage@AllocBitSet2MH@HeapMH@Scaleform@@QEAAXPEAE@Z 0x1426cc850
