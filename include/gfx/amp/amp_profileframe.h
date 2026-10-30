// Recovered Scaleform GFx 4.1.18 AMP: per-frame profile data (GFx/AMP/Amp_ProfileFrame.h).
// The members live in sfr_as3_22 (0x142685f00-0x142690c70). Layouts are checked against the exe offsets below.
#ifndef MS2_SF_GFX_AMP_PROFILEFRAME_H
#define MS2_SF_GFX_AMP_PROFILEFRAME_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/kernel/sf_hash.h"
#include "ms2/scaleform/include/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_memitem.h"

namespace Scaleform {
class Log;
namespace GFx {
namespace AMP {

enum StatAmp
{
    StatAmp_Default = StatGroup_GFxAmp,
    StatAmp_Mem,
    StatAmp_ProfileFrame,
    StatAmp_Server
};

// ActionScript per-instruction timings of each script buffer.
struct MovieInstructionStats : public RefCountBase<MovieInstructionStats, StatAmp_ProfileFrame>
{
    struct InstructionTimePair
    {
        UInt32 Offset;
        UInt64 Time;
    };

    struct ScriptBufferStats : RefCountBase<ScriptBufferStats, StatAmp_ProfileFrame>
    {
        UInt32                       SwdHandle;
        UInt32                       BufferOffset;
        UInt32                       BufferLength;
        ArrayLH<InstructionTimePair> InstructionTimesArray;

        void Read(File& str, UInt32 version);
        void Write(File& str, UInt32 version) const;
    };

    ArrayLH<Ptr<ScriptBufferStats> > BufferStatsArray;

    MovieInstructionStats& operator/=(unsigned numFrames);
    MovieInstructionStats& operator*=(unsigned num);
    void Merge(const MovieInstructionStats& other);

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};
static_assert(sizeof(MovieInstructionStats::InstructionTimePair) == 0x10, "InstructionTimePair");
static_assert(offsetof(MovieInstructionStats::ScriptBufferStats, InstructionTimesArray) == 0x20, "ScriptBufferStats");
static_assert(offsetof(MovieInstructionStats, BufferStatsArray) == 0x10, "MovieInstructionStats");

} // namespace AMP
} // namespace GFx
} // namespace Scaleform

#endif
