// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GAS_Invoke with the receiver
// as a value, gap function of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142946a80-0x142946d00 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe inlines the FnCall destructor
// @0x142946a80
bool GAS_Invoke(const Value& method, Value* presult, const Value& thisVal, Environment* penv, int nargs,
                int firstArgBottomIndex, const char* pmethodName)
{
    FunctionRef func = method.ToFunction(penv);
    if (presult)
        presult->SetUndefined();
    if (!func.IsNull())
    {
        func.Invoke(FnCall(presult, thisVal, penv, nargs, firstArgBottomIndex), pmethodName);
        return true;
    }
    if (penv && penv->IsVerboseActionErrors())
    {
        if (thisVal.ToCharacter(penv))
            penv->LogScriptError("Invoked method %s.%s is not a function",
                                 thisVal.ToCharacter(penv)->GetCharacterHandle()->NamePath.ToCStr(),
                                 pmethodName ? pmethodName : "<unknown>");
        else
            penv->LogScriptError("Invoked method %s is not a function", pmethodName ? pmethodName : "<unknown>");
    }
    return false;
}

} } }
