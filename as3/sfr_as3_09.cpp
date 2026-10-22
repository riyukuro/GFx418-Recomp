// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_09
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424653f0-0x142473710 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142472fc0: Classes::fl_external::ExternalInterface::availableGet
template struct ThunkFunc0<Classes::fl_external::ExternalInterface, 0, bool>;
// thunk 0x142473020: Classes::fl_external::ExternalInterface::marshallExceptionsGet
template struct ThunkFunc0<Classes::fl_external::ExternalInterface, 1, bool>;
// thunk 0x142473080: Classes::fl_external::ExternalInterface::marshallExceptionsSet
template struct ThunkFunc1<Classes::fl_external::ExternalInterface, 2, const Value, bool>;
// thunk 0x1424730e0: Classes::fl_external::ExternalInterface::objectIDGet
template struct ThunkFunc0<Classes::fl_external::ExternalInterface, 3, ASString>;
// thunk 0x142473150: Classes::fl_external::ExternalInterface::addCallback
template struct ThunkFunc2<Classes::fl_external::ExternalInterface, 4, const Value, const ASString&, const Value&>;
// thunk 0x142473330: Classes::fl_external::ExternalInterface::call
template struct ThunkFunc2<Classes::fl_external::ExternalInterface, 5, Value, unsigned, const Value*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142472fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473020
// MS2-PIN: ?Func@?$ThunkFunc1@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473080
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424730e0
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$03$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473150
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$04VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473330
