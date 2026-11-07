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
#include "../include/gfx/text_editorkit.h"


namespace Scaleform { namespace GFx { namespace AS2 {

// SDK Object::SetConstMemberRaw (inline in the SDK header): the name, value and flags are temporaries.
static inline bool TfSetConstMemberRaw(Object* pobj, ASStringContext* psc, const char* pname, const Value& val, const PropFlags& flags)
{
    return pobj->SetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val, flags);
}

// AsBroadcaster::InitializeProto (out of line at 0x142961fe0), inlined by the exe here.
static __forceinline bool TfInitializeProto(ASStringContext* psc, ObjectInterface* pobj)
{
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    return true;
}

// The prototype's TextFieldObject base as the exe inlines it (out of line at 0x142921520).
inline TextFieldObject::TextFieldObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc), pIMECompositionStringStyles(0)
{
    Set__proto__(psc, pprototype);
}

// @0x142921710
TextFieldProto::TextFieldProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<TextFieldObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    TfInitializeProto(psc, this);
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
    TfSetConstMemberRaw(this, psc, "scroll", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "hscroll", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "maxscroll", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "maxhscroll", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "background", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "backgroundColor", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "border", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "borderColor", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "bottomScroll", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "mouseWheelEnabled", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "antiAliasType", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "autoSize", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "condenseWhite", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "embedFonts", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "html", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "htmlText", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "length", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "maxChars", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "multiline", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "password", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "restrict", Value(Value::NULLTYPE), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "selectable", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "styleSheet", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "tabIndex", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "text", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "textColor", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "textHeight", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "textWidth", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "type", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "variable", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    TfSetConstMemberRaw(this, psc, "wordWrap", Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontDelete));
    // SDK GAS_TextFieldExtFunctionTable: in the exe it follows FunctionTable's terminator (0x1432144a0).
    InitFunctionMembers(this, psc, FunctionTable + 9, PropFlags(PropFlags::PropFlag_DontEnum));
    SetIMECompositionStringStyles(Text::CompositionString::GetDefaultStyles());
}

}}}

// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218678
// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432186c0
// MS2-PIN: ??_7TextFieldProto@AS2@GFx@Scaleform@@6B@ 0x143218768
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218580
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432185c8
// MS2-PIN: ??_7?$Prototype@VTextFieldObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143218670
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8
