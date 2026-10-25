// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 BitmapData constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03s
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918ef0-0x142919053 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/as2/as2_object.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Inlined in the exe (no out-of-line copy), as in sfr_as2_03; the deleting dtor of the vftables built here needs it.
inline BitmapData::~BitmapData()
{
}

// The exe inlines commonInit here (0x142994e90 is the same body out of line).
// @0x142918ef0
BitmapData::BitmapData(Environment* penv) : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    ObjectInterface* pif = static_cast<ObjectInterface*>(this);
    pif->Set__proto__(psc, penv->GetPrototype(ASBuiltin_BitmapData));
    pif->SetMemberRaw(psc, penv->CreateConstString("width"), Value(Value::UNSET), PropFlags::PropFlag_ReadOnly);
    pif->SetMemberRaw(psc, penv->CreateConstString("height"), Value(Value::UNSET), PropFlags::PropFlag_ReadOnly);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7BitmapData@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143219cf0
// MS2-PIN: ??_7BitmapData@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219d38
