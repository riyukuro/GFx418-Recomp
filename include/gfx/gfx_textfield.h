// Recovered Scaleform 4.1.18 GFx: TextField (dynamic / input text instances). Shared header of the src/ms2/scaleform
// units (sfr lane): append, do not reorder.
// OPAQUE for now: 0x148 bytes and the constructor (as the AS3 character factory allocates and builds it); the full
// declaration comes with the GFx_TextField units. Used through its DisplayObjectBase part (offset 0).
#ifndef MS2_SF_GFX_TEXTFIELD_H
#define MS2_SF_GFX_TEXTFIELD_H

#include "ms2/scaleform/include/gfx/gfx_characterdef.h"
#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_stream.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"

namespace Scaleform { class Range; }   // (appended, sfr34) kernel/sf_range.h
namespace Scaleform { namespace Render { namespace Text { struct ImageDesc; } } }   // (appended, sfr24) text_core.h

namespace Scaleform { namespace Render { namespace Text { class DocView; } }
namespace GFx {

class FontResource;
class LoadProcess;
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

class TextField
{
public:
    TextField(TextFieldDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* parent,
              ResourceId id);
    operator DisplayObjectBase*() { return reinterpret_cast<DisplayObjectBase*>(this); }

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
    bool IsIMEDisabledFlag() const { return (GetFlags418() & 0x800) != 0; }
    bool IsPassword() const        { return (GetFlags418() & 0x4) != 0; }
    UInt32 GetFlags418() const     { return *reinterpret_cast<const UInt32*>(Unrecovered + 0xfc); }  // +0xfc Flags

    // (appended for the AS2 TextField natives, sfr_as2_02)
    Render::Text::DocView* GetDocument() const   // +0xe0 the document view
    {
        return *reinterpret_cast<Render::Text::DocView* const*>(Unrecovered + 0xe0);
    }
    // The next advance reformats the whole text.
    void SetCompleteReformatReq() { *reinterpret_cast<UInt32*>(Unrecovered + 0xfc) |= 0x10000; }
    bool HasStyleSheet() const;   // exe 0x1425b9730
    void SetDirtyFlag();          // exe 0x1425bc060
    // Replaces [beginPos, endPos) with the first strLen characters of pstr (all of it for SF_MAX_UPINT).
    void ReplaceTextA(const wchar_t* pstr, UPInt beginPos, UPInt endPos, UPInt strLen); // exe 0x1425bb810
    // (appended, sfr31) Sets the text, or the HTML text when html is set.
    void SetText(const wchar_t* ptext, bool html = false);       // exe 0x1425bd530
    bool SetTextValue(const char* ptext, bool html = false, bool notifyVariable = true); // exe 0x1425bd9a0
    // (appended, sfr34) The text, or the HTML text when reqHtml is set.
    ASString GetText(bool reqHtml = false) const;                 // exe 0x1425b91e0
    // (appended, sfr34) Whether the text is HTML (Flags bit 1).
    bool IsHtml() const { return (GetFlags418() & 0x2) != 0; }
    // (appended, sfr34) Whether a URL is under mouse mouseIndex's cursor; its point in the text and range.
    bool IsUrlUnderMouseCursor(unsigned mouseIndex, Render::PointF* ppnt = NULL, Range* purlRangePos = NULL);   // exe 0x1425b9cc0

    // (appended, sfr24) What happened to a link of the text (AvmTextFieldBase::OnLinkEventEx).
    enum LinkEvent
    {
        Link_press,
        Link_release,
        Link_rollover,
        Link_rollout
    };

    // (appended, sfr24) what the AS3 TextField natives call (sfr_as3_13 / 15 / 19).
    struct CSSHolderBase;                                    // the style sheet (CSS) data
    UInt32 GetTextColor32() const;                           // exe 0x1425b9360
    void   SetCSSData(CSSHolderBase* pcssData);              // exe 0x1425bbd10
    void   UpdateUrlStyles();                                // exe 0x1425bec30
    Ptr<Text::EditorKit> CreateEditorKit();                  // exe 0x1425b7840
    void   RemoveIdImageDescAssoc(const char* idStr);        // exe 0x1425bb680
    void   ClearIdImageDescAssoc();                          // exe 0x1425b7220
    void   AddIdImageDescAssoc(const char* idStr, Render::Text::ImageDesc* pdesc);  // exe 0x1425b65e0
    // (appended, sfr24) the display info's position in the text rectangle's space.
    Render::PointF TransformToTextRectSpace(const GFx::Value::DisplayInfo& info) const;      // exe 0x1425be970
    // (appended, sfr22) the flags word at +0xfc, writable (html 0x2, the display-info-set 0x2000).
    UInt32& FlagsRef() { return *reinterpret_cast<UInt32*>(Unrecovered + 0xfc); }

private:
    UByte Unrecovered[0x148];
};

// (appended, sfr24) The text-field half of the AVM part of a text field (AS3::AvmTextField +0x40), after the
// AvmInteractiveObjBase slots: style sheet 23..24, change / link / mouse / char / scroll notifications 25..29, the
// variable binding 30..31 (AS2 only; the AS3 field returns false / does nothing).
class AvmTextFieldBase : public AvmInteractiveObjBase
{
public:
    virtual const Text::StyleManager* GetStyleSheet() const = 0;
    virtual bool HasStyleSheet() const = 0;
    virtual void NotifyChanged() = 0;
    virtual void OnLinkEventEx(TextField::LinkEvent event, unsigned pos, unsigned controllerIndex) = 0;
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
