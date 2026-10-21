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

}} // namespace Scaleform::Alg

#endif
