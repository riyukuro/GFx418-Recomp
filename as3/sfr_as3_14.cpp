// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_14
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424bb1f0-0x1424c91f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/gfx_imemanager.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/kernel/sf_wstring.h"

#if defined(__clang__)
#define SFR14_INSTANCE_CTOR
#else
#define SFR14_INSTANCE_CTOR inline
#endif

// Traits::GetConstructor, out of line in the exe (the InstanceTraits copy).
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);

namespace Scaleform {
// The ByteArray storage grows through this out of line (0x1424beea0) in the exe.
template <> inline SF_NOINLINE void ArrayBase<ArrayData<UInt8, AllocatorLH_POD<UInt8>, ArrayDefaultPolicy> >::Resize(UPInt newSize)
{
    Data.Resize(newSize);
}
}

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424c0d70: Classes::fl_gfx::FocusManager::getFocus
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 7, SPtr<Instances::fl_display::InteractiveObject>, UInt32>;
// thunk 0x1424c0e70: Classes::fl_gfx::FocusManager::numFocusGroupsGet
template struct ThunkFunc0<Classes::fl_gfx::FocusManager, 8, UInt32>;
// thunk 0x1424c0ed0: Classes::fl_gfx::FocusManager::setFocusGroupMask
template struct ThunkFunc2<Classes::fl_gfx::FocusManager, 9, const Value, Instances::fl_display::InteractiveObject*, UInt32>;
// thunk 0x1424c0f80: Classes::fl_gfx::FocusManager::getFocusGroupMask
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 10, UInt32, Instances::fl_display::InteractiveObject*>;
// thunk 0x1424c1020: Classes::fl_gfx::FocusManager::setControllerFocusGroup
template struct ThunkFunc2<Classes::fl_gfx::FocusManager, 11, bool, UInt32, UInt32>;
// thunk 0x1424c1120: Classes::fl_gfx::FocusManager::getControllerFocusGroup
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 12, UInt32, UInt32>;
// thunk 0x1424c11d0: Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 13, UInt32, UInt32>;
// thunk 0x1424c1430: Classes::fl_gfx::FocusManager::getModalClip
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 14, SPtr<Instances::fl_display::Sprite>, UInt32>;
// thunk 0x1424c1530: Classes::fl_gfx::FocusManager::setModalClip
template struct ThunkFunc2<Classes::fl_gfx::FocusManager, 15, const Value, Instances::fl_display::Sprite*, UInt32>;
// thunk 0x1424c1860: Classes::fl_gfx::IMEEx::getIMECandidateListStyle
template struct ThunkFunc0<Classes::fl_gfx::IMEEx, 0, SPtr<Instances::fl_gfx::IMECandidateListStyle>>;
// thunk 0x1424c1910: Classes::fl_gfx::IMEEx::setIMECandidateListStyle
template struct ThunkFunc1<Classes::fl_gfx::IMEEx, 1, const Value, Instances::fl_gfx::IMECandidateListStyle*>;
// thunk 0x1424c1950: Classes::fl_gfx::IMEEx::SendLangBarMessage
// MS2-FUNCTIONAL: not matched: the exe keeps the VM in rdi across the conversions (frame 0x70 + push rdi)
template struct ThunkFunc3<Classes::fl_gfx::IMEEx, 2, const Value, Instances::fl_display::Sprite*, const ASString&, const ASString&>;
// thunk 0x1424c1b60: Classes::fl_gfx::IMEEx::GetOSVersion
template struct ThunkFunc0<Classes::fl_gfx::IMEEx, 3, ASString>;
// thunk 0x1424c1bd0: Classes::fl_gfx::IMEEx::GetCompositionString
template struct ThunkFunc0<Classes::fl_gfx::IMEEx, 4, ASString>;
// thunk 0x1424c1da0: Classes::fl_gfx::TextFieldEx::appendHtml
template struct ThunkFunc2<Classes::fl_gfx::TextFieldEx, 0, const Value, Instances::fl_text::TextField*, const ASString&>;
// thunk 0x1424c1ed0: Classes::fl_gfx::TextFieldEx::setVerticalAlign
template struct ThunkFunc2<Classes::fl_gfx::TextFieldEx, 1, const Value, Instances::fl_text::TextField*, const ASString&>;
// thunk 0x1424c2000: Classes::fl_gfx::TextFieldEx::getVerticalAlign
template struct ThunkFunc1<Classes::fl_gfx::TextFieldEx, 2, ASString, Instances::fl_text::TextField*>;
// thunk 0x1424c20a0: Classes::fl_gfx::TextFieldEx::setTextAutoSize
template struct ThunkFunc2<Classes::fl_gfx::TextFieldEx, 3, const Value, Instances::fl_text::TextField*, const ASString&>;
// thunk 0x1424c21d0: Classes::fl_gfx::TextFieldEx::getTextAutoSize
template struct ThunkFunc1<Classes::fl_gfx::TextFieldEx, 4, ASString, Instances::fl_text::TextField*>;
// thunk 0x1424c2270: Classes::fl_gfx::TextFieldEx::setIMEEnabled
template struct ThunkFunc2<Classes::fl_gfx::TextFieldEx, 5, const Value, Instances::fl_text::TextField*, bool>;
// thunk 0x1424c2300: Classes::fl_gfx::TextFieldEx::setImageSubstitutions
template struct ThunkFunc2<Classes::fl_gfx::TextFieldEx, 6, const Value, Instances::fl_text::TextField*, const Value&>;
// thunk 0x1424c2490: Classes::fl_gfx::TextFieldEx::updateImageSubstitution
// MS2-FUNCTIONAL: not matched: register allocation of the two-pointer, string-argument form differs
template struct ThunkFunc3<Classes::fl_gfx::TextFieldEx, 7, const Value, Instances::fl_text::TextField*, const ASString&, Instances::fl_display::BitmapData*>;
// thunk 0x1424c2610: Classes::fl_gfx::Extensions::enabledSet
template struct ThunkFunc1<Classes::fl_gfx::Extensions, 0, const Value, bool>;
// thunk 0x1424c2670: Classes::fl_gfx::Extensions::enabledGet
template struct ThunkFunc0<Classes::fl_gfx::Extensions, 1, bool>;
// thunk 0x1424c26d0: Classes::fl_gfx::Extensions::noInvisibleAdvanceSet
template struct ThunkFunc1<Classes::fl_gfx::Extensions, 2, const Value, bool>;
// thunk 0x1424c2730: Classes::fl_gfx::Extensions::noInvisibleAdvanceGet
template struct ThunkFunc0<Classes::fl_gfx::Extensions, 3, bool>;
// thunk 0x1424c2790: Classes::fl_gfx::Extensions::getTopMostEntity
template struct ThunkFunc3<Classes::fl_gfx::Extensions, 4, SPtr<Instances::fl_display::DisplayObject>, Value::Number, Value::Number, bool>;
// thunk 0x1424c2920: Classes::fl_gfx::Extensions::getMouseTopMostEntity
template struct ThunkFunc2<Classes::fl_gfx::Extensions, 5, SPtr<Instances::fl_display::DisplayObject>, bool, UInt32>;
// thunk 0x1424c2a70: Classes::fl_gfx::Extensions::setMouseCursorType
template struct ThunkFunc2<Classes::fl_gfx::Extensions, 6, const Value, const ASString&, UInt32>;
// thunk 0x1424c2bc0: Classes::fl_gfx::Extensions::getMouseCursorType
template struct ThunkFunc1<Classes::fl_gfx::Extensions, 7, ASString, UInt32>;
// thunk 0x1424c2c70: Classes::fl_gfx::Extensions::getEdgeAAMode
template struct ThunkFunc1<Classes::fl_gfx::Extensions, 8, UInt32, Instances::fl_display::DisplayObject*>;
// thunk 0x1424c2d10: Classes::fl_gfx::Extensions::setEdgeAAMode
template struct ThunkFunc2<Classes::fl_gfx::Extensions, 9, const Value, Instances::fl_display::DisplayObject*, UInt32>;
// thunk 0x1424c2f20: Classes::fl_gfx::Extensions::numControllersGet
template struct ThunkFunc0<Classes::fl_gfx::Extensions, 10, UInt32>;
// thunk 0x1424c2f80: Classes::fl_gfx::Extensions::visibleRectGet
template struct ThunkFunc0<Classes::fl_gfx::Extensions, 11, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x1424c3030: Classes::fl_gfx::Extensions::isScaleformGet
template struct ThunkFunc0<Classes::fl_gfx::Extensions, 12, bool>;
// thunk 0x1424c3490: Classes::fl_gfx::InteractiveObjectEx::setHitTestDisable
template struct ThunkFunc2<Classes::fl_gfx::InteractiveObjectEx, 0, const Value, Instances::fl_display::InteractiveObject*, bool>;
// thunk 0x1424c3660: Classes::fl_gfx::InteractiveObjectEx::getHitTestDisable
template struct ThunkFunc1<Classes::fl_gfx::InteractiveObjectEx, 1, bool, Instances::fl_display::InteractiveObject*>;
// thunk 0x1424c3700: Classes::fl_gfx::InteractiveObjectEx::setTopmostLevel
template struct ThunkFunc2<Classes::fl_gfx::InteractiveObjectEx, 2, const Value, Instances::fl_display::InteractiveObject*, bool>;
// thunk 0x1424c3790: Classes::fl_gfx::InteractiveObjectEx::getTopmostLevel
template struct ThunkFunc1<Classes::fl_gfx::InteractiveObjectEx, 3, bool, Instances::fl_display::InteractiveObject*>;
// thunk 0x1424c3ad0: Classes::fl_gfx::SystemEx::actionVerboseSet
template struct ThunkFunc1<Classes::fl_gfx::SystemEx, 0, const Value, bool>;
// thunk 0x1424c3b30: Classes::fl_gfx::SystemEx::actionVerboseGet
template struct ThunkFunc0<Classes::fl_gfx::SystemEx, 1, bool>;
// thunk 0x1424c3b90: Classes::fl_gfx::GamePad::supportsAnalogEvents
template struct ThunkFunc0<Classes::fl_gfx::GamePad, 0, bool>;
// thunk 0x1424c3bf0: Classes::fl_gfx::SystemEx::setBackgroundAlpha
template struct ThunkFunc1<Classes::fl_gfx::SystemEx, 2, const Value, Value::Number>;
// thunk 0x1424c3c80: Classes::fl_gfx::SystemEx::getStackTrace
template struct ThunkFunc0<Classes::fl_gfx::SystemEx, 3, ASString>;
// thunk 0x1424c3cf0: Classes::fl_gfx::SystemEx::getCodeFileName
template struct ThunkFunc0<Classes::fl_gfx::SystemEx, 4, ASString>;
// thunk 0x1424c3d60: Classes::fl_gfx::SystemEx::getCodeFileNames
template struct ThunkFunc0<Classes::fl_gfx::SystemEx, 5, SPtr<Instances::fl::Array>>;
// thunk 0x1424c3e10: Classes::fl_gfx::SystemEx::describeType
template struct ThunkFunc1<Classes::fl_gfx::SystemEx, 6, ASString, const Value&>;
// thunk 0x1424c3f90: Classes::fl_gfx::SystemEx::printObjectsReport
template struct ThunkFunc3<Classes::fl_gfx::SystemEx, 7, const Value, bool, UInt32, const ASString&>;
// thunk 0x1424c4270: Instances::fl_gfx::GamePadAnalogEvent::codeGet
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 0, UInt32>;
// thunk 0x1424c42d0: Instances::fl_gfx::GamePadAnalogEvent::codeSet
template struct ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 1, const Value, UInt32>;
// thunk 0x1424c4340: Instances::fl_gfx::GamePadAnalogEvent::controllerIdxGet
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 2, UInt32>;
// thunk 0x1424c43a0: Instances::fl_gfx::GamePadAnalogEvent::controllerIdxSet
template struct ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 3, const Value, UInt32>;
// thunk 0x1424c4410: Instances::fl_gfx::GamePadAnalogEvent::xvalueGet
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 4, Value::Number>;
// thunk 0x1424c4480: Instances::fl_gfx::GamePadAnalogEvent::xvalueSet
template struct ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 5, const Value, Value::Number>;
// thunk 0x1424c4510: Instances::fl_gfx::GamePadAnalogEvent::yvalueGet
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 6, Value::Number>;
// thunk 0x1424c4580: Instances::fl_gfx::GamePadAnalogEvent::yvalueSet
template struct ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 7, const Value, Value::Number>;
// thunk 0x1424c4610: Instances::fl_gfx::GamePadAnalogEvent::clone
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 8, SPtr<Instances::fl_events::Event>>;
// thunk 0x1424c46c0: Instances::fl_gfx::GamePadAnalogEvent::toString
template struct ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 9, ASString>;
// thunk 0x1424c49b0: Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 0, const Value, bool>;
// thunk 0x1424c4a10: Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet
template struct ThunkFunc0<Classes::fl_gfx::FocusManager, 1, bool>;
// thunk 0x1424c4a70: Classes::fl_gfx::FocusManager::disableFocusKeysSet
template struct ThunkFunc1<Classes::fl_gfx::FocusManager, 2, const Value, bool>;
// thunk 0x1424c4c30: Classes::fl_gfx::FocusManager::disableFocusKeysGet
template struct ThunkFunc0<Classes::fl_gfx::FocusManager, 3, bool>;
// thunk 0x1424c4c90: Classes::fl_gfx::FocusManager::moveFocus
template struct ThunkFunc4<Classes::fl_gfx::FocusManager, 4, SPtr<Instances::fl_display::InteractiveObject>, const ASString&, Instances::fl_display::InteractiveObject*, bool, UInt32>;
// thunk 0x1424c4e60: Classes::fl_gfx::FocusManager::findFocus
template struct ThunkFunc6<Classes::fl_gfx::FocusManager, 5, SPtr<Instances::fl_display::InteractiveObject>, const ASString&, Instances::fl_display::DisplayObjectContainer*, bool, Instances::fl_display::InteractiveObject*, bool, UInt32>;
// thunk 0x1424c4f80: Classes::fl_gfx::FocusManager::setFocus
template struct ThunkFunc2<Classes::fl_gfx::FocusManager, 6, const Value, Instances::fl_display::InteractiveObject*, UInt32>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// ==== flash.utils: class traits factories, instance traits and the Endian class =====================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_utils
{
    extern const ClassInfo ByteArrayCI;
    extern const ClassInfo DictionaryCI;
    extern const ClassInfo EndianCI;
    extern const ClassInfo IDataInputCI;
    extern const ClassInfo IDataOutputCI;
    extern const ClassInfo IExternalizableCI;
    extern const ClassInfo ProxyCI;
    extern const ClassInfo TimerCI;
}

// The traits constructors below are inlined into their factories in the exe.
namespace InstanceTraits { namespace fl_utils
{
    inline Dictionary::Dictionary(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_Dictionary;
        SetMemSize(0x48);
    }

    inline Timer::Timer(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x68);
    }
}}

namespace Classes { namespace fl_utils
{
    inline Endian::Endian(ClassTraits::Traits& t)
        : Class(t)
        , BIG_ENDIAN("bigEndian")
        , LITTLE_ENDIAN("littleEndian")
    {
    }
}}

namespace ClassTraits { namespace fl_utils
{
    inline Dictionary::Dictionary(VM& vm)
        : Traits(vm, AS3::fl_utils::DictionaryCI)
    {
        TraitsType = Traits_Dictionary;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_utils::Dictionary(vm, AS3::fl_utils::DictionaryCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Endian::Endian(VM& vm)
        : Traits(vm, AS3::fl_utils::EndianCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_utils::EndianCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_utils::Endian(*this)));
    }

    inline IDataInput::IDataInput(VM& vm)
        : Traits(vm, AS3::fl_utils::IDataInputCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_utils::IDataInputCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline IDataOutput::IDataOutput(VM& vm)
        : Traits(vm, AS3::fl_utils::IDataOutputCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_utils::IDataOutputCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline IExternalizable::IExternalizable(VM& vm)
        : Traits(vm, AS3::fl_utils::IExternalizableCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_utils::IExternalizableCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Proxy::Proxy(VM& vm)
        : Traits(vm, AS3::fl_utils::ProxyCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_utils::ProxyCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Timer::Timer(VM& vm)
        : Traits(vm, AS3::fl_utils::TimerCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_utils::Timer(vm, AS3::fl_utils::TimerCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424bb1f0
    Pickable<Traits> Dictionary::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Dictionary(vm));
    }

    // @0x1424bb340
    Pickable<Traits> Endian::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Endian(vm));
    }

    // @0x1424bb490
    Pickable<Traits> IDataInput::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IDataInput(vm));
    }

    // @0x1424bb5b0
    Pickable<Traits> IDataOutput::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IDataOutput(vm));
    }

    // @0x1424bb6d0
    Pickable<Traits> IExternalizable::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IExternalizable(vm));
    }

    // @0x1424bb7f0
    Pickable<Traits> Proxy::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Proxy(vm));
    }

    // @0x1424bb910
    Pickable<Traits> ByteArray::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ByteArray(vm));
    }

    // @0x1424bb970
    Pickable<Traits> Timer::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Timer(vm));
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.utils ====================================================================================================

// zlib 1.2.5's stream state (0x58 bytes on x64); the zlib in the exe is linked as C.
typedef void* (*ZLib_AllocFunc)(void* opaque, unsigned items, unsigned size);
typedef void  (*ZLib_FreeFunc)(void* opaque, void* address);

struct z_stream_s
{
    const unsigned char* next_in;   // +0
    unsigned             avail_in;  // +8
    unsigned long        total_in;  // +0xc
    unsigned char*       next_out;  // +0x10
    unsigned             avail_out; // +0x18
    unsigned long        total_out; // +0x1c
    char*                msg;       // +0x20
    void*                state;     // +0x28
    ZLib_AllocFunc       zalloc;    // +0x30
    ZLib_FreeFunc        zfree;     // +0x38
    void*                opaque;    // +0x40
    int                  data_type; // +0x48
    unsigned long        adler;     // +0x4c
    unsigned long        reserved;  // +0x50
};

extern "C" int compress2(unsigned char* dest, unsigned long* destLen, const unsigned char* source,
                         unsigned long sourceLen, int level);
extern "C" int inflate(z_stream_s* strm, int flush);
extern "C" int inflateEnd(z_stream_s* strm);
extern "C" int inflateInit_(z_stream_s* strm, const char* version, int streamSize);

// An inflate stream, zeroed and initialised.
struct ZInflateStream : z_stream_s
{
    ZInflateStream();
};

// @0x1424bccb0
ZInflateStream::ZInflateStream()
{
    memset(static_cast<z_stream_s*>(this), 0, sizeof(z_stream_s));
    inflateInit_(this, "1.2.5", sizeof(z_stream_s));
}

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_utils
{
    extern const ClassInfo ByteArrayCI;
}

namespace
{
    // The charset names readMultiByte / writeMultiByte accept, NULL terminated.
    const char* const CharSetASCII[] =
    {
        "us-ascii", "ANSI_X3.4-1968", "ANSI_X3.4-1986", "ascii", "cp367", "csASCII", "IBM367", "ISO_646.irv:1991",
        "ISO646-US", "iso-ir-6us", NULL
    };
    const char* const CharSetUTF8[] =
    {
        "utf-8", "unicode-1-1-utf-8", "unicode-2-0-utf-8", "x-unicode-2-0-utf-8", NULL
    };
    const char* const CharSetUnicode[] = { "unicode", "utf-16", NULL };

    bool IsCharSet(const char* const* names, const ASString& charSet)
    {
        for (unsigned i = 0; names[i] != NULL; ++i)
        {
            if (strcmp(charSet.ToCStr(), names[i]) == 0)
                return true;
        }
        return false;
    }

    inline UInt16 SwapBytes(UInt16 v)
    {
        return (UInt16)((v << 8) | (v >> 8));
    }

    inline UInt32 SwapBytes(UInt32 v)
    {
        return (v >> 24) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | (v << 24);
    }

    inline float SwapBytes(float v)
    {
        union { float f; UInt32 u; } x;
        x.f = v;
        x.u = SwapBytes(x.u);
        return x.f;
    }
}

// @0x1424bf0e0
Value::Number SwapBytes(Value::Number v)
{
    union { Value::Number d; UInt64 u; } x;
    x.d = v;
    x.u = (x.u >> 56) | ((x.u >> 40) & 0xff00) | ((x.u >> 24) & 0xff0000) | ((x.u >> 8) & 0xff000000)
        | ((x.u << 8) & 0xff00000000ULL) | ((x.u << 24) & 0xff0000000000ULL)
        | ((x.u << 40) & 0xff000000000000ULL) | (x.u << 56);
    return x.d;
}

namespace ClassTraits { namespace fl_utils
{
    // MS2-FUNCTIONAL: ctor: Pickable/traits setup register allocation and inlined Multiname temporaries differ
    // @0x1424bc0e0
    ByteArray::ByteArray(VM& vm)
        : Traits(vm, AS3::fl_utils::ByteArrayCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_utils::ByteArray(vm, AS3::fl_utils::ByteArrayCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_utils::ByteArray(*this)));
    }
}}

namespace Classes { namespace fl_utils
{
    // @0x1424bc300
    ByteArray::ByteArray(ClassTraits::Traits& t)
        : Class(t)
        , DefaultObjectEncoding(Instances::fl_utils::ByteArray::encAMF3)
    {
    }

    // @0x1424bf640
    void ByteArray::defaultObjectEncodingGet(UInt32& result)
    {
        result = DefaultObjectEncoding;
    }

    // Only AMF3 is supported: setting the default encoding always fails.
    // @0x1424bf650
    void ByteArray::defaultObjectEncodingSet(const Value& result, UInt32)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowRangeError(VM::Error(VM::eInvalidEnumError, vm, "something", "encAMF0 or encAMF3"));
    }
}}

namespace InstanceTraits { namespace fl_utils
{
    // MS2-FUNCTIONAL: ctor: inlined traits-base construction scheduling differs
    // @0x1424bc330
    ByteArray::ByteArray(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        SetMemSize(0x60);
        RegisterImplementedInterface(Multiname(vm, StringDataPtr("flash.utils.IDataInput")));
        RegisterImplementedInterface(Multiname(vm, StringDataPtr("flash.utils.IDataOutput")));
    }

    // MS2-FUNCTIONAL: Pickable construction: allocation + ctor inlining differs
    // @0x1424be940
    Pickable<ByteArray::InstanceType> ByteArray::MakeInstance(ByteArray& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424beae0
    void ByteArray::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ByteArray&>(t)));
    }

    // @0x1424be9e0
    Pickable<Dictionary::InstanceType> Dictionary::MakeInstance(Dictionary& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424bea60
    Pickable<Timer::InstanceType> Timer::MakeInstance(Timer& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424beb70
    void Dictionary::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Dictionary&>(t)));
    }

    // @0x1424bebe0
    void Timer::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Timer&>(t)));
    }
}}

// Visits the collectable a value holds (0x142504530).
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner);

SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        ForEachChild_GC_Internal(prcc, v, op, owner);
}

// Children of a Dictionary hash. With weak keys, the marking pass first drops the entries whose key died; their
// values are kept alive until the collection ends.
// MS2-FUNCTIONAL: proxy allocation and the delayed-release chain are written plainly
// @0x1424bdf90
void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, bool weakKeys,
                     Instances::fl_utils::Dictionary::ContainerType& h, ASRefCountBaseType::GcOp op,
                     const ASRefCountBaseType& owner)
{
    typedef Instances::fl_utils::Dictionary::ContainerType ContainerType;
    typedef RefCountCollector<StatMV_ActionScript_Mem> CollectorType;
    typedef PtrReleaseProxy<StatMV_VM> ReleaseProxy;

    if (weakKeys && op == &CollectorType::MarkInCycleCall)
    {
        for (;;)
        {
            ContainerType::Iterator it = h.Begin();
            while (!it.IsEnd() && it->First.IsValidWeakRef())
                ++it;
            if (it.IsEnd())
                break;

            const Value& v = it->Second;
            const ASRefCountBaseType* obj = 0;
            const Value::KindType kind = v.GetKind();
            if (kind >= Value::kThunkClosure)
                obj = v.GetClosure();
            else if (kind >= Value::kObject)
                obj = v.GetObject();
            if (obj)
            {
                // The proxy's destructor drops the value's reference once the collection is over.
                Ptr<ReleaseProxy> proxy = *SF_HEAP_AUTO_NEW(&h) ReleaseProxy();
                proxy->Data2 = const_cast<ASRefCountBaseType*>(obj);
                Ptr<ReleaseProxy>& head = reinterpret_cast<Ptr<ReleaseProxy>&>(prcc->HeadDelayedPtrRelease);
                proxy->pNext = head;
                head = proxy;
            }
            it.RemoveAlt(*it);
        }
    }

    for (ContainerType::ConstIterator it = h.Begin(); !it.IsEnd(); ++it)
    {
        if (!weakKeys || it->First.IsValidWeakRef())
            ForEachChild_GC(prcc, it->First, op, owner);
        ForEachChild_GC(prcc, it->Second, op, owner);
    }
}

namespace Instances { namespace fl_utils
{
    // ---- Dictionary ----

    // @0x1424bc660
    Dictionary::Dictionary(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , WeakKeys(false)
    {
    }

    // new Dictionary(weakKeys = false)
    // @0x1424bd560
    void Dictionary::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc != 0 && argv[0].Convert2Boolean())
            WeakKeys = true;
    }

    // @0x1424bcd70
    Dictionary::~Dictionary()
    {
    }

    // Numeric keys are stored as Number, so d[1], d[1.0] and d["1"] are the same entry.
    // MS2-FUNCTIONAL: exe zeroes the return slot up front and stores each Find result into it; ours keeps the iterator in xmm6
    // @0x1424bde70
    Dictionary::ContainerType::Iterator Dictionary::FindKey(const Multiname& mn)
    {
        ContainerType::Iterator result;
        const Value& name = mn.Name;
        const Value::KindType kind = name.GetKind();
        if (kind >= Value::kInt)
        {
            Value::Number num;
            if (kind <= Value::kUInt)
            {
                if (!name.Convert2Number(num))
                    return result;
            }
            else if (kind != Value::kString || !GetStrNumber(name.GetStringNode(), num))
            {
                result = ValueH.Find(name);
                return result;
            }
            result = ValueH.Find(Value(num));
            return result;
        }
        result = ValueH.Find(name);
        return result;
    }

    // @0x1424bd650
    void Dictionary::AddDynamicSlotValuePair(const Value& prop_name, const Value& v, SlotInfo::Attribute)
    {
        Value key(prop_name);
        const Value::KindType kind = key.GetKind();
        if (kind == Value::kString)
        {
            Value::Number num;
            if (GetStrNumber(key.GetStringNode(), num))
                key.SetNumber(num);
        }
        else if (kind == Value::kInt || kind == Value::kUInt)
            key.ToNumberValue();

        ContainerType::Iterator it = ValueH.Find(key);
        if (!it.IsEnd())
        {
            if (!WeakKeys || it->First.IsValidWeakRef())
            {
                it->Second.Assign(v);
                return;
            }
            // the old key died: its entry goes, a new one is made
            it.RemoveAlt(*it);
        }
        if (WeakKeys)
            key.MakeWeakRef();
        ValueH.Add(key, v);
    }

    // Only public names reach the hash; an entry whose weak key died is dropped on the way.
    // @0x1424bdd70
    PropRef Dictionary::FindDynamicSlot(const Multiname& mn)
    {
        if (mn.ContainsNamespace(GetVM().GetPublicNamespace()))
        {
            ContainerType::Iterator it = FindKey(mn);
            if (!it.IsEnd())
            {
                if (!WeakKeys || it->First.IsValidWeakRef())
                    return PropRef(this, &it->Second);
                it.RemoveAlt(*it);
            }
        }
        return PropRef();
    }

    // @0x1424be850
    CheckResult Dictionary::GetProperty(const Multiname& prop_name, Value& value)
    {
        bool result = false;
        if (prop_name.ContainsNamespace(GetVM().GetPublicNamespace()))
        {
            ContainerType::Iterator it = FindKey(prop_name);
            if (!it.IsEnd())
            {
                if (!WeakKeys || it->First.IsValidWeakRef())
                {
                    value.Assign(it->Second);
                    result = true;
                }
                else
                    it.RemoveAlt(*it);
            }
        }
        return result;
    }

    // @0x1424bf0b0
    CheckResult Dictionary::SetProperty(const Multiname& prop_name, const Value& value)
    {
        AddDynamicSlotValuePair(prop_name.Name, value);
        return true;
    }

    // @0x1424bda80
    CheckResult Dictionary::DeleteProperty(const Multiname& prop_name)
    {
        bool result = false;
        if (prop_name.ContainsNamespace(GetVM().GetPublicNamespace()))
        {
            ContainerType::Iterator it = FindKey(prop_name);
            if (!it.IsEnd())
            {
                it.RemoveAlt(*it);
                result = true;
            }
        }
        return result;
    }

    // Enumeration indices are hash slot + 1; 0 ends.
    // @0x1424be5e0
    void Dictionary::GetDynamicProperty(AbsoluteIndex ind, Value& value)
    {
        ContainerType::ConstIterator it(ValueH.Begin().GetContainer(), (UInt32)ind.Get());
        value.Assign(it->Second);
    }

    // @0x1424be710
    void Dictionary::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        if (!ind.IsValid())
            return;
        ContainerType::ConstIterator it(ValueH.Begin().GetContainer(), ind.Get() - 1);
        name.Assign(it->First);
        if (WeakKeys)
            name.MakeStrongRef();
    }

    // @0x1424be630
    GlobalSlotIndex Dictionary::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        const ContainerType::ConstIterator b = ValueH.Begin();
        ContainerType::ConstIterator it(b.GetContainer(), ind.IsValid() ? (SPInt)(ind.Get() - 1) : -1);
        if (!it.IsEnd())
        {
            ++it;
            if (!it.IsEnd() && (!WeakKeys || it->First.IsValidWeakRef()))
                return GlobalSlotIndex((UInt32)it.GetIndex() + 1);
        }
        return GlobalSlotIndex(0);
    }

    // @0x1424be3b0
    void Dictionary::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, WeakKeys, const_cast<ContainerType&>(ValueH), op, *this);
    }

    // ---- Timer ----

    // @0x1424bcc80
    Timer::Timer(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
        , RepeatCount(0)
        , CurrentCount(0)
        , Delay(0)
    {
    }

    // new Timer(delay, repeatCount = 0)
    // @0x1424bd590
    void Timer::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc < 1)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Timer::AS3Constructor", 1, 1, argc));
            return;
        }
        argv[0].Convert2Number(Delay);
        if (argc >= 2)
            argv[1].Convert2Int32(RepeatCount);
    }

    // new TimerEvent(type, bubbles = false, cancelable = false)
    // @0x1424bd9a0
    SPtr<Instances::fl_events::TimerEvent> Timer::CreateTimerEventObject(const ASString& type)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::TimerEvent> evt;
        Value params[] = { Value(type), Value(false), Value(false) };
        asvm.ConstructInstance(evt, asvm.TimerEventClass, 3, params);
        return evt;
    }

    // @0x1424bdb60
    void Timer::ExecuteEvent()
    {
        CurrentCount = (SInt32)static_cast<IntervalTimer*>(pCoreTimer.GetPtr())->GetCurrentCount();

        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::TimerEvent> efe = CreateTimerEventObject(asvm.GetBuiltin(AS3Builtin_timer));
        efe->Target = this;
        DispatchSingleEvent(efe, false);

        if (CurrentCount >= RepeatCount)
        {
            SPtr<Instances::fl_events::TimerEvent> efc = CreateTimerEventObject(asvm.GetBuiltin(AS3Builtin_timerComplete));
            efc->Target = this;
            DispatchSingleEvent(efc, false);
        }
    }

    // @0x1424bf620
    void Timer::currentCountGet(SInt32& result)
    {
        if (pCoreTimer)
            result = static_cast<IntervalTimer*>(pCoreTimer.GetPtr())->GetCurrentCount();
        else
            result = CurrentCount;
    }

    // @0x1424bf6b0
    void Timer::delayGet(Value::Number& result)
    {
        result = Delay;
    }

    // @0x1424bf6c0
    void Timer::delaySet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        Delay = value;
    }

    // @0x1424bffa0
    void Timer::repeatCountGet(SInt32& result)
    {
        result = RepeatCount;
    }

    // @0x1424bffb0
    void Timer::repeatCountSet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        RepeatCount = value;
    }

    // @0x1424bffc0
    void Timer::reset(const Value& result)
    {
        stop(result);
        CurrentCount = 0;
    }

    // @0x1424bffe0
    void Timer::runningGet(bool& result)
    {
        result = pCoreTimer && pCoreTimer->IsActive();
    }

    // A running timer keeps going; a stopped one continues from the count it reached.
    // @0x1424c0240
    void Timer::start(const Value& result)
    {
        SF_UNUSED(result);
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (pCoreTimer)
        {
            if (pCoreTimer->IsActive())
                return;
            CurrentCount = static_cast<IntervalTimer*>(pCoreTimer.GetPtr())->GetCurrentCount();
            pCoreTimer = NULL;
        }
        pCoreTimer = *SF_HEAP_NEW(GetVM().GetMemoryHeap())
            IntervalTimer(this, (unsigned)(SInt64)Delay, CurrentCount, RepeatCount);
        proot->AddIntervalTimer(pCoreTimer);
        pCoreTimer->Start(proot);
    }

    // MS2-FUNCTIONAL: instruction scheduling around the core-timer release differs
    // @0x1424c0310
    // noinline: reset calls it out of line.
    __declspec(noinline) void Timer::stop(const Value& result)
    {
        SF_UNUSED(result);
        if (pCoreTimer && pCoreTimer->IsActive())
        {
            MovieImpl* proot = static_cast<const ASVM&>(GetVM()).GetMovieImpl();
            proot->ClearIntervalTimer(int(pCoreTimer->GetId()));
        }
        pCoreTimer = NULL;
    }

    // ---- ByteArray ----

    // The SDK's ByteArray::GetDefaultEndian.
    static inline ByteArray::EndianType Sfr14DefaultEndian() { return ByteArray::endianBig; }
    // The SDK's Classes::fl_utils::ByteArray::GetDefEncoding.
    static inline ByteArray::EncodingType Sfr14DefEncoding(const Classes::fl_utils::ByteArray& c)
    {
        return (ByteArray::EncodingType)c.DefaultObjectEncoding;
    }

    // The constructor getter is the exe's out-of-line Traits::GetConstructor (0x142508460).
    // @0x1424bc460
    ByteArray::ByteArray(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Encoding(Sfr14DefEncoding(static_cast<Classes::fl_utils::ByteArray&>(FUN_142508460(&t))))
        , Endian(Sfr14DefaultEndian())
        , Position(0)
        , Length(0)
    {
    }

    // @0x1424bc4c0
    ByteArray::ByteArray(InstanceTraits::Traits& t, EncodingType enc)
        : Instances::fl::Object(t)
        , Encoding(enc)
        , Endian(endianBig)
        , Position(0)
    {
    }

    // @0x1424bf180
    void ByteArray::ThrowEOFError()
    {
        Value v;
        VM& vm = GetVM();
        vm.Construct("flash.errors.EOFError", v, 0, NULL, true);
        if (!vm.IsException() && !v.IsNullOrUndefined())
            GetVM().Throw(v);
    }

    // @0x1424bf250
    void ByteArray::ThrowMemoryError()
    {
        Value v;
        VM& vm = GetVM();
        vm.Construct("flash.errors.MemoryError", v, 0, NULL, true);
        if (!vm.IsException() && !v.IsNullOrUndefined())
            GetVM().Throw(v);
    }

    // @0x1424bdb30
    CheckResult ByteArray::EOFError()
    {
        if (Position >= Data.GetSize())
        {
            ThrowEOFError();
            return true;
        }
        return false;
    }

    // block order / register allocation of the EOF check differs
    // @0x1424bec50
    CheckResult ByteArray::Read(void* dest, UInt32 n)
    {
        if ((UPInt)(Position + n) > Data.GetSize())
        {
            ThrowEOFError();
            return false;
        }
        memcpy(dest, Data.GetDataPtr() + Position, n);
        Position += n;
        return true;
    }

    // @0x1424becd0
    UInt16 ByteArray::ReadUInt16()
    {
        UInt16 v;
        ReadValue(v);
        return v;
    }

    // MS2-FUNCTIONAL: string-node creation call shape differs
    static inline bool IsUTF8BOM(const char* str) { return (UInt8)str[0] == 0xEF && (UInt8)str[1] == 0xBB && (UInt8)str[2] == 0xBF; }

    // @0x1424bed20
    CheckResult ByteArray::ReadUTFBytes(ASString& result, UInt32 len)
    {
        if (!(Position + len <= Data.GetSize()))
        {
            ThrowEOFError();
            return false;
        }
        // A UTF-8 byte order mark is skipped.
        if (len > 2 && IsUTF8BOM(reinterpret_cast<char*>(Data.GetDataPtr() + Position)))
        {
            len -= 3;
            Position += 3;
        }
        result = GetVM().GetStringManager().CreateString(reinterpret_cast<char*>(Data.GetDataPtr() + Position), len);
        Position += len;
        return true;
    }

    // @0x1424bef20
    void ByteArray::Resize(UInt32 size)
    {
        UPInt oldSize = Data.GetSize();
        if (size > oldSize)
        {
            Data.Resize(size);
            memset(Data.GetDataPtr() + oldSize, 0, size - oldSize);
        }
        Length = size;
        if (Position > size)
            Position = size;
    }

    // Write(char/UInt8/bool) are unused out of line; writeByte/writeBoolean inline them.
    // @0x1424bf320
    void ByteArray::Write(char v)
    {
        const UInt32 newPos = Position + 1;
        if (newPos >= Data.GetSize())
            Resize(newPos);
        else if (newPos >= Length)
            Length = newPos;
        Data[Position++] = (UInt8)v;
    }

    // @0x1424bf3b0
    void ByteArray::Write(UInt8 v)
    {
        const UInt32 newPos = Position + 1;
        if (newPos >= Data.GetSize())
            Resize(newPos);
        else if (newPos >= Length)
            Length = newPos;
        Data[Position++] = v;
    }

    // @0x1424bf4f0
    void ByteArray::Write(bool v)
    {
        const UInt32 newPos = Position + 1;
        if (newPos >= Data.GetSize())
            Resize(newPos);
        else if (newPos >= Length)
            Length = newPos;
        Data[Position++] = (UInt8)v;
    }

    // @0x1424bf440
    void ByteArray::Write(const void* src, UInt32 n)
    {
        const UInt32 newPos = Position + n;
        if (newPos >= Data.GetSize())
            Resize(newPos);
        else if (newPos >= Length)
            Length = newPos;
        memcpy(Data.GetDataPtr() + Position, src, n);
        Position += n;
    }

    // Reads one value in the array's byte order; on EOF throws and leaves v as it was.
    template <typename T>
    inline bool ByteArray::ReadValue(T& v)
    {
        if (!Read(&v, sizeof(T)))
            return false;
        if (Endian != endianLittle)
            v = SwapBytes(v);
        return true;
    }

    template <typename T>
    inline void ByteArray::WriteValue(T v)
    {
        if (Endian != endianLittle)
            v = SwapBytes(v);
        const UInt32 newPos = Position + (UInt32)sizeof(T);
        if (newPos >= Data.GetSize())
            Resize(newPos);
        else if (newPos >= Length)
            Length = newPos;
        *reinterpret_cast<T*>(Data.GetDataPtr() + Position) = v;
        Position += sizeof(T);
    }

    // for..in / for each: the bytes as signed ints.
    // @0x1424be580
    void ByteArray::GetDynamicProperty(AbsoluteIndex ind, Value& value)
    {
        value.SetSInt32((SInt8)Get((UInt32)ind.Get()));
    }

    // noinline: the exe calls it out of line from GetDynamicProperty.
    // @0x1424be400
    SF_NOINLINE UInt8 ByteArray::Get(UInt32 ind) const
    {
        if (ind < Length)
            return Data[ind];
        VM& vm = GetVM();
        vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "ByteArray::Get", ind, 0, Length - 1));
        return 0;
    }

    // @0x1424bef90
    void ByteArray::Set(UInt32 ind, UInt8 v)
    {
        if (ind >= Length)
            Resize(ind + 1);
        Data[ind] = v;
    }

    // @0x1424befd0
    void ByteArray::Set(const void* data, UPInt size)
    {
        Position = 0;
        Write(data, (UInt32)size);
        Position = 0;
    }

    // ba[i] reads byte i as uint; other names are ordinary properties.
    // @0x1424be790
    CheckResult ByteArray::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            if (ind < Length)
            {
                UInt8 b = Data[ind];
                value.SetUInt32(b);
                return true;
            }
            return false;
        }
        return Object::GetProperty(prop_name, value);
    }

    // ba[i] = v stores the low byte of uint(v), growing the array up to i.
    // @0x1424bf000
    CheckResult ByteArray::SetProperty(const Multiname& prop_name, const Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            UInt32 v;
            if (!value.Convert2UInt32(v))
                return false;
            Set(ind, static_cast<UInt8>(v));
            return true;
        }
        return Object::SetProperty(prop_name, value);
    }

    // @0x1424bf580
    void ByteArray::bytesAvailableGet(UInt32& result)
    {
        result = (UInt32)(Data.GetSize() - Position);
    }

    // zlib-compresses the content in place; the position ends after it.
    // @0x1424bf590
    void ByteArray::compress(Value& result, unsigned, const Value*)
    {
        SF_UNUSED(result);
        if (Length == 0)
            return;
        UPInt destLen = Length * 3 / 2 + 0x20;
        UInt8* buf = (UInt8*)SF_HEAP_AUTO_ALLOC(this, destLen);
        compress2(buf, (unsigned long*)&destLen, Data.GetDataPtr(), Length, 9);
        Resize(0);
        Write(buf, (UInt32)destLen);
        SF_FREE(buf);
    }

    // MS2-FUNCTIONAL: exe selects the string/length with separate branches; ours with cmov
    // @0x1424bf6d0
    void ByteArray::endianGet(ASString& result)
    {
        if (Endian == endianBig)
            result = GetVM().GetStringManager().GetStringManager()->CreateConstString("bigEndian", 9);
        else
            result = GetVM().GetStringManager().GetStringManager()->CreateConstString("littleEndian", 12);
    }

    // @0x1424bf750
    void ByteArray::endianSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        if (strcmp(value.ToCStr(), "bigEndian") == 0)
            Endian = endianBig;
        else if (strcmp(value.ToCStr(), "littleEndian") == 0)
            Endian = endianLittle;
        else
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, value.ToCStr()));
        }
    }

    // @0x1424bf7f0
    void ByteArray::lengthGet(UInt32& result)
    {
        result = Length;
    }

    // @0x1424bf800
    void ByteArray::lengthSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Resize(value);
    }

    // @0x1424bf810
    void ByteArray::objectEncodingGet(UInt32& result)
    {
        result = Encoding;
    }

    // Only AMF3 is supported: setting the encoding always fails.
    // @0x1424bf820
    void ByteArray::objectEncodingSet(const Value& result, UInt32)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowRangeError(VM::Error(VM::eInvalidEnumError, vm, "some type", "encAMF0 or encAMF3"));
    }

    // @0x1424bf880
    void ByteArray::positionGet(UInt32& result)
    {
        result = Position;
    }

    // @0x1424bf890
    void ByteArray::positionSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Position = value;
    }

    // @0x1424bf8a0
    void ByteArray::readBoolean(bool& result)
    {
        if (Position >= Data.GetSize())
        {
            ThrowEOFError();
            return;
        }
        result = Data[Position++] != 0;
    }

    // @0x1424bf8d0
    void ByteArray::readByte(SInt32& result)
    {
        if (Position >= Data.GetSize())
        {
            ThrowEOFError();
            return;
        }
        result = (SInt8)Data[Position++];
    }

    // Reads length bytes (all that is left when 0) into bytes at offset.
    // @0x1424bf900
    void ByteArray::readBytes(const Value& result, Instances::fl_utils::ByteArray* bytes, UInt32 offset, UInt32 length)
    {
        SF_UNUSED(result);

        const UInt32 available_num = (UInt32)Data.GetSize() - Position;

        if (length == 0)
            length = available_num;

        if (length > available_num)
            return ThrowEOFError();

        if (offset + length >= bytes->Data.GetSize())
            bytes->Resize(offset + length);

        Read(bytes->Data.GetDataPtr() + offset, length);
    }

    // @0x1424bf9e0
    void ByteArray::readDouble(Value::Number& result)
    {
        ReadValue(result);
    }

    // @0x1424bfa30
    void ByteArray::readFloat(Value::Number& result)
    {
        float v;
        if (ReadValue(v))
            result = v;
    }

    // @0x1424bfab0
    void ByteArray::readInt(SInt32& result)
    {
        ReadValue(reinterpret_cast<UInt32&>(result));
    }

    // @0x1424bfaf0
    void ByteArray::readMultiByte(ASString& result, UInt32 length, const ASString& charSet)
    {
        if (IsCharSet(CharSetASCII, charSet))
        {
            UInt32 n = length < Length ? length : Length;
            result = GetVM().GetStringManager().CreateString((const char*)Data.GetDataPtr() + Position, n);
            Position += n;
            return;
        }
        if (IsCharSet(CharSetUTF8, charSet))
        {
            // ReadUTFBytes, inlined in the exe.
            if (!(Position + length <= Data.GetSize()))
            {
                ThrowEOFError();
                return;
            }
            if (length > 2 && IsUTF8BOM(reinterpret_cast<char*>(Data.GetDataPtr() + Position)))
            {
                length -= 3;
                Position += 3;
            }
            result = GetVM().GetStringManager().CreateString(reinterpret_cast<char*>(Data.GetDataPtr() + Position), length);
            Position += length;
            return;
        }
        if (IsCharSet(CharSetUnicode, charSet))
        {
            UInt32 n = length < Length ? length : Length;
            result = ASString(GetVM().GetStringManager().GetStringManager()->CreateStringNode(
                (const wchar_t*)(Data.GetDataPtr() + Position), n));
            Position += n;
            return;
        }
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "charSet"));
    }

    // AMF is not supported.
    // @0x1424bfd90
    void ByteArray::readObject(Value& result)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowError(VM::Error(VM::eNotImplementedError, vm, "ByteArray::readObject()"));
    }

    // @0x1424bfde0
    void ByteArray::readShort(SInt32& result)
    {
        result = (SInt16)ReadUInt16();
    }

    // A 16-bit length, then that many UTF-8 bytes.
    // @0x1424bfe40
    void ByteArray::readUTF(ASString& result)
    {
        ReadUTFBytes(result, ReadUInt16());
    }

    // @0x1424bfeb0
    void ByteArray::readUTFBytes(ASString& result, UInt32 length)
    {
        ReadUTFBytes(result, length);
    }

    // @0x1424bfed0
    void ByteArray::readUnsignedByte(UInt32& result)
    {
        if (Position >= Data.GetSize())
        {
            ThrowEOFError();
            return;
        }
        result = Data[Position++];
    }

    // @0x1424bff00
    void ByteArray::readUnsignedInt(UInt32& result)
    {
        ReadValue(result);
    }

    // @0x1424bff40
    void ByteArray::readUnsignedShort(UInt32& result)
    {
        result = ReadUInt16();
    }

    // The content as text: UTF-16 after a byte order mark, UTF-8 otherwise.
    // MS2-FUNCTIONAL: string creation from the data buffer: register allocation differs
    static inline bool IsUTF16BE(const char* str) { return (UInt8)str[0] == 0xFE && (UInt8)str[1] == 0xFF; }
    static inline bool IsUTF16LE(const char* str) { return (UInt8)str[0] == 0xFF && (UInt8)str[1] == 0xFE; }

    // @0x1424c0380
    void ByteArray::toString(ASString& result)
    {
        UPInt size = Data.GetSize();
        const char* p = (const char*)Data.GetDataPtr();
        if (size > 1)
        {
            if (IsUTF16BE(p))
            {
                p += 2;
                size = (size - 2) >> 1;
                result = ASString(GetVM().GetStringManager().GetStringManager()->CreateStringNode((const wchar_t*)p, (SPInt)size));
                return;
            }
            else if (IsUTF16LE(p))
            {
                p += 2;
                size = (size - 2) >> 1;
                result = ASString(GetVM().GetStringManager().GetStringManager()->CreateStringNode((const wchar_t*)p, (SPInt)size));
                return;
            }
            else if (size > 2 && (UInt8)p[0] == 0xef && (UInt8)p[1] == 0xbb && (UInt8)p[2] == 0xbf)
            {
                result = GetVM().GetStringManager().CreateString(p + 3, size - 3);
                return;
            }
        }
        result = GetVM().GetStringManager().CreateString(p, size);
    }

    // Inflates the zlib content in place; the position ends at 0.
    // @0x1424c0440
    void ByteArray::uncompress(Value& result, unsigned, const Value*)
    {
        SF_UNUSED(result);
        UInt32 len = Length;
        if (len == 0)
            return;
        UInt8* src = (UInt8*)SF_HEAP_AUTO_ALLOC(this, len);
        memcpy(src, Data.GetDataPtr(), len);
        Resize(0);

        ZInflateStream zs;
        zs.next_in = src;
        zs.avail_in = len;
        UInt8* out = (UInt8*)SF_HEAP_AUTO_ALLOC(this, 0x2000);
        int ret;
        do
        {
            zs.next_out = out;
            zs.avail_out = 0x2000;
            ret = inflate(&zs, 0);
            Write(out, 0x2000 - zs.avail_out);
        } while (ret == 0);
        SF_FREE(out);
        SF_FREE(src);
        Position = 0;
        if (ret != 1)
        {
            VM& vm = GetVM();
            vm.ThrowError(VM::Error(VM::eShellCompressedDataError, vm));
        }
        inflateEnd(&zs);
    }

    // @0x1424c05c0
    void ByteArray::writeBoolean(const Value& result, bool value)
    {
        SF_UNUSED(result);
        Write(value);
    }

    // @0x1424c0650
    void ByteArray::writeByte(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        Write((char)value);
    }

    // Writes length bytes (all from offset on when 0) of bytes.
    // @0x1424c06e0
    void ByteArray::writeBytes(const Value& result, Instances::fl_utils::ByteArray* bytes, UInt32 offset, UInt32 length)
    {
        SF_UNUSED(result);
        if (!bytes)
            return;
        if (bytes->Length < offset)
            offset = bytes->Length;
        if (length == 0)
            length = bytes->Length - offset;
        if (length > bytes->Length - offset)
        {
            VM& vm = GetVM();
            vm.ThrowRangeError(VM::Error(VM::eParamRangeError, vm));
        }
        else if (length != 0)
            Write(bytes->Data.GetDataPtr() + offset, length);
    }

    // @0x1424c0770
    void ByteArray::writeDouble(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        if (Endian != endianLittle)
            value = SwapBytes(value);
        Write(&value, 8);
    }

    // @0x1424c07b0
    void ByteArray::writeFloat(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        float v = static_cast<float>(value);
        if (Endian != endianLittle)
            v = SwapBytes(v);
        Write(&v, sizeof(v));
    }

    // @0x1424c0890
    void ByteArray::writeInt(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        if (Endian != endianLittle)
            value = (SInt32)SwapBytes((UInt32)value);
        Write(&value, 4);
    }

    // MS2-FUNCTIONAL: charset conversion + Write call scheduling differs
    // @0x1424c08f0
    void ByteArray::writeMultiByte(const Value& result, const ASString& value, const ASString& charSet)
    {
        SF_UNUSED(result);
        if (IsCharSet(CharSetUTF8, charSet))
        {
            Write(value.ToCStr(), value.GetSize());
            return;
        }
        if (IsCharSet(CharSetUnicode, charSet))
        {
            // Writes as many bytes as there are characters (the exe's behaviour).
            WStringBuffer wb;
            wb.SetString(value.ToCStr(), value.GetSize());
            if (wb.GetLength() <= 0xFFFFFFFFU)
                Write(wb.GetBuffer(), (UInt32)wb.GetLength());
            return;
        }
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "charSet"));
    }

    // AMF is not supported.
    // @0x1424c0a90
    void ByteArray::writeObject(const Value& result, const Value&)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowError(VM::Error(VM::eNotImplementedError, vm, "ByteArray::writeObject()"));
    }

    // @0x1424c0ae0
    void ByteArray::writeShort(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        SInt16 v = static_cast<SInt16>(value);
        if (Endian != endianLittle)
            v = (SInt16)(((UInt16)v >> 8) | (v << 8));
        Write(&v, sizeof(v));
    }

    // A 16-bit length, then the UTF-8 bytes.
    // @0x1424c0b90
    void ByteArray::writeUTF(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        if (value.GetSize() > 65535)
        {
            VM& vm = GetVM();
            return vm.ThrowRangeError(VM::Error(VM::eNotImplementedError, vm, "ByteArray::writeUTF"));
        }
        // Write(const void*, UInt32) is called out of line here; through the member pointer cl does not inline it.
        void (ByteArray::*Sfr14WriteOutOfLine)(const void*, UInt32) = &ByteArray::Write;
        const UInt16 size = static_cast<UInt16>(value.GetSize());
        UInt16 len = size;
        if (Endian != endianLittle)
            len = SwapBytes(len);
        (this->*Sfr14WriteOutOfLine)(&len, sizeof(len));
        (this->*Sfr14WriteOutOfLine)(value.ToCStr(), size);
    }

    // @0x1424c0c50
    void ByteArray::writeUTFBytes(const Value& result, const Value& value)
    {
        SF_UNUSED(result);
        if (value.IsNullOrUndefined())
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullArgumentError, vm, "value"));
            return;
        }
        ASString str = GetVM().GetStringManager().CreateEmptyString();
        if (value.Convert2String(str))
            Write(str.ToCStr(), str.GetSize());
    }

    // @0x1424c0d10
    void ByteArray::writeUnsignedInt(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        if (Endian != endianLittle)
            value = SwapBytes(value);
        Write(&value, 4);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// ==== flash.gfx: class traits factories, instance traits, class objects and the extended events ===================

namespace Scaleform { namespace GFx { namespace AS3 {

// The SPtr<InteractiveObject> assignment of the event clones is the exe's out-of-line copy.
template <>
SPtr<Instances::fl_display::InteractiveObject>& SPtr<Instances::fl_display::InteractiveObject>::operator=(
    const SPtr<Instances::fl_display::InteractiveObject>& other);

namespace fl_gfx
{
    extern const ClassInfo ExtensionsCI;
    extern const ClassInfo FocusEventExCI;
    extern const ClassInfo FocusManagerCI;
    extern const ClassInfo GamePadCI;
    extern const ClassInfo GamePadAnalogEventCI;
    extern const ClassInfo IMECandidateListStyleCI;
    extern const ClassInfo IMEEventExCI;
    extern const ClassInfo IMEExCI;
    extern const ClassInfo InteractiveObjectExCI;
    extern const ClassInfo KeyboardEventExCI;
    extern const ClassInfo MouseCursorEventCI;
    extern const ClassInfo MouseEventExCI;
    extern const ClassInfo SystemExCI;
    extern const ClassInfo TextEventExCI;
    extern const ClassInfo TextFieldExCI;
}

namespace Instances { namespace fl_gfx
{
    // @0x1424c5430
    FocusEventEx::FocusEventEx(InstanceTraits::Traits& t)
        : FocusEvent(t)
        , controllerIdx(0)
    {
    }

    // @0x1424c9090
    AS3::Object* FocusEventEx::GetEventClass() const
    {
        return static_cast<ASVM&>(GetVM()).FocusEventExClass;
    }

    // @0x1424c8ae0
    SPtr<Instances::fl_events::Event> FocusEventEx::Clone() const
    {
        SPtr<Instances::fl_events::Event> r = Event::Clone();
        FocusEventEx* p = static_cast<FocusEventEx*>(r.GetPtr());
        p->RelatedObj = RelatedObj;
        p->ShiftKey = ShiftKey;
        p->KeyCode = KeyCode;
        p->controllerIdx = controllerIdx;
        return r;
    }

    // @0x1424c6060
    // The Instances::fl_gfx ctors that take InstanceTraits::Traits& are `inline` under cl, so their out-of-line copies
    // here are COMDAT-any and the inline copies sfr_as3_15 carries (cl emits them) no longer clash with them in the
    // fullexe link (LNK2005). MS2_Sfr14EmitInstanceCtors at the end of the unit keeps them emitted. clang-cl ignores
    // inline_depth, so the hook DLL build keeps them as plain definitions.
    SFR14_INSTANCE_CTOR GamePadAnalogEvent::GamePadAnalogEvent(InstanceTraits::Traits& t)
        : Event(t)
    {
    }

    // @0x1424c8a20
    void GamePadAnalogEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
        {
            UInt32 v;
            argv[3].Convert2UInt32(v);
            Code = v;
        }
        if (argc >= 5)
        {
            UInt32 v;
            argv[4].Convert2UInt32(v);
            ControllerIdx = v;
        }
        if (argc >= 6)
        {
            Value::Number v;
            argv[5].Convert2Number(v);
            XValue = v;
        }
        if (argc >= 7)
        {
            Value::Number v;
            argv[6].Convert2Number(v);
            YValue = v;
        }
    }

    // @0x1424c90a0
    AS3::Object* GamePadAnalogEvent::GetEventClass() const
    {
        return NULL;
    }

    // @0x1424c8b30
    SPtr<Instances::fl_events::Event> GamePadAnalogEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> r = Event::Clone();
        GamePadAnalogEvent* p = static_cast<GamePadAnalogEvent*>(r.GetPtr());
        p->ControllerIdx = ControllerIdx;
        p->XValue = XValue;
        p->YValue = YValue;
        return r;
    }

    // @0x1424c61c0
    SFR14_INSTANCE_CTOR IMECandidateListStyle::IMECandidateListStyle(InstanceTraits::Traits& t)
        : Object(t)
        , textColor(-1), selectedTextColor(-1), fontSize(-1), backgroundColor(-1), selectedBackgroundColor(-1)
        , indexBackgroundColor(-1), selectedIndexBackgroundColor(-1), readingWindowTextColor(-1)
        , readingWindowBackgroundColor(-1), readingWindowFontSize(-1)
    {
    }

    // @0x1424c6420
    SFR14_INSTANCE_CTOR IMEEventEx::IMEEventEx(InstanceTraits::Traits& t)
        : Event(t)
        , message(GetVM().GetStringManager().CreateEmptyString())
    {
    }

    // @0x1424c67b0
    SFR14_INSTANCE_CTOR KeyboardEventEx::KeyboardEventEx(InstanceTraits::Traits& t)
        : KeyboardEvent(t)
        , controllerIdx(0)
    {
    }

    // @0x1424c90b0
    AS3::Object* KeyboardEventEx::GetEventClass() const
    {
        return static_cast<ASVM&>(GetVM()).KeyboardEventExClass;
    }

    // @0x1424c8b70
    SPtr<Instances::fl_events::Event> KeyboardEventEx::Clone() const
    {
        SPtr<Instances::fl_events::Event> r = Event::Clone();
        KeyboardEventEx* p = static_cast<KeyboardEventEx*>(r.GetPtr());
        p->EvtId.Id = EvtId.Id;
        p->EvtId.WcharCode = EvtId.WcharCode;
        p->EvtId.KeyCode = EvtId.KeyCode;
        p->EvtId.AsciiCode = EvtId.AsciiCode;
        p->EvtId.RollOverCnt = EvtId.RollOverCnt;
        p->EvtId.ControllerIndex = EvtId.ControllerIndex;
        p->EvtId.KeysState = EvtId.KeysState;
        p->EvtId.MouseWheelDelta = EvtId.MouseWheelDelta;
        p->KeyLocation = KeyLocation;
        p->controllerIdx = controllerIdx;
        return r;
    }

    // @0x1424c6950
    SFR14_INSTANCE_CTOR MouseCursorEvent::MouseCursorEvent(InstanceTraits::Traits& t)
        : Event(t)
        , cursor(GetVM().GetStringManager().CreateEmptyString())
    {
        Bubbles = false;
        Cancelable = true;
        mouseIdx = 0;
    }

    // @0x1424c6b20
    SFR14_INSTANCE_CTOR MouseEventEx::MouseEventEx(InstanceTraits::Traits& t)
        : MouseEvent(t)
        , mouseIdx(0), buttonIdx(0), nestingIdx(0)
    {
    }

    // @0x1424c90c0
    AS3::Object* MouseEventEx::GetEventClass() const
    {
        return static_cast<ASVM&>(GetVM()).MouseEventExClass;
    }

    // @0x1424c8bf0
    SPtr<Instances::fl_events::Event> MouseEventEx::Clone() const
    {
        SPtr<Instances::fl_events::Event> r = Event::Clone();
        MouseEventEx* p = static_cast<MouseEventEx*>(r.GetPtr());
        p->AltKey = AltKey;
        p->CtrlKey = CtrlKey;
        p->ShiftKey = ShiftKey;
        p->Delta = Delta;
        p->RelatedObj = RelatedObj;
        p->LocalX = LocalX;
        p->LocalY = LocalY;
        p->StageX = StageX;
        p->StageY = StageY;
        p->ButtonsMask = ButtonsMask;
        p->LocalInitialized = LocalInitialized;
        p->mouseIdx = mouseIdx;
        return r;
    }

    // @0x1424c6e10
    SFR14_INSTANCE_CTOR TextEventEx::TextEventEx(InstanceTraits::Traits& t)
        : TextEvent(t)
        , controllerIdx(0), buttonIdx(0)
    {
    }

    // @0x1424c90d0
    AS3::Object* TextEventEx::GetEventClass() const
    {
        return static_cast<ASVM&>(GetVM()).TextEventExClass;
    }

    // @0x1424c8ca0
    SPtr<Instances::fl_events::Event> TextEventEx::Clone() const
    {
        SPtr<Instances::fl_events::Event> r = Event::Clone();
        TextEventEx* p = static_cast<TextEventEx*>(r.GetPtr());
        p->Text = Text;
        p->controllerIdx = controllerIdx;
        p->buttonIdx = buttonIdx;
        return r;
    }
}}

namespace InstanceTraits { namespace fl_gfx
{
    // @0x1424c5400
    FocusEventEx::FocusEventEx(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::FocusEventEx));
    }

    // @0x1424c6030
    GamePadAnalogEvent::GamePadAnalogEvent(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::GamePadAnalogEvent));
    }

    // @0x1424c6190
    IMECandidateListStyle::IMECandidateListStyle(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::IMECandidateListStyle));
    }

    // @0x1424c63f0
    IMEEventEx::IMEEventEx(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::IMEEventEx));
    }

    // @0x1424c6780
    KeyboardEventEx::KeyboardEventEx(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::KeyboardEventEx));
    }

    // @0x1424c6920
    MouseCursorEvent::MouseCursorEvent(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::MouseCursorEvent));
    }

    // @0x1424c6af0
    MouseEventEx::MouseEventEx(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::MouseEventEx));
    }

    // @0x1424c6de0
    TextEventEx::TextEventEx(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl_gfx::TextEventEx));
    }
}}

namespace Classes { namespace fl_gfx
{
    // @0x1424c52c0
    Extensions::Extensions(ClassTraits::Traits& t)
        : Class(t)
        , EDGEAA_INHERIT(0), EDGEAA_ON(1), EDGEAA_OFF(2), EDGEAA_DISABLE(3)
    {
    }

    // @0x1424c5540
    FocusManager::FocusManager(ClassTraits::Traits& t)
        : Class(t)
    {
    }

    // @0x1424c5650
    GamePad::GamePad(ClassTraits::Traits& t)
        : Class(t)
    {
        // PAD_START keeps its undefined value in the exe.
        PAD_NONE.SetUInt32(0);
        PAD_BACK.SetUInt32(0xff00);
        PAD_A.SetUInt32(0xff02);
        PAD_B.SetUInt32(0xff03);
        PAD_X.SetUInt32(0xff04);
        PAD_Y.SetUInt32(0xff05);
        PAD_R1.SetUInt32(0xff06);
        PAD_L1.SetUInt32(0xff07);
        PAD_R2.SetUInt32(0xff08);
        PAD_L2.SetUInt32(0xff09);
        PAD_UP.SetUInt32(0xff0a);
        PAD_DOWN.SetUInt32(0xff0b);
        PAD_RIGHT.SetUInt32(0xff0c);
        PAD_LEFT.SetUInt32(0xff0d);
        PAD_PLUS.SetUInt32(0xff0e);
        PAD_MINUS.SetUInt32(0xff0f);
        PAD_1.SetUInt32(0xff10);
        PAD_2.SetUInt32(0xff11);
        PAD_H.SetUInt32(0xff12);
        PAD_C.SetUInt32(0xff13);
        PAD_Z.SetUInt32(0xff14);
        PAD_O.SetUInt32(0xff15);
        PAD_T.SetUInt32(0xff16);
        PAD_S.SetUInt32(0xff17);
        PAD_SELECT.SetUInt32(0xff18);
        PAD_HOME.SetUInt32(0xff19);
        PAD_RT.SetUInt32(0xff1a);
        PAD_LT.SetUInt32(0xff1b);
    }

    // @0x1424c7230
    GamePad::~GamePad()
    {
    }

    // @0x1424c6540
    IMEEx::IMEEx(ClassTraits::Traits& t)
        : Class(t)
    {
    }

    // @0x1424c8fb0
    void IMEEx::GetCompositionString(ASString& result)
    {
        MovieImpl* movie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (!movie)
            return;
        IMEManagerBase* pime = movie->GetIMEManager().GetPtr();
        if (pime)
        {
            String str(pime->GetCompositionString());
            result.AssignNode(result.GetManager()->CreateStringNode(str.ToCStr(), str.GetSize()));
        }
    }

    // @0x1424c9120
    void IMEEx::GetOSVersion(ASString& result)
    {
        MovieImpl* movie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (!movie)
            return;
        IMEManagerBase* pime = movie->GetIMEManager().GetPtr();
        if (pime)
        {
            String str = pime->GetWindowsVersion();
            result.AssignNode(result.GetManager()->CreateStringNode(str.ToCStr(), str.GetSize()));
        }
    }

    // @0x1424c6650
    InteractiveObjectEx::InteractiveObjectEx(ClassTraits::Traits& t)
        : Class(t)
    {
    }

    // @0x1424c6c50
    SystemEx::SystemEx(ClassTraits::Traits& t)
        : Class(t)
        , REPORT_SHORT_FILENAMES(1), REPORT_NO_CIRCULAR_REFERENCES(2), REPORT_SUPPRESS_OVERALL_STATS(4)
        , REPORT_ONLY_ANON_OBJ_ADDRESSES(8)
    {
    }

    // @0x1424c6f70
    TextFieldEx::TextFieldEx(ClassTraits::Traits& t)
        : Class(t)
        , VALIGN_NONE("none"), VALIGN_TOP("top"), VALIGN_CENTER("center"), VALIGN_BOTTOM("bottom")
        , TEXTAUTOSZ_NONE("none"), TEXTAUTOSZ_SHRINK("shrink"), TEXTAUTOSZ_FIT("fit")
    {
    }

    // @0x1424c6000
    GamePadAnalogEvent::GamePadAnalogEvent(ClassTraits::Traits& t)
        : Class(t)
        , CHANGE("gamePadAnalogChange")
    {
    }

    // @0x1424c6370
    IMEEventEx::IMEEventEx(ClassTraits::Traits& t)
        : Class(t)
        , SET_CURRENT_INPUT_LANGUAGE("SetCurrentInputLanguage")
        , SET_SUPPORTED_LANGUAGES("SetSupportedLanguages")
        , SET_SUPPORTED_IMENAMES("SetSupportedIMENames")
        , SET_IMENAME("SetIMEName")
        , SET_CURRENT_LANGUAGE("SetCurrentLanguage")
        , REMOVE_STATUS_WINDOW("RemoveStatusWindow")
        , DISPLAY_STATUS_WINDOW("DisplayStatusWindow")
        , SET_CONVERSION_STATUS("SetConversionStatus")
    {
    }

    // @0x1424c68f0
    MouseCursorEvent::MouseCursorEvent(ClassTraits::Traits& t)
        : Class(t)
        , CURSOR_CHANGE("mouseCursorChange")
    {
    }

    // @0x1424c6ab0
    MouseEventEx::MouseEventEx(ClassTraits::Traits& t)
        : Class(t)
        , LEFT_BUTTON(0), RIGHT_BUTTON(1), MIDDLE_BUTTON(2)
    {
    }

    // @0x1424c6da0
    TextEventEx::TextEventEx(ClassTraits::Traits& t)
        : Class(t)
        , LINK_MOUSE_OVER("linkMouseOver"), LINK_MOUSE_OUT("linkMouseOut")
    {
    }
}}

namespace ClassTraits { namespace fl_gfx
{
    // @0x1424c51c0
    Extensions::Extensions(VM& vm)
        : Traits(vm, AS3::fl_gfx::ExtensionsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::ExtensionsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::Extensions(*this)));
    }

    // @0x1424c1c40
    Pickable<Traits> Extensions::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Extensions(vm));
    }

    // @0x1424c5300
    FocusEventEx::FocusEventEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::FocusEventExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::FocusEventEx(vm, AS3::fl_gfx::FocusEventExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424c4870
    Pickable<Traits> FocusEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FocusEventEx(vm));
    }

    // @0x1424c5460
    FocusManager::FocusManager(VM& vm)
        : Traits(vm, AS3::fl_gfx::FocusManagerCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::FocusManagerCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::FocusManager(*this)));
    }

    // @0x1424c4730
    Pickable<Traits> FocusManager::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FocusManager(vm));
    }

    // @0x1424c5570
    GamePad::GamePad(VM& vm)
        : Traits(vm, AS3::fl_gfx::GamePadCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::GamePadCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::GamePad(*this)));
    }

    // @0x1424c3830
    Pickable<Traits> GamePad::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GamePad(vm));
    }

    // @0x1424c5ef0
    GamePadAnalogEvent::GamePadAnalogEvent(VM& vm)
        : Traits(vm, AS3::fl_gfx::GamePadAnalogEventCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::GamePadAnalogEvent(vm, AS3::fl_gfx::GamePadAnalogEventCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::GamePadAnalogEvent(*this)));
    }

    // @0x1424c4110
    Pickable<Traits> GamePadAnalogEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GamePadAnalogEvent(vm));
    }

    // @0x1424c6090
    IMECandidateListStyle::IMECandidateListStyle(VM& vm)
        : Traits(vm, AS3::fl_gfx::IMECandidateListStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::IMECandidateListStyle(vm, AS3::fl_gfx::IMECandidateListStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424c15e0
    Pickable<Traits> IMECandidateListStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IMECandidateListStyle(vm));
    }

    // @0x1424c6210
    IMEEventEx::IMEEventEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::IMEEventExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::IMEEventEx(vm, AS3::fl_gfx::IMEEventExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::IMEEventEx(*this)));
    }

    // @0x1424c1280
    Pickable<Traits> IMEEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IMEEventEx(vm));
    }

    // @0x1424c6460
    IMEEx::IMEEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::IMEExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_gfx::IMEExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::IMEEx(*this)));
    }

    // @0x1424c1720
    Pickable<Traits> IMEEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IMEEx(vm));
    }

    // @0x1424c6570
    InteractiveObjectEx::InteractiveObjectEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::InteractiveObjectExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::InteractiveObjectExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::InteractiveObjectEx(*this)));
    }

    // @0x1424c3350
    Pickable<Traits> InteractiveObjectEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InteractiveObjectEx(vm));
    }

    // @0x1424c6680
    KeyboardEventEx::KeyboardEventEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::KeyboardEventExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::KeyboardEventEx(vm, AS3::fl_gfx::KeyboardEventExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424c3520
    Pickable<Traits> KeyboardEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) KeyboardEventEx(vm));
    }

    // @0x1424c67e0
    MouseCursorEvent::MouseCursorEvent(VM& vm)
        : Traits(vm, AS3::fl_gfx::MouseCursorEventCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::MouseCursorEvent(vm, AS3::fl_gfx::MouseCursorEventCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::MouseCursorEvent(*this)));
    }

    // @0x1424c3090
    Pickable<Traits> MouseCursorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MouseCursorEvent(vm));
    }

    // @0x1424c69a0
    MouseEventEx::MouseEventEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::MouseEventExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::MouseEventEx(vm, AS3::fl_gfx::MouseEventExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::MouseEventEx(*this)));
    }

    // @0x1424c2dc0
    Pickable<Traits> MouseEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MouseEventEx(vm));
    }

    // @0x1424c6b50
    SystemEx::SystemEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::SystemExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::SystemExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::SystemEx(*this)));
    }

    // @0x1424c31f0
    Pickable<Traits> SystemEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SystemEx(vm));
    }

    // @0x1424c6c90
    TextEventEx::TextEventEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::TextEventExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_gfx::TextEventEx(vm, AS3::fl_gfx::TextEventExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::TextEventEx(*this)));
    }

    // @0x1424c4ad0
    Pickable<Traits> TextEventEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextEventEx(vm));
    }

    // @0x1424c6e40
    TextFieldEx::TextFieldEx(VM& vm)
        : Traits(vm, AS3::fl_gfx::TextFieldExCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_gfx::TextFieldExCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_gfx::TextFieldEx(*this)));
    }

    // @0x1424c3950
    Pickable<Traits> TextFieldEx::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextFieldEx(vm));
    }
}}

// The movie's log, for the fl_gfx natives' LogBase helpers.
// Through the StateBag directly (no MovieImpl::GetLog wrapper): the exe reads the Ptr through the call's result register.
Log* ASVM::GetLog() const
{
    return GetMovieImpl()->GetStateBag()->GetLog();
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform {

// The out-of-line array destructors the fl_gfx natives (TextFieldEx image substitutions) instantiate. The render
// Text headers do not mix with this kernel tree, so the elements are stand-ins with the exe layouts (pinned below):
// DocView::ImageSubstitutor::Element and StyledText::HTMLImageTagInfo, whose ImageDesc is a RefCountBaseNTS.
struct MS2_ImageSubstElement                // 0x38 bytes
{
    wchar_t              SubString[20];
    Ptr<RefCountNTSImpl> pImageDesc;        // +0x28
    UByte                SubStringLen;
};
struct MS2_HTMLImageTagInfo                 // 0x40 bytes
{
    Ptr<RefCountNTSImpl> pTextImageDesc;
    StringDH             Url;               // +0x08
    StringDH             Id;                // +0x18
    unsigned             Width, Height;
    int                  VSpace, HSpace;
    unsigned             ParaId;
    UByte                Alignment;
};
template ArrayDataBase<MS2_ImageSubstElement, AllocatorLH<MS2_ImageSubstElement, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<MS2_HTMLImageTagInfo, AllocatorDH<MS2_HTMLImageTagInfo, 2>, ArrayDefaultPolicy>::~ArrayDataBase();

// The VM's SPtr<VMAbcFile> array; VMAbcFile is not recovered yet, so a GC-object stand-in (its SPtr releases through
// the GC base like any other).
class MS2_VMAbcFile : public GFx::AS3::GASRefCountBase
{
};
template ArrayDataBase<GFx::AS3::SPtr<MS2_VMAbcFile>, AllocatorGH<GFx::AS3::SPtr<MS2_VMAbcFile>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();

} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {

// Calls each inline Instances::fl_gfx ctor above out of line (inline_depth 0), so cl emits their bodies (and with them the
// vftables and deleting dtors) in this unit. Nothing calls it.
#pragma inline_depth(0)
void MS2_Sfr14EmitInstanceCtors(void* p, InstanceTraits::Traits& t)
{
    using namespace Instances::fl_gfx;
    new(p) GamePadAnalogEvent(t);
    new(p) IMECandidateListStyle(t);
    new(p) IMEEventEx(t);
    new(p) KeyboardEventEx(t);
    new(p) MouseCursorEvent(t);
    new(p) MouseEventEx(t);
    new(p) TextEventEx(t);
}
#pragma inline_depth()

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7Dictionary@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171980
// MS2-PIN: ??_7Endian@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171a10
// MS2-PIN: ??_7IDataInput@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171b80
// MS2-PIN: ??_7IDataOutput@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171c10
// MS2-PIN: ??_7IExternalizable@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171ca8
// MS2-PIN: ??_7Proxy@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171d40
// MS2-PIN: ??_7Timer@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171f38
// MS2-PIN: ??_7Dictionary@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431718d8
// MS2-PIN: ??_7Timer@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143171e98
// MS2-PIN: ??_7Endian@fl_utils@Classes@AS3@GFx@Scaleform@@6B@ 0x143171aa0
// MS2-PIN: ??_GDictionary@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bcf70
// MS2-PIN: ??_GEndian@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd0d0
// MS2-PIN: ??_GIDataInput@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd1c0
// MS2-PIN: ??_GIDataOutput@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd250
// MS2-PIN: ??_GIExternalizable@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd2e0
// MS2-PIN: ??_GProxy@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd370
// MS2-PIN: ??_GTimer@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd400
// MS2-PIN: ??_GDictionary@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd000
// MS2-PIN: ??_GTimer@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd490
// MS2-PIN: ??_GEndian@fl_utils@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd160
// MS2-PIN: ??0ByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@QEAA@AEAVTraits@InstanceTraits@345@@Z 0x1424bc460
// MS2-PIN: ??_7ByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@6B@ 0x1431713f8
// MS2-PIN: ??_7ByteArray@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431714c0
// MS2-PIN: ??_7ByteArray@fl_utils@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143171568
// MS2-PIN: ??_7ByteArray@fl_utils@Classes@AS3@GFx@Scaleform@@6B@ 0x1431715f8
// MS2-PIN: ??_7Dictionary@fl_utils@Instances@AS3@GFx@Scaleform@@6B@ 0x143171810
// MS2-PIN: ??_7Timer@fl_utils@Instances@AS3@GFx@Scaleform@@6B@ 0x143171dd0
// MS2-PIN: ??_GByteArray@fl_utils@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bcdb0
// MS2-PIN: ??_GByteArray@fl_utils@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bce40
// MS2-PIN: ??_GByteArray@fl_utils@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bcea0
// MS2-PIN: ??_GDictionary@fl_utils@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424bd060
// MS2-PIN: ?Reserve@?$ArrayDataBase@EU?$AllocatorLH_POD@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1424bee00
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VValue@AS3@GFx@Scaleform@@V1234@UHashFunctor@1234@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@VValue@AS3@GFx@Scaleform@@V1234@UHashFunctor@1234@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1424c0010

// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$06V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c0d70
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$07K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c0e70
// MS2-PIN: ?Func@?$ThunkFunc2@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVInteractiveObject@fl_display@Instances@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c0ed0
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$09KPEAVInteractiveObject@fl_display@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c0f80
// MS2-PIN: ?Func@?$ThunkFunc2@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0L@_NKK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1020
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0M@KK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1120
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0N@KK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c11d0
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0O@V?$SPtr@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1430
// MS2-PIN: ?Func@?$ThunkFunc2@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@PEAVSprite@fl_display@Instances@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1530
// MS2-PIN: ?Func@?$ThunkFunc0@VIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VIMECandidateListStyle@fl_gfx@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1860
// MS2-PIN: ?Func@?$ThunkFunc1@VIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVIMECandidateListStyle@2Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1910
// MS2-PIN: ?Func@?$ThunkFunc3@VIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAVSprite@fl_display@Instances@456@AEBVASString@56@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1950
// MS2-PIN: ?Func@?$ThunkFunc0@VIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1b60
// MS2-PIN: ?Func@?$ThunkFunc0@VIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1bd0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@PEAVTextField@fl_text@Instances@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1da0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVTextField@fl_text@Instances@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c1ed0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$01VASString@56@PEAVTextField@fl_text@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2000
// MS2-PIN: ?Func@?$ThunkFunc2@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$02$$CBVValue@456@PEAVTextField@fl_text@Instances@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c20a0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$03VASString@56@PEAVTextField@fl_text@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c21d0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAVTextField@fl_text@Instances@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2270
// MS2-PIN: ?Func@?$ThunkFunc2@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$05$$CBVValue@456@PEAVTextField@fl_text@Instances@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2300
// MS2-PIN: ?Func@?$ThunkFunc3@VTextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVTextField@fl_text@Instances@456@AEBVASString@56@PEAVBitmapData@fl_display@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2490
// MS2-PIN: ?Func@?$ThunkFunc1@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2610
// MS2-PIN: ?Func@?$ThunkFunc0@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2670
// MS2-PIN: ?Func@?$ThunkFunc1@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c26d0
// MS2-PIN: ?Func@?$ThunkFunc0@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2730
// MS2-PIN: ?Func@?$ThunkFunc3@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$03V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@NN_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2790
// MS2-PIN: ?Func@?$ThunkFunc2@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$04V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@_NK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2920
// MS2-PIN: ?Func@?$ThunkFunc2@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$05$$CBVValue@456@AEBVASString@56@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2a70
// MS2-PIN: ?Func@?$ThunkFunc1@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$06VASString@56@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2bc0
// MS2-PIN: ?Func@?$ThunkFunc1@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$07KPEAVDisplayObject@fl_display@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2c70
// MS2-PIN: ?Func@?$ThunkFunc2@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVDisplayObject@fl_display@Instances@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2d10
// MS2-PIN: ?Func@?$ThunkFunc0@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$09K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2f20
// MS2-PIN: ?Func@?$ThunkFunc0@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$0L@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c2f80
// MS2-PIN: ?Func@?$ThunkFunc0@VExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3030
// MS2-PIN: ?Func@?$ThunkFunc2@VInteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@PEAVInteractiveObject@fl_display@Instances@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3490
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$00_NPEAVInteractiveObject@fl_display@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3660
// MS2-PIN: ?Func@?$ThunkFunc2@VInteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAVInteractiveObject@fl_display@Instances@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3700
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$02_NPEAVInteractiveObject@fl_display@Instances@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3790
// MS2-PIN: ?Func@?$ThunkFunc1@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3ad0
// MS2-PIN: ?Func@?$ThunkFunc0@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3b30
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePad@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3b90
// MS2-PIN: ?Func@?$ThunkFunc1@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3bf0
// MS2-PIN: ?Func@?$ThunkFunc0@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3c80
// MS2-PIN: ?Func@?$ThunkFunc0@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3cf0
// MS2-PIN: ?Func@?$ThunkFunc0@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$04V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3d60
// MS2-PIN: ?Func@?$ThunkFunc1@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$05VASString@56@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3e10
// MS2-PIN: ?Func@?$ThunkFunc3@VSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@$06$$CBVValue@456@_NKAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c3f90
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4270
// MS2-PIN: ?Func@?$ThunkFunc1@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c42d0
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$01K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4340
// MS2-PIN: ?Func@?$ThunkFunc1@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c43a0
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4410
// MS2-PIN: ?Func@?$ThunkFunc1@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4480
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4510
// MS2-PIN: ?Func@?$ThunkFunc1@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4580
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4610
// MS2-PIN: ?Func@?$ThunkFunc0@VGamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c46c0
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c49b0
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4a10
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4a70
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4c30
// MS2-PIN: ?Func@?$ThunkFunc4@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$03V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@PEAVInteractiveObject@fl_display@Instances@456@_NK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4c90
// MS2-PIN: ?Func@?$ThunkFunc6@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$04V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@PEAVDisplayObjectContainer@fl_display@Instances@456@_NPEAVInteractiveObject@fl_display@Instances@456@_NK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4e60
// MS2-PIN: ?Func@?$ThunkFunc2@VFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@$05$$CBVValue@456@PEAVInteractiveObject@fl_display@Instances@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424c4f80
// MS2-PIN: ??_7FocusEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x1431752e8
// MS2-PIN: ??_7GamePadAnalogEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143174fb0
// MS2-PIN: ??_7IMECandidateListStyle@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143175be8
// MS2-PIN: ??_7IMEEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143175830
// MS2-PIN: ??_7KeyboardEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143174c10
// MS2-PIN: ??_7MouseCursorEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x1431741e8
// MS2-PIN: ??_7MouseEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143174908
// MS2-PIN: ??_7TextEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@6B@ 0x143175508
// MS2-PIN: ??_7Extensions@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143174100
// MS2-PIN: ??_7FocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143173f38
// MS2-PIN: ??_7GamePad@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143174ec8
// MS2-PIN: ??_7IMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143175ea0
// MS2-PIN: ??_7InteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x1431745c0
// MS2-PIN: ??_7SystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143173db8
// MS2-PIN: ??_7TextFieldEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143174748
// MS2-PIN: ??_7GamePadAnalogEvent@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x1431751e0
// MS2-PIN: ??_7IMEEventEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143175a48
// MS2-PIN: ??_7MouseCursorEvent@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143174418
// MS2-PIN: ??_7MouseEventEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143174b28
// MS2-PIN: ??_7TextEventEx@fl_gfx@Classes@AS3@GFx@Scaleform@@6B@ 0x143175728
// MS2-PIN: ??_7FocusEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431753c8
// MS2-PIN: ??_7GamePadAnalogEvent@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143175098
// MS2-PIN: ??_7IMECandidateListStyle@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143175cc0
// MS2-PIN: ??_7IMEEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143175910
// MS2-PIN: ??_7KeyboardEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143174cf8
// MS2-PIN: ??_7MouseCursorEvent@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431742d0
// MS2-PIN: ??_7MouseEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431749e8
// MS2-PIN: ??_7TextEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431755e8
// MS2-PIN: ??_7Extensions@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174070
// MS2-PIN: ??_7FocusEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143175470
// MS2-PIN: ??_7FocusManager@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143173ea0
// MS2-PIN: ??_7GamePad@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174e38
// MS2-PIN: ??_7GamePadAnalogEvent@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143175148
// MS2-PIN: ??_7IMECandidateListStyle@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143175d70
// MS2-PIN: ??_7IMEEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431759b8
// MS2-PIN: ??_7IMEEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143175e10
// MS2-PIN: ??_7InteractiveObjectEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174520
// MS2-PIN: ??_7KeyboardEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174da0
// MS2-PIN: ??_7MouseCursorEvent@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174380
// MS2-PIN: ??_7MouseEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143174a90
// MS2-PIN: ??_7SystemEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143173d28
// MS2-PIN: ??_7TextEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143175690
// MS2-PIN: ??_7TextFieldEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431746b0
// MS2-PIN: ??_GMouseCursorEvent@fl_gfx@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8430
// MS2-PIN: ??_GTextEventEx@fl_gfx@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c88c0
// MS2-PIN: ??_GExtensions@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7730
// MS2-PIN: ??_GFocusManager@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c79a0
// MS2-PIN: ??_GIMEEx@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8040
// MS2-PIN: ??_GInteractiveObjectEx@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8130
// MS2-PIN: ??_GSystemEx@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8710
// MS2-PIN: ??_GGamePadAnalogEvent@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7b80
// MS2-PIN: ??_GMouseCursorEvent@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8370
// MS2-PIN: ??_GMouseEventEx@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8530
// MS2-PIN: ??_GTextEventEx@fl_gfx@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8800
// MS2-PIN: ??_GFocusEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7820
// MS2-PIN: ??_GGamePadAnalogEvent@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7be0
// MS2-PIN: ??_GIMECandidateListStyle@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7d30
// MS2-PIN: ??_GIMEEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7ee0
// MS2-PIN: ??_GKeyboardEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8220
// MS2-PIN: ??_GMouseCursorEvent@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c83d0
// MS2-PIN: ??_GMouseEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8590
// MS2-PIN: ??_GTextEventEx@fl_gfx@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8860
// MS2-PIN: ??_GExtensions@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c76a0
// MS2-PIN: ??_GFocusEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7790
// MS2-PIN: ??_GFocusManager@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7910
// MS2-PIN: ??_GGamePad@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7a00
// MS2-PIN: ??_GGamePadAnalogEvent@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7af0
// MS2-PIN: ??_GIMECandidateListStyle@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7ca0
// MS2-PIN: ??_GIMEEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7df0
// MS2-PIN: ??_GIMEEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c7fb0
// MS2-PIN: ??_GInteractiveObjectEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c80a0
// MS2-PIN: ??_GKeyboardEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8190
// MS2-PIN: ??_GMouseCursorEvent@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c82e0
// MS2-PIN: ??_GMouseEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c84a0
// MS2-PIN: ??_GSystemEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8680
// MS2-PIN: ??_GTextEventEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8770
// MS2-PIN: ??_GTextFieldEx@fl_gfx@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424c8930
// MS2-PIN: ??1?$ArrayDataBase@UMS2_ImageSubstElement@Scaleform@@U?$AllocatorLH@UMS2_ImageSubstElement@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAA@XZ 0x1424c7090
// MS2-PIN: ??1?$ArrayDataBase@UMS2_HTMLImageTagInfo@Scaleform@@U?$AllocatorDH@UMS2_HTMLImageTagInfo@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAA@XZ 0x1424c7100
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VMS2_VMAbcFile@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorGH@V?$SPtr@VMS2_VMAbcFile@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1424c71b0
// MS2-PIN: ?GetLog@ASVM@AS3@GFx@Scaleform@@QEBAPEAVLog@4@XZ 0x1424c90e0
// The delayed-release proxy the Dictionary GC builds; its bases' tables only appear in its inline ctors, whose stores
// the exe drops, so they pair with the proxy's own one-slot table (the folded deleting dtor).
// MS2-PIN: ??_7?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@6B@ 0x14314ba40
// MS2-PIN: ??_7?$RefCountBase@V?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@$0BEI@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEI@@Scaleform@@6B@ 0x142dc9d48
