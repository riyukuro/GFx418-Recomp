// Recovered Scaleform 4.1.18 GFx AS2: the prototype objects of the built-in classes (Prototype<BaseClass>: an
// instance of the class plus the constructor links and implemented interfaces) and super.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// Only the collector traversal is recovered so far; the prototype constructors, GetMemberRaw and friends are
// declared when their units are recovered.
#ifndef MS2_SF_GFX_AS2_OBJECTPROTO_H
#define MS2_SF_GFX_AS2_OBJECTPROTO_H

#include "as2_object.h"
#include "as2_refcountcollector.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The class-independent part of a prototype; it follows the class instance inside Prototype<>. 0x40 bytes.
class GASPrototypeBase
{
protected:
    // The interfaces are released by the collector: finalizing only frees the buffer (default stat, as the exe resize).
    class InterfacesArray : public ArrayLH<Ptr<Object> >
    {
    public:
        InterfacesArray(int size) : ArrayLH<Ptr<Object> >(size) {}

        void Finalize_GC() { AllocatorType::Free(Data.Data); }
    };

    FunctionRef      Constructor;     // +0x08 the "constructor" member
    FunctionRef      __Constructor__; // +0x20
    InterfacesArray* pInterfaces;     // +0x38 implemented interfaces (implements)

    GASPrototypeBase() : pInterfaces(0) {}

    // One of the interfaces is an instance of prototype (exe 0x1429396a0).
    bool DoesImplement(Environment* penv, const Object* prototype) const;
    // Appends ctor's prototype to the interfaces at index; allocates the array first (exe 0x14292f250).
    void AddInterface(ASStringContext* psc, int index, FunctionObject* ctor);

    // Sets "constructor" of the prototype pthis (exe 0x14297ffc0).
    bool SetConstructor(Object* pthis, ASStringContext* psc, const Value& ctor);
    // Part of the prototype construction: the constructor, and its "prototype" member back to pthis
    // (exe 0x14295e1b0).
    void Init(Object* pthis, ASStringContext* psc, const FunctionRef& constructor);
    // Adds the table's functions to the prototype pthis (exe 0x142961830).
    void InitFunctionMembers(Object* pthis, ASStringContext* psc, const NameFunction* table,
                             const PropFlags& flags = PropFlags::PropFlag_DontEnum);

public:
    virtual ~GASPrototypeBase();

    // "constructor" / "__constructor__" of the prototype pthis (exe 0x142953980).
    bool GetMemberRawConstructor(Object* pthis, ASStringContext* psc, const ASString& name, Value* val,
                                 bool isConstructor2);
};

// Prototype object of a built-in class: an instance of BaseClass whose prototype part sits right behind it.
template<class BaseClass, class GASEnvironment = Environment>
class Prototype : public BaseClass, public GASPrototypeBase
{
protected:
    typedef ASRefCountBaseType::Collector Collector;
    typedef ASRefCountBaseType::OperationGC OperationGC;

    template<class Functor>
    void ForEachChild_GC(Collector* prcc) const
    {
        BaseClass::template ForEachChild_GC<Functor>(prcc);
        Constructor.template ForEachChild_GC<Functor>(prcc);
        __Constructor__.template ForEachChild_GC<Functor>(prcc);
        if (pInterfaces)
        {
            for (UPInt i = 0, n = pInterfaces->GetSize(); i < n; ++i)
            {
                const Ptr<Object>& pintf = (*pInterfaces)[i];
                if (pintf)
                    Functor::Call(prcc, pintf);
            }
        }
    }

public:
    Prototype(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
        : BaseClass(psc, pprototype)
    {
        Init(this, psc, constructor);
    }
    // (appended for sfr_as2_03) without the constructor (exe 0x14291fa90 for Object).
    Prototype(ASStringContext* psc, Object* pprototype)
        : BaseClass(psc, pprototype)
    {
    }
    // (appended for sfr_as2_03) a prototype without a prototype of its own (inlined into the exe's ObjectProto ctor).
    Prototype(ASStringContext* psc, const FunctionRef& constructor)
        : BaseClass(psc)
    {
        Init(this, psc, constructor);
    }
    virtual ~Prototype() {}

    // constructor and __constructor__ come from the prototype part (defined in sfr_as2_05).
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val)
    {
        return GetMemberRaw(penv->GetSC(), name, val);
    }
    virtual bool DoesImplement(Environment* penv, const Object* prototype) const
    {
        if (this == prototype)
            return true;
        return GASPrototypeBase::DoesImplement(penv, prototype);
    }
    virtual bool IsBuiltinPrototype() const { return true; }
    virtual void AddInterface(ASStringContext* psc, int index, FunctionObject* ctor)
    {
        GASPrototypeBase::AddInterface(psc, index, ctor);
    }

protected:
    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const
    {
        switch (operation)
        {
        case ASRefCountBaseType::Operation_Release:
            ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(prcc);
            break;
        case ASRefCountBaseType::Operation_MarkInCycle:
            ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
            break;
        case ASRefCountBaseType::Operation_ScanInUse:
            ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(prcc);
            break;
        default:;
        }
    }
    void Finalize_GC()
    {
        if (pInterfaces)
        {
            pInterfaces->Finalize_GC();
            SF_FREE(pInterfaces);
        }
        BaseClass::Finalize_GC();
    }
};

// The "super" object of a method call: forwards member lookups to the prototype chain above the caller's. 0x98
// bytes.
class SuperObject : public Object
{
public:
    Ptr<Object>      SuperProto;  // +0x68
    Ptr<Object>      SavedProto;  // +0x70
    ObjectInterface* RealThis;    // +0x78
    FunctionRef      Constructor; // +0x80

    SuperObject(Object* pproto, ObjectInterface* prealThis, const FunctionRef& ctor); // exe 0x1429213a0
    virtual FunctionRef Get__constructor__(ASStringContext* psc); // exe 0x142958370
    // Back to the saved prototype after an alternate one was set (exe 0x14297dfb0).
    void ResetAltProto();
    // (appended, sfr36) Member lookups start at pproto until ResetAltProto (inlined in the exe, e.g. by the
    // call method action).
    void SetAltProto(Object* pproto)
    {
        if (pproto == SuperProto)
            return;
        SavedProto = SuperProto;
        SuperProto = pproto;
        pProto     = SuperProto;
    }

protected:
    template<class Functor>
    void ForEachChild_GC(Collector* prcc) const
    {
        Object::template ForEachChild_GC<Functor>(prcc);
        if (SuperProto)
            Functor::Call(prcc, SuperProto);
        if (SavedProto)
            Functor::Call(prcc, SavedProto);
        Constructor.template ForEachChild_GC<Functor>(prcc);
    }

    virtual void Finalize_GC(); // exe 0x142943020
};

// The Object class.
class ObjectCtorFunction : public CFunctionObject
{
public:
    ObjectCtorFunction(ASStringContext* psc); // exe 0x14291f8e0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937170

    static const NameFunction StaticFunctionTable[]; // exe 0x1432142f0: registerClass

private:
    // (appended for sfr_as2_02)
    static void RegisterClassA(const FnCall& fn); // exe 0x142908e90 (registerClass)
};

// Object.prototype methods (only the natives so far).
class ObjectProto : public Prototype<Object>
{
public:
    // The Object prototype and its function table (exe 0x143214310).
    ObjectProto(ASStringContext* psc, Object* pprototype);                                // exe 0x14291fa90
    ObjectProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291fb00
    ObjectProto(ASStringContext* psc, const FunctionRef& constructor);                    // exe 0x14291f9a0
    static const NameFunction FunctionTable[];

    static void AddProperty(const FnCall& fn);
    static void HasOwnProperty(const FnCall& fn);
    static void IsPropertyEnumerable(const FnCall& fn);
    static void IsPrototypeOf(const FnCall& fn);
    static void Watch_(const FnCall& fn);
    static void Unwatch_(const FnCall& fn);
    static void ToString(const FnCall& fn);

    // Object(v) wraps a primitive or returns the object; otherwise the instance (a new one when called as a
    // function) gets its constructor (exe 0x14295bee0).
    static void GlobalCtor(const FnCall& fn);
};

// Function.prototype methods (only the natives so far).
class FunctionProto : public Prototype<Object>
{
public:
    // The Function prototype; apply and call are added only when asked (exe 0x14291c0f0).
    FunctionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, bool addApply);
    static const NameFunction FunctionTable[]; // exe 0x143213e80

    static void Apply(const FnCall& fn);
    static void Call(const FnCall& fn);
    static void ToString(const FnCall& fn);

    // Function(f) returns the function f (null for anything else), Function() a new empty function object
    // (exe 0x14295ae40).
    static void GlobalCtor(const FnCall& fn);
};

// The Function class.
class FunctionCtorFunction : public CFunctionObject
{
public:
    FunctionCtorFunction(ASStringContext* psc); // exe 0x14291c010

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936d90
};

}}} // namespace Scaleform::GFx::AS2

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS2::SuperObject) == 0x98, "SuperObject size");

#endif
