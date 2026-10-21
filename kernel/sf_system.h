// Recovered Scaleform GFx 4.1.18: library start-up/shut-down (timer, root heap through the system allocator).
#ifndef MS2_SF_KERNEL_SYSTEM_H
#define MS2_SF_KERNEL_SYSTEM_H

#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocmalloc.h"

#define SF_SYSALLOC_DEFAULT_CLASS SysAllocPagedMalloc

namespace Scaleform {

class System
{
public:
    // out of line in the exe (SF_System.cpp)
    System(SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton());
    System(const MemoryHeap::HeapDesc& rootHeapDesc,
           SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton());
    ~System() { Destroy(); }

    static void SF_CDECL Init(const MemoryHeap::HeapDesc& rootHeapDesc,
                              SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton());
    static void SF_CDECL Init(SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton())
    {
        Init(MemoryHeap::RootHeapDesc(), sysAlloc);
    }
    static void SF_CDECL Destroy();

    static bool HasMemoryLeaks;
};

}  // namespace Scaleform

#endif
