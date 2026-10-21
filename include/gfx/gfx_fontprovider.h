// Recovered Scaleform 4.1.18 GFx: the font provider state (wraps a Render::FontProvider) and its Win32 flavour.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_GFX_FONTPROVIDER_H
#define MS2_SF_INC_GFX_FONTPROVIDER_H

#include "gfx_state.h"
#include "../render/render_fontprovider.h"

namespace Scaleform { namespace GFx {

// Loader state forwarding system font requests to the renderer's provider (0x20 bytes, provider at +0x18).
class FontProvider : public State
{
public:
    FontProvider(const Ptr<Render::FontProvider>& pfp) : State(State_FontProvider), pFontProvider(pfp) {}
    virtual ~FontProvider();

    Render::FontProvider* GetFontProvider() const { return pFontProvider.GetPtr(); }

    virtual Render::Font* CreateFont(const char* name, unsigned fontFlags)
    {
        return pFontProvider->CreateFont(name, fontFlags);
    }
    virtual void LoadFontNames(StringHash<String>& fontnames) { pFontProvider->LoadFontNames(fontnames); }

protected:
    Ptr<Render::FontProvider> pFontProvider;
};

// Font provider backed by GDI.
class FontProviderWin32 : public FontProvider
{
public:
    FontProviderWin32(HDC dc);
    FontProviderWin32(HDC dc, MemoryHeap* heap);

    virtual Render::Font* CreateFont(const char* name, unsigned fontFlags)
    {
        return pFontProvider->CreateFont(name, fontFlags);
    }
    virtual void LoadFontNames(StringHash<String>& fontnames) { pFontProvider->LoadFontNames(fontnames); }

    void SetHinting(const char* name, Render::Font::NativeHintingRange vectorRange,
                    Render::Font::NativeHintingRange rasterRange, unsigned maxVectorHintedSize = 0,
                    unsigned maxRasterHintedSize = 0);
    void SetHintingAllFonts(Render::Font::NativeHintingRange vectorRange, Render::Font::NativeHintingRange rasterRange,
                            unsigned maxVectorHintedSize = 0, unsigned maxRasterHintedSize = 0);

private:
    Render::FontProviderWinAPI* GetWinAPI() const
    {
        return static_cast<Render::FontProviderWinAPI*>(pFontProvider.GetPtr());
    }
};

}} // namespace Scaleform::GFx

#endif
