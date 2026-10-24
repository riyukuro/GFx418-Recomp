// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton::GetMember of
// sfr_as2_05 (gap recovery, lane sfr36).
// MS2-UNIT: sfr_as2_05p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294bea0-0x14294bfdd .text$mn

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

    virtual bool GetMember(Environment* penv, const ASString& name, Value* pval);
};

// Standard members (_x, _alpha, ...) first, then the button's AS object; until that exists the prototype stands
// in (__proto__ itself is answered here). _global is visible from every character.
// @0x14294bea0
bool AvmButton::GetMember(Environment* penv, const ASString& name, Value* pval)
{
    if (name.GetHashFlags() & ASConstString::Flag_StandardMember)
        if (GetStandardMember(GetStandardMemberConstant(name), pval, 0))
            return true;

    if (ASButtonObj)
        return ASButtonObj->GetMember(penv, name, pval);

    if (penv && name == penv->GetBuiltin(ASBuiltin___proto__))
    {
        pval->SetAsObject(pProto);
        return true;
    }
    if (pProto && pProto->GetMember(penv, name, pval))
        return true;
    if (penv && name == penv->GetBuiltin(63)) // _global
    {
        pval->SetAsObject(penv->GetSC()->pContext->pGlobal);
        return true;
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS2
