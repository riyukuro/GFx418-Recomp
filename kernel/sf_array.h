// Recovered Scaleform GFx 4.1.18: dynamic arrays. ArrayDataBase holds {Data, Size, Policy(Capacity)}; the policy gives
// minimum capacity, growth granularity and whether the array may shrink. Growth: size >= capacity reserves size*5/4,
// shrinking below half the capacity reserves the new size.
#ifndef MS2_SF_KERNEL_ARRAY_H
#define MS2_SF_KERNEL_ARRAY_H

#include "ms2/scaleform/kernel/sf_allocator.h"

namespace Scaleform {

struct ArrayDefaultPolicy
{
    ArrayDefaultPolicy() : Capacity(0) { }
    ArrayDefaultPolicy(const ArrayDefaultPolicy&) : Capacity(0) { }
    UPInt GetMinCapacity() const { return 0; }
    UPInt GetGranularity() const { return 4; }
    bool  NeverShrinking() const { return 0; }
    UPInt GetCapacity() const { return Capacity; }
    void  SetCapacity(UPInt c) { Capacity = c; }
private:
    UPInt Capacity;
};

template<int MinCapacity = 0, int Granularity = 4, bool NeverShrink = false>
struct ArrayConstPolicy
{
    typedef ArrayConstPolicy<MinCapacity, Granularity, NeverShrink> SelfType;
    ArrayConstPolicy() : Capacity(0) { }
    ArrayConstPolicy(const SelfType&) : Capacity(0) { }
    UPInt GetMinCapacity() const { return MinCapacity; }
    UPInt GetGranularity() const { return Granularity; }
    bool  NeverShrinking() const { return NeverShrink; }
    UPInt GetCapacity() const { return Capacity; }
    void  SetCapacity(UPInt c) { Capacity = c; }
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

    ArrayDataBase() : Data(0), Size(0), Policy() { }
    ArrayDataBase(const SizePolicy& p) : Data(0), Size(0), Policy(p) { }
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

    void Reserve(const void* heapAddr, UPInt newCapacity)
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
        }
        else
        {
            UPInt gran = Policy.GetGranularity();
            newCapacity = (newCapacity + gran - 1) / gran * gran;
            if (Data)
            {
                if (Allocator::IsMovable())
                {
                    Data = (T*)Allocator::Realloc(Data, sizeof(T) * newCapacity, __FILE__, __LINE__);
                }
                else
                {
                    // non-movable elements: copy-construct into a new block, destroy the old ones
                    T* newData = (T*)Allocator::Alloc(heapAddr, sizeof(T) * newCapacity, __FILE__, __LINE__);
                    UPInt i, s;
                    s = (Size < newCapacity) ? Size : newCapacity;
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
                Data = (T*)Allocator::Alloc(heapAddr, sizeof(T) * newCapacity, __FILE__, __LINE__);
            }
            Policy.SetCapacity(newCapacity);
        }
    }

    void ResizeNoConstruct(const void* heapAddr, UPInt newSize)
    {
        UPInt oldSize = Size;
        if (newSize < oldSize)
        {
            Allocator::DestructArray(Data + newSize, oldSize - newSize);
            if (newSize < (Policy.GetCapacity() >> 1))
                Reserve(heapAddr, newSize);
        }
        else if (newSize >= Policy.GetCapacity())
        {
            Reserve(heapAddr, newSize + (newSize >> 2));
        }
        Size = newSize;
    }

    ValueType* Data;
    UPInt      Size;
    SizePolicy Policy;
};

// Array data whose heap is "the heap that owns this array object" (the allocator gets `this` as the address).
template<class T, class Allocator, class SizePolicy>
struct ArrayData : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayData<T, Allocator, SizePolicy>     SelfType;

    ArrayData() : BaseType() { }
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

// Array data with an explicit heap pointer.
template<class T, class Allocator, class SizePolicy>
struct ArrayDataDH : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayDataDH<T, Allocator, SizePolicy>   SelfType;

    ArrayDataDH(MemoryHeap* heap) : BaseType(), pHeap(heap) { }
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

// Array data that constructs new elements as copies of a default value.
template<class T, class Allocator, class SizePolicy>
struct ArrayDataCC : ArrayDataBase<T, Allocator, SizePolicy>
{
    typedef T                                       ValueType;
    typedef Allocator                               AllocatorType;
    typedef SizePolicy                              SizePolicyType;
    typedef ArrayDataBase<T, Allocator, SizePolicy> BaseType;
    typedef ArrayDataCC<T, Allocator, SizePolicy>   SelfType;

    ArrayDataCC(const ValueType& defval) : BaseType(), DefaultValue(defval) { }
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

    ArrayBase() : Data() { }
    ArrayBase(int size) : Data(size) { }
    ArrayBase(const SelfType& a) : Data(a.Data) { }
    ArrayBase(MemoryHeap* heap) : Data(heap) { }
    ArrayBase(MemoryHeap* heap, int size) : Data(heap, size) { }
    ArrayBase(const ValueType& defval) : Data(defval) { }
    ArrayBase(const ValueType& defval, int size) : Data(defval, size) { }

    SizePolicyType* GetSizePolicy() const { return Data.Policy; }
    void SetSizePolicy(const SizePolicyType& p) { Data.Policy = p; }

    bool  NeverShrinking() const { return Data.Policy.NeverShrinking(); }
    UPInt GetSize() const { return Data.Size; }
    bool  IsEmpty() const { return Data.Size == 0; }
    UPInt GetCapacity() const { return Data.GetCapacity(); }
    UPInt GetNumBytes() const { return Data.GetCapacity() * sizeof(ValueType); }

    void ClearAndRelease() { Data.ClearAndRelease(); }
    void Clear() { Data.Resize(0); }
    void Resize(UPInt newSize) { Data.Resize(newSize); }
    void Reserve(UPInt newCapacity)
    {
        if (newCapacity > Data.GetCapacity())
            Data.Reserve(newCapacity);
    }

    ValueType&       At(UPInt i) { return Data.Data[i]; }
    const ValueType& At(UPInt i) const { return Data.Data[i]; }
    ValueType        ValueAt(UPInt i) const { return Data.Data[i]; }
    ValueType&       operator[](UPInt i) { return Data.Data[i]; }
    const ValueType& operator[](UPInt i) const { return Data.Data[i]; }
    const ValueType* GetDataPtr() const { return Data.Data; }
    ValueType*       GetDataPtr() { return Data.Data; }

    void PushBack(const ValueType& val) { Data.PushBack(val); }
    template<class S> void PushBackAlt(const S& val) { Data.PushBackAlt(val); }
    void PopBack(UPInt count = 1) { Data.Resize(Data.Size - count); }
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

    ValueType&       Front() { return At(0); }
    const ValueType& Front() const { return At(0); }
    ValueType&       Back() { return At(Data.Size - 1); }
    const ValueType& Back() const { return At(Data.Size - 1); }

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
    void Append(const SelfType& other) { Append(other.Data.Data, other.GetSize()); }
    void Append(const ValueType other[], UPInt count) { Data.Append(other, count); }

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

// Concrete arrays: <element, stat id, size policy>, by heap policy (GH global, LH owner's heap, DH explicit heap, CC
// default-value construction) and construction policy (default Mov, _POD, _CPP).
#define MS2_SF_ARRAY_CLASS(Name, DataT, AllocT, ExtraCtors)                                                       \
    template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>                          \
    class Name : public ArrayBase<DataT<T, AllocT<T, SID>, SizePolicy> >                                         \
    {                                                                                                              \
    public:                                                                                                        \
        typedef T                                                ValueType;                                        \
        typedef SizePolicy                                       SizePolicyType;                                   \
        typedef Name<T, SID, SizePolicy>                         SelfType;                                         \
        typedef ArrayBase<DataT<T, AllocT<T, SID>, SizePolicy> > BaseType;                                         \
        ExtraCtors                                                                                                 \
        Name(const SelfType& a) : BaseType(a) { }                                                                  \
        const SelfType& operator=(const SelfType& a) { BaseType::operator=(a); return *this; }                     \
    };

#define MS2_SF_ARRAY_CTORS_PLAIN(Name)                                                                             \
    Name() : BaseType() { }                                                                                        \
    Name(int size) : BaseType(size) { }                                                                            \
    Name(const SizePolicyType& p) : BaseType() { SetSizePolicy(p); }

#define MS2_SF_ARRAY_CTORS_DH(Name)                                                                                \
    Name(MemoryHeap* heap) : BaseType(heap) { }                                                                    \
    Name(MemoryHeap* heap, int size) : BaseType(heap, size) { }                                                    \
    Name(MemoryHeap* heap, const SizePolicyType& p) : BaseType(heap) { SetSizePolicy(p); }

#define MS2_SF_ARRAY_CTORS_CC(Name)                                                                                \
    Name(const ValueType& defval) : BaseType(defval) { }                                                           \
    Name(const ValueType& defval, int size) : BaseType(defval, size) { }                                           \
    Name(const ValueType& defval, const SizePolicyType& p) : BaseType(defval) { SetSizePolicy(p); }

MS2_SF_ARRAY_CLASS(Array,       ArrayData,   AllocatorGH,     MS2_SF_ARRAY_CTORS_PLAIN(Array))
MS2_SF_ARRAY_CLASS(ArrayPOD,    ArrayData,   AllocatorGH_POD, MS2_SF_ARRAY_CTORS_PLAIN(ArrayPOD))
MS2_SF_ARRAY_CLASS(ArrayCPP,    ArrayData,   AllocatorGH_CPP, MS2_SF_ARRAY_CTORS_PLAIN(ArrayCPP))
MS2_SF_ARRAY_CLASS(ArrayLH,     ArrayData,   AllocatorLH,     MS2_SF_ARRAY_CTORS_PLAIN(ArrayLH))
MS2_SF_ARRAY_CLASS(ArrayLH_POD, ArrayData,   AllocatorLH_POD, MS2_SF_ARRAY_CTORS_PLAIN(ArrayLH_POD))
MS2_SF_ARRAY_CLASS(ArrayDH,     ArrayDataDH, AllocatorDH,     MS2_SF_ARRAY_CTORS_DH(ArrayDH))
MS2_SF_ARRAY_CLASS(ArrayDH_POD, ArrayDataDH, AllocatorDH_POD, MS2_SF_ARRAY_CTORS_DH(ArrayDH_POD))
MS2_SF_ARRAY_CLASS(ArrayCC,     ArrayDataCC, AllocatorLH,     MS2_SF_ARRAY_CTORS_CC(ArrayCC))

}  // namespace Scaleform

#endif
