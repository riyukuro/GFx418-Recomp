// Recovered Scaleform 4.1.18 GFx: the text field editor (cursor, selection, keyboard and mouse editing, clipboard,
// the "restrict" character filter) and the IME composition string (bodies in sfr_gfx_07, Text_EditorKit).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_TEXT_EDITORKIT_H
#define MS2_SF_GFX_TEXT_EDITORKIT_H

#include "ms2/scaleform/include/render/text_docview.h"
#include "ms2/scaleform/include/render/text_highlight.h"
#include "../kernel/sf_autoptr.h"
#include "../kernel/sf_range.h"
#include "gfx_textclipboard.h"

namespace Scaleform { namespace GFx {

// Memory stat of the movie's text objects.
enum { StatMV_Text_Mem = 0x145 };

namespace Text {

using Render::TextLayout;
using Render::RectF;
using Render::PointF;
using Render::Color;
using namespace Render::Text;

// Highlight looks used for the parts of an IME composition (0x54 bytes).
struct IMEStyle : public NewOverrideBase<StatMV_Text_Mem>
{
    enum Category
    {
        SC_CompositionSegment = 0,
        SC_ClauseSegment      = 1,
        SC_ConvertedSegment   = 2,
        SC_PhraseLengthAdj    = 3,
        SC_LowConfSegment     = 4,
        SC_MaxNum
    };

    HighlightInfo HighlightStyles[SC_MaxNum]; // +0x00
    UInt8         PresenceMask;               // +0x50 one bit per category that is set

    IMEStyle() : PresenceMask(0) {}

    const HighlightInfo& GetElement(UPInt n) const { return HighlightStyles[n]; }
    bool HasElement(UPInt n) const { return (PresenceMask & (1 << n)) != 0; }
    void SetElement(UPInt n, const HighlightInfo& info)
    {
        PresenceMask |= UInt8(1 << n);
        HighlightStyles[n] = info;
    }
    // Takes every category st has.
    void Unite(const IMEStyle& st)
    {
        for (unsigned i = 0; i < SC_MaxNum; ++i)
            if (st.HasElement(i))
                SetElement(i, st.GetElement(i));
    }
};

class EditorKit;

// The text being composed by an IME, shown inline at its position without being part of the document
// (0x100 bytes, vftable 0x14318eb10).
class CompositionString : public CompositionStringBase
{
public:
    Ptr<TextFormat> pDefaultFormat;                      // +0x10
    EditorKit*      pEditorKit;                          // +0x18
    Ptr<Allocator>  pAllocator;                          // +0x20
    Paragraph       String;                              // +0x28
    UPInt           CursorPos;                           // +0x70
    bool            HasHighlightingFlag;                 // +0x78
    IMEStyle        Styles;                              // +0x7c
    unsigned        HighlightIds[IMEStyle::SC_MaxNum*2]; // +0xd0
    UInt8           HighlightIdsUsed;                    // +0xf8

    Paragraph* GetSourceParagraph();
    void       Reformat();

    CompositionString(EditorKit* const peditorKit);
    ~CompositionString();

    virtual UPInt          GetPosition() const      { return String.GetStartIndex(); }
    virtual UPInt          GetLength() const        { return String.GetLength(); }
    virtual const wchar_t* GetText() const          { return String.GetText(); }
    virtual TextFormat*    GetTextFormat(UPInt pos) { return String.GetTextFormatPtr(pos); }
    virtual Allocator*     GetAllocator() const     { return pAllocator; }

    void SetText(const wchar_t* pwstr, UPInt nchars = SF_MAX_UPINT);
    void SetPosition(UPInt pos);
    Paragraph&  GetParagraph()                { return String; }
    TextFormat* GetDefaultTextFormat() const  { return pDefaultFormat; }

    void  SetCursorPosition(UPInt pos);
    UPInt GetCursorPosition() const { return CursorPos; }

    void HighlightText(UPInt pos, UPInt len, IMEStyle::Category styleCategory);
    void UseStyles(const IMEStyle& styles) { Styles.Unite(styles); }
    void ClearHighlighting();
    bool HasHighlighting() const { return HasHighlightingFlag; }

    static IMEStyle GetDefaultStyles();
};

// Editing state of one text field (0xb0 bytes, vftable 0x14318eb40).
class EditorKit : public EditorKitBase
{
protected:
    enum
    {
        Flags_ReadOnly           = 0x1,
        Flags_Selectable         = 0x2,
        Flags_UseRichClipboard   = 0x4,
        Flags_CursorBlink        = 0x8,
        Flags_CursorTimerBlocked = 0x10,
        Flags_MouseCaptured      = 0x20,
        Flags_ShiftPressed       = 0x40,
        Flags_OverwriteMode      = 0x80,
        Flags_WideCursor         = 0x100,
        Flags_LastDoubleClick    = 0x200,
        Flags_Focused            = 0x400
    };

    // The parsed "restrict" property: the allowed characters as ranges, and the source string.
    struct RestrictParams : public NewOverrideBase<StatMV_Text_Mem>
    {
        typedef RangeDataArray<void*, ArrayLH<RangeData<void*> > > RangesType;
        RangesType RestrictRanges;
        StringLH   RestrictString;
    };

    Ptr<DocView>           pDocView;    // +0x10
    Ptr<TextClipboard>     pClipboard;  // +0x18
    Ptr<TextKeyMap>        pKeyMap;     // +0x20
    Ptr<CompositionString> pComposStr;  // +0x28
    AutoPtr<RestrictParams> pRestrict;  // +0x30
    UPInt                  CursorPos;   // +0x40
    Color                  CursorColor; // +0x48
    int                    SelectPos;   // +0x4c
    CachedValue<RectF>     CursorRect;  // +0x50
    Double                 CursorTimer;                // +0x70
    Double                 LastAdvanceTime;            // +0x78
    float                  LastHorizCursorPos;         // +0x80
    Render::PointF         LastMousePos;               // +0x84
    UInt32                 LastClickTime;              // +0x8c
    UInt32                 ActiveSelectionBkColor;     // +0x90
    UInt32                 ActiveSelectionTextColor;   // +0x94
    UInt32                 InactiveSelectionBkColor;   // +0x98
    UInt32                 InactiveSelectionTextColor; // +0x9c
    UInt16                 Flags;                      // +0xa0

    void SetCursorBlink()             { Flags |= Flags_CursorBlink; }
    void ClearCursorBlink()           { Flags &= ~Flags_CursorBlink; }
    bool IsCursorBlink() const        { return (Flags & Flags_CursorBlink) != 0; }
    void SetCursorTimerBlocked()      { Flags |= Flags_CursorTimerBlocked; }
    void ClearCursorTimerBlocked()    { Flags &= ~Flags_CursorTimerBlocked; }
    bool IsCursorTimerBlocked() const { return (Flags & Flags_CursorTimerBlocked) != 0; }
    void SetMouseCaptured()           { Flags |= Flags_MouseCaptured; }
    void ClearMouseCaptured()         { Flags &= ~Flags_MouseCaptured; }
    void SetShiftPressed()            { Flags |= Flags_ShiftPressed; }
    void ClearShiftPressed()          { Flags &= ~Flags_ShiftPressed; }
    bool IsShiftPressed() const       { return (Flags & Flags_ShiftPressed) != 0; }
    void SetLastDoubleClickFlag()     { Flags |= Flags_LastDoubleClick; }
    void ClearLastDoubleClickFlag()   { Flags &= ~Flags_LastDoubleClick; }
    bool IsLastDoubleClickFlagSet() const { return (Flags & Flags_LastDoubleClick) != 0; }

    virtual void OnDocumentChanged(unsigned notifyMask); // +0x40

    const LineBuffer::GlyphEntry* GetGlyphEntryAtIndex(UPInt charIndex, UPInt* ptextPos);
    void InvalidateSelectionColors();
    bool ParseRestrict(const char* restrStr, UPInt restrStrLen);

public:
    EditorKit(DocView* pdocview);
    ~EditorKit();

    virtual void  AddDrawCursorInfo(TextLayout::Builder& bld);
    virtual bool  IsReadOnly() const { return (Flags & Flags_ReadOnly) != 0; }
    virtual bool  HasCompositionString() const;
    virtual UPInt TextPos2GlyphOffset(UPInt textPos);
    virtual UPInt TextPos2GlyphPos(UPInt textPos);
    virtual UPInt GlyphPos2TextPos(UPInt glyphPos);
    virtual CompositionString* GetCompositionString();

    void SetReadOnly()               { Flags |= Flags_ReadOnly; }
    void ClearReadOnly()             { Flags &= ~Flags_ReadOnly; }
    void SetSelectable()             { Flags |= Flags_Selectable; }
    void ClearSelectable()           { Flags &= ~Flags_Selectable; }
    bool IsSelectable() const        { return (Flags & Flags_Selectable) != 0; }
    void SetUseRichClipboard()       { Flags |= Flags_UseRichClipboard; }
    void ClearUseRichClipboard()     { Flags &= ~Flags_UseRichClipboard; }
    bool DoesUseRichClipboard() const { return (Flags & Flags_UseRichClipboard) != 0; }
    void SetOverwriteMode()          { Flags |= Flags_OverwriteMode; }
    void ClearOverwriteMode()        { Flags &= ~Flags_OverwriteMode; }
    bool IsOverwriteMode() const     { return (Flags & Flags_OverwriteMode) != 0; }
    void SetWideCursor()             { Flags |= Flags_WideCursor; }
    void ClearWideCursor();
    bool IsWideCursor() const        { return (Flags & Flags_WideCursor) != 0; }
    void SetFocused()                { Flags |= Flags_Focused; }
    void ClearFocused()              { Flags &= ~Flags_Focused; }
    bool IsFocused() const           { return (Flags & Flags_Focused) != 0; }
    bool IsMouseCaptured() const     { return (Flags & Flags_MouseCaptured) != 0; }

    void Advance(Double timer);
    void UpdateWideCursor();
    void ResetBlink(bool state = true, bool blocked = false);
    bool HasCursor() const { return !IsReadOnly(); }

    void  SetCursorPos(UPInt pos, bool selectionAllowed);
    void  SetCursorPos(UPInt pos) { SetCursorPos(pos, IsSelectable()); }
    UPInt GetCursorPos() const;
    // a copy: invalidating the result leaves the editor's cache alone
    CachedValue<RectF> GetCursorRect() const { return CursorRect; }

    bool ScrollToPosition(UPInt pos, bool avoidComposStr, bool wideCursor = false);
    bool ScrollToCursor() { return ScrollToPosition(CursorPos, true, IsWideCursor()); }

    void OnMouseDown(float x, float y, int buttons);
    void OnMouseUp(float x, float y, int buttons);
    void OnMouseMove(float x, float y);
    bool OnKeyDown(int code, const KeyModifiers& specKeysState);
    bool OnKeyUp(int code, const KeyModifiers& specKeysState);
    bool OnChar(UInt32 wcharCode);
    void OnSetFocus();
    void OnKillFocus();

    DocView* GetDocument() const { return pDocView; }
    void SetClipboard(TextClipboard* pclipbrd) { pClipboard = pclipbrd; }
    void SetKeyMap(TextKeyMap* pkeymap)        { pKeyMap = pkeymap; }

    bool CalcCursorRectInLineBuffer(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex = NULL,
                                    unsigned* pglyphIndex = NULL, bool avoidComposStr = true,
                                    LineBuffer::Line::Alignment* plineAlignment = NULL);
    bool CalcAbsCursorRectInLineBuffer(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex = NULL,
                                       unsigned* pglyphIndex = NULL)
    {
        return CalcCursorRectInLineBuffer(charIndex, pcursorRect, plineIndex, pglyphIndex, false);
    }
    bool CalcCursorRectOnScreen(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex = NULL,
                                unsigned* pglyphIndex = NULL, bool avoidComposStr = true,
                                LineBuffer::Line::Alignment* plineAlignment = NULL);
    bool CalcAbsCursorRectOnScreen(UPInt charIndex, RectF* pcursorRect, unsigned* plineIndex = NULL,
                                   unsigned* pglyphIndex = NULL)
    {
        return CalcCursorRectOnScreen(charIndex, pcursorRect, plineIndex, pglyphIndex, false);
    }

    void  SetSelection(UPInt startPos, UPInt endPos);
    void  ClearSelection()                  { pDocView->ClearSelection(); }
    UPInt GetBeginSelection() const         { return pDocView->GetBeginSelection(); }
    UPInt GetEndSelection() const           { return pDocView->GetEndSelection(); }
    void  SetBeginSelection(UPInt begSel)   { SetSelection(begSel, GetEndSelection()); }
    void  SetEndSelection(UPInt endSel)     { SetSelection(GetBeginSelection(), endSel); }

    void SetActiveSelectionTextColor(UInt32 c)         { ActiveSelectionTextColor = c; InvalidateSelectionColors(); }
    void SetActiveSelectionBackgroundColor(UInt32 c)   { ActiveSelectionBkColor = c; InvalidateSelectionColors(); }
    void SetInactiveSelectionTextColor(UInt32 c)       { InactiveSelectionTextColor = c; InvalidateSelectionColors(); }
    void SetInactiveSelectionBackgroundColor(UInt32 c) { InactiveSelectionBkColor = c; InvalidateSelectionColors(); }
    UInt32 GetActiveSelectionTextColor() const         { return ActiveSelectionTextColor; }
    UInt32 GetActiveSelectionBackgroundColor() const   { return ActiveSelectionBkColor; }
    UInt32 GetInactiveSelectionTextColor() const       { return InactiveSelectionTextColor; }
    UInt32 GetInactiveSelectionBackgroundColor() const { return InactiveSelectionBkColor; }

    void  CopyToClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard);
    void  CutToClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard);
    UPInt PasteFromClipboard(UPInt startPos, UPInt endPos, bool useRichClipboard);

    bool          SetRestrict(const String& restrStr);
    const String* GetRestrict() const;
    void          ClearRestrict();
    // True when wcharCode passes the restrict filter (or there is none).
    bool CheckRestrict(wchar_t wcharCode) const
    {
        if (pRestrict)
            return !pRestrict->RestrictRanges.GetIteratorAt(int(wcharCode)).IsFinished();
        return true;
    }
    bool HasRestrict() const { return !!pRestrict; }

    CompositionString* CreateCompositionString();
    void               ReleaseCompositionString();
};

}}} // namespace Scaleform::GFx::Text

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::Text::CompositionString) == 0x100, "CompositionString size");
static_assert(sizeof(Scaleform::GFx::Text::EditorKit) == 0xb0, "EditorKit size");

#endif
