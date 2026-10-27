// Recovered Scaleform 4.1.18 Render: the glyph cache's settings (GlyphCacheParams) and the interface they are set
// through (GlyphCacheConfig, Render_GlyphCacheConfig). Plain types only, so both the kernel tree (render_renderer2d.h)
// and the gfx tree (placeholder/gfxrenderer2d.h) can include it.
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_RENDER_GLYPHCACHECONFIG_H
#define MS2_SF_RENDER_GLYPHCACHECONFIG_H

namespace Scaleform { namespace Render {

// (appended for sfr_render_07o) the glyph cache's settings (0x38 bytes)
struct GlyphCacheParams
{
    unsigned TextureWidth;          // +0x00
    unsigned TextureHeight;
    unsigned NumTextures;
    unsigned MaxSlotHeight;
    unsigned SlotPadding;           // +0x10
    unsigned TexUpdWidth;
    unsigned TexUpdHeight;
    float    MaxRasterScale;        // +0x1c
    unsigned MaxVectorCacheSize;    // +0x20
    float    FauxItalicAngle;
    float    FauxBoldRatio;
    float    OutlineRatio;
    float    ShadowQuality;         // +0x30
    bool     UseAutoFit;            // +0x34
    bool     UseVectorOnFullCache;  // +0x35
    bool     FenceWaitOnFullCache;  // +0x36

    // the glyph cache's ctor has it inlined; the client's copy (0x1422f5320, gfxui/gfxrendersinglethread.cpp) shows
    // the argument order: the texture count first, the padding is always 2
    GlyphCacheParams(unsigned numTextures = 1, unsigned textureWidth = 1024, unsigned textureHeight = 1024,
                     unsigned maxSlotHeight = 48)
        : TextureWidth(textureWidth), TextureHeight(textureHeight), NumTextures(numTextures),
          MaxSlotHeight(maxSlotHeight), SlotPadding(2), TexUpdWidth(256), TexUpdHeight(512), MaxRasterScale(1.0f),
          MaxVectorCacheSize(500), FauxItalicAngle(0.25f), FauxBoldRatio(0.045f), OutlineRatio(0.01f),
          ShadowQuality(1.0f), UseAutoFit(true), UseVectorOnFullCache(false), FenceWaitOnFullCache(true)
    {
    }
};

// the glyph cache's settings interface (Render_GlyphCacheConfig)
class GlyphCacheConfig
{
public:
    virtual ~GlyphCacheConfig() {}
    virtual bool                    SetParams(const GlyphCacheParams& params) = 0;
    virtual const GlyphCacheParams& GetParams() const = 0;
    virtual void                    ClearCache() = 0;
};

}} // namespace Scaleform::Render

#endif
