// Recovered Scaleform GFx 4.1.18: the PT heap's free-block bins (HeapPT_FreeBin, exe 0x1426cd3d0..). Free blocks carry
// a BinLNode header; small ones (<= 64 blocks) sit in list bins indexed by size, bigger ones in a bitwise size tree.
// The block size is stored at both ends so neighbours can be merged. 0x620 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_FREEBIN_H
#define MS2_SF_KERNEL_HEAPPT_FREEBIN_H

#include "ms2/scaleform/kernel/sf_heaptypes.h"

namespace Scaleform {
namespace Heap { class SegVisitor; }
namespace HeapPT {

using namespace Heap;

struct BinLNode
{
    BinLNode*    pPrev;
    BinLNode*    pNext;
    HeapSegment* pSegment;
    UPIntHalf    ShortSize;   // blocks, or BinSize+1 when the full size follows the node
    UPIntHalf    Filler;
};

struct BinTNode : BinLNode
{
    UPInt     Size;
    BinTNode* Parent;
    BinTNode* Child[2];
    UPInt     Index;
};

// one ring of equal-size nodes per bin, Mask has a bit per non-empty bin
struct ListBin
{
    enum { BinSize = 8 * sizeof(UPInt) };

    ListBin();
    void Reset();

    void      PushNode(UPInt idx, BinLNode* node);
    void      PullNode(UPInt idx, BinLNode* node);
    BinLNode* PullBest(UPInt idx);
    BinLNode* PullBest(UPInt idx, UPInt blocks, UPInt shift, UPInt alignMask);
    BinLNode* FindAligned(BinLNode* root, UPInt blocks, UPInt shift, UPInt alignMask);

    static UByte* GetAlignedPtr(UByte* start, UPInt alignMask);
    static bool   AlignmentIsOK(const BinLNode* node, UPInt blocks, UPInt shift, UPInt alignMask);

    UPInt     Mask;
    BinLNode* Roots[BinSize];
};

struct TreeBin
{
    enum
    {
        BinSize   = ListBin::BinSize,
        SizeShift = (sizeof(void*) > 4) ? 6 : 5,
        SizeLimit = (sizeof(void*) > 4) ? 0xFFFFFFFFU : 0xFFFFU
    };

    TreeBin();
    void Reset();

    static UPInt ShiftForTreeIndex(UPInt i);
    static UPInt ComputeTreeIndex(UPInt blocks);

    void            PushNode(BinTNode* node);
    void            PullNode(BinTNode* node);
    BinTNode*       FindBest(UPInt size);
    BinTNode*       PullBest(UPInt size);
    const BinTNode* FindExactSize(UPInt size) const;

    UPInt     Mask;
    BinTNode* Roots[BinSize];
};

class FreeBin
{
public:
    enum { BinSize = ListBin::BinSize };

    FreeBin();
    void Reset();

    SF_INLINE static UInt32* GetBitSet(const HeapSegment* seg) { return (UInt32*)(((UByte*)seg) + sizeof(HeapSegment)); }

    SF_INLINE static UPInt GetSize(const void* node)
    {
        UPInt size = ((const BinLNode*)node)->ShortSize;
        if (size < BinSize + 1)
            return size;
        return *(const UPInt*)((const UByte*)node + sizeof(BinLNode));
    }
    SF_INLINE static UPInt GetBytes(const void* node, UPInt shift) { return GetSize(node) << shift; }

    // the short size goes in the head and the last half-word; long sizes also after the header and before the tail
    SF_INLINE static void SetSize(UByte* node, UPInt blocks, UPInt shift)
    {
        UPInt     bytes = blocks << shift;
        BinLNode* head  = (BinLNode*)node;
        if (blocks < BinSize + 1)
        {
            head->ShortSize = *(UPIntHalf*)(node + bytes - sizeof(UPIntHalf)) = UPIntHalf(blocks);
        }
        else
        {
            head->ShortSize = *(UPIntHalf*)(node + bytes - sizeof(UPIntHalf)) = UPIntHalf(BinSize + 1);
            *(UPInt*)(node + sizeof(BinLNode)) = *(UPInt*)(node + bytes - 2 * sizeof(UPInt)) = blocks;
        }
    }
    SF_INLINE static void MakeNode(HeapSegment* seg, UByte* data, UPInt blocks, UPInt shift)
    {
        SetSize(data, blocks, shift);
        ((BinLNode*)data)->pSegment = seg;
    }

    UByte* PullBest(UPInt blocks);
    UByte* PullBest(UPInt blocks, UPInt shift, UPInt alignMask);
    void   Push(UByte* node);
    SF_INLINE void Push(HeapSegment* seg, UByte* node, UPInt blocks, UPInt shift)
    {
        MakeNode(seg, node, blocks, shift);
        Push(node);
    }
    void Pull(UByte* node);
    void Merge(UByte* node, UPInt shift, bool left, bool right);

    UPInt GetTotalFreeSpace(UPInt shift) const { return FreeBlocks << shift; }

    void VisitMem(MemVisitor* visitor, UPInt shift, MemVisitor::Category cat) const;
    void VisitUnused(SegVisitor* visitor, UPInt shift, unsigned cat) const;
    void CheckIntegrity(UPInt shift) const;

private:
    static BinLNode* getPrevAdjacent(UByte* node, UPInt shift);
    static BinLNode* getNextAdjacent(UByte* node, UPInt shift);

    void visitTree(const BinTNode* root, MemVisitor* visitor, UPInt shift, MemVisitor::Category cat) const;
    void visitUnusedNode(const BinLNode* node, SegVisitor* visitor, UPInt shift, unsigned cat) const;
    void visitUnusedInTree(const BinTNode* root, SegVisitor* visitor, UPInt shift, unsigned cat) const;
    void checkBlockIntegrity(const BinLNode* node, UPInt shift) const;
    void checkTreeIntegrity(const BinTNode* root, UPInt shift) const;

    ListBin ListBin1;   // nodes of exactly idx+1 blocks
    ListBin ListBin2;   // nodes of more than 64 blocks too short for the tree, by size class
    TreeBin TreeBin1;
    UPInt   FreeBlocks;
};

}}  // namespace Scaleform::HeapPT

#endif
