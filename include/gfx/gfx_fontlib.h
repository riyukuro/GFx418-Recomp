// Recovered Scaleform 4.1.18 GFx: FontLib, the state that shares fonts out of registered font movies.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_FONTLIB_H
#define MS2_SF_GFX_FONTLIB_H

#include "gfx_moviedef.h"

namespace Scaleform { namespace GFx {

class FontLibImpl;

class FontProvider;

// Font resource of a bound movie (only its Resource base is needed so far).
class FontResource : public Resource
{
public:
    // A font bound in pbinding (exe 0x142654400).
    FontResource(Render::Font* pfont, ResourceBinding* pbinding);

    // Fills the texture glyphs of the font from its loaded image data (exe 0x142657940).
    void ResolveTextureGlyphs();

    Render::Font* GetFont() const { return pFont; }
    const char*   GetName() const { return pFont->GetName(); }

private:
    Ptr<Render::Font> pFont; // +0x18

public:
    // (appended for the sprites, sfr_gfx_05b) the binding the font was bound in; 0x40 bytes in all
    ResourceBinding* GetBinding() const { return pBinding; }

private:
    ResourceBinding* pBinding;      // +0x20
    UByte            Unknown28[0x18]; // +0x28 a RectF and a counter set by the ctor

public:
    // (appended for the font manager, sfr_gfx_07g) a resource for the system font pfontName of pfontProvider,
    // registered in plib; null when the provider has no such font (exe 0x142655240).
    static FontResource* SF_STDCALL CreateFontResource(const char* pfontName, unsigned fontFlags,
                                                       FontProvider* pfontProvider, ResourceWeakLib* plib);
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

// (appended for the font manager, sfr_gfx_07g) font defined in a movie (0x88 bytes, StatRender_Font_Mem); a fresh one has no glyphs (exe ctor 0x1426541a0).
class FontData : public Render::Font
{
public:
    FontData();
    // (sfr_gfx_04) a by-name placeholder, not resolved yet (exe 0x1426540b0)
    FontData(const char* name, unsigned fontFlags);

    virtual const char* GetName() const;

    // (sfr_gfx_04b) the glyph code table and style flags of a DefineFontInfo / DefineFontInfo2 tag (exe 0x142657290)
    void ReadFontInfo(Stream* in, TagType tagType);

private:
    UByte Unrecovered[0x88 - sizeof(Render::Font)]; // the glyph / layout tables
};

inline Ptr<FontLib> StateBag::GetFontLib() const
{
    return *(FontLib*)GetStateAddRef(State::State_FontLib);
}

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::FontData) == 0x88, "FontData size");
static_assert(sizeof(Scaleform::GFx::FontResource) == 0x40, "FontResource size");

#endif
