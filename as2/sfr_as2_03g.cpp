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
    if (name.GetNode() != psc->GetBuiltin(Builtin_gfxExtensions).GetNode())
        return Object::GetMemberRaw(psc, name, val);
    UByte ext = pContext->GFxExtensions.Value;
    val->DropRefs();
    if (ext)
    {
        val->SetBool(ext == Bool3W::B3W_True);
        return true;
    }
    val->SetUndefined();
    return false;
}

// Assigning gfxExtensions switches the extensions (and the gfxVersion member) on or off; with them on,
// noInvisibleAdvance and continueAnimation set the movie's flags.
// MS2-FUNCTIONAL: the movie flags are read by address
// @0x142985ef0
bool GASGlobalObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    MovieRoot* proot = static_cast<MovieRoot*>(penv->StringContext.pContext->pMovieRoot->pASMovieRoot);
    if (name.GetNode() == proot->GetStringManager()->GetBuiltin(Builtin_gfxExtensions).GetNode())
    {
        pContext->GFxExtensions.Value = val.ToBool(penv) ? Bool3W::B3W_True : Bool3W::B3W_False;
        if (pContext->GFxExtensions.Value == Bool3W::B3W_True)
        {
            Value ver(penv->CreateConstString("4.1.18"));
            PropFlags nf(0);
            SetMemberRaw(&penv->StringContext, penv->CreateConstString("gfxVersion"), ver, nf);
        }
        else
            DeleteMember(&penv->StringContext, penv->CreateConstString("gfxVersion"));
        Value dummy;
        dummy.SetUnset();
        return Object::SetMember(penv, name, dummy, flags);
    }
    if (pContext->GFxExtensions.Value == Bool3W::B3W_True)
    {
        UByte* pmovie = 0;
        if (name.GetNode() == proot->GetStringManager()->GetBuiltin(Builtin_noInvisibleAdvance).GetNode())
        {
            pmovie = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(penv->Target) + 0x20) ;
            pmovie = *reinterpret_cast<UByte**>(pmovie + 0x10);
            if (pmovie)
            {
                UInt32* pflags = reinterpret_cast<UInt32*>(pmovie + 0x3490);
                *pflags = val.ToBool(penv) ? (*pflags | 0x800) : (*pflags & ~0x800u);
            }
        }
        else if (name.GetNode() == proot->GetStringManager()->GetBuiltin(Builtin_continueAnimation).GetNode())
        {
            pmovie = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(penv->Target) + 0x20);
            pmovie = *reinterpret_cast<UByte**>(pmovie + 0x10);
            if (pmovie)
            {
                UInt32* pflags = reinterpret_cast<UInt32*>(pmovie + 0x3490);
                *pflags = val.ToBool(penv) ? (*pflags | 0x2000) : (*pflags & ~0x2000u);
            }
        }
    }
    return Object::SetMemberRaw(&penv->StringContext, name, val, flags);
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

// MS2-FUNCTIONAL: the stage flag is read by address
// @0x142923dd0
ValueGuard::ValueGuard(Environment* penv, const Value& v)
    : pEnv(penv), Val(v)
{
    pObject = 0;
    if (v.GetType() == Value::CHARACTER)
    {
        DisplayObject* pdobj = 0;
        if (pEnv && v.V.pCharHandle)
            pdobj = v.V.pCharHandle->ResolveCharacter(pEnv->Target->GetMovieImpl());
        if (pdobj && (*(reinterpret_cast<SInt8*>(pdobj) + 0x6a) < 0))
        {
            pObject = pdobj;
            pdobj->AddRef();
        }
    }
}

// @0x1429260c0
ValueGuard::~ValueGuard()
{
    if (pObject)
        pObject->Release();
}

// MS2-FUNCTIONAL: the stage flag is read by address
// @0x142926a00
ValueGuard& ValueGuard::operator=(const Value& v)
{
    Val = v;
    if (pObject)
        pObject->Release();
    pObject = 0;
    if (v.GetType() == Value::CHARACTER)
    {
        DisplayObject* pdobj = 0;
        if (pEnv && v.V.pCharHandle)
            pdobj = v.V.pCharHandle->ResolveCharacter(pEnv->Target->GetMovieImpl());
        if (pdobj && (*(reinterpret_cast<SInt8*>(pdobj) + 0x6a) < 0))
        {
            pObject = pdobj;
            pdobj->AddRef();
        }
    }
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
            pObject = 0;
        else
            pObject = static_cast<AS2::AvmCharacter*>(static_cast<InteractiveObject*>(pdobj)->GetAvmIntObj())
                          ->GetASObject();
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

// MS2-FUNCTIONAL: the array is the plain POD array with its size policy
// @0x142924090
HeapArrayCopy* FUN_142924090(HeapArrayCopy* pret, MemoryHeap* pheap, const ArrayLH_POD<ArgWords, 323>* psrc)
{
    pret->pHeap = pheap;
    if (!psrc)
    {
        pret->pArray = 0;
        return pret;
    }
    void* pmem = pheap->Alloc(0x18);
    if (!pmem)
    {
        pret->pArray = 0;
        return pret;
    }
    ArrayLH_POD<ArgWords, 323>* parr = ::new (pmem) ArrayLH_POD<ArgWords, 323>();
    UPInt n = psrc->GetSize();
    if (n)
    {
        parr->Resize(n);
        memcpy(&(*parr)[0], &(*psrc)[0], n << 4);
    }
    pret->pArray = parr;
    return pret;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7GASGlobalObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143220278
// MS2-PIN: ??_7GASGlobalObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432202c0
