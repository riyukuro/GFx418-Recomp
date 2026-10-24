// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 runtime. Our own source,
// written from the exe.
// MS2-UNIT: sfr_as3_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423f5770-0x1423ff040 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#undef GetObject

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    static const Value::Number msPerSecond = 1000.0;
    static const Value::Number msPerMinute = 60000.0;
    static const Value::Number msPerHour   = 3600000.0;
    static const Value::Number msPerDay    = 86400000.0;

    // The exe inlines these time components (out-of-line copies of Date::HourFromTime etc. live in sfr_as3_04).
    static SF_INLINE Value::Number hourFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerHour), 24.0);
        if (r < 0)
            r += 24.0;
        return r;
    }

    static SF_INLINE Value::Number minFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerMinute), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    static SF_INLINE Value::Number secFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerSecond), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    static SF_INLINE Value::Number msFromTime(Value::Number t)
    {
        Value::Number r = fmod(t, msPerSecond);
        if (r < 0)
            r += msPerSecond;
        return r;
    }

    static SF_INLINE SInt32 weekDay(Value::Number t)
    {
        SInt32 r = static_cast<SInt32>(fmod(::floor(t / msPerDay) + 4.0, 7.0));
        return r < 0 ? r + 7 : r;
    }

    static SF_INLINE Value::Number timeClip(Value::Number t)
    {
        if (NumberUtil::IsNaNOrInfinity(t) || fabs(t) > 8.64e15)
            return NumberUtil::NaN();
        return t > 0 ? ::floor(t) : ::ceil(t);
    }

    // ---- Date getters: NaN stays NaN; the local forms add LocalTZA ----

    // @0x1423fa190
    void Date::AS3getDate(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = DateFromTime(t + LocalTZA);
    }

    // @0x1423fa200
    void Date::AS3getDay(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = weekDay(t + LocalTZA);
    }

    // @0x1423fa2a0
    void Date::AS3getFullYear(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = YearFromTime(t + LocalTZA);
    }

    // @0x1423fa310
    void Date::AS3getHours(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = hourFromTime(t + LocalTZA);
    }

    // @0x1423fa3a0
    void Date::AS3getMilliseconds(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = msFromTime(t + LocalTZA);
    }

    // @0x1423fa420
    void Date::AS3getMinutes(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = minFromTime(t + LocalTZA);
    }

    // @0x1423fa4b0
    void Date::AS3getMonth(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = MonthFromTime(t + LocalTZA);
    }

    // @0x1423fa520
    void Date::AS3getSeconds(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = secFromTime(t + LocalTZA);
    }

    // @0x1423fa5b0
    void Date::AS3getTime(Value::Number& result)
    {
        result = TimeValue;
    }

    // @0x1423fa5c0
    void Date::AS3getTimezoneOffset(Value::Number& result)
    {
        Value::Number t = TimeValue;
        if (!NumberUtil::IsNaN(t))
            t = (t - (t + LocalTZA)) / msPerMinute;
        result = t;
    }

    // @0x1423fa620
    void Date::AS3getUTCDate(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : DateFromTime(t);
    }

    // @0x1423fa680
    void Date::AS3getUTCDay(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : weekDay(t);
    }

    // @0x1423fa700
    void Date::AS3getUTCFullYear(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : YearFromTime(t);
    }

    // @0x1423fa750
    void Date::AS3getUTCHours(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : hourFromTime(t);
    }

    // @0x1423fa7d0
    void Date::AS3getUTCMilliseconds(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : msFromTime(t);
    }

    // @0x1423fa840
    void Date::AS3getUTCMinutes(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : minFromTime(t);
    }

    // @0x1423fa8c0
    void Date::AS3getUTCMonth(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : MonthFromTime(t);
    }

    // @0x1423fa920
    void Date::AS3getUTCSeconds(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : secFromTime(t);
    }

    // ---- Date setters (local time: the edits are made at LocalTZA) ----

    // @0x1423fe350
    void Date::AS3setDate(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Day, LocalTZA);
    }

    // @0x1423fe380
    void Date::AS3setFullYear(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Year, LocalTZA);
    }

    // @0x1423fe3b0
    void Date::AS3setHours(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Hour, LocalTZA);
    }

    // @0x1423fe590
    void Date::AS3setMilliseconds(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Ms, LocalTZA);
    }

    // @0x1423fe5c0
    void Date::AS3setMinutes(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Minute, LocalTZA);
    }

    // @0x1423fe5f0
    void Date::AS3setMonth(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Month, LocalTZA);
    }

    // @0x1423fea90
    void Date::AS3setSeconds(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Second, LocalTZA);
    }

    // @0x1423fefc0
    void Date::AS3setTime(Value::Number& result, Value::Number t)
    {
        TimeValue = timeClip(t);
        result = TimeValue;
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

// VM::GetValueTraits: the traits of a value (0x14250ffc0).
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);

// HashSetBase<HashNode<UPInt, Value>>::GetAlt<UPInt>, out of line in the exe; returns the node (key, then value).
const Scaleform::HashNode<Scaleform::UPInt, Scaleform::GFx::AS3::Value, Scaleform::FixedSizeHash<Scaleform::UPInt> >*
FUN_1423e87e0(const void* hash, const Scaleform::UPInt* key);

namespace Scaleform { namespace GFx { namespace AS3 {

// The exe inlines SparseArray::At and PushBack into the Array natives (out-of-line copies in sfr_as3_03/04).
static SF_INLINE const Value& saAt(const SparseArray& sa, UPInt ind)
{
    if (ind < sa.ValueA.GetSize())
        return sa.ValueA[ind];
    if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
    {
        const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = FUN_1423e87e0(&sa.ValueH, &ind);
        const Value* v = p ? &p->Second : 0;
        if (v)
            return *v;
    }
    return sa.DefaultValue;
}

static SF_INLINE void saPushBack(SparseArray& sa, const Value& v)
{
    if (sa.Length == sa.ValueA.GetSize())
        sa.ValueA.PushBack(v);
    else
    {
        sa.ValueHHighInd = sa.Length;
        sa.ValueH.Set(sa.ValueHHighInd, v);
    }
    ++sa.Length;
}

namespace Instances { namespace fl
{
    // ---- Array natives ----

    // MS2-FUNCTIONAL: the exe inlines the Array constructor
    // @0x1423f7f50
    void Array::AS3concat(Value& result, unsigned argc, const Value* argv)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        Array* arr = new(itr.Alloc()) Array(itr);
        result.Pick(arr);
        if (arr != this)
            arr->SA.Assign(SA);

        const Traits& tr = FUN_14250ffc0(GetVM(), argv[0]);
        if (argc == 1 && tr.GetTraitsType() == Traits_Array && tr.IsInstanceTraits())
        {
            const SparseArray& other = static_cast<Array*>(argv[0].GetObject())->SA;
            arr->SA.Append(other, 0, other.GetSize());
        }
        else
            arr->SA.Append(argc, argv);
    }

    // Calls callback(element, index, this) on thisObject (callback itself when that is null) for every element;
    // stops when callback is not callable or throws.

    // The result is always false: the exe never stores true.
    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423f8f60
    void Array::AS3every(bool& result, const Value& callback, const Value& thisObject)
    {
        if (!callback.IsNullOrUndefined())
        {
            Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
            for (UPInt i = 0; i < SA.GetSize(); ++i)
            {
                Value argv[3] = {saAt(SA, i), Value(static_cast<UInt32>(i)), Value(this)};
                if (!callback.IsCallable())
                    break;
                Value r;
                GetVM().ExecuteInternalUnsafe(callback, _this, r, 3, argv, false);
                if (GetVM().IsException())
                    break;
                if (!r.IsBool() || !r.AsBool())
                    break;
            }
        }
        result = false;
    }

    // MS2-FUNCTIONAL: the exe inlines the Array constructor and keeps the inlined At's null select as a cmove
    // @0x1423f9880
    void Array::AS3filter(SPtr<Instances::fl::Array>& result, const Value& callback, const Value& thisObject)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        Array* arr = new(itr.Alloc()) Array(itr);
        result = arr;
        if (callback.IsNullOrUndefined())
            return;
        Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
        for (UPInt i = 0; i < SA.GetSize(); ++i)
        {
            Value argv[3] = {saAt(SA, i), Value(static_cast<UInt32>(i)), Value(this)};
            if (!callback.IsCallable())
                break;
            Value r;
            GetVM().ExecuteInternalUnsafe(callback, _this, r, 3, argv, false);
            if (GetVM().IsException())
                break;
            if (r.IsBool() && r.AsBool())
                saPushBack(arr->SA, saAt(SA, i));
        }
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423f9d60
    void Array::AS3forEach(const Value& /*result*/, const Value& callback, const Value& thisObject)
    {
        if (callback.IsNullOrUndefined())
            return;
        Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
        for (UPInt i = 0; i < SA.GetSize(); ++i)
        {
            Value argv[3] = {saAt(SA, i), Value(static_cast<UInt32>(i)), Value(this)};
            if (!callback.IsCallable())
                break;
            Value r;
            GetVM().ExecuteInternalUnsafe(callback, _this, r, 3, argv, false);
            if (GetVM().IsException())
                break;
        }
    }

    // MS2-FUNCTIONAL: the exe inlines the Array constructor and keeps the inlined At's null select as a cmove
    // @0x1423fbb20
    void Array::AS3map(SPtr<Instances::fl::Array>& result, const Value& callback, const Value& thisObject)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        Array* arr = new(itr.Alloc()) Array(itr);
        result = arr;
        if (callback.IsNullOrUndefined())
            return;
        Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
        for (UPInt i = 0; i < SA.GetSize(); ++i)
        {
            Value argv[3] = {saAt(SA, i), Value(static_cast<UInt32>(i)), Value(this)};
            if (!callback.IsCallable())
                break;
            Value r;
            GetVM().ExecuteInternalUnsafe(callback, _this, r, 3, argv, false);
            if (GetVM().IsException())
                break;
            saPushBack(arr->SA, r);
        }
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423fb1a0
    void Array::AS3indexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
    {
        if (fromIndex < 0)
            fromIndex += static_cast<SInt32>(SA.GetSize());
        for (UPInt i = static_cast<SPInt>(fromIndex); i < SA.GetSize(); ++i)
        {
            if (StrictEqual(saAt(SA, i), searchElement))
            {
                result = static_cast<SInt32>(i);
                return;
            }
        }
        result = -1;
    }

    // @0x1423fb450
    void Array::AS3join(Value& result, unsigned argc, const Value* argv)
    {
        ASString sep = GetVM().GetStringManager().GetBuiltin(AS3Builtin_comma_);
        if (argc > 0 && !argv[0].Convert2String(sep))
            return;
        result = ToStringInternal(sep);
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423fb4e0
    void Array::AS3lastIndexOf(SInt32& result, const Value& searchElement, SInt32 fromIndex)
    {
        if (fromIndex < 0)
            fromIndex += static_cast<SInt32>(SA.GetSize());
        SPInt i = static_cast<SPInt>(SA.GetSize()) - 1;
        if (static_cast<SPInt>(fromIndex) < i)
            i = fromIndex;
        for (; i >= 0; --i)
        {
            if (StrictEqual(saAt(SA, i), searchElement))
            {
                result = static_cast<SInt32>(i);
                return;
            }
        }
        result = -1;
    }

    // @0x1423fcd60
    void Array::AS3pop(Value& result)
    {
        if (SA.GetSize() > 0)
        {
            result = SA.Top();
            SA.Pop();
        }
    }

    // @0x1423fd780
    void Array::AS3push(Value& result, unsigned argc, const Value* argv)
    {
        SA.Append(argc, argv);
        result.SetUInt32(static_cast<UInt32>(SA.GetSize()));
    }

    // @0x1423fdf30
    void Array::AS3reverse(SPtr<Instances::fl::Array>& result)
    {
        SA.Reverse();
        result = this;
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl
{
    // @0x1423fa0b0
    void String::AS3fromCharCode(Value& result, unsigned argc, const Value* argv)
    {
        StringBuffer buf(Memory::GetGlobalHeap());
        UInt32 code;
        for (unsigned i = 0; i < argc; ++i)
        {
            if (!argv[i].Convert2UInt32(code))
                return;
            buf.AppendChar(static_cast<UInt16>(code));
        }
        result = GetVM().GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

// NumberUtil::IsNaN, which the exe inlines into String.lastIndexOf.
static SF_INLINE bool isNaN(Double v)
{
    union { Double D; UInt64 I; } u;
    u.D = v;
    return (u.I & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL && (u.I & 0x000FFFFFFFFFFFFFULL) != 0;
}

// InstanceTraits::fl::String::Compare (out of line in sfr_as3_03), inlined into String.localeCompare.
static SF_INLINE SInt32 stringCompare(ASString& l, ASString& r)
{
    SInt32 diff = 0;
    if (l == r)
        return 0;

    const char* lp = l.ToCStr();
    const char* rp = r.ToCStr();
    UInt32 lc, rc;
    do
    {
        lc = UTF8Util::DecodeNextChar(&lp);
        rc = UTF8Util::DecodeNextChar(&rp);
        if (lc == 0 || rc == 0)
            goto tail;
        diff = rc - lc;
    } while (diff == 0);
    return diff;
tail:
    if (lc != rc)
        diff = rc == 0 ? -1 : 1;
    return diff;
}

namespace InstanceTraits { namespace fl
{
    // @0x1423f7310
    void String::AS3charAt(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;
        Value::Number pos = 0;
        if (argc > 0 && !argv[0].Convert2Number(pos))
            return;
        const SInt32 index = static_cast<SInt32>(pos);
        ASString ch = sm.CreateEmptyString();
        if (index >= 0 && static_cast<UInt32>(index) < str.GetLength())
            ch = ASString(ch.AppendCharNode(str.GetCharAt(index)));
        result = ch;
    }

    // MS2-FUNCTIONAL: inliner choice differs (the exe inlines the NaN SetNumber, ours merges both into one call)
    // @0x1423f7440
    void String::AS3charCodeAt(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;
        Value::Number pos = 0;
        if (argc > 0 && !argv[0].Convert2Number(pos))
            return;
        const SInt32 index = static_cast<SInt32>(pos);
        if (index >= 0 && static_cast<UInt32>(index) < str.GetLength())
            result.SetNumber(str.GetCharAt(index));
        else
            result.SetNumber(NumberUtil::NaN());
    }

    // @0x1423f8070
    void String::AS3concat(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;
        ASString arg = sm.CreateEmptyString();
        for (unsigned i = 0; i < argc; ++i)
        {
            if (!argv[i].Convert2String(arg))
                return;
            str.Append(arg);
        }
        result = str;
    }

    // ECMA 15.5.4.8; the search runs over the whole string and keeps the last match at or before the start.
    // @0x1423fb5b0
    void String::AS3lastIndexOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 1)
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

        const char* p = str.ToCStr();
        const char* ps = search.ToCStr();

        SInt32 start = 0x7FFFFFF;
        if (argc > 1)
        {
            Value::Number n = 0x7FFFFFF;
            if (!argv[1].Convert2Number(n))
                return;
            if (!isNaN(n) && !NumberUtil::IsPOSITIVE_INFINITY(n))
            {
                if (NumberUtil::IsNEGATIVE_INFINITY(n))
                    start = 0;
                else
                    start = static_cast<SInt32>(n);
            }
        }

        if (search.GetLength() == 0)
        {
            if (argc > 1)
                result.SetSInt32(start);
            else
                result.SetSInt32(static_cast<SInt32>(str.GetSize()));
            return;
        }

        const UInt32 first = UTF8Util::DecodeNextChar(&ps);
        SInt32 found = -1;
        UInt32 ch;
        for (SInt32 i = 0; (ch = UTF8Util::DecodeNextChar(&p)) != 0; i++)
        {
            if (i <= start && ch == first)
            {
                const char* s1 = p;
                const char* s2 = ps;
                UInt32 c1, c2;
                for (;;)
                {
                    c1 = UTF8Util::DecodeNextChar(&s1);
                    c2 = UTF8Util::DecodeNextChar(&s2);
                    if (c1 == 0 || c2 == 0 || c1 != c2)
                        break;
                }
                if (c2 == 0)
                    found = i;
                if (c1 == 0)
                    break;
            }
        }
        result.SetSInt32(found);
    }

    // MS2-FUNCTIONAL: stack slot order differs (the two strings sit above the shared temporaries in the exe)
    // @0x1423fb960
    void String::AS3localeCompare(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;
        if (argc < 1)
        {
            const Value::Number r = static_cast<SInt32>(str.GetSize() == 0);
            result.SetNumber(r);
            return;
        }
        if (argc > 1)
            return vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "String::AS3localeCompare", 0, 1, argc));

        ASString other = sm.CreateEmptyString();
        if (!argv[0].Convert2String(other))
            return;
        result.SetNumber(stringCompare(other, str));
    }
}} // namespace InstanceTraits::fl

}}} // namespace Scaleform::GFx::AS3

// PCRE (statically linked into the exe).
extern "C" int pcre_exec(const void* code, const void* extra, const char* subject, int length, int start_offset,
                         int options, int* ovector, int ovecsize);
extern "C" void* pcre_compile(const char* pattern, int options, const char** errptr, int* erroffset, const unsigned char* tableptr);
extern "C" int pcre_fullinfo(const void* code, const void* extra, int what, void* where);

// Is v of the class named className (looked up in the VM). 0x1425145d0
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);

// Object::FindProperty: the slot or dynamic value of obj named mn. 0x142502360
void FUN_142502360(Scaleform::GFx::AS3::Object* obj, Scaleform::GFx::AS3::PropRef& result,
                   const Scaleform::GFx::AS3::Multiname& mn, int attr);

namespace Scaleform { namespace GFx { namespace AS3 {

// The fixed slot of tr named name in ns (index receives its slot index). 0x1425011c0
// An array index named by a string ("3") -> ind. 0x142507490
CheckResult GetArrayInd(ASStringNode* sn, UInt32& ind);
const SlotInfo* FindFixedSlot(const Traits& tr, const ASString& name, const Instances::Namespace& ns, UPInt& index,
                              Object* obj);

// SparseArray::PushBack (out of line in sfr_as3_04), inlined into RegExp.exec.
static SF_INLINE void pushBack(SparseArray& sa, const Value& v)
{
    if (sa.Length == sa.ValueA.GetSize())
        sa.ValueA.PushBack(v);
    else
    {
        sa.ValueHHighInd = sa.Length;
        sa.ValueH.Set(sa.ValueHHighInd, v);
    }
    ++sa.Length;
}

namespace Instances { namespace fl
{
    // @0x1423f9300
    void RegExp::AS3exec(SPtr<Instances::fl::Object>& result, const ASString& str)
    {
        int ovector[99];
        char value[1024];
        char name[1024];

        const SInt32 lastIndex = LastIndex;
        const SInt32 start = !IsGlobal ? 0 : lastIndex;
        MatchOffset = 0;
        MatchLength = 0;
        const char* s = str.ToCStr();
        const UInt32 length = str.GetLength();

        int rc = 0;
        if (start >= 0 && start <= static_cast<SInt32>(length))
        {
            rc = pcre_exec(CompRegExp, NULL, s, length, start, 0, ovector, 99);
            if (rc >= 0)
            {
                MatchOffset = ovector[0];
                MatchLength = ovector[1] - ovector[0];

                StringManager& sm = GetVM().GetStringManager();
                SPtr<Instances::fl::Array> arr = GetVM().MakeArray();
                for (int i = 0; i < rc; ++i)
                {
                    if (ovector[i * 2] > -1)
                    {
                        strncpy_s(value, sizeof(value), s + ovector[i * 2], ovector[i * 2 + 1] - ovector[i * 2]);
                        pushBack(arr->SA, Value(sm.CreateString(value)));
                    }
                    else
                        pushBack(arr->SA, Value::GetUndefined());
                }

                arr->AddDynamicSlotValuePair(sm.CreateString("index"), Value(MatchOffset));
                arr->AddDynamicSlotValuePair(sm.CreateString("input"), Value(sm.CreateString(s)));

                if (HasNamedGroups)
                {
                    int count;
                    int entrySize;
                    const char* table;
                    pcre_fullinfo(CompRegExp, NULL, 8, &count);
                    pcre_fullinfo(CompRegExp, NULL, 7, &entrySize);
                    pcre_fullinfo(CompRegExp, NULL, 9, &table);
                    for (int i = 0; i < count; ++i)
                    {
                        strncpy_s(name, sizeof(name), table + 2, strlen(table + 2));
                        const int n = (table[0] << 8) + table[1];
                        strncpy_s(value, sizeof(value), s + ovector[2 * n], ovector[2 * n + 1] - ovector[2 * n]);
                        const ASString group = sm.CreateString(value);
                        const Value v(group);
                        arr->AddDynamicSlotValuePair(sm.CreateString(name), v);
                        table += entrySize;
                    }
                }

                if (IsGlobal)
                    LastIndex = MatchOffset + MatchLength;
                if (LastIndex == lastIndex)
                    ++LastIndex;
                result = static_cast<Instances::fl::Object*>(static_cast<Instance*>(arr.GetPtr()));
                return;
            }
        }
        MatchOffset = rc;
        result = NULL;
    }
}} // namespace Instances::fl

namespace InstanceTraits { namespace fl
{
    // MS2-FUNCTIONAL: block layout differs (the exe places the exec part after the epilogue) and re's release keeps its dead store
    // @0x1423fbf90
    void String::AS3match(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str) || argc < 1)
            return;
        const Value& pattern = argv[0];
        if (pattern.IsNullOrUndefined())
            return;

        SPtr<Instances::fl::RegExp> re;
        if (pattern.IsObject() && FUN_1425145d0(vm, pattern, "RegExp"))
            re = static_cast<Instances::fl::RegExp*>(pattern.GetObject());
        else
        {
            ASString source = sm.CreateEmptyString();
            if (!pattern.Convert2String(source))
                return;
            Value arg(source);
            if (!vm.ConstructBuiltinObject(re, "RegExp", 1, &arg))
                return;
        }

        if (re->IsGlobal)
        {
            SPtr<Instances::fl::Array> arr = vm.MakeArray();
            for (;;)
            {
                SPtr<Instances::fl::Object> m;
                re->AS3exec(m, str);
                if (!m)
                    break;
                pushBack(arr->SA, Value(m));
            }
            result.Assign(arr);
        }
        else
        {
            SPtr<Instances::fl::Object> m;
            re->AS3exec(m, str);
            result.Assign(m);
        }
    }

    // MS2-FUNCTIONAL: regalloc/block layout in the RegExp construct path (the exe keeps the source string address in r8)
    // @0x1423fd8f0
    void String::AS3replace(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str) || argc < 1)
            return;
        const Value& pattern = argv[0];
        if (pattern.IsNullOrUndefined())
            return;

        SPtr<Instances::fl::RegExp> re;
        if (pattern.IsObject() && FUN_1425145d0(vm, pattern, "RegExp"))
            re = static_cast<Instances::fl::RegExp*>(pattern.GetObject());
        else
        {
            ASString source = sm.CreateEmptyString();
            if (!pattern.Convert2String(source))
                return;
            Value arg(source);
            if (!vm.ConstructBuiltinObject(re, "RegExp", 1, &arg))
                return;
        }

        if (argc < 2 || argv[1].IsNullOrUndefined())
            return;
        ASString repl = sm.CreateEmptyString();
        if (!argv[1].Convert2String(repl))
            return;
        do
        {
            {
                SPtr<Instances::fl::Object> m;
                re->AS3exec(m, str);
                if (!m)
                    break;
            }
            const SInt32 offset = re->MatchOffset;
            const SInt32 length = re->MatchLength;
            str = ASString(str.SubstringNode(0, offset)) + repl + ASString(str.SubstringNode(offset + length, str.GetLength()));
        } while (re->IsGlobal);
        result.Assign(str);
    }

    // MS2-FUNCTIONAL: block layout (the exe duplicates the string releases into each exit) and regalloc
    // @0x1423fdfa0
    void String::AS3search(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str) || argc < 1)
            return;
        const Value& pattern = argv[0];
        if (pattern.IsNullOrUndefined())
            return;

        SPtr<Instances::fl::RegExp> re;
        if (pattern.IsObject() && FUN_1425145d0(vm, pattern, "RegExp"))
            re = static_cast<Instances::fl::RegExp*>(pattern.GetObject());
        else
        {
            ASString source = sm.CreateEmptyString();
            if (!pattern.Convert2String(source))
                return;
            Value arg(source);
            if (!vm.ConstructBuiltinObject(re, "RegExp", 1, &arg))
                return;
        }

        SPtr<Instances::fl::Object> m;
        re->AS3exec(m, str);
        if (m)
            result = Value(re->MatchOffset);
    }
}} // namespace InstanceTraits::fl

// Whether a property lookup found something.
static SF_INLINE bool propFound(const PropRef& prop)
{
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.GetKind() == Value::kUndefined || bits == 1)
        return false;
    const bool isValue = (bits & 2) != 0;
    return !isValue || reinterpret_cast<Value*>(bits & ~UPInt(2)) != NULL;
}

namespace InstanceTraits { namespace fl
{
    // MS2-FUNCTIONAL: the exe tests the value tag bit with a byte shift, ours with test al, 2
    // @0x1423fa9e0
    void Object::AS3hasOwnProperty(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, vm));
        if (argc < 1)
            return vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Object::AS3hasOwnProperty", 1, 1, argc));

        if (_this.IsObject())
        {
            AS3::Object* obj = _this.GetObject();
            PropRef prop;
            FUN_142502360(obj, prop, Multiname(vm.GetPublicNamespace(), argv[0]), 1);
            result.SetBool(propFound(prop));
        }
        else
        {
            ASString name = vm.GetStringManager().CreateEmptyString();
            if (!argv[0].Convert2String(name))
                return;
            UPInt index = 0;
            result.SetBool(FindFixedSlot(FUN_14250ffc0(vm, _this), name, vm.GetPublicNamespace(), index, NULL) != NULL);
        }
    }

    // MS2-FUNCTIONAL: the dynamic flag is read as a dword (exe: a byte) and the exe takes its string ref with a checked add
    // @0x1423fd170
    void Object::AS3propertyIsEnumerable(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 1)
            return vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Object::AS3propertyIsEnumerable", 1, 1, argc));

        if (_this.IsObject() && !_this.IsNull())
        {
            UInt32 ind = 0;
            const AS3::Traits& tr = FUN_14250ffc0(vm, _this);
            if (tr.GetTraitsType() == Traits_Array && tr.IsInstanceTraits())
            {
                const Value& name = argv[0];
                const Value::KindType kind = name.GetKind();
                if (kind == Value::kInt || kind == Value::kUInt || kind == Value::kNumber)
                    return result.SetBool(true);
                if (kind == Value::kString && GetArrayInd(name.GetStringNode(), ind))
                    return result.SetBool(true);
            }

            ASString name = vm.GetStringManager().CreateEmptyString();
            if (!argv[0].Convert2String(name))
                return;
            UPInt index = 0;
            const SlotInfo* si = FindFixedSlot(_this.GetObject()->GetTraits(), name, vm.GetPublicNamespace(), index, _this.GetObject());
            if (si)
                return result.SetBool(!si->DontEnum);
            const AS3::Object::DynAttrsType* da = _this.GetObject()->GetDynamicAttrs();
            if (da)
            {
                AS3::Object::DynAttrsType::ConstIterator it = da->Find(name);
                if (!it.IsEnd())
                    return result.SetBool(!((it->First.Flags >> 1) & 1));
            }
        }
        else if (_this.GetKind() == Value::kNamespace && argv[0].IsString())
        {
            const ASString name = argv[0].AsString();
            if (name == "prefix" || name == "uri")
                return result.SetBool(true);
        }

        result.Assign(false);
    }
}} // namespace InstanceTraits::fl

namespace Instances { namespace fl
{
    // MS2-FUNCTIONAL: scheduling (the exe restores rbx after the string releases)
    // @0x1423f5d90
    void RegExp::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc < 1 || argv[0].IsNullOrUndefined())
            return;

        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        ASString source = sm.CreateEmptyString();
        ASString flags = sm.CreateEmptyString();
        if (argv[0].IsObject() && FUN_1425145d0(vm, argv[0], "RegExp"))
        {
            RegExp* re = static_cast<RegExp*>(argv[0].GetObject());
            {
                ASString str = re->GetVM().GetStringManager().CreateEmptyString();
                str = re->GetVM().GetStringManager().CreateString(re->Pattern);
                source = str;
            }
            flags = re->GetFlags();
            if (argc >= 2 && !argv[1].IsNullOrUndefined())
            {
                vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1100), vm));
                return;
            }
        }
        else
        {
            if (!argv[0].Convert2String(source))
                return;
            if (argc >= 2 && !argv[1].IsNullOrUndefined() && !argv[1].Convert2String(flags))
                return;
        }

        const char* s = source.ToCStr();
        const char* f = flags.ToCStr();
        Pattern = s;
        int slashes = 0;
        for (const char* p = s; *p; ++p)
        {
            if (p[0] == '(' && p[1] == '?' && p[2] == 'P' && p[3] == '<')
                HasNamedGroups = true;
            else if (!f && p[0] == '/' && (p == source.ToCStr() || p[-1] != '\\') && slashes++ > 0)
                f = p;
        }
        if (f)
        {
            for (; *f; ++f)
            {
                switch (*f)
                {
                case 'g': IsGlobal = true; break;
                case 'i': OptionFlags |= 1; break;
                case 'm': OptionFlags |= 2; break;
                case 's': OptionFlags |= 4; break;
                case 'x': OptionFlags |= 8; break;
                }
            }
        }
        const char* error;
        int errorOffset;
        CompRegExp = pcre_compile(Pattern.ToCStr(), OptionFlags, &error, &errorOffset, NULL);
    }

    // MS2-FUNCTIONAL: regalloc (the exe also saves rdi and keeps this in rbp)
    // @0x1423f5770
    void Error::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (argv[0].IsObject() && argv[0].GetObject() == NULL)
                message.SetNull();
            else
                argv[0].Convert2String(message);
        }
        if (argc > 1)
        {
            SInt32 id;
            if (argv[1].Convert2Int32(id))
                ID = id;
        }
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

// Namespace::operator= (0x1423f1b00) and Namespace::SetUri (0x142423bd0, 0x142423c10; sfr_as3_04), out of line.
Scaleform::GFx::AS3::Instances::Namespace& FUN_1423f1b00(Scaleform::GFx::AS3::Instances::Namespace* self,
                                                         const Scaleform::GFx::AS3::Instances::Namespace& other);
void FUN_142423bd0(Scaleform::GFx::AS3::Instances::Namespace* self, const Scaleform::GFx::ASString& uri);
void FUN_142423c10(Scaleform::GFx::AS3::Instances::Namespace* self, const Scaleform::GFx::AS3::Value& uri);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances
{
    // new Namespace(), new Namespace(uriValue) and new Namespace(prefixValue, uriValue).
    // @0x1423f5820
    void Namespace::AS3Constructor(unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        switch (argc)
        {
        case 0:
            SetPrefix(vm.GetStringManager().CreateEmptyString());
            break;
        case 1:
            {
                const Value& v = argv[0];
                if (v.IsNamespace())
                    FUN_1423f1b00(this, v.AsNamespace());
                else if (IsQNameObject(v))
                {
                    const fl::QName* qname = static_cast<const fl::QName*>(v.GetObject());
                    if (qname->Ns.GetPtr() == NULL)
                        Uri = vm.GetStringManager().CreateConstString("*");
                    else
                        FUN_142423bd0(this, qname->Ns->GetUri());
                }
                else
                {
                    FUN_142423c10(this, v);
                    if (v.IsString() && v.AsString().IsEmpty())
                        SetPrefix(v);
                    else
                        SetPrefix(Value::GetUndefined());
                }
            }
            break;
        default:
            {
                const Value& vp = argv[0];
                const Value& vu = argv[1];
                StringManager& sm = vm.GetStringManager();
                ASString p = sm.CreateEmptyString();
                ASString u = sm.CreateEmptyString();
                if (!vp.Convert2String(p))
                    return;
                if (!vu.Convert2String(u))
                    return;
                if (!p.IsEmpty() && u.IsEmpty())
                    return vm.ThrowTypeError(VM::Error(VM::eXMLNamespaceWithPrefixAndNoURI, vm, p));
                SetPrefix(vp);
                FUN_142423c10(this, vu);
            }
            break;
        }
    }
} // namespace Instances

}}} // namespace Scaleform::GFx::AS3

// SPtr<Namespace>::operator=(Namespace*) and operator=(Pickable) (0x1423f1840, 0x1423f18b0) and
// ASString::operator= (0x1423f1a30), out of line in the exe here.
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>&
FUN_1423f1840(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>* self,
              Scaleform::GFx::AS3::Instances::Namespace* p);
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>&
FUN_1423f18b0(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>* self,
              Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Namespace> p);
void FUN_1423f1a30(Scaleform::GFx::ASString* self, const Scaleform::GFx::ASString& src);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // InstanceTraits::fl::Namespace::MakeInternedInstance (0x14241ba70), which the exe inlines here.
    static SF_INLINE Pickable<Instances::Namespace> MakeInternedNamespace(InstanceTraits::fl::Namespace& itr,
        Abc::NamespaceKind kind, const ASString& uri, const Value& prefix)
    {
        return itr.InstanceFactory->MakeNamespace(kind, uri, prefix);
    }

    // new QName(), new QName(name) and new QName(namespace, name).
    // @0x1423f5ae0
    void QName::AS3Constructor(unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        if (argc == 0)
            LocalName = sm.CreateEmptyString();
        else if (argc == 1)
        {
            if (!argv[0].IsUndefined())
            {
                if (!argv[0].Convert2String(LocalName))
                    return;
            }
            if (LocalName == "*")
                Ns = NULL;
        }
        else
        {
            Ns = NULL;
            if (!argv[0].IsNull())
            {
                if (IsNamespaceObject(argv[0]))
                    FUN_1423f1840(&Ns, const_cast<Instances::Namespace*>(&argv[0].AsNamespace()));
                else if (IsQNameObject(argv[0]))
                {
                    QName* other = static_cast<QName*>(argv[0].GetObject());
                    Ns = other->Ns;
                }
                else
                {
                    ASString uri = sm.CreateEmptyString();
                    if (argv[0].Convert2String(uri))
                    {
                        InstanceTraits::fl::Namespace& itr_ns = static_cast<InstanceTraits::fl::Namespace&>(
                            GetVM().GetClassTraitsNamespace().GetInstanceTraits());
                        FUN_1423f18b0(&Ns, MakeInternedNamespace(itr_ns, Abc::NS_Public, uri, Value::GetUndefined()));
                    }
                }
            }

            // The local name (a namespace second argument reads the first argument's prefix).
            if (IsNamespaceObject(argv[1]))
                argv[0].AsNamespace().GetPrefix().Convert2String(LocalName).DoNotCheck();
            else if (IsQNameObject(argv[1]))
            {
                QName* other = static_cast<QName*>(argv[1].GetObject());
                FUN_1423f1a30(&LocalName, other->LocalName);
            }
            else if (argv[1].IsUndefined())
                LocalName = sm.CreateEmptyString();
            else
                argv[1].Convert2String(LocalName).DoNotCheck();
        }
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits
{
    // Runs the class's instance initializer on _this (the exec_constructsuper path); the frame keeps the scope
    // stored by ot's parent.
    // @0x1423f6110
    void UserDefined::AS3Constructor(const AS3::Traits& ot, const Value& _this, unsigned argc, const Value* argv) const
    {
        VMAbcFile& file = GetScript().GetFile();
        const SInt32 mbi_ind = file.GetAbcFile().Methods.Info[class_info.inst_info.method_info_ind]->MethodBodyInfoInd;
        GetVM().AddFrame(Value::GetUndefined(), file, mbi_ind, _this, argc, argv, true, ot.GetParent()->InitScope,
                         *ot.GetParent(), GetName() + " instance constructor");
    }
} // namespace InstanceTraits

}}} // namespace Scaleform::GFx::AS3

// ==== E4X natives ====================================================================================================

Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // replace(name, value): a deep copy of an XML or XMLList value, or value's string, takes the place of child
    // prop_name names by index, or of the first child that matches it (the later matches are deleted).
    // @0x1423f6870
    CheckResult XMLElement::AS3Replace(const Multiname& prop_name, const Value& value)
    {
        VM& vm = GetVM();
        Value c;
        if (IsXMLObject(value))
            c = Value(static_cast<XML*>(value.GetObject())->DeepCopy(NULL));
        else if (IsXMLListObject(value))
            c = Value(static_cast<XMLList*>(value.GetObject())->DeepCopy(NULL));
        else
        {
            ASString str = vm.GetStringManager().CreateEmptyString();
            if (!value.Convert2String(str))
                return false;
            c = str;
        }

        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
            return Replace(ind, c);

        // Walk backwards so the match left in found is the first one.
        Value found;
        found.SetUndefinedUnsafe();
        for (UPInt j = Children.GetSize(); j > 0; --j)
        {
            const UPInt k = j - 1;
            if (Children[k]->Matches(prop_name))
            {
                if (!found.IsUndefined())
                    DeleteByIndex(found.AsInt());
                found.SetSInt32(static_cast<SInt32>(k));
            }
        }

        bool result = true;
        if (!found.IsUndefined())
            result = Replace(found.AsInt(), c);
        return result;
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // The index of the first c in s, -1 for none.
    static SF_INLINE SPInt FindFirstChar(const StringDataPtr& s, char c)
    {
        for (UPInt i = 0; i < s.GetSize(); ++i)
        {
            if (s.ToCStr()[i] == c)
                return i;
        }
        return -1;
    }

    // new XMLList(value): an XML value becomes the only item; anything else is converted to a string and parsed as a
    // sequence of text runs and elements (";" separators are skipped).
    // MS2-FUNCTIONAL: the exe inlines MakeInstanceText, the XMLText constructor and List.PushBack
    // @0x1423f63b0
    void XMLList::AS3Constructor(unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        if (argc == 0 || argv[0].IsNullOrUndefined())
            return;
        if (argc != 1)
            return;

        const Value& arg = argv[0];
        if (IsXMLObject(arg))
        {
            List.PushBack(SPtr<XML>(static_cast<XML*>(arg.GetObject())));
            return;
        }

        InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(*vm.GetXMLSupport().GetITraitsXML());
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (!arg.Convert2String(str))
            return;

        StringDataPtr s(str.ToCStr(), str.GetSize());
        const bool ignoreWhitespace =
            static_cast<const Classes::fl::XML&>(FUN_142508460(vm.GetXMLSupport().GetITraitsXML())).ignoreWhitespace;
        while (!s.IsEmpty())
        {
            const char first = *ASUtils::SkipWhiteSpace(s.ToCStr(), s.GetSize());
            if (first == ';')
            {
                s = s.GetTrimLeft(1);
                continue;
            }

            if (first != '<')
            {
                // A text run up to the next element.
                StringDataPtr txt;
                const SPInt len = FindFirstChar(s, '<');
                if (len == -1)
                {
                    txt = s;
                    s = s.GetTrimLeft(s.GetSize());
                }
                else
                {
                    txt = StringDataPtr(s.ToCStr(), len);
                    s = s.GetTrimLeft(len);
                }
                if (ignoreWhitespace)
                    txt = txt.GetTruncateWhitespace();
                SPtr<XML> el(itr.MakeInstanceText(itr, txt, NULL));
                List.PushBack(el);
                continue;
            }

            UPInt pos = 0;
            XMLParser parser(itr);
            if (!parser.Parse(s, pos, true))
            {
                if (pos == 0)
                    return;
                const char c = s.ToCStr()[pos];
                if (c == ';')
                {
                    s = s.GetTrimLeft(1);
                    vm.HandleException = false;
                }
                else if (c == '<')
                {
                    pos = s.FindLastChar('>', pos) + 1;
                    vm.HandleException = false;
                }
                else
                    return;
            }

            for (UPInt i = 0; i < parser.RootElements.GetSize(); ++i)
                List.PushBack(parser.RootElements[i]);
            s = s.GetTrimLeft(pos);
        }
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x142419b10 (sfr_as3_04)
CheckResult IsNameStartChar(int c);

namespace Instances { namespace fl
{
    // The list of the XMLList class's instances (no target).
    static SF_INLINE InstanceTraits::fl::XMLList& xmlListTraits(VM& vm)
    {
        return static_cast<InstanceTraits::fl::XMLList&>(vm.GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
    }

    // A new list of the XMLList class whose target is name of obj.
    static SF_INLINE Pickable<XMLList> MakeTargetList(AS3::Object& obj, const ASString& name, Instances::Namespace& ns)
    {
        InstanceTraits::fl::XMLList& itr = xmlListTraits(obj.GetVM());
        return itr.MakeInstance(itr, obj, name, ns);
    }

    // The list has exactly one item; throws a TypeError naming fn otherwise.
    static SF_INLINE bool HasOneItem(XMLList& list, const char* fn)
    {
        bool result = true;
        if (list.List.GetSize() != 1)
        {
            VM& vm = list.GetVM();
            vm.ThrowTypeError(VM::Error(VM::eXMLOnlyWorksWithOneItemLists, vm, fn));
            result = false;
        }
        return result;
    }

    // Adds ns (converted to a Namespace) to the in-scope namespaces; returns this node.
    // @0x1423f6b10
    __declspec(noinline) void XML::AS3addNamespace(SPtr<XML>& result, const Value& ns)
    {
        if (!ns.IsNullOrUndefined())
        {
            VM& vm = GetVM();
            Value r;
            FUN_142508460(&vm.GetClassTraitsNamespace().GetInstanceTraits()).Construct(r, 1, &ns, true);
            if (vm.IsException())
                return;
            AddInScopeNamespace(r.AsNamespace());
        }
        result = this;
    }

    // @0x1423f6c80
    SPtr<XML> XMLList::AS3addNamespace(const Value& ns)
    {
        SPtr<XML> result;
        AS3addNamespace(result, ns);
        return result;
    }

    // @0x1423f6ca0
    __declspec(noinline) void XMLList::AS3addNamespace(SPtr<XML>& result, const Value& ns)
    {
        if (HasOneItem(*this, "addNamespace"))
            List[0]->AS3addNamespace(result, ns);
    }

    // @0x1423f6d10
    void XML::AS3appendChild(SPtr<XML>& /*result*/, const Value& child)
    {
        AppendChild(child);
    }

    // @0x1423f6d30
    SPtr<XML> XMLList::AS3appendChild(const Value& child)
    {
        SPtr<XML> result;
        AS3appendChild(result, child);
        return result;
    }

    // @0x1423f6d50
    __declspec(noinline) void XMLList::AS3appendChild(SPtr<XML>& result, const Value& child)
    {
        if (HasOneItem(*this, "appendChild"))
            List[0]->AS3appendChild(result, child);
    }

    // @0x1423f6dc0
    SPtr<XMLList> XML::AS3attribute(const Value& arg)
    {
        SPtr<XMLList> result;
        AS3attribute(result, arg);
        return result;
    }

    // The attributes named arg.
    // @0x1423f6de0
    __declspec(noinline) void XML::AS3attribute(SPtr<XMLList>& result, const Value& arg)
    {
        VM& vm = GetVM();
        if (arg.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "arg"));
        Multiname mn(vm, arg);
        mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | Abc::MNF_Attr);
        if (vm.IsException())
            return;
        result = MakeXMLListInstance(mn);
        GetProperty(mn, *result);
    }

    // The attributes named arg of every item.
    // @0x1423f6f70
    void XMLList::AS3attribute(SPtr<XMLList>& result, const Value& arg)
    {
        VM& vm = GetVM();
        if (arg.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "arg"));
        Multiname mn(vm, arg);
        mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | Abc::MNF_Attr);
        if (vm.IsException())
            return;
        result = MakeXMLListInstance(mn);
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            XML* x = List[i];
            if (!x->GetProperty(mn, *result))
                return;
        }
    }

    // @0x1423f7100
    SPtr<XMLList> XML::AS3attributes()
    {
        SPtr<XMLList> result;
        AS3attributes(result);
        return result;
    }

    // MS2-FUNCTIONAL: the exe inlines InstanceTraits::fl::XMLList::MakeInstance and the XMLList constructor
    // @0x1423f7120
    __declspec(noinline) void XML::AS3attributes(SPtr<XMLList>& result)
    {
        InstanceTraits::fl::XMLList& itr = xmlListTraits(GetVM());
        result = itr.MakeInstance(itr);
        GetAttributes(*result);
    }

    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423f71f0
    void XMLList::AS3attributes(SPtr<XMLList>& result)
    {
        result = MakeXMLListInstance();
        XMLList& list = *result;
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List[i]->GetAttributes(list);
    }

    // @0x1423f7560
    SPtr<XMLList> XML::AS3child(const Value& propertyName)
    {
        SPtr<XMLList> result;
        AS3child(result, propertyName);
        return result;
    }

    // The children named propertyName.
    // @0x1423f7580
    __declspec(noinline) void XML::AS3child(SPtr<XMLList>& result, const Value& propertyName)
    {
        VM& vm = GetVM();
        if (propertyName.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "propertyName"));
        Multiname mn(vm, propertyName);
        if (vm.IsException())
            return;
        result = MakeXMLListInstance(mn);
        GetProperty(mn, *result);
    }

    // The children named propertyName (in the public namespace) of every item.
    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423f7710
    void XMLList::AS3child(SPtr<XMLList>& result, const Value& propertyName)
    {
        if (propertyName.IsNullOrUndefined())
        {
            VM& vm = GetVM();
            return vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "propertyName"));
        }
        result = MakeXMLListInstance();
        XMLList& list = *result;
        Multiname mn(GetVM().GetPublicNamespace(), propertyName);
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List[i]->GetChildren(list, mn);
    }

    // The index in the parent's children, -1 without a parent.
    // @0x1423f7920
    void XML::AS3childIndex(SInt32& result)
    {
        result = -1;
        UPInt ind;
        if (GetChildIndex(ind))
            result = static_cast<SInt32>(ind);
    }

    // @0x1423f7960
    void XMLList::AS3childIndex(SInt32& result)
    {
        if (HasOneItem(*this, "childIndex"))
            List[0]->AS3childIndex(result);
    }

    // @0x1423f79f0
    SPtr<XMLList> XML::AS3children()
    {
        SPtr<XMLList> result;
        AS3children(result);
        return result;
    }

    // MS2-FUNCTIONAL: the exe inlines InstanceTraits::fl::XMLList::MakeInstance and the XMLList constructor
    // @0x1423f7a10
    __declspec(noinline) void XML::AS3children(SPtr<XMLList>& result)
    {
        InstanceTraits::fl::XMLList& itr = xmlListTraits(GetVM());
        result = itr.MakeInstance(itr);
        GetChildren(*result, kNone);
    }

    // The children of every item (GetProperty with the any-name, inlined).
    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423f7ae0
    void XMLList::AS3children(SPtr<XMLList>& result)
    {
        result = MakeXMLListInstance();
        Multiname mn(GetVM());
        XMLList& list = *result;
        if (mn.IsAttr())
        {
            const UPInt size = List.GetSize();
            for (UPInt i = 0; i < size; ++i)
                List[i]->GetProperty(mn, list);
        }
        else
        {
            ListGet cb(*this, list);
            ForEachChild(mn, cb);
        }
    }

    // @0x1423f7cb0
    SPtr<XMLList> XML::AS3comments()
    {
        SPtr<XMLList> result;
        AS3comments(result);
        return result;
    }

    // A new list targeting this node of its comment children.
    // MS2-FUNCTIONAL: register allocation only (the exe keeps the null-string node in rbp across MakeInstance)
    // @0x1423f7cd0
    __declspec(noinline) void XML::AS3comments(SPtr<XMLList>& result)
    {
        result = MakeTargetList(*this, GetVM().GetStringManager().CreateNullString(), GetVM().GetPublicNamespace());
        GetChildren(*result, kComment);
    }

    // A new list targeting this list of the comment children of the element items.
    // MS2-FUNCTIONAL: the exe inlines XMLList::Append
    // @0x1423f7db0
    void XMLList::AS3comments(SPtr<XMLList>& result)
    {
        VM& vm = GetVM();
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(GetInstanceTraits());
        result = itr.MakeInstance(itr, *this, vm.GetStringManager().CreateNullString(), vm.GetPublicNamespace());
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            XML* x = List[i];
            if (x->GetKind() == XML::kElement)
                result->Append(*x->AS3comments());
        }
    }

    // v is an XML node equal to this one.
    // @0x1423f8170
    void XML::AS3contains(bool& result, const Value& v)
    {
        result = false;
        if (IsXMLObject(v))
            result = EqualsInternal(*static_cast<XML*>(v.GetObject())) == true3;
    }

    // v is an XML node equal to an item.
    // @0x1423f81d0
    void XMLList::AS3contains(bool& result, const Value& v)
    {
        result = false;
        if (IsXMLObject(v))
        {
            XML* x = static_cast<XML*>(v.GetObject());
            const UPInt size = List.GetSize();
            for (UPInt i = 0; i < size && !result; ++i)
            {
                if (List[i]->EqualsInternal(*x) == true3)
                    result = true;
            }
        }
    }

    // @0x1423f8270
    void XML::AS3copy(SPtr<XML>& result)
    {
        result = DeepCopy(NULL);
    }

    // @0x1423f82d0
    void XMLList::AS3copy(SPtr<XMLList>& result)
    {
        result = DeepCopy(NULL);
    }

    // The descendants named argv[0] ("*" without arguments).
    // MS2-FUNCTIONAL: the exe inlines InstanceTraits::fl::XMLList::MakeInstance and the XMLList constructor
    // @0x1423f8600
    void XML::AS3descendants(Value& result, unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        InstanceTraits::fl::XMLList& itr = xmlListTraits(vm);
        Pickable<XMLList> list = itr.MakeInstance(itr);
        result.Pick(list);
        Multiname mn(GetVM().GetPublicNamespace(),
            argc == 0 ? Value(GetVM().GetStringManager().CreateConstString("*")) : Value(argv[0]));
        GetDescendants(*list, mn);
    }

    // The descendants named argv[0] ("*" without arguments) of every item.
    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423f8840
    void XMLList::AS3descendants(Value& result, unsigned argc, const Value* argv)
    {
        Multiname mn(GetVM().GetPublicNamespace(),
            argc == 0 ? Value(GetVM().GetStringManager().CreateConstString("*")) : Value(argv[0]));
        Pickable<XMLList> list = MakeXMLListInstance();
        result.Pick(list);
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List[i]->GetDescendants(*list, mn);
    }

    // The element children named argv[0] ("*" without arguments).
    // MS2-FUNCTIONAL: the exe inlines InstanceTraits::fl::XMLList::MakeInstance and the XMLList constructor
    // @0x1423f8aa0
    void XML::AS3elements(Value& result, unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        InstanceTraits::fl::XMLList& itr = xmlListTraits(vm);
        Pickable<XMLList> list = itr.MakeInstance(itr);
        result.Pick(list);
        Multiname mn(GetVM().GetPublicNamespace(),
            argc == 0 ? Value(GetVM().GetStringManager().CreateConstString("*")) : Value(argv[0]));
        GetChildren(*list, mn);
    }

    // The element children named argv[0] ("*" without arguments) of every item.
    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423f8ce0
    void XMLList::AS3elements(Value& result, unsigned argc, const Value* argv)
    {
        Pickable<XMLList> list = MakeXMLListInstance();
        result.Pick(list);
        Multiname mn(GetVM().GetPublicNamespace(),
            argc == 0 ? Value(GetVM().GetStringManager().CreateConstString("*")) : Value(argv[0]));
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List[i]->GetChildren(*list, mn);
    }

    // True unless the node has simple content.
    // @0x1423fa9a0
    void XML::AS3hasComplexContent(bool& result)
    {
        result = !HasSimpleContent();
    }

    // @0x1423fac40
    void XML::AS3hasOwnProperty(bool& result, const ASString& p)
    {
        result = HasOwnProperty(p);
    }

    // @0x1423fac60
    void XML::AS3hasSimpleContent(bool& result)
    {
        result = HasSimpleContent();
    }

    // An empty list is simple; one item answers for itself; otherwise simple when no item is an element.
    // @0x1423fac80
    __declspec(noinline) void XMLList::AS3hasSimpleContent(bool& result)
    {
        const UPInt size = List.GetSize();
        switch (size)
        {
        case 0:
            result = true;
            break;
        case 1:
            result = List[0]->HasSimpleContent();
            break;
        default:
            result = true;
            for (UPInt i = 0; i < size; ++i)
            {
                if (List[i]->GetKind() == XML::kElement)
                {
                    result = false;
                    break;
                }
            }
            break;
        }
    }

    // True unless the list has simple content.
    // @0x1423fa9c0
    void XMLList::AS3hasComplexContent(bool& result)
    {
        AS3hasSimpleContent(result);
        result = !result;
    }

    // @0x1423fad30
    SPtr<Instances::fl::Array> XML::AS3inScopeNamespaces()
    {
        SPtr<Instances::fl::Array> result;
        AS3inScopeNamespaces(result);
        return result;
    }

    // Array storage push, as SparseArray::PushBack (0x14241e4b0) which the exe inlines here.
    static SF_INLINE void PushBackValue(SparseArray& sa, const Value& v)
    {
        if (sa.Length == sa.ValueA.GetSize())
            sa.ValueA.PushBack(v);
        else
        {
            sa.ValueHHighInd = sa.Length;
            sa.ValueH.Set(sa.ValueHHighInd, v);
        }
        ++sa.Length;
    }

    // The namespaces in scope here, nearest first, one per prefix (the public one if none).
    // MS2-FUNCTIONAL: the exe inlines Value(Namespace*) (0x1423ef9b0) and with it ArrayDH<Value>::PushBack
    // @0x1423fad50
    __declspec(noinline) void XML::AS3inScopeNamespaces(SPtr<Instances::fl::Array>& result)
    {
        Pickable<Instances::fl::Array> a = GetVM().MakeArray();
        result = a;

        HashSet<Value, Value::HashFunctor> dupeCheck;

        for (XML* xml = this; xml; xml = xml->Parent)
        {
            const NamespaceArray* pnsh = xml->GetInScopeNamespaces();
            if (pnsh)
            {
                const NamespaceArray& nsh = *pnsh;
                const UPInt size = nsh.Namespaces.GetSize();
                for (UPInt i = 0; i < size; ++i)
                {
                    Instances::Namespace* ns = nsh.Namespaces[i];
                    Value prefix = ns->GetPrefix();
                    if (!dupeCheck.Get(prefix))
                    {
                        PushBackValue(a->SA, Value(ns));
                        dupeCheck.Add(prefix);
                    }
                }
            }
        }

        if (a->GetSize() == 0)
            PushBackValue(a->SA, Value(&GetVM().GetPublicNamespace()));
    }

    // @0x1423fb110
    SPtr<Instances::fl::Array> XMLList::AS3inScopeNamespaces()
    {
        SPtr<Instances::fl::Array> result;
        AS3inScopeNamespaces(result);
        return result;
    }

    // @0x1423fb130
    __declspec(noinline) void XMLList::AS3inScopeNamespaces(SPtr<Instances::fl::Array>& result)
    {
        if (HasOneItem(*this, "inScopeNamespaces"))
            List[0]->AS3inScopeNamespaces(result);
    }

    // This node after child2 is inserted after child1, else undefined.
    // @0x1423fb270
    __declspec(noinline) void XML::AS3insertChildAfter(Value& result, const Value& child1, const Value& child2)
    {
        if (InsertChildAfter(child1, child2))
            result = this;
        else
            result.SetUndefined();
    }

    // @0x1423fb2f0
    void XMLList::AS3insertChildAfter(Value& result, const Value& child1, const Value& child2)
    {
        if (HasOneItem(*this, "insertChildAfter"))
            List[0]->AS3insertChildAfter(result, child1, child2);
    }

    // This node after child2 is inserted before child1, else undefined.
    // @0x1423fb360
    __declspec(noinline) void XML::AS3insertChildBefore(Value& result, const Value& child1, const Value& child2)
    {
        if (InsertChildBefore(child1, child2))
            result = this;
        else
            result.SetUndefined();
    }

    // @0x1423fb3e0
    void XMLList::AS3insertChildBefore(Value& result, const Value& child1, const Value& child2)
    {
        if (HasOneItem(*this, "insertChildBefore"))
            List[0]->AS3insertChildBefore(result, child1, child2);
    }

    // @0x1423fb890
    void XML::AS3localName(ASString& result)
    {
        result = Text;
    }

    // @0x1423fb8d0
    void XMLList::AS3localName(ASString& result)
    {
        if (HasOneItem(*this, "localName"))
            List[0]->AS3localName(result);
    }

    // @0x1423fc340
    SPtr<Instances::fl::QName> XML::AS3name()
    {
        SPtr<Instances::fl::QName> result;
        AS3name(result);
        return result;
    }

    // @0x1423fc360
    void XML::AS3name(SPtr<Instances::fl::QName>& result)
    {
        result = GetQName();
    }

    // @0x1423fc400
    SPtr<Instances::fl::QName> XMLList::AS3name()
    {
        SPtr<Instances::fl::QName> result;
        AS3name(result);
        return result;
    }

    // @0x1423fc420
    __declspec(noinline) void XMLList::AS3name(SPtr<Instances::fl::QName>& result)
    {
        if (HasOneItem(*this, "name"))
            List[0]->AS3name(result);
    }

    // @0x1423fc490
    SPtr<Instances::fl::Array> XML::AS3namespaceDeclarations()
    {
        SPtr<Instances::fl::Array> result;
        AS3namespaceDeclarations(result);
        return result;
    }

    // A local namespace list on the VM heap.
    typedef ArrayDH<SPtr<Instances::Namespace> > NamespaceArrayDH;

    // ns pushed unless an equal namespace (uri + kind) is already in, as NamespaceArray::Add.
    static SF_INLINE void AddNamespace(NamespaceArrayDH& arr, Instances::Namespace& ns)
    {
        for (UPInt i = 0; i < arr.GetSize(); ++i)
            if (*arr[i] == ns)
                return;
        arr.PushBack(SPtr<Instances::Namespace>(&ns));
    }

    // The prefixed namespaces declared on this element. The ancestors' prefixed namespaces are
    // collected but, as in the exe, not used to filter the result.
    // The exe calls the SPtr<Namespace> ArrayDH resize (0x14241ff20) and the array destructor (0x1423f06a0)
    // out of line but inlines Value(Namespace*) (0x1423ef9b0); ours does the reverse.
    // MS2-FUNCTIONAL: inlining of the array resize/destructor and of Value(Namespace*) differs
    // @0x1423fc4b0
    __declspec(noinline) void XML::AS3namespaceDeclarations(SPtr<Instances::fl::Array>& result)
    {
        VM& vm = GetVM();
        Pickable<Instances::fl::Array> a = vm.MakeArray();
        result = a;

        XML::Kind kind = GetKind();
        if (kind == kText || kind == kComment || kind == kInstruction || kind == kAttr)
            return;

        NamespaceArrayDH ancestorNS(vm.GetMemoryHeap());
        for (XML* y = Parent; y != NULL; y = y->Parent)
        {
            const NamespaceArray* pnsh = y->GetInScopeNamespaces();
            if (pnsh)
            {
                const NamespaceArray& nsh = *pnsh;
                for (UPInt i = 0; i < nsh.Namespaces.GetSize(); ++i)
                {
                    if (nsh.Namespaces[i]->GetPrefix().IsNullOrUndefined())
                        continue;
                    bool exists = false;
                    for (UPInt j = 0; j < ancestorNS.GetSize(); ++j)
                    {
                        if (StrictEqual(ancestorNS[j]->GetPrefix(), nsh.Namespaces[i]->GetPrefix()))
                        {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists)
                        AddNamespace(ancestorNS, *nsh.Namespaces[i]);
                }
            }
        }

        NamespaceArrayDH declaredNS(vm.GetMemoryHeap());
        const NamespaceArray* pnsh = GetInScopeNamespaces();
        if (pnsh)
        {
            const NamespaceArray& nsh = *pnsh;
            for (UPInt i = 0; i < nsh.Namespaces.GetSize(); ++i)
            {
                if (!nsh.Namespaces[i]->GetPrefix().IsNullOrUndefined())
                    AddNamespace(declaredNS, *nsh.Namespaces[i]);
            }
        }

        for (UPInt i = 0; i < declaredNS.GetSize(); ++i)
            PushBackValue(a->SA, Value(declaredNS[i].GetPtr()));
    }

    // @0x1423fc8d0
    SPtr<Instances::fl::Array> XMLList::AS3namespaceDeclarations()
    {
        SPtr<Instances::fl::Array> result;
        AS3namespaceDeclarations(result);
        return result;
    }

    // @0x1423fc8f0
    __declspec(noinline) void XMLList::AS3namespaceDeclarations(SPtr<Instances::fl::Array>& result)
    {
        if (HasOneItem(*this, "namespaceDeclarations"))
            List[0]->AS3namespaceDeclarations(result);
    }

    // The node's namespace, or the in-scope namespace bound to the prefix argv[0] (undefined when there is none).
    // MS2-FUNCTIONAL: the exe calls Value::operator=(Namespace*) out of line (0x1423f1b90); this build inlines it
    // @0x1423fc960
    __declspec(noinline) void XML::AS3namespace_(Value& result, unsigned argc, const Value* argv)
    {
        if (argc == 0)
        {
            result = &GetCurrNamespace();
            return;
        }

        ASString prefix = GetVM().GetStringManager().CreateEmptyString();
        if (argv[0].Convert2String(prefix))
        {
            Instances::Namespace* ns = FindNamespaceByPrefix(prefix, NULL);
            if (ns)
                result = ns;
            else
                result.SetUndefined();
        }
    }

    // @0x1423fca10
    void XMLList::AS3namespace_(Value& result, unsigned argc, const Value* argv)
    {
        if (HasOneItem(*this, "namespace"))
            List[0]->AS3namespace_(result, argc, argv);
    }

    // @0x1423fca80
    __declspec(noinline) void XML::AS3nodeKind(ASString& result)
    {
        const char* kind = NULL;
        switch (GetKind())
        {
        case kElement:
            kind = "element";
            break;
        case kText:
            kind = "text";
            break;
        case kComment:
            kind = "comment";
            break;
        case kInstruction:
            kind = "processing-instruction";
            break;
        case kAttr:
            kind = "attribute";
            break;
        default:
            break;
        }
        result = kind;
    }

    // @0x1423fcb00
    void XMLList::AS3nodeKind(ASString& result)
    {
        if (HasOneItem(*this, "nodeKind"))
            List[0]->AS3nodeKind(result);
    }

    // @0x1423fcb70
    void XML::AS3normalize(SPtr<XML>& result)
    {
        Normalize();
        result = this;
    }

    // @0x1423fcbe0
    void XMLList::AS3normalize(SPtr<XMLList>& result)
    {
        result = this;
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List[i]->Normalize();
    }

    // @0x1423fcc70
    void XML::AS3parent(Value& result)
    {
        if (Parent.GetPtr() == NULL)
            result.SetUndefined();
        else
            result = Parent;
    }

    // The items' common parent, else undefined.
    // @0x1423fccd0
    void XMLList::AS3parent(Value& result)
    {
        const UPInt size = List.GetSize();
        if (size == 0)
            return result.SetUndefined();
        XML* parent = List[0]->Parent;
        for (UPInt i = 1; i < size; ++i)
        {
            XML* cur_parent = List[i]->Parent;
            if (parent != cur_parent)
                return result.SetUndefined();
        }
        if (parent)
            result = parent;
        else
            result.SetUndefined();
    }

    // This node after child is inserted as its first child, else null.
    // @0x1423fcdb0
    __declspec(noinline) void XML::AS3prependChild(SPtr<XML>& result, const Value& child)
    {
        if (InsertChildAt(0, child))
            result = this;
        else
            result = NULL;
    }

    // @0x1423fce30
    SPtr<XML> XMLList::AS3prependChild(const Value& child)
    {
        SPtr<XML> result;
        AS3prependChild(result, child);
        return result;
    }

    // @0x1423fce50
    __declspec(noinline) void XMLList::AS3prependChild(SPtr<XML>& result, const Value& child)
    {
        if (HasOneItem(*this, "prependChild"))
            List[0]->AS3prependChild(result, child);
    }

    // A new list of the processing-instruction children (named argv[0] if given).
    // MS2-FUNCTIONAL: the exe inlines InstanceTraits::fl::XMLList::MakeInstance and the XMLList constructor
    // @0x1423fcec0
    void XML::AS3processingInstructions(Value& result, unsigned argc, const Value* argv)
    {
        InstanceTraits::fl::XMLList& itr = xmlListTraits(GetVM());
        Pickable<XMLList> list = itr.MakeInstance(itr);
        result.Pick(list);
        ASString name = GetVM().GetStringManager().CreateEmptyString();
        if (argc > 0)
            argv[0].Convert2String(name).DoNotCheck();
        GetChildren(*list, kInstruction, &name);
    }

    // The processing-instruction children (named argv[0] if given) of every item.
    // MS2-FUNCTIONAL: the exe inlines MakeXMLListInstance and the XMLList constructor
    // @0x1423fcfc0
    void XMLList::AS3processingInstructions(Value& result, unsigned argc, const Value* argv)
    {
        Pickable<XMLList> list = MakeXMLListInstance();
        result.Pick(list);
        if (argc == 0)
        {
            const UPInt size = List.GetSize();
            for (UPInt i = 0; i < size; ++i)
                List[i]->GetChildren(*list, XML::kInstruction);
        }
        else
        {
            ASString name = GetVM().GetStringManager().CreateEmptyString();
            if (argv[0].Convert2String(name))
            {
                const UPInt size = List.GetSize();
                for (UPInt i = 0; i < size; ++i)
                    List[i]->GetChildren(*list, XML::kInstruction, &name);
            }
        }
    }

    // True for the property "0" only (a node acts as a one-item list).
    // @0x1423fd4f0
    void XML::AS3propertyIsEnumerable(Value& result, unsigned argc, const Value* argv)
    {
        if (argc > 0 && !argv[0].IsNullOrUndefined())
        {
            Multiname prop_name(GetVM().GetPublicNamespace(), argv[0]);
            UInt32 ind;
            if (GetVectorInd(prop_name, ind) && ind == 0)
            {
                result.SetBool(true);
                return;
            }
        }
        result.SetBool(false);
    }

    // True for an index property below the list length.
    // @0x1423fd650
    void XMLList::AS3propertyIsEnumerable(Value& result, unsigned argc, const Value* argv)
    {
        if (argc > 0 && !argv[0].IsNullOrUndefined())
        {
            Multiname prop_name(GetVM(), argv[0]);
            UInt32 ind;
            if (GetVectorInd(prop_name, ind))
            {
                if (ind < List.GetSize())
                {
                    result.SetBool(true);
                    return;
                }
            }
        }
        result.SetBool(false);
    }

    // @0x1423fd7f0
    __declspec(noinline) void XML::AS3removeNamespace(SPtr<XML>& result, const Value& ns)
    {
        result = RemoveNamespace(ns);
    }

    // @0x1423fd860
    SPtr<XML> XMLList::AS3removeNamespace(const Value& ns)
    {
        SPtr<XML> result;
        AS3removeNamespace(result, ns);
        return result;
    }

    // @0x1423fd880
    __declspec(noinline) void XMLList::AS3removeNamespace(SPtr<XML>& result, const Value& ns)
    {
        if (HasOneItem(*this, "removeNamespace"))
            List[0]->AS3removeNamespace(result, ns);
    }

    // Replaces the properties named propertyName with value (a string is parsed as XML first); returns this node.
    // @0x1423fdca0
    __declspec(noinline) void XML::AS3replace(SPtr<XML>& result, const Value& propertyName, const Value& value)
    {
        VM& vm = GetVM();
        const Multiname prop_name(vm, propertyName);

        if (vm.IsException())
            return;

        bool isXmlValue = false;
        if (FUN_14250ffc0(GetVM(), value).GetTraitsType() == Traits_String)
        {
            Value xmlValue;
            FUN_142508460(&GetTraits()).Construct(xmlValue, 1, &value, false);
            if (GetVM().IsException())
                return;

            if (!AS3Replace(prop_name, xmlValue))
                return;

            isXmlValue = true;
        }

        if (!isXmlValue)
        {
            if (!AS3Replace(prop_name, value))
                return;
        }

        result = this;
    }

    // @0x1423fde40
    SPtr<XML> XMLList::AS3replace(const Value& propertyName, const Value& value)
    {
        SPtr<XML> result;
        AS3replace(result, propertyName, value);
        return result;
    }

    // @0x1423fdec0
    void XMLList::AS3replace(SPtr<XML>& result, const Value& propertyName, const Value& value)
    {
        if (HasOneItem(*this, "replace"))
            List[0]->AS3replace(result, propertyName, value);
    }

    // @0x1423fe250
    __declspec(noinline) void XML::AS3setChildren(SPtr<XML>& result, const Value& value)
    {
        SetChildren(value);
        result = this;
    }

    // @0x1423fe2c0
    SPtr<XML> XMLList::AS3setChildren(const Value& value)
    {
        SPtr<XML> result;
        AS3setChildren(result, value);
        return result;
    }

    // @0x1423fe2e0
    __declspec(noinline) void XMLList::AS3setChildren(SPtr<XML>& result, const Value& value)
    {
        if (HasOneItem(*this, "setChildren"))
            List[0]->AS3setChildren(result, value);
    }

    // A valid XML name: a name start character, then name start characters, '-', '.' or digits.
    static SF_INLINE bool IsValidXMLName(const ASString& name)
    {
        if (name.GetLength() == 0)
            return false;
        if (!IsNameStartChar(name[0]))
            return false;
        const unsigned len = name.GetLength();
        for (unsigned i = 1; i < len; ++i)
        {
            const int c = name[i];
            if (IsNameStartChar(c))
                continue;
            if (c == '-' || c == '.')
                continue;
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }

    // MS2-FUNCTIONAL: the exe hoists the name buffer out of the inlined IsValidName loop (it knows IsNameStartChar
    // writes no memory), so registers and the loop differ
    // @0x1423fe3e0
    __declspec(noinline) void XML::AS3setLocalName(const Value& result, const Value& name)
    {
        SF_UNUSED(result);
        XML::Kind kind = GetKind();

        if (kind == kText || kind == kComment)
            return;

        VM& vm = GetVM();
        if (IsQNameObject(name))
            Text = static_cast<QName*>(name.GetObject())->LocalName;
        else if (!name.IsUndefined())
            name.Convert2String(Text).DoNotCheck();

        if (!IsValidXMLName(Text))
            return vm.ThrowTypeError(VM::Error(VM::eXMLInvalidName, vm));
    }

    // @0x1423fe520
    void XMLList::AS3setLocalName(const Value& result, const Value& name)
    {
        if (HasOneItem(*this, "setLocalName"))
            List[0]->AS3setLocalName(result, name);
    }

    // MS2-FUNCTIONAL: the exe hoists the name buffer out of the inlined IsValidName loop (it knows IsNameStartChar
    // writes no memory), so registers and the loop differ
    // @0x1423fe620
    __declspec(noinline) void XML::AS3setName(const Value& result, const Value& name)
    {
        SF_UNUSED(result);
        XML::Kind kind = GetKind();
        if (kind == kText || kind == kComment)
            return;

        VM& vm = GetVM();
        ASString localName = vm.GetStringManager().CreateEmptyString();
        Namespace* ns = NULL;
        if (IsQNameObject(name))
        {
            QName* qName = static_cast<QName*>(name.GetObject());
            if (qName->Ns.GetPtr() != NULL)
                SetNamespace(*qName->Ns);

            localName = qName->LocalName;
            ns = qName->Ns;
        }
        else if (!name.IsUndefined())
        {
            if (!name.Convert2String(localName))
                return vm.ThrowTypeError(VM::Error(VM::eXMLInvalidName, vm));
        }

        if (!IsValidXMLName(localName))
            return vm.ThrowTypeError(VM::Error(VM::eXMLInvalidName, vm));

        Text = localName;

        if (ns != NULL)
        {
            if (kind == kAttr)
            {
                if (Parent.GetPtr() != NULL)
                    Parent->AddInScopeNamespace(*ns);
            }
            else if (kind == kElement)
                AddInScopeNamespace(*ns);
        }
        SetNamespace(ns ? *ns : vm.GetPublicNamespace());
    }

    // @0x1423fe8c0
    void XMLList::AS3setName(const Value& result, const Value& name)
    {
        if (HasOneItem(*this, "setName"))
            List[0]->AS3setName(result, name);
    }

    // ECMA 13.4.4.36
    // @0x1423fe930
    __declspec(noinline) void XML::AS3setNamespace(const Value& result, const Value& ns)
    {
        SF_UNUSED(result);
        XML::Kind kind = GetKind();

        if (kind == kText || kind == kComment || kind == kInstruction)
            return;

        VM& vm = GetVM();

        Pickable<Namespace> made = vm.MakeNamespace(Abc::NS_Public, vm.GetStringManager().CreateEmptyString(),
                                                    Value::GetUndefined());
        SPtr<Namespace> ns2 = made;
        ns2->AS3Constructor(1, &ns);

        if (kind == kAttr)
        {
            if (Parent.GetPtr() == NULL)
                return;

            Parent->AddInScopeNamespace(*ns2);
        }
        else if (kind == kElement)
            AddInScopeNamespace(*ns2);

        SetNamespace(*ns2);
    }

    // @0x1423fea20
    void XMLList::AS3setNamespace(const Value& result, const Value& ns)
    {
        if (HasOneItem(*this, "setNamespace"))
            List[0]->AS3setNamespace(result, ns);
    }
}} // namespace Instances::fl

namespace Classes { namespace fl
{
    // A new Object holding the default settings.
    // @0x1423f8330
    void XML::AS3defaultSettings(SPtr<Instances::fl::Object>& result)
    {
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        Pickable<Instances::fl::Object> o = vm.MakeObject();
        result = o;
        o->AddDynamicSlotValuePair(sm.CreateConstString("ignoreComments"), Value(true));
        o->AddDynamicSlotValuePair(sm.CreateConstString("ignoreProcessingInstructions"), Value(true));
        o->AddDynamicSlotValuePair(sm.CreateConstString("ignoreWhitespace"), Value(true));
        o->AddDynamicSlotValuePair(sm.CreateConstString("prettyPrinting"), Value(true));
        o->AddDynamicSlotValuePair(sm.CreateConstString("prettyIndent"), Value(SInt32(2)));
    }

    static SF_INLINE const Value* FindDynamicValue(AS3::Object& obj, const ASString& name)
    {
        return obj.GetDynamicAttrs()->Get(AS3::Object::DynAttrsKey(name));
    }

    // null/undefined restores the defaults; an object sets each setting it carries with the right type.
    // @0x1423feac0
    void XML::AS3setSettings(const Value& result, const Value& o)
    {
        SF_UNUSED(result);
        if (o.IsNullOrUndefined())
        {
            ignoreComments = true;
            ignoreProcessingInstructions = true;
            ignoreWhitespace = true;
            prettyPrinting = true;
            prettyIndent = 2;
        }
        else if (o.IsObject())
        {
            AS3::Object& obj = *o.GetObject();
            StringManager& sm = GetVM().GetStringManager();
            const Value* v;

            v = FindDynamicValue(obj, sm.CreateConstString("ignoreComments"));
            if (v && v->IsBool())
                ignoreComments = v->AsBool();
            v = FindDynamicValue(obj, sm.CreateConstString("ignoreProcessingInstructions"));
            if (v && v->IsBool())
                ignoreProcessingInstructions = v->AsBool();
            v = FindDynamicValue(obj, sm.CreateConstString("ignoreWhitespace"));
            if (v && v->IsBool())
                ignoreWhitespace = v->AsBool();
            v = FindDynamicValue(obj, sm.CreateConstString("prettyPrinting"));
            if (v && v->IsBool())
                prettyPrinting = v->AsBool();
            v = FindDynamicValue(obj, sm.CreateConstString("prettyIndent"));
            if (v && v->IsInt())
                prettyIndent = v->AsInt();
        }
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7CallBack@XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436c0
// MS2-PIN: ??_7ListGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143ae0
