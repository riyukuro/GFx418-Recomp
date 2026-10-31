// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Video: Video_Video
// (0x14001c000-0x14001d7a0), the AS3 VideoProviderNetStream (0x140025090-0x140026db0) and the video player over the CRI
// easy player (0x140028360-0x14002a0e0). Our own source, written from the exe; the leaked SDK copies were only used to
// name things. This part of the Video add-on lib is VS2008 SP1 code, so the unit builds with cl 15.00.30729 and the
// vc11 options (MS2-TOOLSET: vc9v, cmake/ms2-unit-profiles.cmake). Keep it C++03: no auto, nullptr, range-for,
// __declspec(safebuffers), alias `using`, explicit conversion operators or variadic templates, and no hook/ms2hook.h
// (its hook registrations are in ../video/sfr_video_hooks.cpp). clang-cl compiles it as before. The CRI
// Movie runs between them (CriMvEasyPlayer, CriMv, CRI Heap; VS2008 SP1) are sfr_cri_01c.
// MS2-UNIT: sfr_cri_01
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14001c000-0x14001d7a0 .text$mn
// MS2-RANGE: 0x140025090-0x140026db0 .text$mn
// MS2-RANGE: 0x140028360-0x14002a0e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/video/video_as3providernetstream.h"
#include "../include/cri/cri_movie.h"
#include "../include/video/video_videoplayerimpl.h"

void FUN_14257db50(void* object);
void FUN_14257db40(void* object);
void FUN_14257dc30(void* object);
void FUN_14257dcb0(void* object);
void FUN_14257dcd0(void* object);
void* FUN_14257dc50(void* object);
void FUN_142584ce0(void* object);
void FUN_142585580(void* object, const void* source);
extern const void* const DAT_1431b8fc8[];
extern const void* const DAT_1431b8fa0[];
extern const void* const DAT_1431b8e08[];
extern const void* const DAT_1431b9028[];
extern const void* const DAT_1431b8fd0[];
extern const void* const DAT_1431b8db0[];
extern const void* const DAT_1431b8f18[];
extern const void* const DAT_1431b8f30[];
extern "C" const void* const DAT_1431b8e30[];
void FUN_14256c520(Scaleform::GFx::MovieImpl* movie, Scaleform::GFx::Video::VideoProvider* provider);
// LoadStates / URLBuilder / MovieImpl entry points OpenUrl uses (their headers are not shared with this unit).
void* FUN_142636ed0(void* self, void* loader, void* states, void* bindStates);   // LoadStates::LoadStates
void  FUN_142638170(const void* self, Scaleform::String* ppath, const void* loc); // LoadStates::BuildURL
bool  FUN_14256f730(const void* movie, Scaleform::String* ppath);                // MovieImpl::GetMainMoviePath
void** FUN_1425b38b0(const void* stateBag, void** ret);                          // StateBag::GetLog (Ptr<Log> by value)

CriMvSoundInterface::~CriMvSoundInterface() {}
CriMvSystemTimerInterface::~CriMvSystemTimerInterface() {}

// The exe's copies are the scalar deleting destructors of the two interfaces (CRI's VS2008 build: no sized-delete
// flag-4 path). Neither has a constructor here, so their ??_G is never emitted; both are written out.
// ??_GCriMvSoundInterface written out (own vftable store, then the CRT operator delete)
// @0x1400283a0
void* DeleteCriMvSoundInterface(CriMvSoundInterface* p, unsigned flags)
{
    *reinterpret_cast<const void* const**>(p) = DAT_1431b8db0;
    if (flags & 1)
        ::operator delete(p);
    return p;
}

// ??_GCriMvSystemTimerInterface written out (own vftable store, then the CRT operator delete)
// @0x1400283e0
void* DeleteCriMvSystemTimerInterface(CriMvSystemTimerInterface* p, unsigned flags)
{
    *reinterpret_cast<const void* const**>(p) = DAT_1431b8e08;
    if (flags & 1)
        ::operator delete(p);
    return p;
}

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
    UInt32             pad1C;       // CharacterDef is 8-aligned: Width starts at +0x20
    UInt32             Width;
    UInt32             Height;
    UInt32             NumFrames;
    UByte              Smoothing;
    UByte              Deblocking;
    UByte              Codec;

    // the inline construction (a member, not a ctor: sfr_gfx_04 defines the real VideoCharacterDef ctor)
    void Init()
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

// (VideoDecoderThrd and VideoReaderConfigThrd are declared in video_videoplayerimpl.h.)

// ==== Video ==========================================================================================================

__forceinline void Video::Initialize()
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

// @0x14001cbb0
// MS2-FUNCTIONAL: no tail calls, other scheduling
Video::Video(const VideoVMSupport& vmSupport, Thread::ThreadPriority priority, bool autoInit)
    : DecodeThreadPriority(priority)
{
    pAS2VSupport = vmSupport.pAS2VSupport;
    pAS3VSupport = vmSupport.pAS3VSupport;
    // MemoryHeap::CreateHeap(name, flags, minAlign, granularity, reserve, threshold, limit, heapId, arena)
    struct VideoHeapDesc
    {
        unsigned Flags;
        UPInt    MinAlign, Granularity, Reserve, Threshold, Limit, HeapId, Arena;
        VideoHeapDesc(unsigned flags, UPInt minAlign, UPInt granularity, UPInt reserve, UPInt threshold, UPInt limit,
                      UPInt heapId, UPInt arena)
            : Flags(flags), MinAlign(minAlign), Granularity(granularity), Reserve(reserve), Threshold(threshold),
              Limit(limit), HeapId(heapId), Arena(arena)
        {
        }
    } desc(0, 64, 128 * 1024, 0, ~UPInt(0), 0, 8 /* HeapId_Video */, 0);
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
void Video::ReadDefineVideoStreamTag(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt32 characterId = p->ReadU16();
    p->LogParse("  video = %d\n", characterId);
    VideoCharacterDef* ch = new VideoCharacterDef;
    if (ch)
        ch->Init();
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
    // initialize the Scaleform base and retain the selected sound renderer.
    // @0x14001c890
    VideoSoundSystem_SoundRenderer(Sound::SoundRenderer* psoundPlayer, MemoryHeap* pheap)
        : VideoSoundSystem(pheap), pSoundPlayer(psoundPlayer) {}
    // release the retained renderer while unwinding through VideoSoundSystem.
    // @0x14001c900
    virtual ~VideoSoundSystem_SoundRenderer() {}

    virtual VideoSound* Create()
    {
        return SF_HEAP_NEW(GetHeap()) VideoSoundRendererStream(GetHeap(), pSoundPlayer);
    }

protected:
    Ptr<Sound::SoundRenderer> pSoundPlayer;     // +0x18
};

// @0x14001c9a0
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
void VideoReaderConfig::AttachReader(VideoReader* preader)
{
    Readers.PushBack(preader);
}

// ==== Player creation, I/O ===========================================================================================

// @0x14001c370
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
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
// MS2-FUNCTIONAL: no tail calls, other scheduling
void Video::EnableIO(bool enable)
{
    if (pReaderConfig)
        pReaderConfig->EnableIO(enable);
}

}}} // namespace Scaleform::GFx::Video

// ==== AS3 VideoProviderNetStream =====================================================================================

namespace Scaleform { namespace GFx {

// ---- display-list pieces touched by the audio target code (the display headers are not shared yet)

class DisplayObject;
class Sprite;

class CharacterHandle : public NewOverrideBase<Stat_Default_Mem>
{
public:
    ~CharacterHandle();
    void AddRef()  { ++RefCount; }
    void Release()
    {
        if (--RefCount <= 0)
            delete this;
    }
    DisplayObject* GetCharacter() const { return pCharacter; }

private:
    int            RefCount;     // +0x00
    DisplayObject* pCharacter;   // +0x08
};

class DisplayObject
{
public:
    bool             IsSprite() const          { return ((Flags >> 10) & 1) != 0; }
    Sprite*          CharToSprite_Unsafe()     { return (Sprite*)this; }
    DisplayObject*   GetParent() const         { return pParent; }
    CharacterHandle* GetCharacterHandle() const
    {
        CharacterHandle* ph = pNameHandle;
        if (!ph)
            ph = CreateCharacterHandle();
        return ph;
    }

protected:
    CharacterHandle* CreateCharacterHandle() const;

private:
    UByte            Pad0[0x38];
    DisplayObject*   pParent;       // +0x38
    UByte            Pad1[0x6a - 0x40];
    UInt16           Flags;         // +0x6a (bit 10: is a sprite)
    UByte            Pad2[0x70 - 0x6c];
    CharacterHandle* pNameHandle;   // +0x70
};

class ASSoundIntf;
class SoundResource;

class Sprite : public DisplayObject
{
public:
    struct ActiveSoundItem : public RefCountBaseNTS<ActiveSoundItem, Stat_Default_Mem>
    {
        Sound::SoundChannel* pChannel;   // +0x10 (Ptr<> in the real layout; only read here)
    };

    float            GetRealSoundVolume();
    float            GetRealSubSoundVolume();
    void             SetSoundVolume(int volume, int subVolume);
    void             AddActiveSound(Sound::SoundChannel* pchan, ASSoundIntf* psobj, SoundResource* pres);
    ActiveSoundItem* ReleaseActiveSound(Sound::SoundChannel* pchan);
    void             AttachActiveSound(ActiveSoundItem* item);
};

namespace Video {

// Only the provider back-pointer is touched here (+0x40); the image classes come with the render units.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte          Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;   // +0x40
};

} // namespace Video

namespace AS3 {

using namespace Video;

// The SWF clock adapter holds a weak reference to its target sprite after the SyncObject base: +0x10 is the target's
// WeakPtrProxy (CreateWeakProxy, 0x14257dc50), released with the proxy's own count, not RefCountNTSImpl::Release.
class SwfVideoSyncObject : public VideoPlayer::SyncObject
{
public:
    explicit SwfVideoSyncObject(Sprite* target);
    virtual ~SwfVideoSyncObject();
    // This unit's exe copies of SyncObject's inline slots (0x140025ca0..0x140025cd0) are separate functions from sfr_video_01's,
    // so they are written out here rather than reusing the shared SyncObject:: symbols.
    virtual void SetStartFrame(unsigned frame) { StartFrame = frame; } // @0x140025ca0
    virtual void Start() {}                                                                                                             // @0x140025cb0
    virtual void Stop() {}                                                                                                              // @0x140025cc0
    virtual void Pause(bool sw) { (void)sw; }                                                                                           // @0x140025cd0
    virtual void GetTime(UInt64* count, UInt64* unit);

    WeakPtr<RefCountWeakSupportImpl> pTarget; // +0x10
    UInt32 StartFrame;                        // +0x18
    float  FrameDuration;                     // +0x1c
};

// adapts the SWF target's frame clock: the start frame and the movie's frame duration (+0x274).
// The exe calls the target's vfunc without a null check (only the weak-proxy fetch is guarded); the one caller
// (SetSwfSync, 0x140025ec0) passes the movie's live sprite.
// @0x140025c30
SwfVideoSyncObject::SwfVideoSyncObject(Sprite* target)
    : VideoPlayer::SyncObject(), pTarget(reinterpret_cast<RefCountWeakSupportImpl*>(target))
{
    void** vtable = *reinterpret_cast<void***>(target);
    StartFrame = reinterpret_cast<UInt32 (__fastcall*)(Sprite*)>(vtable[0x328 / sizeof(void*)])(target);
    UByte* timeline = reinterpret_cast<UByte**>(target)[4];
    UByte* def = *reinterpret_cast<UByte**>(timeline + 0x10);
    FrameDuration = *reinterpret_cast<float*>(def + 0x274);
}

// The novtable SyncObject base skips the exe's store of 0x1431b4f78 here and in FUN_140025e50: a dead store, since
// ~RefCountNTSImplCore (0x14257db50) overwrites it straight away.
// MS2-FUNCTIONAL: releases the target's weak proxy (pTarget's dtor) before the common SyncObject base teardown.
// @0x140025ce0
SwfVideoSyncObject::~SwfVideoSyncObject()
{
}

// BEHAVIOUR FIX (latent): the destructor runs non-virtually (inlined in the exe). The virtual self->~SwfVideoSyncObject()
// would recurse through exe vftable 0x1431b8a60 slot 0 (this function); the fullexe's own vftable avoids that.
// @0x140025e50
SwfVideoSyncObject* FUN_140025e50(SwfVideoSyncObject* self, UInt32 flags)
{
    self->SwfVideoSyncObject::~SwfVideoSyncObject();
    if (flags & 1)
        Memory::Free(self);
    return self;
}

// @0x140025d30
void SwfVideoSyncObject::GetTime(UInt64* count, UInt64* unit)
{
    // The proxy is dropped once the sprite has died; a sprite at zero refs reads as gone.
    Ptr<RefCountWeakSupportImpl> target = pTarget;
    if (target)
    {
        void** vtable = *reinterpret_cast<void***>(target.GetPtr());
        UInt32 current = reinterpret_cast<UInt32 (__fastcall*)(void*)>(vtable[0x328 / sizeof(void*)])(target.GetPtr());
        if (current > StartFrame)
        {
            *unit = 1000000;
            *count = (UInt64)((float)(current - StartFrame) * FrameDuration * (float)*unit);
            return;
        }
    }
    *count = 0;
    *unit = 1000;
}

// The sprite whose sound settings a provider's audio follows: the audio target itself, or its parent when the target
// is not a sprite.
static inline Sprite* GetAudioTargetSprite(CharacterHandle* ph)
{
    DisplayObject* pch = ph->GetCharacter();
    if (!pch)
        return NULL;
    if (pch->IsSprite())
        return pch->CharToSprite_Unsafe();
    DisplayObject* pparent = pch->GetParent();
    if (pparent && pparent->IsSprite())
        return pparent->CharToSprite_Unsafe();
    return NULL;
}

// @0x140025090
// MS2-FUNCTIONAL: other scheduling
const char* NetStreamInterface::NotificationToString(Notification code)
{
    switch (code)
    {
    case PlayStart:          return "NetStream.Play.Start";
    case PlayStop:           return "NetStream.Play.Stop";
    case SeekNotify:         return "NetStream.Seek.Notify";
    case PlayStreamNotFound: return "NetStream.Play.StreamNotFound";
    case SeekInvalidTime:    return "NetStream.Seek.InvalidTime";
    case PlayInternalError:  return "NetStream.Play.InternalError";
    default:                 return "NetStream.Unknown";
    }
}

// @0x140025100
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::Init()
{
    pVideoPlayer = NULL;
    memset(&VInfo, 0, sizeof(VInfo));
    FrameTime                = 1.0f / 12;
    pSubtitleTmp             = NULL;
    pSubtitle                = NULL;
    pTextureManager          = NULL;
    LoopFlag                 = false;
    PoolsNumber              = 2;
    BufferTime               = 0.0f;
    ReloadThreshHoldTime     = 0.8f;
    OpenURLTimeout           = 5.0f;
    SeekPos                  = 0.0f;
    FrameIsReady             = false;
    StartNotificationSent    = false;
    StopNotificationSent     = false;
    SeekNotificationSent     = true;
    NotFoundNotificationSent = false;
}

// @0x1400251a0
void VideoProviderNetStream::Pause(bool pause)
{
    if (pVideoPlayer)
        pVideoPlayer->Pause(pause);
}

// @0x1400251c0
// MS2-FUNCTIONAL: other scheduling
bool VideoProviderNetStream::IsActive()
{
    if (!pVideoPlayer)
        return false;
    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    return status == VideoPlayer::Opening || status == VideoPlayer::Ready || status == VideoPlayer::Starting ||
           status == VideoPlayer::Playing || status == VideoPlayer::Seeking || status == VideoPlayer::Stopping;
}

// @0x140025210
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::AllocSubtitleBuffers()
{
    if (!pSubtitle)
    {
        pSubtitle = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
        memset(pSubtitle, 0, VInfo.MaxSubtitleLen);
    }
    if (!pSubtitleTmp)
    {
        pSubtitleTmp = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
        memset(pSubtitleTmp, 0, VInfo.MaxSubtitleLen);
    }
}

// @0x1400252a0
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::ReleaseSubtitleBuffers()
{
    if (pSubtitleTmp)
    {
        SF_FREE(pSubtitleTmp);
        pSubtitleTmp = NULL;
    }
    if (pSubtitle)
    {
        SF_FREE(pSubtitle);
        pSubtitle = NULL;
    }
}

// @0x140025300
void VideoProviderNetStream::Stop()
{
    if (pVideoPlayer)
        pVideoPlayer->Stop();
}

// @0x140025360
// MS2-FUNCTIONAL: member reloaded after the test
UInt32 VideoProviderNetStream::GetPosition()
{
    if (!pVideoPlayer)
        return 0;
    return pVideoPlayer->GetPosition();
}

// @0x140025380
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetLoopFlag(bool flag)
{
    LoopFlag = flag;
    if (pVideoPlayer)
        pVideoPlayer->SetLoopFlag(flag);
}

// @0x140025ec0
void VideoProviderNetStream::SetSwfSync(bool flag, Sprite* ptarget)
{
    if (flag)
        pSyncObj = *SF_NEW SwfVideoSyncObject(ptarget);
    else
        pSyncObj = NULL;
    if (pVideoPlayer)
        pVideoPlayer->SetSyncObject(pSyncObj);
}

// URLBuilder::LocationInfo (0x18 bytes).
struct OpenUrlLocationInfo
{
    int    Use;          // +0x00 URLBuilder::FileUse
    String FileName;     // +0x08
    String ParentPath;   // +0x10
};

// MS2-FUNCTIONAL: other scheduling. The AS3 and movie
// objects are read through their exe offsets (the AS3 VM and MovieImpl headers are not shared with this unit), and the
// movie heap is read directly where the exe calls the virtual MovieImpl::GetHeap.
// @0x140026720
void VideoProviderNetStream::OpenUrl(const char* url, ASVM& asvm)
{
    UByte* movieRoot = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(&asvm) + 0x2d8);   // AS3::MovieRoot
    UByte* proot     = *reinterpret_cast<UByte**>(movieRoot + 0x10);                         // MovieImpl
    void*  stateBag  = proot + 0x10;                                                         // MovieImpl's StateBag base

    // Ptr<LoadStates> pls = *SF_NEW LoadStates(proot->GetLoaderImpl(), proot->pStateBag);
    void* loaderImpl = *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(proot + 0x48) + 0x28);
    UByte* stateBagImpl = *reinterpret_cast<UByte**>(proot + 0x80);
    void* pls = SF_ALLOC(0xa0, Stat_Default_Mem);
    if (pls)
        pls = FUN_142636ed0(pls, loaderImpl, stateBagImpl ? stateBagImpl + 0x10 : NULL, NULL);

    String level0Path;
    FUN_14256f730(proot, &level0Path);
    OpenUrlLocationInfo loc = { 0, String(url), level0Path };   // URLBuilder::File_Regular
    String fileName;
    FUN_142638170(pls, &fileName, &loc);

    // The main timeline's handle, when it is a sprite.
    DisplayObject* pobj = *reinterpret_cast<DisplayObject**>(*reinterpret_cast<UByte**>(movieRoot + 0x158) + 0x110);
    CharacterHandle* ptarget = NULL;
    if (pobj && pobj->IsSprite())
        ptarget = pobj->GetCharacterHandle();

    FrameTime = 1.0f / 12.0f;
    SeekPos   = 0.0f;
    VInfo.CuePoints.Clear();
    VInfo.AudioTracks.Clear();
    pTextureImage = NULL;
    FrameIsReady  = false;
    if (!pVideoPlayer)
    {
        typedef void* (__fastcall *GetStateFn)(void*, int);
        GetStateFn getState = reinterpret_cast<GetStateFn>((*reinterpret_cast<void***>(stateBag))[0x18 / sizeof(void*)]);
        void* video = getState(stateBag, 30);                         // State_Video
        if (video)
        {
            void** videoVtable = *reinterpret_cast<void***>(video);
            typedef Render::TextureManager* (__fastcall *GetTexMgrFn)(void*);
            pTextureManager = reinterpret_cast<GetTexMgrFn>(videoVtable[0x40 / sizeof(void*)])(video);
            if (!pTextureManager)
            {
                void* imageCreator = getState(stateBag, 11);          // State_ImageCreator
                pTextureManager = *reinterpret_cast<Render::TextureManager**>(reinterpret_cast<UByte*>(imageCreator) + 0x18);
                FUN_14257dcb0(imageCreator);
            }
            void* log = NULL;
            log = *FUN_1425b38b0(stateBag, &log);                     // StateBag::GetLog, Ptr<Log> by value
            void* fileOpener  = getState(stateBag, 9);                // State_FileOpener
            void* taskManager = getState(stateBag, 20);               // State_TaskManager
            void* heap = *reinterpret_cast<void**>(proot + 0x40);
            typedef VideoPlayer* (__fastcall *CreatePlayerFn)(void*, void*, void*, void*, void*);
            pVideoPlayer = reinterpret_cast<CreatePlayerFn>(videoVtable[0x18 / sizeof(void*)])(video, heap, taskManager,
                                                                                                fileOpener, log);
            if (taskManager)
                FUN_14257dcb0(taskManager);
            if (fileOpener)
                FUN_14257dcb0(fileOpener);
            if (log)
                FUN_14257dcb0(log);
        }
        if (pVideoPlayer)
        {
            pVideoPlayer->SetSyncObject(pSyncObj.GetPtr());
            pVideoPlayer->SetBufferTime(BufferTime);
            pVideoPlayer->SetNumberOfFramePools(PoolsNumber);
            pVideoPlayer->SetReloadThresholdTime(ReloadThreshHoldTime);
            pVideoPlayer->SetDecodeHeaderTimeout(OpenURLTimeout);
        }
        if (video)
            FUN_14257dcb0(video);
    }
    if (pVideoPlayer)
    {
        pVideoPlayer->Open(fileName.ToCStr());
        pTarget = ptarget;
        ::FUN_14256c520(reinterpret_cast<MovieImpl*>(proot), this);
        pVideoPlayer->SetLoopFlag(LoopFlag);
        ReleaseSubtitleBuffers();
        StartNotificationSent    = false;
        NotFoundNotificationSent = false;
        SeekNotificationSent     = true;
        if (!pAudioTarget)
        {
            // pAudioTarget = proot->GetRootMovie()->GetCharacterHandle(): ASMovieRootBase vtable slot 14 (+0x70).
            void* asMovieRoot = *reinterpret_cast<void**>(proot + 0x18);
            typedef DisplayObject* (__fastcall *GetRootMovieFn)(void*, void*);
            DisplayObject* proot0 = reinterpret_cast<GetRootMovieFn>((*reinterpret_cast<void***>(asMovieRoot))[0x70 / sizeof(void*)])(asMovieRoot, NULL);
            pAudioTarget = proot0->GetCharacterHandle();
        }
    }
    if (pls)
        FUN_14257dcb0(pls);
}

// @0x1400253b0
void VideoProviderNetStream::SetAudioTrack(int track)
{
    if (pVideoPlayer)
        pVideoPlayer->SetAudioTrack(track);
}

// @0x1400253d0
void VideoProviderNetStream::SetSubAudioTrack(int track)
{
    if (pVideoPlayer)
        pVideoPlayer->SetSubAudioTrack(track);
}

// @0x1400253f0
void VideoProviderNetStream::ReplaceCenterVoice(int track)
{
    if (pVideoPlayer)
        pVideoPlayer->ReplaceCenterVoice(track);
}

// @0x140025410
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetSubtitleChannel(int channel)
{
    if (pVideoPlayer)
        pVideoPlayer->SetSubtitleChannel(channel);
}

// @0x140025430
// MS2-FUNCTIONAL: member reloaded after the test
int VideoProviderNetStream::GetSubtitleChannel()
{
    if (!pVideoPlayer)
        return -1;
    return pVideoPlayer->GetSubtitleChannel();
}

// @0x140025450
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetBufferTime(float time)
{
    BufferTime = time;
    if (pVideoPlayer)
        pVideoPlayer->SetBufferTime(time);
}

// @0x140025480
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetNumberOfFramePools(unsigned pools)
{
    PoolsNumber = pools;
    if (pVideoPlayer)
        pVideoPlayer->SetNumberOfFramePools(pools);
}

// @0x1400254b0
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetReloadThresholdTime(float time)
{
    ReloadThreshHoldTime = time;
    if (pVideoPlayer)
        pVideoPlayer->SetReloadThresholdTime(time);
}

// @0x1400254e0
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SetOpenURLTimeout(float timeout)
{
    OpenURLTimeout = timeout;
    if (pVideoPlayer)
        pVideoPlayer->SetDecodeHeaderTimeout(timeout);
}

// @0x140025510
// MS2-FUNCTIONAL: no tail calls
void VideoProviderNetStream::SendMetaData()
{
    if (pNetStreamInterface)
        pNetStreamInterface->ExecuteOnMataData(&VInfo);
}

// @0x140025580
// MS2-FUNCTIONAL: member reloaded after the test
VideoImage* VideoProviderNetStream::GetTexture(int* width, int* height)
{
    if (!pVideoPlayer || !pTextureImage)
        return NULL;
    *width  = VInfo.Width;
    *height = VInfo.Height;
    return pTextureImage;
}

// @0x1400255b0
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::Close()
{
    if (pTextureImage)
        pTextureImage->pVideoProvider = NULL;
    pTextureImage = NULL;
    if (pVideoPlayer)
        pVideoPlayer->Destroy();
    pVideoPlayer = NULL;
    ReleaseSubtitleBuffers();
}

// @0x140025650
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::InitSoundChannel()
{
    if (pAudioTarget)
    {
        Sprite* psprite = GetAudioTargetSprite(pAudioTarget);
        Sound::SoundChannel* pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (psprite && pchan)
        {
            pchan->SetVolume(psprite->GetRealSoundVolume());
            psprite->AddActiveSound(pchan, NULL, NULL);
        }
        pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::SubAudio);
        if (psprite && pchan)
        {
            pchan->SetVolume(psprite->GetRealSubSoundVolume());
            psprite->AddActiveSound(pchan, NULL, NULL);
        }
    }
}

// @0x140025750
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::SetSoundVolume(int volume, int subVolume)
{
    if (!pAudioTarget)
        return;
    Sprite* psprite = GetAudioTargetSprite(pAudioTarget);
    if (psprite && pVideoPlayer)
    {
        psprite->SetSoundVolume(volume, subVolume);
        Sound::SoundChannel* pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (pchan)
            pchan->SetVolume(psprite->GetRealSoundVolume());
        pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::SubAudio);
        if (pchan)
            pchan->SetVolume(psprite->GetRealSubSoundVolume());
    }
}

}}} // namespace Scaleform::GFx::AS3

// MovieImpl member that registers a provider for advancing (unnamed in the exe's symbols).
void FUN_14256c520(Scaleform::GFx::MovieImpl* proot, Scaleform::GFx::Video::VideoProvider* pprovider);

namespace Scaleform { namespace GFx { namespace AS3 {

using namespace Video;

// @0x140025830
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::Seek(float pos, MovieImpl* proot)
{
    SeekPos = pos;
    if (pVideoPlayer)
    {
        SeekNotificationSent = false;
        VideoPlayer::Status status = pVideoPlayer->GetStatus();
        if (status == VideoPlayer::Ready || status == VideoPlayer::Stopping || status == VideoPlayer::Playing ||
            status == VideoPlayer::Finished)
        {
            pVideoPlayer->Seek((UInt32)((float)VInfo.FrameRate / 1000.0f * SeekPos));
            if (status == VideoPlayer::Finished && proot)
                FUN_14256c520(proot, this);
        }
        InitSoundChannel();
    }
}

// @0x1400258e0
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::SendNotification(NetStreamInterface::Notification n, bool error)
{
    String code(NetStreamInterface::NotificationToString(n));
    String level(error ? "error" : "status");
    if (pNetStreamInterface)
        pNetStreamInterface->DispatchNetStatus(code, level);
}

// @0x140025990
void VideoProviderNetStream::SendSubtitle()
{
    if (strncmp(pSubtitle, pSubtitleTmp, VInfo.MaxSubtitleLen) != 0)
    {
        strncpy_s(pSubtitle, VInfo.MaxSubtitleLen, pSubtitleTmp, VInfo.MaxSubtitleLen);
        if (pNetStreamInterface)
            pNetStreamInterface->ExecuteOnSubtitle(pSubtitle);
    }
}

// @0x140025ad0
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::SetAudioTarget(Sprite* ptarget)
{
    Sprite* pold = pAudioTarget ? GetAudioTargetSprite(pAudioTarget) : NULL;
    if (pold == ptarget)
        return;
    if (pold && pVideoPlayer)
    {
        Sound::SoundChannel* pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (pchan)
        {
            Sprite::ActiveSoundItem* pitem = pold->ReleaseActiveSound(pchan);
            if (pitem)
            {
                pitem->pChannel->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AttachActiveSound(pitem);
                pitem->Release();
            }
            else
            {
                pchan->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AddActiveSound(pchan, NULL, NULL);
            }
        }
    }
    pAudioTarget = ptarget->GetCharacterHandle();
}

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace Video {

// The display object a provider's frames are drawn into; only its weak-pointer base is needed here.
class VideoCharacter : public RefCountBaseWeakSupport<VideoCharacter, Stat_Default_Mem>
{
};

}}} // namespace Scaleform::GFx::Video

// VideoCharacter member that (re)creates its texture from the provider (sfr_video units, not recovered yet).
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo);

namespace Scaleform { namespace GFx { namespace AS3 {

using namespace Video;

// @0x140026c60
VideoProviderNetStream::VideoProviderNetStream(NetStreamInterface* pnsintf)
    : pNetStreamInterface(pnsintf)
{
    Init();
}

// @0x140026320
VideoProviderNetStream::~VideoProviderNetStream()
{
    Close();
}

// @0x140025a30
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::NotifyVideoCharacters()
{
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pvideo = VideoCharacters[i];
        if (pvideo)
            FUN_140010a70(pvideo);
    }
}

// @0x140025f50
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::RegisterVideoCharacter(VideoCharacter* pvideo)
{
    if (!pvideo)
        return;
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pchar = VideoCharacters[i];
        if (pchar == pvideo)
            return;
    }
    VideoCharacters.PushBack(WeakPtr<VideoCharacter>(pvideo));
}

// @0x140026080
// MS2-FUNCTIONAL: other scheduling
VideoCharacter* VideoProviderNetStream::RemoveFirstVideoCharacter()
{
    if (VideoCharacters.GetSize() == 0)
        return NULL;
    Ptr<VideoCharacter> pvideo = VideoCharacters[0];
    VideoCharacters.RemoveAt(0);
    pTextureImage = NULL;
    return pvideo;
}

// @0x140026140
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::SendCuePoints()
{
    for (UPInt i = 0; i < CuePoints.GetSize(); ++i)
    {
        VideoPlayer::CuePoint cuePoint = CuePoints[i];
        if (pNetStreamInterface)
            pNetStreamInterface->ExecuteOnCuePoint(&cuePoint);
    }
}

// @0x140026450
// MS2-FUNCTIONAL: other scheduling
void VideoProviderNetStream::Advance()
{
    if (!pVideoPlayer)
        return;

    FrameIsReady = pVideoPlayer->IsTextureReady();
    pVideoPlayer->Decode();

    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    switch (status)
    {
    case VideoPlayer::Ready:
        if (!pTextureImage)
        {
            pTextureImage = *pVideoPlayer->CreateTexture(pTextureManager);
            if (pTextureImage)
            {
                pVideoPlayer->GetVideoInfo(&VInfo);
                float frameTime = 1000.0f / VInfo.FrameRate;
                FrameTime = frameTime - frameTime * 0.1f;
            }
        }
        if (SeekPos > 0.0f)
            pVideoPlayer->Seek((UInt32)((float)VInfo.FrameRate / 1000.0f * SeekPos));
        InitSoundChannel();
        NotifyVideoCharacters();
        SendNotification(NetStreamInterface::PlayStart);
        SendMetaData();
        pVideoPlayer->Play();
        break;

    case VideoPlayer::Playing:
        if (!SeekNotificationSent && FrameIsReady)
        {
            SeekNotificationSent = true;
            SendNotification(NetStreamInterface::SeekNotify);
        }
        break;

    case VideoPlayer::Finished:
    case VideoPlayer::Stopped:
        if (!SeekNotificationSent)
        {
            SeekNotificationSent = true;
            SendNotification(NetStreamInterface::SeekInvalidTime, true);
        }
        SendNotification(NetStreamInterface::PlayStop);
        break;

    case VideoPlayer::FileNotFound:
        if (!NotFoundNotificationSent)
        {
            NotFoundNotificationSent = true;
            SendNotification(NetStreamInterface::PlayStreamNotFound, true);
        }
        break;

    case VideoPlayer::InternalError:
        SendNotification(NetStreamInterface::PlayInternalError, true);
        break;

    default:
        break;
    }

    if (status == VideoPlayer::Ready || status == VideoPlayer::Playing)
    {
        CuePoints.Clear();
        pVideoPlayer->GetCurrentCuePoints(&CuePoints);
        SendCuePoints();
    }

    if (pNetStreamInterface && VInfo.MaxSubtitleLen > 0)
    {
        AllocSubtitleBuffers();
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, pSubtitleTmp, VInfo.MaxSubtitleLen);
        if (pSubtitle && pSubtitleTmp)
            SendSubtitle();
    }
    else
    {
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, NULL, 0);
    }
}

}}} // namespace Scaleform::GFx::AS3

// ==== Video player over the CRI easy player (0x140028360-0x14002a0e0) ================================================
// VideoPlayerImpl drives one CriMvEasyPlayer through the VideoPlayer status machine; the decoder object (pDecoder)
// starts/stops it. The Status member is re-read at every compare in the exe (volatile).

void     FUN_14258b240(unsigned ms);        // Thread::MSleep
unsigned __int64 FUN_1425e3590(void);               // Timer::GetTicks
void     FUN_1423dce40(void* plog, const char* pfmt, ...);   // Log::LogError

namespace Scaleform { namespace GFx { namespace Video {

// @0x1400285a0
void VideoPlayerImpl::Play()
{
    if (Stat == Ready)
    {
        pPlayer->SetSeekPosition(StartFrame);
        pPlayer->SetSubtitleChannel(SubtitleChannel);
        pPlayer->SetLoopFlag(LoopFlag);
        pPlayer->Start();
        Stat = Starting;
    }
}

// @0x140028610
void VideoPlayerImpl::Stop()
{
    if (Stat == Opening || Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking)
    {
        Stat = Stopping;
        StatusAfterStop = Stopped;
        pPlayer->Stop();
    }
}

// @0x140028670
void VideoPlayerImpl::Pause(bool on)
{
    if (PauseLocked)
    {
        PausePending = on;
        return;
    }
    if (Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking)
    {
        PauseFlag = on;
        pPlayer->Pause(PauseFlag);
    }
}

// MS2-FUNCTIONAL: ; register allocation and block order differ
// @0x1400286d0
UInt32 VideoPlayerImpl::GetPosition()
{
    if (Stat == Finished || Stat == Stopped)
        return 0;
    UInt32 pos = 0;
    if (StmPrm.num_video > 0)
        pos = CurrentFrame % StmPrm.video_prm[0].total_frames;
    return pos;
}

// @0x140028700
void VideoPlayerImpl::SetSubtitleChannel(int channel)
{
    if (Stat == Ready || Stat == Starting || Stat == Playing)
    {
        if ((int)StmPrm.num_subtitle > channel && SubtitleChannel != channel)
        {
            if (channel < 0)
            {
                if (SubtitleChannel == -1)
                    return;
                channel = -1;
            }
            SubtitleChannel = channel;
            pPlayer->SetSubtitleChannel(channel);
        }
    }
}

// MS2-FUNCTIONAL: ; register allocation and block order differ
// @0x140028760
int VideoPlayerImpl::GetSubtitleChannel()
{
    return SubtitleChannel == -1 ? -1 : SubtitleChannel;
}

// MS2-FUNCTIONAL: ; register allocation and block order differ
// @0x140028770
void VideoPlayerImpl::SetDecodeHeaderTimeout(float timeout)
{
    if (timeout > 0.0f)
        DecodeHeaderTimeout = (UInt64)(timeout * 1000.0f * 1000.0f);
    else
        DecodeHeaderTimeout = 0;
}

// @0x1400287d0
void VideoPlayerImpl::UpdateTexture(VideoImage* pimage, char* subtitle, int subtitleLength)
{
    if ((Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking || Stat == Stopping) && pimage)
    {
        UpdateTextureCalled = true;
        FrameOnTime = false;
        // VideoImage::Update(), slot 23 of the Render::Image vftable
        typedef void (*UpdateFunc)(VideoImage*);
        (*reinterpret_cast<UpdateFunc**>(pimage))[23](pimage);
        if (subtitle && subtitleLength > 0 && StmPrm.num_subtitle > 0 && SubtitleChannel != -1)
            pPlayer->GetSubtitleOnTime((CriUint8*)subtitle, subtitleLength);
    }
}

// @0x140028870
void VideoPlayerImpl::SetAudioTrack(int trackIndex)
{
    if (Stat == Ready || Stat == Starting || Stat == Playing)
    {
        pPlayer->SetAudioTrack(trackIndex);
        StartFrame = CurrentFrame % StmPrm.video_prm[0].total_frames;
        if (Stat != Ready)
        {
            Stat = Seeking;
            pPlayer->Stop();
        }
    }
}

// @0x1400288e0
void VideoPlayerImpl::ReplaceCenterVoice(int trackIndex)
{
    if (Stat == Ready)
        pPlayer->ReplaceCenterVoice(trackIndex);
}

// @0x140028910
void VideoPlayerImpl::SetLoopFlag(bool flag)
{
    LoopFlag = flag;
    if (Stat == Ready || Stat == Starting || Stat == Playing)
        pPlayer->SetLoopFlag(LoopFlag);
}

// @0x140028950
void VideoPlayerImpl::SetBufferTime(float time)
{
    if (pPlayer)
        pPlayer->SetBufferingTime(time);
}

// @0x140028970
void VideoPlayerImpl::SetNumberOfFramePools(unsigned pools)
{
    if (pPlayer)
        pPlayer->SetNumberOfFramePools(pools);
}

// @0x140028990
void VideoPlayerImpl::SetReloadThresholdTime(float time)
{
    if (pPlayer)
        pPlayer->SetReloadThresholdTime(time);
}

// @0x1400289b0
void VideoPlayerImpl::GetReadBufferInfo(ReadBufferInfo* info)
{
    if (pPlayer)
    {
        CriMvInputBufferInfo ibuf;
        pPlayer->GetInputBufferInfo(ibuf);
        info->BufferSize      = ibuf.buffer_size;
        info->DataSize        = ibuf.data_size;
        info->ReloadThreshold = ibuf.reload_threshold;
    }
}

// @0x1400291c0
void CriMvSystemTimer::SetSyncObject(VideoPlayer::SyncObject* psync)
{
    pSyncObj = psync;
}

// VideoDecoderSmp::FindPlayer, inlined at every use.
static inline int FindPlayer(Array<VideoPlayerImpl*>& players, VideoPlayerImpl* pplayer)
{
    for (UPInt i = 0; i < players.GetSize(); ++i)
    {
        if (players[i] == pplayer)
            return (int)i;
    }
    return -1;
}

// @0x1400292f0
void VideoDecoderSmp::StopDecoding(VideoPlayer* pp)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pp;
    if (FindPlayer(Players, pplayer) != -1)
    {
        pplayer->pPlayer->Stop();
        ExecuteDecode(pp);
    }
}

// @0x140028570
bool VideoDecoderSmp::IsDecodingStopped(VideoPlayer* pplayer)
{
    return !ExecuteDecode(pplayer);
}

// @0x140029360
bool VideoDecoderSmp::IsIORequired() const
{
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        VideoPlayer::ReadBufferInfo info;
        Players[i]->GetReadBufferInfo(&info);
        if (info.DataSize <= info.ReloadThreshold)
            return true;
    }
    return false;
}

// @0x1400293f0
void VideoPlayerImpl::StopAndWait()
{
    if (Stat == Opening || Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking || Stat == Stopping)
    {
        pDecoder->StopDecoding(this);
        while (!pDecoder->IsDecodingStopped(this))
        {
            Decode();
            FUN_14258b240(1);
        }
    }
}

// @0x140029480
void VideoPlayerImpl::Seek(UInt32 pos)
{
    if (Stat == Ready || Stat == Starting || Stat == Playing)
    {
        StartFrame = pos % StmPrm.video_prm[0].total_frames;
        Stat = Seeking;
        pPlayer->Stop();
    }
    else if (Stat == Finished)
    {
        StartFrame = pos % StmPrm.video_prm[0].total_frames;
        pDecoder->StartDecoding(this);
        Stat = Ready;
        Play();
    }
}

// @0x140029510
void VideoPlayerImpl::DecodeHeader()
{
    pPlayer->Update();
    pDecoder->ExecuteDecode(this);
    if (pPlayer->GetMovieInfo(StmPrm))
    {
        if (StmPrm.is_playable && StmPrm.num_video > 0)
        {
            Width    = StmPrm.video_prm[0].max_width;
            Height   = StmPrm.video_prm[0].max_height;
            HasAlpha = StmPrm.num_alpha > 0;
            Stat     = Ready;
            return;
        }
    }
    else
    {
        if (DecodeHeaderTimeout > 0 && FUN_1425e3590() - OpenTicks > DecodeHeaderTimeout)
        {
            Stat            = Stopping;
            StatusAfterStop = InternalError;
            pDecoder->StopDecoding(this);
            if (pLog)
                FUN_1423dce40(pLog, "Decode USM header timeout. Video file could be broken.\n");
            return;
        }
        if (pPlayer->GetStatus() != CriMvEasyPlayer::MVEASY_STATUS_ERROR)
            return;
    }
    StatusAfterStop = FileNotFound;
    Stat            = Stopping;
    pDecoder->StopDecoding(this);
}

// @0x140029640
void VideoPlayerImpl::Decode()
{
    if (!(Stat == Opening || Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking || Stat == Stopping))
        return;
    if (Stat == Opening)
    {
        DecodeHeader();
        return;
    }

    pPlayer->SyncMasterTimer();
    pPlayer->Update();
    CriMvEasyPlayer::Status st = pPlayer->GetStatus();
    if (st == CriMvEasyPlayer::MVEASY_STATUS_PLAYEND || st == CriMvEasyPlayer::MVEASY_STATUS_STOP)
    {
        if (pDecoder->IsDecodingStopped(this))
        {
            if (Stat == Stopping)
            {
                Stat = StatusAfterStop;
            }
            else if (Stat == Seeking && StartFrame < StmPrm.video_prm[0].total_frames)
            {
                pPlayer->Pause(0);
                pPlayer->SetSeekPosition(StartFrame);
                pPlayer->SetLoopFlag(LoopFlag);
                pPlayer->SetSubtitleChannel(SubtitleChannel);
                pPlayer->Start();
                pDecoder->StartDecoding(this);
                Stat = Starting;
            }
            else
            {
                Stat = Finished;
            }
        }
        return;
    }
    if (st == CriMvEasyPlayer::MVEASY_STATUS_ERROR)
    {
        if (StatusAfterStop != FileNotFound)
            StatusAfterStop = InternalError;
        Stat = Stopping;
        pDecoder->StopDecoding(this);
        if (pDecoder->IsDecodingStopped(this))
        {
            Stat = StatusAfterStop;
            return;
        }
    }
    if (FrameOnTime)
    {
        if (Stat == Starting)
        {
            CurrentFrame = StartFrame;
            pPlayer->Pause(PauseFlag);
            Stat = Playing;
            if (pTimer->pSyncObj)
                pTimer->pSyncObj->SetStartFrame(StartFrame);
        }
        if (FrameInfo.frame_id >= 0)
            CurrentFrame = FrameInfo.frame_id;
    }
    if (UpdateTextureCalled)
    {
        pDecoder->ExecuteDecode(this);
        UpdateTextureCalled = false;
    }
}

// @0x140029880
void VideoPlayerImpl::SetSubAudioTrack(int trackIndex)
{
    if (Stat == Ready && pSubSound)
        pPlayer->SetSubAudioTrack(trackIndex);
}

// @0x1400298b0
Sound::SoundChannel* VideoPlayerImpl::GetSoundChannel(SoundTrack track)
{
    if (track == MainTrack)
    {
        if (pSound)
            return pSound->GetSoundChannel();
    }
    else if (track == SubAudio)
    {
        if (pSubSound)
            return pSubSound->GetSoundChannel();
    }
    return 0;
}

// @0x1400298e0
void VideoPlayerImpl::SetSoundSpatialInfo(Array<Sound::SoundChannel::Vector> spatinfo[])
{
    if (pSound)
    {
        Sound::SoundChannel* pchan = pSound->GetSoundChannel();
        if (pchan)
            pchan->SetSpatialInfo(spatinfo);
    }
    if (pSubSound)
    {
        Sound::SoundChannel* pchan = pSubSound->GetSoundChannel();
        if (pchan)
            pchan->SetSpatialInfo(spatinfo);
    }
}

}}} // namespace Scaleform::GFx::Video

void FUN_14257dc30(void*);
void FUN_14257dcb0(void*);
extern "C" void* DAT_143b15f60;

// MS2-FUNCTIONAL: resize a Scaleform heap-backed pointer array, keeping capacity four-element aligned.
// @0x14001c570
__declspec(noinline) void FUN_14001c570(CriUint64* array, void*, CriUint64 requestedCapacity)
{
    void* oldData = (void*)(uintptr_t)array[0];
    CriUint64 capacity = requestedCapacity == 0 ? 0 : (requestedCapacity + 3) & ~(CriUint64)3;
    void* heap = DAT_143b15f60;
    void** vtable = heap ? *(void***)heap : NULL;
    if (requestedCapacity == 0)
    {
        if (oldData && vtable)
            ((void (*)(void*, void*))vtable[12])(heap, oldData);
        array[0] = 0;
        array[2] = 0;
        return;
    }
    if (oldData && vtable)
    {
        void* resized = ((void* (*)(void*, void*, size_t))vtable[11])(
            heap, oldData, (size_t)(capacity * sizeof(void*)));
        array[0] = (CriUint64)(uintptr_t)resized;
        array[2] = capacity;
        return;
    }
    if (vtable)
    {
        const CriUint32 allocationFlags[2] = { 2, 0 };
        void* data = ((void* (*)(void*, size_t, const CriUint32*))vtable[10])(
            heap, (size_t)(capacity * sizeof(void*)), allocationFlags);
        array[0] = (CriUint64)(uintptr_t)data;
    }
    array[2] = capacity;
}

// RefCountImpl::Release, inlined: the last reference deletes the object through its virtual destructor.
class CriRefCountView : public Scaleform::RefCountImplCore
{
public:
    void Release()
    {
        if (InterlockedDecrement((volatile LONG*)&RefCount) == 0)
            delete this;
    }
};

static inline void CriRefCountRelease(Scaleform::RefCountImplCore* object)
{
    ((CriRefCountView*)object)->Release();
}

// release a RefCountImpl pointer stored in a Scaleform Ptr wrapper (the Ptr destructor).
// @0x14001d210
void FUN_14001d210(Scaleform::RefCountImplCore** pointer)
{
    if (*pointer)
        CriRefCountRelease(*pointer);
}

// replace a Scaleform Ptr wrapper target and release its prior reference.
// @0x14001d240
Scaleform::RefCountImplCore** FUN_14001d240(Scaleform::RefCountImplCore** pointer, Scaleform::RefCountImplCore* replacement)
{
    if (*pointer)
        CriRefCountRelease(*pointer);
    *pointer = replacement;
    return pointer;
}

// ArrayData::Resize inlined into PushBack; the separate inline scope makes cl reload the size.
static __forceinline void CriPointerArrayResize(CriUint64* array, CriUint64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
            FUN_14001c570(array, array, newSize);
    }
    else if (newSize >= array[2])
        FUN_14001c570(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// append a pointer to a Scaleform array and grow the heap allocation when needed (ArrayData::PushBack).
// @0x14001d290
void FUN_14001d290(CriUint64* array, const CriUint64* value)
{
    CriPointerArrayResize(array, array[1] + 1);
    CriUint64* slot = (CriUint64*)(uintptr_t)array[0] + array[1] - 1;
    if (slot)
        *slot = *value;
}

// resize a Scaleform array and adjust its logical element count (ArrayData::Resize).
// @0x14001d310
void FUN_14001d310(CriUint64* array, CriUint64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
            FUN_14001c570(array, array, newSize);
    }
    else if (newSize >= array[2])
        FUN_14001c570(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// the sound-channel holder FUN_14001c170 updates: channel at +0x10, volume at +0x18, a dirty byte at +0x20.
struct CriSoundChannelHolder
{
    CriUint8 Header[0x10];
    void* Channel;
    float Volume;
    CriUint32 Reserved;
    CriUint8 Dirty;
};

// replace a reference-counted sound channel and apply the stored volume.
// @0x14001c170
void FUN_14001c170(void* owner, void* replacement)
{
    CriSoundChannelHolder* holder = (CriSoundChannelHolder*)owner;
    void** slot = &holder->Channel;
    if (*slot)
        ((void (*)(void*))(*(void***)*slot)[3])(*slot);
    if (replacement)
        FUN_14257dc30(replacement);
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = replacement;
    void* channel = *(void* volatile*)slot;   // the exe reloads the slot here
    holder->Dirty = 0;
    if (channel)
        ((void (*)(void*, float))(*(void***)channel)[10])(channel, holder->Volume);
}

// adjust a Scaleform array size and grow or shrink capacity using the shared array helper (ArrayData::Resize).
// @0x14001cab0
void FUN_14001cab0(void* array, void* arrayArg, CriUint64 newSize)
{
    CriUint64* fields = (CriUint64*)array;
    if (newSize < fields[1])
    {
        if (newSize < (fields[2] >> 1))
            FUN_14001c570(fields, arrayArg, newSize);
    }
    else if (newSize >= fields[2])
        FUN_14001c570(fields, arrayArg, newSize + (newSize >> 2));
    fields[1] = newSize;
}

// RefCountImpl::Release on the object itself.
// @0x14001cb10
void FUN_14001cb10(Scaleform::RefCountImplCore* object)
{
    CriRefCountRelease(object);
}

// allocate and construct a VideoSoundRendererStream from the supplied heap state.
// @0x14001d1d0
void* FUN_14001d1d0(void* state)
{
    Scaleform::MemoryHeap** fields = (Scaleform::MemoryHeap**)((CriUint8*)state + 0x10);
    return ::new (fields[0]->Alloc(0x90)) Scaleform::GFx::Video::VideoSoundRendererStream(
        fields[0], (Scaleform::Sound::SoundRenderer*)fields[1]);
}

// clear a Scaleform pointer array and release oversized storage (ArrayData::Resize(0)).
// @0x14001d5d0
void FUN_14001d5d0(CriUint64* array)
{
    if (0 < array[1])
    {
        if (0 < (array[2] >> 1))
        {
            if (array[0])
            {
                void* heap = DAT_143b15f60;
                ((void (*)(void*, void*))(*(void***)heap)[12])(heap, (void*)(uintptr_t)array[0]);
                array[0] = 0;
            }
            array[2] = 0;
        }
    }
    else if (0 >= array[2])
        FUN_14001c570(array, array, 0);
    array[1] = 0;
}

// @0x14001d6d0
void FUN_14001d6d0(CriUint64* array, CriSint64 index)
{
    if (array[1] == 1)
    {
        FUN_14001d5d0(array);
        return;
    }
    CriUint64* data = (CriUint64*)(uintptr_t)array[0];
    CriUint64 count = array[1] - (CriUint64)index - 1;
    memmove(data + index, data + index + 1, (size_t)count * sizeof(CriUint64));
    --array[1];
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the stored allocation through Scaleform's global heap.
// @0x140029a10
void FUN_140029a10(void** value)
{
    if (*value)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, *value);
    }
}
#pragma optimize("", on)

// @0x140029070
void* FUN_140029070(void* destination, const void* source)
{
    FUN_142585580(destination, source);
    FUN_142585580((CriUint8*)destination + 8, (const CriUint8*)source + 8);
    return destination;
}

// @0x1400293d0
void* FUN_1400293d0(void* object)
{
    FUN_142584ce0(object);
    FUN_142584ce0((CriUint8*)object + 8);
    return object;
}

// initialize the two embedded Scaleform strings when the optional CRI value exists.
// @0x140029de0
void FUN_140029de0(void* object)
{
    if (object)
    {
        FUN_142584ce0(object);
        FUN_142584ce0((CriUint8*)object + 8);
    }
}

// MS2-FUNCTIONAL: initialize the CRI system-timer callback object and retain its source.
// @0x140029e40
void* FUN_140029e40(void* object, void* source)
{
    *(CriUint32*)((CriUint8*)object + 8) = 1;
    *(const void***)object = (const void**)DAT_1431b8fc8;
    *(const void***)((CriUint8*)object + 0x10) = (const void**)DAT_1431b8fa0;
    *(void**)((CriUint8*)object + 0x18) = NULL;
    if (source)
        ++*(CriUint32*)((CriUint8*)source + 8);
    if (*(void**)((CriUint8*)object + 0x18))
        FUN_14257dcd0(*(void**)((CriUint8*)object + 0x18));
    *(void**)((CriUint8*)object + 0x18) = source;
    return object;
}

// @0x140029ed0
void FUN_140029ed0(void* object)
{
    *(const void***)object = (const void**)DAT_1431b8fc8;
    *(const void***)((CriUint8*)object + 0x10) = (const void**)DAT_1431b8fa0;
    if (*(void**)((CriUint8*)object + 0x18))
        FUN_14257dcd0(*(void**)((CriUint8*)object + 0x18));
    *(const void***)((CriUint8*)object + 0x10) = (const void**)DAT_1431b8e08;
    FUN_14257db50(object);
}

// MS2-FUNCTIONAL: perform the callback teardown and free the object when scalar-delete is requested.
// @0x140029fa0
void* FUN_140029fa0(void* object, CriUint64 flags)
{
    FUN_140029ed0(object);
    if (flags & 1)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, object);
    }
    return object;
}

// The CRI output callback's constructor (CriMvSound(MemoryHeap*, VideoSound*)): the reference-count base, the heap,
// the retained sound interface and the three vptrs; the four buffer slots start empty.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x14002a010
void* FUN_14002a010(void* mem, void* pheap, void* psound)
{
    *(const void***)mem = (const void**)DAT_1431b9028;
    *(int*)((CriUint8*)mem + 8) = 1;
    *(void**)((CriUint8*)mem + 0x18) = pheap;
    *(const void***)((CriUint8*)mem + 0x10) = (const void**)DAT_1431b8fd0;
    if (psound)
        ++*(int*)((CriUint8*)psound + 8);
    *(void**)((CriUint8*)mem + 0x20) = psound;
    *(const void***)((CriUint8*)mem + 0x28) = (const void**)DAT_1431b8f30;
    *(void**)((CriUint8*)mem + 0x30) = 0;
    *(void**)((CriUint8*)mem + 0x38) = 0;
    *(void**)((CriUint8*)mem + 0x40) = 0;
    *(void**)((CriUint8*)mem + 0x48) = 0;
    return mem;
}

// @0x14002a090
void FUN_14002a090(void* object)
{
    *(const void***)object = (const void**)DAT_1431b9028;
    *(const void***)((CriUint8*)object + 0x10) = (const void**)DAT_1431b8fd0;
    *(const void***)((CriUint8*)object + 0x28) = (const void**)DAT_1431b8f18;
    if (*(void**)((CriUint8*)object + 0x20))
        FUN_14257dcd0(*(void**)((CriUint8*)object + 0x20));
    *(const void***)((CriUint8*)object + 0x10) = (const void**)DAT_1431b8db0;
    FUN_14257db50(object);
}

// @0x140028360
void* FUN_140028360(void* guard, CRITICAL_SECTION* section)
{
    *(CRITICAL_SECTION**)guard = section;
    EnterCriticalSection(section);
    return guard;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the referenced CRI object through its deleting virtual slot.
// @0x140028480
void FUN_140028480(void* object)
{
    if (object)
    {
        void** vtable = *(void***)object;
        ((void (*)(void*, CriUint32))vtable[0])(object, 1);
    }
}
#pragma optimize("", on)

// @0x1400284b0
void* FUN_1400284b0(void* object, CriUint8 flags)
{
    *(const void***)object = (const void**)DAT_1431b8f18;
    if (flags & 1)
        ::operator delete(object);
    return object;
}

// VideoPlayer's deleting dtor: its RefCountNTSImplCore base dtor is empty here.
// @0x140029160
void* FUN_140029160(void* object, unsigned flags)
{
    *(const void***)object = (const void**)DAT_1431b8e30;
    if (flags & 1)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, object);
    }
    return object;
}

// @0x140029280
void* FUN_140029280(void* object, CriUint8 flags)
{
    *(const void***)object = (const void**)DAT_1431b8f18;
    if (flags & 1)
        ::operator delete(object);
    return object;
}

// @0x14001ca70
void* FUN_14001ca70(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, object);
    }
    return object;
}

// @0x140028a30
void* FUN_140028a30(void** slot, void* target)
{
    if (target)
        FUN_14257dc30(target);
    *slot = target;
    return slot;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release a RefCountImpl target held by this pointer slot.
// @0x140028ad0
void FUN_140028ad0(void** slot)
{
    if (*slot)
        FUN_14257dcb0(*slot);
}
#pragma optimize("", on)

// @0x140028af0
void* FUN_140028af0(void** slot, void* target)
{
    if (target)
        FUN_14257dc30(target);
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = target;
    return slot;
}

// @0x140028b30
void* FUN_140028b30(void** slot, void* target)
{
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = target;
    return slot;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the stored RefCountImplCore target.
// @0x140028bb0
void FUN_140028bb0(void** slot)
{
    if (*slot)
        FUN_14257dcd0(*slot);
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the stored RefCountImplCore target.
// @0x140028c20
void FUN_140028c20(void** slot)
{
    if (*slot)
        FUN_14257dcd0(*slot);
}
#pragma optimize("", on)

// @0x140028c40
void* FUN_140028c40(void** slot, void* target)
{
    if (target)
        ++*(CriUint32*)((CriUint8*)target + 8);
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

// @0x140028c90
void* FUN_140028c90(void** slot, void* target)
{
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the stored RefCountImplCore target.
// @0x140028d00
void FUN_140028d00(void** slot)
{
    if (*slot)
        FUN_14257dcd0(*slot);
}
#pragma optimize("", on)

// @0x140028d20
void* FUN_140028d20(void** slot, void* target)
{
    if (target)
        ++*(CriUint32*)((CriUint8*)target + 8);
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

// @0x140028d70
void* FUN_140028d70(void** slot, void* target)
{
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// release the stored RefCountImplCore target.
// @0x140028dd0
void FUN_140028dd0(void** slot)
{
    if (*slot)
        FUN_14257dcd0(*slot);
}
#pragma optimize("", on)

// @0x140028df0
void* FUN_140028df0(void** slot, void* target)
{
    if (target)
        ++*(CriUint32*)((CriUint8*)target + 8);
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

// @0x140028e40
void* FUN_140028e40(void** slot, void* target)
{
    if (*slot)
        FUN_14257dcd0(*slot);
    *slot = target;
    return slot;
}

// @0x140028eb0
void* FUN_140028eb0(void** slot, void* target)
{
    if (target)
        FUN_14257dc30(target);
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = target;
    return slot;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// these three CRI members each release their owned heap buffer.
// @0x140029af0
void FUN_140029af0(void** value)
{
    if (*value)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, *value);
    }
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// this member releases its owned Scaleform heap buffer when non-null.
// @0x140029b10
void FUN_140029b10(void** value)
{
    if (*value)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, *value);
    }
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// this member releases its owned Scaleform heap buffer when non-null.
// @0x140029e20
void FUN_140029e20(void** value)
{
    if (*value)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, *value);
    }
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// forward the CRI adapter's start callback when one is installed.
// @0x140029f20
void FUN_140029f20(void* adapter)
{
    void* target = *(void**)((CriUint8*)adapter + 8);
    if (target)
    {
        void** vtable = *(void***)target;
        ((void (*)(void*))vtable[2])(target);
    }
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// forward the CRI adapter's stop callback when one is installed.
// @0x140029f40
void FUN_140029f40(void* adapter)
{
    void* target = *(void**)((CriUint8*)adapter + 8);
    if (target)
    {
        void** vtable = *(void***)target;
        ((void (*)(void*))vtable[3])(target);
    }
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// pass the enabled state through the adapter's third callback.
// @0x140029f60
void FUN_140029f60(void* adapter, int enabled)
{
    void* target = *(void**)((CriUint8*)adapter + 8);
    if (target)
    {
        void** vtable = *(void***)target;
        ((void (*)(void*, bool))vtable[4])(target, enabled == 1);
    }
}
#pragma optimize("", on)

static __forceinline void CriArrayReserve(void** array, CriUint64* capacity, CriUint64 count, size_t elementSize)
{
    void* data = array[0];
    if (count == 0)
    {
        if (data)
        {
            void* heap = DAT_143b15f60;
            ((void (*)(void*, void*))(*(void***)heap)[12])(heap, data);
        }
        array[0] = NULL;
        *capacity = 0;
        return;
    }

    void* heap = DAT_143b15f60;
    CriUint64 newCapacity = (count + 3) & ~(CriUint64)3;
    if (data)
    {
        data = ((void* (*)(void*, void*, size_t))(*(void***)heap)[11])(
            heap, data, (size_t)(newCapacity * elementSize));
        *capacity = newCapacity;
        array[0] = data;
    }
    else
    {
        CriUint32 heapFlags = 2;
        array[0] = ((void* (*)(void*, size_t, const CriUint32*))(*(void***)heap)[10])(
            heap, (size_t)(newCapacity * elementSize), &heapFlags);
        *capacity = newCapacity;
    }
}

// MS2-FUNCTIONAL: grow or release the CRI pointer vector with four-slot capacity rounding.
// @0x140029bf0
void FUN_140029bf0(void** array, void*, CriUint64 count)
{
    CriArrayReserve(array, (CriUint64*)array + 2, count, sizeof(void*));
}

// MS2-FUNCTIONAL: this CRI vector uses the same four-slot allocation policy.
// @0x140029c90
void FUN_140029c90(void** array, void*, CriUint64 count)
{
    CriArrayReserve(array, (CriUint64*)array + 2, count, sizeof(void*));
}

// MS2-FUNCTIONAL: this CRI vector stores three-word elements and rounds capacity by four.
// @0x140029d30
void FUN_140029d30(void** array, void*, CriUint64 count)
{
    CriArrayReserve(array, (CriUint64*)array + 2, count, sizeof(void*) + 4);
}

static void* CriRefCountDeletingDtor(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if ((flags & 1) != 0)
    {
        void* heap = DAT_143b15f60;
        void** vtable = *(void***)heap;
        ((void (*)(void*, void*))vtable[12])(heap, object);
    }
    return object;
}

// @0x140029970
void* FUN_140029970(void* object, unsigned flags) { return CriRefCountDeletingDtor(object, flags); }

// @0x1400299d0
void* FUN_1400299d0(void* object, unsigned flags) { return CriRefCountDeletingDtor(object, flags); }

// @0x140029a50
void* FUN_140029a50(void* object, unsigned flags) { return CriRefCountDeletingDtor(object, flags); }

// @0x140029ab0
void* FUN_140029ab0(void* object, unsigned flags) { return CriRefCountDeletingDtor(object, flags); }

// Base vftables the exe does have (the same addresses sfr_video_01 pins for its copies of these classes)
// MS2-PIN: ??_7RefCountWeakSupportImpl@Scaleform@@6B@ 0x143183cf8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountWeakSupportImpl@Scaleform@@$01@Scaleform@@6B@ 0x143183cf8
// MS2-PIN: ??_7?$RefCountBaseWeakSupport@VVideoProvider@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ??_7SwfVideoSyncObject@AS3@GFx@Scaleform@@6B@ 0x1431b8a60
// MS2-PIN: ??_7Video@0GFx@Scaleform@@6B@ 0x1431b8050
// MS2-PIN: ??_7AuxStreamer@SoundRenderer@Sound@Scaleform@@6B@ 0x1431b80b8
// MS2-PIN: ??_7VideoSoundSystem_SoundRenderer@Video@GFx@Scaleform@@6B@ 0x1431b80e0
// MS2-PIN: ??_7VideoBase@Video@GFx@Scaleform@@6B@ 0x1431b8100
// MS2-PIN: ??_7SoundChannelDelegate@Sound@Scaleform@@6B@ 0x1431b8160
// MS2-PIN: ??_7VideoSoundRendererStream@Video@GFx@Scaleform@@6B@ 0x1431b81e0
// MS2-PIN: ??_7Streamer@VideoSoundRendererStream@Video@GFx@Scaleform@@6B@ 0x1431b8238
// MS2-PIN: ??_7VideoSound@Video@GFx@Scaleform@@6B@ 0x1431b4b80
// MS2-PIN: ??_7VideoProviderNetStream@AS3@GFx@Scaleform@@6B@ 0x1431b8a90
// MS2-PIN: ??_7VideoProvider@Video@GFx@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ??_7SyncObject@VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b4f78
// MS2-FUNCTIONAL ??_GVideo@0GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GVideo@0GFx@Scaleform@@UEAAPEAXI@Z 0x14001c720
// MS2-FUNCTIONAL ??_GAuxStreamer@SoundRenderer@Sound@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GAuxStreamer@SoundRenderer@Sound@Scaleform@@UEAAPEAXI@Z 0x14001c640
// MS2-FUNCTIONAL ??_GVideoSoundSystem_SoundRenderer@Video@GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GVideoSoundSystem_SoundRenderer@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x14001c940
// MS2-FUNCTIONAL ??_GVideoBase@Video@GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GVideoBase@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x14001cb60
// MS2-FUNCTIONAL ??_GVideoSoundRendererStream@Video@GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GVideoSoundRendererStream@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x14001d0b0
// MS2-FUNCTIONAL ??_GStreamer@VideoSoundRendererStream@Video@GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GStreamer@VideoSoundRendererStream@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x14001d3d0
// MS2-FUNCTIONAL ??_GVideoProviderNetStream@AS3@GFx@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GVideoProviderNetStream@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x140026d70
// MS2-FUNCTIONAL ??_GSoundChannelDelegate@Sound@Scaleform@@UEAAPEAXI@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): the exe's copy calls the out-of-line dtor and has no sized-delete flag-4 path; ours inlines the dtor and adds it, same effect
// MS2-PIN: ??_GSoundChannelDelegate@Sound@Scaleform@@UEAAPEAXI@Z 0x14001cf30
// MS2-FUNCTIONAL ?Stop@SoundChannelDelegate@Sound@Scaleform@@UEAAXXZ: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?Stop@SoundChannelDelegate@Sound@Scaleform@@UEAAXXZ 0x14001cd80
// MS2-FUNCTIONAL ?Pause@SoundChannelDelegate@Sound@Scaleform@@UEAAX_N@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?Pause@SoundChannelDelegate@Sound@Scaleform@@UEAAX_N@Z 0x14001cda0
// MS2-FUNCTIONAL ?SetPosition@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?SetPosition@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z 0x14001cde0
// MS2-FUNCTIONAL ?Loop@SoundChannelDelegate@Sound@Scaleform@@UEAAXHMM@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?Loop@SoundChannelDelegate@Sound@Scaleform@@UEAAXHMM@Z 0x14001ce20
// MS2-FUNCTIONAL ?SetVolume@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?SetVolume@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z 0x14001ce60
// MS2-FUNCTIONAL ?SetPan@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?SetPan@SoundChannelDelegate@Sound@Scaleform@@UEAAXM@Z 0x14001cea0
// MS2-FUNCTIONAL ?SetTransforms@SoundChannelDelegate@Sound@Scaleform@@UEAAXAEBV?$Array@UTransform@SoundChannel@Sound@Scaleform@@$01UArrayDefaultPolicy@4@@3@@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?SetTransforms@SoundChannelDelegate@Sound@Scaleform@@UEAAXAEBV?$Array@UTransform@SoundChannel@Sound@Scaleform@@$01UArrayDefaultPolicy@4@@3@@Z 0x14001cec0
// MS2-FUNCTIONAL ?SetSpatialInfo@SoundChannelDelegate@Sound@Scaleform@@UEAAXQEBV?$Array@UVector@SoundChannel@Sound@Scaleform@@$01UArrayDefaultPolicy@4@@3@@Z: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): calls the delegate and returns where clang/VS2017 tail-jump
// MS2-PIN: ?SetSpatialInfo@SoundChannelDelegate@Sound@Scaleform@@UEAAXQEBV?$Array@UVector@SoundChannel@Sound@Scaleform@@$01UArrayDefaultPolicy@4@@3@@Z 0x14001cee0

// ---- full-exe unresolved: leaves without .pdata that data_cri's tables reference as ?FUN_<va>@@YAXXZ ----

typedef void* (*cri01_cb4)(void* user, void* a, void* b, void* c);
struct cri01_cbslot { cri01_cb4 fn; void* user; };
struct cri01_cbhost                     // {fn, user} pairs at +0x08 and +0x18 (+0x20/+0x30 on the setters' object)
{
    void* vtbl;
    cri01_cbslot s08;
    cri01_cbslot s18;
};
struct cri01_cbhost2 { void* vtbl; void* _08[3]; cri01_cbslot s20; cri01_cbslot s30; };

// MS2-FUNCTIONAL: callback slot {fn +0x18, user +0x20}: calls fn(user, ...) when set, else 0.
// @0x140029240
void* FUN_140029240(cri01_cbhost* self, void* a, void* b, void* c)
{
    cri01_cb4 fn = self->s18.fn;
    return fn ? fn(self->s18.user, a, b, c) : nullptr;
}

// MS2-FUNCTIONAL: callback slot {fn +0x08, user +0x10}: calls fn(user, ...) when set, else 0.
// @0x140029260
void* FUN_140029260(cri01_cbhost* self, void* a, void* b, void* c)
{
    cri01_cb4 fn = self->s08.fn;
    return fn ? fn(self->s08.user, a, b, c) : nullptr;
}

// MS2-FUNCTIONAL: deleting-destructor thunk of the second base (+0x10).
// @0x140029ec0
void* FUN_140029ec0(char* self, CriUint64 flags)
{
    return FUN_140029fa0(self - 0x10, flags);
}

struct cri01_sizer { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
                     virtual void v4() = 0; virtual void GetSize(void* lo, void* hi) = 0; };

struct cri01_sizerhost { void* vtbl; cri01_sizer* inner; };
// MS2-FUNCTIONAL: forwards to the inner object's slot 5 (+0x28); with none, reports {0, 1000}.
// @0x140029f80
void FUN_140029f80(cri01_sizerhost* self, CriUint64* lo, CriUint64* hi)
{
    cri01_sizer* o = self->inner;
    if (o)
    {
        o->GetSize(lo, hi);
        return;
    }
    *lo = 0;
    *hi = 1000;
}

// MS2-FUNCTIONAL: stores the callback pair {fn, user} at +0x20.
// @0x14002a060
void FUN_14002a060(cri01_cbhost2* self, void* fn, void* user)
{
    self->s20.fn = (cri01_cb4)fn;
    self->s20.user = user;
}

// MS2-FUNCTIONAL: stores the callback pair {fn, user} at +0x30.
// @0x14002a070
void FUN_14002a070(cri01_cbhost2* self, void* fn, void* user)
{
    self->s30.fn = (cri01_cb4)fn;
    self->s30.user = user;
}

void* FUN_14002a0e0(void* object, CriUint32 flags);   // sfr_cri_02

// MS2-FUNCTIONAL: deleting-destructor thunk of the second base (+0x10).
// @0x14002a080
void* FUN_14002a080(char* self, CriUint32 flags)
{
    return FUN_14002a0e0(self - 0x10, flags);
}
