// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05,
// lane sfr36): the variables load done on the movie thread, the clip's endFill and the for..in opcode.
// MS2-UNIT: sfr_as2_05m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142938d60-0x14293909b .text$mn
// MS2-RANGE: 0x1429398d0-0x14293991b .text$mn
// MS2-RANGE: 0x142939920-0x142939c17 .text$mn
// MS2-RANGE: 0x142943480-0x1429437e0 .text$mn
// MS2-RANGE: 0x1429437e0-0x142943c6b .text$mn
// MS2-RANGE: 0x142945b20-0x142945c55 .text$mn
// MS2-RANGE: 0x14292a6b0-0x14292a6f2 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_broadcastlocal.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sharedobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_hash.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieRoot::GetLevelMovie, inlined in the exe.
SF_FORCEINLINE InteractiveObject* LqLevelMovie(const MovieRoot* proot, int level)
{
    MovieImpl* pmovie = proot->pMovieImpl;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The script environment of a character.
SF_FORCEINLINE Environment* LqCharEnv(InteractiveObject* pchar)
{
    AvmDisplayObjBase* pavm = pchar->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

} // namespace

// The variables text of a finished load: a LoadVars object gets the byte counts and its onData event (the default
// handler decodes it), otherwise the target clip or level (made empty when missing) gets the pairs as members.
// @0x142938d60
void MovieRoot::DoProcessLoadVars(GFx::LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                  bool)
{
    GFxAS2LoadQueueEntry* pas2entry = static_cast<GFxAS2LoadQueueEntry*>(pentry);
    if (pas2entry->LoadVarsHolder.ToObject(0))
    {
        LoadVarsObject* ploadVars = static_cast<LoadVarsObject*>(pas2entry->LoadVarsHolder.ToObject(0));
        Environment*    penv      = LqCharEnv(LqLevelMovie(this, 0));
        ASString        str       = penv->CreateString(data);
        Number          len       = (Number)fileLen;
        if (ploadVars->BytesTotal < 0)
            ploadVars->BytesTotal = 0;
        ploadVars->BytesLoaded = len;
        ploadVars->BytesTotal += len;
        // LoadVarsObject::NotifyOnData, inlined.
        penv->Push(str);
        BroadcastMessageLocal(penv, ploadVars, penv->CreateConstString("onData"), 1, penv->GetTopIndex());
        penv->Drop1();
        return;
    }

    Ptr<InteractiveObject> pchar;
    if (pas2entry->Level == -1)
        pchar = static_cast<InteractiveObject*>(pas2entry->pCharacter->ResolveCharacter(pMovieImpl));
    else
    {
        pchar = LqLevelMovie(this, pas2entry->Level);
        if (!pchar)
        {
            pchar = *CreateEmptyLevelMovie(pls, pas2entry->Level);
            if (!pchar)
                return;
        }
    }
    LoadVarsProto::LoadVariables(LqCharEnv(LqLevelMovie(this, 0)), ToAvmCharacter(pchar), data);
}

// endFill(): closes the open fill path of the clip.
// @0x1429398d0
void AvmSprite::EndFill()
{
    AcquirePath(true)->EndFill();
}

// for..in: every enumerable member name goes on the stack.
struct EnumerateOpVisitor : public ObjectInterface::MemberVisitor
{
    Environment*  pEnv; // +0x08
    ActionLogger* pLog; // +0x10 set when actions are traced

    EnumerateOpVisitor(Environment* penv, ActionLogger* plog) : pEnv(penv), pLog(plog) {}
    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// Value::ToObjectInterface with ToAvmCharacter and ToCharacter inlined, as in the exe's enumerate opcode.
static SF_FORCEINLINE ObjectInterface* LmEnumToObjectInterface(const Value& v, const Environment* penv)
{
    if (v.GetType() == Value::CHARACTER)
    {
        InteractiveObject* pchar = 0;
        if (penv && v.V.pCharHandle)
        {
            DisplayObject* pdisp = v.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            if (pdisp)
                pchar = pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
        }
        return pchar ? GFx::AS2::ToAvmCharacter(pchar) : 0;
    }
    return v.ToObject(penv);
}

// The 'enumerate' opcodes (ExecutionContext::EnumerateOpCode; the context is not modelled: +0 the environment,
// +0x38 the with stack, +0x40 the logger, +0x62 the verbose flags): a null ends the names pushed for the object on
// top (0x55), or for the variable named on top (0x46). The environment and the with stack are re-read from the
// context after each call, and the logger address is taken at its use, as in the exe.
// @0x142939920
void FUN_142939920(void* pctx, int actionId)
{
    UByte*                       pc         = static_cast<UByte*>(pctx);
    Environment* const&          penv       = *reinterpret_cast<Environment**>(pc);
    const WithStackArray* const& pwithStack = *reinterpret_cast<const WithStackArray**>(pc + 0x38);

    Value varName = *penv->Stack.Top0();
    penv->Drop1();
    Value nullValue;
    nullValue.SetNull();
    penv->Push(nullValue);

    ObjectInterface* pobj;
    if (actionId == 0x55)
    {
        pobj = LmEnumToObjectInterface(varName, penv);
        if (!pobj)
            return;
    }
    else
    {
        ASString name = varName.ToString(penv);
        Value    val;
        if (!penv->GetVariable(name, &val, pwithStack, 0, 0, 0))
            return;
        pobj = LmEnumToObjectInterface(val, penv);
        if (!pobj)
            return;
    }
    ActionLogger* plog = reinterpret_cast<ActionLogger*>(pc + 0x40);
    if (pc[0x62] & 2)
        plog->LogAction("---enumerate - Push: NULL\n");
    EnumerateOpVisitor visitor(penv, plog);
    pobj->VisitMembers(penv->GetSC(), &visitor, ObjectInterface::VisitMember_Prototype |
                                                    ObjectInterface::VisitMember_ChildClips |
                                                    ObjectInterface::VisitMember_NamesOnly, 0);
}


// The empty entry, as in sfr_as2_06.
inline MovieRoot::ActionEntry::ActionEntry()
{
    pNextEntry    = 0;
    Type          = Entry_None;
    pActionBuffer = 0;
    SessionId     = 0;
}

namespace {

// ActionEntry::SetAction for an event and for a function (inlined in the exe).
SF_FORCEINLINE void LmSetEventAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, const EventId& id)
{
    pe->Type       = MovieRoot::ActionEntry::Entry_Event;
    pe->pCharacter = pch;
    pe->mEventId   = id;
}
SF_FORCEINLINE void LmSetFunctionAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, const FunctionRef& func)
{
    pe->Type       = MovieRoot::ActionEntry::Entry_Function;
    pe->pCharacter = pch;
    pe->Function   = func;
}

} // namespace

// The init action of a clip of a registered class: the clip takes the prototype of the class named in Arg(0), then
// gets its construct event and the constructor runs on it. Without a registered class the construct event still
// runs (a component without a class can have one).
// MS2-FUNCTIONAL: the registered class is looked up through the inline hash accessor; the exe calls its out-of-line
// GetCaseCheck.
// @0x142943480
void FUN_142943480(const FnCall& fn)
{
    GlobalContext* pgc = fn.Env->GetSC()->pContext;
    FunctionRef    ctorFunc;
    const ASString symbolName(fn.Arg(0).ToString(fn.Env));
    if (symbolName.IsEmpty())
        return;
    ObjectInterface* pthis = fn.ThisPtr;
    AvmSprite*       pavm  = pthis->GetObjectType() == ObjectInterface::Object_Sprite
                                 ? static_cast<AvmSprite*>(static_cast<AvmCharacter*>(pthis)) : 0;
    const FunctionRef* pctor = pgc->RegisteredClasses.GetCaseCheck(symbolName, fn.Env->IsCaseSensitive());
    if (pctor)
    {
        ctorFunc = *pctor;
        pavm->SetProtoToPrototypeOf(ctorFunc.GetObjectPtr());
        {
            MovieRoot::ActionEntry e;
            LmSetEventAction(&e, pavm->GetDispObj(), EventId(EventId::Event_Construct));
            e.Execute(pavm->GetAS2Root());
        }
        MovieRoot::ActionEntry e;
        LmSetFunctionAction(&e, pavm->GetDispObj(), ctorFunc);
        e.Execute(pavm->GetAS2Root());
    }
    else
    {
        MovieRoot::ActionEntry e;
        LmSetEventAction(&e, pavm->GetDispObj(), EventId(EventId::Event_Construct));
        e.Execute(pavm->GetAS2Root());
    }
}

struct Sfr05mCopyTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it in the ToFunction copy.
static SF_FORCEINLINE void sfr05mFunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
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
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, Sfr05mCopyTag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        sfr05mFunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// The SDK's out-of-line Value::ToFunction (a switch), which the exe inlines here.
struct Sfr05mValueAccess : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef sfr05mToFunction(const Value& v, const Environment* penv)
{
    switch (v.GetType())
    {
    case Value::FUNCTIONNAME:
        return static_cast<const Sfr05mValueAccess&>(v).ResolveFunctionName(penv);
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, Sfr05mCopyTag());
    default:;
    }
    return FunctionRef();
}

// GlobalContext::GetBuiltin (SDK inline): the builtin string of the movie root's string manager.
static SF_FORCEINLINE const ASString& sfr05mGetBuiltin(const GlobalContext* gc, ASBuiltinType btype)
{
    return static_cast<MovieRoot*>(gc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(btype);
}

// The exe (LTCG) inlines ObjectInterface::ToAvmCharacter / ToASObject here, type re-test included.
static SF_FORCEINLINE AvmCharacter* sfr05mToAvmCharacter(ObjectInterface* p)
{
    return p->IsASCharacter() ? static_cast<AvmCharacter*>(p) : 0;
}
static SF_FORCEINLINE Object* sfr05mToASObject(ObjectInterface* p)
{
    return p->IsASObject() ? static_cast<Object*>(p) : 0;
}

// The name of the class the object (or its prototype) is a member of _global under, "name.prototype" for a
// prototype; "unknown" when none.
// @0x1429437e0
ASString GlobalContext::FindClassName(Environment* penv, ObjectInterface* iobj)
{
    if (iobj)
    {
        Object* obj;
        if (iobj->IsASCharacter())
            obj = sfr05mToAvmCharacter(iobj)->GetASObject();
        else
            obj = sfr05mToASObject(iobj);

        // The set's own Iterator (no slice to ConstIterator): the exe keeps { pHash, Index } in registers.
        typedef ASStringHash_GC<Member>::SetType MemberSet;
        MemberSet::Iterator it = const_cast<MemberSet&>(pGlobal->Members.GetSet()).Begin();
        for (; it != pGlobal->Members.GetSet().End(); ++it)
        {
            const ASString& nm  = it->First;
            const Member&   m   = it->Second;
            const Value&    val = m.mValue;
            if (obj->IsFunction())
            {
                if (val.IsFunction() && sfr05mToFunction(val, penv).GetObjectPtr() == obj)
                    return nm;
            }
            else
            {
                if (val.IsObject() && val.ToObject(penv) == obj)
                    return nm;
                if (val.IsFunction())
                {
                    FunctionRef f = sfr05mToFunction(val, penv);
                    Value       protoVal;
                    if (f->GetMemberRaw(penv->GetSC(), sfr05mGetBuiltin(this, ASBuiltin_prototype), &protoVal))
                    {
                        if (protoVal.IsObject() && protoVal.ToObject(penv) == obj)
                            return nm + ".prototype";
                    }
                }
            }
        }
    }
    return static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(
        ASBuiltin_unknown_);
}

// SharedObject.flush: hands the data members to the writer, objects and arrays as nested scopes. Each object is
// written once: VisitedObjects stops the walk at objects already seen.
struct SharedObjectFlushVisitor : public ObjectInterface::MemberVisitor
{
    typedef HashUncached<Object*, Object*, IdentityHash<Object*> > ObjectSet;

    ObjectSet            VisitedObjects; // +0x08
    Environment*         pEnv;           // +0x10
    SharedObjectVisitor* pWriter;        // +0x18

    SharedObjectFlushVisitor(Environment* penv, SharedObjectVisitor* pwriter) : pEnv(penv), pWriter(pwriter) {}
    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// Writes the members of the data object.
// @0x142945b20
void SharedObject::Flush(Environment* penv, SharedObjectVisitor* pwriter)
{
    if (!pwriter)
        return;
    Value val;
    GetMemberRaw(penv->GetSC(), penv->CreateConstString("data"), &val);
    Object*                  pdataObj = val.ToObject(penv);
    SharedObjectFlushVisitor visitor(penv, pwriter);
    pwriter->Begin();
    pdataObj->VisitMembers(penv->GetSC(), &visitor, 0, 0);
    pwriter->End();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7EnumerateOpVisitor@AS2@GFx@Scaleform@@6B@ 0x1432205f0
// MS2-PIN: ??_7SharedObjectFlushVisitor@AS2@GFx@Scaleform@@6B@ 0x1432227f8
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7SetFocusInvokeCallback@AS2@GFx@Scaleform@@6B@ 0x143221850
