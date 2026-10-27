// Recovered Scaleform GFx 4.1.18: thread primitives (threads enabled, Win32 implementation). Waitable objects keep a
// shared, ref-counted handler array that waiters hook into; Mutex/Event/Semaphore/Thread are Waitable and expose the
// two-stage AcquireInterface (TryAcquire, then Commit or Cancel) used by the multi-object waits.
#ifndef MS2_SF_KERNEL_THREADS_H
#define MS2_SF_KERNEL_THREADS_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"

#define SF_WAIT_INFINITE 0xFFFFFFFF

namespace Scaleform {

class Waitable;
class AcquireInterface;
class Mutex;
class WaitCondition;
class Event;
class Semaphore;

class AcquireInterface
{
public:
    SF_EXPORT virtual ~AcquireInterface() { }
    virtual bool CanAcquire();
    virtual bool TryAcquire();
    virtual bool TryAcquireCommit();
    virtual bool TryAcquireCancel();

    static bool AcquireMultipleObjects(Waitable** waitList, unsigned waitCount, unsigned delay = SF_WAIT_INFINITE);
    static int  AcquireOneOfMultipleObjects(Waitable** waitList, unsigned waitCount, unsigned delay = SF_WAIT_INFINITE);
};

class DefaultAcquireInterface : public AcquireInterface
{
public:
    SF_EXPORT virtual ~DefaultAcquireInterface() { }
    static DefaultAcquireInterface* GetDefaultAcquireInterface();
};

class Waitable : public RefCountBase<Waitable, Stat_Default_Mem>
{
public:
    typedef void (*WaitHandler)(void* data);

protected:
    class HandlerStruct
    {
    public:
        WaitHandler Handler;
        void*       pUserData;
        HandlerStruct() { Handler = 0; pUserData = 0; }
        HandlerStruct(WaitHandler h, void* d) { Handler = h; pUserData = d; }
        HandlerStruct(const HandlerStruct& s) { Handler = s.Handler; pUserData = s.pUserData; }
        HandlerStruct& operator=(const HandlerStruct& s)
        {
            Handler = s.Handler;
            pUserData = s.pUserData;
            return *this;
        }
        bool operator==(const HandlerStruct& s) { return Handler == s.Handler && pUserData == s.pUserData; }
    };

    // shared with the CallableHandlers snapshots, so a handler list survives the Waitable while being called
    struct HandlerArray : public NewOverrideBase<Stat_Default_Mem>
    {
        typedef ArrayConstPolicy<0, 16, true>                          SizePolicyType;
        typedef Array<HandlerStruct, Stat_Default_Mem, SizePolicyType> HandlerArrayType;

        AtomicInt<SInt32> RefCount;
        HandlerArrayType  Handlers;
        Lock              HandlersLock;

        HandlerArray() { RefCount.Value = 1; }
        void AddRef() { RefCount++; }
        void Release();
        void CallWaitHandlers();
    };

    HandlerArray* pHandlers;

public:
    Waitable(bool enable);
    virtual ~Waitable();

    void CallWaitHandlers();

    class CallableHandlers
    {
        friend class Waitable;
        Ptr<HandlerArray> pArray;
    public:
        CallableHandlers() { }
        inline void CallWaitHandlers() { if (pArray) pArray->CallWaitHandlers(); }
    };
    inline void GetCallableHandlers(CallableHandlers* h) { if (pHandlers) h->pArray = pHandlers; }

    bool AddWaitHandler(WaitHandler handler, void* data);
    bool RemoveWaitHandler(WaitHandler handler, void* data);
    bool Wait(unsigned delay = SF_WAIT_INFINITE);
    bool Acquire(unsigned delay = SF_WAIT_INFINITE);

    virtual bool              IsSignaled() const;
    virtual AcquireInterface* GetAcquireInterface();
};

class MutexImpl;
class Mutex : public Waitable, public AcquireInterface
{
    friend class WaitConditionImpl;
    friend class MutexImpl;
    MutexImpl* pImpl;
public:
    SF_EXPORT Mutex(bool recursive = 1, bool multiWait = 0);
    ~Mutex();

    void DoLock();
    bool TryLock();
    void Unlock();
    bool IsLockedByAnotherThread();

    virtual bool              IsSignaled() const;
    virtual AcquireInterface* GetAcquireInterface();
    virtual bool              CanAcquire();
    virtual bool              TryAcquire();
    virtual bool              TryAcquireCommit();
    virtual bool              TryAcquireCancel();

    class Locker
    {
    public:
        Mutex* pMutex;
        Locker(Mutex* m) { pMutex = m; pMutex->DoLock(); }
        ~Locker() { pMutex->Unlock(); }
    };
};

class WaitConditionImpl;
class WaitCondition
{
    friend class WaitConditionImpl;
    WaitConditionImpl* pImpl;
public:
    WaitCondition();
    ~WaitCondition();
    bool Wait(Mutex* mutex, unsigned delay = SF_WAIT_INFINITE);
    void Notify();
    void NotifyAll();
};

class Event : public Waitable, public AcquireInterface
{
    volatile bool State;
    volatile bool Temporary;    // set by PulseEvent: the next acquirer clears it
    mutable Mutex StateMutex;
    WaitCondition StateWaitCondition;
public:
    SF_EXPORT Event(bool setInitially = 0, bool multiWait = 0);
    ~Event();

    bool Wait(unsigned delay = SF_WAIT_INFINITE);
    void SetEvent();
    void ResetEvent();
    void PulseEvent();

    virtual bool              IsSignaled() const;
    virtual AcquireInterface* GetAcquireInterface();
    virtual bool              CanAcquire();
    virtual bool              TryAcquire();
    virtual bool              TryAcquireCommit();
    virtual bool              TryAcquireCancel();
};

class Semaphore : public Waitable, public AcquireInterface
{
protected:
    int           MaxValue;
    volatile int  Value;
    mutable Mutex ValueMutex;
    WaitCondition ValueWaitCondition;
public:
    SF_EXPORT Semaphore(int maxValue = 1, bool multiWait = 0);
    ~Semaphore();

    int GetMaxValue() const;
    int GetValue() const;
    int GetAvailable() const;

    bool ObtainSemaphore(int count = 1, unsigned delay = SF_WAIT_INFINITE);
    bool ReleaseSemaphore(int count = 1);

    int operator++(int);
    int operator--(int);
    int operator+=(int count);
    int operator-=(int count);

    Waitable* CreateWaitableIncrement(int count);

    virtual bool              CanAcquire();
    virtual bool              TryAcquire();
    virtual bool              TryAcquireCommit();
    virtual bool              TryAcquireCancel();
    virtual bool              IsSignaled() const;
    virtual AcquireInterface* GetAcquireInterface();

    class Locker
    {
    public:
        Semaphore* pSemaphore;
        int        Count;
        Locker(Semaphore* s, int count = 1) { pSemaphore = s; Count = count; pSemaphore->ObtainSemaphore(count); }
        ~Locker() { pSemaphore->ReleaseSemaphore(Count); }
    };
};

typedef void* ThreadId;

#define SF_THREAD_STARTED         0x01
#define SF_THREAD_FINISHED        0x02
#define SF_THREAD_START_SUSPENDED 0x08
#define SF_THREAD_EXIT            0x10

// Waitable first: it carries the reference count.
class Thread : public Waitable, public AcquireInterface
{
public:
    typedef int (*ThreadFn)(Thread* thread, void* h);
    ThreadFn ThreadFunction;
    void*    UserHandle;

    enum ThreadState { NotRunning = 0, Running = 1, Suspended = 2 };
    enum ThreadPriority
    {
        CriticalPriority,
        HighestPriority,
        AboveNormalPriority,
        NormalPriority,
        BelowNormalPriority,
        LowestPriority,
        IdlePriority,
    };

    struct CreateParams
    {
        CreateParams(ThreadFn func = 0, void* hand = 0, UPInt ssize = 128 * 1024, int proc = -1,
                     ThreadState state = NotRunning, ThreadPriority prior = NormalPriority)
            : threadFunction(func), userHandle(hand), stackSize(ssize), processor(proc), initialState(state),
              priority(prior) { }
        ThreadFn       threadFunction;
        void*          userHandle;
        UPInt          stackSize;
        int            processor;
        ThreadState    initialState;
        ThreadPriority priority;
    };

    // 4.1.18 default stack: 1 MB (the exe's ??_FThread closure 0x1418067c0 passes 0x100000)
    SF_EXPORT Thread(UPInt stackSize = 1024 * 1024, int processor = -1);
    Thread(ThreadFn threadFunction, void* userHandle = 0, UPInt stackSize = 128 * 1024, int processor = -1,
           ThreadState initialState = NotRunning);
    explicit Thread(const CreateParams& params);
    virtual ~Thread();

    static void SF_CDECL FinishAllThreads();

    virtual int  Run();
    virtual void OnExit();
    virtual bool Start(ThreadState initialState = Running);
    virtual void Exit(int exitCode = 0);
    bool Suspend();
    bool Resume();

    bool        GetExitFlag() const;
    void        SetExitFlag(bool exitFlag);
    bool        IsFinished() const;
    bool        IsSuspended() const;
    ThreadState GetThreadState() const;

    static int GetCPUCount();
    SF_INLINE int GetExitCode() const { return ExitCode; }
    void*    GetOSHandle() const { return ThreadHandle; }
    ThreadId GetThreadId() const { return IdValue; }

    static int  GetOSPriority(ThreadPriority);
    static bool Sleep(unsigned secs);
    static bool MSleep(unsigned msecs);

    virtual bool              IsSignaled() const { return (ThreadFlags & SF_THREAD_FINISHED) != 0; }
    virtual AcquireInterface* GetAcquireInterface() { return this; }
    virtual bool              CanAcquire() { return IsSignaled(); }
    virtual bool              TryAcquire() { return IsSignaled(); }
    virtual void              SetThreadName(const char* name);

private:
    friend unsigned WINAPI Thread_Win32StartFn(void* thread);

protected:
    AtomicInt<UInt32> ThreadFlags;
    AtomicInt<SInt32> SuspendCount;
    UPInt             StackSize;
    int               Processor;
    ThreadPriority    Priority;
    void*             ThreadHandle;
    volatile ThreadId IdValue;
    void CleanupSystemThread();
    int  ExitCode;

    int  PRun();
    void FinishAndRelease();
    void Init(const CreateParams& params);
    Thread(const Thread&) : Waitable(1) { }
};

ThreadId GetCurrentThreadId();

}  // namespace Scaleform

#endif
