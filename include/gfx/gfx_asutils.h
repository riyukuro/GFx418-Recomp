// Recovered Scaleform GFx 4.1.18: GFx_ASUtils (URL escaping of the AS2 and AS3 builtins, ECMA white space, and the
// NumberUtil number <-> text conversions shared by both VMs). Shared header of the src/ms2/scaleform units (sfr lane):
// append, do not reorder. Bodies: sfr_gfx_05e.cpp.
#ifndef MS2_SF_GFX_ASUTILS_H
#define MS2_SF_GFX_ASUTILS_H

#include "../kernel/sf_types.h"
#include "../kernel/sf_string.h"

namespace Scaleform { namespace GFx {

typedef double Double;

namespace ASUtils {

// AS2 escape(): every byte outside escapeMask (one bit per 7-bit character, mask[c / 32] bit c % 32) becomes %XX.
void EscapeWithMask(const char* psrc, UPInt length, String* pescapedStr, const unsigned* escapeMask);
void EscapePath(const char* psrc, UPInt length, String* pescapedStr);
void Escape(const char* psrc, UPInt length, String* pescapedStr);
// AS2 unescape(): %XX pairs (either case) back to bytes; an invalid pair is dropped.
void Unescape(const char* psrc, UPInt length, String* punescapedStr);

// ECMA-262 white space and line terminators, the Unicode Zs separators included.
bool IsWhiteSpace(UInt32 c);
// Index of the first character of str that is not white space.
UInt32 SkipWhiteSpace(const String& str);
const char* SkipWhiteSpace(const char* str, UPInt len);

// AS3 escape() / encodeURI() / encodeURIComponent() / unescape(): code points above 0xff are written as %uXXXX and
// %uXXXX / %XX are decoded back to UTF-8. Unescape fails (false) on a % that starts no hex sequence.
namespace AS3 {
void EscapeWithMask(const char* psrc, UPInt length, String& escapedStr, const unsigned* escapeMask);
void Escape(const char* psrc, UPInt length, String& escapedStr);
void EncodeURI(const char* psrc, UPInt length, String& escapedStr);
void EncodeURIComponent(const char* psrc, UPInt length, String& escapedStr);
bool Unescape(const char* psrc, UPInt length, String& unescapedStr);
} // namespace AS3

} // namespace ASUtils

namespace NumberUtil {

Double SF_CDECL NaN();
Double SF_CDECL POSITIVE_INFINITY();
Double SF_CDECL NEGATIVE_INFINITY();
Double SF_CDECL MIN_VALUE();
Double SF_CDECL MAX_VALUE();
Double SF_CDECL POSITIVE_ZERO();
Double SF_CDECL NEGATIVE_ZERO();

inline bool IsNaN(Double v)
{
    union { Double D; UInt64 I; } u;
    u.D = v;
    return (u.I & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL && (u.I & 0x000FFFFFFFFFFFFFULL) != 0;
}
inline bool IsPOSITIVE_INFINITY(Double v)
{
    union { Double D; UInt64 I; } u;
    u.D = v;
    return u.I == 0x7FF0000000000000ULL;
}
inline bool IsNEGATIVE_INFINITY(Double v)
{
    union { Double D; UInt64 I; } u;
    u.D = v;
    return u.I == 0xFFF0000000000000ULL;
}
inline bool IsNaNOrInfinity(Double v)
{
    union { Double D; UInt64 I; } u;
    u.D = v;
    return (u.I & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL;
}

bool IsPOSITIVE_ZERO(Double v);
bool IsNEGATIVE_ZERO(Double v);

// Number.toString(): radix > 0 is the radix (2, 8, 16 print the integer part), radix <= 0 the precision (-radix
// significant digits, at most 14). Returns a pointer into destStr.
const char* ToString(Double value, char destStr[], size_t destStrSize, int radix = 10);
// Writes value right-aligned into destStr and returns its first character.
const char* IntToString(SInt32 value, char destStr[], size_t destStrSize, int radix);
const char* IntToString(SInt32 value, char destStr[], size_t destStrSize);

// parseInt() / parseFloat(); *endIndex receives the byte offset after the parsed text.
Double StringToInt(const char* str, UInt32 strLen, SInt32 radix, UInt32* endIndex);
Double StringToDouble(const char* str, UInt32 strLen, UInt32* endIndex);

} // namespace NumberUtil

}} // namespace Scaleform::GFx

#endif
