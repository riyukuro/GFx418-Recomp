// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextFieldObject constructor
// binding a text field character (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429215f0-0x142921708 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// GlobalContext::GetGC (exe 0x14294afc0), which the exe inlines here.
static inline ASRefCountCollector* Sfr03xGetGC(GlobalContext* gCtxt)
{
    return gCtxt->pMovieRoot ? static_cast<MovieRoot*>(gCtxt->pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}

// Object::Set__proto__ (exe 0x140007ba0) as the exe inlines it: SetMemberRaw stays a virtual call.
static inline void Sfr03xSetProto(ObjectInterface* pobj, ASStringContext* psc, Object* protoObj)
{
    if (!pobj->pProto)
        pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                           PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pobj->pProto = protoObj;
}

// The object takes the text field character's own __proto__, not the global TextField prototype.
// @0x1429215f0
TextFieldObject::TextFieldObject(GlobalContext* gCtxt, InteractiveObject* ptextField)
    : Object(Sfr03xGetGC(gCtxt)), pTextField(ptextField)
{
    AvmCharacter* pavmCh = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(ptextField->GetAvmObjImpl()));
    ASStringContext* psc = pavmCh->GetASEnvironment()->GetSC();
    Sfr03xSetProto(this, psc, pavmCh->Get__proto__());
    pIMECompositionStringStyles = 0;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8
