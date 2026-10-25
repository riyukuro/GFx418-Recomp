// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Stage class constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ah
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142920950-0x142920bd8 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe's vftable stores and member order are followed; the extension strings are made as the
// exe makes them
// @0x142920950
StageCtorFunction::StageCtorFunction(ASStringContext* psc, MovieImpl* pmovie) : CFunctionObject(psc, GlobalCtor)
{
    pMovieRoot = pmovie;
    AsBroadcaster::Initialize(psc, this);
    ObjectInterface* pobj = this;
    {
        PropFlags flags(0);
        Value     unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_width), unset, flags);
    }
    {
        PropFlags flags(0);
        Value     unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_height), unset, flags);
    }
    {
        Value     unset(Value::UNSET);
        PropFlags flags(0);
        pobj->SetMemberRaw(psc, psc->CreateConstString("scaleMode"), unset, flags);
    }
    {
        Value     unset(Value::UNSET);
        PropFlags flags(0);
        pobj->SetMemberRaw(psc, psc->CreateConstString("align"), unset, flags);
    }
    {
        Value     yes(true);
        PropFlags flags(0);
        pobj->SetMemberRaw(psc, psc->CreateConstString("showMenu"), yes, flags);
    }
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7StageCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a7f0
// MS2-PIN: ??_7StageCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a878
