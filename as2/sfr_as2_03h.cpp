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

// The exe inlines CFunctionObject(psc) here (Object(psc) call, then pFunction = 0).
inline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc)
{
}

inline CFunctionObject::CFunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(0)
{
}

// SDK AS2_Capabilities.cpp header inlines (SF_OS_WIN32 branches).
inline ASString CapsManufacturer(ASStringContext* psc) { return psc->CreateConstString("Scaleform Windows"); }
inline ASString CapsOS(ASStringContext* psc) { return psc->CreateConstString("Windows"); }
inline ASString CapsVersion(ASStringContext* psc) { return psc->CreateConstString("WIN 8,0,0,0"); }

// MS2-FUNCTIONAL: LTCG alias floor. At the six Value(ASString temp) sites the exe sinks the ASString AddRef past the
// Value stores and merges it with the Value AddRef (add [node+0x18],2; we emit two incs, 2 bytes each = the 12-byte gap).
// A __declspec(restrict) CreateConstStringNode does not reproduce it. The vptr/flags store order at entry also differs.
// @0x142919ee0
CapabilitiesCtorFunction::CapabilitiesCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, ObjectInlineCtorTag())
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
    Object::SetMemberRaw(psc, psc->CreateConstString("language"), psc->CreateConstString("en"), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("manufacturer"), CapsManufacturer(psc), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("os"), CapsOS(psc), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("pixelAspectRatio"), Value(1), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("playerType"), psc->CreateConstString("External"), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("screenColor"), psc->CreateConstString("color"), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("screenDPI"), Value(72), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("version"), CapsVersion(psc), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("windowlessDisable"), no, flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("screenResolutionX"), Value(Value::UNSET), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("screenResolutionY"), Value(Value::UNSET), flags);
    Object::SetMemberRaw(psc, psc->CreateConstString("serverString"), Value(Value::UNSET), flags);
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7CapabilitiesCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e6d8
// MS2-PIN: ??_7CapabilitiesCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e760
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
