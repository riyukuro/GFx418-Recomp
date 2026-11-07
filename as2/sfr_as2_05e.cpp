// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GenericDisplayObj bounds / hit
// test and the text field style sheet getter, gap functions of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429498a0-0x1429498f7 .text$mn
// MS2-RANGE: 0x142954cb0-0x142954d07 .text$mn
// MS2-RANGE: 0x1429561e0-0x142956228 .text$mn
// MS2-RANGE: 0x142956410-0x1429565ac .text$mn
// MS2-RANGE: 0x1429565c0-0x1429565ce .text$mn
// MS2-RANGE: 0x142956ad0-0x142956b03 .text$mn
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8

#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_genericdisplayobj.h"
#include "../include/gfx/text_stylesheet.h" // Text::StyleManager complete: StyleSheetObject's implicit destructor calls ~StyleManager

// The text field's style data (exe 0x1425b7e60).
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);

namespace Scaleform { namespace GFx { namespace AS2 {

// The style manager of the text field's style sheet, 0 without one. The body runs on the AvmTextFieldBase part
// (+0x30); HasStyleSheet is that part's vftable slot 24.
// @0x1429561e0
const Text::StyleManager* AvmTextField::GetStyleSheet() const
{
    UPInt sheet = FUN_1425b7e60(reinterpret_cast<UPInt>(pDispObj));
    if (HasStyleSheet())
        return reinterpret_cast<const Text::StyleManager*>(
            reinterpret_cast<const UByte*>(*reinterpret_cast<const UPInt*>(sheet + 0x40)) + 0x68);
    return 0;
}

namespace {

// The AS2 style sheet holder (AvmTextField::CSSHolder): the URL zones of CSSHolderBase, then the StyleSheet object.
struct AS2CSSHolderView
{
    void* const*      vfptr;
    UByte             BaseData[0x38];
    StyleSheetObject* pASStyleSheet; // +0x40
};

} // namespace

// AvmTextField::CSSHolder::GetTextStyleManager (vftable 0x143218188 slot 2): the style sheet's style manager, 0
// without a style sheet.
// @0x1429565c0
const void* CSSHolder_GetTextStyleManager(const void* pholder)
{
    const StyleSheetObject* psheet = static_cast<const AS2CSSHolderView*>(pholder)->pASStyleSheet;
    if (psheet)
        return psheet->CSS.Data;
    return 0;
}

// GlobalContext::GetGC (exe 0x14294afc0), which the exe inlines here.
static inline ASRefCountCollector* Sfr05eGetGC(GlobalContext* gCtxt)
{
    return gCtxt->pMovieRoot ? static_cast<MovieRoot*>(gCtxt->pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}

// Object::Set__proto__ (exe 0x140007ba0) as the exe inlines it: SetMemberRaw stays a virtual call.
static inline void Sfr05eSetProto(ObjectInterface* pobj, ASStringContext* psc, Object* protoObj)
{
    if (!pobj->pProto)
        pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                           PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pobj->pProto = protoObj;
}

// The TextFieldObject ctor (exe 0x1429215f0, sfr_as2_03x), which the exe inlines below.
inline TextFieldObject::TextFieldObject(GlobalContext* gCtxt, InteractiveObject* ptextField, ObjectInlineCtorTag)
    : Object(Sfr05eGetGC(gCtxt)), pTextField(ptextField)
{
    AvmCharacter* pavmCh = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(ptextField->GetAvmObjImpl()));
    ASStringContext* psc = pavmCh->GetASEnvironment()->GetSC();
    Sfr05eSetProto(this, psc, pavmCh->Get__proto__());
    pIMECompositionStringStyles = 0;
}

// @0x142956410
TextFieldObject* AvmTextField::GetTextFieldASObject()
{
    if (!ASTextFieldObj)
        ASTextFieldObj = *SF_HEAP_AUTO_NEW(this) TextFieldObject(GetGC(), pDispObj, ObjectInlineCtorTag());
    return ASTextFieldObj;
}

// The exe calls the definition's GetBoundsLocal (slot 7) and GetRectBoundsLocal (slot 8) without loading a
// morph ratio into xmm2.
struct Sfr05eBoundsLocalView
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual RectF GetBoundsLocal() const = 0;
    virtual RectF GetRectBoundsLocal() const = 0;
};

// @0x1429498a0
RectF GenericDisplayObj::GetBounds(const Matrix& t) const
{
    return t.EncloseTransform(reinterpret_cast<const Sfr05eBoundsLocalView*>(pDef.GetPtr())->GetBoundsLocal());
}

// @0x142954cb0
RectF GenericDisplayObj::GetRectBounds(const Matrix& t) const
{
    return t.EncloseTransform(reinterpret_cast<const Sfr05eBoundsLocalView*>(pDef.GetPtr())->GetRectBoundsLocal());
}

// @0x142956ad0
DisplayObjectBase::TopMostResult GenericDisplayObj::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    pdescr->pResult = GetTopMostMouseEntityDef(pDef, pt, pdescr->TestAll, pdescr->pIgnoreMC);
    return pdescr->pResult ? TopMost_Found : TopMost_FoundNothing;
}

}}} // namespace Scaleform::GFx::AS2

// data_rdata_sf_b names the vftable slot by its address
#pragma comment(linker, "/alternatename:?FUN_1429565c0@@YAXXZ=?CSSHolder_GetTextStyleManager@AS2@GFx@Scaleform@@YAPEBXPEBX@Z")
