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
        GetValue(i, v);
        if (!v.IsNullOrUndefined() && !v.Convert2String(buf))
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
// MS2-FUNCTIONAL: Value temporaries/cleanup laid out differently
bool ArrayBase::Some(const Value& callback, const Value& thisObject, Instances::fl::Object* owner) const
{
    if (callback.IsNullOrUndefined() || !CheckCallable(callback))
        return false;
    Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
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
        if (result.AsBool())
            return true;
    }
    return false;
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
CheckResult VectorBase<SInt32>::Resize(UInt32 size)
{
    if (!CheckFixed())
        return false;
    UPInt i = V.GetSize();
    V.Resize(size);
    for (; i < size; ++i)
        V[i] = 0;
    return true;
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
CheckResult VectorBase<UInt32>::Resize(UInt32 size)
{
    if (!CheckFixed())
        return false;
    UPInt i = V.GetSize();
    V.Resize(size);
    for (; i < size; ++i)
        V[i] = 0;
    return true;
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
CheckResult VectorBase<Value::Number>::Resize(UInt32 size)
{
    if (!CheckFixed())
        return false;
    UPInt i = V.GetSize();
    V.Resize(size);
    for (; i < size; ++i)
        V[i] = 0;
    return true;
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
CheckResult VectorBase<Ptr<ASStringNode> >::Resize(UInt32 size)
{
    if (!CheckFixed())
        return false;
    UPInt i = V.GetSize();
    V.Resize(size);
    for (; i < size; ++i)
        V[i] = Ptr<ASStringNode>(VMRef.GetStringManager().GetBuiltin(AS3Builtin_null).GetNode());
    return true;
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

// @0x142563240
template <>
CheckResult VectorBase<Value>::Resize(UInt32 size)
{
    if (!CheckFixed())
        return false;
    UPInt i = V.GetSize();
    V.Resize(size);
    for (; i < size; ++i)
        V[i] = Value(Value::GetNull());
    return true;
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

// ---------------------------------------------------------------- SoundObject

#include "ms2/scaleform/include/gfx/as3/as3_soundobject.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"

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
