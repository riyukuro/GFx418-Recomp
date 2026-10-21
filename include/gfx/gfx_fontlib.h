// Recovered Scaleform 4.1.18 GFx: FontLib, the state that shares fonts out of registered font movies.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_FONTLIB_H
#define MS2_SF_GFX_FONTLIB_H

#include "gfx_moviedef.h"

namespace Scaleform { namespace GFx {

class FontLibImpl;

// Font resource of a bound movie (only its Resource base is needed so far).
class FontResource : public Resource
{
};

// Movies registered with AddFontsFrom are searched for fonts by name (vftable 0x143189198, 0x20 bytes).
class FontLib : public State
{
public:
    // Movie and font resource a successful FindFont hands back; both are held.
    class FontResult
    {
        friend class FontLib;

        MovieDef*     pMovieDef;
        FontResource* pFontResource;

        void SetResult(MovieDef* pmovieDef, FontResource* pfont);

    public:
        FontResult() : pMovieDef(0), pFontResource(0) {}
        ~FontResult();

        MovieDef*     GetMovieDef() const    { return pMovieDef; }
        FontResource* GetFontResource() const { return pFontResource; }
    };

    FontLib();
    virtual ~FontLib();

    void AddFontsFrom(MovieDef* md, bool pin = false);

    // Looks the name up in every registered movie and binds the font for puserDef (or, without one, for a fresh
    // loader over pweakLib).
    virtual bool FindFont(FontResult* presult, const char* pfontname, unsigned fontFlags, MovieDef* puserDef,
                          StateBag* pstates, ResourceWeakLib* pweakLib = 0);

    void LoadFontNames(StringHash<String>& fontnames);
    void LoadFonts(HashSet<Ptr<Render::Font> >& fonts);

    const String& GetSubstitute() const;
    void          SetSubstitute(const char* filename);

private:
    FontLibImpl* pImpl; // +0x18
};

}} // namespace Scaleform::GFx

#endif
