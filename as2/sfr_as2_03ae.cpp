// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 MovieRoot destructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ae
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142925be0-0x142925ce3 .text$mn
// MS2-RANGE: 0x14292c3e0-0x14292c520 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The SDK body is empty: the members (LevelRoots .. TopNode) and the inline ~ASMovieRootBase run after it. Inline
// here so that the deleting destructor below inlines it; the vftable's ??_G keeps the COMDAT copy.
// @0x142925be0
__forceinline MovieRoot::~MovieRoot()
{
}

// The deleting destructor (vftable slot 0); ~MovieRoot is inlined into it.
// @0x14292c3e0
void* DeleteAs2_14292c3e0(void* p, unsigned flags)
{
    static_cast<MovieRoot*>(p)->MovieRoot::~MovieRoot();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x640);
    }
    return p;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MovieRoot@AS2@GFx@Scaleform@@6B@ 0x1432177d8
// The inlined ~ASMovieRootBase stores the base vftable, so it is emitted here as well:
// MS2-PIN: ??_7ASMovieRootBase@GFx@Scaleform@@6B@ 0x14317bde0
