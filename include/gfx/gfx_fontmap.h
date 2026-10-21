// Recovered Scaleform 4.1.18 GFx: the font substitution table (font name -> replacement font, style and scale).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_GFX_FONTMAP_H
#define MS2_SF_INC_GFX_FONTMAP_H

#include "gfx_state.h"
#include "../kernel/sf_stringhash.h"

namespace Scaleform { namespace GFx {

class FontMapImpl;

// Loader state (0x20 bytes): the map itself lives behind pImpl (+0x18) so it can be created lazily.
class FontMap : public State
{
public:
    enum MapFontFlags
    {
        MFF_Original = 0
    };

    // One substitution (0x10 bytes).
    class MapEntry
    {
    public:
        String       Name;        // +0
        float        ScaleFactor; // +8
        MapFontFlags Flags;       // +0xc

        MapEntry() : ScaleFactor(1.0f), Flags(MFF_Original) {}
        MapEntry(const String& name, MapFontFlags flags, float scaleFactor)
            : Name(name), ScaleFactor(scaleFactor), Flags(flags)
        {
        }
    };

    FontMap();
    virtual ~FontMap();

    bool MapFont(const char* pfontName, const char* pnewFontName, MapFontFlags mff = MFF_Original,
                 float scaleFactor = 1.0f);
    bool MapFont(const wchar_t* pfontName, const wchar_t* pnewFontName, MapFontFlags mff = MFF_Original,
                 float scaleFactor = 1.0f);

    bool GetFontMapping(MapEntry* pentry, const char* pfontName);

private:
    FontMapImpl* pImpl;
};

}} // namespace Scaleform::GFx

#endif
