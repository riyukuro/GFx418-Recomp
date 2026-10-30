// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextField, back half (the
// property setters, the geometry setters that keep the text rectangle in place, the composition string setters, the
// document listener's view callbacks and the container templates the field instantiates).
// Queue unit sfr_gfx_03 is split along its original sources: this file is the upper half of GFx_TextField; the lower
// half is sfr_gfx_03e (SetDirtyFlag 0x1425bc060 and TranslatorChanged 0x1425beab0 stay there).
// MS2-UNIT: sfr_gfx_03f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425bb530-0x1425bc060 .text$mn
// MS2-RANGE: 0x1425bc080-0x1425beab0 .text$mn
// MS2-RANGE: 0x1425beb10-0x1425bf3c0 .text$mn
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@UTextFilter@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_7TextFilter@Text@Render@Scaleform@@6B@ 0x1431899f8
// MS2-PIN: ?SetRange@?$RangeDataArray@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@V?$Array@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@5@@Scaleform@@QEAAXAEBV?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@2@@Z 0x1425bc870
// MS2-PIN: ?PushBack@?$ArrayData@V?$Point@M@Render@Scaleform@@U?$AllocatorLH@V?$Point@M@Render@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXAEBV?$Point@M@Render@2@@Z 0x1425bb530
// MS2-PIN: ?Remove@Iterator@?$RangeDataArray@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@V?$Array@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@5@@Scaleform@@AEAAXXZ 0x1425bb5f0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Point@M@Render@Scaleform@@U?$AllocatorLH@V?$Point@M@Render@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x1425bb8f0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@U?$AllocatorGH@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1425bb990
// MS2-PIN: ?Resize@?$ArrayData@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@U?$AllocatorGH@V?$RangeData@UUrlZone@CSSHolderBase@TextField@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAX_K@Z 0x1425bbab0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$StringLH_HashNode@V?$Ptr@UImageDesc@Text@Render@Scaleform@@@Scaleform@@UNoCaseHashFunctor@String@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@V?$Ptr@UImageDesc@Text@Render@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$StringLH_HashNode@V?$Ptr@UImageDesc@Text@Render@Scaleform@@@Scaleform@@UNoCaseHashFunctor@String@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425bf1a0

#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_fontmanager.h"
#include "../include/gfx/gfx_fonthandle.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_valueinfo.h"
#include "../include/gfx/text_editorkit.h"
#include "../include/render/render_twips.h"
#include "../include/gfx/gfx_statictextcharacter.h"
#include "../include/gfx/text_stylesheet.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform {

namespace UTF8Util {
// (the kernel's sf_utf8util.h has it; its default arguments clash with the include/ copy, so only this one)
void SF_STDCALL EncodeString(char* buff, const wchar_t* chars, SPInt length);
}

namespace GFx {

// Text replacement and custom word wrapping hook (state; the bodies are in sfr_gfx_02f).
class Translator : public State
{
public:
    enum WordWrappingTypes
    {
        WWT_Default      = 0,
        WWT_Asian        = 0x1,
        WWT_Prohibition  = 0x2,
        WWT_NoHangulWrap = 0x4,
        WWT_Hyphenation  = 0x8
    };

    // One line the text engine is about to wrap.
    struct LineFormatDesc
    {
        const wchar_t* pParaText;               // +0
        UPInt          ParaTextLen;             // +8
        const float*   pWidths;                 // +0x10 width of the line up to each character
        UPInt          LineStartPos;            // +0x18
        UPInt          NumCharsInLine;          // +0x20
        float          VisibleRectWidth;        // +0x28
        float          CurrentLineWidth;        // +0x2c
        float          LineWidthBeforeWordWrap; // +0x30
        float          DashSymbolWidth;         // +0x34
        unsigned       Alignment;               // +0x38
        UPInt          ProposedWordWrapPoint;   // +0x40
        bool           UseHyphenation;          // +0x48
    };

    unsigned WWMode; // +0x18

    virtual unsigned GetCaps() const;
    virtual void     Translate(void* ptranslateInfo);
    virtual bool     OnWordWrapping(LineFormatDesc* pdesc);
};

// The shadowStyle / shadowColor state of an AS2 field. 0x40 bytes (as in sfr_gfx_03e).
struct TextField::ShadowParams : public NewOverrideBase<0x143>   // StatMV_ActionScript_Mem
{
    Render::Color            ShadowColor;    // +0x00
    ASString                 ShadowStyleStr; // +0x08
    ArrayLH<Render::PointF>  ShadowOffsets;  // +0x10
    ArrayLH<Render::PointF>  TextOffsets;    // +0x28

    ShadowParams(ASStringManager* psm) : ShadowStyleStr(psm->GetEmptyStringNode())
    {
        ShadowColor = Render::Color(0, 0, 0, 255);
    }
};

// sfr_gfx_03e has the body (0x1425b5290).
template<> void InteractiveObject::ModifyOptimizedPlayListLocal<TextField>();

// The field's editor (the document view keeps it as the render-side base).
static inline Text::EditorKit* EditorOf(Render::Text::DocView* pdoc)
{
    return static_cast<Text::EditorKit*>(pdoc->GetEditorKit());
}

// The editor's composition string, with a reference (NULL when none).
static inline Ptr<Text::CompositionString> CompositionOf(Text::EditorKit* peditor)
{
    return static_cast<Text::CompositionString*>(peditor->GetCompositionString());
}

// The scroll notifications go to the AVM side (AvmTextFieldBase::OnScroll).
static inline void NotifyScroll(TextField* pfield)
{
    if (pfield->HasAvmObject())
        pfield->GetAvmObjImpl()->ToAvmTextFieldBase()->OnScroll();
}

// TextField::SetDirtyFlag (0x1425bc060) is defined in the lower half (sfr_gfx_03e); the exe inlines it into this half's
// callers, so they use this copy of its body.
static inline void SetDirtyFlagOf(TextField* pfield)
{
    static_cast<Render::TreeText*>(pfield->GetRenderNode())->NotifyLayoutChanged();
}

// TextField::NotifyChanged (0x1425b9da0, sfr_gfx_03e), inlined by the exe like SetDirtyFlag.
static inline void NotifyChangedOf(TextField* pfield)
{
    if (pfield->HasAvmObject())
        pfield->GetAvmObjImpl()->ToAvmTextFieldBase()->NotifyChanged();
    SetDirtyFlagOf(pfield);
}

}} // namespace Scaleform::GFx

namespace Scaleform {

// ---- container templates of the field

// @0x1425bb530
template void ArrayData<Render::PointF, AllocatorLH<Render::PointF, Stat_Default_Mem>, ArrayDefaultPolicy>::PushBack(
    const Render::PointF&);
// @0x1425bb8f0
template void ArrayDataBase<Render::PointF, AllocatorLH<Render::PointF, Stat_Default_Mem>, ArrayDefaultPolicy>::Reserve(
    const void*, UPInt);
// @0x1425bb990
template void ArrayDataBase<RangeData<GFx::TextField::CSSHolderBase::UrlZone>,
                            AllocatorGH<RangeData<GFx::TextField::CSSHolderBase::UrlZone>, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x1425bbab0
template void ArrayData<RangeData<GFx::TextField::CSSHolderBase::UrlZone>,
                        AllocatorGH<RangeData<GFx::TextField::CSSHolderBase::UrlZone>, Stat_Default_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);
// @0x1425bb5f0
template void RangeDataArray<GFx::TextField::CSSHolderBase::UrlZone>::Iterator::Remove();
// @0x1425bc870
template void RangeDataArray<GFx::TextField::CSSHolderBase::UrlZone>::SetRange(const TypedRangeData&);
// MS2-FUNCTIONAL 0x1425bf1a0: same rehash and calls; the frame layout differs
// @0x1425bf1a0
template void decltype(StringHashLH<Ptr<Render::Text::ImageDesc> >::mHash)::BaseType::setRawCapacity(void*, UPInt);

} // namespace Scaleform

namespace Scaleform { namespace GFx {

// ---- TextField

// @0x1425bb5b0
void TextField::ReleaseCompositionString()
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        peditor->ReleaseCompositionString();
        SetDirtyFlagOf(this);
    }
}

// MS2-FUNCTIONAL 0x1425bb680: same removal; register allocation in the inlined String compare differs (391 bytes against 390)
// @0x1425bb680
void TextField::RemoveIdImageDescAssoc(const char* idStr)
{
    if (pImageDescAssoc)
        pImageDescAssoc->Remove(idStr);
}

// The cursor stays inside the new text; the bound variable and the layout follow the change.
// @0x1425bb810
void TextField::ReplaceTextA(const wchar_t* pstr, UPInt beginPos, UPInt endPos, UPInt strLen)
{
    pDocument->ReplaceText(pstr, beginPos, endPos, strLen);
    if (EditorOf(pDocument))
    {
        // the cursor stays unless its position is gone
        UPInt len = pDocument->GetStyledText()->GetLength();
        if (EditorOf(pDocument)->GetCursorPos() > len)
            EditorOf(pDocument)->SetCursorPos(len, false);
    }
    if (HasAvmObject())
        GetAvmObjImpl()->ToAvmTextFieldBase()->UpdateVariable();
    Flags |= Flags_NeedUpdateLayout;
    NotifyChangedOf(this);
}

// @0x1425bba30
void TextField::ResetBlink(bool state, bool blocked)
{
    if (EditorOf(pDocument))
    {
        if (EditorOf(pDocument)->HasCursor())
        {
            EditorOf(pDocument)->ResetBlink(state, blocked);
            SetDirtyFlagOf(this);
        }
    }
}

// @0x1425bbb90
void TextField::SetBackground(bool b)
{
    Render::Color c(pDocument->GetBackgroundColor());
    c.SetAlpha(b ? 0xFF : 0);
    SetBackgroundColor(c);
    SetDirtyFlagOf(this);
}

// @0x1425bbbe0
void TextField::SetBackgroundColor(const Render::Color& c)
{
    pDocument->SetBackgroundColor(c.ToColor32());
    SetDirtyFlagOf(this);
}

// @0x1425bbc10
void TextField::SetBackgroundColor(UInt32 c)
{
    pDocument->SetBackgroundColor((pDocument->GetBackgroundColor() & 0xFF000000u) | (c & 0xFFFFFFu));
    SetDirtyFlagOf(this);
}

// @0x1425bbc50
void TextField::SetBorder(bool b)
{
    Render::Color c(pDocument->GetBorderColor());
    c.SetAlpha(b ? 0xFF : 0);
    SetBorderColor(c);
    SetDirtyFlagOf(this);
}

// @0x1425bbca0
void TextField::SetBorderColor(const Render::Color& c)
{
    pDocument->SetBorderColor(c.ToColor32());
    SetDirtyFlagOf(this);
}

// @0x1425bbcd0
void TextField::SetBorderColor(UInt32 c)
{
    pDocument->SetBorderColor((pDocument->GetBorderColor() & 0xFF000000u) | (c & 0xFFFFFFu));
    SetDirtyFlagOf(this);
}

// The field owns the holder from now on.
// @0x1425bbd10
void TextField::SetCSSData(CSSHolderBase* pcssData)
{
    pCSSData = pcssData;
}

// The candidate list shows its entries in the font at the cursor (bold / italic as there).
// @0x1425bbd70
void TextField::SetCandidateListFont(DisplayObject* pcandidateList)
{
    Ptr<FontHandle> pcandFont;
    Text::EditorKit* peditor = EditorOf(pDocument);
    UPInt pos = peditor ? peditor->GetCursorPos() : SF_MAX_UPINT;

    const Render::Text::TextFormat*      ptextFmt;
    const Render::Text::ParagraphFormat* pparaFmt;
    pDocument->GetStyledText()->GetTextAndParagraphFormat(&ptextFmt, &pparaFmt, pos);
    String   fontList(ptextFmt->GetFontList());
    unsigned fontFlags = (ptextFmt->IsBold() ? Render::Font::FF_Bold : 0u) |
                         (ptextFmt->IsItalic() ? Render::Font::FF_Italic : 0u);
    if (!pParent)
        return;
    Ptr<FontHandle> pfont =
        *static_cast<FontHandle*>(pParent->GetFontManager()->CreateFontHandle(fontList.ToCStr(), fontFlags, true, 0));
    if (pfont)
    {
        Sprite* psprite = static_cast<Sprite*>(pcandidateList);
        pcandFont = *SF_HEAP_NEW(psprite->GetMovieImpl()->GetMovieHeap())
            FontHandle(0, pfont->GetFont(), "$IMECandidateListFont", 0,
                       static_cast<MovieDef*>(pfont->pSourceMovieDef.GetPtr()));
        psprite->SetIMECandidateListFont(pcandFont);
    }
}

// @0x1425bbed0
void TextField::SetCompositionStringPosition(UPInt pos)
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        Ptr<Text::CompositionString> pcs = CompositionOf(peditor);
        if (pcs)
        {
            pcs->SetPosition(pos);
            SetDirtyFlagOf(this);
        }
    }
}

// @0x1425bbf50
void TextField::SetCompositionStringText(const wchar_t* pstr, UPInt len)
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        Ptr<Text::CompositionString> pcs = CompositionOf(peditor);
        if (pcs)
        {
            pcs->SetText(pstr, len);
            SetDirtyFlagOf(this);
        }
    }
}

// @0x1425bbfe0
void TextField::SetCursorInCompositionString(UPInt pos)
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        Ptr<Text::CompositionString> pcs = CompositionOf(peditor);
        if (pcs)
        {
            pcs->SetCursorPosition(pos);
            SetDirtyFlagOf(this);
        }
    }
}

// The filters become the text's blur / shadow / glow parameters.
// @0x1425bc080
void TextField::SetFilters(const Render::FilterSet* filters)
{
    if (!filters)
        return;
    pFilters = const_cast<Render::FilterSet*>(filters);
    Render::Text::TextFilter textFilter;
    for (unsigned i = 0; i < filters->GetFilterCount(); ++i)
    {
        const Render::Filter* pfilter = filters->GetFilter(i);
        if (pfilter)
            textFilter.LoadFilterDesc(pfilter);
    }
    SetTextFilters(textFilter);
}

// The text rectangle keeps its top; the height is in pixels.
// @0x1425bc370
void TextField::SetHeight(Double height)
{
    RectF r = pDocument->GetViewRect();
    r.y2 = r.y1 + float(Render::PixelsToTwips(height));
    pDocument->SetViewRect(r);
    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
}

// The field's own formats (from its definition) under the document's defaults; an empty definition takes the
// engine's default values under them instead.
// @0x1425bc420
void TextField::SetInitialFormatsAsDefault()
{
    Render::Text::TextFormat      textFmt(Memory::GetHeapByAddress(this));
    Render::Text::ParagraphFormat paraFmt;
    Render::Text::StyledText*     ptext   = pDocument->GetStyledText();
    const Render::Text::TextFormat*      pdocTextFmt = ptext->GetDefaultTextFormat();
    const Render::Text::ParagraphFormat* pdocParaFmt = ptext->GetDefaultParagraphFormat();

    if (!pDef->IsEmptyTextDef())
    {
        GetInitialFormats(&textFmt, &paraFmt);
        if (pdocTextFmt)
            textFmt = pdocTextFmt->Merge(textFmt);
        if (pdocParaFmt)
            paraFmt = pdocParaFmt->Merge(paraFmt);
    }
    else
    {
        if (pdocTextFmt)
            textFmt = *pdocTextFmt;
        if (pdocParaFmt)
            paraFmt = *pdocParaFmt;
        Render::Text::TextFormat      defTextFmt(Memory::GetHeapByAddress(this));
        Render::Text::ParagraphFormat defParaFmt;
        defTextFmt.InitByDefaultValues();
        defParaFmt.InitByDefaultValues();
        textFmt = defTextFmt.Merge(textFmt);
        paraFmt = defParaFmt.Merge(paraFmt);
    }
    pDocument->SetDefaultTextFormat(textFmt);
    Flags |= Flags_NeedUpdateLayout;
    pDocument->SetDefaultParagraphFormat(paraFmt);
    Flags |= Flags_NeedUpdateLayout;
}

// @0x1425bce30
bool TextField::SetRestrict(const ASString& restrStr)
{
    if (!pDocument->HasEditorKit())
        CreateEditorKit();
    return EditorOf(pDocument)->SetRestrict(String(restrStr.ToCStr()));
}

// @0x1425bced0
void TextField::SetRotation(Double rotation)
{
    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
    DisplayObjectBase::SetRotation(rotation);
}

// A selectable field needs an editor; an unselectable one keeps it (read-only fields still scroll).
// @0x1425bcf10
void TextField::SetSelectable(bool f)
{
    Ptr<Text::EditorKit> peditor = EditorOf(pDocument);
    if (f)
    {
        peditor = CreateEditorKit();
        peditor->SetSelectable();
    }
    else if (peditor)
        peditor->ClearSelectable();
}

// Both ends are clamped into the text.
// @0x1425bcfc0
void TextField::SetSelection(SPInt beginIndex, SPInt endIndex)
{
    if (!pDocument->HasEditorKit())
        CreateEditorKit();
    if (pDocument->HasEditorKit())
    {
        beginIndex = Alg::Max<SPInt>(0, beginIndex);
        endIndex   = Alg::Max<SPInt>(0, endIndex);
        SPInt len  = SPInt(pDocument->GetStyledText()->GetLength());
        endIndex   = Alg::Min(len, endIndex);
        beginIndex = Alg::Min(len, beginIndex);
        EditorOf(pDocument)->SetSelection(UPInt(beginIndex), UPInt(endIndex));
        SetDirtyFlagOf(this);
    }
}

// The AS2 shadow parameters keep their own copy of the color.
// @0x1425bd080
void TextField::SetShadowColor(UInt32 c)
{
    pDocument->SetShadowColor(c);
    if (pShadow)
    {
        // the argument is 0xRRGGBB; the shadow keeps its alpha
        UInt32 rgb = pDocument->GetShadowColor();
        pShadow->ShadowColor.SetBlue((UByte)rgb);
        pShadow->ShadowColor.SetGreen((UByte)(rgb >> 8));
        pShadow->ShadowColor.SetRed((UByte)(rgb >> 16));
    }
    SetDirtyFlagOf(this);
}

// The AS2 shadowStyle string, "s{x,y}..t{x,y}..": the shadow's and the text's offsets in pixels. A malformed string
// keeps the previous one (parsed again); the soft (filter) shadow is turned off for the old style one.
// @0x1425bd100
bool TextField::SetShadowStyle(const char* pstr)
{
    if (!pShadow)
        if ((pShadow = SF_HEAP_AUTO_NEW(this) ShadowParams(GetStringManager())) == 0)
            return false;

    UInt32 rgb = pDocument->GetShadowColor();
    pShadow->ShadowColor.SetBlue((UByte)rgb);
    pShadow->ShadowColor.SetGreen((UByte)(rgb >> 8));
    pShadow->ShadowColor.SetRed((UByte)(rgb >> 16));
    pDocument->DisableSoftShadow();

reset:
    pShadow->ShadowOffsets.Clear();
    pShadow->TextOffsets.Clear();

    // Format is like "s{1,0.5}{-1,0.5}t{0,0}"; a bad string falls back to the stored one.
    const char* p = pstr;
    ArrayLH<Render::PointF>* offsets = 0;
    while (*p)
    {
        if (*p == 's' || *p == 'S')
        {
            offsets = &pShadow->ShadowOffsets;
            p++;
        }
        else if (*p == 't' || *p == 'T')
        {
            offsets = &pShadow->TextOffsets;
            p++;
        }
        else if (*p == '{' && offsets)
        {
            char pn[24];
            p++;
            const char* q = p;
            while (*q && *q != ',') q++;
            if (!*q || q - p > 23) { pstr = pShadow->ShadowStyleStr.ToCStr(); goto reset; }
            memcpy(pn, p, q - p);
            pn[q - p] = 0;
            float x = (float)(SFstrtod(pn, NULL) * 20.0);
            q++;
            p = q;

            while (*q && *q != '}') q++;
            if (!*q || q - p > 23) { pstr = pShadow->ShadowStyleStr.ToCStr(); goto reset; }
            memcpy(pn, p, q - p);
            pn[q - p] = 0;
            float y = (float)(SFstrtod(pn, NULL) * 20.0);
            q++;
            p = q;

            offsets->PushBack(Render::PointF(x, y));
        }
        else
        {
            pstr = pShadow->ShadowStyleStr.ToCStr();
            goto reset;
        }
    }

    if (*pstr)
        pShadow->ShadowStyleStr = GetStringManager()->CreateString(pstr);
    SetDirtyFlagOf(this);
    return true;
}

// @0x1425bd4e0
void TextField::SetStateChangeFlags(UByte flags)
{
    InteractiveObject::Flags = (InteractiveObject::Flags & ~Mask_ChangedFlags) | (UInt32(flags & 0xF) << 16);
    Flags |= Flags_ForceOneTimeAdvance;
    InteractiveObject::Flags |= Mask_ReqPartialAdvance;
    if (!IsInPlayList())
        AddToPlayList();
    ModifyOptimizedPlayListLocal<TextField>();
}

// The text goes in as UTF-8 (on the stack when short enough).
// @0x1425bd530
void TextField::SetText(const wchar_t* ptext, bool html)
{
    bool currHtml = IsHtml();
    if (html && !currHtml)        { Flags |= Flags_Html; }
    else if (!html && currHtml)   { Flags &= ~Flags_Html; }

    UPInt len    = SFwcslen(ptext);
    UPInt outLen = len * 3 + 1;
    char  sbuf[512];
    char* pbuf = (outLen <= sizeof(sbuf)) ? sbuf : (char*)SF_HEAP_AUTO_ALLOC(this, outLen);
    UTF8Util::EncodeString(pbuf, ptext, -1);
    SetTextValue(pbuf, html, true);
    if (len >= sizeof(sbuf))
        SF_FREE(pbuf);
}

// The new color applies to the whole text and to what is typed later.
// @0x1425bd630
void TextField::SetTextColor(UInt32 c)
{
    Render::Text::TextFormat fmt(Memory::GetHeapByAddress(this));
    fmt.SetColor32(c);
    pDocument->SetTextFormat(fmt, 0, SF_MAX_UPINT);
    fmt = *pDocument->GetDefaultTextFormat();
    fmt.SetColor32(c);
    pDocument->SetDefaultTextFormat(fmt);
    Flags |= Flags_NeedUpdateLayout;
    SetDirtyFlagOf(this);
}

// MS2-FUNCTIONAL 0x1425bd7a0: same compare and copy; the exe copies ShadowParams.Offset.x through an integer register
// @0x1425bd7a0
void TextField::SetTextFilters(const Render::Text::TextFilter& f)
{
    if (pDocument && pDocument->SetFilters(f))
        SetDirtyFlagOf(this);
}

// The text (UTF-8, HTML when html is set) becomes the field's text unless it is the same and nothing asks for a new
// layout. The movie's translator may replace it first (HTML is stripped for a translator that takes plain text).
// MS2-FUNCTIONAL 0x1425bd9a0: same calls and order; the exe inlines GetStyleSheet on the untranslated HTML path,
// HasStyleSheet and SetDirtyFlag
// @0x1425bd9a0
bool TextField::SetTextValue(const char* ptext, bool html, bool notifyVariable)
{
    if (OriginalTextValue == ptext && !(Flags & Flags_NeedUpdateLayout))
        return false;
    Flags &= ~Flags_NeedUpdateLayout;

    if (HasAvmObject() && GetAvmObjImpl()->ToAvmTextFieldBase()->HasStyleSheet())
    {
        Flags |= Flags_Html;
        html = true;
    }

    OriginalTextValue = ptext;
    if (html)
        Flags |= Flags_OriginalIsHtml;
    else
        Flags &= ~Flags_OriginalIsHtml;
    ptext = OriginalTextValue.ToCStr();

    bool translated = false;
    if (!(Flags & Flags_NoTranslate))
    {
        Ptr<Translator> ptrans = *static_cast<Translator*>(
            GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_Translator));
        if (ptrans)
        {
            // Translator::TranslateInfo (sfr_gfx_02f) with the key and result buffers.
            struct TextTranslateInfo
            {
                enum
                {
                    Flag_Translated = 0x1,
                    Flag_ResultHtml = 0x2,
                    Flag_SourceHtml = 0x4
                };
                const wchar_t*              pKey;          // +0
                WStringBuffer*              pResult;       // +8
                const char*                 pInstanceName; // +0x10
                UByte                       Flags;         // +0x18
                WStringBuffer::Reserve<512> ResultRes;
                WStringBuffer::Reserve<512> KeyRes;
                WStringBuffer               ResultBuf;
                WStringBuffer               KeyBuf;

                TextTranslateInfo(const char* pname)
                    : pKey(NULL), pResult(&ResultBuf), pInstanceName(pname), Flags(0), ResultBuf(ResultRes),
                      KeyBuf(KeyRes) {}
            } info(IsInstanceBasedNameFlagSet() ? "" : GetName().ToCStr());

            if (html && !(ptrans->GetCaps() & 1))
            {
                // the translator takes plain text: the HTML is parsed and its text passed
                Render::Text::TextFormat      textFmt(Memory::GetHeapByAddress(this));
                Render::Text::ParagraphFormat paraFmt;
                GetInitialFormats(&textFmt, &paraFmt);
                pDocument->ParseHtml(ptext, SF_MAX_UPINT, (Flags & Flags_CondenseWhite) != 0, NULL, GetStyleSheet(),
                                     &textFmt, &paraFmt);
                pDocument->GetStyledText()->GetText(&info.KeyBuf);
                if (ptrans->GetCaps() & 2)
                    info.KeyBuf.StripTrailingNewLines();
                info.pKey = info.KeyBuf.GetBuffer();
                ptrans->Translate(&info);
            }
            else
            {
                info.KeyBuf.Resize(UTF8Util::GetLength(ptext) + 1);
                UTF8Util::DecodeString(info.KeyBuf.GetBuffer(), ptext);
                info.pKey = info.KeyBuf.GetBuffer();
                if (html)
                    info.Flags |= TextTranslateInfo::Flag_SourceHtml;
                ptrans->Translate(&info);
            }

            translated = (info.Flags & TextTranslateInfo::Flag_Translated) != 0;
            if (translated)
            {
                if (info.Flags & TextTranslateInfo::Flag_ResultHtml)
                {
                    Render::Text::TextFormat      textFmt(Memory::GetHeapByAddress(this));
                    Render::Text::ParagraphFormat paraFmt;
                    GetInitialFormats(&textFmt, &paraFmt);
                    Render::Text::StyledText::HTMLImageTagInfoArray imageInfos(Memory::GetHeapByAddress(this));
                    pDocument->ParseHtml(info.ResultBuf.ToWStr(), SF_MAX_UPINT, (Flags & Flags_CondenseWhite) != 0,
                                         &imageInfos, GetStyleSheet(), &textFmt, &paraFmt);
                    if (imageInfos.GetSize() > 0)
                        ProcessImageTags(imageInfos);
                }
                else
                {
                    // the old text's first format goes over the whole translation
                    const Render::Text::TextFormat*      ptextFmt;
                    const Render::Text::ParagraphFormat* pparaFmt;
                    Render::Text::StyledText* pstyled = pDocument->GetStyledText();
                    pstyled->GetTextAndParagraphFormat(&ptextFmt, &pparaFmt, 0);
                    pDocument->GetStyledText()->SetDefaultTextFormat(ptextFmt);
                    pDocument->GetStyledText()->SetDefaultParagraphFormat(pparaFmt);
                    pDocument->SetText(info.ResultBuf.ToWStr());
                }
            }
        }
    }

    if (!translated)
    {
        if (html)
        {
            Render::Text::TextFormat      textFmt(Memory::GetHeapByAddress(this));
            Render::Text::ParagraphFormat paraFmt;
            GetInitialFormats(&textFmt, &paraFmt);
            Render::Text::StyledText::HTMLImageTagInfoArray imageInfos(Memory::GetHeapByAddress(this));
            pDocument->ParseHtml(ptext, SF_MAX_UPINT, (Flags & Flags_CondenseWhite) != 0, &imageInfos,
                                 GetStyleSheet(), &textFmt, &paraFmt);
            if (imageInfos.GetSize() > 0)
                ProcessImageTags(imageInfos);
        }
        else
            pDocument->SetText(ptext);
    }

    // a cursor past the new text's end goes to it
    if (pDocument->HasEditorKit())
    {
        Text::EditorKit* peditor = EditorOf(pDocument);
        if (!peditor->IsReadOnly())
        {
            UPInt len = pDocument->GetStyledText()->GetLength();
            if (peditor->GetCursorPos() > len)
                peditor->SetCursorPos(len, false);
        }
    }

    if (HasAvmObject() && GetAvmObjImpl()->ToAvmTextFieldBase()->HasStyleSheet() &&
        pDocument->MayHaveUrl())
        CollectUrlZones();

    if (notifyVariable && HasAvmObject())
        GetAvmObjImpl()->ToAvmTextFieldBase()->UpdateVariable();

    if (translated)
    {
        if (HasAvmObject())
            GetAvmObjImpl()->ToAvmTextFieldBase()->NotifyChanged();
        SetDirtyFlagOf(this);
    }

    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
    return true;
}

// @0x1425be280
void TextField::SetWideCursor(bool wideCursor)
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        if (wideCursor)
            peditor->SetWideCursor();
        else
            peditor->ClearWideCursor();
        SetDirtyFlagOf(this);
    }
}

// The text rectangle keeps its left side; the width is in pixels.
// @0x1425be2d0
void TextField::SetWidth(Double width)
{
    RectF r = pDocument->GetViewRect();
    r.x2 = r.x1 + float(Render::PixelsToTwips(width));
    pDocument->SetViewRect(r);
    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
}

// Matrix2x4::SetInverse, which the exe inlines into SetX and SetY (our cl keeps the in-class copy out of line).
static __forceinline void SetInverseOf(Render::Matrix2F& d, const Render::Matrix2F& m)
{
    float det = m.M[0][0] * m.M[1][1] - m.M[0][1] * m.M[1][0];
    if (det == 0)
    {
        d.SetIdentity();
        d.M[0][3] = -m.M[0][3];
        d.M[1][3] = -m.M[1][3];
    }
    else
    {
        float inv = 1 / det;
        d.M[0][0] =  m.M[1][1] * inv;
        d.M[1][1] =  m.M[0][0] * inv;
        d.M[0][1] = -m.M[0][1] * inv;
        d.M[1][0] = -m.M[1][0] * inv;
        d.M[0][3] = -(d.M[0][0] * m.M[0][3] + d.M[0][1] * m.M[1][3]);
        d.M[1][3] = -(d.M[1][0] * m.M[0][3] + d.M[1][1] * m.M[1][3]);
    }
}

// Matrix2x4::TransformByInverse: a copy of m inverted (SetInverse of a second copy), then p through it.
static __forceinline Render::PointF TransformByInverseOf(const Render::Matrix2F& m, const Render::PointF& p)
{
    Render::Matrix2F inv;
    SetInverseOf(inv, Render::Matrix2F(m));
    return inv.Transform(p);
}

// x is where the text rectangle's left side goes (in the parent): the origin moves by the rectangle's offset.
// MS2-FUNCTIONAL 0x1425be380: same math, inverse inlined as in the exe; float scheduling around it differs
// @0x1425be380
void TextField::SetX(Double x)
{
    if (NumberUtil::IsNaN(x))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(x) || NumberUtil::IsPOSITIVE_INFINITY(x))
        x = 0;
    Matrix m    = GetMatrix();
    Double newX = Render::PixelsToTwips(x);
    Render::PointF p((float)newX);
    p = TransformByInverseOf(m, p);
    Render::PointF r = pDocument->GetViewRect().TopLeft();
    p.x -= r.x;
    p = m.Transform(p);
    DisplayObjectBase::SetX(Double(Render::TwipsToPixels(p.x)));
    if (pGeomData)
        pGeomData->X = Alg::IRound(newX);
}

// @0x1425be630
void TextField::SetXScale(Double xscale)
{
    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
    DisplayObjectBase::SetXScale(xscale);
}

// y is where the text rectangle's top goes (in the parent).
// MS2-FUNCTIONAL 0x1425be670: same math, inverse inlined as in the exe; float scheduling around it differs
// @0x1425be670
void TextField::SetY(Double y)
{
    if (NumberUtil::IsNaN(y))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(y) || NumberUtil::IsPOSITIVE_INFINITY(y))
        y = 0;
    Double newY = Render::PixelsToTwips(y);
    Matrix m    = GetMatrix();
    Render::PointF p(0, (float)newY);
    p = TransformByInverseOf(m, p);
    Render::PointF r = pDocument->GetViewRect().TopLeft();
    p.y -= r.y;
    p = m.Transform(p);
    DisplayObjectBase::SetY(Double(Render::TwipsToPixels(p.y)));
    if (pGeomData)
        pGeomData->Y = Alg::IRound(newY);
}

// @0x1425be930
void TextField::SetYScale(Double yscale)
{
    Flags |= Flags_NeedUpdateGeomData;
    SetDirtyFlagOf(this);
    DisplayObjectBase::SetYScale(yscale);
}

// The display info's position (the current one when unset), in pixels relative to the text rectangle.
// MS2-FUNCTIONAL 0x1425be970: same math; the exe calls the out-parameter TransformByInverse overload
// @0x1425be970
Render::PointF TextField::TransformToTextRectSpace(const GFx::Value::DisplayInfo& info) const
{
    const Matrix&  m = GetMatrix();
    Render::PointF p;
    p.x = info.IsFlagSet(GFx::Value::DisplayInfo::V_x) ? float(Render::PixelsToTwips(info.X)) : float(pGeomData->X);
    p.y = info.IsFlagSet(GFx::Value::DisplayInfo::V_y) ? float(Render::PixelsToTwips(info.Y)) : float(pGeomData->Y);
    p = m.TransformByInverse(p);
    const RectF& r = pDocument->GetViewRect();
    p.x -= r.x1;
    p.y -= r.y1;
    p = m.Transform(p);
    return Render::PointF(Render::TwipsToPixels(p.x), Render::TwipsToPixels(p.y));
}

// The geometry data's position is the text rectangle's top-left corner in the parent.
// MS2-FUNCTIONAL 0x1425beb10: same math in doubles; the exe inlines the point transform
// @0x1425beb10
DisplayObjectBase::GeomDataType& TextField::UpdateAndGetGeomData(GeomDataType* pgeomData, bool force)
{
    GetGeomData(*pgeomData);
    if (force || (Flags & Flags_NeedUpdateGeomData))
    {
        const RectF&  r  = pDocument->GetViewRect();
        const Matrix& m  = GetMatrix();
        Double        x1 = r.x1, y1 = r.y1;
        Double        px = Double(m.Sx()) * x1 + Double(m.Shx()) * y1 + Double(m.Tx());
        Double        py = Double(m.Shy()) * x1 + Double(m.Sy()) * y1 + Double(m.Ty());
        pgeomData->X     = Alg::IRound(px);
        pgeomData->Y     = Alg::IRound(py);
        SetGeomData(*pgeomData);
        Flags &= ~Flags_NeedUpdateGeomData;
    }
    return *pgeomData;
}

// The style sheet's "a" and "a:link" styles over each URL run; the run's formatting is saved again after.
// MS2-FUNCTIONAL 0x1425bec30: same lookups and calls; the exe hoists the zone stride
// @0x1425bec30
void TextField::UpdateUrlStyles()
{
    if (!pCSSData)
        return;
    for (UPInt i = 0, n = pCSSData->UrlZones.Count(); i < n; ++i)
    {
        if (!pCSSData->HasASStyleSheet())
            continue;
        const Render::Text::Style* pastyle =
            pCSSData->GetTextStyleManager()->GetStyle(Render::Text::StyleManagerBase::CSS_Tag, "a");
        const Render::Text::Style* plinkStyle =
            pCSSData->GetTextStyleManager()->GetStyle(Render::Text::StyleManagerBase::CSS_Tag, "a:link");
        Render::Text::TextFormat fmt(Memory::GetHeapByAddress(this));
        if (pastyle)
            fmt = fmt.Merge(pastyle->mTextFormat);
        if (plinkStyle)
            fmt = fmt.Merge(plinkStyle->mTextFormat);

        RangeData<CSSHolderBase::UrlZone>& zone = pCSSData->UrlZones[i];
        const UPInt startPos = UPInt(zone.FirstIndex()), endPos = UPInt(zone.NextIndex());
        pDocument->SetTextFormat(fmt, startPos, endPos);
        zone.GetData().SavedFmt = *pDocument->GetStyledText()->CopyStyledText(startPos, endPos);
    }
}

// ---- TextField::TextDocumentListener (the view's callbacks)

// GetTextField() is 03e's out-of-line helper with no exe copy (the exe inlines the subtraction); spell it out here so this
// unit links on its own.
#define MS2_LISTENER_TF() reinterpret_cast<TextField*>(reinterpret_cast<UPInt>(this) - offsetof(TextField, TextDocListener))

// @0x1425bef80
void TextField::TextDocumentListener::View_OnChanged(Render::Text::DocView& view)
{
    SetDirtyFlagOf(MS2_LISTENER_TF());
}

// @0x1425befb0
void TextField::TextDocumentListener::View_OnHScroll(Render::Text::DocView& view, unsigned newScroll)
{
    SF_UNUSED(newScroll);
    NotifyScroll(MS2_LISTENER_TF());
}

// The translator decides the line's wrap point; it sees the widths in pixels.
// MS2-FUNCTIONAL 0x1425bf000: same copy and scaling; the exe inlines GetTextField
// @0x1425bf000
bool TextField::TextDocumentListener::View_OnLineFormat(Render::Text::DocView& view,
                                                        Render::Text::DocView::LineFormatDesc& desc)
{
    Ptr<Translator> ptrans = *static_cast<Translator*>(
        MS2_LISTENER_TF()->GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_Translator));
    if (!ptrans)
        return false;

    Translator::LineFormatDesc tdesc;
    tdesc.pParaText               = desc.pParaText;
    tdesc.ParaTextLen             = desc.ParaTextLen;
    tdesc.pWidths                 = desc.pWidths;
    tdesc.LineStartPos            = desc.LineStartPos;
    tdesc.NumCharsInLine          = desc.NumCharsInLine;
    tdesc.VisibleRectWidth        = Render::TwipsToPixels(desc.VisibleRectWidth);
    tdesc.CurrentLineWidth        = Render::TwipsToPixels(desc.CurrentLineWidth);
    tdesc.LineWidthBeforeWordWrap = Render::TwipsToPixels(desc.LineWidthBeforeWordWrap);
    tdesc.DashSymbolWidth         = Render::TwipsToPixels(desc.DashSymbolWidth);
    tdesc.Alignment               = desc.Alignment;
    tdesc.ProposedWordWrapPoint   = desc.ProposedWordWrapPoint;
    tdesc.UseHyphenation          = desc.UseHyphenation;
    for (UPInt i = 0; i < tdesc.NumCharsInLine; ++i)
        desc.pWidths[i] = Render::TwipsToPixels(desc.pWidths[i]);
    if (ptrans->OnWordWrapping(&tdesc))
    {
        desc.ProposedWordWrapPoint = tdesc.ProposedWordWrapPoint;
        desc.UseHyphenation        = tdesc.UseHyphenation;
        return true;
    }
    return false;
}

// @0x1425bf110
void TextField::TextDocumentListener::View_OnMaxScrollChanged(Render::Text::DocView& view)
{
    NotifyScroll(MS2_LISTENER_TF());
}

// @0x1425bf160
void TextField::TextDocumentListener::View_OnVScroll(Render::Text::DocView& view, unsigned newScroll)
{
    SF_UNUSED(newScroll);
    NotifyScroll(MS2_LISTENER_TF());
}

}} // namespace Scaleform::GFx
