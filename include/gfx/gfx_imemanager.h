// Recovered Scaleform 4.1.18 GFx: the IME manager state as the AS3 flash.system.IME class reaches it (sfr12).
// (sfr33) All 34 slots and the 0x68-byte layout recovered from the exe (vftable 0x1431898c8, sfr_gfx_03d).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder virtuals.
#ifndef MS2_SF_GFX_IMEMANAGER_H
#define MS2_SF_GFX_IMEMANAGER_H

#include "gfx_state.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_hash.h"
#include "gfx_asimemanager.h"
#include "ms2/scaleform/include/render/render_types2d.h"   // (sfr33) RectF

namespace Scaleform { class Log; }   // (sfr33) kernel/sf_log.h

namespace Scaleform { namespace GFx {

class ASString;
class DisplayObject;
class InteractiveObject;
class Movie;
class Loader;
class ASIMEManager;
class IMEEvent;
class IMECandidateListStyle;    // (appended, sfr24) gfx_imecandidateliststyle.h
class FileOpener;               // (appended, sfr33)
class TextField;

class IMEManagerBase : public State
{
public:
    // (sfr33) the highlight look HighlightText gives a part of the composition string (Text::IMEStyle::Category).
    enum TextHighlightStyle
    {
        THS_CompositionSegment = 0,
        THS_ClauseSegment      = 1,
        THS_ConvertedSegment   = 2,
        THS_PhraseLengthAdj    = 3,
        THS_LowConfSegment     = 4
    };

    // (sfr33) The base bodies (GFx_IMEManager, sfr_gfx_03d) are the do-nothing defaults the Win32 manager overrides;
    // the Broadcast* ones pass the event on to the VM side.
    IMEManagerBase();
    virtual ~IMEManagerBase();                                          // 0
    // Remembers whether the candidate list file is checked before loading; 1 on success.
    virtual UInt32 Init(Log* plog, FileOpener* fileOpener = NULL, const char* xmlFileName = NULL,
                        bool bcheckIMEExists = true);                   // 1
    // (sfr26) the IME command of the imecommand global (command, parameter).
    virtual void IMECommand(Movie* pmovie, const char* pcommand, const char* pparams); // 2
    // A message the IME movies send (SendIMEMessage, through ASIMEManager::IMEFuncHandler).
    virtual void ProcessIMEMessage(const FunctionHandler::Params& params); // 3
    // (sfr24) an IME event the movie got; HE_ReturnValueType bits.
    virtual unsigned HandleIMEEvent(Movie* pmovie, const IMEEvent& imeEvent); // 4
    virtual void ClearCandidateListPath();                              // 5
    virtual bool        SetConversionMode(const UInt32 convMode);       // 6
    virtual const char* GetConversionMode();                            // 7
    virtual bool        SetEnabled(bool enable);                        // 8
    virtual bool        GetEnabled();                                   // 9
    // (sfr26) the language of the active input locale.
    virtual const String GetInputLanguage();                            // 10
    // The language bar / status window events, passed to the VM side (sfr33).
    virtual void BroadcastIMEConversion(const wchar_t* pstr);           // 11
    virtual void BroadcastSwitchLanguage(const char* pstr);             // 12
    virtual void BroadcastSetSupportedLanguages(const char* pstr);      // 13
    virtual void BroadcastSetSupportedIMEs(const char* pstr);           // 14
    virtual void BroadcastSetCurrentInputLanguage(const char* pstr);    // 15
    virtual void BroadcastSetIMEName(const char* pstr);                 // 16
    virtual void BroadcastSetConversionStatus(const char* pstr);        // 17
    virtual void BroadcastRemoveStatusWindow();                         // 18
    virtual void BroadcastDisplayStatusWindow();                        // 19
    // (appended for flash.gfx.IMEEx, sfr19)
    virtual void SendLangBarMessage(DisplayObject* mc, const ASString& command, const ASString& message);   // 20
    // (sfr22) System.IME.setCompositionString: replaces the composition string, false when it cannot.
    virtual bool SetCompositionString(const char* pcompString);         // 21
    // (appended for flash.gfx.IMEEx, sfr13)
    virtual const wchar_t* GetCompositionString();                      // 22
    // (sfr33) the notifications a platform manager overrides.
    virtual void OnShutdown();                                          // 23
    virtual void OnFinalize();                                          // 24
    virtual void OnCandidateListStyleChanged(const IMECandidateListStyle& style); // 25
    virtual void OnCandidateListLoaded(const char* pcandidateListPath); // 26
    virtual void OnCandidateListStyleRequest(IMECandidateListStyle* pstyle) const; // 27
    virtual void OnEnableIME(bool enable);                              // 28
    // (sfr24) the movie the IME works for from now on.
    virtual void SetActiveMovie(Movie* pmovie);                         // 29
    // (sfr19) whether pmovie is the movie the IME works for.
    virtual bool IsMovieActive(Movie* pmovie) const;                    // 30
    virtual Movie* GetActiveMovie() const;                              // 31
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
    // (appended, sfr24) the candidate list style of the active movie (false without one); setting it also tells the
    // candidate list movie (OnCandidateListStyleChanged) once it is loaded.
    bool GetCandidateListStyle(IMECandidateListStyle* pstyle) const;      // 0x1425b4570
    bool SetCandidateListStyle(const IMECandidateListStyle& st);         // 0x1425b4de0

    // (appended, sfr33) the composition calls of the platform manager.
    void StartComposition();                                            // 0x1425b4ed0
    void ClearComposition();                                            // 0x1425b43c0
    void SetCompositionText(const wchar_t* pstr, UPInt len = ~UPInt(0)); // 0x1425b4e80
    void SetCompositionPosition();                                      // 0x1425b4e40
    void SetCursorInComposition(UPInt pos);                             // 0x1425b4ea0
    void HighlightText(UPInt pos, UPInt len, TextHighlightStyle style, bool clause); // 0x1425b4820
    // The focused field's rectangle and the cursor's (cursorOffset characters on), in pixels.
    void GetMetrics(Render::RectF* pviewRect, Render::RectF* pcursorRect, int cursorOffset); // 0x1425b46b0
    // The candidate list's load error, true when there is one.
    bool GetCandidateListErrorMsg(String* pdest);                        // 0x1425b4530

public:
    // (sfr24) the VM side of the IME for the active movie.
    Ptr<ASIMEManager>   pASIMEManager;              // +0x18
    Movie*              pMovie;                     // +0x20 the active movie
    Loader*             pLoader;                    // +0x28 where the file opener and URL builder states come from
    Ptr<TextField>      pTextField;                 // +0x30 the field being composed into
    UPInt               CursorPosition;             // +0x38 where the composition started
    String              CandidateSwfPath;           // +0x40
    bool                IMEDisabled;                // +0x48
    // One VM side per movie the IME was active for.
    Hash<Movie*, Ptr<ASIMEManager>, FixedSizeHash<Movie*> > MovieASIMEManagerHash;   // +0x50
    bool                bCheckIMEExists;            // +0x58 check that the candidate list file exists before loading it
    Log*                pLog;                       // +0x60
};

}} // namespace Scaleform::GFx

#endif
