// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142458c10-0x142463900 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142458c10: Instances::fl_events::EventDispatcher::addEventListener
template struct ThunkFunc5<Instances::fl_events::EventDispatcher, 0, const Value, const ASString&, const Value&, bool, SInt32, bool>;
// thunk 0x142458eb0: Instances::fl_events::EventDispatcher::dispatchEvent
template struct ThunkFunc1<Instances::fl_events::EventDispatcher, 1, bool, Instances::fl_events::Event*>;
// thunk 0x142458f50: Instances::fl_events::EventDispatcher::hasEventListener
template struct ThunkFunc1<Instances::fl_events::EventDispatcher, 2, bool, const ASString&>;
// thunk 0x142459090: Instances::fl_events::EventDispatcher::removeEventListener
// MS2-FUNCTIONAL: block order only: the exe reads the bool argument after the string and value arguments with the call inline in each branch
template struct ThunkFunc3<Instances::fl_events::EventDispatcher, 3, const Value, const ASString&, const Value&, bool>;
// thunk 0x142459400: Instances::fl_events::EventDispatcher::willTrigger
template struct ThunkFunc1<Instances::fl_events::EventDispatcher, 4, bool, const ASString&>;
// thunk 0x142459540: Instances::fl_events::TimerEvent::clone
template struct ThunkFunc0<Instances::fl_events::TimerEvent, 0, SPtr<Instances::fl_events::Event>>;
// thunk 0x1424595f0: Instances::fl_events::TimerEvent::toString
template struct ThunkFunc0<Instances::fl_events::TimerEvent, 1, ASString>;
// thunk 0x142459660: Instances::fl_events::TimerEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::TimerEvent, 2, const Value>;
// thunk 0x142459680: Instances::fl_events::GestureEvent::altKeyGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 0, bool>;
// thunk 0x1424596e0: Instances::fl_events::GestureEvent::altKeySet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 1, const Value, bool>;
// thunk 0x142459740: Instances::fl_events::GestureEvent::commandKeyGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 2, bool>;
// thunk 0x1424597a0: Instances::fl_events::GestureEvent::commandKeySet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 3, const Value, bool>;
// thunk 0x142459800: Instances::fl_events::GestureEvent::controlKeyGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 4, bool>;
// thunk 0x142459860: Instances::fl_events::GestureEvent::controlKeySet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 5, const Value, bool>;
// thunk 0x1424598c0: Instances::fl_events::GestureEvent::ctrlKeyGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 6, bool>;
// thunk 0x142459a70: Instances::fl_events::GestureEvent::ctrlKeySet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 7, const Value, bool>;
// thunk 0x142459ad0: Instances::fl_events::GestureEvent::localXGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 8, Value::Number>;
// thunk 0x142459b40: Instances::fl_events::GestureEvent::localXSet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 9, const Value, Value::Number>;
// thunk 0x142459bd0: Instances::fl_events::GestureEvent::localYGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 10, Value::Number>;
// thunk 0x142459c40: Instances::fl_events::GestureEvent::localYSet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 11, const Value, Value::Number>;
// thunk 0x142459cd0: Instances::fl_events::GestureEvent::phaseGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 12, ASString>;
// thunk 0x142459d40: Instances::fl_events::GestureEvent::phaseSet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 13, const Value, const ASString&>;
// thunk 0x142459e40: Instances::fl_events::GestureEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 14, bool>;
// thunk 0x142459ea0: Instances::fl_events::GestureEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::GestureEvent, 15, const Value, bool>;
// thunk 0x142459f00: Instances::fl_events::GestureEvent::stageXGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 16, Value::Number>;
// thunk 0x142459f70: Instances::fl_events::GestureEvent::stageYGet
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 17, Value::Number>;
// thunk 0x142459fe0: Instances::fl_events::GestureEvent::clone
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 18, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245a090: Instances::fl_events::GestureEvent::toString
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 19, ASString>;
// thunk 0x14245a100: Instances::fl_events::GestureEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::GestureEvent, 20, const Value>;
// thunk 0x14245a270: Instances::fl_events::TransformGestureEvent::offsetXGet
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 0, Value::Number>;
// thunk 0x14245a2e0: Instances::fl_events::TransformGestureEvent::offsetXSet
template struct ThunkFunc1<Instances::fl_events::TransformGestureEvent, 1, const Value, Value::Number>;
// thunk 0x14245a370: Instances::fl_events::TransformGestureEvent::offsetYGet
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 2, Value::Number>;
// thunk 0x14245a3e0: Instances::fl_events::TransformGestureEvent::offsetYSet
template struct ThunkFunc1<Instances::fl_events::TransformGestureEvent, 3, const Value, Value::Number>;
// thunk 0x14245a470: Instances::fl_events::TransformGestureEvent::rotationGet
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 4, Value::Number>;
// thunk 0x14245a4e0: Instances::fl_events::TransformGestureEvent::rotationSet
template struct ThunkFunc1<Instances::fl_events::TransformGestureEvent, 5, const Value, Value::Number>;
// thunk 0x14245a570: Instances::fl_events::FocusEvent::directionGet
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 0, ASString>;
// thunk 0x14245a5e0: Instances::fl_events::TransformGestureEvent::scaleXGet
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 6, Value::Number>;
// thunk 0x14245a650: Instances::fl_events::FocusEvent::directionSet
template struct ThunkFunc1<Instances::fl_events::FocusEvent, 1, const Value, const ASString&>;
// thunk 0x14245a750: Instances::fl_events::TransformGestureEvent::scaleXSet
template struct ThunkFunc1<Instances::fl_events::TransformGestureEvent, 7, const Value, Value::Number>;
// thunk 0x14245a7e0: Instances::fl_events::FocusEvent::keyCodeGet
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 2, UInt32>;
// thunk 0x14245a840: Instances::fl_events::TransformGestureEvent::scaleYGet
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 8, Value::Number>;
// thunk 0x14245a8b0: Instances::fl_events::FocusEvent::keyCodeSet
template struct ThunkFunc1<Instances::fl_events::FocusEvent, 3, const Value, UInt32>;
// thunk 0x14245a920: Instances::fl_events::TransformGestureEvent::scaleYSet
template struct ThunkFunc1<Instances::fl_events::TransformGestureEvent, 9, const Value, Value::Number>;
// thunk 0x14245a9b0: Instances::fl_events::FocusEvent::relatedObjectGet
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 4, SPtr<Instances::fl_display::InteractiveObject>>;
// thunk 0x14245aa60: Instances::fl_events::TransformGestureEvent::clone
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 10, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245ab10: Instances::fl_events::FocusEvent::relatedObjectSet
template struct ThunkFunc1<Instances::fl_events::FocusEvent, 5, const Value, Instances::fl_display::InteractiveObject*>;
// thunk 0x14245ab50: Instances::fl_events::TransformGestureEvent::toString
template struct ThunkFunc0<Instances::fl_events::TransformGestureEvent, 11, ASString>;
// thunk 0x14245abc0: Instances::fl_events::FocusEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 6, bool>;
// thunk 0x14245ac20: Instances::fl_events::FocusEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::FocusEvent, 7, const Value, bool>;
// thunk 0x14245ac80: Instances::fl_events::FocusEvent::clone
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 8, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245ad30: Instances::fl_events::FocusEvent::toString
template struct ThunkFunc0<Instances::fl_events::FocusEvent, 9, ASString>;
// thunk 0x14245af00: Instances::fl_events::ErrorEvent::errorIDGet
template struct ThunkFunc0<Instances::fl_events::ErrorEvent, 0, SInt32>;
// thunk 0x14245af60: Instances::fl_events::ErrorEvent::clone
template struct ThunkFunc0<Instances::fl_events::ErrorEvent, 1, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245b010: Instances::fl_events::PressAndTapGestureEvent::tapLocalXGet
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 0, Value::Number>;
// thunk 0x14245b080: Instances::fl_events::ErrorEvent::toString
template struct ThunkFunc0<Instances::fl_events::ErrorEvent, 2, ASString>;
// thunk 0x14245b0f0: Instances::fl_events::PressAndTapGestureEvent::tapLocalXSet
template struct ThunkFunc1<Instances::fl_events::PressAndTapGestureEvent, 1, const Value, Value::Number>;
// thunk 0x14245b2e0: Instances::fl_events::PressAndTapGestureEvent::tapLocalYGet
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 2, Value::Number>;
// thunk 0x14245b350: Instances::fl_events::PressAndTapGestureEvent::tapLocalYSet
template struct ThunkFunc1<Instances::fl_events::PressAndTapGestureEvent, 3, const Value, Value::Number>;
// thunk 0x14245b3e0: Instances::fl_events::PressAndTapGestureEvent::tapStageXGet
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 4, Value::Number>;
// thunk 0x14245b450: Instances::fl_events::PressAndTapGestureEvent::tapStageYGet
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 5, Value::Number>;
// thunk 0x14245b620: Instances::fl_events::PressAndTapGestureEvent::clone
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 6, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245b6d0: Instances::fl_events::PressAndTapGestureEvent::toString
template struct ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 7, ASString>;
// thunk 0x14245b740: Instances::fl_events::Event::bubblesGet
template struct ThunkFunc0<Instances::fl_events::Event, 0, bool>;
// thunk 0x14245b7a0: Instances::fl_events::Event::cancelableGet
template struct ThunkFunc0<Instances::fl_events::Event, 1, bool>;
// thunk 0x14245b800: Instances::fl_events::Event::currentTargetGet
template struct ThunkFunc0<Instances::fl_events::Event, 2, SPtr<Instances::fl::Object>>;
// thunk 0x14245b910: Instances::fl_events::Event::eventPhaseGet
template struct ThunkFunc0<Instances::fl_events::Event, 3, UInt32>;
// thunk 0x14245b970: Instances::fl_events::Event::targetGet
template struct ThunkFunc0<Instances::fl_events::Event, 4, SPtr<Instances::fl::Object>>;
// thunk 0x14245ba20: Instances::fl_events::Event::typeGet
template struct ThunkFunc0<Instances::fl_events::Event, 5, ASString>;
// thunk 0x14245ba90: Instances::fl_events::Event::clone
template struct ThunkFunc0<Instances::fl_events::Event, 6, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245bb40: Instances::fl_events::Event::formatToString
template struct ThunkFunc2<Instances::fl_events::Event, 7, Value, unsigned, const Value*>;
// thunk 0x14245bb60: Instances::fl_events::TouchEvent::altKeyGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 0, bool>;
// thunk 0x14245bbc0: Instances::fl_events::Event::isDefaultPrevented
template struct ThunkFunc0<Instances::fl_events::Event, 8, bool>;
// thunk 0x14245bc20: Instances::fl_events::TouchEvent::altKeySet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 1, const Value, bool>;
// thunk 0x14245bc80: Instances::fl_events::Event::preventDefault
template struct ThunkFunc0<Instances::fl_events::Event, 9, const Value>;
// thunk 0x14245bca0: Instances::fl_events::TouchEvent::commandKeyGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 2, bool>;
// thunk 0x14245bd00: Instances::fl_events::Event::stopImmediatePropagation
template struct ThunkFunc0<Instances::fl_events::Event, 10, const Value>;
// thunk 0x14245be80: Instances::fl_events::TouchEvent::commandKeySet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 3, const Value, bool>;
// thunk 0x14245bee0: Instances::fl_events::Event::stopPropagation
template struct ThunkFunc0<Instances::fl_events::Event, 11, const Value>;
// thunk 0x14245bf00: Instances::fl_events::TouchEvent::controlKeyGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 4, bool>;
// thunk 0x14245bf60: Instances::fl_events::Event::toString
template struct ThunkFunc0<Instances::fl_events::Event, 12, ASString>;
// thunk 0x14245bfd0: Instances::fl_events::TouchEvent::controlKeySet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 5, const Value, bool>;
// thunk 0x14245c030: Instances::fl_events::TouchEvent::ctrlKeyGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 6, bool>;
// thunk 0x14245c090: Instances::fl_events::TouchEvent::ctrlKeySet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 7, const Value, bool>;
// thunk 0x14245c0f0: Instances::fl_events::TouchEvent::isPrimaryTouchPointGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 8, bool>;
// thunk 0x14245c150: Instances::fl_events::TouchEvent::isPrimaryTouchPointSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 9, const Value, bool>;
// thunk 0x14245c1b0: Instances::fl_events::TouchEvent::isRelatedObjectInaccessibleGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 10, bool>;
// thunk 0x14245c210: Instances::fl_events::TouchEvent::isRelatedObjectInaccessibleSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 11, const Value, bool>;
// thunk 0x14245c270: Instances::fl_events::TouchEvent::localXGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 12, Value::Number>;
// thunk 0x14245c2e0: Instances::fl_events::TouchEvent::localXSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 13, const Value, Value::Number>;
// thunk 0x14245c370: Instances::fl_events::TouchEvent::localYGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 14, Value::Number>;
// thunk 0x14245c3e0: Instances::fl_events::TouchEvent::localYSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 15, const Value, Value::Number>;
// thunk 0x14245c470: Instances::fl_events::TouchEvent::pressureGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 16, Value::Number>;
// thunk 0x14245c4e0: Instances::fl_events::TouchEvent::pressureSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 17, const Value, Value::Number>;
// thunk 0x14245c570: Instances::fl_events::TouchEvent::relatedObjectGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 18, SPtr<Instances::fl_display::InteractiveObject>>;
// thunk 0x14245c620: Instances::fl_events::TouchEvent::relatedObjectSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 19, const Value, Instances::fl_display::InteractiveObject*>;
// thunk 0x14245c660: Instances::fl_events::TouchEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 20, bool>;
// thunk 0x14245c6c0: Instances::fl_events::TouchEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 21, const Value, bool>;
// thunk 0x14245c720: Instances::fl_events::TouchEvent::sizeXGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 22, Value::Number>;
// thunk 0x14245c790: Instances::fl_events::TouchEvent::sizeXSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 23, const Value, Value::Number>;
// thunk 0x14245c820: Instances::fl_events::TouchEvent::sizeYGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 24, Value::Number>;
// thunk 0x14245c890: Instances::fl_events::TouchEvent::sizeYSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 25, const Value, Value::Number>;
// thunk 0x14245c920: Instances::fl_events::TouchEvent::stageXGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 26, Value::Number>;
// thunk 0x14245c990: Instances::fl_events::TouchEvent::stageYGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 27, Value::Number>;
// thunk 0x14245ca00: Instances::fl_events::TouchEvent::touchPointIDGet
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 28, SInt32>;
// thunk 0x14245ca60: Instances::fl_events::TouchEvent::touchPointIDSet
template struct ThunkFunc1<Instances::fl_events::TouchEvent, 29, const Value, SInt32>;
// thunk 0x14245cad0: Instances::fl_events::TouchEvent::clone
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 30, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245cb80: Instances::fl_events::TouchEvent::toString
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 31, ASString>;
// thunk 0x14245cbf0: Instances::fl_events::TouchEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::TouchEvent, 32, const Value>;
// thunk 0x14245d000: Instances::fl_events::IMEEvent::clone
template struct ThunkFunc0<Instances::fl_events::IMEEvent, 0, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245d0b0: Instances::fl_events::IMEEvent::toString
template struct ThunkFunc0<Instances::fl_events::IMEEvent, 1, ASString>;
// thunk 0x14245d4b0: Instances::fl_events::IOErrorEvent::textGet
template struct ThunkFunc0<Instances::fl_events::IOErrorEvent, 0, ASString>;
// thunk 0x14245d520: Instances::fl_events::AppLifecycleEvent::statusGet
template struct ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 0, SPtr<Instances::fl::Object>>;
// thunk 0x14245d5d0: Instances::fl_events::IOErrorEvent::textSet
template struct ThunkFunc1<Instances::fl_events::IOErrorEvent, 1, const Value, const ASString&>;
// thunk 0x14245d6d0: Instances::fl_events::AppLifecycleEvent::clone
template struct ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 1, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245d780: Instances::fl_events::IOErrorEvent::clone
template struct ThunkFunc0<Instances::fl_events::IOErrorEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245d830: Instances::fl_events::AppLifecycleEvent::toString
template struct ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 2, ASString>;
// thunk 0x14245d8a0: Instances::fl_events::IOErrorEvent::toString
template struct ThunkFunc0<Instances::fl_events::IOErrorEvent, 3, ASString>;
// thunk 0x14245d910: Instances::fl_events::KeyboardEvent::altKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 0, bool>;
// thunk 0x14245d970: Instances::fl_events::KeyboardEvent::altKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 1, const Value, bool>;
// thunk 0x14245d9d0: Instances::fl_events::KeyboardEvent::charCodeGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 2, UInt32>;
// thunk 0x14245dbe0: Instances::fl_events::KeyboardEvent::charCodeSet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 3, const Value, UInt32>;
// thunk 0x14245dc50: Instances::fl_events::KeyboardEvent::commandKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 4, bool>;
// thunk 0x14245de10: Instances::fl_events::KeyboardEvent::commandKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 5, const Value, bool>;
// thunk 0x14245de70: Instances::fl_events::KeyboardEvent::controlKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 6, bool>;
// thunk 0x14245ded0: Instances::fl_events::StageOrientationEvent::afterOrientationGet
template struct ThunkFunc0<Instances::fl_events::StageOrientationEvent, 0, ASString>;
// thunk 0x14245df40: Instances::fl_events::KeyboardEvent::controlKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 7, const Value, bool>;
// thunk 0x14245dfa0: Instances::fl_events::StageOrientationEvent::beforeOrientationGet
template struct ThunkFunc0<Instances::fl_events::StageOrientationEvent, 1, ASString>;
// thunk 0x14245e010: Instances::fl_events::KeyboardEvent::ctrlKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 8, bool>;
// thunk 0x14245e070: Instances::fl_events::StageOrientationEvent::clone
template struct ThunkFunc0<Instances::fl_events::StageOrientationEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x14245e120: Instances::fl_events::KeyboardEvent::ctrlKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 9, const Value, bool>;
// thunk 0x14245e180: Instances::fl_events::StageOrientationEvent::toString
template struct ThunkFunc0<Instances::fl_events::StageOrientationEvent, 3, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc5@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@AEBV7456@_NJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458c10
// MS2-PIN: ?Func@?$ThunkFunc1@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$00_NPEAVEvent@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458eb0
// MS2-PIN: ?Func@?$ThunkFunc1@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458f50
// MS2-PIN: ?Func@?$ThunkFunc3@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBVASString@56@AEBV7456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459090
// MS2-PIN: ?Func@?$ThunkFunc1@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$03_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459400
// MS2-PIN: ?Func@?$ThunkFunc0@VTimerEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459540
// MS2-PIN: ?Func@?$ThunkFunc0@VTimerEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424595f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTimerEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459660
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459680
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424596e0
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459740
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424597a0
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459800
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459860
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424598c0
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459a70
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459ad0
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459b40
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459bd0
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459c40
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459cd0
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459d40
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459e40
// MS2-PIN: ?Func@?$ThunkFunc1@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459ea0
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459f00
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459f70
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142459fe0
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BD@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a090
// MS2-PIN: ?Func@?$ThunkFunc0@VGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a100
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a270
// MS2-PIN: ?Func@?$ThunkFunc1@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a2e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a370
// MS2-PIN: ?Func@?$ThunkFunc1@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a3e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a470
// MS2-PIN: ?Func@?$ThunkFunc1@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a4e0
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a570
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a5e0
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a650
// MS2-PIN: ?Func@?$ThunkFunc1@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a750
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a7e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a840
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a8b0
// MS2-PIN: ?Func@?$ThunkFunc1@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a920
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245a9b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245aa60
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAVInteractiveObject@fl_display@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ab10
// MS2-PIN: ?Func@?$ThunkFunc0@VTransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ab50
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245abc0
// MS2-PIN: ?Func@?$ThunkFunc1@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ac20
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ac80
// MS2-PIN: ?Func@?$ThunkFunc0@VFocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ad30
// MS2-PIN: ?Func@?$ThunkFunc0@VErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245af00
// MS2-PIN: ?Func@?$ThunkFunc0@VErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245af60
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b010
// MS2-PIN: ?Func@?$ThunkFunc0@VErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b080
// MS2-PIN: ?Func@?$ThunkFunc1@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b0f0
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b2e0
// MS2-PIN: ?Func@?$ThunkFunc1@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b350
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b3e0
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b450
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b620
// MS2-PIN: ?Func@?$ThunkFunc0@VPressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b6d0
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b740
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b7a0
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b800
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b910
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245b970
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ba20
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ba90
// MS2-PIN: ?Func@?$ThunkFunc2@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bb40
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bb60
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bbc0
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bc20
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bc80
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bca0
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bd00
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245be80
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bee0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bf00
// MS2-PIN: ?Func@?$ThunkFunc0@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bf60
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245bfd0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c030
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c090
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c0f0
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c150
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c1b0
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c210
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c270
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c2e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c370
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c3e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c470
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c4e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c570
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@PEAVInteractiveObject@fl_display@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c620
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BE@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c660
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c6c0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BG@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c720
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c790
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BI@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c820
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c890
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BK@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c920
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BL@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245c990
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BM@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ca00
// MS2-PIN: ?Func@?$ThunkFunc1@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BN@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ca60
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BO@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245cad0
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BP@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245cb80
// MS2-PIN: ?Func@?$ThunkFunc0@VTouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0CA@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245cbf0
// MS2-PIN: ?Func@?$ThunkFunc0@VIMEEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d000
// MS2-PIN: ?Func@?$ThunkFunc0@VIMEEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d0b0
// MS2-PIN: ?Func@?$ThunkFunc0@VIOErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d4b0
// MS2-PIN: ?Func@?$ThunkFunc0@VAppLifecycleEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d520
// MS2-PIN: ?Func@?$ThunkFunc1@VIOErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d5d0
// MS2-PIN: ?Func@?$ThunkFunc0@VAppLifecycleEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d6d0
// MS2-PIN: ?Func@?$ThunkFunc0@VIOErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d780
// MS2-PIN: ?Func@?$ThunkFunc0@VAppLifecycleEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d830
// MS2-PIN: ?Func@?$ThunkFunc0@VIOErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d8a0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d910
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d970
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245d9d0
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245dbe0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245dc50
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245de10
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245de70
// MS2-PIN: ?Func@?$ThunkFunc0@VStageOrientationEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245ded0
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245df40
// MS2-PIN: ?Func@?$ThunkFunc0@VStageOrientationEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245dfa0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245e010
// MS2-PIN: ?Func@?$ThunkFunc0@VStageOrientationEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245e070
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245e120
// MS2-PIN: ?Func@?$ThunkFunc0@VStageOrientationEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14245e180
