// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextFormat object: the AS
// properties written from a paragraph and a character format (gap recovery of sfr_as2_06).
// MS2-UNIT: sfr_as2_06x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142989480-0x142989cec .text$mn
// MS2-RANGE: 0x14298c090-0x14298c9e0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
// The SDK's header-inline ObjectInterface::SetConstMemberRaw, which the exe inlines here.
inline bool SetConstMemberRawInline(ObjectInterface& obj, ASStringContext* psc, const char* pname,
                                            const Value& val)
{
    return obj.SetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val);
}

// ArrayObject::SetElement (exe 0x1429814c0, sfr_as2_07), which the exe inlines here.
SF_FORCEINLINE void SetElementInline(ArrayObject* parr, int i, const Value& val)
{
    if (i < 0 || i >= int(parr->Elements.GetSize())) return;

    parr->LengthValueOverriden = false;
    if (parr->Elements[i] == 0) parr->Elements[i] = SF_HEAP_AUTO_NEW(parr) Value;
    *parr->Elements[i] = val;
}
}

// Copies the format and mirrors each present field as an AS property; the absent ones are set to null.
// @0x142989480
void TextFormatObject::SetParagraphFormat(ASStringContext* psc, const Render::Text::ParagraphFormat& paraFmt)
{
    GetParagraphFormat() = paraFmt;
    Value nullVal(Value::NULLTYPE);
    if (paraFmt.IsAlignmentSet())
    {
        const char* newAlign = "left";
        switch (paraFmt.GetAlignment())
        {
        case Render::Text::ParagraphFormat::Align_Center:  newAlign = "center"; break;
        case Render::Text::ParagraphFormat::Align_Right:   newAlign = "right"; break;
        case Render::Text::ParagraphFormat::Align_Justify: newAlign = "justify"; break;
        default: break;
        }
        SetConstMemberRawInline(*this, psc, "align", Value(psc->CreateString(newAlign)));
    }
    else
        SetConstMemberRawInline(*this, psc, "align", nullVal);

    SetConstMemberRawInline(*this, psc, "bullet", (paraFmt.IsBulletSet()) ? Value(paraFmt.IsBullet()) : nullVal);
    SetConstMemberRawInline(*this, psc, "blockIndent",
                            (paraFmt.IsBlockIndentSet()) ? Value(Number(paraFmt.GetBlockIndent())) : nullVal);
    SetConstMemberRawInline(*this, psc, "indent",
                            (paraFmt.IsIndentSet()) ? Value(Number(paraFmt.GetIndent())) : nullVal);
    SetConstMemberRawInline(*this, psc, "leading",
                            (paraFmt.IsLeadingSet()) ? Value(Number(paraFmt.GetLeading())) : nullVal);
    SetConstMemberRawInline(*this, psc, "leftMargin",
                            (paraFmt.IsLeftMarginSet()) ? Value(Number(paraFmt.GetLeftMargin())) : nullVal);
    SetConstMemberRawInline(*this, psc, "rightMargin",
                            (paraFmt.IsRightMarginSet()) ? Value(Number(paraFmt.GetRightMargin())) : nullVal);
    if (paraFmt.IsTabStopsSet())
    {
        unsigned num = 0;
        const unsigned* ptabStops = paraFmt.GetTabStops(&num);
        Ptr<ArrayObject> parr = *SF_HEAP_NEW(psc->GetHeap()) ArrayObject(psc);
        parr->Resize((int)num);
        for (unsigned i = 0; i < num; i++)
            SetElementInline(parr, i, Value((Number)ptabStops[i]));
        SetConstMemberRawInline(*this, psc, "tabStops", Value(parr));
    }
    else
        SetConstMemberRawInline(*this, psc, "tabStops", nullVal);
}

// Copies the format and mirrors each present field as an AS property in pixels; alpha (percent) is a GFx
// extension.
// @0x14298c090
void TextFormatObject::SetTextFormat(ASStringContext* psc, const Render::Text::TextFormat& textFmt)
{
    // The exe calls the implicit TextFormat::operator= (0x142594030) out of line.
    Render::Text::TextFormat& (Render::Text::TextFormat::*const assign)(const Render::Text::TextFormat&) =
        &Render::Text::TextFormat::operator=;
    (GetTextFormat().*assign)(textFmt);
    Value nullVal(Value::NULLTYPE);

    SetConstMemberRawInline(*this, psc, "bold", textFmt.IsBoldSet() ? Value(textFmt.IsBold()) : nullVal);
    SetConstMemberRawInline(*this, psc, "italic", textFmt.IsItalicSet() ? Value(textFmt.IsItalic()) : nullVal);
    SetConstMemberRawInline(*this, psc, "underline", textFmt.IsUnderlineSet() ? Value(textFmt.IsUnderline()) : nullVal);
    SetConstMemberRawInline(*this, psc, "size", textFmt.IsFontSizeSet() ? Value((Number)textFmt.GetFontSize()) : nullVal);
    SetConstMemberRawInline(*this, psc, "font", textFmt.IsFontListSet() ? Value(psc->CreateString(textFmt.GetFontList())) : nullVal);
    SetConstMemberRawInline(*this, psc, "color", textFmt.IsColorSet() ? Value((Number)(textFmt.GetColor32() & 0xFFFFFFu)) : nullVal);
    SetConstMemberRawInline(*this, psc, "letterSpacing", textFmt.IsLetterSpacingSet() ? Value((Number)textFmt.GetLetterSpacing()) : nullVal);
    SetConstMemberRawInline(*this, psc, "kerning", textFmt.IsKerningSet() ? Value(textFmt.IsKerning()) : nullVal);
    SetConstMemberRawInline(*this, psc, "url", textFmt.IsUrlSet() ? Value(psc->CreateString(textFmt.GetUrl())) : nullVal);
    if (psc->pContext->CheckExtensions())
        SetConstMemberRawInline(*this, psc, "alpha", textFmt.IsColorSet() ? Value(Number(textFmt.GetAlpha() * 100. / 255.)) : nullVal);
}

}}} // namespace Scaleform::GFx::AS2
