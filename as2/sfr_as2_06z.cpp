// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextField: a member set on a
// text field, its text, format, layout, style sheet, filters and the GFx extension properties (gap recovery of
// sfr_as2_06).
// MS2-UNIT: sfr_as2_06z
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142983360-0x142984fa6 .text$mn
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@UTextFilter@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_7TextFilter@Text@Render@Scaleform@@6B@ 0x1431899f8

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/text_editorkit.h"
#include "../include/render/text_docview.h"
#include "../include/render/render_twips.h"
#include "../include/render/text_filterdesc.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// vftable of AvmTextField::CSSHolder, the AS2 side's style sheet holder (deleting destructor exe 0x14292a0e0)
extern void* const AvmTextFieldCSSHolder_vftable[];

namespace {

// The text field members of the MemberTable (after the character ones).
const int Member_LastCharacterMember = 21;
const int Member_text                = 0x28;
const int Member_textColor           = 0x2b;
const int Member_html                = 0x2d;
const int Member_htmlText            = 0x2e;
const int Member_styleSheet          = 0x2f;
const int Member_autoSize            = 0x30;
const int Member_wordWrap            = 0x31;
const int Member_multiline           = 0x32;
const int Member_border              = 0x33;
const int Member_variable            = 0x34;
const int Member_selectable          = 0x35;
const int Member_embedFonts          = 0x36;
const int Member_antiAliasType       = 0x37;
const int Member_hscroll             = 0x38;
const int Member_scroll              = 0x39;
const int Member_background          = 0x3c;
const int Member_backgroundColor     = 0x3d;
const int Member_borderColor         = 0x3e;
const int Member_type                = 0x40;
const int Member_maxChars            = 0x41;
const int Member_condenseWhite       = 0x42;
const int Member_mouseWheelEnabled   = 0x43;
const int Member_password            = 0x44;
// GFx extensions
const int Member_shadowStyle         = 0x45;
const int Member_shadowColor         = 0x46;
const int Member_hitTestDisable      = 0x47;
const int Member_noTranslate         = 0x48;
const int Member_verticalAutoSize    = 0x4b;
const int Member_fontScaleFactor     = 0x4c;
const int Member_verticalAlign       = 0x4d;
const int Member_textAutoSize        = 0x4e;
const int Member_useRichTextClipboard = 0x4f;
const int Member_alwaysShowSelection = 0x50;
const int Member_selectionBkgColor   = 0x53; // the four selection colors
const int Member_selectionTextColor  = 0x54;
const int Member_inactiveSelectionBkgColor  = 0x55;
const int Member_inactiveSelectionTextColor = 0x56;
const int Member_noAutoSelection     = 0x57;
const int Member_disableIME          = 0x58;
const int Member_autoFit             = 0x5c;
const int Member_blurX               = 0x5d;
const int Member_blurY               = 0x5e;
const int Member_blurStrength        = 0x5f;
const int Member_outline             = 0x60;
const int Member_fauxBold            = 0x61;
const int Member_fauxItalic          = 0x62;
const int Member_restrict            = 0x63;
const int Member_shadowAlpha         = 0x64;
const int Member_shadowAngle         = 0x65;
const int Member_shadowBlurX         = 0x66;
const int Member_shadowBlurY         = 0x67;
const int Member_shadowDistance      = 0x68;
const int Member_shadowHideObject    = 0x69;
const int Member_shadowKnockOut      = 0x6a;
const int Member_shadowQuality       = 0x6b;
const int Member_shadowStrength      = 0x6c;

const float DegToRad = 0.017453292f;

// The AS2 style sheet holder: the URL zones of CSSHolderBase, then the StyleSheet object (0x48 bytes).
struct AS2CSSHolder
{
    void* const*          vfptr;
    UByte                 BaseData[0x38];
    Ptr<StyleSheetObject> pASStyleSheet; // +0x40
};

AS2CSSHolder* CSSHolderOf(TextField* ptf)
{
    return reinterpret_cast<AS2CSSHolder*>(ptf->GetCSSData());
}

Text::EditorKit* EditorKitOf(TextField* ptf)
{
    return static_cast<Text::EditorKit*>(ptf->GetDocument()->GetEditorKit());
}

Render::Text::TextFilter& FilterOf(Render::Text::DocView* pdoc)
{
    return const_cast<Render::Text::TextFilter&>(pdoc->GetFilters());
}

typedef Render::Text::DocView DocView;

// A name against a property value: by node when the movie is case sensitive (SWF 7+), else by lowercase twin.
bool NameEquals(Environment* penv, const ASString& str, const char* pname)
{
    ASString name = penv->CreateConstString(pname);
    bool     caseSensitive = penv->IsCaseSensitive();
    if (!caseSensitive)
        name.ResolveLowercase();
    return name.CompareBuiltIn_CaseCheck(str, caseSensitive);
}

// "" before SWF 7, "undefined" from 7 on.
const ASString& UndefinedText(Environment* penv, unsigned version)
{
    return (version - 1 < 6) ? penv->GetBuiltin(ASBuiltin_empty_) : penv->GetBuiltin(ASBuiltin_undefined);
}

void SetFlag(UInt32& flags, UInt32 mask, bool on)
{
    if (on)
        flags |= mask;
    else
        flags &= ~mask;
}

// The SDK's header-inline TextField members, which the exe inlines here.
SF_FORCEINLINE void TF_SetFlag(TextField* ptf, UInt32 mask, bool v)
{
    (v) ? ptf->Flags |= mask : ptf->Flags &= (~mask);
}
SF_FORCEINLINE void TF_SetHtml(TextField* ptf, bool v)                { TF_SetFlag(ptf, TextField::Flags_Html, v); }
SF_FORCEINLINE void TF_SetAutoSize(TextField* ptf, bool v)            { TF_SetFlag(ptf, TextField::Flags_AutoSize, v); }
SF_FORCEINLINE bool TF_IsAutoSize(TextField* ptf)                     { return (ptf->Flags & TextField::Flags_AutoSize) != 0; }
SF_FORCEINLINE void TF_SetPassword(TextField* ptf, bool v)            { TF_SetFlag(ptf, TextField::Flags_Password, v); }
SF_FORCEINLINE void TF_SetCondenseWhite(TextField* ptf, bool v)       { TF_SetFlag(ptf, TextField::Flags_CondenseWhite, v); }
SF_FORCEINLINE void TF_SetMouseWheelEnabled(TextField* ptf, bool v)   { TF_SetFlag(ptf, TextField::Flags_MouseWheelEnabled, v); }
SF_FORCEINLINE void TF_SetNoTranslate(TextField* ptf, bool v)         { TF_SetFlag(ptf, TextField::Flags_NoTranslate, v); }
SF_FORCEINLINE void TF_SetUseRichClipboard(TextField* ptf, bool v)    { TF_SetFlag(ptf, TextField::Flags_UseRichClipboard, v); }
SF_FORCEINLINE bool TF_DoesUseRichClipboard(TextField* ptf)           { return (ptf->Flags & TextField::Flags_UseRichClipboard) != 0; }
SF_FORCEINLINE void TF_SetAlwaysShowSelection(TextField* ptf, bool v) { TF_SetFlag(ptf, TextField::Flags_AlwaysShowSelection, v); }
SF_FORCEINLINE void TF_SetNoAutoSelection(TextField* ptf, bool v)     { TF_SetFlag(ptf, TextField::Flags_NoAutoSelection, v); }
SF_FORCEINLINE void TF_SetIMEDisabledFlag(TextField* ptf, bool v)     { TF_SetFlag(ptf, TextField::Flags_IMEDisabled, v); }
SF_FORCEINLINE void TF_SetForceAdvance(TextField* ptf)                { TF_SetFlag(ptf, TextField::Flags_ForceAdvance, true); }
SF_FORCEINLINE void TF_SetNeedUpdateLayoutFlag(TextField* ptf)        { TF_SetFlag(ptf, TextField::Flags_NeedUpdateLayout, true); }
SF_FORCEINLINE void TF_SetHitTestDisableFlag(TextField* ptf, bool v)
{
    InteractiveObject* pio = ptf;
    (v) ? pio->Flags |= InteractiveObject::Mask_HitTestDisable : pio->Flags &= (~InteractiveObject::Mask_HitTestDisable);
}
SF_FORCEINLINE void TF_SetNeedUpdateGeomData(TextField* ptf)
{
    ptf->Flags |= TextField::Flags_NeedUpdateGeomData;
    ptf->SetDirtyFlag();
}
SF_FORCEINLINE Text::EditorKit* TF_GetEditorKit(TextField* ptf)
{
    return static_cast<Text::EditorKit*>(ptf->GetDocument()->GetEditorKit());
}
SF_FORCEINLINE void TF_SetHScrollOffset(TextField* ptf, Double hs)
{
    ptf->GetDocument()->SetHScrollOffset((unsigned)Render::PixelsToTwips(hs));
}

// The SDK's DocView shadow setters this DocView lacks.
SF_FORCEINLINE void TF_EnableSoftShadow(TextField* ptf)       { FilterOf(ptf->GetDocument()).ShadowFlags &= ~1u; }
SF_FORCEINLINE void TF_SetShadowFlag(TextField* ptf, unsigned mask, bool f)
{
    Render::Text::TextFilter& filter = FilterOf(ptf->GetDocument());
    if (f) filter.ShadowFlags |= mask; else filter.ShadowFlags &= ~mask;
}
SF_FORCEINLINE void TF_SetShadowQuality(TextField* ptf, unsigned v)
{
    Render::Text::TextFilter& filter = FilterOf(ptf->GetDocument());
    if (v > 1) filter.ShadowFlags |= Render::BlurFilterParams::Mode_Highlight;
    else filter.ShadowFlags &= ~Render::BlurFilterParams::Mode_Highlight;
}
SF_FORCEINLINE void TF_SetShadowAngle(TextField* ptf, float a)
{
    Render::Text::TextFilter& filter = FilterOf(ptf->GetDocument());
    filter.ShadowAngle = a;
    filter.UpdateShadowOffset();
}
SF_FORCEINLINE void TF_SetShadowDistance(TextField* ptf, float d)
{
    Render::Text::TextFilter& filter = FilterOf(ptf->GetDocument());
    filter.ShadowDistance = d;
    filter.UpdateShadowOffset();
}
SF_FORCEINLINE float ClampF(float v, float lo, float hi)
{
    float m = (v < hi) ? v : hi;
    return (m < lo) ? lo : m;
}
SF_FORCEINLINE void TF_SetShadowAlpha(TextField* ptf, float a)
{
    Render::Text::TextFilter& filter = FilterOf(ptf->GetDocument());
    filter.ShadowAlpha = UByte(ClampF(a * 255.0f, 0.0f, 255.0f));
    filter.ShadowParams.Colors[0].SetAlpha(filter.ShadowAlpha);
}

// Value::ToStringVersioned, which the exe inlines here.
SF_FORCEINLINE ASString ToStringVersionedInline(const Value& val, Environment* penv, unsigned version)
{
    if (val.IsUndefined())
    {
        if (version > 0 && version <= 6)
            return penv->GetBuiltin(ASBuiltin_empty_);
        else
            return penv->GetBuiltin(ASBuiltin_undefined);
    }
    return val.ToString(penv);
}

// The AS2 CSSHolder constructor (the URL zones zeroed, then the style sheet pointer).
SF_FORCEINLINE TextField::CSSHolderBase* NewCSSHolder()
{
    AS2CSSHolder* pcss = (AS2CSSHolder*)Memory::Alloc(sizeof(AS2CSSHolder));
    if (pcss)
    {
        memset(pcss, 0, sizeof(AS2CSSHolder));
        pcss->vfptr = AvmTextFieldCSSHolder_vftable;
    }
    return reinterpret_cast<TextField::CSSHolderBase*>(pcss);
}

// StyleSheetObject::IsLoading: the loader state at +0x90.
SF_FORCEINLINE bool IsStyleSheetLoading(StyleSheetObject* psheet)
{
    return *(const int*)((const UByte*)psheet + 0x90) == 1;
}

} // namespace

// The watchpoints of the field's AS object see the text field members first. A member the character does not
// take is a text field property; the GFx extension ones need the extensions on, the rest go to the character.
// MS2-FUNCTIONAL: SDK body; the callee-saved registers are permuted (this/ptf/penv/name) and the case blocks
// at offsets 0x810-0xc90 are laid out differently, 7496 vs 7576 bytes.
// @0x142983360
bool AvmTextField::SetMember(Environment* penv, const ASString& name, const Value& origVal, const PropFlags& flags)
{
    StandardMember member = GetStandardMemberConstant(name);

    Value val(origVal);
    if ((int)member < 0 || member > M_BuiltInProperty_End)
    {
        if (penv && GetTextFieldASObject() && ASTextFieldObj->pWatchpoints)
        {
            Value newVal;
            if (ASTextFieldObj->InvokeWatchpoint(penv, name, val, &newVal))
            {
                val = newVal;
            }
        }
    }

    if (SetStandardMember(member, origVal, false))
        return true;

    TextField* ptf = static_cast<TextField*>(pDispObj);
    switch ((int)member)
    {
    case Member_html:
        TF_SetHtml(ptf, val.ToBool(penv));
        return true;

    case Member_htmlText:
        {
            ASString str(ToStringVersionedInline(val, penv, pDispObj->GetVersion()));
            ptf->SetTextValue(str.ToCStr(), ptf->IsHtml());
            return true;
        }

    case Member_text:
        {
            ptf->ResetBlink(1);
            ASString str(ToStringVersionedInline(val, penv, pDispObj->GetVersion()));
            ptf->SetTextValue(str.ToCStr(), false);
            return true;
        }

    case Member_textColor:
        {
            UInt32 rgb = val.ToUInt32(penv);
            ptf->SetTextColor(rgb);
            return true;
        }

    case Member_autoSize:
        {
            ASString asStr(val.ToString(penv));
            String   str = (val.GetType() == Value::BOOLEAN) ?
                ((val.ToBool(penv)) ? "left" : "none") : asStr.ToCStr();

            DocView::ViewAlignment oldAlignment = ptf->GetDocument()->GetAlignment();
            bool oldAutoSize = TF_IsAutoSize(ptf);
            if (str == "none")
            {
                TF_SetAutoSize(ptf, false);
                ptf->GetDocument()->SetAlignment(DocView::Align_Left);
            }
            else
            {
                TF_SetAutoSize(ptf, true);
                if (str == "left")
                    ptf->GetDocument()->SetAlignment(DocView::Align_Left);
                else if (str == "right")
                    ptf->GetDocument()->SetAlignment(DocView::Align_Right);
                else if (str == "center")
                    ptf->GetDocument()->SetAlignment(DocView::Align_Center);
            }
            if ((oldAlignment != ptf->GetDocument()->GetAlignment()) || (oldAutoSize != TF_IsAutoSize(ptf)))
                UpdateAutosizeSettings();
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_wordWrap:
        {
            bool oldWordWrap = ptf->GetDocument()->IsWordWrap();
            bool wordWrap    = val.ToBool(penv);
            if (wordWrap != oldWordWrap)
            {
                if (wordWrap)
                    ptf->GetDocument()->SetWordWrap();
                else
                    ptf->GetDocument()->ClearWordWrap();
                UpdateAutosizeSettings();
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_multiline:
        {
            bool oldML        = ptf->GetDocument()->IsMultiline();
            bool newMultiline = val.ToBool(penv);
            if (oldML != newMultiline)
            {
                if (newMultiline)
                    ptf->GetDocument()->SetMultiline();
                else
                    ptf->GetDocument()->ClearMultiline();
                UpdateAutosizeSettings();
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_variable:
        {
            {
                VariableName = val.ToString(penv);
                UpdateTextFromVariable();
                TF_SetForceAdvance(ptf);
                ptf->ModifyOptimizedPlayListLocal<TextField>();
            }
            return true;
        }

    case Member_selectable:
        {
            ptf->SetSelectable(val.ToBool(penv));
            return true;
        }

    case Member_embedFonts:
        {
            if (val.ToBool(penv))
                ptf->GetDocument()->ClearUseDeviceFont();
            else
                ptf->GetDocument()->SetUseDeviceFont();
            ptf->GetDocument()->SetCompleteReformatReq();
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_password:
        {
            bool pswd     = ptf->IsPassword();
            bool password = val.ToBool(penv);
            if (pswd != password)
            {
                TF_SetPassword(ptf, password);
                if (password)
                    ptf->GetDocument()->SetPasswordMode();
                else
                    ptf->GetDocument()->ClearPasswordMode();
                ptf->GetDocument()->SetCompleteReformatReq();
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_hscroll:
        {
            int scrollVal = (int)val.ToInt32(penv);
            if (scrollVal < 0)
                scrollVal = 0;
            TF_SetHScrollOffset(ptf, (Double)scrollVal);
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_scroll:
        {
            int scrollVal = (int)val.ToInt32(penv);
            if (scrollVal < 1)
                scrollVal = 1;
            ptf->GetDocument()->SetVScrollOffset((unsigned)(scrollVal - 1));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
    case Member_border:
        {
            ptf->SetBorder(val.ToBool(penv));
            return true;
        }
    case Member_background:
        {
            ptf->SetBackground(val.ToBool(penv));
            return true;
        }
    case Member_backgroundColor:
        {
            Number bc = val.ToNumber(penv);
            if (!NumberUtil::IsNaN(bc))
            {
                UInt32 c = val.ToUInt32(penv);
                ptf->SetBackgroundColor(c);
            }
            return true;
        }
    case Member_borderColor:
        {
            Number bc = val.ToNumber(penv);
            if (!NumberUtil::IsNaN(bc))
            {
                UInt32 c = val.ToUInt32(penv);
                ptf->SetBorderColor(c);
            }
            return true;
        }
    case Member_type:
        {
            ASString typeStr = val.ToString(penv);
            if (NameEquals(penv, typeStr, "dynamic"))
            {
                if (ptf->GetDocument()->HasEditorKit())
                    TF_GetEditorKit(ptf)->SetReadOnly();
            }
            else if (NameEquals(penv, typeStr, "input") && !HasStyleSheet())
            {
                Text::EditorKit* peditor = ptf->CreateEditorKit();
                peditor->ClearReadOnly();
            }
            ptf->GetDocument()->SetReformatReq();
            return true;
        }
    case Member_maxChars:
        {
            Number ml = val.ToNumber(penv);
            if (!NumberUtil::IsNaN(ml) && ml >= 0)
            {
                ptf->GetDocument()->SetMaxLength((UPInt)val.ToUInt32(penv));
            }
            return true;
        }
    case Member_condenseWhite:
        {
            TF_SetCondenseWhite(ptf, val.ToBool(penv));
            return true;
        }
    case Member_antiAliasType:
        {
            ASString typeStr = val.ToString(penv);
            if (NameEquals(penv, typeStr, "normal"))
            {
                ptf->GetDocument()->ClearAAForReadability();
            }
            else if (NameEquals(penv, typeStr, "advanced"))
            {
                ptf->GetDocument()->SetAAForReadability();
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }

    case Member_mouseWheelEnabled:
        {
            TF_SetMouseWheelEnabled(ptf, val.ToBool(penv));
            return true;
        }
    case Member_styleSheet:
        {
            Object* pobj = val.ToObject(penv);
            if (pobj && pobj->GetObjectType() == Object_StyleSheet)
            {
                if (!ptf->GetCSSData())
                    ptf->SetCSSData(NewCSSHolder());
                CSSHolderOf(static_cast<TextField*>(pDispObj))->pASStyleSheet = static_cast<StyleSheetObject*>(pobj);

                // make the text field read-only
                if (ptf->GetDocument()->HasEditorKit())
                {
                    TF_GetEditorKit(ptf)->SetReadOnly();
                }

                static_cast<TextField*>(pDispObj)->SetDirtyFlag();

                if (IsStyleSheetLoading(CSSHolderOf(static_cast<TextField*>(pDispObj))->pASStyleSheet))
                {
                    ptf->ModifyOptimizedPlayListLocal<TextField>();
                }
            }
            else if (CSSHolderOf(static_cast<TextField*>(pDispObj)))
                CSSHolderOf(static_cast<TextField*>(pDispObj))->pASStyleSheet = NULL;
            ptf->CollectUrlZones();
            ptf->UpdateUrlStyles();
            TF_SetNeedUpdateLayoutFlag(ptf);
            return true;
        }

        // extension
    case Member_shadowStyle:
        if (!penv->CheckExtensions())
            break;

        {
            ASString    styleStr = val.ToString(penv);
            const char* pstr     = styleStr.ToCStr();

            ptf->SetShadowStyle(pstr);
            return true;
        }

    case Member_shadowColor:
        if (!penv->CheckExtensions())
            break;
        {
            ptf->SetShadowColor(val.ToUInt32(penv));
            return true;
        }

    case Member_hitTestDisable:
        if (penv->CheckExtensions())
        {
            TF_SetHitTestDisableFlag(ptf, val.ToBool(GetASEnvironment()));
            return 1;
        }
        break;

    case Member_noTranslate:
        if (penv->CheckExtensions())
        {
            TF_SetNoTranslate(ptf, val.ToBool(GetASEnvironment()));
            ptf->GetDocument()->SetCompleteReformatReq();
            return 1;
        }
        break;

    case Member_autoFit:
        if (penv->CheckExtensions())
        {
            if (val.ToBool(penv))
                ptf->GetDocument()->SetAutoFit();
            else
                ptf->GetDocument()->ClearAutoFit();
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_blurX:
        if (penv->CheckExtensions())
        {
            FilterOf(ptf->GetDocument()).BlurX = (float)Render::PixelsToTwips(val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_blurY:
        if (penv->CheckExtensions())
        {
            FilterOf(ptf->GetDocument()).BlurY = (float)Render::PixelsToTwips(val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_blurStrength:
        if (penv->CheckExtensions())
        {
            FilterOf(ptf->GetDocument()).BlurStrength = (float)val.ToNumber(penv);
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_outline:
        if (penv->CheckExtensions())
        {
            ptf->GetDocument()->SetOutline((float)val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_fauxBold:
        if (penv->CheckExtensions())
        {
            ptf->GetDocument()->SetFauxBold(val.ToBool(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_fauxItalic:
        if (penv->CheckExtensions())
        {
            ptf->GetDocument()->SetFauxItalic(val.ToBool(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowAlpha:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowAlpha(ptf, (float)val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowAngle:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowAngle(ptf, ((float)val.ToNumber(penv)) * (3.1415926f / 180.f));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowBlurX:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            FilterOf(ptf->GetDocument()).ShadowParams.BlurX = (float)Render::PixelsToTwips(val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowBlurY:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            FilterOf(ptf->GetDocument()).ShadowParams.BlurY = (float)Render::PixelsToTwips(val.ToNumber(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowDistance:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowDistance(ptf, Render::PixelsToTwips((float)val.ToNumber(penv)));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowHideObject:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowFlag(ptf, Render::BlurFilterParams::Mode_HideObject, val.ToBool(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowKnockOut:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowFlag(ptf, Render::BlurFilterParams::Mode_Inner, val.ToBool(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowQuality:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            TF_SetShadowQuality(ptf, (unsigned)val.ToUInt32(penv));
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_shadowStrength:
        if (penv->CheckExtensions())
        {
            TF_EnableSoftShadow(ptf);
            FilterOf(ptf->GetDocument()).ShadowParams.Strength = (float)val.ToNumber(penv);
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_verticalAutoSize:
        if (penv->CheckExtensions())
        {
            ASString asStr(val.ToString(penv));
            String   str = asStr.ToCStr();

            if (str == "none")
            {
                ptf->GetDocument()->ClearAutoSizeY();
                ptf->GetDocument()->SetVAlignment(DocView::VAlign_None);
            }
            else
            {
                ptf->GetDocument()->SetAutoSizeY();
                if (str == "top")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Top);
                else if (str == "bottom")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Bottom);
                else if (str == "center")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Center);
            }
            TF_SetNeedUpdateGeomData(ptf);
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_fontScaleFactor:
        if (penv->CheckExtensions())
        {
            Number factor = val.ToNumber(penv);
            if (factor > 0 && factor < 1000)
                ptf->GetDocument()->SetFontScaleFactor((float)factor);
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
        }
        break;

    case Member_verticalAlign:
        if (penv->CheckExtensions())
        {
            ASString asStr(val.ToString(penv));
            String   str = asStr.ToCStr();

            if (str == "none")
                ptf->GetDocument()->SetVAlignment(DocView::VAlign_None);
            else
            {
                if (str == "top")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Top);
                else if (str == "bottom")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Bottom);
                else if (str == "center")
                    ptf->GetDocument()->SetVAlignment(DocView::VAlign_Center);
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_textAutoSize:
        if (penv->CheckExtensions())
        {
            ASString asStr(val.ToString(penv));
            String   str = asStr.ToCStr();

            if (str == "none")
                ptf->GetDocument()->SetTextAutoSize(DocView::TAS_None);
            else
            {
                if (str == "shrink")
                    ptf->GetDocument()->SetTextAutoSize(DocView::TAS_Shrink);
                else if (str == "fit")
                    ptf->GetDocument()->SetTextAutoSize(DocView::TAS_Fit);
            }
            static_cast<TextField*>(pDispObj)->SetDirtyFlag();
            return true;
        }
        break;

    case Member_useRichTextClipboard:
        if (penv->CheckExtensions())
        {
            TF_SetUseRichClipboard(ptf, val.ToBool(GetASEnvironment()));
            if (ptf->GetDocument()->HasEditorKit())
            {
                if (TF_DoesUseRichClipboard(ptf))
                    TF_GetEditorKit(ptf)->SetUseRichClipboard();
                else
                    TF_GetEditorKit(ptf)->ClearUseRichClipboard();
            }
            return 1;
        }
        break;

    case Member_alwaysShowSelection:
        if (penv->CheckExtensions())
        {
            TF_SetAlwaysShowSelection(ptf, val.ToBool(GetASEnvironment()));
            return 1;
        }
        break;

    case Member_selectionTextColor:
        if (penv->CheckExtensions() && ptf->GetDocument()->HasEditorKit())
        {
            TF_GetEditorKit(ptf)->SetActiveSelectionTextColor(val.ToUInt32(penv));
            return true;
        }
        break;
    case Member_selectionBkgColor:
        if (penv->CheckExtensions() && ptf->GetDocument()->HasEditorKit())
        {
            TF_GetEditorKit(ptf)->SetActiveSelectionBackgroundColor(val.ToUInt32(penv));
            return true;
        }
        break;
    case Member_inactiveSelectionTextColor:
        if (penv->CheckExtensions() && ptf->GetDocument()->HasEditorKit())
        {
            TF_GetEditorKit(ptf)->SetInactiveSelectionTextColor(val.ToUInt32(penv));
            return true;
        }
        break;
    case Member_inactiveSelectionBkgColor:
        if (penv->CheckExtensions() && ptf->GetDocument()->HasEditorKit())
        {
            TF_GetEditorKit(ptf)->SetInactiveSelectionBackgroundColor(val.ToUInt32(penv));
            return true;
        }
        break;
    case Member_noAutoSelection:
        if (penv->CheckExtensions())
        {
            TF_SetNoAutoSelection(ptf, val.ToBool(penv));
            return true;
        }
        break;
    case Member_disableIME:
        if (penv->CheckExtensions())
        {
            TF_SetIMEDisabledFlag(ptf, val.ToBool(penv));
            return true;
        }
        // 4.1.18 has no break here: without the extensions the value is taken as a filters array.
    case M_filters:
        {
            Object* pobj = val.ToObject(penv);
            if (pobj && pobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_Array)))
            {
                Render::Text::TextFilter textfilter;
                bool filterdirty = false;
                ArrayObject* parrobj = static_cast<ArrayObject*>(pobj);
                for (int i = 0; i < parrobj->GetSize(); ++i)
                {
                    Value* arrval = parrobj->GetElementPtr(i);
                    if (arrval)
                    {
                        Object* pavobj = arrval->ToObject(penv);
                        if (pavobj && pavobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_BitmapFilter)))
                        {
                            BitmapFilterObject* pfilterobj = static_cast<BitmapFilterObject*>(pavobj);
                            textfilter.LoadFilterDesc(pfilterobj->GetFilter());
                            filterdirty = true;
                        }
                    }
                }
                if (filterdirty)
                {
                    ptf->SetTextFilters(textfilter);
                    static_cast<TextField*>(pDispObj)->SetDirtyFlag();
                    ptf->SetAcceptAnimMoves(false);
                }
            }
            return true;
        }
        break;
    case Member_restrict:
        {
            ptf->SetRestrict(val.ToString(penv));
            break;
        }
    default:
        break;
    }
    return AvmCharacter::SetMember(penv, name, val, flags);
}

}}} // namespace Scaleform::GFx::AS2
