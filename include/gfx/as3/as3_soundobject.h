// Recovered Scaleform GFx 4.1.18 AS3 sound object (the player behind flash.media.Sound / SoundChannel); our own
// declarations. Only the members the AS3 natives call are declared; the data layout is not recovered.
#ifndef MS2_SF_GFX_AS3_SOUNDOBJECT_H
#define MS2_SF_GFX_AS3_SOUNDOBJECT_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/gfx/gfx_sound.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class SoundObject : public RefCountBase<SoundObject, 0x143>, public ASSoundIntf   // StatMV_ActionScript_Mem
{
public:
    void  LoadFile(const String& url, bool streaming);  // 0x142565470
    void  SetVolume(int volume);                        // 0x142565980
    void  SetPan(int pan);                              // 0x142565940
    float GetPosition();                                // 0x1425653a0
    float GetDuration();                                // 0x142565360
};

}}} // namespace Scaleform::GFx::AS3

#endif
