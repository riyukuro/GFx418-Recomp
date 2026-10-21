// Recovered Scaleform GFx 4.1.18: MH heap root. Small blocks live in 4 KB pages (16-byte units, a 2-bit-per-unit busy
// map at the page end) found through a two-level page table; blocks over 512 bytes come straight from the SysAlloc
// and are tracked by a NodeMH trailer in a global radix tree keyed on the trailer address.
#ifndef MS2_SF_KERNEL_HEAPMH_ROOT_H
#define MS2_SF_KERNEL_HEAPMH_ROOT_H

#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_sysalloc.h"
#include "ms2/scaleform/kernel/sf_radixtree.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_memoryheap.h"

namespace Scaleform { namespace HeapMH {

struct PageMH : public ListNode<PageMH>
{
    enum
    {
        PageSize    = 4096,
        PageMask    = PageSize - 1,
        UnitShift   = 4,
        UnitSize    = 1 << UnitShift,
        UnitMask    = UnitSize - 1,
        BitSetBytes = PageSize / UnitSize / 4,
        MaxBytes    = 512
    };
    MemoryHeapMH* pHeap;
    UByte*        Start;
};

struct PageTableMH
{
    enum
    {
        Index1Shift = 7,
        TableSize   = 1 << Index1Shift,
        Index0Mask  = TableSize - 1
    };
    struct Level0Entry
    {
        PageMH* FirstPage;
        UPInt   SizeMask;
    };
    Level0Entry Entries[TableSize];
};

struct DebugDataMH;

// written at both ends of a page so an address can be validated and mapped back to its page table slot
struct MagicHeader
{
    enum { MagicValue = 0x5FC0 };
    UInt16       Magic;
    UInt16       UseCount;
    UInt32       Index;
    DebugDataMH* DebugHeader;

    UInt32 GetIndex0() const { return Index & PageTableMH::Index0Mask; }
    UInt32 GetIndex1() const { return Index >> PageTableMH::Index1Shift; }
};

// trailer of a direct (large) block; the low 2 bits of pHeap encode the alignment (4/8/16, or 3 = in Align)
struct NodeMH
{
    enum { Align4 = 0, Align8 = 1, Align16 = 2, MoreInfo = 3 };
    NodeMH* Parent;
    NodeMH* Child[2];
    UPInt   pHeap;
    UPInt   Align;

    static UPInt GetNodeSize(UPInt align)
    {
        UPInt size = 4 * sizeof(void*);
        return (align <= 16) ? size : size + sizeof(UPInt);
    }
    MemoryHeapMH* GetHeap() const { return (MemoryHeapMH*)(pHeap & ~UPInt(3)); }
    UPInt GetAlign() const { return ((pHeap & 3) < 3) ? (UPInt(1) << ((pHeap & 3) + 2)) : Align; }
    void SetHeap(MemoryHeapMH* heap, UPInt align)
    {
        switch (align)
        {
        case 1: case 2: case 4:
            pHeap = UPInt(heap);
            break;
        case 8:
            pHeap = UPInt(heap) | Align8;
            break;
        case 16:
            pHeap = UPInt(heap) | Align16;
            break;
        default:
            pHeap = UPInt(heap) | MoreInfo;
            Align = align;
            break;
        }
    }
};

struct TreeNodeAccessor
{
    static UPInt         GetKey(const NodeMH* n) { return UPInt(n); }
    static NodeMH*       GetChild(NodeMH* n, UPInt i) { return n->Child[i]; }
    static const NodeMH* GetChild(const NodeMH* n, UPInt i) { return n->Child[i]; }
    static NodeMH**      GetChildPtr(NodeMH* n, UPInt i) { return &n->Child[i]; }
    static NodeMH*       GetParent(NodeMH* n) { return n->Parent; }
    static const NodeMH* GetParent(const NodeMH* n) { return n->Parent; }
    static void SetParent(NodeMH* n, NodeMH* p) { n->Parent = p; }
    static void SetChild(NodeMH* n, UPInt i, NodeMH* c) { n->Child[i] = c; }
    static void ClearLinks(NodeMH* n) { n->Parent = n->Child[0] = n->Child[1] = 0; }
};

struct MagicHeadersInfo
{
    MagicHeader* Header1;
    MagicHeader* Header2;
    UInt32*      BitSet;
    UByte*       AlignedStart;
    UByte*       AlignedEnd;
    UByte*       Bound;
    PageMH*      Page;
};

struct PageInfoMH
{
    PageMH* Page;
    NodeMH* Node;
    UPInt   UsableSize;
};

void GetMagicHeaders(UPInt pageStart, MagicHeadersInfo* headers);

class RootMH
{
    typedef RadixTree<NodeMH, TreeNodeAccessor> HeapTreeType;

public:
    RootMH(SysAlloc* sysAlloc);
    ~RootMH();

    void      FreeTables();
    SysAlloc* GetSysAlloc() { return pSysAlloc; }

    MemoryHeapMH* CreateHeap(const char* name, MemoryHeapMH* parent, const MemoryHeap::HeapDesc& desc);
    void          DestroyHeap(MemoryHeapMH* heap);
    LockSafe*     GetLock() { return &RootLock; }

    PageMH* AllocPage(MemoryHeapMH* heap);
    void    FreePage(PageMH* page);
    UInt32  GetPageIndex(const PageMH* page) const;
    PageMH* ResolveAddress(UPInt addr) const;

    NodeMH* AddToGlobalTree(UByte* ptr, UPInt size, UPInt align, MemoryHeapMH* heap)
    {
        NodeMH* node = (NodeMH*)(ptr + size);
        node->SetHeap(heap, align);
        HeapTree.Insert(node);
        return node;
    }
    // the trailer of the block containing ptr is the nearest node at or above it
    NodeMH* FindNodeInGlobalTree(UByte* ptr) { return (NodeMH*)HeapTree.FindGrEq(UPInt(ptr)); }
    void    RemoveFromGlobalTree(NodeMH* node) { HeapTree.Remove(node); }

private:
    bool allocPagePool();
    static void setMagic(UByte* pageStart, unsigned magicValue);
    static void clearMagic(UByte* pageStart);

    SysAlloc*        pSysAlloc;    // +0x00
    mutable LockSafe RootLock;     // +0x08
    List<PageMH>     FreePages;    // +0x30
    unsigned         TableCount;   // +0x40
    HeapTreeType     HeapTree;     // +0x48

public:
    static MemoryHeap::HeapTracer* pTracer;
};

extern RootMH*     GlobalRootMH;
extern PageTableMH GlobalPageTableMH;
extern PageMH      GlobalEmptyPage;

}}  // namespace Scaleform::HeapMH

#endif
