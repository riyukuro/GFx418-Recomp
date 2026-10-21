// Recovered Scaleform 4.1.18 Render: the font interface (glyph source of one face). Split out of
// render_fontprovider.h so the text units can use it without windows.h; the virtual order is the exe's.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_RENDER_FONT_H
#define MS2_SF_INC_RENDER_FONT_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_string.h"

namespace Scaleform { namespace Render {

template<class T> class Rect;
typedef Rect<float> RectF;
class TextureGlyph;
class ShapeDataInterface;
class GlyphShape;
class GlyphRaster;

// Glyph source of one face: vslot 1 returns the face name, the style/code page/device bits live at +0x1c.
class Font : public RefCountBase<Font, Stat_Default_Mem>
{
public:
    enum NativeHintingRange
    {
        DontHint,
        HintCJK,
        HintAll
    };

    enum FontFlags
    {
        FF_Italic          = 0x0001,
        FF_Bold            = 0x0002,
        FF_Style_Mask      = FF_Italic | FF_Bold,
        FF_DeviceFont      = 0x0010,
        FF_CodePage_Mask   = 0x0300,
        FF_CreateFont_Mask = FF_Style_Mask | FF_CodePage_Mask,
        FF_NotResolved     = 0x0040 // a placeholder the font manager resolves through the font library / provider
    };

    virtual ~Font() {}
    virtual const char* GetName() const = 0;

    // glyph metrics, shapes and texture glyphs (vslots 2..17); declared only (pure in the SDK) so the
    // placeholder subclasses of the recovered units stay concrete
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
    virtual void   SetTextureGlyphData(void*);
    virtual float  GetTextureGlyphHeight() const;
    virtual const ShapeDataInterface* GetPermanentGlyphShape(unsigned glyphIndex) const;
    virtual bool   GetTemporaryGlyphShape(unsigned glyphIndex, unsigned hintedSize, GlyphShape* shape);
    virtual bool   GetGlyphRaster(unsigned glyphIndex, unsigned hintedSize, GlyphRaster* raster);
    virtual int    GetCharValue(unsigned glyphIndex) const;

    // Number of glyph shapes the font carries; 0 for fonts exported without glyphs (+0x90).
    virtual unsigned GetGlyphShapeCount() const { return 0; }
    // The font carries vector or raster glyphs of its own (+0x98; declared only).
    virtual bool HasVectorOrRasterGlyphs() const;

    unsigned GetFontFlags() const { return Flags; }
    float    GetAscent() const     { return Ascent; }
    float    GetDescent() const    { return Descent; }
    float    GetLeading() const    { return Leading; }
    bool     IsItalic() const      { return (Flags & FF_Italic) != 0; }
    bool     IsBold() const        { return (Flags & FF_Bold) != 0; }
    bool     IsDeviceFont() const  { return (Flags & FF_DeviceFont) != 0; }
    void     SetNotResolvedFlag()  { Flags |= FF_NotResolved; }
    bool     IsResolved() const    { return (Flags & FF_NotResolved) == 0; }

    // A request matches on style always, on the device bit and the code page only when it asks for them.
    static bool SF_STDCALL MatchFontFlags_Static(unsigned fontFlags, unsigned matchFlags)
    {
        unsigned checked = FF_Style_Mask | (matchFlags & FF_DeviceFont) |
                           ((matchFlags & FF_CodePage_Mask) ? FF_CodePage_Mask : 0);
        return (fontFlags & checked) == (matchFlags & (FF_CreateFont_Mask | FF_DeviceFont));
    }
    bool MatchFontFlags(unsigned matchFlags) const { return MatchFontFlags_Static(GetFontFlags(), matchFlags); }
    bool MatchFont(const char* name, unsigned matchFlags) const
    {
        return MatchFontFlags(matchFlags) && !String::CompareNoCase(GetName(), name);
    }
    // fd can stand in for this font: same name and the same style / code page.
    bool MatchSubstituteFont(Font* fd) const
    {
        const char* name  = fd->GetName();
        unsigned    flags = fd->GetFontFlags() & FF_CreateFont_Mask;
        return MatchFont(name, flags);
    }

protected:
    float    Ascent;   // +0x10
    float    Descent;  // +0x14
    float    Leading;  // +0x18
    unsigned Flags;    // +0x1c
};

}} // namespace Scaleform::Render

#endif
