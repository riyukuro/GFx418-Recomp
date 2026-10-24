// Recovered Scaleform 4.1.18 GFx: the texture glyph tables of movie fonts (TextureGlyphData) and a font bound to the
// images of one movie binding (FontDataBound). Bodies: GFx_FontResource (sfr_gfx_08j); FontData and FontResource are
// declared in gfx_fontlib.h. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_FONTRESOURCE_H
#define MS2_SF_GFX_FONTRESOURCE_H

#include "gfx_fontlib.h"
#include "gfx_imageresource.h"
#include "../render/render_textureglyph.h"
#include "../render/render_font.h"

namespace Scaleform { namespace GFx {

using Render::TextureGlyph;

#ifndef SF_GFX_STATMD_FONTS_MEM
#define SF_GFX_STATMD_FONTS_MEM
enum { StatMD_Fonts_Mem = 0x105 };
#endif

// Texture glyphs of a font and the images they live in (0x48 bytes, vftable 0x14318a2c8 ICF-shared). Loaded with
// the font from a file (FileCreation) or packed when the movie is bound.
class TextureGlyphData : public RefCountBaseNTS<TextureGlyphData, StatMD_Fonts_Mem>
{
public:
    // Size of the packed glyphs and of their textures (16 bytes).
    struct TextureConfig
    {
        int NominalSize;    // +0x0 em size of a glyph in pixels
        int PadPixels;      // +0x4
        int TextureWidth;   // +0x8
        int TextureHeight;  // +0xc
    };

private:
    typedef HashLH<ResourceId, ResourcePtr<ImageResource>, FixedSizeHash<ResourceId>, StatMD_Fonts_Mem>
        ImageResourceHash;

    TextureConfig                            PackTextureConfig; // +0x10
    ArrayLH<TextureGlyph, StatMD_Fonts_Mem>  TextureGlyphs;     // +0x20
    ImageResourceHash                        GlyphsTextures;    // +0x38
    bool                                     FileCreation;      // +0x40

public:
    TextureGlyphData(unsigned glyphCount = 0, bool loadedFromFile = false) : FileCreation(loadedFromFile)
    {
        TextureGlyphs.Resize(glyphCount);
    }
    // copies the glyphs and the image table (exe 0x142654480)
    TextureGlyphData(const TextureGlyphData& src);

    void GetTextureConfig(TextureConfig* pconfig) const { *pconfig = PackTextureConfig; }
    void SetTextureConfig(const TextureConfig& config)  { PackTextureConfig = config; }
    bool IsLoadedFromFile() const                       { return FileCreation; }
    int  GetNominalSize() const                         { return PackTextureConfig.NominalSize; }
    unsigned GetConfigTextureWidth() const              { return PackTextureConfig.TextureWidth; }
    unsigned GetConfigTextureHeight() const             { return PackTextureConfig.TextureHeight; }

    unsigned            GetTextureGlyphCount() const { return (unsigned)TextureGlyphs.GetSize(); }
    // the glyph, an empty one past the end (exe 0x142655e80)
    const TextureGlyph& GetTextureGlyph(unsigned glyphIndex) const;
    // every glyph back to empty (exe 0x142657f70)
    void WipeTextureGlyphs();
    // grows the table to the index (exe 0x142654ec0)
    void AddTextureGlyph(unsigned glyphIndex, const TextureGlyph& glyph);
    // the image of a texture id (exe 0x142654e60 / 0x142654dc0)
    void AddTexture(ResourceId textureId, ImageResource* pimageRes);
    void AddTexture(ResourceId textureId, const ResourceHandle& rh);

    struct TextureGlyphVisitor
    {
        virtual ~TextureGlyphVisitor() {}
        virtual void Visit(unsigned index, TextureGlyph* ptextureGlyph) = 0;
    };
    // exe 0x142657d70
    void VisitTextureGlyphs(TextureGlyphVisitor* pvisitor);

    struct TexturesVisitor
    {
        virtual ~TexturesVisitor() {}
        virtual void Visit(ResourceId textureId, ImageResource* pimageRes) = 0;
    };
    // index entries are looked up in pbinding (exe 0x142657de0)
    void VisitTextures(TexturesVisitor* pvisitor, ResourceBinding* pbinding);
};

// A font of a movie bound to the images of one binding (0x48 bytes, vftable 0x143190bd0): forwards to the font, but
// keeps a copy of its texture glyphs whose images are looked up in the binding (FontResource::ResolveTextureGlyphs).
class FontDataBound : public Render::Font
{
public:
    // exe 0x142654210
    FontDataBound(Render::Font* pfont, ResourceBinding* pbinding);

    virtual const char* GetName() const;
    virtual int    GetGlyphIndex(UInt16 code);
    virtual float  GetAdvance(unsigned glyphIndex) const;
    virtual float  GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const;
    virtual float  GetGlyphWidth(unsigned glyphIndex) const;
    virtual float  GetGlyphHeight(unsigned glyphIndex) const;
    virtual RectF& GetGlyphBounds(unsigned glyphIndex, RectF* prect) const;
    virtual bool   IsHintedVectorGlyph(unsigned glyphIndex, unsigned hintedSize) const;
    virtual bool   IsHintedRasterGlyph(unsigned glyphIndex, unsigned hintedSize) const;
    virtual const TextureGlyph* GetTextureGlyph(unsigned glyphIndex) const;
    virtual void*  GetTextureGlyphData() const;
    virtual float  GetTextureGlyphHeight() const;
    virtual const Render::ShapeDataInterface* GetPermanentGlyphShape(unsigned glyphIndex) const;
    virtual bool   GetTemporaryGlyphShape(unsigned glyphIndex, unsigned hintedSize, Render::GlyphShape* shape);
    virtual bool   GetGlyphRaster(unsigned glyphIndex, unsigned hintedSize, Render::GlyphRaster* raster);
    virtual int    GetCharValue(unsigned glyphIndex) const;
    virtual unsigned GetGlyphShapeCount() const;
    virtual bool   HasVectorOrRasterGlyphs() const;
    virtual String GetCharRanges() const;
    virtual float  GetNominalGlyphWidth() const;
    virtual float  GetNominalGlyphHeight() const;

protected:
    Ptr<Render::Font>     pFont;    // +0x38
    Ptr<TextureGlyphData> pTGData;  // +0x40 bound copy; the glyphs have their images
};

}} // namespace Scaleform::GFx

static_assert(sizeof(Scaleform::GFx::TextureGlyphData) == 0x48, "TextureGlyphData size");
static_assert(sizeof(Scaleform::GFx::FontDataBound) == 0x48, "FontDataBound size");

#endif
