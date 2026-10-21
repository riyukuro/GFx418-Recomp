// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapMH_Root (the MH heap root:
// the page pool and its two-level page table, the per-page magic headers, heap creation and destruction).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14263fb00-0x1426406e0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_root.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_memoryheap.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_allocengine.h"
#include <string.h>

namespace Scaleform { namespace HeapMH {

RootMH*     GlobalRootMH = 0;      // exe 0x143b160f0
PageTableMH GlobalPageTableMH;     // exe 0x143b16100
PageMH      GlobalEmptyPage;       // exe 0x143b16900

// The magic headers sit on both sides of the first 4 KB boundary inside the page allocation (the allocation is only
// 8-byte aligned); the busy bit set goes on the larger side.
void GetMagicHeaders(UPInt pageStart, MagicHeadersInfo* headers)
{
    headers->Header1 = 0;
    headers->Header2 = 0;
    UPInt bound = (pageStart + PageMH::PageMask) & ~UPInt(PageMH::PageMask);
    UPInt start = (pageStart + PageMH::UnitMask) & ~UPInt(PageMH::UnitMask);
    UPInt end   = (pageStart + PageMH::PageSize) & ~UPInt(PageMH::UnitMask);
    if (bound - start > sizeof(MagicHeader))
        headers->Header1 = (MagicHeader*)(bound - sizeof(MagicHeader));
    if (end - bound > sizeof(MagicHeader))
        headers->Header2 = (MagicHeader*)bound;
    headers->BitSet = (UInt32*)((bound - start > end - bound) ? bound - sizeof(MagicHeader) - PageMH::BitSetBytes
                                                              : bound + sizeof(MagicHeader));
    headers->AlignedStart = (UByte*)start;
    headers->AlignedEnd   = (UByte*)end;
    headers->Bound        = (UByte*)bound;
    headers->Page         = 0;
}

RootMH::RootMH(SysAlloc* sysAlloc) : pSysAlloc(sysAlloc), TableCount(0)
{
    GlobalEmptyPage.pHeap = 0;
    GlobalEmptyPage.Start = 0;
    for (int i = 0; i < PageTableMH::TableSize; ++i)
    {
        GlobalPageTableMH.Entries[i].FirstPage = &GlobalEmptyPage;
        GlobalPageTableMH.Entries[i].SizeMask  = 0;
    }
    GlobalRootMH = this;
}

RootMH::~RootMH()
{
    FreeTables();
    GlobalRootMH = 0;
}

void RootMH::FreeTables()
{
    for (unsigned i = 0; i < PageTableMH::TableSize; ++i)
    {
        if (GlobalPageTableMH.Entries[i].FirstPage != &GlobalEmptyPage)
            pSysAlloc->Free(GlobalPageTableMH.Entries[i].FirstPage,
                            (GlobalPageTableMH.Entries[i].SizeMask + 1) * sizeof(PageMH), sizeof(void*));
        GlobalPageTableMH.Entries[i].FirstPage = &GlobalEmptyPage;
        GlobalPageTableMH.Entries[i].SizeMask  = 0;
    }
}

MemoryHeapMH* RootMH::CreateHeap(const char* name, MemoryHeapMH* parent, const MemoryHeap::HeapDesc& desc)
{
    UPInt heapSize = (sizeof(MemoryHeapMH) + sizeof(AllocEngineMH) + strlen(name) + 1 + PageMH::UnitMask) &
                     ~UPInt(PageMH::UnitMask);
    UByte* heapBuf = (UByte*)pSysAlloc->Alloc(heapSize, sizeof(void*));
    if (heapBuf == 0)
        return 0;

    MemoryHeapMH*  heap   = ::new(heapBuf) MemoryHeapMH;
    AllocEngineMH* engine = ::new(heapBuf + sizeof(MemoryHeapMH))
                            AllocEngineMH(pSysAlloc, heap, desc.MinAlign, desc.Limit);
    char* heapName = (char*)(heapBuf + sizeof(MemoryHeapMH) + sizeof(AllocEngineMH));

    heap->SelfSize       = heapSize;
    heap->RefCount       = 1;
    heap->pAutoRelease   = 0;
    heap->Info.Desc      = desc;
    heap->Info.pParent   = parent;
    heap->Info.pName     = heapName;
    heap->UseLocks       = (desc.Flags & MemoryHeap::Heap_ThreadUnsafe) == 0;
    heap->TrackDebugInfo = (desc.Flags & MemoryHeap::Heap_NoDebugInfo) == 0;
    heap->pEngine        = engine;
    memcpy(heapName, name, strlen(name) + 1);
    return heap;
}

void RootMH::DestroyHeap(MemoryHeapMH* heap)
{
    UPInt heapSize = heap->SelfSize;
    heap->pEngine->~AllocEngineMH();
    heap->~MemoryHeapMH();
    pSysAlloc->Free(heap, heapSize, sizeof(void*));
}

PageMH* RootMH::AllocPage(MemoryHeapMH* heap)
{
    if (FreePages.IsEmpty())
    {
        if (!allocPagePool())
            return 0;
    }
    PageMH* page = FreePages.GetFirst();
    page->Start = (UByte*)pSysAlloc->Alloc(PageMH::PageSize, sizeof(void*));
    if (page->Start == 0)
    {
        page->pHeap = 0;
        return 0;
    }
    FreePages.Remove(page);
    page->pHeap = heap;
    setMagic(page->Start, MagicHeader::MagicValue);
    return page;
}

void RootMH::FreePage(PageMH* page)
{
    clearMagic(page->Start);
    UByte* start = page->Start;
    page->Start = 0;
    page->pHeap = 0;
    pSysAlloc->Free(start, PageMH::PageSize, sizeof(void*));
    FreePages.PushBack(page);
}

UInt32 RootMH::GetPageIndex(const PageMH* page) const
{
    for (unsigned i = 0; i < TableCount; ++i)
    {
        const PageTableMH::Level0Entry& e = GlobalPageTableMH.Entries[i];
        UPInt index1 = page - e.FirstPage;
        if (index1 <= e.SizeMask)
            return UInt32((index1 << PageTableMH::Index1Shift) | i);
    }
    return ~UInt32(0);
}

PageMH* RootMH::ResolveAddress(UPInt addr) const
{
    UByte* pageAddr = (UByte*)(addr & ~UPInt(PageMH::PageMask));
    const MagicHeader* header = (const MagicHeader*)pageAddr;
    if (header->Magic == MagicHeader::MagicValue)
    {
        const PageTableMH::Level0Entry& e = GlobalPageTableMH.Entries[header->GetIndex0()];
        PageMH* page = e.FirstPage + (header->GetIndex1() & e.SizeMask);
        if (addr - UPInt(page->Start) < PageMH::PageSize)
            return page;
    }
    header = (const MagicHeader*)(pageAddr + PageMH::PageSize - sizeof(MagicHeader));
    if (header->Magic == MagicHeader::MagicValue)
    {
        const PageTableMH::Level0Entry& e = GlobalPageTableMH.Entries[header->GetIndex0()];
        PageMH* page = e.FirstPage + (header->GetIndex1() & e.SizeMask);
        if (addr - UPInt(page->Start) < PageMH::PageSize)
            return page;
    }
    return 0;
}

// Each new table holds twice the pages of the previous 16 (128 << TableCount/16 pages per table).
bool RootMH::allocPagePool()
{
    if (TableCount >= PageTableMH::TableSize)
    {
        *(int*)4 = 0;    // out of page tables: the exe faults deliberately
        return false;
    }
    UPInt   count = PageTableMH::TableSize << (TableCount >> 4);
    PageMH* pages = (PageMH*)pSysAlloc->Alloc(sizeof(PageMH) * count, sizeof(void*));
    if (pages == 0)
        return false;

    GlobalPageTableMH.Entries[TableCount].FirstPage = pages;
    GlobalPageTableMH.Entries[TableCount].SizeMask  = count - 1;
    for (UPInt i = 0; i < count; ++i)
    {
        pages[i].pHeap = 0;
        pages[i].Start = 0;
        FreePages.PushBack(pages + i);
    }
    ++TableCount;
    return true;
}

void RootMH::clearMagic(UByte* pageStart)
{
    MagicHeadersInfo headers;
    GetMagicHeaders(UPInt(pageStart), &headers);
    if (headers.Header1)
    {
        headers.Header1->Magic       = 0;
        headers.Header1->UseCount    = 0;
        headers.Header1->Index       = 0;
        headers.Header1->DebugHeader = 0;
    }
    if (headers.Header2)
    {
        headers.Header2->Magic       = 0;
        headers.Header2->UseCount    = 0;
        headers.Header2->Index       = 0;
        headers.Header2->DebugHeader = 0;
    }
}

void RootMH::setMagic(UByte* pageStart, unsigned magicValue)
{
    MagicHeadersInfo headers;
    GetMagicHeaders(UPInt(pageStart), &headers);
    if (headers.Header1)
        headers.Header1->Magic = UInt16(magicValue);
    if (headers.Header2)
        headers.Header2->Magic = UInt16(magicValue);
}

}}  // namespace Scaleform::HeapMH
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0RootMH@HeapMH@Scaleform@@QEAA@PEAVSysAlloc@2@@Z 0x14263fb00
// MS2-PIN: ??1RootMH@HeapMH@Scaleform@@QEAA@XZ 0x14263fec0
// MS2-PIN: ?AllocPage@RootMH@HeapMH@Scaleform@@QEAAPEAUPageMH@23@PEAVMemoryHeapMH@3@@Z 0x14263ff50
// MS2-PIN: ?CreateHeap@RootMH@HeapMH@Scaleform@@QEAAPEAVMemoryHeapMH@3@PEBDPEAV43@AEBUHeapDesc@MemoryHeap@3@@Z 0x1426400e0
// MS2-PIN: ?DestroyHeap@RootMH@HeapMH@Scaleform@@QEAAXPEAVMemoryHeapMH@3@@Z 0x142640220
// MS2-PIN: ?FreePage@RootMH@HeapMH@Scaleform@@QEAAXPEAUPageMH@23@@Z 0x142640280
// MS2-PIN: ?FreeTables@RootMH@HeapMH@Scaleform@@QEAAXXZ 0x142640340
// MS2-PIN: ?GetMagicHeaders@HeapMH@Scaleform@@YAX_KPEAUMagicHeadersInfo@12@@Z 0x1426403d0
// MS2-PIN: ?GetPageIndex@RootMH@HeapMH@Scaleform@@QEBAKPEBUPageMH@23@@Z 0x142640470
// MS2-PIN: ?ResolveAddress@RootMH@HeapMH@Scaleform@@QEBAPEAUPageMH@23@_K@Z 0x1426404c0
// MS2-PIN: ?allocPagePool@RootMH@HeapMH@Scaleform@@AEAA_NXZ 0x142640550
// MS2-PIN: ?clearMagic@RootMH@HeapMH@Scaleform@@CAXPEAE@Z 0x142640620
// MS2-PIN: ?setMagic@RootMH@HeapMH@Scaleform@@CAXPEAEI@Z 0x142640680
