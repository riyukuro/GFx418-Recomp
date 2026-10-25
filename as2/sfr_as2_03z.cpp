// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton constructor (gap recovery
// of sfr_as2_03).
// MS2-UNIT: sfr_as2_03z
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918830-0x14291892d .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_button.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The button side of a button character: exe vftables 0x143217980 (AvmInteractiveObjBase), 0x143217ac8
// (ObjectInterface) and 0x143217b70 (AvmButtonBase); the other units carry partial local copies.
// AvmCharacter and AvmButtonBase both bring the AvmInteractiveObjBase slots, so the button overrides every one of
// them (the exe has a copy plus a -0x30 adjustor thunk for each); the trivial ones are the exe's inline stubs.
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    AvmButton(Button* pbutton);

    // AvmDisplayObjBase
    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase() { return static_cast<AvmCharacter*>(this); } // 0x142990e10
    virtual AvmSpriteBase*              ToAvmSpriteBase()         { return 0; }    // 0x142990ea0
    virtual AvmButtonBase*              ToAvmButttonBase()        { return this; } // 0x142990cc0
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()      { return 0; }    // 0x142990ee0
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()  { return 0; }    // 0x142990dd0
    virtual const char* GetAbsolutePath(String* ppath) const { return AvmCharacter::GetAbsolutePath(ppath); } // 0x1429494b0
    virtual bool        HasEventHandler(const EventId&) const { return false; } // 0x14295d4e0
    virtual bool        OnEvent(const EventId&) { return false; }               // 0x14296b480
    virtual void        OnEventLoad();                                          // 0x14296b820 (folded with OnEventLoadBase)
    virtual void        OnEventUnload() {}                                      // 0x14296bb90
    virtual bool        OnUnloading(bool);                                      // 0x14296d120

    // AvmCharacter
    virtual Object* GetASObject();       // 0x142949430 (sfr_as2_05v)
    virtual Object* GetASObject() const; // 0x142949440 (sfr_as2_05v)

    // AvmInteractiveObjBase
    virtual bool     ActsAsButton() const { return true; } // 0x14292e040
    virtual unsigned GetCursorType() const;                // 0x14294a370
    virtual void     CloneInternalData(const InteractiveObject* src);         // 0x142934820
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar); // 0x142935c70
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt) // 0x14296bd40
    {
        AvmCharacter::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    }
    virtual void OnGettingKeyboardFocus(unsigned, FocusMovedType) {} // 0x14296c140
    virtual bool OnKeyEvent(const EventId&, int*) { return false; }   // 0x14296c190
    virtual bool OnLosingKeyboardFocus(InteractiveObject*, unsigned, FocusMovedType = GFx_FocusMovedByKeyboard)
    {
        return true; // 0x14296c1e0
    }
    // Buttons take the focus from the keyboard and script, not from a click.
    virtual bool IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const
    {
        return fmt != GFx_FocusMovedByMouse; // 0x1429658a0
    }
    virtual bool IsTabable() const { return AvmCharacter::IsTabable(); } // 0x142965f10

    // AvmButtonBase
    virtual void CreateCharacters() { RecreateCharacters(ButtonRecord::MouseUp); } // 0x142935e90
    virtual bool OnMouseEvent(const EventId& event);                                // 0x14296c430
    virtual bool OnButtonKeyEvent(const EventId& id, int* pkeyMask);                // 0x14296b2b0
    virtual void SwitchState(ButtonRecord::MouseState state) { RecreateCharacters(state); } // 0x142990c30

    // AvmCharacter
    virtual unsigned GetStandardMemberBitMask() const { return 0xefffafcf; } // 0x142956050
    virtual bool     GetStandardMember(StandardMember member, Value* pval, bool opcodeFlag) const; // 0x142954ed0

    // ObjectInterface
    virtual ObjectType GetObjectType() const { return Object_Button; } // 0x142954150
    virtual bool       GetMember(Environment* penv, const ASString& name, Value* pval); // 0x14294bea0

    // Recreates the state characters for the mouse state (0x1429729b0).
    void RecreateCharacters(ButtonRecord::MouseState mouseState);
};

// The prototype comes from the environment of the nearest movie clip above the button.
// MS2-FUNCTIONAL: the exe stores the intermediate vftables and schedules the loop differently
// @0x142918830
AvmButton::AvmButton(Button* pbutton)
    : AvmCharacter(pbutton)
{
    Environment* penv = 0;
    for (InteractiveObject* pparent = pbutton->GetParent(); pparent; pparent = pparent->GetParent())
    {
        if (pparent->InteractiveObject::Flags & InteractiveObject::Mask_MovieClip)
        {
            penv = AS2::ToAvmCharacter(pparent)->GetASEnvironment();
            break;
        }
    }
    pProto = GetAS2Root()->pGlobalContext->GetActualPrototype(penv, ASBuiltin_Button);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7AvmButton@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143217980
// MS2-PIN: ??_7AvmButton@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217ac8
// MS2-PIN: ??_7AvmButton@AS2@GFx@Scaleform@@6B@ 0x143217b70
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmButtonBase@GFx@Scaleform@@6B@ 0x14317db08
