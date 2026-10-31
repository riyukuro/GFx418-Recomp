// Recovered Scaleform 4.1.18 GFx: FontPackParams, the binding state that asks for the glyphs of movie fonts to be
// prerendered into textures, and FontGlyphPacker, which does it when a movie is bound: every glyph shape is measured,
// identical shapes of one font are rendered once, the rects are packed into pages of the configured texture size and
// each page is rasterized into an A8 image. Bodies: GFx_FontGlyphPacker (sfr_gfx_08m).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_FONTGLYPHPACKER_H
#define MS2_SF_GFX_FONTGLYPHPACKER_H

#include "gfx_state.h"
#include "gfx_fontresource.h"
#include "gfx_imagecreator.h"
#include "../kernel/sf_hash.h"
#include "../kernel/sf_array.h"
// The rasterizer's containers include the kernel/ heap headers, whose MemoryHeap and AllocInfo the include/kernel
// sf_memory.h of the gfx headers already declares: skip them.
#ifndef MS2_SF_KERNEL_MEMORYHEAP_H
#define MS2_SF_KERNEL_MEMORYHEAP_H
#define MS2_SF_KERNEL_ALLOCINFO_H
#endif
#include "../render/render_rectpacker.h"
#include "../render/render_rasterizer.h"

namespace Scaleform { namespace GFx {

// Packing options of the movie font glyphs (state State_FontPackParams). Only the fields the packer reads.
class FontPackParams : public State
{
public:
    typedef TextureGlyphData::TextureConfig TextureConfig;

    // Glyph shapes are in twips of a box this tall (some fonts overshoot the nominal 1024); NominalSize pixels span it.
    static const float GlyphBoundBox;

    void GetTextureConfig(TextureConfig* pconfig) const { *pconfig = PackTextureConfig; }
    bool GetUseSeparateTextures() const                 { return SeparateTextures; }
    int  GetGlyphCountLimit() const                     { return GlyphCountLimit; }

protected:
    TextureConfig PackTextureConfig; // +0x18
    bool          SeparateTextures;  // +0x28 each font gets textures of its own
    int           GlyphCountLimit;   // +0x2c fonts with more glyphs are not packed (0: no limit)
};

// Renders the glyphs of the fonts of one binding into textures (0x408 bytes, vftable 0x1431917f8).
class FontGlyphPacker : public RefCountBaseNTS<FontGlyphPacker, Stat_Default_Mem>
{
    // One glyph to place: its pixel rect, then its place in a texture (0x40 bytes).
    struct GlyphInfo
    {
        FontResource*  pFont;       // +0x00
        unsigned       GlyphIndex;  // +0x08
        unsigned       GlyphReuse;  // +0x0c an earlier glyph with the same geometry, ~0 if none
        unsigned       TextureIdx;  // +0x10 ~0 until packed
        RectF          Bounds;      // +0x20 in pixels: the padded glyph bounds, then its rect in the texture
        Render::PointF Origin;      // +0x30 glyph origin in the texture
    };

    // A glyph shape of a font, keyed by its geometry so equal shapes share one texture rect.
    struct GlyphGeometryKey
    {
        const FontResource*               pFont;
        const Render::ShapeDataInterface* pShape;
        UInt32                            Hash;

        GlyphGeometryKey() : pFont(0), pShape(0), Hash(0) {}
        GlyphGeometryKey(const FontResource* font, const Render::ShapeDataInterface* shape, UInt32 hash)
            : pFont(font), pShape(shape), Hash(hash)
        {
        }
        // hash functor of the table
        UPInt operator()(const GlyphGeometryKey& key) const
        {
            return (UPInt)key.Hash ^ ((UPInt)key.pFont >> 6) ^ (UPInt)key.pFont;
        }
        bool operator==(const GlyphGeometryKey& other) const;
    };

    typedef HashLH<GlyphGeometryKey, unsigned, GlyphGeometryKey, Stat_Default_Mem> GlyphGeometryHashType;

public:
    FontGlyphPacker(FontPackParams* params, ImageCreator* pimageCreator, Log* plog, ResourceId* ptextureIdGen,
                    MemoryHeap* fontHeap, bool threadedLoading);
    ~FontGlyphPacker();

    // the fonts that have no texture glyphs yet (and are within the glyph count limit) get them
    void GenerateFontBitmaps(const Array<FontResource*>& fonts);

private:
    FontGlyphPacker(const FontGlyphPacker&);
    const FontGlyphPacker& operator=(const FontGlyphPacker&);

    void     generateGlyphInfo(Array<GlyphInfo>* glyphs, FontResource* font);
    unsigned packGlyphRects(Array<GlyphInfo>* glyphs, unsigned start, unsigned end, unsigned texIdx);
    unsigned packGlyphRects(Array<GlyphInfo>* glyphs);
    void     rasterizeGlyph(Render::RawImage* texImage, GlyphInfo* gi);
    void     generateTextures(Array<GlyphInfo>* glyphs, unsigned numTextures);

    // The packer's copy starts at the defaults (48 px glyphs, 3 px pad, 1024x1024 pages) before the params override it.
    struct PackConfig : FontPackParams::TextureConfig
    {
        PackConfig() { NominalSize = 48; PadPixels = 3; TextureWidth = 1024; TextureHeight = 1024; }
    };

    FontPackParams*               pFontPackParams;   // +0x10
    PackConfig                    PackTextureConfig; // +0x18
    ResourceId*                   pTextureIdGen;     // +0x28
    Ptr<ImageCreator>             pImageCreator;     // +0x30
    Ptr<Log>                      pLog;              // +0x38
    MemoryHeap*                   pFontHeap;         // +0x40
    Render::RectPacker            Packer;            // +0x48
    Render::Rasterizer            Ras;               // +0x128
    GlyphGeometryHashType         GlyphGeometryHash; // +0x3f8
    bool                          ThreadedLoading;   // +0x400
};

// Equal shapes read the same paths, styles and coordinates (exe 0x142661610).
bool   IsEqualGeometry(const Render::ShapeDataInterface& a, const Render::ShapeDataInterface& b);
// Bernstein hash of the fill paths of the first layer, 0 for an empty shape (exe 0x142661000).
UInt32 ComputeGeometryHash(const Render::ShapeDataInterface& shape);

inline bool FontGlyphPacker::GlyphGeometryKey::operator==(const GlyphGeometryKey& other) const
{
    return pFont == other.pFont && IsEqualGeometry(*pShape, *other.pShape);
}

// Packs the fonts' glyphs when both the params and an image creator are given (exe 0x1426612b0).
void GFx_GenerateFontBitmaps(FontPackParams* params, const Array<FontResource*>& fonts, ImageCreator* pimageCreator,
                             Log* plog, ResourceId* ptextureIdGen, MemoryHeap* fontHeap, bool threadedLoading);

}} // namespace Scaleform::GFx

#endif
