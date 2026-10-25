// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Environment constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291b930-0x14291bbca .text$mn

#include "../include/gfx/as2/as2_action.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe inlines each stack's first page with the array's minimum capacity (16 slots) allocated
// inside the constructor; the header's PushBack grows the array through its out-of-line Reserve
// @0x14291b930
Environment::Environment()
    : Target(0), pASLogger(0), ExecutionNestingLevel(0), FuncCallNestingLevel(0), Unrolling(false),
      IsInvalidTarget(false)
{
    ThrowingValue.SetUnset();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x143215ad0
// MS2-PIN: ??_7Environment@AS2@GFx@Scaleform@@6B@ 0x143215ae0
