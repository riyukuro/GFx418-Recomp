// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_Starter (the bootstrap
// allocator behind the page tables). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its
// original sources.
// MS2-UNIT: sfr_kernel_03e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426f0160-0x1426f01d0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_starter.h"

namespace Scaleform { namespace HeapPT {

// 256-byte minimum blocks: the smallest page table level
Starter::Starter(SysAllocPaged* sysAlloc, UPInt granularity, UPInt headerPageSize)
    : Allocator(sysAlloc, 256, granularity, headerPageSize)
{ }

void* Starter::Alloc(UPInt size, UPInt alignSize)
{
    return Allocator.Alloc(size, alignSize);
}

void Starter::Free(void* ptr, UPInt size, UPInt alignSize)
{
    Allocator.Free(ptr, size, alignSize);
}

void Starter::VisitMem(MemVisitor* visitor) const
{
    Allocator.VisitMem(visitor, MemVisitor::Cat_Starter, MemVisitor::Cat_StarterFree);
}

void Starter::VisitSegments(SegVisitor* visitor) const
{
    Allocator.VisitSegments(visitor, SegVisitor::Seg_PageMap, SegVisitor::Seg_PageMapUnused);
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0Starter@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@_K1@Z 0x1426f0160
// MS2-PIN: ?VisitMem@Starter@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@@Z 0x1426f01b0
// MS2-PIN: ?VisitSegments@Starter@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@@Z 0x1426f01c0
// MS2-PIN: ?Alloc@Starter@HeapPT@Scaleform@@QEAAPEAX_K0@Z 0x1426f0190
// MS2-PIN: ?Free@Starter@HeapPT@Scaleform@@QEAAXPEAX_K1@Z 0x1426f01a0
