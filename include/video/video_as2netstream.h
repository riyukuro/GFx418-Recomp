// Recovered Scaleform GFx 4.1.18 Video: the AS2 NetStream class (script object, prototype, constructor) and the
// media provider it plays through. Written from the exe (sfr lane); the code sits in sfr_video_01
// (0x140002930-0x14000e470).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// NetStream is 0xd8 bytes (Object 0x68, then the provider, the pause flag and four callbacks); vftables 0x1431b5030
// (GC side) / 0x1431b5080 (ObjectInterface side). VideoProviderNetStream is 0x138 bytes, vftable 0x1431b5620.
#ifndef MS2_SF_VIDEO_AS2NETSTREAM_H
#define MS2_SF_VIDEO_AS2NETSTREAM_H

#include "video_as3providernetstream.h"
#include "../gfx/as2/as2_action.h"
#include "../gfx/as2/as2_objectproto.h"

namespace Scaleform { namespace GFx {

class Sprite;

namespace AS2 {

class VideoProviderNetStream;

class NetStream : public Object
{
    friend class VideoProviderNetStream;

public:
    NetStream(Environment* penv);   // exe 0x14000cc90
    ~NetStream();   // exe 0x140008070

    virtual ObjectType GetObjectType() const { return Object_NetStream; }

    void OpenUrl(const char* url, Environment* penv);
    void Stop();
    void Pause();
    void Pause(bool pause);
    void Seek(Number pos, Environment* penv);   // exe 0x140005720
    void SetBufferTime(Number time);
    void SetNumberOfFramePools(Number pools);
    void SetReloadThresholdTime(Number time);
    void SetOpenURLTimeout(Number timeout);

    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);   // exe 0x14000aab0
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());                    // exe 0x140008250

    VideoProviderNetStream* GetVideoProvider() { return pVideoProvider; }

    // The four callbacks after the Object members (exe 0x140007e40 / 0x140007ea0 / 0x140007f00).
    template<class Functor> void ForEachChild_GC(Collector* prcc) const;

protected:
    void commonInit(Environment* penv);   // exe 0x14000cc10

    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const;   // exe 0x140007fb0
    virtual void Finalize_GC();                                                         // exe 0x1400056d0
    // Lets the provider go: it stops playing and no longer reports back.
    void ReleaseVideoProvider();

private:
    Ptr<VideoProviderNetStream> pVideoProvider;       // +0x68
    bool                        Paused;               // +0x70
    FunctionRef                 OnSubtitleCallback;   // +0x78
    FunctionRef                 OnMetaDataCallback;   // +0x90
    FunctionRef                 OnStatusCallback;     // +0xa8
    FunctionRef                 OnCuePointCallback;   // +0xc0
};

// NetStream.prototype methods.
class NetStreamProto
{
public:
    static void Close(const FnCall& fn);                    // exe 0x1400047a0
    static void Pause(const FnCall& fn);                    // exe 0x140004810
    static void Play(const FnCall& fn);                     // exe 0x14000c9f0
    static void Seek(const FnCall& fn);                     // exe 0x140005780
    static void SetBufferTime(const FnCall& fn);            // exe 0x140004880
    static void SetNumberOfFramePools(const FnCall& fn);    // exe 0x140004920
    static void SetReloadThresholdTime(const FnCall& fn);   // exe 0x1400049c0
    static void SetOpenURLTimeout(const FnCall& fn);        // exe 0x140004a60
    static void SetSoundSpatial(const FnCall& fn);          // exe 0x1400085c0
};

// The NetStream class (constructor function).
class NetStreamCtorFunction : public CFunctionObject
{
public:
    NetStreamCtorFunction(ASStringContext* psc);   // exe 0x14000ce30

    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x14000cd30

    static void GlobalCtor(const FnCall& fn);   // exe 0x14000cd70
};

// What a NetStream plays from: owns the player, its texture and the subtitle buffers, and reports the player's
// state changes back to the script object.
class VideoProviderNetStream : public Video::VideoProvider
{
public:
    VideoProviderNetStream(NetStream* pnetstream);   // exe 0x14000ca90
    ~VideoProviderNetStream();                       // exe 0x14000c370

    virtual Video::VideoImage* GetTexture(int* width, int* height);   // exe 0x140004da0
    virtual void  Advance();                                          // exe 0x14000be60
    virtual void  Pause(bool pause);                                  // exe 0x140003540
    virtual void  Close();                                            // exe 0x140004b50
    virtual bool  IsActive();                                         // exe 0x140003490
    virtual float GetFrameTime();                                     // exe 0x14000c4a0
    virtual void                   RegisterVideoCharacter(Video::VideoCharacter* pvideo);   // exe 0x140009cf0
    virtual Video::VideoCharacter* RemoveFirstVideoCharacter();                             // exe 0x14000af10

    void   OpenUrl(const char* url, Environment* penv);   // exe 0x14000c4b0
    void   Stop();                                        // exe 0x140003520
    void   Seek(float pos, MovieImpl* proot);             // exe 0x140004cf0
    void   SetBufferTime(float time)
    {
        BufferTime = time;
        if (pVideoPlayer)
            pVideoPlayer->SetBufferTime(time);
    }
    void   SetNumberOfFramePools(unsigned pools)
    {
        PoolsNumber = pools;
        if (pVideoPlayer)
            pVideoPlayer->SetNumberOfFramePools(pools);
    }
    void   SetReloadThresholdTime(float time)
    {
        ReloadThreshHoldTime = time;
        if (pVideoPlayer)
            pVideoPlayer->SetReloadThresholdTime(time);
    }
    void   SetOpenURLTimeout(float timeout)
    {
        OpenURLTimeout = timeout;
        if (pVideoPlayer)
            pVideoPlayer->SetDecodeHeaderTimeout(timeout);
    }

    // Moves the video's sound to another clip (exe 0x140005fc0).
    void   SetAudioTarget(Sprite* ptarget);
    // The movie clip's frames pace the video (exe 0x1400064f0).
    void   SetSwfSync(bool flag, Sprite* ptarget);
    void   SetLoopFlag(bool flag)
    {
        LoopFlag = flag;
        if (pVideoPlayer)
            pVideoPlayer->SetLoopFlag(flag);
    }
    void   SetSubtitleChannel(int channel)
    {
        if (pVideoPlayer)
            pVideoPlayer->SetSubtitleChannel(channel);
    }
    void   SetAudioTrack(int track)
    {
        if (pVideoPlayer)
            pVideoPlayer->SetAudioTrack(track);
    }
    void   SetSubAudioTrack(int track)
    {
        if (pVideoPlayer)
            pVideoPlayer->SetSubAudioTrack(track);
    }
    void   ReplaceCenterVoice(int track)
    {
        if (pVideoPlayer)
            pVideoPlayer->ReplaceCenterVoice(track);
    }
    void   NotifyNetStreamRemoved() { pNetStream = NULL; }
    // Sound position (0), orientation (1) and velocity (2) for the player's 3D sound.
    void   SetSpatialInfo(int i, const Array<Sound::SoundChannel::Vector>& info) { SpatialInfo[i] = info; }
    void   ApplySpatialInfo()
    {
        if (pVideoPlayer)
            pVideoPlayer->SetSoundSpatialInfo(SpatialInfo);
    }
    Video::VideoPlayer* GetPlayer() { return pVideoPlayer; }
    const Video::VideoPlayer::VideoInfo& GetVideoInfo() const { return VInfo; }
    UInt32 GetPosition()        { return pVideoPlayer ? pVideoPlayer->GetPosition() : 0; }
    int    GetSubtitleChannel() { return pVideoPlayer ? pVideoPlayer->GetSubtitleChannel() : -1; }

private:
    void   InitSoundChannel();   // exe 0x140004bf0
    void   NotifyVideoCharacters();                                          // exe 0x140006580
    // The script callbacks of the NetStream, called on the target clip's environment.
    void   SendNotification(const char* note, bool error);                   // exe 0x140008860 (onStatus)
    void   SendMetaInformation();                                            // exe 0x140009140 (onMetaData)
    void   SendCuePoints(const Array<Video::VideoPlayer::CuePoint>& cuePoints); // exe 0x140009850 (onCuePoint)
    void   SendSubtitleInformation();                                        // exe 0x140009ad0 (onSubtitle)

    NetStream*                                      pNetStream;                 // +0x18
    Ptr<CharacterHandle>                            pTarget;                    // +0x20
    Ptr<CharacterHandle>                            pAudioTarget;               // +0x28
    Array<WeakPtr<Video::VideoCharacter> >          VideoCharacters;            // +0x30
    Video::VideoPlayer*                             pVideoPlayer;               // +0x48
    Video::VideoPlayer::VideoInfo                   VInfo;                      // +0x50
    Ptr<Video::VideoPlayer::SyncObject>             pSyncObj;                   // +0xa0
    float                                           FrameTime;                  // +0xa8
    Render::TextureManager*                         pTextureManager;            // +0xb0
    Ptr<Video::VideoImage>                          pTextureImage;              // +0xb8
    bool                                            LoopFlag;                   // +0xc0
    unsigned                                        PoolsNumber;                // +0xc4
    float                                           BufferTime;                 // +0xc8
    float                                           ReloadThreshHoldTime;       // +0xcc
    float                                           OpenURLTimeout;             // +0xd0
    float                                           SeekPos;                    // +0xd4
    bool                                            FrameIsReady;               // +0xd8
    bool                                            StartNotificationSent;      // +0xd9
    bool                                            StopNotificationSent;       // +0xda
    bool                                            SeekNotificationSent;       // +0xdb
    bool                                            NotFoundNotificationSent;   // +0xdc
    char*                                           pSubtitleMsg;               // +0xe0
    char*                                           pSubtitleMsgTmp;            // +0xe8
    Array<Sound::SoundChannel::Vector>              SpatialInfo[3];             // +0xf0
};

inline void NetStream::OpenUrl(const char* url, Environment* penv)
{
    Paused = false;
    pVideoProvider->OpenUrl(url, penv);
}

inline void NetStream::Stop()                              { pVideoProvider->Stop(); }
inline void NetStream::Pause()                             { Paused = !Paused; pVideoProvider->Pause(Paused); }
inline void NetStream::Pause(bool pause)                   { Paused = pause; pVideoProvider->Pause(Paused); }
inline void NetStream::SetBufferTime(Number time)          { pVideoProvider->SetBufferTime((float)time); }
inline void NetStream::SetNumberOfFramePools(Number pools) { pVideoProvider->SetNumberOfFramePools((unsigned)pools); }
inline void NetStream::SetReloadThresholdTime(Number time) { pVideoProvider->SetReloadThresholdTime((float)time); }
inline void NetStream::SetOpenURLTimeout(Number timeout)   { pVideoProvider->SetOpenURLTimeout((float)timeout); }

}}} // namespace Scaleform::GFx::AS2

#endif
