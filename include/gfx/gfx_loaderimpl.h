// Recovered Scaleform 4.1.18 GFx: the loader implementation and the per-load state set
// (only the parts used by recovered units so far; layouts from the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Out-of-line members not recovered yet bind to the exe:
//   LoaderImpl::LoaderImpl(StateBag*, ResourceLib*, bool) 0x1425a8610,
//   LoaderImpl::CreateMovie_LoadState(LoadStates*, MovieDataDef*, unsigned, UPInt) 0x1425aa390,
//   LoadStates::LoadStates(LoaderImpl*, StateBag*, MovieDefBindStates*) 0x142636ed0.
#ifndef MS2_SF_GFX_LOADERIMPL_H
#define MS2_SF_GFX_LOADERIMPL_H

#include "gfx_moviedef.h"

namespace Scaleform { namespace GFx {

// Load option bits of Loader::CreateMovie.
class Loader
{
public:
    enum LoadConstants
    {
        LoadWaitCompletion = 0x01
    };
};

// States captured for one load (0xa0 bytes).
class LoadStates : public RefCountBase<LoadStates, Stat_Default_Mem>
{
public:
    LoadStates(LoaderImpl* ploader, StateBag* pstates = 0, MovieDefBindStates* pbindStates = 0);
    ~LoadStates();

private:
    UByte Unknown10[0x90]; // +0x10
};

// Shared loader state behind Loader (0x70 bytes).
class LoaderImpl : public RefCountBase<LoaderImpl, Stat_Default_Mem>
{
public:
    LoaderImpl(StateBag* pstates, ResourceLib* plib, bool debugHeap = false);
    ~LoaderImpl();

    static MovieDefImpl* SF_STDCALL CreateMovie_LoadState(LoadStates* pls, MovieDataDef* pmd, unsigned loadConstants,
                                                          UPInt memoryArena = 0);

private:
    UByte Unknown10[0x60]; // +0x10
};

}} // namespace Scaleform::GFx

#endif
