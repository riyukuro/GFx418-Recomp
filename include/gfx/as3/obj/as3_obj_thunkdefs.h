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
// Instances::fl_vec::Vector_* callback methods (every 7, filter 8, forEach 9, some 11, map 14): argument 1
// (thisObject) defaults to null.
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_String, 7, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_String, 8, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_String, 9, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_String, 11, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_String, 14, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_double, 7, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_double, 8, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_double, 9, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_double, 11, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_double, 14, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_int, 7, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_int, 8, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_int, 9, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_int, 11, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_int, 14, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_object, 7, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_object, 8, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_object, 9, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_object, 11, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_object, 14, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_uint, 7, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_uint, 8, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_uint, 9, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_uint, 11, 1)
MS2_AS3_THUNK_NULL_DEFAULT(Instances::fl_vec::Vector_uint, 14, 1)
#undef MS2_AS3_THUNK_NULL_DEFAULT

}}} // namespace Scaleform::GFx::AS3

#endif
