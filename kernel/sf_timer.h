// Recovered Scaleform GFx 4.1.18: timer (QueryPerformanceCounter based; bodies in sfr_kernel_02g).
#ifndef MS2_SF_KERNEL_TIMER_H
#define MS2_SF_KERNEL_TIMER_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

class Timer
{
public:
    enum { MsPerSecond = 1000, MksPerMs = 1000, MksPerSecond = MsPerSecond * MksPerMs };

    static UInt32 SF_STDCALL GetTicksMs();
    static UInt64 SF_STDCALL GetTicks();
    static UInt64 SF_STDCALL GetProfileTicks();
    static double SF_STDCALL GetProfileSeconds();
    static UInt64 SF_STDCALL GetRawTicks();
    static UInt64 SF_STDCALL GetRawFrequency();

    static double TicksToSeconds(UInt64 ticks) { return (double)ticks * (1.0 / (double)MksPerSecond); }

    // replaces the system clock for every Timer function while set (pOverride)
    class TimerOverride
    {
    public:
        virtual ~TimerOverride() { }
        virtual UInt32 GetTicksMs() = 0;
        virtual UInt64 GetRawTicks() = 0;
        virtual UInt64 GetRawFrequency() = 0;
    };
    static TimerOverride* pOverride;

private:
    friend class System;
    // set up / tear down by System::Init / Destroy
    static void initializeTimerSystem();
    static void shutdownTimerSystem();
};

}  // namespace Scaleform

#endif
