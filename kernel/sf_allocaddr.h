// Recovered Scaleform GFx 4.1.18: an address-space allocator (SF_AllocAddr). It hands out ranges of an abstract
// address space (video memory and the like) and keeps the free ranges as nodes allocated from a heap, indexed twice:
// by size (best fit, equal sizes in rings) and by address (merging neighbours on free).
#ifndef MS2_SF_KERNEL_ALLOCADDR_H
#define MS2_SF_KERNEL_ALLOCADDR_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_radixtree.h"

namespace Scaleform {

struct AllocAddrNode : ListNode<AllocAddrNode>
{
    AllocAddrNode* AddrParent;     // +0x10
    AllocAddrNode* AddrChild[2];
    AllocAddrNode* SizeParent;     // +0x28
    AllocAddrNode* SizeChild[2];
    UPInt          Addr;           // +0x40
    UPInt          Size;           // +0x48
};

class MemoryHeap;

class AllocAddr
{
    typedef AllocAddrNode FreeNode;

public:
    struct SizeAccessor
    {
        static UPInt           GetKey(const FreeNode* n) { return n->Size; }
        static FreeNode*       GetChild(FreeNode* n, UPInt i) { return n->SizeChild[i]; }
        static const FreeNode* GetChild(const FreeNode* n, UPInt i) { return n->SizeChild[i]; }
        static FreeNode**      GetChildPtr(FreeNode* n, UPInt i) { return &n->SizeChild[i]; }
        static FreeNode*       GetParent(FreeNode* n) { return n->SizeParent; }
        static const FreeNode* GetParent(const FreeNode* n) { return n->SizeParent; }
        static void            SetParent(FreeNode* n, FreeNode* p) { n->SizeParent = p; }
        static void            SetChild(FreeNode* n, UPInt i, FreeNode* c) { n->SizeChild[i] = c; }
        static void            ClearLinks(FreeNode* n) { n->SizeParent = n->SizeChild[0] = n->SizeChild[1] = 0; }
    };
    struct AddrAccessor
    {
        static UPInt           GetKey(const FreeNode* n) { return n->Addr; }
        static FreeNode*       GetChild(FreeNode* n, UPInt i) { return n->AddrChild[i]; }
        static const FreeNode* GetChild(const FreeNode* n, UPInt i) { return n->AddrChild[i]; }
        static FreeNode**      GetChildPtr(FreeNode* n, UPInt i) { return &n->AddrChild[i]; }
        static FreeNode*       GetParent(FreeNode* n) { return n->AddrParent; }
        static const FreeNode* GetParent(const FreeNode* n) { return n->AddrParent; }
        static void            SetParent(FreeNode* n, FreeNode* p) { n->AddrParent = p; }
        static void            SetChild(FreeNode* n, UPInt i, FreeNode* c) { n->AddrChild[i] = c; }
        static void            ClearLinks(FreeNode* n) { n->AddrParent = n->AddrChild[0] = n->AddrChild[1] = 0; }
    };

    AllocAddr(MemoryHeap* nodeHeap);
    AllocAddr(MemoryHeap* nodeHeap, UPInt start, UPInt size);
    ~AllocAddr();

    void AddSegment(UPInt addr, UPInt size);
    void RemoveSegment(UPInt addr, UPInt size);

    UPInt Alloc(UPInt size);                // ~0 when nothing fits
    UPInt Alloc(UPInt size, UPInt align);
    UPInt Free(UPInt addr, UPInt size);     // the size of the merged free range

    UPInt GetLargestAvailable()
    {
        const FreeNode* node = SizeTree.FindBestLeEq(~UPInt(0));
        return node ? node->Size : 0;
    }
    UPInt GetFreeSize() const;

private:
    typedef RadixTreeMulti<FreeNode, SizeAccessor> SizeTreeType;
    typedef RadixTree<FreeNode, AddrAccessor>      AddrTreeType;

    void      destroyAll();
    void      pushNode(FreeNode* node, UPInt addr, UPInt size);
    void      pullNode(FreeNode* node);
    FreeNode* pullBest(UPInt size);
    void      splitNode(FreeNode* node, UPInt addr, UPInt size);
    UPInt     mergeNodes(FreeNode* prev, FreeNode* next, UPInt addr, UPInt size);

    MemoryHeap*  pNodeHeap;
    SizeTreeType SizeTree;
    AddrTreeType AddrTree;
};

}  // namespace Scaleform

#endif
