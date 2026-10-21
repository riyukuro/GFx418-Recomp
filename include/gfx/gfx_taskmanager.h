// Recovered Scaleform 4.1.18 GFx: tasks and the task manager state (loader threads).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_TASKMANAGER_H
#define MS2_SF_GFX_TASKMANAGER_H

#include "gfx_state.h"

namespace Scaleform { namespace GFx {

// Unit of work run by a TaskManager (0x18 bytes, vftable 0x143188d98).
class Task : public RefCountBase<Task, Stat_Default_Mem>
{
public:
    // High word: kind of work, so a manager can route I/O and computation to different threads.
    enum TaskType
    {
        Type_Computation = 0x00010000,
        Type_IO          = 0x00020000,
        Type_Mask        = 0x00FF0000
    };

    enum TaskId
    {
        Id_Unknown        = Type_Computation | 1,
        Id_MovieDecoding  = Type_Computation | 2,
        Id_MovieDataLoad  = Type_IO | 1,
        Id_MovieImageLoad = Type_IO | 2,
        Id_MovieBind      = Type_IO | 3
    };

    enum TaskState
    {
        State_Idle,
        State_Pending,
        State_Running,
        State_Abandoned,
        State_Finished
    };

protected:
    TaskId             ThisTaskId;   // +0x10
    volatile TaskState CurrentState; // +0x14

public:
    Task(TaskId id = Id_Unknown) : ThisTaskId(id), CurrentState(State_Idle) {}
    virtual ~Task() {}

    TaskId    GetTaskId() const    { return ThisTaskId; }
    TaskType  GetTaskType() const  { return (TaskType)(ThisTaskId & Type_Mask); }
    TaskState GetTaskState() const { return CurrentState; }

    virtual void Execute() = 0;
    // Called when the manager drops the task; started says whether Execute already began.
    virtual void OnAbandon(bool started) { SF_UNUSED(started); }
};

// Runs tasks for the loader (state 0x14).
class TaskManager : public State
{
public:
    TaskManager() : State(State_TaskManager) {}
    virtual ~TaskManager() {}

    virtual bool AddTask(Task* ptask)     = 0;
    virtual bool AbandonTask(Task* ptask) = 0;
    virtual void RequestShutdown()        = 0;
};

}} // namespace Scaleform::GFx

#endif
