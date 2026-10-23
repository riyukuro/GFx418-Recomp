// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 runtime. Our own source,
// written from the exe.
// MS2-UNIT: sfr_as3_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423f5770-0x1423ff040 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"

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
