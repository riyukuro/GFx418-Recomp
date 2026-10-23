// Recovered Scaleform 4.1.18 Render Text: the character helpers and number readers of the SGML (HTML) parser that the
// style sheet parser shares. Only these static helpers are recovered so far.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_SGMLPARSER_H
#define MS2_SF_RENDER_TEXT_SGMLPARSER_H

#include <ctype.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform { namespace Render { namespace Text {

// (appended for sfr_render_05i) where the pull parser stands; FINISHED is or-ed in once a part was read
enum SGMLParserState
{
    SGMLPS_NONE,
    SGMLPS_ERROR,
    SGMLPS_START_ELEMENT,
    SGMLPS_CONTENT,
    SGMLPS_END_ELEMENT,
    SGMLPS_EMPTY_ELEMENT,
    SGMLPS_EMPTY_ELEMENT_NAME_END,
    SGMLPS_START_ELEMENT_ATTR,
    SGMLPS_START_ELEMENT_ATTR_VALUE,
    SGMLPS_START_ELEMENT_END_OF_ATTRS,
    SGMLPS_FINISHED               = 0x8000,
    SGMLPS_EMPTY_ELEMENT_FINISHED = SGMLPS_EMPTY_ELEMENT | SGMLPS_FINISHED,
    SGMLPS_START_ELEMENT_FINISHED = SGMLPS_START_ELEMENT | SGMLPS_FINISHED,
    SGMLPS_END_ELEMENT_FINISHED   = SGMLPS_END_ELEMENT | SGMLPS_FINISHED
};

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

    // (appended for sfr_render_05i) the cursor over the markup: the current character (decoded from an entity
    // while content is parsed) and where the next one starts
private:
    const Char* pCurChar;
    const Char* pNextChar;
    const Char* pEnd;
    UInt32      CurChar;
    bool        DoContentParsing;

    UInt32 DecodeCurrentChar();   // per character type
    UInt32 DecodeEscapedChar();

public:
    SGMLCharIter(const Char* p, UPInt size)
        : pCurChar(p), pNextChar(p), pEnd(p + size), CurChar(0), DoContentParsing(false)
    {
        operator++();
    }

    bool        IsFinished() const       { return pCurChar >= pEnd; }
    UInt32      operator*() const        { return CurChar; }
    void        operator++();
    const Char* GetCurCharPtr() const    { return pCurChar; }
    unsigned    GetCurCharLength() const { return (unsigned)(pNextChar - pCurChar); }
    // an entity reference ('&...;') counts only inside content and attribute values
    bool        IsEscapedChar() const    { return DoContentParsing && *pCurChar == '&'; }
    void StartContentParsing()
    {
        bool was = DoContentParsing;
        DoContentParsing = true;
        if (!was && IsEscapedChar())
            DecodeEscapedChar();
    }
    void EndContentParsing() { DoContentParsing = false; }

    static int  EncodeCharTo(UInt32 uniChar, Char* pdestBuf);   // per character type; returns the length
    static bool IsSpace(UInt32 c);
    static bool IsAlphaNum(UInt32 c) { return SFiswalnum((wchar_t)c) != 0; }
    // Case-insensitive compare of two counted strings; the length difference when one is a prefix of the other.
    static int  StrCompare(const Char* dst, UPInt dstlen, const Char* src, UPInt srclen);
};

template<>
inline UInt32 SGMLCharIter<wchar_t>::DecodeCurrentChar()
{
    if (pCurChar >= pEnd)
        return 0;
    CurChar   = *pCurChar;
    pNextChar = pCurChar + 1;
    return CurChar;
}

template<>
inline int SGMLCharIter<wchar_t>::EncodeCharTo(UInt32 uniChar, wchar_t* pdestBuf)
{
    *pdestBuf = (wchar_t)uniChar;
    return 1;
}

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

    // (appended for sfr_render_05i) the pull parser itself: GetNext steps to the next element / content and the
    // Parse* calls read it; names and values with entities are unescaped into pBuffer
    static bool ParseInt(int* pdestVal, const Char* pstr, UPInt len);
    static int  StrCompare(const Char* wstr, const char* str, UPInt len)
    {
        return SGMLCharIter<Char>::StrCompare(wstr, str, len);
    }
    static int  StrCompare(const Char* pstr1, UPInt len1, const Char* pstr2, UPInt len2)
    {
        return SGMLCharIter<Char>::StrCompare(pstr1, len1, pstr2, len2);
    }

protected:
    MemoryHeap*        pHeap;
    int                CurState;
    SGMLCharIter<Char> Iter;
    Char*              pBuffer;
    UPInt              BufSize;
    UPInt              BufPos;
    bool               CondenseWhite;

    void SkipName();
    void SkipSpaces();
    void SkipComment();
    void SkipAttribute();
    void ParseName(const Char** ppname, UPInt* plen);

public:
    SGMLParser(MemoryHeap* pheap, const Char* phtml, UPInt htmlSize)
        : pHeap(pheap), CurState(SGMLPS_NONE), Iter(phtml, htmlSize), pBuffer(0), BufSize(0), BufPos(0),
          CondenseWhite(false)
    {
    }
    ~SGMLParser() { SF_HEAP_FREE(pHeap, pBuffer); }

    void ResetBuf() { BufPos = 0; }
    void AppendToBuf(const Char* pstr, UPInt len);
    void AppendCharToBuf(UInt32 uniChar);
    int  GetNext();
    bool GetNextAttribute(const Char** ppattrName, UPInt* pattrNameSz);
    bool GetNextAttributeValue(const Char** ppattrValue, UPInt* pattrValueSz);
    bool ParseStartElement(const Char** ppelemName, UPInt* pelemLen);
    bool ParseEndElement(const Char** ppelemName, UPInt* pelemLen);
    bool ParseContent(const Char** ppcontent, UPInt* pcontentSize);
    bool HasAttributes() const { return CurState == SGMLPS_START_ELEMENT_ATTR; }
    void SetCondenseWhite()    { CondenseWhite = true; }
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
