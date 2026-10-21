// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_PageTable (the global
// page -> segment map of the PT heaps; the Win64 build walks five table levels). Our own source, written from the
// exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426cc8f0-0x1426cd3d0 .text$mn
#include <new>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_pagetable.h"

namespace Scaleform { namespace HeapPT {

// in-place storage of the one page table (exe 0x143b17350)
static UPInt PageTableMem[(sizeof(PageTable) + sizeof(UPInt) - 1) / sizeof(UPInt)];
PageTable*   GlobalPageTable = 0;   // exe 0x143b17340

PageTable::PageTable() : pStarter(0)
{
    GlobalPageTable = this;
}

void PageTable::Init()
{
    ::new(PageTableMem) PageTable;
}

// make sure every table level below the range exists, holding one reference per covered entry; on failure the part
// mapped so far is unmapped again
bool PageTable::MapRange(void* mem, UPInt size)
{
    UPInt address     = (UPInt)mem;
    UPInt startIndex5 = address >> Heap_Lv5_PageShift;
    UPInt endIndex5   = (address + size - 1) >> Heap_Lv5_PageShift;
    for (UPInt i5 = startIndex5; i5 <= endIndex5; ++i5)
    {
        HeapHeader5* table5 = RootTable + i5;
        if (!table5->AddRef(pStarter))
        {
            UPInt badSize = (i5 - startIndex5) << Heap_Lv5_PageShift;
            UnmapRange(mem, badSize);
            return false;
        }

        UPInt i4        = 0;
        UPInt endIndex4 = Heap_Lv4_TableSize - 1;
        if (i5 == startIndex5)
            i4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        if (i5 == endIndex5)
            endIndex4 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        UPInt startIndex4 = i4;
        for (; i4 <= endIndex4; ++i4)
        {
            HeapHeader4* table4 = table5->GetTable(i4);
            if (!table4->AddRef(pStarter))
            {
                UPInt badSize = ((i5 - startIndex5) << Heap_Lv5_PageShift) +
                                ((i4 - startIndex4) << Heap_Lv4_PageShift);
                UnmapRange(mem, badSize);
                return false;
            }

            UPInt i3        = 0;
            UPInt endIndex3 = Heap_Lv3_TableSize - 1;
            if (i4 == startIndex4)
                i3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            if (i4 == endIndex4)
                endIndex3 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            UPInt startIndex3 = i3;
            for (; i3 <= endIndex3; ++i3)
            {
                HeapHeader3* table3 = table4->GetTable(i3);
                if (!table3->AddRef(pStarter))
                {
                    UPInt badSize = ((i5 - startIndex5) << Heap_Lv5_PageShift) +
                                    ((i4 - startIndex4) << Heap_Lv4_PageShift) +
                                    ((i3 - startIndex3) << Heap_Lv3_PageShift);
                    UnmapRange(mem, badSize);
                    return false;
                }

                UPInt i2        = 0;
                UPInt endIndex2 = Heap_Lv2_TableSize - 1;
                if (i3 == startIndex3)
                    i2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                if (i3 == endIndex3)
                    endIndex2 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                UPInt startIndex2 = i2;
                for (; i2 <= endIndex2; ++i2)
                {
                    HeapHeader2* table2 = table3->GetTable(i2);
                    if (!table2->AddRef(pStarter))
                    {
                        UPInt badSize = ((i5 - startIndex5) << Heap_Lv5_PageShift) +
                                        ((i4 - startIndex4) << Heap_Lv4_PageShift) +
                                        ((i3 - startIndex3) << Heap_Lv3_PageShift) +
                                        ((i2 - startIndex2) << Heap_Lv2_PageShift);
                        UnmapRange(mem, badSize);
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// drop the references MapRange took, innermost level first
void PageTable::UnmapRange(void* mem, UPInt size)
{
    UPInt address     = (UPInt)mem;
    UPInt startIndex5 = address >> Heap_Lv5_PageShift;
    UPInt endIndex5   = (address + size - 1) >> Heap_Lv5_PageShift;
    for (UPInt i5 = startIndex5; i5 <= endIndex5; ++i5)
    {
        HeapHeaderRoot* table5    = RootTable + i5;
        UPInt           i4        = 0;
        UPInt           endIndex4 = Heap_Lv4_TableSize - 1;
        if (i5 == startIndex5)
            i4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        if (i5 == endIndex5)
            endIndex4 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        UPInt startIndex4 = i4;
        for (; i4 <= endIndex4; ++i4)
        {
            HeapHeader4* table4    = table5->GetTable(i4);
            UPInt        i3        = 0;
            UPInt        endIndex3 = Heap_Lv3_TableSize - 1;
            if (i4 == startIndex4)
                i3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            if (i4 == endIndex4)
                endIndex3 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            UPInt startIndex3 = i3;
            for (; i3 <= endIndex3; ++i3)
            {
                HeapHeader3* table3    = table4->GetTable(i3);
                UPInt        i2        = 0;
                UPInt        endIndex2 = Heap_Lv2_TableSize - 1;
                if (i3 == startIndex3)
                    i2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                if (i3 == endIndex3)
                    endIndex2 = ((address + size - 1) & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                for (; i2 <= endIndex2; ++i2)
                {
                    HeapHeader2* table2 = table3->GetTable(i2);
                    table2->Release(pStarter);
                }
                table3->Release(pStarter);
            }
            table4->Release(pStarter);
        }
        table5->Release(pStarter);
    }
}

// resize a mapped block: unmap the old extent and map the new one (or the old one again if that fails), then fill
// the owner back in
bool PageTable::RemapRange(void* mem, UPInt newSize, UPInt oldSize)
{
    if (newSize == oldSize)
        return true;

    HeapSegment* seg  = GetSegment(UPInt(mem));
    bool         ret  = false;
    UPInt        size = oldSize;
    UnmapRange(mem, oldSize);
    if (MapRange(mem, newSize))
    {
        size = newSize;
        ret  = true;
    }
    else
    {
        MapRange(mem, oldSize);
    }
    SetSegmentInRange(UPInt(mem), size, seg);
    return ret;
}

// store the owner in every page entry of the range; the inner bounds apply only on the outer start/end paths
void PageTable::SetSegmentInRange(UPInt address, UPInt size, HeapSegment* seg)
{
    UPInt lastAddr    = address + size - 1;
    UPInt startIndex5 = address >> Heap_Lv5_PageShift;
    UPInt endIndex5   = lastAddr >> Heap_Lv5_PageShift;
    for (UPInt i5 = startIndex5; i5 <= endIndex5; ++i5)
    {
        const HeapHeader5* table5      = RootTable + i5;
        UPInt              startIndex4 = 0;
        UPInt              endIndex4   = Heap_Lv4_TableSize - 1;
        if (i5 == startIndex5)
            startIndex4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        if (i5 == endIndex5)
            endIndex4 = (lastAddr & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        for (UPInt i4 = startIndex4; i4 <= endIndex4; ++i4)
        {
            const HeapHeader4* table4      = table5->GetTable(i4);
            UPInt              startIndex3 = 0;
            UPInt              endIndex3   = Heap_Lv3_TableSize - 1;
            if ((i4 == startIndex4) && (i5 == startIndex5))
                startIndex3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            if ((i4 == endIndex4) && (i5 == endIndex5))
                endIndex3 = (lastAddr & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
            for (UPInt i3 = startIndex3; i3 <= endIndex3; ++i3)
            {
                const HeapHeader3* table3      = table4->GetTable(i3);
                UPInt              startIndex2 = 0;
                UPInt              endIndex2   = Heap_Lv2_TableSize - 1;
                if ((i3 == startIndex3) && (i4 == startIndex4) && (i5 == startIndex5))
                    startIndex2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                if ((i3 == endIndex3) && (i4 == endIndex4) && (i5 == endIndex5))
                    endIndex2 = (lastAddr & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
                for (UPInt i2 = startIndex2; i2 <= endIndex2; ++i2)
                {
                    const HeapHeader2* table2      = table3->GetTable(i2);
                    UPInt              startIndex1 = 0;
                    UPInt              endIndex1   = Heap_Lv1_TableSize - 1;
                    if ((i2 == startIndex2) && (i3 == startIndex3) && (i4 == startIndex4) && (i5 == startIndex5))
                        startIndex1 = (address & SF_HEAPPT_LVMASK(Heap_Lv2_PageShift)) >> Heap_Lv1_PageShift;
                    if ((i2 == endIndex2) && (i3 == endIndex3) && (i4 == endIndex4) && (i5 == endIndex5))
                        endIndex1 = (lastAddr & SF_HEAPPT_LVMASK(Heap_Lv2_PageShift)) >> Heap_Lv1_PageShift;
                    for (UPInt i1 = startIndex1; i1 <= endIndex1; ++i1)
                    {
                        HeapHeader1* table1 = table2->GetTable(i1);
                        table1->pSegment    = seg;
                    }
                }
            }
        }
    }
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?Init@PageTable@HeapPT@Scaleform@@SAXXZ 0x1426cc8f0
// MS2-PIN: ?MapRange@PageTable@HeapPT@Scaleform@@QEAA_NPEAX_K@Z 0x1426cc930
// MS2-PIN: ?RemapRange@PageTable@HeapPT@Scaleform@@QEAA_NPEAX_K1@Z 0x1426ccd30
// MS2-PIN: ?SetSegmentInRange@PageTable@HeapPT@Scaleform@@QEAAX_K0PEAUHeapSegment@Heap@3@@Z 0x1426cce20
// MS2-PIN: ?UnmapRange@PageTable@HeapPT@Scaleform@@QEAAXPEAX_K@Z 0x1426cd0d0
