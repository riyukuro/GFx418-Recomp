// Recovered Scaleform 4.1.18 GFx: ASIMEManager, the reference-counted IME manager an AS support state creates
// (ASSupport::CreateASIMEManager): the VM side of the IME (candidate list movie, language bar and status window
// contexts). Our own declarations from the exe's field accesses (sfr19); AS3::IMEManager (as3_support.h) is the
// only derived class. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_ASIMEMANAGER_H
#define MS2_SF_GFX_ASIMEMANAGER_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx {

enum { StatIME_Mem = (8 << 6) + 1 };   // StatGroup_GFxIME + 1

class Movie;
class Sprite;
class DisplayObject;
class InteractiveObject;
class TextField;
class IMEManagerBase;

// (sfr19) A host function a GFx::Value can call (Movie::CreateFunction). Reference counted; Call is its slot 1.
class FunctionHandler : public RefCountBase<FunctionHandler, Stat_Default_Mem>
{
public:
    // (sfr33) the call's arguments: the receiver is the first of pArgsWithThis, pArgs the rest (NULL when none).
    struct Params
    {
        Value*      pRetVal;        // +0x00
        Movie*      pMovie;         // +0x08
        Value*      pThis;          // +0x10
        Value*      pArgsWithThis;  // +0x18
        Value*      pArgs;          // +0x20
        unsigned    ArgCount;       // +0x28
        void*       pUserData;      // +0x30
    };
    virtual ~FunctionHandler() {}
    virtual void Call(const Params& params) = 0;
};

// 0xa0 bytes; vftable 0x14317fc38. The base bodies do nothing; AS3::IMEManager overrides them all.
class ASIMEManager : public RefCountBase<ASIMEManager, StatIME_Mem>
{
public:
    // The handler of the functions the IME movies call back (SendIMEMessage, SendLangBarMessage).
    class IMEFuncHandler : public FunctionHandler
    {
    public:
        // (sfr33) made by IMEManagerBase::SetActiveMovie for the candidate list and the language bar.
        IMEFuncHandler(IMEManagerBase* pimeMgr) : pimeManager(pimeMgr) {}
        // Hands the message to the IME manager's ProcessIMEMessage (sfr_gfx_03d).
        virtual void Call(const Params& params);
        IMEManagerBase* pimeManager;
    };

    ASIMEManager() : pMovie(NULL), pLangContext2(NULL), pStatusContext2(NULL), pTextField(NULL) {}
    virtual ~ASIMEManager() {}                                                          // 0

    virtual void ShutDown() {}                                                          // 1
    // The AS3 root sprite of the movie exists: the language bar callback is set on it. (base body in sfr_as3_20)
    virtual void ASRootMovieCreated(Ptr<Sprite> spr);                                   // 2
    virtual void IMECommand(Movie* pmovie, const char* pcommand, const char* pparams) {}  // 3
    virtual void BroadcastIMEConversion(const wchar_t* pstr) {}                         // 4
    // The status window and language bar events (scaleform.gfx.IMEEventEx).
    virtual void BroadcastSwitchLanguage(const char* pstr) {}                           // 5
    virtual void BroadcastSetSupportedLanguages(const char* pstr) {}                    // 6
    virtual void BroadcastSetSupportedIMEs(const char* pstr) {}                         // 7
    virtual void BroadcastSetCurrentInputLanguage(const char* pstr) {}                  // 8
    virtual void BroadcastSetIMEName(const char* pstr) {}                               // 9
    virtual void BroadcastSetConversionStatus(const char* pstr) {}                      // 10
    virtual void BroadcastRemoveStatusWindow(const char* pstr) {}                       // 11
    virtual void BroadcastDisplayStatusWindow(const char* pstr) {}                      // 12
    virtual bool IsCandidateListLoaded() const { return false; }                       // 13
    virtual bool IsTextFieldFocused() const { return false; }                          // 14
    // Calls the candidate list's method at the dotted path pmethodName.
    virtual bool Invoke(const char* pmethodName, GFx::Value* presult, const GFx::Value* pargs, unsigned numArgs)
    {
        return false;
    }                                                                                   // 15
    // The focus moves from poldFocus to pnewFocus (ptopMostItem under the mouse): returns where it goes.
    virtual InteractiveObject* HandleFocus(Movie* pmovie, InteractiveObject* poldFocus, InteractiveObject* pnewFocus,
                                           InteractiveObject* ptopMostItem)
    {
        return NULL;
    }                                                                                   // 16
    virtual void OnOpenCandidateList() {}                                               // 17
    virtual bool AcquireCandidateList() { return false; }                               // 18
    virtual void SetIMEMoviePath(const char* pcandidateSwfPath) {}                      // 19
    virtual void SetActiveMovie(Movie* pmovie) { pMovie = pmovie; }                     // 20
    virtual void SetIMEManager(IMEManagerBase* pimeMgr) { pimeManager = pimeMgr; }      // 21

    String                  CandidateSwfPath;       // +0x10
    String                  CandidateSwfErrorMsg;   // +0x18
    Movie*                  pMovie;                 // +0x20
    GFx::Value              pLangContext;           // +0x28
    DisplayObject*          pLangContext2;          // +0x48 the language bar's display object
    DisplayObject*          pStatusContext2;        // +0x50 the status window's display object
    GFx::Value              pStatusContext;         // +0x58
    Movie*                  pMovieContext;          // +0x78
    TextField*              pTextField;             // +0x80
    Ptr<IMEFuncHandler>     CustomFuncCandList;     // +0x88 SendIMEMessage of the candidate list
    Ptr<IMEFuncHandler>     CustomFuncLanguageBar;  // +0x90 SendLangBarMessage of the root
    IMEManagerBase*         pimeManager;            // +0x98
};

}} // namespace Scaleform::GFx

#endif
