// Recovered from MapleStory2.exe: Scaleform GFx IME support.
// MS2-UNIT: sfr_ime_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c8a50-0x1423c8fa0 .text$mn
// MS2-RANGE: 0x1423ca350-0x1423dbde0 .text$mn
#include <windows.h>
#include <imm.h>
#include <cstdarg>
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_string.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/as3/as3_support.h"

namespace Scaleform { namespace GFx { class Movie { public: void Release(); }; } }

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

extern "C" void FUN_14015b310(void*, unsigned long long);
extern "C" void FUN_14257db50(void*);
extern "C" void FUN_1423cdf60(void*);
extern "C" void FUN_1423cde00();
extern "C" const void* DAT_14313a210[];
extern "C" const void* DAT_14313b920[];
extern "C" const void* DAT_14313b968[];
extern "C" const void* DAT_14313a228[];
extern "C" const void* DAT_14313a200[];
extern "C" void FUN_1423d9090(void*, unsigned long long, unsigned long long);
extern "C" void FUN_1423d9690(void*, void*, unsigned long long);
extern "C" void FUN_14257dcd0(void*);
extern "C" void FUN_14257db40(void*);
extern "C" void FUN_1423daf30(void*);
extern "C" void FUN_1423cc7c0(void*);
extern "C" const unsigned long long DAT_14313b410;
extern "C" const unsigned long long DAT_14313b418;
extern "C" const void* DAT_14313ba60[];

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
    FUN_1423cde00();
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
    FUN_1423cde00();
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

extern void FUN_1423d9690(void*, void*, unsigned long long);

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
