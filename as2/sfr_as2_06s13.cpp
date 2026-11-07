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

// IntervalTimer::GetNextInterval, inlined in the exe: never more than ten calls a frame.
static SF_FORCEINLINE UInt64 ItGetNextInterval(const IntervalTimer* pt, UInt64 currentTime, UInt64 frameTime)
{
    UInt64 interval;
    if (pt->Interval < frameTime / 10)
        interval = unsigned(frameTime / 10);
    else
        interval = pt->Interval;
    if (interval == 0)
        return 0;
    return (((currentTime - pt->InvokeTime) + interval) / interval) * interval;
}

// WeakPtr<InteractiveObject>::operator Ptr<InteractiveObject> (0x1422b4770), which the exe calls out of line, called
// through a view of pTarget.
struct Unk_ItWeakTarget { Ptr<InteractiveObject> FUN_1422b4770() const; };

// Not yet due: false. Otherwise the callback runs with the timer's arguments, in the environment of its clip (or
// _level0), and the next call is put a whole number of intervals after the last one, never sooner than a tenth of
// the frame time. A timer whose object or clip is gone stops; a timeout stops after its call.
// MS2-FUNCTIONAL: register allocation and block layout differ; the exe also keeps the converted target in a register
// where ours reloads it from the temporary before releasing it. Not a floor: ours is 1579 bytes against the exe's 1669.
// Both make the same 26 direct calls. The gap is layout: the exe duplicates the GetASEnvironment vcall on the null
// GetLevelMovie(0) path, picks the level clip with a cmov, and joins the penv paths through extra jmp tails.
// @0x142962c90
bool IntervalTimer::Invoke(MovieImpl* proot, float frameTime)
{
    if (!Active)
        return false;
    MovieRoot* asroot = static_cast<MovieRoot*>(proot->pASMovieRoot);

    UInt64 currentTime = proot->TimeElapsed;
    bool   retval      = false;
    if (currentTime >= InvokeTime)
    {
        FunctionRef            function;
        ObjectInterface*       thisPtr = 0;
        Ptr<Object>            thisHolder;
        Ptr<InteractiveObject> targetHolder;
        Environment*           penv = 0;

        if (!Function.IsNull())
        {
            function = Function;
        }
        else
        {
            thisHolder = Ptr<Object>(pObject);
            if (thisHolder)
            {
                thisPtr = thisHolder;
            }
            else if ((targetHolder = Ptr<InteractiveObject>(reinterpret_cast<const Unk_ItWeakTarget&>(pTarget).FUN_1422b4770().GetPtr())))
            {
                thisPtr = ToAvmCharacter(targetHolder);
                penv    = ToAvmCharacter(targetHolder)->GetASEnvironment();
            }
            if (thisPtr)
            {
                Value            methodVal;
                ASStringContext* psc = ToAvmCharacter(asroot->GetLevelMovie(0))->GetASEnvironment()->GetSC();
                if (thisPtr->GetMemberRaw(psc, MethodName, &methodVal))
                {
                    function = methodVal.ToFunction(penv);
                }
            }
            else // the object or clip is gone
                Active = false;
        }

        if (!function.IsNull())
        {
            Value result;
            if (!penv)
            {
                if (Character)
                {
                    Ptr<DisplayObject> levelCh = Character->ResolveCharacter(proot);
                    if (levelCh)
                        penv = ToAvmCharacter(levelCh->IsInteractiveObject()
                                                  ? static_cast<InteractiveObject*>(levelCh.GetPtr())
                                                  : 0)->GetASEnvironment();
                }
                if (!penv)
                {
                    penv = ToAvmCharacter(asroot->GetLevelMovie(0))->GetASEnvironment();
                }
            }

            int nArgs = (int)Params.GetSize();
            if (nArgs > 0)
            {
                for (int i = nArgs - 1; i >= 0; --i)
                    penv->Push(Params[i]);
            }
            function.Invoke(FnCall(&result, thisPtr, penv, nArgs, penv->GetTopIndex()));
            if (nArgs > 0)
            {
                penv->Drop(nArgs);
            }
        }

        if (Unrecovered_79)
        {
            // setTimeout: once only
            Active = false;
        }
        else
        {
            UInt64 interval = ItGetNextInterval(this, currentTime, UInt64(frameTime * 1000000.f));
            if (interval > 0)
                InvokeTime += interval;
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
