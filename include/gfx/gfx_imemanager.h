// Recovered Scaleform 4.1.18 GFx: the IME manager state as the AS3 flash.system.IME class reaches it (sfr12).
// The exe's vftable slots 6..9 are the conversion mode and enable switches; the others are kept as placeholders.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder virtuals.
#ifndef MS2_SF_GFX_IMEMANAGER_H
#define MS2_SF_GFX_IMEMANAGER_H

#include "gfx_state.h"
#include "../kernel/sf_string.h"

namespace Scaleform { namespace GFx {

class ASString;
class DisplayObject;
class Movie;
class Loader;

class IMEManagerBase : public State
{
public:
    virtual ~IMEManagerBase() {}                                        // 0
private:
    virtual void Slot01();                                              // Init
public:
    // (sfr26) the IME command of the imecommand global (command, parameter).
    virtual void IMECommand(Movie* pmovie, const char* pcommand, const char* pparams); // 2
private:
    virtual void Slot03();                                              // ProcessIMEMessage
    virtual void Slot04();                                              // HandleIMEEvent
    virtual void Slot05();                                              // ClearCandidateListPath
public:
    virtual bool        SetConversionMode(const UInt32 convMode);       // 6
    virtual const char* GetConversionMode();                            // 7
    virtual bool        SetEnabled(bool enable);                        // 8
    virtual bool        GetEnabled();                                   // 9
private:
public:
    // (sfr26) the language of the active input locale.
    virtual String GetInputLanguage();                                  // 10
private:
    virtual void Slot11();                                              // BroadcastIMEConversion
    virtual void Slot12();                                              // BroadcastSwitchLanguage
    virtual void Slot13();                                              // BroadcastSetSupportedLanguages
    virtual void Slot14();                                              // BroadcastSetSupportedIMEs
    virtual void Slot15();                                              // BroadcastSetCurrentInputLanguage
    virtual void Slot16();                                              // BroadcastSetIMEName
    virtual void Slot17();                                              // BroadcastSetConversionStatus
    virtual void Slot18();                                              // BroadcastRemoveStatusWindow
    virtual void Slot19();                                              // BroadcastDisplayStatusWindow
public:
    // (appended for flash.gfx.IMEEx, sfr19)
    virtual void SendLangBarMessage(DisplayObject* mc, const ASString& command, const ASString& message);   // 20
private:
    virtual void Slot21();                                              // SetCompositionString
public:
    // (appended for flash.gfx.IMEEx, sfr13)
    virtual const wchar_t* GetCompositionString();                      // 22
private:
    virtual void Slot23();                                              // OnShutdown
    virtual void Slot24();                                              // OnFinalize
    virtual void Slot25();                                              // OnCandidateListStyleChanged
    virtual void Slot26();                                              // OnCandidateListLoaded
    virtual void Slot27();                                              // OnCandidateListStyleRequest
    virtual void Slot28();                                              // OnEnableIME
    virtual void Slot29();                                              // SetActiveMovie
public:
    // (sfr19) whether pmovie is the movie the IME works for.
    virtual bool IsMovieActive(Movie* pmovie) const;                    // 30
private:
    virtual void Slot31();                                              // GetActiveMovie
    virtual void Slot32();                                              // ClearActiveMovie
public:
    virtual String      GetWindowsVersion();                            // 33

    // (appended, sfr19) what the AS3 IME manager uses.
    // Ends the composition (OnFinalize) and drops the focused text field.
    void DoFinalize();                                                  // 0x1425b43d0
    // Switches the IME on or off (OnEnableIME) when that changes IMEDisabled.
    void EnableIME(bool enable);                                        // 0x1425b4400

private:
    UByte   Unrecovered_18[0x28 - 0x18];    // +0x18 Ptr<ASIMEManager>, the active movie
public:
    Loader* pLoader;                        // +0x28 where the file opener and URL builder states come from
private:
    UByte   Unrecovered_30[0x58 - 0x30];    // +0x30 the focused text field, cursor, candidate list path, flags
public:
    bool    bCheckIMEExists;                // +0x58 check that the candidate list file exists before loading it
};

}} // namespace Scaleform::GFx

#endif
