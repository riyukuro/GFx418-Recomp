// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): the BitmapData read-only members and the LoadVars members.
// MS2-UNIT: sfr_as2_06m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429854f0-0x14298556e .text$mn
// MS2-RANGE: 0x142986440-0x1429864d8 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// width and height are read-only.
// MS2-FUNCTIONAL: the exe compares the name with the two literals byte by byte
// @0x1429854f0
bool BitmapData::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "width") == 0 || strcmp(pname, "height") == 0)
        return true;
    return Object::SetMember(penv, name, val, flags);
}

// A member that already exists is rewritten without flags, then the value goes through the plain SetMember.
// MS2-FUNCTIONAL: the member hash insert is inlined
// @0x142986440
bool LoadVarsObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    Member member;
    if (FindMember(penv->GetSC(), name, &member))
    {
        member.SetMemberFlags(PropFlags(0));
        Members.Set(name, member);
    }
    return Object::SetMember(penv, name, val, PropFlags(0));
}

} } }
