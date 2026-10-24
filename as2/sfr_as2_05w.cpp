// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextField: a member read from a
// text field, its text, format, layout, scrolling and the GFx extension properties (gap recovery of sfr_as2_05).
// MS2-UNIT: sfr_as2_05w
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294c720-0x14294d69f .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/text_editorkit.h"
#include "../include/render/text_docview.h"
#include "../include/render/text_filterdesc.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// The text field members of the MemberTable (after the character ones).
const int Member_filters                    = 0x19;
const int Member_text                       = 0x28;
const int Member_textWidth                  = 0x29;
const int Member_textHeight                 = 0x2a;
const int Member_textColor                  = 0x2b;
const int Member_length                     = 0x2c;
const int Member_html                       = 0x2d;
const int Member_htmlText                   = 0x2e;
const int Member_styleSheet                 = 0x2f;
const int Member_autoSize                   = 0x30;
const int Member_wordWrap                   = 0x31;
const int Member_multiline                  = 0x32;
const int Member_border                     = 0x33;
const int Member_variable                   = 0x34;
const int Member_selectable                 = 0x35;
const int Member_embedFonts                 = 0x36;
const int Member_antiAliasType              = 0x37;
const int Member_hscroll                    = 0x38;
const int Member_scroll                     = 0x39;
const int Member_maxscroll                  = 0x3a;
const int Member_maxhscroll                 = 0x3b;
const int Member_background                 = 0x3c;
const int Member_backgroundColor            = 0x3d;
const int Member_borderColor                = 0x3e;
const int Member_bottomScroll               = 0x3f;
const int Member_type                       = 0x40;
const int Member_maxChars                   = 0x41;
const int Member_condenseWhite              = 0x42;
const int Member_mouseWheelEnabled          = 0x43;
const int Member_password                   = 0x44;
// GFx extensions
const int Member_shadowStyle                = 0x45;
const int Member_shadowColor                = 0x46;
const int Member_hitTestDisable             = 0x47;
const int Member_noTranslate                = 0x48;
const int Member_caretIndex                 = 0x49;
const int Member_numLines                   = 0x4a;
const int Member_verticalAutoSize           = 0x4b;
const int Member_fontScaleFactor            = 0x4c;
const int Member_verticalAlign              = 0x4d;
const int Member_textAutoSize               = 0x4e;
const int Member_useRichTextClipboard       = 0x4f;
const int Member_alwaysShowSelection        = 0x50;
const int Member_selectionBeginIndex        = 0x51;
const int Member_selectionEndIndex          = 0x52;
const int Member_selectionBkgColor          = 0x53;
const int Member_selectionTextColor         = 0x54;
const int Member_inactiveSelectionBkgColor  = 0x55;
const int Member_inactiveSelectionTextColor = 0x56;
const int Member_noAutoSelection            = 0x57;
const int Member_disableIME                 = 0x58;
const int Member_autoFit                    = 0x5c;
const int Member_blurX                      = 0x5d;
const int Member_blurY                      = 0x5e;
const int Member_blurStrength               = 0x5f;
const int Member_outline                    = 0x60;
const int Member_fauxBold                   = 0x61;
const int Member_fauxItalic                 = 0x62;
const int Member_shadowAlpha                = 0x64;
const int Member_shadowAngle                = 0x65;
const int Member_shadowBlurX                = 0x66;
const int Member_shadowBlurY                = 0x67;
const int Member_shadowDistance             = 0x68;
const int Member_shadowHideObject           = 0x69;
const int Member_shadowKnockOut             = 0x6a;
const int Member_shadowQuality              = 0x6b;
const int Member_shadowStrength             = 0x6c;
const int Member_restrictMember             = 0x6d; // no getter

const float RadToDeg = 57.295784f;

// TextFilter::ShadowFlags (GlyphParam flags) the shadow members read: hide object 0x40, knock out 0x20, high
// quality 0x80.

typedef Render::Text::DocView DocView;

// The AS2 style sheet holder: the URL zones of CSSHolderBase, then the StyleSheet object (as sfr_as2_06z).
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

inline Double TwipsToPixels(Double v) { return v * 0.05; }

// A constant string of the movie as the value.
inline void SetConstString(Environment* penv, Value* pval, const char* pstr)
{
    pval->SetString(penv->CreateConstString(pstr));
}

// The vertical alignment as its name; false for an unknown one.
bool SetVAlignName(Environment* penv, Value* pval, DocView::ViewVAlignment valign)
{
    switch (valign)
    {
    case DocView::VAlign_None:   SetConstString(penv, pval, "none"); return true;
    case DocView::VAlign_Top:    SetConstString(penv, pval, "top"); return true;
    case DocView::VAlign_Bottom: SetConstString(penv, pval, "bottom"); return true;
    case DocView::VAlign_Center: SetConstString(penv, pval, "center"); return true;
    }
    return false;
}

} // namespace

// The character members first (filters is not readable); a text field property comes from the field and its
// document, the GFx extension ones only with the extensions on. Anything else is looked up on the field's AS object,
// or until that exists on the prototype (__proto__ itself is answered here); _global is visible from every field.
// fontScaleFactor, textAutoSize, useRichTextClipboard and alwaysShowSelection set the value and go on to the lookup
// as in the exe.
// MS2-FUNCTIONAL: the switch shares its tails (the bool stores, the string releases) differently; the GetCSSData
// getter is out of line in the exe and the style sheet holder is read through a layout mirror
// @0x14294c720
bool AvmTextField::GetMember(Environment* penv, const ASString& name, Value* pval)
{
    StandardMember member = GetStandardMemberConstant(name);
    TextField*     ptf    = static_cast<TextField*>(pDispObj);
    DocView*       pdoc   = ptf->GetDocument();

    switch ((int)member)
    {
    case Member_filters:
        pval->SetUndefined();
        if (Log* plog = penv->GetLog())
            plog->LogWarning("Retrieval of the TextField.filters property is not implemented.");
        return true;

    case Member_text:
        pval->SetString(ptf->GetText(false));
        return true;
    case Member_htmlText:
        pval->SetString(ptf->GetText(true));
        return true;
    case Member_textWidth:
        pval->SetNumber(ptf->GetTextWidth());
        return true;
    case Member_textHeight:
        pval->SetNumber(ptf->GetTextHeight());
        return true;
    case Member_textColor:
        pval->SetInt((int)ptf->GetTextColor32());
        return true;
    case Member_length:
        pval->SetNumber((Number)pdoc->GetStyledText()->GetLength());
        return true;
    case Member_html:
        pval->SetBool((ptf->Flags & TextField::Flags_Html) != 0);
        return true;
    case Member_styleSheet:
        pval->SetUndefined();
        if (ptf->GetCSSData() && CSSHolderOf(ptf)->pASStyleSheet)
            pval->SetAsObject(CSSHolderOf(ptf)->pASStyleSheet);
        return true;
    case Member_autoSize:
        if (!(ptf->Flags & TextField::Flags_AutoSize))
            SetConstString(penv, pval, "none");
        else
            switch (pdoc->GetAlignment())
            {
            case DocView::Align_Left:   SetConstString(penv, pval, "left"); break;
            case DocView::Align_Right:  SetConstString(penv, pval, "right"); break;
            case DocView::Align_Center: SetConstString(penv, pval, "center"); break;
            default:                    pval->SetUndefined(); break;
            }
        return true;
    case Member_wordWrap:
        pval->SetBool(pdoc->IsWordWrap());
        return true;
    case Member_multiline:
        pval->SetBool(pdoc->IsMultiline());
        return true;
    case Member_border:
        pval->SetBool((pdoc->GetBorderColor() >> 24) != 0);
        return true;
    case Member_variable:
        if (VariableName.GetSize() != 0)
            pval->SetString(VariableName);
        else
            pval->SetNull();
        return true;
    case Member_selectable:
        pval->SetBool(ptf->IsSelectable());
        return true;
    case Member_embedFonts:
        pval->SetBool(!pdoc->DoesUseDeviceFont());
        return true;
    case Member_antiAliasType:
        SetConstString(penv, pval, pdoc->IsAAForReadability() ? "advanced" : "normal");
        return true;
    case Member_hscroll:
        pval->SetNumber((Number)(unsigned)(SInt64)TwipsToPixels((Double)pdoc->GetHScrollOffset()));
        return true;
    case Member_maxhscroll:
        pval->SetNumber((Number)(unsigned)(SInt64)TwipsToPixels((Double)pdoc->GetMaxHScroll()));
        return true;
    case Member_scroll:
        pval->SetNumber((Number)(pdoc->GetVScrollOffset() + 1));
        return true;
    case Member_maxscroll:
        pval->SetNumber((Number)(pdoc->GetMaxVScroll() + 1));
        return true;
    case Member_bottomScroll:
        pval->SetNumber((Number)(pdoc->GetBottomVScroll() + 1));
        return true;
    case Member_background:
        pval->SetBool((pdoc->GetBackgroundColor() >> 24) != 0);
        return true;
    case Member_backgroundColor:
        pval->SetNumber((Number)(pdoc->GetBackgroundColor() & 0xFFFFFFu));
        return true;
    case Member_borderColor:
        pval->SetNumber((Number)(pdoc->GetBorderColor() & 0xFFFFFFu));
        return true;
    case Member_type:
        SetConstString(penv, pval, ptf->IsReadOnly() ? "dynamic" : "input");
        return true;
    case Member_maxChars:
    {
        unsigned maxLength = (unsigned)pdoc->GetMaxLength();
        if (maxLength == 0)
            pval->SetNull();
        else
            pval->SetNumber((Number)maxLength);
        return true;
    }
    case Member_condenseWhite:
        pval->SetBool((ptf->Flags & TextField::Flags_CondenseWhite) != 0);
        return true;
    case Member_mouseWheelEnabled:
        pval->SetBool((ptf->Flags & TextField::Flags_MouseWheelEnabled) != 0);
        return true;
    case Member_password:
        pval->SetBool((ptf->Flags & TextField::Flags_Password) != 0);
        return true;

    case Member_shadowStyle:
        if (!penv->CheckExtensions())
            break;
        pval->SetString(ptf->GetShadowStyle());
        return true;
    case Member_shadowColor:
        if (!penv->CheckExtensions())
            break;
        pval->SetInt((int)pdoc->GetShadowColor());
        return true;
    case Member_hitTestDisable:
        if (!GetASEnvironment()->CheckExtensions())
            break;
        pval->SetBool((static_cast<InteractiveObject*>(ptf)->Flags & InteractiveObject::Mask_HitTestDisable) != 0);
        return true;
    case Member_noTranslate:
        if (!GetASEnvironment()->CheckExtensions())
            break;
        pval->SetBool((ptf->Flags & TextField::Flags_NoTranslate) != 0);
        return true;
    case Member_caretIndex:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)ptf->GetCursorPos());
        return true;
    case Member_numLines:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)pdoc->GetLinesCount());
        return true;
    case Member_verticalAutoSize:
        if (!penv->CheckExtensions())
            break;
        if (!SetVAlignName(penv, pval, pdoc->IsAutoSizeY() ? pdoc->GetVAlignment() : DocView::VAlign_None))
            pval->SetUndefined();
        return true;
    case Member_verticalAlign:
        if (!penv->CheckExtensions())
            break;
        if (!SetVAlignName(penv, pval, pdoc->GetVAlignment()))
            pval->SetUndefined();
        return true;
    case Member_fontScaleFactor:
        if (penv->CheckExtensions())
            pval->SetNumber((Number)pdoc->GetFontScaleFactor());
        break;
    case Member_textAutoSize:
        if (penv->CheckExtensions())
        {
            switch (pdoc->GetTextAutoSize())
            {
            case DocView::TAS_Shrink: SetConstString(penv, pval, "shrink"); break;
            case DocView::TAS_Fit:    SetConstString(penv, pval, "fit"); break;
            default:                  SetConstString(penv, pval, "none"); break;
            }
        }
        break;
    case Member_useRichTextClipboard:
        if (penv->CheckExtensions())
            pval->SetBool((ptf->Flags & TextField::Flags_UseRichClipboard) != 0);
        break;
    case Member_alwaysShowSelection:
        if (penv->CheckExtensions())
            pval->SetBool((ptf->Flags & TextField::Flags_AlwaysShowSelection) != 0);
        break;
    case Member_selectionBeginIndex:
        if (!penv->CheckExtensions())
            break;
        if (ptf->IsSelectable() && pdoc->GetEditorKit())
            pval->SetNumber((Number)ptf->GetBeginIndex());
        else
            pval->SetNumber(-1);
        return true;
    case Member_selectionEndIndex:
        if (!penv->CheckExtensions())
            break;
        if (ptf->IsSelectable() && pdoc->GetEditorKit())
            pval->SetNumber((Number)ptf->GetEndIndex());
        else
            pval->SetNumber(-1);
        return true;
    case Member_selectionBkgColor:
        if (!penv->CheckExtensions() || !pdoc->GetEditorKit())
            break;
        pval->SetNumber((Number)EditorKitOf(ptf)->GetActiveSelectionBackgroundColor());
        return true;
    case Member_selectionTextColor:
        if (!penv->CheckExtensions() || !pdoc->GetEditorKit())
            break;
        pval->SetNumber((Number)EditorKitOf(ptf)->GetActiveSelectionTextColor());
        return true;
    case Member_inactiveSelectionBkgColor:
        if (!penv->CheckExtensions() || !pdoc->GetEditorKit())
            break;
        pval->SetNumber((Number)EditorKitOf(ptf)->GetInactiveSelectionBackgroundColor());
        return true;
    case Member_inactiveSelectionTextColor:
        if (!penv->CheckExtensions() || !pdoc->GetEditorKit())
            break;
        pval->SetNumber((Number)EditorKitOf(ptf)->GetInactiveSelectionTextColor());
        return true;
    case Member_noAutoSelection:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool((ptf->Flags & TextField::Flags_NoAutoSelection) != 0);
        return true;
    case Member_disableIME:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool((ptf->Flags & TextField::Flags_IMEDisabled) != 0);
        return true;
    case Member_autoFit:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool(pdoc->IsAutoFit());
        return true;
    case Member_blurX:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber(TwipsToPixels((Double)pdoc->GetFilters().BlurX));
        return true;
    case Member_blurY:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber(TwipsToPixels((Double)pdoc->GetFilters().BlurY));
        return true;
    case Member_blurStrength:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)pdoc->GetFilters().BlurStrength);
        return true;
    case Member_outline:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)pdoc->GetOutline());
        return true;
    case Member_fauxBold:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool(pdoc->GetFauxBold());
        return true;
    case Member_fauxItalic:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool(pdoc->GetFauxItalic());
        return true;
    case Member_shadowAlpha:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)((float)pdoc->GetFilters().ShadowAlpha / 255.0f));
        return true;
    case Member_shadowAngle:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)(pdoc->GetFilters().ShadowAngle * RadToDeg));
        return true;
    case Member_shadowBlurX:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber(TwipsToPixels((Double)pdoc->GetFilters().ShadowParams.BlurX));
        return true;
    case Member_shadowBlurY:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber(TwipsToPixels((Double)pdoc->GetFilters().ShadowParams.BlurY));
        return true;
    case Member_shadowDistance:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber(TwipsToPixels((Double)pdoc->GetFilters().ShadowDistance));
        return true;
    case Member_shadowHideObject:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool((pdoc->GetFilters().ShadowFlags & 0x40) != 0);
        return true;
    case Member_shadowKnockOut:
        if (!penv->CheckExtensions())
            break;
        pval->SetBool((pdoc->GetFilters().ShadowFlags & 0x20) != 0);
        return true;
    case Member_shadowQuality:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((pdoc->GetFilters().ShadowFlags & 0x80) ? 2 : 1);
        return true;
    case Member_shadowStrength:
        if (!penv->CheckExtensions())
            break;
        pval->SetNumber((Number)pdoc->GetFilters().ShadowParams.Strength);
        return true;
    case Member_restrictMember:
        break;

    default:
        if (GetStandardMember(member, pval, false))
            return true;
        break;
    }

    if (ASTextFieldObj)
        return ASTextFieldObj->GetMember(penv, name, pval);
    if (penv && name == penv->GetBuiltin(ASBuiltin___proto__))
    {
        pval->SetAsObject(pProto);
        return true;
    }
    if (pProto && pProto->GetMember(penv, name, pval))
        return true;
    if (name == "_global" && penv)
    {
        pval->SetAsObject(penv->GetSC()->pContext->pGlobal);
        return true;
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS2
