// Recovered Scaleform GFx 4.1.18: C library wrappers (MSVC secure CRT variants) and the Unicode character tables.
#ifndef MS2_SF_KERNEL_STD_H
#define MS2_SF_KERNEL_STD_H

#include "ms2/scaleform/kernel/sf_types.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>

namespace Scaleform {

inline char* SF_CDECL SFitoa(int val, char* dest, UPInt destsize, int radix)
{
    _itoa_s(val, dest, destsize, radix);
    return dest;
}
inline UPInt SF_CDECL SFstrlen(const char* str) { return strlen(str); }
inline char* SF_CDECL SFstrcpy(char* dest, UPInt destsize, const char* src)
{
    strcpy_s(dest, destsize, src);
    return dest;
}
inline char* SF_CDECL SFstrncpy(char* dest, UPInt destsize, const char* src, UPInt count)
{
    strncpy_s(dest, destsize, src, count);
    return dest;
}
inline char* SF_CDECL SFstrcat(char* dest, UPInt destsize, const char* src)
{
    strcat_s(dest, destsize, src);
    return dest;
}
inline int SF_CDECL SFstrcmp(const char* a, const char* b) { return strcmp(a, b); }
inline const char* SF_CDECL SFstrchr(const char* s, char c) { return strchr(s, c); }
inline char* SF_CDECL SFstrchr(char* s, char c) { return strchr(s, c); }
inline const char* SFstrrchr(const char* s, char c)
{
    for (UPInt i = SFstrlen(s); i > 0; i--)
        if (s[i] == c)
            return s + i;
    return 0;
}
inline char* SF_CDECL SFstrrchr(char* s, char c)
{
    for (UPInt i = SFstrlen(s); i > 0; i--)
        if (s[i] == c)
            return s + i;
    return 0;
}
inline const UByte* SF_CDECL SFmemrchr(const UByte* s, UPInt size, UByte c)
{
    for (SPInt i = (SPInt)size - 1; i >= 0; i--)
        if (s[i] == c)
            return s + i;
    return 0;
}
double SF_CDECL SFstrtod(const char* string, char** tailptr);
inline long SF_CDECL SFstrtol(const char* s, char** tail, int radix) { return strtol(s, tail, radix); }
inline long SF_CDECL SFstrtoul(const char* s, char** tail, int radix) { return strtoul(s, tail, radix); }
inline int SF_CDECL SFstrncmp(const char* a, const char* b, UPInt n) { return strncmp(a, b, n); }
inline UInt64 SF_CDECL SFstrtouq(const char* s, char** tail, int base) { return _strtoui64(s, tail, base); }
inline SInt64 SF_CDECL SFstrtoq(const char* s, char** tail, int base) { return _strtoi64(s, tail, base); }
inline SInt64 SF_CDECL SFatoq(const char* s) { return _atoi64(s); }
inline UInt64 SF_CDECL SFatouq(const char* s) { return SFstrtouq(s, NULL, 10); }
inline double SF_CDECL SFatof(const char* s) { return atof(s); }
int SF_CDECL SFstricmp(const char* a, const char* b);
int SF_CDECL SFstrnicmp(const char* a, const char* b, UPInt count);

// Truncating printf into a fixed buffer; returns the length written.
inline UPInt SF_CDECL SFsprintf(char* dest, UPInt destsize, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    UPInt ret;
    int rv = _vsnprintf_s(dest, destsize, _TRUNCATE, format, args);
    if (rv == -1)
    {
        dest[destsize - 1] = '\0';
        ret = destsize - 1;
    }
    else
        ret = (UPInt)rv;
    va_end(args);
    return ret;
}
inline UPInt SF_CDECL SFvsprintf(char* dest, UPInt destsize, const char* format, va_list args)
{
    UPInt ret;
    dest[0] = '\0';
    int rv = vsnprintf_s(dest, destsize, _TRUNCATE, format, args);
    if (rv == -1)
    {
        dest[destsize - 1] = '\0';
        ret = destsize - 1;
    }
    else
        ret = (UPInt)rv;
    return ret;
}

wchar_t* SF_CDECL SFwcscpy(wchar_t* dest, UPInt destsize, const wchar_t* src);
wchar_t* SF_CDECL SFwcsncpy(wchar_t* dest, UPInt destsize, const wchar_t* src, UPInt count);
wchar_t* SF_CDECL SFwcscat(wchar_t* dest, UPInt destsize, const wchar_t* src);
UPInt SF_CDECL SFwcslen(const wchar_t* str);
int SF_CDECL SFwcscmp(const wchar_t* a, const wchar_t* b);
int SF_CDECL SFwcsicmp(const wchar_t* a, const wchar_t* b);
inline int SF_CDECL SFwcsicoll(const wchar_t* a, const wchar_t* b) { return ::_wcsicoll(a, b); }
inline int SF_CDECL SFwcscoll(const wchar_t* a, const wchar_t* b) { return wcscoll(a, b); }

// Unicode classification: table[hi byte] = 0 (none), 1 (all) or an offset of 16 bit masks.
inline int SF_CDECL UnicodeCharIs(const UInt16* table, wchar_t ch)
{
    unsigned offset = table[ch >> 8];
    if (offset == 0) return 0;
    if (offset == 1) return 1;
    return (table[offset + ((ch >> 4) & 15)] & (1 << (ch & 15))) != 0;
}
extern const UInt16 UnicodeAlnumBits[];
extern const UInt16 UnicodeAlphaBits[];
extern const UInt16 UnicodeDigitBits[];
extern const UInt16 UnicodeSpaceBits[];
extern const UInt16 UnicodeXDigitBits[];
inline int SF_CDECL SFiswalnum(wchar_t c) { return UnicodeCharIs(UnicodeAlnumBits, c); }
inline int SF_CDECL SFiswalpha(wchar_t c) { return UnicodeCharIs(UnicodeAlphaBits, c); }
inline int SF_CDECL SFiswdigit(wchar_t c) { return UnicodeCharIs(UnicodeDigitBits, c); }
inline int SF_CDECL SFiswspace(wchar_t c) { return UnicodeCharIs(UnicodeSpaceBits, c); }
inline int SF_CDECL SFiswxdigit(wchar_t c) { return UnicodeCharIs(UnicodeXDigitBits, c); }
int SF_CDECL SFtowupper(wchar_t c);
int SF_CDECL SFtowlower(wchar_t c);

inline int SF_CDECL SFtolower(int c) { return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c; }
inline int SF_CDECL SFtoupper(int c) { return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c; }
inline double SF_CDECL SFwcstod(const wchar_t* s, wchar_t** tail) { return wcstod(s, tail); }
inline long SF_CDECL SFwcstol(const wchar_t* s, wchar_t** tail, int radix) { return wcstol(s, tail, radix); }

}  // namespace Scaleform

#endif
