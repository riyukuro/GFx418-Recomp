// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 large builtin-class constructors:
// KeyCtorFunction. Sub-unit of sfr_as2_03 (lane sfr31, taken over from sfr32).
// MS2-UNIT: sfr_as2_03k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291d1e0-0x14291dbe0 .text$mn

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


#include "../include/gfx/as2/as2_keyobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// SDK Object::SetConstMemberRaw (inline in the SDK header): the name, value and flags are temporaries.
// The flags are SetMemberRaw's default argument.
static inline bool KeySetConstMemberRaw(ObjectInterface* pobj, ASStringContext* psc, const char* pname, const Value& val)
{
    return pobj->SetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val);
}

// CFunctionObject(psc, func) (0x142919df0) as the exe inlines it here: Object(psc) and Set__proto__ stay calls.
inline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc)
{
}
inline CFunctionObject::CFunctionObject(ASStringContext* psc, CFunctionPtr func, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(func)
{
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
}

// MS2-FUNCTIONAL: same length as the exe (2559 bytes); this/this+0x20/psc rotate across rbx/rdi/rsi, and the pMovieRoot store sits before the vptr stores. No source form (body assign, pobj local, helper forms) reproduces the exe allocation.
// @0x14291d1e0
KeyCtorFunction::KeyCtorFunction(ASStringContext* psc, MovieImpl* pmovie)
    : CFunctionObject(psc, GlobalCtor, ObjectInlineCtorTag()), pMovieRoot(pmovie)
{
    for (int i = 0; i < 16; i++)
    {
        States[i].LastKeyCode   = 0;
        States[i].LastAsciiCode = 0;
        States[i].LastWcharCode = 0;
    }
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
    KeySetConstMemberRaw(this, psc, "BACKSPACE", Value(8));
    KeySetConstMemberRaw(this, psc, "CAPSLOCK", Value(0x14));
    KeySetConstMemberRaw(this, psc, "CONTROL", Value(0x11));
    KeySetConstMemberRaw(this, psc, "DELETEKEY", Value(0x2e));
    KeySetConstMemberRaw(this, psc, "DOWN", Value(0x28));
    KeySetConstMemberRaw(this, psc, "END", Value(0x23));
    KeySetConstMemberRaw(this, psc, "ENTER", Value(0xd));
    KeySetConstMemberRaw(this, psc, "ESCAPE", Value(0x1b));
    KeySetConstMemberRaw(this, psc, "HOME", Value(0x24));
    KeySetConstMemberRaw(this, psc, "INSERT", Value(0x2d));
    KeySetConstMemberRaw(this, psc, "LEFT", Value(0x25));
    KeySetConstMemberRaw(this, psc, "PGDN", Value(0x22));
    KeySetConstMemberRaw(this, psc, "PGUP", Value(0x21));
    KeySetConstMemberRaw(this, psc, "RIGHT", Value(0x27));
    KeySetConstMemberRaw(this, psc, "SHIFT", Value(0x10));
    KeySetConstMemberRaw(this, psc, "SPACE", Value(0x20));
    KeySetConstMemberRaw(this, psc, "TAB", Value(9));
    KeySetConstMemberRaw(this, psc, "UP", Value(0x26));
    NameFunction::AddConstMembers(this, psc, FunctionTable, 0);
    pmovie->SetKeyboardListener(this);
}

// @0x142942da0
void KeyCtorFunction::Finalize_GC()
{
    pMovieRoot = 0;
    Object::Finalize_GC();
}

}}}

// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c8c8
// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c950
// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6B@ 0x14321c9f8
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
