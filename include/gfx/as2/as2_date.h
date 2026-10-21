// Recovered Scaleform 4.1.18 GFx AS2: the Date class (time kept as UTC and as local time, each split into
// milliseconds since 1970, milliseconds within the day, year and day within the year).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_DATE_H
#define MS2_SF_GFX_AS2_DATE_H

#include "as2_action.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Date instance. 0x98 bytes.
class DateObject : public Object
{
public:
    DateObject(Environment* penv); // exe 0x14291b510

    SInt64 Date;        // +0x68 ms since 1 Jan 1970 UTC
    int    Time;        // +0x70 ms within the UTC day
    int    Year;        // +0x74
    int    JDate;       // +0x78 day within the UTC year (0 based)
    SInt64 LDate;       // +0x80 the same in local time
    int    LTime;       // +0x88
    int    LYear;       // +0x8c
    int    LJDate;      // +0x90
    int    LocalOffset; // +0x94 ms local time is ahead of UTC

    void SetDate(SInt64 val); // exe 0x142980570 (UTC ms since 1970, updates both halves)
    void UpdateGMT();         // exe 0x142992900 (UTC half from the local half)
    void UpdateLocal();       // exe 0x142992b00 (local half from the UTC half)

protected:
    void commonInit(Environment* penv); // exe 0x142994fe0
};

// Date.prototype methods.
class DateProto
{
public:
    static void DateGetTimezoneOffset(const FnCall& fn);
    static void DateGetMonth(const FnCall& fn);
    static void DateGetDate(const FnCall& fn);
    static void DateGetDay(const FnCall& fn);
    static void DateGetTime(const FnCall& fn);
    static void DateGetHours(const FnCall& fn);
    static void DateGetMinutes(const FnCall& fn);
    static void DateGetSeconds(const FnCall& fn);
    static void DateGetMilliseconds(const FnCall& fn);
    static void DateGetYear(const FnCall& fn);
    static void DateGetFullYear(const FnCall& fn);
    static void DateSetYear(const FnCall& fn);
    static void DateSetFullYear(const FnCall& fn);
    static void DateSetMonth(const FnCall& fn);
    static void DateSetDate(const FnCall& fn);
    static void DateSetTime(const FnCall& fn);
    static void DateSetHours(const FnCall& fn);
    static void DateSetMinutes(const FnCall& fn);
    static void DateSetSeconds(const FnCall& fn);
    static void DateSetMilliseconds(const FnCall& fn);
    static void DateGetUTCMonth(const FnCall& fn);
    static void DateGetUTCDate(const FnCall& fn);
    static void DateGetUTCDay(const FnCall& fn);
    static void DateGetUTCHours(const FnCall& fn);
    static void DateGetUTCMinutes(const FnCall& fn);
    static void DateGetUTCSeconds(const FnCall& fn);
    static void DateGetUTCMilliseconds(const FnCall& fn);
    static void DateGetUTCYear(const FnCall& fn);
    static void DateGetUTCFullYear(const FnCall& fn);
    static void DateSetUTCYear(const FnCall& fn);
    static void DateSetUTCFullYear(const FnCall& fn);
    static void DateSetUTCMonth(const FnCall& fn);
    static void DateSetUTCDate(const FnCall& fn);
    static void DateSetUTCHours(const FnCall& fn);
    static void DateSetUTCMinutes(const FnCall& fn);
    static void DateSetUTCSeconds(const FnCall& fn);
    static void DateSetUTCMilliseconds(const FnCall& fn);
    static void DateToString(const FnCall& fn);
    static void DateValueOf(const FnCall& fn);
};

// Gregorian leap year (exe 0x142965c80). The unity build inlines it only inside the month loops; the
// straight-line uses call it, so those go through this declaration and the loops through Date_IsLeapYear.
bool IsLeapYear(int y);

// Inline copy of IsLeapYear.
inline bool Date_IsLeapYear(int y)
{
    return 0 == (y % 4) && ((y % 100) || 0 == (y % 400));
}

// Days from 1 Jan 1970 to 1 Jan of year y.
inline int Date_StartOfYear(int y)
{
    y -= 1970;
    return 365 * y + ((y + 1) / 4) - ((y + 69) / 100) + ((y + 369) / 400);
}

// The Date class: the static Date.UTC.
class DateCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936c40

private:
    static void DateUTC(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
