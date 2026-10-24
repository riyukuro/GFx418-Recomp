// Recovered Scaleform GFx 4.1.18 AS3: the stage's frame counter, the last entry of the play list, which queues the
// frame scripts and frame events of the whole play list once per frame. Stage::OnInsertionAsLevel 0x14251a110
// builds it inline (0xe0 bytes, no parent, ResourceId 0) and adds it to the play list.
// vftables 0x14317e608 (115 slots; over InteractiveObject's 0x14318df70 it overrides only 0, 54, 59, 65, 97, 105)
// and 0x14317e9a0 (+0x18). The deleting destructor 0x1424e2de0 releases pRoot and frees 0xe0 bytes.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Units that define a local class FrameCounter of their own (sfr_as3_18) must not include this header.
#ifndef MS2_SF_GFX_AS3_FRAMECOUNTER_H
#define MS2_SF_GFX_AS3_FRAMECOUNTER_H

#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"

namespace Scaleform { namespace GFx {

namespace AS3 {

class FrameCounter : public InteractiveObject
{
    Ptr<DisplayObjContainer> pRoot;     // +0xd8 never set by the recovered code (the ctor clears it)
public:
    FrameCounter(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
        : InteractiveObject(pbindingDefImpl, pasRoot, pparent, id)
    {
    }
    ~FrameCounter() {}                                                              // ??_G 0x1424e2de0

    virtual void            ForceShutdown() {}                                     // 54 0x142504850
    virtual CharacterDef*   GetCharacterDef() const { return NULL; }               // 59 0x142507b60
    virtual void            AdvanceFrame(bool nextFrame, float framePos = 0.0f);   // 65 0x1424eb260
    virtual int             CheckAdvanceStatus(bool playingNow) { SF_UNUSED(playingNow); return 1; } // 97 0x1424eec90
    virtual unsigned        GetLoadingFrame() const { return 1; }                  // 105 0x14250b390

    void QueueFrameActions();                                                       // 0x14251ff60
};
static_assert(sizeof(FrameCounter) == 0xe0, "FrameCounter size");

}}} // namespace Scaleform::GFx::AS3

#endif
