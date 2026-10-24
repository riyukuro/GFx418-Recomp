// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 leftovers around GFx_ZLibFile:
// the timeline frame's tag destruction and ZLibFile::LTell (a COMDAT shared with every File whose LTell is Tell).
// Gap recovery of queue unit sfr_gfx_08.
// MS2-UNIT: sfr_gfx_08x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142645590-0x1426455f3 .text$mn
// MS2-RANGE: 0x142645cd0-0x142645ce1 .text$mn

#include "../include/gfx/gfx_characterdef.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/kernel/sf_file.h"

namespace Scaleform { namespace GFx {

// The tags live in the movie data's tag memory, so only their destructors run.
// @0x142645590
void TimelineDef::Frame::DestroyTags()
{
    for (unsigned i = 0; i < TagCount; i++)
        pTagPtrList[i]->~ExecuteTag();
    pTagPtrList = 0;
    TagCount    = 0;
}

// @0x142645cd0
SInt64 ZLibFile::LTell()
{
    return Tell();
}

}} // namespace Scaleform::GFx
