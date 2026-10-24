// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TaskManager (the threaded task
// manager: a thread per task, or a pool of worker threads per task type).
// Fifth source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258f330-0x142591050 .text$mn

// The thread primitives come from the kernel header tree, so it goes first.
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "../include/gfx/gfx_taskmanager.h"

namespace Scaleform { namespace GFx {

// The tasks a manager has started, so they can be told to abandon; guarded by the manager's task mutex.
class TasksContainer
{
public:
    TasksContainer(Mutex* ptaskMutex) : pTasksMutex(ptaskMutex) {}
    ~TasksContainer() { AbandonAllTask(); }

    void AddTask(Task* ptask);
    bool RemoveTask(Task* ptask);
    bool AbandonTask(Task* ptask);
    void AbandonAllTask();

private:
    Mutex*       pTasksMutex; // +0
    Array<Task*> Tasks;       // +8
};

class TaskThreadPool;

// The part of ThreadedTaskManager the task threads hold on to, so a running task can keep its manager alive
// (0x60 bytes, vftable 0x143184af0).
class ThreadedTaskManagerImpl : public RefCountBase<ThreadedTaskManagerImpl, Stat_Default_Mem>
{
public:
    ThreadedTaskManagerImpl();
    ~ThreadedTaskManagerImpl();

    bool AddWorkerThreads(unsigned taskMask, unsigned count, UPInt stackSize, int processor = -1);

    TasksContainer* GetRunningTasks() { return &RunningTasks; }
    TaskThreadPool* GetThreadPool() { return pThreadPool; }

    bool AbandonTask(Task* ptask);
    void RequestShutdown();

private:
    friend class TaskThreadPool;

    Mutex           TasksMutex;   // +0x10
    TasksContainer  RunningTasks; // +0x38
    TaskThreadPool* pThreadPool;  // +0x58
};

// Runs one task and goes away (0x70 bytes, vftables 0x143184af8 / 0x143184b38).
class TaskThread : public Thread
{
public:
    TaskThread(Task* ptask, ThreadedTaskManagerImpl* ptm, UPInt stackSize = 128 * 1024, int processor = -1)
        : Thread(stackSize, processor), pTask(ptask), pTaskManager(ptm)
    {
    }
    ~TaskThread();

    virtual int Run();

protected:
    Ptr<Task>                    pTask;        // +0x60
    Ptr<ThreadedTaskManagerImpl> pTaskManager; // +0x68
};

// A pool worker: takes the tasks of its type from the pool's queue until shutdown (0x78 bytes,
// vftables 0x143184b60 / 0x143184ba0).
class TaskThreadInPool : public TaskThread
{
public:
    TaskThreadInPool(unsigned taskMask, ThreadedTaskManagerImpl* ptm, UPInt stackSize = 128 * 1024,
                     int processor = -1)
        : TaskThread(0, ptm, stackSize, processor), TaskMask(taskMask)
    {
    }
    ~TaskThreadInPool() {}

    bool SetTask(Task* ptask);
    virtual int Run();

    unsigned GetTaskType() const { return TaskMask; }

private:
    unsigned TaskMask; // +0x70
};

// The worker threads and the queue of tasks waiting for them (0x70 bytes).
class TaskThreadPool : public NewOverrideBase<Stat_Default_Mem>
{
public:
    TaskThreadPool(ThreadedTaskManagerImpl* ptm);
    ~TaskThreadPool();

    bool AddTask(Task* ptask);
    bool AbandonTask(Task* ptask);
    bool AddThreads(unsigned taskMask, unsigned count, UPInt stackSize, int processor = -1);
    bool RemoveThread(TaskThread* pthread);

    // The next queued task of a type in taskMask, AddRef'ed; waits while there is none, 0 after shutdown.
    Task* GetTaskAddRef(unsigned taskMask);
    // Stops taking tasks and abandons the queued ones.
    void RequestShutdown();

private:
    Task* FindTaskByMask(unsigned taskMask);

    Array<Ptr<Task> >        TasksQueue;        // +0
    Array<TaskThreadInPool*> Threads;           // +0x18
    Lock                     ThreadsLock;       // +0x30
    WaitCondition            TaskWaitCondition; // +0x58
    volatile bool            ShutdownRequested; // +0x60
    ThreadedTaskManagerImpl* pTaskManager;      // +0x68
};

//
// TasksContainer
//

// @0x1425900d0
void TasksContainer::AddTask(Task* ptask)
{
    if (!ptask)
        return;
    Mutex::Locker guard(pTasksMutex);
    Tasks.PushBack(ptask);
}

// @0x1425908e0
bool TasksContainer::RemoveTask(Task* ptask)
{
    if (!ptask)
        return false;
    Mutex::Locker guard(pTasksMutex);
    for (unsigned i = 0; i < Tasks.GetSize(); i++)
    {
        if (Tasks[i] == ptask)
        {
            Tasks.RemoveAt(i);
            return true;
        }
    }
    return false;
}

// @0x14258fd70
bool TasksContainer::AbandonTask(Task* ptask)
{
    if (!ptask)
        return false;
    Mutex::Locker guard(pTasksMutex);
    for (unsigned i = 0; i < Tasks.GetSize(); i++)
    {
        if (Tasks[i] == ptask)
        {
            Tasks[i]->OnAbandon(true);
            return true;
        }
    }
    return false;
}

// @0x14258fc50
void TasksContainer::AbandonAllTask()
{
    Mutex::Locker guard(pTasksMutex);
    for (unsigned i = 0; i < Tasks.GetSize(); i++)
        Tasks[i]->OnAbandon(true);
}

//
// ThreadedTaskManagerImpl
//

// @0x14258f4c0
ThreadedTaskManagerImpl::ThreadedTaskManagerImpl() : RunningTasks(&TasksMutex), pThreadPool(0)
{
}

// @0x14258f7b0
ThreadedTaskManagerImpl::~ThreadedTaskManagerImpl()
{
    RunningTasks.AbandonAllTask();
    delete pThreadPool;
}

// @0x142590490
bool ThreadedTaskManagerImpl::AddWorkerThreads(unsigned taskMask, unsigned count, UPInt stackSize, int processor)
{
    if (!pThreadPool)
        pThreadPool = new TaskThreadPool(this);
    return pThreadPool->AddThreads(taskMask, count, stackSize, processor);
}

// @0x142590b70
void ThreadedTaskManagerImpl::RequestShutdown()
{
    RunningTasks.AbandonAllTask();
    if (pThreadPool)
        pThreadPool->RequestShutdown();
}

// Queued tasks are dropped from the pool; running ones are only told to abandon.
// @0x14258fee0
bool ThreadedTaskManagerImpl::AbandonTask(Task* ptask)
{
    if (pThreadPool)
        return pThreadPool->AbandonTask(ptask);
    return RunningTasks.AbandonTask(ptask);
}

//
// TaskThread, TaskThreadInPool
//

// @0x14258f5a0
TaskThread::~TaskThread()
{
    if (pTask)
    {
        pTask->OnAbandon(true);
        pTaskManager->GetRunningTasks()->RemoveTask(pTask);
    }
    TaskThreadPool* ppool = pTaskManager->GetThreadPool();
    if (ppool)
        ppool->RemoveThread(this);
}

// @0x142590e20
int TaskThread::Run()
{
    if (pTask)
    {
        pTask->Execute();
        pTaskManager->GetRunningTasks()->RemoveTask(pTask);
        pTask = 0;
    }
    return 1;
}

// @0x142591000
bool TaskThreadInPool::SetTask(Task* ptask)
{
    if (pTask)
        return false;
    pTask = ptask;
    return true;
}

// @0x142590e70
int TaskThreadInPool::Run()
{
    Ptr<Task> ptask;
    while ((ptask = *pTaskManager->GetThreadPool()->GetTaskAddRef(TaskMask)))
    {
        SetTask(ptask);
        TaskThread::Run();
        ptask = 0;
    }
    return 1;
}

//
// TaskThreadPool
//

// @0x14258f3a0
TaskThreadPool::TaskThreadPool(ThreadedTaskManagerImpl* ptm) : ShutdownRequested(false), pTaskManager(ptm)
{
}

// @0x14258f6d0
TaskThreadPool::~TaskThreadPool()
{
    RequestShutdown();
    for (unsigned i = 0; i < Threads.GetSize(); i++)
        Threads[i]->Wait();
}

// Queues ptask; false after shutdown or when no worker takes its type.
// @0x14258ffc0
bool TaskThreadPool::AddTask(Task* ptask)
{
    if (ShutdownRequested)
        return false;
    {
        Lock::Locker guard(&ThreadsLock);
        unsigned i;
        for (i = 0; i < Threads.GetSize(); i++)
        {
            if ((unsigned)ptask->GetTaskType() == Threads[i]->GetTaskType())
                break;
        }
        if (i == Threads.GetSize())
            return false;
    }
    Mutex::Locker guard(&pTaskManager->TasksMutex);
    TasksQueue.PushBack(ptask);
    TaskWaitCondition.NotifyAll();
    return true;
}

// @0x142590300
bool TaskThreadPool::AddThreads(unsigned taskMask, unsigned count, UPInt stackSize, int processor)
{
    if (ShutdownRequested)
        return false;
    Lock::Locker guard(&ThreadsLock);
    while (count-- > 0)
    {
        Ptr<TaskThreadInPool> pthread = *new TaskThreadInPool(taskMask, pTaskManager, stackSize, processor);
        pthread->Start();
        Threads.PushBack(pthread);
    }
    return true;
}

// @0x1425909d0
bool TaskThreadPool::RemoveThread(TaskThread* pthread)
{
    Lock::Locker guard(&ThreadsLock);
    for (unsigned i = 0; i < Threads.GetSize(); i++)
    {
        if (Threads[i] == pthread)
        {
            Threads.RemoveAt(i);
            return true;
        }
    }
    return false;
}

// @0x142590770
Task* TaskThreadPool::GetTaskAddRef(unsigned taskMask)
{
    if (ShutdownRequested)
        return 0;
    Mutex::Locker guard(&pTaskManager->TasksMutex);
    Task*         ptask = 0;
    while (!ShutdownRequested && (ptask = FindTaskByMask(taskMask)) == 0)
        TaskWaitCondition.Wait(&pTaskManager->TasksMutex);
    if (ptask)
        pTaskManager->GetRunningTasks()->AddTask(ptask);
    return ptask;
}

// @0x142590680
Task* TaskThreadPool::FindTaskByMask(unsigned taskMask)
{
    Task* ptask = 0;
    for (unsigned i = 0; i < TasksQueue.GetSize(); i++)
    {
        if (TasksQueue[i]->GetTaskType() & taskMask)
        {
            ptask = TasksQueue[i];
            ptask->AddRef();
            TasksQueue.RemoveAt(i);
            break;
        }
    }
    return ptask;
}

// @0x142590ab0
void TaskThreadPool::RequestShutdown()
{
    Mutex::Locker guard(&pTaskManager->TasksMutex);
    if (ShutdownRequested)
        return;
    ShutdownRequested = true;
    for (unsigned i = 0; i < TasksQueue.GetSize(); i++)
        TasksQueue[i]->OnAbandon(false);
    TasksQueue.Clear();
    TaskWaitCondition.NotifyAll();
}

// @0x14258fcc0
bool TaskThreadPool::AbandonTask(Task* ptask)
{
    if (!ptask)
        return false;
    Mutex::Locker guard(&pTaskManager->TasksMutex);
    for (unsigned i = 0; i < TasksQueue.GetSize(); i++)
    {
        if (TasksQueue[i] == ptask)
        {
            TasksQueue[i]->OnAbandon(false);
            TasksQueue.RemoveAt(i);
            return true;
        }
    }
    return pTaskManager->GetRunningTasks()->AbandonTask(ptask);
}

//
// ThreadedTaskManager
//

// @0x14258f400
ThreadedTaskManager::ThreadedTaskManager(UPInt stackSize) : ThreadStackSize(stackSize)
{
    pImpl = new ThreadedTaskManagerImpl;
}

// @0x14258f750
ThreadedTaskManager::~ThreadedTaskManager()
{
    if (pImpl)
    {
        pImpl->RequestShutdown();
        pImpl->Release();
    }
}

// Hands ptask to a pool worker of its type, or else starts a thread for it.
// @0x142590170
bool ThreadedTaskManager::AddTask(Task* ptask)
{
    if (!ptask)
        return false;
    TaskThreadPool* pthreadPool = pImpl->GetThreadPool();
    if (pthreadPool && pthreadPool->AddTask(ptask))
        return true;

    Ptr<TaskThread> ptaskThread = *new TaskThread(ptask, pImpl, ThreadStackSize);
    if (ptaskThread)
    {
        pImpl->GetRunningTasks()->AddTask(ptask);
        ptaskThread->Start();
        return true;
    }
    return false;
}

// @0x14258fe00
bool ThreadedTaskManager::AbandonTask(Task* ptask)
{
    return pImpl->AbandonTask(ptask);
}

// @0x142590480
bool ThreadedTaskManager::AddWorkerThreads(unsigned taskMask, unsigned count, UPInt stackSize, int processor)
{
    return pImpl->AddWorkerThreads(taskMask, count, stackSize, processor);
}

// @0x142590b40
void ThreadedTaskManager::RequestShutdown()
{
    pImpl->RequestShutdown();
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7TaskManager@GFx@Scaleform@@6B@ 0x143184aa8
// MS2-PIN: ??_7?$RefCountBase@VThreadedTaskManagerImpl@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143184ae8
// MS2-PIN: ??_7ThreadedTaskManager@GFx@Scaleform@@6B@ 0x143184ac8
// MS2-PIN: ??_7ThreadedTaskManagerImpl@GFx@Scaleform@@6B@ 0x143184af0
// MS2-PIN: ??_7TaskThread@GFx@Scaleform@@6BWaitable@2@@ 0x143184af8
// MS2-PIN: ??_7TaskThread@GFx@Scaleform@@6BAcquireInterface@2@@ 0x143184b38
// MS2-PIN: ??_7TaskThreadInPool@GFx@Scaleform@@6BWaitable@2@@ 0x143184b60
// MS2-PIN: ??_7TaskThreadInPool@GFx@Scaleform@@6BAcquireInterface@2@@ 0x143184ba0
// MS2-PIN: ??_G?$RefCountBase@VThreadedTaskManagerImpl@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14258f8c0
// MS2-PIN: ??_GTaskManager@GFx@Scaleform@@UEAAPEAXI@Z 0x14258f920
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAVTaskThreadInPool@GFx@Scaleform@@U?$AllocatorGH@PEAVTaskThreadInPool@GFx@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x142590c40
