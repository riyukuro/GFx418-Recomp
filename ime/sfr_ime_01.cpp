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
#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/as3/as3_support.h"
#include "../include/gfx/xml/xml_object.h"

// Scaleform::UTF8Util::EncodeString (exe 0x1425a73c0); the shared sf_utf8util.h does not declare it.
namespace Scaleform { namespace UTF8Util { void SF_STDCALL EncodeString(char* buff, const wchar_t* chars, SPInt length); } }
namespace Scaleform { namespace UTF8Util { SPInt SF_STDCALL GetEncodeStringSize(const wchar_t* chars, SPInt length); } }
namespace Scaleform { namespace UTF8Util { void SF_STDCALL EncodeStringSafe(char* buff, UPInt buffSize, const wchar_t* chars, SPInt length); } }

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
    unsigned char pad_b8[0x10];
public:
    explicit GFxIMEManagerWin32(::HWND__* hwnd);
    virtual ~GFxIMEManagerWin32();
    // GFxManager::InitIME news the manager in the Scaleform heap (IMEManagerBase is a State), so the deleting
    // destructor 0x1423c8ce0 frees it there too, not through the CRT.
    static void operator delete(void* p) { Memory::Free(p); }
};

static_assert(offsetof(GFxIMEManagerWin32, p60) == 0x60, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, hwnd) == 0x68, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, language) == 0x88, "IME layout");
static_assert(offsetof(GFxIMEManagerWin32, conversionMode) == 0xb0, "IME layout");
static_assert(sizeof(GFxIMEManagerWin32) == 0xc8, "IME layout");   // the deleting destructor frees 0xc8 bytes

#ifndef MS2_HOOK_DLL
// The IMEManagerBase constructor (sfr_gfx_03d) and the manager's own vtable (data_rdata_sf_a): this stand-in class
// has no IMEManagerBase base, so the constructor builds the base part and installs the exe's 38-slot vtable itself,
// and the destructor tears the base part down (~IMEManagerBase).
extern "C" void FUN_1425b3e90(void* self);
extern "C" void FUN_1425b3fb0(void* self);
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
#ifndef MS2_HOOK_DLL
    // the exe's 38-slot vtable, as the constructor installs it; the view's own ??_7 has the deleting dtor only
    *reinterpret_cast<void***>(this) = DAT_1431383e0;
#endif
    if (p70)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p70))[0](p70, 1);
    if (p78)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p78))[0](p78, 1);
#ifndef MS2_HOOK_DLL
    FUN_1425b3fb0(this);
#endif
}


}}}

// MS2-PIN: ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z 0x1423c8ce0
// MS2-FUNCTIONAL ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z: frees through Memory::Free as the exe does; ~IMEManagerBase runs from the destructor body, before the String members (the exe runs it after them).

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
    if ((message == 0x101 || message == 0x202) &&
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0xb9)) {
        reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(self))[0x110 / sizeof(void*)])(
            self, -*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x64));
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0xb9) = 0;
    }
    const unsigned mode = static_cast<unsigned>(self[0x13]);
    const bool inputMode = mode == 0xd00001 || (mode >= 5 && mode <= 6) || mode == 0xa10000 || mode == 0xb10000;
    const bool clearKey = (message == 0x100 && key == 0x25) || (key >= 0x26 && key <= 0x28) || key == 0xd;
    if (!inputMode || !clearKey) return;
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
        Scaleform::GFx::Value output;
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveInputWindow", &output, nullptr, 0);
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
            Scaleform::GFx::Value output;
            if (values) {
                reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                    (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                        values, "RemoveList", &output, nullptr, 0);
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
    if (result) return result;
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
            --table[0];
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
        *reinterpret_cast<double*>(value + 16) =
            static_cast<double>(*reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x10));
        *reinterpret_cast<unsigned*>(value + 8) = 5;
        return;
    }
    // The exe returns the state's own string node at +0x18 (0x1423da18e), not the key.
    const auto text = *reinterpret_cast<const unsigned long long*>(static_cast<unsigned char*>(self) + 0x18);
    *reinterpret_cast<unsigned long long*>(value + 16) = (text & ~3ull) + 0xc;
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
    for (unsigned i = 0; i < listCount; ++i) {
        // The records are inline (stride 0x30); +0x28 heads each record's profile-copy list.
        auto* node = *reinterpret_cast<void***>(*reinterpret_cast<unsigned char**>(bytes + 0xb8) + i * 0x30ull + 0x28);
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
    // +0x1a0 is an embedded COM object (its vtable is at +0x1a0), released through slot 2.
    IUnknown* sink = reinterpret_cast<IUnknown*>(bytes + 0x1a0);
    void* remote = *reinterpret_cast<void**>(bytes + 0x1d0);
    void* queried = nullptr;
    if (*reinterpret_cast<int*>(bytes + 0x1b8) != -1) {
        if (remote && SUCCEEDED(reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(remote))[0])(remote, DAT_1431c51e8, &queried))) {
            const HRESULT hr = reinterpret_cast<HRESULT(*)(void*, unsigned)>(
                (*reinterpret_cast<void***>(queried))[4])(queried, *reinterpret_cast<unsigned*>(bytes + 0x1b8));
            if (static_cast<unsigned>(hr) == 0x80040200u) sink->Release();
            static_cast<IUnknown*>(queried)->Release();
        }
        *reinterpret_cast<int*>(bytes + 0x1b8) = -1;
    }
    if (*reinterpret_cast<int*>(bytes + 0x1b0) != -1) {
        if (remote && SUCCEEDED(reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(remote))[0])(remote, DAT_1431c51e8, &queried))) {
            reinterpret_cast<HRESULT(*)(void*, unsigned)>(
                (*reinterpret_cast<void***>(queried))[4])(queried, *reinterpret_cast<unsigned*>(bytes + 0x1b0));
            static_cast<IUnknown*>(queried)->Release();
        }
        *reinterpret_cast<int*>(bytes + 0x1b0) = -1;
    }
    sink->Release();
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

// Holds one COM interface and releases it (vtable slot 2) when it goes out of scope, including during unwind.
struct Unk_ImeComRef
{
    void* p = nullptr;
    ~Unk_ImeComRef()
    {
        if (p) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(p))[2])(p);
    }
};

// MS2-FUNCTIONAL: follows the executable's three-stage input-context COM query and releases each acquired interface.
// The exe wraps the query in catch(...) (continuation 0x1423da407 returns the result reached so far); the three
// interfaces are smart-pointer locals released in order first, second, third.
// @0x1423da320
unsigned char FUN_1423da320(void* object, void*, void*, void*)
{
    auto* bytes = static_cast<unsigned char*>(object);
    Unk_ImeComRef third;
    Unk_ImeComRef second;
    Unk_ImeComRef first;
    unsigned char result = 0;
    try {
        void* initial = *reinterpret_cast<void**>(bytes + 0x28);
        if (!initial) return 0;
        const int hr1 = reinterpret_cast<int(*)(void*, const void*, void**)>(
            (*reinterpret_cast<void***>(initial))[0])(initial, &DAT_14313b8a8, &first.p);
        if (hr1 >= 0) {
            const int hr2 = reinterpret_cast<int(*)(void*, unsigned, void**)>(
                (*reinterpret_cast<void***>(first.p))[6])(first.p,
                    *reinterpret_cast<unsigned*>(bytes + 0x64), &second.p);
            if (hr2 >= 0 && second.p) {
                const int hr3 = reinterpret_cast<int(*)(void*, const void*, void**)>(
                    (*reinterpret_cast<void***>(second.p))[0])(second.p, &DAT_14313b8c8, &third.p);
                if (hr3 >= 0 && third.p) {
                    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(third.p))[0x88 / sizeof(void*)])(third.p);
                    result = 1;
                }
            }
        }
    } catch (...) {
    }
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

// MS2-FUNCTIONAL: stores the abstract vptr, frees the member array, then runs the common IME base teardown.
// @0x1423d1b50
void FUN_1423d1b50(unsigned long long* object)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a5f8);
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

// Allocates four bytes per record and stores the new buffer at +0x190.
// @0x1423cad60
void FUN_1423cad60(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0xd0);
    // CRT new[] (0x14274863a), as the exe: the buffer is freed with operator delete[] (FUN_1423cb0f0)
    *reinterpret_cast<unsigned**>(bytes + 0x190) = new unsigned[count];
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
        FUN_1423daf30(*reinterpret_cast<void**>(bytes + 0xc8), index);
        return;
    }
    INPUT input{};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(index + 0x31);
    input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(index + 0x31, MAPVK_VK_TO_VSC));
    SendInput(1, &input, sizeof(INPUT));
}

// MS2-FUNCTIONAL: destroys GFx::Value entries in reverse order (managed values released through their object interface).
// @0x1423ce6c0
void FUN_1423ce6c0(Scaleform::GFx::Value* values, unsigned long long count)
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
    struct { void* pObjectInterface; unsigned Type; const char* pString; } value = { nullptr, 6, "Hello World" };
    FUN_142576820(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0xa0),
                  "_root.Edit_MLine1.textBox.text", reinterpret_cast<void**>(&value), 1);
    FUN_1423ca030(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0xa0),
                  "Selection.setSelection", "%d %d", 5, 5);
}

// MS2-FUNCTIONAL: attaches the movie: notifies the object at +0x18 (vtable slot 0x90) and the current IME child at
// +0x70 (slot 1, with the movie), then publishes the operating-system label to an AVM version 1 movie as
// _global.gfx_ime_os_version (a GFx::Value string, laid out raw).
// @0x1423ca410
void FUN_1423ca410(void* self, void* movie)
{
    // IMEManagerBase::SetActiveMovie(self, movie)
    reinterpret_cast<void(*)(void*, void*)>(&FUN_1425b49b0)(self, movie);
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

// MS2-FUNCTIONAL: stores the manager vftable, destroys the XML node chain, then releases the arrays, the packed string, the
// four member arrays and the hash table (entries marked empty, then freed) in executable order.
// @0x1423c8bb0
void FUN_1423c8bb0(unsigned long long* object)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_143138360);
    FUN_1423cb0f0(object);
    if (object[0x2e]) Memory::Free(reinterpret_cast<void*>(object[0x2e]));
    if (object[0x2b]) Memory::Free(reinterpret_cast<void*>(object[0x2b]));
    FUN_1423c9330(object[0x17], object[0x18]);
    if (object[0x17]) Memory::Free(reinterpret_cast<void*>(object[0x17]));
    if (object[0x12]) Memory::Free(reinterpret_cast<void*>(object[0x12]));
    Sfr33ReleasePacked(object[0xe]);
    FUN_1422fbf60(object + 0xb);
    FUN_1422fbf60(object + 8);
    FUN_1422fbf60(object + 5);
    FUN_1422fbf60(object + 2);
    if (object[1]) {
        auto* table = reinterpret_cast<unsigned long long*>(object[1]);
        for (unsigned long long i = 0, n = table[1] + 1; i < n; ++i) {
            unsigned long long* entry = reinterpret_cast<unsigned long long*>(object[1]) + 2 + i * 2;
            if (entry[0] != 0xfffffffffffffffeull)
                entry[0] = 0xfffffffffffffffeull;
        }
        Memory::Free(reinterpret_cast<void*>(object[1]));
        object[1] = 0;
    }
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
    data[length] = item;
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
        if (status == static_cast<int>(0x80040200u))
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
        if (status == static_cast<int>(0x80040200u))
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
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a450);
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
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a210);
    const unsigned long long count = object[0x10a];
    auto* entries = reinterpret_cast<unsigned long long*>(object[0x109]);
    for (unsigned long long i = count; i; --i)
        if (entries[i - 1]) FUN_14257dcd0(reinterpret_cast<void*>(entries[i - 1]));
    Memory::Free(entries);
    FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::Value*>(object[0x105]), object[0x106]);
    if (object[0x105]) Memory::Free(reinterpret_cast<void*>(object[0x105]));
    FUN_1422fbf60(object + 0x102);
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a1d8);
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
        if (length < (capacity >> 1))
            FUN_1423d95f0(array, allocator, length);
    } else if (length >= capacity) {
        FUN_1423d95f0(array, allocator, (length >> 2) + length);
    }
    array[1] = length;
}

void FUN_1423d12e0(unsigned long long* array, void*, unsigned long long count);

// MS2-FUNCTIONAL: resizes the executable's Value array, destructing removed entries before changing its capacity.
// @0x1423d9730
extern "C" void FUN_1423d9730(void* rawArray, void* allocator, unsigned long long length)
{
    auto* array = static_cast<unsigned long long*>(rawArray);
    if (length < array[1]) {
        FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::Value*>(array[0] + length * 0x20), array[1] - length);
        if (length < (array[2] >> 1)) FUN_1423d12e0(array, allocator, length);
    } else if (length >= array[2]) {
        FUN_1423d12e0(array, allocator, (length >> 2) + length);
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
    }
    *command = 0;
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
            if (status == static_cast<int>(0x80040200u))
                (*reinterpret_cast<void(***)(void*)>(bytes + 0x1a0))[2](bytes + 0x1a0);  // the embedded interface at +0x1a0
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
    } else if (strcmp(name, "Tag") == 0) {
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
            if (!layout) continue;
            *reinterpret_cast<HKL*>(bytes + 0x198) = layout;
            ActivateKeyboardLayout(layout, 0);
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
        if (!context) {
            cx18_ImmReleaseContext(hwnd, nullptr);
            return 0;
        }
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
        if (!context) {
            cx18_ImmReleaseContext(hwnd, nullptr);
            return 0;
        }
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
    if (!enabled && composition > 0)
        *reinterpret_cast<unsigned char*>(self + 0xc0) = 1;
    if (composition != 0) return;

    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC oldContext = cx18_ImmGetContext(hwnd);
    String language;
    void* languageSource = *reinterpret_cast<void**>(self + 0xa8);
    reinterpret_cast<void(*)(void*, String*)>((*reinterpret_cast<void***>(languageSource))[0x50 / sizeof(void*)])(
        languageSource, &language);
    const bool korean = std::strcmp(language.ToCStr(), "Korean") == 0;
    cx18_ImmAssociateContextEx(hwnd, nullptr, static_cast<DWORD>(enabled) << 4);
    HIMC context = cx18_ImmGetContext(hwnd);
    DWORD conversion = 0;
    DWORD sentence = 0;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    if (!korean) {
        conversion = enabled ? (conversion | 1u) : (conversion & ~1u);
        sentence = static_cast<DWORD>(enabled) << 3;
    } else {
        sentence = 0;
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
            auto* node = *reinterpret_cast<unsigned char***>(entries + i * 0x30 + 0x28);
            auto* record = node[0];
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
                        Scaleform::GFx::Value output;
                        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                                values, "RemoveList", &output, nullptr, 0);
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
                        Scaleform::GFx::Value output;
                        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                                values, "RemoveInputWindow", &output, nullptr, 0);
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

// MS2-FUNCTIONAL: reads the active keyboard layout into [+0x198], maps it to the language id at [+0x84] and shows its
// locale name. For a plain layout (HKL & 0xe0000000 == 0) it sets mode 0x1000000 and shows the "Layout Text" of the
// registry layout record whose id matches the HKL's high word, else the locale name; for an IME layout it shows the
// IME's mode text through FUN_1423cc2d0.
// @0x1423d8870
void FUN_1423d8870(unsigned long long* manager)
{
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    manager[0x33] = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0));
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    const unsigned language = reinterpret_cast<unsigned(*)(void*, short)>(vtable[4])(
        manager, static_cast<short>(manager[0x33]));
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = language;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), language);
    wchar_t locale[0x104];
    if (!GetLocaleInfoW(static_cast<unsigned short>(manager[0x33]), LOCALE_SLANGUAGE, locale, 0x104)) {
        reinterpret_cast<void(*)(void*, DWORD, const char*)>(vtable[0x78 / sizeof(void*)])(
            manager, GetLastError(), "GFxIME Error: Error Initializing Input Language Name ");
        void* languageObject = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(languageObject))[0x78 / sizeof(void*)])(
            languageObject, "Unsupported");
        return;
    }
    {
        String localeText(locale);
        void* languageObject = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(languageObject))[0x78 / sizeof(void*)])(
            languageObject, localeText.ToCStr());
    }
    if (manager[0x33] & 0xe0000000) {
        FUN_1423cc2d0(manager);
        return;
    }
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x88) = 0x1000000;
    const unsigned count = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x160);
    const auto* records = reinterpret_cast<const LayoutRecord*>(manager[0x2b]);
    const unsigned layoutId = static_cast<unsigned short>(manager[0x33] >> 16);
    for (unsigned i = 0; i < count; ++i) {
        if (records[i].layoutId == layoutId) {
            String layoutText(records[i].layoutText);
            FUN_1423ccdc0(manager, &layoutText);
            return;
        }
    }
    String localeText(locale);
    FUN_1423ccdc0(manager, &localeText);
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
    *reinterpret_cast<double*>(argBytes + 0x10) = static_cast<double>(static_cast<long long>(item));
    using Invoke = void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned);
    // The exe rereads the bridge for each call and rebuilds ".SetList" even without one (0x1423d992f).
    auto bridgeOf = [self]() {
        void* movie = *reinterpret_cast<void**>(self + 0x868);
        void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
        return *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    };
    if (void* bridge = bridgeOf())
        reinterpret_cast<Invoke>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, command, &result, &argument, 1);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, 0x400, ".SetList");
    if (void* bridge = bridgeOf())
        reinterpret_cast<Invoke>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, command, &result, nullptr, 0);
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
        if (hr == S_OK && id.vt != VT_I4) hr = static_cast<HRESULT>(0x80004005u);
        else if (hr == S_OK) {
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

// The destructor call is qualified: self->~MemoryContextImpl() is a virtual call through slot 0, back into this
// deleting destructor.
// MS2-FUNCTIONAL: uses our AS3 memory context declaration to release its heap limit handler, owned references, and allocated storage.
// @0x1423dbd20
void* FUN_1423dbd20(Scaleform::GFx::AS3::MemoryContextImpl* self, unsigned flags)
{
    self->MemoryContextImpl::~MemoryContextImpl();
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
        for (unsigned index = 0;; ++index) {
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
                if (_InterlockedDecrement(refs) == 0) {
                    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
                    reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60,
                        reinterpret_cast<void*>(packed & ~3ull));
                }
                return 1;
            }
        }
    }
    auto* refs = reinterpret_cast<volatile long*>((*stringInfo & ~3ull) + 8);
    if (_InterlockedDecrement(refs) == 0) {
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

    // The exe creates the thread manager straight into +0x1d0 (0x1423d5505) and keeps that reference:
    // the dtor and FUN_1423d7610/FUN_1423d7690 unadvise the sinks through it.
    void** managerSlot = reinterpret_cast<void**>(self + 0x3a);
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4858), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c4d28), managerSlot);
    if (FAILED(hr)) return self;
    void* manager = *managerSlot;

    void* provider = nullptr;
    auto** managerVtable = *reinterpret_cast<void***>(manager);
    hr = reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(managerVtable[0])(
        manager, DAT_1431c51e8, &provider);
    if (FAILED(hr)) {
        // Released but left in +0x1d0, as in the exe (0x1423d5585 -> 0x1423d5673).
        reinterpret_cast<ULONG(*)(void*)>(managerVtable[2])(manager);
        return self;
    }
    if (provider) {
        auto** providerVtable = *reinterpret_cast<void***>(provider);
        HRESULT result = reinterpret_cast<HRESULT(*)(void*, const void*, void*, void*)>(providerVtable[3])(
            provider, DAT_14313b400, self + 0x35, self + 0x36);
        if (FAILED(result)) *reinterpret_cast<unsigned*>(self + 0x36) = 0xffffffffu;
        void* language = nullptr;
        hr = reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(managerVtable[0])(
            manager, DAT_1431c5028, &language);
        if (SUCCEEDED(hr) && language) {
            // DAT_14313b410 and DAT_14313b418 are the two halves of one GUID, but separate pieces in the fullexe.
            const unsigned long long compartment[2] = {DAT_14313b410, DAT_14313b418};
            reinterpret_cast<HRESULT(*)(void*, const void*, void**)>(
                (*reinterpret_cast<void***>(language))[3])(language, compartment,
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
    // the base vtable at 0x14313a258 is the p20 member of the DAT_14313a238 piece; DAT_14313a228 is a separate
    // 0x18-byte piece in the fullexe, so DAT_14313a228 + 6 landed in another table
    self[0] = reinterpret_cast<unsigned long long>(DAT_14313a238 + 4);
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
    if (!*reinterpret_cast<unsigned char*>(self + 0x10)) {
        if (*value) FUN_14257dcd0(*value);
        return;
    }
    if (!*value) return;

    // The command goes in the member buffer at +0x410; the descriptor and argument arrays are the
    // pointers stored at +0x828/+0x810, and .Add gets the descriptors with the count at +0x830 (0x1423d9ac3).
    char* command = reinterpret_cast<char*>(self + 0x410);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, 0x400, ".Add");
    for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x818); ++i) {
        void* input = *value;
        reinterpret_cast<void(*)(void*, void*, void*)>((*reinterpret_cast<void***>(input))[1])(input,
            *reinterpret_cast<unsigned char**>(self + 0x828) + i * 0x20,
            *reinterpret_cast<unsigned char**>(self + 0x810) + i * sizeof(void*));
    }
    void* movie = *reinterpret_cast<void**>(self + 0x868);
    void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
    void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    Scaleform::GFx::Value result;
    if (bridge)
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(bridge, command, &result,
                *reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828), *reinterpret_cast<unsigned*>(self + 0x830));
    command[0] = 0;
    FUN_14257dcd0(*value);
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
        // The exe sends each key separately with cbSize = sizeof(inputs) (0x50), which SendInput rejects, so no
        // Escape actually reaches the window.
        SendInput(1, &inputs[0], sizeof(inputs));
        SendInput(1, &inputs[1], sizeof(inputs));
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
                unsigned long long previous = ~0ull;
                unsigned long long current = home;
                for (;;) {
                    if (entry[1] == home && std::strcmp(reinterpret_cast<const char*>(entry[2]), key) == 0) {
                        const unsigned long long next = entry[0];
                        if (current == home) {
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
                    previous = current;
                    current = next;
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
        if (!language || _stricmp(name->ToCStr(), language) != 0) continue;
        if (reinterpret_cast<unsigned(*)(void*, unsigned)>(vtable[3])(
                manager, *reinterpret_cast<unsigned*>(entry + 0x20)) != mode) continue;

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
    *reinterpret_cast<Scaleform::String*>(bytes + 0x70) += Scaleform::String(text) + "@@";
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
    // "false" clears the flag, "true" sets it; any other value leaves it alone.
    const bool isFalse = std::strcmp(value, "false") == 0;
    const bool isTrue = std::strcmp(value, "true") == 0;
    if (std::strcmp(command, "StatusWindow_OnShape") == 0) {
        if (isFalse) conversion &= ~8u;
        if (isTrue) conversion |= 8u;
    } else if (std::strcmp(command, "StatusWindow_OnInputMode") == 0) {
        if (isFalse) conversion &= ~1u;
        if (isTrue) conversion |= 1u;
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
            if (!cx18_ImmGetOpenStatus(context)) cx18_ImmSetOpenStatus(context, TRUE);
            conversion &= ~9u;
        } else if (std::strcmp(value, "DirectInput") == 0 && cx18_ImmGetOpenStatus(context)) {
            cx18_ImmSetOpenStatus(context, FALSE);
        }
    } else if (std::strcmp(command, "StatusWindow_OnSymbol") == 0) {
        if (isFalse) conversion &= ~0x400u;
        if (isTrue) conversion |= 0x400u;
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
            if (log) FUN_1423cd060(log, Scaleform::String(
                "\n Failure in COM, perhaps you called CoCreateInstance in another thread... ").ToCStr());
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
        // The exe logs through FUN_1423cd060 (log vtable slot 1), the second line as one String.
        FUN_1423cd060(log, "\nCould not find requested IME in supported IME list!");
        FUN_1423cd060(log, (Scaleform::String("\n--> You requested: ") + requested).ToCStr());
    }
}

// MS2-FUNCTIONAL: the exe body is instruction-for-instruction the same as FUN_1423d7e80 (StatusWindow mode updates through IMM32).
// @0x1423d61f0
void FUN_1423d61f0(void* manager, const char* command, const char* value)
{
    FUN_1423d7e80(manager, command, value);
}

// WM_IME_STARTCOMPOSITION of the IMM IME object (vtbl 0x14313a5f8; the Vista twin is 0x1423d05a0). Starts the
// composition, resets the candidate counters (+0xcc/+0x64/+0xd4), the target clause (+0x5a4), the reading text (+0x40)
// and the four-space mode buffer (+0xb0), stores the layout and its at-caret flag (+0x5a0, forced by the modes), and
// moves the IMM composition and candidate windows off screen, or for mode 0x1000000 to the cursor rect the owner
// (vtbl+0x190) maps. True unless mode 0x1000000.
// MS2-FUNCTIONAL: the exe keeps an unused GFx::Value local
// @0x1423d43b0
bool FUN_1423d43b0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner) return false;
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10)->GetIMEManager();
    ime->StartComposition();
    *reinterpret_cast<unsigned*>(self + 0xcc) = 0;
    *reinterpret_cast<unsigned*>(self + 0x64) = 0;
    *reinterpret_cast<unsigned*>(self + 0xd4) = 0;
    *reinterpret_cast<unsigned*>(self + 0x5a4) = 1;
    std::memset(*reinterpret_cast<void**>(self + 0x40), 0, 0x100);
    auto* modeBuffer = *reinterpret_cast<wchar_t**>(self + 0xb0);
    modeBuffer[0] = modeBuffer[1] = modeBuffer[2] = modeBuffer[3] = L' ';
    modeBuffer[4] = 0;
    HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(self + 0x58) = layout;
    auto& atCaret = *reinterpret_cast<unsigned*>(self + 0x5a0);
    atCaret = cx18_ImmGetProperty(layout, IGP_PROPERTY) >> 0x12 & 1;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0xd00001) atCaret = 0;
    else if (mode == 0xa10000 || mode == 0xb10000 || mode == 6) atCaret = 1;

    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    POINT position = { -1000, -1000 };
    if (mode == 0x1000000) {
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> metrics =
            reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10)->GetIMEManager();
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        if (metrics) {
            metrics->GetMetrics(&viewRect, &cursorRect, 0);
            Scaleform::Render::RectF mapped(0, 0, 0, 0);
            const auto* screen = reinterpret_cast<const Scaleform::Render::RectF*(*)(
                void*, Scaleform::Render::RectF*, const Scaleform::Render::RectF*, int)>(
                    (*reinterpret_cast<void***>(owner))[0x190 / sizeof(void*)])(owner, &mapped, &cursorRect, 0);
            position.x = static_cast<LONG>(screen->x1);
            position.y = static_cast<LONG>(screen->y2);
        }
        WINDOWINFO info;
        GetWindowInfo(hwnd, &info);
    }
    CANDIDATEFORM candidate;
    candidate.dwIndex = 0;
    candidate.dwStyle = CFS_CANDIDATEPOS;
    candidate.ptCurrentPos = position;
    COMPOSITIONFORM composition;
    composition.dwStyle = CFS_FORCE_POSITION;
    composition.ptCurrentPos = position;
    cx18_ImmSetCompositionWindow(context, &composition);
    cx18_ImmSetCandidateWindow(context, &candidate);
    cx18_ImmReleaseContext(hwnd, context);
    return mode != 0x1000000;
}

// MS2-FUNCTIONAL: WM_IME_STARTCOMPOSITION of the Vista IME object (vtbl 0x14313a450 slot 11; the XP twin is
// 0x1423d43b0, whose +0x5a0/+0x5a4 fields lie past this 0xe8-byte object). Starts the composition, stores the
// layout and its at-caret flag (+0xdc, forced by the modes), and moves the IMM composition and candidate windows
// off screen, or for mode 0x1000000 to the cursor rect the owner (vtbl+0x190) maps. True unless mode 0x1000000.
// @0x1423d05a0
bool FUN_1423d05a0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10)->GetIMEManager();
    self[0xb8] = 1;
    ime->StartComposition();
    self[0xb8] = 1;
    HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(self + 0x58) = layout;
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    auto& atCaret = *reinterpret_cast<unsigned*>(self + 0xdc);
    atCaret = cx18_ImmGetProperty(layout, IGP_PROPERTY) >> 0x12 & 1;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0xd00001 || mode == 5) atCaret = 0;
    if (mode == 0xa10000 || mode == 0xb10000) atCaret = 1;
    POINT position = { -1000, -1000 };
    if (mode == 0x1000000 && owner) {
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> metrics =
            reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10)->GetIMEManager();
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        if (metrics) {
            metrics->GetMetrics(&viewRect, &cursorRect, 0);
            Scaleform::Render::RectF mapped(0, 0, 0, 0);
            const auto* screen = reinterpret_cast<const Scaleform::Render::RectF*(*)(
                void*, Scaleform::Render::RectF*, const Scaleform::Render::RectF*, int)>(
                    (*reinterpret_cast<void***>(owner))[0x190 / sizeof(void*)])(owner, &mapped, &cursorRect, 0);
            position.x = static_cast<LONG>(screen->x1);
            position.y = static_cast<LONG>(screen->y2);
        }
    }
    CANDIDATEFORM candidate;
    candidate.dwIndex = 0;
    candidate.dwStyle = CFS_CANDIDATEPOS;
    candidate.ptCurrentPos = position;
    COMPOSITIONFORM composition;
    composition.dwStyle = CFS_FORCE_POSITION;
    composition.ptCurrentPos = position;
    cx18_ImmSetCompositionWindow(context, &composition);
    cx18_ImmSetCandidateWindow(context, &candidate);
    cx18_ImmReleaseContext(hwnd, context);
    return mode != 0x1000000;
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
        // The exe never tests the first character as a delimiter (0x1423d9fc0 reads [rsi+1]).
        for (const char* cursor = value + 1;; ++cursor) {
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

// MS2-FUNCTIONAL: maps a GFxIME_* label from the executable IME table to its loaded record and selects that IME.
// @0x1423d7420
unsigned long long FUN_1423d7420(unsigned long long* manager, unsigned long long* packedName)
{
    for (unsigned index = 0;; ++index) {
        const auto* entry = DAT_143a2a3e0 + index * 0x10;
        const unsigned code = *reinterpret_cast<const unsigned*>(entry + 8);
        if (code == 0x02000000) break;
        const char* name = reinterpret_cast<const char*>((*packedName & ~3ull) + 0xc);
        if (std::strcmp(name, *reinterpret_cast<const char* const*>(entry)) != 0) continue;
        const unsigned count = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0xd0);
        for (unsigned i = 0; i < count; ++i) {
            auto* record = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
            if (*reinterpret_cast<unsigned*>(record + 0x20) != code) continue;
            auto** vtable = reinterpret_cast<void**>(manager[0]);
            const unsigned state = reinterpret_cast<unsigned*>(manager[0x32])[i];
            if (state == 1 || state == 2) {
                *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) =
                    reinterpret_cast<unsigned(*)(void*)>(vtable[3])(manager);
                for (unsigned mode = 0; mode < manager[0x13]; ++mode) {
                    auto* item = reinterpret_cast<unsigned char*>(manager[0x12]) + mode * 0x20;
                    if (*reinterpret_cast<unsigned*>(item + 0x10) ==
                        *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84))
                        reinterpret_cast<void(*)(void*, const char*)>(vtable[9])(
                            manager, *reinterpret_cast<const char**>(item));
                }
            }
            const unsigned selected = reinterpret_cast<unsigned*>(manager[0x32])[i];
            if (selected != 1 && selected != 2) continue;
            record = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
            const unsigned long long field = *reinterpret_cast<unsigned long long*>(record + (selected == 1 ? 0x10 : 0x18));
            reinterpret_cast<void(*)(void*, const char*)>(vtable[8])(manager,
                reinterpret_cast<const char*>((field & ~3ull) + 0xc));
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
    reinterpret_cast<unsigned char*>(words)[0x80] = 1;
    *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(words) + 0x84) = 0x14;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0x8c) = 0x00ffffff;
    words[0xb] = 0;
    *reinterpret_cast<unsigned*>(words + 0xc) = 0;

    // the text buffer is resized to 0x100 wchar_ts: empty, so it reserves 0x140 (the exe's grow step) from the
    // owner's heap and terminates the first entry
    FUN_1423d1380(words + 8, words + 8, 0x140);
    words[9] = 0x100;
    *reinterpret_cast<wchar_t*>(words[8]) = 0;
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

// The exe's Zhuyin (Bopomofo) key table at 0x14313a720 (41 records of {key, bopomofo char, class}); a copy, so
// the fullexe does not bind an extern DAT_ to a placeholder.
static const unsigned cx18_ZhuyinKeys[41][3] = {
    { 'A', 0x3107, 0 }, { 'B', 0x3116, 0 }, { 'C', 0x310f, 0 }, { 'D', 0x310e, 0 }, { 'E', 0x310d, 0 },
    { 'F', 0x3111, 0 }, { 'G', 0x3115, 0 }, { 'H', 0x3118, 0 }, { 'I', 0x311b, 2 }, { 'J', 0x3128, 1 },
    { 'K', 0x311c, 2 }, { 'L', 0x3120, 2 }, { 'M', 0x3129, 1 }, { 'N', 0x3125, 0 }, { 'O', 0x311f, 2 },
    { 'P', 0x3123, 2 }, { 'Q', 0x3106, 0 }, { 'R', 0x3110, 0 }, { 'S', 0x310b, 0 }, { 'T', 0x3114, 0 },
    { 'U', 0x3127, 1 }, { 'V', 0x3112, 0 }, { 'W', 0x310a, 0 }, { 'X', 0x310c, 0 }, { 'Y', 0x3117, 0 },
    { 'Z', 0x3108, 0 }, { '1', 0x3105, 0 }, { '2', 0x3109, 0 }, { '3', 0x2c7, 3 }, { '4', 0x2cb, 3 },
    { '5', 0x3113, 0 }, { '6', 0x2ca, 3 }, { '7', 0x2d9, 3 }, { '8', 0x311a, 2 }, { '9', 0x311e, 2 },
    { '0', 0x3122, 2 }, { ',', 0x311d, 2 }, { '.', 0x3121, 2 }, { '/', 0x3125, 2 }, { ';', 0x3124, 2 },
    { '-', 0x3126, 2 }
};

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
    words[0xb] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xd4) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x60) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xa0) = 0;
    words[0xb6] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x5a0) = 1;
    bytes[0x5bc] = 0;

    // both text buffers are resized to 0x100 wchar_ts: empty, so each reserves 0x140 (the grow step) through its
    // AllocatorLH Reserve (the owner's heap), +0xb0 first. The buffers are not cleared.
    FUN_1423d5340(words + 0x16, words + 0x16, 0x140);
    words[0x17] = 0x100;
    FUN_1423d1380(words + 8, words + 8, 0x140);
    words[9] = 0x100;

    // the key -> {key, bopomofo, class} records at +0xd8, indexed by tolower(key) - 0x20
    for (const auto& rec : cx18_ZhuyinKeys) {
        const int index = tolower(static_cast<signed char>(rec[0])) - 0x20;
        for (int k = 0; k < 3; ++k)
            *reinterpret_cast<unsigned*>(bytes + 0xd8 + 12 * index + 4 * k) = rec[k];
    }
    return raw;
}

// MS2-FUNCTIONAL: rebuilds the AS3 status list by clearing it, replaying retained row callbacks, and restoring selection.
// @0x1423d9b40
void FUN_1423d9b40(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    const char* prefix = reinterpret_cast<const char*>(self + 0x10);
    if (!*prefix) return;
    // The exe builds every command in the member buffer at +0x410 and rereads the bridge per call.
    char* command = reinterpret_cast<char*>(self + 0x410);
    using Invoke = void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned);
    auto bridgeOf = [self]() {
        void* movie = *reinterpret_cast<void**>(self + 0x868);
        void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
        return *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    };
    auto invoke = [](void* bridge, const char* name, Scaleform::GFx::Value* out,
                     const Scaleform::GFx::Value* args, unsigned count) {
        reinterpret_cast<Invoke>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, name, out, args, count);
    };

    Scaleform::GFx::Value result;
    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".ClearList");
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, nullptr, 0);
    command[0] = 0;

    // SelectDataItem goes out before the rows are added (0x1423d9bea), SetList after them.
    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".SelectDataItem");
    Scaleform::GFx::Value argument;
    auto* argBytes = reinterpret_cast<unsigned char*>(&argument);
    *reinterpret_cast<unsigned*>(argBytes + 8) = Scaleform::GFx::Value::VT_Number;
    *reinterpret_cast<double*>(argBytes + 0x10) =
        static_cast<double>(*reinterpret_cast<long long*>(self + 0x860));
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, &argument, 1);

    for (unsigned row = 0; row < *reinterpret_cast<unsigned long long*>(self + 0x850); ++row) {
        auto* rows = *reinterpret_cast<void***>(self + 0x848);
        if (rows[row]) ++*reinterpret_cast<int*>(static_cast<unsigned char*>(rows[row]) + 8);
        void* callback = rows[row];
        if (*prefix && callback) {
            strcpy_s(command, 0x400, prefix);
            strcat_s(command, 0x400, ".Add");
            auto** callbackVtable = *reinterpret_cast<void***>(callback);
            for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x818); ++i)
                reinterpret_cast<void(*)(void*, void*, void*)>(callbackVtable[1])(callback,
                    *reinterpret_cast<unsigned char**>(self + 0x828) + i * 0x20,
                    *reinterpret_cast<unsigned char**>(self + 0x810) + i * sizeof(void*));
            Scaleform::GFx::Value added;
            if (void* bridge = bridgeOf())
                invoke(bridge, command, &added,
                    *reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828),
                    *reinterpret_cast<unsigned*>(self + 0x830));
            command[0] = 0;
        }
        if (callback) FUN_14257dcd0(callback);
    }

    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".SetList");
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, nullptr, 0);
    command[0] = 0;
}

// MS2-FUNCTIONAL: retrieves the IMM candidate list, converts its UTF-16 entries from the page start to the end of the
// list, and refreshes the movie's candidate list. The selection is max(dwSelection - dwPageStart, 0) for the candidate
// modes, else -1.
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
    for (int i = static_cast<int>(candidates->dwPageStart); i < static_cast<int>(candidates->dwCount); ++i) {
        const DWORD offset = candidates->dwOffset[i];
        if (offset > fetched || offset < offsetof(CANDIDATELIST, dwOffset)) break;
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
            ++*reinterpret_cast<int*>(item + 1);
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
        const int relative = static_cast<int>(candidates->dwSelection - candidates->dwPageStart);
        selected = relative > 0 ? relative : 0;
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

// MS2-FUNCTIONAL: IMM candidate-list update of the Vista IME object (vtable slot 36). It stores the count at +0xd8, the
// page start at +0x70 and the page size at +0x6c, recreates the movie list with RemoveList() and
// CreateList(pageSize, +0xdc), and refills the manager's list at +0x30 with the entries from the page start to the end
// of the list as UTF-8. The selection is dwSelection % dwPageSize for the candidate modes, else -1. Like the exe, it
// does not release the context when the list is empty and releases it twice after a fill.
// @0x1423d0850
void FUN_1423d0850(void* raw, DWORD listIndex)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* candidates = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(bytes));
    const DWORD fetched = cx18_ImmGetCandidateListW(context, listIndex, candidates, bytes);
    *reinterpret_cast<DWORD*>(self + 0xd8) = candidates->dwCount;
    *reinterpret_cast<DWORD*>(self + 0x70) = candidates->dwPageStart;
    const DWORD pageSize = candidates->dwPageSize;
    const DWORD selection = candidates->dwSelection;
    cx18_ImmReleaseContext(hwnd, context);
    if (candidates->dwCount == 0) {
        Scaleform::Memory::Free(candidates);
        return;
    }
    *reinterpret_cast<DWORD*>(self + 0x6c) = pageSize;

    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveList", &result, nullptr, 0);
    }
    {
        Scaleform::GFx::Value args[2];
        args[0] = Scaleform::GFx::Value(static_cast<double>(pageSize));
        args[1] = Scaleform::GFx::Value(static_cast<double>(*reinterpret_cast<int*>(self + 0xdc)));
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "CreateList", &result, args, 2);
    }

    void* list = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d9500(list);
    for (int i = static_cast<int>(candidates->dwPageStart); i < static_cast<int>(candidates->dwCount); ++i) {
        const DWORD offset = candidates->dwOffset[i];
        if (offset > fetched || offset < offsetof(CANDIDATELIST, dwOffset)) break;
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(reinterpret_cast<const unsigned char*>(candidates) + offset);
        const SPInt size = Scaleform::UTF8Util::GetEncodeStringSize(wide, -1);
        char* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size) + 1));
        Scaleform::UTF8Util::EncodeStringSafe(text, static_cast<Scaleform::UPInt>(size) + 1, wide, -1);
        text[size] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            FUN_1423cdb60(item, text);
            ++*reinterpret_cast<int*>(item + 1);
        }
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(list, &retained);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
    Scaleform::Memory::Free(candidates);
    cx18_ImmReleaseContext(hwnd, context);

    long long selected = -1;
    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    if (state == 0x110000 || state == 0x210000 || state == 0xd00800 ||
        state == 0xd00900 || state == 0xd00a00 || state == 0xd10000)
        selected = static_cast<int>(selection) % static_cast<int>(pageSize);
    FUN_1423d97f0(list, static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(list);
    *reinterpret_cast<unsigned char*>(self + 0xb9) = 1;
}

static void cx18_InvokeInputWindow(unsigned char* self, const char* name, Scaleform::GFx::Value* args, unsigned count);
void FUN_1423d5060(void* raw, int);

// Candidate list modes whose selection is shown relative to the visible page (the others select nothing, -1).
static bool cx18_CandidateSelectsInPage(unsigned mode)
{
    return (mode == 2 || mode == 4 || mode == 10) || (mode & 0xf00) || mode == 0x40000 || mode == 0x70000 ||
        mode == 0x110000 || mode == 0x210000 || mode == 0x410000 || mode == 0xd10000;
}

// Fills the candidate list object (+0x30) with the UTF-8 rows [first, first + visible) of an IMM candidate list.
static void cx18_FillCandidateRows(unsigned char* self, const CANDIDATELIST* list, int first, int visible)
{
    void* output = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d9500(output);
    for (int i = 0; i < visible; ++i) {
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(
            reinterpret_cast<const unsigned char*>(list) + list->dwOffset[first + i]);
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(wide, -1));
        auto* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size + 1)));
        Scaleform::UTF8Util::EncodeString(text, wide, -1);
        text[size] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            FUN_1423cdb60(item, text);
            ++*reinterpret_cast<int*>(item + 1);
        }
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(output, &retained);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
}

// Candidate list update of the IMM IME object (IMN_CHANGECANDIDATE). Reads IMM candidate list listIndex, stores its
// count (+0xcc), the page size (+0xd4, never shrinking) and the first visible row (+0x70: the page start, or the
// selection's page for the 0xf00 modes). An empty list calls RemoveList; otherwise the mode decides the visible rows
// (0x410000: up to five from the selection; 0x60000: from the selection; else one page), they replace the rows of
// the list object at +0x30, the selection is set (relative to the page in the paging modes, else -1) and +0x5bc
// marks the list shown.
// MS2-FUNCTIONAL: the exe releases the input context a second time after the rows (kept), and an unused Value local
// @0x1423d3120
void FUN_1423d3120(void* raw, DWORD listIndex)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* list = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(bytes) * 0x1c));
    cx18_ImmGetCandidateListW(context, listIndex, list, bytes);
    *reinterpret_cast<DWORD*>(self + 0xcc) = list->dwCount;
    const int osPage = static_cast<int>(list->dwPageSize);
    const int selection = static_cast<int>(list->dwSelection);
    int& page = *reinterpret_cast<int*>(self + 0xd4);
    if (page <= osPage) page = osPage;
    int& first = *reinterpret_cast<int*>(self + 0x70);
    first = static_cast<int>(list->dwPageStart);
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode & 0xf00) first = selection - selection % page;
    cx18_ImmReleaseContext(hwnd, context);
    const int count = *reinterpret_cast<int*>(self + 0xcc);
    if (!count) {
        cx18_InvokeInputWindow(self, "RemoveList", nullptr, 0);
        Scaleform::Memory::Free(list);
        return;
    }
    int visible;
    if (mode == 0x410000) {
        visible = count;
        if (5 < count && 5 < count - selection) visible = 5;
        else if (5 < count) visible = count - selection;
        first = selection;
    } else {
        visible = osPage;
        if (mode == 0x40000) {
            if (count - first <= osPage) visible = count - first;
        } else if (mode == 0x60000) {
            first = selection;
            if (count - selection <= osPage) visible = count - selection;
        } else {
            visible = count;
            if (mode != 0xd00001 && osPage <= count) {
                visible = osPage;
                if (count - first <= osPage) visible = count - first;
            }
        }
    }
    cx18_FillCandidateRows(self, list, first, visible);
    Scaleform::Memory::Free(list);
    cx18_ImmReleaseContext(hwnd, context);
    long long selected = -1;
    if (cx18_CandidateSelectsInPage(*reinterpret_cast<unsigned*>(self + 0x98))) {
        const int inPage = selection - first;
        selected = inPage < 0 ? 0 : inPage;
    }
    void* output = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d97f0(output, static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(output);
    self[0x5bc] = 1;
}

// Candidate list open of the IMM IME object (IMN_OPENCANDIDATE). Like 0x1423d3120, but the page size (+0xd4) is the
// list's own, mode 0x410000 shows at most five rows, the visible row count goes to +0x6c, the list window is rebuilt
// (RemoveList, then CreateList(page size, at-caret flag +0x5a0)) and the selection is its index within the page.
// An empty list does nothing.
// MS2-FUNCTIONAL: the exe builds the CreateList arguments in a heap Value array, releases the input context a
// second time after the rows (kept), and keeps an unused Value local
// @0x1423d46f0
void FUN_1423d46f0(void* raw, DWORD listIndex)
{
    auto* self = static_cast<unsigned char*>(raw);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* list = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(bytes) * 0x1c));
    cx18_ImmGetCandidateListW(context, listIndex, list, bytes);
    *reinterpret_cast<DWORD*>(self + 0xcc) = list->dwCount;
    const int selection = static_cast<int>(list->dwSelection);
    int& first = *reinterpret_cast<int*>(self + 0x70);
    first = static_cast<int>(list->dwPageStart);
    int page = static_cast<int>(list->dwPageSize);
    *reinterpret_cast<int*>(self + 0xd4) = page;
    cx18_ImmReleaseContext(hwnd, context);
    const int count = *reinterpret_cast<int*>(self + 0xcc);
    if (!count) {
        Scaleform::Memory::Free(list);
        return;
    }
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode & 0xf00) first = selection - selection % *reinterpret_cast<int*>(self + 0xd4);
    int visible;
    if (mode == 0x410000) {
        page = 5;
        visible = count < 5 ? count : 5;
    } else {
        visible = page;
        if (mode == 0x40000) {
            if (count - first <= page) visible = count - first;
        } else if (mode == 0x60000) {
            first = selection;
            if (count - selection <= page) visible = count - selection;
        } else {
            visible = count;
            if (mode != 0xd00001 && page <= count) {
                visible = page;
                if (count - first <= page) visible = count - first;
            }
        }
    }
    *reinterpret_cast<int*>(self + 0x6c) = visible;
    {
        Scaleform::GFx::Value args[2];
        args[0] = Scaleform::GFx::Value(static_cast<double>(page));
        args[1] = Scaleform::GFx::Value(static_cast<double>(*reinterpret_cast<int*>(self + 0x5a0)));
        cx18_InvokeInputWindow(self, "RemoveList", nullptr, 0);
        cx18_InvokeInputWindow(self, "CreateList", args, 2);
    }
    cx18_FillCandidateRows(self, list, first, visible);
    Scaleform::Memory::Free(list);
    cx18_ImmReleaseContext(hwnd, context);
    long long selected = -1;
    if (cx18_CandidateSelectsInPage(*reinterpret_cast<unsigned*>(self + 0x98)))
        selected = selection % *reinterpret_cast<int*>(self + 0xd4);
    void* output = *reinterpret_cast<void**>(self + 0x30);
    FUN_1423d97f0(output, static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(output);
    self[0x5bc] = 1;
}

// The words the exe reads for input mode 4 (Cangjie), indexed by tolower(key) - 0x20 over 0x20..0x7a: the radicals
// for a..y and 'Z' for z (0x14313a910 + 4); keys below 'a' read the bytes before it (0x14313a70c + 8 * (key - 0x20)).
static const unsigned short cx18_CangjieKeys[0x5b] = {
    0x0001, 0x0001, 0x0000, 0x3107, 0x0042, 0x0000, 0x310f, 0x0044, 0x0000, 0x310d, 0x0046, 0x0000,
    0x3115, 0x0048, 0x0000, 0x311b, 0x004a, 0x0001, 0x311c, 0x004c, 0x0002, 0x3129, 0x004e, 0x0000,
    0x311f, 0x0050, 0x0002, 0x3106, 0x0052, 0x0000, 0x310b, 0x0054, 0x0000, 0x3127, 0x0056, 0x0000,
    0x310a, 0x0058, 0x0000, 0x3117, 0x005a, 0x0000, 0x3105, 0x0032, 0x0000, 0x02c7, 0x0034, 0x0003,
    0x3113, 0x0036, 0x0003, 0x02d9, 0x0038, 0x0002, 0x311e, 0x0030, 0x0002, 0x311d, 0x002e, 0x0002,
    0x3125, 0x003b, 0x0002, 0x3126, 0x0000, 0x65e5, 0x6708, 0x91d1, 0x6728, 0x6c34, 0x706b, 0x571f,
    0x7af9, 0x6208, 0x5341, 0x5927, 0x4e2d, 0x4e00, 0x5f13, 0x4eba, 0x5fc3, 0x624b, 0x53e3, 0x5c38,
    0x5eff, 0x5c71, 0x5973, 0x7530, 0x96e3, 0x535c, 0x005a,
};

// Key event hook of the IMM IME object (WM_KEYDOWN/WM_KEYUP). Stores the layout (+0x58, +0x5a8) and the IMM virtual
// key (+0xd0); in mode 0x70000 PgDn/PgUp move the IMM candidate page by nine. A key down that is not VK_PROCESSKEY
// marks a key pending (+0xa0) and an IME UI message (+0xa1). On its key up with no UI message and no composition
// (+0x60) the input window is closed (vtbl+0x80, RemoveInputWindow). A key down then translates the key to its
// character (+0xd0; backspace, return, escape and space stop here): mode 2 (Zhuyin) maps it through the key records
// at +0xd8 (bopomofo to +0xd0, class to +0xc8), mode 4 (Cangjie) through the radical table. A key up after a
// candidate list was shown (+0x5bc) repositions the candidate window (0x1423d5060).
// @0x1423d4c20
void FUN_1423d4c20(void* raw, const void* event)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* message = static_cast<const unsigned char*>(event);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    auto& key = *reinterpret_cast<unsigned short*>(self + 0xd0);
    BYTE state[256];
    wchar_t translated[0x14];
    UINT type = *reinterpret_cast<const UINT*>(message + 0xc);
    if (type == WM_KEYDOWN || type == WM_KEYUP) {
        GetKeyboardState(state);
        HKL layout = GetKeyboardLayout(0);
        *reinterpret_cast<HKL*>(self + 0x58) = layout;
        *reinterpret_cast<HKL*>(self + 0x5a8) = layout;
        const BYTE scan = message[0x1a];
        key = static_cast<unsigned short>(cx18_ImmGetVirtualKey(hwnd));
        if (*reinterpret_cast<int*>(self + 0x98) == 0x70000) {
            if (key == VK_NEXT) {
                HIMC context = cx18_ImmGetContext(hwnd);
                cx18_ImmNotifyIME(context, NI_OPENCANDIDATE, 0, 0);
                cx18_ImmNotifyIME(context, NI_SETCANDIDATE_PAGESTART, 0, *reinterpret_cast<int*>(self + 0x70) + 9);
                cx18_ImmReleaseContext(hwnd, context);
            }
            if (*reinterpret_cast<int*>(self + 0x98) == 0x70000 && key == VK_PRIOR) {
                HIMC context = cx18_ImmGetContext(hwnd);
                cx18_ImmNotifyIME(context, NI_OPENCANDIDATE, 0, 0);
                cx18_ImmNotifyIME(context, NI_SETCANDIDATE_PAGESTART, 0, *reinterpret_cast<int*>(self + 0x70) - 9);
                cx18_ImmReleaseContext(hwnd, context);
            }
        }
        ToUnicodeEx(key, scan, state, translated, 0x14, 0, *reinterpret_cast<HKL*>(self + 0x58));
        type = *reinterpret_cast<const UINT*>(message + 0xc);
    }
    const WPARAM wParam = *reinterpret_cast<const WPARAM*>(message + 0x10);
    const LPARAM lParam = *reinterpret_cast<const LPARAM*>(message + 0x18);
    if (type == WM_KEYDOWN && wParam != VK_PROCESSKEY)
        *reinterpret_cast<short*>(self + 0xa0) = 1;
    if (self[0xa0] && cx18_ImmIsUIMessageW(nullptr, type, wParam, lParam))
        self[0xa1] = 1;
    if (*reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYUP && self[0xa0]) {
        self[0xa0] = 0;
        if (!self[0xa1] && *reinterpret_cast<int*>(self + 0x60) == 0) {
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(self))[0x80 / sizeof(void*)])(self);
            cx18_InvokeInputWindow(self, "RemoveInputWindow", nullptr, 0);
        }
    }
    if (*reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYDOWN) {
        const BYTE scan = message[0x1a];
        const UINT virtualKey = cx18_ImmGetVirtualKey(hwnd);
        key = static_cast<unsigned short>(virtualKey);
        ToUnicodeEx(virtualKey & 0xffff, scan, state, translated, 0x14, 0, *reinterpret_cast<HKL*>(self + 0x58));
        unsigned short ch = static_cast<unsigned short>(translated[0]);
        key = ch;
        if (ch < 0x21 && (0x108002100ull >> ch & 1)) return;
        int mode = *reinterpret_cast<int*>(self + 0x98);
        if (mode == 2 && ch > 0x1f && ch < 0x7b) {
            const int index = tolower(ch) - 0x20;
            ch = *reinterpret_cast<unsigned short*>(self + 0xdc + 12 * index);
            key = ch;
            *reinterpret_cast<int*>(self + 0xc8) = *reinterpret_cast<int*>(self + 0xe0 + 12 * index);
            mode = *reinterpret_cast<int*>(self + 0x98);
        }
        if (mode == 4 && static_cast<unsigned short>(ch - 0x20) < 0x5b)
            key = cx18_CangjieKeys[tolower(ch) - 0x20];
    }
    if (*reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYUP && self[0x5bc]) {
        FUN_1423d5060(self, -*reinterpret_cast<int*>(self + 0x64));
        self[0x5bc] = 0;
    }
}

// MS2-FUNCTIONAL: selects the language record named by primary (state 1) or alternate (state 2), else the record whose
// mode is configured for the language, and adds its text to the conversion-mode lists on first selection.
// @0x1423cada0
int FUN_1423cada0(unsigned long long* manager, const char* primary, const char* alternate, unsigned short language)
{
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    auto modeOf = reinterpret_cast<unsigned(*)(void*, unsigned)>(vtable[3]);
    Scaleform::String selected;
    int result = -1;
    unsigned chosen = 0;
    bool wasSet = false;
    bool found = false;
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        if (!primary) continue;
        auto* record = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
        if (_stricmp(primary, reinterpret_cast<Scaleform::String*>(record + 0x10)->ToCStr()) != 0) continue;
        if (*reinterpret_cast<unsigned*>(bytes + 0x84) != modeOf(manager, *reinterpret_cast<unsigned*>(record + 0x20)))
            continue;
        selected = *reinterpret_cast<Scaleform::String*>(record + 0x10);
        chosen = i;
        found = true;
        break;
    }
    if (!found) {
        for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
            if (!alternate) continue;
            auto* record = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
            if (_stricmp(alternate, reinterpret_cast<Scaleform::String*>(record + 0x10)->ToCStr()) != 0) continue;
            if (*reinterpret_cast<unsigned*>(bytes + 0x84) != modeOf(manager, *reinterpret_cast<unsigned*>(record + 0x20)))
                continue;
            selected = *reinterpret_cast<Scaleform::String*>(reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30 + 0x18);
            result = static_cast<int>(i);
            auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
            wasSet = states[i] != 0;
            states[i] = 2;
            const unsigned code = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30 + 0x20);
            bool conflict = false;
            for (unsigned j = 0; j < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++j) {
                if (reinterpret_cast<unsigned*>(manager[0x32])[j] == 1 &&
                    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager[0x17]) + j * 0x30 + 0x20) == code) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                if (wasSet) return result;
                chosen = i;
                goto addToLists;
            }
            break;
        }
        const int configCount = *reinterpret_cast<int*>(bytes + 0x178);
        for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0) && !found; ++i) {
            const unsigned code = *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30 + 0x20);
            auto* config = reinterpret_cast<unsigned char*>(manager[0x2e]);
            for (long long j = 0; j < configCount; ++j) {
                if (*reinterpret_cast<unsigned long long*>(config + j * 0x10 + 8) != language ||
                    *reinterpret_cast<unsigned*>(config + j * 0x10) != code) continue;
                selected = primary ? primary : alternate;
                chosen = i;
                found = true;
                break;
            }
        }
        if (!found) return result;
    }
    {
        result = static_cast<int>(chosen);
        auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
        wasSet = states[chosen] != 0;
        states[chosen] = 1;
        if (wasSet) return result;
    }
addToLists:
    {
        const unsigned mode = modeOf(manager,
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager[0x17]) + chosen * 0x30 + 0x20));
        if (mode & 0xf00) FUN_1422fd480(manager + 2, &selected);
        if (mode & 0xf000) FUN_1422fd480(manager + 5, &selected);
        if (mode & 0xf0000) FUN_1422fd480(manager + 8, &selected);
        if (mode & 0xf) FUN_1422fd480(manager + 0xb, &selected);
    }
    return result;
}

// Moves the candidate window of the IMM IME object to the composition cursor at offset: RepositionCandWindow(x1, y2,
// y2 - y1) of the cursor rect IMEManagerBase::GetMetrics reports.
// MS2-FUNCTIONAL: the exe builds the three arguments in a heap Value array
// @0x1423d5060
void FUN_1423d5060(void* raw, int offset)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, offset);
    Scaleform::GFx::Value args[3];
    args[0] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
    args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
    args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1));
    cx18_InvokeInputWindow(self, "RepositionCandWindow", args, 3);
}

// MS2-FUNCTIONAL: composition-text update of the Vista IME object (vtable slot 23). It reads GCS_COMPSTR, turns a
// leading space or U+3000 into U+00A0, and either stores the text in the String at +0xb0 (mode 0x60000, which like
// the exe returns without releasing the context) or sends it with SetCompositionText and writes its length to
// *outputLength. The candidate modes also set the cursor, store length - cursor at +0x64 and highlight the whole text.
// It then sets the composition cursor and, unless the mode has a low nibble, calls RepositionInputWindow(x1, y2) of
// the cursor rect IMEManagerBase::GetMetrics reports.
// @0x1423ce730
void FUN_1423ce730(void* raw, unsigned* outputLength)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    HIMC context = cx18_ImmGetContext(hwnd);
    const LONG size = cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, nullptr, 0);
    auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<SPInt>(size * 2)) + 2));
    cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, text, size);
    const int count = size / 2;
    text[count] = 0;
    if (text[0] == L' ' || text[0] == 0x3000) text[0] = 0x00a0;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0x60000) {
        *reinterpret_cast<Scaleform::String*>(self + 0xb0) = text;
        Scaleform::Memory::Free(text);
        return;
    }
    ime->SetCompositionText(text, -1);
    *outputLength = static_cast<unsigned>(count);
    if (mode == 0x210000 || mode == 0x110000 || mode == 0xd10000) {
        const LONG cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
        ime->SetCursorInComposition(static_cast<UPInt>(cursor));
        *reinterpret_cast<unsigned*>(self + 0x64) = *outputLength - static_cast<unsigned>(cursor);
        ime->HighlightText(0, *outputLength, Scaleform::GFx::IMEManagerBase::THS_CompositionSegment, false);
    }
    if (size)
        ime->SetCursorInComposition(static_cast<SPInt>(cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0)));
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, 0);
    if ((mode & 0xf) == 0) {
        Scaleform::GFx::Value args[2];
        args[0] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
        args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RepositionInputWindow", &result, args, 2);
    }
    cx18_ImmReleaseContext(hwnd, context);
    Scaleform::Memory::Free(text);
}

// MS2-FUNCTIONAL: removes the old input window, then shows the composition string (a UTF-8 copy of the String at +0xb0)
// at the cursor rect IMEManagerBase::GetMetrics reports for the composition end (offset -[+0x64]).
// @0x1423ceb30
void FUN_1423ceb30(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* movie = *reinterpret_cast<void**>(self + 0xa8);
    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18))
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &result, nullptr, 0);
    }
    auto* composition = reinterpret_cast<Scaleform::String*>(self + 0xb0);
    const unsigned length = *reinterpret_cast<unsigned*>(
        *reinterpret_cast<UPInt*>(composition) & ~static_cast<UPInt>(3));
    if (!length) return;
    char* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<int>(length + 1)));
    memset(text, 0, length + 1);
    memcpy(text, composition->ToCStr(), length + 1);
    if (!text) {
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        return;
    }
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
    Scaleform::GFx::Value args[4];
    args[0] = Scaleform::GFx::Value(static_cast<const char*>(text));
    args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
    args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
    args[3] = Scaleform::GFx::Value(0.0);
    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18))
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
                (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "DisplayInputWindow", &result, args, 4);
    }
    Scaleform::Memory::Free(text);
}

// The language-bar events FUN_1423cd6b0 and FUN_1423cd0a0 handle the same way. Unknown events go to slot 24 and
// then on to the provider's slot 11 with defaultArgument.
static void cx18_DispatchLangBarEvent(unsigned long long* self, const char* command, const char* argument,
                                      const char* defaultArgument)
{
    auto** vtable = reinterpret_cast<void**>(self[0]);
    auto* provider = reinterpret_cast<unsigned char*>(self[0xf]);
    auto providerCall = [&](unsigned slot) { return (*reinterpret_cast<void***>(provider))[slot]; };
    auto stringData = [](unsigned long long node) { return reinterpret_cast<const char*>((node & ~3ull) + 0xc); };
    if (std::strcmp(command, "LangBar_OnSelectInputLang") == 0) {
        reinterpret_cast<void(*)(void*)>(vtable[18])(self);
        if (provider) reinterpret_cast<void(*)(void*, const char*)>(providerCall(9))(provider, argument);
    } else if (std::strcmp(command, "LangBar_GetIMENames") == 0) {
        if (!provider) return;
        const unsigned mode = *reinterpret_cast<unsigned*>(provider + 0x84);
        unsigned countOffset;
        bool callWhenEmpty = false;
        if (mode == 9) countOffset = 0x60;
        else if (mode == 0x400) { countOffset = 0x18; callWhenEmpty = true; }
        else if (mode == 0x2000) countOffset = 0x30;
        else if (mode == 0x80000) countOffset = 0x48;
        else {
            if (mode == 0x10000000) reinterpret_cast<void(*)(void*)>(vtable[18])(self);
            return;
        }
        Scaleform::String joined;
        const int count = *reinterpret_cast<int*>(provider + countOffset);
        if (count == 0 && !callWhenEmpty) return;
        auto* names = *reinterpret_cast<Scaleform::String**>(provider + countOffset - 8);
        for (int i = 0; i < count; ++i) joined += names[i] + "@@";
        reinterpret_cast<void(*)(void*, const char*)>(vtable[14])(self, joined.ToCStr());
    } else if (std::strcmp(command, "LangBar_OnSelectIME") == 0) {
        if (!provider) return;
        reinterpret_cast<void(*)(void*, const char*)>(providerCall(8))(provider, argument);
        if (*reinterpret_cast<unsigned*>(provider + 0x84) == 9)
            reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        const char* language = stringData(self[0x16]);
        if (std::strcmp(language, "Japanese") == 0 || std::strcmp(language, "Korean") == 0) {
            reinterpret_cast<void(*)(void*)>(vtable[19])(self);
            reinterpret_cast<void(*)(void*, int)>(providerCall(10))(provider, -1);
        }
    } else if (std::strcmp(command, "LangBar_GetInstalledLanguages") == 0) {
        if (provider)
            reinterpret_cast<void(*)(void*, const char*)>(vtable[13])(
                self, stringData(*reinterpret_cast<unsigned long long*>(provider + 0x70)));
    } else {
        reinterpret_cast<void(*)(void*)>(vtable[24])(self);
        if (provider)
            reinterpret_cast<void(*)(void*, const char*, const char*)>(providerCall(11))(
                provider, command, defaultArgument);
    }
}

// MS2-FUNCTIONAL: dispatches the language-bar and status-window callbacks by event name.
// @0x1423cd6b0
void FUN_1423cd6b0(unsigned long long* self, unsigned long long payload,
                   unsigned long long* commandCell, unsigned long long* argumentCell)
{
    const char* command = *reinterpret_cast<const char**>(*commandCell);
    const char* argument = *reinterpret_cast<const char**>(*argumentCell);
    auto** vtable = reinterpret_cast<void**>(self[0]);
    auto* provider = reinterpret_cast<unsigned char*>(self[0xf]);
    if (std::strcmp(command, "LangBar_OnInit") == 0) {
        *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(self[3]) + 0x48) = payload;
        if (provider)
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[12])(provider);
    } else if (std::strcmp(command, "StatusWindow_OnInit") == 0) {
        *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(self[3]) + 0x50) = payload;
        reinterpret_cast<void(*)(void*, const char*)>(vtable[12])(
            self, reinterpret_cast<const char*>((self[0x16] & ~3ull) + 0xc));
        reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        reinterpret_cast<void(*)(void*, int)>(vtable[6])(self, -1);
    } else {
        cx18_DispatchLangBarEvent(self, command, argument, argument);
    }
}

// MS2-FUNCTIONAL: decodes the external callback's Value array (string values may be managed, one more indirection)
// and dispatches its event. The OnInit events keep the second Value in the owner at +0x28/+0x58.
// @0x1423cd0a0
void FUN_1423cd0a0(unsigned long long* self, const unsigned char* event)
{
    using Scaleform::GFx::Value;
    const unsigned count = *reinterpret_cast<const unsigned*>(event + 0x28);
    if (!count) return;
    const unsigned long long payload = *reinterpret_cast<const unsigned long long*>(event + 8);
    auto* values = *reinterpret_cast<unsigned char* const*>(event + 0x20);
    auto valueString = [](const unsigned char* v) {
        const char* text = *reinterpret_cast<const char* const*>(v + 0x10);
        if (*reinterpret_cast<const unsigned*>(v + 8) & Value::VTC_ManagedBit)
            text = *reinterpret_cast<const char* const*>(text);
        return text;
    };
    const char* command = valueString(values);
    unsigned char* second = values + 0x20;
    // The exe reads the second Value's type even for a one-element array (StatusWindow_OnInit, OnItemSelect).
    const unsigned secondType = *reinterpret_cast<const unsigned*>(second + 8) & 0x8f;
    const char* argument = (count > 1 && secondType == Value::VT_String) ? valueString(second) : nullptr;
    auto** vtable = reinterpret_cast<void**>(self[0]);
    auto* provider = reinterpret_cast<unsigned char*>(self[0xf]);
    auto* owner = reinterpret_cast<unsigned char*>(self[3]);
    if (std::strcmp(command, "CandidateList_OnSetItemDataMap") == 0) {
        auto* candidates = reinterpret_cast<unsigned char*>(self[0xe]);
        if (candidates)
            reinterpret_cast<void(*)(void*, unsigned long long, const char*, const char*)>(
                (*reinterpret_cast<void***>(candidates))[0xa0 / sizeof(void*)])(candidates, payload, command, argument);
    } else if (std::strcmp(command, "CandidateList_OnItemSelect") == 0) {
        // The exe calls FUN_1423ca3f0 with the index in edx, which its tail jump passes on to the candidate list's
        // slot 19; our one-argument FUN_1423ca3f0 cannot pass it, so the call is made here.
        auto* candidates = reinterpret_cast<unsigned char*>(self[0xe]);
        if (secondType == Value::VT_Number && candidates)
            reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(candidates))[0x98 / sizeof(void*)])(
                candidates, static_cast<int>(*reinterpret_cast<const double*>(second + 0x10)));
    } else if (std::strcmp(command, "LangBar_OnInit") == 0) {
        if (count < 2 || !secondType) return;
        *reinterpret_cast<Value*>(owner + 0x28) = *reinterpret_cast<const Value*>(second);
        if (provider)
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[12])(provider);
    } else if (std::strcmp(command, "StatusWindow_OnInit") == 0) {
        if (!secondType) return;
        *reinterpret_cast<Value*>(owner + 0x58) = *reinterpret_cast<const Value*>(second);
        const char* language = reinterpret_cast<const char*>((self[0x16] & ~3ull) + 0xc);
        reinterpret_cast<void(*)(void*, const char*)>(vtable[12])(self, language);
        reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        if (std::strcmp(language, "Korean") == 0 && provider)
            reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(provider))[10])(provider, -1);
        reinterpret_cast<void(*)(void*, int)>(vtable[6])(self, -1);
    } else {
        const char* defaultArgument = argument;
        if (secondType == Value::VT_Boolean)
            defaultArgument = *reinterpret_cast<const bool*>(second + 0x10) ? "true" : "false";
        cx18_DispatchLangBarEvent(self, command, argument, defaultArgument);
    }
}

// MS2-FUNCTIONAL: for the (0x282, 0xe, 0x12) notification: on backspace ([+0xd0] == 8) in state 4/0x40000 it removes the
// input window, drops the last character of the wide buffer at [+0x40] and shows the rest; in state 2 it removes the
// window through FUN_1423ca030, blanks the last non-space of the first four characters of [+0xb0] and shows that. The
// text goes out as UTF-8 to DisplayInputWindow(text, cursor.x1, cursor.y2, 0.0) at the IME manager's cursor rect. On
// space ([+0xd0] == 0x20) in state 4 it removes the window and clears [+0x40].
// @0x1423d1d10
void FUN_1423d1d10(void* raw, long long message, long long compositionFlag, long long extra)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (message != 0x282 || compositionFlag != 0xe || extra != 0x12) return;
    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    const short key = *reinterpret_cast<short*>(self + 0xd0);
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    if (key == 8) {
        const wchar_t* shown = nullptr;
        if (state == 4 || state == 0x40000) {
            {
                Scaleform::GFx::Value result;
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "RemoveInputWindow", &result, nullptr, 0);
            }
            auto* buffer = *reinterpret_cast<wchar_t**>(self + 0x40);
            const int length = static_cast<int>(wcslen(buffer));
            if (length) buffer[length - 1] = 0;
            shown = buffer;
        } else if (state == 2) {
            FUN_1423ca030(*reinterpret_cast<void**>(self + 8), "RemoveInputWindow", nullptr);
            auto* buffer = *reinterpret_cast<wchar_t**>(self + 0xb0);
            int i = 3;
            while (i >= 0 && buffer[i] == L' ') --i;
            if (i >= 0) buffer[i] = L' ';
            shown = buffer;
        }
        if (shown) {
            char* text = static_cast<char*>(Scaleform::Memory::Alloc(
                static_cast<SPInt>(Scaleform::UTF8Util::GetEncodeStringSize(shown, -1) + 1)));
            Scaleform::UTF8Util::EncodeString(text, shown, -1);
            void* owner = *reinterpret_cast<void**>(self + 8);
            Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
                reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
            Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
            ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
            Scaleform::GFx::Value args[4];
            args[0] = Scaleform::GFx::Value(static_cast<const char*>(text));
            args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
            args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
            args[3] = Scaleform::GFx::Value(0.0);
            {
                Scaleform::GFx::Value result;
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "DisplayInputWindow", &result, args, 4);
            }
            Scaleform::Memory::Free(text);
        }
    }
    if (key == 0x20 && state == 4) {
        {
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &result, nullptr, 0);
        }
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
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
    // Each token is appended as String(token) + ",", e.g. "Native,full,half,".
    if (mode == 9 || mode == 0x80000 || mode == 0x2000) {
        label += (conversion & 1) ? "Native" : "Alphanumeric";
        label += ",";
        label += (conversion & 8) ? "full" : "half";
        label += ",";
        label += (conversion & 0x400) ? "full" : "half";
        label += ",";
    } else if (mode == 0x400) {
        if (!cx18_ImmGetOpenStatus(context)) {
            *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0xa8) = 0;
            label += "DirectInput";
        } else if (!(conversion & 1)) {
            label += (conversion & 8) ? "Alphanumeric_FullShape" : "Alphanumeric_HalfShape";
        } else {
            *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0xa8) = 1;
            if ((conversion & 0xa) == 0xa) label += "Katakana_FullShape";
            else if ((conversion & 0xa) == 8) label += "Hiragana_FullShape";
            else label += "Katakana_HalfShape";
        }
        label += ",";
    }
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(state))[0x88 / sizeof(void*)])(
        state, label.ToCStr());
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: asks the IME manager for the cursor rect at the given offset and calls
// RepositionCandWindow(cursor.x1, cursor.y2, cursor.y2 - cursor.y1) on the movie's external interface.
// @0x1423d0f60
void FUN_1423d0f60(void* manager, int mode)
{
    auto* self = static_cast<unsigned char*>(manager);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, mode);
    Scaleform::GFx::Value args[3];
    args[0] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
    args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
    args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1));
    Scaleform::GFx::Value result;
    if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(bridge, "RepositionCandWindow", &result, args, 3);
}

// MS2-FUNCTIONAL: converts the candidate/reading window property mask into the two formatted AS calls,
// <path at +0x10>.SetCandidateListProps and <path>.SetReadingWindowProps.
// @0x1423cf670
void FUN_1423cf670(void* raw, const unsigned* attributes)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner || !attributes) return;
    auto* factory = *reinterpret_cast<unsigned char**>(owner + 0x10);
    void* temporary = reinterpret_cast<void*(*)(void*, int)>((*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
    if (!temporary) return;
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
    if (command->GetLength()) {
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), (*command + ".SetCandidateListProps").ToCStr(),
            "%d %d %d %d %d %d %d", values[0], values[3], values[1], values[4], values[8], values[2], values[5]);
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), (*command + ".SetReadingWindowProps").ToCStr(),
            "%d %d %d", values[6], values[7], values[9]);
    }
    FUN_14257dcb0(temporary);
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

// Invokes an ActionScript callback of the IMM IME object's movie (+0xa8, bridge at +0x18, Invoke = slot 0x78).
static void cx18_InvokeInputWindow(unsigned char* self, const char* name, Scaleform::GFx::Value* args, unsigned count)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    Scaleform::GFx::Value result;
    if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
        reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, name, &result, args, count);
}

// Shows the UTF-8 copy of the reading string at +0x40 in the input window at the composition cursor (offset
// -[+0x64]): DisplayInputWindow(text, cursor.x1, cursor.y2, height), height = cursor.y2 - cursor.y1 or 0.
static void cx18_DisplayReading(unsigned char* self, const char* text, bool withHeight)
{
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
    Scaleform::GFx::Value args[4];
    args[0] = Scaleform::GFx::Value(text);
    args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
    args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
    args[3] = Scaleform::GFx::Value(withHeight ? static_cast<double>(cursorRect.y2 - cursorRect.y1) : 0.0);
    cx18_InvokeInputWindow(self, "DisplayInputWindow", args, 4);
}

// Reading-string window of the IMM IME object, called from its WM_IME_COMPOSITION handler (0x1423d3510) for
// GCS_COMPATTR. Removes the old input window, then updates the reading text at +0x40 from the last key (+0xd0) by the
// input mode at +0x98: modes 1/3/5/7 copy the composition reading string; mode 2 (key 0x3000 only) writes the key into
// the +0xb0 buffer at index +0xc8 and copies it (other keys reset that buffer to four spaces); modes 4/10 append up
// to five keys and handle backspace; 0x10000/0x20000/0x30000/0x60000/0xa10000/0xb10000/0xd00001/0xd00002 copy the
// reading string; 0x110000 appends a..z; 0x40000/0x50000/0x70000/0x90000/0xa0000 restart the text when the target
// clause (first attribute 1) moves (its index kept at +0x5a4) and append otherwise. Escape clears it. A non-empty
// result goes to DisplayInputWindow.
// MS2-FUNCTIONAL: the exe builds the four arguments in a heap Value array
// @0x1423d2710
void FUN_1423d2710(void* manager, int key, unsigned length, long long attributes, wchar_t* reading)
{
    auto* self = static_cast<unsigned char*>(manager);
    cx18_InvokeInputWindow(self, "RemoveInputWindow", nullptr, 0);
    const wchar_t ch = *reinterpret_cast<wchar_t*>(self + 0xd0);
    wchar_t* text = *reinterpret_cast<wchar_t**>(self + 0x40);
    if (ch == 0x1b) {
        *text = 0;
        return;
    }
    const int textLength = static_cast<int>(wcslen(text));
    const auto* attrs = reinterpret_cast<const char*>(attributes);
    auto append = [&](wchar_t c) {
        text[textLength] = c;
        text[textLength + 1] = 0;
    };
    const int mode = *reinterpret_cast<int*>(self + 0x98);
    switch (mode) {
    case 1: case 3: case 5: case 7:
        Scaleform::SFwcscpy(text, wcslen(reading) + 1, reading);
        break;
    case 2: {
        const int index = *reinterpret_cast<int*>(self + 0xc8);
        if (index > 4) return;
        wchar_t* buffer = *reinterpret_cast<wchar_t**>(self + 0xb0);
        if (key != 0x3000) {
            buffer[0] = buffer[1] = buffer[2] = buffer[3] = L' ';
            buffer[4] = 0;
            return;
        }
        buffer[index] = ch;
        Scaleform::SFwcscpy(text, wcslen(buffer) + 1, buffer);
        break;
    }
    case 4: case 10:
        if (key != 0x3000) {
            *text = 0;
            return;
        }
        if (ch != L'\r' && ch != L' ' && ch != L'\b' && textLength < 5) append(ch);
        if (ch == L'\b') {
            const int n = static_cast<int>(wcslen(text));
            if (n > 0) text[n - 1] = 0;
        }
        break;
    case 0x10000: case 0x20000: case 0x30000: case 0x60000: case 0xa10000: case 0xb10000: case 0xd00001: case 0xd00002: {
        const int n = static_cast<int>(wcslen(reading));
        memcpy(text, reading, static_cast<size_t>(n) * 2);
        text[n] = 0;
        break;
    }
    case 0x110000:
        if (ch == L'\b') {
            if (textLength > 0) text[textLength - 1] = 0;
        } else if (static_cast<unsigned short>(ch - L'a') < 26) {
            append(ch);
        }
        break;
    case 0x40000: case 0x50000: case 0x70000: case 0x90000: case 0xa0000:
        if (key != 0x3000) {
            *text = 0;
        } else if (ch == L'\b') {
            if (textLength > 0) text[textLength - 1] = 0;
        } else if (ch != L'\r' && ch != L' ') {
            unsigned target = 0;
            while (static_cast<int>(target) < static_cast<int>(length) && attrs[target] != ATTR_TARGET_CONVERTED)
                ++target;
            if (target == length) return;
            auto& lastTarget = *reinterpret_cast<unsigned*>(self + 0x5a4);
            if (lastTarget == target) {
                append(ch);
            } else {
                lastTarget = target;
                text[0] = ch;
                text[1] = 0;
            }
        }
        break;
    default:
        break;
    }
    text = *reinterpret_cast<wchar_t**>(self + 0x40);
    const SPInt size = Scaleform::UTF8Util::GetEncodeStringSize(text, -1);
    if (!static_cast<int>(size)) return;
    char* utf8 = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<int>(size) + 1)));
    Scaleform::UTF8Util::EncodeString(utf8, text, -1);
    cx18_DisplayReading(self, utf8, true);
    Scaleform::Memory::Free(utf8);
}

// WM_IME_COMPOSITION of the IMM IME object (vtbl 0x14313a5f8 slot 10). No flags: clears the composition length
// (+0x60). GCS_RESULTSTR: the result string is finalized into the IME manager, kept in its String at +0x98 and
// broadcast (slot 11); the input window is removed. CS_INSERTCHAR|CS_NOMOVECARET: wParam becomes a one-character
// composition. GCS_COMPSTR|GCS_CURSORPOS: vtbl+0xb8. GCS_COMPATTR: sets the composition cursor, computes +0x64 from
// the target clause, highlights each run of equal attributes, repositions the candidate window in mode 0x40000 and
// updates the reading window (0x1423d2710). Exactly GCS_CURSORPOS|GCS_DELTASTART: shows the reading text at +0x40.
// MS2-FUNCTIONAL: the exe builds the Invoke arguments in heap Value arrays
// @0x1423d3510
void FUN_1423d3510(long long* manager, unsigned long long wParam, unsigned long long flags)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    if (!manager[1]) return;
    auto** vtable = *reinterpret_cast<void***>(self);
    auto* states = reinterpret_cast<Scaleform::GFx::StateBag*>(*reinterpret_cast<unsigned char**>(self + 8) + 0x10);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime = states->GetIMEManager();
    if (!flags) {
        *reinterpret_cast<unsigned*>(self + 0x60) = 0;
        return;
    }
    if (flags & GCS_RESULTSTR) {
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> result = states->GetIMEManager();
        HIMC context = cx18_ImmGetContext(hwnd);
        const LONG size = cx18_ImmGetCompositionStringW(context, GCS_RESULTSTR, nullptr, 0);
        auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(size) * 2 + 2)));
        if (static_cast<unsigned>(cx18_ImmGetCompositionStringW(context, GCS_RESULTSTR, text, size) + 2) > 1) {
            text[static_cast<unsigned>(size) >> 1] = 0;
            result->SetWideCursor(false);
        }
        *reinterpret_cast<unsigned*>(self + 0x60) = 0;
        *reinterpret_cast<unsigned*>(self + 0x68) = 0;
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        *reinterpret_cast<wchar_t*>(self + 0xd0) = 0;
        cx18_InvokeInputWindow(self, "RemoveInputWindow", nullptr, 0);
        cx18_ImmReleaseContext(hwnd, context);
        result->FinalizeComposition(text);
        *reinterpret_cast<Scaleform::String*>(reinterpret_cast<unsigned char*>(result.GetPtr()) + 0x98) = text;
        result->BroadcastIMEConversion(text);
        if (text) Scaleform::Memory::Free(text);
    }
    if ((flags & (CS_INSERTCHAR | CS_NOMOVECARET)) == (CS_INSERTCHAR | CS_NOMOVECARET)) {
        wchar_t inserted[2] = { static_cast<wchar_t>(wParam), 0 };
        *reinterpret_cast<unsigned*>(self + 0x68) = 1;
        *reinterpret_cast<unsigned*>(self + 0x60) = 1;
        ime->SetWideCursor(true);
        ime->SetCompositionPosition();
        ime->SetCompositionText(inserted, 1);
        ime->SetCursorInComposition(0);
    }
    if ((flags & (GCS_COMPSTR | GCS_CURSORPOS)) == (GCS_COMPSTR | GCS_CURSORPOS))
        reinterpret_cast<void(*)(void*, void*)>(vtable[0xb8 / sizeof(void*)])(self, self + 0x60);
    if (flags & GCS_COMPATTR) {
        HIMC context = cx18_ImmGetContext(hwnd);
        const LONG attrSize = cx18_ImmGetCompositionStringW(context, GCS_COMPATTR, nullptr, 0);
        auto* attrs = static_cast<signed char*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(attrSize) + 1)));
        cx18_ImmGetCompositionStringW(context, GCS_COMPATTR, attrs, attrSize);
        unsigned length = *reinterpret_cast<unsigned*>(self + 0x60);
        if (static_cast<unsigned>(attrSize) < length) length = static_cast<unsigned>(attrSize);
        const LONG readSize = cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, nullptr, 0);
        auto* reading = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(readSize) * 2 + 2)));
        memset(reading, 0, static_cast<size_t>(static_cast<unsigned>(readSize) * 2));
        cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, reading, readSize);
        reading[static_cast<unsigned>(readSize) >> 1] = 0;
        const SPInt cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
        cx18_ImmReleaseContext(hwnd, context);
        ime->SetCursorInComposition(cursor);

        struct Segment { int start; int end; int attr; };
        Segment* segments = nullptr;
        UPInt count = 0, capacity = 0;
        auto push = [&](const Segment& segment) {
            const UPInt size = count + 1;
            if (size >= capacity) {
                unsigned long long array[3] = { reinterpret_cast<unsigned long long>(segments), count, capacity };
                FUN_1423d1240(array, array, size + (size >> 2));
                segments = reinterpret_cast<Segment*>(array[0]);
                capacity = array[2];
            }
            segments[size - 1] = segment;
            count = size;
        };
        Segment current = { 0, 0, attrs[0] };
        signed char previous = attrs[0];
        *reinterpret_cast<unsigned*>(self + 0x64) = length;
        unsigned remaining = length;
        for (int i = 0; i < static_cast<int>(length); ++i, --remaining) {
            if (attrs[i] != previous) {
                push(current);
                previous = attrs[i];
                if (previous == ATTR_TARGET_CONVERTED || previous == ATTR_TARGET_NOTCONVERTED)
                    *reinterpret_cast<unsigned*>(self + 0x64) = remaining;
                current.attr = attrs[i];
                current.start = i;
            }
            current.end = i;
        }
        current.end = static_cast<int>(length) - 1;
        push(current);
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
        if (!(mode & 0xf000)) {
            for (UPInt i = 0; i < count; ++i) {
                Scaleform::GFx::IMEManagerBase::TextHighlightStyle style;
                switch (segments[i].attr) {
                case ATTR_INPUT: style = Scaleform::GFx::IMEManagerBase::THS_CompositionSegment; break;
                case ATTR_TARGET_CONVERTED:
                case ATTR_TARGET_NOTCONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ClauseSegment; break;
                case ATTR_CONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ConvertedSegment; break;
                case ATTR_INPUT_ERROR: style = Scaleform::GFx::IMEManagerBase::THS_LowConfSegment; break;
                default: continue;
                }
                ime->HighlightText(static_cast<UPInt>(segments[i].start),
                                   static_cast<UPInt>(segments[i].end - segments[i].start + 1), style, false);
            }
        }
        if (*reinterpret_cast<unsigned*>(self + 0x98) == 0x40000) {
            Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
            ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
            Scaleform::GFx::Value args[3];
            args[0] = Scaleform::GFx::Value(static_cast<double>(cursorRect.x1));
            args[1] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2));
            args[2] = Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1));
            cx18_InvokeInputWindow(self, "RepositionCandWindow", args, 3);
        }
        FUN_1423d2710(self, static_cast<int>(wParam), length, reinterpret_cast<long long>(attrs), reading);
        if (reading) Scaleform::Memory::Free(reading);
        Scaleform::Memory::Free(attrs);
        if (segments) Scaleform::Memory::Free(segments);
    }
    if (flags == (GCS_CURSORPOS | GCS_DELTASTART)) {
        if (reinterpret_cast<Scaleform::String*>(self + 0x10)->GetLength())
            cx18_InvokeInputWindow(self, "RemoveInputWindow", nullptr, 0);
        const wchar_t* text = *reinterpret_cast<wchar_t**>(self + 0x40);
        const SPInt size = Scaleform::UTF8Util::GetEncodeStringSize(text, -1);
        char* utf8 = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<int>(size) + 1)));
        Scaleform::UTF8Util::EncodeString(utf8, text, -1);
        cx18_DisplayReading(self, utf8, false);
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        Scaleform::Memory::Free(utf8);
    }
}

// MS2-FUNCTIONAL: WM_IME_COMPOSITION of the Vista (TSF) IME object (vtbl 0x14313a450 slot 10). No flags: the
// composition goes through vtbl+0xb8. GCS_RESULTSTR: the result string is finalized into the IME manager and kept in
// its String at +0x98. CS_INSERTCHAR|CS_NOMOVECARET: wParam becomes a one-character composition. GCS_COMPSTR with
// GCS_CURSORPOS (unless mode 0xd00001): vtbl+0xb8 again. GCS_COMPATTR: sets the composition cursor, computes +0x64
// from the target clause, redraws the input window (vtbl+0xb0) and highlights each run of equal attributes.
// @0x1423cfd50
void FUN_1423cfd50(long long* manager, unsigned long long wParam, unsigned long long flags)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    auto** vtable = *reinterpret_cast<void***>(self);
    auto* states = reinterpret_cast<Scaleform::GFx::StateBag*>(*reinterpret_cast<unsigned char**>(self + 8) + 0x10);
    HWND hwnd = *reinterpret_cast<HWND*>(self + 0x28);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime = states->GetIMEManager();
    if (!flags)
        reinterpret_cast<void(*)(void*, void*)>(vtable[0xb8 / sizeof(void*)])(self, self + 0x60);
    if (flags & GCS_RESULTSTR) {
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> result = states->GetIMEManager();
        HIMC context = cx18_ImmGetContext(hwnd);
        const LONG size = cx18_ImmGetCompositionStringW(context, GCS_RESULTSTR, nullptr, 0);
        auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(size) * 2 + 2));
        if (static_cast<unsigned>(cx18_ImmGetCompositionStringW(context, GCS_RESULTSTR, text, size) + 2) > 1) {
            text[static_cast<unsigned>(size) >> 1] = 0;
            result->SetWideCursor(false);
        }
        *reinterpret_cast<unsigned*>(self + 0x60) = 0;
        *reinterpret_cast<unsigned*>(self + 0x68) = 0;
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        cx18_ImmReleaseContext(hwnd, context);
        result->FinalizeComposition(text);
        *reinterpret_cast<Scaleform::String*>(reinterpret_cast<unsigned char*>(result.GetPtr()) + 0x98) = text;
        if (text) Scaleform::Memory::Free(text);
    }
    if ((flags & (CS_INSERTCHAR | CS_NOMOVECARET)) == (CS_INSERTCHAR | CS_NOMOVECARET)) {
        wchar_t inserted[2] = { static_cast<wchar_t>(wParam), 0 };
        *reinterpret_cast<unsigned*>(self + 0x68) = 1;
        *reinterpret_cast<unsigned*>(self + 0x60) = 1;
        ime->SetWideCursor(true);
        ime->SetCompositionPosition();
        ime->SetCompositionText(inserted, 1);
    }
    if ((flags & (GCS_COMPSTR | GCS_CURSORPOS)) == (GCS_COMPSTR | GCS_CURSORPOS) &&
        *reinterpret_cast<unsigned*>(self + 0x98) != 0xd00001)
        reinterpret_cast<void(*)(void*, void*)>(vtable[0xb8 / sizeof(void*)])(self, self + 0x60);
    if (!(flags & GCS_COMPATTR)) return;

    HIMC context = cx18_ImmGetContext(hwnd);
    const LONG attrSize = cx18_ImmGetCompositionStringW(context, GCS_COMPATTR, nullptr, 0);
    auto* attrs = static_cast<signed char*>(Scaleform::Memory::Alloc(static_cast<UPInt>(attrSize + 1)));
    cx18_ImmGetCompositionStringW(context, GCS_COMPATTR, attrs, attrSize);
    unsigned length = *reinterpret_cast<unsigned*>(self + 0x60);
    if (static_cast<unsigned>(attrSize) < length) length = static_cast<unsigned>(attrSize);
    // The exe reads the reading string and frees it, then still passes the freed buffer to vtbl+0xb0 (which
    // ignores it).
    const LONG readSize = cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, nullptr, 0);
    auto* reading = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(readSize * 2 + 2)));
    memset(reading, 0, static_cast<size_t>(readSize * 2));
    cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, reading, readSize);
    reading[static_cast<unsigned>(readSize) >> 1] = 0;
    Scaleform::Memory::Free(reading);
    const SPInt cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    ime->SetCursorInComposition(cursor);

    struct Segment { int start; int end; int attr; };
    Segment* segments = nullptr;
    UPInt count = 0, capacity = 0;
    auto push = [&](const Segment& segment) {
        const UPInt size = count + 1;
        if (size >= capacity) {
            unsigned long long array[3] = { reinterpret_cast<unsigned long long>(segments), count, capacity };
            FUN_1423d1240(array, array, size + (size >> 2));
            segments = reinterpret_cast<Segment*>(array[0]);
            capacity = array[2];
        }
        segments[size - 1] = segment;
        count = size;
    };
    Segment current = { 0, 0, attrs[0] };
    unsigned char previous = static_cast<unsigned char>(attrs[0]);
    *reinterpret_cast<int*>(self + 0x64) = static_cast<int>(length - cursor);
    if (previous == ATTR_TARGET_CONVERTED || previous == ATTR_TARGET_NOTCONVERTED)
        *reinterpret_cast<unsigned*>(self + 0x64) = length;
    reinterpret_cast<void(*)(void*, void*)>(vtable[0xb0 / sizeof(void*)])(self, reading);
    unsigned remaining = length;
    for (int i = 0; i < static_cast<int>(length); ++i, --remaining) {
        if (static_cast<unsigned char>(attrs[i]) != previous) {
            push(current);
            previous = static_cast<unsigned char>(attrs[i]);
            if (previous == ATTR_TARGET_CONVERTED || previous == ATTR_TARGET_NOTCONVERTED)
                *reinterpret_cast<unsigned*>(self + 0x64) = remaining;
            current.attr = attrs[i];
            current.start = i;
        }
        current.end = i;
    }
    current.end = static_cast<int>(length) - 1;
    push(current);
    ime->SetCursorInComposition(cursor);
    if (!(*reinterpret_cast<unsigned*>(self + 0x98) & 0xf000)) {
        for (UPInt i = 0; i < count; ++i) {
            const unsigned span = static_cast<unsigned>(segments[i].end - segments[i].start + 1);
            if (!span) continue;
            Scaleform::GFx::IMEManagerBase::TextHighlightStyle style;
            switch (segments[i].attr) {
            case ATTR_INPUT: style = Scaleform::GFx::IMEManagerBase::THS_CompositionSegment; break;
            case ATTR_TARGET_CONVERTED:
            case ATTR_TARGET_NOTCONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ClauseSegment; break;
            case ATTR_CONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ConvertedSegment; break;
            case ATTR_INPUT_ERROR: style = Scaleform::GFx::IMEManagerBase::THS_LowConfSegment; break;
            default: continue;
            }
            ime->HighlightText(static_cast<UPInt>(segments[i].start), span, style, false);
        }
    }
    Scaleform::Memory::Free(attrs);
    if (segments) Scaleform::Memory::Free(segments);
}

// MS2-FUNCTIONAL: language-change handler (manager slot 7): updates the mode and locale label, resolves the layout's
// record text and conversion flags, and refreshes the IME version for flag-4 layouts.
// @0x1423cbe90
void FUN_1423cbe90(long long* manager, unsigned language)
{
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    void* provider = reinterpret_cast<void*>(manager[0xf]);
    if (!provider) return;
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned short)>(vtable[4])(
        manager, static_cast<unsigned short>(language));
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), mode);
    wchar_t locale[0x104];
    if (!GetLocaleInfoW(static_cast<unsigned short>(language), LOCALE_SLANGUAGE, locale, 0x104)) {
        reinterpret_cast<void(*)(void*, DWORD, const char*)>(vtable[0x78 / sizeof(void*)])(
            manager, GetLastError(), "GFxIME Error: Error Initializing Input Language Name ");
        provider = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(provider))[0x60 / sizeof(void*)])(
            provider, "Unsupported");
        return;
    }
    {
        String localeText(locale);
        provider = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(provider))[0x78 / sizeof(void*)])(
            provider, localeText.ToCStr());
    }
    auto& flags = *reinterpret_cast<unsigned*>(bytes + 0x88);
    flags = 0x1000000;
    if (!(language & 0xe0000000)) {
        struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
        const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x160);
        const auto* records = reinterpret_cast<const LayoutRecord*>(manager[0x2b]);
        for (unsigned i = 0; i < count; ++i) {
            if (records[i].layoutId == (language >> 16)) {
                String layoutText(records[i].layoutText);
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &layoutText);
                FUN_1423cb660(manager);
                return;
            }
        }
        String localeText(locale);
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &localeText);
    } else {
        const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0xd0);
        for (unsigned i = 0; i < count; ++i) {
            auto* entry = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
            if (*reinterpret_cast<unsigned*>(entry + 0x28) != language) continue;
            flags = *reinterpret_cast<unsigned*>(entry + 0x20);
            if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 2) {
                String text(*reinterpret_cast<String*>(entry + 0x18));
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &text);
            }
            if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 1) {
                entry = reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30;
                String text(*reinterpret_cast<String*>(entry + 0x10));
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &text);
            }
            FUN_1423cb660(manager);
            *reinterpret_cast<unsigned*>(bytes + 0x188) = 0;
            if (flags == 4) {
                const unsigned version = FUN_1423cb260();
                *reinterpret_cast<unsigned*>(bytes + 0x188) = version;
                FUN_1423ca660(reinterpret_cast<void*>(manager[0xf]), version);
            }
            break;
        }
        if (flags == 0x1000000) {
            String unsupported("Not Supported");
            FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &unsupported);
        }
    }
    const unsigned currentMode = *reinterpret_cast<unsigned*>(bytes + 0x84);
    if (currentMode == 0x400 || currentMode == 0x2000) return;
    if (flags == 0x1000000 || (flags & 0xf00000)) return;
    provider = reinterpret_cast<void*>(manager[0xf]);
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[0x98 / sizeof(void*)])(provider);
}

// MS2-FUNCTIONAL: ITfInputProcessorProfileActivationSink::OnActivated: refreshes the mode and locale label, then
// resolves the activated TSF profile (or plain keyboard layout) to its record text and conversion flags.
// @0x1423d6c10
unsigned long long FUN_1423d6c10(long long raw, int profileType, unsigned short language,
                                long long* clsid, long long* catid, long long* guidProfile, unsigned long long hkl)
{
    static const GUID kIIDProfiles =
        {0x1f02b6c5, 0x7842, 0x4ee6, {0x8a, 0x0b, 0x9a, 0x24, 0x18, 0x3a, 0x95, 0xca}};
    static const GUID kIIDProfileMgr =
        {0x71c6e74c, 0x0f28, 0x11d8, {0xa8, 0x2a, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c}};
    struct Profile {
        unsigned profileType; unsigned short langid; unsigned short pad;
        unsigned long long clsid[2]; unsigned long long guidProfile[2]; unsigned long long catid[2];
        unsigned long long hklSubstitute; unsigned caps; unsigned pad2; unsigned long long hkl; unsigned flags;
    };
    BSTR description = SysAllocStringByteLen(nullptr, 0);
    IUnknown* profiles = nullptr;
    if (FAILED(CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr, CLSCTX_INPROC_SERVER,
                                kIIDProfiles, reinterpret_cast<void**>(&profiles)))) return 0;
    IUnknown* profileMgr = nullptr;
    if (FAILED(profiles->QueryInterface(kIIDProfileMgr, reinterpret_cast<void**>(&profileMgr)))) return 0;
    Profile profile;
    const unsigned long long layout = profileType == 1 ? 0 : hkl;
    reinterpret_cast<HRESULT(*)(void*, int, unsigned short, long long*, long long*, unsigned long long, Profile*)>(
        (*reinterpret_cast<void***>(profileMgr))[5])(profileMgr, profileType, language, clsid, guidProfile, layout,
                                                    &profile);
    if (!profile.guidProfile[0] && !profile.guidProfile[1] && !profile.catid[0] && !profile.catid[1] &&
        !static_cast<unsigned>(profile.hkl))
        return 1;
    if (profileMgr) profileMgr->Release();
    if (!profiles) return 1;
    auto* manager = reinterpret_cast<long long*>(raw - 0x1a8);
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned short)>(
        (*reinterpret_cast<void***>(manager))[4])(manager, language);
    wchar_t locale[0x104]{};
    GetLocaleInfoW(language, LOCALE_SLANGUAGE, locale, 0x104);
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    if (void* provider = reinterpret_cast<void*>(manager[0xf])) {
        FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(provider), mode);
        String localeText(locale);
        provider = reinterpret_cast<void*>(manager[0xf]);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(provider))[0x78 / sizeof(void*)])(
            provider, localeText.ToCStr());
    }
    reinterpret_cast<HRESULT(*)(void*, long long*, unsigned short, long long*, BSTR*)>(
        (*reinterpret_cast<void***>(profiles))[12])(profiles, clsid, language, guidProfile, &description);
    if (!SysStringLen(description)) {
        const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x160);
        manager[0x33] = static_cast<long long>(layout);
        {
            String empty("");
            FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &empty);
        }
        if (layout != 0x4120412) {
            struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
            const auto* records = reinterpret_cast<const LayoutRecord*>(manager[0x2b]);
            bool imeLayout = false;
            for (unsigned i = 0; i < count; ++i) {
                if (records[i].layoutId == static_cast<unsigned>(layout) && std::strlen(records[i].imeFile)) {
                    imeLayout = true;
                    break;
                }
            }
            if (!imeLayout) {
                String localeText(locale);
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &localeText);
                profiles->Release();
                return 1;
            }
        }
    }
    auto& flags = *reinterpret_cast<unsigned*>(bytes + 0x88);
    flags = 0x1000000;
    const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0xd0);
    for (unsigned i = 0; i < count; ++i) {
        auto* entries = reinterpret_cast<unsigned char*>(manager[0x17]);
        for (auto* node = *reinterpret_cast<unsigned char**>(entries + i * 0x30 + 0x28); node;
             node = *reinterpret_cast<unsigned char**>(node + 8)) {
            Profile candidate;
            std::memcpy(&candidate, *reinterpret_cast<void**>(node), 0x50);
            if (candidate.langid != language ||
                candidate.clsid[0] != static_cast<unsigned long long>(clsid[0]) ||
                candidate.clsid[1] != static_cast<unsigned long long>(clsid[1]) ||
                candidate.catid[0] != static_cast<unsigned long long>(catid[0]) ||
                candidate.catid[1] != static_cast<unsigned long long>(catid[1]) ||
                candidate.hkl != layout ||
                candidate.guidProfile[0] != static_cast<unsigned long long>(guidProfile[0]) ||
                candidate.guidProfile[1] != static_cast<unsigned long long>(guidProfile[1]) ||
                candidate.hklSubstitute != profile.hklSubstitute)
                continue;
            flags = *reinterpret_cast<unsigned*>(entries + i * 0x30 + 0x20);
            FUN_1423ca640(reinterpret_cast<void*>(manager[0xf]), flags);
            if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 2) {
                String text(*reinterpret_cast<String*>(reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30 + 0x18));
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &text);
            }
            if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 1) {
                String text(*reinterpret_cast<String*>(reinterpret_cast<unsigned char*>(manager[0x17]) + i * 0x30 + 0x10));
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &text);
            }
            void* provider = reinterpret_cast<void*>(manager[0xf]);
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[0x98 / sizeof(void*)])(provider);
            if (SysStringLen(description)) SysFreeString(description);
            profiles->Release();
            return 1;
        }
    }
    {
        String unsupported("Not Supported");
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), &unsupported);
    }
    if (SysStringLen(description)) SysFreeString(description);
    profiles->Release();
    return 1;
}

unsigned long long FUN_1423cb980(long long* manager, long long layouts, unsigned count);

// MS2-FUNCTIONAL: enumerates the installed keyboard layouts and TSF language profiles into the language list
// (+0x90 entries, "@@"-joined +0x70 names, +0x80 count) and refreshes the active layout, flags and mode.
// @0x1423d8140
unsigned FUN_1423d8140(long long* manager)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    void** vtable = *reinterpret_cast<void***>(manager);
    *reinterpret_cast<unsigned*>(self + 0x88) = 0x1000000;
    *reinterpret_cast<unsigned*>(self + 0x84) = 0x1000000;
    const unsigned count = static_cast<unsigned>(GetKeyboardLayoutList(0, nullptr));
    if (!count) {
        reinterpret_cast<void(*)(void*, const char*, const char*)>(vtable[0xe])(
            manager, "No IME's Installed!", "GFxIME Error");
        return 1;
    }
    auto* layouts = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(count * sizeof(HKL)));
    GetKeyboardLayoutList(static_cast<int>(count), reinterpret_cast<HKL*>(layouts));
    // Each HKL goes through +0x198 with its high dword cleared and is written back.
    for (unsigned i = 0; i < count; ++i) {
        *reinterpret_cast<unsigned long long*>(self + 0x198) = layouts[i];
        *reinterpret_cast<unsigned*>(self + 0x19c) = 0;
        layouts[i] = *reinterpret_cast<unsigned long long*>(self + 0x198);
    }
    const unsigned char registryFailed = static_cast<unsigned char>(
        FUN_1423cb980(manager, reinterpret_cast<long long>(layouts), count));
    Scaleform::Memory::Free(layouts);
    if (registryFailed) return registryFailed;

    auto* states = *reinterpret_cast<unsigned**>(self + 0x190);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xd0); ++i) states[i] = 0;

    auto* layoutRecords = reinterpret_cast<unsigned char*>(*reinterpret_cast<void**>(self + 0x158));
    IUnknown* profiles = nullptr;
    const HRESULT created = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068), reinterpret_cast<void**>(&profiles));
    bool fromLayouts = true;
    if (created < 0) {
        reinterpret_cast<void(*)(void*, HRESULT, const char*)>(vtable[0xf])(
            manager, created, "GFxIME Error: Failure to Initialize InputProcessorProfiles!");
    } else if (profiles) {
        fromLayouts = false;
        void** profileVtable = *reinterpret_cast<void***>(profiles);
        LANGID* languages = nullptr;
        ULONG languageCount = 0;
        if (reinterpret_cast<HRESULT(*)(void*, LANGID**, ULONG*)>(profileVtable[15])(
                profiles, &languages, &languageCount) >= 0) {
            for (ULONG i = 0; i < languageCount; ++i) {
                wchar_t localeName[0x104];
                if (!GetLocaleInfoW(languages[i], LOCALE_SLANGUAGE, localeName, 0x104)) continue;
                IUnknown* profileEnum = nullptr;
                reinterpret_cast<HRESULT(*)(void*, LANGID, IUnknown**)>(profileVtable[16])(
                    profiles, languages[i], &profileEnum);
                // TF_LANGUAGEPROFILE: clsid, langid @0x10, catid @0x14, fActive @0x24, guidProfile @0x28.
                unsigned char profile[0x38] = {};
                *reinterpret_cast<LANGID*>(profile + 0x10) = languages[i];
                FUN_1423d7bc0(manager, profile, localeName);
                BSTR description = SysAllocString(nullptr);
                Scaleform::String unused;
                if (profileEnum) {
                    void** enumVtable = *reinterpret_cast<void***>(profileEnum);
                    auto next = reinterpret_cast<HRESULT(*)(void*, ULONG, void*, ULONG*)>(enumVtable[4]);
                    while (next(profileEnum, 1, profile, nullptr) != 1) {
                        reinterpret_cast<HRESULT(*)(void*, const void*, LANGID, const void*, BSTR*)>(profileVtable[12])(
                            profiles, profile, *reinterpret_cast<LANGID*>(profile + 0x10), profile + 0x28, &description);
                        if (SysStringLen(description)) {
                            SysFreeString(description);
                            description = nullptr;
                        }
                    }
                    profileEnum->Release();
                }
            }
            CoTaskMemFree(languages);
        }
    }

    if (fromLayouts) {
        // No TSF: list the loaded registry layouts by language, once per mode.
        auto* entries = reinterpret_cast<unsigned long long*>(self + 0x90);
        const unsigned long long layoutCount = *reinterpret_cast<unsigned long long*>(self + 0x160);
        for (unsigned i = 0; i < layoutCount; ++i) {
            unsigned char* layout = layoutRecords + i * 0x18;
            if (!*reinterpret_cast<unsigned*>(layout + 0x14)) continue;
            const unsigned id = *reinterpret_cast<unsigned*>(layout + 0x10) & 0xfff;
            unsigned mode = 0x1000000;
            Scaleform::String name;
            if (id == 0x409) { mode = 0x10000000; name = "English"; }
            if (id == 0x404) { mode = 9; name = "Chinese (Traditional)"; }
            if (id == 0x804) { mode = 0x80000; name = "Chinese (Simplified)"; }
            if (id == 0x412) { mode = 0x2000; name = "Korean"; }
            if (id == 0x411) { mode = 0x400; name = "Japanese"; }
            if (mode == 0x1000000) continue;
            bool listed = false;
            for (unsigned j = 0; j < entries[1]; ++j) {
                if (*reinterpret_cast<unsigned*>(entries[0] + j * 0x20ull + 0x10) == mode) { listed = true; break; }
            }
            if (listed) continue;
            const size_t length = name.GetSize();
            char* copy = static_cast<char*>(Scaleform::Memory::Alloc(length + 1));
            std::memcpy(copy, name.ToCStr(), length + 1);
            const unsigned long long nextSize = entries[1] + 1;
            if (nextSize >= entries[2]) FUN_1423d7370(entries, entries, nextSize + (nextSize >> 2));
            entries[1] = nextSize;
            auto* entry = reinterpret_cast<unsigned char*>(entries[0]) + (nextSize - 1) * 0x20;
            *reinterpret_cast<char**>(entry) = copy;
            *reinterpret_cast<unsigned long long*>(entry + 8) = 0;
            *reinterpret_cast<unsigned*>(entry + 0x10) = mode;
            *reinterpret_cast<unsigned*>(entry + 0x14) = 0;
            *reinterpret_cast<unsigned long long*>(entry + 0x18) = id;
            *reinterpret_cast<Scaleform::String*>(self + 0x70) += name + "@@";
            ++*reinterpret_cast<unsigned*>(self + 0x80);
        }
    }

    // Bind each loaded registry layout to its IME record; the active one supplies the flags.
    const unsigned long long active = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0));
    auto* imeRecords = reinterpret_cast<unsigned char*>(*reinterpret_cast<void**>(self + 0xb8));
    for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x160); ++i) {
        unsigned char* layout = layoutRecords + i * 0x18;
        if (!*reinterpret_cast<unsigned*>(layout + 0x14)) continue;
        const int index = reinterpret_cast<int(*)(void*, const char*, const char*)>(vtable[16])(
            manager, *reinterpret_cast<const char**>(layout + 8), *reinterpret_cast<const char**>(layout));
        if (index == -1) continue;
        const unsigned long long id = *reinterpret_cast<unsigned*>(layout + 0x10);
        *reinterpret_cast<unsigned long long*>(imeRecords + index * 0x30ll + 0x28) = id;
        *reinterpret_cast<unsigned long long*>(self + 0x198) = id;
        if (id == active)
            *reinterpret_cast<unsigned*>(self + 0x88) = *reinterpret_cast<unsigned*>(imeRecords + index * 0x30ll + 0x20);
    }
    if (profiles) {
        LANGID current = 0;
        reinterpret_cast<HRESULT(*)(void*, LANGID*)>((*reinterpret_cast<void***>(profiles))[13])(profiles, &current);
    }

    const unsigned long long language = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0)) & 0xfff;
    *reinterpret_cast<unsigned*>(self + 0x84) = 0x1000000;
    *reinterpret_cast<unsigned long long*>(self + 0x198) = language;
    auto* entries = *reinterpret_cast<unsigned char**>(self + 0x90);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0x80); ++i) {
        if (*reinterpret_cast<unsigned long long*>(entries + i * 0x20ull + 0x18) == language)
            *reinterpret_cast<unsigned*>(self + 0x84) = *reinterpret_cast<unsigned*>(entries + i * 0x20ull + 0x10);
    }
    return 0;
}

// MS2-FUNCTIONAL: enumerates HKLM\SYSTEM\CurrentControlSet\Control\Keyboard Layouts and appends one 0x18-byte record
// per layout to the array at +0x158: { UTF-8 "IME File", UTF-8 "Layout Text", layout id, whether the id is among the
// count loaded HKLs }. The subkey id is also parsed into +0x198. Per-subkey errors are logged and skipped; returns
// true when the root key cannot be opened or queried.
// @0x1423cb980
unsigned long long FUN_1423cb980(long long* manager, long long layouts, unsigned count)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    auto* logError = reinterpret_cast<void(*)(void*, DWORD, const char*)>(
        (*reinterpret_cast<void***>(manager))[0x78 / sizeof(void*)]);
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    ::Scaleform::String unused;
    DWORD subkeyCount = 0;
    HKEY root = nullptr;
    LONG error = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts", 0,
                               KEY_READ, &root);
    if (error) {
        logError(manager, error, "GFxIME Error:Opening Registry Key failed ");
        return 1;
    }
    FILETIME written;
    error = RegQueryInfoKeyW(root, nullptr, nullptr, nullptr, &subkeyCount, nullptr, nullptr, nullptr, nullptr,
                             nullptr, nullptr, &written);
    if (error) {
        logError(manager, error, "GFxIME Error:Retrieving subkey information failed ");
        return 1;
    }
    char keyName[0x400];
    wchar_t layoutText[0x400], imeFile[0x400];
    char layoutTextUtf8[0x800], imeFileUtf8[0x800];
    for (DWORD i = 0; i < subkeyCount; ++i) {
        DWORD nameLength = 0x400, valueSize = 0x400;
        error = RegEnumKeyExA(root, i, keyName, &nameLength, nullptr, nullptr, nullptr, &written);
        if (error) {
            logError(manager, error, "GFxIME Error:Enumerating Registry Subkeys Failed ");
            continue;
        }
        sscanf(keyName, "%x", reinterpret_cast<unsigned*>(self + 0x198));
        HKEY subkey = nullptr;
        error = RegOpenKeyExA(root, keyName, 0, KEY_QUERY_VALUE, &subkey);
        if (error) {
            logError(manager, error, "GFxIME Error:Opening Registry subkey Failed ");
            continue;
        }
        if (RegQueryValueExW(subkey, L"Layout Text", nullptr, nullptr, reinterpret_cast<BYTE*>(layoutText), &valueSize))
            memset(layoutText, 0, sizeof(layoutText));
        valueSize = 0x400;
        error = RegQueryValueExW(subkey, L"IME File", nullptr, nullptr, reinterpret_cast<BYTE*>(imeFile), &valueSize);
        if (error) {
            if ((*reinterpret_cast<unsigned*>(self + 0x198) & 0xe000000) == 0xe000000) {
                ::Scaleform::String message = ::Scaleform::String("GFxIME Error:Obtaining IME Filename failed for ") + keyName;
                logError(manager, error, message.ToCStr());
            }
            memset(imeFile, 0, sizeof(imeFile));
        }
        RegCloseKey(subkey);
        ::Scaleform::UTF8Util::EncodeString(layoutTextUtf8, layoutText, -1);
        ::Scaleform::UTF8Util::EncodeString(imeFileUtf8, imeFile, -1);
        LayoutRecord record;
        sscanf(keyName, "%x", &record.layoutId);
        const size_t textSize = strlen(layoutTextUtf8) + 1;
        record.layoutText = static_cast<char*>(::Scaleform::Memory::Alloc(textSize));
        if (record.layoutText) strcpy_s(record.layoutText, textSize, layoutTextUtf8);
        const size_t imeSize = strlen(imeFileUtf8) + 1;
        record.imeFile = static_cast<char*>(::Scaleform::Memory::Alloc(imeSize));
        if (record.imeFile) strcpy_s(record.imeFile, imeSize, imeFileUtf8);
        record.loaded = 0;
        const unsigned long long current = *reinterpret_cast<unsigned long long*>(self + 0x198);
        for (unsigned j = 0; j < count; ++j) {
            if (reinterpret_cast<unsigned long long*>(layouts)[j] == current) {
                record.loaded = 1;
                break;
            }
        }
        auto* records = reinterpret_cast<unsigned long long*>(self + 0x158);   // { data, size, capacity }
        const unsigned long long size = records[1] + 1;
        if (size >= records[2]) FUN_1423cc680(records, records, size + (size >> 2));
        records[1] = size;
        reinterpret_cast<LayoutRecord*>(records[0])[size - 1] = record;
    }
    RegCloseKey(root);
    return 0;
}

// MS2-FUNCTIONAL: Vista provider slot 1 (table 0x14313b520): loads the registry layouts, lists each TSF language
// (FUN_1423d5d80) and registers every enabled or active keyboard profile with its IME record (FUN_1423cada0),
// chaining a copy of the profile onto the record's +0x28 list; the active profile sets +0x88 and the mode.
// @0x1423d64b0
unsigned long long FUN_1423d64b0(long long raw)
{
    auto* manager = reinterpret_cast<long long*>(raw);
    auto* self = reinterpret_cast<unsigned char*>(raw);
    static const GUID kIIDProfiles =
        {0x1f02b6c5, 0x7842, 0x4ee6, {0x8a, 0x0b, 0x9a, 0x24, 0x18, 0x3a, 0x95, 0xca}};
    static const GUID kIIDProfileMgr =
        {0x71c6e74c, 0x0f28, 0x11d8, {0xa8, 0x2a, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c}};
    static const GUID kCategoryKeyboard =
        {0x34745c63, 0xb2f0, 0x4784, {0x8b, 0x67, 0x5e, 0x12, 0xc8, 0x70, 0x1a, 0x31}};
    // TF_INPUTPROCESSORPROFILE.
    struct Profile {
        DWORD profileType; LANGID language; GUID clsid; GUID guidProfile; GUID category;
        HKL hklSubstitute; DWORD caps; HKL hkl; DWORD flags;
    };
    *reinterpret_cast<unsigned*>(self + 0x88) = 0x1000000;
    *reinterpret_cast<unsigned*>(self + 0x84) = 0x1000000;
    FUN_1423cb980(manager, 0, 0);
    auto* states = *reinterpret_cast<unsigned**>(self + 0x190);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xd0); ++i) states[i] = 0;

    IUnknown* profiles = nullptr;
    if (FAILED(CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr, CLSCTX_INPROC_SERVER,
                                kIIDProfiles, reinterpret_cast<void**>(&profiles))) || !profiles) return 1;
    IUnknown* profileMgr = nullptr;
    const HRESULT queried = profiles->QueryInterface(kIIDProfileMgr, reinterpret_cast<void**>(&profileMgr));
    *reinterpret_cast<unsigned*>(self + 0x88) = 0x1000000;
    if (FAILED(queried) || !profileMgr) return 1;
    void** profileVtable = *reinterpret_cast<void***>(profiles);
    void** mgrVtable = *reinterpret_cast<void***>(profileMgr);

    Profile active;
    reinterpret_cast<HRESULT(*)(void*, const GUID&, Profile*)>(mgrVtable[10])(profileMgr, kCategoryKeyboard, &active);
    LANGID* languages = nullptr;
    ULONG languageCount = 0;
    if (reinterpret_cast<HRESULT(*)(void*, LANGID**, ULONG*)>(profileVtable[15])(
            profiles, &languages, &languageCount) >= 0) {
        for (ULONG i = 0; i < languageCount; ++i) {
            wchar_t localeName[0x104];
            if (!GetLocaleInfoW(languages[i], LOCALE_SLANGUAGE, localeName, 0x104)) continue;
            IUnknown* profileEnum = nullptr;
            reinterpret_cast<HRESULT(*)(void*, LANGID, IUnknown**)>(mgrVtable[6])(
                profileMgr, languages[i], &profileEnum);
            Profile profile = {};
            profile.language = languages[i];
            FUN_1423d5d80(manager, &profile, localeName);
            BSTR description = SysAllocString(nullptr);
            Scaleform::String layoutText;
            Scaleform::String imeFile;
            if (profileEnum) {
                void** enumVtable = *reinterpret_cast<void***>(profileEnum);
                auto next = reinterpret_cast<HRESULT(*)(void*, ULONG, Profile*, ULONG*)>(enumVtable[4]);
                while (next(profileEnum, 1, &profile, nullptr) == S_OK) {
                    SysFreeString(description);
                    layoutText.Clear();
                    reinterpret_cast<HRESULT(*)(void*, const GUID&, LANGID, const GUID&, BSTR*)>(profileVtable[12])(
                        profiles, profile.clsid, profile.language, profile.guidProfile, &description);
                    // Descriptions holding '%' are unresolved resource strings; skip those profiles.
                    bool unresolved = false;
                    if (description) {
                        const size_t length = Scaleform::SFwcslen(description);
                        for (size_t c = 0; c < length; ++c) {
                            if (description[c] == L'%') { unresolved = true; break; }
                        }
                    }
                    if (unresolved) continue;
                    const DWORD flags = profile.flags;
                    if (!(flags & 3)) continue;
                    const unsigned hkl = static_cast<unsigned>(reinterpret_cast<ULONG_PTR>(profile.hkl));
                    const unsigned substitute = static_cast<unsigned>(reinterpret_cast<ULONG_PTR>(profile.hklSubstitute));
                    if (!profile.hkl && !profile.hklSubstitute) {
                        layoutText = description;
                    } else {
                        // Match a registry layout: the Korean IME by its low word, others by HKL or substitute.
                        auto* layouts = static_cast<unsigned char*>(*reinterpret_cast<void**>(self + 0x158));
                        const unsigned long long layoutCount = *reinterpret_cast<unsigned long long*>(self + 0x160);
                        bool matched = false;
                        bool needsDescription = false;
                        for (unsigned j = 0; j < layoutCount; ++j) {
                            unsigned char* layout = layouts + j * 0x18;
                            const unsigned id = *reinterpret_cast<unsigned*>(layout + 0x10);
                            if (hkl == 0x4120412) {
                                if ((hkl & 0xffff) != id) continue;
                                layoutText = *reinterpret_cast<const char**>(layout + 8);
                                matched = true;
                                break;
                            }
                            if (hkl != id && substitute != id) continue;
                            layoutText = *reinterpret_cast<const char**>(layout + 8);
                            imeFile = *reinterpret_cast<const char**>(layout);
                            matched = true;
                            needsDescription = true;
                            break;
                        }
                        if (!matched || (needsDescription && imeFile.IsEmpty())) {
                            if (flags & 1) *reinterpret_cast<unsigned*>(self + 0x88) = 0x3000000;
                            continue;
                        }
                        if (needsDescription && layoutText.IsEmpty() && description) layoutText = description;
                    }
                    if (layoutText.IsEmpty()) continue;
                    const int index = FUN_1423cada0(reinterpret_cast<unsigned long long*>(manager),
                        layoutText.ToCStr(), imeFile.ToCStr(), profile.language);
                    void* log = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0x78) + 0x60);
                    if (log) {
                        FUN_1423cd060(log, (Scaleform::String("Registering IME: ") + layoutText +
                            Scaleform::String("\n")).ToCStr());
                    }
                    imeFile.Clear();
                    layoutText.Clear();
                    if (index == -1) continue;
                    auto* copy = static_cast<Profile*>(Scaleform::Memory::Alloc(sizeof(Profile)));
                    *copy = profile;
                    auto* node = static_cast<void**>(Scaleform::Memory::Alloc(0x10));
                    auto* record = *reinterpret_cast<unsigned char**>(self + 0xb8) + index * 0x30ll;
                    node[0] = copy;
                    node[1] = *reinterpret_cast<void**>(record + 0x28);
                    *reinterpret_cast<void**>(record + 0x28) = node;
                    if (flags & 1) *reinterpret_cast<unsigned*>(self + 0x88) = *reinterpret_cast<unsigned*>(record + 0x20);
                }
                profileEnum->Release();
            }
            SysFreeString(description);
        }
        CoTaskMemFree(languages);
    }

    auto* entries = *reinterpret_cast<unsigned char**>(self + 0x90);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0x80); ++i) {
        if (*reinterpret_cast<unsigned long long*>(entries + i * 0x20ull + 0x18) == active.language)
            *reinterpret_cast<unsigned*>(self + 0x84) = *reinterpret_cast<unsigned*>(entries + i * 0x20ull + 0x10);
    }
    profiles->Release();
    profileMgr->Release();
    return 0;
}

// MS2-FUNCTIONAL: TSF BeginUIElement on the UI-element sink. Clears the manager's +0xc0 flag and the sink's candidate
// state at +0x70..+0xa1 and sets *show = FALSE. Unless the manager is in mode 0x1000000/0x2000000 or its vtable +0x30
// check fails, it bumps the manager's +0xbc counter and, when the manager's String at +0x10 is not empty, calls
// RemoveList() and then CreateList(10.0, 1.0). It clears the sink's +0x55/+0x56 flags and walks the enumerator from
// the first method of the thread manager's IID ba468c55 interface, calling each element's first method.
// @0x1423da440
unsigned long long FUN_1423da440(long long raw, unsigned long long, unsigned* result)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    static const GUID kProfileIid = { 0xba468c55, 0x9956, 0x4fb1, { 0xa5, 0x9d, 0x52, 0xa7, 0xdd, 0x7c, 0xc6, 0xaa } };
    auto* self = reinterpret_cast<unsigned char*>(raw);
    auto* manager = *reinterpret_cast<unsigned char**>(self + 8);
    manager[0xc0] = 0;
    std::memset(self + 0x70, 0, 0x32);
    *result = 0;
    const unsigned mode = *reinterpret_cast<unsigned*>(manager + 0x98);
    if (((mode - 0x1000000) & 0xfeffffff) == 0) return 0;
    if (!reinterpret_cast<bool(*)(void*, void*)>((*reinterpret_cast<void***>(manager))[0x30 / sizeof(void*)])(
            manager, *reinterpret_cast<void**>(manager + 8)))
        return 0;
    ++*reinterpret_cast<int*>(manager + 0xbc);
    if (reinterpret_cast<Scaleform::String*>(manager + 0x10)->GetLength()) {
        Scaleform::GFx::Value args[2];
        args[0] = Scaleform::GFx::Value(10.0);
        args[1] = Scaleform::GFx::Value(1.0);
        Scaleform::GFx::Value invokeResult;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveList", &invokeResult, nullptr, 0);
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "CreateList", &invokeResult, args, 2);
    }
    void* owner = *reinterpret_cast<void**>(manager + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    *reinterpret_cast<unsigned short*>(self + 0x55) = 0;
    IUnknown* threadManager = *reinterpret_cast<IUnknown**>(self + 0x20);
    IUnknown* profiles = nullptr;
    if (threadManager->QueryInterface(kProfileIid, reinterpret_cast<void**>(&profiles)) >= 0 && profiles) {
        IUnknown* items = nullptr;
        if (reinterpret_cast<HRESULT(*)(IUnknown*, IUnknown**)>((*reinterpret_cast<void***>(profiles))[3])(
                profiles, &items) == S_OK) {
            typedef HRESULT (*NextFn)(IUnknown*, ULONG, IUnknown**, ULONG*);
            IUnknown* item = nullptr;
            while (reinterpret_cast<NextFn>((*reinterpret_cast<void***>(items))[4])(items, 1, &item, nullptr) == S_OK) {
                unsigned char scratch[0x70];
                reinterpret_cast<HRESULT(*)(IUnknown*, void*)>((*reinterpret_cast<void***>(item))[3])(item, scratch);
                item->Release();
            }
            items->Release();
        }
        profiles->Release();
    }
    return 0;
}

// MS2-FUNCTIONAL: TSF UpdateUIElement on the IME UI-element sink. It gets the element from ITfUIElementMgr. A reading
// element copies its reading string to the manager's String at +0xb0 and calls MakeInvisible, plus RemoveList when
// the sink's +0x55 flag is set. A candidate-list element first calls CreateList(10.0, 0/1) once. It then reads the
// current page's range (GetPageIndex / GetCurrentPage / GetSelection), selects the item, and refills the manager's
// candidate list at +0x30 with the page's strings as UTF-8. The COM calls go through the same pointers the exe uses:
// the GetUIElement result for GetPageIndex(NULL, 0, &n), GetUpdatedFlags and GetString, and the QI'd candidate
// pointer for the rest.
// @0x1423db0c0
unsigned long long FUN_1423db0c0(long long raw, unsigned message)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    static const GUID kUIElementMgrIid = { 0xea1ea135, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    static const GUID kCandidateListIid = { 0xea1ea138, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    static const GUID kReadingInfoIid = { 0xea1ea139, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    auto* self = reinterpret_cast<unsigned char*>(raw);
    const unsigned id = message;
    IUnknown* uiManager = nullptr;
    IUnknown* element = nullptr;
    IUnknown* candidates = nullptr;
    IUnknown* reading = nullptr;
    BSTR readingText = nullptr;
    BSTR description = nullptr;
    GUID guid;
    UINT count = 0;
    auto* manager = *reinterpret_cast<unsigned char**>(self + 8);
    const unsigned mode = *reinterpret_cast<unsigned*>(manager + 0x98);
    if (((mode - 0x1000000) & 0xfeffffff) == 0) return 0;
    if (!reinterpret_cast<bool(*)(void*, void*)>((*reinterpret_cast<void***>(manager))[0x30 / sizeof(void*)])(
            manager, *reinterpret_cast<void**>(manager + 8)))
        return 0;
    if ((*reinterpret_cast<IUnknown**>(self + 0x20))->QueryInterface(kUIElementMgrIid,
            reinterpret_cast<void**>(&uiManager)) < 0)
        return 0;
    reinterpret_cast<HRESULT(*)(IUnknown*, DWORD, IUnknown**)>((*reinterpret_cast<void***>(uiManager))[6])(
        uiManager, id, &element);
    if (element->QueryInterface(kCandidateListIid, reinterpret_cast<void**>(&candidates)) >= 0) candidates->Release();
    reinterpret_cast<HRESULT(*)(IUnknown*, GUID*)>((*reinterpret_cast<void***>(element))[4])(element, &guid);
    reinterpret_cast<HRESULT(*)(IUnknown*, BSTR*)>((*reinterpret_cast<void***>(element))[3])(element, &description);
    if (element->QueryInterface(kReadingInfoIid, reinterpret_cast<void**>(&reading)) >= 0) {
        reinterpret_cast<HRESULT(*)(IUnknown*, BSTR*)>((*reinterpret_cast<void***>(reading))[9])(reading, &readingText);
        *reinterpret_cast<unsigned*>(self + 0x4c) = id;
        if (readingText) {
            unsigned char* owner = *reinterpret_cast<unsigned char**>(self + 8);
            *reinterpret_cast<Scaleform::String*>(owner + 0xb0) = static_cast<const wchar_t*>(readingText);
            if (owner[0xb8])
                reinterpret_cast<void(*)(void*, const wchar_t*)>((*reinterpret_cast<void***>(owner))[0xb0 / sizeof(void*)])(
                    owner, readingText);
        }
        unsigned char* owner = *reinterpret_cast<unsigned char**>(self + 8);
        if (*reinterpret_cast<void**>(owner + 8)) {
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(owner + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "MakeInvisible", &result, nullptr, 0);
        }
        if (self[0x55] == 1) {
            owner = *reinterpret_cast<unsigned char**>(self + 8);
            if (*reinterpret_cast<void**>(owner + 8)) {
                Scaleform::GFx::Value result;
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(owner + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "RemoveList", &result, nullptr, 0);
            }
            self[0x56] = 0;
        }
        self[0x55] = 1;
        reading->Release();
    }
    if (element->QueryInterface(kCandidateListIid, reinterpret_cast<void**>(&candidates)) >= 0) {
        *reinterpret_cast<unsigned*>(self + 0x5c) = id;
        self[0x55] = 0;
        if (!self[0x56]) {
            unsigned char* owner = *reinterpret_cast<unsigned char**>(self + 8);
            const unsigned state = *reinterpret_cast<unsigned*>(owner + 0x98);
            const int vertical = (state == 0xd00001 || state == 5) ? 0 : 1;
            Scaleform::GFx::Value args[2];
            args[0] = Scaleform::GFx::Value(10.0);
            args[1] = Scaleform::GFx::Value(static_cast<double>(vertical));
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(owner + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "CreateList", &result, args, 2);
            {
                void* stateOwner = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 8) + 8);
                Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime = reinterpret_cast<Scaleform::GFx::StateBag*>(
                    static_cast<unsigned char*>(stateOwner) + 0x10)->GetIMEManager();
                self[0x56] = 1;
            }
        }
        reinterpret_cast<HRESULT(*)(IUnknown*, UINT*)>((*reinterpret_cast<void***>(candidates))[9])(candidates, &count);
        if (count) {
            UINT pageCount = 0, currentPage = 0, selection = 0;
            DWORD flags = 0;
            UINT* pages = nullptr;
            BSTR text = nullptr;
            *reinterpret_cast<unsigned*>(self + 0x48) = id;
            reinterpret_cast<HRESULT(*)(IUnknown*, UINT*, UINT, UINT*)>((*reinterpret_cast<void***>(element))[0xc])(
                element, nullptr, 0, &pageCount);
            reinterpret_cast<HRESULT(*)(IUnknown*, DWORD*)>((*reinterpret_cast<void***>(element))[7])(element, &flags);
            self[0x54] = ((flags & 0x24) == 0 || (flags & 8)) ? 1 : 0;
            UINT pageSize = count;
            if (pageCount) {
                pages = static_cast<UINT*>(Scaleform::Memory::Alloc((pageCount + 1) * sizeof(UINT)));
                reinterpret_cast<HRESULT(*)(IUnknown*, UINT*, UINT, UINT*)>((*reinterpret_cast<void***>(candidates))[0xc])(
                    candidates, pages, pageCount, &pageCount);
                if (pageCount > 1) pageSize = pages[1] - pages[0];
            }
            reinterpret_cast<HRESULT(*)(IUnknown*, UINT*)>((*reinterpret_cast<void***>(candidates))[0xe])(
                candidates, &currentPage);
            reinterpret_cast<HRESULT(*)(IUnknown*, UINT*)>((*reinterpret_cast<void***>(candidates))[0xa])(
                candidates, &selection);
            // The exe reads pages[currentPage] unguarded; pages is null when GetPageIndex reported no pages.
            const UINT start = pages ? pages[currentPage] : 0;
            *reinterpret_cast<UINT*>(self + 0x58) = start;
            UINT shown;
            unsigned char* owner = *reinterpret_cast<unsigned char**>(self + 8);
            if ((*reinterpret_cast<unsigned*>(owner + 0x98) & 0xf0f) == 0) {
                if (currentPage == pageCount - 1) shown = count - start;
                else shown = pages ? pages[currentPage + 1] - pages[currentPage] : count;
            } else {
                shown = count;
                if (shown >= pageSize) shown = (currentPage + 1) * pageSize > shown ? shown % pageSize : pageSize;
            }
            if (pages) Scaleform::Memory::Free(pages);
            owner = *reinterpret_cast<unsigned char**>(self + 8);
            if (static_cast<int>(selection) >= 0)
                FUN_1423d97f0(*reinterpret_cast<void**>(owner + 0x30), static_cast<unsigned>(selection - start), 1);
            owner = *reinterpret_cast<unsigned char**>(self + 8);
            FUN_1423d9500(*reinterpret_cast<void**>(owner + 0x30));
            UINT missing = 0;
            for (UINT i = 0; i < shown; ++i) {
                reinterpret_cast<HRESULT(*)(IUnknown*, UINT, BSTR*)>((*reinterpret_cast<void***>(element))[0xb])(
                    element, start + i, &text);
                if (!text) {
                    ++missing;
                    continue;
                }
                const SPInt size = Scaleform::UTF8Util::GetEncodeStringSize(text, -1) + 1;
                char* utf8 = static_cast<char*>(Scaleform::Memory::Alloc(size));
                Scaleform::UTF8Util::EncodeStringSafe(utf8, size, text, -1);
                auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
                if (item) {
                    FUN_1423cdb60(item, utf8);
                    ++*reinterpret_cast<int*>(item + 1);
                }
                unsigned long long retained = reinterpret_cast<unsigned long long>(item);
                FUN_1423d9490(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 8) + 0x30), &retained);
                Scaleform::Memory::Free(utf8);
                if (item) FUN_14257dcd0(item);
            }
            *reinterpret_cast<UINT*>(self + 0x50) = shown - missing;
            FUN_1423d9b40(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 8) + 0x30));
            owner = *reinterpret_cast<unsigned char**>(self + 8);
            owner[0xb9] = 1;
            owner = *reinterpret_cast<unsigned char**>(self + 8);
            if (*reinterpret_cast<unsigned*>(owner + 0x98) == 0x500) {
                reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(owner))[0x110 / sizeof(void*)])(
                    owner, -*reinterpret_cast<int*>(owner + 0x64));
                (*reinterpret_cast<unsigned char**>(self + 8))[0xb9] = 0;
            }
            candidates->Release();
        }
    }
    if (uiManager) uiManager->Release();
    if (element) element->Release();
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
    const unsigned count = *(unsigned*)((UByte*)self + 0x80);
    UByte* records = *(UByte**)((UByte*)self + 0x90);
    for (unsigned i = 0; i < count; ++i) {
        UByte* record = records + i * 0x20;
        if (*(unsigned*)((UByte*)record + 0x18) == (unsigned)id) return *(unsigned*)((UByte*)record + 0x10);
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
// MS2-PIN: ??_7MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c0a8
// MS2-PIN: ??_7HeapLimit@MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c090
// MS2-PIN: ??_7MemoryContext@GFx@Scaleform@@6B@ 0x14313ba60
