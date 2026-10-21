// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text layout TU
// (Render_TextLayout): the Builder that records a text field as a byte stream of fixed-size records (chars,
// colours, fonts, lines, selections, underlines, cursor, images) plus the fonts / images / ref-counted objects
// they point at, and the TextLayout that freezes one Builder into a single block and reads the records back.
// Queue unit sfr_render_04 is split along its original sources (04c Render_TextLayout).
// MS2-UNIT: sfr_render_04c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142664b70-0x142666790 .text$mn

#include <string.h>
#include "ms2/scaleform/include/render/render_textlayout.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"

namespace Scaleform { namespace Render {

// Byte size of each record kind, indexed by RecordType.
static const unsigned TextLayout_RecordSize[] =
{
    sizeof(TextLayout::CharRecord),
    sizeof(TextLayout::ColorRecord),
    sizeof(TextLayout::BackgroundRecord),
    sizeof(TextLayout::LineRecord),
    sizeof(TextLayout::FontRecord),
    sizeof(TextLayout::SelectionRecord),
    sizeof(TextLayout::UnderlineRecord),
    sizeof(TextLayout::CursorRecord),
    sizeof(TextLayout::ImageRecord),
    sizeof(TextLayout::RefCntDataRecord)
};

// ---------------------------------------------------------------------------------------------------------------
// TextLayout

// @0x142664c50
TextLayout::TextLayout(const Builder& builder)
    : pFonts(0), FontCount(0), pImages(0), ImageCount(0), pRefCntData(0), RefCntCount(0)
{
    Create(builder);
}

// @0x142664da0
TextLayout::~TextLayout()
{
    Clear();
}

// Drops the references the layout holds and frees its block.
// @0x142666100
void TextLayout::Clear()
{
    UPInt i;
    for (i = 0; i < FontCount; ++i)
        pFonts[i]->Release();
    for (i = 0; i < ImageCount; ++i)
        pImages[i]->Release();
    for (i = 0; i < RefCntCount; ++i)
        pRefCntData[i]->Release();
    Data.Clear();
}

// One block holds the records and, from the next pointer boundary on, the three pointer tables.
// @0x1426661c0
void TextLayout::Create(const Builder& builder)
{
    pFonts      = 0; FontCount   = 0;
    pImages     = 0; ImageCount  = 0;
    pRefCntData = 0; RefCntCount = 0;

    Bounds  = builder.Bounds;
    ClipBox = builder.ClipBox;
    Param   = builder.Param;

    DataSize = builder.Data.GetSize();
    UPInt tables = (DataSize + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
    UPInt ptrs   = builder.Fonts.GetSize() + builder.Images.GetSize() + builder.RefCntData.GetSize();
    Data.Resize(tables + ptrs * sizeof(void*));

    UPInt at = tables;
    if (builder.Fonts.GetSize())
    {
        pFonts    = (Font**)&Data[at];
        FontCount = builder.Fonts.GetSize();
        at += FontCount * sizeof(void*);
    }
    if (builder.Images.GetSize())
    {
        pImages    = (Image**)&Data[at];
        ImageCount = builder.Images.GetSize();
        at += ImageCount * sizeof(void*);
    }
    if (builder.RefCntData.GetSize())
    {
        pRefCntData = (RefCountImpl**)&Data[at];
        RefCntCount = builder.RefCntData.GetSize();
        at += RefCntCount * sizeof(void*);
    }

    if (builder.Data.GetSize())
        memcpy(&Data[0], &builder.Data[0], DataSize);
    if (pFonts)
        memcpy(pFonts, &builder.Fonts[0], FontCount * sizeof(void*));
    if (pImages)
        memcpy(pImages, &builder.Images[0], ImageCount * sizeof(void*));
    if (pRefCntData)
        memcpy(pRefCntData, &builder.RefCntData[0], RefCntCount * sizeof(void*));

    UPInt i;
    for (i = 0; i < FontCount; ++i)
        pFonts[i]->AddRef();
    for (i = 0; i < ImageCount; ++i)
        pImages[i]->AddRef();
    for (i = 0; i < RefCntCount; ++i)
        pRefCntData[i]->AddRef();
}

// @0x142666460
UPInt TextLayout::ReadNext(UPInt pos, Record* rec) const
{
    if (pos >= DataSize)
        return 0;
    UByte* dst = (UByte*)rec;
    *dst++ = Data[pos++];   // the tag tells how many bytes follow
    unsigned left = TextLayout_RecordSize[rec->mChar.Tag];
    while (--left)
        *dst++ = Data[pos++];
    return pos;
}

// ---------------------------------------------------------------------------------------------------------------
// TextLayout::Builder

// @0x142664b70
TextLayout::Builder::Builder(MemoryHeap* heap)
    : Param(), Bounds(0, 0, 0, 0), ClipBox(0, 0, 0, 0),
      Data(heap), Fonts(heap), Images(heap), RefCntData(heap), LastFont(0), LastScale(1.0f)
{
}

// Appends one record; its size comes from the tag in its first byte.
SF_INLINE void TextLayout::Builder::record(const void* rec)
{
    const UByte* src = (const UByte*)rec;
    unsigned size = TextLayout_RecordSize[src[0]];
    while (size--)
        Data.PushBack(*src++);
}

// @0x142665000
void TextLayout::Builder::AddChar(unsigned glyphIndex, float advance, bool invisible, bool fauxBold, bool fauxItalic)
{
    UByte flags = 0;
    if (invisible)
        flags |= Flag_Invisible;
    if (fauxBold)
        flags |= Flag_FauxBold;
    if (fauxItalic)
        flags |= Flag_FauxItalic;
    CharRecord rec = { Record_Char, flags, UInt16(glyphIndex), advance };
    record(&rec);
}

// Lays out a UTF-8 string in the last font set, glyph by glyph (no kerning).
// @0x1426659d0
void TextLayout::Builder::AddText(const char* utfStr)
{
    UInt32 code;
    while ((code = UTF8Util::DecodeNextChar(&utfStr)) != 0)
    {
        unsigned glyphIndex = LastFont->GetGlyphIndex(UInt16(code));
        AddChar(glyphIndex, LastFont->GetAdvance(glyphIndex) * LastScale, false, false, false);
    }
}

// @0x142665ce0
void TextLayout::Builder::ChangeColor(UInt32 color)
{
    ColorRecord rec = { Record_Color, 0, 0, color };
    record(&rec);
}

// @0x1426664c0
void TextLayout::Builder::SetBackground(UInt32 bkColor, UInt32 brColor)
{
    BackgroundRecord rec = { Record_Background, 0, 0, bkColor, brColor };
    record(&rec);
}

// The font is remembered once for the layout to hold.
// @0x142665e30
void TextLayout::Builder::ChangeFont(Font* f, float size)
{
    FontRecord rec = { Record_Font, 0, 0, size, f };
    record(&rec);
    LastFont  = f;
    LastScale = size / f->GetNominalGlyphHeight();
    for (UPInt i = 0; i < Fonts.GetSize(); ++i)
        if (f == Fonts[i])
            return;
    Fonts.PushBack(f);
}

// @0x1426655c0
void TextLayout::Builder::AddRefCntData(RefCountImpl* p)
{
    RefCntDataRecord rec = { Record_RefCntData, 0, p };
    record(&rec);
    for (UPInt i = 0; i < RefCntData.GetSize(); ++i)
        if (p == RefCntData[i])
            return;
    RefCntData.PushBack(p);
}

// @0x142666620
void TextLayout::Builder::SetNewLine(float x, float y)
{
    LineRecord rec = { Record_NewLine, 0, 0, x, y };
    record(&rec);
}

// @0x142665860
void TextLayout::Builder::AddSelection(const RectF& r, UInt32 color)
{
    SelectionRecord rec = { Record_Selection, 0, 0, color, r.x1, r.y1, r.x2, r.y2 };
    record(&rec);
}

// @0x142665b60
void TextLayout::Builder::AddUnderline(float x, float y, float len, TextUnderlineStyle style, UInt32 color)
{
    UnderlineRecord rec = { Record_Underline, 0, UInt16(style), x, y, len, color };
    record(&rec);
}

// @0x142665190
void TextLayout::Builder::AddCursor(const RectF& r, UInt32 color)
{
    CursorRecord rec = { Record_Cursor, 0, 0, color, r.x1, r.y1, r.x2, r.y2 };
    record(&rec);
}

// @0x142665300
void TextLayout::Builder::AddImage(Image* img, float scaleX, float scaleY, float baseLine, float advance)
{
    ImageRecord rec = { Record_Image, 0, 0, img, scaleX, scaleY, baseLine, advance };
    record(&rec);
    for (UPInt i = 0; i < Images.GetSize(); ++i)
        if (img == Images[i])
            return;
    Images.PushBack(img);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143191890
// MS2-PIN: ??_7?$RefCountBase@VTextLayout@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143191890
// MS2-PIN: ??_7TextLayout@Render@Scaleform@@6B@ 0x143191898
