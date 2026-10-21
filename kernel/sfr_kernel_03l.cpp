// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_AllocAddr (best-fit
// allocator over an abstract address range, free ranges indexed by size and by address). Our own source, written from
// the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a2820-0x1429a3670 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"
#include "ms2/scaleform/kernel/sf_allocaddr.h"

namespace Scaleform {

AllocAddr::AllocAddr(MemoryHeap* nodeHeap) : pNodeHeap(nodeHeap)
{ }

AllocAddr::AllocAddr(MemoryHeap* nodeHeap, UPInt start, UPInt size) : pNodeHeap(nodeHeap)
{
    FreeNode* node = (FreeNode*)pNodeHeap->Alloc(sizeof(FreeNode));
    pushNode(node, start, size);
}

AllocAddr::~AllocAddr()
{
    destroyAll();
}

// in-order walk of the address tree into a plain list
static void linearizeTree(AllocAddrNode* root, List<AllocAddrNode>* nodes)
{
    if (root)
    {
        linearizeTree(root->AddrChild[0], nodes);
        nodes->PushBack(root);
        linearizeTree(root->AddrChild[1], nodes);
    }
}

void AllocAddr::destroyAll()
{
    List<AllocAddrNode> nodes;
    linearizeTree(AddrTree.Root, &nodes);
    AddrTree.Clear();
    SizeTree.Tree.Clear();
    while (!nodes.IsEmpty())
    {
        AllocAddrNode* node = nodes.GetFirst();
        nodes.Remove(node);
        pNodeHeap->Free(node);
    }
}

inline void AllocAddr::pushNode(FreeNode* node, UPInt addr, UPInt size)
{
    node->Addr = addr;
    node->Size = size;
    SizeTree.Insert(node);
    AddrTree.Insert(node);
}

inline void AllocAddr::pullNode(FreeNode* node)
{
    SizeTree.Remove(node);
    AddrTree.Remove(node);
}

AllocAddr::FreeNode* AllocAddr::pullBest(UPInt size)
{
    FreeNode* best = SizeTree.PullBestGrEq(size);
    if (best)
        AddrTree.Remove(best);
    return best;
}

// [addr, addr+size) is taken out of the (already pulled) node: what is left on either side goes back, reusing the
// node for the head and a new node for the tail
void AllocAddr::splitNode(FreeNode* node, UPInt addr, UPInt size)
{
    UPInt headSize = addr - node->Addr;
    UPInt tailSize = (node->Addr + node->Size) - (addr + size);
    if (headSize && tailSize)
    {
        pushNode(node, node->Addr, headSize);
        node = (FreeNode*)pNodeHeap->Alloc(sizeof(FreeNode));
        pushNode(node, addr + size, tailSize);
    }
    else if (headSize)
    {
        pushNode(node, node->Addr, headSize);
    }
    else if (tailSize)
    {
        pushNode(node, addr + size, tailSize);
    }
    else
    {
        pNodeHeap->Free(node);
    }
}

// join a freed range with the free ranges right before/after it (either may be 0)
UPInt AllocAddr::mergeNodes(FreeNode* prev, FreeNode* next, UPInt addr, UPInt size)
{
    UPInt freeSize;
    if (prev && next)
    {
        freeSize = prev->Size + size + next->Size;
        pullNode(prev);
        pullNode(next);
        pushNode(prev, prev->Addr, freeSize);
        pNodeHeap->Free(next);
    }
    else if (prev)
    {
        freeSize = prev->Size + size;
        pullNode(prev);
        pushNode(prev, prev->Addr, freeSize);
    }
    else if (next)
    {
        freeSize = next->Size + size;
        pullNode(next);
        pushNode(next, addr, freeSize);
    }
    else
    {
        freeSize = size;
        next     = (FreeNode*)pNodeHeap->Alloc(sizeof(FreeNode));
        pushNode(next, addr, size);
    }
    return freeSize;
}

UPInt AllocAddr::Alloc(UPInt size)
{
    FreeNode* best = pullBest(size);
    if (best)
    {
        UPInt addr = best->Addr;
        splitNode(best, best->Addr, size);
        return addr;
    }
    return ~UPInt(0);
}

// walk the size classes upwards; in each ring look for a range that holds the aligned block
UPInt AllocAddr::Alloc(UPInt size, UPInt align)
{
    if (align < 2)
        return Alloc(size);

    UPInt pullSize = size;
    for (;;)
    {
        FreeNode* best = (FreeNode*)SizeTree.FindBestGrEq(pullSize);
        if (best == 0)
            break;
        pullSize       = best->Size + 1;
        FreeNode* stop = best;
        do
        {
            UPInt aligned = (best->Addr + align - 1) & ~(align - 1);
            if (aligned + size < best->Addr + best->Size)
            {
                SizeTree.Remove(best);
                AddrTree.Remove(best);
                splitNode(best, aligned, size);
                return aligned;
            }
            best = best->pNext;
        } while (best != stop);
    }
    return ~UPInt(0);
}

UPInt AllocAddr::Free(UPInt addr, UPInt size)
{
    if (size == 0)
        return 0;
    FreeNode* prev = (FreeNode*)AddrTree.FindLeEq(addr);
    FreeNode* next = (FreeNode*)AddrTree.FindGrEq(addr + size);
    if (prev == 0 || prev->Addr + prev->Size != addr)
        prev = 0;
    if (next == 0 || next->Addr != addr + size)
        next = 0;
    return mergeNodes(prev, next, addr, size);
}

void AllocAddr::AddSegment(UPInt addr, UPInt size)
{
    Free(addr, size);
}

// the range must lie inside one free node
void AllocAddr::RemoveSegment(UPInt addr, UPInt size)
{
    FreeNode* node = (FreeNode*)AddrTree.FindLeEq(addr);
    pullNode(node);
    splitNode(node, addr, size);
}

static void calcTreeSize(const AllocAddrNode* node, UPInt* size)
{
    if (node)
    {
        *size += node->Size;
        calcTreeSize(node->AddrChild[0], size);
        calcTreeSize(node->AddrChild[1], size);
    }
}

UPInt AllocAddr::GetFreeSize() const
{
    UPInt size = 0;
    calcTreeSize(AddrTree.Root, &size);
    return size;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocAddr@Scaleform@@QEAA@PEAVMemoryHeap@1@@Z 0x1429a2820
// MS2-PIN: ??0AllocAddr@Scaleform@@QEAA@PEAVMemoryHeap@1@_K1@Z 0x1429a2840
// MS2-PIN: ?destroyAll@AllocAddr@Scaleform@@AEAAXXZ 0x1429a28a0
// MS2-PIN: ?Alloc@AllocAddr@Scaleform@@QEAA_K_K0@Z 0x1429a2970
// MS2-PIN: ?Alloc@AllocAddr@Scaleform@@QEAA_K_K@Z 0x1429a2ab0
// MS2-PIN: ?FindGrEq@?$RadixTree@UAllocAddrNode@Scaleform@@USizeAccessor@AllocAddr@2@@Scaleform@@QEBAPEBUAllocAddrNode@2@_K@Z 0x1429a2b30
// MS2-PIN: ?FindLeEq@?$RadixTree@UAllocAddrNode@Scaleform@@UAddrAccessor@AllocAddr@2@@Scaleform@@QEBAPEBUAllocAddrNode@2@_K@Z 0x1429a2bf0
// MS2-PIN: ?Free@AllocAddr@Scaleform@@QEAA_K_K0@Z 0x1429a2cb0
// MS2-PIN: ?GetFreeSize@AllocAddr@Scaleform@@QEBA_KXZ 0x1429a2ec0
// MS2-PIN: ?Remove@?$RadixTreeMulti@UAllocAddrNode@Scaleform@@USizeAccessor@AllocAddr@2@@Scaleform@@QEAAXPEAUAllocAddrNode@2@@Z 0x1429a3040
// MS2-PIN: ?RemoveSegment@AllocAddr@Scaleform@@QEAAX_K0@Z 0x1429a3120
// MS2-PIN: ?calcTreeSize@Scaleform@@YAXPEBUAllocAddrNode@1@PEA_K@Z 0x1429a31a0
// MS2-PIN: ??1AllocAddr@Scaleform@@QEAA@XZ 0x1429a31f0
// MS2-PIN: ?linearizeTree@Scaleform@@YAXPEAUAllocAddrNode@1@PEAV?$List@UAllocAddrNode@Scaleform@@U12@@1@@Z 0x1429a32b0
// MS2-PIN: ?mergeNodes@AllocAddr@Scaleform@@AEAA_KPEAUAllocAddrNode@2@0_K1@Z 0x1429a3310
// MS2-PIN: ?pullBest@AllocAddr@Scaleform@@AEAAPEAUAllocAddrNode@2@_K@Z 0x1429a3450
// MS2-PIN: ?pushNode@AllocAddr@Scaleform@@AEAAXPEAUAllocAddrNode@2@_K1@Z 0x1429a34b0
// MS2-PIN: ?splitNode@AllocAddr@Scaleform@@AEAAXPEAUAllocAddrNode@2@_K1@Z 0x1429a35c0
