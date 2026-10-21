// Recovered Scaleform 4.1.18 Sound: sound data (a sample's format, rate and length, with the samples in memory or
// in a file) and the sound info a GFx resource holds (sfr lane, written from the exe). Shared header of the
// src/ms2/scaleform units: append, do not reorder.
//
// Out-of-line members bind to the exe until the Sound units are recovered: SoundFile ctor 0x142747cf0,
// ~SoundInfo 0x142748430, SoundInfo GetRate 0x142748490, GetSoundSample 0x1427484a0, SetSoundData 0x142748580,
// ReleaseResource 0x142748540.
#ifndef MS2_SF_SOUND_SOUND_H
#define MS2_SF_SOUND_SOUND_H

#include "../kernel/sf_refcount.h"
#include "sound_renderer.h"

namespace Scaleform { namespace Sound {

// Allocation stat of the sound objects (Stat_Default_Mem + 2).
enum { Stat_Sound_Mem = 4 };

// Sample data description (RefCountBaseNTS, 0x20 bytes).
class SoundDataBase : public RefCountBaseNTS<SoundDataBase, Stat_Sound_Mem>
{
public:
    enum SampleFormat
    {
        Sample_None   = 0,
        Sample_8      = 0x001,
        Sample_16     = 0x002,
        Sample_Stereo = 0x008,
        Sample_PCM    = 0x100,
        Sample_MP3    = 0x200,
        Sample_ADPCM  = 0x300,
        Sample_Format = 0x700,
        Sample_Stream = 0x1000,
        Sample_File   = 0x2000
    };

    SoundDataBase(unsigned format, unsigned rate, unsigned length)
        : Format(format), Rate(rate), Length(length), SeekSample(0) {}

    unsigned GetFormat() const      { return Format; }
    unsigned GetRate() const        { return Rate; }
    unsigned GetSampleCount() const { return Length; }
    bool     IsStreamSample() const { return (Format & Sample_Stream) != 0; }
    bool     IsFileSample() const   { return (Format & Sample_File) != 0; }

    void     SetSeekSample(unsigned sample) { SeekSample = sample; }
    unsigned GetSeekSample() const          { return SeekSample; }

protected:
    unsigned Format;     // +0x10
    unsigned Rate;       // +0x14
    unsigned Length;     // +0x18 samples
    unsigned SeekSample; // +0x1c samples skipped at the start
};

// Samples in memory.
class SoundData : public SoundDataBase
{
public:
    SoundData(unsigned format, unsigned rate, unsigned length, unsigned dsize);
    ~SoundData();

    UByte*   GetData() const     { return pData; }
    unsigned GetDataSize() const { return DataSize; }

protected:
    UByte*   pData;    // +0x20
    unsigned DataSize; // +0x28
};

// Samples in a file (0x28 bytes, vftable 0x1431bef80); the format is Sample_File, plus Sample_Stream when
// streaming.
class SoundFile : public SoundDataBase
{
public:
    SoundFile(const char* fname, unsigned rate, unsigned length, bool streaming);
    ~SoundFile();

    const char* GetFileName() const { return pFileName; }

protected:
    char* pFileName; // +0x20
};

class SoundInfoBase : public RefCountBaseNTS<SoundInfoBase, Stat_Sound_Mem>
{
public:
    virtual unsigned     GetLength() const                         = 0;
    virtual unsigned     GetRate() const                           = 0;
    virtual SoundSample* GetSoundSample(SoundRenderer* prenderer)  = 0;
    virtual bool         SetSoundData(SoundDataBase*)              { return false; }
    virtual bool         IsPlayable() const                        { return false; }
    virtual void         ReleaseResource()                         = 0;
};

// The data and, once played, the renderer's sample for it (0x20 bytes, vftable 0x14318ffa8).
class SoundInfo : public SoundInfoBase
{
protected:
    Ptr<SoundDataBase> pSound;       // +0x10
    Ptr<SoundSample>   pSoundSample; // +0x18

public:
    explicit SoundInfo(SoundDataBase* psound = 0) : pSound(psound) {}
    virtual ~SoundInfo();

    SoundDataBase* GetSound() const { return pSound; }

    unsigned     GetLength() const { return pSound->GetSampleCount(); }
    unsigned     GetRate() const;
    SoundSample* GetSoundSample(SoundRenderer* prenderer);
    bool         SetSoundData(SoundDataBase* psound);
    virtual bool IsPlayable() const { return pSound.GetPtr() != 0; }
    virtual void ReleaseResource();
};

}} // namespace Scaleform::Sound

#endif
