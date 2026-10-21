// Recovered Scaleform GFx 4.1.18: the per-heap PT allocation engine (HeapPT_AllocEngine, exe 0x1426cf7b0..). Small
// sizes come from tiny-block lists, mid sizes from bit-set segments (AllocBitSet2), big ones straight from the system
// allocator. 0x750 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_ALLOCENGINE_H
#define MS2_SF_KERNEL_HEAPPT_ALLOCENGINE_H

#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_pagetable.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_bookkeeper.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocbitset2.h"

namespace Scaleform { namespace HeapPT {

struct HeapOtherStats
{
    UPInt Segments;
    UPInt Bookkeeping;
    UPInt DynamicGranularity;
    UPInt SysDirectSpace;
};

class AllocEngine
{
public:
    struct TinyBlock : ListNode<TinyBlock>
    {
        HeapSegment* pSegment;
    };

private:
    typedef List<HeapSegment> SegmentListType;
    typedef List<TinyBlock>   TinyListType;

public:
    AllocEngine(SysAllocPaged* sysAlloc, MemoryHeapPT* heap, unsigned allocFlags, UPInt minAlignSize = 16,
                UPInt granularity = 8 * 1024, UPInt reserve = 8 * 1024, UPInt internalThreshold = 128 * 1024,
                UPInt limit = 0);
    ~AllocEngine();

    bool  IsValid() const { return Valid; }
    UPInt SetLimit(UPInt lim);
    void  SetLimitHandler(void* handler) { pLimHandler = handler; }

    void FreeAll();

    void* Alloc(UPInt size);
    void* Alloc(UPInt size, UPInt alignSize);
    void* Realloc(HeapSegment* seg, void* oldPtr, UPInt newSize);
    void  Free(HeapSegment* seg, void* ptr);
    void* Realloc(void* oldPtr, UPInt newSize);
    void  Free(void* ptr);

    UPInt GetUsableSize(const void* ptr);
    UPInt GetUsableSize(HeapSegment* seg, const void* ptr);

    UPInt GetFootprint() const;
    UPInt GetUsedSpace() const;

    void ReleaseCachedMem();

    void VisitMem(MemVisitor* visitor, unsigned flags = MemVisitor::VF_Heap) const;
    void VisitSegments(SegVisitor* visitor) const;
    void GetHeapOtherStats(HeapOtherStats* otherStats) const;

    void CheckIntegrity() const { Allocator.CheckIntegrity(); }

private:
    HeapSegment* allocSegment(unsigned segType, UPInt size, UPInt sysAlignment, UPInt bookkeepingSize,
                              bool* limHandlerOK);
    HeapSegment* allocSegmentNoGranulator(UPInt dataSize, UPInt alignment, bool* limHandlerOK);
    HeapSegment* allocSegmentLocked(unsigned segType, UPInt size, UPInt sysAlignment, UPInt bookkeepingSize,
                                    bool* limHandlerOK);
    void         freeSegment(HeapSegment* seg);
    void         freeSegmentLocked(HeapSegment* seg);
    UPInt        calcDynaSize() const;

    HeapSegment* allocSegmentBitSet(UPInt size, UPInt alignSize, UPInt granularity, bool* limHandlerOK);
    HeapSegment* allocSegmentBitSet(UPInt size, UPInt alignSize, bool* limHandlerOK);
    void         freeSegmentBitSet(HeapSegment* seg);

    void* allocSysDirect(UPInt dataSize, UPInt alignSize);
    void* reallocSysDirect(HeapSegment* seg, void* oldPtr, UPInt newSize);
    void* reallocGeneral(HeapSegment* seg, void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignShift);

    void* allocBitSet(UPInt size);
    void* allocBitSet(UPInt size, UPInt alignSize);

    void* allocSegmentTiny(unsigned idx);
    void  releaseSegmentTiny(HeapSegment* seg);
    void  freeSegmentTiny(HeapSegment* seg);
    void* allocTiny(unsigned sizeIdx);
    void  freeTiny(HeapSegment* seg, TinyBlock* ptr);

    MemoryHeapPT*   pHeap;                         // +0x00
    SysAllocPaged*  pSysAlloc;                     // +0x08
    Bookkeeper*     pBookkeeper;                   // +0x10
    UPInt           MinAlignShift;                 // +0x18
    UPInt           MinAlignMask;                  // +0x20
    AllocBitSet2    Allocator;                     // +0x28
    SegmentListType SegmentList;                   // +0x658
    TinyListType    TinyBlocks[Heap_TinyBinSize];  // +0x668
    bool            AllowTinyBlocks;               // +0x6e8
    bool            AllowDynaSize;
    bool            Valid;
    bool            HasRealloc;
    UPInt           SysGranularity;                // +0x6f0
    UPInt           Granularity;
    UPInt           Reserve;
    UPInt           Threshold;
    UPInt           SysDirectThreshold;
    UPInt           Footprint;                     // +0x718
    UPInt           TinyFreeSpace;
    UPInt           SysDirectSpace;
    HeapSegment*    pCachedBSeg;                   // cached bit-set segment
    HeapSegment*    pCachedTSeg;                   // cached tiny-block segment
    UPInt           Limit;                         // +0x740
    void*           pLimHandler;                   // +0x748
};

}}  // namespace Scaleform::HeapPT

#endif
