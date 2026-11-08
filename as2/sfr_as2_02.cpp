// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector traversals
// (ForEachChild_GC of the collectable classes and of every built-in prototype, for the release, mark-in-cycle and
// scan-in-use passes) and the Stage function stub.
// MS2-UNIT: sfr_as2_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428fdc00-0x1428ff660 .text$mn
// MS2-RANGE: 0x1428ffcd0-0x1429006a0 .text$mn
// MS2-RANGE: 0x142900f50-0x142900fc0 .text$mn
// MS2-RANGE: 0x142901ae0-0x142902a00 .text$mn
// MS2-RANGE: 0x142902a00-0x142902a0d .text$mn
// MS2-RANGE: 0x142902a10-0x1429033c0 .text$mn
// MS2-RANGE: 0x1429033c0-0x1429049b0 .text$mn
// MS2-RANGE: 0x142905d70-0x142905e00 .text$mn
// MS2-RANGE: 0x142906330-0x1429064b0 .text$mn
// MS2-RANGE: 0x142906a90-0x142906d80 .text$mn
// MS2-RANGE: 0x142906d80-0x142906fc0 .text$mn
// MS2-RANGE: 0x142906fc0-0x142908840 .text$mn
// MS2-RANGE: 0x142908c30-0x142908e90 .text$mn
// MS2-RANGE: 0x14290bed0-0x142914500 .text$mn
// MS2-RANGE: 0x142914500-0x142914660 .text$mn
// MS2-RANGE: 0x142914660-0x142914880 .text$mn
// MS2-RANGE: 0x142914880-0x142914e60 .text$mn
// MS2-RANGE: 0x142914e60-0x142917780 .text$mn
// MS2-RANGE: 0x142917780-0x142917bf0 .text$mn
// MS2-RANGE: 0x142905b80-0x142905d70 .text$mn
// MS2-RANGE: 0x1429064b0-0x142906650 .text$mn
// MS2-RANGE: 0x1429069f0-0x142906a90 .text$mn
// MS2-RANGE: 0x142905e00-0x142906040 .text$mn
// MS2-RANGE: 0x142905a00-0x142905b80 .text$mn
// MS2-RANGE: 0x1429055f0-0x142905a00 .text$mn
// MS2-RANGE: 0x142906650-0x1429069f0 .text$mn
// MS2-RANGE: 0x142901150-0x142901276 .text$mn
// MS2-RANGE: 0x142900fc0-0x14290114c .text$mn
//
// MS2-RANGE: 0x142908e90-0x142909300 .text$mn
// MS2-RANGE: 0x1428ffa20-0x1428ffcca .text$mn
// MS2-RANGE: 0x1428ff660-0x1428ffa19 .text$mn
// MS2-RANGE: 0x142908840-0x142908a68 .text$mn
// MS2-RANGE: 0x142908a70-0x142908c2c .text$mn
// MS2-RANGE: 0x142906040-0x14290632c .text$mn
// MS2-RANGE: 0x1429049b0-0x142905183 .text$mn
// MS2-RANGE: 0x142901410-0x142901a70 .text$mn
// MS2-RANGE: 0x142905190-0x1429055e9 .text$mn
// MS2-RANGE: 0x14290a0f0-0x14290a17c .text$mn
// MS2-RANGE: 0x14290a180-0x14290a8b4 .text$mn
// MS2-RANGE: 0x14290a8c0-0x14290aab4 .text$mn
// MS2-RANGE: 0x14290b1c0-0x14290b2b4 .text$mn
// MS2-RANGE: 0x14290b920-0x14290b9e5 .text$mn
// MS2-RANGE: 0x14290aac0-0x14290afbc .text$mn
// MS2-RANGE: 0x14290afc0-0x14290b1be .text$mn
// MS2-RANGE: 0x14290b9f0-0x14290bb16 .text$mn
// MS2-RANGE: 0x14290bb20-0x14290bc49 .text$mn
// MS2-RANGE: 0x14290bc50-0x14290bd8d .text$mn
// MS2-RANGE: 0x14290bd90-0x14290becd .text$mn
// MS2-RANGE: 0x142909b00-0x142909d71 .text$mn
// MS2-RANGE: 0x142909d80-0x14290a0ea .text$mn
// MS2-RANGE: 0x142909300-0x142909586 .text$mn
// MS2-RANGE: 0x142909590-0x1429096d1 .text$mn
// MS2-RANGE: 0x1429096e0-0x1429099ca .text$mn
// MS2-RANGE: 0x1429099d0-0x142909af3 .text$mn
// MS2-RANGE: 0x14290b2c0-0x14290b4b7 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

// (the TextSnapshotObject ctor, 0x1429231e0, is defined in sfr_as2_03)
#define MS2_SF_STRING_SDK_GETDATA            // String::GetData in the SDK union form (register allocation)
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
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
#include "../include/gfx/as2/as2_hashaccess.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/video/video_statebag.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"
#include "../include/render/render_screentoworld.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"
#include "../include/gfx/text_editorkit.h"
#include "../include/gfx/text_stylesheet.h" // Text::StyleManager complete: StyleSheetObject's implicit destructor calls ~StyleManager
namespace Scaleform { namespace GFx { class ASSoundIntf; }
// 0x1425dcaf0, a bare ret: the exe folds the empty body the callers below call out of line into this instance.
// Declared as a specialization, so cl calls it by name instead of inlining the header's empty body.
template<> void ConstructorMov<GFx::ASSoundIntf*>::Construct(void*); }

void FUN_14000d250(Scaleform::GFx::AS2::Value* value, double number);         // Value::SetNumber, out of line (sfr_video_01)
// The DocView / EditorKit fields the clipboard natives read.
inline void* DocView_GetEditorKit(void* pdoc) { return *(void**)((char*)pdoc + 0xd8); }
inline unsigned long long DocView_SelectionPos(void* pdoc, int i) { return ((unsigned long long*)((char*)pdoc + 0x38))[i]; }
inline unsigned long long DocView_GetBeginSelection(void* pdoc)
{
    return Scaleform::Alg::PMin(DocView_SelectionPos(pdoc, 0), DocView_SelectionPos(pdoc, 1));
}
inline unsigned long long DocView_GetEndSelection(void* pdoc)
{
    return Scaleform::Alg::PMax(DocView_SelectionPos(pdoc, 0), DocView_SelectionPos(pdoc, 1));
}
inline void* EditorKit_GetDocView(void* pek) { return *(void**)((char*)pek + 0x10); }
inline bool  EditorKit_DoesUseRichClipboard(void* pek) { return (*((unsigned char*)pek + 0xa0) & 4) != 0; }
inline void* DocView_GetStyledText(void* pdoc) { return *(void**)((char*)pdoc + 0x10); }
inline const void* StyledText_GetDefaultParagraphFormat(void* pst) { return *(const void**)((char*)pst + 0x30); }
inline const void* StyledText_GetDefaultTextFormat(void* pst) { return *(const void**)((char*)pst + 0x38); }
namespace Scaleform { struct MS2_ImageSubstElement; typedef ArrayDataBase<MS2_ImageSubstElement, AllocatorLH<MS2_ImageSubstElement, 2>, ArrayDefaultPolicy> As202SubstArr; template<> As202SubstArr::~ArrayDataBase(); } // (C3) FUN_1424c7090 = its dtor (sfr_as3_15, out of line)
inline void* DocView_GetImageSubstitutor(void* pdoc) { return *(void**)((char*)pdoc + 0x30); }
inline void  DocView_SetImageSubstitutor(void* pdoc, void* psubst) { *(void**)((char*)pdoc + 0x30) = psubst; }
inline void  DocView_SetReformatReq(void* pdoc) { *((unsigned char*)pdoc + 0x14b) |= 2; }

namespace Scaleform {
// StyledText::HTMLImageTagInfo: the same stand-in as sfr_as3_14 / sfr_as3_15 (the ArrayDataBase destructor
// instantiation is the exe's 0x1424c7100).
struct MS2_HTMLImageTagInfo // 0x40 bytes
{
    Ptr<RefCountNTSImpl> pTextImageDesc;
    StringDH             Url; // +0x08
    StringDH             Id;  // +0x18
    unsigned             Width, Height;
    int                  VSpace, HSpace;
    unsigned             ParaId;
    UByte                Alignment;
};
} // namespace Scaleform

namespace Scaleform { namespace GFx {
template<> void LogBase<AS2::FnCall>::LogScriptWarning(const char* pfmt, ...) const;   // sfr_as2_06 @0x142968210
extern template void LogBase<DisplayObjectBase>::LogScriptWarning(const char* pfmt, ...) const;
template<> AS2::FunctionRef*
ASStringHashBase<AS2::FunctionRef, HashUncachedLH<ASString, AS2::FunctionRef, ASStringHashFunctor, StatMV_ASString_Mem> >::GetCaseCheck(
    const ASString& key, bool caseSensitive);    // sfr_as2_05 @0x142949f60
}}

namespace Scaleform { namespace GFx { namespace AS3 {
// InteractiveObject::ModifyOptimizedPlayList, out of line in the exe (sfr_as3_18 @0x142517e70).
void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);
}}}

namespace Scaleform { namespace GFx { namespace AS2 {

typedef ASRefCountBaseType::Collector Collector;

Value* ArgCopy(const FnCall* pfn, int n);    // sfr_as2_04e @0x1429316c0, FnCall::Arg out of line

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
        if (fn.NArgs > 1)
        {
            rgba = fn.Arg(1).ToUInt32(fn.Env) | 0xFF000000;
            if (fn.NArgs > 2)
            {
                float alpha = float(fn.Arg(2).ToNumber(fn.Env)) * 255.0f / 100.0f;
                rgba        = (UInt32(Alg::Max(0.0f, Alg::Min(alpha, 255.0f))) << 24) | (rgba & 0xFFFFFF);
                if (fn.NArgs > 3)
                {
                    hinting = fn.Arg(3).ToBool(fn.Env);
                    if (fn.NArgs > 4)
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

// A frame label or a 1-based frame number; unknown labels are ignored.
void AvmSprite::SpriteGotoAndStop(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        psprite->LogScriptError("AvmSprite::SpriteGotoAndStop needs one arg");
        return;
    }
    const Value& arg = fn.Arg(0);
    unsigned frame = unsigned(-1);
    if (arg.IsString())
    {
        ASString label = arg.ToString(fn.Env);
        if (!psprite->GetLabeledFrame(label.ToCStr(), &frame))
            return;
    }
    else
        frame = arg.ToUInt32(fn.Env) - 1;
    psprite->GotoFrame(frame);
    psprite->SetPlayState(State_Stopped);
}

void AvmSprite::SpriteGotoAndPlay(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        psprite->LogScriptError("AvmSprite::SpriteGotoAndPlay needs one arg");
        return;
    }
    const Value& arg = fn.Arg(0);
    unsigned frame = unsigned(-1);
    if (arg.IsString())
    {
        ASString label = arg.ToString(fn.Env);
        if (!psprite->GetLabeledFrame(label.ToCStr(), &frame))
            return;
    }
    else
        frame = arg.ToUInt32(fn.Env) - 1;
    psprite->GotoFrame(frame);
    psprite->SetPlayState(State_Playing);
}

// Only clips at script depths (>= 0) can be removed.
void AvmSprite::SpriteRemoveMovieClip(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (psprite->Depth < 16384)
        psprite->LogScriptWarning("%s.removeMovieClip() failed - depth must be >= 0", psprite->GetName().ToCStr());
    else
        psprite->InteractiveObject::RemoveDisplayObject();
}

// @0x142906330
void AvmSprite::SpriteGetNextHighestDepth(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
    {
        int depth = Alg::Max(0, psprite->mDisplayList.GetLargestDepthInUse() - 16383);
        fn.Result->SetInt(depth);
    }
}

void AvmSprite::SpriteGetInstanceAtDepth(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite && fn.NArgs >= 1)
    {
        int depth = int(fn.Arg(0).ToNumber(fn.Env)) + 16384;
        DisplayObjectBase* pch = psprite->GetCharacterAtDepth(depth);
        if (pch)
            fn.Result->SetAsCharacter(pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0);
    }
}

// null or a non-sprite removes the mask.
void AvmSprite::SpriteSetMask(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 1)
        return;
    if (!fn.Arg(0).IsNull())
    {
        InteractiveObject* pch = fn.Arg(0).ToCharacter(fn.Env);
        if (pch)
        {
            psprite->SetMask(pch->IsSprite() ? static_cast<Sprite*>(pch) : 0);
            return;
        }
    }
    psprite->SetMask(0);
}

// @0x1428ffcd0
void SelectionCtorFunction::GetFocus(const FnCall& fn)
{
    fn.Result->SetNull();
    if (!fn.Env)
        return;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 1)
        controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> focusedChar = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (focusedChar)
        fn.Result->SetString(focusedChar->GetCharacterHandle()->NamePath);
}

// Value::ToCharacter, expanded in place where the exe has it inline.
static inline InteractiveObject* ResolveCharacterValue(const Value& val, const Environment* penv)
{
    if (val.IsCharacter() && penv && val.V.pCharHandle)
    {
        DisplayObject* pdisp = val.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
        if (pdisp)
            return pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
    }
    return 0;
}

// @0x1428ffe30
void SelectionCtorFunction::SetFocus(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (fn.NArgs < 1 || !fn.Env)
        return;
    Ptr<InteractiveObject> newFocus;
    if (fn.Arg(0).IsString())
    {
        Value val;
        if (fn.Env->FindVariable(Environment::GetVarParams(fn.Arg(0).ToString(fn.Env), &val)))
            newFocus = ResolveCharacterValue(val, fn.Env);
    }
    else
        newFocus = fn.Arg(0).ToCharacter(fn.Env);
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 2)
        controllerIdx = fn.Arg(1).ToUInt32(fn.Env);
    if (newFocus)
    {
        if (newFocus->IsFocusEnabled(GFx_FocusMovedByKeyboard))
        {
            fn.Env->GetTarget()->GetMovieImpl()->SetKeyboardFocusTo(newFocus, controllerIdx, GFx_FocusMovedByKeyboard);
            fn.Result->SetBool(true);
        }
    }
    else
    {
        fn.Env->GetTarget()->GetMovieImpl()->SetKeyboardFocusTo(0, controllerIdx, GFx_FocusMovedByKeyboard);
        fn.Result->SetBool(true);
    }
}

// The AS2 Selection natives reach the TextField through the focused InteractiveObject (TextField is opaque here;
// both start at the DisplayObjectBase part).
static inline TextField* ToTextField(InteractiveObject* pch)
{
    return reinterpret_cast<TextField*>(pch);
}

// @0x1429000d0
void SelectionCtorFunction::SetSelection(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (!fn.Env)
        return;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 3)
        controllerIdx = fn.Arg(2).ToUInt32(fn.Env);
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> focusedChar = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (focusedChar && focusedChar->GetType() == CharacterDef::TextField)
    {
        SPInt bi = 0, ei = SPInt(SF_MAX_UPINT >> 1);
        if (fn.NArgs >= 2)
        {
            bi = fn.Arg(0).ToInt32(fn.Env);
            ei = fn.Arg(1).ToInt32(fn.Env);
        }
        ToTextField(focusedChar)->SetSelection(bi, ei);
    }
}

// @0x142900260
void SelectionCtorFunction::GetCaretIndex(const FnCall& fn)
{
    fn.Result->SetNumber(-1);
    if (!fn.Env)
        return;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 1)
        controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> focusedChar = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (focusedChar && focusedChar->GetType() == CharacterDef::TextField)
        fn.Result->SetNumber(Number(ToTextField(focusedChar)->GetCaretIndex()));
}

// @0x1429003c0
void SelectionCtorFunction::GetBeginIndex(const FnCall& fn)
{
    fn.Result->SetNumber(-1);
    if (!fn.Env)
        return;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 3)
        controllerIdx = fn.Arg(2).ToUInt32(fn.Env);
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> focusedChar = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (focusedChar && focusedChar->GetType() == CharacterDef::TextField)
        fn.Result->SetNumber(Number(ToTextField(focusedChar)->GetBeginIndex()));
}

// @0x142900530
void SelectionCtorFunction::GetEndIndex(const FnCall& fn)
{
    fn.Result->SetNumber(-1);
    if (!fn.Env)
        return;
    unsigned controllerIdx = 0;
    if (fn.Env->CheckExtensions() && fn.NArgs >= 3)
        controllerIdx = fn.Arg(2).ToUInt32(fn.Env);
    MovieImpl* proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> focusedChar = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
    if (focusedChar && focusedChar->GetType() == CharacterDef::TextField)
        fn.Result->SetNumber(Number(ToTextField(focusedChar)->GetEndIndex()));
}


// Environment::SetTarget, inlined.
static inline void SetEnvTarget(Environment* penv, InteractiveObject* ptarget)
{
    penv->IsInvalidTarget = false;
    penv->Target          = ptarget;
    penv->StringContext.UpdateVersion(ptarget->GetVersion());
}

// The valueOf entries of ObjectProto's and FunctionProto's function tables (as FUN_: the proto headers declare no
// ValueOf): this itself.
// @0x142902a00
void FUN_142902a00(const FnCall& fn)
{
    fn.Result->SetAsObjectInterface(fn.ThisPtr);
}

// @0x1429033a0
void FUN_1429033a0(const FnCall& fn)
{
    fn.Result->SetAsObject(static_cast<Object*>(fn.ThisPtr));
}

// @0x1429033c0
void AvmSprite::SpriteSwapDepths(const FnCall& fn)
{
    InteractiveObject* pchar = !fn.ThisPtr ? fn.Env->GetTarget() : fn.ThisPtr->ToCharacter();
    if (!pchar || fn.NArgs < 1)
        return;
    InteractiveObject* pparent = pchar->GetParent();
    const Value&       arg     = fn.Arg(0);
    Sprite*            psprite = pchar->IsSprite() ? static_cast<Sprite*>(pchar) : 0;
    InteractiveObject* pother  = 0;
    int                depth2;
    if (arg.IsNumber())
    {
        depth2 = int(arg.ToNumber(fn.Env)) + 16384;
        if (unsigned(depth2) > 0x7efffffd)
            return;
    }
    else
    {
        // A path resolves relative to the clip itself.
        if (psprite)
        {
            InteractiveObject* psaved = fn.Env->Target;
            SetEnvTarget(fn.Env, psprite);
            pother                    = fn.Env->FindTargetByValue(arg);
            SetEnvTarget(fn.Env, psaved);
        }
        else
            pother = fn.Env->FindTargetByValue(arg);
        if (!pother || pother == pchar || pparent != pother->GetParent())
            return;
        depth2 = pother->Depth;
    }
    if (pchar->Depth < 0)
        return;
    pchar->SetAcceptAnimMoves(false);
    if (!pparent)
        return;
    DisplayObjContainer* pcont  = static_cast<DisplayObjContainer*>(pparent);
    int                  depth1 = pchar->Depth;
    if (pcont->mDisplayList.SwapDepths(pcont, depth1, depth2, pcont->GetCurrentFrame()))
    {
        ::Scaleform::ConstructorMov<::Scaleform::GFx::ASSoundIntf*>::Construct(pcont);
        if (pother)
            pother->SetAcceptAnimMoves(false);
    }
}

// getBounds / getRect: the clip's bounds in the space of the argument clip (itself by default), in pixels.
// @0x142903b30
void AvmSprite::SpriteGetBounds(const FnCall& fn)
{
    Sprite* psprite = AvmSprite::SpriteGetTarget(fn);
    if (psprite == NULL) return;
    DisplayObjectBase* pobj    = (fn.NArgs > 0) ? ResolveCharacterValue(fn.Arg(0), fn.Env) : psprite;
    Sprite*            ptarget = pobj ? (pobj->IsSprite() ? static_cast<Sprite*>(pobj) : 0) : 0;
    RectF            b(0, 0, 0, 0);
    Render::Matrix2F matrix;
    if (ptarget)
    {
        if (ptarget != psprite)
        {
            {
                Render::Matrix2F wm;
                ptarget->GetWorldMatrix(&wm);
                Matrix2F_SetInverse(&matrix, wm);
            }
            {
                Render::Matrix2F cm;
                psprite->GetWorldMatrix(&cm);
                matrix.Prepend(cm);
            }
        }
        matrix.EncloseTransform(&b, psprite->GetBounds(Render::Matrix2F()));
    }
    Ptr<Object> presult = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    ASStringContext* psc = fn.Env->GetSC();
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMin), Render::TwipsToPixels(Double(b.x1)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMax), Render::TwipsToPixels(Double(b.x2)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMin), Render::TwipsToPixels(Double(b.y1)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMax), Render::TwipsToPixels(Double(b.y2)));
    fn.Result->SetAsObject(presult);
}

// @0x142903fc0
void AvmSprite::SpriteGetRect(const FnCall& fn)
{
    Sprite* psprite = AvmSprite::SpriteGetTarget(fn);
    if (psprite == NULL) return;
    DisplayObjectBase* pobj    = (fn.NArgs > 0) ? ResolveCharacterValue(fn.Arg(0), fn.Env) : psprite;
    Sprite*            ptarget = pobj ? (pobj->IsSprite() ? static_cast<Sprite*>(pobj) : 0) : 0;
    RectF            b(0, 0, 0, 0);
    Render::Matrix2F matrix;
    if (ptarget)
    {
        if (ptarget != psprite)
        {
            {
                Render::Matrix2F wm;
                ptarget->GetWorldMatrix(&wm);
                Matrix2F_SetInverse(&matrix, wm);
            }
            {
                Render::Matrix2F cm;
                psprite->GetWorldMatrix(&cm);
                matrix.Prepend(cm);
            }
        }
        matrix.EncloseTransform(&b, psprite->GetRectBounds(Render::Matrix2F()));
    }
    Ptr<Object> presult = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    ASStringContext* psc = fn.Env->GetSC();
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMin), Render::TwipsToPixels(Double(b.x1)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMax), Render::TwipsToPixels(Double(b.x2)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMin), Render::TwipsToPixels(Double(b.y1)));
    presult->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMax), Render::TwipsToPixels(Double(b.y2)));
    fn.Result->SetAsObject(presult);
}

// @0x142904450
void AvmSprite::SpriteLocalToGlobal(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 1)
        return;
    ASStringContext* psc  = fn.Env->GetSC();
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    if (!pobj)
        return;
    Value x, y;
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), &x);
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), &y);
    if (x.IsNumber() && y.IsNumber())
    {
        PointF pt = psprite->LocalToGlobal(PointF(Render::PixelsToTwips(float(x.ToNumber(fn.Env))), Render::PixelsToTwips(float(y.ToNumber(fn.Env)))));
        {
            Value vx(Render::TwipsToPixels(Double(pt.x)));
            pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), vx);
        }
        {
            Value vy(Render::TwipsToPixels(Double(pt.y)));
            pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), vy);
        }
    }
}

// MS2-FUNCTIONAL store/register order after GlobalToLocal (scheduling)
// @0x142904700
void AvmSprite::SpriteGlobalToLocal(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 1)
        return;
    ASStringContext* psc  = fn.Env->GetSC();
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    if (!pobj)
        return;
    Value x, y;
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), &x);
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), &y);
    if (x.IsNumber() && y.IsNumber())
    {
        PointF pt(Render::PixelsToTwips(float(x.ToNumber(fn.Env))), Render::PixelsToTwips(float(y.ToNumber(fn.Env))));
        pt = psprite->GlobalToLocal(pt);
        {
            Value vx(Render::TwipsToPixels(Double(pt.x)));
            pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), vx);
        }
        {
            Value vy(Render::TwipsToPixels(Double(pt.y)));
            pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), vy);
        }
    }
}

// @0x1429065d0
void AvmSprite::SpriteGetSWFVersion(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
        fn.Result->SetInt(psprite->GetVersion());
}

// A DragState whose points the ctor body zeroes again, field by field: the exe zeroes them with three qword stores.
struct StartDragState : MovieImpl::DragState
{
    SF_FORCEINLINE StartDragState()
    {
        BoundLT.x = BoundLT.y = 0;
        BoundRB.x = BoundRB.y = 0;
        CenterDelta.x = CenterDelta.y = 0;
    }
};

// startDrag([lockCenter [, left, top, right, bottom]]): the clip follows the mouse, optionally kept in the rectangle.
// @0x142906650
void AvmSprite::SpriteStartDrag(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    StartDragState st;
    bool lockCenter = false;
    if (fn.NArgs > 0)
    {
        lockCenter = fn.Arg(0).ToBool(fn.Env);
        if (fn.NArgs > 4)
        {
            st.Bound = true;
            // Each low bound is copied as soon as it is read, so it keeps its own register beside the compared value.
            float x0     = Render::PixelsToTwips(float(fn.Arg(1).ToNumber(fn.Env)));
            float left   = x0;
            float y0     = Render::PixelsToTwips(float(fn.Arg(2).ToNumber(fn.Env)));
            float top    = y0;
            float x1     = Render::PixelsToTwips(float(fn.Arg(3).ToNumber(fn.Env)));
            float right  = x1;
            float y1     = Render::PixelsToTwips(float(fn.Arg(4).ToNumber(fn.Env)));
            float bottom = y1;
            if (x0 > x1)
            {
                left  = x1;
                right = x0;
            }
            if (y0 > y1)
            {
                top    = y1;
                bottom = y0;
            }
            st.BoundLT.x = left;
            st.BoundLT.y = top;
            st.BoundRB.x = right;
            st.BoundRB.y = bottom;
        }
    }
    st.pCharacter = psprite;
    st.InitCenterDelta(lockCenter);
    psprite->GetMovieImpl()->SetDragState(st);
    UInt32 flags = psprite->InteractiveObject::Flags;
    bool optAdv = ((flags >> 21) & 1) != 0;
    bool marked = ((flags >> 22) & 1) != 0;
    switch (psprite->Sprite::CheckAdvanceStatus(optAdv && !marked))
    {
    case 1:  psprite->AddToOptimizedPlayList(); break;
    case -1: psprite->MarkToRemoveFromOptimizedPlayList(); break;
    }
}

// Drops the dragged character; the clip may now leave the optimized advance list.
// @0x1429069f0
void AvmSprite::SpriteStopDrag(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
    {
        psprite->GetMovieImpl()->pKeepAdvancingChar = 0;
        UInt32 flags = psprite->InteractiveObject::Flags;
        bool optAdv = ((flags >> 21) & 1) != 0;
        bool marked = ((flags >> 22) & 1) != 0;
        switch (psprite->Sprite::CheckAdvanceStatus(optAdv && !marked))
        {
        case 1:  psprite->AddToOptimizedPlayList(); break;
        case -1: psprite->MarkToRemoveFromOptimizedPlayList(); break;
        }
    }
}

// DisplayObjectBase::CharToInteractiveObject.
static SF_FORCEINLINE InteractiveObject* Sfr02CharToInteractiveObject(DisplayObjectBase* pch)
{
    return pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
}

// attachMovie(symbol, name, depth [, initObject]): an instance of an exported library clip; SWF 6+ returns it.
// @0x1429055f0
void AvmSprite::SpriteAttachMovie(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 3)
        return;
    ASString sym = fn.Arg(0).ToString(fn.Env);
    ResourceBindData resBindData;
    bool notFound;
    {
        String symstr(sym.ToCStr());
        notFound = !psprite->GetMovieImpl()->FindExportedResource(psprite->GetResourceMovieDef(), &resBindData, symstr);
    }
    if (notFound)
    {
        psprite->LogScriptWarning("%s.attachMovie() failed - export name \"%s\" is not found.",
                                  psprite->GetName().ToCStr(), sym.ToCStr());
        return;
    }
    if (!(resBindData.pResource->GetResourceTypeCode() & Resource::MakeTypeCode(Resource::RT_CharacterDef_Bit)))
    {
        psprite->LogScriptWarning("%s.attachMovie() failed - \"%s\" is not a movieclip.",
                                  psprite->GetName().ToCStr(), sym.ToCStr());
        return;
    }
    CharacterDef* pdef = static_cast<CharacterDef*>(resBindData.pResource.GetPtr());
    CharacterCreateInfo ccinfo;
    ccinfo.pCharDef     = pdef;
    ccinfo.pResource    = 0;
    ccinfo.pBindDefImpl = resBindData.pBinding->GetOwnerDefImpl();
    CharPosInfo pos(pdef->GetId(), int(fn.Arg(2).ToNumber(fn.Env)) + 16384,
                    1, Render::Cxform::Identity, 1, Render::Matrix2F::Identity);
    if (unsigned(pos.Depth) <= 0x7efffffdu)
    {
        ObjectInterface* initSource = (fn.NArgs == 4) ? fn.Arg(3).ToObjectInterface(fn.Env) : 0;
        Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, fn.Arg(1).ToString(fn.Env), 0, initSource, ~0u, 1, &ccinfo, 0);
        if (newch)
        {
            newch->SetAcceptAnimMoves(false);
            if (psprite->GetVersion() >= 6)
                fn.Result->SetAsCharacter(Sfr02CharToInteractiveObject(newch));
        }
    }
    else
    {
        psprite->LogScriptWarning("%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
                                  psprite->GetName().ToCStr(), sym.ToCStr(), pos.Depth);
    }
}

// attachAudio(netStream): hands the stream's sound to the video module for this clip.
// @0x142905a00
void AvmSprite::SpriteAttachAudio(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("%s.attachAudio() needs one Argument", psprite->GetName().ToCStr());
        return;
    }
    Object* pobj = fn.Arg(0).ToObject(fn.Env);
    if (pobj && pobj->GetObjectType() == Object::Object_NetStream)
    {
        Video::VideoBase* pvideo = fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetVideo().GetPtr();
        if (pvideo && pvideo->GetAS2Support())
            pvideo->GetAS2Support()->AttachAudio(pobj, psprite);
    }
}

// duplicateMovieClip(name, depth [, initObject]): the copy goes to the clip's parent; SWF 6+ returns it.
// @0x142905b80
void AvmSprite::SpriteDuplicateMovieClip(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 2)
        return;
    ObjectInterface* initSource = (fn.NArgs == 3) ? fn.Arg(2).ToObjectInterface(fn.Env) : 0;
    Ptr<InteractiveObject> newch = AS2::ToAvmCharacter(psprite)->CloneDisplayObject(
        fn.Arg(0).ToString(fn.Env), int(fn.Arg(1).ToNumber(fn.Env)) + 16384, initSource);
    if (psprite->GetVersion() >= 6)
        fn.Result->SetAsCharacter(newch);
}

// createEmptyMovieClip(name, depth): a fresh empty clip on this one; it is returned.
// @0x142905e00
void AvmSprite::SpriteCreateEmptyMovieClip(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 2)
        return;
    CharPosInfo pos(ResourceId(ResourceId::IdType_InternalConstant | 1), int(fn.Arg(1).ToNumber(fn.Env)) + 16384,
                    1, Render::Cxform::Identity, 1, Render::Matrix2F::Identity);
    if (unsigned(pos.Depth) > 0x7efffffdu)
        return;
    Value* pname = ArgCopy(&fn, 0);
    Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, pname->ToString(fn.Env), 0, 0, ~0u, 1, 0, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        fn.Result->SetAsCharacter(Sfr02CharToInteractiveObject(newch));
    }
}

// A snapshot of the clip's static text.
// @0x1429064b0
void AvmSprite::SpriteGetTextSnapshot(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    Ptr<TextSnapshotObject> psnap = *SF_HEAP_NEW(fn.Env->GetHeap()) TextSnapshotObject(fn.Env, ObjectInlineCtorTag());
    psprite->GetTextSnapshot(&psnap->GetData());
    fn.Result->SetAsObject(psnap);
}

// @0x142906ba0
void AvmSprite::SpriteLoadMovie(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs <= 0)
        return;
    LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None;
    if (fn.NArgs > 1)
    {
        // "get" / "post" (any case); anything else sends no variables.
        ASString methodName(fn.Arg(1).ToString(fn.Env).ToLowerNode());
        if (methodName == "get")
            method = LoadQueueEntry::LM_Get;
        else if (methodName == "post")
            method = LoadQueueEntry::LM_Post;
    }
    ToAS2Root(psprite)->AddLoadQueueEntry(psprite, fn.Arg(0).ToString(fn.Env).ToCStr(), method);
}

// @0x142906de0
void AvmSprite::SpriteLoadVariables(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs <= 0)
        return;
    LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None;
    if (fn.NArgs > 1)
    {
        // "get" / "post" (any case); anything else sends no variables.
        ASString methodName(fn.Arg(1).ToString(fn.Env).ToLowerNode());
        if (methodName == "get")
            method = LoadQueueEntry::LM_Get;
        else if (methodName == "post")
            method = LoadQueueEntry::LM_Post;
    }
    ToAS2Root(psprite)->AddVarLoadQueueEntry(psprite, fn.Arg(0).ToString(fn.Env).ToCStr(), method);
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

// FunctionRefBase::SetLocalFrame (0x142981e70, sfr_as2_07) and the FunctionRef copy around it, which the exe inlines
// into the ToFunction copy in Watch_. Local copies: an inline redefinition of the member would emit a second COMDAT.
static SF_FORCEINLINE void MS2_SetLocalFrame(FunctionRefBase& r, LocalFrame* localFrame, bool weakRef)
{
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->Release();
    r.pLocalFrame = localFrame;
    if (weakRef)
        r.Flags |= FunctionRefBase::FuncRef_Weak;
    else
        r.Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->AddRef();
}

static SF_FORCEINLINE FunctionRef MS2_CopyFuncRef(const FunctionRefBase& orig)
{
    FunctionRef r;
    r.Flags    = 0;
    r.Function = orig.Function;
    if (!(r.Flags & FunctionRefBase::FuncRef_Internal) && r.Function)
        r.Function->AddRef();
    r.pLocalFrame = 0;
    if (orig.pLocalFrame)
        MS2_SetLocalFrame(r, orig.pLocalFrame, (orig.Flags & FunctionRefBase::FuncRef_Weak) != 0);
    return r;
}

// Value::ToFunction as the SDK writes it (a switch); the exe inlines it here. The derived view reaches the protected
// ResolveFunctionName.
struct MS2_FuncValue : Value
{
    SF_FORCEINLINE FunctionRef ToFunctionSw(const Environment* penv) const
    {
        switch (T.Type)
        {
        case FUNCTIONNAME:
            return ResolveFunctionName(penv);
        case FUNCTION:
            return MS2_CopyFuncRef(V.FunctionValue);
        default:;
        }
        return FunctionRef();
    }
};

// ValueProperty ctor (0x142923e70, sfr_as2_03), which the exe (LTCG) inlines into AddProperty. A tagged copy: an
// inline redefinition of the ctor would be a second COMDAT next to sfr_as2_03's.
struct Sfr02PropertyTag {};
template<>
SF_FORCEINLINE ValueProperty::ValueProperty(ASRefCountCollector* pcc, const FunctionRef& getterMethod,
                                            const FunctionRef& setterMethod, Sfr02PropertyTag)
    : ASRefCountBase<ValueProperty>(pcc), GetterMethod(getterMethod), SetterMethod(setterMethod)
{
}

// Value(getter, setter, heap, collector) (as2_value.h) over the tagged ValueProperty copy.
struct Sfr02PropertyValue : Value
{
    SF_FORCEINLINE Sfr02PropertyValue(const FunctionRef& getter, const FunctionRef& setter, MemoryHeap* pheap,
                                      ASRefCountCollector* pcc)
    {
        T.Type      = PROPERTY;
        V.pProperty = new (pheap) ValueProperty(pcc, getter, setter, Sfr02PropertyTag());
    }
};

// addProperty(name, getter[, setter]): a member read and written through the functions.
// The exe (LTCG) inlines the getter's ToFunction (the SDK switch) and the ValueProperty ctor; the setter goes through
// FnCall::Arg and Value::ToFunction out of line.
// MS2-FUNCTIONAL register allocation: the exe keeps the getter's Flags byte in a frame slot ([rbp+0x67]) and the
// heap/collector in memory, ours keeps them in r15b/r12 (1190 vs 1235 bytes).
// @0x142901d20
void ObjectProto::AddProperty(const FnCall& fn)
{
    if (fn.NArgs >= 2)
    {
        ASString    propName(fn.Arg(0).ToString(fn.Env));
        FunctionRef getter = static_cast<const MS2_FuncValue&>(fn.Arg(1)).ToFunctionSw(fn.Env);
        if (!getter.IsNull())
        {
            FunctionRef setter;
            if (fn.NArgs >= 3 && fn.Arg(2).IsFunction())
                setter = ArgCopy(&fn, 2)->ToFunction_Call(fn.Env);
            Sfr02PropertyValue val(getter, setter, fn.Env->GetHeap(), fn.Env->GetCollector());
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
// @0x1429024e0
void ObjectProto::Watch_(const FnCall& fn)
{
    if (fn.NArgs >= 2)
    {
        FunctionRef func = static_cast<const MS2_FuncValue&>(fn.Arg(1)).ToFunctionSw(fn.Env);
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
// The array elements are pushed in reverse, so Arg(0) is the first element.
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
// Arg(0) becomes this; the remaining arguments are pushed again for the callee.
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

// The exe has strcmp inlined here: the compiler intrinsic, not a hand loop.
#pragma intrinsic(strcmp)
ActionLogger::ActionLogger(DisplayObject* ptarget, const char* suffix)
{
    MovieImpl* pm = ptarget->FindMovieImpl();
    VerboseAction       = (pm->Flags >> 2) & 1;
    VerboseActionErrors = !((pm->Flags >> 6) & 1);
    LogSuffix           = suffix;
    if (!suffix)
        UseSuffix = false;
    else
    {
        // LogSuffix is read before the GetFileURL call, Flags after it.
        MovieDef*   pdef  = ((ActionLoggerMovie*)pm)->GetMovieDef();
        const char* psuf  = LogSuffix;
        const char* url   = pdef->GetFileURL();
        UInt32      flags = pm->Flags;
        if (strcmp(url, psuf) == 0)
            UseSuffix = (flags >> 3) & 1;
        else
            UseSuffix = (flags >> 4) & 1;
    }
    if (!((UByte)(pm->Flags >> 1) & 1))
        pm->pCachedLog = pm->GetStateBag()->GetLog();
    pLog = pm->pCachedLog;

    // Only the file name of the suffix path.
    if (UseSuffix && !((UByte)(pm->Flags >> 5) & 1))
    {
        SPInt len = (SPInt)strlen(suffix);
        for (SPInt i = len; i > 0; --i)
        {
            if (LogSuffix[i] == '/' || LogSuffix[i] == '\\')
            {
                LogSuffix = LogSuffix + i + 1;
                break;
            }
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


// Writes the data object through the writer of the installed shared object manager.
// @0x142901150
void SharedObjectProto::Flush(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, SharedObject);
    SharedObject* pthis = static_cast<SharedObject*>(fn.ThisPtr);
    if (!pthis)
        return;
    Ptr<SharedObjectManagerBase> psomgr = *static_cast<SharedObjectManagerBase*>(
        fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_SharedObject));
    if (psomgr)
    {
        Ptr<SharedObjectVisitor> pwriter = *psomgr->CreateWriter(
            pthis->Name, pthis->LocalPath, fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetFileOpener());
        pthis->Flush(fn.Env, pwriter);
    }
}

// Replaces the data object by an empty one and writes it.
// @0x142900fc0
void SharedObjectProto::Clear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, SharedObject);
    SharedObject* pthis = static_cast<SharedObject*>(fn.ThisPtr);
    if (!pthis)
        return;
    Ptr<Object> pdata = *fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Object));
    pthis->SetDataObject(fn.Env, pdata);
    Ptr<SharedObjectManagerBase> psomgr = *static_cast<SharedObjectManagerBase*>(
        fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_SharedObject));
    if (psomgr)
    {
        Ptr<SharedObjectVisitor> pwriter = *psomgr->CreateWriter(
            pthis->Name, pthis->LocalPath, fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetFileOpener());
        pthis->Flush(fn.Env, pwriter);
    }
}

// Bytes of the data object.
// (SharedObjectProto::GetSize 0x142901280 is in sfr_as2_04, next to the ComputeSizeInBytes it inlines)
//
//
//
//
//
//
//
//
//

// RemoveCaseCheck of the registered class table (exe 0x14297cd20).
void         ClassHash_RemoveCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive);

// The registered class table's findIndexAlt ignoring case, a COMDAT the exe calls out of line (0x142916f50).
struct ClassHashAccess
{
    typedef decltype(ASStringHash<FunctionRef>::mHash) Container;
    typedef Container::BaseType                        SetType;
};
inline SPInt HashFindIndex(const ClassHashAccess* phash, const ASStringNoCaseKey& key);
template struct HashFindIndexAccess<ClassHashAccess, ASStringNoCaseKey,
                                    &ClassHashAccess::SetType::findIndexAlt<ASStringNoCaseKey> >;

// Hash::SetCaseCheck of the registered class table, inline in the exe around the out-of-line findIndexAlt.
template<class K>
SF_INLINE ClassHashAccess::Container::Iterator ClassHash_FindAlt(ASStringHash<FunctionRef>* phash, const K& key)
{
    SPInt index = HashFindIndex(reinterpret_cast<const ClassHashAccess*>(phash), key);
    if (index >= 0)
        return ClassHashAccess::Container::Iterator(&phash->mHash, index);
    return ClassHashAccess::Container::Iterator(0, 0);
}
SF_INLINE ClassHashAccess::Container::Iterator ClassHash_FindNoCase(ASStringHash<FunctionRef>* phash, const ASString& key)
{
    ASStringNoCaseKey ikey(key);
    return ClassHash_FindAlt(phash, ikey);
}
SF_INLINE void ClassHash_SetCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, const FunctionRef& value,
                                      bool caseSensitive)
{
    ClassHashAccess::Container::Iterator it = caseSensitive ? phash->Find(key) : ClassHash_FindNoCase(phash, key);
    if (it != phash->End())
        it->Second = value;
    else
        phash->Add(key, value);
}

static __forceinline bool MS2_GC_RegisterClass(GlobalContext* pgc, ASStringContext* psc, const ASString& className, const FunctionRef& ctorFunction)
{
    ClassHash_SetCaseCheck(&pgc->RegisteredClasses, className, ctorFunction, psc->IsCaseSensitive());
    return true;
}

static __forceinline bool MS2_GC_UnregisterClass(GlobalContext* pgc, ASStringContext* psc, const ASString& className)
{
    if (pgc->RegisteredClasses.GetCaseCheck(className, psc->IsCaseSensitive()) == 0)
        return false;
    ClassHash_RemoveCaseCheck(&pgc->RegisteredClasses, className, psc->IsCaseSensitive());
    return true;
}

// Object.registerClass(name, ctor) binds the constructor to the linkage name; null removes the binding.
// @0x142908e90
void ObjectCtorFunction::RegisterClassA(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (fn.NArgs < 2)
    {
        fn.Env->LogScriptError("Error: Too few parameters for Object.registerClass (%d)", fn.NArgs);
        return;
    }

    GlobalContext* pgctxt = fn.Env->GetSC()->pContext;
    ASString       classname(fn.Arg(0).ToString(fn.Env));
    if (fn.Arg(1).IsFunction())
    {
        FunctionRef func = static_cast<const MS2_FuncValue&>(fn.Arg(1)).ToFunctionSw(fn.Env);
        fn.Result->SetBool(MS2_GC_RegisterClass(pgctxt, fn.Env->GetSC(), classname, func));
    }
    else if (fn.Arg(1).IsNull())
    {
        fn.Result->SetBool(MS2_GC_UnregisterClass(pgctxt, fn.Env->GetSC(), classname));
    }
    else
    {
        ASString a1(fn.Arg(1).ToString(fn.Env));
        fn.Env->LogScriptError("Second parameter of Object.registerClass(%s, %s) should be function or null",
                               classname.ToCStr(), a1.ToCStr());
    }
}

// ExternalInterface.call(methodName, ...args): the arguments, as host values, go to the handler of the movie; the
// result is what the handler stored in the movie root.
// @0x1428ffa20
void ExternalInterfaceCtorFunction::Call(const FnCall& fn)
{
    MovieImpl* pmovie = fn.Env->GetTarget()->GetMovieImpl();
    if (pmovie->pExtIntfHandler)
    {
        unsigned nargs = 0;
        ASString methodName(fn.Env->GetBuiltin(ASBuiltin_empty_));
        if (fn.NArgs >= 1)
        {
            methodName = fn.Arg(0).ToString(fn.Env);
            nargs      = fn.NArgs - 1;
        }

        // Up to 10 arguments are converted on the stack; the buffer is freed only past 40 of them (as the exe).
        void*       onStack[10 * (sizeof(GFx::Value) / sizeof(void*))];
        GFx::Value* args;
        if (nargs > 10)
            args = (GFx::Value*)SF_HEAP_ALLOC(fn.Env->GetHeap(), nargs * sizeof(GFx::Value), Stat_Default_Mem);
        else
            args = (GFx::Value*)onStack;
        for (unsigned i = 0; i < nargs; i++)
        {
            const Value& arg = fn.Arg(i + 1);
            static_cast<MovieRoot*>(pmovie->pASMovieRoot)
                ->ASValue2GFxValue(fn.Env, arg, Scaleform::Construct<GFx::Value>(&args[i]));
        }

        static_cast<MovieRoot*>(pmovie->pASMovieRoot)->ExternalIntfRetVal.SetUndefined();
        pmovie->pExtIntfHandler->Callback(pmovie->AsMovie(), methodName.IsEmpty() ? NULL : methodName.ToCStr(), args, nargs);
        *fn.Result = static_cast<MovieRoot*>(pmovie->pASMovieRoot)->ExternalIntfRetVal;

        for (unsigned i = 0; i < nargs; i++)
            args[i].~Value();
        if (nargs > sizeof(onStack) / sizeof(onStack[0]))
            SF_FREE(args);
    }
    else
    {
        fn.LogScriptWarning("ExternalInterface.call - handler is not installed.");
        fn.Result->SetUndefined();
    }
}

struct MS2_FuncValueAC : Value
{
    // Builds the reference in place in *r and hands its fields back from each case.
    SF_FORCEINLINE void ToFunctionAC(const Environment* penv, FunctionRef* r, FunctionObject*& f, LocalFrame*& lf,
                                     UByte& fl) const
    {
        switch (T.Type)
        {
        case FUNCTIONNAME:
            ::new (r) FunctionRef(ResolveFunctionName(penv));
            fl = r->Flags; lf = r->pLocalFrame; f = r->Function;
            return;
        case FUNCTION:
        {
            const FunctionRefBase& orig = V.FunctionValue;
            f  = orig.Function;
            fl = 0;
            r->Flags    = fl;
            r->Function = f;
            if (f)
                f->AddRef();
            lf = 0;
            r->pLocalFrame = lf;
            if (orig.pLocalFrame)
            {
                lf = orig.pLocalFrame;
                r->pLocalFrame = lf;
                if (orig.Flags & FunctionRefBase::FuncRef_Weak)
                    fl |= FunctionRefBase::FuncRef_Weak;
                else
                    fl &= ~FunctionRefBase::FuncRef_Weak;
                r->Flags = fl;
                if (!(fl & FunctionRefBase::FuncRef_Weak))
                    lf->AddRef();
            }
            return;
        }
        default:
            ::new (r) FunctionRef();
            f = r->Function; lf = r->pLocalFrame; fl = r->Flags;
            return;
        }
    }
};

// MS2-FUNCTIONAL the exe (LTCG) keeps func's fields in registers across AddInvokeAlias; modelled with a dtor-less holder.
// Left: frame 0x78 vs 0x68 (aliasName in the rdx home, rsi/rdi/r12/r14/r15 saved in-frame), the default case re-reads
// the zeroed fields, and the copy's frame flag is a setne bool (an LTCG bool argument of SetLocalFrame).
// @0x1428ff660
void ExternalInterfaceCtorFunction::AddCallback(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs < 3)
        return;
    MovieImpl* pmovie = fn.Env->GetTarget()->GetMovieImpl();
    ASString aliasName(fn.Arg(0).ToString(fn.Env));
    union FuncHolder { FunctionRef f; FuncHolder() {} ~FuncHolder() {} } holder;
    FunctionObject* funcObj;
    LocalFrame* funcFrame;
    UByte funcFlags;
    static_cast<const MS2_FuncValueAC&>(fn.Arg(2)).ToFunctionAC(fn.Env, &holder.f, funcObj, funcFrame, funcFlags);
    const FunctionRef& func = holder.f;
    {
        Ptr<CharacterHandle> thisChar;
        Ptr<Object> thisObj;
        if (fn.Arg(1).IsCharacter())
        {
            Ptr<InteractiveObject> pch = ResolveCharacterValue(fn.Arg(1), fn.Env);
            if (pch)
                thisChar = pch->GetCharacterHandle();
        }
        else
            thisObj = fn.Arg(1).ToObject(fn.Env);
        static_cast<MovieRoot*>(pmovie->pASMovieRoot)->AddInvokeAlias(aliasName, thisChar, thisObj, func);
        fn.Result->SetBool(true);
    }
    if (!(funcFlags & FunctionRefBase::FuncRef_Internal) && funcObj)
        funcObj->Release();
    if (!(funcFlags & FunctionRefBase::FuncRef_Weak) && funcFrame)
        funcFrame->Release();
}

// TextSnapshot.getTextRunInfo(start, end): an array with an info object per glyph in [start, end).
// @0x142908840
void TextSnapshotProto::GetTextRunInfo(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 2)
        return;
    UInt32 start = fn.Arg(0).ToUInt32(fn.Env);
    UInt32 end   = fn.Arg(1).ToUInt32(fn.Env);
    Ptr<ArrayObject> parr = *SF_HEAP_NEW(fn.Env->GetHeap()) ArrayObject(fn.Env);
    GASTextSnapshotGlyphVisitor visitor(fn.Env, parr);
    pthis->GetData().Visit(&visitor, start, end);
    fn.Result->SetAsObject(parr);
}

// TextSnapshot.hitTestTextNearPos(x, y[, closeDist]): the character index near the point, -1 if none.
// @0x142908a70
void TextSnapshotProto::HitTestTextNearPos(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, TextSnapshot);
    TextSnapshotObject* pthis = (TextSnapshotObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 2)
        return;
    float x = (float)fn.Arg(0).ToNumber(fn.Env);
    float y = (float)fn.Arg(1).ToNumber(fn.Env);
    float closeDist = (fn.NArgs > 2) ? (float)fn.Arg(2).ToNumber(fn.Env) : 0.0f;
    int idx = pthis->GetData().HitTestTextNearPos(Render::PixelsToTwips(x), Render::PixelsToTwips(y), Render::PixelsToTwips(closeDist));
    fn.Result->SetNumber((Number)idx);
}

// createTextField(name, depth, x, y, width, height): a new empty text field.
// @0x142906040
void AvmSprite::SpriteCreateTextField(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 6)
        return;
    CharPosInfo pos(ResourceId(ResourceId::IdType_InternalConstant | 2), int(fn.Arg(1).ToNumber(fn.Env)) + 16384,
                    1, Render::Cxform::Identity, 1, Render::Matrix2F::Identity);
    if (unsigned(pos.Depth) > 0x7efffffdu)
        return;
    Value* pname = ArgCopy(&fn, 0);
    Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, pname->ToString(fn.Env), 0, 0, ~0u, 1, 0, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        InteractiveObject* ptextField = Sfr02CharToInteractiveObject(newch);
        AvmCharacter* pavm = ptextField ? AS2::ToAvmCharacter(ptextField) : 0;
        pavm->SetStandardMember(AvmCharacter::M_x, *ArgCopy(&fn, 2), false);
        pavm->SetStandardMember(AvmCharacter::M_y, *ArgCopy(&fn, 3), false);
        pavm->SetStandardMember(AvmCharacter::M_width, *ArgCopy(&fn, 4), false);
        pavm->SetStandardMember(AvmCharacter::M_height, *ArgCopy(&fn, 5), false);
        fn.Result->SetAsCharacter(ptextField);
    }
}

// MovieImpl::SetNormalizedScreenCoords as the SDK player builds it (through the ScreenToWorld member).
static SF_FORCEINLINE void HitTestSetScreenCoords(MovieImpl* proot, const Render::PointF& mousePos)
{
    float nsx = 2.f * ((mousePos.x - Render::PixelsToTwips(proot->ViewOffsetX)) / proot->VisibleFrameRect.Width()) - 1.0f;
    float nsy = 2.f * ((mousePos.y - Render::PixelsToTwips(proot->ViewOffsetY)) / proot->VisibleFrameRect.Height()) - 1.0f;
    proot->GetScreenToWorld().SetNormalizedScreenCoords(nsx, nsy);
}
// DisplayObjectBase::GetLevelMatrix() / GetWorldMatrix() by value (the SDK header inlines).
static SF_FORCEINLINE Matrix2F HitTestLevelMatrix(const DisplayObjectBase* pobj)
{
    Matrix2F m;
    pobj->GetLevelMatrix(&m);
    return m;
}
static SF_FORCEINLINE Matrix2F HitTestWorldMatrix(const DisplayObjectBase* pobj)
{
    Matrix2F m;
    pobj->GetWorldMatrix(&m);
    return m;
}

#pragma strict_gs_check(push, on)
// hitTest(x, y[, shapeFlag[, ...]]) tests a stage point (pixels) against the bounds or the shapes, 3D clips through
// the movie's screen-to-world state; hitTest(target) tests the world bounds of both clips for overlap.
// MS2-FUNCTIONAL: same length and schedule as the exe; only the xmm6/xmm7 assignment of pt.x/pt.y differs
// @0x1429049b0
void AvmSprite::SpriteHitTest(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    fn.Result->SetBool(false);
    RectF bounds = psprite->GetBounds(Matrix2F());
    if (bounds.IsNull())
        return;
    if (fn.NArgs >= 2)
    {
        UByte mask = 0;
        Render::PointF pt(Render::PixelsToTwips(float(fn.Arg(0).ToNumber(fn.Env))),
                          Render::PixelsToTwips(float(fn.Arg(1).ToNumber(fn.Env))));
        if (fn.NArgs >= 3)
            mask |= ArgCopy(&fn, 2)->ToBool(fn.Env) ? 1 : 0;
        if (fn.NArgs >= 4)
            mask |= ArgCopy(&fn, 3)->ToBool(fn.Env) ? 2 : 0;
        MovieImpl* proot = psprite->GetMovieImpl();
        if (proot && psprite->Is3D(true))
        {
            HitTestSetScreenCoords(proot, pt);
            Render::ScreenToWorld& stw = proot->GetScreenToWorld();
            Matrix3F view;
            Matrix4F proj;
            if (psprite->GetProjectionMatrix3D(&proj))
                stw.SetProjection(proj);
            if (psprite->GetViewMatrix3D(&view))
                stw.SetView(view);
            Matrix3F world;
            psprite->GetWorldMatrix3D(&world);
            stw.SetWorld(world);
            // The SDK's Point() leaves x/y uninitialized.
            float pp[2];
            stw.GetWorldPoint(reinterpret_cast<Render::PointF*>(pp));
            fn.Result->SetBool(psprite->PointTestLocal(*reinterpret_cast<Render::PointF*>(pp), mask));
            return;
        }
        Render::PointF ptSpr = HitTestLevelMatrix(psprite).TransformByInverse(pt);
        if (psprite->DisplayObjectBase::Flags & GFx::DisplayObjectBase::Mask_Scale9GridExists)
        {
            fn.Result->SetBool(psprite->PointTestLocal(ptSpr, mask));
        }
        else
        {
            if (bounds.Contains(ptSpr))
            {
                if (!(mask & 1))
                    fn.Result->SetBool(true);
                else
                    fn.Result->SetBool(psprite->PointTestLocal(ptSpr, mask));
            }
            else
                fn.Result->SetBool(false);
        }
    }
    else if (fn.NArgs == 1)
    {
        const Value&       arg     = fn.Arg(0);
        InteractiveObject* ptarget = NULL;
        if (arg.IsCharacter())
        {
            ptarget = arg.ToCharacter(fn.Env);
        }
        else
        {
            ASString varName = arg.ToString(fn.Env);
            Value    result;
            if (fn.Env->GetVariable(varName, &result))
            {
                ptarget = ResolveCharacterValue(result, fn.Env);
            }
        }
        if (!ptarget)
            return;

        RectF tbounds = ptarget->GetBounds(Matrix2F());
        if (tbounds.IsNull())
            return;
        RectF world1 = HitTestWorldMatrix(psprite).EncloseTransform(bounds);
        RectF world2 = HitTestWorldMatrix(ptarget).EncloseTransform(tbounds);
        fn.Result->SetBool(world1.Intersects(world2));
    }
}
#pragma strict_gs_check(pop)

// SharedObject::SetNameAndLocalPath (exe 0x142989250, sfr_as2_07), which the exe inlines into getLocal.
static SF_FORCEINLINE bool GetLocalSetNameAndLocalPath(SharedObject* pthis, const String& name,
                                                       const String& localPath)
{
    const char* pstr;
    UInt32 c = name.GetFirstCharAt(0, &pstr);
    while (c)
    {
        switch (c)
        {
        case '~':
        case '%':
        case '&':
        case '\\':
        case ';':
        case ':':
        case '"':
        case '\'':
        case ',':
        case '<':
        case '>':
        case '?':
        case '#':
            return false;
        }
        if (SFiswspace((wchar_t)c))
            return false;
        c = name.GetNextChar(&pstr);
    }
    pthis->Name = name;
    pthis->LocalPath = localPath;
    return true;
}

// Hash::Get (SDK header inline): the value of key's node, or null.
static SF_FORCEINLINE SharedObjectPtr* GetLocalHashGet(ASStringHash_GC<SharedObjectPtr>::SetType& objects,
                                                       const ASString& key)
{
    ASStringHash_GC<SharedObjectPtr>::NodeType* p = objects.GetAlt(key);
    if (p)
        return &p->Second;
    return 0;
}

// Hash::Add (SDK header inline): the value is a temp that lives across the add.
static SF_FORCEINLINE void GetLocalHashAdd(ASStringHash_GC<SharedObjectPtr>& hash, const ASString& key,
                                           const SharedObjectPtr& value)
{
    ASStringHash_GC<SharedObjectPtr>::NodeType::NodeRef e(key, value);
    reinterpret_cast<ASStringHash_GC<SharedObjectPtr>::SetType&>(hash).Add(&hash, e);
}

// getLocal(name[, localPath]): shared objects are cached by "localPath:name"; a new one gets its data replayed by
// the shared object manager, null when the name is invalid or nothing could be loaded.
// MS2-FUNCTIONAL: 4 bytes long; the exe keeps the constructor in rsi and releases its reference without nulling it
// @0x142901410
void SharedObjectCtorFunction::GetLocal(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ASString name = fn.Arg(0).ToString(fn.Env);
    ASString localPath = fn.Env->CreateConstString("");
    if (fn.NArgs > 1)
        localPath = fn.Arg(1).ToString(fn.Env);
    String nameStr(name.ToCStr());
    String localPathStr(localPath.ToCStr());
    ASString key = fn.Env->CreateString(localPathStr.ToCStr(), localPathStr.GetSize());
    key.Append(":", 1);
    key.Append(nameStr.ToCStr(), strlen(nameStr.ToCStr()));

    FunctionRef ctor = fn.Env->GetConstructor(ASBuiltin_SharedObject);
    SharedObjectCtorFunction* pctor = static_cast<SharedObjectCtorFunction*>(ctor.GetObjectPtr());
    typedef ASStringHash_GC<SharedObjectPtr>::SetType SetType;
    SetType& objects = *reinterpret_cast<SetType*>(&pctor->SharedObjects);
    SharedObjectPtr* psavedObj = GetLocalHashGet(objects, key);
    if (psavedObj)
    {
        fn.Result->SetAsObject(psavedObj->GetPtr());
        return;
    }

    Ptr<SharedObject> pobj = *static_cast<SharedObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_SharedObject)));
    if (!GetLocalSetNameAndLocalPath(pobj, nameStr, localPathStr))
    {
        fn.Result->SetNull();
        return;
    }
    Ptr<Object> pdata = *fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Object));
    GASSharedObjectLoader loader(fn.Env, pdata);
    StateBag* pstates = fn.Env->GetTarget()->GetMovieImpl()->GetStateBag();
    Ptr<SharedObjectManagerBase> psomgr =
        *static_cast<SharedObjectManagerBase*>(pstates->GetStateAddRef(State::State_SharedObject));
    FileOpenerBase* pfileOpener = fn.Env->GetTarget()->GetMovieImpl()->GetStateBag()->GetFileOpener();
    if (psomgr && psomgr->LoadSharedObject(nameStr, localPathStr, &loader, pfileOpener))
    {
        pobj->SetDataObject(fn.Env, pdata);
        fn.Result->SetAsObject(pobj);
        GetLocalHashAdd(pctor->SharedObjects, key, pobj.GetPtr());
    }
    else
        fn.Result->SetNull();
}

// attachBitmap(bitmapData, depth[, pixelSnapping, smoothing]): a new sprite showing the image at the depth.
// MS2-FUNCTIONAL the exe reuses the name temp's slot for the sprite's ResourceId and stores it late
// @0x142905190
void AvmSprite::SpriteAttachBitmap(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 2 || psprite->GetVersion() < 8)
        return;

    Ptr<Object> pobj = fn.Arg(0).ToObject(fn.Env);
    if (!pobj || pobj->GetObjectType() != Object_BitmapData)
    {
        psprite->LogScriptWarning("%s.attachBitmap() failed - the argument is not a BitmapData.",
                                  psprite->GetName().ToCStr());
        return;
    }
    BitmapData*    pbmpData = static_cast<BitmapData*>(pobj.GetPtr());
    ImageResource* pimage   = pbmpData->pImageRes;
    if (!pimage)
    {
        psprite->LogScriptWarning("%s.attachBitmap() failed - no image set in BitmapData.",
                                  psprite->GetName().ToCStr());
        return;
    }

    int         depth = int(ArgCopy(&fn, 1)->ToNumber(fn.Env)) + 0x4000;
    CharPosInfo pos(ResourceId(1), depth, true, Cxform::Identity, true, Matrix2F::Identity);
    if (depth < 0 || depth > 0x7efffffd)
    {
        psprite->LogScriptWarning("%s.attachBitmap() failed - depth (%d) must be >= 0",
                                  psprite->GetName().ToCStr(), pos.Depth);
        return;
    }

    bool       smoothing = (fn.NArgs >= 4) ? ArgCopy(&fn, 3)->ToBool(fn.Env) : false;
    MovieImpl* proot     = fn.Env->GetTarget()->GetMovieImpl();
    MovieRoot* pasRoot   = static_cast<MovieRoot*>(proot->pASMovieRoot);
    Ptr<MovieDefImpl> pimgDef = *proot->CreateImageMovieDef(pimage, smoothing, "");
    if (!pimgDef)
        return;
    pimgDef->GetDataDef()->pData->SetExtMovieDef(pbmpData->pMovieDef);

    Ptr<Sprite> pnewCh = *pasRoot->CreateSprite(pimgDef->GetDataDef(), pimgDef, psprite, ResourceId(0x10001), true);
    if (pnewCh)
    {
        CharPosInfo pos2(ResourceId(1), 1, false, Cxform(), true, Matrix2F());
        ASString    emptyName(fn.Env->GetBuiltin(ASBuiltin_empty_));
        pnewCh->AddToPlayList();
        AS3::Sfr34_ModifyOptimizedPlayList(pnewCh);
        pnewCh->AddDisplayObject(pos2, emptyName, 0, 0, 1, 0, 0, 0);
        psprite->ReplaceDisplayObject(pos, pnewCh, emptyName);
        psprite->SetAcceptAnimMoves(false);
    }
}

// removeTextField(): only for fields created by script (depth from 0x4000 on).
// @0x14290a0f0
void AvmTextField::RemoveTextField(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    InteractiveObject* pch = ToCharacter(ptf);
    if (pch->Depth < 0x4000)
    {
        pch->LogScriptWarning("%s.removeMovieClip() failed - depth must be >= 0", pch->GetName().ToCStr());
        return;
    }
    pch->RemoveDisplayObject();
}

// The boundaries of a character in pixels as a Rectangle, null if there is no such character.
static __forceinline void SetCharBoundariesResult(const FnCall& fn, bool found, const RectF& rect)
{
    if (found)
    {
        Ptr<RectangleObject> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) RectangleObject(fn.Env);
        Render::RectD r(Render::TwipsToPixels(Double(rect.x1)), Render::TwipsToPixels(Double(rect.y1)), Render::TwipsToPixels(Double(rect.x2)),
                Render::TwipsToPixels(Double(rect.y2)));
        pobj->SetProperties(fn.Env, r);
        fn.Result->SetAsObject(pobj);
    }
    else
        fn.Result->SetNull();
}

// getCharBoundaries(charIndex)
// @0x14290a180
void AvmTextField::GetCharBoundaries(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    unsigned idx = fn.Arg(0).ToUInt32(fn.Env);
    Text::DocView* pdoc = ptf->GetDocument();
    RectF    rect(0);
    bool     found = pdoc->GetCharBoundaries(&rect, idx);
    SetCharBoundariesResult(fn, found, rect);
}

// getCharIndexAtPoint(x, y): -1 if there is no character there.
// @0x14290a350
void AvmTextField::GetCharIndexAtPoint(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 2)
        return;
    Number x   = fn.Arg(0).ToNumber(fn.Env);
    Number y   = fn.Arg(1).ToNumber(fn.Env);
    UPInt  pos = ptf->GetDocument()->GetCharIndexAtPoint(float(Render::PixelsToTwips(x)), float(Render::PixelsToTwips(y)));
    if (pos != SF_MAX_UPINT)
        FUN_14000d250(fn.Result, Number(pos));
    else
        FUN_14000d250(fn.Result, -1);
}

// getExactCharBoundaries(charIndex)
// @0x14290a4b0
void AvmTextField::GetExactCharBoundaries(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    unsigned idx = fn.Arg(0).ToUInt32(fn.Env);
    Text::DocView* pdoc = ptf->GetDocument();
    RectF    rect(0);
    bool     found = pdoc->GetExactCharBoundaries(&rect, idx);
    SetCharBoundariesResult(fn, found, rect);
}

// getLineIndexAtPoint(x, y): -1 if there is no line there.
// @0x14290a680
void AvmTextField::GetLineIndexAtPoint(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 2)
        return;
    Number   x    = fn.Arg(0).ToNumber(fn.Env);
    Number   y    = fn.Arg(1).ToNumber(fn.Env);
    unsigned line = ptf->GetDocument()->GetLineIndexAtPoint(float(Render::PixelsToTwips(x)), float(Render::PixelsToTwips(y)));
    if (line != ~0u)
        FUN_14000d250(fn.Result, Number(line));
    else
        FUN_14000d250(fn.Result, -1);
}

// getLineIndexOfChar(charIndex)
// @0x14290a7d0
void AvmTextField::GetLineIndexOfChar(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int idx = int(fn.Arg(0).ToNumber(fn.Env));
    if (idx < 0)
    {
        FUN_14000d250(fn.Result, -1);
        return;
    }
    unsigned line = ptf->GetDocument()->GetLineIndexOfChar(unsigned(idx));
    if (line != ~0u)
        FUN_14000d250(fn.Result, Number(line));
    else
        FUN_14000d250(fn.Result, -1);
}

// getLineOffset(lineIndex): the index of its first character.
// @0x14290a8c0
void AvmTextField::GetLineOffset(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int line = int(fn.Arg(0).ToNumber(fn.Env));
    if (line < 0)
    {
        FUN_14000d250(fn.Result, -1);
        return;
    }
    UPInt off = ptf->GetDocument()->GetLineOffset(unsigned(line));
    if (off != SF_MAX_UPINT)
        FUN_14000d250(fn.Result, Number(off));
    else
        FUN_14000d250(fn.Result, -1);
}

// getLineLength(lineIndex)
// @0x14290a9c0
void AvmTextField::GetLineLength(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int line = int(fn.Arg(0).ToNumber(fn.Env));
    if (line < 0)
    {
        FUN_14000d250(fn.Result, -1);
        return;
    }
    UPInt len = ptf->GetDocument()->GetLineLength(unsigned(line), 0);
    if (len != SF_MAX_UPINT)
        FUN_14000d250(fn.Result, Number(len));
    else
        FUN_14000d250(fn.Result, -1);
}

// getFirstCharInParagraph(charIndex)
// @0x14290b1c0
void AvmTextField::GetFirstCharInParagraph(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int idx = int(fn.Arg(0).ToNumber(fn.Env));
    if (idx < 0)
    {
        FUN_14000d250(fn.Result, -1);
        return;
    }
    UPInt pos = ptf->GetDocument()->GetFirstCharInParagraph(unsigned(idx));
    if (pos != SF_MAX_UPINT)
        FUN_14000d250(fn.Result, Number(pos));
    else
        FUN_14000d250(fn.Result, -1);
}

// appendText(text): not for a field with a style sheet.
// @0x14290b920
void AvmTextField::AppendText(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    Value*   parg = ArgCopy(&fn, 0);
    ASString str = parg->ToString(fn.Env);
    ptf->GetDocument()->AppendText(str.ToCStr(), SF_MAX_UPINT);
    ptf->SetCompleteReformatReq();
    ptf->SetDirtyFlag();
}

// The SDK's header-inline ObjectInterface::SetConstMemberRaw, which the exe inlines here.
static SF_FORCEINLINE bool GlmSetConstMemberRaw(ObjectInterface& obj, ASStringContext* psc, const char* pname, const Value& val)
{
    return obj.SetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val);
}

// getLineMetrics(lineIndex): an object with the line's ascent, descent, width, height, leading and x in pixels.
// @0x14290aac0
void AvmTextField::GetLineMetrics(const FnCall& fn)
{
    if (IsTextFieldTarget(fn))
    {
        TextField* pthis = GetTextFieldTarget(fn);
        if (fn.NArgs >= 1)
        {
            int lineIndex = int(fn.Arg(0).ToNumber(fn.Env));
            if (lineIndex < 0)
                fn.Result->SetUndefined();
            else
            {
                Render::Text::DocView::LineMetrics metrics;
                bool rv = pthis->GetDocument()->GetLineMetrics(unsigned(lineIndex), &metrics);
                if (rv)
                {
                    Ptr<Object> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "ascent", Value(Render::TwipsToPixels((Number)metrics.Ascent)));
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "descent", Value(Render::TwipsToPixels((Number)metrics.Descent)));
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "width", Value(Render::TwipsToPixels((Number)metrics.Width)));
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "height", Value(Render::TwipsToPixels((Number)metrics.Height)));
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "leading", Value(Render::TwipsToPixels((Number)metrics.Leading)));
                    GlmSetConstMemberRaw(*pobj, fn.Env->GetSC(), "x", Value(Render::TwipsToPixels((Number)metrics.FirstCharXOff)));
                    fn.Result->SetAsObject(pobj);
                }
                else
                    fn.Result->SetUndefined();
            }
        }
    }
}

// getLineText(lineIndex): undefined for a negative index, "" past the last line.
// @0x14290afc0
void AvmTextField::GetLineText(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int line = int(fn.Arg(0).ToNumber(fn.Env));
    if (line < 0)
    {
        fn.Result->SetUndefined();
        return;
    }
    Render::Text::DocView* pdoc = ptf->GetDocument();
    UPInt                  len  = 0;
    const wchar_t*         ptext = pdoc->GetLineText(unsigned(line), &len);
    if (ptext)
    {
        String str;
        str.AppendString(ptext, SPInt(len));
        fn.Result->SetString(fn.Env->CreateString(str));
    }
    else
        fn.Result->SetString(fn.Env->CreateConstString(""));
}

// appendHtml(html): not for a field with a style sheet; <img> tags become image substitutions.
// MS2-FUNCTIONAL scheduling only: the exe loads pDocument (+0xe0) between the image array's zero stores; cl loads it after them (doc local, pDocument->, SDK TextField::AppendHtml wrapper, real HTMLImageTagInfoArray type and the SDK nested-if body tried)
// @0x14290b9f0
void AvmTextField::AppendHtml(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    Value*                        parg = ArgCopy(&fn, 0);
    ASString                      str = parg->ToString(fn.Env);
    ArrayDH<MS2_HTMLImageTagInfo> imageInfoArray(Memory::GetHeapByAddress(ptf));
    ptf->GetDocument()->AppendHtml(str.ToCStr(), SF_MAX_UPINT, false, reinterpret_cast<Render::Text::StyledText::HTMLImageTagInfoArray*>(&imageInfoArray));
    ptf->SetCompleteReformatReq();
    if (imageInfoArray.GetSize() > 0)
        ptf->ProcessImageTags(*reinterpret_cast<Render::Text::StyledText::HTMLImageTagInfoArray*>(&imageInfoArray));
    ptf->SetDirtyFlag();
}

// copyToClipboard([richClipboard, startIndex, endIndex]): by default the selection, rich when the editor uses the
// rich clipboard.
// The arguments are read through the out-of-line FnCall::Arg, as in the exe.
// @0x14290bb20
void AvmTextField::CopyToClipboard(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    void* pek = DocView_GetEditorKit(GetTextFieldTarget(fn)->GetDocument());
    if (!pek)
        return;
    bool     richClipboard = EditorKit_DoesUseRichClipboard(pek);
    unsigned startPos      = unsigned(DocView_GetBeginSelection(EditorKit_GetDocView(pek)));
    unsigned endPos        = unsigned(DocView_GetEndSelection(EditorKit_GetDocView(pek)));
    if (fn.NArgs >= 1)
        richClipboard = ArgCopy(&fn, 0)->ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = ArgCopy(&fn, 1)->ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = ArgCopy(&fn, 2)->ToUInt32(fn.Env);
    static_cast<Scaleform::GFx::Text::EditorKit*>(pek)->CopyToClipboard(startPos, endPos, richClipboard);
}

// cutToClipboard([richClipboard, startIndex, endIndex])
// The arguments are read through the out-of-line FnCall::Arg, as in the exe.
// @0x14290bc50
void AvmTextField::CutToClipboard(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    void*      pek = DocView_GetEditorKit(ptf->GetDocument());
    if (!pek)
        return;
    bool     richClipboard = EditorKit_DoesUseRichClipboard(pek);
    unsigned startPos      = unsigned(DocView_GetBeginSelection(EditorKit_GetDocView(pek)));
    unsigned endPos        = unsigned(DocView_GetEndSelection(EditorKit_GetDocView(pek)));
    if (fn.NArgs >= 1)
        richClipboard = ArgCopy(&fn, 0)->ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = ArgCopy(&fn, 1)->ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = ArgCopy(&fn, 2)->ToUInt32(fn.Env);
    static_cast<Scaleform::GFx::Text::EditorKit*>(pek)->CutToClipboard(startPos, endPos, richClipboard);
    ptf->SetDirtyFlag();
}

// pasteFromClipboard([richClipboard, startIndex, endIndex]): replaces the range.
// The arguments are read through the out-of-line FnCall::Arg, as in the exe.
// @0x14290bd90
void AvmTextField::PasteFromClipboard(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    void*      pek = DocView_GetEditorKit(ptf->GetDocument());
    if (!pek)
        return;
    bool     richClipboard = EditorKit_DoesUseRichClipboard(pek);
    unsigned startPos      = unsigned(DocView_GetBeginSelection(EditorKit_GetDocView(pek)));
    unsigned endPos        = unsigned(DocView_GetEndSelection(EditorKit_GetDocView(pek)));
    if (fn.NArgs >= 1)
        richClipboard = ArgCopy(&fn, 0)->ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = ArgCopy(&fn, 1)->ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = ArgCopy(&fn, 2)->ToUInt32(fn.Env);
    static_cast<Scaleform::GFx::Text::EditorKit*>(pek)->PasteFromClipboard(startPos, endPos, richClipboard);
    ptf->SetDirtyFlag();
}

// replaceSel(text): the selection becomes text in the field's default formats, the cursor goes behind it.
// @0x142909b00
void AvmTextField::ReplaceSel(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1 || !DocView_GetEditorKit(ptf->GetDocument()))
        return;
    ASString    str         = fn.Arg(0).ToString(fn.Env);
    void*       pstyledText = DocView_GetStyledText(ptf->GetDocument());
    const void* ptextFmt    = StyledText_GetDefaultTextFormat(pstyledText);
    const void* pparaFmt    = StyledText_GetDefaultParagraphFormat(pstyledText);
    unsigned    len         = str.GetLength();
    void*       pdocView    = EditorKit_GetDocView(DocView_GetEditorKit(ptf->GetDocument()));
    UPInt       startPos    = DocView_GetBeginSelection(pdocView);
    UPInt       endPos      = DocView_GetEndSelection(pdocView);
    if (len < 1024)
    {
        wchar_t wbuf[1024];
        UTF8Util::DecodeString(wbuf, str.ToCStr());
        ptf->ReplaceTextA(wbuf, startPos, endPos, SF_MAX_UPINT);
    }
    else
    {
        wchar_t* pwbuf = (wchar_t*)SF_ALLOC(UPInt(len + 1) * sizeof(wchar_t), StatMV_Text_Mem);
        UTF8Util::DecodeString(pwbuf, str.ToCStr());
        ptf->ReplaceTextA(pwbuf, startPos, endPos, SF_MAX_UPINT);
        SF_FREE(pwbuf);
    }
    UPInt newEnd = startPos + len;
    ((::Scaleform::GFx::Text::EditorKit*)(DocView_GetEditorKit(ptf->GetDocument())))->SetCursorPos(newEnd, false);
    if (pparaFmt)
        ptf->GetDocument()->SetParagraphFormat(*(const Render::Text::ParagraphFormat*)pparaFmt, startPos, newEnd);
    if (ptextFmt)
        ptf->GetDocument()->SetTextFormat(*(const Render::Text::TextFormat*)ptextFmt, startPos, newEnd);
    ptf->SetDirtyFlag();
}

// replaceText(beginIndex, endIndex, text): text takes the formats of the first replaced character.
// MS2-FUNCTIONAL 0x142909d80: 1 byte off: newEnd's add is lea ebx,[r14+r15] (startPos+len), the exe has [r15+r14]; reordering the
// operands or the references to startPos/len (fe36 variants) does not move it
// @0x142909d80
void AvmTextField::ReplaceTextA(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 3)
        return;
    Number   start = ArgCopy(&fn, 0)->ToNumber(fn.Env);
    Number   end   = ArgCopy(&fn, 1)->ToNumber(fn.Env);
    Value*   ptext = ArgCopy(&fn, 2);
    ASString str   = ptext->ToString(fn.Env);
    unsigned len   = str.GetLength();
    unsigned startPos = unsigned(start);
    unsigned endPos   = unsigned(end);
    if (!(start >= 0) || !(end >= 0) || startPos > endPos)
        return;
    UPInt       textLen  = reinterpret_cast<Render::Text::StyledText*>(DocView_GetStyledText(ptf->GetDocument()))->GetLength();
    UPInt       newLen   = UPInt(len) - UPInt(endPos - startPos) + textLen;
    void*       pdoc = ptf->GetDocument();
    const void* ptextFmt; // both branches set them (the exe has no zero init)
    const void* pparaFmt;
    if (startPos >= textLen)
    {
        ptextFmt = StyledText_GetDefaultTextFormat(DocView_GetStyledText(pdoc));
        pparaFmt = StyledText_GetDefaultParagraphFormat(DocView_GetStyledText(pdoc));
    }
    else
        static_cast<Render::Text::StyledText*>(DocView_GetStyledText(ptf->GetDocument()))->GetTextAndParagraphFormat((const Render::Text::TextFormat**)&ptextFmt, (const Render::Text::ParagraphFormat**)&pparaFmt, startPos);
    // Both are held across the replacement.
    if (ptextFmt)
        ++*(int*)ptextFmt;
    if (pparaFmt)
        ++*(int*)pparaFmt;
    if (len < 1024)
    {
        wchar_t wbuf[1024];
        UTF8Util::DecodeString(wbuf, str.ToCStr());
        ptf->ReplaceTextA(wbuf, startPos, endPos, SF_MAX_UPINT);
    }
    else
    {
        wchar_t* pwbuf = (wchar_t*)SF_ALLOC(UPInt(len + 1) * sizeof(wchar_t), StatMV_Text_Mem);
        UTF8Util::DecodeString(pwbuf, str.ToCStr());
        ptf->ReplaceTextA(pwbuf, startPos, endPos, SF_MAX_UPINT);
        SF_FREE(pwbuf);
    }
    void* pek = DocView_GetEditorKit(ptf->GetDocument());
    if (pek && ((::Scaleform::GFx::Text::EditorKit*)(pek))->GetCursorPos() > newLen)
        ((::Scaleform::GFx::Text::EditorKit*)(DocView_GetEditorKit(ptf->GetDocument())))->SetCursorPos(newLen, false);
    unsigned newEnd = startPos + len;
    if (pparaFmt)
        ptf->GetDocument()->SetParagraphFormat(*(const Render::Text::ParagraphFormat*)pparaFmt, startPos, newEnd);
    if (ptextFmt)
        ptf->GetDocument()->SetTextFormat(*(const Render::Text::TextFormat*)ptextFmt, startPos, newEnd);
    if (ptextFmt)
        ((const Render::Text::TextFormat*)ptextFmt)->Release();
    if (pparaFmt)
        ((const Render::Text::ParagraphFormat*)pparaFmt)->Release();
    ptf->SetDirtyFlag();
}

// setTextFormat([beginIndex, [endIndex,]] textFormat): the whole text, one character or [beginIndex, endIndex).
// @0x142909300
void AvmTextField::SetTextFormat(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet())
        return;
    if (fn.NArgs == 1)
    {
        Object* pobj = ArgCopy(&fn, 0)->ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
            ptf->GetDocument()->SetTextFormat(pfmtObj->GetTextFormat(), 0, SF_MAX_UPINT);
            ptf->GetDocument()->SetParagraphFormat(pfmtObj->GetParagraphFormat(), 0, SF_MAX_UPINT);
            ptf->SetDirtyFlag();
        }
    }
    else if (fn.NArgs == 2)
    {
        Object* pobj = ArgCopy(&fn, 1)->ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            Number pos = ArgCopy(&fn, 0)->ToNumber(fn.Env);
            if (pos >= 0)
            {
                TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
                unsigned          upos    = unsigned(pos);
                ptf->GetDocument()->SetTextFormat(pfmtObj->GetTextFormat(), upos, upos + 1);
                ptf->GetDocument()->SetParagraphFormat(pfmtObj->GetParagraphFormat(), upos, upos + 1);
                ptf->SetDirtyFlag();
            }
        }
    }
    else if (fn.NArgs >= 3)
    {
        Object* pobj = ArgCopy(&fn, 2)->ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            Number start = Alg::Max(Number(0), ArgCopy(&fn, 0)->ToNumber(fn.Env));
            Number end   = Alg::Max(Number(0), ArgCopy(&fn, 1)->ToNumber(fn.Env));
            if (end >= start)
            {
                TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
                unsigned          ustart  = unsigned(start);
                unsigned          uend    = unsigned(end);
                ptf->GetDocument()->SetTextFormat(pfmtObj->GetTextFormat(), ustart, uend);
                ptf->GetDocument()->SetParagraphFormat(pfmtObj->GetParagraphFormat(), ustart, uend);
                ptf->SetDirtyFlag();
            }
        }
    }
}

// TextField::SetDefaultTextFormat and SetDefaultParagraphFormat: the document's default, then a full reformat.
static SF_FORCEINLINE void TextField_SetDefaultTextFormat(TextField* ptf, const Render::Text::TextFormat& textFmt)
{
    ptf->GetDocument()->SetDefaultTextFormat(textFmt);
    ptf->SetCompleteReformatReq();
}

static SF_FORCEINLINE void TextField_SetDefaultParagraphFormat(TextField* ptf, const Render::Text::ParagraphFormat& paraFmt)
{
    ptf->GetDocument()->SetDefaultParagraphFormat(paraFmt);
    ptf->SetCompleteReformatReq();
}

// setNewTextFormat(textFormat): merged into the formats new text gets.
// @0x142909590
void AvmTextField::SetNewTextFormat(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    Object* pobj = ArgCopy(&fn, 0)->ToObject(fn.Env);
    if (pobj && pobj->GetObjectType() == Object_TextFormat)
    {
        TextFormatObject* pfmtObj     = static_cast<TextFormatObject*>(pobj);
        void*             pstyledText = DocView_GetStyledText(ptf->GetDocument());
        const Render::Text::TextFormat* ptextFmt =
            (const Render::Text::TextFormat*)StyledText_GetDefaultTextFormat(pstyledText);
        const Render::Text::ParagraphFormat* pparaFmt =
            (const Render::Text::ParagraphFormat*)StyledText_GetDefaultParagraphFormat(pstyledText);
        TextField_SetDefaultTextFormat(ptf, ptextFmt->Merge(pfmtObj->GetTextFormat()));
        TextField_SetDefaultParagraphFormat(ptf, pparaFmt->Merge(pfmtObj->GetParagraphFormat()));
    }
}

// The formats of the Text library: this TU calls their destructors out of line.
struct TextFormatLocal02
{
    union { Render::Text::TextFormat F; };
    SF_FORCEINLINE TextFormatLocal02(MemoryHeap* pheap) : F(pheap) {}
    SF_FORCEINLINE ~TextFormatLocal02() { ::FUN_1424aa0f0(&F); }
};
struct ParagraphFormatLocal02
{
    union { Render::Text::ParagraphFormat F; };
    SF_FORCEINLINE ParagraphFormatLocal02() : F() {}
    SF_FORCEINLINE ~ParagraphFormatLocal02() { F.Render::Text::ParagraphFormat::~ParagraphFormat(); }
};

// getTextFormat([beginIndex, [endIndex]]): a TextFormat with what the characters of the range have in common.
// @0x1429096e0
void AvmTextField::GetTextFormat(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
    {
        fn.Result->SetUndefined();
        return;
    }
    TextField* ptf        = GetTextFieldTarget(fn);
    UPInt      beginIndex = 0;
    UPInt      endIndex   = SF_MAX_UPINT;
    if (fn.NArgs >= 1)
    {
        Number begin = Alg::Max(Number(0), fn.Arg(0).ToNumber(fn.Env));
        if (begin >= 0)
            beginIndex = unsigned(begin);
    }
    if (fn.NArgs >= 2)
    {
        Number end = Alg::Max(Number(0), fn.Arg(1).ToNumber(fn.Env));
        if (end >= 0)
            endIndex = unsigned(end);
    }
    else if (fn.NArgs >= 1)
    {
        // Only the character at beginIndex without an endIndex.
        Number end = Alg::Max(Number(0), ArgCopy(&fn, 0)->ToNumber(fn.Env) + 1);
        if (end >= 0)
            endIndex = unsigned(end);
    }
    if (beginIndex <= endIndex)
    {
        TextFormatLocal02      textFmtL(fn.Env->GetHeap());
        ParagraphFormatLocal02 paraFmtL;
        Render::Text::TextFormat&      textFmt = textFmtL.F;
        Render::Text::ParagraphFormat& paraFmt = paraFmtL.F;
        reinterpret_cast<Render::Text::StyledText*>(DocView_GetStyledText(ptf->GetDocument()))
            ->GetTextAndParagraphFormat(&textFmt, &paraFmt, beginIndex, endIndex);
        Ptr<TextFormatObject> pfmtObj = *SF_HEAP_NEW(fn.Env->GetHeap()) TextFormatObject(fn.Env);
        pfmtObj->SetTextFormat(fn.Env->GetSC(), textFmt);
        pfmtObj->SetParagraphFormat(fn.Env->GetSC(), paraFmt);
        fn.Result->SetAsObject(pfmtObj);
    }
    else
        fn.Result->SetUndefined();
}

// getNewTextFormat(): a TextFormat with the formats new text gets.
// @0x1429099d0
void AvmTextField::GetNewTextFormat(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
    {
        fn.Result->SetUndefined();
        return;
    }
    TextField* ptf         = GetTextFieldTarget(fn);
    void*      pstyledText = DocView_GetStyledText(ptf->GetDocument());
    const Render::Text::TextFormat* ptextFmt =
        (const Render::Text::TextFormat*)StyledText_GetDefaultTextFormat(pstyledText);
    const Render::Text::ParagraphFormat* pparaFmt =
        (const Render::Text::ParagraphFormat*)StyledText_GetDefaultParagraphFormat(pstyledText);
    Ptr<TextFormatObject> pfmtObj = *SF_HEAP_NEW(fn.Env->GetHeap()) TextFormatObject(fn.Env);
    if (ptextFmt)
        pfmtObj->SetTextFormat(fn.Env->GetSC(), *ptextFmt);
    if (pparaFmt)
        pfmtObj->SetParagraphFormat(fn.Env->GetSC(), *pparaFmt);
    fn.Result->SetAsObject(pfmtObj);
}

// setImageSubstitutions(null | substitution object | array of them); null drops every substitution.
// @0x14290b2c0
void AvmTextField::SetImageSubstitutions(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    if (fn.Arg(0).IsNull())
    {
        ((::Scaleform::GFx::TextField*)(ptf))->ClearIdImageDescAssoc();
        void* pdoc   = ptf->GetDocument();
        void* psubst = DocView_GetImageSubstitutor(pdoc);
        if (psubst)
        {
            reinterpret_cast<Scaleform::As202SubstArr*>(psubst)->As202SubstArr::~As202SubstArr();
            SF_FREE(psubst);
        }
        DocView_SetImageSubstitutor(pdoc, 0);
        DocView_SetReformatReq(ptf->GetDocument());
        ptf->SetDirtyFlag();
        return;
    }
    // The field as a character (TextField is opaque here).
    InteractiveObject* pch  = reinterpret_cast<InteractiveObject*>(ptf);
    Object*            pobj = ArgCopy(&fn, 0)->ToObject(fn.Env);
    if (pobj)
    {
        // FromCharacter(pch) at each call (the exe re-reads the AvmTextField offset per element)
        if (pobj->GetObjectType() == Object_Array)
        {
            ArrayObject* parr = static_cast<ArrayObject*>(pobj);
            for (int i = 0, n = parr->GetSize(); i < n; ++i)
                FromCharacter(pch)->ProceedImageSubstitution(fn, i, parr->GetElementPtr(i));
        }
        else
            { const Value* parg = ArgCopy(&fn, 0); FromCharacter(pch)->ProceedImageSubstitution(fn, 0, parg); }
    }
    else
        pch->LogScriptWarning("%s.setImageSubstitutions() failed: parameter should be either 'null', object or array",
                              pch->GetName().ToCStr());
}
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
// The exe inlines CheckExpand into the FunctionRef node add.
template<> SF_FORCEINLINE void GFx::ASStringHash_GC<GFx::AS2::FunctionRef>::SetType::SelfType::CheckExpand(void* pheapAddr)
{
    if (pTable == 0)
        setRawCapacity(pheapAddr, HashMinSize);
    else if (pTable->EntryCount * 5 > (pTable->SizeMask + 1) * 4)
        setRawCapacity(pheapAddr, (pTable->SizeMask + 1) * 2);
}
// (pinned below)
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
// The exe inlines CheckExpand into both event handler adds.
template<> SF_FORCEINLINE void MS2_AS2EventHandlerSet::CheckExpand(void* pheapAddr)
{
    if (pTable == 0)
        setRawCapacity(pheapAddr, HashMinSize);
    else if (pTable->EntryCount * 5 > (pTable->SizeMask + 1) * 4)
        setRawCapacity(pheapAddr, (pTable->SizeMask + 1) * 2);
}
// (pinned below)
// @0x1429159d0
template void MS2_AS2EventHandlerSet::add<MS2_AS2EventHandlerNode>(void*, const MS2_AS2EventHandlerNode&, UPInt);
// (pinned below)
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
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
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
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e2c8
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e310
// MS2-PIN: ??_7GlyphVisitor@StaticTextSnapshotData@GFx@Scaleform@@6B@ 0x14316a500
// MS2-PIN: ??_7GASTextSnapshotGlyphVisitor@AS2@GFx@Scaleform@@6B@ 0x1432228a0
// MS2-PIN: ??_7?$RefCountBaseNTS@VSharedObjectVisitor@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143162f10
// MS2-PIN: ??_7SharedObjectVisitor@GFx@Scaleform@@6B@ 0x143162f18
// MS2-PIN: ??_7GASSharedObjectLoader@AS2@GFx@Scaleform@@6B@ 0x1432227a8
// MS2-PIN: ??$add@UNodeRef@?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@1@_K@Z 0x1429162d0
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@6B@ 0x143215370
// MS2-PIN: ??_7?$ASRefCountBase@UValueProperty@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432153d0
// MS2-PIN: ??_7ValueProperty@AS2@GFx@Scaleform@@6B@ 0x1432153e8
