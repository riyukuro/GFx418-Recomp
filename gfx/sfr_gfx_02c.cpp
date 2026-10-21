// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 font map (font substitution table).
// Third source of queue unit sfr_gfx_02 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_02c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425ac250-0x1425ad1e0 .text$mn

#include "../include/gfx/gfx_fontmap.h"

namespace Scaleform { namespace GFx {

// Case-insensitive name -> entry table (8 bytes, global heap).
class FontMapImpl : public NewOverrideBase<Stat_Default_Mem>
{
public:
    StringHashLH<FontMap::MapEntry> Map;
};

// @0x1425ac6e0
FontMap::FontMap() : State(State_FontMap)
{
    pImpl = new FontMapImpl;
}

// @0x1425ac7d0
FontMap::~FontMap()
{
    delete pImpl;
}

// An existing mapping is never replaced.
// @0x1425acb30
bool FontMap::MapFont(const char* pfontName, const char* pnewFontName, MapFontFlags mff, float scaleFactor)
{
    if (!pImpl || !pfontName)
        return false;

    String fontName(pfontName);
    if (pImpl->Map.GetCaseInsensitive(fontName))
        return false;

    MapEntry entry(pnewFontName, mff, scaleFactor);
    pImpl->Map.Set(fontName, entry);
    return true;
}

// @0x1425acc60
bool FontMap::MapFont(const wchar_t* pfontName, const wchar_t* pnewFontName, MapFontFlags mff, float scaleFactor)
{
    if (!pImpl || !pfontName)
        return false;

    String fontName(pfontName);
    if (pImpl->Map.GetCaseInsensitive(fontName))
        return false;

    MapEntry entry(String(pnewFontName), mff, scaleFactor);
    pImpl->Map.Set(fontName, entry);
    return true;
}

// @0x1425aca90
bool FontMap::GetFontMapping(MapEntry* pentry, const char* pfontName)
{
    if (pImpl)
    {
        const MapEntry* pfound = pImpl->Map.GetCaseInsensitive(pfontName);
        if (pfound)
        {
            *pentry = *pfound;
            return true;
        }
    }
    return false;
}

}} // namespace Scaleform::GFx

// MS2-FUNCTIONAL ?Clear@?$HashsetCachedNodeEntry@U?$StringLH_HashNode@VMapEntry@FontMap@GFx@Scaleform@@UNoCaseHashFunctor@String@4@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ: same code as the exe with rbx and rdi swapped in the register allocation
// MS2-PIN: ??_7FontMap@GFx@Scaleform@@6B@ 0x143189190
// MS2-PIN: ?Clear@?$HashsetCachedNodeEntry@U?$StringLH_HashNode@VMapEntry@FontMap@GFx@Scaleform@@UNoCaseHashFunctor@String@4@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ 0x1425ac920
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
