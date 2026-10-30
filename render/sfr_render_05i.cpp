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
        static int Less(const SGMLElementDesc& element, const Comparable<Char>& key)
        { return (-SGMLCharIter<Char>::StrCompare(key.Str, element.ElemName, key.Size)) < 0; }
    };
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
        : pElemName(0), ElemNameSize(0), pElemDesc(0), StartPos(0),
          TextFmt(Memory::GetHeapByAddress(&pElemName)), ParaFmt()
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
StyledText::HTMLImageTagInfo::~HTMLImageTagInfo()
{
}

HTMLImageTagDesc::~HTMLImageTagDesc()
{
}

// The exe has no out-of-line ~HTMLImageTagDesc; 0x14267dc80 (vftable 0x143191bb8 slot 0) is the scalar deleting
// destructor with the dtor inlined, so it must free on flags & 1 (heap, or the sized delete of 0x70 on flags & 4).
// MS2-FUNCTIONAL: the inlined dtor stores the class vftable first, which the exe omits (the deleting dtor knows the type).
// @0x14267dc80
void* DeleteHTMLImageTagDesc(HTMLImageTagDesc* p, unsigned flags)
{
    p->~HTMLImageTagDesc();
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

template<UPInt N>
static const SGMLElementDesc* FindHTMLDesc(const SGMLElementDesc (&table)[N], const wchar_t* name, UPInt len)
{
    SGMLElementDesc::Comparable<wchar_t> key = { name, len };
    const SGMLElementDesc* ptable = table;
    UPInt i = Alg::LowerBoundSliced(ptable, 0, N, key, SGMLElementDesc::Comparator<wchar_t>::Less);
    if (i < N && SGMLCharIter<wchar_t>::StrCompare(name, table[i].ElemName, len) == 0)
        return &table[i];
    return 0;
}

static void AppendHTMLNewLine(StyledText* self, const TextFormat& fmt, const ParagraphFormat& paraFmt)
{
    self->AppendString(self->IsNewLine0D() ? "\r" : "\n", 1, StyledText::NLP_ReplaceCRLF, &fmt, &paraFmt);
}

// The HTML parser of both ParseHtml overloads (inlined into neither). Each open element keeps on the stack the
// formats its content gets: those of its parent with the element's attributes (and style sheet styles) applied.
// MS2-FUNCTIONAL: same tags, attributes, style lookups, paragraph handling and image descriptors as the exe; the
// exe inlines ParseStartElement / ParseEndElement / ParseFloat and the table searches, and keeps more locals.
// @0x14267b1c0
bool FUN_14267b1c0(StyledText* self, const wchar_t* phtml, UPInt htmlSize,
                   StyledText::HTMLImageTagInfoArray* pimgInfoArr, bool multiline, bool condenseWhite,
                   const StyleManagerBase* pstyleMgr, const TextFormat* txtFmt,
                   const ParagraphFormat* paraFmt)
{
    typedef SGMLStackElemDesc<wchar_t> StackElem;
    if (htmlSize == 0)
    {
        self->EnsureTermNull();
        return false;
    }
    MemoryHeap* pheap = Memory::GetHeapByAddress(self);
    SGMLParser<wchar_t> parser(pheap, phtml, htmlSize);
    if (condenseWhite)
        parser.SetCondenseWhite();
    ArrayDH<StackElem> elemStack(pheap);
    const SGMLElementDesc* pcurDesc = 0;
    int paraCount = 0;

    if (!txtFmt)
        txtFmt = self->GetDefaultTextFormat();
    TextFormat defTextFmt(*txtFmt);
    if (!paraFmt)
        paraFmt = self->GetDefaultParagraphFormat();
    ParagraphFormat defParaFmt(*paraFmt);
    TextFormat lastFmt(defTextFmt);
    defTextFmt.SetUrl("");

    int state;
    while ((state = parser.GetNext()) != SGMLPS_FINISHED)
    {
        if (state == SGMLPS_ERROR)
            break;
        if (state == SGMLPS_CONTENT)
        {
            const wchar_t* content;
            UPInt contentSize;
            if (!parser.ParseContent(&content, &contentSize) || !contentSize)
                continue;
            Paragraph* plast = self->GetLastParagraph();
            UPInt lastLen = plast ? plast->GetLength() : 0;
            // a blank alone at the start of a paragraph is dropped when white space is condensed
            if (condenseWhite && contentSize <= 1 && *content == ' ' && lastLen == 0)
                continue;
            if (elemStack.GetSize() == 0)
            {
                self->AppendString(content, contentSize, StyledText::NLP_ReplaceCRLF, &defTextFmt, &defParaFmt);
                lastFmt = defTextFmt;
            }
            else
            {
                StackElem& top = elemStack.Back();
                self->AppendString(content, contentSize, StyledText::NLP_ReplaceCRLF, &top.TextFmt, &top.ParaFmt);
                lastFmt = top.TextFmt;
            }
        }
        else if (state == SGMLPS_END_ELEMENT || state == SGMLPS_EMPTY_ELEMENT_FINISHED)
        {
            const wchar_t* elemName = 0;
            UPInt elemLen = 0;
            if (state == SGMLPS_END_ELEMENT)
            {
                parser.ParseEndElement(&elemName, &elemLen);
                if (elemStack.GetSize() == 0)
                    continue;
            }
            else
            {
                // "<x/>": only a container element that was just opened is closed
                if ((pcurDesc && pcurDesc->EmptyElement) || elemStack.GetSize() == 0)
                    continue;
                elemName = elemStack.Back().pElemName;
                elemLen = elemStack.Back().ElemNameSize;
            }

            bool matched = SGMLCharIter<wchar_t>::StrCompare(elemName, elemLen, elemStack.Back().pElemName,
                                                              elemStack.Back().ElemNameSize) == 0;
            if (!matched)
            {
                // an unclosed list item or paragraph is closed by the end of the enclosing one
                const SGMLElementDesc* pdesc = FindHTMLDesc(HTMLElementsTable, elemName, elemLen);
                if (!pdesc || paraCount == 0 || (pdesc->ElemId != HTML_LI && pdesc->ElemId != HTML_P))
                    continue;
                while (elemStack.GetSize() != 0)
                {
                    const SGMLElementDesc* ptopDesc = elemStack.Back().pElemDesc;
                    if (ptopDesc && ptopDesc->ElemId == pdesc->ElemId)
                    {
                        matched = true;
                        break;
                    }
                    elemStack.PopBack();
                }
                if (!matched)
                    continue;
            }

            StackElem& top = elemStack.Back();
            const bool displaySet = top.ParaFmt.IsDisplaySet();
            const ParagraphFormat::DisplayType display = top.ParaFmt.GetDisplay();
            const UPInt startPos = top.StartPos;
            pcurDesc = top.pElemDesc;
            elemStack.PopBack();
            if (!pcurDesc)
            {
                if (pstyleMgr && displaySet)
                {
                    if (display == ParagraphFormat::Display_Block)
                    {
                        if (multiline)
                            AppendHTMLNewLine(self, lastFmt, defParaFmt);
                    }
                    else if (display == ParagraphFormat::Display_None)
                    {
                        const UPInt len = self->GetLength();
                        if (multiline)
                            AppendHTMLNewLine(self, lastFmt, defParaFmt);
                        self->Remove(startPos, len - startPos);
                    }
                }
            }
            else if (pcurDesc->ElemId == HTML_LI ||
                     (pcurDesc->ElemId == HTML_P && (--paraCount, state != SGMLPS_EMPTY_ELEMENT_FINISHED)))
            {
                if (multiline)
                    AppendHTMLNewLine(self, lastFmt, defParaFmt);
            }
        }
        else if (state == SGMLPS_START_ELEMENT)
        {
            const wchar_t* elemName;
            UPInt elemLen;
            parser.ParseStartElement(&elemName, &elemLen);
            pcurDesc = FindHTMLDesc(HTMLElementsTable, elemName, elemLen);
            const SPInt parentIdx = (SPInt)elemStack.GetSize() - 1;

            if (pcurDesc && pcurDesc->EmptyElement)
            {
                if (pcurDesc->ElemId == HTML_BR)
                {
                    if (multiline)
                        AppendHTMLNewLine(self, lastFmt, defParaFmt);
                }
                else if (pcurDesc->ElemId == HTML_IMG)
                {
                    if (!pimgInfoArr)
                        continue;
                    pimgInfoArr->PushBack(StyledText::HTMLImageTagInfo(pheap));
                    StyledText::HTMLImageTagInfo& imgInfo = pimgInfoArr->Back();
                    Paragraph* ppara = self->GetLastParagraph();
                    if (!ppara)
                        ppara = self->AppendNewParagraph(&defParaFmt);
                    TextFormat imgFmt(defTextFmt);
                    imgInfo.ParaId = ppara->GetId();

                    const wchar_t* attrName;
                    UPInt attrLen;
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        const wchar_t* value;
                        UPInt valueLen;
                        if (!pattr || !parser.GetNextAttributeValue(&value, &valueLen))
                            continue;
                        int v;
                        switch (pattr->ElemId)
                        {
                        case HTML_ALIGN:
                            if (const SGMLElementDesc* pval = FindHTMLDesc(HTMLAttrsTable, value, valueLen))
                            {
                                if (pval->ElemId == HTML_BASELINE)
                                    imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_BaseLine;
                                else if (pval->ElemId == HTML_LEFT)
                                    imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_Left;
                                else if (pval->ElemId == HTML_RIGHT)
                                    imgInfo.Alignment = StyledText::HTMLImageTagInfo::Align_Right;
                            }
                            break;
                        case HTML_HEIGHT:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                imgInfo.Height = (unsigned)PixelsToFixp(v);
                            break;
                        case HTML_HSPACE:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen))
                                imgInfo.HSpace = PixelsToFixp(v);
                            break;
                        case HTML_ID:
                            imgInfo.Id.AppendString(value, valueLen);
                            break;
                        case HTML_SRC:
                            imgInfo.Url.AppendString(value, valueLen);
                            break;
                        case HTML_VSPACE:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen))
                                imgInfo.VSpace = PixelsToFixp(v);
                            break;
                        case HTML_WIDTH:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                imgInfo.Width = (unsigned)PixelsToFixp(v);
                            break;
                        default:
                            break;
                        }
                    }

                    Ptr<HTMLImageTagDesc> pimgDesc = *SF_HEAP_AUTO_NEW(self) HTMLImageTagDesc;
                    imgFmt.SetImageDesc(pimgDesc);
                    pimgDesc->ScreenWidth = (float)imgInfo.Width;
                    pimgDesc->ScreenHeight = (float)imgInfo.Height;
                    pimgDesc->VSpace = imgInfo.VSpace;
                    pimgDesc->HSpace = imgInfo.HSpace;
                    pimgDesc->Url = imgInfo.Url;
                    pimgDesc->Id = imgInfo.Id;
                    pimgDesc->Alignment = imgInfo.Alignment;
                    imgInfo.pTextImageDesc = pimgDesc;

                    TextFormat* pparentFmt = (parentIdx < 0) ? &defTextFmt : &elemStack[parentIdx].TextFmt;
                    ParagraphFormat* pparentPara = (parentIdx < 0) ? &defParaFmt : &elemStack[parentIdx].ParaFmt;
                    if (pparentFmt->IsUrlSet())
                        imgFmt.SetUrl(pparentFmt->GetUrl());
                    self->AppendString(" ", 1, StyledText::NLP_ReplaceCRLF, &imgFmt, pparentPara);
                    // the text after the image must not repeat it
                    pparentFmt->SetImageDesc(0);
                    lastFmt.SetImageDesc(0);
                    self->SetDefaultTextFormat(*pparentFmt);
                }
                else if (pcurDesc->ElemId == HTML_TAB)
                    self->AppendString("\t", 1, StyledText::NLP_ReplaceCRLF);
                continue;
            }

            const UPInt startPos = self->GetLength();
            {
                StackElem newElem(pheap);
                newElem.pElemName = elemName;
                newElem.ElemNameSize = elemLen;
                newElem.pElemDesc = pcurDesc;
                elemStack.PushBack(newElem);
            }
            StackElem& elem = elemStack.Back();
            elem.StartPos = startPos;
            TextFormat* pfmt = &elem.TextFmt;
            ParagraphFormat* ppfmt = &elem.ParaFmt;
            if (parentIdx < 0)
            {
                *pfmt = defTextFmt;
                *ppfmt = defParaFmt;
            }
            else
            {
                *pfmt = elemStack[parentIdx].TextFmt;
                *ppfmt = elemStack[parentIdx].ParaFmt;
            }

            if (!pcurDesc)
            {
                // an unknown tag still takes the style sheet's style of that name
                if (pstyleMgr)
                {
                    if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen))
                    {
                        *ppfmt = ppfmt->Merge(pstyle->mParagraphFormat);
                        *pfmt = pfmt->Merge(pstyle->mTextFormat);
                    }
                }
            }
            else
            {
                const wchar_t* attrName;
                UPInt attrLen;
                const wchar_t* value;
                UPInt valueLen;
                switch (pcurDesc->ElemId)
                {
                case HTML_A:
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        if (pattr && parser.GetNextAttributeValue(&value, &valueLen) && pattr->ElemId == HTML_HREF)
                        {
                            pfmt->SetUrl(value, valueLen);
                            self->SetMayHaveUrl();
                        }
                    }
                    if (pstyleMgr)
                    {
                        if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, "a"))
                            *pfmt = pfmt->Merge(pstyle->mTextFormat);
                        if (pfmt->IsUrlSet())
                        {
                            if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, "a:link"))
                                *pfmt = pfmt->Merge(pstyle->mTextFormat);
                        }
                    }
                    break;
                case HTML_B:
                    pfmt->SetBold(true);
                    break;
                case HTML_FONT:
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        if (!pattr || !parser.GetNextAttributeValue(&value, &valueLen))
                            continue;
                        UInt32 hex;
                        int v;
                        float f;
                        switch (pattr->ElemId)
                        {
                        case HTML_ALPHA:
                            if (*value == '#' && SGMLParser<wchar_t>::ParseHexInt(&hex, value + 1, valueLen - 1))
                                pfmt->SetAlpha((UInt8)hex);
                            break;
                        case HTML_COLOR:
                            if (*value == '#' && SGMLParser<wchar_t>::ParseHexInt(&hex, value + 1, valueLen - 1))
                                pfmt->SetColor32(hex);
                            break;
                        case HTML_FACE:
                            pfmt->SetFontList(value, valueLen);
                            break;
                        case HTML_KERNING:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                            {
                                if (v == 0)
                                    pfmt->ClearKerning();
                                else
                                    pfmt->SetKerning(true);
                            }
                            break;
                        case HTML_LETTERSPACING:
                            if (SGMLParser<wchar_t>::ParseFloat(&f, value, valueLen))
                                pfmt->SetLetterSpacing(f);
                            break;
                        case HTML_SIZE:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                pfmt->SetFontSize((float)v);
                            break;
                        default:
                            break;
                        }
                    }
                    lastFmt = *pfmt;
                    break;
                case HTML_I:
                    pfmt->SetItalic(true);
                    break;
                case HTML_LI:
                {
                    ppfmt->SetBullet();
                    Paragraph* ppara = self->GetLastParagraph();
                    if (!ppara)
                        ppara = self->AppendNewParagraph(ppfmt);
                    else
                    {
                        if (ppara->GetLength() != 0)
                        {
                            if (multiline)
                                AppendHTMLNewLine(self, lastFmt, defParaFmt);
                            ppara = self->GetLastParagraph();
                        }
                        ppara->SetFormat(self->GetAllocator(), *ppfmt);
                    }
                    if (pstyleMgr)
                    {
                        if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen))
                        {
                            *ppfmt = ppfmt->Merge(pstyle->mParagraphFormat);
                            *pfmt = pfmt->Merge(pstyle->mTextFormat);
                            ppara->SetFormat(self->GetAllocator(), *ppfmt);
                        }
                    }
                    break;
                }
                case HTML_P:
                {
                    Paragraph* ppara = self->GetLastParagraph();
                    if (!ppara)
                        ppara = self->AppendNewParagraph(&defParaFmt);
                    else if (paraCount != 0)
                    {
                        if (multiline)
                            AppendHTMLNewLine(self, lastFmt, defParaFmt);
                        ppara = self->GetLastParagraph();
                    }
                    if (pstyleMgr)
                    {
                        if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Tag, elemName, elemLen))
                        {
                            *ppfmt = ppfmt->Merge(pstyle->mParagraphFormat);
                            *pfmt = pfmt->Merge(pstyle->mTextFormat);
                        }
                    }
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        if (!pattr || !parser.GetNextAttributeValue(&value, &valueLen))
                            continue;
                        if (pattr->ElemId == HTML_ALIGN)
                        {
                            const SGMLElementDesc* pval = FindHTMLDesc(HTMLAttrsTable, value, valueLen);
                            if (!pval)
                                continue;
                            if (pval->ElemId == HTML_LEFT)
                                ppfmt->SetAlignment(ParagraphFormat::Align_Left);
                            else if (pval->ElemId == HTML_RIGHT)
                                ppfmt->SetAlignment(ParagraphFormat::Align_Right);
                            else if (pval->ElemId == HTML_CENTER)
                                ppfmt->SetAlignment(ParagraphFormat::Align_Center);
                            else if (pval->ElemId == HTML_JUSTIFY)
                                ppfmt->SetAlignment(ParagraphFormat::Align_Justify);
                        }
                        else if (pattr->ElemId == HTML_CLASS && pstyleMgr)
                        {
                            if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Class, value, valueLen))
                            {
                                *ppfmt = ppfmt->Merge(pstyle->mParagraphFormat);
                                *pfmt = pfmt->Merge(pstyle->mTextFormat);
                            }
                        }
                    }
                    if (ppara->GetLength() == 0)
                        ppara->SetFormat(self->GetAllocator(), *ppfmt);
                    ++paraCount;
                    break;
                }
                case HTML_SPAN:
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        if (pattr && parser.GetNextAttributeValue(&value, &valueLen) &&
                            pattr->ElemId == HTML_CLASS && pstyleMgr)
                        {
                            if (const Style* pstyle = pstyleMgr->GetStyle(StyleManagerBase::CSS_Class, value, valueLen))
                            {
                                *pfmt = pfmt->Merge(pstyle->mTextFormat);
                                lastFmt = *pfmt;
                            }
                        }
                    }
                    break;
                case HTML_TEXTFORMAT:
                    while (parser.GetNextAttribute(&attrName, &attrLen))
                    {
                        const SGMLElementDesc* pattr = FindHTMLDesc(HTMLAttrsTable, attrName, attrLen);
                        if (!pattr || !parser.GetNextAttributeValue(&value, &valueLen))
                            continue;
                        int v;
                        switch (pattr->ElemId)
                        {
                        case HTML_BLOCKINDENT:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                ppfmt->SetBlockIndent((unsigned)v);
                            break;
                        case HTML_INDENT:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen))
                                ppfmt->SetIndent(v);
                            break;
                        case HTML_LEADING:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen))
                                ppfmt->SetLeading(v);
                            break;
                        case HTML_LEFTMARGIN:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                ppfmt->SetLeftMargin((unsigned)v);
                            break;
                        case HTML_RIGHTMARGIN:
                            if (SGMLParser<wchar_t>::ParseInt(&v, value, valueLen) && v >= 0)
                                ppfmt->SetRightMargin((unsigned)v);
                            break;
                        case HTML_TABSTOPS:
                        {
                            // "[a, b, ...]" or "a, b, ...": one stop per comma-separated number
                            UPInt i = 0;
                            while (i < valueLen && SGMLCharIter<wchar_t>::IsSpace(value[i]))
                                ++i;
                            if (value[i] == '[')
                                ++i;
                            unsigned num = 1;
                            for (UPInt j = i; j < valueLen && value[j] != ']'; ++j)
                            {
                                if (value[j] == ',')
                                    ++num;
                            }
                            ppfmt->BeginTabStops(num);
                            unsigned idx = 0;
                            while (i < valueLen && value[i] != ']')
                            {
                                unsigned stop = 0;
                                for (; i < valueLen && SGMLCharIter<wchar_t>::IsDigit(value[i]); ++i)
                                    stop = stop * 10 + (value[i] - '0');
                                while (i < valueLen && SFiswspace(value[i]))
                                    ++i;
                                ppfmt->SetTabStopsElement(idx++, stop);
                                if (value[i] == ',')
                                {
                                    for (++i; i < valueLen && SFiswspace(value[i]); ++i)
                                        ;
                                }
                            }
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    break;
                case HTML_U:
                    pfmt->SetUnderline(true);
                    break;
                default:
                    break;
                }
            }
            lastFmt = *pfmt;
        }
    }

    if (elemStack.GetSize() != 0)
    {
        StackElem& top = elemStack.Back();
        self->SetDefaultTextFormat(top.TextFmt);
        self->SetDefaultParagraphFormat(top.ParaFmt);
        lastFmt = top.TextFmt;
    }
    else
    {
        self->SetDefaultTextFormat(defTextFmt);
        self->SetDefaultParagraphFormat(defParaFmt);
    }
    self->EnsureTermNull();

    // the empty paragraphs at the end take the last format, so a caret there shows it
    Paragraph* plast = self->GetLastParagraph();
    if (plast && plast->GetLength() == 0)
    {
        for (SPInt i = (SPInt)self->GetParagraphsCount() - 1; i >= 0; --i)
        {
            Paragraph* ppara = const_cast<Paragraph*>(self->GetParagraph((unsigned)i));
            if (ppara->GetLength() > 1)
                break;
            ppara->SetTextFormat(self->GetAllocator(), lastFmt, 0, SF_MAX_UPINT);
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

// MS2-PIN: ?PopBack@?$ArrayBase@U?$ArrayDataDH@U?$SGMLStackElemDesc@_W@Text@Render@Scaleform@@U?$AllocatorDH@U?$SGMLStackElemDesc@_W@Text@Render@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14267f410
// MS2-PIN: ??_7HTMLImageTagDesc@Text@Render@Scaleform@@6B@ 0x143191bb8
// MS2-PIN: ??_7ImageDesc@Text@Render@Scaleform@@6B@ 0x14317c9c0
// MS2-PIN: ??_7?$RefCountBaseNTS@UImageDesc@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
