// Recovered Scaleform GFx 4.1.18: log interface (message id = channel | type), default log to OutputDebugString.
#ifndef MS2_SF_KERNEL_LOG_H
#define MS2_SF_KERNEL_LOG_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include <stdarg.h>

namespace Scaleform {

enum LogMessageType
{
    LogMessage_Text    = 0x00000,
    LogMessage_Warning = 0x20000,
    LogMessage_Error   = 0x30000,
    LogMessage_Assert  = 0x40000,
    LogMessage_Report  = 0x50000,
    LogMessage_Mask    = 0xF0000
};

enum LogChannel
{
    LogChannel_General     = 0x1000,
    LogChannel_Debug       = 0x2000,
    LogChannel_Render      = 0x3000,
    LogChannel_Script      = 0x4000,
    LogChannel_Parse       = 0x5000,
    LogChannel_Action      = 0x6000,
    LogChannel_Memory      = 0x7000,
    LogChannel_Performance = 0x8000,
    LogChannel_Mask        = 0xF000
};

// Passed by value (it has a copy constructor, so the ABI passes a pointer to a temporary).
class LogMessageId
{
    int Id;
public:
    LogMessageId(int id = 0) : Id(id) { }
    LogMessageId(const LogMessageId& o) : Id(o.Id) { }
    LogMessageId& operator=(int id) { Id = id; return *this; }
    LogMessageId& operator=(LogMessageId& o) { Id = o.Id; return *this; }
    operator int() const { return Id; }
    LogMessageType GetMessageType() const { return (LogMessageType)(Id & LogMessage_Mask); }
    LogChannel     GetChannel() const     { return (LogChannel)(Id & LogChannel_Mask); }
};

enum LogConstants
{
    Log_Message      = LogChannel_General | LogMessage_Text,
    Log_Warning      = LogChannel_General | LogMessage_Warning,
    Log_Error        = LogChannel_General | LogMessage_Error,
    Log_DebugMessage = LogChannel_Debug | LogMessage_Text,
    Log_DebugWarning = LogChannel_Debug | LogMessage_Warning,
    Log_DebugError   = LogChannel_Debug | LogMessage_Error,
    Log_DebugAssert  = LogChannel_Debug | LogMessage_Assert
};

class Log : public RefCountBase<Log, Stat_Default_Mem>
{
    friend class System;
public:
    Log() { }
    virtual ~Log();
    virtual void LogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList);
    void LogMessageById(LogMessageId messageId, const char* fmt, ...);

    enum { MaxLogBufferMessageSize = 2048 };
    static void FormatLog(char* buffer, unsigned bufferSize, LogMessageId messageId, const char* fmt, va_list argList);
    static void DefaultLogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList);

    void LogMessage(const char* fmt, ...)
    {
        va_list args; va_start(args, fmt);
        LogMessageVarg(Log_Message, fmt, args);
        va_end(args);
    }
    void LogError(const char* fmt, ...)
    {
        va_list args; va_start(args, fmt);
        LogMessageVarg(Log_Error, fmt, args);
        va_end(args);
    }
    void LogWarning(const char* fmt, ...)
    {
        va_list args; va_start(args, fmt);
        LogMessageVarg(Log_Warning, fmt, args);
        va_end(args);
    }

    static void SetGlobalLog(Log* log);
    static Log* GetGlobalLog();
    static Log* GetDefaultLog();
};

}  // namespace Scaleform

#endif
