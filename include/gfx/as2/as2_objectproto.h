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
    // The interfaces are released by the collector: finalizing only frees the buffer.
    class InterfacesArray : public ArrayLH<Ptr<Object>, StatMV_ActionScript_Mem>
    {
    public:
        void Finalize_GC() { AllocatorType::Free(Data.Data); }
    };

    FunctionRef      Constructor;     // +0x08 the "constructor" member
    FunctionRef      __Constructor__; // +0x20
    InterfacesArray* pInterfaces;     // +0x38 implemented interfaces (implements)

    // One of the interfaces is an instance of prototype (exe 0x1429396a0).
    bool DoesImplement(Environment* penv, const Object* prototype) const;

    // Sets "constructor" of the prototype pthis (exe 0x14297ffc0).
    bool SetConstructor(Object* pthis, ASStringContext* psc, const Value& ctor);
    // Part of the prototype construction: the constructor, and its "prototype" member back to pthis
    // (exe 0x14295e1b0).
    void Init(Object* pthis, ASStringContext* psc, const FunctionRef& constructor);

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
    // constructor and __constructor__ come from the prototype part (defined in sfr_as2_05).
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);

protected:
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

    virtual FunctionRef Get__constructor__(ASStringContext* psc); // exe 0x142958370
    // Back to the saved prototype after an alternate one was set (exe 0x14297dfb0).
    void ResetAltProto();

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
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937170
};

// Object.prototype methods (only the natives so far).
class ObjectProto
{
public:
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
class FunctionProto
{
public:
    static void Apply(const FnCall& fn);
    static void Call(const FnCall& fn);
    static void ToString(const FnCall& fn);

    // Function(f) returns the function f (null for anything else), Function() a new empty function object
    // (exe 0x14295ae40).
    static void GlobalCtor(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
