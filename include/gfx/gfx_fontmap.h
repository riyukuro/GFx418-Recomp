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
    // Style the mapped font is used with: its own (Normal / Bold / Italic), faked from the plain face (Faux*), or the
    // style asked for (Original).
    enum MapFontFlags
    {
        MFF_Normal         = 0,
        MFF_Italic         = 0x1,
        MFF_Bold           = 0x2,
        MFF_BoldItalic     = 0x3,
        MFF_FauxBold       = 0x4,
        MFF_FauxItalic     = 0x8,
        MFF_FauxBoldItalic = 0xC,
        MFF_Original       = 0x10,
        MFF_NoAutoFit      = 0x20
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

        // (appended for the font manager, sfr_gfx_07g) the font flags to look the mapped font up with: the asked
        // ones for MFF_Original, else the entry's style with the asked non-style bits.
        unsigned UpdateFontFlags(unsigned matchFontFlags) const
        {
            if (Flags == MFF_Original)
                return matchFontFlags;
            return (Flags & ~MFF_FauxBoldItalic) | (matchFontFlags & ~MFF_BoldItalic);
        }
        // The style bits the handle has to fake, plus MFF_NoAutoFit.
        unsigned GetOverridenFlags() const
        {
            return ((Flags & MFF_FauxBoldItalic) ? (Flags >> 2) : 0) & MFF_BoldItalic | (Flags & MFF_NoAutoFit);
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
