// Recovered Scaleform GFx 4.1.18: statistic ids and the (shipping build) null statistics classes. Stats are compiled out
// in the exe, so only the ids (AllocInfo::StatId values) and the empty interfaces remain.
#ifndef MS2_SF_KERNEL_STATS_H
#define MS2_SF_KERNEL_STATS_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

class MemoryHeap;

enum StatBasicValues
{
    StatGroup_Default = 0,
    StatGroup_Core    = 16,
    Stat_Mem          = StatGroup_Default + 1,
    Stat_Default_Mem  = Stat_Mem + 1,
    StatHeap_Start    = StatGroup_Core,
    Stat_MaxId        = 64 << 6,
    Stat_EntryCount   = 512,
    HeapId_Default    = 1
};

// GFx-level ids (the exe has sound and video enabled)
enum StatGroup
{
    StatGroup_Renderer       = 1 << 6,
    StatGroup_RenderGen      = 2 << 6,
    StatGroup_GFxFontCache   = 3 << 6,
    StatGroup_GFxMovieData   = 4 << 6,
    StatGroup_GFxMovieView   = 5 << 6,
    StatGroup_GFxRenderCache = 6 << 6,
    StatGroup_GFxPlayer      = 7 << 6,
    StatGroup_GFxIME         = 8 << 6,
    StatGroup_GFxAmp         = 9 << 6,

    Stat_Image_Mem = Stat_Default_Mem + 1,
    Stat_Sound_Mem,
    Stat_String_Mem,
    Stat_Video_Mem,
    Stat_Debug_Mem,
    Stat_DebugHUD_Mem,
    Stat_DebugTracker_Mem,
    Stat_StatBag_Mem
};

enum HeapId
{
    HeapId_Global = HeapId_Default,
    HeapId_MovieDef,
    HeapId_MovieView,
    HeapId_MovieData,
    HeapId_Images,
    HeapId_OtherHeaps,
    HeapId_HUDHeaps,
    HeapId_Video
};

class Stat
{
public:
    enum StatType { Stat_LogicalGroup, Stat_Memory, Stat_Timer, Stat_Counter, Stat_TypeCount };
};

// Null counter (no state without SF_ENABLE_STATS).
class CounterStat : public Stat
{
public:
    CounterStat() { }
    CounterStat(UPInt) { }
    void Init() { }
    CounterStat& operator+=(CounterStat&) { return *this; }
    StatType GetStatType() const { return Stat_Counter; }
    unsigned GetStatCount() const { return 1; }
};

class StatInfo;

// Null statistics bag (SF_ENABLE_STATS is off in the exe).
class StatBag
{
public:
    StatBag(MemoryHeap* = 0, unsigned = 0) { }
    StatBag(const StatBag&) { }
    ~StatBag() { }
    void Clear() { }
    void Reset() { }
    bool Add(unsigned, Stat*) { return false; }
    StatBag& operator+=(const StatBag&) { return *this; }
    StatBag& operator=(const StatBag&) { return *this; }
    void UpdateGroups() { }
    bool GetStat(StatInfo*, unsigned) const { return false; }
    bool AddStat(unsigned, const Stat&) { return false; }
};

}  // namespace Scaleform

#endif
