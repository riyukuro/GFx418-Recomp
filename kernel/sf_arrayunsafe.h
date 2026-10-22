// Recovered Scaleform GFx 4.1.18: ArrayUnsafe, a heap array without growth checks. Reserve / Resize throw the old
// contents away (the capacity only ever grows, so the data address stays put while the size fits); PushBack does no
// bounds check. Used where the element count is known up front (the image resizer's coordinate tables).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_ARRAYUNSAFE_H
#define MS2_SF_KERNEL_ARRAYUNSAFE_H

#include "ms2/scaleform/kernel/sf_allocator.h"

#include <string.h>

namespace Scaleform {

template<class T, class Allocator>
class ArrayUnsafeBase
{
public:
    typedef ArrayUnsafeBase<T, Allocator> SelfType;
    typedef T                             ValueType;
    typedef Allocator                     AllocatorType;

    ArrayUnsafeBase() : Data(0), Size(0), Capacity(0) {}
    ~ArrayUnsafeBase()
    {
        Allocator::DestructArray(Data, Size);
        Allocator::Free(Data);
    }

    void Clear()
    {
        Allocator::DestructArray(Data, Size);
        Size = 0;
    }
    void ClearAndRelease()
    {
        Allocator::DestructArray(Data, Size);
        Allocator::Free(Data);
        Data     = 0;
        Size     = 0;
        Capacity = 0;
    }

    // drops the contents; reallocates only to grow
    void Reserve(UPInt cap, UPInt extraTail = 0)
    {
        Allocator::DestructArray(Data, Size);
        if (cap > Capacity)
        {
            Allocator::Free(Data);
            Capacity = cap + extraTail;
            Data     = Capacity ? (T*)Allocator::Alloc(this, Capacity * sizeof(T), __FILE__, __LINE__) : 0;
        }
        Size = 0;
    }
    // drops the contents and makes size default constructed elements
    void Resize(UPInt size, UPInt extraTail = 0)
    {
        Reserve(size, extraTail);
        Size = size;
        Allocator::ConstructArray(Data, size);
    }
    void Zero() { memset(Data, 0, sizeof(T) * Size); }

    void PushBack(const T& v) { Allocator::Construct(&Data[Size++], v); }

    UPInt GetSize() const     { return Size; }
    UPInt GetCapacity() const { return Capacity; }
    UPInt GetNumBytes() const { return Capacity * sizeof(T); }

    const T& operator[](UPInt i) const { return Data[i]; }
    T&       operator[](UPInt i)       { return Data[i]; }
    const T& At(UPInt i) const         { return Data[i]; }
    T&       At(UPInt i)               { return Data[i]; }
    const T* GetDataPtr() const        { return Data; }
    T*       GetDataPtr()              { return Data; }

private:
    ArrayUnsafeBase(const SelfType&);
    void operator=(const SelfType&);

    T*    Data;
    UPInt Size;
    UPInt Capacity;
};

template<class T, int SID = Stat_Default_Mem>
class ArrayUnsafe : public ArrayUnsafeBase<T, AllocatorGH<T, SID> >
{
public:
    ArrayUnsafe() {}
};

template<class T, int SID = Stat_Default_Mem>
class ArrayUnsafePOD : public ArrayUnsafeBase<T, AllocatorGH_POD<T, SID> >
{
public:
    ArrayUnsafePOD() {}
};

template<class T, int SID = Stat_Default_Mem>
class ArrayUnsafeLH : public ArrayUnsafeBase<T, AllocatorLH<T, SID> >
{
public:
    ArrayUnsafeLH() {}
};

template<class T, int SID = Stat_Default_Mem>
class ArrayUnsafeLH_POD : public ArrayUnsafeBase<T, AllocatorLH_POD<T, SID> >
{
public:
    ArrayUnsafeLH_POD() {}
};

} // namespace Scaleform

#endif
