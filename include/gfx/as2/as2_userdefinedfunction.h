// Recovered Scaleform GFx 4.1.18 AS2: the function object that GFx::Value::CreateFunction makes around a host
// FunctionHandler. 0x78 bytes (MovieRoot::CreateFunction 0x142936360 allocates 0x78 and fills +0x68/+0x70);
// vftable 0x143221ff8 (second one at +0x20: 0x143222080).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// (sfr24) sfr_as2_04 (complete) and sfr_as2_06 (Invoke / InvokeImpl only) still declare local copies of this
// class. A unit has to drop its local copy before it includes this header.
#ifndef MS2_SF_GFX_AS2_USERDEFINEDFUNCTION_H
#define MS2_SF_GFX_AS2_USERDEFINEDFUNCTION_H

#include "as2_action.h"
#include "as2_movieroot.h"
#include "../gfx_asimemanager.h"   // GFx::FunctionHandler

namespace Scaleform { namespace GFx { namespace AS2 {

class UserDefinedFunctionObject : public FunctionObject
{
protected:
    Ptr<FunctionHandler> pContext;  // +0x68
    void*                pUserData; // +0x70

    virtual void Finalize_GC()                                                          // 0x1429431a0
    {
        pContext.Clear();
        Object::Finalize_GC();
    }

public:
    UserDefinedFunctionObject(ASStringContext* psc, FunctionHandler* pfc, void* puserData)
        : FunctionObject(psc), pContext(pfc), pUserData(puserData)
    {
        Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
    }

    virtual Environment* GetEnvironment(const FnCall& fn, Ptr<InteractiveObject>*) { return fn.Env; } // 0x14294ab60
    virtual void         Invoke(const FnCall& fn, LocalFrame*, const char*);                         // 0x142963aa0
    virtual bool         IsNull() const { return !pContext; }                                       // 0x142965d00
    virtual bool         IsEqual(const FunctionObject&) const { return false; }                     // 0x142965560
    virtual int          GetNumArgs() const { return -1; }                                          // 0x142954090

    // Hands the call to the handler (0x142964390).
    void InvokeImpl(const FnCall& fn);
};
static_assert(sizeof(UserDefinedFunctionObject) == 0x78, "UserDefinedFunctionObject size");

}}} // namespace Scaleform::GFx::AS2

#endif
