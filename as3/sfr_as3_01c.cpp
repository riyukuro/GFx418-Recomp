// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, AS3_Obj_All part 1: the class
// traits factories of the core top-level classes and the constructors of their class traits, instance traits, class
// objects and instances (the constructor block is in class-name order). Our own source, written from the exe. Third
// source of queue unit sfr_as3_01.
// MS2-UNIT: sfr_as3_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423e0260-0x1423f06a0 .text$mn
// MS2-RANGE: 0x1423f06a0-0x1423f3510 .text$mn
// MS2-RANGE: 0x1423f3570-0x1423f5770 .text$mn
// (0x1423f3510 ??_GInstance belongs with the Instance vftable, emitted by the ~Instance unit sfr_as3_16)
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_marshalling.h"
#include "ms2/scaleform/include/gfx/gfx_asutils.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_asstringhash.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fl.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fntraits.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_arraysort.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_vec_base.h"
#define XML_STATIC  // the exe links expat statically (libgfxexpat)
#include "../third_party/src/expat-2.0.1/lib/expat.h"

#if defined(__clang__)
#define SFR01C_INSTANCE_CTOR
#else
#define SFR01C_INSTANCE_CTOR inline
#endif

// The exe calls this ResizeNoConstruct instance out of line (explicitly instantiated in sfr_as3_04).
namespace Scaleform {
template<> SF_NOINLINE void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::Instances::fl::XML>,
    AllocatorLH<GFx::AS3::SPtr<GFx::AS3::Instances::fl::XML>, 2>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
}

// The core library's GlobalObject hash key is a borrowed C string. Keep this
// local declaration here: the shared AS3 headers do not expose the key type.
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {
struct ConstStringKey { const char* pChar; };
class ConstStringHashFn {
public:
    UPInt operator()(const ConstStringKey& key) const
    {
        return String::BernsteinHashFunction(key.pChar, strlen(key.pChar));
    }
};
}}}}}

// Out-of-line Traits::GetConstructor (InitOnDemand when the class is not built yet).
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);
// The class infos of the native function kinds' traits (no ABC file): plain and thunk function objects.
extern const Scaleform::GFx::AS3::ClassInfo DAT_14313dc60;
extern const Scaleform::GFx::AS3::ClassInfo DAT_14313dcb0;
// Out-of-line Traits::GetConstructor, second copy.
Scaleform::GFx::AS3::Class& FUN_142508490(const Scaleform::GFx::AS3::Traits* t);
// Out-of-line Value::SetBool copy (sfr_as3_04 0x142421710) that some natives call instead of inlining it.
void FUN_142421710(Scaleform::GFx::AS3::Value& v, bool b);
// VM::GetValueTraits.
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
// VM::GetGlobalObject (sfr_as3_18): the global object of the running frame's script, else of the top frame's 'this'.
Scaleform::GFx::AS3::Object* FUN_14250a550(Scaleform::GFx::AS3::VM& vm);

// ECMA-262 15.9.1 time arithmetic the Date holders inline (the out-of-line Date:: copies are in sfr_as3_03/04).
namespace Scaleform { namespace GFx { namespace AS3 {
    static SF_INLINE Value::Number DateDayOfTime(Value::Number t)
    {
        return ::floor(t / 86400000.0);
    }

    static SF_INLINE Value::Number DateTimeWithinDay(Value::Number t)
    {
        Value::Number r = fmod(t, 86400000.0);
        if (r < 0)
            r += 86400000.0;
        return r;
    }

    static SF_INLINE Value::Number DateDayFromYear(Value::Number y)
    {
        return ::floor((y - 1969.0) * 0.25) + (y - 1970.0) * 365.0 - ::floor((y - 1901.0) / 100.0) +
               ::floor((y - 1601.0) / 400.0);
    }

    static SF_INLINE Value::Number DateHourFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / 3600000.0), 24.0);
        if (r < 0)
            r += 24.0;
        return r;
    }

    static SF_INLINE Value::Number DateMinFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / 60000.0), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    static SF_INLINE Value::Number DateSecFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / 1000.0), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }
}}} 

// The thunks below call through ThunkFuncN<...>::Method, defined (with its dynamic initializer) in the sfr_as3di_*
// units.
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1423e02e0
typedef ThunkFunc1<Classes::fl::Math, 0, Value::Number, Value::Number> TFunc_Classes_Math_abs;
template struct ThunkFunc1<Classes::fl::Math, 0, Value::Number, Value::Number>;

// thunk 0x1423e03c0
typedef ThunkFunc1<Classes::fl::Math, 1, Value::Number, Value::Number> TFunc_Classes_Math_acos;
template struct ThunkFunc1<Classes::fl::Math, 1, Value::Number, Value::Number>;

// thunk 0x1423e04a0
typedef ThunkFunc1<Classes::fl::Math, 2, Value::Number, Value::Number> TFunc_Classes_Math_asin;
template struct ThunkFunc1<Classes::fl::Math, 2, Value::Number, Value::Number>;

// thunk 0x1423e0580
typedef ThunkFunc1<Classes::fl::Math, 3, Value::Number, Value::Number> TFunc_Classes_Math_atan;
template struct ThunkFunc1<Classes::fl::Math, 3, Value::Number, Value::Number>;

namespace ClassTraits { namespace fl
{
    // @0x1423e0660
    Pickable<Traits> Array::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Array(vm));
    }
}}

// thunk 0x1423e07e0
typedef ThunkFunc2<Classes::fl::Math, 4, Value::Number, Value::Number, Value::Number> TFunc_Classes_Math_atan2;
template struct ThunkFunc2<Classes::fl::Math, 4, Value::Number, Value::Number, Value::Number>;

// thunk 0x1423e0910
typedef ThunkFunc1<Classes::fl::Math, 5, Value::Number, Value::Number> TFunc_Classes_Math_ceil;
template struct ThunkFunc1<Classes::fl::Math, 5, Value::Number, Value::Number>;

// thunk 0x1423e09f0
typedef ThunkFunc1<Classes::fl::Math, 6, Value::Number, Value::Number> TFunc_Classes_Math_cos;
template struct ThunkFunc1<Classes::fl::Math, 6, Value::Number, Value::Number>;

// thunk 0x1423e0ad0
typedef ThunkFunc1<Classes::fl::Math, 7, Value::Number, Value::Number> TFunc_Classes_Math_exp;
template struct ThunkFunc1<Classes::fl::Math, 7, Value::Number, Value::Number>;

// thunk 0x1423e0bb0
typedef ThunkFunc1<Classes::fl::Math, 8, Value::Number, Value::Number> TFunc_Classes_Math_floor;
template struct ThunkFunc1<Classes::fl::Math, 8, Value::Number, Value::Number>;

// thunk 0x1423e0c90
typedef ThunkFunc1<Classes::fl::Math, 9, Value::Number, Value::Number> TFunc_Classes_Math_log;
template struct ThunkFunc1<Classes::fl::Math, 9, Value::Number, Value::Number>;

// thunk 0x1423e0d70
typedef ThunkFunc1<Classes::fl::Math, 10, Value::Number, Value::Number> TFunc_Classes_Math_round;
template struct ThunkFunc1<Classes::fl::Math, 10, Value::Number, Value::Number>;

// thunk 0x1423e0e70
typedef ThunkFunc1<Classes::fl::Math, 11, Value::Number, Value::Number> TFunc_Classes_Math_sin;
template struct ThunkFunc1<Classes::fl::Math, 11, Value::Number, Value::Number>;

// thunk 0x1423e0f50
typedef ThunkFunc1<Classes::fl::Math, 12, Value::Number, Value::Number> TFunc_Classes_Math_sqrt;
template struct ThunkFunc1<Classes::fl::Math, 12, Value::Number, Value::Number>;

// thunk 0x1423e1030
typedef ThunkFunc1<Classes::fl::Math, 13, Value::Number, Value::Number> TFunc_Classes_Math_tan;
template struct ThunkFunc1<Classes::fl::Math, 13, Value::Number, Value::Number>;

// thunk 0x1423e1110
typedef ThunkFunc2<Classes::fl::Math, 14, Value::Number, Value::Number, Value::Number> TFunc_Classes_Math_pow;
template struct ThunkFunc2<Classes::fl::Math, 14, Value::Number, Value::Number, Value::Number>;

// thunk 0x1423e1240
typedef ThunkFunc2<Classes::fl::Math, 15, Value, unsigned, const Value*> TFunc_Classes_Math_max;
template struct ThunkFunc2<Classes::fl::Math, 15, Value, unsigned, const Value*>;

// thunk 0x1423e1260
typedef ThunkFunc2<Classes::fl::Math, 16, Value, unsigned, const Value*> TFunc_Classes_Math_min;
template struct ThunkFunc2<Classes::fl::Math, 16, Value, unsigned, const Value*>;

// thunk 0x1423e1280
typedef ThunkFunc0<Classes::fl::Math, 17, Value::Number> TFunc_Classes_Math_random;
template struct ThunkFunc0<Classes::fl::Math, 17, Value::Number>;

namespace ClassTraits { namespace fl
{
    // @0x1423e1590
    Pickable<Traits> RegExp::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) RegExp(vm));
    }

    // @0x1423e16e0
    Pickable<Traits> Catch::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Catch(vm));
    }

    // @0x1423e1940
    Pickable<Traits> XMLList::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLList(vm));
    }
}}

// thunk 0x1423e1aa0
typedef ThunkFunc0<Instances::fl::QName, 0, ASString> TFunc_Instances_QName_localNameGet;
template struct ThunkFunc0<Instances::fl::QName, 0, ASString>;

// thunk 0x1423e1b30
typedef ThunkFunc0<Instances::fl::QName, 2, SPtr<Instances::fl::QName>> TFunc_Instances_QName_AS3valueOf;
template struct ThunkFunc0<Instances::fl::QName, 2, SPtr<Instances::fl::QName>>;

namespace ClassTraits { namespace fl
{
    // @0x1423e1ce0
    Pickable<Traits> QName::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) QName(vm));
    }

    // @0x1423e1e60
    Pickable<Traits> Error::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Error(vm));
    }
}}

// thunk 0x1423e1fb0
typedef ThunkFunc0<Instances::fl::Error, 0, SInt32> TFunc_Instances_Error_errorIDGet;
template struct ThunkFunc0<Instances::fl::Error, 0, SInt32>;

// thunk 0x1423e2010
typedef ThunkFunc0<Instances::fl::Error, 1, ASString> TFunc_Instances_Error_getStackTrace;
template struct ThunkFunc0<Instances::fl::Error, 1, ASString>;

// thunk 0x1423e2080
typedef ThunkFunc0<Instances::fl::Error, 2, ASString> TFunc_Instances_Error_toStringProto;
template struct ThunkFunc0<Instances::fl::Error, 2, ASString>;

// thunk 0x1423e20f0
typedef ThunkFunc1<Classes::fl::Error, 0, ASString, SInt32> TFunc_Classes_Error_getErrorMessage;
template struct ThunkFunc1<Classes::fl::Error, 0, ASString, SInt32>;

namespace ClassTraits { namespace fl
{
    // @0x1423e21c0
    Pickable<Traits> DefinitionError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DefinitionError(vm));
    }

    // @0x1423e2310
    Pickable<Traits> EvalError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) EvalError(vm));
    }

    // @0x1423e2460
    Pickable<Traits> RangeError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) RangeError(vm));
    }

    // @0x1423e25b0
    Pickable<Traits> ReferenceError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ReferenceError(vm));
    }

    // @0x1423e2700
    Pickable<Traits> SecurityError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityError(vm));
    }

    // @0x1423e2bf0
    Pickable<Traits> SyntaxError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SyntaxError(vm));
    }

    // @0x1423e3310
    Pickable<Traits> Number::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Number(vm));
    }

    // @0x1423e34a0
    Pickable<Traits> TypeError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TypeError(vm));
    }

    // @0x1423e35f0
    Pickable<Traits> URIError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URIError(vm));
    }

    // @0x1423e3740
    Pickable<Traits> VerifyError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) VerifyError(vm));
    }

    // @0x1423e3890
    Pickable<Traits> UninitializedError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) UninitializedError(vm));
    }

    // @0x1423e39e0
    Pickable<Traits> ArgumentError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ArgumentError(vm));
    }
}}

// thunk 0x1423e3b30
typedef ThunkFunc0<Instances::fl::Array, 0, UInt32> TFunc_Instances_Array_lengthGet;
template struct ThunkFunc0<Instances::fl::Array, 0, UInt32>;

// thunk 0x1423e3b90
typedef ThunkFunc1<Instances::fl::Array, 1, const Value, UInt32> TFunc_Instances_Array_lengthSet;
template struct ThunkFunc1<Instances::fl::Array, 1, const Value, UInt32>;

namespace ClassTraits { namespace fl
{
    // @0x1423e3e90
    Pickable<Traits> Date::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Date(vm));
    }
}}

// thunk 0x1423e3ff0
typedef ThunkFunc0<Instances::fl::Date, 0, Value::Number> TFunc_Instances_Date_AS3valueOf;
template struct ThunkFunc0<Instances::fl::Date, 0, Value::Number>;

namespace ClassTraits { namespace fl
{
    // @0x1423e4930
    Pickable<Traits> Object::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Object(vm));
    }
}}

// thunk 0x1423e5150
typedef ThunkFunc0<Instances::fl::RegExp, 0, ASString> TFunc_Instances_RegExp_sourceGet;
template struct ThunkFunc0<Instances::fl::RegExp, 0, ASString>;

// thunk 0x1423e51c0
typedef ThunkFunc0<Instances::fl::RegExp, 1, bool> TFunc_Instances_RegExp_globalGet;
template struct ThunkFunc0<Instances::fl::RegExp, 1, bool>;

// thunk 0x1423e5220
typedef ThunkFunc0<Instances::fl::RegExp, 2, bool> TFunc_Instances_RegExp_ignoreCaseGet;
template struct ThunkFunc0<Instances::fl::RegExp, 2, bool>;

// thunk 0x1423e5280
typedef ThunkFunc0<Instances::fl::RegExp, 3, bool> TFunc_Instances_RegExp_multilineGet;
template struct ThunkFunc0<Instances::fl::RegExp, 3, bool>;

// thunk 0x1423e52e0
typedef ThunkFunc0<Instances::fl::RegExp, 4, SInt32> TFunc_Instances_RegExp_lastIndexGet;
template struct ThunkFunc0<Instances::fl::RegExp, 4, SInt32>;

// thunk 0x1423e5340
typedef ThunkFunc1<Instances::fl::RegExp, 5, const Value, SInt32> TFunc_Instances_RegExp_lastIndexSet;
template struct ThunkFunc1<Instances::fl::RegExp, 5, const Value, SInt32>;

// thunk 0x1423e53b0
typedef ThunkFunc0<Instances::fl::RegExp, 6, bool> TFunc_Instances_RegExp_dotallGet;
template struct ThunkFunc0<Instances::fl::RegExp, 6, bool>;

// thunk 0x1423e5410
typedef ThunkFunc0<Instances::fl::RegExp, 7, bool> TFunc_Instances_RegExp_extendedGet;
template struct ThunkFunc0<Instances::fl::RegExp, 7, bool>;

// thunk 0x1423e5470
typedef ThunkFunc1<Instances::fl::RegExp, 8, SPtr<Instances::fl::Object>, const ASString&> TFunc_Instances_RegExp_AS3exec;
template struct ThunkFunc1<Instances::fl::RegExp, 8, SPtr<Instances::fl::Object>, const ASString&>;

namespace ClassTraits { namespace fl
{
    // @0x1423e5f30
    Pickable<Traits> int_::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) int_(vm));
    }

    // @0x1423e6380
    Pickable<Traits> Namespace::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Namespace(vm));
    }

    // @0x1423e6e80
    Pickable<Traits> uint::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) uint(vm));
    }

    // @0x1423e7210
    Pickable<Traits> Boolean::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Boolean(vm));
    }
}}

// thunk 0x1423e7360
typedef ThunkFunc0<Classes::fl::XML, 0, SPtr<Instances::fl::Object>> TFunc_Classes_XML_AS3settings;
template struct ThunkFunc0<Classes::fl::XML, 0, SPtr<Instances::fl::Object>>;

// thunk 0x1423e3c20
typedef ThunkFunc0<Instances::fl::XML, 0, SPtr<Instances::fl::XMLList>> TFunc_Instances_XML_prototypeGet;
template struct ThunkFunc0<Instances::fl::XML, 0, SPtr<Instances::fl::XMLList>>;

// thunk 0x1423e3cd0
typedef ThunkFunc1<Instances::fl::XML, 1, const Value, const Value&> TFunc_Instances_XML_prototypeSet;
template struct ThunkFunc1<Instances::fl::XML, 1, const Value, const Value&>;

// thunk 0x1423e3e20
typedef ThunkFunc0<Instances::fl::XML, 2, ASString> TFunc_Instances_XML_AS3toString;
template struct ThunkFunc0<Instances::fl::XML, 2, ASString>;

// thunk 0x1423e76f0
typedef ThunkFunc0<Instances::fl::XMLList, 0, SPtr<Instances::fl::XMLList>> TFunc_Instances_XMLList_prototypeGet;
template struct ThunkFunc0<Instances::fl::XMLList, 0, SPtr<Instances::fl::XMLList>>;

// thunk 0x1423e7840
typedef ThunkFunc1<Instances::fl::XMLList, 1, const Value, const Value&> TFunc_Instances_XMLList_prototypeSet;
template struct ThunkFunc1<Instances::fl::XMLList, 1, const Value, const Value&>;

// thunk 0x1423e7d80
typedef ThunkFunc0<Instances::fl::XMLList, 2, SInt32> TFunc_Instances_XMLList_AS3length;
template struct ThunkFunc0<Instances::fl::XMLList, 2, SInt32>;

// @0x1423ef9b0
Value::Value(Instances::Namespace* v)
    : Flags(kNamespace)
    , value(v)
{
    if (v)
        v->AddRef();
}

namespace InstanceTraits
{
    // Traits of a method's activation object (its local slots), unnamed, in the public namespace. vftable
    // 0x14313ffe8; GetFixedMemSize (0x142415ac0) and MakeObject (0x14241bd70) are folded with other classes'.
    class Activation : public RTraits
    {
        friend class AS3::VM;
    private:
        Activation(VM& vm);

    public:
        Activation(VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo& mbi, const ASString& name);

        virtual unsigned GetFixedMemSize() const { return 0x38; }
        virtual void MakeObject(Value& result, Traits& t) { SF_UNUSED2(result, t); }
    };

    // The activation of a method body: named after the method, its slots are the body's local traits.
    // @0x1423eb8f0
    Activation::Activation(VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo& mbi, const ASString& name)
        : RTraits(vm, vm.GetStringManager().CreateConstString("activation@") + name,
                  Pickable<Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue), NULL, true, true)
    {
        TraitsType = Traits_Activation;
        AddSlots(mbi, file, GetFixedMemSize());
    }

    // @0x1423eb860
    Activation::Activation(VM& vm)
        : RTraits(vm, vm.GetStringManager().CreateEmptyString(),
                  Pickable<Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue), NULL, true, true)
    {
        TraitsType = Traits_Activation;
        SetMemSize(0x38);
    }
}

namespace InstanceTraits { namespace fl
{
    // The catch scope of an exception handler: one slot, named by the exception variable and typed by the exception
    // type (untyped when the handler catches everything).
    // @0x1423ebff0
    Catch::Catch(VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo::ExceptionInfo& e)
        : CTraits(vm, AS3::fl::CatchCI)
    {
        TraitsType = Traits_Catch;
        UInt32 var_ind = e.var_name_ind;
        if (var_ind != 0)
            var_ind = UInt32(file.GetAbcFile().Const_Pool.ConstStr.GetSize()) - var_ind;
        ASString name = file.GetInternedString(var_ind);
        SlotInfo::BindingType bt = (SlotInfo::BindingType)2;
        if (e.exc_type_ind != 0)
            bt = GetBindingType(file, file.GetAbcFile().Const_Pool.GetMultiname(e.exc_type_ind));
        AddSlot(name, Pickable<const Instances::Namespace>(GetVM().PublicNamespace.GetPtr(), PickValue), bt,
                AbsoluteIndex(0));
        CalculateMemSize(0x38);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423e7de0
    Pickable<Traits> String::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) String(vm));
    }

    // @0x1423e7f30
    Pickable<Traits> XML::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XML(vm));
    }

    // @0x1423eb9f0
    ArgumentError::ArgumentError(VM& vm)
        : Traits(vm, AS3::fl::ArgumentErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ArgumentErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ebaf0
    Array::Array(VM& vm)
        : Traits(vm, AS3::fl::ArrayCI)
    {
        TraitsType = Traits_Array;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Array(vm, AS3::fl::ArrayCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Array(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebc20
    Array::Array(ClassTraits::Traits& t)
        : Class(t), CASEINSENSITIVE(1), DESCENDING(2), UNIQUESORT(4), RETURNINDEXEDARRAY(8), NUMERIC(16)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebc70
    Array::Array(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_Array;
        SetMemSize(sizeof(Instances::fl::Array));
    }
}}

namespace Instances { namespace fl
{
    // The Instances::fl ctors that take InstanceTraits::Traits& are `inline` under cl, so their out-of-line copies
    // here are COMDAT-any and the inline copies that sfr_as3_02/03/04 carry (cl emits some of them) no longer clash
    // with them in the fullexe link (LNK2005). MS2_Sfr01cEmitInstanceCtors at the end of the unit keeps them
    // emitted. clang-cl ignores inline_depth, so the hook DLL build keeps them as plain definitions.
    // @0x1423ebcb0
    SFR01C_INSTANCE_CTOR Array::Array(InstanceTraits::Traits& t)
        : Instance(t), SA(t.GetVM().GetMemoryHeap())
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ebd20
    Boolean::Boolean(VM& vm)
        : Traits(vm, AS3::fl::BooleanCI)
    {
        TraitsType = Traits_Boolean;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Boolean(vm, AS3::fl::BooleanCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Boolean(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebe20
    Boolean::Boolean(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebe50
    Boolean::Boolean(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Boolean;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ebe80
    Catch::Catch(VM& vm)
        : Traits(vm, AS3::fl::CatchCI)
    {
        TraitsType = Traits_Catch;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Catch(vm, AS3::fl::CatchCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Catch(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebf90
    Catch::Catch(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebfc0
    Catch::Catch(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Catch;
        SetMemSize(sizeof(Instances::fl::Catch));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec100
    SFR01C_INSTANCE_CTOR Catch::Catch(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }
}}

// The class Class: traits, instance traits and class object. Only the traits are used outside this unit.
namespace fl { extern const ClassInfo ClassClassCI; }  // 0x14313d940

namespace InstanceTraits
{
    // Instance traits of the class Class: class objects are made by their own traits, never by these. 0xe8 bytes.
    // vftable 0x1431402c8.
    class ClassClass : public CTraits
    {
    public:
        ClassClass(VM& vm) : CTraits(vm, AS3::fl::ClassClassCI) {}
        // 0x14241bea0
        virtual void MakeObject(Value& result, Traits& t) { SF_UNUSED2(result, t); }
    };
}

namespace Classes
{
    // The class object of the class Class. 0x50 bytes. vftable 0x143140350.
    class ClassClass : public Class
    {
    public:
        ClassClass(ClassTraits::Traits& t);
        virtual ~ClassClass() {}
    };

    // @0x1423ec230
    ClassClass::ClassClass(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}

namespace ClassTraits
{
    // @0x1423ec130
    ClassClass::ClassClass(VM& vm)
        : Traits(vm)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::ClassClass(vm);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        Classes::ClassClass* cl = new(mh) Classes::ClassClass(*this);
        it->SetConstructor(Pickable<Class>(cl));
        SetConstructor(*cl);
    }
}

namespace ClassTraits { namespace fl
{
    // @0x1423ec260
    Date::Date(VM& vm)
        : Traits(vm, AS3::fl::DateCI)
    {
        TraitsType = Traits_Date;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Date(vm, AS3::fl::DateCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Date(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ec370
    Date::Date(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ec3a0
    Date::Date(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Date;
        SetMemSize(sizeof(Instances::fl::Date));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec3d0
    SFR01C_INSTANCE_CTOR Date::Date(InstanceTraits::Traits& t)
        : Instance(t), TimeValue(0), LocalTZA(0)
    {
    }

    // @0x1423ec400
    Date::DateHolder::DateHolder(Value::Number time, Value::Number tza)
        : TZA(tza)
    {
        const Value::Number t = time + tza;
        Entries[Date_Year] = Date::YearFromTime(t);
        const SInt32 dayWithinYear = static_cast<SInt32>(DateDayOfTime(t) - DateDayFromYear(Entries[Date_Year]));
        Entries[Date_Month] = Date::MonthFromYearDay(static_cast<SInt32>(Entries[Date_Year]), dayWithinYear);
        Entries[Date_Day] = static_cast<Value::Number>(Date::DateFromTime(t));
        TimeInDay = DateTimeWithinDay(t);
    }

    // new Date(): now; new Date(value): a date string is parsed, anything else is a time value; two or more
    // arguments are local year, month, ... components.
    // @0x1423f5650
    void Date::AS3Constructor(unsigned argc, const Value* argv)
    {
        GetCurrentTimeValue(&TimeValue, &LocalTZA);
        if (argc == 1)
        {
            Value v;
            if (argv[0].Convert2PrimitiveValueUnsafe(v, Value::hintString))
            {
                if (v.IsString())
                {
                    Parser parser(v.AsString().ToCStr());
                    TimeValue = parser.MakeDate(LocalTZA);
                }
                else if (v.ToNumberValue())
                    TimeValue = TimeClip(v.AsNumber());
            }
        }
        else if (argc >= 2)
            TimeValue = decodeUTCArgs(argc, argv, LocalTZA);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ec540
    DefinitionError::DefinitionError(VM& vm)
        : Traits(vm, AS3::fl::DefinitionErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::DefinitionErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ec640
    Error::Error(VM& vm)
        : Traits(vm, AS3::fl::ErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Error(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ec740
    Error::Error(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ec770
    Error::Error(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::Error));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec7a0
    SFR01C_INSTANCE_CTOR Error::Error(InstanceTraits::Traits& t)
        : Instance(t)
        , message(GetVM().GetStringManager().CreateEmptyString())
        , name(GetVM().GetStringManager().CreateEmptyString())
        , ID(0)
        , StackTrace(GetVM().GetStringManager().CreateEmptyString())
    {
        name = t.GetName();
        GetVM().GetStackTraceASString(StackTrace);
    }

    // @0x1423ec890
    SFR01C_INSTANCE_CTOR Error::Error(InstanceTraits::Traits& t, int id, const ASString& msg)
        : Instance(t)
        , message(msg)
        , name(GetVM().GetStringManager().CreateConstString("Error"))
        , ID(id)
        , StackTrace(GetVM().GetStringManager().CreateEmptyString())
    {
        GetVM().GetStackTraceASString(StackTrace);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ec940
    EvalError::EvalError(VM& vm)
        : Traits(vm, AS3::fl::EvalErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::EvalErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }
}}

namespace ClassTraits
{
    // @0x1423eca40
    Function::Function(VM& vm, const ClassInfo& ci)
        : Traits(vm, ci)
    {
        TraitsType = Traits_Function;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Function* it = new(mh) InstanceTraits::Function(vm, ci);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        Classes::Function* cl = new(mh) Classes::Function(*this);
        it->SetConstructor(Pickable<Class>(cl));

        // The native function kinds share the class Function.
        ThunkTraits = Pickable<InstanceTraits::Traits>(new(vm.GetMemoryHeap()) InstanceTraits::Thunk(vm));
        ThunkTraits->SetConstructor(Pickable<Class>(cl, PickValue));
        ThunkFunctionTraits =
            Pickable<InstanceTraits::ThunkFunction>(new(vm.GetMemoryHeap()) InstanceTraits::ThunkFunction(vm));
        ThunkFunctionTraits->SetConstructor(Pickable<Class>(cl, PickValue));
        MethodIndTraits = Pickable<InstanceTraits::Traits>(new(vm.GetMemoryHeap()) InstanceTraits::MethodInd(vm));
        MethodIndTraits->SetConstructor(Pickable<Class>(cl, PickValue));
        VTableTraits = Pickable<InstanceTraits::Traits>(new(vm.GetMemoryHeap()) InstanceTraits::VTableInd(vm));
        VTableTraits->SetConstructor(Pickable<Class>(cl, PickValue));
    }
}

// InstanceTraits::Function::RegisterSlots: the "prototype" slot and the Function methods (defined in sfr_as3_04)
void FUN_14241e5d0(Traits* tr);

namespace InstanceTraits
{
    // @0x1423ecf50
    Function::Function(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
        , MethodInfoInd(0)
    {
        TraitsType = Traits_Function;
        SetMemSize(sizeof(Instances::Function));
        FUN_14241e5d0(this);
    }

    // @0x1423ecfa0
    Function::Function(VMAbcFile& file, const ClassInfo& ci, SInt32 mi, Instances::fl::GlobalObjectScript* gos)
        : CTraits(file.GetVM(), ci)
        , MethodInfoInd(mi)
        , File(&file)
        , GOS(gos)
    {
        SetConstructor(FUN_142508460(&file.GetVM().GetClassTraitsFunction().GetInstanceTraits()));
        TraitsType = Traits_Function;
        SetMemSize(sizeof(Instances::Function));

        // The slots of the method body come first.
        const Abc::File& abc = file.GetAbcFile();
        const Abc::MethodBodyInfo& mbi = *abc.MethodBodies.Info[abc.Methods.Info[MethodInfoInd]->MethodBodyInfoInd];
        if (AddSlots(mbi, file, sizeof(Instances::Function)))
            FUN_14241e5d0(this);
    }
}

namespace Instances
{
    // MS2-FUNCTIONAL: the exe inlines the scope stack copy around an Append call; ours calls the copy out of line
    // @0x1423ed090
    Function::Function(InstanceTraits::Traits& t, const ScopeStackType& ss, const Value& stored_this,
                       const ASString& name)
        : FunctionBase(t)
        , StoredScopeStack(ss)
        , StoredThis(stored_this)
        , Name(name)
    {
    }

    // @0x1423f0eb0
    Function::~Function()
    {
    }

    // The two slot overrides below lie in sfr_as3_04's range (0x142416ff0, 0x142415e70) but progress tracks
    // neither; their vftable slots come from here.
    void* Function::Unk15()
    {
        return &StoredScopeStack;
    }

    UInt32 Function::GetMaxParamNum() const
    {
        const InstanceTraits::Function& t = static_cast<const InstanceTraits::Function&>(GetTraits());
        const Abc::File& abc = t.File->GetAbcFile();
        const Abc::MethodBodyInfo& mbi = *abc.MethodBodies.Info[abc.Methods.Info[t.GetMethodInfoInd()]->MethodBodyInfoInd];
        return static_cast<UInt32>(abc.Methods.Info[mbi.method_info_ind]->ParamTypes.GetSize());
    }

    // @0x1423ed140
    FunctionBase::FunctionBase(InstanceTraits::Traits& t)
        : fl::Object(t)
    {
        Prototype.Pick(GetVM().MakeObject());
    }
}

namespace Classes
{
    // In sfr_as3_03's range (0x1424057a0) but untracked by progress; the vftable slot comes from here.
    void Function::Call(const Value& /*_this*/, Value& result, unsigned argc, const Value* const argv)
    {
        Construct(result, argc, argv);
    }
}

namespace InstanceTraits { namespace fl
{
    // @0x1423ed1c0
    GlobalObject::GlobalObject(VM& vm)
        : CTraits(vm, CInfo)
    {
        SetConstructor(FUN_142508460(&vm.GetClassTraitsObject().GetInstanceTraits()));
        InitScope.Resize(0);
    }

    // Untracked by progress (0x14241bfc0, shared with other empty makers); the vftable slot comes from here.
    void GlobalObject::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ed230
    GlobalObject::GlobalObject(InstanceTraits::Traits& t)
        : fl::Object(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ed6e0
    GlobalObjectScript::GlobalObjectScript(VMAbcFile& file, VM& vm, const Abc::ScriptInfo& script)
        : GlobalObject(vm)
        , File(&file)
        , Script(script)
    {
        AddSlots(script, file, GetFixedMemSize());
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ed7b0
    GlobalObjectScript::GlobalObjectScript(InstanceTraits::fl::GlobalObjectScript& t)
        : GlobalObject(t)
        , Initialized(false)
    {
        t.SetupSlotValues(GetTraits().GetFile(), GetTraits().GetScript(), *this);
    }
}}

// The builtin classes, null-terminated (registered by name in the C++ global object).
extern const ClassInfo* ClassRegistrationTable[];  // 0x143a28a30

namespace Instances { namespace fl
{
    // The members and global functions of the C++ global object, by package.
    extern const MemberInfo GlobalObjectCPP_mi[16];         // 0x143a2a710 Infinity .. FLASH10_FLAGS
    extern const ThunkInfo GlobalObjectCPP_ti[13];          // 0x143144150 decodeURI .. print
    extern const ThunkInfo GlobalObjectCPP_ti_system[1];    // 0x143144410 flash.system
    extern const ThunkInfo GlobalObjectCPP_ti_utils[11];    // 0x143144450 flash.utils
    extern const ThunkInfo GlobalObjectCPP_ti_avmplus[3];   // 0x1431446e0 avmplus

    typedef Scaleform::Hash<ConstStringKey, const ClassInfo*, ConstStringHashFn,
                            Scaleform::AllocatorGH<ConstStringKey, 328> > CIRegistrationHashType;

    // MS2-FUNCTIONAL: the scratch ClassInfo is value-initialized (the exe stores its fields one qword at a time)
    // @0x1423ed260
    GlobalObjectCPP::GlobalObjectCPP(VM& vm, InstanceTraits::fl::GlobalObject& t)
        : GlobalObject(t)
        , CIRegistrationHash(NULL)
        , PositiveInfinity(NumberUtil::POSITIVE_INFINITY())
        , NegativeInfinity(NumberUtil::NEGATIVE_INFINITY())
        , NaN(NumberUtil::NaN())
        , HIDE_NSURI_METHODS(0x0001)
        , INCLUDE_BASES(0x0002)
        , INCLUDE_INTERFACES(0x0004)
        , INCLUDE_VARIABLES(0x0008)
        , INCLUDE_ACCESSORS(0x0010)
        , INCLUDE_METHODS(0x0020)
        , INCLUDE_METADATA(0x0040)
        , INCLUDE_CONSTRUCTOR(0x0080)
        , INCLUDE_TRAITS(0x0100)
        , USE_ITRAITS(0x0200)
        , HIDE_OBJECT(0x0400)
        , FLASH10_FLAGS(0x05ff)
    {
        // the builtin classes by name, for on-demand initialization
        CIRegistrationHashType& h = *reinterpret_cast<CIRegistrationHashType*>(&CIRegistrationHash);
        for (unsigned i = 0; ClassRegistrationTable[i]; ++i)
        {
            ConstStringKey key = { ClassRegistrationTable[i]->GetName() };
            h.Add(key, ClassRegistrationTable[i]);
        }

        // the core classes are always there
        AddFixedSlot(FUN_142508460(&vm.GetClassTraitsObject().GetInstanceTraits()));
        AddFixedSlot(FUN_142508460(&vm.GetClassTraitsClassClass().GetInstanceTraits()));
        AddFixedSlot(FUN_142508460(&vm.GetClassTraitsNamespace().GetInstanceTraits()));
        AddFixedSlot(FUN_142508460(&vm.GetClassTraitsFunction().GetInstanceTraits()));
        AddFixedSlot(vm.GetClassBoolean());
        AddFixedSlot(vm.GetClassNumber());
        AddFixedSlot(vm.GetClassSInt());
        AddFixedSlot(vm.GetClassUInt());
        AddFixedSlot(vm.GetClassString());
        AddFixedSlot(vm.GetClassArray());
        const XMLSupport& xs = vm.GetXMLSupport();
        if (xs.IsEnabled())
        {
            AddFixedSlot(FUN_142508460(xs.GetITraitsQName()));
            AddFixedSlot(FUN_142508460(xs.GetITraitsXML()));
            AddFixedSlot(FUN_142508460(xs.GetITraitsXMLList()));
        }

        // the global functions, by package
        {
            ClassInfo ci = ClassInfo();
            ci.Flags = TypeInfo::CompileTime;
            ci.Name = "";
            ci.PkgName = "";
            for (unsigned i = 0; i < 13; ++i)
                GetTraits().Add2VT(ci, GlobalObjectCPP_ti[i]);
        }
        {
            ClassInfo ci = ClassInfo();
            ci.Flags = TypeInfo::CompileTime;
            ci.Name = "";
            ci.PkgName = "flash.system";
            for (unsigned i = 0; i < 1; ++i)
                GetTraits().Add2VT(ci, GlobalObjectCPP_ti_system[i]);
        }
        {
            ClassInfo ci = ClassInfo();
            ci.Flags = TypeInfo::CompileTime;
            ci.Name = "";
            ci.PkgName = "flash.utils";
            for (unsigned i = 0; i < 11; ++i)
                GetTraits().Add2VT(ci, GlobalObjectCPP_ti_utils[i]);
        }
        // the constants
        for (unsigned i = 0; i < 16; ++i)
            t.AddSlot(GlobalObjectCPP_mi[i]);
        {
            ClassInfo ci = ClassInfo();
            ci.Flags = TypeInfo::CompileTime;
            ci.Name = "";
            ci.PkgName = "avmplus";
            for (unsigned i = 0; i < 3; ++i)
                GetTraits().Add2VT(ci, GlobalObjectCPP_ti_avmplus[i]);
        }
    }

    // MS2-FUNCTIONAL: the registration hash is opaque in the header, so the body destroys it before the other members
    // (the exe destroys it last)
    // @0x1423f0fc0
    GlobalObjectCPP::~GlobalObjectCPP()
    {
        reinterpret_cast<CIRegistrationHashType*>(&CIRegistrationHash)->~CIRegistrationHashType();
    }
}}

// Traits::StoreScopeStack (private in the header): the scope the traits' methods run in, the VM scope stack above
// base_ind (sfr_as3_19's raw-offset model)
void Sfr31StoreScopeStack(UPInt self, UPInt start, UPInt* src);
// Traits: the slots of the interfaces an ABC class implements (sfr_as3_16z)
void Sfr21AddInterfaceSlots(Traits* self, VMAbcFile& file, const Abc::ClassInfo& info);

// The scope stack base of the running call frame (0 outside of any); the call stack is paged, 64 frames of 0xa8
// bytes to a page.
static inline UPInt GetCurrScopeStackBaseInd(const VM& vm)
{
    UPInt base = vm.Unk070[1];
    if (base != 0)
    {
        const UPInt n = base - 1;
        base = *reinterpret_cast<const UPInt*>(reinterpret_cast<const char* const*>(vm.Unk070[4])[n >> 6] +
                                               (n & 0x3f) * 0xa8 + 8);
    }
    return base;
}

namespace ClassTraits
{
    // @0x1423ef690
    UserDefined::UserDefined(VMAbcFile& file, VM& vm, const Abc::ClassInfo& info)
        : Traits(vm, NULL)
        , File(&file)
        , class_info(info)
    {
        Flags |= IsAbcObjectMask;
    }

    // @0x1423f13d0
    UserDefined::~UserDefined()
    {
    }
}

namespace Classes
{
    // MS2-FUNCTIONAL: register allocation (the exe keeps the traits in r9 and the VM in rcx)
    // @0x1423ef700
    UserDefined::UserDefined(ClassTraits::Traits& t)
        : UDBase(t)
    {
        if (t.SetupSlotValues(*this))
        {
            VM& vm = GetVM();
            Sfr31StoreScopeStack(reinterpret_cast<UPInt>(&GetTraits()), GetCurrScopeStackBaseInd(vm),
                reinterpret_cast<UPInt*>(&vm.ScopeStack));
        }
    }
}

namespace InstanceTraits
{
    // MS2-FUNCTIONAL: register allocation; the exe updates Flags in memory
    // @0x1423ef790
    UserDefined::UserDefined(VMAbcFile& file, const AS3::Traits* pt, const Abc::ClassInfo& info)
        : RTraits(file.GetVM(),
                  file.GetInternedString(file.GetAbcFile().Const_Pool.GetMultiname(info.inst_info.name_ind).NameIndex),
                  Pickable<Instances::Namespace>(
                      &file.GetInternedNamespace(file.GetAbcFile().Const_Pool.GetMultiname(info.inst_info.name_ind).Ind),
                      PickValue),
                  pt, !info.inst_info.IsSealed(), info.inst_info.IsFinal())
        , class_info(info)
    {
        Flags |= IsAbcObjectMask;
        Flags ^= (-(SPInt)info.inst_info.IsInterface() ^ Flags) & IsInterfaceMask;
        if (AddSlots(info.inst_info, file, pt ? pt->GetMemSize() : GetFixedMemSize()))
            Sfr21AddInterfaceSlots(this, file, info);
    }
}

namespace InstanceTraits
{
    // @0x1423ed810
    Interface::Interface(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetIsInterface();
        SetMemSize(sizeof(Instances::fl::Object));
    }
}

namespace ClassTraits { namespace fl
{
    // @0x1423ed840
    Math::Math(VM& vm)
        : Traits(vm, AS3::fl::MathCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl::MathCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Math(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ed9c0
    Math::Math(ClassTraits::Traits& t)
        : Class(t), LN10(2.302585092994046), E(2.718281828459045), LN2(0.6931471805599453), LOG10E(0.4342944819032518),
      LOG2E(1.4426950408889634), PI(3.141592653589793), SQRT1_2(0.7071067811865476), SQRT2(1.4142135623730951)
    {
    }
}}

namespace InstanceTraits
{
    // @0x1423eda60
    MethodInd::MethodInd(VM& vm)
        : CTraits(vm, DAT_14313dc60)
    {
        TraitsType = Traits_Function;
        for (unsigned i = 0; i < 3; ++i)
            Add2VT(AS3::fl::FunctionCI, f[i]);
    }
}

namespace Instances
{
    // @0x1423edad0
    Namespace::Namespace(VM& vm, Abc::NamespaceKind kind, const char* uri)
        : GASRefCountBase(vm.GetGCPtr())
        , Kind(kind)
        , IsInterface(false)
        , VMRef(vm)
        , Uri(vm.GetStringManager().CreateConstString(uri))
    {
    }

    // @0x1423edb60
    Namespace::Namespace(VM& vm, NamespaceInstanceFactory* pfactory, Abc::NamespaceKind kind, const ASString& uri,
                         const Value& prefix)
        : GASRefCountBase(vm.GetGCPtr())
        , Kind(kind)
        , IsInterface(false)
        , VMRef(vm)
        , Uri(uri)
        , pFactory(pfactory)
        , Prefix(prefix)
    {
    }
}

namespace ClassTraits { namespace fl
{
    // @0x1423edc20
    Namespace::Namespace(VM& vm)
        : Traits(vm, AS3::fl::NamespaceCI)
    {
        TraitsType = Traits_Namespace;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Namespace(vm, AS3::fl::NamespaceCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Namespace(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423edd90
    Namespace::Namespace(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423eddc0
    Namespace::Namespace(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Namespace;
        InstanceFactory = *SF_HEAP_NEW(vm.GetMemoryHeap()) NamespaceInstanceFactory(this);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ede60
    Number::Number(VM& vm)
        : Traits(vm, AS3::fl::NumberCI)
    {
        TraitsType = Traits_Number;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Number(vm, AS3::fl::NumberCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Number(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423edfa0
    Number::Number(ClassTraits::Traits& t)
        : Class(t), NaN(NumberUtil::NaN()), NEGATIVE_INFINITY(NumberUtil::NEGATIVE_INFINITY()),
      POSITIVE_INFINITY(NumberUtil::POSITIVE_INFINITY()), MIN_VALUE(2.2250738585072014e-308),
      MAX_VALUE(1.7976931348623157e+308)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee000
    Number::Number(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Number;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ee030
    Object::Object(VM& vm)
        : Traits(vm, AS3::fl::ObjectCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl::ObjectCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Object(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ee130
    Object::Object(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee160
    Object::Object(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::Object));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ee190
    Object::Object(VM& vm)
        : Instance(vm)
    {
    }

    // @0x1423ee1c0
    SFR01C_INSTANCE_CTOR Object::Object(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ee840
    QName::QName(VM& vm)
        : Traits(vm, AS3::fl::QNameCI)
    {
        TraitsType = Traits_QName;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::QName(vm, AS3::fl::QNameCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::QName(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ee950
    QName::QName(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee980
    QName::QName(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_QName;
        SetMemSize(sizeof(Instances::fl::QName));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ee9b0
    SFR01C_INSTANCE_CTOR QName::QName(InstanceTraits::Traits& t)
        : Instance(t)
        , LocalName(GetVM().GetStringManager().CreateEmptyString())
        , Ns(&t.GetVM().GetPublicNamespace())
    {
    }

    // @0x1423eea20
    SFR01C_INSTANCE_CTOR QName::QName(InstanceTraits::Traits& t, const ASString& local, Instances::Namespace* ns)
        : Instance(t), LocalName(local), Ns(ns)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eea80
    RangeError::RangeError(VM& vm)
        : Traits(vm, AS3::fl::RangeErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::RangeErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eeb80
    ReferenceError::ReferenceError(VM& vm)
        : Traits(vm, AS3::fl::ReferenceErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ReferenceErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eec80
    RegExp::RegExp(VM& vm)
        : Traits(vm, AS3::fl::RegExpCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::RegExp(vm, AS3::fl::RegExpCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::RegExp(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423eed80
    RegExp::RegExp(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423eedb0
    RegExp::RegExp(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::RegExp));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423eede0
    SFR01C_INSTANCE_CTOR RegExp::RegExp(InstanceTraits::Traits& t)
        : Instance(t)
        , CompRegExp(NULL)
        , MatchOffset(-1)
        , MatchLength(0)
        , IsGlobal(false)
        , LastIndex(0)
        , OptionFlags(0x800)
        , HasNamedGroups(false)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eee40
    SecurityError::SecurityError(VM& vm)
        : Traits(vm, AS3::fl::SecurityErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::SecurityErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eef70
    String::String(VM& vm)
        : Traits(vm, AS3::fl::StringCI)
    {
        TraitsType = Traits_String;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::String(vm, AS3::fl::StringCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::String(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ef070
    String::String(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ef0a0
    String::String(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_String;
    }
}}

namespace InstanceTraits
{
    // @0x1423ef1d0
    Thunk::Thunk(VM& vm)
        : CTraits(vm, DAT_14313dc60)
    {
        TraitsType = Traits_Function;
        for (unsigned i = 0; i < 3; ++i)
            Add2VT(AS3::fl::FunctionCI, f[i]);
    }

    // @0x1423ef240
    ThunkFunction::ThunkFunction(VM& vm)
        : CTraits(vm, DAT_14313dcb0)
    {
        TraitsType = Traits_Function;
        SetMemSize(sizeof(Instances::ThunkFunction));
        Add2VT(AS3::fl::FunctionCI, f[0]);
    }

    // @0x1423ef910
    VTableInd::VTableInd(VM& vm)
        : CTraits(vm, DAT_14313dc60)
    {
        TraitsType = Traits_Function;
        for (unsigned i = 0; i < 3; ++i)
            Add2VT(AS3::fl::FunctionCI, f[i]);
    }
}

namespace Instances { namespace fl
{
    // Three-letter day and month names (exe data, defined with the Date string formatting in sfr_as3_04).
    extern const char* DateWeekDayNames[7];
    extern const char* DateMonthNames[12];

    // The Date string scanners, which the exe inlines into Date::Parser (sfr_as3_04 holds its own copies).
    static SF_INLINE bool DateIsDigit(char c)
    {
        return (unsigned char)(c - '0') <= 9;
    }

    // Skips blanks, commas and any dash that does not start a number.
    static SF_INLINE const char* DateSkipWhitespace(const char* s)
    {
        while (*s && (*s <= ' ' || *s == ',' || (*s == '-' && !DateIsDigit(s[1]))))
            ++s;
        return s;
    }

    static SF_INLINE const char* DateScanUnsignedInt(const char* s, int* pval)
    {
        *pval = 0;
        while (*s >= '0' && *s <= '9')
            *pval = *pval * 10 + (*s++ - '0');
        return s;
    }

    // A word runs up to a blank, a comma or a dash.
    static SF_INLINE const char* DateScanTextString(const char* s)
    {
        while (*s > ' ' && *s != ',' && *s != '-')
            ++s;
        return s;
    }

    // Classifies a word as Date::Parser's StringType: 1 month, 2 week day (*index gets their number), 3 GMT, 4 UTC,
    // 5 AM, 6 PM, 0 anything else.
    static SF_INLINE int DateInterpretString(const char* pstr, SPInt length, int* index)
    {
        if (length == 2)
        {
            if (pstr[1] == 'M')
            {
                if (pstr[0] == 'A')
                    return 5;
                if (pstr[0] == 'P')
                    return 6;
            }
        }
        if (length == 3)
        {
            if (memcmp(pstr, "GMT", 3) == 0)
                return 3;
            if (memcmp(pstr, "UTC", 3) == 0)
                return 4;
            for (int i = 0; i < 7; ++i)
                if (memcmp(pstr, DateWeekDayNames[i], 3) == 0)
                {
                    *index = i;
                    return 2;
                }
            for (int i = 0; i < 12; ++i)
                if (memcmp(pstr, DateMonthNames[i], 3) == 0)
                {
                    *index = i;
                    return 1;
                }
        }
        return 0;
    }

    // Accepts the date parts in any order: "Tue Jun 1 00:00:00 GMT-0400 1999", "1/1/1999 12:30 AM", ...
    // @0x1423ee1f0
    Date::Parser::Parser(const char* str)
        : Valid(true)
        , HasYear(false), HasMonth(false), HasDay(false), HasTime(false), HasTZA(false)
        , Month(-1), Day(-1), Year(-1), DayOfWeek(-1)
        , TZA(0), Hour(0), Minute(0), Sec(0)
    {
        while (*str)
        {
            str = DateSkipWhitespace(str);
            const char ch = *str;
            int val;
            if (ch == 0)
                break;

            if (ch == '-')
            {
                // a negative year
                if (HasYear)
                    goto parse_fail;
                str = DateScanUnsignedInt(str, &Year);
                HasYear = true;
                Year = -Year;
                ++str;
                continue;
            }

            if (DateIsDigit(ch))
            {
                str = DateScanUnsignedInt(str, &val);
                str = DateSkipWhitespace(str);
                if (*str == ':')
                {
                    // hh:mm[:ss]
                    if (HasTime)
                        goto parse_fail;
                    HasTime = true;
                    Hour = val;
                    ++str;
                    str = DateSkipWhitespace(str);
                    if (DateIsDigit(*str))
                    {
                        str = DateScanUnsignedInt(str, &Minute);
                        if (*str == ':')
                        {
                            ++str;
                            str = DateSkipWhitespace(str);
                            if (DateIsDigit(*str))
                                str = DateScanUnsignedInt(str, &Sec);
                        }
                    }
                }
                else if (*str == '/')
                {
                    // MM/DD/YYYY, all three required
                    if (HasYear)
                        goto parse_fail;
                    Month = val - 1;
                    ++str;
                    str = DateSkipWhitespace(str);
                    if (!DateIsDigit(*str))
                        goto parse_fail;
                    str = DateScanUnsignedInt(str, &Day);
                    str = DateSkipWhitespace(str);
                    if (*str != '/')
                        goto parse_fail;
                    ++str;
                    str = DateSkipWhitespace(str);
                    if (!DateIsDigit(*str))
                        goto parse_fail;
                    str = DateScanUnsignedInt(str, &Year);
                    HasYear = HasMonth = HasDay = true;
                }
                else if (HasDay)
                {
                    if (HasYear)
                        goto parse_fail;
                    HasYear = true;
                    Year = val;
                }
                else if (val > 31)
                {
                    // too big for a day
                    if (HasYear)
                        goto parse_fail;
                    HasYear = true;
                    Year = val;
                }
                else
                {
                    HasDay = true;
                    Day = val;
                }
                continue;
            }

            {
                const char* end = DateScanTextString(str);
                const int type = DateInterpretString(str, end - str, &val);
                str = end;
                switch (type)
                {
                case String_Month:
                    if (HasMonth)
                        goto parse_fail;
                    Month = val;
                    HasMonth = true;
                    break;
                case String_WeekDay:
                    if (DayOfWeek != -1)
                        goto parse_fail;
                    DayOfWeek = val;
                    break;
                case String_GMT:
                {
                    // GMT+hhmm / GMT-hhmm
                    if (HasTZA)
                        goto parse_fail;
                    const char sign = *str;
                    if (sign != '+' && sign != '-')
                        goto parse_fail;
                    ++str;
                    if (!(*str >= '0' && *str <= '9'))
                        goto parse_fail;
                    str = DateScanUnsignedInt(str, &val);
                    HasTZA = true;
                    const int minutes = (val / 100) * 60 + val % 100;
                    TZA = (sign == '-' ? -minutes : minutes) * 60000;
                    break;
                }
                case String_UTC:
                    if (HasTZA)
                        goto parse_fail;
                    HasTZA = true;
                    break;
                case String_PM:
                    if (!HasTime || Hour > 12)
                        goto parse_fail;
                    if (Hour != 12)
                        Hour += 12;
                    break;
                case String_AM:
                    if (!HasTime || Hour > 12)
                        goto parse_fail;
                    if (Hour == 12)
                        Hour = 0;
                    break;
                case String_Invalid:
                    goto parse_fail;
                }
            }
        }

        if (HasYear && HasMonth && HasDay)
            return;
    parse_fail:
        Valid = false;
    }

    // @0x1423ef290
    Date::TimeHolder::TimeHolder(Value::Number time, Value::Number tza)
        : TZA(tza)
    {
        const Value::Number t = time + tza;
        Entries[Time_Hour] = DateHourFromTime(t);
        Entries[Time_Minute] = DateMinFromTime(t);
        Entries[Time_Second] = DateSecFromTime(t);
        // The exe stores the seconds again here (not the milliseconds).
        Entries[Time_Ms] = DateSecFromTime(t);
        Day = DateDayOfTime(t);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ef0d0
    SyntaxError::SyntaxError(VM& vm)
        : Traits(vm, AS3::fl::SyntaxErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::SyntaxErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef390
    TypeError::TypeError(VM& vm)
        : Traits(vm, AS3::fl::TypeErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::TypeErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef490
    URIError::URIError(VM& vm)
        : Traits(vm, AS3::fl::URIErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::URIErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef590
    UninitializedError::UninitializedError(VM& vm)
        : Traits(vm, AS3::fl::UninitializedErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::UninitializedErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423efa10
    VerifyError::VerifyError(VM& vm)
        : Traits(vm, AS3::fl::VerifyErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::VerifyErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423efb10
    XML::XML(VM& vm)
        : Traits(vm, AS3::fl::XMLCI)
    {
        TraitsType = Traits_XML;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::XML(vm, AS3::fl::XMLCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::XML(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423efc30
    XML::XML(ClassTraits::Traits& t)
        : Class(t), ignoreComments(true), ignoreProcessingInstructions(true), ignoreWhitespace(true), prettyPrinting(true),
      prettyIndent(2)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423efc60
    XML::XML(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_XML;
        SetMemSize(0x48);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eff70
    XMLList::XMLList(VM& vm)
        : Traits(vm, AS3::fl::XMLListCI)
    {
        TraitsType = Traits_XMLList;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::XMLList(vm, AS3::fl::XMLListCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::XMLList(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f0080
    XMLList::XMLList(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f00b0
    XMLList::XMLList(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_XMLList;
        SetMemSize(sizeof(Instances::fl::XMLList));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423f00f0
    SFR01C_INSTANCE_CTOR XMLList::XMLList(InstanceTraits::Traits& t)
        : Instance(t), TargetProperty(NULL)
    {
    }

    // (inlined into ??_G 0x1423f5070)
    XMLList::~XMLList()
    {
        if (TargetProperty)
            TargetProperty->Release();
    }
}}

namespace Instances { namespace fl
{
    // @0x1423efc90
    SFR01C_INSTANCE_CTOR XML::XML(InstanceTraits::Traits& t)
        : Object(t), Text(t.GetVM().GetStringManager().CreateEmptyString())
    {
    }

    // @0x1423efce0
    SFR01C_INSTANCE_CTOR XML::XML(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : Object(t), Text(text), Parent(parent)
    {
    }

    // @0x1423efd40
    SFR01C_INSTANCE_CTOR XMLAttr::XMLAttr(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                     const ASString& value, XML* parent)
        : XML(t, name, parent), Data(value)
    {
        Ns = GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), ns.GetPrefix());
    }

    // @0x1423efe10
    SFR01C_INSTANCE_CTOR XMLComment::XMLComment(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : XML(t, text, parent)
    {
    }

    // @0x1423efe80
    SFR01C_INSTANCE_CTOR XMLElement::XMLElement(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                           XML* parent)
        : XML(t, name, parent)
    {
        Ns = GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), ns.GetPrefix());
    }

    // @0x1423f0260
    SFR01C_INSTANCE_CTOR XMLProcInstr::XMLProcInstr(InstanceTraits::Traits& t, const ASString& name, const ASString& data, XML* parent)
        : XML(t, name, parent), Data(data)
    {
    }

    // @0x1423f02e0
    SFR01C_INSTANCE_CTOR XMLText::XMLText(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : XML(t, text, parent)
    {
    }
}}

// @0x1423f0130
XMLParser::XMLParser(InstanceTraits::fl::XML& itr)
    : NsSeparator(':')
    , CurrKind(kNone)
    , ITr(itr)
    , Parser(XML_ParserCreate(NULL))
    , RootElements(itr.GetVM().GetMemoryHeap())
    , Text(itr.GetVM().GetStringManager().CreateEmptyString())
    , KindStack(itr.GetVM().GetMemoryHeap())
{
    XML_SetUserData(Parser, this);
    XML_SetElementHandler(Parser, StartElementExpatCallback, EndElementExpatCallback);
    XML_SetCharacterDataHandler(Parser, CharacterDataExpatCallback);
    XML_SetXmlDeclHandler(Parser, XmlDeclExpatCallback);
    XML_SetDoctypeDeclHandler(Parser, StartDoctypeDeclExpatCallback, EndDoctypeDeclExpatCallback);
    XML_SetDefaultHandler(Parser, DefaultExpatCallback);

    const Classes::fl::XML& cl = static_cast<const Classes::fl::XML&>(FUN_142508460(&ITr));
    if (!cl.ignoreComments)
        XML_SetCommentHandler(Parser, CommentExpatCallback);
    if (!cl.ignoreProcessingInstructions)
        XML_SetProcessingInstructionHandler(Parser, ProcessingInstructionExpatCallback);
}

// @0x1423f16e0
XMLParser::~XMLParser()
{
    XML_ParserFree(Parser);
}

// A namespace leaves its factory's interning set when it dies.
// @0x1423f10d0
Instances::Namespace::~Namespace()
{
    if (pFactory)
        pFactory->NamespaceSet.Remove(this);
}

// Not exe code: Multiname's implicit destructor (0x1423f1060) lies in this unit's range; destroying one emits it.
void Unk_As3HelperDestroyMultiname(Multiname* p)
{
    p->~Multiname();
}

// Not exe code: the E4X walk visitors and the Array.sort collectors are constructed only in sfr_as3_02..04, but
// their vftables, sdtors and the collectors' operator() bodies lie in this unit's range; constructing them here
// emits those.
template <class T, class A0>
void Unk_As3HelperConstruct(void* p, A0& a0)
{
    new (p) T(a0);
}
template <class T, class A0, class A1>
void Unk_As3HelperConstruct(void* p, A0& a0, A1& a1)
{
    new (p) T(a0, a1);
}
template void Unk_As3HelperConstruct<ValuePtrCollector>(void*, ArrayDH<ValuePtrPair>&);
template void Unk_As3HelperConstruct<Value2StrCollector>(void*, VM&, ArrayDH<StringValueTriple>&);
template void Unk_As3HelperConstruct<Value2NumberCollector>(void*, ArrayDH<NumberValueTriple>&);
template void Unk_As3HelperConstruct<Instances::fl::EmptyCallBack>(void*, Instances::fl::XMLElement&);
template void Unk_As3HelperConstruct<Instances::fl::AttrGetFirst>(void*, Instances::fl::XMLElement&);
template void Unk_As3HelperConstruct<Instances::fl::ChildGetFirst>(void*, Instances::fl::XMLElement&);
template void Unk_As3HelperConstruct<Instances::fl::ChildGet>(void*, Instances::fl::XMLElement&, Instances::fl::XMLList&);
template void Unk_As3HelperConstruct<Instances::fl::AttrGet>(void*, Instances::fl::XMLElement&, Instances::fl::XMLList&);
template void Unk_As3HelperConstruct<Instances::fl::ListGet>(void*, Instances::fl::XMLList&, Instances::fl::XMLList&);

// Not exe code: the thunk function objects are made only in sfr_as3_04 (their constructors are protected), but the
// sdtors of their vftables and the ThunkFunction dtor lie in this unit's range; constructing a derived one emits those.
namespace
{
    struct Unk_ThunkFunctionMaker : Instances::ThunkFunction
    {
        Unk_ThunkFunctionMaker(InstanceTraits::Traits& t, const ThunkInfo& thunk, const Traits& ot)
            : ThunkFunction(t, thunk, ot)
        {
        }
    };
    struct Unk_CheckTypeTFMaker : Instances::CheckTypeTF
    {
        Unk_CheckTypeTFMaker(InstanceTraits::Traits& t, const ThunkInfo& thunk, const Class& data_type,
                             const Traits& ot)
            : CheckTypeTF(t, thunk, data_type, ot)
        {
        }
    };
}
void Unk_As3HelperConstructTF(void* p, void* q, InstanceTraits::Traits& t, const ThunkInfo& thunk, const Class& c,
                              const Traits& ot)
{
    new (p) Unk_ThunkFunctionMaker(t, thunk, ot);
    new (q) Unk_CheckTypeTFMaker(t, thunk, c, ot);
}

namespace ClassTraits { namespace fl
{
    // @0x1423f0350
    int_::int_(VM& vm)
        : Traits(vm, AS3::fl::int_CI)
    {
        TraitsType = Traits_SInt;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::int_(vm, AS3::fl::int_CI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::int_(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f0460
    int_::int_(ClassTraits::Traits& t)
        : Class(t), MIN_VALUE(SF_MIN_SINT32), MAX_VALUE(SF_MAX_SINT32)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f0490
    int_::int_(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_SInt;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423f04c0
    uint::uint(VM& vm)
        : Traits(vm, AS3::fl::uintCI)
    {
        TraitsType = Traits_UInt;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::uint(vm, AS3::fl::uintCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::uint(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f05d0
    uint::uint(ClassTraits::Traits& t)
        : Class(t), MIN_VALUE(0), MAX_VALUE(SF_MAX_UINT32)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f0600
    uint::uint(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_UInt;
    }
}}


namespace InstanceTraits { namespace fl
{
    // Prototype methods of the primitive wrapper classes: on the class's own prototype object they return the
    // default value, otherwise the AS3 method (inlined from its own unit).
    #define MS2_AS3_ON_PROTOTYPE(getclass) (_this.IsObject() && _this.GetObject() == &vm.getclass().GetPrototype())

    // MS2-FUNCTIONAL: register allocation and throw-path tail merging differ (exe does not tail-call SetBool)
    // @0x1423e4060
    void Object::AS3isPrototypeOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, vm));
        if (argc < 1)
            return vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Object::AS3isPrototypeOf", 1, 1, argc));

        bool r = false;
        if (!argv[0].IsNullOrUndefined())
        {
            const AS3::Object* proto = _this.GetObject();
            for (const AS3::Traits* tr = &FUN_14250ffc0(vm, argv[0]); tr; tr = tr->GetParent())
            {
                if (&FUN_142508490(tr).GetPrototype() == proto)
                {
                    r = true;
                    break;
                }
            }
        }
        FUN_142421710(result, r);
    }

    // MS2-FUNCTIONAL: inlines AS3isPrototypeOf, same differences
    // @0x1423e4490
    void Object::isPrototypeOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        AS3isPrototypeOf(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e41c0
    void Object::setPropertyIsEnumerableProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 1)
            return vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Object::setPropertyIsEnumerableProto", 1, 1, argc));
        if (_this.IsObject() && !_this.IsNull())
        {
            const Value& name = argv[0];
            bool isEnum = true;
            ASString str_name = vm.GetStringManager().CreateEmptyString();
            if (!name.Convert2String(str_name))
                return;
            if (argc > 1)
                isEnum = argv[1].Convert2Boolean();
            const AS3::Object::DynAttrsType* da = _this.GetObject()->GetDynamicAttrs();
            if (da)
            {
                AS3::Object::DynAttrsType::ConstIterator it = da->Find(str_name);
                if (it.IsEnd())
                    return vm.ThrowReferenceError(VM::Error(VM::eWriteSealedError, vm, str_name.ToCStr(), FUN_14250ffc0(vm, _this).GetName().ToCStr()));
                it->First.SetDoNotEnum(!isEnum);
            }
        }
        else
            return vm.ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, vm));
    }

    // InstanceTraits::Thunk::GetThunkName and the other function namers (sfr_as3_04), inlined into
    // Object::toStringProto: "Function-<hex id>" from the strings of tr's VM.
    static SF_INLINE ASString FunctionKindName(const AS3::Traits& tr, unsigned long id)
    {
        LongFormatter f(id);
        ASString s = tr.GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x1423e45d0
    void Object::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        const AS3::Traits& vtr = FUN_14250ffc0(vm, _this);
        const ClassTraits::Function& ftr = static_cast<const ClassTraits::Function&>(vm.GetClassTraitsFunction());
        ASString name = vm.GetStringManager().GetBuiltin(AS3Builtin_objectPrefix_);

        if (vtr.GetTraitsType() == Traits_Function && vtr.IsInstanceTraits())
        {
            if (&vtr == &ftr.GetThunkTraits())
                name += FunctionKindName(vtr, (unsigned long)(UPInt)&_this.AsThunk());
            else if (&vtr == &ftr.GetThunkFunctionTraits())
                name += FunctionKindName(vtr, (unsigned long)(UPInt)&_this.AsThunkFunction().GetThunk());
            else if (&vtr == &ftr.GetMethodIndTraits())
                name += FunctionKindName(vtr, (unsigned long)_this.GetMethodInd());
            else
                name += FunctionKindName(vtr, (unsigned long)static_cast<const InstanceTraits::Function&>(
                                                  _this.GetObject()->GetTraits()).GetMethodInfoInd());
        }
        else
            name += vtr.GetName();

        name += vm.GetStringManager().GetBuiltin(AS3Builtin_closeBracket_);
        result = name;
    }

    // @0x1423e29b0
    void Number::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassNumber))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_zero);
        else
            AS3toString(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e2a50
    void Number::toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        toStringProto(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e2af0
    void Number::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassNumber))
            result.SetNumber(0);
        else if (!_this.IsNumber())
            vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        else
            result = _this;
    }

    // @0x1423e5750
    void int_::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassSInt))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_zero);
        else
            AS3toString(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e57f0
    void int_::toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        toStringProto(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e5890
    void int_::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassSInt))
            result.SetSInt32(0);
        else
            AS3valueOf(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e66a0
    void uint::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassUInt))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_zero);
        else
            AS3toString(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e6740
    void uint::toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        toStringProto(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e67e0
    void uint::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassUInt))
            result.SetUInt32(0);
        else
            AS3valueOf(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e6fe0
    void Boolean::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsBool())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = vm.GetStringManager().GetBuiltin(_this.AsBool() ? AS3Builtin_true : AS3Builtin_false);
    }

    // @0x1423e7050
    void Boolean::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassBoolean))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_false);
        else
            AS3toString(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e7120
    void Boolean::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (MS2_AS3_ON_PROTOTYPE(GetClassBoolean))
            result.SetBool(false);
        else if (!_this.IsBool())
            vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        else
            result = _this;
    }

    #undef MS2_AS3_ON_PROTOTYPE

    // ClassTraits CoerceValue for the primitive classes (defined after the *Proto users, as in the exe's TU order).
    static bool MS2_AS3_CoerceNumber(const Value& v, Value& result);
    static bool MS2_AS3_CoerceSInt(const Value& v, Value& result);
    static bool MS2_AS3_CoerceUInt(const Value& v, Value& result);

    // The *Proto forms of toFixed/toPrecision: coerce this to the class's primitive type, then call the AS3 method.
    #define MS2_AS3_COERCED_PROTO(cls, method, coerce, traits) \
        Value coerced_this; \
        if (!coerce(_this, coerced_this)) \
            return vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, FUN_14250ffc0(vm, _this).GetName().ToCStr(), \
                vm.traits().GetName().ToCStr())); \
        cls::method(ti, vm, coerced_this, result, argc, argv)

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e2ff0
    void Number::toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(Number, AS3toFixed, MS2_AS3_CoerceNumber, GetClassTraitsNumber);
    }

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e3180
    void Number::toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(Number, AS3toPrecision, MS2_AS3_CoerceNumber, GetClassTraitsNumber);
    }

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e5c10
    void int_::toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(int_, AS3toFixed, MS2_AS3_CoerceSInt, GetClassTraitsSInt);
    }

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e5da0
    void int_::toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(int_, AS3toPrecision, MS2_AS3_CoerceSInt, GetClassTraitsSInt);
    }

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e6b60
    void uint::toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(uint, AS3toFixed, MS2_AS3_CoerceUInt, GetClassTraitsUInt);
    }

    // MS2-FUNCTIONAL: stack frame differs (exe keeps the CheckResult/ASString temps in home slots)
    // @0x1423e6cf0
    void uint::toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_COERCED_PROTO(uint, AS3toPrecision, MS2_AS3_CoerceUInt, GetClassTraitsUInt);
    }

    #undef MS2_AS3_COERCED_PROTO

    // toExponential: AS3toExponential (defined below) is inlined into the *Proto form.

    #define MS2_AS3_EXPONENTIAL_PROTO(coerce, traits, method) \
        Value coerced_this; \
        if (!coerce(_this, coerced_this)) \
            return vm.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, vm, FUN_14250ffc0(vm, _this).GetName().ToCStr(), \
                vm.traits().GetName().ToCStr())); \
        method(ti, vm, coerced_this, result, argc, argv)

    // @0x1423e2d40
    void Number::toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_EXPONENTIAL_PROTO(MS2_AS3_CoerceNumber, GetClassTraitsNumber, Number::AS3toExponential);
    }

    // @0x1423e5960
    void int_::toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_EXPONENTIAL_PROTO(MS2_AS3_CoerceSInt, GetClassTraitsSInt, int_::AS3toExponential);
    }

    // @0x1423e68b0
    void uint::toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_EXPONENTIAL_PROTO(MS2_AS3_CoerceUInt, GetClassTraitsUInt, uint::AS3toExponential);
    }

    #undef MS2_AS3_EXPONENTIAL_PROTO

    #define MS2_AS3_DEFINE_TOEXPONENTIAL(cls, number) \
        void cls::AS3toExponential(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv) \
        { \
            UInt32 digits = 0; \
            if (argc > 0 && !argv[0].Convert2UInt32(digits)) \
                return; \
            if (digits > 20) \
                return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm)); \
            DoubleFormatter f(number); \
            f.SetType(DoubleFormatter::FmtScientific).SetPrecision(digits).Convert(); \
            result = vm.GetStringManager().CreateString(f.GetResult().ToCStr(), f.GetSize()); \
        }
    // @0x1423e2850
    MS2_AS3_DEFINE_TOEXPONENTIAL(Number, _this.AsNumber())
    // @0x1423e55f0
    MS2_AS3_DEFINE_TOEXPONENTIAL(int_, _this.AsInt())
    // @0x1423e6540
    MS2_AS3_DEFINE_TOEXPONENTIAL(uint, _this.AsUInt())
    #undef MS2_AS3_DEFINE_TOEXPONENTIAL

    #define MS2_AS3_DEFINE_COERCE(name, type, convert, set) \
        static bool name(const Value& v, Value& result) \
        { \
            type n; \
            if (!v.convert(n)) \
                return false; \
            result.set(n); \
            return true; \
        }
    MS2_AS3_DEFINE_COERCE(MS2_AS3_CoerceNumber, Value::Number, Convert2Number, SetNumber)
    MS2_AS3_DEFINE_COERCE(MS2_AS3_CoerceSInt, SInt32, Convert2Int32, SetSInt32)
    MS2_AS3_DEFINE_COERCE(MS2_AS3_CoerceUInt, UInt32, Convert2UInt32, SetUInt32)
    #undef MS2_AS3_DEFINE_COERCE

    // @0x1423e6090
    void Namespace::prefixGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsNamespace())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this.AsNamespace().GetPrefix();
    }

    // @0x1423e6100
    void Namespace::uriGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsNamespace())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this.AsNamespace().GetUri();
    }

    // @0x1423e6170
    void Namespace::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsNamespace())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this.AsNamespace().GetUri();
    }

    // @0x1423e61e0
    void Namespace::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        const Value::KindType kind = _this.GetKind();
        if (Value::IsObject(kind) && _this.GetObject() != NULL)
        {
            if (_this.GetObject() == &FUN_142508460(&vm.GetClassTraitsNamespace().GetInstanceTraits()).GetPrototype())
                return result.Assign(vm.GetStringManager().GetBuiltin(AS3Builtin_empty_));
        }
        else if (kind == Value::kNamespace)
            return result.Assign(_this.AsNamespace().GetUri());
        vm.ThrowTypeError(VM::Error(VM::eUndefinedVarError, vm));
    }

    // @0x1423e62b0
    void Namespace::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        toStringProto(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e7410
    void String::lengthGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        result.SetSInt32(_this.AsString().GetLength());
    }

    // ECMA 15.5.4.7; generic: this and the search string are converted to strings first.
    // MS2-FUNCTIONAL: inliner choice differs (exe inlines the found/not-found SetSInt32 tail, calls it out of line elsewhere)
    // @0x1423e7490
    void String::AS3indexOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (argc == 0)
        {
            result.SetSInt32(-1);
            return;
        }

        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;

        ASString search = sm.CreateEmptyString();
        if (!argv[0].Convert2String(search))
            return;

        if (search.GetLength() == 0)
        {
            result.SetSInt32(0);
            return;
        }
        const char* ps = search.ToCStr();
        const char* p = str.ToCStr();

        SInt32 start = 0;
        if (argc > 1 && !argv[1].Convert2Int32(start))
            return;

        UInt32 ch;
        const UInt32 first = UTF8Util::DecodeNextChar(&ps);
        for (int i = 0; (ch = UTF8Util::DecodeNextChar(&p)) != 0; i++)
        {
            if (i >= start && ch == first)
            {
                const char* s1 = p;
                const char* s2 = ps;
                UInt32 c1, c2 = 0;
                for (;;)
                {
                    c1 = UTF8Util::DecodeNextChar(&s1);
                    c2 = UTF8Util::DecodeNextChar(&s2);
                    if (c1 == 0 || c2 == 0 || c1 != c2)
                        break;
                }
                if (c2 == 0)
                {
                    result.SetSInt32(i);
                    return;
                }
                if (c1 == 0)
                {
                    result.SetSInt32(-1);
                    return;
                }
            }
        }
        result.SetSInt32(-1);
    }

    // True when the object _this is the prototype object of cls. The class is looked up before _this is read (the exe loads
    // the object pointer between the class lookup and the GetPrototype call).
    static SF_INLINE bool IsPrototypeOf(const Value& _this, Class& cls)
    {
        return _this.GetObject() == &cls.GetPrototype();
    }

    // @0x1423e1be0
    void QName::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && IsPrototypeOf(_this, FUN_142508460(vm.GetXMLSupport().GetITraitsQName())))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
        else
        {
            const AS3::Traits& tr = FUN_14250ffc0(vm, _this);
            if (tr.GetTraitsType() != Traits_QName || tr.IsClassTraits())
                return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));

            Instances::fl::QName* obj = static_cast<Instances::fl::QName*>(_this.GetObject());
            ASString str = vm.GetStringManager().CreateEmptyString();
            obj->AS3toString(str);
            result = str;
        }
    }

    // @0x1423e1840
    void XMLList::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && IsPrototypeOf(_this, FUN_142508460(vm.GetXMLSupport().GetITraitsXMLList())))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
        else
        {
            if (!IsXMLListObject(_this))
                return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm, "XMLList::toStringProto"));

            Instances::fl::XMLList* obj = static_cast<Instances::fl::XMLList*>(_this.GetObject());
            ASString str = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
            obj->AS3toString(str);
            result = str;
        }
    }

    // XMLElement::ForEachAttr (sfr_as3_03), inlined into XMLList::AS3hasOwnProperty.
    static SF_INLINE UInt32 XMLElementForEachAttr(Instances::fl::XMLElement& el, const Multiname& prop_name,
                                                 Instances::fl::XMLElement::CallBack& cb)
    {
        UInt32 num = 0;
        if (!prop_name.Name.IsString())
            return num;
        const UPInt size = el.Attrs.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            if (el.Attrs[i]->Matches(prop_name))
            {
                ++num;
                if (!cb.Call(i))
                    return num;
            }
        }
        return num;
    }

    // XMLElement::HasProperty (sfr_as3_04), inlined into XMLList::AS3hasOwnProperty.
    static SF_INLINE bool XMLElementHasProperty(Instances::fl::XMLElement& el, const Multiname& prop_name)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
            return ind == 0;
        Instances::fl::EmptyCallBack cb(el);
        if (prop_name.IsAttr())
        {
            if (XMLElementForEachAttr(el, prop_name, cb) != 0)
                return true;
            return false;
        }
        if (el.ForEachChild(prop_name, cb) != 0)
            return true;
        return false;
    }

    // XMLList::HasProperty (sfr_as3_04), inlined into XMLList::AS3hasOwnProperty.
    static SF_INLINE bool XMLListHasProperty(Instances::fl::XMLList& list, const Multiname& prop_name)
    {
        bool found = false;
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind < list.List.GetSize())
                found = true;
        }
        else
        {
            const UPInt size = list.List.GetSize();
            for (UPInt i = 0; i < size; ++i)
            {
                Instances::fl::XML* x = list.List[i];
                if (x->GetKind() != Instances::fl::XML::kElement)
                    continue;
                if (XMLElementHasProperty(*static_cast<Instances::fl::XMLElement*>(x), prop_name))
                {
                    found = true;
                    break;
                }
            }
        }
        return found;
    }

    // @0x1423e12f0
    void XMLList::AS3hasOwnProperty(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (argc != 0 && IsXMLListObject(_this))
        {
            Instances::fl::XMLList* list = static_cast<Instances::fl::XMLList*>(_this.GetObject());
            Multiname prop_name(vm, argv[0]);
            const bool rc = XMLListHasProperty(*list, prop_name);
            if (rc)
            {
                FUN_142421710(result, rc);
                return;
            }
        }
        Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e77a0
    void String::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && _this.GetObject() == &vm.GetClassString().GetPrototype())
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
        else
            AS3toString(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e7990
    void String::valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && _this.GetObject() == &vm.GetClassString().GetPrototype())
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
        else
            AS3valueOf(ti, vm, _this, result, argc, argv);
    }

    // @0x1423e7a30
    void XML::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && IsPrototypeOf(_this, FUN_142508460(vm.GetXMLSupport().GetITraitsXML())))
            result = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
        else
        {
            if (!IsXMLObject(_this))
                return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm, "XML::toStringProto"));

            Instances::fl::XML* obj = static_cast<Instances::fl::XML*>(_this.GetObject());
            ASString str = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
            obj->AS3toString(str);
            result = str;
        }
    }

    // @0x1423e7b30
    void XML::PropertyIsEnumerableProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && IsPrototypeOf(_this, FUN_142508460(vm.GetXMLSupport().GetITraitsXML())))
            return Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);

        if (!IsXMLObject(_this))
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm, "XML::PropertyIsEnumerableProto"));

        static_cast<Instances::fl::XML*>(_this.GetObject())->AS3propertyIsEnumerable(result, argc, argv);
    }

    // MS2-FUNCTIONAL: exe inlines AS3hasOwnProperty (direct vcall of the XML's HasOwnProperty slot +0xf0)
    // @0x1423e7c30
    void XML::HasOwnPropertyProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsObject() && IsPrototypeOf(_this, FUN_142508460(vm.GetXMLSupport().GetITraitsXML())))
            return Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);

        if (!IsXMLObject(_this))
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm, "XML::HasOwnPropertyProto"));

        Instances::fl::XML* obj = static_cast<Instances::fl::XML*>(_this.GetObject());
        if (argc < 1 || !argv[0].IsString())
            return vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "XML::HasOwnPropertyProto"));

        bool r;
        obj->AS3hasOwnProperty(r, argv[0].AsString());
        FUN_142421710(result, r);
    }
}}

namespace Instances { namespace fl
{
    // @0x1423f5550
    void Array::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc == 1 && argv[0].IsNumeric())
        {
            // The exe (0x1423f5585) rejects a Number with a fractional part before converting, then only checks
            // for a negative length; the length is truncated to 32 bits with no upper bound check.
            if (argv[0].IsNumber())
            {
                double ip;
                const double frac = modf(argv[0].AsNumber(), &ip);
                if (frac != 0)
                    return GetVM().ThrowRangeError(VM::Error(static_cast<VM::ErrorID>(1005), GetVM(), static_cast<SInt32>(frac)));
            }
            Value::Number number;
            if (!argv[0].Convert2Number(number))
                return;
            if (number < 0)
                return GetVM().ThrowRangeError(VM::Error(static_cast<VM::ErrorID>(1005), GetVM(), static_cast<SInt32>(number)));
            SA.Resize(static_cast<UInt32>(static_cast<SInt64>(number)));
            return;
        }

        SA.Append(argc, argv);
    }

    // Array's toString/toLocaleString are not generic: this is assumed to be an Array.
    // @0x1423e0260
    void Array::toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        result = static_cast<Array*>(_this.GetObject())->ToLocaleStringInternal();
    }

    // @0x1423e02a0
    void Array::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        const ASString& sep = vm.GetStringManager().GetBuiltin(AS3Builtin_comma_);
        result = static_cast<Array*>(_this.GetObject())->ToStringInternal(sep);
    }
}}

// Argument defaults of the two-Value native methods, emitted out of line here (their ThunkFunc2 thunks are in
// sfr_as3_04): Array::AS3sortOn @0x1423e8e60, AS3every @0x1423e8fc0, AS3filter @0x1423e88e0, AS3forEach
// @0x1423e8a40, AS3map @0x1423e8ba0, AS3some @0x1423e8d00 (null thisObject/options), XML::AS3addNamespace..
// @0x1423e9120/9280/93e0, XMLList @0x1423e9540/96a0/9800 (undefined).
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 16, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 17, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 18, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 19, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 12, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::Array, 15, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XML, 20, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XML, 21, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XML, 33, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XMLList, 28, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XMLList, 29, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl::XMLList, 36, const Value&, const Value&>(StringManager&);
namespace Instances {
    // VM::ExecuteUnsafe: ExecuteInternalUnsafe keeping the result.
    static SF_INLINE void VMExecuteUnsafe(VM& vm, const Value& func, const Value& _this, Value& result, unsigned argc,
                                          const Value* argv)
    {
        vm.ExecuteInternalUnsafe(func, _this, result, argc, argv, false);
    }

    // @0x1423e4bf0
    void FunctionBase::call(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        Value r = Value::GetUndefined();
        if (argc < 1)
            VMExecuteUnsafe(vm, _this, Value(FUN_14250a550(vm)), r, argc, argv);
        else
            VMExecuteUnsafe(vm, _this, argv[0].IsNullOrUndefined() ? Value(FUN_14250a550(vm)) : argv[0], r, argc - 1,
                            argv + 1);
        result.Swap(r);
    }

    // HashLH<UPInt, Value>::Get on the sparse part.
    static inline const Value* SparseHashGet(const SparseArray& sa, UPInt ind)
    {
        const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = sa.ValueH.mHash.GetAlt(ind);
        return p ? &p->Second : 0;
    }

    // SparseArray::At, inlined here (out of line in sfr_as3_03).
    static SF_INLINE const Value& SparseAt(const SparseArray& sa, UPInt ind)
    {
        if (ind < sa.ValueA.GetSize())
            return sa.ValueA[ind];
        if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
        {
            if (const Value* v = SparseHashGet(sa, ind))
                return *v;
        }
        return sa.DefaultValue;
    }

    // MS2-FUNCTIONAL: same flow; exe keeps the hash node->value select as a cmove (as in SparseArray::At) and allocates registers differently.
    // @0x1423e4e40
    void FunctionBase::apply(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        Value r = Value::GetUndefined();
        switch (argc)
        {
        case 0:
            VMExecuteUnsafe(vm, _this, Value::GetUndefined(), r, argc, argv);
            break;
        case 1:
            VMExecuteUnsafe(vm, _this, argv[0], r, 0, NULL);
            break;
        default:
        {
            Value coerced;
            if (vm.GetClassTraitsArray().Coerce(argv[1], coerced))
            {
            ValueArrayDH args(vm.GetMemoryHeap());
            unsigned f_argc = 0;
            const Value* f_argv = NULL;
            if (!coerced.IsNull())
            {
                Instances::fl::Array* array = static_cast<Instances::fl::Array*>(coerced.GetObject());
                const SparseArray& sa = array->SA;
                if (sa.GetSize() > sa.ValueA.GetSize())
                {
                    args.Resize(sa.GetSize());
                    for (UPInt i = 0; i < args.GetSize(); ++i)
                        args[i] = SparseAt(sa, i);
                    f_argc = (unsigned)args.GetSize();
                    f_argv = args.GetDataPtr();
                }
                else
                {
                    f_argc = (unsigned)sa.ValueA.GetSize();
                    f_argv = sa.ValueA.GetDataPtr();
                }
            }
            VMExecuteUnsafe(vm, _this, argv[0], r, f_argc, f_argv);
            }
            else
                return vm.ThrowTypeError(VM::Error((VM::ErrorID)1116 /* eApplyError */, vm));
        }
        }
        result.Swap(r);
    }

    // MS2-FUNCTIONAL: matches the function-versus-thunk string semantics; local formatter and ASString codegen differs.
    // @0x1423e4a80
    void FunctionBase::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                                    const Value* argv)
    {
        StringManager& strings = vm.GetStringManager();
        if (!_this.IsThunk())
        {
            result.Assign(strings.CreateConstString("function Function() {}"));
            return;
        }

        LongFormatter formatter(static_cast<unsigned long>(reinterpret_cast<UPInt>(&_this.AsThunk())));
        formatter.SetBase(16).Convert();
        ASString text = strings.CreateConstString("[object Function-");
        text.Append(formatter.ToCStr(), strlen(formatter.ToCStr()));
        text.Append("]", 1);
        result.Assign(text);
    }
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
using NamespaceInstanceSetBase = HashSetBase<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc,
    NamespaceInstanceFactory::NamespaceHashFunc, AllocatorLH<Instances::Namespace*, Stat_Default_Mem>,
    HashsetEntry<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc>>;
}}}
namespace Scaleform {
namespace GFx { namespace AS3 { namespace Impl {
template<class A, class B, class C> struct Triple
{
    A First;
    B Second;
    C Third;
};
}}}

namespace GFx { namespace AS3 { namespace Impl {
class CompareAsNumber {
public:
    explicit CompareAsNumber(bool desc) : Desc(desc) {}
    bool operator()(const Triple<Value::Number, const Value*, unsigned>& a,
                    const Triple<Value::Number, const Value*, unsigned>& b) const
    {
        if (Desc)
            return b.First < a.First;
        return a.First < b.First;
    }
    bool Equal(const Triple<Value::Number, const Value*, unsigned>& a,
               const Triple<Value::Number, const Value*, unsigned>& b) const
    { return a.First == b.First; }
private:
    const bool Desc;
};
class CompareAsString {
public:
    explicit CompareAsString(const GFx::AS3::CompareAsString& cmp) : Cmp(cmp) {}
    bool operator()(const Triple<ASString, const Value*, unsigned>& a,
                    const Triple<ASString, const Value*, unsigned>& b) const
    { return Cmp.Compare(a.First, b.First) < 0; }
    bool Equal(const Triple<ASString, const Value*, unsigned>& a,
               const Triple<ASString, const Value*, unsigned>& b) const
    { return Cmp.Compare(a.First, b.First) == 0; }
private:
    GFx::AS3::CompareAsString Cmp;
};
}}}

using AS3StringValueTriple = GFx::AS3::Impl::Triple<GFx::ASString, const GFx::AS3::Value*, unsigned>;
using AS3NumberValueTriple = GFx::AS3::Impl::Triple<GFx::AS3::Value::Number, const GFx::AS3::Value*, unsigned>;
using AS3StringValueTripleArray = ArrayDH<AS3StringValueTriple>;
using AS3NumberValueTripleArray = ArrayDH<AS3NumberValueTriple>;
// @0x1423e99d0
template bool Alg::QuickSortSafe(AS3StringValueTripleArray&, GFx::AS3::Impl::CompareAsString);
// @0x1423ea060
template bool Alg::QuickSortSlicedSafe(AS3NumberValueTripleArray&, UPInt, UPInt, GFx::AS3::Impl::CompareAsNumber);
// MS2-FUNCTIONAL: same code; the exe adds the element offset and the array base in the other operand order.
// @0x1423ea400
template bool Alg::QuickSortSlicedSafe(AS3StringValueTripleArray&, UPInt, UPInt, GFx::AS3::Impl::CompareAsString);
using AS3ValuePtrPairArray = ArrayDH<GFx::AS3::ValuePtrPair>;
// @0x1423e9960
template bool Alg::QuickSortSafe(AS3ValuePtrPairArray&, GFx::AS3::CompareOn);
// @0x1423e9990
template bool Alg::QuickSortSafe(AS3ValuePtrPairArray&, GFx::AS3::CompareValuePtr);
// @0x1423e9a00
template bool Alg::QuickSortSlicedSafe(AS3ValuePtrPairArray&, UPInt, UPInt, GFx::AS3::CompareOn);
// @0x1423e9d30
template bool Alg::QuickSortSlicedSafe(AS3ValuePtrPairArray&, UPInt, UPInt, GFx::AS3::CompareValuePtr);
using AS3StringValueTripleData = ArrayDataBase<AS3StringValueTriple,
    AllocatorDH<AS3StringValueTriple, Stat_Default_Mem>, ArrayDefaultPolicy>;
// @0x1423f0630
template AS3StringValueTripleData::~ArrayDataBase();

using AS3TraitsPtr = GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>;
using AS3TraitsPtrArrayData = ArrayDataBase<AS3TraitsPtr, AllocatorLH<AS3TraitsPtr, Stat_Default_Mem>, ArrayDefaultPolicy>;
// @0x1423f07a0
template AS3TraitsPtrArrayData::~ArrayDataBase();

using AS3XMLPtr = GFx::AS3::SPtr<GFx::AS3::Instances::fl::XML>;
using AS3XMLPtrArrayData = ArrayDataBase<AS3XMLPtr, AllocatorDH<AS3XMLPtr, Stat_Default_Mem>, ArrayDefaultPolicy>;
// @0x1423f0820
template AS3XMLPtrArrayData::~ArrayDataBase();

using AS3ValueArrayData = ArrayDataBase<GFx::AS3::Value,
    AllocatorLH<GFx::AS3::Value, Stat_Default_Mem>, ArrayDefaultPolicy>;
// @0x1423f0a20
template AS3ValueArrayData::~ArrayDataBase();

using AS3ConstStringKey = GFx::AS3::Instances::fl::ConstStringKey;
using AS3ConstStringHash = GFx::AS3::Instances::fl::ConstStringHashFn;
using AS3ConstStringNode = HashNode<AS3ConstStringKey, const GFx::AS3::ClassInfo*, AS3ConstStringHash>;
using AS3ConstStringSet = HashSetBase<AS3ConstStringNode,
    AS3ConstStringNode::NodeHashF, AS3ConstStringNode::NodeAltHashF,
    AllocatorGH<AS3ConstStringKey, 328>,
    HashsetCachedNodeEntry<AS3ConstStringNode, AS3ConstStringNode::NodeHashF>>;
// @0x1423f0aa0
template AS3ConstStringSet::~HashSetBase();
// @0x1423eaeb0
template void AS3ConstStringSet::add<AS3ConstStringNode::NodeRef>(void*, const AS3ConstStringNode::NodeRef&, UPInt);

template void GFx::AS3::NamespaceInstanceSetBase::Add<GFx::AS3::Instances::Namespace*>(
    void*, GFx::AS3::Instances::Namespace* const&);

using AS3String = GFx::ASString;
using AS3StringHashSetBase = HashSetBase<AS3String, FixedSizeHash<AS3String>, FixedSizeHash<AS3String>,
    AllocatorDH<AS3String, Stat_Default_Mem>, HashsetCachedEntry<AS3String, FixedSizeHash<AS3String>>>;
template AS3String* AS3StringHashSetBase::Get<AS3String>(const AS3String&);
template void AS3StringHashSetBase::add<AS3String>(void*, const AS3String&, UPInt);

using AS3Value = GFx::AS3::Value;
using AS3ValueHashSetBase = HashSetBase<AS3Value, AS3Value::HashFunctor, AS3Value::HashFunctor,
    AllocatorGH<AS3Value, Stat_Default_Mem>, HashsetCachedEntry<AS3Value, AS3Value::HashFunctor>>;
template void AS3ValueHashSetBase::add<AS3Value>(void*, const AS3Value&, UPInt);
template HashsetCachedEntry<AS3Value, AS3Value::HashFunctor>::HashsetCachedEntry(
    const HashsetCachedEntry<AS3Value, AS3Value::HashFunctor>&);

using AS3UInt64ValueNode = HashNode<UInt64, GFx::AS3::Value, FixedSizeHash<UInt64>>;
using AS3UInt64ValueEntry = HashsetCachedNodeEntry<AS3UInt64ValueNode, AS3UInt64ValueNode::NodeHashF>;
using AS3UInt64ValueSetBase = HashSetBase<AS3UInt64ValueNode, AS3UInt64ValueNode::NodeHashF,
    AS3UInt64ValueNode::NodeAltHashF, AllocatorDH<AS3UInt64ValueNode, Stat_Default_Mem>,
    HashsetCachedNodeEntry<AS3UInt64ValueNode, AS3UInt64ValueNode::NodeHashF>>;
template const AS3UInt64ValueNode* AS3UInt64ValueSetBase::GetAlt<UInt64>(const UInt64&) const;
// @0x1423eb220
template void AS3UInt64ValueSetBase::add<AS3UInt64ValueNode::NodeRef>(void*, const AS3UInt64ValueNode::NodeRef&, UPInt);
// The generic add with CheckExpand expanded in place, as the exe inlines it here (our compiler keeps it out of line).
// @0x1423eacc0
template <> template <>
void AS3UInt64ValueSetBase::add<AS3UInt64ValueNode>(void* pheapAddr, const AS3UInt64ValueNode& key, UPInt h)
{
    if (pTable == 0)
        setRawCapacity(pheapAddr, HashMinSize);
    else if (pTable->EntryCount * 5 > (pTable->SizeMask + 1) * 4)
        setRawCapacity(pheapAddr, (pTable->SizeMask + 1) * 2);
    h &= pTable->SizeMask;
    pTable->EntryCount++;

    SPInt  idx  = h;
    AS3UInt64ValueEntry* home = &(E(idx));

    if (home->IsEmpty())
    {
        new (home) AS3UInt64ValueEntry(key, -1);
    }
    else
    {
        SPInt freeIdx = idx;
        do
        {
            freeIdx = (freeIdx + 1) & pTable->SizeMask;
        } while (!E(freeIdx).IsEmpty());
        AS3UInt64ValueEntry* freeSlot = &E(freeIdx);

        if (home->GetCachedHash(pTable->SizeMask) == (UPInt)idx)
        {
            new (freeSlot) AS3UInt64ValueEntry(*home);
            home->Value       = key;
            home->NextInChain = freeIdx;
        }
        else
        {
            SPInt walk = home->GetCachedHash(pTable->SizeMask);
            for (;;)
            {
                AS3UInt64ValueEntry* e = &E(walk);
                if (e->NextInChain == idx)
                {
                    new (freeSlot) AS3UInt64ValueEntry(*home);
                    e->NextInChain = freeIdx;
                    break;
                }
                walk = e->NextInChain;
            }
            home->Value       = key;
            home->NextInChain = -1;
        }
    }
    home->SetCachedHash(h);
}

using AS3TraitsKey = GFx::AS3::TClassTraitsCache::Key;
using AS3TraitsNode = HashNode<AS3TraitsKey, GFx::AS3::ClassTraits::Traits*, AS3TraitsKey::HashFunctor>;
using AS3TraitsSetBase = HashSetBase<AS3TraitsNode, AS3TraitsNode::NodeHashF, AS3TraitsNode::NodeAltHashF,
    AllocatorLH<AS3TraitsNode, GFx::AS3::StatMV_VM_VM_Mem>,
    HashsetCachedNodeEntry<AS3TraitsNode, AS3TraitsNode::NodeHashF>>;
template void AS3TraitsSetBase::add<AS3TraitsNode>(void*, const AS3TraitsNode&, UPInt);
template void AS3TraitsSetBase::add<AS3TraitsNode::NodeRef>(void*, const AS3TraitsNode::NodeRef&, UPInt);
}

namespace Scaleform { namespace Alg {
template <class ArrayT> void ReverseArray(ArrayT& values);

// @0x1423eaa80
template <> void ReverseArray<ArrayDH<GFx::AS3::Value, 2, ArrayDefaultPolicy>>(
    ArrayDH<GFx::AS3::Value, 2, ArrayDefaultPolicy>& values)
{
    SPInt left = 0;
    SPInt right = static_cast<SPInt>(values.GetSize()) - 1;
    while (left < right)
    {
        values[left].Swap(values[right]);
        ++left;
        --right;
    }
}
}}

// MsgFormat argument binders the error-message formatting in this file instantiates.
template void Scaleform::MsgFormat::FormatD1<int>(const int&);
template void Scaleform::MsgFormat::FormatD1<const char*>(const char* const&);
template Scaleform::String Scaleform::AsString<long>(const long&);
template Scaleform::String Scaleform::AsString<unsigned long>(const unsigned long&);

// The SPtr assignments, the XML array copy and the namespace array destructor the exe keeps out of line here.
namespace Scaleform {
using AS3NamespacePtr = GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>;
// @0x1423f1840
template AS3NamespacePtr& AS3NamespacePtr::operator=(GFx::AS3::Instances::Namespace*);
// @0x1423f18b0
template AS3NamespacePtr& AS3NamespacePtr::operator=(Pickable<GFx::AS3::Instances::Namespace>);
// @0x1423f1970
template AS3XMLPtr& AS3XMLPtr::operator=(GFx::AS3::Instances::fl::XML*);
// @0x1423f19e0
template AS3XMLPtr& AS3XMLPtr::operator=(Pickable<GFx::AS3::Instances::fl::XML>);
using AS3XMLPtrArrayLHBase = ArrayBase<ArrayData<AS3XMLPtr, AllocatorLH<AS3XMLPtr, Stat_Default_Mem>, ArrayDefaultPolicy>>;
// @0x1423f1760
template const AS3XMLPtrArrayLHBase& AS3XMLPtrArrayLHBase::operator=(const AS3XMLPtrArrayLHBase&);
using AS3NamespacePtrArrayData = ArrayDataBase<AS3NamespacePtr, AllocatorDH<AS3NamespacePtr, Stat_Default_Mem>,
    ArrayDefaultPolicy>;
// @0x1423f06a0
template AS3NamespacePtrArrayData::~ArrayDataBase();
}

// Namespace::operator= and Value::operator=(Namespace*), out of line in the exe (sfr_as3_02 calls the first).
// @0x1423f1b00
Scaleform::GFx::AS3::Instances::Namespace& FUN_1423f1b00(Scaleform::GFx::AS3::Instances::Namespace* self,
                                                         const Scaleform::GFx::AS3::Instances::Namespace& other)
{
    return *self = other;
}
// MS2-FUNCTIONAL: the exe stores the namespace through a whole VU and inlines its AddRef; the header's
// AssignUnsafe sets the pointer alone and calls AddRefInternal.
// @0x1423f1b90
Scaleform::GFx::AS3::Value& FUN_1423f1b90(Scaleform::GFx::AS3::Value* self,
                                          Scaleform::GFx::AS3::Instances::Namespace* ns)
{
    return *self = ns;
}

// Native method thunks without pdata that only the ThunkInfo tables of data_rdata_sf_a / data_data_game reach: they
// pass (result, argc, argv) or the result alone to ThunkFuncN<...>::Method (sfr_as3di_01). Pinned at the end.
namespace Scaleform { namespace GFx { namespace AS3 {
template struct ThunkFunc2<Instances::ThunkFunction, 0, Value, unsigned, const Value*>;
template struct ThunkFunc0<Instances::fl::QName, 1, Value>;
template struct ThunkFunc2<Classes::fl::String, 0, Value, unsigned, const Value*>;
template struct ThunkFunc2<Classes::fl::Error, 1, Value, unsigned, const Value*>;
template struct ThunkFunc2<Instances::fl::Array, 2, Value, unsigned, const Value*>;

// Object.prototype's hasOwnProperty / propertyIsEnumerable / toLocaleString / valueOf (pdata-less ThunkInfo targets):
// the first three forward to the Object traits' own thunks, valueOf returns this.
// @0x1423e41a0
void FUN_1423e41a0(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
{
    InstanceTraits::fl::Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
}
// @0x1423e41b0
void FUN_1423e41b0(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
{
    InstanceTraits::fl::Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);
}
// @0x1423e4910
void FUN_1423e4910(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
{
    InstanceTraits::fl::Object::toStringProto(ti, vm, _this, result, argc, argv);
}
// @0x1423e4920
void FUN_1423e4920(const ThunkInfo&, VM&, const Value& _this, Value& result, unsigned, const Value*)
{
    result.Assign(_this);
}
// Calls each inline Instances::fl ctor above out of line (inline_depth 0), so cl emits their bodies (and with them
// the vftables and deleting dtors) in this unit. Nothing calls it.
#pragma inline_depth(0)
void MS2_Sfr01cEmitInstanceCtors(void* p, InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& s,
                                 Instances::Namespace* pns, Instances::fl::XML* parent)
{
    using namespace Instances::fl;
    new(p) Array(t);
    new(p) Catch(t);
    new(p) Date(t);
    new(p) Error(t);
    new(p) Error(t, 0, s);
    new(p) Instances::fl::Object(t);
    new(p) QName(t);
    new(p) QName(t, s, pns);
    new(p) RegExp(t);
    new(p) XMLList(t);
    new(p) XML(t);
    new(p) XML(t, s, parent);
    new(p) XMLAttr(t, ns, s, s, parent);
    new(p) XMLComment(t, s, parent);
    new(p) XMLElement(t, ns, s, parent);
    new(p) XMLProcInstr(t, s, s, parent);
    new(p) XMLText(t, s, parent);
}
#pragma inline_depth()
}}}

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Interface@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313f870
// MS2-PIN: ??_7Object@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313f650
// MS2-PIN: ??_7Object@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f590
// MS2-PIN: ??_7Namespace@Instances@AS3@GFx@Scaleform@@6B@ 0x143140070
// MS2-PIN: ??_7Array@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431415b0
// MS2-PIN: ??_7Catch@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140530
// MS2-PIN: ??_7Date@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142508
// MS2-PIN: ??_7Error@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141b80
// MS2-PIN: ??_7QName@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140810
// MS2-PIN: ??_7RegExp@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141880
// MS2-PIN: ??_7XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436d0
// MS2-PIN: ??_7NamespaceInstanceFactory@AS3@GFx@Scaleform@@6B@ 0x143140af8
// MS2-PIN: ??_7Array@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141670
// MS2-PIN: ??_7Boolean@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141148
// MS2-PIN: ??_7Catch@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431405f0
// MS2-PIN: ??_7Date@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431425c8
// MS2-PIN: ??_7Error@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141c40
// MS2-PIN: ??_7Namespace@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431400a8
// MS2-PIN: ??_7Number@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140b00
// MS2-PIN: ??_7QName@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431408d0
// MS2-PIN: ??_7RegExp@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141940
// MS2-PIN: ??_7String@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141360
// MS2-PIN: ??_7XML@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143142bb0
// MS2-PIN: ??_7XMLList@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143143790
// MS2-PIN: ??_7int_@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140d28
// MS2-PIN: ??_7uint@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140f38
// MS2-PIN: ??_7Object@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x14313f788
// MS2-PIN: ??_7Array@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431417a0
// MS2-PIN: ??_7Boolean@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141278
// MS2-PIN: ??_7Catch@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140728
// MS2-PIN: ??_7Date@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431426f8
// MS2-PIN: ??_7Error@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141d70
// MS2-PIN: ??_7Math@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431428e8
// MS2-PIN: ??_7Namespace@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431401e0
// MS2-PIN: ??_7Number@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140c30
// MS2-PIN: ??_7QName@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140a08
// MS2-PIN: ??_7RegExp@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141a78
// MS2-PIN: ??_7String@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141490
// MS2-PIN: ??_7XML@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143142ce0
// MS2-PIN: ??_7XMLList@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431438d0
// MS2-PIN: ??_7int_@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140e58
// MS2-PIN: ??_7uint@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141068
// MS2-PIN: ??_7ArgumentError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142470
// MS2-PIN: ??_7Array@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141710
// MS2-PIN: ??_7Boolean@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431411e8
// MS2-PIN: ??_7Catch@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140698
// MS2-PIN: ??_7Date@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142668
// MS2-PIN: ??_7DefinitionError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141ea0
// MS2-PIN: ??_7Error@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141ce0
// MS2-PIN: ??_7EvalError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141f38
// MS2-PIN: ??_7int_@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140dc8
// MS2-PIN: ??_7Math@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142858
// MS2-PIN: ??_7Namespace@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140150
// MS2-PIN: ??_7Number@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140ba0
// MS2-PIN: ??_7Object@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313f6f8
// MS2-PIN: ??_7QName@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140978
// MS2-PIN: ??_7RangeError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141fc8
// MS2-PIN: ??_7ReferenceError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142058
// MS2-PIN: ??_7RegExp@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431419e8
// MS2-PIN: ??_7SecurityError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431420f0
// MS2-PIN: ??_7String@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141400
// MS2-PIN: ??_7SyntaxError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142188
// MS2-PIN: ??_7TypeError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142220
// MS2-PIN: ??_7uint@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140fd8
// MS2-PIN: ??_7UninitializedError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431423d8
// MS2-PIN: ??_7URIError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431422b0
// MS2-PIN: ??_7VerifyError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142340
// MS2-PIN: ??_7XML@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142c50
// MS2-PIN: ??_7XMLList@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143143838
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$0A@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e02e0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$00NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e03c0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$01NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e04a0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$02NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0580
// MS2-PIN: ?Func@?$ThunkFunc2@VMath@fl@Classes@AS3@GFx@Scaleform@@$03NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e07e0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$04NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0910
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$05NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e09f0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$06NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0ad0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$07NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0bb0
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$08NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0c90
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$09NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0d70
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$0L@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0e70
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$0M@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0f50
// MS2-PIN: ?Func@?$ThunkFunc1@VMath@fl@Classes@AS3@GFx@Scaleform@@$0N@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1030
// MS2-PIN: ?Func@?$ThunkFunc2@VMath@fl@Classes@AS3@GFx@Scaleform@@$0O@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1110
// MS2-PIN: ?Func@?$ThunkFunc2@VMath@fl@Classes@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1240
// MS2-PIN: ?Func@?$ThunkFunc2@VMath@fl@Classes@AS3@GFx@Scaleform@@$0BA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1260
// MS2-PIN: ?Func@?$ThunkFunc0@VMath@fl@Classes@AS3@GFx@Scaleform@@$0BB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1280
// MS2-PIN: ?Func@?$ThunkFunc0@VQName@fl@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1aa0
// MS2-PIN: ?Func@?$ThunkFunc0@VQName@fl@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VQName@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1b30
// MS2-PIN: ?Func@?$ThunkFunc0@VError@fl@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1fb0
// MS2-PIN: ?Func@?$ThunkFunc0@VError@fl@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e2010
// MS2-PIN: ?Func@?$ThunkFunc0@VError@fl@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e2080
// MS2-PIN: ?Func@?$ThunkFunc1@VError@fl@Classes@AS3@GFx@Scaleform@@$0A@VASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e20f0
// MS2-PIN: ?Func@?$ThunkFunc0@VArray@fl@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3b30
// MS2-PIN: ?Func@?$ThunkFunc1@VArray@fl@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3b90
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3ff0
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5150
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e51c0
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5220
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5280
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$03J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e52e0
// MS2-PIN: ?Func@?$ThunkFunc1@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5340
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e53b0
// MS2-PIN: ?Func@?$ThunkFunc0@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$06_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5410
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e7360
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e76f0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$01J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e7d80
// MS2-PIN: ?Func@?$ThunkFunc1@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e5470
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e7840
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BA@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e88e0
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BB@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e8a40
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BC@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e8ba0
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BD@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e8d00
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0M@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e8e60
// MS2-PIN: ??$ThunkMakeDefs2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0P@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e8fc0
// MS2-PIN: ??$ThunkMakeDefs2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BE@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e9120
// MS2-PIN: ??$ThunkMakeDefs2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BF@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e9280
// MS2-PIN: ??$ThunkMakeDefs2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CB@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e93e0
// MS2-PIN: ??$ThunkMakeDefs2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BM@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e9540
// MS2-PIN: ??$ThunkMakeDefs2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BN@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e96a0
// MS2-PIN: ??$ThunkMakeDefs2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CE@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x1423e9800
// MS2-PIN: ??$FormatD1@H@MsgFormat@Scaleform@@QEAAXAEBH@Z 0x1423e8500
// MS2-PIN: ??$FormatD1@PEBD@MsgFormat@Scaleform@@QEAAXAEBQEBD@Z 0x1423e85f0
// MS2-PIN: ??$AsString@J@Scaleform@@YA?AVString@0@AEBJ@Z 0x1423e8220
// MS2-PIN: ??$AsString@K@Scaleform@@YA?AVString@0@AEBK@Z 0x1423e8390
// MS2-PIN: ??_7Activation@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313ffe8
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3c20 ; unique
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3cd0 ; unique
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3e20 ; unique
// MS2-PIN: ??_G?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAPEAXI@Z 0x1423f1f90 ; vtslot
// MS2-PIN: ??_GActivation@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2040 ; vtslot
// MS2-PIN: ??_GArgumentError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f20a0 ; vtslot
// MS2-PIN: ??_GArray@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2130 ; vtslot
// MS2-PIN: ??_GArray@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f21c0 ; vtslot
// MS2-PIN: ??_GArray@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2220 ; vtslot
// MS2-PIN: ??_GArray@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2280 ; vtslot
// MS2-PIN: ??_GBoolean@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f23f0 ; vtslot
// MS2-PIN: ??_GBoolean@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2480 ; vtslot
// MS2-PIN: ??_GBoolean@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f24e0 ; vtslot
// MS2-PIN: ??_GCatch@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f25a0 ; vtslot
// MS2-PIN: ??_GCatch@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2630 ; vtslot
// MS2-PIN: ??_GCatch@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2690 ; vtslot
// MS2-PIN: ??_GCatch@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f26f0 ; vtslot
// MS2-PIN: ??_GClassCallConstruct@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2850 ; vtslot
// MS2-PIN: ??_GDate@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2a10 ; vtslot
// MS2-PIN: ??_GDate@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2aa0 ; vtslot
// MS2-PIN: ??_GDate@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2b00 ; vtslot
// MS2-PIN: ??_GDate@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2b60 ; vtslot
// MS2-PIN: ??_GDefinitionError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2bc0 ; vtslot
// MS2-PIN: ??_GError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2c80 ; vtslot
// MS2-PIN: ??_GError@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2d10 ; vtslot
// MS2-PIN: ??_GError@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2d70 ; vtslot
// MS2-PIN: ??_GError@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2dd0 ; vtslot
// MS2-PIN: ??_GEvalError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2e60 ; vtslot
// MS2-PIN: ??_GGASRefCountBase@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f31f0 ; vtslot
// MS2-PIN: ??_EInitStruct@String@Scaleform@@UEAAPEAXI@Z 0x1423f34e0 ; vtslot
// MS2-PIN: ??_GInterface@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3570 ; vtslot
// MS2-PIN: ??_GMath@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3600 ; vtslot
// MS2-PIN: ??_GMath@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3690 ; vtslot
// MS2-PIN: ??_GNamespace@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3750 ; vtslot
// MS2-PIN: ??_GNamespace@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f37b0 ; vtslot
// MS2-PIN: ??_GNamespace@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3840 ; vtslot
// MS2-PIN: ??_GNamespace@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f38a0 ; vtslot
// MS2-PIN: ??_GNamespaceInstanceFactory@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3930 ; vtslot
// MS2-PIN: ??_GNumber@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f39f0 ; vtslot
// MS2-PIN: ??_GNumber@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3a80 ; vtslot
// MS2-PIN: ??_GNumber@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3ae0 ; vtslot
// MS2-PIN: ??_GObject@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3b40 ; vtslot
// MS2-PIN: ??_GObject@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3bd0 ; vtslot
// MS2-PIN: ??_GObject@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3c30 ; vtslot
// MS2-PIN: ??_GObject@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3c90 ; vtslot
// MS2-PIN: ??_GQName@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3cf0 ; vtslot
// MS2-PIN: ??_GQName@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3d80 ; vtslot
// MS2-PIN: ??_GQName@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3de0 ; vtslot
// MS2-PIN: ??_GQName@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3e40 ; vtslot
// MS2-PIN: ??_GRangeError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3ee0 ; vtslot
// MS2-PIN: ??_GReferenceError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3f70 ; vtslot
// MS2-PIN: ??_GRegExp@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4000 ; vtslot
// MS2-PIN: ??_GRegExp@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4090 ; vtslot
// MS2-PIN: ??_GRegExp@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f40f0 ; vtslot
// MS2-PIN: ??_GRegExp@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4150 ; vtslot
// MS2-PIN: ??_GSecurityError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f41f0 ; vtslot
// MS2-PIN: ??_GString@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4280 ; vtslot
// MS2-PIN: ??_GString@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4310 ; vtslot
// MS2-PIN: ??_GString@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4370 ; vtslot
// MS2-PIN: ??_GSyntaxError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f43d0 ; vtslot
// MS2-PIN: ??_GTypeError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4580 ; vtslot
// MS2-PIN: ??_GURIError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4610 ; vtslot
// MS2-PIN: ??_GUninitializedError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f46a0 ; vtslot
// MS2-PIN: ??_GVerifyError@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f49f0 ; vtslot
// MS2-PIN: ??_GXML@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4a80 ; vtslot
// MS2-PIN: ??_GXML@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4b10 ; vtslot
// MS2-PIN: ??_GXML@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4b70 ; vtslot
// MS2-PIN: ??_GXMLList@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4f20 ; vtslot
// MS2-PIN: ??_GXMLList@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4fb0 ; vtslot
// MS2-PIN: ??_GXMLList@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5010 ; vtslot
// MS2-PIN: ??_GXMLList@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5070 ; vtslot
// MS2-PIN: ??_Gint_@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f52b0 ; vtslot
// MS2-PIN: ??_Gint_@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5340 ; vtslot
// MS2-PIN: ??_Gint_@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f53a0 ; vtslot
// MS2-PIN: ??_Guint@fl@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5400 ; vtslot
// MS2-PIN: ??_Guint@fl@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5490 ; vtslot
// MS2-PIN: ??_Guint@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f54f0 ; vtslot
// MS2-PIN: ?AS3Constructor@Array@fl@Instances@AS3@GFx@Scaleform@@UEAAXIPEBVValue@456@@Z 0x1423f5550 ; vtslot
// MS2-PIN: ?AS3Constructor@Date@fl@Instances@AS3@GFx@Scaleform@@UEAAXIPEBVValue@456@@Z 0x1423f5650 ; vtslot
// MS2-PIN: ??_7XML@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431429d0
// MS2-PIN: ??_7XMLAttr@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142dc8
// MS2-PIN: ??_7XMLElement@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142fa0
// MS2-PIN: ??_7XMLText@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143168
// MS2-PIN: ??_7XMLProcInstr@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143330
// MS2-PIN: ??_7XMLComment@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431434f8
// MS2-PIN: ??_7ClassCallConstruct@AS3@GFx@Scaleform@@6B@ 0x14313f3c8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BFA@@Scaleform@@6B@ 0x14313f3c8
// MS2-PIN: ?Call@ClassCallConstruct@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z 0x1424ee7d0 ; vtslot
// MS2-PIN: ??_GXML@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4bd0
// MS2-PIN: ??_GXMLAttr@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4c80
// MS2-PIN: ??_GXMLComment@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4d70
// MS2-PIN: ??_GXMLElement@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4e20
// MS2-PIN: ??_GXMLProcInstr@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5150
// MS2-PIN: ??_GXMLText@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5200
// MS2-PIN: ??_GXMLList@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f5070
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7?$RefCountBase@VNamespaceInstanceFactory@AS3@GFx@Scaleform@@$0BFA@@Scaleform@@6B@ 0x143140af0
// MS2-PIN: ??_7ArrayFunc@AS3@GFx@Scaleform@@6B@ 0x143141570
// MS2-PIN: ??_7ValuePtrCollector@AS3@GFx@Scaleform@@6B@ 0x143141580
// MS2-PIN: ??_7Value2StrCollector@AS3@GFx@Scaleform@@6B@ 0x143141590
// MS2-PIN: ??_7Value2NumberCollector@AS3@GFx@Scaleform@@6B@ 0x1431415a0
// MS2-PIN: ??_7CallBack@XMLElement@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142f90
// MS2-PIN: ??_7CallBack@XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436c0
// MS2-PIN: ??_7EmptyCallBack@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439b8
// MS2-PIN: ??_7AttrGetFirst@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439c8
// MS2-PIN: ??_7ChildGetFirst@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439d8
// MS2-PIN: ??_7ChildGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439e8
// MS2-PIN: ??_7AttrGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439f8
// MS2-PIN: ??_7ListGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143ae0
// MS2-PIN: ??RValue2NumberCollector@AS3@GFx@Scaleform@@UEAAXKAEBVValue@123@@Z 0x1423f1cb0 ; vtslot
// MS2-PIN: ??RValue2StrCollector@AS3@GFx@Scaleform@@UEAAXKAEBVValue@123@@Z 0x1423f1d70 ; vtslot
// MS2-PIN: ??RValuePtrCollector@AS3@GFx@Scaleform@@UEAAXKAEBVValue@123@@Z 0x1423f1ec0 ; vtslot
// MS2-PIN: ??_GArrayFunc@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2320 ; vtslot
// MS2-PIN: ??_GAttrGet@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2350 ; vtslot
// MS2-PIN: ??_GAttrGetFirst@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2380 ; vtslot
// MS2-PIN: ??_GCallBack@XMLElement@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2540 ; vtslot
// MS2-PIN: ??_GCallBack@XMLList@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2570 ; vtslot
// MS2-PIN: ??_GChildGet@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f27b0 ; vtslot
// MS2-PIN: ??_GChildGetFirst@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f27e0 ; vtslot
// MS2-PIN: ??_GEmptyCallBack@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2c50 ; vtslot
// MS2-PIN: ??_GListGet@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f35d0 ; vtslot
// MS2-PIN: ??_G?$RefCountBase@VNamespaceInstanceFactory@AS3@GFx@Scaleform@@$0BFA@@Scaleform@@UEAAPEAXI@Z 0x1423f1f30 ; vtslot
// MS2-PIN: ??_GValue2NumberCollector@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4960 ; vtslot
// MS2-PIN: ??_GValue2StrCollector@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4990 ; vtslot
// MS2-PIN: ??_GValuePtrCollector@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f49c0 ; vtslot
// MS2-PIN: ??_7Function@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313fea0
// MS2-PIN: ??_7Function@Classes@AS3@GFx@Scaleform@@6B@ 0x14313ff18
// MS2-PIN: ??_7Function@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313fe18
// MS2-PIN: ??_7Function@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f9b8
// MS2-PIN: ??_7FunctionBase@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f8f8
// MS2-PIN: ??_7Thunk@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313fbf8
// MS2-PIN: ??_7MethodInd@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313fc80
// MS2-PIN: ??_7VTableInd@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313fd08
// MS2-PIN: ??_7ThunkFunction@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313fd90
// MS2-PIN: ??_7ThunkFunction@Instances@AS3@GFx@Scaleform@@6B@ 0x14313fa78
// MS2-PIN: ??_7CheckTypeTF@Instances@AS3@GFx@Scaleform@@6B@ 0x14313fb38
// MS2-PIN: ??_GCheckTypeTF@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2750 ; vtslot
// MS2-PIN: ??_GFunction@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2ef0 ; vtslot
// MS2-PIN: ??_GFunction@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2f50 ; vtslot
// MS2-PIN: ??_GFunction@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2fb0 ; vtslot
// MS2-PIN: ??_GFunction@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3070 ; vtslot
// MS2-PIN: ??_GFunctionBase@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3150 ; vtslot
// MS2-PIN: ??_GMethodInd@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f36f0 ; vtslot
// MS2-PIN: ??_GThunk@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4460 ; vtslot
// MS2-PIN: ??_GThunkFunction@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f44c0 ; vtslot
// MS2-PIN: ??_GThunkFunction@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4520 ; vtslot
// MS2-PIN: ??_GVTableInd@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4900 ; vtslot
// MS2-PIN: ??_7ClassClass@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140420
// MS2-PIN: ??_7ClassClass@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431402c8
// MS2-PIN: ??_7ClassClass@Classes@AS3@GFx@Scaleform@@6B@ 0x143140350
// MS2-PIN: ??_GClassClass@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f28b0 ; vtslot
// MS2-PIN: ??_GClassClass@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f29b0 ; vtslot
// MS2-PIN: ??_GClassClass@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f2940 ; vtslot
// MS2-PIN: ??_7GlobalObject@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143b20
// MS2-PIN: ??_7GlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143bf0
// MS2-PIN: ??_7GlobalObject@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143143d98
// MS2-PIN: ??_7GlobalObjectScript@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143143e48
// MS2-PIN: ??_GGlobalObject@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f32b0 ; vtslot
// MS2-PIN: ??_GGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3470 ; vtslot
// MS2-PIN: ??_GGlobalObject@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3250 ; vtslot
// MS2-PIN: ??_GGlobalObjectScript@fl@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f33e0 ; vtslot
// MS2-PIN: ??_7GlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143cc8
// MS2-PIN: ??_GGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f3320 ; vtslot
// MS2-PIN: ??_7UserDefined@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143143fa8
// MS2-PIN: ??_GUserDefined@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4730 ; vtslot
// MS2-PIN: ??_7UserDefined@Classes@AS3@GFx@Scaleform@@6B@ 0x143144040
// MS2-PIN: ??_GUserDefined@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4800 ; vtslot
// MS2-PIN: ??_7UserDefined@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143143ef8
// MS2-PIN: ??_GUserDefined@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423f4870 ; vtslot
// MS2-PIN: ??1Multiname@AS3@GFx@Scaleform@@QEAA@XZ 0x1423f1060
// MS2-PIN: ??$Add@PEAVNamespace@Instances@AS3@GFx@Scaleform@@@?$HashSetBase@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@U67345@U?$AllocatorLH@PEAVNamespace@Instances@AS3@GFx@Scaleform@@$01@5@V?$HashsetEntry@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@@5@@Scaleform@@QEAAXPEAXAEBQEAVNamespace@Instances@AS3@GFx@1@@Z 0x1423e80a0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@VCompareOn@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@VCompareOn@AS3@GFx@1@@Z 0x1423e9960
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@VCompareValuePtr@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@VCompareValuePtr@AS3@GFx@1@@Z 0x1423e9990
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@VCompareAsString@Impl@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@1@VCompareAsString@Impl@AS3@GFx@1@@Z 0x1423e99d0
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@VCompareAsNumber@Impl@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@1@_K1VCompareAsNumber@Impl@AS3@GFx@1@@Z 0x1423ea060
// MS2-PIN: ??$add@UNodeRef@?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@@?$HashSetBase@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorDH@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@1@_K@Z 0x1423eb220
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1423f07a0
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@VCompareOn@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1VCompareOn@AS3@GFx@1@@Z 0x1423e9a00
// MS2-PIN: ??1AttrGetFirst@fl@Instances@AS3@GFx@Scaleform@@UEAA@XZ 0x1423f0c80
// MS2-PIN: ??4?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVXML@fl@Instances@123@@Z 0x1423f1970
// MS2-PIN: ??1ChildGetFirst@fl@Instances@AS3@GFx@Scaleform@@UEAA@XZ 0x1423f0d10
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@VCompareValuePtr@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1VCompareValuePtr@AS3@GFx@1@@Z 0x1423e9d30
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@VCompareAsString@Impl@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@I@Impl@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@1@_K1VCompareAsString@Impl@AS3@GFx@1@@Z 0x1423ea400
// MS2-PIN: ??0Function@Instances@AS3@GFx@Scaleform@@QEAA@AEAVTraits@InstanceTraits@234@AEBV?$ArrayDH@VValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@4@AEBVValue@234@AEBVASString@34@@Z 0x1423ed090
// MS2-PIN: ??0GlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@QEAA@AEAVVM@345@AEAVGlobalObject@1InstanceTraits@345@@Z 0x1423ed260
// MS2-PIN: ??0UserDefined@InstanceTraits@AS3@GFx@Scaleform@@QEAA@AEAVVMAbcFile@234@PEBVTraits@234@AEBVClassInfo@Abc@234@@Z 0x1423ef790
// MS2-PIN: ??4?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAAEBV01@AEBV01@@Z 0x1423f1760
// MS2-PIN: ?Func@?$ThunkFunc2@VThunkFunction@Instances@AS3@GFx@Scaleform@@$0A@VValue@345@IPEBV6345@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0e50
// MS2-PIN: ?Func@?$ThunkFunc0@VQName@fl@Instances@AS3@GFx@Scaleform@@$00VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1b10
// MS2-PIN: ?Func@?$ThunkFunc2@VString@fl@Classes@AS3@GFx@Scaleform@@$0A@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e1e40
// MS2-PIN: ?Func@?$ThunkFunc2@VError@fl@Classes@AS3@GFx@Scaleform@@$00VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e21a0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$01VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e3c00
