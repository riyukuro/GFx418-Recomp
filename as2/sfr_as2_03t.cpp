// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Point copy constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03t
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291fcf0-0x14291fe51 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_pointobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14291fcf0
PointObject::PointObject(Environment* penv, PointObject* psrc)
    : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    Set__proto__(psc, penv->GetPrototype(ASBuiltin_Point));
    Value params[Point_NumProperties];
    static_cast<ObjectInterface&>(*psrc).GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), &params[Point_X]);
    static_cast<ObjectInterface&>(*psrc).GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), &params[Point_Y]);
    ObjectInterface* pif = static_cast<ObjectInterface*>(this);
    pif->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), params[Point_X]);
    pif->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), params[Point_Y]);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7PointObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a100
// MS2-PIN: ??_7PointObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a148
