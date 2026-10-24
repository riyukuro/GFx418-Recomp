// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 IntervalTimer::Invoke of sfr_as2_06
// (gap recovery, lane sfr24): a due setInterval / setTimeout calls its function (or the named method of its object or
// clip) and is rescheduled.
// MS2-UNIT: sfr_as2_06s13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142962c90-0x142963315 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The environment of _level0.
static SF_FORCEINLINE Environment* ItLevel0Env(MovieRoot* proot)
{
    return ToAvmCharacter(proot->GetLevelMovie(0))->GetASEnvironment();
}

// Not yet due: false. Otherwise the callback runs with the timer's arguments, in the environment of its clip (or
// _level0), and the next call is put a whole number of intervals after the last one, never sooner than a tenth of
// the frame time. A timer whose object or clip is gone stops; a timeout stops after its call.
// MS2-FUNCTIONAL: register allocation and block layout differ.
// @0x142962c90
bool IntervalTimer::Invoke(MovieImpl* proot, float frameTime)
{
    if (!Active)
        return false;

    MovieRoot* pasRoot     = static_cast<MovieRoot*>(proot->pASMovieRoot);
    UInt64     currentTime = proot->TimeElapsed;
    bool       retval      = false;
    if (currentTime >= InvokeTime)
    {
        FunctionRef            function;
        Ptr<Object>            thisHolder;
        Ptr<InteractiveObject> target;
        ObjectInterface*       pthis = 0;
        Environment*           penv  = 0;

        if (!Function.IsNull())
            function = Function;
        else
        {
            if (pObject)
            {
                thisHolder = pObject;
                pthis      = thisHolder;
            }
            else
            {
                target = pTarget;
                if (target)
                {
                    pthis = ToAvmCharacter(target);
                    penv  = ToAvmCharacter(target)->GetASEnvironment();
                }
            }
            if (pthis)
            {
                Value methodVal;
                if (pthis->GetMemberRaw(ItLevel0Env(pasRoot)->GetSC(), MethodName, &methodVal))
                    function = methodVal.ToFunction(penv);
            }
            else
                // The object or clip is gone.
                Active = false;
        }

        if (!function.IsNull())
        {
            Value result;
            if (!penv)
            {
                if (Character)
                {
                    Ptr<DisplayObject> pch = Character->ResolveCharacter(proot);
                    if (pch)
                        penv = ToAvmCharacter(pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch.GetPtr())
                                                                          : 0)
                                   ->GetASEnvironment();
                }
                if (!penv)
                    penv = ItLevel0Env(pasRoot);
            }
            int nArgs = int(Params.GetSize());
            if (nArgs > 0)
            {
                for (int i = nArgs - 1; i >= 0; --i)
                    penv->Push(Params[i]);
            }
            function.Invoke(FnCall(&result, pthis, penv, nArgs, penv->GetTopIndex()));
            penv->Drop(nArgs);
        }

        if (Unrecovered_79)
            // setTimeout: once only.
            Active = false;
        else
        {
            UInt64 interval    = Interval;
            UInt64 minInterval = UInt64(frameTime * 1000000.f) / 10;
            if (interval < minInterval)
                interval = unsigned(minInterval);
            if (interval)
            {
                UInt64 delta = currentTime - InvokeTime + interval;
                delta -= delta % interval;
                if (delta)
                    InvokeTime += delta;
                else
                    InvokeTime = currentTime;
            }
            else
                InvokeTime = currentTime;
        }
        retval = true;
    }
    return retval;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
