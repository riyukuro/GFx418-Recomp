// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): GFxLogger, the game's Scaleform::Log that forwards GFx log
// messages to the game log (CLogString) as "[Gfx]{0} {1}" lines, plus this TU's log wrapper instantiation, the Log /
// RefCount base COMDATs its constructor and deleting destructors pull in and the unreferenced CRT memcpy_s copy.
// MS2-UNIT: sfr_gfx_10
// MS2-RANGE: 0x140a5bb10-0x140a5c650 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL ??_GRefCountImplCore@Scaleform@@UEAAPEAXI@Z: the exe's copy is the vector deleting destructor (??_E, emitted because some TU deletes an array of them); with flag bit 2 clear it runs the same dtor and sized delete as this ??_G
// MS2-PIN: ??_GRefCountImplCore@Scaleform@@UEAAPEAXI@Z 0x140a5c250
// MS2-PIN: ??_7GFxLogger@@6B@ 0x142dc9da0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gfxlogger.cpp"
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include "ms2/commonfiles/logstring.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/ms2recover.h"

CStringW FUN_14016a730(const char* sz, int nCodePage);    // a multi-byte text as a wide string (0 = the locale's code page)

using namespace Scaleform;

// This unit is built without optimisation, so its copies of the Log / RefCount base classes differ from the shared
// optimised COMDATs of the same names elsewhere in the exe. Stand-in chain with its own mangled names, same layout.
class Unk_RefCountImpl : public RefCountImplCore
{
};

template <class Base, int Stat> class Unk_RefCountBaseStatImpl : public Base
{
public:
    Unk_RefCountBaseStatImpl() {}
    SF_MEMORY_REDEFINE_NEW(Unk_RefCountBaseStatImpl, Stat)
};

template <class C, int Stat> class Unk_RefCountBase : public Unk_RefCountBaseStatImpl<Unk_RefCountImpl, Stat>
{
public:
    Unk_RefCountBase() {}
};

class Unk_GfxLogBase : public Unk_RefCountBase<Unk_GfxLogBase, 2>
{
public:
    Unk_GfxLogBase() {}
    virtual ~Unk_GfxLogBase() {}
    virtual void LogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList);
};

// The game's GFx log: LogMessageVarg (vftable slot 1) formats the message and writes it to the game log.
class GFxLogger : public Unk_GfxLogBase
{
public:
    GFxLogger();
    virtual ~GFxLogger();
    virtual void LogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList);
};

// The global interface object (the heap of the CRI/GFx allocator) and its slot 12.
extern "C" void* DAT_143b15f60;

// MS2-FUNCTIONAL: the log wrapper (FMT_VARIADIC over CLogString::FUN_1406530d0) for two CStringW arguments.
// @0x140a5bdd0
template <class A, class B> inline void Unk_GfxLog(CLogString* log, int level, int line, const wchar_t* format,
                                                    const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, line, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}

// @0x140a5bb10
GFxLogger::GFxLogger()
{
}

// @0x140a5bb50
GFxLogger::~GFxLogger()
{
}

// MS2-FUNCTIONAL: sets the process-wide GFx log to the given logger.
// @0x140a5bb80
void FUN_140a5bb80(Log* pLog)
{
    Log::SetGlobalLog(pLog);
}

// MS2-FUNCTIONAL: clears the process-wide GFx log.
// @0x140a5bba0
void FUN_140a5bba0()
{
    Log::SetGlobalLog(0);
}

// @0x140a5bbc0
void GFxLogger::LogMessageVarg(LogMessageId messageId, const char* fmt, va_list argList)
{
    CStringA strText;
    strText.FormatV(fmt, argList);
    strText.TrimRight('\n');
    if (CLogString::GetInstance() != 0)
    {
        int nLevel = 0;
        int nType = messageId.GetMessageType();
        if (nType == 0)
            nLevel = 0xb;
        else if (nType == LogMessage_Warning)
            nLevel = 2;
        else if (nType == LogMessage_Error)
            nLevel = 1;
        else if (nType == LogMessage_Assert)
            nLevel = 0xc;
        CStringW strChannel(L"[Unknown]");
        int nChannel = messageId.GetChannel();
        if (nChannel == LogChannel_General)
            strChannel = L"";
        else if (nChannel == LogChannel_Debug)
            strChannel = L"[Debug]";
        else if (nChannel == LogChannel_Render)
            strChannel = L"[Render]";
        else if (nChannel == LogChannel_Script)
            strChannel = L"[Script]";
        else if (nChannel == LogChannel_Parse)
            strChannel = L"[Parse]";
        CStringW strMessage = FUN_14016a730((const char*)strText, 0);
        Unk_GfxLog(CLogString::GetInstance(), nLevel, 0x1a, L"[Gfx]{0} {1}", strChannel, strMessage);
    }
}

// MS2-FUNCTIONAL: forwards a block to the global interface object's slot 12 (its release/free entry).
// @0x140a5c4c0
void FUN_140a5c4c0(void* p)
{
    void** pVtbl = *(void***)DAT_143b15f60;
    ((void (*)(void*, void*))pVtbl[12])(DAT_143b15f60, p);
}

// @0x140a5c220
void FUN_140a5c220(void* p)
{
    FUN_140a5c4c0(p);
}

// ---- the unreferenced CRT copy ----

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x140a5c530
static __inline errno_t ms2_gfxlog_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnGfxMemcpyS)(void*, size_t, const void*, size_t) = &ms2_gfxlog_memcpy_s;
#pragma intrinsic(memcpy, memset)
// MS2-PIN: ??_7Unk_RefCountImpl@@6B@ 0x142dc9d58
// MS2-PIN: ??_7?$Unk_RefCountBaseStatImpl@VUnk_RefCountImpl@@$01@@6B@ 0x142dc9d68
// MS2-PIN: ??_7?$Unk_RefCountBase@VUnk_GfxLogBase@@$01@@6B@ 0x142dc9d78
// MS2-PIN: ??_7Unk_GfxLogBase@@6B@ 0x142dc9d88
// MS2-PIN: ??1?$Unk_RefCountBase@VUnk_GfxLogBase@@$01@@UEAA@XZ 0x140a5c1c0
// MS2-PIN: ??_G?$Unk_RefCountBase@VUnk_GfxLogBase@@$01@@UEAAPEAXI@Z 0x140a5c300
// MS2-PIN: ??_GUnk_GfxLogBase@@UEAAPEAXI@Z 0x140a5c420
