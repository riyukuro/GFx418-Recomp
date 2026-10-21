// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Text_EditorKit: the editor of an
// input text field (cursor and its blinking, selection, key / mouse / character input, clipboard, the restrict
// filter) and the IME composition string drawn inline in the document.
// Main source of queue unit sfr_gfx_07 (the unit spans several original GFx sources, see sfr_gfx_07b / 07e).
// MS2-UNIT: sfr_gfx_07
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142615c70-0x14261a950 .text$mn

// MS2-PIN: ??_7EditorKit@Text@GFx@Scaleform@@6B@ 0x14318eb40
// MS2-PIN: ??_7CompositionString@Text@GFx@Scaleform@@6B@ 0x14318eb10
// MS2-PIN: ??_7?$RefCountBase@VCompositionStringBase@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318ea90
// MS2-PIN: ??_7CompositionStringBase@Text@Render@Scaleform@@6B@ 0x14318ea98
// MS2-PIN: ??_7?$RefCountBase@VEditorKitBase@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318eac8
// MS2-PIN: ??_7EditorKitBase@Text@Render@Scaleform@@6B@ 0x14318ead0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143191890
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_G?$RefCountBase@VCompositionStringBase@Text@Render@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x142616260
// MS2-PIN: ??_G?$RefCountBase@VEditorKitBase@Text@Render@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1426162c0
// MS2-PIN: ??_GCompositionStringBase@Text@Render@Scaleform@@UEAAPEAXI@Z 0x142616450
// MS2-PIN: ??_GCompositionString@Text@GFx@Scaleform@@UEAAPEAXI@Z 0x142616320
// MS2-PIN: ?Reset@?$AutoPtr@URestrictParams@EditorKit@Text@GFx@Scaleform@@@Scaleform@@QEAAXPEAURestrictParams@EditorKit@Text@GFx@2@_N@Z 0x142619740

#include "ms2/scaleform/include/gfx/text_editorkit.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_timer.h"
#include "../include/kernel/sf_utf8util.h"

#include <math.h>

namespace Scaleform { namespace GFx { namespace Text {

// Inactive selection colours (grey background, white text).
#define MS2_INACTIVE_SEL_BKCOLOR   0xFF808080u
#define MS2_INACTIVE_SEL_TEXTCOLOR 0xFFFFFFFFu
// Two clicks at the same spot within this many milliseconds are a double click.
#define MS2_DOUBLE_CLICK_TIME_MS   300

// ---------------------------------------------------------------------------------------------------------------------
// EditorKit

// @0x142615f60
EditorKit::EditorKit(DocView* pdocview)
    : pDocView(pdocview), LastMousePos(Render::PointF::NoInit), Flags(0)
{
    CursorTimer        = 0.0;
    CursorPos          = 0;
    CursorColor        = 0xFF000000u;
    LastAdvanceTime    = 0.0;
    LastHorizCursorPos = -1.0f;
    LastClickTime      = 0;
    CursorRect->Clear();
    ActiveSelectionBkColor     = GFX_ACTIVE_SEL_BKCOLOR;
    ActiveSelectionTextColor   = GFX_ACTIVE_SEL_TEXTCOLOR;
    InactiveSelectionBkColor   = MS2_INACTIVE_SEL_BKCOLOR;
    InactiveSelectionTextColor = MS2_INACTIVE_SEL_TEXTCOLOR;
    pdocview->SetEditorKit(this);
}

// @0x1426161e0
EditorKit::~EditorKit()
{
}

// Moves the cursor (clamped to the text; never into the middle of a substituted image), scrolls it into view and
// updates the selection: extended while shift or the mouse is held, collapsed otherwise.
// @0x142619b80
void EditorKit::SetCursorPos(UPInt pos, bool selectionAllowed)
{
    if (pos != SF_MAX_UPINT)
    {
        UPInt len = pDocView->GetLength();
        if (pos > len)
            pos = len;

        ResetBlink(true);

        if (pDocView->GetImageSubstitutor())
        {
            UPInt textPos;
            const LineBuffer::GlyphEntry* pge = GetGlyphEntryAtIndex(pos, &textPos);
            if (pge && pge->GetLength() != 1 && textPos != pos)
            {
                if (pos >= CursorPos)
                    pos = textPos + pge->GetLength();
                else
                    pos = textPos;
            }
        }
    }

    CursorPos = pos;
    CursorRect.Invalidate();
    LastHorizCursorPos = -1.0f;

    if (CursorPos != SF_MAX_UPINT)
    {
        ScrollToCursor();
        GetDocument()->SetDefaultTextAndParaFormat(CursorPos);
    }
    if (IsSelectable())
    {
        if (selectionAllowed)
        {
            if (IsShiftPressed() || IsMouseCaptured())
            {
                if (pDocView->GetEndSelection() != CursorPos)
                    pDocView->SetEndSelection(CursorPos);
            }
            else
            {
                if (pDocView->GetBeginSelection() != CursorPos || pDocView->GetEndSelection() != CursorPos)
                    pDocView->SetSelection(CursorPos, CursorPos);
            }
        }
        else
            pDocView->SetSelection(CursorPos, CursorPos);
    }

    if (pDocView->GetDocumentListener())
        pDocView->GetDocumentListener()->Editor_OnCursorMoved(*this);
}

// The exe's out-of-line copy of DocView::GetAllocator (the document creates its allocator on first use).
// MS2-FUNCTIONAL StyledText::GetAllocator stays a call here; the exe inlines it
// @0x142617880
Render::Text::Allocator* DocView_GetAllocator_Call(DocView* pdocView)
{
    return pdocView->GetAllocator();
}

// @0x142617990
UPInt EditorKit::GetCursorPos() const
{
    return CursorPos;
}

// Per frame: toggles the cursor every half second, and while the mouse is captured above / below the view scrolls
// one line by moving the cursor there.
// @0x1426169c0
void EditorKit::Advance(Double timer)
{
    Double delta    = timer - LastAdvanceTime;
    LastAdvanceTime = timer;

    if (HasCursor())
    {
        if (CursorTimer + delta > 0.5)
        {
            if (!IsCursorTimerBlocked())
            {
                if (IsCursorBlink())
                    ClearCursorBlink();
                else
                    SetCursorBlink();
                if (pDocView->GetDocumentListener())
                    pDocView->GetDocumentListener()->Editor_OnCursorBlink(*this, IsCursorBlink());
            }
            CursorTimer = 0.0;
            ClearCursorTimerBlocked();
        }
        else
            CursorTimer += delta;
    }

    if (IsMouseCaptured())
    {
        if (LastMousePos.y <= pDocView->GetViewRect().y1)
        {
            unsigned lineIndex = pDocView->GetVScrollOffsetValue();
            if (lineIndex > 0)
            {
                --lineIndex;
                UPInt newPos = pDocView->GetCursorPosInLine(lineIndex, LastMousePos.y);
                if (newPos != CursorPos)
                    SetCursorPos(newPos);
            }
        }
        else if (LastMousePos.y >= pDocView->GetViewRect().y2)
        {
            unsigned lineIndex = pDocView->GetBottomVScroll() + 1;
            if (lineIndex < pDocView->GetLinesCount())
            {
                UPInt newPos = pDocView->GetCursorPosInLine(lineIndex, LastMousePos.y);
                if (newPos != CursorPos)
                    SetCursorPos(newPos);
            }
        }
    }
}

// The cursor box at charIndex in line buffer space: x of the glyph there, its advance as width, the line's height.
// Composition glyphs take no text positions unless avoidComposStr is false.
// MS2-FUNCTIONAL the exe schedules the nGlyph zeroing after the GlyphIterator constructor call
// @0x142616b60
bool EditorKit::CalcCursorRectInLineBuffer(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex,
                                           unsigned* pglyphIndex, bool avoidComposStr,
                                           LineBuffer::Line::Alignment* plineAlignment)
{
    pDocView->ForceReformat();
    unsigned lineIndex = pDocView->GetLineIndexOfChar(charIndex);
    if (lineIndex != ~0u)
    {
        const LineBuffer::Line& line = pDocView->GetLineBuffer()[lineIndex];
        if (plineAlignment)
            *plineAlignment = line.GetAlignment();

        UPInt    posInLine = charIndex - line.GetTextPos();
        int      xoffset   = 0;
        LineBuffer::GlyphIterator git = line.Begin();
        unsigned nGlyph = 0;

        // glyphs of no length before the first character (except a new line)
        for (; !git.IsFinished(); ++git)
        {
            const LineBuffer::GlyphEntry& ge = git.GetGlyph();
            if (ge.GetLength() != 0 || ge.IsNewLineChar())
                break;
            xoffset += ge.GetAdvance();
            ++nGlyph;
        }
        for (unsigned i = 0; i < posInLine && !git.IsFinished(); ++git)
        {
            const LineBuffer::GlyphEntry& ge = git.GetGlyph();
            xoffset += ge.GetAdvance();
            if (!avoidComposStr || !ge.IsComposStrGlyph())
                i += ge.GetLength();
            ++nGlyph;
        }
        float w = 0;
        if (!git.IsFinished())
            w = float(git.GetGlyph().GetAdvance());

        pcursorRect->x1 = line.GetOffsetX() + float(xoffset);
        pcursorRect->y1 = float(line.GetOffsetY());
        pcursorRect->x2 = pcursorRect->x1 + w;
        pcursorRect->y2 = pcursorRect->y1 + line.GetHeight();
        if (plineIndex)
            *plineIndex = lineIndex;
        if (pglyphIndex)
            *pglyphIndex = nGlyph;
        return true;
    }
    return false;
}

// Same box moved through the scroll offsets into the view rectangle's space.
// MS2-FUNCTIONAL float scheduling in the inlined BufferToView (the exe computes y before x and keeps xmm6 live)
// @0x142616df0
bool EditorKit::CalcCursorRectOnScreen(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex,
                                       unsigned* pglyphIndex, bool avoidComposStr,
                                       LineBuffer::Line::Alignment* plineAlignment)
{
    bool rv = CalcCursorRectInLineBuffer(charIndex, pcursorRect, plineIndex, pglyphIndex, avoidComposStr,
                                         plineAlignment);
    if (rv)
    {
        pcursorRect->Offset(Render::PointF(-float(pDocView->GetLineBuffer().GetHScrollOffset()),
                                           -float(pDocView->GetLineBuffer().GetVScrollOffsetInFixp())));
        const RectF& rect = pDocView->GetViewRect();
        pcursorRect->SetTopLeft(pDocView->GetLineBuffer().BufferToView(rect, pcursorRect->TopLeft()));
        pcursorRect->SetBottomRight(pDocView->GetLineBuffer().BufferToView(rect, pcursorRect->BottomRight()));
        pcursorRect->Offset(Render::PointF(rect.x1, rect.y1));
    }
    return rv;
}

// The glyph covering charIndex and the text position where it starts.
// @0x142617a30
const LineBuffer::GlyphEntry* EditorKit::GetGlyphEntryAtIndex(UPInt charIndex, UPInt* ptextPos)
{
    unsigned lineIndex = pDocView->GetLineIndexOfChar(charIndex);
    if (lineIndex == ~0u)
        return NULL;
    const LineBuffer::Line* pline = pDocView->GetLineBuffer().GetLine(lineIndex);
    if (!pline)
        return NULL;

    unsigned textPos   = pline->GetTextPos();
    UPInt    posInLine = charIndex - textPos;
    LineBuffer::GlyphIterator     git = pline->Begin();
    const LineBuffer::GlyphEntry* pge = NULL;

    for (; !git.IsFinished(); ++git)
    {
        const LineBuffer::GlyphEntry& ge = git.GetGlyph();
        if (ge.GetLength() != 0 || ge.IsNewLineChar())
            break;
    }
    unsigned prevLen = 0;
    for (unsigned i = 0; i <= posInLine; ++git)
    {
        textPos += prevLen;
        if (git.IsFinished())
            break;
        pge     = &git.GetGlyph();
        prevLen = pge->GetLength();
        i += prevLen;
    }
    if (ptextPos)
        *ptextPos = textPos;
    return pge;
}

// Overwrite mode draws the cursor as a one character highlight that blinks.
// @0x14261a730
void EditorKit::UpdateWideCursor()
{
    if (!HasCursor() || !IsWideCursor())
        return;

    bool blinkState;
    Highlighter*   phighlighter = pDocView->CreateHighlighterManager();
    HighlightDesc* pdesc        = phighlighter->GetHighlighterPtr(GFX_WIDECURSOR_HIGHLIGHTING_INDEX);
    if (!pdesc)
    {
        HighlightDesc desc;
        desc.StartPos = 0;
        desc.Length   = 0;
        desc.Offset   = 0;
        desc.Id       = GFX_WIDECURSOR_HIGHLIGHTING_INDEX;
        desc.Info.SetBackgroundColor(GFX_ACTIVE_SEL_BKCOLOR);
        desc.Info.SetTextColor(GFX_ACTIVE_SEL_TEXTCOLOR);
        pdesc      = phighlighter->CreateHighlighter(desc);
        blinkState = false;
    }
    else
        blinkState = pdesc->Length != 0;

    if (pdesc->StartPos != CursorPos || blinkState != IsCursorBlink())
    {
        pdesc->StartPos = CursorPos;
        pdesc->Length   = IsCursorBlink() ? 1 : 0;
        pDocView->UpdateHighlight(*pdesc);
    }
}

// @0x1426173e0
void EditorKit::ClearWideCursor()
{
    Flags &= ~Flags_WideCursor;

    Highlighter* phighlighter = pDocView->GetHighlighterManager();
    if (phighlighter)
    {
        HighlightDesc* pdesc = phighlighter->GetHighlighterPtr(GFX_WIDECURSOR_HIGHLIGHTING_INDEX);
        if (pdesc && pdesc->Length)
        {
            pdesc->Length = 0;
            pDocView->UpdateHighlight(*pdesc);
        }
    }
}

// Adds the blinking cursor of a focused editable field to the text layout. Its line buffer box is cached per format
// pass; the colour follows the default text format, or the highlight under the cursor.
// MS2-FUNCTIONAL stack slot assignment of the locals and the inlined UpdateWideCursor's HighlightDesc differ (frame 0x120 vs 0x110)
// @0x1426165e0
#pragma strict_gs_check(push, on)
void EditorKit::AddDrawCursorInfo(TextLayout::Builder& bld)
{
    if (IsReadOnly() || !IsFocused())
        return;
    if (IsWideCursor())
    {
        UpdateWideCursor();
        return;
    }
    if (!IsCursorBlink())
        return;

    unsigned lineIndex = SF_MAX_UINT;
    if (!CursorRect.IsValid(pDocView->GetFormatCounter()))
    {
        __declspec(align(16)) RectF newCursorRect;
        unsigned glyphIndex;
        UPInt    cursorPos = CursorPos;
        if (HasCompositionString())
            cursorPos += pComposStr->GetCursorPosition();

        if (CalcAbsCursorRectInLineBuffer(cursorPos, &newCursorRect, &lineIndex, &glyphIndex))
        {
            newCursorRect.x2 = newCursorRect.x1;

            const TextFormat* pdefFormat = pDocView->GetDefaultTextFormat();
            if (pdefFormat && pdefFormat->IsColorSet())
                CursorColor = pdefFormat->GetColor32();

            Highlighter* phighlighter = pDocView->GetHighlighterManager();
            if (phighlighter)
            {
                HighlighterPosIterator it   = phighlighter->GetPosIterator(CursorPos);
                const HighlightDesc&   desc = *it;
                if (desc.Info.HasTextColor())
                    CursorColor = desc.Info.GetTextColor();
            }
        }
        else
            newCursorRect.Clear();
        CursorRect.SetValue(newCursorRect, pDocView->GetFormatCounter());
    }

    __declspec(align(16)) RectF cursorRect = *CursorRect;
    const RectF& textRect   = pDocView->GetTextRect();
    cursorRect -= Render::PointF(float(pDocView->GetLineBuffer().GetHScrollOffset()),
                                 float(pDocView->GetLineBuffer().GetVScrollOffsetInFixp()));
    cursorRect += textRect.TopLeft();

    // a line taller than the view (single line, big leading) gets its cursor cut at the view's bottom
    if (cursorRect.y2 > textRect.y2)
    {
        if (lineIndex == SF_MAX_UINT)
            lineIndex = pDocView->GetLineIndexOfChar(CursorPos);
        if (pDocView->GetLineBuffer().IsLineVisible(lineIndex))
            cursorRect.y2 = textRect.y2;
    }
    if (textRect.Contains(cursorRect))
    {
        cursorRect.x2 = cursorRect.x1 + PixelsToFixp(1.f);
        bld.AddCursor(cursorRect, CursorColor.ToColor32());
    }
}
#pragma strict_gs_check(pop)

// Shows the cursor (state) or hides it and restarts the blink period; blocked skips the next toggle.
// @0x1426197f0
void EditorKit::ResetBlink(bool state, bool blocked)
{
    if (!IsReadOnly())
    {
        if (state)
            SetCursorBlink();
        else
            ClearCursorBlink();
    }
    else
        ClearCursorBlink();
    CursorTimer = 0.0;
    if (blocked)
        SetCursorTimerBlocked();
}

#pragma strict_gs_check(push, on)
// Scrolls so that the cursor box at pos is inside the text rectangle (not for auto sized fields). True if the
// scroll offsets changed.
// @0x1426199a0
bool EditorKit::ScrollToPosition(UPInt pos, bool avoidComposStr, bool wideCursor)
{
    __declspec(align(16)) RectF newCursorRect;
    unsigned lineIndex;
    bool     rv = false;
    LineBuffer::Line::Alignment lineAlignment;

    if (CalcCursorRectOnScreen(pos, &newCursorRect, &lineIndex, NULL, avoidComposStr, &lineAlignment))
    {
        const RectF& textRect = pDocView->GetTextRect();
        if (!wideCursor)
            newCursorRect.SetWidth(20.f);

        if (!textRect.Contains(newCursorRect) && pDocView->GetTextAutoSize() == DocView::TAS_None &&
            !pDocView->IsAutoSizeX())
        {
            int hscroll     = int(pDocView->GetLineBuffer().GetHScrollOffset());
            int prevHScroll = hscroll;
            int delta       = GFX_EDIT_HSCROLL_DELTA;
            if (lineAlignment != LineBuffer::Line::Align_Left)
                delta = 0;

            if (newCursorRect.x2 > textRect.x2)
            {
                hscroll += int(newCursorRect.x1 - textRect.x2 + delta);
                __declspec(align(16)) RectF lastChar;
                if (pos > 0 && pDocView->GetExactCharBoundaries(&lastChar, pos - 1))
                    hscroll = Alg::Min(int(lastChar.x1 - GFX_TEXT_GUTTER), hscroll);
                hscroll = Alg::Max(0, hscroll);
            }
            else if (newCursorRect.x1 < textRect.x1)
            {
                hscroll -= int(textRect.x1 - newCursorRect.x1) + delta;
                hscroll = Alg::Max(0, hscroll);
            }

            // word wrapped text only ever scrolls back to the left
            if (!pDocView->IsWordWrap() || hscroll < prevHScroll)
                rv = pDocView->SetHScrollOffset(unsigned(hscroll));

            unsigned firstLine = pDocView->GetVScrollOffsetValue();
            if (lineIndex < firstLine)
                return pDocView->SetVScrollOffset(lineIndex) | rv;
            if (lineIndex > pDocView->GetBottomVScroll())
                return pDocView->SetBottomVScroll(lineIndex) | rv;
        }
    }
    return rv;
}
#pragma strict_gs_check(pop)

// Left button: places the cursor and starts a mouse selection; a double click selects the word, a triple click the
// paragraph.
// @0x142618bf0
void EditorKit::OnMouseDown(float x, float y, int buttons)
{
    if (!(buttons & 1))
        return;

    const RectF& r  = pDocView->GetViewRect();
    float        ax = float(floor(x - r.x1));
    float        ay = float(floor(y - r.y1));
    UInt32       tm = UInt32(Timer::GetTicks() / 1000);

    bool doubleClick = false, tripleClick = false;
    if (LastMousePos.x == ax && LastMousePos.y == ay && tm <= LastClickTime + MS2_DOUBLE_CLICK_TIME_MS)
    {
        if (IsLastDoubleClickFlagSet())
            tripleClick = true;
        else
            doubleClick = true;
        SetLastDoubleClickFlag();
    }
    else
        ClearLastDoubleClickFlag();
    LastMousePos.x = ax;
    LastMousePos.y = ay;
    LastClickTime  = tm;

    UPInt pos = pDocView->GetCursorPosAtPoint(ax, ay);
    if (pos == SF_MAX_UPINT)
        return;
    SetCursorPos(pos);
    if (!IsSelectable() || IsMouseCaptured())
        return;

    SetMouseCaptured();
    if (doubleClick || tripleClick)
    {
        UPInt indexInPara;
        StyledText::ParagraphsIterator it = pDocView->GetStyledText()->GetParagraphByIndex(pos, &indexInPara);
        if (!it.IsFinished())
        {
            Paragraph* ppara   = *it;
            UPInt      textLen = ppara->GetLength();
            UPInt      st = indexInPara, en = indexInPara;
            if (doubleClick)
            {
                const wchar_t* ptext = ppara->GetText();
                for (; st > 0; --st)
                    if (SFiswspace(ptext[st - 1]) || !SFiswalnum(ptext[st - 1]))
                        break;
                for (; en < textLen; ++en)
                    if (SFiswspace(ptext[en]) || !SFiswalnum(ptext[en]))
                        break;
            }
            else
            {
                st = 0;
                en = textLen;
            }
            UPInt paraStart = ppara->GetStartIndex();
            st += paraStart;
            en += paraStart;
            SetCursorPos(en);
            pDocView->SetSelection(st, en);
        }
    }
    else if (!IsShiftPressed())
        pDocView->SetSelection(pos, pos);
}

// @0x142619040
void EditorKit::OnMouseUp(float x, float y, int buttons)
{
    (void)x;
    (void)y;
    if (!(buttons & 1) && IsSelectable() && IsMouseCaptured())
        ClearMouseCaptured();
}

// @0x142618f60
void EditorKit::OnMouseMove(float x, float y)
{
    if (!IsMouseCaptured())
        return;
    const RectF& r = pDocView->GetViewRect();
    float ax = float(floor(x - r.x1));
    float ay = float(floor(y - r.y1));
    LastMousePos.x = ax;
    LastMousePos.y = ay;

    UPInt pos = pDocView->GetCursorPosAtPoint(ax, ay);
    if (pos != SF_MAX_UPINT)
    {
        SetCursorPos(pos);
        if (IsSelectable())
            pDocView->SetEndSelection(pos);
    }
}

// @0x142618b60
bool EditorKit::OnKeyUp(int keyCode, const KeyModifiers& specKeysState)
{
    if (pKeyMap)
    {
        const TextKeyMap::KeyMapEntry* pke = pKeyMap->Find(keyCode, specKeysState, TextKeyMap::State_Up);
        if (pke && pke->Action == TextKeyMap::KeyAct_LeaveSelectionMode && IsSelectable() && IsShiftPressed())
            ClearShiftPressed();
    }
    return true;
}

// Runs the key map action bound to keyCode: cursor movement, deletion, clipboard, select all. True if the cursor
// moved.
// MS2-FUNCTIONAL register permutation (rbx / rdi for this) and jump table layout
// @0x142618400
bool EditorKit::OnKeyDown(int keyCode, const KeyModifiers& specKeysState)
{
    DocView* pdocument = GetDocument();
    UPInt    len       = pdocument->GetStyledText()->GetLength();
    bool     rv        = false;
    UPInt    newPos    = CursorPos;

    if (pdocument->GetDocumentListener())
        keyCode = pdocument->GetDocumentListener()->Editor_OnKey(*this, keyCode);

    bool  needChangeNotify = false, noActions = false, isShiftPressed = IsShiftPressed();
    float lastHorizCursorPos = -1.0f;
    UPInt beginSel = pDocView->GetBeginSelection(), endSel = pDocView->GetEndSelection();

    const TextKeyMap::KeyMapEntry* pke = NULL;
    if (pKeyMap)
        pke = pKeyMap->Find(keyCode, specKeysState, TextKeyMap::State_Down);
    if (!pke)
        noActions = true;
    else
    {
        switch (pke->Action)
        {
        case TextKeyMap::KeyAct_EnterSelectionMode:
            if (IsSelectable())
                isShiftPressed = true;
            noActions = true;
            break;

        case TextKeyMap::KeyAct_Left:
            if (newPos == SF_MAX_UPINT)
                newPos = len;
            if (newPos > 0)
                --newPos;
            if (!IsShiftPressed() && beginSel != endSel)
                newPos = Alg::PMin(beginSel, endSel);
            break;

        case TextKeyMap::KeyAct_Right:
            if (newPos == SF_MAX_UPINT)
                newPos = len;
            else if (newPos < len)
                ++newPos;
            if (!IsShiftPressed() && beginSel != endSel)
                newPos = Alg::PMax(beginSel, endSel);
            break;

        case TextKeyMap::KeyAct_LineHome:
        {
            unsigned lineIndex = pDocView->GetLineIndexOfChar(CursorPos);
            if (lineIndex != ~0u)
                newPos = pDocView->GetLineOffset(lineIndex);
            break;
        }
        case TextKeyMap::KeyAct_LineEnd:
        {
            unsigned lineIndex = pDocView->GetLineIndexOfChar(CursorPos);
            if (lineIndex != ~0u)
            {
                bool  hasNewLine = false;
                UPInt lineLen    = pDocView->GetLineLength(lineIndex, &hasNewLine);
                if (hasNewLine)
                    --lineLen;
                newPos = pDocView->GetLineOffset(lineIndex) + lineLen;
            }
            break;
        }
        case TextKeyMap::KeyAct_DocHome:
            newPos = 0;
            break;
        case TextKeyMap::KeyAct_DocEnd:
            newPos = len;
            break;

        case TextKeyMap::KeyAct_PageHome:
            newPos = pDocView->GetLineOffset(pDocView->GetVScrollOffsetValue());
            break;
        case TextKeyMap::KeyAct_PageEnd:
        {
            unsigned lineIndex  = pDocView->GetBottomVScroll();
            bool     hasNewLine = false;
            UPInt    lineLen    = pDocView->GetLineLength(lineIndex, &hasNewLine);
            if (hasNewLine)
                --lineLen;
            newPos = pDocView->GetLineOffset(lineIndex) + lineLen;
            break;
        }

        case TextKeyMap::KeyAct_PageUp:
        {
            RectF    cursorRect;
            unsigned lineIndex;
            if (CalcCursorRectOnScreen(CursorPos, &cursorRect, &lineIndex))
            {
                lastHorizCursorPos = (LastHorizCursorPos < 0) ? cursorRect.x1 : LastHorizCursorPos;
                unsigned linesOnScreen = pDocView->GetBottomVScroll() - pDocView->GetVScrollOffsetValue() + 1;
                if (lineIndex < linesOnScreen)
                    newPos = 0;
                else
                    newPos = pDocView->GetCursorPosInLine(lineIndex - linesOnScreen, lastHorizCursorPos);
            }
            break;
        }
        case TextKeyMap::KeyAct_PageDown:
        {
            RectF    cursorRect;
            unsigned lineIndex;
            if (CalcCursorRectOnScreen(CursorPos, &cursorRect, &lineIndex))
            {
                lastHorizCursorPos = (LastHorizCursorPos < 0) ? cursorRect.x1 : LastHorizCursorPos;
                unsigned linesOnScreen = pDocView->GetBottomVScroll() - pDocView->GetVScrollOffsetValue() + 1;
                lineIndex += linesOnScreen;
                if (lineIndex >= pDocView->GetLinesCount())
                    newPos = len;
                else
                    newPos = pDocView->GetCursorPosInLine(lineIndex, lastHorizCursorPos);
            }
            break;
        }

        case TextKeyMap::KeyAct_Up:
        {
            RectF    cursorRect;
            unsigned lineIndex;
            if (!IsShiftPressed() && beginSel != endSel)
                newPos = Alg::PMin(beginSel, endSel);
            else if (CalcCursorRectOnScreen(CursorPos, &cursorRect, &lineIndex))
            {
                if (lineIndex > 0)
                {
                    lastHorizCursorPos = (LastHorizCursorPos < 0) ? cursorRect.x1 : LastHorizCursorPos;
                    newPos = pDocView->GetCursorPosInLine(lineIndex - 1, lastHorizCursorPos);
                }
                else
                    newPos = 0;
            }
            break;
        }
        case TextKeyMap::KeyAct_Down:
        {
            RectF    cursorRect;
            unsigned lineIndex;
            if (!IsShiftPressed() && beginSel != endSel)
                newPos = Alg::PMax(beginSel, endSel);
            else if (CalcCursorRectOnScreen(CursorPos, &cursorRect, &lineIndex))
            {
                if (lineIndex + 1 < pDocView->GetLinesCount())
                {
                    lastHorizCursorPos = (LastHorizCursorPos < 0) ? cursorRect.x1 : LastHorizCursorPos;
                    newPos = pDocView->GetCursorPosInLine(lineIndex + 1, lastHorizCursorPos);
                }
                else
                    newPos = len;
            }
            break;
        }

        case TextKeyMap::KeyAct_Backspace:
            if (!IsReadOnly())
            {
                ClearShiftPressed();
                if (beginSel == endSel)
                {
                    DocView::DeleteCharCommand cmd(newPos);
                    newPos -= pDocView->EditCommand(DocView::Cmd_BackspaceChar, &cmd);
                }
                else
                {
                    DocView::DeleteTextCommand cmd(beginSel, endSel);
                    pDocView->EditCommand(DocView::Cmd_DeleteText, &cmd);
                    newPos = Alg::PMin(beginSel, endSel);
                }
                needChangeNotify = true;
            }
            break;
        case TextKeyMap::KeyAct_Delete:
            if (!IsReadOnly())
            {
                ClearShiftPressed();
                if (beginSel == endSel)
                {
                    if (CursorPos < len)
                    {
                        DocView::DeleteCharCommand cmd(newPos);
                        pDocView->EditCommand(DocView::Cmd_DeleteChar, &cmd);
                        needChangeNotify = true;
                    }
                }
                else
                {
                    DocView::DeleteTextCommand cmd(beginSel, endSel);
                    pDocView->EditCommand(DocView::Cmd_DeleteText, &cmd);
                    newPos           = Alg::PMin(beginSel, endSel);
                    needChangeNotify = true;
                }
            }
            break;

        case TextKeyMap::KeyAct_SelectAll:
            beginSel = 0;
            endSel = newPos = len;
            SetCursorPos(newPos);
            pDocView->SetSelection(beginSel, endSel);
            noActions = true;
            break;

        case TextKeyMap::KeyAct_Copy:
        case TextKeyMap::KeyAct_Cut:
            if (pClipboard)
            {
                ClearShiftPressed();
                if (IsReadOnly() || pke->Action == TextKeyMap::KeyAct_Copy)
                {
                    CopyToClipboard(beginSel, endSel, DoesUseRichClipboard());
                    noActions = true;
                }
                else
                {
                    CutToClipboard(beginSel, endSel, DoesUseRichClipboard());
                    newPos           = Alg::PMin(beginSel, endSel);
                    needChangeNotify = true;
                }
            }
            break;
        case TextKeyMap::KeyAct_Paste:
        {
            UPInt pastedPos = PasteFromClipboard(beginSel, endSel, DoesUseRichClipboard());
            if (pastedPos != SF_MAX_UPINT)
            {
                newPos           = pastedPos;
                needChangeNotify = true;
            }
            break;
        }

        default:
            noActions = true;
            break;
        }
    }

    if (!noActions)
    {
        if (CursorPos != newPos)
        {
            SetCursorPos(newPos);
            LastHorizCursorPos = lastHorizCursorPos;
            rv = true;
        }
        else if (!IsShiftPressed() && beginSel != endSel)
        {
            SetCursorPos(newPos);
            rv = true;
        }
        if (needChangeNotify)
        {
            if (!rv)
                pDocView->SetDefaultTextAndParaFormat(CursorPos);
            if (pdocument->GetDocumentListener())
                pdocument->GetDocumentListener()->Editor_OnChanged(*this);
        }
    }
    if (isShiftPressed)
        SetShiftPressed();
    return rv;
}

// Types one character: inserts it, replaces the selection with it (or the character under the cursor in overwrite
// mode); Return inserts the document's new line character in multiline fields. A restricted character is retried
// in the other case.
// MS2-FUNCTIONAL register allocation and frame layout differ (the exe uses fewer callee-saved registers)
// @0x142618120
bool EditorKit::OnChar(UInt32 wcharCode)
{
    if (!wcharCode || IsMouseCaptured())
        return false;

    if (pRestrict && !CheckRestrict(wchar_t(wcharCode)))
    {
        int up  = SFtowupper(wchar_t(wcharCode));
        int low = SFtowlower(wchar_t(wcharCode));
        if (int(wcharCode) != up)
            wcharCode = UInt32(up);
        else
            wcharCode = UInt32(low);
        if (!CheckRestrict(wchar_t(wcharCode)))
            return false;
    }

    DocView* pdocument = GetDocument();
    bool     rv        = false;
    UPInt    newPos    = CursorPos;
    UPInt    beginSel  = pDocView->GetBeginSelection(), endSel = pDocView->GetEndSelection();
    bool     needChangeNotify = false;

    if (IsReadOnly())
        return rv;
    wchar_t wc = wchar_t(wcharCode);
    if (wc != 13 && wc < 32)
        return rv;

    if (wc >= 32)
    {
        if (beginSel == endSel && IsOverwriteMode())
            ++endSel;
        if (beginSel == endSel)
        {
            DocView::InsertCharCommand cmd(CursorPos, wc);
            newPos += pDocView->EditCommand(DocView::Cmd_InsertChar, &cmd);
        }
        else
        {
            DocView::ReplaceTextByCharCommand cmd(beginSel, endSel, wc);
            UPInt n = pDocView->EditCommand(DocView::Cmd_ReplaceTextByChar, &cmd);
            newPos  = Alg::PMin(beginSel, endSel) + n;
        }
        needChangeNotify = true;
    }
    else if (pDocView->IsMultiline())
    {
        ClearShiftPressed();
        if (beginSel == endSel)
        {
            DocView::InsertCharCommand cmd(CursorPos, pDocView->NewLineChar());
            pDocView->EditCommand(DocView::Cmd_InsertChar, &cmd);
            ++newPos;
        }
        else
        {
            DocView::ReplaceTextByCharCommand cmd(beginSel, endSel, pDocView->NewLineChar());
            pDocView->EditCommand(DocView::Cmd_ReplaceTextByChar, &cmd);
            newPos = Alg::PMin(beginSel, endSel) + 1;
        }
        needChangeNotify = true;
    }

    if (CursorPos != newPos || beginSel != newPos || endSel != newPos)
    {
        SetCursorPos(newPos, false);
        rv = true;
    }
    if (needChangeNotify && pdocument->GetDocumentListener())
        pdocument->GetDocumentListener()->Editor_OnChanged(*this);
    return rv;
}

// A new text resets the cursor to the start; otherwise it is only kept inside the text.
// @0x142618380
void EditorKit::OnDocumentChanged(unsigned notifyMask)
{
    if (notifyMask & DocView::ViewNotify_SignificantTextChange)
    {
        if (!IsReadOnly() || IsSelectable())
            SetCursorPos(0);
    }
    else if (CursorPos > pDocView->GetLength())
        SetCursorPos(pDocView->GetLength());
}

// @0x142619070
void EditorKit::OnSetFocus()
{
    pDocView->SetSelectionTextColor(ActiveSelectionTextColor);
    pDocView->SetSelectionBackgroundColor(ActiveSelectionBkColor);
    SetFocused();
}

// @0x142618bb0
void EditorKit::OnKillFocus()
{
    pDocView->SetSelectionTextColor(InactiveSelectionTextColor);
    pDocView->SetSelectionBackgroundColor(InactiveSelectionBkColor);
    ClearShiftPressed();
    ClearMouseCaptured();
    ClearFocused();
}

// @0x14261a4f0
void EditorKit::SetSelection(UPInt startPos, UPInt endPos)
{
    if (!IsReadOnly() || IsSelectable())
        SetCursorPos(endPos);
    pDocView->SetSelection(startPos, endPos, IsSelectable());
}

// Password fields never reach the clipboard.
// @0x142617440
void EditorKit::CopyToClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard)
{
    if (!pClipboard || pDocView->IsPasswordMode())
        return;
    if (endPos < startPos)
    {
        UPInt t  = endPos;
        endPos   = startPos;
        startPos = t;
    }
    WStringBuffer wbuf;
    pDocView->GetStyledText()->GetText(&wbuf, startPos, endPos);
    if (useRichClipboard)
    {
        Ptr<StyledText> ptext = *pDocView->GetStyledText()->CopyStyledText(startPos, endPos);
        pClipboard->SetTextAndStyledText(wbuf.ToWStr(), wbuf.GetLength(), ptext);
    }
    else
        pClipboard->SetText(wbuf.ToWStr(), wbuf.GetLength());
}

// @0x1426175b0
void EditorKit::CutToClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard)
{
    if (!pClipboard)
        return;
    if (endPos < startPos)
    {
        UPInt t  = endPos;
        endPos   = startPos;
        startPos = t;
    }
    CopyToClipboard(startPos, endPos, useRichClipboard);
    if (!IsReadOnly())
        pDocView->RemoveText(startPos, endPos);
}

// Inserts the clipboard (styled when asked and available) over the range, then removes or re-cases whatever the
// restrict filter refuses. Returns the cursor position after the pasted text, SF_MAX_UPINT if nothing was pasted.
// MS2-FUNCTIONAL register permutation; the lb5 oracle build is functional only too
// @0x142619270
UPInt EditorKit::PasteFromClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard)
{
    UPInt newPos = SF_MAX_UPINT;
    if (IsReadOnly() || !pClipboard)
        return newPos;
    if (endPos < startPos)
    {
        UPInt t  = endPos;
        endPos   = startPos;
        startPos = t;
    }

    if (useRichClipboard && pClipboard->ContainsRichText())
    {
        Ptr<StyledText> pstr = pClipboard->GetStyledText();
        if (pstr && pstr->GetLength() > 0)
        {
            ClearShiftPressed();
            if (startPos == endPos)
            {
                DocView::InsertStyledTextCommand cmd(startPos, pstr);
                newPos = startPos + pDocView->EditCommand(DocView::Cmd_InsertStyledText, &cmd);
            }
            else
            {
                DocView::ReplaceTextByStyledTextCommand cmd(startPos, endPos, pstr);
                newPos = startPos + pDocView->EditCommand(DocView::Cmd_ReplaceTextByStyledText, &cmd);
            }
        }
    }
    else
    {
        const WStringBuffer& str = pClipboard->GetText();
        if (str.GetLength() > 0)
        {
            ClearShiftPressed();
            if (startPos == endPos)
            {
                DocView::InsertPlainTextCommand cmd(startPos, str.ToWStr(), str.GetLength());
                newPos = startPos + pDocView->EditCommand(DocView::Cmd_InsertPlainText, &cmd);
            }
            else
            {
                DocView::ReplaceTextByPlainTextCommand cmd(startPos, endPos, str.ToWStr(), str.GetLength());
                newPos = startPos + pDocView->EditCommand(DocView::Cmd_ReplaceTextByPlainText, &cmd);
            }
        }
    }

    if (pRestrict)
    {
        UPInt  l = pDocView->GetLength();
        String s = pDocView->GetText();
        for (UPInt i = 0, pos = 0; i < l; ++i, ++pos)
        {
            UInt32 wcharCode = s.GetCharAt(i);
            if (CheckRestrict(wchar_t(wcharCode)))
                continue;
            int up  = SFtowupper(wchar_t(wcharCode));
            int low = SFtowlower(wchar_t(wcharCode));
            if (int(wcharCode) != up)
                wcharCode = UInt32(up);
            else
                wcharCode = UInt32(low);
            if (!CheckRestrict(wchar_t(wcharCode)))
            {
                DocView::DeleteCharCommand cmd(pos);
                pDocView->EditCommand(DocView::Cmd_DeleteChar, &cmd);
                --pos;
            }
            else
            {
                DocView::ReplaceTextByCharCommand cmd(pos, pos + 1, wchar_t(wcharCode));
                pDocView->EditCommand(DocView::Cmd_ReplaceTextByChar, &cmd);
            }
        }
    }
    return newPos;
}

// @0x142618090
void EditorKit::InvalidateSelectionColors()
{
    if (Flags & Flags_Focused)
    {
        pDocView->SetSelectionTextColor(ActiveSelectionTextColor);
        pDocView->SetSelectionBackgroundColor(ActiveSelectionBkColor);
    }
    else
    {
        pDocView->SetSelectionTextColor(InactiveSelectionTextColor);
        pDocView->SetSelectionBackgroundColor(InactiveSelectionBkColor);
    }
}

// @0x142617540
CompositionString* EditorKit::CreateCompositionString()
{
    pComposStr = *SF_HEAP_AUTO_NEW(this) CompositionString(this);
    return pComposStr;
}

// Drops the composition and has its paragraph laid out again without it.
// @0x1426195d0
void EditorKit::ReleaseCompositionString()
{
    if (pComposStr)
    {
        Ptr<CompositionString> pcs = pComposStr;
        pComposStr = NULL;
        pcs->Reformat();
    }
}

// @0x142617e60
bool EditorKit::HasCompositionString() const
{
    return pComposStr && pComposStr->GetLength() > 0;
}

// @0x142617980
CompositionString* EditorKit::GetCompositionString()
{
    return pComposStr;
}

// Text and glyph positions differ by the composition string's length after it.
// @0x14261a690
UPInt EditorKit::TextPos2GlyphOffset(UPInt textPos)
{
    if (HasCompositionString() && textPos > pComposStr->GetPosition())
        return textPos + pComposStr->GetLength();
    return textPos;
}

// @0x14261a6e0
UPInt EditorKit::TextPos2GlyphPos(UPInt textPos)
{
    if (HasCompositionString() && textPos >= pComposStr->GetPosition())
        return textPos + pComposStr->GetLength();
    return textPos;
}

// Glyphs inside the composition all map to its position.
// @0x142617dd0
UPInt EditorKit::GlyphPos2TextPos(UPInt glyphPos)
{
    if (HasCompositionString())
    {
        if (glyphPos <= pComposStr->GetPosition())
            return glyphPos;
        if (glyphPos >= pComposStr->GetPosition() + pComposStr->GetLength())
            return glyphPos - pComposStr->GetLength();
        return pComposStr->GetPosition();
    }
    return glyphPos;
}

// Parses an ActionScript "restrict" string (UTF-8) into allowed character ranges: "a-z" is a range, "^" toggles
// excluding, "\" escapes the next character. Starting with an exclusion allows everything first.
// @0x1426190b0
bool EditorKit::ParseRestrict(const char* restrStr, UPInt restrStrLen)
{
    pRestrict = SF_HEAP_AUTO_NEW(this) RestrictParams();
    if (!pRestrict)
        return false;

    void*       pdata    = 0;
    const char* p        = restrStr;
    const char* pend     = p + restrStrLen;
    bool        negative = false;
    UInt32      rangeStart = 0, prevCh = 0;
    while (p < pend)
    {
        UInt32 ch = UTF8Util::DecodeNextChar(&p);
        if (ch == '^')
        {
            negative = !negative;
            continue;
        }
        if (ch == '\\')
        {
            if (p >= pend)
                break;
            ch = UTF8Util::DecodeNextChar(&p);
        }
        else if (ch == '-')
        {
            rangeStart = prevCh;
            continue;
        }

        if (!rangeStart)
            rangeStart = ch;
        if (ch < rangeStart)
            ch = rangeStart;

        if (!negative)
            pRestrict->RestrictRanges.SetRange(SPInt(rangeStart), ch - rangeStart + 1, pdata);
        else
        {
            if (pRestrict->RestrictRanges.Count() == 0)
                pRestrict->RestrictRanges.SetRange(0, 65536, pdata);
            pRestrict->RestrictRanges.ClearRange(SPInt(rangeStart), ch - rangeStart + 1);
        }
        prevCh     = ch;
        rangeStart = 0;
    }
    return true;
}

// @0x14261a490
bool EditorKit::SetRestrict(const String& restrStr)
{
    bool rv = ParseRestrict(restrStr.ToCStr(), restrStr.GetSize());
    pRestrict->RestrictString = restrStr;
    return rv;
}

// @0x142617d40
const String* EditorKit::GetRestrict() const
{
    if (pRestrict)
        return &pRestrict->RestrictString;
    return NULL;
}

// @0x142617350
void EditorKit::ClearRestrict()
{
    pRestrict = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------
// CompositionString

// Copies the document's default text format and reserves the highlighters it will need.
// MS2-FUNCTIONAL the exe calls DocView::GetAllocator out of line (0x142617880, StyledText::GetAllocator inlined into it); here the inlining is the other way round
// @0x142615c70
CompositionString::CompositionString(EditorKit* const peditorKit)
    : pEditorKit(peditorKit), pAllocator(peditorKit->GetDocument()->GetAllocator()),
      String(peditorKit->GetDocument()->GetAllocator()), CursorPos(0), HasHighlightingFlag(false),
      HighlightIdsUsed(0)
{
    TextFormat        emptyFormat(pAllocator->GetHeap());
    const TextFormat* pdefFmt = peditorKit->GetDocument()->GetDefaultTextFormat();
    if (!pdefFmt)
        pdefFmt = &emptyFormat;
    pDefaultFormat = *GetAllocator()->AllocateTextFormat(*pdefFmt);
    String.AppendTermNull(GetAllocator(), pDefaultFormat);

    Highlighter* phighlighter = pEditorKit->GetDocument()->CreateHighlighterManager();
    for (UPInt i = 0; i < sizeof(HighlightIds) / sizeof(HighlightIds[0]); i++)
    {
        HighlightDesc desc;
        desc.StartPos = 0;
        desc.Offset   = 0;
        desc.Length   = 0;
        HighlightDesc* pdesc = phighlighter->CreateNewHighlighter(&desc);
        HighlightIds[i] = pdesc->Id;
    }
    Styles = GetDefaultStyles();
}

// MS2-FUNCTIONAL the exe inlines ~Paragraph for the String member; the shared render header keeps it out of line
// MS2-FUNCTIONAL ??_GCompositionString@Text@GFx@Scaleform@@UEAAPEAXI@Z: inlines ~CompositionString, see there (~Paragraph stays a call)
// @0x1426160f0
CompositionString::~CompositionString()
{
    Highlighter* phighlighter = pEditorKit->GetDocument()->CreateHighlighterManager();
    for (UPInt i = 0; i < sizeof(HighlightIds) / sizeof(HighlightIds[0]); i++)
        phighlighter->FreeHighlighter(HighlightIds[i]);
    String.FreeText(GetAllocator());
}

// Dotted / thick / single underlines, inverted colours for phrase adjustment, green underline for low confidence.
// @0x1426179a0
IMEStyle CompositionString::GetDefaultStyles()
{
    IMEStyle styles;
    styles.SetElement(IMEStyle::SC_CompositionSegment, HighlightInfo(HighlightInfo::Underline_Dotted));
    styles.SetElement(IMEStyle::SC_ClauseSegment, HighlightInfo(HighlightInfo::Underline_Thick));
    styles.SetElement(IMEStyle::SC_ConvertedSegment, HighlightInfo(HighlightInfo::Underline_Single));
    HighlightInfo adjInfo;
    adjInfo.SetBackgroundColor(GFX_ACTIVE_SEL_BKCOLOR);
    adjInfo.SetTextColor(GFX_ACTIVE_SEL_TEXTCOLOR);
    styles.SetElement(IMEStyle::SC_PhraseLengthAdj, adjInfo);
    HighlightInfo lowConfInfo(HighlightInfo::Underline_Single);
    lowConfInfo.SetUnderlineColor(Color(0, 255, 0, 0));
    styles.SetElement(IMEStyle::SC_LowConfSegment, lowConfInfo);
    return styles;
}

// @0x142617d50
Paragraph* CompositionString::GetSourceParagraph()
{
    UPInt pos = GetPosition();
    StyledText::ParagraphsIterator it = pEditorKit->GetDocument()->GetStyledText()->GetParagraphByIndex(pos, NULL);
    if (!it.IsFinished())
        return *it;
    return NULL;
}

// @0x142619560
void CompositionString::Reformat()
{
    Paragraph* ppara = GetSourceParagraph();
    if (ppara)
    {
        ppara->MarkToReformat();
        pEditorKit->GetDocument()->SetReformatReq();
    }
}

// @0x14261a570
void CompositionString::SetText(const wchar_t* pwstr, UPInt nchars)
{
    ClearHighlighting();
    String.Clear();
    String.SetText(GetAllocator(), pwstr, nchars);
    String.SetTextFormat(GetAllocator(), *pDefaultFormat, 0, String.GetSize());
    String.AppendTermNull(GetAllocator(), pDefaultFormat);
    Reformat();
}

// @0x142619f10
void CompositionString::SetPosition(UPInt pos)
{
    String.SetStartIndex(pos);
    Reformat();
}

// @0x142619e80
void CompositionString::SetCursorPosition(UPInt pos)
{
    CursorPos = pos;
    pEditorKit->GetCursorRect().Invalidate();
    pEditorKit->ResetBlink(true);
    pEditorKit->ScrollToPosition(GetPosition() + CursorPos, false, pEditorKit->IsWideCursor());
}

// Gives the next free highlighter the look of styleCategory over [pos, pos+len) of the composition and scrolls the
// clause into view.
// @0x142617e90
void CompositionString::HighlightText(UPInt pos, UPInt len, IMEStyle::Category styleCategory)
{
    HasHighlightingFlag = true;
    if (HighlightIdsUsed >= sizeof(HighlightIds) / sizeof(HighlightIds[0]))
        return;

    Highlighter*   phighlighter = pEditorKit->GetDocument()->CreateHighlighterManager();
    HighlightDesc* pdesc        = phighlighter->GetHighlighterPtr(HighlightIds[HighlightIdsUsed++]);
    pdesc->StartPos = GetPosition();
    pdesc->Offset   = pos;
    pdesc->Length   = len;
    pdesc->Info     = Styles.GetElement(styleCategory);
    pEditorKit->GetDocument()->UpdateHighlight(*pdesc);

    if (len > 0)
    {
        pEditorKit->ScrollToPosition(GetPosition() + pos + len, false, pEditorKit->IsWideCursor());
        pEditorKit->ScrollToPosition(GetPosition() + pos, false, pEditorKit->IsWideCursor());
    }
}

// @0x142616f60
void CompositionString::ClearHighlighting()
{
    HasHighlightingFlag = false;
    Highlighter* phighlighter = pEditorKit->GetDocument()->CreateHighlighterManager();
    for (UPInt i = 0; i < HighlightIdsUsed; i++)
    {
        HighlightDesc* pdesc = phighlighter->GetHighlighterPtr(HighlightIds[i]);
        pdesc->StartPos = 0;
        pdesc->Length   = 0;
        pEditorKit->GetDocument()->UpdateHighlight(*pdesc);
    }
    HighlightIdsUsed = 0;
}

}}} // namespace Scaleform::GFx::Text

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SFiswalnum@Scaleform@@YAH_W@Z 0x142619900 ; prop
// MS2-PIN: ?SFiswspace@Scaleform@@YAH_W@Z 0x142619950 ; prop
// MS2-PINS-END tplpin
