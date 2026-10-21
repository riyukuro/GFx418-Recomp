// Recovered Scaleform GFx 4.1.18: the PT bootstrap allocator (HeapPT_Starter, exe 0x1426f0160..): a Granulator with a
// 256-byte minimum, used for page tables and heap headers before any heap exists. 0xc8 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_STARTER_H
#define MS2_SF_KERNEL_HEAPPT_STARTER_H

#include "ms2/scaleform/kernel/heappt/sf_heappt_granulator.h"

namespace Scaleform { namespace HeapPT {

class Starter
{
public:
    Starter(SysAllocPaged* sysAlloc, UPInt granularity = 4 * Heap_PageSize, UPInt headerPageSize = 1 * Heap_PageSize);

    SysAllocPaged* GetSysAlloc() { return Allocator.GetSysAlloc(); }

    void* Alloc(UPInt size, UPInt alignSize);
    void  Free(void* ptr, UPInt size, UPInt alignSize);   // the size must be passed back

    void VisitMem(MemVisitor* visitor) const;
    void VisitSegments(class SegVisitor* visitor) const;

    UPInt GetFootprint() const { return Allocator.GetFootprint(); }
    UPInt GetUsedSpace() const { return Allocator.GetUsedSpace(); }

private:
    Granulator Allocator;
};

}}  // namespace Scaleform::HeapPT

#endif
