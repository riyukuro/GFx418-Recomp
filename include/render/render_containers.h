// Recovered Scaleform 4.1.18 Render: small containers of the renderer (Render_Containers). Only the ones the
// recovered units use so far: LinearHeap (bump allocator over a page pool), PagedItemBuffer (append-only item pages)
// DepthUpdateArrayPOD (per-depth singly linked buckets) and ArrayReserveLH_Mov (small in-place arrays).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_CONTAINERS_H
#define MS2_SF_RENDER_CONTAINERS_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"
#include "ms2/scaleform/kernel/sf_allocator.h"

namespace Scaleform { namespace Render {

// Allocations are rounded up to pointer size and carved from the current page; a page that cannot hold a request
// moves on to the next pool slot (the pool doubles when full). Nothing is freed until Clear/ClearAndRelease.
class LinearHeap
{
    enum
    {
        MinAlignMask = sizeof(UPInt) - 1,
        PagePoolSize = 64
    };
    struct PageType
    {
        UByte* pStart;
        UByte* pEnd;
        UByte* pFree;
    };

public:
    LinearHeap(MemoryHeap* heap, UPInt granularity = 8192)
        : pHeap(heap), Granularity(granularity), pPagePool(0), pLastPage(0), MaxPages(0)
    {
    }
    ~LinearHeap() { ClearAndRelease(); }

    void Clear()
    {
        for (UPInt i = 0; i < MaxPages; ++i)
            pPagePool[i].pFree = pPagePool[i].pStart;
        pLastPage = pPagePool;
    }

    void ClearAndRelease()
    {
        if (MaxPages)
        {
            // pages are released last to first, then the pool itself
            PageType* page = pPagePool + MaxPages - 1;
            while (MaxPages--)
            {
                if (page->pStart)
                    pHeap->Free(page->pStart);
                --page;
            }
            pHeap->Free(pPagePool);
        }
        pPagePool = pLastPage = 0;
        MaxPages  = 0;
    }

    UPInt GetFootprint() const
    {
        UPInt bytes = 0;
        for (UPInt i = 0; i < MaxPages; ++i)
            bytes += pPagePool[i].pEnd - pPagePool[i].pStart;
        return UPInt(bytes + MaxPages * sizeof(PageType));
    }

    void* Alloc(UPInt size)
    {
        size = (size + MinAlignMask) & ~MinAlignMask;
        if (pLastPage)
        {
            void* p = allocFromLastPage(size);
            if (p)
                return p;
            ++pLastPage;
        }
        else
        {
            pLastPage = pPagePool = (PageType*)pHeap->Alloc(PagePoolSize * sizeof(PageType));
            memset(pPagePool, 0, PagePoolSize * sizeof(PageType));
            MaxPages = PagePoolSize;
        }
        if (pLastPage - pPagePool >= SPInt(MaxPages))
        {
            UPInt     used = pLastPage - pPagePool;
            PageType* pool = (PageType*)pHeap->Alloc(MaxPages * 2 * sizeof(PageType));
            memcpy(pool, pPagePool, MaxPages * sizeof(PageType));
            memset(pool + MaxPages, 0, MaxPages * sizeof(PageType));
            pHeap->Free(pPagePool);
            pPagePool = pool;
            MaxPages *= 2;
            pLastPage = pPagePool + used;
        }
        return allocFromLastPage(size);
    }

    MemoryHeap* GetMemoryHeap() { return pHeap; }

private:
    void* allocFromLastPage(UPInt size)
    {
        if (pLastPage->pEnd - pLastPage->pFree >= SPInt(size))
        {
            pLastPage->pFree += size;
            return pLastPage->pFree - size;
        }
        if (pLastPage->pFree == pLastPage->pStart)
        {
            // an unused slot: (re)allocate its page big enough for the request
            if (pLastPage->pEnd - pLastPage->pFree < SPInt(size))
                allocPage(size);
            pLastPage->pFree += size;
            return pLastPage->pStart;
        }
        return 0;
    }
    void allocPage(UPInt size)
    {
        if (pLastPage->pStart)
            pHeap->Free(pLastPage->pStart);
        size = (size + Granularity - 1) / Granularity * Granularity;
        pLastPage->pStart = pLastPage->pFree = (UByte*)pHeap->Alloc(size);
        pLastPage->pEnd   = pLastPage->pStart + size;
    }

    MemoryHeap* pHeap;
    UPInt       Granularity;
    PageType*   pPagePool;
    PageType*   pLastPage;
    UPInt       MaxPages;
};

// Items live in fixed pages (a next link, a count, the items) taken from the heap of the buffer's owner.
template<class C, int ItemsPerPage>
class PagedItemBuffer
{
public:
    struct Page
    {
        Page*    pNext;
        unsigned Count;
        C        Items[ItemsPerPage];

        Page*    GetNextPage() const      { return pNext; }
        unsigned GetSize() const          { return Count; }
        C&       GetItem(unsigned index)  { return Items[index]; }
    };

    PagedItemBuffer() : pPages(0), pLast(0) {}
    ~PagedItemBuffer() { freePages(false); }

    C* AddItem()
    {
        ensureCountAvailable(1);
        C* item = &pLast->Items[pLast->Count];
        Construct<C>(item);
        pLast->Count++;
        return item;
    }
    template<class A>
    C* AddItem(const A& arg)
    {
        ensureCountAvailable(1);
        C* item = &pLast->Items[pLast->Count];
        ConstructAlt<C>(item, arg);
        pLast->Count++;
        return item;
    }

    void  Clear(bool keepLast = false) { freePages(keepLast); }
    bool  IsEmpty() const              { return !pPages || pPages->Count == 0; }
    Page* GetFirstPage() const         { return pPages; }

private:
    void ensureCountAvailable(unsigned count)
    {
        if (!pLast)
        {
            pLast = pPages = (Page*)SF_HEAP_AUTO_ALLOC(this, sizeof(Page));
            pLast->pNext = 0;
            pLast->Count = 0;
        }
        else if (pLast->Count + count > ItemsPerPage)
        {
            Page* full = pLast;
            pLast = (Page*)SF_HEAP_AUTO_ALLOC(this, sizeof(Page));
            full->pNext  = pLast;
            pLast->pNext = 0;
            pLast->Count = 0;
        }
    }
    // destroys every item; frees each page once the walk has left it, keeping (emptied) the last one on request
    void freePages(bool keepLast)
    {
        Page* p    = pPages;
        Page* prev = 0;
        while (p)
        {
            for (unsigned i = 0; i < p->Count; i++)
                p->Items[i].C::~C();
            if (prev)
                SF_FREE(prev);
            prev = p;
            p    = p->pNext;
        }
        if (prev)
        {
            if (keepLast)
            {
                prev->Count = 0;
            }
            else
            {
                SF_FREE(prev);
                prev = 0;
            }
        }
        pLast = pPages = prev;
    }

    Page* pPages;
    Page* pLast;
};

// One singly linked bucket head per tree depth: 32 heads inline, a heap array (rounded to 32) beyond that.
template<class N>
class DepthUpdateArrayPOD
{
    enum { MaxDepthReserve = 32 };

    N*          pDepth;
    unsigned    DepthUsed;
    unsigned    DepthAvailable;
    MemoryHeap* pHeap;
    N           NullValue;
    N           ArrayReserve[MaxDepthReserve];

    bool grow(unsigned depth)
    {
        unsigned size = (depth + MaxDepthReserve - 1) & ~(MaxDepthReserve - 1);
        N* p = (N*)SF_HEAP_ALLOC(pHeap, size * sizeof(N), Stat_Default_Mem);
        if (!p)
            return false;
        memcpy(p, pDepth, DepthUsed * sizeof(N));
        unsigned rest = size - DepthUsed;
        for (unsigned i = 0; i < rest; i++)
            p[DepthUsed + i] = NullValue;
        if (pDepth != ArrayReserve)
            SF_FREE(pDepth);
        pDepth         = p;
        DepthAvailable = depth;
        return true;
    }

public:
    DepthUpdateArrayPOD(MemoryHeap* heap, N nullValue)
        : pDepth(&ArrayReserve[0]), DepthUsed(0), DepthAvailable(MaxDepthReserve), pHeap(heap), NullValue(nullValue)
    {
        for (unsigned i = 0; i < MaxDepthReserve; i++)
            ArrayReserve[i] = NullValue;
    }
    ~DepthUpdateArrayPOD()
    {
        if (pDepth != ArrayReserve)
            SF_FREE(pDepth);
    }

    unsigned GetDepthUsed() const      { return DepthUsed; }
    N        Get(unsigned index) const { return pDepth[index]; }

    void Set(unsigned index, N node)
    {
        if (index < DepthAvailable || grow(index + 1))
        {
            pDepth[index] = node;
            if (DepthUsed < index + 1)
                DepthUsed = index + 1;
        }
    }
    // pushes val on bucket index: *next receives the old head
    void Link(unsigned index, N* next, N val)
    {
        if (index < DepthAvailable || grow(index + 1))
        {
            *next         = pDepth[index];
            pDepth[index] = val;
            if (DepthUsed < index + 1)
                DepthUsed = index + 1;
        }
    }
    void Clear()
    {
        for (unsigned i = 0; i < DepthUsed; i++)
            pDepth[i] = NullValue;
        DepthUsed = 0;
    }
};

// An array of movable items that keeps up to InternalSize of them in place and moves to a heap block (sized in
// steps of four) once it grows past that. Size comes first; the in-place items share their storage with the heap
// block pointer and its capacity.
template<class C, int InternalSize = 2>
class ArrayReserveLH_Mov
{
    UPInt Size;

    struct HeapBlock
    {
        C*    pData;
        UPInt Reserve;
    };
    union
    {
        HeapBlock Block;
        UByte     Inline[InternalSize * sizeof(C)];
    };

public:
    ArrayReserveLH_Mov() : Size(0) { }
    ~ArrayReserveLH_Mov()
    {
        DestructArray<C>(GetBuffer(), Size);
        if (Size > InternalSize)
            SF_FREE(Block.pData);
    }

    UPInt    GetSize() const   { return Size; }
    C*       GetBuffer()       { return (Size > InternalSize) ? Block.pData : (C*)Inline; }
    const C* GetBuffer() const { return (Size > InternalSize) ? Block.pData : (const C*)Inline; }

    C&       operator[](UPInt i)       { return GetBuffer()[i]; }
    const C& operator[](UPInt i) const { return GetBuffer()[i]; }
};

}} // namespace Scaleform::Render

#endif
