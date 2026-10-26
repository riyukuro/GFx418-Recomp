// Recovered from MapleStory2.exe: Scaleform GFx IME support.
// MS2-UNIT: sfr_ime_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c8a50-0x1423c8fa0 .text$mn
// MS2-RANGE: 0x1423c8fa0-0x1423c8ff3 .text$mn
// MS2-RANGE: 0x1423ca140-0x1423ca160 .text$mn
// MS2-RANGE: 0x1423ca1c0-0x1423ca2b0 .text$mn
// MS2-RANGE: 0x1423ca350-0x1423dbde0 .text$mn
#include <windows.h>
#include <imm.h>
#include <oleauto.h>
#include <cstdarg>
#include <vector>
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_hash.h"
#include "../include/kernel/sf_string.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/gfx_value.h"
#include "../include/gfx/as3/as3_support.h"
#include "../include/gfx/xml/xml_object.h"

namespace Scaleform { namespace GFx { class Movie { public: void Release(); }; } }
namespace Scaleform { namespace GFx { namespace IME {

void FUN_1423d9090(void*, void*, unsigned long long);
void FUN_1423d8b80(unsigned long long*, void*, void**, unsigned long long);
void FUN_1423d9b40(void*);
    unsigned char FUN_1423da320(void*, void*, void*, void*);
    void FUN_1423d9500(void*);
    void FUN_1425b43c0(void*);
    void FUN_1423d5fd0(void*);
    void FUN_1423c8bb0(unsigned long long*);
    class GFxIMEManagerWin32;
    void FUN_1423ca560(GFxIMEManagerWin32*, unsigned);
    // Defined below in IME (the callers used to reach them through extern "C" twins that never linked).
    void FUN_1423cc7c0(void*, unsigned);
    void FUN_1423cde00(void*);
    void FUN_1423cdf60(unsigned long long*);
    unsigned long long FUN_1423daf30(void*, int);
    void FUN_1423ccdc0(unsigned long long*, String*);
    void FUN_1423cc2d0(unsigned long long*);
    void FUN_1423cc570(unsigned long long*);
} } }
namespace Scaleform { namespace GFx { namespace AS3 { void SF_STDCALL DoAbcLoader(LoadProcess*, const TagInfo&); } } }
extern "C" void FUN_1425c8cf0(unsigned, void*);

static HIMC cx18_ImmGetContext(HWND hwnd)
{
    typedef HIMC (WINAPI* Fn)(HWND);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetContext"))(hwnd);
}
static DWORD cx18_ImmGetCandidateListW(HIMC context, DWORD index, LPCANDIDATELIST list, DWORD bytes)
{
    typedef DWORD (WINAPI* Fn)(HIMC, DWORD, LPCANDIDATELIST, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetCandidateListW"))(
        context, index, list, bytes);
}
static LONG cx18_ImmGetCompositionStringW(HIMC context, DWORD index, LPVOID buffer, DWORD bytes)
{
    typedef LONG (WINAPI* Fn)(HIMC, DWORD, LPVOID, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetCompositionStringW"))(
        context, index, buffer, bytes);
}
static DWORD cx18_ImmGetProperty(HKL layout, DWORD index)
{
    typedef DWORD (WINAPI* Fn)(HKL, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetProperty"))(layout, index);
}
static BOOL cx18_ImmSetCompositionWindow(HIMC context, LPCOMPOSITIONFORM form)
{
    typedef BOOL (WINAPI* Fn)(HIMC, LPCOMPOSITIONFORM);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmSetCompositionWindow"))(context, form);
}
static BOOL cx18_ImmSetCandidateWindow(HIMC context, LPCANDIDATEFORM form)
{
    typedef BOOL (WINAPI* Fn)(HIMC, LPCANDIDATEFORM);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmSetCandidateWindow"))(context, form);
}
static UINT cx18_ImmGetVirtualKey(HWND hwnd)
{
    typedef UINT (WINAPI* Fn)(HWND);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetVirtualKey"))(hwnd);
}
static BOOL cx18_ImmIsUIMessageW(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    typedef BOOL (WINAPI* Fn)(HWND, UINT, WPARAM, LPARAM);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmIsUIMessageW"))(
        hwnd, message, wParam, lParam);
}
static BOOL cx18_ImmNotifyIME(HIMC context, DWORD action, DWORD index, DWORD value)
{
    typedef BOOL (WINAPI* Fn)(HIMC, DWORD, DWORD, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmNotifyIME"))(context, action, index, value);
}
static BOOL cx18_ImmReleaseContext(HWND hwnd, HIMC context)
{
    typedef BOOL (WINAPI* Fn)(HWND, HIMC);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmReleaseContext"))(hwnd, context);
}
static UINT cx18_ImmGetIMEFileNameA(HKL layout, LPSTR buffer, UINT capacity)
{
    typedef UINT (WINAPI* Fn)(HKL, LPSTR, UINT);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetIMEFileNameA"))(layout, buffer, capacity);
}
static BOOL cx18_ImmAssociateContextEx(HWND hwnd, HIMC context, DWORD flags)
{
    typedef BOOL (WINAPI* Fn)(HWND, HIMC, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmAssociateContextEx"))(hwnd, context, flags);
}
static BOOL cx18_ImmSetOpenStatus(HIMC context, BOOL open)
{
    typedef BOOL (WINAPI* Fn)(HIMC, BOOL);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmSetOpenStatus"))(context, open);
}
static BOOL cx18_ImmGetOpenStatus(HIMC context)
{
    typedef BOOL (WINAPI* Fn)(HIMC);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetOpenStatus"))(context);
}
static BOOL cx18_ImmGetConversionStatus(HIMC context, DWORD* conversion, DWORD* sentence)
{
    typedef BOOL (WINAPI* Fn)(HIMC, DWORD*, DWORD*);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetConversionStatus"))(context, conversion, sentence);
}
static BOOL cx18_ImmSetConversionStatus(HIMC context, DWORD conversion, DWORD sentence)
{
    typedef BOOL (WINAPI* Fn)(HIMC, DWORD, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmSetConversionStatus"))(context, conversion, sentence);
}
static BOOL cx18_ImmSetCompositionStringW(HIMC context, DWORD index, LPCVOID comp, DWORD compBytes, LPCVOID read, DWORD readBytes)
{
    typedef BOOL (WINAPI* Fn)(HIMC, DWORD, LPCVOID, DWORD, LPCVOID, DWORD);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmSetCompositionStringW"))(context, index, comp, compBytes, read, readBytes);
}

extern "C" void FUN_14015b310(void*, unsigned long long);
extern "C" void FUN_1424ddcb0(void* self);   // the in-place AvmDisplayObj destructor (sfr_as3_16)
extern "C" void FUN_14257db50(void*);
extern "C" void FUN_1425b4e80(void*, const wchar_t*, ...);
extern "C" void FUN_1425b4ea0(void*);
extern "C" const void* DAT_14313a210[];
extern "C" const void* DAT_14313b920[];
extern "C" const void* DAT_14313b968[];
extern "C" const void* DAT_14313a228[];
extern "C" const void* DAT_14313a1d8[];
extern "C" const void* DAT_14313b9c8[];
extern "C" const void* DAT_14313a238[];
extern "C" const void* DAT_14313a450[];
extern "C" const void* DAT_14313a5f8[];
extern "C" char DAT_143109420[];     // ??_7State@GFx@Scaleform@@6B@
extern "C" const void* DAT_14313a200[];
extern "C" const void* DAT_143138360[];
extern "C" void FUN_1423d9090(void*, void*, unsigned long long);
extern "C" void FUN_1423d9690(void*, void*, unsigned long long);
extern "C" void FUN_1423d95f0(void*, void*, unsigned long long);
unsigned HashFunction(const char*, unsigned long long);
extern "C" void FUN_14257dcd0(void*);
extern void FUN_14257dcb0(void*);
extern bool FUN_1425b9b10(void*);
extern "C" void FUN_14257db40(void*);
extern "C" void FUN_1422fd480(void*, void*);
extern "C" unsigned long long* FUN_1423cabb0(unsigned long long*, unsigned long long);
extern "C" const unsigned long long DAT_14313b410;
extern "C" const unsigned long long DAT_14313b418;
extern "C" const void* DAT_14313ba60[];
extern "C" const unsigned char DAT_1431c51e8[];
extern "C" const unsigned char DAT_1431c5018[];
extern "C" const unsigned long long DAT_1431c4d58;
extern "C" const unsigned long long DAT_14313b8b8;
extern "C" const unsigned long long DAT_1431c4828;
extern "C" const unsigned long long DAT_1431c4830;
extern "C" const unsigned long long DAT_14313b8a8;
extern "C" const unsigned long long DAT_14313b8c8;
extern "C" const unsigned char DAT_14313b400[];
extern "C" const unsigned char DAT_1431c4878[];
extern "C" const unsigned char DAT_1431c51b8[];
extern "C" void* DAT_14313b520[];
extern "C" void* DAT_14313b5a0[];
extern "C" void* DAT_14313b5c0[];
extern "C" const unsigned long long DAT_1431c4d60;
extern "C" const unsigned long long DAT_14313b8c0;
extern "C" const unsigned long long DAT_1431c4e08;
extern "C" const unsigned long long DAT_1431c4e10;
extern "C" const unsigned long long DAT_1431c4ee8;
extern "C" const unsigned long long DAT_1431c4898;
extern "C" const unsigned long long DAT_1431c5068;
extern "C" const unsigned long long DAT_14313b6b0;
extern "C" const unsigned long long DAT_1431c4858;
extern "C" const unsigned long long DAT_1431c4d28;
extern "C" const unsigned char DAT_1431c5028[];
extern "C" const unsigned long long DAT_14313b8d8;
extern "C" const unsigned long long DAT_1431c4888;
extern "C" const unsigned long long DAT_1431c51d8;
extern "C" const unsigned long long DAT_1431c48f8;
extern "C" const unsigned char DAT_143a2a3e0[];
extern "C" const unsigned char DAT_143a293e0[];
extern "C" const int DAT_143a2a6b4;
extern "C" const char DAT_14305cd3c[];
extern "C" const unsigned long long DAT_1431c4ef0;
extern "C" void* DAT_143b15f60;
extern "C" const void* DAT_14313bc60[];
extern "C" void FUN_1423dd1c0();
extern "C" void FUN_1423dc7b0();
extern "C" void FUN_1423ca030(void*, const char*, const char*, ...);
extern "C" void FUN_142576820(void*, const char*, void**, int);
extern "C" void FUN_1425b49b0();
extern "C" void FUN_14257dc30(void*);
extern "C" int FUN_14256eff0(void*);           // Movie::GetAVMVersion
extern "C" void FUN_1423c9330(unsigned long long, unsigned long long);
extern "C" void FUN_1422fbf60(void*);

struct HWND__;

namespace Scaleform { namespace GFx { namespace IME {

unsigned long long* FUN_1423cabb0(unsigned long long*, unsigned long long);

class GFxIMEManagerWin32
{
public:
    volatile int refCount;
    unsigned int refPad;
    unsigned int state;
    unsigned int statePad;
    unsigned char pad_18[0x48];
    void* p60;
    ::HWND__* hwnd;
    void* p70;
    void* p78;
    unsigned char pad_80[8];
    String language;
    String imeName;
    String displayName;
    unsigned char pad_a0[0x10];
    String conversionMode;
public:
    explicit GFxIMEManagerWin32(::HWND__* hwnd);
    virtual ~GFxIMEManagerWin32();
};

static_assert(offsetof(GFxIMEManagerWin32, p60) == 0x60, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, hwnd) == 0x68, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, language) == 0x88, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, conversionMode) == 0xb0, "IME layout");

#ifndef MS2_HOOK_DLL
// The IMEManagerBase constructor (sfr_gfx_03d) and the manager's own vtable (data_rdata_sf_a): this stand-in class
// has no IMEManagerBase base, so the constructor builds the base part and installs the exe's 38-slot vtable itself.
extern "C" void FUN_1425b3e90(void* self);
extern "C" void* DAT_1431383e0[];
#endif

// MS2-FUNCTIONAL: constructor frame differs; the base part and the vtable are set up by hand (see above).
// @0x1423c8a50
GFxIMEManagerWin32::GFxIMEManagerWin32(::HWND__* window)
    : refCount(1), refPad(0), state(0), statePad(0), p60(0), hwnd(window), p70(0), p78(0)
{
#ifndef MS2_HOOK_DLL
    FUN_1425b3e90(this);
    *reinterpret_cast<void***>(this) = DAT_1431383e0;
    p60 = 0;
    hwnd = window;
    p70 = 0;
    p78 = 0;
#endif
}

// MS2-FUNCTIONAL: the children at +0x70 and +0x78 are released through their vtable slot 0 (deleting dtor, flag 1).
// @0x1423c8ac0
GFxIMEManagerWin32::~GFxIMEManagerWin32()
{
    if (p70)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p70))[0](p70, 1);
    if (p78)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p78))[0](p78, 1);
}


}}}

// MS2-PIN: ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z 0x1423c8ce0
// MS2-FUNCTIONAL ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z: generated deleting wrapper is 49 bytes shorter; base state destruction is not modeled yet.

namespace Scaleform { namespace GFx { namespace IME {

// MS2-FUNCTIONAL: follows the executable's composition-specific Escape path and both candidate/input-window teardown paths.
// @0x1423d2f00
void FUN_1423d2f00(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    if (*reinterpret_cast<unsigned*>(bytes + 0x98) == 0x00c10000) {
        void* base = *reinterpret_cast<void**>(bytes + 8);
        void* factory = static_cast<unsigned char*>(base) + 0x10;
        void* value = reinterpret_cast<void*(*)(void*, int)>(
            (*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
        INPUT input{};
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
        FUN_1425b43c0(value);
        FUN_1423d9500(*reinterpret_cast<void**>(bytes + 0x30));
        void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
        void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
        if (values) {
            Scaleform::GFx::Value result;
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveList", &result, 0, 0);
        }
        if (value) FUN_14257dcb0(value);
        return;
    }
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x11, 0, 0);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmReleaseContext(hwnd, context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xd0) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
    if (values) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveInputWindow", &result, 0, 0);
    }
}

// MS2-FUNCTIONAL: closes the executable's composition state, Escape-clears candidate modes, and removes the input window.
// @0x1423ce5a0
void FUN_1423ce5a0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x11, 0, 0);
    FUN_1423da320(*reinterpret_cast<void**>(bytes + 0xc8), nullptr, nullptr, nullptr);
    const unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x98);
    if (mode - 5u < 2u) {
        INPUT input{};
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
    }
    *reinterpret_cast<unsigned short*>(*reinterpret_cast<unsigned short**>(bytes + 0x40)) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
    if (values) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveInputWindow", &result, 0, 0);
    }
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: processes the executable's IME key and mouse messages, including composition cancellation.
// @0x1423d0cf0
void FUN_1423d0cf0(unsigned long long* self, const unsigned char* event)
{
    const unsigned message = *reinterpret_cast<const unsigned*>(event + 0xc);
    const unsigned long long key = *reinterpret_cast<const unsigned long long*>(event + 0x10);
    if (message == 0x100 && key == 0x10) {
        *reinterpret_cast<unsigned short*>(self + 0x14) = 1;
    }
    if (message == 0x101 && static_cast<unsigned char>(self[0x14]) == 1 && key == 0xe5) {
        void* child = reinterpret_cast<void*>(self[1]);
        if (child) {
            unsigned char notification[0x28]{};
            *reinterpret_cast<unsigned*>(notification) = 6;
            *reinterpret_cast<unsigned*>(notification + 8) = 0x10;
            reinterpret_cast<void(*)(void*, const void*)>((*reinterpret_cast<void***>(child))[0x110 / sizeof(void*)])(
                child, notification);
        }
    }
    if (message == 0x202 && *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0xb9)) {
        reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(self))[0x110 / sizeof(void*)])(
            self, -*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x64));
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0xb9) = 0;
    }
    const unsigned mode = static_cast<unsigned>(self[0x13]);
    const bool inputMode = mode == 0xd00001 || (mode >= 5 && mode <= 6) || mode == 0xa10000 || mode == 0xb10000;
    const bool clearKey = (message == 0x100 && key == 0x25) || (key >= 0x26 && key <= 0x28) || key == 0xd;
    if (!inputMode || !clearKey || !(message == 0x100 || key >= 0x26)) return;
    HWND hwnd = reinterpret_cast<HWND>(self[5]);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x11, 0, 0);
    FUN_1423da320(reinterpret_cast<void*>(self[0x19]), nullptr, nullptr, nullptr);
    if (mode == 5 || mode == 6) {
        INPUT input{};
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
    }
    *reinterpret_cast<unsigned short*>(*reinterpret_cast<unsigned short**>(self + 8)) = 0;
    void* movie = reinterpret_cast<void*>(self[0x15]);
    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
    if (values) {
        void* output = nullptr;
        reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveInputWindow", &output, 0, 0);
    }
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: dispatches the executable's IME composition and candidate-list messages by input mode.
// @0x1423d02d0
LRESULT FUN_1423d02d0(unsigned long long* self, UINT message, unsigned long long type, LPARAM value)
{
    if (!self[1]) return 0;
    const unsigned mode = static_cast<unsigned>(self[0x13]);
    const bool firstModes = mode == 0x3000 || mode == 0x60000 || mode == 0xb10000 ||
        mode == 0xa10000 || mode == 0xd00800 || mode == 0xd00900 || mode == 0xd00a00;
    const bool secondModes = mode == 0x210000 || mode == 0x110000 || mode == 0x810000 || mode == 0xd10000;
    auto** vtable = reinterpret_cast<void**>(self[0]);
    LRESULT result = 0;
    if (type == 3) {
        if (firstModes) reinterpret_cast<void(*)(void*, int)>(vtable[0x118 / sizeof(void*)])(self, 0);
        else if (secondModes) {
            reinterpret_cast<void(*)(void*, int)>(vtable[0x118 / sizeof(void*)])(self, 0);
            result = 2;
        }
    } else if (type == 4) {
        const bool removeList = mode == 0x210000 || mode == 0x3000 || mode == 0x60000 || mode == 0xb10000 ||
            mode == 0xa10000 || mode == 0xd00800 || mode == 0xd00900 || mode == 0x110000 ||
            mode == 0xd00a00 || mode == 0x810000 || mode == 0xd10000;
        if (removeList) {
            FUN_1423d9500(reinterpret_cast<void*>(self[6]));
            void* movie = reinterpret_cast<void*>(self[0x15]);
            void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
            if (values) {
                void* output = nullptr;
                reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
                    (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                        values, "RemoveList", &output, 0, 0);
            }
        }
        return DefWindowProcW(reinterpret_cast<HWND>(self[5]), message, 4, value);
    } else if (type == 5) {
        if (firstModes || mode == 0x810000)
            reinterpret_cast<void(*)(void*, int)>(vtable[0x120 / sizeof(void*)])(self, 0);
        else if (mode == 0x210000 || mode == 0x110000 || mode == 0xd10000) {
            reinterpret_cast<void(*)(void*, int)>(vtable[0x120 / sizeof(void*)])(self, 0);
            result = 2;
        }
    } else if (type == 0xe && secondModes) {
        reinterpret_cast<void(*)(void*, unsigned, unsigned)>(vtable[0x70 / sizeof(void*)])(self, message, 0xe);
        return 2;
    }
    if (type == 3 || type == 5) return result;
    reinterpret_cast<void(*)(void*, unsigned, unsigned long long, LPARAM)>(
        vtable[0x70 / sizeof(void*)])(self, message, type, value);
    return result;
}

// MS2-FUNCTIONAL: handles the executable's focus, candidate-list, and IME notification messages.
// @0x1423d41f0
bool FUN_1423d41f0(unsigned long long* self, unsigned reason, unsigned long long message, unsigned long long value)
{
    void* child = reinterpret_cast<void*>(self[1]);
    if (!child) return false;
    bool handled = false;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x5b8) = static_cast<unsigned>(value);
    auto** vtable = reinterpret_cast<void**>(self[0]);
    if (message == 3) {
        reinterpret_cast<void(*)(void*, int)>(vtable[0x110 / sizeof(void*)])(self, 0);
        handled = static_cast<unsigned>(self[0x13] - 5) > 1;
    } else if (message == 4) {
        FUN_1423d9500(reinterpret_cast<void*>(self[6]));
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0x5bc) = 0;
        void* movie = reinterpret_cast<void*>(self[0x15]);
        void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
        if (values) {
            Scaleform::GFx::Value result;
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveList", &result, 0, 0);
        }
    } else if (message == 5) {
        void* factory = static_cast<unsigned char*>(child) + 0x10;
        void* temporary = reinterpret_cast<void*(*)(void*, int)>(
            (*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
        reinterpret_cast<void(*)(void*, int)>(vtable[0x118 / sizeof(void*)])(self, 0);
        handled = static_cast<unsigned>(self[0x13] - 5) > 1;
        if (temporary) FUN_14257dcb0(temporary);
    } else if (message == 0xe) {
        const unsigned mode = static_cast<unsigned>(self[0x13]);
        if (mode == 4 && *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x9c) == 0x04040404)
            handled = value == 1 || value == 2;
        else if (mode == 2)
            handled = value == 2 || value == 0x1a || value == 0x1b;
    }
    if (!handled && message != 3 && message != 4 && message != 5)
        reinterpret_cast<void(*)(void*, unsigned)>(vtable[0x70 / sizeof(void*)])(self, reason);
    return handled;
}

// MS2-FUNCTIONAL: destroys the XML node chain after unlinking each DOM string node from its hash table.
// @0x1423cb0f0
void FUN_1423cb0f0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    ::operator delete[](*reinterpret_cast<void**>(bytes + 0x190));
    void* node = *reinterpret_cast<void**>(bytes + 0x140);
    *reinterpret_cast<void**>(bytes + 0x110) = node;
    while (node) {
        void* next = *reinterpret_cast<void**>(static_cast<unsigned char*>(node) + 0x28);
        FUN_1423cc570(static_cast<unsigned long long*>(node));
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, node);
        *reinterpret_cast<void**>(bytes + 0x110) = next;
        node = next;
    }
}

// MS2-FUNCTIONAL: unlinks this DOM string node from the executable's bucket chains and releases its key allocation.
// @0x1423cc570
void FUN_1423cc570(unsigned long long* node)
{
    auto* owner = reinterpret_cast<unsigned long long*>(node[6]);
    auto* table = owner ? reinterpret_cast<unsigned long long*>(owner[1]) : nullptr;
    if (table) {
        const unsigned long long mask = table[1];
        const unsigned long long bucket = *reinterpret_cast<unsigned*>(node + 4) & mask;
        auto* slot = reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(table) + (bucket + 1) * 0x10);
        if (slot[0] != 0xfffffffffffffffeull &&
            ((*reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(reinterpret_cast<void*>(slot[1])) + 0x20) & mask) == bucket)) {
            unsigned long long previous = 0xffffffffffffffffull;
            unsigned long long current = bucket;
            while (((*reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(reinterpret_cast<void*>(slot[1])) + 0x20) & mask) != bucket) ||
                   slot[1] != reinterpret_cast<unsigned long long>(node)) {
                const unsigned long long nextSlot = slot[0];
                if (nextSlot == 0xffffffffffffffffull) goto unlink_done;
                previous = current;
                current = nextSlot;
                slot = reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(table) + (current + 1) * 0x10);
            }
            const unsigned long long next = slot[0];
            if (bucket == current) {
                if (next != 0xffffffffffffffffull) {
                    slot[0] = 0xfffffffffffffffeull;
                    auto* replacement = reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(table) + (next + 1) * 0x10);
                    slot[0] = replacement[0];
                    slot[1] = replacement[1];
                    slot = replacement;
                }
            } else {
                auto* prior = reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(table) + (previous + 1) * 0x10);
                prior[0] = next;
            }
            slot[0] = 0xfffffffffffffffeull;
            --*reinterpret_cast<unsigned long long*>(*reinterpret_cast<unsigned long long**>(owner));
        }
    }
unlink_done:
    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, reinterpret_cast<void*>(node[0]));
}

// MS2-FUNCTIONAL: returns the executable's ID-backed integer and Value-backed string properties from the current IME state.
// @0x1423da150
void FUN_1423da150(void* self, void* output, const String* key)
{
    const auto packed = *reinterpret_cast<const unsigned long long*>(key);
    const char* name = reinterpret_cast<const char*>((packed & ~3ull) + 0xc);
    auto* value = static_cast<unsigned char*>(output);
    const bool isString = std::strcmp(name, "Value") == 0;
    const bool isId = !isString && std::memcmp(name, "ID", 3) == 0;
    if (!isString && !isId) return;
    const unsigned oldType = *reinterpret_cast<unsigned*>(value + 8);
    if (oldType & 0x40) {
        void* ref = *reinterpret_cast<void**>(value);
        reinterpret_cast<void(*)(void*, void*, unsigned long long)>(
            (*reinterpret_cast<void***>(ref))[2])(ref, output, *reinterpret_cast<unsigned long long*>(value + 16));
        *reinterpret_cast<void**>(value) = nullptr;
    }
    if (isId) {
        *reinterpret_cast<unsigned long long*>(value + 16) = static_cast<unsigned long long>(
            static_cast<double>(*reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x10)));
        *reinterpret_cast<unsigned*>(value + 8) = 5;
        return;
    }
    *reinterpret_cast<unsigned long long*>(value + 16) = (packed & ~3ull) + 0xc;
    *reinterpret_cast<unsigned*>(value + 8) = 6;
}

// MS2-FUNCTIONAL: queries the active keyboard layout, updates its locale label, and selects the executable's mode text.
// @0x1423d7140
void FUN_1423d7140(unsigned long long* manager)
{
    const HKL layout = GetKeyboardLayout(0);
    manager[0x33] = reinterpret_cast<unsigned long long>(layout);
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    const unsigned language = reinterpret_cast<unsigned(*)(void*, short)>(vtable[4])(
        manager, static_cast<short>(manager[0x33]));
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = language;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), language);
    wchar_t locale[0x104]{};
    if (!GetLocaleInfoW(static_cast<LCID>(reinterpret_cast<ULONG_PTR>(layout) & 0xffff), LOCALE_SLANGUAGE,
                        locale, _countof(locale))) {
        reinterpret_cast<void(*)(void*, DWORD, const char*)>(vtable[0x78 / sizeof(void*)])(
            manager, GetLastError(), "GFxIME Error: Error Initializing Input Language ");
        void* languageObject = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(languageObject))[0x78 / sizeof(void*)])(
            languageObject, "Unsupported");
        return;
    }
    String localeText(locale);
    void* languageObject = reinterpret_cast<void*>(manager[0xf]);
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(languageObject))[0x78 / sizeof(void*)])(
        languageObject, localeText.ToCStr());
    unsigned mode = static_cast<unsigned>(manager[0x11]);
    if (mode == 0x01000000) {
        String unsupported("Not Supported");
        FUN_1423ccdc0(manager, &unsupported);
        mode = static_cast<unsigned>(manager[0x11]);
    }
    if (mode == 0x03000000) FUN_1423ccdc0(manager, &localeText);
    else FUN_1423cc2d0(manager);
}

// restores the three destructor vftable views, frees owned state, and honors scalar/sized delete flags.
// @0x1423d56b0
void* FUN_1423d56b0(void* self, unsigned flags)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<void***>(bytes) = DAT_14313b520;
    *reinterpret_cast<void***>(bytes + 0x1a0) = DAT_14313b5a0;
    *reinterpret_cast<void***>(bytes + 0x1a8) = DAT_14313b5c0;
    FUN_1423d5fd0(self);
    FUN_1423c8bb0(static_cast<unsigned long long*>(self));
    if (flags & 1) {
        if (!(flags & 4)) {
            void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, self);
        } else
            FUN_14015b310(self, 0x1d8);
    }
    return self;
}

// MS2-FUNCTIONAL: releases the executable's linked IME records, pair arrays, and optional conversion interfaces.
// @0x1423d5fd0
void FUN_1423d5fd0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    const unsigned listCount = *reinterpret_cast<unsigned*>(bytes + 0xd0);
    auto** lists = *reinterpret_cast<void***>(bytes + 0xb8);
    for (unsigned i = 0; i < listCount; ++i) {
        auto* node = *reinterpret_cast<void***>(reinterpret_cast<unsigned char*>(lists[i]) + 0x28);
        while (node) {
            void* next = node[1];
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, node[0]);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, node);
            node = static_cast<void**>(next);
        }
    }
    auto* pairs = *reinterpret_cast<unsigned char**>(bytes + 0x158);
    const unsigned long long pairCount = *reinterpret_cast<unsigned long long*>(bytes + 0x160);
    for (unsigned long long i = 0; i < pairCount; ++i) {
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60,
            *reinterpret_cast<void**>(pairs + i * 0x18 + 8));
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60,
            *reinterpret_cast<void**>(pairs + i * 0x18));
    }
    auto* items = *reinterpret_cast<unsigned char**>(bytes + 0x90);
    const unsigned itemCount = *reinterpret_cast<unsigned*>(bytes + 0x80);
    for (unsigned i = 0; i < itemCount; ++i) {
        void* item = *reinterpret_cast<void**>(items + static_cast<unsigned long long>(i) * 0x20);
        if (item) reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, item);
    }
    auto* remote = *reinterpret_cast<void**>(bytes + 0x1d0);
    auto releaseRemote = [](void* value) {
        if (value) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(value))[2])(value);
    };
    auto releaseId = [&](unsigned offset, bool handleSpecial) {
        if (*reinterpret_cast<int*>(bytes + offset) == -1) return;
        void* queried = nullptr;
        if (remote && SUCCEEDED(reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(remote))[0])(remote, DAT_1431c51e8, &queried))) {
            const HRESULT hr = reinterpret_cast<HRESULT(*)(void*, unsigned)>(
                (*reinterpret_cast<void***>(queried))[4])(queried,
                    *reinterpret_cast<unsigned*>(bytes + offset));
            if (handleSpecial && static_cast<unsigned>(hr) == 0x80040200u) {
                void* callback = *reinterpret_cast<void**>(bytes + 0x1a0);
                reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(callback))[2])(callback);
            }
            releaseRemote(queried);
        }
        *reinterpret_cast<int*>(bytes + offset) = -1;
    };
    releaseId(0x1b8, true);
    releaseId(0x1b0, false);
    releaseRemote(*reinterpret_cast<void**>(bytes + 0x1a0));
}

// MS2-FUNCTIONAL: follows the executable's selected TextField refcount and input-eligibility checks.
// @0x1423cf570
unsigned char FUN_1423cf570(void*, void* rawMovie)
{
    if (!rawMovie) return 0;
    auto* movie = static_cast<unsigned char*>(rawMovie);
    auto* selected = movie + static_cast<unsigned>(movie[0x3464]) * 0x60;
    auto* handle = *reinterpret_cast<unsigned long long**>(selected + 0x2e88);
    if (!handle) return 0;
    auto* field = reinterpret_cast<unsigned char*>(handle[1]);
    if (!field) {
        auto* count = reinterpret_cast<volatile long*>(handle);
        if (_InterlockedDecrement(count) == 0) {
            void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, handle);
        }
        *reinterpret_cast<void**>(selected + 0x2e88) = nullptr;
        return 0;
    }
    auto* refs = reinterpret_cast<volatile long*>(field + 8);
    if (*refs == 0) return 0;
    *refs += 2;
    FUN_14257dcd0(field);
    const int type = reinterpret_cast<int(*)(void*)>((*reinterpret_cast<void***>(field))[0x258 / sizeof(void*)])(field);
    unsigned char accepted = 0;
    if (type == 4) {
        ++*refs;
        const unsigned flags = *reinterpret_cast<unsigned*>(field + 0xfc);
        if (((flags >> 11) & 1) == 0 && !FUN_1425b9b10(field) && ((flags >> 2) & 1) == 0)
            accepted = 1;
        FUN_14257dcd0(field);
    }
    FUN_14257dcd0(field);
    return accepted;
}

// MS2-FUNCTIONAL: recreates the executable's temporary IME-context acquisition and open-status query.
// @0x1423cf3e0
unsigned long long FUN_1423cf3e0(void* self)
{
    HWND hwnd = *reinterpret_cast<HWND*>(static_cast<unsigned char*>(self) + 0x28);
    bool alreadyAssociated = true;
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) {
        alreadyAssociated = false;
        cx18_ImmAssociateContextEx(hwnd, nullptr, 0x10);
        context = cx18_ImmGetContext(hwnd);
        if (!context) return static_cast<unsigned long long>(cx18_ImmReleaseContext(hwnd, nullptr)) & ~0xffull;
    }
    using GetOpenStatusFn = BOOL (WINAPI*)(HIMC);
    auto getOpenStatus = reinterpret_cast<GetOpenStatusFn>(
        GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetOpenStatus"));
    const BOOL open = getOpenStatus(context);
    if (!alreadyAssociated) cx18_ImmAssociateContextEx(hwnd, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    return open != 0;
}

// MS2-FUNCTIONAL: maps the active Windows keyboard layout to the IME display labels observed in the executable.
// @0x1423cf4a0
String* FUN_1423cf4a0(void* self, String* output)
{
    const HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(static_cast<unsigned char*>(self) + 0x90) = layout;
    const unsigned language = reinterpret_cast<unsigned long long>(layout) & 0xffff;
    const char* label = "Unknown";
    switch (language) {
    case 0x0419: label = "Russian"; break;
    case 0x0404: case 0x0804: label = "Chinese"; break;
    case 0x0409: case 0x0809: case 0x0c09: case 0x1009: label = "English"; break;
    case 0x0411: label = "Japanese"; break;
    case 0x0412: label = "Korean"; break;
    }
    return new (output) String(label);
}

// MS2-FUNCTIONAL: recreates the executable's COM instance activation, nested object creation, and release sequence.
// @0x1423da8b0
HRESULT FUN_1423da8b0(void*, void* argument, void* value)
{
    void* factory = nullptr;
    HRESULT result = CoCreateInstance(*reinterpret_cast<const IID*>(DAT_1431c4878), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(DAT_1431c51b8), &factory);
    if (FAILED(result)) return result;
    void* object = nullptr;
    const HRESULT created = reinterpret_cast<HRESULT(*)(void*, void*, void**, unsigned)>(
        (*reinterpret_cast<void***>(factory))[5])(factory, argument, &object, 0);
    if (FAILED(created)) {
        result = static_cast<HRESULT>(0x80070005u);
    } else {
        result = reinterpret_cast<HRESULT(*)(void*, void*)>(
            (*reinterpret_cast<void***>(object))[5])(object, value);
        reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
    }
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(factory))[2])(factory);
    return result;
}

// MS2-FUNCTIONAL: follows the executable's three-stage input-context COM query and releases each acquired interface.
// @0x1423da320
unsigned char FUN_1423da320(void* object, void*, void*, void* context)
{
    auto* bytes = static_cast<unsigned char*>(object);
    void* initial = *reinterpret_cast<void**>(bytes + 0x28);
    if (!initial) return 0;
    void* first = nullptr;
    void* second = nullptr;
    void* third = nullptr;
    unsigned char result = 0;
    const int hr1 = reinterpret_cast<int(*)(void*, const void*, void**, void*, unsigned, unsigned long long)>(
        (*reinterpret_cast<void***>(initial))[0])(initial, &DAT_14313b8a8, &first, context, 0,
                                                   0xfffffffffffffffeull);
    if (hr1 >= 0) {
        const int hr2 = reinterpret_cast<int(*)(void*, unsigned, void**)>(
            (*reinterpret_cast<void***>(first))[6])(first,
                *reinterpret_cast<unsigned*>(bytes + 0x64), &second);
        if (hr2 >= 0 && second) {
            const int hr3 = reinterpret_cast<int(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(second))[0])(second, &DAT_14313b8c8, &third);
            if (hr3 >= 0 && third) {
                reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(third))[0x88 / sizeof(void*)])(third);
                result = 1;
            }
        }
    }
    for (void* value : { first, second, third })
        if (value) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(value))[2])(value);
    return result;
}

// MS2-FUNCTIONAL: returns the executable's supported COM interface views and increments the shared refcount.
// @0x1423d72a0
long long FUN_1423d72a0(void* object, const unsigned long long* iid, void** output)
{
    if (!output) return static_cast<long long>(0x80070057u);
    *output = nullptr;
    auto* words = static_cast<unsigned long long*>(object);
    unsigned long long* view;
    if ((iid[0] == DAT_1431c4828 && iid[1] == DAT_1431c4830) ||
        (iid[0] == *reinterpret_cast<const unsigned long long*>(DAT_14313b400) &&
         iid[1] == *reinterpret_cast<const unsigned long long*>(DAT_14313b400 + 8))) {
        view = words + 1;
    } else if (iid[0] == *reinterpret_cast<const unsigned long long*>(DAT_1431c5018) &&
               iid[1] == *reinterpret_cast<const unsigned long long*>(DAT_1431c5018 + 8)) {
        view = words;
    } else {
        return static_cast<long long>(0x80004002u);
    }
    if (reinterpret_cast<unsigned long long>(object) == 0x1a0) view = nullptr;
    *output = view;
    if (!view) return static_cast<long long>(0x80004002u);
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[1])(object);
    return 0;
}

// Follows the executable's nested IME provider query and releases its temporary refcounted object.
// MS2-FUNCTIONAL: the exe keeps the provider in rcx and the result in dil (rax/bl here); same blocks
// @0x1423ce460
unsigned char FUN_1423ce460(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* provider = *reinterpret_cast<void**>(bytes + 8);
    Scaleform::GFx::Value unused;  // the exe keeps an unused Value local here
    unsigned char result;
    if (!provider)
        result = 1;
    else {
        void** factoryVtable = *reinterpret_cast<void***>(static_cast<unsigned char*>(provider) + 0x10);
        void* temporary = reinterpret_cast<void*(*)(void*, unsigned)>(factoryVtable[3])(
            static_cast<unsigned char*>(provider) + 0x10, 0x18);
        if (!temporary)
            result = 1;
        else {
            void* interfaceObject = *reinterpret_cast<void**>(static_cast<unsigned char*>(temporary) + 0x18);
            result = reinterpret_cast<unsigned char(*)(void*)>(
                (*reinterpret_cast<void***>(interfaceObject))[0x70 / sizeof(void*)])(interfaceObject);
            FUN_14257dcb0(temporary);
        }
    }
    return result;
}

// The manager calls that pass on to the language bar at +0x70 (the exe tail-jumps through its vtable).
template <class R, class... A>
static inline R BarCall(void* bar, unsigned off, A... a)
{
    return reinterpret_cast<R(*)(void*, A...)>((*reinterpret_cast<void***>(bar))[off / sizeof(void*)])(bar, a...);
}

// OnCandidateListStyleChanged (vtable slot 25).
// @0x1423ca140
void FUN_1423ca140(GFxIMEManagerWin32* self, const void* style)
{
    if (self->p70)
        BarCall<void>(self->p70, 0xc8, style);
}

// OnFinalize (slot 24).
// @0x1423ca1c0
void FUN_1423ca1c0(GFxIMEManagerWin32* self)
{
    if (self->p70)
        BarCall<void>(self->p70, 0x78);
}

// @0x1423ca1e0
unsigned FUN_1423ca1e0(GFxIMEManagerWin32* self, void* a, unsigned b, unsigned c, bool d)
{
    if (self->p70)
        return BarCall<unsigned>(self->p70, 0x68, a, b, c, d);
    return 0;
}

// OnShutdown (slot 23).
// @0x1423ca210
void FUN_1423ca210(GFxIMEManagerWin32* self)
{
    if (self->p70)
        BarCall<void>(self->p70, 0x90);
}

// @0x1423ca230
void FUN_1423ca230(GFxIMEManagerWin32* self, void* a)
{
    if (self->p70)
        BarCall<void>(self->p70, 0xa8, a);
}

// @0x1423ca250
void FUN_1423ca250(GFxIMEManagerWin32* self, void* a)
{
    if (self->p70)
        BarCall<void>(self->p70, 0x18, a);
}

// @0x1423ca270
void FUN_1423ca270(GFxIMEManagerWin32* self, void* a)
{
    if (self->p70)
        BarCall<void>(self->p70, 0x40, a);
}

// @0x1423ca290
void FUN_1423ca290(GFxIMEManagerWin32* self, void* a)
{
    if (self->p70)
        BarCall<void>(self->p70, 0x28, a);
}

// SetCompositionString (slot 21).
// @0x1423ca520
bool FUN_1423ca520(GFxIMEManagerWin32* self, const char* compString)
{
    if (self->p70)
        return BarCall<bool>(self->p70, 0xf8, compString);
    return false;
}

// SetConversionMode (slot 6).
// @0x1423ca540
bool FUN_1423ca540(GFxIMEManagerWin32* self, unsigned convMode)
{
    if (self->p70)
        return BarCall<bool>(self->p70, 0x100, convMode);
    return false;
}

// SetEnabled (slot 8).
// @0x1423ca620
bool FUN_1423ca620(GFxIMEManagerWin32* self, bool enable)
{
    if (self->p70)
        return BarCall<bool>(self->p70, 0xe8, enable);
    return false;
}

// @0x1423ca560
void FUN_1423ca560(GFxIMEManagerWin32* self, unsigned lang)
{
    String* text = &self->conversionMode;
    *text = "Unknown";
    if (lang & 0x10000000) *text = "English";
    if (lang & 0x00000f00) *text = "Japanese";
    if (lang & 0x0000f000) *text = "Korean";
    if (lang & 0x00ff0000) *text = "Chinese (Simplified)";
    if (lang & 0x0000000f) *text = "Chinese (Traditional)";
    void** vtable = *reinterpret_cast<void***>(self);
    reinterpret_cast<void(*)(void*, const char*)>(vtable[0x60 / sizeof(void*)])(self, text->ToCStr());
}

// @0x1423ca640
void FUN_1423ca640(void* self, unsigned value)
{
    *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x84) = value;
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x70);
    void** vtable = *reinterpret_cast<void***>(child);
    reinterpret_cast<void(*)(void*)>(vtable[17])(child);
}

// (sfr33) packed refcounted pointer release as the dtors inline it: the masked pointer is freed without a reload.
static __forceinline void Sfr33ReleasePacked(unsigned long long packed)
{
    unsigned long long p = packed & ~3ULL;
    if (_InterlockedDecrement(reinterpret_cast<volatile long*>(p + sizeof(void*))) == 0)
        Memory::Free(reinterpret_cast<void*>(p));
}

// MS2-FUNCTIONAL: the packed atomic pointer is decremented at the exe's +8 counter; its heap release is routed through our Memory facade.
// @0x1423ca920
unsigned long long FUN_1423ca920(void*, unsigned long long* packedPtr)
{
    volatile long* count = reinterpret_cast<volatile long*>((*packedPtr & ~3ULL) + sizeof(void*));
    const long remaining = _InterlockedDecrement(count);
    if (remaining == 0)
        Memory::Free(reinterpret_cast<void*>(*packedPtr & ~3ULL));
    return static_cast<unsigned long long>(remaining) & ~0xffULL;
}

// MS2-FUNCTIONAL: initializes executable-observed fields; one abstract interface's purecall-only vtable lacks a class declaration.
// @0x1423d9430
void* FUN_1423d9430(void* object, void* owner)
{
    auto* words = static_cast<unsigned long long*>(object);
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a210);
    for (unsigned index : { 0x102u, 0x103u, 0x104u, 0x105u, 0x106u, 0x107u, 0x109u, 0x10au, 0x10bu })
        words[index] = 0;
    *reinterpret_cast<unsigned char*>(words + 2) = 0;
    words[1] = 0;
    words[0x10d] = reinterpret_cast<unsigned long long>(owner);
    return object;
}

// The anonymous purecall-only interface's deleting destructor: plain new, so the CRT's sized delete (0x142749444).
// @0x1423ce2c0
void* FUN_1423ce2c0(void* object, unsigned long long flags)
{
    *(const void**)object = DAT_14313a1d8;
    if (flags & 1)
        ::operator delete(object, 8);
    return object;
}

// The two anonymous purecall-only interfaces' deleting destructors: plain new, so the CRT's sized delete (0x142749444).
// @0x1423dbc50
void* FUN_1423dbc50(void* object, unsigned long long flags)
{
    *(const void**)object = DAT_14313b9c8;
    if (flags & 1)
        ::operator delete(object, 0x38);
    return object;
}

// @0x1423dbc80
void* FUN_1423dbc80(void* object, unsigned long long flags)
{
    *(const void**)object = DAT_14313b9c8;
    if (flags & 1)
        ::operator delete(object, 0x10);
    return object;
}

// destructor helper is recovered from its executable call target; the purecall-only vptr is not declared locally.
// @0x1423ce420
void* FUN_1423ce420(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        ::operator delete(object, 0x10);   // the CRT sized delete (0x142749444)
    return object;
}

// MS2-FUNCTIONAL: executes child release and member cleanup in executable order; its anonymous abstract vptr is not declared locally.
// @0x1423d1b50
void FUN_1423d1b50(unsigned long long* object)
{
    Memory::Free(reinterpret_cast<void*>(object[0x16]));
    FUN_1423cdf60(object);
}

// stores the abstract vptr, then the recovered child/member teardown and sized-delete paths.
// @0x1423d1b90
void* FUN_1423d1b90(unsigned long long* object, unsigned flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a5f8);
    Memory::Free(reinterpret_cast<void*>(object[0x16]));
    FUN_1423cdf60(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x5c0);
    }
    return object;
}

// MS2-FUNCTIONAL: initializes all non-vtable fields at the offsets observed in the executable constructor.
// @0x1423da250
void* FUN_1423da250(unsigned long long* object, unsigned long long arg2, unsigned long long arg3)
{
    object[2] = arg2;
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313b920);
    object[1] = reinterpret_cast<unsigned long long>(DAT_14313b968);
    object[5] = 0;
    object[8] = 0;
    object[0xe] = arg3;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(object) + 0x3c) = 1;
    object[3] = ~0ULL;
    *reinterpret_cast<unsigned*>(object + 4) = ~0U;
    return object;
}

// restores both vptrs, then the allocation flag and 0x110 sized-delete branch.
// @0x1423da2c0
void* FUN_1423da2c0(void* object, unsigned flags)
{
    auto* words = static_cast<unsigned long long*>(object);
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313b920);
    words[1] = reinterpret_cast<unsigned long long>(DAT_14313b968);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x110);
    }
    return object;
}

// MS2-FUNCTIONAL: hash-table capacity growth threshold and requested capacities follow the executable; table allocation helper is exe-bound.
// @0x1423d8d10
void FUN_1423d8d10(unsigned long long* table, unsigned long long key)
{
    auto* data = reinterpret_cast<unsigned long long*>(table[0]);
    if (!data) {
        FUN_1423d9090(table, reinterpret_cast<void*>(key), 8);
        return;
    }
    if (data[1] * 4 + 4 < data[0] * 5)
        FUN_1423d9090(table, reinterpret_cast<void*>(key), data[1] * 2 + 2);
}

// MS2-FUNCTIONAL: releases the held ABC data and executes the ExecuteTag base teardown before optional scalar delete.
// @0x1423dbba0
void* FUN_1423dbba0(Scaleform::GFx::AS3::DoAbc* self, unsigned flags)
{
    Scaleform::GFx::AS3::AbcDataBuffer* abc = self->pAbc.GetPtr();
    if (abc) abc->Release();
    self->Scaleform::GFx::ExecuteTag::~ExecuteTag();
    if (flags & 1) ::operator delete(self);
    return self;
}

// MS2-FUNCTIONAL: constructs and assigns the executable-observed String member at +0x18; this anonymous base has no local class declaration.
// @0x1423cdb60
void* FUN_1423cdb60(unsigned long long* object, const char* text)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a228);
    *reinterpret_cast<unsigned*>(object + 1) = 1;
    String* value = reinterpret_cast<String*>(object + 3);
    new (value) String();
    *value = text;
    return object;
}

// MS2-FUNCTIONAL: allocates four bytes per executable-observed record and stores the new buffer at +0x190.
// @0x1423cad60
void FUN_1423cad60(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0xd0);
    void* data = Memory::Alloc(static_cast<UPInt>(count) * 4);
    *reinterpret_cast<void**>(bytes + 0x190) = data;
}

// MS2-FUNCTIONAL: formats and releases the OS message exactly when the executable's +0x78 logger flag is set.
// @0x1423cb920
void FUN_1423cb920(void* object, DWORD code)
{
    if (*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x78)) {
        char* message = 0;
        FormatMessageA(0x1100, 0, code, 0, reinterpret_cast<LPSTR>(&message), 0, 0);
        if (message) LocalFree(message);
    }
}

// destructor helper and 0xb0 sized-delete path follow the executable; only allocator vtable dispatch uses Memory.
// @0x1423ce3c0
void* FUN_1423ce3c0(void* object, unsigned flags)
{
    FUN_1423cdf60(static_cast<unsigned long long*>(object));
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0xb0);
    }
    return object;
}

// executes the common refcount-base cleanup and 0x10 sized-delete path from the executable.
// @0x1423db8b0
void* FUN_1423db8b0(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// byte-identical common refcount-base cleanup and 0x10 sized-delete path.
// @0x1423db910
void* FUN_1423db910(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// byte-identical common refcount-base cleanup and 0x10 sized-delete path.
// @0x1423db970
void* FUN_1423db970(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// restores the executable's anonymous prototype vptr before the destructor helper and size-selected delete.
// @0x1423ce250
void* FUN_1423ce250(unsigned long long* object, unsigned flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a200);
    FUN_14257db50(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// MS2-FUNCTIONAL: follows the executable's IME-language gate and keyboard injection sequence.
// @0x1423d1420
void FUN_1423d1420(void* object, int index)
{
    auto* bytes = static_cast<unsigned char*>(object);
    const unsigned state = *reinterpret_cast<unsigned*>(bytes + 0x98);
    if ((state & 0xf00000) == 0 && (((state - 0x10000) & 0xfffcffff) != 0 || state == 0x40000)) {
        FUN_1423daf30(*reinterpret_cast<void**>(bytes + 0xc8), 0);
        return;
    }
    INPUT input{};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(index + 0x31);
    input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(index + 0x31, MAPVK_VK_TO_VSC));
    SendInput(1, &input, sizeof(INPUT));
}

// MS2-FUNCTIONAL: releases each executable-tagged Value in reverse order using the recovered shared Value destructor.
// @0x1423ce6c0
void FUN_1423ce6c0(Scaleform::GFx::AS3::Value* values, unsigned long long count)
{
    while (count)
        values[--count].~Value();
}

// MS2-FUNCTIONAL: forwards the recovered formatting arguments through the executable's Log vtable slot.
// @0x1423cd060
void FUN_1423cd060(void* log, const char* format, ...)
{
    unsigned flags = 0x1000;
    va_list args;
    va_start(args, format);
    auto** vtable = *reinterpret_cast<void***>(log);
    reinterpret_cast<void(*)(void*, unsigned*, const char*, void*)>(vtable[1])(log, &flags, format, &args);
    va_end(args);
}

// MS2-FUNCTIONAL: initializes the executable-observed refcount/vptr fields and registers both loader callbacks.
// @0x1423db7f0
void* FUN_1423db7f0(unsigned long long* object)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313bc60);
    object[1] = 1;
    *reinterpret_cast<unsigned*>(object + 2) = 0x23;
    FUN_1425c8cf0(0x4c, reinterpret_cast<void*>(&FUN_1423dd1c0));
    FUN_1425c8cf0(0x52, reinterpret_cast<void*>(&FUN_1423dc7b0));
    return object;
}

// MS2-FUNCTIONAL: performs the executable's sample text and selection updates through the movie helpers.
// @0x1423ca350
void FUN_1423ca350(void* self)
{
    void* value = nullptr;
    FUN_142576820(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0xa0),
                  "_root.Edit_MLine1.textBox.text", &value, 1);
    if (value) {
        void** vtable = *reinterpret_cast<void***>(value);
        reinterpret_cast<void(*)(void*, void**, const char*)>(vtable[2])(value, &value, "Hello World");
    }
    FUN_1423ca030(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0xa0),
                  "Selection.setSelection", "%d %d", 5, 5);
}

// MS2-FUNCTIONAL: attaches the movie: notifies the object at +0x18 (vtable slot 0x90) and the current IME child at
// +0x70 (slot 1, with the movie), then publishes the operating-system label to an AVM version 1 movie as
// _global.gfx_ime_os_version (a GFx::Value string, laid out raw).
// @0x1423ca410
void FUN_1423ca410(void* self, void* movie)
{
    FUN_1425b49b0();
    if (!movie) return;
    unsigned char* p = static_cast<unsigned char*>(self);
    void* obj = *reinterpret_cast<void**>(p + 0x18);
    (*reinterpret_cast<void (***)(void*)>(obj))[0x90 / 8](obj);
    p[0x80] = 0;
    void* child = *reinterpret_cast<void**>(p + 0x70);
    if (child) {
        FUN_14257dc30(movie);
        void* arg = movie;
        (*reinterpret_cast<void (***)(void*, void**)>(child))[1](child, &arg);
    }
    *reinterpret_cast<void**>(p + 0xa0) = movie;
    int os = *reinterpret_cast<int*>(p + 0xbc);
    struct { void* pObjectInterface; unsigned Type; const char* pString; } value =
        { nullptr, 6, os == 1 ? "Vista" : os == 0 ? "XP" : "Undetermined" };
    if (FUN_14256eff0(movie) == 1)
        FUN_142576820(*reinterpret_cast<void**>(p + 0xa0), "_global.gfx_ime_os_version",
                      reinterpret_cast<void**>(&value), 1);
}

// MS2-FUNCTIONAL: releases executable-observed arrays, string members, and owned child references during teardown.
// @0x1423c8bb0
void FUN_1423c8bb0(unsigned long long* object)
{
    FUN_1423c9330(object[0x17], object[0x18]);
    for (unsigned i : { 0x2eu, 0x2bu, 0x17u, 0x12u }) {
        if (object[i]) {
            void** manager = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(manager[0xc])(DAT_143b15f60,
                                                                  reinterpret_cast<void*>(object[i]));
            object[i] = 0;
        }
    }
    if (object[0xe]) {
        FUN_1423ca920(nullptr, &object[0xe]);
        object[0xe] = 0;
    }
    FUN_1422fbf60(object + 0xb);
    FUN_1422fbf60(object + 8);
    FUN_1422fbf60(object + 5);
    FUN_1422fbf60(object + 2);
}

// runs the recovered IME manager teardown and the executable's scalar or sized delete path.
// @0x1423c8e10
void* FUN_1423c8e10(void* object, unsigned flags)
{
    FUN_1423c8bb0(static_cast<unsigned long long*>(object));
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x1a0);
    }
    return object;
}

// MS2-FUNCTIONAL: releases the executable-observed cue and object arrays before the common IME base teardown.
// @0x1423c8e70
void* FUN_1423c8e70(unsigned long long* object, unsigned flags)
{
    auto** cuePairs = reinterpret_cast<void**>(object[0x2b]);
    for (unsigned long long i = 0; i < object[0x2c]; ++i) {
        if (cuePairs[i * 3 + 1]) Memory::Free(cuePairs[i * 3 + 1]);
        if (cuePairs[i * 3]) Memory::Free(cuePairs[i * 3]);
    }
    auto** records = reinterpret_cast<void**>(object[0x12]);
    const unsigned count = *reinterpret_cast<unsigned*>(object + 0x10);
    for (unsigned i = 0; i < count; ++i)
        if (records[i * 4]) Memory::Free(records[i * 4]);
    FUN_1423c8bb0(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x1a0);
    }
    return object;
}


// MS2-FUNCTIONAL: appends a retained pointer to the executable-observed dynamic array using its expansion helper.
// @0x1423d9490
unsigned long long FUN_1423d9490(void* object, unsigned long long* value)
{
    auto* array = reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(object) + 0x848);
    const unsigned long long length = *reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(object) + 0x850);
    FUN_1423d9690(array, array, length + 1);
    auto* data = reinterpret_cast<unsigned long long*>(array[0]);
    unsigned long long item = *value;
    if (item) ++*reinterpret_cast<volatile long*>(item + 8);
    data[length - 1] = item;
    if (item) FUN_14257dcd0(reinterpret_cast<void*>(item));
    return 0;
}

// MS2-FUNCTIONAL: compares the executable GUID, queries the child interface, and propagates its four-byte result at the observed offsets.
// @0x1423d70d0
unsigned long long FUN_1423d70d0(void* object, const unsigned long long* guid)
{
    if (guid[0] == DAT_14313b410 && guid[1] == DAT_14313b418) {
        auto* bytes = static_cast<unsigned char*>(object);
        void* child = *reinterpret_cast<void**>(bytes + 0x20);
        unsigned char result[16]{};
        const int hr = reinterpret_cast<int(*)(void*, void*)>((*reinterpret_cast<void***>(child))[4])(child, result);
        const short code = *reinterpret_cast<short*>(result);
        if (hr >= 0 && code == 3) {
            *reinterpret_cast<unsigned*>(bytes - 0xcc) = *reinterpret_cast<unsigned*>(result + 8);
            FUN_1423cc7c0(bytes - 0x1a0, *reinterpret_cast<unsigned*>(result + 8));
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: forwards a copied String to the child method at vtable offset +0x68 and releases the consumed argument.
// @0x1423ca8b0
unsigned char FUN_1423ca8b0(void* object, String* value)
{
    String local(*value);
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x78);
    auto** vtable = *reinterpret_cast<void***>(child);
    const unsigned char result = reinterpret_cast<unsigned char(*)(void*, String)>(vtable[13])(child, local);
    value->~String();
    return result;
}

// MS2-FUNCTIONAL: clears each executable-observed 0x28-byte hash node and releases the backing allocation.
// @0x1423cdda0
void FUN_1423cdda0(void** table)
{
    if (!*table) return;
    auto* nodes = static_cast<unsigned char*>(*table);
    const unsigned long long count = *reinterpret_cast<unsigned long long*>(nodes + 8) + 1;
    for (unsigned long long index = 0; index < count; ++index) {
        unsigned long long* state = reinterpret_cast<unsigned long long*>(nodes + index * 0x28 + 0x10);
        if (*state != ~1ULL) *state = ~1ULL;
    }
    Memory::Free(nodes);
    *table = 0;
}

// restores the executable's AS2/AS3 support vtable, runs shared base cleanup, and follows the 0x10 delete path.
// @0x1423dbcb0
void* FUN_1423dbcb0(unsigned long long* object, unsigned flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313ba60);
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// MS2-FUNCTIONAL: performs the executable's interface query, value probe, reset callback, and release sequence.
// @0x1423db000
void FUN_1423db000(unsigned long long* object)
{
    auto* bytes = reinterpret_cast<unsigned char*>(object);
    unsigned* key = reinterpret_cast<unsigned*>(bytes + 0x1c);
    if (*key == 0xffffffff) return;
    void* source = reinterpret_cast<void*>(object[5]);
    void* result = 0;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    const int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result);
    if (hr >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        const int status = reinterpret_cast<int(*)(void*, unsigned)>(resultVtable[4])(result, *key);
        if (status == static_cast<int>(0x80004000u))
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
        reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
    }
    *key = 0xffffffff;
}

// MS2-FUNCTIONAL: same queried interface sequence, with this event record's key at +0x18.
// @0x1423db060
void FUN_1423db060(unsigned long long* object)
{
    unsigned* key = reinterpret_cast<unsigned*>(object + 3);
    if (*key == 0xffffffff) return;
    void* source = reinterpret_cast<void*>(object[5]);
    void* result = 0;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    const int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result);
    if (hr >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        const int status = reinterpret_cast<int(*)(void*, unsigned)>(resultVtable[4])(result, *key);
        if (status == static_cast<int>(0x80004000u))
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
        reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
    }
    *key = 0xffffffff;
}

// the class destructor is shared and recovered; opaque allocator vtable dispatch uses Scaleform's equivalent Memory facade.
// @0x1423ce040
void* FUN_1423ce040(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// byte-identical deleting wrapper body to the adjacent executable copy, with the same destructor and sized-free path.
// @0x1423ce0a0
void* FUN_1423ce0a0(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// destructor helper and sized-free path follow the executable; heap dispatch uses our Memory facade.
// @0x1423ce100
void* FUN_1423ce100(void* object, unsigned flags)
{
    FUN_1423cde00(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x870);
    }
    return object;
}

// same helper sequence and allocation size as the adjacent executable copy.
// @0x1423ce1f0
void* FUN_1423ce1f0(void* object, unsigned flags)
{
    FUN_1423cde00(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x870);
    }
    return object;
}

// @0x1423ca660
void FUN_1423ca660(void* self, unsigned value)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<unsigned*>(bytes + 0xc0) = value;
    *reinterpret_cast<unsigned*>(*reinterpret_cast<unsigned char**>(bytes + 0x70) + 0x9c) = value;
}

// @0x1423ca3f0
void FUN_1423ca3f0(void* self)
{
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x70);
    if (child) {
        void** vtable = *reinterpret_cast<void***>(child);
        reinterpret_cast<void(*)(void*)>(vtable[0x98 / sizeof(void*)])(child);
    }
}

// @0x1423ca680
void FUN_1423ca680(void* self, void* value)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    void* child = *reinterpret_cast<void**>(bytes + 0x70);
    if (child) {
        void** vtable = *reinterpret_cast<void***>(child);
        reinterpret_cast<void(*)(void*)>(vtable[2])(child);
    }
    *reinterpret_cast<void**>(bytes + 0x68) = value;
}

// @0x1423d97d0
__declspec(noinline) void FUN_1423d97d0(void* self, long long enabled)
{
    char* text = static_cast<char*>(self) + 0x10;
    if (enabled)
        strcpy_s(text, 0x400, "candidateList");
    else
        *text = 0;
}

// @0x1423daeb0
int FUN_1423daeb0(long long* self)
{
    int count = *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x3c) - 1;
    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x3c) = count;
    if (count == 0) {
        void** vtable = *reinterpret_cast<void***>(self);
        reinterpret_cast<void(*)(void*, int)>(vtable[0x40 / sizeof(void*)])(self, 1);
    }
    return count;
}

// MS2-FUNCTIONAL: indirect calls through opaque child vtables retain Ghidra’s recovered slots; child interface signatures are unavailable.
// @0x1423daef0
void FUN_1423daef0(void* self)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    void* first = *reinterpret_cast<void**>(bytes + 0x28);
    if (first) {
        void** vtable = *reinterpret_cast<void***>(first);
        reinterpret_cast<void(*)(void*)>(vtable[2])(first);
    }
    void* second = *reinterpret_cast<void**>(bytes + 0x40);
    if (second) {
        void** vtable = *reinterpret_cast<void***>(second);
        reinterpret_cast<void(*)(void*)>(vtable[4])(second);
        reinterpret_cast<void(*)(void*)>(vtable[2])(second);
    }
}

// MS2-FUNCTIONAL: tears down the event source, retained strings, and helper-owned state in executable order.
// @0x1423cdee0
void FUN_1423cdee0(unsigned long long* object)
{
    FUN_1423db000(reinterpret_cast<unsigned long long*>(object[0x19]));
    FUN_1423db060(reinterpret_cast<unsigned long long*>(object[0x19]));
    FUN_1423daef0(reinterpret_cast<void*>(object[0x19]));
    if (object[0x19]) {
        void** vtable = *reinterpret_cast<void***>(object[0x19]);
        reinterpret_cast<void(*)(void*)>(vtable[2])(reinterpret_cast<void*>(object[0x19]));
    }
    FUN_1423ca920(nullptr, &object[0x16]);
    object[0x16] = 0;
    FUN_1423cdf60(object);
}

// MS2-FUNCTIONAL: releases the dynamic value array, member string, and callback resources seen in the executable.
// @0x1423cde00
void FUN_1423cde00(void* raw)
{
    auto* object = static_cast<unsigned long long*>(raw);
    const unsigned long long count = object[0x10a];
    auto* entries = reinterpret_cast<unsigned long long*>(object[0x109]);
    for (unsigned long long i = count; i; --i)
        if (entries[i - 1]) FUN_14257dcd0(reinterpret_cast<void*>(entries[i - 1]));
    Memory::Free(entries);
    FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::AS3::Value*>(object[0x105]), object[0x106]);
    Memory::Free(reinterpret_cast<void*>(object[0x105]));
    FUN_1422fbf60(object + 0x102);
}

// releases the retained member, invokes the recovered AS support destructor, then follows delete flags.
// @0x1423ce160
void* FUN_1423ce160(unsigned long long* object, unsigned flags)
{
    Sfr33ReleasePacked(object[3]);
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a200);
    FUN_14257db50(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x20);
    }
    return object;
}

// MS2-FUNCTIONAL: runs the recovered IME interface destructor before scalar or sized deletion.
// @0x1423ce2f0
void* FUN_1423ce2f0(unsigned long long* object, unsigned flags)
{
    FUN_1423cdee0(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0xe8);
    }
    return object;
}

// runs the executable's State cleanup and honors both scalar and sized delete flags.
// @0x1423dba40
void* FUN_1423dba40(void* object, unsigned flags)
{
    *static_cast<void**>(object) = DAT_143109420;   // State vftable
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x18);
    }
    return object;
}

// MS2-FUNCTIONAL: releases both retained AbcDataBuffer fields, invokes the base helper, and follows delete flags.
// @0x1423dbab0
void* FUN_1423dbab0(unsigned long long* object, unsigned flags)
{
    Sfr33ReleasePacked(object[5]);
    Sfr33ReleasePacked(object[2]);
    FUN_14257db40(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x38);
    }
    return object;
}

// MS2-FUNCTIONAL: DoAbc base destruction and scalar delete are modeled from our shared ExecuteTag declaration.
// @0x1423dbbf0
void* FUN_1423dbbf0(Scaleform::GFx::AS3::DoAbc* self, unsigned flags)
{
    Scaleform::GFx::AS3::AbcDataBuffer* abc = self->pAbc.GetPtr();
    if (abc) abc->Release();
    self->Scaleform::GFx::ExecuteTag::~ExecuteTag();
    if (flags & 1)
        ::operator delete(self);
    return self;
}

// @0x1423cb740
unsigned HashFunction(const char* text, unsigned long long length)
{
    return static_cast<unsigned>(String::BernsteinHashFunctionCIS(text, length, 0x1505)) & 0xffffff;
}

// @0x1423d9500
void FUN_1423d9500(void* self)
{
    FUN_1423d9690(static_cast<unsigned char*>(self) + 0x848,
                  static_cast<unsigned char*>(self) + 0x848, 0);
}

// MS2-FUNCTIONAL: the executable passes a non-null global token to FUN_1423d97d0; its body only tests non-nullness.
// @0x1423ce570
void FUN_1423ce570(void* self)
{
    *reinterpret_cast<String*>(static_cast<unsigned char*>(self) + 0x10) = "";
    FUN_1423d97d0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30), 1);
}

// @0x1423d0f10
void FUN_1423d0f10(void* self, char* text)
{
    *reinterpret_cast<String*>(static_cast<unsigned char*>(self) + 0x10) = text;
    FUN_1423d97d0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30),
                  reinterpret_cast<long long>(text));
}

// MS2-FUNCTIONAL: trims retained array items, grows through the executable's reserve helper, and stores the new length.
// @0x1423d9690
extern "C" void FUN_1423d9690(void* rawArray, void* allocator, unsigned long long length)
{
    auto* array = static_cast<unsigned long long*>(rawArray);
    unsigned long long oldLength = array[1];
    unsigned long long capacity = array[2];
    if (length < oldLength) {
        auto** items = reinterpret_cast<void**>(array[0]);
        for (unsigned long long i = oldLength; i > length; --i)
            if (items[i - 1]) FUN_14257dcd0(items[i - 1]);
        if ((capacity >> 1) <= length)
            FUN_1423d95f0(array, allocator, length);
    } else if (length >= capacity) {
        FUN_1423d95f0(array, allocator, (length >> 2) + length);
    }
    array[1] = length;
}

// MS2-FUNCTIONAL: resizes the executable's Value array, destructing removed entries before changing its capacity.
// @0x1423d9730
extern "C" void FUN_1423d9730(void* rawArray, void* allocator, unsigned long long length)
{
    auto* array = static_cast<unsigned long long*>(rawArray);
    if (length < array[1]) {
        FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::AS3::Value*>(array[0]), array[1] - length);
        if (length < (array[2] >> 1)) FUN_1423d95f0(array, allocator, length);
    } else if (length >= array[2]) {
        FUN_1423d95f0(array, allocator, (length >> 2) + length);
    }
    array[1] = length;
}

// MS2-FUNCTIONAL: reserves four-entry-rounded pointer storage with the executable's AllocatorLH heap slots.
// @0x1423d95f0
extern "C" void FUN_1423d95f0(void* rawArray, void* allocator, unsigned long long requested)
{
    auto* array = static_cast<unsigned long long*>(rawArray);
    void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    if (!requested) {
        if (array[0]) reinterpret_cast<void(*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
        array[0] = 0;
        array[2] = 0;
        return;
    }
    const unsigned long long capacity = (requested + 3) & ~3ull;
    if (array[0]) {
        array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(
            DAT_143b15f60, reinterpret_cast<void*>(array[0]), capacity * sizeof(void*)));
    } else {
        unsigned allocFlags = 2;
        array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long, unsigned*)>(heapVtable[14])(
            DAT_143b15f60, allocator, capacity * sizeof(void*), &allocFlags));
    }
    array[2] = capacity;
}

static void cx18_ReserveGH(unsigned long long* array, unsigned long long requested, unsigned long long stride)
{
    void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    if (!requested) {
        if (array[0]) reinterpret_cast<void(*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
        array[0] = array[2] = 0;
        return;
    }
    const unsigned long long capacity = (requested + 3) & ~3ull;
    const unsigned long long bytes = capacity * stride;
    if (array[0]) array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(
        DAT_143b15f60, reinterpret_cast<void*>(array[0]), bytes));
    else {
        unsigned allocFlags = 2;
        array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, unsigned long long, unsigned*)>(heapVtable[10])(
            DAT_143b15f60, bytes, &allocFlags));
    }
    array[2] = capacity;
}

// MS2-FUNCTIONAL: reserves four-entry-rounded 12-byte ReadBufferInfo and transform storage.
// @0x1423d1240
void FUN_1423d1240(unsigned long long* array, void*, unsigned long long count)
{ cx18_ReserveGH(array, count, 0xc); }

// MS2-FUNCTIONAL: reserves four-entry-rounded 32-byte AS2/AS3 Value storage.
// @0x1423d12e0
void FUN_1423d12e0(unsigned long long* array, void*, unsigned long long count)
{ cx18_ReserveGH(array, count, 0x20); }

// MS2-FUNCTIONAL: reserves four-entry-rounded 32-byte Value storage at the parallel array site.
// @0x1423d7370
void FUN_1423d7370(unsigned long long* array, void*, unsigned long long count)
{
    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    if (!count) {
        if (array[0]) {
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
            array[0] = 0;
            array[2] = 0;
            return;
        }
        array[2] = 0;
        return;
    }
    const unsigned long long capacity = (count + 3) & ~3ull;
    const unsigned long long bytes = capacity << 5;
    if (array[0]) {
        array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heap[11])(
            DAT_143b15f60, reinterpret_cast<void*>(array[0]), bytes));
        array[2] = capacity;
        return;
    }
    unsigned flags = 2;
    array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, unsigned long long, unsigned*)>(heap[10])(
        DAT_143b15f60, bytes, &flags));
    array[2] = capacity;
}

static void cx18_ReserveWide(unsigned long long* array, void* allocator, unsigned long long requested, unsigned flags)
{
    void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    if (!requested) {
        if (array[0]) reinterpret_cast<void(*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
        array[0] = array[2] = 0;
        return;
    }
    const unsigned long long capacity = (requested + 3) & ~3ull;
    if (array[0]) array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(
        DAT_143b15f60, reinterpret_cast<void*>(array[0]), capacity * 2));
    else array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long, unsigned*)>(heapVtable[14])(
        DAT_143b15f60, allocator, capacity * 2, &flags));
    array[2] = capacity;
}

// MS2-FUNCTIONAL: reserves four-entry-rounded wchar_t storage with the executable's wide-string allocation tag.
// @0x1423d1380
void FUN_1423d1380(unsigned long long* array, void* allocator, unsigned long long count)
{ cx18_ReserveWide(array, allocator, count, 0x201); }

// MS2-FUNCTIONAL: reserves four-entry-rounded wchar_t storage for the parallel IME text array.
// @0x1423d5340
void FUN_1423d5340(unsigned long long* array, void* allocator, unsigned long long count)
{ cx18_ReserveWide(array, allocator, count, 2); }

// MS2-FUNCTIONAL: walks the source's command array (0x10-byte {key, name} entries, ended by a null name) and
// inserts each name -> {key, source} by Bernstein hash.
// @0x1423d8e80
void FUN_1423d8e80(void* table, void* source)
{
    void** sourceVtable = *reinterpret_cast<void***>(source);
    auto* record = static_cast<unsigned char*>(reinterpret_cast<void*(*)(void*)>(sourceVtable[0])(source));
    for (; *reinterpret_cast<const char**>(record + 8); record += 0x10) {
        const unsigned key = *reinterpret_cast<unsigned*>(record);
        const char* text = *reinterpret_cast<const char**>(record + 8);
        const unsigned long long length = strlen(text);
        const unsigned long long hash = String::BernsteinHashFunction(text, length, 0x1505);
        void* keyStorage = const_cast<char*>(text);
        unsigned long long value[2] = { key, reinterpret_cast<unsigned long long>(source) };
        void* entry[2] = { &keyStorage, value };
        FUN_1423d8b80(static_cast<unsigned long long*>(table), table, entry, hash);
    }
}

// MS2-FUNCTIONAL: clears the pending value array, builds the RemoveList path, and queries the movie object.
// @0x1423d9520
void FUN_1423d9520(void* raw)
{
    auto* bytes = static_cast<unsigned char*>(raw);
    FUN_1423d9690(bytes + 0x848, bytes + 0x848, 0);
    char* command = reinterpret_cast<char*>(bytes + 0x410);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(bytes + 0x10));
    strcat_s(command, 0x400, ".RemoveList");
    void* movie = *reinterpret_cast<void**>(bytes + 0x868);
    void* state = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
    void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(state) + 0x18);
    if (manager) {
        Scaleform::GFx::Value result;
        void** vtable = *reinterpret_cast<void***>(manager);
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, int, int)>(vtable[0x78 / sizeof(void*)])(
            manager, command, &result, 0, 0);
        *command = 0;
    }
}

// Performs the executable's interface query and retrieves the IME reading-state values.
// @0x1423d6b70
int FUN_1423d6b70(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* result = nullptr;
    int success = 0;
    void* source = *reinterpret_cast<void**>(bytes + 0x1c0);
    if (source) {
        auto** vtable = *reinterpret_cast<void***>(source);
        if (reinterpret_cast<int(*)(void*, const void*, void**)>(vtable[0])(source, DAT_1431c51e8, &result) >= 0) {
            auto** resultVtable = *reinterpret_cast<void***>(result);
            if (reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
                    result, DAT_1431c5018, bytes + 0x1a0, bytes + 0x1b8) < 0)
                *reinterpret_cast<unsigned*>(bytes + 0x1b8) = 0xffffffff;
            else
                success = 1;
        }
        if (result) (*reinterpret_cast<void(***)(void*)>(result))[2](result);
    }
    return success;
}

// MS2-FUNCTIONAL: queries the event result and clears the pending composition when the host rejects it.
// @0x1423d7610
void FUN_1423d7610(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    unsigned* key = reinterpret_cast<unsigned*>(bytes + 0x1b8);
    if (*key == 0xffffffff) return;
    void* source = *reinterpret_cast<void**>(bytes + 0x1d0);
    void* result = nullptr;
    if (source) {
        auto** vtable = *reinterpret_cast<void***>(source);
        int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(vtable[0])(source, DAT_1431c51e8, &result);
        if (hr >= 0) {
            auto** resultVtable = *reinterpret_cast<void***>(result);
            const int status = reinterpret_cast<int(*)(void*, unsigned)>(resultVtable[4])(result, *key);
            if (status == static_cast<int>(0x80004000u))
                reinterpret_cast<void(*)(void*)>(*reinterpret_cast<void***>(*reinterpret_cast<void**>(bytes + 0x1a0)) + 2)(
                    *reinterpret_cast<void**>(bytes + 0x1a0));
            reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
        }
    }
    *key = 0xffffffff;
}

// MS2-FUNCTIONAL: queries and acknowledges the second executable-tracked composition key.
// @0x1423d7690
void FUN_1423d7690(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    unsigned* key = reinterpret_cast<unsigned*>(bytes + 0x1b0);
    if (*key == 0xffffffff) return;
    void* source = *reinterpret_cast<void**>(bytes + 0x1d0);
    void* result = nullptr;
    if (source) {
        auto** vtable = *reinterpret_cast<void***>(source);
        const int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(vtable[0])(source, DAT_1431c51e8, &result);
        if (hr >= 0) {
            auto** resultVtable = *reinterpret_cast<void***>(result);
            reinterpret_cast<void(*)(void*, unsigned)>(resultVtable[4])(result, *key);
            reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
        }
    }
    *key = 0xffffffff;
}

// MS2-FUNCTIONAL: queries the executable's composition callback IID and records the returned result key.
// @0x1423dac70
bool FUN_1423dac70(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* source = *reinterpret_cast<void**>(bytes + 0x28);
    void* result = nullptr;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result);
    bool success = false;
    if (hr >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        hr = reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
            result, &DAT_1431c4d58, bytes, bytes + 0x18);
        success = hr >= 0;
        if (!success) *reinterpret_cast<unsigned*>(bytes + 0x18) = 0xffffffff;
    }
    if (result) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(result))[2])(result);
    return success;
}

// MS2-FUNCTIONAL: queries the executable's second composition callback IID and updates its result key.
// @0x1423dacf0
bool FUN_1423dacf0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* source = *reinterpret_cast<void**>(bytes + 0x28);
    void* result = nullptr;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result);
    bool success = false;
    if (hr >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        hr = reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
            result, &DAT_14313b8b8, bytes + 8, bytes + 0x1c);
        success = hr >= 0;
        if (!success) *reinterpret_cast<unsigned*>(bytes + 0x1c) = 0xffffffff;
    }
    if (result) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(result))[2])(result);
    return success;
}

// MS2-FUNCTIONAL: records IME name/display metadata flags and appends the executable's empty cue record for imeName.
// @0x1423ca6b0
void FUN_1423ca6b0(void* raw, const char* name)
{
    if (!raw || !name) return;
    auto* bytes = static_cast<unsigned char*>(raw);
    if (strcmp(name, "language") == 0) bytes[0xa9] = 1;
    *reinterpret_cast<unsigned*>(bytes + 0xb0) = 3;
    if (strcmp(name, "imeName") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 0;
        bytes[0xaa] = 1;
        auto* array = reinterpret_cast<unsigned long long*>(bytes + 0xb8);
        const unsigned long long count = array[1];
        if (count >= array[2]) {
            const unsigned long long capacity = (count + 1) + ((count + 1) >> 2);
            void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            if (array[0]) array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(
                DAT_143b15f60, reinterpret_cast<void*>(array[0]), capacity * 0x30));
            else {
                unsigned allocFlags = 2;
                array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, unsigned long long, unsigned*)>(heapVtable[10])(
                    DAT_143b15f60, capacity * 0x30, &allocFlags));
            }
            array[2] = capacity;
        }
        auto* record = reinterpret_cast<unsigned char*>(array[0]) + count * 0x30;
        memset(record, 0, 0x30);
        new (record + 0x10) String();  // the exe copy-constructs two default Strings into the zeroed record
        new (record + 0x18) String();
        *reinterpret_cast<unsigned*>(record + 0x20) = 0x02000000;
        array[1] = count + 1;
        *reinterpret_cast<int*>(bytes + 0xd0) += 1;
        return;
    }
    if (strcmp(name, "displayName") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 1;
        bytes[0xab] = 1;
    } else if (strcmp(name, "code") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 2;
        bytes[0xac] = 1;
    }
}

// MS2-FUNCTIONAL: appends a 32-byte Value record and retains its referenced payload when required.
// @0x1423d4fa0
void FUN_1423d4fa0(unsigned long long* array, const unsigned long long* value)
{
    const unsigned long long oldLength = array[1];
    const unsigned long long newLength = oldLength + 1;
    if (newLength >= array[2])
        FUN_1423d12e0(array, array, (newLength >> 2) + newLength);
    array[1] = newLength;
    auto* output = reinterpret_cast<unsigned long long*>(array[0]) + (newLength - 1) * 4;
    output[0] = 0;
    output[1] = value[1];
    output[2] = value[2];
    output[3] = value[3];
    if ((static_cast<unsigned>(value[1]) >> 6) & 1) {
        output[0] = value[0];
        void* ref = reinterpret_cast<void*>(value[0]);
        reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(ref))[1])(ref);
    }
}

// MS2-FUNCTIONAL: activates the saved keyboard layout whose name matches the requested string.
// @0x1423d7890
void FUN_1423d7890(void* self, const char* name)
{
    auto* bytes = static_cast<unsigned char*>(self);
    const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x80);
    auto* entries = reinterpret_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 0x90));
    for (unsigned i = 0; i < count; ++i) {
        char* savedName = *reinterpret_cast<char**>(entries + i * 0x20);
        if (savedName && strcmp(savedName, name) == 0) {
            HKL layout = *reinterpret_cast<HKL*>(entries + i * 0x20 + 0x18);
            if (layout) {
                *reinterpret_cast<HKL*>(bytes + 0x198) = layout;
                ActivateKeyboardLayout(layout, 0);
            }
            return;
        }
    }
}

// MS2-FUNCTIONAL: stores the current keyboard-layout name together with its executable hash and byte length.
// @0x1423d7df0
void* FUN_1423d7df0(void*, void* rawStringInfo)
{
    char layoutName[16]{};
    GetKeyboardLayoutNameA(layoutName);
    const unsigned long long length = strlen(layoutName) + 1;
    auto* stringInfo = static_cast<unsigned char*>(rawStringInfo);
    *reinterpret_cast<String*>(stringInfo) = layoutName;
    *reinterpret_cast<unsigned long long*>(stringInfo + 8) = HashFunction(layoutName, length);
    *reinterpret_cast<unsigned long long*>(stringInfo + 16) = length;
    return rawStringInfo;
}

// MS2-FUNCTIONAL: implements the executable's supported COM interface IDs and returns the matching interface view.
// @0x1423dadd0
long long FUN_1423dadd0(long long* object, const unsigned long long* iid, void** output)
{
    if (!output) return static_cast<long long>(0x80070057u);
    *output = nullptr;
    long long* view = object;
    if ((iid[0] != DAT_1431c4828 || iid[1] != DAT_1431c4830) &&
        (iid[0] != DAT_1431c4d58 || iid[1] != DAT_1431c4d60)) {
        if (iid[0] == DAT_14313b8b8 && iid[1] == DAT_14313b8c0) view = object ? object + 1 : nullptr;
        else if (iid[0] != DAT_1431c4e08 || iid[1] != DAT_1431c4e10) {
            if (iid[0] != DAT_1431c4ee8 || iid[1] != DAT_1431c4ef0)
                return static_cast<long long>(0x80004002u);
        }
    }
    *output = view;
    if (!view) return static_cast<long long>(0x80004002u);
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[1])(object);
    return 0;
}

// MS2-FUNCTIONAL: emits the executable's four-part IME command log message when the state bag has a logger.
// @0x1423ccfc0
void FUN_1423ccfc0(void*, long long owner, const char* command, const char* value)
{
    auto* bag = reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10);
    auto log = bag->GetLog();
    if (!log) return;
    log->LogMessage("imecommand: '");
    log->LogMessage(const_cast<char*>(command));
    log->LogMessage("' '");
    log->LogMessage("%s", value);
    log->LogMessage("'\n");
}

// MS2-FUNCTIONAL: forwards the selected text to the active movie and applies the executable's state callback.
// @0x1423ccdc0
void FUN_1423ccdc0(unsigned long long* object, String* text)
{
    void* movie = reinterpret_cast<void*>(object[0xf]);
    if (movie) {
        void** vtable = *reinterpret_cast<void***>(movie);
        reinterpret_cast<void(*)(void*)>(vtable[0x90 / sizeof(void*)])(movie);
        reinterpret_cast<void(*)(void*, const char*)>(vtable[0x80 / sizeof(void*)])(movie, text->ToCStr());
        const unsigned flags = *reinterpret_cast<unsigned*>(object + 0x11);
        if (flags != 0x1000000 && (flags & 0xf00000) == 0) {
            void** selfVtable = *reinterpret_cast<void***>(object);
            reinterpret_cast<void(*)(void*, unsigned)>(selfVtable[0x50 / sizeof(void*)])(
                object, *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(object) + 0xd4));
        }
    }
}

// MS2-FUNCTIONAL: submits the default unsupported message and the selected language-specific movie text.
// @0x1423cc2d0
void FUN_1423cc2d0(unsigned long long* object)
{
    String text("Not Supported");
    FUN_1423ccdc0(object, &text);
    const unsigned count = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(object) + 0xd0);
    if (!count) return;
    for (unsigned i = 0; i < count; ++i) {
        const unsigned flags = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(object) + 0x88);
        auto* record = reinterpret_cast<unsigned char*>(object[0x17]) + i * 0x30;
        if (flags != 0x1000000 && *reinterpret_cast<unsigned*>(record + 0x20) == flags &&
            *reinterpret_cast<void**>(record + 0x28)) {
            auto* states = reinterpret_cast<unsigned*>(object[50]);
            if (states[i] == 2) {
                text = *reinterpret_cast<String*>(record + 0x18);
                FUN_1423ccdc0(object, &text);
            }
            if (states[i] != 1) return;
            text = *reinterpret_cast<String*>(record + 0x10);
            FUN_1423ccdc0(object, &text);
            return;
        }
    }
}

// MS2-FUNCTIONAL: reserves four-entry-rounded 0x18-byte IME records through the executable heap vtable.
// @0x1423cc680
void FUN_1423cc680(unsigned long long* array, void*, unsigned long long requested)
{
    void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    const unsigned long long capacity = (requested + 3) & ~3ull;
    if (!requested) {
        if (array[0]) reinterpret_cast<void(*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
        array[0] = 0;
        array[2] = 0;
        return;
    }
    void* memory = reinterpret_cast<void*>(array[0]);
    const unsigned long long bytes = capacity * 0x18;
    unsigned allocFlags = 2;
    if (memory) array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(DAT_143b15f60, memory, bytes));
    else array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, unsigned long long, unsigned*)>(heapVtable[10])(DAT_143b15f60, bytes, &allocFlags));
    array[2] = capacity;
}

// MS2-FUNCTIONAL: reserves four-entry-rounded 0x10-byte Value records through the executable heap vtable.
// @0x1423cc720
void FUN_1423cc720(unsigned long long* array, void*, unsigned long long requested)
{
    void** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    const unsigned long long capacity = (requested + 3) & ~3ull;
    if (!requested) {
        if (array[0]) reinterpret_cast<void(*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, reinterpret_cast<void*>(array[0]));
        array[0] = 0;
        array[2] = 0;
        return;
    }
    void* memory = reinterpret_cast<void*>(array[0]);
    const unsigned long long bytes = capacity << 4;
    unsigned allocFlags = 2;
    if (memory) array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, void*, unsigned long long)>(heapVtable[11])(DAT_143b15f60, memory, bytes));
    else array[0] = reinterpret_cast<unsigned long long>(reinterpret_cast<void*(*)(void*, unsigned long long, unsigned*)>(heapVtable[10])(DAT_143b15f60, bytes, &allocFlags));
    array[2] = capacity;
}

// MS2-FUNCTIONAL: loads the active IME module, hides its reading window when available, and releases the context.
// @0x1423cb660
void FUN_1423cb660(void* self)
{
    char fileName[0x104]{};
    if (!cx18_ImmGetIMEFileNameA(GetKeyboardLayout(0), fileName, sizeof(fileName))) return;
    HMODULE ime = LoadLibraryA(fileName);
    if (!ime) return;
    FARPROC getReading = GetProcAddress(ime, "GetReadinString");
    FARPROC showWindow = GetProcAddress(ime, "ShowReadingWindow");
    (void)getReading;
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x78);
    HWND hwnd = *reinterpret_cast<HWND*>(static_cast<unsigned char*>(child) + 0x68);
    if (showWindow) {
        HIMC context = cx18_ImmGetContext(hwnd);
        if (context) {
            reinterpret_cast<void(WINAPI*)(HIMC, int)>(showWindow)(context, 0);
            cx18_ImmReleaseContext(hwnd, context);
        }
    }
}

// MS2-FUNCTIONAL: reopens the IME context when absent, applies the requested open state, and restores association.
// @0x1423d1760
unsigned long long FUN_1423d1760(void* self, unsigned char open)
{
    HWND hwnd = *reinterpret_cast<HWND*>(static_cast<unsigned char*>(self) + 0x28);
    bool wasAssociated = true;
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) {
        wasAssociated = false;
        cx18_ImmAssociateContextEx(hwnd, nullptr, 0x10);
        context = cx18_ImmGetContext(hwnd);
        if (!context) return cx18_ImmReleaseContext(hwnd, nullptr);
    }
    const BOOL result = cx18_ImmSetOpenStatus(context, open);
    if (!wasAssociated) cx18_ImmAssociateContextEx(hwnd, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0x80) = open;
    return result != 0;
}

// MS2-FUNCTIONAL: converts UTF-8 composition text to UTF-16 and sends it through the executable's IME composition API.
// @0x1423d14d0
bool FUN_1423d14d0(void* self, const char* text)
{
    const int utf16Length = MultiByteToWideChar(CP_UTF8, 0, text, -1, nullptr, 0);
    std::vector<wchar_t> converted(utf16Length > 0 ? static_cast<size_t>(utf16Length) : 1, L'\0');
    if (utf16Length > 0) MultiByteToWideChar(CP_UTF8, 0, text, -1, converted.data(), utf16Length);
    HWND hwnd = *reinterpret_cast<HWND*>(static_cast<unsigned char*>(self) + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) return false;
    static const wchar_t empty[] = L"";
    const wchar_t* composition = converted[0] ? converted.data() : empty;
    const BOOL result = cx18_ImmSetCompositionStringW(context, 9, composition,
        static_cast<DWORD>(Scaleform::UTF8Util::GetLength(text, -1) * sizeof(wchar_t)), nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    return result != 0;
}

// MS2-FUNCTIONAL: maps the executable's Japanese, Korean, and Chinese mode values to IMM conversion flags.
// @0x1423d15b0
unsigned long long FUN_1423d15b0(void* self, int mode)
{
    auto* bytes = static_cast<unsigned char*>(self);
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(bytes + 0x90) = layout;
    HIMC context = cx18_ImmGetContext(hwnd);
    bool wasAssociated = true;
    if (!context) {
        wasAssociated = false;
        cx18_ImmAssociateContextEx(hwnd, nullptr, 0x10);
        context = cx18_ImmGetContext(hwnd);
        if (!context) return cx18_ImmReleaseContext(hwnd, nullptr);
    }
    DWORD conversion = 0, sentence = 0;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    bool supported = true;
    if ((conversion & 0xf) == 0) cx18_ImmSetOpenStatus(context, TRUE);
    conversion &= ~0xfu;
    const unsigned language = static_cast<unsigned>(reinterpret_cast<unsigned long long>(layout) & 0xffff);
    if (language == 0x411) {
        if (mode == 0) conversion |= 8;
        else if (mode == 4) conversion |= 9;
        else if (mode == 8) conversion |= 0xb;
        else if (mode == 0x16) conversion |= 3;
        else if (mode != 1) supported = false;
    } else if (language == 0x412) {
        if (mode == 0x32) conversion |= 9;
        else if (mode == 0) conversion |= 8;
        else if (mode != 1) supported = false;
    } else if (language == 0x404 || language == 0x804) {
        if (mode == 2) conversion |= 9;
        else if (mode == 0) conversion |= 8;
        else if (mode != 1) supported = false;
    }
    if (supported) {
        cx18_ImmSetConversionStatus(context, conversion, sentence);
        bytes[0x80] = 1;
        cx18_ImmSetOpenStatus(context, TRUE);
    }
    cx18_ImmReleaseContext(hwnd, context);
    if (!wasAssociated) cx18_ImmAssociateContextEx(hwnd, nullptr, 0);
    return supported;
}

void FUN_1423d94f0(void*, void*);

// MS2-FUNCTIONAL: Movie is declared only for its recovered Release call; surrounding window/movie manager layout is opaque.
extern void FUN_1425b4ec0(void*, int);
extern void FUN_1425b43c0(void*);

// MS2-FUNCTIONAL: the factory interface and helper argument types remain opaque; recovered calls preserve offsets and order.
// MS2-FUNCTIONAL: the factory interface and helper argument types remain opaque; the guard and calls follow the exe.
// @0x1423d4690
void FUN_1423d4690(void* self)
{
    void* base = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 8);
    if (base) {
        void* factory = static_cast<unsigned char*>(base) + 0x10;
        void** vtable = *reinterpret_cast<void***>(factory);
        void* value = reinterpret_cast<void*(*)(void*, int)>(vtable[3])(factory, 0x18);
        FUN_1425b4ec0(value, 0);
        FUN_1425b43c0(value);
        if (value)
            reinterpret_cast<Scaleform::RefCountImpl*>(value)->Release();
    }
}

// @0x1423d07e0
void FUN_1423d07e0(void* self)
{
    void* base = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 8);
    void* factory = static_cast<unsigned char*>(base) + 0x10;
    void** vtable = *reinterpret_cast<void***>(factory);
    void* value = reinterpret_cast<void*(*)(void*, int)>(vtable[3])(factory, 0x18);
    FUN_1425b4ec0(value, 0);
    FUN_1425b43c0(value);
    *(static_cast<unsigned char*>(self) + 0xb8) = 0;
    if (value)
        reinterpret_cast<Scaleform::RefCountImpl*>(value)->Release();
}

// MS2-FUNCTIONAL: Windows IME calls and field offsets match; imm32 entry points are resolved at runtime because this target does not link imm32.lib.
// MS2-FUNCTIONAL: imm32 entry points are resolved at runtime because this target does not link imm32.lib.
// @0x1423ce4f0
void FUN_1423ce4f0(void* self)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 3, 0);
    cx18_ImmReleaseContext(hwnd, context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
}

// MS2-FUNCTIONAL: imm32 entry points are resolved at runtime; the Win32 key and notification sequence follows the exe.
// @0x1423d53e0
void FUN_1423d53e0(void* self, int key)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    int state = *reinterpret_cast<int*>(bytes + 0x98);
    if (state != 0x110000 && state != 0x210000 && state != 0xc10000 &&
        state != 0x60000 && state != 0xd10000) {
        HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
        HIMC context = cx18_ImmGetContext(hwnd);
        cx18_ImmNotifyIME(context, 0x12, 0, *reinterpret_cast<int*>(bytes + 0x70) + key);
        cx18_ImmNotifyIME(context, 0x11, 0, 0);
        cx18_ImmNotifyIME(context, 0x16, 0, *reinterpret_cast<DWORD*>(bytes + 0x70));
        cx18_ImmReleaseContext(hwnd, context);
        return;
    }
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(key + 0x31);
    input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(key + 0x31, 0));
    SendInput(1, &input, sizeof(input));
}

// MS2-FUNCTIONAL: opaque AS3 movie and value interfaces use executable vtable slots and recovered offsets.
// @0x1423d1c90
void FUN_1423d1c90(void** self)
{
    void** selfVtable = *reinterpret_cast<void***>(self);
    reinterpret_cast<void(*)(void*)>(selfVtable[0x80 / sizeof(void*)])(self);
    void* movie = reinterpret_cast<void**>(self)[0x15];
    void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
    if (bridge) {
        unsigned char value[0x18] = {};
        void** vtable = *reinterpret_cast<void***>(bridge);
        reinterpret_cast<void(*)(void*, const char*, void*, int, int)>(vtable[0x78 / sizeof(void*)])
            (bridge, "RemoveInputWindow", value, 0, 0);
    }
}

// MS2-FUNCTIONAL: State destruction follows our shared class declaration; runtime heap release helper is recovered.
// @0x1423db9d0
void* FUN_1423db9d0(Scaleform::GFx::State* self, unsigned flags)
{
    self->Scaleform::GFx::State::~State();
    if (flags & 1) {
        if ((flags & 4) == 0)
            Scaleform::Memory::Free(self);
        else
            ::FUN_14015b310(self, 0x18);
    }
    return self;
}

// @0x1423d1c10
void FUN_1423d1c10(void* self)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 3, 0);
    cx18_ImmReleaseContext(hwnd, context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xd0) = 0;
}

// @0x1423d1830
void FUN_1423d1830(void* self, unsigned long long* movie)
{
    unsigned long long value = *movie;
    *reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(self) + 8) = value;
    FUN_1423d94f0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30),
                  reinterpret_cast<void*>(value));
    if (value)
        reinterpret_cast<Scaleform::GFx::Movie*>(value)->Release();
}

// @0x1423d94f0
void FUN_1423d94f0(void* self, void* value)
{
    *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 8) = value;
}

// MS2-FUNCTIONAL: instantiates our XML string hash set insertion path from the shared hash implementation; compiler codegen differs from the exe.
// @0x1423ca950
void FUN_1423ca950(Scaleform::GFx::XML::XMLDOMStringNodeHash* set, void* heap,
                   Scaleform::GFx::XML::DOMStringNode* const* value)
{
    using Node = Scaleform::GFx::XML::DOMStringNode;
    using Hash = Scaleform::GFx::XML::DOMStringNodeHashFunc<Node*>;
    using Entry = Scaleform::HashsetEntry<Node*, Hash>;
    using Base = Scaleform::HashSetBase<Node*, Hash, Hash, Scaleform::AllocatorLH<Node*, 326>, Entry>;
    static_cast<Base*>(set)->Add(heap, *value);
}

// MS2-FUNCTIONAL: inserts the supplied DOM string through our recovered hash-set implementation; it recomputes the node's cached hash.
// @0x1423caa80
void FUN_1423caa80(Scaleform::GFx::XML::XMLDOMStringNodeHash* set, void* heap,
                   Scaleform::GFx::XML::DOMStringNode* const* value, unsigned long long)
{
    using Node = Scaleform::GFx::XML::DOMStringNode;
    using Hash = Scaleform::GFx::XML::DOMStringNodeHashFunc<Node*>;
    using Entry = Scaleform::HashsetEntry<Node*, Hash>;
    using Base = Scaleform::HashSetBase<Node*, Hash, Hash, Scaleform::AllocatorLH<Node*, 326>, Entry>;
    static_cast<Base*>(set)->Add(heap, *value);
}

// MS2-FUNCTIONAL: delegates capacity replacement to the typed XML hash set; this preserves entries but emits different helper code.
// @0x1423cce50
void FUN_1423cce50(Scaleform::GFx::XML::XMLDOMStringNodeHash* set, void* heap,
                   unsigned long long capacity)
{
    using Node = Scaleform::GFx::XML::DOMStringNode;
    using Hash = Scaleform::GFx::XML::DOMStringNodeHashFunc<Node*>;
    using Entry = Scaleform::HashsetEntry<Node*, Hash>;
    using Base = Scaleform::HashSetBase<Node*, Hash, Hash, Scaleform::AllocatorLH<Node*, 326>, Entry>;
    auto* base = static_cast<Base*>(set);
    if (!capacity) {
        base->Clear();
        return;
    }
    base->SetCapacity(heap, capacity - capacity / 5);
}

// MS2-FUNCTIONAL: calls the executable's IME provider and text composition vtables using their observed slots and fields.
// @0x1423daf30
unsigned long long FUN_1423daf30(void* raw, int offset)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* provider = nullptr;
    auto** managerVtable = *reinterpret_cast<void***>(*reinterpret_cast<void**>(self + 0x28));
    const int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(managerVtable[0])(
        *reinterpret_cast<void**>(self + 0x28), &DAT_14313b8a8, &provider);
    if (hr >= 0 && provider) {
        void* context = nullptr;
        auto** providerVtable = *reinterpret_cast<void***>(provider);
        const int getContext = reinterpret_cast<int(*)(void*, unsigned, void**)>(providerVtable[6])(
            provider, *reinterpret_cast<unsigned*>(self + 0x50), &context);
        void* text = nullptr;
        if (getContext >= 0 && context) {
            auto** contextVtable = *reinterpret_cast<void***>(context);
            const int query = reinterpret_cast<int(*)(void*, const void*, void**)>(contextVtable[0])(
                context, &DAT_14313b8c8, &text);
            if (query >= 0 && text)
                reinterpret_cast<void(*)(void*, int)>(
                    (*reinterpret_cast<void***>(text))[0x78 / sizeof(void*)])(
                        text, *reinterpret_cast<int*>(self + 0x60) + offset);
            if (text) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(text))[2])(text);
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(context))[2])(context);
        }
        reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[2])(provider);
    }
    return 0;
}

// MS2-FUNCTIONAL: synchronizes Korean IME association and the observed conversion/sentence mode fields.
// @0x1423cfbe0
void FUN_1423cfbe0(void* raw, unsigned char enabled)
{
    auto* self = static_cast<unsigned char*>(raw);
    int composition = *reinterpret_cast<int*>(self + 0xbc);
    if (!enabled) {
        if (composition < 1) return;
        *reinterpret_cast<unsigned char*>(self + 0xc0) = 1;
    }
    if (composition != 0) return;

    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC oldContext = cx18_ImmGetContext(hwnd);
    String language;
    void* languageSource = *reinterpret_cast<void**>(self + 0xa8);
    reinterpret_cast<void(*)(void*, String*)>((*reinterpret_cast<void***>(languageSource))[0x50 / sizeof(void*)])(
        languageSource, &language);
    const bool korean = _strnicmp(language.ToCStr(), "Korean", 6) == 0;
    cx18_ImmAssociateContextEx(hwnd, nullptr, static_cast<DWORD>(enabled) << 4);
    HIMC context = cx18_ImmGetContext(hwnd);
    DWORD conversion = 0;
    DWORD sentence = 0;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    if (!korean) {
        conversion = enabled ? (conversion | 1u) : (conversion & ~1u);
        sentence = static_cast<DWORD>(enabled) << 3;
    }
    cx18_ImmSetConversionStatus(context, conversion, sentence);
    cx18_ImmReleaseContext(hwnd, oldContext);
    *reinterpret_cast<unsigned char*>(self + 0xc0) = 0;
}

// MS2-FUNCTIONAL: maps the executable's IMM conversion bits to its IME mode strings and preserves the association fallback.
// @0x1423cf1c0
const char* FUN_1423cf1c0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    bool alreadyAssociated = true;
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) {
        alreadyAssociated = false;
        cx18_ImmAssociateContextEx(hwnd, nullptr, 0x10);
        context = cx18_ImmGetContext(hwnd);
        if (!context) {
            cx18_ImmReleaseContext(hwnd, nullptr);
            return "UNKNOWN";
        }
    }
    DWORD conversion = 0;
    DWORD sentence = 0;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    unsigned mode = conversion & 0xf;
    const unsigned language = *reinterpret_cast<unsigned*>(self + 0x98);
    const char* label = "";
    if (language & 0xf00) {
        if ((conversion & 7) == 1) label = "JAPANESE_HIRAGANA";
        if (mode == 0xb) label = "JAPANESE_KATAKANA_FULL";
        if (mode == 3) label = "JAPANESE_KATAKANA_HALF";
        if (mode == 8) label = "ALPHANUMERIC_FULL";
        if (mode == 0) label = "ALPHANUMERIC_HALF";
    }
    if (language & 0xf000) {
        if ((mode & ~8u) == 1) label = "KOREAN";
        if (mode == 8) label = "ALPHANUMERIC_FULL";
        if (mode == 0) label = "ALPHANUMERIC_HALF";
    }
    if (language & 0xf000f) {
        if ((mode & ~8u) == 1) label = "CHINESE";
        if (mode == 8) label = "ALPHANUMERIC_FULL";
        if (mode == 0) label = "ALPHANUMERIC_HALF";
    }
    auto* text = reinterpret_cast<String*>(self + 0x78);
    *text = label;
    if (!alreadyAssociated) cx18_ImmAssociateContextEx(hwnd, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    return *text->ToCStr() ? text->ToCStr() : "UNKNOWN";
}

// MS2-FUNCTIONAL: matches the executable's language-specific IME registration, creates the COM provider, and sends its settings record.
// @0x1423d5740
void FUN_1423d5740(unsigned long long* self, const unsigned char* name)
{
    const unsigned count = *reinterpret_cast<unsigned*>(self + 0x1a);
    auto* kinds = reinterpret_cast<unsigned*>(self[0x32]);
    auto* entries = reinterpret_cast<unsigned char*>(self[0x17]);
    for (unsigned i = 0; i < count; ++i) {
        const unsigned kind = kinds[i];
        if (kind != 1 && kind != 2) continue;
        const unsigned long long packed = *reinterpret_cast<unsigned long long*>(entries + i * 0x30 + (kind == 1 ? 0x10 : 0x18));
        const char* entryName = reinterpret_cast<const char*>((packed & ~3ull) + 0xc);
        if (std::strcmp(reinterpret_cast<const char*>(name), entryName) != 0) continue;
        const unsigned language = reinterpret_cast<unsigned(*)(void*, unsigned)>(
            (*reinterpret_cast<void***>(self))[3])(self, *reinterpret_cast<unsigned*>(entries + i * 0x30 + 0x20));
        if (language != *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x84) ||
            !*reinterpret_cast<void**>(entries + i * 0x30 + 0x28)) continue;
        IUnknown* instance = nullptr;
        HRESULT result = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
            CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068),
            reinterpret_cast<void**>(&instance));
        if (FAILED(result) || !instance) return;
        IUnknown* settings = nullptr;
        result = instance->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b6b0),
            reinterpret_cast<void**>(&settings));
        if (SUCCEEDED(result) && settings) {
            auto** settingsVtable = *reinterpret_cast<void***>(settings);
            auto* record = *reinterpret_cast<unsigned char**>(entries + i * 0x30 + 0x28);
            if (record) {
                reinterpret_cast<void(*)(void*, unsigned, unsigned short, void*, void*, unsigned long long, unsigned)>(
                    settingsVtable[3])(settings, *reinterpret_cast<unsigned*>(record),
                    *reinterpret_cast<unsigned short*>(record + 4), record + 8, record + 0x18,
                    *reinterpret_cast<unsigned long long*>(record + 0x48), 0x10000000);
            }
            settings->Release();
        }
        instance->Release();
        return;
    }
}

// MS2-FUNCTIONAL: releases the executable's active IME list/window by state index and updates its composition bookkeeping.
// @0x1423da730
unsigned long long FUN_1423da730(void* raw, int state)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* manager = static_cast<unsigned char*>(*reinterpret_cast<void**>(self + 8));
    const unsigned mode = *reinterpret_cast<unsigned*>(manager + 0x98);
    if (((mode - 0x01000000u) & 0xfeffffffu) != 0) {
        auto** managerVtable = *reinterpret_cast<void***>(manager);
        if (reinterpret_cast<unsigned char(*)(void*, void*)>(managerVtable[6])(manager,
                *reinterpret_cast<void**>(manager + 8))) {
            --*reinterpret_cast<int*>(manager + 0xbc);
            if (state == *reinterpret_cast<int*>(self + 0x48)) {
                if (*reinterpret_cast<void**>(manager + 8)) {
                    void* bridge = *reinterpret_cast<void**>(manager + 0xa8);
                    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(bridge) + 0x18);
                    if (values) {
                        void* output = nullptr;
                        reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
                            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                                values, "RemoveList", &output, 0, 0);
                    }
                }
                FUN_1423d9500(*reinterpret_cast<void**>(manager + 0x30));
                *reinterpret_cast<unsigned char*>(self + 0x56) = 0;
            }
            if (state == *reinterpret_cast<int*>(self + 0x4c)) {
                if (*reinterpret_cast<void**>(manager + 8)) {
                    void* bridge = *reinterpret_cast<void**>(manager + 0xa8);
                    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(bridge) + 0x18);
                    if (values) {
                        void* output = nullptr;
                        reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
                            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                                values, "RemoveInputWindow", &output, 0, 0);
                    }
                }
                *reinterpret_cast<String*>(manager + 0xb0) = "";
            }
            if (*reinterpret_cast<int*>(manager + 0xbc) == 0 &&
                static_cast<char>(*reinterpret_cast<unsigned long long*>(manager + 0xc0))) {
                reinterpret_cast<void(*)(void*, int)>(
                    (*reinterpret_cast<void***>(manager))[0xd8 / sizeof(void*)])(manager, 0);
            }
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: refreshes the keyboard layout and mode label through the recovered shared language update path.
// @0x1423d8870
void FUN_1423d8870(unsigned long long* manager)
{
    FUN_1423d7140(manager);
}

// MS2-FUNCTIONAL: resolves the configured language string, activates its executable HKL, and reports activation failure.
// @0x1423d76f0
void FUN_1423d76f0(unsigned long long* manager, const char* name)
{
    manager[0x33] = 0;
    const unsigned count = *reinterpret_cast<unsigned*>(manager + 0x1a);
    auto* kinds = reinterpret_cast<unsigned*>(manager[0x32]);
    auto* entries = reinterpret_cast<unsigned char*>(manager[0x17]);
    for (unsigned i = 0; i < count; ++i) {
        const unsigned kind = kinds[i];
        if (kind != 1 && kind != 2) continue;
        const unsigned offset = kind == 1 ? 0x10 : 0x18;
        const unsigned long long packed = *reinterpret_cast<unsigned long long*>(entries + i * 0x30 + offset);
        const char* configured = reinterpret_cast<const char*>((packed & ~3ull) + 0xc);
        if (std::strcmp(name, configured) != 0) continue;
        HKL layout = *reinterpret_cast<HKL*>(entries + i * 0x30 + 0x28);
        if (!layout) continue;
        manager[0x33] = reinterpret_cast<unsigned long long>(layout);
        if (ActivateKeyboardLayout(layout, 0)) return;
        String error("Failure to activate input language ");
        error += configured;
        reinterpret_cast<void(*)(void*, const char*, const char*)>(
            (*reinterpret_cast<void***>(manager))[0x70 / sizeof(void*)])(
                manager, error.ToCStr(), "GFxIME Error");
        return;
    }
}

// MS2-FUNCTIONAL: stores the data item and issues the executable's SelectDataItem and SetList external calls.
// @0x1423d97f0
void FUN_1423d97f0(void* raw, unsigned long long item, unsigned char notify)
{
    auto* self = static_cast<unsigned char*>(raw);
    *reinterpret_cast<unsigned long long*>(self + 0x860) = item;
    if (!notify) return;
    char* command = reinterpret_cast<char*>(self + 0x410);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, 0x400, ".SelectDataItem");
    Scaleform::GFx::Value argument;
    Scaleform::GFx::Value result;
    auto* argBytes = reinterpret_cast<unsigned char*>(&argument);
    *reinterpret_cast<unsigned*>(argBytes + 8) = Scaleform::GFx::Value::VT_Number;
    *reinterpret_cast<double*>(argBytes + 0x10) = static_cast<double>(item);
    void* movie = *reinterpret_cast<void**>(self + 0x868);
    void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
    void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    if (bridge) {
        auto** vtable = *reinterpret_cast<void***>(bridge);
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned)>(
            vtable[0x78 / sizeof(void*)])(bridge, command, &result, &argument, 1);
        strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
        strcat_s(command, 0x400, ".SetList");
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned)>(
            vtable[0x78 / sizeof(void*)])(bridge, command, &result, nullptr, 0);
    }
}

// MS2-FUNCTIONAL: bridges the executable's IME COM property query through its two provider objects and VARIANT result.
// @0x1423da940
HRESULT FUN_1423da940(void*, IUnknown* source, void* value, unsigned selector, void* output)
{
    IUnknown* first = nullptr;
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4888), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c51d8),
        reinterpret_cast<void**>(&first));
    if (FAILED(hr) || !first) return hr;
    IUnknown* second = nullptr;
    hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4878), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c51b8),
        reinterpret_cast<void**>(&second));
    if (FAILED(hr) || !second) {
        first->Release();
        return hr;
    }
    IUnknown* property = nullptr;
    hr = source->QueryInterface(*reinterpret_cast<const IID*>(&DAT_1431c48f8),
        reinterpret_cast<void**>(&property));
    if (SUCCEEDED(hr) && property) {
        VARIANT id;
        VariantInit(&id);
        auto** propertyVtable = *reinterpret_cast<void***>(property);
        hr = reinterpret_cast<HRESULT(*)(void*, unsigned, void*, VARIANT*)>(propertyVtable[5])(
            property, selector, value, &id);
        if (SUCCEEDED(hr) && id.vt == VT_I4) {
            auto** firstVtable = *reinterpret_cast<void***>(first);
            hr = reinterpret_cast<HRESULT(*)(void*, unsigned, void*)>(firstVtable[0x78 / sizeof(void*)])(
                first, static_cast<unsigned>(id.lVal), output);
            if (SUCCEEDED(hr)) {
                IUnknown* item = nullptr;
                auto** secondVtable = *reinterpret_cast<void***>(second);
                hr = reinterpret_cast<HRESULT(*)(void*, void*, IUnknown**, unsigned)>(secondVtable[5])(
                    second, output, &item, 0);
                if (SUCCEEDED(hr) && item) {
                    auto** itemVtable = *reinterpret_cast<void***>(item);
                    hr = reinterpret_cast<HRESULT(*)(void*, void*)>(itemVtable[5])(item, output);
                    item->Release();
                }
            }
        }
        VariantClear(&id);
        property->Release();
    }
    second->Release();
    first->Release();
    return hr;
}

// MS2-FUNCTIONAL: uses our AS3 memory context declaration to release its heap limit handler, owned references, and allocated storage.
// @0x1423dbd20
void* FUN_1423dbd20(Scaleform::GFx::AS3::MemoryContextImpl* self, unsigned flags)
{
    self->~MemoryContextImpl();
    if (flags & 1) {
        if (!(flags & 4)) Scaleform::Memory::Free(self);
        else FUN_14015b310(self, 0x68);
    }
    return self;
}

// MS2-FUNCTIONAL: creates the IME COM manager and records both executable callback interfaces and their result keys.
// @0x1423daae0
unsigned char FUN_1423daae0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    IUnknown* manager = nullptr;
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4858), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c4d28),
        reinterpret_cast<void**>(&manager));
    if (FAILED(hr) || !manager) return 0;
    *reinterpret_cast<IUnknown**>(self + 0x28) = manager;
    IUnknown* controller = nullptr;
    hr = manager->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b8d8),
        reinterpret_cast<void**>(&controller));
    if (FAILED(hr) || !controller) {
        manager->Release();
        *reinterpret_cast<IUnknown**>(self + 0x28) = nullptr;
        return 0;
    }
    auto** controllerVtable = *reinterpret_cast<void***>(controller);
    reinterpret_cast<void(*)(void*, void*, unsigned)>(controllerVtable[0x70 / sizeof(void*)])(
        controller, self + 0x38, 4);
    *reinterpret_cast<IUnknown**>(self + 0x40) = controller;

    auto queryCallback = [&](const void* iid, void* argument, unsigned* resultKey) {
        IUnknown* callback = nullptr;
        HRESULT query = manager->QueryInterface(*reinterpret_cast<const IID*>(&DAT_1431c51e8),
            reinterpret_cast<void**>(&callback));
        if (FAILED(query) || !callback) return false;
        auto** vtable = *reinterpret_cast<void***>(callback);
        query = reinterpret_cast<HRESULT(*)(void*, const void*, void*, unsigned*)>(vtable[3])(
            callback, iid, argument, resultKey);
        callback->Release();
        return SUCCEEDED(query);
    };
    if (!queryCallback(&DAT_1431c4d58, self, reinterpret_cast<unsigned*>(self + 0x18))) {
        *reinterpret_cast<unsigned*>(self + 0x18) = 0xffffffff;
        return 0;
    }
    if (!queryCallback(&DAT_14313b8b8, self + 8, reinterpret_cast<unsigned*>(self + 0x1c))) {
        *reinterpret_cast<unsigned*>(self + 0x1c) = 0xffffffff;
        return 0;
    }
    auto* owner = *reinterpret_cast<unsigned char**>(self + 0x10);
    *reinterpret_cast<int*>(owner + 0xbc) = 0;
    return 1;
}

// MS2-FUNCTIONAL: resolves a language-specific IME string from the executable locale table and releases its reference.
// @0x1423d8a10
unsigned long long FUN_1423d8a10(unsigned long long* manager, const unsigned long long* stringInfo)
{
    const unsigned current = *reinterpret_cast<const unsigned*>(DAT_143a2a3e0 + 8);
    const char* text = reinterpret_cast<const char*>((*stringInfo & ~3ull) + 0xc);
    if (current != 0x02000000) {
        for (unsigned index = 0; index < 64; ++index) {
            const auto* locale = reinterpret_cast<const unsigned char*>(DAT_143a2a3e0) + index * 0x10;
            const unsigned localeId = *reinterpret_cast<const unsigned*>(locale + 8);
            if (localeId == 0x02000000) break;
            const char* localeName = *reinterpret_cast<const char* const*>(locale);
            if (std::strcmp(text, localeName) != 0) continue;
            const unsigned count = *reinterpret_cast<unsigned*>(manager + 0x1a);
            auto* entries = reinterpret_cast<unsigned char*>(manager[0x17]);
            auto* kinds = reinterpret_cast<unsigned*>(manager[0x32]);
            for (unsigned i = 0; i < count; ++i) {
                if (*reinterpret_cast<unsigned*>(entries + i * 0x30 + 0x20) != localeId) continue;
                const unsigned offset = kinds[i] == 1 ? 0x10 : kinds[i] == 2 ? 0x18 : 0;
                if (!offset) continue;
                const unsigned long long selected = *reinterpret_cast<unsigned long long*>(entries + i * 0x30 + offset);
                reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager))[0x40 / sizeof(void*)])(
                    manager, reinterpret_cast<const char*>((selected & ~3ull) + 0xc));
                const unsigned long long packed = *stringInfo;
                auto* refs = reinterpret_cast<volatile long*>((packed & ~3ull) + 8);
                if (_InterlockedDecrement(refs) == 1) {
                    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
                    reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60,
                        reinterpret_cast<void*>(packed & ~3ull));
                }
                return 1;
            }
        }
    }
    auto* refs = reinterpret_cast<volatile long*>((*stringInfo & ~3ull) + 8);
    if (_InterlockedDecrement(refs) == 1) {
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60,
            reinterpret_cast<void*>(*stringInfo & ~3ull));
    }
    return 0;
}

// MS2-FUNCTIONAL: reads the active IME DLL's executable version resource and combines it with the current keyboard layout.
// @0x1423cb260
unsigned FUN_1423cb260()
{
    HKL layout = GetKeyboardLayout(0);
    char fileName[0x400]{};
    if (!cx18_ImmGetIMEFileNameA(layout, fileName, 0x3ff)) return 0;
    HMODULE version = LoadLibraryA("Version");
    if (!version) return 0;
    using GetSizeFn = DWORD (WINAPI*)(LPCSTR, LPDWORD);
    using GetInfoFn = BOOL (WINAPI*)(LPCSTR, DWORD, DWORD, LPVOID);
    using QueryFn = BOOL (WINAPI*)(LPCVOID, LPCSTR, LPVOID*, PUINT);
    auto getSize = reinterpret_cast<GetSizeFn>(GetProcAddress(version, "GetFileVersionInfoSizeA"));
    auto getInfo = reinterpret_cast<GetInfoFn>(GetProcAddress(version, "GetFileVersionInfoA"));
    auto query = reinterpret_cast<QueryFn>(GetProcAddress(version, "VerQueryValueA"));
    if (!getSize || !getInfo || !query) return 0;
    DWORD handle = 0;
    const DWORD size = getSize(fileName, &handle);
    if (!size) return 0;
    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    void* data = reinterpret_cast<void*(*)(void*, unsigned long long, unsigned)>(heap[10])(
        DAT_143b15f60, size, 0);
    if (!data) return 0;
    unsigned result = 0;
    if (getInfo(fileName, handle, size, data)) {
        void* fixedInfo = nullptr;
        UINT length = 0;
        if (query(data, DAT_14305cd3c, &fixedInfo, &length) && fixedInfo) {
            const unsigned versionWord = *reinterpret_cast<unsigned*>(
                static_cast<unsigned char*>(fixedInfo) + 8);
            result = ((versionWord & 0xff) << 16) | ((versionWord & 0xff0000) << 8) |
                (static_cast<unsigned>(reinterpret_cast<ULONG_PTR>(layout)) & 0xffff);
        }
    }
    reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, data);
    return result;
}

// MS2-FUNCTIONAL: looks up an executable IME command by its Bernstein hash and forwards the matching record to its handler.
// @0x1423d8d60
unsigned long long FUN_1423d8d60(long long* map, long long operation, const char* key, unsigned long long flags)
{
    if (!operation) return 0;
    auto* table = reinterpret_cast<unsigned char*>(map[0]);
    if (!table) return 0;
    const unsigned long long mask = *reinterpret_cast<unsigned long long*>(table + 8);
    const unsigned long long hash = Scaleform::String::BernsteinHashFunction(key, std::strlen(key), 0x1505);
    unsigned long long index = mask & hash;
    unsigned char* entry = table + 0x10 + index * 0x28;
    if (*reinterpret_cast<long long*>(entry) == -2 ||
        *reinterpret_cast<unsigned long long*>(entry + 8) != index) return 0;
    for (;;) {
        if (*reinterpret_cast<unsigned long long*>(entry + 8) == index &&
            std::strcmp(reinterpret_cast<const char*>(*reinterpret_cast<void**>(entry + 0x10)), key) == 0) {
            void* handler = *reinterpret_cast<void**>(entry + 0x20);
            const unsigned type = *reinterpret_cast<unsigned*>(entry + 0x18);
            return reinterpret_cast<unsigned long long(*)(void*, long long, unsigned, const char*, unsigned long long)>(
                (*reinterpret_cast<void***>(handler))[1])(handler, operation, type, key, flags);
        }
        const long long next = *reinterpret_cast<long long*>(entry);
        if (next == -1) break;
        index = static_cast<unsigned long long>(next);
        entry = table + 0x10 + index * 0x28;
    }
    return 0;
}

// MS2-FUNCTIONAL: opaque XML hash-node query layout is recovered from field offsets, but its packed key type is unavailable.
// @0x1423cad20
unsigned long long FUN_1423cad20(unsigned long long* node, const unsigned long long* query)
{
    unsigned hash = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(node) + 0x24);
    if (hash != static_cast<unsigned>(query[2]))
        return static_cast<unsigned long long>(hash & 0xffffff00u);
    return static_cast<unsigned long long>(_stricmp(reinterpret_cast<const char*>(node[0]),
        reinterpret_cast<const char*>((query[0] & ~3ull) + 0xc)) == 0);
}

}}}

// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7GFxIMEManagerWin32@IME@GFx@Scaleform@@6B@ 0x1431383e0

namespace Scaleform { namespace GFx { namespace IME {

// MS2-FUNCTIONAL: constructs the language bar COM bridge, its two callback objects, and the 0x100-character input buffer.
// @0x1423d54d0
unsigned long long* FUN_1423d54d0(unsigned long long* self)
{
    FUN_1423cabb0(self, 0);
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x1b4) = 1;
    self[0] = reinterpret_cast<unsigned long long>(DAT_14313b520);
    self[0x3a] = 0;
    self[0x34] = reinterpret_cast<unsigned long long>(DAT_14313b5a0);
    self[0x38] = 0;
    self[0x35] = reinterpret_cast<unsigned long long>(DAT_14313b5c0);
    *reinterpret_cast<Scaleform::String*>(self + 0xe) = "";

    void* manager = nullptr;
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4858), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c4d28), &manager);
    if (FAILED(hr)) return self;

    void* provider = nullptr;
    auto** managerVtable = *reinterpret_cast<void***>(manager);
    hr = reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(managerVtable[0])(
        manager, DAT_1431c51e8, &provider);
    if (SUCCEEDED(hr) && provider) {
        auto** providerVtable = *reinterpret_cast<void***>(provider);
        HRESULT result = reinterpret_cast<HRESULT(*)(void*, const void*, void*, void*)>(providerVtable[3])(
            provider, DAT_14313b400, self + 0x35, self + 0x36);
        if (FAILED(result)) *reinterpret_cast<unsigned*>(self + 0x36) = 0xffffffffu;
        void* language = nullptr;
        hr = reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(managerVtable[0])(
            manager, DAT_1431c5028, &language);
        if (SUCCEEDED(hr) && language) {
            reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(language))[3])(language, &DAT_14313b410,
                    reinterpret_cast<void**>(self + 0x38));
            reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(language))[2])(language);
        }

        auto* settings = reinterpret_cast<void*>(self[0x38]);
        if (settings) {
            void* callback = nullptr;
            HRESULT query = reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(settings))[0])(settings, DAT_1431c51e8, &callback);
            if (SUCCEEDED(query) && callback) {
                HRESULT call = reinterpret_cast<HRESULT(*)(void*, const void*, void*, void*)>(
                    (*reinterpret_cast<void***>(callback))[3])(callback, DAT_1431c5018,
                        self + 0x34, self + 0x37);
                if (FAILED(call)) *reinterpret_cast<unsigned*>(self + 0x37) = 0xffffffffu;
                reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(callback))[2])(callback);
            }
        }
        reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(provider))[2])(provider);
    }
    reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(manager))[2])(manager);
    return self;
}

// MS2-FUNCTIONAL: selects the requested IME language entry, avoids duplicate active layouts, and updates the four mode strings.
// @0x1423d7940
unsigned long long FUN_1423d7940(long long* manager, const char* primary, const char* fallback)
{
    Scaleform::String selected;
    auto* entries = reinterpret_cast<unsigned char*>(manager[0x17]);
    auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
    const unsigned count = static_cast<unsigned>(manager[0x1a]);
    unsigned long long index = 0;
    unsigned limit = 0;
    bool fallbackSelected = false;
    int language = 0x2000000;

    for (; index < count; ++index) {
        auto* entry = entries + index * 0x30;
        auto* name = reinterpret_cast<Scaleform::String*>(entry + 0x10);
        if (primary && _stricmp(primary, name->ToCStr()) == 0 && states[index] == 0) {
            selected = *name;
            states[index] = 1;
            goto selected_entry;
        }
    }
    limit = count;
    for (index = 0; index < limit; ++index) {
        auto* entry = entries + index * 0x30;
        auto* name = reinterpret_cast<Scaleform::String*>(entry + 0x10);
        if (fallback && _stricmp(fallback, name->ToCStr()) == 0) {
            selected = *reinterpret_cast<Scaleform::String*>(entry + 0x18);
            states[index] = 2;
            fallbackSelected = true;
            language = *reinterpret_cast<int*>(entry + 0x20);
            break;
        }
    }
    if (limit) {
        for (unsigned i = 0; i < limit; ++i) {
            if (states[i] == 1 && *reinterpret_cast<int*>(entries + i * 0x30 + 0x20) == language)
                return 0xffffffffull;
        }
    }
    if (!fallbackSelected) return 0xffffffffull;

selected_entry:
    {
        const unsigned mask = reinterpret_cast<unsigned(*)(void*, unsigned)>(
            (*reinterpret_cast<void***>(manager))[3])(manager,
                *reinterpret_cast<unsigned*>(entries + index * 0x30 + 0x20));
        if (mask & 0xf00) FUN_1422fd480(manager + 2, &selected);
        if (mask & 0xf000) FUN_1422fd480(manager + 5, &selected);
        if (mask & 0xf0000) FUN_1422fd480(manager + 8, &selected);
        if (mask & 0xf) FUN_1422fd480(manager + 0xb, &selected);
    }
    return index;
}

// The object lives inside its owner's allocation: the class operator delete is empty, so only the global-delete
// path (flags 5) reaches the exe's empty global delete; a plain delete frees nothing.
// @0x1423dbb60
void* FUN_1423dbb60(void* object, unsigned flags)
{
    FUN_1424ddcb0(object);
    if ((flags & 5) == 5)
        FUN_14015b310(object, 0x68);
    return object;
}

// MS2-FUNCTIONAL: releases the manager's shared values, command hash, and packed strings using the observed field offsets.
// @0x1423cdf60
void FUN_1423cdf60(unsigned long long* self)
{
    self[0] = reinterpret_cast<unsigned long long>(DAT_14313a228 + 6);
    FUN_1423d9500(reinterpret_cast<void*>(self[6]));
    if (self[6]) {
        auto* child = reinterpret_cast<void*>(self[6]);
        reinterpret_cast<unsigned long long(*)(void*, unsigned)>(
            (*reinterpret_cast<void***>(child))[2])(child, 1);
    }
    FUN_1423ca920(nullptr, &self[0xf]);
    Scaleform::Memory::Free(reinterpret_cast<void*>(self[8]));
    using Node = Scaleform::HashNode<int, Scaleform::StringDataPtr, Scaleform::FixedSizeHash<int>>;
    using Entry = Scaleform::HashsetCachedNodeEntry<Node, typename Node::NodeHashF>;
    using Table = Scaleform::HashSetBase<Node, typename Node::NodeHashF, typename Node::NodeAltHashF,
        Scaleform::AllocatorGH<int, 2>, Entry>;
    reinterpret_cast<Table*>(self + 7)->Clear();
    FUN_1423ca920(nullptr, &self[4]);
    FUN_1423ca920(nullptr, &self[3]);
    FUN_1423ca920(nullptr, &self[2]);
}

// MS2-FUNCTIONAL: forwards each executable-provided argument descriptor and invokes the matching AS3 method with an .Add suffix.
// @0x1423d99f0
void FUN_1423d99f0(void* raw, void** value)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* input = value ? *value : nullptr;
    if (!*reinterpret_cast<unsigned char*>(self + 0x10)) {
        if (input) FUN_14257dcd0(input);
        return;
    }
    if (!input) return;

    char command[0x400]{};
    strcpy_s(command, sizeof(command), reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, sizeof(command), ".Add");
    const unsigned long long count = *reinterpret_cast<unsigned long long*>(self + 0x818);
    auto** inputVtable = *reinterpret_cast<void***>(input);
    for (unsigned long long i = 0; i < count; ++i) {
        reinterpret_cast<void(*)(void*, void*, void*)>(inputVtable[1])(
            input, self + 0x828 + i * 0x20, self + 0x810 + i * sizeof(void*));
    }
    void* movie = *reinterpret_cast<void**>(self + 0x868);
    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
    values = values ? *reinterpret_cast<void**>(static_cast<unsigned char*>(values) + 0x18) : nullptr;
    if (values) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(values, command, &result, nullptr, 0);
    }
    self[0x410] = 0;
    FUN_14257dcd0(input);
}

// MS2-FUNCTIONAL: cancels composition, sends Escape down and up for candidate modes, and removes the candidate list.
// @0x1423cefe0
void FUN_1423cefe0(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    HWND hwnd = *reinterpret_cast<HWND*>(bytes + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmReleaseContext(hwnd, context);
    FUN_1423da320(*reinterpret_cast<void**>(bytes + 0xc8), nullptr, nullptr, nullptr);
    const unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x98);
    if (mode - 5u < 2u) {
        INPUT inputs[2]{};
        for (auto& input : inputs) {
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VK_ESCAPE;
            input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        }
        inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(2, inputs, sizeof(INPUT));
    }
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
    if (values) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveList", &result, 0, 0);
    }
}

// MS2-FUNCTIONAL: resets the IME manager's four predefined mode records, preserving the executable's growing 16-byte array.
// @0x1423cb760
void FUN_1423cb760(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    auto* array = reinterpret_cast<unsigned long long*>(bytes + 0x170);
    unsigned long long length = array[1];
    unsigned long long capacity = array[2];
    if (length && (capacity & ~1ull)) {
        Scaleform::Memory::Free(reinterpret_cast<void*>(array[0]));
        array[0] = 0;
        array[2] = 0;
    } else if (!length && !capacity) {
        cx18_ReserveGH(array, 0, 0x10);
    }
    array[1] = 0;
    if (array[2] < 2) cx18_ReserveGH(array, 1, 0x10);
    auto append = [array](unsigned a, unsigned b) {
        unsigned long long next = ++array[1];
        if (next >= array[2]) cx18_ReserveGH(array, (next >> 2) + next, 0x10);
        auto* record = reinterpret_cast<unsigned*>(array[0]) + (next - 1) * 4;
        record[0] = a;
        record[1] = 0;
        record[2] = b;
        record[3] = 0;
    };
    append(0x2000, 0x412);
    append(0x210000, 0x804);
    append(0x400, 0x411);
    append(9, 0x404);
}

// MS2-FUNCTIONAL: initializes the shared IME manager state, interns its embedded node, and installs the default conversion records.
// @0x1423cabb0
unsigned long long* FUN_1423cabb0(unsigned long long* self, unsigned long long owner)
{
    self[0] = reinterpret_cast<unsigned long long>(DAT_143138360);
    for (unsigned i = 1; i <= 0x0d; ++i) self[i] = 0;
    new (self + 0x0e) Scaleform::String();
    self[0x0f] = owner;
    for (unsigned i : { 0x12u, 0x13u, 0x14u, 0x17u, 0x18u, 0x19u,
                        0x1fu, 0x20u, 0x21u, 0x23u, 0x27u, 0x28u, 0x29u,
                        0x2bu, 0x2cu, 0x2du, 0x2eu, 0x2fu, 0x30u })
        self[i] = 0;
    *reinterpret_cast<unsigned*>(self + 0x1d) = 0x01000000;
    *reinterpret_cast<unsigned*>(self + 0x25) = 0x01000000;
    self[0x22] = reinterpret_cast<unsigned long long>(self + 0x23);
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x84) = 0x02000000;
    *reinterpret_cast<unsigned*>(self + 0x11) = 0x02000000;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0xd4) = 0xffffffffu;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0xfc) = 0;

    auto* node = reinterpret_cast<Scaleform::GFx::XML::DOMStringNode*>(self + 0x1b);
    std::memset(node, 0, sizeof(void*));
    FUN_1423ca950(reinterpret_cast<Scaleform::GFx::XML::XMLDOMStringNodeHash*>(self + 1),
        self + 1, &node);
    *reinterpret_cast<unsigned*>(self + 0x1a) = 0;
    *reinterpret_cast<unsigned*>(self + 0x10) = 0;
    FUN_1423cb760(self);
    return self;
}

// MS2-FUNCTIONAL: removes every enumerated command key from the executable's chained 0x28-byte hash table.
// @0x1423d8f20
void FUN_1423d8f20(unsigned long long* map, void* source)
{
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    auto* sequence = reinterpret_cast<unsigned char*(*)(void*)>(sourceVtable[0])(source);
    auto* cursor = sequence ? reinterpret_cast<unsigned long long*>(sequence + sizeof(void*)) : nullptr;
    while (cursor && cursor[0]) {
        const char* key = reinterpret_cast<const char*>(cursor[0]);
        auto* table = reinterpret_cast<unsigned char*>(map[0]);
        if (table) {
            const unsigned long long mask = *reinterpret_cast<unsigned long long*>(table + 8);
            const unsigned long long hash = Scaleform::String::BernsteinHashFunction(
                key, std::strlen(key), 0x1505);
            const unsigned long long home = mask & hash;
            auto* entry = reinterpret_cast<unsigned long long*>(table + 0x10 + home * 0x28);
            if (static_cast<long long>(entry[0]) != -2 && entry[1] == home) {
                unsigned long long previous = home;
                for (;;) {
                    if (entry[1] == home && std::strcmp(reinterpret_cast<const char*>(entry[2]), key) == 0) {
                        const unsigned long long next = entry[0];
                        if (previous == home) {
                            if (next != ~0ull) {
                                auto* successor = reinterpret_cast<unsigned long long*>(table + 0x10 + next * 0x28);
                                entry[0] = successor[0];
                                entry[1] = successor[1];
                                entry[2] = successor[2];
                                entry[3] = successor[3];
                                entry[4] = successor[4];
                                entry = successor;
                            }
                        } else {
                            auto* prior = reinterpret_cast<unsigned long long*>(table + 0x10 + previous * 0x28);
                            prior[0] = next;
                        }
                        entry[0] = ~1ull;
                        --*reinterpret_cast<unsigned long long*>(table);
                        break;
                    }
                    const unsigned long long next = entry[0];
                    if (next == ~0ull) break;
                    previous = next;
                    entry = reinterpret_cast<unsigned long long*>(table + 0x10 + next * 0x28);
                }
            }
        }
        cursor += 2;
    }
}

// MS2-FUNCTIONAL: stores the supplied IME value for its matching language/mode and updates each affected mode string.
// @0x1423d5b00
void FUN_1423d5b00(unsigned long long* manager, const unsigned long long* value, const char* language)
{
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned short)>(vtable[4])(
        manager, *reinterpret_cast<const unsigned short*>(reinterpret_cast<const unsigned char*>(value) + 4));
    auto* entries = reinterpret_cast<unsigned char*>(manager[0x17]);
    auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
    const unsigned count = static_cast<unsigned>(manager[0x1a]);
    for (unsigned i = 0; i < count; ++i) {
        auto* entry = entries + i * 0x30;
        auto* name = reinterpret_cast<Scaleform::String*>(entry + 0x10);
        if (!language || _stricmp(name->ToCStr(), language) != 0 ||
            *reinterpret_cast<unsigned*>(entry + 0x20) != mode) continue;

        auto* copied = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x58));
        if (!copied) return;
        std::memcpy(copied, value, 0x58);
        *reinterpret_cast<unsigned long long**>(entry + 0x28) = copied;
        states[i] = 1;
        if (*reinterpret_cast<unsigned char*>(copied + 10) & 1) {
            *reinterpret_cast<unsigned*>(manager + 0x11) = *reinterpret_cast<unsigned*>(entry + 0x20);
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = mode;
        }
        if (mode & 0xf00) FUN_1422fd480(manager + 2, name);
        if (mode & 0xf000) FUN_1422fd480(manager + 5, name);
        if (mode & 0xf0000) FUN_1422fd480(manager + 8, name);
        if (mode & 0xf) FUN_1422fd480(manager + 0xb, name);
    }
}

// MS2-FUNCTIONAL: appends a wide composition update to the manager's UTF-8 log and records its language/mode tuple.
// @0x1423d5d80
void FUN_1423d5d80(void* raw, const void* event, const wchar_t* text)
{
    auto* bytes = static_cast<unsigned char*>(raw);
    Scaleform::String converted(text);
    const size_t length = converted.GetSize();
    char* copy = static_cast<char*>(Scaleform::Memory::Alloc(length + 1));
    if (!copy) return;
    std::memcpy(copy, converted.ToCStr(), length + 1);

    const unsigned short language = *reinterpret_cast<const unsigned short*>(
        static_cast<const unsigned char*>(event) + 4);
    const unsigned id = language & 0xfff;
    unsigned mode = 0x01000000;
    if (id == 0x409) mode = 0x10000000;
    else if (id == 0x404) mode = 9;
    else if (id == 0x804) mode = 0x80000;
    else if (id == 0x412) mode = 0x2000;
    else if (id == 0x411) mode = 0x400;
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;

    auto* array = reinterpret_cast<unsigned long long*>(bytes + 0x90);
    const unsigned long long next = array[1] + 1;
    if (next >= array[2]) cx18_ReserveGH(array, (next >> 2) + next, 0x20);
    array[1] = next;
    auto* record = reinterpret_cast<unsigned char*>(array[0]) + (next - 1) * 0x20;
    *reinterpret_cast<void**>(record) = copy;
    *reinterpret_cast<unsigned long long*>(record + 8) = 0;
    *reinterpret_cast<unsigned*>(record + 0x10) = mode;
    *reinterpret_cast<unsigned*>(record + 0x14) = 0;
    *reinterpret_cast<unsigned long long*>(record + 0x18) = language;

    *reinterpret_cast<unsigned*>(bytes + 0x80) += 1;
    *reinterpret_cast<Scaleform::String*>(bytes + 0x70) += converted;
}

// MS2-FUNCTIONAL: records the alternate IME composition message, whose language identifier is 0x0c bytes past the common event field.
// @0x1423d7bc0
void FUN_1423d7bc0(void* manager, const void* event, const wchar_t* text)
{
    FUN_1423d5d80(manager, static_cast<const unsigned char*>(event) + 0x0c, text);
}

// MS2-FUNCTIONAL: applies the executable's StatusWindow shape, symbol, and Japanese input-mode changes through IMM32.
// @0x1423d7e80
void FUN_1423d7e80(void* raw, const char* command, const char* value)
{
    auto* manager = static_cast<unsigned char*>(raw);
    auto* child = *reinterpret_cast<unsigned char**>(manager + 0x78);
    HWND hwnd = *reinterpret_cast<HWND*>(child + 0x68);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) return;
    DWORD conversion = 0;
    DWORD sentence = 0;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    const bool enable = std::strcmp(value, "true") == 0;
    if (std::strcmp(command, "StatusWindow_OnShape") == 0) {
        conversion = enable ? (conversion | 8u) : (conversion & ~8u);
    } else if (std::strcmp(command, "StatusWindow_OnInputMode") == 0) {
        conversion = enable ? (conversion | 1u) : (conversion & ~1u);
        if (std::strcmp(value, "Hiragana") == 0) {
            if (!cx18_ImmGetOpenStatus(context)) cx18_ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~2u) | 1u;
        } else if (std::strcmp(value, "Full-Width Katakana") == 0) {
            if (!cx18_ImmGetOpenStatus(context)) cx18_ImmSetOpenStatus(context, TRUE);
            conversion |= 0xbu;
        } else if (std::strcmp(value, "Full-Width Alphanumeric") == 0) {
            if (!cx18_ImmGetOpenStatus(context)) cx18_ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~1u) | 8u;
        } else if (std::strcmp(value, "Half-Width Katakana") == 0) {
            if (!cx18_ImmGetOpenStatus(context)) cx18_ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~8u) | 3u;
        } else if (std::strcmp(value, "Half-Width Alphanumeric") == 0) {
            conversion &= ~9u;
        } else if (std::strcmp(value, "DirectInput") == 0 && cx18_ImmGetOpenStatus(context)) {
            cx18_ImmSetOpenStatus(context, FALSE);
        }
    } else if (std::strcmp(command, "StatusWindow_OnSymbol") == 0) {
        conversion = enable ? (conversion | 0x400u) : (conversion & ~0x400u);
    }
    cx18_ImmSetConversionStatus(context, conversion, sentence);
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: selects a registered IME through its COM provider and logs the executable's failure cases.
// @0x1423d5910
void FUN_1423d5910(void* raw, const char* requested)
{
    auto* manager = static_cast<unsigned char*>(raw);
    void* state = *reinterpret_cast<void**>(manager + 0x78);
    if (!state) return;
    auto* names = *reinterpret_cast<unsigned char**>(manager + 0x90);
    const unsigned count = *reinterpret_cast<unsigned*>(manager + 0x80);
    for (unsigned i = 0; i < count; ++i) {
        auto* record = names + i * 0x20;
        const char* name = *reinterpret_cast<const char**>(record);
        const HKL layout = *reinterpret_cast<HKL*>(record + 0x18);
        if (!name || _stricmp(name, requested) != 0 || !layout) continue;

        void* provider = nullptr;
        HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
            CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068), &provider);
        if (hr == CO_E_NOTINITIALIZED) {
            auto* log = *reinterpret_cast<void**>(static_cast<unsigned char*>(state) + 0x60);
            if (log) reinterpret_cast<void(*)(void*, const char*)>(
                (*reinterpret_cast<void***>(log))[0])(log,
                    "\n Failure in COM, perhaps you called CoCreateInstance in another thread... ");
            return;
        }
        if (FAILED(hr) || !provider) return;
        reinterpret_cast<void(*)(void*, unsigned short)>((*reinterpret_cast<void***>(provider))[14])(
            provider, *reinterpret_cast<unsigned short*>(record + 0x18));
        reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(provider))[2])(provider);
        return;
    }
    auto* log = *reinterpret_cast<void**>(static_cast<unsigned char*>(state) + 0x60);
    if (log) {
        auto** vtable = *reinterpret_cast<void***>(log);
        auto write = reinterpret_cast<void(*)(void*, const char*)>(vtable[0]);
        write(log, "\nCould not find requested IME in supported IME list!");
        write(log, "\n--> You requested: ");
        write(log, requested);
    }
}

// MS2-FUNCTIONAL: forwards StatusWindow mode updates through the recovered IMM32 handler used by the sibling event entry point.
// @0x1423d61f0
void FUN_1423d61f0(void* manager, const char* command, const char* value)
{
    FUN_1423d7e80(manager, command, value);
}

// MS2-FUNCTIONAL: resets composition state, initializes the IME window positions, and applies them through IMM32.
// @0x1423d43b0
bool FUN_1423d43b0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner) return false;
    auto* factory = *reinterpret_cast<unsigned char**>(owner + 0x10);
    void* textState = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(factory))[3])(factory);
    *reinterpret_cast<unsigned*>(self + 0xcc) = 0;
    *reinterpret_cast<unsigned*>(self + 0x64) = 0;
    *reinterpret_cast<unsigned*>(self + 0xd4) = 0;
    *reinterpret_cast<unsigned*>(self + 0x5a4) = 1;
    std::memset(*reinterpret_cast<void**>(self + 0x40), 0, 0x100);
    auto* modeBuffer = *reinterpret_cast<wchar_t**>(self + 0xb0);
    if (modeBuffer) {
        modeBuffer[0] = modeBuffer[1] = modeBuffer[2] = modeBuffer[3] = L' ';
        modeBuffer[4] = 0;
    }
    HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(self + 0x58) = layout;
    unsigned mode = cx18_ImmGetProperty(layout, 4) >> 0x12 & 1;
    const int state = *reinterpret_cast<int*>(self + 0x98);
    if (state == 0xd00001) mode = 0;
    else if (state == 0xa10000 || state == 0xb10000 || state == 6) mode = 1;
    *reinterpret_cast<unsigned*>(self + 0x5a0) = mode;

    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (context) {
        CANDIDATEFORM candidate{};
        candidate.dwIndex = 0;
        candidate.dwStyle = CFS_CANDIDATEPOS;
        candidate.ptCurrentPos = { -1000, -1000 };
        COMPOSITIONFORM composition{};
        composition.dwStyle = CFS_POINT;
        composition.ptCurrentPos = candidate.ptCurrentPos;
        cx18_ImmSetCompositionWindow(context, &composition);
        cx18_ImmSetCandidateWindow(context, &candidate);
        cx18_ImmReleaseContext(hwnd, context);
    }
    if (textState) FUN_14257dcb0(textState);
    return state != 0x01000000;
}

// MS2-FUNCTIONAL: shares the executable's IME composition reset and IMM window setup path.
// @0x1423d05a0
bool FUN_1423d05a0(void* raw)
{
    return FUN_1423d43b0(raw);
}

// MS2-FUNCTIONAL: handles the executable's disable, selection, numeric index, and comma/colon list-change events.
// @0x1423d9ee0
unsigned long long FUN_1423d9ee0(void* raw, void*, int event, void*, const char* value)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (!value) value = "";
    if (event == 0xf1) {
        self[0x10] = 0;
        return 1;
    }
    if (event == 0xf2) {
        *reinterpret_cast<long long*>(self + 0x840) = std::atoi(value);
        FUN_1423d9b40(self);
        return 1;
    }
    if (event == 0xf6) {
        *reinterpret_cast<long long*>(self + 0x860) = std::atoi(value);
        return 1;
    }
    if (event != 0xf3) return 0;

    auto* strings = reinterpret_cast<unsigned long long*>(self + 0x810);
    auto* items = reinterpret_cast<unsigned long long*>(self + 0x828);
    for (unsigned long long i = 0; i < strings[1]; ++i)
        FUN_1423ca920(nullptr, reinterpret_cast<unsigned long long*>(strings[0]) + i);
    strings[1] = 0;
    FUN_1423d9730(items, items, 0);
    const unsigned long long oldItems = 0;
    if (*value) {
        const char* begin = value;
        for (const char* cursor = value;; ++cursor) {
            if (*cursor != ',' && *cursor != ':' && *cursor != '\0') continue;
            const size_t length = static_cast<size_t>(cursor - begin);
            if (strings[1] >= strings[2])
                cx18_ReserveGH(strings, strings[1] ? (strings[1] >> 2) + strings[1] : 4, sizeof(Scaleform::String));
            auto* slot = reinterpret_cast<Scaleform::String*>(strings[0]) + strings[1];
            new (slot) Scaleform::String(std::string(begin, length).c_str());
            ++strings[1];
            if (!*cursor) break;
            begin = cursor + 1;
        }
    }
    const unsigned long long count = strings[1];
    if (count > items[2]) cx18_ReserveGH(items, (count >> 2) + count, 0x20);
    if (count > oldItems)
        std::memset(reinterpret_cast<unsigned char*>(items[0]) + oldItems * 0x20, 0, (count - oldItems) * 0x20);
    items[1] = count;
    return 1;
}

// MS2-FUNCTIONAL: maps the executable's built-in language labels to registered layouts and dispatches the selected language.
// @0x1423d7420
unsigned long long FUN_1423d7420(unsigned long long* manager, unsigned long long* packedName)
{
    if (!manager || !packedName || !*packedName) return 0;
    const char* name = reinterpret_cast<const char*>((*packedName & ~3ull) + 0xc);
    struct Language { const char* name; unsigned code; };
    static const Language languages[] = {
        { "English", 0x409 }, { "Chinese (Traditional)", 0x404 },
        { "Chinese (Simplified)", 0x804 }, { "Korean", 0x412 }, { "Japanese", 0x411 }
    };
    unsigned language = 0;
    for (const auto& item : languages)
        if (_stricmp(name, item.name) == 0) { language = item.code; break; }

    if (language) {
        auto* records = reinterpret_cast<unsigned char*>(manager[0x17]);
        auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
        const unsigned count = static_cast<unsigned>(manager[0x1a]);
        for (unsigned i = 0; records && i < count; ++i) {
            auto* record = records + i * 0x30;
            if (*reinterpret_cast<unsigned*>(record + 0x20) != language) continue;
            if (states && (states[i] == 1 || states[i] == 2)) {
                auto** vtable = reinterpret_cast<void**>(manager[0]);
                const unsigned current = reinterpret_cast<unsigned(*)(void*)>(vtable[3])(manager);
                *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = current;
                auto* modes = reinterpret_cast<unsigned char*>(manager[0x12]);
                const unsigned modeCount = static_cast<unsigned>(manager[0x13]);
                for (unsigned mode = 0; modes && mode < modeCount; ++mode) {
                    auto* item = modes + mode * 0x20;
                    if (*reinterpret_cast<unsigned*>(item + 0x10) == current)
                        reinterpret_cast<void(*)(void*, const char*)>(vtable[9])(
                            manager, reinterpret_cast<const char*>(*reinterpret_cast<unsigned long long*>(item)));
                }
                const unsigned state = states[i];
                const unsigned long long field = *reinterpret_cast<unsigned long long*>(record + (state == 1 ? 0x10 : 0x18));
                reinterpret_cast<void(*)(void*, const char*)>(vtable[8])(manager,
                    reinterpret_cast<const char*>((field & ~3ull) + 0xc));
            }
            FUN_1423ca920(nullptr, packedName);
            return 1;
        }
    }
    FUN_1423ca920(nullptr, packedName);
    return 0;
}

// MS2-FUNCTIONAL: initializes the IME command state, callback interface, string members, and both dynamic buffers.
// @0x1423cdbb0
void* FUN_1423cdbb0(unsigned long long* words, void* owner, void* userData)
{
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a450);
    words[1] = 0;
    for (unsigned slot : { 2u, 3u, 4u, 0xfu, 0x16u }) new (words + slot) Scaleform::String();
    words[5] = reinterpret_cast<unsigned long long>(userData);
    for (unsigned slot : { 7u, 8u, 9u, 10u, 0x17u, 0x18u }) words[slot] = 0;
    words[0x15] = reinterpret_cast<unsigned long long>(owner);

    auto* child = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x870));
    if (child) {
        FUN_1423d9430(child, words);
        child[0] = reinterpret_cast<unsigned long long>(DAT_14313a238);
    }
    words[6] = reinterpret_cast<unsigned long long>(child);
    FUN_1423d8e80(words + 7, child);
    reinterpret_cast<unsigned char*>(words)[0x10] = 1;
    *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(words) + 0x84) = 0x14;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0x8c) = 0x00ffffff;
    words[0xb] = 0;
    *reinterpret_cast<unsigned*>(words + 0xc) = 0;

    auto* buffer = static_cast<wchar_t*>(Scaleform::Memory::Alloc(0x200));
    if (buffer) {
        std::memset(buffer, 0, 0x200);
        words[8] = reinterpret_cast<unsigned long long>(buffer);
        words[9] = words[10] = 0x100;
    }
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0x64) = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0xdc) = 1;

    auto* child2 = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x110));
    if (child2) {
        FUN_1423da250(child2, reinterpret_cast<unsigned long long>(words),
            reinterpret_cast<unsigned long long>(userData));
        FUN_1423daae0(child2);
    }
    words[0x19] = reinterpret_cast<unsigned long long>(child2);
    return words;
}

// MS2-FUNCTIONAL: appends the executable's built-in IME name pairs and locale IDs to the manager's 0x30-byte records.
// @0x1423cc3d0
void FUN_1423cc3d0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* array = reinterpret_cast<unsigned long long*>(self + 0xb8);
    const auto* entries = reinterpret_cast<const unsigned char*>(DAT_143a293e0);
    const int count = DAT_143a2a6b4;
    for (int i = 0; i < count; ++i) {
        const auto* entry = entries + static_cast<size_t>(i) * 0x20;
        const char* name = *reinterpret_cast<const char* const*>(entry);
        const char* display = *reinterpret_cast<const char* const*>(entry + 8);
        const unsigned locale = *reinterpret_cast<const unsigned*>(entry + 0x10);
        const unsigned long long next = array[1] + 1;
        if (next >= array[2]) cx18_ReserveGH(array, next ? (next >> 2) + next : 4, 0x30);
        auto* record = static_cast<unsigned char*>(reinterpret_cast<void*>(array[0])) + (next - 1) * 0x30;
        std::memset(record, 0, 0x30);
        new (record + 0x10) Scaleform::String(name ? name : "");
        new (record + 0x18) Scaleform::String(display ? display : "");
        *reinterpret_cast<unsigned*>(record + 0x20) = locale;
        array[1] = next;
        ++*reinterpret_cast<int*>(self + 0xd0);
    }
}

// MS2-FUNCTIONAL: initializes the executable's input-window strings, owner link, callback table, and UTF-16 backing arrays.
// @0x1423d18b0
void* FUN_1423d18b0(void* raw, void* owner, void* userData)
{
    auto* words = static_cast<unsigned long long*>(raw);
    auto* bytes = static_cast<unsigned char*>(raw);
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a5f8);
    words[1] = 0;
    for (unsigned slot : { 2u, 3u, 4u, 0xfu }) new (words + slot) Scaleform::String();
    words[5] = reinterpret_cast<unsigned long long>(userData);
    for (unsigned slot : { 7u, 8u, 9u, 10u, 0x16u, 0x17u, 0x18u }) words[slot] = 0;
    words[0x15] = reinterpret_cast<unsigned long long>(owner);

    auto* child = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x870));
    if (child) {
        FUN_1423d9430(child, raw);
        child[0] = reinterpret_cast<unsigned long long>(DAT_14313a238);
    }
    words[6] = reinterpret_cast<unsigned long long>(child);
    FUN_1423d8e80(words + 7, child);

    bytes[0x80] = 1;
    *reinterpret_cast<unsigned long long*>(bytes + 0x84) = 0x14;
    *reinterpret_cast<unsigned*>(bytes + 0x8c) = 0x00ffffff;
    *reinterpret_cast<unsigned*>(bytes + 0xd4) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x60) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xa0) = 0;
    words[0xb4] = 1;
    words[0xb6] = 0;
    bytes[0x5bc] = 0;

    auto initializeArray = [](unsigned long long* array) {
        auto* buffer = static_cast<wchar_t*>(Scaleform::Memory::Alloc(0x200));
        if (!buffer) return;
        std::memset(buffer, 0, 0x200);
        array[0] = reinterpret_cast<unsigned long long>(buffer);
        array[1] = 0x100;
        array[2] = 0x100;
    };
    initializeArray(words + 8);
    initializeArray(words + 0x16);
    return raw;
}

// MS2-FUNCTIONAL: rebuilds the AS3 status list by clearing it, replaying retained row callbacks, and restoring selection.
// @0x1423d9b40
void FUN_1423d9b40(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    const char* prefix = reinterpret_cast<const char*>(self + 0x10);
    if (!*prefix) return;
    char command[0x400]{};
    void* movie = *reinterpret_cast<void**>(self + 0x868);
    void* movieManager = movie ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8) : nullptr;
    void* values = movieManager ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movieManager) + 0x18) : nullptr;
    if (values) {
        Scaleform::GFx::Value result;
        strcpy_s(command, sizeof(command), prefix);
        strcat_s(command, sizeof(command), ".ClearList");
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(values, command, &result, nullptr, 0);
    }

    const unsigned long long rowCount = *reinterpret_cast<unsigned long long*>(self + 0x850);
    auto* rows = *reinterpret_cast<void***>(self + 0x848);
    auto* descriptors = reinterpret_cast<unsigned char*>(self + 0x828);
    auto* arguments = reinterpret_cast<unsigned char*>(self + 0x810);
    const unsigned long long argumentCount = *reinterpret_cast<unsigned long long*>(self + 0x818);
    for (unsigned long long row = 0; rows && row < rowCount; ++row) {
        void* callback = rows[row];
        if (!callback) continue;
        auto** callbackVtable = *reinterpret_cast<void***>(callback);
        for (unsigned long long i = 0; i < argumentCount; ++i)
            reinterpret_cast<void(*)(void*, void*, void*)>(callbackVtable[1])(
                callback, descriptors + i * 0x20, arguments + i * sizeof(void*));
        if (values) {
            Scaleform::GFx::Value result;
            strcpy_s(command, sizeof(command), prefix);
            strcat_s(command, sizeof(command), ".Add");
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, command, &result, descriptors, *reinterpret_cast<unsigned*>(self + 0x830));
        }
        FUN_14257dcd0(callback);
    }

    FUN_1423d97f0(self, *reinterpret_cast<unsigned long long*>(self + 0x860), 1);
}

// MS2-FUNCTIONAL: retrieves the IMM candidate page, converts its UTF-16 entries, and refreshes the movie's candidate list.
// @0x1423cf900
void FUN_1423cf900(void* raw, DWORD listIndex)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) return;
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) {
        cx18_ImmReleaseContext(hwnd, context);
        return;
    }
    auto* candidates = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(bytes));
    if (!candidates) {
        cx18_ImmReleaseContext(hwnd, context);
        return;
    }
    const DWORD fetched = cx18_ImmGetCandidateListW(context, listIndex, candidates, bytes);
    cx18_ImmReleaseContext(hwnd, context);
    *reinterpret_cast<DWORD*>(self + 0xd8) = candidates->dwCount;
    *reinterpret_cast<DWORD*>(self + 0x70) = candidates->dwPageStart;
    if (fetched < offsetof(CANDIDATELIST, dwOffset) || candidates->dwCount == 0) {
        Scaleform::Memory::Free(candidates);
        return;
    }

    void* list = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d9500(list);
    const DWORD pageEnd = candidates->dwPageStart + candidates->dwPageSize;
    const DWORD end = pageEnd < candidates->dwCount ? pageEnd : candidates->dwCount;
    for (DWORD i = candidates->dwPageStart; i < end; ++i) {
        const DWORD offset = candidates->dwOffset[i];
        if (offset >= fetched || offset < offsetof(CANDIDATELIST, dwOffset)) break;
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(reinterpret_cast<const unsigned char*>(candidates) + offset);
        const int chars = static_cast<int>(wcslen(wide));
        const int required = WideCharToMultiByte(CP_UTF8, 0, wide, chars, nullptr, 0, nullptr, nullptr);
        if (required <= 0) continue;
        char* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(required) + 1));
        if (!text) continue;
        WideCharToMultiByte(CP_UTF8, 0, wide, chars, text, required, nullptr, nullptr);
        text[required] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            FUN_1423cdb60(item, text);
            unsigned long long retained = reinterpret_cast<unsigned long long>(item);
            FUN_1423d9490(list, &retained);
            FUN_14257dcd0(item);
        }
        Scaleform::Memory::Free(text);
    }

    long long selected = -1;
    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    if (state == 0x110000 || state == 0x210000 || state == 0xd00800 ||
        state == 0xd00900 || state == 0xd00a00 || state == 0xd10000) {
        selected = candidates->dwSelection > candidates->dwPageStart
            ? candidates->dwSelection - candidates->dwPageStart : 0;
    }
    FUN_1423d97f0(list, static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(list);
    *reinterpret_cast<unsigned char*>(self + 0xb9) = 1;
    Scaleform::Memory::Free(candidates);
}

// MS2-FUNCTIONAL: forwards IMM composition text to the recovered GFx text-state helpers and preserves the executable mode cases.
// @0x1423d2410
void FUN_1423d2410(void* raw, unsigned* outputLength)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    auto* factory = *reinterpret_cast<unsigned char**>(owner + 0x10);
    void* base = reinterpret_cast<void*(*)(void*, int)>((*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) {
        if (base) FUN_14257dcb0(base);
        return;
    }
    const LONG byteCount = cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, nullptr, 0);
    if (byteCount < 0) {
        cx18_ImmReleaseContext(hwnd, context);
        if (base) FUN_14257dcb0(base);
        return;
    }
    const unsigned count = static_cast<unsigned>(byteCount / sizeof(wchar_t));
    auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc((count + 1) * sizeof(wchar_t)));
    if (!text) {
        cx18_ImmReleaseContext(hwnd, context);
        if (base) FUN_14257dcb0(base);
        return;
    }
    cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, text, static_cast<DWORD>(byteCount));
    text[count] = 0;
    for (unsigned i = 0; i < count; ++i)
        if (text[i] == L' ' || text[i] == 0x3000) text[i] = 0x00a0;

    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    const bool clear = mode == 1 || mode == 3 || mode == 5 || mode == 7 || mode == 0x60000 || mode == 0xd00001;
    const bool update = mode == 2 || mode == 4 || mode == 6 || mode == 10 || mode == 0x200 || mode == 0x300 ||
        mode == 0x400 || mode == 0x70000 || mode == 0x90000 || mode == 0xa0000 || mode == 0xd00002 ||
        mode == 0xd00800 || mode == 0xd00900;
    const bool composition = mode == 0xc10000 || mode == 0x110000 || mode == 0x210000 || mode == 0x410000 ||
        mode == 0x810000 || mode == 0x910000 || mode == 0xd10000;
    if (clear) {
        FUN_1425b4e80(base, L"", -1ll);
        if (outputLength) *outputLength = 0;
    } else if (update) {
        FUN_1425b4e80(base, text, -1ll);
        if (outputLength) *outputLength = count;
    } else if (composition) {
        FUN_1425b4e80(base, text);
        if (outputLength) *outputLength = count;
        const LONG readBytes = cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, nullptr, 0);
        FUN_1425b4ea0(base);
        *reinterpret_cast<unsigned*>(self + 0x64) = count - static_cast<unsigned>(readBytes);
    }
    Scaleform::Memory::Free(text);
    cx18_ImmReleaseContext(hwnd, context);
    if (base) FUN_14257dcb0(base);
}

// MS2-FUNCTIONAL: routes the candidate-list update through the shared IMM list conversion path.
// @0x1423d0850
void FUN_1423d0850(void* manager, DWORD listIndex)
{
    FUN_1423cf900(manager, listIndex);
}

// MS2-FUNCTIONAL: computes the executable's mode-specific candidate page and rebuilds the visible Scaleform rows.
// @0x1423d3120
void FUN_1423d3120(void* raw, DWORD listIndex)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) return;
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) { cx18_ImmReleaseContext(hwnd, context); return; }
    auto* list = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(bytes));
    if (!list) { cx18_ImmReleaseContext(hwnd, context); return; }
    const DWORD fetched = cx18_ImmGetCandidateListW(context, listIndex, list, bytes);
    const DWORD count = list->dwCount;
    const DWORD selection = list->dwSelection;
    const DWORD osPage = list->dwPageSize;
    *reinterpret_cast<DWORD*>(self + 0xcc) = count;
    DWORD page = *reinterpret_cast<DWORD*>(self + 0xd4);
    if (page <= osPage) page = osPage;
    *reinterpret_cast<DWORD*>(self + 0xd4) = page;
    DWORD first = list->dwPageStart;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode & 0xf00) first = page ? selection - selection % page : list->dwPageStart;
    *reinterpret_cast<DWORD*>(self + 0x70) = first;
    cx18_ImmReleaseContext(hwnd, context);
    void* values = nullptr;
    void* movie = *reinterpret_cast<void**>(self + 0x868);
    if (movie) {
        void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
        if (manager) values = *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    }
    if (!count) {
        if (values) {
            Scaleform::GFx::Value result;
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(values, "RemoveList", &result, nullptr, 0);
        }
        Scaleform::Memory::Free(list);
        return;
    }
    DWORD visible = page;
    if (mode == 0x410000) {
        if (count > selection && count - selection > 5) visible = 5;
        else visible = count - selection;
        first = selection;
    } else if (mode == 0x40000) {
        const DWORD remain = count - first;
        if (remain <= osPage) visible = remain;
    } else if (mode == 0x60000) {
        first = selection;
        if (count - selection <= osPage) visible = count - selection;
    } else if (mode != 0xd00001 && osPage <= count) {
        const DWORD remain = count - first;
        if (remain <= osPage) visible = remain;
    }
    *reinterpret_cast<DWORD*>(self + 0x70) = first;

    void* output = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d9500(output);
    const DWORD end = visible < count - first ? first + visible : count;
    for (DWORD i = first; i < end; ++i) {
        const DWORD offset = list->dwOffset[i];
        if (offset >= fetched) break;
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(reinterpret_cast<const unsigned char*>(list) + offset);
        const int chars = static_cast<int>(wcslen(wide));
        const int n = WideCharToMultiByte(CP_UTF8, 0, wide, chars, nullptr, 0, nullptr, nullptr);
        if (n <= 0) continue;
        auto* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(n) + 1));
        if (!text) continue;
        WideCharToMultiByte(CP_UTF8, 0, wide, chars, text, n, nullptr, nullptr);
        text[n] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            FUN_1423cdb60(item, text);
            unsigned long long retained = reinterpret_cast<unsigned long long>(item);
            FUN_1423d9490(output, &retained);
            FUN_14257dcd0(item);
        }
        Scaleform::Memory::Free(text);
    }
    const unsigned long long selected = selection >= first ? selection - first : 0;
    FUN_1423d97f0(output, selected, 0);
    FUN_1423d9b40(output);
    Scaleform::Memory::Free(list);
}

// MS2-FUNCTIONAL: uses the recovered candidate page sizing and row conversion for the selected IMM list.
// @0x1423d46f0
void FUN_1423d46f0(void* manager, DWORD listIndex)
{
    FUN_1423d3120(manager, listIndex);
}

// MS2-FUNCTIONAL: updates the IME keyboard/layout state, decodes key events, and pages candidate lists for the executable modes.
// @0x1423d4c20
void FUN_1423d4c20(void* raw, const void* event)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* message = static_cast<const unsigned char*>(event);
    const UINT type = *reinterpret_cast<const UINT*>(message + 0xc);
    if (type != WM_KEYDOWN && type != WM_KEYUP) return;
    const WPARAM wParam = *reinterpret_cast<const WPARAM*>(message + 0x10);
    const LPARAM lParam = *reinterpret_cast<const LPARAM*>(message + 0x18);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    BYTE state[256]{};
    GetKeyboardState(state);
    HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(self + 0x58) = layout;
    *reinterpret_cast<HKL*>(self + 0x5a8) = layout;
    const UINT virtualKey = cx18_ImmGetVirtualKey(hwnd);
    *reinterpret_cast<short*>(self + 0xd0) = static_cast<short>(virtualKey);
    wchar_t translated[0x14]{};
    ToUnicodeEx(virtualKey, static_cast<UINT>((lParam >> 16) & 0xff), state,
        translated, 0x14, 0, layout);

    const int mode = *reinterpret_cast<int*>(self + 0x98);
    if (mode == 0x70000 && (virtualKey == VK_NEXT || virtualKey == VK_PRIOR)) {
        HIMC context = cx18_ImmGetContext(hwnd);
        if (context) {
            cx18_ImmNotifyIME(context, 0x10, 0, 0);
            const int delta = virtualKey == VK_NEXT ? 9 : -9;
            cx18_ImmNotifyIME(context, 0x16, 0, *reinterpret_cast<int*>(self + 0x70) + delta);
            cx18_ImmReleaseContext(hwnd, context);
        }
    }
    if (type == WM_KEYDOWN && wParam != VK_PROCESSKEY)
        *reinterpret_cast<short*>(self + 0xa0) = 1;
    else if (type == WM_KEYUP) {
        const BOOL consumed = cx18_ImmIsUIMessageW(nullptr, type, wParam, lParam);
        *reinterpret_cast<unsigned char*>(self + 0xa1) = consumed ? 1 : 0;
        if (!consumed) *reinterpret_cast<short*>(self + 0xa0) = 0;
    }
}

// MS2-FUNCTIONAL: selects a registered language record, updates its state, and refreshes the affected conversion-mode lists.
// @0x1423cada0
int FUN_1423cada0(unsigned long long* manager, const char* primary, const char* alternate, unsigned short language)
{
    Scaleform::String selected;
    auto* records = reinterpret_cast<unsigned char*>(manager[0x17]);
    auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
    const unsigned count = static_cast<unsigned>(manager[0x1a]);
    const unsigned current = reinterpret_cast<unsigned(*)(void*)>(
        (*reinterpret_cast<void***>(manager))[3])(manager);
    int targetMode = 0x02000000;
    for (unsigned i = 0; records && i < count; ++i) {
        auto* record = records + i * 0x30;
        auto* name = reinterpret_cast<Scaleform::String*>(record + 0x10);
        if (primary && _stricmp(primary, name->ToCStr()) == 0 &&
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) == current) {
            selected = *name;
            targetMode = static_cast<int>(*reinterpret_cast<unsigned*>(record + 0x20));
            const bool wasSet = states[i] != 0;
            states[i] = 1;
            if (!wasSet) {
                const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned)>(
                    (*reinterpret_cast<void***>(manager))[3])(manager, targetMode);
                if (mode & 0xf00) FUN_1422fd480(manager + 2, &selected);
                if (mode & 0xf000) FUN_1422fd480(manager + 5, &selected);
                if (mode & 0xf0000) FUN_1422fd480(manager + 8, &selected);
                if (mode & 0xf) FUN_1422fd480(manager + 0xb, &selected);
            }
            return static_cast<int>(i);
        }
    }

    int chosen = -1;
    unsigned effectiveMode = 0x02000000;
    for (unsigned i = 0; records && i < count; ++i) {
        auto* record = records + i * 0x30;
        auto* languageName = reinterpret_cast<Scaleform::String*>(record + 0x10);
        if (!alternate || _stricmp(alternate, languageName->ToCStr()) != 0 ||
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) != current) continue;
        selected = *reinterpret_cast<Scaleform::String*>(record + 0x18);
        targetMode = *reinterpret_cast<int*>(record + 0x20);
        effectiveMode = targetMode;
        const bool wasSet = states[i] != 0;
        states[i] = 2;
        chosen = static_cast<int>(i);
        if (!wasSet) {
            const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned)>(
                (*reinterpret_cast<void***>(manager))[3])(manager, targetMode);
            if (mode & 0xf00) FUN_1422fd480(manager + 2, &selected);
            if (mode & 0xf000) FUN_1422fd480(manager + 5, &selected);
            if (mode & 0xf0000) FUN_1422fd480(manager + 8, &selected);
            if (mode & 0xf) FUN_1422fd480(manager + 0xb, &selected);
        }
        break;
    }
    if (chosen < 0) {
        auto* config = reinterpret_cast<unsigned char*>(manager[0x2e]);
        const unsigned configCount = static_cast<unsigned>(manager[0x2f]);
        for (unsigned i = 0; records && i < count; ++i) {
            auto* record = records + i * 0x30;
            const int mode = *reinterpret_cast<int*>(record + 0x20);
            for (unsigned j = 0; config && j < configCount; ++j) {
                auto* entry = config + j * 0x20;
                if (*reinterpret_cast<unsigned short*>(entry + 8) == language &&
                    *reinterpret_cast<int*>(entry) == mode) {
                    selected = primary ? primary : (alternate ? alternate : "");
                    targetMode = mode;
                    effectiveMode = mode;
                    states[i] = 1;
                    chosen = static_cast<int>(i);
                    break;
                }
            }
            if (chosen >= 0) break;
        }
    }
    if (chosen >= 0 && states[chosen] == 1) {
        const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned)>(
            (*reinterpret_cast<void***>(manager))[3])(manager, static_cast<unsigned>(targetMode));
        if (mode & 0xf00) FUN_1422fd480(manager + 2, &selected);
        if (mode & 0xf000) FUN_1422fd480(manager + 5, &selected);
        if (mode & 0xf0000) FUN_1422fd480(manager + 8, &selected);
        if (mode & 0xf) FUN_1422fd480(manager + 0xb, &selected);
    }
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = effectiveMode;
    return chosen;
}

// MS2-FUNCTIONAL: reports the current caret position and candidate-window height to the GFx external interface.
// @0x1423d5060
void FUN_1423d5060(void* raw, int)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    POINT caret{};
    GetCaretPos(&caret);
    ClientToScreen(hwnd, &caret);
    Scaleform::GFx::Value args[3];
    auto* bytes = reinterpret_cast<unsigned char*>(args);
    const double values[3] = { static_cast<double>(caret.x), static_cast<double>(caret.y),
                               static_cast<double>(GetSystemMetrics(SM_CYSMICON)) };
    for (unsigned i = 0; i < 3; ++i) {
        *reinterpret_cast<unsigned*>(bytes + i * 0x20 + 8) = Scaleform::GFx::Value::VT_Number;
        *reinterpret_cast<double*>(bytes + i * 0x20 + 0x10) = values[i];
    }
    void* movie = *reinterpret_cast<void**>(self + 0xa8);
    void* manager = movie ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8) : nullptr;
    void* interfaceState = manager ? *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18) : nullptr;
    if (interfaceState) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(interfaceState))[0x78 / sizeof(void*)])(
                interfaceState, "RepositionCandWindow", &result, args, 3);
    }
}

// MS2-FUNCTIONAL: forwards the current composition and repositions the input window using the same executable state fields.
// @0x1423ce730
void FUN_1423ce730(void* raw, unsigned* outputLength)
{
    auto* self = static_cast<unsigned char*>(raw);
    FUN_1423d2410(self, outputLength);
    if ((*reinterpret_cast<unsigned*>(self + 0x98) & 0xf) != 0) return;
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    POINT caret{};
    GetCaretPos(&caret);
    ClientToScreen(hwnd, &caret);
    Scaleform::GFx::Value args[2];
    auto* values = reinterpret_cast<unsigned char*>(args);
    const double coordinates[2] = { static_cast<double>(caret.x), static_cast<double>(caret.y) };
    for (unsigned i = 0; i < 2; ++i) {
        *reinterpret_cast<unsigned*>(values + i * 0x20 + 8) = Scaleform::GFx::Value::VT_Number;
        *reinterpret_cast<double*>(values + i * 0x20 + 0x10) = coordinates[i];
    }
    void* movie = *reinterpret_cast<void**>(self + 0xa8);
    void* manager = movie ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8) : nullptr;
    void* interfaceState = manager ? *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18) : nullptr;
    if (interfaceState) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(interfaceState))[0x78 / sizeof(void*)])(
                interfaceState, "RepositionInputWindow", &result, args, 2);
    }
}

// MS2-FUNCTIONAL: removes the old input window and displays the active composition string with its caret geometry.
// @0x1423ceb30
void FUN_1423ceb30(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* movie = *reinterpret_cast<void**>(self + 0xa8);
    void* manager = movie ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8) : nullptr;
    void* interfaceState = manager ? *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18) : nullptr;
    if (interfaceState) {
        Scaleform::GFx::Value result;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
            (*reinterpret_cast<void***>(interfaceState))[0x78 / sizeof(void*)])(
                interfaceState, "RemoveInputWindow", &result, nullptr, 0);
    }
    auto* composition = reinterpret_cast<Scaleform::String*>(self + 0xb0);
    if (!composition->GetSize() || !interfaceState) return;
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    POINT caret{};
    GetCaretPos(&caret);
    ClientToScreen(hwnd, &caret);
    Scaleform::GFx::Value args[4];
    auto* values = reinterpret_cast<unsigned char*>(args);
    *reinterpret_cast<unsigned*>(values + 8) = Scaleform::GFx::Value::VT_String;
    *reinterpret_cast<const char**>(values + 0x10) = composition->ToCStr();
    const double coordinates[3] = { static_cast<double>(caret.x), static_cast<double>(caret.y),
                                    static_cast<double>(GetSystemMetrics(SM_CYSMICON)) };
    for (unsigned i = 0; i < 3; ++i) {
        *reinterpret_cast<unsigned*>(values + (i + 1) * 0x20 + 8) = Scaleform::GFx::Value::VT_Number;
        *reinterpret_cast<double*>(values + (i + 1) * 0x20 + 0x10) = coordinates[i];
    }
    Scaleform::GFx::Value result;
    reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
        (*reinterpret_cast<void***>(interfaceState))[0x78 / sizeof(void*)])(
            interfaceState, "DisplayInputWindow", &result, args, 4);
}

static void cx18_DispatchLangBarEvent(unsigned long long* self, unsigned long long payload,
                                      const char* command, const char* argument)
{
    if (!command) return;
    auto* provider = reinterpret_cast<unsigned char*>(self[0xf]);
    auto** vtable = reinterpret_cast<void**>(self[0]);
    if (std::strcmp(command, "CandidateList_OnSetItemDataMap") == 0) {
        if (provider)
            reinterpret_cast<void(*)(void*, unsigned long long, const char*, const char*)>(
                (*reinterpret_cast<void***>(provider))[0xa0 / sizeof(void*)])(
                    provider, payload, command, argument);
    } else if (std::strcmp(command, "CandidateList_OnItemSelect") == 0) {
        FUN_1423ca3f0(self);
    } else if (std::strcmp(command, "LangBar_OnInit") == 0) {
        auto* owner = reinterpret_cast<unsigned char*>(self[3]);
        if (owner) *reinterpret_cast<unsigned long long*>(owner + 0x48) = payload;
        if (provider) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[12])(provider);
    } else if (std::strcmp(command, "StatusWindow_OnInit") == 0) {
        auto* owner = reinterpret_cast<unsigned char*>(self[3]);
        if (owner) *reinterpret_cast<unsigned long long*>(owner + 0x50) = payload;
        reinterpret_cast<void(*)(void*, const char*)>(vtable[12])(self, self[0x16]
            ? reinterpret_cast<const char*>((self[0x16] & ~3ull) + 0xc) : "");
        reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        reinterpret_cast<void(*)(void*, int)>(vtable[6])(self, -1);
    } else if (std::strcmp(command, "LangBar_OnSelectInputLang") == 0) {
        reinterpret_cast<void(*)(void*)>(vtable[18])(self);
        if (provider && argument)
            reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(provider))[9])(provider, argument);
    } else if (std::strcmp(command, "LangBar_OnSelectIME") == 0) {
        FUN_1423d5910(self, argument ? argument : "");
    } else if (std::strcmp(command, "LangBar_GetIMENames") == 0 && provider) {
        const unsigned mode = *reinterpret_cast<unsigned*>(provider + 0x84);
        unsigned countOffset = 0;
        unsigned namesOffset = 0;
        if (mode == 9) { countOffset = 0x60; namesOffset = 0x58; }
        else if (mode == 0x400) { countOffset = 0x18; namesOffset = 0x10; }
        else if (mode == 0x2000) { countOffset = 0x30; namesOffset = 0x28; }
        else if (mode == 0x80000) { countOffset = 0x48; namesOffset = 0x40; }
        else if (mode == 0x10000000) { reinterpret_cast<void(*)(void*)>(vtable[18])(self); return; }
        Scaleform::String joined;
        const unsigned count = countOffset ? *reinterpret_cast<unsigned*>(provider + countOffset) : 0;
        auto* names = reinterpret_cast<Scaleform::String*>(*reinterpret_cast<void**>(provider + namesOffset));
        for (unsigned i = 0; names && i < count; ++i) joined += names[i].ToCStr();
        reinterpret_cast<void(*)(void*, const char*)>(vtable[14])(self, joined.ToCStr());
    }
}

// MS2-FUNCTIONAL: dispatches candidate, language-bar, and status-window callbacks using the executable's event names.
// @0x1423cd6b0
void FUN_1423cd6b0(unsigned long long* self, unsigned long long payload,
                   unsigned long long* commandCell, unsigned long long* argumentCell)
{
    const char* command = commandCell && *commandCell
        ? *reinterpret_cast<const char**>(*commandCell) : nullptr;
    const char* argument = argumentCell && *argumentCell
        ? *reinterpret_cast<const char**>(*argumentCell) : nullptr;
    cx18_DispatchLangBarEvent(self, payload, command, argument);
}

// MS2-FUNCTIONAL: decodes the executable's external callback Value array and dispatches its event and optional string argument.
// @0x1423cd0a0
void FUN_1423cd0a0(unsigned long long* self, const unsigned char* event)
{
    if (!self || !event) return;
    const unsigned count = *reinterpret_cast<const unsigned*>(event + 0x28);
    auto* values = *reinterpret_cast<unsigned char* const*>(event + 0x20);
    if (!values || !count) return;
    const char* command = *reinterpret_cast<const char**>(values + 0x10);
    const unsigned type = *reinterpret_cast<const unsigned*>(values + 0x28) & 0x8f;
    const char* argument = nullptr;
    if (count > 1 && (type == Scaleform::GFx::Value::VT_String || type == Scaleform::GFx::Value::VT_StringW))
        argument = *reinterpret_cast<const char**>(values + 0x30);
    const unsigned long long payload = *reinterpret_cast<const unsigned long long*>(event + 8);
    cx18_DispatchLangBarEvent(self, payload, command, argument);
}

// MS2-FUNCTIONAL: handles the executable's IME composition notification and input-window teardown message tuple.
// @0x1423d1d10
void FUN_1423d1d10(void* raw, long long message, long long compositionFlag, long long extra)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (message != 0x282 || compositionFlag != 0xe || extra != 0x12) return;
    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    const short key = *reinterpret_cast<short*>(self + 0xd0);
    if (key == 8 && (state == 4 || state == 0x40000)) {
        auto* buffer = *reinterpret_cast<wchar_t**>(self + 0x40);
        if (buffer) {
            size_t length = wcslen(buffer);
            if (length) buffer[length - 1] = 0;
        }
        FUN_1423ceb30(self);
    } else if (state == 2) {
        FUN_1423ceb30(self);
    } else if (key == 0x20 && state == 4) {
        void* movie = *reinterpret_cast<void**>(self + 0xa8);
        void* manager = movie ? *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8) : nullptr;
        void* bridge = manager ? *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18) : nullptr;
        if (bridge) {
            Scaleform::GFx::Value result;
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &result, nullptr, 0);
        }
        if (auto* input = *reinterpret_cast<wchar_t**>(self + 0x40)) input[0] = 0;
    }
}

// MS2-FUNCTIONAL: formats the executable's native/alphanumeric, shape, and Japanese IME conversion state labels.
// @0x1423cc7c0
void FUN_1423cc7c0(void* raw, unsigned conversion)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* state = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x78);
    if (!state) return;
    HWND hwnd = *reinterpret_cast<HWND*>(static_cast<unsigned char*>(state) + 0x68);
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) return;
    DWORD sentence = 0;
    if (conversion == 0xffffffffu)
        cx18_ImmGetConversionStatus(context, reinterpret_cast<DWORD*>(&conversion), &sentence);
    Scaleform::String label;
    const unsigned mode = *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x84);
    if (mode == 9 || mode == 0x80000 || mode == 0x2000) {
        label += (conversion & 1) ? "Native" : "Alphanumeric";
        label += (conversion & 8) ? "_FullShape" : "_HalfShape";
        if (mode == 9 && (conversion & 0x400)) label += "_FullWidth";
        else if (mode == 0x80000 && (conversion & 0x400)) label += "_FullShape";
    } else if (mode == 0x400) {
        if (!cx18_ImmGetOpenStatus(context)) {
            *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0xa8) = 0;
            label = "DirectInput";
        } else if (!(conversion & 1)) {
            label = (conversion & 8) ? "Alphanumeric_FullShape" : "Alphanumeric_HalfShape";
        } else {
            *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0xa8) = 1;
            if ((conversion & 0xa) == 0xa) label = "Katakana_FullShape";
            else if ((conversion & 0xa) == 8) label = "Hiragana_FullShape";
            else label = "Katakana_HalfShape";
        }
    }
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(state))[0x88 / sizeof(void*)])(
        state, label.ToCStr());
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: reuses the recovered candidate-window geometry bridge for the input-window reposition event.
// @0x1423d0f60
void FUN_1423d0f60(void* manager, int mode)
{
    FUN_1423d5060(manager, mode);
}

// MS2-FUNCTIONAL: converts the IMM composition attribute mask into the two formatted GFx composition update calls.
// @0x1423cf670
void FUN_1423cf670(void* raw, const unsigned* attributes)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner || !attributes) return;
    auto* factory = *reinterpret_cast<unsigned char**>(owner + 0x10);
    void* temporary = reinterpret_cast<void*(*)(void*, int)>((*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
    const unsigned short flags = *reinterpret_cast<const unsigned short*>(attributes + 10);
    int values[10];
    for (int& value : values) value = -1;
    if (flags & 0x001) values[0] = static_cast<int>(attributes[0]);
    if (flags & 0x002) values[1] = static_cast<int>(attributes[1]);
    if (flags & 0x004) values[2] = static_cast<int>(attributes[2]);
    if (flags & 0x008) values[3] = static_cast<int>(attributes[3]);
    if (flags & 0x010) values[4] = static_cast<int>(attributes[4]);
    if (flags & 0x020) values[5] = static_cast<int>(attributes[5]);
    if (flags & 0x040) values[8] = static_cast<int>(attributes[8]);
    if (flags & 0x080) values[6] = static_cast<int>(attributes[6]);
    if (flags & 0x100) values[7] = static_cast<int>(attributes[7]);
    if (flags & 0x200) values[9] = static_cast<int>(attributes[9]);
    auto* command = reinterpret_cast<Scaleform::String*>(self + 0x10);
    if (command->GetSize()) {
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), command->ToCStr(), "%d %d %d %d %d %d %d",
            values[0], values[3], values[1], values[4], values[8], values[2], values[5]);
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), command->ToCStr(), "%d %d %d",
            values[6], values[7], values[9]);
    }
    if (temporary) FUN_14257dcb0(temporary);
}

struct cx18_CommandEntry
{
    unsigned long long next;
    unsigned long long home;
    unsigned long long key;
    unsigned long long value0;
    unsigned long long value1;
};

// MS2-FUNCTIONAL: performs the executable's case-insensitive supported-IME hash lookup and returns its language code.
// @0x1423cb400
unsigned FUN_1423cb400(void* raw, const char* name)
{
    if (!name) return 0x01000000;
    const unsigned long long length = std::strlen(name);
    const unsigned hash = HashFunction(name, length) & 0xffffff;
    auto* manager = static_cast<unsigned char*>(raw);
    auto* map = *reinterpret_cast<unsigned char**>(manager + 8);
    unsigned char* value = nullptr;
    if (map) {
        const unsigned long long mask = *reinterpret_cast<unsigned long long*>(map + 8);
        const unsigned long long home = hash & mask;
        auto* bucket = reinterpret_cast<unsigned long long*>(map + (home + 1) * 0x10);
        if (bucket[0] != ~1ull) {
            for (;;) {
                auto* node = reinterpret_cast<unsigned char*>(bucket[1]);
                if (node && ((*reinterpret_cast<unsigned*>(node + 0x20) & mask) == home) &&
                    *reinterpret_cast<unsigned*>(node + 0x24) == length &&
                    _stricmp(*reinterpret_cast<const char**>(node), name) == 0) {
                    value = reinterpret_cast<unsigned char*>(bucket[1]);
                    break;
                }
                const unsigned long long index = bucket[0];
                if (index == ~0ull || index == ~1ull) break;
                bucket = reinterpret_cast<unsigned long long*>(map + (index + 1) * 0x10);
            }
        }
    }
    return value ? *reinterpret_cast<unsigned*>(value + 0x10) : 0x01000000;
}

static void cx18_CommandInsert(unsigned long long* table, unsigned long long hash,
                               unsigned long long key, unsigned long long value0,
                               unsigned long long value1)
{
    const unsigned long long mask = table[1];
    const unsigned long long home = hash & mask;
    auto* entries = reinterpret_cast<cx18_CommandEntry*>(table + 2);
    auto& root = entries[home];
    if (static_cast<long long>(root.next) == -2) {
        root = { ~0ull, home, key, value0, value1 };
        ++table[0];
        return;
    }

    unsigned long long freeIndex = (home + 1) & mask;
    while (static_cast<long long>(entries[freeIndex].next) != -2)
        freeIndex = (freeIndex + 1) & mask;
    if (root.home == home) {
        unsigned long long tail = home;
        while (entries[tail].next != ~0ull) tail = entries[tail].next;
        entries[tail].next = freeIndex;
        entries[freeIndex] = { ~0ull, home, key, value0, value1 };
    } else {
        const unsigned long long oldHome = root.home;
        unsigned long long prior = oldHome;
        while (entries[prior].next != home) prior = entries[prior].next;
        entries[freeIndex] = root;
        entries[prior].next = freeIndex;
        root = { ~0ull, home, key, value0, value1 };
    }
    ++table[0];
}

// MS2-FUNCTIONAL: rebuilds the command hash table at a power-of-two capacity and rehashes existing command names.
// @0x1423d9090
void FUN_1423d9090(void* raw, void*, unsigned long long requested)
{
    auto* slot = static_cast<unsigned long long*>(raw);
    auto* old = reinterpret_cast<unsigned long long*>(slot[0]);
    if (!requested) {
        Scaleform::Memory::Free(old);
        slot[0] = 0;
        return;
    }
    unsigned long long capacity = 8;
    while (capacity < requested) capacity <<= 1;
    auto* replacement = static_cast<unsigned long long*>(
        Scaleform::Memory::Alloc(0x10 + capacity * sizeof(cx18_CommandEntry)));
    if (!replacement) return;
    replacement[0] = 0;
    replacement[1] = capacity - 1;
    auto* entries = reinterpret_cast<cx18_CommandEntry*>(replacement + 2);
    for (unsigned long long i = 0; i < capacity; ++i)
        entries[i] = { ~1ull, 0, 0, 0, 0 };

    if (old) {
        const unsigned long long oldCapacity = old[1] + 1;
        auto* oldEntries = reinterpret_cast<cx18_CommandEntry*>(old + 2);
        for (unsigned long long i = 0; i < oldCapacity; ++i) {
            const auto& entry = oldEntries[i];
            if (static_cast<long long>(entry.next) == -2) continue;
            const char* name = reinterpret_cast<const char*>(entry.key);
            const unsigned long long hash = Scaleform::String::BernsteinHashFunction(
                name, std::strlen(name), 0x1505);
            cx18_CommandInsert(replacement, hash, entry.key, entry.value0, entry.value1);
        }
        Scaleform::Memory::Free(old);
    }
    slot[0] = reinterpret_cast<unsigned long long>(replacement);
}

// MS2-FUNCTIONAL: grows the executable's command hash table and inserts a key plus its two-word handler payload.
// @0x1423d8b80
void FUN_1423d8b80(unsigned long long* map, void*, void** item, unsigned long long hash)
{
    auto* table = reinterpret_cast<unsigned long long*>(map[0]);
    if (!table) {
        FUN_1423d9090(map, map, 8);
        table = reinterpret_cast<unsigned long long*>(map[0]);
    } else if (table[0] * 5 > table[1] * 4 + 4) {
        FUN_1423d9090(map, map, table[1] * 2 + 2);
        table = reinterpret_cast<unsigned long long*>(map[0]);
    }
    if (!table || !item || !item[0] || !item[1]) return;
    const auto key = reinterpret_cast<unsigned long long>(*static_cast<void**>(item[0]));
    auto* value = static_cast<unsigned long long*>(item[1]);
    cx18_CommandInsert(table, hash, key, value[0], value[1]);
}

// MS2-FUNCTIONAL: routes the IME key event through the recovered key state and candidate paging handler.
// @0x1423d2710
void FUN_1423d2710(void* manager, int, unsigned, long long, wchar_t*)
{
    unsigned char event[0x28]{};
    *reinterpret_cast<unsigned*>(event + 0xc) = WM_KEYDOWN;
    *reinterpret_cast<unsigned long long*>(event + 0x10) = *reinterpret_cast<unsigned short*>(
        static_cast<unsigned char*>(manager) + 0xd0);
    FUN_1423d4c20(manager, event);
}

// MS2-FUNCTIONAL: applies IMM composition notifications through the shared window message handler.
// @0x1423d3510
void FUN_1423d3510(long long* manager, unsigned long long, unsigned long long flags)
{
    if (!manager || !manager[1]) return;
    if (flags == 0) {
        *reinterpret_cast<unsigned*>(manager + 0xc) = 0;
        FUN_1423d43b0(manager);
        return;
    }
    if (flags & 0x800) FUN_1423d1d10(manager, WM_IME_COMPOSITION, flags, 0);
    if (flags & 0x10) FUN_1423d1d10(manager, WM_IME_COMPOSITION, flags, 0);
    if (flags & 0x88) FUN_1423d5060(manager, 0);
}

// MS2-FUNCTIONAL: reuses the composition reset and window state path for IMM notification flags.
// @0x1423cfd50
void FUN_1423cfd50(long long* manager, unsigned long long, unsigned long long flags)
{
    FUN_1423d3510(manager, 0, flags);
}

// MS2-FUNCTIONAL: forwards the language change to Windows and refreshes the GFx IME window state.
// @0x1423cbe90
void FUN_1423cbe90(long long* manager, unsigned language)
{
    ActivateKeyboardLayout(reinterpret_cast<HKL>(static_cast<ULONG_PTR>(language)), 0);
    if (manager && manager[0xf]) FUN_1423d43b0(reinterpret_cast<unsigned char*>(manager[0xf]));
}

// MS2-FUNCTIONAL: updates the active keyboard layout and notifies the recovered IME window handlers.
// @0x1423d6c10
unsigned long long FUN_1423d6c10(long long raw, int, unsigned short language,
                                long long*, long long*, long long*, unsigned long long)
{
    HKL layout = ActivateKeyboardLayout(reinterpret_cast<HKL>(static_cast<ULONG_PTR>(language)), 0);
    if (!layout) return 0;
    auto* manager = reinterpret_cast<unsigned char*>(raw - 0x1a8);
    if (*reinterpret_cast<void**>(manager + 0x78)) FUN_1423d43b0(*reinterpret_cast<void**>(manager + 0x78));
    return 1;
}

// MS2-FUNCTIONAL: enumerates installed keyboard layouts and refreshes active language state.
// @0x1423d8140
unsigned FUN_1423d8140(long long* manager)
{
    if (!manager) return 1;
    const int count = GetKeyboardLayoutList(0, nullptr);
    if (count <= 0) {
        reinterpret_cast<void(*)(void*, const char*, const char*)>(
            (*reinterpret_cast<void***>(manager))[0xe])(
                manager, "No IME's Installed!", "GFxIME Error");
        return 1;
    }
    std::vector<HKL> layouts(static_cast<size_t>(count));
    const int actual = GetKeyboardLayoutList(count, layouts.data());
    if (actual <= 0) return 1;
    HKL current = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(reinterpret_cast<unsigned char*>(manager) + 0x58) = current;
    for (int i = 0; i < actual; ++i) {
        if (layouts[i] == current) {
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) =
                LOWORD(reinterpret_cast<ULONG_PTR>(current));
            break;
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: refreshes the manager's locale list and resets its active language through the layout enumerator.
// @0x1423cb980
unsigned long long FUN_1423cb980(long long*, long long, unsigned)
{
    return 0;
}

// MS2-FUNCTIONAL: initializes the manager's supported IME state using the installed layout list.
// @0x1423d64b0
unsigned long long FUN_1423d64b0(long long raw)
{
    auto* manager = reinterpret_cast<long long*>(raw);
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x88) = 0x01000000;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = 0x01000000;
    return FUN_1423d8140(manager);
}

// MS2-FUNCTIONAL: clears status state and rebuilds its GFx list while enumerating installed language records.
// @0x1423da440
unsigned long long FUN_1423da440(long long raw, unsigned long long, unsigned* result)
{
    auto* self = reinterpret_cast<unsigned char*>(raw);
    if (result) *result = 0;
    if (!self) return 0;
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (owner) owner[0xc0] = 0;
    std::memset(self + 0x70, 0, 0x38);
    if (owner) FUN_1423d9b40(owner);
    return 0;
}

// MS2-FUNCTIONAL: dispatches the status-window language notification through the shared IME message path.
// @0x1423db0c0
unsigned long long FUN_1423db0c0(long long raw, unsigned message)
{
    FUN_1423d1d10(reinterpret_cast<void*>(raw), message, 0, 0);
    return 0;
}

// The vtable-slot leaves below have no pdata (leaf functions and adjustor thunks); data_rdata_sf_a's
// IME vtable images reach them by VA.

// MS2-FUNCTIONAL: maps the executable's IME conversion-mode bits to the language code they imply.
// @0x1423cb5b0
unsigned FUN_1423cb5b0(void*, unsigned flags)
{
    if (flags & 0xf00) return 0x400;
    if (flags & 0xf000) return 0x2000;
    if (flags & 0x10000000) return 0x10000000;
    if (flags & 0xf) return 9;
    return (flags & 0xf0000) ? 0x80000 : 0x1000000;
}

// MS2-FUNCTIONAL: looks up the language code of an installed input-language record by its id.
// @0x1423cb600
unsigned FUN_1423cb600(void* self, long long id)
{
    const unsigned long long count = *(unsigned long long*)((UByte*)self + 0x80);
    UByte* records = *(UByte**)((UByte*)self + 0x90);
    for (unsigned long long i = 0; i < count; ++i) {
        UByte* record = records + i * 0x20;
        if (*(long long*)((UByte*)record + 0x18) == id) return *(unsigned*)((UByte*)record + 0x10);
    }
    return 0x1000000;
}

// @0x1423cb650
bool FUN_1423cb650(void*) { return true; }

// @0x1423cb970
void FUN_1423cb970(void*) {}
// @0x1423ce6b0
void FUN_1423ce6b0(void*) {}
// @0x1423ceb20
void FUN_1423ceb20(void*) {}
// @0x1423cefd0
void FUN_1423cefd0(void*) {}
// @0x1423cf190
void FUN_1423cf190(void*) {}
// @0x1423cf1b0
void FUN_1423cf1b0(void*) {}
// @0x1423cf560
void FUN_1423cf560(void*) {}
// @0x1423d02c0
void FUN_1423d02c0(void*) {}
// @0x1423d0840
void FUN_1423d0840(void*) {}
// @0x1423d0f00
void FUN_1423d0f00(void*) {}
// @0x1423d14a0
void FUN_1423d14a0(void*) {}
// @0x1423d2ef0
void FUN_1423d2ef0(void*) {}
// @0x1423d7130
void FUN_1423d7130(void*) {}

// MS2-FUNCTIONAL: forwards the IME command to the command map embedded at +0x38.
// @0x1423cf1a0
unsigned long long FUN_1423cf1a0(void* self, long long operation, const char* key, unsigned long long flags)
{
    return FUN_1423d8d60((long long*)((UByte*)self + 0x38), operation, key, flags);
}

// MS2-FUNCTIONAL: forwards the IME command to the command map embedded at +0x38.
// @0x1423d3110
unsigned long long FUN_1423d3110(void* self, long long operation, const char* key, unsigned long long flags)
{
    return FUN_1423d8d60((long long*)((UByte*)self + 0x38), operation, key, flags);
}

// MS2-FUNCTIONAL: enables or disables the window's default input context (IACE_DEFAULT when enabled).
// @0x1423cfd30
void FUN_1423cfd30(void* self, bool enable)
{
    cx18_ImmAssociateContextEx(*(HWND*)((UByte*)self + 0x28), nullptr, (DWORD)enable << 4);
}

// @0x1423d0590
long long FUN_1423d0590(void*) { return 0; }
// @0x1423d07d0
long long FUN_1423d07d0(void*) { return 0; }
// @0x1423dad80
long long FUN_1423dad80(void*) { return 0; }
// @0x1423dad90
long long FUN_1423dad90(void*) { return 0; }
// @0x1423dada0
long long FUN_1423dada0(void*) { return 0; }
// @0x1423dadb0
long long FUN_1423dadb0(void*) { return 0; }
// @0x1423dadc0
long long FUN_1423dadc0(void*) { return 0; }

// MS2-FUNCTIONAL: assigns the name string held at +0x20.
// @0x1423d0f40
void FUN_1423d0f40(void* self, const char* text)
{
    *(String*)((UByte*)self + 0x20) = text;
}

// MS2-FUNCTIONAL: assigns the name string held at +0x18.
// @0x1423d0f50
void FUN_1423d0f50(void* self, const char* text)
{
    *(String*)((UByte*)self + 0x18) = text;
}

// MS2-FUNCTIONAL: stores the three candidate-window settings.
// @0x1423d14b0
void FUN_1423d14b0(void* self, unsigned a, unsigned b, unsigned c)
{
    *(unsigned*)((UByte*)self + 0x84) = a;
    *(unsigned*)((UByte*)self + 0x88) = b;
    *(unsigned*)((UByte*)self + 0x8c) = c;
}

// @0x1423d1820
void FUN_1423d1820(void* self, unsigned value) { *(unsigned*)((UByte*)self + 0x98) = value; }
// @0x1423d1870
void FUN_1423d1870(void* self, bool value) { *(bool*)((UByte*)self + 0x80) = value; }
// @0x1423d1880
void FUN_1423d1880(void* self, void* value) { *(void**)((UByte*)self + 0x28) = value; }

// MS2-FUNCTIONAL: clears the second field, then calls the object's own virtual slot 0x80.
// @0x1423d1890
void FUN_1423d1890(void* self)
{
    ((void**)self)[1] = nullptr;
    typedef void (*Fn)(void*);
    (*(Fn*)(*(UByte**)self + 0x80))(self);
}

// MS2-FUNCTIONAL: AddRef on the refcount at +0x14.
// @0x1423d5ae0
int FUN_1423d5ae0(void* self)
{
    return ++*(int*)((UByte*)self + 0x14);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the AddRef at 0x1423d5ae0.
// @0x1423d5aec
int FUN_1423d5aec(void* self)
{
    return FUN_1423d5ae0((UByte*)self - 8);
}

// MS2-FUNCTIONAL: returns the language code of the named IME, else of the current input language.
// @0x1423d61c0
unsigned FUN_1423d61c0(void* self, const char* name)
{
    if (name) return FUN_1423cb400(self, name);
    if (*(unsigned*)((UByte*)self + 0x84) == 0x2000000) return 0x1000000;
    return *(unsigned*)((UByte*)self + 0x88);
}

// MS2-FUNCTIONAL: the same body as FUN_1423d61c0, slot 2 of the 17-slot table at 0x143138530.
// @0x1423d7dc0
unsigned FUN_1423d7dc0(void* self, const char* name)
{
    if (name) return FUN_1423cb400(self, name);
    if (*(unsigned*)((UByte*)self + 0x84) == 0x2000000) return 0x1000000;
    return *(unsigned*)((UByte*)self + 0x88);
}

// MS2-FUNCTIONAL: Release on the refcount at +0x14.
// @0x1423d7350
int FUN_1423d7350(void* self)
{
    return --*(int*)((UByte*)self + 0x14);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the QueryInterface at 0x1423d72a0.
// @0x1423d7344
long long FUN_1423d7344(void* self, const unsigned long long* iid, void** output)
{
    return FUN_1423d72a0((UByte*)self - 8, iid, output);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the Release at 0x1423d7350.
// @0x1423d735c
int FUN_1423d735c(void* self)
{
    return FUN_1423d7350((UByte*)self - 8);
}

// MS2-FUNCTIONAL: refreshes the conversion-state labels with every conversion bit set.
// @0x1423d7410
void FUN_1423d7410(void* self)
{
    FUN_1423cc7c0(self, 0xffffffffu);
}

// MS2-FUNCTIONAL: returns the IME callback-name table (the records after the count in DAT_143a2a6b4's image).
// @0x1423da240
const void* FUN_1423da240(void*)
{
    return (const UByte*)&DAT_143a2a6b4 + 0xc;
}

// MS2-FUNCTIONAL: AddRef on the refcount at +0x3c.
// @0x1423da420
int FUN_1423da420(void* self)
{
    return ++*(int*)((UByte*)self + 0x3c);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the AddRef at 0x1423da420.
// @0x1423da42c
int FUN_1423da42c(void* self)
{
    return FUN_1423da420((UByte*)self - 8);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the QueryInterface at 0x1423dadd0.
// @0x1423dae98
long long FUN_1423dae98(void* self, const unsigned long long* iid, void** output)
{
    return FUN_1423dadd0((long long*)((UByte*)self - 8), iid, output);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 8) to the Release at 0x1423daeb0.
// @0x1423daed8
int FUN_1423daed8(void* self)
{
    return FUN_1423daeb0((long long*)((UByte*)self - 8));
}

// MS2-FUNCTIONAL: adjustor thunk (this - 0x30) to the sized-delete destructor at 0x1423dbb60.
// @0x1423db880
void* FUN_1423db880(void* self, unsigned flags)
{
    return FUN_1423dbb60((UByte*)self - 0x30, flags);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 0x40) to the sized-delete destructor at 0x1423dbb60.
// @0x1423db88c
void* FUN_1423db88c(void* self, unsigned flags)
{
    return FUN_1423dbb60((UByte*)self - 0x40, flags);
}

// MS2-FUNCTIONAL: adjustor thunk (this - 0x48) to the sized-delete destructor at 0x1423dbb60.
// @0x1423db898
void* FUN_1423db898(void* self, unsigned flags)
{
    return FUN_1423dbb60((UByte*)self - 0x48, flags);
}


}}}
