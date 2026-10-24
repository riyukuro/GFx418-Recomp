// Recovered Scaleform 4.1.18 GFx: SWF sounds as the loader and the timelines see them (event sounds and their play
// styles, streaming sound definitions, sound resources and their creators, button sounds, the sound tag reader).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Bodies: GFx_SoundResource (sfr_gfx_08d), GFx_Sound (sfr_gfx_08e), GFx_SoundTagsReader (sfr_gfx_08f).
#ifndef MS2_SF_GFX_SOUND_H
#define MS2_SF_GFX_SOUND_H

#include "gfx_loaderimpl.h"
#include "gfx_moviedef.h"
#include "gfx_resource.h"
#include "gfx_state.h"
#include "gfx_stream.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_memory.h"
#include "../sound/sound_renderer.h"
#include "../sound/sound_sound.h"

namespace Scaleform { namespace GFx {

// Allocation stat of the sound definitions.
enum { StatMD_Sounds_Mem = 0x147 };

class InteractiveObject;
class LoadProcess;
class MovieImpl;
class Sprite;
class SoundResource;
class SoundTagsReader;

// Audio / video synchronization settings of a movie, and its sound renderer.
class AudioBase : public State
{
public:
    enum SyncTypeFlags
    {
        NoSync      = 0,
        VideoMaster = 1, // the sound follows the frames
        AudioMaster = 2  // the frames follow the sound
    };

    virtual Sound::SoundRenderer* GetRenderer() const = 0;
    virtual SoundTagsReader*      GetSoundTagsReader() const = 0;

    float         GetMaxTimeDifference() const  { return MaxTimeDifference; }
    unsigned      GetCheckFrameInterval() const { return CheckFrameInterval; }
    SyncTypeFlags GetSyncType() const           { return SyncType; }

protected:
    float         MaxTimeDifference;  // +0x18 seconds
    unsigned      CheckFrameInterval; // +0x1c frames between checks
    SyncTypeFlags SyncType;           // +0x20
};

// Volume point of an event sound (8 bytes).
class SoundEnvelope
{
public:
    UInt32 Mark44; // position in samples at 44 kHz
    UInt16 Level0; // left volume, 0..32768
    UInt16 Level1; // right volume
};

// How an event sound plays (StartSound / button sound records, 0x30 bytes).
class SoundStyle
{
public:
    bool                 NoMultiple;   // +0 do not start while already playing
    bool                 StopPlayback; // +1
    bool                 HasEnvelope;  // +2
    bool                 HasLoops;     // +3
    bool                 HasOutPoint;  // +4
    bool                 HasInPoint;   // +5
    UInt32               InPoint;      // +8 samples
    UInt32               OutPoint;     // +0xc
    UInt16               LoopCount;    // +0x10
    Array<SoundEnvelope> Envelopes;    // +0x18

    void Read(Stream* in);
};

// An event sound and its style (0x48 bytes).
class SoundInfo
{
public:
    ResourcePtr<SoundResource> pSample; // +0
    SoundStyle                 Style;   // +0x10
    ResourceId                 SoundId; // +0x40

    SoundInfo();
    ~SoundInfo();

    void Play(InteractiveObject* pchar);
};

// Sound of a timeline frame by frame (SoundStreamHead / SoundStreamBlock tags).
class SoundStreamDef : public RefCountBaseNTS<SoundStreamDef, StatMD_Sounds_Mem>
{
public:
    virtual ~SoundStreamDef() {}
    virtual bool ProcessSwfFrame(MovieImpl* proot, unsigned frame, Sprite* pchar) = 0;
};

class SoundStreamDefImpl : public SoundStreamDef
{
public:
    unsigned              PlaybackSoundRate;  // +0x10
    unsigned              PlaybackSound16bit; // +0x14
    unsigned              PlaybackStereo;     // +0x18
    unsigned              SoundCompression;   // +0x1c SWF sound format
    unsigned              StreamSoundRate;    // +0x20
    unsigned              StreamSound16bit;   // +0x24
    unsigned              StreamStereo;       // +0x28
    unsigned              StreamSampleCount;  // +0x2c per block
    unsigned              LatencySeek;        // +0x30 MP3 samples to skip
    unsigned              StartFrame;         // +0x34 first frame with a block
    unsigned              LastFrame;          // +0x38
    Ptr<Sound::SoundInfo> pSoundInfo;         // +0x40

    SoundStreamDefImpl();
    ~SoundStreamDefImpl();

    void         ReadHeadTag(Stream* in);
    void         ReadBlockTag(LoadProcess* p);
    virtual bool ProcessSwfFrame(MovieImpl* proot, unsigned frame, Sprite* pchar);
};

// Reads the DefineSound data after the character id.
Sound::SoundData* GFx_ReadSoundData(LoadProcess* p, UInt16 characterId);

// File info of an external sound (0x50 bytes, vftable 0x14318ffe0).
struct SoundFileInfo : public ResourceFileInfo
{
    unsigned Use;         // +0x28
    String   ExportName;  // +0x30
    unsigned Bits;        // +0x38
    unsigned Channels;    // +0x3c
    unsigned SampleRate;  // +0x40
    unsigned SampleCount; // +0x44
    unsigned SeekSample;  // +0x48

    SoundFileInfo() { Use = Resource::Use_SoundSample; }
    SoundFileInfo(const SoundFileInfo& other) : ResourceFileInfo(other)
    {
        Use         = other.Use;
        ExportName  = other.ExportName;
        Bits        = other.Bits;
        Channels    = other.Channels;
        SampleRate  = other.SampleRate;
        SampleCount = other.SampleCount;
        SeekSample  = other.SeekSample;
    }
};

// A sound sample resource (0x38 bytes).
class SoundResource : public Resource
{
public:
    SoundResource(Sound::SoundInfoBase* psound, ResourceUse use = Use_SoundSample)
    {
        pSoundInfo   = psound;
        UseType      = use;
        PlayingCount = 0;
    }
    SoundResource(Sound::SoundInfoBase* psound, const ResourceKey& key, ResourceUse use = Use_SoundSample)
    {
        pSoundInfo   = psound;
        Key          = key;
        UseType      = use;
        PlayingCount = 0;
    }

    virtual ResourceKey GetKey();
    virtual unsigned    GetResourceTypeCode() const { return MakeTypeCode(RT_SoundSample, UseType); }

    static ResourceKey CreateSoundFileKey(SoundFileInfo* pfileInfo, FileOpener* pfileOpener);

    Sound::SoundInfoBase* GetSoundInfo() const { return pSoundInfo; }
    // Count of the channels playing this sample; the sample data is released when it drops to zero.
    void IncPlayingCount()  { PlayingCount++; }
    void DecPlayingCount()  { PlayingCount--; }
    bool IsPlaying() const  { return PlayingCount > 0; }

protected:
    Ptr<Sound::SoundInfoBase> pSoundInfo;   // +0x18
    ResourceKey               Key;          // +0x20
    ResourceUse               UseType;      // +0x30
    int                       PlayingCount; // +0x34
};

// Creates the resource of embedded sound data.
class SoundResourceCreator : public ResourceData::DataInterface
{
    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const;

public:
    static ResourceData CreateSoundResourceData(Sound::SoundData* psound);
};

// Loads an external sound file, shared through the resource library.
class SoundFileResourceCreator : public ResourceData::DataInterface
{
    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const;

public:
    static ResourceData CreateSoundFileResourceData(SoundFileInfo* prfi);
};

// Sounds of the four button states (ButtonSound tag).
class ButtonSoundDef : public NewOverrideBase<StatMD_Sounds_Mem>
{
public:
    virtual ~ButtonSoundDef() {}
    virtual void Play(InteractiveObject* pchar, int buttonIdx) = 0;
};

class ButtonSoundDefImpl : public ButtonSoundDef
{
public:
    SoundInfo ButtonSounds[4]; // +8: up to over, over to up, over to down, down to over

    virtual ~ButtonSoundDefImpl();
    virtual void Play(InteractiveObject* pchar, int buttonIdx);
};

// Allocation stat of the sound tag reader.
enum { StatMD_SoundTagsReader_Mem = 0x107 };

// Reads the sound tags of a SWF file for the loader (vftable 0x143184c08).
class SoundTagsReader : public RefCountBaseNTS<SoundTagsReader, StatMD_SoundTagsReader_Mem>
{
public:
    virtual ButtonSoundDef* ReadButtonSoundDef(LoadProcess* p);
    virtual void ReadDefineSoundTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadStartSoundTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadButtonSoundTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadDefineExternalSoundTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadDefineExternalStreamSoundTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadSoundStreamHeadTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual void ReadSoundStreamBlockTag(LoadProcess* p, const TagInfo& tagInfo);
};

// Script side of a sound (the AS2 Sound object / AS3 SoundChannel) as the clips see it. Slot order of the exe's
// vftable 0x143182f18 (Sprite calls ExecuteOnSoundComplete at +8 and ReleaseTarget at +0x10; 4.1.18 has no GetOwner).
class ASSoundIntf
{
public:
    virtual ~ASSoundIntf() {}

    virtual void ExecuteOnSoundComplete() = 0;
    // The clip the sound was attached to is going away.
    virtual void ReleaseTarget()          = 0;
    // A sound with its own transform ignores the clip's volume and pan.
    virtual bool HasPrivateOverride()     { return false; }
    virtual int  PrivateVolume()          { return 100; }
    virtual int  PrivatePan()             { return 0; }
};

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::SoundFileInfo) == 0x50, "SoundFileInfo size");
static_assert(sizeof(Scaleform::GFx::SoundStreamDefImpl) == 0x48, "SoundStreamDefImpl size");

#endif
