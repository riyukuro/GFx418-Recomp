// Recovered Scaleform 4.1.18 GFx AS2: AsBroadcaster::BroadcastMessage as the exe inlines it in its callers (a local
// callback on the stack and a BroadcastMessageWithCallback call). Shared header of the src/ms2/scaleform units (sfr
// lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BROADCASTLOCAL_H
#define MS2_SF_GFX_AS2_BROADCASTLOCAL_H

#include "as2_builtinobjects.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The broadcaster's local callback: calls each listener's method with the arguments already on the stack (vftable
// 0x143221850; Invoke is in sfr_as2_04o, which has its own copy of the class).
class SetFocusInvokeCallback : public AsBroadcaster::InvokeCallback
{
public:
    int NArgs;
    int FirstArgBottomIndex;

    SetFocusInvokeCallback(int nargs, int firstArg) : NArgs(nargs), FirstArgBottomIndex(firstArg) {}

    virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method);
};

// AsBroadcaster::BroadcastMessage (0x142932180) inlined: false without a broadcaster.
static SF_FORCEINLINE bool BroadcastMessageLocal(Environment* penv, ObjectInterface* pthis, const ASString& eventName,
                                                 int nArgs, int firstArgBottomIndex)
{
    if (!pthis)
        return false;
    SetFocusInvokeCallback callback(nArgs, firstArgBottomIndex);
    AsBroadcaster::BroadcastMessageWithCallback(penv, pthis, eventName, &callback);
    return true;
}

}}} // namespace Scaleform::GFx::AS2

#endif
