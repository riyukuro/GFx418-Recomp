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
    typedef ArrayLH<Ptr<Object>, StatMV_ActionScript_Mem> InterfacesArray;

    FunctionRef      Constructor;     // +0x08 the "constructor" member
    FunctionRef      __Constructor__; // +0x20
    InterfacesArray* pInterfaces;     // +0x38 implemented interfaces (implements)

public:
    virtual ~GASPrototypeBase();
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
};

// Function.prototype methods (only the natives so far).
class FunctionProto
{
public:
    static void Apply(const FnCall& fn);
    static void Call(const FnCall& fn);
    static void ToString(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
