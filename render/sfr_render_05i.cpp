// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the HTML parser TU
// (Text_HTMLParser): the SGML pull parser over wide text (SGMLCharIter / SGMLParser<wchar_t>) and
// StyledText::ParseHtml, which turns the HTML subset of Flash text fields into styled paragraphs.
// MS2-UNIT: sfr_render_05i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14267b120-0x14267fce0 .text$mn

#include "ms2/scaleform/include/render/text_sgmlparser.h"
#include "ms2/scaleform/include/render/text_styledtext.h"
#include "ms2/scaleform/include/kernel/sf_utf8util.h"
#include <string.h>

namespace Scaleform { namespace Render { namespace Text {

struct SGMLElementDesc
{
    const char* ElemName;
    int ElemId;
    bool ReqEndElement;
    bool EmptyElement;
    template<class Char> struct Comparable { const Char* Str; UPInt Size; };
    template<class Char> struct Comparator
    {
        static int Less(const SGMLElementDesc& element, const Comparable<Char>& key)
        { return (-SGMLCharIter<Char>::StrCompare(key.Str, element.ElemName, key.Size)) < 0; }
    };
};

// @0x14267ecf0
template<> __declspec(dllexport) int SGMLElementDesc::Comparator<wchar_t>::Less(
    const SGMLElementDesc& element, const SGMLElementDesc::Comparable<wchar_t>& key)
{
    return (-SGMLCharIter<wchar_t>::StrCompare(key.Str, element.ElemName, key.Size)) < 0;
}

// @0x14267dbe0
StyledText::HTMLImageTagInfo::~HTMLImageTagInfo()
{
}

// MS2-FUNCTIONAL: member destruction order and ownership release match; compiler frame differs from the exe.
// @0x14267dc80
HTMLImageTagDesc::~HTMLImageTagDesc()
{
}

// ***** SGMLCharIter

// @0x14267dc50
template<class Char>
void SGMLCharIter<Char>::operator++()
{
    pCurChar = pNextChar;
    if (IsEscapedChar())
        DecodeEscapedChar();
    else
        DecodeCurrentChar();
}

// Reads the entity reference at the cursor: the named ones Flash knows, or a decimal / hex character code. An
// unknown or malformed one is left as a plain '&'.
// MS2-FUNCTIONAL: branch layout of the entity chain and register allocation differ
// @0x14267df60
template<class Char>
UInt32 SGMLCharIter<Char>::DecodeEscapedChar()
{
    if (pCurChar >= pEnd)
        return 0;
    pNextChar = pCurChar;
    if (*pNextChar != '&')
        return CurChar;

    CurChar = *pNextChar;
    ++pNextChar;
    do
    {
        if (pNextChar + 5 <= pEnd)
        {
            if (StrCompare(pNextChar, "quot;", 5) == 0)
            {
                CurChar = '\"';
                pNextChar += 5;
                break;
            }
            else if (StrCompare(pNextChar, "apos;", 5) == 0)
            {
                CurChar = '\'';
                pNextChar += 5;
                break;
            }
            else if (StrCompare(pNextChar, "nbsp;", 5) == 0)
            {
                CurChar = 0xa0;
                pNextChar += 5;
                break;
            }
        }
        if (pNextChar + 4 <= pEnd && StrCompare(pNextChar, "amp;", 4) == 0)
        {
            CurChar = '&';
            pNextChar += 4;
            break;
        }
        if (pNextChar + 3 <= pEnd)
        {
            if (StrCompare(pNextChar, "lt;", 3) == 0)
            {
                CurChar = '<';
                pNextChar += 3;
                break;
            }
            if (StrCompare(pNextChar, "gt;", 3) == 0)
            {
                CurChar = '>';
                pNextChar += 3;
                break;
            }
        }
        if (pNextChar + 2 <= pEnd)
        {
            if (*pNextChar == '#')
            {
                const Char* hash = pNextChar;
                ++pNextChar;
                UInt32 code = 0;
                // (the shipped code lowers the result of the comparison, not the character)
                if (ToLower(*pNextChar == 'x'))
                {
                    for (++pNextChar; pNextChar < pEnd && *pNextChar != ';'; ++pNextChar)
                    {
                        if (!IsXDigit(*pNextChar))
                        {
                            code = ~0u;
                            break;
                        }
                        code <<= 4;
                        Char c = (Char)ToLower(*pNextChar);
                        if (c >= '0' && c <= '9')
                            code |= (c - '0') & 0xF;
                        else if (c >= 'a' && c <= 'f')
                            code |= ((c - 'a') & 0xF) + 10;
                    }
                    if (code != ~0u && *pNextChar == ';')
                        ++pNextChar;
                }
                else if (IsDigit(*pNextChar))
                {
                    for (; pNextChar < pEnd && *pNextChar != ';'; ++pNextChar)
                    {
                        if (!IsDigit(*pNextChar))
                        {
                            code = ~0u;
                            break;
                        }
                        code = code * 10 + (*pNextChar - '0');
                    }
                    if (code != ~0u && *pNextChar == ';')
                        ++pNextChar;
                }
                else
                    code = ~0u;

                if (code != ~0u)
                    CurChar = code;
                else
                    pNextChar = hash;
            }
            break;
        }
    } while (0);
    return CurChar;
}

// @0x14267eca0
template<class Char>
bool SGMLCharIter<Char>::IsSpace(UInt32 c)
{
    return SFiswspace((wchar_t)c) != 0;
}

// MS2-FUNCTIONAL: register allocation and loop rotation differ
// @0x14267fc30
template<class Char>
int SGMLCharIter<Char>::StrCompare(const Char* dst, UPInt dstlen, const Char* src, UPInt srclen)
{
    if (!dstlen)
        return -(int)srclen;
    SPInt dlen = (SPInt)dstlen, slen = (SPInt)srclen;
    int   d, s;
    do
    {
        d = (int)ToLower((UInt32)*dst++);
        s = (int)ToLower((UInt32)*src++);
    } while (--dstlen && d && d == s && --srclen);

    if (d == s && (dstlen || srclen))
        return (int)(dlen - slen);
    return d - s;
}

// ***** SGMLParser

// @0x14267ddc0
template<class Char>
void SGMLParser<Char>::AppendToBuf(const Char* pstr, UPInt len)
{
    if (BufPos + len > BufSize)
    {
        BufSize += len;
        if (!pBuffer)
            pBuffer = (Char*)SF_HEAP_ALLOC(pHeap, BufSize * sizeof(Char), StatRender_Text_Mem);
        else
            pBuffer = (Char*)SF_REALLOC(pBuffer, BufSize * sizeof(Char), StatRender_Text_Mem);
    }
    memcpy(pBuffer + BufPos, pstr, len * sizeof(Char));
    BufPos += len;
}

// @0x14267dd40
template<class Char>
void SGMLParser<Char>::AppendCharToBuf(UInt32 uniChar)
{
    // room for the longest encoding of one character
    if (BufPos + 6 > BufSize)
    {
        BufSize += 6;
        if (!pBuffer)
            pBuffer = (Char*)SF_HEAP_ALLOC(pHeap, BufSize * sizeof(Char), StatRender_Text_Mem);
        else
            pBuffer = (Char*)SF_REALLOC(pBuffer, BufSize * sizeof(Char), StatRender_Text_Mem);
    }
    BufPos += Iter.EncodeCharTo(uniChar, pBuffer + BufPos);
}

// Finishes whatever part the caller left unread, then classifies what comes next.
// @0x14267e3c0
template<class Char>
int SGMLParser<Char>::GetNext()
{
    if (CurState == SGMLPS_ERROR)
        return SGMLPS_ERROR;

    if (!(CurState & SGMLPS_FINISHED))
    {
        switch (CurState)
        {
        case SGMLPS_START_ELEMENT:
            SkipName();
            // fall through: skip the attributes too
        case SGMLPS_START_ELEMENT_ATTR:
        case SGMLPS_START_ELEMENT_ATTR_VALUE:
            while (CurState == SGMLPS_START_ELEMENT_ATTR || CurState == SGMLPS_START_ELEMENT_ATTR_VALUE)
                SkipAttribute();
            // fall through
        case SGMLPS_START_ELEMENT_END_OF_ATTRS:
            if (*Iter == '>')
            {
                ++Iter;
                CurState = SGMLPS_START_ELEMENT_FINISHED;
            }
            break;
        case SGMLPS_CONTENT:
            while (!Iter.IsFinished() && *Iter != '<')
                ++Iter;
            CurState = SGMLPS_CONTENT | SGMLPS_FINISHED;
            break;
        case SGMLPS_END_ELEMENT:
            while (!Iter.IsFinished() && *Iter != '>')
                ++Iter;
            if (*Iter == '>')
            {
                ++Iter;
                CurState = SGMLPS_END_ELEMENT_FINISHED;
            }
            else
                CurState = SGMLPS_ERROR;
            break;
        default:
            break;
        }
    }
    if (CurState == SGMLPS_ERROR)
        return SGMLPS_ERROR;

    SGMLParserState next = SGMLPS_NONE;
    while (!Iter.IsFinished() && next == SGMLPS_NONE)
    {
        switch (*Iter)
        {
        case 0:
            next = SGMLPS_ERROR;
            break;
        case '<':
            ++Iter;
            if (*Iter == '!')
                SkipComment();
            else if (*Iter == '/')
            {
                ++Iter;
                next = SGMLPS_END_ELEMENT;
            }
            else
                next = SGMLPS_START_ELEMENT;
            break;
        case '/':
            // "/>" closes an empty element right after its name or attributes
            if (CurState == SGMLPS_START_ELEMENT_END_OF_ATTRS || CurState == SGMLPS_EMPTY_ELEMENT_NAME_END)
            {
                ++Iter;
                if (*Iter == '>')
                {
                    ++Iter;
                    next = SGMLPS_EMPTY_ELEMENT_FINISHED;
                }
                else
                    next = SGMLPS_ERROR;
            }
            else
                next = SGMLPS_CONTENT;
            break;
        default:
            next = SGMLPS_CONTENT;
            break;
        }
    }
    CurState = (next == SGMLPS_NONE) ? SGMLPS_FINISHED : next;
    return CurState;
}

// @0x14267e860
template<class Char>
bool SGMLParser<Char>::GetNextAttribute(const Char** ppattrName, UPInt* pattrNameSz)
{
    if (CurState == SGMLPS_ERROR)
        return false;
    if (CurState == SGMLPS_START_ELEMENT_ATTR_VALUE)
        SkipAttribute();

    bool found = false;
    while (CurState == SGMLPS_START_ELEMENT_ATTR && !Iter.IsFinished())
    {
        ParseName(ppattrName, pattrNameSz);
        SkipSpaces();
        if (Iter.IsFinished())
            continue;
        if (*Iter == '=')
        {
            ++Iter;
            SkipSpaces();
            CurState = SGMLPS_START_ELEMENT_ATTR_VALUE;
            found    = true;
        }
        else
            SkipAttribute();
    }
    if (Iter.IsFinished())
        CurState = SGMLPS_ERROR;
    return found;
}

// A quoted value; entities in it are decoded into the buffer.
// @0x14267ea00
template<class Char>
bool SGMLParser<Char>::GetNextAttributeValue(const Char** ppattrValue, UPInt* pattrValueSz)
{
    bool found = false;
    if (CurState == SGMLPS_START_ELEMENT_ATTR_VALUE)
    {
        UInt32 quote = *Iter;
        if (quote == '\"' || quote == '\'')
        {
            ++Iter;
            *ppattrValue  = Iter.GetCurCharPtr();
            *pattrValueSz = 0;
            bool inBuf    = false;
            Iter.StartContentParsing();
            while (!Iter.IsFinished() && *Iter != quote)
            {
                if (Iter.IsEscapedChar())
                {
                    if (!inBuf)
                    {
                        ResetBuf();
                        AppendToBuf(*ppattrValue, *pattrValueSz);
                        inBuf = true;
                    }
                    AppendCharToBuf(*Iter);
                }
                else if (inBuf)
                    AppendToBuf(Iter.GetCurCharPtr(), Iter.GetCurCharLength());
                else
                    *pattrValueSz += Iter.GetCurCharLength();
                ++Iter;
            }
            Iter.EndContentParsing();
            if (inBuf)
            {
                *ppattrValue  = pBuffer;
                *pattrValueSz = BufPos;
            }
            if (Iter.IsFinished())
                CurState = SGMLPS_ERROR;
            else
            {
                found = true;
                ++Iter;   // the closing quote
                SkipSpaces();
                if (*Iter == '>' || *Iter == '/')
                    CurState = SGMLPS_START_ELEMENT_END_OF_ATTRS;
                else
                    CurState = SGMLPS_START_ELEMENT_ATTR;
            }
        }
        else
            CurState = SGMLPS_ERROR;
    }
    if (Iter.IsFinished())
        CurState = SGMLPS_ERROR;
    return found;
}

// The text up to the next tag; with CondenseWhite each run of white space becomes one blank.
// @0x14267ed10
template<class Char>
bool SGMLParser<Char>::ParseContent(const Char** ppcontent, UPInt* pcontentSize)
{
    if (CurState == SGMLPS_CONTENT)
    {
        *ppcontent    = Iter.GetCurCharPtr();
        *pcontentSize = 0;
        bool inBuf    = false;
        Iter.StartContentParsing();
        while (!Iter.IsFinished() && (*Iter != '<' || Iter.IsEscapedChar()))
        {
            if (Iter.IsSpace(*Iter) && CondenseWhite)
            {
                if (!inBuf)
                {
                    ResetBuf();
                    AppendToBuf(*ppcontent, *pcontentSize);
                    inBuf = true;
                }
                AppendCharToBuf(' ');
                SkipSpaces();
                continue;
            }
            if (Iter.IsEscapedChar())
            {
                if (!inBuf)
                {
                    ResetBuf();
                    AppendToBuf(*ppcontent, *pcontentSize);
                    inBuf = true;
                }
                AppendCharToBuf(*Iter);
            }
            else if (inBuf)
                AppendToBuf(Iter.GetCurCharPtr(), Iter.GetCurCharLength());
            else
                *pcontentSize += Iter.GetCurCharLength();
            ++Iter;
        }
        if (inBuf)
        {
            *ppcontent    = pBuffer;
            *pcontentSize = BufPos;
        }
        if (Iter.IsFinished() || (*Iter == '<' && !Iter.IsEscapedChar()))
            CurState |= SGMLPS_FINISHED;
        else
            CurState = SGMLPS_ERROR;
        Iter.EndContentParsing();
    }
    return CurState != SGMLPS_ERROR;
}

// @0x14267ef80
template<class Char>
bool SGMLParser<Char>::ParseEndElement(const Char** ppelemName, UPInt* pelemLen)
{
    if (CurState != SGMLPS_END_ELEMENT)
        return false;
    ParseName(ppelemName, pelemLen);
    if (*Iter == '>')
    {
        CurState = SGMLPS_END_ELEMENT_FINISHED;
        ++Iter;
        return true;
    }
    CurState = SGMLPS_ERROR;
    return false;
}

// A decimal integer with an optional sign.
// @0x14267f0f0
template<class Char>
bool SGMLParser<Char>::ParseInt(int* pdestVal, const Char* pstr, UPInt len)
{
    if (!len)
        return false;
    int         v = 0, sign = 1;
    const Char* p = pstr;
    if (*p == '-')
    {
        sign = -1;
        ++p;
        --len;
    }
    else if (*p == '+')
    {
        ++p;
        --len;
    }
    for (UPInt i = 0; i < len; ++i, ++p)
    {
        if (!SGMLCharIter<Char>::IsDigit(*p))
            return false;
        v = v * 10 + (*p - '0');
    }
    *pdestVal = v * sign;
    return true;
}

// An element or attribute name; one with entities in it is decoded into the buffer.
// MS2-FUNCTIONAL: clang hoists GetCurCharLength out of the two branches; the exe computes it in each
// @0x14267f190
template<class Char>
void SGMLParser<Char>::ParseName(const Char** ppname, UPInt* plen)
{
    *ppname    = Iter.GetCurCharPtr();
    *plen      = 0;
    bool inBuf = false;
    while (!Iter.IsFinished() && *Iter != '=' && *Iter != '>' && *Iter != '<' && *Iter != '/' &&
           !Iter.IsSpace(*Iter))
    {
        if (Iter.IsEscapedChar())
        {
            if (!inBuf)
            {
                ResetBuf();
                AppendToBuf(*ppname, *plen);
                inBuf = true;
            }
            AppendCharToBuf(*Iter);
        }
        else if (inBuf)
            AppendToBuf(Iter.GetCurCharPtr(), Iter.GetCurCharLength());
        else
            *plen += Iter.GetCurCharLength();
        ++Iter;
    }
    if (inBuf)
    {
        *ppname = pBuffer;
        *plen   = BufPos;
    }
}

// MS2-FUNCTIONAL: instructions match the exe; the gate still reports a difference (likely in the call relocations)
// @0x14267f370
template<class Char>
bool SGMLParser<Char>::ParseStartElement(const Char** ppelemName, UPInt* pelemLen)
{
    if (CurState == SGMLPS_START_ELEMENT)
    {
        ParseName(ppelemName, pelemLen);
        if (*Iter == '>')
        {
            CurState = SGMLPS_START_ELEMENT_FINISHED;
            ++Iter;
        }
        else if (*Iter == '/')
            CurState = SGMLPS_EMPTY_ELEMENT_NAME_END;
        else
        {
            CurState = SGMLPS_START_ELEMENT_ATTR;
            SkipSpaces();
        }
        return true;
    }
    return false;
}

// Steps over one attribute (name, '=', quoted value) without reading it.
// @0x14267f730
template<class Char>
void SGMLParser<Char>::SkipAttribute()
{
    if (CurState == SGMLPS_START_ELEMENT_ATTR)
    {
        SkipSpaces();
        while (!Iter.IsFinished() && Iter.IsAlphaNum(*Iter) && *Iter != '=')
            ++Iter;
        if (Iter.IsFinished())
        {
            CurState = SGMLPS_ERROR;
            return;
        }
        if (*Iter == '=')
        {
            ++Iter;
            SkipSpaces();
            CurState = SGMLPS_START_ELEMENT_ATTR_VALUE;
        }
        else if (*Iter == '/' || *Iter == '>')
            CurState = SGMLPS_START_ELEMENT_END_OF_ATTRS;
        else
            CurState = SGMLPS_ERROR;
    }
    if (CurState == SGMLPS_START_ELEMENT_ATTR_VALUE)
    {
        UInt32 quote = *Iter;
        if (quote != '\"' && quote != '\'')
        {
            CurState = SGMLPS_ERROR;
            return;
        }
        do
            ++Iter;
        while (!Iter.IsFinished() && *Iter != quote);
        if (Iter.IsFinished())
        {
            CurState = SGMLPS_ERROR;
            return;
        }
        ++Iter;
        SkipSpaces();
        if (*Iter == '>' || *Iter == '/')
            CurState = SGMLPS_START_ELEMENT_END_OF_ATTRS;
        else
            CurState = SGMLPS_START_ELEMENT_ATTR;
    }
}

// "<!" ... "-->": counts the dashes before the closing '>'.
// @0x14267f980
template<class Char>
void SGMLParser<Char>::SkipComment()
{
    int dashes = 0;
    while (!Iter.IsFinished() && *Iter != 0 && dashes != 3)
    {
        ++Iter;
        if (*Iter == '-')
        {
            if (dashes < 2)
                ++dashes;
        }
        else if (*Iter == '>')
        {
            if (dashes == 2)
                ++dashes;
        }
        else
            dashes = 0;
    }
    if (!Iter.IsFinished() && dashes == 3)
        ++Iter;
}

// @0x14267faa0
template<class Char>
void SGMLParser<Char>::SkipName()
{
    if (CurState != SGMLPS_START_ELEMENT)
        return;
    while (!Iter.IsFinished() && *Iter != '=' && *Iter != '>' && *Iter != '<' && *Iter != '/' &&
           !Iter.IsSpace(*Iter))
        ++Iter;
}

// @0x14267fb70
template<class Char>
void SGMLParser<Char>::SkipSpaces()
{
    while (!Iter.IsFinished() && Iter.IsSpace(*Iter))
        ++Iter;
}

// Keep the wide overload as the small ABI adapter in the executable. ParseHtmlImpl remains an unrecovered local
// callee while its parser body is being reconstructed from the exe.
extern bool FUN_14267b1c0(StyledText* self, const wchar_t* phtml, UPInt htmlSize,
                          StyledText::HTMLImageTagInfoArray* pimgInfoArr, bool multiline, bool condenseWhite,
                          const StyleManagerBase* pstyleMgr, const TextFormat* txtFmt,
                          const ParagraphFormat* paraFmt);

// @0x14267f0d0
bool StyledText::ParseHtml(const wchar_t* phtml, UPInt htmlSize, HTMLImageTagInfoArray* pimgInfoArr,
                           bool multiline, bool condenseWhite, const StyleManagerBase* pstyleMgr,
                           const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    return FUN_14267b1c0(this, phtml, htmlSize, pimgInfoArr, multiline, condenseWhite,
                         pstyleMgr, txtFmt, paraFmt);
}

// MS2-FUNCTIONAL: decodes UTF-8 to the same UTF-16 buffer and forwards the same parser arguments; compiler frame differs.
// @0x14267eff0
bool StyledText::ParseHtml(const char* phtml, UPInt htmlSize, HTMLImageTagInfoArray* pimgInfoArr,
                           bool multiline, bool condenseWhite, const StyleManagerBase* pstyleMgr,
                           const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    MemoryHeap* heap = Memory::GetGlobalHeap();
    wchar_t* wide = static_cast<wchar_t*>(heap->Alloc(htmlSize * sizeof(wchar_t) + sizeof(wchar_t)));
    const UPInt wideSize = UTF8Util::DecodeString(wide, phtml, static_cast<SPInt>(htmlSize));
    const bool result = FUN_14267b1c0(this, wide, wideSize, pimgInfoArr, multiline, condenseWhite,
                                      pstyleMgr, txtFmt, paraFmt);
    heap->Free(wide);
    return result;
}

template class SGMLCharIter<wchar_t>;
template class SGMLParser<wchar_t>;

}}} // namespace Scaleform::Render::Text
