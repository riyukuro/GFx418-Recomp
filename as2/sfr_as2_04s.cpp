// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmSprite::AddDisplayObject, the
// place-object entry of a clip (gap recovery of sfr_as2_04; lane sfr31, taken over from sfr32).
// MS2-UNIT: sfr_as2_04s
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292ea50-0x14292f006 .text$mn

#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx {
namespace AS3 {
// InteractiveObject::ModifyOptimizedPlayList, out of line in the exe (defined in sfr_as3_18).
void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);
}
namespace AS2 {

// The empty hook the exe calls on the clip after a new object was bound (exe 0x1425dcaf0, a bare ret).
void FUN_1425dcaf0(void* pobj);

// addFlags of AddDisplayObject (the same bits the Sprite entry forwards).
enum
{
    AddFlag_ReplaceIfDepthIsOccupied = 0x01, // DisplayList::Flags_ReplaceIfDepthIsOccupied
    AddFlag_PlaceObject              = 0x04  // placed by a tag (the child keeps accepting timeline moves)
};

// MS2-FUNCTIONAL: SDK body (OnAddedDisplayObject inlined); addFlags/frame sit in r13/r12 against the exe r12/r13, the CharToInteractiveObject null is xor not mov 0 (4 bytes), and the CreateCharacterInstance arg loads are scheduled differently (regalloc)
// @0x14292ea50
DisplayObjectBase* AvmSprite::AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                               const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                               const void* pinitSource, unsigned createFrame,
                                               unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                               InteractiveObject* origChar)
{
    MovieDefImpl* pdefImpl = GetSprite()->pDefImpl;

    bool placeObject = (addFlags & AddFlag_PlaceObject) != 0;
    bool replaceIfDepthIsOccupied = (addFlags & AddFlag_ReplaceIfDepthIsOccupied) != 0;

    CharacterCreateInfo ccinfo = pcharCreateOverride ? *pcharCreateOverride :
        pdefImpl->GetCharacterCreateInfo(pos.CharacterId);
    if (!ccinfo.pCharDef)
    {
        GetSprite()->LogError("Sprite::AddDisplayObject() - unknown cid = %d", (int)pos.CharacterId.GetIdIndex());
        return 0;
    }

    bool markedForRemove = false;
    DisplayObjectBase* pexistingChar = GetSprite()->mDisplayList.GetDisplayObjectAtDepth(pos.Depth, &markedForRemove);

    unsigned frame = ((createFrame == (unsigned)-1) ? GetSprite()->GetCurrentFrame() : createFrame);
    if (placeObject)
    {
        bool animatedByTimeline = true;
        if (pexistingChar)
        {
            animatedByTimeline = pexistingChar->GetAcceptAnimMoves();
            if (!animatedByTimeline && pexistingChar->GetContinueAnimationFlag())
            {
                pexistingChar->SetAcceptAnimMoves(true);
                animatedByTimeline = true;
            }
        }
        if (!markedForRemove && pexistingChar && !pexistingChar->GetAcceptAnimMoves())
            return 0;

        if (pexistingChar && pexistingChar->Depth >= -1 &&
            (pexistingChar->Id == pos.CharacterId.GetIdValue()))
        {
            const ASString& originalName =
                ((pexistingChar->IsInteractiveObject()) ? static_cast<DisplayObject*>(pexistingChar)->GetOriginalName() :
                static_cast<MovieRoot*>(GetSprite()->pASRoot)->GetStringManager()->GetBuiltin(ASBuiltin_empty_));

            if (!pexistingChar->IsInteractiveObject() ||
                (name.IsEmpty() && originalName.IsEmpty()) ||
                (name.IsEmpty() && static_cast<DisplayObject*>(pexistingChar)->IsInstanceBasedNameFlagSet()) ||
                (!name.IsEmpty() && originalName.GetNode() == name.GetNode()))
            {
                if (pexistingChar->CreateFrame == frame)
                {
                    CharPosInfo newPos = pos;
                    if (!pos.Flags.HasBlendMode() && pexistingChar->GetBlendMode() != 0)
                    {
                        newPos.Flags.SetBlendModeFlag();
                        newPos.BlendMode = 0;
                    }
                    if (!pos.Flags.HasCxform() && !pexistingChar->GetCxform().IsIdentity())
                    {
                        newPos.Flags.SetCxFormFlag();
                        newPos.ColorTransform.SetIdentity();
                    }

                    GetSprite()->MoveDisplayObject(newPos);
                    return 0;
                }
                replaceIfDepthIsOccupied = 1;
            }
        }
    }
    else
    {
        replaceIfDepthIsOccupied = 1;
    }
    FUN_1425dcaf0(GetSprite());

    Ptr<DisplayObjectBase> ch = *GetSprite()->pASRoot->pASSupport->CreateCharacterInstance(
        GetSprite()->pASRoot->pMovieImpl, ccinfo, GetSprite(), pos.CharacterId);
    InteractiveObject* intObj = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch.GetPtr()) : 0;
    bool               nameSet = 0;

    ch->Flags &= ~1;

    if (intObj)
    {
        if (!name.IsEmpty())
        {
            static_cast<DisplayObject*>(intObj)->SetOriginalName(name);
            nameSet = 1;
        }
        if (origChar)
            intObj->CloneInternalData(origChar);
        if (!(addFlags & AddFlag_PlaceObject))
            intObj->SetAcceptAnimMoves(false);
        else
            static_cast<DisplayObject*>(intObj)->Flags |= DisplayObject::Mask_TimelineObject;
    }

    ch->CreateFrame = frame;

    unsigned sessionId = 0;
    if (intObj)
        sessionId = OnAddingDisplayObject(ccinfo, intObj, peventHandlers, pinitSource, placeObject);

    addFlags &= ~AddFlag_ReplaceIfDepthIsOccupied;
    if (replaceIfDepthIsOccupied)
        addFlags |= AddFlag_ReplaceIfDepthIsOccupied;

    if (intObj)
    {
        intObj->AddToPlayList();
        AS3::Sfr34_ModifyOptimizedPlayList(intObj);
    }

    GetSprite()->mDisplayList.AddDisplayObject(GetSprite(), pos, ch.GetPtr(), (unsigned)addFlags);

    if (nameSet)
        GetSprite()->pASRoot->ResolveStickyVariables(intObj);

    if (intObj)
    {
        Sprite* pspriteCh = intObj->IsSprite() ? static_cast<Sprite*>(intObj) : 0;
        if (intObj && !placeObject)
        {
            static_cast<MovieRoot*>(GetSprite()->pASRoot)->DoActionsForSession(sessionId);
            if (pspriteCh && pspriteCh->HasEventHandler(EventId(EventId::Event_Load)))
                pspriteCh->Flags |= Sprite::Flags_OnLoadReqd;
        }
        else
        {
            if (pspriteCh)
                pspriteCh->Flags |= Sprite::Flags_OnLoadReqd;
        }
    }

    if (intObj && nameSet)
    {
        if (name.GetNode() ==
            static_cast<MovieRoot*>(GetSprite()->pASRoot)->GetStringManager()->GetBuiltin(ASBuiltin_hitArea).GetNode())
            GetSprite()->SetHitArea(static_cast<Sprite*>(intObj));
    }
    return ch.GetPtr();
}

}}} // namespace Scaleform::GFx::AS2
