// Recovered from MapleStory2.exe: Scaleform GFx IME support.
// MS2-UNIT: sfr_ime_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423c8a50-0x1423c8fa0 .text$mn
// MS2-RANGE: 0x1423c8fa0-0x1423c8ff3 .text$mn
// MS2-RANGE: 0x1423ca140-0x1423ca160 .text$mn
// MS2-RANGE: 0x1423ca1c0-0x1423ca2b0 .text$mn
// MS2-RANGE: 0x1423ca350-0x1423dbde0 .text$mn
#include <windows.h>
#include <emmintrin.h>
#include <imm.h>
#pragma comment(lib, "imm32.lib")
#include <oleauto.h>
#include <cstdarg>
#include <vector>
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_refcount.h"
#include "../include/kernel/sf_hash.h"
#include "../include/kernel/sf_array.h"
#include "../include/kernel/sf_string.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/gfx_value.h"
#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/gfx_imemanagerwin32.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_textfield.h"
// AvmMovieClip's deleting destructor 0x1423dbb60 (emitted here) frees only for a global delete: the in-place class delete.
#define SF_AS3_AVM_INPLACE_DELETE
#include "../include/gfx/as3/as3_avm.h"   // AvmMovieClip (and as3_support.h)
#include "../include/gfx/xml/xml_object.h"
#include "ms2/scaleform/kernel/sf_wstring.h"

// Scaleform::UTF8Util::EncodeString (exe 0x1425a73c0); the shared sf_utf8util.h does not declare it.
namespace Scaleform { namespace UTF8Util { void SF_STDCALL EncodeString(char* buff, const wchar_t* chars, SPInt length); } }
namespace Scaleform { namespace UTF8Util { SPInt SF_STDCALL GetEncodeStringSize(const wchar_t* chars, SPInt length); } }
namespace Scaleform { namespace UTF8Util { void SF_STDCALL EncodeStringSafe(char* buff, UPInt buffSize, const wchar_t* chars, SPInt length); } }

namespace Scaleform { int SF_CDECL SFstricmp(const char* a, const char* b); }
// Instantiated out of line in the exe (0x1422fe110).
namespace Scaleform { template <> void ArrayDataBase<String, AllocatorLH<String, 2>, ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt); }
namespace Scaleform { namespace GFx { class Movie { public:
    void Release();
    enum SetVarType { SV_Normal, SV_Sticky, SV_Permanent };
    int GetAVMVersion() const;
    bool SetVariable(const char* ppathToVar, const Value& value, SetVarType setType);
}; } }
namespace Scaleform { namespace GFx { namespace IME {

void FUN_1423d9090(void*, void*, unsigned long long);
__declspec(noinline) void FUN_1423d8b80(unsigned long long*, void*, void**, unsigned long long);
void FUN_1423d9b40(void*);
    unsigned char FUN_1423da320(void*);
    __declspec(noinline) void FUN_1423d9500(void*);
    void FUN_1423d5fd0(void*);
    void FUN_1423c8bb0(unsigned long long*);
    class GFxIMEManagerWin32;
    void FUN_1423ca560(GFxIMEManagerWin32*, unsigned);
    // Defined below in IME (the callers used to reach them through extern "C" twins that never linked).
    void FUN_1423cc7c0(void*, unsigned);
    void FUN_1423cde00(void*);
    void FUN_1423cdf60(unsigned long long*);
    __declspec(noinline) unsigned long long FUN_1423daf30(void*, int);
    void FUN_1423ccdc0(unsigned long long*, String);
    void FUN_1423cc2d0(unsigned long long*);
    void FUN_1423cc570(unsigned long long*);
} } }
namespace Scaleform { namespace GFx { namespace AS3 { void SF_STDCALL DoAbcLoader(LoadProcess*, const TagInfo&); } } }
namespace Scaleform { namespace GFx { bool RegisterTagLoader(unsigned tagType, void (*plf)(LoadProcess*, const TagInfo&)); } }

static __forceinline HIMC cx18_ImmGetContext(HWND hwnd)
{
    return ImmGetContext(hwnd);
}
static __forceinline DWORD cx18_ImmGetCandidateListW(HIMC context, DWORD index, LPCANDIDATELIST list, DWORD bytes)
{
    return ImmGetCandidateListW(
        context, index, list, bytes);
}
static __forceinline LONG cx18_ImmGetCompositionStringW(HIMC context, DWORD index, LPVOID buffer, DWORD bytes)
{
    return ImmGetCompositionStringW(
        context, index, buffer, bytes);
}
static __forceinline DWORD cx18_ImmGetProperty(HKL layout, DWORD index)
{
    return ImmGetProperty(layout, index);
}
static __forceinline BOOL cx18_ImmSetCompositionWindow(HIMC context, LPCOMPOSITIONFORM form)
{
    return ImmSetCompositionWindow(context, form);
}
static __forceinline BOOL cx18_ImmSetCandidateWindow(HIMC context, LPCANDIDATEFORM form)
{
    return ImmSetCandidateWindow(context, form);
}
static __forceinline UINT cx18_ImmGetVirtualKey(HWND hwnd)
{
    return ImmGetVirtualKey(hwnd);
}
static __forceinline BOOL cx18_ImmIsUIMessageW(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return ImmIsUIMessageW(
        hwnd, message, wParam, lParam);
}
static __forceinline BOOL cx18_ImmNotifyIME(HIMC context, DWORD action, DWORD index, DWORD value)
{
    return ImmNotifyIME(context, action, index, value);
}
static __forceinline BOOL cx18_ImmReleaseContext(HWND hwnd, HIMC context)
{
    return ImmReleaseContext(hwnd, context);
}
static __forceinline UINT cx18_ImmGetIMEFileNameA(HKL layout, LPSTR buffer, UINT capacity)
{
    return ImmGetIMEFileNameA(layout, buffer, capacity);
}
static __forceinline BOOL cx18_ImmAssociateContextEx(HWND hwnd, HIMC context, DWORD flags)
{
    return ImmAssociateContextEx(hwnd, context, flags);
}
static __forceinline BOOL cx18_ImmSetOpenStatus(HIMC context, BOOL open)
{
    return ImmSetOpenStatus(context, open);
}
static __forceinline BOOL cx18_ImmGetOpenStatus(HIMC context)
{
    return ImmGetOpenStatus(context);
}
static __forceinline BOOL cx18_ImmGetConversionStatus(HIMC context, DWORD* conversion, DWORD* sentence)
{
    return ImmGetConversionStatus(context, conversion, sentence);
}
static __forceinline BOOL cx18_ImmSetConversionStatus(HIMC context, DWORD conversion, DWORD sentence)
{
    return ImmSetConversionStatus(context, conversion, sentence);
}
static __forceinline BOOL cx18_ImmSetCompositionStringW(HIMC context, DWORD index, LPCVOID comp, DWORD compBytes, LPCVOID read, DWORD readBytes)
{
    return ImmSetCompositionStringW(context, index, const_cast<LPVOID>(comp), compBytes, const_cast<LPVOID>(read), readBytes);
}

extern "C" void FUN_14015b310(void*, unsigned long long);
// AvmMovieClip::~AvmMovieClip 0x1424ddcb0 (sfr_as3_16) is the in-place destructor of FUN_1423dbb60 below.
// The RefCount base destructors, called directly as the exe calls them.
static inline void RawRefCountCoreDtor(void* p) { static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore(); }
static inline void RawRefCountNTSCoreDtor(void* p) { static_cast<Scaleform::RefCountNTSImplCore*>(p)->Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(); }
extern "C" const void* DAT_143138530[];
extern "C" const void* DAT_14313a210[];
extern "C" const void* DAT_14313a228[];
extern "C" const void* DAT_14313a1d8[];
extern "C" const void* DAT_14313b9c8[];
extern "C" const void* DAT_14313a238[];
extern "C" const void* DAT_14313a450[];
extern "C" const void* DAT_14313a5f8[];
extern "C" const void* DAT_14313a200[];
extern "C" const void* DAT_143138360[];
extern "C" void FUN_1423d9090(void*, void*, unsigned long long);
extern "C" __declspec(noinline) void FUN_1423d9690(void*, void*, unsigned long long);
unsigned HashFunction(const char*, unsigned long long);
void FUN_14257dcd0(void*);
extern void FUN_14257dcb0(void*);
extern "C" unsigned long long* FUN_1423cabb0(unsigned long long*, unsigned long long);
extern "C" const unsigned long long DAT_14313b410;
// (DAT_14313b418 is the second half of the DAT_14313b410 GUID: one 16-byte object in data_rdata_sf_a)
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
#define DAT_143b15f60 (static_cast<void*>(Scaleform::Memory::pGlobalHeap))
extern "C" void FUN_1423ca030(void*, const char*, const char*, ...);
void FUN_14257dc30(void*);
extern "C" void FUN_1423c9330(unsigned long long, unsigned long long);
#include "../include/video/video_video.h"   // (C3) FUN_1423ca2b0 = Ime01CueArr::Reserve; typedef below
// ~ArrayLH<String> (0x1422fbf60). Not the real dtor: called as ~ArrayLH it inlines and the two dtor bodies
// below no longer match.
extern "C" void FUN_1422fbf60(void*);
#ifndef MS2_HOOK_DLL
// the body is the client's /Od instantiation of that dtor
#pragma comment(linker, "/alternatename:FUN_1422fbf60=??1?$ArrayLH@VString@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@QEAA@XZ")
#endif
typedef Scaleform::ArrayLH<Scaleform::String> Ime01StringArray; typedef Scaleform::ArrayDataBase<Scaleform::GFx::Video::VideoPlayer::CuePoint, Scaleform::AllocatorGH<Scaleform::GFx::Video::VideoPlayer::CuePoint, 2>, Scaleform::ArrayDefaultPolicy> Ime01CueArr; template<> void Ime01CueArr::Reserve(const void*, Scaleform::UPInt);   // PushBack 0x1422fd480 (Ime01StringArray)
template<> void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::String, Scaleform::AllocatorLH<Scaleform::String, 2>, Scaleform::ArrayDefaultPolicy> >::PushBack(const Scaleform::String&);   // out of line in the exe (0x1422fd480)

struct HWND__;

namespace Scaleform { namespace GFx { namespace IME {

unsigned long long* FUN_1423cabb0(unsigned long long*, unsigned long long);

// The class (base IMEManagerBase, the members the slot functions read) is in gfx_imemanagerwin32.h.

// The members are set in the body, after the String members are built, in the exe's store order.
// @0x1423c8a50
GFxIMEManagerWin32::GFxIMEManagerWin32(::HWND__* window)
{
    hwnd = window;
    p78 = 0;
    pLog = 0;
    p70 = 0;
}

// @0x1423c8ac0
GFxIMEManagerWin32::~GFxIMEManagerWin32()
{
    if (p70)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p70))[0](p70, 1);
    if (p78)
        (*reinterpret_cast<void (***)(void*, unsigned int)>(p78))[0](p78, 1);
    // the String members are released next, then ~IMEManagerBase (the exe's tail call)
}

}}}

// MS2-PIN: ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z 0x1423c8ce0
// MS2-FUNCTIONAL ??_GGFxIMEManagerWin32@IME@GFx@Scaleform@@UEAAPEAXI@Z: frees through Memory::Free as the exe does.

namespace Scaleform { namespace GFx { namespace IME {
// The TSF sink classes (moved up: the manager ctor/dtor below build the one embedded at +0x1a0).
struct __declspec(novtable) Ime01CompartmentEventSink {
    virtual HRESULT QueryInterface(const unsigned long long* iid, void** output) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual unsigned long long OnChange(const unsigned long long* guid) = 0;
};
struct __declspec(novtable) Ime01ProfileActivationSink {
    virtual HRESULT QueryInterface(const unsigned long long* iid, void** output) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual unsigned long long OnActivated(int profileType, unsigned short language, long long* clsid,
        long long* catid, long long* guidProfile, unsigned long long hkl) = 0;
};
class Ime01TsfSink : public Ime01CompartmentEventSink, public Ime01ProfileActivationSink {
public:
    HRESULT QueryInterface(const unsigned long long* iid, void** output) override;   // 0x1423d72a0
    int AddRef() override;                                                         // 0x1423d5ae0
    int Release() override;                                                        // 0x1423d7350
    unsigned long long OnChange(const unsigned long long* guid) override;          // 0x1423d70d0
    unsigned long long OnActivated(int profileType, unsigned short language, long long* clsid,
        long long* catid, long long* guidProfile, unsigned long long hkl) override;  // 0x1423d6c10
    Ime01TsfSink() : refCount(1) {}    // the manager ctor/dtor build and tear down the one embedded at its +0x1a0
    ~Ime01TsfSink() {}
    unsigned cookie;
    int refCount;
};

// @0x1423d2f00
void FUN_1423d2f00(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    // Two Values the exe constructs on entry and never uses.
    Scaleform::GFx::Value unused0;
    Scaleform::GFx::Value unused1;
    if (*reinterpret_cast<unsigned*>(bytes + 0x98) == 0x00c10000) {
        void* base = *reinterpret_cast<void**>(bytes + 8);
        void* factory = static_cast<unsigned char*>(base) + 0x10;
        void* value = reinterpret_cast<void*(*)(void*, int)>(
            (*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
        static_cast<Scaleform::GFx::IMEManagerBase*>(value)->ClearComposition();
        FUN_1423d9500(*reinterpret_cast<void**>(bytes + 0x30));
        void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
        {
            Scaleform::GFx::Value result;
            if (void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18)) {
                reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                    (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                        values, "RemoveList", &result, 0, 0);
            }
        }
        if (value) FUN_14257dcb0(value);
        return;
    }
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x11, 0, 0);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xd0) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    {
        Scaleform::GFx::Value result;
        if (void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18)) {
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveInputWindow", &result, 0, 0);
        }
    }
}

// @0x1423ce5a0
void FUN_1423ce5a0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x11, 0, 0);
    FUN_1423da320(*reinterpret_cast<void**>(bytes + 0xc8));
    if (*reinterpret_cast<unsigned*>(bytes + 0x98) - 5u <= 1u) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
    }
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    {
        Scaleform::GFx::Value result;
        if (void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18)) {
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveInputWindow", &result, 0, 0);
        }
    }
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
}

// The key filter re-reads the event's message and key on every test, as the exe does.
static __forceinline unsigned Ime01EventMessage(const unsigned char* event)
{
    return *reinterpret_cast<const unsigned*>(event + 0xc);
}

static __forceinline unsigned long long Ime01EventKey(const unsigned char* event)
{
    return *reinterpret_cast<const unsigned long long*>(event + 0x10);
}

// The Shift key-up uses the SDK's no-modifier KeyEvent constructor (Event(eventType)), so the modifiers are stored
// before the type, as in the exe.
// IME key and mouse filter: a Shift key-up is sent to the movie after a VK_PROCESSKEY key-up, and the arrow or Enter keys cancel the composition and remove the input window.
// @0x1423d0cf0
void FUN_1423d0cf0(unsigned long long* self, const unsigned char* event)
{
    auto* bytes = reinterpret_cast<unsigned char*>(self);
    if (Ime01EventMessage(event) == WM_KEYDOWN && Ime01EventKey(event) == VK_SHIFT) {
        bytes[0xa0] = 1;
        bytes[0xa1] = 0;
    }
    if (Ime01EventMessage(event) == WM_KEYUP && bytes[0xa0] == 1 && Ime01EventKey(event) == VK_PROCESSKEY) {
        void* movie = reinterpret_cast<void*>(self[1]);
        Scaleform::GFx::KeyEvent shiftUp(Scaleform::GFx::Event::KeyUp, Scaleform::Key::Shift);
        if (movie) {
            reinterpret_cast<void(*)(void*, const Scaleform::GFx::Event*)>((*reinterpret_cast<void***>(movie))[0x110 / sizeof(void*)])(
                movie, &shiftUp);
        }
    }
    if ((Ime01EventMessage(event) == WM_KEYUP || Ime01EventMessage(event) == WM_LBUTTONUP) && bytes[0xb9]) {
        reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(self))[0x110 / sizeof(void*)])(
            self, -*reinterpret_cast<int*>(bytes + 0x64));
        bytes[0xb9] = 0;
    }
    const unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x98);
    if (!(mode == 0xd00001 || mode == 5 || mode == 6 || mode == 0xa10000 || mode == 0xb10000)) return;
    if ((Ime01EventMessage(event) != WM_KEYDOWN || Ime01EventKey(event) != VK_LEFT) && Ime01EventKey(event) - VK_UP > 2 && Ime01EventKey(event) != VK_RETURN) return;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
    cx18_ImmNotifyIME(context, NI_CLOSECANDIDATE, 0, 0);
    FUN_1423da320(reinterpret_cast<void*>(self[0x19]));
    if (*reinterpret_cast<unsigned*>(bytes + 0x98) - 5 <= 1) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_ESCAPE;
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &input, sizeof(input));
    }
    **reinterpret_cast<unsigned short**>(self + 8) = 0;
    {
        Scaleform::GFx::Value output;
        void* movie = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(self[0x15]) + 0x18);
        if (movie) {
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                (*reinterpret_cast<void***>(movie))[0x78 / sizeof(void*)])(
                    movie, "RemoveInputWindow", &output, nullptr, 0);
        }
    }
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
}

// Dispatches the IME composition and candidate-list messages by input mode.
// @0x1423d02d0
LRESULT FUN_1423d02d0(unsigned long long* self, UINT message, unsigned long long type, LPARAM value)
{
    using Forward = void(*)(void*, unsigned long long, unsigned long long, LPARAM);
    if (!self[1]) return 0;
    Scaleform::GFx::Value unused;
    switch (type) {
    case 3: {
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x13);
        if (mode == 0x3000 || mode == 0x60000 || mode == 0xb10000 || mode == 0xa10000 || mode == 0xd00800 ||
            mode == 0xd00900 || mode == 0xd00a00) {
            reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x118 / sizeof(void*)])(self, 0);
        } else if (mode == 0x210000 || mode == 0x110000 || mode == 0x810000 || mode == 0xd10000) {
            reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x118 / sizeof(void*)])(self, 0);
            return 2;
        }
        break;
    }
    case 4: {
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x13);
        if (mode == 0x210000 || mode == 0x3000 || mode == 0x60000 || mode == 0xb10000 || mode == 0xa10000 ||
            mode == 0xd00800 || mode == 0xd00900 || mode == 0x110000 || mode == 0xd00a00 || mode == 0x810000 ||
            mode == 0xd10000) {
            FUN_1423d9500(reinterpret_cast<void*>(self[6]));
            Scaleform::GFx::Value output;
            void* values = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(self[0x15]) + 0x18);
            if (values) {
                reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                    (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                        values, "RemoveList", &output, nullptr, 0);
            }
        }
        return DefWindowProcW(reinterpret_cast<HWND>(self[5]), message, 4, value);
    }
    case 5: {
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x13);
        if (mode == 0x3000 || mode == 0x60000 || mode == 0xb10000 || mode == 0xa10000 || mode == 0xd00800 ||
            mode == 0xd00900 || mode == 0xd00a00 || mode == 0x810000) {
            reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x120 / sizeof(void*)])(self, 0);
        } else if (mode == 0x210000 || mode == 0x110000 || mode == 0xd10000) {
            reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x120 / sizeof(void*)])(self, 0);
            return 2;
        }
        break;
    }
    case 0xe: {
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x13);
        if (mode == 0x210000 || mode == 0x110000 || mode == 0x810000 || mode == 0xd10000) {
            reinterpret_cast<Forward>(reinterpret_cast<void**>(self[0])[0x70 / sizeof(void*)])(self, message, 0xe, value);
            return 2;
        }
        break;
    }
    }
    reinterpret_cast<Forward>(reinterpret_cast<void**>(self[0])[0x70 / sizeof(void*)])(self, message, type, value);
    return 0;
}

// MS2-FUNCTIONAL: handles the executable's focus, candidate-list, and IME notification messages. Reviewed case by case
// against the exe, same behaviour. The rest is register allocation: the exe keeps self in rsi, the result in rdi and
// the case 5 temporary in rbx.
// @0x1423d41f0
LRESULT FUN_1423d41f0(unsigned long long* self, unsigned reason, unsigned long long message, unsigned long long value)
{
    void* child = reinterpret_cast<void*>(self[1]);
    if (!child) return 0;
    LRESULT handled = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x5b8) = static_cast<unsigned>(value);
    Scaleform::GFx::Value unused;
    switch (message) {
    case 3:
        reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x110 / sizeof(void*)])(self, 0);
        handled = static_cast<unsigned>(*reinterpret_cast<int*>(self + 0x13) - 5) > 1;
        break;
    case 4: {
        FUN_1423d9500(reinterpret_cast<void*>(self[6]));
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(self) + 0x5bc) = 0;
        Scaleform::GFx::Value result;
        void* movie = reinterpret_cast<void*>(self[0x15]);
        void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18);
        if (values)
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveList", &result, 0, 0);
        break;
    }
    case 5: {
        void* factory = static_cast<unsigned char*>(child) + 0x10;
        void* temporary = reinterpret_cast<void*(*)(void*, int)>(
            (*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
        reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void**>(self[0])[0x118 / sizeof(void*)])(self, 0);
        handled = static_cast<unsigned>(*reinterpret_cast<int*>(self + 0x13) - 5) > 1;
        if (temporary) FUN_14257dcb0(temporary);
        break;
    }
    case 0xe: {
        const int mode = *reinterpret_cast<int*>(self + 0x13);
        if (mode == 4) {
            if (*reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x9c) == 0x04040404 &&
                (value == 1 || value == 2)) {
                handled = 1;
                break;
            }
        } else if (mode == 2) {
            if (value == 0x10 || value == 0x11 || value == 0x1a || value == 0x1b || value == 0x1c) {
                handled = 1;
                break;
            }
        }
    }
    default:
        reinterpret_cast<void(*)(void*, unsigned long long, unsigned long long, unsigned long long)>(
            reinterpret_cast<void**>(self[0])[0x70 / sizeof(void*)])(self, reason, message, value);
        break;
    }
    return handled;
}

// MS2-FUNCTIONAL: destroys the XML node chain after unlinking each DOM string node from its hash table. noinline:
// FUN_1423c8bb0 calls it out of line, as the exe does.
// @0x1423cb0f0
__declspec(noinline) void FUN_1423cb0f0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    ::operator delete[](*reinterpret_cast<void**>(bytes + 0x190));
    void*& cursor = *reinterpret_cast<void**>(bytes + 0x110);
    cursor = *reinterpret_cast<void**>(bytes + 0x140);
    while (void* node = cursor) {
        FUN_1423cc570(static_cast<unsigned long long*>(node));
        cursor = *reinterpret_cast<void**>(static_cast<unsigned char*>(cursor) + 0x28);
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, node);
    }
}

// FUN_1423cc570 unlinks a DOM string node from the owner's hash set (an inlined Scaleform HashSet::RemoveAlt
// written as a member that reads pTable directly) and frees its key.
static __forceinline unsigned long long* Ime01HashEntry(unsigned long long* table, unsigned long long index)
{
    return reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(table) + (index + 1) * 0x10);
}
static __forceinline unsigned long long Ime01CachedHash(const unsigned long long* entry, unsigned long long mask)
{
    return *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(reinterpret_cast<void*>(entry[1])) + 0x20) & mask;
}
// Scaleform HashSet::RemoveAlt shape on the owner's set (pTable at +8).
struct Ime01NodeSet {
    void* owner;
    unsigned long long* pTable;
    __forceinline void RemoveAlt(unsigned long long* node);
};
__forceinline void Ime01NodeSet::RemoveAlt(unsigned long long* node)
{
    if (pTable == nullptr) return;
    const unsigned long long hashValue = *reinterpret_cast<unsigned*>(node + 4);
    long long index = hashValue & pTable[1];
    unsigned long long* e = Ime01HashEntry(pTable, index);
    if (e[0] == 0xfffffffffffffffeull || Ime01CachedHash(e, pTable[1]) != static_cast<unsigned long long>(index)) return;
    const long long naturalIndex = index;
    long long prevIndex = -1;
    while (Ime01CachedHash(e, pTable[1]) != static_cast<unsigned long long>(naturalIndex) || e[1] != reinterpret_cast<unsigned long long>(node)) {
        prevIndex = index;
        index = e[0];
        if (index == -1) return;
        e = Ime01HashEntry(pTable, index);
    }
    if (naturalIndex == index) {
        if (e[0] != 0xffffffffffffffffull) {
            unsigned long long* enext = Ime01HashEntry(pTable, e[0]);
            e[0] = 0xfffffffffffffffeull;
            e[0] = enext[0];
            e[1] = enext[1];
            e = enext;
        }
    } else {
        Ime01HashEntry(pTable, prevIndex)[0] = e[0];
    }
    e[0] = 0xfffffffffffffffeull;
    --pTable[0];
}

// @0x1423cc570
void FUN_1423cc570(unsigned long long* node)
{
    auto* owner = reinterpret_cast<Ime01NodeSet*>(node[6]);
    if (owner) owner->RemoveAlt(node);
    void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, reinterpret_cast<void*>(node[0]));
}

// MS2-FUNCTIONAL: the exe keeps the output in rdi and the string node in rbx; ours swaps them. Same code otherwise.
// Returns the state's ID as a number and its +0x18 string as the Value property.
// @0x1423da150
void FUN_1423da150(void* self, void* output, const String* key)
{
    auto* value = static_cast<Scaleform::GFx::Value*>(output);
    const char* name = key->ToCStr();
    if (std::strcmp(name, "Value") == 0) {
        // The exe returns the state's own string node at +0x18 (0x1423da18e), not the key.
        const char* node = reinterpret_cast<const char*>(
            *reinterpret_cast<const unsigned long long*>(static_cast<unsigned char*>(self) + 0x18) & ~3ull);
        value->SetString(node + 0xc);
        return;
    }
    if (std::strcmp(name, "ID") == 0)
        value->SetNumber(static_cast<double>(*reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x10)));
}

// Queries the active keyboard layout (+0x198), stores its language (+0x84), shows its locale name in the +0x78 movie and
// shows "Not Supported" / the locale name / the layout text for the current +0x88 mode.
// @0x1423d7140
void FUN_1423d7140(unsigned long long* manager)
{
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    manager[0x33] = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0));
    const unsigned language = reinterpret_cast<unsigned(*)(void*, unsigned short)>((*reinterpret_cast<void***>(manager))[4])(
        manager, *reinterpret_cast<unsigned short*>(bytes + 0x198));
    *reinterpret_cast<unsigned*>(bytes + 0x84) = language;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), language);
    wchar_t locale[0x104];
    if (!GetLocaleInfoW(*reinterpret_cast<unsigned short*>(bytes + 0x198), LOCALE_SLANGUAGE, locale, 0x104)) {
        const DWORD error = GetLastError();
        reinterpret_cast<void(*)(void*, DWORD, const char*)>((*reinterpret_cast<void***>(manager))[0x78 / sizeof(void*)])(
            manager, error, "GFxIME Error: Error Initializing Input Language Name ");
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x78 / sizeof(void*)])(
            reinterpret_cast<void*>(manager[0xf]), "Unsupported");
        return;
    }
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x78 / sizeof(void*)])(
        reinterpret_cast<void*>(manager[0xf]), String(locale).ToCStr());
    unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x88);
    if (mode == 0x01000000) {
        FUN_1423ccdc0(manager, String("Not Supported"));
        mode = *reinterpret_cast<unsigned*>(bytes + 0x88);
    }
    if (mode == 0x03000000) FUN_1423ccdc0(manager, String(locale));
    else FUN_1423cc2d0(manager);
}

// restores the three destructor vftable views, frees owned state, and honors scalar/sized delete flags.
// @0x1423d56b0
void* FUN_1423d56b0(void* self, unsigned flags)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<void***>(bytes) = DAT_14313b520;
    reinterpret_cast<Ime01TsfSink*>(bytes + 0x1a0)->~Ime01TsfSink();
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

static __forceinline void Ime01HeapFree(void* p)
{
    SF_FREE(p);
}

// Releases the linked IME records, pair arrays, and optional conversion interfaces (every array is reread
// from self after each free, as in the exe). queried is scoped so the final sink Release is a tail call.
// @0x1423d5fd0
void FUN_1423d5fd0(void* self)
{
    struct ProfileNode { void* data; ProfileNode* next; };
    struct Record { unsigned char pad[0x28]; ProfileNode* head; };
    struct Pair { void* a; void* b; void* pad; };
    struct Item { void* ptr; unsigned char pad[0x18]; };
    auto* bytes = static_cast<unsigned char*>(self);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        ProfileNode* node = (*reinterpret_cast<Record**>(bytes + 0xb8))[i].head;
        while (node) {
            Ime01HeapFree(node->data);
            ProfileNode* next = node->next;
            Ime01HeapFree(node);
            node = next;
        }
    }
    struct PairArray { Pair* Data; unsigned long long Size; };
    PairArray& pairs = *reinterpret_cast<PairArray*>(bytes + 0x158);
    for (unsigned i = 0; i < pairs.Size; ++i) {
        Ime01HeapFree(pairs.Data[i].b);
        Ime01HeapFree(pairs.Data[i].a);
    }
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0x80); ++i) {
        void* item = (*reinterpret_cast<Item**>(bytes + 0x90))[i].ptr;
        if (item) Ime01HeapFree(item);
    }
    // +0x1a0 is an embedded COM object (its vtable is at +0x1a0), released through slot 2.
    {
        IUnknown* queried = nullptr;
        if (*reinterpret_cast<int*>(bytes + 0x1b8) != -1) {
            IUnknown* remote = *reinterpret_cast<IUnknown**>(bytes + 0x1d0);
            if (remote && SUCCEEDED(remote->QueryInterface(*reinterpret_cast<const IID*>(DAT_1431c51e8),
                    reinterpret_cast<void**>(&queried)))) {
                const HRESULT hr = reinterpret_cast<HRESULT(*)(void*, unsigned)>(
                    (*reinterpret_cast<void***>(queried))[4])(queried, *reinterpret_cast<unsigned*>(bytes + 0x1b8));
                if (static_cast<unsigned>(hr) == 0x80040200u) reinterpret_cast<IUnknown*>(bytes + 0x1a0)->Release();
                queried->Release();
            }
            *reinterpret_cast<int*>(bytes + 0x1b8) = -1;
        }
        if (*reinterpret_cast<int*>(bytes + 0x1b0) != -1) {
            IUnknown* remote = *reinterpret_cast<IUnknown**>(bytes + 0x1d0);
            if (remote && SUCCEEDED(remote->QueryInterface(*reinterpret_cast<const IID*>(DAT_1431c51e8),
                    reinterpret_cast<void**>(&queried)))) {
                reinterpret_cast<HRESULT(*)(void*, unsigned)>(
                    (*reinterpret_cast<void***>(queried))[4])(queried, *reinterpret_cast<unsigned*>(bytes + 0x1b0));
                queried->Release();
            }
            *reinterpret_cast<int*>(bytes + 0x1b0) = -1;
        }
    }
    reinterpret_cast<IUnknown*>(bytes + 0x1a0)->Release();
}

// Whether the movie's focused character accepts IME input: it locks the focus group's WeakPtr (dropping a dead proxy),
// and accepts only a TextField (type 4) whose flag bits 11 and 2 are clear and that is not read-only
// (TextField::IsReadOnly, 0x1425b9b10, called out of line).
// The exe increments the inner reference before it loads the flag word; the compiler barrier keeps that order.
// @0x1423cf570
unsigned char FUN_1423cf570(void*, void* rawMovie)
{
    unsigned char accepted = 0;
    if (rawMovie) {
        auto* movie = static_cast<unsigned char*>(rawMovie);
        // the focus group's WeakPtr to the last focused character
        auto* selected = movie + static_cast<unsigned>(movie[0x3464]) * 0x60;
        auto* handle = *reinterpret_cast<int**>(selected + 0x2e88);
        if (handle) {
            auto* field = *reinterpret_cast<unsigned char**>(handle + 2);
            if (field) {
                if (*reinterpret_cast<int*>(field + 8) != 0) {
                    *reinterpret_cast<int*>(field + 8) += 2;
                    FUN_14257dcd0(field);
                    if (reinterpret_cast<int(*)(void*)>((*reinterpret_cast<void***>(field))[0x258 / sizeof(void*)])(
                            field) == 4) {
                        ++*reinterpret_cast<int*>(field + 8);
                        _ReadWriteBarrier();
                        // the TextField flag word at +0xfc: bit 11 and bit 2 block IME input
                        if (!(static_cast<unsigned char>(*reinterpret_cast<unsigned*>(field + 0xfc) >> 11) & 1) &&
                            !reinterpret_cast<Scaleform::GFx::TextField*>(field)->IsReadOnly())
                            if (!(static_cast<unsigned char>(*reinterpret_cast<unsigned*>(field + 0xfc) >> 2) & 1))
                                accepted = 1;
                        FUN_14257dcd0(field);
                    }
                    FUN_14257dcd0(field);
                }
            } else {
                if (--*handle == 0)
                    reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(
                        DAT_143b15f60, handle);
                *reinterpret_cast<void**>(selected + 0x2e88) = nullptr;
            }
        }
    }
    return accepted;
}

// Recreates the executable's temporary IME-context acquisition and open-status query.
// @0x1423cf3e0
bool FUN_1423cf3e0(void* self)
{
#define hwnd (*reinterpret_cast<HWND*>(static_cast<unsigned char*>(self) + 0x28))
    bool alreadyAssociated = true;
    HIMC context = cx18_ImmGetContext(hwnd);
    if (!context) {
        alreadyAssociated = false;
        cx18_ImmAssociateContextEx(hwnd, nullptr, 0x10);
        context = cx18_ImmGetContext(hwnd);
        if (!context) {
            cx18_ImmReleaseContext(hwnd, nullptr);
            return false;
        }
    }
    const bool open = ImmGetOpenStatus(context) != 0;
    if (!alreadyAssociated) cx18_ImmAssociateContextEx(hwnd, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
#undef hwnd
    return open;
}

// @0x1423cf4a0
String* FUN_1423cf4a0(void* self, String* output)
{
    const HKL layout = GetKeyboardLayout(0);
    *reinterpret_cast<HKL*>(static_cast<unsigned char*>(self) + 0x90) = layout;
    const unsigned long long language = reinterpret_cast<unsigned long long>(layout) & 0xffff;
    const char* label;
    switch (language) {
    case 0x0419: label = "Russian"; break;
    case 0x0404: case 0x0804: label = "Chinese"; break;
    case 0x0409: case 0x0809: case 0x0c09: case 0x1009: label = "English"; break;
    case 0x0411: label = "Japanese"; break;
    case 0x0412: label = "Korean"; break;
    default: label = "Unknown"; break;
    }
    new (output) String(label);
    return output;
}

// @0x1423da8b0
HRESULT FUN_1423da8b0(void*, void* argument, void* value)
{
    void* factory;
    HRESULT result = CoCreateInstance(*reinterpret_cast<const IID*>(DAT_1431c4878), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(DAT_1431c51b8), &factory);
    if (FAILED(result)) return result;
    void* object;
    if (SUCCEEDED(reinterpret_cast<HRESULT(*)(void*, void*, void**, unsigned)>(
            (*reinterpret_cast<void***>(factory))[5])(factory, argument, &object, 0))) {
        result = reinterpret_cast<HRESULT(*)(void*, void*)>(
            (*reinterpret_cast<void***>(object))[5])(object, value);
        static_cast<IUnknown*>(object)->Release();
    } else {
        result = E_FAIL;
    }
    static_cast<IUnknown*>(factory)->Release();
    return result;
}

// ITfSource (msctf.h): the TSF sink advise interface, queried with IID_ITfSource (DAT_1431c51e8).
#ifndef CONNECT_E_NOCONNECTION
#define CONNECT_E_NOCONNECTION static_cast<HRESULT>(0x80040200L)  // olectl.h
#endif
struct ImeTfSource : IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE AdviseSink(REFIID riid, IUnknown* punk, DWORD* pdwCookie) = 0;
    virtual HRESULT STDMETHODCALLTYPE UnadviseSink(DWORD dwCookie) = 0;
};

// Holds one COM interface and releases it (vtable slot 2) when it goes out of scope, including during unwind.
struct Unk_ImeComRef
{
    void* p = nullptr;
    ~Unk_ImeComRef()
    {
        if (p) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(p))[2])(p);
    }
};

// MS2-FUNCTIONAL: the three-stage input-context COM query in a catch(...) that releases first, second and third as
// the exe's funclet does. Same length; the exe loads second right after the second COM call, before the hr2 test,
// so its failure branch skips the reload for the release; cl loads it after the test (a hoisted copy or a
// _ReadWriteBarrier does not move it). Writing hr2 >= 0 && second moves first/second to the other's slot.
// @0x1423da320
unsigned char FUN_1423da320(void* object)
{
    using Release = ULONG(*)(void*);
    auto* bytes = static_cast<unsigned char*>(object);
    void* first = nullptr;
    void* second = nullptr;
    void* third = nullptr;
    unsigned char result = 0;
    if (!*reinterpret_cast<void**>(bytes + 0x28)) return 0;
    try {
        void* initial = *reinterpret_cast<void**>(bytes + 0x28);
        const int hr1 = reinterpret_cast<int(*)(void*, const void*, void**)>(
            (*reinterpret_cast<void***>(initial))[0])(initial, &DAT_14313b8a8, &first);
        if (hr1 >= 0) {
            const int hr2 = reinterpret_cast<int(*)(void*, unsigned, void**)>(
                (*reinterpret_cast<void***>(first))[6])(first, *reinterpret_cast<unsigned*>(bytes + 0x64), &second);
            if (hr2 >= 0) if (second) {
                const int hr3 = reinterpret_cast<int(*)(void*, const void*, void**)>(
                    (*reinterpret_cast<void***>(second))[0])(second, &DAT_14313b8c8, &third);
                if (hr3 >= 0 && third) {
                    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(third))[0x88 / sizeof(void*)])(third);
                    result = 1;
                }
            }
        }
        if (first) reinterpret_cast<Release>((*reinterpret_cast<void***>(first))[2])(first);
        if (second) reinterpret_cast<Release>((*reinterpret_cast<void***>(second))[2])(second);
        if (third) reinterpret_cast<Release>((*reinterpret_cast<void***>(third))[2])(third);
    } catch (...) {
        if (first) reinterpret_cast<Release>((*reinterpret_cast<void***>(first))[2])(first);
        if (second) reinterpret_cast<Release>((*reinterpret_cast<void***>(second))[2])(second);
        if (third) reinterpret_cast<Release>((*reinterpret_cast<void***>(third))[2])(third);
    }
    return result;
}

// The owner of the two sink interfaces at +0x1a0 and +0x1a8 whose QueryInterface follows.
struct ImeSinkOwnerHead { unsigned char opaque[0x1a0]; };
struct ImeSinkFirst { void* vftable; };
struct ImeSinkSecond { void* vftable; };
struct ImeSinkOwner : ImeSinkOwnerHead, ImeSinkFirst, ImeSinkSecond {};

// The two TSF sink classes (see Ime01EmitTsfSinkVftables / Ime01EmitTsfUiSinkVftables at the end of the file).
// Their overriders are the bodies below, tagged with the exe VAs.
struct __declspec(novtable) Ime01ThreadMgrEventSink {
    virtual HRESULT QueryInterface(const unsigned long long* iid, void** output) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual long long OnInitDocumentMgr(void* documentMgr) = 0;
    virtual long long OnUninitDocumentMgr(void* documentMgr) = 0;
    virtual long long OnSetFocus(void* focus, void* previousFocus) = 0;
    virtual long long OnPushContext(void* context) = 0;
    virtual long long OnPopContext(void* context) = 0;
};
struct __declspec(novtable) Ime01UIElementSink {
    virtual HRESULT QueryInterface(const unsigned long long* iid, void** output) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;
    virtual unsigned long long BeginUIElement(unsigned long long elementId, unsigned* show) = 0;
    virtual unsigned long long UpdateUIElement(unsigned elementId) = 0;
    virtual unsigned long long EndUIElement(int elementId) = 0;
};
class Ime01TsfUiSink : public Ime01ThreadMgrEventSink, public Ime01UIElementSink {
public:
    HRESULT QueryInterface(const unsigned long long* iid, void** output) override;           // 0x1423dadd0
    int AddRef() override;                                                                 // 0x1423da420
    int Release() override;                                                                // 0x1423daeb0
    long long OnInitDocumentMgr(void* documentMgr) override;                               // 0x1423dad80
    long long OnUninitDocumentMgr(void* documentMgr) override;                             // 0x1423dadc0
    long long OnSetFocus(void* focus, void* previousFocus) override;                       // 0x1423dadb0
    long long OnPushContext(void* context) override;                                       // 0x1423dada0
    long long OnPopContext(void* context) override;                                        // 0x1423dad90
    virtual void* DeletingDestructor(unsigned flags);                                      // 0x1423da2c0
    unsigned long long BeginUIElement(unsigned long long elementId, unsigned* show) override;   // 0x1423da440
    unsigned long long UpdateUIElement(unsigned elementId) override;                       // 0x1423db0c0
    unsigned long long EndUIElement(int elementId) override;                               // 0x1423da730
    Ime01TsfUiSink(unsigned long long ownerArg, unsigned long long userDataArg);              // 0x1423da250
    ~Ime01TsfUiSink() {}   // stores both vptrs; called by DeletingDestructor
    unsigned long long owner;          // +0x10
    unsigned long long elementId;      // +0x18
    unsigned elementIndex;             // +0x20
    unsigned pad24;
    unsigned long long field28;        // +0x28
    unsigned long long field30;
    unsigned field38;
    int refCount;                      // +0x3c
    unsigned long long field40;        // +0x40
    unsigned long long field48[5];
    unsigned long long userData;       // +0x70
    unsigned char tail78[0x110 - 0x78];
};
// The QueryInterface of the sink embedded at +0x1a0 of its owner: IUnknown (DAT_1431c4828) and the interface at
// DAT_14313b400 answer with the owner's +0x1a8 view, DAT_1431c5018 with the +0x1a0 view.
// @0x1423d72a0
__declspec(noinline) HRESULT Ime01TsfSink::QueryInterface(const unsigned long long* iid, void** output)
{
    void* object = this;
    if (!output) return E_INVALIDARG;
    *output = nullptr;
    const IID& riid = *reinterpret_cast<const IID*>(iid);
    if (riid == *reinterpret_cast<const IID*>(&DAT_1431c4828) || riid == *reinterpret_cast<const IID*>(DAT_14313b400))
        *output = static_cast<ImeSinkSecond*>(reinterpret_cast<ImeSinkOwner*>(static_cast<unsigned char*>(object) - 0x1a0));
    else if (riid == *reinterpret_cast<const IID*>(DAT_1431c5018))
        *output = static_cast<ImeSinkFirst*>(reinterpret_cast<ImeSinkOwner*>(static_cast<unsigned char*>(object) - 0x1a0));
    else
        return E_NOINTERFACE;
    if (!*output) return E_NOINTERFACE;
    static_cast<IUnknown*>(object)->AddRef();
    return S_OK;
}

// Asks the IME provider's factory for a temporary refcounted object and returns its interface's slot-0x70 test
// (true when there is no provider or no object). The object is held in a Ptr and released at the end.
// @0x1423ce460
unsigned char FUN_1423ce460(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    Scaleform::GFx::Value unused;  // the exe keeps an unused Value local here
    unsigned char* provider = *reinterpret_cast<unsigned char**>(bytes + 8);
    bool result;
    if (!provider)
        result = true;
    else {
        void* factory = provider + 0x10;
        Scaleform::Ptr<Scaleform::RefCountImpl> temporary = *static_cast<Scaleform::RefCountImpl*>(
            reinterpret_cast<void*(*)(void*, unsigned)>((*reinterpret_cast<void***>(factory))[3])(factory, 0x18));
        if (!temporary)
            result = true;
        else {
            void* interfaceObject =
                *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(temporary.GetPtr()) + 0x18);
            result = reinterpret_cast<bool(*)(void*)>(
                (*reinterpret_cast<void***>(interfaceObject))[0x70 / sizeof(void*)])(interfaceObject);
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
void GFxIMEManagerWin32::OnCandidateListStyleChanged(const IMECandidateListStyle& st)
{
    GFxIMEManagerWin32* self = this;
    const void* style = &st;
    if (self->p70)
        BarCall<void>(self->p70, 0xc8, style);
}

// OnFinalize (slot 24).
// @0x1423ca1c0
void GFxIMEManagerWin32::OnFinalize()
{
    GFxIMEManagerWin32* self = this;
    if (self->p70)
        BarCall<void>(self->p70, 0x78);
}

// @0x1423ca1e0
unsigned FUN_1423ca1e0(GFxIMEManagerWin32* self, void* a, unsigned b, unsigned c, bool d)
{
    if (self->p70)
        return BarCall<unsigned>(self->p70, 0x68, a, (UPInt)b, (UPInt)c, d);
    return 0;
}

// OnShutdown (slot 23).
// @0x1423ca210
void GFxIMEManagerWin32::OnShutdown()
{
    GFxIMEManagerWin32* self = this;
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
bool GFxIMEManagerWin32::SetCompositionString(const char* compString)
{
    GFxIMEManagerWin32* self = this;
    if (self->p70)
        return BarCall<bool>(self->p70, 0xf8, compString);
    return false;
}

// SetConversionMode (slot 6).
// @0x1423ca540
bool GFxIMEManagerWin32::SetConversionMode(const UInt32 convMode)
{
    GFxIMEManagerWin32* self = this;
    if (self->p70)
        return BarCall<bool>(self->p70, 0x100, convMode);
    return false;
}

// SetEnabled (slot 8).
// @0x1423ca620
bool GFxIMEManagerWin32::SetEnabled(bool enable)
{
    GFxIMEManagerWin32* self = this;
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
__declspec(noinline) void FUN_1423ca640(void* self, unsigned value)
{
    *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(self) + 0x84) = value;
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x70);
    void** vtable = *reinterpret_cast<void***>(child);
    reinterpret_cast<void(*)(void*, unsigned)>(vtable[17])(child, value);
}

// (sfr33) packed refcounted pointer release as the dtors inline it: the masked pointer is freed without a reload.
static __forceinline void Sfr33ReleasePacked(unsigned long long packed)
{
    unsigned long long p = packed & ~3ULL;
    if (_InterlockedDecrement(reinterpret_cast<volatile long*>(p + sizeof(void*))) == 0)
        Memory::Free(reinterpret_cast<void*>(p));
}

// @0x1423ca920
bool FUN_1423ca920(void*, unsigned long long* packedPtr)
{
    unsigned char* data = reinterpret_cast<unsigned char*>(*packedPtr & ~3ULL);
    if (_InterlockedDecrement(reinterpret_cast<volatile long*>(data + sizeof(void*))) == 0)
        Memory::Free(data);
    return false;
}

// @0x1423d9430
__declspec(noinline) void* FUN_1423d9430(void* object, void* owner)
{
    auto* words = static_cast<unsigned long long*>(object);
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a210);
    words[0x102] = 0;
    words[0x103] = 0;
    words[0x104] = 0;
    words[0x105] = 0;
    words[0x106] = 0;
    words[0x107] = 0;
    words[0x109] = 0;
    words[0x10a] = 0;
    words[0x10b] = 0;
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
    RawRefCountNTSCoreDtor(object);
    if (flags & 1)
        ::operator delete(object, 0x10);   // the CRT sized delete (0x142749444)
    return object;
}

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

// @0x1423da250
__declspec(noinline) Ime01TsfUiSink::Ime01TsfUiSink(unsigned long long ownerArg, unsigned long long userDataArg)
{
    owner = ownerArg;
    field28 = 0;
    field40 = 0;
    userData = userDataArg;
    refCount = 1;
    elementId = ~0ULL;
    elementIndex = ~0U;
}

// restores both vptrs, then the allocation flag and 0x110 sized-delete branch.
// @0x1423da2c0
void* Ime01TsfUiSink::DeletingDestructor(unsigned flags)
{
    void* object = this;
    this->~Ime01TsfUiSink();
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x110);
    }
    return object;
}

// @0x1423d8d10
__declspec(noinline) void FUN_1423d8d10(unsigned long long* table, unsigned long long key)
{
    auto* data = reinterpret_cast<unsigned long long*>(table[0]);
    if (!data) {
        FUN_1423d9090(table, reinterpret_cast<void*>(key), 8);
        return;
    }
    if (data[0] * 5 > (data[1] + 1) * 4)
        FUN_1423d9090(table, reinterpret_cast<void*>(key), data[1] * 2 + 2);
}

// @0x1423dbba0
void* FUN_1423dbba0(Scaleform::GFx::AS3::DoAbc* self, unsigned flags)
{
    Scaleform::GFx::AS3::AbcDataBuffer* abc = self->pAbc.GetPtr();
    if (abc) abc->Release();
    self->Scaleform::GFx::ExecuteTag::~ExecuteTag();
    if (flags & 1) ::operator delete(self, 0x10);
    return self;
}

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

// @0x1423cb920
void FUN_1423cb920(void* object, DWORD code)
{
    if (*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x78)) {
        char* message;
        FormatMessageA(0x1100, 0, code, 0, reinterpret_cast<LPSTR>(&message), 0, 0);
        LocalFree(message);
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
    RawRefCountCoreDtor(object);
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
    RawRefCountCoreDtor(object);
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
    RawRefCountCoreDtor(object);
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
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// IME language gate: forwards the digit to the candidate list (+0xc8), or injects the digit key with SendInput. Like the exe, only type, wVk and wScan of INPUT are set.
// @0x1423d1420
void FUN_1423d1420(void* object, int index)
{
    auto* bytes = static_cast<unsigned char*>(object);
    const unsigned state = *reinterpret_cast<unsigned*>(bytes + 0x98);
    if ((state & 0xf00000) == 0 && (((state - 0x10000) & 0xfffcffff) != 0 || state == 0x40000)) {
        FUN_1423daf30(*reinterpret_cast<void**>(bytes + 0xc8), index);
    } else {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = static_cast<WORD>(index + 0x31);
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(index + 0x31, MAPVK_VK_TO_VSC));
        SendInput(1, &input, sizeof(INPUT));
    }
}

// destroys GFx::Value entries in reverse order (ConstructorMov<Value>::DestructArray).
// @0x1423ce6c0
__declspec(noinline) void FUN_1423ce6c0(Scaleform::GFx::Value* values, unsigned long long count)
{
    values += count - 1;
    for (UPInt i = 0; i < count; ++i, --values)
        values->~Value();
}

// @0x1423cd060
void FUN_1423cd060(void* log, const char* format, ...)
{
    unsigned flags = 0x1000;
    va_list args;
    va_start(args, format);
    auto** vtable = *reinterpret_cast<void***>(log);
    reinterpret_cast<void(*)(void*, unsigned*, const char*, void*)>(vtable[1])(log, &flags, format, args);
    va_end(args);
}

}}} // namespace Scaleform::GFx::IME

namespace Scaleform { namespace GFx {

// The AS3 support state: registers the SymbolClass and DoABC tag loaders.
// MS2-PIN: ??_7AS3Support@GFx@Scaleform@@6B@ 0x14313bc60
// @0x1423db7f0
AS3Support::AS3Support()
{
    SType = State_AS3Support;
    RegisterTagLoader(0x4c, AS3::SymbolClassLoader);
    RegisterTagLoader(0x52, AS3::DoAbcLoader);
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace IME {

// Sample text and selection updates through the movie helpers.
// @0x1423ca350
void FUN_1423ca350(void* self)
{
    {
        Scaleform::GFx::Value value("Hello World");
        (*reinterpret_cast<Scaleform::GFx::Movie**>(static_cast<unsigned char*>(self) + 0xa0))->SetVariable(
            "_root.Edit_MLine1.textBox.text", value, Scaleform::GFx::Movie::SV_Sticky);
    }
    FUN_1423ca030(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0xa0),
                  "Selection.setSelection", "%d %d", 5, 5);
}

// Attaches the movie: notifies the object at +0x18 (vtable slot 0x90) and the current IME child at +0x70 (slot 1,
// with the movie), then publishes the operating-system label to an AVM version 1 movie as _global.gfx_ime_os_version.
// @0x1423ca410
static __forceinline void cx18_SetActiveMovie(void* self, void* movie)
{
    // IMEManagerBase::SetActiveMovie(self, movie)
    static_cast<Scaleform::GFx::IMEManagerBase*>(self)->Scaleform::GFx::IMEManagerBase::SetActiveMovie(
        static_cast<Scaleform::GFx::Movie*>(movie));
    if (!movie) return;
    unsigned char* p = static_cast<unsigned char*>(self);
    void* obj = *reinterpret_cast<void**>(p + 0x18);
    (*reinterpret_cast<void (***)(void*)>(obj))[0x90 / 8](obj);
    struct Fields { unsigned char pad[0x70]; void* child; unsigned char pad78[8]; bool flag; };
    Fields* fields = reinterpret_cast<Fields*>(p);
    fields->flag = false;
    if (fields->child) {
        FUN_14257dc30(movie);
        void* arg = movie;
        (*reinterpret_cast<void (***)(void*, void**)>(fields->child))[1](fields->child, &arg);
    }
    *reinterpret_cast<void**>(p + 0xa0) = movie;
    const int os = *reinterpret_cast<int*>(p + 0xbc);
    Scaleform::GFx::Value value;
    if (os == 1)
        value.SetString("Vista");
    else if (os == 0)
        value.SetString("XP");
    else
        value.SetString("Undetermined");
    if (static_cast<Scaleform::GFx::Movie*>(movie)->GetAVMVersion() == 1)
        (*reinterpret_cast<Scaleform::GFx::Movie**>(p + 0xa0))->SetVariable("_global.gfx_ime_os_version", value,
                                                                         Scaleform::GFx::Movie::SV_Sticky);
}
void GFxIMEManagerWin32::SetActiveMovie(Movie* pmovie)
{
    cx18_SetActiveMovie(this, pmovie);
}

// stores the manager vftable, destroys the XML node chain, then releases the arrays, the packed string, the four member
// arrays and the hash table (the SDK HashSetBase::Clear: entries marked empty, then freed) in executable order.
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
    struct TableHdr { unsigned long long EntryCount, SizeMask; };
    struct TableEntry { long long NextInChain; unsigned long long Value; bool IsEmpty() const { return NextInChain == -2; } void Clear() { NextInChain = -2; } };
    struct Table {
        TableHdr* pTable;
        TableEntry& E(unsigned long long index) { return *(((TableEntry*)(pTable + 1)) + index); }
        void Clear()
        {
            if (pTable) {
                for (unsigned long long i = 0, n = pTable->SizeMask; i <= n; i++) {
                    TableEntry* e = &E(i);
                    if (!e->IsEmpty())
                        e->Clear();
                }
                Memory::Free(pTable);
                pTable = 0;
            }
        }
    };
    reinterpret_cast<Table*>(object + 1)->Clear();
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

// Releases the executable-observed cue and object arrays before the common IME base teardown.
// @0x1423c8e70
void* FUN_1423c8e70(unsigned long long* object, unsigned flags)
{
    struct Record { void* key; unsigned long long pad[3]; };
    *reinterpret_cast<const void**>(object) = DAT_143138530;
    for (unsigned i = 0; i < object[0x2c]; ++i) {
        Memory::Free(reinterpret_cast<void**>(object[0x2b])[(unsigned long long)i * 3 + 1]);
        Memory::Free(reinterpret_cast<void**>(object[0x2b])[(unsigned long long)i * 3]);
    }
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(object + 0x10); ++i) {
        if (reinterpret_cast<Record*>(object[0x12])[i].key) Memory::Free(reinterpret_cast<Record*>(object[0x12])[i].key);
    }
    FUN_1423c8bb0(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x1a0);
    }
    return object;
}


// @0x1423d9490
__declspec(noinline) unsigned long long FUN_1423d9490(void* object, unsigned long long* value, unsigned long long)
{
    auto* array = reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(object) + 0x848);
    FUN_1423d9690(array, array, array[1] + 1);
    unsigned long long* slot = reinterpret_cast<unsigned long long*>(array[0]) + array[1] - 1;
    if (*value) ++*reinterpret_cast<int*>(*value + 8);
    *slot = *value;
    if (*value) FUN_14257dcd0(reinterpret_cast<void*>(*value));
    return 0;
}

// TSF compartment change sink: for the watched compartment GUID, reads its VT_I4 value and passes it on (FUN_1423cc7c0).
// As in the exe, the VARIANT is not initialised or cleared.
// @0x1423d70d0
unsigned long long Ime01TsfSink::OnChange(const unsigned long long* guid)
{
    void* object = this;
    // IsEqualGUID (memcmp) against the conversion-mode compartment GUID, compared as two 8-byte halves.
    if (memcmp(guid, &DAT_14313b410, 8) == 0 && memcmp(guid + 1, &DAT_14313b410 + 1, 8) == 0) {
        auto* bytes = static_cast<unsigned char*>(object);
        void* compartment = *reinterpret_cast<void**>(bytes + 0x20);
        VARIANT value;
        // ITfCompartment::GetValue
        const HRESULT hr = reinterpret_cast<HRESULT(*)(void*, VARIANT*)>((*reinterpret_cast<void***>(compartment))[4])(
            compartment, &value);
        if (SUCCEEDED(hr) && value.vt == VT_I4) {
            *reinterpret_cast<LONG*>(bytes - 0xcc) = value.lVal;
            FUN_1423cc7c0(bytes - 0x1a0, value.lVal);
        }
    }
    return 1;
}

// Forwards a copy of the by-value String to the +0x78 child's vtable slot 13 (+0x68); the argument is destroyed on return.
// @0x1423ca8b0
unsigned char FUN_1423ca8b0(void* object, String value)
{
    void** slot = *reinterpret_cast<void***>(*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x78)) + 13;
    return reinterpret_cast<unsigned char(*)(void*, String)>(*slot)(
        *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x78), value);
}

// @0x1423cdda0
void FUN_1423cdda0(void** table)
{
    if (*table) {
        const unsigned long long sizeMask = *reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(*table) + 8);
        for (unsigned long long index = 0; index <= sizeMask; ++index) {
            unsigned long long* state = reinterpret_cast<unsigned long long*>(
                static_cast<unsigned char*>(*table) + index * 0x28 + 0x10);
            if (*state != ~1ULL) *state = ~1ULL;
        }
        if (*table) Memory::Free(*table);
        *table = 0;
    }
}

// restores the executable's AS2/AS3 support vtable, runs shared base cleanup, and follows the 0x10 delete path.
// @0x1423dbcb0
void* FUN_1423dbcb0(unsigned long long* object, unsigned flags)
{
    object[0] = reinterpret_cast<unsigned long long>(DAT_14313ba60);
    RawRefCountCoreDtor(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x10);
    }
    return object;
}

// @0x1423db000
__declspec(noinline) void FUN_1423db000(unsigned long long* object)
{
    auto* bytes = reinterpret_cast<unsigned char*>(object);
    if (*reinterpret_cast<DWORD*>(bytes + 0x1c) != 0xffffffff) {
        ImeTfSource* source;
        if (SUCCEEDED(reinterpret_cast<IUnknown*>(object[5])->QueryInterface(
                *reinterpret_cast<const IID*>(DAT_1431c51e8), reinterpret_cast<void**>(&source)))) {
            if (source->UnadviseSink(*reinterpret_cast<DWORD*>(bytes + 0x1c)) == CONNECT_E_NOCONNECTION)
                reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
            source->Release();
        }
        *reinterpret_cast<DWORD*>(bytes + 0x1c) = 0xffffffff;
    }
}

// @0x1423db060
__declspec(noinline) void FUN_1423db060(unsigned long long* object)
{
    auto* bytes = reinterpret_cast<unsigned char*>(object);
    if (*reinterpret_cast<DWORD*>(bytes + 0x18) != 0xffffffff) {
        ImeTfSource* source;
        if (SUCCEEDED(reinterpret_cast<IUnknown*>(object[5])->QueryInterface(
                *reinterpret_cast<const IID*>(DAT_1431c51e8), reinterpret_cast<void**>(&source)))) {
            if (source->UnadviseSink(*reinterpret_cast<DWORD*>(bytes + 0x18)) == CONNECT_E_NOCONNECTION)
                reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
            source->Release();
        }
        *reinterpret_cast<DWORD*>(bytes + 0x18) = 0xffffffff;
    }
}

// the class destructor is shared and recovered; opaque allocator vtable dispatch uses Scaleform's equivalent Memory facade.
// @0x1423ce040
void* FUN_1423ce040(void* object, unsigned flags)
{
    RawRefCountNTSCoreDtor(object);
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
    RawRefCountNTSCoreDtor(object);
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
__declspec(noinline) void FUN_1423ca660(void* self, unsigned value)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<unsigned*>(bytes + 0xc0) = value;
    *reinterpret_cast<unsigned*>(*reinterpret_cast<unsigned char**>(bytes + 0x70) + 0x9c) = value;
}

// @0x1423ca3f0
__declspec(noinline) void FUN_1423ca3f0(void* self, int index)
{
    void* child = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x70);
    if (child) {
        void** vtable = *reinterpret_cast<void***>(child);
        reinterpret_cast<void(*)(void*, int)>(vtable[0x98 / sizeof(void*)])(child, index);
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
__declspec(noinline) void FUN_1423d97d0(void* self, const char* enabled)
{
    char* text = static_cast<char*>(self) + 0x10;
    if (enabled)
        strcpy_s(text, 0x400, "candidateList");
    else
        *text = 0;
}

// @0x1423daeb0
__declspec(noinline) int Ime01TsfUiSink::Release()
{
    long long* self = reinterpret_cast<long long*>(this);
    int count = *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x3c) - 1;
    *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(self) + 0x3c) = count;
    if (count == 0) {
        void** vtable = *reinterpret_cast<void***>(self);
        reinterpret_cast<void(*)(void*, int)>(vtable[0x40 / sizeof(void*)])(self, 1);
    }
    return count;
}

struct ImeSinkOwnerView {
    struct Unknown { virtual void Slot0() = 0; virtual void Slot1() = 0; virtual void Release() = 0; virtual void Slot3() = 0; virtual void Slot4() = 0; };
    unsigned char pad0[0x28]; Unknown* first; unsigned char pad30[0x10]; Unknown* second;
};
// @0x1423daef0
__declspec(noinline) void FUN_1423daef0(void* self)
{
    auto* view = static_cast<ImeSinkOwnerView*>(self);
    if (view->first) view->first->Release();
    if (view->second) {
        view->second->Slot4();
        view->second->Release();
    }
}

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
    FUN_1423cdf60(object);
}

// ConstructorMov<Ptr<..>>::DestructArray: releases the entries in reverse order.
static __forceinline void Ime01ReleaseArray(void** p, unsigned long long count)
{
    p += count - 1;
    for (unsigned long long i = 0; i < count; ++i, --p)
        if (*p) FUN_14257dcd0(*p);
}

// restores the vptr, releases the Ptr array in reverse and frees it, destroys the Value array and the member string.
// @0x1423cde00
void FUN_1423cde00(void* raw)
{
    auto* object = static_cast<unsigned long long*>(raw);
    *static_cast<void**>(raw) = DAT_14313a210;
    Ime01ReleaseArray(reinterpret_cast<void**>(object[0x109]), object[0x10a]);
    Memory::Free(reinterpret_cast<void*>(object[0x109]));
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
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x20);
    }
    return object;
}

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
    static_cast<Scaleform::GFx::State*>(object)->Scaleform::GFx::State::~State();
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x18);
    }
    return object;
}

// Scalar deleting destructor: releases the +0x28 and +0x10 strings (reverse member order), runs the RefCountImplCore
// destructor, and follows the delete flags.
// @0x1423dbab0
void* FUN_1423dbab0(unsigned long long* object, unsigned flags)
{
    struct View { void* vtable; unsigned long long refCount; Scaleform::String s10; unsigned long long p18[2]; Scaleform::String s28; };
    reinterpret_cast<View*>(object)->~View();
    RawRefCountCoreDtor(object);
    if (flags & 1) {
        if (!(flags & 4)) Memory::Free(object);
        else FUN_14015b310(object, 0x38);
    }
    return object;
}

// ExecuteTag scalar deleting destructor (slot 0 of the ExecuteTag vftable 0x14313ba68): an 8-byte object, freed with
// sized delete. The exe's twin of ??_GExecuteTag (0x1423dbc20).
// @0x1423dbbf0
void* FUN_1423dbbf0(Scaleform::GFx::ExecuteTag* self, unsigned flags)
{
    self->Scaleform::GFx::ExecuteTag::~ExecuteTag();
    if (flags & 1)
        ::operator delete(self, sizeof(Scaleform::GFx::ExecuteTag));
    return self;
}

// @0x1423cb740
__declspec(noinline) unsigned HashFunction(const char* text, unsigned long long length)
{
    return static_cast<unsigned>(String::BernsteinHashFunctionCIS(text, length, 0x1505)) & 0xffffff;
}

// @0x1423d9500
void FUN_1423d9500(void* self)
{
    FUN_1423d9690(static_cast<unsigned char*>(self) + 0x848,
                  static_cast<unsigned char*>(self) + 0x848, 0);
}

// @0x1423ce570
void FUN_1423ce570(void* self)
{
    *reinterpret_cast<String*>(static_cast<unsigned char*>(self) + 0x10) = "";
    FUN_1423d97d0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30), "");
}

// @0x1423d0f10
void FUN_1423d0f10(void* self, char* text)
{
    *reinterpret_cast<String*>(static_cast<unsigned char*>(self) + 0x10) = text;
    FUN_1423d97d0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30), text);
}

// The SDK's out-of-line ArrayDataBase::Reserve, one explicit instantiation per array type (pinned at the end of
// the file). The exe compiles one copy per element size; Ime01Pod stands in for element types with no recovered
// class. The FUN_ names are kept as inline forwarders for the callers.
template <unsigned long long ElementSize>
struct Ime01Pod { unsigned char bytes[ElementSize]; };
template <unsigned long long ElementSize>
using Ime01ArrayGH = ArrayDataBase<Ime01Pod<ElementSize>, AllocatorGH_POD<Ime01Pod<ElementSize>>, ArrayDefaultPolicy>;
// The candidate list's Value array (ArrayData<Value, AllocatorGH<Value, 2>>).
typedef ArrayDataBase<Scaleform::GFx::Value, AllocatorGH<Scaleform::GFx::Value, 2>, ArrayDefaultPolicy> ValueArrayBase;
typedef ArrayDataBase<void*, AllocatorLH_POD<void*>, ArrayDefaultPolicy> Ime01PtrArrayLH;
// The wide-string arrays: wchar_t storage with the 0x201 wide-string stat, and the parallel IME text array.
typedef ArrayDataBase<wchar_t, AllocatorLH_POD<wchar_t, 0x201>, ArrayDefaultPolicy> Ime01WideArrayLH;
typedef ArrayDataBase<wchar_t, AllocatorLH_POD<wchar_t, 2>, ArrayDefaultPolicy> Ime01TextArrayLH;
}}}
namespace Scaleform {
template void ArrayDataBase<GFx::IME::Ime01Pod<0xc>, AllocatorGH_POD<GFx::IME::Ime01Pod<0xc>>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::IME::Ime01Pod<0x10>, AllocatorGH_POD<GFx::IME::Ime01Pod<0x10>>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::IME::Ime01Pod<0x18>, AllocatorGH_POD<GFx::IME::Ime01Pod<0x18>>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// The exe keeps this one out of line even where its arguments are constants (FUN_1423ce730), so it is an explicit
// specialization with the SDK body.
template <>
__declspec(noinline) void ArrayDataBase<GFx::IME::Ime01Pod<0x20>, AllocatorGH_POD<GFx::IME::Ime01Pod<0x20>>,
                                        ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity)
{
    typedef GFx::IME::Ime01Pod<0x20> T;
    typedef AllocatorGH_POD<T> Allocator;
    if (Policy.NeverShrinking() && newCapacity < GetCapacity())
        return;
    if (newCapacity < Policy.GetMinCapacity())
        newCapacity = Policy.GetMinCapacity();
    if (newCapacity == 0) {
        if (Data) {
            Allocator::Free(Data);
            Data = 0;
        }
        Policy.SetCapacity(0);
        return;
    }
    UPInt gran = Policy.GetGranularity();
    newCapacity = (newCapacity + gran - 1) / gran * gran;
    if (Data)
        Data = (T*)Allocator::Realloc(Data, sizeof(T) * newCapacity, MS2_SF_ARRAY_SITE, 137);
    else
        Data = (T*)Allocator::Alloc(pheapAddr, sizeof(T) * newCapacity, MS2_SF_ARRAY_SITE, 161);
    Policy.SetCapacity(newCapacity);
}
template void GFx::IME::ValueArrayBase::Reserve(const void*, UPInt);
template void GFx::IME::Ime01PtrArrayLH::Reserve(const void*, UPInt);
template void GFx::IME::Ime01WideArrayLH::Reserve(const void*, UPInt);
template void GFx::IME::Ime01TextArrayLH::Reserve(const void*, UPInt);
}
namespace Scaleform { namespace GFx { namespace IME {

static __forceinline void FUN_1423d95f0(void* array, void* allocator, unsigned long long requested)
{ static_cast<Ime01PtrArrayLH*>(array)->Reserve(allocator, requested); }
static __forceinline void FUN_1423d1240(unsigned long long* array, void* heapAddr, unsigned long long count)
{ reinterpret_cast<Ime01ArrayGH<0xc>*>(array)->Reserve(heapAddr, count); }
static __forceinline void FUN_1423d12e0(unsigned long long* array, void* heapAddr, unsigned long long count)
{ reinterpret_cast<Ime01ArrayGH<0x20>*>(array)->Reserve(heapAddr, count); }
static __forceinline void FUN_1423d7370(unsigned long long* array, void* heapAddr, unsigned long long count)
{ reinterpret_cast<ValueArrayBase*>(array)->Reserve(heapAddr, count); }
static __forceinline void FUN_1423d1380(unsigned long long* array, void* allocator, unsigned long long count)
{ reinterpret_cast<Ime01WideArrayLH*>(array)->Reserve(allocator, count); }
static __forceinline void FUN_1423d5340(unsigned long long* array, void* allocator, unsigned long long count)
{ reinterpret_cast<Ime01TextArrayLH*>(array)->Reserve(allocator, count); }
static __forceinline void FUN_1423cc680(unsigned long long* array, void* heapAddr, unsigned long long requested)
{ reinterpret_cast<Ime01ArrayGH<0x18>*>(array)->Reserve(heapAddr, requested); }
static __forceinline void FUN_1423cc720(unsigned long long* array, void* heapAddr, unsigned long long requested)
{ reinterpret_cast<Ime01ArrayGH<0x10>*>(array)->Reserve(heapAddr, requested); }

// Releases the trimmed items, grows through the reserve helper, and stores the new length.
// @0x1423d9690
extern "C" __declspec(noinline) void FUN_1423d9690(void* rawArray, void* allocator, unsigned long long length)
{
    auto* array = static_cast<unsigned long long*>(rawArray);
    unsigned long long oldLength = array[1];
    if (length < oldLength) {
        void** item = reinterpret_cast<void**>(array[0]) + length;
        unsigned long long count = oldLength - length;
        item += count - 1;
        for (unsigned long long i = 0; i < count; ++i, --item) {
            if (*item) FUN_14257dcd0(*item);
        }
        if (length < (array[2] >> 1))
            FUN_1423d95f0(array, allocator, length);
    } else if (length >= array[2]) {
        FUN_1423d95f0(array, allocator, (length >> 2) + length);
    }
    array[1] = length;
}

// @0x1423d9730
extern "C" __declspec(noinline) void FUN_1423d9730(void* rawArray, void* allocator, unsigned long long length)
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



struct Ime01CmdKey
{
    const char* Text;
    Ime01CmdKey(const char* text) : Text(text) {}
    bool operator==(const Ime01CmdKey& o) const { return std::strcmp(Text, o.Text) == 0; }
};
struct Ime01CmdKeyHash
{
    UPInt operator()(const Ime01CmdKey& key) const
    {
        return Scaleform::String::BernsteinHashFunction(key.Text, std::strlen(key.Text), 0x1505);
    }
};
struct Ime01Cmd
{
    unsigned Type;
    void* Handler;
};
typedef Scaleform::Hash<Ime01CmdKey, Ime01Cmd, Ime01CmdKeyHash> Ime01CmdMap;
struct Ime01CmdRecord
{
    unsigned Type;
    const char* Name;
};

// Walks the source's command array (0x10-byte {key, name} entries, ended by a null name) and
// inserts each name -> {key, source} by Bernstein hash.
// @0x1423d8e80
void FUN_1423d8e80(void* table, void* source)
{
    void** sourceVtable = *reinterpret_cast<void***>(source);
    auto* record = reinterpret_cast<Ime01CmdRecord*(*)(void*)>(sourceVtable[0])(source);
    while (record->Name) {
        const unsigned type = record->Type;
        Ime01CmdKey key(record->Name);
        Ime01Cmd value = { type, source };
        Ime01CmdMap::NodeRef entry(key, value);
        const unsigned long long hash = Ime01CmdKeyHash()(key);
        FUN_1423d8b80(static_cast<unsigned long long*>(table), table, reinterpret_cast<void**>(&entry), hash);
        ++record;
    }
}

// Clears the pending value array, builds the RemoveList path, and queries the movie object.
// @0x1423d9520
void FUN_1423d9520(void* raw)
{
    auto* bytes = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value result;
    FUN_1423d9690(bytes + 0x848, bytes + 0x848, 0);
    char* command = reinterpret_cast<char*>(bytes + 0x410);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(bytes + 0x10));
    strcat_s(command, 0x400, ".RemoveList");
    void* movie = *reinterpret_cast<void**>(bytes + 0x868);
    void* state = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
    void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(state) + 0x18);
    if (manager) {
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

// @0x1423d7610
void FUN_1423d7610(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    ImeTfSource* source = nullptr;
    if (*reinterpret_cast<DWORD*>(bytes + 0x1b8) != 0xffffffff) {
        if (IUnknown* manager = *reinterpret_cast<IUnknown**>(bytes + 0x1d0)) {
            if (SUCCEEDED(manager->QueryInterface(*reinterpret_cast<const IID*>(DAT_1431c51e8),
                                                  reinterpret_cast<void**>(&source)))) {
                if (source->UnadviseSink(*reinterpret_cast<DWORD*>(bytes + 0x1b8)) == CONNECT_E_NOCONNECTION)
                    reinterpret_cast<IUnknown*>(bytes + 0x1a0)->Release();  // the embedded sink at +0x1a0
                source->Release();
            }
        }
        *reinterpret_cast<DWORD*>(bytes + 0x1b8) = 0xffffffff;
    }
}

// @0x1423d7690
void FUN_1423d7690(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    if (*reinterpret_cast<DWORD*>(bytes + 0x1b0) != 0xffffffff) {
        if (IUnknown* manager = *reinterpret_cast<IUnknown**>(bytes + 0x1d0)) {
            ImeTfSource* source;
            if (SUCCEEDED(manager->QueryInterface(*reinterpret_cast<const IID*>(DAT_1431c51e8),
                                                  reinterpret_cast<void**>(&source)))) {
                source->UnadviseSink(*reinterpret_cast<DWORD*>(bytes + 0x1b0));
                source->Release();
            }
        }
        *reinterpret_cast<DWORD*>(bytes + 0x1b0) = 0xffffffff;
    }
}

// @0x1423dac70
int FUN_1423dac70(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* source = *reinterpret_cast<void**>(bytes + 0x28);
    void* result;
    int success = 0;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    if (reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result) >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        if (reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
                result, &DAT_1431c4d58, bytes, bytes + 0x18) < 0)
            *reinterpret_cast<unsigned*>(bytes + 0x18) = 0xffffffff;
        else
            success = 1;
    }
    if (result) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(result))[2])(result);
    return success;
}

// @0x1423dacf0
int FUN_1423dacf0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* source = *reinterpret_cast<void**>(bytes + 0x28);
    void* result = nullptr;
    int success = 0;
    auto** sourceVtable = *reinterpret_cast<void***>(source);
    if (reinterpret_cast<int(*)(void*, const void*, void**)>(sourceVtable[0])(source, DAT_1431c51e8, &result) >= 0) {
        auto** resultVtable = *reinterpret_cast<void***>(result);
        if (reinterpret_cast<int(*)(void*, const void*, void*, void*)>(resultVtable[3])(
                result, &DAT_14313b8b8, bytes + 8, bytes + 0x1c) < 0)
            *reinterpret_cast<unsigned*>(bytes + 0x1c) = 0xffffffff;
        else
            success = 1;
    }
    if (result) reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(result))[2])(result);
    return success;
}

// Records the IME name/display metadata flags and appends an empty IME record for imeName.
// @0x1423ca6b0
void FUN_1423ca6b0(void* raw, const char* name)
{
    struct Record {
        struct Unknown { unsigned long long low, high; Unknown() {} } unknown;
        Scaleform::String name;
        Scaleform::String display;
        unsigned locale;
        void* profiles;
        Record() : locale(0x2000000), profiles(nullptr) {}
    };
    if (!raw) return;
    auto* bytes = static_cast<unsigned char*>(raw);
    if (strcmp(name, "language") == 0) bytes[0xa9] = 1;
    *reinterpret_cast<unsigned*>(bytes + 0xb0) = 3;
    if (strcmp(name, "imeName") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 0;
        bytes[0xaa] = 1;
        Record record;
        auto* array = reinterpret_cast<unsigned long long*>(bytes + 0xb8);
        const unsigned long long size = array[1];
        const unsigned long long newSize = size + 1;
        if (newSize < size) {
            FUN_1423c9330(array[0] + newSize * sizeof(Record), size - newSize);
            if (newSize < (array[2] >> 1))
                reinterpret_cast<Ime01CueArr*>(array)->Reserve(array, newSize);
        } else if (newSize >= array[2])
            reinterpret_cast<Ime01CueArr*>(array)->Reserve(array, newSize + (newSize >> 2));
        array[1] = newSize;
        new (reinterpret_cast<Record*>(array[0]) + newSize - 1) Record(record);
        ++*reinterpret_cast<int*>(bytes + 0xd0);
    }
    if (strcmp(name, "displayName") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 1;
        bytes[0xab] = 1;
    }
    if (strcmp(name, "Tag") == 0) {
        *reinterpret_cast<unsigned*>(bytes + 0xb0) = 2;
        bytes[0xac] = 1;
    }
}

// @0x1423d4fa0
__declspec(noinline) void FUN_1423d4fa0(unsigned long long* array, const Scaleform::GFx::Value* value)
{
    // ArrayData<Value>::PushBack: the generic Resize(size + 1) inline, then a placement copy.
    const unsigned long long oldLength = array[1];
    const unsigned long long newLength = oldLength + 1;
    if (newLength < oldLength) {
        FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::Value*>(array[0]) + newLength, oldLength - newLength);
        if (newLength < (array[2] >> 1))
            FUN_1423d12e0(array, array, newLength);
    } else if (newLength >= array[2]) {
        FUN_1423d12e0(array, array, (newLength >> 2) + newLength);
    }
    array[1] = newLength;
    new (reinterpret_cast<Scaleform::GFx::Value*>(array[0]) + newLength - 1) Scaleform::GFx::Value(*value);
}

// The keyboard layouts the IMM IME object saved (+0x80 count, +0x90 records) and the active one (+0x198).
struct SavedLayout { char* name; void* p8; void* p10; HKL layout; };
struct SavedLayoutsView
{
    unsigned char pad0[0x80];
    unsigned count;
    unsigned char pad84[0xc];
    SavedLayout* layouts;
    unsigned char pad98[0x100];
    HKL active;

    int Find(const char* name) const
    {
        for (unsigned i = 0; i < count; ++i)
            if (strcmp(layouts[i].name, name) == 0 && layouts[i].layout)
                return i;
        return -1;
    }
};
static_assert(sizeof(SavedLayout) == 0x20, "IME layout");
static_assert(offsetof(SavedLayoutsView, active) == 0x198, "IME layout");

// activates the saved keyboard layout whose name matches the requested string.
// @0x1423d7890
void FUN_1423d7890(void* self, const char* name)
{
    auto* view = static_cast<SavedLayoutsView*>(self);
    int index = view->Find(name);
    if (index != -1) {
        view->active = view->layouts[index].layout;
        ActivateKeyboardLayout(view->active, 0);
    }
}

// A keyboard-layout name keyed by its hash (slot 5 of 0x143138530 returns it by value).
struct LayoutNameKey { String name; UPInt hash; SPInt length; };

// stores the current keyboard-layout name together with its hash and byte length.
// @0x1423d7df0
LayoutNameKey* FUN_1423d7df0(void*, LayoutNameKey* key)
{
    char layoutName[KL_NAMELENGTH];
    GetKeyboardLayoutNameA(layoutName);
    int length = static_cast<int>(strlen(layoutName));
    unsigned hash = HashFunction(layoutName, length);
    new (key) String(layoutName);
    key->hash = hash;
    key->length = length;
    return key;
}

// An object with a second interface view at +8, whose QueryInterface follows.
struct ImeQiFirst { void* vftable; };
struct ImeQiSecond { void* vftable; };
struct ImeQiObject : ImeQiFirst, ImeQiSecond {};

// The QueryInterface of an object with two interface views: IUnknown (DAT_1431c4828), DAT_1431c4d58, DAT_1431c4e08
// and DAT_1431c4ee8 answer with the object itself, DAT_14313b8b8 with its +8 view.
// @0x1423dadd0
__declspec(noinline) HRESULT Ime01TsfUiSink::QueryInterface(const unsigned long long* iid, void** output)
{
    long long* object = reinterpret_cast<long long*>(this);
    if (!output) return E_INVALIDARG;
    *output = nullptr;
    const IID& riid = *reinterpret_cast<const IID*>(iid);
    if (riid == *reinterpret_cast<const IID*>(&DAT_1431c4828) || riid == *reinterpret_cast<const IID*>(&DAT_1431c4d58))
        *output = object;
    else if (riid == *reinterpret_cast<const IID*>(&DAT_14313b8b8))
        *output = static_cast<ImeQiSecond*>(reinterpret_cast<ImeQiObject*>(object));
    else if (riid == *reinterpret_cast<const IID*>(&DAT_1431c4e08) || riid == *reinterpret_cast<const IID*>(&DAT_1431c4ee8))
        *output = object;
    else
        return E_NOINTERFACE;
    if (!*output) return E_NOINTERFACE;
    reinterpret_cast<IUnknown*>(object)->AddRef();
    return S_OK;
}

// @0x1423ccfc0
void GFxIMEManagerWin32::IMECommand(Movie* pmovie, const char* command, const char* value)
{
    long long owner = reinterpret_cast<long long>(pmovie);
    auto* bag = reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10);
    auto log = bag->GetLog();
    if (!log) return;
    log->LogMessage("imecommand: '");
    log->LogMessage(const_cast<char*>(command));
    log->LogMessage("' '");
    log->LogMessage("%s", value);
    log->LogMessage("'\n");
}

// Shows `text` (taken by value, released on return) in the +0x78 status movie: slot 18 (+0x90) then slot 16 (+0x80)
// with the C string, re-reading the movie in between. Unless the +0x88 mode is 0x1000000 or has a 0xf00000 bit,
// it then calls its own slot 10 (+0x50) with the +0xd4 value.
// @0x1423ccdc0
void FUN_1423ccdc0(unsigned long long* object, String text)
{
    auto* bytes = reinterpret_cast<unsigned char*>(object);
    if (!*reinterpret_cast<void**>(bytes + 0x78))
        return;
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(*reinterpret_cast<void**>(bytes + 0x78)))[0x90 / sizeof(void*)])(
        *reinterpret_cast<void**>(bytes + 0x78));
    void* movie = *reinterpret_cast<void**>(bytes + 0x78);
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(movie))[0x80 / sizeof(void*)])(movie, text.ToCStr());
    const unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x88);
    if (mode != 0x1000000 && (mode & 0xf00000) == 0)
        reinterpret_cast<void(*)(void*, unsigned)>((*reinterpret_cast<void***>(object))[0x50 / sizeof(void*)])(
            object, *reinterpret_cast<unsigned*>(bytes + 0xd4));
}

// Shows "Not Supported", then for the first saved layout record (+0xb8, 0x30 bytes each, +0xd0 of them) whose mode is the
// current +0x88 mode and that has a layout: its +0x18 text when the +0x190 state is 2, its +0x10 text when it is 1.
// MS2-FUNCTIONAL: register choice only (exe holds the +0x88 mode in r8d, ours r9d).
// @0x1423cc2d0
void FUN_1423cc2d0(unsigned long long* object)
{
    struct LayoutRecord { unsigned char pad[0x10]; String text1; String text2; unsigned mode; void* layout; };
    auto* bytes = reinterpret_cast<unsigned char*>(object);
    FUN_1423ccdc0(object, String("Not Supported"));
    unsigned i = 0;
    if (!*reinterpret_cast<unsigned*>(bytes + 0xd0))
        return;
    const unsigned mode = *reinterpret_cast<unsigned*>(bytes + 0x88);
    for (; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        if (mode != 0x1000000 && mode == reinterpret_cast<LayoutRecord*>(object[0x17])[i].mode &&
            reinterpret_cast<LayoutRecord*>(object[0x17])[i].layout) {
            if (reinterpret_cast<unsigned*>(object[50])[i] == 2)
                FUN_1423ccdc0(object, reinterpret_cast<LayoutRecord*>(object[0x17])[i].text2);
            if (reinterpret_cast<unsigned*>(object[50])[i] == 1)
                FUN_1423ccdc0(object, reinterpret_cast<LayoutRecord*>(object[0x17])[i].text1);
            break;
        }
    }
}


// The IME module's reading-string entry points (exe 0x143b103d0 / 0x143b103d8), kept by FUN_1423cb660 only.
static FARPROC s_imeGetReadingString;
static FARPROC s_imeShowReadingWindow;

struct ImeReadingWindowHost { unsigned char opaque[0x68]; HWND hwnd; };
struct ImeReadingWindowOwner { unsigned char opaque[0x78]; ImeReadingWindowHost* host; };

// Loads the current keyboard layout's IME module and hides its reading window through ShowReadingWindow.
// @0x1423cb660
void FUN_1423cb660(void* self)
{
    char fileName[0x104];
    if (!cx18_ImmGetIMEFileNameA(GetKeyboardLayout(0), fileName, sizeof(fileName))) return;
    HMODULE ime = LoadLibraryA(fileName);
    if (!ime) return;
    s_imeGetReadingString = GetProcAddress(ime, "GetReadinString");
    s_imeShowReadingWindow = GetProcAddress(ime, "ShowReadingWindow");
    if (!s_imeShowReadingWindow) return;
    HIMC context = ImmGetContext(static_cast<ImeReadingWindowOwner*>(self)->host->hwnd);
    if (!context) return;
    reinterpret_cast<void(WINAPI*)(HIMC, int)>(s_imeShowReadingWindow)(context, 0);
    cx18_ImmReleaseContext(static_cast<ImeReadingWindowOwner*>(self)->host->hwnd, context);
}

// Sets the IME open status (ImmSetOpenStatus), associating a default context for the call when the window has none.
// @0x1423d1760
bool FUN_1423d1760(void* self, unsigned char open)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    bool wasAssociated = true;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    if (!context) {
        wasAssociated = false;
        cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr, 0x10);
        context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
        if (!context) {
            cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr);
            return false;
        }
    }
    const bool result = cx18_ImmSetOpenStatus(context, open) != 0;
    if (!wasAssociated) cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    bytes[0x80] = open;
    return result;
}

// Sets the IME composition string (SCS_SETSTR) to the UTF-8 `text`, decoded by WStringBuffer; the byte length is the
// UTF-8 character count (UTF8Util::GetLength) times two, as in the exe.
// @0x1423d14d0
bool FUN_1423d14d0(void* self, const char* text)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    const SPInt length = Scaleform::UTF8Util::GetLength(text, -1);
    Scaleform::WStringBuffer composition;
    composition = text;
    bool result;
    if (context) {
        const wchar_t* chars = composition.GetBuffer();
        result = cx18_ImmSetCompositionStringW(context, SCS_SETSTR, chars ? chars : L"",
                                               static_cast<DWORD>(length * sizeof(wchar_t)), nullptr, 0) != 0;
        cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    } else
        result = false;
    return result;
}

// Sets the IME conversion mode for the current keyboard layout (saved at +0x90). The low conversion bits are
// cleared and, per language, `mode` picks the native/full-shape bits: Japanese 0 / 4 / 8 / 0x16, Korean 0x32 or 0,
// Chinese (0x404 / 0x804) 2 or 0; mode 1 keeps alphanumeric, any other mode is unsupported for these languages and
// sets nothing (the IME may already have been opened). Other languages always take the cleared mode. Returns
// whether the mode was applied.
// Checked case by case against the exe's control flow (Korean chat depends on the 0x412 path).
// MS2-FUNCTIONAL: the exe loads the whole HKL and does not thread the 0x411 block past the 0x412 test
// @0x1423d15b0
bool FUN_1423d15b0(void* self, int mode)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<HKL*>(bytes + 0x90) = GetKeyboardLayout(0);
    bool wasAssociated = true;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    if (!context) {
        wasAssociated = false;
        cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr, 0x10);
        context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
        if (!context) {
            cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr);
            return false;
        }
    }
    bool supported = true;
    DWORD conversion, sentence;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    if ((conversion & 0xf) == 0) cx18_ImmSetOpenStatus(context, TRUE);
    conversion &= ~0xfu;
    const unsigned long long language = reinterpret_cast<unsigned long long>(*reinterpret_cast<HKL*>(bytes + 0x90)) & 0xffff;
    if (language == 0x411) {
        switch (mode) {
        case 0: conversion |= 8; break;
        case 1: break;
        case 4: conversion |= 9; break;
        case 8: conversion |= 0xb; break;
        case 0x16: conversion |= 3; break;
        default: supported = false; break;
        }
    }
    if (language == 0x412) {
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
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    if (!wasAssociated) cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(bytes + 0x28), nullptr, 0);
    return supported;
}

__declspec(noinline) void FUN_1423d94f0(void*, void*);

// MS2-FUNCTIONAL: Movie is declared only for its recovered Release call; surrounding window/movie manager layout is opaque.

// The factory interface and helper argument types remain opaque; recovered calls preserve offsets and order.
// @0x1423d4690
void FUN_1423d4690(void* self)
{
    void* base = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 8);
    if (base) {
        void* factory = static_cast<unsigned char*>(base) + 0x10;
        void** vtable = *reinterpret_cast<void***>(factory);
        void* value = reinterpret_cast<void*(*)(void*, int)>(vtable[3])(factory, 0x18);
        static_cast<Scaleform::GFx::IMEManagerBase*>(value)->SetWideCursor(false);
        static_cast<Scaleform::GFx::IMEManagerBase*>(value)->ClearComposition();
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
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> value = *static_cast<Scaleform::GFx::IMEManagerBase*>(
        reinterpret_cast<void*(*)(void*, int)>(vtable[3])(factory, 0x18));
    value->SetWideCursor(false);
    value->ClearComposition();
    *(static_cast<unsigned char*>(self) + 0xb8) = 0;
}

// Cancels the composition (NI_COMPOSITIONSTR: CPS_CANCEL, CPS_COMPLETE, CPS_CONVERT) and clears the buffer.
// @0x1423ce4f0
void FUN_1423ce4f0(void* self)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 3, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
}

// Selects candidate `key`: through the IMM candidate list (NI_SELECTCANDIDATESTR, NI_OPENCANDIDATE,
// NI_SETCANDIDATE_PAGESTART), or for five values of +0x98 by sending the digit key ('1' + key) with SendInput.
// @0x1423d53e0
void FUN_1423d53e0(void* self, int key)
{
    unsigned char* bytes = static_cast<unsigned char*>(self);
    int state = *reinterpret_cast<int*>(bytes + 0x98);
    if (state != 0x110000 && state != 0x210000 && state != 0xc10000 &&
        state != 0x60000 && state != 0xd10000) {
        HIMC context = ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
        cx18_ImmNotifyIME(context, 0x12, 0, *reinterpret_cast<int*>(bytes + 0x70) + key);
        cx18_ImmNotifyIME(context, 0x11, 0, 0);
        cx18_ImmNotifyIME(context, 0x16, 0, *reinterpret_cast<DWORD*>(bytes + 0x70));
        cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    } else {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = static_cast<WORD>(key + 0x31);
        input.ki.wScan = static_cast<WORD>(MapVirtualKeyW(key + 0x31, 0));
        SendInput(1, &input, sizeof(input));
    }
}

// @0x1423d1c90
void FUN_1423d1c90(void** self)
{
    void** selfVtable = *reinterpret_cast<void***>(self);
    reinterpret_cast<void(*)(void*)>(selfVtable[0x80 / sizeof(void*)])(self);
    void* movie = reinterpret_cast<void**>(self)[0x15];
    Scaleform::GFx::Value result;
    if (void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18)) {
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
            (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(bridge, "RemoveInputWindow", &result, 0, 0);
    }
}

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
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 3, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xd0) = 0;
}

// @0x1423d1830
void FUN_1423d1830(void* self, unsigned long long* movie)
{
    const unsigned long long value = *movie;
    *reinterpret_cast<unsigned long long*>(static_cast<unsigned char*>(self) + 8) = value;
    FUN_1423d94f0(*reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x30),
                  reinterpret_cast<void*>(value));
    if (*movie)
        reinterpret_cast<Scaleform::GFx::Movie*>(*movie)->Release();
}

// @0x1423d94f0
void FUN_1423d94f0(void* self, void* value)
{
    *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 8) = value;
}

// The XML DOM string set's out-of-line HashSetBase members (pinned at the end of the file): Add at 0x1423ca950,
// add (with the hash value) at 0x1423caa80 and setRawCapacity at 0x1423cce50. The exe keeps copies of these apart
// from the XML unit's (0x1429a4ad0/0x1429a4c00/0x1429a63b0); the unit-local hash functor gives them their own names.
// The set's nodes keep their 32-bit hash at +0x20, not at DOMStringNode::HashFlags (+0x10).
struct Ime01NodeHash
{
    UPInt operator()(Scaleform::GFx::XML::DOMStringNode* const& node) const
    { return *reinterpret_cast<const UInt32*>(reinterpret_cast<const char*>(node) + 0x20); }
};
typedef Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode*, Ime01NodeHash, Ime01NodeHash,
    Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode*, 0x201>,
    Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode*, Ime01NodeHash>> Ime01StringSetBase;
}}}
namespace Scaleform {
template void GFx::IME::Ime01StringSetBase::Add<GFx::XML::DOMStringNode*>(void*, GFx::XML::DOMStringNode* const&);
template void GFx::IME::Ime01StringSetBase::add<GFx::XML::DOMStringNode*>(void*, GFx::XML::DOMStringNode* const&, UPInt);
template void GFx::IME::Ime01StringSetBase::setRawCapacity(void*, UPInt);
}
namespace Scaleform { namespace GFx { namespace IME {

static __forceinline void FUN_1423ca950(Scaleform::GFx::XML::XMLDOMStringNodeHash* set, void* heap,
                                        Scaleform::GFx::XML::DOMStringNode* const* value)
{ reinterpret_cast<Ime01StringSetBase*>(set)->Add(heap, *value); }

// Queries the +0x28 manager for the provider (IID 0x14313b8a8), gets the context for the +0x50 id (slot 6), and from it
// the text interface (IID 0x14313b8c8), then calls slot 15 (+0x78) with the +0x60 base plus `offset`. As in the exe,
// the out pointers are not initialised and are released only when the query succeeded.
// @0x1423daf30
unsigned long long FUN_1423daf30(void* raw, int offset)
{
    auto* self = static_cast<unsigned char*>(raw);
    IUnknown* manager = *reinterpret_cast<IUnknown**>(self + 0x28);
    IUnknown* provider;
    if (FAILED(manager->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b8a8), reinterpret_cast<void**>(&provider))))
        return 0;
    IUnknown* context;
    if (FAILED(reinterpret_cast<HRESULT(*)(IUnknown*, unsigned, IUnknown**)>((*reinterpret_cast<void***>(provider))[6])(
            provider, *reinterpret_cast<unsigned*>(self + 0x50), &context))) {
        if (provider) provider->Release();
        return 0;
    }
    IUnknown* text;
    if (FAILED(context->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b8c8), reinterpret_cast<void**>(&text)))) {
        if (context) context->Release();
        if (provider) provider->Release();
        return 0;
    }
    reinterpret_cast<void(*)(IUnknown*, int)>((*reinterpret_cast<void***>(text))[0x78 / sizeof(void*)])(
        text, *reinterpret_cast<int*>(self + 0x60) + offset);
    if (context) context->Release();
    if (provider) provider->Release();
    if (text) text->Release();
    return 0;
}

// Enables or disables the window IME (IACE_DEFAULT). For Korean the sentence mode is cleared; for other languages the
// native-mode bit and phrase prediction follow the flag. Reviewed against the exe, same behaviour.
// enabled is 0 or 1, so enabled << 3 is IME_SMODE_PHRASEPREDICT; the barrier keeps cl from hoisting the
// ImmGetConversionStatus call that both branches make, as the exe does.
// MS2-FUNCTIONAL: same length; the flag and the context are in each other's registers (rsi/rbp), and the shift comes
// before the movzx
// @0x1423cfbe0
void FUN_1423cfbe0(void* raw, unsigned char enabled)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (!enabled && *reinterpret_cast<int*>(self + 0xbc) > 0)
        *reinterpret_cast<unsigned char*>(self + 0xc0) = 1;
    if (*reinterpret_cast<int*>(self + 0xbc) != 0) return;

    HIMC oldContext = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    // IMEManagerBase::GetInputLanguage (slot 10); the exe inlines strcmp and drops the String right away
    const bool korean =
        std::strcmp((*reinterpret_cast<IMEManagerBase**>(self + 0xa8))->GetInputLanguage().ToCStr(), "Korean") == 0;
    cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(self + 0x28), nullptr, static_cast<DWORD>(enabled) << 4);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    DWORD conversion;
    DWORD sentence;
    if (korean) {
        _ReadWriteBarrier();
        cx18_ImmGetConversionStatus(context, &conversion, &sentence);
        cx18_ImmSetConversionStatus(context, conversion, IME_SMODE_NONE);
    } else {
        cx18_ImmGetConversionStatus(context, &conversion, &sentence);
        conversion = !enabled ? (conversion & ~IME_CMODE_NATIVE) : (conversion | IME_CMODE_NATIVE);
        sentence = static_cast<unsigned char>(enabled << 3);
        cx18_ImmSetConversionStatus(context, conversion, sentence);
    }
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), oldContext);
    *reinterpret_cast<unsigned char*>(self + 0xc0) = 0;
}

// Maps the IMM conversion bits to the IME mode label (Japanese, Korean or Chinese by the language mask at +0x98) and
// stores it in the String at +0x78; associates a default context temporarily when the window has none.
// @0x1423cf1c0
const char* FUN_1423cf1c0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    bool alreadyAssociated = true;
    if (!context) {
        alreadyAssociated = false;
        cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(self + 0x28), nullptr, IACE_DEFAULT);
        context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
        if (!context) {
            cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), nullptr);
            return "UNKNOWN";
        }
    }
    DWORD conversion;
    DWORD sentence;
    cx18_ImmGetConversionStatus(context, &conversion, &sentence);
    auto* text = reinterpret_cast<String*>(self + 0x78);
    *text = "";
    conversion &= 0xf;
    if (*reinterpret_cast<unsigned*>(self + 0x98) & 0xf00) {
        if ((conversion & ~8u) == 1) *text = "JAPANESE_HIRAGANA";
        if (conversion == 0xb) *text = "JAPANESE_KATAKANA_FULL";
        if (conversion == 3) *text = "JAPANESE_KATAKANA_HALF";
        if (conversion == 8) *text = "ALPHANUMERIC_FULL";
        if (conversion == 0) *text = "ALPHANUMERIC_HALF";
    }
    if (*reinterpret_cast<unsigned*>(self + 0x98) & 0xf000) {
        if ((conversion & ~8u) == 1) *text = "KOREAN";
        if (conversion == 8) *text = "ALPHANUMERIC_FULL";
        if (conversion == 0) *text = "ALPHANUMERIC_HALF";
    }
    if (*reinterpret_cast<unsigned*>(self + 0x98) & 0xf000f) {
        if ((conversion & ~8u) == 1) *text = "CHINESE";
        if (conversion == 8) *text = "ALPHANUMERIC_FULL";
        if (conversion == 0) *text = "ALPHANUMERIC_HALF";
    }
    if (!alreadyAssociated) cx18_ImmAssociateContextEx(*reinterpret_cast<HWND*>(self + 0x28), nullptr, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    if (text->GetSize() == 0) return "UNKNOWN";
    return text->ToCStr();
}

// MS2-FUNCTIONAL: matches the executable's language-specific IME registration, creates the COM provider, and sends its settings record.
// The search loop breaks out with the record index, as in the exe. Still differs: the exe addresses each record field as
// base + i*6 qwords (rsi*8), where ours forms a record pointer (shl 4; add).
// @0x1423d5740
void FUN_1423d5740(unsigned long long* self, const unsigned char* name)
{
    struct Record { unsigned long long pad0[2]; unsigned long long text1; unsigned long long text2; unsigned id; unsigned pad1; unsigned char** node; };
    int index = -1;
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0x1a); ++i) {
        const unsigned kind = reinterpret_cast<unsigned*>(self[0x32])[i];
        Record* records;
        if (kind == 1) {
            records = reinterpret_cast<Record*>(self[0x17]);
            if (std::strcmp(reinterpret_cast<const char*>(name),
                    reinterpret_cast<const char*>((records[i].text1 & ~3ull) + 0xc)) != 0) continue;
        } else if (kind == 2) {
            records = reinterpret_cast<Record*>(self[0x17]);
            if (std::strcmp(reinterpret_cast<const char*>(name),
                    reinterpret_cast<const char*>((records[i].text2 & ~3ull) + 0xc)) != 0) continue;
        } else {
            continue;
        }
        if (*reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x84) ==
                reinterpret_cast<unsigned(*)(void*, unsigned)>((*reinterpret_cast<void***>(self))[3])(self, records[i].id) &&
            reinterpret_cast<Record*>(self[0x17])[i].node) {
            index = static_cast<int>(i);
            break;
        }
    }
    if (index == -1) return;
    IUnknown* instance;
    HRESULT result = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068),
        reinterpret_cast<void**>(&instance));
    if (FAILED(result) || !instance) return;
    IUnknown* settings;
    result = instance->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b6b0),
        reinterpret_cast<void**>(&settings));
    if (SUCCEEDED(result) && settings) {
        auto* record = reinterpret_cast<Record*>(self[0x17])[index].node[0];
        if (record) {
            reinterpret_cast<void(*)(void*, unsigned, unsigned short, void*, void*, unsigned long long, unsigned)>(
                (*reinterpret_cast<void***>(settings))[3])(settings, *reinterpret_cast<unsigned*>(record),
                *reinterpret_cast<unsigned short*>(record + 4), record + 8, record + 0x18,
                *reinterpret_cast<unsigned long long*>(record + 0x48), 0x10000000);
        }
        settings->Release();
    }
    instance->Release();
}

// Releases the active IME list/window by state index and updates the composition bookkeeping. The manager is reread
// through self+8 each time and each Value is built before the movie lookup.
// @0x1423da730
unsigned long long Ime01TsfUiSink::EndUIElement(int state)
{
    void* raw = reinterpret_cast<unsigned char*>(this) + 8;   // the Ime01UIElementSink view
    auto* self = static_cast<unsigned char*>(raw);
    unsigned char*& manager = *reinterpret_cast<unsigned char**>(self + 8);
    const unsigned mode = *reinterpret_cast<unsigned*>(manager + 0x98);
    if (((mode - 0x01000000u) & 0xfeffffffu) != 0) {
        auto** managerVtable = *reinterpret_cast<void***>(manager);
        if (reinterpret_cast<unsigned char(*)(void*, void*)>(managerVtable[6])(manager,
                *reinterpret_cast<void**>(manager + 8))) {
            --*reinterpret_cast<int*>(manager + 0xbc);
            if (state == *reinterpret_cast<int*>(self + 0x48)) {
                if (*reinterpret_cast<void**>(manager + 8)) {
                    Scaleform::GFx::Value output;
                    void* bridge = *reinterpret_cast<void**>(manager + 0xa8);
                    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(bridge) + 0x18);
                    if (values) {
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
                    Scaleform::GFx::Value output;
                    void* bridge = *reinterpret_cast<void**>(manager + 0xa8);
                    void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(bridge) + 0x18);
                    if (values) {
                        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, void*, unsigned)>(
                            (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                                values, "RemoveInputWindow", &output, nullptr, 0);
                    }
                }
                *reinterpret_cast<String*>(manager + 0xb0) = "";
            }
            if (*reinterpret_cast<int*>(manager + 0xbc) == 0 &&
                *reinterpret_cast<char*>(manager + 0xc0)) {
                reinterpret_cast<void(*)(void*, int)>(
                    (*reinterpret_cast<void***>(manager))[0xd8 / sizeof(void*)])(manager, 0);
            }
        }
    }
    return 0;
}

// Reads the active keyboard layout into [+0x198], maps it to the language id at [+0x84] and shows its
// locale name. For a plain layout (HKL & 0xe0000000 == 0) it sets mode 0x1000000 and shows the "Layout Text" of the
// registry layout record whose id matches the HKL's high word, else the locale name; for an IME layout it shows the
// IME's mode text through FUN_1423cc2d0.
// The loop compares HIWORD of the re-read HKL (manager[0x33]), which cl zero-extends per iteration as the exe does.
// @0x1423d8870
void FUN_1423d8870(unsigned long long* manager)
{
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    manager[0x33] = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0));
    const unsigned language = reinterpret_cast<unsigned(*)(void*, unsigned short)>((*reinterpret_cast<void***>(manager))[4])(
        manager, *reinterpret_cast<unsigned short*>(bytes + 0x198));
    *reinterpret_cast<unsigned*>(bytes + 0x84) = language;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), language);
    wchar_t locale[0x104];
    if (!GetLocaleInfoW(*reinterpret_cast<unsigned short*>(bytes + 0x198), LOCALE_SLANGUAGE, locale, 0x104)) {
        const DWORD error = GetLastError();
        reinterpret_cast<void(*)(void*, DWORD, const char*)>((*reinterpret_cast<void***>(manager))[0x78 / sizeof(void*)])(
            manager, error, "GFxIME Error: Error Initializing Input Language Name ");
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x78 / sizeof(void*)])(
            reinterpret_cast<void*>(manager[0xf]), "Unsupported");
        return;
    }
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x78 / sizeof(void*)])(
        reinterpret_cast<void*>(manager[0xf]), String(locale).ToCStr());
    const unsigned long long layout = manager[0x33];
    if (!(layout & 0xe0000000)) {
        *reinterpret_cast<unsigned*>(bytes + 0x88) = 0x1000000;
        for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0x160); ++i) {
            if (HIWORD(manager[0x33]) == reinterpret_cast<LayoutRecord*>(manager[0x2b])[i].layoutId) {
                const char* text = reinterpret_cast<LayoutRecord*>(manager[0x2b])[i].layoutText;
                FUN_1423ccdc0(manager, String(text));
                return;
            }
        }
        FUN_1423ccdc0(manager, String(locale));
    } else
        FUN_1423cc2d0(manager);
}

// MS2-FUNCTIONAL: resolves the configured language string, activates its executable HKL, and reports activation failure.
// Still differs: the record pointer and the index swap r9 and r10, and the HKL is held in rax, not rcx.
// @0x1423d76f0
void FUN_1423d76f0(unsigned long long* manager, const char* name)
{
    struct Record { unsigned long long pad0[2]; unsigned long long text1; unsigned long long text2; unsigned id; unsigned pad1; HKL layout; };
    manager[0x33] = 0;
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(manager + 0x1a); ++i) {
        auto* kinds = reinterpret_cast<unsigned*>(manager[0x32]);
        Record* record;
        if (kinds[i] == 1) {
            record = &reinterpret_cast<Record*>(manager[0x17])[i];
            if (std::strcmp(name, reinterpret_cast<const char*>((record->text1 & ~3ull) + 0xc)) != 0) continue;
        } else if (kinds[i] == 2) {
            record = &reinterpret_cast<Record*>(manager[0x17])[i];
            if (std::strcmp(name, reinterpret_cast<const char*>((record->text2 & ~3ull) + 0xc)) != 0) continue;
        } else {
            continue;
        }
        HKL layout = record->layout;
        if (!layout) continue;
        manager[0x33] = reinterpret_cast<unsigned long long>(layout);
        if (ActivateKeyboardLayout(layout, 0)) return;
        reinterpret_cast<void(*)(void*, const char*, const char*)>(
            (*reinterpret_cast<void***>(manager))[0x70 / sizeof(void*)])(
                manager, (String("Failure to activate input language ") + name).ToCStr(), "GFxIME Error");
        return;
    }
}

// A local ArrayData<Value> the exe sizes through FUN_1423d9730.
struct Ime01ValueArgs
{
    Scaleform::GFx::Value* data;
    unsigned long long size;
    unsigned long long capacity;
    Ime01ValueArgs() : capacity(0) { _mm_storeu_si128(reinterpret_cast<__m128i*>(&data), _mm_setzero_si128()); }
    ~Ime01ValueArgs()
    {
        FUN_1423ce6c0(data, size);
        if (data) Memory::Free(data);
    }
};

// Stores the data item and, when notify is set, calls the input window's SelectDataItem (with the item) and SetList.
// @0x1423d97f0
__declspec(noinline) void FUN_1423d97f0(void* raw, unsigned long long item, unsigned char notify)
{
    auto* self = static_cast<unsigned char*>(raw);
    *reinterpret_cast<unsigned long long*>(self + 0x860) = item;
    if (!notify) return;
    Scaleform::GFx::Value result;
    Ime01ValueArgs args;
    char* command = reinterpret_cast<char*>(self + 0x410);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, 0x400, ".SelectDataItem");
    {
        Scaleform::GFx::Value argument(static_cast<double>(*reinterpret_cast<long long*>(self + 0x860)));
        FUN_1423d9730(&args, &args, 1);
        ::new (static_cast<void*>(args.data + args.size - 1)) Scaleform::GFx::Value(argument);
    }
    using Invoke = void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned);
    // The exe rereads the bridge for each call and rebuilds ".SetList" even without one (0x1423d992f).
    auto bridgeOf = [self]() {
        void* movie = *reinterpret_cast<void**>(self + 0x868);
        void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
        return *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
    };
    if (void* bridge = bridgeOf())
        reinterpret_cast<Invoke>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, command, &result, args.data, 1);
    strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
    strcat_s(command, 0x400, ".SetList");
    if (void* bridge = bridgeOf())
        reinterpret_cast<Invoke>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, command, &result, nullptr, 0);
}

// TSF display attribute of a range: ITfContext::GetProperty(GUID_PROP_ATTRIBUTE) (slot 12), ITfProperty::GetValue
// (slot 5) gives the attribute's guid atom, ITfCategoryMgr::GetGUID (slot 15) turns it into a GUID, and
// ITfDisplayAttributeMgr::GetDisplayAttributeInfo (slot 5) plus ITfDisplayAttributeInfo::GetAttributeInfo (slot 5)
// fill the TF_DISPLAYATTRIBUTE at attribute. A value that is not VT_I4 gives E_FAIL.
// @0x1423da940
HRESULT FUN_1423da940(void*, IUnknown* context, void* range, unsigned editCookie, void* attribute)
{
    IUnknown* categories;
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4888), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c51d8),
        reinterpret_cast<void**>(&categories));
    if (FAILED(hr)) return hr;
    IUnknown* attributes;
    hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4878), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c51b8),
        reinterpret_cast<void**>(&attributes));
    if (FAILED(hr)) {
        categories->Release();
        return hr;
    }
    IUnknown* property;
    hr = reinterpret_cast<HRESULT(*)(void*, const GUID&, IUnknown**)>((*reinterpret_cast<void***>(context))[12])(
        context, *reinterpret_cast<const GUID*>(&DAT_1431c48f8), &property);
    if (SUCCEEDED(hr)) {
        VARIANT atom;
        VariantInit(&atom);
        hr = reinterpret_cast<HRESULT(*)(void*, unsigned, void*, VARIANT*)>((*reinterpret_cast<void***>(property))[5])(
            property, editCookie, range, &atom);
        if (hr == S_OK) {
            if (static_cast<VARTYPE>(VT_I4) == atom.vt) {
                GUID guid;
                hr = reinterpret_cast<HRESULT(*)(void*, unsigned, GUID*)>((*reinterpret_cast<void***>(categories))[15])(
                    categories, static_cast<unsigned>(atom.lVal), &guid);
                if (SUCCEEDED(hr)) {
                    IUnknown* info;
                    hr = reinterpret_cast<HRESULT(*)(void*, const GUID&, IUnknown**, CLSID*)>(
                        (*reinterpret_cast<void***>(attributes))[5])(attributes, guid, &info, nullptr);
                    if (SUCCEEDED(hr)) {
                        hr = reinterpret_cast<HRESULT(*)(void*, void*)>((*reinterpret_cast<void***>(info))[5])(
                            info, attribute);
                        info->Release();
                    }
                }
            } else {
                hr = E_FAIL;
            }
            VariantClear(&atom);
        }
        property->Release();
    }
    categories->Release();
    attributes->Release();
    return hr;
}

// The destructor call is qualified: self->~MemoryContextImpl() is a virtual call through slot 0, back into this
// deleting destructor.
// Uses our AS3 memory context declaration to release its heap limit handler, owned references, and allocated storage.
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

// Creates the IME COM manager, queries its controller straight into +0x40 and advises both callback sinks; a key is
// set to -1 only when its advise call fails. The first sink's callback is not zeroed before its query, as in the exe.
// Returns 1 on success, 0 otherwise (the exe returns an int: xor eax,eax / mov eax,edi).
// MS2-FUNCTIONAL: same length; the callback is in rcx's home and rbx is saved at 0x18, where the exe saves rbx in
// rcx's home and keeps the callback at 0x50
// @0x1423daae0
int FUN_1423daae0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    IUnknown* callback;
    IUnknown* manager = nullptr;
    const HRESULT created = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4858), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c4d28), reinterpret_cast<void**>(&manager));
    if (FAILED(created)) {
        if (manager) manager->Release();
        return 0;
    }
    *reinterpret_cast<IUnknown**>(self + 0x28) = manager;
    if (FAILED(manager->QueryInterface(*reinterpret_cast<const IID*>(&DAT_14313b8d8),
            reinterpret_cast<void**>(self + 0x40)))) {
        if (manager) manager->Release();
        return 0;
    }
    IUnknown* controller = *reinterpret_cast<IUnknown**>(self + 0x40);
    auto** controllerVtable = *reinterpret_cast<void***>(controller);
    reinterpret_cast<void(*)(void*, void*, unsigned)>(controllerVtable[0x70 / sizeof(void*)])(
        controller, self + 0x38, 4);

    using Advise = HRESULT(*)(void*, const void*, void*, unsigned*);
    int ok = 0;
    if (SUCCEEDED((*reinterpret_cast<IUnknown**>(self + 0x28))->QueryInterface(
            *reinterpret_cast<const IID*>(&DAT_1431c51e8), reinterpret_cast<void**>(&callback)))) {
        auto* key = reinterpret_cast<unsigned*>(self + 0x18);
        if (FAILED(reinterpret_cast<Advise>((*reinterpret_cast<void***>(callback))[3])(callback, &DAT_1431c4d58, self, key)))
            *key = 0xffffffff;
        else
            ok = 1;
    }
    if (callback) callback->Release();
    if (ok != 1) return 0;
    callback = nullptr;
    ok = 0;
    if (SUCCEEDED((*reinterpret_cast<IUnknown**>(self + 0x28))->QueryInterface(
            *reinterpret_cast<const IID*>(&DAT_1431c51e8), reinterpret_cast<void**>(&callback)))) {
        auto* key = reinterpret_cast<unsigned*>(self + 0x1c);
        if (FAILED(reinterpret_cast<Advise>((*reinterpret_cast<void***>(callback))[3])(callback, &DAT_14313b8b8, self + 8,
                key)))
            *key = 0xffffffff;
        else
            ok = 1;
    }
    if (callback) callback->Release();
    if (ok != 1) return 0;
    auto* owner = *reinterpret_cast<unsigned char**>(self + 0x10);
    *reinterpret_cast<int*>(owner + 0xbc) = 0;
    return ok;
}

static __forceinline void Ime01ReleaseStringNode(const unsigned long long* stringInfo)
{
    Sfr33ReleasePacked(*stringInfo);
}

// Finds the locale row named by the by-value String (released on both exits) and shows the matching layout's
// text 1 or 2 through the manager's slot 8; returns bool (the sub eax,1 release form needs it).
// The slot 8 call is written once per kind; cl merges the two calls, loading the vtable into r8 as in the exe.
// @0x1423d8a10
bool FUN_1423d8a10(unsigned long long* manager, const unsigned long long* stringInfo)
{
    struct LocaleRow { const char* name; unsigned id; unsigned pad; };
    struct LayoutEntry { unsigned long long pad0[2]; String text1; String text2; unsigned id; unsigned pad1[3]; };
    const auto* rows = reinterpret_cast<const LocaleRow*>(DAT_143a2a3e0);
    unsigned index = 0;
    if (rows[0].id != 0x02000000) {
        do {
            if (std::strcmp(reinterpret_cast<const String*>(stringInfo)->ToCStr(), rows[index].name) == 0) {
                const unsigned localeId = rows[index].id;
                for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(manager + 0x1a); ++i) {
                    auto* entries = reinterpret_cast<LayoutEntry*>(manager[0x17]);
                    if (entries[i].id == localeId) {
                        const unsigned kind = reinterpret_cast<unsigned*>(manager[0x32])[i];
                        using Show = void(*)(void*, const char*);
                        if (kind == 1)
                            reinterpret_cast<Show>((*reinterpret_cast<void***>(manager))[0x40 / sizeof(void*)])(
                                manager, entries[i].text1.ToCStr());
                        else if (kind == 2)
                            reinterpret_cast<Show>((*reinterpret_cast<void***>(manager))[0x40 / sizeof(void*)])(
                                manager, entries[i].text2.ToCStr());
                        else continue;
                        Ime01ReleaseStringNode(stringInfo);
                        return true;
                    }
                }
            }
            ++index;
        } while (rows[index].id != 0x02000000);
    }
    Ime01ReleaseStringNode(stringInfo);
    return false;
}

// Reads the active IME DLL's version resource and combines its version bytes with the current keyboard layout's low word;
// 0 when any step fails.
unsigned FUN_1423cb260();
static __forceinline unsigned Ime01ImeVersion()
{
    HKL layout = GetKeyboardLayout(0);
    char fileName[0x400];
    if (cx18_ImmGetIMEFileNameA(layout, fileName, 0x3ff)) {
        if (HMODULE version = LoadLibraryA("Version")) {
            using GetSizeFn = DWORD (WINAPI*)(LPCSTR, LPDWORD);
            using GetInfoFn = BOOL (WINAPI*)(LPCSTR, DWORD, DWORD, LPVOID);
            using QueryFn = BOOL (WINAPI*)(LPCVOID, LPCSTR, LPVOID*, PUINT);
            auto getSize = reinterpret_cast<GetSizeFn>(GetProcAddress(version, "GetFileVersionInfoSizeA"));
            auto getInfo = reinterpret_cast<GetInfoFn>(GetProcAddress(version, "GetFileVersionInfoA"));
            auto query = reinterpret_cast<QueryFn>(GetProcAddress(version, "VerQueryValueA"));
            if (getSize && getInfo && query) {
                DWORD handle;
                if (const DWORD size = getSize(fileName, &handle)) {
                    void* data = reinterpret_cast<void*(*)(void*, unsigned long long, unsigned)>(
                        (*reinterpret_cast<void***>(DAT_143b15f60))[10])(DAT_143b15f60, size, 0);
                    if (data) {
                        void* fixedInfo;
                        UINT length;
                        if (getInfo(fileName, handle, size, data) && query(data, DAT_14305cd3c, &fixedInfo, &length)) {
                            const unsigned versionWord = *reinterpret_cast<unsigned*>(
                                static_cast<unsigned char*>(fixedInfo) + 8);
                            reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(
                                DAT_143b15f60, data);
                            return (static_cast<unsigned char>(versionWord) << 16) | (static_cast<int>(versionWord & 0xff0000) << 8) |
                                static_cast<unsigned short>(reinterpret_cast<ULONG_PTR>(layout));
                        }
                    }
                    reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(
                        DAT_143b15f60, data);
                }
            }
        }
    }
    return 0;
}

// @0x1423cb260
unsigned FUN_1423cb260()
{
    return Ime01ImeVersion();
}

// Looks up an executable IME command by its Bernstein hash and forwards the matching record to its handler.
// @0x1423d8d60
bool FUN_1423d8d60(Ime01CmdMap* map, long long operation, const char* key, unsigned long long flags)
{
    if (!operation) return false;
    Ime01CmdMap::Iterator it = map->Find(key);
    if (it.IsEnd()) return false;
    void* handler = it->Second.Handler;
    return reinterpret_cast<bool(*)(void*, long long, unsigned, const char*, unsigned long long)>(
        (*reinterpret_cast<void***>(handler))[1])(handler, operation, it->Second.Type, key, flags);
}

// @0x1423cad20
bool FUN_1423cad20(unsigned long long* node, const unsigned long long* query)
{
    if (*reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(node) + 0x24) != query[2])
        return false;
    return SFstricmp(reinterpret_cast<const char*>(node[0]),
        reinterpret_cast<const char*>((query[0] & ~3ull) + 0xc)) == 0;
}

}}}

// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7GFxIMEManagerWin32@IME@GFx@Scaleform@@6B@ 0x1431383e0

namespace Scaleform { namespace GFx { namespace IME {

// MS2-FUNCTIONAL: constructs the language bar COM bridge, its two callback objects, and the 0x100-character input buffer.
// The source shape follows the exe: FUN_1423cabb0 stays a call, the manager is re-read from +0x1d0 at every use,
// and the provider, language and callback references are released at the exe's points. data_rdata_sf_a now
// defines DAT_14313b410 as one 16-byte GUID, so the GUID is passed straight from .rdata like the exe does
// (466 bytes, the exe's size). One diff remains (22 lines; 12 before the embedded sink at +0x1a0 was built by its
// inline ctor instead of raw vftable-image stores, which also gives up the r12 zero register): /O2 store scheduling. The exe puts the
// provider-home zero store ([rsp+0x88]) and the +0x1c0 zero store right after the vftable store; cl sinks
// both below the other vftable stores, next to the String ctor call. Declaring provider earlier moves its
// store above the FUN_1423cabb0 call (7 lines). Every reorder of the eight setup stores gives the same 12 lines.
// Same stores and values in a different order, so behaviour does not change.
//
// Before this change the function was 828 bytes (FUN_1423cabb0 inlined), then 500 (a 16-byte local GUID copy).
//
// @0x1423d54d0
unsigned long long* FUN_1423d54d0(unsigned long long* self, unsigned long long owner)
{
    FUN_1423cabb0(self, owner);
    reinterpret_cast<Ime01TsfSink*>(self + 0x34)->Ime01TsfSink::Ime01TsfSink();
    void* provider = nullptr;
    self[0] = reinterpret_cast<unsigned long long>(DAT_14313b520);
    void** managerSlot = reinterpret_cast<void**>(self + 0x3a);
    *managerSlot = nullptr;
    self[0x38] = 0;
    *reinterpret_cast<Scaleform::String*>(self + 0xe) = "";

    // The exe creates the thread manager straight into +0x1d0 (0x1423d5505) and keeps that reference:
    // the dtor and FUN_1423d7610/FUN_1423d7690 unadvise the sinks through it.
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4858), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c4d28), managerSlot);
    if (FAILED(hr)) return self;
#define manager (*managerSlot)
#define comCall(p, slot, sig) reinterpret_cast<sig>((*reinterpret_cast<void***>(p))[slot])
    if (FAILED(comCall(manager, 0, HRESULT(*)(void*, const void*, void**))(manager, DAT_1431c51e8, &provider))) {
        // Released but left in +0x1d0, as in the exe (0x1423d5585 -> 0x1423d5673).
        if (manager) comCall(manager, 2, ULONG(*)(void*))(manager);
    } else {
        if (FAILED(comCall(provider, 3, HRESULT(*)(void*, const void*, void*, void*))(
                provider, DAT_14313b400, self + 0x35, self + 0x36)))
            *reinterpret_cast<unsigned*>(self + 0x36) = 0xffffffffu;
        void* language = nullptr;
        if (SUCCEEDED(comCall(manager, 0, HRESULT(*)(void*, const void*, void**))(manager, DAT_1431c5028, &language))
                && language) {
            // The compartment GUID is passed straight from .rdata (0x14313b410).
            comCall(language, 3, HRESULT(*)(void*, const void*, void**))(language, &DAT_14313b410,

                reinterpret_cast<void**>(self + 0x38));
            comCall(language, 2, ULONG(*)(void*))(language);
        }
        void* callback = nullptr;
        if (void* settings = reinterpret_cast<void*>(self[0x38])) {
            if (SUCCEEDED(comCall(settings, 0, HRESULT(*)(void*, const void*, void**))(settings, DAT_1431c51e8, &callback))) {
                if (FAILED(comCall(callback, 3, HRESULT(*)(void*, const void*, void*, void*))(
                        callback, DAT_1431c5018, self + 0x34, self + 0x37)))
                    *reinterpret_cast<unsigned*>(self + 0x37) = 0xffffffffu;
            }
            if (callback) comCall(callback, 2, ULONG(*)(void*))(callback);
        }
    }
    if (provider) comCall(provider, 2, ULONG(*)(void*))(provider);
#undef manager
#undef comCall
    return self;
}

// MS2-FUNCTIONAL: selects the requested IME language entry, avoids duplicate active layouts, and updates the four mode strings.
// The manager's entry array (+0xb8), count (+0xd0) and state array (+0x190) are re-read after every call, as in the exe.
// @0x1423d7940
unsigned long long FUN_1423d7940(long long* manager, const char* primary, const char* fallback)
{
#define cx40_Entry(i) (reinterpret_cast<unsigned char*>(manager[0x17]) + static_cast<unsigned long long>(i) * 0x30)
#define cx40_Name(i)  (*reinterpret_cast<Scaleform::String*>(cx40_Entry(i) + 0x10))
#define cx40_Lang(i)  (*reinterpret_cast<int*>(cx40_Entry(i) + 0x20))
#define cx40_Count    (*reinterpret_cast<unsigned*>(manager + 0x1a))
#define cx40_States   (reinterpret_cast<unsigned*>(manager[0x32]))
    Scaleform::String selected;
    unsigned index;
    for (index = 0; index < cx40_Count; ++index) {
        if (primary && Scaleform::SFstricmp(primary, cx40_Name(index).ToCStr()) == 0 && cx40_States[index] == 0) {
            selected = cx40_Name(index);
            cx40_States[index] = 1;
            goto selected_entry;
        }
    }
    {
        bool fallbackSelected = false;
        int language = 0x2000000;
        for (index = 0; index < cx40_Count; ++index) {
            if (fallback && Scaleform::SFstricmp(fallback, cx40_Name(index).ToCStr()) == 0) {
                selected = *reinterpret_cast<Scaleform::String*>(cx40_Entry(index) + 0x18);
                cx40_States[index] = 2;
                fallbackSelected = true;
                language = cx40_Lang(index);
                break;
            }
        }
        for (unsigned i = 0; i < cx40_Count; ++i) {
            if (cx40_States[i] == 1 && cx40_Lang(i) == language)
                return 0xffffffffu;
        }
        if (!fallbackSelected)
            return 0xffffffffu;
    }
selected_entry:
    {
        const unsigned mask = reinterpret_cast<unsigned(*)(void*, unsigned)>(
            (*reinterpret_cast<void***>(manager))[3])(manager, cx40_Lang(index));
        if (mask & 0xf00) reinterpret_cast<Ime01StringArray*>(manager + 2)->PushBack(selected);
        if (mask & 0xf000) reinterpret_cast<Ime01StringArray*>(manager + 5)->PushBack(selected);
        if (mask & 0xf0000) reinterpret_cast<Ime01StringArray*>(manager + 8)->PushBack(selected);
        if (mask & 0xf) reinterpret_cast<Ime01StringArray*>(manager + 0xb)->PushBack(selected);
    }
    return index;
#undef cx40_Entry
#undef cx40_Name
#undef cx40_Lang
#undef cx40_Count
#undef cx40_States
}

// (0x1423dbb60 is cl's ??_GAvmMovieClip, emitted here by Ime01EmitAvmMovieClipVftables at the end of the file)

__declspec(noinline) void FUN_1423cdda0(void** table);

// Destroys the manager: releases the child at +0x30, then the +0x78 string, the +0x40 array, the +0x38 hash and the
// +0x20 / +0x18 / +0x10 strings, in reverse member order.
// @0x1423cdf60
void FUN_1423cdf60(unsigned long long* self)
{
    // the base vtable at 0x14313a258 is the p20 member of the DAT_14313a238 piece; DAT_14313a228 is a separate
    // 0x18-byte piece in the fullexe, so DAT_14313a228 + 6 landed in another table
    struct Hash { void* table; ~Hash() { FUN_1423cdda0(&table); } };
    struct Array { void* data; unsigned long long size, capacity; ~Array() { Scaleform::Memory::Free(data); } };
    struct View {
        const void* vtable; unsigned long long p8;
        Scaleform::String s10, s18, s20; unsigned long long p28; void* child;
        Hash hash; Array array; unsigned long long p58[4];
        Scaleform::String s78;
        ~View()
        {
            vtable = DAT_14313a238 + 4;
            FUN_1423d9500(child);
            if (child)
                reinterpret_cast<unsigned long long(*)(void*, unsigned)>((*reinterpret_cast<void***>(child))[2])(child, 1);
        }
    };
    reinterpret_cast<View*>(self)->~View();
}

// A by-value Ptr to a RefCountNTSImpl object (released through FUN_14257dcd0 when the callee returns).
struct Ime01NtsPtr
{
    void* p;
    Ime01NtsPtr(const Ime01NtsPtr& src);
    ~Ime01NtsPtr() { if (p) FUN_14257dcd0(p); }
};
// A GFx::Value whose destructor keeps the two zero stores after the managed release, as the exe's inlined dtor does.
// The barrier keeps the stores without volatile, so the slot can still be shared with other Values.
struct Ime01KeptValue
{
    void** objectInterface = nullptr;
    Scaleform::GFx::Value::ValueType type = Scaleform::GFx::Value::VT_Undefined;
    void* data;
    unsigned long long dataAux;
    Scaleform::GFx::Value* AsValue() { return reinterpret_cast<Scaleform::GFx::Value*>(this); }
    bool IsManaged() const { return (type & Scaleform::GFx::Value::VTC_ManagedBit) != 0; }
    ~Ime01KeptValue()
    {
        if (IsManaged()) {
            reinterpret_cast<void(*)(void*, void*, void*)>((*reinterpret_cast<void***>(objectInterface))[2])(
                objectInterface, this, data);
            objectInterface = nullptr;
        }
        type = Scaleform::GFx::Value::VT_Undefined;
        _ReadWriteBarrier();
    }
};

// An ArrayDataBase<GFx::Value> the exe declares and never fills; only its DestructArray(0, 0) call is left.
struct Ime01UnusedValueArray
{
    Scaleform::GFx::Value* data = nullptr;
    unsigned long long size = 0;
    ~Ime01UnusedValueArray() { FUN_1423ce6c0(data, size); }
};

// MS2-FUNCTIONAL: fills the +0x828 argument Values from the descriptors and invokes "<name>.Add" with them. The result
// Value is an Ime01KeptValue so its two dead zero stores stay, as in the exe. Left: the exe loads the by-value Ptr for
// its release before the Type store and enters the shared release test from the flag-zero exit with its own load.
// @0x1423d99f0
void FUN_1423d99f0(void* raw, Ime01NtsPtr value)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (*reinterpret_cast<unsigned char*>(self + 0x10)) {
        if (!value.p) return;

        // The command goes in the member buffer at +0x410; the descriptor and argument arrays are the
        // pointers stored at +0x828/+0x810, and .Add gets the descriptors with the count at +0x830 (0x1423d9ac3).
        char* command = reinterpret_cast<char*>(self + 0x410);
        strcpy_s(command, 0x400, reinterpret_cast<const char*>(self + 0x10));
        strcat_s(command, 0x400, ".Add");
        for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x818); ++i) {
            void* input = value.p;
            reinterpret_cast<void(*)(void*, void*, void*)>((*reinterpret_cast<void***>(input))[1])(input,
                &(*reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828))[i],
                &(*reinterpret_cast<void***>(self + 0x810))[i]);
        }
        Ime01KeptValue result;
        Ime01UnusedValueArray unused;
        void* movie = *reinterpret_cast<void**>(self + 0x868);
        void* manager = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0xa8);
        void* bridge = *reinterpret_cast<void**>(static_cast<unsigned char*>(manager) + 0x18);
        if (bridge)
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, const Scaleform::GFx::Value*, unsigned)>(
                (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(bridge, command, result.AsValue(),
                    *reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828), *reinterpret_cast<unsigned*>(self + 0x830));
        command[0] = 0;
    }
}

// @0x1423cefe0
void FUN_1423cefe0(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    // Two Values the exe constructs on entry and never uses.
    Scaleform::GFx::Value unused0;
    Scaleform::GFx::Value unused1;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(bytes + 0x28));
    cx18_ImmNotifyIME(context, 0x15, 1, 0);
    cx18_ImmNotifyIME(context, 0x15, 4, 0);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(bytes + 0x28), context);
    FUN_1423da320(*reinterpret_cast<void**>(bytes + 0xc8));
    if (*reinterpret_cast<unsigned*>(bytes + 0x98) - 5u <= 1u) {
        INPUT inputs[2];
        memset(inputs, 0, sizeof(inputs));
        // The exe sends each key separately with cbSize = sizeof(inputs) (0x50), which SendInput rejects, so no
        // Escape actually reaches the window.
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_ESCAPE;
        inputs[0].ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        SendInput(1, &inputs[0], sizeof(inputs));
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = VK_ESCAPE;
        inputs[1].ki.wScan = static_cast<WORD>(MapVirtualKeyW(VK_ESCAPE, 0));
        inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &inputs[1], sizeof(inputs));
    }
    **reinterpret_cast<unsigned short**>(bytes + 0x40) = 0;
    void* movie = *reinterpret_cast<void**>(bytes + 0xa8);
    {
        Scaleform::GFx::Value result;
        if (void* values = *reinterpret_cast<void**>(static_cast<unsigned char*>(movie) + 0x18)) {
            reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, unsigned, unsigned)>(
                (*reinterpret_cast<void***>(values))[0x78 / sizeof(void*)])(
                    values, "RemoveList", &result, 0, 0);
        }
    }
}

// Resets the IME manager's four predefined mode records (conversion mode, language) with the SDK array Clear and
// PushBack (Reserve FUN_1423cc720). The record's padding word is copied as is, as in the exe.
// MS2-FUNCTIONAL: cl keeps the capacity in a register across the Clear; the exe reloads it at the first PushBack
// @0x1423cb760
void FUN_1423cb760(void* object)
{
    struct ModeRecord { unsigned conversion; unsigned long long language; };
    typedef ArrayData<Ime01Pod<0x10>, AllocatorGH_POD<Ime01Pod<0x10>>, ArrayDefaultPolicy> RecordArray;
    auto& records = *reinterpret_cast<RecordArray*>(static_cast<unsigned char*>(object) + 0x170);
    records.Resize(0);
    ModeRecord record;
    record.conversion = 0x2000;
    record.language = 0x412;
    records.PushBack(*reinterpret_cast<const Ime01Pod<0x10>*>(&record));
    record.conversion = 0x210000;
    record.language = 0x804;
    records.PushBack(*reinterpret_cast<const Ime01Pod<0x10>*>(&record));
    record.conversion = 0x400;
    record.language = 0x411;
    records.PushBack(*reinterpret_cast<const Ime01Pod<0x10>*>(&record));
    record.conversion = 0x9;
    record.language = 0x404;
    records.PushBack(*reinterpret_cast<const Ime01Pod<0x10>*>(&record));
}

// Initializes the shared IME manager state, interns its embedded node, and installs the default conversion records.
// @0x1423cabb0
__declspec(noinline) unsigned long long* FUN_1423cabb0(unsigned long long* self, unsigned long long owner)
{
    self[0] = reinterpret_cast<unsigned long long>(DAT_143138360);
    self[1] = 0; self[2] = 0; self[3] = 0; self[4] = 0; self[5] = 0; self[6] = 0; self[7] = 0;
    self[8] = 0; self[9] = 0; self[0x0a] = 0; self[0x0b] = 0; self[0x0c] = 0; self[0x0d] = 0;
    new (self + 0x0e) Scaleform::String();
    self[0x0f] = owner;
    self[0x12] = 0;
    self[0x13] = 0;
    self[0x14] = 0;
    self[0x17] = 0;
    self[0x18] = 0;
    self[0x19] = 0;
    // Two embedded 0x38-byte records at +0xd8 and +0x118: tail cleared, flags word 0x01000000, head cleared.
    unsigned long long* const first = self + 0x1b;
    first[4] = 0;
    first[5] = 0;
    first[6] = 0;
    *reinterpret_cast<unsigned*>(first + 2) = 0x01000000;
    first[0] = 0;
    unsigned long long* const second = self + 0x23;
    second[4] = 0;
    second[5] = 0;
    second[6] = 0;
    *reinterpret_cast<unsigned*>(second + 2) = 0x01000000;
    second[0] = 0;
    self[0x2b] = 0;
    self[0x2c] = 0;
    self[0x2d] = 0;
    self[0x2e] = 0;
    self[0x2f] = 0;
    self[0x30] = 0;
    auto* node = reinterpret_cast<Scaleform::GFx::XML::DOMStringNode*>(first);
    self[0x22] = reinterpret_cast<unsigned long long>(second);
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0x84) = 0x02000000;
    *reinterpret_cast<unsigned*>(self + 0x11) = 0x02000000;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0xd4) = 0xffffffffu;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(self) + 0xfc) = 0;
    FUN_1423ca950(reinterpret_cast<Scaleform::GFx::XML::XMLDOMStringNodeHash*>(self + 1),
        self + 1, &node);
    *reinterpret_cast<unsigned*>(self + 0x1a) = 0;
    *reinterpret_cast<unsigned*>(self + 0x10) = 0;
    FUN_1423cb760(self);
    return self;
}

// Removes every enumerated command key from the executable's chained 0x28-byte hash table.
// @0x1423d8f20
void FUN_1423d8f20(unsigned long long* map, void* source)
{
    void** sourceVtable = *reinterpret_cast<void***>(source);
    auto* record = reinterpret_cast<Ime01CmdRecord*(*)(void*)>(sourceVtable[0])(source);
    while (record->Name) {
        reinterpret_cast<Ime01CmdMap*>(map)->Remove(Ime01CmdKey(record->Name));
        ++record;
    }
}

static __forceinline void Ime01AddModeName(void* list, const Scaleform::String& name)
{
    // PushBack takes the name as const String&; the exe passes it a temporary copy.
    static_cast<Ime01StringArray*>(list)->PushBack(Scaleform::String(name));
}

// Stores a copy of the supplied 0x58-byte IME value in every layout entry whose language name and mode match, and
// adds the entry's name to each affected mode list (the exe neither checks the language nor the allocation).
// MS2-FUNCTIONAL: the exe loads the layout array into rcx (ours rax) for the name compare and swaps base/index on
// the first id read (3 instructions).
// @0x1423d5b00
void FUN_1423d5b00(unsigned long long* manager, const unsigned long long* value, const char* language)
{
    struct ValueBlock { unsigned long long q[11]; };
    struct LayoutEntry { unsigned long long pad0[2]; Scaleform::String name; unsigned long long pad1; unsigned id; unsigned pad2;
        ValueBlock* value; };
    auto** vtable = reinterpret_cast<void**>(manager[0]);
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned short)>(vtable[4])(
        manager, *reinterpret_cast<const unsigned short*>(reinterpret_cast<const unsigned char*>(value) + 4));
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(manager + 0x1a); ++i) {
        if (Scaleform::SFstricmp(reinterpret_cast<LayoutEntry*>(manager[0x17])[i].name.ToCStr(), language) != 0) continue;
        if (mode != reinterpret_cast<unsigned(*)(void*, unsigned)>((*reinterpret_cast<void***>(manager))[3])(
                manager, reinterpret_cast<LayoutEntry*>(manager[0x17])[i].id)) continue;
        auto* copied = static_cast<ValueBlock*>(Scaleform::Memory::Alloc(0x58));
        *copied = *reinterpret_cast<const ValueBlock*>(value);
        reinterpret_cast<LayoutEntry*>(manager[0x17])[i].value = copied;
        reinterpret_cast<unsigned*>(manager[0x32])[i] = 1;
        if (*reinterpret_cast<unsigned char*>(&copied->q[10]) & 1) {
            *reinterpret_cast<unsigned*>(manager + 0x11) = reinterpret_cast<LayoutEntry*>(manager[0x17])[i].id;
            *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(manager) + 0x84) = mode;
        }
        if (mode & 0xf00) Ime01AddModeName(manager + 2, reinterpret_cast<LayoutEntry*>(manager[0x17])[i].name);
        if (mode & 0xf000) Ime01AddModeName(manager + 5, reinterpret_cast<LayoutEntry*>(manager[0x17])[i].name);
        if (mode & 0xf0000) Ime01AddModeName(manager + 8, reinterpret_cast<LayoutEntry*>(manager[0x17])[i].name);
        if (mode & 0xf) Ime01AddModeName(manager + 0xb, reinterpret_cast<LayoutEntry*>(manager[0x17])[i].name);
    }
}

struct Ime01ModeRecord {
    char* text;
    unsigned long long reserved0;
    unsigned mode;
    unsigned reserved1;
    unsigned long long language;
};
static __forceinline void Ime01PushModeRecord(unsigned long long* array, const Ime01ModeRecord& record)
{
    const unsigned long long size = array[1];
    const unsigned long long newSize = size + 1;
    if (newSize < size) {
        if (newSize < (array[2] >> 1)) FUN_1423d7370(array, array, newSize);
    } else if (newSize >= array[2])
        FUN_1423d7370(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
    reinterpret_cast<Ime01ModeRecord*>(array[0])[newSize - 1] = record;
}

// MS2-FUNCTIONAL: appends a wide composition update to the manager's UTF-8 log and records its language/mode tuple.
// Code is exe-identical except the frame: the exe keeps the record below the two String temporaries.
// @0x1423d5d80
void FUN_1423d5d80(void* raw, const void* event, const wchar_t* text)
{
    auto* bytes = static_cast<unsigned char*>(raw);
    Scaleform::String converted(text);
    char buffer[0x400];
    strcpy_s(buffer, 0x400, converted.ToCStr());
    const unsigned short language = *reinterpret_cast<const unsigned short*>(
        static_cast<const unsigned char*>(event) + 4);
    unsigned mode = 0x01000000;
    if ((language & 0xfff) == 0x409) mode = 0x10000000;
    else if ((language & 0xfff) == 0x404) mode = 9;
    else if ((language & 0xfff) == 0x804) mode = 0x80000;
    else if ((language & 0xfff) == 0x412) mode = 0x2000;
    else if ((language & 0xfff) == 0x411) mode = 0x400;
    Ime01ModeRecord record;
    record.language = language;
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    record.mode = mode;
    record.text = static_cast<char*>(Scaleform::Memory::Alloc(converted.GetSize() + 1));
    std::memcpy(record.text, buffer, converted.GetSize() + 1);
    Ime01PushModeRecord(reinterpret_cast<unsigned long long*>(bytes + 0x90), record);

    *reinterpret_cast<Scaleform::String*>(bytes + 0x70) += Scaleform::String(text) + "@@";
    *reinterpret_cast<unsigned*>(bytes + 0x80) += 1;
}

// Records the alternate IME composition message, whose language identifier is at +0x10 of the event, and copies
// the text straight from the converted string.
// @0x1423d7bc0
void FUN_1423d7bc0(void* raw, const void* event, const wchar_t* text)
{
    auto* bytes = static_cast<unsigned char*>(raw);
    Scaleform::String converted(text);
    const unsigned short language = *reinterpret_cast<const unsigned short*>(
        static_cast<const unsigned char*>(event) + 0x10);
    unsigned mode = 0x01000000;
    if ((language & 0xfff) == 0x409) mode = 0x10000000;
    else if ((language & 0xfff) == 0x404) mode = 9;
    else if ((language & 0xfff) == 0x804) mode = 0x80000;
    else if ((language & 0xfff) == 0x412) mode = 0x2000;
    else if ((language & 0xfff) == 0x411) mode = 0x400;
    Ime01ModeRecord record;
    record.language = language;
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    record.mode = mode;
    record.text = static_cast<char*>(Scaleform::Memory::Alloc(converted.GetSize() + 1));
    std::memcpy(record.text, converted.ToCStr(), converted.GetSize() + 1);
    Ime01PushModeRecord(reinterpret_cast<unsigned long long*>(bytes + 0x90), record);

    *reinterpret_cast<Scaleform::String*>(bytes + 0x70) += Scaleform::String(text) + "@@";
    *reinterpret_cast<unsigned*>(bytes + 0x80) += 1;
}

static __forceinline void Ime01StatusWindowCommand(void* raw, const char* command, const char* value);

// Applies the StatusWindow shape, symbol and Japanese input-mode commands through IMM32. FUN_1423d61f0 is an
// identical copy.
// @0x1423d7e80
void FUN_1423d7e80(void* raw, const char* command, const char* value)
{
    Ime01StatusWindowCommand(raw, command, value);
}

static __forceinline void Ime01StatusWindowCommand(void* raw, const char* command, const char* value)
{
    auto* manager = static_cast<unsigned char*>(raw);
    HIMC context = ImmGetContext(*reinterpret_cast<HWND*>(*reinterpret_cast<unsigned char**>(manager + 0x78) + 0x68));
    DWORD conversion;
    DWORD sentence;
    ImmGetConversionStatus(context, &conversion, &sentence);
    if (!context) return;
    // "false" clears the flag, "true" sets it; any other value leaves it alone.
    if (std::strcmp(command, "StatusWindow_OnShape") == 0) {
        if (std::strcmp(value, "false") == 0) conversion &= ~8u;
        if (std::strcmp(value, "true") == 0) conversion |= 8u;
    } else if (std::strcmp(command, "StatusWindow_OnInputMode") == 0) {
        if (std::strcmp(value, "false") == 0) conversion &= ~1u;
        if (std::strcmp(value, "true") == 0) conversion |= 1u;
        if (std::strcmp(value, "Hiragana") == 0) {
            if (!ImmGetOpenStatus(context)) ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~2u) | 1u;
        }
        if (std::strcmp(value, "Full-Width Katakana") == 0) {
            if (!ImmGetOpenStatus(context)) ImmSetOpenStatus(context, TRUE);
            conversion |= 0xbu;
        }
        if (std::strcmp(value, "Full-Width Alphanumeric") == 0) {
            if (!ImmGetOpenStatus(context)) ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~1u) | 8u;
        }
        if (std::strcmp(value, "Half-Width Katakana") == 0) {
            if (!ImmGetOpenStatus(context)) ImmSetOpenStatus(context, TRUE);
            conversion = (conversion & ~8u) | 3u;
        }
        if (std::strcmp(value, "Half-Width Alphanumeric") == 0) {
            if (!ImmGetOpenStatus(context)) ImmSetOpenStatus(context, TRUE);
            conversion &= ~9u;
        }
        if (std::strcmp(value, "DirectInput") == 0 && ImmGetOpenStatus(context))
            ImmSetOpenStatus(context, FALSE);
    } else if (std::strcmp(command, "StatusWindow_OnSymbol") == 0) {
        if (std::strcmp(value, "false") == 0) conversion &= ~0x400u;
        if (std::strcmp(value, "true") == 0) conversion |= 0x400u;
    }
    ImmSetConversionStatus(context, conversion, sentence);
    ImmReleaseContext(*reinterpret_cast<HWND*>(*reinterpret_cast<unsigned char**>(manager + 0x78) + 0x68), context);
}

struct Ime01ImeRecord { const char* name; void* reserved[2]; HKL layout; };

static __forceinline const Ime01ImeRecord& Ime01ImeAt(unsigned char* manager, unsigned long long index)
{
    return (*reinterpret_cast<Ime01ImeRecord**>(manager + 0x90))[index];
}

// Selects a registered IME through its COM provider and logs the executable's failure cases. The name and log pointers are not NULL-checked, as in the exe.
// @0x1423d5910
void FUN_1423d5910(void* raw, const char* requested)
{
    auto* manager = static_cast<unsigned char*>(raw);
    if (!*reinterpret_cast<void**>(manager + 0x78)) return;
    int found = -1;
    const unsigned count = *reinterpret_cast<unsigned*>(manager + 0x80);
    for (unsigned i = 0; i < count; ++i) {
        const Ime01ImeRecord& record = Ime01ImeAt(manager, i);
        if (std::strcmp(record.name, requested) == 0 && record.layout) {
            found = static_cast<int>(i);
            break;
        }
    }
    if (found == -1) {
        // The exe logs through FUN_1423cd060 (log vtable slot 1), the second line as one String.
        FUN_1423cd060(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager + 0x78) + 0x60),
            "\nCould not find requested IME in supported IME list!");
        FUN_1423cd060(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager + 0x78) + 0x60),
            (Scaleform::String("\n--> You requested: ") + requested).ToCStr());
        return;
    }
    void* provider;
    HRESULT hr = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068), &provider);
    if (hr == CO_E_NOTINITIALIZED) {
        FUN_1423cd060(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager + 0x78) + 0x60),
            Scaleform::String("\n Failure in COM, perhaps you called CoCreateInstance in another thread... ").ToCStr());
        return;
    }
    if (FAILED(hr) || !provider) return;
    reinterpret_cast<void(*)(void*, unsigned short)>((*reinterpret_cast<void***>(provider))[14])(
        provider, LOWORD(Ime01ImeAt(manager, found).layout));
    reinterpret_cast<ULONG(*)(void*)>((*reinterpret_cast<void***>(provider))[2])(provider);
}

// The exe's own copy of FUN_1423d7e80 (StatusWindow mode updates through IMM32).
// @0x1423d61f0
void FUN_1423d61f0(void* raw, const char* command, const char* value)
{
    Ime01StatusWindowCommand(raw, command, value);
}

// WM_IME_STARTCOMPOSITION of the IMM IME object (vtbl 0x14313a5f8; the Vista twin is 0x1423d05a0). Starts the
// composition, resets the candidate counters (+0xcc/+0x64/+0xd4), the target clause (+0x5a4), the reading text (+0x40)
// and the four-space mode buffer (+0xb0), stores the layout and its at-caret flag (+0x5a0, forced by the modes), and
// moves the IMM composition and candidate windows off screen, or for mode 0x1000000 to the cursor rect the owner
// (vtbl+0x190) maps. Nonzero (int) unless mode 0x1000000. The exe keeps an unused GFx::Value local, and the
// mapped rect is an uninitialised POD slot.
// @0x1423d43b0
int FUN_1423d43b0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner) return 0;
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(owner + 0x10)->GetIMEManager();
    ime->StartComposition();
    *reinterpret_cast<unsigned*>(self + 0xcc) = 0;
    *reinterpret_cast<unsigned*>(self + 0x64) = 0;
    *reinterpret_cast<unsigned*>(self + 0xd4) = 0;
    Scaleform::GFx::Value unused;
    *reinterpret_cast<unsigned*>(self + 0x5a4) = 1;
    std::memset(*reinterpret_cast<void**>(self + 0x40), 0, 0x100);
    (*reinterpret_cast<wchar_t**>(self + 0xb0))[0] = L' ';
    (*reinterpret_cast<wchar_t**>(self + 0xb0))[1] = L' ';
    (*reinterpret_cast<wchar_t**>(self + 0xb0))[2] = L' ';
    (*reinterpret_cast<wchar_t**>(self + 0xb0))[3] = L' ';
    (*reinterpret_cast<wchar_t**>(self + 0xb0))[4] = 0;
    *reinterpret_cast<HKL*>(self + 0x58) = GetKeyboardLayout(0);
    *reinterpret_cast<unsigned*>(self + 0x5a0) =
        cx18_ImmGetProperty(*reinterpret_cast<HKL*>(self + 0x58), IGP_PROPERTY) >> 0x12 & 1;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0xd00001) *reinterpret_cast<unsigned*>(self + 0x5a0) = 0;
    else if (mode == 0xa10000 || mode == 0xb10000 || mode == 6) *reinterpret_cast<unsigned*>(self + 0x5a0) = 1;

    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    POINT position = { -1000, -1000 };
    COMPOSITIONFORM composition;
    CANDIDATEFORM candidate;
    candidate.ptCurrentPos = position;
    composition.ptCurrentPos = position;
    candidate.dwIndex = 0;
    candidate.dwStyle = CFS_CANDIDATEPOS;
    composition.dwStyle = CFS_FORCE_POSITION;
    if (*reinterpret_cast<unsigned*>(self + 0x98) == 0x1000000 && *reinterpret_cast<unsigned char**>(self + 8)) {
        auto* movie = *reinterpret_cast<unsigned char**>(self + 8);
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> metrics =
            reinterpret_cast<Scaleform::GFx::StateBag*>(movie + 0x10)->GetIMEManager();
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        if (metrics) {
            metrics->GetMetrics(&viewRect, &cursorRect, 0);
            auto* current = *reinterpret_cast<unsigned char**>(self + 8);
            struct alignas(16) RawRect { float x1, y1, x2, y2; } mapped;  // uninitialised RectF out slot
            const auto* screen = reinterpret_cast<const Scaleform::Render::RectF*(*)(
                void*, Scaleform::Render::RectF*, const Scaleform::Render::RectF*, int)>(
                    (*reinterpret_cast<void***>(current))[0x190 / sizeof(void*)])(current, reinterpret_cast<Scaleform::Render::RectF*>(&mapped), &cursorRect, 0);
            position.x = static_cast<LONG>(screen->x1);
            position.y = static_cast<LONG>(screen->y2);
        }
        WINDOWINFO info;
        GetWindowInfo(*reinterpret_cast<HWND*>(self + 0x28), &info);
        candidate.ptCurrentPos = position;
        composition.ptCurrentPos = position;
    }
    cx18_ImmSetCompositionWindow(context, &composition);
    cx18_ImmSetCandidateWindow(context, &candidate);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    return *reinterpret_cast<unsigned*>(self + 0x98) != 0x1000000;
}

// WM_IME_STARTCOMPOSITION of the Vista IME object (vtbl 0x14313a450 slot 11; the XP twin is
// 0x1423d43b0, whose +0x5a0/+0x5a4 fields lie past this 0xe8-byte object). Starts the composition, stores the
// layout and its at-caret flag (+0xdc, forced by the modes), and moves the IMM composition and candidate windows
// off screen, or for mode 0x1000000 to the cursor rect the owner (vtbl+0x190) maps. Returns 1 unless mode 0x1000000
// (an int: the exe holds 0 in r14 from the at-caret store to the final setne r14b).
// @0x1423d05a0
int FUN_1423d05a0(void* raw)
{
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(*reinterpret_cast<unsigned char**>(self + 8) + 0x10)->GetIMEManager();
    self[0xb8] = 1;
    ime->StartComposition();
    self[0xb8] = 1;
    *reinterpret_cast<HKL*>(self + 0x58) = GetKeyboardLayout(0);
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    *reinterpret_cast<unsigned*>(self + 0xdc) =
        cx18_ImmGetProperty(*reinterpret_cast<HKL*>(self + 0x58), IGP_PROPERTY) >> 0x12 & 1;
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0xd00001 || mode == 5) *reinterpret_cast<unsigned*>(self + 0xdc) = 0;
    if (mode == 0xa10000 || mode == 0xb10000) *reinterpret_cast<unsigned*>(self + 0xdc) = 1;
    POINT position = { -1000, -1000 };
    CANDIDATEFORM candidate;
    COMPOSITIONFORM composition;
    candidate.ptCurrentPos = position;
    composition.ptCurrentPos = position;
    candidate.dwIndex = 0;
    candidate.dwStyle = CFS_CANDIDATEPOS;
    composition.dwStyle = CFS_FORCE_POSITION;
    if (mode == 0x1000000 && *reinterpret_cast<unsigned char**>(self + 8)) {
        auto* movie = *reinterpret_cast<unsigned char**>(self + 8);
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> metrics =
            reinterpret_cast<Scaleform::GFx::StateBag*>(movie + 0x10)->GetIMEManager();
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        if (metrics) {
            metrics->GetMetrics(&viewRect, &cursorRect, 0);
            auto* current = *reinterpret_cast<unsigned char**>(self + 8);
            struct alignas(16) RawRect { float x1, y1, x2, y2; } mapped;  // uninitialised RectF out slot
            const auto* screen = reinterpret_cast<const Scaleform::Render::RectF*(*)(
                void*, Scaleform::Render::RectF*, const Scaleform::Render::RectF*, int)>(
                    (*reinterpret_cast<void***>(current))[0x190 / sizeof(void*)])(current, reinterpret_cast<Scaleform::Render::RectF*>(&mapped), &cursorRect, 0);
            position.x = static_cast<LONG>(screen->x1);
            position.y = static_cast<LONG>(screen->y2);
        }
        candidate.ptCurrentPos = position;
        composition.ptCurrentPos = position;
    }
    cx18_ImmSetCompositionWindow(context, &composition);
    cx18_ImmSetCandidateWindow(context, &candidate);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    return *reinterpret_cast<unsigned*>(self + 0x98) != 0x1000000;
}

// MS2-FUNCTIONAL: handles the executable's disable, selection, numeric index, and comma/colon list-change events.
// Still differs: the exe loads value into r15 at entry and walks the list with a pointer.
// @0x1423d9ee0
bool FUN_1423d9ee0(void* raw, void*, int event, void*, const char* value)
{
    typedef ArrayData<String, AllocatorLH<String, 2>, ArrayDefaultPolicy> StringArray;
    struct ValueArray { Value* Data; UPInt Size; UPInt Capacity; };
    auto* self = static_cast<unsigned char*>(raw);
    switch (event) {
    case 0xf1:
        self[0x10] = 0;
        return true;
    case 0xf2:
        *reinterpret_cast<long long*>(self + 0x840) = std::atoi(value);
        FUN_1423d9b40(self);
        return true;
    case 0xf6:
        *reinterpret_cast<long long*>(self + 0x860) = std::atoi(value);
        return true;
    case 0xf3: {
        auto* strings = reinterpret_cast<StringArray*>(self + 0x810);
        auto* items = reinterpret_cast<ValueArray*>(self + 0x828);
        strings->Resize(0);
        FUN_1423d9730(items, items, 0);
        int i = 0;
        int start = 0;
        if (*value) {
            for (;;) {
                do ++i; while (value[i] != ',' && value[i] != ':' && value[i] != '\0');
                const SPInt length = i - start;
                char* buffer = static_cast<char*>(std::malloc(length + 1));
                strncpy_s(buffer, length + 1, value + start, length);
                buffer[i - start] = '\0';
                {
                    String token(buffer);
                    strings->PushBack(token);
                }
                std::free(buffer);
                if (!value[i]) break;
                start = i + 1;
            }
        }
        const UPInt count = strings->Size;
        const UPInt oldCount = items->Size;
        FUN_1423d9730(items, items, count);
        if (count > oldCount)
            AllocatorGH<Value, 2>::ConstructArray(items->Data + oldCount, count - oldCount);
        return true;
    }
    }
    return false;
}

// MS2-FUNCTIONAL: maps a GFxIME_* label from the executable IME table to its loaded record and selects that IME,
// then releases the by-value name string (inline, as in the exe). Still differs: vtable[8] goes through r8 in the exe.
// @0x1423d7420
bool FUN_1423d7420(unsigned long long* manager, unsigned long long* packedName)
{
    struct LocaleRow { const char* name; unsigned id; unsigned pad; };
    struct Record { unsigned long long pad0[2]; unsigned long long text1; unsigned long long text2; unsigned id; unsigned pad1[3]; };
    struct Mode { const char* name; unsigned long long pad0; unsigned id; unsigned pad1[3]; };
    const auto* rows = reinterpret_cast<const LocaleRow*>(DAT_143a2a3e0);
    auto* self = reinterpret_cast<unsigned char*>(manager);
    unsigned index = 0;
    if (rows[0].id != 0x02000000) {
        do {
            const char* name = reinterpret_cast<const char*>((*packedName & ~3ull) + 0xc);
            if (std::strcmp(name, rows[index].name) == 0) {
                const unsigned code = rows[index].id;
                for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xd0); ++i) {
                    auto* records = reinterpret_cast<Record*>(manager[0x17]);
                    if (records[i].id != code) continue;
                    auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
                    if (states[i] == 1 || states[i] == 2) {
                        *reinterpret_cast<unsigned*>(self + 0x84) =
                            reinterpret_cast<unsigned(*)(void*, unsigned)>(reinterpret_cast<void**>(manager[0])[3])(manager, records[i].id);
                        for (unsigned mode = 0; mode < manager[0x13]; ++mode) {
                            auto* modes = reinterpret_cast<Mode*>(manager[0x12]);
                            if (modes[mode].id == *reinterpret_cast<unsigned*>(self + 0x84))
                                reinterpret_cast<void(*)(void*, const char*)>(reinterpret_cast<void**>(manager[0])[9])(manager, modes[mode].name);
                        }
                    }
                    const unsigned selected = reinterpret_cast<unsigned*>(manager[0x32])[i];
                    unsigned long long field;
                    if (selected == 1)
                        field = reinterpret_cast<Record*>(manager[0x17])[i].text1;
                    else if (selected == 2)
                        field = reinterpret_cast<Record*>(manager[0x17])[i].text2;
                    else
                        continue;
                    {
                        const char* text = reinterpret_cast<const char*>((field & ~3ull) + 0xc);
                        reinterpret_cast<void(*)(void*, const char*)>(reinterpret_cast<void**>(manager[0])[8])(manager, text);
                        unsigned char* data = reinterpret_cast<unsigned char*>(*packedName & ~3ull);
                        if ((_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(data + sizeof(void*)), -1) - 1) == 0)
                            Memory::Free(data);
                        return true;
                    }
                }
            }
            ++index;
        } while (rows[index].id != 0x02000000);
    }
    unsigned char* data = reinterpret_cast<unsigned char*>(*packedName & ~3ull);
    if ((_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(data + sizeof(void*)), -1) - 1) == 0)
        Memory::Free(data);
    return false;
}

// Initializes the IME command state, callback interface, string members, and both dynamic buffers.
// @0x1423cdbb0
void* FUN_1423cdbb0(unsigned long long* words, void* owner, void* userData)
{
    // base part (vtable 0x14313a258, the p20 member of the DAT_14313a238 piece)
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a238 + 4);
    words[1] = 0;
    new (words + 2) Scaleform::String();
    new (words + 3) Scaleform::String();
    new (words + 4) Scaleform::String();
    words[5] = reinterpret_cast<unsigned long long>(userData);
    words[7] = 0;
    words[8] = 0;
    words[9] = 0;
    words[10] = 0;
    new (words + 0xf) Scaleform::String();
    words[0x15] = reinterpret_cast<unsigned long long>(owner);
    auto* child = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x870));
    if (child) {
        FUN_1423d9430(child, words);
        child[0] = reinterpret_cast<unsigned long long>(DAT_14313a238);
    } else
        child = nullptr;
    words[6] = reinterpret_cast<unsigned long long>(child);
    FUN_1423d8e80(words + 7, child);
    reinterpret_cast<unsigned char*>(words)[0x80] = 1;

    // derived part
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a450);
    *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(words) + 0x84) = 0x14;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0x8c) = 0x00ffffff;
    new (words + 0x16) Scaleform::String();
    words[0xb] = 0;
    *reinterpret_cast<unsigned*>(words + 0xc) = 0;
    // the text buffer is resized to 0x100 wchar_ts and its first entry terminated
    reinterpret_cast<Ime01WideArrayLH*>(words + 8)->ResizeNoConstruct(words + 8, 0x100);
    *reinterpret_cast<wchar_t*>(words[8]) = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0x64) = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<unsigned char*>(words) + 0xdc) = 1;
    void* child2 = Scaleform::Memory::Alloc(0x110);
    child2 = child2 ? ::new (child2) Ime01TsfUiSink(reinterpret_cast<unsigned long long>(words),
        reinterpret_cast<unsigned long long>(userData)) : nullptr;
    words[0x19] = reinterpret_cast<unsigned long long>(child2);
    FUN_1423daae0(child2);
    return words;
}

// Appends the built-in IME name pairs and locale IDs to the manager's 0x30-byte records: an inlined
// ArrayData::PushBack of a temporary record (ResizeNoConstruct, then copy construction).
// @0x1423cc3d0
void FUN_1423cc3d0(void* raw)
{
    struct BuiltinIme { const char* name; const char* display; unsigned locale; const void* reserved; };
    struct Record {
        struct Unknown { unsigned long long low, high; Unknown() {} } unknown;
        Scaleform::String name;
        Scaleform::String display;
        unsigned locale;
        void* profiles;
        Record() : locale(0x2000000), profiles(nullptr) {}
    };
    auto* self = static_cast<unsigned char*>(raw);
    const auto* entries = reinterpret_cast<const BuiltinIme*>(DAT_143a293e0);
    for (int i = 0; i < DAT_143a2a6b4; ++i) {
        auto* array = reinterpret_cast<unsigned long long*>(self + 0xb8);
        Record record;
        record.display = entries[i].display;
        record.name = entries[i].name;
        record.locale = entries[i].locale;
        const unsigned long long size = array[1];
        const unsigned long long newSize = size + 1;
        if (newSize < size) {
            FUN_1423c9330(array[0] + newSize * sizeof(Record), size - newSize);
            if (newSize < (array[2] >> 1))
                reinterpret_cast<Ime01CueArr*>(array)->Reserve(array, newSize);
        } else if (newSize >= array[2])
            reinterpret_cast<Ime01CueArr*>(array)->Reserve(array, newSize + (newSize >> 2));
        array[1] = newSize;
        new (reinterpret_cast<Record*>(array[0]) + newSize - 1) Record(record);
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
    // base part (vtable 0x14313a258, as in FUN_1423cdbb0)
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a238 + 4);
    words[1] = 0;
    new (words + 2) Scaleform::String();
    new (words + 3) Scaleform::String();
    new (words + 4) Scaleform::String();
    words[5] = reinterpret_cast<unsigned long long>(userData);
    words[7] = 0;
    words[8] = 0;
    words[9] = 0;
    words[10] = 0;
    new (words + 0xf) Scaleform::String();
    words[0x15] = reinterpret_cast<unsigned long long>(owner);
    auto* child = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x870));
    if (child) {
        FUN_1423d9430(child, raw);
        child[0] = reinterpret_cast<unsigned long long>(DAT_14313a238);
    } else
        child = nullptr;
    words[6] = reinterpret_cast<unsigned long long>(child);
    FUN_1423d8e80(words + 7, child);
    // Left: the exe forms rdi = +0xb0 before the +0x80 store, and sets k = 0 before src in the key loop (scheduling)
    auto* text = reinterpret_cast<Ime01TextArrayLH*>(words + 0x16);
    bytes[0x80] = 1;

    // derived part
    *reinterpret_cast<unsigned long long*>(bytes + 0x84) = 0x14;
    words[0] = reinterpret_cast<unsigned long long>(DAT_14313a5f8);
    *reinterpret_cast<unsigned*>(bytes + 0x8c) = 0x00ffffff;
    ::new (static_cast<void*>(text)) ArrayLH_POD<wchar_t, 2>();
    words[0xb] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xd4) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x60) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 0xa0) = 0;
    words[0xb6] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x5a0) = 1;
    bytes[0x5bc] = 0;
    // both text buffers are resized to 0x100 wchar_ts, +0xb0 first; the buffers are not cleared
    text->ResizeNoConstruct(text, 0x100);
    reinterpret_cast<Ime01WideArrayLH*>(words + 8)->ResizeNoConstruct(words + 8, 0x100);

    // the key -> {key, bopomofo, class} records at +0xd8, indexed by tolower(key) - 0x20
    auto* keyTable = reinterpret_cast<unsigned (*)[3]>(raw);
    for (long long i = 0; i < 41; ++i) {
        const unsigned* rec = cx18_ZhuyinKeys[i];
        long long k = 0;
        for (const unsigned* src = rec; k < 3; ++k) {
            const int index = tolower(static_cast<signed char>(rec[0])) - 0x20;
            keyTable[index + 0x12LL][k] = *src++;
        }
    }
    return raw;
}

// An empty local Value array (never filled; its destructor still runs).
struct Ime01ArgArrayEmpty
{
    Scaleform::GFx::Value* data;
    unsigned long long size;
    unsigned long long capacity;
    Ime01ArgArrayEmpty() : data(nullptr), size(0), capacity(0) {}
    ~Ime01ArgArrayEmpty()
    {
        FUN_1423ce6c0(data, size);
        if (data) Memory::Free(data);
    }
};

// Rebuilds the AS3 status list by clearing it, replaying retained row callbacks, and restoring selection.
// The SelectDataItem argument goes through a local Value array (FUN_1423d9730), and each Add call has an empty one, as
// in the exe. The added Value is an Ime01KeptValue (its reset stores stay before the row release).
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

    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".ClearList");
    Scaleform::GFx::Value result;
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, nullptr, 0);
    command[0] = 0;

    // SelectDataItem goes out before the rows are added (0x1423d9bea), SetList after them.
    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".SelectDataItem");
    Ime01ValueArgs args;
    {
        Scaleform::GFx::Value argument(static_cast<double>(*reinterpret_cast<long long*>(self + 0x860)));
        FUN_1423d9730(&args, &args, 1);
        ::new (static_cast<void*>(args.data + args.size - 1)) Scaleform::GFx::Value(argument);
    }
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, args.data, 1);

    for (unsigned row = 0; row < *reinterpret_cast<unsigned long long*>(self + 0x850); ++row) {
        auto* rows = *reinterpret_cast<void***>(self + 0x848);
        if (rows[row]) ++*reinterpret_cast<int*>(static_cast<unsigned char*>(rows[row]) + 8);
        void* callback = rows[row];
        if (*prefix && callback) {
            strcpy_s(command, 0x400, prefix);
            strcat_s(command, 0x400, ".Add");
            for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x818); ++i)
                reinterpret_cast<void(*)(void*, void*, void*)>((*reinterpret_cast<void***>(callback))[1])(callback,
                    *reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828) + i,
                    *reinterpret_cast<void***>(self + 0x810) + i);
            {
                Ime01KeptValue added;
                Ime01ArgArrayEmpty unused;
                if (void* bridge = bridgeOf())
                    invoke(bridge, command, added.AsValue(),
                        *reinterpret_cast<Scaleform::GFx::Value**>(self + 0x828),
                        *reinterpret_cast<unsigned*>(self + 0x830));
                command[0] = 0;
            }
            FUN_14257dcd0(callback);
        }
        else if (callback) FUN_14257dcd0(callback);
    }

    strcpy_s(command, 0x400, prefix);
    strcat_s(command, 0x400, ".SetList");
    if (void* bridge = bridgeOf()) invoke(bridge, command, &result, nullptr, 0);
    command[0] = 0;
}

// Candidate list refresh: reads IMM candidate list listIndex, stores its count (+0xd8) and page start (+0x70), and
// replaces the rows of the list object (+0x30) with its UTF-8 entries from the page start to the end, stopping at an
// offset outside the fetched block. The selection is max(dwSelection - dwPageStart, 0) for the candidate modes, else -1.
// @0x1423cf900
void FUN_1423cf900(void* raw, DWORD listIndex)
{
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* candidates = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(bytes * sizeof(CANDIDATELIST)));
    const DWORD fetched = cx18_ImmGetCandidateListW(context, listIndex, candidates, bytes);
    *reinterpret_cast<DWORD*>(self + 0xd8) = candidates->dwCount;
    const DWORD selection = candidates->dwSelection;
    *reinterpret_cast<DWORD*>(self + 0x70) = candidates->dwPageStart;
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    if (*reinterpret_cast<DWORD*>(self + 0xd8) == 0) {
        Scaleform::Memory::Free(candidates);
        return;
    }

    FUN_1423d9500(*reinterpret_cast<void**>(self + 0x30));
    for (int i = *reinterpret_cast<int*>(self + 0x70); i < *reinterpret_cast<int*>(self + 0xd8); ++i) {
        const DWORD offset = candidates->dwOffset[i];
        if (offset > fetched || offset < sizeof(CANDIDATELIST)) break;
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(reinterpret_cast<const unsigned char*>(candidates) + offset);
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(wide, -1));
        char* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size) + 1));
        Scaleform::UTF8Util::EncodeStringSafe(text, static_cast<Scaleform::UPInt>(size) + 1, wide, -1);
        text[size] = 0;
        void* memory = Scaleform::Memory::Alloc(0x20);
        auto* item = memory ? static_cast<unsigned long long*>(
            FUN_1423cdb60(static_cast<unsigned long long*>(memory), text)) : nullptr;
        if (item) ++*reinterpret_cast<int*>(item + 1);
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(*reinterpret_cast<void**>(self + 0x30), &retained, 0);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
    Scaleform::Memory::Free(candidates);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);

    long long selected = -1;
    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    if (state == 0x110000 || state == 0x210000 || state == 0xd00800 ||
        state == 0xd00900 || state == 0xd00a00 || state == 0xd10000) {
        const int relative = static_cast<int>(selection - *reinterpret_cast<DWORD*>(self + 0x70));
        selected = relative >= 0 ? relative : 0;
    }
    FUN_1423d97f0(*reinterpret_cast<void**>(self + 0x30), static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(*reinterpret_cast<void**>(self + 0x30));
    *reinterpret_cast<unsigned char*>(self + 0xb9) = 1;
}

// MS2-FUNCTIONAL: composition-text update. It reads GCS_COMPSTR, turns every space and U+3000 into U+00A0 and, by mode,
// clears the composition text, sends the text, or sends it, sets the cursor from GCS_CURSORPOS, stores
// length - cursor at +0x64 and highlights the whole text. Other modes change nothing. Reviewed case by case against
// the exe, same behaviour; the exe keeps the U+00A0 value and the counter in other registers (1 byte longer).
// @0x1423d2410
void FUN_1423d2410(void* raw, unsigned* outputLength)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::GFx::Value unused;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    const LONG size = cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, nullptr, 0);
    auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<SPInt>(size * 2)) + 2));
    cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, text, size);
    const int count = size / 2;
    text[count] = 0;
    wchar_t* cursor = text;
    for (int i = 0; i < count; ++i, ++cursor)
        if (*cursor == L' ' || *cursor == 0x3000) *cursor = 0x00a0;

    switch (*reinterpret_cast<int*>(self + 0x98)) {
    case 1: case 3: case 5: case 7:
    case 0x10000: case 0x20000: case 0x30000: case 0x60000: case 0xd00001:
        ime->SetCompositionText(L"", -1);
        *outputLength = 0;
        break;
    case 2: case 4: case 6: case 10:
    case 0x100: case 0x200: case 0x300: case 0x400: case 0x500:
    case 0x40000: case 0x70000: case 0x90000: case 0xa0000:
    case 0xd00002: case 0xd00800: case 0xd00900:
        ime->SetCompositionText(text, -1);
        *outputLength = static_cast<unsigned>(count);
        break;
    case 0x110000: case 0x210000: case 0x410000: case 0x810000: case 0x910000:
    case 0xc10000: case 0xd10000: {
        ime->SetCompositionText(text, -1);
        *outputLength = static_cast<unsigned>(count);
        const LONG cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
        ime->SetCursorInComposition(static_cast<UPInt>(cursor));
        *reinterpret_cast<unsigned*>(self + 0x64) = static_cast<unsigned>(count - cursor);
        ime->HighlightText(0, static_cast<UPInt>(count), Scaleform::GFx::IMEManagerBase::THS_CompositionSegment, false);
        break;
    }
    }
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    if (text) Scaleform::Memory::Free(text);
}

// The allocator of the local Value arrays: GH POD storage of 32-byte elements whose DestructArray is the out-of-line
// ConstructorMov<Value>::DestructArray (FUN_1423ce6c0).
struct Ime01ArgAlloc : AllocatorGH_POD<Ime01Pod<0x20>>
{
    static void DestructArray(Ime01Pod<0x20>* p, UPInt count)
    {
        FUN_1423ce6c0(reinterpret_cast<Scaleform::GFx::Value*>(p), count);
    }
};
// A local ArrayData<Value>: the SDK ArrayDataBase ctor/dtor (one movdqu for Data and Size, the capacity apart).
struct Ime01ArgArray
{
    ArrayData<Ime01Pod<0x20>, Ime01ArgAlloc, ArrayDefaultPolicy> array;
    Scaleform::GFx::Value* data() const { return reinterpret_cast<Scaleform::GFx::Value*>(array.Data); }
};
static inline void Ime01PushArg(Ime01ArgArray& args, const Scaleform::GFx::Value& value)
{
    auto& array = args.array;
    const unsigned long long oldLength = array.Size;
    const unsigned long long newLength = oldLength + 1;
    if (newLength < oldLength) {
        FUN_1423ce6c0(args.data() + newLength, oldLength - newLength);
        if (newLength < (array.Policy.GetCapacity() >> 1))
            reinterpret_cast<Ime01ArrayGH<0x20>*>(&array)->Reserve(&array, newLength);
    } else if (newLength >= array.Policy.GetCapacity()) {
        reinterpret_cast<Ime01ArrayGH<0x20>*>(&array)->Reserve(&array, (newLength >> 2) + newLength);
    }
    array.Size = newLength;
    ::new (static_cast<void*>(args.data() + newLength - 1)) Scaleform::GFx::Value(value);
}

// IMM candidate-list update of the Vista IME object (vtable slot 36). It stores the count at +0xd8, the page start at
// +0x70 and the page size at +0x6c, recreates the movie list with RemoveList() and CreateList(pageSize, +0xdc), and
// refills the manager's list at +0x30 with the entries from the page start to the end of the list as UTF-8. The
// selection is dwSelection % dwPageSize for the candidate modes, else -1. Like the exe, it releases the context once
// before the empty-list return and once more after the fill.
// @0x1423d0850
void FUN_1423d0850(void* raw, DWORD listIndex)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* candidates = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(bytes * sizeof(CANDIDATELIST)));
    const DWORD fetched = cx18_ImmGetCandidateListW(context, listIndex, candidates, bytes);
    *reinterpret_cast<DWORD*>(self + 0xd8) = candidates->dwCount;
    const DWORD selection = candidates->dwSelection;
    *reinterpret_cast<DWORD*>(self + 0x70) = candidates->dwPageStart;
    const DWORD pageSize = candidates->dwPageSize;
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    if (*reinterpret_cast<DWORD*>(self + 0xd8) == 0) {
        Scaleform::Memory::Free(candidates);
        return;
    }
    *reinterpret_cast<DWORD*>(self + 0x6c) = pageSize;
    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveList", &result, nullptr, 0);
        Ime01ArgArray args;
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(static_cast<int>(pageSize))));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(*reinterpret_cast<int*>(self + 0xdc))));
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "CreateList", &result, args.data(), 2);
    }

    FUN_1423d9500(*reinterpret_cast<void**>(self + 0x30));
    for (int i = *reinterpret_cast<int*>(self + 0x70); i < *reinterpret_cast<int*>(self + 0xd8); ++i) {
        const DWORD offset = candidates->dwOffset[i];
        if (offset > fetched || offset < sizeof(CANDIDATELIST)) break;
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(reinterpret_cast<const unsigned char*>(candidates) + offset);
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(wide, -1));
        char* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size) + 1));
        Scaleform::UTF8Util::EncodeStringSafe(text, static_cast<Scaleform::UPInt>(size) + 1, wide, -1);
        text[size] = 0;
        void* memory = Scaleform::Memory::Alloc(0x20);
        auto* item = memory ? static_cast<unsigned long long*>(
            FUN_1423cdb60(static_cast<unsigned long long*>(memory), text)) : nullptr;
        if (item) ++*reinterpret_cast<int*>(item + 1);
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(*reinterpret_cast<void**>(self + 0x30), &retained, 0);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
    Scaleform::Memory::Free(candidates);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);

    const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
    long long selected;
    if (state == 0x110000 || state == 0x210000 || state == 0xd00800 ||
        state == 0xd00900 || state == 0xd00a00 || state == 0xd10000)
        selected = static_cast<int>(selection) % static_cast<int>(pageSize);
    else
        selected = -1;
    FUN_1423d97f0(*reinterpret_cast<void**>(self + 0x30), static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(*reinterpret_cast<void**>(self + 0x30));
    *reinterpret_cast<unsigned char*>(self + 0xb9) = 1;
}

static void cx18_InvokeInputWindow(unsigned char* self, const char* name, Scaleform::GFx::Value* args, unsigned count);
void FUN_1423d5060(void* raw, int);

// Candidate list update of the IMM IME object (IMN_CHANGECANDIDATE). Reads IMM candidate list listIndex, stores its
// count (+0xcc), the page size (+0xd4, never shrinking) and the first visible row (+0x70: the page start, or the
// selection's page for the 0xf00 modes). An empty list calls RemoveList; otherwise the mode decides the visible rows
// (0x410000: up to five from the selection; 0x60000: from the selection; else one page), they replace the rows of
// the list object at +0x30, the selection is set (relative to the page in the paging modes, else -1) and +0x5bc
// marks the list shown. The exe inlines the row loop and the row item ctor (FUN_1423cdb60) and keeps an unused Value
// local.
// @0x1423d3120
void FUN_1423d3120(void* raw, DWORD listIndex)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    const DWORD bytes = cx18_ImmGetCandidateListW(context, listIndex, nullptr, 0);
    if (!bytes) return;
    auto* list = static_cast<LPCANDIDATELIST>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(bytes) * 0x1c));
    cx18_ImmGetCandidateListW(context, listIndex, list, bytes);
    *reinterpret_cast<DWORD*>(self + 0xcc) = list->dwCount;
    const int osPage = static_cast<int>(list->dwPageSize);
    const int selection = static_cast<int>(list->dwSelection);
    int page = *reinterpret_cast<int*>(self + 0xd4);
    page = page <= osPage ? osPage : page;
    *reinterpret_cast<int*>(self + 0xd4) = page;
    *reinterpret_cast<int*>(self + 0x70) = static_cast<int>(list->dwPageStart);
    if (*reinterpret_cast<unsigned*>(self + 0x98) & 0xf00) *reinterpret_cast<int*>(self + 0x70) = selection - selection % page;
    int& first = *reinterpret_cast<int*>(self + 0x70);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    int visible = *reinterpret_cast<int*>(self + 0xcc);
    if (!visible) {
        {
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveList", &result, nullptr, 0);
        }
        Scaleform::Memory::Free(list);
        return;
    }
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode == 0x410000) {
        if (visible > 5) {
            visible -= selection;
            if (visible > 5) visible = 5;
        }
        first = selection;
    } else if (mode == 0x40000) {
        const int rest = visible - first;
        visible = osPage;
        visible = osPage >= rest ? rest : osPage;
    } else if (mode == 0x60000) {
        const int rest = visible - selection;
        first = selection;
        visible = osPage >= rest ? rest : osPage;
    } else if (mode != 0xd00001 && visible >= osPage) {
        const int rest = visible - first;
        visible = osPage;
        if (rest <= osPage) visible = rest;
    }
    FUN_1423d9500(*reinterpret_cast<void**>(self + 0x30));
    for (int i = 0; i < visible; ++i) {
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(
            reinterpret_cast<const unsigned char*>(list) + list->dwOffset[first + i]);
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(wide, -1));
        auto* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size + 1)));
        Scaleform::UTF8Util::EncodeString(text, wide, -1);
        text[size] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            *reinterpret_cast<unsigned*>(item + 1) = 1;
            String* value = reinterpret_cast<String*>(item + 3);
            item[0] = reinterpret_cast<unsigned long long>(DAT_14313a228);
            new (value) String();
            *value = text;
            ++*reinterpret_cast<int*>(item + 1);
        } else
            item = nullptr;
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(*reinterpret_cast<void**>(self + 0x30), &retained, 0);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
    Scaleform::Memory::Free(list);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    const unsigned now = *reinterpret_cast<unsigned*>(self + 0x98);
    long long selected = -1;
    if ((now == 2 || now == 4 || now == 10) || (now & 0xf00) || now == 0x40000 || now == 0x70000 ||
        now == 0x110000 || now == 0x210000 || now == 0x410000 || now == 0xd10000) {
        const int inPage = selection - first;
        selected = inPage >= 0 ? inPage : 0;
    }
    FUN_1423d97f0(*reinterpret_cast<void**>(self + 0x30), static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(*reinterpret_cast<void**>(self + 0x30));
    self[0x5bc] = 1;
}

// Candidate list open of the IMM IME object (IMN_OPENCANDIDATE). Like 0x1423d3120, but the page size (+0xd4) is the
// list's own, mode 0x410000 shows at most five rows, the visible row count goes to +0x6c, the list window is rebuilt
// (RemoveList, then CreateList(page size, at-caret flag +0x5a0)) and the selection is its index within the page.
// An empty list does nothing.
// MS2-FUNCTIONAL: the input context is released a second time after the rows, as in the exe (kept). What is left:
// register allocation and frame slots (the list pointer's r12 spill, -1/5 in r13). Reviewed against the exe: same
// rows, page and CreateList arguments (int -> float -> double, as the exe converts them).
// @0x1423d46f0
void FUN_1423d46f0(void* raw, DWORD listIndex)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
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
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    int visible = *reinterpret_cast<int*>(self + 0xcc);
    if (!visible) {
        Scaleform::Memory::Free(list);
        return;
    }
    const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
    if (mode & 0xf00) first = selection - selection % *reinterpret_cast<int*>(self + 0xd4);
    if (mode == 0x410000) {
        page = 5;
        visible = visible > 5 ? 5 : visible;
    } else if (mode == 0x40000) {
        visible -= first;
        if (page < visible) visible = page;
    } else if (mode == 0x60000) {
        first = selection;
        visible -= first;
        if (page < visible) visible = page;
    } else if (mode != 0xd00001 && visible >= page) {
        const int rest = visible - first;
        visible = rest <= page ? rest : page;
    }
    *reinterpret_cast<int*>(self + 0x6c) = visible;
    {
        Scaleform::GFx::Value result;
        Ime01ArgArray args;
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(static_cast<float>(page))));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(static_cast<float>(*reinterpret_cast<int*>(self + 0x5a0)))));
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveList", &result, nullptr, 0);
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "CreateList", &result, args.data(), 2);
    }
    FUN_1423d9500(*reinterpret_cast<void**>(self + 0x30));
    for (int i = 0; i < visible; ++i) {
        const wchar_t* wide = reinterpret_cast<const wchar_t*>(
            reinterpret_cast<const unsigned char*>(list) + list->dwOffset[first + i]);
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(wide, -1));
        auto* text = static_cast<char*>(Scaleform::Memory::Alloc(static_cast<Scaleform::UPInt>(size + 1)));
        Scaleform::UTF8Util::EncodeString(text, wide, -1);
        text[size] = 0;
        auto* item = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(0x20));
        if (item) {
            *reinterpret_cast<unsigned*>(item + 1) = 1;
            String* value = reinterpret_cast<String*>(item + 3);
            item[0] = reinterpret_cast<unsigned long long>(DAT_14313a228);
            new (value) String();
            *value = text;
            ++*reinterpret_cast<int*>(item + 1);
        } else
            item = nullptr;
        unsigned long long retained = reinterpret_cast<unsigned long long>(item);
        FUN_1423d9490(*reinterpret_cast<void**>(self + 0x30), &retained, 0);
        Scaleform::Memory::Free(text);
        if (item) FUN_14257dcd0(item);
    }
    Scaleform::Memory::Free(list);
    cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    const unsigned now = *reinterpret_cast<unsigned*>(self + 0x98);
    long long selected = -1;
    if ((now == 2 || now == 4 || now == 10) || (now & 0xf00) || now == 0x40000 || now == 0x70000 ||
        now == 0x110000 || now == 0x210000 || now == 0x410000 || now == 0xd10000)
        selected = selection % *reinterpret_cast<int*>(self + 0xd4);
    FUN_1423d97f0(*reinterpret_cast<void**>(self + 0x30), static_cast<unsigned long long>(selected), 0);
    FUN_1423d9b40(*reinterpret_cast<void**>(self + 0x30));
    self[0x5bc] = 1;
}

// The records the exe reads for input mode 4 (Cangjie): entries[tolower(key) - 'a'].radical, 8-byte records at
// 0x14313a910 (radical at +4) holding the radicals for a..y and 'Z' for z. Keys 0x20..0x60 index below the
// array and read the bytes before it (0x14313a70c + 8 * (key - 0x20)), which `before` holds at the same offsets.
struct cx18_CangjieEntry { unsigned code; unsigned short radical; unsigned short pad; };
static const struct cx18_CangjieTable {
    unsigned short before[0x102];
    cx18_CangjieEntry entries[26];
} cx18_Cangjie = {
    {
        0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x3107, 0x0000, 0x0000, 0x0000, 0x0042, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x310f, 0x0000, 0x0000, 0x0000, 0x0044, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x310d, 0x0000, 0x0000, 0x0000, 0x0046, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x3115, 0x0000, 0x0000, 0x0000, 0x0048, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x311b, 0x0000, 0x0000, 0x0000, 0x004a, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
        0x311c, 0x0000, 0x0000, 0x0000, 0x004c, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x3129, 0x0000, 0x0000, 0x0000, 0x004e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x311f, 0x0000, 0x0000, 0x0000, 0x0050, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x3106, 0x0000, 0x0000, 0x0000, 0x0052, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x310b, 0x0000, 0x0000, 0x0000, 0x0054, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x3127, 0x0000, 0x0000, 0x0000, 0x0056, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x310a, 0x0000, 0x0000, 0x0000, 0x0058, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x3117, 0x0000, 0x0000, 0x0000, 0x005a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x3105, 0x0000, 0x0000, 0x0000, 0x0032, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x02c7, 0x0000, 0x0000, 0x0000, 0x0034, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000,
        0x3113, 0x0000, 0x0000, 0x0000, 0x0036, 0x0000, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000, 0x0000,
        0x02d9, 0x0000, 0x0000, 0x0000, 0x0038, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x311e, 0x0000, 0x0000, 0x0000, 0x0030, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x311d, 0x0000, 0x0000, 0x0000, 0x002e, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x3125, 0x0000, 0x0000, 0x0000, 0x003b, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
        0x3126, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    },
    {
        {0, 0x65e5, 0}, {0, 0x6708, 0}, {0, 0x91d1, 0}, {0, 0x6728, 0}, {0, 0x6c34, 0}, {0, 0x706b, 0},
        {0, 0x571f, 0}, {0, 0x7af9, 0}, {0, 0x6208, 0}, {0, 0x5341, 0}, {0, 0x5927, 0}, {0, 0x4e2d, 0},
        {0, 0x4e00, 0}, {0, 0x5f13, 0}, {0, 0x4eba, 0}, {0, 0x5fc3, 0}, {0, 0x624b, 0}, {0, 0x53e3, 0},
        {0, 0x5c38, 0}, {0, 0x5eff, 0}, {0, 0x5c71, 0}, {0, 0x5973, 0}, {0, 0x7530, 0}, {0, 0x96e3, 0},
        {0, 0x535c, 0}, {0, 0x005a, 0},
    },
};

// The per-key records at +0xdc (12 bytes each, for keys 0x20..0x7a; the code of each sits 4 bytes before it).
struct Ime01KeyRecord
{
    unsigned short ch;
    unsigned short reserved;
    int value;
    unsigned nextCode;
};

// Key event hook of the IMM IME object (WM_KEYDOWN/WM_KEYUP). Stores the layout (+0x58, +0x5a8) and the IMM virtual
// key (+0xd0); in mode 0x70000 PgDn/PgUp move the IMM candidate page by nine. A key down that is not VK_PROCESSKEY
// marks a key pending (+0xa0) and an IME UI message (+0xa1). On its key up with no UI message and no composition
// (+0x60) the input window is closed (vtbl+0x80, RemoveInputWindow). A key down then translates the key to its
// character (+0xd0; backspace, return, escape and space stop here): mode 2 (Zhuyin) maps it through the key records
// at +0xdc (bopomofo to +0xd0, class to +0xc8), mode 4 (Cangjie) through the radical table. A key up after a
// candidate list was shown (+0x5bc) repositions the candidate window (0x1423d5060, out of line as in the exe).
// The message type is read from the message each time and the pending flag is two byte stores (the exe's word store).
// The Cangjie radicals are read as 8-byte records indexed by tolower(key) - 'a', as in the exe.
// Still differs: cl folds the mode 2 range test into one sub/cmp where the exe keeps cmp 0x20 / cmp 0x7a, and
// some registers differ.
// @0x1423d4c20
void FUN_1423d4c20(void* raw, const void* event)
{
    auto* self = static_cast<unsigned char*>(raw);
    auto* message = static_cast<const unsigned char*>(event);
    auto& key = *reinterpret_cast<unsigned short*>(self + 0xd0);
    BYTE state[256];
    wchar_t translated[0x14];
    if (*reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYDOWN ||
        *reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYUP) {
        GetKeyboardState(state);
        HKL layout = GetKeyboardLayout(0);
        *reinterpret_cast<HKL*>(self + 0x58) = layout;
        *reinterpret_cast<HKL*>(self + 0x5a8) = layout;
        const UINT scan = message[0x1a];
        key = static_cast<unsigned short>(cx18_ImmGetVirtualKey(*reinterpret_cast<HWND*>(self + 0x28)));
        if (*reinterpret_cast<int*>(self + 0x98) == 0x70000 && key == VK_NEXT) {
            HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
            cx18_ImmNotifyIME(context, NI_OPENCANDIDATE, 0, 0);
            cx18_ImmNotifyIME(context, NI_SETCANDIDATE_PAGESTART, 0, *reinterpret_cast<int*>(self + 0x70) + 9);
            cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
        }
        if (*reinterpret_cast<int*>(self + 0x98) == 0x70000 && key == VK_PRIOR) {
            HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
            cx18_ImmNotifyIME(context, NI_OPENCANDIDATE, 0, 0);
            cx18_ImmNotifyIME(context, NI_SETCANDIDATE_PAGESTART, 0, *reinterpret_cast<int*>(self + 0x70) - 9);
            cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
        }
        ToUnicodeEx(key, scan, state, translated, 0x14, 0, *reinterpret_cast<HKL*>(self + 0x58));
    }
    if (*reinterpret_cast<const UINT*>(message + 0xc) == WM_KEYDOWN &&
        *reinterpret_cast<const WPARAM*>(message + 0x10) != VK_PROCESSKEY) {
        self[0xa0] = 1;
        self[0xa1] = 0;
    }
    if (self[0xa0] && cx18_ImmIsUIMessageW(nullptr, *reinterpret_cast<const UINT*>(message + 0xc),
                                           *reinterpret_cast<const WPARAM*>(message + 0x10),
                                           *reinterpret_cast<const LPARAM*>(message + 0x18)))
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
        const UINT virtualKey = cx18_ImmGetVirtualKey(*reinterpret_cast<HWND*>(self + 0x28));
        key = static_cast<unsigned short>(virtualKey);
        ToUnicodeEx(virtualKey & 0xffff, scan, state, translated, 0x14, 0, *reinterpret_cast<HKL*>(self + 0x58));
        unsigned short ch = static_cast<unsigned short>(static_cast<short>(static_cast<signed char>(translated[0])));
        key = ch;
        switch (ch) { case 8: case 13: case 27: case 32: return; }
        int mode = *reinterpret_cast<int*>(self + 0x98);
        if (mode == 2 && ch >= 0x20 && ch <= 0x7a) {
            Ime01KeyRecord& record = reinterpret_cast<Ime01KeyRecord*>(self + 0xdc)[tolower(ch) - 0x20];
            ch = record.ch;
            key = ch;
            *reinterpret_cast<int*>(self + 0xc8) = record.value;
            mode = *reinterpret_cast<int*>(self + 0x98);
        }
        if (mode == 4 && static_cast<unsigned short>(ch - 0x20) <= 0x5a)
            key = cx18_Cangjie.entries[tolower(ch) - 'a'].radical;
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
    typedef unsigned (*ModeOf)(void*, unsigned);
    struct Record { unsigned long long pad0[2]; Scaleform::String name; Scaleform::String text; unsigned code; unsigned pad1[3]; };
    Scaleform::String selected;
    bool alternateFound = false;
    int wasSet = 0;
    unsigned i = 0;
    int result = -1;
    unsigned code = 0x2000000;
    for (i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        if (primary &&
            Scaleform::SFstricmp(primary, reinterpret_cast<Record*>(manager[0x17])[i].name.ToCStr()) == 0 &&
            *reinterpret_cast<unsigned*>(bytes + 0x84) ==
                reinterpret_cast<ModeOf>((*reinterpret_cast<void***>(manager))[3])(manager,
                    reinterpret_cast<Record*>(manager[0x17])[i].code)) {
            selected = reinterpret_cast<Record*>(manager[0x17])[i].name;
            goto setState;
        }
    }
    for (i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        if (alternate &&
            Scaleform::SFstricmp(alternate, reinterpret_cast<Record*>(manager[0x17])[i].name.ToCStr()) == 0 &&
            *reinterpret_cast<unsigned*>(bytes + 0x84) ==
                reinterpret_cast<ModeOf>((*reinterpret_cast<void***>(manager))[3])(manager,
                    reinterpret_cast<Record*>(manager[0x17])[i].code)) {
            selected = reinterpret_cast<Record*>(manager[0x17])[i].text;
            alternateFound = true;
            result = static_cast<int>(i);
            auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
            wasSet = states[i] != 0;
            states[i] = 2;
            code = reinterpret_cast<Record*>(manager[0x17])[i].code;
            break;
        }
    }
    for (unsigned j = 0; j < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++j) {
        if (reinterpret_cast<unsigned*>(manager[0x32])[j] == 1 &&
            reinterpret_cast<Record*>(manager[0x17])[j].code == code)
            goto searchConfig;
    }
    if (alternateFound == true) goto addToLists;
searchConfig:
    {
        struct Config { unsigned code; unsigned pad; unsigned long long language; };
        for (i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
            for (int j = 0; j < *reinterpret_cast<int*>(bytes + 0x178); ++j) {
                if (reinterpret_cast<Config*>(manager[0x2e])[j].language == language &&
                    reinterpret_cast<Config*>(manager[0x2e])[j].code == reinterpret_cast<Record*>(manager[0x17])[i].code) {
                    selected = primary ? primary : alternate;
                    wasSet = false;
                    goto setState;
                }
            }
        }
        return result;
    }
setState:
    {
        result = static_cast<int>(i);
        auto* states = reinterpret_cast<unsigned*>(manager[0x32]);
        wasSet = states[i] != 0;
        states[i] = 1;
    }
addToLists:
    if (!wasSet) {
        Record* record = reinterpret_cast<Record*>(manager[0x17]) + i;
        const unsigned mode = reinterpret_cast<ModeOf>((*reinterpret_cast<void***>(manager))[3])(manager,
            record->code);
        if (mode & 0xf00) reinterpret_cast<Ime01StringArray*>(manager + 2)->PushBack(selected);
        if (mode & 0xf000) reinterpret_cast<Ime01StringArray*>(manager + 5)->PushBack(selected);
        if (mode & 0xf0000) reinterpret_cast<Ime01StringArray*>(manager + 8)->PushBack(selected);
        if (mode & 0xf) reinterpret_cast<Ime01StringArray*>(manager + 0xb)->PushBack(selected);
    }
    return result;
}

// The out-of-line ArrayData<Value>::PushBack (FUN_1423d4fa0) on a local Ime01ValueArgs.
static inline void Ime01PushArgCall(Ime01ValueArgs& args, const Scaleform::GFx::Value& value)
{
    FUN_1423d4fa0(reinterpret_cast<unsigned long long*>(&args), &value);
}

// Moves the candidate window of the IMM IME object to the composition cursor at offset: RepositionCandWindow(x1, y2,
// y2 - y1) of the cursor rect IMEManagerBase::GetMetrics reports.
// The arguments go through the inlined Value array (Ime01ArgArray).
// @0x1423d5060
__declspec(noinline) void FUN_1423d5060(void* raw, int offset)
{
    auto* self = static_cast<unsigned char*>(raw);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, offset);
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    Ime01ArgArray args;
    Scaleform::GFx::Value result;
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1)));
    if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
        reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
            bridge, "RepositionCandWindow", &result, args.data(), 3);
}

// Composition-text update of the Vista IME object (vtable slot 23). It reads GCS_COMPSTR, turns a
// leading space or U+3000 into U+00A0, and either stores the text in the String at +0xb0 (mode 0x60000, which like
// the exe returns without releasing the context) or sends it with SetCompositionText and writes its length to
// *outputLength. The candidate modes also set the cursor, store length - cursor at +0x64 and highlight the whole text.
// It then sets the composition cursor and, unless the mode has a low nibble, calls RepositionInputWindow(x1, y2) of
// the cursor rect IMEManagerBase::GetMetrics reports. Reviewed against the exe, same behaviour. The arguments go
// through an inlined Value array (Ime01ArgArray: Reserve FUN_1423d12e0, element dtor FUN_1423ce6c0).
// @0x1423ce730
void FUN_1423ce730(void* raw, unsigned* outputLength)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    HIMC context = cx18_ImmGetContext(*reinterpret_cast<HWND*>(self + 0x28));
    const LONG size = cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, nullptr, 0);
    auto* text = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<SPInt>(size * 2)) + 2));
    cx18_ImmGetCompositionStringW(context, GCS_COMPSTR, text, size);
    const int count = size / 2;
    text[count] = 0;
    if (text[0] == L' ' || text[0] == 0x3000) text[0] = 0x00a0;
    if (*reinterpret_cast<unsigned*>(self + 0x98) == 0x60000) {
        *reinterpret_cast<Scaleform::String*>(self + 0xb0) = text;
    } else {
        ime->SetCompositionText(text, -1);
        *outputLength = static_cast<unsigned>(count);
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
        if (mode == 0x210000 || mode == 0x110000 || mode == 0xd10000) {
            const LONG cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
            ime->SetCursorInComposition(static_cast<unsigned>(cursor));
            *reinterpret_cast<unsigned*>(self + 0x64) = *outputLength - static_cast<unsigned>(cursor);
            ime->HighlightText(0, *outputLength, Scaleform::GFx::IMEManagerBase::THS_CompositionSegment, false);
        }
        if (size)
            ime->SetCursorInComposition(static_cast<SPInt>(cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0)));
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        ime->GetMetrics(&viewRect, &cursorRect, 0);
        if ((*reinterpret_cast<unsigned*>(self + 0x98) & 0xf) == 0) {
            Ime01ArgArray args;
            Scaleform::GFx::Value result;
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RepositionInputWindow", &result, args.data(), 2);
        }
        cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(self + 0x28), context);
    }
    Scaleform::Memory::Free(text);
}

// Removes the old input window, then shows the composition string (a UTF-8 copy of the String at +0xb0) at the
// cursor rect IMEManagerBase::GetMetrics reports for the composition end (offset -[+0x64]). The arguments go through
// the inlined Value array (Ime01ArgArray).
// @0x1423ceb30
void FUN_1423ceb30(void* raw)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveInputWindow", &result, nullptr, 0);
    }
    auto* composition = reinterpret_cast<Scaleform::String*>(self + 0xb0);
    const unsigned length = *reinterpret_cast<unsigned*>(
        *reinterpret_cast<UPInt*>(composition) & ~static_cast<UPInt>(3));
    if (!length) return;
    const SPInt size = static_cast<int>(length + 1);
    char* text = static_cast<char*>(Scaleform::Memory::Alloc(size));
    memset(text, 0, size);
    memcpy(text, composition->ToCStr(), size);
    if (!text) {
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        return;
    }
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
    {
        Ime01ArgArray args;
        Scaleform::GFx::Value result;
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<const char*>(text)));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
        Ime01PushArg(args, Scaleform::GFx::Value(0.0));
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "DisplayInputWindow", &result, args.data(), 4);
    }
    Scaleform::Memory::Free(text);
}

// The language-bar events FUN_1423cd6b0 and FUN_1423cd0a0 handle the same way. Unknown events go to slot 24 and
// then on to the provider's slot 11 with defaultArgument. The exe inlines this into both callers and re-reads the
// vtable and provider (+0x78) from self at every use, so they are macros here, not locals.
static __forceinline void cx18_DispatchLangBarEvent(unsigned long long* self, const char* command, const char* argument,
                                      const Scaleform::GFx::Value* values)
{
#define vtable (reinterpret_cast<void**>(self[0]))
#define provider (reinterpret_cast<unsigned char*>(self[0xf]))
    auto providerCall = [&](unsigned slot) { return (*reinterpret_cast<void***>(provider))[slot]; };
    auto stringData = [](unsigned long long node) { return reinterpret_cast<const char*>((node & ~3ull) + 0xc); };
    if (std::strcmp(command, "LangBar_OnSelectInputLang") == 0) {
        reinterpret_cast<void(*)(void*)>(vtable[18])(self);
        if (provider) reinterpret_cast<void(*)(void*, const char*)>(providerCall(9))(provider, argument);
    } else if (std::strcmp(command, "LangBar_GetIMENames") == 0) {
        // One block per input mode, each with its own joined String; mode 0x400 reports an empty list too.
#define IME_JOIN(off, always) { Scaleform::String joined; const int count = *reinterpret_cast<int*>(provider + (off)); \
    if (always || count) { for (int i = 0; i < count; ++i) joined += (*reinterpret_cast<Scaleform::String**>(provider + (off) - 8))[i] + "@@"; \
    reinterpret_cast<void(*)(void*, const char*)>(vtable[14])(self, joined.ToCStr()); } break; }
        switch (*reinterpret_cast<unsigned*>(provider + 0x84)) {
        case 9: IME_JOIN(0x60, false)
        case 0x400: IME_JOIN(0x18, true)
        case 0x2000: IME_JOIN(0x30, false)
        case 0x80000: IME_JOIN(0x48, false)
        case 0x10000000: reinterpret_cast<void(*)(void*)>(vtable[18])(self); break;
        }
#undef IME_JOIN
    } else if (std::strcmp(command, "LangBar_OnSelectIME") == 0) {
        if (provider) reinterpret_cast<void(*)(void*, const char*)>(providerCall(8))(provider, argument);
        if (*reinterpret_cast<unsigned*>(provider + 0x84) == 9)
            reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        const char* language = stringData(self[0x16]);
        if (std::strcmp(language, "Japanese") == 0 || std::strcmp(language, "Korean") == 0) {
            reinterpret_cast<void(*)(void*)>(vtable[19])(self);
            reinterpret_cast<void(*)(void*, int)>(providerCall(10))(provider, -1);
        }
    } else if (std::strcmp(command, "LangBar_GetInstalledLanguages") == 0) {
        reinterpret_cast<void(*)(void*, const char*)>(vtable[13])(
                self, stringData(*reinterpret_cast<unsigned long long*>(provider + 0x70)));
    } else {
        reinterpret_cast<void(*)(void*)>(vtable[24])(self);
        if (provider) {
            const char* defaultArgument = argument;
            if (values && values[1].GetType() == Scaleform::GFx::Value::VT_Boolean) defaultArgument = values[1].GetBool() == false ? "false" : "true";
            reinterpret_cast<void(*)(void*, const char*, const char*)>(providerCall(11))(provider, command, defaultArgument); }
    }
}
#undef vtable
#undef provider

// Dispatches the language-bar and status-window callbacks by event name; the rest go to
// cx18_DispatchLangBarEvent with the argument as the default.
// @0x1423cd6b0
static __forceinline void cx18_SendLangBarMessage(unsigned long long* self, unsigned long long payload,
                   const unsigned long long* commandCell, const unsigned long long* argumentCell)
{
    const char* argument = *reinterpret_cast<const char**>(*argumentCell);
    const char* command = *reinterpret_cast<const char**>(*commandCell);
#define vtable (reinterpret_cast<void**>(self[0]))
#define provider (reinterpret_cast<unsigned char*>(self[0xf]))
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
        cx18_DispatchLangBarEvent(self, command, argument, nullptr);
    }
}
#undef vtable
#undef provider
void GFxIMEManagerWin32::SendLangBarMessage(DisplayObject* mc, const ASString& cmd, const ASString& msg)
{
    cx18_SendLangBarMessage(reinterpret_cast<unsigned long long*>(this), reinterpret_cast<unsigned long long>(mc),
                            reinterpret_cast<const unsigned long long*>(&cmd),
                            reinterpret_cast<const unsigned long long*>(&msg));
}

// MS2-FUNCTIONAL: decodes the external callback's Value array and dispatches its event by name. The OnInit events
// keep the second Value in the owner at +0x28/+0x58. CandidateList_OnItemSelect passes the selected index (a
// VT_Number second Value) to FUN_1423ca3f0, which forwards it to the candidate list's slot 19. Unknown events go
// through cx18_DispatchLangBarEvent, which sends "true"/"false" for a VT_Boolean second Value.
// Same length (1547 bytes) and the same instructions as the exe. Three scheduling differences are left:
// - At the tail, cl loads the "false" literal before "true". The exe loads "true" into r15 first. This holds for
//   every spelling tried: ternary, inverted ternary, if/else, and default-then-override.
// - In StatusWindow_OnInit, cl keeps the -1 for provider slot 10 and vtable[6] in ebx, set inside the inlined
//   "Korean" compare loop. The exe uses two mov edx,-1 immediates. Nesting the provider check does not change it.
// - In the inlined LangBar_GetIMENames case 0x80000, the exe uses a 6-byte je for the empty-list skip. Ours is
//   a 2-byte je, so the loop padding differs (2-byte nop vs 7-byte nop). FUN_1423cd6b0 inlines the same helper
//   and matches, so this follows from cl's branch-size estimate for this caller.
// fe4 tried these on 11-06 and left them.
// @0x1423cd0a0
void GFxIMEManagerWin32::ProcessIMEMessage(const FunctionHandler::Params& params)
{
    unsigned long long* self = reinterpret_cast<unsigned long long*>(this);
    const unsigned char* event = reinterpret_cast<const unsigned char*>(&params);
    using Scaleform::GFx::Value;
    const unsigned count = *reinterpret_cast<const unsigned*>(event + 0x28);
    const unsigned long long payload = *reinterpret_cast<const unsigned long long*>(event + 8);
    const Value* values = *reinterpret_cast<const Value* const*>(event + 0x20);
    if (!count) return;
    const char* command = values[0].GetString();
    const char* argument = nullptr;
    if (count > 1 && values[1].GetType() == Value::VT_String) argument = values[1].GetString();
#define vtable (reinterpret_cast<void**>(self[0]))
#define provider (reinterpret_cast<unsigned char*>(self[0xf]))
#define owner (reinterpret_cast<unsigned char*>(self[3]))
    if (std::strcmp(command, "CandidateList_OnSetItemDataMap") == 0) {
        auto* candidates = reinterpret_cast<unsigned char*>(self[0xe]);
        if (candidates)
            reinterpret_cast<void(*)(void*, unsigned long long, const char*, const char*)>(
                (*reinterpret_cast<void***>(candidates))[0xa0 / sizeof(void*)])(candidates, payload, command, argument);
    } else if (std::strcmp(command, "CandidateList_OnItemSelect") == 0) {
        // The exe reads the second Value's type here without checking count, so a one-element array reads past its
        // end. StatusWindow_OnInit does the same. Both are kept as in the exe.
        // FUN_1423ca3f0 is noinline because the exe calls it rather than inlining it.
        if (values[1].GetType() == Value::VT_Number) FUN_1423ca3f0(self, static_cast<int>(values[1].GetNumber()));
    } else if (std::strcmp(command, "LangBar_OnInit") == 0) {
        if (count < 2 || values[1].IsUndefined()) return;
        *reinterpret_cast<Value*>(owner + 0x28) = values[1];
        if (provider)
            reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[12])(provider);
    } else if (std::strcmp(command, "StatusWindow_OnInit") == 0) {
        if (count < 1 || values[1].IsUndefined()) return;
        *reinterpret_cast<Value*>(owner + 0x58) = values[1];
        const char* language = reinterpret_cast<const char*>((self[0x16] & ~3ull) + 0xc);
        reinterpret_cast<void(*)(void*, const char*)>(vtable[12])(self, language);
        reinterpret_cast<void(*)(void*)>(vtable[19])(self);
        // The exe reloads the name here: either slot may have replaced the string at +0xb0.
        language = reinterpret_cast<const char*>((self[0x16] & ~3ull) + 0xc);
        if (std::strcmp(language, "Korean") == 0 && provider)
            reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(provider))[10])(provider, -1);
        reinterpret_cast<void(*)(void*, int)>(vtable[6])(self, -1);
    } else {
        cx18_DispatchLangBarEvent(self, command, argument, values);
    }
#undef vtable
#undef provider
#undef owner
}

// For the (0x282, 0xe, 0x12) notification: on backspace ([+0xd0] == 8) in state 4/0x40000 it removes the
// input window, drops the last character of the wide buffer at [+0x40] and shows the rest; in state 2 it removes the
// window through FUN_1423ca030, blanks the last non-space of the first four characters of [+0xb0] and shows that. The
// text goes out as UTF-8 to DisplayInputWindow(text, cursor.x1, cursor.y2, 0.0) at the IME manager's cursor rect. On
// space ([+0xd0] == 0x20) in state 4 it removes the window and clears [+0x40].
// @0x1423d1d10
void FUN_1423d1d10(void* raw, long long message, long long compositionFlag, long long extra)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(raw);
    Scaleform::GFx::Value unused;
    if (message != 0x282 || compositionFlag != 0xe || extra != 0x12) return;
    if (*reinterpret_cast<short*>(self + 0xd0) == 8) {
        const unsigned state = *reinterpret_cast<unsigned*>(self + 0x98);
        if (state == 4 || state == 0x40000) {
            {
                Scaleform::GFx::Value result;
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "RemoveInputWindow", &result, nullptr, 0);
            }
            auto* buffer = *reinterpret_cast<wchar_t**>(self + 0x40);
            const int length = static_cast<int>(wcslen(buffer));
            buffer[length - 1] = 0;
            const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(*reinterpret_cast<wchar_t**>(self + 0x40), -1));
            char* text = static_cast<char*>(Scaleform::Memory::Alloc(size + 1));
            Scaleform::UTF8Util::EncodeString(text, *reinterpret_cast<wchar_t**>(self + 0x40), -1);
            void* owner = *reinterpret_cast<void**>(self + 8);
            Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
                reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
            Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
            ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
            {
                Ime01ValueArgs args;
                Scaleform::GFx::Value result;
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<const char*>(text)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(0.0));
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "DisplayInputWindow", &result, args.data, 4);
            }
            Scaleform::Memory::Free(text);
        }
        if (*reinterpret_cast<unsigned*>(self + 0x98) == 2) {
            FUN_1423ca030(*reinterpret_cast<void**>(self + 8), "RemoveInputWindow", nullptr);
            int i = 3;
            while (i >= 0) {
                if ((*reinterpret_cast<wchar_t**>(self + 0xb0))[i] != L' ') break;
                --i;
            }
            if (i >= 0) (*reinterpret_cast<wchar_t**>(self + 0xb0))[i] = L' ';
            Scaleform::GFx::Value kept;
            const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(*reinterpret_cast<wchar_t**>(self + 0xb0), -1));
            char* text = static_cast<char*>(Scaleform::Memory::Alloc(size + 1));
            Scaleform::UTF8Util::EncodeString(text, *reinterpret_cast<wchar_t**>(self + 0xb0), -1);
            void* owner = *reinterpret_cast<void**>(self + 8);
            Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
                reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
            Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
            ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
            {
                Ime01ValueArgs args;
                Scaleform::GFx::Value result;
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<const char*>(text)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
                Ime01PushArgCall(args, Scaleform::GFx::Value(0.0));
                if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                    reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                        bridge, "DisplayInputWindow", &result, args.data, 4);
            }
            if (text) Scaleform::Memory::Free(text);
        }
    }
    if (*reinterpret_cast<short*>(self + 0xd0) == 0x20 && *reinterpret_cast<unsigned*>(self + 0x98) == 4) {
        {
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &result, nullptr, 0);
        }
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
    }
}

// Formats the native/alphanumeric, shape, and Japanese IME conversion state labels.
// @0x1423cc7c0
void FUN_1423cc7c0(void* raw, unsigned conversion)
{
    auto* self = static_cast<unsigned char*>(raw);
    if (!*reinterpret_cast<void**>(self + 0x78)) return;
    Scaleform::String label;
    HIMC context = ImmGetContext(*reinterpret_cast<HWND*>(*reinterpret_cast<unsigned char**>(self + 0x78) + 0x68));
    if (!context) return;
    {
        DWORD sentence;
        if (conversion == 0xffffffffu)
            cx18_ImmGetConversionStatus(context, reinterpret_cast<DWORD*>(&conversion), &sentence);
        Scaleform::String saved(*reinterpret_cast<const Scaleform::String*>(*reinterpret_cast<unsigned char**>(self + 0x78) + 0x88));
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x84);
        // Each token is appended as String(token) + ",", e.g. "Native,full,half,".
        if (mode == 0x80000 || mode == 9 || mode == 0x2000) {
            if (conversion & 1) label += Scaleform::String("Native") + ",";
            else label += Scaleform::String("Alphanumeric") + ",";
            if (conversion & 8) label += Scaleform::String("full") + ",";
            else label += Scaleform::String("half") + ",";
            if (conversion & 0x400) label += Scaleform::String("full") + ",";
            else label += Scaleform::String("half") + ",";
        }
        if (*reinterpret_cast<unsigned*>(self + 0x84) == 0x400) {
            if (!cx18_ImmGetOpenStatus(context)) {
                *reinterpret_cast<unsigned char*>(self + 0xa8) = 0;
                label += Scaleform::String("DirectInput") + ",";
            } else if (conversion & 1) {
                *reinterpret_cast<unsigned char*>(self + 0xa8) = 1;
                if ((conversion & 0xa) == 0xa) label += Scaleform::String("Katakana_FullShape") + ",";
                else if ((conversion & 0xa) == 8) label += Scaleform::String("Hiragana_FullShape") + ",";
                else label += Scaleform::String("Katakana_HalfShape") + ",";
            } else {
                if (conversion & 8) label += Scaleform::String("Alphanumeric_FullShape") + ",";
                else label += Scaleform::String("Alphanumeric_HalfShape") + ",";
            }
        }
        void* state = *reinterpret_cast<void**>(self + 0x78);
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(state))[0x88 / sizeof(void*)])(
            state, label.ToCStr());
        cx18_ImmReleaseContext(*reinterpret_cast<HWND*>(*reinterpret_cast<unsigned char**>(self + 0x78) + 0x68), context);
    }
}

// Asks the IME manager for the cursor rect at the given offset and calls
// RepositionCandWindow(cursor.x1, cursor.y2, cursor.y2 - cursor.y1) on the movie's external interface. The arguments
// go through the inlined Value array (Ime01ArgArray).
// @0x1423d0f60
void FUN_1423d0f60(void* manager, int mode)
{
    auto* self = static_cast<unsigned char*>(manager);
    void* owner = *reinterpret_cast<void**>(self + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, mode);
    Ime01ArgArray args;
    Scaleform::GFx::Value result;
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
    Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1)));
    if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
        reinterpret_cast<void(*)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned)>(
            (*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(bridge, "RepositionCandWindow", &result,
                                                                        args.data(), 3);
}

struct Ime01CandidateProps
{
    int values[10];
    unsigned short flags;
};

// MS2-FUNCTIONAL: converts the candidate/reading window property mask into the two formatted AS calls,
// <path at +0x10>.SetCandidateListProps and <path>.SetReadingWindowProps. Same operations as the exe (bit 4 is
// tested twice there too). The values are unsigned (the exe keeps value0 in the -1 register). Left: the exe saves rbp
// without using it, keeps self in r14 and the temporary in rdi, and puts the spilled values in other slots.
// @0x1423cf670
void FUN_1423cf670(void* raw, const unsigned* rawAttributes)
{
    auto* attributes = reinterpret_cast<const Ime01CandidateProps*>(rawAttributes);
    auto* self = static_cast<unsigned char*>(raw);
    auto* owner = *reinterpret_cast<unsigned char**>(self + 8);
    if (!owner) return;
    auto* factory = owner + 0x10;
    void* temporary = reinterpret_cast<void*(*)(void*, int)>((*reinterpret_cast<void***>(factory))[3])(factory, 0x18);
    if (!temporary) return;
    unsigned value0 = ~0u, value1 = ~0u, value2 = ~0u, value3 = ~0u, value4 = ~0u;
    unsigned value5 = ~0u, value6 = ~0u, value7 = ~0u, value8 = ~0u, value9 = ~0u;
    if (*reinterpret_cast<const unsigned char*>(&attributes->flags) & 1) value0 = attributes->values[0];
    if (static_cast<unsigned char>(attributes->flags >> 1) & 1) value1 = attributes->values[1];
    if (static_cast<unsigned char>(attributes->flags >> 3) & 1) value3 = attributes->values[3];
    if (static_cast<unsigned char>(attributes->flags >> 4) & 1) value4 = attributes->values[4];
    if (static_cast<unsigned char>(attributes->flags >> 5) & 1) value5 = attributes->values[5];
    if (static_cast<unsigned char>(attributes->flags >> 2) & 1) value2 = attributes->values[2];
    if (static_cast<unsigned char>(attributes->flags >> 4) & 1) value4 = attributes->values[4];
    if (static_cast<unsigned char>(attributes->flags >> 6) & 1) value8 = attributes->values[8];
    if (static_cast<unsigned char>(attributes->flags >> 7) & 1) value6 = attributes->values[6];
    if (static_cast<unsigned char>(attributes->flags >> 8) & 1) value7 = attributes->values[7];
    if (static_cast<unsigned char>(attributes->flags >> 9) & 1) value9 = attributes->values[9];
    auto* command = reinterpret_cast<Scaleform::String*>(self + 0x10);
    if (command->GetLength()) {
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), (*command + ".SetCandidateListProps").ToCStr(),
            "%d %d %d %d %d %d %d", value0, value3, value1, value4, value8, value2, value5);
        FUN_1423ca030(*reinterpret_cast<void**>(self + 8), (*command + ".SetReadingWindowProps").ToCStr(),
            "%d %d %d", value6, value7, value9);
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

// The SDK's case-insensitive StringHash lookup: the key copies the name with its hash and length, the table walk is
// HashSetBase::findIndexCore, and the found value is read without a null check (as in the exe, an unknown name
// dereferences address 0).
// @0x1423cb400
unsigned FUN_1423cb400(void* raw, const char* name)
{
    struct Node { const char* name; unsigned long long p8; unsigned code; unsigned p14; unsigned long long p18;
        unsigned hash; unsigned length; };
    struct Key {
        String str; unsigned long long hash, length;
        Key() {}
        Key(const char* s, unsigned long long h, unsigned long long l) : str(s), hash(h & 0xffffff), length(l) {}
    };
    struct Entry { long long NextInChain; Node* Value; };
    struct TableHdr { unsigned long long EntryCount, SizeMask; };
    struct Set {
        TableHdr* pTable;
        Entry& E(unsigned long long index) { return *(((Entry*)(pTable + 1)) + index); }
        long long findIndexCore(const Key& key, unsigned long long hashValue)
        {
            unsigned long long index = hashValue;
            Entry* e = &E(index);
            if (e->NextInChain == -2 || (e->Value->hash & pTable->SizeMask) != index) return -1;
            for (;;) {
                if ((e->Value->hash & pTable->SizeMask) == hashValue && e->Value->length == key.length &&
                    SFstricmp(e->Value->name, key.str.ToCStr()) == 0)
                    return index;
                index = e->NextInChain;
                if (index == ~0ull) break;
                e = &E(index);
            }
            return -1;
        }
        long long findIndex(const Key& key)
        {
            if (!pTable) return -1;
            return findIndexCore(key, key.hash & pTable->SizeMask);
        }
        Node** Get(const Key& key)
        {
            long long index = findIndex(key);
            if (index >= 0) return &E(index).Value;
            return 0;
        }
    };
    Key key;
    const unsigned long long length = std::strlen(name);
    key = Key(name, String::BernsteinHashFunctionCIS(name, length, 0x1505), length);
    Node** found = reinterpret_cast<Set*>(static_cast<unsigned char*>(raw) + 8)->Get(key);
    unsigned code;
    if (*found) code = (*found)->code;
    else code = 0x01000000;
    return code;
}

// MS2-FUNCTIONAL: HashSetBase::setRawCapacity on the command table (clear on 0, round up with UpperBit, rehash each
// live entry through CheckExpand and the inline add, whose probe and walk re-read the table through fresh). Left: the
// stat id and the new table sit in other home slots (rbx is saved at 0x58, not 0x50), and the entry and hash swap rbx
// and rdi.
// @0x1423d9090
void FUN_1423d9090(void* raw, void* heap, unsigned long long requested)
{
    struct Payload { unsigned long long value0, value1; };
    struct Node { unsigned long long key, value0, value1; };
    auto* slot = static_cast<unsigned long long*>(raw);
    if (!requested) {
        if (slot[0]) {
            for (unsigned long long i = 0, last = reinterpret_cast<unsigned long long*>(slot[0])[1]; i <= last; ++i) {
                auto& e = reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(slot[0]) + 2)[i];
                if (static_cast<long long>(e.next) != -2) e.next = ~1ull;
            }
            if (void* p = reinterpret_cast<void*>(slot[0])) Scaleform::Memory::Free(p);
            slot[0] = 0;
        }
        return;
    }

    if (requested < 8)
        requested = 8;
    else {
        const unsigned long long v = requested - 1;
        unsigned char bit;
        if (v & 0xFFFFFFFF00000000) {
            if (v & 0xFFFF000000000000)
                bit = (v & 0xFF00000000000000) ? Scaleform::Alg::UpperBitTable[(v >> 56)] + 56
                                               : Scaleform::Alg::UpperBitTable[(v >> 48) & 0xFF] + 48;
            else
                bit = (v & 0xFF0000000000) ? Scaleform::Alg::UpperBitTable[(v >> 40) & 0xFF] + 40
                                           : Scaleform::Alg::UpperBitTable[(v >> 32) & 0xFF] + 32;
        } else {
            if (v & 0xFFFF0000)
                bit = (v & 0xFF000000) ? Scaleform::Alg::UpperBitTable[(v >> 24)] + 24
                                       : Scaleform::Alg::UpperBitTable[(v >> 16) & 0xFF] + 16;
            else
                bit = (v & 0xFF00) ? Scaleform::Alg::UpperBitTable[(v >> 8) & 0xFF] + 8
                                   : Scaleform::Alg::UpperBitTable[v & 0xFF];
        }
        const int bits = bit + 1;
        requested = 1ull << bits;
    }

    unsigned long long fresh = reinterpret_cast<unsigned long long>(Scaleform::Memory::Alloc(
        0x10 + requested * sizeof(cx18_CommandEntry), Scaleform::AllocInfo(2, nullptr, 0)));
    reinterpret_cast<unsigned long long*>(fresh)[0] = 0;
    reinterpret_cast<unsigned long long*>(fresh)[1] = requested - 1;
    for (unsigned long long i = 0; i < requested; ++i)
        reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(fresh) + 2)[i].next = ~1ull;

    if (slot[0]) {
        for (unsigned long long i = 0, last = reinterpret_cast<unsigned long long*>(slot[0])[1]; i <= last; ++i) {
            cx18_CommandEntry* e = &reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(slot[0]) + 2)[i];
            if (static_cast<long long>(e->next) == -2) continue;
            const char* name = reinterpret_cast<const char*>(e->key);
            unsigned long long hash = Scaleform::String::BernsteinHashFunction(name, std::strlen(name), 0x1505);
            FUN_1423d8d10(&fresh, reinterpret_cast<unsigned long long>(heap));

            hash &= reinterpret_cast<unsigned long long*>(fresh)[1];
            ++reinterpret_cast<unsigned long long*>(fresh)[0];
            const long long index = static_cast<long long>(hash);
            auto* table = reinterpret_cast<unsigned long long*>(fresh);
            cx18_CommandEntry* natural = &reinterpret_cast<cx18_CommandEntry*>(table + 2)[index];
            if (static_cast<long long>(natural->next) == -2) {
                natural->next = ~0ull;
                natural->key = e->key;
                *reinterpret_cast<Payload*>(&natural->value0) = *reinterpret_cast<Payload*>(&e->value0);
            } else {
                long long blank = index;
                do {
                    blank = (blank + 1) & reinterpret_cast<unsigned long long*>(fresh)[1];
                } while (static_cast<long long>(reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(fresh) + 2)[blank].next) != -2);
                cx18_CommandEntry* free = &reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(fresh) + 2)[blank];
                if (natural->home == static_cast<unsigned long long>(index)) {
                    free->next = natural->next;
                    free->home = natural->home;
                    free->key = natural->key;
                    *reinterpret_cast<Payload*>(&free->value0) = *reinterpret_cast<Payload*>(&natural->value0);
                    *reinterpret_cast<Node*>(&natural->key) = *reinterpret_cast<Node*>(&e->key);
                    natural->next = blank;
                } else {
                    long long walk = static_cast<long long>(natural->home);
                    for (;;) {
                        cx18_CommandEntry* w = &reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(fresh) + 2)[walk];
                        if (static_cast<long long>(w->next) == index) {
                            free->next = natural->next;
                            free->home = natural->home;
                            free->key = natural->key;
                            *reinterpret_cast<Payload*>(&free->value0) = *reinterpret_cast<Payload*>(&natural->value0);
                            w->next = blank;
                            break;
                        }
                        walk = static_cast<long long>(w->next);
                    }
                    *reinterpret_cast<Node*>(&natural->key) = *reinterpret_cast<Node*>(&e->key);
                    natural->next = ~0ull;
                }
            }
            natural->home = hash;
            e->next = ~1ull;
        }
        if (void* p = reinterpret_cast<void*>(slot[0])) Scaleform::Memory::Free(p);
    }
    slot[0] = fresh;
}

// HashSetBase::add on the command table (grow, then insert at the home slot, moving the old head or a borrowed slot to
// the next free entry). The probe and walk re-read the table through map[0] each time, as the SDK's E(i) reads pTable.
// @0x1423d8b80
__declspec(noinline) void FUN_1423d8b80(unsigned long long* map, void* heap, void** item, unsigned long long hash)
{
    struct Payload { unsigned long long value0, value1; };
    auto* table = reinterpret_cast<unsigned long long*>(map[0]);
    if (!table)
        FUN_1423d9090(map, heap, 8);
    else if (table[0] * 5 > table[1] * 4 + 4)
        FUN_1423d9090(map, heap, table[1] * 2 + 2);

    hash &= reinterpret_cast<unsigned long long*>(map[0])[1];
    ++reinterpret_cast<unsigned long long*>(map[0])[0];

    const long long index = static_cast<long long>(hash);
    table = reinterpret_cast<unsigned long long*>(map[0]);
    cx18_CommandEntry* natural = &reinterpret_cast<cx18_CommandEntry*>(table + 2)[index];
    if (static_cast<long long>(natural->next) == -2) {
        natural->next = ~0ull;
        natural->key = *static_cast<unsigned long long*>(item[0]);
        *reinterpret_cast<Payload*>(&natural->value0) = *static_cast<Payload*>(item[1]);
    } else {
        long long blank = index;
        do {
            blank = (blank + 1) & reinterpret_cast<unsigned long long*>(map[0])[1];
        } while (static_cast<long long>(reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(map[0]) + 2)[blank].next) != -2);
        cx18_CommandEntry* free = &reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(map[0]) + 2)[blank];
        if (natural->home == static_cast<unsigned long long>(index)) {
            free->next = natural->next;
            free->home = natural->home;
            free->key = natural->key;
            *reinterpret_cast<Payload*>(&free->value0) = *reinterpret_cast<Payload*>(&natural->value0);
            natural->key = *static_cast<unsigned long long*>(item[0]);
            *reinterpret_cast<Payload*>(&natural->value0) = *static_cast<Payload*>(item[1]);
            _ReadWriteBarrier();
            natural->next = blank;
        } else {
            long long walk = static_cast<long long>(natural->home);
            for (;;) {
                cx18_CommandEntry* e = &reinterpret_cast<cx18_CommandEntry*>(reinterpret_cast<unsigned long long*>(map[0]) + 2)[walk];
                if (static_cast<long long>(e->next) == index) {
                    free->next = natural->next;
                    free->home = natural->home;
                    free->key = natural->key;
                    *reinterpret_cast<Payload*>(&free->value0) = *reinterpret_cast<Payload*>(&natural->value0);
                    e->next = blank;
                    break;
                }
                walk = static_cast<long long>(e->next);
            }
            natural->key = *static_cast<unsigned long long*>(item[0]);
            *reinterpret_cast<Payload*>(&natural->value0) = *static_cast<Payload*>(item[1]);
            _ReadWriteBarrier();
            natural->next = ~0ull;
        }
    }
    _ReadWriteBarrier();
    natural->home = hash;
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

// Reading-string window of the IMM IME object, called from its WM_IME_COMPOSITION handler (0x1423d3510) for
// GCS_COMPATTR. Removes the old input window, then updates the reading text at +0x40 from the last key (+0xd0) by the
// input mode at +0x98: modes 1/3/5/7 copy the composition reading string; mode 2 (key 0x3000 only) writes the key into
// the +0xb0 buffer at index +0xc8 and copies it (other keys reset that buffer to four spaces); modes 4/10 append up
// to five keys and handle backspace; 0x10000/0x20000/0x30000/0x60000/0xa10000/0xb10000/0xd00001/0xd00002 copy the
// reading string; 0x110000 appends a..z; 0x40000/0x50000/0x70000/0x90000/0xa0000 restart the text when the target
// clause (first attribute 1) moves (its index kept at +0x5a4) and append otherwise. Escape clears it. A non-empty
// result goes to DisplayInputWindow.
// MS2-FUNCTIONAL: register allocation (key/attributes swap r14/rbx) and the 0x40000 group's append, which the exe
// keeps separate with a reload of +0xd0 while cl tail-merges it with the 0x110000 append. Same behaviour.
// @0x1423d2710
void FUN_1423d2710(void* manager, int key, unsigned length, long long attributes, wchar_t* reading)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = static_cast<unsigned char*>(manager);
    Scaleform::GFx::Value unused;
    {
        Scaleform::GFx::Value result;
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveInputWindow", &result, nullptr, 0);
    }
    const wchar_t& ch = *reinterpret_cast<wchar_t*>(self + 0xd0);
    wchar_t*& text = *reinterpret_cast<wchar_t**>(self + 0x40);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime;
    if (ch == 0x1b) {
        *text = 0;
        return;
    }
    const int textLength = static_cast<int>(wcslen(text));
    const int count = static_cast<int>(length);
    const auto* attrs = reinterpret_cast<const char*>(attributes);
    switch (*reinterpret_cast<int*>(self + 0x98)) {
    case 4: case 10:
        if (key != 0x3000) {
            *text = 0;
            return;
        }
        if (ch != L'\r' && ch != L' ' && ch != L'\b') {
            const int n = static_cast<int>(wcslen(text));
            if (n <= 4) {
                text[n] = ch;
                text[n + 1] = 0;
            }
        }
        if (ch == L'\b') {
            const int n = static_cast<int>(wcslen(text));
            if (n > 0) text[n - 1] = 0;
        }
        break;
    case 2: {
        const int index = *reinterpret_cast<int*>(self + 0xc8);
        if (index > 4) return;
        wchar_t*& buffer = *reinterpret_cast<wchar_t**>(self + 0xb0);
        if (key == 0x3000) {
            buffer[index] = ch;
            Scaleform::SFwcscpy(text, wcslen(buffer) + 1, buffer);
            break;
        }
        buffer[0] = L' ';
        buffer[1] = L' ';
        buffer[2] = L' ';
        buffer[3] = L' ';
        buffer[4] = 0;
        return;
    }
    case 1: case 3: case 5: case 7:
        Scaleform::SFwcscpy(text, wcslen(reading) + 1, reading);
        break;
    case 0x40000: case 0x50000: case 0x70000: case 0x90000: case 0xa0000:
        if (key == 0x3000) {
            if (ch == L'\b') {
                if (textLength > 0) text[textLength - 1] = 0;
            } else if (ch != L'\r' && ch != L' ') {
                int target = 0;
                for (; target < count; ++target)
                    if (attrs[target] == ATTR_TARGET_CONVERTED) break;
                if (target == count) return;
                auto& lastTarget = *reinterpret_cast<int*>(self + 0x5a4);
                if (lastTarget == target) {
                    text[textLength] = ch;
                    text[textLength + 1] = 0;
                } else {
                    lastTarget = target;
                    text[0] = ch;
                    text[1] = 0;
                }
            }
        } else {
            *text = 0;
        }
        break;
    case 0x110000:
        if (ch == L'\b') {
            if (textLength > 0) text[textLength - 1] = 0;
        } else if (static_cast<unsigned short>(ch - L'a') <= 0x19) {
            text[textLength] = ch;
            text[textLength + 1] = 0;
        }
        break;
    case 0x10000: case 0x20000: case 0x30000: case 0x60000: case 0xa10000: case 0xb10000: case 0xd00001: case 0xd00002: {
        const int n = static_cast<int>(wcslen(reading));
        memcpy(text, reading, n * 2);
        text[n] = 0;
        break;
    }
    default:
        break;
    }
    const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(text, -1));
    if (!size) return;
    char* utf8 = static_cast<char*>(Scaleform::Memory::Alloc(size + 1));
    Scaleform::UTF8Util::EncodeString(utf8, text, -1);
    void* owner = *reinterpret_cast<void**>(self + 8);
    ime = reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
    ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
    {
        Ime01ArgArray args;
        Scaleform::GFx::Value result;
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<const char*>(utf8)));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
        Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1)));
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "DisplayInputWindow", &result, args.data(), 4);
    }
    if (utf8) Scaleform::Memory::Free(utf8);
}

// WM_IME_COMPOSITION of the IMM IME object (vtbl 0x14313a5f8 slot 10). No flags: clears the composition length
// (+0x60). GCS_RESULTSTR: the result string is finalized into the IME manager, kept in its String at +0x98 and
// broadcast (slot 11); the input window is removed. CS_INSERTCHAR|CS_NOMOVECARET: wParam becomes a one-character
// composition. GCS_COMPSTR|GCS_CURSORPOS: vtbl+0xb8. GCS_COMPATTR: sets the composition cursor, computes +0x64 from
// the target clause, highlights each run of equal attributes, repositions the candidate window in mode 0x40000 and
// updates the reading window (0x1423d2710). Exactly GCS_CURSORPOS|GCS_DELTASTART: shows the reading text at +0x40.
// MS2-FUNCTIONAL: what is left is the frame (exe 0x118 with rsi saved, ours 0x138 with rbx; the exe shares the run
// and rect slots) and register allocation in the attribute loop. Reviewed branch by branch against the exe (result
// string, inserted char, attribute runs and their highlight styles, candidate window, reading window): same behaviour.
// @0x1423d3510
void FUN_1423d3510(long long* manager, unsigned long long wParam, unsigned long long flags)
{
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    auto* self = reinterpret_cast<unsigned char*>(manager);
    if (!manager[1]) return;
#define states reinterpret_cast<Scaleform::GFx::StateBag*>(*reinterpret_cast<unsigned char**>(self + 8) + 0x10)
#define hwnd (*reinterpret_cast<HWND*>(self + 0x28))
#define vtable (*reinterpret_cast<void***>(self))
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime = states->GetIMEManager();
    Scaleform::GFx::Value unused;
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
        {
            Scaleform::GFx::Value removed;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &removed, nullptr, 0);
        }
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
        int length = *reinterpret_cast<int*>(self + 0x60);
        if (static_cast<unsigned>(attrSize) < static_cast<unsigned>(length)) length = attrSize;
        const LONG readSize = cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, nullptr, 0);
        auto* reading = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(readSize) * 2 + 2)));
        memset(reading, 0, static_cast<size_t>(static_cast<unsigned>(readSize) * 2));
        cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, reading, readSize);
        reading[static_cast<unsigned>(readSize) >> 1] = 0;
        const SPInt cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
        cx18_ImmReleaseContext(hwnd, context);
        ime->SetCursorInComposition(cursor);

        struct Segment { int start; int end; int attr; };
        ArrayData<Ime01Pod<0xc>, AllocatorGH_POD<Ime01Pod<0xc>>, ArrayDefaultPolicy> array;
        auto push = [&](const Segment& segment) {
            array.ResizeNoConstruct(&array, array.Size + 1);
            reinterpret_cast<Segment*>(array.Data)[array.Size - 1] = segment;
        };
        unsigned char previous = static_cast<unsigned char>(attrs[0]);
        Segment current;
        current.attr = attrs[0];
        current.start = 0;
        *reinterpret_cast<unsigned*>(self + 0x64) = length;
        unsigned remaining = length;
        for (int i = 0; i < length; ++i, --remaining) {
            if (static_cast<unsigned char>(attrs[i]) != previous) {
                push(current);
                if (attrs[i] == ATTR_TARGET_CONVERTED || attrs[i] == ATTR_TARGET_NOTCONVERTED)
                    *reinterpret_cast<unsigned*>(self + 0x64) = remaining;
                previous = static_cast<unsigned char>(attrs[i]);
                current.attr = attrs[i];
                current.start = i;
            }
            current.end = i;
        }
        current.end = length - 1;
        push(current);
        auto* segments = reinterpret_cast<const Segment*>(array.Data);
        const UPInt count = array.Size;
        const unsigned mode = *reinterpret_cast<unsigned*>(self + 0x98);
        if (!(mode & 0xf000)) {
            for (UPInt i = 0; i < count; ++i) {
                const unsigned start = static_cast<unsigned>(segments[i].start);
                const unsigned span = static_cast<unsigned>(segments[i].end - segments[i].start + 1);
                Scaleform::GFx::IMEManagerBase::TextHighlightStyle style;
                switch (segments[i].attr) {
                case ATTR_INPUT: style = Scaleform::GFx::IMEManagerBase::THS_CompositionSegment; break;
                case ATTR_TARGET_CONVERTED:
                case ATTR_TARGET_NOTCONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ClauseSegment; break;
                case ATTR_CONVERTED: style = Scaleform::GFx::IMEManagerBase::THS_ConvertedSegment; break;
                case ATTR_INPUT_ERROR: style = Scaleform::GFx::IMEManagerBase::THS_LowConfSegment; break;
                default: continue;
                }
                ime->HighlightText(start, span, style, false);
            }
        }
        if (*reinterpret_cast<unsigned*>(self + 0x98) == 0x40000) {
            Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
            ime->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
            Ime01ArgArray args;
            Scaleform::GFx::Value result;
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2 - cursorRect.y1)));
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RepositionCandWindow", &result, args.data(), 3);
        }
        FUN_1423d2710(self, static_cast<int>(wParam), length, reinterpret_cast<long long>(attrs), reading);
        if (reading) Scaleform::Memory::Free(reading);
        Scaleform::Memory::Free(attrs);
    }
    if (flags == (GCS_CURSORPOS | GCS_DELTASTART)) {
        if (reinterpret_cast<Scaleform::String*>(self + 0x10)->GetLength()) {
            Scaleform::GFx::Value result;
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "RemoveInputWindow", &result, nullptr, 0);
        }
        const int size = static_cast<int>(Scaleform::UTF8Util::GetEncodeStringSize(*reinterpret_cast<wchar_t**>(self + 0x40), -1));
        char* utf8 = static_cast<char*>(Scaleform::Memory::Alloc(size + 1));
        Scaleform::UTF8Util::EncodeString(utf8, *reinterpret_cast<wchar_t**>(self + 0x40), -1);
        void* owner = *reinterpret_cast<void**>(self + 8);
        Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> reader =
            reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
        Scaleform::Render::RectF viewRect(0, 0, 0, 0), cursorRect(0, 0, 0, 0);
        reader->GetMetrics(&viewRect, &cursorRect, -*reinterpret_cast<int*>(self + 0x64));
        {
            Ime01ArgArray args;
            Scaleform::GFx::Value result;
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<const char*>(utf8)));
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.x1)));
            Ime01PushArg(args, Scaleform::GFx::Value(static_cast<double>(cursorRect.y2)));
            Ime01PushArg(args, Scaleform::GFx::Value(0.0));
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "DisplayInputWindow", &result, args.data(), 4);
        }
        **reinterpret_cast<wchar_t**>(self + 0x40) = 0;
        Scaleform::Memory::Free(utf8);
    }
}
#undef states
#undef hwnd
#undef vtable

// MS2-FUNCTIONAL: WM_IME_COMPOSITION of the Vista (TSF) IME object (vtbl 0x14313a450 slot 10). No flags: the
// composition goes through vtbl+0xb8. GCS_RESULTSTR: the result string is finalized into the IME manager and kept in
// its String at +0x98. CS_INSERTCHAR|CS_NOMOVECARET: wParam becomes a one-character composition. GCS_COMPSTR with
// GCS_CURSORPOS (unless mode 0xd00001): vtbl+0xb8 again. GCS_COMPATTR: sets the composition cursor, computes +0x64
// from the target clause, redraws the input window (vtbl+0xb0) and highlights each run of equal attributes.
// Reviewed branch by branch against the exe, same behaviour; the buffer sizes are 32-bit as in the exe. Left: the
// frame (exe 0xd8, ime spilled) and register allocation in the attribute loop (the exe counts a 64-bit trip count).
// @0x1423cfd50
void FUN_1423cfd50(long long* manager, unsigned long long wParam, unsigned long long flags)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
#define states reinterpret_cast<Scaleform::GFx::StateBag*>(*reinterpret_cast<unsigned char**>(self + 8) + 0x10)
#define hwnd (*reinterpret_cast<HWND*>(self + 0x28))
#define vtable (*reinterpret_cast<void***>(self))
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime = states->GetIMEManager();
    Scaleform::GFx::Value unused;
    if (!flags)
        reinterpret_cast<void(*)(void*, void*)>(vtable[0xb8 / sizeof(void*)])(self, self + 0x60);
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
    auto* attrs = static_cast<signed char*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(attrSize) + 1)));
    cx18_ImmGetCompositionStringW(context, GCS_COMPATTR, attrs, attrSize);
    unsigned length = *reinterpret_cast<unsigned*>(self + 0x60);
    if (static_cast<unsigned>(attrSize) < length) length = static_cast<unsigned>(attrSize);
    // The exe reads the reading string and frees it, then still passes the freed buffer to vtbl+0xb0 (which
    // ignores it).
    const LONG readSize = cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, nullptr, 0);
    auto* reading = static_cast<wchar_t*>(Scaleform::Memory::Alloc(static_cast<UPInt>(static_cast<unsigned>(readSize) * 2 + 2)));
    memset(reading, 0, static_cast<size_t>(static_cast<unsigned>(readSize) * 2));
    cx18_ImmGetCompositionStringW(context, GCS_COMPREADSTR, reading, readSize);
    reading[static_cast<unsigned>(readSize) >> 1] = 0;
    Scaleform::Memory::Free(reading);
    const SPInt cursor = cx18_ImmGetCompositionStringW(context, GCS_CURSORPOS, nullptr, 0);
    cx18_ImmReleaseContext(hwnd, context);
    ime->SetCursorInComposition(cursor);

    struct Segment { int start; int end; int attr; };
    ArrayData<Ime01Pod<0xc>, AllocatorGH_POD<Ime01Pod<0xc>>, ArrayDefaultPolicy> array;
    auto push = [&](const Segment& segment) {
        array.ResizeNoConstruct(&array, array.Size + 1);
        reinterpret_cast<Segment*>(array.Data)[array.Size - 1] = segment;
    };
    Segment current;
    current.attr = attrs[0];
    current.start = 0;
    unsigned char previous = static_cast<unsigned char>(attrs[0]);
    *reinterpret_cast<int*>(self + 0x64) = static_cast<int>(length - cursor);
    if (previous == ATTR_TARGET_CONVERTED || previous == ATTR_TARGET_NOTCONVERTED)
        *reinterpret_cast<unsigned*>(self + 0x64) = length;
    reinterpret_cast<void(*)(void*, void*)>(vtable[0xb0 / sizeof(void*)])(self, reading);
    unsigned remaining = length;
    for (int i = 0; i < static_cast<int>(length); ++i, --remaining) {
        if (static_cast<unsigned char>(attrs[i]) != previous) {
            push(current);
            if (attrs[i] == ATTR_TARGET_CONVERTED || attrs[i] == ATTR_TARGET_NOTCONVERTED)
                *reinterpret_cast<unsigned*>(self + 0x64) = remaining;
            previous = static_cast<unsigned char>(attrs[i]);
            current.attr = attrs[i];
            current.start = i;
        }
        current.end = i;
    }
    current.end = static_cast<int>(length) - 1;
    push(current);
    ime->SetCursorInComposition(cursor);
    auto* segments = reinterpret_cast<const Segment*>(array.Data);
    const UPInt count = array.Size;
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
}
#undef states
#undef hwnd
#undef vtable

// MS2-FUNCTIONAL: language-change handler (manager slot 7): updates the mode and locale label, resolves the layout's
// record text and conversion flags, and refreshes the IME version for flag-4 layouts. Left: the exe tests the device
// bits with mov/and eax where cl emits test ebx (1 byte shorter, so the loop alignment shifts), and register picks
// in the two record loops.
// @0x1423cbe90
void FUN_1423cbe90(long long* manager, unsigned language)
{
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    struct ProfileRecord { unsigned char pad[0x10]; String text1; String text2; unsigned mode; unsigned pad24; unsigned layout; unsigned pad2c; };
    auto* bytes = reinterpret_cast<unsigned char*>(manager);
    if (!manager[0xf]) return;
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned)>((*reinterpret_cast<void***>(manager))[4])(
        manager, static_cast<unsigned short>(language));
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(manager[0xf]), mode);
    wchar_t locale[0x104];
    if (!GetLocaleInfoW(language & 0xffff, LOCALE_SLANGUAGE, locale, 0x104)) {
        const DWORD error = GetLastError();
        reinterpret_cast<void(*)(void*, DWORD, const char*)>((*reinterpret_cast<void***>(manager))[0x78 / sizeof(void*)])(
            manager, error, "GFxIME Error: Error Initializing Input Language Name ");
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x60 / sizeof(void*)])(
            reinterpret_cast<void*>(manager[0xf]), "Unsupported");
        return;
    }
    reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(manager[0xf]))[0x78 / sizeof(void*)])(
        reinterpret_cast<void*>(manager[0xf]), String(locale).ToCStr());
    *reinterpret_cast<unsigned*>(bytes + 0x88) = 0x1000000;
    if (!(language & 0xe0000000)) {
        unsigned i = 0;
        for (; i < *reinterpret_cast<unsigned*>(bytes + 0x160); ++i) {
            if ((language >> 16) == reinterpret_cast<LayoutRecord*>(manager[0x2b])[i].layoutId) {
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager),
                              String(reinterpret_cast<LayoutRecord*>(manager[0x2b])[i].layoutText));
                FUN_1423cb660(manager);
                return;
            }
        }
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), String(locale));
    } else {
        for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
            if (language == reinterpret_cast<ProfileRecord*>(manager[0x17])[i].layout) {
                *reinterpret_cast<unsigned*>(bytes + 0x88) = reinterpret_cast<ProfileRecord*>(manager[0x17])[i].mode;
                if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 2)
                    FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager),
                                  reinterpret_cast<ProfileRecord*>(manager[0x17])[i].text2);
                if (reinterpret_cast<unsigned*>(manager[0x32])[i] == 1)
                    FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager),
                                  reinterpret_cast<ProfileRecord*>(manager[0x17])[i].text1);
                FUN_1423cb660(manager);
                *reinterpret_cast<unsigned*>(bytes + 0x188) = 0;
                if (*reinterpret_cast<unsigned*>(bytes + 0x88) == 4) {
                    const unsigned version = Ime01ImeVersion();
                    *reinterpret_cast<unsigned*>(bytes + 0x188) = version;
                    FUN_1423ca660(reinterpret_cast<void*>(manager[0xf]), version);
                }
                break;
            }
        }
        if (*reinterpret_cast<unsigned*>(bytes + 0x88) == 0x1000000)
            FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), String("Not Supported"));
    }
    const unsigned currentMode = *reinterpret_cast<unsigned*>(bytes + 0x84);
    if (currentMode == 0x400 || currentMode == 0x2000) return;
    const unsigned flags = *reinterpret_cast<unsigned*>(bytes + 0x88);
    if (flags == 0x1000000 || (flags & 0xf00000)) return;
    reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(manager[0xf]))[0x98 / sizeof(void*)])(
        reinterpret_cast<void*>(manager[0xf]));
}

// MS2-FUNCTIONAL: ITfInputProcessorProfileActivationSink::OnActivated: refreshes the mode and locale label, then
// resolves the activated TSF profile (or plain keyboard layout) to its record text and conversion flags. What is
// left: register allocation (the exe spills the language and keeps hkl in r14), the GUID_NULL compares, the profile
// slot (rbp+0x10 vs rbp+0) and the layout loop, which the exe does not strength-reduce.
// @0x1423d6c10
unsigned long long Ime01TsfSink::OnActivated(int profileType, unsigned short language,
                                long long* clsid, long long* catid, long long* guidProfile, unsigned long long hkl)
{
    long long raw = reinterpret_cast<long long>(this) + 8;   // the Ime01ProfileActivationSink view
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
    IUnknown* profiles;
    if (FAILED(CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr, CLSCTX_INPROC_SERVER,
                                kIIDProfiles, reinterpret_cast<void**>(&profiles)))) return 0;
    IUnknown* profileMgr;
    if (FAILED(profiles->QueryInterface(kIIDProfileMgr, reinterpret_cast<void**>(&profileMgr)))) return 0;
    Profile profile;
    if (profileType == 1) hkl = 0;
    reinterpret_cast<HRESULT(*)(void*, int, unsigned short, long long*, long long*, unsigned long long, Profile*)>(
        (*reinterpret_cast<void***>(profileMgr))[5])(profileMgr, profileType, language, clsid, guidProfile, hkl,
                                                    &profile);
    GUID empty = GUID_NULL;
    if (*reinterpret_cast<const GUID*>(profile.guidProfile) == empty &&
        *reinterpret_cast<const GUID*>(profile.catid) == empty &&
        !static_cast<unsigned long long>(static_cast<unsigned>(profile.hkl)))
        return 1;
    if (profileMgr) profileMgr->Release();
    if (!profiles) return 1;
    auto* manager = reinterpret_cast<long long*>(raw - 0x1a8);
    auto* bytes = reinterpret_cast<unsigned char*>(raw) - 0x1a8;
    auto field = [raw](int index) -> long long& { return reinterpret_cast<long long*>(raw)[index - 0x35]; };
    const unsigned mode = reinterpret_cast<unsigned(*)(void*, unsigned short)>(
        (*reinterpret_cast<void***>(manager))[4])(manager, language);
    wchar_t locale[0x104];
    GetLocaleInfoW(language, LOCALE_SLANGUAGE, locale, 0x104);
    *reinterpret_cast<unsigned*>(bytes + 0x84) = mode;
    if (void* provider = reinterpret_cast<void*>(field(0xf))) {
        FUN_1423ca560(reinterpret_cast<GFxIMEManagerWin32*>(provider), mode);
        String localeText(locale);
        provider = reinterpret_cast<void*>(field(0xf));
        reinterpret_cast<void(*)(void*, const char*)>((*reinterpret_cast<void***>(provider))[0x78 / sizeof(void*)])(
            provider, localeText.ToCStr());
    }
    reinterpret_cast<HRESULT(*)(void*, long long*, unsigned short, long long*, BSTR*)>(
        (*reinterpret_cast<void***>(profiles))[12])(profiles, clsid, language, guidProfile, &description);
    if (!SysStringLen(description)) {
        const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x160);
        field(0x33) = static_cast<long long>(hkl);
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), String(""));
        const unsigned long long current = static_cast<unsigned long long>(field(0x33));
        if (current != 0x4120412) {
            struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
            const auto* records = reinterpret_cast<const LayoutRecord*>(field(0x2b));
            bool imeLayout = false;
            for (unsigned i = 0; i < count; ++i) {
                if (static_cast<unsigned long long>(records[i].layoutId) == static_cast<unsigned>(current) &&
                    std::strlen(records[i].imeFile)) {
                    imeLayout = true;
                    break;
                }
            }
            if (!imeLayout) {
                FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), String(locale));
                goto release;
            }
        }
    }
    auto& flags = *reinterpret_cast<unsigned*>(bytes + 0x88);
    flags = 0x1000000;
    struct ProfileEntry { unsigned char pad[0x10]; String text1; String text2; unsigned flags; unsigned pad24; unsigned char* head; };
    unsigned i;
    for (i = 0; i < *reinterpret_cast<unsigned*>(bytes + 0xd0); ++i) {
        auto* entries = reinterpret_cast<ProfileEntry*>(field(0x17));
        for (auto* node = entries[i].head; node;
             node = *reinterpret_cast<unsigned char**>(node + 8)) {
            Profile candidate;
            std::memcpy(&candidate, *reinterpret_cast<void**>(node), 0x50);
            if (candidate.langid == language &&
                candidate.clsid[0] == static_cast<unsigned long long>(clsid[0]) &&
                candidate.clsid[1] == static_cast<unsigned long long>(clsid[1]) &&
                candidate.catid[0] == static_cast<unsigned long long>(catid[0]) &&
                candidate.catid[1] == static_cast<unsigned long long>(catid[1]) &&
                candidate.hkl == hkl &&
                candidate.guidProfile[0] == static_cast<unsigned long long>(guidProfile[0]) &&
                candidate.guidProfile[1] == static_cast<unsigned long long>(guidProfile[1]) &&
                candidate.hklSubstitute == profile.hklSubstitute)
                goto found;
        }
    }
    FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager), String("Not Supported"));
done:
    if (SysStringLen(description)) SysFreeString(description);
release:
    if (profiles) profiles->Release();
    return 1;
found:
    flags = reinterpret_cast<ProfileEntry*>(field(0x17))[i].flags;
    FUN_1423ca640(reinterpret_cast<void*>(field(0xf)), flags);
    if (reinterpret_cast<unsigned*>(field(0x32))[i] == 2)
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager),
                      reinterpret_cast<ProfileEntry*>(field(0x17))[i].text2);
    if (reinterpret_cast<unsigned*>(field(0x32))[i] == 1)
        FUN_1423ccdc0(reinterpret_cast<unsigned long long*>(manager),
                      reinterpret_cast<ProfileEntry*>(field(0x17))[i].text1);
    {
        void* provider = reinterpret_cast<void*>(field(0xf));
        reinterpret_cast<void(*)(void*)>((*reinterpret_cast<void***>(provider))[0x98 / sizeof(void*)])(provider);
    }
    goto done;
}

bool FUN_1423cb980(long long* manager, long long layouts, unsigned count);

// MS2-FUNCTIONAL: enumerates the installed keyboard layouts and TSF language profiles into the language list
// (+0x90 entries, "@@"-joined +0x70 names, +0x80 count) and refreshes the active layout, flags and mode.
// Left (3 lines): the exe compares the +0xd0 count with its zero register (edi) before the states loop, and loads
// the loaded flag (+0x14) and the language (+0x10) as [rax + r14]; ours uses the counter copy and [r14 + rax].
// The last four mode tests are written as byte offsets so their loads come out [r14 + rcx], as in the exe.
// @0x1423d8140
bool FUN_1423d8140(long long* manager)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    struct ImeRecord { unsigned char pad[0x20]; unsigned code; unsigned pad24; unsigned long long layoutId; };
    *reinterpret_cast<unsigned*>(self + 0x88) = 0x1000000;
    *reinterpret_cast<unsigned*>(self + 0x84) = 0x1000000;
    const unsigned count = static_cast<unsigned>(GetKeyboardLayoutList(0, nullptr));
    if (!count) {
        reinterpret_cast<void(*)(void*, const char*, const char*)>((*reinterpret_cast<void***>(manager))[0xe])(
            manager, "No IME's Installed!", "GFxIME Error");
    }
    auto* layouts = static_cast<unsigned long long*>(Scaleform::Memory::Alloc(count * sizeof(HKL)));
    GetKeyboardLayoutList(static_cast<int>(count), reinterpret_cast<HKL*>(layouts));
    // Each HKL goes through +0x198 with its high dword cleared and is written back.
    for (unsigned i = 0; i < count; ++i) {
        *reinterpret_cast<unsigned long long*>(self + 0x198) = layouts[i];
        *reinterpret_cast<unsigned*>(self + 0x19c) = 0;
        layouts[i] = *reinterpret_cast<unsigned long long*>(self + 0x198);
    }
    const bool registryFailed = (
        FUN_1423cb980)(manager, reinterpret_cast<long long>(layouts), count);
    Scaleform::Memory::Free(layouts);
    if (registryFailed) return registryFailed;

    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xd0); ++i)
        (*reinterpret_cast<unsigned**>(self + 0x190))[i] = 0;

    IUnknown* profiles;
    const HRESULT created = CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr,
        CLSCTX_INPROC_SERVER, *reinterpret_cast<const IID*>(&DAT_1431c5068), reinterpret_cast<void**>(&profiles));
    if (created < 0) {
        reinterpret_cast<void(*)(void*, HRESULT, const char*)>((*reinterpret_cast<void***>(manager))[0xf])(
            manager, created, "GFxIME Error: Failure to Initialize InputProcessorProfiles!");
    }
    if (created < 0 || !profiles) {
        // No TSF: list the loaded registry layouts by language, once per mode.
        for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x160); ++i) {
            if (!reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].loaded) continue;
            Ime01ModeRecord record;
            record.mode = 0x1000000;
            Scaleform::String name;
            if ((reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].layoutId & 0xfff) == 0x409) {
                record.mode = 0x10000000; name = "English";
            }
            if ((*reinterpret_cast<unsigned*>(i * sizeof(LayoutRecord) + *reinterpret_cast<unsigned long long*>(self + 0x158) + 0x10) & 0xfff) == 0x404) {
                record.mode = 9; name = "Chinese (Traditional)";
            }
            if ((*reinterpret_cast<unsigned*>(i * sizeof(LayoutRecord) + *reinterpret_cast<unsigned long long*>(self + 0x158) + 0x10) & 0xfff) == 0x804) {
                record.mode = 0x80000; name = "Chinese (Simplified)";
            }
            if ((*reinterpret_cast<unsigned*>(i * sizeof(LayoutRecord) + *reinterpret_cast<unsigned long long*>(self + 0x158) + 0x10) & 0xfff) == 0x412) {
                record.mode = 0x2000; name = "Korean";
            }
            if ((*reinterpret_cast<unsigned*>(i * sizeof(LayoutRecord) + *reinterpret_cast<unsigned long long*>(self + 0x158) + 0x10) & 0xfff) == 0x411) {
                record.mode = 0x400; name = "Japanese";
            }
            if (record.mode != 0x1000000) {
            bool listed = false;
            for (unsigned j = 0; j < *reinterpret_cast<unsigned long long*>(self + 0x98); ++j) {
                if ((*reinterpret_cast<Ime01ModeRecord**>(self + 0x90))[j].mode == record.mode) { listed = true; break; }
            }
            if (!listed) {
            record.language =
                reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].layoutId & 0xfff;
            record.text = static_cast<char*>(Scaleform::Memory::Alloc(name.GetSize() + 1));
            std::memcpy(record.text, name.ToCStr(), name.GetSize() + 1);
            Ime01PushModeRecord(reinterpret_cast<unsigned long long*>(self + 0x90), record);
            *reinterpret_cast<Scaleform::String*>(self + 0x70) += name + "@@";
            ++*reinterpret_cast<unsigned*>(self + 0x80);
            }
            }
        }
    } else {
        LANGID* languages;
        ULONG languageCount;
        if (reinterpret_cast<HRESULT(*)(void*, LANGID**, ULONG*)>((*reinterpret_cast<void***>(profiles))[15])(
                profiles, &languages, &languageCount) >= 0) {
            for (ULONG i = 0; i < languageCount; ++i) {
                wchar_t localeName[0x104];
                if (!GetLocaleInfoW(languages[i], LOCALE_SLANGUAGE, localeName, 0x104)) continue;
                IUnknown* profileEnum;
                reinterpret_cast<HRESULT(*)(void*, LANGID, IUnknown**)>((*reinterpret_cast<void***>(profiles))[16])(
                    profiles, languages[i], &profileEnum);
                // TF_LANGUAGEPROFILE: clsid, langid @0x10, catid @0x14, fActive @0x24, guidProfile @0x28.
                struct LanguageProfile { GUID clsid; LANGID langid; GUID catid; BOOL active; GUID guidProfile; };
                GUID none;
                *reinterpret_cast<unsigned long long*>(&none) = 0;
                LanguageProfile profile;
                profile.catid = none;
                profile.clsid = none;
                profile.guidProfile = none;
                profile.langid = languages[i];
                FUN_1423d7bc0(manager, &profile, localeName);
                BSTR description = SysAllocString(nullptr);
                Scaleform::String unused;
                if (profileEnum) {
                    while (reinterpret_cast<HRESULT(*)(void*, ULONG, void*, ULONG*)>(
                               (*reinterpret_cast<void***>(profileEnum))[4])(profileEnum, 1, &profile, nullptr) != 1) {
                        reinterpret_cast<HRESULT(*)(void*, const void*, LANGID, const void*, BSTR*)>(
                            (*reinterpret_cast<void***>(profiles))[12])(
                            profiles, &profile.clsid, profile.langid, &profile.guidProfile, &description);
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

    // Bind each loaded registry layout to its IME record; the active one supplies the flags.
    const unsigned long long active = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0));
    for (unsigned i = 0; i < *reinterpret_cast<unsigned long long*>(self + 0x160); ++i) {
        if (!reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].loaded) continue;
        const int index = reinterpret_cast<int(*)(void*, const char*, const char*)>(
            (*reinterpret_cast<void***>(manager))[16])(manager,
            reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].layoutText,
            reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].imeFile);
        if (index == -1) continue;
        reinterpret_cast<ImeRecord*>(*reinterpret_cast<void**>(self + 0xb8))[index].layoutId =
            reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].layoutId;
        *reinterpret_cast<unsigned long long*>(self + 0x198) =
            reinterpret_cast<LayoutRecord*>(*reinterpret_cast<void**>(self + 0x158))[i].layoutId;
        if (*reinterpret_cast<unsigned long long*>(self + 0x198) == active)
            *reinterpret_cast<unsigned*>(self + 0x88) =
                reinterpret_cast<ImeRecord*>(*reinterpret_cast<void**>(self + 0xb8))[index].code;
    }
    LANGID current;
    if (profiles)
        reinterpret_cast<HRESULT(*)(void*, LANGID*)>((*reinterpret_cast<void***>(profiles))[13])(profiles, &current);

    const unsigned long long language = reinterpret_cast<unsigned long long>(GetKeyboardLayout(0)) & 0xfff;
    *reinterpret_cast<unsigned*>(self + 0x84) = 0x1000000;
    *reinterpret_cast<unsigned long long*>(self + 0x198) = language;
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0x80); ++i) {
        const Ime01ModeRecord& entry = (*reinterpret_cast<Ime01ModeRecord**>(self + 0x90))[i];
        if (entry.language == language) *reinterpret_cast<unsigned*>(self + 0x84) = entry.mode;
    }
    return false;
}

// Enumerates HKLM\SYSTEM\CurrentControlSet\Control\Keyboard Layouts and appends one 0x18-byte record
// per layout to the array at +0x158: { UTF-8 "IME File", UTF-8 "Layout Text", layout id, whether the id is among the
// count loaded HKLs }. The subkey id is also parsed into +0x198. Per-subkey errors are logged and skipped; returns
// true when the root key cannot be opened or queried.
// @0x1423cb980
bool FUN_1423cb980(long long* manager, long long layouts, unsigned count)
{
    auto* self = reinterpret_cast<unsigned char*>(manager);
    auto logError = [](long long* m, DWORD e, const char* s) { reinterpret_cast<void(*)(void*, DWORD, const char*)>(
        (*reinterpret_cast<void***>(m))[0x78 / sizeof(void*)])(m, e, s); };
    struct LayoutRecord { char* imeFile; char* layoutText; unsigned layoutId; unsigned loaded; };
    DWORD subkeyCount = 0;
    ::Scaleform::String unused;
    HKEY root;
    LONG error = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts", 0,
                               KEY_READ, &root);
    if (error) {
        logError(manager, error, "GFxIME Error:Opening Registry Key failed ");
        return true;
    } else if (!root) return true;
    FILETIME written;
    error = RegQueryInfoKeyW(root, nullptr, nullptr, nullptr, &subkeyCount, nullptr, nullptr, nullptr, nullptr,
                             nullptr, nullptr, &written);
    if (error) {
        logError(manager, error, "GFxIME Error:Retrieving subkey information failed ");
        return true;
    }
    char keyName[0x400];
    wchar_t layoutText[0x400], imeFile[0x400];
    char layoutTextUtf8[0x800], imeFileUtf8[0x800];
    if (subkeyCount) for (DWORD i = 0; i < subkeyCount; ++i) { auto* const layoutId = reinterpret_cast<unsigned long long*>(self + 0x198);
        DWORD nameLength = 0x400, valueSize = 0x400;
        error = RegEnumKeyExA(root, i, keyName, &nameLength, nullptr, nullptr, nullptr, &written);
        if (error) {
            logError(manager, error, "GFxIME Error:Enumerating Registry Subkeys Failed ");
            continue;
        }
        sscanf(keyName, "%x", reinterpret_cast<unsigned*>(layoutId));
        HKEY subkey;
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
            if ((*layoutId & 0xe000000) == 0xe000000) {
                logError(manager, error,
                         (::Scaleform::String("GFxIME Error:Obtaining IME Filename failed for ") + keyName).ToCStr());
            }
            memset(imeFile, 0, sizeof(imeFile));
        }
        RegCloseKey(subkey);
        ::Scaleform::UTF8Util::EncodeString(layoutTextUtf8, layoutText, -1);
        ::Scaleform::UTF8Util::EncodeString(imeFileUtf8, imeFile, -1);
        LayoutRecord record;
        sscanf(keyName, "%x", &record.layoutId);
        const unsigned textSize = unsigned(strlen(layoutTextUtf8) + 1);
        record.layoutText = static_cast<char*>(::Scaleform::Memory::Alloc(textSize));
        if (record.layoutText) strcpy_s(record.layoutText, textSize, layoutTextUtf8);
        const unsigned imeSize = unsigned(strlen(imeFileUtf8) + 1);
        record.imeFile = static_cast<char*>(::Scaleform::Memory::Alloc(imeSize));
        if (record.imeFile) strcpy_s(record.imeFile, imeSize, imeFileUtf8);
        for (unsigned j = 0; j < count; ++j)
            if (reinterpret_cast<unsigned long long*>(layouts)[j] == *layoutId) { record.loaded = 1; goto recorded; }
        record.loaded = 0;
    recorded:

        auto* records = reinterpret_cast<unsigned long long*>(self + 0x158);   // { data, size, capacity }
        // ArrayData::ResizeNoConstruct(Size + 1), then the copy into the new last slot.
        const unsigned long long oldSize = records[1], size = oldSize + 1;
        if (size < oldSize) {
            if (size < (records[2] >> 1)) FUN_1423cc680(records, records, size);
        } else if (size >= records[2]) FUN_1423cc680(records, records, size + (size >> 2));
        records[1] = size;
        reinterpret_cast<LayoutRecord*>(records[0])[size - 1] = record;
    }
    RegCloseKey(root);
    return false;
}

// MS2-FUNCTIONAL: Vista provider slot 1 (table 0x14313b520): loads the registry layouts, lists each TSF language
// (FUN_1423d5d80) and registers every enabled or active keyboard profile with its IME record (FUN_1423cada0),
// chaining a copy of the profile onto the record's +0x28 list; the active profile sets +0x88 and the mode.
// Reviewed step by step against the exe, same behaviour. Like the exe it re-reads each COM vtable and the IME
// record array at every use, leaves the enumerator and GUID Data4 uninitialised, and returns through rax where
// the exe returns a bool (mov al). What remains is register colouring (the exe spills the loop index) and a
// frame 0x10 smaller (GS data 0x370).
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
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0xd0); ++i)
        (*reinterpret_cast<unsigned**>(self + 0x190))[i] = 0;

    IUnknown* profiles;
    if (FAILED(CoCreateInstance(*reinterpret_cast<const IID*>(&DAT_1431c4898), nullptr, CLSCTX_INPROC_SERVER,
                                kIIDProfiles, reinterpret_cast<void**>(&profiles))) || !profiles) return 1;
    IUnknown* profileMgr;
    const HRESULT queried = profiles->QueryInterface(kIIDProfileMgr, reinterpret_cast<void**>(&profileMgr));
    *reinterpret_cast<unsigned*>(self + 0x88) = 0x1000000;
    if (FAILED(queried) || !profileMgr) return 1;
#define IME01_VT(p) (*reinterpret_cast<void***>(p))

    Profile active;
    reinterpret_cast<HRESULT(*)(void*, const GUID&, Profile*)>(IME01_VT(profileMgr)[10])(profileMgr, kCategoryKeyboard, &active);
    LANGID* languages;
    ULONG languageCount;
    if (reinterpret_cast<HRESULT(*)(void*, LANGID**, ULONG*)>(IME01_VT(profiles)[15])(
            profiles, &languages, &languageCount) >= 0) {
        for (ULONG i = 0; i < languageCount; ++i) {
            wchar_t localeName[0x104];
            if (!GetLocaleInfoW(languages[i], LOCALE_SLANGUAGE, localeName, 0x104)) continue;
            IUnknown* profileEnum;   // not nulled, as in the exe: a failed EnumProfiles leaves it unset
            reinterpret_cast<HRESULT(*)(void*, LANGID, IUnknown**)>(IME01_VT(profileMgr)[6])(
                profileMgr, languages[i], &profileEnum);
            // only Data1..Data3 of the zero GUID are written; the exe copies Data4 uninitialised
            GUID zero;
            zero.Data1 = 0;
            zero.Data2 = 0;
            zero.Data3 = 0;
            Profile profile;
            profile.category = zero;
            profile.clsid = zero;
            profile.guidProfile = zero;
            profile.language = languages[i];
            FUN_1423d5d80(manager, &profile, localeName);
            BSTR description = SysAllocString(nullptr);
            Scaleform::String layoutText;
            Scaleform::String imeFile;
            if (profileEnum) {
                while (reinterpret_cast<HRESULT(*)(void*, ULONG, Profile*, ULONG*)>(IME01_VT(profileEnum)[4])(
                           profileEnum, 1, &profile, nullptr) == S_OK) {
                    SysFreeString(description);
                    layoutText.Clear();
                    reinterpret_cast<HRESULT(*)(void*, const GUID&, LANGID, const GUID&, BSTR*)>(IME01_VT(profiles)[12])(
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
                    if (!(profile.flags & 2) && !(profile.flags & 1)) continue;
                    {
                        const HKL hkl = profile.hkl;
                        const HKL substitute = profile.hklSubstitute;
                        if (!hkl && !substitute) {
                            layoutText = description;
                            goto registered;
                        }
                        // Match a registry layout: the Korean IME by its low word, others by HKL or substitute.
                        struct LayoutEntry { const char* imeFile; const char* layoutText; unsigned id; unsigned loaded; };
                        const LayoutEntry* layouts = *reinterpret_cast<LayoutEntry* const*>(self + 0x158);
                        const unsigned long long layoutCount = *reinterpret_cast<unsigned long long*>(self + 0x160);
                        const ULONG_PTR hkl32 = static_cast<unsigned>(reinterpret_cast<ULONG_PTR>(hkl));
                        for (unsigned j = 0; j < layoutCount; ++j) {
                            if (hkl32 == 0x4120412) {
                                if ((reinterpret_cast<ULONG_PTR>(hkl) & 0xffff) == layouts[j].id) {
                                    layoutText = layouts[j].layoutText;
                                    goto registered;
                                }
                            } else if (hkl32 == layouts[j].id
                                       || static_cast<ULONG_PTR>(static_cast<unsigned>(reinterpret_cast<ULONG_PTR>(substitute))) == layouts[j].id) {
                                layoutText = layouts[j].layoutText;
                                imeFile = (*reinterpret_cast<LayoutEntry* const*>(self + 0x158))[j].imeFile;
                                if (imeFile.IsEmpty()) goto rejected;
                                if (layoutText.IsEmpty() && description) layoutText = description;
                                goto registered;
                            }
                        }
                    }
                rejected:
                    if (profile.flags & 1) *reinterpret_cast<unsigned*>(self + 0x88) = 0x3000000;
                    continue;
                registered:
                    if (layoutText.IsEmpty()) continue;
                    const int index = FUN_1423cada0(reinterpret_cast<unsigned long long*>(manager),
                        layoutText.ToCStr(), imeFile.ToCStr(), profile.language);
#define IME01_LOG (*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 0x78) + 0x60))
                    if (IME01_LOG) {
                        FUN_1423cd060(IME01_LOG, (Scaleform::String("Registering IME: ") + layoutText +
                            Scaleform::String("\n")).ToCStr());
                    }
                    imeFile.Clear();
                    layoutText.Clear();
                    if (index == -1) continue;
                    auto* copy = static_cast<Profile*>(Scaleform::Memory::Alloc(sizeof(Profile)));
                    *copy = profile;
                    auto* node = static_cast<void**>(Scaleform::Memory::Alloc(0x10));
                    // the IME records (0x30 each): +0x20 mode, +0x28 profile list; the array is re-read at each use
                    struct ImeRecord { unsigned char pad[0x20]; unsigned mode; unsigned pad24; void* profiles; };
#define IME01_RECORD (*reinterpret_cast<ImeRecord**>(self + 0xb8))[index]
                    node[0] = copy;
                    node[1] = IME01_RECORD.profiles;
                    IME01_RECORD.profiles = node;
                    if (profile.flags & 1) *reinterpret_cast<unsigned*>(self + 0x88) = IME01_RECORD.mode;
#undef IME01_RECORD
                }
                profileEnum->Release();
            }
            SysFreeString(description);
            description = nullptr;
        }
        CoTaskMemFree(languages);
    }

    auto* entries = *reinterpret_cast<unsigned char**>(self + 0x90);
    for (unsigned i = 0; i < *reinterpret_cast<unsigned*>(self + 0x80); ++i) {
        if (*reinterpret_cast<unsigned long long*>(entries + i * 0x20ull + 0x18) == active.language)
            *reinterpret_cast<unsigned*>(self + 0x84) = *reinterpret_cast<unsigned*>(entries + i * 0x20ull + 0x10);
    }
    if (profiles) profiles->Release();
    if (profileMgr) profileMgr->Release();
    return 0;
#undef IME01_LOG
#undef IME01_VT
}

// TSF BeginUIElement on the UI-element sink. Clears the manager's +0xc0 flag and the sink's candidate
// state at +0x70..+0xa1 and sets *show = FALSE. Unless the manager is in mode 0x1000000/0x2000000 or its vtable +0x30
// check fails, it bumps the manager's +0xbc counter and, when the manager's String at +0x10 is not empty, calls
// RemoveList() and then CreateList(10.0, 1.0). It clears the sink's +0x55/+0x56 flags and walks the enumerator from
// the first method of the thread manager's IID ba468c55 interface, calling each element's first method.
// @0x1423da440
unsigned long long Ime01TsfUiSink::BeginUIElement(unsigned long long, unsigned* result)
{
    long long raw = reinterpret_cast<long long>(this) + 8;   // the Ime01UIElementSink view
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    static const GUID kProfileIid = { 0xba468c55, 0x9956, 0x4fb1, { 0xa5, 0x9d, 0x52, 0xa7, 0xdd, 0x7c, 0xc6, 0xaa } };
    auto* self = reinterpret_cast<unsigned char*>(raw);
    auto manager = [self] { return *reinterpret_cast<unsigned char**>(self + 8); };
    manager()[0xc0] = 0;
    std::memset(self + 0x70, 0, 0x32);
    *result = 0;
    const unsigned mode = *reinterpret_cast<unsigned*>(manager() + 0x98);
    if (((mode - 0x1000000) & 0xfeffffff) == 0) return 0;
    if (!reinterpret_cast<bool(*)(void*, void*)>((*reinterpret_cast<void***>(manager()))[0x30 / sizeof(void*)])(
            manager(), *reinterpret_cast<void**>(manager() + 8)))
        return 0;
    ++*reinterpret_cast<int*>(manager() + 0xbc);
    if (reinterpret_cast<Scaleform::String*>(manager() + 0x10)->GetLength()) {
        Scaleform::GFx::Value invokeResult;
        Ime01ValueArgs args;
        Ime01PushArgCall(args, Scaleform::GFx::Value(10.0));
        Ime01PushArgCall(args, Scaleform::GFx::Value(1.0));
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager() + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "RemoveList", &invokeResult, nullptr, 0);
        if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(manager() + 0xa8) + 0x18))
            reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                bridge, "CreateList", &invokeResult, args.data, 2);
    }
    void* owner = *reinterpret_cast<void**>(manager() + 8);
    Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> ime =
        reinterpret_cast<Scaleform::GFx::StateBag*>(static_cast<unsigned char*>(owner) + 0x10)->GetIMEManager();
    IUnknown* threadManager = *reinterpret_cast<IUnknown**>(self + 0x20);
    self[0x55] = 0;
    self[0x56] = 0;
    IUnknown* profiles;
    if (threadManager->QueryInterface(kProfileIid, reinterpret_cast<void**>(&profiles)) >= 0 && profiles) {
        IUnknown* items;
        if (reinterpret_cast<HRESULT(*)(IUnknown*, IUnknown**)>((*reinterpret_cast<void***>(profiles))[3])(
                profiles, &items) == S_OK) {
            typedef HRESULT (*NextFn)(IUnknown*, ULONG, IUnknown**, ULONG*);
            IUnknown* item;
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

// The exe keeps an unreferenced `vector destructor iterator' (0x1423c8fa0) in this unit: some Value[2] local was
// destroyed through it. CreateList below now builds its arguments with PushBack as the exe does, so this
// never-called helper keeps that iterator emitted.
__declspec(noinline) void Ime01KeepValueArrayDtor()
{
    Scaleform::GFx::Value values[2];
}

// MS2-FUNCTIONAL: TSF UpdateUIElement on the IME UI-element sink. It gets the element from ITfUIElementMgr. A reading
// element copies its reading string to the manager's String at +0xb0 and calls MakeInvisible, plus RemoveList when
// the sink's +0x55 flag is set. A candidate-list element first calls CreateList(10.0, 0/1) once. It then reads the
// current page's range (GetPageIndex / GetCurrentPage / GetSelection), selects the item, and refills the manager's
// candidate list at +0x30 with the page's strings as UTF-8. The COM calls go through the same pointers the exe uses:
// the GetUIElement result for GetPageIndex(NULL, 0, &n), GetUpdatedFlags and GetString, and the QI'd candidate
// pointer for the rest.
// @0x1423db0c0
unsigned long long Ime01TsfUiSink::UpdateUIElement(unsigned message)
{
    long long raw = reinterpret_cast<long long>(this) + 8;   // the Ime01UIElementSink view
    typedef void (*InvokeFn)(void*, const char*, Scaleform::GFx::Value*, Scaleform::GFx::Value*, unsigned);
    static const GUID kUIElementMgrIid = { 0xea1ea135, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    static const GUID kCandidateListIid = { 0xea1ea138, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    static const GUID kReadingInfoIid = { 0xea1ea139, 0x19df, 0x11d7, { 0xa6, 0xd2, 0x00, 0x06, 0x5b, 0x84, 0x43, 0x5c } };
    auto* self = reinterpret_cast<unsigned char*>(raw);
    const unsigned id = message;
    IUnknown* uiManager = nullptr;
    IUnknown* element = nullptr;
    BSTR readingText = nullptr;
    UINT count = 0;
    BSTR description = nullptr;
    IUnknown* reading = nullptr;
    IUnknown* candidates = nullptr;
    GUID guid;
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
            if (!owner[0xb8]) {
                *reinterpret_cast<Scaleform::String*>(owner + 0xb0) = static_cast<const wchar_t*>(readingText);
            } else {
                *reinterpret_cast<Scaleform::String*>(owner + 0xb0) = static_cast<const wchar_t*>(readingText);
                owner = *reinterpret_cast<unsigned char**>(self + 8);
                reinterpret_cast<void(*)(void*, const wchar_t*)>((*reinterpret_cast<void***>(owner))[0xb0 / sizeof(void*)])(
                    owner, readingText);
            }
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
            Ime01ValueArgs args;
            Scaleform::GFx::Value result;
            Ime01PushArgCall(args, Scaleform::GFx::Value(10.0));
            Ime01PushArgCall(args, Scaleform::GFx::Value(static_cast<double>(vertical)));
            if (void* bridge = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(
                    *reinterpret_cast<unsigned char**>(self + 8) + 0xa8) + 0x18))
                reinterpret_cast<InvokeFn>((*reinterpret_cast<void***>(bridge))[0x78 / sizeof(void*)])(
                    bridge, "CreateList", &result, args.data, 2);
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
                FUN_1423d9490(*reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(self + 8) + 0x30), &retained, 0);
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

// Maps the executable's IME conversion-mode bits to the language code they imply.
// @0x1423cb5b0
unsigned FUN_1423cb5b0(void*, unsigned flags)
{
    if (flags & 0xf00) return 0x400;
    if (flags & 0xf000) return 0x2000;
    if (flags & 0x10000000) return 0x10000000;
    if (flags & 0xf) return 9;
    return (flags & 0xf0000) ? 0x80000 : 0x1000000;
}

// Looks up the language code of an installed input-language record by its id.
// @0x1423cb600
unsigned FUN_1423cb600(void* self, long long id)
{
    struct LangRecord { UByte pad[0x10]; unsigned code; unsigned pad14; unsigned id; unsigned pad1c; };
    for (unsigned i = 0; i < *(unsigned*)((UByte*)self + 0x80); ++i) {
        if ((unsigned)id == (*(LangRecord**)((UByte*)self + 0x90))[i].id) return (*(LangRecord**)((UByte*)self + 0x90))[i].code;
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

// Forwards the IME command to the command map embedded at +0x38.
// @0x1423cf1a0
bool FUN_1423cf1a0(void* self, long long operation, const char* key, unsigned long long flags)
{
    return FUN_1423d8d60((Ime01CmdMap*)((UByte*)self + 0x38), operation, key, flags);
}

// Forwards the IME command to the command map embedded at +0x38.
// @0x1423d3110
bool FUN_1423d3110(void* self, long long operation, const char* key, unsigned long long flags)
{
    return FUN_1423d8d60((Ime01CmdMap*)((UByte*)self + 0x38), operation, key, flags);
}

// Enables or disables the window's default input context (IACE_DEFAULT when enabled).
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
long long Ime01TsfUiSink::OnInitDocumentMgr(void*) { return 0; }
// @0x1423dad90
long long Ime01TsfUiSink::OnPopContext(void*) { return 0; }
// @0x1423dada0
long long Ime01TsfUiSink::OnPushContext(void*) { return 0; }
// @0x1423dadb0
long long Ime01TsfUiSink::OnSetFocus(void*, void*) { return 0; }
// @0x1423dadc0
long long Ime01TsfUiSink::OnUninitDocumentMgr(void*) { return 0; }

// Assigns the name string held at +0x20.
// @0x1423d0f40
void FUN_1423d0f40(void* self, const char* text)
{
    *(String*)((UByte*)self + 0x20) = text;
}

// Assigns the name string held at +0x18.
// @0x1423d0f50
void FUN_1423d0f50(void* self, const char* text)
{
    *(String*)((UByte*)self + 0x18) = text;
}

// Stores the three candidate-window settings.
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

// Clears the second field, then calls the object's own virtual slot 0x80.
// @0x1423d1890
void FUN_1423d1890(void* self)
{
    ((void**)self)[1] = nullptr;
    typedef void (*Fn)(void*);
    (*(Fn*)(*(UByte**)self + 0x80))(self);
}

// AddRef on the refcount at +0x14.
// @0x1423d5ae0
__declspec(noinline) int Ime01TsfSink::AddRef()
{
    void* self = this;
    return ++*(int*)((UByte*)self + 0x14);
}

// Returns the language code of the named IME, else of the current input language.
// @0x1423d61c0
unsigned FUN_1423d61c0(void* self, const char* name)
{
    if (name) return FUN_1423cb400(self, name);
    if (*(unsigned*)((UByte*)self + 0x84) == 0x2000000) return 0x1000000;
    return *(unsigned*)((UByte*)self + 0x88);
}

// The same body as FUN_1423d61c0, slot 2 of the 17-slot table at 0x143138530.
// @0x1423d7dc0
unsigned FUN_1423d7dc0(void* self, const char* name)
{
    if (name) return FUN_1423cb400(self, name);
    if (*(unsigned*)((UByte*)self + 0x84) == 0x2000000) return 0x1000000;
    return *(unsigned*)((UByte*)self + 0x88);
}

// Release on the refcount at +0x14.
// @0x1423d7350
__declspec(noinline) int Ime01TsfSink::Release()
{
    void* self = this;
    return --*(int*)((UByte*)self + 0x14);
}

// Refreshes the conversion-state labels with every conversion bit set.
// @0x1423d7410
void FUN_1423d7410(void* self)
{
    FUN_1423cc7c0(self, 0xffffffffu);
}

// Returns the IME callback-name table (the records after the count in DAT_143a2a6b4's image).
// @0x1423da240
const void* FUN_1423da240(void*)
{
    return (const UByte*)&DAT_143a2a6b4 + 0xc;
}

// AddRef on the refcount at +0x3c.
// @0x1423da420
__declspec(noinline) int Ime01TsfUiSink::AddRef()
{
    void* self = this;
    return ++*(int*)((UByte*)self + 0x3c);
}

// (0x1423db880 / 0x1423db88c / 0x1423db898 are cl's AvmMovieClip ??_E adjustor thunks for its +0x30 / +0x40 / +0x48
// parts, emitted by Ime01EmitAvmMovieClipVftables at the end of the file)

}}}

// AvmMovieClip (as3_avm.h): the exe keeps its deleting destructor 0x1423dbb60 and the ??_E adjustor thunks
// 0x1423db880/88c/898 in this TU, so a copy-construct anchor makes cl emit its vftables, ??_G and thunks here.
namespace Scaleform { namespace GFx { namespace IME {
void Ime01EmitAvmMovieClipVftables(void* p, const AS3::AvmMovieClip* pclip)
{
    ::new (p) AS3::AvmMovieClip(*pclip);
}
}}}

// The TSF sink embedded at +0x1a0 of the IME manager: a compartment event sink (OnChange 0x1423d70d0) at +0 and a
// profile activation sink (0x1423d6c10) at +8, with the cookie at +0x10 and the refcount at +0x14. The exe's
// vftables 0x14313b5a0 / 0x14313b5c0 are cl's, and the second one's QueryInterface/AddRef/Release are cl's adjustor
// thunks 0x1423d7344 / 0x1423d5aec / 0x1423d735c. The overriders are defined earlier in the file (class definition
// before FUN_1423d72a0), each at its exe VA; Ime01EmitTsfSinkVftables copy-constructs one so cl emits the vftables and thunks here. The
// manager's ctor FUN_1423d54d0 and dtor FUN_1423d56b0 build/tear down the sink embedded at +0x1a0 with its inline ctor/dtor.
namespace Scaleform { namespace GFx { namespace IME {
void Ime01EmitTsfSinkVftables(void* p, const Ime01TsfSink* psink)
{
    ::new (p) Ime01TsfSink(*psink);
}
}}}
// The TSF UI-element sink object built by FUN_1423da250 (0x110 bytes, refcount at +0x3c): a thread-manager event
// sink at +0 (exe vftable 0x14313b920: QI 0x1423dadd0, AddRef 0x1423da420, Release 0x1423daeb0, the five S_OK
// callbacks, then the deleting destructor 0x1423da2c0) and a UI-element sink at +8 (0x14313b968: cl's this-8
// thunks 0x1423dae98 / 0x1423da42c / 0x1423daed8, then Begin/Update/EndUIElement). The overriders are defined earlier
// in the file at their exe VAs. The destructor slot is a plain virtual, DeletingDestructor, so the hand-written
// ??_G body (0x1423da2c0, exact) stays the definition; it calls the inline ~Ime01TsfUiSink for the two vptr stores. Ime01EmitTsfUiSinkVftables copy-constructs one
// so cl emits the vftables and thunks here.
namespace Scaleform { namespace GFx { namespace IME {
void Ime01EmitTsfUiSinkVftables(void* p, const Ime01TsfUiSink* psink)
{
    ::new (p) Ime01TsfUiSink(*psink);
}
}}}
// MS2-PIN: ??_7MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c0a8
// MS2-PIN: ??_7HeapLimit@MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c090
// MS2-PIN: ??_7MemoryContext@GFx@Scaleform@@6B@ 0x14313ba60
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Ime01Pod@$0M@@IME@GFx@Scaleform@@U?$AllocatorGH_POD@U?$Ime01Pod@$0M@@IME@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1423d1240
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Ime01Pod@$0BA@@IME@GFx@Scaleform@@U?$AllocatorGH_POD@U?$Ime01Pod@$0BA@@IME@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1423cc720
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Ime01Pod@$0BI@@IME@GFx@Scaleform@@U?$AllocatorGH_POD@U?$Ime01Pod@$0BI@@IME@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1423cc680
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Ime01Pod@$0CA@@IME@GFx@Scaleform@@U?$AllocatorGH_POD@U?$Ime01Pod@$0CA@@IME@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1423d12e0
// MS2-PIN: ?Reserve@?$ArrayDataBase@VValue@GFx@Scaleform@@U?$AllocatorGH@VValue@GFx@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x1423d7370
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAXU?$AllocatorLH_POD@PEAX$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1423d95f0
// MS2-PIN: ?Reserve@?$ArrayDataBase@_WU?$AllocatorLH_POD@_W$0CAB@@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1423d1380
// MS2-PIN: ?Reserve@?$ArrayDataBase@_WU?$AllocatorLH_POD@_W$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1423d5340
// MS2-PIN: ?setRawCapacity@?$HashSetBase@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@U5634@U?$AllocatorLH@PEAUDOMStringNode@XML@GFx@Scaleform@@$0CAB@@4@V?$HashsetEntry@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@@4@@Scaleform@@AEAAXPEAX_K@Z 0x1423cce50
// MS2-PIN: ??$Add@PEAUDOMStringNode@XML@GFx@Scaleform@@@?$HashSetBase@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@U5634@U?$AllocatorLH@PEAUDOMStringNode@XML@GFx@Scaleform@@$0CAB@@4@V?$HashsetEntry@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@@4@@Scaleform@@QEAAXPEAXAEBQEAUDOMStringNode@XML@GFx@1@@Z 0x1423ca950
// MS2-PIN: ??$add@PEAUDOMStringNode@XML@GFx@Scaleform@@@?$HashSetBase@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@U5634@U?$AllocatorLH@PEAUDOMStringNode@XML@GFx@Scaleform@@$0CAB@@4@V?$HashsetEntry@PEAUDOMStringNode@XML@GFx@Scaleform@@UIme01NodeHash@IME@34@@4@@Scaleform@@AEAAXPEAXAEBQEAUDOMStringNode@XML@GFx@1@_K@Z 0x1423caa80
// AvmMovieClip's vftables (also emitted by sfr_as3_16), its deleting destructor and adjustor thunks.
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14313bcd8
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14313bdd0
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmDisplayObjContainer@123@@ 0x14313be88
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmSpriteBase@23@@ 0x14313bf48
// MS2-PIN: ??_GAvmMovieClip@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1423dbb60
// MS2-PIN: ??_EAvmMovieClip@AS3@GFx@Scaleform@@WDA@EAAPEAXI@Z 0x1423db880
// MS2-PIN: ??_EAvmMovieClip@AS3@GFx@Scaleform@@WEA@EAAPEAXI@Z 0x1423db88c
// MS2-PIN: ??_EAvmMovieClip@AS3@GFx@Scaleform@@WEI@EAAPEAXI@Z 0x1423db898
// Ime01TsfSink's vftables and the adjustor thunks of its profile activation sink.
// MS2-PIN: ??_7Ime01TsfSink@IME@GFx@Scaleform@@6BIme01CompartmentEventSink@123@@ 0x14313b5a0
// MS2-PIN: ??_7Ime01TsfSink@IME@GFx@Scaleform@@6BIme01ProfileActivationSink@123@@ 0x14313b5c0
// MS2-PIN: ?QueryInterface@Ime01TsfSink@IME@GFx@Scaleform@@W7EAAJPEB_KPEAPEAX@Z 0x1423d7344
// MS2-PIN: ?AddRef@Ime01TsfSink@IME@GFx@Scaleform@@W7EAAHXZ 0x1423d5aec
// MS2-PIN: ?Release@Ime01TsfSink@IME@GFx@Scaleform@@W7EAAHXZ 0x1423d735c
// AvmMovieClip's base-class vftables, emitted here through its copy-construct anchor.
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObjContainerBase@GFx@Scaleform@@6B@ 0x14317c0a0
// MS2-PIN: ??_7AvmSpriteBase@GFx@Scaleform@@6B@ 0x14317c898
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cb30
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317cbe8
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cce0
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6B@ 0x14317cd98
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ce80
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cf78
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmDisplayObjContainer@123@@ 0x14317d030
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmSpriteBase@23@@ 0x14317d0f0
// Ime01TsfUiSink's vftables and the adjustor thunks of its UI-element sink.
// MS2-PIN: ??_7Ime01TsfUiSink@IME@GFx@Scaleform@@6BIme01ThreadMgrEventSink@123@@ 0x14313b920
// MS2-PIN: ??_7Ime01TsfUiSink@IME@GFx@Scaleform@@6BIme01UIElementSink@123@@ 0x14313b968
// MS2-PIN: ?QueryInterface@Ime01TsfUiSink@IME@GFx@Scaleform@@W7EAAJPEB_KPEAPEAX@Z 0x1423dae98
// MS2-PIN: ?AddRef@Ime01TsfUiSink@IME@GFx@Scaleform@@W7EAAHXZ 0x1423da42c
// MS2-PIN: ?Release@Ime01TsfUiSink@IME@GFx@Scaleform@@W7EAAHXZ 0x1423daed8
