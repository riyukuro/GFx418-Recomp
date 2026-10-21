// Recovered Scaleform GFx 4.1.18: Win32 paged system allocator (VirtualAlloc through SysAllocMapper).
#ifndef MS2_SF_KERNEL_HEAPPT_SYSALLOCWINAPI_H
#define MS2_SF_KERNEL_HEAPPT_SYSALLOCWINAPI_H

#include "ms2/scaleform/kernel/sf_sysalloc.h"

namespace Scaleform {

class SysMemMapperWinAPI : public SysMemMapper
{
public:
    virtual UPInt GetPageSize() const;
    virtual void* ReserveAddrSpace(UPInt size);
    virtual bool  ReleaseAddrSpace(void* ptr, UPInt size);
    virtual void* MapPages(void* ptr, UPInt size);
    virtual bool  UnmapPages(void* ptr, UPInt size);
};

class SysAllocWinAPI : public SysAllocBase_SingletonSupport<SysAllocWinAPI, SysAllocPaged>
{
    enum { SegSize = 128 * 1024 * 1024 };

public:
    SysAllocWinAPI(UPInt granularity = 64 * 1024, UPInt segSize = SegSize);
    virtual ~SysAllocWinAPI();

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt align);
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align);
    virtual bool  Free(void* ptr, UPInt size, UPInt align);
    virtual UPInt GetFootprint() const;
    virtual UPInt GetUsedSpace() const;
    const UInt32* GetBitSet(UPInt seg) const;
    virtual UPInt GetBase() const;

private:
    SysMemMapperWinAPI    Mapper;
    class SysAllocMapper* pAllocator;
    UPInt                 PrivateData[128];   // the SysAllocMapper lives here
};

}  // namespace Scaleform

#endif
