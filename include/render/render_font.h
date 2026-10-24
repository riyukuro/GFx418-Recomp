// Recovered Scaleform 4.1.18 Render: the font interface (glyph source of one face). Split out of
// render_fontprovider.h so the text units can use it without windows.h; the virtual order is the exe's.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_RENDER_FONT_H
#define MS2_SF_INC_RENDER_FONT_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/include/render/render_stats.h"

namespace Scaleform { namespace Render {

template<class T> class Rect;
typedef Rect<float> RectF;
class TextureGlyph;
class ShapeDataInterface;
class GlyphShape;
class GlyphRaster;
class FontCacheHandle;
class FontCacheHandleManager;
class GlyphCache;

// The font's link to the glyph cache's handle of it (0x10 bytes); dropped with the font. releaseFont lives with the
// font cache handle unit (0x1426d4b40).
class FontCacheHandleRef
{
    AtomicPtr<FontCacheHandleManager> pManager;     // +0x00
    FontCacheHandle* volatile         pFontHandle;  // +0x08

    void releaseFont();
    // (appended for sfr_render_07k) drops the manager without telling it (it is destroying the handle itself)
    void releaseFont_NoNotify();

    friend class FontCacheHandleManager;

public:
    FontCacheHandleRef() : pFontHandle(0) {}
    ~FontCacheHandleRef() { releaseFont(); }
};

// Glyph source of one face: vslot 1 returns the face name, the style/code page/device bits live at +0x1c.
class Font : public RefCountBase<Font, StatRender_Font_Mem>
{
    friend class FontCacheHandleManager;   // (sfr_render_07k) reaches hRef

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
        FF_NotResolved     = 0x0040, // a placeholder the font manager resolves through the font library / provider
        FF_PixelAligned    = 0x8000  // glyphs are snapped to pixels (bitmap fonts)
    };

    Font(unsigned fontFlags = 0)
        : Ascent(0), Descent(0), Leading(0), Flags(fontFlags), LowerCaseTop(0), UpperCaseTop(0)
    {
    }
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
    // The character ranges the font covers, as text (+0xa0; declared only).
    virtual String GetCharRanges() const;
    // The em square the glyph coordinates are given in (+0xa8 / +0xb0).
    virtual float GetNominalGlyphWidth() const  { return 512.0f; }
    virtual float GetNominalGlyphHeight() const { return 1024.0f; }

    unsigned GetFontFlags() const { return Flags; }
    float    GetAscent() const     { return Ascent; }
    float    GetDescent() const    { return Descent; }
    float    GetLeading() const    { return Leading; }
    bool     IsItalic() const      { return (Flags & FF_Italic) != 0; }
    bool     IsBold() const        { return (Flags & FF_Bold) != 0; }
    bool     IsDeviceFont() const  { return (Flags & FF_DeviceFont) != 0; }
    bool     IsPixelAligned() const { return (Flags & FF_PixelAligned) != 0; }
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

public:
    // (appended for the static text, sfr_gfx_05d) the font carries ascent / descent / advances (FF_HasLayout 0x2000)
    bool HasLayout() const { return ((Flags >> 13) & 1) != 0; }

    // (appended for the Win32 font provider, sfr_render_04o) the hinting setup of a system font (0x18 bytes)
    struct NativeHintingType
    {
        String             Typeface;              // +0x00, empty for the default entry
        NativeHintingRange RasterRange;           // +0x08
        NativeHintingRange VectorRange;           // +0x0c
        unsigned           MaxRasterHintedSize;   // +0x10
        unsigned           MaxVectorHintedSize;   // +0x14
    };
    enum { FF_NativeHinting = 0x0020 };
    // the code is in one of the CJK blocks (hinting of HintCJK fonts; 0x1426d4bf0)
    bool IsCJK(UInt16 code) const;

protected:
    SInt16             LowerCaseTop, UpperCaseTop;  // +0x20
    FontCacheHandleRef hRef;                        // +0x28

    // (appended for sfr_render_07l) the hinting tops: -(glyph top) of the first sample capital / small letter the
    // font has; both -1 (auto-hinting off, warned through log) when it lacks either
    void   calcLowerUpperTop(GlyphCache* log);   // 0x1426d4c30
    UInt16 calcTopBound(UInt16 code);             // 0x1426d4dc0, 0 without the glyph

public:
    // (appended for sfr_render_06d) the hinting tops, measured on first use; 0 when the font has none
    UInt16 GetLowerCaseTop(GlyphCache* log)
    {
        if (LowerCaseTop == 0)
            calcLowerUpperTop(log);
        return (LowerCaseTop <= 0) ? 0 : LowerCaseTop;
    }
    UInt16 GetUpperCaseTop(GlyphCache* log)
    {
        if (UpperCaseTop == 0)
            calcLowerUpperTop(log);
        return (UpperCaseTop <= 0) ? 0 : UpperCaseTop;
    }

    // (appended for GFx FontDataBound, sfr_gfx_08j) copies the metrics and flags; the copy has a reference count of
    // its own and no cache handle yet
    Font(const Font& f)
        : RefCountBase<Font, StatRender_Font_Mem>(), Ascent(f.Ascent), Descent(f.Descent), Leading(f.Leading),
          Flags(f.Flags), LowerCaseTop(f.LowerCaseTop), UpperCaseTop(f.UpperCaseTop)
    {
    }
};

}} // namespace Scaleform::Render

#endif
