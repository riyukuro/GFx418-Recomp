// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the HTML parser TU
// (Text_HTMLParser): the SGML pull parser over wide text (SGMLCharIter / SGMLParser<wchar_t>) and
// StyledText::ParseHtml, which turns the HTML subset of Flash text fields into styled paragraphs.
// MS2-UNIT: sfr_render_05i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14267b120-0x14267fce0 .text$mn

#include "ms2/scaleform/include/render/text_sgmlparser.h"
#include "ms2/scaleform/include/render/text_styledtext.h"
#include "ms2/scaleform/include/kernel/sf_utf8util.h"
#include "ms2/scaleform/include/kernel/sf_alg.h"
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
        static int Compare(const SGMLElementDesc& element, const Comparable<Char>& key)
        { return -SGMLCharIter<Char>::StrCompare(key.Str, element.ElemName, key.Size); }
        static int Less(const SGMLElementDesc& element, const Comparable<Char>& key)
        { return (-SGMLCharIter<Char>::StrCompare(key.Str, element.ElemName, key.Size)) < 0; }
    };
    template<class Char>
    static const SGMLElementDesc* FindElem(const Char* lookForElemName, UPInt nameSize,
                                           const SGMLElementDesc* ptable, UPInt tableSize)
    {
        Comparable<Char> e = { lookForElemName, nameSize };
        UPInt i = Alg::LowerBoundSliced(ptable, 0, tableSize, e, Comparator<Char>::Less);
        if (i < tableSize && Comparator<Char>::Compare(ptable[i], e) == 0)
            return &ptable[i];
        return NULL;
    }
};

template<class Char> struct SGMLStackElemDesc
{
    const Char* pElemName;
    UPInt ElemNameSize;
    const SGMLElementDesc* pElemDesc;
    UPInt StartPos;
    TextFormat TextFmt;
    ParagraphFormat ParaFmt;
    SGMLStackElemDesc()
        : pElemName(0), ElemNameSize(0), pElemDesc(0), TextFmt(Memory::GetHeapByAddress(&pElemName))
    {
    }
    SGMLStackElemDesc(MemoryHeap* pheap, const Char* pname, UPInt sz, const SGMLElementDesc* pelemDesc, UPInt startPos)
        : pElemName(pname), ElemNameSize(sz), pElemDesc(pelemDesc), StartPos(startPos), TextFmt(pheap)
    {
    }
    explicit SGMLStackElemDesc(MemoryHeap* pheap)
        : pElemName(0), ElemNameSize(0), pElemDesc(0), StartPos(0), TextFmt(pheap), ParaFmt()
    {
    }
};

// @0x14267ecf0
template<> __declspec(dllexport) int SGMLElementDesc::Comparator<wchar_t>::Less(
    const SGMLElementDesc& element, const SGMLElementDesc::Comparable<wchar_t>& key)
{
    return (-SGMLCharIter<wchar_t>::StrCompare(key.Str, element.ElemName, key.Size)) < 0;
}

}}} // namespace Scaleform::Render::Text


namespace Scaleform {
using SGMLStackElem = Render::Text::SGMLStackElemDesc<wchar_t>;
using SGMLStackAlloc = AllocatorDH<SGMLStackElem, Stat_Default_Mem>;
using SGMLStackData = ArrayDataBase<SGMLStackElem, SGMLStackAlloc, ArrayDefaultPolicy>;
using SGMLStackArrayData = ArrayDataDH<SGMLStackElem, SGMLStackAlloc, ArrayDefaultPolicy>;

// @0x14267db70
template SGMLStackData::~ArrayDataBase();
// @0x14267de50
template void ConstructorMov<SGMLStackElem>::Construct(void*, const SGMLStackElem&);
// @0x14267f410
template __declspec(dllexport) void ArrayBase<SGMLStackArrayData>::PopBack(UPInt);
// @0x14267f510
template void SGMLStackData::Reserve(const void*, UPInt);
// @0x14267f650
template void SGMLStackData::ResizeNoConstruct(const void*, UPInt);

using HTMLImageInfo = Render::Text::StyledText::HTMLImageTagInfo;
using HTMLImageInfoData = ArrayDataBase<HTMLImageInfo,
    AllocatorDH<HTMLImageInfo, Stat_Default_Mem>, ArrayDefaultPolicy>;
// @0x14267f5b0
template void HTMLImageInfoData::Reserve(const void*, UPInt);
}

namespace Scaleform { namespace Alg {
using SGMLElementLessFn = int (*)(const Render::Text::SGMLElementDesc&,
    const Render::Text::SGMLElementDesc::Comparable<wchar_t>&);
// @0x14267b120
template UPInt LowerBoundSliced<const Render::Text::SGMLElementDesc*,
    Render::Text::SGMLElementDesc::Comparable<wchar_t>, SGMLElementLessFn>(
    const Render::Text::SGMLElementDesc* const&, UPInt, UPInt,
    const Render::Text::SGMLElementDesc::Comparable<wchar_t>&, SGMLElementLessFn);
}}

namespace Scaleform { namespace Render { namespace Text {

// @0x14267dbe0
__declspec(noinline) StyledText::HTMLImageTagInfo::~HTMLImageTagInfo()
{
}

HTMLImageTagDesc::~HTMLImageTagDesc()
{
}

// The exe has no out-of-line ~HTMLImageTagDesc; 0x14267dc80 (vftable 0x143191bb8 slot 0) is the scalar deleting
// destructor with the dtor inlined, so it must free on flags & 1 (heap, or the sized delete of 0x70 on flags & 4).
// The members go one by one: a dtor call would store the class vftable, which the exe omits (implicit dtor in the SDK).
// @0x14267dc80
void* DeleteHTMLImageTagDesc(HTMLImageTagDesc* p, unsigned flags)
{
    p->Id.~StringLH();
    p->Url.~StringLH();
    p->ImageDesc::~ImageDesc();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
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
// @0x14267df60
template<class Char>
UInt32 SGMLCharIter<Char>::DecodeEscapedChar()
{
    if (pCurChar < pEnd)
    {
        pNextChar = pCurChar;
        if (*pNextChar == '&')
        {
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
        }
        return CurChar;
    }
    return 0;
}

// @0x14267eca0
template<class Char>
bool SGMLCharIter<Char>::IsSpace(UInt32 c)
{
    return SFiswspace((wchar_t)c) != 0;
}

// @0x14267fc30
template<class Char>
int SGMLCharIter<Char>::StrCompare(const Char* dst, UPInt dstlen, const Char* src, UPInt srclen)
{
    if (dstlen)
    {
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
    return -(int)srclen;
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
// @0x14267f190
template<class Char>
void SGMLParser<Char>::ParseName(const Char** ppname, UPInt* plen)
{
    *ppname    = Iter.GetCurCharPtr();
    *plen      = 0;
    bool inBuf = false;
    while (!Iter.IsFinished() &&
           *Iter != '=' && *Iter != '>' && *Iter != '<' && *Iter != '>' && *Iter != '/' && !Iter.IsSpace(*Iter))
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
        else
        {
            if (inBuf)
                AppendToBuf(Iter.GetCurCharPtr(), Iter.GetCurCharLength());
            else
                (*plen) += Iter.GetCurCharLength();
        }
        ++Iter;
    }
    if (inBuf)
    {
        *ppname = pBuffer;
        *plen   = BufPos;
    }
}

// @0x14267f370
template<class Char>
bool SGMLParser<Char>::ParseStartElement(const Char** ppelemName, UPInt* pelemLen)
{
    bool rv = false;
    if (CurState == SGMLPS_START_ELEMENT)
    {
        ParseName(ppelemName, pelemLen);

        rv = true;
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
    }
    return rv;
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

// The tags of the HTML subset, sorted for the binary search (exe table 0x143191bd0); SBR is a second BR.
enum HTMLElementId
{
    HTML_A, HTML_B, HTML_BR, HTML_FONT, HTML_I, HTML_IMG, HTML_LI, HTML_P, HTML_SPAN, HTML_TAB, HTML_TEXTFORMAT,
    HTML_U,
    // attributes and their keyword values
    HTML_ALIGN, HTML_ALPHA, HTML_BASELINE, HTML_BLOCKINDENT, HTML_CLASS, HTML_COLOR, HTML_FACE, HTML_HEIGHT,
    HTML_HREF, HTML_HSPACE, HTML_ID, HTML_INDENT, HTML_KERNING, HTML_LEADING, HTML_LEFTMARGIN, HTML_LETTERSPACING,
    HTML_RIGHTMARGIN, HTML_SRC, HTML_SIZE, HTML_TARGET, HTML_TABSTOPS, HTML_VSPACE, HTML_WIDTH, HTML_LEFT,
    HTML_RIGHT, HTML_CENTER, HTML_JUSTIFY
};

static const SGMLElementDesc HTMLElementsTable[] =
{
    { "A",          HTML_A,          true,  false },
    { "B",          HTML_B,          true,  false },
    { "BR",         HTML_BR,         false, true  },
    { "FONT",       HTML_FONT,       true,  false },
    { "I",          HTML_I,          true,  false },
    { "IMG",        HTML_IMG,        false, true  },
    { "LI",         HTML_LI,         false, false },
    { "P",          HTML_P,          false, false },
    { "SBR",        HTML_BR,         false, true  },
    { "SPAN",       HTML_SPAN,       true,  false },
    { "TAB",        HTML_TAB,        false, true  },
    { "TEXTFORMAT", HTML_TEXTFORMAT, true,  false },
    { "U",          HTML_U,          true,  false }
};

// exe table 0x143191cd0
static const SGMLElementDesc HTMLAttrsTable[] =
{
    { "ALIGN",         HTML_ALIGN,         false, false },
    { "ALPHA",         HTML_ALPHA,         false, false },
    { "BASELINE",      HTML_BASELINE,      false, false },
    { "BLOCKINDENT",   HTML_BLOCKINDENT,   false, false },
    { "CENTER",        HTML_CENTER,        false, false },
    { "CLASS",         HTML_CLASS,         false, false },
    { "COLOR",         HTML_COLOR,         false, false },
    { "FACE",          HTML_FACE,          false, false },
    { "HEIGHT",        HTML_HEIGHT,        false, false },
    { "HREF",          HTML_HREF,          false, false },
    { "HSPACE",        HTML_HSPACE,        false, false },
    { "ID",            HTML_ID,            false, false },
    { "INDENT",        HTML_INDENT,        false, false },
    { "JUSTIFY",       HTML_JUSTIFY,       false, false },
    { "KERNING",       HTML_KERNING,       false, false },
    { "LEADING",       HTML_LEADING,       false, false },
    { "LEFT",          HTML_LEFT,          false, false },
    { "LEFTMARGIN",    HTML_LEFTMARGIN,    false, false },
    { "LETTERSPACING", HTML_LETTERSPACING, false, false },
    { "RIGHT",         HTML_RIGHT,         false, false },
    { "RIGHTMARGIN",   HTML_RIGHTMARGIN,   false, false },
    { "SIZE",          HTML_SIZE,          false, false },
    { "SRC",           HTML_SRC,           false, false },
    { "TABSTOPS",      HTML_TABSTOPS,      false, false },
    { "TARGET",        HTML_TARGET,        false, false },
    { "VSPACE",        HTML_VSPACE,        false, false },
    { "WIDTH",         HTML_WIDTH,         false, false }
};

// SGMLParser::ParseFloat (SDK body) as the exe has it: inlined into the HTML parser only.
static __forceinline bool ParseFloatInl(float* pdestVal, const wchar_t* pstr, UPInt len)
{
    if (len == 0)
        return false;
    Double v = 0, sign = 1;
    const wchar_t* p = pstr;
    const wchar_t* const pend = pstr + len;
    if (*p == '-')
    {
        sign = -1;
        ++p;
    }
    else
    {
        if (*p == '+') ++p;
    }
    for (; p < pend && *p != '.' && *p != ','; ++p)
    {
        if (!SGMLCharIter<wchar_t>::IsDigit(*p))
            return false;
        v *= 10;
        v += (*p - '0');
    }
    if (p < pend && (*p == '.' || *p == ','))
    {
        ++p;
        Double frac = 0;
        for (; p < pend; ++p)
        {
            if (!SGMLCharIter<wchar_t>::IsDigit(*p))
                return false;
            frac += (*p - '0');
            frac *= Double(0.1);
        }
        v += frac;
    }
    *pdestVal = (float)(v * sign);
    return true;
}

// The HTML parser of both ParseHtml overloads (inlined into neither). Each open element keeps on the stack the
// formats its content gets: those of its parent with the element's attributes (and style sheet styles) applied.
// The SDK's StyledText::ParseHtmlImpl<wchar_t> (Text_HTMLParser.cpp, GFX_ENABLE_CSS on) statement for statement,
// with ParseFloat inlined through the local copy above.
// @0x14267b1c0
bool FUN_14267b1c0(StyledText* self, const wchar_t* phtml, UPInt htmlSize,
                   StyledText::HTMLImageTagInfoArray* pimgInfoArr, bool multiline, bool condenseWhite,
                   const StyleManagerBase* pstyleMgr, const TextFormat* defTxtFmt,
                   const ParagraphFormat* defParaFmt)
{
    if (htmlSize == 0)
    {
        self->EnsureTermNull();
        return false;
    }

    MemoryHeap* pheap = Memory::GetHeapByAddress(self);

    ArrayDH<SGMLStackElemDesc<wchar_t> > elementsStack(pheap);

    SGMLParser<wchar_t> parser(pheap, phtml, htmlSize);
    if (condenseWhite)
        parser.SetCondenseWhite();

    int type;
    Paragraph* pcurPara = NULL;
    const SGMLElementDesc* plastElemDesc = NULL;
    int p_elem_is_opened = 0;

    TextFormat defaultTextFmt        = (defTxtFmt)  ? *defTxtFmt  : *self->GetDefaultTextFormat();
    ParagraphFormat defaultParaFmt   = (defParaFmt) ? *defParaFmt : *self->GetDefaultParagraphFormat();

    TextFormat lastFormat = defaultTextFmt;

    //clear URL for just inserted text
    // This is necessary to prevent URL-style propagation after
    // closing </A> tag. 
    defaultTextFmt.SetUrl("");

    while((type = parser.GetNext()) != SGMLPS_FINISHED && type != SGMLPS_ERROR)
    {
        switch(type)
        {
        case SGMLPS_START_ELEMENT:
            {
                const wchar_t* elemName;
                UPInt elemLen;

                parser.ParseStartElement(&elemName, &elemLen);

                const SGMLElementDesc* pelemDesc = SGMLElementDesc::FindElem<wchar_t>
                    (elemName, elemLen, HTMLElementsTable, sizeof(HTMLElementsTable)/sizeof(HTMLElementsTable[0]));
                plastElemDesc = pelemDesc;

                int prevStackIndex = int(elementsStack.GetSize()-1);

                if (pelemDesc && pelemDesc->EmptyElement)
                {
                    switch(pelemDesc->ElemId)
                    {
                    case HTML_BR:
                        // new paragraph
                        if (multiline)
                            self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt);
                        break;
                    case HTML_TAB:
                        self->AppendString("\t", 1);
                        break;
                    case HTML_IMG:
                        {
                            if (pimgInfoArr)
                            {
                                const wchar_t* pattrName;
                                UPInt      attrSz;
                                pimgInfoArr->PushBack(StyledText::HTMLImageTagInfo(pheap));
                                StyledText::HTMLImageTagInfo&  imgInfo = (*pimgInfoArr)[pimgInfoArr->GetSize() - 1];
                                pcurPara = self->GetLastParagraph();
                                if (pcurPara == NULL)
                                    pcurPara = self->AppendNewParagraph(&defaultParaFmt);
                                TextFormat imgCharFmt(defaultTextFmt);
                                imgInfo.ParaId = pcurPara->GetId();
                                while(parser.GetNextAttribute(&pattrName, &attrSz))
                                {
                                    const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                        (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                    if (pattrDesc)
                                    {
                                        const wchar_t* pattrVal;
                                        UPInt      attrValSz;                                        
                                        if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                        {
                                            switch(pattrDesc->ElemId)
                                            {
                                            case HTML_SRC:
                                                imgInfo.Url.AppendString(pattrVal, attrValSz);
                                                break;
                                            case HTML_ID:
                                                imgInfo.Id.AppendString(pattrVal, attrValSz);
                                                break;
                                            case HTML_ALIGN:
                                                pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                                    (pattrVal, attrValSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                                if (pattrDesc)
                                                {
                                                    switch(pattrDesc->ElemId)
                                                    {
                                                    case HTML_LEFT:
                                                        imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_Left;
                                                        break;
                                                    case HTML_RIGHT:
                                                        imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_Right;
                                                        break;
                                                    case HTML_BASELINE:
                                                        imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_BaseLine;
                                                        break;
                                                    default: break;
                                                    }
                                                }
                                                break;
                                            case HTML_WIDTH:
                                                {
                                                    int v;
                                                    if (parser.ParseInt(&v, pattrVal, attrValSz) && v >= 0)
                                                    {
                                                        imgInfo.Width = PixelsToFixp((unsigned)v);
                                                    }
                                                }
                                                break;
                                            case HTML_HEIGHT:
                                                {
                                                    int v;
                                                    if (parser.ParseInt(&v, pattrVal, attrValSz) && v >= 0)
                                                    {
                                                        imgInfo.Height = PixelsToFixp((unsigned)v);
                                                    }
                                                }
                                                break;
                                            case HTML_VSPACE:
                                                {
                                                    int v;
                                                    if (parser.ParseInt(&v, pattrVal, attrValSz))
                                                    {
                                                        imgInfo.VSpace = PixelsToFixp(v);
                                                    }
                                                }
                                                break;
                                            case HTML_HSPACE:
                                                {
                                                    int v;
                                                    if (parser.ParseInt(&v, pattrVal, attrValSz))
                                                    {
                                                        imgInfo.HSpace = PixelsToFixp(v);
                                                    }
                                                }
                                                break;
                                            default: break;
                                            }
                                        }
                                    }
                                }
                                Ptr<HTMLImageTagDesc> ptextImageDesc = *SF_HEAP_AUTO_NEW(self) HTMLImageTagDesc;
                                imgCharFmt.SetImageDesc(ptextImageDesc);
                                ptextImageDesc->ScreenWidth     = (float)imgInfo.Width;
                                ptextImageDesc->ScreenHeight    = (float)imgInfo.Height;
                                ptextImageDesc->VSpace          = imgInfo.VSpace;
                                ptextImageDesc->HSpace          = imgInfo.HSpace;
                                ptextImageDesc->Url             = imgInfo.Url;
                                ptextImageDesc->Id              = imgInfo.Id;
                                ptextImageDesc->Alignment       = imgInfo.Alignment;
                                imgInfo.pTextImageDesc = ptextImageDesc;
                                TextFormat* ptextFmt;
                                const ParagraphFormat* pparaFmt;
                                if (prevStackIndex >= 0)
                                {
                                    ptextFmt = &elementsStack[prevStackIndex].TextFmt;
                                    pparaFmt = &elementsStack[prevStackIndex].ParaFmt;
                                }
                                else
                                {
                                    ptextFmt = &defaultTextFmt;
                                    pparaFmt = &defaultParaFmt;
                                }
                                if (ptextFmt->IsUrlSet())
                                    imgCharFmt.SetUrl(ptextFmt->GetUrl());
                                self->AppendString(" ", 1, StyledText::NLP_ReplaceCRLF, &imgCharFmt, pparaFmt);
                                ptextFmt->SetImageDesc(NULL);  // make sure IMG is not duplicated for following content
                                lastFormat.SetImageDesc(NULL); // make sure IMG is not duplicated for <br>
                                self->SetDefaultTextFormat(*ptextFmt);
                            }
                        }
                        break;
                    default: break;
                    }
                }
                else
                {
                    UPInt curPos = self->GetLength();
                    elementsStack.PushBack(SGMLStackElemDesc<wchar_t>(pheap, elemName, elemLen, pelemDesc, 0));
                    SGMLStackElemDesc<wchar_t>& stackElem = elementsStack[elementsStack.GetSize()-1];
                    stackElem.StartPos = curPos;
                    if (prevStackIndex >= 0)
                    {
                        stackElem.TextFmt = elementsStack[prevStackIndex].TextFmt;
                        stackElem.ParaFmt = elementsStack[prevStackIndex].ParaFmt;
                    }
                    else
                    {
                        stackElem.TextFmt = defaultTextFmt;
                        stackElem.ParaFmt = defaultParaFmt;
                    }

                    if (!pelemDesc)
                    {
                        // apply CSS class for arbitrary tag
                        if (pstyleMgr)
                        {
                            const Style* pstyle =
                                pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen);
                            if (pstyle)
                            {
                                stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                            }
                        }
                    }
                    else
                    {
                        switch(pelemDesc->ElemId)
                        {
                        case HTML_A:
                            const wchar_t* pattrName;
                            UPInt      attrSz;
                            while(parser.GetNextAttribute(&pattrName, &attrSz))
                            {
                                const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                    (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                if (pattrDesc)
                                {
                                    const wchar_t* pattrVal;
                                    UPInt       attrValSz;                                        
                                    if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                    {
                                        switch(pattrDesc->ElemId)
                                        {
                                        case HTML_HREF:
                                            stackElem.TextFmt.SetUrl(pattrVal, attrValSz);
                                            self->SetMayHaveUrl();
                                            break;
                                        default: break;
                                        }
                                    }
                                }
                            }
                            if (pstyleMgr)
                            {
                                // apply CSS style, if any
                                const Style* pstyle = 
                                    pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, "a");
                                if (pstyle)
                                {
                                    //?stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                    stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                }
                                if (stackElem.TextFmt.IsUrlSet())
                                {
                                    // get a:link CSS style since there is a HREF attr
                                    const Style* pstyle = 
                                        pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, "a:link");
                                    if (pstyle)
                                    {
                                        //?stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                        stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                    }
                                }
                            }
                            break;
                        case HTML_LI:
                        {
                            stackElem.ParaFmt.SetBullet();
                            pcurPara = self->GetLastParagraph();
                            if (pcurPara == NULL)
                                pcurPara = self->AppendNewParagraph(&stackElem.ParaFmt);
                            else if (pcurPara->GetLength() == 0)
                                pcurPara->SetFormat(self->GetAllocator(), stackElem.ParaFmt);
                            else
                            {
                                if (multiline)
                                    self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt); 
                                pcurPara = self->GetLastParagraph();
                                pcurPara->SetFormat(self->GetAllocator(), stackElem.ParaFmt);
                            }
                            // apply CSS class (on tag basis)
                            if (pstyleMgr)
                            {
                                const Style* pstyle =
                                    pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen);
                                if (pstyle)
                                {
                                    stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                    stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                    pcurPara->SetFormat(self->GetAllocator(), stackElem.ParaFmt);
                                }
                            }
                            break;
                        }
                        case HTML_P:
                        {
                            if ((pcurPara = self->GetLastParagraph()) == NULL)
                            {
                                // no paragraphs yet
                                pcurPara = self->AppendNewParagraph(&defaultParaFmt);
                            }
                            else if (p_elem_is_opened)
                            {
                                if (multiline)
                                    self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt);
                                pcurPara = self->GetLastParagraph();
                            }
                            // apply CSS class (on tag basis)
                            if (pstyleMgr)
                            {
                                const Style* pstyle =
                                    pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen);
                                if (pstyle)
                                {
                                    stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                    stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                }
                            }

                            // new paragraph
                            const wchar_t* pattrName;
                            UPInt       attrSz;
                            while(parser.GetNextAttribute(&pattrName, &attrSz))
                            {
                                const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                    (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                if (pattrDesc)
                                {
                                    const wchar_t* pattrVal;
                                    UPInt       attrValSz;                                        
                                    if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                    {
                                        switch(pattrDesc->ElemId)
                                        {
                                        case HTML_CLASS:
                                            {
                                                // apply CSS class
                                                if (pstyleMgr)
                                                {
                                                    const Style* pstyle =
                                                        pstyleMgr->GetStyle(StyleManagerBase::CSS_Class, pattrVal, attrValSz);
                                                    if (pstyle)
                                                    {
                                                        stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                                        stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                                    }
                                                }
                                            }
                                            break;
                                        case HTML_ALIGN:
                                            {
                                                pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                                    (pattrVal, attrValSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                                if (pattrDesc)
                                                {
                                                    switch(pattrDesc->ElemId)
                                                    {
                                                    case HTML_LEFT:
                                                        stackElem.ParaFmt.SetAlignment(ParagraphFormat::Align_Left);
                                                        break;
                                                    case HTML_RIGHT:
                                                        stackElem.ParaFmt.SetAlignment(ParagraphFormat::Align_Right);
                                                        break;
                                                    case HTML_CENTER:
                                                        stackElem.ParaFmt.SetAlignment(ParagraphFormat::Align_Center);
                                                        break;
                                                    case HTML_JUSTIFY:
                                                        stackElem.ParaFmt.SetAlignment(ParagraphFormat::Align_Justify);
                                                        break;
                                                    default: break;
                                                    }
                                                }
                                            }
                                            break;
                                        default: break;
                                        }
                                    }
                                }
                            }
                            if (pcurPara->GetLength() == 0)
                                pcurPara->SetFormat(self->GetAllocator(), stackElem.ParaFmt);
                            //}
                            ++p_elem_is_opened;
                            break;
                        }
                        case HTML_B:
                            stackElem.TextFmt.SetBold(true);
                            break;
                        case HTML_I:
                            stackElem.TextFmt.SetItalic(true);
                            break;
                        case HTML_U:
                            stackElem.TextFmt.SetUnderline(true);
                            break;
                        case HTML_FONT:
                            {
                                const wchar_t* pattrName;
                                UPInt       attrSz;
                                while(parser.GetNextAttribute(&pattrName, &attrSz))
                                {
                                    const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                        (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                    if (pattrDesc)
                                    {
                                        const wchar_t* pattrVal;
                                        UPInt       attrValSz;                                        
                                        if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                        {
                                            switch(pattrDesc->ElemId)
                                            {
                                            case HTML_COLOR:
                                                // parse color: #RRGGBB
                                                if (*pattrVal == '#')
                                                {
                                                    UInt32 color;
                                                    if (parser.ParseHexInt(&color, pattrVal+1, attrValSz-1))
                                                    {
                                                        stackElem.TextFmt.SetColor32(color);    
                                                    }
                                                }
                                                break;
                                            case HTML_FACE:
                                                stackElem.TextFmt.SetFontList(pattrVal, attrValSz);
                                                break;
                                            case HTML_SIZE:
                                                // parse size
                                                int sz;
                                                if (parser.ParseInt(&sz, pattrVal, attrValSz) && sz >= 0)
                                                {
                                                    stackElem.TextFmt.SetFontSize((float)sz);
                                                }
                                                break;
                                            case HTML_KERNING:
                                                // parse kerning
                                                int kern;
                                                if (parser.ParseInt(&kern, pattrVal, attrValSz) && kern >= 0)
                                                {
                                                    if (kern)
                                                        stackElem.TextFmt.SetKerning();
                                                    else
                                                        stackElem.TextFmt.ClearKerning();
                                                }
                                                break;
                                            case HTML_LETTERSPACING:
                                                // parse letterspacing
                                                float ls;
                                                if (ParseFloatInl(&ls, pattrVal, attrValSz))
                                                {
                                                    stackElem.TextFmt.SetLetterSpacing(ls);
                                                }
                                                break;
                                                // extension
                                            case HTML_ALPHA:
                                                // parse alpha: #AA
                                                if (*pattrVal == '#')
                                                {
                                                    UInt32 alpha;
                                                    if (parser.ParseHexInt(&alpha, pattrVal+1, attrValSz-1))
                                                    {
                                                        stackElem.TextFmt.SetAlpha(UInt8(alpha));    
                                                    }
                                                }
                                                break;
                                            default: break;
                                            }
                                        }
                                    }
                                }
                                lastFormat = stackElem.TextFmt;
                            }

                            break;
                        case HTML_TEXTFORMAT:
                            {
                                const wchar_t* pattrName;
                                UPInt       attrSz;
                                while(parser.GetNextAttribute(&pattrName, &attrSz))
                                {
                                    const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                        (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                    if (pattrDesc)
                                    {
                                        const wchar_t* pattrVal;
                                        UPInt       attrValSz;                                        
                                        if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                        {
                                            switch(pattrDesc->ElemId)
                                            {
                                            case HTML_INDENT:
                                                {
                                                    // parse indent
                                                    int indent;
                                                    if (parser.ParseInt(&indent, pattrVal, attrValSz))
                                                    {
                                                        stackElem.ParaFmt.SetIndent(indent);
                                                    }
                                                    break;
                                                }
                                            case HTML_BLOCKINDENT:
                                                {
                                                    // parse indent
                                                    int indent;
                                                    if (parser.ParseInt(&indent, pattrVal, attrValSz) && indent >= 0)
                                                    {
                                                        stackElem.ParaFmt.SetBlockIndent((unsigned)indent);
                                                    }
                                                    break;
                                                }
                                            case HTML_LEADING:
                                                {
                                                    // parse indent
                                                    int leading;
                                                    if (parser.ParseInt(&leading, pattrVal, attrValSz))
                                                    {
                                                        stackElem.ParaFmt.SetLeading(leading);
                                                    }
                                                    break;
                                                }
                                            case HTML_LEFTMARGIN:
                                                {
                                                    // parse margin
                                                    int margin;
                                                    if (parser.ParseInt(&margin, pattrVal, attrValSz) && margin >= 0)
                                                    {
                                                        stackElem.ParaFmt.SetLeftMargin((unsigned)margin);
                                                    }
                                                    break;
                                                }
                                            case HTML_RIGHTMARGIN:
                                                {
                                                    // parse margin
                                                    int margin;
                                                    if (parser.ParseInt(&margin, pattrVal, attrValSz) && margin >= 0)
                                                    {
                                                        stackElem.ParaFmt.SetRightMargin((unsigned)margin);
                                                    }
                                                    break;
                                                }
                                            case HTML_TABSTOPS:
                                                {
                                                    // parse tabstops as [xx,xx,xx]
                                                    // calculate number of tabstops first
                                                    UPInt i = 0;
                                                    while(i < attrValSz && SGMLCharIter<wchar_t>::IsSpace(pattrVal[i]))
                                                        ++i;
                                                    if (pattrVal[i] == '[')
                                                        ++i; // skip the [
                                                    unsigned n = 1;
                                                    UPInt j;
                                                    for (j = i; j < attrValSz && pattrVal[j] != ']'; ++j)
                                                    {
                                                        if (pattrVal[j] == ',')
                                                            ++n;
                                                    }
                                                    stackElem.ParaFmt.BeginTabStops(n);
                                                    unsigned idx = 0;
                                                    for (j = i; j < attrValSz && pattrVal[j] != ']'; )
                                                    {
                                                        unsigned v = 0;
                                                        for (; j < attrValSz && SGMLCharIter<wchar_t>::IsDigit(pattrVal[j]); ++j)
                                                        {
                                                            v *= 10;
                                                            v += (pattrVal[j] - '0');
                                                        }
                                                        while(j < attrValSz && SGMLCharIter<wchar_t>::IsSpace(pattrVal[j]))
                                                            ++j;
                                                        stackElem.ParaFmt.SetTabStopsElement(idx, v);
                                                        ++idx;
                                                        if (pattrVal[j] == ',')
                                                        {
                                                            ++j;
                                                            while(j < attrValSz && SGMLCharIter<wchar_t>::IsSpace(pattrVal[j]))
                                                                ++j;
                                                        }
                                                    }
                                                }
                                                break;
                                            default: break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case HTML_SPAN:
                            {
                                const wchar_t* pattrName;
                                UPInt       attrSz;
                                while(parser.GetNextAttribute(&pattrName, &attrSz))
                                {
                                    const SGMLElementDesc* pattrDesc = SGMLElementDesc::FindElem<wchar_t>
                                        (pattrName, attrSz, HTMLAttrsTable, sizeof(HTMLAttrsTable)/sizeof(HTMLAttrsTable[0]));
                                    if (pattrDesc)
                                    {
                                        const wchar_t* pattrVal;
                                        UPInt       attrValSz;                                        
                                        if (parser.GetNextAttributeValue(&pattrVal, &attrValSz))
                                        {
                                            switch(pattrDesc->ElemId)
                                            {
                                                case HTML_CLASS:
                                                    // apply CSS class
                                                    if (pstyleMgr)
                                                    {
                                                        const Style* pstyle =
                                                            pstyleMgr->GetStyle(StyleManagerBase::CSS_Class, pattrVal, attrValSz);
                                                        if (pstyle)
                                                        {
                                                            //?stackElem.ParaFmt = stackElem.ParaFmt.Merge(pstyle->mParagraphFormat);
                                                            stackElem.TextFmt = stackElem.TextFmt.Merge(pstyle->mTextFormat);
                                                            lastFormat = stackElem.TextFmt;
                                                        }
                                                    }
                                                    break;
                                                default: break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        default: break;
                        }
                    }
                    lastFormat = stackElem.TextFmt;
                }
            }
            break;
        case SGMLPS_CONTENT:
            {
                const wchar_t* content;
                UPInt  contentSize;
                if (parser.ParseContent(&content, &contentSize))
                {
                    if (contentSize > 0)
                    {
                        pcurPara = self->GetLastParagraph();
                        UPInt paraLen = (pcurPara) ? pcurPara->GetLength() : 0;
                        // do not add space at the beginning of paragraph, if condenseWhite
                        if (!condenseWhite || contentSize > 1 || content[0] != ' ' || paraLen > 0)
                        {
                            if (elementsStack.GetSize() > 0)
                            {
                                SGMLStackElemDesc<wchar_t>& stackElem = elementsStack[elementsStack.GetSize()-1];
                                self->AppendString(content, contentSize, StyledText::NLP_ReplaceCRLF, &stackElem.TextFmt, &stackElem.ParaFmt);
                                lastFormat = stackElem.TextFmt;
                            }
                            else
                            {
                                self->AppendString(content, contentSize, StyledText::NLP_ReplaceCRLF, &defaultTextFmt, &defaultParaFmt);
                                lastFormat = defaultTextFmt; 
                            }
                        }
                    }
                }
            }
            break;
        case SGMLPS_END_ELEMENT:
        case SGMLPS_EMPTY_ELEMENT_FINISHED:
            {
                const wchar_t* elemName = NULL;
                UPInt  elemLen       = 0;

                UPInt startPos;
                const SGMLStackElemDesc<wchar_t>* pstackElem = NULL;
                if (type == SGMLPS_END_ELEMENT)
                {
                    if (elementsStack.GetSize() > 0)
                        pstackElem = &elementsStack[elementsStack.GetSize()-1];
                    parser.ParseEndElement(&elemName, &elemLen);
                }
                else
                {
                    // ignore end elements for BR & TAB
                    if (plastElemDesc)
                    {
                        if (plastElemDesc->EmptyElement)
                            break;
                    }
                    if (elementsStack.GetSize() > 0)
                    {
                        pstackElem = &elementsStack[elementsStack.GetSize()-1];
                        elemName = pstackElem->pElemName;
                        elemLen  = pstackElem->ElemNameSize;
                    }
                    else
                        break; // shouldn't get here at all.
                }
                if (pstackElem)
                {
                    // verify matching of end-element and start-element
                    if (parser.StrCompare(elemName, elemLen, pstackElem->pElemName, pstackElem->ElemNameSize) != 0)
                    {
                        // mismatch!
                        // just ignore such an element for now. Do we need to print
                        // kinda warning?
                        const SGMLElementDesc* pelemDesc = SGMLElementDesc::FindElem<wchar_t>
                            (elemName, elemLen, HTMLElementsTable, sizeof(HTMLElementsTable)/sizeof(HTMLElementsTable[0]));
                        if (pelemDesc && p_elem_is_opened && (pelemDesc->ElemId == HTML_P || pelemDesc->ElemId == HTML_LI))
                        {
                            // looks like, if </p> end tag is used w/o closing all tags nested to it
                            // then it should close all opened tags till <p>
                            while(elementsStack.GetSize() > 0)
                            {
                                const SGMLStackElemDesc<wchar_t>& stackElem = elementsStack[elementsStack.GetSize()-1];
                                if (stackElem.pElemDesc && pelemDesc->ElemId == stackElem.pElemDesc->ElemId)
                                    break;
                                elementsStack.PopBack();
                            }
                            if (elementsStack.GetSize() > 0)
                                pstackElem = &elementsStack[elementsStack.GetSize()-1];
                            else
                                break;
                        }
                        else
                            break;
                    }
                    bool isDisplaySet = pstackElem->ParaFmt.IsDisplaySet();
                    ParagraphFormat::DisplayType display = pstackElem->ParaFmt.GetDisplay();
                    plastElemDesc = pstackElem->pElemDesc;
                    startPos = pstackElem->StartPos;
                    elementsStack.PopBack();

                    if (plastElemDesc)
                    {
                        switch(plastElemDesc->ElemId)
                        {
                        case HTML_P:
                            --p_elem_is_opened;
                            // Empty <P/> element doesn't produce a new paragraph in Flash
                            if (type == SGMLPS_EMPTY_ELEMENT_FINISHED)
                                break;
                        case HTML_LI:
                            if (multiline)
                                self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt);
                            break;
                        default: break;
                        }
                    }
                    else
                    {
                        // arbitrary tags handling, if necessary
                        if (pstyleMgr)
                        {
                            // if CSS is used, check if we have block or none display
                            if (isDisplaySet)
                            {
                                switch(display)
                                {
                                case ParagraphFormat::Display_Block:
                                    // create a new paragraph
                                    if (multiline)
                                        self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt);
                                    break;
                                case ParagraphFormat::Display_None:
                                    {
                                    // create a new paragraph and remove the invisible text
                                    UPInt curPos = self->GetLength();
                                    if (multiline)
                                    {
                                        self->AppendString((self->IsNewLine0D() ? "\r" : "\n"), 1, StyledText::NLP_ReplaceCRLF, &lastFormat, &defaultParaFmt);
                                    }
                                    self->Remove(startPos, curPos - startPos);
                                    break;
                                    }
                                default:;
                                }
                            }

                        }
                    }
                }
                else
                {
                    // wrong end elem, ignore...
                    break;
                }
            }
            break;
        default: break;
        }
    }
    if (elementsStack.GetSize() > 0)
    {
        SGMLStackElemDesc<wchar_t>& stackElem = elementsStack[elementsStack.GetSize()-1];
        self->SetDefaultTextFormat(stackElem.TextFmt);
        self->SetDefaultParagraphFormat(stackElem.ParaFmt);
        lastFormat = stackElem.TextFmt;
    }
    else
    {
        self->SetDefaultTextFormat(defaultTextFmt);
        self->SetDefaultParagraphFormat(defaultParaFmt);
    }
    self->EnsureTermNull();

    // Flash treats empty paragraphs at the end of the specific way. For example, if 
    // HTML code is as follows: 
    // "<p align="left"><font face="Arial" size="20" color="#ffffff" letterSpacing="5" kerning="1">Test 12345</font></p><p align="left"></p>"
    // then the last paragraph should be empty w/o any format data (<p align="left"></p>). Though,
    // Flash propagates the last known text format on the empty paragraphs. The code below does
    // this in GFx.
    Paragraph* ppara = self->GetLastParagraph();
    if (ppara && ppara->GetLength() == 0)
    {
        StyledText::ParagraphsIterator paraIter = self->Paragraphs.Last();
        while(!paraIter.IsFinished())
        {
            Paragraph* pcurPara = paraIter->GetPtr();
            if (pcurPara->GetLength() <= 1)
            {
                pcurPara->SetTextFormat(self->GetAllocator(), lastFormat, 0, SF_MAX_UPINT);
            }
            else
                break;
            --paraIter;
        }
    }

    return true;
}

// @0x14267f0d0
bool StyledText::ParseHtml(const wchar_t* phtml, UPInt htmlSize, HTMLImageTagInfoArray* pimgInfoArr,
                           bool multiline, bool condenseWhite, const StyleManagerBase* pstyleMgr,
                           const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    return FUN_14267b1c0(this, phtml, htmlSize, pimgInfoArr, multiline, condenseWhite,
                         pstyleMgr, txtFmt, paraFmt);
}

// @0x14267eff0
bool StyledText::ParseHtml(const char* phtml, UPInt htmlSize, HTMLImageTagInfoArray* pimgInfoArr,
                           bool multiline, bool condenseWhite, const StyleManagerBase* pstyleMgr,
                           const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    wchar_t* wide = static_cast<wchar_t*>(Memory::GetGlobalHeap()->Alloc(htmlSize * sizeof(wchar_t) + sizeof(wchar_t)));
    const UPInt wideSize = UTF8Util::DecodeString(wide, phtml, static_cast<SPInt>(htmlSize));
    const bool result = FUN_14267b1c0(this, wide, wideSize, pimgInfoArr, multiline, condenseWhite,
                                      pstyleMgr, txtFmt, paraFmt);
    Memory::GetGlobalHeap()->Free(wide);
    return result;
}

template class SGMLCharIter<wchar_t>;
template class SGMLParser<wchar_t>;

}}} // namespace Scaleform::Render::Text

// MS2-PIN: ?PopBack@?$ArrayBase@U?$ArrayDataDH@U?$SGMLStackElemDesc@_W@Text@Render@Scaleform@@U?$AllocatorDH@U?$SGMLStackElemDesc@_W@Text@Render@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14267f410
// MS2-PIN: ??_7HTMLImageTagDesc@Text@Render@Scaleform@@6B@ 0x143191bb8
// MS2-PIN: ??_7ImageDesc@Text@Render@Scaleform@@6B@ 0x14317c9c0
// MS2-PIN: ??_7?$RefCountBaseNTS@UImageDesc@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
