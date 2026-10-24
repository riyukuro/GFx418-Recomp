// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 large builtin-class constructors:
// TextFieldProto. Sub-unit of sfr_as2_03 (lane sfr31, taken over from sfr32).
// MS2-UNIT: sfr_as2_03j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142921710-0x142922650 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_array.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/render/text_core.h"
#include "../include/render/text_fontmanager.h"
#include "../include/render/render_font.h"
#include "../include/kernel/sf_std.h"


namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL scheduling of the Value/PropFlags temporaries around the unrolled member sets
// @0x142921710
TextFieldProto::TextFieldProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<TextFieldObject>(psc, pprototype, constructor)
{
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("scroll"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("hscroll"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("maxscroll"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("maxhscroll"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("background"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("backgroundColor"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("border"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("borderColor"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("bottomScroll"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("mouseWheelEnabled"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("antiAliasType"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("autoSize"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("condenseWhite"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("embedFonts"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("html"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("htmlText"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("length"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("maxChars"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("multiline"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("password"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("restrict"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("selectable"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("styleSheet"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("tabIndex"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("text"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("textColor"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("textHeight"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("textWidth"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("type"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("variable"), unset, flags);
    }
    {
        PropFlags flags(2);
        Value unset(Value::UNSET);
        pobj->SetMemberRaw(psc, psc->CreateConstString("wordWrap"), unset, flags);
    }
}

}}}

// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218678
// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432186c0
// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6B@ 0x143218768
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218580
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432185c8
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143218670
