// Recovered Scaleform 4.1.18 kernel: index ranges and RangeDataArray, a sorted array of non-overlapping
// [Index, Index+Length) runs each carrying a value (the text format runs of a paragraph). The member templates are
// instantiated by their users (Render Text_StyledText: RangeDataArray<Ptr<TextFormat>, ArrayLH<...>>).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_KERNEL_RANGE_H
#define MS2_SF_INC_KERNEL_RANGE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_array.h"

namespace Scaleform {

class Range
{
public:
    SPInt Index;
    UPInt Length;

    enum BoundsType { Min, Max };

    Range() : Index(0), Length(0) {}
    explicit Range(UPInt count) { SetRange(count); }
    Range(SPInt index, UPInt length) { SetRange(index, length); }
    Range(const Range& r) { SetRange(r); }
    Range(BoundsType bt) { SetRange(bt); }

    void SetRange(UPInt count) { Index = 0; Length = count; }
    void SetRange(SPInt index, UPInt length)
    {
        Index  = index;
        Length = length;
    }
    void SetRange(const Range& r) { SetRange(r.Index, r.Length); }
    void SetRange(BoundsType bt)
    {
        switch (bt)
        {
        case Min: SetRange(0, 0); break;
        case Max: SetRange(0, SF_MAX_UPINT); break;
        }
    }

    // moves the start forward by delta (at most Length), keeping the end
    SPInt MoveIndex(SPInt delta)
    {
        delta = (delta > SPInt(Length)) ? SPInt(Length) : delta;
        Index += delta;
        Length = (UPInt)(Length - delta);
        return Index;
    }
    // shifts the whole range
    SPInt MoveRange(SPInt delta)
    {
        Index += delta;
        return Index;
    }
    UPInt ShrinkRange(UPInt lengthDelta)
    {
        if (lengthDelta > Length)
            Length = 0;
        else
            Length -= lengthDelta;
        return Length;
    }
    UPInt ExpandRange(UPInt lengthDelta)
    {
        Length += lengthDelta;
        return Length;
    }

    SPInt NextIndex() const  { return Index + Length; }
    SPInt LastIndex() const  { return Index + Length - 1; }
    SPInt FirstIndex() const { return Index; }
    bool  IsEmpty() const    { return Length == 0; }
    void  Clear()            { SetRange(Min); }

    bool Contains(SPInt index) const      { return (index >= Index && index <= LastIndex()); }
    bool Contains(const Range& r) const   { return (r.Index >= Index && r.LastIndex() <= LastIndex()); }
    bool Intersects(const Range& r) const { return (r.LastIndex() >= FirstIndex()) && (LastIndex() >= r.FirstIndex()); }

    // 0 inside, otherwise the signed distance from the nearer end
    int CompareTo(SPInt index) const
    {
        if (Contains(index))
            return 0;
        if (index < Index)
            return int(Index - index);
        else
            return int(LastIndex() - index);
    }
};

template<class T>
class RangeData : public Range
{
    T Data;

public:
    RangeData() : Range() {}
    RangeData(SPInt index, UPInt length, const T& data) : Range(index, length), Data(data) {}

    T&       GetData()                    { return Data; }
    const T& GetData() const              { return Data; }
    T&       operator->()                 { return Data; }
    const T& operator->() const           { return Data; }
    T&       operator*()                  { return Data; }
    const T& operator*() const            { return Data; }
    void     SetData(const T& data)       { Data = data; }
    bool     IsDataEqual(const T& data) const { return Data == data; }
};

template<class T, class Array = Scaleform::Array<RangeData<T> > >
class RangeDataArray
{
    UPInt FindRangeIndex(SPInt index) const;
    UPInt FindNearestRangeIndex(SPInt index) const;

public:
    typedef RangeData<T> TypedRangeData;
    typedef Array        RangeArrayType;

    RangeArrayType Ranges;

    TypedRangeData&       operator[](UPInt position)       { return Ranges[position]; }
    const TypedRangeData& operator[](UPInt position) const { return Ranges[position]; }
    UPInt Count() const { return Ranges.GetSize(); }

    void SetRange(SPInt index, UPInt length, const T& data) { SetRange(TypedRangeData(index, length, data)); }
    void SetRange(const TypedRangeData& range);
    void ClearRange(SPInt index, UPInt length);
    TypedRangeData& Append(UPInt length, const T& data);
    void InsertRange(SPInt startPos, UPInt length, const T& data);
    void ExpandRange(SPInt startPos, UPInt length);
    void RemoveRange(SPInt startPos, UPInt length);
    void RemoveAll() { Ranges.Resize(0); }

    class Iterator
    {
        friend class RangeDataArray<T, Array>;
        RangeDataArray<T, Array>* pArray;
        SPInt                     Index;

        explicit Iterator(RangeDataArray<T, Array>& arr) : pArray(&arr), Index(0) {}
        Iterator(RangeDataArray<T, Array>& arr, bool) : pArray(&arr), Index(pArray->Count() - 1) {}

        void InsertBefore(const TypedRangeData& range);
        void InsertAfter(const TypedRangeData& range);
        void Remove();

    public:
        Iterator(const Iterator& it) : pArray(it.pArray), Index(it.Index) {}
        Iterator() : pArray(0), Index(-1) {}

        Iterator& operator++()
        {
            if (Index < (SPInt)pArray->Count())
                ++Index;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator it(*this);
            if (Index < (SPInt)pArray->Count())
                ++Index;
            return it;
        }
        Iterator& operator--()
        {
            if (Index >= 0)
                --Index;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator it(*this);
            if (Index >= 0)
                --Index;
            return it;
        }
        TypedRangeData& operator*()  { return (*pArray)[Index]; }
        TypedRangeData* operator->() { return &(*pArray)[Index]; }
        TypedRangeData* GetPtr()     { return (Index < (SPInt)pArray->Count()) ? &(*pArray)[Index] : NULL; }
        bool operator==(const Iterator& it) const { return (pArray == it.pArray && Index == it.Index); }
        // clamped to the array
        Iterator operator+(SPInt delta) const
        {
            Iterator it(*this);
            if (Index + delta < 0)
                it.Index = 0;
            else if (UPInt(Index + delta) >= pArray->Count())
                it.Index = pArray->Count() - 1;
            else
                it.Index += delta;
            return it;
        }
        bool IsFinished() const { return Index < 0 || UPInt(Index) >= pArray->Count(); }
    };

    Iterator Begin() { return Iterator(*this); }
    Iterator Last()  { return Iterator(*this, true); }
    Iterator GetIteratorAt(SPInt index);
    Iterator GetIteratorByNearestIndex(SPInt index);

    class ConstIterator
    {
        friend class RangeDataArray<T, Array>;
        const RangeDataArray<T, Array>* pArray;
        SPInt                           Index;

        explicit ConstIterator(const RangeDataArray<T, Array>& arr) : pArray(&arr), Index(0) {}
        ConstIterator(const RangeDataArray<T, Array>& arr, bool) : pArray(&arr), Index(pArray->Count() - 1) {}

    public:
        ConstIterator(const ConstIterator& it) : pArray(it.pArray), Index(it.Index) {}
        ConstIterator() : pArray(0), Index(-1) {}

        ConstIterator& operator++()
        {
            if (Index < (SPInt)pArray->Count())
                ++Index;
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator it(*this);
            if (Index < (SPInt)pArray->Count())
                ++Index;
            return it;
        }
        ConstIterator& operator--()
        {
            if (Index >= 0)
                --Index;
            return *this;
        }
        ConstIterator operator--(int)
        {
            ConstIterator it(*this);
            if (Index >= 0)
                --Index;
            return it;
        }
        const TypedRangeData& operator*() const  { return (*pArray)[Index]; }
        const TypedRangeData* operator->() const { return &(*pArray)[Index]; }
        const TypedRangeData* GetPtr() const     { return (Index < (SPInt)pArray->Count()) ? &(*pArray)[Index] : NULL; }
        bool operator==(const ConstIterator& it) const { return (pArray == it.pArray && Index == it.Index); }
        ConstIterator operator+(SPInt delta) const
        {
            ConstIterator it(*this);
            if (Index + delta < 0)
                it.Index = 0;
            else if (UPInt(Index + delta) >= pArray->Count())
                it.Index = pArray->Count() - 1;
            else
                it.Index += delta;
            return it;
        }
        bool IsFinished() const { return Index < 0 || UPInt(Index) >= pArray->Count(); }
    };

    ConstIterator Begin() const { return ConstIterator(*this); }
    ConstIterator Last() const  { return ConstIterator(*this, true); }
    ConstIterator GetIteratorAt(SPInt index) const;
    ConstIterator GetIteratorByNearestIndex(SPInt index) const;

    void CheckIntegrity() {}
};

template<class T, class Array>
void RangeDataArray<T, Array>::Iterator::InsertBefore(const TypedRangeData& range)
{
    pArray->Ranges.InsertAt(Index, range);
}

template<class T, class Array>
void RangeDataArray<T, Array>::Iterator::InsertAfter(const TypedRangeData& range)
{
    pArray->Ranges.InsertAt(Index + 1, range);
}

template<class T, class Array>
void RangeDataArray<T, Array>::Iterator::Remove()
{
    if (Index >= 0 && UPInt(Index) < pArray->Count())
        pArray->Ranges.RemoveAt(Index);
}

// binary search for the run containing index; SF_MAX_UPINT if none does
template<class T, class Array>
UPInt RangeDataArray<T, Array>::FindRangeIndex(SPInt index) const
{
    const UPInt count = Count();
    UPInt lo = 0;
    UPInt hi = count - 1;
    while (lo < hi && hi != (UPInt)-1)
    {
        UPInt mid = (lo + hi) / 2;
        int   cmp = Ranges[mid].CompareTo(index);
        if (cmp == 0)
            return mid;
        if (cmp < 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if (lo == hi && Ranges[lo].CompareTo(index) == 0)
        return lo;
    return SF_MAX_UPINT;
}

template<class T, class Array>
typename RangeDataArray<T, Array>::Iterator RangeDataArray<T, Array>::GetIteratorAt(SPInt index)
{
    UPInt i = FindRangeIndex(index);
    if (i != SF_MAX_UPINT)
        return Begin() + i;
    return Iterator();
}

template<class T, class Array>
typename RangeDataArray<T, Array>::ConstIterator RangeDataArray<T, Array>::GetIteratorAt(SPInt index) const
{
    UPInt i = FindRangeIndex(index);
    if (i != SF_MAX_UPINT)
        return Begin() + i;
    return ConstIterator();
}

// the run containing index, or else the last run that starts before it (0 when the array is empty)
template<class T, class Array>
UPInt RangeDataArray<T, Array>::FindNearestRangeIndex(SPInt index) const
{
    const UPInt count = Count();
    if (count == 0)
        return 0;
    UPInt lo = 0;
    UPInt hi = count - 1;
    UPInt lowest = 0;
    while (lo < hi && hi != (UPInt)-1)
    {
        UPInt mid = (lo + hi) / 2;
        int   cmp = Ranges[mid].CompareTo(index);
        if (cmp == 0)
            return mid;
        if (cmp < 0)
        {
            lowest = lo;
            lo     = mid + 1;
        }
        else
            hi = mid - 1;
    }
    if (lo == hi && Ranges[lo].CompareTo(index) == 0)
        return lo;
    while (lowest < hi && Ranges[lowest + 1].CompareTo(index) < 0)
        ++lowest;
    return lowest;
}

template<class T, class Array>
typename RangeDataArray<T, Array>::Iterator RangeDataArray<T, Array>::GetIteratorByNearestIndex(SPInt index)
{
    return Begin() + FindNearestRangeIndex(index);
}

template<class T, class Array>
typename RangeDataArray<T, Array>::ConstIterator RangeDataArray<T, Array>::GetIteratorByNearestIndex(SPInt index) const
{
    return Begin() + FindNearestRangeIndex(index);
}

// Puts range in, cutting or splitting the runs it overlaps, then merges it with equal-valued neighbours.
template<class T, class Array>
void RangeDataArray<T, Array>::SetRange(const TypedRangeData& range)
{
    if (Count() > 0)
    {
        Iterator it = GetIteratorByNearestIndex(range.Index);
        Iterator insertionPoint;
        if (it->Contains(range))
        {
            if (it->Index == range.Index)
            {
                // same start: the old run keeps its tail
                it->MoveIndex(range.Length);
                if (it->IsEmpty())
                    *it = range;
                else
                    it.InsertBefore(range);
                insertionPoint = it;
                ++it;
            }
            else if (it->NextIndex() > range.NextIndex())
            {
                // strictly inside: split the old run around range
                TypedRangeData tail = *it;
                SPInt end = it->NextIndex();
                it->ShrinkRange(end - range.Index);
                tail.MoveIndex(it->Length + range.Length);
                it.InsertAfter(range);
                ++it;
                insertionPoint = it;
                it.InsertAfter(tail);
                ++it;
            }
            else
            {
                // same end
                it->ShrinkRange(range.Length);
                insertionPoint = ++it;
                it.InsertBefore(range);
                ++it;
            }
        }
        else if (it->Contains(range.Index))
        {
            it->ShrinkRange(it->NextIndex() - range.Index);
            insertionPoint = ++it;
            it.InsertBefore(range);
            ++it;
        }
        else
        {
            if (it->CompareTo(range.Index) > 0)
            {
                it.InsertBefore(range);
                insertionPoint = it;
            }
            else
            {
                it.InsertAfter(range);
                insertionPoint = ++it;
            }
            ++it;
        }
        // drop the runs range covers completely, cut the head of the one it ends in
        while (!it.IsFinished() && range.Contains(*it))
            it.Remove();
        if (!it.IsFinished() && it->Contains(range.NextIndex() - 1))
            it->MoveIndex(range.NextIndex() - it->Index);

        Iterator prevIt = insertionPoint;
        --prevIt;
        if (!prevIt.IsFinished())
        {
            if (prevIt->IsEmpty())
            {
                --insertionPoint;
                prevIt.Remove();
            }
            else if (prevIt->NextIndex() == range.Index && prevIt->IsDataEqual(insertionPoint->GetData()))
            {
                prevIt->ExpandRange(range.Length);
                insertionPoint.Remove();
                insertionPoint = prevIt;
            }
        }
        Iterator nextIt = insertionPoint;
        ++nextIt;
        if (!nextIt.IsFinished())
        {
            if (nextIt->IsEmpty())
                nextIt.Remove();
            else if (insertionPoint->NextIndex() == nextIt->Index && insertionPoint->IsDataEqual(nextIt->GetData()))
            {
                insertionPoint->ExpandRange(nextIt->Length);
                nextIt.Remove();
            }
        }
    }
    else
    {
        Begin().InsertBefore(range);
    }
    CheckIntegrity();
}

template<class T, class Array>
typename RangeDataArray<T, Array>::TypedRangeData& RangeDataArray<T, Array>::Append(UPInt length, const T& data)
{
    UPInt count = Count();
    TypedRangeData* plast = NULL;
    if (count > 0)
    {
        plast = &Ranges[count - 1];
        if (count > 0 && plast->IsDataEqual(data))
        {
            plast->Length += length;
            return *plast;
        }
    }
    Ranges.Resize(count + 1);
    TypedRangeData& r = Ranges[count];
    if (plast)
        r.Index = plast->Index + plast->Length;
    else
        r.Index = 0;
    r.Length = length;
    r.SetData(data);
    CheckIntegrity();
    return r;
}

template<class T, class Array>
void RangeDataArray<T, Array>::InsertRange(SPInt startPos, UPInt length, const T& data)
{
    ExpandRange(startPos, length);
    SetRange(startPos, length, data);
    CheckIntegrity();
}

// Opens a gap of length positions at startPos: the run containing (or ending at) startPos grows, later runs shift.
template<class T, class Array>
void RangeDataArray<T, Array>::ExpandRange(SPInt startPos, UPInt length)
{
    if (Count() > 0)
    {
        Iterator it = GetIteratorByNearestIndex(startPos);
        TypedRangeData* pnearest = it.GetPtr();
        if (pnearest)
        {
            if (pnearest->Contains(startPos) || pnearest->NextIndex() == startPos)
                pnearest->Length += length;
        }
        for (++it; !it.IsFinished(); ++it)
            it->MoveRange((SPInt)length);
    }
    CheckIntegrity();
}

// Deletes the positions [startPos, startPos+length) and closes the gap (SF_MAX_UPINT: to the end).
template<class T, class Array>
void RangeDataArray<T, Array>::RemoveRange(SPInt startPos, UPInt length)
{
    CheckIntegrity();
    if (Count() > 0)
    {
        Iterator it = GetIteratorByNearestIndex(startPos);
        Iterator removalPoint;
        if (length == SF_MAX_UPINT)
            length = SF_MAX_SPINT - startPos;
        TypedRangeData range(startPos, length, T());
        TypedRangeData& r = *it;
        if (r.Contains(range))
        {
            if (r.Index == range.Index)
            {
                r.MoveIndex(range.Length);
                if (r.IsEmpty())
                    it.Remove();
                removalPoint = it;
            }
            else if (r.NextIndex() > range.NextIndex())
            {
                r.ShrinkRange(range.Length);
                if (r.IsEmpty())
                    it.Remove();
                else
                    ++it;
                removalPoint = it;
            }
            else
            {
                r.ShrinkRange(range.Length);
                removalPoint = ++it;
                ++it;
            }
        }
        else if (r.Contains(range.Index))
        {
            r.ShrinkRange(r.NextIndex() - range.Index);
            if (r.IsEmpty())
                it.Remove();
            else
                ++it;
            removalPoint = it;
        }
        else
        {
            if (r.CompareTo(range.Index) > 0)
                removalPoint = it;
            else
                removalPoint = ++it;
        }
        while (!it.IsFinished() && range.Contains(*it))
            it.Remove();
        if (!it.IsFinished() && it->Contains(range.NextIndex() - 1))
            it->MoveIndex(range.NextIndex() - it->Index);

        // the runs on both sides of the gap meet: merge them when their values are equal
        Iterator prevIt = removalPoint;
        --prevIt;
        if (!prevIt.IsFinished() && !removalPoint.IsFinished() &&
            prevIt->NextIndex() == removalPoint->Index - SPInt(length) &&
            prevIt->IsDataEqual(removalPoint->GetData()))
        {
            prevIt->ExpandRange(removalPoint->Length);
            removalPoint.Remove();
        }
        for (; !removalPoint.IsFinished(); ++removalPoint)
            removalPoint->MoveRange(-((SPInt)length));
    }
    CheckIntegrity();
}

// Removes the values from [startPos, startPos+length) without moving anything (SF_MAX_UPINT: to the end).
template<class T, class Array>
void RangeDataArray<T, Array>::ClearRange(SPInt startPos, UPInt length)
{
    CheckIntegrity();
    if (Count() > 0)
    {
        Iterator it = GetIteratorByNearestIndex(startPos);
        Iterator removalPoint;
        if (length == SF_MAX_UPINT)
            length = SF_MAX_SPINT - startPos;
        TypedRangeData range(startPos, length, T());
        if (it->Contains(range))
        {
            if (it->Index == range.Index)
            {
                it->MoveIndex(range.Length);
                removalPoint = it;
                if (it->IsEmpty())
                    it.Remove();
                else
                    ++it;
            }
            else if (it->NextIndex() > range.NextIndex())
            {
                TypedRangeData tail = *it;
                SPInt end = it->NextIndex();
                it->ShrinkRange(end - range.Index);
                tail.MoveIndex(it->Length + range.Length);
                ++it;
                removalPoint = it;
                it.InsertBefore(tail);
                ++it;
            }
            else
            {
                it->ShrinkRange(range.Length);
                removalPoint = ++it;
                ++it;
            }
        }
        else if (it->Contains(range.Index))
        {
            it->ShrinkRange(it->NextIndex() - range.Index);
            removalPoint = ++it;
            ++it;
        }
        else
        {
            if (it->CompareTo(range.Index) > 0)
            {
                removalPoint = it;
                ++it;
            }
            else
            {
                removalPoint = ++it;
            }
        }
        while (!it.IsFinished() && range.Contains(*it))
            it.Remove();
        if (!it.IsFinished() && it->Contains(range.NextIndex() - 1))
            it->MoveIndex(range.NextIndex() - it->Index);
    }
    CheckIntegrity();
}

} // namespace Scaleform

#endif
