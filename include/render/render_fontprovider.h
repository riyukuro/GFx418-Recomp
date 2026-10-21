// Recovered Scaleform 4.1.18 Render: the system font provider interface and its Win32 GDI implementation
// (only what the recovered GFx units use).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The Win32 provider and its fonts are recovered in sfr_render_04o (Render_FontProviderWinAPI).
#ifndef MS2_SF_INC_RENDER_FONTPROVIDER_H
#define MS2_SF_INC_RENDER_FONTPROVIDER_H

#include "../kernel/sf_refcount.h"
#include "../kernel/sf_stringhash.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_types2d.h"

namespace Scaleform {

namespace Render {

// Source of system fonts: vslot 1 creates a font by name, vslot 2 lists the installed font names.
class FontProvider : public RefCountBase<FontProvider, StatRender_Font_Mem>
{
public:
    virtual ~FontProvider() {}
    virtual Font* CreateFont(const char* name, unsigned fontFlags) = 0;
    virtual void  LoadFontNames(StringHash<String>& fontnames)    = 0;
};

class FontProviderWinAPI;

// What the fonts of one provider share: the device context they select into and the outline buffer (0x20 bytes).
struct FontSysDataWinAPI
{
    // the outline buffer grows by this much past the size GetGlyphOutline asks for
    enum { BufSizeInc = 1024 - 8 };

    Array<UByte> GlyphBuffer;   // +0x00
    HDC          WinHDC;        // +0x18

    FontSysDataWinAPI(HDC dc) : WinHDC(dc) {}
};

// A system font read through GDI (0xe0 bytes). Metrics come from the master font made at GGO_FontHeight pixels and
// are scaled to the 1024 em square; hinted shapes and rasters use a second font made at the hinted size.
class ExternalFontWinAPI : public Font
{
    // the master font's pixel height
    enum { GGO_FontHeight = 240 };

public:
    ExternalFontWinAPI(FontProviderWinAPI* pprovider, FontSysDataWinAPI* psysData, const char* name,
                       unsigned fontFlags, Lock* fontLock);
    virtual ~ExternalFontWinAPI();

    // GDI could make the face
    bool IsValid() const { return MasterFont != 0; }
    // the ranges and size limits only; the typeface stays this font's own
    void SetHinting(const NativeHintingType& nh)
    {
        Hinting.MaxRasterHintedSize = nh.MaxRasterHintedSize;
        Hinting.MaxVectorHintedSize = nh.MaxVectorHintedSize;
        Hinting.RasterRange         = nh.RasterRange;
        Hinting.VectorRange         = nh.VectorRange;
    }

    virtual const char* GetName() const;
    virtual int    GetGlyphIndex(UInt16 code);
    virtual float  GetAdvance(unsigned glyphIndex) const;
    virtual float  GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const;
    virtual float  GetGlyphWidth(unsigned glyphIndex) const;
    virtual float  GetGlyphHeight(unsigned glyphIndex) const;
    virtual RectF& GetGlyphBounds(unsigned glyphIndex, RectF* prect) const;
    virtual bool   IsHintedVectorGlyph(unsigned glyphIndex, unsigned hintedSize) const;
    virtual bool   IsHintedRasterGlyph(unsigned glyphIndex, unsigned hintedSize) const;
    virtual const ShapeDataInterface* GetPermanentGlyphShape(unsigned) const { return 0; }
    virtual bool   GetTemporaryGlyphShape(unsigned glyphIndex, unsigned hintedSize, GlyphShape* shape);
    virtual bool   GetGlyphRaster(unsigned glyphIndex, unsigned hintedSize, GlyphRaster* raster);

private:
    bool decomposeGlyphOutline(const UByte* data, unsigned size, GlyphShape* shape, unsigned hintedSize);
    void decomposeGlyphBitmap(const UByte* data, int width, int height, int originX, int originY,
                              GlyphRaster* raster);
    void loadKerningPairs();

    // GDI 16.16 fixed point to twips, and to the 1024 em square of the master font
    static float FxToTwips(FIXED v) { return float(v.value) * 20.0f + float(v.fract) * 20.0f / 65536.0f; }
    static float FxToS1024(FIXED v)
    {
        return float((int(v.value) << 8) + (int(v.fract) >> 8)) * 4.0f / float(GGO_FontHeight);
    }

    // one glyph met so far (0x20 bytes)
    struct GlyphType
    {
        unsigned Code;          // +0x00
        float    Advance;       // +0x04
        UInt32   Reserved[2];   // +0x08, never written
        RectF    Bounds;        // +0x10
    };
    struct KerningPairType
    {
        UInt16 Char0, Char1;
        bool operator==(const KerningPairType& k) const { return Char0 == k.Char0 && Char1 == k.Char1; }
    };

    Ptr<FontProviderWinAPI>          pFontProvider;        // +0x38, keeps the shared sys data alive
    FontSysDataWinAPI*               pSysData;             // +0x40
    ArrayLH<char>                    Name;                 // +0x48
    ArrayLH<wchar_t>                 NameW;                // +0x60
    HFONT                            MasterFont;           // +0x78
    HFONT                            HintedFont;           // +0x80
    unsigned                         LastHintedFontSize;   // +0x88
    ArrayLH<GlyphType>               Glyphs;               // +0x90
    HashUncachedLH<UInt16, unsigned, IdentityHash<UInt16> > CodeTable;   // +0xa8, character code -> glyph index
    HashLH<KerningPairType, float>   KerningPairs;         // +0xb0
    float                            Scale1024;            // +0xb8
    NativeHintingType                Hinting;              // +0xc0
    Lock*                            pFontLock;            // +0xd8, the provider's
};

// GDI font provider (0x70 bytes).
class FontProviderWinAPI : public FontProvider
{
public:
    FontProviderWinAPI(HDC dc);
    virtual ~FontProviderWinAPI();

    virtual Font* CreateFont(const char* name, unsigned fontFlags);
    virtual void  LoadFontNames(StringHash<String>& fontnames);

    void SetHinting(const char* name, Font::NativeHintingRange vectorRange, Font::NativeHintingRange rasterRange,
                    unsigned maxVectorHintedSize = 0, unsigned maxRasterHintedSize = 0);
    void SetHintingAllFonts(Font::NativeHintingRange vectorRange, Font::NativeHintingRange rasterRange,
                            unsigned maxVectorHintedSize = 0, unsigned maxRasterHintedSize = 0);

private:
    Font::NativeHintingType* findNativeHinting(const char* name);

    FontSysDataWinAPI              SysData;         // +0x10
    Array<Font::NativeHintingType> NativeHinting;   // +0x30, [0] is the default for every face
    Lock                           FontLock;        // +0x48
};

}} // namespace Scaleform::Render

#endif
