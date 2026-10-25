// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 constructors of the character
// binding and the function objects built from an environment (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918930-0x142918976 .text$mn
// MS2-RANGE: 0x142919db0-0x142919de3 .text$mn
// MS2-RANGE: 0x14291c0c0-0x14291c0eb .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_eventid.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142918930
AvmCharacter::AvmCharacter(InteractiveObject* pdispObj)
    : pDispObj(pdispObj)
{
    pdispObj->BindAvmObj(this);
}

// @0x14291c0c0
FunctionObject::FunctionObject(Environment* penv)
    : Object(penv)
{
}

// @0x142919db0
CFunctionObject::CFunctionObject(Environment* penv)
    : FunctionObject(penv), pFunction(0)
{
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143215b00
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215c48
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
