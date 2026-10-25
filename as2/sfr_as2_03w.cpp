// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 movie clip script side
// constructor (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03w
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918980-0x142918b48 .text$mn
// MS2-RANGE: 0x142990e20-0x142990e23 .text$mn
// MS2-RANGE: 0x142990eb0-0x142990ebd .text$mn
// MS2-RANGE: 0x142990ce0-0x142990ce2 .text$mn
// MS2-RANGE: 0x142990ef0-0x142990ef2 .text$mn
// MS2-RANGE: 0x142990de0-0x142990ded .text$mn
// MS2-RANGE: 0x142949620-0x142949624 .text$mn
// MS2-RANGE: 0x14296bbb0-0x14296bbc5 .text$mn
// MS2-RANGE: 0x14296c0d0-0x14296c0d4 .text$mn
// MS2-RANGE: 0x14296c160-0x14296c162 .text$mn
// MS2-RANGE: 0x14296c1b0-0x14296c1b2 .text$mn
// MS2-RANGE: 0x14296c200-0x14296c202 .text$mn
// MS2-RANGE: 0x1429660a0-0x1429660a4 .text$mn
// MS2-RANGE: 0x142949470-0x142949475 .text$mn
// MS2-RANGE: 0x142949480-0x142949485 .text$mn
// MS2-RANGE: 0x142949410-0x142949414 .text$mn
// MS2-RANGE: 0x142949420-0x142949424 .text$mn
// MS2-RANGE: 0x142956070-0x142956075 .text$mn
// MS2-RANGE: 0x142954170-0x142954175 .text$mn
// MS2-RANGE: 0x1429413b0-0x1429413b2 .text$mn
// MS2-RANGE: 0x142945d80-0x142945d82 .text$mn
// MS2-RANGE: 0x14294b110-0x14294b116 .text$mn
// MS2-RANGE: 0x142965ce0-0x142965ceb .text$mn
// MS2-RANGE: 0x142933430-0x142933439 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The exe inlines the environment's construction and target binding here.
// MS2-FUNCTIONAL: member by member as in the exe, byte order of the stores differs
// @0x142918980
AvmSprite::AvmSprite(Sprite* psprite)
    : AvmCharacter(psprite), Level(-1), Unrecovered_1f8(false)
{
    Env.IsInvalidTarget = false;
    Env.Target          = psprite;
    Env.StringContext.UpdateVersion(psprite->GetVersion());
    Env.StringContext.pContext = GetGC();
    psprite->Sprite::Flags &= ~Sprite::Flags_LockRoot;
    psprite->InteractiveObject::Flags |= InteractiveObject::Mask_MovieClip;
    unsigned frames = psprite->pDef->GetFrameCount();
    InitActionsExecuted.Resize(frames);
    memset(&InitActionsExecuted[0], 0, frames);
    pProto = GetAS2Root()->pGlobalContext->GetActualPrototype(&Env, ASBuiltin_MovieClip);
}

// The small vftable overrides of AvmSprite (casts, focus stubs, level accessors).

// @0x142990e20
AvmInteractiveObjBase* AvmSprite::ToAvmInteractiveObjBase()
{
    return static_cast<AvmCharacter*>(this);
}

// @0x142990eb0
AvmSpriteBase* AvmSprite::ToAvmSpriteBase()
{
    return this;
}

// @0x142990ce0
AvmButtonBase* AvmSprite::ToAvmButttonBase()
{
    return 0;
}

// @0x142990ef0
AvmTextFieldBase* AvmSprite::ToAvmTextFieldBase()
{
    return 0;
}

// @0x142990de0
AvmDisplayObjContainerBase* AvmSprite::ToAvmDispContainerBase()
{
    return this;
}

// @0x142949620
const char* AvmSprite::GetAbsolutePath(String* ppath) const
{
    return AvmCharacter::GetAbsolutePath(ppath);
}

// @0x14296bbb0
void AvmSprite::OnEventUnload()
{
    Set__proto__(Env.GetSC(), 0);
}

// @0x14296c0d0
void AvmSprite::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                        unsigned controllerIdx, FocusMovedType fmt)
{
    AvmCharacter::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
}

// @0x14296c160
void AvmSprite::OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
{
}

// @0x14296c1b0
bool AvmSprite::OnKeyEvent(const EventId& id, int* pkeyMask)
{
    return false;
}

// @0x14296c200
bool AvmSprite::OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx, FocusMovedType fmt)
{
    return true;
}

// @0x1429660a0
bool AvmSprite::IsTabable() const
{
    return AvmCharacter::IsTabable();
}

// @0x142949470
Object* AvmSprite::GetASObject()
{
    return GetMovieClipObject();
}

// @0x142949480
Object* AvmSprite::GetASObject() const
{
    return const_cast<AvmSprite*>(this)->GetMovieClipObject();
}

// @0x142949410
Environment* AvmSprite::GetASEnvironment()
{
    return &Env;
}

// @0x142949420
const Environment* AvmSprite::GetASEnvironment() const
{
    return &Env;
}

// @0x142956070
unsigned AvmSprite::GetStandardMemberBitMask() const
{
    return (unsigned)-1;
}

// @0x142954170
ObjectInterface::ObjectType AvmSprite::GetObjectType() const
{
    return Object_Sprite;
}

// @0x1429413b0
void AvmSprite::ExecuteFrameTags(unsigned frame)
{
}

// @0x142945d80
void AvmSprite::ForceShutdown()
{
}

// @0x14294b110
int AvmSprite::GetLevel() const
{
    return Level;
}

// @0x142965ce0
bool AvmSprite::IsLevelMovie() const
{
    return Level >= 0;
}

// @0x142933430
bool AvmSprite::CheckCandidateListLevel(int level) const
{
    return Level == level;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x143215ad0
// MS2-PIN: ??_7Environment@AS2@GFx@Scaleform@@6B@ 0x143215ae0
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143216338
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216480
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6B@ 0x143216528
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143215b00
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215c48
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObjContainerBase@GFx@Scaleform@@6B@ 0x14317c0a0
// MS2-PIN: ??_7AvmSpriteBase@GFx@Scaleform@@6B@ 0x14317c898
