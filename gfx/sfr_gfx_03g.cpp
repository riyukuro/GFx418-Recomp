// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextField, the deleting
// destructor of Render::Text::TextFilter (0x50 bytes) that the exe keeps inside the TextField TU (the linker folds
// it with the other RefCountBaseNTS deleting destructors of the same size). The rest of the TU is sfr_gfx_03e /
// sfr_gfx_03f.
// MS2-UNIT: sfr_gfx_03g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425b6580-0x1425b65e0 .text$mn

#include "ms2/scaleform/include/render/text_filterdesc.h"

extern "C" void FUN_14015b310(void*, unsigned long long);

namespace Scaleform { namespace Render { namespace Text {

// Destroys the filter (only the reference-count base has anything to undo); bit 1 frees it, bit 4 with the sized
// operator delete.
// @0x1425b6580
void* FUN_1425b6580(TextFilter* pfilter, unsigned flags)
{
    pfilter->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(pfilter);
        else
            FUN_14015b310(pfilter, sizeof(TextFilter));
    }
    return pfilter;
}

}}} // namespace Scaleform::Render::Text
