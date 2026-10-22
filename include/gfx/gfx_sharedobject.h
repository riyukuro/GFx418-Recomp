// Recovered Scaleform 4.1.18 GFx: the receiver of a shared object's stored data. SharedObjectManagerBase::
// LoadSharedObject replays the saved tree as visits (vtable slots from the AS2 and AS3 loaders in the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder virtuals.
#ifndef MS2_SF_GFX_SHAREDOBJECT_H
#define MS2_SF_GFX_SHAREDOBJECT_H

#include "gfx_value.h"
#include "../kernel/sf_string.h"
#include "gfx_state.h"

namespace Scaleform { namespace GFx {

class SharedObjectVisitor : public RefCountBaseNTS<SharedObjectVisitor, Stat_Default_Mem>
{
public:
    virtual void Begin() = 0;                                                           // slot 1
    virtual void PushObject(const String& name) = 0;                                    // slot 2
    virtual void PushArray(const String& name) = 0;                                     // slot 3
    virtual void AddProperty(const String& name, const String& value, Value::ValueType type) = 0;  // slot 4
    virtual void PopObject() = 0;                                                       // slot 5
    virtual void PopArray() = 0;                                                        // slot 6
    virtual void End() = 0;                                                             // slot 7
};

// (appended, sfr15) the SharedObject state: loads a stored shared object and hands out its writer.
class SharedObjectManagerBase : public State
{
public:
    SharedObjectManagerBase() : State(State_SharedObject) {}

    // Replays the stored data of name into psobj; false if there is none.
    virtual bool LoadSharedObject(const String& name, const String& localPath, SharedObjectVisitor* psobj,
                                  FileOpenerBase* pfileOpener) = 0;                    // slot 1
    // A new visitor that stores what it is given under name (the caller owns the reference).
    virtual SharedObjectVisitor* CreateWriter(const String& name, const String& localPath,
                                              FileOpenerBase* pfileOpener) = 0;          // slot 2
};

}} // namespace Scaleform::GFx

#endif // MS2_SF_GFX_SHAREDOBJECT_H
