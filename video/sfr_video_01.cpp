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
