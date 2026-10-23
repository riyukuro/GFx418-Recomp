// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector traversals
// (ForEachChild_GC of the collectable classes and of every built-in prototype, for the release, mark-in-cycle and
// scan-in-use passes) and the Stage function stub.
// MS2-UNIT: sfr_as2_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428fdc00-0x1428ff660 .text$mn
// MS2-RANGE: 0x1428ffcd0-0x1429006a0 .text$mn
// MS2-RANGE: 0x142900f50-0x142900fc0 .text$mn
// MS2-RANGE: 0x142901ae0-0x142902a00 .text$mn
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
// MS2-RANGE: 0x142901280-0x142901406 .text$mn
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
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
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

// Render::Text::DocView (render/text_docview.h needs the full kernel array headers, not the ones of this unit): the
// document view calls of the TextField natives, by address.
unsigned long long FUN_142612af0(void* pdoc, unsigned long long pos);       // DocView::GetFirstCharInParagraph
unsigned FUN_142612c50(void* pdoc, unsigned long long pos);                 // DocView::GetLineIndexOfChar
unsigned long long FUN_142612cb0(void* pdoc, unsigned line, bool* phasNewLine);  // DocView::GetLineLength
unsigned long long FUN_142612e80(void* pdoc, unsigned line);                // DocView::GetLineOffset
unsigned long long FUN_142612240(void* pdoc, float x, float y);             // DocView::GetCharIndexAtPoint
unsigned FUN_142612bd0(void* pdoc, float x, float y);                       // DocView::GetLineIndexAtPoint
bool     FUN_142611ff0(void* pdoc, Scaleform::Render::RectF* prect, unsigned long long pos);  // DocView::GetCharBoundaries
bool     FUN_142612740(void* pdoc, Scaleform::Render::RectF* prect, unsigned long long pos);  // DocView::GetExactCharBoundaries
void     FUN_14260df50(void* pdoc, const char* putf8Str, unsigned long long utf8Len);        // DocView::AppendText
void     FUN_14260de50(void* pdoc, const char* phtml, unsigned long long htmlSize, bool condenseWhite,
                       void* pimgInfoArr);                                                 // DocView::AppendHtml
void     FUN_1425ba7d0(void* ptf, void* pimgInfoArr);                                       // TextField::ProcessImageTags
bool     FUN_142612d50(void* pdoc, unsigned line, void* pmetrics);                          // DocView::GetLineMetrics
const wchar_t* FUN_142612f00(void* pdoc, unsigned line, unsigned long long* plen);         // DocView::GetLineText
void     FUN_142617440(void* pek, unsigned long long startPos, unsigned long long endPos, bool useRichClipboard);  // EditorKit::CopyToClipboard
void     FUN_1426175b0(void* pek, unsigned long long startPos, unsigned long long endPos, bool useRichClipboard);  // EditorKit::CutToClipboard
unsigned long long FUN_142619270(void* pek, unsigned long long startPos, unsigned long long endPos,
                                 bool useRichClipboard);                                   // EditorKit::PasteFromClipboard
// The DocView / EditorKit fields the clipboard natives read.
inline void* DocView_GetEditorKit(void* pdoc) { return *(void**)((char*)pdoc + 0xd8); }
inline unsigned long long DocView_SelectionPos(void* pdoc, int i) { return ((unsigned long long*)((char*)pdoc + 0x38))[i]; }
inline unsigned long long DocView_GetBeginSelection(void* pdoc)
{
    return DocView_SelectionPos(pdoc, 0) < DocView_SelectionPos(pdoc, 1) ? DocView_SelectionPos(pdoc, 0) : DocView_SelectionPos(pdoc, 1);
}
inline unsigned long long DocView_GetEndSelection(void* pdoc)
{
    return DocView_SelectionPos(pdoc, 0) > DocView_SelectionPos(pdoc, 1) ? DocView_SelectionPos(pdoc, 0) : DocView_SelectionPos(pdoc, 1);
}
inline void* EditorKit_GetDocView(void* pek) { return *(void**)((char*)pek + 0x10); }
inline bool  EditorKit_DoesUseRichClipboard(void* pek) { return (*((unsigned char*)pek + 0xa0) & 4) != 0; }
inline void* DocView_GetStyledText(void* pdoc) { return *(void**)((char*)pdoc + 0x10); }
inline const void* StyledText_GetDefaultParagraphFormat(void* pst) { return *(const void**)((char*)pst + 0x30); }
inline const void* StyledText_GetDefaultTextFormat(void* pst) { return *(const void**)((char*)pst + 0x38); }
unsigned long long FUN_142598a50(void* pst);                                               // StyledText::GetLength
bool     FUN_1425996b0(void* pst, const void** pptextFmt, const void** ppparaFmt, unsigned long long pos);  // StyledText::GetTextAndParagraphFormat
unsigned long long FUN_142617990(void* pek);                                               // EditorKit::GetCursorPos
void     FUN_142619b80(void* pek, unsigned long long pos, bool updateSelection);            // EditorKit::SetCursorPos
void     FUN_142615410(void* pdoc, const void* pparaFmt, unsigned long long startPos, unsigned long long endPos);  // DocView::SetParagraphFormat
void     FUN_142615640(void* pdoc, const void* ptextFmt, unsigned long long startPos, unsigned long long endPos);  // DocView::SetTextFormat
void     FUN_1424ae680(const void* ptextFmt);                                               // TextFormat::Release
void     FUN_1424ae650(const void* pparaFmt);                                               // ParagraphFormat::Release
void     FUN_1425990d0(void* pst, Scaleform::Render::Text::TextFormat* ptextFmt, Scaleform::Render::Text::ParagraphFormat* pparaFmt,
                       unsigned long long startPos, unsigned long long endPos);            // StyledText::GetTextAndParagraphFormat
void     FUN_14259c250(void* pst, const Scaleform::Render::Text::TextFormat& fmt);                     // StyledText::SetDefaultTextFormat
void     FUN_14259c170(void* pst, const Scaleform::Render::Text::ParagraphFormat& fmt);                // StyledText::SetDefaultParagraphFormat

namespace Scaleform {
// DocView::LineMetrics, in twips.
struct MS2_LineMetrics
{
    unsigned Width, Height;
    unsigned Ascent, Descent;
    int      FirstCharXOff;
    int      Leading;
};
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

// A frame label or a 1-based frame number; unknown labels are ignored.
void AvmSprite::SpriteGotoAndStop(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        psprite->LogScriptWarning("AvmSprite::SpriteGotoAndStop needs one arg");
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
        psprite->LogScriptWarning("AvmSprite::SpriteGotoAndPlay needs one arg");
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

// MS2-FUNCTIONAL the exe clamps the depth before reading fn.Result and keeps 0 in ebp
// @0x142906330
void AvmSprite::SpriteGetNextHighestDepth(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (psprite)
    {
        int depth = Alg::Max(psprite->mDisplayList.GetLargestDepthInUse() - 16383, 0);
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

// Empty in this build (folded with other empty bodies); called on the parent after a depth swap.
void FUN_1425dcaf0(DisplayObjectBase* p);

// Environment::SetTarget, inlined.
static inline void SetEnvTarget(Environment* penv, InteractiveObject* ptarget)
{
    penv->IsInvalidTarget = false;
    penv->Target          = ptarget;
    penv->StringContext.UpdateVersion(ptarget->GetVersion());
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
        FUN_1425dcaf0(pcont);
        if (pother)
            pother->SetAcceptAnimMoves(false);
    }
}

// getBounds / getRect: the clip's bounds in the space of the argument clip (itself by default), in pixels.
static inline void SpriteBoundsObject(const FnCall& fn, bool rectOnly)
{
    Sprite* psprite = AvmSprite::SpriteGetTarget(fn);
    if (!psprite)
        return;
    DisplayObjectBase* pspace = psprite;
    if (fn.NArgs > 0)
        pspace = fn.Arg(0).ToCharacter(fn.Env);
    Sprite* pspaceSprite = (pspace && pspace->IsSprite()) ? static_cast<Sprite*>(pspace) : 0;
    Render::Matrix2F m;
    RectF            b(0, 0, 0, 0);
    if (pspaceSprite)
    {
        if (pspaceSprite != psprite)
        {
            Render::Matrix2F wm;
            pspaceSprite->GetWorldMatrix(&wm);
            Matrix2F_SetInverse(&m, wm);
            Render::Matrix2F cm;
            psprite->GetWorldMatrix(&cm);
            m.Prepend(cm);
        }
        m.EncloseTransform(&b, rectOnly ? psprite->GetRectBounds(Render::Matrix2F()) : psprite->GetBounds(Render::Matrix2F()));
    }
    Ptr<Object> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    ASStringContext* psc = fn.Env->GetSC();
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMin), Value(Render::TwipsToPixels(Double(b.x1))));
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_xMax), Value(Render::TwipsToPixels(Double(b.x2))));
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMin), Value(Render::TwipsToPixels(Double(b.y1))));
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_yMax), Value(Render::TwipsToPixels(Double(b.y2))));
    fn.Result->SetAsObject(pobj);
}

// MS2-FUNCTIONAL bounds object build: register allocation/scheduling differs
// @0x142903b30
void AvmSprite::SpriteGetBounds(const FnCall& fn)
{
    SpriteBoundsObject(fn, false);
}

// MS2-FUNCTIONAL bounds object build: register allocation/scheduling differs
// @0x142903fc0
void AvmSprite::SpriteGetRect(const FnCall& fn)
{
    SpriteBoundsObject(fn, true);
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

// startDrag([lockCenter [, left, top, right, bottom]]): the clip follows the mouse, optionally kept in the rectangle.
// MS2-FUNCTIONAL regalloc: the exe keeps the twips factor and the four bounds in xmm6-xmm11 and an rbp frame
// @0x142906650
void AvmSprite::SpriteStartDrag(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    MovieImpl::DragState st;
    bool lockCenter = false;
    if (fn.NArgs > 0)
    {
        lockCenter = fn.Arg(0).ToBool(fn.Env);
        if (fn.NArgs > 4)
        {
            st.Bound = true;
            float x0 = Render::PixelsToTwips(float(fn.Arg(1).ToNumber(fn.Env)));
            float y0 = Render::PixelsToTwips(float(fn.Arg(2).ToNumber(fn.Env)));
            float x1 = Render::PixelsToTwips(float(fn.Arg(3).ToNumber(fn.Env)));
            float y1 = Render::PixelsToTwips(float(fn.Arg(4).ToNumber(fn.Env)));
            float left = x0, right = x1;
            if (x1 < x0)
            {
                left  = x1;
                right = x0;
            }
            float top = y0, bottom = y1;
            if (y1 < y0)
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

// attachMovie(symbol, name, depth [, initObject]): an instance of an exported library clip; SWF 6+ returns it.
// MS2-FUNCTIONAL IsInteractiveObject tested as al&1
// @0x1429055f0
void AvmSprite::SpriteAttachMovie(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite || fn.NArgs < 3)
        return;
    ASString sym = fn.Arg(0).ToString(fn.Env);
    ResourceBindData resBindData;
    bool found;
    {
        String symstr(sym.ToCStr());
        found = psprite->GetMovieImpl()->FindExportedResource(psprite->GetResourceMovieDef(), &resBindData, symstr);
    }
    if (!found)
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
                fn.Result->SetAsCharacter(newch->IsInteractiveObject() ? static_cast<InteractiveObject*>(newch.GetPtr()) : 0);
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
// MS2-FUNCTIONAL the exe calls FnCall::Arg(0) out of line; IsInteractiveObject tested as al&1
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
    Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, fn.Arg(0).ToString(fn.Env), 0, 0, ~0u, 1, 0, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        fn.Result->SetAsCharacter(newch->IsInteractiveObject() ? static_cast<InteractiveObject*>(newch.GetPtr()) : 0);
    }
}

// A snapshot of the clip's static text.
// @0x1429064b0
void AvmSprite::SpriteGetTextSnapshot(const FnCall& fn)
{
    Sprite* psprite = SpriteGetTarget(fn);
    if (!psprite)
        return;
    Ptr<TextSnapshotObject> psnap = *SF_HEAP_NEW(fn.Env->GetHeap()) TextSnapshotObject(fn.Env);
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
// MS2-FUNCTIONAL the exe inlines ComputeSizeInBytes (out of line in sfr_as2_04)
// @0x142901280
void SharedObjectProto::GetSize(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, SharedObject);
    SharedObject* pthis = static_cast<SharedObject*>(fn.ThisPtr);
    if (!pthis)
        return;
    fn.Result->SetInt((int)pthis->ComputeSizeInBytes(fn.Env));
}

// GetCaseCheck / RemoveCaseCheck of the registered class table (exe 0x142949f60 / 0x14297cd20).
FunctionRef* ClassHash_GetCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive);
void         ClassHash_RemoveCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive);

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
    GlobalContext* pgc = fn.Env->GetSC()->pContext;
    ASString       classname(fn.Arg(0).ToString(fn.Env));
    if (fn.Arg(1).IsFunction())
    {
        FunctionRef func = fn.Arg(1).ToFunction(fn.Env);
        pgc->RegisteredClasses.SetCaseCheck(classname, func, fn.Env->IsCaseSensitive());
        fn.Result->SetBool(true);
    }
    else if (fn.Arg(1).IsNull())
    {
        bool rv = false;
        if (ClassHash_GetCaseCheck(&pgc->RegisteredClasses, classname, fn.Env->IsCaseSensitive()))
        {
            ClassHash_RemoveCaseCheck(&pgc->RegisteredClasses, classname, fn.Env->IsCaseSensitive());
            rv = true;
        }
        fn.Result->SetBool(rv);
    }
    else
        fn.Env->LogScriptError("Second parameter of Object.registerClass(%s, %s) should be function or null",
                               classname.ToCStr(), fn.Arg(1).ToString(fn.Env).ToCStr());
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
        GFx::Value* args = (GFx::Value*)onStack;
        if (nargs > 10)
            args = (GFx::Value*)SF_HEAP_ALLOC(fn.Env->GetHeap(), nargs * sizeof(GFx::Value), Stat_Default_Mem);
        for (unsigned i = 0; i < nargs; i++)
            static_cast<MovieRoot*>(pmovie->pASMovieRoot)
                ->ASValue2GFxValue(fn.Env, fn.Arg(i + 1), Scaleform::Construct<GFx::Value>(&args[i]));

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

// MS2-FUNCTIONAL the exe expands the FunctionRef copy (local frame flag) inline and orders the ToFunction blocks differently
// @0x1428ff660
void ExternalInterfaceCtorFunction::AddCallback(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs < 3)
        return;
    MovieImpl* pmovie = fn.Env->GetTarget()->GetMovieImpl();
    ASString aliasName(fn.Arg(0).ToString(fn.Env));
    FunctionRef func = fn.Arg(2).ToFunction(fn.Env);
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
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line (as createEmptyMovieClip)
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
    Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, fn.Arg(0).ToString(fn.Env), 0, 0, ~0u, 1, 0, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        InteractiveObject* ptextField = newch->IsInteractiveObject() ? static_cast<InteractiveObject*>(newch.GetPtr()) : 0;
        AvmCharacter* pavm = ptextField ? AS2::ToAvmCharacter(ptextField) : 0;
        pavm->SetStandardMember(AvmCharacter::M_x, fn.Arg(2), false);
        pavm->SetStandardMember(AvmCharacter::M_y, fn.Arg(3), false);
        pavm->SetStandardMember(AvmCharacter::M_width, fn.Arg(4), false);
        pavm->SetStandardMember(AvmCharacter::M_height, fn.Arg(5), false);
        fn.Result->SetAsCharacter(ptextField);
    }
}

#pragma strict_gs_check(push, on)
// hitTest(x, y[, shapeFlag[, ...]]) tests a stage point (pixels) against the bounds or the shapes, 3D clips through
// the movie's screen-to-world state; hitTest(target) tests the world bounds of both clips for overlap.
// MS2-FUNCTIONAL: the exe calls FnCall::Arg out of line for the optional arguments and the target
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
        float x = (float)fn.Arg(0).ToNumber(fn.Env) * 20.0f;
        float y = (float)fn.Arg(1).ToNumber(fn.Env) * 20.0f;
        UByte mask = 0;
        if (fn.NArgs >= 3 && fn.Arg(2).ToBool(fn.Env))
            mask = 1;
        if (fn.NArgs >= 4)
            mask |= fn.Arg(3).ToBool(fn.Env) ? 2 : 0;
        Render::PointF pt(x, y);
        MovieImpl* proot = psprite->GetMovieImpl();
        if (proot && psprite->Is3D(true))
        {
            proot->SetNormalizedScreenCoords(pt);
            Matrix3F view;
            Matrix4F proj;
            Render::ScreenToWorld& stw = proot->GetScreenToWorld();
            if (psprite->GetProjectionMatrix3D(&proj))
                stw.SetProjection(proj);
            if (psprite->GetViewMatrix3D(&view))
                stw.SetView(view);
            Matrix3F world;
            psprite->GetWorldMatrix3D(&world);
            stw.SetWorld(world);
            stw.GetWorldPoint(&pt);
            fn.Result->SetBool(psprite->PointTestLocal(pt, mask));
            return;
        }
        Matrix2F level;
        psprite->GetLevelMatrix(&level);
        Render::PointF local = level.TransformByInverse(pt);
        bool hit = false;
        if (!(psprite->Flags & GFx::DisplayObjectBase::Mask_Scale9GridExists))
        {
            if (bounds.Contains(local))
            {
                if (!(mask & 1))
                {
                    fn.Result->SetBool(true);
                    return;
                }
                hit = psprite->PointTestLocal(local, mask);
            }
        }
        else
            hit = psprite->PointTestLocal(local, mask);
        fn.Result->SetBool(hit);
    }
    else if (fn.NArgs == 1)
    {
        InteractiveObject* ptarget = 0;
        const Value& arg = fn.Arg(0);
        if (arg.IsCharacter())
            ptarget = arg.ToCharacter(fn.Env);
        else
        {
            Value val;
            if (fn.Env->GetVariable(arg.ToString(fn.Env), &val))
                ptarget = ResolveCharacterValue(val, fn.Env);
        }
        if (!ptarget)
            return;
        RectF tbounds = ptarget->GetBounds(Matrix2F());
        if (tbounds.IsNull())
            return;
        RectF world1, world2;
        {
            Matrix2F m;
            psprite->GetWorldMatrix(&m);
            m.EncloseTransform(&world1, bounds);
        }
        {
            Matrix2F m;
            ptarget->GetWorldMatrix(&m);
            m.EncloseTransform(&world2, tbounds);
        }
        fn.Result->SetBool(world1.Intersects(world2));
    }
}
#pragma strict_gs_check(pop)

// getLocal(name[, localPath]): shared objects are cached by "localPath:name"; a new one gets its data replayed by
// the shared object manager, null when the name is invalid or nothing could be loaded.
// MS2-FUNCTIONAL: the exe inlines SetNameAndLocalPath (its character switch) and the cache lookup
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
    ASStringHash_GC<SharedObjectPtr>::NodeType* pnode = objects.GetAlt(key);
    if (pnode)
    {
        fn.Result->SetAsObject(pnode->Second.GetPtr());
        return;
    }

    Ptr<SharedObject> pobj = *static_cast<SharedObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_SharedObject)));
    if (!pobj->SetNameAndLocalPath(nameStr, localPathStr))
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
        ASStringHash_GC<SharedObjectPtr>::NodeType::NodeRef e(key, SharedObjectPtr(pobj));
        objects.Add(&pctor->SharedObjects, e);
    }
    else
        fn.Result->SetNull();
}

// attachBitmap(bitmapData, depth[, pixelSnapping, smoothing]): a new sprite showing the image at the depth.
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line for depth and smoothing
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

    int         depth = int(fn.Arg(1).ToNumber(fn.Env)) + 0x4000;
    CharPosInfo pos(ResourceId(1), depth, true, Cxform::Identity, true, Matrix2F::Identity);
    if ((unsigned)depth > 0x7efffffd)
    {
        psprite->LogScriptWarning("%s.attachBitmap() failed - depth (%d) must be >= 0",
                                  psprite->GetName().ToCStr(), pos.Depth);
        return;
    }

    bool       smoothing = (fn.NArgs >= 4) ? fn.Arg(3).ToBool(fn.Env) : false;
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
        pnewCh->ModifyOptimizedPlayList();
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
static void SetCharBoundariesResult(const FnCall& fn, bool found, const RectF& rect)
{
    if (!found)
    {
        fn.Result->SetNull();
        return;
    }
    Ptr<RectangleObject> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) RectangleObject(fn.Env);
    Render::RectD r(Render::TwipsToPixels(Double(rect.x1)), Render::TwipsToPixels(Double(rect.y1)), Render::TwipsToPixels(Double(rect.x2)),
            Render::TwipsToPixels(Double(rect.y2)));
    pobj->SetProperties(fn.Env, r);
    fn.Result->SetAsObject(pobj);
}

// getCharBoundaries(charIndex)
// MS2-FUNCTIONAL the exe inlines the Rectangle result into each caller
// @0x14290a180
void AvmTextField::GetCharBoundaries(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    unsigned idx = fn.Arg(0).ToUInt32(fn.Env);
    RectF    rect(0);
    bool     found = FUN_142611ff0(ptf->GetDocument(), &rect, idx);
    SetCharBoundariesResult(fn, found, rect);
}

// getCharIndexAtPoint(x, y): -1 if there is no character there.
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290a350
void AvmTextField::GetCharIndexAtPoint(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 2)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    Number x   = fn.Arg(0).ToNumber(fn.Env);
    Number y   = fn.Arg(1).ToNumber(fn.Env);
    UPInt  pos = FUN_142612240(ptf->GetDocument(), float(Render::PixelsToTwips(x)), float(Render::PixelsToTwips(y)));
    fn.Result->SetNumber(pos == SF_MAX_UPINT ? -1 : Number(pos));
}

// getExactCharBoundaries(charIndex)
// MS2-FUNCTIONAL the exe inlines the Rectangle result into each caller
// @0x14290a4b0
void AvmTextField::GetExactCharBoundaries(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    unsigned idx = fn.Arg(0).ToUInt32(fn.Env);
    RectF    rect(0);
    bool     found = FUN_142612740(ptf->GetDocument(), &rect, idx);
    SetCharBoundariesResult(fn, found, rect);
}

// getLineIndexAtPoint(x, y): -1 if there is no line there.
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290a680
void AvmTextField::GetLineIndexAtPoint(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 2)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    Number   x    = fn.Arg(0).ToNumber(fn.Env);
    Number   y    = fn.Arg(1).ToNumber(fn.Env);
    unsigned line = FUN_142612bd0(ptf->GetDocument(), float(Render::PixelsToTwips(x)), float(Render::PixelsToTwips(y)));
    fn.Result->SetNumber(line == ~0u ? -1 : Number(line));
}

// getLineIndexOfChar(charIndex)
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290a7d0
void AvmTextField::GetLineIndexOfChar(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    int idx = int(fn.Arg(0).ToNumber(fn.Env));
    if (idx < 0)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    unsigned line = FUN_142612c50(ptf->GetDocument(), unsigned(idx));
    fn.Result->SetNumber(line == ~0u ? -1 : Number(line));
}

// getLineOffset(lineIndex): the index of its first character.
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290a8c0
void AvmTextField::GetLineOffset(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    int line = int(fn.Arg(0).ToNumber(fn.Env));
    if (line < 0)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    UPInt off = FUN_142612e80(ptf->GetDocument(), unsigned(line));
    fn.Result->SetNumber(off == SF_MAX_UPINT ? -1 : Number(off));
}

// getLineLength(lineIndex)
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290a9c0
void AvmTextField::GetLineLength(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    int line = int(fn.Arg(0).ToNumber(fn.Env));
    if (line < 0)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    UPInt len = FUN_142612cb0(ptf->GetDocument(), unsigned(line), 0);
    fn.Result->SetNumber(len == SF_MAX_UPINT ? -1 : Number(len));
}

// getFirstCharInParagraph(charIndex)
// MS2-FUNCTIONAL the exe calls Value::SetNumber out of line (0x14000d250)
// @0x14290b1c0
void AvmTextField::GetFirstCharInParagraph(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn) || fn.NArgs < 1)
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    int idx = int(fn.Arg(0).ToNumber(fn.Env));
    if (idx < 0)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    UPInt pos = FUN_142612af0(ptf->GetDocument(), unsigned(idx));
    fn.Result->SetNumber(pos == SF_MAX_UPINT ? -1 : Number(pos));
}

// appendText(text): not for a field with a style sheet.
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line
// @0x14290b920
void AvmTextField::AppendText(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    ASString str = fn.Arg(0).ToString(fn.Env);
    FUN_14260df50(ptf->GetDocument(), str.ToCStr(), SF_MAX_UPINT);
    ptf->SetCompleteReformatReq();
    ptf->SetDirtyFlag();
}

// getLineMetrics(lineIndex): an object with the line's ascent, descent, width, height, leading and x in pixels.
// MS2-FUNCTIONAL register allocation and stack layout differ from the exe
// @0x14290aac0
void AvmTextField::GetLineMetrics(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (fn.NArgs < 1)
        return;
    int             line = int(fn.Arg(0).ToNumber(fn.Env));
    MS2_LineMetrics metrics;
    if (line < 0 || !FUN_142612d50(ptf->GetDocument(), unsigned(line), &metrics))
    {
        fn.Result->SetUndefined();
        return;
    }
    Ptr<Object> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("ascent"), Value(Render::TwipsToPixels(Double(metrics.Ascent))));
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("descent"), Value(Render::TwipsToPixels(Double(metrics.Descent))));
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("width"), Value(Render::TwipsToPixels(Double(metrics.Width))));
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("height"), Value(Render::TwipsToPixels(Double(metrics.Height))));
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("leading"), Value(Render::TwipsToPixels(Double(metrics.Leading))));
    pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("x"), Value(Render::TwipsToPixels(Double(metrics.FirstCharXOff))));
    fn.Result->SetAsObject(pobj);
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
    UPInt          len   = 0;
    const wchar_t* ptext = FUN_142612f00(ptf->GetDocument(), unsigned(line), &len);
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
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line
// @0x14290b9f0
void AvmTextField::AppendHtml(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    ASString                      str = fn.Arg(0).ToString(fn.Env);
    ArrayDH<MS2_HTMLImageTagInfo> imageInfoArray(Memory::GetHeapByAddress(ptf));
    FUN_14260de50(ptf->GetDocument(), str.ToCStr(), SF_MAX_UPINT, false, &imageInfoArray);
    ptf->SetCompleteReformatReq();
    if (imageInfoArray.GetSize() > 0)
        FUN_1425ba7d0(ptf, &imageInfoArray);
    ptf->SetDirtyFlag();
}

// copyToClipboard([richClipboard, startIndex, endIndex]): by default the selection, rich when the editor uses the
// rich clipboard.
// MS2-FUNCTIONAL register allocation differs from the exe
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
        richClipboard = fn.Arg(0).ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = fn.Arg(1).ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = fn.Arg(2).ToUInt32(fn.Env);
    FUN_142617440(pek, startPos, endPos, richClipboard);
}

// cutToClipboard([richClipboard, startIndex, endIndex])
// MS2-FUNCTIONAL register allocation differs from the exe
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
        richClipboard = fn.Arg(0).ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = fn.Arg(1).ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = fn.Arg(2).ToUInt32(fn.Env);
    FUN_1426175b0(pek, startPos, endPos, richClipboard);
    ptf->SetDirtyFlag();
}

// pasteFromClipboard([richClipboard, startIndex, endIndex]): replaces the range.
// MS2-FUNCTIONAL register allocation differs from the exe
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
        richClipboard = fn.Arg(0).ToBool(fn.Env);
    if (fn.NArgs >= 2)
        startPos = fn.Arg(1).ToUInt32(fn.Env);
    if (fn.NArgs >= 3)
        endPos = fn.Arg(2).ToUInt32(fn.Env);
    FUN_142619270(pek, startPos, endPos, richClipboard);
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
    FUN_142619b80(DocView_GetEditorKit(ptf->GetDocument()), newEnd, false);
    if (pparaFmt)
        FUN_142615410(ptf->GetDocument(), pparaFmt, startPos, newEnd);
    if (ptextFmt)
        FUN_142615640(ptf->GetDocument(), ptextFmt, startPos, newEnd);
    ptf->SetDirtyFlag();
}

// replaceText(beginIndex, endIndex, text): text takes the formats of the first replaced character.
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line
// @0x142909d80
void AvmTextField::ReplaceTextA(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 3)
        return;
    Number   start = fn.Arg(0).ToNumber(fn.Env);
    Number   end   = fn.Arg(1).ToNumber(fn.Env);
    ASString str   = fn.Arg(2).ToString(fn.Env);
    unsigned len   = str.GetLength();
    unsigned startPos = unsigned(start);
    unsigned endPos   = unsigned(end);
    if (start < 0 || end < 0 || startPos > endPos)
        return;
    UPInt       textLen  = FUN_142598a50(DocView_GetStyledText(ptf->GetDocument()));
    UPInt       newLen   = UPInt(len) - UPInt(endPos - startPos) + textLen;
    const void* ptextFmt = 0;
    const void* pparaFmt = 0;
    if (startPos < textLen)
        FUN_1425996b0(DocView_GetStyledText(ptf->GetDocument()), &ptextFmt, &pparaFmt, startPos);
    else
    {
        ptextFmt = StyledText_GetDefaultTextFormat(DocView_GetStyledText(ptf->GetDocument()));
        pparaFmt = StyledText_GetDefaultParagraphFormat(DocView_GetStyledText(ptf->GetDocument()));
    }
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
    if (pek && FUN_142617990(pek) > newLen)
        FUN_142619b80(DocView_GetEditorKit(ptf->GetDocument()), newLen, false);
    unsigned newEnd = startPos + len;
    if (pparaFmt)
        FUN_142615410(ptf->GetDocument(), pparaFmt, startPos, newEnd);
    if (ptextFmt)
    {
        FUN_142615640(ptf->GetDocument(), ptextFmt, startPos, newEnd);
        FUN_1424ae680(ptextFmt);
    }
    if (pparaFmt)
        FUN_1424ae650(pparaFmt);
    ptf->SetDirtyFlag();
}

// setTextFormat([beginIndex, [endIndex,]] textFormat): the whole text, one character or [beginIndex, endIndex).
// MS2-FUNCTIONAL the exe calls FnCall::Arg out of line
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
        Object* pobj = fn.Arg(0).ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
            FUN_142615640(ptf->GetDocument(), &pfmtObj->GetTextFormat(), 0, SF_MAX_UPINT);
            FUN_142615410(ptf->GetDocument(), &pfmtObj->GetParagraphFormat(), 0, SF_MAX_UPINT);
            ptf->SetDirtyFlag();
        }
    }
    else if (fn.NArgs == 2)
    {
        Object* pobj = fn.Arg(1).ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            Number pos = fn.Arg(0).ToNumber(fn.Env);
            if (pos >= 0)
            {
                TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
                unsigned          upos    = unsigned(pos);
                FUN_142615640(ptf->GetDocument(), &pfmtObj->GetTextFormat(), upos, upos + 1);
                FUN_142615410(ptf->GetDocument(), &pfmtObj->GetParagraphFormat(), upos, upos + 1);
                ptf->SetDirtyFlag();
            }
        }
    }
    else if (fn.NArgs >= 3)
    {
        Object* pobj = fn.Arg(2).ToObject(fn.Env);
        if (pobj && pobj->GetObjectType() == Object_TextFormat)
        {
            Number start = Alg::Max(Number(0), fn.Arg(0).ToNumber(fn.Env));
            Number end   = Alg::Max(Number(0), fn.Arg(1).ToNumber(fn.Env));
            if (end >= start)
            {
                TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(pobj);
                unsigned          ustart  = unsigned(start);
                unsigned          uend    = unsigned(end);
                FUN_142615640(ptf->GetDocument(), &pfmtObj->GetTextFormat(), ustart, uend);
                FUN_142615410(ptf->GetDocument(), &pfmtObj->GetParagraphFormat(), ustart, uend);
                ptf->SetDirtyFlag();
            }
        }
    }
}

// setNewTextFormat(textFormat): merged into the formats new text gets.
// MS2-FUNCTIONAL the exe calls FnCall::Arg and the TextFormat destructor out of line
// @0x142909590
void AvmTextField::SetNewTextFormat(const FnCall& fn)
{
    if (!IsTextFieldTarget(fn))
        return;
    TextField* ptf = GetTextFieldTarget(fn);
    if (ptf->HasStyleSheet() || fn.NArgs < 1)
        return;
    Object* pobj = fn.Arg(0).ToObject(fn.Env);
    if (pobj && pobj->GetObjectType() == Object_TextFormat)
    {
        TextFormatObject* pfmtObj     = static_cast<TextFormatObject*>(pobj);
        void*             pstyledText = DocView_GetStyledText(ptf->GetDocument());
        const Render::Text::TextFormat* ptextFmt =
            (const Render::Text::TextFormat*)StyledText_GetDefaultTextFormat(pstyledText);
        const Render::Text::ParagraphFormat* pparaFmt =
            (const Render::Text::ParagraphFormat*)StyledText_GetDefaultParagraphFormat(pstyledText);
        FUN_14259c250(DocView_GetStyledText(ptf->GetDocument()), ptextFmt->Merge(pfmtObj->GetTextFormat()));
        ptf->SetCompleteReformatReq();
        FUN_14259c170(DocView_GetStyledText(ptf->GetDocument()), pparaFmt->Merge(pfmtObj->GetParagraphFormat()));
        ptf->SetCompleteReformatReq();
    }
}

// getTextFormat([beginIndex, [endIndex]]): a TextFormat with what the characters of the range have in common.
// MS2-FUNCTIONAL the exe calls FnCall::Arg and the format destructors out of line
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
    if (fn.NArgs >= 1)
    {
        // Only the character at beginIndex without an endIndex.
        Number end = (fn.NArgs >= 2) ? fn.Arg(1).ToNumber(fn.Env) : fn.Arg(0).ToNumber(fn.Env) + 1;
        end        = Alg::Max(Number(0), end);
        if (end >= 0)
            endIndex = unsigned(end);
    }
    if (beginIndex > endIndex)
    {
        fn.Result->SetUndefined();
        return;
    }
    Render::Text::TextFormat      textFmt(fn.Env->GetHeap());
    Render::Text::ParagraphFormat paraFmt;
    FUN_1425990d0(DocView_GetStyledText(ptf->GetDocument()), &textFmt, &paraFmt, beginIndex, endIndex);
    Ptr<TextFormatObject> pfmtObj = *SF_HEAP_NEW(fn.Env->GetHeap()) TextFormatObject(fn.Env);
    pfmtObj->SetTextFormat(fn.Env->GetSC(), textFmt);
    pfmtObj->SetParagraphFormat(fn.Env->GetSC(), paraFmt);
    fn.Result->SetAsObject(pfmtObj);
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
