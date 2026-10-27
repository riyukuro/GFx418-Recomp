// Recovered Scaleform 4.1.18 Sound: SoundRendererFMOD, the FMOD Ex sound renderer interface (built without the FMOD
// Designer event system: GFxSoundFMOD::Finalize calls Finalize through slot 12). The implementation is in the statically
// linked library; the GFx UI's GFxSoundFMOD (gfxui/gfxsoundfmod.cpp) creates it.
#ifndef MS2_SF_SOUND_SOUNDRENDERERFMOD_H
#define MS2_SF_SOUND_SOUNDRENDERERFMOD_H

#include "sound_renderer.h"

namespace FMOD { class System; }

namespace Scaleform { namespace Sound {

class SoundRendererFMOD : public SoundRenderer
{
public:
    static SoundRendererFMOD* CreateSoundRenderer();

    virtual FMOD::System* GetFMODSystem() = 0;                                                        // 10
    virtual bool          Initialize(FMOD::System* pd, bool callFmodUpdate = true,
                                     bool threadedUpdate = true) = 0;                                  // 11
    virtual void          Finalize() = 0;                                                             // 12
};

}} // namespace Scaleform::Sound

#endif
