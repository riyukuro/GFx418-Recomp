// Recovered from MapleStory2.exe: Scaleform GFx IME support.
// MS2-UNIT: sfr_ime_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c8a50-0x1423c8fa0 .text$mn
// MS2-RANGE: 0x1423ca350-0x1423dbde0 .text$mn
#include "../include/kernel/sf_string.h"

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

// @0x1423ca640
void FUN_1423ca640(void* self, unsigned value)
{
    *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x84) = value;
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x70);
    void** vtable = *reinterpret_cast<void***>(child);
    reinterpret_cast<void(*)(void*)>(vtable[17])(child);
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
void FUN_1423d97d0(void* self, long long enabled)
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
