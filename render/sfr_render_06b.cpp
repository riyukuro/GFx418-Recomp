// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the matrix pool TU
// (Render_MatrixPool). Cache nodes hold HMatrix handles; a handle points at a block (header + optional cxform,
// texture matrices, user data, then the 2D or 3D matrix) inside 4 KB data pages. Handles live in 2 KB aligned
// handle pages so blocks can move: a squeeze compacts the pages and repoints the handles.
// Queue unit sfr_render_06 is split along its original sources (06b Render_MatrixPool).
// MS2-UNIT: sfr_render_06b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426b9cd0-0x1426bb650 .text$mn

#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/kernel/sf_memory.h"

#include <string.h>

namespace Scaleform { namespace Render { namespace MatrixPoolImpl {

namespace {

// Bytes of a block's payload for a format: everything ahead of the matrix plus two (2D) or three (3D) units.
inline unsigned PayloadBytes(unsigned formatBits)
{
    unsigned front = HMatrixConstants::MatrixElementSizeTable[formatBits & HMatrixConstants::Has_TableMask]
                         .Offsets[HMatrixConstants::Element_Matrix];
    return (front + ((formatBits & HMatrixConstants::Has_3D) ? 3 : 2)) * Pool_DataUnitSize;
}

inline bool SameMatrix(const Matrix2F& a, const Matrix2F& b) { return memcmp(&a, &b, sizeof(Matrix2F)) == 0; }
inline bool SameMatrix(const Matrix3F& a, const Matrix3F& b) { return memcmp(&a, &b, sizeof(Matrix3F)) == 0; }

// Moves a live block to dest inside page and repoints its handle.
inline void MoveBlock(DataPage* page, DataHeader* dest, DataHeader* src)
{
    if (dest == src)
        return;
    memmove(dest, src, src->UnitSize * Pool_DataUnitSize);
    dest->DataPageOffset = (SInt16)((UByte*)page - (UByte*)dest);
    dest->pHandle->pHeader = dest;
}

} // namespace

// ---------------------------------------------------------------------------------------------------------------
// Handles

// Puts the handle back on its page's free list; a page that was full goes back to the partly free list first, and
// a page with no handles left is freed.
void EntryHandle::ReleaseHandle()
{
    HandlePage* page = GetHandlePage();
    if (page->pFreeList == 0)
    {
        page->RemoveNode();
        page->pTable->PartiallyFreePages.PushFront(page);
    }
    FreeLink() = page->pFreeList;
    page->pFreeList = this;
    if (--page->UseCount == 0)
    {
        page->RemoveNode();
        SF_HEAP_FREE(page->pTable->pHeap, page);
    }
}

bool EntryHandleTable::allocEntryPage()
{
    HandlePage* page = (HandlePage*)SF_HEAP_MEMALIGN(pHeap, HandlePage::PageBytes, HandlePage::PageAlign,
                                                     StatRender_MatrixPoolHandle_Mem);
    if (page == 0)
        return false;
    page->pTable   = this;
    page->UseCount = 0;
    // chain every entry, first to last
    EntryHandle* next = 0;
    for (UPInt i = HandlePage::EntryCount; i != 0; i--)
    {
        page->Entries[i - 1].FreeLink() = next;
        next = &page->Entries[i - 1];
    }
    page->pFreeList = next;
    PartiallyFreePages.PushBack(page);
    return true;
}

EntryHandle* EntryHandleTable::AllocEntry(DataHeader* header)
{
    if (PartiallyFreePages.IsEmpty() && !allocEntryPage())
        return 0;
    HandlePage*  page = PartiallyFreePages.GetFirst();
    EntryHandle* h    = page->pFreeList;
    page->pFreeList = h->FreeLink();
    page->UseCount++;
    if (h->FreeLink() == 0)
    {
        // that was the page's last free handle
        page->RemoveNode();
        FullPages.PushBack(page);
    }
    h->pHeader = header;
    return h;
}

// The block's last reference: its bytes become a hole of the page, and the handle is returned.
void DataHeader::Release()
{
    if (--RefCount != 0)
        return;
    DataPage* page = GetDataPage();
    page->FreeMiddle = page->FreeMiddle + (UInt16)(UnitSize * Pool_DataUnitSize);
    page->pPool->FreedSpace += UnitSize * Pool_DataUnitSize;
    pHandle->ReleaseHandle();
    pHandle = 0;
}

// ---------------------------------------------------------------------------------------------------------------
// HMatrix

void HMatrix::operator=(const HMatrix& other)
{
    if (other.pHandle != &NullHandle)
        other.pHandle->AddRef();
    if (pHandle != &NullHandle)
        pHandle->Release();
    pHandle = other.pHandle;
}

void HMatrix::SetMatrix2D(const Matrix2F& m)
{
    *pHandle->GetMatrixPtr() = m;
}

// MS2-FUNCTIONAL: rbx/rdi swap (pHandle / m). A 2D block only grows a 3D matrix when the new one is not the identity.
void HMatrix::SetMatrix3D(const Matrix3F& m)
{
    if (!Has3D())
    {
        if (SameMatrix(m, Matrix3F::Identity))
            return;
        pHandle->ChangeFormat(pHandle->pHeader->Format | Has_3D);
    }
    *pHandle->GetMatrix3DPtr() = m;
}

void HMatrix::SetCxform(const Cxform& cx)
{
    if (!pHandle->HasElement(Element_Cxform))
    {
        if (cx == Cxform::Identity)
            return;
        pHandle->AddElement(Element_Cxform);
    }
    *pHandle->GetCxformPtr() = cx;
}

// MS2-FUNCTIONAL: register allocation (mask / format / handle).
void HMatrix::SetTextureMatrix(const Matrix2F& m, unsigned index)
{
    ElementIndex e = (ElementIndex)(Element_T0 + index);
    if (!pHandle->pHeader->HasElement(e))
    {
        if (SameMatrix(m, Matrix2F::Identity))
            return;
        pHandle->ChangeFormat(pHandle->pHeader->Format | (1 << e));
    }
    *pHandle->pHeader->GetTextureMatrixPtr(e) = m;
}

// A null data pointer clears the user data (and does not add it to a block without any).
void HMatrix::SetUserData(const void* data, UPInt size)
{
    if (!pHandle->HasElement(Element_UserData))
    {
        if (data == 0)
            return;
        pHandle->AddElement(Element_UserData);
    }
    void* dest = pHandle->GetUserDataPtr();
    if (data != 0)
        memcpy(dest, data, size);
    else
        memset(dest, 0, size);
}

// ---------------------------------------------------------------------------------------------------------------
// MatrixPool

MatrixPool::MatrixPool(MemoryHeap* heap)
    : pHeap(heap), AllocatedSpace(0), DataPageCount(0), FreedSpace(0), HandleTable(heap, this),
      pAllocPage(0), pSqueezePage(0), pLastFreedPage(0)
{
}

MatrixPool::~MatrixPool()
{
    while (!DataPages.IsEmpty())
        freeDataPage(DataPages.GetFirst());
    if (pLastFreedPage != 0)
        SF_FREE(pLastFreedPage);
}

EntryHandle* MatrixPool::createMatrixHelper(const Matrix2F& m, const Cxform& cx, unsigned formatBits)
{
    EntryHandle* h = allocMatrixData(formatBits);
    if (h != 0)
    {
        *h->pHeader->GetMatrixPtr() = m;
        if (formatBits & Has_Cxform)
            *h->pHeader->GetCxformPtr() = cx;
        if (formatBits & Has_T0)
            h->pHeader->GetTextureMatrixPtr(Element_T0)->SetIdentity();
        if (formatBits & Has_T1)
            h->pHeader->GetTextureMatrixPtr(Element_T1)->SetIdentity();
        if (formatBits & Has_UserData)
            memset(h->pHeader->GetUserDataPtr(), 0, Pool_UserDataSize);
    }
    else
    {
        h = &HMatrix::NullHandle;   // out of memory: the identity
    }
    return h;
}

EntryHandle* MatrixPool::createMatrixHelper(const Matrix3F& m, const Cxform& cx, unsigned formatBits)
{
    EntryHandle* h = allocMatrixData(formatBits);
    if (h != 0)
    {
        *h->pHeader->GetMatrix3DPtr() = m;
        if (formatBits & Has_Cxform)
            *h->pHeader->GetCxformPtr() = cx;
        if (formatBits & Has_T0)
            h->pHeader->GetTextureMatrixPtr(Element_T0)->SetIdentity();
        if (formatBits & Has_T1)
            h->pHeader->GetTextureMatrixPtr(Element_T1)->SetIdentity();
        if (formatBits & Has_UserData)
            memset(h->pHeader->GetUserDataPtr(), 0, Pool_UserDataSize);
    }
    else
    {
        h = &HMatrix::NullHandle;   // out of memory: the identity
    }
    return h;
}

HMatrix MatrixPool::CreateMatrix(unsigned formatBits)
{
    return HMatrix(createMatrixHelper(Matrix2F::Identity, Cxform::Identity, formatBits));
}

HMatrix MatrixPool::CreateMatrix(const Matrix2F& m, unsigned formatBits)
{
    return HMatrix(createMatrixHelper(m, Cxform::Identity, formatBits));
}

HMatrix MatrixPool::CreateMatrix(const Matrix3F& m, unsigned formatBits)
{
    return HMatrix(createMatrixHelper(m, Cxform::Identity, formatBits));
}

HMatrix MatrixPool::CreateMatrix(const Matrix2F& m, const Cxform& cx, unsigned formatBits)
{
    return HMatrix(createMatrixHelper(m, cx, formatBits));
}

HMatrix MatrixPool::CreateMatrix(const Matrix3F& m, const Cxform& cx, unsigned formatBits)
{
    return HMatrix(createMatrixHelper(m, cx, formatBits));
}

// Squeezes once the holes reach 3/32 of the pages (always when forced); an incremental squeeze first resumes where
// the last one stopped.
bool MatrixPool::MemorySqueeze(SqueezeType type)
{
    if (type != Squeeze_Force && FreedSpace < (AllocatedSpace * 3) / 32)
        return false;
    if (type == Squeeze_Incremental && pSqueezePage != 0 &&
        squeezeMemoryRange(pSqueezePage, DataPages.GetFirst()->pPrev, type))
        return true;
    return squeezeMemoryRange(DataPages.GetFirst(), DataPages.GetFirst()->pPrev, type);
}

bool MatrixPool::allocDataPage()
{
    DataPage* page = pLastFreedPage;
    if (page == 0)
    {
        page = (DataPage*)SF_HEAP_MEMALIGN(pHeap, DataPage::PageBytes, Pool_DataUnitSize, StatRender_MatrixPool_Mem);
        if (page == 0)
            return false;
    }
    else
    {
        pLastFreedPage = 0;
    }
    page->pPool      = this;
    page->FreeTail   = (UInt16)DataPage::DataBytes();
    page->FreeMiddle = 0;
    DataPages.PushBack(page);
    AllocatedSpace += DataPage::DataBytes();
    DataPageCount++;
    pAllocPage = page;
    return true;
}

// Unlinks the page and keeps it as the cached free page (freeing the previous one).
void MatrixPool::freeDataPage(DataPage* page)
{
    page->RemoveNode();
    AllocatedSpace -= DataPage::DataBytes();
    DataPageCount--;
    if (pLastFreedPage != 0)
        SF_FREE(pLastFreedPage);
    pLastFreedPage = page;
}

bool MatrixPool::ensureAllocSpace(UPInt size)
{
    // allocation may have moved into an earlier page after a squeeze; go back to the last page
    if (pAllocPage != DataPages.GetLast() && !DataPages.IsEmpty())
    {
        pAllocPage = DataPages.GetLast();
        if (pAllocPage->FreeTail >= size)
            return true;
    }
    MemorySqueeze(Squeeze_Incremental);
    if (pAllocPage != 0 && pAllocPage->FreeTail >= size)
        return true;
    return allocDataPage();
}

DataHeader* MatrixPool::allocData(UPInt size, EntryHandle* handle)
{
    UPInt blockBytes = size + Pool_DataUnitSize;
    if ((pAllocPage == 0 || pAllocPage->FreeTail < blockBytes) && !ensureAllocSpace(blockBytes))
        return 0;
    DataPage*   page = pAllocPage;
    DataHeader* d    = page->TailStart();
    d->pHandle        = handle;
    d->RefCount       = 1;
    d->DataPageOffset = (SInt16)((UByte*)page - (UByte*)d);
    d->UnitSize       = (UByte)(size / Pool_DataUnitSize) + 1;
    d->Format         = 0;
    page->FreeTail = page->FreeTail - (UInt16)blockBytes;
    return d;
}

EntryHandle* MatrixPool::allocMatrixData(unsigned formatBits)
{
    UPInt        size = PayloadBytes(formatBits);
    EntryHandle* h    = HandleTable.AllocEntry();
    if (h == 0)
        return 0;
    h->pHeader = allocData(size, h);
    if (h->pHeader == 0)
    {
        h->ReleaseHandle();
        return 0;
    }
    h->pHeader->Format = (UByte)formatBits;
    return h;
}

// Gives the handle a new block in the new format, carrying over what both formats have (missing elements start
// as identity / zero) and turning the old block into a hole.
// MS2-FUNCTIONAL: the exe's 2D->3D temporary is 16-byte aligned (movaps) and r9/r10 swap.
bool MatrixPool::reallocMatrixData(EntryHandle* handle, unsigned formatBits)
{
    DataHeader* to = allocData(PayloadBytes(formatBits), handle);
    if (to == 0)
        return false;
    DataHeader* from = handle->pHeader;   // read after allocData (a squeeze may have moved it)
    to->Format   = (UByte)formatBits;
    to->RefCount = from->RefCount;
    UByte oldFormat = from->Format;

    if (formatBits & Has_3D)
    {
        if (from->Format & Has_3D)
            *to->GetMatrix3DPtr() = *from->GetMatrix3DPtr();
        else
            *to->GetMatrix3DPtr() = *from->GetMatrixPtr();   // a 2D matrix widened to 3D
    }
    else
    {
        *to->GetMatrixPtr() = *from->GetMatrixPtr();
    }

    if (formatBits & Has_Cxform)
        *to->GetCxformPtr() = (oldFormat & Has_Cxform) ? *from->GetCxformPtr() : Cxform::Identity;
    if (formatBits & Has_T0)
        *to->GetTextureMatrixPtr(Element_T0) =
            (oldFormat & Has_T0) ? *from->GetTextureMatrixPtr(Element_T0) : Matrix2F::Identity;
    if (formatBits & Has_T1)
        *to->GetTextureMatrixPtr(Element_T1) =
            (oldFormat & Has_T1) ? *from->GetTextureMatrixPtr(Element_T1) : Matrix2F::Identity;
    if (formatBits & Has_UserData)
    {
        void* dest = to->GetUserDataPtr();
        if (oldFormat & Has_UserData)
            memcpy(dest, from->GetUserDataPtr(), Pool_UserDataSize);
        else
            memset(dest, 0, Pool_UserDataSize);
    }

    if (from->pHandle != &HMatrix::NullHandle)
    {
        UInt16 bytes = (UInt16)(from->UnitSize * Pool_DataUnitSize);
        from->pHandle  = 0;
        from->RefCount = 0;
        DataPage* page = from->GetDataPage();
        page->FreeMiddle = page->FreeMiddle + bytes;
        FreedSpace += bytes;
    }
    handle->pHeader = to;
    return true;
}

// Compacts the live blocks of the pages [from, to) towards the front: pages with under 5% free space are skipped,
// blocks are moved into the current destination page, and a page left empty is freed. An incremental squeeze stops
// after the first page it frees (or that gains a quarter page of tail).
bool MatrixPool::squeezeMemoryRange(DataPage* from, DataPage* to, SqueezeType type)
{
    enum { SkipBelow = (DataPage::PageBytes - sizeof(DataPage)) / 20,
           StopAbove = (DataPage::PageBytes - sizeof(DataPage)) / 4 };

    bool freed = false;
    pAllocPage   = 0;
    pSqueezePage = 0;

    DataPage*   src     = from;
    DataPage*   dst     = 0;
    DataHeader* dstAt   = 0;
    DataHeader* dstEnd  = 0;

    while (src != to)
    {
        if ((unsigned)(src->FreeMiddle + src->FreeTail) <= (unsigned)SkipBelow)
        {
            src = src->pNext;
            continue;
        }

        DataHeader* at    = src->First();
        DataHeader* end   = src->TailStart();
        UInt16      holes = src->FreeMiddle;
        if (dst == 0)
        {
            dst    = src;
            dstAt  = dst->First();
            dstEnd = dst->End();
            if (src->FreeMiddle == 0)
            {
                // nothing to close up in this page; continue filling after its last block
                at    = end;
                dstAt = end;
            }
        }

        unsigned units = 0;
        for (; at != end; at = at->Next(units))
        {
            units = at->UnitSize;
            if (at->RefCount == 0)
                continue;
            if (dstAt->Next(units) > dstEnd)
            {
                // destination full: close it and continue in the source page itself
                dst->FreeTail = (UInt16)((UByte*)dstEnd - (UByte*)dstAt);
                dst    = src;
                dstAt  = dst->First();
                dstEnd = dst->End();
            }
            MoveBlock(dst, dstAt, at);
            dstAt = dstAt->Next(units);
        }

        FreedSpace -= src->FreeMiddle;
        src->FreeMiddle = 0;

        if (dst != src || dstAt == dst->First())
        {
            // everything moved out: the source page is empty
            if (dst == src)
                dst = 0;
            DataPage* empty = src;
            src = src->pNext;
            freeDataPage(empty);
            freed = true;
            if (type == Squeeze_Incremental)
                break;
            continue;
        }

        if (holes != 0 && (SPInt)((UByte*)dstEnd - (UByte*)dstAt) >= (SPInt)StopAbove)
        {
            freed = true;
            if (type == Squeeze_Incremental)
                break;
        }
        src = src->pNext;
    }

    if (dst != 0)
    {
        dst->FreeTail = (UInt16)((UByte*)dstEnd - (UByte*)dstAt);
        pAllocPage   = dst;
        pSqueezePage = dst;
    }
    else
    {
        pAllocPage = 0;
        if (!DataPages.IsNull(src))
            pSqueezePage = src;
    }
    return freed;
}

}}} // namespace Scaleform::Render::MatrixPoolImpl

// MS2-PIN: ?SetCxform@HMatrix@MatrixPoolImpl@Render@Scaleform@@QEAAXAEBVCxform@34@@Z 0x1426ba420
// MS2-PIN: ?SetMatrix3D@HMatrix@MatrixPoolImpl@Render@Scaleform@@QEAAXAEBV?$Matrix3x4@M@34@@Z 0x1426ba520
// MS2-PIN: ?SetTextureMatrix@HMatrix@MatrixPoolImpl@Render@Scaleform@@QEAAXAEBV?$Matrix2x4@M@34@I@Z 0x1426ba5e0
// MS2-PIN: ?createMatrixHelper@MatrixPool@MatrixPoolImpl@Render@Scaleform@@AEAAPEAUEntryHandle@234@AEBV?$Matrix2x4@M@34@AEBVCxform@34@I@Z 0x1426bab60
// MS2-PIN: ?createMatrixHelper@MatrixPool@MatrixPoolImpl@Render@Scaleform@@AEAAPEAUEntryHandle@234@AEBV?$Matrix3x4@M@34@AEBVCxform@34@I@Z 0x1426bad00
// MS2-PIN: ?reallocMatrixData@MatrixPool@MatrixPoolImpl@Render@Scaleform@@AEAA_NPEAUEntryHandle@234@I@Z 0x1426bb040
// MS2-PIN: ??_7MatrixPool@MatrixPoolImpl@Render@Scaleform@@6B@ 0x143192610
// MS2-PIN: ??_7?$RefCountBase@VMatrixPool@MatrixPoolImpl@Render@Scaleform@@$0EM@@Scaleform@@6B@ 0x143192600
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EM@@Scaleform@@6B@ 0x143192608
