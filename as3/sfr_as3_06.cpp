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
#include "ms2/scaleform/include/gfx/gfx_imageresource.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display_pixels.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}}
#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/render/render_twips.h"
#include "ms2/scaleform/include/render/render_filters.h"
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

namespace Scaleform { namespace GFx {

// @0x14243d330
SF_NOINLINE ImageResource::~ImageResource()
{
    if (pImage && pImage != &Delegate)
        pImage->Release();
}

}} // namespace Scaleform::GFx

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

// The exe never calls a Multiname copy constructor out of line; defined inline here for the PushBack below.
inline Multiname::Multiname(const Multiname& other)
    : Kind(other.Kind)
    , Obj(other.Obj)
    , Name(other.Name)
{
}

namespace InstanceTraits
{
    // @0x142446010
    void CTraits::RegisterImplementedInterface(const Multiname& mn)
    {
        ImplementsInterfaces.PushBack(mn);
    }
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

    // @0x1424443f0
    const MovieDataDef::SceneInfo* MovieClip::GetSceneInfo(unsigned frame) const
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            for (UPInt i = 0; i < count; ++i)
            {
                if (frame >= pscenes[i].Offset && frame < pscenes[i].Offset + pscenes[i].NumFrames)
                    return &pscenes[i];
            }
        }
        return NULL;
    }

    // @0x142444490
    const MovieDataDef::SceneInfo* MovieClip::GetSceneInfoByName(const ASString& name) const
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            for (UPInt i = 0; i < count; ++i)
            {
                if (strcmp(name.ToCStr(), pscenes[i].Name.ToCStr()) == 0)
                    return &pscenes[i];
            }
        }
        return NULL;
    }

    // MS2-FUNCTIONAL: the no-scene throw schedules the scene-name load differently
    // @0x142444050
    bool MovieClip::GetLabeledFrame(GFx::Sprite* spr, const Value& frame, const Value& scene, unsigned* targetFrame)
    {
        spr->GetLabeledFrame(frame.AsString().ToCStr(), targetFrame);
        if (!scene.IsNull() && !scene.IsUndefined())
        {
            ASString sceneName = GetVM().GetStringManager().CreateEmptyString();
            scene.Convert2String(sceneName);
            const MovieDataDef::SceneInfo* pscene = GetSceneInfoByName(sceneName);
            if (!pscene)
            {
                GetVM().ThrowArgumentError(VM::Error(VM::eSceneNotFound, GetVM(), sceneName.ToCStr()));
                return false;
            }
            if (pscene != GetSceneInfo(*targetFrame))
            {
                GetVM().ThrowArgumentError(VM::Error(VM::eFrameLabelNotFoundInScene, GetVM(), frame, sceneName.ToCStr()));
                return false;
            }
        }
        else
        {
            // No scene given: the label has to be in the current scene.
            const MovieDataDef::SceneInfo* pcur = GetSceneInfo(spr->GetCurrentFrame());
            if (pcur)
            {
                const MovieDataDef::SceneInfo* ptarget = GetSceneInfo(*targetFrame);
                if (pcur != ptarget)
                {
                    VM& vm = GetVM();
                    vm.ThrowArgumentError(VM::Error(VM::eFrameLabelNotFoundInScene, vm, frame, pcur->Name.ToCStr()));
                    return false;
                }
            }
        }
        return true;
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
// MovieImpl::GetDrawableImageContext (made on first use).
void* FUN_14256f220(Scaleform::GFx::MovieImpl* pmovie);
// Render::DrawableImage constructors (format, size, transparent, fill color) and (transparent, delegate image),
// with the by-address size and color spelled out.
Scaleform::Render::ImageBase* FUN_1425e9810(void* pmem, Scaleform::UInt32 format, const Scaleform::UInt32* psize, bool transparent,
                                           const Scaleform::UInt32* pfillColor, void* pcontext);
Scaleform::Render::ImageBase* FUN_1425e9a00(void* pmem, bool transparent, Scaleform::Render::ImageBase* pdelegate, void* pcontext);
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

    // BitmapData(width, height, transparent = true, fillColor = 0xFFFFFFFF): a drawable image of that size, or a
    // drawable copy of the library bitmap the class is bound to.
    // @0x142440a20
    // MS2-FUNCTIONAL: written from the exe's control flow
    void BitmapData::AS3Constructor(unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        if (argc < 2)
        {
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "BitmapData::AS3Constructor", 2, 2, argc));
            return;
        }
        SInt32 w, h;
        if (!argv[0].Convert2Int32(w))
            return;
        Width = w;
        if (!argv[1].Convert2Int32(h))
            return;
        Height = h;
        UInt32 fillColor = 0xffffffff;
        if (argc > 2)
            Transparent = argv[2].Convert2Boolean();
        if (argc > 3)
            argv[3].Convert2UInt32(fillColor);

        // The render thread's interfaces (DrawableImageContext::pRTCommandQueue, ThreadCommandQueue::GetRenderInterfaces).
        void* pcontext = FUN_14256f220(GetASRoot(vm)->GetMovieImpl());
        void* pqueue = *reinterpret_cast<void**>(reinterpret_cast<UByte*>(pcontext) + 0x40);
        void* ifs[4] = { NULL, NULL, NULL, NULL };
        typedef void (*GetRenderInterfacesFn)(void*, void**);
        (*reinterpret_cast<GetRenderInterfacesFn* const*>(pqueue))[2](pqueue, ifs);
        void* pmem = SF_ALLOC(0xc8, Stat_Default_Mem);
        Render::ImageBase* pnew = NULL;
        if (!pImageResource)
        {
            if (pmem)
            {
                // TextureManager::GetDrawableImageFormat.
                typedef UInt32 (*GetFormatFn)(void*);
                UInt32 format = (*reinterpret_cast<GetFormatFn* const*>(ifs[0]))[12](ifs[0]);
                UInt32 size[2] = { (UInt32)Width, (UInt32)Height };
                pnew = FUN_1425e9810(pmem, format, size, Transparent, &fillColor, pcontext);
            }
        }
        else if (pmem)
            pnew = FUN_1425e9a00(pmem, true, pImageResource->GetImage(), pcontext);
        pImage = Pickable<Render::ImageBase>(pnew);
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

    // Binds a BitmapData to a library bitmap: the given image resource, or else the one exported under the
    // object's class name from its movie. The exe returns false on every path.
    // @0x142441730
    // MS2-FUNCTIONAL: written from the exe's control flow
    bool BindLibraryBitmap(BitmapData* pthis, Resource* pres, MovieDefImpl* pdefImpl)
    {
        if (pthis->pImage)
            return false;
        if (pres)
        {
            pthis->pImageResource = static_cast<ImageResource*>(pres);
            pthis->pImage = static_cast<ImageResource*>(pres)->GetImage();
            pthis->pDefImpl = pdefImpl;
            return false;
        }
        VM& vm = pthis->GetVM();
        MovieDefImpl* pobjDef = FUN_14250d8f0(vm, pthis);
        if (!pobjDef || !pthis->GetTraits().IsAbcObject())
            return false;
        ASString name = pthis->GetTraits().GetQualifiedName(Traits::qnfWithDot);
        MovieImpl* pmovie = GetASRoot(vm)->GetMovieImpl();
        ResourceBindData data;
        if (!FUN_14256ec50(pmovie, pobjDef, &data, String(name.ToCStr())))
        {
            Ptr<Log> plog = pmovie->GetLog();
            if (plog)
                plog->LogWarning("Attaching a bitmap with class '%s' failed", name.ToCStr());
            return false;
        }
        if (data.pResource &&
            (data.pResource->GetResourceTypeCode() & Resource::RT_TypeCode_Mask) == Resource::MakeTypeCode(Resource::RT_Image))
        {
            ImageResource* pimgRes = static_cast<ImageResource*>(data.pResource.GetPtr());
            pthis->pImageResource = pimgRes;
            pthis->pImage = pimgRes->GetImage();
            pthis->pDefImpl = data.pBinding ? data.pBinding->GetOwnerDefImpl() : pobjDef;
        }
        return false;
    }

    // @0x1424419e0
    // MS2-FUNCTIONAL: written from the exe's control flow
    GFx::DisplayObject* Bitmap::CreateStageObject()
    {
        if (pDispObj)
            return pDispObj;
        VM& vm = GetVM();
        ASMovieRootBase* proot = GetASRoot(vm);
        MovieDefImpl* pdefImpl = FUN_14250d8f0(vm, this);
        if (!pdefImpl)
            return pDispObj;
        CharacterCreateInfo ccinfo;
        ccinfo.pCharDef = NULL;
        ccinfo.pBindDefImpl = NULL;
        ccinfo.pResource = NULL;
        if (!FindLibrarySymbol(this, &ccinfo, pdefImpl) && !FUN_142501a80(proot, this, &ccinfo))
        {
            ccinfo.pCharDef = NULL;
            ccinfo.pResource = NULL;
        }
        DisplayObjectBase* pch = proot->pASSupport->CreateCharacterInstance(proot->GetMovieImpl(), ccinfo, NULL,
                                                                             ResourceId(0x40000), CharacterDef::Bitmap);
        AttachStageObject(this, static_cast<GFx::DisplayObject*>(pch));
        if (ccinfo.pResource &&
            (ccinfo.pResource->GetResourceTypeCode() & Resource::RT_TypeCode_Mask) == Resource::MakeTypeCode(Resource::RT_Image))
        {
            // A library bitmap: give it a BitmapData(0, 0) bound to the image.
            Value args[2] = { Value(Value::Number(0)), Value(Value::Number(0)) };
            SPtr<BitmapData> pbd;
            if (vm.ConstructBuiltinObject(pbd, "flash.display.BitmapData", 2, args) &&
                BindLibraryBitmap(pbd, ccinfo.pResource, ccinfo.pBindDefImpl))
            {
                pBitmapData = pbd;
                if (pDispObj)
                    FUN_142528e70(pDispObj, pBitmapData ? pBitmapData->pDefImpl.GetPtr() : NULL);
                if (pDispObj)
                    FUN_142520b20(pDispObj);
            }
        }
        return pDispObj;
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

// ---- Loader / LoaderInfo load notifications ----
// EventDispatcher::HasEventHandler(type, capture), CreateEventObject(type, bubbles, cancelable), and the IOErrorEvent /
// ProgressEvent makers, with their hidden return slots spelled out.
bool FUN_14246a160(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* pthis, const Scaleform::GFx::ASString& type, bool capture);
void FUN_142466cd0(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* pthis,
                   Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>* pret,
                   const Scaleform::GFx::ASString& type, bool bubbles, bool cancelable);
void FUN_142467190(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* pthis,
                   Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>* pret, const char* ptext);
void FUN_142467dc0(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* pthis,
                   Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>* pret,
                   const Scaleform::GFx::ASString& type);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_display
{
    // The AS3 movie root's builtin event names.
    enum LoadEventName
    {
        LoadEvent_complete = 0x298,
        LoadEvent_progress = 0x2a0,
        LoadEvent_open     = 0x2a8,
        LoadEvent_init     = 0x2b0
    };

    static ASString GetLoadEventName(VM& vm, LoadEventName name)
    {
        return ASString(*reinterpret_cast<ASStringNode**>(reinterpret_cast<UByte*>(GetASRoot(vm)) + name));
    }

    // Dispatches a plain event of the given name to pthis' listeners, if it has any.
    static void DispatchLoadEvent(fl_events::EventDispatcher* pthis, LoadEventName name)
    {
        ASString type = GetLoadEventName(pthis->GetVM(), name);
        if (FUN_14246a160(pthis, type, false))
        {
            SPtr<fl_events::Event> evt;
            FUN_142466cd0(pthis, &evt, type, false, false);
            evt->Target = pthis;
            pthis->DispatchSingleEvent(evt, false);
        }
    }

    // @0x1424421e0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::ExecuteCompleteEvent()
    {
        if (pContentLoaderInfo)
            pContentLoaderInfo->ExecuteCompleteEvent();
    }

    // @0x1424422a0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void LoaderInfo::ExecuteCompleteEvent()
    {
        DispatchLoadEvent(this, LoadEvent_complete);
    }

    // @0x142442410
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::ExecuteErrorEvent(const char* purl)
    {
        if (!pContentLoaderInfo)
            return;
        char text[1024];
        SFsprintf(text, sizeof(text), "Error reading %s", purl);
        pContentLoaderInfo->ExecuteErrorEvent(text);
    }

    // @0x142442520
    // MS2-FUNCTIONAL: written from the exe's control flow
    void LoaderInfo::ExecuteErrorEvent(const char* ptext)
    {
        SPtr<fl_events::Event> evt;
        FUN_142467190(this, &evt, ptext);
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x1424425d0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::ExecuteInitEvent(GFx::DisplayObject* pcontent)
    {
        if (pContentLoaderInfo)
            pContentLoaderInfo->ExecuteInitEvent(pcontent);
    }

    // @0x1424426d0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void LoaderInfo::ExecuteInitEvent(GFx::DisplayObject* pcontent)
    {
        if (pcontent)
        {
            // Make sure the content has its AS3 object (AvmDisplayObj virtual slot 15), then publish it.
            AvmDisplayObj* pavm = ToAvmDisplayObj(pcontent);
            typedef void (*CreateASInstanceFn)(AvmDisplayObj*, bool);
            (*reinterpret_cast<CreateASInstanceFn* const*>(pavm))[15](pavm, true);
            DisplayObject* pas3 = pavm->pAS3RawPtr;
            if (!pas3)
                pas3 = reinterpret_cast<DisplayObject*>(reinterpret_cast<UPInt>(pavm->pAS3CollectiblePtr) & ~(UPInt)1);
            Content = pas3;
        }
        DispatchLoadEvent(this, LoadEvent_init);
    }

    // @0x1424428f0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::ExecuteOpenEvent()
    {
        if (pContentLoaderInfo)
            pContentLoaderInfo->ExecuteOpenEvent();
    }

    // @0x1424429b0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void LoaderInfo::ExecuteOpenEvent()
    {
        DispatchLoadEvent(this, LoadEvent_open);
    }

    // @0x142442a60
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::ExecuteProgressEvent(UPInt bytesLoaded, UPInt bytesTotal)
    {
        if (pContentLoaderInfo)
            pContentLoaderInfo->ExecuteProgressEvent(bytesLoaded, bytesTotal);
    }

    // @0x142442b50
    // MS2-FUNCTIONAL: written from the exe's control flow
    void LoaderInfo::ExecuteProgressEvent(UPInt bytesLoaded, UPInt bytesTotal)
    {
        ASString type = GetLoadEventName(GetVM(), LoadEvent_progress);
        if (FUN_14246a160(this, type, false))
        {
            SPtr<fl_events::Event> evt;
            FUN_142467dc0(this, &evt, type);
            evt->Target = this;
            BytesLoaded = (UInt32)bytesLoaded;
            BytesTotal = (UInt32)bytesTotal;
            // ProgressEvent's bytesLoaded / bytesTotal (+0x58 / +0x60, 64-bit counts).
            UByte* pevt = reinterpret_cast<UByte*>(evt.GetPtr());
            *reinterpret_cast<UInt64*>(pevt + 0x58) = bytesLoaded;
            *reinterpret_cast<UInt64*>(pevt + 0x60) = bytesTotal;
            DispatchSingleEvent(evt, false);
        }
    }

    // @0x142443d00
    GFx::DisplayObject* LoaderInfo::GetContentDispObj() const
    {
        Ptr<GFx::DisplayObject> p;
        if (Content)
            p = Content->pDispObj;
        return p.GetPtr();
    }

    // @0x142443e40
    ImageResource* Bitmap::GetImageResource() const
    {
        return pBitmapData ? pBitmapData->GetImageResource() : NULL;
    }

    // @0x142443e50
    // MS2-FUNCTIONAL: written from the exe's control flow
    ImageResource* BitmapData::GetImageResource()
    {
        if (!pImageResource && pImage)
        {
            Render::ImageBase* pimg = pImage;
            ImageResource* pres = SF_HEAP_AUTO_NEW(pimg) ImageResource((Render::Image*)NULL);
            // A plain image goes behind the resource's delegate, any other image source is held directly.
            if (pimg->GetImageType() == Render::ImageBase::Type_ImageBase)
                pres->SetImage(static_cast<Render::Image*>(pimg));
            else
                pres->SetImageSource(static_cast<Render::ImageSource*>(pimg));
            pImageResource = Pickable<ImageResource>(pres);
        }
        return pImageResource;
    }

    // @0x142446bd0
    void Scene::Set(GFx::Sprite* psprite)
    {
        SpriteObj = psprite;
    }

    // @0x1424463f0
    void Loader::ResetContent()
    {
        pContentLoaderInfo->Content = NULL;
    }

    // An entry of the AS3 movie root's action queue as the loader fills it.
    struct LoaderActionEntry
    {
        void*                       pNext;          // +0x00
        int                         Type;           // +0x08
        Ptr<GFx::DisplayObject>     pCharacter;     // +0x10
        SPtr<Instances::fl::Object> pAS3Obj;        // +0x18
        UByte                       Pad20[0x18];    // +0x20
        Value                       Function;       // +0x38
        void                        (*CFunction)(const LoaderActionEntry& entry); // +0x58
        Ptr<RefCountImpl>           pRef;           // +0x60
    };
    // MovieRoot::ActionQueueType::InsertEntry
    extern "C" LoaderActionEntry* FUN_142512800(void* pqueue, int prio);

    static LoaderActionEntry* InsertLoaderAction(VM& vm)
    {
        return FUN_142512800(reinterpret_cast<UByte*>(GetASRoot(vm)) + 0x88, 6);
    }

    // @0x142442350
    static void LoaderCompleteAction(const LoaderActionEntry& entry)
    {
        static_cast<Loader*>(entry.pAS3Obj.GetPtr())->ExecuteCompleteEvent();
    }

    // @0x1424427d0
    // MS2-FUNCTIONAL: written from the exe's control flow
    static void LoaderInitAction(const LoaderActionEntry& entry)
    {
        static_cast<Loader*>(entry.pAS3Obj.GetPtr())->ExecuteInitEvent(entry.pCharacter);
        // Tell the load queue entry the init event ran (its virtual slot 2).
        if (RefCountImpl* pref = entry.pRef)
        {
            typedef void (*NotifyFn)(RefCountImpl*);
            (*reinterpret_cast<NotifyFn* const*>(pref))[2](pref);
        }
    }

    // @0x142445ca0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::QueueCompleteEvent()
    {
        if (!pContentLoaderInfo)
            return;
        if (LoaderActionEntry* pentry = InsertLoaderAction(GetVM()))
        {
            pentry->Type        = 3;
            pentry->pCharacter  = pDispObj;
            pentry->pAS3Obj     = this;
            pentry->CFunction   = LoaderCompleteAction;
            pentry->Function.SetUndefined();
            pentry->pRef        = NULL;
        }
    }

    // @0x142445db0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Loader::QueueInitEvent(GFx::DisplayObject* pcontent, Ptr<RefCountImpl> pref)
    {
        if (!pContentLoaderInfo)
            return;
        if (LoaderActionEntry* pentry = InsertLoaderAction(GetVM()))
        {
            pentry->Type        = 3;
            pentry->pCharacter  = pDispObj;
            pentry->pAS3Obj     = this;
            pentry->CFunction   = LoaderInitAction;
            pentry->Function.SetUndefined();
            pentry->pRef        = NULL;
            pentry->pCharacter  = pcontent;
            pentry->pRef        = pref;
        }
    }

    // @0x1424466b0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void MovieClip::FrameScript::Set(MemoryHeap* pheap, unsigned frameCnt, unsigned descrCnt, const Descr* pdescrs)
    {
        unsigned cnt = 0;
        if (!pData)
        {
            if (descrCnt == 0)
                return;
            FrameCnt = (UInt16)frameCnt;
            DescrCnt = (UInt16)(descrCnt < frameCnt ? descrCnt : frameCnt);
            pData = SF_HEAP_ALLOC(pheap, ((FrameCnt + 31) >> 5) * 4 + DescrCnt * sizeof(Descr), StatMV_ActionScript_Mem);
            if (!pData)
                return;
            memset(pData, 0, (FrameCnt + 7) >> 3);
            Descr* pdst = GetDescrs();
            // From the back: the last descriptor of a frame wins; they land at the top of the array.
            int k = DescrCnt;
            for (int i = DescrCnt - 1; i >= 0; --i)
            {
                unsigned frame = pdescrs[i].Frame;
                if (frame < FrameCnt && !IsSet(frame))
                {
                    new (&pdst[--k]) Descr(pdescrs[i]);
                    reinterpret_cast<UByte*>(pData)[frame >> 3] |= (UByte)(1 << (frame & 7));
                    ++cnt;
                }
            }
            if (k != 0)
                memmove(pdst, pdst + k, cnt * sizeof(Descr));
        }
        else
        {
            // Frames already set get their method replaced; count the new ones.
            unsigned added = 0;
            Descr* pdst = GetDescrs();
            for (int i = (int)descrCnt - 1; i >= 0; --i)
            {
                unsigned frame = pdescrs[i].Frame;
                if (frame >= FrameCnt)
                    continue;
                if (!IsSet(frame))
                    ++added;
                else
                {
                    UPInt j = Alg::LowerBoundSliced(pdst, 0, DescrCnt, Descr(Value::GetUndefined(), frame), Descr::Less);
                    pdst[j].Method = pdescrs[i].Method;
                    pdst[j].Frame  = frame;
                }
            }
            cnt = DescrCnt;
            if (added)
            {
                unsigned total = DescrCnt + added;
                pData = SF_REALLOC(pData, ((FrameCnt + 31) >> 5) * 4 + total * sizeof(Descr), StatMV_ActionScript_Mem);
                pdst = GetDescrs();
                unsigned k = total;
                for (int i = (int)descrCnt - 1; i >= 0 && k > DescrCnt; --i)
                {
                    unsigned frame = pdescrs[i].Frame;
                    if (frame < FrameCnt && !IsSet(frame))
                    {
                        new (&pdst[--k]) Descr(pdescrs[i]);
                        reinterpret_cast<UByte*>(pData)[frame >> 3] |= (UByte)(1 << (frame & 7));
                        ++cnt;
                    }
                }
                if (k != DescrCnt)
                    memmove(pdst + DescrCnt, pdst + k, (cnt - DescrCnt) * sizeof(Descr));
                DescrCnt = (UInt16)total;
            }
        }
        if (DescrCnt != cnt)
        {
            DescrCnt = (UInt16)cnt;
            pData = SF_REALLOC(pData, ((FrameCnt + 31) >> 5) * 4 + cnt * sizeof(Descr), StatMV_ActionScript_Mem);
        }
        Descr* pd = GetDescrs();
        Alg::QuickSortSliced(pd, 0, DescrCnt, Descr::Less);
    }
}}

namespace Classes { namespace fl_display
{
    // @0x1424439d0
    // MS2-FUNCTIONAL: written from the exe's control flow
    Render::BlendMode BlendMode::GetBlendMode(const ASString& name)
    {
        const char* p = name.ToCStr();
        if (!strcmp(p, "normal"))       return Render::Blend_Normal;
        if (!strcmp(p, "add"))          return Render::Blend_Add;
        if (!strcmp(p, "alpha"))        return Render::Blend_Alpha;
        if (!strcmp(p, "multiply"))     return Render::Blend_Multiply;
        if (!strcmp(p, "subtract"))     return Render::Blend_Subtract;
        if (!strcmp(p, "layer"))        return Render::Blend_Layer;
        if (!strcmp(p, "screen"))       return Render::Blend_Screen;
        if (!strcmp(p, "lighten"))      return Render::Blend_Lighten;
        if (!strcmp(p, "darken"))       return Render::Blend_Darken;
        if (!strcmp(p, "difference"))   return Render::Blend_Difference;
        if (!strcmp(p, "invert"))       return Render::Blend_Invert;
        if (!strcmp(p, "erase"))        return Render::Blend_Erase;
        if (!strcmp(p, "overlay"))      return Render::Blend_Overlay;
        if (!strcmp(p, "hardlight"))    return Render::Blend_HardLight;
        return Render::Blend_None;
    }
}}

// ThunkMakeDefs2 instances for MovieClip::gotoAndPlay @0x142439120 and gotoAndStop @0x142439280 (frame undefined,
// scene null); the thunks live in sfr_as3_05, which sees the same defaults through as3_obj_thunkdefs.h.
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_display::MovieClip, 13, const Value&, const Value&>(StringManager&);
template ThunkDefs2<const Value&, const Value&> ThunkMakeDefs2<Instances::fl_display::MovieClip, 14, const Value&, const Value&>(StringManager&);

namespace Instances { namespace fl_display
{
    // @0x1424442f0
    UPInt VectorPixelProvider::GetLength() const
    {
        UInt32 length;
        pVector->lengthGet(length);
        return length;
    }

    // @0x142445f30
    UInt32 ByteArrayPixelProvider::ReadNextPixel()
    {
        UInt32 v;
        pBytes->readUnsignedInt(v);
        return v;
    }

    // @0x142445f50
    UInt32 VectorPixelProvider::ReadNextPixel()
    {
        Value v;
        UInt32 ind = Index++;
        if (ind < (UInt32)pVector->V.V.GetSize())
            v.SetUInt32Unsafe(pVector->V.V[ind]);
        return v.AsUInt();
    }
}}

}}} // namespace Scaleform::GFx::AS3

// Filter list growth instances referenced out of line by the filter setters.
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>, Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>, Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);

namespace Scaleform { namespace GFx { namespace AS3 {

}}} // namespace Scaleform::GFx::AS3

// addFrameScript's descriptor array instances.
template Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr, Scaleform::AllocatorGH_CPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr, 2>, Scaleform::ArrayDefaultPolicy>::~ArrayDataBase();
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr, Scaleform::AllocatorGH_CPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ConstructorCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Construct(void*, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&);

namespace Scaleform { namespace GFx { namespace AS3 {

// VectorBase<UInt32>::Set instance, emitted here for the pixel vector writers.
// MS2-FUNCTIONAL: exe calls an out-of-line CheckFixed copy (0x14255b2d0); ours inlines it
// @0x142446540
template <>
CheckResult VectorBase<UInt32>::Set(UInt32 ind, const Value& v, const ClassTraits::Traits& tr)
{
    if ((Fixed && ind >= (UInt32)V.GetSize()) || ind > (UInt32)V.GetSize())
    {
        VM& vm = VMRef;
        vm.ThrowRangeError(VM::Error(VM::eInvalidRangeError, vm, (int)ind, (int)V.GetSize() - 1));
        return false;
    }
    if (ind == (UInt32)V.GetSize())
    {
        if (!CheckFixed())
            return false;
        UPInt i = V.GetSize();
        V.Resize(ind + 1);
        for (; i < ind + 1; ++i)
            V[i] = 0;
    }
    Value r;
    if (!CheckCoerce(tr, v, r))
        return false;
    V[ind] = r.AsUInt();
    return true;
}

}}} // namespace Scaleform::GFx::AS3

// The loader's content LoaderInfo (Loader::GetContentLoaderInfo, out of line in the exe).
// @0x142443d90
Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo* FUN_142443d90(Scaleform::GFx::AS3::Instances::fl_display::Loader* pthis)
{
    return pthis->pContentLoaderInfo.GetPtr();
}

// FilterSet::AddFilter, out of line in the exe (called from the filter conversion code).
// @0x142440dd0
void FUN_142440dd0(Scaleform::Render::FilterSet* pset, Scaleform::Render::Filter* pfilter)
{
    pset->AddFilter(pfilter);
}

// The frame script table destructor (an unreferenced COMDAT): Clear inlined.
// MS2-FUNCTIONAL: ours calls the out-of-line Clear
// @0x142440e50
void FUN_142440e50(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript* pthis)
{
    pthis->~FrameScript();
}

// ASVM::_constructInstance (exe body; as3_asvm.h clashes with as3_support.h's MovieRoot in this unit).
bool FUN_142531f40(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>& pobj,
                   Scaleform::GFx::AS3::Object* classObj, unsigned argc, const Scaleform::GFx::AS3::Value* argv);

// A Scene object standing for the whole clip (no scene table): an unreferenced MovieClip helper.
// MS2-FUNCTIONAL: written from the exe's control flow
// @0x142440f80
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Scene>
FUN_142440f80(Scaleform::GFx::AS3::Instances::fl_display::MovieClip* pthis)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    VM& vm = pthis->GetVM();
    SPtr<Instances::fl_display::Scene> scene;
    FUN_142531f40(vm, reinterpret_cast<SPtr<Object>&>(scene), vm.GetClass(StringDataPtr("flash.display.Scene")), 0, NULL);
    scene->SpriteObj = static_cast<GFx::Sprite*>(pthis->pDispObj.GetPtr());
    return scene;
}

// Graphics::AcquirePath: marks the display object dirty and starts a new path (a new shape when asked).
// noinline: the gradient helper calls it out of line.
// @0x142440d90
__declspec(noinline) void FUN_142440d90(Scaleform::GFx::AS3::Instances::fl_display::Graphics* pthis, bool newShapeFlag)
{
    pthis->pDispObj->SetDirtyFlag();
    pthis->pDispObj->InvalidateHitResult();
    pthis->pDrawing->AcquirePath(newShapeFlag);
}

// Graphics: reads the gradient arguments of beginGradientFill / lineGradientStyle (type, colors, alphas,
// ratios, matrix, spreadMethod, interpolationMethod, focalPointRatio) into the complex fill. Unlike later
// players this build requires all three arrays and uses an unscaled identity as the default matrix.
// MS2-FUNCTIONAL: register allocation and scheduling differ (the exe shrink-wraps the prologue past the argc check)
// @0x142441010
void FUN_142441010(Scaleform::GFx::AS3::Instances::fl_display::Graphics* pthis, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv, Scaleform::Render::ComplexFill* pfill)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using GFx::ASString;
    namespace NumberUtil = GFx::NumberUtil;
    if (argc < 4)
        return;
    ASString fillTypeStr(argv[0].AsString());
    if (!(fillTypeStr == "linear") && !(fillTypeStr == "radial"))
    {
        VM& vm = pthis->GetVM();
        vm.ThrowArgumentError(VM::Error(VM::eInvalidEnumParamError, vm, "type"));
        return;
    }

    if (!argv[1].IsObject())
        return;
    Instances::fl::Array* colors = static_cast<Instances::fl::Array*>(argv[1].GetObject());
    if (colors->GetTraits().GetTraitsType() != Traits_Array || colors->GetTraits().IsClassTraits())
        return;
    if (!argv[2].IsObject())
        return;
    Instances::fl::Array* alphas = static_cast<Instances::fl::Array*>(argv[2].GetObject());
    if (alphas->GetTraits().GetTraitsType() != Traits_Array || alphas->GetTraits().IsClassTraits())
        return;
    if (!argv[3].IsObject())
        return;
    Instances::fl::Array* ratios = static_cast<Instances::fl::Array*>(argv[3].GetObject());
    if (ratios->GetTraits().GetTraitsType() != Traits_Array || ratios->GetTraits().IsClassTraits())
        return;

    Render::Matrix2x4<double> matrix;
    if (argc > 4 && FUN_1425145d0(pthis->GetVM(), argv[4], "flash.geom.Matrix"))
        matrix = static_cast<Instances::fl_geom::Matrix*>(argv[4].GetObject())->GetMatrix();

    bool linearRGB = false;
    float focalPointRatio = 0;
    if (argc > 5)
    {
        // spreadMethod: read but not used.
        ASString spreadMethod(argv[5].AsString());
        if (argc > 6)
        {
            linearRGB = argv[6].AsString() == "linearRGB";
            if (argc > 7)
            {
                focalPointRatio = (float)argv[7].AsNumber();
                if (NumberUtil::IsNaN(focalPointRatio))
                    focalPointRatio = 0;
                else if (focalPointRatio < -1)
                    focalPointRatio = -1;
                else if (focalPointRatio > 1)
                    focalPointRatio = 1;
            }
        }
    }

    Render::GradientType gradType = Render::GradientLinear;
    if (fillTypeStr == "radial")
    {
        gradType = Render::GradientRadial;
        if (focalPointRatio != 0)
            gradType = Render::GradientFocalPoint;
    }
    pfill->pGradient = *SF_NEW Render::GradientData(gradType, (UInt16)colors->GetSize(), linearRGB);
    if (!pfill->pGradient)
        return;
    pfill->pGradient->SetFocalRatio(focalPointRatio);

    for (UPInt i = 0; i < colors->GetSize(); i++)
    {
        UInt32 color;
        colors->At(i).Convert2UInt32(color);
        Value::Number a, r;
        alphas->At(i).Convert2NumberInline(a);
        ratios->At(i).Convert2NumberInline(r);
        unsigned alpha = Alg::Min<unsigned>((unsigned)(a * 255.0), 255);
        float ratio = Alg::Max(0.0f, Alg::Min((float)r, 255.0f));
        Render::GradientRecord& record = pfill->pGradient->At((unsigned)i);
        record.Ratio = (UByte)ratio;
        record.ColorV.Raw = (color & 0xFFFFFF) | (alpha << 24);
    }

    FUN_142440d90(pthis, true);
    Render::Matrix2F matF;
    matF.Sx() = (float)matrix.Sx();
    matF.Shy() = (float)matrix.Shy();
    matF.Shx() = (float)matrix.Shx();
    matF.Sy() = (float)matrix.Sy();
    matF.Tx() = (float)Render::PixelsToTwips(matrix.Tx());
    matF.Ty() = (float)Render::PixelsToTwips(matrix.Ty());
    pfill->ImageMatrix.SetIdentity();
    pfill->ImageMatrix.AppendScaling(1.0f / 32768.0f);
    if (gradType == Render::GradientLinear)
        pfill->ImageMatrix.AppendTranslation(0.5f, 0.0f);
    else
        pfill->ImageMatrix.AppendTranslation(0.5f, 0.5f);
    pfill->ImageMatrix.Prepend(matF.GetInverse());
}

// The const flavour of the frame script lower bound (an unreferenced COMDAT next to the mutable one).
template Scaleform::UPInt Scaleform::Alg::LowerBoundSliced<const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr*,
    Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,
    bool (*)(const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&)>(
    const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr* const&, Scaleform::UPInt, Scaleform::UPInt,
    const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&,
    bool (*)(const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr&));

// The first five arguments of BitmapData.draw (source, matrix, colorTransform, blendMode, clipRect), read out of
// line by its thunk.
template struct Scaleform::GFx::AS3::ThunkArgs5<const Scaleform::GFx::AS3::Value,
    Scaleform::GFx::AS3::Instances::fl::Object*, Scaleform::GFx::AS3::Instances::fl_geom::Matrix*,
    Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform*, const Scaleform::GFx::ASString&,
    Scaleform::GFx::AS3::Instances::fl_geom::Rectangle*>;

// Out of line in the exe, called from the AS3 transform code and the render tree.
template Scaleform::Render::Matrix2x4<float>& Scaleform::Render::Matrix2x4<float>::Prepend(const Scaleform::Render::Matrix2x4<float>&);

namespace Scaleform { namespace GFx { namespace AS3 {

// SPtr assignment instances referenced out of line from the display object accessors.
template SPtr<Instances::fl_display::DisplayObject>& SPtr<Instances::fl_display::DisplayObject>::operator=(const SPtr<Instances::fl_display::DisplayObject>&);
template SPtr<Instances::fl_display::DisplayObject>& SPtr<Instances::fl_display::DisplayObject>::operator=(Instances::fl_display::DisplayObject*);
template SPtr<Instances::fl_display::DisplayObjectContainer>& SPtr<Instances::fl_display::DisplayObjectContainer>::operator=(Instances::fl_display::DisplayObjectContainer*);
template SPtr<Instances::fl_display::Graphics>& SPtr<Instances::fl_display::Graphics>::operator=(const SPtr<Instances::fl_display::Graphics>&);
template SPtr<Instances::fl_display::InteractiveObject>& SPtr<Instances::fl_display::InteractiveObject>::operator=(Instances::fl_display::InteractiveObject*);
template SPtr<Instances::fl_display::LoaderInfo>& SPtr<Instances::fl_display::LoaderInfo>::operator=(const SPtr<Instances::fl_display::LoaderInfo>&);
template SPtr<Instances::fl_geom::Rectangle>& SPtr<Instances::fl_geom::Rectangle>::operator=(Instances::fl_geom::Rectangle*);
template SPtr<Instances::fl_display::Sprite>& SPtr<Instances::fl_display::Sprite>::operator=(Instances::fl_display::Sprite*);
template SPtr<Instances::fl_display::Stage>& SPtr<Instances::fl_display::Stage>::operator=(Instances::fl_display::Stage*);
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
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
// MS2-PIN: ??$ThunkMakeDefs2@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0N@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142439120
// MS2-PIN: ??$ThunkMakeDefs2@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0O@AEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@YA?AU?$ThunkDefs2@AEBVValue@AS3@GFx@Scaleform@@AEBV1234@@012@AEAVStringManager@012@@Z 0x142439280
// MS2-PIN: ??_GImageResource@GFx@Scaleform@@UEAAPEAXI@Z 0x14243ede0
// MS2-PIN: ??4?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x14243d5d0
// MS2-PIN: ??4?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVDisplayObject@fl_display@Instances@123@@Z 0x14243d640
// MS2-PIN: ??4?$SPtr@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVDisplayObjectContainer@fl_display@Instances@123@@Z 0x14243d6b0
// MS2-PIN: ??4?$SPtr@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x14243d720
// MS2-PIN: ??4?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVInteractiveObject@fl_display@Instances@123@@Z 0x14243d790
// MS2-PIN: ??4?$SPtr@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x14243d800
// MS2-PIN: ??4?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVRectangle@fl_geom@Instances@123@@Z 0x14243d8e0
// MS2-PIN: ??4?$SPtr@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVSprite@fl_display@Instances@123@@Z 0x14243d950
// MS2-PIN: ??4?$SPtr@VStage@fl_display@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@PEAVStage@fl_display@Instances@123@@Z 0x14243d9c0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@UEAAPEAXI@Z 0x14243dbb0
// MS2-PIN: ??_G?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@UEAAPEAXI@Z 0x14243dc10
// MS2-PIN: ??$LowerBoundSliced@PEAUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U12345678@P6A_NAEBU12345678@0@Z@Alg@Scaleform@@YA_KAEBQEAUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@1@_K1AEBU23456781@P6A_N22@Z@Z 0x142439080
// MS2-PIN: ??$LowerBoundSliced@PEBUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U12345678@P6A_NAEBU12345678@0@Z@Alg@Scaleform@@YA_KAEBQEBUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@1@_K1AEBU23456781@P6A_N22@Z@Z 0x142438fe0
// MS2-PIN: ?Prepend@?$Matrix2x4@M@Render@Scaleform@@QEAAAEAV123@AEBV123@@Z 0x142445bc0
// MS2-PIN: ?Resize@?$ArrayDataDH@KU?$AllocatorDH@K$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAX_K@Z 0x142446430
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VFilter@Render@Scaleform@@@Scaleform@@U?$AllocatorGH@V?$Ptr@VFilter@Render@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1424462b0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@VFilter@Render@Scaleform@@@Scaleform@@U?$AllocatorGH@V?$Ptr@VFilter@Render@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1424464a0
// MS2-PIN: ??1?$ArrayDataBase@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U?$AllocatorGH_CPP@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$01@8@UArrayDefaultPolicy@8@@Scaleform@@QEAA@XZ 0x14243cf90
// MS2-PIN: ?Construct@?$ConstructorCPP@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAXAEBUDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@2@@Z 0x142440f00
// MS2-FUNCTIONAL ?Reserve@?$ArrayDataBase@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U?$AllocatorGH_CPP@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$01@8@UArrayDefaultPolicy@8@@Scaleform@@QEAAXPEBX_K@Z: the exe calls ConstructorCPP<Descr>::Construct out of line in the element-wise move; ours inlines it
// MS2-PIN: ?Reserve@?$ArrayDataBase@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@U?$AllocatorGH_CPP@UDescr@FrameScript@MovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$01@8@UArrayDefaultPolicy@8@@Scaleform@@QEAAXPEBX_K@Z 0x142446140
// MS2-FUNCTIONAL ??0?$ThunkArgs5@$$CBVValue@AS3@GFx@Scaleform@@PEAVObject@fl@Instances@234@PEAVMatrix@fl_geom@7234@PEAVColorTransform@97234@AEBVASString@34@PEAVRectangle@97234@@AS3@GFx@Scaleform@@QEAA@AEAVVM@123@AEAVValue@123@IPEBV5123@AEBU?$ThunkDefs5@PEAVObject@fl@Instances@AS3@GFx@Scaleform@@PEAVMatrix@fl_geom@3456@PEAVColorTransform@83456@AEBVASString@56@PEAVRectangle@83456@@123@@Z: the exe inlines the base argument readers; ours calls the ThunkArgs4 ctor
// MS2-PIN: ??0?$ThunkArgs5@$$CBVValue@AS3@GFx@Scaleform@@PEAVObject@fl@Instances@234@PEAVMatrix@fl_geom@7234@PEAVColorTransform@97234@AEBVASString@34@PEAVRectangle@97234@@AS3@GFx@Scaleform@@QEAA@AEAVVM@123@AEAVValue@123@IPEBV5123@AEBU?$ThunkDefs5@PEAVObject@fl@Instances@AS3@GFx@Scaleform@@PEAVMatrix@fl_geom@3456@PEAVColorTransform@83456@AEBVASString@56@PEAVRectangle@83456@@123@@Z 0x142439a70
