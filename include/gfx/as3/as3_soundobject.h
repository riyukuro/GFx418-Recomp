// Recovered Scaleform GFx 4.1.18 AS3 sound object (the player behind flash.media.Sound / SoundChannel); our own
// declarations. Bodies in sfr_as3_21 (0x142564d80-0x142565a30).
#ifndef MS2_SF_GFX_AS3_SOUNDOBJECT_H
#define MS2_SF_GFX_AS3_SOUNDOBJECT_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/gfx/gfx_sound.h"

namespace Scaleform { namespace GFx {

class MovieImpl;
class CharacterHandle;

namespace AS3 {

class ASVM;
namespace Instances { namespace fl_media { class Sound; } }

// 0x48 bytes; vftables 0x143182f50 (RefCountBase part) and 0x143182f58 (ASSoundIntf part).
class SoundObject : public RefCountBase<SoundObject, 0x143>, public ASSoundIntf   // StatMV_ActionScript_Mem
{
public:
    void  LoadFile(const String& url, bool streaming);  // 0x142565470
    void  SetVolume(int volume);                        // 0x142565980
    void  SetPan(int pan);                              // 0x142565940
    float GetPosition();                                // 0x1425653a0
    float GetDuration();                                // 0x142565360

    // (appended, sfr_as3_21) the rest of the object
    SoundObject(ASVM& asvm, Instances::fl_media::Sound* psound);   // 0x142564d80
    ~SoundObject();                                                // 0x142564ea0

    void     AttachToTarget(Sprite* psprite);           // 0x142565230
    void     DetachFromTarget();                        // 0x1425652c0
    Sprite*  GetSprite();                               // 0x142565400

    // ASSoundIntf
    virtual void ExecuteOnSoundComplete();              // 0x142565310: the Sound's soundComplete event
    virtual void ReleaseTarget();                       // 0x1425658e0
    virtual bool HasPrivateOverride()   { return true; }
    virtual int  PrivateVolume()        { return GetVolume(); }
    virtual int  PrivatePan()           { return GetPan(); }

    void     AttachResource(SoundResource* presource);  // 0x142565140
    void     Play(int startTime, int loops);            // 0x142565720
    void     Stop();                                    // 0x1425659c0
    int      GetVolume();                               // 0x142565440
    int      GetPan();                                  // 0x142565390
    unsigned GetBytesLoaded();                          // 0x142565320
    unsigned GetBytesTotal();                           // 0x142565340

    int                          Volume;          // +0x18
    int                          Pan;             // +0x1c
    Instances::fl_media::Sound*  pSound;          // +0x20 the AS3 object the events go to
    Ptr<Sound::SoundSample>      pSample;         // +0x28
    Ptr<SoundResource>           pResource;       // +0x30 set when the sample came from the movie's library
    Ptr<CharacterHandle>         pTargetHandle;   // +0x38 the sprite the sound plays on
    MovieImpl*                   pMovieRoot;      // +0x40
};

}}} // namespace Scaleform::GFx::AS3

#endif
