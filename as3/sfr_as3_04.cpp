// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424133c0-0x14242a640 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl::Array::AS3slice argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 8, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0xffffff; }
};
// thunk 0x1424133c0: Instances::fl::Array::AS3slice
template struct ThunkFunc2<Instances::fl::Array, 8, SPtr<Instances::fl::Array>, SInt32, SInt32>;
// thunk 0x142413510: Instances::fl::Array::AS3unshift
template struct ThunkFunc2<Instances::fl::Array, 9, Value, unsigned, const Value*>;
// thunk 0x142413530: Instances::fl::Array::AS3splice
template struct ThunkFunc2<Instances::fl::Array, 10, Value, unsigned, const Value*>;
// thunk 0x142413550: Instances::fl::Array::AS3filter
template struct ThunkFunc2<Instances::fl::Array, 16, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x1424136c0: Instances::fl::Array::AS3forEach
template struct ThunkFunc2<Instances::fl::Array, 17, const Value, const Value&, const Value&>;
// thunk 0x1424137a0: Instances::fl::Array::AS3map
template struct ThunkFunc2<Instances::fl::Array, 18, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413910: Instances::fl::Array::AS3some
template struct ThunkFunc2<Instances::fl::Array, 19, bool, const Value&, const Value&>;
// thunk 0x142413a30: Instances::fl::Array::AS3sort
template struct ThunkFunc2<Instances::fl::Array, 11, Value, unsigned, const Value*>;
// thunk 0x142413a50: Instances::fl::Array::AS3sortOn
template struct ThunkFunc2<Instances::fl::Array, 12, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413bc0: Instances::fl::Array::AS3indexOf
template struct ThunkFunc2<Instances::fl::Array, 13, SInt32, const Value&, SInt32>;
// Instances::fl::Array::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 14, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x142413d70: Instances::fl::Array::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl::Array, 14, SInt32, const Value&, SInt32>;
// thunk 0x142413f20: Instances::fl::Array::AS3every
template struct ThunkFunc2<Instances::fl::Array, 15, bool, const Value&, const Value&>;
// thunk 0x142414040: Instances::fl::Date::AS3setFullYear
template struct ThunkFunc2<Instances::fl::Date, 27, Value, unsigned, const Value*>;
// thunk 0x142414060: Instances::fl::Date::AS3setMonth
template struct ThunkFunc2<Instances::fl::Date, 28, Value, unsigned, const Value*>;
// thunk 0x142414080: Instances::fl::Date::AS3setDate
template struct ThunkFunc2<Instances::fl::Date, 29, Value, unsigned, const Value*>;
// thunk 0x1424140a0: Instances::fl::Date::AS3setHours
template struct ThunkFunc2<Instances::fl::Date, 30, Value, unsigned, const Value*>;
// thunk 0x1424140c0: Instances::fl::Date::AS3setMinutes
template struct ThunkFunc2<Instances::fl::Date, 31, Value, unsigned, const Value*>;
// thunk 0x1424140e0: Instances::fl::Date::AS3setSeconds
template struct ThunkFunc2<Instances::fl::Date, 32, Value, unsigned, const Value*>;
// thunk 0x142414100: Instances::fl::Date::AS3setMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 33, Value, unsigned, const Value*>;
// thunk 0x142414120: Instances::fl::Date::AS3setUTCFullYear
template struct ThunkFunc2<Instances::fl::Date, 34, Value, unsigned, const Value*>;
// thunk 0x142414140: Instances::fl::Date::AS3setUTCMonth
template struct ThunkFunc2<Instances::fl::Date, 35, Value, unsigned, const Value*>;
// thunk 0x142414160: Instances::fl::Date::AS3setUTCDate
template struct ThunkFunc2<Instances::fl::Date, 36, Value, unsigned, const Value*>;
// thunk 0x142414180: Instances::fl::Date::AS3setUTCHours
template struct ThunkFunc2<Instances::fl::Date, 37, Value, unsigned, const Value*>;
// thunk 0x1424141a0: Instances::fl::Date::AS3setUTCMinutes
template struct ThunkFunc2<Instances::fl::Date, 38, Value, unsigned, const Value*>;
// thunk 0x1424141c0: Instances::fl::Date::AS3setUTCSeconds
template struct ThunkFunc2<Instances::fl::Date, 39, Value, unsigned, const Value*>;
// thunk 0x1424141e0: Instances::fl::Date::AS3setUTCMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 40, Value, unsigned, const Value*>;
// thunk 0x142414200: Instances::fl::GlobalObjectCPP::parseInt
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 6, Value, unsigned, const Value*>;
// thunk 0x142414220: Instances::fl::GlobalObjectCPP::escape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 8, Value, unsigned, const Value*>;
// thunk 0x142414240: Instances::fl::GlobalObjectCPP::unescape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 9, Value, unsigned, const Value*>;
// thunk 0x142414260: Instances::fl::GlobalObjectCPP::trace
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 11, Value, unsigned, const Value*>;
// thunk 0x142414280: Instances::fl::GlobalObjectCPP::print
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 12, Value, unsigned, const Value*>;
// thunk 0x1424142a0: Instances::fl::GlobalObjectCPP::fscommand
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 30, Value, unsigned, const Value*>;
// thunk 0x1424142c0: Instances::fl::GlobalObjectCPP::setInterval
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 21, Value, unsigned, const Value*>;
// thunk 0x1424142e0: Instances::fl::GlobalObjectCPP::setTimeout
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 22, Value, unsigned, const Value*>;
// thunk 0x142414300: Classes::fl::String::fromCharCode
template struct ThunkFunc2<Classes::fl::String, 1, Value, unsigned, const Value*>;
// thunk 0x142414320: Instances::fl::XML::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XML, 4, Value, unsigned, const Value*>;
// thunk 0x142414340: Instances::fl::XML::AS3elements
template struct ThunkFunc2<Instances::fl::XML, 16, Value, unsigned, const Value*>;
// thunk 0x142414360: Instances::fl::XML::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XML, 20, Value, const Value&, const Value&>;
// thunk 0x142414440: Instances::fl::XML::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XML, 21, Value, const Value&, const Value&>;
// thunk 0x142414520: Instances::fl::XML::AS3namespace_
template struct ThunkFunc2<Instances::fl::XML, 25, Value, unsigned, const Value*>;
// thunk 0x142414540: Instances::fl::XML::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XML, 30, Value, unsigned, const Value*>;
// thunk 0x142414560: Instances::fl::XML::AS3replace
template struct ThunkFunc2<Instances::fl::XML, 33, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x1424146d0: Instances::fl::XML::AS3descendants
template struct ThunkFunc2<Instances::fl::XML, 15, Value, unsigned, const Value*>;
// thunk 0x1424146f0: Instances::fl::XMLList::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XMLList, 6, Value, unsigned, const Value*>;
// thunk 0x142414710: Instances::fl::XMLList::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XMLList, 21, Value, unsigned, const Value*>;
// thunk 0x142414730: Instances::fl::XMLList::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XMLList, 28, Value, const Value&, const Value&>;
// thunk 0x142414810: Instances::fl::XMLList::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XMLList, 29, Value, const Value&, const Value&>;
// thunk 0x1424148f0: Instances::fl::XMLList::AS3namespace_
template struct ThunkFunc2<Instances::fl::XMLList, 31, Value, unsigned, const Value*>;
// thunk 0x142414910: Instances::fl::XMLList::AS3replace
template struct ThunkFunc2<Instances::fl::XMLList, 36, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x142414a80: Instances::fl::XMLList::AS3descendants
template struct ThunkFunc2<Instances::fl::XMLList, 14, Value, unsigned, const Value*>;
// thunk 0x142414aa0: Instances::fl::XMLList::AS3elements
template struct ThunkFunc2<Instances::fl::XMLList, 15, Value, unsigned, const Value*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <sys/timeb.h>
#include <math.h>
#include "ms2/scaleform/kernel/sf_random.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_asutils.h"
#include <string.h>
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- Value: reference take-over of the function / namespace kinds ----

// @0x14241dc00
void Value::Pick(Instances::FunctionBase* v)
{
    Release();
    SetKind(kFunction);
    value = reinterpret_cast<Instances::Function*>(v);
}

// @0x14241dc60
void Value::Pick(Instances::Function* v)
{
    Release();
    SetKind(kFunction);
    value = v;
}

// @0x14241dcc0
void Value::Pick(Instances::Namespace* v)
{
    Release();
    SetKind(kNamespace);
    value = v;
}

// @0x14241dd20
void Value::Pick(Instances::ThunkFunction* v)
{
    Release();
    SetKind(kThunkFunction);
    value = v;
}

// @0x14241ddc0
void Value::PickUnsafe(Instances::Function* v)
{
    SetKind(kFunction);
    value = v;
}

// @0x14241dde0
void Value::PickUnsafe(Instances::FunctionBase* v)
{
    SetKind(kFunction);
    value = reinterpret_cast<Instances::Function*>(v);
}

// @0x14241de00
void Value::PickUnsafe(Instances::Namespace* v)
{
    SetKind(kNamespace);
    value = v;
}

// @0x14241de20
void Value::PickUnsafe(Instances::ThunkFunction* v)
{
    SetKind(kThunkFunction);
    value = v;
}


// ---- XML 1.0 (5th ed.) name productions ----

// MS2-FUNCTIONAL: range tests are ordered/merged differently by the compiler
// @0x142419b10
CheckResult IsNameStartChar(int c)
{
    return c == ':' || c == '_' ||
        (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= 0xC0 && c <= 0xD6) || (c >= 0xD8 && c <= 0xF6) || (c >= 0xF8 && c <= 0x2FF) ||
        (c >= 0x370 && c <= 0x37D) || (c >= 0x37F && c <= 0x1FFF) || (c >= 0x200C && c <= 0x200D) ||
        (c >= 0x2070 && c <= 0x218F) || (c >= 0x2C00 && c <= 0x2FEF) || (c >= 0x3001 && c <= 0xD7FF) ||
        (c >= 0xF900 && c <= 0xFDCF) || (c >= 0xFDF0 && c <= 0xFFFD) || (c >= 0x10000 && c <= 0xEFFFF);
}

// MS2-FUNCTIONAL: the '-', '.', digit range tests compile to a bit test
// @0x142419aa0
CheckResult IsNameChar(int c)
{
    return IsNameStartChar(c) || (c >= '-' && c <= '.') || (c >= '0' && c <= '9') || c == 0xB7 ||
        (c >= 0x300 && c <= 0x36F) || (c >= 0x203F && c <= 0x2040);
}

// @0x142419a50
CheckResult IsNCNameStartChar(int c)
{
    return IsNameStartChar(c) && c != ':';
}

// MS2-FUNCTIONAL: the inlined '-', '.', digit range tests compile to a bit test
// @0x1424199d0
CheckResult IsNCNameChar(int c)
{
    return IsNameChar(c) && c != ':';
}

// MS2-FUNCTIONAL: the inlined IsNameChar range tests compile differently
// @0x142419bf0
CheckResult IsValidName(const ASString& name)
{
    if (name.GetLength() == 0 || !IsNameStartChar(name[0]))
        return false;
    const unsigned len = name.GetLength();
    for (unsigned i = 1; i < len; ++i)
    {
        if (!IsNameChar(name[i]))
            return false;
    }
    return true;
}

// ---- SparseArray: dense ValueA, then sparse indices [ValueHLowInd, ValueHHighInd] in ValueH ----

// MS2-FUNCTIONAL: the exe inlines the hash lookup with different loop layout
// @0x142415de0
UPInt SparseArray::GetLeftEqualInd(UPInt start_from) const
{
    SPInt i = static_cast<SPInt>(start_from);
    for (; i >= 0; --i)
    {
        if (ValueH.Get(i))
            break;
    }
    return static_cast<UPInt>(i);
}

// MS2-FUNCTIONAL: the exe inlines the hash lookup with different loop layout
// @0x142416eb0
UPInt SparseArray::GetRightEqualInd(UPInt start_from, UPInt end_ind) const
{
    UPInt i = start_from;
    for (; i <= end_ind; ++i)
    {
        if (ValueH.Get(i))
            break;
    }
    return i;
}

// MS2-FUNCTIONAL: branch order and the inlined hash lookups differ
// @0x142416000
SF_NOINLINE AbsoluteIndex SparseArray::GetNextArrayIndex(AbsoluteIndex ind) const
{
    const UPInt denseSize = ValueA.GetSize();
    if (!ind.IsValid())
    {
        if (denseSize != 0)
            return AbsoluteIndex(0);
        if (ValueH.GetSize() != 0)
            return AbsoluteIndex(ValueHLowInd);
    }
    else
    {
        const UPInt i = static_cast<UInt32>(ind.Get());
        if (static_cast<UPInt>(ind.Get()) < denseSize)
        {
            if (i != denseSize - 1)
                return AbsoluteIndex(ind.Get() + 1);
            if (ValueH.GetSize() != 0)
                return AbsoluteIndex(ValueHLowInd);
        }
        if (i >= ValueHLowInd && i <= ValueHHighInd)
        {
            for (UPInt j = static_cast<UInt32>(i + 1); j <= ValueHHighInd; ++j)
            {
                if (ValueH.Get(j))
                    return AbsoluteIndex(j);
            }
        }
    }
    return AbsoluteIndex(-1);
}

// MS2-FUNCTIONAL: the exe inlines the hash lookup with different block layout
// @0x142427180
const Value& SparseArray::Top() const
{
    const UPInt ind = Length - 1;
    if (ind < ValueA.GetSize())
        return ValueA[ind];
    if (ind >= ValueHLowInd && ind <= ValueHHighInd)
    {
        const Value* v = ValueH.Get(ind);
        if (v)
            return *v;
    }
    return DefaultValue;
}

// @0x14241e4b0
void SparseArray::PushBack(const Value& v)
{
    if (Length == ValueA.GetSize())
        ValueA.PushBack(v);
    else
    {
        ValueHHighInd = Length;
        ValueH.Set(ValueHHighInd, v);
    }
    ++Length;
}

// @0x14241d1b0
void SparseArray::MoveHashRight(UPInt first_ind, UPInt offset)
{
    Value v;
    for (UPInt i = ValueHHighInd + 1; i > first_ind; --i)
    {
        const UPInt ci = i - 1;
        if (ValueH.Get(ci, &v))
        {
            ValueH.Remove(ci);
            ValueH.Set(ci + offset, v);
        }
    }
}

// MS2-FUNCTIONAL: the exe inlines Hash::Get/Remove with different register use
// @0x14241e9d0
void SparseArray::RemoveHash(UPInt first_ind, UPInt num)
{
    for (UInt32 i = 0; i < num; ++i)
    {
        const UPInt ind = i + first_ind;
        if (ValueH.Get(ind))
            ValueH.Remove(ind);
    }
}

// MS2-FUNCTIONAL: the exe's trim loop of the hash tail reads its key through a null node pointer (it faults when
// reached); ours drops the hash entries past the new length instead
// @0x14241fe30
void SparseArray::Resize(UPInt newLength)
{
    if (newLength == 0)
        ValueA.Clear();
    else if (newLength <= ValueA.GetSize() && ValueA.GetSize() != 0)
        ValueA.Resize(newLength);
    else if (newLength >= ValueHLowInd)
    {
        if (newLength < ValueHHighInd)
        {
            while (newLength < ValueHHighInd)
            {
                ValueH.Remove(ValueHHighInd);
                --ValueHHighInd;
            }
        }
        Length = newLength;
        return;
    }
    ValueH.Clear();
    Length = newLength;
    ValueHLowInd = 0;
    ValueHHighInd = 0;
}

// MS2-FUNCTIONAL: the exe inlines ValueA.PushBack inside the dense-merge loop
// @0x1424213b0
void SparseArray::Set(UPInt ind, const Value& v)
{
    if (ind >= Length)
        Resize(ind + 1);

    if (ind < ValueA.GetSize())
        ValueA[ind].Assign(v);
    else if (ind == ValueA.GetSize())
    {
        ValueA.PushBack(v);

        // Pull the hash run that now continues the dense part into ValueA.
        Value hv;
        while (ValueA.GetSize() == ValueHLowInd)
        {
            const Value* p = ValueH.Get(ValueHLowInd);
            if (!p)
                break;
            hv.Assign(*p);
            ValueH.Remove(ValueHLowInd);
            ValueA.PushBack(hv);
            if (ValueH.IsEmpty())
            {
                ValueH.Clear();
                ValueHHighInd = 0;
                ValueHLowInd = 0;
            }
            else
                ValueHLowInd = (*ValueH.Begin()).First;
        }
    }
    else
    {
        ValueH.Set(ind, v);
        if (ind < ValueHLowInd || ValueH.GetSize() == 1)
            ValueHLowInd = ind;
        if (ind > ValueHHighInd)
            ValueHHighInd = ind;
    }
}

// @0x142418d50
void SparseArray::Insert(UPInt pos, unsigned argc, const Value* argv)
{
    if (pos < ValueA.GetSize())
    {
        for (unsigned i = 0; i < argc; ++i)
            ValueA.InsertAt(pos + i, argv[i]);
        if (ValueHLowInd != 0)
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHLowInd += argc;
            ValueHHighInd += argc;
        }
    }
    else if (pos == ValueA.GetSize())
    {
        for (unsigned i = 0; i < argc; ++i)
            ValueA.PushBack(argv[i]);
        if (!ValueH.IsEmpty())
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHLowInd += argc;
            ValueHHighInd += argc;
        }
    }
    else
    {
        if (pos < ValueHLowInd)
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHHighInd += argc;
            ValueHLowInd = pos;
        }
        else if (pos <= ValueHHighInd)
        {
            MoveHashRight(pos, argc);
            ValueHHighInd += argc;
        }
        else
            ValueHHighInd = pos - 1 + argc;

        for (unsigned i = 0; i < argc; ++i)
            ValueH.Set(pos + i, argv[i]);
    }
    Length += argc;
}

namespace Instances { namespace fl
{
    // ---- Array: indices are the dense/sparse store, everything else goes to Object ----

    // Element ind of the store, DefaultValue for holes.
    static SF_INLINE const Value& ElementAt(const SparseArray& sa, UPInt ind)
    {
        if (ind < sa.ValueA.GetSize())
            return sa.ValueA[ind];
        if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
        {
            const Value* v = sa.ValueH.Get(ind);
            if (v)
                return *v;
        }
        return sa.DefaultValue;
    }

    // @0x142421ff0
    CheckResult Array::SetProperty(const Multiname& prop_name, const Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            SA.Set(ind, value);
            return true;
        }
        return Object::SetProperty(prop_name, value);
    }

    // MS2-FUNCTIONAL: the exe tail-calls Value::Assign with the inlined element lookup laid out differently
    // @0x142416730
    CheckResult Array::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            value.Assign(ElementAt(SA, ind));
            return true;
        }
        return Object::GetProperty(prop_name, value);
    }

    // MS2-FUNCTIONAL: the exe reads the index as 32 bits
    // @0x1424159a0
    void Array::GetDynamicProperty(AbsoluteIndex ind, Value& value)
    {
        value.Assign(ElementAt(SA, ind.Get()));
    }

    // MS2-FUNCTIONAL: the SetUndefined/SetUInt32 releases inline with different block layout
    // @0x142416200
    void Array::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        if (!ind.IsValid())
        {
            name.SetUndefined();
            return;
        }
        if (ind.Get() <= SA.GetSize())
            name.SetUInt32(ind.Get() - 1);
        else
            Object::GetNextPropertyName(name, GlobalSlotIndex(ind.Get() - static_cast<UInt32>(SA.GetSize())));
    }

    // MS2-FUNCTIONAL: the exe keeps the slot index in a callee-saved register across the Object call
    // @0x142416100
    GlobalSlotIndex Array::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        if (ind.Get() <= SA.GetSize())
        {
            const AbsoluteIndex next = SA.GetNextArrayIndex(AbsoluteIndex(static_cast<UPInt>(ind.Get()) - 1));
            if (next.IsValid())
                return GlobalSlotIndex(static_cast<UInt32>(next.Get()) + 1);
        }
        UInt32 i = ind.Get();
        if (i >= static_cast<UInt32>(SA.GetSize()))
            i -= static_cast<UInt32>(SA.GetSize());
        GlobalSlotIndex r = Object::GetNextDynPropIndex(GlobalSlotIndex(i));
        if (!r.IsValid())
            return r;
        return GlobalSlotIndex(r.Get() + static_cast<UInt32>(SA.GetSize()));
    }

    // MS2-FUNCTIONAL: the exe tail-calls Value::Assign from each branch
    // @0x142416520
    void Array::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
    {
        if (!ind.IsValid())
        {
            value.SetUndefined();
            return;
        }
        if (ind.Get() > SA.GetSize())
        {
            Object::GetNextPropertyValue(value, GlobalSlotIndex(ind.Get() - static_cast<UInt32>(SA.GetSize())));
            return;
        }
        value.Assign(ElementAt(SA, ind.Get() - 1));
    }

    // @0x142429290
    void Array::lengthGet(UInt32& result)
    {
        result = static_cast<UInt32>(SA.GetSize());
    }
}} // namespace Instances::fl

namespace Instances { namespace fl
{
    // ---- Date: ECMA-262 15.9.1 time arithmetic ----

    static const Value::Number msPerSecond  = 1000.0;
    static const Value::Number msPerMinute  = 60000.0;
    static const Value::Number msPerHour    = 3600000.0;
    static const Value::Number msPerDay     = 86400000.0;

    // Days before the end of each month: common years, then leap years.
    static const SInt32 MonthEndDay[24] =
    {
        31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365,
        31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
    };

    static SF_INLINE bool IsLeapYear(SInt32 y)
    {
        return (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0);
    }

    // Day number of the first day of year y.
    static SF_INLINE Value::Number DayFromYear(Value::Number y)
    {
        return ::floor((y - 1969.0) * 0.25) + (y - 1970.0) * 365.0 - ::floor((y - 1901.0) / 100.0) +
               ::floor((y - 1601.0) / 400.0);
    }

    static SF_INLINE Value::Number TimeFromYear(Value::Number y)
    {
        return msPerDay * DayFromYear(y);
    }

    // @0x142415730
    void Date::GetCurrentTimeValue(Value::Number* pTime, SInt32* pLocalTZA)
    {
        __timeb64 tb;
        TIME_ZONE_INFORMATION tzi;
        _ftime64(&tb);
        GetTimeZoneInformation(&tzi);
        *pLocalTZA = tzi.Bias * -60000;
        *pTime = static_cast<Value::Number>(tb.time) * 1000.0 + tb.millitm;
    }

    // @0x142417730
    Value::Number Date::HourFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerHour), 24.0);
        if (r < 0)
            r += 24.0;
        return r;
    }

    // @0x14241ccb0
    Value::Number Date::MinFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerMinute), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    // @0x142421230
    Value::Number Date::SecFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerSecond), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    // @0x14241d500
    Value::Number Date::MsFromTime(Value::Number t)
    {
        Value::Number r = fmod(t, msPerSecond);
        if (r < 0)
            r += msPerSecond;
        return r;
    }

    // @0x142427260
    SInt32 Date::WeekDay(Value::Number t)
    {
        SInt32 r = static_cast<SInt32>(fmod(::floor(t / msPerDay) + 4.0, 7.0));
        return r < 0 ? r + 7 : r;
    }

    // MS2-FUNCTIONAL: binary-search register allocation differs
    // @0x1424272a0
    Value::Number Date::YearFromTime(Value::Number t)
    {
        // The year lies between the estimates for all-leap and all-common years.
        const SInt32 y1 = static_cast<SInt32>(::floor(t / 31536000000.0)) + 1970;
        const SInt32 y2 = static_cast<SInt32>(::floor(t / 31622400000.0)) + 1970;
        SInt32 lo = y2 <= y1 ? y2 : y1;
        SInt32 hi = y2 <= y1 ? y1 : y2;
        while (lo < hi)
        {
            const SInt32 mid = (lo + hi) / 2;
            if (TimeFromYear(mid) <= t)
            {
                if (t < TimeFromYear(mid + 1))
                    return mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return lo;
    }

    // MS2-FUNCTIONAL: exe unrolls the month-table scan by six; ours is a plain loop
    // @0x14241cdc0
    SInt32 Date::MonthFromYearDay(SInt32 year, SInt32 day)
    {
        const SInt32* tbl = IsLeapYear(year) ? MonthEndDay + 12 : MonthEndDay;
        SInt32 m = 0;
        for (; m < 12; ++m)
        {
            if (day < tbl[m])
                break;
        }
        return m;
    }

    // MS2-FUNCTIONAL: DayFromYear term order/constant loads differ
    // @0x14241ccf0
    SInt32 Date::MonthFromTime(Value::Number t)
    {
        const Value::Number y = YearFromTime(t);
        return MonthFromYearDay(static_cast<SInt32>(y), static_cast<SInt32>(::floor(t / msPerDay) - DayFromYear(y)));
    }

    // MS2-FUNCTIONAL: month/leap index arithmetic schedules differently
    // @0x14241a230
    Value::Number Date::MakeDay(Value::Number year, Value::Number month, Value::Number date)
    {
        if (NumberUtil::IsNaNOrInfinity(year + month + date))
            return NumberUtil::NaN();

        const SInt32 m = static_cast<SInt32>(month);
        const Value::Number ym = static_cast<SInt32>(year) + ::floor(m / 12.0);
        Value::Number mn = fmod(static_cast<Value::Number>(m), 12.0);
        if (mn < 0)
            mn += 12.0;
        const Value::Number day = ::floor(DayFromYear(ym));
        const SInt32 leap = IsLeapYear(static_cast<SInt32>(ym)) ? 12 : 0;
        const SInt32 im = static_cast<SInt32>(mn);
        const SInt32 monthDay = im != 0 ? MonthEndDay[im - 1 + leap] : 0;
        return monthDay + day + static_cast<SInt32>(date) - 1.0;
    }

    static SF_INLINE Value::Number ToInteger(Value::Number v)
    {
        return v > 0 ? ::floor(v) : -::floor(-v);
    }

    // @0x14241c6a0
    Value::Number Date::MakeTime(Value::Number hour, Value::Number min, Value::Number sec, Value::Number ms)
    {
        if (NumberUtil::IsNaNOrInfinity(hour + min + sec + ms))
            return NumberUtil::NaN();
        const Value::Number h = ToInteger(hour);
        const Value::Number m = ToInteger(min);
        const Value::Number s = ToInteger(sec);
        const Value::Number milli = ToInteger(ms);
        return m * msPerMinute + h * msPerHour + s * msPerSecond + milli;
    }

    // @0x1424254f0
    Value::Number Date::TimeClip(Value::Number t)
    {
        if (NumberUtil::IsNaNOrInfinity(t) || fabs(t) > 8.64e15)
            return NumberUtil::NaN();
        return t > 0 ? ::floor(t) : ::ceil(t);
    }

    // ---- Date component editing and string helpers ----

    // Three-letter day and month names (exe data), shared with the Date string formatting.
    extern const char* DateWeekDayNames[7];
    extern const char* DateMonthNames[12];

    // @0x142419ff0
    Value::Number Date::DateHolder::MakeDate() const
    {
        const Value::Number day = Date::MakeDay(Entries[Date_Year], Entries[Date_Month], Entries[Date_Day]);
        return Date::TimeClip(day * msPerDay + TimeInDay - TZA);
    }

    // @0x14241a190
    Value::Number Date::TimeHolder::MakeDate() const
    {
        const Value::Number time = Date::MakeTime(Entries[Time_Hour], Entries[Time_Minute], Entries[Time_Second], Entries[Time_Ms]);
        return Date::TimeClip(Day * msPerDay + time - TZA);
    }

    // @0x14241a080
    Value::Number Date::Parser::MakeDate(int localTZA) const
    {
        if (!Valid)
            return NumberUtil::NaN();
        if (HasTZA)
            localTZA = TZA;
        const Value::Number time = Date::MakeTime(Hour, Minute, Sec, 0);
        const Value::Number day = Date::MakeDay(Year, Month, Day);
        return Date::TimeClip(day * msPerDay + time - localTZA);
    }

    // @0x142427600
    void Date::applyDateArg(DateEntry arg, Value::Number value, Value::Number tza)
    {
        DateHolder h(TimeValue, tza);
        h.Entries[arg] = value;
        TimeValue = h.MakeDate();
    }

    // MS2-FUNCTIONAL: Value::Convert2NumberInline is an out-of-line call in the exe
    // @0x1424276e0
    void Date::applyDateArgs(Value& result, unsigned argc, const Value* const argv, DateEntry firstArg, Value::Number tza)
    {
        if (argc != 0)
        {
            DateHolder h(TimeValue, tza);
            const unsigned maxArgs = Date_Entry_Count - firstArg;
            if (argc > maxArgs)
                argc = maxArgs;
            for (unsigned i = 0; i < argc; ++i)
            {
                if (!argv[i].Convert2NumberInline(h.Entries[firstArg + i]))
                    return;
            }
            TimeValue = h.MakeDate();
        }
        result.SetNumber(TimeValue);
    }

    // MS2-FUNCTIONAL: the exe computes Day * msPerDay after the MakeTime call
    // @0x142427810
    void Date::applyTimeArg(TimeEntry arg, Value::Number value, Value::Number tza)
    {
        TimeHolder h(TimeValue, tza);
        h.Entries[arg] = value;
        TimeValue = h.MakeDate();
    }

    // MS2-FUNCTIONAL: Value::Convert2NumberInline is an out-of-line call in the exe
    // @0x142427900
    void Date::applyTimeArgs(Value& result, unsigned argc, const Value* const argv, TimeEntry firstArg, Value::Number tza)
    {
        if (argc != 0)
        {
            TimeHolder h(TimeValue, tza);
            const unsigned maxArgs = Time_Entry_Count - firstArg;
            if (argc > maxArgs)
                argc = maxArgs;
            for (unsigned i = 0; i < argc; ++i)
            {
                if (!argv[i].Convert2NumberInline(h.Entries[firstArg + i]))
                    return;
            }
            TimeValue = h.MakeDate();
        }
        result.SetNumber(TimeValue);
    }

    // MS2-FUNCTIONAL: Value::Convert2NumberInline is an out-of-line call in the exe
    // @0x142427f10
    Value::Number Date::decodeUTCArgs(unsigned argc, const Value* const argv, Value::Number tza)
    {
        // (year, month[, date[, hours[, minutes[, seconds[, ms]]]]]); two-digit years are 19xx.
        Value::Number year, month;
        if (!argv[0].Convert2NumberInline(year))
            return 0;
        if (static_cast<UInt32>(static_cast<SInt32>(year)) < 100)
            year += 1900;
        if (!argv[1].Convert2NumberInline(month))
            return 0;

        Value::Number date = 1, hours = 0, minutes = 0, seconds = 0, ms = 0;
        if (argc >= 3 && !argv[2].Convert2NumberInline(date))
            return 0;
        if (argc >= 4)
        {
            if (!argv[3].Convert2NumberInline(hours))
                return 0;
            hours = static_cast<SInt32>(hours);
        }
        if (argc >= 5)
        {
            if (!argv[4].Convert2NumberInline(minutes))
                return 0;
            minutes = static_cast<SInt32>(minutes);
        }
        if (argc >= 6)
        {
            if (!argv[5].Convert2NumberInline(seconds))
                return 0;
            seconds = static_cast<SInt32>(seconds);
        }
        if (argc >= 7)
        {
            if (!argv[6].Convert2NumberInline(ms))
                return 0;
            ms = static_cast<SInt32>(ms);
        }

        const Value::Number time = MakeTime(hours, minutes, seconds, ms);
        return TimeClip(MakeDay(year, month, date) * msPerDay + time - tza);
    }

    // MS2-FUNCTIONAL 0x142428e10: the day/month name tables are read through SF_EXE_DATA (RIP-relative; the exe indexes off __ImageBase, which the DLL cannot link to exe data: LNK2016)
    // @0x142428e10
    Date::Parser::StringType Date::Parser::interpretDateString(const char* pstr, SPInt length, int* index)
    {
        if (length == 2)
        {
            if (pstr[1] == 'M')
            {
                if (pstr[0] == 'A')
                    return String_AM;
                if (pstr[0] == 'P')
                    return String_PM;
            }
        }
        else if (length == 3)
        {
            if (memcmp(pstr, "GMT", 3) == 0)
                return String_GMT;
            if (memcmp(pstr, "UTC", 3) == 0)
                return String_UTC;
            for (int i = 0; i < 7; ++i)
            {
                if (memcmp(pstr, SF_EXE_DATA(DateWeekDayNames)[i], 3) == 0)
                {
                    *index = i;
                    return String_WeekDay;
                }
            }
            for (int i = 0; i < 12; ++i)
            {
                if (memcmp(pstr, SF_EXE_DATA(DateMonthNames)[i], 3) == 0)
                {
                    *index = i;
                    return String_Month;
                }
            }
        }
        return String_Invalid;
    }

    // MS2-FUNCTIONAL: MsgFormat::FormatD1 instances are out-of-line calls in the exe
    // @0x1424284c0
    UPInt Date::formatDateTimeString(char* buffer, UPInt bufferSize, Value::Number t, int tza,
                                     bool needDate, bool needTime, bool utc)
    {
        if (NumberUtil::IsNaN(t))
        {
            memcpy(buffer, "Invalid Date", 13);
            return 12;
        }

        const Value::Number local = utc ? t : t + tza;
        UPInt size = 0;
        DateHolder dh(local, 0);

        // "Www Mmm d "
        if (needDate)
        {
            const int weekDay = WeekDay(local);
            const int day = static_cast<int>(dh.Entries[Date_Day]);
            MsgFormat f(MsgFormat::Sink(StringDataPtr(buffer, bufferSize)));
            f.Parse("{0} {1} {2} ");
            f.FormatD1(SF_EXE_DATA(DateWeekDayNames)[weekDay]);
            f.FormatD1(SF_EXE_DATA(DateMonthNames)[static_cast<int>(dh.Entries[Date_Month])]);
            f.FormatD1(day);
            f.FinishFormatD();
            size = f.GetStrSize();
        }

        // "hh:mm:ss[ GMT+hhmm]"
        if (needTime)
        {
            TimeHolder th(local, 0);
            const char* fmt = "{0:02}:{1:02}:{2:02}";
            const int tzMinutes = tza / 60000;
            int tzValue = tzMinutes + (tzMinutes / 60) * 40;
            const char* gmt = "GMT+";
            if (!utc)
            {
                fmt = "{0:02}:{1:02}:{2:02} {3}{4:04}";
                if (tzValue < 0)
                {
                    tzValue = -tzValue;
                    gmt = "GMT-";
                }
            }
            const int sec = static_cast<int>(th.Entries[Time_Second]);
            const int min = static_cast<int>(th.Entries[Time_Minute]);
            const int hour = static_cast<int>(th.Entries[Time_Hour]);
            MsgFormat f(MsgFormat::Sink(StringDataPtr(buffer + size, bufferSize - size)));
            f.Parse(fmt);
            f.FormatD1(hour);
            f.FormatD1(min);
            f.FormatD1(sec);
            f.FormatD1(gmt);
            f.FormatD1(tzValue);
            f.FinishFormatD();
            size += f.GetStrSize();
        }

        // year
        if (needDate)
        {
            const int year = static_cast<int>(dh.Entries[Date_Year]);
            MsgFormat f(MsgFormat::Sink(StringDataPtr(buffer + size, bufferSize - size)));
            f.Parse(needTime ? " {0}" : "{0}");
            f.FormatD1(year);
            f.FinishFormatD();
            size += f.GetStrSize();
        }

        if (needTime && utc)
        {
            memcpy(buffer + size, " UTC", 5);
            size += 4;
        }
        return size;
    }

    // ---- Date property getters (UTC forms read TimeValue, the local ones add LocalTZA) ----

    // @0x142427c60
    void Date::dateUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : DateFromTime(t);
    }

    // @0x1424289a0
    void Date::fullYearGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = YearFromTime(t + LocalTZA);
    }

    // @0x142428a20
    void Date::fullYearUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : YearFromTime(t);
    }

    // @0x142429660
    void Date::millisecondsUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : MsFromTime(t);
    }

    // MS2-FUNCTIONAL: int->double conversion uses cvtsi2sd instead of movd+cvtdq2pd
    // @0x1424298a0
    void Date::monthUTCGet(Value::Number& result)
    {
        Value::Number t = TimeValue;
        if (!NumberUtil::IsNaN(t))
            t = MonthFromTime(t);
        result = t;
    }

    // MS2-FUNCTIONAL: same logic; register allocation around the temporary String differs
    // @0x142429af0
    void GlobalObjectCPP::parseFloat(Value::Number& result, const ASString& str)
    {
        const char* s = str.ToCStr();
        UInt32 len = str.GetSize();
        UInt32 pos = (UInt32)UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(String(s)), s, len);
        s += pos;
        if (strncmp(s, "0x", 2) == 0 || strncmp(s, "0X", 2) == 0)
        {
            result = 0;
            return;
        }
        result = NumberUtil::StringToDouble(s, len - pos, &pos);
    }
}} // namespace Instances::fl

namespace Classes { namespace fl
{
    // @0x142427200
    void Date::UTC(Value& result, unsigned argc, const Value* argv)
    {
        result.SetNumber(Instances::fl::Date::decodeUTCArgs(argc, argv, 0));
    }

    // ---- Math ----

    // @0x1424274f0
    void Math::abs(Value::Number& result, Value::Number v)
    {
        if (NumberUtil::IsNEGATIVE_ZERO(v))
        {
            result = 0.0;
            return;
        }
        result = fabs(v);
    }

    // @0x142427540
    void Math::acos(Value::Number& result, Value::Number v)
    {
        result = ::acos(v);
    }

    // @0x142427a60
    void Math::asin(Value::Number& result, Value::Number v)
    {
        result = ::asin(v);
    }

    // @0x142427b90
    void Math::atan(Value::Number& result, Value::Number v)
    {
        result = ::atan(v);
    }

    // MS2-FUNCTIONAL: infinity tests compiled as integer bit compares in a different branch order
    // @0x142427a80
    void Math::atan2(Value::Number& result, Value::Number y, Value::Number x)
    {
        // atan2 of two infinities is the quadrant diagonal.
        if (NumberUtil::IsPOSITIVE_INFINITY(y))
        {
            if (NumberUtil::IsPOSITIVE_INFINITY(x))
                result = PI * 0.25;
            else if (NumberUtil::IsNEGATIVE_INFINITY(x))
                result = PI * 0.75;
            else
                result = PI * 0.5;
            return;
        }
        if (NumberUtil::IsNEGATIVE_INFINITY(y))
        {
            if (NumberUtil::IsPOSITIVE_INFINITY(x))
                result = PI * -0.25;
            else if (NumberUtil::IsNEGATIVE_INFINITY(x))
                result = PI * -0.75;
            else
                result = PI * -0.5;
            return;
        }
        result = ::atan2(y, x);
    }

    // @0x142427bb0
    void Math::ceil(Value::Number& result, Value::Number v)
    {
        result = ::ceil(v);
    }

    // @0x142427c10
    void Math::cos(Value::Number& result, Value::Number v)
    {
        result = ::cos(v);
    }

    // @0x142428470
    void Math::exp(Value::Number& result, Value::Number v)
    {
        result = ::exp(v);
    }

    // @0x1424284a0
    void Math::floor(Value::Number& result, Value::Number v)
    {
        result = ::floor(v);
    }

    // @0x1424294d0
    void Math::log(Value::Number& result, Value::Number v)
    {
        result = ::log(v);
    }

    // MS2-FUNCTIONAL: comparison-loop register allocation differs
    // @0x1424294f0
    void Math::max(Value& result, unsigned argc, const Value* argv)
    {
        if (argc == 0)
        {
            result.SetNumber(NumberUtil::NEGATIVE_INFINITY());
            return;
        }
        result.Assign(argv[0]);
        for (unsigned i = 1; i < argc; ++i)
        {
            Boolean3 cmp;
            if (!AbstractLessThan(cmp, argv[i], result))
                return;
            if (cmp == undefined3)
            {
                result.SetNumber(NumberUtil::NaN());
                return;
            }
            if (cmp == false3)
                result.Assign(argv[i]);
        }
        result.ToNumberValue();
    }

    // MS2-FUNCTIONAL: comparison-loop register allocation differs
    // @0x1424296e0
    void Math::min(Value& result, unsigned argc, const Value* argv)
    {
        if (argc == 0)
        {
            result.SetNumber(NumberUtil::POSITIVE_INFINITY());
            return;
        }
        result.Assign(argv[0]);
        for (unsigned i = 1; i < argc; ++i)
        {
            Boolean3 cmp;
            if (!AbstractLessThan(cmp, result, argv[i]))
                return;
            if (cmp == undefined3)
            {
                result.SetNumber(NumberUtil::NaN());
                return;
            }
            if (cmp == false3)
                result.Assign(argv[i]);
        }
        result.ToNumberValue();
    }

    // @0x142429d40
    void Math::pow(Value::Number& result, Value::Number x, Value::Number y)
    {
        if (y == 0.0)
        {
            result = 1.0;
            return;
        }
        if ((x == 1.0 || x == -1.0) && NumberUtil::IsNaNOrInfinity(y))
        {
            result = NumberUtil::NaN();
            return;
        }
        result = ::pow(x, y);
    }

    // @0x142429fb0
    void Math::random(Value::Number& result)
    {
        result = Alg::Random::NextRandom() / 4294967295.0;
    }

    // @0x142429fe0
    void Math::round(Value::Number& result, Value::Number v)
    {
        if (NumberUtil::IsNaNOrInfinity(v))
        {
            result = v;
            return;
        }
        result = ::floor(v + 0.5);
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

bool FUN_1425e4ad0(const char* pstr, unsigned len, Scaleform::String* presult);   // URI decode; false on a malformed escape
void FUN_1425e3750(const char* pstr, unsigned len, Scaleform::String* presult);   // encodeURI escaping
void FUN_1425e37c0(const char* pstr, unsigned len, Scaleform::String* presult);   // encodeURIComponent escaping

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // MS2-FUNCTIONAL: same code; the 0x7fffffffffffffff size-mask constant is loaded at a different point
    // @0x142427cf0
    void GlobalObjectCPP::decodeURI(ASString& result, const ASString& uri)
    {
        String out;
        if (!FUN_1425e4ad0(uri.ToCStr(), uri.GetSize(), &out))
        {
            GetVM().ThrowURIError(VM::Error(VM::eInvalidURIError, GetVM(), "decodeURI"));
            return;
        }
        result = GetVM().GetStringManager().CreateString(out);
    }

    // MS2-FUNCTIONAL: same code; the 0x7fffffffffffffff size-mask constant is loaded at a different point
    // @0x142427e00
    void GlobalObjectCPP::decodeURIComponent(ASString& result, const ASString& uri)
    {
        String out;
        if (!FUN_1425e4ad0(uri.ToCStr(), uri.GetSize(), &out))
        {
            GetVM().ThrowURIError(VM::Error(VM::eInvalidURIError, GetVM(), "decodeURI"));
            return;
        }
        result = GetVM().GetStringManager().CreateString(out);
    }

    // MS2-FUNCTIONAL: same code; the 0x7fffffffffffffff size-mask constant is loaded at a different point
    // @0x142428140
    void GlobalObjectCPP::encodeURI(ASString& result, const ASString& uri)
    {
        String out;
        FUN_1425e3750(uri.ToCStr(), uri.GetSize(), &out);
        result = GetVM().GetStringManager().CreateString(out);
    }

    // MS2-FUNCTIONAL: same code; the 0x7fffffffffffffff size-mask constant is loaded at a different point
    // @0x142428210
    void GlobalObjectCPP::encodeURIComponent(ASString& result, const ASString& uri)
    {
        String out;
        FUN_1425e37c0(uri.ToCStr(), uri.GetSize(), &out);
        result = GetVM().GetStringManager().CreateString(out);
    }

    // @0x142428a80
    void GlobalObjectCPP::getDefinitionByName(Value& result, const ASString& name)
    {
        Class* c = GetVM().GetClass(StringDataPtr(name.ToCStr()));
        if (c)
            result.Assign(c);
        else
            result.SetUndefined();
    }

    // @0x142428b70
    void GlobalObjectCPP::getQualifiedClassName(ASString& result, const Value& v)
    {
        const InstanceTraits::Traits& itr = GetVM().GetInstanceTraits(v);
        result = itr.GetQualifiedName();
    }

    // @0x142428be0
    void GlobalObjectCPP::getQualifiedSuperclassName(Value& result, const Value& v)
    {
        const InstanceTraits::Traits& itr = GetVM().GetInstanceTraits(v);
        if (itr.GetParent())
            result.Assign(itr.GetParent()->GetQualifiedName());
        else
            result.SetNull();
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances
{
    // @0x1424291d0
    void ThunkFunction::length(Value& result, unsigned, const Value*)
    {
        const Value f(Function);
        const ThunkInfo& ti = f.AsThunk();
        unsigned n = ti.GetMaxArgNum();
        if (n == 0x3ff)
            n = ti.GetMinArgNum();
        result.SetUInt32(n);
    }
} // namespace Instances

namespace Classes { namespace fl
{
    // @0x142428b20
    void Error::getErrorMessage(ASString& result, SInt32)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowError(VM::Error(VM::eNotImplementedError, vm, "class_::Error::getErrorMessage()"));
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

void FUN_1424e6f90(const Scaleform::GFx::AS3::Class* cls, Scaleform::GFx::AS3::Object& obj);  // Class::AddConstructor: obj.constructor = cls
void FUN_142511ac0(const Scaleform::GFx::AS3::Class* cls, Scaleform::GFx::AS3::Object& obj);  // adds the instance traits' vtable methods to the prototype
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e3a0[7];   // Classes::fl::Object prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e7f0[2];   // Classes::fl::Boolean prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d6e8[1];   // Classes::fl::Error prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e690[2];   // Classes::fl::Namespace prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d850[6];   // Classes::fl::Number prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d6a0[1];   // Classes::fl::QName prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2d128[1];   // Classes::fl::RegExp prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e8e0[3];   // Classes::fl::XML prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d650[2];   // Classes::fl::XMLList prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e5a0[6];   // Classes::fl::int_ prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e700[6];   // Classes::fl::uint prototype methods

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl
{
    // The prototype methods: name -> thunk, not enumerable.
    template <unsigned N>
    static SF_INLINE void AddDynamicFuncs(AS3::Object& obj, const ThunkInfo (&f)[N])
    {
        for (unsigned i = 0; i < N; ++i)
        {
            const ThunkInfo& ti = f[i];
            obj.AddDynamicSlotValuePair(obj.GetVM().GetStringManager().CreateConstString(ti.Name), Value(ti),
                                        SlotInfo::aReadOnly);
        }
    }

    // @0x142417f60
    void Object::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e3a0);
        FUN_1424e6f90(this, obj);
    }

    // @0x142417a30
    void Boolean::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e7f0);
        FUN_1424e6f90(this, obj);
    }

    // @0x142417b40
    void Error::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d6e8);
        FUN_1424e6f90(this, obj);
    }

    // @0x142417d40
    void Namespace::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e690);
        FUN_1424e6f90(this, obj);
    }

    // @0x142417e50
    void Number::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d850);
        FUN_1424e6f90(this, obj);
    }

    // @0x142418070
    void QName::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d6a0);
        FUN_1424e6f90(this, obj);
    }

    // @0x142418160
    void RegExp::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        FUN_142511ac0(this, obj);
        AddDynamicFuncs(obj, DAT_143a2d128);
        // (no constructor slot: RegExp's prototype keeps its own)
    }

    // @0x142418390
    void XML::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        FUN_142511ac0(this, obj);
        AddDynamicFuncs(obj, DAT_14313e8e0);
        FUN_1424e6f90(this, obj);
    }

    // @0x1424184b0
    void XMLList::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        FUN_142511ac0(this, obj);
        AddDynamicFuncs(obj, DAT_14313d650);
        FUN_1424e6f90(this, obj);
    }

    // @0x1424185d0
    void int_::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e5a0);
        FUN_1424e6f90(this, obj);
    }

    // @0x1424186e0
    void uint::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e700);
        FUN_1424e6f90(this, obj);
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// The out-of-line copies of the inline Value setters the exe keeps in this range.
extern void (Value::* const ValueSetBool)(bool);
void (Value::* const ValueSetBool)(bool) = &Value::SetBool;
extern void (Value::* const ValueSetNull)();
void (Value::* const ValueSetNull)() = &Value::SetNull;
extern void (Value::* const ValueSetSInt32)(SInt32);
void (Value::* const ValueSetSInt32)(SInt32) = &Value::SetSInt32;
extern bool (Value::* const ValueIsCallable)() const;
bool (Value::* const ValueIsCallable)() const = &Value::IsCallable;
extern bool (* const pIsXMLObject)(const Value&);
bool (* const pIsXMLObject)(const Value&) = &IsXMLObject;
extern bool (* const pIsXMLListObject)(const Value&);
bool (* const pIsXMLListObject)(const Value&) = &IsXMLListObject;
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
namespace InstanceTraits
{
    // MS2-FUNCTIONAL: the exe inlines the Catch constructor
    // @0x14241be30
    void fl::Catch::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Catch(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Object constructor
    // @0x14241bfd0
    void fl::Object::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Object(t));
    }

    // An interface makes plain objects.
    // MS2-FUNCTIONAL: the exe inlines the Object constructor
    // @0x14241c060
    void Interface::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Object(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Object constructor
    // @0x14241aaf0
    Pickable<Instances::fl::Object> Interface::MakeInstance(Interface& t)
    {
        return Pickable<Instances::fl::Object>(new(t.Alloc()) Instances::fl::Object(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Object constructor
    // @0x14241ac70
    Pickable<Instances::fl::Object> fl::Object::MakeInstance(Object& t)
    {
        return Pickable<Instances::fl::Object>(new(t.Alloc()) Instances::fl::Object(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Array constructor
    // @0x14241a500
    Pickable<Instances::fl::Array> fl::Array::MakeInstance(Array& t)
    {
        return Pickable<Instances::fl::Array>(new(t.Alloc()) Instances::fl::Array(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Array constructor
    // @0x14241bd80
    void fl::Array::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Array(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Date constructor
    // @0x14241a620
    Pickable<Instances::fl::Date> fl::Date::MakeInstance(Date& t)
    {
        return Pickable<Instances::fl::Date>(new(t.Alloc()) Instances::fl::Date(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Date constructor
    // @0x14241beb0
    void fl::Date::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Date(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the Error constructor
    // @0x14241a6a0
    __declspec(noinline) Pickable<Instances::fl::Error> fl::Error::MakeInstance(Error& t)
    {
        return Pickable<Instances::fl::Error>(new(t.Alloc()) Instances::fl::Error(t));
    }

    // @0x14241bf20
    void fl::Error::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Error&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the RegExp constructor
    // @0x14241ad90
    Pickable<Instances::fl::RegExp> fl::RegExp::MakeInstance(RegExp& t)
    {
        return Pickable<Instances::fl::RegExp>(new(t.Alloc()) Instances::fl::RegExp(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the RegExp constructor
    // @0x14241c160
    void fl::RegExp::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::RegExp(t));
    }

    // The traits of a class prototype object: plain object traits whose constructor is the class itself.
    class Prototype : public fl::Object
    {
    public:
        Prototype(VM& vm, const ClassInfo& ci, Class& c);
    };
}

namespace Classes { namespace fl
{
    // MS2-FUNCTIONAL: the exe inlines the Array constructor
    // @0x14241c350
    Pickable<AS3::Object> Array::MakePrototype() const
    {
        InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(GetClassTraits().GetInstanceTraits());
        return itr.MakeInstance(itr);
    }

    // A Date prototype gets its own traits so its constructor is Date.
    // MS2-FUNCTIONAL: the exe inlines the Date constructor
    // @0x14241c400
    Pickable<AS3::Object> Date::MakePrototype() const
    {
        SPtr<InstanceTraits::Prototype> prototype = MakePickable(new(GetVM().GetMemoryHeap()) InstanceTraits::Prototype(GetVM(), AS3::fl::DateCI, const_cast<Date&>(*this)));
        InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        return Pickable<AS3::Object>(new(itr.Alloc()) Instances::fl::Date(*prototype));
    }

    // @0x14241c4d0
    Pickable<AS3::Object> Error::MakePrototype() const
    {
        InstanceTraits::fl::Error& itr = static_cast<InstanceTraits::fl::Error&>(GetClassTraits().GetInstanceTraits());
        return itr.MakeInstance(itr);
    }
}}
}}} // namespace Scaleform::GFx::AS3

// The instance traits of the four function kinds. Each names an anonymous function "Function-<hex id>".
namespace Scaleform { namespace GFx { namespace AS3 {
namespace InstanceTraits
{
    // Traits of AS3 (ABC) function closures.
    class Function : public CTraits
    {
    public:
        ASString GetFunctionName(const Value& _this) const;
        SInt32 GetMethodInfoInd() const { return MethodInfoInd; }

    public:
        SInt32 MethodInfoInd;   // +0xe8
    };

    // Traits of unbound ABC methods (a method index value).
    class MethodInd : public CTraits
    {
    public:
        ASString GetMethodIndName(const Value& _this) const;
    };

    // Traits of native thunks.
    class Thunk : public CTraits
    {
    public:
        ASString GetThunkName(const Value& _this) const;
    };

    // Traits of native thunks wrapped in a function object.
    class ThunkFunction : public CTraits
    {
    public:
        ASString GetThunkName(const Value& _this) const;
    };

    // @0x142415b00
    ASString Function::GetFunctionName(const Value& _this) const
    {
        const Function& itr = static_cast<const Function&>(_this.GetObject()->GetTraits());
        LongFormatter f((unsigned long)itr.GetMethodInfoInd());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x142415ef0
    ASString MethodInd::GetMethodIndName(const Value& _this) const
    {
        LongFormatter f((unsigned long)_this.GetMethodInd());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x142417100
    ASString Thunk::GetThunkName(const Value& _this) const
    {
        LongFormatter f((unsigned long)(UPInt)&_this.AsThunk());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x1424171d0
    ASString ThunkFunction::GetThunkName(const Value& _this) const
    {
        LongFormatter f((unsigned long)(UPInt)&_this.AsThunkFunction().GetThunk());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }
}
}}} // namespace Scaleform::GFx::AS3

// MS2-FUNCTIONAL: the exe inlines the Catch constructor
// @0x14241a5b0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch>
Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(Catch& t)
{
    return Pickable<Instances::fl::Catch>(new(t.Alloc()) Instances::fl::Catch(t));
}

namespace Scaleform { namespace GFx { namespace AS3 {
typedef HashSetBase<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc,
                    NamespaceInstanceFactory::NamespaceHashFunc, AllocatorLH<Instances::Namespace*, Stat_Default_Mem>,
                    HashsetEntry<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc> >
    NamespaceInstanceSetBase;

// MS2-FUNCTIONAL: the exe inlines the Namespace constructor
// @0x14241ab60
Pickable<Instances::Namespace> InstanceTraits::fl::Namespace::MakeInstance(Abc::NamespaceKind kind, const ASString& uri,
                                                                           const Value& prefix)
{
    return Pickable<Instances::Namespace>(SF_HEAP_AUTO_NEW(this) Instances::Namespace(GetVM(), InstanceFactory, kind, uri, prefix));
}

// @0x14241ba70
Pickable<Instances::Namespace> InstanceTraits::fl::Namespace::MakeInternedInstance(Abc::NamespaceKind kind,
                                                                                   const ASString& uri,
                                                                                   const Value& prefix)
{
    return InstanceFactory->MakeNamespace(kind, uri, prefix);
}

// MS2-FUNCTIONAL: the exe keeps the lookup key in other registers
// @0x14241baa0
Pickable<Instances::Namespace> NamespaceInstanceFactory::MakeNamespace(Abc::NamespaceKind kind, const ASString& uri,
                                                                       const Value& prefix)
{
    Instances::Namespace** pns = NamespaceSet.GetAlt(Key(kind, uri));
    if (pns)
        return Pickable<Instances::Namespace>(*pns, PickValue);

    Pickable<Instances::Namespace> ns = pNamespaceInstanceTraits->MakeInstance(kind, uri, prefix);
    NamespaceSet.Add(ns.GetPtr());
    return ns;
}
}}}
// The namespace set's out-of-line rehash.
template void Scaleform::GFx::AS3::NamespaceInstanceSetBase::setRawCapacity(void*, Scaleform::UPInt);
// Namespace enumerates two properties: 1 = uri, 2 = prefix.
// Namespace::GetNextPropIndex.
// @0x1424161e0
Scaleform::GFx::AS3::GlobalSlotIndex*
FUN_1424161e0(const Scaleform::GFx::AS3::Instances::Namespace*, Scaleform::GFx::AS3::GlobalSlotIndex* result,
              Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    if (ind.Get() <= 1)
    {
        ind = Scaleform::GFx::AS3::GlobalSlotIndex(ind.Get() + 1);
        *result = ind;
        return result;
    }
    *result = Scaleform::GFx::AS3::GlobalSlotIndex(0);
    return result;
}
// Namespace::GetNextPropertyName.
// @0x1424162b0
void FUN_1424162b0(const Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& name,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    Scaleform::GFx::AS3::VM& vm = self->GetVM();
    switch (ind.Get())
    {
    case 1: name.Assign(vm.GetStringManager().CreateConstString("uri")); break;
    case 2: name.Assign(vm.GetStringManager().CreateConstString("prefix")); break;
    }
}
// Namespace::GetNextPropertyValue.
// @0x142416600
void FUN_142416600(Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& value,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    switch (ind.Get())
    {
    case 1: value.Assign(self->GetUri()); break;
    case 2: value.Assign(self->GetPrefix()); break;
    }
}
// Namespace::SetUri.
// @0x142423bd0
void FUN_142423bd0(Scaleform::GFx::AS3::Instances::Namespace* self, const Scaleform::GFx::ASString& uri)
{ const_cast<Scaleform::GFx::ASString&>(self->GetUri()) = uri; }
// MultinameHash<ClassTraits::Traits*>::Get: the class traits cached under {name, ns}.
// MS2-FUNCTIONAL: the exe builds the temporary key in another home slot
// @0x142414ac0
Scaleform::GFx::AS3::ClassTraits::Traits**
FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name,
              const Scaleform::GFx::AS3::Instances::Namespace& ns)
{ return self->Entries.Get(Scaleform::GFx::AS3::TClassTraitsCache::Key(name, &ns)); }
// Multiname::IsAnyNamespace: a qualified name with no namespace.
// @0x1424198b0
bool FUN_1424198b0(const Scaleform::GFx::AS3::Multiname& mn)
{
    return (mn.Kind & 3) <= 1 && mn.Obj.GetPtr() == NULL;
}

// ---- global functions ----
void* FUN_1424d7e50(void* pmem, const Scaleform::GFx::AS3::Value& function, unsigned delay, bool timeout);   // IntervalTimer ctor
void  FUN_1425264b0(void* ptimer, unsigned argc, const Scaleform::GFx::AS3::Value* argv);                   // IntervalTimer: the extra call arguments
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl
{
    // A repeating interval timer registered with the movie; returns its id.
    // @0x14242a0c0
    void GlobalObjectCPP::setInterval(Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 2)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, GetVM(), "GlobalObjectCPP::setInterval", 2, 1023, argc));
            return;
        }
        UInt32 delay;
        if (!argv[1].Convert2UInt32(delay))
            return;
        void* pmem = GetVM().GetMemoryHeap()->Alloc(0x70);
        ASIntervalTimerIntf* ptimer = pmem ? (ASIntervalTimerIntf*)FUN_1424d7e50(pmem, argv[0], delay, false) : NULL;
        if (argc > 2)
            FUN_1425264b0(ptimer, argc - 2, argv + 2);
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        result.Assign(Value(UInt32(proot->AddIntervalTimer(ptimer))));
        ptimer->Start(proot);
        ptimer->Release();
    }

    // Milliseconds since the movie started.
    // @0x142428d70
    void GlobalObjectCPP::getTimer(SInt32& result)
    {
        result = (SInt32)AsMovieSlots(static_cast<ASVM&>(GetVM()).GetMovieImpl())->GetASTimerMs();
    }
}}}}} // namespace Scaleform::GFx::AS3::Instances::fl
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances
{
    // The AS3 Function.length: the declared parameter count.
    // @0x1424292a0
    void FunctionBase::lengthGet(UInt32& result)
    {
        result = GetMaxParamNum();
    }
}}}} // namespace Scaleform::GFx::AS3::Instances

// The array element types of the Array sort helpers and of the XML parser's node-kind stack.
namespace Scaleform {
template <class F, class S> struct Pair { F First; S Second; };
namespace GFx { namespace AS3 {
namespace Impl { template <class A, class B, class C> struct Triple { A First; B Second; C Third; }; }
class XMLParser { public: enum Kind { kNone }; };
namespace Instances { namespace fl { class XMLAttr : public XML {}; } }
}}} // namespace Scaleform::GFx::AS3

// The out-of-line ArrayDataBase::Reserve instances of this range.
template void Scaleform::ArrayDataBase<Scaleform::UInt32, Scaleform::AllocatorDH<Scaleform::UInt32, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Pair<const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::Pair<const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<double, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<double, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value, Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::XMLParser::Kind, Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::XMLParser::Kind, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);


// The out-of-line array resize and insert/remove instances of this range.
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveAt(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveAt(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy> >::InsertAt(Scaleform::UPInt, const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>&);
template void Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveMultipleAt(Scaleform::UPInt, Scaleform::UPInt);

// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424133c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413510
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413530
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413550
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424136c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424137a0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BD@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413910
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a30
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a50
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0N@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413bc0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0O@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413d70
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0P@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413f20
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BL@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414040
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414060
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414080
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140e0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CB@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414100
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414120
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414140
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414160
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414180
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CH@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CI@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141e0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414200
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$07VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414220
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414240
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414260
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414280
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142a0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142c0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142e0
// MS2-PIN: ?Func@?$ThunkFunc2@VString@fl@Classes@AS3@GFx@Scaleform@@$00VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414300
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$03VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414320
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414340
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414360
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414440
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BJ@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414520
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414540
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CB@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414560
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146d0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414710
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414730
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414810
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424148f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CE@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414910
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414a80
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414aa0
// MS2-PIN: ?SetBool@Value@AS3@GFx@Scaleform@@QEAAX_N@Z 0x142421710
// MS2-PIN: ?SetNull@Value@AS3@GFx@Scaleform@@QEAAXXZ 0x142421ed0
// MS2-PIN: ?SetSInt32@Value@AS3@GFx@Scaleform@@QEAAXJ@Z 0x142423a90
// MS2-PIN: ?Reserve@?$ArrayDataBase@KU?$AllocatorDH@K$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14241f560
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@U?$AllocatorDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14241f600
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@K@Impl@AS3@GFx@Scaleform@@U?$AllocatorDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@K@Impl@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241f6a0
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@K@Impl@AS3@GFx@Scaleform@@U?$AllocatorDH@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@K@Impl@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241f740
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f7e0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f880
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXMLAttr@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXMLAttr@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f920
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f9c0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fa60
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fb00
// MS2-PIN: ?Reserve@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fc40
// MS2-PIN: ?Reserve@?$ArrayDataBase@W4Kind@XMLParser@AS3@GFx@Scaleform@@U?$AllocatorDH_POD@W4Kind@XMLParser@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241fce0
// MS2-PIN: ?IsCallable@Value@AS3@GFx@Scaleform@@QEBA_NXZ 0x142419940
// MS2-PIN: ?IsXMLObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z 0x142419ca0
// MS2-PIN: ?IsXMLListObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z 0x142419cd0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241ff20
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241ffc0
// MS2-FUNCTIONAL ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z: the exe calls DestructArray out of line; ours inlines it
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142420100
// MS2-FUNCTIONAL ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z: the exe calls DestructArray out of line; ours inlines it
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142420060
// MS2-FUNCTIONAL ?Resize@?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line; ours inlines it
// MS2-PIN: ?Resize@?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14241fd80
// MS2-FUNCTIONAL ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line for Clear; ours inlines it
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14241e8b0
// MS2-FUNCTIONAL ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line for Clear; ours inlines it
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14241e940
// MS2-FUNCTIONAL ?InsertAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@@Z: the exe calls ResizeNoConstruct out of line; ours inlines it
// MS2-PIN: ?InsertAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@@Z 0x1424190e0
// MS2-PIN: ?RemoveMultipleAt@?$ArrayBase@U?$ArrayDataDH@VValue@AS3@GFx@Scaleform@@U?$AllocatorDH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K0@Z 0x14241ebb0
// MS2-FUNCTIONAL ?setRawCapacity@?$HashSetBase@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@U67345@U?$AllocatorLH@PEAVNamespace@Instances@AS3@GFx@Scaleform@@$01@5@V?$HashsetEntry@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@@5@@Scaleform@@AEAAXPEAX_K@Z: the exe keeps the table in another register
// MS2-PIN: ?setRawCapacity@?$HashSetBase@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@U67345@U?$AllocatorLH@PEAVNamespace@Instances@AS3@GFx@Scaleform@@$01@5@V?$HashsetEntry@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@@5@@Scaleform@@AEAAXPEAX_K@Z 0x14242a240
