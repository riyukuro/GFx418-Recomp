// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_21
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425584f0-0x142568420 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x14255c2b0: Instances::fl_vec::Vector_String::AS3toLocaleString
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 5, ASString>;
// thunk 0x14255c320: Instances::fl_vec::Vector_String::AS3reverse
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 16, SPtr<Instances::fl_vec::Vector_String>>;
// thunk 0x14255c3d0: Instances::fl_vec::Vector_String::AS3shift
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 17, ASString>;
// thunk 0x14255c440: Instances::fl_vec::Vector_String::AS3pop
template struct ThunkFunc0<Instances::fl_vec::Vector_String, 15, ASString>;
// thunk 0x14255c4b0: Instances::fl_vec::Vector_double::AS3toLocaleString
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 5, ASString>;
// thunk 0x14255c520: Instances::fl_vec::Vector_double::AS3reverse
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 16, SPtr<Instances::fl_vec::Vector_double>>;
// thunk 0x14255c5d0: Instances::fl_vec::Vector_double::AS3shift
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 17, Value::Number>;
// thunk 0x14255c640: Instances::fl_vec::Vector_double::AS3pop
template struct ThunkFunc0<Instances::fl_vec::Vector_double, 15, Value::Number>;
// thunk 0x14255c6b0: Instances::fl_vec::Vector_int::AS3toLocaleString
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 5, ASString>;
// thunk 0x14255c720: Instances::fl_vec::Vector_int::AS3reverse
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 16, SPtr<Instances::fl_vec::Vector_int>>;
// thunk 0x14255c7d0: Instances::fl_vec::Vector_int::AS3shift
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 17, SInt32>;
// thunk 0x14255c830: Instances::fl_vec::Vector_int::AS3pop
template struct ThunkFunc0<Instances::fl_vec::Vector_int, 15, SInt32>;
// thunk 0x14255c890: Instances::fl_vec::Vector_object::AS3toLocaleString
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 5, ASString>;
// thunk 0x14255c900: Instances::fl_vec::Vector_object::AS3reverse
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 16, SPtr<Instances::fl_vec::Vector_object>>;
// thunk 0x14255c9b0: Instances::fl_vec::Vector_object::AS3shift
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 17, Value>;
// thunk 0x14255c9d0: Instances::fl_vec::Vector_object::AS3pop
template struct ThunkFunc0<Instances::fl_vec::Vector_object, 15, Value>;
// thunk 0x14255c9f0: Instances::fl_vec::Vector_uint::AS3toLocaleString
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 5, ASString>;
// thunk 0x14255ca60: Instances::fl_vec::Vector_uint::AS3reverse
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 16, SPtr<Instances::fl_vec::Vector_uint>>;
// thunk 0x14255cb10: Instances::fl_vec::Vector_uint::AS3shift
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 17, UInt32>;
// thunk 0x14255cb70: Instances::fl_vec::Vector_uint::AS3pop
template struct ThunkFunc0<Instances::fl_vec::Vector_uint, 15, UInt32>;
// Instances::fl_vec::Vector_String::AS3join argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_String, 6, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString(","); }
};
// thunk 0x14255cbd0: Instances::fl_vec::Vector_String::AS3join
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 6, ASString, const ASString&>;
// Instances::fl_vec::Vector_double::AS3join argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_double, 6, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString(","); }
};
// thunk 0x14255cd20: Instances::fl_vec::Vector_double::AS3join
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 6, ASString, const ASString&>;
// Instances::fl_vec::Vector_int::AS3join argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_int, 6, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString(","); }
};
// thunk 0x14255ce70: Instances::fl_vec::Vector_int::AS3join
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 6, ASString, const ASString&>;
// Instances::fl_vec::Vector_object::AS3join argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_object, 6, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString(","); }
};
// thunk 0x14255cfc0: Instances::fl_vec::Vector_object::AS3join
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 6, ASString, const ASString&>;
// Instances::fl_vec::Vector_uint::AS3join argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_uint, 6, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString(","); }
};
// thunk 0x14255d110: Instances::fl_vec::Vector_uint::AS3join
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 6, ASString, const ASString&>;
// thunk 0x14255d260: Instances::fl_vec::Vector_String::AS3every
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 7, bool, const Value&, const Value&>;
// thunk 0x14255d380: Instances::fl_vec::Vector_String::AS3forEach
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 8, const Value, const Value&, const Value&>;
// thunk 0x14255d460: Instances::fl_vec::Vector_String::AS3map
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 9, SPtr<Instances::fl_vec::Vector_String>, const Value&, const Value&>;
// thunk 0x14255d5d0: Instances::fl_vec::Vector_String::AS3push
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 10, Value, unsigned, const Value*>;
// thunk 0x14255d5f0: Instances::fl_vec::Vector_String::AS3slice
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 18, Value, unsigned, const Value*>;
// thunk 0x14255d610: Instances::fl_vec::Vector_String::AS3sort
template struct ThunkFunc1<Instances::fl_vec::Vector_String, 19, SPtr<Instances::fl_vec::Vector_String>, const Value&>;
// thunk 0x14255d630: Instances::fl_vec::Vector_String::AS3splice
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 20, Value, unsigned, const Value*>;
// thunk 0x14255d650: Instances::fl_vec::Vector_String::AS3indexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 21, SInt32, const ASString&, SInt32>;
// Instances::fl_vec::Vector_String::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_String, 22, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x14255d7e0: Instances::fl_vec::Vector_String::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 22, SInt32, const ASString&, SInt32>;
// thunk 0x14255d970: Instances::fl_vec::Vector_String::AS3some
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 11, bool, const Value&, const Value&>;
// thunk 0x14255da90: Instances::fl_vec::Vector_String::AS3unshift
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 12, Value, unsigned, const Value*>;
// thunk 0x14255dab0: Instances::fl_vec::Vector_String::AS3concat
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 13, Value, unsigned, const Value*>;
// thunk 0x14255dad0: Instances::fl_vec::Vector_String::AS3filter
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 14, SPtr<Instances::fl_vec::Vector_String>, const Value&, const Value&>;
// thunk 0x14255dc40: Instances::fl_vec::Vector_double::AS3every
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 7, bool, const Value&, const Value&>;
// thunk 0x14255dd60: Instances::fl_vec::Vector_double::AS3forEach
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 8, const Value, const Value&, const Value&>;
// thunk 0x14255de40: Instances::fl_vec::Vector_double::AS3map
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 9, SPtr<Instances::fl_vec::Vector_double>, const Value&, const Value&>;
// thunk 0x14255dfb0: Instances::fl_vec::Vector_double::AS3push
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 10, Value, unsigned, const Value*>;
// thunk 0x14255dfd0: Instances::fl_vec::Vector_double::AS3slice
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 18, Value, unsigned, const Value*>;
// thunk 0x14255dff0: Instances::fl_vec::Vector_double::AS3sort
template struct ThunkFunc1<Instances::fl_vec::Vector_double, 19, SPtr<Instances::fl_vec::Vector_double>, const Value&>;
// thunk 0x14255e010: Instances::fl_vec::Vector_double::AS3splice
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 20, Value, unsigned, const Value*>;
// thunk 0x14255e030: Instances::fl_vec::Vector_double::AS3indexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 21, SInt32, Value::Number, SInt32>;
// Instances::fl_vec::Vector_double::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_double, 22, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x14255e140: Instances::fl_vec::Vector_double::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 22, SInt32, Value::Number, SInt32>;
// thunk 0x14255e250: Instances::fl_vec::Vector_double::AS3some
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 11, bool, const Value&, const Value&>;
// thunk 0x14255e370: Instances::fl_vec::Vector_double::AS3unshift
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 12, Value, unsigned, const Value*>;
// thunk 0x14255e390: Instances::fl_vec::Vector_double::AS3concat
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 13, Value, unsigned, const Value*>;
// thunk 0x14255e3b0: Instances::fl_vec::Vector_double::AS3filter
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 14, SPtr<Instances::fl_vec::Vector_double>, const Value&, const Value&>;
// thunk 0x14255e520: Instances::fl_vec::Vector_int::AS3every
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 7, bool, const Value&, const Value&>;
// thunk 0x14255e640: Instances::fl_vec::Vector_int::AS3forEach
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 8, const Value, const Value&, const Value&>;
// thunk 0x14255e720: Instances::fl_vec::Vector_int::AS3map
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 9, SPtr<Instances::fl_vec::Vector_int>, const Value&, const Value&>;
// thunk 0x14255e890: Instances::fl_vec::Vector_int::AS3push
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 10, Value, unsigned, const Value*>;
// thunk 0x14255e8b0: Instances::fl_vec::Vector_int::AS3slice
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 18, Value, unsigned, const Value*>;
// thunk 0x14255e8d0: Instances::fl_vec::Vector_int::AS3sort
template struct ThunkFunc1<Instances::fl_vec::Vector_int, 19, SPtr<Instances::fl_vec::Vector_int>, const Value&>;
// thunk 0x14255e8f0: Instances::fl_vec::Vector_int::AS3splice
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 20, Value, unsigned, const Value*>;
// thunk 0x14255e910: Instances::fl_vec::Vector_int::AS3indexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 21, SInt32, SInt32, SInt32>;
// Instances::fl_vec::Vector_int::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_int, 22, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x14255ea10: Instances::fl_vec::Vector_int::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 22, SInt32, SInt32, SInt32>;
// thunk 0x14255eb10: Instances::fl_vec::Vector_int::AS3some
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 11, bool, const Value&, const Value&>;
// thunk 0x14255ec30: Instances::fl_vec::Vector_int::AS3unshift
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 12, Value, unsigned, const Value*>;
// thunk 0x14255ec50: Instances::fl_vec::Vector_int::AS3concat
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 13, Value, unsigned, const Value*>;
// thunk 0x14255ec70: Instances::fl_vec::Vector_int::AS3filter
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 14, SPtr<Instances::fl_vec::Vector_int>, const Value&, const Value&>;
// thunk 0x14255ede0: Instances::fl_vec::Vector_object::AS3every
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 7, bool, const Value&, const Value&>;
// thunk 0x14255ef00: Instances::fl_vec::Vector_object::AS3forEach
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 8, const Value, const Value&, const Value&>;
// thunk 0x14255efe0: Instances::fl_vec::Vector_object::AS3map
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 9, SPtr<Instances::fl_vec::Vector_object>, const Value&, const Value&>;
// thunk 0x14255f150: Instances::fl_vec::Vector_object::AS3push
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 10, Value, unsigned, const Value*>;
// thunk 0x14255f170: Instances::fl_vec::Vector_object::AS3slice
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 18, Value, unsigned, const Value*>;
// thunk 0x14255f190: Instances::fl_vec::Vector_object::AS3sort
template struct ThunkFunc1<Instances::fl_vec::Vector_object, 19, SPtr<Instances::fl_vec::Vector_object>, const Value&>;
// thunk 0x14255f1b0: Instances::fl_vec::Vector_object::AS3splice
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 20, Value, unsigned, const Value*>;
// thunk 0x14255f1d0: Instances::fl_vec::Vector_object::AS3indexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 21, SInt32, const Value&, SInt32>;
// Instances::fl_vec::Vector_object::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_object, 22, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x14255f380: Instances::fl_vec::Vector_object::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 22, SInt32, const Value&, SInt32>;
// thunk 0x14255f530: Instances::fl_vec::Vector_object::AS3some
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 11, bool, const Value&, const Value&>;
// thunk 0x14255f650: Instances::fl_vec::Vector_object::AS3unshift
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 12, Value, unsigned, const Value*>;
// thunk 0x14255f670: Instances::fl_vec::Vector_object::AS3concat
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 13, Value, unsigned, const Value*>;
// thunk 0x14255f690: Instances::fl_vec::Vector_object::AS3filter
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 14, SPtr<Instances::fl_vec::Vector_object>, const Value&, const Value&>;
// thunk 0x14255f800: Instances::fl_vec::Vector_uint::AS3every
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 7, bool, const Value&, const Value&>;
// thunk 0x14255f920: Instances::fl_vec::Vector_uint::AS3forEach
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 8, const Value, const Value&, const Value&>;
// thunk 0x14255fa00: Instances::fl_vec::Vector_uint::AS3map
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 9, SPtr<Instances::fl_vec::Vector_uint>, const Value&, const Value&>;
// thunk 0x14255fb70: Instances::fl_vec::Vector_uint::AS3push
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 10, Value, unsigned, const Value*>;
// thunk 0x14255fb90: Instances::fl_vec::Vector_uint::AS3slice
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 18, Value, unsigned, const Value*>;
// thunk 0x14255fbb0: Instances::fl_vec::Vector_uint::AS3sort
template struct ThunkFunc1<Instances::fl_vec::Vector_uint, 19, SPtr<Instances::fl_vec::Vector_uint>, const Value&>;
// thunk 0x14255fbd0: Instances::fl_vec::Vector_uint::AS3splice
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 20, Value, unsigned, const Value*>;
// thunk 0x14255fbf0: Instances::fl_vec::Vector_uint::AS3indexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 21, SInt32, UInt32, SInt32>;
// Instances::fl_vec::Vector_uint::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_vec::Vector_uint, 22, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x14255fcf0: Instances::fl_vec::Vector_uint::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 22, SInt32, UInt32, SInt32>;
// thunk 0x14255fdf0: Instances::fl_vec::Vector_uint::AS3some
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 11, bool, const Value&, const Value&>;
// thunk 0x14255ff10: Instances::fl_vec::Vector_uint::AS3unshift
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 12, Value, unsigned, const Value*>;
// thunk 0x14255ff30: Instances::fl_vec::Vector_uint::AS3concat
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 13, Value, unsigned, const Value*>;
// thunk 0x14255ff50: Instances::fl_vec::Vector_uint::AS3filter
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 14, SPtr<Instances::fl_vec::Vector_uint>, const Value&, const Value&>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c2b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c320
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BB@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c3d0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0P@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c440
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c4b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c520
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c5d0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0P@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c640
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c6b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c720
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BB@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c7d0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0P@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c830
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c890
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c900
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BB@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c9b0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c9d0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255c9f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ca60
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BB@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255cb10
// MS2-PIN: ?Func@?$ThunkFunc0@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0P@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255cb70
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$05VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255cbd0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$05VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255cd20
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$05VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ce70
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$05VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255cfc0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$05VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d110
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$06_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d260
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d380
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d460
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d5d0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d5f0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d610
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d630
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JAEBVASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d650
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JAEBVASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d7e0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d970
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255da90
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dab0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dad0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$06_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dc40
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dd60
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255de40
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dfb0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dfd0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dff0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e010
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JNJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e030
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JNJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e140
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e250
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e370
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e390
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e3b0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$06_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e520
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e640
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e720
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e890
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e8b0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e8d0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e8f0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e910
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ea10
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255eb10
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ec30
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ec50
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ec70
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$06_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ede0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ef00
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255efe0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f150
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f170
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f190
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f1b0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f1d0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f380
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f530
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f650
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f670
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f690
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$06_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f800
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f920
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fa00
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fb70
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fb90
// MS2-PIN: ?Func@?$ThunkFunc1@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbb0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbd0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JKJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JKJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fcf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fdf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff10
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff30
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff50
