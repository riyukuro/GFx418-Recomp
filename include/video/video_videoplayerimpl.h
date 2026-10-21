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

namespace Scaleform { namespace GFx { namespace Video {

// The CRI system timer the player syncs to; follows the SWF clock through pSyncObj when one is set.
class CriMvSystemTimer : public CriMvSystemTimerInterface
{
public:
    void                     SetSyncObject(VideoPlayer::SyncObject* psync);            // 0x1400291c0
    VideoPlayer::SyncObject* GetSyncObject() const { return pSyncObj; }

    UInt64                   StartCount;    // +0x08
    UInt64                   PauseCount;    // +0x10
    Ptr<VideoPlayer::SyncObject> pSyncObj;  // +0x18
};

// The player's sound output (VideoSound wrapper); only slot 1 is used by the player.
class VideoPlayerSound
{
public:
    virtual ~VideoPlayerSound() {}
    virtual Sound::SoundChannel* GetSoundChannel() = 0;   // 1
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

    void                StopAndWait();                                            // 0x1400293f0
    void                DecodeHeader();                                           // 0x140029510

    CriMvEasyPlayer*         pPlayer;               // +0x008
    volatile Status          Stat;                  // +0x010
    CriMvSystemTimer*        pTimer;                // +0x018
    void*                    pUnk20;                // +0x020
    VideoPlayerSound*        pSound;                // +0x028
    VideoPlayerSound*        pSubSound;             // +0x030
    CriMvStreamingParameters StmPrm;                // +0x038
    CriMvFrameInfo           FrameInfo;             // +0x2c0
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
    void*                    pUnk3c0;               // +0x3c0
    VideoDecoder*            pDecoder;              // +0x3c8
    void*                    pUnk3d0[2];            // +0x3d0
    Log*                     pLog;                  // +0x3e0
};

// Decodes the players on the calling thread.
class VideoDecoderSmp : public VideoDecoder
{
public:
    virtual void StopDecoding(VideoPlayer* pplayer);                // 2
    virtual bool IsDecodingStopped(VideoPlayer* pplayer);           // 3
    virtual bool IsIORequired() const;                              // 6

    void*                       pUnk10;     // +0x10
    ArrayLH<VideoPlayerImpl*>   Players;    // +0x18
};

}}} // namespace Scaleform::GFx::Video

#endif
