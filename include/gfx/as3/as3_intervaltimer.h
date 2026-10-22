// Recovered Scaleform GFx 4.1.18 AS3: the interval timer behind setInterval/setTimeout and flash.utils.Timer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// Layout from IntervalTimer(Timer*, unsigned, unsigned, unsigned) 0x1424d7f10 (0x70 bytes, vftable 0x14317f258).
#ifndef MS2_SF_GFX_AS3_INTERVALTIMER_H
#define MS2_SF_GFX_AS3_INTERVALTIMER_H

#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_utils { class Timer; } }

class IntervalTimer : public ASIntervalTimerIntf
{
public:
    // A flash.utils.Timer's core timer; delay in milliseconds (0x1424d7f10).
    IntervalTimer(Instances::fl_utils::Timer* timerObj, unsigned delay, unsigned curCount, unsigned repeatCount);

    virtual ~IntervalTimer();

    virtual void   Start(MovieImpl* proot);
    virtual bool   Invoke(MovieImpl* proot, float frameTime);
    virtual bool   IsActive() const;
    virtual void   Clear();
    virtual bool   ClearFor(MovieImpl* proot, MovieDefImpl* pdefImpl);
    virtual UInt64 GetNextInvokeTime() const;
    virtual void   SetId(int id);
    virtual int    GetId() const;

    unsigned GetCurrentCount() const { return CurrentCount; }

private:
    Value                               Function;       // +0x10 the setInterval closure
    SPtr<Instances::fl_utils::Timer>    TimerObj;       // +0x30
    ArrayLH<Value>                      Params;         // +0x38
    unsigned                            CurrentCount;   // +0x50
    unsigned                            RepeatCount;    // +0x54
    UInt64                              Interval;       // +0x58 microseconds
    UInt64                              InvokeTime;     // +0x60 microseconds
    int                                 Id;             // +0x68
    bool                                Active;         // +0x6c
    bool                                Timeout;        // +0x6d fire once (setTimeout)
};

}}} // namespace Scaleform::GFx::AS3

#endif
