// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 Text_StyleSheet: the CSS parser
// behind TextField.StyleSheet - a tokenizer, a selector/property parser driving a handler, and the handler that turns
// the properties into the TextFormat / ParagraphFormat of the StyleManager's styles.
// Queue unit sfr_gfx_06 is split along its original sources (06 DisplayObject, 06b InteractiveObject, 06c
// DisplayList, 06d DisplayObjContainer, 06e DrawingContext, 06f Input, 06g Text_StyleSheet).
// MS2-UNIT: sfr_gfx_06g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142608a30-0x14260c6d0 .text$mn
// MS2-PIN: ??_7?$CSSHandler@_W@Text@GFx@Scaleform@@6B@ 0x14318e930
// MS2-PIN: ??_7?$TextStyleParserHandler@_W@Text@GFx@Scaleform@@6B@ 0x14318e950
// MS2-PIN: ??_G?$CSSHandler@_W@Text@GFx@Scaleform@@UEAAPEAXI@Z 0x1426091e0
// MS2-PIN: ??_7StyleManagerBase@Text@Render@Scaleform@@6B@ 0x14316a718
// MS2-PIN: ??_7StyleManager@Text@GFx@Scaleform@@6B@ 0x14316a738
// MS2-PIN: ?ParseFloat@?$SGMLParser@_W@Text@Render@Scaleform@@SA_NPEAMPEB_W_K@Z 0x14260b880
// MS2-PIN: ?StrCompare@?$SGMLCharIter@_W@Text@Render@Scaleform@@SAHPEB_WPEBD_K@Z 0x14260c3d0
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/include/render/text_sgmlparser.h"
#include "ms2/scaleform/include/gfx/text_stylesheet.h"

// The HTML parser's case-insensitive compare is emitted here (exe 0x14260c3d0).
template class Scaleform::Render::Text::SGMLCharIter<wchar_t>;

namespace Scaleform { namespace GFx { namespace Text {

using Render::Text::ParagraphFormat;
using Render::Text::SGMLCharIter;
using Render::Text::SGMLParser;

// ---------------------------------------------------------------------------------------------------------------
// Tokens

template<class T>
struct CSSToken
{
    enum TokenType
    {
        TT_Name,
        TT_QString,
        TT_WhiteSpace, // also comments
        TT_Number,
        TT_HexNumber,
        TT_Comma,
        TT_OpenBrace,
        TT_CloseBrace,
        TT_SemiColon,
        TT_Colon,
        TT_EOF,
        TT_Unknown
    };

    TokenType Type;   // +0
    const T*  pBase;  // +8
    UPInt     Length; // +0x10

    CSSToken() : Type(TT_Unknown), pBase(0), Length(0) {}
    CSSToken(TokenType type) : Type(type), pBase(0), Length(0) {}

    bool operator==(TokenType type) const { return Type == type; }
    // Extends the token over the one that follows it.
    void operator+=(const CSSToken& tok) { Length += tok.Length; }
};

template<class T>
class CSSTokenizer
{
public:
    CSSTokenizer(const T* buffer, UPInt len)
        : pCurr(buffer), pEnd(buffer + len), CurrentToken(CSSToken<T>::TT_Unknown), LineNo(1), ColNo(1), LineDev(0),
          ColDev(0)
    {
    }

    CSSToken<T> GetNextToken();

    UPInt GetLineNo() const { return LineNo; }
    UPInt GetColNo() const  { return ColNo; }

private:
    const T*    pCurr;        // +0
    const T*    pEnd;         // +8
    CSSToken<T> CurrentToken; // +0x10
    UPInt       LineNo;       // +0x28
    UPInt       ColNo;        // +0x30
    UPInt       LineDev;      // +0x38 lines and columns the current token spans
    UPInt       ColDev;       // +0x40

    int IsSpace(T c)  { return SFiswspace(c); }
    int IsDigit(T c);
    int IsXDigit(T c) { return SFiswxdigit(c); }
    int IsAlpha(T c)  { return SFiswalpha(c); }
    int IsAlNum(T c)  { return SFiswalnum(c); }
};

// Out of line in the exe (the coverage calls it IsSpace).
// @0x14260b180
template<>
int CSSTokenizer<wchar_t>::IsDigit(wchar_t c)
{
    return SFiswdigit(c);
}

// @0x1426097a0
// MS2-FUNCTIONAL: the exe keeps the quoted-string counters in memory and reloads pEnd in that loop; ours keeps them in registers
template<class T>
CSSToken<T> CSSTokenizer<T>::GetNextToken()
{
    if (CurrentToken == CSSToken<T>::TT_EOF)
        return CSSToken<T>::TT_EOF;

    pCurr += CurrentToken.Length;
    CurrentToken.pBase  = pCurr;
    CurrentToken.Length = 1;
    LineNo += LineDev;
    ColNo += ColDev;
    LineDev = 0;
    ColDev  = 0;

    const T* pstr = pCurr;
    if (pstr == pEnd)
        CurrentToken = CSSToken<T>::TT_EOF;
    else if (IsSpace(*pstr))
    {
        for (;;)
        {
            if (*pstr == '\n')
            {
                LineDev++;
                ColDev = 0;
            }
            pstr++;
            ColDev++;
            if (pstr == pEnd || !IsSpace(*pstr))
                break;
            CurrentToken.Length++;
        }
        CurrentToken.Type = CSSToken<T>::TT_WhiteSpace;
    }
    else if (*pstr == '/')
    {
        // only a comment may start with '/'; anything else ends the parse
        CurrentToken.Type = CSSToken<T>::TT_WhiteSpace;
        pstr++;
        ColDev++;
        if (*pstr != '*')
        {
            pCurr             = pEnd;
            CurrentToken.Type = CSSToken<T>::TT_EOF;
        }
        else
        {
            CurrentToken.Length++;
            CurrentToken.Type = CSSToken<T>::TT_WhiteSpace;
            bool star         = false;
            for (;;)
            {
                if (*pstr == '\n')
                {
                    LineDev++;
                    ColDev = 0;
                }
                pstr++;
                ColDev++;
                if (pstr == pEnd)
                    break;
                if (*pstr == '*')
                    star = true;
                else if (star && *pstr == '/')
                {
                    pstr++;
                    ColDev++;
                    CurrentToken.Length++;
                    break;
                }
                else
                    star = false;
                CurrentToken.Length++;
            }
        }
    }
    else if (IsAlpha(*pstr) || *pstr == '_' || *pstr == '.')
    {
        for (;;)
        {
            pstr++;
            ColDev++;
            if (pstr == pEnd || !(IsAlNum(*pstr) || *pstr == '-' || *pstr == '_'))
                break;
            CurrentToken.Length++;
        }
        CurrentToken.Type = CSSToken<T>::TT_Name;
    }
    else if (*pstr == '"')
    {
        for (;;)
        {
            pstr++;
            ColDev++;
            if (pstr == pEnd || *pstr == '"')
                break;
            CurrentToken.Length++;
        }
        // the closing quote belongs to the token
        ColDev++;
        CurrentToken.Length++;
        CurrentToken.Type = CSSToken<T>::TT_QString;
    }
    else if (IsDigit(*pstr))
    {
        for (;;)
        {
            pstr++;
            ColDev++;
            if (pstr == pEnd || !(IsDigit(*pstr) || *pstr == '.'))
                break;
            CurrentToken.Length++;
        }
        CurrentToken.Type = CSSToken<T>::TT_Number;
        if (*pstr == '.')
        {
            CurrentToken.Length++;
            pstr++;
            ColDev++;
            for (;;)
            {
                pstr++;
                ColDev++;
                if (pstr == pEnd || !IsDigit(*pstr))
                    break;
                CurrentToken.Length++;
            }
        }
    }
    else if (*pstr == '#')
    {
        for (;;)
        {
            pstr++;
            ColDev++;
            if (pstr == pEnd || !IsXDigit(*pstr))
                break;
            CurrentToken.Length++;
        }
        CurrentToken.Type = CSSToken<T>::TT_HexNumber;
    }
    else
    {
        switch (*pstr)
        {
        case ',': CurrentToken.Type = CSSToken<T>::TT_Comma; break;
        case ';': CurrentToken.Type = CSSToken<T>::TT_SemiColon; break;
        case ':': CurrentToken.Type = CSSToken<T>::TT_Colon; break;
        case '{': CurrentToken.Type = CSSToken<T>::TT_OpenBrace; break;
        case '}': CurrentToken.Type = CSSToken<T>::TT_CloseBrace; break;
        default:  CurrentToken.Type = CSSToken<T>::TT_Unknown;
        }
        ColDev++;
    }
    return CurrentToken;
}

// ---------------------------------------------------------------------------------------------------------------
// Parser

// Receives the selectors and properties in parse order (vftable 0x14318e930).
template<class T>
class CSSHandler
{
public:
    virtual ~CSSHandler() {}
    virtual void OpenCSSSelectorBlock(const CSSToken<T>& name, void* pdata)                                    = 0;
    virtual void CloseCSSSelectorBlock(void* pdata)                                                            = 0;
    virtual void PushCSSSelectorProperty(const CSSToken<T>& name, const Array<CSSToken<T> >& value, void* pdata) = 0;
};

template<class T>
class CSSParser
{
    enum ParseState
    {
        PS_ReadStyleName,
        PS_ReadPropertyName,
        PS_ReadPropertyValue,
        PS_Success,
        PS_Error
    };

    CSSToken<T>          SelectorName;  // +0
    CSSToken<T>          PropertyName;  // +0x18
    Array<CSSToken<T> >  PropertyValue; // +0x30
    bool                 bPseudoClass;  // +0x48 the selector name continues after a ':'
    bool                 bPropValSpool; // +0x49 a property value is being collected
    UPInt                PropValLinePos, PropValColPos;

public:
    CSSParser() : bPseudoClass(false), bPropValSpool(false) {}

    bool Parse(const T* buffer, UPInt len, CSSHandler<T>* handler, void* pdata);
};

// @0x14260b3f0
template<class T>
bool CSSParser<T>::Parse(const T* buffer, UPInt len, CSSHandler<T>* handler, void* pdata)
{
    CSSTokenizer<T> tokens(buffer, len);
    CSSToken<T>     token;
    ParseState      state         = PS_ReadStyleName;
    bool            preserveToken = false;
    bool            done          = false;

    while (!done)
    {
        if (state == PS_Error)
            break;
        if (!preserveToken)
            token = tokens.GetNextToken();
        else
            preserveToken = false;

        if (token == CSSToken<T>::TT_EOF)
            state = PS_Success;

        switch (state)
        {
        case PS_ReadStyleName:
            switch (token.Type)
            {
            case CSSToken<T>::TT_WhiteSpace:
                if (bPseudoClass)
                    state = PS_Error;
                break;
            case CSSToken<T>::TT_Name:
                if (!bPseudoClass)
                {
                    SelectorName = token;
                    token        = tokens.GetNextToken();
                    if (token == CSSToken<T>::TT_Colon)
                    {
                        SelectorName += token;
                        bPseudoClass = true;
                        break;
                    }
                    preserveToken = true;
                }
                else
                    SelectorName += token;

                handler->OpenCSSSelectorBlock(SelectorName, pdata);

                if (!preserveToken)
                    token = tokens.GetNextToken();
                else
                    preserveToken = false;
                if (token == CSSToken<T>::TT_WhiteSpace)
                    token = tokens.GetNextToken();
                switch (token.Type)
                {
                case CSSToken<T>::TT_Comma:
                    state        = PS_ReadStyleName;
                    bPseudoClass = false;
                    break;
                case CSSToken<T>::TT_OpenBrace:
                    state        = PS_ReadPropertyName;
                    bPseudoClass = false;
                    break;
                default:
                    state = PS_Error;
                }
                break;
            default:
                state = PS_Error;
            }
            break;

        case PS_ReadPropertyName:
            switch (token.Type)
            {
            case CSSToken<T>::TT_WhiteSpace:
                break;
            case CSSToken<T>::TT_CloseBrace:
                handler->CloseCSSSelectorBlock(pdata);
                state = PS_ReadStyleName;
                break;
            case CSSToken<T>::TT_Name:
                PropertyName = token;
                token        = tokens.GetNextToken();
                if (token == CSSToken<T>::TT_WhiteSpace)
                    token = tokens.GetNextToken();
                state = (token == CSSToken<T>::TT_Colon) ? PS_ReadPropertyValue : PS_Error;
                break;
            default:
                state = PS_Error;
            }
            break;

        case PS_ReadPropertyValue:
            switch (token.Type)
            {
            case CSSToken<T>::TT_SemiColon:
                handler->PushCSSSelectorProperty(PropertyName, PropertyValue, pdata);
                bPropValSpool = false;
                state         = PS_ReadPropertyName;
                break;
            case CSSToken<T>::TT_CloseBrace:
                handler->PushCSSSelectorProperty(PropertyName, PropertyValue, pdata);
                handler->CloseCSSSelectorBlock(pdata);
                bPropValSpool = false;
                state         = PS_ReadStyleName;
                break;
            default:
                if (!bPropValSpool)
                {
                    PropertyValue.Clear();
                    bPropValSpool = true;
                    if (token == CSSToken<T>::TT_WhiteSpace)
                        token = tokens.GetNextToken();
                    PropValLinePos = tokens.GetLineNo();
                    PropValColPos  = tokens.GetColNo();
                }
                PropertyValue.PushBack(token);
            }
            break;

        default:
            done = true;
        }
    }
    return state == PS_Success;
}

// ---------------------------------------------------------------------------------------------------------------
// The handler that fills the StyleManager (0x10 bytes, vftable 0x14318e950)

template<class T>
class TextStyleParserHandler : public CSSHandler<T>
{
public:
    TextStyleParserHandler(StyleManager* manager) : pManager(manager) {}
    virtual ~TextStyleParserHandler() {}

    void OpenCSSSelectorBlock(const CSSToken<T>& name, void* pdata);
    void CloseCSSSelectorBlock(void* pdata);
    void PushCSSSelectorProperty(const CSSToken<T>& name, const Array<CSSToken<T> >& value, void* pdata);

private:
    void HandleColor(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleDisplay(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleFontFamily(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleFontSize(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleFontStyle(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleFontWeight(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleKerning(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleLeading(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleLetterSpacing(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleMarginLeft(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleMarginRight(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleTextAlign(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleTextDecoration(const Array<Style*>& styles, const Array<CSSToken<T> >& value);
    void HandleTextIndent(const Array<Style*>& styles, const Array<CSSToken<T> >& value);

    // Compares a keyword value without regard to case; only the first size characters count.
    static bool IsKeyword(const char* keyword, const T* pstr, UPInt size)
    {
        return SGMLCharIter<T>::StrCompare(pstr, keyword, size) == 0;
    }
    Style* GetStyle(const StyleKey& key)
    {
        Style** ppstyle = pManager->Styles.Get(key);
        return ppstyle ? *ppstyle : 0;
    }
    void AddStyle(const StyleKey& key, Style* pstyle) { pManager->Styles.Add(key, pstyle); }

    StyleManager* pManager; // +8
};

// @0x14260b1d0
template<class T>
void TextStyleParserHandler<T>::OpenCSSSelectorBlock(const CSSToken<T>& name, void* pdata)
{
    String                     keystr;
    StyleManagerBase::KeyType type = StyleManagerBase::CSS_Tag;
    if (name.Length > 0 && name.pBase[0] == '.')
    {
        type = StyleManagerBase::CSS_Class;
        keystr.AppendString(name.pBase + 1, name.Length - 1);
    }
    else
        keystr.AppendString(name.pBase, name.Length);

    const StyleKey& key    = pManager->GetTempStyleKey(type, keystr);
    Style*          pstyle = GetStyle(key);
    if (!pstyle)
    {
        MemoryHeap* pheap = Memory::GetHeapByAddress(pManager);
        pstyle            = SF_HEAP_NEW(pheap) Style(pheap);
        AddStyle(key, pstyle);
    }
    else
        pstyle->Reset();

    ((Array<Style*>*)pdata)->PushBack(pstyle);
}

// @0x142609720
template<class T>
void TextStyleParserHandler<T>::CloseCSSSelectorBlock(void* pdata)
{
    ((Array<Style*>*)pdata)->Clear();
}

// @0x14260ba90
template<class T>
void TextStyleParserHandler<T>::PushCSSSelectorProperty(const CSSToken<T>& name, const Array<CSSToken<T> >& value,
                                                        void* pdata)
{
    String sname;
    sname.AppendString(name.pBase, name.Length);

    const Array<Style*>& styles = *(Array<Style*>*)pdata;
    if (value.GetSize() < 1)
        return;

    if (sname == "color")
        HandleColor(styles, value);
    else if (sname == "display")
        HandleDisplay(styles, value);
    else if (sname == "font-family")
        HandleFontFamily(styles, value);
    else if (sname == "font-size")
        HandleFontSize(styles, value);
    else if (sname == "font-style")
        HandleFontStyle(styles, value);
    else if (sname == "font-weight")
        HandleFontWeight(styles, value);
    else if (sname == "kerning")
        HandleKerning(styles, value);
    else if (sname == "leading")
        HandleLeading(styles, value);
    else if (sname == "letter-spacing")
        HandleLetterSpacing(styles, value);
    else if (sname == "margin-left")
        HandleMarginLeft(styles, value);
    else if (sname == "margin-right")
        HandleMarginRight(styles, value);
    else if (sname == "text-align")
        HandleTextAlign(styles, value);
    else if (sname == "text-decoration")
        HandleTextDecoration(styles, value);
    else if (sname == "text-indent")
        HandleTextIndent(styles, value);
}

// "#rrggbb"; the alpha of the format stays.
// @0x142609e70
template<class T>
void TextStyleParserHandler<T>::HandleColor(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_HexNumber || value[idx].Length != 7)
        return;
    UInt32 color = 0;
    SGMLParser<T>::ParseHexInt(&color, value[idx].pBase + 1, value[idx].Length - 1);
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mTextFormat.SetColor32(color);
}

// @0x142609f70
template<class T>
void TextStyleParserHandler<T>::HandleDisplay(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    ParagraphFormat::DisplayType display = ParagraphFormat::Display_Inline;
    if (IsKeyword("inline", pstr, (size < 6) ? size : 6))
        display = ParagraphFormat::Display_Inline;
    else if (IsKeyword("block", pstr, (size < 5) ? size : 5))
        display = ParagraphFormat::Display_Block;
    else if (IsKeyword("none", pstr, (size < 4) ? size : 4))
        display = ParagraphFormat::Display_None;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mParagraphFormat.SetDisplay(display);
}

// A comma separated list of names or quoted names.
// @0x14260a1d0
template<class T>
void TextStyleParserHandler<T>::HandleFontFamily(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt        idx = 0;
    UPInt        num = value.GetSize();
    StringBuffer fontList;
    while (idx < num)
    {
        if (fontList.GetSize() > 0)
            fontList.AppendChar(',');
        if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
        {
            idx++;
            if (num < idx + 1)
                return;
        }
        if (value[idx].Type != CSSToken<T>::TT_Name &&
            !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
            return;
        const T* pstr = value[idx].pBase;
        UPInt    size = value[idx].Length;
        if (value[idx].Type == CSSToken<T>::TT_QString)
        {
            pstr++;
            size -= 2;
        }
        fontList.AppendString(pstr, size);
        // skip to the next name
        while (idx < num && value[idx++].Type != CSSToken<T>::TT_Comma)
        {
        }
    }
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mTextFormat.SetFontList(fontList.ToCStr());
}

// @0x14260a320
template<class T>
void TextStyleParserHandler<T>::HandleFontSize(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mTextFormat.SetFontSize(num);
}

// @0x14260a3e0
template<class T>
void TextStyleParserHandler<T>::HandleFontStyle(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    if (IsKeyword("normal", pstr, (size < 6) ? size : 6))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetItalic(false);
    }
    else if (IsKeyword("italic", pstr, (size < 6) ? size : 6))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetItalic(true);
    }
}

// @0x14260a5b0
template<class T>
void TextStyleParserHandler<T>::HandleFontWeight(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    if (IsKeyword("normal", pstr, (size < 6) ? size : 6))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetBold(false);
    }
    else if (IsKeyword("bold", pstr, (size < 4) ? size : 4))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetBold(true);
    }
}

// @0x14260a780
template<class T>
void TextStyleParserHandler<T>::HandleKerning(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    if (IsKeyword("true", pstr, (size < 4) ? size : 4))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetKerning(true);
    }
    else if (IsKeyword("false", pstr, (size < 5) ? size : 5))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetKerning(false);
    }
}

// @0x14260a950
template<class T>
void TextStyleParserHandler<T>::HandleLeading(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mParagraphFormat.SetLeading((int)num);
}

// @0x14260a9f0
template<class T>
void TextStyleParserHandler<T>::HandleLetterSpacing(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mTextFormat.SetLetterSpacing(num);
}

// @0x14260aa90
template<class T>
void TextStyleParserHandler<T>::HandleMarginLeft(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mParagraphFormat.SetLeftMargin((unsigned)num);
}

// @0x14260ab30
template<class T>
void TextStyleParserHandler<T>::HandleMarginRight(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mParagraphFormat.SetRightMargin((unsigned)num);
}

// @0x14260abd0
template<class T>
void TextStyleParserHandler<T>::HandleTextAlign(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    if (IsKeyword("left", pstr, (size < 4) ? size : 4))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mParagraphFormat.SetAlignment(ParagraphFormat::Align_Left);
    }
    else if (IsKeyword("center", pstr, (size < 6) ? size : 6))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mParagraphFormat.SetAlignment(ParagraphFormat::Align_Center);
    }
    else if (IsKeyword("right", pstr, (size < 5) ? size : 5))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mParagraphFormat.SetAlignment(ParagraphFormat::Align_Right);
    }
    else if (IsKeyword("justify", pstr, (size < 7) ? size : 7))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mParagraphFormat.SetAlignment(ParagraphFormat::Align_Justify);
    }
}

// @0x14260af10
template<class T>
void TextStyleParserHandler<T>::HandleTextDecoration(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Name &&
        !(value[idx].Type == CSSToken<T>::TT_QString && value[idx].Length > 2))
        return;
    const T* pstr = value[idx].pBase;
    UPInt    size = value[idx].Length;
    if (value[idx].Type == CSSToken<T>::TT_QString)
    {
        pstr++;
        size -= 2;
    }

    if (IsKeyword("none", pstr, (size < 4) ? size : 4))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetUnderline(false);
    }
    else if (IsKeyword("underline", pstr, (size < 9) ? size : 9))
    {
        for (UPInt i = 0; i < styles.GetSize(); i++)
            styles[i]->mTextFormat.SetUnderline(true);
    }
}

// @0x14260b0e0
template<class T>
void TextStyleParserHandler<T>::HandleTextIndent(const Array<Style*>& styles, const Array<CSSToken<T> >& value)
{
    UPInt idx = 0;
    if (value[idx].Type == CSSToken<T>::TT_WhiteSpace)
    {
        idx++;
        if (value.GetSize() < 2)
            return;
    }
    if (value[idx].Type != CSSToken<T>::TT_Number)
        return;
    float num = 0;
    SGMLParser<T>::ParseFloat(&num, value[idx].pBase, value[idx].Length);
    if (num == 0)
        return;
    for (UPInt i = 0; i < styles.GetSize(); i++)
        styles[i]->mParagraphFormat.SetIndent((int)num);
}

// ---------------------------------------------------------------------------------------------------------------
// StyleManager

// @0x142609070
StyleManager::~StyleManager()
{
    ClearStyles();
}

// @0x142608a30
template<class Char>
bool StyleManager::ParseCSSImpl(const Char* buffer, UPInt len)
{
    CSSParser<Char>              parser;
    Array<Style*>                selectors;
    TextStyleParserHandler<Char> handler(this);
    return parser.Parse(buffer, len, &handler, &selectors);
}

// The UTF-8 text is parsed as wide characters.
// @0x14260b7f0
bool StyleManager::ParseCSS(const char* buffer, UPInt len)
{
    wchar_t* pwbuf = (wchar_t*)SF_ALLOC((len + 1) * sizeof(wchar_t), StatMV_Text_Mem);
    len            = UTF8Util::DecodeString(pwbuf, buffer, len);
    bool ok        = ParseCSSImpl<wchar_t>(pwbuf, len);
    SF_FREE(pwbuf);
    return ok;
}

// @0x14260b870
bool StyleManager::ParseCSS(const wchar_t* buffer, UPInt len)
{
    return ParseCSSImpl<wchar_t>(buffer, len);
}

// @0x142609c70
const Style* StyleManager::GetStyle(KeyType type, const String& name) const
{
    Style* const* ppstyle = Styles.Get(GetTempStyleKey(type, name));
    return ppstyle ? *ppstyle : 0;
}

// @0x142609d30
const Style* StyleManager::GetStyle(KeyType type, const char* name, UPInt len) const
{
    if (len == SF_MAX_UPINT)
        len = SFstrlen(name);
    String str(name, len);
    return GetStyle(type, str);
}

// @0x142609dc0
const Style* StyleManager::GetStyle(KeyType type, const wchar_t* name, UPInt len) const
{
    if (len == SF_MAX_UPINT)
        len = SFwcslen(name);
    String str;
    str.AppendString(name, len);
    return GetStyle(type, str);
}

// @0x142609e60
const StyleHash& StyleManager::GetStyles() const
{
    return Styles;
}

// @0x142609240
void StyleManager::AddStyle(const StyleKey& key, Style* pstyle)
{
    Styles.Add(key, pstyle);
}

// @0x1426093c0
void StyleManager::ClearStyle(KeyType type, const String& name)
{
    const StyleKey& key     = GetTempStyleKey(type, name);
    Style**         ppstyle = Styles.Get(key);
    if (ppstyle)
    {
        delete *ppstyle;
        Styles.Remove(key);
    }
}

// @0x1426095a0
void StyleManager::ClearStyle(KeyType type, const char* name, UPInt len)
{
    if (len == SF_MAX_UPINT)
        len = SFstrlen(name);
    String str(name, len);
    ClearStyle(type, str);
}

// @0x142609630
void StyleManager::ClearStyles()
{
    for (StyleHash::Iterator it = Styles.Begin(); it != Styles.End(); ++it)
        delete it->Second;
    Styles.Clear();
}

}}} // namespace Scaleform::GFx::Text
