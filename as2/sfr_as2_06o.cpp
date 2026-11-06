// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): MovieRoot::SetVariable.
// MS2-UNIT: sfr_as2_06o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298cfb0-0x14298d1d3 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_player.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The movie loaded as _level<level>, 0 if none.
static SF_FORCEINLINE InteractiveObject* FindLevelMovie(const MovieRoot* proot, int level)
{
    for (unsigned i = 0; i < proot->pMovieImpl->MovieLevelsSize; i++)
    {
        if (proot->pMovieImpl->pMovieLevels[i].Level == level)
            return proot->pMovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The movie's log as a raw pointer (MovieRoot::GetLog: the Ptr temp is released at once).
static SF_FORCEINLINE Log* MS2_RootLog(const MovieImpl* pmovieImpl)
{
    return pmovieImpl->GetStateBag()->GetLog().GetPtr();
}

// Sets a script variable from the host: on _level0 now, or (sticky / permanent) kept until the target exists.
// MS2-FUNCTIONAL: register allocation only: the exe keeps the level array in rbx and uses one more saved register (r15)
// @0x14298cfb0
bool MovieRoot::SetVariable(const char* ppathToVar, const GFx::Value& value, SetVarTypeArg setType)
{
    if (!FindLevelMovie(this, 0))
        return false;
    if (!ppathToVar)
    {
        if (MS2_RootLog(pMovieImpl))
            MS2_RootLog(pMovieImpl)->LogError("NULL pathToVar passed to SetVariable/SetDouble()");
        return false;
    }
    Environment* penv = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(FindLevelMovie(this, 0)->GetAvmObjImpl()))
                            ->GetASEnvironment();
    ASString path(penv->CreateString(ppathToVar));
    Value    asval;
    Value2ASValue(value, &asval);
    bool ok = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(FindLevelMovie(this, 0)->GetAvmObjImpl()))
               ->GetASEnvironment()->SetVariable(path, asval, 0, setType == Movie::SV_Normal);
    if ((!ok && setType != Movie::SV_Normal) || setType == Movie::SV_Permanent)
        AddStickyVariable(path, asval, setType);
    return ok;
}

}}} // namespace Scaleform::GFx::AS2
