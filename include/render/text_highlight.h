// Recovered Scaleform 4.1.18 Render Text: highlighting of text ranges (selection, IME composition, underlines).
// A Highlighter keeps a list of HighlightDesc (a text range, its glyph range and the colours/underline to apply);
// the position iterator walks the merged result glyph by glyph. Bodies: Text_Highlight (unit sfr_render_04).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_HIGHLIGHT_H
#define MS2_SF_RENDER_TEXT_HIGHLIGHT_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_stats.h"

namespace Scaleform { namespace Render { namespace Text {

class Highlighter;
class CompositionStringBase;

// highlight ids at the top of the range are reserved for the editor
#define GFX_TOPMOST_HIGHLIGHTING_INDEX    INT_MAX
#define GFX_WIDECURSOR_HIGHLIGHTING_INDEX (GFX_TOPMOST_HIGHLIGHTING_INDEX - 1)
#define GFX_COMPOSSTR_HIGHLIGHTING_INDEX  (GFX_TOPMOST_HIGHLIGHTING_INDEX - 7)

// What a highlight does to its characters: each colour only applies when its flag is set (0x10 bytes).
struct HighlightInfo : public NewOverrideBase<StatRender_Text_Mem>
{
    enum UnderlineStyle
    {
        Underline_None           = 0,
        Underline_Single         = 1,
        Underline_Thick          = 2,
        Underline_Dotted         = 3,
        Underline_DottedThick    = 4,
        Underline_DitheredSingle = 5,
        Underline_DitheredThick  = 6
    };
    enum
    {
        Flag_UnderlineStyle = 0x7,   // the low bits hold the style
        Flag_Background     = 0x8,
        Flag_TextColor      = 0x10,
        Flag_UnderlineColor = 0x20
    };

    Color BackgroundColor;
    Color TextColor;
    Color UnderlineColor;
    UByte Flags;

    HighlightInfo() { Reset(); }
    HighlightInfo(UnderlineStyle st) { Reset(); SetUnderlineStyle(st); }

    void Reset() { BackgroundColor = TextColor = UnderlineColor = 0; Flags = 0; }
    void Append(const HighlightInfo& mergee);
    void Prepend(const HighlightInfo& mergee);
    bool IsEqualWithFlags(const HighlightInfo& right, unsigned flags);

    UnderlineStyle GetUnderlineStyle() const { return UnderlineStyle(Flags & Flag_UnderlineStyle); }
    bool HasUnderlineStyle() const           { return GetUnderlineStyle() != 0; }
    void ClearUnderlineStyle()               { Flags &= ~Flag_UnderlineStyle; }
    void SetUnderlineStyle(UnderlineStyle us) { ClearUnderlineStyle(); Flags |= (us & Flag_UnderlineStyle); }
    void SetSingleUnderline()                { SetUnderlineStyle(Underline_Single); }
    void SetThickUnderline()                 { SetUnderlineStyle(Underline_Thick); }
    void SetDottedUnderline()                { SetUnderlineStyle(Underline_Dotted); }
    void SetDottedThickUnderline()           { SetUnderlineStyle(Underline_DottedThick); }
    void SetDitheredSingleUnderline()        { SetUnderlineStyle(Underline_DitheredSingle); }
    void SetDitheredThickUnderline()         { SetUnderlineStyle(Underline_DitheredThick); }

    void  SetBackgroundColor(const Color& c) { Flags |= Flag_Background; BackgroundColor = c; }
    bool  HasBackgroundColor() const         { return (Flags & Flag_Background) != 0; }
    void  ClearBackgroundColor()             { Flags &= ~Flag_Background; }
    Color GetBackgroundColor() const         { return HasBackgroundColor() ? BackgroundColor : Color(0, 0, 0, 0); }

    void  SetTextColor(const Color& c)       { Flags |= Flag_TextColor; TextColor = c; }
    bool  HasTextColor() const               { return (Flags & Flag_TextColor) != 0; }
    void  ClearTextColor()                   { Flags &= ~Flag_TextColor; }
    Color GetTextColor() const               { return HasTextColor() ? TextColor : Color(0, 0, 0, 0); }

    void  SetUnderlineColor(const Color& c)  { Flags |= Flag_UnderlineColor; UnderlineColor = c; }
    bool  HasUnderlineColor() const          { return (Flags & Flag_UnderlineColor) != 0; }
    void  ClearUnderlineColor()              { Flags &= ~Flag_UnderlineColor; }
    Color GetUnderlineColor() const          { return HasUnderlineColor() ? UnderlineColor : Color(0, 0, 0, 0); }
};

// One highlighted range (0x40 bytes).
struct HighlightDesc
{
    UPInt         StartPos;      // +0x00 text position
    UPInt         Length;        // +0x08 in characters
    SPInt         Offset;        // +0x10 glyph offset from StartPos
    UPInt         AdjStartPos;   // +0x18 StartPos moved by the composition string
    UPInt         GlyphNum;      // +0x20 glyphs covered
    unsigned      Id;            // +0x28
    HighlightInfo Info;          // +0x2c

    HighlightDesc() : StartPos(SF_MAX_UPINT), Length(0), Offset(-1), AdjStartPos(0), GlyphNum(0), Id(0) {}
    HighlightDesc(SPInt startPos, UPInt len)
        : StartPos(startPos), Length(len), Offset(-1), AdjStartPos(0), GlyphNum(0), Id(0) {}

    bool ContainsPos(UPInt pos) const     { return Length > 0 && pos >= StartPos && pos < StartPos + Length; }
    bool ContainsIndex(UPInt index) const { return GlyphNum > 0 && index >= AdjStartPos && index < AdjStartPos + GlyphNum; }
    bool IsEmpty() const                  { return Length == 0; }
};

// Walks the merged highlight glyph by glyph.
class HighlighterPosIterator
{
    const Highlighter* pManager;
    UPInt              CurAdjStartPos;
    UPInt              NumGlyphs;
    HighlightDesc      CurDesc;

    void InitCurDesc();

public:
    HighlighterPosIterator() { CurAdjStartPos = NumGlyphs = 0; }
    HighlighterPosIterator(const Highlighter* pmanager, UPInt startPos, UPInt len = SF_MAX_UPINT);

    const HighlightDesc& operator*() const { return CurDesc; }
    void operator++(int);
    void operator++() { operator++(0); }
    void operator+=(UPInt p);
    bool IsFinished() const;
};

// Walks the ranges with equal highlighting.
class HighlighterRangeIterator
{
    const Highlighter* pManager;
    UPInt              CurTextPos;
    UPInt              CurRangeIndex;
    HighlightDesc      CurDesc;
    unsigned           Flags;

    void InitCurDesc();

public:
    HighlighterRangeIterator(const Highlighter* pmanager, unsigned flags);
    HighlighterRangeIterator(const Highlighter* pmanager, UPInt startPos, unsigned flags);

    HighlightDesc operator*();
    void operator++(int);
    void operator++() { operator++(0); }
    bool IsFinished() const;
};

// The list of highlights of one view (0x38 bytes).
class Highlighter : public NewOverrideBase<StatRender_Text_Mem>
{
    friend class HighlighterRangeIterator;
    friend class HighlighterPosIterator;

protected:
    ArrayLH<HighlightDesc> Highlighters;    // +0x00
    unsigned               LastId;          // +0x18
    UPInt                  CorrectionPos;   // +0x20
    UPInt                  CorrectionLen;   // +0x28
    bool                   Valid;           // +0x30
    mutable SInt8          HasUnderline;    // +0x31 0 unknown, 1 yes, else no

public:
    Highlighter();

    bool IsEmpty() const { return Highlighters.GetSize() == 0; }

    HighlightDesc* CreateNewHighlighter(HighlightDesc* pdesc);
    HighlightDesc* CreateHighlighter(const HighlightDesc& desc);
    HighlightDesc* CreateEmptyHighlighter(unsigned* pid)
    {
        HighlightDesc  empty;
        HighlightDesc* pdesc = CreateNewHighlighter(&empty);
        *pid = empty.Id;
        return pdesc;
    }
    HighlightDesc  GetHighlighter(unsigned id) const;
    HighlightDesc* GetHighlighterPtr(unsigned id);
    bool           SetHighlighter(unsigned id, const HighlightInfo& info);
    bool           FreeHighlighter(unsigned id);

    HighlighterPosIterator   GetPosIterator(UPInt startPos = 0, UPInt len = SF_MAX_UPINT) const;
    HighlighterRangeIterator GetRangeIterator(UPInt startPos = 0, unsigned flags = SF_MAX_UINT) const;

    void UpdateGlyphIndices(const CompositionStringBase* pcs);
    void Invalidate()     { Valid = false; HasUnderline = 0; }
    void Validate()       { Valid = true; }
    bool IsValid() const  { return Valid; }
    bool HasUnderlineHighlight() const;

    void Add(HighlightDesc& merge);
    void Remove(const HighlightDesc& cut);
    void SetSelectColor(const Color& color);
    bool IsAnyCharSelected(UPInt selectStart, UPInt selectEnd);
};

}}} // namespace Scaleform::Render::Text

#endif
