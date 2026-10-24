// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): clip event handler assignment, Selection.setControllerFocusGroup and the read-only Stage members.
// MS2-UNIT: sfr_as2_06g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297fed0-0x14297ffb7 .text$mn
// MS2-RANGE: 0x14297ffc0-0x14298011a .text$mn
// MS2-RANGE: 0x142980120-0x142980233 .text$mn
// MS2-RANGE: 0x142988a40-0x142988b49 .text$mn
// MS2-RANGE: 0x142988f30-0x142989016 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieslots.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Sets the handler of each event of a flag set; a single event goes straight through.
// MS2-FUNCTIONAL: the event flag count is a bit-twiddling popcount in the exe
// @0x14297fed0
void AvmCharacter::SetClipEventHandlers(const EventId& id, const Value& handler)
{
    unsigned count = 0;
    for (UInt32 bits = id.Id; bits; bits &= bits - 1)
        ++count;
    if (count == 1)
    {
        SetSingleClipEventHandler(id, handler);
        return;
    }
    unsigned done = 0;
    for (UInt32 flag = 1; done < count; flag *= 2)
    {
        if (id.Id & flag)
        {
            EventId single(id);
            single.Id = flag;
            ++done;
            SetSingleClipEventHandler(single, handler);
        }
    }
}

// The prototype keeps the constructor function; its "constructor" member is made hidden and permanent, and its value
// is left to the property lookup (an unset value).
// MS2-FUNCTIONAL: the function reference copy and its releases are inlined in the exe
// @0x14297ffc0
bool GASPrototypeBase::SetConstructor(Object* pthis, ASStringContext* psc, const Value& ctor)
{
    Constructor = ctor.ToFunction(0);
    pthis->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_constructor), Value(Value::UNSET),
                        PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete);
    return true;
}

// Selection.setControllerFocusGroup(controllerIdx, focusGroupIdx): true when the controller took the group.
// MS2-FUNCTIONAL: the argument stack indexing is inlined differently
// @0x142980120
void SelectionCtorFunction::SetControllerFocusGroup(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs > 1)
    {
        MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
        unsigned   controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
        unsigned   groupIdx      = fn.Arg(1).ToUInt32(fn.Env);
        fn.Result->SetBool(AsMovieSlots(proot)->SetControllerFocusGroup(controllerIdx, groupIdx));
    }
}

// width and height of the Stage are read-only.
// MS2-FUNCTIONAL: the case check helper is inlined twice with the string node fields reloaded
// @0x142988f30
bool StageCtorFunction::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                                     const PropFlags& flags)
{
    if (psc->GetBuiltin(ASBuiltin_width).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()) ||
        psc->GetBuiltin(ASBuiltin_height).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
        return true;
    return Object::SetMemberRaw(psc, name, val, flags);
}

// A standard member (_x, _alpha, ...) is set on the clip itself, anything else goes to its MovieClipObject.
// MS2-FUNCTIONAL: the standard member test is inlined (string node flags, lowercase node)
// @0x142988a40
bool AvmSprite::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (IsStandardMember(name))
    {
        StandardMember index = GetStandardMemberConstant(name);
        if (SetStandardMember(index, val, false))
            return true;
    }
    if (!pMovieClipObj && !GetMovieClipObject())
        return false;
    return pMovieClipObj->SetMemberRaw(psc, name, val, flags);
}

} } }
