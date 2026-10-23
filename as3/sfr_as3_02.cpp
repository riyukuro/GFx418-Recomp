// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 runtime. Our own source,
// written from the exe.
// MS2-UNIT: sfr_as3_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423f5770-0x1423ff040 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
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
                return result.SetBool(!((static_cast<UInt32>(si->Bits) >> 1) & 1));
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
