// Recovered Scaleform 4.1.18 GFx: printf-style logging mixed into GFx classes, and the log state.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The Log class itself comes from the recovered kernel tree (src/ms2/scaleform/kernel/sf_log.h).
#ifndef MS2_SF_GFX_LOG_H
#define MS2_SF_GFX_LOG_H

#include "gfx_state.h"
#include "../../kernel/sf_log.h"

namespace Scaleform { namespace GFx {

// Mixin giving Derived the LogError/... helpers. Derived supplies GetLog() and IsLogNotNull()
// (the latter is a compile-time "GetLog never returns null"). Base vftable 0x143188dd0.
template<class Derived>
class LogBase
{
public:
    virtual ~LogBase() {}

    virtual bool IsVerboseActionErrors() const { return true; }

    void LogError(const char* pfmt, ...) const;
    // Parse channel message (out of line per Derived in the exe, e.g. LogBase<Stream> 0x14258e410).
    void LogParse(const char* pfmt, ...) const;
    // Script error channel (out of line per Derived, e.g. LogBase<LogState> 0x14246a960).
    void LogScriptError(const char* pfmt, ...) const;

protected:
    bool IsLogNotNull() const { return 0; }
};

template<class Derived>
void LogBase<Derived>::LogError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    Derived* p    = (Derived*)this;
    Log*     plog = p->GetLog();
    if (p->IsLogNotNull() || plog)
        plog->LogMessageVarg(Log_Error, pfmt, argList);
    va_end(argList);
}

// The Log of a loader or movie; falls back to the global log.
class LogState : public State, public LogBase<LogState>
{
protected:
    Ptr<Log> pLog; // +0x20

public:
    LogState(Log* plog) : State(State_Log), pLog(plog) {}
    virtual ~LogState(); // exe 0x1425b3490

    // Sends the message to GetLog() (exe 0x1425b3970).
    virtual void LogMessageVarg(LogMessageId messageId, const char* pfmt, va_list argList);

    Log* GetLog() const       { return pLog ? pLog.GetPtr() : Log::GetGlobalLog(); }
    bool IsLogNotNull() const { return 1; }

    // exe 0x1425b3940
    void LogMessageByType(LogMessageId messageId, const char* pfmt, ...);
};

}} // namespace Scaleform::GFx

namespace Scaleform {
namespace Render { template<class T> class Matrix2x4; class Cxform; class Color; }
namespace GFx {

// Text of render values for the parse log, written into pbuffer (GFx_Log; exe: Matrix 0x1425b35c0,
// Color 0x1425b36d0, Cxform 0x1425b37b0). Return pbuffer.
char* Format(char* pbuffer, UPInt bufferSize, const Render::Matrix2x4<float>& matrix);
char* Format(char* pbuffer, UPInt bufferSize, const Render::Color& color);
char* Format(char* pbuffer, UPInt bufferSize, const Render::Cxform& cxform);

}} // namespace Scaleform::GFx

#endif
