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
const int Member_selectionBeginIndex = 0x53; // the four selection colors
const int Member_selectionEndIndex   = 0x54;
const int Member_selectionBkgColor   = 0x55;
const int Member_selectionTextColor  = 0x56;
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

} // namespace

// The watchpoints of the field's AS object see the text field members first. A member the character does not
// take is a text field property; the GFx extension ones need the extensions on, the rest go to the character.
// MS2-FUNCTIONAL: the switch shares its tails (flag stores, SetDirtyFlag, the string releases) differently and the
// style sheet holder is filled through a layout mirror; same behavior
// @0x142983360
bool AvmTextField::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    StandardMember member = GetStandardMemberConstant(name);
    Value          v(val);
    if ((int)member > Member_LastCharacterMember && penv && GetTextFieldASObject() &&
        ASTextFieldObj->pWatchpoints)
    {
        Value newVal;
        if (ASTextFieldObj->InvokeWatchpoint(penv, name, v, &newVal))
            v = newVal;
    }
    if (SetStandardMember(member, val, false))
        return true;

    TextField*             ptf  = static_cast<TextField*>(pDispObj);
    Render::Text::DocView* pdoc = ptf->GetDocument();
    switch ((int)member)
    {
    case M_filters:
    filters:
    {
        Object* pobj = v.ToObject(penv);
        if (pobj && pobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_Array), true))
        {
            ArrayObject*             parr = static_cast<ArrayObject*>(pobj);
            Render::Text::TextFilter textFilter;
            bool                     found = false;
            for (int i = 0; i < parr->GetSize(); ++i)
            {
                Value* pelem = parr->GetElementPtr(i);
                if (!pelem)
                    continue;
                Object* pfilterObj = pelem->ToObject(penv);
                if (pfilterObj && pfilterObj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_BitmapFilter), true))
                {
                    textFilter.LoadFilterDesc(static_cast<BitmapFilterObject*>(pfilterObj)->GetFilter());
                    found = true;
                }
            }
            if (found)
            {
                ptf->SetTextFilters(textFilter);
                ptf->SetDirtyFlag();
                ptf->SetAcceptAnimMoves(false);
            }
        }
        return true;
    }

    case Member_text:
    {
        ptf->ResetBlink(true, false);
        unsigned version = ptf->GetVersion();
        ASString str     = v.IsUndefined() ? UndefinedText(penv, version) : v.ToString(penv);
        ptf->SetTextValue(str.ToCStr(), false, true);
        break;
    }
    case Member_textColor:
        ptf->SetTextColor(v.ToUInt32(penv));
        break;
    case Member_html:
        SetFlag(ptf->Flags, TextField::Flags_Html, v.ToBool(penv));
        break;
    case Member_htmlText:
    {
        unsigned version = ptf->GetVersion();
        ASString str     = v.IsUndefined() ? UndefinedText(penv, version) : v.ToString(penv);
        ptf->SetTextValue(str.ToCStr(), ptf->IsHtml(), true);
        break;
    }
    case Member_styleSheet:
    {
        Object* pobj = v.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_StyleSheet)
        {
            if (!ptf->GetCSSData())
            {
                AS2CSSHolder* pcss = (AS2CSSHolder*)Memory::Alloc(sizeof(AS2CSSHolder));
                if (pcss)
                {
                    memset(pcss, 0, sizeof(AS2CSSHolder));
                    pcss->vfptr = AvmTextFieldCSSHolder_vftable;
                }
                ptf->SetCSSData(reinterpret_cast<TextField::CSSHolderBase*>(pcss));
            }
            StyleSheetObject* pstyleSheet = static_cast<StyleSheetObject*>(pobj);
            CSSHolderOf(ptf)->pASStyleSheet = pstyleSheet;
            if (Text::EditorKit* pkit = EditorKitOf(ptf))
                pkit->SetReadOnly();
            ptf->SetDirtyFlag();
            // still loading: the field advances until the sheet arrives
            if (*(const int*)((const UByte*)CSSHolderOf(ptf)->pASStyleSheet.GetPtr() + 0x90) == 1)
                ptf->ModifyOptimizedPlayListLocal<TextField>();
        }
        else if (ptf->GetCSSData())
            CSSHolderOf(ptf)->pASStyleSheet = NULL;
        ptf->CollectUrlZones();
        ptf->UpdateUrlStyles();
        ptf->Flags |= TextField::Flags_NeedUpdateLayout;
        break;
    }
    case Member_autoSize:
    {
        ASString    str = v.ToString(penv);
        const char* pstr;
        if (v.GetType() == Value::BOOLEAN)
            pstr = v.ToBool(penv) ? "left" : "none";
        else
            pstr = str.ToCStr();
        String  autoSize(pstr);
        DocView::ViewAlignment oldAlign = pdoc->GetAlignment();
        UInt32  oldAutoSize = ptf->Flags;
        if (strcmp(autoSize.ToCStr(), "none") == 0)
        {
            ptf->Flags &= ~TextField::Flags_AutoSize;
            pdoc->SetAlignment(DocView::Align_Left);
            pdoc->SetReformatReq();
        }
        else
        {
            ptf->Flags |= TextField::Flags_AutoSize;
            if (strcmp(autoSize.ToCStr(), "left") == 0)
            {
                pdoc->SetAlignment(DocView::Align_Left);
                pdoc->SetReformatReq();
            }
            else if (strcmp(autoSize.ToCStr(), "right") == 0)
            {
                pdoc->SetAlignment(DocView::Align_Right);
                pdoc->SetReformatReq();
            }
            else if (strcmp(autoSize.ToCStr(), "center") == 0)
            {
                pdoc->SetAlignment(DocView::Align_Center);
                pdoc->SetReformatReq();
            }
        }
        if (oldAlign != ptf->GetDocument()->GetAlignment() ||
            (oldAutoSize & TextField::Flags_AutoSize) != (ptf->Flags & TextField::Flags_AutoSize))
            UpdateAutosizeSettings();
        ptf->SetDirtyFlag();
        break;
    }
    case Member_wordWrap:
    {
        bool wasWrap  = pdoc->IsWordWrap();
        bool wordWrap = v.ToBool(penv);
        if (wordWrap != wasWrap)
        {
            if (wordWrap)
                ptf->GetDocument()->SetWordWrap();
            else
                ptf->GetDocument()->ClearWordWrap();
            UpdateAutosizeSettings();
        }
        ptf->SetDirtyFlag();
        break;
    }
    case Member_multiline:
    {
        bool wasMultiline = pdoc->IsMultiline();
        bool multiline    = v.ToBool(penv);
        if (wasMultiline != multiline)
        {
            if (multiline)
                ptf->GetDocument()->SetMultiline();
            else
                ptf->GetDocument()->ClearMultiline();
            UpdateAutosizeSettings();
        }
        ptf->SetDirtyFlag();
        break;
    }
    case Member_border:
        ptf->SetBorder(v.ToBool(penv));
        break;
    case Member_variable:
        VariableName = v.ToString(penv);
        UpdateTextFromVariable();
        ptf->Flags |= TextField::Flags_ForceAdvance;
        ptf->ModifyOptimizedPlayListLocal<TextField>();
        break;
    case Member_selectable:
        ptf->SetSelectable(v.ToBool(penv));
        break;
    case Member_embedFonts:
        if (v.ToBool(penv))
            pdoc->ClearUseDeviceFont();
        else
            pdoc->SetUseDeviceFont();
        ptf->GetDocument()->SetCompleteReformatReq();
        ptf->SetDirtyFlag();
        break;
    case Member_antiAliasType:
    {
        ASString str = v.ToString(penv);
        if (NameEquals(penv, str, "normal"))
        {
            ptf->GetDocument()->ClearAAForReadability();
            ptf->SetDirtyFlag();
        }
        else
        {
            if (NameEquals(penv, str, "advanced"))
                ptf->GetDocument()->SetAAForReadability();
            ptf->SetDirtyFlag();
        }
        break;
    }
    case Member_hscroll:
    {
        int hscroll = v.ToInt32(penv);
        if (hscroll < 0)
            hscroll = 0;
        pdoc->SetHScrollOffset((unsigned)(SInt64)((Double)hscroll * 20.0));
        ptf->SetDirtyFlag();
        break;
    }
    case Member_scroll:
    {
        int scroll = v.ToInt32(penv);
        if (scroll < 1)
            scroll = 1;
        pdoc->SetVScrollOffset(scroll - 1);
        ptf->SetDirtyFlag();
        break;
    }
    case Member_background:
        ptf->SetBackground(v.ToBool(penv));
        break;
    case Member_backgroundColor:
        if (!NumberUtil::IsNaN(v.ToNumber(penv)))
            ptf->SetBackgroundColor(v.ToUInt32(penv));
        break;
    case Member_borderColor:
        if (!NumberUtil::IsNaN(v.ToNumber(penv)))
            ptf->SetBorderColor(v.ToUInt32(penv));
        break;
    case Member_type:
    {
        ASString str = v.ToString(penv);
        if (NameEquals(penv, str, "dynamic"))
        {
            if (Text::EditorKit* pkit = EditorKitOf(ptf))
                pkit->SetReadOnly();
        }
        else if (NameEquals(penv, str, "input") && !HasStyleSheet())
            ptf->CreateEditorKit()->ClearReadOnly();
        ptf->GetDocument()->SetReformatReq();
        break;
    }
    case Member_maxChars:
    {
        Number n = v.ToNumber(penv);
        if (!NumberUtil::IsNaN(n) && n >= 0)
            pdoc->SetMaxLength(v.ToUInt32(penv));
        break;
    }
    case Member_condenseWhite:
        SetFlag(ptf->Flags, TextField::Flags_CondenseWhite, v.ToBool(penv));
        break;
    case Member_mouseWheelEnabled:
        SetFlag(ptf->Flags, TextField::Flags_MouseWheelEnabled, v.ToBool(penv));
        break;
    case Member_password:
    {
        bool wasPassword = (ptf->Flags & TextField::Flags_Password) != 0;
        bool password    = v.ToBool(penv);
        if (wasPassword != password)
        {
            SetFlag(ptf->Flags, TextField::Flags_Password, password);
            if (password)
                ptf->GetDocument()->SetPasswordMode();
            else
                ptf->GetDocument()->ClearPasswordMode();
            ptf->GetDocument()->SetCompleteReformatReq();
        }
        ptf->SetDirtyFlag();
        break;
    }

    case Member_shadowStyle:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        ASString str = v.ToString(penv);
        ptf->SetShadowStyle(str.ToCStr());
        break;
    }
    case Member_shadowColor:
        if (!penv->CheckExtensions())
            goto fallback;
        ptf->SetShadowColor(v.ToUInt32(penv));
        break;
    case Member_hitTestDisable:
        if (!penv->CheckExtensions())
            goto fallback;
        SetFlag(static_cast<InteractiveObject*>(ptf)->Flags, InteractiveObject::Mask_HitTestDisable, v.ToBool(GetASEnvironment()));
        break;
    case Member_noTranslate:
        if (!penv->CheckExtensions())
            goto fallback;
        SetFlag(ptf->Flags, TextField::Flags_NoTranslate, v.ToBool(GetASEnvironment()));
        ptf->GetDocument()->SetCompleteReformatReq();
        break;
    case Member_verticalAutoSize:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        ASString str = v.ToString(penv);
        String   valign(str.ToCStr());
        if (strcmp(valign.ToCStr(), "none") == 0)
        {
            ptf->GetDocument()->ClearAutoSizeY();
            ptf->GetDocument()->SetVAlignment(DocView::VAlign_None);
            ptf->GetDocument()->SetReformatReq();
        }
        else
        {
            ptf->GetDocument()->SetAutoSizeY();
            Render::Text::DocView* pd = ptf->GetDocument();
            if (strcmp(valign.ToCStr(), "top") == 0)
            {
                pd->SetVAlignment(DocView::VAlign_Top);
                pd->SetReformatReq();
            }
            else if (strcmp(valign.ToCStr(), "bottom") == 0)
            {
                pd->SetVAlignment(DocView::VAlign_Bottom);
                pd->SetReformatReq();
            }
            else if (strcmp(valign.ToCStr(), "center") == 0)
            {
                pd->SetVAlignment(DocView::VAlign_Center);
                pd->SetReformatReq();
            }
        }
        ptf->Flags |= TextField::Flags_NeedUpdateGeomData;
        ptf->SetDirtyFlag();
        static_cast<TextField*>(pDispObj)->SetDirtyFlag();
        break;
    }
    case Member_fontScaleFactor:
        if (penv->CheckExtensions())
        {
            Number factor = v.ToNumber(penv);
            if (factor > 0 && factor < 1000)
                pdoc->SetFontScaleFactor((float)factor);
            ptf->SetDirtyFlag();
        }
        goto fallback;
    case Member_verticalAlign:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        ASString str = v.ToString(penv);
        String   valign(str.ToCStr());
        Render::Text::DocView* pd = ptf->GetDocument();
        if (strcmp(valign.ToCStr(), "none") == 0)
        {
            pd->SetVAlignment(DocView::VAlign_None);
            pd->SetReformatReq();
        }
        else if (strcmp(valign.ToCStr(), "top") == 0)
        {
            pd->SetVAlignment(DocView::VAlign_Top);
            pd->SetReformatReq();
        }
        else if (strcmp(valign.ToCStr(), "bottom") == 0)
        {
            pd->SetVAlignment(DocView::VAlign_Bottom);
            pd->SetReformatReq();
        }
        else if (strcmp(valign.ToCStr(), "center") == 0)
        {
            pd->SetVAlignment(DocView::VAlign_Center);
            pd->SetReformatReq();
        }
        ptf->SetDirtyFlag();
        break;
    }
    case Member_textAutoSize:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        ASString str = v.ToString(penv);
        String   tas(str.ToCStr());
        Render::Text::DocView* pd = ptf->GetDocument();
        if (strcmp(tas.ToCStr(), "none") == 0)
        {
            pd->SetTextAutoSize(DocView::TAS_None);
            pd->SetReformatReq();
        }
        else if (strcmp(tas.ToCStr(), "shrink") == 0)
        {
            pd->SetTextAutoSize(DocView::TAS_Shrink);
            pd->SetReformatReq();
        }
        else if (strcmp(tas.ToCStr(), "fit") == 0)
        {
            pd->SetTextAutoSize(DocView::TAS_Fit);
            pd->SetReformatReq();
        }
        ptf->SetDirtyFlag();
        break;
    }
    case Member_useRichTextClipboard:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        SetFlag(ptf->Flags, TextField::Flags_UseRichClipboard, v.ToBool(GetASEnvironment()));
        if (Text::EditorKit* pkit = EditorKitOf(ptf))
        {
            if (ptf->Flags & TextField::Flags_UseRichClipboard)
                pkit->SetUseRichClipboard();
            else
                pkit->ClearUseRichClipboard();
        }
        break;
    }
    case Member_alwaysShowSelection:
        if (!penv->CheckExtensions())
            goto fallback;
        SetFlag(ptf->Flags, TextField::Flags_AlwaysShowSelection, v.ToBool(GetASEnvironment()));
        break;
    case Member_selectionBeginIndex:
    case Member_selectionEndIndex:
    case Member_selectionBkgColor:
    case Member_selectionTextColor:
    {
        Text::EditorKit* pkit;
        if (!penv->CheckExtensions() || (pkit = EditorKitOf(ptf)) == NULL)
            goto fallback;
        UInt32 color = v.ToUInt32(penv);
        if (member == Member_selectionBeginIndex)
            pkit->SetActiveSelectionBackgroundColor(color);
        else if (member == Member_selectionEndIndex)
            pkit->SetActiveSelectionTextColor(color);
        else if (member == Member_selectionBkgColor)
            pkit->SetInactiveSelectionBackgroundColor(color);
        else
            pkit->SetInactiveSelectionTextColor(color);
        break;
    }
    case Member_noAutoSelection:
        if (!penv->CheckExtensions())
            goto fallback;
        SetFlag(ptf->Flags, TextField::Flags_NoAutoSelection, v.ToBool(penv));
        break;
    case Member_disableIME:
        // without the extensions the value is taken as a filters array
        if (!penv->CheckExtensions())
            goto filters;
        SetFlag(ptf->Flags, TextField::Flags_IMEDisabled, v.ToBool(penv));
        break;
    case Member_autoFit:
        if (!penv->CheckExtensions())
            goto fallback;
        if (v.ToBool(penv))
            ptf->GetDocument()->SetAutoFit();
        else
            ptf->GetDocument()->ClearAutoFit();
        ptf->SetDirtyFlag();
        break;
    case Member_blurX:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).BlurX = (float)(v.ToNumber(penv) * 20.0);
        ptf->SetDirtyFlag();
        break;
    case Member_blurY:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).BlurY = (float)(v.ToNumber(penv) * 20.0);
        ptf->SetDirtyFlag();
        break;
    case Member_blurStrength:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).BlurStrength = (float)v.ToNumber(penv);
        ptf->SetDirtyFlag();
        break;
    case Member_outline:
        if (!penv->CheckExtensions())
            goto fallback;
        pdoc->SetOutline((float)v.ToNumber(penv));
        ptf->SetDirtyFlag();
        break;
    case Member_fauxBold:
        if (!penv->CheckExtensions())
            goto fallback;
        ptf->GetDocument()->SetFauxBold(v.ToBool(penv));
        ptf->SetDirtyFlag();
        break;
    case Member_fauxItalic:
        if (!penv->CheckExtensions())
            goto fallback;
        ptf->GetDocument()->SetFauxItalic(v.ToBool(penv));
        ptf->SetDirtyFlag();
        break;
    case Member_restrict:
    {
        ASString str = v.ToString(penv);
        ptf->SetRestrict(str);
        goto fallback;
    }

    // The drop shadow members turn the shadow on (ShadowFlags bit 0 off).
    case Member_shadowAlpha:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        float alpha = (float)v.ToNumber(penv) * 255.0f;
        Render::Text::TextFilter& f = FilterOf(ptf->GetDocument());
        if (alpha >= 255.0f)
            alpha = 255.0f;
        UByte a = (UByte)(int)(alpha >= 0.0f ? alpha : 0.0f);
        f.ShadowAlpha = a;
        f.ShadowParams.Colors[0].SetAlpha(a);
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowAngle:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        float angle = (float)v.ToNumber(penv) * DegToRad;
        Render::Text::TextFilter& f = FilterOf(ptf->GetDocument());
        f.ShadowAngle = angle;
        float dist    = f.ShadowDistance;
        f.ShadowParams.Offset.x = cosf(angle) * dist;
        f.ShadowParams.Offset.y = sinf(angle) * dist;
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowBlurX:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        FilterOf(ptf->GetDocument()).ShadowParams.BlurX = (float)(v.ToNumber(penv) * 20.0);
        ptf->SetDirtyFlag();
        break;
    case Member_shadowBlurY:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        FilterOf(ptf->GetDocument()).ShadowParams.BlurY = (float)(v.ToNumber(penv) * 20.0);
        ptf->SetDirtyFlag();
        break;
    case Member_shadowDistance:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        float dist = (float)v.ToNumber(penv) * 20.0f;
        Render::Text::TextFilter& f = FilterOf(ptf->GetDocument());
        f.ShadowDistance = dist;
        float angle      = f.ShadowAngle;
        f.ShadowParams.Offset.x = cosf(angle) * dist;
        f.ShadowParams.Offset.y = sinf(angle) * dist;
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowHideObject:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        bool on = v.ToBool(penv);
        SetFlag(*(UInt32*)&FilterOf(ptf->GetDocument()).ShadowFlags, Render::BlurFilterParams::Mode_HideObject, on);
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowKnockOut:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        bool on = v.ToBool(penv);
        SetFlag(*(UInt32*)&FilterOf(ptf->GetDocument()).ShadowFlags, Render::BlurFilterParams::Mode_Inner, on);
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowQuality:
    {
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        UInt32 quality = v.ToUInt32(penv);
        SetFlag(*(UInt32*)&FilterOf(ptf->GetDocument()).ShadowFlags, Render::BlurFilterParams::Mode_Highlight,
                quality > 1);
        ptf->SetDirtyFlag();
        break;
    }
    case Member_shadowStrength:
        if (!penv->CheckExtensions())
            goto fallback;
        FilterOf(pdoc).ShadowFlags &= ~1u;
        FilterOf(ptf->GetDocument()).ShadowParams.Strength = (float)v.ToNumber(penv);
        ptf->SetDirtyFlag();
        break;

    default:
    fallback:
        return AvmCharacter::SetMember(penv, name, v, flags);
    }
    return true;
}

}}} // namespace Scaleform::GFx::AS2
