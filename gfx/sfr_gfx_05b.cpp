// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Sprite, the movie clip instance:
// construction, the active sound bookkeeping (event sounds, the streaming sound and the AS Sound objects attached to
// the clip, with volume and pan inherited down the clip tree) and the timeline accessors.
// MS2-UNIT: sfr_gfx_05b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425d9760-0x1425dd840 .text$mn
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEH@@Scaleform@@6B@ 0x14318be28
// MS2-PIN: ??_7?$RefCountBaseNTS@UActiveSoundItem@Sprite@GFx@Scaleform@@$0BEH@@Scaleform@@6B@ 0x14318be28
// MS2-PIN: ??_7ActiveSoundItem@Sprite@GFx@Scaleform@@6B@ 0x14318be30
// MS2-PIN: ??_7Sprite@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318be38
// MS2-PIN: ??_7Sprite@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318c228
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEH@@Scaleform@@UEAAPEAXI@Z 0x1425d9c00

#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/gfx/gfx_spritedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_timelinesnapshot.h"
#include "../include/gfx/gfx_fontmanager.h"

namespace Scaleform { namespace GFx {

// ---------------------------------------------------------------------------------------------------------------------
// Sounds

inline Sprite::ActiveSounds::ActiveSounds()
{
    Volume = 100;
    Pan    = 0;
}

// @0x1425d99f0
Sprite::ActiveSounds::~ActiveSounds()
{
    if (pStreamSound)
    {
        pStreamSound->Stop();
        pStreamSound = 0;
    }
    for (UPInt i = 0; i < ASSounds.GetSize(); i++)
        ASSounds[i]->ReleaseTarget();
}

// @0x1425d9980
Sprite::ActiveSoundItem::~ActiveSoundItem()
{
    if (pChannel)
        pChannel->Stop();
    if (pResource)
    {
        pResource->DecPlayingCount();
        if (!pResource->IsPlaying())
            pResource->GetSoundInfo()->ReleaseResource();
        pResource->Release();
    }
}

// @0x1425dbba0
bool Sprite::IsSoundPlaying(ASSoundIntf* psnd)
{
    if (pActiveSounds)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
        {
            ActiveSoundItem* item = pActiveSounds->Sounds[i];
            if (item->pSoundObject == psnd)
                return item->pChannel && item->pChannel->IsPlaying();
        }
    }
    return false;
}

// Registers a channel this clip started; a channel already known only gets its owner and resource replaced.
// @0x1425d9f20
void Sprite::AddActiveSound(Sound::SoundChannel* pchan, ASSoundIntf* psnd, SoundResource* pres)
{
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;

    Ptr<ActiveSoundItem> item;
    for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
    {
        if (pActiveSounds->Sounds[i]->pChannel.GetPtr() == pchan)
        {
            item = pActiveSounds->Sounds[i];
            break;
        }
    }
    if (!item)
    {
        item = *new ActiveSoundItem;
        item->pChannel = pchan;
        pActiveSounds->Sounds.PushBack(item);
        ModifyOptimizedPlayListLocal<Sprite>();
    }
    item->pSoundObject = psnd;
    item->pResource    = pres;
    if (item->pResource)
    {
        item->pResource->IncPlayingCount();
        item->pResource->AddRef();
    }
}

// @0x1425dd090
void Sprite::SetStreamingSound(Sound::SoundChannel* pchan)
{
    if (!pchan && !pActiveSounds)
        return;
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;
    if (pActiveSounds->pStreamSound)
        pActiveSounds->pStreamSound->Stop();
    pActiveSounds->pStreamSound = pchan;
    if (pActiveSounds->pStreamSound)
    {
        pActiveSounds->pStreamSound->SetVolume(GetRealSoundVolume());
        AddActiveSound(pchan, 0, 0);
    }
}

// @0x1425db3d0
Sound::SoundChannel* Sprite::GetStreamingSound() const
{
    if (!pActiveSounds)
        return 0;
    return pActiveSounds->pStreamSound;
}

// @0x1425da920
void Sprite::DetachSoundObject(ASSoundIntf* psnd)
{
    if (!pActiveSounds || !psnd)
        return;
    UPInt i;
    for (i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
    {
        Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
        if (item->pSoundObject == psnd)
            item->pSoundObject = 0;
    }
    for (i = 0; i < pActiveSounds->ASSounds.GetSize(); i++)
    {
        if (pActiveSounds->ASSounds[i] == psnd)
        {
            pActiveSounds->ASSounds.RemoveAt(i);
            break;
        }
    }
}

// Position in seconds of the first channel psnd plays, 0 when none.
// @0x1425dace0
float Sprite::GetActiveSoundPosition(ASSoundIntf* psnd)
{
    if (pActiveSounds && psnd)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
        {
            Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
            if (item->pSoundObject == psnd && item->pChannel)
                return item->pChannel->GetPosition();
        }
    }
    return 0.0f;
}

// @0x1425da2f0
void Sprite::AttachSoundObject(ASSoundIntf* psnd)
{
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;
    pActiveSounds->ASSounds.PushBack(psnd);
}

// @0x1425db3b0
int Sprite::GetSoundVolume()
{
    if (pActiveSounds)
        return pActiveSounds->Volume;
    return 100;
}

// The clip's volume scaled by every parent clip's (1 = full).
// @0x1425db210
float Sprite::GetRealSoundVolume()
{
    float v = GetSoundVolume() / 100.0f;
    for (InteractiveObject* parent = GetParent(); parent; parent = parent->GetParent())
    {
        if (parent->IsSprite())
            v *= static_cast<Sprite*>(parent)->GetSoundVolume() / 100.0f;
    }
    return v;
}

// Same as GetRealSoundVolume for the sub audio track.
// @0x1425db280
float Sprite::GetRealSubSoundVolume()
{
    float v = (pActiveSounds ? pActiveSounds->SubVolume : 100) / 100.0f;
    for (InteractiveObject* parent = GetParent(); parent; parent = parent->GetParent())
    {
        if (parent->IsSprite())
        {
            Sprite* sprite = static_cast<Sprite*>(parent);
            v *= (sprite->pActiveSounds ? sprite->pActiveSounds->SubVolume : 100) / 100.0f;
        }
    }
    return v;
}

// @0x1425dcff0
void Sprite::SetSoundVolume(int volume, int subVolume)
{
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;
    pActiveSounds->Volume    = volume;
    pActiveSounds->SubVolume = subVolume;
    UpdateActiveSoundVolume();
}

// Applies the inherited volume to the clip's channels (a sound object with its own transform keeps its volume),
// then to the child clips.
// @0x1425dd720
void Sprite::UpdateActiveSoundVolume()
{
    if (!pActiveSounds)
        return;
    float v = GetRealSoundVolume();
    for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
    {
        Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
        if (item->pSoundObject && item->pSoundObject->HasPrivateOverride())
            v = item->pSoundObject->PrivateVolume() / 100.0f;
        item->pChannel->SetVolume(v);
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsSprite())
            static_cast<Sprite*>(ch)->UpdateActiveSoundVolume();
    }
}

// @0x1425db390
int Sprite::GetSoundPan()
{
    if (pActiveSounds)
        return pActiveSounds->Pan;
    return 0;
}

// @0x1425db1a0
float Sprite::GetRealSoundPan()
{
    float v = GetSoundPan() / 100.0f;
    for (InteractiveObject* parent = GetParent(); parent; parent = parent->GetParent())
    {
        if (parent->IsSprite())
            v *= static_cast<Sprite*>(parent)->GetSoundPan() / 100.0f;
    }
    return v;
}

// @0x1425dcf70
void Sprite::SetSoundPan(int pan)
{
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;
    pActiveSounds->Pan = pan;
    UpdateActiveSoundPan();
}

// @0x1425dd5b0
void Sprite::UpdateActiveSoundPan()
{
    if (!pActiveSounds)
        return;
    float v = GetRealSoundPan();
    for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
    {
        Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
        if (item->pSoundObject && item->pSoundObject->HasPrivateOverride())
            v = item->pSoundObject->PrivatePan() / 100.0f;
        item->pChannel->SetPan(v);
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsSprite())
            static_cast<Sprite*>(ch)->UpdateActiveSoundPan();
    }
}

// Stops every channel of this clip and its child clips.
// @0x1425dd4d0
// MS2-FUNCTIONAL: the exe tests the child's interactive and sprite flag bits one shift at a time (bit-field reads?), cl folds them into one mask compare
void Sprite::StopActiveSounds()
{
    if (pActiveSounds)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
        {
            Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
            item->pChannel->Stop();
        }
        pActiveSounds->Sounds.Resize(0);
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsSprite())
            static_cast<Sprite*>(ch)->StopActiveSounds();
    }
}

// Stops the channels playing pres, here and in the child clips.
// @0x1425dd380
// MS2-FUNCTIONAL: the exe tests the child's interactive and sprite flag bits one shift at a time (bit-field reads?), cl folds them into one mask compare
void Sprite::StopActiveSounds(SoundResource* pres)
{
    if (pActiveSounds)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize();)
        {
            Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
            if (item->pResource == pres)
            {
                item->pChannel->Stop();
                pActiveSounds->Sounds.RemoveAt(i);
            }
            else
                i++;
        }
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsSprite())
            static_cast<Sprite*>(ch)->StopActiveSounds(pres);
    }
}

// Stops the channels started by psnd, here and in the child clips.
// @0x1425dd230
// MS2-FUNCTIONAL: the exe tests the child's interactive and sprite flag bits one shift at a time (bit-field reads?), cl folds them into one mask compare
void Sprite::StopActiveSounds(ASSoundIntf* psnd)
{
    if (pActiveSounds)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize();)
        {
            Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
            if (item->pSoundObject == psnd)
            {
                item->pChannel->Stop();
                pActiveSounds->Sounds.RemoveAt(i);
            }
            else
                i++;
        }
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsSprite())
            static_cast<Sprite*>(ch)->StopActiveSounds(psnd);
    }
}

// Hands the item of pchan over to the caller (MovieClip.attachAudio moves it to another clip); the caller owns the
// returned reference.
// @0x1425dc620
Sprite::ActiveSoundItem* Sprite::ReleaseActiveSound(Sound::SoundChannel* pchan)
{
    if (!pActiveSounds)
        return 0;
    for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
    {
        Ptr<ActiveSoundItem> item = pActiveSounds->Sounds[i];
        if (item->pChannel.GetPtr() == pchan)
        {
            pActiveSounds->Sounds.RemoveAt(i);
            ModifyOptimizedPlayListLocal<Sprite>();
            item->AddRef();
            return item.GetPtr();
        }
    }
    return 0;
}

// Takes an item from ReleaseActiveSound.
// @0x1425da220
void Sprite::AttachActiveSound(ActiveSoundItem* item)
{
    if (!pActiveSounds)
        pActiveSounds = new ActiveSounds;
    pActiveSounds->Sounds.PushBack(Ptr<ActiveSoundItem>(item));
    ModifyOptimizedPlayListLocal<Sprite>();
}

// ---------------------------------------------------------------------------------------------------------------------
// Construction

// A clip loaded by loadMovie (loadedSeparately) or imported from another movie gets its own root node.
// @0x1425d9760
// MS2-FUNCTIONAL: member initialisation order and the flag byte merge differ from the exe
Sprite::Sprite(TimelineDef* pdef, MovieDefImpl* pdefImpl, ASMovieRootBase* pr, InteractiveObject* pparent,
               ResourceId id, bool loadedSeparately)
    : DisplayObjContainer(pdefImpl, pr, pparent, id), pDef(pdef), PlayStatePriv(State_Playing), CurrentFrame(0),
      pActiveSounds(0), pHitAreaHandle(0), pHitAreaHolder(0), Flags(0), FocusEnabled(0), MouseStatePriv(MouseState_Up)
{
    pASRoot       = pr;
    pActiveSounds = 0;
    if (pdef->GetResourceType() == Resource::RT_SpriteDef)
    {
        SetScale9Grid(static_cast<SpriteDef*>(pdef)->GetScale9Grid());
        Flags |= Flags_SpriteDef;
    }
    DisplayObjectBase::Flags |= Mask_Sprite;
    Flags = UByte((Flags & ~(Flags_HasLoopedPriv | Flags_LockRoot)) | Flags_UpdateFrame);
    Flags = UByte(loadedSeparately ? (Flags | Flags_LoadedSeparately) : (Flags & ~Flags_LoadedSeparately));

    bool importFlag = pparent && !loadedSeparately && pparent->GetResourceMovieDef() != pdefImpl;
    if (loadedSeparately || importFlag)
        AssignRootNode(importFlag);
}

// @0x1425d9ac0
Sprite::~Sprite()
{
    if (pActiveSounds)
        delete pActiveSounds;
    mDisplayList.Clear(this);
    DisplayObjectBase::SetDirtyFlag();
}

// ---------------------------------------------------------------------------------------------------------------------
// Simple state

// @0x1425dcda0
void Sprite::SetLoadedSeparately(bool v)
{
    Flags = UByte(v ? (Flags | Flags_LoadedSeparately) : (Flags & ~Flags_LoadedSeparately));
    if (v)
        AssignRootNode();
}

// @0x1425dcf40
void Sprite::SetRootNodeLoadingStat(unsigned bytesLoaded, unsigned loadingFrame)
{
    if (pRootNode)
    {
        pRootNode->BytesLoaded  = bytesLoaded;
        pRootNode->LoadingFrame = pRootNode->ImportFlag ? 0 : loadingFrame;
    }
}

// @0x1425dcc00
void Sprite::SetIMECandidateListFont(FontHandle* pfont)
{
    if (pfont)
        pRootNode->pFontManager->SetIMECandidateFont(pfont);
}

// Identical code to the rect variant, so the linker folded the two.
// @0x1425db2f0
RectF DisplayObjContainer::GetBounds(const Matrix& t) const
{
    return mDisplayList.GetRectBounds(t);
}

// _root, honouring _lockroot of a separately loaded clip.
// @0x1425db650
InteractiveObject* Sprite::GetTopParent(bool ignoreLockRoot) const
{
    if (!GetParent() || (!ignoreLockRoot && IsLoadedSeparately() && IsLockRoot()))
        return const_cast<Sprite*>(this);
    if (IsUnloaded())
        return GetMovieImpl()->pMainMovie;
    return GetParent()->GetTopParent(ignoreLockRoot);
}

// @0x1425dae80
UInt32 Sprite::GetBytesLoaded() const
{
    MovieDefRootNode* root = FindRootNode();
    if (root)
        return root->BytesLoaded;
    return 0;
}

// Frames loaded so far (background loading).
// @0x1425db150
// MS2-FUNCTIONAL: no exe function row (the body sits in the padding of the GetLabeledFrame row)
unsigned Sprite::GetLoadingFrame() const
{
    if (pRootNode && !pRootNode->ImportFlag)
        return pRootNode->LoadingFrame;
    // Imported or fully loaded: every frame of the definition.
    return pDef->GetFrameCount();
}

// @0x1425daea0
CharacterDef* Sprite::GetCharacterDef() const
{
    return pDef;
}

// @0x1425daeb0
unsigned Sprite::GetCurrentFrame() const
{
    return CurrentFrame;
}

// @0x1425db110
bool Sprite::GetLabeledFrame(const char* label, unsigned* frameNumber, bool translateNumbers)
{
    return pDef->GetLabeledFrame(label, frameNumber, translateNumbers);
}

// @0x1425db6a0
CharacterDef::CharacterDefType Sprite::GetType() const
{
    return CharacterDef::Sprite;
}

// @0x1425dba00
bool Sprite::HasLooped() const
{
    return (Flags & Flags_HasLoopedPriv) != 0;
}

// @0x1425db180
// MS2-FUNCTIONAL: no exe function row (the body sits in the padding of the GetLoadingFrame row)
PlayState Sprite::GetPlayState() const
{
    return (DisplayObjectBase::Flags & Mask_MovieClip) ? PlayStatePriv : State_Stopped;
}

// @0x1425dceb0
// MS2-FUNCTIONAL: the exe keeps the new state in edx and reloads PlayStatePriv only after the play list update
void Sprite::SetPlayState(PlayState s)
{
    PlayStatePriv = s;
    if (!IsUnloading() && !IsUnloaded())
        ModifyOptimizedPlayListLocal<Sprite>();
    if (PlayStatePriv == State_Stopped)
        SetStreamingSound(0);
}

// Pauses or resumes the clip's channels and every interactive child.
// @0x1425dcdf0
void Sprite::SetPause(bool pause)
{
    if (pActiveSounds)
    {
        for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
        {
            ActiveSoundItem* item = pActiveSounds->Sounds[i];
            if (item->pChannel)
                item->pChannel->Pause(pause);
        }
    }
    for (unsigned i = 0; i < mDisplayList.GetCount(); i++)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch->IsInteractiveObject())
            static_cast<InteractiveObject*>(ch)->SetPause(pause);
    }
}

// @0x1425dcdd0
void Sprite::SetName(const ASString& name)
{
    DisplayObject::SetName(name);
    mDisplayList.pCachedChar = 0;
}

// @0x1425db0b0
Sprite* Sprite::GetHitArea() const
{
    if (pHitAreaHandle)
    {
        DisplayObject* ch = pHitAreaHandle->ResolveCharacter(GetMovieImpl());
        if (ch)
            return ch->IsSprite() ? static_cast<Sprite*>(ch) : 0;
    }
    return 0;
}

// @0x1425db100
Sprite* Sprite::GetHitAreaHolder() const
{
    return pHitAreaHolder;
}

// @0x1425dcb00
void Sprite::SetHitArea(Sprite* phitArea)
{
    Sprite* old = GetHitArea();
    if (old)
        old->pHitAreaHolder = 0;
    if (phitArea)
    {
        pHitAreaHandle           = phitArea->GetCharacterHandle();
        phitArea->pHitAreaHolder = this;
    }
    else
        pHitAreaHandle = 0;
    if (HasAvmObject())
        GetAvmSprite()->SetHitAreaNotify(phitArea);
}

// ---------------------------------------------------------------------------------------------------------------------
// Timeline

// Runs the tags of a frame; only a movie clip runs anything past frame 0.
// @0x1425daab0
void Sprite::ExecuteFrameTags(unsigned frame)
{
    if (!(DisplayObjectBase::Flags & Mask_MovieClip) && frame != 0)
        return;
    Ptr<Sprite> keepAlive(this);
    if (frame >= GetLoadingFrame())
        return;
    const TimelineDef::Frame playlist = pDef->GetPlaylist(frame);
    for (unsigned i = 0; i < playlist.GetTagCount(); i++)
        playlist.GetTag(i)->ExecuteWithPriority(this, ActionPriority::AP_Frame);
    if (HasAvmObject())
        GetAvmSprite()->ExecuteFrameTags(frame);
}

// Steps to the next frame. A clip waiting on the loader stays at the last loaded frame; at the end it wraps to
// frame 0 (a one-frame clip stops instead).
// @0x1425dba10
void Sprite::IncrementFrameAndCheckForLoop()
{
    CurrentFrame++;
    unsigned loadingFrame = GetLoadingFrame();
    unsigned frameCount   = pDef->GetFrameCount();
    if (loadingFrame < frameCount && CurrentFrame >= loadingFrame)
    {
        CurrentFrame = loadingFrame ? loadingFrame - 1 : 0;
        return;
    }
    if (CurrentFrame < frameCount)
        return;
    Flags |= Flags_HasLoopedPriv;
    CurrentFrame = 0;
    if (frameCount > 1)
        mDisplayList.MarkAllEntriesForRemoval(this, 0);
    else
        SetPlayState(State_Stopped);
}

// Removes the sounds that stopped playing (their Sound objects get onSoundComplete) and updates the clip's place on
// the advance list, which a playing sound keeps it on.
// @0x1425da3c0
// MS2-FUNCTIONAL: the exe inlines the play list update (CheckAdvanceStatus included); here it is the out of line
// ModifyOptimizedPlayListLocal<Sprite> instance
void Sprite::CheckActiveSounds()
{
    if (!pActiveSounds)
        return;
    Array<Ptr<ActiveSoundItem> > sounds;
    for (UPInt i = 0; i < pActiveSounds->Sounds.GetSize(); i++)
        sounds.PushBack(pActiveSounds->Sounds[i]);

    Array<Ptr<ActiveSoundItem> > finished;
    for (UPInt i = 0; i < sounds.GetSize();)
    {
        Ptr<ActiveSoundItem> item = sounds[i];
        if (item->pChannel->IsPlaying())
        {
            i++;
            continue;
        }
        if (item->pSoundObject)
            item->pSoundObject->ExecuteOnSoundComplete();
        finished.PushBack(sounds[i]);
        sounds.RemoveAt(i);
        ModifyOptimizedPlayListLocal<Sprite>();
    }

    for (UPInt i = 0; i < finished.GetSize(); i++)
    {
        if (!pActiveSounds)
            continue;
        ArrayLH<Ptr<ActiveSoundItem> >& active = pActiveSounds->Sounds;
        for (UPInt j = 0; j < active.GetSize(); j++)
        {
            if (active[j] == finished[i])
            {
                active.RemoveAt(j);
                break;
            }
        }
    }
}

// 1: put the clip on the advance list, -1: take it off, 0: leave it. A clip advances while it plays, while it has
// sounds or while it is the movie's keep-advancing character; otherwise only if the AVM needs its frame events.
// @0x1425da750
// MS2-FUNCTIONAL: the exe keeps advanceDisabled in a register across the AVM calls and saves one fewer nonvolatile
int Sprite::CheckAdvanceStatus(bool playingNow)
{
    bool advanceDisabled = IsAdvanceDisabled() || (DisplayObjectBase::Flags & Mask_MarkedForRemove);
    if (!advanceDisabled)
    {
        if (GetPlayState() == State_Playing || GetMovieImpl()->pKeepAdvancingChar == this ||
            (pActiveSounds && pActiveSounds->Sounds.GetSize() != 0))
            return !playingNow;
    }
    if (playingNow)
    {
        if (advanceDisabled)
            return -1;
        return (HasAvmObject() && GetAvmSprite()->MustBeInPlaylist()) ? 0 : -1;
    }
    if (advanceDisabled)
        return 0;
    if (HasAvmObject() && GetAvmSprite()->MustBeInPlaylist())
        return 1;
    return 0;
}

// Per-frame advance: the sounds, the streaming sound block of the frame, then the AVM.
// @0x1425da130
void Sprite::AdvanceFrame(bool nextFrame, float framePos)
{
    if (!(DisplayObjectBase::Flags & Mask_MovieClip) && IsAdvanceDisabled())
        return;
    if (IsUnloading())
        return;
    Ptr<Sprite> keepAlive(this);
    if (nextFrame)
    {
        CheckActiveSounds();
        if (PlayStatePriv != State_Stopped)
        {
            SoundStreamDef* psoundStream = pDef->GetSoundStream();
            if (psoundStream && !psoundStream->ProcessSwfFrame(GetMovieImpl(), CurrentFrame, this))
                pDef->SetSoundStream(0);
        }
    }
    if (HasAvmObject())
        GetAvmSprite()->AdvanceFrame(nextFrame, framePos);
}

// The InitActions of a movie imported into this clip's movie, frame by frame.
// @0x1425dab70
void Sprite::ExecuteImportedInitActions(MovieDef* psourceMovie)
{
    MovieDefImpl* pdefImpl  = static_cast<MovieDefImpl*>(psourceMovie);
    MovieDataDef* pdataDef  = pdefImpl->GetDataDef();
    unsigned      frameCount = pdataDef->GetInitActionListSize();
    for (unsigned f = 0; f < frameCount; f++)
    {
        TimelineDef::Frame actions;
        if (!pdataDef->GetInitActions(&actions, f))
            continue;
        for (unsigned i = 0; i < actions.GetTagCount(); i++)
        {
            ExecuteTag* ptag = actions.GetTag(i);
            if (ptag->IsInitImportActionsTag())
                static_cast<GFxInitImportActions*>(ptag)->ExecuteInContext(this, pdefImpl, true);
            else
                ptag->ExecuteWithPriority(this, ActionPriority::AP_Highest);
        }
    }
}

// gotoAndPlay/gotoAndStop with a label (offset frames after it).
// @0x1425db970
bool Sprite::GotoLabeledFrame(const char* label, int offset)
{
    unsigned targetFrame = ~0u;
    if (pDef->GetLabeledFrame(label, &targetFrame, false))
    {
        GotoFrame(targetFrame + offset);
        return true;
    }
    LogWarning("MovieImpl::GotoLabeledFrame('%s') unknown label", label);
    return false;
}

// Back to frame 0 in the playing state, re-running its init actions and tags.
// @0x1425dca60
// MS2-FUNCTIONAL: the exe merges the flag byte in al with one store after the field resets; cl updates it in place
void Sprite::Restart()
{
    mDisplayList.MarkAllEntriesForRemoval(this, 0);
    Flags         = (Flags & ~Flags_HasLoopedPriv) | Flags_UpdateFrame;
    PlayStatePriv = State_Playing;
    CurrentFrame  = 0;
    RollOverCnt   = 0;
    if (HasAvmObject())
        GetAvmSprite()->ExecuteInitActionFrameTags(CurrentFrame);
    ExecuteFrameTags(CurrentFrame);
    mDisplayList.UnloadMarkedObjects(this);
}

// Hands the no-advance state down to the children and updates their place on the advance list.
// @0x1425dc3e0
// MS2-FUNCTIONAL: the exe tests the two play list bits one shift at a time (shr/test), cl folds them into one mask compare
void Sprite::PropagateNoAdvanceGlobalFlag()
{
    bool noAdvance = IsNoAdvanceGlobalFlagSet();
    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; i++)
    {
        DisplayObjectBase* pch = mDisplayList.GetDisplayObject(i);
        InteractiveObject* pich = pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
        if (!pich)
            continue;
        pich->SetNoAdvanceGlobalFlag(IsNoAdvanceGlobalFlagSet() || noAdvance);
        pich->PropagateNoAdvanceGlobalFlag();
        int status = pich->CheckAdvanceStatus(pich->IsInPlayList());
        if (status == -1)
            pich->Flags |= Mask_MarkedToRemoveFromOptAdvList;
        else if (status == 1)
            pich->AddToOptimizedPlayList();
    }
}

// @0x1425dc500
// MS2-FUNCTIONAL: the exe tests the two play list bits one shift at a time (shr/test), cl folds them into one mask compare
void Sprite::PropagateNoAdvanceLocalFlag()
{
    bool noAdvance = IsNoAdvanceLocalFlagSet();
    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; i++)
    {
        DisplayObjectBase* pch = mDisplayList.GetDisplayObject(i);
        InteractiveObject* pich = pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
        if (!pich)
            continue;
        pich->SetNoAdvanceLocalFlag(IsNoAdvanceLocalFlagSet() || noAdvance);
        pich->PropagateNoAdvanceLocalFlag();
        int status = pich->CheckAdvanceStatus(pich->IsInPlayList());
        if (status == -1)
            pich->Flags |= Mask_MarkedToRemoveFromOptAdvList;
        else if (status == 1)
            pich->AddToOptimizedPlayList();
    }
}

// Hiding a clip stops its advance when the movie has noInvisibleAdvance set.
// @0x1425dd1a0
void Sprite::SetVisible(bool visible)
{
    SetVisibleFlag(visible);
    bool noAdvance = !visible && GetMovieImpl()->IsNoInvisibleAdvanceFlagSet();
    if (noAdvance == IsNoAdvanceGlobalFlagSet())
        return;
    SetNoAdvanceGlobalFlag(noAdvance);
    ModifyOptimizedPlayListLocal<Sprite>();
    if (pParent && !pParent->IsNoAdvanceGlobalFlagSet())
        PropagateNoAdvanceGlobalFlag();
}

// Jumps to a frame (clamped to the loaded ones) and stops there. Going back rebuilds the display list from frame 0;
// going forward over several frames applies their tags as one snapshot; the target frame's tags then run normally.
// @0x1425db6b0
// MS2-FUNCTIONAL: the backward jump gets the heap through the virtual MovieImpl::GetMovieHeap (vftable +0x178, MovieImpl's
// vtable is not recovered); here both jumps read MovieImpl::pHeap, and the stack frame differs
void Sprite::GotoFrame(unsigned targetFrameNumber)
{
    if (!(DisplayObjectBase::Flags & Mask_MovieClip) || IsUnloading())
        return;
    int target = Alg::Min<int>(targetFrameNumber, GetLoadingFrame() - 1);
    if (target < 0)
        target = 0;
    unsigned frame = target;
    SetStreamingSound(0);

    if (frame < CurrentFrame)
    {
        mDisplayList.MarkAllEntriesForRemoval(this, frame ? frame - 1 : 0);
        if (frame >= 1)
        {
            TimelineSnapshot snapshot(TimelineSnapshot::Direction_Backward, GetMovieImpl()->pHeap, this);
            snapshot.MakeSnapshot(pDef, 0, frame - 1);
            CurrentFrame = frame;
            snapshot.ExecuteSnapshot(this);
        }
        else
            CurrentFrame = frame;
        if (HasAvmObject())
            GetAvmSprite()->ExecuteInitActionFrameTags(frame);
        ExecuteFrameTags(frame);
        mDisplayList.UnloadMarkedObjects(this);
    }
    else if (frame > CurrentFrame)
    {
        if (frame > 1 && frame > CurrentFrame + 1)
        {
            TimelineSnapshot snapshot(TimelineSnapshot::Direction_Forward, GetMovieImpl()->pHeap, this);
            snapshot.MakeSnapshot(pDef, CurrentFrame + 1, frame - 1);
            if (HasAvmObject())
            {
                for (unsigned f = CurrentFrame + 1; f < frame; f++)
                    GetAvmSprite()->ExecuteInitActionFrameTags(f);
            }
            CurrentFrame = frame;
            snapshot.ExecuteSnapshot(this);
        }
        else
            CurrentFrame = frame;
        if (HasAvmObject())
            GetAvmSprite()->ExecuteInitActionFrameTags(frame);
        ExecuteFrameTags(frame);
    }
    PlayStatePriv = State_Stopped;
}

// The nodes go back to the pool, which then frees its pages.
// @0x1425d9b70
TimelineSnapshot::~TimelineSnapshot()
{
    SnapshotElement* pe = SnapshotList.GetFirst();
    while (!SnapshotList.IsNull(pe))
    {
        SnapshotElement* next = SnapshotList.GetNext(pe);
        SnapshotHeap.Free(pe);
        pe = next;
    }
    SnapshotList.Clear();
}

// @0x1425dcf10
TimelineSnapshot::SnapshotElement::~SnapshotElement() {}

// ---------------------------------------------------------------------------------------------------------------------
// Focus and mouse

// A clip that acts as a button gets a rollOver when the keyboard brings the focus to it.
// @0x1425dbe70
void Sprite::OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
{
    if (fmt != GFx_FocusMovedByKeyboard)
        return;
    if (HasAvmObject() && GetAvmIntObj()->ActsAsButton() && !GetMovieImpl()->IsDisableFocusRolloverEvent())
    {
        EventId evt(EventId::Event_RollOver);
        evt.ControllerIndex = (SByte)controllerIdx;
        OnMouseEvent(evt);
    }
}

// ... and a rollOut when the keyboard moves the focus away while the focus rectangle is shown.
// @0x1425dc150
bool Sprite::OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx, FocusMovedType fmt)
{
    if (fmt == GFx_FocusMovedByKeyboard && HasAvmObject() && GetAvmIntObj()->ActsAsButton())
    {
        MovieImpl* proot = GetMovieImpl();
        if (proot->IsFocusRectShown(controllerIdx) && !proot->IsDisableFocusRolloverEvent())
        {
            EventId evt(EventId::Event_RollOut);
            evt.ControllerIndex = (SByte)controllerIdx;
            OnMouseEvent(evt);
        }
    }
    return true;
}

// Button events go to the AVM handlers; unhandled ones bubble up to the parent (level movies keep theirs).
// @0x1425dc210
bool Sprite::OnMouseEvent(const EventId& evt)
{
    if (HasAvmObject() && GetAvmSprite()->IsLevelMovie())
        return false;
    if (HasAvmObject() && GetAvmSprite()->OnEvent(evt))
        return false;
    if (pParent)
        return pParent->OnMouseEvent(evt);
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// AVM forwarding

// @0x1425db120
int Sprite::GetLevel() const
{
    return GetAvmSprite()->GetLevel();
}

// @0x1425dbb60
bool Sprite::IsLevelMovie() const
{
    return GetAvmSprite()->IsLevelMovie();
}

// @0x1425dbc60
bool Sprite::MustBeInPlaylist() const
{
    if (HasAvmObject())
        return GetAvmSprite()->MustBeInPlaylist();
    return false;
}

// @0x1425da0c0
DisplayObjectBase* Sprite::AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                            const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                            const void* pinitSource, unsigned createFrame, unsigned long addFlags,
                                            CharacterCreateInfo* pcharCreateOverride, InteractiveObject* origChar)
{
    if (HasAvmObject())
        return GetAvmSprite()->AddDisplayObject(pos, name, peventHandlers, pinitSource, createFrame, addFlags,
                                                pcharCreateOverride, origChar);
    return 0;
}

// A clip replaced by the timeline continues from this clip's frame.
// @0x1425da8b0
void Sprite::CreateAndReplaceDisplayObject(const CharPosInfo& pos, const ASString& name, DisplayObjectBase** newChar)
{
    if (newChar)
        *newChar = 0;
    DisplayObjContainer::CreateAndReplaceDisplayObject(pos, name, newChar);
    if (newChar && *newChar)
        (*newChar)->CreateFrame = CurrentFrame;
}

// @0x1425da860
void Sprite::CloneInternalData(const InteractiveObject* src)
{
    DisplayObjContainer::CloneInternalData(src);
    if (HasAvmObject())
        GetAvmSprite()->CloneInternalData(src);
}

// @0x1425daca0
void Sprite::ForceShutdown()
{
    DisplayObjContainer::ForceShutdown();
    if (HasAvmObject())
        GetAvmSprite()->ForceShutdown();
    RemoveFromPlayList();
}

// Runs the init actions and the tags of frame 0 once.
// @0x1425daa30
void Sprite::ExecuteFrame0Events()
{
    if (Flags & Flags_OnEventLoadCalled)
        return;
    Flags |= Flags_OnEventLoadCalled;
    if (HasAvmObject())
        GetAvmSprite()->ExecuteInitActionFrameTags(0);
    ExecuteFrameTags(0);
    if (HasAvmObject())
        GetAvmSprite()->ExecuteFrame0Events();
}

// @0x1425da900
void Sprite::DefaultOnEventLoad()
{
    ExecuteFrameTags(0);
    DisplayObjectBase::Flags |= Mask_JustLoaded;
}

// @0x1425dbca0
bool Sprite::OnEvent(const EventId& id)
{
    if (HasAvmObject())
        return GetAvmSprite()->OnEvent(id);
    return false;
}

// @0x1425dbe20
void Sprite::OnEventXmlsocketOnxml()
{
    if (HasAvmObject())
        GetAvmSprite()->OnEvent(EventId(EventId::Event_SockXML));
}

// @0x1425dbce0
void Sprite::OnEventIntervalTimer() {}

// @0x1425dbcf0
void Sprite::OnEventLoadProgress()
{
    if (HasAvmObject())
        GetAvmSprite()->OnEvent(EventId(EventId::Event_LoadProgress));
}

// @0x1425dbf10
void Sprite::OnIntervalTimer(void* timer) {}

// @0x1425dbd40
void Sprite::OnEventUnload()
{
    DisplayObjectBase::Flags |= Mask_Unloading;
    if (pActiveSounds)
        delete pActiveSounds;
    pActiveSounds = 0;
    if (pHitAreaHandle)
        SetHitArea(0);
    mDisplayList.Clear(this);
    DisplayObjContainer::OnEventUnload();
}

// @0x1425dc2a0
bool Sprite::OnUnloading()
{
    bool mayRemove = mDisplayList.UnloadAll(this);
    if (HasAvmObject())
        mayRemove = GetAvmObjImpl()->OnUnloading(mayRemove);
    return mayRemove;
}

// Focus by mouse follows the default rules; otherwise focusEnabled decides, undefined asking the AVM.
// @0x1425dbad0
bool Sprite::IsFocusEnabled(FocusMovedType fmt) const
{
    if (fmt == GFx_FocusMovedByMouse)
        return InteractiveObject::IsFocusEnabled(fmt);
    if (FocusEnabled == 0 && HasAvmObject())
        return GetAvmSprite()->IsFocusEnabled(fmt);
    if (FocusEnabled == 2)
        return HasAvmObject() && GetAvmIntObj()->ActsAsButton();
    return FocusEnabled == 1;
}

}} // namespace Scaleform::GFx
