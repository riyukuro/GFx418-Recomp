// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmSprite::ExecuteEvent, gap
// function of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429409a0-0x142940a86 .text$mn

#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"

// The event dispatch proper (AvmCharacter::ExecuteEvent, a gap function of this unit's family): the exe passes the
// event through in rdx.
namespace Scaleform { namespace GFx { class EventId; } }
Scaleform::UPInt FUN_142940160(void* pavmsprite, const Scaleform::GFx::EventId& id);

namespace Scaleform { namespace GFx { namespace AS2 {

// Runs the handlers of the event; Unload marks the clip unloaded and queues it for the unload pass.
// MS2-FUNCTIONAL: Ptr holder / early-return scheduling
// @0x1429409a0
bool AvmSprite::ExecuteEvent(const EventId& id)
{
    Sprite* psprite = GetSprite();
    if (psprite->DisplayObjectBase::Flags & DisplayObjectBase::Mask_Unloaded)
        return false;
    Ptr<Sprite> holder(psprite);
    bool        result;
    if (id.Id == EventId::Event_Load)
    {
        psprite->DisplayObjectBase::Flags &= ~DisplayObjectBase::Mask_JustLoaded;
        if (!(psprite->DisplayObject::Flags & DisplayObject::Mask_AcceptAnimMoves) && !(psprite->Sprite::Flags & Sprite::Flags_OnLoadReqd))
            return false;
    }
    result = FUN_142940160(this, id) & 0xff;
    if (id.Id == EventId::Event_Unload)
    {
        MovieImpl* pmovie = static_cast<MovieImpl*>(GetSprite()->pASRoot->GetMovieImpl());
        GetSprite()->DisplayObjectBase::Flags |= DisplayObjectBase::Mask_Unloaded;
        GetSprite()->pNextUnloaded = pmovie->pUnloadListHead;
        pmovie->pUnloadListHead    = GetSprite();
        GetSprite()->AddRef();
    }
    return result;
}

} } }
