// Recovered Scaleform GFx 4.1.18: shared heap constants (Win64, no debug info), the segment header and the memory /
// segment visitor interfaces.
#ifndef MS2_SF_KERNEL_HEAPTYPES_H
#define MS2_SF_KERNEL_HEAPTYPES_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_list.h"

namespace Scaleform {

class MemoryHeap;
class MemoryHeapPT;

namespace Heap {

typedef UInt32 UPIntHalf;
typedef UInt16 UPIntQuarter;

struct HeapSegment : ListNode<HeapSegment>
{
    UPInt         SelfSize;
    UPIntHalf     SegType;
    UPIntHalf     Alignment;
    UPInt         UseCount;
    MemoryHeapPT* pHeap;
    UPInt         DataSize;
    UByte*        pData;
};

enum HeapConstants
{
    Heap_AllowTinyBlocks = 0x10,
    Heap_AllowDynaSize   = 0x20,

    Heap_StarterGranularity       = 32 * 1024,
    Heap_StarterHeaderPageSize    = 8 * 1024,
    Heap_GranulatorHeaderPageSize = 8 * 1024,
    Heap_BookkeeperGranularity    = 32 * 1024,

    // 64-bit address space: a 6-level page table (4 KB pages)
    Heap_Lv1_PageShift  = 12,
    Heap_Lv2_PageShift  = 20,
    Heap_Lv3_PageShift  = 28,
    Heap_Lv4_PageShift  = 40,
    Heap_Lv5_PageShift  = 52,
    Heap_Lv6_PageShift  = 64,
    Heap_Lv1_TableSize  = 1 << (Heap_Lv2_PageShift - Heap_Lv1_PageShift),
    Heap_Lv2_TableSize  = 1 << (Heap_Lv3_PageShift - Heap_Lv2_PageShift),
    Heap_Lv3_TableSize  = 1 << (Heap_Lv4_PageShift - Heap_Lv3_PageShift),
    Heap_Lv4_TableSize  = 1 << (Heap_Lv5_PageShift - Heap_Lv4_PageShift),
    Heap_Lv5_TableSize  = 1 << (Heap_Lv6_PageShift - Heap_Lv5_PageShift),
    Heap_Root_TableSize = Heap_Lv5_TableSize,
    Heap_Root_PageShift = Heap_Lv5_PageShift,

    Heap_PageShift = Heap_Lv1_PageShift,
    Heap_PageSize  = 1 << Heap_PageShift,
    Heap_PageMask  = Heap_PageSize - 1,

    Heap_SegmentTiny1      = 0,
    Heap_SegmentTiny2      = 1,
    Heap_SegmentTiny3      = 2,
    Heap_SegmentTiny4      = 3,
    Heap_SegmentTiny5      = 4,
    Heap_SegmentTiny6      = 5,
    Heap_SegmentTiny7      = 6,
    Heap_SegmentTiny8      = 7,
    Heap_SegmentBookkeeper = 8,
    Heap_SegmentSystem     = 9,
    Heap_SegmentBitSet     = 10,
    Heap_SegmentUndefined  = 16,

    Heap_MinShift = 5,
    Heap_MinSize  = 1 << Heap_MinShift,
    Heap_MinMask  = Heap_MinSize - 1,

    Heap_TinyBinSize = 8,
    Heap_DummyValue
};

class MemVisitor
{
public:
    enum Category
    {
        Cat_SysAlloc,
        Cat_SysAllocFree,
        Cat_Starter,
        Cat_StarterFree,
        Cat_Bookkeeper,
        Cat_BookkeeperFree,
        Cat_SystemDirect,
        Cat_AllocBitSet,
        Cat_AllocBitSetFree,
        Cat_AllocTiny,
        Cat_AllocTinyFree,
        Cat_DebugInfo,
        Cat_DebugInfoFree,
        Cat_DebugPagePool,
        Cat_DebugPageFree,
        Cat_DebugDataPool,
        Cat_DebugDataBusy,
        Cat_DebugDataFree,
        Cat_Other
    };
    enum VisitingFlags
    {
        VF_SysAlloc           = 0x01,
        VF_Starter            = 0x02,
        VF_Bookkeeper         = 0x04,
        VF_BookkeeperFree     = 0x08,
        VF_BookkeeperDetailed = VF_Bookkeeper | VF_BookkeeperFree,
        VF_Heap               = 0x10,
        VF_HeapFree           = 0x20,
        VF_HeapDetailed       = VF_Heap | VF_HeapFree,
        VF_DebugInfo          = 0x40,
        VF_DebugInfoDetailed  = 0x80 | VF_DebugInfo,
        VF_All                = 0xFFFFFFFF
    };
    virtual ~MemVisitor() { }
    virtual void Visit(const HeapSegment* seg, UPInt address, UPInt size, Category cat) = 0;
};

class SegVisitor
{
public:
    enum Seg_Category
    {
        Seg_SysMem           = 1,
        Seg_PageMap          = 2,
        Seg_Bookkeeper       = 3,
        Seg_DebugInfo        = 4,
        Seg_Heap             = 5,
        Seg_UnusedMask       = 0x80,
        Seg_SysMemUnused     = Seg_UnusedMask | Seg_SysMem,
        Seg_PageMapUnused    = Seg_UnusedMask | Seg_PageMap,
        Seg_BookkeeperUnused = Seg_UnusedMask | Seg_Bookkeeper,
        Seg_DebugInfoUnused  = Seg_UnusedMask | Seg_DebugInfo,
        Seg_HeapUnused       = Seg_UnusedMask | Seg_Heap
    };
    virtual ~SegVisitor() { }
    virtual void Visit(unsigned cat, const MemoryHeap* heap, UPInt addr, UPInt size) = 0;
};

}  // namespace Heap
}  // namespace Scaleform

#endif
