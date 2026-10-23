// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the font base (Render_Font):
// the CJK test of the hinting setup and the capital / small letter tops auto-hinting aligns glyphs to.
// Queue unit sfr_render_07 is split along its original sources (07l Render_Font).
// MS2-UNIT: sfr_render_07l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d4bf0-0x1426d4e40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"

namespace Scaleform { namespace Render {

// @0x1426d4dc0
UInt16 Font::calcTopBound(UInt16 code)
{
    RectF bounds;
    int   glyph = GetGlyphIndex(code);
    if (glyph != -1)
    {
        GetGlyphBounds(glyph, &bounds);
        // glyph space grows downward: the top is the negated upper edge
        return UInt16(-bounds.y1);
    }
    return 0;
}

// @0x1426d4c30
void Font::calcLowerUpperTop(GlyphCache* log)
{
    SInt16 lowerTop = 0;
    SInt16 upperTop = 0;
    if (LowerCaseTop == 0 && UpperCaseTop == 0)
    {
        // letters with a flat top, tried in order until the font has one
        const UByte capitals[] = "HEFTUVWXZ";
        const UByte smalls[]   = "zxvwy";

        const UByte* c;
        for (c = capitals; *c; ++c)
        {
            upperTop = calcTopBound(*c);
            if (upperTop)
                break;
        }
        if (upperTop)
        {
            for (c = smalls; *c; ++c)
            {
                lowerTop = calcTopBound(*c);
                if (lowerTop)
                    break;
            }
        }
    }

    if (lowerTop && upperTop)
    {
        LowerCaseTop = lowerTop;
        UpperCaseTop = upperTop;
        return;
    }
    if (log)
        log->LogWarning("Font '%s%s%s': No hinting chars (any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting disabled.",
                        GetName(), IsBold() ? " Bold" : "", IsItalic() ? " Italic" : "");
    LowerCaseTop = -1;
    UpperCaseTop = -1;
}

// @0x1426d4bf0
bool Font::IsCJK(UInt16 code) const
{
    // inclusive code ranges: Hangul Jamo, CJK radicals / KangXi, the CJK symbol .. extension A blocks, Yijing and the
    // unified ideographs, Hangul syllables, compatibility ideographs, the halfwidth CJK forms
    static const UInt16 cjkRanges[] =
    {
        0x1100, 0x11FF,
        0x2E80, 0x2FDF,
        0x2FF0, 0x4DB5,
        0x4DC0, 0x9FBB,
        0xAC00, 0xD7A3,
        0xF900, 0xFAFF,
        0xFF62, 0xFFDC,
        0, 0
    };
    for (unsigned i = 0; cjkRanges[i]; i += 2)
    {
        if (code >= cjkRanges[i] && code <= cjkRanges[i + 1])
            return true;
    }
    return false;
}

}} // namespace Scaleform::Render
