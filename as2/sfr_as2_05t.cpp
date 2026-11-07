// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the class and function opcodes of the action interpreter (extends, function, function2).
// MS2-UNIT: sfr_as2_05t
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142941680-0x142941b39 .text$mn
// MS2-RANGE: 0x142945da0-0x14294638b .text$mn
// MS2-RANGE: 0x142946390-0x1429469c5 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/kernel/sf_array.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// An allocation of Size bytes from pHeap, for an object larger than its modelled class.
struct FunctionOpSizedAlloc
{
    MemoryHeap* pHeap;
    UPInt       Size;
};

}}} // namespace Scaleform::GFx::AS2

#pragma warning(disable : 4291) // no matching delete: the exe frees nothing if the ctor throws
inline void* operator new(size_t, Scaleform::GFx::AS2::FunctionOpSizedAlloc a)
{
    return a.pHeap->Alloc(a.Size);
}

namespace Scaleform { namespace GFx { namespace AS2 {

struct ExtendsLocalFrameInlineTag {};

// FunctionProto(psc, pprototype, constructor, false) (exe 0x14291c0f0), inlined in the function opcodes.
__forceinline FunctionProto::FunctionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor,
                                           Prototype<Object>::InlineCtorTag)
    : Prototype<Object>(psc, pprototype, constructor, Prototype<Object>::InlineCtorTag())
{
}

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it in the extends opcode.
static SF_FORCEINLINE void ExtendsFunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded.
template<>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, ExtendsLocalFrameInlineTag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        ExtendsFunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// Environment::Top() / Top1() as the SDK writes them (PagedStack::Top0 / Top1).
static SF_FORCEINLINE Value& ExtendsTop0(Environment* penv)
{
    return *penv->Stack.pCurrent;
}
static SF_FORCEINLINE Value& ExtendsTop1(Environment* penv)
{
    PagedStack<Value, 32>& st = penv->Stack;
    return *((st.pCurrent > st.pPageStart) ? (st.pCurrent - 1) : st.pPrevPageTop);
}

// ObjectProto(psc, pprototype) (exe 0x14291fa90), inlined in the extends opcode down to the Object ctor call.
__forceinline ObjectProto::ObjectProto(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Prototype<Object>(psc, pprototype, Prototype<Object>::InlineCtorTag())
{
}

// Value::ToFunction as the SDK writes it (a switch), with the copy above.
struct ExtendsValueAccess : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef ExtendsValueToFunction(const Value& v, const Environment* penv)
{
    switch (v.GetType())
    {
    case Value::FUNCTIONNAME:
        return static_cast<const ExtendsValueAccess&>(v).ResolveFunctionName(penv);
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, ExtendsLocalFrameInlineTag());
    default:;
    }
    return FunctionRef();
}

// The 'extends' opcode (ExecutionContext::ExtendsOpCode; the context is not modelled: +0 the environment, +0x40 the
// logger, +0x62 the verbose flag): the subclass below the superclass on top gets a new prototype whose __proto__ is
// the superclass prototype and whose __constructor__ is the superclass.
// MS2-FUNCTIONAL: the exe keeps the LTCG-inlined ToFunction FunctionRef in registers and re-reads pEnv from the context at each use
// @0x142941680
void FUN_142941680(void* pctx)
{
    UByte*        pc   = static_cast<UByte*>(pctx);
    Environment*  penv = *reinterpret_cast<Environment**>(pc);
    ActionLogger* plog = reinterpret_cast<ActionLogger*>(pc + 0x40);

    Value       superClassCtorVal = ExtendsTop0(penv);
    Value       subClassCtorVal   = ExtendsTop1(penv);
    FunctionRef superClassCtor    = ExtendsValueToFunction(superClassCtorVal, penv);
    FunctionRef subClassCtor      = ExtendsValueToFunction(subClassCtorVal, penv);
    if (!superClassCtor.IsNull() && !subClassCtor.IsNull())
    {
        Value superProtoVal;
        if (!superClassCtor->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &superProtoVal) ||
            !superProtoVal.IsObject())
        {
            if (pc[0x62] & 1)
                plog->LogScriptError("can't extend by the class w/o prototype.");
        }
        else
        {
            Ptr<Object>      superProto = superProtoVal.ToObject(penv);
            // An ObjectProto, so that implements and instanceof see the class.
            Ptr<ObjectProto> newSubclassProto =
                *SF_HEAP_NEW(penv->GetHeap()) ObjectProto(penv->GetSC(), superProto, ObjectInlineCtorTag());
            subClassCtor->SetPrototype(penv->GetSC(), newSubclassProto);
            newSubclassProto->Set__constructor__(penv->GetSC(), superClassCtor);
        }
    }
    else if (pc[0x62] & 1)
    {
        if (superClassCtor.IsNull())
            plog->LogScriptError("Can't extend with unknown super class.");
        else
            plog->LogScriptError("Can't extend the unknown class.");
    }
    penv->Drop2();
}

namespace {

// An argument of a script function: its register (function2) and name.
struct FnArgSpec
{
    int      Register; // +0
    ASString Name;     // +8
};

// The members of AsFunctionObject past +0x78 that the definition fills (as AsFunctionBody of sfr_as2_06b).
struct FnDefBody
{
    void*                       pActionBuffer;      // +0x78
    UByte                       WithStack[0x18];    // +0x80
    unsigned                    StartPc;            // +0x98
    unsigned                    Length;             // +0x9c
    ArrayCC<FnArgSpec, StatMV_ActionScript_Mem> Args; // +0xa0
    UInt16                      Function2Flags;     // +0xc8
    UByte                       ExecType;           // +0xca
    UByte                       LocalRegisterCount; // +0xcb
};

inline FnDefBody* BodyOf(AsFunctionObject* pfunc)
{
    return reinterpret_cast<FnDefBody*>(reinterpret_cast<UByte*>(pfunc) + 0x78);
}

// AsFunctionObject::AddArg (inlined in the exe).
inline FnArgSpec& AddArg(AsFunctionObject* pfunc, int argRegister, const ASString& name)
{
    ArrayCC<FnArgSpec, StatMV_ActionScript_Mem>& args = BodyOf(pfunc)->Args;
    UPInt newSize = args.GetSize() + 1;
    _ReadWriteBarrier();
    args.Resize(newSize);
    FnArgSpec& arg = args.Back();
    arg.Register   = argRegister;
    arg.Name       = name;
    return arg;
}

// The common tail of both definitions: the function is stored on the target under its name (or left on the stack
// when anonymous), with a fresh prototype whose constructor is the function.
// GlobalContext::GetPrototype (out of line at exe 0x142954ba0), inlined here as the exe has it.
SF_FORCEINLINE Object* FnGetPrototype(GlobalContext* pgc, ASBuiltinType type)
{
    Ptr<Object>* presult = pgc->Prototypes.Get(type);
    if (!presult)
    {
        pgc->ResolveFunctionName(static_cast<MovieRoot*>(pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(type));
        presult = pgc->Prototypes.Get(type);
    }
    return presult ? presult->GetPtr() : 0;
}

// Environment::GetTopLocalFrame(0) (exe 0x142956740), GetAvmTarget and FunctionObject::SetPrototype (sfr_as2_07),
// inlined here in the exe.
SF_FORCEINLINE LocalFrame* FnTopLocalFrame(const Environment* penv)
{
    if (penv->LocalFrames.GetSize() > 0)
        return penv->LocalFrames[penv->LocalFrames.GetSize() - 1];
    return 0;
}
// FunctionRefBase::SetLocalFrame(frame, false) as the function opcodes expand it: no weak flag to clear.
SF_FORCEINLINE void FnSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}
SF_FORCEINLINE AvmCharacter* FnAvmTarget(const Environment* penv)
{
    if (!penv->Target)
        return 0;
    return ToAvmCharacter(penv->Target);
}
SF_FORCEINLINE void FnSetPrototype(FunctionObject* pfunc, ASStringContext* psc, Object* pprototype)
{
    pfunc->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), Value(pprototype));
}

SF_FORCEINLINE void PublishFunction(Environment* const& penv, Ptr<AsFunctionObject>& funcObj, const ASString& name)
{
    FunctionRef funcRef(funcObj.GetPtr());
    if (LocalFrame* plocalFrame = FnTopLocalFrame(penv))
        FnSetLocalFrame(&funcRef, plocalFrame);

    Value functionValue(funcRef);
    if (name.GetSize() != 0)
        FnAvmTarget(penv)->SetMemberRaw(penv->GetSC(), name, functionValue);

    ASStringContext*   psc = penv->GetSC();
    Ptr<FunctionProto> funcProto =
        *SF_HEAP_NEW(psc->GetHeap()) FunctionProto(psc, FnGetPrototype(psc->pContext, ASBuiltin_Object), funcRef, Prototype<Object>::InlineCtorTag());
    funcRef->SetProtoAndCtor(psc, FnGetPrototype(psc->pContext, ASBuiltin_Function));
    FnSetPrototype(funcObj, psc, funcProto);

    if (name.GetSize() == 0)
        penv->Push(functionValue);
}

} // namespace

// The 'function' opcode (ExecutionContext::Function1OpCode; the context is not modelled: +0 the environment, +0x10
// the code bytes, +0x24 the next pc, +0x28 the pc, +0x38 the with stack): name, argument names and body length;
// the body is skipped.
// MS2-FUNCTIONAL: AddArg, the FunctionProto tag ctor, GetPrototype and SetPrototype are inlined as in the exe; the frame is 0x20 larger and r12/r13 and the zero register are allocated differently
// in the exe
// @0x142945da0
void FUN_142945da0(void* pctx, ActionBuffer* pactions)
{
    UByte*       pc      = static_cast<UByte*>(pctx);
    Environment*&       penv    = *reinterpret_cast<Environment**>(pc);
    const UByte*&       pbuffer = *reinterpret_cast<const UByte**>(pc + 0x10);
    unsigned&    nextPc  = *reinterpret_cast<unsigned*>(pc + 0x24);

    // The function object is 0xd0 bytes in the exe; the header models only its first 0x78.
    Ptr<AsFunctionObject> funcObj = *::new (FunctionOpSizedAlloc{penv->GetHeap(), 0xd0})
        AsFunctionObject(penv, pactions, nextPc, 0, *reinterpret_cast<void**>(pc + 0x38), 1);

    int i = *reinterpret_cast<int*>(pc + 0x28) + 3;
    ASString name = penv->CreateString(reinterpret_cast<const char*>(&pbuffer[i]));
    i += (int)name.GetSize() + 1;

    int nargs = pbuffer[i] | (pbuffer[i + 1] << 8);
    i += 2;
    for (int n = 0; n < nargs; n++)
    {
        ASString argstr(penv->CreateString(reinterpret_cast<const char*>(&pbuffer[i])));
        i += (int)AddArg(funcObj, 0, argstr).Name.GetSize() + 1;
    }

    int length = pbuffer[i] | (pbuffer[i + 1] << 8);
    BodyOf(funcObj)->Length = length;
    nextPc += length;

    PublishFunction(penv, funcObj, name);
}

// The 'function2' opcode (ExecutionContext::Function2OpCode, the context as in FUN_142945da0): as 'function' with
// the register count, the flags of the implicit arguments and a register per argument.
// MS2-FUNCTIONAL: as FUN_142945da0
// @0x142946390
void FUN_142946390(void* pctx, ActionBuffer* pactions)
{
    UByte*       pc      = static_cast<UByte*>(pctx);
    Environment*&       penv    = *reinterpret_cast<Environment**>(pc);
    const UByte*&       pbuffer = *reinterpret_cast<const UByte**>(pc + 0x10);
    unsigned&    nextPc  = *reinterpret_cast<unsigned*>(pc + 0x24);

    // The function object is 0xd0 bytes in the exe; the header models only its first 0x78.
    Ptr<AsFunctionObject> funcObj = *::new (FunctionOpSizedAlloc{penv->GetHeap(), 0xd0})
        AsFunctionObject(penv, pactions, nextPc, 0, *reinterpret_cast<void**>(pc + 0x38), 2);

    int i = *reinterpret_cast<int*>(pc + 0x28) + 3;
    ASString name = penv->CreateString(reinterpret_cast<const char*>(&pbuffer[i]));
    i += (int)name.GetSize() + 1;

    int nargs = pbuffer[i] | (int(pbuffer[i + 1]) << 8);
    i += 2;
    BodyOf(funcObj)->LocalRegisterCount = pbuffer[i];
    i += 1;
    BodyOf(funcObj)->Function2Flags = UInt16(pbuffer[i] | (UInt16(pbuffer[i + 1]) << 8));
    i += 2;

    for (int n = 0; n < nargs; n++)
    {
        int argRegister = pbuffer[i];
        i++;
        unsigned argLength = (unsigned)strlen(reinterpret_cast<const char*>(&pbuffer[i]));
        ASString argstr(penv->CreateString(reinterpret_cast<const char*>(&pbuffer[i]), argLength));
        i += (int)AddArg(funcObj, argRegister, argstr).Name.GetSize() + 1;
    }

    int length = pbuffer[i] | (pbuffer[i + 1] << 8);
    BodyOf(funcObj)->Length = length;
    nextPc += length;

    PublishFunction(penv, funcObj, name);
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216058
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432160a0
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B@ 0x143216148
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216150
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216198
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6B@ 0x143216240
