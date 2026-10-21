// Recovered Scaleform 4.1.18 Render Text: the character helpers and number readers of the SGML (HTML) parser that the
// style sheet parser shares. Only these static helpers are recovered so far.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_SGMLPARSER_H
#define MS2_SF_RENDER_TEXT_SGMLPARSER_H

#include <ctype.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_std.h"

namespace Scaleform { namespace Render { namespace Text {

template<class Char>
class SGMLCharIter
{
public:
    static bool   IsDigit(UInt32 c)  { return isdigit((int)c) != 0; }
    static bool   IsXDigit(UInt32 c) { return isxdigit((int)c) != 0; }
    static UInt32 ToLower(UInt32 c)  { return SFtowlower((wchar_t)c); }

    // Case-insensitive compare of at most len characters of wstr with the ASCII str; when one string runs out
    // first, the difference of the lengths.
    static int StrCompare(const Char* wstr, const char* str, UPInt len);
};

template<class Char>
int SGMLCharIter<Char>::StrCompare(const Char* wstr, const char* str, UPInt len)
{
    if (len)
    {
        SPInt       count  = (SPInt)len;
        const char* pstart = str;
        int         wc, c;
        do
        {
            wc = (int)ToLower((UInt32)*wstr++);
            c  = (int)ToLower((UInt32)*str++);
        } while (--len && wc && wc == c && *str);

        if (wc == c && (len || *str))
            return (int)count - (int)SFstrlen(pstart);
        return wc - c;
    }
    else
        return -(int)SFstrlen(str);
}

template<class Char>
class SGMLParser
{
public:
    static bool ParseHexInt(UInt32* pdestVal, const Char* pstr, UPInt len);
    static bool ParseFloat(float* pdestVal, const Char* pstr, UPInt len);
};

template<class Char>
bool SGMLParser<Char>::ParseHexInt(UInt32* pdestVal, const Char* pstr, UPInt len)
{
    if (!len)
        return false;
    UInt32 v = 0;
    for (UPInt i = 0; i < len; ++i, ++pstr)
    {
        if (!SGMLCharIter<Char>::IsXDigit(*pstr))
            return false;
        v <<= 4;
        Char c = (Char)SGMLCharIter<Char>::ToLower(*pstr);
        if (c >= '0' && c <= '9')
            v |= (c - '0') & 0xF;
        else if (c >= 'a' && c <= 'f')
            v |= ((c - 'a') & 0xF) + 10;
    }
    *pdestVal = v;
    return true;
}

// A decimal number with an optional sign; '.' or ',' separates the fraction.
template<class Char>
__declspec(noinline) bool SGMLParser<Char>::ParseFloat(float* pdestVal, const Char* pstr, UPInt len)
{
    if (!len)
        return false;
    const Char* p    = pstr;
    const Char* pend = pstr + len;
    double      v = 0, sign = 1;
    if (*p == '-')
    {
        sign = -1;
        ++p;
    }
    else if (*p == '+')
        ++p;

    for (; p < pend && *p != '.' && *p != ','; ++p)
    {
        if (!SGMLCharIter<Char>::IsDigit(*p))
            return false;
        v = v * 10 + (*p - '0');
    }
    if (p < pend && (*p == '.' || *p == ','))
    {
        double frac = 0;
        for (++p; p < pend; ++p)
        {
            if (!SGMLCharIter<Char>::IsDigit(*p))
                return false;
            frac += (*p - '0');
            frac *= 0.1;
        }
        v += frac;
    }
    *pdestVal = (float)(v * sign);
    return true;
}

}}} // namespace Scaleform::Render::Text

#endif
