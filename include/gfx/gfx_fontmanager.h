// Recovered Scaleform 4.1.18 GFx: FontManager, the per-movie font lookup (device fonts, the font library, the
// movie's own and imported fonts). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The class is recovered from GFx_FontManager (sfr_gfx_07g): 0x70 bytes, vftable 0x14318f7b8.
#ifndef MS2_SF_GFX_FONTMANAGER_H
#define MS2_SF_GFX_FONTMANAGER_H

#include <string.h>
#include "../kernel/sf_std.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_hash.h"
#include "../kernel/sf_array.h"
#include "gfx_fontlib.h"
#include "gfx_fonthandle.h"
#include "gfx_fontmap.h"
#include "gfx_fontprovider.h"
#include "../render/text_fontmanager.h"

namespace Scaleform { namespace GFx {

class MovieImpl;
class MovieDefImpl;
class MovieDataDef;
class ResourceWeakLib;
class Translator;

// The font states the font managers of one movie share: font library, map, provider and translator, each cached so
// a change can be detected; every other state is asked from pDelegate (0x40 bytes).
class FontManagerStates : public RefCountBaseNTS<FontManagerStates, Stat_Default_Mem>, public StateBag
{
public:
    Ptr<FontLib>      pFontLib;      // +0x18
    Ptr<FontMap>      pFontMap;      // +0x20
    Ptr<FontProvider> pFontProvider; // +0x28
    Ptr<Translator>   pTranslator;   // +0x30
    StateBag*         pDelegate;     // +0x38 the movie's StateBag (not counted: the movie owns these states)

#ifdef SF_GFX_PLAYERIMPL   // (inline in MovieImpl's ctor; the members' dtors need the complete state types)
    FontManagerStates(StateBag* pdelegate) : pDelegate(pdelegate) {}
#endif

    // StateBag: the delegate's state bag (0x14256fb80).
    virtual StateBag* GetStateBagImpl() const { return pDelegate; }

    // StateBag: the four font states here, the rest from pDelegate (0x14263da70).
    virtual State* GetStateAddRef(State::StateType state) const;

    // Takes the four states; the DisplayObjectBase::StateChanged_* bits of the ones that changed (0x14263c330).
    UInt8 CheckStateChange(FontLib* pfontLib, FontMap* pfontMap, FontProvider* pfontProvider,
                           Translator* ptranslator);
};

class FontManager : public Render::Text::FontManagerBase
{
    friend class FontHandle;

public:
    // A cache lookup key: a font name and the style asked for.
    struct FontKey
    {
        const char* pFontName;
        unsigned    FontStyle;

        FontKey() : FontStyle(0) {}
        FontKey(const char* pfontName, unsigned style) : pFontName(pfontName), FontStyle(style) {}

        static UPInt CalcHashCode(const char* pname, UPInt namelen, unsigned fontFlags)
        {
            UPInt hash = String::BernsteinHashFunctionCIS(pname, namelen);
            return hash ^ (fontFlags & Render::Font::FF_Style_Mask);
        }
    };

    // A cached handle. SearchedForNonDeviceFont: a device font handle that a request without the device flag has
    // already been resolved against (no embedded font of the name exists).
    struct NodePtr
    {
        FontHandle*  pNode;
        mutable bool SearchedForNonDeviceFont;

        NodePtr() {}
        NodePtr(FontHandle* pnode) : pNode(pnode), SearchedForNonDeviceFont(false) {}
        NodePtr(const NodePtr& other) : pNode(other.pNode), SearchedForNonDeviceFont(other.SearchedForNonDeviceFont)
        {
        }

        // Same handle, or the same name with the same style, code page and device bits (a device and an embedded
        // font of one name may both be cached; out-of-line copy 0x14263b630).
        bool operator==(const NodePtr& other) const
        {
            if (pNode == other.pNode)
                return true;
            enum { FontFlagsMask = Render::Font::FF_CreateFont_Mask | Render::Font::FF_DeviceFont };
            unsigned ourFlags   = pNode->GetFontFlags() & FontFlagsMask;
            unsigned otherFlags = other.pNode->GetFontFlags() & FontFlagsMask;
            return ourFlags == otherFlags && !String::CompareNoCase(pNode->GetFontName(), other.pNode->GetFontName());
        }

        // A cached font matching the key's style.
        bool operator==(const FontKey& key) const
        {
            return Render::Font::MatchFontFlags_Static(pNode->GetFontFlags(), key.FontStyle) &&
                   !String::CompareNoCase(pNode->GetFontName(), key.pFontName);
        }
    };

    struct NodePtrHashOp
    {
        UPInt operator()(const NodePtr& other) const
        {
            FontHandle* pnode     = other.pNode;
            const char* pfontName = pnode->GetFontName();
            return FontKey::CalcHashCode(pfontName, SFstrlen(pfontName),
                                         pnode->GetFontStyle() | pnode->GetFont()->GetFontFlags());
        }
        UPInt operator()(const FontHandle* pnode) const
        {
            const char* pfontName = pnode->GetFontName();
            return FontKey::CalcHashCode(pfontName, SFstrlen(pfontName),
                                         pnode->GetFont()->GetFontFlags() | pnode->GetFontStyle());
        }
        UPInt operator()(const FontKey& data) const
        {
            return FontKey::CalcHashCode(data.pFontName, SFstrlen(data.pFontName), data.FontStyle);
        }
    };

    typedef HashSetLH<NodePtr, NodePtrHashOp, NodePtrHashOp> FontSet;

protected:
    FontSet                   CreatedFonts;      // +0x10 every live handle made by this manager
    Array<Ptr<MovieDataDef> > FontMovies;        // +0x18
    MovieDefImpl*             pDefImpl;          // +0x30 searched first
    ResourceWeakLib*          pWeakLib;          // +0x38 for provider fonts when there is no pDefImpl
    FontManagerStates*        pState;            // +0x40
    Ptr<FontHandle>           pEmptyFont;        // +0x48 handed out when nothing matches
    FontMap::MapEntry         FontMapEntry;      // +0x50 scratch entry of the font map lookups
    MovieImpl*                pMovie;            // +0x60 for its registered fonts
    Ptr<FontHandle>           pIMECandidateFont; // +0x68

    // The cached or a new handle of exactly that name and style (no faux styles). A font that exists but needs a
    // faux style is handed back through ppfoundFont (0x14263cb70).
    FontHandle* FindOrCreateHandle(const char* pfontName, unsigned matchFontFlags, FontResource** ppfoundFont,
                                   FontSearchPathInfo* searchInfo);
    // One name: the font itself, else its plain style with faux bold / italic, else an empty font of the name
    // (0x14263c790).
    FontHandle* CreateFontHandleFromName(const char* pfontName, unsigned matchFontFlags,
                                         FontSearchPathInfo* searchInfo);

private:
    void commonInit();

public:
    // The font manager of one root movie (0x14263b350) / of a resource library (0x14263b400).
    FontManager(MovieImpl* pmovie, MovieDefImpl* pdefImpl, FontManagerStates* pfontStates);
    FontManager(ResourceWeakLib* pweakLib, FontManagerStates* pfontStates);
    ~FontManager();

    // A handle on the first font of the comma separated list that is found (or on pfontName as a whole); a search
    // info makes it a diagnostic search that neither uses nor fills the cache.
    virtual FontHandle* CreateFontHandle(const char* pfontName, unsigned matchFontFlags, bool allowListOfFonts = true,
                                         FontSearchPathInfo* searchInfo = 0);

    // Called by a dying handle.
    void RemoveFontHandle(FontHandle* phandle);

    virtual FontHandle* GetEmptyFont();

    // Drops every cached handle (they stay alive but forget the manager).
    virtual void CleanCache();
    void         CleanCacheFor(MovieDefImpl* pdefImpl);

    // Font used by the IME candidate list window (0x14263db50, an ICF-folded body).
    void SetIMECandidateFont(FontHandle* pfont);

    MovieDefImpl* GetDefImpl() const { return pDefImpl; }
};

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::FontManager) == 0x70, "FontManager size");

#endif
