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

// MS2-FUNCTIONAL scheduling of the Value/PropFlags temporaries around the unrolled member sets
// @0x14291d1e0
KeyCtorFunction::KeyCtorFunction(ASStringContext* psc, MovieImpl* pmovie)
    : CFunctionObject(psc, GlobalCtor), pMovieRoot(pmovie)
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
    {
        PropFlags flags(0);
        Value val(8);
        pobj->SetMemberRaw(psc, psc->CreateConstString("BACKSPACE"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x14);
        pobj->SetMemberRaw(psc, psc->CreateConstString("CAPSLOCK"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x11);
        pobj->SetMemberRaw(psc, psc->CreateConstString("CONTROL"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x2e);
        pobj->SetMemberRaw(psc, psc->CreateConstString("DELETEKEY"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x28);
        pobj->SetMemberRaw(psc, psc->CreateConstString("DOWN"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x23);
        pobj->SetMemberRaw(psc, psc->CreateConstString("END"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0xd);
        pobj->SetMemberRaw(psc, psc->CreateConstString("ENTER"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x1b);
        pobj->SetMemberRaw(psc, psc->CreateConstString("ESCAPE"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x24);
        pobj->SetMemberRaw(psc, psc->CreateConstString("HOME"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x2d);
        pobj->SetMemberRaw(psc, psc->CreateConstString("INSERT"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x25);
        pobj->SetMemberRaw(psc, psc->CreateConstString("LEFT"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x22);
        pobj->SetMemberRaw(psc, psc->CreateConstString("PGDN"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x21);
        pobj->SetMemberRaw(psc, psc->CreateConstString("PGUP"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x27);
        pobj->SetMemberRaw(psc, psc->CreateConstString("RIGHT"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x10);
        pobj->SetMemberRaw(psc, psc->CreateConstString("SHIFT"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x20);
        pobj->SetMemberRaw(psc, psc->CreateConstString("SPACE"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(9);
        pobj->SetMemberRaw(psc, psc->CreateConstString("TAB"), val, flags);
    }
    {
        PropFlags flags(0);
        Value val(0x26);
        pobj->SetMemberRaw(psc, psc->CreateConstString("UP"), val, flags);
    }
    NameFunction::AddConstMembers(pobj, psc, FunctionTable, 0);
    pmovie->SetKeyboardListener(this);
}

// MS2-FUNCTIONAL: exe tail-jumps into Object::Finalize_GC
// @0x142942da0
void KeyCtorFunction::Finalize_GC()
{
    pMovieRoot = 0;
    Object::Finalize_GC();
}

}}}

// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c8c8
// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c950
// MS2-PIN: ??_7KeyCtorFunction@AS2@GFx@Scaleform@@6BIListener@KeyboardState@23@@ 0x14321c9f8
