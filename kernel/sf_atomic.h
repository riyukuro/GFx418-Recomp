// Recovered Scaleform GFx 4.1.18: atomic operations and the critical-section Lock (Win64, Interlocked* based; x86/x64
// needs no extra fences, so every _Sync/_Acquire/_Release variant is the plain interlocked call).
#ifndef MS2_SF_KERNEL_ATOMIC_H
#define MS2_SF_KERNEL_ATOMIC_H

#include "ms2/scaleform/kernel/sf_types.h"
#include <windows.h>

namespace Scaleform {

// Interlocked primitives by operand size.
template<int Size> struct AtomicOpsRaw;
template<> struct AtomicOpsRaw<4>
{
    typedef LONG T;
    static T    Exchange_NoSync(volatile T* p, T v)              { return InterlockedExchange(p, v); }
    static T    ExchangeAdd_NoSync(volatile T* p, T v)           { return InterlockedExchangeAdd(p, v); }
    static bool CompareAndSet_NoSync(volatile T* p, T c, T v)    { return InterlockedCompareExchange(p, v, c) == c; }
};
template<> struct AtomicOpsRaw<8>
{
    typedef LONG64 T;
    static T    Exchange_NoSync(volatile T* p, T v)              { return InterlockedExchange64(p, v); }
    static T    ExchangeAdd_NoSync(volatile T* p, T v)           { return InterlockedExchangeAdd64(p, v); }
    static bool CompareAndSet_NoSync(volatile T* p, T c, T v)    { return InterlockedCompareExchange64(p, v, c) == c; }
};

// Typed front end: C is reinterpreted as the same-size interlocked integer.
template<class C>
class AtomicOps
{
    typedef AtomicOpsRaw<sizeof(C)> Ops;
    typedef typename Ops::T         T;
    typedef volatile T*             PT;
    union Cast { C c; T t; };
public:
    static C Exchange_NoSync(volatile C* p, C v)     { Cast u; u.c = v; u.t = Ops::Exchange_NoSync((PT)p, u.t); return u.c; }
    static C Exchange_Sync(volatile C* p, C v)       { return Exchange_NoSync(p, v); }
    static C Exchange_Acquire(volatile C* p, C v)    { return Exchange_NoSync(p, v); }
    static C Exchange_Release(volatile C* p, C v)    { return Exchange_NoSync(p, v); }
    static C ExchangeAdd_NoSync(volatile C* p, C v)  { Cast u; u.c = v; u.t = Ops::ExchangeAdd_NoSync((PT)p, u.t); return u.c; }
    static C ExchangeAdd_Sync(volatile C* p, C v)    { return ExchangeAdd_NoSync(p, v); }
    static C ExchangeAdd_Acquire(volatile C* p, C v) { return ExchangeAdd_NoSync(p, v); }
    static C ExchangeAdd_Release(volatile C* p, C v) { return ExchangeAdd_NoSync(p, v); }
    static bool CompareAndSet_NoSync(volatile C* p, C c, C v)
    { Cast nv, cv; nv.c = v; cv.c = c; return Ops::CompareAndSet_NoSync((PT)p, cv.t, nv.t); }
    static bool CompareAndSet_Sync(volatile C* p, C c, C v)    { return CompareAndSet_NoSync(p, c, v); }
    static bool CompareAndSet_Acquire(volatile C* p, C c, C v) { return CompareAndSet_NoSync(p, c, v); }
    static bool CompareAndSet_Release(volatile C* p, C c, C v) { return CompareAndSet_NoSync(p, c, v); }
    static void Store_Release(volatile C* p, C v)    { *p = v; }        // x64: a plain store (xchg only on 32-bit x86)
    static C    Load_Acquire(const volatile C* p)    { return *p; }
};

template<class T>
class AtomicValueBase
{
protected:
    typedef AtomicOps<T> Ops;
public:
    volatile T Value;

    AtomicValueBase() { }
    explicit AtomicValueBase(T v) { Ops::Store_Release(&Value, v); }
    operator T() const { return Value; }

    T    Exchange_Sync(T v)                { return Ops::Exchange_Sync(&Value, v); }
    T    Exchange_Release(T v)             { return Ops::Exchange_Release(&Value, v); }
    T    Exchange_Acquire(T v)             { return Ops::Exchange_Acquire(&Value, v); }
    T    Exchange_NoSync(T v)              { return Ops::Exchange_NoSync(&Value, v); }
    bool CompareAndSet_Sync(T c, T v)      { return Ops::CompareAndSet_Sync(&Value, c, v); }
    bool CompareAndSet_Release(T c, T v)   { return Ops::CompareAndSet_Release(&Value, c, v); }
    bool CompareAndSet_Acquire(T c, T v)   { return Ops::CompareAndSet_Acquire(&Value, c, v); }
    bool CompareAndSet_NoSync(T c, T v)    { return Ops::CompareAndSet_NoSync(&Value, c, v); }
    void Store_Release(T v)                { Ops::Store_Release(&Value, v); }
    T    Load_Acquire() const              { return Ops::Load_Acquire(&Value); }
};

template<class T>
class AtomicPtr : public AtomicValueBase<T*>
{
    typedef typename AtomicValueBase<T*>::Ops Ops;
public:
    AtomicPtr() { this->Value = 0; }
    explicit AtomicPtr(T* v) : AtomicValueBase<T*>(v) { }
    T* operator->() const { return this->Load_Acquire(); }
    operator T*() const   { return this->Load_Acquire(); }
    T* operator=(T* v)    { this->Store_Release(v); return v; }
};

template<class T>
class AtomicInt : public AtomicValueBase<T>
{
    typedef typename AtomicValueBase<T>::Ops Ops;
public:
    AtomicInt() { }
    explicit AtomicInt(T v) : AtomicValueBase<T>(v) { }

    T    ExchangeAdd_Sync(T v)     { return Ops::ExchangeAdd_Sync(&this->Value, v); }
    T    ExchangeAdd_Release(T v)  { return Ops::ExchangeAdd_Release(&this->Value, v); }
    T    ExchangeAdd_Acquire(T v)  { return Ops::ExchangeAdd_Acquire(&this->Value, v); }
    T    ExchangeAdd_NoSync(T v)   { return Ops::ExchangeAdd_NoSync(&this->Value, v); }
    void Increment_Sync()          { ExchangeAdd_Sync((T)1); }
    void Increment_NoSync()        { ExchangeAdd_NoSync((T)1); }

    T operator=(T v)   { this->Store_Release(v); return v; }
    T operator+=(T v)  { return ExchangeAdd_Sync(v) + v; }
    T operator-=(T v)  { return ExchangeAdd_Sync(0 - v) - v; }
    T operator++()     { return ExchangeAdd_Sync((T)1) + 1; }
    T operator--()     { return ExchangeAdd_Sync(((T)0) - 1) - 1; }
    T operator++(int)  { return ExchangeAdd_Sync((T)1); }
    T operator--(int)  { return ExchangeAdd_Sync(((T)0) - 1); }
    T operator|=(T a)
    {
        T c, n;
        do { c = this->Value; n = c | a; } while (!this->CompareAndSet_Sync(c, n));
        return n;
    }
    T operator&=(T a)
    {
        T c, n;
        do { c = this->Value; n = c & a; } while (!this->CompareAndSet_Sync(c, n));
        return n;
    }
};

// Recursive lock over a CRITICAL_SECTION (0x28 bytes).
class Lock
{
    void operator delete(void*) { }
    CRITICAL_SECTION cs;
public:
    Lock(unsigned spinCount = 0);
    SF_NOINLINE ~Lock();   // out of line in the exe (SF_Atomic.cpp), called from every user
    void DoLock() { ::EnterCriticalSection(&cs); }
    void Unlock() { ::LeaveCriticalSection(&cs); }

    class Locker
    {
    public:
        Lock* pLock;
        Locker(Lock* lock) { pLock = lock; pLock->DoLock(); }
        ~Locker() { pLock->Unlock(); }
    };
};

class LockSafe
{
public:
    LockSafe(unsigned spinCount = 0) : mLock(spinCount) { }
    void DoLock() { mLock.DoLock(); }
    void Unlock() { mLock.Unlock(); }

    class Locker
    {
    public:
        LockSafe* pLock;
        Locker(LockSafe* lock) { pLock = lock; pLock->DoLock(); }
        ~Locker() { pLock->Unlock(); }
    };
    class TmpUnlocker
    {
    public:
        LockSafe* pLock;
        TmpUnlocker(LockSafe* lock) { pLock = lock; pLock->Unlock(); }
        ~TmpUnlocker() { pLock->DoLock(); }
    };
private:
    Lock mLock;
};

}  // namespace Scaleform

#endif
