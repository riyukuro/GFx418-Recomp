// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_21
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425584f0-0x142568420 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEBJU?$AllocatorDH@PEBJ$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1425629a0 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEBNU?$AllocatorDH@PEBN$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142562ae0 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@U?$AllocatorDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142562b80 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEBVValue@AS3@GFx@Scaleform@@U?$AllocatorDH@PEBVValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142562c20 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Pair@NK@Scaleform@@U?$AllocatorDH@U?$Pair@NK@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142562cc0 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@U?$AllocatorDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142562d60 ; prop
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"

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
template struct ThunkFunc2<Instances::fl_vec::Vector_String, 19, Value, unsigned, const Value*>;
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
template struct ThunkFunc2<Instances::fl_vec::Vector_double, 19, Value, unsigned, const Value*>;
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
template struct ThunkFunc2<Instances::fl_vec::Vector_int, 19, Value, unsigned, const Value*>;
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
template struct ThunkFunc2<Instances::fl_vec::Vector_object, 19, Value, unsigned, const Value*>;
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
template struct ThunkFunc2<Instances::fl_vec::Vector_uint, 19, Value, unsigned, const Value*>;
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


// sfr_as3_20: the Vector.slice / Vector.splice bodies, one per element type
void FUN_14254fe70(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142553bb0(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142550070(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142553e90(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142550290(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_142554280(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_142550490(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142554660(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142550640(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);
void FUN_142554880(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);

// ---------------------------------------------------------------- Vector

// VM::GetClassTraits(const Value&) / ClassTraits::Traits::IsParentTypeOf
Scaleform::GFx::AS3::ClassTraits::Traits& FUN_142507f60(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other);
// GetValueTraits (sfr_as3_09)
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x1425602c0
AbsoluteIndex ArrayBase::GetNextArrayIndex(AbsoluteIndex ind) const
{
    const SInt32 size = (SInt32)GetSize();
    if (!ind.IsValid())
    {
        if (size != 0)
            return AbsoluteIndex(0);
    }
    else if ((UPInt)ind.Get() < (UPInt)(SPInt)(size - 1))
        return AbsoluteIndex(ind.Get() + 1);
    return AbsoluteIndex(-1);
}

// @0x142564220
ASString ArrayBase::Join(const ASString& sep) const
{
    StringBuffer buf(VMRef.GetMemoryHeap());
    const UInt32 size = GetSize();
    for (UInt32 i = 0; i < size; ++i)
    {
        if (i != 0)
            buf.AppendString(sep.ToCStr());
        Value v;
        GetValueUnsafe(i, v);
        if (v.IsNullOrUndefined())
            continue;
        if (!v.Convert2String(buf))
            break;
    }
    return VMRef.GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
}

// @0x14255af20
// MS2-FUNCTIONAL: callable kind test laid out as a different range compare
CheckResult ArrayBase::CheckCallable(const Value& v) const
{
    if (v.IsCallable())
        return true;
    VM& vm = VMRef;
    vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, FUN_14250ffc0(vm, v).GetName().ToCStr(), "callable"));
    return false;
}

// @0x142563ee0
bool ArrayBase::Some(const Value& callback, const Value& thisObject, Instances::fl::Object* owner) const
{
    if (callback.IsNullOrUndefined() || !CheckCallable(callback))
        return false;
    Value _this(!thisObject.IsNullOrUndefined() ? thisObject : callback);
    const UInt32 size = GetSize();
    for (UInt32 i = 0; i < size; ++i)
    {
        Value argv[3] = {Value::GetUndefined(), Value(i), Value(owner)};
        Value result;
        GetValue(i, argv[0]);
        VMRef.ExecuteInternalUnsafe(callback, _this, result, 3, argv, false);
        if (VMRef.IsException())
            break;
        if (!result.IsBool())
            return false;
        if (result.AsBool() == true)
            return true;
    }
    return false;
}

// @0x14255bbd0
bool ArrayBase::Every(const Value& callback, const Value& thisObject, Instances::fl::Object* owner) const
{
    if (callback.IsNullOrUndefined() || !CheckCallable(callback))
        return false;
    UInt32 i = 0;
    Value _this(!thisObject.IsNullOrUndefined() ? thisObject : callback);
    const UInt32 size = GetSize();
    for (; i < size; ++i)
    {
        Value argv[3] = {Value::GetUndefined(), Value(i), Value(owner)};
        Value result;
        GetValue(i, argv[0]);
        VMRef.ExecuteInternalUnsafe(callback, _this, result, 3, argv, false);
        if (VMRef.IsException())
            break;
        if (!result.IsBool() || !result.AsBool())
            break;
    }
    return i == size;
}

// @0x14255bf00
void ArrayBase::ForEach(const Value& callback, const Value& thisObject, Instances::fl::Object* owner) const
{
    if (callback.IsNullOrUndefined() || !CheckCallable(callback))
        return;
    Value _this(!thisObject.IsNullOrUndefined() ? thisObject : callback);
    const UInt32 size = GetSize();
    for (UInt32 i = 0; i < size; ++i)
    {
        Value argv[3] = {Value::GetUndefined(), Value(i), Value(owner)};
        Value result;
        GetValue(i, argv[0]);
        VMRef.ExecuteInternalUnsafe(callback, _this, result, 3, argv, false);
        if (VMRef.IsException())
            break;
    }
}

// @0x14255b1d0
// MS2-FUNCTIONAL: error-path register allocation differs
CheckResult ArrayBase::CheckArgTypes(unsigned argc, const Value* argv, const ClassTraits::Traits& tr) const
{
    for (unsigned i = 0; i < argc; ++i)
    {
        if (!FUN_1425149a0(tr, FUN_142507f60(VMRef, argv[i])))
        {
            VM& vm = VMRef;
            vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, "arguments", tr.GetName().ToCStr()));
            return false;
        }
    }
    return true;
}

// @0x14255afd0
// MS2-FUNCTIONAL: register allocation / frame size (0x50 vs 0x40) differ
CheckResult ArrayBase::CheckCoerce(const ClassTraits::Traits& tr, const Value& v, Value& result) const
{
    if (!tr.Coerce(v, result))
    {
        VM& vm = VMRef;
        const Traits& vtr = FUN_14250ffc0(vm, v);
        vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, vtr.GetName().ToCStr(), tr.GetName().ToCStr()));
        return false;
    }
    return true;
}

// ---- VectorBase<SInt32>

// @0x142560220
template <>
UInt32 VectorBase<SInt32>::GetSize() const
{
    return (UInt32)V.GetSize();
}

// @0x142560b40
template <>
void VectorBase<SInt32>::GetValue(UInt32 ind, Value& v) const
{
    v.Assign(V[ind]);
}

// @0x142560ca0
template <>
void VectorBase<SInt32>::GetValueUnsafe(UInt32 ind, Value& v) const
{
    v.AssignUnsafe(V[ind]);
}

// @0x142562520
template <>
void VectorBase<SInt32>::PushBackUnsafe(const Value& v)
{
    V.PushBack(v.AsInt());
}

// jmp thunk 0x142562750
template <>
void VectorBase<SInt32>::PushBackValueUnsafe(const Value& v)
{
    PushBackUnsafe(v);
}

// @0x142562e70
template <>
CheckResult VectorBase<SInt32>::Resize(UPInt size)
{
    bool ok = false;
    if (CheckFixed())
    {
        UPInt i = V.GetSize();
        V.Resize(size);
        for (; i < size; ++i)
            V[i] = 0;
        ok = true;
    }
    return ok;
}

// @0x142563720
// MS2-FUNCTIONAL: size compares and the inlined Resize scheduled differently
template <>
__declspec(noinline) CheckResult VectorBase<SInt32>::Set(UInt32 ind, const Value& v, const ClassTraits::Traits& tr)
{
    if ((Fixed && ind >= (UInt32)V.GetSize()) || ind > (UInt32)V.GetSize())
    {
        VM& vm = VMRef;
        vm.ThrowRangeError(VM::Error(VM::eInvalidRangeError, vm, (int)ind, (int)V.GetSize() - 1));
        return false;
    }
    if (ind == (UInt32)V.GetSize() && !Resize(ind + 1))
        return false;
    Value r;
    if (!CheckCoerce(tr, v, r))
        return false;
    V[ind] = r.AsInt();
    return true;
}

// @0x142564390
// MS2-FUNCTIONAL: exe inlines the array growth/memmove/zero fill; InsertMultipleAt is called here
template <>
void VectorBase<SInt32>::Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    V.InsertMultipleAt(0, argc);
    for (unsigned i = 0; i < argc; ++i)
        V[i] = argv[i].AsInt();
}

// ---- VectorBase<UInt32>

// @0x142560230
template <>
UInt32 VectorBase<UInt32>::GetSize() const
{
    return (UInt32)V.GetSize();
}

// @0x142560ba0
template <>
void VectorBase<UInt32>::GetValue(UInt32 ind, Value& v) const
{
    v.Assign(V[ind]);
}

// @0x142560cd0
template <>
void VectorBase<UInt32>::GetValueUnsafe(UInt32 ind, Value& v) const
{
    v.AssignUnsafe(V[ind]);
}

// @0x142562590
template <>
void VectorBase<UInt32>::PushBackUnsafe(const Value& v)
{
    V.PushBack(v.AsUInt());
}

// jmp thunk 0x142562760
template <>
void VectorBase<UInt32>::PushBackValueUnsafe(const Value& v)
{
    PushBackUnsafe(v);
}

// @0x142562f30
template <>
CheckResult VectorBase<UInt32>::Resize(UPInt size)
{
    bool ok = false;
    if (CheckFixed())
    {
        UPInt i = V.GetSize();
        V.Resize(size);
        for (; i < size; ++i)
            V[i] = 0;
        ok = true;
    }
    return ok;
}

// @0x1425644f0
// MS2-FUNCTIONAL: exe inlines the array growth/memmove/zero fill; InsertMultipleAt is called here
template <>
void VectorBase<UInt32>::Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    V.InsertMultipleAt(0, argc);
    for (unsigned i = 0; i < argc; ++i)
        V[i] = argv[i].AsUInt();
}

// ---- VectorBase<Value::Number>

// @0x142560240
template <>
UInt32 VectorBase<Value::Number>::GetSize() const
{
    return (UInt32)V.GetSize();
}

// @0x142560c00
template <>
void VectorBase<Value::Number>::GetValue(UInt32 ind, Value& v) const
{
    v.Assign(V[ind]);
}

// @0x142560d00
template <>
void VectorBase<Value::Number>::GetValueUnsafe(UInt32 ind, Value& v) const
{
    v.AssignUnsafe(V[ind]);
}

// @0x142562600
template <>
void VectorBase<Value::Number>::PushBackUnsafe(const Value& v)
{
    V.PushBack(v.AsNumber());
}

// jmp thunk 0x142562770
template <>
void VectorBase<Value::Number>::PushBackValueUnsafe(const Value& v)
{
    PushBackUnsafe(v);
}

// @0x142562ff0
template <>
CheckResult VectorBase<Value::Number>::Resize(UPInt size)
{
    bool ok = false;
    if (CheckFixed())
    {
        UPInt i = V.GetSize();
        V.Resize(size);
        for (; i < size; ++i)
            V[i] = 0;
        ok = true;
    }
    return ok;
}

// @0x142564650
// MS2-FUNCTIONAL: exe inlines the array growth/memmove/zero fill; InsertMultipleAt is called here
template <>
void VectorBase<Value::Number>::Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    V.InsertMultipleAt(0, argc);
    for (unsigned i = 0; i < argc; ++i)
        V[i] = argv[i].AsNumber();
}

// ---- VectorBase<Ptr<ASStringNode> >

// @0x142560250
template <>
UInt32 VectorBase<Ptr<ASStringNode> >::GetSize() const
{
    return (UInt32)V.GetSize();
}

// @0x142560c60
template <>
void VectorBase<Ptr<ASStringNode> >::GetValue(UInt32 ind, Value& v) const
{
    v.Assign(V[ind].GetPtr());
}

// @0x142560d30
template <>
void VectorBase<Ptr<ASStringNode> >::GetValueUnsafe(UInt32 ind, Value& v) const
{
    v.AssignUnsafe(V[ind].GetPtr());
}

template <>
void VectorBase<Ptr<ASStringNode> >::PushBackUnsafe(const Value& v)
{
    Ptr<ASStringNode> node(v.GetStringNode());
    V.PushBack(node);
}

// @0x142562780
template <>
void VectorBase<Ptr<ASStringNode> >::PushBackValueUnsafe(const Value& v)
{
    PushBackUnsafe(v);
}

// @0x1425630f0
template <>
CheckResult VectorBase<Ptr<ASStringNode> >::Resize(UPInt size)
{
    bool ok = false;
    if (CheckFixed())
    {
        UPInt i = V.GetSize();
        V.Resize(size);
        for (; i < size; ++i)
            V[i] = Ptr<ASStringNode>(VMRef.GetStringManager().GetBuiltin(AS3Builtin_null).GetNode());
        ok = true;
    }
    return ok;
}

// @0x1425638c0
// MS2-FUNCTIONAL: size compares scheduled differently
template <>
__declspec(noinline) CheckResult VectorBase<Ptr<ASStringNode> >::Set(UInt32 ind, const Value& v, const ClassTraits::Traits& tr)
{
    if ((Fixed && ind >= (UInt32)V.GetSize()) || ind > (UInt32)V.GetSize())
    {
        VM& vm = VMRef;
        vm.ThrowRangeError(VM::Error(VM::eInvalidRangeError, vm, (int)ind, (int)V.GetSize() - 1));
        return false;
    }
    if (ind == (UInt32)V.GetSize() && !Resize(ind + 1))
        return false;
    Value r;
    if (!CheckCoerce(tr, v, r))
        return false;
    V[ind] = r.GetStringNode();
    return true;
}

// @0x142564860
// MS2-FUNCTIONAL: exe inlines the array growth/memmove/zero fill; InsertMultipleAt is called here
template <>
void VectorBase<Ptr<ASStringNode> >::Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    V.InsertMultipleAt(0, argc);
    for (unsigned i = 0; i < argc; ++i)
        V[i] = argv[i].GetStringNode();
}

// ---- VectorBase<Value>

// @0x142560260
template <>
UInt32 VectorBase<Value>::GetSize() const
{
    return (UInt32)V.GetSize();
}

// @0x142560c80
template <>
void VectorBase<Value>::GetValue(UInt32 ind, Value& v) const
{
    v.Assign(V[ind]);
}

// @0x142560d50
template <>
void VectorBase<Value>::GetValueUnsafe(UInt32 ind, Value& v) const
{
    v.AssignUnsafe(V[ind]);
}

// @0x142562670
template <>
void VectorBase<Value>::PushBackUnsafe(const Value& v)
{
    Value tmp(v);
    V.PushBack(tmp);
}

// jmp thunk 0x1425627e0
template <>
void VectorBase<Value>::PushBackValueUnsafe(const Value& v)
{
    PushBackUnsafe(v);
}

// MS2-FUNCTIONAL: ours inlines ArrayDataDH<Value>::Resize, the exe calls it (0x14241fdd0)
// @0x142563240
template <>
CheckResult VectorBase<Value>::Resize(UPInt size)
{
    bool ok = false;
    if (CheckFixed())
    {
        UPInt i = V.GetSize();
        V.Resize(size);
        for (; i < size; ++i)
            V[i] = Value(Value::GetNull());
        ok = true;
    }
    return ok;
}

template class VectorBase<SInt32>;
template class VectorBase<UInt32>;
template class VectorBase<Value::Number>;
template class VectorBase<Ptr<ASStringNode> >;
template class VectorBase<Value>;

namespace Instances { namespace fl_vec {

// ---- Vector_String

// @0x142560270
void Vector_String::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    static_cast<ArrayBase&>(V).GetValue((UInt32)ind.Get(), value);
}

// @0x142560510
// MS2-FUNCTIONAL: Value setter codegen differs
void Vector_String::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    if (ind.IsValid())
        name.SetUInt32(ind.Get() - 1);
    else
        name.SetUndefined();
}

// @0x142560330
// MS2-FUNCTIONAL: index arithmetic codegen differs
GlobalSlotIndex Vector_String::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const AbsoluteIndex next = V.GetNextArrayIndex(AbsoluteIndex((SPInt)ind.Get() - 1));
    return GlobalSlotIndex(next.IsValid() ? (UInt32)next.Get() + 1 : 0);
}

// @0x1425607e0
// MS2-FUNCTIONAL: element read inlined differently
CheckResult Vector_String::GetProperty(const Multiname& prop_name, Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::GetProperty(prop_name, value);
    if (ind < V.V.GetSize())
    {
        V.GetValue(ind, value);
        return true;
    }
    return false;
}

// @0x1425587a0
// MS2-FUNCTIONAL: CheckFixed/RemoveAt inlining differs
void Vector_String::AS3shift(ASString& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        ASStringNode* node = V.V[0];
        if (!node)
            node = result.GetManager()->GetNullStringNode();
        result.AssignNode(node);
        V.V.RemoveAt(0);
    }
}

// @0x142564bf0
void Vector_String::fixedGet(bool& result)
{
    result = V.Fixed;
}

// @0x142564c40
void Vector_String::fixedSet(const Value& result, bool f)
{
    SF_UNUSED(result);
    V.Fixed = f;
}

// @0x142564c90
void Vector_String::lengthGet(UInt32& result)
{
    result = (UInt32)V.V.GetSize();
}

// @0x142564ce0
// MS2-FUNCTIONAL: Resize is inlined here, the exe calls it
void Vector_String::lengthSet(const Value& result, UInt32 len)
{
    SF_UNUSED(result);
    V.Resize(len);
}

// ---- Vector_double

// @0x142560280
void Vector_double::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    static_cast<ArrayBase&>(V).GetValue((UInt32)ind.Get(), value);
}

// @0x1425605a0
// MS2-FUNCTIONAL: Value setter codegen differs
void Vector_double::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    if (ind.IsValid())
        name.SetUInt32(ind.Get() - 1);
    else
        name.SetUndefined();
}

// @0x142560390
// MS2-FUNCTIONAL: index arithmetic codegen differs
GlobalSlotIndex Vector_double::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const AbsoluteIndex next = V.GetNextArrayIndex(AbsoluteIndex((SPInt)ind.Get() - 1));
    return GlobalSlotIndex(next.IsValid() ? (UInt32)next.Get() + 1 : 0);
}

// @0x142560870
// MS2-FUNCTIONAL: element read inlined differently
CheckResult Vector_double::GetProperty(const Multiname& prop_name, Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::GetProperty(prop_name, value);
    if (ind < V.V.GetSize())
    {
        V.GetValue(ind, value);
        return true;
    }
    return false;
}

// @0x1425584f0
void Vector_double::AS3reverse(SPtr<Vector_double>& result)
{
    for (SPInt i = 0, j = (SPInt)V.V.GetSize() - 1; i < j; ++i, --j)
    {
        const Value::Number tmp = V.V[i];
        V.V[i] = V.V[j];
        V.V[j] = tmp;
    }
    result = this;
}

// @0x142558850
// MS2-FUNCTIONAL: CheckFixed/RemoveAt inlining differs
void Vector_double::AS3shift(Value::Number& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        result = V.V[0];
        V.V.RemoveAt(0);
    }
}

// @0x142564c00
void Vector_double::fixedGet(bool& result)
{
    result = V.Fixed;
}

// @0x142564c50
void Vector_double::fixedSet(const Value& result, bool f)
{
    SF_UNUSED(result);
    V.Fixed = f;
}

// @0x142564ca0
void Vector_double::lengthGet(UInt32& result)
{
    result = (UInt32)V.V.GetSize();
}

// @0x142564d00
// MS2-FUNCTIONAL: Resize is inlined here, the exe calls it
void Vector_double::lengthSet(const Value& result, UInt32 len)
{
    SF_UNUSED(result);
    V.Resize(len);
}

// ---- Vector_int

// @0x142560290
void Vector_int::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    static_cast<ArrayBase&>(V).GetValue((UInt32)ind.Get(), value);
}

// @0x142560630
// MS2-FUNCTIONAL: Value setter codegen differs
void Vector_int::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    if (ind.IsValid())
        name.SetUInt32(ind.Get() - 1);
    else
        name.SetUndefined();
}

// @0x1425603f0
// MS2-FUNCTIONAL: index arithmetic codegen differs
GlobalSlotIndex Vector_int::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const AbsoluteIndex next = V.GetNextArrayIndex(AbsoluteIndex((SPInt)ind.Get() - 1));
    return GlobalSlotIndex(next.IsValid() ? (UInt32)next.Get() + 1 : 0);
}

// @0x142560930
// MS2-FUNCTIONAL: element read inlined differently
CheckResult Vector_int::GetProperty(const Multiname& prop_name, Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::GetProperty(prop_name, value);
    if (ind < V.V.GetSize())
    {
        V.GetValue(ind, value);
        return true;
    }
    return false;
}

// @0x142558590
void Vector_int::AS3reverse(SPtr<Vector_int>& result)
{
    for (SPInt i = 0, j = (SPInt)V.V.GetSize() - 1; i < j; ++i, --j)
    {
        const SInt32 tmp = V.V[i];
        V.V[i] = V.V[j];
        V.V[j] = tmp;
    }
    result = this;
}

// @0x142558910
// MS2-FUNCTIONAL: CheckFixed/RemoveAt inlining differs
void Vector_int::AS3shift(SInt32& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        result = V.V[0];
        V.V.RemoveAt(0);
    }
}

// @0x142564c10
void Vector_int::fixedGet(bool& result)
{
    result = V.Fixed;
}

// @0x142564c60
void Vector_int::fixedSet(const Value& result, bool f)
{
    SF_UNUSED(result);
    V.Fixed = f;
}

// @0x142564cb0
void Vector_int::lengthGet(UInt32& result)
{
    result = (UInt32)V.V.GetSize();
}

// @0x142564d20
// MS2-FUNCTIONAL: Resize is inlined here, the exe calls it
void Vector_int::lengthSet(const Value& result, UInt32 len)
{
    SF_UNUSED(result);
    V.Resize(len);
}

// ---- Vector_object

// @0x1425602a0
void Vector_object::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    static_cast<ArrayBase&>(V).GetValue((UInt32)ind.Get(), value);
}

// @0x1425606c0
// MS2-FUNCTIONAL: Value setter codegen differs
void Vector_object::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    if (ind.IsValid())
        name.SetUInt32(ind.Get() - 1);
    else
        name.SetUndefined();
}

// @0x142560450
// MS2-FUNCTIONAL: index arithmetic codegen differs
GlobalSlotIndex Vector_object::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const AbsoluteIndex next = V.GetNextArrayIndex(AbsoluteIndex((SPInt)ind.Get() - 1));
    return GlobalSlotIndex(next.IsValid() ? (UInt32)next.Get() + 1 : 0);
}

// @0x1425609f0
// MS2-FUNCTIONAL: element read inlined differently
CheckResult Vector_object::GetProperty(const Multiname& prop_name, Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::GetProperty(prop_name, value);
    if (ind < V.V.GetSize())
    {
        V.GetValue(ind, value);
        return true;
    }
    return false;
}

// @0x142558630
// MS2-FUNCTIONAL: Value::Swap inlined differently
void Vector_object::AS3reverse(SPtr<Vector_object>& result)
{
    for (SPInt i = 0, j = (SPInt)V.V.GetSize() - 1; i < j; ++i, --j)
    {
        V.V[i].Swap(V.V[j]);
    }
    result = this;
}

// @0x1425589d0
// MS2-FUNCTIONAL: CheckFixed/RemoveAt inlining differs
void Vector_object::AS3shift(Value& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        result.Assign(V.V[0]);
        V.V.RemoveAt(0);
    }
}

// @0x142564c20
void Vector_object::fixedGet(bool& result)
{
    result = V.Fixed;
}

// @0x142564c70
void Vector_object::fixedSet(const Value& result, bool f)
{
    SF_UNUSED(result);
    V.Fixed = f;
}

// @0x142564cc0
void Vector_object::lengthGet(UInt32& result)
{
    result = (UInt32)V.V.GetSize();
}

// @0x142564d40
void Vector_object::lengthSet(const Value& result, UInt32 len)
{
    SF_UNUSED(result);
    V.Resize(len);
}

// ---- Vector_uint

// @0x1425602b0
void Vector_uint::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    static_cast<ArrayBase&>(V).GetValue((UInt32)ind.Get(), value);
}

// @0x142560750
// MS2-FUNCTIONAL: Value setter codegen differs
void Vector_uint::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    if (ind.IsValid())
        name.SetUInt32(ind.Get() - 1);
    else
        name.SetUndefined();
}

// @0x1425604b0
// MS2-FUNCTIONAL: index arithmetic codegen differs
GlobalSlotIndex Vector_uint::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const AbsoluteIndex next = V.GetNextArrayIndex(AbsoluteIndex((SPInt)ind.Get() - 1));
    return GlobalSlotIndex(next.IsValid() ? (UInt32)next.Get() + 1 : 0);
}

// @0x142560a80
// MS2-FUNCTIONAL: element read inlined differently
CheckResult Vector_uint::GetProperty(const Multiname& prop_name, Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::GetProperty(prop_name, value);
    if (ind < V.V.GetSize())
    {
        V.GetValue(ind, value);
        return true;
    }
    return false;
}

// @0x142558700
void Vector_uint::AS3reverse(SPtr<Vector_uint>& result)
{
    for (SPInt i = 0, j = (SPInt)V.V.GetSize() - 1; i < j; ++i, --j)
    {
        const UInt32 tmp = V.V[i];
        V.V[i] = V.V[j];
        V.V[j] = tmp;
    }
    result = this;
}

// @0x142558a60
// MS2-FUNCTIONAL: CheckFixed/RemoveAt inlining differs
void Vector_uint::AS3shift(UInt32& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        result = V.V[0];
        V.V.RemoveAt(0);
    }
}

// @0x142564c30
void Vector_uint::fixedGet(bool& result)
{
    result = V.Fixed;
}

// @0x142564c80
void Vector_uint::fixedSet(const Value& result, bool f)
{
    SF_UNUSED(result);
    V.Fixed = f;
}

// @0x142564cd0
void Vector_uint::lengthGet(UInt32& result)
{
    result = (UInt32)V.V.GetSize();
}

// @0x142564d60
// MS2-FUNCTIONAL: Resize is inlined here, the exe calls it
void Vector_uint::lengthSet(const Value& result, UInt32 len)
{
    SF_UNUSED(result);
    V.Resize(len);
}

// ---- Vector_String (2)

// @0x142558b20
void Vector_String::AS3slice(Value& result, unsigned argc, const Value* argv)
{
    FUN_14254fe70(V, result, argc, argv, *this);
}

// @0x142558bc0
void Vector_String::AS3some(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Some(callback, thisObject, this);
}

// @0x1425592b0
void Vector_String::AS3splice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142553bb0(V, result, argc, argv, *this);
}

// @0x142559350
void Vector_String::AS3toLocaleString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}

// @0x142559530
void Vector_String::AS3toString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}


// @0x142559710
void Vector_String::AS3unshift(Value& result, unsigned argc, const Value* argv)
{
    V.Unshift(argc, argv, GetVM().GetClassTraitsString());
    result.SetUInt32((UInt32)V.V.GetSize());
}


// ---- Vector_double (2)

// @0x142558b40
void Vector_double::AS3slice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142550070(V, result, argc, argv, *this);
}

// @0x142558bf0
void Vector_double::AS3some(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Some(callback, thisObject, this);
}

// @0x1425592d0
void Vector_double::AS3splice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142553e90(V, result, argc, argv, *this);
}

// @0x1425593b0
void Vector_double::AS3toLocaleString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}

// @0x142559590
void Vector_double::AS3toString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}


// @0x142559790
void Vector_double::AS3unshift(Value& result, unsigned argc, const Value* argv)
{
    V.Unshift(argc, argv, GetVM().GetClassTraitsNumber());
    result.SetUInt32((UInt32)V.V.GetSize());
}


// ---- Vector_int (2)

// @0x142558b60
void Vector_int::AS3slice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142550290(V, result, argc, argv, *this);
}

// @0x142558c20
void Vector_int::AS3some(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Some(callback, thisObject, this);
}

// @0x1425592f0
void Vector_int::AS3splice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142554280(V, result, argc, argv, *this);
}

// @0x142559410
void Vector_int::AS3toLocaleString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}

// @0x1425595f0
void Vector_int::AS3toString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}


// @0x142559810
void Vector_int::AS3unshift(Value& result, unsigned argc, const Value* argv)
{
    V.Unshift(argc, argv, GetVM().GetClassTraitsSInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}


// ---- Vector_object (2)

// @0x142558b80
void Vector_object::AS3slice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142550490(V, result, argc, argv, *this);
}

// @0x142558c50
void Vector_object::AS3some(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Some(callback, thisObject, this);
}

// @0x142559310
void Vector_object::AS3splice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142554660(V, result, argc, argv, *this);
}

// @0x142559470
void Vector_object::AS3toLocaleString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}

// @0x142559650
void Vector_object::AS3toString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}


// ---- Vector_uint (2)

// @0x142558ba0
void Vector_uint::AS3slice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142550640(V, result, argc, argv, *this);
}

// @0x142558c80
void Vector_uint::AS3some(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Some(callback, thisObject, this);
}

// @0x142559330
void Vector_uint::AS3splice(Value& result, unsigned argc, const Value* argv)
{
    FUN_142554880(V, result, argc, argv, *this);
}

// @0x1425594d0
void Vector_uint::AS3toLocaleString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}

// @0x1425596b0
void Vector_uint::AS3toString(ASString& result)
{
    result = V.Join(GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_));
}


// @0x142559930
void Vector_uint::AS3unshift(Value& result, unsigned argc, const Value* argv)
{
    V.Unshift(argc, argv, GetVM().GetClassTraitsUInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// ---- DeleteProperty

// @0x14255b7f0
CheckResult Vector_String::DeleteProperty(const Multiname& prop_name)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::DeleteProperty(prop_name);
    if (ind >= V.V.GetSize())
        return false;
    V.V.RemoveAt(ind);
    return true;
}

// @0x14255b890
// MS2-FUNCTIONAL: RemoveAt's Clear is inlined here, the exe calls it
CheckResult Vector_double::DeleteProperty(const Multiname& prop_name)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::DeleteProperty(prop_name);
    if (ind >= V.V.GetSize())
        return false;
    V.V.RemoveAt(ind);
    return true;
}

// @0x14255b970
// MS2-FUNCTIONAL: RemoveAt's Clear is inlined here, the exe calls it
CheckResult Vector_int::DeleteProperty(const Multiname& prop_name)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::DeleteProperty(prop_name);
    if (ind >= V.V.GetSize())
        return false;
    V.V.RemoveAt(ind);
    return true;
}

// @0x14255ba50
CheckResult Vector_object::DeleteProperty(const Multiname& prop_name)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::DeleteProperty(prop_name);
    if (ind >= V.V.GetSize())
        return false;
    V.V.RemoveAt(ind);
    return true;
}

// @0x14255baf0
// MS2-FUNCTIONAL: RemoveAt's Clear is inlined here, the exe calls it
CheckResult Vector_uint::DeleteProperty(const Multiname& prop_name)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::DeleteProperty(prop_name);
    if (ind >= V.V.GetSize())
        return false;
    V.V.RemoveAt(ind);
    return true;
}

// ---- SetProperty

// @0x142563b20
CheckResult Vector_String::SetProperty(const Multiname& prop_name, const Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::SetProperty(prop_name, value);
    return V.Set(ind, value, GetVM().GetClassTraitsString());
}

// @0x142563bb0
CheckResult Vector_double::SetProperty(const Multiname& prop_name, const Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::SetProperty(prop_name, value);
    return V.Set(ind, value, GetVM().GetClassTraitsNumber());
}

// @0x142563c40
CheckResult Vector_int::SetProperty(const Multiname& prop_name, const Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::SetProperty(prop_name, value);
    return V.Set(ind, value, GetVM().GetClassTraitsSInt());
}

// @0x142563db0
CheckResult Vector_uint::SetProperty(const Multiname& prop_name, const Value& value)
{
    UInt32 ind;
    if (!GetVectorInd(prop_name, ind))
        return Instances::fl::Object::SetProperty(prop_name, value);
    return V.Set(ind, value, GetVM().GetClassTraitsUInt());
}

}} // namespace Instances::fl_vec

}}} // namespace Scaleform::GFx::AS3

// ---------------------------------------------------------------- Vector sort

// The Vector.sort bodies (sfr_as3_20), one per element type: compare function or Array sort option bits.
void FUN_142550840(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142551250(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142551cb0(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_1425526f0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
// Traits::GetConstructor, out of line in the exe.
const Scaleform::GFx::AS3::Class& FUN_142508490(const Scaleform::GFx::AS3::Traits* tr);
void FUN_142553170(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, Scaleform::GFx::AS3::Value& result, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv,
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// TypeError 1034 for a sort argument that is neither callable nor given.
#define MS2_VEC_SORT(TYPE, SORT)                                                                            \
void TYPE::AS3sort(Value& result, unsigned argc, const Value* argv)                                         \
{                                                                                                           \
    if (argc >= 1 && !argv[0].IsNullOrUndefined() && argv[0].IsCallable())                                 \
    {                                                                                                       \
        SORT(V, result, argc, argv, *this);                                                                 \
        return;                                                                                             \
    }                                                                                                       \
    VM& vm = GetVM();                                                                                       \
    vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm,                                              \
        argc ? FUN_14250ffc0(vm, argv[0]).GetName().ToCStr() : "undefined",                                 \
        GetVM().GetClassTraitsString().GetName().ToCStr()));                                               \
}

// @0x142558cb0
MS2_VEC_SORT(Vector_String, FUN_142550840)
// @0x142558de0
MS2_VEC_SORT(Vector_double, FUN_142551250)
// @0x142558f10
MS2_VEC_SORT(Vector_int, FUN_142551cb0)
// @0x142559040
// Same as above, but the error names the element class: the Vector.<T> class traits keep T's
// ClassTraits at +0xc8 (ClassTraits::fl_vec::Vector_object::EnclosedClassTraits).
void Vector_object::AS3sort(Value& result, unsigned argc, const Value* argv)
{
    if (argc >= 1 && !argv[0].IsNullOrUndefined() && argv[0].IsCallable())
    {
        FUN_1425526f0(V, result, argc, argv, *this);
        return;
    }
    VM& vm = GetVM();
    vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm,
        argc ? FUN_14250ffc0(vm, argv[0]).GetName().ToCStr() : "undefined",
        (*reinterpret_cast<ClassTraits::Traits* const*>(
            reinterpret_cast<const char*>(&FUN_142508490(&GetTraits()).GetClassTraits()) + 0xc8))
            ->GetName().ToCStr()));
}
// @0x142559180
MS2_VEC_SORT(Vector_uint, FUN_142553170)

#undef MS2_VEC_SORT

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x142560d70
template <>
void VectorBase<Value>::Insert(UPInt pos, unsigned argc, const Value* argv)
{
    for (UPInt i = 0; i < argc; ++i)
        V.InsertAt(pos + i, Value(argv[i]));
}

// @0x1425614e0
CheckResult ArrayBase::OfCorrectType(const Instances::fl::Array& arr, const ClassTraits::Traits& tr) const
{
    for (unsigned i = 0; i < arr.GetSize(); ++i)
    {
        if (!FUN_1425149a0(tr, FUN_142507f60(VMRef, arr.At(i))))
            return false;
    }
    return true;
}

// @0x142561570
CheckResult ArrayBase::OfCorrectType(unsigned argc, const Value* argv, const ClassTraits::Traits& tr) const
{
    for (unsigned i = 0; i < argc; ++i)
    {
        if (!FUN_1425149a0(tr, FUN_142507f60(VMRef, argv[i])))
            return false;
    }
    return true;
}

namespace InstanceTraits { namespace fl_vec {

// @0x142560ef0
__declspec(noinline) SPtr<Vector_String::InstanceType> Vector_String::MakeInstanceS(Vector_String& t)
{
    return MakeInstance(t);
}

// @0x142560f90
__declspec(noinline) SPtr<Vector_double::InstanceType> Vector_double::MakeInstanceS(Vector_double& t)
{
    return MakeInstance(t);
}

// @0x142561030
__declspec(noinline) SPtr<Vector_int::InstanceType> Vector_int::MakeInstanceS(Vector_int& t)
{
    return MakeInstance(t);
}

// @0x1425610d0
__declspec(noinline) SPtr<Vector_object::InstanceType> Vector_object::MakeInstanceS(Vector_object& t)
{
    return MakeInstance(t);
}

// @0x142561170
__declspec(noinline) SPtr<Vector_uint::InstanceType> Vector_uint::MakeInstanceS(Vector_uint& t)
{
    return MakeInstance(t);
}

// @0x142561210
void Vector_String::MakeObject(Value& result, Traits& t)
{
    result.Pick(MakeInstance(static_cast<Vector_String&>(t)));
}

// @0x1425612a0
void Vector_double::MakeObject(Value& result, Traits& t)
{
    result.Pick(MakeInstance(static_cast<Vector_double&>(t)));
}

// @0x142561330
void Vector_int::MakeObject(Value& result, Traits& t)
{
    result.Pick(MakeInstance(static_cast<Vector_int&>(t)));
}

// @0x1425613c0
void Vector_object::MakeObject(Value& result, Traits& t)
{
    result.Pick(MakeInstance(static_cast<Vector_object&>(t)));
}

// @0x142561450
void Vector_uint::MakeObject(Value& result, Traits& t)
{
    result.Pick(MakeInstance(static_cast<Vector_uint&>(t)));
}

}}}}} // namespace Scaleform::GFx::AS3::InstanceTraits::fl_vec

// ---------------------------------------------------------------- SoundObject

#include "ms2/scaleform/include/gfx/as3/as3_soundobject.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace {

// The movie's sound player; the Audio state is only held for the call.
inline Sound::SoundRenderer* GetSoundRenderer(MovieImpl* pmovie)
{
    Ptr<AudioBase> paudio = *(AudioBase*)pmovie->GetStateBag()->GetStateAddRef(State::State_Audio);
    if (!paudio)
        return 0;
    return paudio->GetRenderer();
}

// The stage's root (the main timeline): MovieRoot +0x158 is the Stage, the Stage's root is at +0x110.
inline DisplayObjContainer* GetMainTimeline(ASVM& asvm)
{
    const UByte* pstage = *(UByte* const*)((const UByte*)asvm.GetMovieRoot() + 0x158);
    return *(DisplayObjContainer* const*)(pstage + 0x110);
}

} // namespace

// @0x142564d80
// MS2-FUNCTIONAL: exe inlines AttachToTarget into the ctor and keeps a smaller EH frame; same fields set, same sprite attach
SoundObject::SoundObject(ASVM& asvm, Instances::fl_media::Sound* psound) : Volume(100), Pan(0)
{
    pMovieRoot = asvm.GetMovieImpl();
    DisplayObjContainer* pobj = GetMainTimeline(asvm);
    if (pobj && pobj->IsSprite())
        AttachToTarget(static_cast<Sprite*>(pobj));
    pSound = psound;
}

// @0x142564ea0
SoundObject::~SoundObject()
{
    DetachFromTarget();
}

// @0x142565140
void SoundObject::AttachResource(SoundResource* presource)
{
    Sound::SoundRenderer* pplayer = GetSoundRenderer(pMovieRoot);
    if (!pplayer)
        return;
    if (presource && presource->GetResourceType() == Resource::RT_SoundSample)
    {
        pResource = presource;
        pSample   = pResource->GetSoundInfo()->GetSoundSample(pplayer);
    }
}

// @0x142565230
void SoundObject::AttachToTarget(Sprite* psprite)
{
    pTargetHandle = psprite->GetCharacterHandle();
    psprite->AttachSoundObject(this);
}

// @0x1425652c0
void SoundObject::DetachFromTarget()
{
    if (!pTargetHandle)
        return;
    Sprite* psprite = GetSprite();
    if (psprite)
        psprite->DetachSoundObject(this);
}

// @0x142565310
void SoundObject::ExecuteOnSoundComplete()
{
    pSound->DispatchEventSoundComplete();
}

// @0x142565320
unsigned SoundObject::GetBytesLoaded()
{
    if (pSample)
        return pSample->GetBytesLoaded();
    return 0;
}

// @0x142565340
unsigned SoundObject::GetBytesTotal()
{
    if (pSample)
        return pSample->GetBytesTotal();
    return 0;
}

// @0x142565360
float SoundObject::GetDuration()
{
    if (pSample)
        return pSample->GetDuration() * 1000.f;
    return 0;
}

// @0x142565390
int SoundObject::GetPan()
{
    return Pan;
}

// @0x1425653a0
float SoundObject::GetPosition()
{
    Sprite* psprite = GetSprite();
    if (psprite)
        return psprite->GetActiveSoundPosition(this) * 1000.f;
    return 0;
}

// @0x142565400
Sprite* SoundObject::GetSprite()
{
    DisplayObject* ptarget = pTargetHandle->ResolveCharacter(pMovieRoot);
    if (!ptarget)
        return 0;
    return ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0;
}

// @0x142565440
int SoundObject::GetVolume()
{
    return Volume;
}

// @0x142565470
void SoundObject::LoadFile(const String& url, bool streaming)
{
    Sprite* psprite = GetSprite();
    if (!psprite)
        return;
    Sound::SoundRenderer* pplayer = GetSoundRenderer(pMovieRoot);
    if (!pplayer)
        return;

    pSound->DispatchEventOpen();
    Ptr<LoadStates> pls = *new LoadStates(pMovieRoot->pMainMovieDef->pLoaderImpl, pMovieRoot->pStateBag);
    String level0Path;
    pMovieRoot->GetMainMoviePath(&level0Path);
    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, url, level0Path);
    String fileName;
    pls->BuildURL(&fileName, loc);
    Ptr<Sound::SoundSample> psample = *pplayer->CreateSampleFromFile(fileName.ToCStr(), streaming);
    if (!psample)
        pSound->DispatchEventIOError();
    else
    {
        pSample   = psample;
        pResource = 0;
        pSound->DispatchEventComplete();
    }
}

// @0x142565720
void SoundObject::Play(int startTime, int loops)
{
    Sprite* psprite = GetSprite();
    if (!psprite)
        return;
    Sound::SoundRenderer* pplayer = GetSoundRenderer(pMovieRoot);
    if (!pplayer)
        return;

    if (loops == 0)
        loops = 1;
    if (pSample)
    {
        Ptr<Sound::SoundChannel> pchan = *pplayer->PlaySample(pSample, true);
        if (pchan)
        {
            if (startTime > 0 || loops > 0)
                pchan->Loop(loops, startTime / 1000.f);
            Volume = psprite->GetSoundVolume();
            pchan->SetVolume(Volume / 100.f);
            Pan = psprite->GetSoundPan();
            pchan->SetPan(Pan / 100.f);
            pchan->Pause(false);
            psprite->AddActiveSound(pchan, this, pResource);
        }
    }
}

// @0x1425658e0
void SoundObject::ReleaseTarget()
{
    pTargetHandle = 0;
}

// @0x142565940
void SoundObject::SetPan(int pan)
{
    Pan = pan;
    Sprite* psprite = GetSprite();
    if (psprite)
        psprite->UpdateActiveSoundPan();
}

// @0x142565980
void SoundObject::SetVolume(int volume)
{
    Volume = volume;
    Sprite* psprite = GetSprite();
    if (psprite)
        psprite->UpdateActiveSoundVolume();
}

// @0x1425659c0
void SoundObject::Stop()
{
    Sprite* psprite = GetSprite();
    if (psprite)
    {
        if (pResource)
            psprite->StopActiveSounds(pResource);
        else
            psprite->StopActiveSounds(this);
    }
}

}}} // namespace Scaleform::GFx::AS3

// The exe keeps the pointer tables' Resize (PopBack) out of line; spelled out per element type.
#define MS2_ABC_RESIZE_NOINLINE(T) \
    template<> __declspec(noinline) void Scaleform::ArrayData<T, \
        Scaleform::AllocatorLH_POD<T, Scaleform::GFx::AS3::StatMV_VM_AbcFile_Mem>, Scaleform::ArrayDefaultPolicy>::Resize(UPInt newSize) \
    { \
        BaseType::ResizeNoConstruct(this, newSize); \
    }

MS2_ABC_RESIZE_NOINLINE(Scaleform::GFx::AS3::Abc::ClassInfo*)      // @0x1425683a0

// ==== Abc::Reader (AS3_Abc_Read) ======================================================================================

namespace Scaleform { namespace GFx { namespace AS3 { namespace Abc {

// @0x142565a30
bool Read(const UInt8*& ptr, MethodInfo& obj)
{
    bool result = true;

    SInt32 param_count = 0;
    result = result &&
        Read(ptr, param_count) &&
        Read(ptr, obj.RetTypeInd);

    result = result && (obj.RetTypeInd >= 0);
    if (!result)
        return result;

    obj.ParamTypes.Reserve(param_count);
    for (int i = 0; i < param_count; ++i)
        obj.ParamTypes.PushBack(ReadU30(ptr));

    // The name is not used.
    SInt32 name_ind;
    result = result &&
        Read(ptr, name_ind) &&
        Read8(ptr, obj.Flags);

    if (!result)
        return result;

    if (obj.HasOptionalParams())
    {
        SInt32 count = 0;
        result = result && Read(ptr, count);

        obj.OptionalParams.Reserve(count);
        for (int i = 0; result && (i < count); ++i)
        {
            ValueDetail detail;

            result = result && Read(ptr, detail);
            if (!result)
                return result;

            obj.OptionalParams.PushBack(detail);
        }
    }

    if (obj.HasParamNames())
    {
        obj.ParamNames.Reserve(param_count);
        for (int i = 0; i < param_count; ++i)
        {
            SInd ind = 0;
            result = result && Read(ptr, ind);

            if (result)
                obj.ParamNames.PushBack(ind);
            else
                break;
        }
    }

    return result;
}

// @0x142565c50
bool Read(const UInt8*& ptr, ValueDetail& obj)
{
    bool result = true;

    UInt8 kind = 0;
    result = result &&
        Read(ptr, obj.ValueIndex) &&
        Read8(ptr, kind);

    result = result && (obj.ValueIndex >= 0);

    obj.Kind = static_cast<ValueKind>(kind);

    return result;
}

// @0x142565c90
bool Reader::Read(Code& obj)
{
    bool result = true;

    obj.code = StringView(CP);

    SInt32 count = 0;
    result = result && Read(count);
    CP += count;

    return result;
}

// @0x142565cc0
// MS2-FUNCTIONAL: string constants copy through extra stack temporaries (sf_string.h StringDataPtr lacks the SDK copy ctor); frame/register allocation differs
bool Reader::Read(ConstPool& obj)
{
    bool result = true;
    UInt32 number = 0;

    // int
    result = result && Read(number);
    if (result)
    {
        obj.ConstInt.Reserve(number);
        obj.ConstInt.PushBack(0);

        for (UInt32 i = 1; i < number; ++i)
            obj.ConstInt.PushBack(ReadU30(CP));
    }

    // uint
    number = 0;
    result = result && Read(number);
    if (result)
    {
        obj.ConstUInt.Reserve(number);
        obj.ConstUInt.PushBack(0);

        for (UInt32 i = 1; i < number; ++i)
            obj.ConstUInt.PushBack(ReadU30(CP));
    }

    // double: kept in place
    obj.DoubleCount = 0;
    obj.ConstDouble = NULL;
    result = result && Read(obj.DoubleCount);
    if (result)
    {
        obj.ConstDouble = CP;
        if (obj.DoubleCount)
            CP += 8 * (obj.DoubleCount - 1);
    }

    // string: kept in place
    number = 0;
    result = result && Read(number);
    if (result)
    {
        obj.ConstStr.Reserve(number);
        obj.ConstStr.PushBack(StringView());

        for (UInt32 i = 0; number > 0 && i < number - 1; ++i)
        {
            obj.ConstStr.PushBack(StringView(CP));
            const int size = ReadU30(CP);
            CP += size;
        }
    }

    // namespace
    number = 0;
    result = result && Read(number);
    if (result)
    {
        obj.ConstNamespace.Reserve(number);
        obj.ConstNamespace.PushBack(NamespaceInfo(NS_Public, ""));

        for (UInt32 i = 1; i < number; ++i)
        {
            NamespaceInfo info(NS_Public, "");

            result = result && Read(obj, info);
            obj.ConstNamespace.PushBack(info);
        }
    }

    // namespace set
    number = 0;
    result = result && Read(number);
    if (result)
    {
        obj.const_ns_set.Reserve(number);
        obj.const_ns_set.PushBack(NamespaceSetInfo());

        obj.const_ns_set.Back().Data = NULL;

        NamespaceSetInfo info;
        for (UInt32 i = 1; i < number; ++i)
        {
            result = result && Read(info);
            obj.const_ns_set.PushBack(info);
        }
    }

    // multiname
    number = 0;
    result = result && Read(number);
    if (result)
    {
        obj.const_multiname.Reserve(number + 1);
        const Multiname any = {MNF_QName, -1, 0, -1};
        obj.const_multiname.PushBack(any);

        for (UInt32 i = 1; i < number; ++i)
        {
            Multiname info = {MNF_QName, -1, 0, -1};

            result = result && Read(obj, info);
            obj.const_multiname.PushBack(info);
        }
    }

    return result;
}

// @0x142566460
bool Reader::Read(MethodBodyInfo::Exception& obj)
{
    bool result = true;

    SInt32 count = 0;
    result = result && Read(count);

    obj.info.Reserve(count);
    for (int i = 0; result && (i < count); ++i)
    {
        MethodBodyInfo::ExceptionInfo info;

        result = result && Read(info);
        if (!result)
            break;

        obj.info.PushBack(info);
    }

    return result;
}

// @0x142566570
bool Reader::Read(MethodBodyInfo::ExceptionInfo& obj)
{
    bool result = true;

    result = result &&
        Read(obj.from) &&
        Read(obj.to) &&
        Read(obj.target) &&
        Read(obj.exc_type_ind) &&
        Read(obj.var_name_ind);

    return result;
}

// @0x1425667f0
bool Reader::Read(Instance::Interfaces& obj)
{
    bool result = true;

    SInt32 count = 0;
    result = result && Read(count);

    obj.info.Reserve(count);
    for (int i = 0; i < count; ++i)
        obj.info.PushBack(ReadU30(CP));

    return result;
}

// @0x1425668b0
bool Reader::Read(MetadataInfo::Item& obj)
{
    bool result = true;

    result = result &&
        Read(obj.KeyInd) &&
        Read(obj.ValueInd);

    return result;
}

// @0x1425668f0
bool Reader::Read(TraitInfo::MetaInfo& obj)
{
    bool result = true;

    SInt32 count = 0;
    result = result && Read(count);

    SInd ind;
    obj.info.Reserve(count);
    for (int i = 0; i < count; ++i)
    {
        Read(ind);
        obj.info.PushBack(ind);
    }

    return result;
}

// @0x1425669b0
// MS2-FUNCTIONAL: 1 prologue byte, rbx/item home-slot assignment swapped
bool Reader::Read(MetadataInfo& obj)
{
    // The name is not kept.
    SInt32 name_ind;
    Read(name_ind);

    SInt32 count;
    Read(count);

    obj.Items.Reserve(count);
    for (int i = 0; i < count; ++i)
    {
        MetadataInfo::Item item;
        Read(item);
        obj.Items.PushBack(item);
    }

    return true;
}

// @0x142566a80
// MS2-FUNCTIONAL: inlined Read(MetadataInfo) home-slot assignment differs (same as 0x1425669b0)
bool Reader::Read(MetadataTable& obj)
{
    SInt32 count;
    Read(count);

    obj.Info.Reserve(count);
    for (int i = 0; i < count; ++i)
    {
        obj.Info.PushBack(SF_HEAP_AUTO_NEW(this) MetadataInfo());
        Read(*obj.Info.Back());
    }

    return true;
}

// @0x142566c30
bool Reader::Read(MethodTable& obj)
{
    bool result = true;

    SInt32 count = 0;
    result = result && Read(count);

    obj.Info.Reserve(count);
    for (int i = 0; result && (i < count); ++i)
    {
        obj.Info.PushBack(SF_HEAP_AUTO_NEW(this) MethodInfo());

        result = result && Read(*obj.Info.Back());
        if (!result)
        {
            delete obj.Info.Back();
            obj.Info.PopBack();
            break;
        }
    }

    return result;
}

// @0x142566de0
bool Reader::Read(NamespaceSetInfo& obj)
{
    bool result = true;

    SInt32 entry = 0;
    UInt32 size = 0;

    obj.Data = CP;
    result = result && Read(size);

    for (UInt32 i = 0; result && (i < size); ++i)
    {
        result = result && Read(entry);

        if (!result || (entry == 0))
            return false;
    }

    return result;
}

// @0x142566e40
// MS2-FUNCTIONAL: exe lowers the trait-kind switch to a jump table, this build to compare chains
bool Reader::Read(TraitInfo& obj)
{
    bool result = true;

    result = result &&
        Read(obj.name_ind) &&
        Read8(obj.kind);

    result = result && (obj.name_ind >= 0);
    if (!result)
        return result;

    switch (obj.GetType())
    {
    case TraitInfo::tMethod:
    case TraitInfo::tGetter:
    case TraitInfo::tSetter:
    case TraitInfo::tClass:
    case TraitInfo::tFunction:
        result = result &&
            Read(obj.SlotId) &&
            Read(obj.Ind);

        result = result && (obj.SlotId >= 0) && (obj.Ind >= 0);
        break;
    case TraitInfo::tSlot:
    case TraitInfo::tConst:
        {
            SInd vindex = 0;

            result = result &&
                Read(obj.SlotId) &&
                Read(obj.Ind) &&
                Read(vindex);

            if (!result)
                return result;

            if (vindex)
            {
                UInt8 kind = 0;
                result = result && Read8(kind);

                if (!IsValidValueKind(kind))
                    result = false;

                obj.default_value = ValueDetail(vindex, static_cast<ValueKind>(kind));
            }
        }
        break;
    default:
        result = false;
        break;
    }

    if (!result)
        return result;

    if (TraitInfo::HasMetaData(obj.kind))
        result = result && Read(obj.meta_info);

    return result;
}

// @0x142566fe0
bool Reader::Read(TraitTable& t, ClassTable& obj)
{
    bool result = true;

    SInt32 count = 0;
    int i;

    result = result && Read(count);

    obj.Info.Reserve(count);
    for (i = 0; result && (i < count); ++i)
    {
        obj.Info.PushBack(SF_HEAP_AUTO_NEW(this) ClassInfo());

        Instance& inst_info = obj.Info.Back()->inst_info;

        result = result && Read(t, inst_info);
        if (!result)
        {
            delete obj.Info.Back();
            obj.Info.PopBack();
            break;
        }
    }

    for (i = 0; result && (i < count); ++i)
    {
        StaticInfo& stat_info = obj.Info[i]->stat_info;

        result = result && Read(t, stat_info);
    }

    return result;
}

// @0x1425672f0
bool Reader::Read(TraitTable& t, HasCode& obj)
{
    bool result = true;

    result = result &&
        Read(obj.method_info_ind) &&
        Read(t, static_cast<HasTraits&>(obj));

    result = result && (obj.method_info_ind >= 0);

    return result;
}

// @0x142567360
bool Reader::Read(TraitTable& t, Instance& obj)
{
    bool result = true;

    result = result &&
        Read(obj.name_ind) &&
        Read(obj.super_name_ind) &&
        Read8(obj.flags);

    result = result && (obj.name_ind >= 0) && (obj.super_name_ind >= 0);

    if (obj.HasProtectedNamespace())
        result = result && Read(obj.protected_namespace_ind);

    result = result &&
        Read(obj.implemented_interfaces) &&
        Read(t, static_cast<HasCode&>(obj));

    return result;
}

// @0x1425674b0
bool Reader::Read(TraitTable& t, MethodBodyInfo& obj)
{
    bool result = true;

    result = result &&
        Read(obj.method_info_ind) &&
        Read(obj.max_stack) &&
        Read(obj.local_reg_count) &&
        Read(obj.init_scope_depth) &&
        Read(obj.max_scope_depth) &&
        Read(obj.code) &&
        Read(obj.exception) &&
        Read(t, static_cast<HasTraits&>(obj));

    result = result && (obj.method_info_ind >= 0);

    return result;
}

// @0x142567670
bool Reader::Read(TraitTable& t, MethodTable& mt, MethodBodyTable& obj)
{
    bool result = true;

    SInd count = 0;
    result = result && Read(count);

    obj.Info.Reserve(count);
    for (SInd i = 0; i < count; ++i)
    {
        obj.Info.PushBack(SF_HEAP_AUTO_NEW(this) MethodBodyInfo());
        MethodBodyInfo& mbi = *obj.Info.Back();

        result = result && Read(t, mbi);
        if (result)
        {
            // Link the method to its body.
            mt.Info[mbi.method_info_ind]->MethodBodyInfoInd = i;
        }
        else
        {
            delete obj.Info.Back();
            obj.Info.PopBack();
            break;
        }
    }

    return result;
}

// @0x1425665d0
bool Reader::Read(File& obj)
{
    bool result = true;

    obj.Clear();

    result = result &&
        Read16(obj.MinorVersion) &&
        Read16(obj.MajorVersion);

    result = result && (obj.MajorVersion == 46) && (obj.MinorVersion == 16);

    result = result &&
        Read(obj.Const_Pool) &&
        Read(obj.Methods) &&
        Read(obj.Metadata) &&
        Read(obj.Traits, obj.AS3_Classes) &&
        Read(obj.Traits, obj.Scripts) &&
        Read(obj.Traits, obj.Methods, obj.MethodBodies);

    return result;
}

// @0x1425677f0
bool Reader::Read(TraitTable& t, ScriptInfo& obj)
{
    bool result = true;

    result = Read(t, static_cast<HasCode&>(obj));

    return result;
}

// @0x142567850
bool Reader::Read(TraitTable& t, ScriptTable& obj)
{
    bool result = true;

    SInt32 count = 0;
    result = result && Read(count);

    obj.Info.Reserve(count);
    for (int i = 0; i < count; ++i)
    {
        obj.Info.PushBack(SF_HEAP_AUTO_NEW(this) ScriptInfo());

        result = result && Read(t, *obj.Info.Back());
        if (!result)
        {
            delete obj.Info.Back();
            obj.Info.PopBack();
            break;
        }
    }

    return result;
}

// @0x1425679e0
bool Reader::Read(TraitTable& t, StaticInfo& obj)
{
    bool result = true;

    result = Read(t, static_cast<HasCode&>(obj));

    return result;
}

// @0x142567a40
bool Reader::Read(const ConstPool& cp, Multiname& obj)
{
    bool result = true;
    String any_name("*");
    UInt8 kind = 0;

    result = result && Read8(kind);

    // Decode the AbcKind into the flag-encoded multiname kind.
    MultinameFlagKind mnKind;
    switch (static_cast<AbcKind>(kind))
    {
    case AbcKind_Qname:       mnKind = MNF_QName; break;
    case AbcKind_QnameA:      mnKind = MNF_QNameA; break;
    case AbcKind_RTQname:     mnKind = MNF_RTQName; break;
    case AbcKind_RTQnameA:    mnKind = MNF_RTQNameA; break;
    case AbcKind_RTQnameL:    mnKind = MNF_RTQNameL; break;
    case AbcKind_RTQnameLA:   mnKind = MNF_RTQNameLA; break;
    case AbcKind_Multiname:   mnKind = MNF_Multiname; break;
    case AbcKind_MultinameL:  mnKind = MNF_MultinameL; break;
    case AbcKind_MultinameA:  mnKind = MNF_MultinameA; break;
    case AbcKind_MultinameLA: mnKind = MNF_MultinameLA; break;
    case AbcKind_TypeName:    mnKind = MNF_Typename; break;
    default:
        mnKind = MNF_Invalid;
        result = false;
        break;
    }
    obj.Kind = mnKind;

    switch (mnKind)
    {
    case MNF_QName:
    case MNF_QNameA:
        result = result &&
            Read(obj.Ind) &&
            Read(obj.NameIndex);
        break;
    case MNF_RTQName:
    case MNF_RTQNameA:
        result = result &&
            Read(obj.NameIndex);
        break;
    case MNF_RTQNameL:
    case MNF_RTQNameLA:
        break;
    case MNF_Multiname:
    case MNF_MultinameA:
        result = result &&
            Read(obj.NameIndex) &&
            Read(obj.Ind);
        break;
    case MNF_MultinameL:
    case MNF_MultinameLA:
        result = result &&
            Read(obj.Ind);
        break;
    case MNF_Typename:
        {
            SInt32 ind = 0;

            // The type in the constant pool.
            result = result && Read(ind);
            if (!result)
                break;

            obj = cp.GetMultiname(ind);

            result = result && Read(ind);
            result = result && (ind == 1);
            if (!result)
                break;

            result = result && Read(obj.NextIndex);
        }
        break;
    default:
        break;
    }

    if (!result)
        obj.Kind = MNF_Invalid;

    return result;
}

// @0x142567c60
// MS2-FUNCTIONAL: uri string view copies through an extra stack temporary (sf_string.h StringDataPtr lacks the SDK copy ctor)
bool Reader::Read(const ConstPool& cp, NamespaceInfo& obj)
{
    bool result = true;

    UInt8 kind = 0;

    result = result &&
        Read8(kind) &&
        Read(cp, obj.NameURI, "");

    switch (static_cast<AbcKind>(kind))
    {
    case AbcKind_Namespace:
    case AbcKind_PackageNamespace:
        obj.Kind = NS_Public;
        break;
    case AbcKind_PackageInternalNs:
        obj.Kind = NS_PackageInternal;
        break;
    case AbcKind_ProtectedNamespace:
        obj.Kind = NS_Protected;
        break;
    case AbcKind_ExplicitNamespace:
        obj.Kind = NS_Explicit;
        break;
    case AbcKind_StaticProtectedNs:
        obj.Kind = NS_StaticProtected;
        break;
    case AbcKind_PrivateNs:
        // Each class has its own private namespace.
        obj.Kind = NS_Private;
        break;
    default:
        result = false;
        break;
    }

    return result;
}

// @0x142567df0
// MS2-FUNCTIONAL: the exe copies the converted string view through one more stack temporary (sf_string.h StringDataPtr lacks the SDK's user copy ctor)
bool Reader::Read(const ConstPool& cp, StringDataPtr& obj, const StringDataPtr& zero_val)
{
    UInt32 ind;
    Read(ind);

    if (ind == 0)
        obj = zero_val;
    else
        obj = cp.GetString(ind);

    return true;
}

// @0x142567e60
bool Reader::ReadTraits(TraitTable& t, HasTraits::ObjectTraits& obj_traits)
{
    bool result = true;

    SInd count = 0;
    result = result && Read(count);

    obj_traits.Reserve(count);
    t.TraitInfos.Reserve(t.TraitInfos.GetSize() + count);
    for (int i = 0; i < count; ++i)
    {
        obj_traits.PushBack(static_cast<SInd>(t.TraitInfos.GetSize()));
        t.TraitInfos.PushBack(SF_HEAP_AUTO_NEW(this) TraitInfo());

        result = result && Read(*t.TraitInfos.Back());
        if (!result)
        {
            obj_traits.PopBack();
            delete t.TraitInfos.Back();
            t.TraitInfos.PopBack();
            break;
        }
    }

    return result;
}

}}}} // namespace Scaleform::GFx::AS3::Abc

// ---------------------------------------------------------------- Vector.<*>.unshift (sfr19)

namespace Scaleform { namespace GFx { namespace AS3 {

// Visits the collectable a value holds (0x142504530).
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner);

// @0x1425649c0
template <>
void VectorBase<Value>::Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    V.InsertMultipleAt(0, argc);
    for (unsigned i = 0; i < argc; ++i)
        V[i] = Value(argv[i]);
}

// @0x142563e40
template <>
__declspec(noinline) void VectorBase<Value>::SetUnsafe(UInt32 ind, const Value& v)
{
    V[ind] = Value(v);
}

// @0x142563a00
// MS2-FUNCTIONAL: size compares scheduled differently
template <>
__declspec(noinline) CheckResult VectorBase<Value>::Set(UInt32 ind, const Value& v, const ClassTraits::Traits& tr)
{
    if ((Fixed && ind >= (UInt32)V.GetSize()) || ind > (UInt32)V.GetSize())
    {
        VM& vm = VMRef;
        vm.ThrowRangeError(VM::Error(VM::eInvalidRangeError, vm, (int)ind, (int)V.GetSize() - 1));
        return false;
    }
    if (ind == (UInt32)V.GetSize() && !Resize(ind + 1))
        return false;
    Value r;
    if (!CheckCoerce(tr, v, r))
        return false;
    SetUnsafe(ind, r);
    return true;
}

namespace Instances { namespace fl_vec {

// @0x142563cd0
CheckResult Vector_object::SetProperty(const Multiname& prop_name, const Value& value)
{
    UInt32 ind;
    if (GetVectorInd(prop_name, ind))
        return V.Set(ind, value, static_cast<const ClassTraits::fl_vec::Vector_object&>(
            FUN_142508490(&GetTraits()).GetClassTraits()).GetEnclosedClassTraits());
    VM& vm = GetVM();
    vm.ThrowReferenceError(VM::Error(VM::eWriteSealedError, vm, prop_name.Name, GetTraits().GetName().ToCStr()));
    return false;
}

// @0x142559890
void Vector_object::AS3unshift(Value& result, unsigned argc, const Value* argv)
{
    V.Unshift(argc, argv, static_cast<const ClassTraits::fl_vec::Vector_object&>(
        FUN_142508490(&GetTraits()).GetClassTraits()).GetEnclosedClassTraits());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x14255c220
void Vector_object::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Object::ForEachChild_GC(prcc, op);
    for (UPInt i = 0, n = V.V.GetSize(); i < n; ++i)
    {
        const Value& v = V.V[i];
        if (v.IsGarbageCollectable() && !v.IsWeakRef())
            ForEachChild_GC_Internal(prcc, v, op, *this);
    }
}

}} // namespace Instances::fl_vec

// @0x142559b40
void ArrayBase::Append(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(argc, argv, tr))
        return;
    for (UPInt i = 0; i < argc; ++i)
        PushBackValueUnsafe(argv[i]);
}

// @0x14255b0c0
// MS2-FUNCTIONAL: error-path temporaries in other stack slots
CheckResult ArrayBase::CheckArgTypes(const Instances::fl::Array& arr, const ClassTraits::Traits& tr) const
{
    for (UInt32 i = 0; i < arr.GetSize(); ++i)
    {
        if (!FUN_1425149a0(tr, FUN_142507f60(VMRef, arr.At(i))))
        {
            VM& vm = VMRef;
            vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, arr.GetTraits().GetName().ToCStr(),
                                        tr.GetName().ToCStr()));
            return false;
        }
    }
    return true;
}

// @0x1425599b0
// MS2-FUNCTIONAL: type-check loop counter and size registers swapped
void ArrayBase::Append(const Instances::fl::Array& arr, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed || !CheckArgTypes(arr, tr))
        return;
    for (UPInt i = 0; i < arr.GetSize(); ++i)
        PushBackValueUnsafe(arr.At(i));
}

}}} // namespace Scaleform::GFx::AS3

// ---------------------------------------------------------------- Vector.<T> append (sfr19)

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// @0x142559c00
void Vector_String::Append(const Vector_String& other) { V.Append(other.V); }
// @0x142559cd0
void Vector_double::Append(const Vector_double& other) { V.Append(other.V); }
// @0x142559dc0
void Vector_int::Append(const Vector_int& other) { V.Append(other.V); }
// @0x142559eb0
void Vector_object::Append(const Vector_object& other) { V.Append(other.V); }
// @0x142559fc0
void Vector_uint::Append(const Vector_uint& other) { V.Append(other.V); }

// @0x1425621c0
void Vector_String::PushBack(ASStringNode* v) { V.PushBack(v); }
// @0x142562280
void Vector_double::PushBack(Value::Number v) { V.PushBack(v); }
// @0x142562340
void Vector_int::PushBack(SInt32 v) { V.PushBack(v); }
// @0x1425623f0
void Vector_object::PushBack(const Value& v) { V.PushBack(v); }
// @0x142562470
void Vector_uint::PushBack(UInt32 v) { V.PushBack(v); }

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

// ---------------------------------------------------------------- Vector.push (sfr19)

namespace Scaleform { namespace GFx { namespace AS3 {

#define MS2_VEC_PUSHBACK(T)                                                                                 \
template <>                                                                                                 \
void VectorBase<T>::PushBack(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)               \
{                                                                                                           \
    CheckFixed();                                                                                           \
    if (Fixed)                                                                                              \
        return;                                                                                             \
    for (unsigned i = 0; i < argc; ++i)                                                                     \
    {                                                                                                       \
        Value r;                                                                                            \
        if (!CheckCoerce(tr, argv[i], r))                                                                   \
            break;                                                                                          \
        PushBackUnsafe(r);                                                                                  \
    }                                                                                                       \
}

// @0x1425616b0
MS2_VEC_PUSHBACK(SInt32)
// @0x1425618d0
MS2_VEC_PUSHBACK(UInt32)
// @0x142561af0
MS2_VEC_PUSHBACK(Value::Number)
// @0x142561d20
MS2_VEC_PUSHBACK(Ptr<ASStringNode>)

// @0x142561f40
template <>
void VectorBase<Value>::PushBack(unsigned argc, const Value* argv, const ClassTraits::Traits& tr)
{
    CheckFixed();
    if (Fixed)
        return;
    for (unsigned i = 0; i < argc; ++i)
    {
        Value r;
        if (!CheckCoerce(tr, argv[i], r))
            break;
        V.PushBack(Value(r));
    }
}

#undef MS2_VEC_PUSHBACK

}}} // namespace Scaleform::GFx::AS3

// ---------------------------------------------------------------- Vector coercion (sfr19)

// Traits::GetConstructor, out of line in the exe (the InstanceTraits copy).
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
// MultinameHash<ClassTraits::Traits*>::Get (sfr_as3_04)
Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self,
    const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns);
// GlobalObject::AddFixedSlotValuePair (sfr_as3_03): a fixed slot name/ns of type ctr holding v; index receives it
const void* FUN_142403d70(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP* self, const Scaleform::GFx::ASString& name,
    Scaleform::Pickable<const Scaleform::GFx::AS3::Instances::Namespace> ns, const Scaleform::GFx::AS3::ClassTraits::Traits* ctr,
    const Scaleform::GFx::AS3::Value& v, Scaleform::UPInt& index);

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14255a0b0
void ArrayBase::AppendCoerce(const ArrayBase& arr, const ClassTraits::Traits& tr)
{
    if (!CheckFixed())
        return;
    const UInt32 size = arr.GetSize();
    for (UInt32 i = 0; i < size; ++i)
    {
        Value r;
        Value v;
        arr.GetValueUnsafe(i, v);
        if (!tr.Coerce(v, r))
        {
            VM& vm = VMRef;
            vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, FUN_14250ffc0(vm, v).GetName().ToCStr(),
                tr.GetName().ToCStr()));
            break;
        }
        PushBackValueUnsafe(r);
    }
}

// @0x14255a2d0
void ArrayBase::AppendCoerce(const Instances::fl::Array& arr, const ClassTraits::Traits& tr)
{
    if (!CheckFixed())
        return;
    const UPInt size = arr.GetSize();
    for (UPInt i = 0; i < size; ++i)
    {
        Value r;
        const Value& v = arr.At(i);
        if (!tr.Coerce(v, r))
        {
            VM& vm = VMRef;
            vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, FUN_14250ffc0(vm, v).GetName().ToCStr(),
                tr.GetName().ToCStr()));
            break;
        }
        PushBackValueUnsafe(r);
    }
}

// @0x14255a4b0
bool ArrayBase::AppendCoerce(const Value& v, const ClassTraits::Traits& tr)
{
    VM& vm = VMRef;
    const ClassTraits::Traits& ctr = FUN_142507f60(vm, v);
    if (FUN_1425149a0(ctr, vm.GetClassTraitsArray()))
    {
        AppendCoerce(*static_cast<const Instances::fl::Array*>(v.GetObject()), tr);
        return !VMRef.IsException();
    }
    if (FUN_1425149a0(ctr, *vm.TraitsVector_int) || FUN_1425149a0(ctr, *vm.TraitsVector_uint) ||
        FUN_1425149a0(ctr, *vm.TraitsVector_double) || FUN_1425149a0(ctr, *vm.TraitsVector_String) ||
        (ctr.GetTraitsType() == Traits_Vector_object && ctr.IsClassTraits()))
    {
        // Every Vector.<T> instance keeps its VectorBase at +0x38.
        const ArrayBase* a = reinterpret_cast<const ArrayBase*>(reinterpret_cast<const char*>(v.GetObject()) + 0x38);
        if (a)
        {
            AppendCoerce(*a, tr);
            return !vm.IsException();
        }
    }
    return false;
}

namespace Classes { namespace fl_vec {

// @0x14255a5c0
Class& Vector::ApplyTypeArgs(unsigned argc, const Value* argv)
{
    if (argc != 1)
    {
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eWrongTypeArgCountError, vm));
        return *this;
    }
    const Value& type = argv[0];
    if (!type.IsClass() && !type.IsNullOrUndefined())
    {
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eCorruptABCError, vm));
        return *this;
    }
    const Class& cl = type.IsNullOrUndefined()
        ? FUN_142508460(&GetVM().GetClassTraitsObject().GetInstanceTraits()) : type.AsClass();
    const ClassTraits::Traits& ctr = cl.GetClassTraits();
    VM& vm = GetVM();
    if (&ctr == &vm.GetClassTraitsSInt())
        return vm.GetClassVectorSInt();
    if (&ctr == &vm.GetClassTraitsUInt())
        return vm.GetClassVectorUInt();
    if (&ctr == &vm.GetClassTraitsNumber())
        return vm.GetClassVectorNumber();
    if (&ctr == &vm.GetClassTraitsString())
        return vm.GetClassVectorString();
    return FUN_142508460(&Resolve2Vector(ctr).GetInstanceTraits());
}

// The class traits of Vector.<elem>: looked up by name ("Vector$" + the element's name) in the vector namespace,
// else made and kept alive by the element's file, or for a builtin element class by a slot of the global object.
// @0x142563380
// MS2-FUNCTIONAL: the Vector name temporaries and the global slot arguments are made and released in another order
ClassTraits::Traits& Vector::Resolve2Vector(const ClassTraits::Traits& elem)
{
    VM& vm = GetVM();
    const ASString vname = GetClassTraits().GetName();
    const ASString name = vname + "$" + elem.GetName();

    ClassTraits::Traits** found = FUN_142414ac0(&vm.ClassTraitsSet, name, vm.GetVectorNamespace());
    if (found && *found)
        return **found;

    SPtr<ClassTraits::Traits> tr = Pickable<ClassTraits::Traits>(
        SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl_vec::Vector_object(vm, name, &elem));
    VMAbcFile* file = elem.GetFilePtr();
    if (file)
    {
        file->RegisterLoadedClass(tr);
        vm.ClassTraitsSet.Entries.Add(TClassTraitsCache::Key(name, &vm.GetVectorNamespace()), tr.GetPtr());
    }
    else
    {
        UPInt index = 0;
        Class& cl = FUN_142508460(&tr->GetInstanceTraits());
        FUN_142403d70(vm.GlobalObject.GetPtr(), cl.GetClassTraits().GetName(),
            Pickable<const Instances::Namespace>(&vm.GetVectorNamespace(), PickValue), &cl.GetClassTraits(),
            Value(&cl), index);
    }
    return *tr;
}

// Vector.<T>(v): v itself when it is null/undefined or already a Vector.<T>, else a new Vector.<T> of v's
// elements (an Array or another Vector) coerced to T; TypeError 1034 when v is neither.
#define MS2_VEC_CALL(TYPE, ELEM)                                                                            \
void TYPE::Call(const Value& /*_this*/, Value& result, unsigned argc, const Value* const argv)              \
{                                                                                                           \
    if (argc == 1)                                                                                          \
    {                                                                                                       \
        const Value& v = argv[0];                                                                           \
        InstanceTraits::fl_vec::TYPE& itr = static_cast<InstanceTraits::fl_vec::TYPE&>(GetInstanceTraits());\
        if (v.IsNullOrUndefined() || &FUN_14250ffc0(GetVM(), v) == &itr)                                    \
            result = v;                                                                                     \
        else                                                                                                \
        {                                                                                                   \
            SPtr<Instances::fl_vec::TYPE> p = itr.MakeInstanceS(itr);                                       \
            if (p->V.AppendCoerce(v, ELEM))                                                                 \
                result = p;                                                                                 \
            else                                                                                            \
            {                                                                                               \
                VM& vm = GetVM();                                                                           \
                vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, v, itr.GetName().ToCStr()));     \
            }                                                                                               \
        }                                                                                                   \
    }                                                                                                       \
    else                                                                                                    \
    {                                                                                                       \
        VM& vm = GetVM();                                                                                   \
        vm.ThrowRangeError(VM::Error(VM::eCoerceArgumentCountError, vm, (int)argc));                        \
    }                                                                                                       \
}

// @0x14255a700
// MS2-FUNCTIONAL: the exe keeps the new vector through the returned pointer and orders its stack temporaries differently
MS2_VEC_CALL(Vector_String, p->GetVM().GetClassTraitsString())
// @0x14255a8a0
// MS2-FUNCTIONAL: the exe keeps the new vector through the returned pointer and orders its stack temporaries differently
MS2_VEC_CALL(Vector_double, p->GetVM().GetClassTraitsNumber())
// @0x14255aa40
// MS2-FUNCTIONAL: the exe keeps the new vector through the returned pointer and orders its stack temporaries differently
MS2_VEC_CALL(Vector_int, p->GetVM().GetClassTraitsSInt())
// @0x14255abe0
// MS2-FUNCTIONAL: the exe keeps the new vector through the returned pointer and orders its stack temporaries differently
MS2_VEC_CALL(Vector_object, static_cast<const ClassTraits::fl_vec::Vector_object&>(
    FUN_142508490(&p->GetTraits()).GetClassTraits()).GetEnclosedClassTraits())
// @0x14255ad80
// MS2-FUNCTIONAL: the exe keeps the new vector through the returned pointer and orders its stack temporaries differently
MS2_VEC_CALL(Vector_uint, p->GetVM().GetClassTraitsUInt())

#undef MS2_VEC_CALL

}} // namespace Classes::fl_vec

namespace ClassTraits { namespace fl_vec {

// @0x14255c1d0
void Vector_object::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Traits::ForEachChild_GC(prcc, op);
    // The exe passes the owner as a third argument to the GcOp (r8); the shared GcOp typedef has two.
    typedef void (*GcOpWithOwner)(Collector* prcc, const ASRefCountBaseType** pchild, const ASRefCountBaseType& owner);
    if (EnclosedClassTraits.GetPtr())
        reinterpret_cast<GcOpWithOwner>(op)(prcc,
            reinterpret_cast<const ASRefCountBaseType**>(EnclosedClassTraits.GetRawPtr()), *this);
}

}} // namespace ClassTraits::fl_vec

}}} // namespace Scaleform::GFx::AS3

// ---- Vector.sort comparisons (sfr19): the string-key order and the call of an AS3 compare function, which the
// sorts in sfr_as3_20 keep out of line.
#include "ms2/scaleform/include/gfx/gfx_asutils.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_vec {

// Same definition as sfr_as3_20 (whose operator() orders the (key, index) pairs by Compare).
struct CompareAsStringInd
{
    CompareAsStringInd(bool desc, bool ci, bool loc) : Desc(desc), CaseInsensitive(ci), UseLocale(loc) {}
    SInt32 Compare(const ASString& a, const ASString& b) const;

    bool Desc;
    bool CaseInsensitive;
    bool UseLocale;
};

// @0x14255b4c0
// MS2-FUNCTIONAL: CaseInsensitive is read before the Desc test and the arguments live in other registers
SInt32 CompareAsStringInd::Compare(const ASString& a, const ASString& b) const
{
    if (UseLocale)
    {
        if (Desc)
            return b.LocaleCompare_CaseCheck(a.ToCStr(), a.GetLength(), !CaseInsensitive);
        return a.LocaleCompare_CaseCheck(b.ToCStr(), b.GetLength(), !CaseInsensitive);
    }
    const SInt32 r = CaseInsensitive ? String::CompareNoCase(a.ToCStr(), b.ToCStr()) : strcmp(a.ToCStr(), b.ToCStr());
    return Desc ? -r : r;
}

}} // namespace Instances::fl_vec

namespace Impl {

// funct(a, b) as a sign: <0, 0 or >0 (0 also when it threw or did not return a number).
// @0x14255b5d0
// MS2-FUNCTIONAL: the result and argument counter swap esi/edi; the sign of a nonzero result is selected in another order
int CompareFunct(VM& vm, const Value& funct, const Value& a, const Value& b)
{
    Value result;
    Value argv[2] = {a, b};
    vm.ExecuteInternalUnsafe(funct, Value::GetUndefined(), result, 2, argv, false);
    int r = 0;
    if (!vm.IsException())
    {
        Value::Number n;
        if (result.Convert2Number(n))
        {
            if (NumberUtil::IsNEGATIVE_INFINITY(n))
                r = -1;
            else if (NumberUtil::IsPOSITIVE_INFINITY(n))
                r = 1;
            else if (NumberUtil::IsNEGATIVE_ZERO(n))
                r = -1;
            else if (NumberUtil::IsPOSITIVE_ZERO(n))
                r = 1;
            else if (n != 0)
                r = n < 0 ? -1 : 1;
        }
    }
    return r;
}

} // namespace Impl

}}} // namespace Scaleform::GFx::AS3

// ---- Vector.sort array growth (sfr19): the out-of-line Reserve of the arrays the sort collectors fill
// (sfr_as3_20) and the PushBack of the string sort keys.

namespace Scaleform {
// A sort key and the index of the element it came from (same definition as sfr_as3_20).
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};

// @0x1425629a0
template void ArrayDataBase<const SInt32*, AllocatorDH<const SInt32*, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562a40
template void ArrayDataBase<const UInt32*, AllocatorDH<const UInt32*, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562ae0
template void ArrayDataBase<const GFx::AS3::Value::Number*, AllocatorDH<const GFx::AS3::Value::Number*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562b80
template void ArrayDataBase<const Ptr<GFx::ASStringNode>*, AllocatorDH<const Ptr<GFx::ASStringNode>*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562c20
template void ArrayDataBase<const GFx::AS3::Value*, AllocatorDH<const GFx::AS3::Value*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562cc0
template void ArrayDataBase<Pair<GFx::AS3::Value::Number, UInt32>, AllocatorDH<Pair<GFx::AS3::Value::Number, UInt32>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142562d60
template void ArrayDataBase<Pair<GFx::ASString, UInt32>, AllocatorDH<Pair<GFx::ASString, UInt32>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x1425615f0
template void ArrayBase<ArrayDataDH<Pair<GFx::ASString, UInt32>, AllocatorDH<Pair<GFx::ASString, UInt32>, 2>,
                                    ArrayDefaultPolicy> >::PushBack(const Pair<GFx::ASString, UInt32>&);
} // namespace Scaleform

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
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255d610
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
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255dff0
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
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255e8d0
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
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255f190
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
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbb0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbd0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BF@JKJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fbf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0BG@JKJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fcf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255fdf0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff10
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0N@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff30
// MS2-PIN: ?Func@?$ThunkFunc2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14255ff50
// MS2-PIN: ??_7ArrayBase@AS3@GFx@Scaleform@@6B@ 0x143181db8
// MS2-PIN: ??_7?$VectorBase@VValue@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181de0
// MS2-PIN: ??_7?$VectorBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181e08
// MS2-PIN: ??_7?$VectorBase@J@AS3@GFx@Scaleform@@6B@ 0x143181e30
// MS2-PIN: ??_7?$VectorBase@K@AS3@GFx@Scaleform@@6B@ 0x143182148
// MS2-PIN: ??_7?$VectorBase@N@AS3@GFx@Scaleform@@6B@ 0x143182460
// MS2-PIN: ??_7SoundObject@AS3@GFx@Scaleform@@6B?$RefCountBase@VSoundObject@AS3@GFx@Scaleform@@$0BED@@3@@ 0x143182f50
// MS2-PIN: ??_7SoundObject@AS3@GFx@Scaleform@@6BASSoundIntf@23@@ 0x143182f58
// MS2-PIN: ??_GSoundObject@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142565020
// MS2-PIN: ??_GASSoundIntf@GFx@Scaleform@@UEAAPEAXI@Z 0x142564ff0
// MS2-PIN: ??_G?$RefCountBase@VSoundObject@AS3@GFx@Scaleform@@$0BED@@Scaleform@@UEAAPEAXI@Z 0x142564f90
// MS2-PIN: ??_7ASSoundIntf@GFx@Scaleform@@6B@ 0x143182f18
// MS2-PIN: ??_7?$RefCountBase@VSoundObject@AS3@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x143182f48
// MS2-PIN: ?Reserve@?$ArrayDataBase@UItem@MetadataInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH@UItem@MetadataInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@6@UArrayDefaultPolicy@6@@Scaleform@@QEAAXPEBX_K@Z 0x142568260
// MS2-PIN: ?Reserve@?$ArrayDataBase@VValueDetail@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH@VValueDetail@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142568300
// MS2-PIN: ?Resize@?$ArrayData@PEAVClassInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVClassInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAX_K@Z 0x1425683a0
// The Vector_* instance classes carry no exe RTTI of their own: their vftables at the symbol rows' VAs.
// MS2-PIN: ??_7Vector_int@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143181e58
// MS2-PIN: ??_7Vector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182170
// MS2-PIN: ??_7Vector_double@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182488
// MS2-PIN: ??_7Vector_String@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182788
// MS2-PIN: ??_7Vector_object@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182a88
// Unreferenced COMDAT table with no exe copy of its own: the one VA the other Scaleform units pin it at.
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
