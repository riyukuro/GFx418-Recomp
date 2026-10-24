// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 large builtin-class constructors:
// System.capabilities (CapabilitiesCtorFunction). Sub-unit of sfr_as2_03 (lane sfr31, taken over from sfr32).
// MS2-UNIT: sfr_as2_03h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142919ee0-0x14291aaf0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_array.h"
#include "../include/gfx/as2/as2_builtinobjects.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// System.capabilities: a function object holding the player's capability flags as members (0x70 bytes).
class CapabilitiesCtorFunction : public CFunctionObject
{
public:
    CapabilitiesCtorFunction(ASStringContext* psc);
    virtual ~CapabilitiesCtorFunction() {}     // exe 0x14292a1d0
    virtual Object* CreateNewObject(Environment*) const { return 0; } // exe 0x142936b00
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);      // exe 0x14294de70
    virtual bool SetMemberRaw(ASStringContext*, const ASString&, const Value&, const PropFlags&)
    { return false; } // exe 0x142988b50: read-only
};

// MS2-FUNCTIONAL register allocation (exe keeps a fourth callee-saved value live across the member-set calls)
// @0x142919ee0
CapabilitiesCtorFunction::CapabilitiesCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc)
{
    PropFlags flags(6);
    Value no(false);
    Object::SetMemberRaw(psc, psc->CreateConstString("avHardwareDisable"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasAccessibility"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasAudio"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasAudioEncoder"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasEmbeddedVideo"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasIME"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasMP3"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasPrinting"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasScreenBroadcast"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasScreenPlayback"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasStreamingAudio"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasStreamingVideo"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("hasVideoEncoder"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("isDebugger"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("localFileReadDisable"), no, flags);
    {
        Value v(psc->CreateConstString("en"));
        Object::SetMemberRaw(psc, psc->CreateConstString("language"), v, flags);
    }
    {
        Value v(psc->CreateConstString("Scaleform Windows"));
        Object::SetMemberRaw(psc, psc->CreateConstString("manufacturer"), v, flags);
    }
    {
        Value v(psc->CreateConstString("Windows"));
        Object::SetMemberRaw(psc, psc->CreateConstString("os"), v, flags);
    }
    {
        Value v(1);
        Object::SetMemberRaw(psc, psc->CreateConstString("pixelAspectRatio"), v, flags);
    }
    {
        Value v(psc->CreateConstString("External"));
        Object::SetMemberRaw(psc, psc->CreateConstString("playerType"), v, flags);
    }
    {
        Value v(psc->CreateConstString("color"));
        Object::SetMemberRaw(psc, psc->CreateConstString("screenColor"), v, flags);
    }
    {
        Value v(0x48);
        Object::SetMemberRaw(psc, psc->CreateConstString("screenDPI"), v, flags);
    }
    {
        Value v(psc->CreateConstString("WIN 8,0,0,0"));
        Object::SetMemberRaw(psc, psc->CreateConstString("version"), v, flags);
    }
    Object::SetMemberRaw(psc, psc->CreateConstString("windowlessDisable"), no, flags);
    {
        Value unset(Value::UNSET);
        Object::SetMemberRaw(psc, psc->CreateConstString("screenResolutionX"), unset, flags);
        Object::SetMemberRaw(psc, psc->CreateConstString("screenResolutionY"), unset, flags);
        Object::SetMemberRaw(psc, psc->CreateConstString("serverString"), unset, flags);
    }
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7CapabilitiesCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e6d8
// MS2-PIN: ??_7CapabilitiesCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e760
