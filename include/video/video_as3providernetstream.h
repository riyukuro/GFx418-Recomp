// Recovered Scaleform GFx 4.1.18 Video: the media provider interface and its AS3 NetStream implementation.
// Written from the exe (sfr lane); the provider's helpers sit in sfr_cri_01 (0x140025090-0x140026dd0).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// VideoProviderNetStream is 0x108 bytes: VideoProvider base (vfptr, RefCount, pWeakProxy) then the members below.
#ifndef MS2_SF_VIDEO_AS3PROVIDERNETSTREAM_H
#define MS2_SF_VIDEO_AS3PROVIDERNETSTREAM_H

#include "video_video.h"

namespace Scaleform { namespace GFx {

class CharacterHandle;
class Sprite;
class MovieImpl;

namespace AS3 { class ASVM; }

namespace Video {

class VideoCharacter;
class VideoImage;

// What a display object plays from: implemented by the AS2/AS3 NetStream providers.
class VideoProvider : public RefCountBaseWeakSupport<VideoProvider, Stat_Default_Mem>
{
public:
    virtual ~VideoProvider() {}

    virtual VideoImage* GetTexture(int* width, int* height) = 0;   // 1
    virtual void        Advance() = 0;                             // 2
    virtual void        Pause(bool pause) = 0;                     // 3
    virtual void        Close() = 0;                               // 4
    virtual bool        IsActive() = 0;                            // 5
    virtual float       GetFrameTime() = 0;                        // 6
    virtual void            RegisterVideoCharacter(VideoCharacter* pvideo) = 0;  // 7
    virtual VideoCharacter* RemoveFirstVideoCharacter() = 0;                     // 8
};

} // namespace Video

namespace AS3 {

// The AS3 NetStream object as the provider sees it (events go back to ActionScript through it).
class NetStreamInterface : public RefCountBaseNTS<NetStreamInterface, Stat_Default_Mem>
{
public:
    enum Notification
    {
        PlayStart,
        PlayStop,
        SeekNotify,
        PlayStreamNotFound,
        SeekInvalidTime,
        PlayInternalError,
        NoCode = -1
    };

    virtual void DispatchNetStatus(const String& code, const String& level) = 0;     // 1
    virtual void ExecuteOnMataData(Video::VideoPlayer::VideoInfo* pinfo) = 0;       // 2
    virtual void ExecuteOnCuePoint(Video::VideoPlayer::CuePoint* pcuepoint) = 0;    // 3
    virtual void ExecuteOnSubtitle(const String& subtitle) = 0;                     // 4

    static const char* NotificationToString(Notification code);
};

class VideoProviderNetStream : public Video::VideoProvider
{
public:
    VideoProviderNetStream(NetStreamInterface* pnsintf);
    ~VideoProviderNetStream();

    virtual Video::VideoImage* GetTexture(int* width, int* height);
    virtual void  Advance();
    virtual void  Pause(bool pause);
    virtual void  Close();
    virtual bool  IsActive();
    virtual float GetFrameTime() { return FrameTime; }
    virtual void                   RegisterVideoCharacter(Video::VideoCharacter* pvideo);
    virtual Video::VideoCharacter* RemoveFirstVideoCharacter();

    void   OpenUrl(const char* url, ASVM& asvm);
    void   Stop();
    UInt32 GetPosition();
    void   Seek(float pos, MovieImpl* proot);
    void   SetLoopFlag(bool flag);
    void   SetSwfSync(bool flag, Sprite* ptarget);
    void   SetAudioTrack(int track);
    void   SetSubAudioTrack(int track);
    void   ReplaceCenterVoice(int track);
    void   SetSubtitleChannel(int channel);
    int    GetSubtitleChannel();
    void   SetBufferTime(float time);
    void   SetNumberOfFramePools(unsigned pools);
    void   SetReloadThresholdTime(float time);
    void   SetOpenURLTimeout(float timeout);
    void   SetAudioTarget(Sprite* psprite);
    void   SetSoundVolume(int volume, int subVolume = 100);

    void   SendNotification(NetStreamInterface::Notification n, bool error = false);
    void   SendMetaData();
    void   SendCuePoints();
    void   SendSubtitle();

    void   NotifyNetStreamRemoved() { pNetStreamInterface = NULL; }
    Video::VideoPlayer* GetPlayer() { return pVideoPlayer; }
    const Video::VideoPlayer::VideoInfo& GetVideoInfo() const { return VInfo; }

private:
    void   Init();
    void   InitSoundChannel();
    void   NotifyVideoCharacters();
    void   AllocSubtitleBuffers();
    void   ReleaseSubtitleBuffers();

    NetStreamInterface*                      pNetStreamInterface;   // +0x18
    Ptr<CharacterHandle>                     pTarget;               // +0x20
    Ptr<CharacterHandle>                     pAudioTarget;          // +0x28
    Array<WeakPtr<Video::VideoCharacter> >   VideoCharacters;       // +0x30
    Video::VideoPlayer*                      pVideoPlayer;          // +0x48
    Video::VideoPlayer::VideoInfo            VInfo;                 // +0x50
    Ptr<Video::VideoPlayer::SyncObject>      pSyncObj;              // +0xa0
    float                                    FrameTime;             // +0xa8
    Array<Video::VideoPlayer::CuePoint>      CuePoints;             // +0xb0
    char*                                    pSubtitle;             // +0xc8
    char*                                    pSubtitleTmp;          // +0xd0
    Render::TextureManager*                  pTextureManager;       // +0xd8
    Ptr<Video::VideoImage>                   pTextureImage;         // +0xe0
    bool                                     LoopFlag;              // +0xe8
    unsigned                                 PoolsNumber;           // +0xec
    float                                    BufferTime;            // +0xf0
    float                                    ReloadThreshHoldTime;  // +0xf4
    float                                    OpenURLTimeout;        // +0xf8
    float                                    SeekPos;               // +0xfc
    bool                                     FrameIsReady;          // +0x100
    bool                                     StartNotificationSent; // +0x101
    bool                                     StopNotificationSent;  // +0x102
    bool                                     SeekNotificationSent;  // +0x103
    bool                                     NotFoundNotificationSent; // +0x104
};

}}} // namespace Scaleform::GFx::AS3

#endif
