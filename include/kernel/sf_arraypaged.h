// Recovered Scaleform 4.1.18 kernel: paged arrays (items in pages of 1 << PageSh, a page table that grows by
// PtrPoolInc entries; pages stay put, so element addresses are stable). Shared header of the src/ms2/scaleform units
// (sfr lane): append, do not reorder.
//
// Layout: { allocator (empty bases, 8 bytes); +0x08 Size; +0x10 NumPages; +0x18 MaxPages; +0x20 T** Pages } 0x28
// bytes, as the AS3 collector's root buffer (ArrayPagedLH_POD<const RefCountBaseGC*, 10, 5> at +0x10) has it.
#ifndef MS2_SF_KERNEL_ARRAYPAGED_H
#define MS2_SF_KERNEL_ARRAYPAGED_H

#include "sf_allocator.h"

namespace Scaleform {

// Element construction over a page table: nothing for POD items, placement new / destructor calls otherwise.
template<class T>
class ConstructorPagedPOD : public ConstructorPOD<T>
{
public:
    static void ConstructArrayPaged(T**, UPInt, UPInt, UPInt, UPInt) {}
    static void DestructArrayPaged(T**, UPInt, UPInt, UPInt, UPInt) {}
};

template<class T>
class ConstructorPagedMov : public ConstructorMov<T>
{
public:
    static void ConstructArrayPaged(T** pages, UPInt start, UPInt end, UPInt pageShift, UPInt pageMask)
    {
        for (UPInt i = start; i < end; ++i)
            ConstructorMov<T>::Construct(pages[i >> pageShift] + (i & pageMask));
    }
    // Back to front.
    static void DestructArrayPaged(T** pages, UPInt start, UPInt end, UPInt pageShift, UPInt pageMask)
    {
        for (UPInt i = end; i > start; --i)
            ConstructorMov<T>::Destruct(pages[(i - 1) >> pageShift] + ((i - 1) & pageMask));
    }
};

template<class T, int SID> struct AllocatorPagedGH_POD : AllocatorBaseGH<SID>, ConstructorPagedPOD<T> {};
template<class T, int SID> struct AllocatorPagedGH     : AllocatorBaseGH<SID>, ConstructorPagedMov<T> {};
template<class T, int SID> struct AllocatorPagedLH_POD : AllocatorBaseLH<SID>, ConstructorPagedPOD<T> {};
template<class T, int SID> struct AllocatorPagedLH     : AllocatorBaseLH<SID>, ConstructorPagedMov<T> {};

template<class T, int PageSh, int PtrPoolInc, class Allocator>
class ArrayPagedBase : public Allocator
{
public:
    enum PageConsts
    {
        PageShift = PageSh,
        PageSize  = 1 << PageShift,
        PageMask  = PageSize - 1
    };
    typedef ArrayPagedBase<T, PageSh, PtrPoolInc, Allocator> SelfType;
    typedef T         ValueType;
    typedef Allocator AllocatorType;

    ArrayPagedBase() : Size(0), NumPages(0), MaxPages(0), Pages(0) {}
    ~ArrayPagedBase() { ClearAndRelease(); }

    // Destroys the items and frees every page and the page table, last page first.
    void ClearAndRelease()
    {
        if (NumPages)
        {
            T**         page     = Pages + NumPages - 1;
            const UPInt fullPages = (Size > 0) ? (Size >> PageShift) : 0;
            while (NumPages--)
            {
                const UPInt used = (NumPages < fullPages) ? PageSize : ((NumPages == fullPages) ? (Size & PageMask) : 0);
                Allocator::DestructArray(*page, used);
                Allocator::Free(*page);
                --page;
            }
            Allocator::Free(Pages);
        }
        Size = NumPages = MaxPages = 0;
        Pages = 0;
    }
    void Clear()
    {
        Allocator::DestructArrayPaged(Pages, 0, Size, PageShift, PageMask);
        Size = 0;
    }

    void PushBack(const T& val)
    {
        Allocator::Construct(acquireDataPtr(), val);
        ++Size;
    }
    // False when a page could not be allocated.
    bool PushBackSafe(const T& val)
    {
        T* p = acquireDataPtrSafe();
        if (!p)
            return false;
        Allocator::Construct(p, val);
        ++Size;
        return true;
    }
    void PopBack()
    {
        if (Size)
        {
            Allocator::Destruct(&At(Size - 1));
            --Size;
        }
    }

    UPInt GetCapacity() const { return NumPages << PageShift; }
    void Reserve(UPInt newCapacity)
    {
        if (newCapacity > GetCapacity())
        {
            UPInt pages = (newCapacity + PageMask) >> PageShift;
            for (UPInt i = NumPages; i < pages; ++i)
                allocatePage(i);
        }
    }
    // Grows by whole pages (constructing the new items) or destroys the cut items; pages are kept.
    void Resize(UPInt newSize)
    {
        if (newSize > Size)
        {
            UPInt pages = (newSize + PageMask) >> PageShift;
            for (UPInt i = NumPages; i < pages; ++i)
                allocatePage(i);
            Allocator::ConstructArrayPaged(Pages, Size, newSize, PageShift, PageMask);
            Size = newSize;
            return;
        }
        if (newSize < Size)
        {
            Allocator::DestructArrayPaged(Pages, newSize, Size, PageShift, PageMask);
            Size = newSize;
        }
    }

    // (appended for sfr_render_06d) drops the items from n on, pages are kept
    void CutAt(UPInt n)
    {
        if (n < Size)
        {
            Allocator::DestructArrayPaged(Pages, n, Size, PageShift, PageMask);
            Size = n;
        }
    }

    UPInt    GetSize() const               { return Size; }
    const T& operator[](UPInt i) const     { return Pages[i >> PageShift][i & PageMask]; }
    T&       operator[](UPInt i)           { return Pages[i >> PageShift][i & PageMask]; }
    const T& At(UPInt i) const             { return Pages[i >> PageShift][i & PageMask]; }
    T&       At(UPInt i)                   { return Pages[i >> PageShift][i & PageMask]; }
    T        ValueAt(UPInt i) const        { return Pages[i >> PageShift][i & PageMask]; }
    const T& Front() const                 { return Pages[0][0]; }
    T&       Front()                       { return Pages[0][0]; }
    const T& Back() const                  { return At(Size - 1); }
    T&       Back()                        { return At(Size - 1); }

private:
    ArrayPagedBase(const SelfType&);
    const SelfType& operator=(const SelfType&);

    // Page nb (the page table grows by PtrPoolInc entries when full).
    void allocatePage(UPInt nb)
    {
        if (nb >= MaxPages)
        {
            if (Pages)
                Pages = (T**)Allocator::Realloc(Pages, (MaxPages + PtrPoolInc) * sizeof(T*), __FILE__, __LINE__);
            else
                Pages = (T**)Allocator::Alloc(this, PtrPoolInc * sizeof(T*), __FILE__, __LINE__);
            MaxPages += PtrPoolInc;
        }
        Pages[nb] = (T*)Allocator::Alloc(this, PageSize * sizeof(T), __FILE__, __LINE__);
        NumPages++;
    }
    SF_INLINE T* acquireDataPtr()
    {
        UPInt np = Size >> PageShift;
        if (np >= NumPages)
            allocatePage(np);
        return Pages[np] + (Size & PageMask);
    }
    bool allocatePageSafe(UPInt nb)
    {
        if (nb >= MaxPages)
        {
            T** table;
            if (Pages)
                table = (T**)Allocator::Realloc(Pages, (MaxPages + PtrPoolInc) * sizeof(T*), __FILE__, __LINE__);
            else
                table = (T**)Allocator::Alloc(this, PtrPoolInc * sizeof(T*), __FILE__, __LINE__);
            if (!table)
                return false;
            Pages = table;
            MaxPages += PtrPoolInc;
        }
        Pages[nb] = (T*)Allocator::Alloc(this, PageSize * sizeof(T), __FILE__, __LINE__);
        if (!Pages[nb])
            return false;
        NumPages++;
        return true;
    }
    SF_INLINE T* acquireDataPtrSafe()
    {
        UPInt np = Size >> PageShift;
        if (np >= NumPages)
        {
            if (!allocatePageSafe(np))
                return NULL;
        }
        return Pages[np] + (Size & PageMask);
    }

    UPInt Size;
    UPInt NumPages;
    UPInt MaxPages;
    T**   Pages;
};

template<class T, int PageSh = 6, int PtrPoolInc = 64, int SID = Stat_Default_Mem>
class ArrayPagedPOD : public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedGH_POD<T, SID> >
{
};
template<class T, int PageSh = 6, int PtrPoolInc = 64, int SID = Stat_Default_Mem>
class ArrayPaged : public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedGH<T, SID> >
{
};
template<class T, int PageSh = 6, int PtrPoolInc = 64, int SID = Stat_Default_Mem>
class ArrayPagedLH_POD : public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedLH_POD<T, SID> >
{
};
template<class T, int PageSh = 6, int PtrPoolInc = 64, int SID = Stat_Default_Mem>
class ArrayPagedLH : public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedLH<T, SID> >
{
};

} // namespace Scaleform

#endif
