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

void FUN_1425f4090(void* p);  // global in the exe
void FUN_14257dcd0(void* p);  // global in the exe

// The exe calls the out-of-line instantiation (sfr_as3_18) on the grow path of MovieLevels.Clear()
namespace Scaleform {
template<>
void ArrayDataBase<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 327>, ArrayDefaultPolicy>::Reserve(
    const void* pheapAddr, UPInt newCapacity);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// Runs the action tags of one frame as their own action session (gotoAndPlay's callFrame).
// @0x1429329a0
void AvmSprite::CallFrameActions(unsigned frame)
{
    typedef unsigned (*FrameCountFn)(Sprite*);
    if (frame == 0xffffffffu ||
        frame >= reinterpret_cast<FrameCountFn>((*reinterpret_cast<void***>(GetSprite()))[0x348 / 8])(GetSprite()))
    {
        GetSprite()->LogError("CallFrame('%d') - unknown frame", frame);
        return;
    }
    // ActionQueue.StartNewSession: Field_a0 is the current session, the dword at Field_a8 the last one handed out
    MovieRoot::ActionQueueType& queue   = GetAS2Root()->GetActionQueue();
    unsigned*                   plast   = reinterpret_cast<unsigned*>(&queue.Field_a8);
    unsigned                    saved   = queue.Field_a0;
    unsigned                    session = queue.Field_a0 = ++*plast;
    const TimelineDef::Frame playlist   = GetSprite()->pDef->GetPlaylist(frame);
    for (unsigned i = 0; i < playlist.TagCount; i++)
    {
        ExecuteTag* ptag = playlist.pTagPtrList[i];
        if (ptag->IsActionTag())
            ptag->Execute(GetSprite());
    }
    GetAS2Root()->GetActionQueue().Field_a0 = saved;
    GetAS2Root()->DoActionsForSession(session);
}

// The level clips, as the movie holds them (MovieImpl::LevelInfo with its counted sprite reference; as sfr_as3_17d).
struct Sfr04mLevelInfo
{
    int                    Level;
    Ptr<InteractiveObject> pSprite;
};

// Clears every level's display list, then lets each level run its teardown slot and empties the level array.
// @0x142934480
void MovieRoot::ClearDisplayList()
{
    typedef void (*LevelSlot)(void*);
    for (UPInt n = pMovieImpl->MovieLevelsSize; n != 0; --n)
    {
        DisplayObjContainer* plevel = reinterpret_cast<DisplayObjContainer*>(pMovieImpl->pMovieLevels[n - 1].pSprite);
        plevel->mDisplayList.Clear(plevel);
        FUN_1425f4090(plevel);
    }
    for (UPInt n = pMovieImpl->MovieLevelsSize; n != 0; --n)
    {
        void* plevel = pMovieImpl->pMovieLevels[n - 1].pSprite;
        reinterpret_cast<LevelSlot>((*static_cast<void***>(plevel))[0x1b0 / 8])(plevel);
    }
    reinterpret_cast<ArrayLH<Sfr04mLevelInfo, 0x147>*>(&pMovieImpl->pMovieLevels)->Clear();
}

}}} // namespace Scaleform::GFx::AS2
