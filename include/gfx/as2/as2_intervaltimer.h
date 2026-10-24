// Recovered Scaleform GFx 4.1.18 AS2: IntervalTimer, the timer behind setInterval / setTimeout. 0x80 bytes,
// vftable 0x14321bd70 (slots: deleting dtor 0x14292b710, then the ASIntervalTimerIntf ones).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_AS2_INTERVALTIMER_H
#define MS2_SF_GFX_AS2_INTERVALTIMER_H

#include "as2_action.h"
#include "../gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

class IntervalTimer : public ASIntervalTimerIntf
{
public:
    FunctionRef              Function;    // +0x10 the callback (setInterval(func, ...))
    Ptr<Object>              pObject;     // +0x28 the object whose method is called (setInterval(obj, "name", ...))
    WeakPtr<InteractiveObject> pTarget;   // +0x30 the character the timer was made from
    ASString                 MethodName;  // +0x38
    Array<Value, 2>          Params;      // +0x40 the extra arguments
    UInt64                   Interval;    // +0x58
    UInt64                   InvokeTime;  // +0x60
    int                      Id;          // +0x68
    Ptr<CharacterHandle>     Character;   // +0x70
    bool                     Active;      // +0x78
    bool                     Unrecovered_79;

    IntervalTimer(const FunctionRefBase& fn, ASStringContext* psc);     // exe 0x14291cf60
    IntervalTimer(InteractiveObject* ptarget, const ASString& method);  // exe 0x14291d030
    virtual ~IntervalTimer();                                           // exe 0x1429259d0

    virtual void   Start(MovieImpl* proot);
    virtual bool   Invoke(MovieImpl* proot, float frameTime);
    virtual bool   IsActive() const;
    virtual void   Clear();
    virtual bool   ClearFor(MovieImpl* proot, MovieDefImpl* pdefImpl);
    virtual UInt64 GetNextInvokeTime() const;
    virtual void   SetId(int id);
    virtual int    GetId() const;

    // setInterval(obj, "method", ...): inlined at its one use, no exe copy.
    IntervalTimer(Object* pobj, const ASString& method)
        : pObject(pobj), MethodName(method), Interval(0), InvokeTime(0), Id(0), Active(true), Unrecovered_79(false)
    {
    }

private:
    // setInterval / setTimeout: the callback (a function, or an object or character with a method name), the
    // interval in ms and the extra arguments; the result is the timer id (exe 0x14297f3d0).
    static void Set(const FnCall& fn, bool isTimeout);
};
static_assert(sizeof(IntervalTimer) == 0x80, "IntervalTimer size");

}}} // namespace Scaleform::GFx::AS2

#endif
