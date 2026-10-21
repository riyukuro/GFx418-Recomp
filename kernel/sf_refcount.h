// Recovered Scaleform GFx 4.1.18: reference counting (thread-safe RefCountImpl / virtual RefCountVImpl / single-thread
// RefCountNTSImpl, weak-pointer support), the RefCountBase* templates with their heap operators, Ptr<> and WeakPtr<>.
#ifndef MS2_SF_KERNEL_REFCOUNT_H
#define MS2_SF_KERNEL_REFCOUNT_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform {

class WeakPtrProxy;

#define SF_REFCOUNT_NORMAL     0x00000000
#define SF_REFCOUNT_THREADSAFE 0x00000001

// vfptr + count (starts at 1)
class RefCountImplCore
{
protected:
    volatile int RefCount;
public:
    SF_INLINE RefCountImplCore() : RefCount(1) { }
    virtual ~RefCountImplCore();
    int GetRefCount() const { return RefCount; }
    static void checkInvalidDelete(RefCountImplCore*) { }
    void operator=(const RefCountImplCore&) { }
};

class RefCountNTSImplCore
{
protected:
    mutable int RefCount;
public:
    SF_INLINE RefCountNTSImplCore() : RefCount(1) { }
    virtual ~RefCountNTSImplCore();
    int GetRefCount() const { return RefCount; }
    static void checkInvalidDelete(RefCountNTSImplCore*) { }
    void operator=(const RefCountNTSImplCore&) { }
};

class RefCountImpl : public RefCountImplCore
{
public:
    void AddRef();
    void Release();
};

class RefCountVImpl : public RefCountImplCore
{
public:
    virtual void AddRef();
    virtual void Release();
};

class RefCountNTSImpl : public RefCountNTSImplCore
{
public:
    SF_INLINE void AddRef() const { RefCount++; }
    void Release() const;
};

class RefCountWeakSupportImpl : public RefCountNTSImpl
{
protected:
    mutable WeakPtrProxy* pWeakProxy;
public:
    RefCountWeakSupportImpl() { pWeakProxy = 0; }
    virtual ~RefCountWeakSupportImpl();
    WeakPtrProxy* CreateWeakProxy() const;
};

// Adds the heap-aware operator new/delete set to a ref-count implementation.
template<class Base, int StatType>
class RefCountBaseStatImpl : public Base
{
public:
    RefCountBaseStatImpl() { }
#define SF_REFCOUNTALLOC_CHECK_DELETE(class_name, p)
    SF_MEMORY_REDEFINE_NEW_IMPL(Base, SF_REFCOUNTALLOC_CHECK_DELETE, StatType)
};

template<class C, int Stat>
class RefCountBase : public RefCountBaseStatImpl<RefCountImpl, Stat>
{
public:
    enum { StatType = Stat };
    SF_INLINE RefCountBase() : RefCountBaseStatImpl<RefCountImpl, Stat>() { }
};

template<class C, int Stat>
class RefCountBaseV : public RefCountBaseStatImpl<RefCountVImpl, Stat>
{
public:
    enum { StatType = Stat };
    SF_INLINE RefCountBaseV() : RefCountBaseStatImpl<RefCountVImpl, Stat>() { }
};

template<class C, int Stat>
class RefCountBaseNTS : public RefCountBaseStatImpl<RefCountNTSImpl, Stat>
{
public:
    enum { StatType = Stat };
    SF_INLINE RefCountBaseNTS() : RefCountBaseStatImpl<RefCountNTSImpl, Stat>() { }
};

template<class C, int Stat>
class RefCountBaseWeakSupport : public RefCountBaseStatImpl<RefCountWeakSupportImpl, Stat>
{
public:
    enum { StatType = Stat };
    SF_INLINE RefCountBaseWeakSupport() : RefCountBaseStatImpl<RefCountWeakSupportImpl, Stat>() { }
};

// A raw pointer whose reference is handed over (not added) when it initializes a Ptr.
enum PickType { PickValue };

template<typename T>
class Pickable
{
public:
    Pickable() : pV(NULL) { }
    explicit Pickable(T* p) : pV(p) { }
    Pickable(T* p, PickType) : pV(p) { if (pV) pV->AddRef(); }
    template<typename OT> Pickable(const Pickable<OT>& o) : pV(o.GetPtr()) { }
    Pickable& operator=(const Pickable& o) { pV = o.pV; return *this; }
    T* GetPtr() const { return pV; }
    T* operator->() const { return pV; }
    T& operator*() const { return *pV; }
private:
    T* pV;
};

template<typename T>
SF_INLINE Pickable<T> MakePickable(T* p) { return Pickable<T>(p); }

template<class C>
class Ptr
{
protected:
    C* pObject;
public:
    SF_INLINE Ptr() : pObject(0) { }
    SF_INLINE Ptr(C& obj) : pObject(&obj) { }
    SF_INLINE Ptr(Pickable<C> v) : pObject(v.GetPtr()) { }
    SF_INLINE Ptr(Ptr<C>& other, PickType) : pObject(other.pObject) { other.pObject = NULL; }
    SF_INLINE Ptr(C* p)
    {
        if (p) p->AddRef();
        pObject = p;
    }
    SF_INLINE Ptr(const Ptr<C>& src)
    {
        if (src.pObject) src.pObject->AddRef();
        pObject = src.pObject;
    }
    template<class R>
    SF_INLINE Ptr(Ptr<R>& src)
    {
        if (src) src->AddRef();
        pObject = src;
    }
    template<class R>
    SF_INLINE Ptr(Pickable<R> v) : pObject(v.GetPtr()) { }
    SF_INLINE ~Ptr()
    {
        if (pObject) pObject->Release();
    }

    SF_INLINE bool operator==(const Ptr& o) const { return pObject == o.pObject; }
    SF_INLINE bool operator!=(const Ptr& o) const { return pObject != o.pObject; }
    SF_INLINE bool operator==(C* p) const { return pObject == p; }
    SF_INLINE bool operator!=(C* p) const { return pObject != p; }
    SF_INLINE bool operator<(const Ptr& o) const { return pObject < o.pObject; }

    template<class R>
    SF_INLINE const Ptr<C>& operator=(const Ptr<R>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    SF_INLINE const Ptr<C>& operator=(const Ptr<C>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    SF_INLINE const Ptr<C>& operator=(C* p)
    {
        if (p) p->AddRef();
        if (pObject) pObject->Release();
        pObject = p;
        return *this;
    }
    SF_INLINE const Ptr<C>& operator=(C& src)
    {
        if (pObject) pObject->Release();
        pObject = &src;
        return *this;
    }
    SF_INLINE Ptr<C>& operator=(Pickable<C> src) { return Pick(src); }
    template<class R>
    SF_INLINE Ptr<C>& operator=(Pickable<R> src) { return Pick(src); }

    template<class R>
    SF_INLINE Ptr<C>& SetPtr(const Ptr<R>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    SF_INLINE Ptr<C>& SetPtr(const Ptr<C>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    SF_INLINE Ptr<C>& SetPtr(C* p)
    {
        if (p) p->AddRef();
        if (pObject) pObject->Release();
        pObject = p;
        return *this;
    }
    SF_INLINE Ptr<C>& SetPtr(C& src)
    {
        if (pObject) pObject->Release();
        pObject = &src;
        return *this;
    }
    SF_INLINE Ptr<C>& SetPtr(Pickable<C> src) { return Pick(src); }

    SF_INLINE void NullWithoutRelease() { pObject = 0; }
    SF_INLINE void Clear()
    {
        if (pObject) pObject->Release();
        pObject = 0;
    }

    SF_INLINE C*& GetRawRef() { return pObject; }
    SF_INLINE C* GetPtr() const { return pObject; }
    SF_INLINE C& operator*() const { return *pObject; }
    SF_INLINE C* operator->() const { return pObject; }
    SF_INLINE operator C*() const { return pObject; }

    SF_INLINE Ptr<C>& Pick(Ptr<C>& other)
    {
        if (&other != this)
        {
            if (pObject) pObject->Release();
            pObject = other.pObject;
            other.pObject = 0;
        }
        return *this;
    }
    SF_INLINE Ptr<C>& Pick(Pickable<C> v)
    {
        if (v.GetPtr() != pObject)
        {
            if (pObject) pObject->Release();
            pObject = v.GetPtr();
        }
        return *this;
    }
    template<class R>
    SF_INLINE Ptr<C>& Pick(Pickable<R> v)
    {
        if (v.GetPtr() != pObject)
        {
            if (pObject) pObject->Release();
            pObject = v.GetPtr();
        }
        return *this;
    }
    SF_INLINE Ptr<C>& Pick(C* p)
    {
        if (p != pObject)
        {
            if (pObject) pObject->Release();
            pObject = p;
        }
        return *this;
    }
};

// Shared liveness record between an object with weak support and its WeakPtrs.
class WeakPtrProxy : public NewOverrideBase<Stat_Default_Mem>
{
public:
    WeakPtrProxy(RefCountWeakSupportImpl* obj) : RefCount(1), pObject(obj) { }
    SF_INLINE bool IsAlive() const { return pObject != 0; }
    SF_INLINE void NotifyObjectDied() { pObject = 0; }
    RefCountWeakSupportImpl* GetObject() const { return pObject; }
    SF_INLINE void AddRef() { RefCount++; }
    SF_INLINE void Release()
    {
        RefCount--;
        if (RefCount == 0)
            delete this;
    }
private:
    WeakPtrProxy(const WeakPtrProxy&);
    void operator=(const WeakPtrProxy&);
    int                      RefCount;
    RefCountWeakSupportImpl* pObject;
};

template<class C>
class WeakPtr
{
public:
    WeakPtr() { }
    SF_INLINE WeakPtr(C* p) : pProxy(*(p ? p->CreateWeakProxy() : (WeakPtrProxy*)0)) { }
    SF_INLINE WeakPtr(const Ptr<C>& p) : pProxy(*(p.GetPtr() ? p->CreateWeakProxy() : (WeakPtrProxy*)0)) { }
    SF_INLINE void operator=(C* p)
    {
        if (p)
            pProxy = *p->CreateWeakProxy();
        else
            pProxy.Clear();
    }
    SF_INLINE void operator=(const Ptr<C>& p) { operator=(p.GetPtr()); }
    operator Ptr<C>() const { return Ptr<C>(GetObjectThroughProxy()); }
    SF_INLINE bool operator==(C* p) { return GetObjectThroughProxy() == p; }
    SF_INLINE bool operator==(const Ptr<C>& p) { return GetObjectThroughProxy() == p.GetPtr(); }
private:
    SF_INLINE C* GetObjectThroughProxy() const
    {
        C* obj = 0;
        if (pProxy)
        {
            if (pProxy->IsAlive())
            {
                obj = (C*)pProxy->GetObject();
                if (obj->GetRefCount() == 0)
                    obj = 0;
            }
            else
                pProxy.Clear();
        }
        return obj;
    }
    mutable Ptr<WeakPtrProxy> pProxy;
};

}  // namespace Scaleform

#endif
