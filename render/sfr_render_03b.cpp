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
#include "ms2/scaleform/include/render/text_wwhelper.h"

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

// @0x142614c90
void DocView::DocumentText::OnTextInserting(UPInt, UPInt, const wchar_t*)
{
    pDocument->OnDocumentChanged(ViewNotify_TextChange);
}

// @0x142614c80
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

// @0x14260e010
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

// @0x14260df50
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
SF_NOINLINE bool DocView::SetHScrollOffset(unsigned hscroll)
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

// Rect inequality in this build's member order (x1, x2, y1, y2)
static inline bool RectDiffers(const RectF& a, const RectF& b)
{
    return a.x1 != b.x1 || a.x2 != b.x2 || a.y1 != b.y1 || a.y2 != b.y2;
}

// some paragraph is not left aligned (inlined into SetViewRect)
inline bool DocView::ContainsNonLeftAlignment() const
{
    for (unsigned i = 0, n = pDocument->GetParagraphsCount(); i < n; ++i)
    {
        const Paragraph* ppara = pDocument->GetParagraph(i);
        if (ppara->GetFormat()->GetAlignment() != ParagraphFormat::Align_Left)
            return true;
    }
    return false;
}

// @0x1426156d0
void DocView::SetViewRect(const RectF& rect, UseType ut)
{
    if (RectDiffers(rect, ViewRect))
    {
        unsigned oldW = (unsigned)ViewRect.Width();
        unsigned oldH = (unsigned)ViewRect.Height();
        ViewRect = rect;
        RectF textRect = ViewRect;
        textRect.Contract(GFX_TEXT_GUTTER, GFX_TEXT_GUTTER);
        mLineBuffer.SetVisibleRect(textRect);
        if (ut == UseExternally)
        {
            // a width change reformats only when the layout depends on the width (word wrap, a non-left
            // alignment, a shrink with clipping off); a height change only under a bottom / center vertical
            // alignment or a shrink with clipping off; auto size always reformats. Otherwise only the cached
            // scroll limits are refreshed.
            unsigned newW = (unsigned)ViewRect.Width();
            unsigned newH = (unsigned)ViewRect.Height();
            if (GetTextAutoSize() != TAS_None ||
                (oldW != newW && (IsWordWrap() || (newW < oldW && mLineBuffer.Geom.IsNoClipping()) ||
                                  GetAlignment() != Align_Left || ContainsNonLeftAlignment())) ||
                (oldH != newH && ((GetVAlignment() != VAlign_None && GetVAlignment() != VAlign_Top) ||
                                  (newH < oldH && mLineBuffer.Geom.IsNoClipping()))))
            {
                SetCompleteReformatReq();
            }
            else
            {
                ++FormatCounter;
                unsigned maxHScroll = GetMaxHScroll();
                if (GetHScrollOffsetValue() > maxHScroll)
                    SetHScrollOffset(maxHScroll);
                unsigned maxVScroll = GetMaxVScroll();
                if (GetVScrollOffsetValue() > maxVScroll)
                    SetVScrollOffset(maxVScroll);
                mLineBuffer.InvalidateCache();
            }
        }
    }
}

// @0x142614710
bool DocView::IsUrlAtPoint(float x, float y, Range* purlPosRange)
{
    ForceReformat();
    x -= mLineBuffer.Geom.VisibleRect.x1 - ViewRect.x1;
    y -= mLineBuffer.Geom.VisibleRect.y1 - ViewRect.y1;
    LineBuffer::Iterator it = mLineBuffer.FindLineAtYOffset(y + mLineBuffer.GetVScrollOffsetInFixp());
    bool rv = false;
    if (!it.IsFinished())
    {
        LineBuffer::Line& line = *it;

        float lineOffX = (float)line.GetOffsetX();
        if (x >= lineOffX && x <= lineOffX + float(line.GetWidth()))
        {
            float xoffInLine = x - lineOffX + mLineBuffer.GetHScrollOffset();
            int   xoffset    = 0;

            LineBuffer::GlyphIterator git = line.Begin();
            unsigned i = 0;
            for (; !git.IsFinished(); ++git)
            {
                const LineBuffer::GlyphEntry& ge = git.GetGlyph();
                unsigned advance = ge.GetAdvance();
                if (xoffset + advance > xoffInLine)
                {
                    rv = ge.IsUrl();
                    break;
                }
                xoffset += advance;
                i += ge.GetLength();
            }
            if (rv && purlPosRange)
            {
                // widen to the run of formats that carry the same url around the hit character
                purlPosRange->Index  = 0;
                purlPosRange->Length = 0;
                UPInt posInDoc    = i + line.GetTextPos();
                UPInt indexInPara = 0;
                StyledText::ParagraphsIterator paraIter = pDocument->GetParagraphByIndex(posInDoc, &indexInPara);
                if (!paraIter.IsFinished())
                {
                    Paragraph* ppara = *paraIter;
                    TextFormat formatAtThePoint = ppara->GetTextFormat(indexInPara, indexInPara + 1);
                    Paragraph::FormatRunIterator fit = ppara->GetIterator();
                    for (; !fit.IsFinished(); ++fit)
                    {
                        UPInt indexInDoc = (UPInt)fit->Index + ppara->GetStartIndex();
                        if (fit->pFormat->IsUrlSet() && fit->pFormat->GetUrl() == formatAtThePoint.GetUrl())
                        {
                            if ((UPInt)purlPosRange->Index + purlPosRange->Length < indexInDoc)
                            {
                                if (indexInDoc > posInDoc)
                                    break;
                                purlPosRange->Index  = indexInDoc;
                                purlPosRange->Length = fit->Length;
                            }
                            else
                                purlPosRange->Length += fit->Length;
                        }
                        else
                        {
                            if (indexInDoc > posInDoc)
                                break;
                            purlPosRange->Index  = 0;
                            purlPosRange->Length = 0;
                        }
                    }
                }
            }
        }
    }
    return rv;
}

// moves a rectangle by a point (Rect += Point in this build: x1, x2, then y1, y2)
static inline void OffsetRect(RectF* r, const PointF& pt)
{
    r->x1 += pt.x;
    r->x2 += pt.x;
    r->y1 += pt.y;
    r->y2 += pt.y;
}

// @0x142611ff0
bool DocView::GetCharBoundaries(RectF* pCharRect, UPInt indexOfChar)
{
    if (!pCharRect || indexOfChar >= pDocument->GetLength())
        return false;
    ForceReformat();

    LineBuffer::Iterator it = mLineBuffer.FindLineByTextPos(indexOfChar);
    bool rv = false;
    if (!it.IsFinished())
    {
        LineBuffer::Line& line = *it;
        UPInt indexInLine = indexOfChar - line.GetTextPos();
        LineBuffer::GlyphIterator git = line.Begin();
        int advance = 0;
        for (unsigned i = 0; !git.IsFinished(); ++git, ++i)
        {
            const LineBuffer::GlyphEntry& glyph = git.GetGlyph();
            if (i == indexInLine)
            {
                // a newline has no box here (GetExactCharBoundaries gives one)
                if (glyph.IsNewLineChar())
                    break;
                rv = true;

                pCharRect->SetRect(0, 0, 0, 0);
                pCharRect->x2 += float(glyph.GetAdvance());
                pCharRect->y1 = GFX_TEXT_GUTTER;
                pCharRect->y2 = float(line.GetHeight());
                OffsetRect(pCharRect, PointF(float(advance) + GFX_TEXT_GUTTER, float(line.GetOffsetY())));
                break;
            }
            advance += glyph.GetAdvance();
        }
    }
    return rv;
}

// @0x142612740
// The box of the glyph outline (or the embedded image); a newline gets a third of its glyph width.
bool DocView::GetExactCharBoundaries(RectF* pCharRect, UPInt indexOfChar)
{
    UPInt len = pDocument->GetLength();
    if (!pCharRect || indexOfChar > len)
        return false;
    ForceReformat();

    LineBuffer::Iterator it = mLineBuffer.FindLineByTextPos(indexOfChar);
    bool rv = false;
    if (!it.IsFinished())
    {
        LineBuffer::Line& line = *it;
        UPInt indexInLine = indexOfChar - line.GetTextPos();
        LineBuffer::GlyphIterator git = line.Begin();
        int advance = 0;
        for (unsigned i = 0; !git.IsFinished(); ++git, ++i)
        {
            const LineBuffer::GlyphEntry& glyph = git.GetGlyph();
            if (i == indexInLine)
            {
                if (!glyph.HasFmtImage())
                {
                    rv = true;
                    Font* pfont = git.GetFont();
                    float scale = PixelsToFixp(glyph.GetFontSize()) / 1024.0f;   // glyphs are in a 1024 EM square

                    pfont->GetGlyphBounds(glyph.GetIndex(), pCharRect);
                    if (glyph.IsNewLineChar())
                        pCharRect->x2 = pCharRect->x1 + pCharRect->Width() / 3;

                    float textHeight = (pfont->GetAscent() + pfont->GetDescent()) * scale;
                    pCharRect->x1 *= scale;
                    pCharRect->x2 *= scale;
                    pCharRect->y1 = line.GetBaseLineOffset() - pfont->GetAscent() * scale + GFX_TEXT_GUTTER;
                    pCharRect->y2 = pCharRect->y1 + textHeight;
                    OffsetRect(pCharRect, PointF(float(advance) + GFX_TEXT_GUTTER, float(line.GetOffsetY())));
                }
                else
                {
                    rv = true;
                    ImageDesc* pimg = git.GetImage();
                    pCharRect->x1 = -pimg->GetBaseLineX();
                    pCharRect->y1 = -pimg->GetBaseLineY();
                    pCharRect->x2 = pCharRect->x1 + pimg->GetScreenWidth();
                    pCharRect->y2 = pCharRect->y1 + pimg->GetScreenHeight();
                    OffsetRect(pCharRect, PointF(float(advance) + GFX_TEXT_GUTTER, line.GetOffsetY() + GFX_TEXT_GUTTER));
                }
                break;
            }
            advance += glyph.GetAdvance();
        }
    }
    return rv;
}

// (GlyphEntry::SetFontSize(float) is inline in text_linebuffer.h; the exe keeps a copy here)


// ***** Font lookup

#define GFX_BULLET_CHAR_CODE        0x2022
#define GFX_BULLET_CHAR_ADVANCE     15
#define GFX_BULLET_PARA_INDENT      20
#define GFX_LINE_ALLOC_DELTA        100
#define GFX_TEXT_JUSTIFY_CORRECTION 30
#define GFX_MIN_LINE_HEIGHT_FOR_AUTOSIZE PixelsToFixp(6)
#define GFX_NBSP_CHAR_CODE          160

// Resolves the font of pCurrentFormat: same as the previous format, the per-pass cache, the handle stored in
// the format, then the font manager (an empty font if nothing matches; logged once per view).
// @0x14260f270
FontHandle* DocView::FindFont(FindFontInfo* pfontInfo, bool quietMode)
{
    if (!pfontInfo->pCurrentFont || !pfontInfo->pPrevFormat ||
        !pfontInfo->pCurrentFormat->IsFontSame(*pfontInfo->pPrevFormat))
    {
        Ptr<FontHandle>* pcached = (pfontInfo->pFontCache) ? pfontInfo->pFontCache->Get(pfontInfo->pCurrentFormat) : NULL;
        if (pcached)
            pfontInfo->pCurrentFont = *pcached;
        else
        {
            if (pfontInfo->pCurrentFormat->IsFontHandleSet())
                pfontInfo->pCurrentFont = pfontInfo->pCurrentFormat->GetFontHandle();
            else
            {
                FontManagerBase* pfontMgr = GetFontManager();
                if (pfontInfo->pCurrentFormat->IsFontListSet())
                {
                    pfontInfo->pCurrentFont = *pfontMgr->CreateFontHandle(
                        pfontInfo->pCurrentFormat->GetFontList().ToCStr(), pfontInfo->pCurrentFormat->IsBold(),
                        pfontInfo->pCurrentFormat->IsItalic(), DoesUseDeviceFont(),
                        !pfontInfo->pCurrentFormat->IsSingleFontNameSet());
                }
                if (!pfontInfo->pCurrentFont)
                {
                    if (!quietMode && !(RTFlags & RTFlags_FontErrorDetected) && pLog)
                    {
                        // ask again with a search log for the message
                        FontManagerBase::FontSearchPathInfo searchInfo(1);
                        Ptr<FontHandle> h = *pfontMgr->CreateFontHandle(
                            pfontInfo->pCurrentFormat->GetFontList().ToCStr(), pfontInfo->pCurrentFormat->IsBold(),
                            pfontInfo->pCurrentFormat->IsItalic(), DoesUseDeviceFont(),
                            !pfontInfo->pCurrentFormat->IsSingleFontNameSet(), &searchInfo);
                        String charPath = GetDocumentListener() ? GetDocumentListener()->GetCharacterPath() : String();
                        pLog->LogError("Missing font \"%s\" in \"%s\". Search log:\n%s",
                                       pfontInfo->pCurrentFormat->GetFontList().ToCStr(), charPath.ToCStr(),
                                       searchInfo.Info.ToCStr());
                        RTFlags |= RTFlags_FontErrorDetected;
                    }
                    pfontInfo->pCurrentFont = *pfontMgr->GetEmptyFont();
                }
            }
            if (pfontInfo->pFontCache)
                pfontInfo->pFontCache->Set(pfontInfo->pCurrentFormat, pfontInfo->pCurrentFont);
        }
    }
    pfontInfo->pPrevFormat = pfontInfo->pCurrentFormat;
    return pfontInfo->pCurrentFont;
}

// ***** Line formatting

// Where the formatter stands in a paragraph: the character iterator (with the IME composition string spliced
// in), the glyphs written so far for the current line and the metrics gathered for it. Copies of the cursor
// are kept as restart points for word wrapping.
class GFxLineCursor
{
public:
    LineBuffer::GlyphEntry*     pPrevGrec;          // +0x00 last glyph written (kerning, final advance)
    Ptr<FontHandle>             pLastFont;          // +0x08
    unsigned                    LastCharCode;       // +0x10
    unsigned                    LastGlyphIndex;     // +0x14
    float                       LastAdvance;        // +0x18
    int                         LastGlyphWidth;     // +0x1c
    UInt32                      LastColor;          // +0x20
    Ptr<CompositionStringBase>  pComposStr;         // +0x28
    UPInt                       ComposStrPosition;  // +0x30
    UPInt                       ComposStrLength;    // +0x38
    UPInt                       ComposStrCurPos;    // +0x40
    DocView*                    pDocView;           // +0x48
    const Paragraph*            pParagraph;         // +0x50
    int                         LineWidth;          // +0x58
    int                         LineWidthWithoutTrailingSpaces;
    unsigned                    LineLength;         // +0x60 characters on the line
    float                       MaxFontAscent;      // +0x64
    float                       MaxFontDescent;     // +0x68
    float                       MaxFontLeading;     // +0x6c
    Paragraph::CharactersIterator CharIter;         // +0x70
    Paragraph::CharacterInfo    CharInfoHolder;     // +0xb0
    int                         Indent;             // +0xc8
    int                         LeftMargin;         // +0xcc
    int                         RightMargin;        // +0xd0
    LineBuffer::GlyphInserter   GlyphIns;           // +0xd8
    unsigned                    NumOfSpaces;        // +0xf8
    unsigned                    NumOfTrailingSpaces;// +0xfc
    float                       FontScaleFactor;    // +0x100
    bool                        LastKerning;        // +0x104
    bool                        LineHasNewLine;     // +0x105
    UPInt                       NumChars;           // +0x108 characters consumed

    // @0x14260cde0
    GFxLineCursor()
        : pPrevGrec(NULL), pLastFont(NULL), LastCharCode(0), LastGlyphIndex(0), LastAdvance(0), LastGlyphWidth(0),
          LastColor(0), ComposStrPosition(SF_MAX_UPINT), ComposStrLength(0), ComposStrCurPos(0), pDocView(NULL),
          pParagraph(NULL), LineWidth(0), LineWidthWithoutTrailingSpaces(0), LineLength(0), MaxFontAscent(0),
          MaxFontDescent(0), MaxFontLeading(0), Indent(0), LeftMargin(0), RightMargin(0), NumOfSpaces(0),
          NumOfTrailingSpaces(0), FontScaleFactor(1.f), LastKerning(false), LineHasNewLine(false), NumChars(0)
    {
    }
    GFxLineCursor(DocView* pview, const Paragraph* ppara)
        : pPrevGrec(NULL), pLastFont(NULL), LastCharCode(0), LastGlyphIndex(0), LastAdvance(0), LastGlyphWidth(0),
          LastColor(0), ComposStrPosition(SF_MAX_UPINT), ComposStrLength(0), ComposStrCurPos(0), pDocView(pview),
          pParagraph(ppara), LineWidth(0), LineWidthWithoutTrailingSpaces(0), LineLength(0), MaxFontAscent(0),
          MaxFontDescent(0), MaxFontLeading(0), CharIter(ppara->GetCharactersIterator(0)), Indent(0), LeftMargin(0),
          RightMargin(0), NumOfSpaces(0), NumOfTrailingSpaces(0), FontScaleFactor(1.f), LastKerning(false),
          LineHasNewLine(false), NumChars(0)
    {
    }

    bool IsFinished() const { return CharIter.IsFinished(); }

    // steps n characters; the composition string counts as text at its position
    void operator+=(unsigned n)
    {
        if (pComposStr && pComposStr->GetLength() > 0)
        {
            UPInt step   = n;
            UPInt curPos = CharIter.GetCurTextIndex() + pParagraph->GetStartIndex();
            if (curPos <= pComposStr->GetPosition() && curPos + n >= pComposStr->GetPosition())
            {
                step = Alg::PMin(pComposStr->GetPosition() - curPos, (UPInt)n);
                if (ComposStrCurPos + (n - step) > pComposStr->GetLength())
                {
                    step += ComposStrCurPos + (n - step) - pComposStr->GetLength();
                    ComposStrCurPos = pComposStr->GetLength();
                    NumChars += ComposStrCurPos;
                }
                else
                {
                    ComposStrCurPos += n - step;
                    NumChars += n - step;
                }
                n = (unsigned)step;
            }
        }
        if (n > 0)
        {
            CharIter += n;
            NumChars += n;
        }
    }
    bool IsInsideComposStr() const
    {
        if (pComposStr && pComposStr->GetLength() > 0)
        {
            UPInt curPos = const_cast<Paragraph::CharactersIterator&>(CharIter)->Index + pParagraph->GetStartIndex();
            if (curPos >= pComposStr->GetPosition() && ComposStrCurPos < pComposStr->GetLength())
                return true;
        }
        return false;
    }

    // the current character: composition string characters carry the run format merged with their own
    // @0x14260d8f0
    const Paragraph::CharacterInfo& operator*()
    {
        CharInfoHolder.Index = CharIter->Index;
        if (pComposStr && pComposStr->GetLength() > 0)
        {
            UPInt curPos = CharInfoHolder.Index + pParagraph->GetStartIndex();
            if (curPos >= pComposStr->GetPosition())
            {
                if (curPos == pComposStr->GetPosition() && ComposStrCurPos < pComposStr->GetLength())
                {
                    CharInfoHolder.Index     = CharIter->Index + ComposStrCurPos;
                    CharInfoHolder.Character = pComposStr->GetText()[ComposStrCurPos];
                    CharInfoHolder.pFormat   = *pComposStr->GetAllocator()->AllocateTextFormat(
                        CharIter->pFormat->Merge(*pComposStr->GetTextFormat(ComposStrCurPos)));
                    return CharInfoHolder;
                }
                CharInfoHolder.Index = CharIter->Index + pComposStr->GetLength();
            }
        }
        CharInfoHolder.pFormat = CharIter->pFormat;
        if (pDocView->IsPasswordMode() && CharIter->Character != '\0')
            CharInfoHolder.Character = '*';
        else
            CharInfoHolder.Character = CharIter->Character;
        return CharInfoHolder;
    }

    float GetPrevGlyphAdvanceAdj(wchar_t c) const
    {
        if (pPrevGrec)
            return pLastFont->GetFont()->GetKerningAdjustment(LastCharCode, c);
        return 0;
    }
    // per-line state back to the start of a line
    void Reset()
    {
        pPrevGrec     = NULL;
        MaxFontAscent = MaxFontDescent = MaxFontLeading = 0;
        LastAdvance   = 0;
        LastKerning   = LineHasNewLine = false;
        LineWidthWithoutTrailingSpaces = 0;
        LineLength    = 0;
        NumOfSpaces   = NumOfTrailingSpaces = 0;
        NumChars      = 0;
        LastCharCode  = 0;
    }

    // the line is as tall as its tallest font; fonts without metrics count as 960 / 64 of the 1024 EM
    // @0x142615970
    void TrackFontParams(Font* pfont, float scale)
    {
        float ascent  = pfont->GetAscent();
        float descent = pfont->GetDescent();
        if (ascent == 0)
            ascent = 960.f;
        if (descent == 0)
            descent = 1024.f - 960.f;
        MaxFontAscent  = Alg::Max(MaxFontAscent, ascent * scale);
        MaxFontDescent = Alg::Max(MaxFontDescent, descent * scale);
        MaxFontLeading = Alg::Max(MaxFontLeading, pfont->GetLeading() * scale);
    }
};


// Lays out one paragraph at a time into lines of the view's LineBuffer. A line is built in a temporary line
// (on the stack buffer when it fits) and copied into a right-sized Line8 / Line32 when it is finished. A
// custom word-wrap handler of the document listener may move the wrap point; the line is then formatted a
// second time (Pass 2) up to the requested position.
class ParagraphFormatter
{
    DocView*                pDocView;               // +0x00
    const Paragraph*        pParagraph;             // +0x08
    const ParagraphFormat*  pParaFormat;            // +0x10
    LineBuffer::Line*       pTempLine;              // +0x18
    GFxLineCursor           LineCursor;             // +0x20
    DocView::FontCache      FontCache;              // +0x130
    DocView::FindFontInfo   FindFontInfo;           // +0x140
    GFxLineCursor           StartPoint;             // +0x160 restart points for the custom word wrap
    GFxLineCursor           HalfPoint;              // +0x270
    GFxLineCursor           WordWrapPoint;          // +0x380 last break opportunity
    float                   TextRectWidth;          // +0x490
    unsigned                TabStopsNum;            // +0x494
    unsigned                TabStopsIndex;          // +0x498
    unsigned                DeltaText;              // +0x49c characters to step after this one
    int                     Pass;                   // +0x4a0
    bool                    HyphenationRequested;   // +0x4a4
    unsigned                RequestedWordWrapPos;   // +0x4a8 Pass 2 only
    bool                    HasLineFormatHandler;   // +0x4ac

    wchar_t                 TextBufForCustomFormat[256];    // +0x4ae
    wchar_t*                pTextBufForCustomFormat;        // +0x6b0
    UPInt                   TextBufLen;                     // +0x6b8

    // state of the character being placed
    Font*                   pFont;                  // +0x6c0
    Ptr<FontHandle>         pFontHandle;            // +0x6c8
    float                   Scale;                  // +0x6d0
    int                     GlyphIndex;
    float                   GlyphAdvance;
    int                     LastAdvance;
    int                     GlyphWidth;
    int                     AdjLineWidth;
    int                     NewLineWidth;
    float                   FontSize;
    bool                    isSpace;
    bool                    isNbsp;

public:
    LineBuffer::Iterator*   pLinesIter;             // +0x6f8 where the lines go
    UByte                   TempLineBuff[1024];     // +0x700
    LineBuffer::Line*       pDynLine;               // +0xb00 temporary line too big for TempLineBuff
    int                     NextOffsetY;            // +0xb08

    int                     ParaYOffset;            // +0xb0c
    Log*                    pLog;                   // +0xb10

    int                     ParaWidth;              // +0xb18
    int                     ParaHeight;             // +0xb1c
    unsigned                ParaLines;              // +0xb20
    bool                    NeedRecenterLines;      // +0xb24
    bool                    ForceVerticalCenterAutoSize;

    void  FinalizeLine();
    void  InitParagraph(const Paragraph& paragraph);
    void  InitCustomWordWrapping();
    float GetActualFontSize();
    bool  CheckWordWrap();
    bool  HandleCustomWordWrap();

    ParagraphFormatter(DocView* pdoc, Log* plog);
    ~ParagraphFormatter();
    void Format(const Paragraph& paragraph);
};

// @0x14260cec0
ParagraphFormatter::ParagraphFormatter(DocView* pdoc, Log* plog)
    : pDocView(pdoc), pParagraph(NULL), pParaFormat(NULL), pTempLine(NULL), FontCache(pdoc->GetHeap()),
      FindFontInfo(&FontCache), pDynLine(NULL)
{
    ParaYOffset                 = 0;
    NextOffsetY                 = 0;
    NeedRecenterLines           = false;
    ForceVerticalCenterAutoSize = false;
    pLog                        = plog;
}

// @0x14260d230
ParagraphFormatter::~ParagraphFormatter()
{
    if (pDynLine)
        pDocView->mLineBuffer.LineAllocator.FreeLine(pDynLine);
}

// @0x1426140b0
void ParagraphFormatter::InitParagraph(const Paragraph& paragraph)
{
    pParagraph  = &paragraph;
    pParaFormat = pParagraph->GetFormat();
    LineCursor  = GFxLineCursor(pDocView, &paragraph);
    StartPoint = HalfPoint = WordWrapPoint = GFxLineCursor();
    LineCursor.FontScaleFactor = pDocView->GetFontScaleFactor();

    if (pDocView->HasEditorKit() && pDocView->GetEditorKit()->HasCompositionString())
    {
        LineCursor.pComposStr        = pDocView->GetEditorKit()->GetCompositionString();
        LineCursor.ComposStrPosition = LineCursor.pComposStr->GetPosition();
        LineCursor.ComposStrLength   = LineCursor.pComposStr->GetLength();
    }

    InitCustomWordWrapping();

    // at most one glyph per character (plus the bullet) and two format entries per glyph
    UPInt maxGlyphCount = paragraph.GetSize() + LineCursor.ComposStrLength;
    if (pParaFormat->IsBullet())
        ++maxGlyphCount;
    unsigned linesz = LineBuffer::CalcLineSize((unsigned)maxGlyphCount, (unsigned)maxGlyphCount * 2, LineBuffer::Line32);
    if (linesz < sizeof(TempLineBuff))
    {
        pTempLine = ::new (TempLineBuff) LineBuffer::Line();
        pTempLine->SetMemSize(linesz);
    }
    else if (pDynLine)
    {
        if (linesz >= pDynLine->GetMemSize())
        {
            pDocView->mLineBuffer.LineAllocator.FreeLine(pDynLine);
            pDynLine = pDocView->mLineBuffer.LineAllocator.AllocLine(linesz + GFX_LINE_ALLOC_DELTA, LineBuffer::Line32);
        }
        pTempLine = pDynLine;
    }
    else
        pTempLine = pDynLine =
            pDocView->mLineBuffer.LineAllocator.AllocLine(linesz + GFX_LINE_ALLOC_DELTA, LineBuffer::Line32);
    pTempLine->InitLine32();
    pTempLine->ClearInitialized();   // the temporary line never releases its formats
    pTempLine->SetNumGlyphs((unsigned)maxGlyphCount);
    pTempLine->SetTextPos(unsigned(pDocView->TextPos2GlyphOffset(paragraph.GetStartIndex())));

    LineCursor.GlyphIns =
        LineBuffer::GlyphInserter(pTempLine->GetGlyphs(), pTempLine->GetNumGlyphs(), pTempLine->GetFormatData());

    ParaHeight = ParaWidth = 0;
    ParaLines  = 0;

    DeltaText            = 1;
    Pass                 = 1;
    HyphenationRequested = false;
    RequestedWordWrapPos = 0;
    isSpace              = false;
    TextRectWidth        = pDocView->GetTextRect().Width();
    TabStopsNum = 0, TabStopsIndex = 0;
}

// the custom word-wrap handler sees the paragraph text with the composition string spliced in
// @0x142613f20
void ParagraphFormatter::InitCustomWordWrapping()
{
    HasLineFormatHandler    = (pDocView->pDocumentListener && pDocView->pDocumentListener->DoesHandleLineFormat());
    pTextBufForCustomFormat = NULL;
    if (HasLineFormatHandler)
    {
        UPInt bufLen = pParagraph->GetLength();
        bool  composInPara = (LineCursor.ComposStrPosition >= pParagraph->GetStartIndex() &&
                              LineCursor.ComposStrPosition <= pParagraph->GetStartIndex() + pParagraph->GetLength());
        if (composInPara)
            bufLen = pParagraph->GetLength() + LineCursor.ComposStrLength;
        wchar_t* pbuf;
        if (bufLen < sizeof(TextBufForCustomFormat) / sizeof(TextBufForCustomFormat[0]))
            pbuf = TextBufForCustomFormat;
        else
            pbuf = pDocView->GetAllocator()->AllocText(bufLen + 1);

        const wchar_t* ptext = pParagraph->GetText();
        if (composInPara && LineCursor.ComposStrLength > 0)
        {
            UPInt composOff = LineCursor.ComposStrPosition - pParagraph->GetStartIndex();
            memcpy(pbuf, ptext, composOff * sizeof(wchar_t));
            ptext += composOff;
            memcpy(pbuf + composOff, LineCursor.pComposStr->GetText(), LineCursor.ComposStrLength * sizeof(wchar_t));
            memcpy(pbuf + composOff + LineCursor.ComposStrLength, ptext,
                   (pParagraph->GetLength() - composOff) * sizeof(wchar_t));
        }
        else
            memcpy(pbuf, ptext, bufLen * sizeof(wchar_t));
        pbuf[bufLen]            = 0;
        pTextBufForCustomFormat = pbuf;
        TextBufLen              = bufLen;
    }
}

// @0x142611ee0
float ParagraphFormatter::GetActualFontSize()
{
    float fontSize = FindFontInfo.pCurrentFormat->GetFontSize();
    if (FindFontInfo.pCurrentFont->GetFontScaleFactor() != 1.0f)
        fontSize *= FindFontInfo.pCurrentFont->GetFontScaleFactor();
    if (pDocView->HasFontScaleFactor())
        fontSize *= pDocView->GetFontScaleFactor();
    return fontSize;
}

// Copies the temporary line into a real one (Line8 when everything fits its narrow fields), justifies it,
// places it and starts the next one.
// @0x14260ebb0
void ParagraphFormatter::FinalizeLine()
{
    int lastAdvance = Alg::IRound(LineCursor.LastAdvance);
    if (LineCursor.pPrevGrec)
        LineCursor.pPrevGrec->SetAdvance(lastAdvance);

    // the last glyph counts with its real width rather than its advance
    if (LineCursor.pLastFont)
        LineCursor.LineWidth += LineCursor.LastGlyphWidth;
    else
        LineCursor.LineWidth += lastAdvance;

    if (pParaFormat->GetAlignment() == ParagraphFormat::Align_Right || pParaFormat->GetAlignment() == ParagraphFormat::Align_Center)
    {
        LineCursor.LineWidth += LineCursor.RightMargin;
        LineCursor.LineWidthWithoutTrailingSpaces += LineCursor.RightMargin;
    }

    float fleading = (pParaFormat->IsLeadingSet()) ? PixelsToFixp<float>(float(pParaFormat->GetLeading()))
                                                   : LineCursor.MaxFontLeading;
    int lineHeight = Alg::IRound(LineCursor.MaxFontAscent + LineCursor.MaxFontDescent);
    int leading    = Alg::IRound(fleading);

    LineCursor.LineWidth = Alg::Max(0, LineCursor.LineWidth);
    LineCursor.LineWidthWithoutTrailingSpaces = Alg::Max(0, LineCursor.LineWidthWithoutTrailingSpaces);

    LineBuffer::Line* pline;
    unsigned glyphsCount = LineCursor.GlyphIns.GetGlyphIndex();
    unsigned fmtCount    = LineCursor.GlyphIns.GetFormatDataElementsCount();
    if (pDocView->GetTextAutoSize() == DocView::TAS_None && LineCursor.LineLength <= 255 && glyphsCount <= 255 &&
        (leading >= -128 && leading <= 127) && (lineHeight >= 0 && lineHeight < 65536) &&
        (LineCursor.LineWidth >= 0 && LineCursor.LineWidth < 65536))
        pline = pLinesIter->InsertNewLine(glyphsCount, fmtCount, LineBuffer::Line8);
    else
        pline = pLinesIter->InsertNewLine(glyphsCount, fmtCount, LineBuffer::Line32);
    pline->SetParagraphId(LineCursor.pParagraph->GetId());
    pline->SetParagraphModId(LineCursor.pParagraph->GetModCounter());

    memcpy(pline->GetGlyphs(), pTempLine->GetGlyphs(), glyphsCount * sizeof(LineBuffer::GlyphEntry));
    memcpy(pline->GetFormatData(), pTempLine->GetFormatData(), fmtCount * sizeof(LineBuffer::FormatDataEntry));

    pline->SetTextPos(pTempLine->GetTextPos());
    pline->SetTextLength(LineCursor.LineLength);
    pline->SetBaseLineOffset(LineCursor.MaxFontAscent);

    // justify: spread the free width over the inner spaces (not the last line of a paragraph)
    if (!LineCursor.LineHasNewLine && pDocView->IsWordWrap() &&
        LineCursor.NumOfSpaces - LineCursor.NumOfTrailingSpaces > 0 && pParaFormat->GetAlignment() == ParagraphFormat::Align_Justify)
    {
        int deltaW = (int(TextRectWidth - GFX_TEXT_JUSTIFY_CORRECTION) - LineCursor.RightMargin) -
                     (LineCursor.LineWidthWithoutTrailingSpaces + LineCursor.Indent + LineCursor.LeftMargin);
        if (deltaW > 0)
        {
            int perSpace = deltaW / (LineCursor.NumOfSpaces - LineCursor.NumOfTrailingSpaces);
            for (LineBuffer::GlyphIterator git = pline->Begin(); !git.IsFinished(); ++git)
            {
                LineBuffer::GlyphEntry& ge = git.GetGlyph();
                if (ge.IsSpaceChar())
                    ge.SetAdvance(ge.GetAdvance() + perSpace);
            }
            LineCursor.LineWidth += deltaW;
        }
    }

    int lineOffsetX = LineCursor.Indent + LineCursor.LeftMargin;
    pline->SetOffset(lineOffsetX, NextOffsetY);
    pline->SetLeading(leading);

    switch (pParaFormat->GetAlignment())
    {
    case ParagraphFormat::Align_Right:
        pline->SetAlignment(LineBuffer::Line::Align_Right);
        pline->SetDimensions(LineCursor.LineWidthWithoutTrailingSpaces, lineHeight);
        pline->SetOffsetX(Alg::Max(0, Alg::IRound(TextRectWidth) - LineCursor.LineWidthWithoutTrailingSpaces));
        if (pDocView->IsAutoSizeX() || pDocView->GetTextAutoSize() != DocView::TAS_None)
            NeedRecenterLines = true;
        break;
    case ParagraphFormat::Align_Center:
        {
            pline->SetAlignment(LineBuffer::Line::Align_Center);
            pline->SetDimensions(LineCursor.LineWidthWithoutTrailingSpaces, lineHeight);
            // the right margin is already in the width
            float adjWidth = TextRectWidth - float(LineCursor.LeftMargin);
            pline->SetOffsetX(Alg::Max(0, Alg::IRound(adjWidth / 2 - LineCursor.LineWidthWithoutTrailingSpaces / 2) +
                                              LineCursor.LeftMargin));
            if (pDocView->IsAutoSizeX() || pDocView->GetTextAutoSize() != DocView::TAS_None)
                NeedRecenterLines = true;
            break;
        }
    default:
        pline->SetAlignment(LineBuffer::Line::Align_Left);
        pline->SetDimensions(LineCursor.LineWidth, lineHeight);
        break;
    }

    ParaWidth   = Alg::Max(ParaWidth, lineOffsetX + LineCursor.LineWidth);
    ParaHeight  = NextOffsetY + lineHeight - ParaYOffset;
    NextOffsetY += Alg::IRound(lineHeight + leading);
    LineCursor.Indent = 0;
    LineCursor.GlyphIns.Reset();
    LineCursor.LastColor = 0;
    LineCursor.pLastFont = NULL;
}


// Offers the line to the listener's word-wrap handler (first pass only). When it moves the wrap point the
// cursor is rewound to the nearest saved point before it and the line is formatted again (true). A requested
// hyphen is appended here.
// @0x1426135e0
bool ParagraphFormatter::HandleCustomWordWrap()
{
    if (!LineCursor.pLastFont)
        return false;

    if (Pass == 1 && HasLineFormatHandler)
    {
        float lineWidthBeforeWW;
        Font* pfont;
        UPInt wrapPos;
        if (WordWrapPoint.IsFinished())
        {
            lineWidthBeforeWW = (float)LineCursor.LineWidth;
            pfont             = LineCursor.pLastFont->GetFont();
            wrapPos           = LineCursor.NumChars;
        }
        else
        {
            lineWidthBeforeWW = (float)WordWrapPoint.LineWidth;
            pfont             = WordWrapPoint.pLastFont->GetFont();
            wrapPos           = WordWrapPoint.NumChars;
        }
        DocView::LineFormatDesc desc;
        desc.pParaText      = pTextBufForCustomFormat;
        desc.ParaTextLen    = TextBufLen;
        desc.LineStartPos   = pTempLine->GetTextPos() - pParagraph->GetStartIndex();
        desc.NumCharsInLine = LineCursor.NumChars;
        switch (pParaFormat->GetAlignment())
        {
        case ParagraphFormat::Align_Left:    desc.Alignment = DocView::LineFormatDesc::Align_Left; break;
        case ParagraphFormat::Align_Right:   desc.Alignment = DocView::LineFormatDesc::Align_Right; break;
        case ParagraphFormat::Align_Center:  desc.Alignment = DocView::LineFormatDesc::Align_Center; break;
        case ParagraphFormat::Align_Justify: desc.Alignment = DocView::LineFormatDesc::Align_Justify; break;
        default:;
        }
        desc.VisibleRectWidth        = (float)TextRectWidth;
        desc.CurrentLineWidth        = (float)LineCursor.LineWidth;
        desc.LineWidthBeforeWordWrap = lineWidthBeforeWW;
        int dashIndex = pfont->GetGlyphIndex('-');
        if (dashIndex > 0)
            desc.DashSymbolWidth = pfont->GetGlyphWidth(dashIndex);
        desc.ProposedWordWrapPoint = wrapPos;

        float  widthsBuf[256];
        float* pwidths = widthsBuf;
        if (desc.NumCharsInLine + 1 > sizeof(widthsBuf) / sizeof(widthsBuf[0]))
            pwidths = (float*)SF_HEAP_ALLOC(pDocView->GetAllocator()->GetHeap(),
                                            sizeof(float) * (desc.NumCharsInLine + 1), StatRender_Text_Mem);
        unsigned i = 0;
        unsigned numGlyphs;
        LineBuffer::GlyphEntry* pglyphs = LineCursor.GlyphIns.GetReadyGlyphs(&numGlyphs);
        // glyphs without characters (the bullet) at the start do not count
        float skipped = 0;
        for (; i < numGlyphs; ++i)
        {
            if (pglyphs[i].GetLength() == 0)
                skipped += pglyphs[i].GetAdvance();
            else
                break;
        }
        desc.pWidths                  = pwidths;
        desc.VisibleRectWidth        -= skipped;
        desc.CurrentLineWidth        -= skipped;
        desc.LineWidthBeforeWordWrap -= skipped;
        // the width before every character; characters of an image all sit at its start
        float curW = 0;
        UPInt p;
        for (p = 0; i < numGlyphs; ++i)
        {
            pwidths[p] = curW;
            curW += (float)pglyphs[i].GetAdvance();
            unsigned len = pglyphs[i].GetLength();
            if (len > 1)
            {
                for (unsigned j = 0; j < len; ++j)
                {
                    pTextBufForCustomFormat[p + j] = GFX_NBSP_CHAR_CODE;
                    pwidths[p + j] = 0;
                }
            }
            p += len;
        }
        pwidths[p] = curW;
        desc.UseHyphenation = false;
        bool handled = pDocView->pDocumentListener->View_OnLineFormat(*pDocView, desc);
        if (handled)
        {
            HyphenationRequested = desc.UseHyphenation;
            if (desc.ProposedWordWrapPoint == 0)
                desc.ProposedWordWrapPoint = 1;   // keep at least one character on the line
            if (desc.ProposedWordWrapPoint != wrapPos)
            {
                if (!WordWrapPoint.IsFinished() && desc.ProposedWordWrapPoint > WordWrapPoint.NumChars)
                {
                    LineCursor.GlyphIns.ResetTo(WordWrapPoint.GlyphIns);
                    LineCursor = WordWrapPoint;
                }
                else if (!HalfPoint.IsFinished() && desc.ProposedWordWrapPoint > HalfPoint.NumChars)
                {
                    LineCursor.GlyphIns.ResetTo(HalfPoint.GlyphIns);
                    LineCursor = HalfPoint;
                }
                else
                {
                    LineCursor.GlyphIns.ResetTo(StartPoint.GlyphIns);
                    LineCursor = StartPoint;
                }
                Pass                 = 2;
                RequestedWordWrapPos = (unsigned)desc.ProposedWordWrapPoint;
                DeltaText            = 0;
            }
        }
        if (pwidths != widthsBuf)
        {
            // the allocator is still looked up (it may be created here), the block goes to the global free
            pDocView->GetAllocator();
            SF_FREE(pwidths);
        }
        StartPoint = HalfPoint = GFxLineCursor();
        if (handled && Pass == 2)
            return true;
    }
    else if (Pass == 2)
    {
        WordWrapPoint = GFxLineCursor();
        Pass          = 1;
    }

    if (HyphenationRequested)
    {
        LineBuffer::GlyphEntry& grec = LineCursor.GlyphIns.GetGlyph();
        int lastAdvance = Alg::IRound(LineCursor.LastAdvance);
        if (LineCursor.pPrevGrec)
            LineCursor.pPrevGrec->SetAdvance(lastAdvance);
        int dashIndex = LineCursor.pLastFont->GetFont()->GetGlyphIndex('-');
        grec.SetIndex(dashIndex);
        grec.SetLength(0);
        grec.SetFontSize(FontSize);
        LineCursor.LineWidth = NewLineWidth;
        float dashAdvance = LineCursor.pLastFont->GetFont()->GetAdvance(dashIndex) * Scale;
        RectF dashBounds;
        int   dashWidth =
            Alg::IRound(Alg::Max(pFont->GetGlyphBounds(dashIndex, &dashBounds).x2 * Scale + 20, dashAdvance));
        LineCursor.LastGlyphWidth = (int)(LineCursor.pLastFont->GetFont()->GetGlyphWidth(dashIndex) * Scale);
        LineCursor.LastAdvance    = (float)dashWidth;
        LineCursor.LastGlyphWidth = dashWidth;
        LineCursor.LastGlyphIndex = dashIndex;
        LineCursor.NumOfTrailingSpaces            = 0;
        LineCursor.LineWidthWithoutTrailingSpaces = NewLineWidth + dashWidth;
        HyphenationRequested = false;
        LineCursor.pPrevGrec = &grec;
        ++LineCursor.GlyphIns;
    }
    return false;
}

// Breaks the line when the next glyph would cross the right edge (or, in the second pass, at the requested
// position): back to the last break opportunity if there is one, finalize, start the next line. True when
// the cursor was moved back and the loop must not step.
// @0x14260e120
bool ParagraphFormatter::CheckWordWrap()
{
    if ((Pass == 1 && (pDocView->IsWordWrap() && !isSpace &&
                       NewLineWidth + AdjLineWidth + LineCursor.Indent + LineCursor.LeftMargin >
                           TextRectWidth - LineCursor.RightMargin)) ||
        (Pass == 2 && LineCursor.NumChars == RequestedWordWrapPos))
    {
        if (HandleCustomWordWrap())
            return true;

        NewLineWidth = 0;
        bool wrapped = false;
        if (!WordWrapPoint.IsFinished())
        {
            LineBuffer::GlyphInserter ins = WordWrapPoint.GlyphIns;
            LineCursor.GlyphIns.ResetTo(ins);
            LineCursor = WordWrapPoint;
            isSpace    = false;
            wrapped    = true;
            DeltaText  = 0;
        }
        WordWrapPoint = GFxLineCursor();
        UPInt newTextPos = pParagraph->GetStartIndex() + (*LineCursor).Index;

        if (LineCursor.pPrevGrec)
            LineCursor.pPrevGrec->SetWordWrapSeparator();

        FinalizeLine();

        LineCursor.Reset();
        TabStopsIndex = 0;   // tab stops apply again on every line
        pTempLine->SetTextPos((unsigned)newTextPos);
        if (wrapped)
        {
            LineCursor.LineWidth = 0;
            return true;
        }
    }
    return false;
}

// @0x142610b20
// MS2-FUNCTIONAL: the exe calls an identical FindCharWithFlags copy from another TU (0x14267fce0) and keeps a /GS cookie; logic matches
void ParagraphFormatter::Format(const Paragraph& paragraph)
{
    InitParagraph(paragraph);

    LineCursor.LeftMargin = 0;
    if (pParaFormat->IsBullet())
    {
        LineBuffer::GlyphEntry& grec = LineCursor.GlyphIns.GetGlyph();
        const Paragraph::CharacterInfo& chInfo = *LineCursor;
        FindFontInfo.pCurrentFormat = chInfo.pFormat;
        if (FindFontInfo.pCurrentFormat)   // an empty paragraph may have no format
        {
            Ptr<FontHandle> pfontHandle = pDocView->FindFont(&FindFontInfo, false);
            int glyphIndex = pfontHandle->GetFont()->GetGlyphIndex(GFX_BULLET_CHAR_CODE);
            grec.SetIndex(glyphIndex);
            grec.SetAdvance(PixelsToFixp<int>(GFX_BULLET_CHAR_ADVANCE));
            float fontSize = GetActualFontSize() * 2 / 3;
            grec.SetFontSize(fontSize);
            grec.SetLength(0);

            UInt32 color = FindFontInfo.pCurrentFormat->GetColor32();
            LineCursor.GlyphIns.AddFont(pfontHandle);
            LineCursor.GlyphIns.AddColor(color);
            ++LineCursor.GlyphIns;

            LineCursor.pLastFont = pfontHandle;
            LineCursor.LastColor = color;
        }
        LineCursor.LeftMargin = PixelsToFixp<int>(GFX_BULLET_PARA_INDENT) + PixelsToFixp<int>(GFX_BULLET_CHAR_ADVANCE);
        LineCursor.LineWidth  = LineCursor.LeftMargin;
        LineCursor.Indent     = -PixelsToFixp<int>(GFX_BULLET_CHAR_ADVANCE);
    }
    else
        LineCursor.Indent = PixelsToFixp<int>(pParaFormat->GetIndent());
    LineCursor.LeftMargin += PixelsToFixp<int>(pParaFormat->GetLeftMargin() + pParaFormat->GetBlockIndent());
    LineCursor.RightMargin = PixelsToFixp<int>(pParaFormat->GetRightMargin());
    const unsigned* const ptabStops = pParaFormat->GetTabStops(&TabStopsNum);

    Ptr<ImageDesc> pimgDesc;
    for (; !LineCursor.IsFinished(); LineCursor += DeltaText)
    {
        const Paragraph::CharacterInfo& chInfo = *LineCursor;

        if (Pass == 1 && pDocView->IsWordWrap() && !pimgDesc)
        {
            wchar_t lastChar = (wchar_t)LineCursor.LastCharCode;
            if (WordWrapHelper::IsLineBreakOpportunityAt(WordWrapHelper::WWT_All, lastChar, chInfo.Character))
                WordWrapPoint = LineCursor;
        }

        // restart points for the custom word wrap: the line start and the first character past half width
        if (Pass == 1 && HasLineFormatHandler)
        {
            float w = TextRectWidth;
            if (LineCursor.LineWidth == 0 && !StartPoint.pDocView)
                StartPoint = LineCursor;
            if (LineCursor.LineWidth > w / 2)
            {
                if (!HalfPoint.pDocView)
                    HalfPoint = LineCursor;
            }
        }

        DeltaText = 1;
        pimgDesc  = NULL;
        if (pDocView->pImageSubstitutor)
        {
            UPInt remlen;
            const wchar_t* prest = LineCursor.CharIter.GetRemainingTextPtr(&remlen);
            UPInt textLen;
            pimgDesc = pDocView->pImageSubstitutor->FindImageDesc(prest, remlen, &textLen);
            if (pimgDesc)
                DeltaText = (unsigned)textLen;
        }
        if (!pimgDesc)
        {
            if (chInfo.pFormat && chInfo.pFormat->IsImageDescSet() && chInfo.Character != 0)
                pimgDesc = chInfo.pFormat->GetImageDesc();
        }

        pFont    = NULL;
        Scale    = 1.f;
        FontSize = -1;
        if (!pimgDesc)
        {
            isNbsp  = (chInfo.Character == GFX_NBSP_CHAR_CODE);
            isSpace = (chInfo.Character == 0 || (!isNbsp && WordWrapHelper::IsWhiteSpaceChar(chInfo.Character)));

            if (FindFontInfo.pCurrentFont && FindFontInfo.pCurrentFormat == chInfo.pFormat)
                pFontHandle = FindFontInfo.pCurrentFont;
            else
            {
                FindFontInfo.pCurrentFormat = chInfo.pFormat;
                bool quietMode = (chInfo.Character == 0);   // no "font not found" for the terminating null
                pFontHandle = pDocView->FindFont(&FindFontInfo, quietMode);
                if (!pFontHandle)
                    continue;
            }
            pFont    = pFontHandle->GetFont();
            FontSize = GetActualFontSize();
            Scale    = PixelsToFixp(FontSize) / 1024.0f;   // glyphs are in a 1024 EM square
            if (chInfo.Character == pDocView->NewLineChar() || chInfo.Character == '\0')
            {
                // end of the paragraph: an invisible glyph half a space wide
                GlyphIndex   = pFont->GetGlyphIndex(' ');
                GlyphAdvance = pFont->GetAdvance(GlyphIndex) / 2 * Scale;
            }
            else if (chInfo.Character != '\t')
            {
                GlyphIndex = pFont->GetGlyphIndex((UInt16)chInfo.Character);
                if (GlyphIndex == -1)
                {
                    if (isNbsp)
                        GlyphIndex = pFont->GetGlyphIndex(' ');
                    if (GlyphIndex == -1)
                    {
                        if (pLog && !(pDocView->RTFlags & DocView::RTFlags_FontErrorDetected))
                        {
                            FontManagerBase::FontSearchPathInfo searchInfo(1);
                            Ptr<FontHandle> h = *pDocView->GetFontManager()->CreateFontHandle(
                                FindFontInfo.pCurrentFormat->GetFontList().ToCStr(),
                                FindFontInfo.pCurrentFormat->IsBold(), FindFontInfo.pCurrentFormat->IsItalic(),
                                pDocView->DoesUseDeviceFont(), !FindFontInfo.pCurrentFormat->IsSingleFontNameSet(),
                                &searchInfo);
                            String charPath = pDocView->GetDocumentListener()
                                                  ? pDocView->GetDocumentListener()->GetCharacterPath()
                                                  : String();
                            String   charRanges  = pFont->GetCharRanges();
                            unsigned glyphsCount = pFont->GetGlyphShapeCount();
                            pLog->LogError("Missing \"%s\" glyph '%c' (0x%x) in \"%s\".\n"
                                           "Font has %u glyphs, ranges %s.\nSearch log: \n%s",
                                           FindFontInfo.pCurrentFormat->GetFontList().ToCStr(), (char)chInfo.Character,
                                           chInfo.Character, charPath.ToCStr(), glyphsCount, charRanges.ToCStr(),
                                           searchInfo.Info.ToCStr());
                            pDocView->RTFlags |= DocView::RTFlags_FontErrorDetected;
                        }
                        // index -1 draws the empty box
                    }
                }
                GlyphAdvance = pFont->GetAdvance(GlyphIndex) * Scale;
            }
            else
            {
                // a tab gets no glyph; its advance is computed below
                GlyphIndex   = -1;
                GlyphAdvance = 0;
            }

            // kerning against the previous glyph adjusts that glyph's advance
            if (LineCursor.pPrevGrec)
            {
                float kernAdj = 0;
                if (LineCursor.LastKerning)
                    kernAdj = LineCursor.GetPrevGlyphAdvanceAdj(chInfo.Character) * Scale;
                LastAdvance = Alg::IRound(LineCursor.LastAdvance + kernAdj);
            }
            else
                LastAdvance = Alg::IRound(LineCursor.LastAdvance);
            GlyphWidth = Alg::IRound(GlyphAdvance);
            // a space never pushes the line over the edge
            AdjLineWidth = (isSpace) ? 0 : GlyphWidth;
        }
        else
        {
            FindFontInfo.pCurrentFormat = chInfo.pFormat;
            GlyphWidth   = Alg::IRound(pimgDesc->GetScreenWidth());
            GlyphAdvance = GlyphWidth + 40.f;
            LastAdvance  = Alg::IRound(LineCursor.LastAdvance);
            AdjLineWidth = GlyphWidth;
            GlyphIndex   = ~0u;
            isSpace      = false;
            isNbsp       = false;
        }

        NewLineWidth = LineCursor.LineWidth + LastAdvance;

        if (CheckWordWrap())
            continue;

        if (LineCursor.pPrevGrec)
            LineCursor.pPrevGrec->SetAdvance(LastAdvance);

        LineBuffer::GlyphEntry& grec = LineCursor.GlyphIns.GetGlyph();
        grec.SetIndex(GlyphIndex);
        if (LineCursor.IsInsideComposStr())
            grec.SetComposStrGlyph();
        // the advance is set on the next character or in FinalizeLine (kerning)

        if (pimgDesc)
        {
            LineCursor.GlyphIns.AddImage(pimgDesc);
            grec.SetLength(DeltaText);
            LineCursor.LastKerning = false;

            Render::PointF p(0, 0);
            pimgDesc->Matrix.Transform(&p.x, &p.y);
            LineCursor.MaxFontAscent  = Alg::Max(LineCursor.MaxFontAscent, -p.y);
            LineCursor.MaxFontDescent = Alg::Max(LineCursor.MaxFontDescent, pimgDesc->GetScreenHeight() - -p.y);

            LineCursor.NumOfTrailingSpaces            = 0;
            LineCursor.LineWidthWithoutTrailingSpaces = NewLineWidth + AdjLineWidth;

            if (FindFontInfo.pCurrentFormat->IsUrlSet())
                grec.SetUrl();
            else
                grec.ClearUrl();
        }
        else
        {
            UInt32 color = FindFontInfo.pCurrentFormat->GetColor32();
            grec.SetFontSize(FontSize);

            if (pFontHandle != LineCursor.pLastFont)
                LineCursor.GlyphIns.AddFont(pFontHandle);
            if (color != LineCursor.LastColor)
                LineCursor.GlyphIns.AddColor(color);

            if (chInfo.Character == pDocView->NewLineChar() || chInfo.Character == '\0')
            {
                // the paragraph end: no width, but highlighting still covers it
                if (chInfo.Character == '\0')
                    grec.SetLength(0);
                else
                    grec.SetLength(1);
                grec.SetInvisibleChar();
                grec.SetNewLineChar();
                GlyphWidth = 0;
                LineCursor.LineHasNewLine = true;

                // an empty line still gets the height of its font
                if (chInfo.Index == 0)
                    LineCursor.TrackFontParams(pFont, Scale);
            }
            else
            {
                if (isSpace || isNbsp)
                {
                    grec.SetSpaceChar();
                    if (GlyphIndex < 0)
                        grec.SetInvisibleChar();
                    else
                    {
                        RectF bnd(0, 0, 0, 0);
                        pFont->GetGlyphBounds(GlyphIndex, &bnd);
                        if (bnd.IsEmpty())
                            grec.SetInvisibleChar();
                    }
                    ++LineCursor.NumOfSpaces;   // a non-breaking space justifies like a space
                    if (isSpace)
                        ++LineCursor.NumOfTrailingSpaces;
                    else
                    {
                        LineCursor.NumOfTrailingSpaces            = 0;
                        LineCursor.LineWidthWithoutTrailingSpaces = NewLineWidth + AdjLineWidth;
                    }
                }
                else
                {
                    LineCursor.NumOfTrailingSpaces            = 0;
                    LineCursor.LineWidthWithoutTrailingSpaces = NewLineWidth + AdjLineWidth;
                }
                grec.SetLength(1);
                LineCursor.TrackFontParams(pFont, Scale);
            }
            if (FindFontInfo.pCurrentFormat->IsUnderline())
                grec.SetUnderline();
            else
                grec.ClearUnderline();
            if (FindFontInfo.pCurrentFormat->IsUrlSet())
                grec.SetUrl();
            else
                grec.ClearUrl();

            LineCursor.pLastFont   = pFontHandle;
            LineCursor.LastColor   = color;
            LineCursor.LastKerning = FindFontInfo.pCurrentFormat->IsKerning();
        }

        if (chInfo.Character == '\t')
        {
            if (TabStopsIndex < TabStopsNum)
            {
                int nextTabStop = PixelsToFixp<int>(ptabStops[TabStopsIndex]);
                ++TabStopsIndex;
                if (nextTabStop > NewLineWidth)
                    GlyphAdvance = float(nextTabStop - NewLineWidth);
            }
            else
            {
                // default stops, close to what Flash does (it measures from the stage, we from the text)
                float tabStopSize = PixelsToFixp(floorf((FontSize * 2 + 8) / 8) * 8);
                float nextTabStop = floorf((NewLineWidth + tabStopSize) / tabStopSize) * tabStopSize;
                GlyphAdvance = nextTabStop - NewLineWidth;
            }
        }

        LineCursor.LineLength += grec.GetLength();
        LineCursor.pPrevGrec    = &grec;
        LineCursor.LastCharCode = chInfo.Character;
        LineCursor.LineWidth    = NewLineWidth;

        LineCursor.LastGlyphIndex = GlyphIndex;
        LineCursor.LastAdvance    = GlyphAdvance;
        if (FindFontInfo.pCurrentFormat->IsLetterSpacingSet())
            LineCursor.LastAdvance += PixelsToFixp(FindFontInfo.pCurrentFormat->GetLetterSpacing());
        LineCursor.LastGlyphWidth = GlyphWidth;

        ++LineCursor.GlyphIns;
    }

    if (pTempLine)
        FinalizeLine();
    if (pTextBufForCustomFormat && pTextBufForCustomFormat != TextBufForCustomFormat)
        pDocView->GetAllocator()->FreeText(pTextBufForCustomFormat);
}


// Reformats the changed paragraphs: lines of unchanged paragraphs only move, lines of removed or modified
// ones are dropped and re-laid out. Then auto size, text auto size (shrink / fit), scroll clamping, vertical
// alignment and recentering of the lines, and the listener notifications.
// @0x14260f920
// MS2-FUNCTIONAL: the exe inlines SetHScrollOffset (out of line here for its other callers) -> different register allocation
void DocView::Format()
{
    RectF textRect = ViewRect;
    textRect.Contract(GFX_TEXT_GUTTER, GFX_TEXT_GUTTER);
    mLineBuffer.SetVisibleRect(textRect);

    StyledText* pstyledText = GetStyledText();
    if (!pstyledText)
        return;

    unsigned oldMaxHScroll = GetMaxHScrollValue();
    unsigned oldMaxVScroll = GetMaxVScrollValue();

    // text auto size scales everything, so everything is laid out again
    if (GetTextAutoSize() != TAS_None)
        SetCompleteReformatReq();

    StyledText::ParagraphsIterator paraIter = pstyledText->GetParagraphIterator();
    LineBuffer::Iterator           linesIt  = mLineBuffer.Begin();

    ParagraphFormatter formatter(this, pLog);
    int textWidth = 0, textHeight = 0;

    while (!paraIter.IsFinished())
    {
        const Paragraph* ppara = *paraIter;
        if (!linesIt.IsFinished())
        {
            LineBuffer::Line& curLine = *linesIt;
            if (!IsCompleteReformatReq() && ppara->GetId() == curLine.GetParagraphId() &&
                ppara->GetModCounter() == curLine.GetParagraphModId())
            {
                // unchanged: move its lines to the new text position and y offset
                UPInt pos = TextPos2GlyphOffset(ppara->GetStartIndex());
                for (; !linesIt.IsFinished(); ++linesIt)
                {
                    LineBuffer::Line& line = *linesIt;
                    if (ppara->GetId() != line.GetParagraphId())
                        break;
                    line.SetTextPos((unsigned)pos);
                    int oldX = (int)line.GetOffsetX();
                    int oldY = (int)line.GetOffsetY();

                    pos += line.GetTextLength();
                    line.SetOffsetY(formatter.NextOffsetY);

                    textWidth = Alg::Max(textWidth, line.GetWidth());
                    // the trailing empty line only counts in editable text (as in Flash)
                    if (ppara->GetLength() != 0 || (HasEditorKit() && !GetEditorKit()->IsReadOnly()))
                        textHeight = int(formatter.NextOffsetY + line.GetHeight());

                    formatter.NextOffsetY += line.GetHeight() + line.GetLeading();

                    if (IsAutoSizeX())
                    {
                        switch (line.GetAlignment())
                        {
                        case LineBuffer::Line::Align_Right:
                            line.SetOffsetX(Alg::Max(0, Alg::IRound(GetTextRect().Width()) - line.GetWidth()));
                            formatter.NeedRecenterLines = true;   // the view width may still change
                            break;
                        case LineBuffer::Line::Align_Center:
                            line.SetOffsetX(Alg::Max(0, Alg::IRound(GetTextRect().Width() / 2) - line.GetWidth() / 2));
                            formatter.NeedRecenterLines = true;
                            break;
                        default: break;
                        }
                    }
                    if (oldX != (int)line.GetOffsetX() || oldY != (int)line.GetOffsetY())
                        mLineBuffer.InvalidateCache();
                }
                ++paraIter;
                continue;
            }
            else
            {
                if (curLine.GetTextPos() == ~0u)
                {
                    // the paragraph is gone: drop its lines and look at the same paragraph again
                    unsigned n      = 0;
                    UInt32   paraId = curLine.GetParagraphId();
                    for (LineBuffer::Iterator it = linesIt; !it.IsFinished(); ++n, ++it)
                    {
                        if ((*it).GetParagraphId() != paraId)
                            break;
                    }
                    if (n > 0)
                    {
                        linesIt.Remove(n);
                        mLineBuffer.InvalidateCache();
                    }
                    continue;
                }
                else if (ppara->GetId() == curLine.GetParagraphId() &&
                         ppara->GetModCounter() != curLine.GetParagraphModId())
                {
                    // modified: drop its lines and lay it out again
                    unsigned n = 0;
                    for (LineBuffer::Iterator it = linesIt; !it.IsFinished(); ++n, ++it)
                    {
                        if ((*it).GetParagraphId() != ppara->GetId())
                            break;
                    }
                    linesIt.Remove(n);
                    mLineBuffer.InvalidateCache();
                }
            }
        }

        formatter.pLinesIter  = &linesIt;
        formatter.ParaYOffset = formatter.NextOffsetY;
        formatter.Format(*ppara);
        mLineBuffer.InvalidateCache();

        textWidth = Alg::Max(textWidth, formatter.ParaWidth);
        if (ppara->GetLength() != 0 || (HasEditorKit() && !GetEditorKit()->IsReadOnly()))
            textHeight = int(formatter.ParaYOffset + formatter.ParaHeight);

        ++paraIter;
    }
    // lines past the last paragraph
    if (!linesIt.IsFinished())
    {
        linesIt.Remove(mLineBuffer.GetSize() - linesIt.GetIndex());
        mLineBuffer.InvalidateCache();
    }

    TextWidth  = (UInt32)textWidth;
    TextHeight = (UInt32)textHeight;
    ++FormatCounter;
    ClearReformatReq();

    // auto size: the view follows the text
    bool           valignApplied = false;
    ViewVAlignment valign        = GetVAlignment();
    if (IsAutoSizeX() || IsAutoSizeY() || formatter.ForceVerticalCenterAutoSize)
    {
        RectF newViewRect = ViewRect;
        if (IsAutoSizeX())
        {
            float newW = TextWidth + GFX_TEXT_GUTTER * 2;
            switch (GetAlignment())
            {
            case Align_Center:
                newViewRect.x1 += newViewRect.Width() / 2 - newW / 2;
                break;
            case Align_Right:
                newViewRect.x1 = newViewRect.x2 - newW;
                break;
            default: break;
            }
            newViewRect.x2 = newViewRect.x1 + newW;
        }
        if (IsAutoSizeY() || formatter.ForceVerticalCenterAutoSize)
        {
            float newH = TextHeight + GFX_TEXT_GUTTER * 2;
            if ((valign == VAlign_None && formatter.ForceVerticalCenterAutoSize) || valign == VAlign_Center)
                newViewRect.y1 += newViewRect.Height() / 2 - newH / 2;
            else if (valign == VAlign_Bottom)
                newViewRect.y1 = newViewRect.y2 - newH;
            newViewRect.y2 = newViewRect.y1 + newH;
            valignApplied  = true;
        }
        if (RectDiffers(newViewRect, ViewRect))
            SetViewRect(newViewRect, UseInternally);
    }

    // text auto size: scale the laid out lines into the view
    ViewTextAutoSize tas;
    if ((tas = GetTextAutoSize()) != TAS_None)
    {
        RectF maxTextRect = ViewRect;
        maxTextRect.Contract(GFX_TEXT_GUTTER, GFX_TEXT_GUTTER);

        // a single line field is centered vertically unless told otherwise
        if (!IsMultiline() && valign == VAlign_None)
            valign = VAlign_Center;
        float scale  = 1.f;
        float hscale = 1.f, vscale = 1.f;
        if (tas == TAS_Shrink)
        {
            if (textWidth > maxTextRect.Width())
                hscale = maxTextRect.Width() / textWidth;
            if (textHeight > maxTextRect.Height())
                vscale = maxTextRect.Height() / textHeight;
            scale = Alg::Min(vscale, hscale);
        }
        else if (tas == TAS_Fit)
        {
            hscale = vscale = SF_MAX_FLOAT;
            if (textWidth >= 20)
                hscale = maxTextRect.Width() / textWidth;
            if (textHeight >= 20)
                vscale = maxTextRect.Height() / textHeight;
            scale = Alg::Min(vscale, hscale);
            if (scale == SF_MAX_FLOAT)
                scale = 1.0f;   // no text to fit
        }
        if (scale != 1.f)
        {
            // never below the minimal readable line height
            int minLineH = mLineBuffer.GetMinLineHeight();
            if (minLineH > 0)
            {
                float fmlh = float(minLineH);
                if (fmlh * scale < GFX_MIN_LINE_HEIGHT_FOR_AUTOSIZE)
                    scale = GFX_MIN_LINE_HEIGHT_FOR_AUTOSIZE / fmlh;
            }
            TextWidth  = (UInt32)(textWidth * scale);
            TextHeight = (UInt32)(textHeight * scale);
            mLineBuffer.Scale(scale);
        }
    }

    // clamp the vertical scroll before the vertical alignment looks at it
    bool     needOnScroller = false;
    unsigned maxVScroll     = GetMaxVScroll();
    if (GetVScrollOffsetValue() > maxVScroll)
        SetVScrollOffset(maxVScroll);
    else if (maxVScroll != oldMaxVScroll)
        needOnScroller = true;

    // vertical alignment inside an unchanged view
    if (!valignApplied && valign != VAlign_None && !IsAutoSizeY())
    {
        RectF maxTextRect = ViewRect;
        maxTextRect.Contract(GFX_TEXT_GUTTER, GFX_TEXT_GUTTER);

        RectF newTextRect = GetTextRect();
        float textH = float(TextHeight);
        if (textH < maxTextRect.Height())
        {
            switch (valign)
            {
            case VAlign_Top:
                newTextRect = maxTextRect;
                break;
            case VAlign_Center:
                newTextRect.y1 = maxTextRect.y1 + (maxTextRect.Height() / 2 - textH / 2);
                break;
            case VAlign_Bottom:
                newTextRect.y1 = maxTextRect.y2 - textH;
                break;
            default: break;
            }
            mLineBuffer.SetVisibleRect(newTextRect);
        }
        else
        {
            newTextRect = maxTextRect;
            if (valign == VAlign_Center || valign == VAlign_Bottom)
            {
                // align what is visible at the bottom of the scroll range
                float visTextHeight = 0;
                LineBuffer::Iterator it = mLineBuffer.Begin() + GetBottomVScroll();
                for (int i = 0; !it.IsFinished(); --it, ++i)
                {
                    LineBuffer::Line& line = *it;
                    int lh = line.GetHeight();
                    if (i != 0)   // no leading below the last line
                        lh += line.GetLeading();
                    if (visTextHeight + float(lh) <= maxTextRect.Height())
                        visTextHeight += lh;
                    else
                        break;
                }
                if (valign == VAlign_Bottom)
                    newTextRect.y1 = maxTextRect.y2 - visTextHeight;
                else
                    newTextRect.y1 = maxTextRect.y1 + (maxTextRect.Height() / 2 - visTextHeight / 2);
            }
            mLineBuffer.SetVisibleRect(newTextRect);
        }
    }
    // right / centered lines follow a view width changed by auto size or text auto size
    if (formatter.NeedRecenterLines)
    {
        for (LineBuffer::Iterator it = mLineBuffer.Begin(); !it.IsFinished(); ++it)
        {
            LineBuffer::Line& line = *it;
            switch (line.GetAlignment())
            {
            case LineBuffer::Line::Align_Right:
                line.SetOffsetX(Alg::Max(0, Alg::IRound(GetTextRect().Width()) - line.GetWidth()));
                break;
            case LineBuffer::Line::Align_Center:
                line.SetOffsetX(Alg::Max(0, Alg::IRound(GetTextRect().Width() / 2) - line.GetWidth() / 2));
                break;
            default: break;
            }
        }
    }

    unsigned maxHScroll = GetMaxHScroll();
    if (GetHScrollOffsetValue() > maxHScroll)
        SetHScrollOffset(maxHScroll);
    else if (maxHScroll != oldMaxHScroll)
        needOnScroller = true;
    if (pDocumentListener)
    {
        if (needOnScroller && pDocumentListener->DoesHandleOnMaxScrollChanged())
            pDocumentListener->View_OnMaxScrollChanged(*this);
        if (pDocumentListener->DoesHandleOnViewChanged())
            pDocumentListener->View_OnChanged(*this);
    }

    // text that fits needs no clipping (keeps the overhang of right aligned italics)
    if (IsReadOnly() && TextWidth <= ViewRect.Width() && TextHeight <= ViewRect.Height() &&
        GetHScrollOffsetValue() == 0)
        mLineBuffer.Geom.SetNoClipping();
    else
        mLineBuffer.Geom.ClearNoClipping();

    if (pHighlight)
        pHighlight->HighlightManager.UpdateGlyphIndices(HasEditorKit() ? GetEditorKit()->GetCompositionString() : NULL);

    // a pixel aligned font on the first glyph means a bitmap font
    ClearBitmapFontFlag();
    if (mLineBuffer.Lines.GetSize() > 0 && mLineBuffer.Lines[0]->GetNumGlyphs() > 0)
    {
        if (mLineBuffer.Lines[0]->GetGlyphs()->HasFmtFont())
        {
            LineBuffer::FormatDataEntry* pfmtData = mLineBuffer.Lines[0]->GetFormatData();
            if (pfmtData->pFont->GetFont()->IsPixelAligned())
                SetBitmapFontFlag();
        }
    }
}



// Feeds the visible lines to the text layout builder: the glyph parameters come from the filters and the view
// flags, then the background / border and the editor's cursor; the bounds are the (reformatted) view rect.
// @0x14260e4c0
void DocView::CreateVisibleTextLayout(TextLayout::Builder& bld)
{
    if (pHighlight && !pHighlight->IsValid())
    {
        pHighlight->HighlightManager.UpdateGlyphIndices(HasEditorKit() ? GetEditorKit()->GetCompositionString() : NULL);
        pHighlight->Validate();
    }

    TextFieldParam param;
    LoadTextFieldParamFromTextFilter(param, Filter);
    if (IsAAForReadability())
    {
        param.TextParam.SetOptRead(true);
        param.ShadowParam.SetOptRead(true);
    }
    if (IsAutoFit())
    {
        param.TextParam.SetAutoFit(true);
        param.ShadowParam.SetAutoFit(true);
    }
    param.TextParam.SetBitmapFont(IsBitmapFontFlagSet());
    param.TextParam.SetFauxBold(GetFauxBold());
    param.TextParam.SetFauxItalic(GetFauxItalic());
    param.TextParam.SetOutline((unsigned)GetOutline());

    mLineBuffer.CreateVisibleTextLayout(bld, pHighlight ? &pHighlight->HighlightManager : NULL, param);

    // a visible border or background is drawn under the text
    if (Color(BorderColor).GetAlpha() != 0 || Color(BackgroundColor).GetAlpha() != 0)
        bld.SetBackground(BackgroundColor, BorderColor);

    if (pEditorKit)
        pEditorKit->AddDrawCursorInfo(bld);
    bld.SetBounds(GetViewRect());
}


// Applies one editing command to the document, keeping within MaxLength; returns the number of characters
// inserted (or removed, for the delete commands).
// @0x14260e6b0
UPInt DocView::EditCommand(DocView::CommandType cmdId, const void* command)
{
    UPInt res = 0;
    switch (cmdId)
    {
    case Cmd_InsertChar:
    {
        const InsertCharCommand& cmd = *static_cast<const InsertCharCommand*>(command);
        if (!HasMaxLength() || GetLength() + 1 <= GetMaxLength())
            res = pDocument->InsertString(&cmd.CharCode, cmd.PosAt, 1);
        break;
    }
    case Cmd_InsertPlainText:
    {
        const InsertPlainTextCommand& cmd = *static_cast<const InsertPlainTextCommand*>(command);
        UPInt len    = cmd.Length;
        UPInt curLen = GetLength();
        if (HasMaxLength() && curLen + len > GetMaxLength())
            len = GetMaxLength() - curLen;   // cut to what still fits
        res = pDocument->InsertString(cmd.pStr, cmd.PosAt, len, StyledText::NLP_CompressCRLF);
        break;
    }
    case Cmd_InsertStyledText:
    {
        const InsertStyledTextCommand& cmd = *static_cast<const InsertStyledTextCommand*>(command);
        UPInt len = SF_MAX_UPINT;
        if (HasMaxLength())
        {
            UPInt dstLen = GetLength();
            UPInt srcLen = cmd.pText->GetLength();
            if (dstLen + srcLen > GetMaxLength())
                len = GetMaxLength() - dstLen;
        }
        res = pDocument->InsertStyledText(*cmd.pText, cmd.PosAt, len);
        break;
    }
    case Cmd_ReplaceTextByChar:
    {
        const ReplaceTextByCharCommand& cmd = *static_cast<const ReplaceTextByCharCommand*>(command);
        UPInt stPos, endPos;
        if (cmd.BeginPos > cmd.EndPos)
        {
            stPos  = cmd.EndPos;
            endPos = cmd.BeginPos;
        }
        else
        {
            stPos  = cmd.BeginPos;
            endPos = cmd.EndPos;
        }
        UPInt len = 1;
        if (HasMaxLength())
        {
            // the length once the replaced range is gone
            UPInt dstLen = GetLength();
            UPInt ep = Alg::Clamp(endPos, UPInt(0), dstLen), sp = Alg::Clamp(stPos, UPInt(0), dstLen);
            dstLen -= (ep - sp);
            if (dstLen + 1 > GetMaxLength())
                len = 0;
        }
        if (len > 0)
        {
            res = pDocument->InsertString(&cmd.CharCode, stPos, 1, StyledText::NLP_CompressCRLF);
            RemoveText(stPos + 1, endPos + 1);
        }
        break;
    }
    case Cmd_ReplaceTextByPlainText:
    {
        const ReplaceTextByPlainTextCommand& cmd = *static_cast<const ReplaceTextByPlainTextCommand*>(command);
        UPInt stPos, endPos;
        if (cmd.BeginPos > cmd.EndPos)
        {
            stPos  = cmd.EndPos;
            endPos = cmd.BeginPos;
        }
        else
        {
            stPos  = cmd.BeginPos;
            endPos = cmd.EndPos;
        }
        UPInt len = cmd.Length;
        if (HasMaxLength())
        {
            UPInt dstLen = GetLength();
            UPInt ep = Alg::Clamp(endPos, UPInt(0), dstLen), sp = Alg::Clamp(stPos, UPInt(0), dstLen);
            dstLen -= (ep - sp);
            if (dstLen + cmd.Length > GetMaxLength())
                len = GetMaxLength() - dstLen;
        }
        res = pDocument->InsertString(cmd.pStr, stPos, len, StyledText::NLP_CompressCRLF);
        RemoveText(stPos + res, endPos + res);
        break;
    }
    case Cmd_ReplaceTextByStyledText:
    {
        const ReplaceTextByStyledTextCommand& cmd = *static_cast<const ReplaceTextByStyledTextCommand*>(command);
        UPInt stPos, endPos;
        if (cmd.BeginPos > cmd.EndPos)
        {
            stPos  = cmd.EndPos;
            endPos = cmd.BeginPos;
        }
        else
        {
            stPos  = cmd.BeginPos;
            endPos = cmd.EndPos;
        }
        UPInt len = SF_MAX_UPINT;
        if (HasMaxLength())
        {
            UPInt dstLen = GetLength();
            UPInt ep = Alg::Clamp(endPos, UPInt(0), dstLen), sp = Alg::Clamp(stPos, UPInt(0), dstLen);
            dstLen -= (ep - sp);
            if (dstLen + cmd.pText->GetLength() > GetMaxLength())
                len = GetMaxLength() - dstLen;
        }
        res = pDocument->InsertStyledText(*cmd.pText, stPos, len);
        RemoveText(stPos + res, endPos + res);
        break;
    }
    case Cmd_BackspaceChar:
    {
        const DeleteCharCommand& cmd = *static_cast<const DeleteCharCommand*>(command);
        res = 1;
        // at the start of a bulleted or indented paragraph, backspace first takes away the bullet / indent
        UPInt                          indexInPara = 0;
        StyledText::ParagraphsIterator paraIter    = pDocument->GetParagraphByIndex(cmd.PosAt, &indexInPara);
        if (!paraIter.IsFinished() && indexInPara == 0)
        {
            Paragraph*             ppara    = *paraIter;
            const ParagraphFormat* pparaFmt = ppara->GetFormat();
            if (pparaFmt)
            {
                if (pparaFmt->IsBullet())
                {
                    ParagraphFormat newFmt = *pparaFmt;
                    newFmt.SetBullet(false);
                    ppara->SetFormat(pDocument->GetAllocator(), newFmt);
                    OnDocumentChanged(ViewNotify_TextChange);
                    res = 0;
                }
                else if (pparaFmt->GetIndent() != 0 || pparaFmt->GetBlockIndent() != 0)
                {
                    ParagraphFormat newFmt = *pparaFmt;
                    newFmt.SetIndent(0);
                    newFmt.SetBlockIndent(0);
                    ppara->SetFormat(pDocument->GetAllocator(), newFmt);
                    OnDocumentChanged(ViewNotify_TextChange);
                    res = 0;
                }
            }
        }
        if (res == 1 && cmd.PosAt > 0)
            RemoveText(cmd.PosAt - 1, cmd.PosAt);
        else
            res = 0;
        break;
    }
    case Cmd_DeleteChar:
    {
        const DeleteCharCommand& cmd = *static_cast<const DeleteCharCommand*>(command);
        RemoveText(cmd.PosAt, cmd.PosAt + 1);
        res = 1;
        break;
    }
    case Cmd_DeleteText:
    {
        const DeleteTextCommand& cmd = *static_cast<const DeleteTextCommand*>(command);
        UPInt stPos, endPos;
        if (cmd.BeginPos > cmd.EndPos)
        {
            stPos  = cmd.EndPos;
            endPos = cmd.BeginPos;
        }
        else
        {
            stPos  = cmd.BeginPos;
            endPos = cmd.EndPos;
        }
        RemoveText(stPos, endPos);
        res = endPos - stPos;
        break;
    }
    default: break;
    }
    return res;
}

}}} // namespace Scaleform::Render::Text

// MS2-PIN: ??1StyledText@Text@Render@Scaleform@@UEAA@XZ 0x14260d2c0
// MS2-FUNCTIONAL ??1StyledText@Text@Render@Scaleform@@UEAA@XZ: the inlined paragraph array teardown picks other callee-saved registers (r12/r14/r15 for rbp/rsi) and a 0x10 bigger frame; same calls and order
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318ea90
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_7StyledText@Text@Render@Scaleform@@6B@ 0x143184ca0
// MS2-PIN: ??_7?$RefCountBaseNTS@UTextFilter@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_7TextFilter@Text@Render@Scaleform@@6B@ 0x1431899f8
// MS2-PIN: ??_7?$RefCountBase@VDocView@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318e980
// MS2-PIN: ??_7DocView@Text@Render@Scaleform@@6B@ 0x14318e9c0
// MS2-PIN: ??_7DocumentText@DocView@Text@Render@Scaleform@@6B@ 0x14318e988
