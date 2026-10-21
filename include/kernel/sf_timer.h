// Recovered Scaleform 4.1.18 kernel: the timer (only the parts used by recovered units so far; bodies in
// sfr_kernel_02g).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Same include guard as the kernel tree's src/ms2/scaleform/kernel/sf_timer.h on purpose: both describe the same
// class, so a unit only ever gets one of them.
#ifndef MS2_SF_KERNEL_TIMER_H
#define MS2_SF_KERNEL_TIMER_H

#include "sf_types.h"

namespace Scaleform {

class Timer
{
public:
    static UInt64 SF_STDCALL GetProfileTicks();
};

} // namespace Scaleform

#endif
