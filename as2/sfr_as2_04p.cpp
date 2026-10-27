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

// Delivers eventName to a snapshot of the _listeners array: each listener's method (a function, or a function name
// resolved against the listener) is handed to the callback together with the listener.
// MS2-FUNCTIONAL: the listener and method references are held by smart pointers
// @0x142932290
bool AsBroadcaster::BroadcastMessageWithCallback(Environment* penv, ObjectInterface* pthis, const ASString& eventName,
                                                 InvokeCallback* pcallback)
{
    if (!pthis)
        return false;

    Value listenersVal;
    if (pthis->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listenersVal))
    {
        Ptr<Object> plisteners = listenersVal.ToObject(penv);
        if (plisteners && plisteners->GetObjectType() == Object_Array)
        {
            ArrayObject* psrc = static_cast<ArrayObject*>(plisteners.GetPtr());
            if (psrc->GetSize() > 0)
            {
                Ptr<ArrayObject> pcopy = *SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
                pcopy->MakeDeepCopyFrom(penv->GetHeap(), *psrc);
                for (unsigned i = 0, n = pcopy->GetSize(); i < n; ++i)
                {
                    Value* plistener = pcopy->GetElementPtr(i);
                    if (!plistener)
                        continue;
                    ObjectInterface* pif = plistener->ToObjectInterface(penv);
                    if (!pif)
                        continue;
                    Ptr<Object>            pobj;
                    Ptr<InteractiveObject> pchar;
                    if (plistener->GetType() == Value::CHARACTER)
                        pchar = plistener->ToCharacter(penv);
                    else
                        pobj = plistener->ToObject(penv);

                    Value method;
                    if (pif->GetMemberRaw(penv->GetSC(), eventName, &method))
                    {
                        FunctionRef func = method.ToFunction(penv);
                        if (func.GetObjectPtr())
                            pcallback->Invoke(penv, pif, func);
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
    AS2::MovieRoot*   proot = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    AvmDisplayObjBase* pmain = proot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    AS2::Environment*  penv  =
        static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
    AS2::ObjectInterface* pobj = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
        if (!pdobj)
            return false;
        InteractiveObject* pch  = static_cast<InteractiveObject*>(pdobj);
        // the character's own interface (its AvmCharacter), not its AS object
        pobj = static_cast<AS2::AvmCharacter*>(pch->GetAvmIntObj());
    }
    if (!pobj)
        return false;
    ASString key = penv->StringContext.CreateConstString(name);
    return pobj->DeleteMember(&penv->StringContext, key);
}

}} // namespace Scaleform::GFx
