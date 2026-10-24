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

// The 'extends' opcode (ExecutionContext::ExtendsOpCode; the context is not modelled: +0 the environment, +0x40 the
// logger, +0x62 the verbose flag): the subclass below the superclass on top gets a new prototype whose __proto__ is
// the superclass prototype and whose __constructor__ is the superclass.
// MS2-FUNCTIONAL: the context is read by address; the ObjectProto constructor is inlined in the exe
// @0x142941680
void FUN_142941680(void* pctx)
{
    UByte*        pc   = static_cast<UByte*>(pctx);
    Environment*  penv = *reinterpret_cast<Environment**>(pc);
    ActionLogger* plog = reinterpret_cast<ActionLogger*>(pc + 0x40);

    Value       superClassCtorVal = penv->Top(0);
    Value       subClassCtorVal   = penv->Top(1);
    FunctionRef superClassCtor    = superClassCtorVal.ToFunction(penv);
    FunctionRef subClassCtor      = subClassCtorVal.ToFunction(penv);
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
                *SF_HEAP_NEW(penv->GetHeap()) ObjectProto(penv->GetSC(), superProto);
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
    args.Resize(args.GetSize() + 1);
    FnArgSpec& arg = args.Back();
    arg.Register   = argRegister;
    arg.Name       = name;
    return arg;
}

// The common tail of both definitions: the function is stored on the target under its name (or left on the stack
// when anonymous), with a fresh prototype whose constructor is the function.
inline void PublishFunction(Environment* penv, Ptr<AsFunctionObject>& funcObj, const ASString& name)
{
    FunctionRef funcRef(funcObj.GetPtr());
    if (LocalFrame* plocalFrame = penv->GetTopLocalFrame())
        funcRef.SetLocalFrame(plocalFrame);

    Value functionValue(funcRef);
    if (name.GetSize() != 0)
        penv->GetAvmTarget()->SetMemberRaw(penv->GetSC(), name, functionValue);

    ASStringContext*   psc = penv->GetSC();
    Ptr<FunctionProto> funcProto =
        *SF_HEAP_NEW(psc->GetHeap()) FunctionProto(psc, penv->GetPrototype(ASBuiltin_Object), funcRef, false);
    funcRef->SetProtoAndCtor(psc, penv->GetPrototype(ASBuiltin_Function));
    funcObj->SetPrototype(psc, funcProto);

    if (name.GetSize() == 0)
        penv->Push(functionValue);
}

} // namespace

// The 'function' opcode (ExecutionContext::Function1OpCode; the context is not modelled: +0 the environment, +0x10
// the code bytes, +0x24 the next pc, +0x28 the pc, +0x38 the with stack): name, argument names and body length;
// the body is skipped.
// MS2-FUNCTIONAL: the context is read by address; AddArg, the FunctionProto constructor and SetPrototype are inlined
// in the exe
// @0x142945da0
void FUN_142945da0(void* pctx, ActionBuffer* pactions)
{
    UByte*       pc      = static_cast<UByte*>(pctx);
    Environment* penv    = *reinterpret_cast<Environment**>(pc);
    const UByte* pbuffer = *reinterpret_cast<const UByte**>(pc + 0x10);
    unsigned&    nextPc  = *reinterpret_cast<unsigned*>(pc + 0x24);

    Ptr<AsFunctionObject> funcObj = *SF_HEAP_NEW(penv->GetHeap())
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
    Environment* penv    = *reinterpret_cast<Environment**>(pc);
    const UByte* pbuffer = *reinterpret_cast<const UByte**>(pc + 0x10);
    unsigned&    nextPc  = *reinterpret_cast<unsigned*>(pc + 0x24);

    Ptr<AsFunctionObject> funcObj = *SF_HEAP_NEW(penv->GetHeap())
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
