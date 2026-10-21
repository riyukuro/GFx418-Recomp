// Recovered Scaleform GFx 4.1.18: MH in-page allocator (2-bit-per-unit busy map + ListBinMH free lists).
#ifndef MS2_SF_KERNEL_HEAPMH_ALLOCBITSET2_H
#define MS2_SF_KERNEL_HEAPMH_ALLOCBITSET2_H

#include "ms2/scaleform/kernel/heapmh/sf_heapmh_freebin.h"

namespace Scaleform { namespace HeapMH {

class AllocBitSet2MH
{
public:
    AllocBitSet2MH();
    void Reset() { Bin.Reset(); }

    void  InitPage(PageMH* page, UInt32 index);
    void  ReleasePage(UByte* start);
    void* Alloc(UPInt size, MagicHeadersInfo* headers);
    void* Alloc(UPInt size, UPInt alignSize, MagicHeadersInfo* headers);
    void* ReallocInPlace(PageMH* page, void* oldPtr, UPInt newSize, UPInt* oldSize, MagicHeadersInfo* headers);
    void  Free(PageMH* page, void* ptr, MagicHeadersInfo* headers, UPInt* oldBytes);
    UPInt GetUsableSize(const PageMH* page, const void* ptr) const;

private:
    ListBinMH Bin;
};

}}  // namespace Scaleform::HeapMH

#endif
