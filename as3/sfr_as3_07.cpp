// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_07
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142447390-0x142458c10 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142455e90: Instances::fl_events::KeyboardEvent::keyCodeGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 10, UInt32>;
// thunk 0x142455ef0: Instances::fl_events::KeyboardEvent::keyCodeSet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 11, const Value, UInt32>;
// thunk 0x142455f60: Instances::fl_events::KeyboardEvent::keyLocationGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 12, UInt32>;
// thunk 0x142455fc0: Instances::fl_events::KeyboardEvent::keyLocationSet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 13, const Value, UInt32>;
// thunk 0x142456030: Instances::fl_events::KeyboardEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 14, bool>;
// thunk 0x142456090: Instances::fl_events::KeyboardEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 15, const Value, bool>;
// thunk 0x142456250: Instances::fl_events::KeyboardEvent::clone
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 16, SPtr<Instances::fl_events::Event>>;
// thunk 0x142456470: Instances::fl_events::KeyboardEvent::toString
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 17, ASString>;
// thunk 0x1424564e0: Instances::fl_events::KeyboardEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 18, const Value>;
// thunk 0x142456680: Instances::fl_events::MouseEvent::altKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 0, bool>;
// thunk 0x1424566e0: Instances::fl_events::MouseEvent::altKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 1, const Value, bool>;
// thunk 0x142456740: Instances::fl_events::MouseEvent::buttonDownGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 2, bool>;
// thunk 0x1424567a0: Instances::fl_events::MouseEvent::buttonDownSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 3, const Value, bool>;
// thunk 0x142456800: Instances::fl_events::MouseEvent::clickCountGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 4, SInt32>;
// thunk 0x142456860: Instances::fl_events::MouseEvent::commandKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 5, bool>;
// thunk 0x142456a20: Instances::fl_events::MouseEvent::commandKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 6, const Value, bool>;
// thunk 0x142456a80: Instances::fl_events::MouseEvent::controlKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 7, bool>;
// thunk 0x142456ae0: Instances::fl_events::MouseEvent::controlKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 8, const Value, bool>;
// thunk 0x142456b40: Instances::fl_events::MouseEvent::ctrlKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 9, bool>;
// thunk 0x142456ba0: Instances::fl_events::MouseEvent::ctrlKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 10, const Value, bool>;
// thunk 0x142456c00: Instances::fl_events::MouseEvent::deltaGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 11, SInt32>;
// thunk 0x142456c60: Instances::fl_events::MouseEvent::deltaSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 12, const Value, SInt32>;
// thunk 0x142456cd0: Instances::fl_events::MouseEvent::localXGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 13, Value::Number>;
// thunk 0x142456d40: Instances::fl_events::MouseEvent::localXSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 14, const Value, Value::Number>;
// thunk 0x142456dd0: Instances::fl_events::MouseEvent::localYGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 15, Value::Number>;
// thunk 0x142456e40: Instances::fl_events::MouseEvent::localYSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 16, const Value, Value::Number>;
// thunk 0x142457030: Instances::fl_events::MouseEvent::relatedObjectGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 17, SPtr<Instances::fl_display::InteractiveObject>>;
// thunk 0x1424570e0: Instances::fl_events::MouseEvent::relatedObjectSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 18, const Value, Instances::fl_display::InteractiveObject*>;
// thunk 0x142457120: Instances::fl_events::MouseEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 19, bool>;
// thunk 0x142457180: Instances::fl_events::MouseEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 20, const Value, bool>;
// thunk 0x1424571e0: Instances::fl_events::MouseEvent::stageXGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 21, Value::Number>;
// thunk 0x142457250: Instances::fl_events::MouseEvent::stageYGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 22, Value::Number>;
// thunk 0x1424572c0: Instances::fl_events::MouseEvent::clone
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 23, SPtr<Instances::fl_events::Event>>;
// thunk 0x142457370: Instances::fl_events::MouseEvent::toString
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 24, ASString>;
// thunk 0x142457540: Instances::fl_events::MouseEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 25, const Value>;
// thunk 0x1424576e0: Instances::fl_events::NetStatusEvent::infoGet
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142457790: Instances::fl_events::NetStatusEvent::infoSet
template struct ThunkFunc1<Instances::fl_events::NetStatusEvent, 1, const Value, const Value&>;
// thunk 0x1424578e0: Instances::fl_events::NetStatusEvent::clone
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x142457c50: Instances::fl_events::NetStatusEvent::toString
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 3, ASString>;
// thunk 0x142457f80: Instances::fl_events::ProgressEvent::bytesLoadedGet
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 0, Value::Number>;
// thunk 0x142457ff0: Instances::fl_events::ProgressEvent::bytesLoadedSet
template struct ThunkFunc1<Instances::fl_events::ProgressEvent, 1, const Value, Value::Number>;
// thunk 0x142458080: Instances::fl_events::ProgressEvent::bytesTotalGet
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 2, Value::Number>;
// thunk 0x1424580f0: Instances::fl_events::ProgressEvent::bytesTotalSet
template struct ThunkFunc1<Instances::fl_events::ProgressEvent, 3, const Value, Value::Number>;
// thunk 0x142458180: Instances::fl_events::ProgressEvent::clone
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 4, SPtr<Instances::fl_events::Event>>;
// thunk 0x142458230: Instances::fl_events::ProgressEvent::toString
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 5, ASString>;
// thunk 0x142458980: Instances::fl_events::TextEvent::textGet
template struct ThunkFunc0<Instances::fl_events::TextEvent, 0, ASString>;
// thunk 0x1424589f0: Instances::fl_events::TextEvent::textSet
template struct ThunkFunc1<Instances::fl_events::TextEvent, 1, const Value, const ASString&>;
// thunk 0x142458af0: Instances::fl_events::TextEvent::clone
template struct ThunkFunc0<Instances::fl_events::TextEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x142458ba0: Instances::fl_events::TextEvent::toString
template struct ThunkFunc0<Instances::fl_events::TextEvent, 3, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_errors.h"

// Bitmap's pixel snapping mode of its AS3 name; AvmBitmap::RecreateRenderNode (both in sfr_as3_06).
Scaleform::SInt32 FUN_142446f30(Scaleform::GFx::AS3::Instances::fl_display::Bitmap* pbitmap, const char* pname);
void FUN_142520b20(Scaleform::GFx::DisplayObject* pbitmap);

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- flash.errors: class traits (instances are InstanceTraits::fl::Error, class objects plain Class) ----

namespace fl_errors
{
    extern const ClassInfo EOFErrorCI;
    extern const ClassInfo IOErrorCI;
    extern const ClassInfo IllegalOperationErrorCI;
    extern const ClassInfo InvalidSWFErrorCI;
    extern const ClassInfo MemoryErrorCI;
    extern const ClassInfo ScriptTimeoutErrorCI;
    extern const ClassInfo StackOverflowErrorCI;
}

namespace ClassTraits { namespace fl_errors
{
    // @0x142455410
    EOFError::EOFError(VM& vm)
        : Traits(vm, AS3::fl_errors::EOFErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::EOFErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454e70
    Pickable<Traits> EOFError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) EOFError(vm));
    }

    // @0x1424554f0
    IOError::IOError(VM& vm)
        : Traits(vm, AS3::fl_errors::IOErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::IOErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454d50
    Pickable<Traits> IOError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IOError(vm));
    }

    // @0x1424555d0
    IllegalOperationError::IllegalOperationError(VM& vm)
        : Traits(vm, AS3::fl_errors::IllegalOperationErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::IllegalOperationErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424552f0
    Pickable<Traits> IllegalOperationError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IllegalOperationError(vm));
    }

    // @0x1424556b0
    InvalidSWFError::InvalidSWFError(VM& vm)
        : Traits(vm, AS3::fl_errors::InvalidSWFErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::InvalidSWFErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454c30
    Pickable<Traits> InvalidSWFError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InvalidSWFError(vm));
    }

    // @0x142455790
    MemoryError::MemoryError(VM& vm)
        : Traits(vm, AS3::fl_errors::MemoryErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::MemoryErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454f90
    Pickable<Traits> MemoryError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MemoryError(vm));
    }

    // @0x142455870
    ScriptTimeoutError::ScriptTimeoutError(VM& vm)
        : Traits(vm, AS3::fl_errors::ScriptTimeoutErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::ScriptTimeoutErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424550b0
    Pickable<Traits> ScriptTimeoutError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ScriptTimeoutError(vm));
    }

    // @0x142455950
    StackOverflowError::StackOverflowError(VM& vm)
        : Traits(vm, AS3::fl_errors::StackOverflowErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::StackOverflowErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424551d0
    Pickable<Traits> StackOverflowError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StackOverflowError(vm));
    }
}}

// ---- flash.events: class traits factories (the ClassTraits ctors are in sfr_as3_08) ----

namespace ClassTraits { namespace fl_events
{
    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424560f0
    Pickable<Traits> GestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456300
    Pickable<Traits> StageOrientation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageOrientation(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456500
    Pickable<Traits> TransformGestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TransformGestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424568c0
    Pickable<Traits> PressAndTapGestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) PressAndTapGestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456ed0
    Pickable<Traits> KeyboardEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) KeyboardEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424573e0
    Pickable<Traits> ProgressEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ProgressEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457560
    Pickable<Traits> FocusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FocusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457990
    Pickable<Traits> TextEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457af0
    Pickable<Traits> IOErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IOErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457cc0
    Pickable<Traits> ErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457e20
    Pickable<Traits> NetStatusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) NetStatusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424582a0
    Pickable<Traits> SecurityErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142458400
    Pickable<Traits> AsyncErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AsyncErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142458560
    Pickable<Traits> StatusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StatusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424586c0
    Pickable<Traits> SyncEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SyncEvent(vm));
    }
}}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// ---- flash.display.DisplayObject: simple property getters forwarding to the scripted display object ----
namespace Instances { namespace fl_display
{
    // @0x142447de0
    void DisplayObject::alphaGet(Value::Number& result)
    {
        result = pDispObj->GetAlpha() / 100.0;
    }

    // @0x14244e520
    void DisplayObject::heightGet(Value::Number& result)
    {
        result = pDispObj->GetHeight();
    }

    // @0x142450880
    void DisplayObject::mouseXGet(Value::Number& result)
    {
        result = pDispObj->GetMouseX();
    }

    // @0x1424508a0
    void DisplayObject::mouseYGet(Value::Number& result)
    {
        result = pDispObj->GetMouseY();
    }

    // @0x142452150
    void DisplayObject::rotationGet(Value::Number& result)
    {
        result = pDispObj->GetRotation();
    }

    // @0x142452190
    void DisplayObject::rotationXGet(Value::Number& result)
    {
        result = pDispObj->GetXRotation();
    }

    // @0x1424521d0
    void DisplayObject::rotationYGet(Value::Number& result)
    {
        result = pDispObj->GetYRotation();
    }

    // @0x142452210
    void DisplayObject::rotationZGet(Value::Number& result)
    {
        result = pDispObj->GetRotation();
    }

    // @0x142452660
    void DisplayObject::scaleXGet(Value::Number& result)
    {
        result = pDispObj->GetXScale() / 100.0;
    }

    // @0x1424526b0
    void DisplayObject::scaleYGet(Value::Number& result)
    {
        result = pDispObj->GetYScale() / 100.0;
    }

    // @0x142452700
    void DisplayObject::scaleZGet(Value::Number& result)
    {
        result = pDispObj->GetZScale() / 100.0;
    }

    // @0x142454920
    void DisplayObject::visibleGet(bool& result)
    {
        result = pDispObj->GetVisible();
    }

    // @0x142454a00
    void DisplayObject::widthGet(Value::Number& result)
    {
        result = pDispObj->GetWidth();
    }

    // @0x142454b60
    void DisplayObject::xGet(Value::Number& result)
    {
        result = pDispObj->GetX();
    }

    // @0x142454ba0
    void DisplayObject::yGet(Value::Number& result)
    {
        result = pDispObj->GetY();
    }

    // @0x142454be0
    void DisplayObject::zGet(Value::Number& result)
    {
        result = pDispObj->GetZ() * 0.05;
    }
}}

// ---- flash.display.Graphics: drawing API forwarding to the DrawingContext (coordinates converted to twips) ----

namespace Instances { namespace fl_display
{
    // @0x142448400
    void Graphics::beginFill(const Value& result, UInt32 color, Value::Number alpha)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(true);
        pDrawing->BeginSolidFill((UInt32(alpha * 255.0) << 24) | color);
    }

    // @0x1424489d0
    void Graphics::clear(const Value& result)
    {
        SF_UNUSED(result);
        pDrawing->Clear();
        pDispObj->InvalidateHitResult();
        pDispObj->SetDirtyFlag();
    }

    // @0x142449b70
    void Graphics::curveTo(const Value& result, Value::Number controlX, Value::Number controlY,
                           Value::Number anchorX, Value::Number anchorY)
    {
        SF_UNUSED(result);
        pDrawing->CurveTo(float(controlX) * 20.0f, float(controlY) * 20.0f,
                          float(anchorX) * 20.0f, float(anchorY) * 20.0f);
        pDispObj->InvalidateHitResult();
    }

    // @0x14244b9f0
    void Graphics::endFill(const Value& result)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(true);
        pDrawing->EndFill();
    }

    // @0x14244fdd0
    void Graphics::lineTo(const Value& result, Value::Number x, Value::Number y)
    {
        SF_UNUSED(result);
        pDrawing->LineTo(float(x * 20.0), float(y * 20.0));
        pDispObj->InvalidateHitResult();
    }

    // @0x1424508c0
    void Graphics::moveTo(const Value& result, Value::Number x, Value::Number y)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(false);
        pDrawing->MoveTo(float(x * 20.0), float(y * 20.0));
        pDispObj->InvalidateHitResult();
    }
}}

// ---- flash.display: by-value forms of the SPtr-returning natives (used by the thunk table) ----

namespace Instances { namespace fl_display
{
    // @0x1424474d0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::addChild(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        addChild(result, a0);
        return result;
    }

    // @0x142447640
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::addChildAt(Instances::fl_display::DisplayObject* a0, SInt32 a1)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        addChildAt(result, a0, a1);
        return result;
    }

    // @0x142447e30
    SPtr<Instances::fl_system::ApplicationDomain> LoaderInfo::applicationDomainGet()
    {
        SPtr<Instances::fl_system::ApplicationDomain> result;
        applicationDomainGet(result);
        return result;
    }

    // @0x142449930
    SPtr<Instances::fl_display::Scene> MovieClip::currentSceneGet()
    {
        SPtr<Instances::fl_display::Scene> result;
        currentSceneGet(result);
        return result;
    }

    // @0x142449de0
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::downStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        downStateGet(result);
        return result;
    }

    // @0x14244b850
    SPtr<Instances::fl_display::DisplayObject> Sprite::dropTargetGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        dropTargetGet(result);
        return result;
    }

    // @0x14244bb60
    SPtr<Instances::fl::Array> DisplayObject::filtersGet()
    {
        SPtr<Instances::fl::Array> result;
        filtersGet(result);
        return result;
    }

    // @0x14244c060
    SPtr<Instances::fl_display::InteractiveObject> Stage::focusGet()
    {
        SPtr<Instances::fl_display::InteractiveObject> result;
        focusGet(result);
        return result;
    }

    // @0x14244c570
    SPtr<Instances::fl_geom::Rectangle> BitmapData::generateFilterRect(Instances::fl_geom::Rectangle* a0, Instances::fl_filters::BitmapFilter* a1)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        generateFilterRect(result, a0, a1);
        return result;
    }

    // @0x14244c8f0
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::getBounds(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getBounds(result, a0);
        return result;
    }

    // @0x14244cc80
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::getChildAt(SInt32 a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        getChildAt(result, a0);
        return result;
    }

    // @0x14244cdc0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::getChildByName(const ASString& a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        getChildByName(result, a0);
        return result;
    }

    // @0x14244cfb0
    SPtr<Instances::fl_geom::Rectangle> BitmapData::getColorBoundsRect(UInt32 a0, UInt32 a1, bool a2)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getColorBoundsRect(result, a0, a1, a2);
        return result;
    }

    // @0x14244d1c0
    SPtr<Instances::fl::Array> DisplayObjectContainer::getObjectsUnderPoint(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl::Array> result;
        getObjectsUnderPoint(result, a0);
        return result;
    }

    // @0x14244d540
    SPtr<Instances::fl_utils::ByteArray> BitmapData::getPixels(Instances::fl_geom::Rectangle* a0)
    {
        SPtr<Instances::fl_utils::ByteArray> result;
        getPixels(result, a0);
        return result;
    }

    // @0x14244d740
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::getRect(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getRect(result, a0);
        return result;
    }

    // @0x14244dad0
    SPtr<Instances::fl_vec::Vector_uint> BitmapData::getVector(Instances::fl_geom::Rectangle* a0)
    {
        SPtr<Instances::fl_vec::Vector_uint> result;
        getVector(result, a0);
        return result;
    }

    // @0x14244dd00
    SPtr<Instances::fl_geom::Vector3D> DisplayObject::globalToLocal3D(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Vector3D> result;
        globalToLocal3D(result, a0);
        return result;
    }

    // @0x14244df20
    SPtr<Instances::fl_geom::Point> DisplayObject::globalToLocal(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        globalToLocal(result, a0);
        return result;
    }

    // @0x14244e2c0
    SPtr<Instances::fl_display::Graphics> Shape::graphicsGet()
    {
        SPtr<Instances::fl_display::Graphics> result;
        graphicsGet(result);
        return result;
    }

    // @0x14244e3a0
    SPtr<Instances::fl_display::Graphics> Sprite::graphicsGet()
    {
        SPtr<Instances::fl_display::Graphics> result;
        graphicsGet(result);
        return result;
    }

    // @0x14244f480
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::hitTestStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        hitTestStateGet(result);
        return result;
    }

    // @0x14244f590
    SPtr<Instances::fl::Array> Scene::labelsGet()
    {
        SPtr<Instances::fl::Array> result;
        labelsGet(result);
        return result;
    }

    // @0x14244ff90
    SPtr<Instances::fl_display::LoaderInfo> DisplayObject::loaderInfoGet()
    {
        SPtr<Instances::fl_display::LoaderInfo> result;
        loaderInfoGet(result);
        return result;
    }

    // @0x1424500c0
    SPtr<Instances::fl_geom::Point> DisplayObject::local3DToGlobal(Instances::fl_geom::Vector3D* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        local3DToGlobal(result, a0);
        return result;
    }

    // @0x1424502a0
    SPtr<Instances::fl_geom::Point> DisplayObject::localToGlobal(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        localToGlobal(result, a0);
        return result;
    }

    // @0x142450e30
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::overStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        overStateGet(result);
        return result;
    }

    // @0x142451240
    SPtr<Instances::fl_display::DisplayObjectContainer> DisplayObject::parentGet()
    {
        SPtr<Instances::fl_display::DisplayObjectContainer> result;
        parentGet(result);
        return result;
    }

    // @0x142451bf0
    SPtr<Instances::fl_geom::Rectangle> BitmapData::rectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        rectGet(result);
        return result;
    }

    // @0x142451ed0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::removeChildAt(SInt32 a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        removeChildAt(result, a0);
        return result;
    }

    // @0x142452270
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::scale9GridGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        scale9GridGet(result);
        return result;
    }

    // @0x142452750
    SPtr<Instances::fl::Array> MovieClip::scenesGet()
    {
        SPtr<Instances::fl::Array> result;
        scenesGet(result);
        return result;
    }

    // @0x142452a60
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::scrollRectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        scrollRectGet(result);
        return result;
    }

    // @0x142453470
    SPtr<Instances::fl_display::Stage> DisplayObject::stageGet()
    {
        SPtr<Instances::fl_display::Stage> result;
        stageGet(result);
        return result;
    }

    // @0x142453cf0
    SPtr<Instances::fl_text::TextSnapshot> DisplayObjectContainer::textSnapshotGet()
    {
        SPtr<Instances::fl_text::TextSnapshot> result;
        textSnapshotGet(result);
        return result;
    }

    // @0x142454380
    SPtr<Instances::fl_geom::Transform> DisplayObject::transformGet()
    {
        SPtr<Instances::fl_geom::Transform> result;
        transformGet(result);
        return result;
    }

    // @0x1424546e0
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::upStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        upStateGet(result);
        return result;
    }
}}

// ---- flash.display: small natives ----

namespace Instances { namespace fl_display
{
    // @0x142449cf0
    void BitmapData::dispose(const Value& result)
    {
        SF_UNUSED(result);
        pImage = NULL;
        Width = 0;
        Height = 0;
    }

    // @0x1424496a0
    void MovieClip::currentFrameGet(SInt32& result)
    {
        if (!pDispObj)
            result = 0;
        else
            result = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->GetCurrentFrame() + 1;
    }

    // @0x1424509c0
    void FrameLabel::nameGet(ASString& result)
    {
        result = FrameName;
    }

    // @0x142451a50
    void Bitmap::pixelSnappingSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        PixelSnapping = FUN_142446f30(this, value.ToCStr());
        if (pDispObj)
            FUN_142520b20(pDispObj);
    }
}}

// ---- flash.display: getters this build does not implement (warn and return null) ----

namespace Instances { namespace fl_display
{
    void DisplayObject::accessibilityPropertiesGet(SPtr<Instances::fl_accessibility::AccessibilityProperties>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::DisplayObject::accessibilityPropertiesGet() is not implemented\n");
    }

    // @0x142447440
    SPtr<Instances::fl_accessibility::AccessibilityProperties> DisplayObject::accessibilityPropertiesGet()
    {
        SPtr<Instances::fl_accessibility::AccessibilityProperties> result;
        accessibilityPropertiesGet(result);
        return result;
    }

    void LoaderInfo::bytesGet(SPtr<Instances::fl_utils::ByteArray>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method LoaderInfo::bytesGet() is not implemented\n");
    }

    // @0x142448810
    SPtr<Instances::fl_utils::ByteArray> LoaderInfo::bytesGet()
    {
        SPtr<Instances::fl_utils::ByteArray> result;
        bytesGet(result);
        return result;
    }

    void Stage::fullScreenSourceRectGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Stage::fullScreenSourceRectGet() is not implemented\n");
    }

    // @0x14244c4d0
    SPtr<Instances::fl_geom::Rectangle> Stage::fullScreenSourceRectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        fullScreenSourceRectGet(result);
        return result;
    }

    void LoaderInfo::sharedEventsGet(SPtr<Instances::fl_events::EventDispatcher>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method LoaderInfo::sharedEventsGet() is not implemented\n");
    }

    // @0x142453250
    SPtr<Instances::fl_events::EventDispatcher> LoaderInfo::sharedEventsGet()
    {
        SPtr<Instances::fl_events::EventDispatcher> result;
        sharedEventsGet(result);
        return result;
    }

    void SimpleButton::soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SimpleButton::soundTransformGet() is not implemented\n");
    }

    // @0x142453320
    SPtr<Instances::fl_media::SoundTransform> SimpleButton::soundTransformGet()
    {
        SPtr<Instances::fl_media::SoundTransform> result;
        soundTransformGet(result);
        return result;
    }

    void Sprite::soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Sprite::soundTransformGet() is not implemented\n");
    }

    // @0x142453380
    SPtr<Instances::fl_media::SoundTransform> Sprite::soundTransformGet()
    {
        SPtr<Instances::fl_media::SoundTransform> result;
        soundTransformGet(result);
        return result;
    }

    void Stage::textSnapshotGet(SPtr<Instances::fl_text::TextSnapshot>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Stage::textSnapshotGet() is not implemented\n");
    }

    // @0x142453e50
    SPtr<Instances::fl_text::TextSnapshot> Stage::textSnapshotGet()
    {
        SPtr<Instances::fl_text::TextSnapshot> result;
        textSnapshotGet(result);
        return result;
    }
}}

namespace Instances { namespace fl_display
{
    // @0x142448790
    void DisplayObject::blendModeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        Render::BlendMode mode = Classes::fl_display::BlendMode::GetBlendMode(value);
        pDispObj->SetBlendMode(mode);
    }

    // @0x142450540
    void DisplayObject::maskSet(const Value& result, Instances::fl_display::DisplayObject* value)
    {
        SF_UNUSED(result);
        GFx::DisplayObject* pmask;
        if (!value)
            pmask = NULL;
        else
        {
            pmask = value->pDispObj;
            if (!pmask)
            {
                value->CreateStageObject();
                pmask = value->pDispObj;
            }
        }
        pDispObj->SetMask(pmask);
    }

    // @0x14244ecc0
    void Sprite::hitAreaSet(const Value& result, Instances::fl_display::Sprite* value)
    {
        SF_UNUSED(result);
        GFx::DisplayObject* phit;
        if (value)
        {
            phit = value->pDispObj;
            if (!phit)
            {
                value->CreateStageObject();
                phit = value->pDispObj;
            }
        }
        else
            phit = NULL;
        static_cast<GFx::Sprite*>(pDispObj.GetPtr())->SetHitArea(static_cast<GFx::Sprite*>(phit));
    }

    // @0x14244c480
    void MovieClip::framesLoadedGet(SInt32& result)
    {
        if (!pDispObj)
        {
            result = 1;
            return;
        }
        result = static_cast<GFx::Sprite*>(pDispObj.GetPtr())->GetLoadingFrame();
    }

    // @0x142451a90
    void MovieClip::prevFrame(const Value& result)
    {
        SF_UNUSED(result);
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        int frame = psprite->GetCurrentFrame();
        if (frame > 0)
            psprite->GotoFrame(frame - 1);
        psprite->SetPlayState(State_Stopped);
    }

    // @0x1424542b0
    void MovieClip::totalFramesGet(SInt32& result)
    {
        result = static_cast<GFx::Sprite*>(pDispObj.GetPtr())->pDef->GetFrameCount();
    }

    // @0x142450d60
    void Scene::numFramesGet(SInt32& result)
    {
        if (SceneInfo)
        {
            result = SceneInfo->NumFrames;
            return;
        }
        result = SpriteObj->pDef->GetFrameCount();
    }

    // @0x142453420
    void Stage::stageFocusRectGet(bool& result)
    {
        result = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->IsFocusRectEnabled();
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455e90
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455ef0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455f60
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456030
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456090
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456250
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456470
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424564e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456680
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424566e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456740
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424567a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456800
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456860
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456a20
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456a80
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456ae0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456b40
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456ba0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456c00
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456c60
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456cd0
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456d40
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456dd0
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456e40
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457030
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@PEAVInteractiveObject@fl_display@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424570e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BD@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457120
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457180
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424571e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BG@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457250
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BH@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424572c0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BI@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457370
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457540
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424576e0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457790
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424578e0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457c50
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457f80
// MS2-PIN: ?Func@?$ThunkFunc1@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457ff0
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458080
// MS2-PIN: ?Func@?$ThunkFunc1@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424580f0
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458180
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458230
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458980
// MS2-PIN: ?Func@?$ThunkFunc1@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424589f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458af0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458ba0
// MS2-PIN: ??_7EOFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f138
// MS2-PIN: ??_7IOError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f0a8
// MS2-PIN: ??_7IllegalOperationError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ef70
// MS2-PIN: ??_7InvalidSWFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f010
// MS2-PIN: ??_7MemoryError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f1c8
// MS2-PIN: ??_7ScriptTimeoutError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f260
// MS2-PIN: ??_7StackOverflowError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f2f8
// MS2-PIN: ??_GEOFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455a30
// MS2-PIN: ??_GIOError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455ac0
// MS2-PIN: ??_GIllegalOperationError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455b50
// MS2-PIN: ??_GInvalidSWFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455be0
// MS2-PIN: ??_GMemoryError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455c70
// MS2-PIN: ??_GScriptTimeoutError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455d00
// MS2-PIN: ??_GStackOverflowError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455d90
