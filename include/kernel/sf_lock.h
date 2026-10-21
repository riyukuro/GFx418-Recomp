// Recovered Scaleform 4.1.18 kernel: the atomic counter, the critical-section Lock and the Event (Win32 build).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The out-of-line members live in the kernel thread units; until those are recovered they bind to the exe:
//   Lock::Lock(unsigned) 0x14258d030, Lock::~Lock 0x14258d0b0,
//   Event::Event(bool, bool) 0x142582300, Event::~Event 0x142582530, Event::Wait 0x142584540, Event::SetEvent 0x1425842b0.
#ifndef MS2_SF_INC_KERNEL_LOCK_H
#define MS2_SF_INC_KERNEL_LOCK_H

#include "sf_types.h"
#include <intrin.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

namespace Scaleform {

// 32-bit counter updated with interlocked instructions. The _NoSync/_Acquire variants are the same instruction on x64.
template<class T>
class AtomicInt
{
public:
    volatile T Value;

    AtomicInt() {}
    AtomicInt(T v) : Value(v) {}

    operator T() const { return Value; }

    T ExchangeAdd_NoSync(T v)   { return (T)_InterlockedExchangeAdd((volatile long*)&Value, (long)v); }
    T ExchangeAdd_Acquire(T v)  { return (T)_InterlockedExchangeAdd((volatile long*)&Value, (long)v); }
    T ExchangeAdd_Sync(T v)     { return (T)_InterlockedExchangeAdd((volatile long*)&Value, (long)v); }
    void Increment_NoSync()     { ExchangeAdd_NoSync(1); }

    bool CompareAndSet_NoSync(T c, T v)
    {
        return (T)_InterlockedCompareExchange((volatile long*)&Value, (long)v, (long)c) == c;
    }
};

// Recursive mutex over a CRITICAL_SECTION (0x28 bytes).
class Lock
{
    CRITICAL_SECTION cs;

public:
    Lock(unsigned spinCount = 0);
    ~Lock();

    void DoLock() { ::EnterCriticalSection(&cs); }
    void Unlock() { ::LeaveCriticalSection(&cs); }

    // Scope guard.
    class Locker
    {
    public:
        Lock* pLock;
        Locker(Lock* plock) : pLock(plock) { pLock->DoLock(); }
        ~Locker() { pLock->Unlock(); }
    };
};

// Waitable event (0x58 bytes). Its state is not touched inline by any recovered unit, so it stays opaque here.
class Event
{
public:
    Event(bool setInitially = false, bool multiWait = false);
    virtual ~Event();

    bool Wait(unsigned delay = 0xFFFFFFFF);
    void SetEvent();

private:
    void* Opaque[10];
};

} // namespace Scaleform

#endif
