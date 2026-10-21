// Recovered Scaleform 4.1.18 GFx Text: StyleManager, the CSS style sheet of TextField.StyleSheet - styles by tag or
// class name, filled by parsing CSS text. Bodies: unit sfr_gfx_06g (Text_StyleSheet).
// Built on the render text headers (the ms2/scaleform/kernel tree), so it does not mix with the gfx headers of the
// include/kernel tree in one unit.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_TEXT_STYLESHEET_H
#define MS2_SF_GFX_TEXT_STYLESHEET_H

#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/include/render/text_styledtext.h"

namespace Scaleform { namespace GFx { namespace Text {

using Render::Text::Style;
using Render::Text::StyleManagerBase;

enum { StatMV_Text_Mem = StatGroup_GFxMovieView + 5 };

// A style name with its kind; the hash value is computed when the key is set.
struct StyleKey
{
    typedef StyleManagerBase::KeyType KeyType;

    KeyType  Type;      // +0
    StringLH Value;     // +8
    UPInt    HashValue; // +0x10

    StyleKey() : Type(StyleManagerBase::CSS_None) {}

    void Set(KeyType type, const String& value)
    {
        Type      = type;
        Value     = value;
        HashValue = String::BernsteinHashFunction(value.ToCStr(), value.GetSize());
        HashValue += Type;
    }

    bool operator==(const StyleKey& other) const { return Type == other.Type && Value == other.Value; }
};

template<class C>
class StyleHashFunc
{
public:
    UPInt operator()(const C& key) const { return key.HashValue; }
};

typedef HashUncachedLH<StyleKey, Style*, StyleHashFunc<StyleKey>, StatMV_Text_Mem> StyleHash;

// vftable 0x14316a738 (the StyleManagerBase one is 0x14316a718).
class StyleManager : public StyleManagerBase
{
    template<class Char> friend class TextStyleParserHandler;

public:
    enum States
    {
        Ready           = 0,
        Loading         = 1,
        LoadingFinished = 2,
        Error           = 3
    };

    StyleManager() : State(Ready) {}
    ~StyleManager();

    bool ParseCSS(const char* buffer, UPInt len);
    bool ParseCSS(const wchar_t* buffer, UPInt len);

    const StyleHash& GetStyles() const;

    virtual const Style* GetStyle(KeyType type, const String& name) const;
    virtual const Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const;
    virtual const Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const;

    void AddStyle(const StyleKey& key, Style* pstyle);
    void ClearStyles();
    void ClearStyle(KeyType type, const String& name);
    void ClearStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT);

    // The key of a lookup, kept in the manager so that a lookup needs no key construction.
    const StyleKey& GetTempStyleKey(KeyType type, const String& name) const
    {
        TempKey.Set(type, name);
        return TempKey;
    }

    bool IsReady() const            { return State == Ready; }
    bool IsLoading() const          { return State == Loading; }
    bool IsLoadingFinished() const  { return State == LoadingFinished; }
    bool IsError() const            { return State == Error; }
    void SetState(States s)         { State = s; }

private:
    template<class Char>
    bool ParseCSSImpl(const Char* buffer, UPInt len);

    StyleHash        Styles;  // +8
    mutable StyleKey TempKey; // +0x10
    mutable States   State;   // +0x28
};

}}} // namespace Scaleform::GFx::Text

#endif
