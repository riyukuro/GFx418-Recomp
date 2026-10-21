// Recovered Scaleform 4.1.18 kernel: reference counting bases and the Ptr<> smart pointer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The out-of-line members live in the kernel units (sfr_kernel_*); until those are recovered they bind to the exe:
//   RefCountImplCore::~RefCountImplCore 0x14257db40, RefCountNTSImplCore::~RefCountNTSImplCore 0x14257db50,
//   RefCountImpl::AddRef 0x14257dc30, RefCountImpl::Release 0x14257dcb0, RefCountNTSImpl::Release 0x14257dcd0.
#ifndef MS2_SF_KERNEL_REFCOUNT_H
#define MS2_SF_KERNEL_REFCOUNT_H

#include "sf_memory.h"

namespace Scaleform {

// Thread-safe count (atomic AddRef/Release in RefCountImpl).
class RefCountImplCore
{
protected:
    volatile int RefCount;
public:
    RefCountImplCore() : RefCount(1) {}
    virtual ~RefCountImplCore();
    int  GetRefCount() const { return RefCount; }
    static void checkInvalidDelete(RefCountImplCore*) {}
    void operator=(const RefCountImplCore&) {}
};

// Single-threaded count.
class RefCountNTSImplCore
{
protected:
    mutable int RefCount;
public:
    RefCountNTSImplCore() : RefCount(1) {}
    virtual ~RefCountNTSImplCore();
    int  GetRefCount() const { return RefCount; }
    static void checkInvalidDelete(RefCountNTSImplCore*) {}
    void operator=(const RefCountNTSImplCore&) {}
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
    void AddRef() const { RefCount++; }
    void Release() const;
};

// Adds the Scaleform heap operator new/delete set to a reference counted base.
template<class Base, int StatType>
class RefCountBaseStatImpl : public Base
{
public:
    RefCountBaseStatImpl() {}
#define SF_REFCOUNTALLOC_CHECK_DELETE(class_name, p)
    SF_MEMORY_REDEFINE_NEW_IMPL(Base, SF_REFCOUNTALLOC_CHECK_DELETE, StatType)
};

template<class C, int Stat>
class RefCountBase : public RefCountBaseStatImpl<RefCountImpl, Stat>
{
public:
    enum { StatType = Stat };
    RefCountBase() : RefCountBaseStatImpl<RefCountImpl, Stat>() {}
};

template<class C, int Stat>
class RefCountBaseV : public RefCountBaseStatImpl<RefCountVImpl, Stat>
{
public:
    enum { StatType = Stat };
    RefCountBaseV() : RefCountBaseStatImpl<RefCountVImpl, Stat>() {}
};

template<class C, int Stat>
class RefCountBaseNTS : public RefCountBaseStatImpl<RefCountNTSImpl, Stat>
{
public:
    enum { StatType = Stat };
    RefCountBaseNTS() : RefCountBaseStatImpl<RefCountNTSImpl, Stat>() {}
};

// A pointer whose reference is handed over without an AddRef (Ptr<T> p = *new T).
enum PickType { PickValue };

template<typename T>
class Pickable
{
public:
    Pickable() : pV(NULL) {}
    explicit Pickable(T* p) : pV(p) {}
    Pickable(T* p, PickType) : pV(p) { if (pV) pV->AddRef(); }
    template<typename OT>
    Pickable(const Pickable<OT>& other) : pV(other.GetPtr()) {}

    Pickable& operator=(const Pickable& other) { pV = other.pV; return *this; }

    T* GetPtr() const     { return pV; }
    T* operator->() const { return pV; }
    T& operator*() const  { return *pV; }
private:
    T* pV;
};

template<typename T>
inline Pickable<T> MakePickable(T* p) { return Pickable<T>(p); }

// Intrusive smart pointer: AddRef on store, Release on overwrite/destruction. Assigning a reference (*p) takes it over
// without AddRef.
template<class C>
class Ptr
{
protected:
    C* pObject;
public:
    Ptr() : pObject(0) {}
    Ptr(C& robj) : pObject(&robj) {}
    Ptr(Pickable<C> v) : pObject(v.GetPtr()) {}
    Ptr(Ptr<C>& other, PickType) : pObject(other.pObject) { other.pObject = NULL; }
    Ptr(C* pobj)
    {
        if (pobj) pobj->AddRef();
        pObject = pobj;
    }
    Ptr(const Ptr<C>& src)
    {
        if (src.pObject) src.pObject->AddRef();
        pObject = src.pObject;
    }
    template<class R>
    Ptr(Ptr<R>& src)
    {
        if (src) src->AddRef();
        pObject = src;
    }
    template<class R>
    Ptr(Pickable<R> v) : pObject(v.GetPtr()) {}

    ~Ptr()
    {
        if (pObject) pObject->Release();
    }

    bool operator==(const Ptr& other) const { return pObject == other.pObject; }
    bool operator!=(const Ptr& other) const { return pObject != other.pObject; }
    bool operator==(C* pother) const        { return pObject == pother; }
    bool operator!=(C* pother) const        { return pObject != pother; }
    bool operator<(const Ptr& other) const  { return pObject < other.pObject; }

    template<class R>
    const Ptr<C>& operator=(const Ptr<R>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    const Ptr<C>& operator=(const Ptr<C>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    const Ptr<C>& operator=(C* psrc)
    {
        if (psrc) psrc->AddRef();
        if (pObject) pObject->Release();
        pObject = psrc;
        return *this;
    }
    const Ptr<C>& operator=(C& src)
    {
        if (pObject) pObject->Release();
        pObject = &src;
        return *this;
    }
    Ptr<C>& operator=(Pickable<C> src) { return Pick(src); }
    template<class R>
    Ptr<C>& operator=(Pickable<R> src) { return Pick(src); }

    template<class R>
    Ptr<C>& SetPtr(const Ptr<R>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    Ptr<C>& SetPtr(const Ptr<C>& src)
    {
        if (src) src->AddRef();
        if (pObject) pObject->Release();
        pObject = src;
        return *this;
    }
    Ptr<C>& SetPtr(C* psrc)
    {
        if (psrc) psrc->AddRef();
        if (pObject) pObject->Release();
        pObject = psrc;
        return *this;
    }
    Ptr<C>& SetPtr(C& src)
    {
        if (pObject) pObject->Release();
        pObject = &src;
        return *this;
    }
    Ptr<C>& SetPtr(Pickable<C> src) { return Pick(src); }

    void NullWithoutRelease() { pObject = 0; }
    void Clear()
    {
        if (pObject) pObject->Release();
        pObject = 0;
    }

    C*& GetRawRef()          { return pObject; }
    C*  GetPtr() const       { return pObject; }
    C&  operator*() const    { return *pObject; }
    C*  operator->() const   { return pObject; }
    operator C*() const      { return pObject; }

    Ptr<C>& Pick(Ptr<C>& other)
    {
        if (&other != this)
        {
            if (pObject) pObject->Release();
            pObject = other.pObject;
            other.pObject = 0;
        }
        return *this;
    }
    Ptr<C>& Pick(Pickable<C> v)
    {
        if (v.GetPtr() != pObject)
        {
            if (pObject) pObject->Release();
            pObject = v.GetPtr();
        }
        return *this;
    }
    template<class R>
    Ptr<C>& Pick(Pickable<R> v)
    {
        if (v.GetPtr() != pObject)
        {
            if (pObject) pObject->Release();
            pObject = v.GetPtr();
        }
        return *this;
    }
    Ptr<C>& Pick(C* p)
    {
        if (p != pObject)
        {
            if (pObject) pObject->Release();
            pObject = p;
        }
        return *this;
    }
};

// Weak-pointer support (same as the kernel unit's sf_refcount.h). The out-of-line members bind to the exe:
//   RefCountWeakSupportImpl::~RefCountWeakSupportImpl 0x14257db60, RefCountWeakSupportImpl::CreateWeakProxy 0x14257dc50.
class WeakPtrProxy;

class RefCountWeakSupportImpl : public RefCountNTSImpl
{
protected:
    mutable WeakPtrProxy* pWeakProxy;
public:
    RefCountWeakSupportImpl() { pWeakProxy = 0; }
    virtual ~RefCountWeakSupportImpl();
    WeakPtrProxy* CreateWeakProxy() const;
};

template<class C, int Stat>
class RefCountBaseWeakSupport : public RefCountBaseStatImpl<RefCountWeakSupportImpl, Stat>
{
public:
    enum { StatType = Stat };
    RefCountBaseWeakSupport() : RefCountBaseStatImpl<RefCountWeakSupportImpl, Stat>() {}
};

// Shared liveness record between an object with weak support and its WeakPtrs.
class WeakPtrProxy : public NewOverrideBase<Stat_Default_Mem>
{
public:
    WeakPtrProxy(RefCountWeakSupportImpl* obj) : RefCount(1), pObject(obj) {}
    bool IsAlive() const          { return pObject != 0; }
    void NotifyObjectDied()       { pObject = 0; }
    RefCountWeakSupportImpl* GetObject() const { return pObject; }
    void AddRef()                 { RefCount++; }
    void Release()
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
    WeakPtr() {}
    WeakPtr(C* p) : pProxy(*(p ? p->CreateWeakProxy() : (WeakPtrProxy*)0)) {}
    WeakPtr(const Ptr<C>& p) : pProxy(*(p.GetPtr() ? p->CreateWeakProxy() : (WeakPtrProxy*)0)) {}
    void operator=(C* p)
    {
        if (p)
            pProxy = *p->CreateWeakProxy();
        else
            pProxy.Clear();
    }
    void operator=(const Ptr<C>& p) { operator=(p.GetPtr()); }
    operator Ptr<C>() const { return Ptr<C>(GetObjectThroughProxy()); }
    bool operator==(C* p)            { return GetObjectThroughProxy() == p; }
    bool operator==(const Ptr<C>& p) { return GetObjectThroughProxy() == p.GetPtr(); }
private:
    C* GetObjectThroughProxy() const
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

} // namespace Scaleform

#endif
