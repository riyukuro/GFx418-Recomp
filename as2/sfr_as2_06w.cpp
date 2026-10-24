// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr36): SetStandardMember of AvmButton, AvmCharacter and AvmSprite, the built-in property setters behind
// setProperty and the "_x"/"blendMode"/... members of buttons and clips.
// MS2-UNIT: sfr_as2_06w
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298a880-0x14298b97c .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/render/render_filters.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The script side of a button (partial local copy; the other units carry their own).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual bool SetStandardMember(StandardMember index, const Value& val, bool opcodeFlag);

private:
    ButtonObject* GetButtonASObject();
};

namespace {

// The blendMode names by Render::BlendMode (0 and 1 are both "normal").
const char* BlendModeNames[] = {"normal",     "normal", "layer",    "multiply", "screen",
                                "lighten",    "darken", "difference", "add",    "subtract",
                                "invert",     "alpha",  "erase",    "overlay",  "hardlight"};

// A watch on the built-in property of pobj may replace the value being set.
SF_FORCEINLINE void InvokeMemberWatchpoint(Object* pobj, Environment* penv, AvmCharacter::StandardMember index,
                                           Value& val)
{
    Value newVal;
    if (pobj->InvokeWatchpoint(penv, penv->CreateConstString(AvmCharacter::MemberTable[index].pName), val, &newVal))
        val = newVal;
}

// A Rectangle object's bounds in twips, for scale9Grid.
SF_FORCEINLINE RectF RectangleToGridTwips(Object* pobj, Environment* penv)
{
    ASRect r(0, 0, 0, 0);
    static_cast<RectangleObject*>(pobj)->GetProperties(penv, r);
    const float x1 = Render::PixelsToTwips(float(r.x1));
    const float y1 = Render::PixelsToTwips(float(r.y1));
    return RectF(x1, y1, Render::PixelsToTwips(float(r.x2 - r.x1)) + x1, Render::PixelsToTwips(float(r.y2 - r.y1)) + y1);
}

} // namespace

// The button's watched properties go through the watchpoints of its AS object first; then the common setters,
// scale9Grid (SWF 8) and the hitTestDisable extension.
// @0x14298a880
bool AvmButton::SetStandardMember(StandardMember index, const Value& origVal, bool opcodeFlag)
{
    Value        val(origVal);
    Environment* penv = GetASEnvironment();
    if (index > M_BuiltInProperty_End && penv)
    {
        ButtonObject* pobj = GetButtonASObject();
        if (pobj && ASButtonObj->pWatchpoints)
            InvokeMemberWatchpoint(ASButtonObj, penv, index, val);
    }

    if (AvmCharacter::SetStandardMember(index, val, opcodeFlag))
        return true;

    switch (index)
    {
    case M_scale9Grid:
        if (GetASEnvironment()->GetVersion() >= 8)
        {
            Environment* penv = GetASEnvironment();
            Object*      pobj = val.ToObject(penv);
            if (pobj && pobj->GetObjectType() == Object::Object_Rectangle)
                pDispObj->SetScale9Grid(RectangleToGridTwips(pobj, penv));
            else
                pDispObj->SetScale9Grid(RectF(0, 0, 0, 0));
            return true;
        }
        break;

    case M_hitTestDisable:
        if (GetASEnvironment()->CheckExtensions())
        {
            InteractiveObject* pch = pDispObj;
            if (val.ToBool(GetASEnvironment()))
                pch->Flags |= InteractiveObject::Mask_HitTestDisable;
            else
                pch->Flags &= ~InteractiveObject::Mask_HitTestDisable;
            return true;
        }
        break;

    default:
        break;
    }
    return false;
}

// The properties every character has. opcodeFlag (setProperty) only reaches the first 22; the rest are set when
// the bit mask of the character kind has them.
// MS2-FUNCTIONAL: the exe compares the blend mode names with an inlined strcmp
// @0x14298ab80
bool AvmCharacter::SetStandardMember(StandardMember index, const Value& val, bool opcodeFlag)
{
    if (opcodeFlag && (unsigned)index > M_BuiltInProperty_End)
    {
        pDispObj->LogScriptWarning("Invalid SetProperty request, property number %d", index);
        return false;
    }
    if (index == M_InvalidMember || index > M_LastBitMaskMember ||
        !((GetStandardMemberBitMask() >> index) & 1))
        return false;

    Environment* penv = GetASEnvironment();
    switch (index)
    {
    case M_x:
        if (!val.IsUndefined())
            pDispObj->SetX(val.ToNumber(penv));
        break;
    case M_y:
        if (!val.IsUndefined())
            pDispObj->SetY(val.ToNumber(penv));
        break;
    case M_xscale:
        if (!val.IsUndefined())
            pDispObj->SetXScale(val.ToNumber(penv));
        break;
    case M_yscale:
        if (!val.IsUndefined())
            pDispObj->SetYScale(val.ToNumber(penv));
        break;

    case M_currentframe:
    case M_totalframes:
    case M_target:
    case M_framesloaded:
    case M_droptarget:
    case M_url:
    case M_xmouse:
    case M_ymouse:
    case M_parent:
        penv->LogScriptWarning("Attempt to write read-only property %s.%s, ignored", pDispObj->GetName().ToCStr(),
                               MemberTable[index].pName);
        break;

    case M_alpha:
        if (!val.IsUndefined())
            pDispObj->SetAlpha(val.ToNumber(penv));
        break;
    case M_visible:
        pDispObj->SetVisible(val.ToBool(penv));
        break;
    case M_width:
        if (!val.IsUndefined())
            pDispObj->SetWidth(val.ToNumber(penv));
        break;
    case M_height:
        if (!val.IsUndefined())
            pDispObj->SetHeight(val.ToNumber(penv));
        break;
    case M_rotation:
        if (!val.IsUndefined())
            pDispObj->SetRotation(val.ToNumber(penv));
        break;
    case M_name:
        pDispObj->SetName(val.ToString(penv));
        break;

    case M_highquality:
    case M_soundbuftime:
    case M_quality:
        break;

    case M_focusrect:
        if (!val.IsUndefined())
            pDispObj->SetFocusRectFlag(val.ToBool(GetASEnvironment()));
        else
            // the exe clears the tabEnabled bits here
            pDispObj->Flags &= ~InteractiveObject::Mask_TabEnabled;
        pDispObj->SetDirtyFlag();
        break;

    case M_blendMode:
        if (!val.IsString())
        {
            int mode = (int)val.ToNumber(penv);
            mode     = Alg::Max(1, Alg::Min(mode, 14));
            pDispObj->SetBlendMode((Render::BlendMode)mode);
        }
        else
        {
            String asstr(val.ToString(penv).ToCStr());
            for (unsigned i = 1; i < 15; i++)
            {
                if (asstr == BlendModeNames[i])
                {
                    pDispObj->SetBlendMode((Render::BlendMode)i);
                    break;
                }
            }
        }
        break;

    case M_filters:
    {
        Object* pobj = val.ToObject(penv);
        if (pobj && pobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_Array)))
        {
            Ptr<Render::FilterSet> filters = *SF_NEW Render::FilterSet();
            ArrayObject*           parr    = static_cast<ArrayObject*>(pobj);
            for (int i = 0; i < parr->GetSize(); i++)
            {
                Value* pelem = parr->GetElementPtr(i);
                if (!pelem)
                    continue;
                Object* pfobj = pelem->ToObject(penv);
                if (pfobj && pfobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_BitmapFilter)))
                {
                    Ptr<Render::Filter> pfilter = static_cast<BitmapFilterObject*>(pfobj)->GetFilter();
                    filters->AddFilter(pfilter);
                }
            }
            pDispObj->SetFilters(Ptr<Render::FilterSet>(filters));
            pDispObj->SetDirtyFlag();
            pDispObj->SetAcceptAnimMoves(false);
        }
        break;
    }

    case M_enabled:
        if (val.ToBool(penv))
            pDispObj->Flags |= InteractiveObject::Mask_Enabled;
        else
            pDispObj->Flags &= ~InteractiveObject::Mask_Enabled;
        break;
    case M_trackAsMenu:
        pDispObj->SetTrackAsMenuFlag(val.ToBool(penv));
        break;

    case M_tabEnabled:
        if (!val.IsUndefined())
        {
            if (val.ToBool(GetASEnvironment()))
                pDispObj->Flags |= InteractiveObject::Mask_TabEnabled;
            else
            {
                pDispObj->Flags &= ~0x20u;
                pDispObj->Flags |= 0x40u;
            }
        }
        else
            pDispObj->Flags &= ~InteractiveObject::Mask_TabEnabled;
        break;
    case M_tabIndex:
        pDispObj->TabIndex = (SInt16)(int)val.ToNumber(GetASEnvironment());
        break;
    case M_useHandCursor:
        if (!val.IsUndefined())
        {
            if (val.ToBool(GetASEnvironment()))
                pDispObj->Flags |= InteractiveObject::Mask_UseHandCursor;
            else
            {
                pDispObj->Flags &= ~0x200u;
                pDispObj->Flags |= 0x400u;
            }
        }
        else
            pDispObj->Flags &= ~InteractiveObject::Mask_UseHandCursor;
        break;

    case M_edgeaaMode:
    {
        Render::EdgeAAMode mode = Render::EdgeAA_Inherit;
        const Double       v    = (Double)val.ToInt32(GetASEnvironment());
        if (v == 3)
            mode = Render::EdgeAA_Disable;
        else if (v == 1)
            mode = Render::EdgeAA_On;
        else if (v == 2)
            mode = Render::EdgeAA_Off;
        pDispObj->GetRenderNode()->SetEdgeAAMode(mode);
        break;
    }

    default:
        return false;
    }
    return true;
}

// The clip's watched properties go through its MovieClip object first; then the common setters and the sprite
// ones: _lockroot, focusEnabled, tabChildren, scale9Grid / scrollRect (SWF 8), hitArea and hitTestDisable.
// MS2-FUNCTIONAL: the exe builds the watched name inline from the member table
// @0x14298b410
bool AvmSprite::SetStandardMember(StandardMember index, const Value& origVal, bool opcodeFlag)
{
    Value        val(origVal);
    Environment* penv = GetASEnvironment();
    if (index > M_BuiltInProperty_End && penv && pMovieClipObj && pMovieClipObj->pWatchpoints)
        InvokeMemberWatchpoint(pMovieClipObj, penv, index, val);

    if (AvmCharacter::SetStandardMember(index, val, opcodeFlag))
        return true;

    switch (index)
    {
    case M_currentframe:
    case M_totalframes:
    case M_framesloaded:
        return true;

    case M_lockroot:
    {
        Sprite* psprite = GetSprite();
        if (val.ToBool(GetASEnvironment()))
            psprite->Flags |= Sprite::Flags_LockRoot;
        else
            psprite->Flags &= ~Sprite::Flags_LockRoot;
        return true;
    }

    case M_focusEnabled:
    {
        Sprite* psprite = GetSprite();
        if (val.IsUndefined())
            psprite->FocusEnabled = 0;
        else
            psprite->FocusEnabled = val.ToBool(GetASEnvironment()) ? 1 : 2;
        return true;
    }

    case M_tabChildren:
        if (val.IsUndefined())
            Unrecovered_1f8 = 0;
        else
        {
            const bool tabChildren = val.ToBool(GetASEnvironment());
            *reinterpret_cast<UByte*>(&Unrecovered_1f8) = tabChildren ? 1 : 2;
            if (tabChildren)
                pDispObj->Flags &= ~InteractiveObject::Mask_TabChildrenDisabled;
            else
                pDispObj->Flags |= InteractiveObject::Mask_TabChildrenDisabled;
        }
        return true;

    case M_scale9Grid:
    {
        if (GetASEnvironment()->GetVersion() < 8)
            return false;
        Environment* penv = GetASEnvironment();
        Object*      pobj = val.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object::Object_Rectangle)
            pDispObj->SetScale9Grid(RectangleToGridTwips(pobj, penv));
        else
            pDispObj->SetScale9Grid(RectF(0, 0, 0, 0));
        return true;
    }

    case M_hitArea:
    {
        Environment* penv = GetASEnvironment();
        if (val.GetType() == Value::CHARACTER && penv && val.V.pCharHandle)
        {
            DisplayObject* pch = val.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            if (pch)
            {
                Sprite* phitArea = pch->IsInteractiveObject() ? static_cast<Sprite*>(pch) : 0;
                if (phitArea && phitArea->IsSprite())
                {
                    GetSprite()->SetHitArea(phitArea);
                    return true;
                }
            }
        }
        GetSprite()->SetHitArea(0);
        return false;
    }

    case M_scrollRect:
        if (GetASEnvironment()->GetVersion() >= 8)
        {
            Environment* penv = GetASEnvironment();
            Object*      pobj = val.ToObject(penv);
            if (!pobj)
                pDispObj->SetScrollRect(0);
            else if (pobj->GetObjectType() == Object::Object_Rectangle)
            {
                ASRect r(0, 0, 0, 0);
                static_cast<RectangleObject*>(pobj)->GetProperties(penv, r);
                const Double x1 = Render::PixelsToTwips(r.x1);
                const Double y1 = Render::PixelsToTwips(r.y1);
                Render::RectD rt(x1, y1, Render::PixelsToTwips(r.x2 - r.x1) + x1, Render::PixelsToTwips(r.y2 - r.y1) + y1);
                pDispObj->SetScrollRect(&rt);
            }
        }
        return false;

    case M_hitTestDisable:
        if (!GetASEnvironment()->CheckExtensions())
            return false;
        {
            InteractiveObject* pch = pDispObj;
            if (val.ToBool(GetASEnvironment()))
                pch->Flags |= InteractiveObject::Mask_HitTestDisable;
            else
                pch->Flags &= ~InteractiveObject::Mask_HitTestDisable;
        }
        return true;

    default:
        return false;
    }
}

}}} // namespace Scaleform::GFx::AS2
