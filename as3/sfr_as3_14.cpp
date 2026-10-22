// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_14
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424bb1f0-0x1424c2a70 .text$mn
// MS2-RANGE: 0x1424c52c0-0x1424c91f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/kernel/sf_wstring.h"

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
        vm.ThrowRangeError(VM::Error(VM::eInvalidEnumError, vm, "some type", "encAMF0 or encAMF3"));
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

    // MS2-FUNCTIONAL: MakeObject: Pickable/Value assignment scheduling differs
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
            static_cast<ASVM&>(GetVM()).GetMovieImpl()->ClearIntervalTimer(pCoreTimer->GetId());
        pCoreTimer = NULL;
    }

    // ---- ByteArray ----

    // @0x1424bc460
    ByteArray::ByteArray(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Encoding((EncodingType)static_cast<Classes::fl_utils::ByteArray&>(t.GetConstructor()).DefaultObjectEncoding)
        , Endian(endianBig)
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

    // MS2-FUNCTIONAL: VM::Error temporary construction/destruction scheduling differs
    // @0x1424bf180
    void ByteArray::ThrowEOFError()
    {
        VM& vm = GetVM();
        Value v;
        vm.Construct("flash.errors.EOFError", v, 0, NULL, true);
        if (!vm.IsException() && !v.IsNullOrUndefined())
            GetVM().Throw(v);
    }

    // MS2-FUNCTIONAL: VM::Error temporary construction/destruction scheduling differs
    // @0x1424bf250
    void ByteArray::ThrowMemoryError()
    {
        VM& vm = GetVM();
        Value v;
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

    // MS2-FUNCTIONAL: block order / register allocation of the EOF check differs
    // @0x1424bec50
    CheckResult ByteArray::Read(void* dest, UInt32 n)
    {
        if (Data.GetSize() < (UPInt)(Position + n))
        {
            ThrowEOFError();
            return false;
        }
        memcpy(dest, Data.GetDataPtr() + Position, n);
        Position += n;
        return true;
    }

    // MS2-FUNCTIONAL: string-node creation call shape differs
    // @0x1424bed20
    CheckResult ByteArray::ReadUTFBytes(ASString& result, UInt32 len)
    {
        if (Data.GetSize() < (UPInt)(Position + len))
        {
            ThrowEOFError();
            return false;
        }
        const char* p = (const char*)Data.GetDataPtr() + Position;
        // A UTF-8 byte order mark is skipped.
        if (len > 2 && (UInt8)p[0] == 0xef && (UInt8)p[1] == 0xbb && (UInt8)p[2] == 0xbf)
        {
            len -= 3;
            Position += 3;
        }
        result = GetVM().GetStringManager().CreateString((const char*)Data.GetDataPtr() + Position, len);
        Position += len;
        return true;
    }

    // @0x1424bef20
    void ByteArray::Resize(UInt32 size)
    {
        UPInt oldSize = Data.GetSize();
        if (oldSize < size)
        {
            Data.Resize(size);
            memset(Data.GetDataPtr() + oldSize, 0, size - oldSize);
        }
        Length = size;
        if (size < Position)
            Position = size;
    }

    // MS2-FUNCTIONAL: exe calls ArrayBase::Resize out of line; ours inlines it
    // @0x1424bf320
    void ByteArray::Write(UInt8 v)
    {
        GrowFor(1);
        Data[Position++] = v;
    }

    // MS2-FUNCTIONAL: grow + memcpy register allocation differs
    // @0x1424bf440
    void ByteArray::Write(const void* src, UInt32 n)
    {
        GrowFor(n);
        memcpy(Data.GetDataPtr() + Position, src, n);
        Position += n;
    }

    // Reads one value in the array's byte order; on EOF throws and leaves v as it was.
    template <typename T>
    inline bool ByteArray::ReadValue(T& v)
    {
        if (Position + (UInt32)sizeof(T) > Data.GetSize())
        {
            ThrowEOFError();
            return false;
        }
        memcpy(&v, Data.GetDataPtr() + Position, sizeof(T));
        Position += sizeof(T);
        if (Endian != endianLittle)
            v = SwapBytes(v);
        return true;
    }

    template <typename T>
    inline void ByteArray::WriteValue(T v)
    {
        if (Endian != endianLittle)
            v = SwapBytes(v);
        GrowFor(sizeof(T));
        *reinterpret_cast<T*>(Data.GetDataPtr() + Position) = v;
        Position += sizeof(T);
    }

    // @0x1424be400
    UInt8 ByteArray::Get(UInt32 ind) const
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

    // @0x1424bf580
    void ByteArray::bytesAvailableGet(UInt32& result)
    {
        result = (UInt32)(Data.GetSize() - Position);
    }

    // zlib-compresses the content in place; the position ends after it.
    // MS2-FUNCTIONAL: tail call into the compress helper differs
    // @0x1424bf590
    void ByteArray::compress(Value& result, unsigned, const Value*)
    {
        SF_UNUSED(result);
        if (Length == 0)
            return;
        unsigned long destLen = Length * 3 / 2 + 0x20;
        UInt8* buf = (UInt8*)SF_HEAP_AUTO_ALLOC(this, destLen);
        compress2(buf, &destLen, Data.GetDataPtr(), Length, 9);
        Length = 0;
        if (Position != 0)
            Position = 0;
        Write(buf, destLen);
        SF_FREE(buf);
    }

    // MS2-FUNCTIONAL: exe selects the string/length with separate branches; ours with cmov
    // @0x1424bf6d0
    void ByteArray::endianGet(ASString& result)
    {
        result = GetVM().GetStringManager().GetStringManager()->CreateConstString(Endian == endianBig ? "bigEndian" : "littleEndian", Endian == endianBig ? 9 : 12);
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
        vm.ThrowRangeError(VM::Error(VM::eInvalidEnumError, vm, "something", "encAMF0 or encAMF3"));
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
    // MS2-FUNCTIONAL: bounds checks / Resize call scheduling differ
    // @0x1424bf900
    void ByteArray::readBytes(const Value& result, Instances::fl_utils::ByteArray* bytes, UInt32 offset, UInt32 length)
    {
        SF_UNUSED(result);
        UInt32 avail = (UInt32)(Data.GetSize() - Position);
        if (length == 0 || length <= avail)
        {
            UInt32 n = length ? length : avail;
            UInt32 end = offset + n;
            if (bytes->Data.GetSize() < end)
                bytes->Resize(end);
            else if (bytes->Length < end)
                bytes->Length = end;
            if ((UPInt)(Position + n) <= Data.GetSize())
            {
                memcpy(bytes->Data.GetDataPtr() + offset, Data.GetDataPtr() + Position, n);
                Position += n;
                return;
            }
        }
        ThrowEOFError();
    }

    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bf9e0
    void ByteArray::readDouble(Value::Number& result)
    {
        ReadValue(result);
    }

    // MS2-FUNCTIONAL: inlined ReadValue + float conversion register allocation differs
    // @0x1424bfa30
    void ByteArray::readFloat(Value::Number& result)
    {
        float v;
        if (ReadValue(v))
            result = v;
    }

    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bfab0
    void ByteArray::readInt(SInt32& result)
    {
        ReadValue(reinterpret_cast<UInt32&>(result));
    }

    // MS2-FUNCTIONAL: charset lookup + string creation scheduling differs
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
            ReadUTFBytes(result, length);
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

    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bfde0
    void ByteArray::readShort(SInt32& result)
    {
        UInt16 v;
        ReadValue(v);
        result = (SInt16)v;
    }

    // A 16-bit length, then that many UTF-8 bytes.
    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bfe40
    void ByteArray::readUTF(ASString& result)
    {
        UInt16 len;
        ReadValue(len);
        ReadUTFBytes(result, len);
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

    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bff00
    void ByteArray::readUnsignedInt(UInt32& result)
    {
        ReadValue(result);
    }

    // MS2-FUNCTIONAL: inlined ReadValue register allocation differs
    // @0x1424bff40
    void ByteArray::readUnsignedShort(UInt32& result)
    {
        UInt16 v;
        ReadValue(v);
        result = v;
    }

    // The content as text: UTF-16 after a byte order mark, UTF-8 otherwise.
    // MS2-FUNCTIONAL: string creation from the data buffer: register allocation differs
    // @0x1424c0380
    void ByteArray::toString(ASString& result)
    {
        UPInt size = Data.GetSize();
        const char* p = (const char*)Data.GetDataPtr();
        if (size > 1)
        {
            if (((UInt8)p[0] == 0xfe && (UInt8)p[1] == 0xff) || ((UInt8)p[0] == 0xff && (UInt8)p[1] == 0xfe))
            {
                result = ASString(GetVM().GetStringManager().GetStringManager()->CreateStringNode(
                    (const wchar_t*)(p + 2), (SPInt)((size - 2) >> 1)));
                return;
            }
            if (size > 2 && (UInt8)p[0] == 0xef && (UInt8)p[1] == 0xbb && (UInt8)p[2] == 0xbf)
            {
                size -= 3;
                p += 3;
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
        Length = 0;
        if (Position != 0)
            Position = 0;

        z_stream_s zs;
        memset(&zs, 0, sizeof(zs));
        inflateInit_(&zs, "1.2.5", sizeof(zs));
        zs.next_in = src;
        zs.avail_in = len;
        UInt8* out = (UInt8*)SF_HEAP_AUTO_ALLOC(this, 0x2000);
        int ret;
        do
        {
            zs.avail_out = 0x2000;
            zs.next_out = out;
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

    // MS2-FUNCTIONAL: exe inlines Write(UInt8); ours tail-calls it
    // @0x1424c05c0
    void ByteArray::writeBoolean(const Value& result, bool value)
    {
        SF_UNUSED(result);
        Write((UInt8)value);
    }

    // MS2-FUNCTIONAL: exe inlines Write(UInt8); ours tail-calls it
    // @0x1424c0650
    void ByteArray::writeByte(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        Write((UInt8)value);
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

    // MS2-FUNCTIONAL: inlined WriteValue register allocation differs
    // @0x1424c07b0
    void ByteArray::writeFloat(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        WriteValue((float)value);
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
            if (wb.GetLength() < 0x100000000ULL)
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

    // MS2-FUNCTIONAL: inlined WriteValue register allocation differs
    // @0x1424c0ae0
    void ByteArray::writeShort(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        WriteValue((UInt16)value);
    }

    // A 16-bit length, then the UTF-8 bytes.
    // MS2-FUNCTIONAL: UTF length check + Write call scheduling differs
    // @0x1424c0b90
    void ByteArray::writeUTF(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        UInt32 size = value.GetSize();
        if (size < 0x10000)
        {
            UInt16 len = (UInt16)size;
            if (Endian != endianLittle)
                len = SwapBytes(len);
            Write(&len, 2);
            Write(value.ToCStr(), size);
            return;
        }
        VM& vm = GetVM();
        vm.ThrowRangeError(VM::Error(VM::eNotImplementedError, vm, "ByteArray::writeUTF"));
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
