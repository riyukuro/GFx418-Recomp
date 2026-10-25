// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 the text field's script side
// constructor (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918b50-0x142918cdb .text$mn
// MS2-RANGE: 0x142956080-0x142956085 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe frame keeps the field's string node and prototype in different temporaries
// @0x142918b50
AvmTextField::AvmTextField(TextField* ptf)
    : AvmCharacter(reinterpret_cast<InteractiveObject*>(ptf)),
      VariableName(reinterpret_cast<InteractiveObject*>(ptf)->GetStringManager()->CreateString(
          (*reinterpret_cast<TextFieldDef**>(reinterpret_cast<UByte*>(ptf) + 0xd8))->VariableName.ToCStr(),
          (*reinterpret_cast<TextFieldDef**>(reinterpret_cast<UByte*>(ptf) + 0xd8))->VariableName.GetSize()))
{
    if (VariableName.GetLength() != 0)
        *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(ptf) + 0xfc) |= 0x8000;
    Environment* penv = 0;
    for (InteractiveObject* p = GetDispObj()->GetParent(); p; p = p->GetParent())
        if (p->IsSprite())
        {
            penv = AS2::ToAvmCharacter(p)->GetASEnvironment();
            break;
        }
    pProto = GetAS2Root()->pGlobalContext->GetActualPrototype(penv, ASBuiltin_TextField);
    AsBroadcaster::InitializeInstance(this->GetASEnvironment()->GetSC(), static_cast<ObjectInterface*>(this));
    AsBroadcaster::AddListener(this->GetASEnvironment(), static_cast<ObjectInterface*>(this),
                               static_cast<ObjectInterface*>(this));
}

// @0x142956080
unsigned AvmTextField::GetStandardMemberBitMask() const
{
    return 0x627dafcf;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143215b00
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215c48
// MS2-PIN: ??_7AvmTextField@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x1432181a0
// MS2-PIN: ??_7AvmTextField@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432182e8
// MS2-PIN: ??_7AvmTextField@AS2@GFx@Scaleform@@6B@ 0x143218390
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmTextFieldBase@GFx@Scaleform@@6B@ 0x14317e508
