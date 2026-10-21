// Recovered Scaleform 4.1.18 kernel: small algorithm helpers.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_ALG_H
#define MS2_SF_KERNEL_ALG_H

#include "sf_types.h"

namespace Scaleform { namespace Alg {

template<class T> inline T Min(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T Max(T a, T b) { return (b < a) ? a : b; }

// Index of the highest set bit per byte value (data table in the exe).
extern const UByte UpperBitTable[256];

// Highest set bit of a 64-bit value: split into halves, quarters, then one table lookup.
inline UByte UpperBit(UPInt v)
{
    if (v & 0xFFFFFFFF00000000)
    {
        if (v & 0xFFFF000000000000)
            return (v & 0xFF00000000000000) ? UpperBitTable[(v >> 56)] + 56
                                            : UpperBitTable[(v >> 48) & 0xFF] + 48;
        return (v & 0xFF0000000000) ? UpperBitTable[(v >> 40) & 0xFF] + 40
                                    : UpperBitTable[(v >> 32) & 0xFF] + 32;
    }
    if (v & 0xFFFF0000)
        return (v & 0xFF000000) ? UpperBitTable[(v >> 24)] + 24
                                : UpperBitTable[(v >> 16) & 0xFF] + 16;
    return (v & 0xFF00) ? UpperBitTable[(v >> 8) & 0xFF] + 8
                        : UpperBitTable[v & 0xFF];
}

template<class T>
inline void Swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

// Array view of a plain element buffer for the sort templates.
template<class T>
class ArrayAdaptor
{
public:
    typedef T ValueType;

    ArrayAdaptor() : Data(0), Size(0) {}
    ArrayAdaptor(T* ptr, UPInt size) : Data(ptr), Size(size) {}

    UPInt    GetSize() const { return Size; }
    const T& operator[](UPInt i) const { return Data[i]; }
    T&       operator[](UPInt i) { return Data[i]; }

private:
    T*    Data;
    UPInt Size;
};

// Sorts the elements [start, end) of arr by less: quicksort with a median of three pivot and an explicit range
// stack, insertion sort for short ranges. Returns false and stops when a partition scan leaves the range, which only
// an inconsistent less (a script compare function) causes.
template<class ArrayT, class Less>
bool QuickSortSlicedSafe(ArrayT& arr, UPInt start, UPInt end, Less less)
{
    enum { InsertionSortMax = 9 };

    if (end - start < 2)
        return true;

    SPInt  ranges[80];
    SPInt* ptop = ranges;
    SPInt  lo   = (SPInt)start;
    SPInt  hi   = (SPInt)end;

    for (;;)
    {
        SPInt count = hi - lo;
        SPInt i, j;
        if (count > InsertionSortMax)
        {
            Swap(arr[lo], arr[lo + count / 2]);

            i = lo + 1;
            j = hi - 1;
            if (less(arr[j], arr[i]))
                Swap(arr[j], arr[i]);
            if (less(arr[lo], arr[i]))
                Swap(arr[lo], arr[i]);
            if (less(arr[j], arr[lo]))
                Swap(arr[j], arr[lo]);

            for (;;)
            {
                do
                {
                    if (++i >= hi)
                        return false;
                } while (less(arr[i], arr[lo]));
                do
                {
                    if (--j < 0)
                        return false;
                } while (less(arr[lo], arr[j]));
                if (i > j)
                    break;
                Swap(arr[i], arr[j]);
            }
            Swap(arr[lo], arr[j]);

            // Keep sorting the smaller part, remember the larger one.
            if (j - lo > hi - i)
            {
                ptop[0] = lo;
                ptop[1] = j;
                lo      = i;
            }
            else
            {
                ptop[0] = i;
                ptop[1] = hi;
                hi      = j;
            }
            ptop += 2;
        }
        else
        {
            // Insertion sort: j trails i by one before each insertion.
            for (j = lo, i = lo + 1; i < hi; j = i, ++i)
            {
                for (; less(arr[j + 1], arr[j]); --j)
                {
                    Swap(arr[j + 1], arr[j]);
                    if (j == lo)
                        break;
                }
            }
            if (ptop <= ranges)
                return true;
            ptop -= 2;
            lo = ptop[0];
            hi = ptop[1];
        }
    }
}

template<class ArrayT, class Less>
bool QuickSortSafe(ArrayT& arr, Less less)
{
    return QuickSortSlicedSafe(arr, 0, arr.GetSize(), less);
}

// (appended for the display list, sfr_gfx_06c)
// First index in [start, end) whose element is not less than val (binary search over a sorted range).
template<class ArrayT, class Value, class Less>
UPInt LowerBoundSliced(const ArrayT& arr, UPInt start, UPInt end, const Value& val, Less less)
{
    SPInt first = (SPInt)start;
    SPInt len   = (SPInt)(end - start);
    while (len > 0)
    {
        SPInt half   = len >> 1;
        SPInt middle = first + half;
        if (less(arr[middle], val))
        {
            first = middle + 1;
            len   = len - half - 1;
        }
        else
            len = half;
    }
    return (UPInt)first;
}

template<class ArrayT, class Value, class Less>
UPInt LowerBound(const ArrayT& arr, const Value& val, Less less)
{
    return LowerBoundSliced(arr, 0, arr.GetSize(), val, less);
}

// (appended for the timeline snapshot, sfr_gfx_05)
// First index in [start, end) whose element val is less than (binary search over a sorted range).
template<class ArrayT, class Value, class Less>
UPInt UpperBoundSliced(const ArrayT& arr, UPInt start, UPInt end, const Value& val, Less less)
{
    SPInt first = (SPInt)start;
    SPInt len   = (SPInt)(end - start);
    while (len > 0)
    {
        SPInt half   = len >> 1;
        SPInt middle = first + half;
        if (less(val, arr[middle]))
            len = half;
        else
        {
            first = middle + 1;
            len   = len - half - 1;
        }
    }
    return (UPInt)first;
}

template<class ArrayT, class Value, class Less>
UPInt UpperBound(const ArrayT& arr, const Value& val, Less less)
{
    return UpperBoundSliced(arr, 0, arr.GetSize(), val, less);
}

// (appended for the static text, sfr_gfx_05d)
template<class T> SF_INLINE const T Abs(const T v) { return (v >= 0) ? v : -v; }

}} // namespace Scaleform::Alg

#endif
