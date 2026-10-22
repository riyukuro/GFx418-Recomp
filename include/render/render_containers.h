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

    // (appended for the mesh cache, sfr_render_07g) growth in steps of four once the inline slots are full; removal
    // moves the items back inline when they fit again
    bool Add(const C& val)
    {
        C* p = insertSpot(Size);
        if (!p)
            return false;
        ConstructAlt<C>(p, val);
        return true;
    }
    bool Add_NoDuplicate(const C& val)
    {
        C* buf = GetBuffer();
        for (UPInt i = 0; i < Size; ++i)
            if (buf[i] == val)
                return false;
        return Add(val);
    }
    void RemoveAt(UPInt index)
    {
        C* buf = GetBuffer();
        Destruct<C>(buf + index);
        memmove(buf + index, buf + index + 1, (Size - index - 1) * sizeof(C));
        --Size;
        if (Size == InternalSize)
        {
            C* heapData = Block.pData;
            memcpy(Inline, heapData, Size * sizeof(C));
            SF_FREE(heapData);
        }
    }
    void Remove(const C& val)
    {
        C* buf = GetBuffer();
        for (UPInt i = 0; i < Size; ++i)
        {
            if (buf[i] == val)
            {
                RemoveAt(i);
                break;
            }
        }
    }

private:
    static UPInt roundReserve(UPInt n) { return (n + 3) & ~UPInt(3); }

    // a new block of reserve items holding the old ones with a hole at index (out of line, e.g. 0x1426dc260)
    C* allocInsertCopy(UPInt index, C* src, UPInt size, UPInt reserve)
    {
        C* data = (C*)SF_HEAP_AUTO_ALLOC(this, reserve * sizeof(C));
        if (data)
        {
            if (index)
                memcpy(data, src, index * sizeof(C));
            if (index < size)
                memcpy(data + index + 1, src + index, (size - index) * sizeof(C));
        }
        return data;
    }
    static void openGap(UPInt index, C* data, UPInt size)
    {
        if (index < size)
            memmove(data + index + 1, data + index, (size - index) * sizeof(C));
    }
    C* insertSpot(UPInt index)
    {
        C* slot;
        if (Size < InternalSize)
        {
            openGap(index, (C*)Inline, Size);
            slot = (C*)Inline + index;
        }
        else if (Size == InternalSize)
        {
            UPInt reserve = roundReserve(Size + 1);
            C*    data    = allocInsertCopy(index, (C*)Inline, Size, reserve);
            if (!data)
                return 0;
            slot          = data + index;
            Block.pData   = data;
            Block.Reserve = reserve;
        }
        else if (Size < Block.Reserve)
        {
            openGap(index, Block.pData, Size);
            slot = Block.pData + index;
        }
        else
        {
            UPInt reserve = roundReserve(Size + 1);
            C*    data    = allocInsertCopy(index, Block.pData, Size, reserve);
            if (!data)
                return 0;
            slot = data + index;
            SF_FREE(Block.pData);
            Block.pData   = data;
            Block.Reserve = reserve;
        }
        ++Size;
        return slot;
    }
};

// (appended for the stroker, sfr_render_05b) a growable array on a LinearHeap: items in pages of 1 << PageSh, the
// page table grows by doubling from PtrPoolInc entries. Old tables and pages are never freed (the heap is reset as
// a whole), so the array cannot be copied.
template<class T, unsigned PageSh, unsigned PtrPoolInc>
class ArrayPaged
{
public:
    enum
    {
        PageShift = PageSh,
        PageSize  = 1 << PageShift,
        PageMask  = PageSize - 1
    };
    typedef T ValueType;

    ArrayPaged(LinearHeap* heap) : pHeap(heap), Size(0), NumPages(0), MaxPages(0), Pages(0) {}

    void  Clear()           { Size = 0; }
    void  ClearAndRelease() { Size = NumPages = MaxPages = 0; Pages = 0; }
    UPInt GetSize() const   { return Size; }

    void PushBack(const T& v)
    {
        *nextSlot() = v;
        ++Size;
    }
    void PopBack()
    {
        if (Size)
            --Size;
    }
    void CutAt(UPInt size)
    {
        if (size < Size)
            Size = size;
    }

    T&       operator[](UPInt i)       { return Pages[i >> PageShift][i & PageMask]; }
    const T& operator[](UPInt i) const { return Pages[i >> PageShift][i & PageMask]; }
    T&       Back()                    { return (*this)[Size - 1]; }
    const T& Back() const              { return (*this)[Size - 1]; }

private:
    ArrayPaged(const ArrayPaged&);
    void operator=(const ArrayPaged&);

    T* nextSlot()
    {
        UPInt page = Size >> PageShift;
        if (page >= NumPages)
            addPage(page);
        return Pages[page] + (Size & PageMask);
    }
    void addPage(UPInt page)
    {
        if (page >= MaxPages)
        {
            if (Pages)
            {
                T** table = (T**)pHeap->Alloc(MaxPages * 2 * sizeof(T*));
                memcpy(table, Pages, NumPages * sizeof(T*));
                Pages = table;
                MaxPages *= 2;
            }
            else
            {
                MaxPages = PtrPoolInc;
                Pages    = (T**)pHeap->Alloc(PtrPoolInc * sizeof(T*));
            }
        }
        Pages[page] = (T*)pHeap->Alloc(PageSize * sizeof(T));
        ++NumPages;
    }

    LinearHeap* pHeap;      // +0x00
    UPInt       Size;       // +0x08
    UPInt       NumPages;   // +0x10
    UPInt       MaxPages;   // +0x18
    T**         Pages;      // +0x20
};

// (appended for the stroker, sfr_render_05b) a plain array on a LinearHeap; growing reallocates, zero-fills and
// keeps the old items
template<class T>
class ArrayUnsafe
{
public:
    typedef T ValueType;

    ArrayUnsafe(LinearHeap* heap) : pHeap(heap), Size(0), Data(0) {}

    void  ClearAndRelease() { Size = 0; Data = 0; }
    UPInt GetSize() const   { return Size; }
    void  Resize(UPInt size)
    {
        if (size > Size)
        {
            T* data = (T*)pHeap->Alloc(size * sizeof(T));
            memset(data, 0, size * sizeof(T));
            if (Data && Size)
                memcpy(data, Data, Size * sizeof(T));
            Data = data;
        }
        Size = size;
    }

    T&       operator[](UPInt i)       { return Data[i]; }
    const T& operator[](UPInt i) const { return Data[i]; }

    // (appended for the tessellator, sfr_render_05c)
    void Zero() { memset(Data, 0, sizeof(T) * Size); }

private:
    ArrayUnsafe(const ArrayUnsafe&);
    void operator=(const ArrayUnsafe&);

    LinearHeap* pHeap;  // +0x00
    UPInt       Size;   // +0x08
    T*          Data;   // +0x10
};

// (appended for the tessellator, sfr_render_05c) a set of paged arrays on one LinearHeap (one triangle list per
// mesh). Each array keeps its own page table; Split cuts an array at a page boundary into two.
template<class T, unsigned PageSh, unsigned PtrPoolInc>
class ArrayJagged
{
    struct ArrayType
    {
        UPInt Size;
        UPInt NumPages;
        UPInt MaxPages;
        T**   Pages;
    };

public:
    enum
    {
        ArrayInc  = 16,
        PageShift = PageSh,
        PageSize  = 1 << PageShift,
        PageMask  = PageSize - 1
    };
    typedef T ValueType;

    // one of the arrays seen as a plain indexable array (for the sorts)
    class ArrayAdaptor
    {
    public:
        typedef T ValueType;

        ArrayAdaptor(UPInt size, T** pages) : Size(size), Pages(pages) {}
        UPInt    GetSize() const               { return Size; }
        T&       operator[](UPInt i)           { return Pages[i >> PageShift][i & PageMask]; }
        const T& operator[](UPInt i) const     { return Pages[i >> PageShift][i & PageMask]; }

    private:
        UPInt Size;
        T**   Pages;
    };

    ArrayJagged(LinearHeap* heap) : pHeap(heap), Arrays(0), NumArrays(0), MaxArrays(0) {}

    void ClearAndRelease()
    {
        Arrays    = 0;
        NumArrays = MaxArrays = 0;
    }

    void AddArray()
    {
        if (NumArrays >= MaxArrays)
        {
            if (NumArrays)
            {
                ArrayType* arrays = (ArrayType*)pHeap->Alloc(MaxArrays * 2 * sizeof(ArrayType));
                memcpy(arrays, Arrays, NumArrays * sizeof(ArrayType));
                Arrays = arrays;
                MaxArrays *= 2;
            }
            else
                Arrays = (ArrayType*)pHeap->Alloc((MaxArrays = ArrayInc) * sizeof(ArrayType));
        }
        memset(&Arrays[NumArrays], 0, sizeof(ArrayType));
        ++NumArrays;
    }

    ArrayAdaptor GetArrayAdaptor(UPInt i) { return ArrayAdaptor(Arrays[i].Size, Arrays[i].Pages); }
    UPInt        GetArrayCount() const    { return NumArrays; }
    UPInt        GetSize(UPInt i) const   { return Arrays[i].Size; }

    void PushBack(UPInt i, const T& v)
    {
        *nextSlot(i) = v;
        ++Arrays[i].Size;
    }
    void PopBack(UPInt i)
    {
        if (Arrays[i].Size)
            --Arrays[i].Size;
    }
    void CutAt(UPInt i, UPInt size)
    {
        if (size < Arrays[i].Size)
            Arrays[i].Size = size;
    }

    T&       At(UPInt i, UPInt j)         { return Arrays[i].Pages[j >> PageShift][j & PageMask]; }
    const T& At(UPInt i, UPInt j) const   { return Arrays[i].Pages[j >> PageShift][j & PageMask]; }
    T&       Back(UPInt i)                { return At(i, Arrays[i].Size - 1); }
    const T& Back(UPInt i) const          { return At(i, Arrays[i].Size - 1); }
    UPInt    GetPageCount(UPInt i) const  { return Arrays[i].NumPages; }
    const T* GetPage(UPInt i, UPInt j) const { return Arrays[i].Pages[j]; }

    // moves the items of array i from the page holding item at on into a new array; false when at is past the end
    bool Split(UPInt i, UPInt at)
    {
        if (at >= GetSize(i))
            return false;
        UPInt keepSize   = at & ~UPInt(PageMask);
        UPInt restSize   = GetSize(i) - keepSize;
        UPInt keepPages  = at >> PageShift;
        UPInt restPages  = Arrays[i].NumPages - keepPages;
        UPInt restMax    = Arrays[i].MaxPages - keepPages;
        T**   restTable  = Arrays[i].Pages + keepPages;
        AddArray();
        Arrays[i].NumPages = keepPages;
        Arrays[i].MaxPages = keepPages;
        Arrays[i].Size     = keepSize;
        i                  = NumArrays - 1;
        Arrays[i].NumPages = restPages;
        Arrays[i].MaxPages = restMax;
        Arrays[i].Size     = restSize;
        Arrays[i].Pages    = restTable;
        return true;
    }

private:
    ArrayJagged(const ArrayJagged&);
    const ArrayJagged& operator=(const ArrayJagged&);

    void addPage(ArrayType* a, UPInt page)
    {
        if (page >= a->MaxPages)
        {
            if (a->Pages)
            {
                T** table = (T**)pHeap->Alloc(a->MaxPages * 2 * sizeof(T*));
                memcpy(table, a->Pages, a->NumPages * sizeof(T*));
                a->Pages = table;
                a->MaxPages *= 2;
            }
            else
                a->Pages = (T**)pHeap->Alloc((a->MaxPages = PtrPoolInc) * sizeof(T*));
        }
        a->Pages[page] = (T*)pHeap->Alloc(PageSize * sizeof(T));
        a->NumPages++;
    }
    T* nextSlot(UPInt i)
    {
        ArrayType* a    = &Arrays[i];
        UPInt      page = a->Size >> PageShift;
        if (page >= a->NumPages)
            addPage(a, page);
        return a->Pages[page] + (a->Size & PageMask);
    }

    LinearHeap* pHeap;      // +0x00
    ArrayType*  Arrays;     // +0x08
    UPInt       NumArrays;  // +0x10
    UPInt       MaxArrays;  // +0x18
};

// (appended for the tessellator, sfr_render_05c) a square table on a LinearHeap; Resize drops the old contents and
// fills the new table with 0xFF bytes
template<class T>
class ArrayMatrix
{
public:
    typedef T ValueType;

    ArrayMatrix(LinearHeap* heap) : pHeap(heap), Size(0), Array(0) {}

    void ClearAndRelease()
    {
        Size  = 0;
        Array = 0;
    }
    void Resize(UPInt size)
    {
        Size  = size;
        Array = (T*)pHeap->Alloc(size * size * sizeof(T));
        memset(Array, 0xFF, size * size * sizeof(T));
    }

    T&       At(UPInt i, UPInt j)       { return Array[i * Size + j]; }
    const T& At(UPInt i, UPInt j) const { return Array[i * Size + j]; }
    T        ValueAt(UPInt i, UPInt j) const { return Array[i * Size + j]; }

private:
    LinearHeap* pHeap;  // +0x00
    UPInt       Size;   // +0x08
    T*          Array;  // +0x10
};

}} // namespace Scaleform::Render

#endif
