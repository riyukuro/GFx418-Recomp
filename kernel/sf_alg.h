// Recovered Scaleform GFx 4.1.18: small algorithms (min/max/swap, bit scans over the byte lookup tables of SF_Alg).
#ifndef MS2_SF_KERNEL_ALG_H
#define MS2_SF_KERNEL_ALG_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Alg {

template<class T> SF_INLINE void Swap(T& a, T& b) { T t = a; a = b; b = t; }
template<class T> SF_INLINE const T Min(const T a, const T b) { return (a < b) ? a : b; }
template<class T> SF_INLINE const T Max(const T a, const T b) { return (b < a) ? a : b; }
template<class T> SF_INLINE const T Clamp(const T v, const T minVal, const T maxVal) { return Max<T>(minVal, Min<T>(v, maxVal)); }
template<class T> SF_INLINE int Chop(T f) { return (int)f; }
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
template<class T> SF_INLINE const T PMin(const T a, const T b) { return (a < b) ? a : b; }   // pointer-sized min/max
template<class T> SF_INLINE const T PMax(const T a, const T b) { return (b < a) ? a : b; }
inline bool IsMax(UPInt v) { return v == SF_MAX_UPINT; }
template<class T> SF_INLINE const T Abs(const T v) { return (v >= 0) ? v : -v; }
// round half away from zero
template<class T> SF_INLINE int IRound(const T a) { return (a > 0.0) ? (int)(a + 0.5) : (int)(a - 0.5); }
template<class T> SF_INLINE unsigned URound(const T a) { return (unsigned)(a + 0.5); }

// binary search in arr[start, end): the first index whose element is not less than val
template<class Array, class Value, class Less>
UPInt LowerBoundSliced(const Array& arr, UPInt start, UPInt end, const Value& val, Less less)
{
    SPInt first = (SPInt)start;
    SPInt count = (SPInt)(end - start);
    while (count > 0)
    {
        SPInt step = count >> 1;
        if (less(arr[first + step], val))
        {
            first += step + 1;
            count -= step + 1;
        }
        else
            count = step;
    }
    return (UPInt)first;
}

// binary search over the whole array
template<class Array, class Value, class Less>
UPInt LowerBound(const Array& arr, const Value& val, Less less)
{
    return LowerBoundSliced(arr, 0, arr.GetSize(), val, less);
}

// index of the highest / lowest set bit of a byte (0 for 0)
extern const UByte UpperBitTable[256];
extern const UByte LowerBitTable[256];

// highest set bit, by byte lookups (val must be nonzero)
inline UByte UpperBit(UPInt val)
{
    if (val & 0xFFFFFFFF00000000)
    {
        if (val & 0xFFFF000000000000)
            return (val & 0xFF00000000000000) ? UpperBitTable[(val >> 56)] + 56
                                              : UpperBitTable[(val >> 48) & 0xFF] + 48;
        return (val & 0xFF0000000000) ? UpperBitTable[(val >> 40) & 0xFF] + 40
                                      : UpperBitTable[(val >> 32) & 0xFF] + 32;
    }
    else
    {
        if (val & 0xFFFF0000)
            return (val & 0xFF000000) ? UpperBitTable[(val >> 24)] + 24 : UpperBitTable[(val >> 16) & 0xFF] + 16;
        return (val & 0xFF00) ? UpperBitTable[(val >> 8) & 0xFF] + 8 : UpperBitTable[(val) & 0xFF];
    }
}

// lowest set bit, by byte lookups (val must be nonzero)
inline UByte LowerBit(UPInt val)
{
    if (val & 0xFFFFFFFF)
    {
        if (val & 0xFFFF)
            return (val & 0xFF) ? LowerBitTable[val & 0xFF] : LowerBitTable[(val >> 8) & 0xFF] + 8;
        return (val & 0xFF0000) ? LowerBitTable[(val >> 16) & 0xFF] + 16 : LowerBitTable[(val >> 24) & 0xFF] + 24;
    }
    else
    {
        if (val & 0xFFFF00000000)
            return (val & 0xFF00000000) ? LowerBitTable[(val >> 32) & 0xFF] + 32
                                        : LowerBitTable[(val >> 40) & 0xFF] + 40;
        return (val & 0xFF000000000000) ? LowerBitTable[(val >> 48) & 0xFF] + 48
                                        : LowerBitTable[(val >> 56) & 0xFF] + 56;
    }
}

}}  // namespace Scaleform::Alg

#endif
