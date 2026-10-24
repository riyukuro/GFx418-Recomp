// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 large builtin-class constructors:
// TextFormatObject(Environment*). Sub-unit of sfr_as2_03 (lane sfr31, taken over from sfr32).
// MS2-UNIT: sfr_as2_03i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429226d0-0x142923030 .text$mn

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
// @0x1429226d0
TextFormatObject::TextFormatObject(Environment* penv) : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    ::new (Data68) Render::Text::TextFormat(psc->GetHeap());
    ::new (Data68 + 9) Render::Text::ParagraphFormat();
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_TextFormat));
    ObjectInterface* pobj = this;
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("align"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("blockIndent"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("bold"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("bullet"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("color"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("font"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("indent"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("italic"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("leading"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("leftMargin"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("rightMargin"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("size"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("tabStops"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("target"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("underline"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("url"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("kerning"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("letterSpacing"), nul, flags);
    }
    {
        PropFlags flags(2);
        Value nul(Value::NULLTYPE);
        pobj->SetMemberRaw(psc, psc->CreateConstString("alpha"), nul, flags);
    }
}

}}}
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d688
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d6d0
