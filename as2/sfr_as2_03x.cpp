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

// The object takes the text field character's own __proto__, not the global TextField prototype.
// MS2-FUNCTIONAL: the exe inlines Object::Set__proto__ (a virtual SetMemberRaw); same members
// @0x1429215f0
TextFieldObject::TextFieldObject(GlobalContext* gCtxt, InteractiveObject* ptextField)
    : Object(gCtxt->GetGC()), pTextField(ptextField), pIMECompositionStringStyles(0)
{
    AvmCharacter* pavmCh = AS2::ToAvmCharacter(ptextField);
    Set__proto__(pavmCh->GetASEnvironment()->GetSC(), pavmCh->Get__proto__());
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8
