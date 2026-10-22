// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Video, the AS2 side: the video sound
// stream helpers, then NetStream (script object, prototype methods, constructor) with its media provider, and the AS2
// Video object. Our own source, written from the exe; the leaked SDK copies were only used to name things.
// The Video add-on lib was prebuilt with VS2012 (Rich 0xce build 65501), so with our toolset its code is functional.
// MS2-UNIT: sfr_video_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140002930-0x14000e470 .text$mn
#include "../include/video/video_as2netstream.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/gfx_loaderimpl.h"

namespace Scaleform { namespace GFx { namespace Video {

// Only the provider back-pointer is touched here (+0x40); the image classes come with the render units.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte          Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;   // +0x40
};

// The display object a provider's frames are drawn into; only its weak-pointer base is needed here.
class VideoCharacter : public RefCountBaseWeakSupport<VideoCharacter, Stat_Default_Mem>
{
};

}}} // namespace Scaleform::GFx::Video

// MovieImpl member that registers a provider for advancing (unnamed in the exe's symbols).
void FUN_14256c520(Scaleform::GFx::MovieImpl* proot, Scaleform::GFx::Video::VideoProvider* pprovider);
// Wakes a video display object up when its provider has a first frame (sfr_video_02).
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo);
// Points a video display object at a provider, or at none (sfr_video_02).
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* pvideo, Scaleform::GFx::Video::VideoProvider* pprovider);

namespace Scaleform { namespace GFx { namespace AS2 {

using namespace Video;

// ==== VideoProviderNetStream =========================================================================================

// The sprite whose sound settings a provider's audio follows: the audio target itself, or its parent when the target
// is not a sprite.
static inline Sprite* GetAudioTargetSprite(CharacterHandle* ph)
{
    DisplayObject* pch = ph->pCharacter;
    if (!pch)
        return NULL;
    if (pch->IsSprite())
        return (Sprite*)pch;
    DisplayObject* pparent = (DisplayObject*)pch->pParent;
    if (pparent && pparent->IsSprite())
        return (Sprite*)pparent;
    return NULL;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000ca90
VideoProviderNetStream::VideoProviderNetStream(NetStream* pnetstream)
    : pNetStream(pnetstream)
{
    pVideoPlayer = NULL;
    memset(&VInfo, 0, sizeof(VInfo));
    FrameTime                = 1.0f / 12;
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
    pSubtitleMsgTmp          = NULL;
    pSubtitleMsg             = NULL;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000c370
VideoProviderNetStream::~VideoProviderNetStream()
{
    Close();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140003490
bool VideoProviderNetStream::IsActive()
{
    if (!pVideoPlayer)
        return false;
    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    return status == VideoPlayer::Opening || status == VideoPlayer::Ready || status == VideoPlayer::Starting ||
           status == VideoPlayer::Playing || status == VideoPlayer::Seeking || status == VideoPlayer::Stopping;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls
// @0x140003520
void VideoProviderNetStream::Stop()
{
    if (pVideoPlayer)
        pVideoPlayer->Stop();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls
// @0x140003540
void VideoProviderNetStream::Pause(bool pause)
{
    if (pVideoPlayer)
        pVideoPlayer->Pause(pause);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004b50
void VideoProviderNetStream::Close()
{
    if (pTextureImage)
        pTextureImage->pVideoProvider = NULL;
    pTextureImage = NULL;
    if (pVideoPlayer)
        pVideoPlayer->Destroy();
    pVideoPlayer = NULL;
    if (pSubtitleMsgTmp)
    {
        SF_FREE(pSubtitleMsgTmp);
        pSubtitleMsgTmp = NULL;
    }
    if (pSubtitleMsg)
    {
        SF_FREE(pSubtitleMsg);
        pSubtitleMsg = NULL;
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004bf0
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

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004cf0
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

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005fc0
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

// The clock of a swfSync video: the target clip's frames played since the video started, at the movie's frame rate.
class SwfVideoSyncObject : public VideoPlayer::SyncObject
{
public:
    SF_NOINLINE SwfVideoSyncObject(Sprite* ptarget);
    ~SwfVideoSyncObject() {}

    virtual void SetStartFrame(unsigned frame) { StartFrame = frame; }
    virtual void Start() {}
    virtual void Stop() {}
    virtual void Pause(bool) {}
    virtual void GetTime(UInt64* count, UInt64* unit);

private:
    WeakPtr<Sprite> pTarget;      // +0x10
    unsigned        StartFrame;   // +0x18
    float           FrameTime;    // +0x1c
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140006120
SwfVideoSyncObject::SwfVideoSyncObject(Sprite* ptarget)
    : pTarget(ptarget), StartFrame(ptarget->GetCurrentFrame()), FrameTime(ptarget->GetMovieImpl()->FrameTime)
{
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400063d0
void SwfVideoSyncObject::GetTime(UInt64* count, UInt64* unit)
{
    Ptr<Sprite> ptarget = pTarget;
    if (ptarget)
    {
        unsigned frame = ptarget->GetCurrentFrame();
        if (frame > StartFrame)
        {
            *unit  = 1000000;
            *count = (UInt64)((float)(frame - StartFrame) * FrameTime * (float)*unit);
            return;
        }
    }
    *count = 0;
    *unit  = 1000;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400064f0
void VideoProviderNetStream::SetSwfSync(bool flag, Sprite* ptarget)
{
    if (flag)
        pSyncObj = *SF_NEW SwfVideoSyncObject(ptarget);
    else
        pSyncObj = NULL;
    if (pVideoPlayer)
        pVideoPlayer->SetSyncObject(pSyncObj);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): member reloaded after the test
// @0x140004da0
VideoImage* VideoProviderNetStream::GetTexture(int* width, int* height)
{
    if (!pVideoPlayer || !pTextureImage)
        return NULL;
    *width  = VInfo.Width;
    *height = VInfo.Height;
    return pTextureImage;
}

// The image state; only the texture manager it creates textures with is read here.
class ImageCreator : public State
{
public:
    Render::TextureManager* GetTextureManager() const { return pTexManager; }

protected:
    Render::TextureManager* pTexManager;   // +0x18
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling; the movie heap
// read directly where the exe calls the virtual Movie::GetHeap, the audio target taken from _level0 where the exe
// asks the AS2 root for the root movie (the same object)
// @0x14000c4b0
void VideoProviderNetStream::OpenUrl(const char* url, Environment* penv)
{
    MovieImpl* proot = penv->GetMovieImpl();
    Ptr<LoadStates> pls = *SF_NEW LoadStates(proot->pMainMovieDef->pLoaderImpl, proot->pStateBag);

    String level0Path;
    penv->GetAS2Root()->GetLevel0Path(&level0Path);
    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, String(url), level0Path);
    String fileName;
    pls->BuildURL(&fileName, loc);

    FrameTime = 1.0f / 12.0f;
    SeekPos   = 0.0f;
    VInfo.CuePoints.Clear();
    VInfo.AudioTracks.Clear();
    pTextureImage = NULL;
    FrameIsReady  = false;
    if (!pVideoPlayer)
    {
        StateBag* pstates = proot->GetStateBag();
        Ptr<GFx::Video::VideoBase> pvideo = *(GFx::Video::VideoBase*)pstates->GetStateAddRef(State::State_Video);
        if (pvideo)
        {
            pTextureManager = pvideo->GetTextureManager();
            if (!pTextureManager)
            {
                Ptr<ImageCreator> pimgCreator = *(ImageCreator*)pstates->GetStateAddRef(State::State_ImageCreator);
                pTextureManager = pimgCreator->GetTextureManager();
            }
            Ptr<Log>            plog        = pstates->GetLog();
            Ptr<FileOpenerBase> pfileOpener = *(FileOpenerBase*)pstates->GetStateAddRef(State::State_FileOpener);
            Ptr<TaskManager>    ptaskMgr    = *(TaskManager*)pstates->GetStateAddRef(State::State_TaskManager);
            pVideoPlayer = pvideo->CreateVideoPlayer(proot->GetMovieHeap(), ptaskMgr, pfileOpener, plog);
        }
        if (pVideoPlayer)
        {
            pVideoPlayer->SetSyncObject(pSyncObj);
            pVideoPlayer->SetBufferTime(BufferTime);
            pVideoPlayer->SetNumberOfFramePools(PoolsNumber);
            pVideoPlayer->SetReloadThresholdTime(ReloadThreshHoldTime);
            pVideoPlayer->SetDecodeHeaderTimeout(OpenURLTimeout);
            pVideoPlayer->SetSoundSpatialInfo(SpatialInfo);
        }
    }
    if (pVideoPlayer)
    {
        pVideoPlayer->Open(fileName.ToCStr());
        pTarget = penv->GetTarget()->GetCharacterHandle();
        FUN_14256c520(proot, this);
        pVideoPlayer->SetLoopFlag(LoopFlag);
        StartNotificationSent    = false;
        NotFoundNotificationSent = false;
        SeekNotificationSent     = true;
        if (pSubtitleMsgTmp)
        {
            SF_FREE(pSubtitleMsgTmp);
            pSubtitleMsgTmp = NULL;
        }
        if (pSubtitleMsg)
        {
            SF_FREE(pSubtitleMsg);
            pSubtitleMsg = NULL;
        }
        if (!pAudioTarget)
            pAudioTarget = ((DisplayObject*)proot->pMainMovie)->GetCharacterHandle();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501)
// @0x14000c4a0
float VideoProviderNetStream::GetFrameTime()
{
    return FrameTime;
}

// ==== NetStream ======================================================================================================

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cc10
void NetStream::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_NetStream));
    pVideoProvider = *SF_HEAP_NEW(penv->GetHeap()) VideoProviderNetStream(this);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cc90
NetStream::NetStream(Environment* penv)
    : Object(penv), Paused(false)
{
    commonInit(penv);
}

inline void NetStream::ReleaseVideoProvider()
{
    if (pVideoProvider)
    {
        pVideoProvider->NotifyNetStreamRemoved();
        if (pVideoProvider->GetPlayer())
            pVideoProvider->GetPlayer()->Stop();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008070
NetStream::~NetStream()
{
    ReleaseVideoProvider();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400056d0
void NetStream::Finalize_GC()
{
    ReleaseVideoProvider();
    pVideoProvider.~Ptr<VideoProviderNetStream>();
    Object::Finalize_GC();
}

// The exe keeps the three instantiations out of line (pinned at the end of the file).
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
template<class Functor>
SF_NOINLINE void NetStream::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    OnSubtitleCallback.template ForEachChild_GC<Functor>(prcc);
    OnMetaDataCallback.template ForEachChild_GC<Functor>(prcc);
    OnStatusCallback.template ForEachChild_GC<Functor>(prcc);
    OnCuePointCallback.template ForEachChild_GC<Functor>(prcc);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007fb0
void NetStream::ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const
{
    ASRefCountBaseType::CallForEachChild<NetStream>(prcc, operation);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008250
bool NetStream::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (name == "onMetaData")
    {
        OnMetaDataCallback = val.ToFunction_Call(penv);
        return true;
    }
    else if (name == "onStatus")
    {
        OnStatusCallback = val.ToFunction_Call(penv);
        return true;
    }
    else if (name == "onCuePoint")
    {
        OnCuePointCallback = val.ToFunction_Call(penv);
        return true;
    }
    if (penv->CheckExtensions())
    {
        if (name == "onSubtitle")
        {
            OnSubtitleCallback = val.ToFunction_Call(penv);
            return true;
        }
        else if (name == "subtitleTrack")
        {
            if (!OnSubtitleCallback.IsNull())
                pVideoProvider->SetSubtitleChannel((int)val.ToNumber(penv) - 1);
            return true;
        }
        else if (name == "audioTrack")
        {
            pVideoProvider->SetAudioTrack((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "subAudioTrack")
        {
            pVideoProvider->SetSubAudioTrack((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "voiceTrack")
        {
            pVideoProvider->ReplaceCenterVoice((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "loop")
        {
            pVideoProvider->SetLoopFlag(val.ToBool(penv));
            return true;
        }
        else if (name == "swfSync")
        {
            AvmCharacter* pavm = penv->GetAvmTarget();
            if (pavm->GetDispObj()->IsSprite())
            {
                Sprite* psprite = (Sprite*)static_cast<const ObjectInterface*>(pavm)->ToSprite();
                pVideoProvider->SetSwfSync(val.ToBool(penv), psprite);
            }
        }
    }
    return Object::SetMember(penv, name, val, flags);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000aab0
bool NetStream::GetMember(Environment* penv, const ASString& name, Value* val)
{
    if (penv->CheckExtensions())
    {
        if (name == "setReloadThresholdTime")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetReloadThresholdTime);
            return true;
        }
        else if (name == "setNumberOfFramePools")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetNumberOfFramePools);
            return true;
        }
        else if (name == "setOpenTimeout")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetOpenURLTimeout);
            return true;
        }
        else if (name == "setSoundSpatial")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetSoundSpatial);
            return true;
        }
        else if (name == "onSubtitle")
        {
            *val = Value(OnSubtitleCallback);
            return true;
        }
        else if (name == "subtitleTrack")
        {
            int channel = pVideoProvider->GetSubtitleChannel();
            if (channel < 0)
                channel = -1;
            *val = Value(channel + 1);
            return true;
        }
        else if (name == "currentFrame")
        {
            *val = Value((Number)(float)(pVideoProvider->GetPosition() + 1));
            return true;
        }
    }
    if (name == "time")
    {
        UInt32 pos       = pVideoProvider->GetPosition();
        UInt32 frameRate = pVideoProvider->GetVideoInfo().FrameRate;
        if (frameRate)
            *val = Value((Number)((float)pos / ((float)frameRate / 1000.0f)));
        else
            *val = Value((Number)0);
        return true;
    }
    else if (name == "onMetaData")
    {
        *val = Value(OnMetaDataCallback);
        return true;
    }
    else if (name == "onStatus")
    {
        *val = Value(OnStatusCallback);
        return true;
    }
    else if (name == "onCuePoint")
    {
        *val = Value(OnCuePointCallback);
        return true;
    }
    else if (name == "currentFps")
    {
        *val = Value((Number)((float)pVideoProvider->GetVideoInfo().FrameRate / 1000.0f));
        return true;
    }
    return Object::GetMember(penv, name, val);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005720
void NetStream::Seek(Number pos, Environment* penv)
{
    pVideoProvider->Seek((float)pos, penv->GetMovieImpl());
}

// ---- NetStream.prototype

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400047a0
void NetStreamProto::Close(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    pnetstream->Stop();
    // close(true) also drops the player
    if (fn.NArgs > 0 && fn.Arg(0).ToBool(fn.Env))
        pnetstream->GetVideoProvider()->Close();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004810
void NetStreamProto::Pause(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    if (fn.NArgs > 0)
        pnetstream->Pause(fn.Arg(0).ToBool(fn.Env));
    else
        pnetstream->Pause();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004880
void NetStreamProto::SetBufferTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setBufferTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetBufferTime(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004920
void NetStreamProto::SetNumberOfFramePools(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setNumberOfFramePools requires one argument (pools)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetNumberOfFramePools(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400049c0
void NetStreamProto::SetReloadThresholdTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setReloadThresholdTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetReloadThresholdTime(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004a60
void NetStreamProto::SetOpenURLTimeout(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setOpenTimeout requires one argument (timeout)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetOpenURLTimeout(fn.Arg(0).ToNumber(fn.Env));
}

// Reads an array of numbers as (x, y, z) triples.
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007080
static SF_NOINLINE void ReadVectorArray(Environment* penv, const Value& val, Array<Sound::SoundChannel::Vector>& vecs)
{
    if (!val.IsObject() || val.ToObject(penv)->GetObjectType() != Object::Object_Array)
        return;
    ArrayObject* parr = static_cast<ArrayObject*>(val.ToObject(penv));
    for (int i = 0, n = parr->GetSize(); i < n; i += 3)
    {
        Sound::SoundChannel::Vector v;
        v.X = (float)parr->GetElementPtr(i)->ToNumber(penv);
        v.Y = (float)parr->GetElementPtr(i + 1)->ToNumber(penv);
        v.Z = (float)parr->GetElementPtr(i + 2)->ToNumber(penv);
        vecs.PushBack(v);
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400085c0
void NetStreamProto::SetSoundSpatial(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.SetSoundSpatial requires at least one argument (position)\n");
        return;
    }
    Environment* penv = fn.Env;
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;

    Array<Sound::SoundChannel::Vector> position;
    ReadVectorArray(penv, fn.Arg(0), position);
    pnetstream->GetVideoProvider()->SetSpatialInfo(0, position);
    if (fn.NArgs > 1)
    {
        Array<Sound::SoundChannel::Vector> orientation;
        ReadVectorArray(penv, fn.Arg(1), orientation);
        pnetstream->GetVideoProvider()->SetSpatialInfo(1, orientation);
    }
    if (fn.NArgs > 2)
    {
        Array<Sound::SoundChannel::Vector> velocity;
        ReadVectorArray(penv, fn.Arg(2), velocity);
        pnetstream->GetVideoProvider()->SetSpatialInfo(2, velocity);
    }
    pnetstream->GetVideoProvider()->ApplySpatialInfo();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005780
void NetStreamProto::Seek(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.seek requires one argument (offset)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->Seek(fn.Arg(0).ToNumber(fn.Env), fn.Env);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000c9f0
void NetStreamProto::Play(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.Play requires one argument (file name)\n");
        return;
    }
    ASString url = fn.Arg(0).ToString(fn.Env);
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (pnetstream)
        pnetstream->OpenUrl(url.ToCStr(), fn.Env);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009cf0
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

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000af10
VideoCharacter* VideoProviderNetStream::RemoveFirstVideoCharacter()
{
    if (VideoCharacters.GetSize() == 0)
        return NULL;
    Ptr<VideoCharacter> pvideo = VideoCharacters[0];
    VideoCharacters.RemoveAt(0);
    pTextureImage = NULL;
    return pvideo;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140006580
void VideoProviderNetStream::NotifyVideoCharacters()
{
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pvideo = VideoCharacters[i];
        if (pvideo)
            FUN_140010a70(pvideo);
    }
}

// The environment the NetStream callbacks run on: the target character's, none when it is not interactive.
static inline Environment* GetTargetEnvironment(CharacterHandle* ptarget)
{
    DisplayObject* pch = ptarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return NULL;
    return ToAvmCharacter(pchar)->GetASEnvironment();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008860
void VideoProviderNetStream::SendNotification(const char* note, bool error)
{
    if (!pTarget || !pNetStream || pNetStream->OnStatusCallback.IsNull())
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Ptr<Object> pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    if (error)
        pobj->SetConstMemberRaw(penv->GetSC(), "level", Value(penv->CreateConstString("error")));
    else
        pobj->SetConstMemberRaw(penv->GetSC(), "level", Value(penv->CreateConstString("status")));
    pobj->SetConstMemberRaw(penv->GetSC(), "code", Value(penv->CreateConstString(note)));

    penv->Push(Value(pobj));
    Value ret;
    pNetStream->OnStatusCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// A cue point as a script object: name, time in seconds, type and its parameters.
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008bb0
static Object* ConvertCuePoint(const VideoPlayer::CuePoint& cp, Environment* penv)
{
    Object* pobj = SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("name"), Value(penv->CreateString(cp.Name)));
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("time"), Value((Number)(cp.Time / 1000.0f)));
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("type"),
                       Value(penv->CreateConstString(cp.Type == VideoPlayer::NavigationCuePoint ? "navigation" : "event")));
    if (cp.Params.GetSize() > 0)
    {
        Ptr<Object> pparams = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
        for (UPInt i = 0; i < cp.Params.GetSize(); ++i)
        {
            // The exe builds an object per parameter that it never uses.
            Ptr<Object> pparam = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
            pparams->SetMemberRaw(penv->GetSC(), penv->CreateString(cp.Params[i].Name),
                                  Value(penv->CreateString(cp.Params[i].Value)));
        }
        pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("parameters"), Value(pparams));
    }
    return pobj;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009140
void VideoProviderNetStream::SendMetaInformation()
{
    if (!pNetStream || !pTarget || pNetStream->OnMetaDataCallback.IsNull())
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Ptr<Object> pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    pobj->SetConstMemberRaw(penv->GetSC(), "canSeekToEnd", Value(true));
    pobj->SetConstMemberRaw(penv->GetSC(), "framerate", Value((Number)(VInfo.FrameRate / 1000.0f)));
    pobj->SetConstMemberRaw(penv->GetSC(), "width", Value(VInfo.Width));
    pobj->SetConstMemberRaw(penv->GetSC(), "height", Value(VInfo.Height));
    pobj->SetConstMemberRaw(penv->GetSC(), "duration",
                            Value((Number)((float)VInfo.TotalFrames * 1000.0f / (float)VInfo.FrameRate)));
    if (penv->CheckExtensions())
    {
        pobj->SetConstMemberRaw(penv->GetSC(), "subtitleTracksNumber", Value(VInfo.SubtitleChannelsNumber));
        if (VInfo.AudioTracks.GetSize() > 0)
        {
            Ptr<ArrayObject> ptracks = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));
            for (UPInt i = 0; i < VInfo.AudioTracks.GetSize(); ++i)
            {
                Ptr<Object> ptrack = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
                ptrack->SetConstMemberRaw(penv->GetSC(), "trackIndex", Value(VInfo.AudioTracks[i].Index));
                ptrack->SetConstMemberRaw(penv->GetSC(), "channelsNumber",
                                          Value((int)VInfo.AudioTracks[i].ChannelsNumber));
                ptrack->SetConstMemberRaw(penv->GetSC(), "sampleRate", Value((int)VInfo.AudioTracks[i].SampleRate));
                ptrack->SetConstMemberRaw(penv->GetSC(), "totalSamples",
                                          Value((int)VInfo.AudioTracks[i].TotalSamples));
                ptracks->PushBack(Value(ptrack));
            }
            pobj->SetConstMemberRaw(penv->GetSC(), "audioTracks", Value(ptracks));
        }
    }
    if (VInfo.CuePoints.GetSize() > 0)
    {
        Ptr<ArrayObject> pcuePoints = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));
        for (UPInt i = 0; i < VInfo.CuePoints.GetSize(); ++i)
        {
            Ptr<Object> pcuePoint = *ConvertCuePoint(VInfo.CuePoints[i], penv);
            pcuePoints->PushBack(Value(pcuePoint));
        }
        pobj->SetConstMemberRaw(penv->GetSC(), "cuePoints", Value(pcuePoints));
    }

    penv->Push(Value(pobj));
    Value ret;
    pNetStream->OnMetaDataCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009850
void VideoProviderNetStream::SendCuePoints(const Array<VideoPlayer::CuePoint>& cuePoints)
{
    if (!pNetStream || !pTarget || pNetStream->OnCuePointCallback.IsNull() || cuePoints.GetSize() == 0)
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    for (UPInt i = 0; i < cuePoints.GetSize(); ++i)
    {
        Ptr<Object> pcuePoint = *ConvertCuePoint(cuePoints[i], penv);
        penv->Push(Value(pcuePoint));
        Value ret;
        pNetStream->OnCuePointCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
        penv->Drop1();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009ad0
void VideoProviderNetStream::SendSubtitleInformation()
{
    if (!pTarget)
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Value ret;
    penv->Push(Value(penv->CreateString(pSubtitleMsg)));
    pNetStream->OnSubtitleCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000be60
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
        SendNotification("NetStream.Play.Start", false);
        SendMetaInformation();
        pVideoPlayer->Play();
        break;

    case VideoPlayer::Playing:
        if (!SeekNotificationSent && FrameIsReady)
        {
            SeekNotificationSent = true;
            SendNotification("NetStream.Seek.Notify", false);
        }
        break;

    case VideoPlayer::Finished:
    case VideoPlayer::Stopped:
        if (!SeekNotificationSent)
        {
            SeekNotificationSent = true;
            SendNotification("NetStream.Seek.InvalidTime", true);
        }
        SendNotification("NetStream.Play.Stop", false);
        break;

    case VideoPlayer::FileNotFound:
        if (!NotFoundNotificationSent)
        {
            NotFoundNotificationSent = true;
            SendNotification("NetStream.Play.StreamNotFound", true);
        }
        break;

    case VideoPlayer::InternalError:
        SendNotification("NetStream.Play.InternalError", true);
        break;

    default:
        break;
    }

    if (status == VideoPlayer::Ready || status == VideoPlayer::Playing)
    {
        Array<VideoPlayer::CuePoint> cuePoints;
        pVideoPlayer->GetCurrentCuePoints(&cuePoints);
        SendCuePoints(cuePoints);
    }

    if (pNetStream && !pNetStream->OnSubtitleCallback.IsNull() && VInfo.MaxSubtitleLen > 0)
    {
        if (!pSubtitleMsg)
        {
            pSubtitleMsg = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
            memset(pSubtitleMsg, 0, VInfo.MaxSubtitleLen);
        }
        if (!pSubtitleMsgTmp)
        {
            pSubtitleMsgTmp = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
            memset(pSubtitleMsgTmp, 0, VInfo.MaxSubtitleLen);
        }
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, pSubtitleMsgTmp, VInfo.MaxSubtitleLen);
        if (pSubtitleMsg && pSubtitleMsgTmp && strncmp(pSubtitleMsg, pSubtitleMsgTmp, VInfo.MaxSubtitleLen) != 0)
        {
            strncpy_s(pSubtitleMsg, VInfo.MaxSubtitleLen, pSubtitleMsgTmp, VInfo.MaxSubtitleLen);
            SendSubtitleInformation();
        }
    }
    else
    {
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, NULL, 0);
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400054b0
bool ObjectInterface::SetConstMemberRaw(ASStringContext* psc, const char* name, const Value& val,
                                        const PropFlags& flags)
{
    return SetMemberRaw(psc, psc->CreateConstString(name), val, flags);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007af0
FnCall::~FnCall()
{
}

// ==== NetStream constructor function ================================================================================

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cd30
Object* NetStreamCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) NetStream(penv);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cd70
void NetStreamCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<NetStream> pnetstream;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_NetStream && !fn.ThisPtr->IsBuiltinPrototype())
        pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    else
        pnetstream = *SF_HEAP_NEW(fn.Env->GetHeap()) NetStream(fn.Env);
    fn.Result->SetAsObject(pnetstream.GetPtr());
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000ce30
NetStreamCtorFunction::NetStreamCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// ==== Video ========================================================================================================

// Video.prototype methods.
class VideoProto
{
public:
    static void AttachVideo(const FnCall& fn);   // exe 0x14000d400
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000d400
void VideoProto::AttachVideo(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: Video.attachVideo requires one argument (NetStream object)\n");
        return;
    }
    if (!fn.Arg(0).IsObject() || !fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_Video)
        return;

    VideoCharacter* pvideo    = (VideoCharacter*)static_cast<AvmCharacter*>(fn.ThisPtr)->GetDispObj();
    VideoProvider*  pprovider = NULL;
    if (fn.Arg(0).ToObject(fn.Env)->GetObjectType() == Object::Object_NetStream)
    {
        NetStream* pnetstream = static_cast<NetStream*>(fn.Arg(0).ToObject(fn.Env));
        if (pnetstream)
            pprovider = pnetstream->GetVideoProvider();
    }
    if (pvideo)
    {
        FUN_140010b80(pvideo, pprovider);
        if (pprovider)
        {
            // Without extensions a provider feeds one video only: the one it fed before lets go.
            if (!fn.Env->CheckExtensions())
            {
                VideoCharacter* pcurrent = pprovider->RemoveFirstVideoCharacter();
                if (pcurrent)
                    FUN_140010b80(pcurrent, NULL);
            }
            pprovider->RegisterVideoCharacter(pvideo);
        }
    }
}

// The script object of a Video clip.
class VideoObject : public Object
{
public:
    VideoObject(ASStringContext* psc, Object* pprototype);              // exe 0x14000de10
    VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter);   // exe 0x14000dee0
    VideoObject(Environment* penv);                                     // exe 0x14000dfb0

    virtual ObjectType GetObjectType() const { return Object_VideoASObject; }

protected:
    virtual void Finalize_GC();   // exe 0x14000db80

    WeakPtr<InteractiveObject> pCharacter;   // +0x68
};

// The Video class (constructor function).
class VideoCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x14000e0c0

    static void GlobalCtor(const FnCall& fn);   // exe 0x14000e100
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007ba0
void ObjectInterface::Set__proto__(ASStringContext* psc, Object* protoObj)
{
    if (!pProto)
        SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                     PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = protoObj;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000de10
VideoObject::VideoObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    Set__proto__(psc, pprototype);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000dee0
VideoObject::VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter)
    : Object(gCtxt->GetGC()), pCharacter(pcharacter)
{
    Environment* penv = AS2::ToAvmCharacter(pcharacter)->GetASEnvironment();
    Set__proto__(penv->GetSC(), gCtxt->GetPrototype(ASBuiltin_Video));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000dfb0
VideoObject::VideoObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Video));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000db80
void VideoObject::Finalize_GC()
{
    pCharacter.~WeakPtr();
    Object::Finalize_GC();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000e0c0
Object* VideoCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) VideoObject(penv);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000e100
void VideoCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Video && !fn.ThisPtr->IsBuiltinPrototype())
        fn.Result->SetAsObject(static_cast<Object*>(fn.ThisPtr));
    else
        fn.Result->SetAsObject(SF_HEAP_NEW(fn.Env->GetHeap()) VideoObject(fn.Env));
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5030
// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5080
// MS2-PIN: ??_7VideoProviderNetStream@AS2@GFx@Scaleform@@6B@ 0x1431b5620
// MS2-PIN: ??_7VideoProvider@Video@GFx@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??$ForEachChild_GC@UReleaseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007e40
// MS2-PIN: ??$ForEachChild_GC@UMarkInCycleFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007ea0
// MS2-PIN: ??$ForEachChild_GC@UScanInUseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007f00
// MS2-PIN: ??_7SwfVideoSyncObject@AS2@GFx@Scaleform@@6B@ 0x1431b4fe8
// MS2-PIN: ??0?$WeakPtr@VVideoCharacter@Video@GFx@Scaleform@@@Scaleform@@QEAA@PEAVVideoCharacter@Video@GFx@1@@Z 0x140004eb0
// MS2-PIN: ??_7NetStreamCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b56b0
// MS2-PIN: ??_7NetStreamCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5740
// MS2-PIN: ??_7VideoObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5af0
// MS2-PIN: ??_7VideoObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5a40
// MS2-PIN: ??0?$WeakPtr@VSprite@GFx@Scaleform@@@Scaleform@@QEAA@PEAVSprite@GFx@1@@Z 0x14000d530
// MS2-PIN: ?ToString@Value@AS2@GFx@Scaleform@@QEBA?AVASString@34@PEAVEnvironment@234@H@Z 0x140003290
// MS2-PIN: ?CreateString@StringManager@AS2@GFx@Scaleform@@QEBA?AVASString@34@PEBD@Z 0x140003940
// MS2-PIN: ??4?$Ptr@VVideoImage@Video@GFx@Scaleform@@@Scaleform@@QEAAAEBV01@PEAVVideoImage@Video@GFx@1@@Z 0x140003a70
// MS2-PIN: ??0LocationInfo@URLBuilder@GFx@Scaleform@@QEAA@W4FileUse@123@AEBVString@3@1@Z 0x140004290
// MS2-PIN: ?OperatorNew@Environment@AS2@GFx@Scaleform@@QEAAPEAVObject@234@AEBVASString@34@HH@Z 0x1400044b0
// MS2-PIN: ??0?$WeakPtr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@QEAA@PEAVInteractiveObject@GFx@1@@Z 0x140004ef0
// MS2-PIN: ??0CuePointParam@VideoPlayer@Video@GFx@Scaleform@@QEAA@AEBU01234@@Z 0x140005390
// MS2-PIN: ??0CuePoint@VideoPlayer@Video@GFx@Scaleform@@QEAA@XZ 0x14000a920
