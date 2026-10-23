// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector traversals
// (ForEachChild_GC of the collectable classes and of every built-in prototype, for the release, mark-in-cycle and
// scan-in-use passes) and the Stage function stub.
// MS2-UNIT: sfr_as2_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428fdc00-0x1428ff660 .text$mn
// MS2-RANGE: 0x142900f50-0x142900fc0 .text$mn
// MS2-RANGE: 0x142901ae0-0x142902a00 .text$mn
// MS2-RANGE: 0x142902a10-0x1429033c0 .text$mn
// MS2-RANGE: 0x1429035a0-0x142903650 .text$mn
// MS2-RANGE: 0x142903910-0x142903b30 .text$mn
// MS2-RANGE: 0x142906d80-0x142906de0 .text$mn
// MS2-RANGE: 0x142906fc0-0x142908840 .text$mn
// MS2-RANGE: 0x142908c30-0x142908e90 .text$mn
// MS2-RANGE: 0x14290bed0-0x142914500 .text$mn
// MS2-RANGE: 0x142914500-0x142914660 .text$mn
// MS2-RANGE: 0x142914660-0x142914880 .text$mn
// MS2-RANGE: 0x142914880-0x142914e60 .text$mn
// MS2-RANGE: 0x142914e60-0x142917780 .text$mn
// MS2-RANGE: 0x142917780-0x142917bf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx { namespace AS2 {

typedef ASRefCountBaseType::Collector Collector;

// Day of the year at which each month ends, for common and leap years.
static const int DateMonthEnds[2][12] = {
    {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

static const char* const DateDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
static const char* const DateMonthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// Local time as "Thu Jan  1 00:00:00 GMT+0000 1970".
// @0x1428fe7e0
void DateProto::DateToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    int         month = 0, date = 0;
    for (int m = 0; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            month = m;
            date  = pthis->LJDate - (m ? DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m - 1] : 0) + 1;
            break;
        }
    }

    // 1 Jan 1970 was a Thursday; days before it count backwards.
    const char* dayName;
    if (pthis->LDate >= 0)
        dayName = DateDayNames[(pthis->LDate / 86400000 + 4) % 7];
    else
    {
        SInt64 absDate = _abs64(pthis->LDate);
        dayName        = DateDayNames[((3 - absDate / 86400000) % 7 + 7) % 7];
    }

    char out[128];
    Format(StringDataPtr(out, sizeof(out)), "{0} {1} {2:2} {3:02}:{4:02}:{5:02} GMT{6:+03}{7:02} {8}", dayName,
           DateMonthNames[month], date, pthis->LTime / 3600000, (pthis->LTime % 3600000) / 60000,
           (pthis->LTime % 60000) / 1000, pthis->LocalOffset / 3600000, (pthis->LocalOffset % 3600000) / 60000,
           pthis->LYear);
    fn.Result->SetString(fn.Env->CreateString(out));
}

// Date.UTC(year, month[, date[, hours[, minutes[, seconds[, ms]]]]]): ms since 1970 of a UTC date; years 0..99 are
// 1900 based.
// MS2-FUNCTIONAL the exe keeps the month in r10 across the IsLeapYear call (see DateSetUTCDate)
// @0x1428fed10
void DateCtorFunction::DateUTC(const FnCall& fn)
{
    if (fn.NArgs >= 2)
    {
        int year = (int)fn.Arg(0).ToNumber(fn.Env);
        if (year >= 0 && year < 100)
            year += 1900;
        Number date  = Date_StartOfYear(year);
        Number time  = 0;
        int    month = (int)fn.Arg(1).ToNumber(fn.Env);
        if (month)
            date += DateMonthEnds[IsLeapYear(year)][month - 1];
        if (fn.NArgs >= 3)
            date += (int)fn.Arg(2).ToNumber(fn.Env) - 1;
        if (fn.NArgs >= 4)
            time += fn.Arg(3).ToNumber(fn.Env) * 3600000;
        if (fn.NArgs >= 5)
            time += fn.Arg(4).ToNumber(fn.Env) * 60000;
        if (fn.NArgs >= 6)
            time += fn.Arg(5).ToNumber(fn.Env) * 1000;
        if (fn.NArgs >= 7)
            time += fn.Arg(6).ToNumber(fn.Env);
        fn.Result->SetNumber(date * 86400000 + time);
    }
    else
        fn.Result->SetNumber(0);
}

void DateProto::DateGetUTCSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->Time % 60000) / 1000));
}

void DateProto::DateGetUTCYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Year - 1900));
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fdd50
void DateProto::DateSetUTCDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int day = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            int delta = day - (pthis->JDate - (m ? DateMonthEnds[IsLeapYear(pthis->Year)][m - 1] : 0)) - 1;
            pthis->JDate += delta;
            pthis->Date += SInt64(delta) * SInt64(86400000);
            pthis->UpdateLocal();
            return;
        }
    }
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fdef0
void DateProto::DateSetUTCFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (pthis->JDate >= 60)
        pthis->JDate += IsLeapYear(year) - IsLeapYear(pthis->Year);
    pthis->Date = SInt64(pthis->Time) + SInt64(Date_StartOfYear(year) + pthis->JDate) * SInt64(86400000);
    pthis->Year = year;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int hours = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = (hours - pthis->Time / 3600000) * 3600000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int ms    = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = ms - pthis->Time % 1000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int minutes = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (minutes - (pthis->Time % 3600000) / 60000) * 60000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

// Moves the date by whole months: the day within the month is not clamped.
void DateProto::DateSetUTCMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int month = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            int delta = DateMonthEnds[Date_IsLeapYear(pthis->Year)][month] -
                        DateMonthEnds[Date_IsLeapYear(pthis->Year)][m];
            pthis->JDate += delta;
            pthis->Date += SInt64(delta) * SInt64(86400000);
            pthis->UpdateLocal();
            return;
        }
    }
}

void DateProto::DateSetUTCSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int seconds = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (seconds - (pthis->Time % 60000) / 1000) * 1000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

// Two digit years count from 1900.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fe670
void DateProto::DateSetUTCYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (year < 100 && year >= 0)
        year += 1900;
    if (pthis->JDate >= 60)
        pthis->JDate += IsLeapYear(year) - IsLeapYear(pthis->Year);
    pthis->Date = SInt64(pthis->Time) + SInt64(Date_StartOfYear(year) + pthis->JDate) * SInt64(86400000);
    pthis->Year = year;
    pthis->UpdateLocal();
}

void DateProto::DateValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Date));
}

// Number.prototype.toString([radix])
void GAS_NumberToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Number);
    NumberObject* pthis = (NumberObject*)(Object*)fn.ThisPtr;
    int radix = 10;
    if (fn.NArgs > 0)
        radix = (int)fn.Arg(0).ToNumber(fn.Env);
    fn.Result->SetString(fn.Env->CreateString(pthis->ToString(radix)));
}

// Number.prototype.valueOf()
void GAS_NumberValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Number);
    NumberObject* pthis = (NumberObject*)(Object*)fn.ThisPtr;
    fn.Result->SetNumber(pthis->GetValue().ToNumber(fn.Env));
}

void ObjectProto::HasOwnProperty(const FnCall& fn)
{
    fn.Result->SetBool(fn.ThisPtr->HasMember(fn.Env->GetSC(), fn.Arg(0).ToString(fn.Env), false));
}

// True for an own member that is not hidden from for..in.
void ObjectProto::IsPropertyEnumerable(const FnCall& fn)
{
    if (fn.NArgs >= 1)
    {
        ASString prop(fn.Arg(0).ToString(fn.Env));
        bool     rv = fn.ThisPtr->HasMember(fn.Env->GetSC(), prop, false);
        if (rv)
        {
            Member m;
            fn.ThisPtr->FindMember(fn.Env->GetSC(), prop, &m);
            if (m.GetMemberFlags().GetDontEnum())
                rv = false;
        }
        fn.Result->SetBool(rv);
    }
    else
        fn.Result->SetBool(false);
}

// MovieImpl::AdvanceStats (+0x30, not recovered in gfx_movieimpl.h yet).
static inline AMP::ViewStats* GetAdvanceStats(MovieImpl* pmovie)
{
    return *(AMP::ViewStats**)((UByte*)pmovie + 0x30);
}

// AmpMarker.addMarker(name)
void AmpMarkerCtorFunction::AddMarker(const FnCall& fn)
{
    fn.Result->SetNull();
    if (!fn.Env || fn.NArgs == 0)
        return;
    GetAdvanceStats(fn.Env->GetTarget()->GetMovieImpl())->AddMarker(fn.Arg(0).ToString(fn.Env).ToCStr());
}

// Key.getAscii([controller]): the controller argument is a Scaleform extension.
void KeyCtorFunction::KeyGetAscii(const FnCall& fn)
{
    KeyCtorFunction* ko = (KeyCtorFunction*)fn.ThisPtr;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 1)
        controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
    fn.Result->SetInt(ko->GetLastAsciiCode(controllerIdx));
}

void KeyCtorFunction::KeyGetCode(const FnCall& fn)
{
    KeyCtorFunction* ko = (KeyCtorFunction*)fn.ThisPtr;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 1)
        controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
    fn.Result->SetInt(ko->GetLastKeyCode(controllerIdx));
}

// MovieImpl::pUserEventHandler (+0x230, not recovered in gfx_movieimpl.h yet).
static inline UserEventHandler* GetUserEventHandler(MovieImpl* pmovie)
{
    return *(UserEventHandler**)((UByte*)pmovie + 0x230);
}

void MouseCtorFunction::Show(const FnCall& fn)
{
    fn.Result->SetUndefined();
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    if (GetUserEventHandler(proot))
    {
        unsigned mouseIndex = 0;
        if (fn.NArgs >= 1)
            mouseIndex = fn.Arg(0).ToUInt32(fn.Env);
        GetUserEventHandler(proot)->HandleEvent((Movie*)proot, MouseCursorEvent(Event::DoShowMouse, mouseIndex));
    }
    else
        fn.Env->LogScriptWarning("No user event handler interface is installed; Mouse.show failed.");
}

void MouseCtorFunction::Hide(const FnCall& fn)
{
    fn.Result->SetUndefined();
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    if (GetUserEventHandler(proot))
    {
        unsigned mouseIndex = 0;
        if (fn.NArgs >= 1)
            mouseIndex = fn.Arg(0).ToUInt32(fn.Env);
        GetUserEventHandler(proot)->HandleEvent((Movie*)proot, MouseCursorEvent(Event::DoHideMouse, mouseIndex));
    }
    else
        fn.Env->LogScriptWarning("No user event handler interface is installed; Mouse.hide failed.");
}

// MovieImpl::KeyboardStates[4] (+0x13b0, not recovered in gfx_movieimpl.h yet).
static inline const KeyboardState* GetKeyboardState(MovieImpl* pmovie, unsigned controllerIdx)
{
    if (controllerIdx < 4)
        return (const KeyboardState*)((UByte*)pmovie + 0x13b0 + (UPInt)controllerIdx * 0x688);
    return 0;
}

// Key.isDown(code[, controller])
void KeyCtorFunction::KeyIsDown(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("KeyIsDown needs one Argument (the key code)");
        return;
    }
    int      code          = fn.Arg(0).ToInt32(fn.Env);
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 2)
        controllerIdx = fn.Arg(1).ToUInt32(fn.Env);
    KeyCtorFunction*     ko = (KeyCtorFunction*)fn.ThisPtr;
    const KeyboardState* ks = GetKeyboardState(ko->pMovieRoot, controllerIdx);
    fn.Result->SetBool(ks ? ks->IsKeyDown(code) : false);
}

// Key.isToggled(code[, controller]) for the lock keys.
void KeyCtorFunction::KeyIsToggled(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("KeyIsToggled needs one Argument (the key code)");
        return;
    }
    int      code          = fn.Arg(0).ToInt32(fn.Env);
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 2)
        controllerIdx = fn.Arg(1).ToUInt32(fn.Env);
    KeyCtorFunction*     ko = (KeyCtorFunction*)fn.ThisPtr;
    const KeyboardState* ks = GetKeyboardState(ko->pMovieRoot, controllerIdx);
    fn.Result->SetBool(ks ? ks->IsKeyToggled(code) : false);
}

// TextSnapshot.findText(start, text, caseSensitive)
// MS2-FUNCTIONAL register allocation differs (rbx/rsi/rdi swapped)
// @0x142908090
void TextSnapshotProto::FindTextA(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 3)
        return;
    UInt32   start         = fn.Arg(0).ToUInt32(fn.Env);
    ASString text          = fn.Arg(1).ToString(fn.Env);
    bool     caseSensitive = fn.Arg(2).ToBool(fn.Env);
    String   query(text.ToCStr(), text.GetSize());
    fn.Result->SetInt(pthis->GetData().FindTextA(start, query.ToCStr(), caseSensitive));
}

void TextSnapshotProto::GetCount(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (pthis)
        fn.Result->SetUInt((unsigned)pthis->GetData().GetCharCount());
}

// TextSnapshot.getSelected(start[, end]): any character of the range selected.
void TextSnapshotProto::GetSelected(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 1)
        return;
    UInt32 start = fn.Arg(0).ToUInt32(fn.Env);
    UInt32 end   = (fn.NArgs > 1) ? fn.Arg(1).ToUInt32(fn.Env) : UInt32(pthis->GetData().GetCharCount());
    if (end <= start)
        end = start + 1;
    fn.Result->SetBool(pthis->GetData().IsSelected(start, end));
}

void TextSnapshotProto::GetSelectedText(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis)
        return;
    bool   inclLineEndings = (fn.NArgs > 0) ? fn.Arg(0).ToBool(fn.Env) : false;
    String text            = pthis->GetData().GetSelectedText(inclLineEndings);
    fn.Result->SetString(fn.Env->CreateString(text));
}

// TextSnapshot.getText(start, end[, includeLineEndings])
void TextSnapshotProto::GetText(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 2)
        return;
    UInt32 start           = fn.Arg(0).ToUInt32(fn.Env);
    UInt32 end             = fn.Arg(1).ToUInt32(fn.Env);
    bool   inclLineEndings = (fn.NArgs < 3) ? false : fn.Arg(2).ToBool(fn.Env);
    if (end <= start)
        end = start + 1;
    String text = pthis->GetData().GetSubString(start, end, inclLineEndings);
    fn.Result->SetString(fn.Env->CreateString(text));
}

// TextSnapshot.setSelectColor(rgb): always opaque.
void TextSnapshotProto::SetSelectColor(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 1)
        return;
    Render::Color color(fn.Arg(0).ToUInt32(fn.Env));
    color.SetAlpha(255);
    pthis->SetSelectColor(color);
}

// TextSnapshot.setSelected(start, end, select)
void TextSnapshotProto::SetSelected(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 3)
        return;
    UInt32 start  = fn.Arg(0).ToUInt32(fn.Env);
    UInt32 end    = fn.Arg(1).ToUInt32(fn.Env);
    bool   select = fn.Arg(2).ToBool(fn.Env);
    if (end <= start)
        end = start + 1;
    pthis->GetData().SetSelected(start, end, select);
}

// The depth as scripts see it: timeline depths start at -16384.
void AvmCharacter::CharacterGetDepth(const FnCall& fn)
{
    InteractiveObject* pcharacter = fn.ThisPtr->ToCharacter();
    if (!pcharacter)
        pcharacter = fn.Env->GetTarget();
    int depth = pcharacter->Depth;
    fn.Result->SetInt(depth - 16384);
}

void AvmSprite::SpritePlay(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        psprite->SetPlayState(State_Playing);
}

void AvmSprite::SpriteStop(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        psprite->SetPlayState(State_Stopped);
}

// Steps one frame (as far as loaded) and stops.
void AvmSprite::SpriteNextFrame(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    int loaded  = psprite->GetLoadingFrame();
    int current = psprite->GetCurrentFrame();
    if (current < loaded)
        psprite->GotoFrame(current + 1);
    psprite->SetPlayState(State_Stopped);
}

void AvmSprite::SpritePrevFrame(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    int current = psprite->GetCurrentFrame();
    if (current > 0)
        psprite->GotoFrame(current - 1);
    psprite->SetPlayState(State_Stopped);
}

// Bytes of the loaded frames, so that preloaders comparing it with getBytesTotal see the frames as there.
void AvmSprite::SpriteGetBytesLoaded(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        fn.Result->SetInt(psprite->GetBytesLoaded());
}

void AvmSprite::SpriteGetBytesTotal(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        fn.Result->SetInt(psprite->GetResourceMovieDef()->GetDataDef()->GetFileBytes());
}

// Unloading is a load of the empty url.
void AvmSprite::SpriteUnloadMovie(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        ToAS2Root(psprite)->AddLoadQueueEntry(psprite, "");
}

// Drops the drawing (and the cached hit result).
void AvmSprite::SpriteClear(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (psprite->GetDrawingContext())
        psprite->GetDrawingContext()->Clear();
    psprite->InvalidateHitResult();
    psprite->SetDirtyFlag();
}

// beginFill([rgb[, alpha 0..100]]): no colour ends the fill.
void AvmSprite::SpriteBeginFill(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs > 0)
    {
        UInt32 rgba = fn.Arg(0).ToUInt32(fn.Env) | 0xFF000000;
        if (fn.NArgs > 1)
        {
            float alpha = float(fn.Arg(1).ToNumber(fn.Env)) * 255.0f / 100.0f;
            rgba        = (UInt32(Alg::Max(0.0f, Alg::Min(alpha, 255.0f))) << 24) | (rgba & 0xFFFFFF);
        }
        FromSprite(psprite)->AcquirePath(true)->BeginSolidFill(rgba);
    }
    else
    {
        AvmSprite*      avm = FromSprite(psprite);
        DrawingContext* pdc = avm->GetDrawingContext();
        avm->AcquirePath(true);
        pdc->SetNoFill();
    }
}

void AvmSprite::SpriteEndFill(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        FromSprite(psprite)->AcquirePath(true)->EndFill();
}

// Pen moves take pixels; the drawing is in twips.
void AvmSprite::SpriteMoveTo(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite && fn.NArgs >= 2)
    {
        float           x   = float(fn.Arg(0).ToNumber(fn.Env));
        float           y   = float(fn.Arg(1).ToNumber(fn.Env));
        AvmSprite*      avm = FromSprite(psprite);
        DrawingContext* pdc = avm->AcquirePath(false);
        pdc->MoveTo(Render::PixelsToTwips(x), Render::PixelsToTwips(y));
        avm->GetSprite()->InvalidateHitResult();
    }
}

void AvmSprite::SpriteLineTo(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite && fn.NArgs >= 2)
    {
        float           x   = float(fn.Arg(0).ToNumber(fn.Env));
        float           y   = float(fn.Arg(1).ToNumber(fn.Env));
        AvmSprite*      avm = FromSprite(psprite);
        DrawingContext* pdc = avm->GetDrawingContext();
        pdc->LineTo(Render::PixelsToTwips(x), Render::PixelsToTwips(y));
        avm->GetSprite()->InvalidateHitResult();
    }
}

void AvmSprite::SpriteCurveTo(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite && fn.NArgs >= 4)
    {
        float      cx  = float(fn.Arg(0).ToNumber(fn.Env));
        float      cy  = float(fn.Arg(1).ToNumber(fn.Env));
        float      ax  = float(fn.Arg(2).ToNumber(fn.Env));
        float      ay  = float(fn.Arg(3).ToNumber(fn.Env));
        AvmSprite*      avm = FromSprite(psprite);
        DrawingContext* pdc = avm->GetDrawingContext();
        pdc->CurveTo(Render::PixelsToTwips(cx), Render::PixelsToTwips(cy), Render::PixelsToTwips(ax), Render::PixelsToTwips(ay));
        avm->GetSprite()->InvalidateHitResult();
    }
}

void AvmSprite::SpriteBeginGradientFill(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
    {
        DrawingContext*      pdc   = FromSprite(psprite)->AcquirePath(true);
        Render::ComplexFill* pfill = pdc->CreateNewComplexFill();
        pdc->BeginFill();
        if (pfill)
            SpriteCreateGradient(fn, pfill);
    }
}

// MS2-FUNCTIONAL the exe puts the GetMatrix temporary below the matrix local and keeps the fill type in ebp
// @0x1429072c0
void AvmSprite::SpriteBeginBitmapFill(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite && fn.NArgs > 0)
    {
        Ptr<Object> pobj = fn.Arg(0).ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_BitmapData)
        {
            ImageResource* pimageRes = static_cast<BitmapData*>(pobj.GetPtr())->pImageRes;
            if (pimageRes)
            {
                Render::Matrix2F mtx;
                if (fn.NArgs > 1)
                {
                    Object* pmobj = fn.Arg(1).ToObject(fn.Env);
                    if (pmobj && pmobj->GetObjectType() == Object_Matrix)
                        mtx = static_cast<MatrixObject*>(pmobj)->GetMatrix(fn.Env);
                }
                bool repeat    = true;
                bool smoothing = false;
                if (fn.NArgs > 2)
                {
                    repeat = fn.Arg(2).ToBool(fn.Env);
                    if (fn.NArgs > 3)
                        smoothing = fn.Arg(3).ToBool(fn.Env);
                }
                FillType fillType;
                if (smoothing)
                    fillType = repeat ? Fill_TiledSmoothImage : Fill_ClippedSmoothImage;
                else if (repeat)
                    fillType = Fill_TiledImage;
                else
                    fillType = Fill_ClippedImage;
                AvmSprite*      avm = FromSprite(psprite);
                DrawingContext* pdc = avm->GetDrawingContext();
                avm->GetSprite()->SetDirtyFlag();
                avm->GetSprite()->InvalidateHitResult();
                pdc->AcquirePath(true);
                pdc->BeginBitmapFill(fillType, pimageRes, mtx);
            }
        }
    }
}

void AvmSprite::SpriteLineGradientStyle(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
    {
        Render::ComplexFill* pfill = FromSprite(psprite)->AcquirePath(true)->CreateLineComplexFill();
        if (pfill)
            SpriteCreateGradient(fn, pfill);
    }
}

void AvmSprite::SpriteLineStyle(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs > 0)
    {
        float    lineWidth  = float(fn.Arg(0).ToNumber(fn.Env));
        UInt32   rgba       = 0xFF000000;
        bool     hinting    = false;
        unsigned scaling    = 0;
        unsigned caps       = 0;
        unsigned joins      = 0;
        float    miterLimit = 3.0f;
        if (fn.NArgs >= 2)
        {
            rgba = fn.Arg(1).ToUInt32(fn.Env) | 0xFF000000;
            if (fn.NArgs >= 3)
            {
                float alpha = float(fn.Arg(2).ToNumber(fn.Env)) * 255.0f / 100.0f;
                rgba        = (UInt32(Alg::Max(0.0f, Alg::Min(alpha, 255.0f))) << 24) | (rgba & 0xFFFFFF);
                if (fn.NArgs >= 4)
                {
                    hinting = fn.Arg(3).ToBool(fn.Env);
                    if (fn.NArgs >= 5)
                    {
                        ASString str = fn.Arg(4).ToString(fn.Env);
                        if (str == "none")
                            scaling = 6;
                        else if (str == "vertical")
                            scaling = 4;
                        else if (str == "horizontal")
                            scaling = 2;
                        if (fn.NArgs > 5)
                        {
                            str = fn.Arg(5).ToString(fn.Env);
                            if (str == "none")
                                caps = 0x140;
                            else if (str == "square")
                                caps = 0x280;
                            if (fn.NArgs > 6)
                            {
                                str = fn.Arg(6).ToString(fn.Env);
                                if (str == "miter")
                                    joins = 0x20;
                                else if (str == "bevel")
                                    joins = 0x10;
                                if (fn.NArgs > 7)
                                    miterLimit = Alg::Min(255.0f, Alg::Max(1.0f, float(fn.Arg(7).ToNumber(fn.Env))));
                            }
                        }
                    }
                }
            }
        }
        DrawingContext* pdc = FromSprite(psprite)->GetDrawingContext();
        pdc->ChangeLineStyle(Render::PixelsToTwips(lineWidth), rgba, hinting, scaling, caps, joins, miterLimit);
    }
    else
    {
        AvmSprite*      avm = FromSprite(psprite);
        DrawingContext* pdc = avm->GetDrawingContext();
        if (!pdc->NoLine())
        {
            avm->AcquirePath(false);
            pdc->SetNoLine();
        }
    }
}

// this is in the prototype chain of the argument (interfaces not counted).
void ObjectProto::IsPrototypeOf(const FnCall& fn)
{
    if (fn.NArgs >= 1 && !fn.ThisPtr->IsASCharacter())
    {
        Object*          pthis = (Object*)fn.ThisPtr;
        ObjectInterface* iobj  = fn.Arg(0).ToObjectInterface(fn.Env);
        if (iobj)
        {
            fn.Result->SetBool(iobj->InstanceOf(fn.Env, pthis, false));
            return;
        }
    }
    fn.Result->SetBool(false);
}

// "[type Function]", the target path of a character or "[object Object]".
// MS2-FUNCTIONAL the exe keeps the character handle of the temporary in a register and drops it unconditionally
// @0x142902880
void ObjectProto::ToString(const FnCall& fn)
{
    if (fn.ThisPtr->IsFunction())
        fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_typeFunction_));
    else if (fn.ThisPtr->IsASCharacter())
        fn.Result->SetString(Value(fn.ThisPtr->ToCharacter()).GetCharacterNamePath(fn.Env));
    else
        fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_objectObject_));
}

// addProperty(name, getter[, setter]): a member read and written through the functions.
// MS2-FUNCTIONAL the exe calls FnCall::Arg, Value::ToFunction and the ValueProperty constructor out of line for the
// setter and the property, ours inlines the first two and calls the constructor
// @0x142901d20
void ObjectProto::AddProperty(const FnCall& fn)
{
    if (fn.NArgs >= 2)
    {
        ASString    propName(fn.Arg(0).ToString(fn.Env));
        FunctionRef getter = fn.Arg(1).ToFunction(fn.Env);
        if (!getter.IsNull())
        {
            FunctionRef setter;
            if (fn.NArgs >= 3 && (fn.Arg(2).IsFunctionObject() || fn.Arg(2).IsFunctionName()))
                setter = fn.Arg(2).ToFunction(fn.Env);
            Value val(getter, setter, fn.Env->GetHeap(), fn.Env->GetCollector());
            fn.ThisPtr->SetMemberRaw(fn.Env->GetSC(), propName, val);
            fn.Result->SetBool(true);
        }
        else
            fn.Result->SetBool(false);
    }
    else
        fn.Result->SetBool(false);
}

// watch(name, callback[, userData]): the callback sees every assignment of the member.
// MS2-FUNCTIONAL the exe inlines SetLocalFrame into the function copy of ToFunction
// @0x1429024e0
void ObjectProto::Watch_(const FnCall& fn)
{
    if (fn.NArgs >= 2)
    {
        FunctionRef func = fn.Arg(1).ToFunction(fn.Env);
        if (!func.IsNull())
        {
            Value userData;
            if (fn.NArgs >= 3)
                userData = fn.Arg(2);
            fn.Result->SetBool(fn.ThisPtr->Watch(fn.Env->GetSC(), fn.Arg(0).ToString(fn.Env), func, userData));
        }
        else
            fn.Result->SetBool(false);
    }
    else
        fn.Result->SetBool(false);
}

void ObjectProto::Unwatch_(const FnCall& fn)
{
    if (fn.NArgs >= 1)
        fn.Result->SetBool(fn.ThisPtr->Unwatch(fn.Env->GetSC(), fn.Arg(0).ToString(fn.Env)));
    else
        fn.Result->SetBool(false);
}

// apply(thisObject[, argArray]): call with the arguments taken from an array.
// MS2-FUNCTIONAL register allocation; ours calls ~FunctionRef of the FnCall temporaries out of line
// @0x142902ae0
void FunctionProto::Apply(const FnCall& fn)
{
    Ptr<Object>            keepObject; // keeps this alive during the call
    Ptr<InteractiveObject> keepChar;
    ObjectInterface*       pthis = 0;
    int                    nargs = 0;

    fn.Result->SetUndefined();
    Ptr<ArrayObject> argArray;
    if (fn.NArgs >= 1)
    {
        pthis = fn.Arg(0).ToObjectInterface(fn.Env);
        if (pthis)
        {
            if (pthis->IsASCharacter())
                keepChar = pthis->ToCharacter();
            else
                keepObject = static_cast<Object*>(pthis);
        }
    }
    if (fn.NArgs >= 2)
    {
        Object* pobj = fn.Arg(1).ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == ObjectInterface::Object_Array)
        {
            argArray = static_cast<ArrayObject*>(pobj);
            nargs    = argArray->GetSize();
            if (nargs > 0)
            {
                for (int i = nargs - 1; i >= 0; i--)
                    fn.Env->Push(*argArray->GetElementPtr(i));
            }
        }
    }

    Value result;
    if (!fn.ThisFunctionRef.IsNull())
        fn.ThisFunctionRef.Invoke(FnCall(&result, pthis, fn.Env, nargs, fn.Env->GetTopIndex()));
    else
    {
        Ptr<FunctionObject> pfunc = static_cast<FunctionObject*>(fn.ThisPtr);
        pfunc->Invoke(FnCall(&result, pthis, fn.Env, nargs, fn.Env->GetTopIndex()), 0, 0);
    }
    if (nargs > 0)
        fn.Env->Drop(nargs);
    *fn.Result = result;
}

// call(thisObject, arg1, ...): the arguments go onto the stack again and the function runs with this set.
// MS2-FUNCTIONAL register allocation; ours calls ~FunctionRef of the FnCall temporaries out of line
// @0x142902f40
void FunctionProto::Call(const FnCall& fn)
{
    Ptr<Object>            keepObject; // keeps this alive during the call
    Ptr<InteractiveObject> keepChar;
    ObjectInterface*       pthis = 0;
    int                    nargs = 0;

    fn.Result->SetUndefined();
    if (fn.NArgs >= 1)
    {
        pthis = fn.Arg(0).ToObjectInterface(fn.Env);
        if (pthis)
        {
            if (pthis->IsASCharacter())
                keepChar = pthis->ToCharacter();
            else
                keepObject = static_cast<Object*>(pthis);
        }
    }
    if (fn.NArgs >= 2)
    {
        nargs = fn.NArgs - 1;
        for (int i = nargs; i >= 1; i--)
            fn.Env->Push(fn.Arg(i));
    }

    Value result;
    if (!fn.ThisFunctionRef.IsNull())
        fn.ThisFunctionRef.Invoke(FnCall(&result, pthis, fn.Env, nargs, fn.Env->GetTopIndex()));
    else
    {
        Ptr<FunctionObject> pfunc = static_cast<FunctionObject*>(fn.ThisPtr);
        pfunc->Invoke(FnCall(&result, pthis, fn.Env, nargs, fn.Env->GetTopIndex()), 0, 0);
    }
    if (nargs > 0)
        fn.Env->Drop(nargs);
    *fn.Result = result;
}

void FunctionProto::ToString(const FnCall& fn)
{
    fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_typeFunction_));
}

// The Stage methods that do nothing in GFx.
void GFx_StageFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// Instantiates ForEachChild_GC of a class for the three collector passes.
#define MS2_AS2_GC_FOR_EACH_CHILD(Class)                                                                        \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector * prcc) const;           \
    template void Class::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector * prcc) const;       \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector * prcc) const;

template<class Functor>
void FunctionRefBase::ForEachChild_GC(Collector* prcc) const
{
    if (Function)
        Functor::Call(prcc, Function);
    if (pLocalFrame)
        Functor::Call(prcc, pLocalFrame);
}
MS2_AS2_GC_FOR_EACH_CHILD(FunctionRefBase)

template<class Functor>
void Value::ForEachChild_GC(Collector* prcc) const
{
    if (IsFunctionObject())
        V.FunctionValue.template ForEachChild_GC<Functor>(prcc);
    else if (IsObject() && V.pObjectValue)
        Functor::Call(prcc, V.pObjectValue);
    else if (IsProperty())
        Functor::Call(prcc, V.pProperty);
}
MS2_AS2_GC_FOR_EACH_CHILD(Value)

template<class Functor>
void Object::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Member>::ConstIterator it = Members.Begin();
    while (it != Members.End())
    {
        const Value& value = it->Second.GetMemberValue();
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    ResolveHandler.template ForEachChild_GC<Functor>(prcc);
    if (pWatchpoints)
    {
        ASStringHash_GC<Watchpoint>::ConstIterator wit = pWatchpoints->Begin();
        while (wit != pWatchpoints->End())
        {
            const Watchpoint& wp = wit->Second;
            wp.template ForEachChild_GC<Functor>(prcc);
            ++wit;
        }
    }
    if (pProto)
        Functor::Call(prcc, pProto);
}
MS2_AS2_GC_FOR_EACH_CHILD(Object)

template<class Functor>
void LocalFrame::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Value>::ConstIterator it = Variables.Begin();
    while (it != Variables.End())
    {
        const Value& value = it->Second;
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    if (PrevFrame)
        Functor::Call(prcc, PrevFrame);
    Callee.template ForEachChild_GC<Functor>(prcc);
    Caller.template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(LocalFrame)

template<class Functor>
void ArrayObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<Functor>(prcc);
    }
}
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// The mark pass copy, which the exe does not inline into the prototype (the other two it does).
template<>
__declspec(noinline) void ArrayObject::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const
{
    Object::template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    }
}

MS2_AS2_GC_FOR_EACH_CHILD(SuperObject)

// Never inlined into the prototype in the exe.
template<class Functor>
__declspec(noinline) void TransformObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    if (Matrix)
        Functor::Call(prcc, Matrix);
    if (pColorTransform)
        Functor::Call(prcc, pColorTransform);
    if (PixelBounds)
        Functor::Call(prcc, PixelBounds);
}
MS2_AS2_GC_FOR_EACH_CHILD(TransformObject)

template<class Functor>
void MouseCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    SetCursorTypeFunc.template ForEachChild_GC<Functor>(prcc);
    if (pListenersArray)
        Functor::Call(prcc, pListenersArray);
    CFunctionObject::template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(MouseCtorFunction)

template<class Functor>
void SharedObjectCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    ASStringHash_GC<SharedObjectPtr>::ConstIterator it = SharedObjects.Begin();
    while (it != SharedObjects.End())
    {
        const SharedObjectPtr& pobj = it->Second;
        pobj.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
}
MS2_AS2_GC_FOR_EACH_CHILD(SharedObjectCtorFunction)

// The built-in prototypes.
#define MS2_AS2_GC_PROTOTYPE(Class) MS2_AS2_GC_FOR_EACH_CHILD(Prototype<Class>)

MS2_AS2_GC_PROTOTYPE(AmpMarker)
MS2_AS2_GC_PROTOTYPE(ArrayObject)
MS2_AS2_GC_PROTOTYPE(Selection)
MS2_AS2_GC_PROTOTYPE(ColorMatrixFilterObject)
MS2_AS2_GC_PROTOTYPE(SharedObject)
MS2_AS2_GC_PROTOTYPE(BevelFilterObject)
MS2_AS2_GC_PROTOTYPE(BlurFilterObject)
MS2_AS2_GC_PROTOTYPE(GlowFilterObject)
MS2_AS2_GC_PROTOTYPE(DropShadowFilterObject)
MS2_AS2_GC_PROTOTYPE(BitmapFilterObject)
MS2_AS2_GC_PROTOTYPE(BooleanObject)
MS2_AS2_GC_PROTOTYPE(TextSnapshotObject)
MS2_AS2_GC_PROTOTYPE(DateObject)
MS2_AS2_GC_PROTOTYPE(StringObject)
MS2_AS2_GC_PROTOTYPE(ExternalInterface)
MS2_AS2_GC_PROTOTYPE(ColorObject)
MS2_AS2_GC_PROTOTYPE(MouseObject)
MS2_AS2_GC_PROTOTYPE(NumberObject)
MS2_AS2_GC_PROTOTYPE(KeyObject)
MS2_AS2_GC_PROTOTYPE(AsBroadcaster)
MS2_AS2_GC_PROTOTYPE(Math)
MS2_AS2_GC_PROTOTYPE(ButtonObject)
MS2_AS2_GC_PROTOTYPE(BitmapData)
MS2_AS2_GC_PROTOTYPE(TextFieldObject)
MS2_AS2_GC_PROTOTYPE(StageObject)
MS2_AS2_GC_PROTOTYPE(PointObject)
MS2_AS2_GC_PROTOTYPE(RectangleObject)
MS2_AS2_GC_PROTOTYPE(MatrixObject)
MS2_AS2_GC_PROTOTYPE(LoadVarsObject)
MS2_AS2_GC_PROTOTYPE(Object)
MS2_AS2_GC_PROTOTYPE(MovieClipLoader)
MS2_AS2_GC_PROTOTYPE(StyleSheetObject)
MS2_AS2_GC_PROTOTYPE(MovieClipObject)
MS2_AS2_GC_PROTOTYPE(TextFormatObject)
MS2_AS2_GC_PROTOTYPE(ColorTransformObject)
MS2_AS2_GC_PROTOTYPE(TransformObject)

// The two-slot head of the Movie interface MovieImpl starts with (gfx_movie.h is not recovered).
struct ActionLoggerMovie
{
    virtual void      Unused0()           = 0;
    virtual MovieDef* GetMovieDef() const = 0; // 1
};

// MS2-FUNCTIONAL 0x142917910: the exe saves rsi only on the suffix path and keeps suffix in rbp; same flag logic and stores
ActionLogger::ActionLogger(DisplayObject* ptarget, const char* suffix)
{
    MovieImpl* pm = ptarget->FindMovieImpl();
    VerboseAction       = (pm->Flags >> 2) & 1;
    LogSuffix           = suffix;
    VerboseActionErrors = !((pm->Flags >> 6) & 1);
    UseSuffix = suffix ? ((strcmp(((ActionLoggerMovie*)pm)->GetMovieDef()->GetFileURL(), LogSuffix) == 0
                               ? (pm->Flags >> 3) : (pm->Flags >> 4)) & 1)
                       : false;
    if (!((pm->Flags >> 1) & 1))
        pm->pCachedLog = pm->GetStateBag()->GetLog();
    pLog = pm->pCachedLog;

    // Only the file name of the suffix path.
    if (UseSuffix && !((pm->Flags >> 5) & 1))
    {
        SPInt len = (SPInt)strlen(suffix);
        if (len > 0)
        {
            const char* p = LogSuffix + len;
            while (*p != '/' && *p != '\\')
            {
                --p;
                if (p <= LogSuffix)
                    return;
            }
            LogSuffix = p + 1;
        }
    }
}

ActionBuffer::ActionBuffer(ASStringContext* psc, ActionBufferData* pbufferData)
    : pBufferData(pbufferData), Dictionary(psc->GetBuiltin(ASBuiltin_empty_)), DeclDictProcessedAt(-1)
{
}

AmpMarker::AmpMarker(Environment* penv) : Object(penv)
{
    // commonInit inlined: the call goes through the vftable.
    ObjectInterface* pthis = this;
    pthis->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Amp));
}

// A BitmapData of the image exported under linkageId by the movie of the target.
// MS2-FUNCTIONAL 0x142914770: the String instance; the exe swaps rbx/rdi for the movie and the string data
template<class T>
BitmapData* GFx_LoadBitmap(Environment* penv, const T& linkageId)
{
    Ptr<ImageResource> pimg = penv->GetTarget()->GetMovieImpl()->GetImageResourceByLinkageId(penv->GetTarget()->GetResourceMovieDef(),
                                                              linkageId.ToCStr());
    if (!pimg)
    {
        penv->LogScriptWarning("BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"",
                               linkageId.ToCStr());
        return 0;
    }
    Ptr<MovieDef> pmd = penv->GetTarget()->GetResourceMovieDef();
    if (!pmd)
        return 0;
    BitmapData* pbmp = SF_HEAP_NEW(penv->GetHeap()) BitmapData(penv);
    pbmp->SetImage(penv, pimg, pmd);
    return pbmp;
}
template BitmapData* GFx_LoadBitmap<ASString>(Environment*, const ASString&);
template BitmapData* GFx_LoadBitmap<String>(Environment*, const String&);

template Prototype<Object, Environment>::Prototype(ASStringContext*, Object*, const FunctionRef&);

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// The string-keyed hashes of AS2: insertion of a node or a node reference, exact and case-insensitive lookup, and
// the entry copies the rehash calls out of line.
#define MS2_AS2_STRING_HASH_ADD(U, K)                                                                            \
    template void GFx::ASStringHash_GC<U>::SetType::add<K>(void*, const K&, UPInt);
#define MS2_AS2_STRING_HASH_FIND(U)                                                                              \
    template SPInt GFx::ASStringHash_GC<U>::SetType::findIndexAlt<GFx::ASString>(const GFx::ASString&) const;   \
    template SPInt GFx::ASStringHash_GC<U>::SetType::findIndexAlt<GFx::ASStringNoCaseKey>(                      \
        const GFx::ASStringNoCaseKey&) const;

MS2_AS2_STRING_HASH_ADD(GFx::AS2::SharedObjectPtr, GFx::ASStringHash_GC<GFx::AS2::SharedObjectPtr>::NodeType)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Value, GFx::ASStringHash_GC<GFx::AS2::Value>::NodeType)
MS2_AS2_STRING_HASH_ADD(char, GFx::ASStringHash_GC<char>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::SharedObjectPtr, GFx::ASStringHash_GC<GFx::AS2::SharedObjectPtr>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Value, GFx::ASStringHash_GC<GFx::AS2::Value>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Object::Watchpoint, GFx::ASStringHash_GC<GFx::AS2::Object::Watchpoint>::NodeType)
// MS2-FUNCTIONAL the exe inlines CheckExpand here (pinned below)
// @0x142915300
MS2_AS2_STRING_HASH_ADD(GFx::AS2::FunctionRef, GFx::ASStringHash_GC<GFx::AS2::FunctionRef>::NodeType)
// (pinned below)
// @0x1429154d0
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Member, GFx::ASStringHash_GC<GFx::AS2::Member>::NodeType)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Object::Watchpoint, GFx::ASStringHash_GC<GFx::AS2::Object::Watchpoint>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::FunctionRef, GFx::ASStringHash_GC<GFx::AS2::FunctionRef>::NodeType::NodeRef)
// (pinned below)
// @0x1429164b0
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Member, GFx::ASStringHash_GC<GFx::AS2::Member>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Object::Watchpoint)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::FunctionRef)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Member)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Value)

// Entry copies of the rehash.
#define MS2_AS2_STRING_HASH_ENTRY_COPY(U)                                                                       \
    template HashsetNodeEntry<GFx::ASStringHash_GC<U>::NodeType, GFx::ASStringHash_GC<U>::NodeType::NodeHashF>::    \
        HashsetNodeEntry(const HashsetNodeEntry<GFx::ASStringHash_GC<U>::NodeType,                             \
                                                GFx::ASStringHash_GC<U>::NodeType::NodeHashF>&);

MS2_AS2_STRING_HASH_ENTRY_COPY(GFx::AS2::FunctionRef)
MS2_AS2_STRING_HASH_ENTRY_COPY(GFx::AS2::Object::Watchpoint)
MS2_AS2_STRING_HASH_ENTRY_COPY(GFx::AS2::Member)

// The standard member names of the global context (ASStringHash<char>: the allocator is keyed by the string).
typedef HashNode<GFx::ASString, char, GFx::ASStringHashFunctor> MS2_AS2StandardMemberNode;
typedef HashLH<GFx::ASString, char, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem, MS2_AS2StandardMemberNode,
               HashsetNodeEntry<MS2_AS2StandardMemberNode, MS2_AS2StandardMemberNode::NodeHashF> >
    MS2_AS2StandardMemberHash;
template void decltype(MS2_AS2StandardMemberHash::mHash)::BaseType::add<MS2_AS2StandardMemberNode>(
    void*, const MS2_AS2StandardMemberNode&, UPInt);

// The ExternalInterface callbacks of a movie (ASStringHash<InvokeAliasInfo>).
typedef HashNode<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor> MS2_AS2InvokeAliasNode;
typedef HashLH<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem,
               MS2_AS2InvokeAliasNode, HashsetNodeEntry<MS2_AS2InvokeAliasNode, MS2_AS2InvokeAliasNode::NodeHashF> >
    MS2_AS2InvokeAliasHash;
template void decltype(MS2_AS2InvokeAliasHash::mHash)::BaseType::add<MS2_AS2InvokeAliasNode>(
    void*, const MS2_AS2InvokeAliasNode&, UPInt);
template void decltype(MS2_AS2InvokeAliasHash::mHash)::BaseType::add<MS2_AS2InvokeAliasNode::NodeRef>(
    void*, const MS2_AS2InvokeAliasNode::NodeRef&, UPInt);

// The load progress of the movies of a MovieClipLoader by URL (StringHashLH<ProgressDesc>).
typedef StringHashLH<GFx::AS2::MovieClipLoader::ProgressDesc> MS2_AS2ProgressHash;
typedef StringLH_HashNode<GFx::AS2::MovieClipLoader::ProgressDesc, String::NoCaseHashFunctor> MS2_AS2ProgressNode;
template void decltype(MS2_AS2ProgressHash::mHash)::BaseType::add<MS2_AS2ProgressNode::NodeRef>(
    void*, const MS2_AS2ProgressNode::NodeRef&, UPInt);

// The images of a text field's HTML by name (StringHashLH<Ptr<Render::Text::ImageDesc>>).
namespace Render { namespace Text { struct ImageDesc; } } // render/text_core.h
typedef StringHashLH<Ptr<Render::Text::ImageDesc> > MS2_AS2TextImageHash;
template SPInt decltype(MS2_AS2TextImageHash::mHash)::BaseType::findIndexAlt<String>(const String&) const;

// Array.sort / Array.sortOn over the element pointers.
template bool Alg::QuickSortSafe<Alg::ArrayAdaptor<GFx::AS2::Value*>, GFx::AS2::ArraySortFunctor>(
    Alg::ArrayAdaptor<GFx::AS2::Value*>&, GFx::AS2::ArraySortFunctor);
// MS2-FUNCTIONAL the exe inlines ~ArraySortOnFunctor (calling the ArrayDataBase dtor of the functor array), cl
// calls it out of line; same for QuickSortSlicedSafe<..., ArraySortOnFunctor> (exe 0x142914bd0).
// @0x1429148e0
template bool Alg::QuickSortSafe<Alg::ArrayAdaptor<GFx::AS2::Value*>, GFx::AS2::ArraySortOnFunctor>(
    Alg::ArrayAdaptor<GFx::AS2::Value*>&, GFx::AS2::ArraySortOnFunctor);

// The event handler table of a character (EventId -> handlers).
typedef HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
               GFx::AS2::StatMV_ActionScript_Mem>
    MS2_AS2EventHandlerHash;
template SPInt decltype(MS2_AS2EventHandlerHash::mHash)::BaseType::findIndexAlt<GFx::EventId>(const GFx::EventId&) const;
typedef decltype(MS2_AS2EventHandlerHash::mHash)::BaseType MS2_AS2EventHandlerSet;
typedef HashNode<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor>
    MS2_AS2EventHandlerNode;
// MS2-FUNCTIONAL the exe inlines CheckExpand and assigns the EventId field by field (pinned below)
// @0x1429159d0
template void MS2_AS2EventHandlerSet::add<MS2_AS2EventHandlerNode>(void*, const MS2_AS2EventHandlerNode&, UPInt);
// MS2-FUNCTIONAL as the node add (pinned below)
// @0x142916a70
template void MS2_AS2EventHandlerSet::add<MS2_AS2EventHandlerHash::NodeRef>(void*, const MS2_AS2EventHandlerHash::NodeRef&,
                                                                          UPInt);

// Object* -> Object* identity map.
typedef HashNode<GFx::AS2::Object*, GFx::AS2::Object*, IdentityHash<GFx::AS2::Object*> > MS2_AS2ObjectIdentityNode;
typedef Hash<GFx::AS2::Object*, GFx::AS2::Object*, IdentityHash<GFx::AS2::Object*>, AllocatorGH<GFx::AS2::Object*>,
             MS2_AS2ObjectIdentityNode, HashsetNodeEntry<MS2_AS2ObjectIdentityNode, MS2_AS2ObjectIdentityNode::NodeHashF> >
    MS2_AS2ObjectIdentityHash;
template void decltype(MS2_AS2ObjectIdentityHash::mHash)::BaseType::add<MS2_AS2ObjectIdentityHash::NodeRef>(
    void*, const MS2_AS2ObjectIdentityHash::NodeRef&, UPInt);

// Copy of a value array (the ArrayLH<Value> data).
// MS2-FUNCTIONAL the exe calls ResizeNoConstruct out of line (pinned below)
// @0x1429175f0
template ArrayData<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, ArrayDefaultPolicy>::ArrayData(
    const ArrayData<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, ArrayDefaultPolicy>&);

// Two-argument message format (text, then a C string).
template UPInt Format<StringDataPtr, const char*>(const MsgFormat::Sink&, const char*, const StringDataPtr&,
                                                  const char* const&);

} // namespace Scaleform

// MS2-PIN: ??_7SharedObjectPtr@AS2@GFx@Scaleform@@6B@ 0x14321dd78
// MS2-PIN: ??0?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAA@AEBV01@@Z 0x142917700
// MS2-PIN: ??$add@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@1@_K@Z 0x142915300
// MS2-PIN: ??$add@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@1@_K@Z 0x1429154d0
// MS2-PIN: ??$add@UNodeRef@?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@1@_K@Z 0x1429164b0
// MS2-PIN: ??0?$ArrayData@VValue@AS2@GFx@Scaleform@@U?$AllocatorLH@VValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@AEBU01@@Z 0x1429175f0
// MS2-PIN: ??$add@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@1@_K@Z 0x1429159d0
// MS2-PIN: ??$add@UNodeRef@?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@1@_K@Z 0x142916a70
// MS2-PIN: ??$Format@VStringDataPtr@Scaleform@@PEBD@Scaleform@@YA_KAEBVSink@MsgFormat@0@PEBDAEBVStringDataPtr@0@AEBQEBD@Z 0x142914500
// MS2-PIN: ??$QuickSortSafe@V?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@Alg@Scaleform@@VArraySortFunctor@AS2@GFx@3@@Alg@Scaleform@@YA_NAEAV?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@01@VArraySortFunctor@AS2@GFx@1@@Z 0x142914880
// MS2-PIN: ??$QuickSortSafe@V?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@Alg@Scaleform@@VArraySortOnFunctor@AS2@GFx@3@@Alg@Scaleform@@YA_NAEAV?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@01@VArraySortOnFunctor@AS2@GFx@1@@Z 0x1429148e0
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@Alg@Scaleform@@VArraySortFunctor@AS2@GFx@3@@Alg@Scaleform@@YA_NAEAV?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@01@_K1VArraySortFunctor@AS2@GFx@1@@Z 0x142914940
// MS2-PIN: ??$QuickSortSlicedSafe@V?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@Alg@Scaleform@@VArraySortOnFunctor@AS2@GFx@3@@Alg@Scaleform@@YA_NAEAV?$ArrayAdaptor@PEAVValue@AS2@GFx@Scaleform@@@01@_K1VArraySortOnFunctor@AS2@GFx@1@@Z 0x142914bd0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7ActionLogger@AS2@GFx@Scaleform@@6B@ 0x143215ac0
// MS2-PIN: ??_7ActionBuffer@AS2@GFx@Scaleform@@6B@ 0x1432153c8
// MS2-PIN: ??_7?$RefCountBaseNTS@VActionBuffer@AS2@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x143183600
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x143183600
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7AmpMarker@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321deb8
// MS2-PIN: ??_7AmpMarker@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321df00
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??0ActionLogger@AS2@GFx@Scaleform@@QEAA@PEAVDisplayObject@23@PEBD@Z 0x142917910
// MS2-PIN: ??$GFx_LoadBitmap@VString@Scaleform@@@AS2@GFx@Scaleform@@YAPEAVBitmapData@012@PEAVEnvironment@012@AEBVString@2@@Z 0x142914770
// MS2-PIN: ??_7?$LogBase@VActionLogger@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b5018
