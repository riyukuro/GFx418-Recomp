// Recovered Scaleform 4.1.18 GFx: Audio, the AudioBase state over a sound renderer (GFx_Audio). Its members are in the
// Scaleform lib; the game's GFxManager (gfxui/gfxmanager.cpp) sets one on the loader over its FMOD renderer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AUDIO_H
#define MS2_SF_GFX_AUDIO_H

#include "gfx_sound.h"

namespace Scaleform { namespace GFx {

class Audio : public AudioBase
{
public:
    Audio(Sound::SoundRenderer* pplayer, float maxTimeDiff = 0.1f, unsigned checkFrameInterval = 15,
          SyncTypeFlags syncType = AudioMaster);
    ~Audio();

    virtual Sound::SoundRenderer* GetRenderer() const;
    virtual SoundTagsReader*      GetSoundTagsReader() const;
    virtual void                  RegisterASClasses(AS2::GlobalContext& gc, AS2::ASStringContext& sc);

protected:
    Ptr<Sound::SoundRenderer> pPlayer;     // +0x28
    SoundTagsReader*          pTagsReader; // +0x30
};

inline void StateBag::SetAudio(AudioBase* ptr) { SetState(State::State_Audio, ptr); }

}} // namespace Scaleform::GFx

#endif
