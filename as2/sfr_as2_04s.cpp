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

namespace Scaleform { namespace GFx { namespace AS2 {

// The empty hook the exe calls on the clip after a new object was bound (exe 0x1425dcaf0, a bare ret).
void FUN_1425dcaf0(void* pobj);

// addFlags of AddDisplayObject (the same bits the Sprite entry forwards).
enum
{
    AddFlag_NamedChild    = 0x01, // DisplayList::AddDisplayObject: the child has an instance name
    AddFlag_PlaceObject   = 0x04  // placed by a tag (the child keeps accepting timeline moves)
};

// MS2-FUNCTIONAL: raw ASString node counting and the folded empty hook; behaviour follows the exe
// @0x14292ea50
DisplayObjectBase* AvmSprite::AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                               const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                               const void* pinitSource, unsigned createFrame,
                                               unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                               InteractiveObject* origChar)
{
    Sprite* psprite = GetSprite();
    bool    placeObject = (addFlags & AddFlag_PlaceObject) != 0;

    CharacterCreateInfo ccinfo;
    if (pcharCreateOverride)
        ccinfo = *pcharCreateOverride;
    else
        ccinfo = psprite->pDefImpl->GetCharacterCreateInfo(pos.CharacterId);

    if (!ccinfo.pCharDef)
    {
        psprite->LogError("Sprite::AddDisplayObject() - unknown cid = %d", (int)pos.CharacterId.GetIdIndex());
        return 0;
    }

    bool               markedForRemove = false;
    DisplayObjectBase* pexisting = psprite->mDisplayList.GetDisplayObjectAtDepth(pos.Depth, &markedForRemove);
    if (createFrame == (unsigned)-1)
        createFrame = psprite->GetCurrentFrame();

    if (placeObject)
    {
        if (pexisting && !pexisting->GetAcceptAnimMoves() && pexisting->GetContinueAnimationFlag())
            pexisting->SetAcceptAnimMoves(true);
        if (!markedForRemove && pexisting && !pexisting->GetAcceptAnimMoves())
            return 0;
        {
            if (pexisting && pexisting->Depth > -2 && pexisting->Id == pos.CharacterId.GetIdIndex())
            {
                // The same character again: it is moved instead of replaced when the instance name agrees.
                bool    isChar   = pexisting->IsInteractiveObject();
                ASString current = isChar ? static_cast<DisplayObject*>(pexisting)->GetOriginalName()
                                          : static_cast<MovieRoot*>(psprite->pASRoot)->GetStringManager()->GetBuiltin(ASBuiltin_empty_);
                bool sameName;
                if (!isChar)
                    sameName = true;
                else if (name.IsEmpty())
                    sameName = current.IsEmpty() || static_cast<DisplayObject*>(pexisting)->IsInstanceBasedNameFlagSet();
                else
                    sameName = current.GetNode() == name.GetNode();

                if (sameName && pexisting->CreateFrame == createFrame)
                {
                    CharPosInfo move = pos;
                    if (!move.Flags.HasBlendMode() && pexisting->GetBlendMode() != 0)
                    {
                        move.BlendMode = 0;
                        move.Flags.SetBlendModeFlag();
                    }
                    if (!move.Flags.HasCxform() && !pexisting->GetCxform().IsIdentity())
                    {
                        move.Flags.SetCxFormFlag();
                        move.ColorTransform.SetIdentity();
                    }
                    psprite->MoveDisplayObject(move);
                    return 0;
                }
            }
        }
    }

    FUN_1425dcaf0(psprite);
    DisplayObjectBase* pch = psprite->pASRoot->pASSupport->CreateCharacterInstance(
        psprite->pASRoot->pMovieImpl, ccinfo, psprite, pos.CharacterId);

    InteractiveObject* pich = pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
    pch->Flags &= ~1;
    bool hasName = false;
    if (pich)
    {
        hasName = !name.IsEmpty();
        if (hasName)
            static_cast<DisplayObject*>(pich)->SetOriginalName(name);
        if (origChar)
            pich->CloneInternalData(origChar);
        if (!placeObject)
            pich->SetAcceptAnimMoves(false);
        else
            static_cast<DisplayObject*>(pich)->Flags |= DisplayObject::Mask_TimelineObject;
    }
    pch->CreateFrame = createFrame;

    unsigned sessionId = 0;
    if (pich)
    {
        sessionId = OnAddingDisplayObject(ccinfo, pich, peventHandlers, pinitSource, placeObject);
        pich->AddToPlayList();
        pich->ModifyOptimizedPlayList();
    }
    unsigned listFlags = (unsigned)addFlags & ~1u;
    if (hasName)
        listFlags |= AddFlag_NamedChild;
    psprite->mDisplayList.AddDisplayObject(psprite, pos, pch, listFlags);
    if (hasName)
        psprite->pASRoot->ResolveStickyVariables(pich);
    if (!pich)
        return pch;

    Sprite* pspriteCh = pich->IsSprite() ? static_cast<Sprite*>(pich) : 0;
    bool    needOnLoad;
    if (!placeObject)
    {
        static_cast<MovieRoot*>(psprite->pASRoot)->DoActionsForSession(sessionId);
        needOnLoad = pspriteCh && pspriteCh->HasEventHandler(EventId(EventId::Event_Load));
    }
    else
        needOnLoad = pspriteCh != 0;
    if (needOnLoad)
        pspriteCh->Flags |= Sprite::Flags_OnLoadReqd;

    if (hasName &&
        name.GetNode() ==
            static_cast<MovieRoot*>(psprite->pASRoot)->GetStringManager()->GetBuiltin(ASBuiltin_hitArea).GetNode())
        psprite->SetHitArea(static_cast<Sprite*>(pich));
    return pch;
}

}}} // namespace Scaleform::GFx::AS2
