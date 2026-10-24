// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GenericDisplayObj bounds / hit
// test and the text field style sheet getter, gap functions of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429498a0-0x1429498f7 .text$mn
// MS2-RANGE: 0x142954cb0-0x142954d07 .text$mn
// MS2-RANGE: 0x1429561e0-0x142956228 .text$mn
// MS2-RANGE: 0x142956410-0x1429565ac .text$mn
// MS2-RANGE: 0x142956ad0-0x142956b03 .text$mn

#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_genericdisplayobj.h"

// The text field's style data (exe 0x1425b7e60).
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);

namespace Scaleform { namespace GFx { namespace AS2 {

bool AvmTextFieldBase_HasStyleSheet(const void* self); // sfr_as2_06

// The style manager of the text field's style sheet, 0 without one. The exe tags this with AvmTextField's vftable
// slot; the TextField lies 0x10 bytes before the part it is called on.
// MS2-FUNCTIONAL: HasStyleSheet is a virtual call in the exe, called directly here
// @0x1429561e0
const void* AvmTextFieldBase_GetStyleSheet(const void* self)
{
    UPInt sheet = FUN_1425b7e60(*reinterpret_cast<const UPInt*>(static_cast<const UByte*>(self) - 0x10));
    if (AvmTextFieldBase_HasStyleSheet(self))
        return reinterpret_cast<const UByte*>(*reinterpret_cast<const UPInt*>(sheet + 0x40)) + 0x68;
    return 0;
}

// MS2-FUNCTIONAL: the exe inlines the TextFieldObject ctor and the Set__proto__ member creation
// @0x142956410
TextFieldObject* AvmTextField::GetTextFieldASObject()
{
    if (!ASTextFieldObj)
        ASTextFieldObj = *SF_HEAP_AUTO_NEW(this) TextFieldObject(GetGC(), pDispObj);
    return ASTextFieldObj;
}

// @0x1429498a0
RectF GenericDisplayObj::GetBounds(const Matrix& t) const
{
    return t.EncloseTransform(pDef->GetBoundsLocal());
}

// @0x142954cb0
RectF GenericDisplayObj::GetRectBounds(const Matrix& t) const
{
    return t.EncloseTransform(pDef->GetRectBoundsLocal());
}

// @0x142956ad0
DisplayObjectBase::TopMostResult GenericDisplayObj::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    pdescr->pResult = GetTopMostMouseEntityDef(pDef, pt, pdescr->TestAll, pdescr->pIgnoreMC);
    return pdescr->pResult ? TopMost_Found : TopMost_FoundNothing;
}

}}} // namespace Scaleform::GFx::AS2
