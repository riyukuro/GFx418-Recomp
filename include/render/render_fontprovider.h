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

#include "ms2/scaleform/include/render/render_font.h"

namespace Scaleform {

namespace Render {

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
