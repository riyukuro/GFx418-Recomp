// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 IntervalTimer constructors and
// destructor (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03r
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291cf60-0x14291d026 .text$mn
// MS2-RANGE: 0x14291d030-0x14291d0c5 .text$mn
// MS2-RANGE: 0x1429259d0-0x142925ad0 .text$mn

#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14291cf60
IntervalTimer::IntervalTimer(const FunctionRefBase& fn, ASStringContext* psc)
    : Function(fn), MethodName(psc->GetBuiltin(ASBuiltin_empty_)), Interval(0), InvokeTime(0), Id(0), Active(true),
      Unrecovered_79(false)
{
}

// @0x14291d030
IntervalTimer::IntervalTimer(InteractiveObject* ptarget, const ASString& method)
    : pTarget(ptarget), MethodName(method), Interval(0), InvokeTime(0), Id(0), Active(true), Unrecovered_79(false)
{
}

// MS2-FUNCTIONAL: the members go in the exe's order, but cl also stores the vftable on entry (10 bytes the exe does not have)
// @0x1429259d0
IntervalTimer::~IntervalTimer()
{
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7IntervalTimer@AS2@GFx@Scaleform@@6B@ 0x14321bd70
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7RefCountImpl@Scaleform@@6B@ 0x142dc9d58
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// RefCountBase<ASIntervalTimerIntf,0x143> is the table ~IntervalTimer stores last (0x142925ab1); see sfr_as3_15.
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
