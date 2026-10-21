// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the dynamic initializers of
// the native method member pointers ThunkFuncN<T, N, R, A...>::Method (0x140142910-0x140146150): each stores
// {method, 0} (16 bytes, the general member-pointer representation of as3_marshalling.h). The thunks that call
// through them are in the sfr_as3_* units. Our own source, written from the exe (work/sfr5/gen_natives.py).
// MS2-UNIT: sfr_as3di_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140142910-0x140146150 .text$di
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

typedef ThunkFunc0<Instances::fl_events::MouseEvent, 23, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_MouseEvent_clone;
// @0x140142910
template <> const TFunc_Instances_fl_events_MouseEvent_clone::TMethod TFunc_Instances_fl_events_MouseEvent_clone::Method = &Instances::fl_events::MouseEvent::clone;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 24, ASString> TFunc_Instances_fl_events_MouseEvent_toString;
// @0x140142940
template <> const TFunc_Instances_fl_events_MouseEvent_toString::TMethod TFunc_Instances_fl_events_MouseEvent_toString::Method = &Instances::fl_events::MouseEvent::toString;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 25, const Value> TFunc_Instances_fl_events_MouseEvent_updateAfterEvent;
// @0x140142970
template <> const TFunc_Instances_fl_events_MouseEvent_updateAfterEvent::TMethod TFunc_Instances_fl_events_MouseEvent_updateAfterEvent::Method = &Instances::fl_events::MouseEvent::updateAfterEvent;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 11, SInt32> TFunc_Instances_fl_events_MouseEvent_deltaGet;
// @0x1401429a0
template <> const TFunc_Instances_fl_events_MouseEvent_deltaGet::TMethod TFunc_Instances_fl_events_MouseEvent_deltaGet::Method = &Instances::fl_events::MouseEvent::deltaGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 13, Value::Number> TFunc_Instances_fl_events_MouseEvent_localXGet;
// @0x1401429d0
template <> const TFunc_Instances_fl_events_MouseEvent_localXGet::TMethod TFunc_Instances_fl_events_MouseEvent_localXGet::Method = &Instances::fl_events::MouseEvent::localXGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 15, Value::Number> TFunc_Instances_fl_events_MouseEvent_localYGet;
// @0x140142a00
template <> const TFunc_Instances_fl_events_MouseEvent_localYGet::TMethod TFunc_Instances_fl_events_MouseEvent_localYGet::Method = &Instances::fl_events::MouseEvent::localYGet;
typedef ThunkFunc0<Instances::fl_events::NetStatusEvent, 2, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_NetStatusEvent_clone;
// @0x140142a30
template <> const TFunc_Instances_fl_events_NetStatusEvent_clone::TMethod TFunc_Instances_fl_events_NetStatusEvent_clone::Method = &Instances::fl_events::NetStatusEvent::clone;
typedef ThunkFunc0<Instances::fl_events::NetStatusEvent, 3, ASString> TFunc_Instances_fl_events_NetStatusEvent_toString;
// @0x140142a60
template <> const TFunc_Instances_fl_events_NetStatusEvent_toString::TMethod TFunc_Instances_fl_events_NetStatusEvent_toString::Method = &Instances::fl_events::NetStatusEvent::toString;
typedef ThunkFunc0<Instances::fl_events::NetStatusEvent, 0, SPtr<Instances::fl::Object>> TFunc_Instances_fl_events_NetStatusEvent_infoGet;
// @0x140142a90
template <> const TFunc_Instances_fl_events_NetStatusEvent_infoGet::TMethod TFunc_Instances_fl_events_NetStatusEvent_infoGet::Method = &Instances::fl_events::NetStatusEvent::infoGet;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 2, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYGet;
// @0x140142ac0
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYGet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYGet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapLocalYGet;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 4, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageXGet;
// @0x140142af0
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageXGet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageXGet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapStageXGet;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 5, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageYGet;
// @0x140142b20
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageYGet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapStageYGet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapStageYGet;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 6, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_PressAndTapGestureEvent_clone;
// @0x140142b50
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_clone::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_clone::Method = &Instances::fl_events::PressAndTapGestureEvent::clone;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 7, ASString> TFunc_Instances_fl_events_PressAndTapGestureEvent_toString;
// @0x140142b80
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_toString::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_toString::Method = &Instances::fl_events::PressAndTapGestureEvent::toString;
typedef ThunkFunc0<Instances::fl_events::PressAndTapGestureEvent, 0, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXGet;
// @0x140142bb0
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXGet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXGet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapLocalXGet;
typedef ThunkFunc0<Instances::fl_events::ProgressEvent, 2, Value::Number> TFunc_Instances_fl_events_ProgressEvent_bytesTotalGet;
// @0x140142be0
template <> const TFunc_Instances_fl_events_ProgressEvent_bytesTotalGet::TMethod TFunc_Instances_fl_events_ProgressEvent_bytesTotalGet::Method = &Instances::fl_events::ProgressEvent::bytesTotalGet;
typedef ThunkFunc0<Instances::fl_events::ProgressEvent, 4, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_ProgressEvent_clone;
// @0x140142c10
template <> const TFunc_Instances_fl_events_ProgressEvent_clone::TMethod TFunc_Instances_fl_events_ProgressEvent_clone::Method = &Instances::fl_events::ProgressEvent::clone;
typedef ThunkFunc0<Instances::fl_events::ProgressEvent, 5, ASString> TFunc_Instances_fl_events_ProgressEvent_toString;
// @0x140142c40
template <> const TFunc_Instances_fl_events_ProgressEvent_toString::TMethod TFunc_Instances_fl_events_ProgressEvent_toString::Method = &Instances::fl_events::ProgressEvent::toString;
typedef ThunkFunc0<Instances::fl_events::ProgressEvent, 0, Value::Number> TFunc_Instances_fl_events_ProgressEvent_bytesLoadedGet;
// @0x140142c70
template <> const TFunc_Instances_fl_events_ProgressEvent_bytesLoadedGet::TMethod TFunc_Instances_fl_events_ProgressEvent_bytesLoadedGet::Method = &Instances::fl_events::ProgressEvent::bytesLoadedGet;
typedef ThunkFunc0<Instances::fl_events::StageOrientationEvent, 1, ASString> TFunc_Instances_fl_events_StageOrientationEvent_beforeOrientationGet;
// @0x140142ca0
template <> const TFunc_Instances_fl_events_StageOrientationEvent_beforeOrientationGet::TMethod TFunc_Instances_fl_events_StageOrientationEvent_beforeOrientationGet::Method = &Instances::fl_events::StageOrientationEvent::beforeOrientationGet;
typedef ThunkFunc0<Instances::fl_events::StageOrientationEvent, 2, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_StageOrientationEvent_clone;
// @0x140142cd0
template <> const TFunc_Instances_fl_events_StageOrientationEvent_clone::TMethod TFunc_Instances_fl_events_StageOrientationEvent_clone::Method = &Instances::fl_events::StageOrientationEvent::clone;
typedef ThunkFunc0<Instances::fl_events::StageOrientationEvent, 3, ASString> TFunc_Instances_fl_events_StageOrientationEvent_toString;
// @0x140142d00
template <> const TFunc_Instances_fl_events_StageOrientationEvent_toString::TMethod TFunc_Instances_fl_events_StageOrientationEvent_toString::Method = &Instances::fl_events::StageOrientationEvent::toString;
typedef ThunkFunc0<Instances::fl_events::StageOrientationEvent, 0, ASString> TFunc_Instances_fl_events_StageOrientationEvent_afterOrientationGet;
// @0x140142d30
template <> const TFunc_Instances_fl_events_StageOrientationEvent_afterOrientationGet::TMethod TFunc_Instances_fl_events_StageOrientationEvent_afterOrientationGet::Method = &Instances::fl_events::StageOrientationEvent::afterOrientationGet;
typedef ThunkFunc0<Instances::fl_events::TextEvent, 2, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_TextEvent_clone;
// @0x140142d60
template <> const TFunc_Instances_fl_events_TextEvent_clone::TMethod TFunc_Instances_fl_events_TextEvent_clone::Method = &Instances::fl_events::TextEvent::clone;
typedef ThunkFunc0<Instances::fl_events::TextEvent, 3, ASString> TFunc_Instances_fl_events_TextEvent_toString;
// @0x140142d90
template <> const TFunc_Instances_fl_events_TextEvent_toString::TMethod TFunc_Instances_fl_events_TextEvent_toString::Method = &Instances::fl_events::TextEvent::toString;
typedef ThunkFunc0<Instances::fl_events::TextEvent, 0, ASString> TFunc_Instances_fl_events_TextEvent_textGet;
// @0x140142dc0
template <> const TFunc_Instances_fl_events_TextEvent_textGet::TMethod TFunc_Instances_fl_events_TextEvent_textGet::Method = &Instances::fl_events::TextEvent::textGet;
typedef ThunkFunc0<Instances::fl_events::TimerEvent, 1, ASString> TFunc_Instances_fl_events_TimerEvent_toString;
// @0x140142df0
template <> const TFunc_Instances_fl_events_TimerEvent_toString::TMethod TFunc_Instances_fl_events_TimerEvent_toString::Method = &Instances::fl_events::TimerEvent::toString;
typedef ThunkFunc0<Instances::fl_events::TimerEvent, 2, const Value> TFunc_Instances_fl_events_TimerEvent_updateAfterEvent;
// @0x140142e20
template <> const TFunc_Instances_fl_events_TimerEvent_updateAfterEvent::TMethod TFunc_Instances_fl_events_TimerEvent_updateAfterEvent::Method = &Instances::fl_events::TimerEvent::updateAfterEvent;
typedef ThunkFunc0<Instances::fl_events::TimerEvent, 0, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_TimerEvent_clone;
// @0x140142e50
template <> const TFunc_Instances_fl_events_TimerEvent_clone::TMethod TFunc_Instances_fl_events_TimerEvent_clone::Method = &Instances::fl_events::TimerEvent::clone;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 2, bool> TFunc_Instances_fl_events_TouchEvent_commandKeyGet;
// @0x140142e80
template <> const TFunc_Instances_fl_events_TouchEvent_commandKeyGet::TMethod TFunc_Instances_fl_events_TouchEvent_commandKeyGet::Method = &Instances::fl_events::TouchEvent::commandKeyGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 4, bool> TFunc_Instances_fl_events_TouchEvent_controlKeyGet;
// @0x140142eb0
template <> const TFunc_Instances_fl_events_TouchEvent_controlKeyGet::TMethod TFunc_Instances_fl_events_TouchEvent_controlKeyGet::Method = &Instances::fl_events::TouchEvent::controlKeyGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 6, bool> TFunc_Instances_fl_events_TouchEvent_ctrlKeyGet;
// @0x140142ee0
template <> const TFunc_Instances_fl_events_TouchEvent_ctrlKeyGet::TMethod TFunc_Instances_fl_events_TouchEvent_ctrlKeyGet::Method = &Instances::fl_events::TouchEvent::ctrlKeyGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 8, bool> TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointGet;
// @0x140142f10
template <> const TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointGet::TMethod TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointGet::Method = &Instances::fl_events::TouchEvent::isPrimaryTouchPointGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 10, bool> TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleGet;
// @0x140142f40
template <> const TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleGet::TMethod TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleGet::Method = &Instances::fl_events::TouchEvent::isRelatedObjectInaccessibleGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 0, bool> TFunc_Instances_fl_events_TouchEvent_altKeyGet;
// @0x140142f70
template <> const TFunc_Instances_fl_events_TouchEvent_altKeyGet::TMethod TFunc_Instances_fl_events_TouchEvent_altKeyGet::Method = &Instances::fl_events::TouchEvent::altKeyGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 16, Value::Number> TFunc_Instances_fl_events_TouchEvent_pressureGet;
// @0x140142fa0
template <> const TFunc_Instances_fl_events_TouchEvent_pressureGet::TMethod TFunc_Instances_fl_events_TouchEvent_pressureGet::Method = &Instances::fl_events::TouchEvent::pressureGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 18, SPtr<Instances::fl_display::InteractiveObject>> TFunc_Instances_fl_events_TouchEvent_relatedObjectGet;
// @0x140142fd0
template <> const TFunc_Instances_fl_events_TouchEvent_relatedObjectGet::TMethod TFunc_Instances_fl_events_TouchEvent_relatedObjectGet::Method = &Instances::fl_events::TouchEvent::relatedObjectGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 20, bool> TFunc_Instances_fl_events_TouchEvent_shiftKeyGet;
// @0x140143000
template <> const TFunc_Instances_fl_events_TouchEvent_shiftKeyGet::TMethod TFunc_Instances_fl_events_TouchEvent_shiftKeyGet::Method = &Instances::fl_events::TouchEvent::shiftKeyGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 22, Value::Number> TFunc_Instances_fl_events_TouchEvent_sizeXGet;
// @0x140143030
template <> const TFunc_Instances_fl_events_TouchEvent_sizeXGet::TMethod TFunc_Instances_fl_events_TouchEvent_sizeXGet::Method = &Instances::fl_events::TouchEvent::sizeXGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 24, Value::Number> TFunc_Instances_fl_events_TouchEvent_sizeYGet;
// @0x140143060
template <> const TFunc_Instances_fl_events_TouchEvent_sizeYGet::TMethod TFunc_Instances_fl_events_TouchEvent_sizeYGet::Method = &Instances::fl_events::TouchEvent::sizeYGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 26, Value::Number> TFunc_Instances_fl_events_TouchEvent_stageXGet;
// @0x140143090
template <> const TFunc_Instances_fl_events_TouchEvent_stageXGet::TMethod TFunc_Instances_fl_events_TouchEvent_stageXGet::Method = &Instances::fl_events::TouchEvent::stageXGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 27, Value::Number> TFunc_Instances_fl_events_TouchEvent_stageYGet;
// @0x1401430c0
template <> const TFunc_Instances_fl_events_TouchEvent_stageYGet::TMethod TFunc_Instances_fl_events_TouchEvent_stageYGet::Method = &Instances::fl_events::TouchEvent::stageYGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 28, SInt32> TFunc_Instances_fl_events_TouchEvent_touchPointIDGet;
// @0x1401430f0
template <> const TFunc_Instances_fl_events_TouchEvent_touchPointIDGet::TMethod TFunc_Instances_fl_events_TouchEvent_touchPointIDGet::Method = &Instances::fl_events::TouchEvent::touchPointIDGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 30, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_TouchEvent_clone;
// @0x140143120
template <> const TFunc_Instances_fl_events_TouchEvent_clone::TMethod TFunc_Instances_fl_events_TouchEvent_clone::Method = &Instances::fl_events::TouchEvent::clone;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 31, ASString> TFunc_Instances_fl_events_TouchEvent_toString;
// @0x140143150
template <> const TFunc_Instances_fl_events_TouchEvent_toString::TMethod TFunc_Instances_fl_events_TouchEvent_toString::Method = &Instances::fl_events::TouchEvent::toString;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 32, const Value> TFunc_Instances_fl_events_TouchEvent_updateAfterEvent;
// @0x140143180
template <> const TFunc_Instances_fl_events_TouchEvent_updateAfterEvent::TMethod TFunc_Instances_fl_events_TouchEvent_updateAfterEvent::Method = &Instances::fl_events::TouchEvent::updateAfterEvent;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 12, Value::Number> TFunc_Instances_fl_events_TouchEvent_localXGet;
// @0x1401431b0
template <> const TFunc_Instances_fl_events_TouchEvent_localXGet::TMethod TFunc_Instances_fl_events_TouchEvent_localXGet::Method = &Instances::fl_events::TouchEvent::localXGet;
typedef ThunkFunc0<Instances::fl_events::TouchEvent, 14, Value::Number> TFunc_Instances_fl_events_TouchEvent_localYGet;
// @0x1401431e0
template <> const TFunc_Instances_fl_events_TouchEvent_localYGet::TMethod TFunc_Instances_fl_events_TouchEvent_localYGet::Method = &Instances::fl_events::TouchEvent::localYGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 2, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_offsetYGet;
// @0x140143210
template <> const TFunc_Instances_fl_events_TransformGestureEvent_offsetYGet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_offsetYGet::Method = &Instances::fl_events::TransformGestureEvent::offsetYGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 4, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_rotationGet;
// @0x140143240
template <> const TFunc_Instances_fl_events_TransformGestureEvent_rotationGet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_rotationGet::Method = &Instances::fl_events::TransformGestureEvent::rotationGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 6, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_scaleXGet;
// @0x140143270
template <> const TFunc_Instances_fl_events_TransformGestureEvent_scaleXGet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_scaleXGet::Method = &Instances::fl_events::TransformGestureEvent::scaleXGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 8, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_scaleYGet;
// @0x1401432a0
template <> const TFunc_Instances_fl_events_TransformGestureEvent_scaleYGet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_scaleYGet::Method = &Instances::fl_events::TransformGestureEvent::scaleYGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 10, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_TransformGestureEvent_clone;
// @0x1401432d0
template <> const TFunc_Instances_fl_events_TransformGestureEvent_clone::TMethod TFunc_Instances_fl_events_TransformGestureEvent_clone::Method = &Instances::fl_events::TransformGestureEvent::clone;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 0, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_offsetXGet;
// @0x140143300
template <> const TFunc_Instances_fl_events_TransformGestureEvent_offsetXGet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_offsetXGet::Method = &Instances::fl_events::TransformGestureEvent::offsetXGet;
typedef ThunkFunc0<Instances::fl_events::TransformGestureEvent, 11, ASString> TFunc_Instances_fl_events_TransformGestureEvent_toString;
// @0x140143330
template <> const TFunc_Instances_fl_events_TransformGestureEvent_toString::TMethod TFunc_Instances_fl_events_TransformGestureEvent_toString::Method = &Instances::fl_events::TransformGestureEvent::toString;
typedef ThunkFunc1<Instances::fl_events::EventDispatcher, 1, bool, Instances::fl_events::Event*> TFunc_Instances_fl_events_EventDispatcher_dispatchEvent;
// @0x140143360
template <> const TFunc_Instances_fl_events_EventDispatcher_dispatchEvent::TMethod TFunc_Instances_fl_events_EventDispatcher_dispatchEvent::Method = &Instances::fl_events::EventDispatcher::dispatchEvent;
typedef ThunkFunc1<Instances::fl_events::EventDispatcher, 2, bool, const ASString&> TFunc_Instances_fl_events_EventDispatcher_hasEventListener;
// @0x140143390
template <> const TFunc_Instances_fl_events_EventDispatcher_hasEventListener::TMethod TFunc_Instances_fl_events_EventDispatcher_hasEventListener::Method = &Instances::fl_events::EventDispatcher::hasEventListener;
typedef ThunkFunc1<Instances::fl_events::EventDispatcher, 4, bool, const ASString&> TFunc_Instances_fl_events_EventDispatcher_willTrigger;
// @0x1401433c0
template <> const TFunc_Instances_fl_events_EventDispatcher_willTrigger::TMethod TFunc_Instances_fl_events_EventDispatcher_willTrigger::Method = &Instances::fl_events::EventDispatcher::willTrigger;
typedef ThunkFunc1<Instances::fl_events::FocusEvent, 1, const Value, const ASString&> TFunc_Instances_fl_events_FocusEvent_directionSet;
// @0x1401433f0
template <> const TFunc_Instances_fl_events_FocusEvent_directionSet::TMethod TFunc_Instances_fl_events_FocusEvent_directionSet::Method = &Instances::fl_events::FocusEvent::directionSet;
typedef ThunkFunc1<Instances::fl_events::FocusEvent, 3, const Value, UInt32> TFunc_Instances_fl_events_FocusEvent_keyCodeSet;
// @0x140143420
template <> const TFunc_Instances_fl_events_FocusEvent_keyCodeSet::TMethod TFunc_Instances_fl_events_FocusEvent_keyCodeSet::Method = &Instances::fl_events::FocusEvent::keyCodeSet;
typedef ThunkFunc1<Instances::fl_events::FocusEvent, 5, const Value, Instances::fl_display::InteractiveObject*> TFunc_Instances_fl_events_FocusEvent_relatedObjectSet;
// @0x140143450
template <> const TFunc_Instances_fl_events_FocusEvent_relatedObjectSet::TMethod TFunc_Instances_fl_events_FocusEvent_relatedObjectSet::Method = &Instances::fl_events::FocusEvent::relatedObjectSet;
typedef ThunkFunc1<Instances::fl_events::FocusEvent, 7, const Value, bool> TFunc_Instances_fl_events_FocusEvent_shiftKeySet;
// @0x140143480
template <> const TFunc_Instances_fl_events_FocusEvent_shiftKeySet::TMethod TFunc_Instances_fl_events_FocusEvent_shiftKeySet::Method = &Instances::fl_events::FocusEvent::shiftKeySet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 1, const Value, bool> TFunc_Instances_fl_events_GestureEvent_altKeySet;
// @0x1401434b0
template <> const TFunc_Instances_fl_events_GestureEvent_altKeySet::TMethod TFunc_Instances_fl_events_GestureEvent_altKeySet::Method = &Instances::fl_events::GestureEvent::altKeySet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 3, const Value, bool> TFunc_Instances_fl_events_GestureEvent_commandKeySet;
// @0x1401434e0
template <> const TFunc_Instances_fl_events_GestureEvent_commandKeySet::TMethod TFunc_Instances_fl_events_GestureEvent_commandKeySet::Method = &Instances::fl_events::GestureEvent::commandKeySet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 5, const Value, bool> TFunc_Instances_fl_events_GestureEvent_controlKeySet;
// @0x140143510
template <> const TFunc_Instances_fl_events_GestureEvent_controlKeySet::TMethod TFunc_Instances_fl_events_GestureEvent_controlKeySet::Method = &Instances::fl_events::GestureEvent::controlKeySet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 7, const Value, bool> TFunc_Instances_fl_events_GestureEvent_ctrlKeySet;
// @0x140143540
template <> const TFunc_Instances_fl_events_GestureEvent_ctrlKeySet::TMethod TFunc_Instances_fl_events_GestureEvent_ctrlKeySet::Method = &Instances::fl_events::GestureEvent::ctrlKeySet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 9, const Value, Value::Number> TFunc_Instances_fl_events_GestureEvent_localXSet;
// @0x140143570
template <> const TFunc_Instances_fl_events_GestureEvent_localXSet::TMethod TFunc_Instances_fl_events_GestureEvent_localXSet::Method = &Instances::fl_events::GestureEvent::localXSet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 11, const Value, Value::Number> TFunc_Instances_fl_events_GestureEvent_localYSet;
// @0x1401435a0
template <> const TFunc_Instances_fl_events_GestureEvent_localYSet::TMethod TFunc_Instances_fl_events_GestureEvent_localYSet::Method = &Instances::fl_events::GestureEvent::localYSet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 13, const Value, const ASString&> TFunc_Instances_fl_events_GestureEvent_phaseSet;
// @0x1401435d0
template <> const TFunc_Instances_fl_events_GestureEvent_phaseSet::TMethod TFunc_Instances_fl_events_GestureEvent_phaseSet::Method = &Instances::fl_events::GestureEvent::phaseSet;
typedef ThunkFunc1<Instances::fl_events::GestureEvent, 15, const Value, bool> TFunc_Instances_fl_events_GestureEvent_shiftKeySet;
// @0x140143600
template <> const TFunc_Instances_fl_events_GestureEvent_shiftKeySet::TMethod TFunc_Instances_fl_events_GestureEvent_shiftKeySet::Method = &Instances::fl_events::GestureEvent::shiftKeySet;
typedef ThunkFunc1<Instances::fl_events::IOErrorEvent, 1, const Value, const ASString&> TFunc_Instances_fl_events_IOErrorEvent_textSet;
// @0x140143630
template <> const TFunc_Instances_fl_events_IOErrorEvent_textSet::TMethod TFunc_Instances_fl_events_IOErrorEvent_textSet::Method = &Instances::fl_events::IOErrorEvent::textSet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 1, const Value, bool> TFunc_Instances_fl_events_KeyboardEvent_altKeySet;
// @0x140143660
template <> const TFunc_Instances_fl_events_KeyboardEvent_altKeySet::TMethod TFunc_Instances_fl_events_KeyboardEvent_altKeySet::Method = &Instances::fl_events::KeyboardEvent::altKeySet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 3, const Value, UInt32> TFunc_Instances_fl_events_KeyboardEvent_charCodeSet;
// @0x140143690
template <> const TFunc_Instances_fl_events_KeyboardEvent_charCodeSet::TMethod TFunc_Instances_fl_events_KeyboardEvent_charCodeSet::Method = &Instances::fl_events::KeyboardEvent::charCodeSet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 5, const Value, bool> TFunc_Instances_fl_events_KeyboardEvent_commandKeySet;
// @0x1401436c0
template <> const TFunc_Instances_fl_events_KeyboardEvent_commandKeySet::TMethod TFunc_Instances_fl_events_KeyboardEvent_commandKeySet::Method = &Instances::fl_events::KeyboardEvent::commandKeySet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 7, const Value, bool> TFunc_Instances_fl_events_KeyboardEvent_controlKeySet;
// @0x1401436f0
template <> const TFunc_Instances_fl_events_KeyboardEvent_controlKeySet::TMethod TFunc_Instances_fl_events_KeyboardEvent_controlKeySet::Method = &Instances::fl_events::KeyboardEvent::controlKeySet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 9, const Value, bool> TFunc_Instances_fl_events_KeyboardEvent_ctrlKeySet;
// @0x140143720
template <> const TFunc_Instances_fl_events_KeyboardEvent_ctrlKeySet::TMethod TFunc_Instances_fl_events_KeyboardEvent_ctrlKeySet::Method = &Instances::fl_events::KeyboardEvent::ctrlKeySet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 11, const Value, UInt32> TFunc_Instances_fl_events_KeyboardEvent_keyCodeSet;
// @0x140143750
template <> const TFunc_Instances_fl_events_KeyboardEvent_keyCodeSet::TMethod TFunc_Instances_fl_events_KeyboardEvent_keyCodeSet::Method = &Instances::fl_events::KeyboardEvent::keyCodeSet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 13, const Value, UInt32> TFunc_Instances_fl_events_KeyboardEvent_keyLocationSet;
// @0x140143780
template <> const TFunc_Instances_fl_events_KeyboardEvent_keyLocationSet::TMethod TFunc_Instances_fl_events_KeyboardEvent_keyLocationSet::Method = &Instances::fl_events::KeyboardEvent::keyLocationSet;
typedef ThunkFunc1<Instances::fl_events::KeyboardEvent, 15, const Value, bool> TFunc_Instances_fl_events_KeyboardEvent_shiftKeySet;
// @0x1401437b0
template <> const TFunc_Instances_fl_events_KeyboardEvent_shiftKeySet::TMethod TFunc_Instances_fl_events_KeyboardEvent_shiftKeySet::Method = &Instances::fl_events::KeyboardEvent::shiftKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 1, const Value, bool> TFunc_Instances_fl_events_MouseEvent_altKeySet;
// @0x1401437e0
template <> const TFunc_Instances_fl_events_MouseEvent_altKeySet::TMethod TFunc_Instances_fl_events_MouseEvent_altKeySet::Method = &Instances::fl_events::MouseEvent::altKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 3, const Value, bool> TFunc_Instances_fl_events_MouseEvent_buttonDownSet;
// @0x140143810
template <> const TFunc_Instances_fl_events_MouseEvent_buttonDownSet::TMethod TFunc_Instances_fl_events_MouseEvent_buttonDownSet::Method = &Instances::fl_events::MouseEvent::buttonDownSet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 6, const Value, bool> TFunc_Instances_fl_events_MouseEvent_commandKeySet;
// @0x140143840
template <> const TFunc_Instances_fl_events_MouseEvent_commandKeySet::TMethod TFunc_Instances_fl_events_MouseEvent_commandKeySet::Method = &Instances::fl_events::MouseEvent::commandKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 8, const Value, bool> TFunc_Instances_fl_events_MouseEvent_controlKeySet;
// @0x140143870
template <> const TFunc_Instances_fl_events_MouseEvent_controlKeySet::TMethod TFunc_Instances_fl_events_MouseEvent_controlKeySet::Method = &Instances::fl_events::MouseEvent::controlKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 10, const Value, bool> TFunc_Instances_fl_events_MouseEvent_ctrlKeySet;
// @0x1401438a0
template <> const TFunc_Instances_fl_events_MouseEvent_ctrlKeySet::TMethod TFunc_Instances_fl_events_MouseEvent_ctrlKeySet::Method = &Instances::fl_events::MouseEvent::ctrlKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 16, const Value, Value::Number> TFunc_Instances_fl_events_MouseEvent_localYSet;
// @0x1401438d0
template <> const TFunc_Instances_fl_events_MouseEvent_localYSet::TMethod TFunc_Instances_fl_events_MouseEvent_localYSet::Method = &Instances::fl_events::MouseEvent::localYSet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 18, const Value, Instances::fl_display::InteractiveObject*> TFunc_Instances_fl_events_MouseEvent_relatedObjectSet;
// @0x140143900
template <> const TFunc_Instances_fl_events_MouseEvent_relatedObjectSet::TMethod TFunc_Instances_fl_events_MouseEvent_relatedObjectSet::Method = &Instances::fl_events::MouseEvent::relatedObjectSet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 20, const Value, bool> TFunc_Instances_fl_events_MouseEvent_shiftKeySet;
// @0x140143930
template <> const TFunc_Instances_fl_events_MouseEvent_shiftKeySet::TMethod TFunc_Instances_fl_events_MouseEvent_shiftKeySet::Method = &Instances::fl_events::MouseEvent::shiftKeySet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 12, const Value, SInt32> TFunc_Instances_fl_events_MouseEvent_deltaSet;
// @0x140143960
template <> const TFunc_Instances_fl_events_MouseEvent_deltaSet::TMethod TFunc_Instances_fl_events_MouseEvent_deltaSet::Method = &Instances::fl_events::MouseEvent::deltaSet;
typedef ThunkFunc1<Instances::fl_events::MouseEvent, 14, const Value, Value::Number> TFunc_Instances_fl_events_MouseEvent_localXSet;
// @0x140143990
template <> const TFunc_Instances_fl_events_MouseEvent_localXSet::TMethod TFunc_Instances_fl_events_MouseEvent_localXSet::Method = &Instances::fl_events::MouseEvent::localXSet;
typedef ThunkFunc1<Instances::fl_events::NetStatusEvent, 1, const Value, const Value&> TFunc_Instances_fl_events_NetStatusEvent_infoSet;
// @0x1401439c0
template <> const TFunc_Instances_fl_events_NetStatusEvent_infoSet::TMethod TFunc_Instances_fl_events_NetStatusEvent_infoSet::Method = &Instances::fl_events::NetStatusEvent::infoSet;
typedef ThunkFunc1<Instances::fl_events::PressAndTapGestureEvent, 1, const Value, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXSet;
// @0x1401439f0
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXSet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalXSet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapLocalXSet;
typedef ThunkFunc1<Instances::fl_events::PressAndTapGestureEvent, 3, const Value, Value::Number> TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYSet;
// @0x140143a20
template <> const TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYSet::TMethod TFunc_Instances_fl_events_PressAndTapGestureEvent_tapLocalYSet::Method = &Instances::fl_events::PressAndTapGestureEvent::tapLocalYSet;
typedef ThunkFunc1<Instances::fl_events::ProgressEvent, 1, const Value, Value::Number> TFunc_Instances_fl_events_ProgressEvent_bytesLoadedSet;
// @0x140143a50
template <> const TFunc_Instances_fl_events_ProgressEvent_bytesLoadedSet::TMethod TFunc_Instances_fl_events_ProgressEvent_bytesLoadedSet::Method = &Instances::fl_events::ProgressEvent::bytesLoadedSet;
typedef ThunkFunc1<Instances::fl_events::ProgressEvent, 3, const Value, Value::Number> TFunc_Instances_fl_events_ProgressEvent_bytesTotalSet;
// @0x140143a80
template <> const TFunc_Instances_fl_events_ProgressEvent_bytesTotalSet::TMethod TFunc_Instances_fl_events_ProgressEvent_bytesTotalSet::Method = &Instances::fl_events::ProgressEvent::bytesTotalSet;
typedef ThunkFunc1<Instances::fl_events::TextEvent, 1, const Value, const ASString&> TFunc_Instances_fl_events_TextEvent_textSet;
// @0x140143ab0
template <> const TFunc_Instances_fl_events_TextEvent_textSet::TMethod TFunc_Instances_fl_events_TextEvent_textSet::Method = &Instances::fl_events::TextEvent::textSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 1, const Value, bool> TFunc_Instances_fl_events_TouchEvent_altKeySet;
// @0x140143ae0
template <> const TFunc_Instances_fl_events_TouchEvent_altKeySet::TMethod TFunc_Instances_fl_events_TouchEvent_altKeySet::Method = &Instances::fl_events::TouchEvent::altKeySet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 3, const Value, bool> TFunc_Instances_fl_events_TouchEvent_commandKeySet;
// @0x140143b10
template <> const TFunc_Instances_fl_events_TouchEvent_commandKeySet::TMethod TFunc_Instances_fl_events_TouchEvent_commandKeySet::Method = &Instances::fl_events::TouchEvent::commandKeySet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 5, const Value, bool> TFunc_Instances_fl_events_TouchEvent_controlKeySet;
// @0x140143b40
template <> const TFunc_Instances_fl_events_TouchEvent_controlKeySet::TMethod TFunc_Instances_fl_events_TouchEvent_controlKeySet::Method = &Instances::fl_events::TouchEvent::controlKeySet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 7, const Value, bool> TFunc_Instances_fl_events_TouchEvent_ctrlKeySet;
// @0x140143b70
template <> const TFunc_Instances_fl_events_TouchEvent_ctrlKeySet::TMethod TFunc_Instances_fl_events_TouchEvent_ctrlKeySet::Method = &Instances::fl_events::TouchEvent::ctrlKeySet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 9, const Value, bool> TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointSet;
// @0x140143ba0
template <> const TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointSet::TMethod TFunc_Instances_fl_events_TouchEvent_isPrimaryTouchPointSet::Method = &Instances::fl_events::TouchEvent::isPrimaryTouchPointSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 17, const Value, Value::Number> TFunc_Instances_fl_events_TouchEvent_pressureSet;
// @0x140143bd0
template <> const TFunc_Instances_fl_events_TouchEvent_pressureSet::TMethod TFunc_Instances_fl_events_TouchEvent_pressureSet::Method = &Instances::fl_events::TouchEvent::pressureSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 19, const Value, Instances::fl_display::InteractiveObject*> TFunc_Instances_fl_events_TouchEvent_relatedObjectSet;
// @0x140143c00
template <> const TFunc_Instances_fl_events_TouchEvent_relatedObjectSet::TMethod TFunc_Instances_fl_events_TouchEvent_relatedObjectSet::Method = &Instances::fl_events::TouchEvent::relatedObjectSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 21, const Value, bool> TFunc_Instances_fl_events_TouchEvent_shiftKeySet;
// @0x140143c30
template <> const TFunc_Instances_fl_events_TouchEvent_shiftKeySet::TMethod TFunc_Instances_fl_events_TouchEvent_shiftKeySet::Method = &Instances::fl_events::TouchEvent::shiftKeySet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 23, const Value, Value::Number> TFunc_Instances_fl_events_TouchEvent_sizeXSet;
// @0x140143c60
template <> const TFunc_Instances_fl_events_TouchEvent_sizeXSet::TMethod TFunc_Instances_fl_events_TouchEvent_sizeXSet::Method = &Instances::fl_events::TouchEvent::sizeXSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 25, const Value, Value::Number> TFunc_Instances_fl_events_TouchEvent_sizeYSet;
// @0x140143c90
template <> const TFunc_Instances_fl_events_TouchEvent_sizeYSet::TMethod TFunc_Instances_fl_events_TouchEvent_sizeYSet::Method = &Instances::fl_events::TouchEvent::sizeYSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 29, const Value, SInt32> TFunc_Instances_fl_events_TouchEvent_touchPointIDSet;
// @0x140143cc0
template <> const TFunc_Instances_fl_events_TouchEvent_touchPointIDSet::TMethod TFunc_Instances_fl_events_TouchEvent_touchPointIDSet::Method = &Instances::fl_events::TouchEvent::touchPointIDSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 11, const Value, bool> TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleSet;
// @0x140143cf0
template <> const TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleSet::TMethod TFunc_Instances_fl_events_TouchEvent_isRelatedObjectInaccessibleSet::Method = &Instances::fl_events::TouchEvent::isRelatedObjectInaccessibleSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 13, const Value, Value::Number> TFunc_Instances_fl_events_TouchEvent_localXSet;
// @0x140143d20
template <> const TFunc_Instances_fl_events_TouchEvent_localXSet::TMethod TFunc_Instances_fl_events_TouchEvent_localXSet::Method = &Instances::fl_events::TouchEvent::localXSet;
typedef ThunkFunc1<Instances::fl_events::TouchEvent, 15, const Value, Value::Number> TFunc_Instances_fl_events_TouchEvent_localYSet;
// @0x140143d50
template <> const TFunc_Instances_fl_events_TouchEvent_localYSet::TMethod TFunc_Instances_fl_events_TouchEvent_localYSet::Method = &Instances::fl_events::TouchEvent::localYSet;
typedef ThunkFunc1<Instances::fl_events::TransformGestureEvent, 1, const Value, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_offsetXSet;
// @0x140143d80
template <> const TFunc_Instances_fl_events_TransformGestureEvent_offsetXSet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_offsetXSet::Method = &Instances::fl_events::TransformGestureEvent::offsetXSet;
typedef ThunkFunc1<Instances::fl_events::TransformGestureEvent, 3, const Value, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_offsetYSet;
// @0x140143db0
template <> const TFunc_Instances_fl_events_TransformGestureEvent_offsetYSet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_offsetYSet::Method = &Instances::fl_events::TransformGestureEvent::offsetYSet;
typedef ThunkFunc1<Instances::fl_events::TransformGestureEvent, 5, const Value, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_rotationSet;
// @0x140143de0
template <> const TFunc_Instances_fl_events_TransformGestureEvent_rotationSet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_rotationSet::Method = &Instances::fl_events::TransformGestureEvent::rotationSet;
typedef ThunkFunc1<Instances::fl_events::TransformGestureEvent, 7, const Value, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_scaleXSet;
// @0x140143e10
template <> const TFunc_Instances_fl_events_TransformGestureEvent_scaleXSet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_scaleXSet::Method = &Instances::fl_events::TransformGestureEvent::scaleXSet;
typedef ThunkFunc1<Instances::fl_events::TransformGestureEvent, 9, const Value, Value::Number> TFunc_Instances_fl_events_TransformGestureEvent_scaleYSet;
// @0x140143e40
template <> const TFunc_Instances_fl_events_TransformGestureEvent_scaleYSet::TMethod TFunc_Instances_fl_events_TransformGestureEvent_scaleYSet::Method = &Instances::fl_events::TransformGestureEvent::scaleYSet;
typedef ThunkFunc2<Instances::fl_events::Event, 7, Value, unsigned, const Value*> TFunc_Instances_fl_events_Event_formatToString;
// @0x140143e70
template <> const TFunc_Instances_fl_events_Event_formatToString::TMethod TFunc_Instances_fl_events_Event_formatToString::Method = &Instances::fl_events::Event::formatToString;
typedef ThunkFunc3<Instances::fl_events::EventDispatcher, 3, const Value, const ASString&, const Value&, bool> TFunc_Instances_fl_events_EventDispatcher_removeEventListener;
// @0x140143ea0
template <> const TFunc_Instances_fl_events_EventDispatcher_removeEventListener::TMethod TFunc_Instances_fl_events_EventDispatcher_removeEventListener::Method = &Instances::fl_events::EventDispatcher::removeEventListener;
typedef ThunkFunc5<Instances::fl_events::EventDispatcher, 0, const Value, const ASString&, const Value&, bool, SInt32, bool> TFunc_Instances_fl_events_EventDispatcher_addEventListener;
// @0x140143ed0
template <> const TFunc_Instances_fl_events_EventDispatcher_addEventListener::TMethod TFunc_Instances_fl_events_EventDispatcher_addEventListener::Method = &Instances::fl_events::EventDispatcher::addEventListener;
typedef ThunkFunc0<Classes::fl_external::ExternalInterface, 1, bool> TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsGet;
// @0x140143f00
template <> const TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsGet::TMethod TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsGet::Method = &Classes::fl_external::ExternalInterface::marshallExceptionsGet;
typedef ThunkFunc0<Classes::fl_external::ExternalInterface, 3, ASString> TFunc_Classes_fl_external_ExternalInterface_objectIDGet;
// @0x140143f30
template <> const TFunc_Classes_fl_external_ExternalInterface_objectIDGet::TMethod TFunc_Classes_fl_external_ExternalInterface_objectIDGet::Method = &Classes::fl_external::ExternalInterface::objectIDGet;
typedef ThunkFunc0<Classes::fl_external::ExternalInterface, 0, bool> TFunc_Classes_fl_external_ExternalInterface_availableGet;
// @0x140143f60
template <> const TFunc_Classes_fl_external_ExternalInterface_availableGet::TMethod TFunc_Classes_fl_external_ExternalInterface_availableGet::Method = &Classes::fl_external::ExternalInterface::availableGet;
typedef ThunkFunc1<Classes::fl_external::ExternalInterface, 2, const Value, bool> TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsSet;
// @0x140143f90
template <> const TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsSet::TMethod TFunc_Classes_fl_external_ExternalInterface_marshallExceptionsSet::Method = &Classes::fl_external::ExternalInterface::marshallExceptionsSet;
typedef ThunkFunc2<Classes::fl_external::ExternalInterface, 4, const Value, const ASString&, const Value&> TFunc_Classes_fl_external_ExternalInterface_addCallback;
// @0x140143fc0
template <> const TFunc_Classes_fl_external_ExternalInterface_addCallback::TMethod TFunc_Classes_fl_external_ExternalInterface_addCallback::Method = &Classes::fl_external::ExternalInterface::addCallback;
typedef ThunkFunc2<Classes::fl_external::ExternalInterface, 5, Value, unsigned, const Value*> TFunc_Classes_fl_external_ExternalInterface_call;
// @0x140143ff0
template <> const TFunc_Classes_fl_external_ExternalInterface_call::TMethod TFunc_Classes_fl_external_ExternalInterface_call::Method = &Classes::fl_external::ExternalInterface::call;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 2, Value::Number> TFunc_Instances_fl_filters_BevelFilter_blurXGet;
// @0x140144020
template <> const TFunc_Instances_fl_filters_BevelFilter_blurXGet::TMethod TFunc_Instances_fl_filters_BevelFilter_blurXGet::Method = &Instances::fl_filters::BevelFilter::blurXGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 4, Value::Number> TFunc_Instances_fl_filters_BevelFilter_blurYGet;
// @0x140144050
template <> const TFunc_Instances_fl_filters_BevelFilter_blurYGet::TMethod TFunc_Instances_fl_filters_BevelFilter_blurYGet::Method = &Instances::fl_filters::BevelFilter::blurYGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 6, Value::Number> TFunc_Instances_fl_filters_BevelFilter_distanceGet;
// @0x140144080
template <> const TFunc_Instances_fl_filters_BevelFilter_distanceGet::TMethod TFunc_Instances_fl_filters_BevelFilter_distanceGet::Method = &Instances::fl_filters::BevelFilter::distanceGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 8, Value::Number> TFunc_Instances_fl_filters_BevelFilter_highlightAlphaGet;
// @0x1401440b0
template <> const TFunc_Instances_fl_filters_BevelFilter_highlightAlphaGet::TMethod TFunc_Instances_fl_filters_BevelFilter_highlightAlphaGet::Method = &Instances::fl_filters::BevelFilter::highlightAlphaGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 10, UInt32> TFunc_Instances_fl_filters_BevelFilter_highlightColorGet;
// @0x1401440e0
template <> const TFunc_Instances_fl_filters_BevelFilter_highlightColorGet::TMethod TFunc_Instances_fl_filters_BevelFilter_highlightColorGet::Method = &Instances::fl_filters::BevelFilter::highlightColorGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 0, Value::Number> TFunc_Instances_fl_filters_BevelFilter_angleGet;
// @0x140144110
template <> const TFunc_Instances_fl_filters_BevelFilter_angleGet::TMethod TFunc_Instances_fl_filters_BevelFilter_angleGet::Method = &Instances::fl_filters::BevelFilter::angleGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 16, Value::Number> TFunc_Instances_fl_filters_BevelFilter_shadowAlphaGet;
// @0x140144140
template <> const TFunc_Instances_fl_filters_BevelFilter_shadowAlphaGet::TMethod TFunc_Instances_fl_filters_BevelFilter_shadowAlphaGet::Method = &Instances::fl_filters::BevelFilter::shadowAlphaGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 18, UInt32> TFunc_Instances_fl_filters_BevelFilter_shadowColorGet;
// @0x140144170
template <> const TFunc_Instances_fl_filters_BevelFilter_shadowColorGet::TMethod TFunc_Instances_fl_filters_BevelFilter_shadowColorGet::Method = &Instances::fl_filters::BevelFilter::shadowColorGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 20, Value::Number> TFunc_Instances_fl_filters_BevelFilter_strengthGet;
// @0x1401441a0
template <> const TFunc_Instances_fl_filters_BevelFilter_strengthGet::TMethod TFunc_Instances_fl_filters_BevelFilter_strengthGet::Method = &Instances::fl_filters::BevelFilter::strengthGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 22, ASString> TFunc_Instances_fl_filters_BevelFilter_typeGet;
// @0x1401441d0
template <> const TFunc_Instances_fl_filters_BevelFilter_typeGet::TMethod TFunc_Instances_fl_filters_BevelFilter_typeGet::Method = &Instances::fl_filters::BevelFilter::typeGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 24, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_BevelFilter_clone;
// @0x140144200
template <> const TFunc_Instances_fl_filters_BevelFilter_clone::TMethod TFunc_Instances_fl_filters_BevelFilter_clone::Method = &Instances::fl_filters::BevelFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 12, bool> TFunc_Instances_fl_filters_BevelFilter_knockoutGet;
// @0x140144230
template <> const TFunc_Instances_fl_filters_BevelFilter_knockoutGet::TMethod TFunc_Instances_fl_filters_BevelFilter_knockoutGet::Method = &Instances::fl_filters::BevelFilter::knockoutGet;
typedef ThunkFunc0<Instances::fl_filters::BevelFilter, 14, SInt32> TFunc_Instances_fl_filters_BevelFilter_qualityGet;
// @0x140144260
template <> const TFunc_Instances_fl_filters_BevelFilter_qualityGet::TMethod TFunc_Instances_fl_filters_BevelFilter_qualityGet::Method = &Instances::fl_filters::BevelFilter::qualityGet;
typedef ThunkFunc0<Instances::fl_filters::BitmapFilter, 0, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_BitmapFilter_clone;
// @0x140144290
template <> const TFunc_Instances_fl_filters_BitmapFilter_clone::TMethod TFunc_Instances_fl_filters_BitmapFilter_clone::Method = &Instances::fl_filters::BitmapFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::BlurFilter, 2, Value::Number> TFunc_Instances_fl_filters_BlurFilter_blurYGet;
// @0x1401442c0
template <> const TFunc_Instances_fl_filters_BlurFilter_blurYGet::TMethod TFunc_Instances_fl_filters_BlurFilter_blurYGet::Method = &Instances::fl_filters::BlurFilter::blurYGet;
typedef ThunkFunc0<Instances::fl_filters::BlurFilter, 4, SInt32> TFunc_Instances_fl_filters_BlurFilter_qualityGet;
// @0x1401442f0
template <> const TFunc_Instances_fl_filters_BlurFilter_qualityGet::TMethod TFunc_Instances_fl_filters_BlurFilter_qualityGet::Method = &Instances::fl_filters::BlurFilter::qualityGet;
typedef ThunkFunc0<Instances::fl_filters::BlurFilter, 6, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_BlurFilter_clone;
// @0x140144320
template <> const TFunc_Instances_fl_filters_BlurFilter_clone::TMethod TFunc_Instances_fl_filters_BlurFilter_clone::Method = &Instances::fl_filters::BlurFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::BlurFilter, 0, Value::Number> TFunc_Instances_fl_filters_BlurFilter_blurXGet;
// @0x140144350
template <> const TFunc_Instances_fl_filters_BlurFilter_blurXGet::TMethod TFunc_Instances_fl_filters_BlurFilter_blurXGet::Method = &Instances::fl_filters::BlurFilter::blurXGet;
typedef ThunkFunc0<Instances::fl_filters::ColorMatrixFilter, 2, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_ColorMatrixFilter_clone;
// @0x140144380
template <> const TFunc_Instances_fl_filters_ColorMatrixFilter_clone::TMethod TFunc_Instances_fl_filters_ColorMatrixFilter_clone::Method = &Instances::fl_filters::ColorMatrixFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::ColorMatrixFilter, 0, SPtr<Instances::fl::Array>> TFunc_Instances_fl_filters_ColorMatrixFilter_matrixGet;
// @0x1401443b0
template <> const TFunc_Instances_fl_filters_ColorMatrixFilter_matrixGet::TMethod TFunc_Instances_fl_filters_ColorMatrixFilter_matrixGet::Method = &Instances::fl_filters::ColorMatrixFilter::matrixGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 2, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_angleGet;
// @0x1401443e0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_angleGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_angleGet::Method = &Instances::fl_filters::DropShadowFilter::angleGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 4, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_blurXGet;
// @0x140144410
template <> const TFunc_Instances_fl_filters_DropShadowFilter_blurXGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_blurXGet::Method = &Instances::fl_filters::DropShadowFilter::blurXGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 6, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_blurYGet;
// @0x140144440
template <> const TFunc_Instances_fl_filters_DropShadowFilter_blurYGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_blurYGet::Method = &Instances::fl_filters::DropShadowFilter::blurYGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 8, UInt32> TFunc_Instances_fl_filters_DropShadowFilter_colorGet;
// @0x140144470
template <> const TFunc_Instances_fl_filters_DropShadowFilter_colorGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_colorGet::Method = &Instances::fl_filters::DropShadowFilter::colorGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 10, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_distanceGet;
// @0x1401444a0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_distanceGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_distanceGet::Method = &Instances::fl_filters::DropShadowFilter::distanceGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 0, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_alphaGet;
// @0x1401444d0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_alphaGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_alphaGet::Method = &Instances::fl_filters::DropShadowFilter::alphaGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 16, bool> TFunc_Instances_fl_filters_DropShadowFilter_knockoutGet;
// @0x140144500
template <> const TFunc_Instances_fl_filters_DropShadowFilter_knockoutGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_knockoutGet::Method = &Instances::fl_filters::DropShadowFilter::knockoutGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 18, SInt32> TFunc_Instances_fl_filters_DropShadowFilter_qualityGet;
// @0x140144530
template <> const TFunc_Instances_fl_filters_DropShadowFilter_qualityGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_qualityGet::Method = &Instances::fl_filters::DropShadowFilter::qualityGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 20, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_strengthGet;
// @0x140144560
template <> const TFunc_Instances_fl_filters_DropShadowFilter_strengthGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_strengthGet::Method = &Instances::fl_filters::DropShadowFilter::strengthGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 22, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_DropShadowFilter_clone;
// @0x140144590
template <> const TFunc_Instances_fl_filters_DropShadowFilter_clone::TMethod TFunc_Instances_fl_filters_DropShadowFilter_clone::Method = &Instances::fl_filters::DropShadowFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 12, bool> TFunc_Instances_fl_filters_DropShadowFilter_hideObjectGet;
// @0x1401445c0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_hideObjectGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_hideObjectGet::Method = &Instances::fl_filters::DropShadowFilter::hideObjectGet;
typedef ThunkFunc0<Instances::fl_filters::DropShadowFilter, 14, bool> TFunc_Instances_fl_filters_DropShadowFilter_innerGet;
// @0x1401445f0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_innerGet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_innerGet::Method = &Instances::fl_filters::DropShadowFilter::innerGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 2, Value::Number> TFunc_Instances_fl_filters_GlowFilter_blurXGet;
// @0x140144620
template <> const TFunc_Instances_fl_filters_GlowFilter_blurXGet::TMethod TFunc_Instances_fl_filters_GlowFilter_blurXGet::Method = &Instances::fl_filters::GlowFilter::blurXGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 4, Value::Number> TFunc_Instances_fl_filters_GlowFilter_blurYGet;
// @0x140144650
template <> const TFunc_Instances_fl_filters_GlowFilter_blurYGet::TMethod TFunc_Instances_fl_filters_GlowFilter_blurYGet::Method = &Instances::fl_filters::GlowFilter::blurYGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 6, UInt32> TFunc_Instances_fl_filters_GlowFilter_colorGet;
// @0x140144680
template <> const TFunc_Instances_fl_filters_GlowFilter_colorGet::TMethod TFunc_Instances_fl_filters_GlowFilter_colorGet::Method = &Instances::fl_filters::GlowFilter::colorGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 8, bool> TFunc_Instances_fl_filters_GlowFilter_innerGet;
// @0x1401446b0
template <> const TFunc_Instances_fl_filters_GlowFilter_innerGet::TMethod TFunc_Instances_fl_filters_GlowFilter_innerGet::Method = &Instances::fl_filters::GlowFilter::innerGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 10, bool> TFunc_Instances_fl_filters_GlowFilter_knockoutGet;
// @0x1401446e0
template <> const TFunc_Instances_fl_filters_GlowFilter_knockoutGet::TMethod TFunc_Instances_fl_filters_GlowFilter_knockoutGet::Method = &Instances::fl_filters::GlowFilter::knockoutGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 0, Value::Number> TFunc_Instances_fl_filters_GlowFilter_alphaGet;
// @0x140144710
template <> const TFunc_Instances_fl_filters_GlowFilter_alphaGet::TMethod TFunc_Instances_fl_filters_GlowFilter_alphaGet::Method = &Instances::fl_filters::GlowFilter::alphaGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 16, SPtr<Instances::fl_filters::BitmapFilter>> TFunc_Instances_fl_filters_GlowFilter_clone;
// @0x140144740
template <> const TFunc_Instances_fl_filters_GlowFilter_clone::TMethod TFunc_Instances_fl_filters_GlowFilter_clone::Method = &Instances::fl_filters::GlowFilter::clone;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 12, SInt32> TFunc_Instances_fl_filters_GlowFilter_qualityGet;
// @0x140144770
template <> const TFunc_Instances_fl_filters_GlowFilter_qualityGet::TMethod TFunc_Instances_fl_filters_GlowFilter_qualityGet::Method = &Instances::fl_filters::GlowFilter::qualityGet;
typedef ThunkFunc0<Instances::fl_filters::GlowFilter, 14, Value::Number> TFunc_Instances_fl_filters_GlowFilter_strengthGet;
// @0x1401447a0
template <> const TFunc_Instances_fl_filters_GlowFilter_strengthGet::TMethod TFunc_Instances_fl_filters_GlowFilter_strengthGet::Method = &Instances::fl_filters::GlowFilter::strengthGet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 1, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_angleSet;
// @0x1401447d0
template <> const TFunc_Instances_fl_filters_BevelFilter_angleSet::TMethod TFunc_Instances_fl_filters_BevelFilter_angleSet::Method = &Instances::fl_filters::BevelFilter::angleSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 3, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_blurXSet;
// @0x140144800
template <> const TFunc_Instances_fl_filters_BevelFilter_blurXSet::TMethod TFunc_Instances_fl_filters_BevelFilter_blurXSet::Method = &Instances::fl_filters::BevelFilter::blurXSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 5, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_blurYSet;
// @0x140144830
template <> const TFunc_Instances_fl_filters_BevelFilter_blurYSet::TMethod TFunc_Instances_fl_filters_BevelFilter_blurYSet::Method = &Instances::fl_filters::BevelFilter::blurYSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 7, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_distanceSet;
// @0x140144860
template <> const TFunc_Instances_fl_filters_BevelFilter_distanceSet::TMethod TFunc_Instances_fl_filters_BevelFilter_distanceSet::Method = &Instances::fl_filters::BevelFilter::distanceSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 9, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_highlightAlphaSet;
// @0x140144890
template <> const TFunc_Instances_fl_filters_BevelFilter_highlightAlphaSet::TMethod TFunc_Instances_fl_filters_BevelFilter_highlightAlphaSet::Method = &Instances::fl_filters::BevelFilter::highlightAlphaSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 17, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_shadowAlphaSet;
// @0x1401448c0
template <> const TFunc_Instances_fl_filters_BevelFilter_shadowAlphaSet::TMethod TFunc_Instances_fl_filters_BevelFilter_shadowAlphaSet::Method = &Instances::fl_filters::BevelFilter::shadowAlphaSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 19, const Value, UInt32> TFunc_Instances_fl_filters_BevelFilter_shadowColorSet;
// @0x1401448f0
template <> const TFunc_Instances_fl_filters_BevelFilter_shadowColorSet::TMethod TFunc_Instances_fl_filters_BevelFilter_shadowColorSet::Method = &Instances::fl_filters::BevelFilter::shadowColorSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 21, const Value, Value::Number> TFunc_Instances_fl_filters_BevelFilter_strengthSet;
// @0x140144920
template <> const TFunc_Instances_fl_filters_BevelFilter_strengthSet::TMethod TFunc_Instances_fl_filters_BevelFilter_strengthSet::Method = &Instances::fl_filters::BevelFilter::strengthSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 23, const Value, const ASString&> TFunc_Instances_fl_filters_BevelFilter_typeSet;
// @0x140144950
template <> const TFunc_Instances_fl_filters_BevelFilter_typeSet::TMethod TFunc_Instances_fl_filters_BevelFilter_typeSet::Method = &Instances::fl_filters::BevelFilter::typeSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 11, const Value, UInt32> TFunc_Instances_fl_filters_BevelFilter_highlightColorSet;
// @0x140144980
template <> const TFunc_Instances_fl_filters_BevelFilter_highlightColorSet::TMethod TFunc_Instances_fl_filters_BevelFilter_highlightColorSet::Method = &Instances::fl_filters::BevelFilter::highlightColorSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 13, const Value, bool> TFunc_Instances_fl_filters_BevelFilter_knockoutSet;
// @0x1401449b0
template <> const TFunc_Instances_fl_filters_BevelFilter_knockoutSet::TMethod TFunc_Instances_fl_filters_BevelFilter_knockoutSet::Method = &Instances::fl_filters::BevelFilter::knockoutSet;
typedef ThunkFunc1<Instances::fl_filters::BevelFilter, 15, const Value, SInt32> TFunc_Instances_fl_filters_BevelFilter_qualitySet;
// @0x1401449e0
template <> const TFunc_Instances_fl_filters_BevelFilter_qualitySet::TMethod TFunc_Instances_fl_filters_BevelFilter_qualitySet::Method = &Instances::fl_filters::BevelFilter::qualitySet;
typedef ThunkFunc1<Instances::fl_filters::BlurFilter, 1, const Value, Value::Number> TFunc_Instances_fl_filters_BlurFilter_blurXSet;
// @0x140144a10
template <> const TFunc_Instances_fl_filters_BlurFilter_blurXSet::TMethod TFunc_Instances_fl_filters_BlurFilter_blurXSet::Method = &Instances::fl_filters::BlurFilter::blurXSet;
typedef ThunkFunc1<Instances::fl_filters::BlurFilter, 3, const Value, Value::Number> TFunc_Instances_fl_filters_BlurFilter_blurYSet;
// @0x140144a40
template <> const TFunc_Instances_fl_filters_BlurFilter_blurYSet::TMethod TFunc_Instances_fl_filters_BlurFilter_blurYSet::Method = &Instances::fl_filters::BlurFilter::blurYSet;
typedef ThunkFunc1<Instances::fl_filters::BlurFilter, 5, const Value, SInt32> TFunc_Instances_fl_filters_BlurFilter_qualitySet;
// @0x140144a70
template <> const TFunc_Instances_fl_filters_BlurFilter_qualitySet::TMethod TFunc_Instances_fl_filters_BlurFilter_qualitySet::Method = &Instances::fl_filters::BlurFilter::qualitySet;
typedef ThunkFunc1<Instances::fl_filters::ColorMatrixFilter, 1, const Value, Instances::fl::Array*> TFunc_Instances_fl_filters_ColorMatrixFilter_matrixSet;
// @0x140144aa0
template <> const TFunc_Instances_fl_filters_ColorMatrixFilter_matrixSet::TMethod TFunc_Instances_fl_filters_ColorMatrixFilter_matrixSet::Method = &Instances::fl_filters::ColorMatrixFilter::matrixSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 1, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_alphaSet;
// @0x140144ad0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_alphaSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_alphaSet::Method = &Instances::fl_filters::DropShadowFilter::alphaSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 3, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_angleSet;
// @0x140144b00
template <> const TFunc_Instances_fl_filters_DropShadowFilter_angleSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_angleSet::Method = &Instances::fl_filters::DropShadowFilter::angleSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 5, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_blurXSet;
// @0x140144b30
template <> const TFunc_Instances_fl_filters_DropShadowFilter_blurXSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_blurXSet::Method = &Instances::fl_filters::DropShadowFilter::blurXSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 7, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_blurYSet;
// @0x140144b60
template <> const TFunc_Instances_fl_filters_DropShadowFilter_blurYSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_blurYSet::Method = &Instances::fl_filters::DropShadowFilter::blurYSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 9, const Value, UInt32> TFunc_Instances_fl_filters_DropShadowFilter_colorSet;
// @0x140144b90
template <> const TFunc_Instances_fl_filters_DropShadowFilter_colorSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_colorSet::Method = &Instances::fl_filters::DropShadowFilter::colorSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 17, const Value, bool> TFunc_Instances_fl_filters_DropShadowFilter_knockoutSet;
// @0x140144bc0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_knockoutSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_knockoutSet::Method = &Instances::fl_filters::DropShadowFilter::knockoutSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 19, const Value, SInt32> TFunc_Instances_fl_filters_DropShadowFilter_qualitySet;
// @0x140144bf0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_qualitySet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_qualitySet::Method = &Instances::fl_filters::DropShadowFilter::qualitySet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 21, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_strengthSet;
// @0x140144c20
template <> const TFunc_Instances_fl_filters_DropShadowFilter_strengthSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_strengthSet::Method = &Instances::fl_filters::DropShadowFilter::strengthSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 11, const Value, Value::Number> TFunc_Instances_fl_filters_DropShadowFilter_distanceSet;
// @0x140144c50
template <> const TFunc_Instances_fl_filters_DropShadowFilter_distanceSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_distanceSet::Method = &Instances::fl_filters::DropShadowFilter::distanceSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 13, const Value, bool> TFunc_Instances_fl_filters_DropShadowFilter_hideObjectSet;
// @0x140144c80
template <> const TFunc_Instances_fl_filters_DropShadowFilter_hideObjectSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_hideObjectSet::Method = &Instances::fl_filters::DropShadowFilter::hideObjectSet;
typedef ThunkFunc1<Instances::fl_filters::DropShadowFilter, 15, const Value, bool> TFunc_Instances_fl_filters_DropShadowFilter_innerSet;
// @0x140144cb0
template <> const TFunc_Instances_fl_filters_DropShadowFilter_innerSet::TMethod TFunc_Instances_fl_filters_DropShadowFilter_innerSet::Method = &Instances::fl_filters::DropShadowFilter::innerSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 1, const Value, Value::Number> TFunc_Instances_fl_filters_GlowFilter_alphaSet;
// @0x140144ce0
template <> const TFunc_Instances_fl_filters_GlowFilter_alphaSet::TMethod TFunc_Instances_fl_filters_GlowFilter_alphaSet::Method = &Instances::fl_filters::GlowFilter::alphaSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 3, const Value, Value::Number> TFunc_Instances_fl_filters_GlowFilter_blurXSet;
// @0x140144d10
template <> const TFunc_Instances_fl_filters_GlowFilter_blurXSet::TMethod TFunc_Instances_fl_filters_GlowFilter_blurXSet::Method = &Instances::fl_filters::GlowFilter::blurXSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 5, const Value, Value::Number> TFunc_Instances_fl_filters_GlowFilter_blurYSet;
// @0x140144d40
template <> const TFunc_Instances_fl_filters_GlowFilter_blurYSet::TMethod TFunc_Instances_fl_filters_GlowFilter_blurYSet::Method = &Instances::fl_filters::GlowFilter::blurYSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 7, const Value, UInt32> TFunc_Instances_fl_filters_GlowFilter_colorSet;
// @0x140144d70
template <> const TFunc_Instances_fl_filters_GlowFilter_colorSet::TMethod TFunc_Instances_fl_filters_GlowFilter_colorSet::Method = &Instances::fl_filters::GlowFilter::colorSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 9, const Value, bool> TFunc_Instances_fl_filters_GlowFilter_innerSet;
// @0x140144da0
template <> const TFunc_Instances_fl_filters_GlowFilter_innerSet::TMethod TFunc_Instances_fl_filters_GlowFilter_innerSet::Method = &Instances::fl_filters::GlowFilter::innerSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 11, const Value, bool> TFunc_Instances_fl_filters_GlowFilter_knockoutSet;
// @0x140144dd0
template <> const TFunc_Instances_fl_filters_GlowFilter_knockoutSet::TMethod TFunc_Instances_fl_filters_GlowFilter_knockoutSet::Method = &Instances::fl_filters::GlowFilter::knockoutSet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 13, const Value, SInt32> TFunc_Instances_fl_filters_GlowFilter_qualitySet;
// @0x140144e00
template <> const TFunc_Instances_fl_filters_GlowFilter_qualitySet::TMethod TFunc_Instances_fl_filters_GlowFilter_qualitySet::Method = &Instances::fl_filters::GlowFilter::qualitySet;
typedef ThunkFunc1<Instances::fl_filters::GlowFilter, 15, const Value, Value::Number> TFunc_Instances_fl_filters_GlowFilter_strengthSet;
// @0x140144e30
template <> const TFunc_Instances_fl_filters_GlowFilter_strengthSet::TMethod TFunc_Instances_fl_filters_GlowFilter_strengthSet::Method = &Instances::fl_filters::GlowFilter::strengthSet;
typedef ThunkFunc0<Instances::fl_geom::ColorTransform, 3, ASString> TFunc_Instances_fl_geom_ColorTransform_toString;
// @0x140144e60
template <> const TFunc_Instances_fl_geom_ColorTransform_toString::TMethod TFunc_Instances_fl_geom_ColorTransform_toString::Method = &Instances::fl_geom::ColorTransform::toString;
typedef ThunkFunc0<Instances::fl_geom::ColorTransform, 0, UInt32> TFunc_Instances_fl_geom_ColorTransform_colorGet;
// @0x140144e90
template <> const TFunc_Instances_fl_geom_ColorTransform_colorGet::TMethod TFunc_Instances_fl_geom_ColorTransform_colorGet::Method = &Instances::fl_geom::ColorTransform::colorGet;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 1, SPtr<Instances::fl_geom::Vector3D>> TFunc_Instances_fl_geom_Matrix3D_positionGet;
// @0x140144ec0
template <> const TFunc_Instances_fl_geom_Matrix3D_positionGet::TMethod TFunc_Instances_fl_geom_Matrix3D_positionGet::Method = &Instances::fl_geom::Matrix3D::positionGet;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 3, SPtr<Instances::fl_vec::Vector_double>> TFunc_Instances_fl_geom_Matrix3D_rawDataGet;
// @0x140144ef0
template <> const TFunc_Instances_fl_geom_Matrix3D_rawDataGet::TMethod TFunc_Instances_fl_geom_Matrix3D_rawDataGet::Method = &Instances::fl_geom::Matrix3D::rawDataGet;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 9, SPtr<Instances::fl_geom::Matrix3D>> TFunc_Instances_fl_geom_Matrix3D_clone;
// @0x140144f20
template <> const TFunc_Instances_fl_geom_Matrix3D_clone::TMethod TFunc_Instances_fl_geom_Matrix3D_clone::Method = &Instances::fl_geom::Matrix3D::clone;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 0, Value::Number> TFunc_Instances_fl_geom_Matrix3D_determinantGet;
// @0x140144f50
template <> const TFunc_Instances_fl_geom_Matrix3D_determinantGet::TMethod TFunc_Instances_fl_geom_Matrix3D_determinantGet::Method = &Instances::fl_geom::Matrix3D::determinantGet;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 24, const Value> TFunc_Instances_fl_geom_Matrix3D_transpose;
// @0x140144f80
template <> const TFunc_Instances_fl_geom_Matrix3D_transpose::TMethod TFunc_Instances_fl_geom_Matrix3D_transpose::Method = &Instances::fl_geom::Matrix3D::transpose;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 12, const Value> TFunc_Instances_fl_geom_Matrix3D_identity;
// @0x140144fb0
template <> const TFunc_Instances_fl_geom_Matrix3D_identity::TMethod TFunc_Instances_fl_geom_Matrix3D_identity::Method = &Instances::fl_geom::Matrix3D::identity;
typedef ThunkFunc0<Instances::fl_geom::Matrix3D, 15, bool> TFunc_Instances_fl_geom_Matrix3D_invert;
// @0x140144fe0
template <> const TFunc_Instances_fl_geom_Matrix3D_invert::TMethod TFunc_Instances_fl_geom_Matrix3D_invert::Method = &Instances::fl_geom::Matrix3D::invert;
typedef ThunkFunc0<Instances::fl_geom::Matrix, 5, const Value> TFunc_Instances_fl_geom_Matrix_identity;
// @0x140145010
template <> const TFunc_Instances_fl_geom_Matrix_identity::TMethod TFunc_Instances_fl_geom_Matrix_identity::Method = &Instances::fl_geom::Matrix::identity;
typedef ThunkFunc0<Instances::fl_geom::Matrix, 6, const Value> TFunc_Instances_fl_geom_Matrix_invert;
// @0x140145040
template <> const TFunc_Instances_fl_geom_Matrix_invert::TMethod TFunc_Instances_fl_geom_Matrix_invert::Method = &Instances::fl_geom::Matrix::invert;
typedef ThunkFunc0<Instances::fl_geom::Matrix, 9, ASString> TFunc_Instances_fl_geom_Matrix_toString;
// @0x140145070
template <> const TFunc_Instances_fl_geom_Matrix_toString::TMethod TFunc_Instances_fl_geom_Matrix_toString::Method = &Instances::fl_geom::Matrix::toString;
typedef ThunkFunc0<Instances::fl_geom::Matrix, 0, SPtr<Instances::fl_geom::Matrix>> TFunc_Instances_fl_geom_Matrix_clone;
// @0x1401450a0
template <> const TFunc_Instances_fl_geom_Matrix_clone::TMethod TFunc_Instances_fl_geom_Matrix_clone::Method = &Instances::fl_geom::Matrix::clone;
typedef ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 2, Value::Number> TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthGet;
// @0x1401450d0
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthGet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthGet::Method = &Instances::fl_geom::PerspectiveProjection::focalLengthGet;
typedef ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 4, Value::Number> TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewGet;
// @0x140145100
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewGet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewGet::Method = &Instances::fl_geom::PerspectiveProjection::fieldOfViewGet;
typedef ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 6, SPtr<Instances::fl_geom::Matrix3D>> TFunc_Instances_fl_geom_PerspectiveProjection_toMatrix3D;
// @0x140145130
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_toMatrix3D::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_toMatrix3D::Method = &Instances::fl_geom::PerspectiveProjection::toMatrix3D;
typedef ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 0, SPtr<Instances::fl_geom::Point>> TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterGet;
// @0x140145160
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterGet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterGet::Method = &Instances::fl_geom::PerspectiveProjection::projectionCenterGet;
typedef ThunkFunc0<Instances::fl_geom::Point, 2, SPtr<Instances::fl_geom::Point>> TFunc_Instances_fl_geom_Point_clone;
// @0x140145190
template <> const TFunc_Instances_fl_geom_Point_clone::TMethod TFunc_Instances_fl_geom_Point_clone::Method = &Instances::fl_geom::Point::clone;
typedef ThunkFunc0<Instances::fl_geom::Point, 7, ASString> TFunc_Instances_fl_geom_Point_toString;
// @0x1401451c0
template <> const TFunc_Instances_fl_geom_Point_toString::TMethod TFunc_Instances_fl_geom_Point_toString::Method = &Instances::fl_geom::Point::toString;
typedef ThunkFunc0<Instances::fl_geom::Point, 0, Value::Number> TFunc_Instances_fl_geom_Point_lengthGet;
// @0x1401451f0
template <> const TFunc_Instances_fl_geom_Point_lengthGet::TMethod TFunc_Instances_fl_geom_Point_lengthGet::Method = &Instances::fl_geom::Point::lengthGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 2, SPtr<Instances::fl_geom::Point>> TFunc_Instances_fl_geom_Rectangle_bottomRightGet;
// @0x140145220
template <> const TFunc_Instances_fl_geom_Rectangle_bottomRightGet::TMethod TFunc_Instances_fl_geom_Rectangle_bottomRightGet::Method = &Instances::fl_geom::Rectangle::bottomRightGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 4, Value::Number> TFunc_Instances_fl_geom_Rectangle_leftGet;
// @0x140145250
template <> const TFunc_Instances_fl_geom_Rectangle_leftGet::TMethod TFunc_Instances_fl_geom_Rectangle_leftGet::Method = &Instances::fl_geom::Rectangle::leftGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 6, Value::Number> TFunc_Instances_fl_geom_Rectangle_rightGet;
// @0x140145280
template <> const TFunc_Instances_fl_geom_Rectangle_rightGet::TMethod TFunc_Instances_fl_geom_Rectangle_rightGet::Method = &Instances::fl_geom::Rectangle::rightGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 8, SPtr<Instances::fl_geom::Point>> TFunc_Instances_fl_geom_Rectangle_sizeGet;
// @0x1401452b0
template <> const TFunc_Instances_fl_geom_Rectangle_sizeGet::TMethod TFunc_Instances_fl_geom_Rectangle_sizeGet::Method = &Instances::fl_geom::Rectangle::sizeGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 10, Value::Number> TFunc_Instances_fl_geom_Rectangle_topGet;
// @0x1401452e0
template <> const TFunc_Instances_fl_geom_Rectangle_topGet::TMethod TFunc_Instances_fl_geom_Rectangle_topGet::Method = &Instances::fl_geom::Rectangle::topGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 0, Value::Number> TFunc_Instances_fl_geom_Rectangle_bottomGet;
// @0x140145310
template <> const TFunc_Instances_fl_geom_Rectangle_bottomGet::TMethod TFunc_Instances_fl_geom_Rectangle_bottomGet::Method = &Instances::fl_geom::Rectangle::bottomGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 23, bool> TFunc_Instances_fl_geom_Rectangle_isEmpty;
// @0x140145340
template <> const TFunc_Instances_fl_geom_Rectangle_isEmpty::TMethod TFunc_Instances_fl_geom_Rectangle_isEmpty::Method = &Instances::fl_geom::Rectangle::isEmpty;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 26, const Value> TFunc_Instances_fl_geom_Rectangle_setEmpty;
// @0x140145370
template <> const TFunc_Instances_fl_geom_Rectangle_setEmpty::TMethod TFunc_Instances_fl_geom_Rectangle_setEmpty::Method = &Instances::fl_geom::Rectangle::setEmpty;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 27, ASString> TFunc_Instances_fl_geom_Rectangle_toString;
// @0x1401453a0
template <> const TFunc_Instances_fl_geom_Rectangle_toString::TMethod TFunc_Instances_fl_geom_Rectangle_toString::Method = &Instances::fl_geom::Rectangle::toString;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 12, SPtr<Instances::fl_geom::Point>> TFunc_Instances_fl_geom_Rectangle_topLeftGet;
// @0x1401453d0
template <> const TFunc_Instances_fl_geom_Rectangle_topLeftGet::TMethod TFunc_Instances_fl_geom_Rectangle_topLeftGet::Method = &Instances::fl_geom::Rectangle::topLeftGet;
typedef ThunkFunc0<Instances::fl_geom::Rectangle, 14, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_geom_Rectangle_clone;
// @0x140145400
template <> const TFunc_Instances_fl_geom_Rectangle_clone::TMethod TFunc_Instances_fl_geom_Rectangle_clone::Method = &Instances::fl_geom::Rectangle::clone;
typedef ThunkFunc0<Instances::fl_geom::Transform, 2, SPtr<Instances::fl_geom::ColorTransform>> TFunc_Instances_fl_geom_Transform_concatenatedColorTransformGet;
// @0x140145430
template <> const TFunc_Instances_fl_geom_Transform_concatenatedColorTransformGet::TMethod TFunc_Instances_fl_geom_Transform_concatenatedColorTransformGet::Method = &Instances::fl_geom::Transform::concatenatedColorTransformGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 3, SPtr<Instances::fl_geom::Matrix>> TFunc_Instances_fl_geom_Transform_concatenatedMatrixGet;
// @0x140145460
template <> const TFunc_Instances_fl_geom_Transform_concatenatedMatrixGet::TMethod TFunc_Instances_fl_geom_Transform_concatenatedMatrixGet::Method = &Instances::fl_geom::Transform::concatenatedMatrixGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 4, SPtr<Instances::fl_geom::Matrix>> TFunc_Instances_fl_geom_Transform_matrixGet;
// @0x140145490
template <> const TFunc_Instances_fl_geom_Transform_matrixGet::TMethod TFunc_Instances_fl_geom_Transform_matrixGet::Method = &Instances::fl_geom::Transform::matrixGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 6, SPtr<Instances::fl_geom::Matrix3D>> TFunc_Instances_fl_geom_Transform_matrix3DGet;
// @0x1401454c0
template <> const TFunc_Instances_fl_geom_Transform_matrix3DGet::TMethod TFunc_Instances_fl_geom_Transform_matrix3DGet::Method = &Instances::fl_geom::Transform::matrix3DGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 8, SPtr<Instances::fl_geom::PerspectiveProjection>> TFunc_Instances_fl_geom_Transform_perspectiveProjectionGet;
// @0x1401454f0
template <> const TFunc_Instances_fl_geom_Transform_perspectiveProjectionGet::TMethod TFunc_Instances_fl_geom_Transform_perspectiveProjectionGet::Method = &Instances::fl_geom::Transform::perspectiveProjectionGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 10, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_geom_Transform_pixelBoundsGet;
// @0x140145520
template <> const TFunc_Instances_fl_geom_Transform_pixelBoundsGet::TMethod TFunc_Instances_fl_geom_Transform_pixelBoundsGet::Method = &Instances::fl_geom::Transform::pixelBoundsGet;
typedef ThunkFunc0<Instances::fl_geom::Transform, 0, SPtr<Instances::fl_geom::ColorTransform>> TFunc_Instances_fl_geom_Transform_colorTransformGet;
// @0x140145550
template <> const TFunc_Instances_fl_geom_Transform_colorTransformGet::TMethod TFunc_Instances_fl_geom_Transform_colorTransformGet::Method = &Instances::fl_geom::Transform::colorTransformGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 1, Value::Number> TFunc_Instances_fl_geom_Vector3D_lengthSquaredGet;
// @0x140145580
template <> const TFunc_Instances_fl_geom_Vector3D_lengthSquaredGet::TMethod TFunc_Instances_fl_geom_Vector3D_lengthSquaredGet::Method = &Instances::fl_geom::Vector3D::lengthSquaredGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 3, Value::Number> TFunc_Instances_fl_geom_Vector3D_xGet;
// @0x1401455b0
template <> const TFunc_Instances_fl_geom_Vector3D_xGet::TMethod TFunc_Instances_fl_geom_Vector3D_xGet::Method = &Instances::fl_geom::Vector3D::xGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 5, Value::Number> TFunc_Instances_fl_geom_Vector3D_yGet;
// @0x1401455e0
template <> const TFunc_Instances_fl_geom_Vector3D_yGet::TMethod TFunc_Instances_fl_geom_Vector3D_yGet::Method = &Instances::fl_geom::Vector3D::yGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 7, Value::Number> TFunc_Instances_fl_geom_Vector3D_zGet;
// @0x140145610
template <> const TFunc_Instances_fl_geom_Vector3D_zGet::TMethod TFunc_Instances_fl_geom_Vector3D_zGet::Method = &Instances::fl_geom::Vector3D::zGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 9, Value::Number> TFunc_Instances_fl_geom_Vector3D_wGet;
// @0x140145640
template <> const TFunc_Instances_fl_geom_Vector3D_wGet::TMethod TFunc_Instances_fl_geom_Vector3D_wGet::Method = &Instances::fl_geom::Vector3D::wGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 0, Value::Number> TFunc_Instances_fl_geom_Vector3D_lengthGet;
// @0x140145670
template <> const TFunc_Instances_fl_geom_Vector3D_lengthGet::TMethod TFunc_Instances_fl_geom_Vector3D_lengthGet::Method = &Instances::fl_geom::Vector3D::lengthGet;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 18, const Value> TFunc_Instances_fl_geom_Vector3D_negate;
// @0x1401456a0
template <> const TFunc_Instances_fl_geom_Vector3D_negate::TMethod TFunc_Instances_fl_geom_Vector3D_negate::Method = &Instances::fl_geom::Vector3D::negate;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 19, Value::Number> TFunc_Instances_fl_geom_Vector3D_normalize;
// @0x1401456d0
template <> const TFunc_Instances_fl_geom_Vector3D_normalize::TMethod TFunc_Instances_fl_geom_Vector3D_normalize::Method = &Instances::fl_geom::Vector3D::normalize;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 20, const Value> TFunc_Instances_fl_geom_Vector3D_project;
// @0x140145700
template <> const TFunc_Instances_fl_geom_Vector3D_project::TMethod TFunc_Instances_fl_geom_Vector3D_project::Method = &Instances::fl_geom::Vector3D::project;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 23, ASString> TFunc_Instances_fl_geom_Vector3D_toString;
// @0x140145730
template <> const TFunc_Instances_fl_geom_Vector3D_toString::TMethod TFunc_Instances_fl_geom_Vector3D_toString::Method = &Instances::fl_geom::Vector3D::toString;
typedef ThunkFunc0<Instances::fl_geom::Vector3D, 11, SPtr<Instances::fl_geom::Vector3D>> TFunc_Instances_fl_geom_Vector3D_clone;
// @0x140145760
template <> const TFunc_Instances_fl_geom_Vector3D_clone::TMethod TFunc_Instances_fl_geom_Vector3D_clone::Method = &Instances::fl_geom::Vector3D::clone;
typedef ThunkFunc1<Instances::fl_geom::ColorTransform, 1, const Value, UInt32> TFunc_Instances_fl_geom_ColorTransform_colorSet;
// @0x140145790
template <> const TFunc_Instances_fl_geom_ColorTransform_colorSet::TMethod TFunc_Instances_fl_geom_ColorTransform_colorSet::Method = &Instances::fl_geom::ColorTransform::colorSet;
typedef ThunkFunc1<Instances::fl_geom::ColorTransform, 2, const Value, Instances::fl_geom::ColorTransform*> TFunc_Instances_fl_geom_ColorTransform_concat;
// @0x1401457c0
template <> const TFunc_Instances_fl_geom_ColorTransform_concat::TMethod TFunc_Instances_fl_geom_ColorTransform_concat::Method = &Instances::fl_geom::ColorTransform::concat;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 2, const Value, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_positionSet;
// @0x1401457f0
template <> const TFunc_Instances_fl_geom_Matrix3D_positionSet::TMethod TFunc_Instances_fl_geom_Matrix3D_positionSet::Method = &Instances::fl_geom::Matrix3D::positionSet;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 4, const Value, Instances::fl_vec::Vector_double*> TFunc_Instances_fl_geom_Matrix3D_rawDataSet;
// @0x140145820
template <> const TFunc_Instances_fl_geom_Matrix3D_rawDataSet::TMethod TFunc_Instances_fl_geom_Matrix3D_rawDataSet::Method = &Instances::fl_geom::Matrix3D::rawDataSet;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 5, const Value, Instances::fl_geom::Matrix3D*> TFunc_Instances_fl_geom_Matrix3D_append;
// @0x140145850
template <> const TFunc_Instances_fl_geom_Matrix3D_append::TMethod TFunc_Instances_fl_geom_Matrix3D_append::Method = &Instances::fl_geom::Matrix3D::append;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 10, SPtr<Instances::fl_vec::Vector_object>, const ASString&> TFunc_Instances_fl_geom_Matrix3D_decompose;
// @0x140145880
template <> const TFunc_Instances_fl_geom_Matrix3D_decompose::TMethod TFunc_Instances_fl_geom_Matrix3D_decompose::Method = &Instances::fl_geom::Matrix3D::decompose;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 17, const Value, Instances::fl_geom::Matrix3D*> TFunc_Instances_fl_geom_Matrix3D_prepend;
// @0x1401458b0
template <> const TFunc_Instances_fl_geom_Matrix3D_prepend::TMethod TFunc_Instances_fl_geom_Matrix3D_prepend::Method = &Instances::fl_geom::Matrix3D::prepend;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 22, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_transformVector;
// @0x1401458e0
template <> const TFunc_Instances_fl_geom_Matrix3D_transformVector::TMethod TFunc_Instances_fl_geom_Matrix3D_transformVector::Method = &Instances::fl_geom::Matrix3D::transformVector;
typedef ThunkFunc1<Instances::fl_geom::Matrix3D, 11, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_deltaTransformVector;
// @0x140145910
template <> const TFunc_Instances_fl_geom_Matrix3D_deltaTransformVector::TMethod TFunc_Instances_fl_geom_Matrix3D_deltaTransformVector::Method = &Instances::fl_geom::Matrix3D::deltaTransformVector;
typedef ThunkFunc1<Instances::fl_geom::Matrix, 1, const Value, Instances::fl_geom::Matrix*> TFunc_Instances_fl_geom_Matrix_concat;
// @0x140145940
template <> const TFunc_Instances_fl_geom_Matrix_concat::TMethod TFunc_Instances_fl_geom_Matrix_concat::Method = &Instances::fl_geom::Matrix::concat;
typedef ThunkFunc1<Instances::fl_geom::Matrix, 4, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Matrix_deltaTransformPoint;
// @0x140145970
template <> const TFunc_Instances_fl_geom_Matrix_deltaTransformPoint::TMethod TFunc_Instances_fl_geom_Matrix_deltaTransformPoint::Method = &Instances::fl_geom::Matrix::deltaTransformPoint;
typedef ThunkFunc1<Instances::fl_geom::Matrix, 7, const Value, Value::Number> TFunc_Instances_fl_geom_Matrix_rotate;
// @0x1401459a0
template <> const TFunc_Instances_fl_geom_Matrix_rotate::TMethod TFunc_Instances_fl_geom_Matrix_rotate::Method = &Instances::fl_geom::Matrix::rotate;
typedef ThunkFunc1<Instances::fl_geom::Matrix, 10, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Matrix_transformPoint;
// @0x1401459d0
template <> const TFunc_Instances_fl_geom_Matrix_transformPoint::TMethod TFunc_Instances_fl_geom_Matrix_transformPoint::Method = &Instances::fl_geom::Matrix::transformPoint;
typedef ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 1, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterSet;
// @0x140145a00
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterSet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_projectionCenterSet::Method = &Instances::fl_geom::PerspectiveProjection::projectionCenterSet;
typedef ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 3, const Value, Value::Number> TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthSet;
// @0x140145a30
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthSet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_focalLengthSet::Method = &Instances::fl_geom::PerspectiveProjection::focalLengthSet;
typedef ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 5, const Value, Value::Number> TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewSet;
// @0x140145a60
template <> const TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewSet::TMethod TFunc_Instances_fl_geom_PerspectiveProjection_fieldOfViewSet::Method = &Instances::fl_geom::PerspectiveProjection::fieldOfViewSet;
typedef ThunkFunc1<Instances::fl_geom::Point, 1, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Point_add;
// @0x140145a90
template <> const TFunc_Instances_fl_geom_Point_add::TMethod TFunc_Instances_fl_geom_Point_add::Method = &Instances::fl_geom::Point::add;
typedef ThunkFunc1<Instances::fl_geom::Point, 3, bool, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Point_equals;
// @0x140145ac0
template <> const TFunc_Instances_fl_geom_Point_equals::TMethod TFunc_Instances_fl_geom_Point_equals::Method = &Instances::fl_geom::Point::equals;
typedef ThunkFunc1<Instances::fl_geom::Point, 4, const Value, Value::Number> TFunc_Instances_fl_geom_Point_normalize;
// @0x140145af0
template <> const TFunc_Instances_fl_geom_Point_normalize::TMethod TFunc_Instances_fl_geom_Point_normalize::Method = &Instances::fl_geom::Point::normalize;
typedef ThunkFunc1<Instances::fl_geom::Point, 6, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Point_subtract;
// @0x140145b20
template <> const TFunc_Instances_fl_geom_Point_subtract::TMethod TFunc_Instances_fl_geom_Point_subtract::Method = &Instances::fl_geom::Point::subtract;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 1, const Value, Value::Number> TFunc_Instances_fl_geom_Rectangle_bottomSet;
// @0x140145b50
template <> const TFunc_Instances_fl_geom_Rectangle_bottomSet::TMethod TFunc_Instances_fl_geom_Rectangle_bottomSet::Method = &Instances::fl_geom::Rectangle::bottomSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 3, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_bottomRightSet;
// @0x140145b80
template <> const TFunc_Instances_fl_geom_Rectangle_bottomRightSet::TMethod TFunc_Instances_fl_geom_Rectangle_bottomRightSet::Method = &Instances::fl_geom::Rectangle::bottomRightSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 5, const Value, Value::Number> TFunc_Instances_fl_geom_Rectangle_leftSet;
// @0x140145bb0
template <> const TFunc_Instances_fl_geom_Rectangle_leftSet::TMethod TFunc_Instances_fl_geom_Rectangle_leftSet::Method = &Instances::fl_geom::Rectangle::leftSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 7, const Value, Value::Number> TFunc_Instances_fl_geom_Rectangle_rightSet;
// @0x140145be0
template <> const TFunc_Instances_fl_geom_Rectangle_rightSet::TMethod TFunc_Instances_fl_geom_Rectangle_rightSet::Method = &Instances::fl_geom::Rectangle::rightSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 9, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_sizeSet;
// @0x140145c10
template <> const TFunc_Instances_fl_geom_Rectangle_sizeSet::TMethod TFunc_Instances_fl_geom_Rectangle_sizeSet::Method = &Instances::fl_geom::Rectangle::sizeSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 16, bool, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_containsPoint;
// @0x140145c40
template <> const TFunc_Instances_fl_geom_Rectangle_containsPoint::TMethod TFunc_Instances_fl_geom_Rectangle_containsPoint::Method = &Instances::fl_geom::Rectangle::containsPoint;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 17, bool, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_geom_Rectangle_containsRect;
// @0x140145c70
template <> const TFunc_Instances_fl_geom_Rectangle_containsRect::TMethod TFunc_Instances_fl_geom_Rectangle_containsRect::Method = &Instances::fl_geom::Rectangle::containsRect;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 18, bool, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_geom_Rectangle_equals;
// @0x140145ca0
template <> const TFunc_Instances_fl_geom_Rectangle_equals::TMethod TFunc_Instances_fl_geom_Rectangle_equals::Method = &Instances::fl_geom::Rectangle::equals;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 20, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_inflatePoint;
// @0x140145cd0
template <> const TFunc_Instances_fl_geom_Rectangle_inflatePoint::TMethod TFunc_Instances_fl_geom_Rectangle_inflatePoint::Method = &Instances::fl_geom::Rectangle::inflatePoint;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 21, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_geom_Rectangle_intersection;
// @0x140145d00
template <> const TFunc_Instances_fl_geom_Rectangle_intersection::TMethod TFunc_Instances_fl_geom_Rectangle_intersection::Method = &Instances::fl_geom::Rectangle::intersection;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 22, bool, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_geom_Rectangle_intersects;
// @0x140145d30
template <> const TFunc_Instances_fl_geom_Rectangle_intersects::TMethod TFunc_Instances_fl_geom_Rectangle_intersects::Method = &Instances::fl_geom::Rectangle::intersects;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 25, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_offsetPoint;
// @0x140145d60
template <> const TFunc_Instances_fl_geom_Rectangle_offsetPoint::TMethod TFunc_Instances_fl_geom_Rectangle_offsetPoint::Method = &Instances::fl_geom::Rectangle::offsetPoint;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 28, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_geom_Rectangle_union_;
// @0x140145d90
template <> const TFunc_Instances_fl_geom_Rectangle_union_::TMethod TFunc_Instances_fl_geom_Rectangle_union_::Method = &Instances::fl_geom::Rectangle::union_;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 11, const Value, Value::Number> TFunc_Instances_fl_geom_Rectangle_topSet;
// @0x140145dc0
template <> const TFunc_Instances_fl_geom_Rectangle_topSet::TMethod TFunc_Instances_fl_geom_Rectangle_topSet::Method = &Instances::fl_geom::Rectangle::topSet;
typedef ThunkFunc1<Instances::fl_geom::Rectangle, 13, const Value, Instances::fl_geom::Point*> TFunc_Instances_fl_geom_Rectangle_topLeftSet;
// @0x140145df0
template <> const TFunc_Instances_fl_geom_Rectangle_topLeftSet::TMethod TFunc_Instances_fl_geom_Rectangle_topLeftSet::Method = &Instances::fl_geom::Rectangle::topLeftSet;
typedef ThunkFunc1<Instances::fl_geom::Transform, 1, const Value, Instances::fl_geom::ColorTransform*> TFunc_Instances_fl_geom_Transform_colorTransformSet;
// @0x140145e20
template <> const TFunc_Instances_fl_geom_Transform_colorTransformSet::TMethod TFunc_Instances_fl_geom_Transform_colorTransformSet::Method = &Instances::fl_geom::Transform::colorTransformSet;
typedef ThunkFunc1<Instances::fl_geom::Transform, 5, const Value, Instances::fl_geom::Matrix*> TFunc_Instances_fl_geom_Transform_matrixSet;
// @0x140145e50
template <> const TFunc_Instances_fl_geom_Transform_matrixSet::TMethod TFunc_Instances_fl_geom_Transform_matrixSet::Method = &Instances::fl_geom::Transform::matrixSet;
typedef ThunkFunc1<Instances::fl_geom::Transform, 7, const Value, Instances::fl_geom::Matrix3D*> TFunc_Instances_fl_geom_Transform_matrix3DSet;
// @0x140145e80
template <> const TFunc_Instances_fl_geom_Transform_matrix3DSet::TMethod TFunc_Instances_fl_geom_Transform_matrix3DSet::Method = &Instances::fl_geom::Transform::matrix3DSet;
typedef ThunkFunc1<Instances::fl_geom::Transform, 9, const Value, Instances::fl_geom::PerspectiveProjection*> TFunc_Instances_fl_geom_Transform_perspectiveProjectionSet;
// @0x140145eb0
template <> const TFunc_Instances_fl_geom_Transform_perspectiveProjectionSet::TMethod TFunc_Instances_fl_geom_Transform_perspectiveProjectionSet::Method = &Instances::fl_geom::Transform::perspectiveProjectionSet;
typedef ThunkFunc1<Instances::fl_geom::Transform, 11, SPtr<Instances::fl_geom::Matrix3D>, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_geom_Transform_getRelativeMatrix3D;
// @0x140145ee0
template <> const TFunc_Instances_fl_geom_Transform_getRelativeMatrix3D::TMethod TFunc_Instances_fl_geom_Transform_getRelativeMatrix3D::Method = &Instances::fl_geom::Transform::getRelativeMatrix3D;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 2, const Value, Value::Number> TFunc_Instances_fl_geom_Vector3D_xSet;
// @0x140145f10
template <> const TFunc_Instances_fl_geom_Vector3D_xSet::TMethod TFunc_Instances_fl_geom_Vector3D_xSet::Method = &Instances::fl_geom::Vector3D::xSet;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 4, const Value, Value::Number> TFunc_Instances_fl_geom_Vector3D_ySet;
// @0x140145f40
template <> const TFunc_Instances_fl_geom_Vector3D_ySet::TMethod TFunc_Instances_fl_geom_Vector3D_ySet::Method = &Instances::fl_geom::Vector3D::ySet;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 6, const Value, Value::Number> TFunc_Instances_fl_geom_Vector3D_zSet;
// @0x140145f70
template <> const TFunc_Instances_fl_geom_Vector3D_zSet::TMethod TFunc_Instances_fl_geom_Vector3D_zSet::Method = &Instances::fl_geom::Vector3D::zSet;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 8, const Value, Value::Number> TFunc_Instances_fl_geom_Vector3D_wSet;
// @0x140145fa0
template <> const TFunc_Instances_fl_geom_Vector3D_wSet::TMethod TFunc_Instances_fl_geom_Vector3D_wSet::Method = &Instances::fl_geom::Vector3D::wSet;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 10, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_add;
// @0x140145fd0
template <> const TFunc_Instances_fl_geom_Vector3D_add::TMethod TFunc_Instances_fl_geom_Vector3D_add::Method = &Instances::fl_geom::Vector3D::add;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 16, const Value, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_incrementBy;
// @0x140146000
template <> const TFunc_Instances_fl_geom_Vector3D_incrementBy::TMethod TFunc_Instances_fl_geom_Vector3D_incrementBy::Method = &Instances::fl_geom::Vector3D::incrementBy;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 21, const Value, Value::Number> TFunc_Instances_fl_geom_Vector3D_scaleBy;
// @0x140146030
template <> const TFunc_Instances_fl_geom_Vector3D_scaleBy::TMethod TFunc_Instances_fl_geom_Vector3D_scaleBy::Method = &Instances::fl_geom::Vector3D::scaleBy;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 22, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_subtract;
// @0x140146060
template <> const TFunc_Instances_fl_geom_Vector3D_subtract::TMethod TFunc_Instances_fl_geom_Vector3D_subtract::Method = &Instances::fl_geom::Vector3D::subtract;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 12, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_crossProduct;
// @0x140146090
template <> const TFunc_Instances_fl_geom_Vector3D_crossProduct::TMethod TFunc_Instances_fl_geom_Vector3D_crossProduct::Method = &Instances::fl_geom::Vector3D::crossProduct;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 13, const Value, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_decrementBy;
// @0x1401460c0
template <> const TFunc_Instances_fl_geom_Vector3D_decrementBy::TMethod TFunc_Instances_fl_geom_Vector3D_decrementBy::Method = &Instances::fl_geom::Vector3D::decrementBy;
typedef ThunkFunc1<Instances::fl_geom::Vector3D, 14, Value::Number, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Vector3D_dotProduct;
// @0x1401460f0
template <> const TFunc_Instances_fl_geom_Vector3D_dotProduct::TMethod TFunc_Instances_fl_geom_Vector3D_dotProduct::Method = &Instances::fl_geom::Vector3D::dotProduct;
typedef ThunkFunc2<Instances::fl_geom::Matrix3D, 21, bool, Instances::fl_vec::Vector_object*, const ASString&> TFunc_Instances_fl_geom_Matrix3D_recompose;
// @0x140146120
template <> const TFunc_Instances_fl_geom_Matrix3D_recompose::TMethod TFunc_Instances_fl_geom_Matrix3D_recompose::Method = &Instances::fl_geom::Matrix3D::recompose;

}}} // namespace Scaleform::GFx::AS3

