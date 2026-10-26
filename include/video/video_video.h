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
#include "../kernel/sf_string.h"
#include "../kernel/sf_threads.h"
#include "../gfx/gfx_state.h"
#include "../sound/sound_renderer.h"

namespace Scaleform {
namespace GFx { namespace Video { class VideoDecoder; class VideoReader; class VideoSoundSystem; class VideoSound; struct SyncObjectTag; } }

// The exe has no vftable for the RefCountBaseNTS layer of VideoDecoder / VideoReader nor for the abstract VideoDecoder itself, VideoSoundSystem, VideoSound
// (the derived constructors store only their final vftable): novtable keeps them out of the object file.
template<>
class __declspec(novtable) RefCountBaseNTS<GFx::Video::VideoDecoder, Stat_Default_Mem> : public RefCountBaseStatImpl<RefCountNTSImpl, Stat_Default_Mem>
{
public:
    enum { StatType = Stat_Default_Mem };
    RefCountBaseNTS() {}
};
template<>
class __declspec(novtable) RefCountBaseNTS<GFx::Video::VideoSoundSystem, Stat_Default_Mem> : public RefCountBaseStatImpl<RefCountNTSImpl, Stat_Default_Mem>
{
public:
    enum { StatType = Stat_Default_Mem };
    RefCountBaseNTS() {}
};
template<>
class __declspec(novtable) RefCountBaseNTS<GFx::Video::VideoSound, Stat_Default_Mem> : public RefCountBaseStatImpl<RefCountNTSImpl, Stat_Default_Mem>
{
public:
    enum { StatType = Stat_Default_Mem };
    RefCountBaseNTS() {}
};
#ifdef MS2_VIDEO_SYNCOBJECT_NOVTABLE
template<>
class __declspec(novtable) RefCountBaseNTS<GFx::Video::SyncObjectTag, Stat_Default_Mem> : public RefCountBaseStatImpl<RefCountNTSImpl, Stat_Default_Mem>
{
public:
    enum { StatType = Stat_Default_Mem };
    RefCountBaseNTS() {}
};
#endif
template<>
class __declspec(novtable) RefCountBaseNTS<GFx::Video::VideoReader, Stat_Default_Mem> : public RefCountBaseStatImpl<RefCountNTSImpl, Stat_Default_Mem>
{
public:
    enum { StatType = Stat_Default_Mem };
    RefCountBaseNTS() {}
};

class Log;
namespace Render { class TextureManager; }

namespace GFx {

class LoadProcess;
class TaskManager;
class MovieImpl;
class CharacterDef;
class InteractiveObject;
class DisplayObjectBase;
class ResourceId;
class MovieDefImpl;
namespace AS3 { class VM; }
namespace AS2 { class GlobalContext; class Object; }
class ASStringContext;
class Sprite;
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

// The AS3 side of the video module: creates the AS3 Video display objects (vftable: dtor, CreateASCharacter at +0x8,
// RegisterASClasses).
class AS3VideoSupport : public RefCountBaseNTS<AS3VideoSupport, Stat_Default_Mem>
{
public:
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl) = 0;
    virtual void               RegisterASClasses(AS3::VM* pvm) = 0;
    // (appended, sfr_video_04) creates the glue object in the global heap (exe 0x140002730).
    static AS3VideoSupport*    CreateInstance();
};

// The AS2 side (vftable 0x1431b4ab0: dtor, CreateASCharacter, RegisterASClasses, AttachAudio).
class AS2VideoSupport : public RefCountBaseNTS<AS2VideoSupport, Stat_Default_Mem>
{
public:
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl) = 0;
    virtual void               RegisterASClasses(AS2::GlobalContext& gc, ASStringContext& sc) = 0;
    // MovieClip.attachAudio(netStream): the stream's sound goes to the clip.
    virtual void               AttachAudio(AS2::Object* pnetStream, Sprite* pchar) = 0;
    // (appended, sfr_video_04) creates the glue object in the global heap (exe 0x1400019f0).
    static AS2VideoSupport*    CreateInstance();
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

class VideoImage;

// One playing movie (implemented by VideoPlayerImpl). Slot order checked against the AS3 VideoProviderNetStream calls.
class VideoPlayer : public NewOverrideBase<Stat_Default_Mem>
{
public:
    virtual ~VideoPlayer() {}

    enum CuePointType { EventCuePoint, NavigationCuePoint };

    struct CuePointParam
    {
        String Name;
        String Value;
    };
    struct CuePoint                                 // 0x38 bytes
    {
        CuePointType         Type;
        String               Name;
        UInt32               Time;
        Array<CuePointParam> Params;
    };
    struct AudioTrackInfo
    {
        int    Index;
        UInt32 SampleRate;
        UInt32 ChannelsNumber;
        UInt32 TotalSamples;
    };
    struct VideoInfo                                // 0x50 bytes
    {
        int                   Width;                // +0x00
        int                   Height;               // +0x04
        UInt32                FrameRate;            // +0x08
        UInt32                AudioDataRate;        // +0x0c
        UInt32                TotalFrames;          // +0x10
        Array<CuePoint>       CuePoints;            // +0x18
        int                   SubtitleChannelsNumber; // +0x30
        int                   MaxSubtitleLen;       // +0x34
        Array<AudioTrackInfo> AudioTracks;          // +0x38
    };

    enum Status
    {
        NotInitialized, Opening, Ready, Starting, Playing, Seeking, Stopping, Finished, Stopped,
        FileNotFound, InternalError
    };

    // Lets the player follow an external clock (the SWF timeline when SetSwfSync is on).
#ifdef MS2_VIDEO_SYNCOBJECT_NOVTABLE
    // sfr_cri_01 only builds the SWF adapter: the exe's constructor there inlines SyncObject and stores only the adapter's
    // vftable (sfr_video_01 builds a bare SyncObject and keeps both base vftables, so this is opt-in per unit).
    class __declspec(novtable) SyncObject : public RefCountBaseNTS<SyncObjectTag, Stat_Default_Mem>
#else
    class SyncObject : public RefCountBaseNTS<SyncObject, Stat_Default_Mem>
#endif
    {
    public:
        virtual void SetStartFrame(unsigned frame)
        {
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(this) + 0x18) = frame;
        }
        virtual void Start() {}
        virtual void Stop() {}
        virtual void Pause(bool sw) { (void)sw; }
        virtual void GetTime(UInt64* count, UInt64* unit)
        {
            *count = 0;
            *unit = 1000;
        }
        virtual ~SyncObject() {}
    };

    struct ReadBufferInfo
    {
        UInt32 BufferSize;
        UInt32 DataSize;
        UInt32 ReloadThreshold;
    };

    enum SoundTrack { MainTrack, SubAudio };

    virtual void        Destroy() { delete this; }                                        // 1
    virtual void        Open(const char* url) = 0;                                        // 2
    virtual Status      GetStatus() = 0;                                                  // 3
    virtual void        GetVideoInfo(VideoInfo* info) = 0;                                // 4
    virtual void        Play() = 0;                                                       // 5
    virtual void        Seek(UInt32 pos) = 0;                                             // 6
    virtual void        SetSubtitleChannel(int channel) = 0;                              // 7
    virtual int         GetSubtitleChannel() = 0;                                         // 8
    virtual UInt32      GetPosition() = 0;                                                // 9
    virtual VideoImage* CreateTexture(Render::TextureManager* ptexman) = 0;               // 10
    virtual void        UpdateTexture(VideoImage* pimage, char* subtitle, int subtitleLength) = 0; // 11
    virtual bool        IsTextureReady() = 0;                                             // 12
    virtual void        Decode() = 0;                                                     // 13
    virtual void        Stop() = 0;                                                       // 14
    virtual void        Pause(bool on) = 0;                                               // 15
    virtual void        SetSyncObject(SyncObject*) = 0;                                   // 16
    virtual void        GetCurrentCuePoints(Array<CuePoint>* cuePoints) = 0;              // 17
    virtual void        SetAudioTrack(int trackIndex) = 0;                                // 18
    virtual void        SetSubAudioTrack(int trackIndex) = 0;                             // 19
    virtual void        ReplaceCenterVoice(int trackIndex) = 0;                           // 20
    virtual void        SetLoopFlag(bool flag) = 0;                                       // 21
    virtual void        SetBufferTime(float time) = 0;                                    // 22
    virtual void        SetNumberOfFramePools(unsigned pools) = 0;                        // 23
    virtual void        SetReloadThresholdTime(float time) = 0;                           // 24
    virtual void        GetReadBufferInfo(ReadBufferInfo* info) = 0;                      // 25
    virtual void        SetDecodeHeaderTimeout(float timeout) = 0;                        // 26
    virtual Sound::SoundChannel* GetSoundChannel(SoundTrack track = MainTrack) = 0;      // 27
    virtual void        SetSoundSpatialInfo(Array<Sound::SoundChannel::Vector> spatinfo[]) = 0; // 28

    // Opens url with a temporary player on its own heap and reads its header (0x14002d020).
    static bool         LoadVideoInfo(const char* url, VideoInfo* pinfo, FileOpenerBase* pfileOpener);
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
class __declspec(novtable) VideoDecoder : public RefCountBaseNTS<VideoDecoder, Stat_Default_Mem>
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
    friend class VideoReader;           // reads the opener and IOEnabled
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
    friend class VideoPlayerImpl;   // Init reads the decoder, reader config and sound system

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
