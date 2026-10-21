// Recovered Scaleform GFx 4.1.18: per-allocation info (shipping build: only the statistic id).
#ifndef MS2_SF_KERNEL_ALLOCINFO_H
#define MS2_SF_KERNEL_ALLOCINFO_H

#include "ms2/scaleform/kernel/sf_stats.h"

namespace Scaleform {

struct AllocInfo
{
    unsigned StatId;

    AllocInfo() : StatId(Stat_Default_Mem) { }
    AllocInfo(unsigned statId, const char*, unsigned) : StatId(statId) { }
    AllocInfo(const AllocInfo& src) : StatId(src.StatId) { }
};

}  // namespace Scaleform

#endif
