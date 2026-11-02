// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 frame advance: the collector's
// per-movie frame counting and the movie clip's AdvanceFrame.
// MS2-UNIT: sfr_as2_04k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142931300-0x142931423 .text$mn
// MS2-RANGE: 0x142931430-0x14293157e .text$mn
// MS2-RANGE: 0x142931580-0x1429316b8 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The frame accounting of one movie against the collector: a movie counts frames until the collector's limit, then
// the collector counts the frame in turn and collects when the root count or the frame count asks for it.
static SF_FORCEINLINE void CollectorAdvanceFrame(ASRefCountCollector* pgc, unsigned* pframeCnt, unsigned* pseenCount)
{
    if (*pseenCount != pgc->CollectCount)
    {
        *pseenCount = pgc->CollectCount;
        *pframeCnt  = 1;
        return;
    }
    if (*pframeCnt < pgc->FrameCnt)
    {
        ++*pframeCnt;
        return;
    }
    unsigned roots = pgc->GetRootsCount();
    ++pgc->FrameCountTotal;
    ++pgc->FrameCnt;
    pgc->PeakRootCount = Alg::Max(pgc->PeakRootCount, roots);
    if ((pgc->PresetMaxRootCount != 0 && roots > pgc->MaxRootCount) ||
        (pgc->PresetFramesBetween != 0 && pgc->FrameCnt >= pgc->PresetFramesBetween && roots > pgc->PresetMaxRootCount))
    {
        RefCountCollector<StatMV_ActionScript_Mem>::Stats stats;
        pgc->Collect(&stats);
        if (stats.RootsFreedTotal > pgc->PresetMaxRootCount)
        {
            pgc->PeakRootCount = roots;
            pgc->MaxRootCount  = pgc->PresetMaxRootCount;
        }
        pgc->MaxRootCount = Alg::Max(pgc->MaxRootCount, roots - stats.RootsFreedTotal);
        if (pgc->PeakRootCount < (unsigned)(pgc->MaxRootCount * 0.7))
            pgc->MaxRootCount = (unsigned)(pgc->MaxRootCount * 0.7);
        pgc->CollectCount      = pgc->FrameCountTotal;
        pgc->FrameCnt          = 0;
        pgc->PeakRootCountLast = pgc->PeakRootCount;
        pgc->RootsLeftLast     = stats.RootsFreedTotal;
    }
    pgc->LastRootCount = roots;
    *pframeCnt         = pgc->FrameCnt;
    *pseenCount        = pgc->CollectCount;
}

// @0x142931300
void ASRefCountCollector::AdvanceFrame(unsigned* pframeCnt, unsigned* pseenCount)
{
    CollectorAdvanceFrame(this, pframeCnt, pseenCount);
}

// A frame of the clip: mouse drag, the next frame of a playing clip with its frame tags, the enterFrame event.
// MS2-FUNCTIONAL: the event is built member by member in both paths as in the exe, the rest follows its order
// @0x142931430
void AvmSprite::AdvanceFrame(bool nextFrame, float framePos)
{
    Ptr<Sprite> psprite = GetSprite();
    if (psprite->IsUnloading() ||
        (psprite->InteractiveObject::Flags & (InteractiveObject::Mask_NoAdvanceLocal | InteractiveObject::Mask_NoAdvanceGlobal)))
        return;
    if (psprite->GetMovieImpl()->IsMouseSupportEnabled())
        psprite->DoMouseDrag();
    if (!nextFrame)
        return;
    unsigned prevFrame = psprite->GetCurrentFrame();
    unsigned frame     = prevFrame;
    if (psprite->GetPlayState() == State_Playing)
    {
        psprite->IncrementFrameAndCheckForLoop();
        frame = psprite->GetCurrentFrame();
        if (frame != prevFrame)
        {
            // init action tags come before Event_EnterFrame, which comes before the frame's actions
            ExecuteInitActionFrameTags(frame);
            OnEvent(EventId(EventId::Event_EnterFrame));
            psprite->Sprite::ExecuteFrameTags(frame);
        }
        else
            OnEvent(EventId(EventId::Event_EnterFrame));
    }
    else
        OnEvent(EventId(EventId::Event_EnterFrame));
    if (frame == 0)
        psprite->mDisplayList.UnloadMarkedObjects(psprite);
}

// The movie's share of the collector's frame accounting (the exe inlines the collector's AdvanceFrame here).
// @0x142931580
void MovieRoot::AdvanceFrame(bool nextFrame)
{
    if (!nextFrame)
        return;
    CollectorAdvanceFrame(MemContext->ASGC, &GCFrameCnt, &GCSeenCollectCount);
}

}}} // namespace Scaleform::GFx::AS2
