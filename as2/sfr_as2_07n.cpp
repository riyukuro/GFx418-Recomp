// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the common body of setInterval and setTimeout, which makes the timer and hands it to the movie.
// MS2-UNIT: sfr_as2_07n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297f3d0-0x14297fab2 .text$mn

#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the exe inlines the timer constructors (ours sets the callback after construction) and frees the method name before the interval is read;
// same behavior
// @0x14297f3d0
void IntervalTimer::Set(const FnCall& fn, bool isTimeout)
{
    fn.Result->SetUndefined();
    if (fn.NArgs < 2)
        return;

    Ptr<IntervalTimer> ptimer;
    int                argIndex;
    const Value&       first = fn.Arg(0);
    if (first.IsFunction())
    {
        // setInterval(func, ms, ...)
        ptimer = *SF_HEAP_NEW(fn.Env->GetHeap()) IntervalTimer((Object*)0, fn.Env->GetBuiltin(ASBuiltin_empty_));
        ptimer->Function = first.ToFunction(fn.Env);
        argIndex         = 1;
    }
    else if (first.IsObject())
    {
        // setInterval(obj, "method", ms, ...)
        ASString method = fn.Arg(1).ToString(fn.Env);
        ptimer   = *SF_HEAP_NEW(fn.Env->GetHeap()) IntervalTimer(fn.Arg(0).ToObject(fn.Env), method);
        argIndex = 2;
    }
    else if (first.IsCharacter())
    {
        // setInterval(mc, "method", ms, ...)
        ASString method = fn.Arg(1).ToString(fn.Env);
        ptimer          = *SF_HEAP_NEW(fn.Env->GetHeap()) IntervalTimer((Object*)0, method);
        ptimer->pTarget = fn.Arg(0).ToCharacter(fn.Env);
        argIndex        = 2;
    }
    else
        return;

    if (argIndex >= fn.NArgs)
        return;

    // The timer keeps the movie's root alive by its handle.
    InteractiveObject* ptarget = fn.Env->GetTarget();
    if (ptarget)
        ptimer->Character = ptarget->GetTopParent()->GetCharacterHandle();

    ptimer->Unrecovered_79 = isTimeout;
    ptimer->Interval       = UInt64(fn.Arg(argIndex).ToNumber(fn.Env)) * 1000;
    for (++argIndex; argIndex < fn.NArgs; ++argIndex)
        ptimer->Params.PushBack(fn.Arg(argIndex));

    MovieImpl* pmovie = fn.Env->GetTarget()->GetMovieImpl();
    int        id     = pmovie->AddIntervalTimer(ptimer);
    fn.Result->SetNumber(Number(id));
    ptimer->Start(pmovie);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7IntervalTimer@AS2@GFx@Scaleform@@6B@ 0x14321bd70
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7RefCountImpl@Scaleform@@6B@ 0x142dc9d58
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// RefCountBase<ASIntervalTimerIntf,0x143> is the table ~IntervalTimer (0x1429259d0) stores last before ~RefCountImplCore;
// slot 0 is its deleting destructor 0x1424e21a0 (ICF-folded with the other RefCountBase<*,0x143> tables).
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
