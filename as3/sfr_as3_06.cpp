// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142438be0-0x142444560 .text$mn
// MS2-RANGE: 0x142445480-0x142446c10 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#undef GetObject   // windows.h

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl_display::BitmapData::getColorBoundsRect argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 15, 2, bool>
{
    SF_INLINE static bool Get(StringManager&) { return true; }
};
// thunk 0x142438be0: Instances::fl_display::BitmapData::getColorBoundsRect
template struct ThunkFunc3<Instances::fl_display::BitmapData, 15, SPtr<Instances::fl_geom::Rectangle>, UInt32, UInt32, bool>;
// thunk 0x142438d50: Instances::fl_display::DisplayObject::transformSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 43, const Value, Instances::fl_geom::Transform*>;
// thunk 0x142438d90: Instances::fl_display::MovieClip::currentSceneGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 4, SPtr<Instances::fl_display::Scene>>;
// thunk 0x142438e40: Instances::fl_display::BitmapData::getPixel
template struct ThunkFunc2<Instances::fl_display::BitmapData, 16, UInt32, SInt32, SInt32>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_display
{
    extern const ClassInfo AVM1MovieCI;
    extern const ClassInfo ActionScriptVersionCI;
    extern const ClassInfo BitmapCI;
    extern const ClassInfo BitmapDataCI;
    extern const ClassInfo BitmapDataChannelCI;
    extern const ClassInfo BlendModeCI;
    extern const ClassInfo CapsStyleCI;
    extern const ClassInfo DisplayObjectCI;
    extern const ClassInfo DisplayObjectContainerCI;
    extern const ClassInfo FrameLabelCI;
    extern const ClassInfo GradientTypeCI;
    extern const ClassInfo GraphicsCI;
    extern const ClassInfo IBitmapDrawableCI;
    extern const ClassInfo InteractiveObjectCI;
    extern const ClassInfo InterpolationMethodCI;
    extern const ClassInfo JointStyleCI;
    extern const ClassInfo LineScaleModeCI;
    extern const ClassInfo LoaderCI;
    extern const ClassInfo LoaderInfoCI;
    extern const ClassInfo MorphShapeCI;
    extern const ClassInfo MovieClipCI;
    extern const ClassInfo PixelSnappingCI;
    extern const ClassInfo SWFVersionCI;
    extern const ClassInfo SceneCI;
    extern const ClassInfo ShaderCI;
    extern const ClassInfo ShaderDataCI;
    extern const ClassInfo ShapeCI;
    extern const ClassInfo SimpleButtonCI;
    extern const ClassInfo SpreadMethodCI;
    extern const ClassInfo SpriteCI;
    extern const ClassInfo StageCI;
    extern const ClassInfo StageAlignCI;
    extern const ClassInfo StageDisplayStateCI;
    extern const ClassInfo StageQualityCI;
    extern const ClassInfo StageScaleModeCI;
}

// ---- AVM1Movie ----

namespace ClassTraits { namespace fl_display
{
    // @0x142439bf0
    AVM1Movie::AVM1Movie(VM& vm)
        : Traits(vm, AS3::fl_display::AVM1MovieCI)
    {
        TraitsType = Traits_AVM1Movie;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::AVM1Movie(vm, AS3::fl_display::AVM1MovieCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> AVM1Movie::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AVM1Movie(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x142439d00
    AVM1Movie::AVM1Movie(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_AVM1Movie;
        SetMemSize(0x68);
    }

    // @0x142445480
    void AVM1Movie::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x142439d30
    AVM1Movie::AVM1Movie(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObject(t)
    {
    }
}}

// ---- ActionScriptVersion ----

namespace ClassTraits { namespace fl_display
{
    // @0x142439d60
    ActionScriptVersion::ActionScriptVersion(VM& vm)
        : Traits(vm, AS3::fl_display::ActionScriptVersionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ActionScriptVersionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::ActionScriptVersion(*this)));
    }

    inline Pickable<Traits> ActionScriptVersion::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ActionScriptVersion(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x142439e50
    ActionScriptVersion::ActionScriptVersion(ClassTraits::Traits& t)
        : Class(t)
        , Actionscript2(2)
        , Actionscript3(3)
    {
    }
}}

// ---- Bitmap ----

namespace ClassTraits { namespace fl_display
{
    // @0x142439e80
    Bitmap::Bitmap(VM& vm)
        : Traits(vm, AS3::fl_display::BitmapCI)
    {
        TraitsType = Traits_Bitmap;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Bitmap(vm, AS3::fl_display::BitmapCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Bitmap::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Bitmap(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x142439f90
    Bitmap::Bitmap(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Bitmap;
        SetMemSize(0x78);
    }

    // @0x1424454e0
    void Bitmap::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x142439fc0
    Bitmap::Bitmap(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObject(t)
        , PixelSnapping(0)
        , Smoothing(true)
    {
    }
}}

// ---- BitmapData ----

namespace ClassTraits { namespace fl_display
{
    // @0x142439ff0
    BitmapData::BitmapData(VM& vm)
        : Traits(vm, AS3::fl_display::BitmapDataCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::BitmapData(vm, AS3::fl_display::BitmapDataCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> BitmapData::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapData(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243a170
    BitmapData::BitmapData(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x60);
        RegisterImplementedInterface(Multiname(GetVM(), StringDataPtr("flash.display.IBitmapDrawable")));
    }

    // @0x142445550
    void BitmapData::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243a220
    BitmapData::BitmapData(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Width(0)
        , Height(0)
        , Transparent(true)
        , Unk59(false)
    {
    }
}}

// ---- BitmapDataChannel ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243a260
    BitmapDataChannel::BitmapDataChannel(VM& vm)
        : Traits(vm, AS3::fl_display::BitmapDataChannelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::BitmapDataChannelCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::BitmapDataChannel(*this)));
    }

    inline Pickable<Traits> BitmapDataChannel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapDataChannel(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243a360
    BitmapDataChannel::BitmapDataChannel(ClassTraits::Traits& t)
        : Class(t)
        , Alpha(8)
        , Blue(4)
        , Green(2)
        , Red(1)
    {
    }
}}

// ---- BlendMode ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243a3a0
    BlendMode::BlendMode(VM& vm)
        : Traits(vm, AS3::fl_display::BlendModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::BlendModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::BlendMode(*this)));
    }

    inline Pickable<Traits> BlendMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BlendMode(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243a540
    BlendMode::BlendMode(ClassTraits::Traits& t)
        : Class(t)
        , Add("add")
        , Alpha("alpha")
        , Darken("darken")
        , Difference("difference")
        , Erase("erase")
        , Hardlight("hardlight")
        , Invert("invert")
        , Layer("layer")
        , Lighten("lighten")
        , Multiply("multiply")
        , Normal("normal")
        , Overlay("overlay")
        , Screen("screen")
        , Subtract("subtract")
    {
    }
}}

// ---- CapsStyle ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243a620
    CapsStyle::CapsStyle(VM& vm)
        : Traits(vm, AS3::fl_display::CapsStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::CapsStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::CapsStyle(*this)));
    }

    inline Pickable<Traits> CapsStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) CapsStyle(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243a720
    CapsStyle::CapsStyle(ClassTraits::Traits& t)
        : Class(t)
        , None("none")
        , Round("round")
        , Square("square")
    {
    }
}}

// ---- DisplayObject ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243a7d0
    DisplayObject::DisplayObject(VM& vm)
        : Traits(vm, AS3::fl_display::DisplayObjectCI)
    {
        TraitsType = Traits_DisplayObject;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::DisplayObject(vm, AS3::fl_display::DisplayObjectCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> DisplayObject::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplayObject(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243a960
    DisplayObject::DisplayObject(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_DisplayObject;
        SetMemSize(0x68);
        RegisterImplementedInterface(Multiname(GetVM(), StringDataPtr("flash.display.IBitmapDrawable")));
    }

    // @0x1424455d0
    void DisplayObject::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243aa10
    DisplayObject::DisplayObject(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
        pReleaseProxy = *SF_HEAP_AUTO_NEW(this) ReleaseProxy();
    }
}}

// ---- DisplayObjectContainer ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243aad0
    DisplayObjectContainer::DisplayObjectContainer(VM& vm)
        : Traits(vm, AS3::fl_display::DisplayObjectContainerCI)
    {
        TraitsType = Traits_DisplayObjectContainer;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::DisplayObjectContainer(vm, AS3::fl_display::DisplayObjectContainerCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> DisplayObjectContainer::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplayObjectContainer(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243abe0
    DisplayObjectContainer::DisplayObjectContainer(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_DisplayObjectContainer;
        SetMemSize(0x70);
    }

    // @0x142445610
    void DisplayObjectContainer::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243ac10
    DisplayObjectContainer::DisplayObjectContainer(InstanceTraits::Traits& t)
        : Instances::fl_display::InteractiveObject(t)
    {
    }
}}

// ---- FrameLabel ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243ac40
    FrameLabel::FrameLabel(VM& vm)
        : Traits(vm, AS3::fl_display::FrameLabelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::FrameLabel(vm, AS3::fl_display::FrameLabelCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> FrameLabel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FrameLabel(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243ad40
    FrameLabel::FrameLabel(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }

    // @0x142445670
    void FrameLabel::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243ad70
    FrameLabel::FrameLabel(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , FrameNumber(0xffffffff)
        , FrameName(GetVM().GetStringManager().CreateEmptyString())
    {
    }
}}

// ---- GradientType ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243adc0
    GradientType::GradientType(VM& vm)
        : Traits(vm, AS3::fl_display::GradientTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::GradientTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::GradientType(*this)));
    }

    inline Pickable<Traits> GradientType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GradientType(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243aec0
    GradientType::GradientType(ClassTraits::Traits& t)
        : Class(t)
        , Linear("linear")
        , Radial("radial")
    {
    }
}}

// ---- Graphics ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243af00
    Graphics::Graphics(VM& vm)
        : Traits(vm, AS3::fl_display::GraphicsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Graphics(vm, AS3::fl_display::GraphicsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Graphics::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Graphics(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243b000
    Graphics::Graphics(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }

    // @0x1424456f0
    void Graphics::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243b030
    Graphics::Graphics(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pDispObj(NULL)
    {
    }
}}

// ---- IBitmapDrawable ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b060
    IBitmapDrawable::IBitmapDrawable(VM& vm)
        : Traits(vm, AS3::fl_display::IBitmapDrawableCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_display::IBitmapDrawableCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> IBitmapDrawable::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IBitmapDrawable(vm));
    }
}}

// ---- InteractiveObject ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b140
    InteractiveObject::InteractiveObject(VM& vm)
        : Traits(vm, AS3::fl_display::InteractiveObjectCI)
    {
        TraitsType = Traits_InteractiveObject;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::InteractiveObject(vm, AS3::fl_display::InteractiveObjectCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> InteractiveObject::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InteractiveObject(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243b250
    InteractiveObject::InteractiveObject(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_InteractiveObject;
        SetMemSize(0x70);
    }

    // @0x142445760
    void InteractiveObject::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243b280
    InteractiveObject::InteractiveObject(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObject(t)
    {
    }
}}

// ---- InterpolationMethod ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b2b0
    InterpolationMethod::InterpolationMethod(VM& vm)
        : Traits(vm, AS3::fl_display::InterpolationMethodCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::InterpolationMethodCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::InterpolationMethod(*this)));
    }

    inline Pickable<Traits> InterpolationMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InterpolationMethod(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243b3b0
    InterpolationMethod::InterpolationMethod(ClassTraits::Traits& t)
        : Class(t)
        , LinearRgb("linearRGB")
        , Rgb("rgb")
    {
    }
}}

// ---- JointStyle ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b3f0
    JointStyle::JointStyle(VM& vm)
        : Traits(vm, AS3::fl_display::JointStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::JointStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::JointStyle(*this)));
    }

    inline Pickable<Traits> JointStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) JointStyle(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243b4f0
    JointStyle::JointStyle(ClassTraits::Traits& t)
        : Class(t)
        , Bevel("bevel")
        , Miter("miter")
        , Round("round")
    {
    }
}}

// ---- LineScaleMode ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b540
    LineScaleMode::LineScaleMode(VM& vm)
        : Traits(vm, AS3::fl_display::LineScaleModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::LineScaleModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::LineScaleMode(*this)));
    }

    inline Pickable<Traits> LineScaleMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LineScaleMode(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243b650
    LineScaleMode::LineScaleMode(ClassTraits::Traits& t)
        : Class(t)
        , Horizontal("horizontal")
        , None("none")
        , Normal("normal")
        , Vertical("vertical")
    {
    }
}}

// ---- Loader ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b6a0
    Loader::Loader(VM& vm)
        : Traits(vm, AS3::fl_display::LoaderCI)
    {
        TraitsType = Traits_Loader;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Loader(vm, AS3::fl_display::LoaderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Loader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Loader(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243b7b0
    Loader::Loader(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Loader;
        SetMemSize(0x78);
    }

    // @0x1424457c0
    void Loader::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243b7e0
    Loader::Loader(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObjectContainer(t)
    {
    }
}}

// ---- LoaderInfo ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b810
    LoaderInfo::LoaderInfo(VM& vm)
        : Traits(vm, AS3::fl_display::LoaderInfoCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::LoaderInfo(vm, AS3::fl_display::LoaderInfoCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::LoaderInfo(*this)));
    }

    inline Pickable<Traits> LoaderInfo::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LoaderInfo(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243b940
    LoaderInfo::LoaderInfo(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x68);
    }

    // @0x142445830
    void LoaderInfo::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243b970
    LoaderInfo::LoaderInfo(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
        BytesLoaded = 0;
        BytesTotal = 0;
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243b910
    LoaderInfo::LoaderInfo(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

// ---- MorphShape ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243b9a0
    MorphShape::MorphShape(VM& vm)
        : Traits(vm, AS3::fl_display::MorphShapeCI)
    {
        TraitsType = Traits_MorphShape;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::MorphShape(vm, AS3::fl_display::MorphShapeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> MorphShape::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MorphShape(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243bab0
    MorphShape::MorphShape(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_MorphShape;
        SetMemSize(0x68);
    }

    // @0x1424458a0
    void MorphShape::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243bae0
    MorphShape::MorphShape(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObject(t)
    {
    }
}}

// ---- MovieClip ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243bb10
    MovieClip::MovieClip(VM& vm)
        : Traits(vm, AS3::fl_display::MovieClipCI)
    {
        TraitsType = Traits_MovieClip;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::MovieClip(vm, AS3::fl_display::MovieClipCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> MovieClip::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MovieClip(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243bc20
    MovieClip::MovieClip(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_MovieClip;
        SetMemSize(0x88);
    }

    // @0x142445900
    void MovieClip::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243bc50
    MovieClip::MovieClip(InstanceTraits::Traits& t)
        : Instances::fl_display::Sprite(t)
    {
    }
}}

// ---- PixelSnapping ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243bc90
    PixelSnapping::PixelSnapping(VM& vm)
        : Traits(vm, AS3::fl_display::PixelSnappingCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::PixelSnappingCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::PixelSnapping(*this)));
    }

    inline Pickable<Traits> PixelSnapping::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) PixelSnapping(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243bd90
    PixelSnapping::PixelSnapping(ClassTraits::Traits& t)
        : Class(t)
        , Always("always")
        , Auto("auto")
        , Never("never")
    {
    }
}}

// ---- SWFVersion ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243bde0
    SWFVersion::SWFVersion(VM& vm)
        : Traits(vm, AS3::fl_display::SWFVersionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::SWFVersionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::SWFVersion(*this)));
    }

    inline Pickable<Traits> SWFVersion::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SWFVersion(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243bf00
    SWFVersion::SWFVersion(ClassTraits::Traits& t)
        : Class(t)
        , Flash1(1)
        , Flash2(2)
        , Flash3(3)
        , Flash4(4)
        , Flash5(5)
        , Flash6(6)
        , Flash7(7)
        , Flash8(8)
        , Flash9(9)
    {
    }
}}

// ---- Scene ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243bf60
    Scene::Scene(VM& vm)
        : Traits(vm, AS3::fl_display::SceneCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Scene(vm, AS3::fl_display::SceneCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Scene::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Scene(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243c060
    Scene::Scene(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }

    // @0x142445970
    void Scene::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243c090
    Scene::Scene(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , SceneInfo(NULL)
    {
    }
}}

// ---- Shader ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c0c0
    Shader::Shader(VM& vm)
        : Traits(vm, AS3::fl_display::ShaderCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ShaderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Shader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Shader(vm));
    }
}}

// ---- ShaderData ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c1a0
    ShaderData::ShaderData(VM& vm)
        : Traits(vm, AS3::fl_display::ShaderDataCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ShaderDataCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> ShaderData::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ShaderData(vm));
    }
}}

// ---- Shape ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c280
    Shape::Shape(VM& vm)
        : Traits(vm, AS3::fl_display::ShapeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Shape(vm, AS3::fl_display::ShapeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Shape::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Shape(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243c380
    Shape::Shape(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x70);
    }

    // @0x1424459e0
    void Shape::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243c3b0
    Shape::Shape(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObject(t)
    {
    }
}}

// ---- SimpleButton ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c3e0
    SimpleButton::SimpleButton(VM& vm)
        : Traits(vm, AS3::fl_display::SimpleButtonCI)
    {
        TraitsType = Traits_SimpleButton;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::SimpleButton(vm, AS3::fl_display::SimpleButtonCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> SimpleButton::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SimpleButton(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243c4f0
    SimpleButton::SimpleButton(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_SimpleButton;
        SetMemSize(0x70);
    }

    // @0x142445a40
    void SimpleButton::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243c520
    SimpleButton::SimpleButton(InstanceTraits::Traits& t)
        : Instances::fl_display::InteractiveObject(t)
    {
    }
}}

// ---- SpreadMethod ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c550
    SpreadMethod::SpreadMethod(VM& vm)
        : Traits(vm, AS3::fl_display::SpreadMethodCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::SpreadMethodCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::SpreadMethod(*this)));
    }

    inline Pickable<Traits> SpreadMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SpreadMethod(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243c650
    SpreadMethod::SpreadMethod(ClassTraits::Traits& t)
        : Class(t)
        , Pad("pad")
        , Reflect("reflect")
        , Repeat("repeat")
    {
    }
}}

// ---- Sprite ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c6a0
    Sprite::Sprite(VM& vm)
        : Traits(vm, AS3::fl_display::SpriteCI)
    {
        TraitsType = Traits_Sprite;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Sprite(vm, AS3::fl_display::SpriteCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    inline Pickable<Traits> Sprite::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Sprite(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243c7b0
    Sprite::Sprite(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Sprite;
        SetMemSize(0x78);
    }

    // @0x142445aa0
    void Sprite::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243c7e0
    Sprite::Sprite(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObjectContainer(t)
    {
    }
}}

// ---- Stage ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c810
    Stage::Stage(VM& vm)
        : Traits(vm, AS3::fl_display::StageCI)
    {
        TraitsType = Traits_Stage;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Stage(vm, AS3::fl_display::StageCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::Stage(*this)));
    }

    inline Pickable<Traits> Stage::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Stage(vm));
    }
}}

namespace InstanceTraits { namespace fl_display
{
    // @0x14243c950
    Stage::Stage(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Stage;
        SetMemSize(0x70);
    }

    // @0x142445b10
    void Stage::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14243c980
    Stage::Stage(InstanceTraits::Traits& t)
        : Instances::fl_display::DisplayObjectContainer(t)
    {
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243c920
    Stage::Stage(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

// ---- StageAlign ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243c9b0
    StageAlign::StageAlign(VM& vm)
        : Traits(vm, AS3::fl_display::StageAlignCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageAlignCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageAlign(*this)));
    }

    inline Pickable<Traits> StageAlign::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageAlign(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243caf0
    StageAlign::StageAlign(ClassTraits::Traits& t)
        : Class(t)
        , Bottom("B")
        , BottomLeft("BL")
        , BottomRight("BR")
        , Left("L")
        , Right("R")
        , Top("T")
        , TopLeft("TL")
        , TopRight("TR")
    {
    }
}}

// ---- StageDisplayState ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243cb70
    StageDisplayState::StageDisplayState(VM& vm)
        : Traits(vm, AS3::fl_display::StageDisplayStateCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageDisplayStateCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageDisplayState(*this)));
    }

    inline Pickable<Traits> StageDisplayState::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageDisplayState(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243cc70
    StageDisplayState::StageDisplayState(ClassTraits::Traits& t)
        : Class(t)
        , FullScreen("fullScreen")
        , FullScreenInteractive("fullScreenInteractive")
        , Normal("normal")
    {
    }
}}

// ---- StageQuality ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243ccc0
    StageQuality::StageQuality(VM& vm)
        : Traits(vm, AS3::fl_display::StageQualityCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageQualityCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageQuality(*this)));
    }

    inline Pickable<Traits> StageQuality::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageQuality(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243cdd0
    StageQuality::StageQuality(ClassTraits::Traits& t)
        : Class(t)
        , Best("best")
        , High("high")
        , Low("low")
        , Medium("medium")
    {
    }
}}

// ---- StageScaleMode ----

namespace ClassTraits { namespace fl_display
{
    // @0x14243ce20
    StageScaleMode::StageScaleMode(VM& vm)
        : Traits(vm, AS3::fl_display::StageScaleModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageScaleModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageScaleMode(*this)));
    }

    inline Pickable<Traits> StageScaleMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageScaleMode(vm));
    }
}}

namespace Classes { namespace fl_display
{
    // @0x14243cf30
    StageScaleMode::StageScaleMode(ClassTraits::Traits& t)
        : Class(t)
        , ExactFit("exactFit")
        , NoBorder("noBorder")
        , NoScale("noScale")
        , ShowAll("showAll")
    {
    }
}}

// ---- destructors, collector visits, frame scripts ----

// Visits the collectable a value holds (0x142504530).
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner);

SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        ForEachChild_GC_Internal(prcc, v, op, owner);
}

// The exe passes the owner as a third argument to every GcOp (r8); the shared GcOp typedef has two.
typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const ASRefCountBaseType** pchild,
                              const ASRefCountBaseType& owner);
SF_INLINE void CallGcOp(ASRefCountBaseType::GcOp op, RefCountCollector<StatMV_ActionScript_Mem>* prcc,
                        const ASRefCountBaseType** pchild, const ASRefCountBaseType& owner)
{
    reinterpret_cast<GcOpWithOwner>(op)(prcc, pchild, owner);
}

// Visits a counted pointer member.
template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (p.GetPtr())
        CallGcOp(op, prcc, const_cast<const ASRefCountBaseType**>(reinterpret_cast<ASRefCountBaseType**>(p.GetRawPtr())), owner);
}

}}} // namespace Scaleform::GFx::AS3

// Collector op of the marking pass that drops a reference (0x1423df980).
void FUN_1423df980(Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>* prcc,
                   const Scaleform::GFx::AS3::ASRefCountBaseType** pchild);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_display
{
    // ---- DisplayObject ----

    // A display object dying inside a collection leaves pDispObj to the collector, which releases it once the
    // collection is over.
    // @0x14243d0b0
    DisplayObject::~DisplayObject()
    {
        if (pDispObj)
        {
            ToAvmDisplayObj(pDispObj)->ReleaseAS3Obj();
            if (GetVM().GetGC().Flags & ASRefCountCollector::Flags_InCollect)
            {
                pReleaseProxy->Data = pDispObj.GetPtr();
                ReleaseProxy* pproxy = pReleaseProxy;
                Ptr<ReleaseProxy>& head = reinterpret_cast<Ptr<ReleaseProxy>&>(GetVM().GetGC().HeadDelayedPtrRelease);
                if (pproxy)
                {
                    if (!head)
                    {
                        head = pproxy;
                        pproxy->pNext = NULL;
                    }
                    else
                    {
                        pproxy->pNext = head;
                        head = pproxy;
                    }
                }
            }
        }
    }

    // @0x142441cc0
    GFx::DisplayObject* DisplayObject::CreateStageObject()
    {
        return pDispObj;
    }

    // @0x142443380
    String DisplayObject::GetAS3ObjectName() const
    {
        if (!pDispObj)
            return String("");
        return String(pDispObj->GetName().ToCStr());
    }

    // @0x142442e10
    void DisplayObject::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instances::fl_events::EventDispatcher::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pLoaderInfo, op, *this);
    }

    // ---- Bitmap ----

    // @0x142442db0
    void Bitmap::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        DisplayObject::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pBitmapData, op, *this);
    }

    // ---- BitmapData ----

    // @0x14243d050
    BitmapData::~BitmapData()
    {
    }

    // ---- InteractiveObject ----

    // @0x14243d3a0
    InteractiveObject::~InteractiveObject()
    {
    }

    // @0x142442fe0
    void InteractiveObject::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        DisplayObject::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pContextMenu, op, *this);
    }

    // ---- DisplayObjectContainer ----

    // The children's AS3 objects belong to the container; the passes that only count references skip them outside a
    // full collection.
    // @0x142442e50
    void DisplayObjectContainer::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        InteractiveObject::ForEachChild_GC(prcc, op);
        if (pDispObj)
        {
            GFx::DisplayObjContainer* pcont = static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr());
            const unsigned n = (unsigned)pcont->mDisplayList.GetCount();
            for (unsigned i = 0; i < n; ++i)
            {
                DisplayObjectBase* pch = pcont->GetChildAt(i);
                DisplayObjectBase* pscr = pch->IsScriptableObject() ? pch : NULL;
                if (pscr)
                {
                    const ASRefCountBaseType** pchild =
                        (const ASRefCountBaseType**)&ToAvmDisplayObj(pscr)->pAS3CollectiblePtr;
                    if (pchild &&
                        ((prcc->Flags & Collector::Flags_InCollect) ||
                         (op != &Collector::KillChildCall && op != &FUN_1423df980)) &&
                        *pchild)
                        AS3::CallGcOp(op, prcc, pchild, *this);
                }
            }
        }
    }

    // ---- Loader ----

    // @0x142443040
    void Loader::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        DisplayObjectContainer::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pContentLoaderInfo, op, *this);
    }

    // ---- LoaderInfo ----

    // @0x142443080
    void LoaderInfo::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instances::fl_events::EventDispatcher::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Content, op, *this);
        AS3::ForEachChild_GC(prcc, pLoader, op, *this);
    }

    // ---- Shape ----

    // @0x14243d410
    Shape::~Shape()
    {
    }

    // @0x1424431b0
    void Shape::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        DisplayObject::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pGraphics, op, *this);
    }

    // ---- Sprite ----

    // @0x14243d470
    Sprite::~Sprite()
    {
    }

    // @0x142443210
    void Sprite::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        DisplayObjectContainer::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, pGraphics, op, *this);
    }

    // @0x142443e10
    bool Sprite::GetFrameScript(unsigned, Value*)
    {
        return false;
    }

    // ---- MovieClip ----

    // @0x14243a770
    MovieClip::FrameScript::Descr::Descr(const Descr& other)
        : Method(other.Method)
        , Frame(other.Frame)
    {
    }

    // @0x14243d290
    void MovieClip::FrameScript::Clear()
    {
        if (pData)
        {
            Descr* pdescrs = GetDescrs();
            for (unsigned i = 0; i < DescrCnt; ++i)
                pdescrs[i].~Descr();
            SF_FREE(pData);
            pData = NULL;
        }
    }

    // @0x142443250
    // noinline: GetFrameScript calls it out of line.
    __declspec(noinline) const MovieClip::FrameScript::Descr* MovieClip::FrameScript::Get(unsigned frame)
    {
        if (frame < FrameCnt && IsSet(frame))
        {
            Descr* pdescrs = GetDescrs();
            UPInt i = Alg::LowerBoundSliced(pdescrs, 0, DescrCnt, Descr(Value::GetUndefined(), frame), Descr::Less);
            if (pdescrs[i].Frame == frame)
                return &pdescrs[i];
        }
        return NULL;
    }

    // @0x142442f40
    void MovieClip::FrameScript::ForEachChild_GC(Collector* prcc, GcOp op, const Instances::fl::Object& owner) const
    {
        if (pData)
        {
            const Descr* pdescrs = GetDescrs();
            for (unsigned i = 0; i < DescrCnt; ++i)
                AS3::ForEachChild_GC(prcc, pdescrs[i].Method, op, owner);
        }
    }

    // @0x142443db0
    bool MovieClip::GetFrameScript(unsigned frame, Value* pv)
    {
        const FrameScript::Descr* pdescr = frameScript.Get(frame);
        if (pdescr && pdescr->Method.IsCallable() && !pdescr->Method.IsNull())
        {
            *pv = pdescr->Method;
            return true;
        }
        return false;
    }

    // @0x1424430e0
    void MovieClip::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Sprite::ForEachChild_GC(prcc, op);
        frameScript.ForEachChild_GC(prcc, op, *this);
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- Stage objects of the display classes ----
// Bodies of the exe called here (not recovered yet), by their addresses.
// AvmDisplayObj::AssignAS3Obj: makes pinst the AS3 object of pavm.
void FUN_1424edca0(Scaleform::GFx::AS3::AvmDisplayObj* pavm, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* pinst);
// The movie whose library an AS3 object's class came from.
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* pobj);
// VM::IsOfType(v, class name).
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);
// MovieDefImpl::GetCharacterCreateInfo(rid) with its hidden return slot spelled out.
Scaleform::GFx::CharacterCreateInfo* FUN_1425cf500(Scaleform::GFx::MovieDefImpl* pdef, Scaleform::GFx::CharacterCreateInfo* pret,
                                                   const Scaleform::GFx::ResourceId* prid);
// MovieImpl::FindExportedResource.
bool FUN_14256ec50(Scaleform::GFx::MovieImpl* pmovie, Scaleform::GFx::MovieDefImpl* pdef, Scaleform::GFx::ResourceBindData* pdata,
                   const Scaleform::String& symbol);
// AS3::MovieRoot::FindLibrarySymbolInAllABCs, AddScriptableMovieClip.
bool FUN_142501a80(Scaleform::GFx::ASMovieRootBase* proot, const Scaleform::GFx::AS3::Instances::fl::Object* pobj,
                   Scaleform::GFx::CharacterCreateInfo* pinfo);
void FUN_1424e9380(Scaleform::GFx::ASMovieRootBase* proot, Scaleform::GFx::DisplayObject* pcont);
// AvmLoader constructor (returns this).
Scaleform::GFx::DisplayObject* FUN_1424d6500(void* pmem, Scaleform::GFx::ASMovieRootBase* proot, Scaleform::GFx::MovieDefImpl* pdef,
                                             Scaleform::GFx::InteractiveObject* pparent, const Scaleform::GFx::ResourceId* prid);
// AvmBitmap::SetResourceMovieDef, RecreateRenderNode.
void FUN_142528e70(Scaleform::GFx::DisplayObject* pbitmap, Scaleform::GFx::MovieDefImpl* pdef);
void FUN_142520b20(Scaleform::GFx::DisplayObject* pbitmap);
// Bitmap's pixel snapping mode of its AS3 name.
Scaleform::SInt32 FUN_142446f30(Scaleform::GFx::AS3::Instances::fl_display::Bitmap* pbitmap, const char* pname);
// AvmButton: set the up / over / down / hit test state character.
void FUN_14252a4e0(Scaleform::GFx::AS3::AvmDisplayObj* pavm, Scaleform::GFx::DisplayObject* pch);
void FUN_1425287b0(Scaleform::GFx::AS3::AvmDisplayObj* pavm, Scaleform::GFx::DisplayObject* pch);
void FUN_1425272f0(Scaleform::GFx::AS3::AvmDisplayObj* pavm, Scaleform::GFx::DisplayObject* pch);
void FUN_142527490(Scaleform::GFx::AS3::AvmDisplayObj* pavm, Scaleform::GFx::DisplayObject* pch);
// AvmButton set-up after its creation from AS3.
void FUN_1425ddd20(Scaleform::GFx::DisplayObject* pbtn);
// AvmSprite: the AS3 constructor of a sprite created from script.
void FUN_1424f3320(Scaleform::GFx::AS3::AvmDisplayObj* pavm);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_display
{
    // ASVM::pMovieRoot: the AS3 movie root, used through its ASMovieRootBase part.
    static ASMovieRootBase* GetASRoot(VM& vm)
    {
        return *reinterpret_cast<ASMovieRootBase**>(reinterpret_cast<UByte*>(&vm) + 0x2d8);
    }

    static AvmDisplayObj* AvmOf(GFx::DisplayObject* p)
    {
        return p ? ToAvmDisplayObj(p) : NULL;
    }

    // Takes over the reference of a freshly created display object and makes this its AS3 object.
    static void AttachStageObject(DisplayObject* pthis, GFx::DisplayObject* pdisp)
    {
        pthis->pDispObj = Pickable<GFx::DisplayObject>(pdisp);
        FUN_1424edca0(AvmOf(pdisp), pthis);
    }

    // The definition (call frame's movie) a stage object created from script binds to.
    static MovieDefImpl* GetCallerDefImpl(VM& vm)
    {
        const UByte* pvm = reinterpret_cast<const UByte*>(&vm);
        UPInt n = *reinterpret_cast<const UPInt*>(pvm + 0x78) - 1;
        const UByte* ppage = (*reinterpret_cast<UByte* const* const*>(pvm + 0x90))[n >> 6];
        const UByte* pframe = ppage + (n & 0x3f) * 0xa8;
        const UByte* pfile = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(pframe + 0x28) + 0x28);
        return *reinterpret_cast<MovieDefImpl* const*>(pfile + 0x188);
    }

    // Looks the class of pobj, then its ABC base classes, up among the movie's exported symbols. Fills pinfo with a
    // character definition or another resource; false if no class name is exported.
    // @0x142442c30
    // MS2-FUNCTIONAL: written from the exe's control flow
    bool FindLibrarySymbol(const DisplayObject* pobj, CharacterCreateInfo* pinfo, MovieDefImpl* pdefImpl)
    {
        VM& vm = pobj->GetVM();
        pinfo->pCharDef = NULL;
        pinfo->pResource = NULL;
        pinfo->pBindDefImpl = pdefImpl;
        const Traits* ptraits = &pobj->GetTraits();
        while (ptraits)
        {
            if (!(ptraits->Flags & Traits::IsAbcObjectMask))
                break;
            if (pinfo->pCharDef)
                return true;
            if (pinfo->pResource)
                break;
            ASString name = ptraits->GetQualifiedName(Traits::qnfWithDot);
            ResourceBindData data;
            bool found = FUN_14256ec50(GetASRoot(vm)->GetMovieImpl(), pdefImpl, &data,
                                       String(name.ToCStr()));
            if (found)
            {
                if (data.pResource->GetResourceTypeCode() & (Resource::RT_CharacterDef_Bit << Resource::RT_TypeCode_Shift))
                    pinfo->pCharDef = static_cast<CharacterDef*>(data.pResource.GetPtr());
                else
                    pinfo->pResource = data.pResource;
                pinfo->pBindDefImpl = *reinterpret_cast<MovieDefImpl**>(reinterpret_cast<UByte*>(data.pBinding) + 0x48);
            }
            else
                ptraits = ptraits->pParent;
        }
        if (pinfo->pCharDef)
            return true;
        return pinfo->pResource != NULL;
    }

    // @0x142440910
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Bitmap::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc == 0)
            return;
        VM& vm = GetVM();
        if (FUN_1425145d0(vm, argv[0], "flash.display.BitmapData"))
        {
            pBitmapData = static_cast<Instances::fl_display::BitmapData*>(argv[0].GetObject());
            if (pDispObj)
                FUN_142528e70(pDispObj, pBitmapData ? pBitmapData->pDefImpl.GetPtr() : NULL);
        }
        if (argc > 1)
        {
            ASString mode = vm.GetStringManager().CreateEmptyString();
            if (!argv[1].Convert2String(mode))
                return;
            PixelSnapping = FUN_142446f30(this, mode.ToCStr());
            if (argc > 2)
                Smoothing = argv[2].Convert2Boolean();
        }
        if (pDispObj)
            FUN_142520b20(pDispObj);
    }

    // The optional up, over, down and hit test state objects.
    // @0x142440c30
    // MS2-FUNCTIONAL: written from the exe's control flow
    void SimpleButton::AS3Constructor(unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        if (argc > 0 && FUN_1425145d0(vm, argv[0], "flash.display.DisplayObject"))
            FUN_14252a4e0(AvmOf(pDispObj), static_cast<DisplayObject*>(argv[0].GetObject())->pDispObj);
        if (argc > 1 && FUN_1425145d0(vm, argv[1], "flash.display.DisplayObject"))
            FUN_1425287b0(AvmOf(pDispObj), static_cast<DisplayObject*>(argv[1].GetObject())->pDispObj);
        if (argc > 2 && FUN_1425145d0(vm, argv[2], "flash.display.DisplayObject"))
            FUN_1425272f0(AvmOf(pDispObj), static_cast<DisplayObject*>(argv[2].GetObject())->pDispObj);
        if (argc > 3 && FUN_1425145d0(vm, argv[3], "flash.display.DisplayObject"))
            FUN_142527490(AvmOf(pDispObj), static_cast<DisplayObject*>(argv[3].GetObject())->pDispObj);
    }

    // @0x142440d70
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Sprite::AS3Constructor(unsigned, const Value*)
    {
        FUN_1424f3320(ToAvmDisplayObj(pDispObj));
    }

    // @0x142441cd0
    // MS2-FUNCTIONAL: written from the exe's control flow
    GFx::DisplayObject* Loader::CreateStageObject()
    {
        if (!pDispObj)
        {
            ASMovieRootBase* proot = GetASRoot(GetVM());
            MovieImpl* pmovie = proot->GetMovieImpl();
            void* pmem = pmovie->pHeap->Alloc(0x158);
            GFx::DisplayObject* pdisp = NULL;
            if (pmem)
            {
                ResourceId rid(ResourceId::InvalidId);
                pdisp = FUN_1424d6500(pmem, proot, pmovie->pMainMovieDef, NULL, &rid);
            }
            AttachStageObject(this, pdisp);
            FUN_1424e9380(proot, pDispObj);
        }
        return pDispObj;
    }

    // @0x142441da0
    // MS2-FUNCTIONAL: written from the exe's control flow
    GFx::DisplayObject* Shape::CreateStageObject()
    {
        if (!pDispObj)
        {
            ASMovieRootBase* proot = GetASRoot(GetVM());
            ResourceId emptyShapeId(0x10004);
            CharacterCreateInfo ccinfo;
            FUN_1425cf500(proot->GetMovieImpl()->pMainMovieDef, &ccinfo, &emptyShapeId);
            DisplayObjectBase* pch = proot->pASSupport->CreateCharacterInstance(proot->GetMovieImpl(), ccinfo, NULL,
                                                                                 ResourceId(0x10001), CharacterDef::Shape);
            AttachStageObject(this, static_cast<GFx::DisplayObject*>(pch));
        }
        return pDispObj;
    }

    // @0x142441e60
    // MS2-FUNCTIONAL: written from the exe's control flow
    GFx::DisplayObject* SimpleButton::CreateStageObject()
    {
        if (pDispObj)
            return pDispObj;
        VM& vm = GetVM();
        ASMovieRootBase* proot = GetASRoot(vm);
        MovieDefImpl* pdefImpl = FUN_14250d8f0(vm, this);
        if (!pdefImpl)
            return pDispObj;
        CharacterCreateInfo ccinfo;
        FindLibrarySymbol(this, &ccinfo, pdefImpl);
        if (!ccinfo.pCharDef)
        {
            ResourceId emptyButtonId(0x10003);
            CharacterCreateInfo def;
            FUN_1425cf500(pdefImpl, &def, &emptyButtonId);
            ccinfo.pCharDef = def.pCharDef;
            ccinfo.pResource = def.pResource;
            ccinfo.pBindDefImpl = GetCallerDefImpl(GetVM());
        }
        DisplayObjectBase* pch = proot->pASSupport->CreateCharacterInstance(proot->GetMovieImpl(), ccinfo, NULL,
                                                                             ResourceId(ResourceId::InvalidId), CharacterDef::Button);
        AttachStageObject(this, static_cast<GFx::DisplayObject*>(pch));
        FUN_1425ddd20(pDispObj);
        return pDispObj;
    }

    // @0x142441ff0
    // MS2-FUNCTIONAL: written from the exe's control flow
    GFx::DisplayObject* Sprite::CreateStageObject()
    {
        if (pDispObj)
            return pDispObj;
        VM& vm = GetVM();
        ASMovieRootBase* proot = GetASRoot(vm);
        MovieDefImpl* pdefImpl = FUN_14250d8f0(vm, this);
        if (!pdefImpl)
            return pDispObj;
        CharacterCreateInfo ccinfo;
        FindLibrarySymbol(this, &ccinfo, pdefImpl);
        if (!ccinfo.pCharDef && !FUN_142501a80(proot, this, &ccinfo))
        {
            ResourceId emptySpriteId(0x10001);
            CharacterCreateInfo def;
            FUN_1425cf500(pdefImpl, &def, &emptySpriteId);
            ccinfo.pCharDef = def.pCharDef;
            ccinfo.pResource = def.pResource;
            ccinfo.pBindDefImpl = pdefImpl;
            if (*reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(&vm) + 0x78) != 0)
                ccinfo.pBindDefImpl = GetCallerDefImpl(vm);
        }
        DisplayObjectBase* pch = proot->pASSupport->CreateCharacterInstance(proot->GetMovieImpl(), ccinfo, NULL,
                                                                             ResourceId(ResourceId::InvalidId), CharacterDef::Sprite);
        AttachStageObject(this, static_cast<GFx::DisplayObject*>(pch));
        return pDispObj;
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc3@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0P@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@KK_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438be0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CL@$$CBVValue@456@PEAVTransform@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438d50
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VScene@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438d90
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@KJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438e40
// MS2-PIN: ??_7?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@6B@ 0x14314ba40
// MS2-PIN: ??_7AVM1Movie@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143149fe0
// MS2-PIN: ??_7AVM1Movie@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143149f38
// MS2-PIN: ??_7AVM1Movie@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x143149e60
// MS2-PIN: ??_7ActionScriptVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431496f0
// MS2-PIN: ??_7ActionScriptVersion@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x143149790
// MS2-PIN: ??_7Bitmap@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a428
// MS2-PIN: ??_7Bitmap@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314a388
// MS2-PIN: ??_7Bitmap@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314a2b8
// MS2-PIN: ??_7BitmapData@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a228
// MS2-PIN: ??_7BitmapData@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314a178
// MS2-PIN: ??_7BitmapData@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314a0a8
// MS2-PIN: ??_7BitmapDataChannel@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314acb8
// MS2-PIN: ??_7BitmapDataChannel@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314ad50
// MS2-PIN: ??_7BlendMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a7b0
// MS2-PIN: ??_7BlendMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314a840
// MS2-PIN: ??_7CapsStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314aeb8
// MS2-PIN: ??_7CapsStyle@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314af48
// MS2-PIN: ??_7DisplayObject@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143149dc8
// MS2-PIN: ??_7DisplayObject@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143149d20
// MS2-PIN: ??_7DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x143149c48
// MS2-PIN: ??_7DisplayObjectContainer@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b1c8
// MS2-PIN: ??_7DisplayObjectContainer@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b118
// MS2-PIN: ??_7DisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314b038
// MS2-PIN: ??_7FrameLabel@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314bf68
// MS2-PIN: ??_7FrameLabel@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314bec0
// MS2-PIN: ??_7FrameLabel@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314bdf0
// MS2-PIN: ??_7GradientType@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314bff8
// MS2-PIN: ??_7GradientType@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c090
// MS2-PIN: ??_7Graphics@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c2f8
// MS2-PIN: ??_7Graphics@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314c250
// MS2-PIN: ??_7Graphics@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314c188
// MS2-PIN: ??_7IBitmapDrawable@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a718
// MS2-PIN: ??_7InteractiveObject@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a648
// MS2-PIN: ??_7InteractiveObject@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314a598
// MS2-PIN: ??_7InteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314a4b8
// MS2-PIN: ??_7InterpolationMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c488
// MS2-PIN: ??_7InterpolationMethod@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c528
// MS2-PIN: ??_7JointStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c620
// MS2-PIN: ??_7JointStyle@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c6b0
// MS2-PIN: ??_7LineScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c798
// MS2-PIN: ??_7LineScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c830
// MS2-PIN: ??_7Loader@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b3d8
// MS2-PIN: ??_7Loader@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b338
// MS2-PIN: ??_7Loader@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314b268
// MS2-PIN: ??_7LoaderInfo@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b8c0
// MS2-PIN: ??_7LoaderInfo@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314b950
// MS2-PIN: ??_7LoaderInfo@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b818
// MS2-PIN: ??_7LoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314b748
// MS2-PIN: ??_7MorphShape@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ce50
// MS2-PIN: ??_7MorphShape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314cda8
// MS2-PIN: ??_7MorphShape@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314ccd0
// MS2-PIN: ??_7MovieClip@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d290
// MS2-PIN: ??_7MovieClip@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d1e8
// MS2-PIN: ??_7MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314d0f8
// MS2-PIN: ??_7PixelSnapping@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d530
// MS2-PIN: ??_7PixelSnapping@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314d5c8
// MS2-PIN: ??_7SWFVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e960
// MS2-PIN: ??_7SWFVersion@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e9f0
// MS2-PIN: ??_7Scene@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d488
// MS2-PIN: ??_7Scene@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d3e8
// MS2-PIN: ??_7Scene@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314d320
// MS2-PIN: ??_7Shader@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314eb68
// MS2-PIN: ??_7ShaderData@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ead8
// MS2-PIN: ??_7Shape@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d840
// MS2-PIN: ??_7Shape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d7a0
// MS2-PIN: ??_7Shape@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314d6d0
// MS2-PIN: ??_7SimpleButton@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314da50
// MS2-PIN: ??_7SimpleButton@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d9a8
// MS2-PIN: ??_7SimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314d8d0
// MS2-PIN: ??_7SpreadMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314db88
// MS2-PIN: ??_7SpreadMethod@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314dc20
// MS2-PIN: ??_7Sprite@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d068
// MS2-PIN: ??_7Sprite@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314cfc8
// MS2-PIN: ??_7Sprite@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314cee0
// MS2-PIN: ??_7Stage@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b5d8
// MS2-PIN: ??_7Stage@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314b668
// MS2-PIN: ??_7Stage@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b538
// MS2-PIN: ??_7Stage@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314b468
// MS2-PIN: ??_7StageAlign@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e310
// MS2-PIN: ??_7StageAlign@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e3a0
// MS2-PIN: ??_7StageDisplayState@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e490
// MS2-PIN: ??_7StageDisplayState@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e528
// MS2-PIN: ??_7StageQuality@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e640
// MS2-PIN: ??_7StageQuality@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e6d8
// MS2-PIN: ??_7StageScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e7e0
// MS2-PIN: ??_7StageScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e878
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEI@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7?$RefCountBase@V?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@$0BEI@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_G?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243da40
// MS2-PIN: ??_GAVM1Movie@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243dcd0
// MS2-PIN: ??_GAVM1Movie@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243dd60
// MS2-PIN: ??_GAVM1Movie@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ddc0
// MS2-PIN: ??_GActionScriptVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243de20
// MS2-PIN: ??_GActionScriptVersion@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243deb0
// MS2-PIN: ??_GBitmap@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243df10
// MS2-PIN: ??_GBitmap@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243dfa0
// MS2-PIN: ??_GBitmap@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e000
// MS2-PIN: ??_GBitmapData@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e090
// MS2-PIN: ??_GBitmapData@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e120
// MS2-PIN: ??_GBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e180
// MS2-PIN: ??_GBitmapDataChannel@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e220
// MS2-PIN: ??_GBitmapDataChannel@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e2b0
// MS2-PIN: ??_GBlendMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e310
// MS2-PIN: ??_GBlendMode@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e3a0
// MS2-PIN: ??_GCapsStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e400
// MS2-PIN: ??_GCapsStyle@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e490
// MS2-PIN: ??_GDisplayObject@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e520
// MS2-PIN: ??_GDisplayObject@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e5b0
// MS2-PIN: ??_GDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e610
// MS2-PIN: ??_GDisplayObjectContainer@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e670
// MS2-PIN: ??_GDisplayObjectContainer@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e700
// MS2-PIN: ??_GDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e760
// MS2-PIN: ??_GFrameLabel@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e800
// MS2-PIN: ??_GFrameLabel@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e890
// MS2-PIN: ??_GFrameLabel@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e8f0
// MS2-PIN: ??_GGradientType@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e960
// MS2-PIN: ??_GGradientType@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243e9f0
// MS2-PIN: ??_GGraphics@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ea50
// MS2-PIN: ??_GGraphics@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243eae0
// MS2-PIN: ??_GGraphics@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243eb40
// MS2-PIN: ??_GIBitmapDrawable@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ebb0
// MS2-PIN: ??_GInteractiveObject@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ee40
// MS2-PIN: ??_GInteractiveObject@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243eed0
// MS2-PIN: ??_GInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ef30
// MS2-PIN: ??_GInterpolationMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243efd0
// MS2-PIN: ??_GInterpolationMethod@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f060
// MS2-PIN: ??_GJointStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f0c0
// MS2-PIN: ??_GJointStyle@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f150
// MS2-PIN: ??_GLineScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f1b0
// MS2-PIN: ??_GLineScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f240
// MS2-PIN: ??_GLoader@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f2a0
// MS2-PIN: ??_GLoader@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f330
// MS2-PIN: ??_GLoader@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f390
// MS2-PIN: ??_GLoaderInfo@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f450
// MS2-PIN: ??_GLoaderInfo@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f4e0
// MS2-PIN: ??_GLoaderInfo@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f540
// MS2-PIN: ??_GLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f5a0
// MS2-PIN: ??_GMorphShape@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f660
// MS2-PIN: ??_GMorphShape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f6f0
// MS2-PIN: ??_GMorphShape@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f750
// MS2-PIN: ??_GMovieClip@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f7b0
// MS2-PIN: ??_GMovieClip@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f840
// MS2-PIN: ??_GMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f8a0
// MS2-PIN: ??_GPixelSnapping@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f910
// MS2-PIN: ??_GPixelSnapping@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243f9a0
// MS2-PIN: ??_GSWFVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fa90
// MS2-PIN: ??_GSWFVersion@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fb20
// MS2-PIN: ??_GScene@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fb80
// MS2-PIN: ??_GScene@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fc10
// MS2-PIN: ??_GScene@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fc70
// MS2-PIN: ??_GShader@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fce0
// MS2-PIN: ??_GShaderData@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fd70
// MS2-PIN: ??_GShape@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fe00
// MS2-PIN: ??_GShape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fe90
// MS2-PIN: ??_GShape@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243fef0
// MS2-PIN: ??_GSimpleButton@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ff90
// MS2-PIN: ??_GSimpleButton@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440020
// MS2-PIN: ??_GSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440080
// MS2-PIN: ??_GSpreadMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440120
// MS2-PIN: ??_GSpreadMethod@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424401b0
// MS2-PIN: ??_GSprite@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440210
// MS2-PIN: ??_GSprite@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424402a0
// MS2-PIN: ??_GSprite@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440300
// MS2-PIN: ??_GStage@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440360
// MS2-PIN: ??_GStage@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424403f0
// MS2-PIN: ??_GStage@fl_display@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440450
// MS2-PIN: ??_GStage@fl_display@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424404b0
// MS2-PIN: ??_GStageAlign@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440550
// MS2-PIN: ??_GStageAlign@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424405e0
// MS2-PIN: ??_GStageDisplayState@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440640
// MS2-PIN: ??_GStageDisplayState@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424406d0
// MS2-PIN: ??_GStageQuality@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440730
// MS2-PIN: ??_GStageQuality@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424407c0
// MS2-PIN: ??_GStageScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142440820
// MS2-PIN: ??_GStageScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424408b0
// tplpin --simulate (accepted by hand):
// MS2-PIN: ??$LowerBoundSliced@PEAUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U12345678@P6A_NAEBU12345678@0@Z@Alg@Scaleform@@YA_KAEBQEAUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@1@_K1AEBU23456781@P6A_N22@Z@Z 0x142438fe0
// MS2-PIN: ??_G?$RefCountBase@V?$PtrReleaseProxy@$0BEI@@AS3@GFx@Scaleform@@$0BEI@@Scaleform@@UEAAPEAXI@Z 0x14243daf0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEI@@Scaleform@@UEAAPEAXI@Z 0x14243db50
// MS2-PIN: ??0LineScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@QEAA@AEAVTraits@ClassTraits@345@@Z 0x14243b650
// MS2-PIN: ??0StageScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@QEAA@AEAVTraits@ClassTraits@345@@Z 0x14243cf30
// MS2-PIN: ??1Stage@fl_display@Instances@AS3@GFx@Scaleform@@UEAA@XZ 0x14243d500
// MS2-PIN: ??0StageQuality@fl_display@Classes@AS3@GFx@Scaleform@@QEAA@AEAVTraits@ClassTraits@345@@Z 0x14243cdd0
// MS2-PIN: ??4?$SPtr@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVBitmapData@fl_display@Instances@123@@Z 0x14243d560
