// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Sound (SWF event sounds and
// their play styles, streaming sound blocks kept in step with the timeline, and the SWF sound data readers with the
// ADPCM decoder).
// Fifth source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d2820-0x1426d4780 .text$mn

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_memory.h"
#include "../include/sound/sound_renderer.h"
#include "../include/sound/sound_sound.h"

namespace Scaleform { namespace GFx {

// Allocation stat of the sound definitions.
enum { StatMD_Sounds_Mem = 0x147 };

class InteractiveObject;
class SoundResource;

// Audio / video synchronization settings of a movie (only the fields read here).
class AudioBase : public State
{
public:
    enum SyncTypeFlags
    {
        NoSync      = 0,
        VideoMaster = 1, // the sound follows the frames
        AudioMaster = 2  // the frames follow the sound
    };

    float         GetMaxTimeDifference() const  { return MaxTimeDifference; }
    unsigned      GetCheckFrameInterval() const { return CheckFrameInterval; }
    SyncTypeFlags GetSyncType() const           { return SyncType; }

protected:
    float         MaxTimeDifference;  // +0x18 seconds
    unsigned      CheckFrameInterval; // +0x1c frames between checks
    SyncTypeFlags SyncType;           // +0x20
};

// The movie (only the fields read here).
class MovieImpl
{
    UByte Unknown0[0x250];

public:
    AudioBase*            pAudio;            // +0x250
    Sound::SoundRenderer* pSoundRenderer;    // +0x258

private:
    UByte Unknown260[0x14];

public:
    float                 FrameTime;         // +0x274 seconds per frame
    unsigned              ForceFrameCatchUp; // +0x278 frames to run at once to catch up with the sound
};

class Sprite
{
public:
    Sound::SoundChannel* GetStreamingSound() const;
    void                 SetStreamingSound(Sound::SoundChannel* pchan);
};

// A resource reference of a definition: the resource, or its index in the movie binding.
template<class C>
class ResourcePtr
{
public:
    enum PtrType
    {
        RP_Resource,
        RP_Index
    };

    ResourcePtr() : PType(RP_Resource), pResource(0) {}

protected:
    PtrType PType; // +0
    union
    {
        C*       pResource; // +8
        unsigned BindIndex;
    };
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

void GFx_AdpcmExpand(void* pdataOut, Stream* in, int codeBits, int sampleCount, bool stereo);
void s_ReadSoundData(Stream* in, int datasize, UByte* pdata, unsigned sample16bit, unsigned format);

// SWF sound formats.
enum SwfSoundFormat
{
    SwfSound_Raw         = 0, // native byte order PCM
    SwfSound_Adpcm       = 1,
    SwfSound_Mp3         = 2,
    SwfSound_RawLE       = 3, // little endian PCM
};

// @0x1426d2820
SoundInfo::SoundInfo()
{
}

// @0x1426d2840
SoundStreamDefImpl::SoundStreamDefImpl() : StartFrame(0), LastFrame(0)
{
}

// @0x1426d2870
SoundStreamDefImpl::~SoundStreamDefImpl()
{
}

// @0x1426d4610
void s_ReadSoundData(Stream* in, int datasize, UByte* pdata, unsigned sample16bit, unsigned format)
{
    if (sample16bit)
    {
        for (int i = 0; i < datasize >> 1; i++)
            ((UInt16*)pdata)[i] = in->ReadU16();
        if (datasize & 1)
            pdata[datasize - 1] = in->ReadU8();
    }
    else
    {
        // 8-bit raw samples are unsigned in the file; the renderer takes them signed.
        for (int i = 0; i < datasize; i++)
        {
            if (format == SwfSound_Raw || format == SwfSound_RawLE)
                pdata[i] = in->ReadU8() ^ 0x80;
            else
                pdata[i] = in->ReadU8();
        }
    }
}

// @0x1426d3280
Sound::SoundData* GFx_ReadSoundData(LoadProcess* p, UInt16 characterId)
{
    Stream* in = p->GetStream();

    const int sampleRates[] = { 5512, 11025, 22050, 44100 };

    unsigned format      = in->ReadUInt(4);
    unsigned rate        = sampleRates[in->ReadUInt(2)];
    unsigned sample16bit = in->ReadUInt1();
    unsigned stereo      = in->ReadUInt1();
    unsigned sampleCount = in->ReadU32();

    unsigned sf = (sample16bit ? Sound::SoundDataBase::Sample_16 : Sound::SoundDataBase::Sample_8) |
                  (stereo ? Sound::SoundDataBase::Sample_Stereo : 0);
    unsigned seekSample = 0;
    unsigned codeBits   = 2;

    switch (format)
    {
    case SwfSound_Raw:
    case SwfSound_RawLE:
        sf |= Sound::SoundDataBase::Sample_PCM;
        break;
    case SwfSound_Adpcm:
        // Decoded to PCM here.
        sf |= Sound::SoundDataBase::Sample_PCM;
        codeBits = in->ReadUInt(2);
        break;
    case SwfSound_Mp3:
        sf |= Sound::SoundDataBase::Sample_MP3;
        seekSample = in->ReadU16();
        break;
    }

    p->LogParse("define sound: ch=%d, format=%d, rate=%d, 16=%d, stereo=%d, ct=%d\n", characterId, format, rate,
                (int)sample16bit, (int)stereo, sampleCount);

    int               datasize = in->GetTagEndPosition() - in->Tell();
    Sound::SoundData* psound;
    if (format == SwfSound_Adpcm)
    {
        psound = SF_NEW Sound::SoundData(sf, rate, sampleCount, stereo ? sampleCount * 4 : sampleCount * 2);
        GFx_AdpcmExpand(psound->GetData(), in, codeBits + 2, sampleCount, stereo != 0);
    }
    else
    {
        psound = SF_NEW Sound::SoundData(sf, rate, sampleCount, datasize);
        psound->SetSeekSample(seekSample);
        s_ReadSoundData(in, datasize, psound->GetData(), sample16bit, format);
    }
    return psound;
}

// @0x1426d3be0
void SoundStyle::Read(Stream* in)
{
    InPoint = OutPoint = LoopCount = 0;

    in->ReadUInt(2); // reserved
    StopPlayback = in->ReadUInt(1) != 0;
    NoMultiple   = in->ReadUInt(1) != 0;
    HasEnvelope  = in->ReadUInt(1) != 0;
    HasLoops     = in->ReadUInt(1) != 0;
    HasOutPoint  = in->ReadUInt(1) != 0;
    HasInPoint   = in->ReadUInt(1) != 0;

    if (HasInPoint)
        InPoint = in->ReadU32();
    if (HasOutPoint)
        OutPoint = in->ReadU32();
    if (HasLoops)
        LoopCount = in->ReadU16();

    if (HasEnvelope)
    {
        int count = in->ReadU8();
        Envelopes.Resize(count);
        for (int i = 0; i < count; i++)
        {
            Envelopes[i].Mark44 = in->ReadU32();
            Envelopes[i].Level0 = in->ReadU16();
            Envelopes[i].Level1 = in->ReadU16();
        }
    }
    else
    {
        Envelopes.Resize(0);
    }

    in->LogParse("  HasEnvelope = %d\n", (int)HasEnvelope);
    in->LogParse("  HasLoops = %d\n", (int)HasLoops);
    in->LogParse("  HasOutPoint = %d\n", (int)HasOutPoint);
    in->LogParse("  HasInPoint = %d\n", (int)HasInPoint);
    in->LogParse("  InPoint = %d\n", (int)InPoint);
    in->LogParse("  OutPoint = %d\n", (int)OutPoint);
    in->LogParse("  LoopCount = %d\n", (int)LoopCount);
    in->LogParse("  envelope size = %d\n", (int)Envelopes.GetSize());
}

// @0x1426d42a0
void SoundStreamDefImpl::ReadHeadTag(Stream* in)
{
    in->ReadUInt(4); // reserved
    const int sampleRates[] = { 5512, 11025, 22050, 44100 };

    PlaybackSoundRate  = sampleRates[in->ReadUInt(2)];
    PlaybackSound16bit = in->ReadUInt1();
    PlaybackStereo     = in->ReadUInt1();
    SoundCompression   = in->ReadUInt(4);
    StreamSoundRate    = sampleRates[in->ReadUInt(2)];
    StreamSound16bit   = in->ReadUInt1();
    StreamStereo       = in->ReadUInt1();
    StreamSampleCount  = in->ReadU16();
    LatencySeek        = 0;
    if (SoundCompression == SwfSound_Mp3)
        LatencySeek = in->ReadU16();

    in->LogParse("  PlaybackSoundRate: %d\n  PlaybackSound16bit: %d\n  PlaybackStereo: %d\n  SoundCompression: %d\n",
                 PlaybackSoundRate, (int)PlaybackSound16bit, (int)PlaybackStereo, (int)SoundCompression);
    in->LogParse("  StreamSoundRate: %d\n  StreamSound16bit: %d\n  StreamStereo: %d\n  StreamSampleCount: %d\n"
                 "  LatencySeek: %d\n",
                 StreamSoundRate, (int)StreamSound16bit, (int)StreamStereo, (int)StreamSampleCount, (int)LatencySeek);
}

// @0x1426d3fe0
// MS2-FUNCTIONAL: same code, the stream and this pointers sit in swapped registers
void SoundStreamDefImpl::ReadBlockTag(LoadProcess* p)
{
    Stream*  in          = p->GetStream();
    unsigned datasize    = in->GetTagEndPosition() - in->Tell();
    UInt16   sampleCount = 0;
    p->LogParse("SoundStreamBlock: size=%d", datasize);
    if (datasize == 0)
        return;

    if (!pSoundInfo)
    {
        // The first block creates the sound; the later ones append to it.
        unsigned sf = (StreamSound16bit ? Sound::SoundDataBase::Sample_16 : Sound::SoundDataBase::Sample_8) |
                      (StreamStereo ? Sound::SoundDataBase::Sample_Stereo : 0);
        switch (SoundCompression)
        {
        case SwfSound_Raw:
        case SwfSound_Adpcm:
        case SwfSound_RawLE:
            sf |= Sound::SoundDataBase::Sample_PCM;
            break;
        case SwfSound_Mp3:
            sf |= Sound::SoundDataBase::Sample_MP3;
            break;
        }
        StartFrame = p->GetLoadingFrameForStreamSound();

        Ptr<Sound::AppendableSoundData> psound = *SF_NEW Sound::AppendableSoundData(sf, StreamSoundRate);
        psound->SetSeekSample(LatencySeek);
        pSoundInfo = *SF_NEW Sound::SoundInfo(psound);
    }
    LastFrame = p->GetLoadingFrameForStreamSound();

    unsigned codeBits = 2;
    if (SoundCompression == SwfSound_Mp3)
    {
        sampleCount = in->ReadU16();
        in->ReadU16(); // seek samples
        datasize -= 4;
    }
    else
    {
        if (SoundCompression == SwfSound_Adpcm)
            codeBits = in->ReadUInt(2);
        sampleCount = (UInt16)StreamSampleCount;
    }

    if (datasize > 0)
    {
        Sound::AppendableSoundData* psound = (Sound::AppendableSoundData*)pSoundInfo->GetSound();
        UByte*                      pdata  = 0;
        unsigned                    dsize  = datasize;
        if (SoundCompression != SwfSound_Adpcm)
        {
            pdata = psound->LockDataForAppend(sampleCount, dsize);
            s_ReadSoundData(in, dsize, pdata, StreamSound16bit, SoundCompression);
            psound->UnlockData();
        }
        else
        {
            // Decoded to 16-bit PCM.
            dsize = StreamStereo ? sampleCount * 4 : sampleCount * 2;
            pdata = psound->LockDataForAppend(sampleCount, dsize);
            GFx_AdpcmExpand(pdata, in, codeBits + 2, sampleCount, StreamStereo > 0);
            psound->UnlockData();
        }
    }
}

// @0x1426d39d0
bool SoundStreamDefImpl::ProcessSwfFrame(MovieImpl* proot, unsigned frame, Sprite* pchar)
{
    AudioBase*               paudio    = proot->pAudio;
    Sound::SoundRenderer*    prenderer = proot->pSoundRenderer;
    float                    frameTime = proot->FrameTime;
    Ptr<Sound::SoundChannel> pchan     = pchar->GetStreamingSound();

    if (pSoundInfo && paudio && prenderer)
    {
        if (frame >= StartFrame && frame < LastFrame)
        {
            if (!pchan || !pchan->IsPlaying())
            {
                pchan = *prenderer->PlaySample(pSoundInfo->GetSoundSample(prenderer), true);
                if (!pchan)
                    return false;
                pchan->SetPosition((frame - StartFrame) * frameTime);
                pchar->SetStreamingSound(pchan);
                pchan->Pause(false);
            }
            else if (paudio->GetSyncType() != AudioBase::NoSync && frame % paudio->GetCheckFrameInterval() == 0)
            {
                // Resynchronize when the sound and the frames drift apart.
                float soundTime = pchan->GetPosition();
                float frameTimePos = (frame - StartFrame) * frameTime;
                if (soundTime - frameTimePos > paudio->GetMaxTimeDifference())
                {
                    if (paudio->GetSyncType() == AudioBase::VideoMaster)
                    {
                        pchan->SetPosition(frameTimePos);
                    }
                    else if (!proot->ForceFrameCatchUp)
                    {
                        unsigned catchUp = (unsigned)((soundTime - frameTimePos) / frameTime);
                        if (catchUp)
                            proot->ForceFrameCatchUp = catchUp + 1;
                    }
                }
                else if (frameTimePos - soundTime > paudio->GetMaxTimeDifference())
                {
                    pchan->SetPosition(frameTimePos);
                }
            }
        }
        else if (pchan && pchan->IsPlaying())
        {
            pchar->SetStreamingSound(0);
        }
    }
    return true;
}

// ADPCM tables (IMA step sizes; the index change per code magnitude for each code size).
static int AdpcmIndexUpdate2[2]  = { -1, 2 };
static int AdpcmIndexUpdate3[4]  = { -1, -1, 2, 4 };
static int AdpcmIndexUpdate4[8]  = { -1, -1, -1, -1, 2, 4, 6, 8 };
static int AdpcmIndexUpdate5[16] = { -1, -1, -1, -1, -1, -1, -1, -1, 1, 2, 4, 6, 8, 10, 13, 16 };

static int* AdpcmIndexUpdate[4] = { AdpcmIndexUpdate2, AdpcmIndexUpdate3, AdpcmIndexUpdate4, AdpcmIndexUpdate5 };

enum { AdpcmStepCount = 89 };

static int AdpcmStepSize[AdpcmStepCount] = {
    7,     8,     9,     10,    11,    12,    13,    14,    16,    17,    19,    21,    23,    25,    28,
    31,    34,    37,    41,    45,    50,    55,    60,    66,    73,    80,    88,    97,    107,   118,
    130,   143,   157,   173,   190,   209,   230,   253,   279,   307,   337,   371,   408,   449,   494,
    544,   598,   658,   724,   796,   876,   963,   1060,  1166,  1282,  1411,  1552,  1707,  1878,  2066,
    2272,  2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,  5894,  6484,  7132,  7845,  8630,
    9493,  10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

// Decodes one code of Bits bits: the sign bit and a magnitude that scales the current step.
template<int Bits>
SF_FORCEINLINE void AdpcmDecode(int code, int& sample, int& stepIndex)
{
    const int signBit  = 1 << (Bits - 1);
    int       mag      = code & (signBit - 1);
    bool      negative = (code & signBit) ? 1 : 0;

    int delta = (AdpcmStepSize[stepIndex] * ((mag << 1) + 1)) >> (Bits - 1);
    if (negative)
        delta = -delta;

    sample += delta;
    sample = Alg::Max(-32768, Alg::Min(sample, 32767));

    stepIndex += AdpcmIndexUpdate[Bits - 2][mag];
    stepIndex = Alg::Max(0, Alg::Min(stepIndex, AdpcmStepCount - 1));
}

// A block starts with its first sample uncompressed.
template<int Bits>
SF_FORCEINLINE void AdpcmMonoBlock(SInt16** ppout, Stream* in, int& count, int& sample, int& stepIndex)
{
    count--;
    *(*ppout)++ = (SInt16)sample;
    while (count--)
    {
        AdpcmDecode<Bits>(in->ReadUInt(Bits), sample, stepIndex);
        *(*ppout)++ = (SInt16)sample;
    }
}

// Stereo codes alternate left and right.
template<int Bits>
SF_FORCEINLINE void AdpcmStereoBlock(SInt16** ppout, Stream* in, int& count, int& left, int& leftIndex, int& right,
                                     int& rightIndex)
{
    count--;
    *(*ppout)++ = (SInt16)left;
    *(*ppout)++ = (SInt16)right;
    while (count--)
    {
        AdpcmDecode<Bits>(in->ReadUInt(Bits), left, leftIndex);
        *(*ppout)++ = (SInt16)left;
        AdpcmDecode<Bits>(in->ReadUInt(Bits), right, rightIndex);
        *(*ppout)++ = (SInt16)right;
    }
}

// Decodes sampleCount samples (pairs in stereo) of 2..5 bit ADPCM to 16-bit PCM, in blocks of 4096.
// @0x1426d2a00
void GFx_AdpcmExpand(void* pdataOut, Stream* in, int codeBits, int sampleCount, bool stereo)
{
    SInt16* pout = (SInt16*)pdataOut;

    while (sampleCount)
    {
        int sample    = in->ReadSInt(16);
        int stepIndex = in->ReadUInt(6);

        int count = Alg::Min(sampleCount, 4096);
        sampleCount -= count;

        if (!stereo)
        {
            switch (codeBits)
            {
            case 2: AdpcmMonoBlock<2>(&pout, in, count, sample, stepIndex); break;
            case 3: AdpcmMonoBlock<3>(&pout, in, count, sample, stepIndex); break;
            case 4: AdpcmMonoBlock<4>(&pout, in, count, sample, stepIndex); break;
            case 5: AdpcmMonoBlock<5>(&pout, in, count, sample, stepIndex); break;
            }
        }
        else
        {
            int right      = in->ReadSInt(16);
            int rightIndex = in->ReadUInt(6);
            switch (codeBits)
            {
            case 2: AdpcmStereoBlock<2>(&pout, in, count, sample, stepIndex, right, rightIndex); break;
            case 3: AdpcmStereoBlock<3>(&pout, in, count, sample, stepIndex, right, rightIndex); break;
            case 4: AdpcmStereoBlock<4>(&pout, in, count, sample, stepIndex, right, rightIndex); break;
            case 5: AdpcmStereoBlock<5>(&pout, in, count, sample, stepIndex, right, rightIndex); break;
            }
        }
    }
}

}} // namespace Scaleform::GFx

namespace Scaleform {
// The envelope transforms SoundInfo::Play hands to the channel (exe 0x1426d4450).
template void ArrayDataBase<Sound::SoundChannel::Transform, AllocatorGH<Sound::SoundChannel::Transform, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);
} // namespace Scaleform

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937d0
// MS2-PIN: ??_7?$RefCountBaseNTS@VSoundStreamDef@GFx@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937d0
// MS2-PIN: ??_7SoundStreamDef@GFx@Scaleform@@6B@ 0x1431937d8
// MS2-PIN: ??_7SoundStreamDefImpl@GFx@Scaleform@@6B@ 0x1431937e8
// MS2-PIN: ??_7SoundInfo@Sound@Scaleform@@6B@ 0x14318ffa8
// MS2-PIN: ??_7?$RefCountBaseNTS@VSoundInfoBase@Sound@Scaleform@@$03@Scaleform@@6B@ 0x14318ff60
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$03@Scaleform@@6B@ 0x14318ff68
// MS2-PIN: ??_7SoundInfoBase@Sound@Scaleform@@6B@ 0x14318ff70
