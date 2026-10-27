// Recovered Scaleform 4.1.18 GFx: TextField (dynamic / input text instances). Shared header of the src/ms2/scaleform
// units (sfr lane): append, do not reorder.
// TextField is 0x148 bytes (ctor 0x1425b5930, vftables 0x143189ac8 / LogBase 0x143189e60, its document listener's
// 0x143189a68); bodies in sfr_gfx_03e. The override order is the exe's, checked slot by slot.
#ifndef MS2_SF_GFX_TEXTFIELD_H
#define MS2_SF_GFX_TEXTFIELD_H

#include "ms2/scaleform/include/gfx/gfx_characterdef.h"
#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_stream.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/kernel/sf_stringhash.h"
#include "ms2/scaleform/include/kernel/sf_range.h"
#include "ms2/scaleform/include/render/text_docview.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"

namespace Scaleform { class Range; }   // (appended, sfr34) kernel/sf_range.h
namespace Scaleform { namespace Render { namespace Text { struct ImageDesc; } } }   // (appended, sfr24) text_core.h

namespace Scaleform { namespace Render { namespace Text { class DocView; } }
namespace GFx {

class FontResource;
class LoadProcess;

// Memory stat of the movie's text objects. (also in text_editorkit.h)
#ifndef SF_GFX_STATMV_TEXT_MEM
#define SF_GFX_STATMV_TEXT_MEM
enum { StatMV_Text_Mem = 0x145 };
#endif
namespace Text { class StyleManager; class EditorKit; }   // (appended, sfr24)

// The edit text definition, as the DefineEditText tag gives it (a struct in 4.1.18, as the TextField constructor's
// mangled name has it). Bodies: GFx_TextFieldDef (sfr_gfx_01c); vftable 0x143184748.
//   0x90 bytes: the constructor inits up to +0x84, but both allocation sites (the tag loader and
//   MovieDataDef's empty definitions) ask for 0x90; nothing in the exe touches +0x88.
struct TextFieldDef : public CharacterDef
{
    ResourcePtr<FontResource> pFont;        // +0x20
    ResourceId                FontId;       // +0x30
    StringLH                  FontClass;    // +0x38
    RectF                     TextRect;     // +0x40
    float                     TextHeight;   // +0x50 in twips
    Render::Color             ColorV;       // +0x54
    int                       MaxLength;    // +0x58
    float                     LeftMargin;   // +0x5c
    float                     RightMargin;  // +0x60
    float                     Indent;       // +0x64 first line
    float                     Leading;      // +0x68 extra line spacing

    StringLH                  DefaultText;  // +0x70
    StringLH                  VariableName; // +0x78

    enum
    {
        Flags_WordWrap      = 0x1,
        Flags_Multiline     = 0x2,
        Flags_Password      = 0x4,
        Flags_ReadOnly      = 0x8,
        Flags_AutoSize      = 0x10,
        Flags_Selectable    = 0x20,
        Flags_Border        = 0x40,
        Flags_Html          = 0x80,
        Flags_UseDeviceFont = 0x100,
        Flags_HasLayout     = 0x200, // the alignment, margins, indent and leading came with the tag
        Flags_AAReadability = 0x400,
        Flags_EmptyTextDef  = 0x800, // made by createTextField, not loaded
        Flags_WasStatic     = 0x1000
    };
    UInt16 Flags; // +0x80

    enum alignment
    {
        ALIGN_LEFT,
        ALIGN_RIGHT,
        ALIGN_CENTER,
        ALIGN_JUSTIFY
    };
    alignment Alignment; // +0x84

private:
    UByte Unrecovered_88[8]; // +0x88 (see above)

public:
    TextFieldDef();
    ~TextFieldDef();

    virtual unsigned         GetResourceTypeCode() const { return MakeTypeCode(RT_EditTextDef); }
    virtual CharacterDefType GetType() const { return TextField; }

    void SetFlag(UInt16 flag, bool v) { if (v) Flags |= flag; else Flags &= ~flag; }
    bool HasFlag(UInt16 flag) const   { return (Flags & flag) != 0; }

    void SetWordWrap(bool v = true)        { SetFlag(Flags_WordWrap, v); }
    void SetMultiline(bool v = true)       { SetFlag(Flags_Multiline, v); }
    void SetPassword(bool v = true)        { SetFlag(Flags_Password, v); }
    void SetReadOnly(bool v = true)        { SetFlag(Flags_ReadOnly, v); }
    void SetAutoSize(bool v = true)        { SetFlag(Flags_AutoSize, v); }
    void SetSelectable(bool v = true)      { SetFlag(Flags_Selectable, v); }
    void SetBorder(bool v = true)          { SetFlag(Flags_Border, v); }
    void SetHtml(bool v = true)            { SetFlag(Flags_Html, v); }
    void SetUseDeviceFont(bool v = true)   { SetFlag(Flags_UseDeviceFont, v); }
    void SetHasLayout(bool v = true)       { SetFlag(Flags_HasLayout, v); }
    void SetAAForReadability(bool v = true){ SetFlag(Flags_AAReadability, v); }
    void SetEmptyTextDef(bool v = true)    { SetFlag(Flags_EmptyTextDef, v); }
    void SetWasStatic(bool v = true)       { SetFlag(Flags_WasStatic, v); }

    bool IsWordWrap() const         { return HasFlag(Flags_WordWrap); }
    bool IsMultiline() const        { return HasFlag(Flags_Multiline); }
    bool IsPassword() const         { return HasFlag(Flags_Password); }
    bool IsReadOnly() const         { return HasFlag(Flags_ReadOnly); }
    bool IsAutoSize() const         { return HasFlag(Flags_AutoSize); }
    bool IsSelectable() const       { return HasFlag(Flags_Selectable); }
    bool IsBorder() const           { return HasFlag(Flags_Border); }
    bool IsHtml() const             { return HasFlag(Flags_Html); }
    bool DoesUseDeviceFont() const  { return HasFlag(Flags_UseDeviceFont); }
    bool HasLayout() const          { return HasFlag(Flags_HasLayout); }
    bool IsAAForReadability() const { return HasFlag(Flags_AAReadability); }
    bool IsEmptyTextDef() const     { return HasFlag(Flags_EmptyTextDef); }
    bool WasStatic() const          { return HasFlag(Flags_WasStatic); }

    // The definition createTextField uses: 12 px black device-font text, read-only and selectable.
    void InitEmptyTextDef();
    void Read(LoadProcess* p, TagType tagType);
};
static_assert(sizeof(TextFieldDef) == 0x90, "TextFieldDef size (both allocation sites)");

class TextField : public InteractiveObject
{
public:
    // Flags (+0xfc).
    enum
    {
        Flags_AutoSize            = 0x1,
        Flags_Html                = 0x2,
        Flags_Password            = 0x4,
        Flags_NoTranslate         = 0x8,
        Flags_CondenseWhite       = 0x10,
        Flags_HandCursor          = 0x20,
        Flags_NextFrame           = 0x40,
        Flags_MouseWheelEnabled   = 0x80,
        Flags_UseRichClipboard    = 0x100,
        Flags_AlwaysShowSelection = 0x200,
        Flags_NoAutoSelection     = 0x400,
        Flags_IMEDisabled         = 0x800,
        Flags_OriginalIsHtml      = 0x1000,
        Flags_NeedUpdateGeomData  = 0x2000,
        Flags_ForceOneTimeAdvance = 0x4000,
        Flags_ForceAdvance        = 0x8000,
        Flags_NeedUpdateLayout    = 0x10000
    };

    // The shadowStyle / shadowColor state (AS2), made when one of them is first set.
    struct ShadowParams;

    // The document view's and editor's callbacks into the field (TextDocListener, +0x130).
    class TextDocumentListener : public Render::Text::DocView::DocumentListener
    {
        TextField* GetTextField() const;
    public:
        TextDocumentListener();
        virtual bool    View_OnLineFormat(Render::Text::DocView& view, Render::Text::DocView::LineFormatDesc& desc); // 1
        virtual void    View_OnHScroll(Render::Text::DocView& view, unsigned newScroll);     // 2
        virtual void    View_OnVScroll(Render::Text::DocView& view, unsigned newScroll);     // 3
        virtual void    View_OnMaxScrollChanged(Render::Text::DocView& view);                // 4
        virtual void    View_OnChanged(Render::Text::DocView& view);                         // 5
        virtual unsigned Editor_OnKey(Render::Text::EditorKitBase& editor, unsigned keyCode);       // 6
        virtual wchar_t Editor_OnCharacter(Render::Text::EditorKitBase& editor, wchar_t srcChar);   // 7
        virtual void    Editor_OnChanged(Render::Text::EditorKitBase& editor);               // 8
        virtual void    Editor_OnCursorMoved(Render::Text::EditorKitBase& editor);           // 9
        virtual void    Editor_OnCursorBlink(Render::Text::EditorKitBase& editor, bool cursorState); // 10
        virtual String  GetCharacterPath();                                                  // 11
        void TranslatorChanged();
        void OnScroll(Render::Text::DocView& view);
        void SetHandlersMask(UInt8 mask) { HandlersMask = mask; }
    };

    // (appended, sfr24) what happened to a link of the text (AvmTextFieldBase::OnLinkEventEx).
    enum LinkEvent
    {
        Link_press,
        Link_release,
        Link_rollover,
        Link_rollout
    };

    // The style sheet (CSS) data (+0x108), made by the AVM side: the URL runs of the text and each mouse's state
    // over them. 0x40 bytes.
    struct CSSHolderBase : public NewOverrideBase<StatMV_Text_Mem>
    {
        struct UrlZone
        {
            Ptr<Render::Text::StyledText> SavedFmt;
            unsigned                      HitCount;
            unsigned                      OverCount;

            UrlZone() : HitCount(0), OverCount(0) {}
            bool operator==(const UrlZone& r) const
            {
                return SavedFmt == r.SavedFmt && HitCount == r.HitCount && OverCount == r.OverCount;
            }
            bool operator!=(const UrlZone& r) const { return !operator==(r); }
        };
        RangeDataArray<UrlZone> UrlZones;   // +0x08
        struct MouseStateType
        {
            unsigned UrlZoneIndex;          // 1-based; 0: over no URL
            bool     OverBit;
            bool     HitBit;
            MouseStateType() : UrlZoneIndex(0), OverBit(false), HitBit(false) {}
        } MouseState[MaxMiceSupported];     // +0x20

        CSSHolderBase() {}
        virtual ~CSSHolderBase() {}
        virtual bool HasASStyleSheet() const = 0;
        virtual const Render::Text::StyleManagerBase* GetTextStyleManager() const = 0;
    };

    TextField(TextFieldDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* parent,
              ResourceId id);
    virtual ~TextField();                                                               // 0

protected:
    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;  // 1
public:
    virtual void            SetX(Double x);                                             // 17
    virtual Double          GetX() const;                                               // 18
    virtual void            SetY(Double y);                                             // 19
    virtual Double          GetY() const;                                               // 20
    virtual void            SetXScale(Double xscale);                                   // 23
    virtual void            SetYScale(Double yscale);                                   // 25
    virtual void            SetRotation(Double rotation);                               // 29
    virtual void            SetWidth(Double width);                                     // 41
    virtual void            SetHeight(Double height);                                   // 43
    virtual void            SetFilters(const Render::FilterSet* filters);               // 50
    virtual const Render::FilterSet* GetFilters() const;                                // 51
    virtual RectF           GetBounds(const Matrix& t) const;                           // 55
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;  // 57
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);  // 58
    virtual CharacterDef*   GetCharacterDef() const;                                    // 59
    virtual void            AdvanceFrame(bool nextFrame, float framePos = 0.0f);        // 65
    virtual void            OnEventLoad();                                              // 67
    virtual void            OnEventUnload();                                            // 69
    virtual void            SetStateChangeFlags(UByte flags);                           // 73
    virtual CharacterDef::CharacterDefType GetType() const;                             // 75
    virtual bool            IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx) const; // 79 / 80
    virtual bool            IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx);
    virtual bool            IsTabable() const;                                          // 81
    virtual bool            IsFocusRectEnabled() const;                                 // 82
    virtual bool            IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;  // 83
    virtual void            OnFocus(FocusEventType event, InteractiveObject* oldOrNewFocusCh, unsigned controllerIdx,
                                    FocusMovedType fmt);                                // 84
    virtual bool            OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                                  FocusMovedType fmt = GFx_FocusMovedByKeyboard);  // 86
    virtual bool            OnKeyEvent(const EventId& id, int* pkeyMask);               // 90
    virtual bool            OnCharEvent(UInt32 wcharCode, unsigned controllerIdx);      // 91
    virtual bool            OnMouseWheelEvent(int mwDelta);                             // 92
    virtual void            PropagateMouseEvent(const EventId& id);                     // 93
    virtual bool            OnMouseEvent(const EventId& id);                            // 94
    virtual int             CheckAdvanceStatus(bool playingNow);                        // 97
    virtual unsigned        GetCursorType() const;                                      // 110

    // Selection (AS2 Selection natives, sfr_as2_02).
    SPInt GetCaretIndex() const;                         // exe 0x1425b7e70
    UPInt GetBeginIndex() const;                         // exe 0x1425b7df0
    UPInt GetEndIndex() const;                           // exe 0x1425b8220
    void  SetSelection(SPInt beginIndex, SPInt endIndex); // exe 0x1425bcfc0

    // (appended, sfr19) IME (AS3 IME manager, sfr_as3_20).
    bool IsReadOnly() const;                             // exe 0x1425b9b10
    bool IsSelectable() const;                           // exe 0x1425b9b50 (sfr_as2_06)
    // The IME may write into it: not IME-disabled, not read-only, not a password field.
    bool IsIMEEnabled() const
    {
        return !IsIMEDisabledFlag() && !IsReadOnly() && !IsPassword();
    }
    // Gives the candidate list movie the field's font (exe 0x1425bbd70).
    void SetCandidateListFont(DisplayObject* pcandidateList);
    bool IsIMEDisabledFlag() const { return (Flags & Flags_IMEDisabled) != 0; }
    bool IsPassword() const        { return (Flags & Flags_Password) != 0; }
    UInt32 GetFlags418() const     { return Flags; }

    // (appended for the AS2 TextField natives, sfr_as2_02)
    Render::Text::DocView* GetDocument() const { return pDocument; }
    // (appended for the game's GFxManager) the text length against the field's maxChars.
    unsigned GetMaxLength() const  { return (unsigned)pDocument->GetMaxLength(); }
    UPInt    GetTextLength() const { return pDocument->GetLength(); }
    bool     HasMaxLength() const  { return pDocument->HasMaxLength(); }
    // The next advance reformats the whole text.
    void SetCompleteReformatReq() { Flags |= Flags_NeedUpdateLayout; }
    bool HasStyleSheet() const;   // exe 0x1425b9730
    void SetDirtyFlag();          // exe 0x1425bc060
    // Replaces [beginPos, endPos) with the first strLen characters of pstr (all of it for SF_MAX_UPINT).
    void ReplaceTextA(const wchar_t* pstr, UPInt beginPos, UPInt endPos, UPInt strLen); // exe 0x1425bb810
    // (appended, sfr31) Sets the text, or the HTML text when html is set.
    void SetText(const wchar_t* ptext, bool html = false);       // exe 0x1425bd530
    bool SetTextValue(const char* ptext, bool html = false, bool notifyVariable = true); // exe 0x1425bd9a0
    // (appended, sfr34) The text, or the HTML text when reqHtml is set.
    ASString GetText(bool reqHtml = false) const;                 // exe 0x1425b91e0
    // (appended, sfr34) Whether the text is HTML.
    bool IsHtml() const { return (Flags & Flags_Html) != 0; }
    // (appended, sfr34) Whether a URL is under mouse mouseIndex's cursor; its point in the text and range.
    bool IsUrlUnderMouseCursor(unsigned mouseIndex, Render::PointF* ppnt = NULL, Range* purlRangePos = NULL);   // exe 0x1425b9cc0

    // (appended, sfr24) what the AS3 TextField natives call (sfr_as3_13 / 15 / 19).
    UInt32 GetTextColor32() const;                           // exe 0x1425b9360
    void   SetCSSData(CSSHolderBase* pcssData);              // exe 0x1425bbd10
    void   UpdateUrlStyles();                                // exe 0x1425bec30
    Ptr<Text::EditorKit> CreateEditorKit();                  // exe 0x1425b7840
    void   RemoveIdImageDescAssoc(const char* idStr);        // exe 0x1425bb680
    void   ClearIdImageDescAssoc();                          // exe 0x1425b7220
    void   AddIdImageDescAssoc(const char* idStr, Render::Text::ImageDesc* pdesc);  // exe 0x1425b65e0
    // (appended, sfr24) the display info's position in the text rectangle's space.
    Render::PointF TransformToTextRectSpace(const GFx::Value::DisplayInfo& info) const;      // exe 0x1425be970
    // (appended, sfr22) the flags word, writable (html 0x2, the display-info-set 0x2000).
    UInt32& FlagsRef() { return Flags; }

    // (appended, sfr33) the composition string calls of the IME manager (sfr_gfx_03d).
    void           CreateCompositionString();                                   // exe 0x1425b77a0
    void           ClearCompositionString();                                    // exe 0x1425b71a0
    void           CommitCompositionString(const wchar_t* pstr, UPInt len);     // exe 0x1425b75f0
    const wchar_t* GetCompositionString();                                      // exe 0x1425b7f80
    UPInt          GetCompositionStringLength() const;                          // exe 0x1425b7fe0
    UPInt          GetCompositionStringPosition() const;                        // exe 0x1425b8040
    void           SetCompositionStringPosition(UPInt pos);                     // exe 0x1425bbed0
    void           SetCompositionStringText(const wchar_t* pstr, UPInt len);    // exe 0x1425bbf50
    void           SetCursorInCompositionString(UPInt pos);                     // exe 0x1425bbfe0
    // hcategory is a Text::IMEStyle::Category (text_editorkit.h is too heavy to include here).
    void           HighlightCompositionStringText(UPInt pos, UPInt len, unsigned hcategory); // exe 0x1425b9770
    void           SetWideCursor(bool wideCursor);                              // exe 0x1425be280
    // The cursor's rectangle at charIndex in the field's space (twips).
    Render::RectF  GetCursorBounds(UPInt charIndex, float* phitTestX, float* phitTestY); // exe 0x1425b80b0

    // (appended, sfr33) the rest of GFx_TextField (sfr_gfx_03e)
    // The definition's font, size, color and layout become the document's default formats.
    void SetInitialFormatsAsDefault();                                           // exe 0x1425bc420
    // The cursor's text position (-1 without an editor).
    SPInt GetCursorPos() const;                                                  // exe 0x1425b81a0
    // Rebuilds the style sheet's URL zones from the text's link runs.
    void  CollectUrlZones();                                                     // exe 0x1425b72a0
    // The text changed: tells the AVM side and re-lays the field out.
    void  NotifyChanged();                                                       // exe 0x1425b9da0
    const Text::StyleManager* GetStyleSheet() const;                             // exe 0x1425b91a0

    // (appended, sfr36) the property setters of the AS2 AvmTextField::SetMember (sfr_as2_06z).
    // Restarts the editor's cursor blink (no editor: nothing).
    void ResetBlink(bool state = true, bool blocked = false);                    // exe 0x1425bba30
    // The background / border show through the color's alpha byte; the colors keep that byte.
    void SetBackground(bool b);                                                  // exe 0x1425bbb90
    void SetBackgroundColor(UInt32 c);                                           // exe 0x1425bbc10
    void SetBorder(bool b);                                                      // exe 0x1425bbc50
    void SetBorderColor(UInt32 c);                                               // exe 0x1425bbcd0
    bool SetRestrict(const ASString& restrStr);                                  // exe 0x1425bce30
    void SetSelectable(bool f);                                                  // exe 0x1425bcf10
    void SetShadowColor(UInt32 c);                                               // exe 0x1425bd080
    // A shadowStyle string ("s{x,y}..." offsets); false when it does not parse.
    bool SetShadowStyle(const char* pstr);                                       // exe 0x1425bd100
    void SetTextColor(UInt32 c);                                                 // exe 0x1425bd630
    void SetTextFilters(const Render::Text::TextFilter& f);                      // exe 0x1425bd7a0
    CSSHolderBase* GetCSSData() const { return pCSSData.GetPtr(); }              // exe 0x1425b7e60 (out of line)

    // (appended, sfr35) the rest of the setters of the back half (sfr_gfx_03f).
    void ReleaseCompositionString();                                             // exe 0x1425bb5b0
    void SetBackgroundColor(const Render::Color& c);                             // exe 0x1425bbbe0
    void SetBorderColor(const Render::Color& c);                                 // exe 0x1425bbca0
    // The geometry data with its position refreshed from the text rectangle when stale (or forced).
    GeomDataType& UpdateAndGetGeomData(GeomDataType* pgeomData, bool force = false); // exe 0x1425beb10
    // The formats of the definition (font, size, color, alignment, margins..).
    void GetInitialFormats(Render::Text::TextFormat* ptextFmt, Render::Text::ParagraphFormat* pparaFmt); // exe 0x1425b8910
    // The <img> tags the HTML parse found become image descriptors of the document.
    void ProcessImageTags(Render::Text::StyledText::HTMLImageTagInfoArray& imageInfoArray);  // exe 0x1425ba7d0

    // (appended, sfr33) the getters of the front half (sfr_gfx_03e).
    Double GetTextHeight() const;                                                // exe 0x1425b93d0
    Double GetTextWidth() const;                                                 // exe 0x1425b9400
    // The restrict string of the editor (NULL: any character, or no editor).
    const String* GetRestrict() const;                                           // exe 0x1425b90a0
    ASString GetShadowStyle() const;                                             // exe 0x1425b9100
    bool IsUrlTheSame(unsigned mouseIndex, const Range& urlRange);               // exe 0x1425b9c20
    FontResource* GetFontResource();                                             // exe 0x1425b87f0
    void GetPosition(GFx::Value::DisplayInfo* pinfo);                            // exe 0x1425b8e60
    // The style sheet's link format of the URL under the mouse (urlRange) or of its last URL (NULL) for the event.
    void ChangeUrlFormat(LinkEvent event, unsigned mouseIndex, const Range* urlRange = NULL);   // exe 0x1425b6a40

    Ptr<TextFieldDef>             pDef;                 // +0xd8
    Ptr<Render::Text::DocView>    pDocument;            // +0xe0
    ResourceBinding*              pBinding;             // +0xe8 the binding movie's resources (fonts)
    mutable Ptr<Render::FilterSet> pFilters;            // +0xf0
    TextFieldDef::alignment       Alignment;            // +0xf8
    UInt32                        Flags;                // +0xfc
    StringLH                      OriginalTextValue;    // +0x100
    AutoPtr<CSSHolderBase>        pCSSData;             // +0x108
    ShadowParams*                 pShadow;              // +0x118
    StringHashLH<Ptr<Render::Text::ImageDesc> >* pImageDescAssoc;  // +0x120 the <img id=...> images
    unsigned                      FocusedControllerIdx; // +0x128
    TextDocumentListener          TextDocListener;      // +0x130
};
static_assert(sizeof(TextField) == 0x148, "TextField size (the character factories allocate 0x148)");

// (appended, sfr24) The text-field half of the AVM part of a text field (AS3::AvmTextField +0x40), after the
// AvmInteractiveObjBase slots: style sheet 23..24, change / link / mouse / char / scroll notifications 25..29, the
// variable binding 30..31 (AS2 only; the AS3 field returns false / does nothing).
class AvmTextFieldBase : public AvmInteractiveObjBase
{
public:
    virtual const Text::StyleManager* GetStyleSheet() const = 0;
    virtual bool HasStyleSheet() const = 0;
    virtual void NotifyChanged() = 0;
    virtual void OnLinkEventEx(TextField::LinkEvent event, unsigned pos, unsigned controllerIndex)
    {
        SF_UNUSED3(event, pos, controllerIndex);
    }
    virtual bool OnMouseEvent(const EventId& event) = 0;
    virtual bool OnCharEvent(wchar_t wcharCode, unsigned controllerIdx) = 0;
    virtual void OnScroll() = 0;
    // Takes the text from the bound variable; true when it changed.
    virtual bool UpdateTextFromVariable() = 0;
    // Stores the text into the bound variable.
    virtual void UpdateVariable() = 0;
};

}} // namespace Scaleform::GFx

#endif
