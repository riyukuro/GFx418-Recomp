// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_20
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142542820-0x1425584f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"

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
