// Recovered Scaleform 4.1.18 Sound: the renderer interface the video and sound code talk to (sfr lane, written from the
// exe). Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// Slot order checked against the exe's callers (Video_Video): SoundRenderer GetRenderCaps +0x08,
// CreateSampleFromAuxStreamer +0x20, PlaySample +0x28; SoundChannel Stop +0x18 ... SetSpatialInfo +0x70 (the
// SoundChannelDelegate vtable 0x1431b8160 fills all 15 slots).
#ifndef MS2_SF_SOUND_RENDERER_H
#define MS2_SF_SOUND_RENDERER_H

#include "../kernel/sf_array.h"
#include "../kernel/sf_refcount.h"
#include <intrin.h>

namespace Scaleform { namespace Sound {

class SoundRenderer;
class SoundDataBase;

// A sound sample counts its references itself (atomic, inline), unlike the RefCountBase classes.
class SoundSample : public NewOverrideBase<Stat_Default_Mem>
{
public:
    SoundSample()          { RefCount = 1; }
    virtual ~SoundSample() {}

    virtual SoundRenderer* GetSoundRenderer() const = 0;
    virtual bool           IsDataValid() const      = 0;
    virtual float          GetDuration() const      = 0;
    virtual int            GetBytesTotal() const    = 0;
    virtual int            GetBytesLoaded() const   = 0;

private:
    volatile long RefCount;

public:
    void AddRef() { _InterlockedExchangeAdd(&RefCount, 1); }
    void Release()
    {
        if ((_InterlockedExchangeAdd(&RefCount, -1) - 1) == 0)
            delete this;
    }
};

// A playing sound.
class SoundChannel : public RefCountBase<SoundChannel, Stat_Default_Mem>
{
public:
    struct Transform
    {
        float Position;
        float LeftVolume;
        float RightVolume;
    };
    struct Vector
    {
        float X, Y, Z;
        Vector() : X(0.0f), Y(0.0f), Z(0.0f) {}
    };

    SoundChannel() {}

    virtual SoundRenderer* GetSoundRenderer() const                          = 0; // 1
    virtual SoundSample*   GetSample() const                                 = 0; // 2
    virtual void           Stop()                                            = 0; // 3
    virtual void           Pause(bool pause)                                 = 0; // 4
    virtual bool           IsPlaying() const                                 = 0; // 5
    virtual void           SetPosition(float seconds)                        = 0; // 6
    virtual float          GetPosition()                                     = 0; // 7
    virtual void           Loop(int count, float start = 0, float end = 0)   = 0; // 8
    virtual float          GetVolume()                                       = 0; // 9
    virtual void           SetVolume(float volume)                           = 0; // 10
    virtual float          GetPan()                                          = 0; // 11
    virtual void           SetPan(float pan)                                 = 0; // 12
    virtual void           SetTransforms(const Array<Transform>& transforms) = 0; // 13
    virtual void           SetSpatialInfo(const Array<Vector> spatinfo[])    = 0; // 14
};

class SoundRenderer : public RefCountBase<SoundRenderer, Stat_Default_Mem>
{
public:
    enum SoundRendererCapBits
    {
        Cap_NoMP3        = 0x00000001,
        Cap_NoVideoSound = 0x00000002,
        Cap_NoStreaming  = 0x00000004
    };

    // Pull interface for PCM data coming from another source (video audio tracks).
    class AuxStreamer : public RefCountBase<AuxStreamer, Stat_Default_Mem>
    {
    public:
        enum PCMFormat
        {
            PCM_SInt16,
            PCM_Float
        };
        virtual ~AuxStreamer() {}
        virtual unsigned GetPCMData(UByte* pdata, unsigned datasize) = 0;
        virtual bool     SetPosition(float) { return false; }
    };

    SoundRenderer() {}
    virtual ~SoundRenderer() {}

    virtual bool          GetRenderCaps(UInt32* pcaps)                         = 0; // 1
    virtual SoundSample*  CreateSampleFromFile(const char* fname, bool streaming) = 0; // 2
    virtual SoundSample*  CreateSampleFromData(SoundDataBase* psd)             = 0; // 3
    virtual SoundSample*  CreateSampleFromAuxStreamer(AuxStreamer*, UInt32, UInt32, AuxStreamer::PCMFormat)
                                                                               { return 0; } // 4
    virtual SoundChannel* PlaySample(SoundSample* ps, bool paused)             = 0; // 5
    virtual float         GetMasterVolume()                                    = 0;
    virtual void          SetMasterVolume(float volume)                        = 0;
    virtual float         Update()                                             = 0;
    virtual void          Mute(bool mute)                                      = 0;
};

}} // namespace Scaleform::Sound

#endif
