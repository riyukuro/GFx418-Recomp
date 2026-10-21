// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text view TU
// (Text_DocView): DocView and its document, the emoticon image substitutor, scrolling / selection / line queries,
// the line formatter (ParagraphFormatter, GFxLineCursor) and the font lookup of a format run.
// MS2-UNIT: sfr_render_03b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14260c6d0-0x142615c70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/text_docview.h"

namespace Scaleform { namespace Render { namespace Text {

// ***** DocView

// @0x14260cc10
DocView::DocView(Allocator* pallocator, FontManagerBase* pfontMgr, Log* plog)
    : pFontManager(pfontMgr), pHighlight(NULL), pLog(plog), BorderColor(0), BackgroundColor(0)
{
    pDocument      = *SF_HEAP_AUTO_NEW(this) DocumentText(this, pallocator);
    FormatCounter  = 1;
    BeginSelection = EndSelection = SF_MAX_UPINT;
    SetAlignment(Align_Left);
    SetVAlignment(VAlign_None);
    SetTextAutoSize(TAS_None);
    Outline = 0;
    Flags = FlagsEx = RTFlags = 0;
    ViewRect.SetRect(0, 0, 0, 0);
    pImageSubstitutor = NULL;
    SetFontScaleFactor(1);
    MaxLength = 0;
    SetAutoFit();
    SetDefaultShadow();
    TextWidth = TextHeight = 0;
}

// @0x14260d050
DocView::~DocView()
{
    Close();
    ClearImageSubstitutor();
    delete pHighlight;
}

// The emoticon list is sorted by substring; a lookup matches the longest entry that prefixes the text.
struct ImageSubstCmp
{
    struct Comparable
    {
        const wchar_t* Str;
        UPInt          MaxSize;

        Comparable(const wchar_t* p, UPInt sz) : Str(p), MaxSize(sz) {}
    };

    // compares at most dstlen characters; for an insertion a shorter dst sorts by length
    static int StrCompare(const wchar_t* dst, UPInt dstlen, const wchar_t* src, UPInt srclen, bool insertion)
    {
        if (dstlen)
        {
            int f, l;
            int slen = (int)srclen, dlen = (int)dstlen;
            do
            {
                f = (int)*dst++;
                l = (int)*src++;
            } while (--dstlen && f && f == l && --srclen);

            if (f == l && srclen != 0 && (!insertion || dstlen != 0))
                return dlen - slen;
            return f - l;
        }
        return 0 - (int)srclen;
    }
    static int InsLess(const DocView::ImageSubstitutor::Element& p1, const Comparable& p2);
    static int Less(const DocView::ImageSubstitutor::Element& p1, const Comparable& p2);
    static int Equals(const DocView::ImageSubstitutor::Element& p1, const Comparable& p2)
    {
        return StrCompare(p2.Str, p2.MaxSize, p1.SubString, p1.SubStringLen, false) == 0;
    }
};

// @0x1426145c0
int ImageSubstCmp::InsLess(const DocView::ImageSubstitutor::Element& p1, const Comparable& p2)
{
    return -StrCompare(p2.Str, p2.MaxSize, p1.SubString, p1.SubStringLen, true) < 0;
}

// @0x142614b50
int ImageSubstCmp::Less(const DocView::ImageSubstitutor::Element& p1, const Comparable& p2)
{
    return -StrCompare(p2.Str, p2.MaxSize, p1.SubString, p1.SubStringLen, false) < 0;
}

// @0x14260dcc0
void DocView::ImageSubstitutor::AddImageDesc(const Element& elem)
{
    if (FindImageDesc(elem.SubString, elem.SubStringLen))
        return;
    ImageSubstCmp::Comparable e(elem.SubString, elem.SubStringLen);
    UPInt i = Alg::LowerBound(Elements, e, ImageSubstCmp::InsLess);
    Elements.InsertAt(i, elem);
}

// @0x14260f780
ImageDesc* DocView::ImageSubstitutor::FindImageDesc(const wchar_t* pstr, UPInt maxlen, UPInt* ptextLen)
{
    ImageSubstCmp::Comparable e(pstr, maxlen);
    UPInt i = Alg::LowerBound(Elements, e, ImageSubstCmp::Less);
    if (i < Elements.GetSize() && ImageSubstCmp::Equals(Elements[i], e))
    {
        if (ptextLen)
            *ptextLen = Elements[i].SubStringLen;
        return Elements[i].pImageDesc;
    }
    return NULL;
}

// @0x142614e30
void DocView::ImageSubstitutor::RemoveImageDesc(ImageDesc* pimgDesc)
{
    // the count is taken once (this build does not re-read it after a removal)
    UPInt n = Elements.GetSize();
    for (UPInt i = 0; i < n;)
    {
        if (Elements[i].pImageDesc == pimgDesc)
            Elements.RemoveAt(i);
        else
            ++i;
    }
}

// @0x1426155e0
void DocView::SetText(const char* putf8String, UPInt stringSize)
{
    pDocument->SetText(putf8String, stringSize);
    OnDocumentChanged(ViewNotify_SignificantTextChange | ViewNotify_ScrollingParamsChange);
}

// @0x142615610
void DocView::SetText(const wchar_t* pstring, UPInt length)
{
    pDocument->SetText(pstring, length);
    OnDocumentChanged(ViewNotify_SignificantTextChange | ViewNotify_ScrollingParamsChange);
}

// @0x142615640
void DocView::SetTextFormat(const TextFormat& fmt, UPInt startPos, UPInt endPos)
{
    RTFlags &= ~RTFlags_FontErrorDetected;
    pDocument->SetTextFormat(fmt, startPos, endPos);
    OnDocumentChanged(ViewNotify_FormatChange);
}

// @0x142615410
void DocView::SetParagraphFormat(const ParagraphFormat& fmt, UPInt startPos, UPInt endPos)
{
    pDocument->SetParagraphFormat(fmt, startPos, endPos);
    OnDocumentChanged(ViewNotify_FormatChange);
}

// @0x142614c70
void DocView::DocumentText::OnParagraphRemoving(const Paragraph& para)
{
    pDocument->OnDocumentParagraphRemoving(para);
}

// @0x142614c80
void DocView::DocumentText::OnTextInserting(UPInt, UPInt, const wchar_t*)
{
    pDocument->OnDocumentChanged(ViewNotify_TextChange);
}

// @0x142614c90
void DocView::DocumentText::OnTextInserting(UPInt, UPInt, const char*)
{
    pDocument->OnDocumentChanged(ViewNotify_TextChange);
}

// @0x142614ca0
void DocView::DocumentText::OnTextRemoving(UPInt, UPInt)
{
    pDocument->OnDocumentChanged(ViewNotify_TextChange);
}

// @0x1426134a0
String DocView::GetText() const
{
    return pDocument->GetText();
}

// @0x1426134c0
String& DocView::GetText(String* retStr) const
{
    return pDocument->GetText(retStr);
}

// @0x142612b90
String DocView::GetHtml() const
{
    return pDocument->GetHtml();
}

String& DocView::GetHtml(String* retStr) const
{
    return pDocument->GetHtml(retStr);
}

StringBuffer& DocView::GetHtml(StringBuffer* retStr) const
{
    return pDocument->GetHtml(retStr);
}

// @0x142614cb0
void DocView::ParseHtml(const char* putf8Str, UPInt utf8Len, bool condenseWhite,
                        StyledText::HTMLImageTagInfoArray* pimgInfoArr, const StyleManagerBase* pstyleMgr,
                        const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    pDocument->Clear();
    if (utf8Len == SF_MAX_UPINT)
        utf8Len = SFstrlen(putf8Str);
    pDocument->ParseHtml(putf8Str, utf8Len, pimgInfoArr, IsMultiline(), condenseWhite, pstyleMgr, txtFmt, paraFmt);
    OnDocumentChanged(ViewNotify_SignificantTextChange | ViewNotify_ScrollingParamsChange);
}

// @0x142614d60
void DocView::ParseHtml(const wchar_t* pwStr, UPInt strLen, bool condenseWhite,
                        StyledText::HTMLImageTagInfoArray* pimgInfoArr, const StyleManagerBase* pstyleMgr,
                        const TextFormat* txtFmt, const ParagraphFormat* paraFmt)
{
    pDocument->Clear();
    if (strLen == SF_MAX_UPINT)
        strLen = SFwcslen(pwStr);
    pDocument->ParseHtml(pwStr, strLen, pimgInfoArr, IsMultiline(), condenseWhite, pstyleMgr, txtFmt, paraFmt);
    OnDocumentChanged(ViewNotify_SignificantTextChange | ViewNotify_ScrollingParamsChange);
}

// @0x14260df50
void DocView::AppendText(const wchar_t* pwStr, UPInt strLen)
{
    const TextFormat*      ptxtfmt;
    const ParagraphFormat* pparafmt;
    UPInt len = pDocument->GetLength();
    if (len > 0 && pDocument->GetTextAndParagraphFormat(&ptxtfmt, &pparafmt, len - 1))
        pDocument->AppendString(pwStr, strLen, GetNewLinePolicy(), ptxtfmt, pparafmt);
    else
        pDocument->AppendString(pwStr, strLen, GetNewLinePolicy());
    OnDocumentChanged(ViewNotify_TextChange | ViewNotify_ScrollingParamsChange);
}

// @0x14260e010
void DocView::AppendText(const char* putf8Str, UPInt utf8Len)
{
    const TextFormat*      ptxtfmt;
    const ParagraphFormat* pparafmt;
    UPInt len = pDocument->GetLength();
    if (len > 0 && pDocument->GetTextAndParagraphFormat(&ptxtfmt, &pparafmt, len - 1))
        pDocument->AppendString(putf8Str, utf8Len, GetNewLinePolicy(), ptxtfmt, pparafmt);
    else
        pDocument->AppendString(putf8Str, utf8Len, GetNewLinePolicy());
    OnDocumentChanged(ViewNotify_TextChange | ViewNotify_ScrollingParamsChange);
}

// @0x14260dec0
void DocView::AppendHtml(const wchar_t* pwStr, UPInt strLen, bool condenseWhite,
                         StyledText::HTMLImageTagInfoArray* pimgInfoArr)
{
    if (strLen == SF_MAX_UPINT)
        strLen = SFwcslen(pwStr);
    pDocument->ParseHtml(pwStr, strLen, pimgInfoArr, IsMultiline(), condenseWhite);
    OnDocumentChanged(ViewNotify_TextChange | ViewNotify_ScrollingParamsChange);
}

// @0x14260de50
void DocView::AppendHtml(const char* putf8Str, UPInt utf8Len, bool condenseWhite,
                         StyledText::HTMLImageTagInfoArray* pimgInfoArr)
{
    if (utf8Len == SF_MAX_UPINT)
        utf8Len = SFstrlen(putf8Str);
    pDocument->ParseHtml(putf8Str, utf8Len, pimgInfoArr, IsMultiline(), condenseWhite);
    OnDocumentChanged(ViewNotify_TextChange | ViewNotify_ScrollingParamsChange);
}

// @0x142614630
UPInt DocView::InsertText(const wchar_t* pstr, UPInt startPos, UPInt strLen)
{
    return pDocument->InsertString(pstr, startPos, strLen);
}

// @0x142614ee0
UPInt DocView::ReplaceText(const wchar_t* pstr, UPInt startPos, UPInt endPos, UPInt strLen)
{
    RemoveText(startPos, endPos);
    return pDocument->InsertString(pstr, startPos, strLen);
}

// @0x14260e370
void DocView::Close()
{
    if (pDocument)
    {
        pDocument = NULL;
        SetDocumentListener(NULL);
        pEditorKit = NULL;
        mLineBuffer.ClearLines();
    }
}

// @0x142614bc0
void DocView::OnDocumentChanged(unsigned notifyMask)
{
    if (notifyMask & ViewNotify_SignificantMask)
        SetCompleteReformatReq();
    else
        SetReformatReq();
}

// @0x142614bd0
void DocView::OnDocumentParagraphRemoving(const Paragraph& para)
{
    // the lines of the paragraph are contiguous; mark them for removal by the next Format
    LineBuffer::Iterator linesIt = mLineBuffer.Begin();
    for (bool found = false; !linesIt.IsFinished(); ++linesIt)
    {
        LineBuffer::Line& curLine = *linesIt;
        if (para.GetId() == curLine.GetParagraphId())
        {
            found = true;
            curLine.SetTextPos(~0u);
        }
        else if (found)
            break;
    }
    SetReformatReq();
}

// @0x142612b50
unsigned DocView::GetHScrollOffset()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    return GetHScrollOffsetValue();
}

// @0x142613550
unsigned DocView::GetVScrollOffset()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    return GetVScrollOffsetValue();
}

// @0x142613510
float DocView::GetTextWidth()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    if (TextWidth > 0)
        return float(TextWidth);
    return 0;
}

// @0x1426134d0
float DocView::GetTextHeight()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    if (TextHeight > 0)
        return float(TextHeight);
    return 0;
}

// @0x142613000
unsigned DocView::GetLinesCount()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    return mLineBuffer.GetSize();
}

// @0x142613060
SF_NOINLINE unsigned DocView::GetMaxHScrollValue() const
{
    if (IsWordWrap())
        return 0;
    int editorDelta = !IsReadOnly() ? GFX_EDIT_HSCROLL_DELTA : 0;
    return unsigned(Alg::Max(0.f, ((TextWidth > 0) ? float(TextWidth) : 0) - GetTextRect().Width() + editorDelta));
}

// @0x142613030
unsigned DocView::GetMaxHScroll()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    return GetMaxHScrollValue();
}

// @0x1426130f0
unsigned DocView::GetMaxVScroll()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
    }
    if (!MaxVScroll.IsValid(FormatCounter))
    {
        if (mLineBuffer.GetSize() == 0)
            MaxVScroll.SetValue(0, FormatCounter);
        else
        {
            unsigned             l       = 0;
            LineBuffer::Iterator linesIt = mLineBuffer.Last();
            const RectF&         textRect = GetTextRect();

            const LineBuffer::Line* pbottomLine = linesIt.GetPtr();
            // a read-only field does not scroll to its last, empty line
            if (IsReadOnly() && pbottomLine->GetTextLength() == 0)
            {
                --linesIt;
                ++l;
            }
            if (!linesIt.IsFinished())
            {
                pbottomLine = linesIt.GetPtr();
                int   lineH = pbottomLine->GetHeight();
                float top   = textRect.y1 + (pbottomLine->GetOffsetY() + lineH - textRect.y2);

                for (; !linesIt.IsFinished(); --linesIt, ++l)
                {
                    const LineBuffer::Line& line = *linesIt;
                    if (l > 0 && line.GetOffsetY() < top)
                        break;
                }
                MaxVScroll.SetValue(mLineBuffer.GetSize() - l, FormatCounter);
            }
            else
                MaxVScroll.SetValue(0, FormatCounter);
        }
    }
    return MaxVScroll;
}

// @0x1426146e0
bool DocView::IsReadOnly() const
{
    return !HasEditorKit() || GetEditorKit()->IsReadOnly();
}

// @0x1426150b0
void DocView::SetAutoSizeX()
{
    if (!IsAutoSizeX())
    {
        Flags |= Flags_AutoSizeX;
        SetCompleteReformatReq();
    }
}

// @0x1426150d0
void DocView::SetAutoSizeY()
{
    if (!IsAutoSizeY())
    {
        Flags |= Flags_AutoSizeY;
        SetCompleteReformatReq();
    }
}

// @0x142615910
void DocView::SetWordWrap()
{
    if (!IsWordWrap())
    {
        Flags |= Flags_WordWrap;
        SetCompleteReformatReq();
    }
}

// @0x14260e350
void DocView::ClearWordWrap()
{
    if (IsWordWrap())
    {
        Flags &= ~Flags_WordWrap;
        SetCompleteReformatReq();
    }
}

// @0x14260f8f0
bool DocView::ForceReformat()
{
    if (IsReformatReq())
    {
        Format();
        ClearReformatReq();
        return true;
    }
    return false;
}

// @0x142613580
const RectF& DocView::GetViewRect()
{
    ForceReformat();
    return ViewRect;
}

// @0x1426152e0
void DocView::SetFontScaleFactor(float f)
{
    if (f == 1)
    {
        RTFlags &= ~RTFlags_HasFontScaleFactor;
        FontScaleFactor = PixelsToFixp(UInt16(1));
    }
    else
    {
        RTFlags |= RTFlags_HasFontScaleFactor;
        FontScaleFactor = (UInt16)PixelsToFixp(f);
    }
}

// @0x142615390
bool DocView::SetHScrollOffset(unsigned hscroll)
{
    bool     rv         = false;
    unsigned maxHScroll = GetMaxHScroll();
    if (hscroll > maxHScroll)
        hscroll = maxHScroll;
    if (mLineBuffer.GetHScrollOffset() != hscroll)
    {
        mLineBuffer.SetHScrollOffset(hscroll);
        if (GetDocumentListener())
            GetDocumentListener()->View_OnHScroll(*this, hscroll);
        rv = true;
    }
    return rv;
}

// @0x142615670
bool DocView::SetVScrollOffset(unsigned vscroll)
{
    bool     rv         = false;
    unsigned maxVScroll = GetMaxVScroll();
    if (vscroll > maxVScroll)
        vscroll = maxVScroll;
    if (mLineBuffer.GetFirstVisibleLineIndex() != vscroll)
    {
        mLineBuffer.SetFirstVisibleLine(vscroll);
        if (GetDocumentListener())
            GetDocumentListener()->View_OnVScroll(*this, vscroll);
        rv = true;
    }
    return rv;
}

// @0x142612bd0
unsigned DocView::GetLineIndexAtPoint(float, float y)
{
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.FindLineAtYOffset(y + mLineBuffer.GetVScrollOffsetInFixp());
    if (!it.IsFinished())
        return it.GetIndex();
    return ~0u;
}

// @0x142612c50
unsigned DocView::GetLineIndexOfChar(UPInt indexOfChar)
{
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.FindLineByTextPos(indexOfChar);
    if (!it.IsFinished())
        return it.GetIndex();
    return ~0u;
}

// @0x142612e80
UPInt DocView::GetLineOffset(unsigned lineIndex)
{
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.Begin() + lineIndex;
    if (!it.IsFinished())
        return it->GetTextPos();
    return SF_MAX_UPINT;
}

// @0x142612cb0
UPInt DocView::GetLineLength(unsigned lineIndex, bool* phasNewLine)
{
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.Begin() + lineIndex;
    if (!it.IsFinished())
    {
        if (phasNewLine)
            *phasNewLine = it->HasNewLine();
        return it->GetTextLength();
    }
    if (phasNewLine)
        *phasNewLine = false;
    return SF_MAX_UPINT;
}

// @0x142612f00
const wchar_t* DocView::GetLineText(unsigned lineIndex, UPInt* plen)
{
    if (!plen)
        return NULL;
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.Begin() + lineIndex;
    if (!it.IsFinished())
    {
        unsigned pos         = it->GetTextPos();
        UPInt    indexInPara = 0;
        StyledText::ParagraphsIterator pit = pDocument->GetParagraphByIndex(pos, &indexInPara);
        if (!pit.IsFinished())
        {
            *plen = it->GetTextLength();
            return pit->GetPtr()->GetText() + indexInPara;
        }
    }
    return NULL;
}

// @0x142613290
SPInt DocView::GetParagraphLength(UPInt charIndex)
{
    ForceReformat();
    UPInt indexInPara = 0;
    StyledText::ParagraphsIterator pit = pDocument->GetParagraphByIndex(charIndex, &indexInPara);
    if (!pit.IsFinished())
        return pit->GetPtr()->GetLength();
    return -1;
}

// @0x142612d50
bool DocView::GetLineMetrics(unsigned lineIndex, LineMetrics* pmetrics)
{
    if (!pmetrics)
        return false;
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.Begin() + lineIndex;
    if (!it.IsFinished())
    {
        LineBuffer::Line& line  = *it;
        pmetrics->Ascent        = (unsigned)line.GetAscent();
        pmetrics->Descent       = (unsigned)line.GetDescent();
        pmetrics->Width         = (unsigned)line.GetWidth();
        pmetrics->Height        = (unsigned)line.GetHeight();
        pmetrics->Leading       = line.GetLeading();
        pmetrics->FirstCharXOff = (int)line.GetOffsetX();
        return true;
    }
    return false;
}

// @0x142612af0
UPInt DocView::GetFirstCharInParagraph(UPInt indexOfChar)
{
    UPInt indexInPara = SF_MAX_UPINT;
    StyledText::ParagraphsIterator pit = pDocument->GetParagraphByIndex(indexOfChar, &indexInPara);
    if (!pit.IsFinished())
        return indexOfChar - indexInPara;
    return SF_MAX_UPINT;
}

// @0x142611f40
// MS2-FUNCTIONAL: the exe calls ForceReformat out of line here (inlined in every other caller); rest identical
unsigned DocView::GetBottomVScroll()
{
    ForceReformat();
    LineBuffer::Iterator it = mLineBuffer.BeginVisible(-float(mLineBuffer.GetVScrollOffsetInFixp()));
    unsigned index = 0;
    for (; it.IsVisible(); ++it)
        index = it.GetIndex();
    return index;
}

// @0x1426150f0
bool DocView::SetBottomVScroll(unsigned newBottomMostLine)
{
    if (newBottomMostLine >= mLineBuffer.GetSize())
        newBottomMostLine = mLineBuffer.GetSize() - 1;
    SPInt l = newBottomMostLine;
    LineBuffer::Iterator linesIt = mLineBuffer.Begin() + newBottomMostLine;
    if (!linesIt.IsFinished())
    {
        const LineBuffer::Line& bottomLine = *linesIt;
        const RectF& textRect    = GetTextRect();
        int          lineH       = bottomLine.GetHeight() + bottomLine.GetNonNegLeading();
        float        top         = textRect.y1 + (bottomLine.GetOffsetY() + lineH - textRect.y2);
        unsigned     topMostLine = newBottomMostLine;
        for (; l >= 0 && !linesIt.IsFinished(); --linesIt)
        {
            const LineBuffer::Line& line = *linesIt;
            if (line.GetOffsetY() < top)
                break;
            topMostLine = (unsigned)l;
            --l;
        }
        return SetVScrollOffset(topMostLine);
    }
    return false;
}

// @0x14260e430
Highlighter* DocView::CreateHighlighterManager()
{
    if (!pHighlight)
        pHighlight = SF_HEAP_AUTO_NEW(this) HighlightDescLoc;
    return &pHighlight->HighlightManager;
}

// @0x14260dc30
bool DocView::AddHighlight(HighlightDesc* pdesc)
{
    if (!pHighlight)
        pHighlight = SF_HEAP_AUTO_NEW(this) HighlightDescLoc;
    return pHighlight->HighlightManager.CreateNewHighlighter(pdesc) != NULL;
}

// @0x1426159e0
void DocView::UpdateHighlight(const HighlightDesc&)
{
    if (!pHighlight)
        return;
    pHighlight->Invalidate();
}

// @0x1426133e0
HighlightDesc* DocView::GetSelectionHighlighterDesc() const
{
    if (!pHighlight)
        return NULL;
    HighlightDesc* pdesc = pHighlight->HighlightManager.GetHighlighterPtr(GFX_TOPMOST_HIGHLIGHTING_INDEX);
    if (!pdesc)
    {
        HighlightDesc desc;
        desc.StartPos = 0;
        desc.Length   = 0;
        desc.Id       = GFX_TOPMOST_HIGHLIGHTING_INDEX;
        desc.Info.SetBackgroundColor(GFX_ACTIVE_SEL_BKCOLOR);
        desc.Info.SetTextColor(GFX_ACTIVE_SEL_TEXTCOLOR);
        pdesc = pHighlight->HighlightManager.CreateHighlighter(desc);
    }
    return pdesc;
}

// @0x142613360
HighlightDesc* DocView::GetSelectionHighlighterDesc()
{
    if (!pHighlight)
        pHighlight = SF_HEAP_AUTO_NEW(this) HighlightDescLoc;
    return const_cast<const DocView*>(this)->GetSelectionHighlighterDesc();
}

// @0x142615440
void DocView::SetSelection(UPInt startPos, UPInt endPos, bool highlightSelection)
{
    BeginSelection = startPos;
    EndSelection   = endPos;
    if (highlightSelection)
    {
        if (!pHighlight)
            pHighlight = SF_HEAP_AUTO_NEW(this) HighlightDescLoc;
        if (endPos < startPos)
        {
            UPInt t  = endPos;
            endPos   = startPos;
            startPos = t;
        }
        HighlightDesc* pdesc  = GetSelectionHighlighterDesc();
        UPInt          newLen = endPos - startPos;
        if (pdesc->StartPos != startPos || pdesc->Length != newLen)
        {
            pdesc->StartPos = startPos;
            pdesc->Length   = newLen;
            pHighlight->Invalidate();
        }
    }
}

// @0x142615520
void DocView::SetSelectionBackgroundColor(UInt32 color)
{
    HighlightDesc* pdesc = GetSelectionHighlighterDesc();
    if (pdesc->Info.GetBackgroundColor() != color)
    {
        pdesc->Info.SetBackgroundColor(color);
        pHighlight->Invalidate();
    }
}

// @0x142615580
void DocView::SetSelectionTextColor(UInt32 color)
{
    HighlightDesc* pdesc = GetSelectionHighlighterDesc();
    if (pdesc->Info.GetTextColor() != color)
    {
        pdesc->Info.SetTextColor(color);
        pHighlight->Invalidate();
    }
}

// @0x142613320
UInt32 DocView::GetSelectionBackgroundColor() const
{
    HighlightDesc* pdesc = GetSelectionHighlighterDesc();
    if (pdesc)
        return pdesc->Info.GetBackgroundColor().ToColor32();
    return GFX_ACTIVE_SEL_BKCOLOR;
}

// @0x142613460
// (this build also answers the background colour here)
UInt32 DocView::GetSelectionTextColor() const
{
    HighlightDesc* pdesc = GetSelectionHighlighterDesc();
    if (pdesc)
        return pdesc->Info.GetBackgroundColor().ToColor32();
    return GFX_ACTIVE_SEL_TEXTCOLOR;
}

// @0x142615230
void DocView::SetDefaultTextAndParaFormat(UPInt cursorPos)
{
    const ParagraphFormat* pparaFmt = NULL;
    const TextFormat*      ptextFmt = NULL;

    UPInt indexInPara = GetFirstCharInParagraph(cursorPos);
    if (indexInPara != SF_MAX_UPINT)
    {
        bool res;
        if (indexInPara != cursorPos)
            res = pDocument->GetTextAndParagraphFormat(&ptextFmt, &pparaFmt, cursorPos - 1);
        else
            res = pDocument->GetTextAndParagraphFormat(&ptextFmt, &pparaFmt, cursorPos);
        if (res)
        {
            pDocument->SetDefaultParagraphFormat(pparaFmt);
            pDocument->SetDefaultTextFormat(ptextFmt);
        }
    }
}

// @0x142612540
UPInt DocView::GetCursorPosInLine(unsigned lineIndex, float x)
{
    if (lineIndex >= mLineBuffer.GetSize())
        return SF_MAX_UPINT;
    ForceReformat();
    return GetCursorPosInLineByOffset(lineIndex, x);
}

// @0x1426125b0
UPInt DocView::GetCursorPosInLineByOffset(unsigned lineIndex, float relativeOffsetX)
{
    if (lineIndex >= mLineBuffer.GetSize())
        return SF_MAX_UPINT;
    LineBuffer::Line& line = mLineBuffer[lineIndex];

    float xoffInLine = relativeOffsetX - line.GetOffsetX() + mLineBuffer.GetHScrollOffset();
    int   xoffset    = 0;

    // the glyph under the offset; past its middle the cursor goes after it
    LineBuffer::GlyphIterator git = line.Begin();
    unsigned i = 0;
    for (; !git.IsFinished(); ++git)
    {
        const LineBuffer::GlyphEntry& ge = git.GetGlyph();
        unsigned advance = ge.GetAdvance();

        if (xoffset + advance > xoffInLine)
        {
            if (xoffInLine - xoffset > advance / 2)
                i += ge.GetLength();
            break;
        }
        xoffset += advance;
        if (!ge.IsNewLineChar())
            i += ge.GetLength();
    }
    return line.GetTextPos() + i;
}

// @0x142612410
UPInt DocView::GetCursorPosAtPoint(float x, float y)
{
    ForceReformat();
    x -= mLineBuffer.Geom.VisibleRect.x1 - ViewRect.x1;
    y -= mLineBuffer.Geom.VisibleRect.y1 - ViewRect.y1;
    LineBuffer::Iterator it = mLineBuffer.FindLineAtYOffset(y + mLineBuffer.GetVScrollOffsetInFixp());
    if (it.IsFinished())
    {
        if (y <= 0)
            it = mLineBuffer.Begin();
        else
            it = mLineBuffer.Begin() + mLineBuffer.GetSize() - 1;
    }
    if (!it.IsFinished())
        return GetCursorPosInLineByOffset(it.GetIndex(), x);
    return (mLineBuffer.GetSize() == 0) ? 0 : SF_MAX_UPINT;
}

// @0x142612240
UPInt DocView::GetCharIndexAtPoint(float x, float y)
{
    ForceReformat();
    x -= mLineBuffer.Geom.VisibleRect.x1 - ViewRect.x1;
    y -= mLineBuffer.Geom.VisibleRect.y1 - ViewRect.y1;
    LineBuffer::Iterator it = mLineBuffer.FindLineAtYOffset(y + mLineBuffer.GetVScrollOffsetInFixp());
    if (!it.IsFinished())
    {
        LineBuffer::Line& line = *it;

        float lineOffX = (float)line.GetOffsetX();
        if (x >= lineOffX && x <= lineOffX + float(line.GetWidth()))
        {
            float xoffInLine = x - lineOffX;
            int   xoffset    = 0;

            LineBuffer::GlyphIterator git = line.Begin();
            unsigned i = 0;
            for (; !git.IsFinished(); ++git)
            {
                const LineBuffer::GlyphEntry& ge = git.GetGlyph();
                xoffset += ge.GetAdvance();
                if (xoffset > xoffInLine)
                    break;
                i += ge.GetLength();
            }
            return line.GetTextPos() + i;
        }
    }
    return SF_MAX_UPINT;
}

}}} // namespace Scaleform::Render::Text
