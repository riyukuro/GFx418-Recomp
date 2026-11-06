// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): the read-only Stage members and AvmSprite::SetMemberRaw. SetClipEventHandlers, SetConstructor and
// Selection.setControllerFocusGroup (0x14297fed0-0x142980233) live in sfr_as2_07h, whose map unit owns them.
// MS2-UNIT: sfr_as2_06g
// MS2-FLAGS: scaleform
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

// width and height of the Stage are read-only.
// @0x142988f30
bool StageCtorFunction::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                                     const PropFlags& flags)
{
    if (psc->GetBuiltin(ASBuiltin_width).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()) ||
        psc->GetBuiltin(ASBuiltin_height).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
        return true;
    return Object::SetMemberRaw(psc, name, val, flags);
}

// AvmCharacter::IsStandardMember (sfr_as2_06) as the exe inlines it here, without the lowercase name out.
static inline bool IsStandardMemberInline(const ASString& memberName)
{
    if ((UByte)(memberName.GetHashFlags() >> 29) & 1)
        return true;
    if (memberName.GetLength() > 0 && memberName.GetCharAt(0) == '_')
    {
        ASString lower(memberName.ToLowerNode());
        if ((UByte)(lower.GetHashFlags() >> 28) & 1)
            return true;
    }
    return false;
}

// A standard member (_x, _alpha, ...) is set on the clip itself, anything else goes to its MovieClipObject.
// @0x142988a40
bool AvmSprite::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (IsStandardMemberInline(name))
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
