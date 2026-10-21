// Recovered Scaleform 4.1.18 Render: the glyph rasterization parameters (GlyphParam, TextFieldParam) and
// TextLayout, the record stream a text field hands to the renderer (chars, colours, fonts, lines, selections,
// underlines, cursor, images). The DocView / LineBuffer fill a TextLayout::Builder.
// Bodies: Render_TextLayout (unit sfr_render_04..07); only what the recovered units use is declared.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXTLAYOUT_H
#define MS2_SF_RENDER_TEXTLAYOUT_H

#include <math.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_arraystaticbuff.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_stats.h"

namespace Scaleform { namespace Render {

class Font;
class Image;
class FontCacheHandle;

enum TextUnderlineStyle
{
    TextUnderline_Single,
    TextUnderline_Thick,
    TextUnderline_Dotted,
    TextUnderline_DottedThick,
    TextUnderline_Dithered,
    TextUnderline_DitheredThick
};

// How one glyph (or a whole field) is rasterized; sizes and blur in 12.4 fixed point (0x18 bytes).
struct GlyphParam
{
    FontCacheHandle* pFont;         // +0x00
    UInt16           GlyphIndex;    // +0x08
    UInt16           FontSize;      // +0x0a
    UInt16           Flags;         // +0x0c FlagsType
    UInt16           BlurX;         // +0x0e
    UInt16           BlurY;         // +0x10
    UInt16           BlurStrength;  // +0x12

    enum FlagsType
    {
        OptRead     = 0x0001,
        AutoFit     = 0x0002,
        Stretch     = 0x0004,
        FauxBold    = 0x0008,
        FauxItalic  = 0x0010,
        KnockOut    = 0x0020,
        HideObject  = 0x0040,
        FineBlur    = 0x0080,
        BitmapFont  = 0x0100,
        UseRaster   = 0x0200,
        OutlineMask = 0xF000
    };

    void Clear()
    {
        pFont = 0; GlyphIndex = 0; FontSize = 0; Flags = 0;
        BlurX = 0; BlurY = 0; BlurStrength = 16;
    }

    float GetFontSize() const     { return float(FontSize) / 16.0f; }
    float GetBlurX() const        { return float(BlurX) / 16.0f; }
    float GetBlurY() const        { return float(BlurY) / 16.0f; }
    float GetBlurStrength() const { return float(BlurStrength) / 16.0f; }
    unsigned GetOutline() const   { return Flags >> 12; }

    void SetOptRead(bool f)    { if (f) Flags |= OptRead;    else Flags &= ~OptRead; }
    void SetAutoFit(bool f)    { if (f) Flags |= AutoFit;    else Flags &= ~AutoFit; }
    void SetStretch(bool f)    { if (f) Flags |= Stretch;    else Flags &= ~Stretch; }
    void SetUseRaster(bool f)  { if (f) Flags |= UseRaster;  else Flags &= ~UseRaster; }
    void SetFauxBold(bool f)   { if (f) Flags |= FauxBold;   else Flags &= ~FauxBold; }
    void SetFauxItalic(bool f) { if (f) Flags |= FauxItalic; else Flags &= ~FauxItalic; }
    void SetKnockOut(bool f)   { if (f) Flags |= KnockOut;   else Flags &= ~KnockOut; }
    void SetHideObject(bool f) { if (f) Flags |= HideObject; else Flags &= ~HideObject; }
    void SetFineBlur(bool f)   { if (f) Flags |= FineBlur;   else Flags &= ~FineBlur; }
    void SetFontSize(float s)     { FontSize = UInt16(floor(s * 16.0)); }
    void SetBlurX(float v)        { BlurX = UInt16(v * 16.0f + 0.5f); }
    void SetBlurY(float v)        { BlurY = UInt16(v * 16.0f + 0.5f); }
    void SetBlurStrength(float v) { BlurStrength = UInt16(v * 16.0f + 0.5f); }
    // a bitmap font is drawn as is: readability on, no auto fit, no stretch
    void SetBitmapFont(bool f)
    {
        if (f)
        {
            Flags |= BitmapFont;
            SetOptRead(true);
            SetAutoFit(false);
            SetStretch(false);
        }
        else
            Flags &= ~BitmapFont;
    }
    void SetOutline(unsigned outline)
    {
        Flags &= ~OutlineMask;
        Flags |= (outline & 0xF) << 12;
    }
};

// The parameters of a whole text field: the text and its drop shadow (0x40 bytes).
struct TextFieldParam
{
    enum { ShadowDisabled = 0x01 };

    GlyphParam TextParam;       // +0x00 (pFont / GlyphIndex / FontSize unused)
    GlyphParam ShadowParam;     // +0x18
    UInt32     ShadowColor;     // +0x30
    float      ShadowOffsetX;   // +0x34
    float      ShadowOffsetY;   // +0x38

    void Clear()
    {
        TextParam.Clear();
        ShadowParam.Clear();
        ShadowColor = 0; ShadowOffsetX = 0; ShadowOffsetY = 0;
    }
    TextFieldParam() { Clear(); }
};

class TextLayout : public RefCountBase<TextLayout, StatRender_Text_Mem>
{
public:
    // Collects the records of a layout.
    class Builder
    {
        enum { StaticDataSize = 1024, StaticFontSize = 32, StaticImageSize = 32, StaticRefCntSize = StaticFontSize };

    public:
        Builder(MemoryHeap* heap);

        void SetBounds(const RectF& b)         { Bounds = b; }
        void SetClipBox(const RectF& b)        { ClipBox = b; }
        void SetParam(const TextFieldParam& p) { Param = p; }

        void AddChar(unsigned glyphIndex, float advance, bool invisible, bool fauxBold, bool fauxItalic);
        void AddText(const char* utfStr);
        void AddImage(Image* img, float scaleX, float scaleY, float baseLine, float advance);
        void AddSelection(const RectF& r, UInt32 color);
        void AddUnderline(float x, float y, float len, TextUnderlineStyle style, UInt32 color);
        void AddCursor(const RectF& r, UInt32 color);
        void AddRefCntData(RefCountImpl*);
        void ChangeColor(UInt32 color);
        void SetBackground(UInt32 bkColor, UInt32 brColor);
        void ChangeFont(Font* f, float size);
        void SetNewLine(float x, float y);

    private:
        Builder(const Builder&);
        void operator=(const Builder&);

        TextFieldParam                                       Param;      // +0x00
        RectF                                                Bounds;     // +0x40
        RectF                                                ClipBox;    // +0x50
        ArrayStaticBuffPOD<UByte, StaticDataSize>            Data;
        ArrayStaticBuffPOD<Font*, StaticFontSize>            Fonts;
        ArrayStaticBuffPOD<Image*, StaticImageSize>          Images;
        ArrayStaticBuffPOD<RefCountImpl*, StaticRefCntSize>  RefCntData;
        Font*                                                LastFont;
        float                                                LastScale;
        friend class TextLayout;
    };
};

}} // namespace Scaleform::Render

#endif
