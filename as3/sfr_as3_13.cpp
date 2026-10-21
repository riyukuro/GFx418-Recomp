// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424aa5c0-0x1424ad030 .text$mn
// MS2-RANGE: 0x1424ad4d0-0x1424bbab0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424b5730: Classes::fl_ui::Mouse::cursorSet
template struct ThunkFunc1<Classes::fl_ui::Mouse, 0, const Value, const ASString&>;
// thunk 0x1424b5830: Classes::fl_ui::Mouse::cursorGet
template struct ThunkFunc0<Classes::fl_ui::Mouse, 1, ASString>;
// thunk 0x1424b58a0: Classes::fl_ui::Mouse::hide
template struct ThunkFunc0<Classes::fl_ui::Mouse, 2, const Value>;
// thunk 0x1424b58c0: Classes::fl_ui::Mouse::show
template struct ThunkFunc0<Classes::fl_ui::Mouse, 3, const Value>;
// thunk 0x1424b5f30: Instances::fl_ui::ContextMenu::builtInItemsGet
template struct ThunkFunc0<Instances::fl_ui::ContextMenu, 0, SPtr<Instances::fl_ui::ContextMenuBuiltInItems>>;
// thunk 0x1424b5fe0: Instances::fl_ui::ContextMenu::builtInItemsSet
template struct ThunkFunc1<Instances::fl_ui::ContextMenu, 1, const Value, Instances::fl_ui::ContextMenuBuiltInItems*>;
// thunk 0x1424b6020: Instances::fl_ui::ContextMenu::customItemsGet
template struct ThunkFunc0<Instances::fl_ui::ContextMenu, 2, SPtr<Instances::fl::Array>>;
// thunk 0x1424b60d0: Instances::fl_ui::ContextMenu::customItemsSet
template struct ThunkFunc1<Instances::fl_ui::ContextMenu, 3, const Value, Instances::fl::Array*>;
// thunk 0x1424b6110: Instances::fl_ui::ContextMenu::hideBuiltInItems
template struct ThunkFunc0<Instances::fl_ui::ContextMenu, 4, const Value>;
// thunk 0x1424b6390: Classes::fl_ui::Multitouch::inputModeGet
template struct ThunkFunc0<Classes::fl_ui::Multitouch, 0, ASString>;
// thunk 0x1424b6400: Classes::fl_ui::Multitouch::inputModeSet
template struct ThunkFunc1<Classes::fl_ui::Multitouch, 1, const Value, const ASString&>;
// thunk 0x1424b6500: Classes::fl_ui::Multitouch::maxTouchPointsGet
template struct ThunkFunc0<Classes::fl_ui::Multitouch, 2, SInt32>;
// thunk 0x1424b6560: Classes::fl_ui::Multitouch::supportedGesturesGet
template struct ThunkFunc0<Classes::fl_ui::Multitouch, 3, SPtr<Instances::fl_vec::Vector_String>>;
// thunk 0x1424b6610: Classes::fl_ui::Multitouch::supportsGestureEventsGet
template struct ThunkFunc0<Classes::fl_ui::Multitouch, 4, bool>;
// thunk 0x1424b6670: Classes::fl_ui::Multitouch::supportsTouchEventsGet
template struct ThunkFunc0<Classes::fl_ui::Multitouch, 5, bool>;
// thunk 0x1424b6830: Classes::fl_ui::Keyboard::capsLockGet
template struct ThunkFunc0<Classes::fl_ui::Keyboard, 0, bool>;
// thunk 0x1424b6890: Classes::fl_ui::Keyboard::numLockGet
template struct ThunkFunc0<Classes::fl_ui::Keyboard, 1, bool>;
// thunk 0x1424b68f0: Classes::fl_ui::Keyboard::isAccessible
template struct ThunkFunc0<Classes::fl_ui::Keyboard, 2, bool>;
// thunk 0x1424b9860: Instances::fl_utils::Timer::currentCountGet
template struct ThunkFunc0<Instances::fl_utils::Timer, 0, SInt32>;
// thunk 0x1424b98c0: Instances::fl_utils::Timer::delayGet
template struct ThunkFunc0<Instances::fl_utils::Timer, 1, Value::Number>;
// thunk 0x1424b9930: Instances::fl_utils::Timer::delaySet
template struct ThunkFunc1<Instances::fl_utils::Timer, 2, const Value, Value::Number>;
// thunk 0x1424b99c0: Instances::fl_utils::Timer::repeatCountGet
template struct ThunkFunc0<Instances::fl_utils::Timer, 3, SInt32>;
// thunk 0x1424b9a20: Instances::fl_utils::Timer::repeatCountSet
template struct ThunkFunc1<Instances::fl_utils::Timer, 4, const Value, SInt32>;
// thunk 0x1424b9a90: Instances::fl_utils::Timer::runningGet
template struct ThunkFunc0<Instances::fl_utils::Timer, 5, bool>;
// thunk 0x1424b9af0: Instances::fl_utils::Timer::reset
template struct ThunkFunc0<Instances::fl_utils::Timer, 6, const Value>;
// thunk 0x1424b9b10: Instances::fl_utils::Timer::start
template struct ThunkFunc0<Instances::fl_utils::Timer, 7, const Value>;
// thunk 0x1424b9b30: Instances::fl_utils::Timer::stop
template struct ThunkFunc0<Instances::fl_utils::Timer, 8, const Value>;
// thunk 0x1424b9b50: Instances::fl_utils::ByteArray::bytesAvailableGet
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 0, UInt32>;
// thunk 0x1424b9bb0: Instances::fl_utils::ByteArray::endianGet
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 1, ASString>;
// thunk 0x1424b9c20: Instances::fl_utils::ByteArray::endianSet
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 2, const Value, const ASString&>;
// thunk 0x1424b9d20: Instances::fl_utils::ByteArray::lengthGet
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 3, UInt32>;
// thunk 0x1424b9d80: Instances::fl_utils::ByteArray::lengthSet
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 4, const Value, UInt32>;
// thunk 0x1424b9df0: Instances::fl_utils::ByteArray::objectEncodingGet
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 5, UInt32>;
// thunk 0x1424b9e50: Instances::fl_utils::ByteArray::objectEncodingSet
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 6, const Value, UInt32>;
// thunk 0x1424b9ec0: Instances::fl_utils::ByteArray::positionGet
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 7, UInt32>;
// thunk 0x1424b9f20: Instances::fl_utils::ByteArray::positionSet
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 8, const Value, UInt32>;
// thunk 0x1424b9f90: Instances::fl_utils::ByteArray::compress
template struct ThunkFunc2<Instances::fl_utils::ByteArray, 9, Value, unsigned, const Value*>;
// thunk 0x1424b9fb0: Instances::fl_utils::ByteArray::readBoolean
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 10, bool>;
// thunk 0x1424ba010: Instances::fl_utils::ByteArray::readByte
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 11, SInt32>;
// thunk 0x1424ba070: Instances::fl_utils::ByteArray::readBytes
template struct ThunkFunc3<Instances::fl_utils::ByteArray, 12, const Value, Instances::fl_utils::ByteArray*, UInt32, UInt32>;
// thunk 0x1424ba160: Instances::fl_utils::ByteArray::readDouble
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 13, Value::Number>;
// thunk 0x1424ba1d0: Instances::fl_utils::ByteArray::readFloat
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 14, Value::Number>;
// thunk 0x1424ba240: Instances::fl_utils::ByteArray::readInt
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 15, SInt32>;
// thunk 0x1424ba2a0: Instances::fl_utils::ByteArray::readMultiByte
template struct ThunkFunc2<Instances::fl_utils::ByteArray, 16, ASString, UInt32, const ASString&>;
// thunk 0x1424ba420: Instances::fl_utils::ByteArray::readObject
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 17, Value>;
// thunk 0x1424ba440: Instances::fl_utils::ByteArray::readShort
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 18, SInt32>;
// thunk 0x1424ba4a0: Instances::fl_utils::ByteArray::readUnsignedByte
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 19, UInt32>;
// thunk 0x1424ba500: Instances::fl_utils::ByteArray::readUnsignedInt
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 20, UInt32>;
// thunk 0x1424ba560: Instances::fl_utils::ByteArray::readUnsignedShort
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 21, UInt32>;
// thunk 0x1424ba5c0: Instances::fl_utils::ByteArray::readUTF
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 22, ASString>;
// thunk 0x1424ba630: Instances::fl_utils::ByteArray::readUTFBytes
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 23, ASString, UInt32>;
// thunk 0x1424ba6e0: Instances::fl_utils::ByteArray::toString
template struct ThunkFunc0<Instances::fl_utils::ByteArray, 24, ASString>;
// thunk 0x1424ba750: Instances::fl_utils::ByteArray::uncompress
template struct ThunkFunc2<Instances::fl_utils::ByteArray, 25, Value, unsigned, const Value*>;
// thunk 0x1424ba770: Instances::fl_utils::ByteArray::writeBoolean
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 26, const Value, bool>;
// thunk 0x1424ba7d0: Instances::fl_utils::ByteArray::writeByte
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 27, const Value, SInt32>;
// thunk 0x1424ba840: Instances::fl_utils::ByteArray::writeBytes
template struct ThunkFunc3<Instances::fl_utils::ByteArray, 28, const Value, Instances::fl_utils::ByteArray*, UInt32, UInt32>;
// thunk 0x1424ba930: Instances::fl_utils::ByteArray::writeDouble
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 29, const Value, Value::Number>;
// thunk 0x1424ba9c0: Instances::fl_utils::ByteArray::writeFloat
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 30, const Value, Value::Number>;
// thunk 0x1424baa50: Instances::fl_utils::ByteArray::writeInt
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 31, const Value, SInt32>;
// thunk 0x1424baac0: Instances::fl_utils::ByteArray::writeMultiByte
template struct ThunkFunc2<Instances::fl_utils::ByteArray, 32, const Value, const ASString&, const ASString&>;
// thunk 0x1424baca0: Instances::fl_utils::ByteArray::writeObject
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 33, const Value, const Value&>;
// thunk 0x1424badf0: Instances::fl_utils::ByteArray::writeShort
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 34, const Value, SInt32>;
// thunk 0x1424bae60: Instances::fl_utils::ByteArray::writeUnsignedInt
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 35, const Value, UInt32>;
// thunk 0x1424baed0: Instances::fl_utils::ByteArray::writeUTF
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 36, const Value, const ASString&>;
// thunk 0x1424bafd0: Instances::fl_utils::ByteArray::writeUTFBytes
template struct ThunkFunc1<Instances::fl_utils::ByteArray, 37, const Value, const Value&>;
// thunk 0x1424bb120: Classes::fl_utils::ByteArray::defaultObjectEncodingSet
template struct ThunkFunc1<Classes::fl_utils::ByteArray, 0, const Value, UInt32>;
// thunk 0x1424bb190: Classes::fl_utils::ByteArray::defaultObjectEncodingGet
template struct ThunkFunc0<Classes::fl_utils::ByteArray, 1, UInt32>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc1@VMouse@fl_ui@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b5730
// MS2-PIN: ?Func@?$ThunkFunc0@VMouse@fl_ui@Classes@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b5830
// MS2-PIN: ?Func@?$ThunkFunc0@VMouse@fl_ui@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b58a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouse@fl_ui@Classes@AS3@GFx@Scaleform@@$02$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b58c0
// MS2-PIN: ?Func@?$ThunkFunc0@VContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VContextMenuBuiltInItems@fl_ui@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b5f30
// MS2-PIN: ?Func@?$ThunkFunc1@VContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVContextMenuBuiltInItems@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b5fe0
// MS2-PIN: ?Func@?$ThunkFunc0@VContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6020
// MS2-PIN: ?Func@?$ThunkFunc1@VContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b60d0
// MS2-PIN: ?Func@?$ThunkFunc0@VContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6110
// MS2-PIN: ?Func@?$ThunkFunc0@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6390
// MS2-PIN: ?Func@?$ThunkFunc1@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6400
// MS2-PIN: ?Func@?$ThunkFunc0@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$01J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6500
// MS2-PIN: ?Func@?$ThunkFunc0@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$02V?$SPtr@VVector_String@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6560
// MS2-PIN: ?Func@?$ThunkFunc0@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6610
// MS2-PIN: ?Func@?$ThunkFunc0@VMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6670
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboard@fl_ui@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6830
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboard@fl_ui@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b6890
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboard@fl_ui@Classes@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b68f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9860
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$00N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b98c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9930
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$02J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b99c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9a20
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9a90
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9af0
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9b10
// MS2-PIN: ?Func@?$ThunkFunc0@VTimer@fl_utils@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9b30
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9b50
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9bb0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9c20
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$02K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9d20
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9d80
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$04K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9df0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9e50
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$06K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9ec0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9f20
// MS2-PIN: ?Func@?$ThunkFunc2@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9f90
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424b9fb0
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0L@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba010
// MS2-PIN: ?Func@?$ThunkFunc3@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@PEAV123456@KK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba070
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0N@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba160
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0O@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba1d0
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0P@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba240
// MS2-PIN: ?Func@?$ThunkFunc2@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BA@VASString@56@KAEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba2a0
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BB@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba420
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BC@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba440
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BD@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba4a0
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BE@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba500
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BF@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba560
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba5c0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BH@VASString@56@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba630
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BI@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba6e0
// MS2-PIN: ?Func@?$ThunkFunc2@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BJ@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba750
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BK@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba770
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BL@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba7d0
// MS2-PIN: ?Func@?$ThunkFunc3@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BM@$$CBVValue@456@PEAV123456@KK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba840
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BN@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba930
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BO@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ba9c0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0BP@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424baa50
// MS2-PIN: ?Func@?$ThunkFunc2@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CA@$$CBVValue@456@AEBVASString@56@AEBV856@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424baac0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CB@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424baca0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CC@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424badf0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CD@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424bae60
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CE@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424baed0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@$0CF@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424bafd0
// MS2-PIN: ?Func@?$ThunkFunc1@VByteArray@fl_utils@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424bb120
// MS2-PIN: ?Func@?$ThunkFunc0@VByteArray@fl_utils@Classes@AS3@GFx@Scaleform@@$00K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424bb190
