// Recovered Scaleform 4.1.18 kernel: character class helpers.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_STD_H
#define MS2_SF_KERNEL_STD_H

#include "sf_types.h"
#include <stdarg.h>
#include <stdio.h>

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

inline int SF_CDECL SFtolower(int c) { return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c; }

int SF_CDECL SFtowlower(wchar_t ch);

UPInt SF_CDECL    SFwcslen(const wchar_t* str);
// Copies at most count characters of src into dest (destsize characters) and terminates it.
wchar_t* SF_CDECL SFwcsncpy(wchar_t* dest, UPInt destsize, const wchar_t* src, UPInt count);

// Truncating printf into a fixed buffer; returns the length written. Inline: each unit that prints keeps its own
// copy (as3_01 at 0x1423dd130).
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

// Locale independent strtod (exe 0x1425a4a70).
double SF_CDECL SFstrtod(const char* string, char** tailptr);

inline int SF_CDECL SFtoupper(int c) { return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c; }

// (appended for the static text, sfr_gfx_05d)
inline const char* SF_CDECL SFstrchr(const char* s, char c) { return strchr(s, c); }
inline char* SF_CDECL       SFstrchr(char* s, char c)       { return strchr(s, c); }

// (appended for GFx Text_EditorKit, sfr_gfx_07)
extern const UInt16 UnicodeAlnumBits[];

inline int SF_CDECL SFiswalnum(wchar_t ch) { return UnicodeCharIs(UnicodeAlnumBits, ch); }

int SF_CDECL SFtowupper(wchar_t ch);

// (appended for GFx FontManager, sfr_gfx_07g)
inline UPInt SF_CDECL SFstrlen(const char* str) { return strlen(str); }
// (appended for GFx FontData, sfh) SF_MSVC_SAFESTRING form
inline char* SF_CDECL SFstrcpy(char* dest, UPInt destsize, const char* src)
{
    strcpy_s(dest, destsize, src);
    return dest;
}

// (appended for GFx::Value::operator==, fq1) the game's /Od units keep SFstrcmp as an out-of-line COMDAT; SFwcscmp is
// the kernel's own (exe 0x1425a4c70, sfr_kernel_02).
#ifndef MS2_SF_SFSTRCMP_DEFINED   // also in sf_string.h and the other sf_std.h
#define MS2_SF_SFSTRCMP_DEFINED
inline int SF_CDECL SFstrcmp(const char* a, const char* b) { return strcmp(a, b); }
#endif
int SF_CDECL SFwcscmp(const wchar_t* a, const wchar_t* b);
// (appended for GFxClipboard::OnTextStore, fq1) copies src with its terminator into dest (destsize characters).
wchar_t* SF_CDECL SFwcscpy(wchar_t* dest, UPInt destsize, const wchar_t* src);

} // namespace Scaleform

#endif
