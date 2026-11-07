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

// The frame barrier grows the frame array out of line (0x14297e450, as in sfr_as2_04n).
namespace Scaleform {
template<> void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                              ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// The state of one script function call (the class of sfr_as2_06b, where AsFunctionObject::Invoke uses it).
class InvokeContext
{
public:
    AsFunctionObject*      pThis;         // +0x00
    Environment*           pOurEnv;       // +0x08 the environment the body runs in
    const FnCall&          mFnCall;       // +0x10
    LocalFrame*            pLocalFrame;   // +0x18
    const char*            pMethodName;   // +0x20
    Ptr<InteractiveObject> TargetCh;      // +0x28
    Ptr<InteractiveObject> FnEnvCh;       // +0x30
    Ptr<InteractiveObject> PassedThisCh;  // +0x38
    Ptr<Object>            PassedThisObj; // +0x40
    Ptr<LocalFrame>        CurLocalFrame; // +0x48
    int                    LocalStackTop; // +0x50

    InvokeContext(AsFunctionObject* pthis, const FnCall& fn, LocalFrame* plocalFrame, const char* pmethodName)
        : pThis(pthis), mFnCall(fn), pLocalFrame(plocalFrame), pMethodName(pmethodName)
    {
    }

    void Setup();
    void Cleanup();
};

namespace {

// The execution types of a function body (ActionBuffer::ExecuteType).
const UByte Exec_Function  = 1;
const UByte Exec_Function2 = 2;

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

    // ArrayLH<ArgSpec>::operator[] and GetSize.
    SF_FORCEINLINE ArgDescr& At(UPInt index) { return pArgs[index]; }
    SF_FORCEINLINE UPInt     GetSize() const { return ArgCount; }
};

SF_FORCEINLINE FunctionArgsView* ArgsOf(AsFunctionObject* pfunc)
{
    return reinterpret_cast<FunctionArgsView*>(reinterpret_cast<UByte*>(pfunc) + 0xa0);
}
// PagedStack::Push.
SF_FORCEINLINE void StackPush(PagedStack<Ptr<FunctionObject>, 32>* stack, const Ptr<FunctionObject>& val)
{
    stack->pCurrent++;
    if (stack->pCurrent >= stack->pPageEnd)
        stack->PushPage();
    Construct<Ptr<FunctionObject> >(stack->pCurrent, val);
}

// Environment::CallPush.
SF_FORCEINLINE void CallPush(Environment* penv, const FunctionObject* pfuncObj)
{
    StackPush(&penv->CallStack, Ptr<FunctionObject>(const_cast<FunctionObject*>(pfuncObj)));
}
SF_FORCEINLINE bool IsFunction2(AsFunctionObject* pfunc) { return ArgsOf(pfunc)->ExecType == Exec_Function2; }

typedef ArrayBase<ArrayData<Value, AllocatorLH<Value, Stat_Default_Mem>, ArrayDefaultPolicy> > LocalRegisterBase;

// Environment::AddLocalRegisters; the exe calls the register array's Resize (0x14297e0e0) out of line.
SF_FORCEINLINE void AddLocalRegisters(Environment* penv, unsigned count)
{
    (penv->LocalRegister.*&LocalRegisterBase::Resize)(penv->LocalRegister.GetSize() + count);
}

// Environment::LocalRegisterPtr (exe 0x14296f2d0 out of line), which the exe inlines here.
SF_FORCEINLINE Value* LocalRegisterPtr(Environment* penv, unsigned reg)
{
    if (reg >= penv->LocalRegister.GetSize())
    {
        penv->LogError("Invalid local register %d, stack only has %d entries", reg, (int)penv->LocalRegister.GetSize());
        return &penv->GlobalRegister[0];
    }
    return &penv->LocalRegister[penv->LocalRegister.GetSize() - reg - 1];
}

// PagedStack::TopIndex and Top(offset).
SF_FORCEINLINE unsigned StackTopIndex(const PagedStack<Ptr<FunctionObject>, 32>& stack)
{
    return (((unsigned)stack.Pages.GetSize() - 1) * 32) + (unsigned)(stack.pCurrent - stack.pPageStart);
}
SF_FORCEINLINE Ptr<FunctionObject>* StackTop(const PagedStack<Ptr<FunctionObject>, 32>& stack, unsigned offset)
{
    Ptr<FunctionObject>* p        = 0;
    unsigned             topIndex = StackTopIndex(stack);

    if (offset <= topIndex)
    {
        const unsigned absidx  = topIndex - offset;
        const unsigned pageidx = absidx / 32;
        const unsigned idx     = absidx % 32;
        p = &stack.Pages[pageidx]->Values[idx];
    }
    return p;
}

// Environment::CallTop: the call stack entry at a distance from the top, null past the bottom.
SF_FORCEINLINE Value CallTop(Environment* penv, int off)
{
    if (StackTopIndex(penv->CallStack) < (unsigned)off)
        return Value(Value::NULLTYPE);
    else
        return Value(static_cast<Object*>(StackTop(penv->CallStack, off)->GetPtr()));
}

// ObjectInterface::ToASObject, which the exe inlines here.
SF_FORCEINLINE Object* ToASObjectInline(ObjectInterface* pobj)
{
    return pobj->IsASObject() ? static_cast<Object*>(pobj) : 0;
}

// ObjectInterface::FindOwner, which the exe inlines here.
SF_FORCEINLINE Object* FindOwnerInline(ObjectInterface* pobj, ASStringContext* psc, const ASString& name)
{
    for (ObjectInterface* proto = pobj; proto != 0; proto = proto->Get__proto__())
    {
        if (proto->HasMember(psc, name, false))
            return static_cast<Object*>(proto);
    }
    return NULL;
}

// Ptr::operator=(C*), which the exe inlines here.
SF_FORCEINLINE void AssignPtrInline(Ptr<InteractiveObject>& dst, InteractiveObject* psrc)
{
    InteractiveObject*& pobj = reinterpret_cast<InteractiveObject*&>(dst);
    if (psrc) psrc->AddRef();
    if (pobj) pobj->Release();
    pobj = psrc;
}

// Value::SetAsCharacter and SetAsObjectInterface, which the exe inlines for the this local of a function2.
SF_FORCEINLINE void SetAsCharacterInline(Value& v, InteractiveObject* pch)
{
    CharacterHandle* phandle = pch ? pch->GetCharacterHandle() : 0;
    if (v.T.Type != Value::CHARACTER || v.V.pCharHandle != phandle)
    {
        v.DropRefs();
        v.T.Type        = Value::CHARACTER;
        v.V.pCharHandle = phandle;
        if (phandle)
            phandle->AddRef();
    }
}
SF_FORCEINLINE void SetAsObjectInterfaceInline(Value& v, ObjectInterface* pobj)
{
    if (pobj->IsASCharacter())
        SetAsCharacterInline(v, pobj->ToCharacter());
    else
        v.SetAsObject(ToASObjectInline(pobj));
}

} // namespace

// MS2-FUNCTIONAL: SDK body at equal length 3881; the exe keeps the first plain-function argument loop's
// Args[i] index unreduced (movsxd/shl per pass) and orders two Args[i].Register base+index operands the other way.
// @0x14298dee0
void InvokeContext::Setup()
{
    CallPush(pOurEnv, pThis);

    // 'this' can differ from the scope the function was declared in; it comes with the call.
    ObjectInterface* pthis = mFnCall.ThisPtr;

    MemoryHeap* pheap = pOurEnv->GetHeap();

    // The local frame for the parameters and locals.
    LocalStackTop = (int)pOurEnv->LocalFrames.GetSize();

    if (IsFunction2(pThis) || (ArgsOf(pThis)->ExecType == Exec_Function))
    {
        CurLocalFrame            = pOurEnv->CreateNewLocalFrame();
        CurLocalFrame->PrevFrame = pLocalFrame;
    }
    else
        pOurEnv->LocalFrames.PushBack(0);

    ObjectInterface* passedThis = pthis;
    // The passed this is held for the call.
    if (passedThis)
    {
        PassedThisCh  = passedThis->ToCharacter();
        PassedThisObj = ToASObjectInline(passedThis);
    }

    if (pthis && pthis->IsSuper())
        pthis = static_cast<SuperObject*>(pthis)->RealThis;

    if (!IsFunction2(pThis))
    {
        int i;
        int version = pOurEnv->GetVersion();

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
        if (CurLocalFrame && mFnCall.Env && version >= 5)
        {
            if (pOurEnv != mFnCall.Env)
                AssignPtrInline(FnEnvCh, mFnCall.Env->GetTarget());
            CurLocalFrame->Env                 = mFnCall.Env;
            CurLocalFrame->NArgs               = mFnCall.NArgs;
            CurLocalFrame->FirstArgBottomIndex = mFnCall.FirstArgBottomIndex;
            CurLocalFrame->Callee              = CallTop(pOurEnv, 0);
            CurLocalFrame->Caller              = CallTop(pOurEnv, 1);
        }

        int ArgsToPass = Alg::Min<int>(mFnCall.NArgs, (int)ArgsOf(pThis)->GetSize());
        for (i = 0; i < ArgsToPass; i++)
            pOurEnv->AddLocal(ArgsOf(pThis)->At(i).Name, mFnCall.Arg(i));
        // The missing arguments are undefined.
        for (int n = (int)ArgsOf(pThis)->GetSize(); i < n; i++)
            pOurEnv->AddLocal(ArgsOf(pThis)->At(i).Name, Value());
    }
    else
    {
        // function2: arguments with a register go there, the others become locals.
        AddLocalRegisters(pOurEnv, ArgsOf(pThis)->LocalRegisterCount);

        int ArgsToPass = Alg::Min<int>(mFnCall.NArgs, (int)ArgsOf(pThis)->GetSize());
        int i;
        for (i = 0; i < ArgsToPass; i++)
        {
            if (ArgsOf(pThis)->At(i).Register == 0)
                pOurEnv->AddLocal(ArgsOf(pThis)->At(i).Name, mFnCall.Arg(i));
            else
            {
                int reg = ArgsOf(pThis)->At(i).Register;
                *(LocalRegisterPtr(pOurEnv, reg)) = mFnCall.Arg(i);
            }
        }
        for (int n = (int)ArgsOf(pThis)->GetSize(); i < n; i++)
        {
            if (ArgsOf(pThis)->At(i).Register == 0)
                pOurEnv->AddLocal(ArgsOf(pThis)->At(i).Name, Value());
        }

        // super: the prototype above the one owning the called method, with the real this and that prototype's
        // constructor.
        Ptr<SuperObject> superObj;
        if ((ArgsOf(pThis)->Function2Flags & 0x10) || !(ArgsOf(pThis)->Function2Flags & 0x20))
        {
            Ptr<Object> proto = passedThis->Get__proto__();
            if (proto)
            {
                if (pMethodName)
                {
                    Ptr<Object> newProto =
                        FindOwnerInline(proto, pOurEnv->GetSC(), pOurEnv->CreateString(pMethodName));
                    if (newProto)
                        proto = newProto;
                }
                FunctionRef __ctor__ = proto->Get__constructor__(pOurEnv->GetSC());
                superObj = *SF_HEAP_NEW(pheap) SuperObject(proto->Get__proto__(), pthis, __ctor__);
            }
        }

        // The implicit arguments.
        int CurrentReg = 1;
        if (ArgsOf(pThis)->Function2Flags & 0x01)
        {
            if (pthis)
                (*(LocalRegisterPtr(pOurEnv, CurrentReg))).SetAsObjectInterface(pthis);
            else
                (*(LocalRegisterPtr(pOurEnv, CurrentReg))).SetUndefined();
            CurrentReg++;
        }

        if (ArgsOf(pThis)->Function2Flags & 0x02)
        {
            // No this local.
        }
        else
        {
            Value pthisVal;
            if (pthis) SetAsObjectInterfaceInline(pthisVal, pthis);
            pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_this), pthisVal);
        }

        // The arguments array, when it is going to be used.
        Ptr<ArrayObject> pargArray;
        if ((ArgsOf(pThis)->Function2Flags & 0x04) || !(ArgsOf(pThis)->Function2Flags & 0x08))
        {
            pargArray = *SF_HEAP_NEW(pheap) ArrayObject(pOurEnv);
            pargArray->Resize(mFnCall.NArgs);
            for (int i = 0; i < mFnCall.NArgs; i++)
                pargArray->SetElement(i, mFnCall.Arg(i));
        }

        if (ArgsOf(pThis)->Function2Flags & 0x04)
        {
            (*(LocalRegisterPtr(pOurEnv, CurrentReg))).SetAsObject(pargArray.GetPtr());
            CurrentReg++;
        }

        if (ArgsOf(pThis)->Function2Flags & 0x08)
        {
            // No arguments local.
        }
        else
        {
            pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_arguments), Value(pargArray.GetPtr()));
            pargArray->SetMemberRaw(pOurEnv->GetSC(), pOurEnv->GetBuiltin(ASBuiltin_callee), CallTop(pOurEnv, 0),
                PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_ReadOnly);
            pargArray->SetMemberRaw(pOurEnv->GetSC(), pOurEnv->GetBuiltin(ASBuiltin_caller), CallTop(pOurEnv, 1),
                PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_ReadOnly);
        }

        if (ArgsOf(pThis)->Function2Flags & 0x10)
        {
            (*(LocalRegisterPtr(pOurEnv, CurrentReg))).SetAsObject(superObj);
            CurrentReg++;
        }

        if (ArgsOf(pThis)->Function2Flags & 0x20)
        {
            // No super local.
        }
        else
        {
            Value superVal;
            superVal.SetAsObject(superObj);
            pOurEnv->AddLocal(pOurEnv->GetBuiltin(ASBuiltin_super), superVal);
        }

        if (ArgsOf(pThis)->Function2Flags & 0x40)
        {
            SetAsCharacterInline(*(LocalRegisterPtr(pOurEnv, CurrentReg)), pOurEnv->GetTarget()->GetTopParent());
            CurrentReg++;
        }

        if (ArgsOf(pThis)->Function2Flags & 0x80)
        {
            Value parent;
            pOurEnv->GetVariable(pOurEnv->GetBuiltin(ASBuiltin__parent), &parent);
            (*(LocalRegisterPtr(pOurEnv, CurrentReg))) = parent;
            CurrentReg++;
        }

        if (ArgsOf(pThis)->Function2Flags & 0x100)
        {
            (*(LocalRegisterPtr(pOurEnv, CurrentReg))).SetAsObject(pOurEnv->StringContext.pContext->pGlobal);
            CurrentReg++;
        }
    }
}

}}} // namespace Scaleform::GFx::AS2
