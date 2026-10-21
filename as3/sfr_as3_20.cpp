// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_20
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142542820-0x1425584f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142546850: Instances::fl_vec::Vector_double::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 0, UInt32>;
// thunk 0x1425468b0: Instances::fl_vec::Vector_double::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 1, const Value, UInt32>;
// thunk 0x142546920: Instances::fl_vec::Vector_double::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 2, const Value, bool>;
// thunk 0x142546980: Instances::fl_vec::Vector_double::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 3, bool>;
// thunk 0x1425469e0: Instances::fl_vec::Vector_double::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 4, ASString>;
// thunk 0x142546a50: Instances::fl_vec::Vector_String::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 0, UInt32>;
// thunk 0x142546ab0: Instances::fl_vec::Vector_String::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 1, const Value, UInt32>;
// thunk 0x142546b20: Instances::fl_vec::Vector_String::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 2, const Value, bool>;
// thunk 0x142546b80: Instances::fl_vec::Vector_String::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 3, bool>;
// thunk 0x142546be0: Instances::fl_vec::Vector_String::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 4, ASString>;
// thunk 0x142547220: Instances::fl_vec::Vector_object::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 0, UInt32>;
// thunk 0x142547280: Instances::fl_vec::Vector_object::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 1, const Value, UInt32>;
// thunk 0x1425472f0: Instances::fl_vec::Vector_object::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 2, const Value, bool>;
// thunk 0x142547350: Instances::fl_vec::Vector_object::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 3, bool>;
// thunk 0x1425473b0: Instances::fl_vec::Vector_object::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 4, ASString>;
// thunk 0x142547560: Instances::fl_vec::Vector_int::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 0, UInt32>;
// thunk 0x1425475c0: Instances::fl_vec::Vector_int::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 1, const Value, UInt32>;
// thunk 0x142547630: Instances::fl_vec::Vector_int::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 2, const Value, bool>;
// thunk 0x142547690: Instances::fl_vec::Vector_int::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 3, bool>;
// thunk 0x1425476f0: Instances::fl_vec::Vector_int::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 4, ASString>;
// thunk 0x142547760: Instances::fl_vec::Vector_uint::lengthGet
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 0, UInt32>;
// thunk 0x1425477c0: Instances::fl_vec::Vector_uint::lengthSet
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 1, const Value, UInt32>;
// thunk 0x142547830: Instances::fl_vec::Vector_uint::fixedSet
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 2, const Value, bool>;
// thunk 0x142547890: Instances::fl_vec::Vector_uint::fixedGet
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 3, bool>;
// thunk 0x1425478f0: Instances::fl_vec::Vector_uint::AS3toString
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 4, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546850
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425468b0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546920
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546980
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425469e0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546a50
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546ab0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546b20
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546b80
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142546be0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547220
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547280
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425472f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547350
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425473b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547560
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425475c0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547630
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547690
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425476f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547760
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425477c0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547830
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142547890
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1425478f0
