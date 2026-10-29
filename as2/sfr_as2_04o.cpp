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

// MS2-FUNCTIONAL: the pushes are made through Push(), the exe builds each value in place
// @0x1429326a0
void Selection::BroadcastOnSetFocus(Environment* penv, InteractiveObject* pold, InteractiveObject* pnew,
                                    unsigned controllerIdx)
{
    Value selection;
    if (!penv->GetSC()->pContext->pGlobal->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_Selection),
                                                         &selection))
        return;
    Object* pobj = selection.ToObject(penv);
    if (!pobj)
        return;
    int nargs = 2;
    if (penv->CheckExtensions())
    {
        penv->Push(Value((double)controllerIdx));
        nargs = 3;
    }
    penv->Push(pnew ? Value(pnew) : Value(Value::NULLTYPE));
    penv->Push(pold ? Value(pold) : Value(Value::NULLTYPE));
    ASString eventName = penv->CreateConstString("onSetFocus");
    SetFocusInvokeCallback callback(nargs, penv->GetTopIndex());
    AsBroadcaster::BroadcastMessageWithCallback(penv, pobj, eventName, &callback);
    penv->Drop(nargs);
}

// MS2-FUNCTIONAL: the focus group's weak reference is resolved with Ptr assignment
// @0x142932ab0
void SelectionCtorFunction::CaptureFocus(const FnCall& fn)
{
    fn.Result->SetUndefined();
    bool enable = true;
    if (fn.NArgs >= 1)
        enable = fn.Arg(0).ToBool(fn.Env);
    MovieImpl* pmovie        = fn.Env->GetTarget()->GetMovieImpl();
    unsigned   controllerIdx = 0;
    if (fn.NArgs > 1)
        controllerIdx = fn.Arg(1).ToUInt32(fn.Env);
    Ptr<InteractiveObject> focused = pmovie->FocusGroups[pmovie->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (!focused)
    {
        FUN_14256bbf0(pmovie, controllerIdx);
        focused = pmovie->FocusGroups[pmovie->FocusGroupIndexes[controllerIdx]].LastFocused;
    }
    if (!enable)
        pmovie->HideFocusRect(controllerIdx);
    else
    {
        if (!focused)
            return;
        if (focused->IsFocusEnabled(GFx_FocusMovedByKeyboard))
            pmovie->SetKeyboardFocusTo(focused, controllerIdx, GFx_FocusMovedByKeyboard);
    }
    if (focused)
        fn.Result->SetAsCharacter(focused);
}

// The cursor of a mouse changed: with the extensions and a script replacement the Mouse.setCursorType handler is
// called, otherwise the host is asked to show the shape.
// MS2-FUNCTIONAL: the handler call is made through FunctionRef::Invoke
// @0x142933010
void MovieRoot::ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType)
{
    Environment* penv = 0;
    for (UPInt i = 0; i < pMovieImpl->MovieLevelsSize; ++i)
    {
        if (pMovieImpl->pMovieLevels[i].Level == 0)
        {
            penv = ToAvmCharacter(pMovieImpl->pMovieLevels[i].pSprite)->GetASEnvironment();
            break;
        }
    }
    if (!(pMovieImpl->Flags & MovieImpl::Flag_SetCursorTypeFuncOverloaded) || !penv->CheckExtensions())
    {
        if (newCursorType == *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(pMovieImpl) + 0x12a4 + mouseIdx * 0x50))
            return;
        if (UserEventHandler* phandler = pMovieImpl->pUserEventHandler)
            phandler->HandleEvent(reinterpret_cast<Movie*>(pMovieImpl), MouseCursorEvent(static_cast<MouseCursorEvent::CursorShapeType>(newCursorType), mouseIdx));
        return;
    }
    Value mouse;
    if (!penv->GetSC()->pContext->pGlobal->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_Mouse), &mouse))
        return;
    Object* pmouse = mouse.ToObject(penv);
    if (!pmouse)
        return;
    Value handler;
    if (!pmouse->GetMember(penv, penv->GetBuiltin(ASBuiltin_setCursorType), &handler))
        return;
    FunctionRef method = handler.ToFunction(penv);
    if (!method.IsNull())
    {
        penv->Push(Value((double)mouseIdx));
        penv->Push(Value((double)newCursorType));
        Value result;
        method.Invoke(FnCall(&result, static_cast<ObjectInterface*>(pmouse), penv, 2, penv->GetTopIndex()));
        penv->Drop(2);
    }
}

// _root, _global and _levelN before the scope chain's own lookup: 0 = not one of them, 1 = the value is set, 2 = a
// level name whose level does not exist.
// _root is the target's top parent (its own level, or the _lockroot clip), like the exe's virtual call.
// MS2-FUNCTIONAL
// @0x142933bd0
UByte* FUN_142933bd0(Environment* penv, UByte* pout, const Environment::GetVarParams& params)
{
    const ASString& name   = params.VarName;
    bool            cs     = penv->IsCaseSensitive();
    ASStringContext* psc   = penv->GetSC();
    InteractiveObject* pch = 0;
    if (psc->GetBuiltin(ASBuiltin__root).CompareBuiltIn_CaseCheck(name, cs))
        pch = penv->GetTarget()->GetTopParent();
    else if (psc->GetBuiltin(63).CompareBuiltIn_CaseCheck(name, cs)) // _global
    {
        params.pResult->SetAsObject(penv->StringContext.pContext->pGlobal);
        *pout = 1;
        return pout;
    }
    else
    {
        const char* ptail = 0;
        int level = MovieRoot::ParseLevelName(name.ToCStr(), &ptail, cs);
        if (level == -1 || *ptail != '\0')
        {
            *pout = 0;
            return pout;
        }
        pch = penv->GetAS2Root()->GetLevelMovie(level);
        if (!pch)
        {
            *pout = 2;
            return pout;
        }
    }
    params.pResult->SetAsCharacter(pch);
    *pout = 1;
    return pout;
}

// The invoked function's frame is left: the alternate prototype of a super call is dropped, this and super become
// undefined again in the caller's frame when the function did not take them, the locals and the call stack are
// back where they were.
// MS2-FUNCTIONAL: the context is not modelled, its fields are read by address
// @0x142933e20
void FUN_142933e20(void* pctx)
{
    UByte*       pc    = static_cast<UByte*>(pctx);
    UByte*       pfunc = *reinterpret_cast<UByte**>(pc);
    Environment* penv  = *reinterpret_cast<Environment**>(pc + 8);
    Object*      pobj  = *reinterpret_cast<Object**>(pc + 0x40);
    if (pobj && static_cast<ObjectInterface*>(pobj)->IsSuper())
        static_cast<SuperObject*>(pobj)->ResetAltProto();

    bool isFunc2 = pfunc[0xca] == 2;
    for (int i = 0; i < 2; ++i)
    {
        if (isFunc2 && (pfunc[0xc8] & (i ? 0x20 : 0x02)))
            continue;
        Value undef;
        if (penv->LocalFrames.GetSize() != 0 && penv->LocalFrames.Back())
        {
            const ASString& str = penv->GetBuiltin(i ? 62 : ASBuiltin_this);
            if (penv->FindLocal(str))
                penv->SetLocal(str, undef);
            else
                penv->AddLocal(str, undef);
        }
    }
    penv->LocalFrames.Resize(*reinterpret_cast<unsigned*>(pc + 0x50));
    if (isFunc2)
        penv->LocalRegister.Resize(penv->LocalRegister.GetSize() - pfunc[0xcb]);
    if (penv)
        penv->CallStack.Pop1();
}

// The button side of a character created from a button record: a class registered for the symbol's export name
// becomes the button's prototype and its constructor is queued, otherwise the lookup is queued for later.
class AvmButton : public AvmCharacter
{
public:
    void ConstructCharacter(InteractiveObject* pchar, const ButtonRecord* prec);
};

// MS2-FUNCTIONAL: the queued entries are filled member by member in the exe's order
// @0x142935820
void AvmButton::ConstructCharacter(InteractiveObject* pchar, const ButtonRecord* prec)
{
    if (!(*reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pchar) + 0x6a) & 0x400))
        return;
    GlobalContext* pcontext = GetASEnvironment()->StringContext.pContext;
    const String*  pname    = pchar->GetResourceMovieDef()->GetNameOfExportedResource(prec->CharacterId);
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

// The destructor of a paged array of unsigned (the exe folds the identical instantiations into one).
// @0x1429343f0
void FUN_1429343f0(ArrayPagedLH_POD<unsigned, 6, 64, 2>* parray)
{
    parray->~ArrayPagedLH_POD();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7SetFocusInvokeCallback@AS2@GFx@Scaleform@@6B@ 0x143221850
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
