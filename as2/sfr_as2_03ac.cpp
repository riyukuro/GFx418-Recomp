// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 load queue entry destructor
// (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ac
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142925890-0x1429258d9 .text$mn

#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142925890
GFxAS2LoadQueueEntryMT_LoadMovie::~GFxAS2LoadQueueEntryMT_LoadMovie()
{
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7GFxAS2LoadQueueEntryMT_LoadMovie@AS2@GFx@Scaleform@@6B@ 0x143217750
