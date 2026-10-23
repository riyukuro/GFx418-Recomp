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
