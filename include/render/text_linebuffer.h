// Recovered Scaleform 4.1.18 Render Text: LineBuffer, the formatted lines of a text view. Each Line is one heap
// block: a header (the 8- or 32-bit LineData variant), its glyph entries and then the format data the glyphs
// switch to (fonts, colours, images). Geometry is in twips. LineBuffer 0x60 bytes (Geom 16-byte aligned at +0x20).
// Bodies: Text_LineBuffer (unit sfr_render_04): ctor 0x142667f60, dtor 0x142667f90, RemoveLines 0x142669c10.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_LINEBUFFER_H
#define MS2_SF_RENDER_TEXT_LINEBUFFER_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_textlayout.h"
#include "ms2/scaleform/include/render/text_core.h"
#include "ms2/scaleform/include/render/text_highlight.h"
#include "ms2/scaleform/include/render/text_filterdesc.h"

namespace Scaleform { namespace Render { namespace Text {

using Render::TextLayout;
using Render::TextFieldParam;

#define GFX_TEXT_GUTTER Render::Text::PixelsToFixp(2.f)

// Scroll state and the visible rectangle of the buffer (0x30 bytes, 16-byte aligned).
struct __declspec(align(16)) LineBufferGeometry
{
    LineBufferGeometry() : FirstVisibleLinePos(0), VisibleRect(0, 0, 0, 0), HScrollOffset(0), Flags(0) {}

    unsigned                       FirstVisibleLinePos;   // +0x00
    __declspec(align(16)) RectF    VisibleRect;           // +0x10
    unsigned                       HScrollOffset;         // +0x20
    enum
    {
        Flag_InvalidCache      = 0x01,
        Flag_BatchHasUnderline = 0x02,
        Flag_StaticText        = 0x04,
        Flag_Readability       = 0x08,
        Flag_CheckPreciseScale = 0x10,
        Flag_NoClipping        = 0x20
    };
    UInt8                          Flags;                 // +0x24

    void InvalidateCache()         { Flags |= Flag_InvalidCache; }
    void ValidateCache()           { Flags &= ~Flag_InvalidCache; }
    bool IsCacheInvalid() const    { return (Flags & Flag_InvalidCache) != 0; }
    void SetStaticText()           { Flags |= Flag_StaticText; }
    bool IsStaticText() const      { return (Flags & Flag_StaticText) != 0; }
    bool HasBatchUnderline() const { return (Flags & Flag_BatchHasUnderline) != 0; }
};

class LineBuffer
{
public:
    enum LineType
    {
        Line8,
        Line32
    };

    // One glyph (8 bytes): its index, the advance (sign kept in the flags) and how many characters it stands for.
    class GlyphEntry
    {
    protected:
        UInt16 Index;
        UInt16 Advance;
        UInt16 LenAndFontSize;  // length in the top 4 bits, font size in the low 12
        enum
        {
            Mask_Length    = 0xF,
            Shift_Length   = 12,
            Mask_FontSize  = 0xFFF,
            Shift_FontSize = 0,

            Flags_NextFormat         = 0x4000,
            Flags_FmtHasFont         = 0x2000,
            Flags_FmtHasColor        = 0x1000,
            Flags_FmtHasImage        = 0x0800,
            Flags_Underline          = 0x0400,
            Flags_InvisibleChar      = 0x0200,
            Flags_NewLineChar        = 0x0100,
            Flags_Url                = 0x0080,
            Flags_NegAdvance         = 0x0040,
            Flags_FractionalFontSize = 0x0010,
            Flags_WordWrapSeparator  = 0x0008,
            Flags_ComposStrGlyph     = 0x0004,
            Flags_SpaceChar          = 0x0002
        };
        UInt16 Flags;

        bool IsNegAdvance() const { return (Flags & Flags_NegAdvance) != 0; }

    public:
        GlyphEntry() { Init(); }
        void Init() { LenAndFontSize = 0; Flags = 0; }

        unsigned GetIndex() const  { return (Index < 65535) ? Index : ~0u; }
        void     SetIndex(unsigned index) { Index = (UInt16)index; }
        unsigned GetLength() const { return (LenAndFontSize >> Shift_Length) & Mask_Length; }
        void SetLength(unsigned len)
        {
            LenAndFontSize = (UInt16)((LenAndFontSize & ~(Mask_Length << Shift_Length)) |
                                      ((len & Mask_Length) << Shift_Length));
        }
        float GetFontSize() const
        {
            unsigned fsz = (LenAndFontSize >> Shift_FontSize) & Mask_FontSize;
            if (!(Flags & Flags_FractionalFontSize))
                return float(fsz);
            return float(fsz) / 16.f;
        }
        int  GetAdvance() const { return !IsNegAdvance() ? Advance : -(int)Advance; }
        void SetAdvance(int v)
        {
            if (v >= 0)
            {
                Advance = (UInt16)v;
                Flags &= ~Flags_NegAdvance;
            }
            else
            {
                Advance = (UInt16)(-v);
                Flags |= Flags_NegAdvance;
            }
        }

        bool IsNextFormat() const        { return (Flags & Flags_NextFormat) != 0; }
        bool HasFmtFont() const          { return (Flags & Flags_FmtHasFont) != 0; }
        bool HasFmtColor() const         { return (Flags & Flags_FmtHasColor) != 0; }
        bool HasFmtImage() const         { return (Flags & Flags_FmtHasImage) != 0; }
        bool IsUnderline() const         { return (Flags & Flags_Underline) != 0; }
        bool IsCharInvisible() const     { return (Flags & Flags_InvisibleChar) != 0; }
        bool IsNewLineChar() const       { return (Flags & Flags_NewLineChar) != 0; }
        bool IsEOFChar() const           { return IsNewLineChar() && GetLength() == 0; }
        bool IsUrl() const               { return (Flags & Flags_Url) != 0; }
        bool IsWordWrapSeparator() const { return (Flags & Flags_WordWrapSeparator) != 0; }
        bool IsComposStrGlyph() const    { return (Flags & Flags_ComposStrGlyph) != 0; }
        bool IsSpaceChar() const         { return (Flags & Flags_SpaceChar) != 0; }
    };

    // what a glyph with the next-format flag switches to
    union FormatDataEntry
    {
        FontHandle* pFont;
        ImageDesc*  pImage;
        UInt32      ColorV;
    };

    // Walks the glyphs of a line with the font / colour / highlight in effect for each (0x98 bytes).
    class GlyphIterator
    {
        GlyphEntry*                   pGlyphs;            // +0x00
        GlyphEntry*                   pEndGlyphs;         // +0x08
        FormatDataEntry*              pNextFormatData;    // +0x10
        HighlighterPosIterator        HighlighterIter;    // +0x18
        UInt32                        ColorV, OrigColor, UnderlineColor, SelectionColor;   // +0x70
        Ptr<FontHandle>               pFontHandle;        // +0x80
        Ptr<ImageDesc>                pImage;             // +0x88
        HighlightInfo::UnderlineStyle UnderlineStyle;     // +0x90
        unsigned                      Delta;              // +0x94

        void UpdateDesc();

    public:
        GlyphIterator(void* pglyphs, unsigned glyphsCount, FormatDataEntry* pfmtData)
            : ColorV(0), OrigColor(0), UnderlineColor(0), SelectionColor(0),
              UnderlineStyle(HighlightInfo::Underline_None), Delta(0)
        {
            pGlyphs         = reinterpret_cast<GlyphEntry*>(pglyphs);
            pEndGlyphs      = pGlyphs + glyphsCount;
            pNextFormatData = pfmtData;
            UpdateDesc();
        }
        GlyphIterator(void* pglyphs, unsigned glyphsCount, FormatDataEntry* pfmtData,
                      const Highlighter& highlighter, UPInt lineStartPos)
            : ColorV(0), OrigColor(0), UnderlineColor(0), SelectionColor(0),
              UnderlineStyle(HighlightInfo::Underline_None), Delta(0)
        {
            HighlighterIter = highlighter.GetPosIterator(lineStartPos);
            pGlyphs         = reinterpret_cast<GlyphEntry*>(pglyphs);
            pEndGlyphs      = pGlyphs + glyphsCount;
            pNextFormatData = pfmtData;
            UpdateDesc();
        }

        bool        IsFinished() const    { return !pGlyphs || pGlyphs >= pEndGlyphs; }
        void        operator++();
        FontHandle* GetFontHandle() const { return pFontHandle; }
        Color       GetColor() const      { return Color(ColorV); }
        GlyphEntry& GetGlyph() const      { return *pGlyphs; }
        ImageDesc*  GetImage() const      { return pImage; }
        bool        HasImage() const      { return !!pImage; }
        bool        IsUnderline() const   { return UnderlineStyle != HighlightInfo::Underline_None; }
        HighlightInfo::UnderlineStyle GetUnderlineStyle() const { return UnderlineStyle; }
        Color       GetUnderlineColor() const { return Color(UnderlineColor); }
        bool        IsSelected() const    { return SelectionColor != 0; }
        Color       GetSelectionColor() const { return Color(SelectionColor); }
    };

    // Header of a line with 32-bit fields (0x26 bytes used).
    struct LineData32
    {
        UInt32 GlyphsCount;       // +0x00
        UInt32 TextPos;           // +0x04 first character
        SInt32 OffsetX, OffsetY;  // +0x08 top left, twips
        UInt32 Width, Height;     // +0x10
        UInt32 ParagraphId;       // +0x18
        UInt32 TextLength;        // +0x1c
        UInt16 ParagraphModId;    // +0x20
        UInt16 BaseLineOffset;    // +0x22 from the top to the baseline
        SInt16 Leading;           // +0x24

        static unsigned GetLineStructSize() { return 0x26; }
        GlyphEntry* GetGlyphs() const { return reinterpret_cast<GlyphEntry*>(((UByte*)this) + GetLineStructSize()); }
    };

    // Header of a short line: 24-bit text position and 8-bit length packed, 16-bit sizes (0x16 bytes used).
    struct LineData8
    {
        UInt32 ParagraphId;       // +0x00
        UInt32 TextPosAndLength;  // +0x04 position in the low 24 bits, length in the top 8
        SInt32 OffsetX, OffsetY;  // +0x08
        UInt16 Width, Height;     // +0x10
        UInt16 ParagraphModId;    // +0x14
        UInt16 BaseLineOffset;    // +0x16
        UInt8  GlyphsCount;       // +0x18
        SInt8  Leading;           // +0x19
        enum
        {
            Mask_TextPos     = 0xFFFFFFu,
            Shift_TextPos    = 0,
            Mask_TextLength  = 0xFF,
            Shift_TextLength = 24
        };

        static unsigned GetLineStructSize() { return 0x1a; }
        unsigned GetTextPos() const
        {
            unsigned v = (TextPosAndLength >> Shift_TextPos) & Mask_TextPos;
            return (v == Mask_TextPos) ? ~0u : v;
        }
        unsigned GetTextLength() const { return (TextPosAndLength >> Shift_TextLength) & Mask_TextLength; }
        GlyphEntry* GetGlyphs() const { return reinterpret_cast<GlyphEntry*>(((UByte*)this) + GetLineStructSize()); }
    };

    class Line
    {
        UInt32 MemSize;     // size in the low 28 bits, alignment in bits 28-29, flags on top
        enum
        {
            Flags_Data8       = 0x80000000u,
            Flags_Initialized = 0x40000000u,
            Mask_MemSize      = 0x0FFFFFFFu,
            Shift_MemSize     = 0,
            Mask_Alignment    = 0x3,
            Shift_Alignment   = 28
        };
        union
        {
            LineData32 Data32;
            LineData8  Data8;
        };

    public:
        enum Alignment
        {
            Align_Left   = 0,
            Align_Right  = 1,
            Align_Center = 2
        };

        bool IsData8() const  { return (MemSize & Flags_Data8) != 0; }
        bool IsData32() const { return !IsData8(); }
        Alignment GetAlignment() const { return (Alignment)((MemSize >> Shift_Alignment) & Mask_Alignment); }
        bool IsLeftAlignment() const   { return GetAlignment() == Align_Left; }

        unsigned GetTextPos() const    { return IsData8() ? Data8.GetTextPos() : Data32.TextPos; }
        void SetTextPos(unsigned tp)
        {
            if (IsData8())
                Data8.TextPosAndLength = (Data8.TextPosAndLength & ~(LineData8::Mask_TextPos << LineData8::Shift_TextPos)) |
                                         ((tp & LineData8::Mask_TextPos) << LineData8::Shift_TextPos);
            else
                Data32.TextPos = tp;
        }
        unsigned GetNumGlyphs() const  { return IsData8() ? Data8.GlyphsCount : Data32.GlyphsCount; }
        GlyphEntry* GetGlyphs() const  { return IsData8() ? Data8.GetGlyphs() : Data32.GetGlyphs(); }
        FormatDataEntry* GetFormatData() const;
        unsigned GetTextLength() const { return IsData8() ? Data8.GetTextLength() : Data32.TextLength; }
        float GetBaseLineOffset() const { return IsData8() ? float(Data8.BaseLineOffset) : float(Data32.BaseLineOffset); }
        float GetAscent() const        { return GetBaseLineOffset(); }
        float GetDescent() const       { return GetHeight() - GetBaseLineOffset(); }
        int   GetLeading() const       { return IsData8() ? int(Data8.Leading) : int(Data32.Leading); }
        int   GetNonNegLeading() const
        {
            return IsData8() ? (Data8.Leading > 0 ? int(Data8.Leading) : 0)
                             : (Data32.Leading > 0 ? int(Data32.Leading) : 0);
        }
        int  GetWidth() const   { return IsData8() ? int(Data8.Width) : int(Data32.Width); }
        int  GetHeight() const  { return IsData8() ? int(Data8.Height) : int(Data32.Height); }
        int  GetOffsetX() const { return IsData8() ? Data8.OffsetX : Data32.OffsetX; }
        int  GetOffsetY() const { return IsData8() ? Data8.OffsetY : Data32.OffsetY; }
        unsigned GetParagraphId() const    { return IsData8() ? Data8.ParagraphId : Data32.ParagraphId; }
        UInt16   GetParagraphModId() const { return IsData8() ? Data8.ParagraphModId : Data32.ParagraphModId; }

        GlyphIterator Begin() const { return GlyphIterator(GetGlyphs(), GetNumGlyphs(), GetFormatData()); }
        GlyphIterator Begin(const Highlighter* phighlighter) const
        {
            if (phighlighter)
                return GlyphIterator(GetGlyphs(), GetNumGlyphs(), GetFormatData(), *phighlighter, GetTextPos());
            return Begin();
        }
        bool HasNewLine() const;
    };

    class ConstIterator;

    // Position in the line list (0x20 bytes); YOffset only matters for the visibility test.
    class Iterator
    {
        friend class LineBuffer;

        LineBuffer*        pLineBuffer;   // +0x00
        const Highlighter* pHighlight;    // +0x08
        unsigned           CurrentPos;    // +0x10
        float              YOffset;       // +0x14
        bool               StaticText;    // +0x18

        Iterator(LineBuffer& lb)
            : pLineBuffer(&lb), pHighlight(NULL), CurrentPos(0), YOffset(0), StaticText(lb.IsStaticText()) {}
        Iterator(LineBuffer& lb, unsigned pos, float yoffset = 0)
            : pLineBuffer(&lb), pHighlight(NULL), CurrentPos(pos), YOffset(yoffset), StaticText(lb.IsStaticText()) {}

    public:
        Iterator() : pLineBuffer(NULL), pHighlight(NULL), CurrentPos(0), YOffset(0), StaticText(false) {}
        Iterator(const Iterator& it)
            : pLineBuffer(it.pLineBuffer), pHighlight(it.pHighlight), CurrentPos(it.CurrentPos), YOffset(it.YOffset),
              StaticText(it.StaticText) {}

        bool IsFinished() const
        {
            return !pLineBuffer || CurrentPos >= pLineBuffer->Lines.GetSize() || (int)CurrentPos < 0;
        }
        // inside the buffer and on screen at the iterator's y offset (static text shows every line)
        bool IsVisible() const
        {
            if (!IsFinished())
            {
                if (StaticText)
                    return true;
                return pLineBuffer->IsLineVisible(CurrentPos, YOffset);
            }
            return false;
        }
        Iterator& operator++()
        {
            if (CurrentPos < pLineBuffer->Lines.GetSize())
                ++CurrentPos;
            return *this;
        }
        Iterator& operator--()
        {
            if ((int)CurrentPos >= 0)
                --CurrentPos;
            return *this;
        }
        Iterator operator+(unsigned delta) const { return Iterator(*pLineBuffer, CurrentPos + delta, YOffset); }
        Iterator operator-(unsigned delta) const { return Iterator(*pLineBuffer, CurrentPos - delta, YOffset); }
        Line& operator*() const  { return (*pLineBuffer)[CurrentPos]; }
        Line* operator->() const { return &(*pLineBuffer)[CurrentPos]; }
        Line* GetPtr() const     { return &(*pLineBuffer)[CurrentPos]; }
        unsigned GetIndex() const { return ((int)CurrentPos >= 0) ? unsigned(CurrentPos) : ~0u; }
        void SetHighlighter(const Highlighter* ph) { pHighlight = ph; }
        const Highlighter* GetHighlighter() const  { return pHighlight; }
    };

    LineBuffer();
    ~LineBuffer();

    void CreateVisibleTextLayout(TextLayout::Builder& bld, const Highlighter* phighlighter,
                                 const TextFieldParam& textFieldParam);

    Line&       operator[](unsigned pos)       { return *Lines[pos]; }
    const Line& operator[](unsigned pos) const { return *Lines[pos]; }
    unsigned    GetSize() const                { return (unsigned)Lines.GetSize(); }

    void ResetCache();
    void ClearLines()
    {
        InvalidateCache();
        RemoveLines(0, (unsigned)Lines.GetSize());
    }

    Iterator Begin()                     { return Iterator(*this); }
    Iterator BeginVisible(float yoffset) { return Iterator(*this, Geom.FirstVisibleLinePos, yoffset); }
    Iterator Last()                      { return Iterator(*this, (unsigned)Lines.GetSize() - 1); }
    Iterator FindLineByTextPos(UPInt textPos);
    Iterator FindLineAtYOffset(float yoff);
    Iterator FindLineAtOffset(const PointF& p);

    void  SetVisibleRect(const RectF& bnd) { Geom.VisibleRect = bnd; }
    Line* GetLine(unsigned lineIdx);
    Line* InsertNewLine(unsigned lineIdx, unsigned glyphCount, unsigned formatDataElementsCount, LineType lineType);
    void  RemoveLines(unsigned lineIdx, unsigned num);
    static unsigned CalcLineSize(unsigned glyphCount, unsigned formatDataElementsCount, LineType lineType);

    void     SetFirstVisibleLine(unsigned line);
    unsigned GetFirstVisibleLineIndex() const { return Geom.FirstVisibleLinePos; }
    unsigned GetVScrollOffsetInFixp() const;
    void     SetHScrollOffset(unsigned offset);
    unsigned GetHScrollOffset() const { return Geom.HScrollOffset; }

    void InvalidateCache()      { Geom.InvalidateCache(); }
    void ValidateCache()        { Geom.ValidateCache(); }
    bool IsCacheInvalid() const { return Geom.IsCacheInvalid(); }
    void SetStaticText()        { Geom.SetStaticText(); }
    bool IsStaticText() const   { return Geom.IsStaticText(); }

    bool IsLineVisible(unsigned lineIndex) const
    {
        float yOffset = -float(GetVScrollOffsetInFixp());
        return IsLineVisible(lineIndex, yOffset);
    }
    bool IsLineVisible(unsigned lineIndex, float yOffset) const;
    bool IsPartiallyVisible(float yOffset) const;
    void Scale(float scaleFactor);
    int  GetMinLineHeight() const;

public:
    ArrayLH<Line*>     Lines;               // +0x00
    LineBufferGeometry Geom;                // +0x20
    class TextLineAllocator
    {
    public:
        Line* AllocLine(unsigned size, LineBuffer::LineType lineType);
        void  FreeLine(Line* ptr);
    } LineAllocator;                        // +0x50
    unsigned           LastHScrollOffset;   // +0x54
};

void LoadTextFieldParamFromTextFilter(TextFieldParam& params, const TextFilter& filter);

}}} // namespace Scaleform::Render::Text

#endif
