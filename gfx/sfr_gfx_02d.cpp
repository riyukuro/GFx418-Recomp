// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 font library (fonts shared out of
// registered font movies).
// Fourth source of queue unit sfr_gfx_02 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_02d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425ad1e0-0x1425ae790 .text$mn
//
// The range stops before 0x1425ae790 (an AS2 StackMemPool placement new that the linker put here).

#include "../include/gfx/gfx_fontlib.h"
#include "../include/gfx/gfx_loaderimpl.h"

namespace Scaleform { namespace GFx {

// Registered font movies and the substitute font file name (0x20 bytes, global heap).
class FontLibImpl : public NewOverrideBase<Stat_Default_Mem>
{
public:
    Array<Ptr<MovieDataDef> > FontMovies;       // +0
    String                    FileToSubstitute; // +0x18
};

// @0x1425ad550
FontLib::FontLib() : State(State_FontLib), pImpl(new FontLibImpl)
{
    pImpl->FileToSubstitute = "gfxfontlib.swf";
}

// @0x1425ad7c0
FontLib::~FontLib()
{
    delete pImpl;
}

// The data def is kept rather than the binding so the font movie does not hold its user's states.
// @0x1425ada80
void FontLib::AddFontsFrom(MovieDef* md, bool pin)
{
    MovieDefImpl* pmdi = (MovieDefImpl*)md;

    if (pImpl && pmdi)
    {
        pImpl->FontMovies.PushBack(pmdi->GetDataDef());
        if (pin)
            md->PinResource();
    }
}

// @0x1425ae4c0
void FontLib::FontResult::SetResult(MovieDef* pmovieDef, FontResource* pfont)
{
    if (pmovieDef)
        pmovieDef->AddRef();
    if (pfont)
        pfont->AddRef();

    if (pMovieDef)
        pMovieDef->Release();
    if (pFontResource)
        pFontResource->Release();

    pMovieDef     = pmovieDef;
    pFontResource = pfont;
}

// @0x1425ad840
FontLib::FontResult::~FontResult()
{
    if (pMovieDef)
        pMovieDef->Release();
    if (pFontResource)
        pFontResource->Release();
}

// @0x1425adc40
// MS2-FUNCTIONAL: same code as the exe except that the font list head is loaded through rdi instead of rax (2 bytes)
bool FontLib::FindFont(FontResult* presult, const char* pfontname, unsigned fontFlags, MovieDef* puserDef,
                       StateBag* pstates, ResourceWeakLib* pweakLib)
{
    if (!pImpl)
        return false;

    unsigned          i, fontBindIndex = 0;
    MovieDataDef*     pdataDef  = 0;
    bool              fontFound = false;
    Ptr<MovieDefImpl> pfontDefImpl;

    for (i = 0; (i < pImpl->FontMovies.GetSize()) && !fontFound; i++)
    {
        pdataDef = pImpl->FontMovies[i];

        // All fonts are only there once the movie finished loading.
        pdataDef->WaitForLoadFinish();

        for (FontDataUseNode* pfont = pdataDef->GetFirstFont(); pfont != 0; pfont = pfont->pNext)
        {
            if (pfont->pFontData->MatchFont(pfontname, fontFlags))
            {
                fontBindIndex = pfont->BindIndex;
                fontFound     = true;
                break;
            }
        }
    }

    if (!fontFound)
        return false;

    if (puserDef)
    {
        // Binding states of the user movie, other states from pstates.
        MovieDefImpl*   pudi = (MovieDefImpl*)puserDef;
        Ptr<LoadStates> pls  = *new LoadStates(pudi->pLoaderImpl, pstates, pudi->pBindStates);

        pfontDefImpl = *pudi->pLoaderImpl->CreateMovie_LoadState(pls, pdataDef,
                                                                 pudi->GetLoadFlags() | Loader::LoadWaitCompletion);
    }
    else if (pweakLib)
    {
        // No user movie (DrawText): bind through a throwaway loader over the given library.
        Ptr<LoaderImpl>         loaderImpl = *new LoaderImpl(pstates, pweakLib->GetResourceLib());
        Ptr<MovieDefBindStates> bs         = *new MovieDefBindStates(pstates);
        Ptr<LoadStates>         pls        = *new LoadStates(loaderImpl, pstates, bs);

        pfontDefImpl = *loaderImpl->CreateMovie_LoadState(pls, pdataDef, Loader::LoadWaitCompletion);
    }
    if (!pfontDefImpl)
        return false;

    ResourceBindData rbd;
    pfontDefImpl->GetResourceBinding().GetResourceData(&rbd, fontBindIndex);
    if (rbd.pResource)
    {
        presult->SetResult(pfontDefImpl, (FontResource*)rbd.pResource.GetPtr());
        return true;
    }
    return false;
}

// @0x1425adfe0
const String& FontLib::GetSubstitute() const
{
    return pImpl->FileToSubstitute;
}

// @0x1425adff0
void FontLib::LoadFontNames(StringHash<String>& fontnames)
{
    if (!pImpl)
        return;

    for (unsigned i = 0; i < pImpl->FontMovies.GetSize(); i++)
    {
        MovieDataDef* pdataDef = pImpl->FontMovies[i];
        pdataDef->WaitForLoadFinish();

        for (FontDataUseNode* pfont = pdataDef->GetFirstFont(); pfont != 0; pfont = pfont->pNext)
        {
            String fontname(pfont->pFontData->GetName());
            fontnames.Set(fontname, fontname);
        }
    }
}

// @0x1425ae210
void FontLib::LoadFonts(HashSet<Ptr<Render::Font> >& fonts)
{
    if (!pImpl)
        return;

    for (unsigned i = 0; i < pImpl->FontMovies.GetSize(); i++)
    {
        MovieDataDef* pdataDef = pImpl->FontMovies[i];
        pdataDef->WaitForLoadFinish();

        for (FontDataUseNode* pfont = pdataDef->GetFirstFont(); pfont != 0; pfont = pfont->pNext)
            fonts.Set(pfont->pFontData);
    }
}

// @0x1425ae530
void FontLib::SetSubstitute(const char* filename)
{
    pImpl->FileToSubstitute = filename;
}

}} // namespace Scaleform::GFx

// MS2-FUNCTIONAL ?setRawCapacity@?$HashSetBase@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@VString@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z: same code as the exe with a different register allocation (the exe also saves r15)
// MS2-PIN: ??_7FontLib@GFx@Scaleform@@6B@ 0x143189198
// MS2-PIN: ??_7MovieDefBindStates@GFx@Scaleform@@6B@ 0x1431891b0
// MS2-PIN: ??_7?$RefCountBase@VMovieDefBindStates@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431891a8
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@VString@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425ae540
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
