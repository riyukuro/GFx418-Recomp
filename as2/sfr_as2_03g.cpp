// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 small helpers: the global
// object, the value guard, the host object data, a pointer array copy (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291c160-0x14291c1b4 .text$mn
// MS2-RANGE: 0x142923dd0-0x142923e62 .text$mn
// MS2-RANGE: 0x142923f30-0x142923fcf .text$mn
// MS2-RANGE: 0x142924090-0x142924176 .text$mn
// MS2-RANGE: 0x1429260c0-0x1429260f0 .text$mn
// MS2-RANGE: 0x1429261c0-0x1429261fa .text$mn
// MS2-RANGE: 0x142926a00-0x142926aa8 .text$mn
// MS2-RANGE: 0x142953210-0x14295327d .text$mn
// MS2-RANGE: 0x142985ef0-0x142986168 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_array.h"

namespace Scaleform { namespace GFx { namespace AS2 {

void FUN_142939780(void*);

// The _global object: an Object holding its context (0x70 bytes).
// MS2-FUNCTIONAL: only the members this constructor touches are declared
class GASGlobalObject : public Object
{
public:
    GlobalContext* pContext; // +0x68
    GASGlobalObject(GlobalContext* pcontext);

    // Empty but user-declared: the deleting dtor 0x14292ade0 (sfr_as2_04b) stores the vftables.
    virtual ~GASGlobalObject() {}
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val); // exe 0x142953210
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags =
                                                                                          PropFlags()); // exe 0x142985ef0
};

// The Scaleform extension names of the movie's builtin strings: gfxExtensions, noInvisibleAdvance, continueAnimation.
enum { Builtin_gfxExtensions = 71, Builtin_noInvisibleAdvance = 72, Builtin_continueAnimation = 73 };

// _global.gfxExtensions reads the context's extensions flag (unset until assigned).
// @0x142953210
bool GASGlobalObject::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    if (name.GetNode() == psc->GetBuiltin(Builtin_gfxExtensions).GetNode())
    {
        UByte ext = pContext->GFxExtensions.Value;
        if (ext)
        {
            val->SetBool(ext == Bool3W::B3W_True);
            return true;
        }
        val->SetUndefined();
        return false;
    }
    return Object::GetMemberRaw(psc, name, val);
}

// The SDK's inline GlobalContext string helper and Environment::GetMovieImpl (Target->...->pMovieImpl), as the exe inlines them.
static SF_FORCEINLINE ASString GlobalCreateConstString(GlobalContext* gc, const char* pstr)
{
    return static_cast<MovieRoot*>(gc->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateConstString(pstr);
}
// ObjectInterface::SetConstMemberRaw as the SDK header inlines it.
static SF_FORCEINLINE bool GlobalSetConstMemberRaw(ObjectInterface& oi, ASStringContext* psc, const char* name,
                                                   const Value& val)
{
    return oi.SetMemberRaw(psc, psc->CreateConstString(name), val, PropFlags());
}
static SF_FORCEINLINE UByte* GlobalEnvMovieImpl(Environment* penv)
{
    UByte* p = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(penv->Target) + 0x20);
    return *reinterpret_cast<UByte**>(p + 0x10);
}

// Assigning gfxExtensions switches the extensions (and the gfxVersion member) on or off; with them on,
// noInvisibleAdvance and continueAnimation set the movie's flags.
// @0x142985ef0
bool GASGlobalObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (name == penv->GetSC()->GetBuiltin(ASBuiltin_gfxExtensions))
    {
        pContext->GFxExtensions = val.ToBool(penv);
        if (pContext->GFxExtensions.IsTrue())
        {
            GlobalSetConstMemberRaw(*this, penv->GetSC(), "gfxVersion", Value(GlobalCreateConstString(pContext, "4.1.18")));
        }
        else
        {
            DeleteMember(penv->GetSC(), GlobalCreateConstString(pContext, "gfxVersion"));
        }
        return Object::SetMember(penv, name, Value(Value::UNSET), flags);
    }
    else if (pContext->GFxExtensions.IsTrue())
    {
        if (name == penv->GetSC()->GetBuiltin(ASBuiltin_noInvisibleAdvance))
        {
            UByte* proot = GlobalEnvMovieImpl(penv);
            if (proot)
                G_SetFlag<0x800>(*reinterpret_cast<UInt32*>(proot + 0x3490), val.ToBool(penv));
        }
        else if (name == penv->GetSC()->GetBuiltin(ASBuiltin_continueAnimation))
        {
            UByte* proot = GlobalEnvMovieImpl(penv);
            if (proot)
                G_SetFlag<0x2000>(*reinterpret_cast<UInt32*>(proot + 0x3490), val.ToBool(penv));
        }
    }
    return Object::SetMemberRaw(penv->GetSC(), name, val, flags);
}

// @0x14291c160
GASGlobalObject::GASGlobalObject(GlobalContext* pcontext)
    : Object(pcontext->pMovieRoot ? static_cast<MovieRoot*>(pcontext->pMovieRoot->pASMovieRoot)->MemContext->ASGC
                                : (ASRefCountCollector*)0), pContext(pcontext)
{
}

// Keeps a value alive across calls that may unload its character: a copy of the value and, for a character value,
// the display object while it is still on the stage (0x30 bytes).
class ValueGuard
{
public:
    Environment*   pEnv;    // +0x00
    Value          Val;     // +0x08
    DisplayObject* pObject; // +0x28

    ValueGuard(Environment* penv, const Value& v);
    ~ValueGuard();
    ValueGuard& operator=(const Value& v);
};

// Holds the character of a character value only when it is an interactive object.
// @0x142923dd0
ValueGuard::ValueGuard(Environment* penv, const Value& v)
    : pEnv(penv), Val(v)
{
    if (v.GetType() == Value::CHARACTER)
    {
        DisplayObject* pdobj = 0;
        if (pEnv && v.V.pCharHandle)
            pdobj = v.V.pCharHandle->ResolveCharacter(pEnv->Target->GetMovieImpl());
        pObject = pdobj ? (pdobj->IsInteractiveObject() ? pdobj : 0) : 0;
        if (pObject)
            pObject->AddRef();
    }
    else
        pObject = 0;
}

// @0x1429260c0
ValueGuard::~ValueGuard()
{
    if (pObject)
        pObject->Release();
}

// As the ctor, but the exe AddRefs without a null check (a character value that does not resolve to an interactive
// object faults here in the exe too).
// @0x142926a00
ValueGuard& ValueGuard::operator=(const Value& v)
{
    Val = v;
    if (pObject)
        pObject->Release();
    if (v.GetType() == Value::CHARACTER)
    {
        DisplayObject* pdobj = 0;
        if (pEnv && v.V.pCharHandle)
            pdobj = v.V.pCharHandle->ResolveCharacter(pEnv->Target->GetMovieImpl());
        pObject = pdobj ? (pdobj->IsInteractiveObject() ? pdobj : 0) : 0;
        pObject->AddRef();
    }
    else
        pObject = 0;
    return *this;
}

// The with-stack of an execution context, owned through a pointer (0x10 bytes).
struct WithStackHolder
{
    UPInt           Field0;
    WithStackArray* pStack; // +0x08
    ~WithStackHolder() { delete pStack; }
};

// @0x1429261c0
void FUN_WithStackHolder_dtor(WithStackHolder* p) { p->~WithStackHolder(); }

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The AS side of a host value: the AS object (the character's own for a display object), the level-0
// environment and the AS movie root (0x18 bytes).
// MS2-FUNCTIONAL: the interface's movie is its first member
struct Value_AS2ObjectData
{
    AS2::ObjectInterface* pObject; // +0x00
    AS2::Environment*     pEnv;    // +0x08
    AS2::MovieRoot*       pRoot;   // +0x10

    Value_AS2ObjectData(Value::ObjectInterface* pif, void* pdata, bool isdobj);
};

struct InterfaceAccess : public Value::ObjectInterface
{
    using Value::ObjectInterface::pMovieRoot;
};

// The SDK's ToAvmCharacter, with its null check.
SF_FORCEINLINE AS2::AvmCharacter* VodToAvmCharacter(InteractiveObject* po)
{
    if (!po)
        return NULL;
    return static_cast<AS2::AvmCharacter*>(po->GetAvmIntObj());
}

// @0x142923f30
Value_AS2ObjectData::Value_AS2ObjectData(Value::ObjectInterface* pif, void* pdata, bool isdobj)
{
    MovieImpl* pmovie = static_cast<InterfaceAccess*>(pif)->pMovieRoot;
    pRoot             = static_cast<AS2::MovieRoot*>(pmovie->pASMovieRoot);
    AvmDisplayObjBase* pmain = pRoot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    pEnv = static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
    pObject = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
        if (!pdobj)
        {
            pObject = 0;   // the handle no longer resolves
            return;
        }
        // the character's own ObjectInterface (+8), not its AS object
        pObject = VodToAvmCharacter(static_cast<InteractiveObject*>(pdobj));
    }
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS2 {

struct ArgWords
{
    UPInt A, B;
};

// A heap-owned copy of a 16-byte element array, kept next to its heap (the argument list of a function object).
struct HeapArrayCopy
{
    MemoryHeap*                    pHeap;
    ArrayLH_POD<ArgWords, 323>*    pArray;
};

// A heap-new copy of the source array, or null when there is none.
// @0x142924090
HeapArrayCopy* FUN_142924090(HeapArrayCopy* pret, MemoryHeap* pheap, const ArrayLH_POD<ArgWords, 323>* psrc)
{
    pret->pHeap = pheap;
    pret->pArray = psrc ? SF_HEAP_NEW(pheap) ArrayLH_POD<ArgWords, 323>(*psrc) : 0;
    return pret;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7GASGlobalObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143220278
// MS2-PIN: ??_7GASGlobalObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432202c0
