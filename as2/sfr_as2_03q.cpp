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

// AvmCharacter::GetASEnvironment (0x1429493c0, sfr_as2_05v), which the exe inlines here (as in the AvmButton ctor).
static SF_FORCEINLINE Environment* MS2_CharEnv(AvmCharacter* pc)
{
    for (InteractiveObject* p = pc->GetDispObj()->GetParent(); p; p = p->GetParent())
    {
        if (p->IsSprite())
            return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(p->GetAvmObjImpl()))->GetASEnvironment();
    }
    return 0;
}

// The AvmCharacter ctor (0x142918930), which the exe also inlines here.
inline AvmCharacter::AvmCharacter(InteractiveObject* pdispObj, ObjectInlineCtorTag)
    : pDispObj(pdispObj)
{
    pdispObj->BindAvmObj(this);
}

// @0x142918b50
AvmTextField::AvmTextField(TextField* ptf)
    : AvmCharacter(reinterpret_cast<InteractiveObject*>(ptf), ObjectInlineCtorTag()),
      VariableName(reinterpret_cast<InteractiveObject*>(ptf)->GetStringManager()->CreateString(
          (*reinterpret_cast<TextFieldDef**>(reinterpret_cast<UByte*>(ptf) + 0xd8))->VariableName))
{
    if (!VariableName.IsEmpty())
        *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(ptf) + 0xfc) |= 0x8000;
    pProto = GetAS2Root()->pGlobalContext->GetActualPrototype(MS2_CharEnv(this), ASBuiltin_TextField);
    AsBroadcaster::InitializeInstance(FromCharacter(reinterpret_cast<InteractiveObject*>(ptf))->GetASEnvironment()->GetSC(),
                                      static_cast<ObjectInterface*>(this));
    AsBroadcaster::AddListener(FromCharacter(reinterpret_cast<InteractiveObject*>(ptf))->GetASEnvironment(),
                               static_cast<ObjectInterface*>(this), static_cast<ObjectInterface*>(this));
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
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
