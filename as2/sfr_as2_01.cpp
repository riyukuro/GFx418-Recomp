// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 builtin class natives
// (Boolean prototype methods, the Math object functions, Date prototype getters/setters).
// MS2-UNIT: sfr_as2_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428f4cd0-0x1428f4e40 .text$mn
// MS2-RANGE: 0x1428fb110-0x1428fbb70 .text$mn
// MS2-RANGE: 0x1428fc160-0x1428fdc00 .text$mn

#include <math.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/gfx_displayobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Boolean wrapper object. 0x70 bytes.
class BooleanObject : public Object
{
public:
    bool bValue; // +0x68
};

// Boolean.prototype.toString(): "true" / "false" of the wrapped value.
// @0x1428f4cd0
void GAS_BooleanToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetString(pthis->GetValue().ToString(fn.Env));
}

// Boolean.prototype.valueOf()
// @0x1428f4da0
void GAS_BooleanValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetBool(pthis->GetValue().ToBool(fn.Env));
}

class Math
{
public:
    // Next value of the movie's random generator (exe 0x142953f50).
    static UInt32 GetNextRandom(MovieImpl* proot);
};

// The Math object's functions; every argument goes through ToNumber.
class MathCtorFunction
{
    static void Abs(const FnCall& fn);
    static void Acos(const FnCall& fn);
    static void Asin(const FnCall& fn);
    static void Atan(const FnCall& fn);
    static void Ceil(const FnCall& fn);
    static void Cos(const FnCall& fn);
    static void Exp(const FnCall& fn);
    static void Floor(const FnCall& fn);
    static void Log(const FnCall& fn);
    static void Sin(const FnCall& fn);
    static void Sqrt(const FnCall& fn);
    static void Tan(const FnCall& fn);
    static void Atan2(const FnCall& fn);
    static void Max(const FnCall& fn);
    static void Min(const FnCall& fn);
    static void Pow(const FnCall& fn);
    static void Random(const FnCall& fn);
    static void Round(const FnCall& fn);
};

// @0x1428fb110
void MathCtorFunction::Abs(const FnCall& fn)
{
    fn.Result->SetNumber(fabs(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb1a0
void MathCtorFunction::Acos(const FnCall& fn)
{
    fn.Result->SetNumber(acos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb220
void MathCtorFunction::Asin(const FnCall& fn)
{
    fn.Result->SetNumber(asin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb2a0
void MathCtorFunction::Atan(const FnCall& fn)
{
    fn.Result->SetNumber(atan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb320
void MathCtorFunction::Ceil(const FnCall& fn)
{
    fn.Result->SetNumber(ceil(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb3a0
void MathCtorFunction::Cos(const FnCall& fn)
{
    fn.Result->SetNumber(cos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb420
void MathCtorFunction::Exp(const FnCall& fn)
{
    fn.Result->SetNumber(exp(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb4a0
void MathCtorFunction::Floor(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb520
void MathCtorFunction::Log(const FnCall& fn)
{
    fn.Result->SetNumber(log(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb5a0
void MathCtorFunction::Sin(const FnCall& fn)
{
    fn.Result->SetNumber(sin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb620
void MathCtorFunction::Sqrt(const FnCall& fn)
{
    fn.Result->SetNumber(sqrt(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb6a0
void MathCtorFunction::Tan(const FnCall& fn)
{
    fn.Result->SetNumber(tan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb720
void MathCtorFunction::Atan2(const FnCall& fn)
{
    Number y = fn.Arg(0).ToNumber(fn.Env);
    Number x = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(atan2(y, x));
}

// @0x1428fb800
void MathCtorFunction::Max(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a > b ? a : b);
}

// @0x1428fb8d0
void MathCtorFunction::Min(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a < b ? a : b);
}

// @0x1428fb9a0
void MathCtorFunction::Pow(const FnCall& fn)
{
    Number base     = fn.Arg(0).ToNumber(fn.Env);
    Number exponent = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(pow(base, exponent));
}

// Uniform in [0, 1].
// @0x1428fba80
void MathCtorFunction::Random(const FnCall& fn)
{
    MovieImpl* proot = ((DisplayObjectBase*)fn.Env->Target)->GetMovieImpl();
    fn.Result->SetNumber(Number(Math::GetNextRandom(proot)) / Number(0xFFFFFFFFu));
}

// @0x1428fbae0
void MathCtorFunction::Round(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env) + 0.5));
}

// Day of the year at which each month ends, for common and leap years.
static const int DateMonthEnds[2][12] = {
    {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

// @0x1428fc160
void DateProto::DateGetDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][0])
    {
        fn.Result->SetNumber(Number(pthis->LJDate + 1));
        return;
    }
    for (int m = 1; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            fn.Result->SetNumber(Number(pthis->LJDate + 1 - DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m - 1]));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// 1 Jan 1970 was a Thursday.
// @0x1428fc350
void DateProto::DateGetDay(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((int(pthis->LDate / 86400000) + 4) % 7));
}

// @0x1428fc410
void DateProto::DateGetFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LYear));
}

// @0x1428fc490
void DateProto::DateGetHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LTime / 3600000));
}

// @0x1428fc520
void DateProto::DateGetMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LTime % 1000));
}

// @0x1428fc5c0
void DateProto::DateGetMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->LTime % 3600000) / 60000));
}

// @0x1428fc680
void DateProto::DateGetMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    for (int m = 0; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            fn.Result->SetNumber(Number(m));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// @0x1428fc7e0
void DateProto::DateGetSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->LTime % 60000) / 1000));
}

// @0x1428fc8a0
void DateProto::DateGetTime(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Date));
}

// Minutes UTC is ahead of local time.
// @0x1428fc920
void DateProto::DateGetTimezoneOffset(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(-pthis->LocalOffset / 60000));
}

// @0x1428fc9b0
void DateProto::DateGetYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LYear - 1900));
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fca40
void DateProto::DateSetDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int day = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            int delta = day - (pthis->LJDate - (m ? DateMonthEnds[IsLeapYear(pthis->LYear)][m - 1] : 0)) - 1;
            pthis->LJDate += delta;
            pthis->LDate += SInt64(delta) * SInt64(86400000);
            pthis->UpdateGMT();
            return;
        }
    }
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fcbf0
void DateProto::DateSetFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (pthis->LJDate >= 60)
        pthis->LJDate += IsLeapYear(year) - IsLeapYear(pthis->LYear);
    pthis->LDate = SInt64(pthis->LTime) + SInt64(Date_StartOfYear(year) + pthis->LJDate) * SInt64(86400000);
    pthis->LYear = year;
    pthis->UpdateGMT();
}

// @0x1428fcd60
void DateProto::DateSetHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int hours = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = (hours - pthis->LTime / 3600000) * 3600000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fce60
void DateProto::DateSetMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int ms    = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = ms - pthis->LTime % 1000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fcf60
void DateProto::DateSetMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int minutes = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (minutes - (pthis->LTime % 3600000) / 60000) * 60000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// Keeps the day of the month, clamped to the length of the new month.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fd070
void DateProto::DateSetMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int month = (int)fn.Arg(0).ToNumber(fn.Env);
    DateGetDate(fn);
    int day        = (int)fn.Result->ToNumber(fn.Env);
    int oldDay     = pthis->LJDate;
    int monthStart = 0;
    if (month > 0)
        monthStart = DateMonthEnds[IsLeapYear(pthis->LYear)][month - 1];
    int monthLength = DateMonthEnds[IsLeapYear(pthis->LYear)][month] - monthStart;
    if (day > monthLength)
        day = monthLength;
    pthis->LJDate = monthStart + day - 1;
    pthis->LDate += SInt64(pthis->LJDate - oldDay) * SInt64(86400000);
    fn.Result->SetUndefined();
}

// @0x1428fd230
void DateProto::DateSetSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int seconds = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (seconds - (pthis->LTime % 60000) / 1000) * 1000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fd340
void DateProto::DateSetTime(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    pthis->SetDate((SInt64)fn.Arg(0).ToNumber(fn.Env));
}

// Two digit years count from 1900.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fd400
void DateProto::DateSetYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (year < 100 && year >= 0)
        year += 1900;
    if (pthis->LJDate >= 60)
        pthis->LJDate += IsLeapYear(year) - IsLeapYear(pthis->LYear);
    pthis->LDate = SInt64(pthis->LTime) + SInt64(Date_StartOfYear(year) + pthis->LJDate) * SInt64(86400000);
    pthis->LYear = year;
    pthis->UpdateGMT();
}

// @0x1428fd580
void DateProto::DateGetUTCDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][0])
    {
        fn.Result->SetNumber(Number(pthis->JDate + 1));
        return;
    }
    for (int m = 1; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            fn.Result->SetNumber(Number(pthis->JDate + 1 - DateMonthEnds[Date_IsLeapYear(pthis->Year)][m - 1]));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// @0x1428fd770
void DateProto::DateGetUTCDay(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((int(pthis->Date / 86400000) + 4) % 7));
}

// @0x1428fd830
void DateProto::DateGetUTCFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Year));
}

// @0x1428fd8b0
void DateProto::DateGetUTCHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Time / 3600000));
}

// @0x1428fd940
void DateProto::DateGetUTCMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Time % 1000));
}

// @0x1428fd9e0
void DateProto::DateGetUTCMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->Time % 3600000) / 60000));
}

// @0x1428fdaa0
void DateProto::DateGetUTCMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            fn.Result->SetNumber(Number(m));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

}}} // namespace Scaleform::GFx::AS2
