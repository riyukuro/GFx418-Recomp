// Recovered Scaleform GFx 4.1.18: paged system allocator over malloc/free (the default when none is given).
#ifndef MS2_SF_KERNEL_HEAPPT_SYSALLOCMALLOC_H
#define MS2_SF_KERNEL_HEAPPT_SYSALLOCMALLOC_H

#include "ms2/scaleform/kernel/sf_sysalloc.h"

namespace Scaleform {

class SysAllocPagedMalloc : public SysAllocBase_SingletonSupport<SysAllocPagedMalloc, SysAllocPaged>
{
public:
    enum { MinGranularity = 64 * 1024 };

    SysAllocPagedMalloc(UPInt granularity = MinGranularity);

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt align);
    virtual bool  Free(void* ptr, UPInt size, UPInt align);
    virtual UPInt GetFootprint() const { return Footprint; }
    virtual UPInt GetUsedSpace() const { return Footprint; }
    virtual UPInt GetBase() const;

private:
    UPInt Granularity;
    UPInt Footprint;
    UPInt Base;     // lowest address handed out
};

}  // namespace Scaleform

#endif
