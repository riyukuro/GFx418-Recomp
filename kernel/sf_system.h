// Recovered Scaleform GFx 4.1.18: library start-up/shut-down (timer, root heap through the system allocator).
#ifndef MS2_SF_KERNEL_SYSTEM_H
#define MS2_SF_KERNEL_SYSTEM_H

#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocmalloc.h"

// The game's bootstrap TU (unit_141803210) picks the MH heap's SysAllocMalloc: its ??_FSystem closure calls that singleton.
#ifndef SF_SYSALLOC_DEFAULT_CLASS
#define SF_SYSALLOC_DEFAULT_CLASS SysAllocPagedMalloc
#endif

namespace Scaleform {

class System
{
public:
    SF_EXPORT System(SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton())
    {
        Init(sysAlloc);
    }
    SF_EXPORT System(const MemoryHeap::HeapDesc& rootHeapDesc,
                     SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton())
    {
        Init(rootHeapDesc, sysAlloc);
    }
    SF_EXPORT ~System() { Destroy(); }

    static void SF_CDECL Init(const MemoryHeap::HeapDesc& rootHeapDesc,
                              SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton());
    SF_EXPORT static void SF_CDECL Init(SysAllocBase* sysAlloc = SF_SYSALLOC_DEFAULT_CLASS::InitSystemSingleton())
    {
        Init(MemoryHeap::RootHeapDesc(), sysAlloc);
    }
    static void SF_CDECL Destroy();

    static bool HasMemoryLeaks;
};

}  // namespace Scaleform

#endif
