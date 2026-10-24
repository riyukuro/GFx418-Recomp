// Recovered Scaleform GFx 4.1.18 AS3: the movie root's event chains (AS3::MovieRoot +0x150), one list per frame or
// activation event of the display objects that listen for it. A single word: the table pointer of an uncached
// HashLH<int, AutoPtr<ArrayLH<WeakPtr<DisplayObject>, 2> > > (the exe's dtor 0x1424dcbb0 names that HashSetBase).
// Entries are only nulled while a chain may be walked (RemoveFromChain); QueueEvents / Dispatch drop them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Units that define a local class EventChains of their own (sfr_as3_09, sfr_as3_17, sfr_as3_18) must not include
// this header.
#ifndef MS2_SF_GFX_AS3_EVENTCHAINS_H
#define MS2_SF_GFX_AS3_EVENTCHAINS_H

#include "ms2/scaleform/include/kernel/sf_hash.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/gfx_eventid.h"

namespace Scaleform { namespace GFx {

class DisplayObject;

namespace AS3 {

class EventChains
{
public:
    // Scaleform::AutoPtr, not the GFx::AutoPtr of gfx_moviedef.h: the exe's mangled names use the kernel one.
    typedef ArrayLH<WeakPtr<DisplayObject>, Stat_Default_Mem>                    Chain;
    typedef HashUncachedLH<int, Scaleform::AutoPtr<Chain>, IdentityHash<int>, Stat_Default_Mem> ChainHash;

    void         AddToChain(EventId::IdCode evtId, DisplayObject* obj);          // 0x1424eac70
    void         RemoveFromChain(EventId::IdCode evtId, DisplayObject* obj);     // 0x142522830
    void         QueueEvents(EventId::IdCode evtId);                             // 0x14251fd40
    // Fires the event on every live object of its chain.
    void         Dispatch(EventId::IdCode evtId);                                // 0x1424f71b0
    // NULL when nothing listens for evtId.
    const Chain* GetChain(EventId::IdCode evtId) const;                          // 0x142507a70

private:
    // SF_MAX_UPINT when obj is not in the chain.
    UPInt        FindObjectIndexInChain(Chain* chain, DisplayObject* obj);       // 0x142501dc0

    ChainHash    Chains;     // +0x00
};
// MovieRoot keeps it at +0x150 with pStage at +0x158 (as3_asvm.h).
static_assert(sizeof(EventChains) == 8, "EventChains size");

}}} // namespace Scaleform::GFx::AS3

#endif
