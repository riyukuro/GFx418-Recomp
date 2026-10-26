// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Win32 IME manager leftovers
// next to the AS2 support: the IME list XML handlers, OS/locale queries, HandleIMEEvent, Init, and the
// small helpers (MovieImpl::GetCachedLog, Log::LogWarning, the CuePoint array Reserve).
// The manager is the same opaque object sfr_ime_01 reads by offset; this unit follows that convention.
// MS2-UNIT: sfr_as2_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c9140-0x1423ca140 .text$mn
// MS2-RANGE: 0x1423ca160-0x1423ca1c0 .text$mn
// MS2-RANGE: 0x1423ca2b0-0x1423ca350 .text$mn
// MS2-RANGE: 0x1423c9000-0x1423c9020 .text$mn
// MS2-PIN: ?LogWarning@Log@Scaleform@@QEAAXPEBDZZ 0x1423ca0c0

#include <windows.h>
#include <imm.h>
#pragma comment(lib, "imm32.lib")   // ImmIsUIMessageW / ImmGetContext / ImmGetOpenStatus / ImmReleaseContext
#include <objbase.h>
#include <stdlib.h>
#include <string.h>
#include <cstdarg>

#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_string.h"
#include "../include/gfx/gfx_player.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_imemanager.h"
#include "../kernel/sf_log.h"
#define XML_STATIC  // the exe links expat statically (libgfxexpat)
#include "../third_party/src/expat-2.0.1/lib/expat.h"

// The IME name table (45 entries of { const char* name; int langId; }) the XML "Lang" text is looked up in.
extern "C" const unsigned char DAT_143a2a3e0[];
extern "C" const int DAT_143a2a6b0;
// The Vista language bar's vtable (the 0x1a0-byte list object constructed through FUN_1423cabb0).
extern "C" void* DAT_143138530[];

void FUN_14257dcb0(void*); // RefCountImpl::Release

// Bodies in sfr_ime_01 (the IME manager unit).
namespace Scaleform { namespace GFx { namespace IME {
unsigned long long* FUN_1423cabb0(unsigned long long*, unsigned long long);
unsigned long long* FUN_1423d54d0(unsigned long long* self);
void* FUN_1423cdbb0(unsigned long long* words, void* owner, void* userData);
void* FUN_1423d18b0(void* raw, void* owner, void* userData);
void FUN_1423cc3d0(void* raw);
void FUN_1423cad60(void* object);
void FUN_1423ca6b0(void* raw, const char* name);
}}}

namespace {

using namespace Scaleform;

inline unsigned char* B(void* p) { return static_cast<unsigned char*>(p); }
template <class T> inline T& At(void* p, size_t off) { return *reinterpret_cast<T*>(B(p) + off); }

template <class R, class... A>
inline R VCall(void* obj, size_t off, A... a)
{
    typedef R (*Fn)(void*, A...);
    return (*reinterpret_cast<Fn*>(*static_cast<unsigned char**>(obj) + off))(obj, a...);
}

} // namespace

namespace Scaleform { namespace GFx { namespace IME {

// Named (not in the anonymous namespace) so HandleIMEEvent keeps external linkage: the vtable slot references it.
// The window message HandleIMEEvent receives (GFx IMEWin32Event: type, message, wParam, lParam, hwnd, flag).
struct IMEEventView
{
    unsigned char pad0[8];
    int           Type;     // +0x08 (1 = pre-process)
    UINT          Message;  // +0x0c
    UPInt         WParam;   // +0x10
    UPInt         LParam;   // +0x18
    HWND          hWnd;     // +0x20
    int           Flag;     // +0x28
};

// MS2-FUNCTIONAL: XML character-data handler; register allocation and the inlined name-table strcmp differ.
// The text of <imeName>, <displayName> or <Lang> fills the last record (0x30 bytes: +0x10 name, +0x18 display
// name, +0x20 language id looked up in the IME name table).
// @0x1423c9140
void FUN_1423c9140(void* self, const char* text, int len)
{
    if (!At<unsigned char>(self, 0xa9))
        return;
    unsigned char* record = 0;
    int count = At<int>(self, 0xc0);
    if (count > 0)
        record = At<unsigned char*>(self, 0xb8) + (UPInt)(count - 1) * 0x30;

    int mode = At<int>(self, 0xb0);
    if (mode == 0)
        *reinterpret_cast<String*>(record + 0x10) = String(text, (UPInt)len);
    else if (mode == 1)
        *reinterpret_cast<String*>(record + 0x18) = String(text, (UPInt)len);
    else if (mode == 2)
    {
        String value(text, (UPInt)len);
        SPInt entries = DAT_143a2a6b0;
        for (SPInt i = 0; i < entries; ++i)
        {
            const unsigned char* entry = DAT_143a2a3e0 + i * 16;
            if (strcmp(value.ToCStr(), *reinterpret_cast<const char* const*>(entry)) == 0)
            {
                *reinterpret_cast<int*>(record + 0x20) = *reinterpret_cast<const int*>(entry + 8);
                break;
            }
        }
    }
}

// MS2-FUNCTIONAL: XML end-element handler; the exe inlines the 8- and 4-byte compares.
// @0x1423c93f0
void FUN_1423c93f0(void* self, const char* name)
{
    if (strcmp(name, "Language") == 0)
        At<unsigned char>(self, 0xa9) = 0;
    if (memcmp(name, "imeName", 8) == 0)
    {
        At<unsigned char>(self, 0xaa) = 0;
        At<int>(self, 0xb0) = 3;
    }
    if (strcmp(name, "displayName") == 0)
    {
        At<unsigned char>(self, 0xab) = 0;
        At<int>(self, 0xb0) = 3;
    }
    if (memcmp(name, "Tag", 4) == 0)
    {
        At<unsigned char>(self, 0xac) = 0;
        At<int>(self, 0xb0) = 3;
    }
}

// The manager vtable slots that pass the call on to the language bar at +0x70 (the exe tail-jumps).
// ClearCandidateListPath (slot 5).
// @0x1423c92f0
void FUN_1423c92f0(void* self)
{
    void* bar = At<void*>(self, 0x70);
    if (bar)
        VCall<void>(bar, 0x20);
}

// GetConversionMode (slot 7): "UNKNOWN" without a language bar.
// @0x1423c9570
const char* FUN_1423c9570(void* self)
{
    void* bar = At<void*>(self, 0x70);
    if (bar)
        return VCall<const char*>(bar, 0x108);
    return "UNKNOWN";
}

// GetEnabled (slot 9).
// @0x1423c9590
bool FUN_1423c9590(void* self)
{
    void* bar = At<void*>(self, 0x70);
    if (bar)
        return VCall<bool>(bar, 0xf0);
    return false;
}

// MS2-FUNCTIONAL: GetIMEName: the language bar's name, "UNKNOWN" without one.
// @0x1423c95b0
String* FUN_1423c95b0(void* self, String* out)
{
    void* bar = At<void*>(self, 0x70);
    if (bar)
    {
        VCall<void>(bar, 0xe0, out);
        return out;
    }
    new (out) String("UNKNOWN");
    return out;
}

// MS2-FUNCTIONAL: an empty string.
// @0x1423c95f0
String* FUN_1423c95f0(void*, String* out)
{
    new (out) String();
    return out;
}

// MS2-FUNCTIONAL: the system default locale's abbreviated language name (LOCALE_SABBREVLANGNAME).
// @0x1423c9610
String* FUN_1423c9610(void*, String* out)
{
    char name[16];
    if (GetLocaleInfoA(LOCALE_SYSTEM_DEFAULT, LOCALE_SABBREVLANGNAME, name, 4))
    {
        new (out) String(name);
        return out;
    }
    GetLastError();
    new (out) String((const char*)0);
    return out;
}

// MS2-FUNCTIONAL: the OS family name for the version GetOSVersion stored at +0xbc.
// @0x1423c9670
String* FUN_1423c9670(void* self, String* out)
{
    int os = At<int>(self, 0xbc);
    if (os == 0)
        new (out) String("XP");
    else if (os == 1)
        new (out) String("Vista");
    else
        new (out) String("Unknown");
    return out;
}

// MS2-FUNCTIONAL: classifies the OS: 0 XP/2003, 1 Vista+, 2 Windows 2000, 3 Win32s/9x.
// @0x1423c96d0
void FUN_1423c96d0(void*, int* os)
{
    OSVERSIONINFOW info;
    info.dwOSVersionInfoSize = sizeof(info);
#pragma warning(suppress: 4996)
    GetVersionExW(&info);
    if (info.dwPlatformId == VER_PLATFORM_WIN32s)
    {
        *os = 3;
        return;
    }
    if (info.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    {
        if (info.dwMinorVersion == 0 || info.dwMinorVersion == 10 || info.dwMinorVersion == 90)
            *os = 3;
        return;
    }
    if (info.dwPlatformId != VER_PLATFORM_WIN32_NT)
        return;
    if (info.dwMajorVersion == 5)
    {
        if (info.dwMinorVersion == 0)
            *os = 2;
        else if (info.dwMinorVersion - 1 <= 1)
            *os = 0;
    }
    else if (info.dwMajorVersion == 6)
        *os = 1;
}

}}} // namespace Scaleform::GFx::IME

namespace Scaleform { namespace GFx {

// MS2-FUNCTIONAL: MovieImpl::GetCachedLog; the exe reuses the StateBag::GetLog temporary.
// @0x1423c94e0
Log* FUN_1423c94e0(MovieImpl* movie)
{
    if (!(movie->Flags & MovieImpl::Flag_CachedLogFlag))
        movie->pCachedLog = movie->GetLog();
    return movie->pCachedLog;
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace IME {

// MS2-FUNCTIONAL: HandleIMEEvent (0 = not handled, 1 = handled, 2 = handled and eaten); the exe tail-calls
// the composition-start slot.
// @0x1423c9780
unsigned FUN_1423c9780(void* self, MovieImpl* movie, const IMEEventView* ev)
{
    if (!At<unsigned char>(self, 0xb9))
    {
        if (movie)
            FUN_1423c94e0(movie)->LogWarning("Failure in obtaining list of installed IMEs! IME is disabled");
        return 0;
    }
    void* bar = At<void*>(self, 0x70);
    if (!bar)
        return 1;
    if (!VCall<bool>(self, 0xf0))
        return 0;

    void* list = At<void*>(self, 0x78);
    if (list)
    {
        unsigned lang = VCall<unsigned>(list, 0x10, 0);
        At<unsigned>(self, 0x84) = lang;
        VCall<void>(At<void*>(self, 0x70), 0x88, lang);
    }

    UINT msg = ev->Message;
    if (msg == WM_IME_STARTCOMPOSITION)
        return VCall<unsigned>(At<void*>(self, 0x70), 0x58, ev->WParam, ev->LParam, ev->Flag != 0);
    if (msg == WM_IME_SETCONTEXT)
        return 2;
    if (msg == WM_INPUTLANGCHANGE)
    {
        VCall<void>(At<void*>(self, 0x78), 0x38, (unsigned)ev->LParam);
        if (At<void*>(self, 0x70))
            VCall<void>(At<void*>(self, 0x70), 0x78);
    }
    if (ev->Message == WM_IME_NOTIFY && ev->WParam == IMN_SETCONVERSIONMODE)
        VCall<void>(At<void*>(self, 0x78), 0x50, -1);

    if (!VCall<bool>(At<void*>(self, 0x70), 0x30, movie))
        return 0;

    if (ev->Type == 1)
    {
        if (!VCall<bool>(At<void*>(self, 0x18), 0x70) || At<unsigned>(self, 0x84) == 0x1000000)
            return 0;
        UINT m = ev->Message;
        BOOL ui = ImmIsUIMessageW(0, m, (WPARAM)ev->WParam, (LPARAM)ev->LParam);
        if ((m - WM_KEYDOWN < 2 || ui || m == WM_LBUTTONUP) && At<void*>(self, 0x70))
            VCall<void>(At<void*>(self, 0x70), 0xa8, ev);
        return 2;
    }
    if (At<unsigned>(self, 0x84) == 0x1000000)
        return 0;

    msg = ev->Message;
    if (msg == WM_IME_ENDCOMPOSITION)
    {
        VCall<void>(At<void*>(self, 0x70), 0x60, ev->WParam, ev->LParam, ev->Flag != 0);
        return 1;
    }
    if (msg == WM_IME_COMPOSITION)
    {
        VCall<void>(At<void*>(self, 0x70), 0x50, ev->WParam, ev->LParam, ev->Flag);
        return 2;
    }
    if (msg != WM_IME_NOTIFY)
        return msg == WM_IME_REQUEST ? 2 : 0;

    UPInt cmd = ev->WParam;
    if (cmd - IMN_CHANGECANDIDATE > 2 && cmd != 0xe)
    {
        if (cmd == IMN_SETCONVERSIONMODE)
            VCall<void>(At<void*>(self, 0x78), 0x50, -1);
        else if (cmd == IMN_SETOPENSTATUS)
        {
            HIMC context = ImmGetContext(ev->hWnd);
            BOOL open = ImmGetOpenStatus(context);
            void* b = At<void*>(self, 0x70);
            At<unsigned char>(self, 0xb8) = open ? 1 : 0;
            VCall<void>(b, 0xd0, open ? 1 : 0);
            if (strcmp(At<String>(self, 0xb0).ToCStr(), "Japanese") == 0)
                VCall<void>(At<void*>(self, 0x78), 0x50, -1);
            ImmReleaseContext(ev->hWnd, context);
        }
        else if (cmd == IMN_OPENSTATUSWINDOW)
        {
            VCall<void>(At<void*>(self, 0x70), 0xd8, 0);
            VCall<void>(At<void*>(self, 0x70), 0xd8, 1);
            return 0;
        }
        VCall<void>(At<void*>(self, 0x70), 0x70, (unsigned)WM_IME_NOTIFY, ev->WParam, ev->LParam);
        return 1;
    }
    if (!At<unsigned char>(self, 0x80))
    {
        String error;
        if (static_cast<IMEManagerBase*>(self)->GetCandidateListErrorMsg(&error))
            FUN_1423c94e0(movie)->LogWarning(error.ToCStr());
        At<unsigned char>(self, 0x80) = 1;
    }
    if (!VCall<void*>(At<void*>(self, 0x70), 0x68, (unsigned)WM_IME_NOTIFY, ev->WParam, ev->LParam, 1))
        return 0;
    return 2;
}

// MS2-FUNCTIONAL: Init: picks the XP or Vista candidate/language-bar objects, loads the IME list XML (relative
// paths under %GFXSDK%\Bin\Data\), falls back to the built-in list, and reports whether the list is usable.
// @0x1423c9ba0
bool FUN_1423c9ba0(void* self, Log* log, void* opener, const char* xmlPath, bool flag)
{
    unsigned long long* w = static_cast<unsigned long long*>(self);
    w[0xc] = reinterpret_cast<unsigned long long>(log);
    VCall<void>(self, 0x128, B(self) + 0xbc);
    At<unsigned char>(self, 0x58) = flag;
    w[0xf] = 0;
    w[0xe] = 0;
    CoInitialize(0);

    int os = At<int>(self, 0xbc);
    if (os == 1)
    {
        void* mem = Memory::pGlobalHeap->Alloc(0xe8);
        w[0xe] = reinterpret_cast<unsigned long long>(
            mem ? FUN_1423cdbb0(static_cast<unsigned long long*>(mem), self, (void*)w[0xd]) : 0);
        mem = Memory::pGlobalHeap->Alloc(0x1d8);
        w[0xf] = reinterpret_cast<unsigned long long>(
            mem ? FUN_1423d54d0(static_cast<unsigned long long*>(mem)) : 0);
    }
    else if (os == 0)
    {
        void* mem = Memory::pGlobalHeap->Alloc(0x5c0);
        w[0xe] = reinterpret_cast<unsigned long long>(mem ? FUN_1423d18b0(mem, self, (void*)w[0xd]) : 0);
        unsigned long long* bar = static_cast<unsigned long long*>(Memory::pGlobalHeap->Alloc(0x1a0));
        if (bar)
        {
            FUN_1423cabb0(bar, reinterpret_cast<unsigned long long>(self));
            bar[0] = reinterpret_cast<unsigned long long>(DAT_143138530);
        }
        w[0xf] = reinterpret_cast<unsigned long long>(bar);
    }

    if (!opener || !xmlPath)
    {
        if (w[0xc])
            reinterpret_cast<Log*>(w[0xc])->LogWarning(
                "IME Warning: No fileopener and/or xml file specified. Defaulting to internal list\n");
        if (w[0xf])
            FUN_1423cc3d0((void*)w[0xf]);
    }
    else
    {
        XML_Parser parser = XML_ParserCreate(0);
        void* file;
        if (URLBuilder::IsPathAbsolute(xmlPath))
            file = VCall<void*>(opener, 8, xmlPath, 0x21, 0x1b6);
        else
        {
            char sdk[0x104];
            size_t len;
            getenv_s(&len, sdk, 0x104, "GFXSDK");
            String path = String(sdk) + "\\Bin\\Data\\" + xmlPath;
            file = VCall<void*>(opener, 8, path.ToCStr(), 0x21, 0x1b6);
        }
        if (file && VCall<bool>(file, 0x10))
        {
            int size = VCall<int>(file, 0x30);
            if (size)
            {
                char* data = static_cast<char*>(Memory::pGlobalHeap->Alloc((UPInt)(SPInt)size));
                VCall<int>(file, 0x50, data, size);
                XML_SetStartElementHandler(parser, reinterpret_cast<XML_StartElementHandler>(&FUN_1423ca6b0));
                XML_SetEndElementHandler(parser, reinterpret_cast<XML_EndElementHandler>(&FUN_1423c93f0));
                XML_SetCharacterDataHandler(parser, reinterpret_cast<XML_CharacterDataHandler>(&FUN_1423c9140));
                XML_SetUserData(parser, (void*)w[0xf]);
                if (w[0xf])
                    At<unsigned char>((void*)w[0xf], 0xa9) = 0;
                if (XML_Parse(parser, data, size, 1) != 1)
                {
                    XML_Error code = XML_GetErrorCode(parser);
                    int col = (int)XML_GetCurrentColumnNumber(parser) + 1;
                    int line = (int)XML_GetCurrentLineNumber(parser);
                    if (w[0xc])
                        reinterpret_cast<Log*>(w[0xc])->LogWarning(
                            "IME Error: Error reading xml file: %s \t\t\t\t\t\t\t\t\t\t @ line:%d col:%d - %.64s\n",
                            xmlPath, line, col, XML_ErrorString(code));
                }
                Memory::pGlobalHeap->Free(data);
            }
            VCall<void>(file, 0x98);
        }
        // (the exe falls through to this warning and the internal list after reading the file as well)
        if (w[0xc])
            reinterpret_cast<Log*>(w[0xc])->LogWarning(
                "IME Warning:error in opening xml file, check path. Defaulting to internal list\n");
        if (w[0xf])
            FUN_1423cc3d0((void*)w[0xf]);
        XML_ParserFree(parser);
        if (file)
            FUN_14257dcb0(file);
    }

    void* bar = 0;
    if (w[0xf])
    {
        FUN_1423cad60((void*)w[0xf]);
        bar = (void*)w[0xf];
    }
    bool ok = false;
    At<unsigned char>(self, 0xb9) = 0;
    if (bar)
    {
        ok = !VCall<bool>(bar, 8);
        At<unsigned char>(self, 0xb9) = ok;
    }
    return ok;
}

}}} // namespace Scaleform::GFx::IME

// MS2-FUNCTIONAL: invokes an ActionScript method on the movie (Movie::InvokeArgs, no result).
// @0x1423ca030
extern "C" void FUN_1423ca030(void* movie, const char* method, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    static_cast<Scaleform::GFx::Movie*>(movie)->InvokeArgs(method, 0, fmt, args);
    va_end(args);
}

// MS2-FUNCTIONAL: destroys a run of 0x30-byte IME records (names at +0x10/+0x18), last to first.
// @0x1423c9330
extern "C" void FUN_1423c9330(unsigned long long records, unsigned long long count)
{
    for (; count; --count)
    {
        unsigned char* record = reinterpret_cast<unsigned char*>(records) + (count - 1) * 0x30;
        reinterpret_cast<Scaleform::String*>(record + 0x18)->~String();
        reinterpret_cast<Scaleform::String*>(record + 0x10)->~String();
    }
}

namespace Scaleform { namespace GFx { namespace IME {

// MS2-FUNCTIONAL: IsTextFieldOnTopLevel-style checks: is the path inside the IME candidate/status levels.
// @0x1423ca060
bool FUN_1423ca060(void*, const char* path) { return strstr(path, "_level9999") != 0; }
// @0x1423ca080
bool FUN_1423ca080(void*, const char* path) { return strstr(path, "_level9998") != 0; }
// @0x1423ca0a0
bool FUN_1423ca0a0(void*, const char* path) { return strstr(path, "_level9997") != 0; }

// MS2-FUNCTIONAL: forwards to the owner (+0x18 slot 0x88) and the language bar (slot 0x18).
// @0x1423ca100
void FUN_1423ca100(void* self, void* arg)
{
    VCall<void>(At<void*>(self, 0x18), 0x88, arg);
    void* bar = At<void*>(self, 0x70);
    if (bar)
        VCall<void>(bar, 0x18, arg);
}

// MS2-FUNCTIONAL: forwards to the language bar (slot 0xd8) and, for Japanese, resets the candidate position.
// @0x1423ca160
void FUN_1423ca160(void* self, void* arg)
{
    void* bar = At<void*>(self, 0x70);
    if (bar)
        VCall<void>(bar, 0xd8, arg);
    if (strcmp(At<String>(self, 0xb0).ToCStr(), "Japanese") == 0)
        VCall<void>(At<void*>(self, 0x78), 0x50, -1);
}

}}} // namespace Scaleform::GFx::IME

namespace Scaleform { namespace GFx {

// MS2-FUNCTIONAL: ArrayDataBase<Video::VideoPlayer::CuePoint, AllocatorGH<CuePoint,2>>::Reserve (0x30-byte
// elements; { Data, Size, Policy.Capacity }).
// @0x1423ca2b0
void FUN_1423ca2b0(void* array, const void*, UPInt newCapacity)
{
    void*& data = At<void*>(array, 0);
    UPInt& capacity = At<UPInt>(array, 0x10);
    if (newCapacity == 0)
    {
        if (data)
        {
            Memory::pGlobalHeap->Free(data);
            data = 0;
        }
        capacity = 0;
        return;
    }
    UPInt rounded = (newCapacity + 3) & ~(UPInt)3;
    if (data)
        data = Memory::pGlobalHeap->Realloc(data, rounded * 0x30);
    else
    {
        AllocInfo info(2, 0, 0);
        data = Memory::pGlobalHeap->Alloc(rounded * 0x30, &info);
    }
    capacity = rounded;
}

}} // namespace Scaleform::GFx

// Empty vtable slots without .pdata (`ret 0`) the AS2 data images reference.
// MS2-FUNCTIONAL: empty leaf.
// @0x1423c9000
void FUN_1423c9000() {}

// MS2-FUNCTIONAL: empty leaf.
// @0x1423c9010
void FUN_1423c9010() {}

// MS2-FUNCTIONAL: empty leaf.
// @0x1423c9b90
void FUN_1423c9b90() {}
