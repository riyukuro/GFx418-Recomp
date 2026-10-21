// Recovered Scaleform 4.1.18 kernel: thread declarations needed by the users of Thread (only the priority enum so far).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_THREADS_H
#define MS2_SF_KERNEL_THREADS_H

#include "sf_types.h"

namespace Scaleform {

class Thread
{
public:
    enum ThreadPriority
    {
        CriticalPriority,
        HighestPriority,
        AboveNormalPriority,
        NormalPriority,
        BelowNormalPriority,
        LowestPriority,
        IdlePriority,
    };
};

} // namespace Scaleform

#endif
