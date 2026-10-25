// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 MovieRoot destructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ae
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142925be0-0x142925ce3 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The render tree entry's destroyHelper (Render::ContextImpl::Entry is not usable in this unit).
void FUN_142581700(void* pentry);

// MS2-FUNCTIONAL: the raw members are released by hand in the exe's order; ASMovieRootBase's destructor is a call
// @0x142925be0
MovieRoot::~MovieRoot()
{
    for (UPInt i = LevelRootCount; i != 0; --i)
        if (pLevelRoots[i - 1])
            static_cast<RefCountNTSImpl*>(pLevelRoots[i - 1])->Release();
    Memory::pGlobalHeap->Free(pLevelRoots);
    BuiltinsMgr.pStringManager->ReleaseBuiltinArray(BuiltinsMgr.Builtins, StringManager::BuiltinCount);
    GetActionQueue().~ActionQueueType();
    ExternalIntfRetVal.~Value();
    if (pGlobalContext)
        pGlobalContext->Release();
    if (MemContext)
        MemContext->Release();
    if (pAS2Support)
        pAS2Support->Release();
    UPInt* pentry = *reinterpret_cast<UPInt**>(Unrecovered_28);
    if (pentry && --pentry[1] == 0)
        FUN_142581700(pentry);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MovieRoot@AS2@GFx@Scaleform@@6B@ 0x1432177d8
