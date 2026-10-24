// Recovered Scaleform GFx 4.1.18 Video: the CRI-backed player (VideoPlayerImpl), its system timer and the
// same-thread decoder. Written from the exe (sfr lane); the methods sit in sfr_cri_01/02 (0x140028480-0x14002d000).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// VideoPlayerImpl vftable 0x1431b9260 (29 slots, VideoPlayer order), VideoDecoderSmp vftable 0x1431b9170.
// No out-of-line virtual is declared here so that including units do not emit the vftables.
#ifndef MS2_SF_VIDEO_VIDEOPLAYERIMPL_H
#define MS2_SF_VIDEO_VIDEOPLAYERIMPL_H

#include "video_video.h"
#include "../cri/cri_movie.h"
#include "../kernel/sf_lock.h"
#include "../kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_listalloc.h"

namespace Scaleform { namespace GFx { namespace Video {

// The CRI system timer the player syncs to (0x20 bytes, vftables 0x1431b8fc8 / 0x1431b8fa0 for the CRI interface at
// +0x10); follows the SWF clock or the system clock through pSyncObj.
class CriMvSystemTimer : public RefCountBaseNTS<CriMvSystemTimer, Stat_Default_Mem>, public CriMvSystemTimerInterface
{
public:
    CriMvSystemTimer(VideoPlayer::SyncObject* psync);                                 // 0x140029e40
    void                     SetSyncObject(VideoPlayer::SyncObject* psync);            // 0x1400291c0
    VideoPlayer::SyncObject* GetSyncObject() const { return pSyncObj; }

    Ptr<VideoPlayer::SyncObject> pSyncObj;  // +0x18
};

// The player's sound output over a VideoSound (CriMvSound, 0x50 bytes, vftable 0x1431b9028; the CRI sound interface
// sits at +0x10). Only slot 1 is used by the player.
class VideoPlayerSound : public RefCountBaseNTS<VideoPlayerSound, Stat_Default_Mem>
{
public:
    virtual Sound::SoundChannel* GetSoundChannel() = 0;   // 1
};

// The file reader a player streams from (0x50 bytes, vftables 0x1431b93b0 / 0x1431b9360 for the CRI file reader
// interface at +0x10). Opens, reads and seeks synchronously through the reader config's file opener.
class VideoReader : public RefCountBaseNTS<VideoReader, Stat_Default_Mem>, public CriMvFileReaderInterface
{
public:
    VideoReader(VideoReaderConfig* pconfig);                                         // 0x14002d970
    virtual ~VideoReader();

    virtual void        Open(CriChar8* fname);
    virtual void        Close(void);
    virtual void        Read(CriUint8* buffer, CriSint64 req_size);
    virtual AsyncStatus GetOpenStatus(void)  { return OpenStatus; }
    virtual AsyncStatus GetCloseStatus(void) { return CloseStatus; }
    virtual AsyncStatus GetReadStatus(void)  { return ReadStatus; }
    virtual CriSint64   GetReadSize(void)    { return ReadSize; }
    virtual CriSint64   Seek(CriSint64 size, SeekOrigin offset);
    virtual CriSint64   GetFileSize(void)    { return FileSize; }

    void                OpenFile(const char* fname);
    void                CloseFile();
    void                ReadFile(UByte* buffer, SInt64 size);

    Ptr<VideoReaderConfig>   pReaderConfig;         // +0x18
    RefCountImpl*            pFile;                 // +0x20 Ptr<File>
    int                      ReadSize;              // +0x28
    AsyncStatus              OpenStatus;            // +0x2c
    AsyncStatus              CloseStatus;           // +0x30
    AsyncStatus              ReadStatus;            // +0x34
    SInt64                   Position;              // +0x38 where the next read starts
    SInt64                   FilePos;               // +0x40 where the file is
    SInt64                   FileSize;              // +0x48
};

class VideoPlayerImpl : public VideoPlayer
{
public:
    VideoPlayerImpl(MemoryHeap* pheap);
    bool Init(Video* pvideo, TaskManager* ptaskManager, FileOpenerBase* pfileOpener, Log* plog);

    virtual void        Open(const char* url);
    virtual Status      GetStatus();
    virtual void        GetVideoInfo(VideoInfo* info);
    virtual void        Play();
    virtual void        Seek(UInt32 pos);
    virtual void        SetSubtitleChannel(int channel);
    virtual int         GetSubtitleChannel();
    virtual UInt32      GetPosition();
    virtual VideoImage* CreateTexture(Render::TextureManager* ptexman);
    virtual void        UpdateTexture(VideoImage* pimage, char* subtitle, int subtitleLength);
    virtual bool        IsTextureReady();
    virtual void        Decode();
    virtual void        Stop();
    virtual void        Pause(bool on);
    virtual void        SetSyncObject(SyncObject*);
    virtual void        GetCurrentCuePoints(Array<CuePoint>* cuePoints);
    virtual void        SetAudioTrack(int trackIndex);
    virtual void        SetSubAudioTrack(int trackIndex);
    virtual void        ReplaceCenterVoice(int trackIndex);
    virtual void        SetLoopFlag(bool flag);
    virtual void        SetBufferTime(float time);
    virtual void        SetNumberOfFramePools(unsigned pools);
    virtual void        SetReloadThresholdTime(float time);
    virtual void        GetReadBufferInfo(ReadBufferInfo* info);
    virtual void        SetDecodeHeaderTimeout(float timeout);
    virtual Sound::SoundChannel* GetSoundChannel(SoundTrack track);
    virtual void        SetSoundSpatialInfo(Array<Sound::SoundChannel::Vector> spatinfo[]);

    virtual ~VideoPlayerImpl();

    void                StopAndWait();                                            // 0x1400293f0
    void                DecodeHeader();                                           // 0x140029510

    static void         CuePointCallback(CriMvEasyPlayer* mveasy, CriMvEventPoint* eventinfo, void* usrobj);

    CriMvEasyPlayer*         pPlayer;               // +0x008
    volatile Status          Stat;                  // +0x010
    CriMvSystemTimer*        pTimer;                // +0x018 (owned reference)
    VideoReader*             pReader;               // +0x020 (owned reference)
    VideoPlayerSound*        pSound;                // +0x028
    VideoPlayerSound*        pSubSound;             // +0x030
    CriMvStreamingParameters StmPrm;                // +0x038
    struct
    {
        CriUint8*            imageptr;
        CriSint32            frame_id;
        UByte                Rest[0xa4];
    }                        FrameInfo;             // +0x2c0 (the player's 0xb0-byte frame info copy)
    Array<CuePoint>          CurrentCuePoints;      // +0x370 collected by the cue point callback
    UInt32                   Width;                 // +0x388
    UInt32                   Height;                // +0x38c
    bool                     HasAlpha;              // +0x390
    UInt32                   CurrentFrame;          // +0x394
    UInt32                   StartFrame;            // +0x398
    Status                   StatusAfterStop;       // +0x39c
    CriBool                  PauseFlag;             // +0x3a0
    CriBool                  LoopFlag;              // +0x3a4
    bool                     UpdateTextureCalled;   // +0x3a8
    bool                     FrameOnTime;           // +0x3a9
    bool                     PauseLocked;           // +0x3aa
    bool                     PausePending;          // +0x3ab
    int                      SubtitleChannel;       // +0x3ac
    UInt64                   OpenTicks;             // +0x3b0
    UInt64                   DecodeHeaderTimeout;   // +0x3b8
    bool                     UseAudioTimer;         // +0x3c0 the sound output is the master timer
    VideoDecoder*            pDecoder;              // +0x3c8 (owned reference)
    MemoryHeap*              pHeap;                 // +0x3d0
    void*                    pCriHeap;              // +0x3d8 CriHeap over pHeap
    Log*                     pLog;                  // +0x3e0 (owned, thread-safe reference)
};

// Decodes the players on the calling thread (0x48 bytes).
class VideoDecoderSmp : public VideoDecoder
{
public:
    VideoDecoderSmp() : Paused(false) {}

    virtual void StartDecoding(VideoPlayer* pplayer);               // 1
    virtual void StopDecoding(VideoPlayer* pplayer);                // 2
    virtual bool IsDecodingStopped(VideoPlayer* pplayer);           // 3
    virtual bool ExecuteDecode(VideoPlayer* pplayer);               // 4
    virtual void GetReadBufferInfo(void* info);                     // 5
    virtual bool IsIORequired() const;                              // 6
    virtual void PauseDecoding(bool pause);                         // 7

    bool                        Paused;         // +0x10
    Array<VideoPlayerImpl*>     Players;        // +0x18
    Array<VideoPlayerImpl*>     PausedPlayers;  // +0x30 players kept paused by PauseDecoding(true)
};

// Decodes the players on its own thread, started on demand (0x88 bytes).
class VideoDecoderThrd : public VideoDecoderSmp
{
public:
    VideoDecoderThrd(MemoryHeap* pheap, Thread::ThreadPriority priority);
    ~VideoDecoderThrd();

    virtual void StartDecoding(VideoPlayer* pplayer);
    virtual void StopDecoding(VideoPlayer* pplayer);
    virtual bool IsDecodingStopped(VideoPlayer* pplayer);
    virtual bool ExecuteDecode(VideoPlayer*) { return false; }

    static int   DecodeFunc(Thread* pthread, void* obj);

    MemoryHeap*                 pHeap;          // +0x48
    RefCountImpl*               pDecodeThread;  // +0x50 Ptr<Thread>
    Thread::ThreadPriority      ThreadPriority; // +0x58
    Lock                        DecodeLock;     // +0x60
};

// Creates the readers in the calling thread (0x40 bytes, vftable 0x1431b91d8; Register allocates 0x40).
class VideoReaderConfigSmp : public VideoReaderConfig
{
public:
    VideoReaderConfigSmp(MemoryHeap* pheap, FileOpenerBase* pfileOpener);   // 0x14002b150
    virtual VideoReader* CreateReader();
};
static_assert(sizeof(VideoReaderConfigSmp) == 0x40, "VideoReaderConfigSmp size"); // (sfr24) its allocation is 0x40

// Creates the readers serviced by the reader thread (0x110 bytes, vftable 0x1431b9430).
class VideoReaderConfigThrd : public VideoReaderConfig
{
public:
    VideoReaderConfigThrd(MemoryHeap* pheap, FileOpenerBase* pfileOpener);  // 0x14002e450
    virtual VideoReader* CreateReader();

    // (appended, sfr24) the reader thread's state, offsets from the ctor 0x14002e450. Layout only: the methods in
    // sfr_cri_02 reach these through raw offsets.
    enum CmdId
    {
        OpenCmd,
        ReadCmd,
        CloseCmd,
        TermCmd
    };
    // A queued request for the reader thread (0x38 bytes).
    struct Cmd : public ListNode<Cmd>
    {
        CmdId               id;       // +0x10
        VideoReader*        preader;  // +0x18
        char*               fname;    // +0x20
        UByte*              buffer;   // +0x28
        SInt64              req_size; // +0x30
    };

    ListAllocPOD<Cmd, 127, Stat_Video_Mem> CmdsHolder;    // +0x40
    List<Cmd>                              CmdList;       // +0x68
    Mutex                                  CmdListLock;   // +0x78
    Scaleform::Event                       Event;         // +0xa0
    RefCountImpl*                          pThread;       // +0xf8 Ptr<Thread>, started by CreateReader
    WaitCondition                          IOFinished;    // +0x100
    ReadCallback*                          pReadCallback; // +0x108 Ptr<ReadCallback>
};
static_assert(sizeof(VideoReaderConfigThrd::Cmd) == 0x38, "VideoReaderConfigThrd::Cmd size");
static_assert(sizeof(VideoReaderConfigThrd) == 0x110, "VideoReaderConfigThrd size");

}}} // namespace Scaleform::GFx::Video

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::Video::VideoDecoderThrd) == 0x88, "VideoDecoderThrd size");
static_assert(sizeof(Scaleform::GFx::Video::VideoPlayerImpl) == 0x3e8, "VideoPlayerImpl size");

#endif
