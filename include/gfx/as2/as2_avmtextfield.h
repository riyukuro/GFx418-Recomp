// Recovered Scaleform 4.1.18 GFx AS2: the script side of a text field (AvmTextField) and its TextField natives.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_AS2_AVMTEXTFIELD_H
#define MS2_SF_GFX_AS2_AVMTEXTFIELD_H

#include "as2_avmcharacter.h"
#include "../gfx_textfield.h"

namespace Scaleform { namespace GFx { namespace AS2 {

class TextFieldObject;

// The AS2 text field's part of the movie, 0x68 bytes. AvmCharacter at +0 (vftables 0x1432181a0, +8 0x1432182e8),
// AvmTextFieldBase at +0x30 (vftable 0x143218390: slots 0..22 jump back to the main ones, 23..31 are the text-field
// ones). The constructor 0x142918b50 clears VariableVal and ASTextFieldObj; the deleting destructor 0x1429296e0
// releases ASTextFieldObj, VariableVal and VariableName, then runs AvmCharacter's and frees 0x68 bytes.
class AvmTextField : public AvmCharacter, public AvmTextFieldBase
{
public:
    ASString VariableName; // +0x38, the variable bound to this field

    // Sends the event named by the first argument to the listeners of the text field.
    static void BroadcastMessage(const FnCall& fn);

    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar);

    // (appended for sfr_as2_02) the TextField natives. The field a method works on: this when it is a TextField
    // (TextField is opaque, it starts at its InteractiveObject part).
    static bool IsTextFieldTarget(const FnCall& fn)
    {
        return fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object_TextField;
    }
    // Only after IsTextFieldTarget.
    static TextField* GetTextFieldTarget(const FnCall& fn)
    {
        return reinterpret_cast<TextField*>(fn.ThisPtr->ToCharacter());
    }
    static InteractiveObject* ToCharacter(TextField* ptf) { return reinterpret_cast<InteractiveObject*>(ptf); }

    static void RemoveTextField(const FnCall& fn);         // exe 0x14290a0f0
    static void GetCharBoundaries(const FnCall& fn);       // exe 0x14290a180
    static void GetCharIndexAtPoint(const FnCall& fn);     // exe 0x14290a350
    static void GetExactCharBoundaries(const FnCall& fn);  // exe 0x14290a4b0
    static void GetLineIndexAtPoint(const FnCall& fn);     // exe 0x14290a680
    static void GetLineIndexOfChar(const FnCall& fn);      // exe 0x14290a7d0
    static void GetLineOffset(const FnCall& fn);           // exe 0x14290a8c0
    static void GetLineLength(const FnCall& fn);           // exe 0x14290a9c0
    static void GetFirstCharInParagraph(const FnCall& fn); // exe 0x14290b1c0
    static void AppendText(const FnCall& fn);              // exe 0x14290b920
    static void GetLineMetrics(const FnCall& fn);          // exe 0x14290aac0
    static void GetLineText(const FnCall& fn);             // exe 0x14290afc0
    static void AppendHtml(const FnCall& fn);              // exe 0x14290b9f0
    static void CopyToClipboard(const FnCall& fn);         // exe 0x14290bb20
    static void CutToClipboard(const FnCall& fn);          // exe 0x14290bc50
    static void PasteFromClipboard(const FnCall& fn);      // exe 0x14290bd90
    static void ReplaceSel(const FnCall& fn);              // exe 0x142909b00
    static void ReplaceTextA(const FnCall& fn);            // exe 0x142909d80 (replaceText)
    static void SetTextFormat(const FnCall& fn);           // exe 0x142909300
    static void SetNewTextFormat(const FnCall& fn);        // exe 0x142909590
    static void GetTextFormat(const FnCall& fn);           // exe 0x1429096e0
    static void GetNewTextFormat(const FnCall& fn);        // exe 0x1429099d0
    static void UpdateImageSubstitution(const FnCall& fn); // exe 0x14290b4c0 (appended for sfr_as2_02b)
    static void SetImageSubstitutions(const FnCall& fn);   // exe 0x14290b2c0

    // The script side of a text field; AvmCharacter sits at the start of its AVM object.
    static AvmTextField* FromCharacter(InteractiveObject* pch)
    {
        return static_cast<AvmTextField*>(
            static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pch->GetAvmObjImpl())));
    }

private:
    // Applies one substitution object (the idx-th of the call's argument) to the field (exe 0x14296f870, sfr_as2_06).
    void ProceedImageSubstitution(const FnCall& fn, int idx, const Value* pve);

public:
    // (appended for sfr_as2_06) A click gives no focus to a read-only field that cannot be selected (exe 0x1429659e0).
    virtual bool IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    virtual bool IsTabable() const;
    virtual void OnEventLoad(); // exe 0x14296ba60
    // Unloads at once, leaving the playlist (exe 0x14296d310).
    virtual bool OnUnloading(bool mayRemove);

    // (appended, sfr24) the rest of the layout and the vftable.
    Value                 VariableVal;    // +0x40, the bound variable's value as last seen
    Ptr<TextFieldObject>  ASTextFieldObj; // +0x60, the field's AS object once a script asked for it

    AvmTextField(TextField* ptf); // exe 0x142918b50

    // ObjectInterface slots 1..4 (+8 vftable 0x1432182e8); the members go to the field's properties first
    // (exe 0x142983360, 0x14294c720).
    virtual const char* GetTextValue(Environment* penv = 0) const { SF_UNUSED(penv); return ""; }
    virtual ObjectType  GetObjectType() const { return Object_TextField; }
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    // Both bases carry the AvmInteractiveObjBase slots: these final overriders resolve them (the +0x30 vftable
    // reaches them through this-adjusting thunks).
    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase() { return static_cast<AvmCharacter*>(this); }
    virtual AvmSpriteBase*              ToAvmSpriteBase()         { return 0; }
    virtual AvmButtonBase*              ToAvmButttonBase()        { return 0; }
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()      { return this; }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()  { return 0; }
    virtual const char* GetAbsolutePath(String* ppath) const { return AvmCharacter::GetAbsolutePath(ppath); }
    virtual bool        HasEventHandler(const EventId& id) const { SF_UNUSED(id); return false; }
    virtual bool        OnEvent(const EventId& id) { SF_UNUSED(id); return false; }
    virtual void        OnEventUnload() {}
    virtual bool        ActsAsButton() const { return false; }
    virtual unsigned    GetCursorType() const { return 0; }
    virtual void        OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                unsigned controllerIdx, FocusMovedType fmt)
    {
        AvmCharacter::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    }
    virtual void        OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
    {
        SF_UNUSED2(controllerIdx, fmt);
    }
    virtual bool        OnKeyEvent(const EventId& id, int* pkeyMask) { SF_UNUSED2(id, pkeyMask); return false; }
    virtual bool        OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                              FocusMovedType fmt = GFx_FocusMovedByKeyboard)
    {
        SF_UNUSED3(newFocusCh, controllerIdx, fmt);
        return true;
    }

    // AvmTextFieldBase slots 23..31 (this is the +0x30 part in the exe bodies).
    virtual const Text::StyleManager* GetStyleSheet() const; // exe 0x1429561e0
    virtual bool HasStyleSheet() const;                      // exe 0x14295dbb0
    virtual void NotifyChanged();                            // exe 0x142969080
    virtual void OnLinkEventEx(TextField::LinkEvent event, unsigned pos, unsigned controllerIndex)
    {
        SF_UNUSED3(event, pos, controllerIndex);
    }
    virtual bool OnMouseEvent(const EventId& event);         // exe 0x14296c8c0
    virtual bool OnCharEvent(wchar_t wcharCode, unsigned controllerIdx)
    {
        SF_UNUSED2(wcharCode, controllerIdx);
        return true;
    }
    virtual void OnScroll();                                 // exe 0x14296ce90
    virtual bool UpdateTextFromVariable();                   // exe 0x142992c40
    virtual void UpdateVariable();                           // exe 0x142992d80
};
static_assert(sizeof(AvmTextField) == 0x68, "AS2 AvmTextField size");

}}} // namespace Scaleform::GFx::AS2

#endif
