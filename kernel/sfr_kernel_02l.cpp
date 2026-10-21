// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_AllocLite (best-fit
// allocator over caller-provided segments; free blocks are indexed by size and by address so neighbours coalesce).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142642f90-0x142644190 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_alloclite.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

// sizes are kept in MinSize blocks (MinSize: the power of two at or above minSize)
AllocLite::AllocLite(UPInt minSize)
    : MinShift(Alg::UpperBit(minSize)), MinSize(UPInt(1) << MinShift), MinMask(MinSize - 1), SizeTree(), AddrTree(),
      FreeBlocks(0)
{
}

inline void AllocLite::pushNode(FreeNode* node, TreeSeg* seg, UPInt blocks)
{
    node->Size      = blocks;
    node->ParentSeg = seg;
    SizeTree.Insert(node);
    AddrTree.Insert(node);
    FreeBlocks += blocks;
}

inline void AllocLite::pullNode(FreeNode* node)
{
    FreeBlocks -= node->Size;
    SizeTree.Remove(node);
    AddrTree.Remove(node);
}

AllocLite::FreeNode* AllocLite::pullBest(UPInt blocks)
{
    FreeNode* best = SizeTree.PullBestGrEq(blocks);
    if (best)
    {
        AddrTree.Remove(best);
        FreeBlocks -= best->Size;
    }
    return best;
}

// walk the size classes from the smallest fitting one; within a class, the first node that still fits once aligned
AllocLite::FreeNode* AllocLite::pullBest(UPInt blocks, UPInt alignMask)
{
    if (alignMask <= MinMask)
        return pullBest(blocks);

    FreeNode* best;
    FreeNode* head;
    UPInt     search = blocks;
    while ((head = best = (FreeNode*)SizeTree.FindBestGrEq(search)) != 0)
    {
        do
        {
            if (best->AlignmentIsOK(blocks, MinShift, alignMask))
            {
                SizeTree.Remove(best);
                AddrTree.Remove(best);
                FreeBlocks -= best->Size;
                return best;
            }
            best = best->pNext;
        } while (best != head);
        search = best->Size + 1;
    }
    return best;
}

// give back what is left of node on both sides of [start, start + size)
void AllocLite::splitNode(FreeNode* node, UByte* start, UPInt size)
{
    TreeSeg* seg   = node->ParentSeg;
    UPInt    head  = start - (UByte*)node;
    UPInt    tail  = (UPInt(node) + (node->Size << MinShift)) - (UPInt(start) + size);
    if (head)
        pushNode(node, seg, head >> MinShift);
    if (tail)
        pushNode((FreeNode*)(start + size), seg, tail >> MinShift);
}

void AllocLite::InitSegment(TreeSeg* seg)
{
    pushNode((FreeNode*)seg->Buffer, seg, seg->Size >> MinShift);
}

void AllocLite::ReleaseSegment(TreeSeg* seg)
{
    pullNode((FreeNode*)seg->Buffer);
}

void* AllocLite::Alloc(UPInt size, UPInt alignSize, TreeSeg** allocSeg)
{
    if (size < MinSize)
        size = MinSize;
    if (alignSize < MinSize)
        alignSize = MinSize;
    size = (size + alignSize - 1) & ~(alignSize - 1);

    FreeNode* best = pullBest(size >> MinShift, alignSize - 1);
    if (best)
    {
        UByte* aligned = DualTNode::GetAlignedPtr((UByte*)best, alignSize - 1);
        *allocSeg = best->ParentSeg;
        splitNode(best, aligned, size);
        return aligned;
    }
    return 0;
}

void AllocLite::Free(TreeSeg* seg, void* ptr, UPInt size, UPInt alignSize)
{
    if (size < MinSize)
        size = MinSize;
    if (alignSize < MinSize)
        alignSize = MinSize;
    size = (size + alignSize - 1) & ~(alignSize - 1);

    // free neighbours in the same segment, touching the block
    FreeNode* prev = (FreeNode*)AddrTree.FindLeEq(UPInt(ptr));
    FreeNode* next = (FreeNode*)AddrTree.FindGrEq(UPInt(ptr) + size);
    if ((UByte*)prev == 0 || prev->ParentSeg != seg || (UByte*)prev + (prev->Size << MinShift) != (UByte*)ptr)
        prev = 0;
    if ((UByte*)next == 0 || next->ParentSeg != seg || (UByte*)next != (UByte*)ptr + size)
        next = 0;

    FreeNode* node = (FreeNode*)ptr;
    node->Size      = size >> MinShift;
    node->ParentSeg = seg;

    UPInt     blocks = node->Size;
    FreeNode* merged = node;
    if (prev)
    {
        merged  = prev;
        blocks += prev->Size;
        pullNode(prev);
    }
    if (next)
    {
        blocks += next->Size;
        pullNode(next);
    }
    pushNode(merged, seg, blocks);
}

AllocLite::ReallocResult AllocLite::ReallocInPlace(TreeSeg* seg, void* ptr, UPInt oldSize, UPInt newSize,
                                                   UPInt alignSize)
{
    if (alignSize < MinSize)
        alignSize = MinSize;
    oldSize = (oldSize + alignSize - 1) & ~(alignSize - 1);
    newSize = (newSize + alignSize - 1) & ~(alignSize - 1);
    if (newSize == oldSize)
        return ReallocSucceeded;

    if (newSize > oldSize)
    {
        // grow into the free block right after it
        FreeNode* next = (FreeNode*)AddrTree.FindGrEq(UPInt(ptr) + oldSize);
        if (next && next->ParentSeg == seg && (UByte*)next == (UByte*)ptr + oldSize)
        {
            UPInt freeBytes = next->Size << MinShift;
            if ((UByte*)ptr + newSize <= (UByte*)next + freeBytes)
            {
                pullNode(next);
                splitNode(next, (UByte*)next, newSize - oldSize);
                return ReallocSucceeded;
            }
            if ((UByte*)next + freeBytes == seg->Buffer + seg->Size)
                return ReallocFailedAtTail;
        }
        if ((UByte*)ptr + oldSize == seg->Buffer + seg->Size)
            return ReallocFailedAtTail;
        return ReallocFailed;
    }

    // shrink: free the tail (it merges with a free successor)
    Free(seg, (UByte*)ptr + newSize, oldSize - newSize, alignSize);
    UPInt  tailBytes = ((FreeNode*)((UByte*)ptr + newSize))->Size << MinShift;
    UByte* segEnd    = seg->Buffer + seg->Size;
    return ((UByte*)ptr + newSize + tailBytes == segEnd) ? ReallocShrinkedAtTail : ReallocSucceeded;
}

// the segment grew by incSize at its end
void AllocLite::Extend(TreeSeg* seg, UPInt incSize)
{
    FreeNode* prev = (FreeNode*)AddrTree.FindLeEq(UPInt(seg->Buffer + seg->Size) - 1);
    if (prev && prev->ParentSeg == seg && (UByte*)prev + (prev->Size << MinShift) == seg->Buffer + seg->Size)
    {
        pullNode(prev);
        pushNode(prev, seg, prev->Size + (incSize >> MinShift));
    }
    else
    {
        pushNode((FreeNode*)(seg->Buffer + seg->Size), seg, incSize >> MinShift);
    }
    seg->Size += incSize;
}

// cut the segment at ptrAt if everything from there to its end is free
bool AllocLite::TrimAt(TreeSeg* seg, UByte* ptrAt)
{
    DualTNode* node = (DualTNode*)AddrTree.FindLeEq(UPInt(ptrAt));
    if (node && node->ParentSeg == seg && ptrAt >= (UByte*)node && ptrAt < (UByte*)node + (node->Size << MinShift))
    {
        pullNode(node);
        UPInt tailBytes = (UByte*)node + (node->Size << MinShift) - ptrAt;
        if ((UByte*)node < ptrAt)
        {
            pushNode(node, seg, (ptrAt - (UByte*)node) >> MinShift);
            node = (DualTNode*)ptrAt;
            node->ParentSeg = seg;
            node->Size      = tailBytes >> MinShift;
        }
        seg->Size -= tailBytes;
        return true;
    }
    return false;
}

void AllocLite::visitTree(const FreeNode* root, HeapSegment* seg, MemVisitor* visitor, MemVisitor::Category cat) const
{
    if (root)
    {
        visitTree(root->Child[0], seg, visitor, cat);
        const FreeNode* node = root;
        do
        {
            seg->DataSize = node->ParentSeg->Size;
            seg->pData    = node->ParentSeg->Buffer;
            visitor->Visit(seg, UPInt(node), node->Size << MinShift, cat);
            node = node->pNext;
        } while (node != root);
        visitTree(root->Child[1], seg, visitor, cat);
    }
}

void AllocLite::VisitMem(MemVisitor* visitor, MemVisitor::Category cat) const
{
    HeapSegment seg;    // stands in for the owner segment of each visited block
    seg.SelfSize  = 0;
    seg.SegType   = Heap_SegmentUndefined;
    seg.Alignment = 0;
    seg.UseCount  = 0;
    seg.pHeap     = 0;
    seg.DataSize  = 0;
    seg.pData     = 0;
    visitTree(SizeTree.Tree.Root, &seg, visitor, cat);
}

// the whole pages inside a free block
void AllocLite::visitUnusedNode(const FreeNode* node, SegVisitor* visitor, unsigned cat) const
{
    UPInt start = (UPInt(node) + Heap_PageMask) & ~UPInt(Heap_PageMask);
    UPInt end   = (UPInt(node) + (node->Size << MinShift)) & ~UPInt(Heap_PageMask);
    if (start + Heap_PageSize <= end)
        visitor->Visit(cat, 0, start, end - start);
}

void AllocLite::visitUnusedInTree(const FreeNode* root, SegVisitor* visitor, unsigned cat) const
{
    if (root)
    {
        visitUnusedInTree(root->Child[0], visitor, cat);
        const FreeNode* node = root;
        do
        {
            visitUnusedNode(node, visitor, cat);
            node = node->pNext;
        } while (node != root);
        visitUnusedInTree(root->Child[1], visitor, cat);
    }
}

void AllocLite::VisitUnused(SegVisitor* visitor, unsigned cat) const
{
    visitUnusedInTree(SizeTree.Tree.Root, visitor, cat);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocLite@HeapPT@Scaleform@@QEAA@_K@Z 0x142642f90
// MS2-PIN: ?Alloc@AllocLite@HeapPT@Scaleform@@QEAAPEAX_K0PEAPEAUTreeSeg@23@@Z 0x142643090
// MS2-PIN: ?Extend@AllocLite@HeapPT@Scaleform@@QEAAXPEAUTreeSeg@23@_K@Z 0x142643230
// MS2-PIN: ?FindGrEq@?$RadixTree@UDualTNode@HeapPT@Scaleform@@UAddrAccessor@AllocLite@23@@Scaleform@@QEBAPEBUDualTNode@HeapPT@2@_K@Z 0x1426432f0
// MS2-PIN: ?FindGrEq@?$RadixTree@UDualTNode@HeapPT@Scaleform@@USizeAccessor@AllocLite@23@@Scaleform@@QEBAPEBUDualTNode@HeapPT@2@_K@Z 0x1426433a0
// MS2-PIN: ?FindLeEq@?$RadixTree@UDualTNode@HeapPT@Scaleform@@UAddrAccessor@AllocLite@23@@Scaleform@@QEBAPEBUDualTNode@HeapPT@2@_K@Z 0x142643460
// MS2-PIN: ?Free@AllocLite@HeapPT@Scaleform@@QEAAXPEAUTreeSeg@23@PEAX_K2@Z 0x142643510
// MS2-PIN: ?InitSegment@AllocLite@HeapPT@Scaleform@@QEAAXPEAUTreeSeg@23@@Z 0x142643640
// MS2-PIN: ?ReallocInPlace@AllocLite@HeapPT@Scaleform@@QEAA?AW4ReallocResult@123@PEAUTreeSeg@23@PEAX_K22@Z 0x142643660
// MS2-PIN: ?ReleaseSegment@AllocLite@HeapPT@Scaleform@@QEAAXPEAUTreeSeg@23@@Z 0x1426438a0
// MS2-PIN: ?Remove@?$RadixTree@UDualTNode@HeapPT@Scaleform@@UAddrAccessor@AllocLite@23@@Scaleform@@QEAAXPEAUDualTNode@HeapPT@2@@Z 0x1426438e0
// MS2-PIN: ?Remove@?$RadixTree@UDualTNode@HeapPT@Scaleform@@USizeAccessor@AllocLite@23@@Scaleform@@QEAAXPEAUDualTNode@HeapPT@2@0@Z 0x1426439a0
// MS2-PIN: ?Remove@?$RadixTreeMulti@UDualTNode@HeapPT@Scaleform@@USizeAccessor@AllocLite@23@@Scaleform@@QEAAXPEAUDualTNode@HeapPT@2@@Z 0x142643a10
// MS2-PIN: ?TrimAt@AllocLite@HeapPT@Scaleform@@QEAA_NPEAUTreeSeg@23@PEAE@Z 0x142643af0
// MS2-PIN: ?VisitMem@AllocLite@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@W4Category@453@@Z 0x142643bc0
// MS2-PIN: ?VisitUnused@AllocLite@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@I@Z 0x142643c00
// MS2-PIN: ?pullBest@AllocLite@HeapPT@Scaleform@@AEAAPEAUDualTNode@23@_K0@Z 0x142643c10
// MS2-PIN: ?pullBest@AllocLite@HeapPT@Scaleform@@AEAAPEAUDualTNode@23@_K@Z 0x142643d60
// MS2-PIN: ?pullNode@AllocLite@HeapPT@Scaleform@@AEAAXPEAUDualTNode@23@@Z 0x142643dc0
// MS2-PIN: ?pushNode@AllocLite@HeapPT@Scaleform@@AEAAXPEAUDualTNode@23@PEAUTreeSeg@23@_K@Z 0x142643e00
// MS2-PIN: ?splitNode@AllocLite@HeapPT@Scaleform@@AEAAXPEAUDualTNode@23@PEAE_K@Z 0x142643f20
// MS2-PIN: ?visitTree@AllocLite@HeapPT@Scaleform@@AEBAXPEBUDualTNode@23@PEAUHeapSegment@Heap@3@PEAVMemVisitor@63@W4Category@763@@Z 0x142643fb0
// MS2-PIN: ?visitUnusedInTree@AllocLite@HeapPT@Scaleform@@AEBAXPEBUDualTNode@23@PEAVSegVisitor@Heap@3@I@Z 0x142644060
// MS2-PIN: ?visitUnusedNode@AllocLite@HeapPT@Scaleform@@AEBAXPEBUDualTNode@23@PEAVSegVisitor@Heap@3@I@Z 0x142644130
