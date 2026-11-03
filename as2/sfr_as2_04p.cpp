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

// Delivers eventName to a snapshot of the _listeners array: each listener's method (a function, or a function name
// resolved against the listener) is handed to the callback together with the listener.
// MS2-FUNCTIONAL: inline (the exe inlines FunctionRefBase::SetLocalFrame into the ToFunction copy, ours calls it)
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
                    if (pelem && (plistener = pelem->ToObjectInterface(penv)) != NULL)
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
                            FunctionRef method = methodVal.ToFunction(penv);
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

// The 'cast' opcode (ExecutionContext::CastOpCode, the context is not modelled: +0 the environment, +0x40 the
// logger, +0x62 the verbose flag): the object below the constructor stays when it is an instance of it, null otherwise.
// MS2-FUNCTIONAL: the context is read by address
// @0x142932d20
void FUN_142932d20(void* pctx)
{
    UByte*        pc    = static_cast<UByte*>(pctx);
    Environment*  penv  = *reinterpret_cast<Environment**>(pc);
    ActionLogger* plog  = reinterpret_cast<ActionLogger*>(pc + 0x40);
    bool          verbose = (pc[0x62] & 1) != 0;

    Value  rv(Value::NULLTYPE);
    Value& objVal  = penv->Top(0);
    Value& ctorVal = penv->Top(1);
    if (ctorVal.IsFunction())
    {
        FunctionRef ctorFunc = ctorVal.ToFunction(penv);
        if (!ctorFunc.IsNull())
        {
            ObjectInterface* pobj = objVal.ToObjectInterface(penv);
            if (pobj)
            {
                Value protoVal;
                if (ctorFunc->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &protoVal))
                {
                    Object* pproto = protoVal.ToObject(penv);
                    if (pobj->InstanceOf(penv, pproto))
                        rv.SetAsObjectInterface(pobj);
                }
                else if (verbose)
                    plog->LogScriptError("The constructor function in 'cast' should have 'prototype'.");
            }
        }
    }
    else if (verbose)
        plog->LogScriptError("The parameter of 'cast' should be a function.");

    penv->Drop(2);
    penv->Push(rv);
}

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
