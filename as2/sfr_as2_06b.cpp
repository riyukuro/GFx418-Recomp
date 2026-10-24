// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 invocation entry points:
// the host's GFx::Value::Invoke on AS2 objects, MovieRoot::Invoke / InvokeArgs / InvokeAlias, script function bodies,
// the user defined (host) functions and the primitive toString / valueOf calls.
// MS2-UNIT: sfr_as2_06b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142962710-0x1429629a0 .text$mn
// MS2-RANGE: 0x1429629a0-0x142962b30 .text$mn
// MS2-RANGE: 0x142963820-0x142963a10 .text$mn
// MS2-RANGE: 0x142963b90-0x142963db0 .text$mn
// MS2-RANGE: 0x142963db0-0x142963fc0 .text$mn
// MS2-RANGE: 0x142964020-0x142964200 .text$mn
// MS2-RANGE: 0x142964390-0x142964710 .text$mn
// MS2-RANGE: 0x142964710-0x142964950 .text$mn
// MS2-RANGE: 0x142964950-0x142964b90 .text$mn
// MS2-RANGE: 0x142971ac0-0x142971ba0 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_userdefinedfunction.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx {

namespace {

SF_FORCEINLINE AS2::MovieRoot* InvRoot(MovieImpl* pmovieRoot)
{
    return static_cast<AS2::MovieRoot*>(pmovieRoot->pASMovieRoot);
}

// The environment of the main movie.
SF_FORCEINLINE AS2::Environment* InvMainEnv(AS2::MovieRoot* proot)
{
    AvmDisplayObjBase* pmain = proot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    return static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
}

} // namespace

// Calls the member function name of the object (or display object) with the arguments converted to AS2 values.
// MS2-FUNCTIONAL: register allocation and scheduling differ (the movie root is kept in a register in the exe).
// @0x142962710
bool AS2ValueObjectInterface::Invoke(void* pdata, Value* presult, const char* name, const Value* pargs, UPInt nargs,
                                     bool isdobj)
{
    AS2::MovieRoot*   proot = InvRoot(pMovieRoot);
    AS2::Environment* penv  = InvMainEnv(proot);
    AS2::ObjectInterface* pobj = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
        if (!pdobj)
            return false;
        pobj = AS2::ToAvmCharacter(static_cast<InteractiveObject*>(pdobj));
    }
    if (!pobj)
        return false;

    AS2::Value member;
    AS2::Value result;
    if (!pobj->GetMemberRaw(penv->GetSC(), penv->CreateConstString(name), &member))
        return false;
    AS2::Value asArg;
    for (int i = (int)nargs - 1; i >= 0; --i)
    {
        proot->Value2ASValue(pargs[i], &asArg);
        penv->Push(asArg);
    }
    bool ok = AS2::GAS_Invoke(member, &result, pobj, penv, (int)nargs, penv->GetTopIndex(), 0);
    for (int n = (int)nargs; n; n--)
        penv->Drop1();
    if (presult)
        proot->ASValue2GFxValue(penv, result, presult);
    return ok;
}

// MS2-FUNCTIONAL: the exe inlines ArrayObject::PushBack (the new element allocated and constructed in place).
// @0x142971ac0
bool AS2ValueObjectInterface::PushBack(void* pdata, const Value& value)
{
    AS2::Value asval;
    InvRoot(pMovieRoot)->Value2ASValue(value, &asval);
    static_cast<AS2::ArrayObject*>(static_cast<AS2::ObjectInterface*>(pdata))->PushBack(asval);
    return true;
}

namespace AS2 {

// The movie loaded as _level<level>, 0 if none.
static SF_FORCEINLINE InteractiveObject* GetMovieAtLevel(const MovieImpl* pmovieImpl, int level)
{
    for (unsigned i = 0; i < pmovieImpl->MovieLevelsSize; i++)
    {
        if (pmovieImpl->pMovieLevels[i].Level == level)
            return pmovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

static SF_FORCEINLINE AvmCharacter* AvmOfMovie(InteractiveObject* pmovie)
{
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmovie->GetAvmObjImpl()));
}

// Environment::GetAS2Root inline: the movie root of the target.
static SF_FORCEINLINE MovieRoot* EnvRoot(const Environment* penv)
{
    return static_cast<MovieRoot*>(penv->GetTarget()->pASRoot->pMovieImpl->pASMovieRoot);
}

// The state of one script function call: the environments and characters kept alive while the body runs.
// 0x58 bytes on the stack of AsFunctionObject::Invoke.
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

    // Builds the local frame, the arguments, this / super and the registers (exe 0x14298dee0).
    void Setup();
    // Restores the environment after the body (exe 0x142933e20).
    void Cleanup();
};
static_assert(sizeof(InvokeContext) == 0x58, "InvokeContext size");

// The members of AsFunctionObject past +0x78 (the body of a script function).
struct AsFunctionBody
{
    ActionBuffer*  pActionBuffer;          // +0x78 Ptr<ActionBuffer>
    WithStackArray WithStack;              // +0x80
    unsigned       StartPc;                // +0x98
    unsigned       Length;                 // +0x9c
    UByte          Unrecovered_a0[0x28];   // +0xa0 the argument specs (ArrayCC<ArgSpec>)
    UInt16         Function2Flags;         // +0xc8
    UByte          ExecType;               // +0xca
    UByte          LocalRegisterCount;     // +0xcb
};
static_assert(sizeof(AsFunctionBody) == 0x58, "AsFunctionBody size");

// MS2-FUNCTIONAL: the 255 nesting limit constant is loaded after the increment in the exe (scheduling only).
// @0x1429629a0
void AsFunctionObject::Invoke(const FnCall& fn, LocalFrame* plocalFrame, const char* pmethodName)
{
    InvokeContext ctxt(this, fn, plocalFrame, pmethodName);
    ctxt.pOurEnv = GetEnvironment(fn, &ctxt.TargetCh);
    // The function was defined in a character that is being unloaded: run in the caller's environment.
    if (ctxt.pOurEnv->GetTarget()->IsUnloaded())
        ctxt.pOurEnv = fn.Env;
    if (ctxt.pOurEnv->FuncCallNestingLevel++ >= 255)
    {
        if (ctxt.pOurEnv->IsVerboseActionErrors())
            ctxt.pOurEnv->LogScriptError("Stack overflow, max level of 255 nested calls is reached.");
    }
    else
    {
        ctxt.Setup();
        AsFunctionBody* pbody = reinterpret_cast<AsFunctionBody*>(reinterpret_cast<UByte*>(this) + 0x78);
        pbody->pActionBuffer->Execute(ctxt.pOurEnv, pbody->StartPc, pbody->Length, fn.Result, &pbody->WithStack,
                                      (ActionBuffer::ExecuteType)pbody->ExecType);
        ctxt.Cleanup();
    }
    ctxt.pOurEnv->FuncCallNestingLevel--;
}

// Calls the method ppathToMethod of _level0 (or the alias registered for it) with the arguments from pargFmt.
// MS2-FUNCTIONAL: register allocation differs (the format argument is kept in rsi).
// @0x142963820
bool MovieRoot::Invoke(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt, ...)
{
    if (!GetMovieAtLevel(pMovieImpl, 0))
        return false;
    Value   resultVal;
    va_list args;
    va_start(args, pargFmt);
    bool             retVal;
    InvokeAliasInfo* palias;
    if (*reinterpret_cast<void* const*>(Unrecovered_78) && (palias = ResolveInvokeAlias(ppathToMethod)) != 0)
        retVal = InvokeAliasArgs(ppathToMethod, *palias, &resultVal, pargFmt, args);
    else
    {
        AvmSprite*             pavmSprite = static_cast<AvmSprite*>(AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0)));
        Ptr<InteractiveObject> holder     = pavmSprite->GetDispObj();
        retVal = GAS_InvokeParsed(ppathToMethod, &resultVal, pavmSprite, &pavmSprite->Env, pargFmt, args);
    }
    va_end(args);
    if (retVal && presult)
        ASValue2GFxValue(AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0))->GetASEnvironment(), resultVal, presult);
    return retVal;
}

// @0x142964020
bool MovieRoot::InvokeArgs(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt, va_list args)
{
    if (!GetMovieAtLevel(pMovieImpl, 0))
        return false;
    Value            resultVal;
    bool             retVal;
    InvokeAliasInfo* palias;
    if (*reinterpret_cast<void* const*>(Unrecovered_78) && (palias = ResolveInvokeAlias(ppathToMethod)) != 0)
        retVal = InvokeAliasArgs(ppathToMethod, *palias, &resultVal, pargFmt, args);
    else
    {
        AvmSprite*             pavmSprite = static_cast<AvmSprite*>(AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0)));
        Ptr<InteractiveObject> holder     = pavmSprite->GetDispObj();
        retVal = GAS_InvokeParsed(ppathToMethod, &resultVal, pavmSprite, &pavmSprite->Env, pargFmt, args);
    }
    if (retVal && presult)
        ASValue2GFxValue(AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0))->GetASEnvironment(), resultVal, presult);
    return retVal;
}

// Calls the function of an invoke alias with this its object (or character) and numArgs values already pushed.
// MS2-FUNCTIONAL: register allocation and prologue differ.
// @0x142963b90
bool MovieRoot::InvokeAlias(const char* pmethodName, const InvokeAliasInfo& iai, Value* presult, unsigned numArgs)
{
    if (!GetMovieAtLevel(pMovieImpl, 0))
        return false;
    Ptr<Object>            pobj = iai.ThisObject;
    Ptr<InteractiveObject> pch;
    if (iai.ThisChar)
        pch = static_cast<InteractiveObject*>(iai.ThisChar->ResolveCharacter(pMovieImpl));
    ObjectInterface* pthis;
    if (pobj)
        pthis = pobj;
    else if (pch)
        pthis = ToAvmCharacter(pch);
    else
        pthis = 0;
    Environment* penv = AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0))->GetASEnvironment();
    return GAS_Invoke(Value(iai.Function), presult, pthis, penv, numArgs, penv->GetTopIndex(), pmethodName);
}

// The same with the arguments pushed from pmethodArgFmt and args.
// MS2-FUNCTIONAL: register allocation differs (rsi/rbp/r14 swapped).
// @0x142963db0
bool MovieRoot::InvokeAliasArgs(const char* pmethodName, const InvokeAliasInfo& iai, Value* presult,
                                const char* pmethodArgFmt, va_list args)
{
    if (!GetMovieAtLevel(pMovieImpl, 0))
        return false;
    Ptr<Object>            pobj = iai.ThisObject;
    Ptr<InteractiveObject> pch;
    if (iai.ThisChar)
        pch = static_cast<InteractiveObject*>(iai.ThisChar->ResolveCharacter(pMovieImpl));
    ObjectInterface* pthis;
    if (pobj)
        pthis = pobj;
    else if (pch)
        pthis = ToAvmCharacter(pch);
    else
        pthis = 0;
    Environment* penv = AvmOfMovie(GetMovieAtLevel(pMovieImpl, 0))->GetASEnvironment();
    return GAS_InvokeParsed(Value(iai.Function), presult, pthis, penv, pmethodArgFmt, args, pmethodName);
}

// Hands the call to the host's function handler: this and the arguments converted to GFx values, the result back.
// @0x142964390
void UserDefinedFunctionObject::InvokeImpl(const FnCall& fn)
{
    Environment*         penv = fn.Env;
    ArrayCPP<GFx::Value> args;
    GFx::Value           thisVal, retVal;
    Value                thisAS;
    if (fn.ThisPtr)
        thisAS.SetAsObjectInterface(fn.ThisPtr);
    else
        thisAS.SetNull();
    EnvRoot(penv)->ASValue2GFxValue(penv, thisAS, &thisVal);
    args.PushBack(thisVal); // this goes first to the handler

    for (int i = 0; i < fn.NArgs; i++)
    {
        GFx::Value arg;
        EnvRoot(penv)->ASValue2GFxValue(penv, fn.Arg(i), &arg);
        args.PushBack(arg);
    }

    FunctionHandler::Params params;
    params.pMovie        = reinterpret_cast<Movie*>(EnvRoot(penv)->pMovieImpl); // MovieImpl is a Movie
    params.pRetVal       = &retVal;
    params.pThis         = &thisVal;
    params.pArgs         = fn.NArgs > 0 ? &args[1] : 0;
    params.pArgsWithThis = &args[0];
    params.ArgCount      = (unsigned)args.GetSize() - 1;
    params.pUserData     = pUserData;
    pContext->Call(params);

    if (!retVal.IsUndefined())
        EnvRoot(penv)->Value2ASValue(retVal, fn.Result);
}

// toString / valueOf on a primitive: the method from the prototype chain of the wrapper object, else undefined.
// MS2-FUNCTIONAL: register allocation differs and the obj uses a frame pointer.
// @0x142964710
bool BooleanObject::InvokePrimitiveMethod(const FnCall& fnCall, const ASString& methodName)
{
    BooleanObject* pthis = static_cast<BooleanObject*>(fnCall.ThisPtr);
    if (fnCall.Env->GetBuiltin(ASBuiltin_toString).CompareBuiltIn_CaseCheck(methodName, fnCall.Env->IsCaseSensitive()) ||
        fnCall.Env->GetBuiltin(87 /* valueOf */).CompareBuiltIn_CaseCheck(methodName, fnCall.Env->IsCaseSensitive()))
    {
        Value method;
        if (pthis->GetMemberRaw(fnCall.Env->GetSC(), methodName, &method))
        {
            FunctionRef func = method.ToFunction(fnCall.Env);
            if (!func.IsNull())
            {
                func.Invoke(fnCall);
                return true;
            }
        }
    }
    fnCall.Result->SetUndefined();
    return false;
}

// MS2-FUNCTIONAL: register allocation differs and the obj uses a frame pointer.
// @0x142964950
bool NumberObject::InvokePrimitiveMethod(const FnCall& fnCall, const ASString& methodName)
{
    NumberObject* pthis = static_cast<NumberObject*>(fnCall.ThisPtr);
    if (fnCall.Env->GetBuiltin(ASBuiltin_toString).CompareBuiltIn_CaseCheck(methodName, fnCall.Env->IsCaseSensitive()) ||
        fnCall.Env->GetBuiltin(87 /* valueOf */).CompareBuiltIn_CaseCheck(methodName, fnCall.Env->IsCaseSensitive()))
    {
        Value method;
        if (pthis->GetMemberRaw(fnCall.Env->GetSC(), methodName, &method))
        {
            FunctionRef func = method.ToFunction(fnCall.Env);
            if (!func.IsNull())
            {
                func.Invoke(fnCall);
                return true;
            }
        }
    }
    fnCall.Result->SetUndefined();
    return false;
}

} // namespace AS2

}} // namespace Scaleform::GFx
