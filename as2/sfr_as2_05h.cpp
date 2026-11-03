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

namespace Scaleform { namespace GFx { namespace AS2 {

// Runs the handlers of the event; Unload marks the clip unloaded and queues it for the unload pass.
// @0x1429409a0
bool AvmSprite::ExecuteEvent(const EventId& id)
{
    if (GetSprite()->IsUnloaded())
        return false;
    Ptr<Sprite> holder(GetSprite());
    if (id.Id == EventId::Event_Load)
    {
        GetSprite()->DisplayObjectBase::Flags &= ~DisplayObjectBase::Mask_JustLoaded;
        if (!GetSprite()->IsAcceptAnimMovesFlagSet() && !(GetSprite()->Sprite::Flags & Sprite::Flags_OnLoadReqd))
            return false;
    }
    bool result = AvmCharacter::ExecuteEvent(id);
    if (id.Id == EventId::Event_Unload)
    {
        GetSprite()->SetUnloaded();
        GetSprite()->SetNextUnloaded(static_cast<MovieImpl*>(GetSprite()->pASRoot->GetMovieImpl())->pUnloadListHead);
        static_cast<MovieImpl*>(GetSprite()->pASRoot->GetMovieImpl())->pUnloadListHead = GetSprite();
        GetSprite()->AddRef();
    }
    return result;
}

} } }
