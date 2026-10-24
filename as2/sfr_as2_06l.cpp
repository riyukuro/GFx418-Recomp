// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): the Selection focus extension properties. Selection.setModalClip (0x142989060) lives in sfr_as2_07h,
// whose map unit owns it.
// MS2-UNIT: sfr_as2_06l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142987090-0x14298727c .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// A two-bit extension flag of the movie: cleared, then set to the boolean.
static void Selection_SetFlag(MovieImpl* pmovie, unsigned shift, bool value)
{
    pmovie->Flags &= ~(3u << shift);
    pmovie->Flags |= (unsigned)value << shift;
}

// With the extensions on, the focus properties and modalClip go to the movie; the rest is a plain member.
// MS2-FUNCTIONAL: the sprite test of modalClip is a vtable call in the exe
// @0x142987090
bool SelectionCtorFunction::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (penv->GetSC()->pContext->CheckExtensions())
    {
        MovieImpl*  pmovie = penv->GetTarget()->GetMovieImpl();
        const char* pname  = name.ToCStr();
        if (strcmp(pname, "disableFocusAutoRelease") == 0)
        {
            Selection_SetFlag(pmovie, MovieImpl::Shift_DisableFocusAutoRelease, val.ToBool(penv));
            return true;
        }
        if (strcmp(pname, "alwaysEnableArrowKeys") == 0)
        {
            Selection_SetFlag(pmovie, MovieImpl::Shift_AlwaysEnableArrowKeys, val.ToBool(penv));
            return true;
        }
        if (strcmp(pname, "alwaysEnableKeyboardPress") == 0)
        {
            Selection_SetFlag(pmovie, MovieImpl::Shift_AlwaysEnableKeyboardPress, val.ToBool(penv));
            return true;
        }
        if (strcmp(pname, "disableFocusRolloverEvent") == 0)
        {
            Selection_SetFlag(pmovie, MovieImpl::Shift_DisableFocusRolloverEvent, val.ToBool(penv));
            return true;
        }
        if (strcmp(pname, "disableFocusKeys") == 0)
        {
            Selection_SetFlag(pmovie, MovieImpl::Shift_DisableFocusKeys, val.ToBool(penv));
            return true;
        }
        if (strcmp(pname, "modalClip") == 0)
        {
            InteractiveObject* pch = val.ToCharacter(penv);
            Sprite* psprite = (pch && pch->IsSprite()) ? static_cast<Sprite*>(pch) : 0;
            pmovie->SetModalClip(psprite, 0);
            return true;
        }
    }
    return Object::SetMember(penv, name, val, flags);
}

} } }
