// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_20
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142542820-0x1425584f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
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

}}}} // namespace Scaleform::GFx::AS3::Abc

// ---------------------------------------------------------------- Vector.<T> natives

// ArrayBase::Every (sfr_as3_21): callback(element, index, owner) on thisObject while it returns true
bool FUN_14255bbd0(const Scaleform::GFx::AS3::ArrayBase& v, const Scaleform::GFx::AS3::Value& callback,
    const Scaleform::GFx::AS3::Value& thisObject, Scaleform::GFx::AS3::Instances::fl::Object* owner);
// VectorBase<T>::PushBack(argc, argv, element ClassTraits) (sfr_as3_21)
void FUN_142561d20(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >& v, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv, const Scaleform::GFx::AS3::ClassTraits::Traits& tr);
void FUN_142561af0(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value::Number>& v, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv, const Scaleform::GFx::AS3::ClassTraits::Traits& tr);
void FUN_1425616b0(Scaleform::GFx::AS3::VectorBase<Scaleform::SInt32>& v, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv, const Scaleform::GFx::AS3::ClassTraits::Traits& tr);
void FUN_142561f40(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>& v, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv, const Scaleform::GFx::AS3::ClassTraits::Traits& tr);
void FUN_1425618d0(Scaleform::GFx::AS3::VectorBase<Scaleform::UInt32>& v, unsigned argc,
    const Scaleform::GFx::AS3::Value* argv, const Scaleform::GFx::AS3::ClassTraits::Traits& tr);
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
    result = FUN_14255bbd0(V, callback, thisObject, this);
}

// @0x1425574d0
void Vector_double::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = FUN_14255bbd0(V, callback, thisObject, this);
}

// @0x142557500
void Vector_int::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = FUN_14255bbd0(V, callback, thisObject, this);
}

// @0x142557530
void Vector_object::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = FUN_14255bbd0(V, callback, thisObject, this);
}

// @0x142557560
void Vector_uint::AS3every(bool& result, const Value& callback, const Value& thisObject)
{
    result = FUN_14255bbd0(V, callback, thisObject, this);
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
    FUN_142561d20(V, argc, argv, GetVM().GetClassTraitsString());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x1425581a0
void Vector_double::AS3push(Value& result, unsigned argc, const Value* argv)
{
    FUN_142561af0(V, argc, argv, GetVM().GetClassTraitsNumber());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558220
void Vector_int::AS3push(Value& result, unsigned argc, const Value* argv)
{
    FUN_1425616b0(V, argc, argv, GetVM().GetClassTraitsSInt());
    result.SetUInt32((UInt32)V.V.GetSize());
}

// MS2-FUNCTIONAL: the exe calls Traits::GetConstructor out of line (0x142508490); ours inlines it
// @0x1425582a0
void Vector_object::AS3push(Value& result, unsigned argc, const Value* argv)
{
    FUN_142561f40(V, argc, argv, GetEnclosedClassTraits(*this));
    result.SetUInt32((UInt32)V.V.GetSize());
}

// @0x142558340
void Vector_uint::AS3push(Value& result, unsigned argc, const Value* argv)
{
    FUN_1425618d0(V, argc, argv, GetVM().GetClassTraitsUInt());
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
// Append(other) / PushBack(element) of the result instances (sfr_as3_21)
void FUN_142559c00(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& r, const Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& other);
void FUN_142559cd0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& r, const Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& other);
void FUN_142559dc0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& r, const Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& other);
void FUN_142559eb0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& r, const Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& other);
void FUN_142559fc0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& r, const Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& other);
void FUN_1425621c0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String& r, Scaleform::GFx::ASStringNode* v);
void FUN_142562280(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double& r, Scaleform::GFx::AS3::Value::Number v);
void FUN_142562340(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int& r, Scaleform::SInt32 v);
void FUN_1425623f0(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object& r, const Scaleform::GFx::AS3::Value& v);
void FUN_142562470(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint& r, Scaleform::UInt32 v);

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_vec {

// the element as a callback argument
static SF_INLINE Value ElementValue(const Ptr<ASStringNode>& e)     { return Value(e.GetPtr()); }
static SF_INLINE Value ElementValue(Value::Number e)                { return Value(e); }
static SF_INLINE Value ElementValue(SInt32 e)                       { return Value(e); }
static SF_INLINE Value ElementValue(const Value& e)                 { return e; }
static SF_INLINE Value ElementValue(UInt32 e)                       { return Value(e); }

// an element pushed into the result instance
static SF_INLINE void PushElement(Vector_String& r, const Ptr<ASStringNode>& e)    { FUN_1425621c0(r, e.GetPtr()); }
static SF_INLINE void PushElement(Vector_double& r, Value::Number e)                { FUN_142562280(r, e); }
static SF_INLINE void PushElement(Vector_int& r, SInt32 e)                         { FUN_142562340(r, e); }
static SF_INLINE void PushElement(Vector_object& r, const Value& e)                { FUN_1425623f0(r, e); }
static SF_INLINE void PushElement(Vector_uint& r, UInt32 e)                        { FUN_142562470(r, e); }

// a coerced Value pushed into the result instance
static SF_INLINE void PushCoerced(Vector_String& r, const Value& v)    { FUN_1425621c0(r, v.AsStringNode()); }
static SF_INLINE void PushCoerced(Vector_double& r, const Value& v)    { FUN_142562280(r, v.AsNumber()); }
static SF_INLINE void PushCoerced(Vector_int& r, const Value& v)       { FUN_142562340(r, v.AsInt()); }
static SF_INLINE void PushCoerced(Vector_object& r, const Value& v)    { FUN_1425623f0(r, v); }
static SF_INLINE void PushCoerced(Vector_uint& r, const Value& v)      { FUN_142562470(r, v.AsUInt()); }

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

static SF_INLINE void Append(Vector_String& r, const Vector_String& o)  { FUN_142559c00(r, o); }
static SF_INLINE void Append(Vector_double& r, const Vector_double& o)  { FUN_142559cd0(r, o); }
static SF_INLINE void Append(Vector_int& r, const Vector_int& o)        { FUN_142559dc0(r, o); }
static SF_INLINE void Append(Vector_object& r, const Vector_object& o)  { FUN_142559eb0(r, o); }
static SF_INLINE void Append(Vector_uint& r, const Vector_uint& o)      { FUN_142559fc0(r, o); }

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

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_vec

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
