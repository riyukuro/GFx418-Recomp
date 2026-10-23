// Recovered from MapleStory2.exe: Scaleform GFx IME support.
// MS2-UNIT: sfr_ime_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c8a50-0x1423c8fa0 .text$mn
// MS2-RANGE: 0x1423ca350-0x1423dbde0 .text$mn
#include <windows.h>
#include <imm.h>
#include <cstdarg>
#include <vector>
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_string.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/as3/as3_support.h"

namespace Scaleform { namespace GFx { class Movie { public: void Release(); }; } }
namespace Scaleform { namespace GFx { namespace IME {
    unsigned char FUN_1423da320(void*, void*, void*, void*);
    void FUN_1423d9500(void*);
    void FUN_1425b43c0(void*);
    void FUN_1423d5fd0(void*);
    void FUN_1423c8bb0(unsigned long long*);
} } }
namespace Scaleform { namespace GFx { namespace AS3 { void SF_STDCALL DoAbcLoader(LoadProcess*, const TagInfo&); } } }
extern "C" void FUN_1425c8cf0(unsigned, void*);

static HIMC cx18_ImmGetContext(HWND hwnd)
{
    typedef HIMC (WINAPI* Fn)(HWND);
    return reinterpret_cast<Fn>(GetProcAddress(GetModuleHandleA("imm32.dll"), "ImmGetContext"))(hwnd);
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
extern "C" void FUN_14257db50(void*);
extern "C" void FUN_1423cdf60(void*);
extern "C" void FUN_1423cde00(void*);
extern "C" const void* DAT_14313a210[];
extern "C" const void* DAT_14313b920[];
extern "C" const void* DAT_14313b968[];
extern "C" const void* DAT_14313a228[];
extern "C" const void* DAT_14313a200[];
extern "C" void FUN_1423d9090(void*, unsigned long long, unsigned long long);
extern "C" void FUN_1423d9690(void*, void*, unsigned long long);
extern "C" void FUN_1423d95f0(void*, void*, unsigned long long);
extern "C" void FUN_1423d8b80(void*, void*, void*, unsigned long long);
unsigned HashFunction(const char*, unsigned long long);
extern "C" void FUN_14257dcd0(void*);
extern void FUN_14257dcb0(void*);
extern bool FUN_1425b9b10(void*);
extern "C" void FUN_14257db40(void*);
extern "C" void FUN_1423daf30(void*);
extern "C" void FUN_1423cc7c0(void*);
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
extern "C" const unsigned long long DAT_1431c4ef0;
extern "C" void* DAT_143b15f60;
extern "C" const void* DAT_14313bc60[];
extern "C" void FUN_1423dd1c0();
extern "C" void FUN_1423dc7b0();
extern "C" void FUN_1423ca030(void*, const char*, const char*, ...);
extern "C" void FUN_142576820(void*, const char*, void**, int);
extern "C" void FUN_1425b49b0();
extern "C" void FUN_14257dc30(void*);
extern "C" void FUN_1423c9330(unsigned long long, unsigned long long);
extern "C" void FUN_1422fbf60(void*);

struct HWND__;

namespace Scaleform { namespace GFx { namespace IME {

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

// MS2-FUNCTIONAL: constructor frame differs; the executable constructor also initializes opaque manager state.
// @0x1423c8a50
GFxIMEManagerWin32::GFxIMEManagerWin32(::HWND__* window)
    : refCount(1), refPad(0), state(0), statePad(0), p60(0), hwnd(window), p70(0), p78(0)
{
}

// MS2-FUNCTIONAL: opaque child pointers at +0x70 and +0x78 use executable-specific release thunks.
// @0x1423c8ac0
GFxIMEManagerWin32::~GFxIMEManagerWin32()
{
    if (p70)
        reinterpret_cast<void(*)(void*, unsigned int)>(*reinterpret_cast<void***>(p70))(p70, 1);
    if (p78)
        reinterpret_cast<void(*)(void*, unsigned int)>(*reinterpret_cast<void***>(p78))(p78, 1);
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
            void* result = nullptr;
            reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
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
        void* result = nullptr;
        reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
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
        void* result = nullptr;
        reinterpret_cast<void(*)(void*, const char*, void**, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                values, "RemoveInputWindow", &result, 0, 0);
    }
    cx18_ImmReleaseContext(hwnd, context);
}

// MS2-FUNCTIONAL: restores the three destructor vftable views, frees owned state, and honors scalar/sized delete flags.
// @0x1423d56b0
void* FUN_1423d56b0(void* self, unsigned long long flags)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<void***>(bytes) = DAT_14313b520;
    *reinterpret_cast<void***>(bytes + 0x1a0) = DAT_14313b5a0;
    *reinterpret_cast<void***>(bytes + 0x1a8) = DAT_14313b5c0;
    FUN_1423d5fd0(self);
    FUN_1423c8bb0(static_cast<unsigned long long*>(self));
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(self, 0x1d8);
        else {
            void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, self);
        }
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

// MS2-FUNCTIONAL: follows the executable's nested IME provider query and releases its temporary refcounted object.
// @0x1423ce460
unsigned char FUN_1423ce460(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* provider = *reinterpret_cast<void**>(bytes + 8);
    if (!provider) return 1;
    void* factory = static_cast<unsigned char*>(provider) + 0x10;
    void* temporary = reinterpret_cast<void*(*)(void*, unsigned)>(
        (*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
    if (!temporary) return 1;
    void* interfaceObject = *reinterpret_cast<void**>(static_cast<unsigned char*>(temporary) + 0x18);
    unsigned char result = reinterpret_cast<unsigned char(*)(void*)>(
        (*reinterpret_cast<void***>(interfaceObject))[0x70 / sizeof(void*)])(interfaceObject);
    FUN_14257dcb0(temporary);
    return result;
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

// MS2-FUNCTIONAL: deleting wrappers release the allocation when requested; the anonymous purecall-only interface is not declared in our headers.
// @0x1423ce2c0
void* FUN_1423ce2c0(void* object, unsigned long long flags)
{
    if (flags & 1)
        Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: deleting wrappers release the allocation when requested; the two equivalent anonymous purecall-only interfaces are not declared in our headers.
// @0x1423dbc50
void* FUN_1423dbc50(void* object, unsigned long long flags)
{
    if (flags & 1)
        Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: omits only the abstract purecall vptr store; allocation release follows the executable flag path.
// @0x1423dbc80
void* FUN_1423dbc80(void* object, unsigned long long flags)
{
    if (flags & 1)
        Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: destructor helper is recovered from its executable call target; the purecall-only vptr is not declared locally.
// @0x1423ce420
void* FUN_1423ce420(void* object, unsigned long long flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: executes child release and member cleanup in executable order; its anonymous abstract vptr is not declared locally.
// @0x1423d1b50
void FUN_1423d1b50(unsigned long long* object)
{
    Memory::Free(reinterpret_cast<void*>(object[0x16]));
    FUN_1423cdf60(object);
}

// MS2-FUNCTIONAL: follows the recovered child/member teardown and sized-delete paths; only the anonymous abstract vptr store is omitted.
// @0x1423d1b90
void* FUN_1423d1b90(unsigned long long* object, unsigned flags)
{
    Memory::Free(reinterpret_cast<void*>(object[0x16]));
    FUN_1423cdf60(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x5c0);
        else Memory::Free(object);
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

// MS2-FUNCTIONAL: mirrors the executable allocation flag and 0x110 sized-delete branch; anonymous vptr stores are omitted.
// @0x1423da2c0
void* FUN_1423da2c0(void* object, unsigned long long flags)
{
    auto* words = static_cast<unsigned long long*>(object);
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313b920);
    words[1] = reinterpret_cast<unsigned long long>(DAT_14313b968);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x110);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: hash-table capacity growth threshold and requested capacities follow the executable; table allocation helper is exe-bound.
// @0x1423d8d10
void FUN_1423d8d10(unsigned long long* table, unsigned long long key)
{
    auto* data = reinterpret_cast<unsigned long long*>(table[0]);
    if (!data) {
        FUN_1423d9090(table, key, 8);
        return;
    }
    if (data[1] * 4 + 4 < data[0] * 5)
        FUN_1423d9090(table, key, data[1] * 2 + 2);
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

// MS2-FUNCTIONAL: destructor helper and 0xb0 sized-delete path follow the executable; only allocator vtable dispatch uses Memory.
// @0x1423ce3c0
void* FUN_1423ce3c0(void* object, unsigned long long flags)
{
    FUN_1423cdf60(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0xb0);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: executes the common refcount-base cleanup and 0x10 sized-delete path from the executable.
// @0x1423db8b0
void* FUN_1423db8b0(void* object, unsigned long long flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: byte-identical common refcount-base cleanup and 0x10 sized-delete path.
// @0x1423db910
void* FUN_1423db910(void* object, unsigned long long flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: byte-identical common refcount-base cleanup and 0x10 sized-delete path.
// @0x1423db970
void* FUN_1423db970(void* object, unsigned long long flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: restores the executable's anonymous prototype vptr before the destructor helper and size-selected delete.
// @0x1423ce250
void* FUN_1423ce250(unsigned long long* object, unsigned long long flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313a200);
    FUN_14257db50(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
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
        FUN_1423daf30(*reinterpret_cast<void**>(bytes + 0xc8));
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

// MS2-FUNCTIONAL: attaches the movie, updates the operating-system label and notifies the current IME child.
// @0x1423ca410
void FUN_1423ca410(void* self, void* movie)
{
    FUN_1425b49b0();
    if (!movie) return;
    void** fields = static_cast<void**>(self);
    reinterpret_cast<void(*)(void*)>(*reinterpret_cast<void***>(fields[3]))(fields[3]);
    *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0x80) = 0;
    if (fields[0xe]) {
        FUN_14257dc30(movie);
        void* arg = movie;
        reinterpret_cast<void(*)(void*, void**)>(*reinterpret_cast<void***>(fields[0xe]))(fields[0xe], &arg);
    }
    fields[0x14] = movie;
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

// MS2-FUNCTIONAL: runs the recovered IME manager teardown and the executable's scalar or sized delete path.
// @0x1423c8e10
void* FUN_1423c8e10(void* object, unsigned long long flags)
{
    FUN_1423c8bb0(static_cast<unsigned long long*>(object));
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x1a0);
        else Memory::Free(object);
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
        if (flags & 4) FUN_14015b310(object, 0x1a0);
        else Memory::Free(object);
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
            FUN_1423cc7c0(bytes - 0x1a0);
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

// MS2-FUNCTIONAL: restores the executable's AS2/AS3 support vtable, runs shared base cleanup, and follows the 0x10 delete path.
// @0x1423dbcb0
void* FUN_1423dbcb0(unsigned long long* object, unsigned long long flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313ba60);
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
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

// MS2-FUNCTIONAL: the class destructor is shared and recovered; opaque allocator vtable dispatch uses Scaleform's equivalent Memory facade.
// @0x1423ce040
void* FUN_1423ce040(void* object, unsigned long long flags)
{
    FUN_14257db50(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: byte-identical deleting wrapper body to the adjacent executable copy, with the same destructor and sized-free path.
// @0x1423ce0a0
void* FUN_1423ce0a0(void* object, unsigned long long flags)
{
    FUN_14257db50(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x10);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: destructor helper and sized-free path follow the executable; heap dispatch uses our Memory facade.
// @0x1423ce100
void* FUN_1423ce100(void* object, unsigned long long flags)
{
    FUN_1423cde00(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x870);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: same helper sequence and allocation size as the adjacent executable copy.
// @0x1423ce1f0
void* FUN_1423ce1f0(void* object, unsigned long long flags)
{
    FUN_1423cde00(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x870);
        else Memory::Free(object);
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

// MS2-FUNCTIONAL: releases the retained member, invokes the recovered AS support destructor, then follows delete flags.
// @0x1423ce160
void* FUN_1423ce160(unsigned long long* object, unsigned flags)
{
    FUN_1423ca920(nullptr, &object[3]);
    object[3] = 0;
    FUN_14257db50(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x20);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: runs the recovered IME interface destructor before scalar or sized deletion.
// @0x1423ce2f0
void* FUN_1423ce2f0(unsigned long long* object, unsigned long long flags)
{
    FUN_1423cdee0(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0xe8);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: runs the executable's State cleanup and honors both scalar and sized delete flags.
// @0x1423dba40
void* FUN_1423dba40(void* object, unsigned long long flags)
{
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x18);
        else Memory::Free(object);
    }
    return object;
}

// MS2-FUNCTIONAL: releases both retained AbcDataBuffer fields, invokes the base helper, and follows delete flags.
// @0x1423dbab0
void* FUN_1423dbab0(unsigned long long* object, unsigned flags)
{
    FUN_1423ca920(nullptr, &object[5]);
    FUN_1423ca920(nullptr, &object[2]);
    FUN_14257db40(object);
    if (flags & 1) {
        if (flags & 4) FUN_14015b310(object, 0x38);
        else Memory::Free(object);
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
{ cx18_ReserveGH(array, count, 0x20); }

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

// MS2-FUNCTIONAL: walks the executable's linked string records and inserts each key/value pair by Bernstein hash.
// @0x1423d8e80
void FUN_1423d8e80(void* table, void* source)
{
    void** sourceVtable = *reinterpret_cast<void***>(source);
    auto* record = static_cast<unsigned char*>(reinterpret_cast<void*(*)(void*)>(sourceVtable[0])(source));
    if (!record) return;
    record = *reinterpret_cast<unsigned char**>(record + 8);
    while (record) {
        const unsigned key = *reinterpret_cast<unsigned*>(record);
        const char* text = *reinterpret_cast<const char**>(record + 8);
        const unsigned long long length = strlen(text);
        const unsigned long long hash = String::BernsteinHashFunction(text, length, 0x1505);
        void* value = const_cast<char*>(text);
        unsigned keyCopy = key;
        void* valueRef = &value;
        unsigned* keyRef = &keyCopy;
        void* entry[2] = { valueRef, keyRef };
        FUN_1423d8b80(table, table, entry, hash);
        record = *reinterpret_cast<unsigned char**>(record + 24);
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
        void* result = nullptr;
        void** vtable = *reinterpret_cast<void***>(manager);
        reinterpret_cast<void(*)(void*, const char*, void**, int, int)>(vtable[0x78 / sizeof(void*)])(
            manager, command, &result, 0, 0);
        *command = 0;
        if (result) {
            void** resultVtable = *reinterpret_cast<void***>(result);
            reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
        }
    }
}

// MS2-FUNCTIONAL: performs the executable's interface query and retrieves the IME reading-state values.
// @0x1423d6b70
bool FUN_1423d6b70(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* source = *reinterpret_cast<void**>(bytes + 0x1c0);
    if (!source) return false;
    void* result = nullptr;
    auto** vtable = *reinterpret_cast<void***>(source);
    int hr = reinterpret_cast<int(*)(void*, const void*, void**)>(vtable[0])(source, DAT_1431c51e8, &result);
    bool success = false;
    if (hr >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        hr = reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
            result, DAT_1431c5018, bytes + 0x1a0, bytes + 0x1b8);
        success = hr >= 0;
        if (!success) *reinterpret_cast<unsigned*>(bytes + 0x1b8) = 0xffffffff;
        reinterpret_cast<void(*)(void*)>(resultVtable[2])(result);
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
        *reinterpret_cast<String*>(record + 0x10) = "";
        *reinterpret_cast<String*>(record + 0x18) = "";
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

// MS2-FUNCTIONAL: decrements the executable's 32-bit interface refcount and triggers scalar deletion at zero.
// @0x1423daeb0
int FUN_1423daeb0(void* self)
{
    auto* count = reinterpret_cast<int*>(static_cast<unsigned char*>(self) + 0x3c);
    const int remaining = --*count;
    if (remaining == 0) {
        void** vtable = *reinterpret_cast<void***>(self);
        reinterpret_cast<void(*)(void*, int)>(vtable[8])(self, 1);
    }
    return remaining;
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
            reinterpret_cast<void(*)(void*, unsigned)>(selfVtable[0xa0 / sizeof(void*)])(
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
