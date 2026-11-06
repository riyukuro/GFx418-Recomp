// Recovered Scaleform 4.1.18 GFx: the Win32 IME manager, GFx::IME::GFxIMEManagerWin32 (0xc8 bytes, base IMEManagerBase,
// no RTTI in the exe; 38-slot vtable 0x1431383e0, slots 34-37 its own). The partial SDK in work/scaleform has no source
// for it; the bodies are in sfr_ime_01 / sfr_as2_01c. Shared header of the src/ms2/scaleform units and GFxManager.
#ifndef MS2_SF_GFX_IMEMANAGERWIN32_H
#define MS2_SF_GFX_IMEMANAGERWIN32_H

#include <stddef.h>
#include "gfx_imemanager.h"

struct HWND__;

namespace Scaleform { namespace GFx { namespace IME {

class GFxIMEManagerWin32 : public IMEManagerBase
{
public:
    explicit GFxIMEManagerWin32(::HWND__* hwnd);                     // 0x1423c8a50
    virtual ~GFxIMEManagerWin32();                                  // 0x1423c8ac0

    // the IMEManagerBase overrides (vtable 0x1431383e0 slot: body VA)
    virtual UInt32 Init(Log* plog, FileOpener* fileOpener = NULL, const char* xmlFileName = NULL,
                        bool bcheckIMEExists = false);                  // 1: 0x1423c9ba0
    virtual void IMECommand(Movie* pmovie, const char* pcommand, const char* pparams); // 2: 0x1423ccfc0
    virtual void ProcessIMEMessage(const FunctionHandler::Params& params); // 3: 0x1423cd0a0
    virtual unsigned HandleIMEEvent(Movie* pmovie, const IMEEvent& imeEvent); // 4: 0x1423c9780
    virtual void ClearCandidateListPath();                              // 5: 0x1423c92f0
    virtual bool        SetConversionMode(const UInt32 convMode);       // 6: 0x1423ca540
    virtual const char* GetConversionMode();                            // 7: 0x1423c9570
    virtual bool        SetEnabled(bool enable);                        // 8: 0x1423ca620
    virtual bool        GetEnabled();                                   // 9: 0x1423c9590
    virtual const String GetInputLanguage();                            // 10: 0x1423c95b0
    virtual void SendLangBarMessage(DisplayObject* mc, const ASString& command, const ASString& message); // 20: 0x1423cd6b0
    virtual bool SetCompositionString(const char* pcompString);         // 21: 0x1423ca520
    virtual void OnShutdown();                                          // 23: 0x1423ca210
    virtual void OnFinalize();                                          // 24: 0x1423ca1c0
    virtual void OnCandidateListStyleChanged(const IMECandidateListStyle& style); // 25: 0x1423ca140
    virtual void OnCandidateListLoaded(const char* pcandidateListPath); // 26: 0x1423ca100
    virtual void OnEnableIME(bool enable);                              // 28: 0x1423ca160
    virtual void SetActiveMovie(Movie* pmovie);                         // 29: 0x1423ca410
    virtual String      GetWindowsVersion();                            // 33: 0x1423c9670

    // its own virtuals (slots 34-37; the SDK has no source, the names are ours)
    virtual bool IsCandidateListPath(const char* path);                 // 34: 0x1423ca060 "_level9999"
    virtual bool IsLangBarPath(const char* path);                       // 35: 0x1423ca0a0 "_level9997"
    virtual bool IsStatusWindowPath(const char* path);                  // 36: 0x1423ca080 "_level9998"
    virtual void GetOSVersion(int* os);                                 // 37: 0x1423c96d0

public:
    ::HWND__*   hwnd;                       // +0x68 the game window
    void*       p70;                        // +0x70 the language bar / composition window (the slot calls pass to it)
    void*       p78;                        // +0x78
    UInt32      m_80;
    UInt32      m_dwConversionMode;         // +0x84 (GFxManager::FUN_1422af8a0; 0x1000000 = none)
    String      language;                   // +0x88
    String      imeName;                    // +0x90
    String      displayName;                // +0x98
    unsigned char pad_a0[0x10];
    String      conversionMode;             // +0xb0 the input language's name (FUN_1423ca560)
    unsigned char pad_b8[0x10];
};

static_assert(offsetof(GFxIMEManagerWin32, hwnd) == 0x68, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, m_dwConversionMode) == 0x84, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, language) == 0x88, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, conversionMode) == 0xb0, "IME layout");
static_assert(sizeof(GFxIMEManagerWin32) == 0xc8, "IME layout");   // the deleting destructor frees 0xc8 bytes

}}}

#endif
