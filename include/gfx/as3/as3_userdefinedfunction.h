// Recovered Scaleform GFx 4.1.18 AS3: the function object that MovieRoot::CreateFunction 0x1424f3780 builds around
// a host FunctionHandler, so that AS3 code can call back into the application. 0x50 bytes, vftable 0x14317ef38
// (24 slots; over FunctionBase's 0x14313f8f8 it overrides only 4, 21, 22 and 23). The deleting destructor
// 0x1424e3de0 releases pHandler, runs ~FunctionBase 0x1423f0f50 and frees 0x50 bytes.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_USERDEFINEDFUNCTION_H
#define MS2_SF_GFX_AS3_USERDEFINEDFUNCTION_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/gfx_asimemanager.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class UserDefinedFunction : public Instances::FunctionBase
{
public:
    // CreateFunction passes the instance traits of the Function class.
    UserDefinedFunction(InstanceTraits::Traits& t, FunctionHandler* pfc, void* puserData)
        : Instances::FunctionBase(t)
    {
        pHandler  = pfc;
        pUserData = puserData;
    }
    // MS2-FUNCTIONAL 0x1424e3de0: our ??_G inlines ~FunctionBase, the exe calls it (0x1423f0f50).
    virtual ~UserDefinedFunction() {}                                                        // 4  0x1424e3de0 (??_G)

    // Hands the receiver and the arguments to pHandler as GFx values (the receiver first in the argument array);
    // a defined return value comes back in result.
    virtual void     ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv); // 21 0x142500250
    // Runs the function; the result goes on the operand stack unless discarded. The exe calls the body of
    // ExecuteUnsafe (0x1424feb00, which slot 21 jumps to) directly.
    virtual void     Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result = false); // 22 0x1424f9ce0
    // Any number of arguments.
    virtual UInt32   GetMaxParamNum() const { return 0x3ff; }                                // 23 0x14250b490

    Ptr<FunctionHandler> pHandler;      // +0x40
    void*                pUserData;     // +0x48
};
// The deleting destructor 0x1424e3de0 frees 0x50 bytes.
static_assert(sizeof(UserDefinedFunction) == 0x50, "UserDefinedFunction size");

}}} // namespace Scaleform::GFx::AS3

#endif
