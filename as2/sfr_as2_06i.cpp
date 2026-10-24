// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): Environment::SetVariableRaw and IntervalTimer::Start.
// MS2-UNIT: sfr_as2_06i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298da70-0x14298dbf5 .text$mn
// MS2-RANGE: 0x14298fe90-0x14298fe9f .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// A plain name is set on the innermost with() scope that has it, else on the local or the target.
// MS2-FUNCTIONAL: the exe keeps the scope lookups in different registers
// @0x14298da70
void Environment::SetVariableRaw(const ASString& varname, const Value& val, const WithStackArray* pwithStack)
{
    if (pwithStack)
    {
        for (SPInt i = int(pwithStack->GetSize()) - 1; i >= 0; i--)
        {
            const WithStackEntry& entry = (*pwithStack)[i];
            ObjectInterface*      iface;
            if (entry.IsObject)
                iface = entry.pObject;
            else
            {
                InteractiveObject* pchar = entry.pCharacter;
                iface                    = pchar ? ToAvmCharacter(pchar) : 0;
            }
            Value found;
            if (iface && iface->GetMember(this, varname, &found))
            {
                iface->SetMember(this, varname, val);
                return;
            }
        }
    }
    Value* plocal = const_cast<Value*>(FindLocal(varname));
    if (plocal)
        *plocal = val;
    else
        ToAvmCharacter(Target)->SetMember(this, varname, val);
}

// The timer fires its interval from now on.
// @0x14298fe90
void IntervalTimer::Start(MovieImpl* proot)
{
    InvokeTime = proot->TimeElapsed + Interval;
}

}}} // namespace Scaleform::GFx::AS2
