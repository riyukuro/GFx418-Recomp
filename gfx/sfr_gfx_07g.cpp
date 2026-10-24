// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_FontManager: the per-movie
// font lookup (the movie's own and imported fonts, registered fonts, the font map, the font library and the font
// provider), its handle cache and the font states the managers share.
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14263a9d0-0x14263dfa0 .text$mn
// MS2-PIN: ??$RemoveAlt@UNodePtr@FontManager@GFx@Scaleform@@@Iterator@?$HashSetBase@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@U5234@U?$AllocatorLH@UNodePtr@FontManager@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@@4@@Scaleform@@QEAAXAEBUNodePtr@FontManager@GFx@2@@Z 0x14263ae40
// MS2-PIN: ?setRawCapacity@?$HashSetBase@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@U5234@U?$AllocatorLH@UNodePtr@FontManager@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x14263dcf0
// MS2-PIN: ?FindOrCreateHandle@FontManager@GFx@Scaleform@@IEAAPEAVFontHandle@23@PEBDIPEAPEAVFontResource@23@PEAUFontSearchPathInfo@FontManagerBase@Text@Render@3@@Z 0x14263cb70
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318ea90
// MS2-PIN: ??_7?$RefCountBase@VFontHandle@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x1431899e0
// MS2-PIN: ??_7FontHandle@Text@Render@Scaleform@@6B@ 0x1431899e8
// MS2-PIN: ??_7FontHandle@GFx@Scaleform@@6B@ 0x143189e70
// MS2-PIN: ??_7?$RefCountBase@VFontManagerBase@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318f790
// MS2-PIN: ??_7FontManagerBase@Text@Render@Scaleform@@6B@ 0x14318f798
// MS2-PIN: ??_7FontManager@GFx@Scaleform@@6B@ 0x14318f7b8
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL ??$RemoveAlt@UNodePtr@FontManager@GFx@Scaleform@@@Iterator@?$HashSetBase@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@U5234@U?$AllocatorLH@UNodePtr@FontManager@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UNodePtr@FontManager@GFx@Scaleform@@UNodePtrHashOp@234@@4@@Scaleform@@QEAAXAEBUNodePtr@FontManager@GFx@2@@Z: same code as the exe with rbx / rdi swapped for the node and its flags in the hash

#include "../include/gfx/gfx_fontmanager.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/kernel/sf_msgformat.h"

#include <string.h>

namespace Scaleform { namespace GFx {

// The text replacement state (the full class is in sfr_gfx_02f); only its State base is needed here.
class Translator : public State
{
};

// DisplayObjectBase::StateChanged_* bits.
enum
{
    StateChanged_FontLib      = 0x1,
    StateChanged_FontMap      = 0x2,
    StateChanged_FontProvider = 0x4,
    StateChanged_Translator   = 0x8
};

State* FontManagerStates::GetStateAddRef(State::StateType state) const
{
    if (state == State::State_FontLib)
    {
        if (pFontLib)
            pFontLib->AddRef();
        return pFontLib.GetPtr();
    }
    else if (state == State::State_FontMap)
    {
        if (pFontMap)
            pFontMap->AddRef();
        return pFontMap.GetPtr();
    }
    else if (state == State::State_FontProvider)
    {
        if (pFontProvider)
            pFontProvider->AddRef();
        return pFontProvider.GetPtr();
    }
    if (state == State::State_Translator)
    {
        if (pTranslator)
            pTranslator->AddRef();
        return pTranslator.GetPtr();
    }
    return pDelegate->GetStateAddRef(state);
}

UInt8 FontManagerStates::CheckStateChange(FontLib* pfontLib, FontMap* pfontMap, FontProvider* pfontProvider,
                                          Translator* ptranslator)
{
    UInt8 changed = 0;
    if (pFontLib.GetPtr() != pfontLib)
    {
        changed |= StateChanged_FontLib;
        pFontLib = pfontLib;
    }
    if (pFontMap.GetPtr() != pfontMap)
    {
        changed |= StateChanged_FontMap;
        pFontMap = pfontMap;
    }
    if (pFontProvider.GetPtr() != pfontProvider)
    {
        changed |= StateChanged_FontProvider;
        pFontProvider = pfontProvider;
    }
    if (pTranslator.GetPtr() != ptranslator)
    {
        changed |= StateChanged_Translator;
        pTranslator = ptranslator;
    }
    return changed;
}

FontManager::FontManager(MovieImpl* pmovie, MovieDefImpl* pdefImpl, FontManagerStates* pfontStates)
{
    pMovie   = pmovie;
    pDefImpl = pdefImpl;
    pWeakLib = 0;
    pState   = pfontStates;
    commonInit();
}

FontManager::FontManager(ResourceWeakLib* pweakLib, FontManagerStates* pfontStates)
{
    pMovie   = 0;
    pDefImpl = 0;
    pWeakLib = pweakLib;
    pState   = pfontStates;
    commonInit();
}

// The empty font: a glyphless font of no name.
void FontManager::commonInit()
{
    Ptr<FontData>     pfontData  = *SF_HEAP_AUTO_NEW(this) FontData();
    Ptr<FontResource> pemptyFont = *SF_HEAP_AUTO_NEW(this) FontResource(pfontData, 0);
    pEmptyFont                   = *new FontHandle(0, pemptyFont->GetFont());
}

FontManager::~FontManager()
{
}

void FontManager::RemoveFontHandle(FontHandle* phandle)
{
    if (phandle != pEmptyFont)
        CreatedFonts.Remove(phandle);
}

static const char* StrFlags[] = {"",       "[Bold]",        "[Italic]",         "[Bold,Italic]",
                                 "[Device]", "[Bold,Device]", "[Italic,Device]", "[Bold,Italic,Device]"};

static const char* FontFlagsToString(unsigned matchFontFlags)
{
    if (!matchFontFlags)
        return StrFlags[0];
    if (matchFontFlags & Render::Font::FF_DeviceFont)
    {
        if ((matchFontFlags & Render::Font::FF_Style_Mask) == Render::Font::FF_Style_Mask)
            return StrFlags[7];
        if (matchFontFlags & Render::Font::FF_Bold)
            return StrFlags[5];
        if (matchFontFlags & Render::Font::FF_Italic)
            return StrFlags[6];
        return StrFlags[4];
    }
    else
    {
        if ((matchFontFlags & Render::Font::FF_Style_Mask) == Render::Font::FF_Style_Mask)
            return StrFlags[3];
        if (matchFontFlags & Render::Font::FF_Bold)
            return StrFlags[1];
        if (matchFontFlags & Render::Font::FF_Italic)
            return StrFlags[2];
    }
    return StrFlags[0];
}

typedef Render::Text::FontManagerBase::FontSearchPathInfo FontSearchPathInfo;

// One indented line of the search report.
void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* line)
{
    if (!psearchInfo)
        return;
    String indent("   ");
    for (int i = 0; i < psearchInfo->Indent; ++i)
        psearchInfo->Info.AppendString(indent.ToCStr(), indent.GetSize());
    psearchInfo->Info.AppendString(line);
    psearchInfo->Info.AppendString("\n");
}

// What the movie's own resources and imports said about the font.
void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* pfontname, unsigned flags, bool fontlibInstalled,
                   const MovieDefImpl::SearchInfo& resSearchInfo)
{
    char          buff[1024];
    StringDataPtr buffData(buff, sizeof(buff));

    if (!psearchInfo)
        return;
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInResources)
    {
        Format(buffData, "Movie resource: \"{0}\" {1} found.", pfontname, FontFlagsToString(flags));
        AddSearchInfo(psearchInfo, buff);
        return;
    }
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInResourcesNeedFaux)
    {
        Format(buffData, "Movie resource: \"{0}\" {1} found, requires faux", pfontname, FontFlagsToString(flags));
        AddSearchInfo(psearchInfo, buff);
        return;
    }
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInResourcesNoGlyphs)
    {
        Format(buffData, "Movie resource: \"{0}\" {1} ref found, requires FontLib/Map/Provider.", pfontname,
               FontFlagsToString(flags));
        AddSearchInfo(psearchInfo, buff);
        return;
    }

    Format(buffData, "Movie resource: \"{0}\" {1} not found.", pfontname, FontFlagsToString(flags));
    AddSearchInfo(psearchInfo, buff);
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInImports ||
        (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInImportsFontLib && !fontlibInstalled))
    {
        Format(buffData, "Imports       : \"{0}\" {1} found in \"{2}\".", pfontname, FontFlagsToString(flags),
               resSearchInfo.ImportFoundUrl);
        AddSearchInfo(psearchInfo, buff);
        return;
    }
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInImportsFontLib)
    {
        Format(buffData, "Imports       : \"{0}\" {1} import delegates to font library.", pfontname,
               FontFlagsToString(flags));
        AddSearchInfo(psearchInfo, buff);
        return;
    }
    Format(buffData, "Imports       : \"{0}\" {1} not found.", pfontname, FontFlagsToString(flags));
    AddSearchInfo(psearchInfo, buff);
    if (resSearchInfo.ImportSearchUrls.GetSize() > 0)
    {
        String urls;
        for (MovieDefImpl::SearchInfo::StringSet::ConstIterator it = resSearchInfo.ImportSearchUrls.Begin();
             it != resSearchInfo.ImportSearchUrls.End(); ++it)
        {
            if (it != resSearchInfo.ImportSearchUrls.Begin())
                urls += ", ";
            urls += String("\"") + *it + "\"";
        }
        Format(buffData, "              : {0}.", urls);
        AddSearchInfo(psearchInfo, buff);
    }
    if (resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInExports)
    {
        Format(buffData, "Exported      : \"{0}\" {1} found.", pfontname, FontFlagsToString(flags));
        AddSearchInfo(psearchInfo, buff);
        return;
    }
    Format(buffData, "Exported      : \"{0}\" {1} not found.", pfontname, FontFlagsToString(flags));
    AddSearchInfo(psearchInfo, buff);
}

static inline void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* str1, const char* str2,
                                 const char* str3)
{
    if (!psearchInfo)
        return;
    StringBuffer buf;
    buf.AppendString(str1);
    buf.AppendString(str2);
    buf.AppendString(str3);
    AddSearchInfo(psearchInfo, buf.ToCStr());
}

void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* str1, const char* str2, const char* str3,
                   unsigned flags, const char* str4)
{
    if (!psearchInfo)
        return;
    StringBuffer buf;
    buf.AppendString(str1);
    buf.AppendString(str2);
    buf.AppendString(str3);
    buf.AppendString(FontFlagsToString(flags));
    buf.AppendString(str4);
    AddSearchInfo(psearchInfo, buf.ToCStr());
}

static inline void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* str1, const char* str2,
                                 const char* str3, unsigned flags1, const char* str4, const char* str5,
                                 const char* str6, unsigned flags2)
{
    if (!psearchInfo)
        return;
    StringBuffer buf;
    buf.AppendString(str1);
    buf.AppendString(str2);
    buf.AppendString(str3);
    buf.AppendString(FontFlagsToString(flags1));
    buf.AppendString(str4);
    buf.AppendString(str5);
    buf.AppendString(str6);
    buf.AppendString(FontFlagsToString(flags2));
    AddSearchInfo(psearchInfo, buf.ToCStr());
}

static inline void AddSearchInfo(FontSearchPathInfo* psearchInfo, const char* str1, const char* str2,
                                 const char* str3, const char* str4, const char* str5, unsigned flags)
{
    if (!psearchInfo)
        return;
    StringBuffer buf;
    buf.AppendString(str1);
    buf.AppendString(str2);
    buf.AppendString(str3);
    buf.AppendString(str4);
    buf.AppendString(str5);
    buf.AppendString(FontFlagsToString(flags));
    AddSearchInfo(psearchInfo, buf.ToCStr());
}

// MS2-FUNCTIONAL same lookup order and results; the exe's frame is 0x10 bytes larger and its registers differ
FontHandle* FontManager::FindOrCreateHandle(const char* pfontName, unsigned matchFontFlags,
                                            FontResource** ppfoundFont, FontSearchPathInfo* searchInfo)
{
    FontKey       key(pfontName, matchFontFlags);
    FontHandle*   phandle       = 0;
    FontLib*      pfontLib      = pState->pFontLib.GetPtr();
    FontProvider* pfontProvider = pState->pFontProvider.GetPtr();
    FontMap*      pfontMap      = pState->pFontMap.GetPtr();

    int                       indentDif      = 0;
    const NodePtr*            psetNode       = 0;
    const NodePtr*            pfoundNode     = 0;
    MovieDefImpl::SearchInfo  resSearchInfo;
    MovieDefImpl::SearchInfo* presSearchInfo = 0;
    bool                      secondLoop     = false;

    // the IME candidate list font goes by its name only
    if (pIMECandidateFont && !String::CompareNoCase(pIMECandidateFont->GetFontName(), pfontName))
    {
        pIMECandidateFont->AddRef();
        return pIMECandidateFont;
    }

retry_font_lookup:
    if (searchInfo)
    {
        indentDif++;
        searchInfo->Indent++;
        presSearchInfo = &resSearchInfo;
    }
    else
    {
        psetNode = CreatedFonts.Get(key);
        if (psetNode)
        {
            // a cached device font answers a non-device request only once no embedded font was found
            if ((matchFontFlags & Render::Font::FF_DeviceFont) == 0 &&
                (psetNode->pNode->GetFontFlags() & Render::Font::FF_DeviceFont) != 0)
            {
                if (psetNode->SearchedForNonDeviceFont)
                {
                    psetNode->pNode->AddRef();
                    return psetNode->pNode;
                }
                pfoundNode = psetNode;
            }
            else
            {
                psetNode->pNode->AddRef();
                return psetNode->pNode;
            }
        }
    }

    // the movie's own and imported fonts, then the registered ones
    FontResource* pfontRes = pDefImpl ? pDefImpl->GetFontResource(pfontName, matchFontFlags, presSearchInfo) : 0;
    AddSearchInfo(searchInfo, pfontName, matchFontFlags, pState->pFontLib.GetPtr() != 0, resSearchInfo);

    MovieDef* psrcMovieDef = 0;
    if (!pfontRes && pMovie)
    {
        pfontRes = pMovie->FindRegisteredFont(pfontName, matchFontFlags, &psrcMovieDef);
        if (!pfontRes)
            AddSearchInfo(searchInfo, "Registered fonts: \"", pfontName, "\"", matchFontFlags, " not found.");
    }
    if (pfontRes)
    {
        if (pfontRes->GetFont()->IsResolved())
        {
            // a plain face for a bold / italic request: the caller fakes the style
            if ((matchFontFlags & Render::Font::FF_Style_Mask) && !pfontRes->GetFont()->HasVectorOrRasterGlyphs())
            {
                if (ppfoundFont)
                    *ppfoundFont = pfontRes;
                if (pfoundNode)
                {
                    pfoundNode->pNode->pFontManager = 0;
                    CreatedFonts.Remove(pfoundNode->pNode);
                }
                return 0;
            }
            phandle = new FontHandle(searchInfo ? 0 : this, pfontRes->GetFont(), pfontName, 0, psrcMovieDef);
        }
    }

    if (pfoundNode)
    {
        if (!phandle)
        {
            pfoundNode->SearchedForNonDeviceFont = true;
            pfoundNode->pNode->AddRef();
            return pfoundNode->pNode;
        }
        // the embedded font replaces the cached device one
        pfoundNode->pNode->pFontManager = 0;
        CreatedFonts.Remove(pfoundNode->pNode);
        pfoundNode = CreatedFonts.Get(phandle);
        if (pfoundNode)
        {
            phandle->pFontManager = 0;
            phandle->Release();
            pfoundNode->pNode->AddRef();
            return pfoundNode->pNode;
        }
    }

    const char* plookupFontName = pfontName;
    unsigned    lookupFlags     = matchFontFlags;
    float       scaleFactor     = 1.0f;
    unsigned    overridenFlags  = 0;

    // the font map
    if (!phandle && pfontMap)
    {
        if (pfontMap->GetFontMapping(&FontMapEntry, pfontName))
        {
            plookupFontName = FontMapEntry.Name.ToCStr();
            lookupFlags     = FontMapEntry.UpdateFontFlags(matchFontFlags);
            scaleFactor     = FontMapEntry.ScaleFactor;
            overridenFlags  = FontMapEntry.GetOverridenFlags();
            if (searchInfo)
                AddSearchInfo(searchInfo, "Applying FontMap: \"", pfontName, "\"  mapped to \"", plookupFontName,
                              "\"", lookupFlags);
            else
            {
                FontKey lookupKey(plookupFontName, lookupFlags);
                psetNode = CreatedFonts.Get(lookupKey);
                if (psetNode)
                {
                    if (psetNode->pNode->FontScaleFactor != scaleFactor)
                    {
                        phandle = new FontHandle(searchInfo ? 0 : this, psetNode->pNode->pFont, pfontName,
                                                 matchFontFlags,
                                                 static_cast<MovieDef*>(psetNode->pNode->pSourceMovieDef.GetPtr()));
                        phandle->FontScaleFactor = scaleFactor;
                    }
                    else
                    {
                        psetNode->pNode->AddRef();
                        return psetNode->pNode;
                    }
                }
                FontKey lookupKey2(pfontName, lookupFlags);
                psetNode = CreatedFonts.Get(lookupKey2);
                if (psetNode)
                {
                    if (psetNode->pNode->FontScaleFactor != scaleFactor)
                    {
                        phandle = new FontHandle(searchInfo ? 0 : this, psetNode->pNode->pFont, pfontName,
                                                 matchFontFlags,
                                                 static_cast<MovieDef*>(psetNode->pNode->pSourceMovieDef.GetPtr()));
                        phandle->FontScaleFactor = scaleFactor;
                    }
                    else
                    {
                        psetNode->pNode->AddRef();
                        return psetNode->pNode;
                    }
                }
            }
        }
    }

    // the font library
    if (!phandle && pfontLib)
    {
        FontLib::FontResult fr;
        if (pfontLib->FindFont(&fr, plookupFontName, lookupFlags, pDefImpl, pState, pWeakLib))
        {
            if (overridenFlags)
            {
                FontKey lookupKey(pfontName, overridenFlags);
                psetNode = CreatedFonts.Get(lookupKey);
                if (!psetNode)
                {
                    phandle = new FontHandle(searchInfo ? 0 : this, fr.GetFontResource()->GetFont(), pfontName,
                                             overridenFlags, fr.GetMovieDef());
                    phandle->FontScaleFactor = scaleFactor;
                }
                else
                {
                    psetNode->pNode->AddRef();
                    return psetNode->pNode;
                }
                AddSearchInfo(searchInfo, "Searching FontLib: \"", pfontName, "\" ", overridenFlags, " found.");
            }
            else
            {
                phandle = new FontHandle(searchInfo ? 0 : this, fr.GetFontResource()->GetFont(), pfontName, 0,
                                         fr.GetMovieDef());
                phandle->FontScaleFactor = scaleFactor;
                AddSearchInfo(searchInfo, "Searching FontLib: \"", plookupFontName, "\" ", lookupFlags, " found.");
            }
        }
        else
            AddSearchInfo(searchInfo, "Searching FontLib: \"", plookupFontName, "\" ", lookupFlags, " not found.");
    }
    if (!secondLoop && searchInfo && !phandle && !pfontLib &&
        resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInResourcesNoGlyphs)
        AddSearchInfo(searchInfo, "FontLib not installed.");

    // the font provider (system fonts)
    if (!phandle && pfontProvider)
    {
        Ptr<FontResource> pfont = *FontResource::CreateFontResource(
            plookupFontName, lookupFlags, pfontProvider,
            pDefImpl ? pDefImpl->GetWeakLib() : pWeakLib);
        if (pfont)
        {
            AddSearchInfo(searchInfo, "Searching FontProvider: \"", plookupFontName, "\" ", lookupFlags, " found.");
            phandle = new FontHandle(searchInfo ? 0 : this, pfont->GetFont(), pfontName, 0, 0);
            phandle->FontScaleFactor = scaleFactor;
        }
        else
            AddSearchInfo(searchInfo, "Searching FontProvider: \"", plookupFontName, "\" ", lookupFlags,
                          " not found.");
    }
    if (!secondLoop && searchInfo && !phandle && !pfontProvider &&
        resSearchInfo.Status == MovieDefImpl::SearchInfo::FoundInResourcesNoGlyphs)
        AddSearchInfo(searchInfo, "FontProvider not installed.");

    // a device font request may still be met by a library font
    if (!phandle && pfontLib && (lookupFlags & Render::Font::FF_DeviceFont))
    {
        unsigned            lf = lookupFlags & ~Render::Font::FF_DeviceFont;
        FontLib::FontResult fr;
        if (pfontLib->FindFont(&fr, plookupFontName, lf, pDefImpl, pState))
        {
            phandle = new FontHandle(searchInfo ? 0 : this, fr.GetFontResource()->GetFont(), pfontName,
                                     Render::Font::FF_DeviceFont, fr.GetMovieDef());
            phandle->FontScaleFactor = scaleFactor;
            AddSearchInfo(searchInfo, "Searching FontLib without [Device] flag: \"", plookupFontName, "\" ", lf,
                          " found.");
        }
        else
            AddSearchInfo(searchInfo, "Searching FontLib without [Device] flag: \"", plookupFontName, "\" ", lf,
                          " not found.");
    }

    if (phandle)
    {
        if (searchInfo)
            searchInfo->Indent -= indentDif;
        else
            CreatedFonts.Add(phandle);
        return phandle;
    }

    if (matchFontFlags & Render::Font::FF_DeviceFont)
    {
        AddSearchInfo(searchInfo, "Searching again without [Device] flag:");
        matchFontFlags &= ~Render::Font::FF_DeviceFont;
        key.FontStyle = matchFontFlags;
        pfontProvider = 0;
        pfontLib      = 0;
        secondLoop    = true;
        goto retry_font_lookup;
    }
    if (searchInfo)
        searchInfo->Indent -= indentDif;
    return 0;
}

FontHandle* FontManager::CreateFontHandle(const char* pfontName, unsigned matchFontFlags, bool allowListOfFonts,
                                          FontSearchPathInfo* searchInfo)
{
    if (!allowListOfFonts)
        return CreateFontHandleFromName(pfontName, matchFontFlags, searchInfo);

    FontHandle* fh = 0;
    const char* pe = 0;
    char        buf[128];
    do
    {
        pe = SFstrchr(pfontName, ',');
        const char* curName;
        if (pe)
        {
            UPInt len = pe - pfontName;
            if (len > sizeof(buf) - 1)
                continue; // a name too long for the buffer is skipped
            strncpy_s(buf, sizeof(buf) - 1, pfontName, len);
            buf[len]  = '\0';
            curName   = buf;
            pfontName = pe + 1;
        }
        else
            curName = pfontName;
        fh = CreateFontHandleFromName(curName, matchFontFlags, searchInfo);
    } while (!fh && pe != 0);
    return fh;
}

FontHandle* FontManager::CreateFontHandleFromName(const char* pfontName, unsigned matchFontFlags,
                                                  FontSearchPathInfo* searchInfo)
{
    int saveIndent = 0;
    if (searchInfo)
    {
        saveIndent = searchInfo->Indent;
        AddSearchInfo(searchInfo, "Searching for font: \"", pfontName, "\" ", matchFontFlags, "");
    }
    FontResource* pfoundFont = 0;
    FontHandle*   phandle    = FindOrCreateHandle(pfontName, matchFontFlags, &pfoundFont, searchInfo);
    if (!phandle)
    {
        // bold / italic faked from the plain face
        if (matchFontFlags & Render::Font::FF_Style_Mask)
        {
            unsigned newMatchFontFlags = matchFontFlags & ~Render::Font::FF_Style_Mask;
            if (searchInfo)
            {
                searchInfo->Indent++;
                AddSearchInfo(searchInfo, "Searching for font: \"", pfontName, "\" ", newMatchFontFlags, "");
            }
            Ptr<FontHandle> pplainHandle = *FindOrCreateHandle(pfontName, newMatchFontFlags, 0, searchInfo);
            if (pplainHandle)
            {
                phandle = new FontHandle(*pplainHandle);
                phandle->FontFlags |= (matchFontFlags & Render::Font::FF_Style_Mask);
                if (!searchInfo)
                    CreatedFonts.Add(phandle);
                else
                    AddSearchInfo(searchInfo, "Font \"", pfontName, "\" ", matchFontFlags,
                                  " will be generated from \"", pfontName, "\"", newMatchFontFlags);
            }
        }
    }
    if (searchInfo)
        searchInfo->Indent = saveIndent;

    // a font of the name exists but cannot render the style: an empty font of the name
    if (!phandle && pfoundFont)
    {
        AddSearchInfo(searchInfo, "Empty font: \"", pfontName, "\" is created");
        phandle = new FontHandle(searchInfo ? 0 : this, pfoundFont->GetFont(), pfontName, 0, 0);
        if (!searchInfo)
            CreatedFonts.Add(phandle);
    }
    if (!phandle)
        AddSearchInfo(searchInfo, "Font not found.");
    return phandle;
}

void FontManager::SetIMECandidateFont(FontHandle* pfont)
{
    pIMECandidateFont = pfont;
}

FontHandle* FontManager::GetEmptyFont()
{
    pEmptyFont->AddRef();
    return pEmptyFont;
}

void FontManager::CleanCache()
{
    for (FontSet::Iterator it = CreatedFonts.Begin(); it != CreatedFonts.End(); ++it)
    {
        FontHandle* phandle   = it->pNode;
        phandle->pFontManager = 0;
    }
    CreatedFonts.Clear();
}

void FontManager::CleanCacheFor(MovieDefImpl* pdefImpl)
{
    for (FontSet::Iterator it = CreatedFonts.Begin(); it != CreatedFonts.End(); ++it)
    {
        FontHandle* phandle = it->pNode;
        if (phandle->pSourceMovieDef == static_cast<Resource*>(pdefImpl))
        {
            phandle->pFontManager = 0;
            it.Remove();
        }
    }
}

}} // namespace Scaleform::GFx
