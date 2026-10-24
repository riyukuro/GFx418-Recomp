// Recovered Scaleform 4.1.18 GFx: FontLib, the state that shares fonts out of registered font movies.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_FONTLIB_H
#define MS2_SF_GFX_FONTLIB_H

#include "gfx_moviedef.h"

namespace Scaleform { namespace GFx {

class FontLibImpl;
class TextureGlyphData;   // gfx_fontresource.h
class ShapeDataBase;
class LoadProcess;
struct TagInfo;

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
    ResourceKey      FontKey;       // +0x28 (sfr_gfx_08j) set for the fonts of a font provider only
    SInt16           LowerCaseTop;  // +0x38 hinting tops ('z' / 'Z' heights), measured on first use
    SInt16           UpperCaseTop;  // +0x3a

public:
    // (appended for the font manager, sfr_gfx_07g) a resource for the system font pfontName of pfontProvider,
    // registered in plib; null when the provider has no such font (exe 0x142655240).
    static FontResource* SF_STDCALL CreateFontResource(const char* pfontName, unsigned fontFlags,
                                                       FontProvider* pfontProvider, ResourceWeakLib* plib);

    // (appended, sfr_gfx_08j) GFx_FontResource
    // a font of a font provider, under its library key (exe 0x142654350)
    FontResource(Render::Font* pfont, const ResourceKey& key);
    virtual ~FontResource();   // exe 0x1426548f0

    virtual unsigned    GetResourceTypeCode() const { return MakeTypeCode(RT_Font); }
    virtual ResourceKey GetKey();   // exe 0x142655d90

    // the library key of a provider font (exe 0x1426554d0)
    static ResourceKey SF_STDCALL CreateFontResourceKey(const char* pfontName, unsigned fontFlags,
                                                        FontProvider* pfontProvider);

    UInt16 GetLowerCaseTop(Log* log)
    {
        if (LowerCaseTop == 0)
            calcLowerUpperTop(log);
        return (LowerCaseTop <= 0) ? 0 : LowerCaseTop;
    }
    UInt16 GetUpperCaseTop(Log* log)
    {
        if (UpperCaseTop == 0)
            calcLowerUpperTop(log);
        return (UpperCaseTop <= 0) ? 0 : UpperCaseTop;
    }

private:
    UInt16 calcTopBound(UInt16 code);   // exe 0x142658230
    void   calcLowerUpperTop(Log* log); // exe 0x142658080
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

    // (appended, sfr_gfx_08j) GFx_FontResource
    virtual ~FontData();   // exe 0x142654770

    // a DefineFont / DefineFont2 / DefineFont3 tag (exe 0x142655fe0)
    void Read(LoadProcess* p, const TagInfo& tagInfo);

    virtual int    GetGlyphIndex(UInt16 code);   // exe 0x142655b80
    virtual float  GetAdvance(unsigned glyphIndex) const;
    virtual float  GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const;
    virtual float  GetGlyphWidth(unsigned glyphIndex) const;
    virtual float  GetGlyphHeight(unsigned glyphIndex) const;
    virtual RectF& GetGlyphBounds(unsigned glyphIndex, RectF* prect) const;   // exe 0x142655980
    virtual const Render::TextureGlyph* GetTextureGlyph(unsigned glyphIndex) const;
    virtual void*  GetTextureGlyphData() const;
    virtual void   SetTextureGlyphData(void* pdata);   // exe 0x142657c30
    virtual float  GetTextureGlyphHeight() const;
    virtual const Render::ShapeDataInterface* GetPermanentGlyphShape(unsigned glyphIndex) const;
    virtual int    GetCharValue(unsigned glyphIndex) const;   // exe 0x1426558b0
    virtual unsigned GetGlyphShapeCount() const;
    virtual bool   HasVectorOrRasterGlyphs() const;
    virtual String GetCharRanges() const;   // exe 0x142655690

private:
    void ReadCodeTable(Stream* in);   // exe 0x1426570f0

    // Layout of one glyph (12 bytes); the box is in twips.
    struct AdvanceEntry
    {
        float  Advance;
        SInt16 Left, Top;
        UInt16 Width, Height;
    };
    struct KerningPair
    {
        UInt16 Char0, Char1;
        bool   operator==(const KerningPair& o) const { return Char0 == o.Char0 && Char1 == o.Char1; }
    };

    char*                                         Name;          // +0x38 own copy
    Ptr<TextureGlyphData>                         pTGData;       // +0x40 texture glyphs loaded with the font
    ArrayLH<Ptr<ShapeDataBase>, 0x105>            Glyphs;        // +0x48 the glyph shapes (StatMD_Fonts_Mem)
    HashIdentityLH<UInt16, UInt16, 0x105>         CodeTable;     // +0x60 character code -> glyph index
    ArrayLH<AdvanceEntry, 0x105>                  AdvanceTable;  // +0x68 per glyph
    HashLH<KerningPair, float, FixedSizeHash<KerningPair>, 0x105> KerningPairs; // +0x80
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
