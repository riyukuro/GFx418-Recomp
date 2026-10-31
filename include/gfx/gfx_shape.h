// Recovered Scaleform 4.1.18 GFx: the shape character side of GFx_Shape (only the parts used by recovered units so
// far). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_SHAPE_H
#define MS2_SF_GFX_SHAPE_H

#include "../kernel/sf_memory.h"
#include "../kernel/sf_types.h"

namespace Scaleform { namespace GFx {

// Page allocator of the shape paths of a movie (0x18 bytes). Pages are chained in allocation order; only the last one
// is allocated from, FreeBytes being what is left of it.
class PathAllocator : public NewOverrideBase<0x104> // StatMD_ShapeData_Mem
{
    struct Page
    {
        Page*  pNext;
        UInt32 PageSize;
        UByte  Buffer[4]; // the page data starts at +0xc

        UByte* GetBufferPtr() { return ((UByte*)(&PageSize + 1)); }
        UByte* GetBufferPtr(unsigned freeBytes) { return ((UByte*)(&PageSize + 1)) + PageSize - freeBytes; }
    };

    static bool IsInPage(const void* ppage, const UByte* ptr)
    {
        const Page* p = (const Page*)ppage;
        return (ptr - (const UByte*)(&p->PageSize + 1)) < (int)p->PageSize;
    }

    Page*  pFirstPage;      // +0
    Page*  pLastPage;       // +8
    UInt16 FreeBytes;       // +0x10
    UInt16 DefaultPageSize; // +0x12

public:
    PathAllocator(unsigned pageSize = 0x2000);
    ~PathAllocator();

    void Clear();

    // A path record: one flag byte, the path header (3 fields of pathSize bytes, aligned to pathSize) and the edge
    // data (aligned to edgeSize).
    UByte* AllocPath(unsigned edgesDataSize, unsigned pathSize, unsigned edgeSize);
    UByte* AllocRawPath(UInt32 sizeInBytes);
    // sizeForCurrentPage bytes from the current page, or sizeInNewPage from a new one when it does not fit.
    UByte* AllocMemoryBlock(UInt32 sizeForCurrentPage, UInt32 sizeInNewPage);
    // Shrinks the last block of the current page (newSize < oldSize).
    bool   ReallocLastBlock(UByte* ptr, UInt32 oldSize, UInt32 newSize);
};

}} // namespace Scaleform::GFx

#endif
