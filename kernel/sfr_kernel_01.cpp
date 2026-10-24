// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, first block. Our own source,
// written from the exe (the leaked SDK copies were only used to name things and to compare layouts). Original files of
// this range, in exe order: SF_RefCount, SF_Log, SF_MemoryHeap (0x14257dc30), SF_Threads, SF_String, HeapMH_MemoryHeap,
// HeapPT_SysAllocStatic, SF_ThreadsWinAPI, SF_System, GFx_Loader, HeapPT_SysAllocMalloc,
// HeapPT_SysAllocWinAPI, SF_Atomic (0x14258cb30). SF_ThreadsWinAPI is in sfr_kernel_01b.cpp (split so that inlining
// across the original sources matches); the GFx_Loader functions inside the range belong to sfr_gfx_01.
// MS2-UNIT: sfr_kernel_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14257dc30-0x14257e560 .text$mn
// MS2-RANGE: 0x142582300-0x14258a0c0 .text$mn
// MS2-RANGE: 0x14258c0a0-0x14258c130 .text$mn   (0x14258a0c0-0x14258c0a0: SF_ThreadsWinAPI, sfr_kernel_01b.cpp)
// MS2-RANGE: 0x14258c270-0x14258c2f0 .text$mn   (0x14258c130-0x14258c270: GFx::Loader ctors, sfr_gfx_01)
// MS2-RANGE: 0x14258cb30-0x14258d0c0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_timer.h"
#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_system.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocmalloc.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocwinapi.h"
#include "ms2/scaleform/kernel/heappt/sf_sysallocmapper.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_root.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_allocengine.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_alloclite.h"
#include <stdlib.h>
#include <new>
#include <process.h>

// This file holds several original translation units, and cl inlines across them where the exe could not: a function
// the exe never inlines into its callers here is kept out of line (MemoryHeap ctor for HeapMH_MemoryHeap, System::Init).
#define MS2_SF_XTU __declspec(noinline)

namespace Scaleform {

// ==== SF_RefCount ====================================================================================================

void RefCountImpl::AddRef()
{
    AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, 1);
}

void RefCountVImpl::AddRef()
{
    AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, 1);
}

WeakPtrProxy* RefCountWeakSupportImpl::CreateWeakProxy() const
{
    if (!pWeakProxy)
        if ((pWeakProxy = SF_HEAP_AUTO_NEW(this) WeakPtrProxy(const_cast<RefCountWeakSupportImpl*>(this))) == 0)
            return 0;
    pWeakProxy->AddRef();
    return pWeakProxy;
}

void RefCountImpl::Release()
{
    if ((AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, -1) - 1) == 0)
        delete this;
}

void RefCountNTSImpl::Release() const
{
    RefCount--;
    if (RefCount == 0)
        delete this;
}

void RefCountVImpl::Release()
{
    if ((AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, -1) - 1) == 0)
        delete this;
}

// ==== SF_Log =========================================================================================================

#ifndef MS2_HOOK_DLL
Log* volatile SF_GlobalLog = 0;       // exe 0x143b15f50
#else
extern Log* volatile SF_GlobalLog;
#endif

Log::~Log()
{
    if (this == SF_GlobalLog)
        SF_GlobalLog = 0;
}

// The exe keeps the debugger output of the default log in its release build.
void Log::DefaultLogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList)
{
    char buffer[MaxLogBufferMessageSize];
    FormatLog(buffer, MaxLogBufferMessageSize, messageId, fmt, argList);
    ::OutputDebugStringA(buffer);
}

void Log::FormatLog(char* buffer, unsigned bufferSize, LogMessageId messageId, const char* fmt, va_list argList)
{
    switch (messageId.GetMessageType())
    {
    case LogMessage_Error:   SFstrcpy(buffer, bufferSize, "Error: "); break;
    case LogMessage_Warning: SFstrcpy(buffer, bufferSize, "Warning: "); break;
    case LogMessage_Assert:  SFstrcpy(buffer, bufferSize, "Assert: "); break;
    case LogMessage_Text:    buffer[0] = 0; break;
    case LogMessage_Report:  buffer[0] = 0; break;
    case LogMessage_Mask:    break;
    }
    UPInt prefixLength = SFstrlen(buffer);
    char* text = buffer + prefixLength;
    SFvsprintf(text, bufferSize - prefixLength, fmt, argList);
    if (messageId.GetMessageType() != LogMessage_Text)
        SFstrcat(buffer, bufferSize, "\n");
}

Log* Log::GetDefaultLog()
{
    static Log defaultLog;
    return &defaultLog;
}

Log* Log::GetGlobalLog()
{
    return SF_GlobalLog;
}

void Log::LogMessageById(LogMessageId messageId, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    LogMessageVarg(messageId, fmt, args);
    va_end(args);
}

void Log::LogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList)
{
    DefaultLogMessageVarg(messageId, fmt, argList);
}

void Log::SetGlobalLog(Log* log)
{
    SF_GlobalLog = log;
}

// ==== SF_MemoryHeap ==================================================================================================

#ifndef MS2_HOOK_DLL
MemoryHeap* Memory::pGlobalHeap = 0;  // exe 0x143b15f60
#endif

MS2_SF_XTU MemoryHeap::MemoryHeap()
    : SelfSize(0), RefCount(1), OwnerThreadId(0), pAutoRelease(0), ChildHeaps(), HeapLock(), UseLocks(true),
      TrackDebugInfo(true)
{
    memset(&Info, 0, sizeof(Info));
}

void MemoryHeap::AssignToCurrentThread()
{
    OwnerThreadId = (UPInt)::GetCurrentThreadId();
}

bool MemoryHeap::DumpMemoryLeaks()
{
    Lock::Locker locker(&HeapLock);
    return dumpMemoryLeaks();
}

void MemoryHeap::LockAndVisit(HeapVisitor* visitor)
{
    Lock::Locker locker(&HeapLock);
    visitor->Visit(NULL, this);
}

void MemoryHeap::ReleaseOnFree(void* ptr)
{
    pAutoRelease = ptr;
}

void MemoryHeap::VisitChildHeaps(HeapVisitor* visitor)
{
    Lock::Locker locker(&HeapLock);
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        visitor->Visit(this, heap);
        heap = heap->pNext;
    }
}

void MemoryHeap::GetHeapInfo(HeapInfo* infoPtr) const
{
    memcpy(infoPtr, &Info, sizeof(HeapInfo));
}

void MemoryHeap::UltimateCheck()     { Memory::pGlobalHeap->ultimateCheck(); }
void MemoryHeap::CheckIntegrity()    { Memory::pGlobalHeap->checkIntegrity(); }
void MemoryHeap::ReleaseCachedMem()  { Memory::pGlobalHeap->releaseCachedMem(); }
int MemoryHeap::CheckRead(int v) const { return v + 1; }


// ==== SF_Threads =====================================================================================================

Waitable::Waitable(bool enable)
    : RefCountBase<Waitable, Stat_Default_Mem>()
{
    pHandlers = enable ? new HandlerArray : 0;
}

Waitable::~Waitable()
{
    if (pHandlers)
        pHandlers->Release();
}

bool Waitable::AddWaitHandler(WaitHandler handler, void* data)
{
    if (!pHandlers)
        return 0;
    HandlerStruct hs(handler, data);
    Lock::Locker lock(&pHandlers->HandlersLock);
    pHandlers->Handlers.PushBack(hs);
    return 1;
}

bool Waitable::RemoveWaitHandler(WaitHandler handler, void* data)
{
    if (!pHandlers)
        return 0;
    HandlerStruct hs(handler, data);
    bool result = 0;
    Lock::Locker lock(&pHandlers->HandlersLock);
    for (unsigned i = 0; i < pHandlers->Handlers.GetSize(); i++)
        if (pHandlers->Handlers[i] == hs)
        {
            pHandlers->Handlers.RemoveAt(i);
            result = 1;
            break;
        }
    return result;
}

void Waitable::HandlerArray::Release()
{
    if ((RefCount.ExchangeAdd_NoSync(-1) - 1) == 0)
        delete this;
}

void Waitable::HandlerArray::CallWaitHandlers()
{
    Lock::Locker lock(&HandlersLock);
    UPInt size = Handlers.GetSize();
    if (size == 0)
        return;
    if (size == 1)
    {
        HandlerStruct hs(Handlers[0]);
        Handlers[0].Handler(Handlers[0].pUserData);
    }
    else
    {
        // handlers may remove themselves while called: walk a copy
        HandlerArrayType handlersCopy(Handlers);
        for (UPInt i = 0; i < handlersCopy.GetSize(); i++)
            handlersCopy[i].Handler(handlersCopy[i].pUserData);
    }
}

void Waitable::CallWaitHandlers()
{
    if (pHandlers)
        pHandlers->CallWaitHandlers();
}

bool Waitable::Acquire(unsigned delay)
{
    Waitable* w = this;
    return AcquireInterface::AcquireOneOfMultipleObjects(&w, 1, delay) == 0;
}

struct Waitable_SingleWaitData
{
    Waitable* pWaitable;
    Event*    pEvent;
    Waitable_SingleWaitData(Waitable* w, Event* e) : pWaitable(w), pEvent(e) { }
};

void Waitable_SingleWaitHandler(void* data)
{
    Waitable_SingleWaitData* d = (Waitable_SingleWaitData*)data;
    if (d->pWaitable->IsSignaled())
        d->pEvent->PulseEvent();
}

bool Waitable::Wait(unsigned delay)
{
    if (IsSignaled())
        return 1;
    if (delay == 0)
        return 0;

    Event                   event;
    Waitable_SingleWaitData waitData(this, &event);
    if (!AddWaitHandler(Waitable_SingleWaitHandler, &waitData))
        return 0;
    if (IsSignaled())
    {
        RemoveWaitHandler(Waitable_SingleWaitHandler, &waitData);
        return 1;
    }

    bool     result = 0;
    UInt32   start = 0;
    unsigned adjustedDelay = delay;
    if (delay != SF_WAIT_INFINITE)
        start = Timer::GetTicksMs();
    while (event.Wait(adjustedDelay))
    {
        if (IsSignaled())
        {
            result = 1;
            break;
        }
        if (delay != SF_WAIT_INFINITE)
        {
            unsigned elapsed = (unsigned)(Timer::GetTicksMs() - start);
            if (elapsed >= delay)
                break;
            adjustedDelay = delay - elapsed;
        }
    }
    RemoveWaitHandler(Waitable_SingleWaitHandler, &waitData);
    return result;
}

bool Waitable::IsSignaled() const
{
    return 1;
}

AcquireInterface* Waitable::GetAcquireInterface()
{
    return DefaultAcquireInterface::GetDefaultAcquireInterface();
}

DefaultAcquireInterface* DefaultAcquireInterface::GetDefaultAcquireInterface()
{
    static DefaultAcquireInterface defaultInterface;
    return &defaultInterface;
}

bool AcquireInterface::CanAcquire()       { return 1; }
bool AcquireInterface::TryAcquire()       { return 1; }
bool AcquireInterface::TryAcquireCommit() { return 1; }
bool AcquireInterface::TryAcquireCancel() { return 1; }

// A multi-object wait: the handler installed on every object pulses the event when the wait may be satisfied.
struct AcquireInterface_AcquireDesc
{
    Waitable**         pWaitList;
    unsigned           WaitCount;
    Event*             pEvent;
    AcquireInterface** pAcquireList;

    AcquireInterface_AcquireDesc(Waitable** waitList, unsigned waitCount, Event* e, AcquireInterface** acquireList = 0)
    {
        pWaitList = waitList;
        WaitCount = waitCount;
        pEvent = e;
        pAcquireList = acquireList;
    }
    bool AddHandlers(Waitable::WaitHandler handler);
    void RemoveHandlers(Waitable::WaitHandler handler);
};

// acquire interfaces of a wait list; up to 32 live on the stack
struct AcquireInterface_AcquireList
{
    AcquireInterface** pList;
    AcquireInterface*  StaticList[32];

    AcquireInterface_AcquireList(Waitable** waitList, unsigned waitCount)
    {
        pList = (waitCount > 32) ? (AcquireInterface**)SF_ALLOC(sizeof(AcquireInterface*) * waitCount, Stat_Default_Mem)
                                 : StaticList;
        for (unsigned i = 0; i < waitCount; i++)
            pList[i] = waitList[i]->GetAcquireInterface();
    }
    ~AcquireInterface_AcquireList()
    {
        if (pList != StaticList)
            SF_FREE(pList);
    }
};

bool AcquireInterface_AcquireDesc::AddHandlers(Waitable::WaitHandler handler)
{
    for (unsigned i = 0; i < WaitCount; i++)
    {
        if (!pWaitList[i]->AddWaitHandler(handler, this))
        {
            while (i > 0)
                pWaitList[--i]->RemoveWaitHandler(handler, this);
            return 0;
        }
    }
    return 1;
}

void AcquireInterface_AcquireDesc::RemoveHandlers(Waitable::WaitHandler handler)
{
    for (unsigned i = 0; i < WaitCount; i++)
        pWaitList[i]->RemoveWaitHandler(handler, this);
}

void AcquireInterface_MultipleWaitHandler(void* data)
{
    AcquireInterface_AcquireDesc* desc = (AcquireInterface_AcquireDesc*)data;
    for (unsigned i = 0; i < desc->WaitCount; i++)
        if (!desc->pAcquireList[i]->CanAcquire())
            return;
    desc->pEvent->PulseEvent();
}

bool AcquireInterface_TryAcquireAll(AcquireInterface** acquireList, unsigned waitCount)
{
    unsigned i;
    for (i = 0; i < waitCount; i++)
        if (!acquireList[i]->TryAcquire())
            break;
    if (i == waitCount)
    {
        for (i = 0; i < waitCount; i++)
            acquireList[i]->TryAcquireCommit();
        return 1;
    }
    else
    {
        while (i > 0)
            acquireList[--i]->TryAcquireCancel();
    }
    return 0;
}

bool AcquireInterface::AcquireMultipleObjects(Waitable** waitList, unsigned waitCount, unsigned delay)
{
    AcquireInterface_AcquireList acquireList(waitList, waitCount);
    if (AcquireInterface_TryAcquireAll(acquireList.pList, waitCount))
        return 1;
    if (delay == 0)
        return 0;

    Event                        event;
    AcquireInterface_AcquireDesc acquireDesc(waitList, waitCount, &event, acquireList.pList);
    if (!acquireDesc.AddHandlers(AcquireInterface_MultipleWaitHandler))
        return 0;
    if (AcquireInterface_TryAcquireAll(acquireList.pList, waitCount))
    {
        acquireDesc.RemoveHandlers(AcquireInterface_MultipleWaitHandler);
        return 1;
    }

    bool     result = 0;
    UInt32   start = 0;
    unsigned adjustedDelay = delay;
    if (delay != SF_WAIT_INFINITE)
        start = Timer::GetTicksMs();
    while (event.Wait(adjustedDelay))
    {
        if (AcquireInterface_TryAcquireAll(acquireList.pList, waitCount))
        {
            result = 1;
            break;
        }
        if (delay != SF_WAIT_INFINITE)
        {
            unsigned elapsed = (unsigned)(Timer::GetTicksMs() - start);
            if (elapsed >= delay)
                break;
            adjustedDelay = delay - elapsed;
        }
    }
    acquireDesc.RemoveHandlers(AcquireInterface_MultipleWaitHandler);
    return result;
}

void AcquireInterface_OneOfMultipleWaitHandler(void* data)
{
    AcquireInterface_AcquireDesc* desc = (AcquireInterface_AcquireDesc*)data;
    for (unsigned i = 0; i < desc->WaitCount; i++)
        if (desc->pWaitList[i]->GetAcquireInterface()->CanAcquire())
        {
            desc->pEvent->PulseEvent();
            break;
        }
}

int AcquireInterface_TryAcquireOne(Waitable** waitList, unsigned waitCount)
{
    unsigned i;
    for (i = 0; i < waitCount; i++)
    {
        AcquireInterface* ai = waitList[i]->GetAcquireInterface();
        if (ai->TryAcquire())
        {
            ai->TryAcquireCommit();
            return (int)i;
        }
    }
    return -1;
}

int AcquireInterface::AcquireOneOfMultipleObjects(Waitable** waitList, unsigned waitCount, unsigned delay)
{
    int result = AcquireInterface_TryAcquireOne(waitList, waitCount);
    if (result != -1)
        return result;
    if (delay == 0)
        return -1;

    Event                        event;
    AcquireInterface_AcquireDesc acquireDesc(waitList, waitCount, &event);
    if (!acquireDesc.AddHandlers(AcquireInterface_OneOfMultipleWaitHandler))
        return 0;
    result = AcquireInterface_TryAcquireOne(waitList, waitCount);
    if (result != -1)
    {
        acquireDesc.RemoveHandlers(AcquireInterface_OneOfMultipleWaitHandler);
        return result;
    }

    UInt32   start = 0;
    unsigned adjustedDelay = delay;
    if (delay != SF_WAIT_INFINITE)
        start = Timer::GetTicksMs();
    if ((result = AcquireInterface_TryAcquireOne(waitList, waitCount)) == -1)
        while (event.Wait(adjustedDelay))
        {
            if ((result = AcquireInterface_TryAcquireOne(waitList, waitCount)) != -1)
                break;
            if (delay != SF_WAIT_INFINITE)
            {
                unsigned elapsed = (unsigned)(Timer::GetTicksMs() - start);
                if (elapsed >= delay)
                    break;
                adjustedDelay = delay - elapsed;
            }
        }
    acquireDesc.RemoveHandlers(AcquireInterface_OneOfMultipleWaitHandler);
    return result;
}

Event::Event(bool setInitially, bool multiWait)
    : Waitable(multiWait)
{
    State = setInitially;
    Temporary = 0;
}

Event::~Event()
{
}

bool Event::Wait(unsigned delay)
{
    Mutex::Locker lock(&StateMutex);
    switch (delay)
    {
    case 0:
        break;
    case SF_WAIT_INFINITE:
        while (!State)
            StateWaitCondition.Wait(&StateMutex);
        break;
    default:
        if (!State)
            StateWaitCondition.Wait(&StateMutex, delay);
        break;
    }
    bool state = State;
    if (Temporary)
    {
        Temporary = 0;
        State = 0;
    }
    return state;
}

void Event::SetEvent()
{
    StateMutex.DoLock();
    State = 1;
    Temporary = 0;
    StateWaitCondition.NotifyAll();
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    StateMutex.Unlock();
    handlers.CallWaitHandlers();
}

void Event::ResetEvent()
{
    Mutex::Locker lock(&StateMutex);
    State = 0;
    Temporary = 0;
}

void Event::PulseEvent()
{
    StateMutex.DoLock();
    State = 1;
    Temporary = 1;
    StateWaitCondition.NotifyAll();
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    StateMutex.Unlock();
    handlers.CallWaitHandlers();
}

bool              Event::IsSignaled() const    { return State; }
AcquireInterface* Event::GetAcquireInterface() { return this; }
bool              Event::CanAcquire()          { return IsSignaled(); }
bool              Event::TryAcquire()          { return IsSignaled(); }

bool Event::TryAcquireCommit()
{
    Mutex::Locker lock(&StateMutex);
    if (Temporary)
    {
        Temporary = 0;
        State = 0;
    }
    return 1;
}

bool Event::TryAcquireCancel() { return 1; }

Semaphore::Semaphore(int maxValue, bool multiWait)
    : Waitable(multiWait)
{
    MaxValue = maxValue;
    Value = 0;
}

Semaphore::~Semaphore()
{
}

int Semaphore::GetMaxValue() const  { return MaxValue; }
int Semaphore::GetValue() const     { return Value; }
int Semaphore::GetAvailable() const { return MaxValue - Value; }

bool Semaphore::ObtainSemaphore(int count, unsigned delay)
{
    if (count > MaxValue)
        return 0;
    Mutex::Locker lock(&ValueMutex);
    if ((Value + count) <= MaxValue)
    {
        Value += count;
        return 1;
    }
    if (delay == 0)
        return 0;
    if (delay == SF_WAIT_INFINITE)
    {
        while ((Value + count) > MaxValue)
            ValueWaitCondition.Wait(&ValueMutex);
        Value += count;
        return 1;
    }
    unsigned adjustedDelay = delay;
    UInt32   start = Timer::GetTicksMs();
    while (ValueWaitCondition.Wait(&ValueMutex, adjustedDelay))
    {
        if ((Value + count) <= MaxValue)
        {
            Value += count;
            return 1;
        }
        unsigned elapsed = (unsigned)(Timer::GetTicksMs() - start);
        if (elapsed >= delay)
            break;
        adjustedDelay = delay - elapsed;
    }
    return 0;
}

bool Semaphore::ReleaseSemaphore(int count)
{
    if (count == 0)
        return 1;
    ValueMutex.DoLock();
    if ((Value - count) >= 0)
        Value = Value - count;
    else
        Value = 0;
    if (count == 1)
        ValueWaitCondition.Notify();
    else
        ValueWaitCondition.NotifyAll();
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    ValueMutex.Unlock();
    handlers.CallWaitHandlers();
    return 1;
}

int Semaphore::operator++(int)
{
    Mutex::Locker lock(&ValueMutex);
    while (Value >= MaxValue)
        ValueWaitCondition.Wait(&ValueMutex);
    Value++;
    return Value;
}

int Semaphore::operator--(int)
{
    ValueMutex.DoLock();
    if (Value > 0)
        Value--;
    ValueWaitCondition.Notify();
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    ValueMutex.Unlock();
    handlers.CallWaitHandlers();
    return Value;
}

int Semaphore::operator+=(int count)
{
    Mutex::Locker lock(&ValueMutex);
    while ((Value + count) > MaxValue)
        ValueWaitCondition.Wait(&ValueMutex);
    Value += count;
    return Value;
}

int Semaphore::operator-=(int count)
{
    ValueMutex.DoLock();
    if ((Value - count) >= 0)
        Value = Value - count;
    else
        Value = 0;
    ValueWaitCondition.NotifyAll();
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    ValueMutex.Unlock();
    handlers.CallWaitHandlers();
    return Value;
}

bool              Semaphore::CanAcquire()          { return GetAvailable() > 0; }
bool              Semaphore::TryAcquire()          { return ObtainSemaphore(1, 0); }
bool              Semaphore::TryAcquireCommit()    { return 1; }
bool              Semaphore::TryAcquireCancel()    { return ReleaseSemaphore(1); }
bool              Semaphore::IsSignaled() const    { return GetAvailable() > 0; }
AcquireInterface* Semaphore::GetAcquireInterface() { return this; }

// Waitable view of "count units of a semaphore are available"; owned by its creator, so not ref counted.
class SemaphoreWaitableIncrement : public Waitable, public AcquireInterface
{
    Semaphore* pSemaphore;
    int        Count;
public:
    SemaphoreWaitableIncrement() : Waitable(1) { pSemaphore = 0; Count = 0; }
    SemaphoreWaitableIncrement(Semaphore* semaphore, int count);
    ~SemaphoreWaitableIncrement();

    virtual bool              CanAcquire();
    virtual bool              TryAcquire();
    virtual bool              TryAcquireCommit();
    virtual bool              TryAcquireCancel();
    virtual bool              IsSignaled() const;
    virtual AcquireInterface* GetAcquireInterface();
    virtual void              AddRef() { }
    virtual void              Release(unsigned flags = 0) { SF_UNUSED(flags); }
};

void SemaphoreWaitableIncrement_SemaphoreWaitHandler(void* data)
{
    Waitable* increment = (Waitable*)data;
    increment->CallWaitHandlers();
}

SemaphoreWaitableIncrement::SemaphoreWaitableIncrement(Semaphore* semaphore, int count)
    : Waitable(1)
{
    pSemaphore = semaphore;
    Count = count;
    pSemaphore->AddWaitHandler(SemaphoreWaitableIncrement_SemaphoreWaitHandler, this);
}

SemaphoreWaitableIncrement::~SemaphoreWaitableIncrement()
{
    pSemaphore->RemoveWaitHandler(SemaphoreWaitableIncrement_SemaphoreWaitHandler, this);
}

bool SemaphoreWaitableIncrement::CanAcquire()
{
    if (!pSemaphore)
        return 0;
    return pSemaphore->GetAvailable() >= Count;
}

bool SemaphoreWaitableIncrement::TryAcquire()
{
    if (!pSemaphore)
        return 0;
    return pSemaphore->ObtainSemaphore(Count, 0);
}

bool SemaphoreWaitableIncrement::TryAcquireCommit()
{
    if (!pSemaphore)
        return 0;
    return 1;
}

bool SemaphoreWaitableIncrement::TryAcquireCancel()
{
    if (!pSemaphore)
        return 0;
    return pSemaphore->ReleaseSemaphore(Count);
}

bool SemaphoreWaitableIncrement::IsSignaled() const
{
    if (!pSemaphore)
        return 0;
    return pSemaphore->GetAvailable() >= Count;
}

AcquireInterface* SemaphoreWaitableIncrement::GetAcquireInterface() { return this; }

Waitable* Semaphore::CreateWaitableIncrement(int count)
{
    return new SemaphoreWaitableIncrement(this, count);
}


// ==== SF_String ======================================================================================================

#define MS2_SF_STRING_LENGTH_IS_SIZE (UPInt(1) << String::Flag_LengthIsSizeShift)

#ifndef MS2_HOOK_DLL
String::DataDesc String::NullData = {MS2_SF_STRING_LENGTH_IS_SIZE, 1, {0}};   // exe 0x143a2ef90
#endif

String::String()
{
    pData = &NullData;
    pData->AddRef();
};

String::String(const char* data)
{
    UPInt size = data ? SFstrlen(data) : 0;
    pData = AllocDataCopy1(Memory::GetGlobalHeap(), size, 0, data, size);
};

String::String(const char* data1, const char* data2, const char* data3)
{
    UPInt size1 = data1 ? SFstrlen(data1) : 0;
    UPInt size2 = data2 ? SFstrlen(data2) : 0;
    UPInt size3 = data3 ? SFstrlen(data3) : 0;
    DataDesc* desc = AllocDataCopy2(Memory::GetGlobalHeap(), size1 + size2 + size3, 0, data1, size1, data2, size2);
    memcpy(desc->Data + size1 + size2, data3, size3);
    pData = desc;
}

String::String(const char* data, UPInt size)
{
    pData = AllocDataCopy1(Memory::GetGlobalHeap(), size, 0, data, size);
};

String::String(const InitStruct& src, UPInt size)
{
    pData = AllocData(Memory::GetGlobalHeap(), size, 0);
    src.InitString(GetData()->Data, size);
}

String::String(const String& src)
{
    DataDesc* data = src.GetData();
    // share the text when it already lives in the global heap
    if (src.GetHeap() == Memory::GetGlobalHeap())
    {
        pData = data;
        pData->AddRef();
    }
    else
    {
        UPInt size = data->GetSize();
        pData = AllocDataCopy1(Memory::GetGlobalHeap(), size, data->GetLengthFlag(), data->Data, size);
    }
}

String::String(const StringBuffer& src)
{
    pData = AllocDataCopy1(Memory::GetGlobalHeap(), src.GetSize(), 0, src.ToCStr(), src.GetSize());
}

String::String(const wchar_t* data)
{
    pData = &NullData;
    pData->AddRef();
    if (data)
        *this = data;
}

String::DataDesc* String::AllocData(MemoryHeap* heap, UPInt size, UPInt lengthIsSize)
{
    String::DataDesc* desc;
    if (size == 0)
    {
        desc = &NullData;
        desc->AddRef();
        return desc;
    }
    desc = (DataDesc*)SF_HEAP_ALLOC(heap, sizeof(DataDesc) + size, Stat_String_Mem);
    desc->Data[size] = 0;
    desc->RefCount = 1;
    desc->Size = size | lengthIsSize;
    return desc;
}

String::DataDesc* String::AllocDataCopy1(MemoryHeap* heap, UPInt size, UPInt lengthIsSize, const char* data,
                                         UPInt copySize)
{
    String::DataDesc* desc = AllocData(heap, size, lengthIsSize);
    memcpy(desc->Data, data, copySize);
    return desc;
}

String::DataDesc* String::AllocDataCopy2(MemoryHeap* heap, UPInt size, UPInt lengthIsSize, const char* data1,
                                         UPInt copySize1, const char* data2, UPInt copySize2)
{
    String::DataDesc* desc = AllocData(heap, size, lengthIsSize);
    memcpy(desc->Data, data1, copySize1);
    memcpy(desc->Data + copySize1, data2, copySize2);
    return desc;
}

MemoryHeap* String::GetHeap() const
{
    MemoryHeap* heap = 0;
    switch (GetHeapType())
    {
    case HT_Global:  heap = Memory::GetGlobalHeap(); break;
    case HT_Local:   heap = Memory::GetHeapByAddress(this); break;
    case HT_Dynamic: heap = ((const StringDH*)this)->GetHeap(); break;
    default:;
    }
    return heap;
}

UPInt String::GetLength() const
{
    DataDesc* data = GetData();
    UPInt     length, size = data->GetSize();
    if (data->LengthIsSize())
        return size;
    length = (UPInt)UTF8Util::GetLength(data->Data, (UPInt)size);
    if (length == size)
        data->Size |= MS2_SF_STRING_LENGTH_IS_SIZE;
    return length;
}

UInt32 String::GetCharAt(UPInt index) const
{
    SPInt       i = (SPInt)index;
    DataDesc*   data = GetData();
    const char* buf = data->Data;
    UInt32      c;
    if (data->LengthIsSize())
    {
        buf += i;
        return UTF8Util::DecodeNextChar_Advance0(&buf);
    }
    c = UTF8Util::GetCharAt(index, buf, data->GetSize());
    return c;
}

UInt32 String::GetFirstCharAt(UPInt index, const char** offset) const
{
    DataDesc*   data = GetData();
    SPInt       i = (SPInt)index;
    const char* buf = data->Data;
    const char* end = buf + data->GetSize();
    UInt32      c;
    do
    {
        c = UTF8Util::DecodeNextChar_Advance0(&buf);
        i--;
        if (buf >= end)
            return c;
    } while (i >= 0);
    *offset = buf;
    return c;
}

UInt32 String::GetNextChar(const char** offset) const
{
    return UTF8Util::DecodeNextChar(offset);
}

void String::AppendChar(UInt32 ch)
{
    DataDesc* data = GetData();
    UPInt     size = data->GetSize();
    char      buff[8];
    SPInt     encodeSize = 0;
    UTF8Util::EncodeCharSafe(buff, sizeof(buff), &encodeSize, ch);
    SetData(AllocDataCopy2(GetHeap(), size + (UPInt)encodeSize, 0, data->Data, size, buff, (UPInt)encodeSize));
    data->Release();
}

// MS2-FUNCTIONAL: register choice differs (the exe keeps the string in rsi/r12, cl picks rdi/r15)
void String::AppendString(const wchar_t* str, SPInt len)
{
    if (!str)
        return;
    DataDesc* data = GetData();
    UPInt     oldSize = data->GetSize();
    UPInt     encodeSize = (UPInt)UTF8Util::GetEncodeStringSize(str, len);
    UPInt     newSize = oldSize + encodeSize;
    DataDesc* newData = AllocDataCopy1(GetHeap(), newSize, 0, data->Data, oldSize);
    UTF8Util::EncodeStringSafe(newData->Data + oldSize, newSize + 1, str, len);   // the exe bounds by the whole size
    SetData(newData);
    data->Release();
}

void String::AppendString(const char* utf8, SPInt utf8StrSz)
{
    if (!utf8 || !utf8StrSz)
        return;
    if (utf8StrSz == -1)
        utf8StrSz = (SPInt)SFstrlen(utf8);
    DataDesc* data = GetData();
    UPInt     oldSize = data->GetSize();
    SetData(AllocDataCopy2(GetHeap(), oldSize + (UPInt)utf8StrSz, 0, data->Data, oldSize, utf8, (UPInt)utf8StrSz));
    data->Release();
}

void String::AssignString(const InitStruct& src, UPInt size)
{
    DataDesc* oldData = GetData();
    DataDesc* newData = AllocData(GetHeap(), size, 0);
    src.InitString(newData->Data, size);
    SetData(newData);
    oldData->Release();
}

void String::AssignString(const char* utf8, UPInt size)
{
    DataDesc* oldData = GetData();
    SetData(AllocDataCopy1(GetHeap(), size, 0, utf8, size));
    oldData->Release();
}

void String::operator=(const char* str)
{
    AssignString(str, str ? SFstrlen(str) : 0);
}

void String::operator=(const wchar_t* wstr)
{
    DataDesc* oldData = GetData();
    UPInt     size = wstr ? (UPInt)UTF8Util::GetEncodeStringSize(wstr) : 0;
    DataDesc* newData = AllocData(GetHeap(), size, 0);
    UTF8Util::EncodeStringSafe(newData->Data, size + 1, wstr);
    SetData(newData);
    oldData->Release();
}

void String::operator=(const String& src)
{
    MemoryHeap* heap = GetHeap();
    DataDesc*   srcData = src.GetData();
    DataDesc*   data = GetData();
    if (heap == src.GetHeap())
    {
        SetData(srcData);
        srcData->AddRef();
    }
    else
    {
        SetData(AllocDataCopy1(heap, srcData->GetSize(), srcData->GetLengthFlag(), srcData->Data, srcData->GetSize()));
    }
    data->Release();
}

void String::operator=(const StringBuffer& src)
{
    DataDesc* oldData = GetData();
    SetData(AllocDataCopy1(GetHeap(), src.GetSize(), 0, src.ToCStr(), src.GetSize()));
    oldData->Release();
}

void String::operator+=(const String& src)
{
    DataDesc* ourData = GetData();
    DataDesc* srcData = src.GetData();
    UPInt     ourSize = ourData->GetSize();
    UPInt     srcSize = srcData->GetSize();
    UPInt     lflag = ourData->GetLengthFlag() & srcData->GetLengthFlag();
    SetData(AllocDataCopy2(GetHeap(), ourSize + srcSize, lflag, ourData->Data, ourSize, srcData->Data, srcSize));
    ourData->Release();
}

String String::operator+(const char* str) const
{
    String tmp(*this);
    tmp += (str ? str : "");
    return tmp;
}

String String::operator+(const String& src) const
{
    String tmp(*this);
    tmp += src;
    return tmp;
}

void String::Remove(UPInt posAt, SPInt removeLength)
{
    DataDesc* data = GetData();
    UPInt     oldSize = data->GetSize();
    UPInt     length = GetLength();
    if (posAt >= length)
        return;
    if ((posAt + removeLength) > length)
        removeLength = length - posAt;

    SPInt bytePos = UTF8Util::GetByteIndex(posAt, data->Data, oldSize);
    SPInt removeSize = UTF8Util::GetByteIndex(removeLength, data->Data + bytePos, oldSize - bytePos);
    SetData(AllocDataCopy2(GetHeap(), oldSize - removeSize, data->GetLengthFlag(), data->Data, bytePos,
                           pData->Data + bytePos + removeSize, (oldSize - bytePos - removeSize)));
    data->Release();
}

String String::Substring(UPInt start, UPInt end) const
{
    UPInt length = GetLength();
    if ((start >= length) || (start >= end))
        return String();

    DataDesc* data = GetData();
    if (data->LengthIsSize())
        return String(data->Data + start, end - start);

    SPInt byteStart = UTF8Util::GetByteIndex(start, data->Data, data->GetSize());
    SPInt byteSize = UTF8Util::GetByteIndex(end - start, data->Data + byteStart, data->GetSize() - byteStart);
    return String(data->Data + byteStart, (UPInt)byteSize);
}

void String::Clear()
{
    NullData.AddRef();
    GetData()->Release();
    SetData(&NullData);
}

// case conversion goes through a 512-byte staging buffer
String String::ToUpper() const
{
    UInt32      c;
    const char* source = GetData()->Data;
    const char* end = source + GetData()->GetSize();
    String      str;
    SPInt       bufferOffset = 0;
    char        buffer[512];
    while (source < end)
    {
        do {
            c = UTF8Util::DecodeNextChar_Advance0(&source);
            UTF8Util::EncodeCharSafe(buffer, sizeof(buffer), &bufferOffset, SFtowupper(wchar_t(c)));
        } while ((source < end) && (bufferOffset < SPInt(sizeof(buffer) - 8)));
        str.AppendString(buffer, bufferOffset);
        bufferOffset = 0;
    }
    return str;
}

String String::ToLower() const
{
    UInt32      c;
    const char* source = GetData()->Data;
    const char* end = source + GetData()->GetSize();
    String      str;
    SPInt       bufferOffset = 0;
    char        buffer[512];
    while (source < end)
    {
        do {
            c = UTF8Util::DecodeNextChar_Advance0(&source);
            UTF8Util::EncodeCharSafe(buffer, sizeof(buffer), &bufferOffset, SFtowlower(wchar_t(c)));
        } while ((source < end) && (bufferOffset < SPInt(sizeof(buffer) - 8)));
        str.AppendString(buffer, bufferOffset);
        bufferOffset = 0;
    }
    return str;
}

String& String::Insert(const char* substr, UPInt posAt, SPInt strSize)
{
    DataDesc* oldData = GetData();
    UPInt     oldSize = oldData->GetSize();
    UPInt     insertSize = (strSize < 0) ? SFstrlen(substr) : (UPInt)strSize;
    UPInt     byteIndex = (oldData->LengthIsSize()) ? posAt : (UPInt)UTF8Util::GetByteIndex(posAt, oldData->Data, oldSize);

    DataDesc* newData = AllocDataCopy2(GetHeap(), oldSize + insertSize, 0, oldData->Data, byteIndex, substr, insertSize);
    memcpy(newData->Data + byteIndex + insertSize, oldData->Data + byteIndex, oldSize - byteIndex);
    SetData(newData);
    oldData->Release();
    return *this;
}

UPInt String::InsertCharAt(UInt32 c, UPInt posAt)
{
    char  buf[8];
    SPInt index = 0;
    UTF8Util::EncodeCharSafe(buf, sizeof(buf), &index, c);
    buf[(UPInt)index] = 0;
    Insert(buf, posAt, index);
    return (UPInt)index;
}

int String::CompareNoCase(const char* a, const char* b)
{
    return SFstricmp(a, b);
}

int String::CompareNoCase(const char* a, const char* b, SPInt len)
{
    if (len)
    {
        SPInt f, l;
        SPInt slen = len;
        const char* s = b;
        do {
            f = (SPInt)SFtolower((int)(*(a++)));
            l = (SPInt)SFtolower((int)(*(b++)));
        } while (--len && f && (f == l) && *b != 0);

        // equal prefix: the shorter one sorts first
        if (f == l && (len != 0 || *b != 0))
        {
            f = (SPInt)slen;
            l = (SPInt)SFstrlen(s);
            return int(f - l);
        }
        return int(f - l);
    }
    else
        return (0 - (int)SFstrlen(b));
}

// djb2 variant (xor), over the bytes back to front
UPInt String::BernsteinHashFunction(const void* dataIn, UPInt size, UPInt seed)
{
    const UByte* data = (const UByte*)dataIn;
    UPInt        h = seed;
    while (size > 0)
    {
        size--;
        h = ((h << 5) + h) ^ (unsigned)data[size];
    }
    return h;
}

UPInt String::BernsteinHashFunctionCIS(const void* dataIn, UPInt size, UPInt seed)
{
    const UByte* data = (const UByte*)dataIn;
    UPInt        h = seed;
    while (size > 0)
    {
        size--;
        h = ((h << 5) + h) ^ SFtolower(data[size]);
    }
    return h;
}

void String::EscapeSpecialHTML(const char* src, UPInt length, String* escapedStr)
{
    UInt32       ch;
    StringBuffer buf;
    const char*  end = src + length;
    while (ch = UTF8Util::DecodeNextChar_Advance0(&src), (src < end))
    {
        if (ch == '<')
            buf.AppendString("&lt;", 4);
        else if (ch == '>')
            buf.AppendString("&gt;", 4);
        else if (ch == '\"')
            buf.AppendString("&quot;", 6);
        else if (ch == '\'')
            buf.AppendString("&apos;", 6);
        else if (ch == '&')
            buf.AppendString("&amp;", 5);
        else
            buf.AppendChar(ch);
    }
    *escapedStr = buf;
}

// note: the loop stops after the first entity it decodes (kept as the exe does it)
void String::UnescapeSpecialHTML(const char* src, UPInt length, String* unescapedStr)
{
    UInt32       ch;
    StringBuffer buf;
    const char*  end = src + length;
    while (ch = UTF8Util::DecodeNextChar_Advance0(&src), (src < end))
    {
        if (ch == '&')
        {
            if (strncmp(src, "quot;", 5) == 0)
            {
                buf.AppendChar('\"');
                src += 5;
                break;
            }
            else if (strncmp(src, "apos;", 5) == 0)
            {
                buf.AppendChar('\'');
                src += 5;
                break;
            }
            else if (strncmp(src, "amp;", 4) == 0)
            {
                buf.AppendChar('&');
                src += 4;
                break;
            }
            else if (strncmp(src, "lt;", 3) == 0)
            {
                buf.AppendChar('<');
                src += 3;
                break;
            }
            else if (strncmp(src, "gt;", 3) == 0)
            {
                buf.AppendChar('>');
                src += 3;
                break;
            }
            else
                buf.AppendChar(ch);
        }
        else
            buf.AppendChar(ch);
    }
    *unescapedStr = buf;
}

StringLH::StringLH() : String(String::NoConstructor())
{
    NullData.AddRef();
    SetDataLcl(&NullData);
};

StringLH::StringLH(const char* data) : String(String::NoConstructor())
{
    UPInt size = data ? SFstrlen(data) : 0;
    SetDataLcl(AllocDataCopy1(Memory::GetHeapByAddress(this), size, 0, data, size));
};

StringLH::StringLH(const char* data, UPInt size) : String(String::NoConstructor())
{
    SetDataLcl(AllocDataCopy1(Memory::GetHeapByAddress(this), size, 0, data, size));
};

StringLH::StringLH(const InitStruct& src, UPInt size) : String(String::NoConstructor())
{
    SetDataLcl(AllocData(Memory::GetHeapByAddress(this), size, 0));
    src.InitString(GetData()->Data, size);
}

void StringLH::CopyConstructHelper(const String& src)
{
    DataDesc*   data = src.GetData();
    MemoryHeap* heap = Memory::GetHeapByAddress(this);
    if (src.GetHeap() == heap)
    {
        data->AddRef();
        SetDataLcl(data);
    }
    else
    {
        UPInt size = data->GetSize();
        SetDataLcl(AllocDataCopy1(heap, size, data->GetLengthFlag(), data->Data, size));
    }
}

StringLH::StringLH(const wchar_t* data)
{
    if (data)
        *this = data;
}

StringDH::StringDH(MemoryHeap* heap)
    : String(String::NoConstructor())
{
    pHeap = heap;
    NullData.AddRef();
    SetDataLcl(&NullData);
};

StringDH::StringDH(MemoryHeap* heap, const char* data)
    : String(String::NoConstructor())
{
    UPInt size = data ? SFstrlen(data) : 0;
    pHeap = heap;
    SetDataLcl(AllocDataCopy1(heap, size, 0, data, size));
};

StringDH::StringDH(MemoryHeap* heap, const char* data1, const char* data2, const char* data3)
{
    UPInt size1 = data1 ? SFstrlen(data1) : 0;
    UPInt size2 = data2 ? SFstrlen(data2) : 0;
    UPInt size3 = data3 ? SFstrlen(data3) : 0;
    DataDesc* desc = AllocDataCopy2(heap, size1 + size2 + size3, 0, data1, size1, data2, size2);
    memcpy(desc->Data + size1 + size2, data3, size3);
    pHeap = heap;
    SetDataLcl(desc);
}

StringDH::StringDH(MemoryHeap* heap, const char* data, UPInt size)
    : String(String::NoConstructor())
{
    pHeap = heap;
    SetDataLcl(AllocDataCopy1(heap, size, 0, data, size));
};

StringDH::StringDH(MemoryHeap* heap, const InitStruct& src, UPInt size)
    : String(String::NoConstructor())
{
    pHeap = heap;
    SetDataLcl(AllocData(heap, size, 0));
    src.InitString(GetData()->Data, size);
}

void StringDH::CopyConstructHelper(const String& src, MemoryHeap* heap)
{
    DataDesc*   data = src.GetData();
    MemoryHeap* srcHeap = src.GetHeap();
    if (!heap)
        heap = srcHeap;
    pHeap = heap;
    if (srcHeap == heap)
    {
        data->AddRef();
        SetDataLcl(data);
    }
    else
    {
        UPInt size = data->GetSize();
        SetDataLcl(AllocDataCopy1(heap, size, data->GetLengthFlag(), data->Data, size));
    }
}

StringDH::StringDH(MemoryHeap* heap, const wchar_t* data)
{
    pHeap = heap;
    if (data)
        *this = data;
}

enum { MS2_SF_STRINGBUFFER_GROW_SIZE = 512 };

StringBuffer::StringBuffer(MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
}

StringBuffer::StringBuffer(UPInt growSize, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    SetGrowSize(growSize);
}

StringBuffer::StringBuffer(const char* data, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    *this = data;
}

StringBuffer::StringBuffer(const char* data, UPInt dataSize, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    AppendString(data, dataSize);
}

StringBuffer::StringBuffer(const String& src, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    AppendString(src.ToCStr(), src.GetSize());
}

StringBuffer::StringBuffer(const StringBuffer& src, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    AppendString(src.ToCStr(), src.GetSize());
    LengthIsSize = src.LengthIsSize;
}

StringBuffer::StringBuffer(const wchar_t* data, MemoryHeap* heap)
    : pData(NULL), Size(0), BufferSize(0), GrowSize(MS2_SF_STRINGBUFFER_GROW_SIZE), LengthIsSize(false), pHeap(heap)
{
    *this = data;
}

StringBuffer::~StringBuffer()
{
    if (pData)
        SF_HEAP_FREE(pHeap, pData);
}

void StringBuffer::SetGrowSize(UPInt growSize)
{
    if (growSize <= 16)
        GrowSize = 16;
    else
    {
        UInt8 bits = Alg::UpperBit(UInt32(growSize - 1));
        UPInt size = (UPInt)(1 << bits);
        GrowSize = size == growSize ? growSize : size;
    }
}

UPInt StringBuffer::GetLength() const
{
    UPInt length, size = GetSize();
    if (LengthIsSize)
        return size;
    length = (UPInt)UTF8Util::GetLength(pData, (UPInt)GetSize());
    if (length == GetSize())
        LengthIsSize = true;
    return length;
}

void StringBuffer::Reserve(UPInt size)
{
    if (size >= BufferSize)
    {
        BufferSize = (size + 1 + GrowSize - 1) & ~(GrowSize - 1);
        if (!pData)
            pData = (char*)SF_HEAP_ALLOC(pHeap, BufferSize, Stat_String_Mem);
        else
            pData = (char*)SF_REALLOC(pData, BufferSize, Stat_String_Mem);
    }
}

void StringBuffer::Resize(UPInt size)
{
    Reserve(size);
    LengthIsSize = false;
    Size = size;
    if (pData)
        pData[Size] = 0;
}

void StringBuffer::Clear()
{
    Resize(0);
}

void StringBuffer::AppendChar(UInt32 ch)
{
    char  buff[8];
    UPInt origSize = GetSize();
    SPInt srcSize = 0;
    UTF8Util::EncodeCharSafe(buff, sizeof(buff), &srcSize, ch);
    UPInt size = origSize + srcSize;
    Resize(size);
    memcpy(pData + origSize, buff, srcSize);
}

void StringBuffer::AppendString(const wchar_t* str, SPInt len)
{
    if (!str)
        return;
    SPInt srcSize = UTF8Util::GetEncodeStringSize(str, len);
    UPInt origSize = GetSize();
    UPInt size = srcSize + origSize;
    Resize(size);
    UTF8Util::EncodeStringSafe(pData + origSize, srcSize + 1, str, len);
}

void StringBuffer::AppendString(const char* utf8, SPInt utf8StrSz)
{
    if (!utf8 || !utf8StrSz)
        return;
    if (utf8StrSz == -1)
        utf8StrSz = (SPInt)SFstrlen(utf8);
    UPInt origSize = GetSize();
    UPInt size = utf8StrSz + origSize;
    Resize(size);
    memcpy(pData + origSize, utf8, utf8StrSz);
}

void StringBuffer::operator=(const char* str)
{
    str = str ? str : "";
    UPInt size = SFstrlen(str);
    Resize(size);
    memcpy(pData, str, size);
}

void StringBuffer::operator=(const wchar_t* str)
{
    str = str ? str : L"";
    UPInt size = (UPInt)UTF8Util::GetEncodeStringSize(str);
    Resize(size);
    UTF8Util::EncodeStringSafe(pData, size + 1, str);
}

void StringBuffer::operator=(const String& src)
{
    Resize(src.GetSize());
    memcpy(pData, src.ToCStr(), src.GetSize());
}

void StringBuffer::operator=(const StringBuffer& src)
{
    pHeap = src.pHeap;
    GrowSize = src.GrowSize;
    Resize(src.GetSize());
    memcpy(pData, src.ToCStr(), src.GetSize());
    LengthIsSize = src.LengthIsSize;
}

void StringBuffer::Insert(const char* substr, UPInt posAt, SPInt len)
{
    UPInt oldSize = Size;
    UPInt insertSize = (len < 0) ? SFstrlen(substr) : (UPInt)len;
    UPInt byteIndex = LengthIsSize ? posAt : (UPInt)UTF8Util::GetByteIndex(posAt, pData, (SPInt)Size);

    Reserve(oldSize + insertSize);
    memmove(pData + byteIndex + insertSize, pData + byteIndex, oldSize - byteIndex + 1);
    memcpy(pData + byteIndex, substr, insertSize);
    LengthIsSize = false;
    Size = oldSize + insertSize;
    pData[Size] = 0;
}

UPInt StringBuffer::InsertCharAt(UInt32 c, UPInt posAt)
{
    char  buf[8];
    SPInt len = 0;
    UTF8Util::EncodeCharSafe(buf, sizeof(buf), &len, c);
    buf[(UPInt)len] = 0;
    Insert(buf, posAt, len);
    return (UPInt)len;
}

#ifndef MS2_HOOK_DLL
StringDataPtr StringDataPtr::Null("", 0);
#endif

bool StringDataPtr::IsWhiteSpace(UInt32 c)
{
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' || c == '\v' || (c >= 0x2000 && c <= 0x200b) ||
            c == 0x2028 || c == 0x2029 || c == 0x205f || c == 0x3000);
}

StringDataPtr StringDataPtr::GetTruncateWhitespace() const
{
    const char* s = ToCStr();
    const char* b = s;
    const char* str = s;
    const char* e = s + GetSize();
    bool        foundNonWhite = false;

    // first non-white character
    while (b < e)
    {
        str = b;
        UInt32 c = UTF8Util::DecodeNextChar_Advance0(&b);
        if (!IsWhiteSpace(c))
        {
            foundNonWhite = true;
            break;
        }
    }
    if (b == e && !foundNonWhite)
        return StringDataPtr();

    // end of the last non-white character
    const char* l = b;
    const char* endNonWhite = l;
    while (l < e)
    {
        UInt32 c = UTF8Util::DecodeNextChar_Advance0(&l);
        if (IsWhiteSpace(c))
        {
            while (l < e)
            {
                UInt32 c2 = UTF8Util::DecodeNextChar_Advance0(&l);
                if (!IsWhiteSpace(c2))
                    break;
            }
        }
        else
            endNonWhite = l;
    }

    if (str == ToCStr() && endNonWhite == e)
        return *this;
    return StringDataPtr(str, endNonWhite - str);
}

SPInt StringDataPtr::FindLastChar(char c, UPInt initInd) const
{
    if (initInd == (UPInt)~0 || initInd > GetSize())
        initInd = GetSize();
    else
        ++initInd;
    for (UPInt i = initInd; i > 0; --i)
        if (pStr[i - 1] == c)
            return static_cast<SPInt>(i - 1);
    return -1;
}

SPInt StringDataPtr::FindSubstring(const StringDataPtr& s, UPInt initInd) const
{
    if (s.IsEmpty())
        return -1;
    const UPInt lastSi = s.GetSize() - 1;
    UPInt       si = 0;
    char        c = s[si];
    for (UPInt i = initInd; i < GetSize(); ++i)
    {
        if (pStr[i] == c)
        {
            if (si == lastSi)
                return static_cast<SPInt>(i - s.GetSize());
            else
                c = s[++si];
        }
        else if (si > 0)
        {
            si = 0;
            c = s[si];
        }
    }
    return -1;
}

StringDataPtr StringDataPtr::GetNextToken(char separator) const
{
    UPInt       curPos = 0;
    const char* curStr = ToCStr();
    for (; curPos < GetSize() && curStr[curPos]; ++curPos)
        if (curStr[curPos] == separator)
            break;
    return StringDataPtr(ToCStr(), curPos);
}


// ==== SF_Atomic ======================================================================================================

typedef BOOL (WINAPI* MS2_SF_InitCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD);

// Spin counts need InitializeCriticalSectionAndSpinCount, looked up once (it is missing on very old Windows).
Lock::Lock(unsigned spinCount)
{
    static bool    initTried = false;
    static FARPROC initFn = 0;
    if (!initTried)
    {
        initFn = ::GetProcAddress(::LoadLibraryA("kernel32.dll"), "InitializeCriticalSectionAndSpinCount");
        initTried = true;
    }
    if (initFn)
        ((MS2_SF_InitCriticalSectionAndSpinCount)initFn)(&cs, spinCount);
    else
        ::InitializeCriticalSection(&cs);
}

Lock::~Lock()
{
    ::DeleteCriticalSection(&cs);
}


// ==== SF_System ======================================================================================================

#ifndef MS2_HOOK_DLL
static SysAllocBase* System_pSysAlloc = 0;
bool                 System::HasMemoryLeaks = false;   // exe 0x143b15ff8
#else
extern SysAllocBase* System_pSysAlloc;                 // file static in the exe, bound by a symbols-manual row
#endif

// This library copy has the same body as the exported constructor in unit_141803210; keep it under a private
// helper name so the DLL publishes the game's exported address as the canonical decorated symbol.
// MS2-FUNCTIONAL: preserves the duplicate library constructor behavior under a unique helper name.
// @0x14258c290
void SystemCtorCopy14258c290(System* self, SysAllocBase* sysAlloc)
{
    (void)self;
    System::Init(MemoryHeap::RootHeapDesc(), sysAlloc);
}

// MS2-FUNCTIONAL: preserves the duplicate library constructor behavior under a unique helper name.
// @0x14258c270
void SystemCtorCopy14258c270(System* self, const MemoryHeap::HeapDesc& rootHeapDesc, SysAllocBase* sysAlloc)
{
    (void)self;
    System::Init(rootHeapDesc, sysAlloc);
}

MS2_SF_XTU void System::Init(const MemoryHeap::HeapDesc& rootHeapDesc, SysAllocBase* sysAlloc)
{
    if (!System_pSysAlloc)
    {
        Timer::initializeTimerSystem();
        sysAlloc->initHeapEngine(&rootHeapDesc);
        System_pSysAlloc = sysAlloc;
    }
}

void System::Destroy()
{
    if (System_pSysAlloc)
    {
        Thread::FinishAllThreads();
        HasMemoryLeaks = !System_pSysAlloc->shutdownHeapEngine();
        System_pSysAlloc = 0;
        Timer::shutdownTimerSystem();
    }
}

// ==== HeapPT_SysAllocMalloc ==========================================================================================

SysAllocPagedMalloc::SysAllocPagedMalloc(UPInt granularity)
    : Granularity((granularity + MinGranularity - 1) / MinGranularity * MinGranularity), Footprint(0), Base(~UPInt(0))
{
}

void SysAllocPagedMalloc::GetInfo(Info* i) const
{
    i->MinAlign = 1;
    i->MaxAlign = 1;
    i->Granularity = Granularity;
    i->SysDirectThreshold = 32768;
    i->MaxHeapGranularity = 8192;
    i->HasRealloc = false;
}

void* SysAllocPagedMalloc::Alloc(UPInt size, UPInt)
{
    void* ptr = malloc(size);
    if (ptr)
    {
        Footprint += size;
        if (UPInt(ptr) < Base)
            Base = UPInt(ptr);
    }
    return ptr;
}

bool SysAllocPagedMalloc::Free(void* ptr, UPInt size, UPInt)
{
    free(ptr);
    Footprint -= size;
    return true;
}

UPInt SysAllocPagedMalloc::GetBase() const
{
    return Base;
}

// ==== HeapPT_SysAllocWinAPI ==========================================================================================

UPInt SysMemMapperWinAPI::GetPageSize() const
{
    SYSTEM_INFO info;
    ::GetSystemInfo(&info);
    return info.dwPageSize;
}

// Unlike the SDK, the exe treats failing to reserve or commit address space as out of memory.
void* SysMemMapperWinAPI::ReserveAddrSpace(UPInt size)
{
    void* p = ::VirtualAlloc(0, size, MEM_RESERVE, PAGE_READWRITE);
    if (!p)
        throw std::bad_alloc();
    return p;
}

bool SysMemMapperWinAPI::ReleaseAddrSpace(void* ptr, UPInt)
{
    return ::VirtualFree(ptr, 0, MEM_RELEASE) != 0;
}

void* SysMemMapperWinAPI::MapPages(void* ptr, UPInt size)
{
    void* p = ::VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE);
    if (!p)
        throw std::bad_alloc();
    return p;
}

bool SysMemMapperWinAPI::UnmapPages(void* ptr, UPInt size)
{
    return ::VirtualFree(ptr, size, MEM_DECOMMIT) != 0;
}

SysAllocWinAPI::SysAllocWinAPI(UPInt granularity, UPInt segSize)
    : Mapper(), pAllocator(::new(PrivateData) SysAllocMapper(&Mapper, segSize, granularity, true))
{
}

SysAllocWinAPI::~SysAllocWinAPI()
{
}

void  SysAllocWinAPI::GetInfo(Info* i) const   { pAllocator->GetInfo(i); }
void* SysAllocWinAPI::Alloc(UPInt size, UPInt align) { return pAllocator->Alloc(size, align); }

bool SysAllocWinAPI::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align)
{
    return pAllocator->ReallocInPlace(oldPtr, oldSize, newSize, align);
}

bool  SysAllocWinAPI::Free(void* ptr, UPInt size, UPInt align) { return pAllocator->Free(ptr, size, align); }
UPInt SysAllocWinAPI::GetFootprint() const { return pAllocator->GetFootprint(); }
UPInt SysAllocWinAPI::GetUsedSpace() const { return pAllocator->GetUsedSpace(); }
const UInt32* SysAllocWinAPI::GetBitSet(UPInt seg) const { return pAllocator->GetBitSet(seg); }
UPInt SysAllocWinAPI::GetBase() const { return pAllocator->GetBase(); }


// ==== HeapMH_MemoryHeap ==============================================================================================

namespace HeapMH {
// in-place storage of the MH root (the exe's copy is never touched by the hook DLL)
static UPInt HeapRootMemMH[(sizeof(RootMH) + sizeof(UPInt) - 1) / sizeof(UPInt)];
}

void MemoryHeap::InitMH(SysAlloc* sysAlloc)
{
    if (HeapMH::GlobalRootMH)
        return;
    ::new(HeapMH::HeapRootMemMH) HeapMH::RootMH(sysAlloc);
}

void MemoryHeap::CleanUpMH()
{
    if (HeapMH::GlobalRootMH == 0)
        return;
    HeapMH::GlobalRootMH->~RootMH();
    HeapMH::GlobalRootMH = 0;
}

MemoryHeap* MemoryHeap::CreateRootHeapMH(const HeapDesc& desc)
{
    if (HeapMH::GlobalRootMH == 0)
        return 0;
    {
        LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
        if (Memory::pGlobalHeap)
            return 0;
        HeapDesc d2 = desc;
        d2.HeapId = HeapId_Global;
        Memory::pGlobalHeap = HeapMH::GlobalRootMH->CreateHeap("Global", 0, d2);
    }
    return Memory::pGlobalHeap;
}

MemoryHeap* MemoryHeap::CreateRootHeapMH()
{
    HeapDesc desc;
    desc.Flags = Heap_Root;
    desc.MinAlign = RootHeap_MinAlign;
    desc.Granularity = RootHeap_Granularity;
    desc.Reserve = RootHeap_Reserve;
    desc.Threshold = RootHeap_Threshold;
    desc.Limit = RootHeap_Limit;
    desc.HeapId = HeapId_Global;
    return CreateRootHeapMH(desc);
}

bool MemoryHeap::ReleaseRootHeapMH()
{
    bool hasNoLeaks;
    if (HeapMH::GlobalRootMH == 0)
        return true;
    LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
    if (Memory::pGlobalHeap == 0)
        return true;
    hasNoLeaks = !Memory::pGlobalHeap->dumpMemoryLeaks();
    Memory::pGlobalHeap->destroyItself();
    Memory::pGlobalHeap = 0;
    return hasNoLeaks;
}

MemoryHeapMH::MemoryHeapMH() : MemoryHeap(), pEngine(0), pDebugStorage(0)
{
}

void MemoryHeapMH::CreateArena(UPInt, SysAllocPaged*) { }
void MemoryHeapMH::DestroyArena(UPInt) { }
bool MemoryHeapMH::ArenaIsEmpty(UPInt) { return true; }

MemoryHeap* MemoryHeapMH::CreateHeap(const char* name, const HeapDesc& desc)
{
    MemoryHeap* heap = 0;
    {
        LockSafe::Locker lock(HeapMH::GlobalRootMH->GetLock());
        heap = HeapMH::GlobalRootMH->CreateHeap(name, this, desc);
        if (heap)
            RefCount++;   // a child keeps its parent alive
    }
    if (heap)
    {
        Lock::Locker lock(&HeapLock);
        ChildHeaps.PushBack(heap);
    }
    return heap;
}

UPInt MemoryHeapMH::GetFootprint() const
{
    Lock::Locker lock(&HeapLock);
    return pEngine->GetFootprint();
}

UPInt MemoryHeapMH::GetTotalFootprint() const
{
    Lock::Locker lock(&HeapLock);
    UPInt footprint = 0;
    if (!(Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        footprint = pEngine->GetFootprint();
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        footprint += heap->GetTotalFootprint();
        heap = heap->pNext;
    }
    return footprint;
}

UPInt MemoryHeapMH::GetUsedSpace() const
{
    Lock::Locker lock(&HeapLock);
    return pEngine->GetUsedSpace();
}

UPInt MemoryHeapMH::GetTotalUsedSpace() const
{
    Lock::Locker lock(&HeapLock);
    UPInt space = 0;
    if (!(Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        space = pEngine->GetUsedSpace();
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        space += heap->GetTotalUsedSpace();
        heap = heap->pNext;
    }
    return space;
}

void MemoryHeapMH::SetLimitHandler(LimitHandler* handler)
{
    Lock::Locker locker(&HeapLock);
    pEngine->SetLimitHandler(handler);
}

void MemoryHeapMH::SetLimit(UPInt newLimit)
{
    Lock::Locker locker(&HeapLock);
    if (newLimit < Info.Desc.Limit)
    {
        if (newLimit < pEngine->GetFootprint())
            newLimit = pEngine->GetFootprint();
    }
    Info.Desc.Limit = pEngine->SetLimit(newLimit);
}

void MemoryHeapMH::AddRef()
{
    LockSafe::Locker lock(HeapMH::GlobalRootMH->GetLock());
    RefCount++;
}

// The last release destroys the heap and drops the reference it held on its parent.
void MemoryHeapMH::Release()
{
    MemoryHeap* parent = Info.pParent;
    if (parent)
    {
        Lock::Locker     localLock(&parent->HeapLock);
        LockSafe::Locker globalLock(HeapMH::GlobalRootMH->GetLock());
        if (--RefCount == 0)
        {
            dumpMemoryLeaks();
            parent->ChildHeaps.Remove(this);
            HeapMH::GlobalRootMH->DestroyHeap(this);
        }
        else
        {
            parent = 0;
        }
    }
    else
    {
        LockSafe::Locker lock(HeapMH::GlobalRootMH->GetLock());
        RefCount--;
    }
    if (parent)
        parent->Release();
}

bool MemoryHeapMH::dumpMemoryLeaks()
{
    return false;   // no debug storage in this build
}

void MemoryHeapMH::destroyItself()
{
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        MemoryHeap* next = heap->pNext;
        heap->destroyItself();
        heap = next;
    }
    HeapMH::GlobalRootMH->DestroyHeap(this);
}

void MemoryHeapMH::freeLocked(void* ptr, bool globalLocked)
{
    Lock::Locker heapLocker(&HeapLock);
    if (globalLocked)
    {
        pEngine->Free(ptr, true);
    }
    else
    {
        LockSafe::Locker rootLocker(HeapMH::GlobalRootMH->GetLock());
        pEngine->Free(ptr, true);
    }
}

inline void* MemoryHeapMH::allocMem(UPInt size, const AllocInfo*, bool globalLocked)
{
    HeapMH::PageInfoMH pageInfo;
    return pEngine->Alloc(size, &pageInfo, globalLocked);
}

inline void* MemoryHeapMH::allocMem(UPInt size, UPInt align, const AllocInfo*, bool globalLocked)
{
    HeapMH::PageInfoMH pageInfo;
    return pEngine->Alloc(size, align, &pageInfo, globalLocked);
}

inline void* MemoryHeapMH::allocMem(HeapMH::PageInfoMH*, const void*, UPInt size, const AllocInfo*, bool globalLocked)
{
    HeapMH::PageInfoMH pageInfo;
    return pEngine->Alloc(size, &pageInfo, globalLocked);
}

inline void* MemoryHeapMH::allocMem(HeapMH::PageInfoMH*, const void*, UPInt size, UPInt align, const AllocInfo*,
                                    bool globalLocked)
{
    HeapMH::PageInfoMH pageInfo;
    return pEngine->Alloc(size, align, &pageInfo, globalLocked);
}

void* MemoryHeapMH::Alloc(UPInt size, const AllocInfo* info)
{
    if (UseLocks)
    {
        Lock::Locker locker(&HeapLock);
        return allocMem(size, info, false);
    }
    return allocMem(size, info, false);
}

void* MemoryHeapMH::Alloc(UPInt size, UPInt align, const AllocInfo* info)
{
    if (UseLocks)
    {
        Lock::Locker locker(&HeapLock);
        return allocMem(size, align, info, false);
    }
    return allocMem(size, align, info, false);
}

// Allocate in the heap owning thisPtr: a page-table lookup for small blocks, else the global tree (root lock).
void* MemoryHeapMH::AllocAutoHeap(const void* thisPtr, UPInt size, const AllocInfo* info)
{
    MemoryHeapMH*   heap;
    HeapMH::PageMH* page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(thisPtr));
    void*           ptr = 0;
    if (page)
    {
        heap = page->pHeap;
        if (heap->UseLocks)
        {
            Lock::Locker locker(&heap->HeapLock);
            return heap->allocMem(0, thisPtr, size, info, false);
        }
        else
        {
            return heap->allocMem(0, thisPtr, size, info, false);
        }
    }
    else
    {
        HeapMH::NodeMH* node = 0;
        {
            LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
            node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)thisPtr);
            heap = node->GetHeap();
        }
        if (heap->UseLocks)
        {
            Lock::Locker     locker1(&heap->HeapLock);
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            ptr = heap->allocMem(0, thisPtr, size, info, true);
        }
        else
        {
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            ptr = heap->allocMem(0, thisPtr, size, info, true);
        }
    }
    return ptr;
}

void* MemoryHeapMH::AllocAutoHeap(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info)
{
    MemoryHeapMH*   heap;
    HeapMH::PageMH* page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(thisPtr));
    void*           ptr = 0;
    if (page)
    {
        heap = page->pHeap;
        if (heap->UseLocks)
        {
            Lock::Locker locker(&heap->HeapLock);
            return heap->allocMem(0, thisPtr, size, align, info, false);
        }
        else
        {
            return heap->allocMem(0, thisPtr, size, align, info, false);
        }
    }
    else
    {
        HeapMH::NodeMH* node = 0;
        {
            LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
            node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)thisPtr);
            heap = node->GetHeap();
        }
        if (heap->UseLocks)
        {
            Lock::Locker     locker1(&heap->HeapLock);
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            ptr = heap->allocMem(0, thisPtr, size, align, info, true);
        }
        else
        {
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            ptr = heap->allocMem(0, thisPtr, size, align, info, true);
        }
    }
    return ptr;
}

void MemoryHeapMH::freeMem(HeapMH::PageMH* page, void* ptr, bool globalLocked)
{
    pEngine->Free(page, ptr, globalLocked);
}

void MemoryHeapMH::freeMem(HeapMH::NodeMH* node, void* ptr, bool globalLocked)
{
    pEngine->Free(node, ptr, globalLocked);
}

void MemoryHeapMH::Free(void* ptr)
{
    if (ptr)
    {
        MemoryHeapMH*   heap = 0;
        HeapMH::PageMH* page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(ptr));
        if (page)
        {
            heap = page->pHeap;
            if (heap->UseLocks)
            {
                Lock::Locker locker(&heap->HeapLock);
                heap->freeMem(page, ptr, false);
            }
            else
            {
                heap->freeMem(page, ptr, false);
            }
        }
        else
        {
            HeapMH::NodeMH* node = 0;
            {
                LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
                node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)ptr);
                heap = node->GetHeap();
            }
            if (heap->UseLocks)
            {
                Lock::Locker     locker1(&heap->HeapLock);
                LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
                heap->freeMem(node, ptr, true);
            }
            else
            {
                LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
                heap->freeMem(node, ptr, true);
            }
        }
        // ReleaseOnFree: the heap goes away with this block
        if (ptr == heap->pAutoRelease)
            heap->Release();
    }
}

void* MemoryHeapMH::reallocMem(HeapMH::PageMH* page, void* oldPtr, UPInt newSize, bool globalLocked)
{
    HeapMH::PageInfoMH newPageInfo;
    void* newPtr = pEngine->ReallocInPage(page, oldPtr, newSize, &newPageInfo, globalLocked);
    if (newPtr == 0)
    {
        if (globalLocked)
        {
            newPtr = pEngine->ReallocGeneral(page, oldPtr, newSize, &newPageInfo, true);
        }
        else
        {
            LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
            newPtr = pEngine->ReallocGeneral(page, oldPtr, newSize, &newPageInfo, true);
        }
    }
    return newPtr;
}

void* MemoryHeapMH::reallocMem(HeapMH::NodeMH* node, void* oldPtr, UPInt newSize, bool globalLocked)
{
    HeapMH::PageInfoMH newPageInfo;
    void* newPtr = pEngine->ReallocInNode(node, oldPtr, newSize, &newPageInfo, globalLocked);
    return newPtr;
}

void* MemoryHeapMH::Realloc(void* oldPtr, UPInt newSize)
{
    MemoryHeapMH*   heap;
    HeapMH::PageMH* page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(oldPtr));
    void*           newPtr = 0;
    if (page)
    {
        heap = page->pHeap;
        if (heap->UseLocks)
        {
            Lock::Locker locker(&heap->HeapLock);
            newPtr = heap->reallocMem(page, oldPtr, newSize, false);
        }
        else
        {
            newPtr = heap->reallocMem(page, oldPtr, newSize, false);
        }
    }
    else
    {
        HeapMH::NodeMH* node = 0;
        {
            LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
            node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)oldPtr);
            heap = node->GetHeap();
        }
        if (heap->UseLocks)
        {
            Lock::Locker     locker1(&heap->HeapLock);
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            newPtr = heap->reallocMem(node, oldPtr, newSize, true);
        }
        else
        {
            LockSafe::Locker locker2(HeapMH::GlobalRootMH->GetLock());
            newPtr = heap->reallocMem(node, oldPtr, newSize, true);
        }
    }
    return newPtr;
}

MemoryHeap* MemoryHeapMH::GetAllocHeap(const void* thisPtr)
{
    HeapMH::PageMH* page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(thisPtr));
    if (page)
        return page->pHeap;
    LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
    HeapMH::NodeMH* node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)thisPtr);
    return node->GetHeap();
}

UPInt MemoryHeapMH::GetUsableSize(const void* ptr)
{
    HeapMH::PageMH*    page = HeapMH::GlobalRootMH->ResolveAddress(UPInt(ptr));
    HeapMH::PageInfoMH pageInfo;
    if (page)
    {
        page->pHeap->pEngine->GetPageInfoWithSize(page, ptr, &pageInfo);
        return pageInfo.UsableSize;
    }
    LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
    HeapMH::NodeMH* node = HeapMH::GlobalRootMH->FindNodeInGlobalTree((UByte*)ptr);
    node->GetHeap()->pEngine->GetPageInfoWithSize(node, ptr, &pageInfo);
    return pageInfo.UsableSize;
}

void* MemoryHeapMH::AllocSysDirect(UPInt size)
{
    LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
    return HeapMH::GlobalRootMH->GetSysAlloc()->Alloc(size, sizeof(void*));
}

void MemoryHeapMH::FreeSysDirect(void* ptr, UPInt size)
{
    LockSafe::Locker locker(HeapMH::GlobalRootMH->GetLock());
    return HeapMH::GlobalRootMH->GetSysAlloc()->Free(ptr, size, sizeof(void*));
}

// With the null StatBag only the child footprint walk is left.
bool MemoryHeapMH::GetStats(StatBag* bag)
{
    Lock::Locker locker(&HeapLock);
    UPInt footprint = pEngine->GetFootprint();
    bag->AddStat(StatHeap_LocalFootprint, CounterStat(footprint));
    bag->AddStat(StatHeap_LocalUsedSpace, CounterStat(pEngine->GetUsedSpace()));
    bag->AddStat(StatHeap_Granularity, CounterStat(0));
    bag->AddStat(StatHeap_Reserve, CounterStat(0));
    bag->AddStat(StatHeap_Bookkeeping, CounterStat(0));
    bag->AddStat(StatHeap_Segments, CounterStat(0));
    bag->AddStat(StatHeap_DynamicGranularity, CounterStat(0));
    bag->AddStat(StatHeap_SysDirectSpace, CounterStat(0));

    UPInt childHeapCount = 0;
    UPInt childFootprint = 0;
    MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        if (!(heap->Info.Desc.Flags & MemoryHeap::Heap_UserDebug))
        {
            childHeapCount++;
            childFootprint += heap->GetTotalFootprint();
        }
        heap = heap->pNext;
    }
    if (childHeapCount)
    {
        bag->AddStat(StatHeap_ChildHeaps, CounterStat(childHeapCount));
        bag->AddStat(StatHeap_ChildFootprint, CounterStat(childFootprint));
    }
    bag->AddStat(StatHeap_TotalFootprint, CounterStat(childFootprint + footprint));
    return true;
}

void MemoryHeapMH::VisitMem(Heap::MemVisitor*, unsigned) { }
void MemoryHeapMH::VisitHeapSegments(Heap::SegVisitor*) const { }
void MemoryHeapMH::VisitRootSegments(Heap::SegVisitor*) { }

void MemoryHeapMH::getUserDebugStats(RootStats* stats) const
{
    Lock::Locker lock(&HeapLock);
    if (Info.Desc.Flags & MemoryHeap::Heap_UserDebug)
    {
        stats->UserDebugFootprint += pEngine->GetFootprint();
        stats->UserDebugUsedSpace += pEngine->GetUsedSpace();
    }
    const MemoryHeap* heap = ChildHeaps.GetFirst();
    while (!ChildHeaps.IsNull(heap))
    {
        heap->getUserDebugStats(stats);
        heap = heap->pNext;
    }
}

void MemoryHeapMH::GetRootStats(RootStats* stats)
{
    stats->UserDebugFootprint = 0;
    stats->UserDebugUsedSpace = 0;
    getUserDebugStats(stats);
    stats->DebugInfoFootprint = 0;
    stats->DebugInfoUsedSpace = 0;
    stats->SysMemFootprint = GetTotalFootprint() + stats->UserDebugFootprint + stats->DebugInfoFootprint;
    stats->SysMemUsedSpace = GetTotalUsedSpace() + stats->UserDebugFootprint + stats->DebugInfoFootprint;
    stats->PageMapFootprint = 0;
    stats->PageMapUsedSpace = 0;
    stats->BookkeepingFootprint = 0;
    stats->BookkeepingUsedSpace = 0;
}

void MemoryHeapMH::SetTracer(HeapTracer* tracer) { SF_UNUSED(tracer); }
void MemoryHeapMH::ultimateCheck() { }
void MemoryHeapMH::checkIntegrity() const { }
void MemoryHeapMH::releaseCachedMem() { }

bool SysAlloc::initHeapEngine(const void* heapDesc)
{
    MemoryHeap::InitMH(this);
    const MemoryHeap::HeapDesc& rootHeapDesc = *(const MemoryHeap::HeapDesc*)heapDesc;
    MemoryHeap* p = MemoryHeap::CreateRootHeapMH(rootHeapDesc);
    return p != 0;
}

bool SysAlloc::shutdownHeapEngine()
{
    bool hasNoLeaks = MemoryHeap::ReleaseRootHeapMH();
    MemoryHeap::CleanUpMH();
    return hasNoLeaks;
}


// ==== HeapPT_SysAllocStatic ==========================================================================================

SysAllocStatic::SysAllocStatic(void* mem1, UPInt size1, void* mem2, UPInt size2, void* mem3, UPInt size3, void* mem4,
                               UPInt size4)
    : MinSize(Heap::Heap_PageSize), NumSegments(0), pAllocator(0), TotalSpace(0)
{
    pAllocator = ::new(PrivateData) HeapPT::AllocLite(MinSize);
    if (mem1) AddMemSegment(mem1, size1);
    if (mem2) AddMemSegment(mem2, size2);
    if (mem3) AddMemSegment(mem3, size3);
    if (mem4) AddMemSegment(mem4, size4);
}

SysAllocStatic::SysAllocStatic(UPInt minSize)
    : MinSize(minSize), NumSegments(0), pAllocator(0), TotalSpace(0)
{
    pAllocator = ::new(PrivateData) HeapPT::AllocLite(MinSize);
}

// the usable part of a block is trimmed to MinSize alignment at both ends
void SysAllocStatic::AddMemSegment(void* mem, UPInt size)
{
    UByte* ptr = (UByte*)((UPInt(mem) + MinSize - 1) & ~(MinSize - 1));
    UByte* end = (UByte*)((UPInt(mem) + size) & ~(MinSize - 1));
    if (NumSegments < MaxSegments)
    {
        HeapPT::TreeSeg* seg = (HeapPT::TreeSeg*)Segments[NumSegments];
        seg->Buffer = ptr;
        seg->Size = end - ptr;
        seg->UseCount = 0;
        TotalSpace += seg->Size;
        pAllocator->InitSegment(seg);
        ++NumSegments;
    }
}

void SysAllocStatic::GetInfo(Info* i) const
{
    i->MinAlign = pAllocator->GetMinSize();
    i->MaxAlign = 0;
    i->Granularity = 0;
    i->HasRealloc = true;
}

void* SysAllocStatic::Alloc(UPInt size, UPInt alignment)
{
    HeapPT::TreeSeg* seg;
    return pAllocator->Alloc(size, alignment, &seg);
}

bool SysAllocStatic::ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignment)
{
    UPInt i;
    for (i = 0; i < NumSegments; ++i)
    {
        HeapPT::TreeSeg* seg = (HeapPT::TreeSeg*)Segments[i];
        if ((UByte*)oldPtr >= seg->Buffer && (UByte*)oldPtr < seg->Buffer + seg->Size)
        {
            HeapPT::AllocLite::ReallocResult ret = pAllocator->ReallocInPlace(seg, oldPtr, oldSize, newSize, alignment);
            return ret < HeapPT::AllocLite::ReallocFailed;
        }
    }
    return false;
}

bool SysAllocStatic::Free(void* ptr, UPInt size, UPInt alignment)
{
    UPInt i;
    for (i = 0; i < NumSegments; ++i)
    {
        HeapPT::TreeSeg* seg = (HeapPT::TreeSeg*)Segments[i];
        if ((UByte*)ptr >= seg->Buffer && (UByte*)ptr < seg->Buffer + seg->Size)
        {
            pAllocator->Free(seg, ptr, size, alignment);
            return true;
        }
    }
    return false;
}

void SysAllocStatic::VisitMem(Heap::MemVisitor* visitor) const
{
    pAllocator->VisitMem(visitor, Heap::MemVisitor::Cat_SysAllocFree);
}

UPInt SysAllocStatic::GetBase() const
{
    UPInt i;
    UPInt m = ~UPInt(0);
    for (i = 0; i < NumSegments; ++i)
    {
        HeapPT::TreeSeg* seg = (HeapPT::TreeSeg*)Segments[i];
        if (UPInt(seg->Buffer) < m)
            m = UPInt(seg->Buffer);
    }
    return m;
}

UPInt SysAllocStatic::GetSize() const
{
    UPInt i;
    UPInt s = 0;
    for (i = 0; i < NumSegments; ++i)
        s += ((HeapPT::TreeSeg*)Segments[i])->Size;
    return s;
}

UPInt SysAllocStatic::GetFootprint() const { return TotalSpace; }
UPInt SysAllocStatic::GetUsedSpace() const { return TotalSpace - pAllocator->GetFreeBytes(); }

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?AddRef@RefCountImpl@Scaleform@@QEAAXXZ 0x14257dc30
// MS2-PIN: ?AddRef@RefCountVImpl@Scaleform@@UEAAXXZ 0x14257dc40
// MS2-PIN: ?CreateWeakProxy@RefCountWeakSupportImpl@Scaleform@@QEBAPEAVWeakPtrProxy@2@XZ 0x14257dc50
// MS2-PIN: ?Release@RefCountImpl@Scaleform@@QEAAXXZ 0x14257dcb0
// MS2-PIN: ?Release@RefCountNTSImpl@Scaleform@@QEBAXXZ 0x14257dcd0
// MS2-PIN: ?Release@RefCountVImpl@Scaleform@@UEAAXXZ 0x14257dcf0
// MS2-PIN: ??1Log@Scaleform@@UEAA@XZ 0x14257dd10
// MS2-PIN: ?DefaultLogMessageVarg@Log@Scaleform@@SAXVLogMessageId@2@PEBDPEAD@Z 0x14257dd40
// MS2-PIN: ?FormatLog@Log@Scaleform@@SAXPEADIVLogMessageId@2@PEBD0@Z 0x14257deb0
// MS2-PIN: ?GetDefaultLog@Log@Scaleform@@SAPEAV12@XZ 0x14257e000
// MS2-PIN: ?GetGlobalLog@Log@Scaleform@@SAPEAV12@XZ 0x14257e080
// MS2-PIN: ?LogMessageById@Log@Scaleform@@QEAAXVLogMessageId@2@PEBDZZ 0x14257e090
// MS2-PIN: ?LogMessageVarg@Log@Scaleform@@UEAAXVLogMessageId@2@PEBDPEAD@Z 0x14257e0c0
// MS2-PIN: ?SetGlobalLog@Log@Scaleform@@SAXPEAV12@@Z 0x14257e230
// MS2-PIN: ??0MemoryHeap@Scaleform@@IEAA@XZ 0x14257e240
// MS2-PIN: ??_GMemoryHeap@Scaleform@@MEAAPEAXI@Z 0x14257e310
// MS2-PIN: ?AssignToCurrentThread@MemoryHeap@Scaleform@@QEAAXXZ 0x14257e360
// MS2-PIN: ?DumpMemoryLeaks@MemoryHeap@Scaleform@@QEAA_NXZ 0x14257e3b0
// MS2-PIN: ?LockAndVisit@MemoryHeap@Scaleform@@QEAAXPEAUHeapVisitor@12@@Z 0x14257e430
// MS2-PIN: ?ReleaseOnFree@MemoryHeap@Scaleform@@QEAAXPEAX@Z 0x14257e4a0
// MS2-PIN: ?VisitChildHeaps@MemoryHeap@Scaleform@@QEAAXPEAUHeapVisitor@12@@Z 0x14257e4d0
// MS2-PIN: ??0Event@Scaleform@@QEAA@_N0@Z 0x142582300
// MS2-PIN: ??0Semaphore@Scaleform@@QEAA@H_N@Z 0x142582360
// MS2-PIN: ??0SemaphoreWaitableIncrement@Scaleform@@QEAA@PEAVSemaphore@1@H@Z 0x1425823c0
// MS2-PIN: ??0Waitable@Scaleform@@QEAA@_N@Z 0x142582490
// MS2-PIN: ??1Event@Scaleform@@UEAA@XZ 0x142582530
// MS2-PIN: ??1Semaphore@Scaleform@@UEAA@XZ 0x142582580
// MS2-PIN: ??1SemaphoreWaitableIncrement@Scaleform@@UEAA@XZ 0x1425825d0
// MS2-PIN: ??1Waitable@Scaleform@@UEAA@XZ 0x142582620
// MS2-PIN: ??ESemaphore@Scaleform@@QEAAHH@Z 0x1425826a0
// MS2-PIN: ??FSemaphore@Scaleform@@QEAAHH@Z 0x142582710
// MS2-PIN: ??YSemaphore@Scaleform@@QEAAHH@Z 0x1425827f0
// MS2-PIN: ??ZSemaphore@Scaleform@@QEAAHH@Z 0x142582870
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142582980
// MS2-PIN: ??_GAcquireInterface@Scaleform@@UEAAPEAXI@Z 0x1425829e0
// MS2-PIN: ??_GDefaultAcquireInterface@Scaleform@@UEAAPEAXI@Z 0x142582a10
// MS2-PIN: ??_GEvent@Scaleform@@UEAAPEAXI@Z 0x142582a40
// MS2-PIN: ??_GSemaphore@Scaleform@@UEAAPEAXI@Z 0x142582ad0
// MS2-PIN: ??_GSemaphoreWaitableIncrement@Scaleform@@UEAAPEAXI@Z 0x142582b60
// MS2-PIN: ??_GWaitable@Scaleform@@UEAAPEAXI@Z 0x142582bf0
// MS2-PIN: ?Acquire@Waitable@Scaleform@@QEAA_NI@Z 0x142582c50
// MS2-PIN: ?AcquireInterface_MultipleWaitHandler@Scaleform@@YAXPEAX@Z 0x142582c80
// MS2-PIN: ?AcquireInterface_OneOfMultipleWaitHandler@Scaleform@@YAXPEAX@Z 0x142582d70
// MS2-PIN: ?AcquireInterface_TryAcquireAll@Scaleform@@YA_NPEAPEAVAcquireInterface@1@I@Z 0x142582e70
// MS2-PIN: ?AcquireInterface_TryAcquireOne@Scaleform@@YAHPEAPEAVWaitable@1@I@Z 0x142582f20
// MS2-PIN: ?AcquireMultipleObjects@AcquireInterface@Scaleform@@SA_NPEAPEAVWaitable@2@II@Z 0x142582f90
// MS2-PIN: ?AcquireOneOfMultipleObjects@AcquireInterface@Scaleform@@SAHPEAPEAVWaitable@2@II@Z 0x1425833a0
// MS2-PIN: ?AddHandlers@AcquireInterface_AcquireDesc@Scaleform@@QEAA_NP6AXPEAX@Z@Z 0x1425836f0
// MS2-PIN: ?AddWaitHandler@Waitable@Scaleform@@QEAA_NP6AXPEAX@Z0@Z 0x142583780
// MS2-PIN: ?CanAcquire@AcquireInterface@Scaleform@@UEAA_NXZ 0x142583960
// MS2-PIN: ?CreateWaitableIncrement@Semaphore@Scaleform@@QEAAPEAVWaitable@2@H@Z 0x1425839b0
// MS2-PIN: ?GetAcquireInterface@Waitable@Scaleform@@UEAAPEAVAcquireInterface@2@XZ 0x142583ae0
// MS2-PIN: ?GetDefaultAcquireInterface@DefaultAcquireInterface@Scaleform@@SAPEAV12@XZ 0x142583b70
// MS2-PIN: ?ObtainSemaphore@Semaphore@Scaleform@@QEAA_NHI@Z 0x142583c50
// MS2-PIN: ?PulseEvent@Event@Scaleform@@QEAAXXZ 0x142583d50
// MS2-PIN: ?Release@HandlerArray@Waitable@Scaleform@@QEAAXXZ 0x142583e10
// MS2-PIN: ?ReleaseSemaphore@Semaphore@Scaleform@@QEAA_NH@Z 0x142583e80
// MS2-PIN: ?RemoveHandlers@AcquireInterface_AcquireDesc@Scaleform@@QEAAXP6AXPEAX@Z@Z 0x142583f80
// MS2-PIN: ?RemoveWaitHandler@Waitable@Scaleform@@QEAA_NP6AXPEAX@Z0@Z 0x142584090
// MS2-PIN: ?Reserve@?$ArrayDataBase@VHandlerStruct@Waitable@Scaleform@@U?$AllocatorGH@VHandlerStruct@Waitable@Scaleform@@$01@3@U?$ArrayConstPolicy@$0A@$0BA@$00@3@@Scaleform@@QEAAXPEBX_K@Z 0x1425841b0
// MS2-PIN: ?ResetEvent@Event@Scaleform@@QEAAXXZ 0x142584260
// MS2-PIN: ?SetEvent@Event@Scaleform@@QEAAXXZ 0x1425842b0
// MS2-PIN: ?TryAcquire@AcquireInterface@Scaleform@@UEAA_NXZ 0x142584370
// MS2-PIN: ?TryAcquire@Semaphore@Scaleform@@UEAA_NXZ 0x142584390
// MS2-PIN: ?TryAcquire@SemaphoreWaitableIncrement@Scaleform@@UEAA_NXZ 0x1425843f0
// MS2-PIN: ?TryAcquireCancel@AcquireInterface@Scaleform@@UEAA_NXZ 0x142584480
// MS2-PIN: ?TryAcquireCommit@AcquireInterface@Scaleform@@UEAA_NXZ 0x1425844d0
// MS2-PIN: ?TryAcquireCommit@Event@Scaleform@@UEAA_NXZ 0x1425844e0
// MS2-PIN: ?Wait@Event@Scaleform@@QEAA_NI@Z 0x142584540
// MS2-PIN: ?Wait@Waitable@Scaleform@@QEAA_NI@Z 0x1425845e0
// MS2-PIN: ?Waitable_SingleWaitHandler@Scaleform@@YAXPEAX@Z 0x142584890
// MS2-PIN: ??0String@Scaleform@@QEAA@AEBUInitStruct@01@_K@Z 0x1425848c0
// MS2-PIN: ??0String@Scaleform@@QEAA@AEBV01@@Z 0x142584950
// MS2-PIN: ??0String@Scaleform@@QEAA@AEBVStringBuffer@1@@Z 0x142584a00
// MS2-PIN: ??0String@Scaleform@@QEAA@PEBD00@Z 0x142584aa0
// MS2-PIN: ??0String@Scaleform@@QEAA@PEBD@Z 0x142584b70
// MS2-PIN: ??0String@Scaleform@@QEAA@PEBD_K@Z 0x142584c10
// MS2-PIN: ??0String@Scaleform@@QEAA@PEB_W@Z 0x142584ca0
// MS2-PIN: ??0String@Scaleform@@QEAA@XZ 0x142584ce0
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@AEBV01@PEAVMemoryHeap@1@@Z 0x142584d00
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@AEBVString@1@PEAVMemoryHeap@1@@Z 0x142584d60
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@PEAVMemoryHeap@1@@Z 0x142584db0
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@PEBDPEAVMemoryHeap@1@@Z 0x142584dd0
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@PEBD_KPEAVMemoryHeap@1@@Z 0x142584e50
// MS2-PIN: ??0StringBuffer@Scaleform@@QEAA@PEB_WPEAVMemoryHeap@1@@Z 0x142584e90
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@@Z 0x142584fc0
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@AEBUInitStruct@String@1@_K@Z 0x142584ff0
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@PEBD11@Z 0x142585080
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@PEBD@Z 0x142585180
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@PEBD_K@Z 0x142585230
// MS2-PIN: ??0StringDH@Scaleform@@QEAA@PEAVMemoryHeap@1@PEB_W@Z 0x1425852c0
// MS2-PIN: ??0StringLH@Scaleform@@QEAA@AEBUInitStruct@String@1@_K@Z 0x142585300
// MS2-PIN: ??0StringLH@Scaleform@@QEAA@PEBD@Z 0x1425853a0
// MS2-PIN: ??0StringLH@Scaleform@@QEAA@PEBD_K@Z 0x142585460
// MS2-PIN: ??0StringLH@Scaleform@@QEAA@PEB_W@Z 0x142585500
// MS2-PIN: ??0StringLH@Scaleform@@QEAA@XZ 0x142585540
// MS2-PIN: ??4String@Scaleform@@QEAAXAEBV01@@Z 0x142585580
// MS2-PIN: ??4String@Scaleform@@QEAAXAEBVStringBuffer@1@@Z 0x1425856c0
// MS2-PIN: ??4String@Scaleform@@QEAAXPEBD@Z 0x1425857d0
// MS2-PIN: ??4String@Scaleform@@QEAAXPEB_W@Z 0x1425858e0
// MS2-PIN: ??4StringBuffer@Scaleform@@QEAAXAEBV01@@Z 0x1425859f0
// MS2-PIN: ??4StringBuffer@Scaleform@@QEAAXAEBVString@1@@Z 0x142585a50
// MS2-PIN: ??4StringBuffer@Scaleform@@QEAAXPEBD@Z 0x142585ab0
// MS2-PIN: ??4StringBuffer@Scaleform@@QEAAXPEB_W@Z 0x142585b10
// MS2-PIN: ??HString@Scaleform@@QEBA?AV01@AEBV01@@Z 0x142585b80
// MS2-PIN: ??HString@Scaleform@@QEBA?AV01@PEBD@Z 0x142585c90
// MS2-PIN: ??YString@Scaleform@@QEAAXAEBV01@@Z 0x142585ce0
// MS2-PIN: ?AllocData@String@Scaleform@@IEAAPEAUDataDesc@12@PEAVMemoryHeap@2@_K1@Z 0x142585de0
// MS2-PIN: ?AllocDataCopy1@String@Scaleform@@IEAAPEAUDataDesc@12@PEAVMemoryHeap@2@_K1PEBD1@Z 0x142585e50
// MS2-PIN: ?AllocDataCopy2@String@Scaleform@@IEAAPEAUDataDesc@12@PEAVMemoryHeap@2@_K1PEBD121@Z 0x142585ed0
// MS2-PIN: ?AppendChar@String@Scaleform@@QEAAXK@Z 0x142585f70
// MS2-PIN: ?AppendChar@StringBuffer@Scaleform@@QEAAXK@Z 0x1425860b0
// MS2-PIN: ?AppendString@String@Scaleform@@QEAAXPEBD_J@Z 0x142586130
// MS2-PIN: ?AppendString@String@Scaleform@@QEAAXPEB_W_J@Z 0x142586230
// MS2-PIN: ?AppendString@StringBuffer@Scaleform@@QEAAXPEBD_J@Z 0x142586340
// MS2-PIN: ?AppendString@StringBuffer@Scaleform@@QEAAXPEB_W_J@Z 0x1425863b0
// MS2-PIN: ?AssignString@String@Scaleform@@QEAAXAEBUInitStruct@12@_K@Z 0x142586430
// MS2-PIN: ?AssignString@String@Scaleform@@QEAAXPEBD_K@Z 0x142586530
// MS2-PIN: ?BernsteinHashFunction@String@Scaleform@@SA_KPEBX_K1@Z 0x142586630
// MS2-PIN: ?BernsteinHashFunctionCIS@String@Scaleform@@SA_KPEBX_K1@Z 0x142586660
// MS2-PIN: ?Clear@String@Scaleform@@QEAAXXZ 0x1425866a0
// MS2-PIN: ?CompareNoCase@String@Scaleform@@SAHPEBD0_J@Z 0x142586720
// MS2-PIN: ?CopyConstructHelper@StringDH@Scaleform@@AEAAXAEBVString@2@PEAVMemoryHeap@2@@Z 0x1425867f0
// MS2-PIN: ?CopyConstructHelper@StringLH@Scaleform@@AEAAXAEBVString@2@@Z 0x1425868d0
// MS2-PIN: ?EscapeSpecialHTML@String@Scaleform@@SAXPEBD_KPEAV12@@Z 0x1425869b0
// MS2-PIN: ?FindLastChar@StringDataPtr@Scaleform@@QEBA_JD_K@Z 0x142586e30
// MS2-PIN: ?FindSubstring@StringDataPtr@Scaleform@@QEBA_JAEBV12@_K@Z 0x142586e70
// MS2-PIN: ?GetCharAt@String@Scaleform@@QEBAK_K@Z 0x142586ef0
// MS2-PIN: ?GetFirstCharAt@String@Scaleform@@QEBAK_KPEAPEBD@Z 0x142586f50
// MS2-PIN: ?GetLength@String@Scaleform@@QEBA_KXZ 0x142587010
// MS2-PIN: ?GetLength@StringBuffer@Scaleform@@QEBA_KXZ 0x142587070
// MS2-PIN: ?GetNextChar@String@Scaleform@@QEBAKPEAPEBD@Z 0x1425870b0
// MS2-PIN: ?GetNextToken@StringDataPtr@Scaleform@@QEBA?AV12@D@Z 0x1425870d0
// MS2-PIN: ?GetTruncateWhitespace@StringDataPtr@Scaleform@@QEBA?AV12@XZ 0x142587110
// MS2-PIN: ?Insert@String@Scaleform@@QEAAAEAV12@PEBD_K_J@Z 0x1425872a0
// MS2-PIN: ?Insert@StringBuffer@Scaleform@@QEAAXPEBD_K_J@Z 0x1425873e0
// MS2-PIN: ?InsertCharAt@String@Scaleform@@QEAA_KK_K@Z 0x1425874d0
// MS2-PIN: ?InsertCharAt@StringBuffer@Scaleform@@QEAA_KK_K@Z 0x1425876b0
// MS2-PIN: ?Remove@String@Scaleform@@QEAAX_K_J@Z 0x142587840
// MS2-PIN: ?Reserve@StringBuffer@Scaleform@@QEAAX_K@Z 0x1425879b0
// MS2-PIN: ?Resize@StringBuffer@Scaleform@@QEAAX_K@Z 0x142587a10
// MS2-PIN: ?Substring@String@Scaleform@@QEBA?AV12@_K0@Z 0x142587b20
// MS2-PIN: ?ToLower@String@Scaleform@@QEBA?AV12@XZ 0x142587bf0
// MS2-PIN: ?ToUpper@String@Scaleform@@QEBA?AV12@XZ 0x142587e00
// MS2-PIN: ?UnescapeSpecialHTML@String@Scaleform@@SAXPEBD_KPEAV12@@Z 0x142588010
// MS2-PIN: ??0MemoryHeapMH@Scaleform@@AEAA@XZ 0x142588540
// MS2-PIN: ??_GMemoryHeapMH@Scaleform@@EEAAPEAXI@Z 0x1425885a0
// MS2-PIN: ?AddRef@MemoryHeapMH@Scaleform@@UEAAXXZ 0x1425885f0
// MS2-PIN: ?Alloc@MemoryHeapMH@Scaleform@@UEAAPEAX_K0PEBUAllocInfo@2@@Z 0x142588630
// MS2-PIN: ?Alloc@MemoryHeapMH@Scaleform@@UEAAPEAX_KPEBUAllocInfo@2@@Z 0x1425886d0
// MS2-PIN: ?AllocAutoHeap@MemoryHeapMH@Scaleform@@UEAAPEAXPEBX_K1PEBUAllocInfo@2@@Z 0x142588760
// MS2-PIN: ?AllocAutoHeap@MemoryHeapMH@Scaleform@@UEAAPEAXPEBX_KPEBUAllocInfo@2@@Z 0x1425888f0
// MS2-PIN: ?AllocSysDirect@MemoryHeapMH@Scaleform@@UEAAPEAX_K@Z 0x142588a70
// MS2-PIN: ?CleanUpMH@MemoryHeap@Scaleform@@SAXXZ 0x142588ae0
// MS2-PIN: ?CreateHeap@MemoryHeapMH@Scaleform@@UEAAPEAVMemoryHeap@2@PEBDAEBUHeapDesc@32@@Z 0x142588b20
// MS2-PIN: ?CreateRootHeapMH@MemoryHeap@Scaleform@@SAPEAV12@AEBUHeapDesc@12@@Z 0x142588be0
// MS2-PIN: ?CreateRootHeapMH@MemoryHeap@Scaleform@@SAPEAV12@XZ 0x142588c90
// MS2-PIN: ?FindNodeInGlobalTree@RootMH@HeapMH@Scaleform@@QEAAPEAUNodeMH@23@PEAE@Z 0x142588cf0
// MS2-PIN: ?Free@MemoryHeapMH@Scaleform@@UEAAXPEAX@Z 0x142588da0
// MS2-PIN: ?FreeSysDirect@MemoryHeapMH@Scaleform@@UEAAXPEAX_K@Z 0x142588f20
// MS2-PIN: ?GetAllocHeap@MemoryHeapMH@Scaleform@@UEAAPEAVMemoryHeap@2@PEBX@Z 0x142588f80
// MS2-PIN: ?GetFootprint@MemoryHeapMH@Scaleform@@UEBA_KXZ 0x142588ff0
// MS2-PIN: ?GetRootStats@MemoryHeapMH@Scaleform@@UEAAXPEAURootStats@MemoryHeap@2@@Z 0x142589040
// MS2-PIN: ?GetStats@MemoryHeapMH@Scaleform@@UEAA_NPEAVStatBag@2@@Z 0x1425890d0
// MS2-PIN: ?GetTotalFootprint@MemoryHeapMH@Scaleform@@UEBA_KXZ 0x142589150
// MS2-PIN: ?GetTotalUsedSpace@MemoryHeapMH@Scaleform@@UEBA_KXZ 0x1425891f0
// MS2-PIN: ?GetUsableSize@MemoryHeapMH@Scaleform@@UEAA_KPEBX@Z 0x142589290
// MS2-PIN: ?GetUsedSpace@MemoryHeapMH@Scaleform@@UEBA_KXZ 0x142589340
// MS2-PIN: ?Realloc@MemoryHeapMH@Scaleform@@UEAAPEAXPEAX_K@Z 0x1425893b0
// MS2-PIN: ?Release@MemoryHeapMH@Scaleform@@UEAAXXZ 0x142589550
// MS2-PIN: ?ReleaseRootHeapMH@MemoryHeap@Scaleform@@SA_NXZ 0x142589650
// MS2-PIN: ?SetLimit@MemoryHeapMH@Scaleform@@UEAAX_K@Z 0x1425896d0
// MS2-PIN: ?SetLimitHandler@MemoryHeapMH@Scaleform@@UEAAXPEAULimitHandler@MemoryHeap@2@@Z 0x142589740
// MS2-PIN: ?destroyItself@MemoryHeapMH@Scaleform@@EEAAXXZ 0x1425897e0
// MS2-PIN: ?freeLocked@MemoryHeapMH@Scaleform@@AEAAXPEAX_N@Z 0x142589860
// MS2-PIN: ?getUserDebugStats@MemoryHeapMH@Scaleform@@EEBAXPEAURootStats@MemoryHeap@2@@Z 0x142589920
// MS2-PIN: ?initHeapEngine@SysAlloc@Scaleform@@MEAA_NPEBX@Z 0x1425899d0
// MS2-PIN: ?reallocMem@MemoryHeapMH@Scaleform@@AEAAPEAXPEAUNodeMH@HeapMH@2@PEAX_K_N@Z 0x142589a10
// MS2-PIN: ?reallocMem@MemoryHeapMH@Scaleform@@AEAAPEAXPEAUPageMH@HeapMH@2@PEAX_K_N@Z 0x142589a40
// MS2-PIN: ?shutdownHeapEngine@SysAlloc@Scaleform@@MEAA_NXZ 0x142589b30
// MS2-PIN: ??0SysAllocStatic@Scaleform@@QEAA@PEAX_K010101@Z 0x142589bf0
// MS2-PIN: ??0SysAllocStatic@Scaleform@@QEAA@_K@Z 0x142589cc0
// MS2-PIN: ??_GSysAllocPaged@Scaleform@@UEAAPEAXI@Z 0x142589d10
// MS2-PIN: ??_GSysAllocStatic@Scaleform@@UEAAPEAXI@Z 0x142589d40
// MS2-PIN: ?AddMemSegment@SysAllocStatic@Scaleform@@QEAAXPEAX_K@Z 0x142589d70
// MS2-PIN: ?Alloc@SysAllocStatic@Scaleform@@UEAAPEAX_K0@Z 0x142589de0
// MS2-PIN: ?Free@SysAllocStatic@Scaleform@@UEAA_NPEAX_K1@Z 0x142589e10
// MS2-PIN: ?GetSize@SysAllocStatic@Scaleform@@UEBA_KXZ 0x142589f40
// MS2-PIN: ?ReallocInPlace@SysAllocStatic@Scaleform@@UEAA_NPEAX_K11@Z 0x142589ff0
// MS2-PIN: ?Destroy@System@Scaleform@@SAXXZ 0x14258c0a0
// MS2-PIN: ?Init@System@Scaleform@@SAXAEBUHeapDesc@MemoryHeap@2@PEAVSysAllocBase@2@@Z 0x14258c0f0
// MS2-PIN: ??0SysAllocPagedMalloc@Scaleform@@QEAA@_K@Z 0x14258cb30
// MS2-PIN: ??_G?$SysAllocBase_SingletonSupport@VSysAllocPagedMalloc@Scaleform@@VSysAllocPaged@2@@Scaleform@@UEAAPEAXI@Z 0x14258cb70
// MS2-PIN: ??_GSysAllocPagedMalloc@Scaleform@@UEAAPEAXI@Z 0x14258cba0
// MS2-PIN: ?Alloc@SysAllocPagedMalloc@Scaleform@@UEAAPEAX_K0@Z 0x14258cbd0
// MS2-PIN: ?Free@SysAllocPagedMalloc@Scaleform@@UEAA_NPEAX_K1@Z 0x14258cc10
// MS2-PIN: ?shutdownHeapEngine@?$SysAllocBase_SingletonSupport@VSysAllocPagedMalloc@Scaleform@@VSysAllocPaged@2@@Scaleform@@MEAA_NXZ 0x14258cca0
// MS2-PIN: ??0SysAllocWinAPI@Scaleform@@QEAA@_K0@Z 0x14258ccf0
// MS2-PIN: ??_G?$SysAllocBase_SingletonSupport@VSysAllocWinAPI@Scaleform@@VSysAllocPaged@2@@Scaleform@@UEAAPEAXI@Z 0x14258cd70
// MS2-PIN: ??_GSysAllocWinAPI@Scaleform@@UEAAPEAXI@Z 0x14258cda0
// MS2-PIN: ??_GSysMemMapper@Scaleform@@UEAAPEAXI@Z 0x14258cde0
// MS2-PIN: ??_GSysMemMapperWinAPI@Scaleform@@UEAAPEAXI@Z 0x14258ce10
// MS2-PIN: ?GetPageSize@SysMemMapperWinAPI@Scaleform@@UEBA_KXZ 0x14258cec0
// MS2-PIN: ?MapPages@SysMemMapperWinAPI@Scaleform@@UEAAPEAXPEAX_K@Z 0x14258cef0
// MS2-PIN: ?ReleaseAddrSpace@SysMemMapperWinAPI@Scaleform@@UEAA_NPEAX_K@Z 0x14258cf50
// MS2-PIN: ?ReserveAddrSpace@SysMemMapperWinAPI@Scaleform@@UEAAPEAX_K@Z 0x14258cf70
// MS2-PIN: ?UnmapPages@SysMemMapperWinAPI@Scaleform@@UEAA_NPEAX_K@Z 0x14258cfb0
// MS2-PIN: ?shutdownHeapEngine@?$SysAllocBase_SingletonSupport@VSysAllocWinAPI@Scaleform@@VSysAllocPaged@2@@Scaleform@@MEAA_NXZ 0x14258cfe0
// MS2-PIN: ??0Lock@Scaleform@@QEAA@I@Z 0x14258d030
// MS2-PIN: ??_7MemoryHeap@Scaleform@@6B@ 0x143183e08
// MS2-PIN: ??_7?$RefCountBase@VWaitable@Scaleform@@$01@Scaleform@@6B@ 0x143183fb8
// MS2-PIN: ??_7Waitable@Scaleform@@6B@ 0x143183fc0
// MS2-PIN: ??_7Event@Scaleform@@6BWaitable@1@@ 0x143183fd8
// MS2-PIN: ??_7Event@Scaleform@@6BAcquireInterface@1@@ 0x143183ff0
// MS2-PIN: ??_7Semaphore@Scaleform@@6BWaitable@1@@ 0x143184018
// MS2-PIN: ??_7Semaphore@Scaleform@@6BAcquireInterface@1@@ 0x143184030
// MS2-PIN: ??_7SemaphoreWaitableIncrement@Scaleform@@6BWaitable@1@@ 0x143184058
// MS2-PIN: ??_7SemaphoreWaitableIncrement@Scaleform@@6BAcquireInterface@1@@ 0x143184080
// MS2-PIN: ??_7MemoryHeapMH@Scaleform@@6B@ 0x1431840c8
// MS2-PIN: ??_7SysAllocPaged@Scaleform@@6B@ 0x1431841e0
// MS2-PIN: ??_7SysAllocStatic@Scaleform@@6B@ 0x143184258
// MS2-PIN: ??_7?$SysAllocBase_SingletonSupport@VSysAllocPagedMalloc@Scaleform@@VSysAllocPaged@2@@Scaleform@@6B@ 0x143184440
// MS2-PIN: ??_7SysAllocPagedMalloc@Scaleform@@6B@ 0x1431844b8
// MS2-PIN: ??_7SysMemMapper@Scaleform@@6B@ 0x143184530
// MS2-PIN: ??_7SysMemMapperWinAPI@Scaleform@@6B@ 0x143184560
// MS2-PIN: ??_7?$SysAllocBase_SingletonSupport@VSysAllocWinAPI@Scaleform@@VSysAllocPaged@2@@Scaleform@@6B@ 0x143184590
// MS2-PIN: ??_7SysAllocWinAPI@Scaleform@@6B@ 0x143184608
