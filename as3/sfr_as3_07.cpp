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
