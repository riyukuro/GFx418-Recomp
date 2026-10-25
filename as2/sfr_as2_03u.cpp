// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 FnCall constructor taking the
// this value (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03u
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291be60-0x14291c005 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe builds the function ref by hand (type switch, copy and release of both halves) before
// assigning it; this goes through ToFunction and the ref's assignment
// @0x14291be60
FnCall::FnCall(Value* res, const Value& thisVal, Environment* penv, int nargs, int firstArgBottomIndex)
    : Result(res), ThisPtr(thisVal.ToObjectInterface(penv)), Env(penv), NArgs(nargs),
      FirstArgBottomIndex(firstArgBottomIndex)
{
    if (thisVal.GetType() == Value::FUNCTION || thisVal.GetType() == Value::FUNCTIONNAME)
        ThisFunctionRef = thisVal.ToFunction(penv);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
