// Recovered Scaleform GFx 4.1.18: ListAlloc, a paged free-list allocator of fixed size elements. Pages of PageSize
// elements are chained through a pointer after the elements; freed elements are linked through their first word
// and reused first. Pages are only released by ClearAndRelease / the destructor.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_LISTALLOC_H
#define MS2_SF_KERNEL_LISTALLOC_H

#include "ms2/scaleform/kernel/sf_allocator.h"

namespace Scaleform {

template<class T, int PageSize, class Allocator>
class ListAllocBase
{
public:
    typedef T                                     ValueType;
    typedef Allocator                             AllocatorType;
    typedef ListAllocBase<T, PageSize, Allocator> SelfType;

private:
    struct PageType
    {
        ValueType Data[PageSize];
        PageType* pNext;
    };
    struct NodeType
    {
        NodeType* pNext;
    };

protected:
    ListAllocBase(void* heap)
        : FirstPage(0), LastPage(0), NumElementsInPage(PageSize), FirstEmptySlot(0), pHeapOrPtr(heap) { }

public:
    ListAllocBase()
        : FirstPage(0), LastPage(0), NumElementsInPage(PageSize), FirstEmptySlot(0) { pHeapOrPtr = this; }
    ~ListAllocBase() { freeMem(); }

    void ClearAndRelease()
    {
        freeMem();
        FirstPage         = 0;
        LastPage          = 0;
        NumElementsInPage = PageSize;
        FirstEmptySlot    = 0;
    }

    UPInt GetNumBytes() const
    {
        UPInt n = 0;
        for (const PageType* p = FirstPage; p; p = p->pNext)
            n += sizeof(PageType);
        return n;
    }

    T* Alloc()
    {
        T* p = allocate();
        Allocator::Construct(p);
        return p;
    }
    T* Alloc(const T& v)
    {
        T* p = allocate();
        Allocator::Construct(p, v);
        return p;
    }
    template<class S>
    T* AllocAlt(const S& v)
    {
        T* p = allocate();
        Allocator::ConstructAlt(p, v);
        return p;
    }

    void Free(T* p)
    {
        Allocator::Destruct(p);
        ((NodeType*)p)->pNext = FirstEmptySlot;
        FirstEmptySlot        = (NodeType*)p;
    }

private:
    ListAllocBase(const SelfType&);
    const SelfType& operator=(SelfType&);

    T* allocate()
    {
        if (FirstEmptySlot)
        {
            T* p           = (T*)FirstEmptySlot;
            FirstEmptySlot = FirstEmptySlot->pNext;
            return p;
        }
        if (NumElementsInPage < PageSize)
            return &LastPage->Data[NumElementsInPage++];

        PageType* page = (PageType*)Allocator::Alloc(pHeapOrPtr, sizeof(PageType), __FILE__, __LINE__);
        page->pNext    = 0;
        if (LastPage)
            LastPage->pNext = page;
        else
            FirstPage = page;
        LastPage          = page;
        NumElementsInPage = 1;
        return &LastPage->Data[0];
    }

    void freeMem()
    {
        PageType* page = FirstPage;
        while (page)
        {
            PageType* next = page->pNext;
            Allocator::Free(page);
            page = next;
        }
    }

    PageType* FirstPage;          // +0x00
    PageType* LastPage;
    unsigned  NumElementsInPage;  // +0x10
    NodeType* FirstEmptySlot;     // +0x18
    void*     pHeapOrPtr;         // +0x20 (0x28 bytes)
};

template<class T, int PageSize = 127, int SID = Stat_Default_Mem>
class ListAllocPOD : public ListAllocBase<T, PageSize, AllocatorGH_POD<T, SID> > { };

template<class T, int PageSize = 127, int SID = Stat_Default_Mem>
class ListAlloc : public ListAllocBase<T, PageSize, AllocatorGH<T, SID> > { };

template<class T, int PageSize = 127, int SID = Stat_Default_Mem>
class ListAllocLH_POD : public ListAllocBase<T, PageSize, AllocatorLH_POD<T, SID> > { };

template<class T, int PageSize = 127, int SID = Stat_Default_Mem>
class ListAllocLH : public ListAllocBase<T, PageSize, AllocatorLH<T, SID> > { };

} // namespace Scaleform

#endif
