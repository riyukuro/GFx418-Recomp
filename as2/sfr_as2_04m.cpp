// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 frame actions and level teardown
// (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429329a0-0x142932aa4 .text$mn
// MS2-RANGE: 0x142934480-0x1429345b5 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

void FUN_1425f4090(void* pobj);
void FUN_14257dcd0();

// Runs the action tags of one frame as their own action session (gotoAndPlay's callFrame).
// MS2-FUNCTIONAL: the frame count and the session counter are reached by slot and by address
// @0x1429329a0
void AvmSprite::CallFrameActions(unsigned frame)
{
    Sprite* psprite = GetSprite();
    typedef unsigned (*FrameCountFn)(Sprite*);
    if (frame != 0xffffffffu &&
        frame < reinterpret_cast<FrameCountFn>((*reinterpret_cast<void***>(psprite))[0x348 / 8])(psprite))
    {
        MovieRoot::ActionQueueType& queue   = GetAS2Root()->GetActionQueue();
        unsigned                    saved   = queue.Field_a0;
        unsigned*                   counter = reinterpret_cast<unsigned*>(&queue.Field_a8);
        unsigned                    session = ++*counter;
        queue.Field_a0                      = session;
        TimelineDef::Frame playlist         = psprite->pDef->GetPlaylist(frame);
        for (unsigned i = 0; i < playlist.TagCount; ++i)
        {
            ExecuteTag* ptag = playlist.pTagPtrList[i];
            if (ptag->IsActionTag())
                ptag->Execute(psprite);
        }
        queue.Field_a0 = saved;
        GetAS2Root()->DoActionsForSession(session);
        return;
    }
    psprite->LogError("CallFrame('%d') - unknown frame", frame);
}

// Clears every level's display list, then lets each level run its teardown slot and empties the level array.
// MS2-FUNCTIONAL: the levels are raw words of the movie, the level slot is reached by address
// @0x142934480
void MovieRoot::ClearDisplayList()
{
    typedef void (*LevelSlot)(void*);
    MovieImpl* pmovie = pMovieImpl;
    for (UPInt n = pmovie->MovieLevelsSize; n != 0; --n)
    {
        DisplayObjContainer* plevel = reinterpret_cast<DisplayObjContainer*>(pmovie->pMovieLevels[n - 1].pSprite);
        plevel->mDisplayList.Clear(plevel);
        FUN_1425f4090(plevel);
    }
    for (UPInt n = pmovie->MovieLevelsSize; n != 0; --n)
    {
        void* plevel = pmovie->pMovieLevels[n - 1].pSprite;
        reinterpret_cast<LevelSlot>((*static_cast<void***>(plevel))[0x1b0 / 8])(plevel);
    }
    UPInt size = pmovie->MovieLevelsSize;
    if (size != 0)
    {
        for (UPInt n = size; n != 0; --n)
            if (pmovie->pMovieLevels[n - 1].pSprite)
                FUN_14257dcd0();
        if (pmovie->MovieLevelsCapacity & ~UPInt(1))
        {
            if (pmovie->pMovieLevels)
            {
                Memory::pGlobalHeap->Free(pmovie->pMovieLevels);
                pmovie->pMovieLevels = 0;
            }
            pmovie->MovieLevelsCapacity = 0;
        }
    }
    pmovie->MovieLevelsSize = 0;
}

}}} // namespace Scaleform::GFx::AS2
