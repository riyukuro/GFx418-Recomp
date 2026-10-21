// Recovered Scaleform GFx 4.1.18: "lite" best-fit allocator over caller segments (used by SysAllocStatic and the PT
// bookkeeping). Free blocks are DualTNode headers indexed twice: by size (equal sizes in a ring) and by address.
#ifndef MS2_SF_KERNEL_HEAPPT_ALLOCLITE_H
#define MS2_SF_KERNEL_HEAPPT_ALLOCLITE_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_radixtree.h"
#include "ms2/scaleform/kernel/sf_heaptypes.h"

namespace Scaleform {
namespace Heap { class SegVisitor; }
namespace HeapPT {

using namespace Heap;

struct HdrPage;

struct TreeSeg
{
    TreeSeg*  AddrParent;
    TreeSeg*  AddrChild[2];
    HdrPage*  Headers;
    UByte*    Buffer;
    UPInt     Size;
    UPInt     UseCount;
    UPIntHalf AlignShift;
    UPIntHalf HeadBytes;
};

struct DualTNode : ListNode<DualTNode>
{
    DualTNode* Parent;
    DualTNode* Child[2];
    DualTNode* AddrParent;
    DualTNode* AddrChild[2];
    TreeSeg*   ParentSeg;
    UPInt      Size;        // in MinSize blocks

    // first aligned address that leaves either no head or a head big enough to be a free node
    static SF_INLINE UByte* GetAlignedPtr(UByte* start, UPInt alignMask)
    {
        UPInt aligned = (UPInt(start) + alignMask) & ~alignMask;
        UPInt head = aligned - UPInt(start);
        while (head && head < 16 * sizeof(void*))
        {
            aligned += alignMask + 1;
            head += alignMask + 1;
        }
        return (UByte*)aligned;
    }
    SF_INLINE bool AlignmentIsOK(UPInt blocks, UPInt shift, UPInt alignMask) const
    {
        UPInt bytes = blocks << shift;
        UPInt aligned = UPInt(GetAlignedPtr((UByte*)this, alignMask));
        return aligned + bytes <= UPInt(this) + (Size << shift);
    }
};

class AllocLite
{
    typedef DualTNode FreeNode;

public:
    struct SizeAccessor
    {
        static UPInt           GetKey(const FreeNode* n) { return n->Size; }
        static FreeNode*       GetChild(FreeNode* n, UPInt i) { return n->Child[i]; }
        static const FreeNode* GetChild(const FreeNode* n, UPInt i) { return n->Child[i]; }
        static FreeNode**      GetChildPtr(FreeNode* n, UPInt i) { return &n->Child[i]; }
        static FreeNode*       GetParent(FreeNode* n) { return n->Parent; }
        static const FreeNode* GetParent(const FreeNode* n) { return n->Parent; }
        static void SetParent(FreeNode* n, FreeNode* p) { n->Parent = p; }
        static void SetChild(FreeNode* n, UPInt i, FreeNode* c) { n->Child[i] = c; }
        static void ClearLinks(FreeNode* n) { n->Parent = n->Child[0] = n->Child[1] = 0; }
    };
    struct AddrAccessor
    {
        static UPInt           GetKey(const FreeNode* n) { return UPInt(n); }
        static FreeNode*       GetChild(FreeNode* n, UPInt i) { return n->AddrChild[i]; }
        static const FreeNode* GetChild(const FreeNode* n, UPInt i) { return n->AddrChild[i]; }
        static FreeNode**      GetChildPtr(FreeNode* n, UPInt i) { return &n->AddrChild[i]; }
        static FreeNode*       GetParent(FreeNode* n) { return n->AddrParent; }
        static const FreeNode* GetParent(const FreeNode* n) { return n->AddrParent; }
        static void SetParent(FreeNode* n, FreeNode* p) { n->AddrParent = p; }
        static void SetChild(FreeNode* n, UPInt i, FreeNode* c) { n->AddrChild[i] = c; }
        static void ClearLinks(FreeNode* n) { n->AddrParent = n->AddrChild[0] = n->AddrChild[1] = 0; }
    };

public:
    enum ReallocResult
    {
        ReallocSucceeded      = 0,
        ReallocShrinkedAtTail = 1,
        ReallocFailed         = 2,
        ReallocFailedAtTail   = 3
    };

    AllocLite(UPInt minSize);

    void  InitSegment(TreeSeg* seg);
    void  ReleaseSegment(TreeSeg* seg);
    void* Alloc(UPInt size, UPInt alignSize, TreeSeg** allocSeg);
    void  Free(TreeSeg* seg, void* ptr, UPInt size, UPInt alignSize);
    ReallocResult ReallocInPlace(TreeSeg* seg, void* ptr, UPInt oldSize, UPInt newSize, UPInt alignSize);
    void  Extend(TreeSeg* seg, UPInt incSize);
    bool  TrimAt(TreeSeg* seg, UByte* ptrAt);

    UPInt GetMinSize() const { return MinSize; }
    UPInt GetFreeBytes() const { return FreeBlocks << MinShift; }

    void VisitMem(MemVisitor* visitor, MemVisitor::Category cat) const;
    void VisitUnused(SegVisitor* visitor, unsigned cat) const;

private:
    typedef RadixTreeMulti<FreeNode, SizeAccessor> SizeTreeType;
    typedef RadixTree<FreeNode, AddrAccessor>      AddrTreeType;

    void      pushNode(FreeNode* node, TreeSeg* seg, UPInt blocks);
    void      pullNode(FreeNode* node);
    FreeNode* pullBest(UPInt blocks);
    FreeNode* pullBest(UPInt blocks, UPInt alignMask);
    void      splitNode(FreeNode* node, UByte* start, UPInt size);
    void      visitTree(const FreeNode* root, HeapSegment* seg, MemVisitor* visitor, MemVisitor::Category cat) const;
    void      visitUnusedNode(const FreeNode* node, SegVisitor* visitor, unsigned cat) const;
    void      visitUnusedInTree(const FreeNode* root, SegVisitor* visitor, unsigned cat) const;

    UPInt        MinShift;
    UPInt        MinSize;
    UPInt        MinMask;
    SizeTreeType SizeTree;
    AddrTreeType AddrTree;
    UPInt        FreeBlocks;
};

}}  // namespace Scaleform::HeapPT

#endif
