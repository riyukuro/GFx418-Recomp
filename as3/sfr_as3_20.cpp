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
