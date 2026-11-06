// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 MovieRoot constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ag
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291f070-0x14291f2b6 .text$mn
// MS2-RANGE: 0x142528740-0x142528744 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
namespace Scaleform { namespace GFx { namespace AS2 {

// The inlined CreateObjectInterface builds an AS2ValueObjectInterface, so its vftable is emitted here:
// MS2-PIN: ??_7AS2ValueObjectInterface@GFx@Scaleform@@6B@ 0x143222128
// MS2-PIN: ??_7ObjectInterface@Value@GFx@Scaleform@@6B@ 0x14317bc90

// MS2-FUNCTIONAL: the +0x78 hash and the +0x80 action queue block are zeroed by hand, and the member Ptrs are built
// in the init list (the exe AddRefs the ASSupport without a null test)
// @0x14291f070
MovieRoot::MovieRoot(MemoryContextImpl* pmemContext, MovieImpl* pmovie, ASSupport* pasSupport)
    : pAS2Support(pasSupport), MemContext(pmemContext),
      BuiltinsMgr(*reinterpret_cast<ASStringManager**>(reinterpret_cast<UByte*>(pmemContext) + 0x18))
{
    pMovieImpl = 0;
    pASSupport = pasSupport;
    AVMVersion = pasSupport->GetAVMVersion();
    GCFrameCnt         = 0;
    GCSeenCollectCount = 0;
    pMouseListener     = 0;
    pGlobalContext     = 0;
    // The invoke alias hash (+0x78) and the action queue block (+0x80) start zeroed.
    ::memset(Unrecovered_78, 0, 0x138 - 0x78);
    // The action queue starts at modification 1 and session 1 and allocates its entries from the movie's heap.
    ActionQueueType& queue = GetActionQueue();
    queue.ModId    = 1;
    queue.Field_a0 = 1;
    *reinterpret_cast<unsigned*>(&queue.Field_a8) = 1;
    queue.pHeap    = pmemContext->Heap;
    pMovieImpl     = pmovie;
    pmovie->SetASMovieRoot(this);

    pMovieImpl->pObjectInterface = SF_HEAP_NEW(pMovieImpl->pHeap) AS2ValueObjectInterface(pMovieImpl);
//
//
//
//
//
//
//
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The shared base's only non-pure slot: both movie roots keep the base's implementation unless they override it.
// @0x142528740
void ASMovieRootBase::SetMovie(MovieImpl* pmovie)
{
    pMovieImpl = pmovie;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7MovieRoot@AS2@GFx@Scaleform@@6B@ 0x1432177d8
// MS2-PIN: ??_7ASMovieRootBase@GFx@Scaleform@@6B@ 0x14317bde0
// MS2-PIN: ??_7?$RefCountBase@VASMovieRootBase@GFx@Scaleform@@$0BEH@@Scaleform@@6B@ 0x14317bde0
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7RefCountImpl@Scaleform@@6B@ 0x142dc9d58
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937a8
