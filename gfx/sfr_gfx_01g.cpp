// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextFieldDef, part two: the
// edit text definition (TextFieldDef) and its tag loaders (DefineEditText, CSMTextSettings). Its own file as these
// need the loader headers, which do not mix with the text header tree of part one (sfr_gfx_01c).
// Seventh source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258d550-0x14258d600 .text$mn
// MS2-RANGE: 0x14258d6a0-0x14258d750 .text$mn
// MS2-RANGE: 0x14258d750-0x14258d7a0 .text$mn
// MS2-RANGE: 0x14258d830-0x14258d930 .text$mn
// MS2-RANGE: 0x14258dad0-0x14258dae0 .text$mn
// MS2-RANGE: 0x14258dc80-0x14258e030 .text$mn
// MS2-RANGE: 0x14258e060-0x14258e070 .text$mn
// MS2-RANGE: 0x14258e070-0x14258e0b0 .text$mn
// MS2-RANGE: 0x14258e410-0x14258e470 .text$mn
// MS2-RANGE: 0x14258e470-0x14258ecc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

// The CharacterDef vftable and its deleting destructor (0x14258d750) belong to this source.
#define SF_GFX_CHARACTERDEF_VFTABLE
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_statictextcharacter.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx {

// The parse channel of the SWF reader, out of line for Stream (Read logs through it).
// @0x14258e410
template <> void LogBase<Stream>::LogParse(const char* pfmt, ...) const
{
    va_list args;
    va_start(args, pfmt);
    Stream* stream = (Stream*)this;
    if (stream->IsVerboseParse())
    {
        Log* log = stream->GetLog();
        if (stream->IsLogNotNull() || log)
            log->LogMessageVarg(LogChannel_Parse | LogMessage_Text, pfmt, args);
    }
    va_end(args);
}

//
// TextFieldDef
//

// @0x14258d550
TextFieldDef::TextFieldDef()
    : FontId(0), TextHeight(1.0f), MaxLength(0), LeftMargin(0.0f), RightMargin(0.0f), Indent(0.0f), Leading(0.0f),
      Flags(0), Alignment(ALIGN_LEFT)
{
    ColorV.SetRGBA(0, 0, 0, 255);
    TextRect.Clear();
}

// @0x14258d6a0
TextFieldDef::~TextFieldDef()
{
}

// @0x14258e070
void TextFieldDef::InitEmptyTextDef()
{
    SetEmptyTextDef();
    ColorV     = Color(0, 0, 0, 255);
    TextHeight = Render::PixelsToTwips(12.0f);
    SetReadOnly();
    SetSelectable();
    SetUseDeviceFont();
    SetAAForReadability();
}

// The DefineEditText body after the character id: bounds, the flag bits, then the optional font, colour, length
// and layout records, the variable name and the initial text.
// @0x14258e470
void TextFieldDef::Read(LoadProcess* p, TagType tagType)
{
    SF_UNUSED(tagType);
    Stream* in = p->GetStream();

    in->ReadRect(&TextRect);
    in->LogParse("  TextRect = { l: %f, t: %f, r: %f, b: %f }\n", (float)TextRect.x1, (float)TextRect.y1,
                 (float)TextRect.x2, (float)TextRect.y2);

    in->Align();
    bool hasText = in->ReadUInt(1) != 0;
    SetWordWrap(in->ReadUInt(1) != 0);
    SetMultiline(in->ReadUInt(1) != 0);
    SetPassword(in->ReadUInt(1) != 0);
    SetReadOnly(in->ReadUInt(1) != 0);
    in->LogParse("  WordWrap = %d, Multiline = %d, Password = %d, ReadOnly = %d\n", (int)IsWordWrap(),
                 (int)IsMultiline(), (int)IsPassword(), (int)IsReadOnly());

    bool hasColor     = in->ReadUInt(1) != 0;
    bool hasMaxLength = in->ReadUInt(1) != 0;
    bool hasFont      = in->ReadUInt(1) != 0;
    bool hasFontClass = in->ReadUInt(1) != 0;
    SetAutoSize(in->ReadUInt(1) != 0);
    bool hasLayout = in->ReadUInt(1) != 0;
    SetSelectable(in->ReadUInt(1) == 0); // the bit is NoSelect
    SetBorder(in->ReadUInt(1) != 0);
    SetWasStatic(in->ReadUInt(1) != 0);
    SetHtml(in->ReadUInt(1) != 0);
    SetUseDeviceFont(in->ReadUInt(1) == 0); // the bit is UseOutlines
    in->LogParse("  AutoSize = %d, Selectable = %d, Border = %d, Html = %d, UseDeviceFont = %d\n", (int)IsAutoSize(),
                 (int)IsSelectable(), (int)IsBorder(), (int)IsHtml(), (int)DoesUseDeviceFont());

    if (hasFont)
    {
        FontId = ResourceId(in->ReadU16());
        in->LogParse("  HasFont: font id = %d\n", FontId.GetIdIndex());
        ResourceHandle hres;
        p->GetResourceHandle(&hres, FontId);
        pFont.SetFromHandle(hres);
    }
    else if (hasFontClass)
    {
        in->ReadString(&FontClass);
        in->LogParse("  HasFontClass: font class = %s\n", FontClass.ToCStr());
    }
    if (hasFont || hasFontClass)
    {
        TextHeight = (float)in->ReadU16();
        in->LogParse("  FontHeight = %f\n", Render::TwipsToPixels(TextHeight));
    }
    if (hasColor)
    {
        in->ReadRgba(&ColorV);
        in->LogParse("  HasColor\n");
    }
    if (hasMaxLength)
    {
        MaxLength = in->ReadU16();
        in->LogParse("  HasMaxLength: len = %d\n", MaxLength);
    }
    if (hasLayout)
    {
        SetHasLayout();
        Alignment   = (alignment)in->ReadU8();
        LeftMargin  = (float)in->ReadU16();
        RightMargin = (float)in->ReadU16();
        Indent      = (float)(SInt16)in->ReadU16();
        Leading     = (float)(SInt16)in->ReadU16();
        in->LogParse("  HasLayout: alignment = %d, leftmarg = %f, rightmarg = %f, indent = %f, leading = %f\n",
                     (int)Alignment, LeftMargin, RightMargin, Indent, Leading);
    }

    in->ReadString(&VariableName);
    if (hasText)
        in->ReadString(&DefaultText);
    in->LogParse("EditTextChar, varname = %s, text = %s\n", VariableName.ToCStr(), DefaultText.ToCStr());
}

// @0x14258dec0
void SF_STDCALL GFx_DefineEditTextLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16            characterId = p->ReadU16();
    Ptr<TextFieldDef> pch = *SF_HEAP_NEW_ID(p->GetLoadHeap(), StatMD_CharDefs_Mem) TextFieldDef();
    p->LogParse("EditTextChar, id = %d\n", characterId);
    pch->Read(p, tagInfo.TagType);
    p->AddResource(ResourceId(characterId), pch);
}

// CSMTextSettings: the anti-aliasing settings of a text character; only "anti-alias for readability" is kept.
// @0x14258dc80
// MS2-FUNCTIONAL: register allocation differs in the two inlined Stream::ReadFloat reads
void SF_STDCALL GFx_CSMTextSettings(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    UInt16  characterId = p->ReadU16();
    Stream* in          = p->GetStream();

    unsigned flagType  = in->ReadUInt(2);
    unsigned gridFit   = in->ReadUInt(3);
    float    thickness = in->ReadFloat();
    float    sharpness = in->ReadFloat();
    if (in->IsVerboseParse())
    {
        static const char* const gridFitNames[] = {"None", "Pixel", "LCD"};
        p->LogParse("CSMTextSettings, id = %d\n", characterId);
        p->LogParse("  FlagType = %s, GridFit = %s\n", flagType == 0 ? "System" : "Internal", gridFitNames[gridFit]);
        p->LogParse("  Thinkness = %f, Sharpnesss = %f\n", (float)thickness, (float)sharpness);
    }

    ResourceHandle handle;
    if (p->GetResourceHandle(&handle, ResourceId(characterId)))
    {
        Resource* pres = handle.GetResourcePtr();
        if (pres)
        {
            if (pres->GetResourceType() == Resource::RT_EditTextDef)
                static_cast<TextFieldDef*>(pres)->SetAAForReadability();
            else if (pres->GetResourceType() == Resource::RT_TextDef)
                static_cast<StaticTextDef*>(pres)->Flags |= StaticTextDef::Flags_AAReadability;
        }
    }
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7TextFieldDef@GFx@Scaleform@@6B@ 0x143184748
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7CharacterDef@GFx@Scaleform@@6B@ 0x1431846c8
