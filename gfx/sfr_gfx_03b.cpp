// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Log (the log state of the
// state bags and the parse-log text of render values).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_Log.
// MS2-UNIT: sfr_gfx_03b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425b3380-0x1425b3a90 .text$mn

#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/render/render_color.h"
#include "../include/render/render_cxform.h"
#include "../include/render/render_matrix2x4.h"
#include "../include/render/render_twips.h"
#include "../include/kernel/sf_msgformat.h"

namespace Scaleform { namespace GFx {

// @0x1425b3490
LogState::~LogState()
{
}

// @0x1425b3940
void LogState::LogMessageByType(LogMessageId messageId, const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogMessageVarg(messageId, pfmt, argList);
    va_end(argList);
}

// @0x1425b3970
void LogState::LogMessageVarg(LogMessageId messageId, const char* pfmt, va_list argList)
{
    Log* plog = GetLog();
    if (plog)
        plog->LogMessageVarg(messageId, pfmt, argList);
}

// @0x1425b39d0
void StateBag::SetLog(Log* plog)
{
    Ptr<LogState> pstate = *SF_NEW LogState(plog);
    SetState(State::State_Log, pstate);
}

// @0x1425b38b0
Ptr<Log> StateBag::GetLog() const
{
    Ptr<LogState> pstate = *(LogState*)GetStateAddRef(State::State_Log);
    return pstate->GetLog();
}

// @0x1425b3910
Ptr<LogState> StateBag::GetLogState() const
{
    return *(LogState*)GetStateAddRef(State::State_Log);
}

// @0x1425b35c0
char* Format(char* pbuffer, UPInt bufferSize, const Render::Matrix2x4<float>& matrix)
{
    Format(StringDataPtr(pbuffer, bufferSize),
           "| {0:4.4} {1:4.4} {2:4.4} |\n"
           "| {3:4.4} {4:4.4} {5:4.4} |\n",
           matrix.M[0][0], matrix.M[0][1], Render::TwipsToPixels(matrix.M[0][3]), matrix.M[1][0], matrix.M[1][1],
           Render::TwipsToPixels(matrix.M[1][3]));
    return pbuffer;
}

// @0x1425b36d0
char* Format(char* pbuffer, UPInt bufferSize, const Render::Color& color)
{
    Format(StringDataPtr(pbuffer, bufferSize), "RGBA: {0} {1} {2} {3}\n", (int)color.GetRed(), (int)color.GetGreen(),
           (int)color.GetBlue(), (int)color.GetAlpha());
    return pbuffer;
}

// @0x1425b37b0
char* Format(char* pbuffer, UPInt bufferSize, const Render::Cxform& cxform)
{
    Format(StringDataPtr(pbuffer, bufferSize),
           "    *         +\n"
           "| {0:4.4} {1:4.4}|\n"
           "| {2:4.4} {3:4.4}|\n"
           "| {4:4.4} {5:4.4}|\n"
           "| {6:4.4} {7:4.4}|\n",
           cxform.M[0][0], cxform.M[1][0], cxform.M[0][1], cxform.M[1][1], cxform.M[0][2], cxform.M[1][2],
           cxform.M[0][3], cxform.M[1][3]);
    return pbuffer;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7?$LogBase@VLogState@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431897c8
// MS2-PIN: ??_7LogState@GFx@Scaleform@@6BState@12@@ 0x1431897d8
// MS2-PIN: ??_7LogState@GFx@Scaleform@@6B?$LogBase@VLogState@GFx@Scaleform@@@12@@ 0x1431897e8
