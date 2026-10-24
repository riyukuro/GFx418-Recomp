// Recovered Scaleform 4.1.18 Render: TextureGlyph, a glyph prerendered into a font texture (the texture glyphs of
// movie fonts, GFx FontResource / FontGlyphPacker). Layout from the exe (sfr_gfx_08j).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_RENDER_TEXTUREGLYPH_H
#define MS2_SF_INC_RENDER_TEXTUREGLYPH_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_image.h"

namespace Scaleform { namespace Render {

// 0x40 bytes (vftable 0x14318a2b0, ICF-shared). The rectangle is 16-aligned, so +0x18 is padding.
class TextureGlyph : public RefCountBase<TextureGlyph, Stat_Default_Mem>
{
public:
    Ptr<ImageBase> pImage;  // +0x10 the texture, null until bound (virtual AddRef / Release)
    RectF      UvBounds;    // +0x20 the glyph's texture coordinates
    PointF     UvOrigin;    // +0x30 its origin (pen position) in texture coordinates; not set by the ctor
    unsigned   BindIndex;   // +0x38 index of the image in the binding; ~0 when the image is held directly

    TextureGlyph() : UvOrigin(PointF::NoInit), BindIndex(~0u) {}

    // copies the image, the coordinates and the bind index (exe 0x142654a10, sfr_gfx_08j)
    TextureGlyph& operator=(const TextureGlyph& src);
};

}} // namespace Scaleform::Render

static_assert(sizeof(Scaleform::Render::TextureGlyph) == 0x40, "TextureGlyph size");

#endif
