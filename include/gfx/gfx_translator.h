// Recovered Scaleform 4.1.18 GFx: Translator, the state a host installs to replace text field contents (0x20 bytes).
// Only what the GFx UI's font config reader (sfr_gfx_11) uses; its inline members are COMDATs of that unit
// (ctor 0x1422fbeb0, GetCaps 0x1422fce40, Translate 0x1422fe430, TranslateInfo::GetKey 0x1422fcee0,
// TranslateInfo::SetResultHtml 0x1422fe320). OnWordWrapping and TranslateInfo::SetResult are in sfr_gfx_02f.
#ifndef MS2_SF_GFX_TRANSLATOR_H
#define MS2_SF_GFX_TRANSLATOR_H

#include "../kernel/sf_types.h"
#include "gfx_state.h"
#include "gfx_fontmap.h"
#include "gfx_moviedef.h"

namespace Scaleform {

class WStringBuffer;

namespace GFx {

class Translator : public State
{
public:
    enum TranslateCaps
    {
        Cap_ReceiveHtml           = 0x1,
        Cap_StripTrailingNewLines = 0x2
    };

    unsigned WWMode; // +0x18 word wrapping mode, 0 = default

    Translator() : State(State_Translator), WWMode(0) {}

    virtual unsigned GetCaps() const { return 0; }

    // The text going in (key) and the replacement coming out.
    class TranslateInfo
    {
    protected:
        const wchar_t* pKey;          // +0
        WStringBuffer* pResult;       // +8
        const char*    pInstanceName; // +0x10
        enum
        {
            Flag_Translated = 0x01,
            Flag_ResultHtml = 0x02
        };
        UInt8 Flags;                  // +0x18

    public:
        const wchar_t* GetKey() const { return pKey; }

        void SetResult(const wchar_t* presultText, UPInt resultLen = SF_MAX_UPINT);
        void SetResult(const char* presultTextUTF8, UPInt resultUTF8Len = SF_MAX_UPINT);

        void SetResultHtml(const char* presultHtmlUTF8, UPInt resultLen = SF_MAX_UPINT)
        {
            SetResult(presultHtmlUTF8, resultLen);
            Flags |= Flag_ResultHtml;
        }
    };

    virtual void Translate(TranslateInfo* ptranslateInfo) { (void)ptranslateInfo; }

    struct LineFormatDesc;
    virtual bool OnWordWrapping(LineFormatDesc* pdesc);
};

inline void StateBag::SetFontMap(FontMap* ptr)
{
    SetState(State::State_FontMap, ptr);
}
inline void StateBag::SetTranslator(Translator* ptr)
{
    SetState(State::State_Translator, ptr);
}

}} // namespace Scaleform::GFx

#endif
