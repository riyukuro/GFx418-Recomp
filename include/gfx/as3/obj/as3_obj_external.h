// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_EXTERNAL_H
#define MS2_SF_GFX_AS3_OBJ_EXTERNAL_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl_external {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ExternalInterface : public Class
    {
    public:
        // @0x142473710
        void addCallback(const Value& result, const ASString&, const Value&);
        // @0x142473730
        void availableGet(bool& result);
        // @0x142473760
        void call(Value& result, unsigned, const Value*);
        // @0x142473990
        void marshallExceptionsGet(bool& result);
        // @0x1424739f0
        void marshallExceptionsSet(const Value& result, bool);
        // @0x142473a50
        void objectIDGet(ASString& result);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
