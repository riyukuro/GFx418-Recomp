// Recovered Scaleform GFx 4.1.18: SysAllocMalloc, the MH-heap system allocator over the CRT's aligned heap (Win32 build).
// The exe's /Od copies of its inline members are COMDATs of the game code (unit_141803210: ctor 0x141803ab0,
// Alloc 0x141806af0, Free 0x141807170, Realloc 0x141807690); GFxSysAlloc (placeholder/gfxsysalloc.h) derives from it.
#ifndef MS2_SF_KERNEL_HEAPMH_SYSALLOCMALLOC_H
#define MS2_SF_KERNEL_HEAPMH_SYSALLOCMALLOC_H

#include "ms2/scaleform/kernel/sf_sysalloc.h"
#include <malloc.h>
#include <string.h>
#include <new>

namespace Scaleform {

class SysAllocMalloc : public SysAllocBase_SingletonSupport<SysAllocMalloc, SysAlloc>
{
public:
    SysAllocMalloc() {}
    virtual ~SysAllocMalloc() {}

    virtual void* Alloc(UPInt size, UPInt align)
    {
        return _aligned_malloc(size, align);
    }

    virtual void Free(void* ptr, UPInt size, UPInt align)
    {
        (void)size; (void)align;
        _aligned_free(ptr);
    }

    // Allocate, copy and free instead of _aligned_realloc; an unchanged size hands the block back.
    virtual void* Realloc(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align)
    {
        if (newSize == oldSize)
            return oldPtr;

        void* newPtr = _aligned_malloc(newSize, align);
        if (newPtr)
        {
            memcpy(newPtr, oldPtr, (oldSize < newSize) ? oldSize : newSize);
            _aligned_free(oldPtr);
        }
        return newPtr;
    }
};

}  // namespace Scaleform

#endif
