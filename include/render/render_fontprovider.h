// Recovered Scaleform 4.1.18 Render: the system font provider interface and its Win32 GDI implementation
// (only what the recovered GFx units use).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The Win32 provider lives in the Render font units; until those are recovered its members bind to the exe:
//   FontProviderWinAPI::FontProviderWinAPI(HDC) 0x142647ae0, SetHinting 0x142649880, SetHintingAllFonts 0x142649970.
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

namespace Scaleform {

namespace Render {

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

private:
    // Glyph metrics, shapes and texture glyphs (slots 2..17): placeholders until a recovered unit calls them. They
    // are only declared; no recovered unit makes a Font vftable.
    virtual void Slot02(); // GetGlyphIndex
    virtual void Slot03(); // GetAdvance
    virtual void Slot04(); // GetKerningAdjustment
    virtual void Slot05(); // GetGlyphWidth
    virtual void Slot06(); // GetGlyphHeight
    virtual void Slot07(); // GetGlyphBounds
    virtual void Slot08(); // IsHintedVectorGlyph
    virtual void Slot09(); // IsHintedRasterGlyph
    virtual void Slot10(); // GetTextureGlyph
    virtual void Slot11(); // GetTextureGlyphData
    virtual void Slot12(); // SetTextureGlyphData
    virtual void Slot13(); // GetTextureGlyphHeight
    virtual void Slot14(); // GetPermanentGlyphShape
    virtual void Slot15(); // GetTemporaryGlyphShape
    virtual void Slot16(); // GetGlyphRaster
    virtual void Slot17(); // GetCharValue

public:
    // Number of glyph shapes the font carries; 0 for fonts exported without glyphs (+0x90).
    virtual unsigned GetGlyphShapeCount() const { return 0; }
    // The font carries vector or raster glyphs of its own (+0x98; declared only).
    virtual bool HasVectorOrRasterGlyphs() const;

    unsigned GetFontFlags() const { return Flags; }
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

// Source of system fonts: vslot 1 creates a font by name, vslot 2 lists the installed font names.
class FontProvider : public RefCountBase<FontProvider, Stat_Default_Mem>
{
public:
    virtual ~FontProvider() {}
    virtual Font* CreateFont(const char* name, unsigned fontFlags) = 0;
    virtual void  LoadFontNames(StringHash<String>& fontnames)    = 0;
};

// GDI font provider (0x70 bytes).
class FontProviderWinAPI : public FontProvider
{
public:
    FontProviderWinAPI(HDC dc);

    virtual Font* CreateFont(const char* name, unsigned fontFlags);
    virtual void  LoadFontNames(StringHash<String>& fontnames);

    void SetHinting(const char* name, Font::NativeHintingRange vectorRange, Font::NativeHintingRange rasterRange,
                    unsigned maxVectorHintedSize = 0, unsigned maxRasterHintedSize = 0);
    void SetHintingAllFonts(Font::NativeHintingRange vectorRange, Font::NativeHintingRange rasterRange,
                            unsigned maxVectorHintedSize = 0, unsigned maxRasterHintedSize = 0);

private:
    void* Opaque[12]; // +0x10 .. +0x70
};

}} // namespace Scaleform::Render

#endif
