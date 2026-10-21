// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_14
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424bbab0-0x1424c2a70 .text$mn
// MS2-RANGE: 0x1424c52c0-0x1424c91f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

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
