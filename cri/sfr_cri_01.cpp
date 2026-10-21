// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Video_Video (0x14001c000-0x14001d7a0),
// then the CRI Movie 3.07.01 "easy player" layer (CriMvEasyPlayer, from 0x14001d7a0). Our own source, written from the
// exe; the leaked SDK copies were only used to name things.
// The CRI part was built by CRI with VS2008 SP1 (Utc1500 build 30729 in the Rich header) and can only be functional
// with our toolset; it shares the scaleform flag profile, which only matters for the Video part.
// MS2-UNIT: sfr_cri_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14001c000-0x14002a0e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/cri/cri_movie.h"

namespace Scaleform { namespace GFx {

// ---- loader pieces used by ReadDefineVideoStreamTag (the loader headers are not shared yet; only what is touched)

class Resource
{
public:
    void Release();
};

class ResourceId
{
public:
    UInt32 Id;
    ResourceId(UInt32 id) : Id(id) {}
};

class MovieDataDef
{
public:
    class LoadTaskData
    {
    public:
        void AddResource(ResourceId rid, Resource* pres);
    };
};

// SWF input stream: the inline reader helpers inspect the buffer directly.
class Stream
{
public:
    void Align() { UnusedBits = 0; }
    UInt16 ReadU16()
    {
        Align();
        if (DataSize - Pos < 2)
            PopulateBuffer(2);
        unsigned pos = Pos;
        UInt16 val = (UInt16)(pBuffer[pos] | (pBuffer[pos + 1] << 8));
        Pos = pos + 2;
        return val;
    }

private:
    bool PopulateBuffer(int size);

    UByte        Unrecovered0[0x29];
    UByte        UnusedBits;            // +0x29
    UByte        Unrecovered2a[0x4c - 0x2a];
    int          Pos;                   // +0x4c
    int          DataSize;              // +0x50
    UByte        Unrecovered54[0x60 - 0x54];
    const UByte* pBuffer;               // +0x60
};

template<class T>
class LogBase
{
public:
    void LogParse(const char* pfmt, ...);
};

class LoadProcess
{
public:
    enum LoadStateType { LS_LoadingFrames, LS_LoadFinished, LS_LoadCanceled, LS_LoadError };

    Stream* GetStream()  { return pAltStream ? pAltStream : &ProcessStream; }
    UInt16  ReadU16()    { return GetStream()->ReadU16(); }
    void    LogParse(const char* pfmt, UInt32 v) { Log.LogParse(pfmt, v); }
    void    AddResource(ResourceId rid, Resource* pres)
    {
        if (LoadState == LS_LoadingFrames)
            pLoadData->AddResource(rid, pres);
    }

private:
    UByte                       Unrecovered0[0x20];
    LogBase<LoadProcess>        Log;                // +0x20
    UByte                       Unrecovered21[0x38 - 0x21];
    MovieDataDef::LoadTaskData* pLoadData;          // +0x38 (Ptr<LoadTaskData>)
    UByte                       Unrecovered40[0x50 - 0x40];
    Stream                      ProcessStream;      // +0x50 (SWFProcessInfo::Stream)
    UByte                       Unrecovered[0x3b8 - 0x50 - sizeof(Stream)];
    LoadStateType               LoadState;          // +0x3b8
    UByte                       Unrecovered3bc[0x418 - 0x3bc];
    Stream*                     pAltStream;         // +0x418
};

struct TagInfo
{
    int      TagType;
    unsigned TagOffset;
    int      TagLength;
    unsigned TagDataOffset;
};

namespace Video {

// The video character definition is recovered with Video_VideoCharacter; here only its inline construction, which
// fills the Resource / CharacterDef / VideoCharacterDef image (0x30 bytes) and stores the two vtables.
extern "C" const void* const MS2_SF_Resource_vftable[];            // ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
extern "C" const void* const MS2_SF_VideoCharacterDef_vftable[];   // ??_7VideoCharacterDef@Video@GFx@Scaleform@@6B@ 0x14318b778

struct VideoCharacterDef
{
    const void* const* vfptr;
    volatile int       RefCount;    // Resource
    void*              pLib;
    UInt32             Id;          // CharacterDef: ResourceId::InvalidId
    UInt32             Width;
    UInt32             Height;
    UInt32             NumFrames;
    UByte              Smoothing;
    UByte              Deblocking;
    UByte              Codec;

    VideoCharacterDef()
    {
        vfptr     = MS2_SF_Resource_vftable;
        RefCount  = 1;
        pLib      = 0;
        Id        = 0x40000;
        vfptr     = MS2_SF_VideoCharacterDef_vftable;
        Width     = 0;
        Height    = 0;
        NumFrames = 0;
        Smoothing = 0;
        Deblocking = 0;
        Codec     = 2;
    }
    void* operator new(UPInt sz) { return Memory::Alloc(sz); }
    void  operator delete(void* p) { Memory::Free(p); }

    void Read(LoadProcess* p, int tagType);     // 0x14000f2d0 (Video_VideoCharacter)
    Resource* GetResource() { return (Resource*)this; }
};

// ---- other Video classes constructed here (implemented in Video_VideoPlayerImpl / the reader and decoder sources)

class VideoDecoderThrd : public VideoDecoder
{
public:
    VideoDecoderThrd(MemoryHeap* pheap, Thread::ThreadPriority priority);
    virtual void StartDecoding(VideoPlayer*);
    virtual void StopDecoding(VideoPlayer*);
    virtual bool IsDecodingStopped(VideoPlayer*);
    virtual bool ExecuteDecode(VideoPlayer*);
    virtual void GetReadBufferInfo(void* info);
    virtual bool IsIORequired() const;
    virtual void PauseDecoding(bool);
};

class VideoReaderConfigThrd : public VideoReaderConfig
{
public:
    VideoReaderConfigThrd(MemoryHeap* pheap, FileOpenerBase* pfileOpener);
    virtual VideoReader* CreateReader();
};

class VideoPlayerImpl : public VideoPlayer
{
public:
    VideoPlayerImpl(MemoryHeap* pheap);
    bool Init(Video* pvideo, TaskManager* ptaskManager, FileOpenerBase* pfileOpener, Log* plog);
};

// ==== Video ==========================================================================================================

// @0x14001cbb0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
Video::Video(const VideoVMSupport& vmSupport, Thread::ThreadPriority priority, bool autoInit)
    : DecodeThreadPriority(priority)
{
    pAS2VSupport = vmSupport.pAS2VSupport;
    pAS3VSupport = vmSupport.pAS3VSupport;
    // MemoryHeap::CreateHeap(name, flags, minAlign, granularity, reserve, threshold, limit, heapId, arena)
    struct { unsigned Flags; UPInt MinAlign, Granularity, Reserve, Threshold, Limit, HeapId, Arena; } desc =
        { 0, 64, 128 * 1024, 0, ~UPInt(0), 0, 8 /* HeapId_Video */, 0 };
    pHeap = *Memory::GetGlobalHeap()->CreateHeap("_Video_Heap", *(const HeapDesc*)&desc);
    if (autoInit)
        Initialize();
}

// @0x14001c000
Video::~Video()
{
    pSoundSystem  = NULL;
    pReaderConfig = NULL;
    pDecoder      = NULL;
    if (pAS2VSupport)
        SF_FREE(pAS2VSupport);
    if (pAS3VSupport)
        SF_FREE(pAS3VSupport);
    Finalize();
    pHeap = NULL;
}

void Video::Initialize()
{
    if (!Initialized++)
    {
        criHeap_Initialize();
        HandleWorkSize = CriMv::CalcMovieHandleWork(VIDEO_HANDLE_MAX);
        pHandleWorkBuf = SF_ALLOC(HandleWorkSize, Stat_Video_Mem);
        CriMv::SetupMovieHandleWork(VIDEO_HANDLE_MAX, pHandleWorkBuf, HandleWorkSize);
        CriMv::Initialize();
    }
}

void Video::Finalize()
{
    if (1 == Initialized--)
    {
        CriMv::Finalize();
        if (pHandleWorkBuf)
            SF_FREE(pHandleWorkBuf);
        criHeap_Finalize();
    }
}

// @0x14001c760
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void Video::ReadDefineVideoStreamTag(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt32 characterId = p->ReadU16();
    p->LogParse("  video = %d\n", characterId);
    VideoCharacterDef* ch = new VideoCharacterDef;
    ch->Read(p, tagInfo.TagType);
    p->AddResource(ResourceId(characterId), ch->GetResource());
    if (ch)
        ch->GetResource()->Release();
}

}} // namespace GFx::Video

// ==== Sound channel delegate =========================================================================================

namespace Sound {

#define SAMPL_BUFF_SIZE 4096

// Channel handed out before the real one exists; forwards everything once SetDelegate() gives it a target.
class SoundChannelDelegate : public SoundChannel
{
public:
    SoundChannelDelegate() : Volume(1.0f), Pan(0.0f), JustCreated(true) {}

    void SetDelegate(SoundChannel* pdel)
    {
        if (pDelegate)
            pDelegate->Stop();
        pDelegate   = pdel;
        JustCreated = false;
        if (pDelegate)
            pDelegate->SetVolume(Volume);
    }

    virtual SoundRenderer* GetSoundRenderer() const { return pDelegate ? pDelegate->GetSoundRenderer() : NULL; }
    virtual SoundSample*   GetSample() const        { return pDelegate ? pDelegate->GetSample() : NULL; }
    virtual void    Stop()                          { if (pDelegate) pDelegate->Stop(); }
    virtual void    Pause(bool pause)               { if (pDelegate) pDelegate->Pause(pause); }
    virtual bool    IsPlaying() const               { return pDelegate ? pDelegate->IsPlaying() : JustCreated; }
    virtual void    SetPosition(float seconds)      { if (pDelegate) pDelegate->SetPosition(seconds); }
    virtual float   GetPosition()                   { return pDelegate ? pDelegate->GetPosition() : 0.0f; }
    virtual void    Loop(int count, float start = 0, float end = 0)
                                                    { if (pDelegate) pDelegate->Loop(count, start, end); }
    virtual float   GetVolume()                     { return pDelegate ? pDelegate->GetVolume() : Volume; }
    virtual void    SetVolume(float volume)         { Volume = volume; if (pDelegate) pDelegate->SetVolume(volume); }
    virtual float   GetPan()                        { return pDelegate ? pDelegate->GetPan() : Pan; }
    virtual void    SetPan(float pan)               { Pan = pan; if (pDelegate) pDelegate->SetPan(pan); }
    virtual void    SetTransforms(const Array<Transform>& transforms)
                                                    { if (pDelegate) pDelegate->SetTransforms(transforms); }
    virtual void    SetSpatialInfo(const Array<Vector> spatinfo[])
                                                    { if (pDelegate) pDelegate->SetSpatialInfo(spatinfo); }

private:
    Ptr<SoundChannel> pDelegate;    // +0x10
    float             Volume;       // +0x18
    float             Pan;          // +0x1c
    bool              JustCreated;  // +0x20
};

} // namespace Sound

namespace GFx { namespace Video {

// ==== Video sound through the GFx sound renderer =====================================================================

class VideoSoundRendererStream : public VideoSound
{
public:
    VideoSoundRendererStream(MemoryHeap* pheap, Sound::SoundRenderer* psoundPlayer);
    virtual ~VideoSoundRendererStream() {}

    virtual bool                 CreateOutput(UInt32 channel, UInt32 samplerate);
    virtual void                 DestroyOutput();
    virtual PCMFormat            GetPCMFormat() const { return PCM_Float; }
    virtual void                 Start(PCMStream* pstream);
    virtual void                 Stop();
    virtual Status               GetStatus() const;
    virtual void                 Pause(bool sw);
    virtual void                 GetTime(UInt64* count, UInt64* unit) const;
    virtual Sound::SoundChannel* GetSoundChannel();
    virtual void                 SetSpatialInfo(const Array<Sound::SoundChannel::Vector>[]) {}

    // Feeds the renderer straight from the PCMStream given to Start().
    class Streamer : public Sound::SoundRenderer::AuxStreamer
    {
    public:
        Streamer(VideoSoundRendererStream* pparent) : pParent(pparent) {}
        virtual ~Streamer() {}
        virtual unsigned GetPCMData(UByte* pdata, unsigned datasize);

        unsigned GetData(UInt32 nch, float* pcmbuf[], UInt32 req_nsmpl)
        {
            return pParent->pPCMStream->GetDataFloat(nch, pcmbuf, req_nsmpl);
        }

        VideoSoundRendererStream* pParent;
    };
    friend class Streamer;

private:
    MemoryHeap*                      pHeap;             // +0x10
    Ptr<Streamer>                    pStreamer;         // +0x18
    Ptr<Sound::SoundRenderer>        pSoundPlayer;      // +0x20
    Ptr<Sound::SoundChannelDelegate> pChannel;          // +0x28
    PCMStream*                       pPCMStream;        // +0x30
    unsigned                         ChannelCount;      // +0x38
    UInt32                           SampleRate;        // +0x3c
    Status                           Stat;              // +0x40
    UInt64                           TotalGotSamples;   // +0x48
    float*                           SampleBuffers[MaxChannels]; // +0x50
};

// @0x14001cfa0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
VideoSoundRendererStream::VideoSoundRendererStream(MemoryHeap* pheap, Sound::SoundRenderer* psoundPlayer)
    : pHeap(pheap), pSoundPlayer(psoundPlayer),
      pPCMStream(0), ChannelCount(0), SampleRate(0), Stat(Sound_Stopped), TotalGotSamples(0)
{
    for (unsigned i = 0; i < MaxChannels; ++i)
        SampleBuffers[i] = NULL;
}

bool VideoSoundRendererStream::CreateOutput(UInt32 channels, UInt32 samplerate)
{
    if (channels == 0)
        return false;
    ChannelCount = channels;
    SampleRate   = samplerate;
    Stat         = Sound_Stopped;
    for (unsigned i = 0; i < ChannelCount; ++i)
    {
        SampleBuffers[i] = (float*)SF_HEAP_ALLOC(pHeap, sizeof(float) * SAMPL_BUFF_SIZE, Stat_Video_Mem);
        if (!SampleBuffers[i])
        {
            while (i > 0)
            {
                i--;
                SF_HEAP_FREE(pHeap, SampleBuffers[i]);
                SampleBuffers[i] = NULL;
            }
            return false;
        }
    }
    return true;
}

void VideoSoundRendererStream::DestroyOutput()
{
    for (unsigned i = 0; i < ChannelCount; ++i)
    {
        SF_HEAP_FREE(pHeap, SampleBuffers[i]);
        SampleBuffers[i] = NULL;
    }
    ChannelCount = 0;
}

// @0x14001d420
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoSoundRendererStream::Start(PCMStream* pstream)
{
    Stat            = Sound_Playing;
    TotalGotSamples = 0;
    pPCMStream      = pstream;

    if (!pStreamer)
        pStreamer = *SF_NEW Streamer(this);
    if (!pChannel)
        pChannel = *SF_HEAP_NEW(pHeap) Sound::SoundChannelDelegate;

    Ptr<Sound::SoundSample> psample;
    psample = *pSoundPlayer->CreateSampleFromAuxStreamer(pStreamer, ChannelCount, SampleRate,
                                                         Streamer::PCM_Float);
    Ptr<Sound::SoundChannel> pchan = *pSoundPlayer->PlaySample(psample, false);
    pChannel->SetDelegate(pchan);
}

// @0x14001c1e0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoSoundRendererStream::Stop()
{
    if (pChannel)
        pChannel->SetDelegate(NULL);
    pChannel        = NULL;
    Stat            = Sound_Stopped;
    TotalGotSamples = 0;
    pPCMStream      = 0;
}

// @0x14001c270
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoSoundRendererStream::Pause(bool sw)
{
    if (sw == true)
    {
        if (Stat == Sound_Playing)
        {
            Stat = Sound_Paused;
            if (pChannel)
                pChannel->Pause(true);
        }
    }
    else
    {
        if (Stat == Sound_Paused)
        {
            Stat = Sound_Playing;
            if (pChannel)
                pChannel->Pause(false);
        }
    }
}

VideoSound::Status VideoSoundRendererStream::GetStatus() const
{
    return Stat;
}

// @0x14001c2c0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoSoundRendererStream::GetTime(UInt64* count, UInt64* unit) const
{
    if (TotalGotSamples == 0)
    {
        *count = 0;
        *unit  = 1000;
    }
    else
    {
        if (pChannel)
        {
            float pos = pChannel->GetPosition();
            *count = (UInt64)(pos * 1000);
            *unit  = 1000;
        }
        else
        {
            *count = TotalGotSamples * 1000 / SampleRate;
            *unit  = 1000;
        }
    }
}

// @0x14001d130
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
Sound::SoundChannel* VideoSoundRendererStream::GetSoundChannel()
{
    if (!pChannel)
        pChannel = *SF_HEAP_NEW(pHeap) Sound::SoundChannelDelegate;
    return pChannel;
}

unsigned VideoSoundRendererStream::Streamer::GetPCMData(UByte* pdata, unsigned datasize)
{
    UInt32   recv_nsmpl = 0;
    unsigned ssize      = 32;
    UInt32   nsmpl      = datasize * 8 / ssize / pParent->ChannelCount;
    float*   buffer     = (float*)pdata;

    if (pParent->pPCMStream)
    {
        if (pParent->ChannelCount == 1)
        {
            recv_nsmpl = GetData(1, &buffer, nsmpl);
        }
        else
        {
            while (nsmpl > 0)
            {
                UInt32 gsmpl = GetData(pParent->ChannelCount, pParent->SampleBuffers,
                                       nsmpl > SAMPL_BUFF_SIZE ? SAMPL_BUFF_SIZE : nsmpl);
                if (gsmpl == 0)
                    break;
                for (unsigned count = 0; count < gsmpl; count++)
                    for (unsigned i = 0; i < pParent->ChannelCount; ++i)
                        *buffer++ = pParent->SampleBuffers[i][count];
                nsmpl      -= gsmpl;
                recv_nsmpl += gsmpl;
            }
        }
    }
    pParent->TotalGotSamples += recv_nsmpl;
    return recv_nsmpl * ssize * pParent->ChannelCount / 8;
}

// Sound system that plays video audio through a Sound::SoundRenderer.
class VideoSoundSystem_SoundRenderer : public VideoSoundSystem
{
public:
    VideoSoundSystem_SoundRenderer(Sound::SoundRenderer* psoundPlayer, MemoryHeap* pheap)
        : VideoSoundSystem(pheap), pSoundPlayer(psoundPlayer) {}
    virtual ~VideoSoundSystem_SoundRenderer() {}

    virtual VideoSound* Create()
    {
        return SF_HEAP_NEW(GetHeap()) VideoSoundRendererStream(GetHeap(), pSoundPlayer);
    }

protected:
    Ptr<Sound::SoundRenderer> pSoundPlayer;     // +0x18
};

// @0x14001c9a0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void Video::SetSoundSystem(Sound::SoundRenderer* psoundRenderer)
{
    if (!psoundRenderer)
        return;
    UInt32 cap_bits = 0;
    psoundRenderer->GetRenderCaps(&cap_bits);
    if (cap_bits & Sound::SoundRenderer::Cap_NoVideoSound)
        return;
    Ptr<VideoSoundSystem> psc = *SF_NEW VideoSoundSystem_SoundRenderer(psoundRenderer, pHeap);
    SetSoundSystem(psc);
}

// ==== Readers ========================================================================================================

// @0x14001d720
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoReaderConfig::DetachReader(VideoReader* preader)
{
    for (size_t i = 0; i < Readers.GetSize(); ++i)
    {
        if (Readers[i] == preader)
        {
            Readers.RemoveAt(i);
            break;
        }
    }
}

// @0x14001d650
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void VideoReaderConfig::AttachReader(VideoReader* preader)
{
    Readers.PushBack(preader);
}

// ==== Player creation, I/O ===========================================================================================

// @0x14001c370
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
VideoPlayer* Video::CreateVideoPlayer(MemoryHeap* pheap, TaskManager* ptaskManager,
                                      FileOpenerBase* pfileOpener, Log* plog)
{
    SF_UNUSED(pheap);
    if (!pDecoder)
    {
        pDecoder = *SF_HEAP_NEW(pHeap) VideoDecoderThrd(pHeap, DecodeThreadPriority);
        ApplySystemSettings(pDecoder);
    }
    if (!pReaderConfig)
    {
        pReaderConfig = *SF_HEAP_NEW(pHeap) VideoReaderConfigThrd(pHeap, pfileOpener);
        ApplySystemSettings(pReaderConfig);
        pReaderConfig->SetReadCallback(pReadCallback);
    }

    VideoPlayerImpl* pplayer = SF_HEAP_NEW(pHeap) VideoPlayerImpl(pHeap);
    if (pplayer->Init(this, ptaskManager, pfileOpener, plog))
        ApplySystemSettings(pplayer);
    else
    {
        pplayer->Destroy();
        pplayer = NULL;
    }
    return pplayer;
}

// @0x14001c4c0
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void Video::SetReadCallback(ReadCallback* pcallback)
{
    pReadCallback = pcallback;
    if (pReaderConfig)
        pReaderConfig->SetReadCallback(pReadCallback);
}

bool Video::IsIORequired() const
{
    if (!pDecoder)
        return false;
    return pDecoder->IsIORequired();
}

// @0x14001c530
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls, other scheduling
void Video::EnableIO(bool enable)
{
    if (pReaderConfig)
        pReaderConfig->EnableIO(enable);
}

}}} // namespace Scaleform::GFx::Video

// MS2-PIN: ??_7Video@0GFx@Scaleform@@6B@ 0x1431b8050
// MS2-PIN: ??_7AuxStreamer@SoundRenderer@Sound@Scaleform@@6B@ 0x1431b80b8
// MS2-PIN: ??_7VideoSoundSystem_SoundRenderer@Video@GFx@Scaleform@@6B@ 0x1431b80e0
// MS2-PIN: ??_7VideoBase@Video@GFx@Scaleform@@6B@ 0x1431b8100
// MS2-PIN: ??_7SoundChannelDelegate@Sound@Scaleform@@6B@ 0x1431b8160
// MS2-PIN: ??_7VideoSoundRendererStream@Video@GFx@Scaleform@@6B@ 0x1431b81e0
// MS2-PIN: ??_7Streamer@VideoSoundRendererStream@Video@GFx@Scaleform@@6B@ 0x1431b8238
// MS2-PIN: ??_7VideoSound@Video@GFx@Scaleform@@6B@ 0x1431b4b80
