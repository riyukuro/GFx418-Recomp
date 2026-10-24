// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton gap functions of
// sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142943360-0x14294347d .text$mn
// MS2-RANGE: 0x142949960-0x142949b12 .text$mn
// MS2-RANGE: 0x14294a370-0x14294a41f .text$mn
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217c48
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217c90

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The script side of a button (partial local copy; the other units carry their own).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual unsigned GetCursorType() const;

private:
    ButtonObject*     GetButtonASObject();
    Button::CharToRec FindCharacterAndRemove(const ButtonRecord& rec);
};

inline ButtonObject::ButtonObject(GlobalContext* pgc, InteractiveObject* pbutton)
    : Object(pgc->GetGC()), pButton(pbutton)
{
    AvmCharacter* pavm = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pbutton->GetAvmObjImpl()));
    ButtonObject::Set__proto__(pavm->GetASEnvironment()->GetSC(), pavm->Get__proto__());
}

// The hand while the button is enabled and its useHandCursor (looked up through the prototype chain) is true.
// MS2-FUNCTIONAL: same lookups, the exe keeps the value object in the frame differently
// @0x14294a370
unsigned AvmButton::GetCursorType() const
{
    const Environment* penv = GetASEnvironment();
    Value              val;
    if (penv && (pDispObj->Flags & InteractiveObject::Mask_Enabled))
    {
        ObjectInterface* pobj = 0;
        if (ASButtonObj)
            pobj = const_cast<AvmButton*>(this);
        else if (pProto)
            pobj = pProto;
        if (pobj)
            pobj->GetMember(const_cast<Environment*>(penv), penv->GetBuiltin(ASBuiltin_useHandCursor), &val);
        if (val.ToBool(penv))
            return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: the exe inlines the ButtonObject ctor and the Set__proto__ member creation
// @0x142949960
ButtonObject* AvmButton::GetButtonASObject()
{
    if (!ASButtonObj)
        ASButtonObj = *SF_HEAP_AUTO_NEW(this) ButtonObject(GetGC(), pDispObj);
    return ASButtonObj;
}

// The state character made from rec leaves its state (the Hit state holds none): found by record.
// MS2-FUNCTIONAL: element removal through the array class instead of the inlined memmove
// @0x142943360
Button::CharToRec AvmButton::FindCharacterAndRemove(const ButtonRecord& rec)
{
    // Button::States (+0xe0, 0x20 bytes each) is protected.
    struct StateView
    {
        void*                  pRenNode;
        Button::StateCharArray Characters;
    };
    StateView* pstates = reinterpret_cast<StateView*>(reinterpret_cast<UByte*>(pDispObj) + 0xe0);
    for (unsigned state = 0; state < 4; ++state)
    {
        if (state == Button::Hit)
            continue;
        Button::StateCharArray& chars = pstates[state].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            if (chars[i].Record == &rec)
            {
                Button::CharToRec found = chars[i];
                chars.RemoveAt(i);
                return found;
            }
        }
    }
    Button::CharToRec none;
    none.Record = 0;
    return none;
}

}}} // namespace Scaleform::GFx::AS2
