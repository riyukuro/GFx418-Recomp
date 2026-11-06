// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AsBroadcaster message delivery
// (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142932290-0x142932695 .text$mn
// MS2-RANGE: 0x142932d20-0x142933005 .text$mn
// MS2-RANGE: 0x1429384f0-0x1429385e1 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// ArrayObject::MakeDeepCopyFrom (0x142968560, sfr_as2_06), which the exe inlines into BroadcastMessageWithCallback.
static SF_FORCEINLINE void Sfr04pMakeDeepCopyFrom(ArrayObject* pthis, MemoryHeap* pheap, const ArrayObject& ao)
{
    pthis->Elements.Resize(ao.Elements.GetSize());
    for (UPInt i = 0, n = pthis->Elements.GetSize(); i < n; i++)
    {
        if (ao.Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*ao.Elements[i]);
            pthis->Elements[i] = pval;
        }
    }
}

// FunctionRefBase::SetLocalFrame (0x142981e70, sfr_as2_07) and the FunctionRef copy around it, which the exe inlines
// into the ToFunction copy below. Local copies: an inline redefinition of the member would emit a second COMDAT.
static SF_FORCEINLINE void MS2_SetLocalFrame(FunctionRefBase& r, LocalFrame* localFrame, bool weakRef)
{
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->Release();
    r.pLocalFrame = localFrame;
    if (weakRef)
        r.Flags |= FunctionRefBase::FuncRef_Weak;
    else
        r.Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->AddRef();
}

static SF_FORCEINLINE FunctionRef MS2_CopyFuncRef(const FunctionRefBase& orig)
{
    FunctionRef r(orig.Function);
    if (orig.pLocalFrame)
        MS2_SetLocalFrame(r, orig.pLocalFrame, (orig.Flags & FunctionRefBase::FuncRef_Weak) != 0);
    return r;
}

// Value::ToFunction as the SDK writes it (a switch); the exe inlines it here. The derived view reaches the protected
// ResolveFunctionName.
struct MS2_FuncValue : Value
{
    SF_FORCEINLINE FunctionRef ToFunctionSw(const Environment* penv) const
    {
        switch (T.Type)
        {
        case FUNCTIONNAME:
            return ResolveFunctionName(penv);
        case FUNCTION:
            return MS2_CopyFuncRef(V.FunctionValue);
        default:;
        }
        return FunctionRef();
    }
};

// Delivers eventName to a snapshot of the _listeners array: each listener's method (a function, or a function name
// resolved against the listener) is handed to the callback together with the listener.
// @0x142932290
bool AsBroadcaster::BroadcastMessageWithCallback(Environment* penv, ObjectInterface* pthis, const ASString& eventName,
                                                 InvokeCallback* pcallback)
{
    if (!pthis)
        return false;

    Value listenersVal;
    if (pthis->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listenersVal))
    {
        Object* pobj = listenersVal.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_Array)
        {
            Ptr<ArrayObject> porigArrObj = static_cast<ArrayObject*>(pobj);
            if (porigArrObj->GetSize() > 0)
            {
                Ptr<ArrayObject> parrObj = *SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
                Sfr04pMakeDeepCopyFrom(parrObj, penv->GetHeap(), *porigArrObj);
                for (unsigned i = 0, n = parrObj->GetSize(); i < n; i++)
                {
                    Value*           pelem = parrObj->GetElementPtr(i);
                    ObjectInterface* plistener;
                    if (pelem && (plistener = pelem->ToObjectInterface_Call(penv)) != NULL)
                    {
                        Ptr<Object>            objHolder;
                        Ptr<InteractiveObject> charHolder;
                        if (pelem->GetType() == Value::CHARACTER)
                            charHolder = pelem->ToCharacter(penv);
                        else
                            objHolder = pelem->ToObject(penv);

                        Value methodVal;
                        if (plistener->GetMemberRaw(penv->GetSC(), eventName, &methodVal))
                        {
                            FunctionRef method = static_cast<const MS2_FuncValue&>(methodVal).ToFunctionSw(penv);
                            if (!method.IsNull())
                                pcallback->Invoke(penv, plistener, method);
                        }
                    }
                }
            }
        }
    }
    return true;
}

// The SDK's inline Value::ToFunction and FunctionRef copy (as in sfr_as2_06s1).
struct SetLocalFrameInlineTag04p {};
static SF_FORCEINLINE void FunctionRefSetLocalFrame04p(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
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
template<>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, SetLocalFrameInlineTag04p)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        FunctionRefSetLocalFrame04p(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}
struct ValueAccess04p : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef ValueToFunction04p(const Value& v, const Environment* penv, UByte vtype)
{
    switch (vtype)
    {
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, SetLocalFrameInlineTag04p());
    case Value::FUNCTIONNAME:
        return static_cast<const ValueAccess04p&>(v).ResolveFunctionName(penv);
    }
    return FunctionRef();
}

// The 'cast' opcode (ExecutionContext::CastOpCode, the context is not modelled: +0 the environment, +0x40 the
// logger, +0x62 the verbose flag): the object below the constructor stays when it is an instance of it, null otherwise.
// The environment is re-read from the context after each call, and the logger is addressed in place. The
// constructor's type is read once, before rv is built, and the inline ToFunction switches on that read.
// @0x142932d20
void FUN_142932d20(void* pctx)
{
    UByte*        pc   = static_cast<UByte*>(pctx);
    Environment*& penv = *reinterpret_cast<Environment**>(pc);
#define plog reinterpret_cast<ActionLogger*>(pc + 0x40) // a local pointer costs a callee-saved register

    Value& ctorVal = *((penv->Stack.pCurrent > penv->Stack.pPageStart) ? (penv->Stack.pCurrent - 1)
                                                                         : penv->Stack.pPrevPageTop);
    UByte  ctype   = ctorVal.GetType();
    Value& objVal  = *penv->Stack.Top0();
    Value  rv(Value::NULLTYPE);
    if (ctype == Value::FUNCTION || ctype == Value::FUNCTIONNAME)
    {
        FunctionRef ctorFunc = ValueToFunction04p(ctorVal, penv, ctype);
        if (!ctorFunc.IsNull())
        {
            ObjectInterface* pobj = objVal.IsCharacter()
                                        ? static_cast<ObjectInterface*>(objVal.ToAvmCharacter(penv))
                                        : static_cast<ObjectInterface*>(objVal.ToObject(penv));
            if (pobj)
            {
                Value protoVal;
                if (ctorFunc->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &protoVal))
                {
                    Object* pproto = protoVal.ToObject(penv);
                    if (pobj->InstanceOf(penv, pproto))
                        rv.SetAsObjectInterface(pobj);
                }
                else if (pc[0x62] & 1)
                    plog->LogScriptError("The constructor function in 'cast' should have 'prototype'.");
            }
        }
    }
    else if (pc[0x62] & 1)
        plog->LogScriptError("The parameter of 'cast' should be a function.");

    penv->Drop2();
    penv->Push(rv);
}
#undef plog

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The host side of AS2 values; only the members recovered in this unit.
class AS2ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual bool DeleteMember(void* pdata, const char* name, bool isdobj);
};

// Deletes the member of the AS object (or of the character) in pdata.
// @0x1429384f0
bool AS2ValueObjectInterface::DeleteMember(void* pdata, const char* name, bool isdobj)
{
    MovieImpl*        pmovie = pMovieRoot;
    AS2::MovieRoot*   proot = static_cast<AS2::MovieRoot*>(pmovie->pASMovieRoot);
    AvmDisplayObjBase* pmain = proot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    AS2::Environment*  penv  =
        static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
    AS2::ObjectInterface* pobj = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
        if (!pdobj)
            return false;
        InteractiveObject* pch  = static_cast<InteractiveObject*>(pdobj);
        // the character's own interface (its AvmCharacter), not its AS object
        pobj = AS2::ToAvmCharacter(pch);
    }
    if (!pobj)
        return false;
    AS2::ASStringContext* psc = &penv->StringContext;
    ASString key = psc->CreateConstString(name);
    return pobj->DeleteMember(psc, key);
}

}} // namespace Scaleform::GFx
