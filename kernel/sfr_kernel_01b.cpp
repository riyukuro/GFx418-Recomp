// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_ThreadsWinAPI (Win32 mutex,
// condition variable, threads and the running-thread list). Our own source, written from the exe (the leaked SDK copies
// were only used to name things and to compare layouts). Queue unit sfr_kernel_01 is split along its original sources
// (sfr_kernel_01 / 01b): inlining of the Mutex/Waitable members differs between them.
// MS2-UNIT: sfr_kernel_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258a0c0-0x14258c0a0 .text$mn
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

namespace Scaleform {

// ==== SF_ThreadsWinAPI ===============================================================================================

// Acquire interface handed out while the calling thread already owns the mutex (recursive re-acquire).
class Mutex_AreadyLockedAcquireInterface : public AcquireInterface
{
public:
    Mutex* pMutex;
    Mutex_AreadyLockedAcquireInterface() { pMutex = 0; }

    virtual bool CanAcquire();
    virtual bool TryAcquire();
    virtual bool TryAcquireCommit();
    virtual bool TryAcquireCancel();
    virtual void AddRef() { }
    virtual void Release(unsigned flags = 0) { SF_UNUSED(flags); }
};

bool Mutex_AreadyLockedAcquireInterface::CanAcquire()       { return 1; }
bool Mutex_AreadyLockedAcquireInterface::TryAcquire()       { return pMutex->TryAcquire(); }
bool Mutex_AreadyLockedAcquireInterface::TryAcquireCommit() { return pMutex->TryAcquireCommit(); }
bool Mutex_AreadyLockedAcquireInterface::TryAcquireCancel() { return pMutex->TryAcquireCancel(); }

// Win32 mutex (recursive) or a one-count semaphore (non-recursive).
class MutexImpl : public NewOverrideBase<Stat_Default_Mem>
{
    HANDLE            hMutexOrSemaphore;
    bool              Recursive;
    volatile unsigned LockCount;
    Mutex_AreadyLockedAcquireInterface AreadyLockedAcquire;

    friend class WaitConditionImpl;

public:
    MutexImpl(Mutex* mutex, bool recursive = 1);
    ~MutexImpl();

    void              DoLock();
    bool              TryLock();
    void              Unlock(Mutex* mutex);
    bool              IsLockedByAnotherThread(Mutex* mutex);
    bool              IsSignaled() const;
    AcquireInterface* GetAcquireInterface(Mutex* mutex);
};

MutexImpl::MutexImpl(Mutex* mutex, bool recursive)
{
    AreadyLockedAcquire.pMutex = mutex;
    Recursive = recursive;
    LockCount = 0;
    hMutexOrSemaphore = Recursive ? CreateMutexA(NULL, 0, NULL) : CreateSemaphoreA(NULL, 1, 1, NULL);
}

MutexImpl::~MutexImpl()
{
    CloseHandle(hMutexOrSemaphore);
}

void MutexImpl::DoLock()
{
    if (::WaitForSingleObject(hMutexOrSemaphore, INFINITE) != WAIT_OBJECT_0)
        return;
    LockCount++;
}

bool MutexImpl::TryLock()
{
    DWORD ret;
    if ((ret = ::WaitForSingleObject(hMutexOrSemaphore, 0)) != WAIT_OBJECT_0)
        return 0;
    LockCount++;
    return 1;
}

void MutexImpl::Unlock(Mutex* mutex)
{
    unsigned lockCount;
    LockCount--;
    lockCount = LockCount;

    // take the handlers before releasing: the mutex may be destroyed by the next owner
    Mutex::CallableHandlers handlers;
    mutex->GetCallableHandlers(&handlers);

    if ((Recursive ? ReleaseMutex(hMutexOrSemaphore) : ReleaseSemaphore(hMutexOrSemaphore, 1, NULL)) != 0)
    {
        if (lockCount == 0)
            handlers.CallWaitHandlers();
    }
}

bool MutexImpl::IsLockedByAnotherThread(Mutex* mutex)
{
    if (LockCount == 0)
        return 0;
    if (!TryLock())
        return 1;
    Unlock(mutex);
    return 0;
}

bool MutexImpl::IsSignaled() const
{
    return LockCount == 0;
}

AcquireInterface* MutexImpl::GetAcquireInterface(Mutex* mutex)
{
    if (LockCount && !IsLockedByAnotherThread(mutex))
        return &AreadyLockedAcquire;
    return mutex;
}

Mutex::Mutex(bool recursive, bool multiWait)
    : Waitable(multiWait)
{
    pImpl = new MutexImpl(this, recursive);
}

Mutex::~Mutex()
{
    delete pImpl;
}

void Mutex::DoLock()                              { pImpl->DoLock(); }
bool Mutex::TryLock()                             { return pImpl->TryLock(); }
void Mutex::Unlock()                              { pImpl->Unlock(this); }
bool Mutex::IsLockedByAnotherThread()             { return pImpl->IsLockedByAnotherThread(this); }
bool Mutex::IsSignaled() const                    { return pImpl->IsSignaled(); }
AcquireInterface* Mutex::GetAcquireInterface()    { return pImpl->GetAcquireInterface(this); }
bool Mutex::CanAcquire()                          { return !IsLockedByAnotherThread(); }
bool Mutex::TryAcquire()                          { return TryLock(); }
bool Mutex::TryAcquireCommit()                    { return 1; }

bool Mutex::TryAcquireCancel()
{
    Unlock();
    return 1;
}

// Condition variable: a FIFO of manual-reset events, one per waiter, recycled through a free list.
class WaitConditionImpl : public NewOverrideBase<Stat_Default_Mem>
{
    struct EventPoolEntry : public NewOverrideBase<Stat_Default_Mem>
    {
        HANDLE          hEvent;
        EventPoolEntry* pNext;
        EventPoolEntry* pPrev;
    };

    Lock            WaitQueueLoc;
    EventPoolEntry* pFreeEventList;
    EventPoolEntry* pQueueHead;
    EventPoolEntry* pQueueTail;

    EventPoolEntry* GetNewEvent();
    void            ReleaseEvent(EventPoolEntry* entry);
    void            QueuePush(EventPoolEntry* entry);
    EventPoolEntry* QueuePop();
    void            QueueFindAndRemove(EventPoolEntry* entry);

public:
    WaitConditionImpl();
    ~WaitConditionImpl();

    bool Wait(Mutex* mutex, unsigned delay = SF_WAIT_INFINITE);
    void Notify();
    void NotifyAll();
};

WaitConditionImpl::WaitConditionImpl()
{
    pFreeEventList = 0;
    pQueueHead = pQueueTail = 0;
}

WaitConditionImpl::~WaitConditionImpl()
{
    EventPoolEntry* p = pFreeEventList;
    EventPoolEntry* entry;
    while (p)
    {
        entry = p;
        p = p->pNext;
        ::CloseHandle(entry->hEvent);
        delete entry;
    }
    pFreeEventList = 0;
    pQueueHead = pQueueTail = 0;
}

WaitConditionImpl::EventPoolEntry* WaitConditionImpl::GetNewEvent()
{
    EventPoolEntry* entry;
    if (pFreeEventList)
    {
        entry = pFreeEventList;
        pFreeEventList = pFreeEventList->pNext;
    }
    else
    {
        entry = new EventPoolEntry;
        entry->pNext = 0;
        entry->pPrev = 0;
        entry->hEvent = ::CreateEventA(NULL, TRUE, 0, NULL);
    }
    return entry;
}

void WaitConditionImpl::ReleaseEvent(EventPoolEntry* entry)
{
    ::ResetEvent(entry->hEvent);
    entry->pNext = pFreeEventList;
    entry->pPrev = 0;
    pFreeEventList = entry;
}

void WaitConditionImpl::QueuePush(EventPoolEntry* entry)
{
    if (pQueueTail)
    {
        entry->pPrev = pQueueTail;
        pQueueTail->pNext = entry;
        entry->pNext = 0;
        pQueueTail = entry;
    }
    else
    {
        entry->pNext = entry->pPrev = 0;
        pQueueHead = pQueueTail = entry;
    }
}

WaitConditionImpl::EventPoolEntry* WaitConditionImpl::QueuePop()
{
    EventPoolEntry* entry = pQueueHead;
    if (entry)
    {
        if (pQueueHead->pNext)
        {
            pQueueHead = entry->pNext;
            pQueueHead->pPrev = 0;
        }
        else
        {
            pQueueTail = pQueueHead = 0;
        }
    }
    return entry;
}

void WaitConditionImpl::QueueFindAndRemove(EventPoolEntry* entry)
{
    EventPoolEntry* p = pQueueHead;
    while (p)
    {
        if (p == entry)
        {
            if (entry->pPrev)
                entry->pPrev->pNext = entry->pNext;
            else
                pQueueHead = entry->pNext;
            if (entry->pNext)
                entry->pNext->pPrev = entry->pPrev;
            else
                pQueueTail = entry->pPrev;
            return;
        }
        p = p->pNext;
    }
}

bool WaitConditionImpl::Wait(Mutex* mutex, unsigned delay)
{
    bool            result = 0;
    unsigned        i;
    unsigned        lockCount = mutex->pImpl->LockCount;
    EventPoolEntry* entry;

    // waiting needs the mutex held
    if (lockCount == 0)
        return 0;

    WaitQueueLoc.DoLock();
    QueuePush(entry = GetNewEvent());
    WaitQueueLoc.Unlock();

    // release every recursion level of the mutex
    if (mutex->pImpl->Recursive)
    {
        mutex->pImpl->LockCount = 0;
        for (i = 0; i < lockCount; i++)
            ::ReleaseMutex(mutex->pImpl->hMutexOrSemaphore);
        mutex->CallWaitHandlers();
    }
    else
    {
        mutex->pImpl->LockCount = 0;
        ::ReleaseSemaphore(mutex->pImpl->hMutexOrSemaphore, 1, NULL);
        mutex->CallWaitHandlers();
    }

    DWORD waitResult = ::WaitForSingleObject(entry->hEvent, (delay == SF_WAIT_INFINITE) ? INFINITE : delay);

    WaitQueueLoc.DoLock();
    switch (waitResult)
    {
    case WAIT_ABANDONED:
    case WAIT_OBJECT_0:
        result = 1;
        ReleaseEvent(entry);
        break;
    default:
        // timed out: we are still queued
        QueueFindAndRemove(entry);
        ReleaseEvent(entry);
    }
    WaitQueueLoc.Unlock();

    for (i = 0; i < lockCount; i++)
        mutex->DoLock();
    return result;
}

void WaitConditionImpl::Notify()
{
    Lock::Locker lock(&WaitQueueLoc);
    EventPoolEntry* entry = QueuePop();
    if (entry)
        ::SetEvent(entry->hEvent);
}

void WaitConditionImpl::NotifyAll()
{
    Lock::Locker lock(&WaitQueueLoc);
    EventPoolEntry* entry = QueuePop();
    while (entry)
    {
        ::SetEvent(entry->hEvent);
        entry = QueuePop();
    }
}

WaitCondition::WaitCondition()
{
    pImpl = new WaitConditionImpl;
}

WaitCondition::~WaitCondition()
{
    delete pImpl;
}

bool WaitCondition::Wait(Mutex* mutex, unsigned delay) { return pImpl->Wait(mutex, delay); }
void WaitCondition::Notify()                           { pImpl->Notify(); }
void WaitCondition::NotifyAll()                        { pImpl->NotifyAll(); }

Thread::Thread(UPInt stackSize, int processor)
    : Waitable(1)
{
    CreateParams params;
    params.stackSize = stackSize;
    params.processor = processor;
    Init(params);
}

Thread::Thread(Thread::ThreadFn threadFunction, void* userHandle, UPInt stackSize, int processor,
               Thread::ThreadState initialState)
    : Waitable(1)
{
    CreateParams params(threadFunction, userHandle, stackSize, processor, initialState);
    Init(params);
}

Thread::Thread(const CreateParams& params)
    : Waitable(1)
{
    Init(params);
}

void Thread::Init(const CreateParams& params)
{
    ThreadFlags = 0;
    ThreadHandle = 0;
    IdValue = 0;
    ExitCode = 0;
    SuspendCount = 0;
    StackSize = params.stackSize;
    Processor = params.processor;
    Priority = params.priority;
    ThreadFunction = params.threadFunction;
    UserHandle = params.userHandle;
    if (params.initialState != NotRunning)
        Start(params.initialState);
}

Thread::~Thread()
{
    CleanupSystemThread();
    ThreadHandle = 0;
}

int Thread::Run()
{
    return (ThreadFunction) ? ThreadFunction(this, UserHandle) : 0;
}

void Thread::OnExit()
{
}

// Drops the reference Start took; handlers are taken first because Release may destroy the thread object.
void Thread::FinishAndRelease()
{
    CallableHandlers handlers;
    GetCallableHandlers(&handlers);
    ThreadFlags &= (UInt32)~(SF_THREAD_STARTED);
    ThreadFlags |= SF_THREAD_FINISHED;
    Release();
    handlers.CallWaitHandlers();
}

// All running threads, so FinishAllThreads can wait for them at shutdown.
class ThreadList : public NewOverrideBase<Stat_Default_Mem>
{
    struct ThreadHashOp
    {
        UPInt operator()(const Thread* ptr) { return (((UPInt)ptr) >> 6) ^ (UPInt)ptr; }
    };

    HashSet<Thread*, ThreadHashOp> ThreadSet;
    Mutex                          ThreadMutex;
    WaitCondition                  ThreadsEmpty;
    ThreadId                       RootThreadId;

    static ThreadList* volatile pRunningThreads;

    void addThread(Thread* thread)
    {
        Mutex::Locker lock(&ThreadMutex);
        ThreadSet.Add(thread);
    }
    void removeThread(Thread* thread)
    {
        Mutex::Locker lock(&ThreadMutex);
        ThreadSet.Remove(thread);
        if (ThreadSet.GetSize() == 0)
            ThreadsEmpty.Notify();
    }
    void finishAllThreads()
    {
        Mutex::Locker lock(&ThreadMutex);
        while (ThreadSet.GetSize() != 0)
            ThreadsEmpty.Wait(&ThreadMutex);
    }

public:
    ThreadList() { RootThreadId = GetCurrentThreadId(); }
    ~ThreadList() { }

    static void AddRunningThread(Thread* thread)
    {
        if (!pRunningThreads)
            pRunningThreads = new ThreadList;
        pRunningThreads->addThread(thread);
    }
    static void RemoveRunningThread(Thread* thread)
    {
        pRunningThreads->removeThread(thread);
    }
    static void FinishAllThreads()
    {
        if (pRunningThreads)
        {
            pRunningThreads->finishAllThreads();
            delete pRunningThreads;
            pRunningThreads = 0;
        }
    }
};

#ifndef MS2_HOOK_DLL
ThreadList* volatile ThreadList::pRunningThreads = 0;   // exe copy 0x143b15ff0
#endif

void Thread::FinishAllThreads()
{
    ThreadList::FinishAllThreads();
}

int Thread::PRun()
{
    if (ThreadFlags & SF_THREAD_START_SUSPENDED)
    {
        Suspend();
        ThreadFlags &= (UInt32)~SF_THREAD_START_SUSPENDED;
    }
    ExitCode = Run();
    return ExitCode;
}

bool Thread::GetExitFlag() const
{
    return (ThreadFlags & SF_THREAD_EXIT) != 0;
}

void Thread::SetExitFlag(bool exitFlag)
{
    if (exitFlag)
        ThreadFlags |= SF_THREAD_EXIT;
    else
        ThreadFlags &= (UInt32)~SF_THREAD_EXIT;
}

bool Thread::IsFinished() const
{
    return (ThreadFlags & SF_THREAD_FINISHED) != 0;
}

bool Thread::IsSuspended() const
{
    return SuspendCount > 0;
}

Thread::ThreadState Thread::GetThreadState() const
{
    if (IsSuspended())
        return Suspended;
    if (ThreadFlags & SF_THREAD_STARTED)
        return Running;
    return NotRunning;
}

int Thread::GetOSPriority(ThreadPriority p)
{
    switch (p)
    {
    case Thread::CriticalPriority:    return THREAD_PRIORITY_TIME_CRITICAL;
    case Thread::HighestPriority:     return THREAD_PRIORITY_HIGHEST;
    case Thread::AboveNormalPriority: return THREAD_PRIORITY_ABOVE_NORMAL;
    case Thread::NormalPriority:      return THREAD_PRIORITY_NORMAL;
    case Thread::BelowNormalPriority: return THREAD_PRIORITY_BELOW_NORMAL;
    case Thread::LowestPriority:      return THREAD_PRIORITY_LOWEST;
    case Thread::IdlePriority:        return THREAD_PRIORITY_IDLE;
    }
    return THREAD_PRIORITY_NORMAL;
}

}  // namespace Scaleform

// Optional callback every Scaleform thread runs on startup, before its Run() (not in the SDK; null unless the game
// sets it).
extern void (*DAT_143b15f88)();

namespace Scaleform {

// MS2-FUNCTIONAL: the exe's frame is 0x10 larger with two more IP-to-state entries (try layout not reproduced)
unsigned WINAPI Thread_Win32StartFn(void* handle)
{
    Thread* thread = (Thread*)handle;
    if (thread->Processor != -1)
        ::SetThreadAffinityMask(GetCurrentThread(), (DWORD)thread->Processor);
    ::SetThreadPriority(GetCurrentThread(), Thread::GetOSPriority(thread->Priority));
    thread->IdValue = (ThreadId)(UPInt)::GetCurrentThreadId();

    // MS2 addition: the start hook and the thread body run under a catch-all (in a library built without unwind
    // semantics, so cl warns C4530); an escaping exception just ends the thread
    unsigned result;
#pragma warning(suppress : 4530)
    try
    {
        if (DAT_143b15f88)
            DAT_143b15f88();
        result = thread->PRun();
    }
    catch (...)
    {
    }
    thread->FinishAndRelease();
    ThreadList::RemoveRunningThread(thread);
    return result;
}

bool Thread::Start(ThreadState initialState)
{
    if (initialState == NotRunning)
        return 0;
    if ((GetThreadState() != NotRunning) && !Wait())
        return 0;

    CleanupSystemThread();
    // the running thread holds a reference until FinishAndRelease
    AddRef();
    ThreadList::AddRunningThread(this);

    ExitCode = 0;
    SuspendCount = 0;
    ThreadFlags = (initialState == Running) ? 0 : SF_THREAD_START_SUSPENDED;
    ThreadHandle = (HANDLE)_beginthreadex(0, (unsigned)StackSize, Thread_Win32StartFn, this, 0, (unsigned*)&IdValue);
    if (ThreadHandle == 0)
    {
        ThreadFlags = 0;
        Release();
        ThreadList::RemoveRunningThread(this);
        return 0;
    }
    return 1;
}

bool Thread::Suspend()
{
    if (!(ThreadFlags & SF_THREAD_STARTED))
        return 0;
    if (::SuspendThread(ThreadHandle) != 0xFFFFFFFF)
    {
        SuspendCount++;
        return 1;
    }
    return 0;
}

bool Thread::Resume()
{
    if (!(ThreadFlags & SF_THREAD_STARTED))
        return 0;
    SInt32 oldCount = SuspendCount.ExchangeAdd_Acquire(-1);
    if (oldCount >= 1)
    {
        if (oldCount == 1)
        {
            if (::ResumeThread(ThreadHandle) != 0xFFFFFFFF)
                return 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void Thread::Exit(int exitCode)
{
    OnExit();
    FinishAndRelease();
    ThreadList::RemoveRunningThread(this);
    _endthreadex((unsigned)exitCode);
}

void Thread::CleanupSystemThread()
{
    if (ThreadHandle != 0)
    {
        ::CloseHandle(ThreadHandle);
        ThreadHandle = 0;
    }
}

bool Thread::Sleep(unsigned secs)
{
    return MSleep(secs * 1000);
}

bool Thread::MSleep(unsigned msecs)
{
    ::Sleep(msecs);
    return 1;
}

// The exe names its threads for the debugger even in this build (the MSVC 0x406D1388 exception).
void Thread::SetThreadName(const char* name)
{
    struct ThreadNameInfo
    {
        DWORD  dwType;
        LPCSTR szName;
        DWORD  dwThreadID;
        DWORD  dwFlags;
    };
    ThreadNameInfo info;
    info.dwType = 0x1000;
    info.szName = name;
    info.dwThreadID = (DWORD)(UPInt)GetThreadId();
    info.dwFlags = 0;
    __try
    {
        RaiseException(0x406D1388, 0, sizeof(info) / sizeof(DWORD), (const ULONG_PTR*)&info);
    }
    __except (GetExceptionCode() == 0x406D1388 ? EXCEPTION_CONTINUE_EXECUTION : EXCEPTION_EXECUTE_HANDLER)
    {
    }
}

int Thread::GetCPUCount()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return (int)sysInfo.dwNumberOfProcessors;
}

ThreadId GetCurrentThreadId()
{
    return (ThreadId)(UPInt)::GetCurrentThreadId();
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??$Add@PEAVThread@Scaleform@@@?$HashSetBase@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@U342@U?$AllocatorGH@PEAVThread@Scaleform@@$01@2@V?$HashsetCachedEntry@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@@2@@Scaleform@@QEAAXPEAXAEBQEAVThread@1@@Z 0x14258a0c0
// MS2-PIN: ??$add@PEAVThread@Scaleform@@@?$HashSetBase@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@U342@U?$AllocatorGH@PEAVThread@Scaleform@@$01@2@V?$HashsetCachedEntry@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@@2@@Scaleform@@AEAAXPEAXAEBQEAVThread@1@_K@Z 0x14258a210
// MS2-PIN: ??0Mutex@Scaleform@@QEAA@_N0@Z 0x14258a350
// MS2-PIN: ??0MutexImpl@Scaleform@@QEAA@PEAVMutex@1@_N@Z 0x14258a430
// MS2-PIN: ??0Thread@Scaleform@@QEAA@AEBUCreateParams@01@@Z 0x14258a490
// MS2-PIN: ??0Thread@Scaleform@@QEAA@P6AHPEAV01@PEAX@Z1_KHW4ThreadState@01@@Z 0x14258a510
// MS2-PIN: ??0Thread@Scaleform@@QEAA@_KH@Z 0x14258a5b0
// MS2-PIN: ??0WaitCondition@Scaleform@@QEAA@XZ 0x14258a620
// MS2-PIN: ??0WaitConditionImpl@Scaleform@@QEAA@XZ 0x14258a690
// MS2-PIN: ??1?$HashSetBase@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@U342@U?$AllocatorGH@PEAVThread@Scaleform@@$01@2@V?$HashsetCachedEntry@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@@2@@Scaleform@@QEAA@XZ 0x14258a6c0
// MS2-PIN: ??1Mutex@Scaleform@@UEAA@XZ 0x14258a720
// MS2-PIN: ??1MutexImpl@Scaleform@@QEAA@XZ 0x14258a790
// MS2-PIN: ??1Thread@Scaleform@@UEAA@XZ 0x14258a7c0
// MS2-PIN: ??1WaitCondition@Scaleform@@QEAA@XZ 0x14258a810
// MS2-PIN: ??1WaitConditionImpl@Scaleform@@QEAA@XZ 0x14258a8a0
// MS2-PIN: ??_GMutex_AreadyLockedAcquireInterface@Scaleform@@UEAAPEAXI@Z 0x14258a990
// MS2-PIN: ??_GThread@Scaleform@@UEAAPEAXI@Z 0x14258a9c0
// MS2-PIN: ?AddRunningThread@ThreadList@Scaleform@@SAXPEAVThread@2@@Z 0x14258aa70
// MS2-PIN: ?CanAcquire@Mutex@Scaleform@@UEAA_NXZ 0x14258abf0
// MS2-PIN: ?CleanupSystemThread@Thread@Scaleform@@IEAAXXZ 0x14258ac70
// MS2-PIN: ?DoLock@Mutex@Scaleform@@QEAAXXZ 0x14258aca0
// MS2-PIN: ?DoLock@MutexImpl@Scaleform@@QEAAXXZ 0x14258acd0
// MS2-PIN: ?Exit@Thread@Scaleform@@UEAAXH@Z 0x14258ad00
// MS2-PIN: ?FinishAllThreads@Thread@Scaleform@@SAXXZ 0x14258ad40
// MS2-PIN: ?FinishAndRelease@Thread@Scaleform@@IEAAXXZ 0x14258ae30
// MS2-PIN: ?GetAcquireInterface@Mutex@Scaleform@@UEAAPEAVAcquireInterface@2@XZ 0x14258aec0
// MS2-PIN: ?GetAcquireInterface@MutexImpl@Scaleform@@QEAAPEAVAcquireInterface@2@PEAVMutex@2@@Z 0x14258af20
// MS2-PIN: ?GetCPUCount@Thread@Scaleform@@SAHXZ 0x14258afa0
// MS2-PIN: ?GetCurrentThreadId@Scaleform@@YAPEAXXZ 0x14258afc0
// MS2-PIN: ?GetNewEvent@WaitConditionImpl@Scaleform@@AEAAPEAUEventPoolEntry@12@XZ 0x14258aff0
// MS2-PIN: ?GetOSPriority@Thread@Scaleform@@SAHW4ThreadPriority@12@@Z 0x14258b060
// MS2-PIN: ?IsLockedByAnotherThread@Mutex@Scaleform@@QEAA_NXZ 0x14258b140
// MS2-PIN: ?IsLockedByAnotherThread@MutexImpl@Scaleform@@QEAA_NPEAVMutex@2@@Z 0x14258b1a0
// MS2-PIN: ?MSleep@Thread@Scaleform@@SA_NI@Z 0x14258b240
// MS2-PIN: ?Notify@WaitCondition@Scaleform@@QEAAXXZ 0x14258b260
// MS2-PIN: ?Notify@WaitConditionImpl@Scaleform@@QEAAXXZ 0x14258b2b0
// MS2-PIN: ?NotifyAll@WaitCondition@Scaleform@@QEAAXXZ 0x14258b300
// MS2-PIN: ?NotifyAll@WaitConditionImpl@Scaleform@@QEAAXXZ 0x14258b390
// MS2-PIN: ?PRun@Thread@Scaleform@@IEAAHXZ 0x14258b430
// MS2-PIN: ?ReleaseEvent@WaitConditionImpl@Scaleform@@AEAAXPEAUEventPoolEntry@12@@Z 0x14258b570
// MS2-PIN: ?RemoveRunningThread@ThreadList@Scaleform@@SAXPEAVThread@2@@Z 0x14258b5b0
// MS2-PIN: ?Resume@Thread@Scaleform@@QEAA_NXZ 0x14258b720
// MS2-PIN: ?SetThreadName@Thread@Scaleform@@UEAAXPEBD@Z 0x14258b7c0
// MS2-PIN: ?Sleep@Thread@Scaleform@@SA_NI@Z 0x14258b800
// MS2-PIN: ?Start@Thread@Scaleform@@UEAA_NW4ThreadState@12@@Z 0x14258b820
// MS2-PIN: ?Suspend@Thread@Scaleform@@QEAA_NXZ 0x14258b910
// MS2-PIN: ?Thread_Win32StartFn@Scaleform@@YAIPEAX@Z 0x14258b950
// MS2-PIN: ?TryAcquire@Mutex@Scaleform@@UEAA_NXZ 0x14258ba50
// MS2-PIN: ?TryAcquireCancel@Mutex@Scaleform@@UEAA_NXZ 0x14258bab0
// MS2-PIN: ?TryLock@Mutex@Scaleform@@QEAA_NXZ 0x14258bb00
// MS2-PIN: ?TryLock@MutexImpl@Scaleform@@QEAA_NXZ 0x14258bb40
// MS2-PIN: ?Unlock@Mutex@Scaleform@@QEAAXXZ 0x14258bb70
// MS2-PIN: ?Unlock@MutexImpl@Scaleform@@QEAAXPEAVMutex@2@@Z 0x14258bb80
// MS2-PIN: ?Wait@WaitCondition@Scaleform@@QEAA_NPEAVMutex@2@I@Z 0x14258bc20
// MS2-PIN: ?Wait@WaitConditionImpl@Scaleform@@QEAA_NPEAVMutex@2@I@Z 0x14258bc30
// MS2-PIN: ?setRawCapacity@?$HashSetBase@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@U342@U?$AllocatorGH@PEAVThread@Scaleform@@$01@2@V?$HashsetCachedEntry@PEAVThread@Scaleform@@UThreadHashOp@ThreadList@2@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14258be40
// MS2-PIN: ??_7Mutex@Scaleform@@6BWaitable@1@@ 0x1431842f8
// MS2-PIN: ??_7Mutex@Scaleform@@6BAcquireInterface@1@@ 0x143184310
// MS2-PIN: ??_7Thread@Scaleform@@6BWaitable@1@@ 0x143184338
// MS2-PIN: ??_7Thread@Scaleform@@6BAcquireInterface@1@@ 0x143184378
// MS2-PIN: ??_7Mutex_AreadyLockedAcquireInterface@Scaleform@@6B@ 0x1431843a0
