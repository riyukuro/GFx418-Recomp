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
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The movie's value interface (exe vftable 0x143222128; its members are recovered elsewhere).
extern const void* DAT_143222128[];

// MS2-FUNCTIONAL: the unmodelled words (+0x28 entry, +0x78 action queue block, +0x638) are zeroed by hand and the
// value interface is built from raw words
// @0x14291f070
MovieRoot::MovieRoot(MemoryContextImpl* pmemContext, MovieImpl* pmovie, ASSupport* pasSupport)
    : BuiltinsMgr(*reinterpret_cast<ASStringManager**>(reinterpret_cast<UByte*>(pmemContext) + 0x18))
{
    pMovieImpl = 0;
    pASSupport = pasSupport;
    AVMVersion = pasSupport->GetAVMVersion();
    ::memset(Unrecovered_28, 0, sizeof(Unrecovered_28));
    pAS2Support = pasSupport;
    pasSupport->AddRef();
    MemContext = pmemContext;
    if (pmemContext)
        pmemContext->AddRef();
    GCFrameCnt         = 0;
    GCSeenCollectCount = 0;
    pMouseListener     = 0;
    pGlobalContext     = 0;
    ::memset(Unrecovered_78, 0, sizeof(Unrecovered_78));
    pLevelRoots    = 0;
    LevelRootCount = 0;
    pMovieImpl     = pmovie;
    pmovie->SetASMovieRoot(this);

    UPInt* pif = static_cast<UPInt*>(pMovieImpl->pHeap->Alloc(0x10));
    if (pif)
    {
        pif[1] = reinterpret_cast<UPInt>(pMovieImpl);
        pif[0] = reinterpret_cast<UPInt>(DAT_143222128);
        pMovieImpl->pObjectInterface = pif;
    }
    else
        pMovieImpl->pObjectInterface = 0;
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
