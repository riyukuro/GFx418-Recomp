// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Sprite, the movie clip instance:
// construction, the active sound bookkeeping (event sounds, the streaming sound and the AS Sound objects attached to
// the clip, with volume and pan inherited down the clip tree) and the timeline accessors.
// MS2-UNIT: sfr_gfx_05b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425d9760-0x1425dd9e0 .text$mn

#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_sound.h"

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

}} // namespace Scaleform::GFx
