// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Selection: the onSetFocus
// broadcast and Selection.captureFocus (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429326a0-0x142932999 .text$mn
// MS2-RANGE: 0x142963320-0x1429633fb .text$mn
// MS2-RANGE: 0x142932ab0-0x142932d1c .text$mn
// MS2-RANGE: 0x142933010-0x1429333c6 .text$mn
// MS2-RANGE: 0x142933bd0-0x142933d4e .text$mn
// MS2-RANGE: 0x142933e20-0x14293405a .text$mn
// MS2-RANGE: 0x1429343f0-0x142934474 .text$mn
// MS2-RANGE: 0x142935820-0x142935b4c .text$mn

#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_event.h"
#include "../include/kernel/sf_arraypaged.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// MovieImpl::ActivateFocusCapture, declared only in the player build
void FUN_14256bbf0(MovieImpl* pmovie, unsigned controllerIdx);
// AvmSprite::FindClassAndInitializeClassInstance (gap of sfr_as2_05)
void FUN_142943480(const FnCall& fn);

// Calls each listener's onSetFocus with the arguments already on the stack.
class SetFocusInvokeCallback : public AsBroadcaster::InvokeCallback
{
public:
    int NArgs;
    int FirstArgBottomIndex;

    SetFocusInvokeCallback(int nargs, int firstArg) : NArgs(nargs), FirstArgBottomIndex(firstArg) {}

    virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method);
};

// MS2-FUNCTIONAL the exe inlines ~FnCall (both ThisFunctionRef releases); here it is a call
// @0x142963320
void SetFocusInvokeCallback::Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method)
{
    Value result;
    method.Invoke(FnCall(&result, pthis, penv, NArgs, FirstArgBottomIndex));
}

// AsBroadcaster::BroadcastMessage (0x142932180), inlined in BroadcastOnSetFocus.
static SF_FORCEINLINE bool BroadcastMessageLocal(Environment* penv, ObjectInterface* pthis, const ASString& eventName,
                                                 int nArgs, int firstArgBottomIndex)
{
    if (!pthis)
        return false;
    SetFocusInvokeCallback callback(nArgs, firstArgBottomIndex);
    AsBroadcaster::BroadcastMessageWithCallback(penv, pthis, eventName, &callback);
    return true;
}

// Environment::Drop as the exe has it (ArrayPaged Pop(n): while (n > 0) { Pop1(); n--; }).
static SF_FORCEINLINE void DropLocal(Environment* penv, unsigned n)
{
    while (n > 0)
    {
        penv->Drop1();
        n--;
    }
}

// @0x1429326a0
void Selection::BroadcastOnSetFocus(Environment* penv, InteractiveObject* pOldFocus, InteractiveObject* pNewFocus,
                                    unsigned controllerIdx)
{
    Value selectionCtorVal;
    if (penv->GetSC()->pContext->pGlobal->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_Selection),
                                                        &selectionCtorVal))
    {
        ObjectInterface* pselectionObj = selectionCtorVal.ToObject(penv);
        if (pselectionObj)
        {
            int nargs = 2;
            if (penv->CheckExtensions())
            {
                penv->Push(Number(controllerIdx));
                ++nargs;
            }
            if (pNewFocus)
                penv->Push(Value(pNewFocus));
            else
                penv->Push(Value::NULLTYPE);
            if (pOldFocus)
                penv->Push(Value(pOldFocus));
            else
                penv->Push(Value::NULLTYPE);
            BroadcastMessageLocal(penv, pselectionObj, penv->CreateConstString("onSetFocus"), nargs,
                                  penv->GetTopIndex());
            DropLocal(penv, nargs);
        }
    }
}

// Value::SetAsCharacter (0x14297fba0) with SetAsCharacterHandle, inlined in captureFocus.
static SF_FORCEINLINE void SetValueAsCharacter(Value* pv, InteractiveObject* pchar)
{
    CharacterHandle* phandle = pchar ? pchar->GetCharacterHandle() : 0;
    if (pv->T.Type != Value::CHARACTER || pv->V.pCharHandle != phandle)
    {
        pv->DropRefs();
        pv->T.Type        = Value::CHARACTER;
        pv->V.pCharHandle = phandle;
        if (pv->V.pCharHandle)
            pv->V.pCharHandle->AddRef();
    }
}

// @0x142932ab0
void SelectionCtorFunction::CaptureFocus(const FnCall& fn)
{
    fn.Result->SetUndefined();
    bool capture;
    if (fn.NArgs >= 1)
        capture = fn.Arg(0).ToBool(fn.Env);
    else
        capture = true;
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    unsigned controllerIdx = 0;
    if (fn.NArgs >= 2)
        controllerIdx = fn.Arg(1).ToUInt32(fn.Env);
    Ptr<InteractiveObject> focusedChar = proot->GetFocusedCharacter(controllerIdx);
    if (!focusedChar)
    {
        // no character is focused: simulate a Tab press
        FUN_14256bbf0(proot, controllerIdx);
        focusedChar = proot->GetFocusedCharacter(controllerIdx);
    }
    if (capture)
    {
        if (focusedChar && focusedChar->IsFocusEnabled(GFx_FocusMovedByKeyboard))
            proot->SetKeyboardFocusTo(focusedChar, controllerIdx, GFx_FocusMovedByKeyboard);
    }
    else
        proot->HideFocusRect(controllerIdx);
    if (focusedChar)
        SetValueAsCharacter(fn.Result, focusedChar);
}

// MovieImpl::GetLevelMovie inlined: the sprite of the level, 0 if there is none.
static SF_FORCEINLINE InteractiveObject* LevelMovieInline(MovieImpl* pmovie, int level)
{
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The cursor of a mouse changed: with the extensions and a script replacement the Mouse.setCursorType handler is
// called, otherwise the host is asked to show the shape.
// MS2-FUNCTIONAL: the exe keeps 0 in esi (push r12/r13, 0xe0 frame) and inlines ToFunction as a switch
// @0x142933010
void MovieRoot::ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType)
{
    // MovieRoot::GetAvmLevelMovie(0) with ToAvmSprite inlined
    AvmSprite*   plevel0 = static_cast<AvmSprite*>(static_cast<AvmCharacter*>(LevelMovieInline(pMovieImpl, 0)->GetAvmObjImpl()));
    Environment* penv    = plevel0->GetASEnvironment();
    if (G_IsFlagSet<MovieImpl::Flag_SetCursorTypeFuncOverloaded>(pMovieImpl->Flags) && penv->CheckExtensions())
    {
        // extensions enabled and Mouse.setCursorType overloaded from ActionScript: call it
        Value objVal;
        if (penv->GetSC()->pContext->pGlobal->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_Mouse), &objVal))
        {
            Object* pobj = objVal.ToObject(penv);
            if (pobj)
            {
                Value scval;
                if (pobj->GetMember(penv, penv->GetBuiltin(ASBuiltin_setCursorType), &scval))
                {
                    FunctionRef funcRef = scval.ToFunction(penv);
                    if (!funcRef.IsNull())
                    {
                        Value res;
                        penv->Push(Number(mouseIdx));
                        penv->Push(Number(newCursorType));
                        funcRef.Invoke(FnCall(&res, objVal, penv, 2, penv->GetTopIndex()));
                        penv->Drop2();
                    }
                }
            }
        }
    }
    else
    {
        // MouseCtorFunction::SetCursorType inlined: the host is asked to show the shape
        if (newCursorType != *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(pMovieImpl) + 0x12a4 + mouseIdx * 0x50))
        {
            if (UserEventHandler* phandler = pMovieImpl->pUserEventHandler)
                phandler->HandleEvent(reinterpret_cast<Movie*>(pMovieImpl),
                                      MouseCursorEvent(static_cast<MouseCursorEvent::CursorShapeType>(newCursorType), mouseIdx));
        }
    }
}

// _root, _global and _levelN before the scope chain's own lookup: 0 = not one of them, 1 = the value is set, 2 = a
// level name whose level does not exist.
// MS2-FUNCTIONAL: ours shares the case-insensitive _global SetAsObject tail with the case-sensitive one (the exe
// repeats it) and keeps the builtins in r15 where the exe uses rbp
// @0x142933bd0
Bool3W Environment::CheckGlobalAndLevels(const GetVarParams& params) const
{
    // Handle _root and _global.
    if (IsCaseSensitive())
    {
        if (GetBuiltin(ASBuiltin__root).CompareBuiltIn_CaseCheck(params.VarName, true))
        {
            params.pResult->SetAsCharacter(Target->GetTopParent());
            return Bool3W(true);
        }
        else if (GetBuiltin(63).CompareBuiltIn_CaseCheck(params.VarName, true)) // _global
        {
            params.pResult->SetAsObject(StringContext.pContext->pGlobal);
            return Bool3W(true);
        }
    }
    else
    {
        if (GetBuiltin(ASBuiltin__root).CompareBuiltIn_CaseCheck(params.VarName, false))
        {
            params.pResult->SetAsCharacter(Target->GetTopParent());
            return Bool3W(true);
        }
        else if (GetBuiltin(63).CompareBuiltIn_CaseCheck(params.VarName, false))
        {
            params.pResult->SetAsObject(StringContext.pContext->pGlobal);
            return Bool3W(true);
        }
    }

    // Check for _levelN.
    const char* ptail = 0;
    int         level = MovieRoot::ParseLevelName(params.VarName.ToCStr(), &ptail, IsCaseSensitive());
    if ((level != -1) && !*ptail)
    {
        InteractiveObject* lm = static_cast<MovieRoot*>(Target->GetMovieImpl()->pASMovieRoot)->GetLevelMovie(level);
        if (lm)
        {
            params.pResult->SetAsCharacter(lm);
            return Bool3W(true);
        }
        return Bool3W(false);
    }
    return Bool3W();
}

// The state of one script function call (the layout of sfr_as2_06b's model, 0x58 bytes).
class InvokeContext
{
public:
    UByte*                 pThis;         // +0x00 AsFunctionObject
    Environment*           pOurEnv;       // +0x08
    const FnCall*          pFn;           // +0x10
    void*                  pLocalFrame;   // +0x18
    const char*            pMethodName;   // +0x20
    Ptr<InteractiveObject> TargetCh;      // +0x28
    Ptr<InteractiveObject> FnEnvCh;       // +0x30
    Ptr<InteractiveObject> PassedThisCh;  // +0x38
    Ptr<Object>            PassedThisObj; // +0x40
    void*                  CurLocalFrame; // +0x48
    unsigned               LocalStackTop; // +0x50

    // AsFunctionObject::IsFunction2 / Function2Flags / LocalRegisterCount.
    bool   IsFunction2() const { return pThis[0xca] == 2; }
    UInt16 Function2Flags() const { return *reinterpret_cast<const UInt16*>(pThis + 0xc8); }
    UByte  LocalRegisterCount() const { return pThis[0xcb]; }

    void Cleanup();
};

// Environment::SetLocal (out of line in sfr_as2_07), inlined in Cleanup.
static SF_FORCEINLINE void SetLocalInline(Environment* penv, const ASString& varname, const Value& val)
{
    if (penv->LocalFrames.GetSize() == 0)
        return;
    if (!penv->LocalFrames[penv->LocalFrames.GetSize() - 1])
        return;
    Value* pvalue = const_cast<Value*>(penv->FindLocal(varname));
    if (!pvalue)
        penv->AddLocal(varname, val);
    else
        *pvalue = val;
}

// The resizes Cleanup calls out of line (COMDATs where cl inlines them, as in Environment::Reset in sfr_as2_06): the
// frame array's ResizeNoConstruct (exe 0x14297e450) and the register array's Resize (exe 0x14297e0e0).
typedef ArrayDataBase<Ptr<LocalFrame>, AllocatorLH<Ptr<LocalFrame>, Stat_Default_Mem>, ArrayDefaultPolicy> LocalFramesData;
typedef ArrayBase<ArrayData<Value, AllocatorLH<Value, Stat_Default_Mem>, ArrayDefaultPolicy> > LocalRegisterBase;

// Environment::SetLocalFrameTop: LocalFrames.Resize(t).
static SF_FORCEINLINE void SetLocalFrameTopInline(Environment* penv, unsigned t)
{
    LocalFramesData* pdata   = reinterpret_cast<LocalFramesData*>(&penv->LocalFrames);
    UPInt            oldSize = pdata->Size;
    (pdata->*&LocalFramesData::ResizeNoConstruct)(&penv->LocalFrames, t);
    if (t > oldSize)
        AllocatorLH<Ptr<LocalFrame>, Stat_Default_Mem>::ConstructArray(pdata->Data + oldSize, t - oldSize);
}

// The invoked function's frame is left: the alternate prototype of a super call is dropped, this and super become
// undefined again in the caller's frame when the function did not take them, the locals and the call stack are
// back where they were.
// @0x142933e20
void InvokeContext::Cleanup()
{
    ObjectInterface* passedThis = PassedThisObj.GetPtr();
    if (passedThis && passedThis->IsSuper())
        static_cast<SuperObject*>(passedThis)->ResetAltProto();

    if (!IsFunction2() || !(Function2Flags() & 0x02))
        SetLocalInline(pOurEnv, pOurEnv->GetBuiltin(ASBuiltin_this), Value());
    if (!IsFunction2() || !(Function2Flags() & 0x20))
        SetLocalInline(pOurEnv, pOurEnv->GetBuiltin(ASBuiltin_super), Value());

    SetLocalFrameTopInline(pOurEnv, LocalStackTop);

    if (IsFunction2())
        (pOurEnv->LocalRegister.*&LocalRegisterBase::Resize)(pOurEnv->LocalRegister.GetSize() - LocalRegisterCount());

    if (pOurEnv)
        pOurEnv->CallStack.Pop1();
}

// The button side of a character created from a button record: a class registered for the symbol's export name
// becomes the button's prototype and its constructor is queued, otherwise the lookup is queued for later.
class AvmButton : public AvmCharacter
{
    void ConstructCharacter(InteractiveObject* pchar, const ButtonRecord& rec);
};

// MS2-FUNCTIONAL: the queued entries are filled member by member in the exe's order
// @0x142935820
void AvmButton::ConstructCharacter(InteractiveObject* pchar, const ButtonRecord& rec)
{
    if (!(*reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pchar) + 0x6a) & 0x400))
        return;
    GlobalContext* pcontext = GetASEnvironment()->StringContext.pContext;
    const String*  pname    = pchar->GetResourceMovieDef()->GetNameOfExportedResource(rec.CharacterId);
    if (!pname)
        return;
    ASString         name = GetASEnvironment()->GetSC()->CreateString(pname->ToCStr(), pname->GetSize());
    FunctionRef      ctor;
    FunctionRef*     pfound = pcontext->RegisteredClasses.GetCaseCheck(name, GetASEnvironment()->IsCaseSensitive());
    MovieRoot*       proot  = GetAS2Root();
    if (!pfound)
    {
        Array<Value> args;
        args.PushBack(Value(name));
        MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
        if (pe)
        {
            pe->Type          = MovieRoot::ActionEntry::Entry_CFunction;
            pe->pCharacter    = pchar;
            pe->pActionBuffer = 0;
            pe->CFunction     = FUN_142943480;
            pe->FunctionParams = args;
        }
        return;
    }
    ctor = *pfound;
    AS2::ToAvmCharacter(pchar)->SetProtoToPrototypeOf(ctor.IsNull() ? 0 : static_cast<ObjectInterface*>(ctor.GetObjectPtr()));
    MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
    if (pe)
    {
        pe->Type          = MovieRoot::ActionEntry::Entry_Event;
        pe->pCharacter    = pchar;
        pe->pActionBuffer = 0;
        pe->mEventId      = EventId(EventId::Event_Construct);
    }
    pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
    if (pe)
    {
        pe->Type          = MovieRoot::ActionEntry::Entry_Function;
        pe->pCharacter    = pchar;
        pe->pActionBuffer = 0;
        pe->Function      = ctor;
    }
}

// RootArray::ClearAndRelease: frees the pages and the page table (the exe folds the identical paged-array
// destructors into this one body).
// @0x1429343f0
template<>
void RefCountCollector<StatMV_ActionScript_Mem>::RootArray::ClearAndRelease()
{
    reinterpret_cast<ArrayPagedLH_POD<unsigned, 6, 64, 2>*>(this)->~ArrayPagedLH_POD();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7SetFocusInvokeCallback@AS2@GFx@Scaleform@@6B@ 0x143221850
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
