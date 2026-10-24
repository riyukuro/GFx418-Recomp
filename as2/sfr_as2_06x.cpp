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

// Copies the format and mirrors each present field as an AS property; the absent ones are set to null.
// MS2-FUNCTIONAL: the exe's frame keeps the two value temporaries in a different order
// @0x142989480
void TextFormatObject::SetParagraphFormat(ASStringContext* psc, const Render::Text::ParagraphFormat& paraFmt)
{
    GetParagraphFormat() = paraFmt;
    Value nullVal(Value::NULLTYPE);

    if (paraFmt.IsAlignmentSet())
    {
        const char* palign = "left";
        switch (paraFmt.GetAlignment())
        {
        case Render::Text::ParagraphFormat::Align_Right:   palign = "right"; break;
        case Render::Text::ParagraphFormat::Align_Justify: palign = "justify"; break;
        case Render::Text::ParagraphFormat::Align_Center:  palign = "center"; break;
        default: break;
        }
        ASString align = psc->CreateString(palign);
        SetMemberRaw(psc, psc->CreateConstString("align"), Value(align));
    }
    else
        SetMemberRaw(psc, psc->CreateConstString("align"), nullVal);

    SetMemberRaw(psc, psc->CreateConstString("bullet"),
                 paraFmt.IsBulletSet() ? Value(paraFmt.IsBullet()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("blockIndent"),
                 paraFmt.IsBlockIndentSet() ? Value((Number)paraFmt.GetBlockIndent()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("indent"),
                 paraFmt.IsIndentSet() ? Value((Number)paraFmt.GetIndent()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("leading"),
                 paraFmt.IsLeadingSet() ? Value((Number)paraFmt.GetLeading()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("leftMargin"),
                 paraFmt.IsLeftMarginSet() ? Value((Number)paraFmt.GetLeftMargin()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("rightMargin"),
                 paraFmt.IsRightMarginSet() ? Value((Number)paraFmt.GetRightMargin()) : nullVal);

    if (paraFmt.IsTabStopsSet())
    {
        unsigned        num   = 0;
        const unsigned* stops = paraFmt.GetTabStops(&num);
        Ptr<ArrayObject> parr = *SF_HEAP_NEW(psc->GetHeap()) ArrayObject(psc);
        parr->Resize(num);
        for (unsigned i = 0; i < num; ++i)
            parr->SetElement(i, Value((Number)stops[i]));
        SetMemberRaw(psc, psc->CreateConstString("tabStops"), Value(parr.GetPtr()));
    }
    else
        SetMemberRaw(psc, psc->CreateConstString("tabStops"), nullVal);
}

// Copies the format and mirrors each present field as an AS property in pixels; alpha (percent) is a GFx
// extension.
// MS2-FUNCTIONAL: the exe makes the font and url strings with fewer out-of-line calls
// @0x14298c090
void TextFormatObject::SetTextFormat(ASStringContext* psc, const Render::Text::TextFormat& textFmt)
{
    GetTextFormat() = textFmt;
    Value nullVal(Value::NULLTYPE);

    SetMemberRaw(psc, psc->CreateConstString("bold"), textFmt.IsBoldSet() ? Value(textFmt.IsBold()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("italic"),
                 textFmt.IsItalicSet() ? Value(textFmt.IsItalic()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("underline"),
                 textFmt.IsUnderlineSet() ? Value(textFmt.IsUnderline()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("size"),
                 textFmt.IsFontSizeSet() ? Value((Number)textFmt.GetFontSize()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("font"),
                 textFmt.IsFontListSet() ? Value(psc->CreateString(textFmt.GetFontList())) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("color"),
                 textFmt.IsColorSet() ? Value((Number)(textFmt.GetColor32() & 0xFFFFFFu)) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("letterSpacing"),
                 textFmt.IsLetterSpacingSet() ? Value((Number)textFmt.GetLetterSpacing()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("kerning"),
                 textFmt.IsKerningSet() ? Value(textFmt.IsKerning()) : nullVal);
    SetMemberRaw(psc, psc->CreateConstString("url"),
                 textFmt.IsUrlSet() ? Value(psc->CreateString(textFmt.GetUrl())) : nullVal);
    if (psc->pContext->CheckExtensions())
        SetMemberRaw(psc, psc->CreateConstString("alpha"),
                     textFmt.IsColorSet() ? Value(textFmt.GetAlpha() * 100.0 / 255.0) : nullVal);
}

}}} // namespace Scaleform::GFx::AS2
