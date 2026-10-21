// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_Timer (millisecond clock
// over timeGetTime with wrap counting, microsecond clock over the performance counter, optional override).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e33f0-0x1425e3750 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_timer.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")     // timeGetTime, timeBeginPeriod, timeEndPeriod

namespace Scaleform {

Timer::TimerOverride* Timer::pOverride = 0;         // exe 0x143b16050 (the state below: 0x143b16020..0x143b16068)

// state of the 64-bit millisecond clock: timeGetTime wraps every 49.7 days
CRITICAL_SECTION Timer_MMTimeLock;
volatile UInt32  Timer_MMTimeLast = 0;
volatile UInt32  Timer_MMTimeWraps = 0;
UInt64           Timer_PerfFrequency = 0;

double SF_STDCALL Timer::GetProfileSeconds()
{
    static UInt64 start = GetProfileTicks();
    return TicksToSeconds(GetProfileTicks() - start);
}

UInt64 SF_STDCALL Timer::GetProfileTicks()
{
    return (GetRawTicks() * MksPerSecond) / GetRawFrequency();
}

UInt64 SF_STDCALL Timer::GetRawFrequency()
{
    if (pOverride)
        return pOverride->GetRawFrequency();
    if (Timer_PerfFrequency == 0)
    {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        Timer_PerfFrequency = freq.QuadPart;
    }
    return Timer_PerfFrequency;
}

UInt64 SF_STDCALL Timer::GetRawTicks()
{
    if (pOverride)
        return pOverride->GetRawTicks();
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);
    return ticks.QuadPart;
}

UInt64 SF_STDCALL Timer::GetTicks()
{
    EnterCriticalSection(&Timer_MMTimeLock);
    UInt32 ms = pOverride ? pOverride->GetTicksMs() : timeGetTime();
    if (Timer_MMTimeLast > ms)
        Timer_MMTimeWraps++;
    Timer_MMTimeLast = ms;
    UInt64 result = ((UInt64)Timer_MMTimeWraps << 32) | ms;
    LeaveCriticalSection(&Timer_MMTimeLock);
    return result * MksPerMs;
}

UInt32 SF_STDCALL Timer::GetTicksMs()
{
    if (pOverride)
        return pOverride->GetTicksMs();
    return timeGetTime();
}

void Timer::initializeTimerSystem()
{
    timeBeginPeriod(1);
    InitializeCriticalSection(&Timer_MMTimeLock);
}

void Timer::shutdownTimerSystem()
{
    DeleteCriticalSection(&Timer_MMTimeLock);
    timeEndPeriod(1);
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?GetProfileSeconds@Timer@Scaleform@@SANXZ 0x1425e33f0
// MS2-PIN: ?GetProfileTicks@Timer@Scaleform@@SA_KXZ 0x1425e3480
// MS2-PIN: ?GetRawFrequency@Timer@Scaleform@@SA_KXZ 0x1425e3510
// MS2-PIN: ?GetRawTicks@Timer@Scaleform@@SA_KXZ 0x1425e3560
// MS2-PIN: ?GetTicks@Timer@Scaleform@@SA_KXZ 0x1425e3590
// MS2-PIN: ?GetTicksMs@Timer@Scaleform@@SAKXZ 0x1425e3610
// MS2-PIN: ?initializeTimerSystem@Timer@Scaleform@@CAXXZ 0x1425e3640
// MS2-PIN: ?shutdownTimerSystem@Timer@Scaleform@@CAXXZ 0x1425e3670
