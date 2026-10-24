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
class InteractiveObject;
class Movie;
class Loader;
class ASIMEManager;
class IMEEvent;

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
public:
    // (sfr24) an IME event the movie got; HE_ReturnValueType bits.
    virtual unsigned HandleIMEEvent(Movie* pmovie, const IMEEvent& imeEvent); // 4
private:
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
public:
    // (sfr24) the movie the IME works for from now on.
    virtual void SetActiveMovie(Movie* pmovie);                         // 29
    // (sfr19) whether pmovie is the movie the IME works for.
    virtual bool IsMovieActive(Movie* pmovie) const;                    // 30
private:
    virtual void Slot31();                                              // GetActiveMovie
public:
    // (sfr24) the movie being destroyed lets go of the IME.
    virtual void ClearActiveMovie();                                    // 32
    virtual String      GetWindowsVersion();                            // 33

    // (appended, sfr19) what the AS3 IME manager uses.
    // Ends the composition (OnFinalize) and drops the focused text field.
    void DoFinalize();                                                  // 0x1425b43d0
    // Switches the IME on or off (OnEnableIME) when that changes IMEDisabled.
    void EnableIME(bool enable);                                        // 0x1425b4400
    // (appended, sfr24) what the player's OnMovieFocus uses.
    // Ends the composition with the given text (len ~0: up to the terminator).
    void FinalizeComposition(const wchar_t* pstr, UPInt len = ~UPInt(0)); // 0x1425b4420
    // Widens or narrows the focused text field's cursor.
    void SetWideCursor(bool ow = true);                                 // 0x1425b4ec0
    // (appended, sfr24) a mouse button went down / up over ptopMostChar (the player's ProcessMouse).
    void OnMouseDown(Movie* pmovie, int buttonsState, InteractiveObject* ptopMostChar);   // 0x1425b4900
    void OnMouseUp(Movie* pmovie, int buttonsState, InteractiveObject* ptopMostChar);     // 0x1425b4960

public:
    // (sfr24) the VM side of the IME (a Ptr; raw here so the header needs no complete ASIMEManager).
    ASIMEManager* pASIMEManager;            // +0x18
private:
    UByte   Unrecovered_20[0x28 - 0x20];    // +0x20 the active movie
public:
    Loader* pLoader;                        // +0x28 where the file opener and URL builder states come from
private:
    UByte   Unrecovered_30[0x58 - 0x30];    // +0x30 the focused text field, cursor, candidate list path, flags
public:
    bool    bCheckIMEExists;                // +0x58 check that the candidate list file exists before loading it
};

}} // namespace Scaleform::GFx

#endif
