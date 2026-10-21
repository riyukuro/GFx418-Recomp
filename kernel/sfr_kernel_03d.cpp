// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_FreeBin (the free
// block bins of the PT bit-set allocator: two rings-of-lists bins for short blocks and a bitwise size tree for the
// rest). Release build: the integrity checks are empty. Our own source, written from the exe. Queue unit
// sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426cd3d0-0x1426ce850 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_freebin.h"

namespace Scaleform { namespace HeapPT {

// ---- ListBin ----

ListBin::ListBin()
{
    Reset();
}

void ListBin::Reset()
{
    Mask = 0;
    memset(Roots, 0, sizeof(Roots));
}

// ---- TreeBin ----

TreeBin::TreeBin()
{
    Reset();
}

void TreeBin::Reset()
{
    Mask = 0;
    memset(Roots, 0, sizeof(Roots));
}

// first aligned address in the block that leaves either no head or a head big enough to be a free block itself
UByte* ListBin::GetAlignedPtr(UByte* start, UPInt alignMask)
{
    UPInt aligned = (UPInt(start) + alignMask) & ~alignMask;
    UPInt head    = aligned - UPInt(start);
    while (head && head < Heap_MinSize)
    {
        aligned += alignMask + 1;
        head    += alignMask + 1;
    }
    return (UByte*)aligned;
}

bool ListBin::AlignmentIsOK(const BinLNode* node, UPInt blocks, UPInt shift, UPInt alignMask)
{
    UPInt bytes   = blocks << shift;
    UPInt aligned = UPInt(GetAlignedPtr((UByte*)node, alignMask));
    return aligned + bytes <= UPInt(node) + FreeBin::GetBytes(node, shift);
}

// the new node becomes the root of its ring
SF_INLINE void ListBin::PushNode(UPInt idx, BinLNode* node)
{
    BinLNode* root = Roots[idx];
    if (root)
    {
        node->pPrev        = root;
        node->pNext        = root->pNext;
        root->pNext->pPrev = node;
        root->pNext        = node;
    }
    else
    {
        node->pPrev = node->pNext = node;
    }
    Roots[idx] = node;
    Mask |= UPInt(1) << idx;
}

SF_INLINE void ListBin::PullNode(UPInt idx, BinLNode* node)
{
    BinLNode* root = Roots[idx];
    if (node != root)
    {
        node->pPrev->pNext = node->pNext;
        node->pNext->pPrev = node->pPrev;
        return;
    }
    if (root != root->pNext)
    {
        Roots[idx]         = root->pNext;
        node->pPrev->pNext = node->pNext;
        node->pNext->pPrev = node->pPrev;
        return;
    }
    Roots[idx] = 0;
    Mask &= ~(UPInt(1) << idx);
}

// the root of the first non-empty bin at or above idx
SF_INLINE BinLNode* ListBin::PullBest(UPInt idx)
{
    BinLNode* best = 0;
    UPInt     bits = Mask >> idx;
    if (bits)
    {
        UPInt i = idx + Alg::LowerBit(bits);
        best    = Roots[i];
        PullNode(i, best);
    }
    return best;
}

BinLNode* ListBin::FindAligned(BinLNode* root, UPInt blocks, UPInt shift, UPInt alignMask)
{
    BinLNode* node = root;
    if (node) do
    {
        if (AlignmentIsOK(node, blocks, shift, alignMask))
            return node;
        node = node->pNext;
    } while (node != root);
    return 0;
}

// like PullBest(idx), but the node must hold an aligned run of the given size; scans the bins upwards
BinLNode* ListBin::PullBest(UPInt idx, UPInt blocks, UPInt shift, UPInt alignMask)
{
    BinLNode* best = 0;
    UPInt     bits = Mask >> idx;
    if (bits)
    {
        UPInt i = idx + Alg::LowerBit(bits);
        do
        {
            best = FindAligned(Roots[i], blocks, shift, alignMask);
            if (best)
            {
                PullNode(i, best);
                break;
            }
        } while (++i < BinSize);
    }
    return best;
}

// ---- TreeBin: a bitwise trie per size class (two classes per power of two), equal sizes chained in a ring ----

SF_INLINE UPInt TreeBin::ShiftForTreeIndex(UPInt i)
{
    return (i >= BinSize - 1) ? 0 : (BinSize - 1) - ((i >> 1) + SizeShift - 2);
}

SF_INLINE UPInt TreeBin::ComputeTreeIndex(UPInt blocks)
{
    UPInt piles = blocks >> SizeShift;
    if (piles == 0)
        return 0;
    if (piles > SizeLimit)
        return BinSize - 1;
    UPInt pow2 = Alg::UpperBit(piles);
    return (pow2 << 1) + ((blocks >> (pow2 + (SizeShift - 1))) & 1);
}

void TreeBin::PushNode(BinTNode* node)
{
    UPInt      size = node->Size;
    UPInt      idx  = ComputeTreeIndex(size);
    BinTNode** root = Roots + idx;
    node->Index    = idx;
    node->Child[0] = node->Child[1] = 0;
    UPInt mask = UPInt(1) << idx;
    if ((Mask & mask) == 0)
    {
        // first node of the class: its parent link points at the root slot
        Mask |= mask;
        *root        = node;
        node->Parent = (BinTNode*)root;
        node->pNext = node->pPrev = node;
    }
    else
    {
        BinTNode* head = *root;
        UPInt     bits = size << ShiftForTreeIndex(idx);
        for (;;)
        {
            if (head->Size != size)
            {
                BinTNode** link = &(head->Child[(bits >> (BinSize - 1)) & 1]);
                bits <<= 1;
                if (*link != 0)
                {
                    head = *link;
                }
                else
                {
                    *link        = node;
                    node->Parent = head;
                    node->pNext = node->pPrev = node;
                    break;
                }
            }
            else
            {
                // same size: join the ring; ring members other than the tree node have no parent
                BinTNode* next = (BinTNode*)head->pNext;
                head->pNext = next->pPrev = node;
                node->pNext  = next;
                node->pPrev  = head;
                node->Parent = 0;
                break;
            }
        }
    }
}

void TreeBin::PullNode(BinTNode* node)
{
    BinTNode* parent = node->Parent;
    BinTNode* rotor;
    if (node->pPrev != node)
    {
        // a ring neighbour takes the node's place
        BinTNode* f  = (BinTNode*)node->pNext;
        rotor        = (BinTNode*)node->pPrev;
        f->pPrev     = rotor;
        rotor->pNext = f;
    }
    else
    {
        // the rightmost-deepest leaf of the subtree takes its place
        BinTNode** rp;
        if (((rotor = *(rp = &(node->Child[1]))) != 0) || ((rotor = *(rp = &(node->Child[0]))) != 0))
        {
            BinTNode** cp;
            while ((*(cp = &(rotor->Child[1])) != 0) || (*(cp = &(rotor->Child[0])) != 0))
                rotor = *(rp = cp);
            *rp = 0;
        }
    }
    if (parent != 0)
    {
        BinTNode** root = Roots + node->Index;
        if (node == *root)
        {
            if ((*root = rotor) == 0)
                Mask &= ~(UPInt(1) << node->Index);
        }
        else
        {
            parent->Child[parent->Child[0] != node] = rotor;
        }
        if (rotor != 0)
        {
            BinTNode* child;
            rotor->Parent = parent;
            if ((child = node->Child[0]) != 0)
            {
                rotor->Child[0] = child;
                child->Parent   = rotor;
            }
            if ((child = node->Child[1]) != 0)
            {
                rotor->Child[1] = child;
                child->Parent   = rotor;
            }
        }
    }
}

// smallest node not below size: walk the trie by the size bits remembering the last right subtree not taken, then
// the leftmost path of what is left (or of the next non-empty class)
BinTNode* TreeBin::FindBest(UPInt size)
{
    BinTNode* best  = 0;
    UPInt     rsize = -SPInt(size);
    UPInt     idx   = ComputeTreeIndex(size);
    UPInt     tail;
    BinTNode* node = Roots[idx];
    if (node != 0)
    {
        BinTNode* rst  = 0;
        UPInt     bits = size << ShiftForTreeIndex(idx);
        for (;;)
        {
            BinTNode* rt;
            tail = node->Size - size;
            if (tail < rsize)
            {
                best = node;
                if ((rsize = tail) == 0)
                    break;
            }
            rt   = node->Child[1];
            node = node->Child[(bits >> (BinSize - 1)) & 1];
            if (rt != 0 && rt != node)
                rst = rt;
            if (node == 0)
            {
                node = rst;
                break;
            }
            bits <<= 1;
        }
    }
    if (node == 0 && best == 0)
    {
        UPInt x = UPInt(1) << (idx + 1);
        x       = (x | -SPInt(x)) & Mask;
        if (x)
            node = Roots[Alg::LowerBit(x)];
    }
    while (node)
    {
        tail = node->Size - size;
        if (tail < rsize)
        {
            rsize = tail;
            best  = node;
        }
        node = node->Child[node->Child[0] == 0];
    }
    return best;
}

// take a ring neighbour of the best fit when there is one: it comes out without touching the trie
SF_INLINE BinTNode* TreeBin::PullBest(UPInt size)
{
    BinTNode* best = FindBest(size);
    if (best)
    {
        best = (BinTNode*)best->pNext;
        PullNode(best);
    }
    return best;
}

const BinTNode* TreeBin::FindExactSize(UPInt size) const
{
    UPInt           idx  = ComputeTreeIndex(size);
    const BinTNode* node = Roots[idx];
    UPInt           bits = size << ShiftForTreeIndex(idx);
    while (node && node->Size != size)
    {
        node = node->Child[(bits >> (BinSize - 1)) & 1];
        bits <<= 1;
    }
    return node;
}

// ---- FreeBin ----

FreeBin::FreeBin() : FreeBlocks(0) { }

void FreeBin::Reset()
{
    ListBin1.Reset();
    ListBin2.Reset();
    TreeBin1.Reset();
    FreeBlocks = 0;
}

SF_INLINE BinLNode* FreeBin::getPrevAdjacent(UByte* node, UPInt shift)
{
    // the left neighbour's size sits right before this node
    UPInt size = *(((const UPIntHalf*)node) - 1);
    if (size >= BinSize + 1)
        size = *(((const UPInt*)node) - 2);
    return (BinLNode*)(node - (size << shift));
}

SF_INLINE BinLNode* FreeBin::getNextAdjacent(UByte* node, UPInt shift)
{
    return (BinLNode*)(node + (GetSize(node) << shift));
}

void FreeBin::Push(UByte* node)
{
    UPInt blocks = GetSize(node);
    FreeBlocks += blocks;
    if (blocks <= 1 * BinSize)
    {
        ListBin1.PushNode(blocks - 1, (BinLNode*)node);
        return;
    }
    if (blocks <= 2 * BinSize)
    {
        ListBin2.PushNode(blocks - BinSize - 1, (BinLNode*)node);
        return;
    }
    TreeBin1.PushNode((BinTNode*)node);
}

void FreeBin::Pull(UByte* node)
{
    UPInt blocks = GetSize(node);
    FreeBlocks -= blocks;
    if (blocks <= 1 * BinSize)
    {
        ListBin1.PullNode(blocks - 1, (BinLNode*)node);
        return;
    }
    if (blocks <= 2 * BinSize)
    {
        ListBin2.PullNode(blocks - BinSize - 1, (BinLNode*)node);
        return;
    }
    TreeBin1.PullNode((BinTNode*)node);
}

UByte* FreeBin::PullBest(UPInt blocks)
{
    BinLNode* best = 0;
    if (blocks <= 2 * BinSize)
    {
        if (blocks <= 1 * BinSize && (best = ListBin1.PullBest(blocks - 1)) != 0)
        {
            FreeBlocks -= UPInt(best->ShortSize);
            return (UByte*)best;
        }
        UPInt idx = (blocks <= BinSize) ? 0 : blocks - BinSize - 1;
        if ((best = ListBin2.PullBest(idx)) != 0)
        {
            FreeBlocks -= ((BinTNode*)best)->Size;
            return (UByte*)best;
        }
    }
    best = TreeBin1.PullBest(blocks);
    if (best)
        FreeBlocks -= ((BinTNode*)best)->Size;
    return (UByte*)best;
}

UByte* FreeBin::PullBest(UPInt blocks, UPInt shift, UPInt alignMask)
{
    if (blocks <= 2 * BinSize)
    {
        BinLNode* best = 0;
        if (blocks <= 1 * BinSize && (best = ListBin1.PullBest(blocks - 1, blocks, shift, alignMask)) != 0)
        {
            FreeBlocks -= UPInt(best->ShortSize);
            return (UByte*)best;
        }
        UPInt idx = (blocks <= BinSize) ? 0 : blocks - BinSize - 1;
        if ((best = ListBin2.PullBest(idx, blocks, shift, alignMask)) != 0)
        {
            FreeBlocks -= ((BinTNode*)best)->Size;
            return (UByte*)best;
        }
    }

    // tree: try each ring from the best fit upwards until one member can hold the aligned run
    BinTNode* head;
    BinTNode* best;
    UPInt     search = blocks;
    while ((head = best = TreeBin1.FindBest(search)) != 0)
    {
        do
        {
            if (ListBin::AlignmentIsOK(best, blocks, shift, alignMask))
            {
                TreeBin1.PullNode(best);
                FreeBlocks -= best->Size;
                return (UByte*)best;
            }
            best = (BinTNode*)best->pNext;
        } while (best != head);
        search = best->Size + 1;
    }
    return 0;
}

// join the node with its free neighbours (as told by the caller) and bin the result
void FreeBin::Merge(UByte* node, UPInt shift, bool left, bool right)
{
    UPInt     mergeSize = GetSize(node);
    BinLNode* mergeNode = (BinLNode*)node;
    if (left)
    {
        mergeNode  = getPrevAdjacent(node, shift);
        mergeSize += GetSize(mergeNode);
        Pull((UByte*)mergeNode);
    }
    if (right)
    {
        BinLNode* nextAdjacent = getNextAdjacent(node, shift);
        mergeSize += GetSize(nextAdjacent);
        Pull((UByte*)nextAdjacent);
    }
    SetSize((UByte*)mergeNode, mergeSize, shift);
    Push((UByte*)mergeNode);
}

// whole free pages inside a node
void FreeBin::visitUnusedNode(const BinLNode* node, SegVisitor* visitor, UPInt shift, unsigned cat) const
{
    UPInt start = (UPInt(node) + Heap_PageMask) & ~UPInt(Heap_PageMask);
    UPInt end   = (UPInt(node) + GetBytes(node, shift)) & ~UPInt(Heap_PageMask);
    if (start + Heap_PageSize <= end)
        visitor->Visit(cat, node->pSegment->pHeap, start, end - start);
}

void FreeBin::visitUnusedInTree(const BinTNode* root, SegVisitor* visitor, UPInt shift, unsigned cat) const
{
    if (root)
    {
        visitUnusedInTree(root->Child[0], visitor, shift, cat);
        const BinLNode* node = root;
        do
        {
            visitUnusedNode(node, visitor, shift, cat);
            node = node->pNext;
        } while (node != root);
        visitUnusedInTree(root->Child[1], visitor, shift, cat);
    }
}

void FreeBin::VisitUnused(SegVisitor* visitor, UPInt shift, unsigned cat) const
{
    const BinLNode* node;
    const BinLNode* root;
    for (UPInt i = 0; i < BinSize; ++i)
    {
        node = root = ListBin1.Roots[i];
        if (root && GetBytes(root, shift) >= Heap_PageSize) do
        {
            visitUnusedNode(node, visitor, shift, cat);
            node = node->pNext;
        } while (node != root);

        node = root = ListBin2.Roots[i];
        if (root && GetBytes(root, shift) >= Heap_PageSize) do
        {
            visitUnusedNode(node, visitor, shift, cat);
            node = node->pNext;
        } while (node != root);

        visitUnusedInTree(TreeBin1.Roots[i], visitor, shift, cat);
    }
}

void FreeBin::visitTree(const BinTNode* root, MemVisitor* visitor, UPInt shift, MemVisitor::Category cat) const
{
    if (root)
    {
        visitTree(root->Child[0], visitor, shift, cat);
        const BinTNode* node = root;
        do
        {
            visitor->Visit(node->pSegment, UPInt(node), node->Size << shift, cat);
            node = (BinTNode*)node->pNext;
        } while (node != root);
        visitTree(root->Child[1], visitor, shift, cat);
    }
}

void FreeBin::VisitMem(MemVisitor* visitor, UPInt shift, MemVisitor::Category cat) const
{
    UPInt           i;
    const BinLNode* node;
    const BinLNode* root;
    for (i = 0; i < BinSize; ++i)
    {
        node = root = ListBin1.Roots[i];
        if (root) do
        {
            visitor->Visit(node->pSegment, UPInt(node), UPInt(node->ShortSize) << shift, cat);
            node = node->pNext;
        } while (node != root);

        node = root = ListBin2.Roots[i];
        if (root) do
        {
            visitor->Visit(node->pSegment, UPInt(node), GetSize(node) << shift, cat);
            node = node->pNext;
        } while (node != root);

        visitTree(TreeBin1.Roots[i], visitor, shift, cat);
    }
}

void FreeBin::CheckIntegrity(UPInt) const { }

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0FreeBin@HeapPT@Scaleform@@QEAA@XZ 0x1426cd3d0
// MS2-PIN: ??0TreeBin@HeapPT@Scaleform@@QEAA@XZ 0x1426cd440
// MS2-PIN: ??0ListBin@HeapPT@Scaleform@@QEAA@XZ 0x1426cd470
// MS2-PIN: ?AlignmentIsOK@ListBin@HeapPT@Scaleform@@SA_NPEBUBinLNode@23@_K11@Z 0x1426cd4a0
// MS2-PIN: ?CheckIntegrity@FreeBin@HeapPT@Scaleform@@QEBAX_K@Z 0x1426cd500
// MS2-PIN: ?FindAligned@ListBin@HeapPT@Scaleform@@QEAAPEAUBinLNode@23@PEAU423@_K11@Z 0x1426cd510
// MS2-PIN: ?FindBest@TreeBin@HeapPT@Scaleform@@QEAAPEAUBinTNode@23@_K@Z 0x1426cd5b0
// MS2-PIN: ?FindExactSize@TreeBin@HeapPT@Scaleform@@QEBAPEBUBinTNode@23@_K@Z 0x1426cd740
// MS2-PIN: ?GetAlignedPtr@ListBin@HeapPT@Scaleform@@SAPEAEPEAE_K@Z 0x1426cd7d0
// MS2-PIN: ?LowerBit@Alg@Scaleform@@YAE_K@Z 0x1426cd800
// MS2-PIN: ?Merge@FreeBin@HeapPT@Scaleform@@QEAAXPEAE_K_N2@Z 0x1426cd8c0
// MS2-PIN: ?Pull@FreeBin@HeapPT@Scaleform@@QEAAXPEAE@Z 0x1426cd9c0
// MS2-PIN: ?PullBest@FreeBin@HeapPT@Scaleform@@QEAAPEAE_K00@Z 0x1426cda80
// MS2-PIN: ?PullBest@FreeBin@HeapPT@Scaleform@@QEAAPEAE_K@Z 0x1426cdc10
// MS2-PIN: ?PullBest@ListBin@HeapPT@Scaleform@@QEAAPEAUBinLNode@23@_K000@Z 0x1426cddb0
// MS2-PIN: ?PullNode@TreeBin@HeapPT@Scaleform@@QEAAXPEAUBinTNode@23@@Z 0x1426cdf00
// MS2-PIN: ?Push@FreeBin@HeapPT@Scaleform@@QEAAXPEAE@Z 0x1426cdfe0
// MS2-PIN: ?PushNode@TreeBin@HeapPT@Scaleform@@QEAAXPEAUBinTNode@23@@Z 0x1426ce1e0
// MS2-PIN: ?Reset@FreeBin@HeapPT@Scaleform@@QEAAXXZ 0x1426ce2f0
// MS2-PIN: ?VisitMem@FreeBin@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@_KW4Category@453@@Z 0x1426ce3a0
// MS2-PIN: ?VisitUnused@FreeBin@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@_KI@Z 0x1426ce4a0
// MS2-PIN: ?visitTree@FreeBin@HeapPT@Scaleform@@AEBAXPEBUBinTNode@23@PEAVMemVisitor@Heap@3@_KW4Category@563@@Z 0x1426ce670
// MS2-PIN: ?visitUnusedInTree@FreeBin@HeapPT@Scaleform@@AEBAXPEBUBinTNode@23@PEAVSegVisitor@Heap@3@_KI@Z 0x1426ce710
