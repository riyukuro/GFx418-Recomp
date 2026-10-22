// Recovered Scaleform GFx 4.1.18 AS3: argument defaults of native methods whose ThunkMakeDefsN instance is emitted
// out of line in more than one unit (sfr_as3_01c, sfr_as3_04), so every unit sees the same defaults. Our own
// declarations, from the exe's ThunkMakeDefs2 bodies.
#ifndef MS2_SF_GFX_AS3_OBJ_THUNKDEFS_H
#define MS2_SF_GFX_AS3_OBJ_THUNKDEFS_H

#include "ms2/scaleform/include/gfx/as3/as3_marshalling.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl::Array callback methods (sortOn, every, filter, forEach, map, some): argument 1 (options or
// thisObject) defaults to null.
#define MS2_AS3_THUNK_NULL_DEFAULT(T, N, K) \
    template <> struct ThunkMethodDefault<T, N, K, const Value&> \
    { \
        SF_INLINE static Value Get(StringManager&) { return Value::GetNull(); } \
    };
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 12, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 15, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 16, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 17, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 18, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl::Array, 19, 1)
#undef MS2_AS3_THUNK_NULL_DEFAULT

}}} // namespace Scaleform::GFx::AS3

#endif
