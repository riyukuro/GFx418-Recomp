// Recovered from MapleStory2.exe KMS2_DEV x64: Scaleform GFx 4.1.18 Video glue, AS3 half.
// Source is written from the executable; leaked SDK copies are naming/layout reference only.
// MS2-UNIT: sfr_video_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14000e470-0x140016b50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/gfx/as2/as2_avmcharacter.h"

namespace Scaleform { namespace GFx { namespace Video {

}}} // namespace Scaleform::GFx::Video

namespace Scaleform { namespace GFx { namespace AS2 {

// AvmVideoCharacter::OnUnloading: detach this clip from the frame advance list.
// MS2-FUNCTIONAL: recovered behavior; standalone body is used while AvmVideoCharacter's full vtable is pending.
// @0x14000e5e0
bool AvmVideoCharacter_OnUnloading(AvmCharacter* pavm)
{
    pavm->pDispObj->RemoveFromPlayList();
    return true;
}

// The two interface adjustors are separate executable entries in this video glue range.
// @0x14000e510
void* FUN_14000e510(void* p)
{
    return p ? static_cast<void*>(static_cast<unsigned char*>(p) + 0x30) : 0;
}

// @0x14000e520
uintptr_t FUN_14000e520(uintptr_t value)
{
    return value;
}

// @0x14000e530
uintptr_t FUN_14000e530() { return 0; }

// @0x14000e540
uintptr_t FUN_14000e540() { return 0; }

// @0x14000e550
uintptr_t FUN_14000e550() { return 0; }

// @0x14000e560
uintptr_t FUN_14000e560() { return 0; }

// @0x14000e580
bool FUN_14000e580() { return false; }

}}} // namespace Scaleform::GFx::AS2
