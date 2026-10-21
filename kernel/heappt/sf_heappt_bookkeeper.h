// Recovered Scaleform GFx 4.1.18: the PT bookkeeping allocator (HeapPT_Bookkeeper, exe 0x1426f0e80..): memory for
// segment headers and bit sets, taken in Granularity-sized segments and carved by an AllocBitSet1. 0x658 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_BOOKKEEPER_H
#define MS2_SF_KERNEL_HEAPPT_BOOKKEEPER_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_sysalloc.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_pagetable.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocbitset1.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

class Bookkeeper
{
public:
    typedef List<HeapSegment> SegmentListType;

    Bookkeeper(SysAllocPaged* sysAlloc, UPInt granularity = Heap_PageSize);

    SysAllocPaged* GetSysAlloc() { return pSysAlloc; }

    void* Alloc(UPInt size);
    void  Free(void* ptr, UPInt size);

    void VisitMem(MemVisitor* visitor, unsigned flags) const;
    void VisitSegments(SegVisitor* visitor) const;

    UPInt GetFootprint() const { return Footprint; }
    UPInt GetUsedSpace() const { return Footprint - Allocator.GetTotalFreeSpace(); }

private:
    UPInt        getHeaderSize(UPInt dataSize) const;
    HeapSegment* allocSegment(UPInt size);
    void         freeSegment(HeapSegment* seg);

    SysAllocPaged*  pSysAlloc;     // +0x00
    UPInt           Granularity;   // +0x08
    SegmentListType SegmentList;   // +0x10
    AllocBitSet1    Allocator;     // +0x20
    UPInt           Footprint;     // +0x650
};

}}  // namespace Scaleform::HeapPT

#endif
