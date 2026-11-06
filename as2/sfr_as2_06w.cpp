// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr36): SetStandardMember of AvmButton, AvmCharacter and AvmSprite, the built-in property setters behind
// setProperty and the "_x"/"blendMode"/... members of buttons and clips.
// MS2-UNIT: sfr_as2_06w
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298a880-0x14298b97c .text$mn

// The SDK union GetData: the blendMode String dtor then shares the not-found tail as in the exe.
#define MS2_SF_STRING_SDK_GETDATA
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
// MS2-FUNCTIONAL: the exe computes the member table index before the watch value's ctor; same behavior
// @0x14298a880
bool AvmButton::SetStandardMember(StandardMember index, const Value& origVal, bool opcodeFlag)
{
    Value        val(origVal);
    Environment* penv = GetASEnvironment();
    if (index > M_BuiltInProperty_End && penv)
    {
        ButtonObject* pobj = GetButtonASObject();
        if (pobj && ASButtonObj->pWatchpoints)
        {
            Value newVal;
            if (ASButtonObj->InvokeWatchpoint(penv, penv->CreateConstString(MemberTable[index].pName), val, &newVal))
                val = newVal;
        }
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

// The flag setters of InteractiveObject (SetEnabledFlag, SetTabEnabledFlag, SetUseHandCursorFlag in the SDK) that
// our header lacks. The exe inlines them after ToBool and reads pDispObj only then.
static __forceinline void Sfr06wSetEnabledFlag(InteractiveObject* p, bool v)
{
    if (v)
        p->Flags |= InteractiveObject::Mask_Enabled;
    else
        p->Flags &= ~InteractiveObject::Mask_Enabled;
}

static __forceinline void Sfr06wSetTabEnabledFlag(InteractiveObject* p, bool v)
{
    (v) ? (p->Flags |= InteractiveObject::Mask_TabEnabled)
        : p->Flags = ((p->Flags & (~InteractiveObject::Mask_TabEnabled)) |
                      ((InteractiveObject::Mask_TabEnabled - 1) & InteractiveObject::Mask_TabEnabled));
}

static __forceinline void Sfr06wSetUseHandCursorFlag(InteractiveObject* p, bool v)
{
    (v) ? (p->Flags |= InteractiveObject::Mask_UseHandCursor)
        : p->Flags = ((p->Flags & (~InteractiveObject::Mask_UseHandCursor)) |
                      ((InteractiveObject::Mask_UseHandCursor - 1) & InteractiveObject::Mask_UseHandCursor));
}

// The properties every character has. opcodeFlag (setProperty) only reaches the first 22; the rest are set when
// the bit mask of the character kind has them. The body follows the SDK: each case returns 1 itself.
// @0x14298ab80
bool AvmCharacter::SetStandardMember(StandardMember index, const Value& val, bool opcodeFlag)
{
    if (opcodeFlag && (unsigned)index > M_BuiltInProperty_End)
    {
        pDispObj->LogScriptError("Invalid SetProperty request, property number %d", index);
        return 0;
    }
    if (index == M_InvalidMember)
        return 0;
    if (!((index <= M_LastBitMaskMember) && (GetStandardMemberBitMask() & (1 << index))))
        return 0;
    Environment* penv = GetASEnvironment();

    switch (index)
    {
    case M_x:
    {
        if (val.IsUndefined())
            return 1;
        Number xval = val.ToNumber(penv);
        pDispObj->SetX(xval);
        return 1;
    }

    case M_y:
    {
        if (val.IsUndefined())
            return 1;
        Number yval = val.ToNumber(penv);
        pDispObj->SetY(yval);
        return 1;
    }

    case M_xscale:
    {
        if (val.IsUndefined())
            return 1;
        Double newXScale = val.ToNumber(penv);
        pDispObj->SetXScale(newXScale);
        return 1;
    }

    case M_yscale:
    {
        if (val.IsUndefined())
            return 1;
        Double newYScale = val.ToNumber(penv);
        pDispObj->SetYScale(newYScale);
        return 1;
    }

    case M_rotation:
    {
        if (val.IsUndefined())
            return 1;
        Number rval = val.ToNumber(penv);
        pDispObj->SetRotation(rval);
        return 1;
    }

    case M_width:
    {
        if (val.IsUndefined())
            return 1;
        Number wval = val.ToNumber(penv);
        pDispObj->SetWidth(wval);
        return 1;
    }

    case M_height:
    {
        if (val.IsUndefined())
            return 1;
        Number hval = val.ToNumber(penv);
        pDispObj->SetHeight(hval);
        return 1;
    }

    case M_alpha:
    {
        if (val.IsUndefined())
            return 1;
        Number aval = val.ToNumber(penv);
        pDispObj->SetAlpha(aval);
        return 1;
    }

    case M_visible:
    {
        pDispObj->SetVisible(val.ToBool(penv));
        return 1;
    }

    case M_blendMode:
    {
        if (val.GetType() == Value::STRING)
        {
            ASString asstr(val.ToString(penv));
            String   str = asstr.ToCStr();
            for (unsigned i = 1; i < (sizeof(BlendModeNames) / sizeof(BlendModeNames[0])); i++)
            {
                if (str == BlendModeNames[i])
                {
                    pDispObj->SetBlendMode((Render::BlendMode)i);
                    return 1;
                }
            }
        }
        else
        {
            int mode = (int)val.ToNumber(penv);
            mode     = Alg::Max<int>(Alg::Min<int>(mode, 14), 1);
            pDispObj->SetBlendMode((Render::BlendMode)mode);
        }
        return 1;
    }

    case M_name:
    {
        pDispObj->SetName(val.ToString(penv));
        return 1;
    }

    case M_enabled:
    {
        Sfr06wSetEnabledFlag(pDispObj, val.ToBool(penv));
        return 1;
    }

    case M_trackAsMenu:
    {
        pDispObj->SetTrackAsMenuFlag(val.ToBool(penv));
        return 1;
    }

    case M_droptarget:
    case M_target:
    case M_url:
    case M_xmouse:
    case M_ymouse:
    case M_parent:
    case M_currentframe:
    case M_totalframes:
    case M_framesloaded:
        penv->LogScriptWarning("Attempt to write read-only property %s.%s, ignored", pDispObj->GetName().ToCStr(),
                               AvmCharacter::MemberTable[index].pName);
        return 1;

    case M_tabEnabled:
        if (!val.IsUndefined())
        {
            Sfr06wSetTabEnabledFlag(pDispObj, val.ToBool(GetASEnvironment()));
        }
        else
            pDispObj->Flags &= (~InteractiveObject::Mask_TabEnabled);
        return 1;

    case M_tabIndex:
        pDispObj->TabIndex = (SInt16)(int)val.ToNumber(GetASEnvironment());
        return 1;

    case M_focusrect:
        if (!val.IsUndefined())
            pDispObj->SetFocusRectFlag(val.ToBool(GetASEnvironment()));
        else
            pDispObj->Flags &= (~InteractiveObject::Mask_TabEnabled);
        pDispObj->SetDirtyFlag();
        return 1;

    case M_soundbuftime:
    case M_highquality:
    case M_quality:
        return 1;

    case M_useHandCursor:
        if (!val.IsUndefined())
        {
            Sfr06wSetUseHandCursorFlag(pDispObj, val.ToBool(GetASEnvironment()));
        }
        else
            pDispObj->Flags &= (~InteractiveObject::Mask_UseHandCursor);
        return 1;

    case M_filters:
    {
        Object* pobj = val.ToObject(penv);
        if (pobj && pobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_Array)))
        {
            ArrayObject*           parrobj    = static_cast<ArrayObject*>(pobj);
            Ptr<Render::FilterSet> newfilters = *SF_NEW Render::FilterSet();
            for (int i = 0; i < parrobj->GetSize(); ++i)
            {
                Value* arrval = parrobj->GetElementPtr(i);
                if (arrval)
                {
                    Object* pavobj = arrval->ToObject(penv);
                    if (pavobj && pavobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_BitmapFilter)))
                    {
                        BitmapFilterObject* pfilterobj = static_cast<BitmapFilterObject*>(pavobj);
                        newfilters->AddFilter(pfilterobj->GetFilter());
                    }
                }
            }
            pDispObj->SetFilters(Ptr<Render::FilterSet>(newfilters));
            pDispObj->SetDirtyFlag();
            pDispObj->SetAcceptAnimMoves(false);
        }
        return 1;
    }

    case M_edgeaaMode:
    {
        Render::EdgeAAMode edgeAA = Render::EdgeAA_Inherit;
        Double             mode   = (Double)val.ToInt32(GetASEnvironment());
        if (mode == 3)
            edgeAA = Render::EdgeAA_Disable;
        else
        {
            if (mode == 1)
                edgeAA = Render::EdgeAA_On;
            else if (mode == 2)
                edgeAA = Render::EdgeAA_Off;
        }
        pDispObj->GetRenderNode()->SetEdgeAAMode(edgeAA);
        return 1;
    }

    default:
        return 0;
    }
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
