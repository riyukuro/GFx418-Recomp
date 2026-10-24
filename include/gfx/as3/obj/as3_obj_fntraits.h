// Recovered Scaleform GFx 4.1.18 AS3: the instance traits of the native function kinds a Value holds without a
// function object (a thunk, an unbound method index, a virtual table index) and of thunk function objects. Our own
// declarations from the exe. ClassTraits::Function (as3_obj_fl.h) makes one of each; constructors, vftables and
// sdtors lie in sfr_as3_01c's range, the name helpers in sfr_as3_04's (which still declares its own copies).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_FNTRAITS_H
#define MS2_SF_GFX_AS3_OBJ_FNTRAITS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fl.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl { extern const ClassInfo FunctionCI; }  // 0x14313dc10: the methods of every function kind

namespace InstanceTraits {
    // Traits of native thunks (Value kind Thunk). vftable 0x14313fbf8.
    class Thunk : public CTraits
    {
    public:
        Thunk(VM& vm);
        // a thunk is no object: nothing to make. 0x14241c200
        virtual void MakeObject(Value& result, Traits& t);
        ASString GetThunkName(const Value& _this) const;

        // apply, call, length (0x142a2a930)
        static const ThunkInfo f[3];
    };

    // Traits of unbound ABC methods (Value kind MethodInd). vftable 0x14313fc80.
    class MethodInd : public CTraits
    {
    public:
        MethodInd(VM& vm);
        // 0x14241c030
        virtual void MakeObject(Value& result, Traits& t);
        ASString GetMethodIndName(const Value& _this) const;

        // 0x142a2a9b0
        static const ThunkInfo f[3];
    };

    // Traits of methods addressed by their virtual table index (Value kind VTableInd). vftable 0x14313fd08.
    class VTableInd : public CTraits
    {
    public:
        VTableInd(VM& vm);
        // 0x14241c220
        virtual void MakeObject(Value& result, Traits& t);

        // 0x142a2aa30
        static const ThunkInfo f[3];
    };

    // Traits of native thunks wrapped in a function object (Instances::ThunkFunction). vftable 0x14313fd90.
    class ThunkFunction : public CTraits
    {
    public:
        ThunkFunction(VM& vm);
        // 0x14241c210
        virtual void MakeObject(Value& result, Traits& t);
        ASString GetThunkName(const Value& _this) const;

        // length (0x14313e4b8)
        static const ThunkInfo f[1];
    };
}

}}} // namespace Scaleform::GFx::AS3

#endif
