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

// The render tree entry, only its destroyHelper (render_context.h is not usable in this unit; as in sfr_as2_04h).
namespace Scaleform { namespace Render { namespace ContextImpl {
class Entry
{
protected:
    void destroyHelper();
};
struct EntryAccess : Entry { using Entry::destroyHelper; };
} } }

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: the SDK body is empty. In the exe, +0x28 (TopNode, Ptr<Render::TreeContainer>), +0x30 (Ptr<ASSupport>)
// and +0x38 (Ptr<MemoryContextImpl>) are member Ptrs destroyed after +0x58/+0x50, and ~ASMovieRootBase (an inline {} in
// the SDK) is inlined. Here those are raw fields released by hand and the base dtor is out of line (sfr_as3_16). The fix
// needs the as2_movieroot.h member types, the 03ag ctor and the base-dtor inline change together
// @0x142925be0
MovieRoot::~MovieRoot()
{
    for (UPInt i = LevelRootCount; i != 0; --i)
        if (pLevelRoots[i - 1])
            static_cast<RefCountNTSImpl*>(pLevelRoots[i - 1])->Release();
    Memory::pGlobalHeap->Free(pLevelRoots);
    BuiltinsMgr.pStringManager->ReleaseBuiltinArray(BuiltinsMgr.Builtins, StringManager::BuiltinCount);
    GetActionQueue().~ActionQueueType();
    // ExternalIntfRetVal (+0x58) and pGlobalContext (+0x50) are real members: their implicit destructors drop them
    // once, after the body. (Destroying them here as well dropped the Value's refs and released the GlobalContext
    // twice.) The exe destroys them before the raw +0x38/+0x30/+0x28 releases below.
    if (MemContext)
        MemContext->Release();
    if (pAS2Support)
        pAS2Support->Release();
    UPInt* pentry = *reinterpret_cast<UPInt**>(Unrecovered_28);
    if (pentry && --pentry[1] == 0)
        reinterpret_cast<Render::ContextImpl::EntryAccess*>(pentry)->destroyHelper();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MovieRoot@AS2@GFx@Scaleform@@6B@ 0x1432177d8
