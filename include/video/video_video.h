// Recovered Scaleform GFx 4.1.18 Video: the video state (VideoBase/Video), its sound system and decoder interfaces.
// Written from the exe (sfr lane); class and member names follow the exe's RTTI-free vtables and the Scaleform naming.
// Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// Layouts checked against Video_Video (sfr_cri_01): Video 0x60 bytes, VideoSoundRendererStream 0x90,
// VideoSoundSystem_SoundRenderer 0x20, SoundChannelDelegate 0x28. Slot orders from the vtables:
//   Video                     0x1431b8050 (13 slots: VideoBase 0..9, then ApplySystemSettings x3 in reverse
//                                          declaration order, as MSVC lays out overloads)
//   VideoBase                 0x1431b8100
//   VideoSoundSystem_SoundRenderer 0x1431b80e0, VideoSoundRendererStream 0x1431b81e0, VideoSound 0x1431b4b80
//   VideoSoundRendererStream::Streamer 0x1431b8238, Sound::SoundRenderer::AuxStreamer 0x1431b80b8
#ifndef MS2_SF_VIDEO_VIDEO_H
#define MS2_SF_VIDEO_VIDEO_H

#include "../kernel/sf_array.h"
#include "../kernel/sf_refcount.h"
#include "../kernel/sf_threads.h"
#include "../gfx/gfx_state.h"
#include "../sound/sound_renderer.h"

namespace Scaleform {

class Log;
namespace Render { class TextureManager; }

namespace GFx {

class LoadProcess;
class TaskManager;
struct TagInfo;

namespace Video {

class VideoPlayer;
class VideoReader;
class AS2VideoSupport;
class AS3VideoSupport;

// The AS2/AS3 glue a Video state is created with (copied into Video::pAS2VSupport/pAS3VSupport).
struct VideoVMSupport
{
    AS2VideoSupport* pAS2VSupport;
    AS3VideoSupport* pAS3VSupport;
};

// Abstract video state stored in the StateBag (State_Video).
class VideoBase : public State
{
public:
    VideoBase() : State((StateType)30) {}   // State_Video (0x1e in 4.1.18; not in gfx_state.h yet)
    virtual ~VideoBase() {}

    virtual AS2VideoSupport* GetAS2Support() const = 0;                                               // 1
    virtual AS3VideoSupport* GetAS3Support() const = 0;                                               // 2
    virtual VideoPlayer*     CreateVideoPlayer(MemoryHeap*, TaskManager*, FileOpenerBase*, Log*) = 0;  // 3

    // Notified by the readers around file I/O.
    class ReadCallback : public RefCountBase<ReadCallback, Stat_Default_Mem>
    {
    public:
        virtual ~ReadCallback() {}
        virtual void OnReadRequested() = 0;
        virtual void OnReadCompleted() = 0;
    };

    virtual void             SetReadCallback(ReadCallback*) = 0;                                      // 4
    virtual bool             IsIORequired() const = 0;                                                // 5
    virtual void             EnableIO(bool) = 0;                                                      // 6
    virtual void             ReadDefineVideoStreamTag(LoadProcess*, const TagInfo&) = 0;              // 7
    virtual Render::TextureManager* GetTextureManager() const = 0;                                    // 8
    virtual MemoryHeap*      GetHeap() const = 0;                                                     // 9
};

// One playing movie (implemented by VideoPlayerImpl); only the slots the recovered code calls are named.
class VideoPlayer : public NewOverrideBase<Stat_Default_Mem>
{
public:
    virtual ~VideoPlayer() {}
    virtual void Destroy() { delete this; }
};

class VideoSound;

// Creates the VideoSound objects that play a movie's audio tracks.
class VideoSoundSystem : public RefCountBaseNTS<VideoSoundSystem, Stat_Default_Mem>
{
public:
    VideoSoundSystem(MemoryHeap* pheap) : pHeap(pheap) {}
    virtual ~VideoSoundSystem() {}

    virtual VideoSound* Create() = 0;   // 1
    virtual void        Update() {}     // 2

    MemoryHeap* GetHeap() const { return pHeap; }

private:
    MemoryHeap* pHeap;
};

// Output for one audio track of a movie: pulls PCM data from the decoder through PCMStream.
class VideoSound : public RefCountBaseNTS<VideoSound, Stat_Default_Mem>
{
public:
    enum PCMFormat
    {
        PCM_SInt16,
        PCM_Float
    };
    enum Status
    {
        Sound_Stopped,
        Sound_Playing,
        Sound_Paused
    };
    enum { MaxChannels = 8 };

    class PCMStream
    {
    public:
        virtual ~PCMStream() {}
        virtual UInt32 GetDataSInt16(UInt32 nch, SInt16* pcmbuf[], UInt32 samplesRequested) = 0;
        virtual UInt32 GetDataFloat(UInt32 nch, float* pcmbuf[], UInt32 samplesRequested)   = 0;
    };

    VideoSound() {}
    virtual ~VideoSound() {}

    virtual bool                 CreateOutput(UInt32 channels, UInt32 samplerate) = 0;  // 1
    virtual void                 DestroyOutput() = 0;                                  // 2
    virtual PCMFormat            GetPCMFormat() const = 0;                             // 3
    virtual void                 Start(PCMStream* pstream) = 0;                        // 4
    virtual void                 Stop() = 0;                                           // 5
    virtual void                 Pause(bool paused) = 0;                               // 6
    virtual Status               GetStatus() const = 0;                                // 7
    virtual void                 GetTime(UInt64* count, UInt64* unit) const = 0;       // 8
    virtual Sound::SoundChannel* GetSoundChannel() = 0;                                // 9
    virtual void                 SetSpatialInfo(const Array<Sound::SoundChannel::Vector> spatinfo[]) = 0; // 10
};

// Drives the decoding of the players (thread or same-thread implementation).
class VideoDecoder : public RefCountBaseNTS<VideoDecoder, Stat_Default_Mem>
{
public:
    virtual void StartDecoding(VideoPlayer*)     = 0;   // 1
    virtual void StopDecoding(VideoPlayer*)      = 0;   // 2
    virtual bool IsDecodingStopped(VideoPlayer*) = 0;   // 3
    virtual bool ExecuteDecode(VideoPlayer*)     = 0;   // 4
    virtual void GetReadBufferInfo(void* info)   = 0;   // 5 (Array<VideoPlayer::ReadBufferInfo>&, unrecovered)
    virtual bool IsIORequired() const            = 0;   // 6
    virtual void PauseDecoding(bool)             = 0;   // 7
};

// Creates the file readers of the players and keeps the list of live ones.
class VideoReaderConfig : public RefCountBaseNTS<VideoReaderConfig, Stat_Default_Mem>
{
public:
    typedef VideoBase::ReadCallback ReadCallback;

    virtual VideoReader* CreateReader() = 0;                    // 1
    virtual void         SetReadCallback(ReadCallback*) {}      // 2
    virtual void         DetachReader(VideoReader* preader);    // 3
    void                 AttachReader(VideoReader* preader);
    virtual void         EnableIO(bool enable) { IOEnabled = enable; } // 4

protected:
    MemoryHeap*          pHeap;         // +0x10
    Ptr<FileOpenerBase>  pFileOpener;   // +0x18 (layout only)
    Array<VideoReader*>  Readers;       // +0x20
    volatile bool        IOEnabled;     // +0x38
};

// The video state the game installs.
class Video : public VideoBase
{
public:
    Video(const VideoVMSupport& vmSupport, Thread::ThreadPriority decodingThreadsPriority, bool autoInit = true);
    virtual ~Video();

    virtual AS2VideoSupport* GetAS2Support() const { return pAS2VSupport; }
    virtual AS3VideoSupport* GetAS3Support() const { return pAS3VSupport; }

    virtual VideoPlayer*     CreateVideoPlayer(MemoryHeap*, TaskManager*, FileOpenerBase*, Log*);
    virtual void             SetReadCallback(ReadCallback*);
    virtual bool             IsIORequired() const;
    virtual void             EnableIO(bool enable);
    virtual void             ReadDefineVideoStreamTag(LoadProcess* p, const TagInfo& tagInfo);
    virtual Render::TextureManager* GetTextureManager() const
                                                     { return (Render::TextureManager*)pTextureManager.GetPtr(); }
    virtual MemoryHeap*      GetHeap() const { return pHeap; }

    virtual void             ApplySystemSettings(VideoPlayer*) {}         // 12
    virtual void             ApplySystemSettings(VideoDecoder*) {}        // 11
    virtual void             ApplySystemSettings(VideoReaderConfig*) {}   // 10

    void                     SetSoundSystem(Sound::SoundRenderer* psoundRenderer);
    void                     SetSoundSystem(VideoSoundSystem* psoundSystem) { pSoundSystem = psoundSystem; }

    static void              Initialize();
    static void              Finalize();

    static unsigned          Initialized;     // 0x143b277b4
    static void*             pHandleWorkBuf;  // 0x143b277a8
    static UInt32            HandleWorkSize;  // 0x143b277b0

    enum { VIDEO_HANDLE_MAX = 8 };

protected:
    Ptr<MemoryHeap>              pHeap;                 // +0x18
    Ptr<RefCountImpl>            pTextureManager;       // +0x20 Render::TextureManager (render headers not shared yet)
    Ptr<VideoDecoder>            pDecoder;              // +0x28
    Ptr<VideoReaderConfig>       pReaderConfig;         // +0x30
    Ptr<VideoSoundSystem>        pSoundSystem;          // +0x38
    Ptr<ReadCallback>            pReadCallback;         // +0x40
    Thread::ThreadPriority       DecodeThreadPriority;  // +0x48
    AS2VideoSupport*             pAS2VSupport;          // +0x50
    AS3VideoSupport*             pAS3VSupport;          // +0x58
};

}}} // namespace Scaleform::GFx::Video

#endif
