// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_20
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142542820-0x1425584f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#undef GetObject

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

namespace Scaleform { namespace GFx { namespace AS3 { namespace Abc {

// @0x1425452c0
double ConstPool::GetDouble(UPInt ind) const
{
    if (ind != 0)
    {
        const UInt8* p = ConstDouble + (ind - 1) * sizeof(double);
        return ReadDouble(p);
    }
    return 0.0;
}

// @0x1425452f0
UPInt NamespaceSetInfo::GetSize() const
{
    const UInt8* p = Data;
    return static_cast<UInt32>(ReadU30(p));
}

template <typename T>
UInt8 ReadU8(const T*& p)
{
    return *p++;
}

template <typename T>
UInt8 ReadU8(const T* data, UPInt& pos)
{
    return data[pos++];
}

// noinline: the exe reads ABC data through out-of-line calls (GetSize, GetDouble and the parser).
template <typename T>
SF_NOINLINE int ReadU30(const T*& p)
{
    UInt8 b = ReadU8(p);
    int result = b & 0x7f;
    for (UInt32 shift = 7; (b & 0x80) && shift < 32; shift += 7)
    {
        b = ReadU8(p);
        result |= (b & 0x7f) << shift;
    }
    return result;
}

template <typename T>
SF_NOINLINE int ReadU30(const T* data, UPInt& pos)
{
    UInt8 b = ReadU8(data, pos);
    int result = b & 0x7f;
    for (UInt32 shift = 7; (b & 0x80) && shift < 32; shift += 7)
    {
        b = ReadU8(data, pos);
        result |= (b & 0x7f) << shift;
    }
    return result;
}

template <typename T>
SF_NOINLINE int ReadS24(const T* data, UPInt& pos)
{
    UInt32 b0 = data[pos];
    UInt32 b1 = data[pos + 1];
    UInt32 b2 = data[pos + 2];
    pos += 3;
    int result = ((b2 << 8 | b1) << 8) | b0;
    if (b2 & 0x80)
        result = ~(result ^ 0xffffff);
    return result;
}

// Assembled byte by byte: the ABC data is little endian and need not be aligned.
template <typename T>
SF_NOINLINE double ReadDouble(const T*& p)
{
    union { UInt32 u[2]; double d; } v;
    v.u[0] = ((((UInt32)p[3] << 8 | p[2]) << 8 | p[1]) << 8) | p[0];
    v.u[1] = ((((UInt32)p[7] << 8 | p[6]) << 8 | p[5]) << 8) | p[4];
    p += 8;
    return v.d;
}

template <typename T>
String ReadString(const T*& p, UPInt size)
{
    String result(reinterpret_cast<const char*>(p), size);
    p += size;
    return result;
}

template <typename T>
String ReadString(const T* data, UPInt& pos, UPInt size)
{
    String result(reinterpret_cast<const char*>(data + pos), size);
    pos += size;
    return result;
}

// The instances for byte data (pinned below).
template int    ReadU30<UInt8>(const UInt8*& p);
template int    ReadU30<UInt8>(const UInt8* data, UPInt& pos);
template int    ReadS24<UInt8>(const UInt8* data, UPInt& pos);
template double ReadDouble<UInt8>(const UInt8*& p);
template String ReadString<UInt8>(const UInt8*& p, UPInt size);
template String ReadString<UInt8>(const UInt8* data, UPInt& pos, UPInt size);

template <typename T>
SF_NOINLINE int Read16(const T*& p)
{
    const int hi = p[1];
    const int lo = p[0];
    p += 2;
    return hi << 8 | lo;
}

// The bytes of a pool string, without copying them.
template <typename T>
SF_NOINLINE StringDataPtr ReadStringPtr(const T*& p, UPInt size)
{
    StringDataPtr result(reinterpret_cast<const char*>(p), size);
    p += size;
    return result;
}

template int           Read16<UInt8>(const UInt8*& p);
template StringDataPtr ReadStringPtr<UInt8>(const UInt8*& p, UPInt size);

// @0x142545310
StringDataPtr StringView::ToStringDataPtr() const
{
    const UInt8* p = Data;
    const int size = ReadU30(p);
    return ReadStringPtr(p, size);
}

// @0x142545670
MethodBodyInfo::ExceptionInfo::ExceptionInfo()
    : from(0), to(0), target(0), exc_type_ind(0), var_name_ind(0)
{
}

// @0x142545650
MethodBodyInfo::ExceptionInfo::ExceptionInfo(SInd from, SInd to, SInd target, SInd exc_type_ind, SInd var_name_ind)
    : from(from), to(to), target(target), exc_type_ind(exc_type_ind), var_name_ind(var_name_ind)
{
}

// @0x142545680
MethodBodyInfo::MethodBodyInfo()
    : method_info_ind(-1), max_stack(-1), local_reg_count(-1), init_scope_depth(-1), max_scope_depth(-1)
{
}

// @0x142545a80
MethodBodyInfo::~MethodBodyInfo()
{
}

// @0x142545ac0
MethodBodyTable::~MethodBodyTable()
{
    const UPInt size = Info.GetSize();
    for (UPInt i = 0; i < size; ++i)
        delete Info[i];
}

// @0x1425456e0
File::~File()
{
}

// @0x142545bc0
void ConstPool::Clear()
{
    ConstInt.Clear();
    ConstUInt.Clear();
    ConstStr.Clear();
    ConstNamespace.Clear();
    const_ns_set.Clear();
    const_multiname.Clear();
}

// @0x142545dd0
void File::Clear()
{
    MinorVersion = 0;
    MajorVersion = 0;
    Const_Pool.Clear();
    Methods.Info.Clear();
    Metadata.Info.Clear();
    Traits.TraitInfos.Clear();
    AS3_Classes.Info.Clear();
    Scripts.Info.Clear();
    MethodBodies.Info.Clear();
}

// @0x142545ff0
bool MethodBodyInfo::Exception::FindExceptionInfo(UPInt offset, UPInt& from) const
{
    const UPInt size = info.GetSize();
    for (; from < size; ++from)
    {
        const ExceptionInfo& e = info[from];
        if (offset >= static_cast<UInt32>(e.from) && offset <= static_cast<UInt32>(e.to))
            return true;
    }
    return false;
}

// @0x142546050
const Multiname& TraitInfo::GetName(const ConstPool& cp) const
{
    if (name_ind == 0)
        return cp.AnyType;
    return cp.GetMultiname(name_ind);
}

// @0x142546080
bool IsValidValueKind(UInt8 vk)
{
    // Undefined, Utf8, Int, UInt, PrivateNs, Double, Namespace, False, True, Null and the four namespace kinds.
    switch (vk)
    {
    case 0x00: case 0x01: case 0x03: case 0x04: case 0x05: case 0x06: case 0x08: case 0x0a: case 0x0b: case 0x0c:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        return true;
    default:
        break;
    }
    return false;
}

}}}} // namespace Scaleform::GFx::AS3::Abc

// ---------------------------------------------------------------- Vector.<T> natives

// VectorBase<T>::Concat/Filter/Map member templates (this unit, below the natives)
void FUN_142547960(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142547c40(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142547f30(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_142548280(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142548580(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, Scaleform::GFx::AS3::Value& result,
    unsigned argc, const Scaleform::GFx::AS3::Value* argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);
void FUN_142548bd0(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_142548f60(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_142549300(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_1425496a0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_142549a60(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);
void FUN_14254c050(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& owner);
void FUN_14254c4e0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& owner);
void FUN_14254c980(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& owner);
void FUN_14254ce20(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& owner);
void FUN_14254d380(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>& result,
    const Scaleform::GFx::AS3::Value& callback, const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& owner);

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// The element type of a Vector.<T> of objects: ClassTraits::fl_vec::Vector_object keeps it at +0xc8.
static const ClassTraits::Traits& GetEnclosedClassTraits(const Vector_object& v)
{
    const ClassTraits::Traits& ctr = v.GetTraits().GetConstructor().GetClassTraits();
    return **reinterpret_cast<ClassTraits::Traits* const*>(reinterpret_cast<const char*>(&ctr) + 0xc8);
}

// ---- AS3Constructor: (length = 0, fixed = false)

// @0x142557110
void Vector_String::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x142557180
void Vector_double::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// MS2-FUNCTIONAL: the exe inlines VectorBase<SInt32>::Resize here; ours calls it
// @0x1425571f0
void Vector_int::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// @0x1425572c0
void Vector_object::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// MS2-FUNCTIONAL: the exe inlines VectorBase<UInt32>::Resize here; ours calls it
// @0x142557330
void Vector_uint::AS3Constructor(unsigned argc, const Value* argv)
{
    if (argc > 0)
    {
        UInt32 length;
        if (!argv[0].Convert2UInt32(length))
            return;
        if (!V.Resize(length))
            return;
    }
    if (argc > 1)
        V.Fixed = argv[1].Convert2Boolean();
}

// ---- concat

// @0x142557400
void Vector_String::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547960(V, result, argc, argv, *this);
}

// @0x142557420
void Vector_double::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547c40(V, result, argc, argv, *this);
}

// @0x142557440
void Vector_int::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142547f30(V, result, argc, argv, *this);
}

// @0x142557460
void Vector_object::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142548280(V, result, argc, argv, *this);
}

// @0x142557480
void Vector_uint::AS3concat(Value& result, unsigned argc, const Value* argv)
{
    FUN_142548580(V, result, argc, argv, *this);
}

// ---- every

// @0x1425574a0
void Vector_String::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x1425574d0
void Vector_double::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557500
void Vector_int::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557530
void Vector_object::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// @0x142557560
void Vector_uint::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = V.Every(callback, thisObject, this);
}

// ---- filter

// @0x142557590
void Vector_String::AS3filter(SPtr<Vector_String>& result, const Value& callback, const Value& thisObject)
{
    FUN_142548bd0(V, result, callback, thisObject, *this);
}

// @0x1425575b0
void Vector_double::AS3filter(SPtr<Vector_double>& result, const Value& callback, const Value& thisObject)
{
    FUN_142548f60(V, result, callback, thisObject, *this);
}

// @0x1425575d0
void Vector_int::AS3filter(SPtr<Vector_int>& result, const Value& callback, const Value& thisObject)
{
    FUN_142549300(V, result, callback, thisObject, *this);
}

// @0x1425575f0
void Vector_object::AS3filter(SPtr<Vector_object>& result, const Value& callback, const Value& thisObject)
{
    FUN_1425496a0(V, result, callback, thisObject, *this);
}

// @0x142557610
void Vector_uint::AS3filter(SPtr<Vector_uint>& result, const Value& callback, const Value& thisObject)
{
    FUN_142549a60(V, result, callback, thisObject, *this);
}

// ---- forEach

// @0x142557630
void Vector_String::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557650
void Vector_double::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557670
void Vector_int::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x142557690
void Vector_object::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// @0x1425576b0
void Vector_uint::AS3forEach(const Value& result, const Value& callback, const Value& thisObject)
{
    V.ForEach(callback, thisObject, this);
}

// ---- indexOf / lastIndexOf (a negative fromIndex counts from the end)

// @0x1425576d0
void Vector_String::AS3indexOf(SInt32& result, const ASString& searchElement, SInt32 fromIndex)
{
    const Ptr<ASStringNode> node = searchElement.GetNode();
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (UPInt i = fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (V.V[i] == node)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x1425577d0
void Vector_object::AS3indexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
{
    for (UPInt i = (UPInt)(SPInt)fromIndex; i < (UInt32)V.V.GetSize(); ++i)
    {
        if (StrictEqual(V.V[i], searchElement))
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557a30
void Vector_String::AS3lastIndexOf(SInt32& result, const ASString& searchElement, SInt32 fromIndex)
{
    const Ptr<ASStringNode> node = searchElement.GetNode();
    if (fromIndex < 0)
        fromIndex = (SInt32)((UInt32)V.V.GetSize() + fromIndex);
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (V.V[i] == node)
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// @0x142557b50
void Vector_object::AS3lastIndexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
{
    for (SPInt i = Alg::Min<SPInt>(fromIndex, (SPInt)(UInt32)V.V.GetSize() - 1); i >= 0; --i)
    {
        if (StrictEqual(V.V[i], searchElement))
        {
            result = (SInt32)i;
            return;
        }
    }
    result = -1;
}

// ---- join

// @0x1425578a0
void Vector_String::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x1425578f0
void Vector_double::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x142557940
void Vector_int::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x142557990
void Vector_object::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// @0x1425579e0
void Vector_uint::AS3join(ASString& result, const ASString& separator)
{
    result = V.Join(separator);
}

// ---- map

// @0x142557c30
void Vector_String::AS3map(SPtr<Vector_String>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c050(V, result, callback, thisObject, *this);
}

// @0x142557c50
void Vector_double::AS3map(SPtr<Vector_double>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c4e0(V, result, callback, thisObject, *this);
}

// @0x142557c70
void Vector_int::AS3map(SPtr<Vector_int>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254c980(V, result, callback, thisObject, *this);
}

// @0x142557c90
void Vector_object::AS3map(SPtr<Vector_object>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254ce20(V, result, callback, thisObject, *this);
}

// @0x142557cb0
void Vector_uint::AS3map(SPtr<Vector_uint>& result, const Value& callback, const Value& thisObject)
{
    FUN_14254d380(V, result, callback, thisObject, *this);
}

// ---- pop: RangeError on a fixed vector; nothing on an empty one

// MS2-FUNCTIONAL: the exe calls ArrayDataBase::ResizeNoConstruct out of line for the pop; ours inlines it
// @0x142557cd0
void Vector_String::AS3pop(ASString& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
    {
        Ptr<ASStringNode> node = V.V.Pop();
        result.AssignNode(node ? node.GetPtr() : result.GetManager()->GetNullStringNode());
    }
}

// MS2-FUNCTIONAL: the exe calls ArrayDataDH<double>::Resize out of line for the pop; ours inlines it
// @0x142557e00
void Vector_double::AS3pop(Value::Number& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// MS2-FUNCTIONAL: the exe calls ArrayDataDH<SInt32>::Resize out of line for the pop; ours inlines it
// @0x142557ea0
void Vector_int::AS3pop(SInt32& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// MS2-FUNCTIONAL: the exe calls ArrayDataBase::ResizeNoConstruct out of line for the pop; ours inlines it
// @0x142557f30
void Vector_object::AS3pop(Value& result)
{
    if (V.CheckFixed() && V.V.GetSize() != 0)
        result.Assign(V.V.Pop());
}

// MS2-FUNCTIONAL: the exe calls ArrayDataDH<UInt32>::Resize out of line for the pop; ours inlines it
// @0x142558090
void Vector_uint::AS3pop(UInt32& result)
{
    if (!V.CheckFixed())
        return;
    if ((UInt32)V.V.GetSize() > 0)
        result = V.V.Pop();
}

// ---- push: argv coerced to the element type; the new length is returned

// @0x142558120
void Vector_String::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsString());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x1425581a0
void Vector_double::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsNumber());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558220
void Vector_int::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsSInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line (0x142508490); ours inlines it
// @0x1425582a0
void Vector_object::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetEnclosedClassTraits(*this));
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558340
void Vector_uint::AS3push(Value& result, unsigned argc, const Value* argv)
{
    V.PushBack(argc, argv, GetVM().GetClassTraitsUInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// ---- reverse

// MS2-FUNCTIONAL: Ptr<ASStringNode> swap temporaries scheduled differently
// @0x1425583c0
void Vector_String::AS3reverse(SPtr<Vector_String>& result)
{
    for (SPInt i = 0, j = (SPInt)V.V.GetSize() - 1; i < j; ++i, --j)
    {
        const Ptr<ASStringNode> tmp = V.V[i];
        V.V[i] = V.V[j];
        V.V[j] = tmp;
    }
    result = this;
}

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

// VectorBase<T>::Concat/Filter/Map<I>: one body per element type, written once below and forced inline into each.
// VM::GetValueTraits / VM::GetClassTraits(const Value&) / ClassTraits::Traits::IsParentTypeOf
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
Scaleform::GFx::AS3::ClassTraits::Traits& FUN_142507f60(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other);

namespace Scaleform {
// A sort key and the index of the element it came from.
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};
namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec { struct CompareAsStringInd; } } } }
}

// Vector.sort helpers the exe keeps out of line (sfr_as3_21): CompareAsStringInd::Compare, Impl::CompareFunct
// (calls the AS3 compare function, its result as an int) and ArrayDH<Pair<ASString,UInt32> >::PushBack.
namespace Scaleform { namespace GFx { namespace AS3 { namespace Impl {
int CompareFunct(VM& vm, const Value& funct, const Value& a, const Value& b);
}}}}
void FUN_1425615f0(Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString, Scaleform::UInt32> >& pairs, const Scaleform::Pair<Scaleform::GFx::ASString, Scaleform::UInt32>& v);

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// the element as a callback argument
static SF_INLINE Value ElementValue(const Ptr<ASStringNode>& e)     { return Value(e.GetPtr()); }
static SF_INLINE Value ElementValue(Value::Number e)                { return Value(e); }
static SF_INLINE Value ElementValue(SInt32 e)                       { return Value(e); }
static SF_INLINE Value ElementValue(const Value& e)                 { return e; }
static SF_INLINE Value ElementValue(UInt32 e)                       { return Value(e); }

// an element pushed into the result instance
static SF_INLINE void PushElement(Vector_String& r, const Ptr<ASStringNode>& e)    { r.PushBack(e.GetPtr()); }
static SF_INLINE void PushElement(Vector_double& r, Value::Number e)                { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_int& r, SInt32 e)                         { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_object& r, const Value& e)                { r.PushBack(e); }
static SF_INLINE void PushElement(Vector_uint& r, UInt32 e)                        { r.PushBack(e); }

// a coerced Value pushed into the result instance
static SF_INLINE void PushCoerced(Vector_String& r, const Value& v)    { r.PushBack(v.AsStringNode()); }
static SF_INLINE void PushCoerced(Vector_double& r, const Value& v)    { r.PushBack(v.AsNumber()); }
static SF_INLINE void PushCoerced(Vector_int& r, const Value& v)       { r.PushBack(v.AsInt()); }
static SF_INLINE void PushCoerced(Vector_object& r, const Value& v)    { r.PushBack(v); }
static SF_INLINE void PushCoerced(Vector_uint& r, const Value& v)      { r.PushBack(v.AsUInt()); }

// a concat() argument of the element type, appended in place
static SF_INLINE void ConcatPush(Vector_String& r, const Value& v)
{
    const Ptr<ASStringNode> s(v.GetStringNode());
    if (r.V.CheckFixed())
        r.V.V.PushBack(s);
}
static SF_INLINE void ConcatPush(Vector_double& r, const Value& v)  { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsNumber()); }
static SF_INLINE void ConcatPush(Vector_int& r, const Value& v)     { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsInt()); }
static SF_INLINE void ConcatPush(Vector_object& r, const Value& v)  { if (r.V.CheckFixed()) r.V.V.PushBack(v); }
static SF_INLINE void ConcatPush(Vector_uint& r, const Value& v)    { if (r.V.CheckFixed()) r.V.V.PushBack(v.AsUInt()); }

static SF_INLINE void Append(Vector_String& r, const Vector_String& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_double& r, const Vector_double& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_int& r, const Vector_int& o)        { r.Append(o); }
static SF_INLINE void Append(Vector_object& r, const Vector_object& o)  { r.Append(o); }
static SF_INLINE void Append(Vector_uint& r, const Vector_uint& o)      { r.Append(o); }

// the ClassTraits map() coerces the callback results to
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_String& o)  { return o.GetVM().GetClassTraitsString(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_double& o)  { return o.GetVM().GetClassTraitsNumber(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_int& o)     { return o.GetVM().GetClassTraitsSInt(); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_object& o)  { return GetEnclosedClassTraits(o); }
static SF_INLINE const ClassTraits::Traits& MapClassTraits(const Vector_uint& o)    { return o.GetVM().GetClassTraitsUInt(); }

template <class I, class TR, typename T>
static __forceinline void VectorConcat(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    VM& vm = self.VMRef;
    const ClassTraits::Traits& currClassTR = owner.GetTraits().GetConstructor().GetClassTraits();
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    Append(r, owner);

    for (unsigned i = 0; i < argc; ++i)
    {
        const Value& value = argv[i];
        const Traits& argTraits = FUN_14250ffc0(vm, value);
        const ClassTraits::Traits& argClassTR = FUN_142507f60(vm, value);

        if (argTraits.IsArrayLike())
        {
            if (FUN_1425149a0(vm.GetClassTraitsArray(), argClassTR))
            {
                self.VMRef.ThrowError(VM::Error(VM::eNotImplementedError, self.VMRef, "Vector::concat() for argument of type Array"));
                return;
            }
            if (&currClassTR != &argClassTR)
            {
                self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                    currClassTR.GetName().ToCStr(), argClassTR.GetName().ToCStr()));
                return;
            }
            Append(r, static_cast<I&>(*value.GetObject()));
        }
        else if (FUN_1425149a0(currClassTR, FUN_142507f60(self.VMRef, value)))
            ConcatPush(r, value);
        else
        {
            self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                currClassTR.GetName().ToCStr(), argClassTR.GetName().ToCStr()));
            return;
        }
    }
}

template <class I, class TR, typename T>
static __forceinline void VectorFilter(VectorBase<T>& self, SPtr<I>& result, const Value& callback, const Value& thisObject, I& owner)
{
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    if (callback.IsNullOrUndefined() || !self.CheckCallable(callback))
        return;

    Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
    for (UPInt i = 0; i < (UInt32)self.V.GetSize(); ++i)
    {
        const Value argv[3] = {ElementValue(self.V[i]), Value((UInt32)i), Value(&owner)};
        Value res;
        self.VMRef.ExecuteInternalUnsafe(callback, _this, res, 3, argv, false);
        if (self.VMRef.IsException())
            break;
        if (!res.IsBool() || !res.AsBool())
            continue;
        PushElement(r, self.V[i]);
    }
}

template <class I, class TR, typename T>
static __forceinline void VectorMap(VectorBase<T>& self, SPtr<I>& result, const Value& callback, const Value& thisObject, I& owner)
{
    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    result.Pick(pr);
    if (callback.IsNullOrUndefined() || !self.CheckCallable(callback))
        return;

    Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
    const ClassTraits::Traits& tr = MapClassTraits(owner);
    for (UPInt i = 0; i < (UInt32)self.V.GetSize(); ++i)
    {
        const Value argv[3] = {ElementValue(self.V[i]), Value((UInt32)i), Value(&owner)};
        Value res;
        self.VMRef.ExecuteInternalUnsafe(callback, _this, res, 3, argv, false);
        if (self.VMRef.IsException())
            break;
        Value coerced;
        if (!self.CheckCoerce(tr, res, coerced))
            return;
        PushCoerced(r, coerced);
    }
}

// ---- sort: the elements are collected (as numbers, strings or element pointers), sorted, then copied back

typedef Pair<Value::Number, UInt32> NumberPair;
typedef Pair<ASString, UInt32>      StringPair;

// Called once per element; vftables of the int/uint/double/String/Value bases
// 0x143182e08/0x143182de8/0x143182dc8/0x143182da8/0x143182d88.
template <typename T>
struct SortFunc
{
    virtual ~SortFunc() {}
    virtual void operator()(UInt32 ind, const T& v) = 0;
};

template <typename T>
static SF_INLINE void ForEachElement(const VectorBase<T>& self, SortFunc<T>& f)
{
    const UPInt size = self.V.GetSize();
    for (UInt32 i = 0; i < size; ++i)
        f(i, self.V[i]);
}

static SF_INLINE CheckResult ElementNumber(SInt32 v, Value::Number& n)                    { n = v; return true; }
static SF_INLINE CheckResult ElementNumber(UInt32 v, Value::Number& n)                    { n = v; return true; }
static SF_INLINE CheckResult ElementNumber(Value::Number v, Value::Number& n)             { n = v; return true; }

// (number, index) pairs; elements that do not convert are left out
template <typename T>
struct Value2NumberCollector : public SortFunc<T>
{
    Value2NumberCollector(ArrayDH<NumberPair>& pairs) : Pairs(pairs) {}
    virtual void operator()(UInt32 ind, const T& v)
    {
        Value::Number n;
        if (ElementNumber(v, n))
            Pairs.PushBack(NumberPair(n, ind));
    }

    ArrayDH<NumberPair>& Pairs;
};

template <>
void Value2NumberCollector<Value>::operator()(UInt32 ind, const Value& v)
{
    Value::Number n;
    if (v.Convert2Number(n))
        Pairs.PushBack(NumberPair(n, ind));
}

template <>
void Value2NumberCollector<Ptr<ASStringNode> >::operator()(UInt32 ind, const Ptr<ASStringNode>& v)
{
    Value::Number n;
    Value tmp(v.GetPtr());
    if (tmp.Convert2Number(n))
        Pairs.PushBack(NumberPair(n, ind));
}

// (string, index) pairs; elements that do not convert are left out
template <typename T>
struct Value2StrCollector : public SortFunc<T>
{
    Value2StrCollector(VM& vm, ArrayDH<StringPair>& pairs) : VMRef(vm), Pairs(pairs) {}
    virtual void operator()(UInt32 ind, const T& v)
    {
        ASString str = VMRef.GetStringManager().CreateEmptyString();
        if (Value(v).Convert2String(str))
        {
            const StringPair p(str, ind);
            FUN_1425615f0(Pairs, p);
        }
    }

    VM&                  VMRef;
    ArrayDH<StringPair>& Pairs;
};

template <>
void Value2StrCollector<Value>::operator()(UInt32 ind, const Value& v)
{
    ASString str = VMRef.GetStringManager().CreateEmptyString();
    if (v.Convert2String(str))
    {
        const StringPair p(str, ind);
        FUN_1425615f0(Pairs, p);
    }
}

template <>
void Value2StrCollector<Ptr<ASStringNode> >::operator()(UInt32 ind, const Ptr<ASStringNode>& v)
{
    FUN_1425615f0(Pairs, StringPair(ASString(v.GetPtr()), ind));
}

// pointers to the elements, for a compare function
template <typename T>
struct ValuePtrCollector : public SortFunc<T>
{
    ValuePtrCollector(ArrayDH<const T*>& ptrs) : Ptrs(ptrs) {}
    virtual void operator()(UInt32, const T& v) { Ptrs.PushBack(&v); }

    ArrayDH<const T*>& Ptrs;
};

// Array.CASEINSENSITIVE / DESCENDING / Locale-aware string order of the pairs.
struct CompareAsStringInd
{
    CompareAsStringInd(bool desc, bool ci, bool loc) : Desc(desc), CaseInsensitive(ci), UseLocale(loc) {}
    bool operator()(const StringPair& a, const StringPair& b) const { return Compare(a.First, b.First) < 0; }
    SInt32 Compare(const ASString& a, const ASString& b) const;

    bool Desc;
    bool CaseInsensitive;
    bool UseLocale;
};

struct CompareAsNumberInd
{
    CompareAsNumberInd(bool desc) : Desc(desc) {}
    bool operator()(const NumberPair& a, const NumberPair& b) const { return Desc ? a.First > b.First : b.First > a.First; }

    bool Desc;
};

static SF_INLINE SInt32 CompareElements(VM& vm, const Value& f, const Value& a, const Value& b)  { return Impl::CompareFunct(vm, f, a, b); }
template <typename T>
static SF_INLINE SInt32 CompareElements(VM& vm, const Value& f, const T& a, const T& b)          { return Impl::CompareFunct(vm, f, ElementValue(a), ElementValue(b)); }

template <typename T>
struct CompareValuePtr
{
    CompareValuePtr(VM& vm, const Value& f) : VMRef(vm), Func(f) {}
    bool operator()(const T* a, const T* b) const { return Impl::CompareFunct(VMRef, Func, ElementValue(*a), ElementValue(*b)) < 0; }

    VM&          VMRef;
    const Value& Func;
};

template <>
bool CompareValuePtr<Ptr<ASStringNode> >::operator()(const Ptr<ASStringNode>* a, const Ptr<ASStringNode>* b) const
{
    VM& vm = VMRef;
    return Impl::CompareFunct(vm, Func, Value(a->GetPtr()), Value(b->GetPtr())) < 0;
}

template <>
bool CompareValuePtr<Value>::operator()(const Value* a, const Value* b) const { return Impl::CompareFunct(VMRef, Func, *a, *b) < 0; }

template <class I, class TR, typename T>
static __forceinline void VectorSort(VectorBase<T>& self, Value& result, unsigned argc, const Value* argv, I& owner)
{
    enum { CaseInsensitive = 1, Descending = 2, UniqueSort = 4, ReturnIndexedArray = 8, Numeric = 16 };

    Value compareFunction;
    SInt32 flags = 0;
    if (argc > 0)
    {
        if (argv[0].IsCallable())
            compareFunction.Assign(argv[0]);
        else if (!argv[0].Convert2Int32(flags))
        {
            self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
                FUN_14250ffc0(self.VMRef, argv[0]).GetName().ToCStr(), MapClassTraits(owner).GetName().ToCStr()));
            return;
        }
    }
    if (argc > 1 && !argv[1].Convert2Int32(flags))
    {
        self.VMRef.ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, self.VMRef,
            FUN_14250ffc0(self.VMRef, argv[1]).GetName().ToCStr(), MapClassTraits(owner).GetName().ToCStr()));
        return;
    }

    VM& vm = self.VMRef;
    MemoryHeap* heap = vm.GetMemoryHeap();
    ArrayDH<T> newSA(heap);
    if (compareFunction.IsNullOrUndefined())
    {
        if ((flags & Numeric) == 0)
        {
            ArrayDH<StringPair> pairs(heap);
            Value2StrCollector<T> vc(vm, pairs);
            ForEachElement(self, vc);

            CompareAsStringInd cmp((flags & Descending) != 0, (flags & CaseInsensitive) != 0, ((flags >> 10) & 1) != 0);
            Alg::QuickSortSafe(pairs, cmp);
            if (flags & UniqueSort)
            {
                for (UInt32 i = 1; i < pairs.GetSize(); ++i)
                {
                    if (cmp.Compare(pairs[i - 1].First, pairs[i].First) == 0)
                    {
                        result.SetNull();
                        return;
                    }
                }
            }
            for (UPInt i = 0; i < pairs.GetSize(); ++i)
                newSA.PushBack(self.V[pairs[i].Second]);
        }
        else
        {
            ArrayDH<NumberPair> pairs(heap);
            Value2NumberCollector<T> vc(pairs);
            ForEachElement(self, vc);

            Alg::QuickSortSlicedSafe(pairs, 0, pairs.GetSize(), CompareAsNumberInd((flags & Descending) != 0));
            if (flags & UniqueSort)
            {
                for (UInt32 i = 1; i < pairs.GetSize(); ++i)
                {
                    if (pairs[i - 1].First == pairs[i].First)
                    {
                        result.SetSInt32(0);
                        return;
                    }
                }
            }
            for (UPInt i = 0; i < pairs.GetSize(); ++i)
                newSA.PushBack(self.V[pairs[i].Second]);
        }
    }
    else
    {
        ArrayDH<const T*> ptrs(heap);
        ValuePtrCollector<T> vc(ptrs);
        ForEachElement(self, vc);

        Alg::QuickSortSafe(ptrs, CompareValuePtr<T>(vm, compareFunction));
        if (flags & UniqueSort)
        {
            for (UInt32 i = 1; i < ptrs.GetSize(); ++i)
            {
                if (CompareElements(vm, compareFunction, *ptrs[i - 1], *ptrs[i]) == 0)
                {
                    result.SetNull();
                    return;
                }
            }
        }
        for (UPInt i = 0; i < ptrs.GetSize(); ++i)
            newSA.PushBack(*ptrs[i]);
    }

    if ((flags & ReturnIndexedArray) == 0)
    {
        self.V = newSA;
        result.Assign(&owner);
        return;
    }

    Pickable<I> pr = TR::MakeInstance(static_cast<TR&>(owner.GetTraits()));
    I& r = *pr.GetPtr();
    if (r.V.CheckFixed())
    {
        for (UPInt i = 0; i < newSA.GetSize(); ++i)
            r.V.V.PushBack(newSA[i]);
    }
    result.Pick(pr);
}

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

// The whole-array sorts VectorSort calls (out of line in the exe).
namespace Scaleform { namespace Alg {
typedef GFx::AS3::Value AS3Value;
template bool QuickSortSafe(ArrayDH<const SInt32*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<SInt32>);
template bool QuickSortSafe(ArrayDH<const UInt32*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<UInt32>);
template bool QuickSortSafe(ArrayDH<const GFx::AS3::Value::Number*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<GFx::AS3::Value::Number>);
template bool QuickSortSafe(ArrayDH<const Ptr<GFx::ASStringNode>*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<Ptr<GFx::ASStringNode> >);
template bool QuickSortSafe(ArrayDH<const AS3Value*>&, GFx::AS3::Instances::fl_vec::CompareValuePtr<AS3Value>);
template bool QuickSortSafe(ArrayDH<Pair<GFx::ASString, UInt32> >&, GFx::AS3::Instances::fl_vec::CompareAsStringInd);
}} // namespace Scaleform::Alg

using namespace Scaleform;
using namespace Scaleform::GFx::AS3;
namespace VI = Scaleform::GFx::AS3::Instances::fl_vec;
namespace VT = Scaleform::GFx::AS3::InstanceTraits::fl_vec;

// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line; ours inlines it
// @0x142547960
void FUN_142547960(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorConcat<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line; ours inlines it
// @0x142547c40
void FUN_142547c40(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorConcat<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line; ours inlines it
// @0x142547f30
void FUN_142547f30(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorConcat<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line; ours inlines it
// @0x142548280
void FUN_142548280(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorConcat<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line; ours inlines it
// @0x142548580
void FUN_142548580(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorConcat<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }

// @0x142548bd0
void FUN_142548bd0(VectorBase<Ptr<GFx::ASStringNode> >& v, SPtr<VI::Vector_String>& result, const Value& callback, const Value& thisObject, VI::Vector_String& owner)
{ VI::VectorFilter<VI::Vector_String, VT::Vector_String>(v, result, callback, thisObject, owner); }
// @0x142548f60
void FUN_142548f60(VectorBase<Value::Number>& v, SPtr<VI::Vector_double>& result, const Value& callback, const Value& thisObject, VI::Vector_double& owner)
{ VI::VectorFilter<VI::Vector_double, VT::Vector_double>(v, result, callback, thisObject, owner); }
// @0x142549300
void FUN_142549300(VectorBase<SInt32>& v, SPtr<VI::Vector_int>& result, const Value& callback, const Value& thisObject, VI::Vector_int& owner)
{ VI::VectorFilter<VI::Vector_int, VT::Vector_int>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: register assignment for thisObject/callback differs from the exe
// @0x1425496a0
void FUN_1425496a0(VectorBase<Value>& v, SPtr<VI::Vector_object>& result, const Value& callback, const Value& thisObject, VI::Vector_object& owner)
{ VI::VectorFilter<VI::Vector_object, VT::Vector_object>(v, result, callback, thisObject, owner); }
// @0x142549a60
void FUN_142549a60(VectorBase<UInt32>& v, SPtr<VI::Vector_uint>& result, const Value& callback, const Value& thisObject, VI::Vector_uint& owner)
{ VI::VectorFilter<VI::Vector_uint, VT::Vector_uint>(v, result, callback, thisObject, owner); }

// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c050
void FUN_14254c050(VectorBase<Ptr<GFx::ASStringNode> >& v, SPtr<VI::Vector_String>& result, const Value& callback, const Value& thisObject, VI::Vector_String& owner)
{ VI::VectorMap<VI::Vector_String, VT::Vector_String>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c4e0
void FUN_14254c4e0(VectorBase<Value::Number>& v, SPtr<VI::Vector_double>& result, const Value& callback, const Value& thisObject, VI::Vector_double& owner)
{ VI::VectorMap<VI::Vector_double, VT::Vector_double>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254c980
void FUN_14254c980(VectorBase<SInt32>& v, SPtr<VI::Vector_int>& result, const Value& callback, const Value& thisObject, VI::Vector_int& owner)
{ VI::VectorMap<VI::Vector_int, VT::Vector_int>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce and the result PushBack; ours calls them
// @0x14254ce20
void FUN_14254ce20(VectorBase<Value>& v, SPtr<VI::Vector_object>& result, const Value& callback, const Value& thisObject, VI::Vector_object& owner)
{ VI::VectorMap<VI::Vector_object, VT::Vector_object>(v, result, callback, thisObject, owner); }
// MS2-FUNCTIONAL: the exe inlines ArrayBase::CheckCoerce; ours calls it
// @0x14254d380
void FUN_14254d380(VectorBase<UInt32>& v, SPtr<VI::Vector_uint>& result, const Value& callback, const Value& thisObject, VI::Vector_uint& owner)
{ VI::VectorMap<VI::Vector_uint, VT::Vector_uint>(v, result, callback, thisObject, owner); }

// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142550840
void FUN_142550840(VectorBase<Ptr<GFx::ASStringNode> >& v, Value& result, unsigned argc, const Value* argv, VI::Vector_String& owner)
{ VI::VectorSort<VI::Vector_String, VT::Vector_String>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142551250
void FUN_142551250(VectorBase<Value::Number>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_double& owner)
{ VI::VectorSort<VI::Vector_double, VT::Vector_double>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142551cb0
void FUN_142551cb0(VectorBase<SInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_int& owner)
{ VI::VectorSort<VI::Vector_int, VT::Vector_int>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor and Value::SetNull out of line; ours inlines them
// @0x1425526f0
void FUN_1425526f0(VectorBase<Value>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_object& owner)
{ VI::VectorSort<VI::Vector_object, VT::Vector_object>(v, result, argc, argv, owner); }
// MS2-FUNCTIONAL: the exe keeps Value::SetNull and the result-array growth out of line; ours inlines them
// @0x142553170
void FUN_142553170(VectorBase<UInt32>& v, Value& result, unsigned argc, const Value* argv, VI::Vector_uint& owner)
{ VI::VectorSort<VI::Vector_uint, VT::Vector_uint>(v, result, argc, argv, owner); }


// ==== Vector class traits (sfr19) ====================================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_vec
{
    extern const ClassInfo VectorCI;
    extern const ClassInfo Vector_StringCI;
    extern const ClassInfo Vector_doubleCI;
    extern const ClassInfo Vector_intCI;
    extern const ClassInfo Vector_objectCI;
    extern const ClassInfo Vector_uintCI;
    // The package of the Vector classes, "__AS3__.vec".
    extern const char* NS_Vector;
}

namespace ClassTraits { namespace fl_vec
{
    // @0x142546c50
    Pickable<Traits> Vector_int::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_int(vm));
    }

    // @0x142546da0
    Pickable<Traits> Vector_uint::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_uint(vm));
    }

    // @0x142546ef0
    Pickable<Traits> Vector_double::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_double(vm));
    }

    // @0x142547040
    Pickable<Traits> Vector_String::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_String(vm));
    }

    // @0x142547190
    Pickable<Traits> Vector_object::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector_object(vm));
    }

    // @0x142547420
    Pickable<Traits> Vector::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector(vm));
    }

    // @0x142554c80
    Vector::Vector(VM& vm)
        : Traits(vm, AS3::fl_vec::VectorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_vec::VectorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_vec::Vector(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142554d60
    Vector::Vector(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142554d90
    Vector_String::Vector_String(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_StringCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_StringCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142554e90
    Vector_String::Vector_String(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142554ec0
    Vector_String::Vector_String(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142554f50
    Vector_double::Vector_double(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_doubleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_doubleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142555050
    Vector_double::Vector_double(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142555080
    Vector_double::Vector_double(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x142555110
    Vector_int::Vector_int(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_intCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_intCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x142555210
    Vector_int::Vector_int(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x142555240
    Vector_int::Vector_int(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // The traits of Vector.<*>; its instance traits are made per element type.
    // @0x1425552d0
    Vector_object::Vector_object(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_objectCI)
        , EnclosedClassTraits(NULL)
    {
        TraitsType = Traits_Vector_object;
    }

    // @0x142555310
    Vector_object::Vector_object(VM& vm, const ASString& n, const ClassTraits::Traits* ect)
        : Traits(vm, AS3::fl_vec::Vector_objectCI)
        , EnclosedClassTraits(ect)
    {
        TraitsType = Traits_Vector_object;

        InstanceTraits::Traits* it = new(vm.GetMemoryHeap()) InstanceTraitsType(vm, n,
            vm.MakeInternedNamespace(Abc::NS_Public, AS3::fl_vec::NS_Vector),
            &vm.GetClassTraitsObject().GetInstanceTraits(), true, true);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(vm.GetMemoryHeap()) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x1425554a0
    Vector_object::Vector_object(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x1425554d0
    Vector_object::Vector_object(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, const Traits* pt,
        bool isDynamic, bool isFinal)
        : RTraits(vm, n, ns, pt, isDynamic, isFinal)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_Vector_object;
        for (unsigned i = 0; i < ThunkInfoNum; ++i)
            Add2VT(AS3::fl_vec::Vector_objectCI, AS3::fl_vec::Vector_objectCI.InstanceMethod[i]);
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_vec
{
    // @0x1425555c0
    Vector_uint::Vector_uint(VM& vm)
        : Traits(vm, AS3::fl_vec::Vector_uintCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraitsType(vm, AS3::fl_vec::Vector_uintCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassType(*this)));
    }
}}

namespace Classes { namespace fl_vec
{
    // @0x1425556c0
    Vector_uint::Vector_uint(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_vec
{
    // @0x1425556f0
    Vector_uint::Vector_uint(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x70);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// Argument defaults of the Vector.<T> callback methods, emitted out of line here (their ThunkFunc2 thunks are in
// sfr_as3_21): every 7, filter 8, forEach 9, some 11, map 14 per element type; callback undefined, thisObject null.
namespace Scaleform { namespace GFx { namespace AS3 {
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_String, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_double, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_int, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_object, 14, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 7, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 8, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 9, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 11, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_vec::Vector_uint, 14, const Value&, const Value&>(StringManager&);
}}} // namespace Scaleform::GFx::AS3

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
// MS2-PIN: ??$ReadDouble@E@Abc@AS3@GFx@Scaleform@@YANAEAPEBE@Z 0x142545390
// MS2-PIN: ??$ReadS24@E@Abc@AS3@GFx@Scaleform@@YAHPEBEAEA_K@Z 0x1425454b0
// MS2-PIN: ??$ReadString@E@Abc@AS3@GFx@Scaleform@@YA?AVString@3@AEAPEBE_K@Z 0x1425454f0
// MS2-PIN: ??$ReadString@E@Abc@AS3@GFx@Scaleform@@YA?AVString@3@PEBEAEA_K_K@Z 0x142545530
// MS2-FUNCTIONAL 0x1425455b0: the exe reloads the pointer/position through the reference on every loop pass; ours keeps it in a register
// MS2-PIN: ??$ReadU30@E@Abc@AS3@GFx@Scaleform@@YAHAEAPEBE@Z 0x1425455b0
// MS2-FUNCTIONAL 0x142545600: the exe reloads the pointer/position through the reference on every loop pass; ours keeps it in a register
// MS2-PIN: ??$ReadU30@E@Abc@AS3@GFx@Scaleform@@YAHPEBEAEA_K@Z 0x142545600
// MS2-PIN: ??_7ArrayBase@AS3@GFx@Scaleform@@6B@ 0x143181db8
// MS2-PIN: ??_7?$VectorBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181e08
// MS2-PIN: ??_7?$VectorBase@N@AS3@GFx@Scaleform@@6B@ 0x143182460
// MS2-PIN: ??_7?$VectorBase@J@AS3@GFx@Scaleform@@6B@ 0x143181e30
// MS2-PIN: ??_7?$VectorBase@VValue@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@6B@ 0x143181de0
// MS2-PIN: ??_7?$VectorBase@K@AS3@GFx@Scaleform@@6B@ 0x143182148
// MS2-PIN: ??_7Vector_String@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182788
// MS2-PIN: ??_7Vector_double@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182488
// MS2-PIN: ??_7Vector_int@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143181e58
// MS2-PIN: ??_7Vector_object@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182a88
// MS2-PIN: ??_7Vector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182170
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d950
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@1@@Z 0x14254df40
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@1@_K1U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@1@@Z 0x14254e530
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z: the exe reads the comparator VM reference before building the two Value temporaries, ours after; other registers and a 0x10 bigger exe frame follow, same calls and order
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254eb40
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@Scaleform@@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@1@_K1U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f140
// MS2-PIN: ??_G?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425564f0
// MS2-PIN: ??R?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142555b10
// MS2-PIN: ??_G?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425564c0
// MS2-PIN: ??R?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x142555a40
// MS2-PIN: ??_G?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556490
// MS2-PIN: ??R?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x1425559c0
// MS2-PIN: ??_G?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556460
// MS2-PIN: ??R?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555940
// MS2-PIN: ??_G?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556430
// MS2-PIN: ??R?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x1425558c0
// MS2-PIN: ??_G?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425565e0
// MS2-FUNCTIONAL ??R?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142555eb0
// MS2-PIN: ??_G?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425565b0
// MS2-FUNCTIONAL ??R?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x142555e50
// MS2-PIN: ??_G?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556580
// MS2-FUNCTIONAL ??R?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x142555d70
// MS2-PIN: ??_G?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556550
// MS2-FUNCTIONAL ??R?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555c90
// MS2-PIN: ??_G?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556520
// MS2-FUNCTIONAL ??R?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z: the exe keeps the pushed pair string node in rbx across the PushBack call and releases it from there; ours reloads it from the temporary
// MS2-PIN: ??R?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x142555bb0
// MS2-PIN: ??R?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBVValue@345@@Z 0x142556110
// MS2-PIN: ??R?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBV?$Ptr@UASStringNode@GFx@Scaleform@@@5@@Z 0x1425560a0
// MS2-PIN: ??R?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBN@Z 0x142556030
// MS2-PIN: ??R?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBK@Z 0x142555fc0
// MS2-PIN: ??R?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAXKAEBJ@Z 0x142555f50
// MS2-PIN: ??_G?$SortFunc@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556400
// MS2-PIN: ??_G?$SortFunc@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425563d0
// MS2-PIN: ??_G?$SortFunc@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425563a0
// MS2-PIN: ??_G?$SortFunc@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556370
// MS2-PIN: ??_G?$SortFunc@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556340
// MS2-PIN: ??_G?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425566d0
// MS2-PIN: ??_G?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556610
// MS2-PIN: ??_G?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556640
// MS2-PIN: ??_G?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142556670
// MS2-PIN: ??_G?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1425566a0
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@1@@Z: the exe swaps the (number, index) pairs member by member; ours moves the 16-byte pair with movups
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@NK@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsNumberInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f400
// MS2-FUNCTIONAL ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z: the inlined (string, index) pair swaps and node releases get other registers and frame layout; same calls and order
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@_K1UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254f740
// MS2-PIN: ??_7?$SortFunc@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182d88
// MS2-PIN: ??_7?$SortFunc@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182da8
// MS2-PIN: ??_7?$SortFunc@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182dc8
// MS2-PIN: ??_7?$SortFunc@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182de8
// MS2-PIN: ??_7?$SortFunc@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e08
// MS2-PIN: ??_7?$Value2NumberCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182d98
// MS2-PIN: ??_7?$Value2NumberCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182db8
// MS2-PIN: ??_7?$Value2NumberCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182dd8
// MS2-PIN: ??_7?$Value2NumberCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182df8
// MS2-PIN: ??_7?$Value2NumberCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e18
// MS2-PIN: ??_7?$Value2StrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e28
// MS2-PIN: ??_7?$Value2StrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e38
// MS2-PIN: ??_7?$Value2StrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e48
// MS2-PIN: ??_7?$Value2StrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e58
// MS2-PIN: ??_7?$Value2StrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182e68
// MS2-PIN: ??_7?$ValuePtrCollector@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ec8
// MS2-PIN: ??_7?$ValuePtrCollector@J@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ed8
// MS2-PIN: ??_7?$ValuePtrCollector@K@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ee8
// MS2-PIN: ??_7?$ValuePtrCollector@N@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182ef8
// MS2-PIN: ??_7?$ValuePtrCollector@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@Scaleform@@6B@ 0x143182f08
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142549df0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142549f50
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a0b0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a210
// MS2-PIN: ??$ThunkMakeDefs2@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a370
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a4d0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a630
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a790
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254a8f0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254aa50
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254abb0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254ad10
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254ae70
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254afd0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_int@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b130
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b290
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b3f0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b550
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b6b0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b810
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$06AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254b970
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$07AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bad0
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$08AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bc30
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0L@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bd90
// MS2-PIN: ??$ThunkMakeDefs2@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x14254bef0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBJ$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@J@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d820
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBK$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@K@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d850
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBN$01UArrayDefaultPolicy@Scaleform@@@1@U?$CompareValuePtr@N@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d880
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBV?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@1@U?$CompareValuePtr@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d8b0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@Scaleform@@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@PEBVValue@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@1@U?$CompareValuePtr@VValue@AS3@GFx@Scaleform@@@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d8e0
// MS2-PIN: ??$QuickSortSafe@V?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@2@@Alg@Scaleform@@YA_NAEAV?$ArrayDH@U?$Pair@VASString@GFx@Scaleform@@K@Scaleform@@$01UArrayDefaultPolicy@2@@1@UCompareAsStringInd@fl_vec@Instances@AS3@GFx@1@@Z 0x14254d920
// MS2-PIN: ??$Read16@E@Abc@AS3@GFx@Scaleform@@YAHAEAPEBE@Z 0x142545350
// MS2-PIN: ??$ReadStringPtr@E@Abc@AS3@GFx@Scaleform@@YA?AVStringDataPtr@3@AEAPEBE_K@Z 0x142545570
// MS2-PIN: ??_GCode@Abc@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142545b70
// MS2-PIN: ??_7Code@Abc@AS3@GFx@Scaleform@@6B@ 0x143181a00
// MS2-PIN: ??_7File@Abc@AS3@GFx@Scaleform@@6B@ 0x14317b050
