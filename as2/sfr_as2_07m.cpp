// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the entry into a script function: its call stack entry and local frame, the arguments as locals or registers,
// and this / super / arguments / _root / _parent / _global as the function asked for them.
// MS2-UNIT: sfr_as2_07m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298dee0-0x14298ee09 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The state of one script function call (the class of sfr_as2_06b, where AsFunctionObject::Invoke uses it).
class InvokeContext
{
public:
    AsFunctionObject*      pThis;         // +0x00
    Environment*           pOurEnv;       // +0x08 the environment the body runs in
    const FnCall&          Fn;            // +0x10
    LocalFrame*            pLocalFrame;   // +0x18
    const char*            pMethodName;   // +0x20
    Ptr<InteractiveObject> TargetCh;      // +0x28
    Ptr<InteractiveObject> FnEnvCh;       // +0x30
    Ptr<InteractiveObject> PassedThisCh;  // +0x38
    Ptr<Object>            PassedThisObj; // +0x40
    Ptr<LocalFrame>        CurLocalFrame; // +0x48
    int                    LocalStackTop; // +0x50

    InvokeContext(AsFunctionObject* pthis, const FnCall& fn, LocalFrame* plocalFrame, const char* pmethodName)
        : pThis(pthis), Fn(fn), pLocalFrame(plocalFrame), pMethodName(pmethodName)
    {
    }

    void Setup();
    void Cleanup();
};

namespace {

// The builtin names ASBuiltinType does not name yet.
const int Builtin_callee = 69;
const int Builtin_caller = 70;

// The execution types of a function body (ActionBuffer::ExecuteType).
const UByte Exec_Function  = 1;
const UByte Exec_Function2 = 2;

// The DefineFunction2 flags: preload into a register, or suppress the local variable.
const UInt16 F2_PreloadThis      = 0x001;
const UInt16 F2_SuppressThis     = 0x002;
const UInt16 F2_PreloadArguments = 0x004;
const UInt16 F2_SuppressArgs     = 0x008;
const UInt16 F2_PreloadSuper     = 0x010;
const UInt16 F2_SuppressSuper    = 0x020;
const UInt16 F2_PreloadRoot      = 0x040;
const UInt16 F2_PreloadParent    = 0x080;
const UInt16 F2_PreloadGlobal    = 0x100;

// A declared argument: a register (function2 only) or 0 for a local variable of that name.
struct ArgDescr
{
    unsigned Register; // +0x00
    ASString Name;     // +0x08
};

// The members of AsFunctionObject past +0xa0 that the call setup reads.
struct FunctionArgsView
{
    ArgDescr* pArgs;              // +0xa0
    UPInt     ArgCount;           // +0xa8
    UByte     Unrecovered_b0[0x18];
    UInt16    Function2Flags;     // +0xc8
    UByte     ExecType;           // +0xca
    UByte     LocalRegisterCount; // +0xcb
};

inline FunctionArgsView* ArgsOf(AsFunctionObject* pfunc)
{
    return reinterpret_cast<FunctionArgsView*>(reinterpret_cast<UByte*>(pfunc) + 0xa0);
}

// The call stack entry from the top (the running function is 0) as a value; undefined past the bottom.
inline Value CallTopValue(Environment* penv, unsigned dist)
{
    Ptr<FunctionObject>* pentry = penv->CallStack.Top(dist);
    if (!pentry)
        return Value();
    return Value(static_cast<Object*>(pentry->GetPtr()));
}

} // namespace

// MS2-FUNCTIONAL: the exe inlines LocalRegisterPtr, ToASObject and FindOwner and frees the temporaries in a
// different order; same behavior
// @0x14298dee0
void InvokeContext::Setup()
{
    pOurEnv->CallStack.Push(Ptr<FunctionObject>(pThis));

    FunctionArgsView* pargs      = ArgsOf(pThis);
    ObjectInterface*  passedThis = Fn.ThisPtr;
    MemoryHeap*       pheap      = pOurEnv->GetHeap();

    LocalStackTop = (int)pOurEnv->LocalFrames.GetSize();
    if (pargs->ExecType == Exec_Function || pargs->ExecType == Exec_Function2)
    {
        CurLocalFrame             = pOurEnv->CreateNewLocalFrame();
        CurLocalFrame->PrevFrame  = pLocalFrame;
    }
    else
        pOurEnv->LocalFrames.PushBack(Ptr<LocalFrame>()); // a barrier: no frame of its own

    // The passed this is held for the call; a super call runs on the real this.
    ObjectInterface* pthis = passedThis;
    if (passedThis)
    {
        PassedThisCh  = passedThis->ToCharacter();
        PassedThisObj = passedThis->ToASObject();
        if (passedThis->IsSuper())
            pthis = static_cast<SuperObject*>(passedThis)->RealThis;
    }

    if (pargs->ExecType != Exec_Function2)
    {
        unsigned version = pOurEnv->GetVersion();
        if (pthis)
        {
            Value thisVal;
            thisVal.SetAsObjectInterface(pthis);
            pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_this), thisVal);
        }
        // super of a plain function is made when it is asked for, from what the frame keeps.
        if (version >= 6 && CurLocalFrame)
            CurLocalFrame->SuperThis = passedThis;
        // So are the arguments: the frame keeps where they are on the caller's stack.
        if (CurLocalFrame && Fn.Env && version >= 5)
        {
            if (pOurEnv != Fn.Env)
                FnEnvCh = Fn.Env->GetTarget();
            CurLocalFrame->Env                 = Fn.Env;
            CurLocalFrame->NArgs               = Fn.NArgs;
            CurLocalFrame->FirstArgBottomIndex = Fn.FirstArgBottomIndex;
            CurLocalFrame->Callee              = CallTopValue(pOurEnv, 0);
            CurLocalFrame->Caller              = CallTopValue(pOurEnv, 1);
        }

        int nargs = Alg::Min<int>(Fn.NArgs, (int)pargs->ArgCount);
        int i;
        for (i = 0; i < nargs; ++i)
            pOurEnv->AddLocal(pargs->pArgs[i].Name, Fn.Arg(i));
        for (; i < (int)pargs->ArgCount; ++i)
            pOurEnv->AddLocal(pargs->pArgs[i].Name, Value());
        return;
    }

    // function2: arguments with a register go there, the others become locals.
    pOurEnv->LocalRegister.Resize(pOurEnv->LocalRegister.GetSize() + pargs->LocalRegisterCount);
    int nargs = Alg::Min<int>(Fn.NArgs, (int)pargs->ArgCount);
    int i;
    for (i = 0; i < nargs; ++i)
    {
        if (pargs->pArgs[i].Register == 0)
            pOurEnv->AddLocal(pargs->pArgs[i].Name, Fn.Arg(i));
        else
            *pOurEnv->LocalRegisterPtr(pargs->pArgs[i].Register) = Fn.Arg(i);
    }
    for (; i < (int)pargs->ArgCount; ++i)
    {
        if (pargs->pArgs[i].Register == 0)
            pOurEnv->AddLocal(pargs->pArgs[i].Name, Value());
    }

    const UInt16 flags = pargs->Function2Flags;

    // super: the prototype above the one owning the called method, with the real this and that prototype's
    // constructor.
    Ptr<SuperObject> superObj;
    if ((flags & F2_PreloadSuper) || !(flags & F2_SuppressSuper))
    {
        Ptr<Object> proto = passedThis->Get__proto__();
        if (proto)
        {
            if (pMethodName)
            {
                Ptr<Object> owner = proto->FindOwner(&pOurEnv->StringContext, pOurEnv->CreateString(pMethodName));
                if (owner)
                    proto = owner;
            }
            FunctionRef ctor = proto->Get__constructor__(&pOurEnv->StringContext);
            superObj         = *SF_HEAP_NEW(pheap) SuperObject(proto->Get__proto__(), pthis, ctor);
        }
    }

    unsigned reg = 1;
    if (flags & F2_PreloadThis)
    {
        if (pthis)
            pOurEnv->LocalRegisterPtr(reg)->SetAsObjectInterface(pthis);
        else
            pOurEnv->LocalRegisterPtr(reg)->SetUndefined();
        ++reg;
    }
    if (!(flags & F2_SuppressThis))
    {
        Value thisVal;
        if (pthis)
            thisVal.SetAsObjectInterface(pthis);
        pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_this), thisVal);
    }

    Ptr<ArrayObject> pargArray;
    if ((flags & F2_PreloadArguments) || !(flags & F2_SuppressArgs))
    {
        pargArray = *SF_HEAP_NEW(pheap) ArrayObject(pOurEnv);
        pargArray->Resize(Fn.NArgs);
        for (int n = 0; n < Fn.NArgs; ++n)
            pargArray->SetElement(n, Fn.Arg(n));
    }
    if (flags & F2_PreloadArguments)
    {
        pOurEnv->LocalRegisterPtr(reg)->SetAsObject(pargArray);
        ++reg;
    }
    if (!(flags & F2_SuppressArgs))
    {
        pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_arguments), Value(pargArray.GetPtr()));
        const PropFlags hidden(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete |
                               PropFlags::PropFlag_ReadOnly);
        pargArray->SetMemberRaw(&pOurEnv->StringContext, pOurEnv->GetBuiltin(Builtin_callee),
                                CallTopValue(pOurEnv, 0), hidden);
        pargArray->SetMemberRaw(&pOurEnv->StringContext, pOurEnv->GetBuiltin(Builtin_caller),
                                CallTopValue(pOurEnv, 1), hidden);
    }

    if (flags & F2_PreloadSuper)
    {
        pOurEnv->LocalRegisterPtr(reg)->SetAsObject(superObj);
        ++reg;
    }
    if (!(flags & F2_SuppressSuper))
    {
        Value superVal;
        superVal.SetAsObject(superObj);
        pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_super), superVal);
    }

    if (flags & F2_PreloadRoot)
    {
        pOurEnv->LocalRegisterPtr(reg)->SetAsCharacter(pOurEnv->GetTarget()->GetTopParent());
        ++reg;
    }
    if (flags & F2_PreloadParent)
    {
        Value parent;
        pOurEnv->GetVariable(pOurEnv->GetBuiltin(ASBuiltin__parent), &parent);
        *pOurEnv->LocalRegisterPtr(reg) = parent;
        ++reg;
    }
    if (flags & F2_PreloadGlobal)
        pOurEnv->LocalRegisterPtr(reg)->SetAsObject(pOurEnv->StringContext.pContext->pGlobal);
}

}}} // namespace Scaleform::GFx::AS2
