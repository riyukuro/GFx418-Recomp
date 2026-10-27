// Recovered Scaleform 4.1.18 kernel: dynamic arrays.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout: ArrayDataBase { T* Data; UPInt Size; SizePolicy Policy (UPInt Capacity) } = 0x18 bytes. Capacity grows in
// steps of the policy granularity (4); ResizeNoConstruct grows to n + n/4 and shrinks when below half the capacity.
#ifndef MS2_SF_KERNEL_ARRAY_H
#define MS2_SF_KERNEL_ARRAY_H

#include "sf_allocator.h"

// Allocation site handed to the allocators: the exe's build path of this header and the line. The /Od game units pass
// it on; the /Ob2 library units inline the allocator, which ignores it.
#define MS2_SF_ARRAY_SITE "e:\\build\\kr\\22_04\\gamebryo\\integrations\\scaleform\\gfx sdk 4.0\\src\\kernel\\sf_array.h"

namespace Scaleform {

struct ArrayDefaultPolicy
{
    ArrayDefaultPolicy() : Capacity(0) {}
    ArrayDefaultPolicy(const ArrayDefaultPolicy&) : Capacity(0) {}

    UPInt GetMinCapacity() const { return 0; }
    UPInt GetGranularity() const { return 4; }
    bool  NeverShrinking() const { return 0; }

    UPInt GetCapacity() const         { return Capacity; }
    void  SetCapacity(UPInt capacity) { Capacity = capacity; }
private:
    UPInt Capacity;
};

template<int MinCapacity = 0, int Granularity = 4, bool NeverShrink = false>
struct ArrayConstPolicy
{
    typedef ArrayConstPolicy<MinCapacity, Granularity, NeverShrink> SelfType;

    ArrayConstPolicy() : Capacity(0) {}
    ArrayConstPolicy(const SelfType&) : Capacity(0) {}

    UPInt GetMinCapacity() const { return MinCapacity; }
    UPInt GetGranularity() const { return Granularity; }
    bool  NeverShrinking() const { return NeverShrink; }

    UPInt GetCapacity() const         { return Capacity; }
    void  SetCapacity(UPInt capacity) { Capacity = capacity; }
private:
    UPInt Capacity;
};

template<class T, class Allocator, class SizePolicy>
struct ArrayDataBase
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> SelfType;

    ArrayDataBase() : Data(0), Size(0), Policy() {}
    ArrayDataBase(const SizePolicy& p) : Data(0), Size(0), Policy(p) {}
    ~ArrayDataBase()
    {
        Allocator::DestructArray(Data, Size);
        Allocator::Free(Data);
    }

    UPInt GetCapacity() const { return Policy.GetCapacity(); }

    void ClearAndRelease()
    {
        Allocator::DestructArray(Data, Size);
        Allocator::Free(Data);
        Data = 0;
        Size = 0;
        Policy.SetCapacity(0);
    }

    void Reserve(const void* pheapAddr, UPInt newCapacity)
    {
        if (Policy.NeverShrinking() && newCapacity < GetCapacity())
            return;
        if (newCapacity < Policy.GetMinCapacity())
            newCapacity = Policy.GetMinCapacity();

        if (newCapacity == 0)
        {
            if (Data)
            {
                Allocator::Free(Data);
                Data = 0;
            }
            Policy.SetCapacity(0);
            return;
        }

        UPInt gran = Policy.GetGranularity();
        newCapacity = (newCapacity + gran - 1) / gran * gran;
        if (Data)
        {
            if (Allocator::IsMovable())
            {
                Data = (T*)Allocator::Realloc(Data, sizeof(T) * newCapacity, MS2_SF_ARRAY_SITE, 137);
            }
            else
            {
                // Element-wise move into a fresh block.
                T* newData = (T*)Allocator::Alloc(pheapAddr, sizeof(T) * newCapacity, MS2_SF_ARRAY_SITE, 142);
                UPInt i, s = (Size < newCapacity) ? Size : newCapacity;
                for (i = 0; i < s; ++i)
                {
                    Allocator::Construct(&newData[i], Data[i]);
                    Allocator::Destruct(&Data[i]);
                }
                for (i = s; i < Size; ++i)
                    Allocator::Destruct(&Data[i]);
                Allocator::Free(Data);
                Data = newData;
            }
        }
        else
        {
            Data = (T*)Allocator::Alloc(pheapAddr, sizeof(T) * newCapacity, MS2_SF_ARRAY_SITE, 161);
        }
        Policy.SetCapacity(newCapacity);
    }

    void ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
    {
        UPInt oldSize = Size;
        if (newSize < oldSize)
        {
            Allocator::DestructArray(Data + newSize, oldSize - newSize);
            if (newSize < (Policy.GetCapacity() >> 1))
                Reserve(pheapAddr, newSize);
        }
        else if (newSize >= Policy.GetCapacity())
        {
            Reserve(pheapAddr, newSize + (newSize >> 2));
        }
        Size = newSize;
    }

    ValueType* Data;
    UPInt      Size;
    SizePolicy Policy;
};

// Heap = the array's own address (LH) or the global heap (GH).
template<class T, class Allocator, class SizePolicy>
struct ArrayData : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayData<T, Allocator, SizePolicy>     SelfType;

    ArrayData() : BaseType() {}
    ArrayData(int size) : BaseType() { Resize(size); }
    ArrayData(const SelfType& a) : BaseType(a.Policy) { Append(a.Data, a.Size); }

    void Reserve(UPInt newCapacity) { BaseType::Reserve(this, newCapacity); }

    void Resize(UPInt newSize)
    {
        UPInt oldSize = this->Size;
        BaseType::ResizeNoConstruct(this, newSize);
        if (newSize > oldSize)
            Allocator::ConstructArray(this->Data + oldSize, newSize - oldSize);
    }

    void PushBack(const ValueType& val)
    {
        BaseType::ResizeNoConstruct(this, this->Size + 1);
        Allocator::Construct(this->Data + this->Size - 1, val);
    }

    template<class S>
    void PushBackAlt(const S& val)
    {
        BaseType::ResizeNoConstruct(this, this->Size + 1);
        Allocator::ConstructAlt(this->Data + this->Size - 1, val);
    }

    void Append(const ValueType other[], UPInt count)
    {
        if (count)
        {
            UPInt oldSize = this->Size;
            BaseType::ResizeNoConstruct(this, this->Size + count);
            Allocator::ConstructArray(this->Data + oldSize, count, other);
        }
    }
};

// Heap given explicitly at construction.
template<class T, class Allocator, class SizePolicy>
struct ArrayDataDH : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayDataDH<T, Allocator, SizePolicy>   SelfType;

    ArrayDataDH(MemoryHeap* heap) : BaseType(), pHeap(heap) {}
    ArrayDataDH(MemoryHeap* heap, int size) : BaseType(), pHeap(heap) { Resize(size); }
    ArrayDataDH(const SelfType& a) : BaseType(a.Policy), pHeap(a.pHeap) { Append(a.Data, a.Size); }

    void Reserve(UPInt newCapacity) { BaseType::Reserve(pHeap, newCapacity); }

    void Resize(UPInt newSize)
    {
        UPInt oldSize = this->Size;
        BaseType::ResizeNoConstruct(pHeap, newSize);
        if (newSize > oldSize)
            Allocator::ConstructArray(this->Data + oldSize, newSize - oldSize);
    }

    void PushBack(const ValueType& val)
    {
        BaseType::ResizeNoConstruct(pHeap, this->Size + 1);
        Allocator::Construct(this->Data + this->Size - 1, val);
    }

    template<class S>
    void PushBackAlt(const S& val)
    {
        BaseType::ResizeNoConstruct(pHeap, this->Size + 1);
        Allocator::ConstructAlt(this->Data + this->Size - 1, val);
    }

    void Append(const ValueType other[], UPInt count)
    {
        if (count > 0)
        {
            UPInt oldSize = this->Size;
            BaseType::ResizeNoConstruct(pHeap, this->Size + count);
            Allocator::ConstructArray(this->Data + oldSize, count, other);
        }
    }

    const MemoryHeap* pHeap;
};

// (appended for sfr_as2_02) Grows with copies of a default value; heap = the array's own address.
template<class T, class Allocator, class SizePolicy>
struct ArrayDataCC : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayDataCC<T, Allocator, SizePolicy>   SelfType;

    ArrayDataCC(const ValueType& defval) : BaseType(), DefaultValue(defval) {}
    ArrayDataCC(const ValueType& defval, int size) : BaseType(), DefaultValue(defval) { Resize(size); }
    ArrayDataCC(const SelfType& a) : BaseType(a.Policy), DefaultValue(a.DefaultValue) { Append(a.Data, a.Size); }

    void Reserve(UPInt newCapacity) { BaseType::Reserve(this, newCapacity); }

    void Resize(UPInt newSize)
    {
        UPInt oldSize = this->Size;
        BaseType::ResizeNoConstruct(this, newSize);
        if (newSize > oldSize)
            Allocator::ConstructArray(this->Data + oldSize, newSize - oldSize, DefaultValue);
    }

    void PushBack(const ValueType& val)
    {
        BaseType::ResizeNoConstruct(this, this->Size + 1);
        Allocator::Construct(this->Data + this->Size - 1, val);
    }

    void Append(const ValueType other[], UPInt count)
    {
        if (count)
        {
            UPInt oldSize = this->Size;
            BaseType::ResizeNoConstruct(this, this->Size + count);
            Allocator::ConstructArray(this->Data + oldSize, count, other);
        }
    }

    ValueType DefaultValue;
};

template<class ArrayData>
class ArrayBase
{
public:
    typedef typename ArrayData::ValueType      ValueType;
    typedef typename ArrayData::AllocatorType  AllocatorType;
    typedef typename ArrayData::SizePolicyType SizePolicyType;
    typedef ArrayBase<ArrayData>               SelfType;

    SF_MEMORY_REDEFINE_NEW(ArrayBase, AllocatorType::StatId)

    ArrayBase() : Data() {}
    ArrayBase(int size) : Data(size) {}
    ArrayBase(const SelfType& a) : Data(a.Data) {}
    ArrayBase(MemoryHeap* heap) : Data(heap) {}
    ArrayBase(MemoryHeap* heap, int size) : Data(heap, size) {}
    ArrayBase(const ValueType& defval) : Data(defval) {}
    ArrayBase(const ValueType& defval, int size) : Data(defval, size) {}

    SizePolicyType* GetSizePolicy() const                  { return Data.Policy; }
    void            SetSizePolicy(const SizePolicyType& p) { Data.Policy = p; }

    bool  NeverShrinking() const { return Data.Policy.NeverShrinking(); }
    UPInt GetSize() const        { return Data.Size; }
    bool  IsEmpty() const        { return Data.Size == 0; }
    UPInt GetCapacity() const    { return Data.GetCapacity(); }
    UPInt GetNumBytes() const    { return Data.GetCapacity() * sizeof(ValueType); }

    void ClearAndRelease()         { Data.ClearAndRelease(); }
    void Clear()                   { Data.Resize(0); }
    void Resize(UPInt newSize)     { Data.Resize(newSize); }
    void Reserve(UPInt newCapacity)
    {
        if (newCapacity > Data.GetCapacity())
            Data.Reserve(newCapacity);
    }

    ValueType&       At(UPInt index)                 { return Data.Data[index]; }
    const ValueType& At(UPInt index) const           { return Data.Data[index]; }
    ValueType        ValueAt(UPInt index) const      { return Data.Data[index]; }
    ValueType&       operator[](UPInt index)         { return Data.Data[index]; }
    const ValueType& operator[](UPInt index) const   { return Data.Data[index]; }

    const ValueType* GetDataPtr() const { return Data.Data; }
    ValueType*       GetDataPtr()       { return Data.Data; }

    void PushBack(const ValueType& val) { Data.PushBack(val); }
    template<class S>
    void PushBackAlt(const S& val)      { Data.PushBackAlt(val); }
    void PopBack(UPInt count = 1)       { Data.Resize(Data.Size - count); }

    ValueType& PushDefault()
    {
        Data.PushBack(ValueType());
        return Back();
    }
    ValueType Pop()
    {
        ValueType t = Back();
        PopBack();
        return t;
    }

    ValueType&       Front()       { return At(0); }
    const ValueType& Front() const { return At(0); }
    ValueType&       Back()        { return At(Data.Size - 1); }
    const ValueType& Back() const  { return At(Data.Size - 1); }

    const SelfType& operator=(const SelfType& a)
    {
        Resize(a.GetSize());
        for (UPInt i = 0; i < Data.Size; i++)
            *(Data.Data + i) = a[i];
        return *this;
    }

    void RemoveMultipleAt(UPInt index, UPInt num)
    {
        if (Data.Size == num)
        {
            Clear();
        }
        else
        {
            AllocatorType::DestructArray(Data.Data + index, num);
            AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + num, Data.Size - num - index);
            Data.Size -= num;
        }
    }
    // (appended, sfr19) RemoveMultipleAt, always inlined: the AS3 Vector.splice bodies (sfr_as3_20) inline it
    // where the compiler's heuristics alone do not.
    __forceinline void RemoveMultipleAtInline(UPInt index, UPInt num)
    {
        if (Data.Size == num)
        {
            Clear();
        }
        else
        {
            AllocatorType::DestructArray(Data.Data + index, num);
            AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + num, Data.Size - num - index);
            Data.Size -= num;
        }
    }

    void RemoveAt(UPInt index)
    {
        if (Data.Size == 1)
        {
            Clear();
        }
        else
        {
            AllocatorType::Destruct(Data.Data + index);
            AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
            --Data.Size;
        }
    }

    void InsertAt(UPInt index, const ValueType& val = ValueType())
    {
        Data.Resize(Data.Size + 1);
        if (index < Data.Size - 1)
            AllocatorType::CopyArrayBackward(Data.Data + index + 1, Data.Data + index, Data.Size - 1 - index);
        AllocatorType::Construct(Data.Data + index, val);
    }

    void InsertMultipleAt(UPInt index, UPInt num, const ValueType& val = ValueType())
    {
        Data.Resize(Data.Size + num);
        if (index < Data.Size - num)
            AllocatorType::CopyArrayBackward(Data.Data + index + num, Data.Data + index, Data.Size - num - index);
        for (UPInt i = 0; i < num; ++i)
            AllocatorType::Construct(Data.Data + index + i, val);
    }

    void Append(const SelfType& other)                { Append(other.Data.Data, other.GetSize()); }
    void Append(const ValueType other[], UPInt count) { Data.Append(other, count); }

    // (appended, sfr33) the index iterators, as kernel/sf_array.h has them (text_styledtext.h needs them)
    class Iterator
    {
        SelfType* pArray;
        SPInt     CurIndex;
    public:
        Iterator() : pArray(0), CurIndex(-1) { }
        Iterator(SelfType* a, SPInt i = 0) : pArray(a), CurIndex(i) { }
        bool operator==(const Iterator& o) const { return pArray == o.pArray && CurIndex == o.CurIndex; }
        bool operator!=(const Iterator& o) const { return pArray != o.pArray || CurIndex != o.CurIndex; }
        Iterator& operator++()
        {
            if (pArray)
                if (CurIndex < (SPInt)pArray->GetSize())
                    ++CurIndex;
            return *this;
        }
        Iterator operator++(int) { Iterator it(*this); operator++(); return it; }
        Iterator& operator--()
        {
            if (pArray)
                if (CurIndex >= 0)
                    --CurIndex;
            return *this;
        }
        Iterator operator--(int) { Iterator it(*this); operator--(); return it; }
        Iterator operator+(int d) const { return Iterator(pArray, CurIndex + d); }
        Iterator operator-(int d) const { return Iterator(pArray, CurIndex - d); }
        SPInt operator-(const Iterator& r) const { return CurIndex - r.CurIndex; }
        ValueType& operator*() const { return (*pArray)[CurIndex]; }
        ValueType* operator->() const { return &(*pArray)[CurIndex]; }
        ValueType* GetPtr() const { return &(*pArray)[CurIndex]; }
        bool IsFinished() const { return !pArray || CurIndex < 0 || CurIndex >= (int)pArray->GetSize(); }
        void Remove()
        {
            if (!IsFinished())
                pArray->RemoveAt(CurIndex);
        }
        SPInt GetIndex() const { return CurIndex; }
    };
    Iterator Begin() { return Iterator(this); }
    Iterator End() { return Iterator(this, (SPInt)GetSize()); }
    Iterator Last() { return Iterator(this, (SPInt)GetSize() - 1); }

    class ConstIterator
    {
        const SelfType* pArray;
        SPInt           CurIndex;
    public:
        ConstIterator() : pArray(0), CurIndex(-1) { }
        ConstIterator(const SelfType* a, SPInt i = 0) : pArray(a), CurIndex(i) { }
        bool operator==(const ConstIterator& o) const { return pArray == o.pArray && CurIndex == o.CurIndex; }
        bool operator!=(const ConstIterator& o) const { return pArray != o.pArray || CurIndex != o.CurIndex; }
        ConstIterator& operator++()
        {
            if (pArray)
                if (CurIndex < (int)pArray->GetSize())
                    ++CurIndex;
            return *this;
        }
        ConstIterator operator++(int) { ConstIterator it(*this); operator++(); return it; }
        ConstIterator& operator--()
        {
            if (pArray)
                if (CurIndex >= 0)
                    --CurIndex;
            return *this;
        }
        ConstIterator operator--(int) { ConstIterator it(*this); operator--(); return it; }
        ConstIterator operator+(int d) const { return ConstIterator(pArray, CurIndex + d); }
        ConstIterator operator-(int d) const { return ConstIterator(pArray, CurIndex - d); }
        SPInt operator-(const ConstIterator& r) const { return CurIndex - r.CurIndex; }
        const ValueType& operator*() const { return (*pArray)[CurIndex]; }
        const ValueType* operator->() const { return &(*pArray)[CurIndex]; }
        const ValueType* GetPtr() const { return &(*pArray)[CurIndex]; }
        bool IsFinished() const { return !pArray || CurIndex < 0 || CurIndex >= (int)pArray->GetSize(); }
        SPInt GetIndex() const { return CurIndex; }
    };
    ConstIterator Begin() const { return ConstIterator(this); }
    ConstIterator End() const { return ConstIterator(this, (SPInt)GetSize()); }
    ConstIterator Last() const { return ConstIterator(this, (SPInt)GetSize() - 1); }

protected:
    ArrayData Data;
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class Array : public ArrayBase<ArrayData<T, AllocatorGH<T, SID>, SizePolicy> >
{
public:
    typedef T                                                         ValueType;
    typedef AllocatorGH<T, SID>                                       AllocatorType;
    typedef SizePolicy                                                SizePolicyType;
    typedef Array<T, SID, SizePolicy>                                 SelfType;
    typedef ArrayBase<ArrayData<T, AllocatorGH<T, SID>, SizePolicy> > BaseType;

    Array() : BaseType() {}
    Array(int size) : BaseType(size) {}
    Array(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }
    Array(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayPOD : public ArrayBase<ArrayData<T, AllocatorGH_POD<T, SID>, SizePolicy> >
{
public:
    typedef T                                                             ValueType;
    typedef AllocatorGH<T, SID>                                           AllocatorType;
    typedef SizePolicy                                                    SizePolicyType;
    typedef ArrayPOD<T, SID, SizePolicy>                                  SelfType;
    typedef ArrayBase<ArrayData<T, AllocatorGH_POD<T, SID>, SizePolicy> > BaseType;

    ArrayPOD() : BaseType() {}
    ArrayPOD(int size) : BaseType(size) {}
    ArrayPOD(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }
    ArrayPOD(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayCPP : public ArrayBase<ArrayData<T, AllocatorGH_CPP<T, SID>, SizePolicy> >
{
public:
    typedef T                                                             ValueType;
    typedef AllocatorGH<T, SID>                                           AllocatorType;
    typedef SizePolicy                                                    SizePolicyType;
    typedef ArrayCPP<T, SID, SizePolicy>                                  SelfType;
    typedef ArrayBase<ArrayData<T, AllocatorGH_CPP<T, SID>, SizePolicy> > BaseType;

    ArrayCPP() : BaseType() {}
    ArrayCPP(int size) : BaseType(size) {}
    ArrayCPP(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }
    ArrayCPP(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayLH : public ArrayBase<ArrayData<T, AllocatorLH<T, SID>, SizePolicy> >
{
public:
    typedef T                                                         ValueType;
    typedef AllocatorLH<T, SID>                                       AllocatorType;
    typedef SizePolicy                                                SizePolicyType;
    typedef ArrayLH<T, SID, SizePolicy>                               SelfType;
    typedef ArrayBase<ArrayData<T, AllocatorLH<T, SID>, SizePolicy> > BaseType;

    ArrayLH() : BaseType() {}
    ArrayLH(int size) : BaseType(size) {}
    ArrayLH(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }
    ArrayLH(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayLH_POD : public ArrayBase<ArrayData<T, AllocatorLH_POD<T, SID>, SizePolicy> >
{
public:
    typedef T                                                             ValueType;
    typedef AllocatorLH<T, SID>                                           AllocatorType;
    typedef SizePolicy                                                    SizePolicyType;
    typedef ArrayLH_POD<T, SID, SizePolicy>                               SelfType;
    typedef ArrayBase<ArrayData<T, AllocatorLH_POD<T, SID>, SizePolicy> > BaseType;

    ArrayLH_POD() : BaseType() {}
    ArrayLH_POD(int size) : BaseType(size) {}
    ArrayLH_POD(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }
    ArrayLH_POD(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayDH : public ArrayBase<ArrayDataDH<T, AllocatorDH<T, SID>, SizePolicy> >
{
public:
    typedef T                                                           ValueType;
    typedef AllocatorDH<T, SID>                                         AllocatorType;
    typedef SizePolicy                                                  SizePolicyType;
    typedef ArrayDH<T, SID, SizePolicy>                                 SelfType;
    typedef ArrayBase<ArrayDataDH<T, AllocatorDH<T, SID>, SizePolicy> > BaseType;

    ArrayDH(MemoryHeap* heap) : BaseType(heap) {}
    ArrayDH(MemoryHeap* heap, int size) : BaseType(heap, size) {}
    ArrayDH(MemoryHeap* heap, const SizePolicyType& p) : BaseType(heap) { SetSizePolicy(p); }
    ArrayDH(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayDH_POD : public ArrayBase<ArrayDataDH<T, AllocatorDH_POD<T, SID>, SizePolicy> >
{
public:
    typedef T                                                               ValueType;
    typedef AllocatorDH<T, SID>                                             AllocatorType;
    typedef SizePolicy                                                      SizePolicyType;
    typedef ArrayDH_POD<T, SID, SizePolicy>                                 SelfType;
    typedef ArrayBase<ArrayDataDH<T, AllocatorDH_POD<T, SID>, SizePolicy> > BaseType;

    ArrayDH_POD(MemoryHeap* heap) : BaseType(heap) {}
    ArrayDH_POD(MemoryHeap* heap, int size) : BaseType(heap, size) {}
    ArrayDH_POD(MemoryHeap* heap, const SizePolicyType& p) : BaseType(heap) { SetSizePolicy(p); }
    ArrayDH_POD(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

// (appended for sfr_as2_02)
template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
class ArrayCC : public ArrayBase<ArrayDataCC<T, AllocatorLH<T, SID>, SizePolicy> >
{
public:
    typedef T                                                           ValueType;
    typedef AllocatorLH<T, SID>                                         AllocatorType;
    typedef SizePolicy                                                  SizePolicyType;
    typedef ArrayCC<T, SID, SizePolicy>                                 SelfType;
    typedef ArrayBase<ArrayDataCC<T, AllocatorLH<T, SID>, SizePolicy> > BaseType;

    ArrayCC(const ValueType& defval) : BaseType(defval) {}
    ArrayCC(const ValueType& defval, int size) : BaseType(defval, size) {}
    ArrayCC(const SelfType& a) : BaseType(a) {}
    const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }
};

} // namespace Scaleform

#endif
