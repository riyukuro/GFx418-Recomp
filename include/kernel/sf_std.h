// Recovered Scaleform 4.1.18 kernel: character class helpers.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_STD_H
#define MS2_SF_KERNEL_STD_H

#include "sf_types.h"

namespace Scaleform {

// Two-level bit table: table[hi byte] is 0 (none of the 256 code points), 1 (all of them) or the index of sixteen
// UInt16 words holding one bit per code point.
inline int SF_CDECL UnicodeCharIs(const UInt16* table, wchar_t ch)
{
    unsigned row = table[ch >> 8];
    if (row == 0)
        return 0;
    if (row == 1)
        return 1;
    return (table[row + ((ch >> 4) & 15)] & (1 << (ch & 15))) != 0;
}

extern const UInt16 UnicodeSpaceBits[];

inline int SF_CDECL SFiswspace(wchar_t ch) { return UnicodeCharIs(UnicodeSpaceBits, ch); }

} // namespace Scaleform

#endif
