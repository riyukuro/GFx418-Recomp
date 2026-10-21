// Recovered Scaleform GFx 4.1.18: page-mapping system allocator (bodies in sfr_kernel_02). Reserves address-space
// segments through a SysMemMapper, commits pages on demand and keeps a 2-bit-per-page busy map in the last page of
// each segment.
#ifndef MS2_SF_KERNEL_HEAPPT_SYSALLOCMAPPER_H
#define MS2_SF_KERNEL_HEAPPT_SYSALLOCMAPPER_H

#include "ms2/scaleform/kernel/sf_sysalloc.h"

namespace Scaleform {

class SysAllocMapper : public SysAllocPaged
{
    struct Segment
    {
        UByte* Memory;
        UPInt  Size;
        UPInt  PageCount;
    };
    enum { MaxSegments = 32 };

public:
    SysAllocMapper(SysMemMapper* mapper, UPInt segSize, UPInt granularity, bool bestFit = true);

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt align);
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align);
    virtual bool  Free(void* ptr, UPInt size, UPInt align);
    virtual UPInt GetFootprint() const { return Footprint; }
    virtual UPInt GetUsedSpace() const { return Footprint; }

    const UInt32* GetBitSet(UPInt numSeg) const
    {
        if (numSeg >= NumSegments)
            return 0;
        return (const UInt32*)(Segments[numSeg].Memory + SegmSize - PageSize);
    }
    virtual UPInt GetBase() const;

private:
    UPInt   getBitSize(UPInt size) const;
    UInt32* getBitSet(const UByte* start, UPInt size) const;
    UPInt   getEndBit(UPInt size) const;
    UByte*  getAlignedPtr(const UByte* ptr, UPInt alignment) const;
    bool    alignmentIsOK(const UByte* ptr, UPInt size, UPInt alignment, UPInt limit) const;
    void*   allocMem(UPInt pos, UPInt size, UPInt alignment);
    void*   allocMem(UPInt size, UPInt alignment);
    UPInt   freeMem(void* ptr, UPInt size);
    bool    inRange(const UByte* ptr, const Segment* seg) const;
    UPInt   binarySearch(const UByte* ptr) const;
    UPInt   findSegment(const UByte* ptr) const;
    bool    reserveSegment(UPInt size);
    void    releaseSegment(UPInt pos);

    SysMemMapper* pMapper;
    UPInt         PageSize;
    UPInt         PageShift;
    UPInt         SegmSize;
    UPInt         Granularity;
    UPInt         Footprint;
    Segment       Segments[MaxSegments];
    UPInt         NumSegments;
    UPInt         LastSegment;
    bool          BestFit;
    UByte*        LastUsed;
};

}  // namespace Scaleform

#endif
