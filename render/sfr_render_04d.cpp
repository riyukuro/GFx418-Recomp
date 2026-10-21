// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the line buffer TU
// (Text_LineBuffer): allocation and release of the variable-sized lines, the glyph iterator that resolves the
// format switches and highlights per glyph, the line searches and visibility tests, scaling, and the walk over
// the visible lines that fills a TextLayout::Builder.
// Queue unit sfr_render_04 is split along its original sources (04d Text_LineBuffer).
// MS2-UNIT: sfr_render_04d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142667cf0-0x14266a500 .text$mn

#include "ms2/scaleform/include/render/text_linebuffer.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_log.h"

namespace Scaleform {
void LogDebugMessage(LogMessageId id, const char* fmt, ...);
}

namespace Scaleform { namespace Render { namespace Text {

// ---------------------------------------------------------------------------------------------------------------
// Line allocation

// The header is set up for the requested variant; the glyphs are left to the caller.
// @0x142668050
LineBuffer::Line* LineBuffer::TextLineAllocator::AllocLine(unsigned size, LineBuffer::LineType lineType)
{
    Line* pline = (Line*)SF_HEAP_AUTO_ALLOC(this, size);
    pline->SetMemSize(size);
    if (lineType == Line8)
        pline->InitLine8();
    else
        pline->InitLine32();
    return pline;
}

// @0x1426692f0
void LineBuffer::TextLineAllocator::FreeLine(LineBuffer::Line* ptr)
{
    if (ptr)
    {
        ptr->Release();
        SF_FREE(ptr);
    }
}

// Walks n glyphs and releases the fonts and images their format switches hold.
// @0x142669b80
void LineBuffer::ReleasePartOfLine(GlyphEntry* pglyphs, unsigned n, FormatDataEntry* pnextFormatData)
{
    for (unsigned i = 0; i < n; ++i, ++pglyphs)
    {
        GlyphEntry* pglyph = pglyphs;
        if (pglyph->IsNextFormat())
        {
            if (pglyph->HasFmtFont())
            {
                pnextFormatData->pFont->Release();
                ++pnextFormatData;
            }
            if (pglyph->HasFmtColor())
                ++pnextFormatData;
            if (pglyph->HasFmtImage())
            {
                pnextFormatData->pImage->Release();
                ++pnextFormatData;
            }
        }
    }
}

// Rewinds to a saved position; the formats written after it are released first.
// @0x142669e50
void LineBuffer::GlyphInserter::ResetTo(const GlyphInserter& savedPos)
{
    if (savedPos.GlyphIndex < GlyphIndex && GlyphsCount > 0)
    {
        GlyphEntry*      pglyphs = savedPos.pGlyphs + savedPos.GlyphIndex;
        unsigned         n       = GlyphIndex - savedPos.GlyphIndex;
        FormatDataEntry* pfmt    = savedPos.pNextFormatData + savedPos.FormatDataIndex;
        ReleasePartOfLine(pglyphs, n, pfmt);
    }
    operator=(savedPos);
}

// ---------------------------------------------------------------------------------------------------------------
// GlyphIterator

// The highlighter advances by characters, so it moves once a glyph that carries characters is reached.
// @0x142667fc0
void LineBuffer::GlyphIterator::operator++()
{
    if (!IsFinished())
    {
        if (Delta == 0)
            Delta = pGlyphs->GetLength();
        ++pGlyphs;
        if (pGlyphs->GetLength() > 0 && Delta > 0 && !HighlighterIter.IsFinished())
        {
            HighlighterIter += Delta;
            Delta = 0;
        }
        UpdateDesc();
    }
}

// @0x14266a320
void LineBuffer::GlyphIterator::UpdateDesc()
{
    pImage = NULL;
    if (IsFinished())
        return;

    if (pGlyphs->IsNextFormat())
    {
        if (pGlyphs->HasFmtFont())
        {
            pFontHandle = pNextFormatData->pFont;
            ++pNextFormatData;
        }
        if (pGlyphs->HasFmtColor())
        {
            OrigColor = ColorV = pNextFormatData->ColorV;
            ++pNextFormatData;
        }
        if (pGlyphs->HasFmtImage())
        {
            pImage = pNextFormatData->pImage;
            ++pNextFormatData;
        }
    }
    if (pGlyphs->IsUnderline())
    {
        UnderlineStyle = HighlightInfo::Underline_Single;
        UnderlineColor = ColorV;
    }
    else
        UnderlineStyle = HighlightInfo::Underline_None;

    if (!HighlighterIter.IsFinished())
    {
        // the highlight in effect overrides the glyph's own colours
        const HighlightDesc& hd = *HighlighterIter;
        ColorV = OrigColor;
        if (pGlyphs->GetLength() > 0 || pGlyphs->IsWordWrapSeparator())
        {
            if (hd.Info.HasTextColor())
                ColorV = hd.Info.GetTextColor().ToColor32();
            if (hd.Info.HasUnderlineStyle())
                UnderlineStyle = hd.Info.GetUnderlineStyle();
            if (hd.Info.HasUnderlineColor())
                UnderlineColor = hd.Info.GetUnderlineColor().ToColor32();
            else
                UnderlineColor = ColorV;
            if (hd.Info.HasBackgroundColor())
                SelectionColor = hd.Info.GetBackgroundColor().ToColor32();
            else
                SelectionColor = 0;
        }
    }
    else
    {
        SelectionColor = 0;
        if (pGlyphs->IsUnderline())
        {
            UnderlineColor = ColorV;
            UnderlineStyle = HighlightInfo::Underline_Single;
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Line

// The format data follows the glyphs at the next pointer boundary.
// @0x1426693d0
LineBuffer::FormatDataEntry* LineBuffer::Line::GetFormatData() const
{
    UByte* p  = reinterpret_cast<UByte*>(GetGlyphs() + GetNumGlyphs());
    UPInt  pi = (UPInt)p;
    UPInt  pad = ((pi + sizeof(FormatDataEntry*) - 1) & ~(sizeof(FormatDataEntry*) - 1)) - pi;
    return reinterpret_cast<FormatDataEntry*>(p + pad);
}

// @0x142669ae0
void LineBuffer::Line::Release()
{
    if (!IsInitialized())
        return;
    GlyphEntry*      pglyphs = GetGlyphs();
    unsigned         n       = GetNumGlyphs();
    FormatDataEntry* pfmt    = GetFormatData();
    ReleasePartOfLine(pglyphs, n, pfmt);
    SetNumGlyphs(0);
}

// A trailing new-line glyph counts, the end-of-text marker does not.
// @0x142669540
bool LineBuffer::Line::HasNewLine() const
{
    unsigned n = GetNumGlyphs();
    if (n > 0)
    {
        GlyphEntry* pglyphs = GetGlyphs();
        return pglyphs[n - 1].IsNewLineChar() && !pglyphs[n - 1].IsEOFChar();
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// LineBuffer

// @0x142667f60
LineBuffer::LineBuffer()
{
    Geom.VisibleRect.Clear();
    LastHScrollOffset = ~0u;
}

// @0x142667f90
LineBuffer::~LineBuffer()
{
    ClearLines();
}

// @0x142669450
const LineBuffer::Line* LineBuffer::GetLine(unsigned lineIdx) const
{
    if (lineIdx >= Lines.GetSize())
        return NULL;
    return Lines[lineIdx];
}

// Header, glyphs, padding to a pointer boundary, then the format entries.
// @0x1426680c0
unsigned LineBuffer::CalcLineSize(unsigned glyphCount, unsigned formatDataElementsCount, LineBuffer::LineType lineType)
{
    unsigned sz;
    if (lineType == Line8)
        sz = LineData8::GetLineStructSize();
    else
        sz = LineData32::GetLineStructSize();
    sz += sizeof(UInt32);
    sz += sizeof(GlyphEntry) * glyphCount;
    sz = (sz + sizeof(FormatDataEntry) - 1) & ~(sizeof(FormatDataEntry) - 1);
    sz += sizeof(FormatDataEntry) * formatDataElementsCount;
    return sz;
}

// @0x1426695a0
LineBuffer::Line* LineBuffer::InsertNewLine(unsigned lineIdx, unsigned glyphCount, unsigned formatDataElementsCount,
                                            LineBuffer::LineType lineType)
{
    unsigned sz    = CalcLineSize(glyphCount, formatDataElementsCount, lineType);
    Line*    pline = LineAllocator.AllocLine(sz, lineType);
    if (!pline)
        return NULL;
    pline->SetNumGlyphs(glyphCount);
    Lines.InsertAt(lineIdx, pline);
    return pline;
}

// @0x142669c10
void LineBuffer::RemoveLines(unsigned lineIdx, unsigned num)
{
    Iterator it = Begin() + lineIdx;
    for (unsigned i = 0; i < num && !it.IsFinished(); ++it, ++i)
        LineAllocator.FreeLine(it.GetPtr());
    Lines.RemoveMultipleAt(lineIdx, num);
}

// How far the first visible line is below the first line.
// @0x142669500
unsigned LineBuffer::GetVScrollOffsetInFixp() const
{
    int yOffset = 0;
    if (Geom.FirstVisibleLinePos != 0)
    {
        ConstIterator visIt   = BeginVisible(0);
        ConstIterator linesIt = Begin();
        if (!visIt.IsFinished() && !linesIt.IsFinished())
            yOffset = visIt->GetOffsetY() - linesIt->GetOffsetY();
    }
    return unsigned(yOffset);
}

// @0x14266a300
void LineBuffer::SetFirstVisibleLine(unsigned line)
{
    Geom.FirstVisibleLinePos = line;
    InvalidateCache();
}

// (the exe folds this with an AS3 setter of the same code)
// @0x14266a310
void LineBuffer::SetHScrollOffset(unsigned offset)
{
    Geom.HScrollOffset = offset;
}

// @0x142669170
LineBuffer::Iterator LineBuffer::FindLineByTextPos(UPInt textPos)
{
    if (Lines.GetSize() > 0)
    {
        UPInt i = Alg::LowerBound(Lines, (unsigned)textPos, LineIndexComparator::Less);
        if (i == Lines.GetSize())
            --i;
        Line*    pline = Lines[(unsigned)i];
        unsigned start = pline->GetTextPos();
        if (textPos >= start && textPos <= start + pline->GetTextLength())
            return Iterator(*this, (unsigned)i);
    }
    return Iterator();
}

// @0x142669010
LineBuffer::Iterator LineBuffer::FindLineAtYOffset(float yoff)
{
    if (Lines.GetSize() > 0)
    {
        UPInt i = Alg::LowerBound(Lines, yoff, LineYOffsetComparator::Less);
        if (i == Lines.GetSize())
            --i;
        Line* pline = Lines[(unsigned)i];
        if (yoff >= pline->GetOffsetY() && yoff < pline->GetOffsetY() + pline->GetHeight() + pline->GetLeading())
            return Iterator(*this, (unsigned)i);
    }
    return Iterator();
}

// Lines on the same row share the y offset; the row is scanned for the one under the point.
// @0x142668e40
LineBuffer::Iterator LineBuffer::FindLineAtOffset(const PointF& p)
{
    if (Lines.GetSize() > 0)
    {
        UPInt i = Alg::LowerBound(Lines, p.y, LineYOffsetComparator::Less);
        if (i == Lines.GetSize())
            --i;
        Line* pline = Lines[(unsigned)i];
        int   rowY  = pline->GetOffsetY();
        while (pline)
        {
            if (p.y >= pline->GetOffsetY() && p.y < pline->GetOffsetY() + pline->GetHeight() + pline->GetLeading())
            {
                if (p.x >= pline->GetOffsetX() && p.x < pline->GetOffsetX() + pline->GetWidth())
                    return Iterator(*this, (unsigned)i);
                if (++i == Lines.GetSize())
                    break;
                pline = Lines[(unsigned)i];
                if (pline->GetOffsetY() != rowY)
                    break;
            }
            else
                break;
        }
    }
    return Iterator();
}

// The first visible line shows even when cut at the bottom; the others only when they fit entirely.
// @0x1426696b0
bool LineBuffer::IsLineVisible(unsigned lineIndex, float yOffset) const
{
    const Line& line = *Lines[lineIndex];
    if (lineIndex == Geom.FirstVisibleLinePos)
        return line.GetOffsetY() + yOffset <= Geom.VisibleRect.Height() + GFX_TEXT_GUTTER / 2;
    return lineIndex > Geom.FirstVisibleLinePos &&
           line.GetOffsetY() + line.GetHeight() + yOffset <= Geom.VisibleRect.Height() + GFX_TEXT_GUTTER / 2;
}

// The first visible line starts inside the view but runs past its bottom.
bool LineBuffer::IsPartiallyVisible(float yOffset) const
{
    if (Geom.FirstVisibleLinePos < GetSize())
    {
        const Line& line = *Lines[Geom.FirstVisibleLinePos];
        if (line.GetWidth() != 0 && line.GetHeight() != 0)
        {
            float lh     = (float)line.GetHeight();
            float bottom = Geom.VisibleRect.Height() + GFX_TEXT_GUTTER / 2;
            float top    = (float)line.GetOffsetY() + yOffset;
            if (top <= bottom && top + lh > bottom)
                return true;
        }
    }
    return false;
}

// Scales every line and glyph metric (used on 32-bit lines).
// @0x142669f40
void LineBuffer::Scale(float scaleFactor)
{
    Iterator it = Begin();
    for (; !it.IsFinished(); ++it)
    {
        Line& line = *it;

        float leading = float(line.GetLeading()) * scaleFactor;
        float w       = float(line.GetWidth()) * scaleFactor;
        float h       = float(line.GetHeight()) * scaleFactor;
        line.SetLeading(int(leading));
        line.SetDimensions(int(w), int(h));
        line.SetBaseLineOffset(line.GetBaseLineOffset() * scaleFactor);
        line.SetOffsetX(int(float(line.GetOffsetX()) * scaleFactor));
        line.SetOffsetY(int(float(line.GetOffsetY()) * scaleFactor));

        GlyphIterator git = line.Begin();
        for (; !git.IsFinished(); ++git)
        {
            GlyphEntry& ge = git.GetGlyph();
            ge.SetAdvance(int(float(ge.GetAdvance()) * scaleFactor));
            ge.SetFontSize(ge.GetFontSize() * scaleFactor);
        }
    }
    InvalidateCache();
}

// @0x142669470
int LineBuffer::GetMinLineHeight() const
{
    if (GetSize() == 0)
        return 0;
    int minH = SF_MAX_SINT;
    for (ConstIterator it = Begin(); !it.IsFinished(); ++it)
    {
        int h = (*it).GetHeight();
        if (h < minH)
            minH = h;
    }
    return minH;
}

// Moves the rectangle's origin and any size past 16 bits into the matrix.
// @0x142669940
void RecalculateRectToFit16Bit(Matrix2F& matrix, const RectF& srcRect, RectF* pdestRect)
{
    matrix.PrependTranslation(srcRect.x1, srcRect.y1);

    float xscale = 1, width = srcRect.Width();
    if (width > 32767)
    {
        xscale = width / 32767;
        width  = 32767;
    }
    float yscale = 1, height = srcRect.Height();
    if (height > 32767)
    {
        yscale = height / 32767;
        height = 32767;
    }
    matrix.PrependScaling(xscale, yscale);
    pdestRect->y1 = pdestRect->x1 = 0;
    pdestRect->SetWidth(width);
    pdestRect->SetHeight(height);
}

static TextUnderlineStyle ConvertUnderlineStyle(HighlightInfo::UnderlineStyle st)
{
    switch (st)
    {
    case HighlightInfo::Underline_Single:         return TextUnderline_Single;
    case HighlightInfo::Underline_Thick:          return TextUnderline_Thick;
    case HighlightInfo::Underline_Dotted:         return TextUnderline_Dotted;
    case HighlightInfo::Underline_DottedThick:    return TextUnderline_DottedThick;
    case HighlightInfo::Underline_DitheredSingle: return TextUnderline_Dithered;
    case HighlightInfo::Underline_DitheredThick:  return TextUnderline_DitheredThick;
    default:;
    }
    return TextUnderline_Single;
}

// Emits the records of every visible line: a new-line record at the first glyph drawn, colour / font switches,
// images, and the underline and selection runs merged across glyphs of the same colour and style. Glyphs left
// of the view are skipped and the line ends at the right edge; a clip box is set once something is cut.
// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1426680e0
void LineBuffer::CreateVisibleTextLayout(TextLayout::Builder& bld, const Highlighter* phighlighter,
                                         const TextFieldParam& textFieldParam)
{
    float yOffset = -float(GetVScrollOffsetInFixp());

    Iterator linesIt = BeginVisible(yOffset);
    RectF    glyphBounds;
    bool     hasUnderline = false;
    if (phighlighter)
        hasUnderline = phighlighter->HasUnderlineHighlight();
    Color prevColor(0u);
    Font* prevFont     = NULL;
    float prevFontSize = 0;
    bool  maskApplied;

    if (!IsStaticText() && !Geom.IsNoClipping() && IsPartiallyVisible(yOffset))
    {
        bld.SetClipBox(Geom.VisibleRect);
        maskApplied = true;
    }
    else
        maskApplied = false;

    for (; linesIt.IsVisible(); ++linesIt)
    {
        Line&  line = *linesIt;
        PointF offset;
        offset.x = (float)line.GetOffsetX();
        offset.y = (float)line.GetOffsetY();
        offset += Geom.VisibleRect.TopLeft();
        offset.y += yOffset + line.GetBaseLineOffset();
        GlyphIterator glyphIt      = line.Begin(phighlighter);
        bool          firstVisible = true;

        Color prevSelectionColor(0u);
        RectF selectionRect(0, 0, 0, 0);

        HighlightInfo::UnderlineStyle prevUnderlineStyle = HighlightInfo::Underline_None;
        Color                         prevUnderlineColor(0u);

        int    underlineLen = 0;
        PointF underlineBeginPt(0, 0);
        float  descent = float(line.GetHeight() - line.GetBaseLineOffset());

        for (int advance = 0; !glyphIt.IsFinished(); ++glyphIt, offset.x += advance)
        {
            const GlyphEntry& glyph = glyphIt.GetGlyph();
            advance = glyph.GetAdvance();

            float      scale          = 1.0f;
            float      approxSymW     = 0;
            unsigned   index          = glyph.GetIndex();
            ImageDesc* pimage         = NULL;
            Font*      pfont          = NULL;
            float      fontSize       = -1;
            Color      selectionColor = glyphIt.GetSelectionColor();

            if (glyphIt.HasImage())
            {
                pimage     = glyphIt.GetImage();
                approxSymW = pimage->GetScreenWidth();
            }
            else
            {
                fontSize = (float)PixelsToFixp(glyph.GetFontSize());
                scale    = fontSize / 1024.0f;   // glyph coordinates are in a 1024 em square
                pfont    = glyphIt.GetFont();
                // static text needs neither the clip test nor the (costly) glyph bounds
                if (!IsStaticText())
                    approxSymW = pfont->GetGlyphBounds(index, &glyphBounds).x2 * scale;
                else
                    approxSymW = 0;
            }
            float adjox = offset.x - Geom.HScrollOffset;

            if (!IsStaticText())
            {
                // wholly left of the view: skip; at or past the right edge: the rest of the line is hidden too
                if (index != ~0u && adjox + approxSymW <= Geom.VisibleRect.x1)
                    continue;
                if (int(adjox) >= int(Geom.VisibleRect.x2))
                    break;
            }
            if (glyphIt.IsUnderline())
            {
                if (!glyph.IsNewLineChar())
                    hasUnderline = true;
            }
            else
                hasUnderline = false;

            if (firstVisible)
            {
                bld.SetNewLine(adjox, offset.y);
                firstVisible = false;
            }

            // a glyph across either side of the view needs the clip box
            if (!maskApplied && !IsStaticText() && !Geom.IsNoClipping() &&
                ((adjox < Geom.VisibleRect.x1 && adjox + approxSymW > Geom.VisibleRect.x1) ||
                 (adjox < Geom.VisibleRect.x2 && adjox + approxSymW > Geom.VisibleRect.x2)))
            {
                bld.SetClipBox(Geom.VisibleRect);
                maskApplied = true;
            }

            if (pimage)
            {
                if (pimage->pImage)
                {
                    float yscale = pimage->GetYScale();
                    bld.AddImage(pimage->pImage, pimage->GetXScale(), yscale, pimage->BaseLineY, float(advance));
                }
                else
                    LogDebugMessage(Log_Warning, "An image in TextLayout is NULL");
                continue;
            }

            Color color(glyphIt.GetColor());
            if (color != prevColor)
                bld.ChangeColor(color.ToColor32());
            if (pfont != prevFont || fontSize != prevFontSize)
            {
                bld.ChangeFont(pfont, fontSize);
                // the layout holds the font handle: it may own the font's container
                FontHandle* fh = glyphIt.GetFontHandle();
                bld.AddRefCntData(fh);
            }

            // underline runs: a change of colour or style closes the previous run
            if (prevUnderlineColor != glyphIt.GetUnderlineColor() || prevUnderlineStyle != glyphIt.GetUnderlineStyle())
            {
                if (prevUnderlineColor != 0)
                {
                    bld.AddUnderline(underlineBeginPt.x - float(Geom.HScrollOffset), underlineBeginPt.y + descent / 2,
                                     float(underlineLen), ConvertUnderlineStyle(prevUnderlineStyle),
                                     prevUnderlineColor.ToColor32());
                }
                underlineBeginPt = offset;
                underlineLen     = advance;
            }
            else if (glyphIt.GetUnderlineColor() != 0)
                underlineLen += advance;

            // selection runs: grow the rectangle while the colour stays, emit it when it changes
            if (glyphIt.IsSelected() || prevSelectionColor != 0)
            {
                PointF rectOff(offset.x, offset.y - line.GetBaseLineOffset());
                RectF  glyphRect(0, 0, float(advance), float(line.GetHeight() + line.GetNonNegLeading()));
                glyphRect += rectOff;
                if (selectionColor != prevSelectionColor)
                {
                    if (prevSelectionColor != 0)
                    {
                        RectF sr(selectionRect);
                        sr -= PointF(float(Geom.HScrollOffset), 0);
                        bld.AddSelection(sr, prevSelectionColor.ToColor32());
                    }
                    selectionRect = glyphRect;
                }
                else if (selectionColor != 0)
                    selectionRect.Union(glyphRect);
            }

            bld.AddChar(index, float(advance), glyph.IsCharInvisible(), glyphIt.IsFauxBold(), glyphIt.IsFauxItalic());
            prevColor          = color;
            prevFont           = pfont;
            prevFontSize       = fontSize;
            prevSelectionColor = selectionColor;
            if (hasUnderline)
            {
                prevUnderlineColor = glyphIt.GetUnderlineColor();
                prevUnderlineStyle = glyphIt.GetUnderlineStyle();
            }
            else
            {
                prevUnderlineColor = Color(0u);
                prevUnderlineStyle = HighlightInfo::Underline_None;
            }
        }
        if (prevUnderlineColor != 0)
        {
            bld.AddUnderline(underlineBeginPt.x - float(Geom.HScrollOffset), underlineBeginPt.y + descent / 2,
                             float(underlineLen), ConvertUnderlineStyle(prevUnderlineStyle),
                             prevUnderlineColor.ToColor32());
        }
        if (prevSelectionColor != 0)
        {
            selectionRect -= PointF(float(Geom.HScrollOffset), 0);
            bld.AddSelection(selectionRect, prevSelectionColor.ToColor32());
        }
    }
    bld.SetParam(textFieldParam);
}

// @0x142669880
void LoadTextFieldParamFromTextFilter(TextFieldParam& params, const TextFilter& filter)
{
    params.TextParam.SetBlurX(filter.BlurX);
    params.TextParam.SetBlurY(filter.BlurY);
    params.TextParam.Flags = GlyphParam::FineBlur;
    params.TextParam.SetBlurStrength(filter.BlurStrength);

    if ((filter.ShadowFlags & TextFieldParam::ShadowDisabled) == 0)
    {
        params.ShadowParam.Flags = UInt16(filter.ShadowFlags & ~TextFieldParam::ShadowDisabled);
        params.ShadowParam.SetBlurX(filter.ShadowParams.BlurX);
        params.ShadowParam.SetBlurY(filter.ShadowParams.BlurX);   // (sic: the shadow is blurred square)
        params.ShadowParam.SetBlurStrength(filter.ShadowParams.Strength);
        params.ShadowColor   = filter.ShadowParams.Colors[0].ToColor32();
        params.ShadowOffsetX = filter.ShadowParams.Offset.x;
        params.ShadowOffsetY = filter.ShadowParams.Offset.y;
    }
}

}}} // namespace Scaleform::Render::Text
