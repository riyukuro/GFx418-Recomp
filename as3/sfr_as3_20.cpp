// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_20
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142542820-0x1425584f0 .text$mn
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_moviedef.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_imemanager.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_net.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_gfx.h"
#undef GetObject

namespace Scaleform { namespace GFx { namespace AS3 {
// Initializes the constant-pool arrays and the any namespace. As in the exe, DoubleCount and ConstDouble stay unset:
// Reader::Read (sfr_as3_21) zeroes and fills them before any GetDouble.
// @0x142545230
// The any namespace (multiname index 0) is the public one with an empty, non-null URI: the exe stores kind 0 and "".
Abc::ConstPool::ConstPool()
    : any_namespace(Abc::NS_Public, "", 0), AnyType{MNF_QName, 0, 0, -1}
{
}

// @0x142543f40
bool IMEManager::GetIMEMoviePath(String& path)
{
    path = "";
    return path.GetSize() != 0;
}
}}}

namespace Scaleform { namespace GFx {

// The host movie interface, as far as the IME manager calls it (Movie is a MovieImpl).
class Movie
{
public:
    // The value at the dotted AS path ppathToVar. 0x1425700a0
    bool GetVariable(Value* pval, const char* ppathToVar) const;
    // A function value calling pfc back. 0x14256e4c0
    void CreateFunction(Value* pfunc, FunctionHandler* pfc, void* puserData = 0);
};

// The base does nothing with the root (exe 0x1425431c0, below the unit's tracked functions).
void ASIMEManager::ASRootMovieCreated(Ptr<Sprite> spr)
{
}

namespace AS3 {

static inline MovieImpl* GetMovieImpl(Movie* pmovie)
{
    return reinterpret_cast<MovieImpl*>(pmovie);
}

static inline MovieRoot* GetAS3Root(Movie* pmovie)
{
    return static_cast<MovieRoot*>(GetMovieImpl(pmovie)->pASMovieRoot);
}

// The focused character of the movie's first focus group.
static inline Ptr<InteractiveObject> GetFocusedChar(Movie* pmovie)
{
    MovieImpl* pmovieImpl = GetMovieImpl(pmovie);
    return pmovieImpl->FocusGroups[pmovieImpl->FocusGroupIndexes[0]].LastFocused;
}

static inline bool IsTextField(DisplayObjectBase* pch)
{
    return pch->GetType() == CharacterDef::TextField;
}

static inline TextField* ToTextField(DisplayObjectBase* pch)
{
    return reinterpret_cast<TextField*>(pch);
}

// Calls the IME manager's InitEventCallback when the candidate list movie has loaded: the movie goes on the stage
// and gets its SendIMEMessage callback. 0x28 bytes; vftable 0x14317fdf0.
class NotifyLoadInitCandidateList : public NotifyLoadInitC
{
public:
    NotifyLoadInitCandidateList(MovieRoot* proot, Instances::fl_display::Loader* ploader, IMEManager* pimeManager)
        : pMovieRoot(proot), pLoader(ploader), pIMEManager(pimeManager) {}
    // The destructor is implicit: 0x1425430b0, the scalar deleting destructor (pinned at the end of the file), has
    // no vftable store of its own.

    // @0x142545160
    virtual void OpenEventCallback() {}
    virtual void InitEventCallback();
    // @0x142543e60
    virtual void ErrorEventCallback() {}
    // @0x142545040
    virtual void LoadEventCallback() {}

    MovieRoot*                              pMovieRoot;     // +0x10
    SPtr<Instances::fl_display::Loader>     pLoader;        // +0x18
    Ptr<IMEManager>                         pIMEManager;    // +0x20
};

// MS2-FUNCTIONAL: register allocation and local order (the exe keeps two unused host values)
// @0x1425445d0
void NotifyLoadInitCandidateList::InitEventCallback()
{
    if (!pMovieRoot)
        return;
    GFx::Value unused1, unused2;
    Value loaderInfo, content;
    Multiname loaderInfoName(pMovieRoot->pAVM->GetPublicNamespace(),
                             Value(pMovieRoot->BuiltinsMgr.CreateString("contentLoaderInfo")));
    if (!pLoader->GetProperty(loaderInfoName, loaderInfo) || !pIMEManager->CandListVal.IsNull())
        return;
    Multiname contentName(pMovieRoot->pAVM->GetPublicNamespace(),
                          Value(pMovieRoot->BuiltinsMgr.CreateString("content")));
    if (!loaderInfo.GetObject()->GetProperty(contentName, content))
        return;
    pMovieRoot->ASValue2GFxValue(content, &pIMEManager->CandListVal);
    if (pIMEManager->CandListVal.IsNull())
        return;

    GFx::Value func;
    pIMEManager->pMovie->CreateFunction(&func, pIMEManager->CustomFuncCandList);
    pIMEManager->CandListVal.SetMember("SendIMEMessage", func);
    pIMEManager->CandidateListState = 2;
    GFx::DisplayObject* pstage = pMovieRoot->pStage;
    AvmDisplayObjContainer* pstageAvm = pstage
        ? AvmDisplayObjContainer::FromBase(pstage->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL;
    pstageAvm->AddChild(pLoader->pDispObj);
    pIMEManager->OnOpenCandidateList();
    pIMEManager->CandListVal.Invoke("Init", NULL, NULL, 0);
}

// @0x142542bd0
IMEManager::IMEManager()
{
    UnsupportedIMEWindowsFlag = 3;
    pTextField = 0;
    pMovie = 0;
    CandidateListState = 0;
    CandListVal.SetNull();
}

// @0x142542da0
IMEManager::~IMEManager()
{
}

// @0x1425451f0
void IMEManager::ShutDown()
{
    CandListVal.SetUndefined();
}

// The root sprite gets the SendLangBarMessage callback.
// @0x1425431d0
void IMEManager::ASRootMovieCreated(Ptr<Sprite> spr)
{
    if (!pMovie)
        return;
    GFx::Value func;
    Value asFunc;
    MovieRoot* proot = GetAS3Root(pMovie);
    ASVM* pvm = proot->pAVM;
    pMovie->CreateFunction(&func, CustomFuncLanguageBar);
    proot->GFxValue2ASValue(func, &asFunc);
    AvmDisplayObj* pavm = ToAvmDisplayObj(reinterpret_cast<DisplayObjectBase*>(spr.GetPtr()));
    if (pavm)
    {
        Multiname name(proot->pAVM->GetPublicNamespace(), proot->BuiltinsMgr.CreateString("SendLangBarMessage"));
        if (pavm->GetAS3Obj())
        {
            if (!pavm->GetAS3Obj()->SetProperty(name, asFunc))
            {
                if (pvm->IsException())
                {
                    // VM::OutputAndIgnoreException, inline in the SDK header
                    pvm->HandleException = false;
                    pvm->OutputError(pvm->ExceptionObj);
                    pvm->ExceptionObj.SetUndefined();
                }
            }
        }
    }
}

void IMEManager::IMECommand(Movie* pmovie, const char* pcommand, const char* pparams)
{
}

void IMEManager::BroadcastIMEConversion(const wchar_t* pstr)
{
}

void IMEManager::BroadcastSwitchLanguage(const char* pstr)
{
    DispatchEvent(pstr, "SetCurrentLanguage", "StatusWindow");
}

void IMEManager::BroadcastSetSupportedLanguages(const char* pstr)
{
    DispatchEvent(pstr, "SetSupportedLanguages", "LangBar");
}

void IMEManager::BroadcastSetSupportedIMEs(const char* pstr)
{
    DispatchEvent(pstr, "SetSupportedIMENames", "LangBar");
}

void IMEManager::BroadcastSetCurrentInputLanguage(const char* pstr)
{
    DispatchEvent(pstr, "SetCurrentInputLanguage", "LangBar");
}

void IMEManager::BroadcastSetIMEName(const char* pstr)
{
    DispatchEvent(pstr, "SetIMEName", "LangBar");
}

void IMEManager::BroadcastSetConversionStatus(const char* pstr)
{
    DispatchEvent(pstr, "SetConversionStatus", "StatusWindow");
}

void IMEManager::BroadcastRemoveStatusWindow(const char* pstr)
{
    DispatchEvent(pstr, "RemoveStatusWindow", "StatusWindow");
}

void IMEManager::BroadcastDisplayStatusWindow(const char* pstr)
{
    DispatchEvent(pstr, "DisplayStatusWindow", "StatusWindow");
}

// Sends an IMEEventEx of type messageType carrying message to the language bar or the status window.
// @0x142543b80
void IMEManager::DispatchEvent(const char* message, const char* messageType, const char* type)
{
    if (!pMovie)
        return;
    ArrayLH<Value> unusedArgs;
    MovieRoot* proot = GetAS3Root(pMovie);
    {
        AvmDisplayObj* pctx = NULL;
        Value unused;
        if (pLangContext2 && strcmp(type, "LangBar") == 0)
            pctx = ToAvmDisplayObj(pLangContext2);
        else if (pStatusContext2 && strcmp(type, "StatusWindow") == 0)
            pctx = ToAvmDisplayObj(pStatusContext2);
        if (proot && pctx)
        {
            Instances::fl_display::DisplayObject* pdispatcher = pctx->GetAS3Obj();
            const ASString& evtType = proot->BuiltinsMgr.CreateString(messageType);
            if (pdispatcher->HasEventHandler(evtType, false))
            {
                SPtr<Instances::fl_gfx::IMEEventEx> pevt;
                Value args[3] = { Value(evtType), Value(true), Value(true) };
                ASVM* pvm = proot->pAVM;
                pvm->ConstructInstance(pevt, pvm->GetClass(StringDataPtr("scaleform.gfx.IMEEventEx")), 3, args);
                pevt->Target = pdispatcher;
                pevt->message = message;
                pdispatcher->DispatchEventObject(pevt, pdispatcher->pDispObj);
            }
        }
    }
}

// @0x142543e70
DisplayObject* IMEManager::GetCandidateListSprite() const
{
    if (CandListVal.IsNull() || !pMovie)
        return NULL;

    MovieRoot* pmovieRoot = GetAS3Root(pMovie);
    Value pdestVal;
    pmovieRoot->GFxValue2ASValue(CandListVal, &pdestVal);
    if (pdestVal.IsObject())
    {
        const Traits& tr = pdestVal.GetObject()->GetTraits();
        if (!((unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
                (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
            tr.IsInstanceTraits()))
            return 0;
        DisplayObject* parentDispObj = static_cast<Instances::fl_display::DisplayObject*>(pdestVal.GetObject())->pDispObj;
        return parentDispObj;
    }
    return NULL;
}

// The candidate list movie has set _global.gfx_ime_candidate_list_state.
// @0x142544cf0
bool IMEManager::IsCandidateListLoaded() const
{
    if (pMovie)
    {
        GFx::Value v;
        if (!pMovie->GetVariable(&v, "_global.gfx_ime_candidate_list_state"))
            v.SetNumber(0);
        return true;
    }
    return false;
}

// @0x142544e10
bool IMEManager::IsTextFieldFocused(InteractiveObject* pfocusedChar) const
{
    if (pMovie)
    {
        Ptr<InteractiveObject> pfocused = GetFocusedChar(pMovie);
        return (pfocused && IsTextField(pfocused) && ToTextField(pfocused)->IsIMEEnabled() &&
                pfocused == pfocusedChar);
    }
    return false;
}

// @0x142544ef0
bool IMEManager::IsTextFieldFocused() const
{
    if (pMovie)
    {
        Ptr<InteractiveObject> pfocused = GetFocusedChar(pMovie);
        return IsTextFieldFocused(pfocused);
    }
    return false;
}

// Calls the candidate list's method at the dotted path pmethodName (the object path walked member by member).
// MS2-FUNCTIONAL: register allocation and local order
// @0x142544a00
bool IMEManager::Invoke(const char* pmethodName, GFx::Value* presult, const GFx::Value* pargs, unsigned numArgs)
{
    if (CandListVal.IsUndefined() || CandListVal.IsNull())
        return false;
    int len = (int)strlen(pmethodName);
    char* pbuf = (char*)SF_ALLOC(len + 1, StatIME_Mem);
    char* pcontext = NULL;
    memcpy(pbuf, pmethodName, len);
    pbuf[len] = 0;
    char* ptoken = strtok_s(pbuf, ".", &pcontext);
    GFx::Value obj = CandListVal;
    GFx::Value member = CandListVal;
    char* pname = NULL;
    while (!obj.IsNull() && ptoken)
    {
        obj = member;
        obj.GetMember(ptoken, &member);
        pname = ptoken;
        ptoken = strtok_s(NULL, ".", &pcontext);
    }
    if (!obj.IsNull())
        obj.Invoke(pname, presult, pargs, numArgs);
    SF_FREE(pbuf);
    return false;
}

// Clicks on the IME movies keep the focus where it is; a text field taking the focus gives the candidate list
// its font, and the IME follows whether the new focus takes IME input.
// MS2-FUNCTIONAL: register allocation and the order of the name/multiname temporaries
// @0x142543f90
InteractiveObject* IMEManager::HandleFocus(Movie* pmovie, InteractiveObject* poldFocus, InteractiveObject* pnewFocus,
                                           InteractiveObject* ptopMostItem)
{
    IMEManagerBase* pime = pimeManager;
    if (!pime || !pime->IsMovieActive(pmovie))
        return pnewFocus;
    if (ptopMostItem)
    {
        String path;
        ptopMostItem->GetAbsolutePath(&path);
        if (IsCandidateList(path.ToCStr()))
            return poldFocus;
        Value unused;
        for (InteractiveObject* pch = ptopMostItem; pch; pch = pch->GetParent())
        {
            if (!pch->IsSprite())
                continue;
            AvmDisplayObj* pavm = ToAvmDisplayObj(pch);
            Instances::fl_display::DisplayObject* pobj = pavm->GetAS3Obj();
            Value result;
            if (!pobj)
                continue;
            if (pobj->GetProperty(Multiname(pavm->GetAVM()->GetPublicNamespace(),
                                            Value(pavm->GetAS3Root()->BuiltinsMgr.CreateString("IsCandidateList"))),
                                  result) ||
                pobj->GetProperty(Multiname(pavm->GetAVM()->GetPublicNamespace(),
                                            Value(pavm->GetAS3Root()->BuiltinsMgr.CreateString("IsStatusWindow"))),
                                  result) ||
                pobj->GetProperty(Multiname(pavm->GetAVM()->GetPublicNamespace(),
                                            Value(pavm->GetAS3Root()->BuiltinsMgr.CreateString("IsLangBar"))),
                                  result))
                return poldFocus;
        }
    }
    if (pnewFocus && IsTextField(pnewFocus))
    {
        if (DisplayObject* plist = GetCandidateListSprite())
            ToTextField(pnewFocus)->SetCandidateListFont(plist);
    }
    if (poldFocus && IsTextField(poldFocus))
        pime->DoFinalize();
    pime->EnableIME(pnewFocus && IsTextField(pnewFocus) && ToTextField(pnewFocus)->IsIMEEnabled());
    return pnewFocus;
}

// @0x142545060
void IMEManager::OnOpenCandidateList()
{
    if (!pMovie)
        return;
    TextField* ptextField = pTextField;
    if (!ptextField)
    {
        Ptr<InteractiveObject> pfocused = GetFocusedChar(pMovie);
        if (pfocused && IsTextField(pfocused))
        {
            ptextField = ToTextField(pfocused);
        }
        if (!ptextField)
            return;
    }

    DisplayObject* plist = GetCandidateListSprite();
    if (plist)
        ptextField->SetCandidateListFont(plist);
}

// Starts loading the candidate list movie (CandidateSwfPath, next to the main movie): a Loader and its request go
// through the load queue, and NotifyLoadInitCandidateList finishes once it is in. With bCheckIMEExists the file
// must exist first.
// MS2-FUNCTIONAL: register allocation, the state/URL temporaries and the notify object's reference handling
// @0x142543440
bool IMEManager::AcquireCandidateList()
{
    if (!pMovie)
        return false;
    MovieRoot* proot = GetAS3Root(pMovie);
    Value loaderVal, requestVal, unused;
    if (CandidateListState != 0)
        return true;
    if (pimeManager && pimeManager->bCheckIMEExists)
    {
        Ptr<FileOpenerBase> pfileOpener =
            *static_cast<FileOpenerBase*>(pimeManager->pLoader->GetStateAddRef(State::State_FileOpener));
        Ptr<URLBuilder> purlBuilder =
            *static_cast<URLBuilder*>(pimeManager->pLoader->GetStateAddRef(State::State_URLBuilder));
        if (!purlBuilder)
            purlBuilder = *SF_NEW URLBuilder();
        if (pfileOpener)
        {
            String path;
            path = GetMovieImpl(pMovie)->AsMovieInterface()->GetMovieDef()->GetFileURL();
            URLBuilder::ExtractFilePath(&path);
            if (URLBuilder::IsPathAbsolute(path.ToCStr()))
            {
                URLBuilder::LocationInfo loc(URLBuilder::File_Regular, CandidateSwfPath, path);
                String url;
                if (purlBuilder)
                    purlBuilder->BuildURL(&url, loc);
                else
                    URLBuilder::DefaultBuildURL(&url, loc);
                if (pfileOpener->GetFileModifyTime(url.ToCStr()) == -1)
                    return false;
            }
        }
    }
    CandidateListState = 1;
    ASVM* pvm = proot->pAVM;
    pvm->Construct("flash.display.Loader", loaderVal, 0, NULL, true);
    if (pvm->IsException() || loaderVal.IsUndefined() || (loaderVal.IsObject() && !loaderVal.GetObject()))
        return false;
    pvm->Construct("flash.net.URLRequest", requestVal, 0, NULL, true);
    if (pvm->IsException() || requestVal.IsUndefined() || (requestVal.IsObject() && !requestVal.GetObject()))
        return false;
    Instances::fl_display::Loader* ploader = static_cast<Instances::fl_display::Loader*>(loaderVal.GetObject());
    Instances::fl_net::URLRequest* prequest = static_cast<Instances::fl_net::URLRequest*>(requestVal.GetObject());
    ploader->InitInstance(false);
    prequest->urlSet(unused, proot->BuiltinsMgr.CreateString(CandidateSwfPath));
    LoadQueueEntry* pentry = SF_HEAP_NEW(proot->GetMovieImpl()->GetMovieHeap())
        LoadQueueEntry(prequest, ploader, GFx::LoadQueueEntry::LM_None);
    Ptr<NotifyLoadInitC> pnotify = *SF_NEW NotifyLoadInitCandidateList(proot, ploader, this);
    pentry->NotifyLoadInitCInterface = pnotify;
    proot->GetMovieImpl()->AddLoadQueueEntry(pentry);
    return true;
}

// @0x1425451d0
void IMEManager::SetIMEMoviePath(const char* pcandidateSwfPath)
{
    CandidateSwfPath = pcandidateSwfPath;
}

void IMEManager::SetActiveMovie(Movie* pmovie)
{
    pMovie = pmovie;
}

void IMEManager::SetIMEManager(IMEManagerBase* pimeMgr)
{
    pimeManager = pimeMgr;
}

bool IMEManager::Init(Log* plog)
{
    return true;
}

bool IMEManager::SetCompositionString(const char* pcompString)
{
    return false;
}

bool IMEManager::IsCandidateList(const char* ppath)
{
    return false;
}

bool IMEManager::IsStatusWindow(const char* ppath)
{
    return false;
}

bool IMEManager::IsLangBar(const char* ppath)
{
    return false;
}

void IMEManager::OnShutdown()
{
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// The class object's string form uses the VM's canonical name for its traits.
// MS2-FUNCTIONAL: the executable builds the same value through a lower-level string-node path.
// @0x142542a60
void ClassToString(Object* pobj, ASString* presult)
{
    *presult = pobj->GetVM().GetStringManager().CreateConstString("[class ") + pobj->GetTraits().GetName() + "]";
}
}}}

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142546850: Instances::fl_vec::Vector_double::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 0, UInt32>;
// thunk 0x1425468b0: Instances::fl_vec::Vector_double::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 1, const Value, UInt32>;
// thunk 0x142546920: Instances::fl_vec::Vector_double::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 2, const Value, bool>;
// thunk 0x142546980: Instances::fl_vec::Vector_double::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 3, bool>;
// thunk 0x1425469e0: Instances::fl_vec::Vector_double::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 4, ASString>;
// thunk 0x142546a50: Instances::fl_vec::Vector_String::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 0, UInt32>;
// thunk 0x142546ab0: Instances::fl_vec::Vector_String::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 1, const Value, UInt32>;
// thunk 0x142546b20: Instances::fl_vec::Vector_String::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 2, const Value, bool>;
// thunk 0x142546b80: Instances::fl_vec::Vector_String::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 3, bool>;
// thunk 0x142546be0: Instances::fl_vec::Vector_String::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 4, ASString>;
// thunk 0x142547220: Instances::fl_vec::Vector_object::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 0, UInt32>;
// thunk 0x142547280: Instances::fl_vec::Vector_object::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 1, const Value, UInt32>;
// thunk 0x1425472f0: Instances::fl_vec::Vector_object::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 2, const Value, bool>;
// thunk 0x142547350: Instances::fl_vec::Vector_object::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 3, bool>;
// thunk 0x1425473b0: Instances::fl_vec::Vector_object::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 4, ASString>;
// thunk 0x142547560: Instances::fl_vec::Vector_int::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 0, UInt32>;
// thunk 0x1425475c0: Instances::fl_vec::Vector_int::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 1, const Value, UInt32>;
// thunk 0x142547630: Instances::fl_vec::Vector_int::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 2, const Value, bool>;
// thunk 0x142547690: Instances::fl_vec::Vector_int::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 3, bool>;
// thunk 0x1425476f0: Instances::fl_vec::Vector_int::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 4, ASString>;
// thunk 0x142547760: Instances::fl_vec::Vector_uint::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 0, UInt32>;
// thunk 0x1425477c0: Instances::fl_vec::Vector_uint::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 1, const Value, UInt32>;
// thunk 0x142547830: Instances::fl_vec::Vector_uint::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 2, const Value, bool>;
// thunk 0x142547890: Instances::fl_vec::Vector_uint::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 3, bool>;
// thunk 0x1425478f0: Instances::fl_vec::Vector_uint::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 4, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

namespace Scaleform { namespace GFx { namespace AS3 { namespace Abc {

// @0x1425452c0
double ConstPool::GetDouble(UPInt ind) const
{
    if (ind != 0)
    {
        const UInt8* p = ConstDouble + (ind - 1) * sizeof(double);
        return ReadDouble(p);
    }
    return 0.0;
}

// @0x1425452f0
UPInt NamespaceSetInfo::GetSize() const
{
    const UInt8* p = Data;
    return static_cast<UInt32>(ReadU30(p));
}

template <typename T>
UInt8 ReadU8(const T*& p)
{
    return *p++;
}

template <typename T>
UInt8 ReadU8(const T* data, UPInt& pos)
{
    return data[pos++];
}

// noinline: the exe reads ABC data through out-of-line calls (GetSize, GetDouble and the parser).
template <typename T>
SF_NOINLINE int ReadU30(const T*& p)
{
    UInt32 shift = 0;
    UInt32 s = 0;
    int nr = 0;

    while (true)
    {
        UInt8 b = ReadU8(p);
        ++nr;
        s |= (b & 127) << shift;
        shift += 7;

        if (!(b & 128) || shift >= 32)
            break;
    }

    return s;
}

template <typename T>
SF_NOINLINE int ReadU30(const T* data, UPInt& pos)
{
    UInt32 shift = 0;
    UInt32 s = 0;
    int nr = 0;

    while (true)
    {
        UInt8 b = ReadU8(data, pos);
        ++nr;
        s |= (b & 127) << shift;
        shift += 7;

        if (!(b & 128) || shift >= 32)
            break;
    }

    return s;
}

template <typename T>
SF_NOINLINE int ReadS24(const T* data, UPInt& pos)
{
    UInt32 b0 = data[pos];
    UInt32 b1 = data[pos + 1];
    UInt32 b2 = data[pos + 2];
    pos += 3;
    int result = ((b2 << 8 | b1) << 8) | b0;
    if (b2 & 0x80)
        result = ~(result ^ 0xffffff);
    return result;
}

// Assembled byte by byte: the ABC data is little endian and need not be aligned.
template <typename T>
SF_NOINLINE double ReadDouble(const T*& p)
{
    union { UInt32 u[2]; double d; } v;
    v.u[0] = ((((UInt32)p[3] << 8 | p[2]) << 8 | p[1]) << 8) | p[0];
    v.u[1] = ((((UInt32)p[7] << 8 | p[6]) << 8 | p[5]) << 8) | p[4];
    p += 8;
    return v.d;
}

template <typename T>
String ReadString(const T*& p, UPInt size)
{
    String result(reinterpret_cast<const char*>(p), size);
    p += size;
    return result;
}

template <typename T>
String ReadString(const T* data, UPInt& pos, UPInt size)
{
    String result(reinterpret_cast<const char*>(data + pos), size);
    pos += size;
    return result;
}

// The instances for byte data (pinned below).
template int    ReadU30<UInt8>(const UInt8*& p);
template int    ReadU30<UInt8>(const UInt8* data, UPInt& pos);
template int    ReadS24<UInt8>(const UInt8* data, UPInt& pos);
template double ReadDouble<UInt8>(const UInt8*& p);
template String ReadString<UInt8>(const UInt8*& p, UPInt size);
template String ReadString<UInt8>(const UInt8* data, UPInt& pos, UPInt size);

template <typename T>
SF_NOINLINE int Read16(const T*& p)
{
    const int hi = p[1];
    const int lo = p[0];
    p += 2;
    return hi << 8 | lo;
}

// The bytes of a pool string, without copying them.
template <typename T>
SF_NOINLINE StringDataPtr ReadStringPtr(const T*& p, UPInt size)
{
    StringDataPtr result(reinterpret_cast<const char*>(p), size);
    p += size;
    return result;
}

template int           Read16<UInt8>(const UInt8*& p);
template StringDataPtr ReadStringPtr<UInt8>(const UInt8*& p, UPInt size);

// @0x142545310
StringDataPtr StringView::ToStringDataPtr() const
{
    const UInt8* p = Data;
    const int size = ReadU30(p);
    return ReadStringPtr(p, size);
}

// @0x142545670
MethodBodyInfo::ExceptionInfo::ExceptionInfo()
    : from(0), to(0), target(0), exc_type_ind(0), var_name_ind(0)
{
}

// @0x142545650
MethodBodyInfo::ExceptionInfo::ExceptionInfo(SInd from, SInd to, SInd target, SInd exc_type_ind, SInd var_name_ind)
    : from(from), to(to), target(target), exc_type_ind(exc_type_ind), var_name_ind(var_name_ind)
{
}

// @0x142545680
MethodBodyInfo::MethodBodyInfo()
    : method_info_ind(-1), max_stack(-1), local_reg_count(-1), init_scope_depth(-1), max_scope_depth(-1)
{
}

// @0x142545a80
MethodBodyInfo::~MethodBodyInfo()
{
}

// @0x142545ac0
MethodBodyTable::~MethodBodyTable()
{
    const UPInt size = Info.GetSize();
    for (UPInt i = 0; i < size; ++i)
        delete Info[i];
}

// @0x1425456e0
File::~File()
{
}

// @0x142545bc0
void ConstPool::Clear()
{
    ConstInt.Clear();
    ConstUInt.Clear();
    ConstStr.Clear();
    ConstNamespace.Clear();
    const_ns_set.Clear();
    const_multiname.Clear();
}

// @0x142545dd0
void File::Clear()
{
    MinorVersion = 0;
    MajorVersion = 0;
    Const_Pool.Clear();
    Methods.Info.Clear();
    Metadata.Info.Clear();
    Traits.TraitInfos.Clear();
    AS3_Classes.Info.Clear();
    Scripts.Info.Clear();
    MethodBodies.Info.Clear();
}

// @0x142545ff0
bool MethodBodyInfo::Exception::FindExceptionInfo(UPInt offset, UPInt& from) const
{
    const UPInt size = info.GetSize();
    for (; from < size; ++from)
    {
        const ExceptionInfo& e = info[from];
        if (offset >= static_cast<UInt32>(e.from) && offset <= static_cast<UInt32>(e.to))
            return true;
    }
    return false;
}

// @0x142546050
const Multiname& TraitInfo::GetName(const ConstPool& cp) const
{
    if (name_ind == 0)
        return cp.AnyType;
    return cp.GetMultiname(name_ind);
}

// @0x142546080
bool IsValidValueKind(UInt8 vk)
{
    // Undefined, Utf8, Int, UInt, PrivateNs, Double, Namespace, False, True, Null and the four namespace kinds.
    switch (vk)
    {
    case 0x00: case 0x01: case 0x03: case 0x04: case 0x05: case 0x06: case 0x08: case 0x0a: case 0x0b: case 0x0c:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        return true;
    default:
        break;
    }
    return false;
}

}}}} // namespace Scaleform::GFx::AS3::Abc

// ---------------------------------------------------------------- Vector.<T> natives

// VectorBase<T>::Concat/Filter/Map member templates (this unit, below the natives)
void FUN_142547960(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142547c40(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142547f30(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_142548280(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142548580(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);
void FUN_142548bd0(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142548f60(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142549300(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_1425496a0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142549a60(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);
void FUN_14254c050(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_14254c4e0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_14254c980(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_14254ce20(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_14254d380(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);

// Traits::GetConstructor, out of line in the exe.
const Scaleform::GFx::AS3::Class& FUN_142508490(const Scaleform::GFx::AS3::Traits* tr);

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// The element type of a Vector.<T> of objects: ClassTraits::fl_vec::Vector_object keeps it at +0xc8.
static const ClassTraits::Traits& GetEnclosedClassTraits(const Vector_object& v)
{
    const ClassTraits::Traits& ctr = FUN_142508490(&v.GetTraits()).GetClassTraits();
    return **reinterpret_cast<ClassTraits::Traits* const*>(reinterpret_cast<const char*>(&ctr) + 0xc8);
}

// ---- AS3Constructor: (length = 0, fixed = false)

// The exe inlines VectorBase<SInt32/UInt32>::Resize (sfr_as3_21) into those two constructors; this is the
// same body. The String and double constructors call Resize out of line.
template <typename T>
inline CheckResult ResizeInline(VectorBase<T>& v, UPInt size)
{
    bool ok = false;
    if (v.CheckFixed())
    {
        UPInt i = v.V.GetSize();
        v.V.Resize(size);
        for (; i < size; ++i)
            v.V[i] = 0;
        ok = true;
    }
    return ok;
}

// @0x142557110
void Vector_String::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x142557180
void Vector_double::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x1425571f0
void Vector_int::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!ResizeInline(V, length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x1425572c0
void Vector_object::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x142557330
void Vector_uint::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!ResizeInline(V, length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// ---- concat

// @0x142557400
void Vector_String::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547960(V, result, argc, argv, *this);
}

// @0x142557420
void Vector_double::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547c40(V, result, argc, argv, *this);
}

// @0x142557440
void Vector_int::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547f30(V, result, argc, argv, *this);
}

// @0x142557460
void Vector_object::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142548280(V, result, argc, argv, *this);
}

// @0x142557480
void Vector_uint::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142548580(V, result, argc, argv, *this);
}

// ---- every

// @0x1425574a0
void Vector_String::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x1425574d0
void Vector_double::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557500
void Vector_int::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557530
void Vector_object::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557560
void Vector_uint::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// ---- filter

// @0x142557590
void Vector_String::AS3filter(SPtr<Vector_String>& result, const Value& callback, const Value& thisObject)
{
    FUN_142548bd0(V, result, callback, thisObject, *this);
}

// @0x1425575b0
void Vector_double::AS3filter(SPtr<Vector_double>& result, const Value& callback, const Value& thisObject)
{
    FUN_142548f60(V, result, callback, thisObject, *this);
}

// @0x1425575d0
void Vector_int::AS3filter(SPtr<Vector_int>& result, const Value& callback, const Value& thisObject)
{
    FUN_142549300(V, result, callback, thisObject, *this);
}

// @0x1425575f0
void Vector_object::AS3filter(SPtr<Vector_object>& result, const Value& callback, const Value& thisObject)
{
    FUN_1425496a0(V, result, callback, thisObject, *this);
}

// @0x142557610
void Vector_uint::AS3filter(SPtr<Vector_uint>& result, const Value& callback, const Value& thisObject)
{
    FUN_142549a60(V, result, callback, thisObject, *this);
}

// ---- forEach

// @0x142557630
void Vector_String::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557650
void Vector_double::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557670
void Vector_int::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557690
void Vector_object::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x1425576b0
void Vector_uint::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// ---- indexOf / lastIndexOf (a negative fromIndex counts from the end)

// @0x1425576d0
void Vector_String::AS3indexOf(SInt32& result, const ASString& searchElement, SInt32 fromIndex)
{
    const Ptr<ASStringNode> node = searchElement.GetNode();
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (UPInt i = fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (V.V[i] == node)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557740
void Vector_double::AS3indexOf(SInt32& result, Value::Number searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (UPInt i = fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557790
void Vector_int::AS3indexOf(SInt32& result, SInt32 searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (UPInt i = fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x1425577d0
void Vector_object::AS3indexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
{
    for (UPInt i = (UPInt)(SPInt)fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (StrictEqual(V.V[i], searchElement))
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557860
void Vector_uint::AS3indexOf(SInt32& result, UInt32 searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (UPInt i = fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557a30
void Vector_String::AS3lastIndexOf(SInt32& result, const ASString& searchElement, SInt32 fromIndex)
{
    const Ptr<ASStringNode> node = searchElement.GetNode();
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (V.V[i] == node)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557aa0
void Vector_double::AS3lastIndexOf(SInt32& result, Value::Number searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557b00
void Vector_int::AS3lastIndexOf(SInt32& result, SInt32 searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557b50
void Vector_object::AS3lastIndexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
{
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (StrictEqual(V.V[i], searchElement))
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557be0
void Vector_uint::AS3lastIndexOf(SInt32& result, UInt32 searchElement, SInt32 fromIndex)
{
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (V.V[i] == searchElement)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// ---- join

// @0x1425578a0
void Vector_String::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x1425578f0
void Vector_double::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x142557940
void Vector_int::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x142557990
void Vector_object::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x1425579e0
void Vector_uint::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// ---- map

// @0x142557c30
void Vector_String::AS3map(SPtr<Vector_String>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c050(V, result, callback, thisObject, *this);
}

// @0x142557c50
void Vector_double::AS3map(SPtr<Vector_double>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c4e0(V, result, callback, thisObject, *this);
}

// @0x142557c70
void Vector_int::AS3map(SPtr<Vector_int>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c980(V, result, callback, thisObject, *this);
}

// @0x142557c90
void Vector_object::AS3map(SPtr<Vector_object>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254ce20(V, result, callback, thisObject, *this);
}

// @0x142557cb0
void Vector_uint::AS3map(SPtr<Vector_uint>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254d380(V, result, callback, thisObject, *this);
}

// ---- pop: RangeError on a fixed vector; nothing on an empty one

// @0x142557cd0
void Vector_String::AS3pop(ASString& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
    {
        Ptr<ASStringNode> node = V.V.Pop();
        if (node)
            result.AssignNode(node.GetPtr());
        else
            result.AssignNode(result.GetManager()->GetNullStringNode());
    }
}

// @0x142557e00
void Vector_double::AS3pop(Value::Number& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// @0x142557ea0
void Vector_int::AS3pop(SInt32& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// @0x142557f30
void Vector_object::AS3pop(Value& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result.Assign(V.V.Pop());
}

// @0x142558090
void Vector_uint::AS3pop(UInt32& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// ---- push: argv coerced to the element type; the new length is returned

// @0x142558120
void Vector_String::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsString());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x1425581a0
void Vector_double::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsNumber());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558220
void Vector_int::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsSInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x1425582a0
void Vector_object::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetEnclosedClassTraits(*this));
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558340
void Vector_uint::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsUInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// ---- reverse

// Same helper as sfr_as3_21's: Alg::Swap, and the result assigned from a pointer argument.
template <typename A, typename C>
inline void ReverseT(A& v, SPtr<C>& result, C* obj)
{
    for (SPInt i = 0, j = (SPInt)v.GetSize() - 1; i < j; ++i, --j)
        Alg::Swap(v[i], v[j]);
    result = obj;
}

// @0x1425583c0
void Vector_String::AS3reverse(SPtr<Vector_String>& result)
{
    ReverseT(V.V, result, this);
}

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

// VectorBase<T>::Concat/Filter/Map<I>: one body per element type, written once below and forced inline into each.
// VM::GetValueTraits / VM::GetClassTraits(const Value&) / ClassTraits::Traits::IsParentTypeOf
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other);

namespace Scaleform {
// A sort key and the index of the element it came from.
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};
namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec { struct CompareAsStringInd; } } } }
}

// Vector.sort helpers the exe keeps out of line (sfr_as3_21): CompareAsStringInd::Compare, Impl::CompareFunct
// (calls the AS3 compare function, its result as an int) and ArrayDH<Pair<ASString,UInt32> >::PushBack.
namespace Scaleform { namespace GFx { namespace AS3 { namespace Impl {
int CompareFunct(VM& vm, const Value& funct, const Value& a, const Value& b);
}}}}
namespace Scaleform {
template<> SF_NOINLINE void ArrayBase<ArrayDataDH<Pair<GFx::ASString, UInt32>, AllocatorDH<Pair<GFx::ASString, UInt32>, 2>,
    ArrayDefaultPolicy> >::PushBack(const Pair<GFx::ASString, UInt32>& val);
}

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// the element as a callback argument
static SF_INLINE Value ElementValue(const Ptr<ASStringNode>& e)     { return Value(e.GetPtr()); }
static SF_INLINE Value ElementValue(Value::Number e)                { return Value(e); }
static SF_INLINE Value ElementValue(SInt32 e)                       { return Value(e); }
static SF_INLINE Value ElementValue(const Value& e)                 { return e; }
static SF_INLINE Value ElementValue(UInt32 e)                       { return Value(e); }

// an element pushed into the result instance
static SF_INLINE void PushElement(Vector_String& r, const Ptr<ASStringNode>& e)    { r.PushBack(e.GetPtr()); }
static SF_INLINE void PushElement(Vector_double& r, Value::Number e)                { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_int& r, SInt32 e)                         { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_object& r, const Value& e)                { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_uint& r, UInt32 e)                        { r.PushBack(e); }

// a coerced Value pushed into the result instance
static SF_INLINE void PushCoerced(Vector_String& r, const Value& v)    { r.PushBack(v.AsStringNode()); }
static SF_INLINE void PushCoerced(Vector_double& r, const Value& v)    { r.PushBack(v.AsNumber()); }
static SF_INLINE void PushCoerced(Vector_int& r, const Value& v)       { r.PushBack(v.AsInt()); }
static SF_INLINE void PushCoerced(Vector_object& r, const Value& v)    { r.PushBack(v); }
static SF_INLINE void PushCoerced(Vector_uint& r, const Value& v)      { r.PushBack(v.AsUInt()); }

// a concat() argument of the element type, appended in place
static SF_INLINE void ConcatPush(Vector_String& r, const Value& v)
{
    const Ptr<ASStringNode> s(v.GetStringNode());
    if (r.V.CheckFixed())
        r.V.V.PushBack(s);
}
static SF_INLINE void ConcatPush(Vector_double& r, const Value& v)  { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsNumber()); }
static SF_INLINE void ConcatPush(Vector_int& r, const Value& v)     { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsInt()); }
static SF_INLINE void ConcatPush(Vector_object& r, const Value& v)  { if (r.V.CheckFixed()) r.V.V.PushBack(v); }
static SF_INLINE void ConcatPush(Vector_uint& r, const Value& v)    { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsUInt()); }

static SF_INLINE void Append(Vector_String& r, const Vector_String& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_double& r, const Vector_double& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_int& r, const Vector_int& o)        { r.Append(o); }
static SF_INLINE void Append(Vector_object& r, const Vector_object& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_uint& r, const Vector_uint& o)      { r.Append(o); }

// the ClassTraits map() coerces the callback results to
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_String& o)  { return o.GetVM().GetClassTraitsString(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_double& o)  { return o.GetVM().GetClassTraitsNumber(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_int& o)     { return o.GetVM().GetClassTraitsSInt(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_object& o)  { return GetEnclosedClassTraits(o); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_uint& o)    { return o.GetVM().GetClassTraitsUInt(); }

template <class I, class TR, typename T>
static __forceinline void VectorConcat(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    VM& vm = self.VMRef;
    const ClassTraits::Traits& currClassTR = FUN_142508490(&owner.GetTraits()).GetClassTraits();
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    Append(r, owner);

    for (unsigned i = 0; i < argc; ++i)
    {
        const Value& value = argv[i];
        const Traits& argTraits = FUN_14250ffc0(vm, value);
        const ClassTraits::Traits& argClassTR = vm.GetClassTraits(value);

        if (argTraits.IsArrayLike())
        {
            if (FUN_1425149a0(vm.GetClassTraitsArray(), argClassTR))
            {
                self.VMRef.ThrowError(VM::Error(VM::eNotImplementedError, self.VMRef, "Vector::concat() for argument of type Array"));
                return;
            }
            if (&currClassTR != &argClassTR)
            {
                self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                    currClassTR.GetName().ToCStr(), argClassTR.GetName().ToCStr()));
                return;
            }
            Append(r, static_cast<I&>(*value.GetObject()));
        }
        else if (FUN_1425149a0(currClassTR, self.VMRef.GetClassTraits(value)))
            ConcatPush(r, value);
        else
        {
            self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                currClassTR.GetName().ToCStr(), argClassTR.GetName().ToCStr()));
            return;
        }
    }
}

template <class I, class TR, typename T>
static __forceinline void VectorFilter(VectorBase<T>& self, SPtr<I>& result, const Value& callback, const Value& thisObject, I& owner)
{
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    if (callback.IsNullOrUndefined() || !self.CheckCallable(callback))
        return;

    Value _this(!thisObject.IsNullOrUndefined() ? thisObject : callback);
    for (UPInt i = 0; i < (UInt32)self.V.GetSize(); ++i)
    {
        const Value argv[3] = {ElementValue(self.V[i]), Value((UInt32)i), Value(&owner)};
        Value res;
        self.VMRef.ExecuteInternalUnsafe(callback, _this, res, 3, argv, false);
        if (self.VMRef.IsException())
            break;
        if (!res.IsBool() || !res.AsBool())
            continue;
        PushElement(r, self.V[i]);
    }
}

template <class I, class TR, typename T>
static __forceinline void VectorMap(VectorBase<T>& self, SPtr<I>& result, const Value& callback, const Value& thisObject, I& owner)
{
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    if (callback.IsNullOrUndefined() || !self.CheckCallable(callback))
        return;

    Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
    const ClassTraits::Traits& tr = MapClassTraits(owner);
    for (UPInt i = 0; i < (UInt32)self.V.GetSize(); ++i)
    {
        const Value argv[3] = {ElementValue(self.V[i]), Value((UInt32)i), Value(&owner)};
        Value res;
        self.VMRef.ExecuteInternalUnsafe(callback, _this, res, 3, argv, false);
        if (self.VMRef.IsException())
            break;
        Value coerced;
        if (!self.CheckCoerce(tr, res, coerced))
            return;
        PushCoerced(r, coerced);
    }
}

// ---- slice / splice

// a splice() insertion argument (already of the element type) inserted at pos
static SF_INLINE void InsertElement(VectorBase<Ptr<ASStringNode> >& v, UPInt pos, const Value& a)
{
    v.V.InsertAt(pos, Ptr<ASStringNode>(a.GetStringNode()));
}
static SF_INLINE void InsertElement(VectorBase<Value::Number>& v, UPInt pos, const Value& a) { v.V.InsertAt(pos, a.AsNumber()); }
static SF_INLINE void InsertElement(VectorBase<SInt32>& v, UPInt pos, const Value& a)        { v.V.InsertAt(pos, a.AsInt()); }
static SF_INLINE void InsertElement(VectorBase<Value>& v, UPInt pos, const Value& a)         { v.V.InsertAt(pos, a); }
static SF_INLINE void InsertElement(VectorBase<UInt32>& v, UPInt pos, const Value& a)        { v.V.InsertAt(pos, a.AsUInt()); }

template <typename T>
static SF_INLINE void SlicePush(VectorBase<T>& d, const VectorBase<T>& s, UPInt i) { const T e = s.V[i]; d.PushBack(e); }
static SF_INLINE void SlicePush(VectorBase<Ptr<ASStringNode> >& d, const VectorBase<Ptr<ASStringNode> >& s, UPInt i) { const Ptr<ASStringNode> e(s.V[i].GetPtr()); d.PushBack(e); }
static SF_INLINE void SlicePush(VectorBase<Value>& d, const VectorBase<Value>& s, UPInt i) { const Value& e = s.V[i]; d.CheckFixed(); if (!d.Fixed) d.V.PushBack(e); }
template <class I, class TR, typename T>
static SF_INLINE void VectorSlice(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);

    SInt32 startIndex = 0;
    SInt32 endIndex = 0xffffff;
    if (argc > 0 && !argv[0].Convert2Int32(startIndex))
        return;
    if (argc > 1 && !argv[1].Convert2Int32(endIndex))
        return;

    const SInt32 size = (SInt32)self.V.GetSize();
    if (startIndex < 0)
        startIndex += size;
    startIndex = Alg::Max<SInt32>(0, startIndex);
    if (endIndex < 0)
        endIndex += size;
    endIndex = Alg::Min((SInt32)self.V.GetSize(), endIndex);

    for (SInt32 i = startIndex; i < endIndex; ++i)
        SlicePush(r.V, self, i);
}

// RangeError 1125 (index out of range) naming the two values.
static SF_INLINE void ThrowRangeError(ArrayBase& self, const char* value, const char* range)
{
    VM& vm = self.VMRef;
    vm.ThrowRangeError(VM::Error(VM::eInvalidRangeError, vm, value, range));
}

// Vector.splice: the count elements from pos moved into deleted, the new vector it returns.
template <class I, typename T>
static SF_INLINE void DeleteElements(VectorBase<T>& self, UPInt pos, UPInt count, I& deleted)
{
    for (UPInt i = 0; i < count && i + pos < self.V.GetSize(); ++i)
        SlicePush(deleted.V, self, i + pos);
    self.V.RemoveMultipleAtInline(pos, count);
}
// out of line for the String and object vectors
void DeleteMultipleAt(VectorBase<Ptr<ASStringNode> >& self, UPInt pos, UPInt count, Vector_String& deleted);
void DeleteMultipleAt(VectorBase<Value>& self, UPInt pos, UPInt count, Vector_object& deleted);
template <class I, typename T>
static SF_INLINE void DeleteMultipleAt(VectorBase<T>& self, UPInt pos, UPInt count, I& deleted)
{
    DeleteElements(self, pos, count, deleted);
}

// Vector.splice: argv inserted at pos (already of the element type).
template <typename T>
static SF_INLINE void InsertElements(VectorBase<T>& self, UPInt pos, unsigned argc, const Value* argv)
{
    for (UPInt i = 0; i < argc; ++i)
        InsertElement(self, pos + i, argv[i]);
}
static SF_INLINE void InsertElements(VectorBase<Value>& self, UPInt pos, unsigned argc, const Value* argv)
{
    self.Insert(pos, argc, argv);
}

template <class I, class TR, typename T>
static __forceinline void VectorSplice(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    self.CheckFixed();
    if (self.Fixed)
        return;

    SInt32 startIndex = 0;
    if (argc > 0 && !argv[0].Convert2Int32(startIndex))
        return;

    const UInt32 size = (UInt32)self.V.GetSize();
    UInt32 deleteCount = 0;
    if (startIndex < 0)
        startIndex += size;
    if (argc > 1)
    {
        if (!argv[1].Convert2UInt32(deleteCount))
            return;
        if (startIndex < 0 || startIndex + deleteCount > size)
        {
            ThrowRangeError(self, AsString(size).ToCStr(), AsString(size).ToCStr());
            return;
        }
    }
    else
        deleteCount = size - startIndex;

    TR& itr = static_cast<TR&>(owner.GetTraits());
    I* r;
    {
        SPtr<I> sr = itr.MakeInstanceS(itr);
        r = sr.GetPtr();
        result.Pick(sr);
    }
    if (startIndex > (SInt32)size || startIndex < 0)
        return;

    DeleteMultipleAt(self, startIndex, deleteCount, *r);

    if (argc > 2)
    {
        startIndex = Alg::Min((SInt32)self.V.GetSize(), startIndex);
        InsertElements(self, startIndex, argc - 2, argv + 2);
    }
}

// @0x1425488d0
void DeleteMultipleAt(VectorBase<Ptr<ASStringNode> >& self, UPInt pos, UPInt count, Vector_String& deleted)
{
    DeleteElements(self, pos, count, deleted);
}

// @0x142548a70
void DeleteMultipleAt(VectorBase<Value>& self, UPInt pos, UPInt count, Vector_object& deleted)
{
    DeleteElements(self, pos, count, deleted);
}

// ---- sort: the elements are collected (as numbers, strings or element pointers), sorted, then copied back

typedef Pair<Value::Number, UInt32> NumberPair;
typedef Pair<ASString, UInt32>      StringPair;

// Called once per element; vftables of the int/uint/double/String/Value bases
// 0x143182e08/0x143182de8/0x143182dc8/0x143182da8/0x143182d88.
template <typename T>
struct SortFunc
{
    virtual ~SortFunc() {}
    virtual void operator()(UInt32 ind, const T& v) = 0;
};

template <typename T>
static SF_INLINE void ForEachElement(const VectorBase<T>& self, SortFunc<T>& f)
{
    const UPInt size = self.V.GetSize();
    for (UInt32 i = 0; i < size; ++i)
        f(i, self.V[i]);
}

static SF_INLINE CheckResult ElementNumber(SInt32 v, Value::Number& n)                    { n = v; return true; }
static SF_INLINE CheckResult ElementNumber(UInt32 v, Value::Number& n)                    { n = v; return true; }
static SF_INLINE CheckResult ElementNumber(Value::Number v, Value::Number& n)             { n = v; return true; }

// (number, index) pairs; elements that do not convert are left out
template <typename T>
struct Value2NumberCollector : public SortFunc<T>
{
    Value2NumberCollector(ArrayDH<NumberPair>& pairs) : Pairs(pairs) {}
    virtual void operator()(UInt32 ind, const T& v)
    {
        Value::Number n;
        if (ElementNumber(v, n))
            Pairs.PushBack(NumberPair(n, ind));
    }

    ArrayDH<NumberPair>& Pairs;
};

template <>
void Value2NumberCollector<Value>::operator()(UInt32 ind, const Value& v)
{
    Value::Number n;
    if (v.Convert2Number(n))
        Pairs.PushBack(NumberPair(n, ind));
}

template <>
void Value2NumberCollector<Ptr<ASStringNode> >::operator()(UInt32 ind, const Ptr<ASStringNode>& v)
{
    Value::Number n;
    Value tmp(v.GetPtr());
    if (tmp.Convert2Number(n))
        Pairs.PushBack(NumberPair(n, ind));
}

// (string, index) pairs; elements that do not convert are left out
template <typename T>
struct Value2StrCollector : public SortFunc<T>
{
    Value2StrCollector(VM& vm, ArrayDH<StringPair>& pairs) : VMRef(vm), Pairs(pairs) {}
    virtual void operator()(UInt32 ind, const T& v)
    {
        ASString str = VMRef.GetStringManager().CreateEmptyString();
        if (Value(v).Convert2String(str))
        {
            const StringPair p(str, ind);
            Pairs.PushBack(p);
        }
    }

    VM&                  VMRef;
    ArrayDH<StringPair>& Pairs;
};

template <>
void Value2StrCollector<Value>::operator()(UInt32 ind, const Value& v)
{
    ASString str = VMRef.GetStringManager().CreateEmptyString();
    if (v.Convert2String(str))
    {
        const StringPair p(str, ind);
        Pairs.PushBack(p);
    }
}

template <>
void Value2StrCollector<Ptr<ASStringNode> >::operator()(UInt32 ind, const Ptr<ASStringNode>& v)
{
    Pairs.PushBack(StringPair(ASString(v.GetPtr()), ind));
}

// pointers to the elements, for a compare function
template <typename T>
struct ValuePtrCollector : public SortFunc<T>
{
    ValuePtrCollector(ArrayDH<const T*>& ptrs) : Ptrs(ptrs) {}
    virtual void operator()(UInt32, const T& v) { Ptrs.PushBack(&v); }

    ArrayDH<const T*>& Ptrs;
};

// Array.CASEINSENSITIVE / DESCENDING / Locale-aware string order of the pairs.
struct CompareAsStringInd
{
    CompareAsStringInd(bool desc, bool ci, bool loc) : Desc(desc), CaseInsensitive(ci), UseLocale(loc) {}
    bool operator()(const StringPair& a, const StringPair& b) const { return Compare(a.First, b.First) < 0; }
    SInt32 Compare(const ASString& a, const ASString& b) const;

    bool Desc;
    bool CaseInsensitive;
    bool UseLocale;
};

struct CompareAsNumberInd
{
    CompareAsNumberInd(bool desc) : Desc(desc) {}
    bool operator()(const NumberPair& a, const NumberPair& b) const { return Desc ? a.First > b.First : b.First > a.First; }

    bool Desc;
};

static SF_INLINE SInt32 CompareElements(VM& vm, const Value& f, const Value& a, const Value& b)  { return Impl::CompareFunct(vm, f, a, b); }
template <typename T>
static SF_INLINE SInt32 CompareElements(VM& vm, const Value& f, const T& a, const T& b)          { return Impl::CompareFunct(vm, f, ElementValue(a), ElementValue(b)); }

template <typename T>
struct CompareValuePtr
{
    CompareValuePtr(VM& vm, const Value& f) : VMRef(vm), Func(f) {}
    bool operator()(const T* a, const T* b) const { return Impl::CompareFunct(VMRef, Func, ElementValue(*a), ElementValue(*b)) < 0; }

    VM&          VMRef;
    const Value& Func;
};

template <>
bool CompareValuePtr<Ptr<ASStringNode> >::operator()(const Ptr<ASStringNode>* a, const Ptr<ASStringNode>* b) const
{
    VM& vm = VMRef;
    return Impl::CompareFunct(vm, Func, Value(a->GetPtr()), Value(b->GetPtr())) < 0;
}

template <>
bool CompareValuePtr<Value>::operator()(const Value* a, const Value* b) const { return Impl::CompareFunct(VMRef, Func, *a, *b) < 0; }

template <class I, class TR, typename T>
static __forceinline void VectorSort(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    enum { CaseInsensitive = 1, Descending = 2, UniqueSort = 4, ReturnIndexedArray = 8, Numeric = 16 };

    Value compareFunction;
    SInt32 flags = 0;
    if (argc > 0)
    {
        if (argv[0].IsCallable())
            compareFunction.Assign(argv[0]);
        else if (!argv[0].Convert2Int32(flags))
        {
            self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                FUN_14250ffc0(self.VMRef, argv[0]).GetName().ToCStr(), MapClassTraits(owner).GetName().ToCStr()));
            return;
        }
    }
    if (argc > 1 && !argv[1].Convert2Int32(flags))
    {
        self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
            FUN_14250ffc0(self.VMRef, argv[1]).GetName().ToCStr(), MapClassTraits(owner).GetName().ToCStr()));
        return;
    }

    VM& vm = self.VMRef;
    MemoryHeap* heap = vm.GetMemoryHeap();
    ArrayDH<T> newSA(heap);
    if (compareFunction.IsNullOrUndefined())
    {
        if ((flags & Numeric) == 0)
        {
            ArrayDH<StringPair> pairs(heap);
            Value2StrCollector<T> vc(vm, pairs);
            ForEachElement(self, vc);

            CompareAsStringInd cmp((flags & Descending) != 0, (flags & CaseInsensitive) != 0, ((flags >> 10) & 1) != 0);
            Alg::QuickSortSafe(pairs, cmp);
            if (flags & UniqueSort)
            {
                for (UInt32 i = 1; i < pairs.GetSize(); ++i)
                {
                    if (cmp.Compare(pairs[i - 1].First, pairs[i].First) == 0)
                    {
                        result.SetNull();
                        return;
                    }
                }
            }
            for (UPInt i = 0; i < pairs.GetSize(); ++i)
                newSA.PushBack(self.V[pairs[i].Second]);
        }
        else
        {
            ArrayDH<NumberPair> pairs(heap);
            Value2NumberCollector<T> vc(pairs);
            ForEachElement(self, vc);

            // always ascending: the exe passes false here, so NUMERIC drops DESCENDING (the SDK honours it)
            Alg::QuickSortSlicedSafe(pairs, 0, pairs.GetSize(), CompareAsNumberInd(false));
            if (flags & UniqueSort)
            {
                for (UInt32 i = 1; i < pairs.GetSize(); ++i)
                {
                    if (pairs[i - 1].First == pairs[i].First)
                    {
                        result.SetSInt32(0);
                        return;
                    }
                }
            }
            for (UPInt i = 0; i < pairs.GetSize(); ++i)
                newSA.PushBack(self.V[pairs[i].Second]);
        }
    }
    else
    {
        ArrayDH<const T*> ptrs(heap);
        ValuePtrCollector<T> vc(ptrs);
        ForEachElement(self, vc);

        Alg::QuickSortSafe(ptrs, CompareValuePtr<T>(vm, compareFunction));
        if (flags & UniqueSort)
        {
            for (UInt32 i = 1; i < ptrs.GetSize(); ++i)
            {
                if (CompareElements(vm, compareFunction, *ptrs[i - 1], *ptrs[i]) == 0)
                {
                    result.SetNull();
                    return;
                }
            }
        }
        for (UPInt i = 0; i < ptrs.GetSize(); ++i)
            newSA.PushBack(*ptrs[i]);
    }

    if ((flags & ReturnIndexedArray) == 0)
    {
        self.V = newSA;
        result.Assign(&owner);
        return;
    }

    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    if (r.V.CheckFixed())
    {
        for (UPInt i = 0; i < newSA.GetSize(); ++i)
            r.V.V.PushBack(newSA[i]);
    }
    result.Pick(pr);
}

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

// The whole-array sorts VectorSort calls (out of line in the exe).
namespace Scaleform { namespace Alg {
typedef GFx::AS3::Value AS3Value;
template bool QuickSortSafe(ArrayDH<const SInt32*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<SInt32>);
template bool QuickSortSafe(ArrayDH<const UInt32*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<UInt32>);
template bool QuickSortSafe(ArrayDH<const GFx::AS3::Value::Number*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<GFx::AS3::Value::Number>);
template bool QuickSortSafe(ArrayDH<const Ptr<GFx::ASStringNode>*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<Ptr<GFx::ASStringNode> >);
template bool QuickSortSafe(ArrayDH<const AS3Value*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<AS3Value>);
template bool QuickSortSafe(ArrayDH<Pair<GFx::ASString, UInt32> >&, GFx::AS3::Instances::fl_vec::CompareAsStringInd);
}} // namespace Scaleform::Alg

using namespace Scaleform;
using namespace Scaleform::GFx::AS3;
namespace VI = Scaleform::GFx::AS3::Instances::fl_vec;
namespace VT = Scaleform::GFx::AS3::InstanceTraits::fl_vec;

// MS2-FUNCTIONAL: register allocation and frame layout (the exe frame is 0x10 bytes larger)
// @0x142547960
void FUN_142547960(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorConcat<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: register allocation and frame layout (the exe frame is 0x10 bytes larger)
// @0x142547c40
void FUN_142547c40(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorConcat<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: register allocation and frame layout (the exe frame is 0x10 bytes larger)
// @0x142547f30
void FUN_142547f30(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorConcat<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: register allocation and frame layout (the exe frame is 0x10 bytes larger)
// @0x142548280
void FUN_142548280(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorConcat<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: register allocation and frame layout (the exe frame is 0x10 bytes larger)
// @0x142548580
void FUN_142548580(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorConcat<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }

// @0x142548bd0
void FUN_142548bd0(VectorBase<Ptr<GFx::ASStringNode> >& v, SPtr<VI::Vector_String>& result, const Value& callback, const Value& thisObject, VI::Vector_String& owner)
{ VI::VectorFilter<VI::Vector_String, VT::Vector_String>(v, result, callback, thisObject, owner); }
// @0x142548f60
void FUN_142548f60(VectorBase<Value::Number>& v, SPtr<VI::Vector_double>& result, const Value& callback, const Value& thisObject, VI::Vector_double& owner)
{ VI::VectorFilter<VI::Vector_double, VT::Vector_double>(v, result, callback, thisObject, owner); }
// @0x142549300
void FUN_142549300(VectorBase<SInt32>& v, SPtr<VI::Vector_int>& result, const Value& callback, const Value& thisObject, VI::Vector_int& owner)
{ VI::VectorFilter<VI::Vector_int, VT::Vector_int>(v, result, callback, thisObject, owner); }
// @0x1425496a0
void FUN_1425496a0(VectorBase<Value>& v, SPtr<VI::Vector_object>& result, const Value& callback, const Value& thisObject, VI::Vector_object& owner)
{ VI::VectorFilter<VI::Vector_object, VT::Vector_object>(v, result, callback, thisObject, owner); }
// @0x142549a60
void FUN_142549a60(VectorBase<UInt32>& v, SPtr<VI::Vector_uint>& result, const Value& callback, const Value& thisObject, VI::Vector_uint& owner)
{ VI::VectorFilter<VI::Vector_uint, VT::Vector_uint>(v, result, callback, thisObject, owner); }

// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c050
void FUN_14254c050(VectorBase<Ptr<GFx::ASStringNode> >& v, SPtr<VI::Vector_String>& result, const Value& callback, const Value& thisObject, VI::Vector_String& owner)
{ VI::VectorMap<VI::Vector_String, VT::Vector_String>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c4e0
void FUN_14254c4e0(VectorBase<Value::Number>& v, SPtr<VI::Vector_double>& result, const Value& callback, const Value& thisObject, VI::Vector_double& owner)
{ VI::VectorMap<VI::Vector_double, VT::Vector_double>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c980
void FUN_14254c980(VectorBase<SInt32>& v, SPtr<VI::Vector_int>& result, const Value& callback, const Value& thisObject, VI::Vector_int& owner)
{ VI::VectorMap<VI::Vector_int, VT::Vector_int>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce and the result PushBack; ours calls them
// @0x14254ce20
void FUN_14254ce20(VectorBase<Value>& v, SPtr<VI::Vector_object>& result, const Value& callback, const Value& thisObject, VI::Vector_object& owner)
{ VI::VectorMap<VI::Vector_object, VT::Vector_object>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254d380
void FUN_14254d380(VectorBase<UInt32>& v, SPtr<VI::Vector_uint>& result, const Value& callback, const Value& thisObject, VI::Vector_uint& owner)
{ VI::VectorMap<VI::Vector_uint, VT::Vector_uint>(v, result, callback, thisObject, owner); }

// MS2-FUNCTIONAL: slice start clamp: the exe re-tests startIndex after the add (extra test before cmovs)
// @0x14254fe70
void FUN_14254fe70(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorSlice<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: slice start clamp: the exe re-tests startIndex after the add (extra test before cmovs)
// @0x142550070
void FUN_142550070(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorSlice<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: slice start clamp: the exe re-tests startIndex after the add (extra test before cmovs)
// @0x142550290
void FUN_142550290(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorSlice<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// @0x142550490
void FUN_142550490(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorSlice<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: slice start clamp: the exe re-tests startIndex after the add (extra test before cmovs)
// @0x142550640
void FUN_142550640(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorSlice<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }

// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142550840
void FUN_142550840(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorSort<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142551250
void FUN_142551250(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorSort<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142551cb0
void FUN_142551cb0(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorSort<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x1425526f0
void FUN_1425526f0(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorSort<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142553170
void FUN_142553170(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorSort<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }

// MS2-FUNCTIONAL: splice: the RangeError's AsString temporaries get other stack slots and ToCStr is scheduled differently; register allocation
// @0x142553bb0
void FUN_142553bb0(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorSplice<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: splice: the RangeError's AsString temporaries get other stack slots and ToCStr is scheduled differently; register allocation
// @0x142553e90
void FUN_142553e90(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorSplice<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: splice: the RangeError's AsString temporaries get other stack slots and ToCStr is scheduled differently; register allocation
// @0x142554280
void FUN_142554280(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorSplice<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: splice: the RangeError's AsString temporaries get other stack slots and ToCStr is scheduled differently; register allocation
// @0x142554660
void FUN_142554660(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorSplice<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: splice: the RangeError's AsString temporaries get other stack slots and ToCStr is scheduled differently; register allocation
// @0x142554880
void FUN_142554880(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorSplice<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }


// ==== Vector class traits (sfr19) ====================================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_vec
{
    extern const ClassInfo VectorCI;
    extern const ClassInfo Vector_StringCI;
    extern const ClassInfo Vector_doubleCI;
    extern const ClassInfo Vector_intCI;
    extern const ClassInfo Vector_objectCI;
    extern const ClassInfo Vector_uintCI;
    // The package of the Vector classes, "__AS3__.vec".
    extern const char* NS_Vector;
}

namespace ClassTraits { namespace fl_vec
{
    // @0x142546c50
    Pickable<Traits> Vector_int::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_int(vm));
    }

    // @0x142546da0
    Pickable<Traits> Vector_uint::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_uint(vm));
    }

    // @0x142546ef0
    Pickable<Traits> Vector_double::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_double(vm));
    }

    // @0x142547040
    Pickable<Traits> Vector_String::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_String(vm));
    }

    // @0x142547190
    Pickable<Traits> Vector_object::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_object(vm));
    }

    // @0x142547420
    Pickable<Traits> Vector::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector(vm));
    }

    // @0x142554c80
    Vector::Vector(VM& vm)
        : Traits(vm, AS3::fl_vec::VectorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_vec::VectorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_vec::Vector(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142554d60
    Vector::Vector(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142554d90
    Vector_String::Vector_String(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_StringCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_StringCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142554e90
    Vector_String::Vector_String(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142554ec0
    Vector_String::Vector_String(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142554f50
    Vector_double::Vector_double(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_doubleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_doubleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142555050
    Vector_double::Vector_double(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142555080
    Vector_double::Vector_double(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142555110
    Vector_int::Vector_int(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_intCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_intCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142555210
    Vector_int::Vector_int(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142555240
    Vector_int::Vector_int(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // The traits of Vector.<*>; its instance traits are made per element type.
    // @0x1425552d0
    Vector_object::Vector_object(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_objectCI)
        , EnclosedClassTraits(NULL)
    {
        TraitsType = Traits_Vector_object;
    }

    // @0x142555310
    Vector_object::Vector_object(VM& vm, const ASString& n, const ClassTraits::Traits* ect)
        : Traits(vm, AS3::fl_vec::Vector_objectCI)
        , EnclosedClassTraits(ect)
    {
        TraitsType = Traits_Vector_object;

        InstanceTraits::Traits* it = new(vm.GetMemoryHeap()) InstanceTraitsType(vm, n,
            vm.MakeInternedNamespace(Abc::NS_Public, AS3::fl_vec::NS_Vector),
            &vm.GetClassTraitsObject().GetInstanceTraits(), true, true);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(vm.GetMemoryHeap()) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x1425554a0
    Vector_object::Vector_object(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x1425554d0
    Vector_object::Vector_object(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, const Traits* pt,
        bool isDynamic, bool isFinal)
        : RTraits(vm, n, ns, pt, isDynamic, isFinal)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_Vector_object;
        for (unsigned i = 0; i < ThunkInfoNum; ++i)
            Add2VT(AS3::fl_vec::Vector_objectCI, AS3::fl_vec::Vector_objectCI.InstanceMethod[i]);
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x1425555c0
    Vector_uint::Vector_uint(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_uintCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_uintCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x1425556c0
    Vector_uint::Vector_uint(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x1425556f0
    Vector_uint::Vector_uint(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// Script-global set capacity recovery; the type is also used by the add instantiation in sfr_as3_15.
typedef Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> MS2_ScriptPtr;
typedef Scaleform::HashSetBase<MS2_ScriptPtr, Scaleform::FixedSizeHash<MS2_ScriptPtr>,
                               Scaleform::FixedSizeHash<MS2_ScriptPtr>,
                               Scaleform::AllocatorLH<MS2_ScriptPtr, 2>,
                               Scaleform::HashsetCachedEntry<MS2_ScriptPtr,
                                   Scaleform::FixedSizeHash<MS2_ScriptPtr> > > MS2_ScriptSet;
// @0x142542820
// MS2-FUNCTIONAL ?setRawCapacity@?$HashSetBase@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@AEAAXPEAX_K@Z: equivalent rehashing; local allocator calls and frame layout differ from the exe
// MS2-PIN: ?setRawCapacity@?$HashSetBase@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@AEAAXPEAX_K@Z 0x142542820
template void MS2_ScriptSet::setRawCapacity(void*, Scaleform::UPInt);

// Argument defaults of the Vector.<T> callback methods, emitted out of line here (their ThunkFunc2 thunks are in
// sfr_as3_21): every 7, filter 8, forEach 9, some 11, map 14 per element type; callback undefined, thisObject null.
namespace Scaleform { namespace GFx { namespace AS3 {
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 14, const Value&, const Value&>(StringManager&);
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Alg {
// @0x14254fda0
void ReverseArray(ArrayDH<Ptr<GFx::ASStringNode>, 2, ArrayDefaultPolicy>& values)
{
    SPInt from = 0;
    SPInt to = (SPInt)values.GetSize() - 1;
    while (from < to)
    {
        Swap(values[from], values[to]);
        ++from;
        --to;
    }
}
}}

// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546850
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425468b0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546920
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546980
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425469e0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546a50
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546ab0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546b20
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546b80
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546be0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547220
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547280
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425472f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547350
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425473b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547560
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425475c0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547630
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547690
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425476f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547760
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425477c0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547830
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547890
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425478f0
// MS2-PIN: ??$ReadDouble@E@Abc@AS3@GFx@Scaleform@@YANAEAPEBE@Z 0x142545390
// MS2-PIN: ??$ReadS24@E@Abc@AS3@GFx@Scaleform@@YAHPEBEAEA_K@Z 0x1425454b0
// MS2-PIN: ??$ReadString@E@Abc@AS3@GFx@Scaleform@@YA?AVString@3@AEAPEBE_K@Z 0x1425454f0
// MS2-PIN: ??$ReadString@E@Abc@AS3@GFx@Scaleform@@YA?AVString@3@PEBEAEA_K_K@Z 0x142545530
// MS2-FUNCTIONAL 0x1425455b0: the exe reloads the pointer/position through the reference on every loop pass; ours keeps it in a register
// MS2-PIN: ??$ReadU30@E@Abc@AS3@GFx@Scaleform@@YAHAEAPEBE@Z 0x1425455b0
// MS2-FUNCTIONAL 0x142545600: the exe reloads the pointer/position through the reference on every loop pass; ours keeps it in a register
// MS2-PIN: ??$ReadU30@E@Abc@AS3@GFx@Scaleform@@YAHPEBEAEA_K@Z 0x142545600
// MS2-PIN: ??_7ArrayBase@AS3@GFx@Scaleform@@6B@ 0x143181db8
// MS2-PIN: ??_7?$VectorBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181e08
// MS2-PIN: ??_7?$VectorBase@N@AS3@GFx@Scaleform@@6B@ 0x143182460
// MS2-PIN: ??_7?$VectorBase@J@AS3@GFx@Scaleform@@6B@ 0x143181e30
// MS2-PIN: ??_7?$VectorBase@VValue@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181de0
// MS2-PIN: ??_7?$VectorBase@K@AS3@GFx@Scaleform@@6B@ 0x143182148
// These non-RTTI vftables are pinned to executable addresses recovered from their slot layouts.
// MS2-PIN: ??_7URLBuilder@GFx@Scaleform@@6B@ 0x14317fbe8
// MS2-PIN: ??_7ASIMEManager@GFx@Scaleform@@6B@ 0x14317fc38
// MS2-PIN: ??_7IMEManager@AS3@GFx@Scaleform@@6B@ 0x14317fce8
// MS2-PIN: ??_7NotifyLoadInitCandidateList@AS3@GFx@Scaleform@@6B@ 0x14317fdf0
// MS2-PIN: ??_7Vector_String@fl_vec@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143182858
// MS2-PIN: ??_7Vector_double@fl_vec@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143182558
// MS2-PIN: ??_7Vector_int@fl_vec@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143181f20
// MS2-PIN: ??_7Vector_object@fl_vec@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143182b58
// MS2-PIN: ??_7Vector_uint@fl_vec@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143182238
// MS2-PIN: ??_7Vector@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143181c40
// MS2-PIN: ??_7Vector_String@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143182908
// MS2-PIN: ??_7Vector_double@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143182608
// MS2-PIN: ??_7Vector_int@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143181fd0
// MS2-PIN: ??_7Vector_object@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143182c00
// MS2-PIN: ??_7Vector_uint@fl_vec@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431822e0
// MS2-PIN: ??_7Vector@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x143181cd0
// MS2-PIN: ??_7Vector_String@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x1431829a0
// MS2-PIN: ??_7Vector_double@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x1431826a0
// MS2-PIN: ??_7Vector_int@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x143182060
// MS2-PIN: ??_7Vector_object@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x143182ca0
// MS2-PIN: ??_7Vector_uint@fl_vec@Classes@AS3@GFx@Scaleform@@6B@ 0x143182378
// MS2-PIN: ??_7Vector_String@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182788
// MS2-PIN: ??_7Vector_double@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182488
// MS2-PIN: ??_7Vector_int@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143181e58
// MS2-PIN: ??_7Vector_object@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182a88
// MS2-PIN: ??_7Vector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182170
// The remaining compiler-emitted tables are abstract/interface-only layers with no independent executable table:
// NotifyLoadInitC has four pure callback slots; the two RefCountBase layers occur only as ASIMEManager subobjects.
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d950
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@1@@Z 0x14254df40
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@1@@Z 0x14254e530
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z: the exe reads the comparator VM reference before building the two Value temporaries, ours after; other registers and a 0x10 bigger exe frame follow, same calls and order
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254eb40
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@Scaleform@@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@1@_K1U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f140
// MS2-PIN: ??_G?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425564f0
// MS2-PIN: ??R?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142555b10
// MS2-PIN: ??_G?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425564c0
// MS2-PIN: ??R?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x142555a40
// MS2-PIN: ??_G?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556490
// MS2-PIN: ??R?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x1425559c0
// MS2-PIN: ??_G?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556460
// MS2-PIN: ??R?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555940
// MS2-PIN: ??_G?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556430
// MS2-PIN: ??R?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x1425558c0
// MS2-PIN: ??_G?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425565e0
// MS2-FUNCTIONAL ??R?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142555eb0
// MS2-PIN: ??_G?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425565b0
// MS2-FUNCTIONAL ??R?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x142555e50
// MS2-PIN: ??_G?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556580
// MS2-FUNCTIONAL ??R?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x142555d70
// MS2-PIN: ??_G?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556550
// MS2-FUNCTIONAL ??R?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555c90
// MS2-PIN: ??_G?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556520
// MS2-FUNCTIONAL ??R?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x142555bb0
// MS2-PIN: ??R?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142556110
// MS2-PIN: ??R?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x1425560a0
// MS2-PIN: ??R?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x142556030
// MS2-PIN: ??R?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555fc0
// MS2-PIN: ??R?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x142555f50
// MS2-PIN: ??_G?$SortFunc@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556400
// MS2-PIN: ??_G?$SortFunc@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425563d0
// MS2-PIN: ??_G?$SortFunc@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425563a0
// MS2-PIN: ??_G?$SortFunc@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556370
// MS2-PIN: ??_G?$SortFunc@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556340
// MS2-PIN: ??_G?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425566d0
// MS2-PIN: ??_G?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556610
// MS2-PIN: ??_G?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556640
// MS2-PIN: ??_G?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556670
// MS2-PIN: ??_G?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425566a0
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@1@@Z: the exe swaps the (number, index) pairs member by member; ours moves the 16-byte pair with movups
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f400
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z: the inlined (string, index) pair swaps and node releases get other registers and frame layout; same calls and order
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f740
// MS2-PIN: ??_7?$SortFunc@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182d88
// MS2-PIN: ??_7?$SortFunc@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182da8
// MS2-PIN: ??_7?$SortFunc@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182dc8
// MS2-PIN: ??_7?$SortFunc@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182de8
// MS2-PIN: ??_7?$SortFunc@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e08
// MS2-PIN: ??_7?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182d98
// MS2-PIN: ??_7?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182db8
// MS2-PIN: ??_7?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182dd8
// MS2-PIN: ??_7?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182df8
// MS2-PIN: ??_7?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e18
// MS2-PIN: ??_7?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e28
// MS2-PIN: ??_7?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e38
// MS2-PIN: ??_7?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e48
// MS2-PIN: ??_7?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e58
// MS2-PIN: ??_7?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e68
// MS2-PIN: ??_7?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ec8
// MS2-PIN: ??_7?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ed8
// MS2-PIN: ??_7?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ee8
// MS2-PIN: ??_7?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ef8
// MS2-PIN: ??_7?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182f08
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142549df0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142549f50
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a0b0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a210
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a370
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a4d0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a630
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a790
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a8f0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254aa50
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254abb0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254ad10
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254ae70
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254afd0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b130
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b290
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b3f0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b550
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b6b0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b810
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b970
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bad0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bc30
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bd90
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bef0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d820
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d850
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d880
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d8b0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@Scaleform@@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@1@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d8e0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d920
// MS2-PIN: ??$Read16@E@Abc@AS3@GFx@Scaleform@@YAHAEAPEBE@Z 0x142545350
// MS2-PIN: ??$ReadStringPtr@E@Abc@AS3@GFx@Scaleform@@YA?AVStringDataPtr@3@AEAPEBE_K@Z 0x142545570
// MS2-PIN: ??_GCode@Abc@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142545b70
// MS2-PIN: ??_7Code@Abc@AS3@GFx@Scaleform@@6B@ 0x143181a00
// MS2-PIN: ??_7File@Abc@AS3@GFx@Scaleform@@6B@ 0x14317b050
// MS2-PIN: ??_G?$VectorBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556270 ; prop
// MS2-PIN: ??_G?$VectorBase@VValue@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425562c0 ; prop
// MS2-PIN: ??_GArrayBase@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556310 ; unique
// The scalar-deleting destructor bodies share an identical COMDAT; pin each emitted type to the matching exe slot.
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142542e10
// MS2-PIN: ??_G?$RefCountBase@VNotifyLoadInitC@AS3@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142542e70
// MS2-PIN: ??_GNotifyLoadInitC@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142543050
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0CAB@@Scaleform@@UEAAPEAXI@Z 0x142542ed0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0CAB@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7?$RefCountBase@VASIMEManager@GFx@Scaleform@@$0CAB@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7NotifyLoadInitC@AS3@GFx@Scaleform@@6B@ 0x14317fc00
// MS2-PIN: ??_7?$RefCountBase@VNotifyLoadInitC@AS3@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14317fbf8
// MS2-PIN: ??_GNotifyLoadInitCandidateList@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425430b0
