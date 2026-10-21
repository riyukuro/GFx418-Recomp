// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_Std (C library wrappers and
// the Unicode case mapping). Our own source, written from the exe (the leaked SDK copies were only used to name things
// and to compare layouts). Queue unit sfr_kernel_02 is split along its original sources (sfr_kernel_02 / 02b ...).
// The case tables are data of the exe and are not reproduced here: declared extern, bound by symbols-manual rows.
// MS2-UNIT: sfr_kernel_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a4900-0x1425a4d00 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include <locale.h>

namespace Scaleform {

// Locale independent strtod: the decimal separator of the C locale is swapped in before converting.
double SF_CDECL SFstrtod(const char* string, char** tailptr)
{
    const char decimalPoint = *localeconv()->decimal_point;
    if (decimalPoint != '.')
    {
        char buffer[348];
        SFstrcpy(buffer, sizeof(buffer), string);
        for (char* p = buffer; *p != 0; p++)
            if (*p == '.')
            {
                *p = decimalPoint;
                break;
            }
        return strtod(buffer, tailptr);
    }
    return strtod(string, tailptr);
}

int SF_CDECL SFstricmp(const char* a, const char* b)
{
    return _stricmp(a, b);
}

wchar_t* SF_CDECL SFwcscpy(wchar_t* dest, UPInt destsize, const wchar_t* src)
{
    wcscpy_s(dest, destsize, src);
    return dest;
}

wchar_t* SF_CDECL SFwcsncpy(wchar_t* dest, UPInt destsize, const wchar_t* src, UPInt count)
{
    wcsncpy_s(dest, destsize, src, count);
    return dest;
}

wchar_t* SF_CDECL SFwcscat(wchar_t* dest, UPInt destsize, const wchar_t* src)
{
    wcscat_s(dest, destsize, src);
    return dest;
}

UPInt SF_CDECL SFwcslen(const wchar_t* str)
{
    return wcslen(str);
}

int SF_CDECL SFwcscmp(const wchar_t* a, const wchar_t* b)
{
    return wcscmp(a, b);
}

// sorted (key, mapped) pairs, ended by a {0xFFFF, 0} sentinel that the searches leave out
struct GUnicodePairType
{
    UInt16 Key, Value;
};

static inline bool CmpUnicodeKey(const GUnicodePairType& a, UInt16 key)
{
    return a.Key < key;
}

extern const UInt16           UnicodeToUpperBits[];
extern const UInt16           UnicodeToLowerBits[];
extern const GUnicodePairType UnicodeToUpperTable[641];
extern const GUnicodePairType UnicodeToLowerTable[677];

int SF_CDECL SFtowupper(wchar_t charCode)
{
    if (!UnicodeCharIs(UnicodeToUpperBits, charCode))
        return charCode;
    UPInt n = sizeof(UnicodeToUpperTable) / sizeof(UnicodeToUpperTable[0]) - 1;
    return UnicodeToUpperTable[Alg::LowerBoundSliced(UnicodeToUpperTable, 0, n, (UInt16)charCode, CmpUnicodeKey)].Value;
}

int SF_CDECL SFtowlower(wchar_t charCode)
{
    if (!UnicodeCharIs(UnicodeToLowerBits, charCode))
        return charCode;
    UPInt n = sizeof(UnicodeToLowerTable) / sizeof(UnicodeToLowerTable[0]) - 1;
    return UnicodeToLowerTable[Alg::LowerBoundSliced(UnicodeToLowerTable, 0, n, (UInt16)charCode, CmpUnicodeKey)].Value;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??$LowerBoundSliced@$$BY0CKF@UGUnicodePairType@Scaleform@@GP6A_NAEBU12@G@Z@Alg@Scaleform@@YA_KAEAY0CKF@$$CBUGUnicodePairType@1@_K1AEBGP6A_NAEBU21@G@Z@Z 0x1425a4900
// MS2-PIN: ??$LowerBoundSliced@$$BY0CIB@UGUnicodePairType@Scaleform@@GP6A_NAEBU12@G@Z@Alg@Scaleform@@YA_KAEAY0CIB@$$CBUGUnicodePairType@1@_K1AEBGP6A_NAEBU21@G@Z@Z 0x1425a49a0
// MS2-PIN: ?SFstrtod@Scaleform@@YANPEBDPEAPEAD@Z 0x1425a4a70
// MS2-PIN: ?SFtowlower@Scaleform@@YAH_W@Z 0x1425a4b30
// MS2-PIN: ?SFtowupper@Scaleform@@YAH_W@Z 0x1425a4bc0
// MS2-PIN: ?SFwcscat@Scaleform@@YAPEA_WPEA_W_KPEB_W@Z 0x1425a4c50
// MS2-PIN: ?SFwcscmp@Scaleform@@YAHPEB_W0@Z 0x1425a4c70
// MS2-PIN: ?SFwcscpy@Scaleform@@YAPEA_WPEA_W_KPEB_W@Z 0x1425a4c90
// MS2-PIN: ?SFwcslen@Scaleform@@YA_KPEB_W@Z 0x1425a4cc0
// MS2-PIN: ?SFwcsncpy@Scaleform@@YAPEA_WPEA_W_KPEB_W1@Z 0x1425a4ce0
// MS2-PIN: ?SFstricmp@Scaleform@@YAHPEBD0@Z 0x1425a4a50
