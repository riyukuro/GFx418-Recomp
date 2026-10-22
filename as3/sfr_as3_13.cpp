// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424aa5c0-0x1424ad030 .text$mn
// MS2-RANGE: 0x1424ad4d0-0x1424bb1f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"

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


// ==== flash.ui: class traits, instance traits, classes and instances =================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_ui
{
    extern const ClassInfo ContextMenuCI;
    extern const ClassInfo ContextMenuBuiltInItemsCI;
    extern const ClassInfo ContextMenuClipboardItemsCI;
    extern const ClassInfo ContextMenuItemCI;
    extern const ClassInfo KeyLocationCI;
    extern const ClassInfo KeyboardCI;
    extern const ClassInfo MouseCI;
    extern const ClassInfo MouseCursorCI;
    extern const ClassInfo MultitouchCI;
    extern const ClassInfo MultitouchInputModeCI;
}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b54a0
    Pickable<Traits> KeyLocation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) KeyLocation(vm));
    }

    // @0x1424b55f0
    Pickable<Traits> Mouse::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Mouse(vm));
    }

    // @0x1424b58e0
    Pickable<Traits> MouseCursor::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MouseCursor(vm));
    }

    // @0x1424b5a50
    Pickable<Traits> Multitouch::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Multitouch(vm));
    }

    // @0x1424b5b90
    Pickable<Traits> ContextMenuClipboardItems::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ContextMenuClipboardItems(vm));
    }

    // @0x1424b5cd0
    Pickable<Traits> ContextMenuItem::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ContextMenuItem(vm));
    }

    // @0x1424b5df0
    Pickable<Traits> ContextMenu::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ContextMenu(vm));
    }

    // @0x1424b6130
    Pickable<Traits> Keyboard::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Keyboard(vm));
    }

    // @0x1424b6250
    Pickable<Traits> ContextMenuBuiltInItems::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ContextMenuBuiltInItems(vm));
    }

    // @0x1424b66d0
    Pickable<Traits> MultitouchInputMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MultitouchInputMode(vm));
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6950
    ContextMenu::ContextMenu(VM& vm)
        : Traits(vm, AS3::fl_ui::ContextMenuCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_ui::ContextMenu(vm, AS3::fl_ui::ContextMenuCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_ui
{
    // @0x1424b6a50
    ContextMenu::ContextMenu(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_ui
{
    // @0x1424b6a80
    ContextMenu::ContextMenu(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6ab0
    ContextMenuBuiltInItems::ContextMenuBuiltInItems(VM& vm)
        : Traits(vm, AS3::fl_ui::ContextMenuBuiltInItemsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_ui::ContextMenuBuiltInItems(vm, AS3::fl_ui::ContextMenuBuiltInItemsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_ui
{
    // @0x1424b6bb0
    ContextMenuBuiltInItems::ContextMenuBuiltInItems(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_ui
{
    // @0x1424b6be0
    ContextMenuBuiltInItems::ContextMenuBuiltInItems(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , forwardAndBack(true)
        , loop(true)
        , play(true)
        , print(true)
        , quality(true)
        , rewind(true)
        , save(true)
        , zoom(true)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6c10
    ContextMenuClipboardItems::ContextMenuClipboardItems(VM& vm)
        : Traits(vm, AS3::fl_ui::ContextMenuClipboardItemsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_ui::ContextMenuClipboardItems(vm, AS3::fl_ui::ContextMenuClipboardItemsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_ui
{
    // @0x1424b6d10
    ContextMenuClipboardItems::ContextMenuClipboardItems(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_ui
{
    // @0x1424b6d40
    ContextMenuClipboardItems::ContextMenuClipboardItems(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , clear(false)
        , copy(false)
        , cut(false)
        , paste(false)
        , selectAll(true)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6d70
    ContextMenuItem::ContextMenuItem(VM& vm)
        : Traits(vm, AS3::fl_ui::ContextMenuItemCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_ui::ContextMenuItemCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6e50
    KeyLocation::KeyLocation(VM& vm)
        : Traits(vm, AS3::fl_ui::KeyLocationCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::KeyLocationCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::KeyLocation(*this)));
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b6f50
    KeyLocation::KeyLocation(ClassTraits::Traits& t)
        : Class(t)
        , LEFT(1)
        , NUM_PAD(3)
        , RIGHT(2)
        , STANDARD(0)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b6f90
    Keyboard::Keyboard(VM& vm)
        : Traits(vm, AS3::fl_ui::KeyboardCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::KeyboardCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::Keyboard(*this)));
    }
}}

// <windows.h> defines ALTERNATE and DELETE as macros; the Keyboard constants reuse the names.
#pragma push_macro("ALTERNATE")
#pragma push_macro("DELETE")
#undef ALTERNATE
#undef DELETE
namespace Classes { namespace fl_ui
{
    // @0x1424b7070
    Keyboard::Keyboard(ClassTraits::Traits& t)
        : Class(t)
        , A(65)
        , ALTERNATE(18)
        , B(66)
        , BACKQUOTE(192)
        , BACKSLASH(220)
        , BACKSPACE(8)
        , C(67)
        , CAPS_LOCK(20)
        , COMMA(188)
        , COMMAND(15)
        , CONTROL(17)
        , D(68)
        , DELETE(46)
        , DOWN(40)
        , E(69)
        , END(35)
        , ENTER(13)
        , EQUAL(187)
        , ESCAPE(27)
        , F(70)
        , F1(112)
        , F10(121)
        , F11(122)
        , F12(123)
        , F13(124)
        , F14(125)
        , F15(126)
        , F2(113)
        , F3(114)
        , F4(115)
        , F5(116)
        , F6(117)
        , F7(118)
        , F8(119)
        , F9(120)
        , G(71)
        , H(72)
        , HOME(36)
        , I(73)
        , INSERT(45)
        , J(74)
        , K(75)
        , KEYNAME_BEGIN("Begin")
        , KEYNAME_BREAK("Break")
        , KEYNAME_CLEARDISPLAY("ClrDsp")
        , KEYNAME_CLEARLINE("ClrLn")
        , KEYNAME_DELETE("Delete")
        , KEYNAME_DELETECHAR("DelChr")
        , KEYNAME_DELETELINE("DelLn")
        , KEYNAME_DOWNARROW("Down")
        , KEYNAME_END("End")
        , KEYNAME_EXECUTE("Exec")
        , KEYNAME_F1("F1")
        , KEYNAME_F10("F10")
        , KEYNAME_F11("F11")
        , KEYNAME_F12("F12")
        , KEYNAME_F13("F13")
        , KEYNAME_F14("F14")
        , KEYNAME_F15("F15")
        , KEYNAME_F16("F16")
        , KEYNAME_F17("F17")
        , KEYNAME_F18("F18")
        , KEYNAME_F19("F19")
        , KEYNAME_F2("F2")
        , KEYNAME_F20("F20")
        , KEYNAME_F21("F21")
        , KEYNAME_F22("F22")
        , KEYNAME_F23("F23")
        , KEYNAME_F24("F24")
        , KEYNAME_F25("F25")
        , KEYNAME_F26("F26")
        , KEYNAME_F27("F27")
        , KEYNAME_F28("F28")
        , KEYNAME_F29("F29")
        , KEYNAME_F3("F3")
        , KEYNAME_F30("F30")
        , KEYNAME_F31("F31")
        , KEYNAME_F32("F32")
        , KEYNAME_F33("F33")
        , KEYNAME_F34("F34")
        , KEYNAME_F35("F35")
        , KEYNAME_F4("F4")
        , KEYNAME_F5("F5")
        , KEYNAME_F6("F6")
        , KEYNAME_F7("F7")
        , KEYNAME_F8("F8")
        , KEYNAME_F9("F9")
        , KEYNAME_FIND("Find")
        , KEYNAME_HELP("Help")
        , KEYNAME_HOME("Home")
        , KEYNAME_INSERT("Insert")
        , KEYNAME_INSERTCHAR("InsChr")
        , KEYNAME_INSERTLINE("InsLn")
        , KEYNAME_LEFTARROW("Left")
        , KEYNAME_MENU("Menu")
        , KEYNAME_MODESWITCH("ModeSw")
        , KEYNAME_NEXT("Next")
        , KEYNAME_PAGEDOWN("PgDn")
        , KEYNAME_PAGEUP("PgUp")
        , KEYNAME_PAUSE("Pause")
        , KEYNAME_PREV("Prev")
        , KEYNAME_PRINT("Print")
        , KEYNAME_PRINTSCREEN("PrntScrn")
        , KEYNAME_REDO("Redo")
        , KEYNAME_RESET("Reset")
        , KEYNAME_RIGHTARROW("Right")
        , KEYNAME_SCROLLLOCK("ScrlLck")
        , KEYNAME_SELECT("Select")
        , KEYNAME_STOP("Stop")
        , KEYNAME_SYSREQ("SysReq")
        , KEYNAME_SYSTEM("Sys")
        , KEYNAME_UNDO("Undo")
        , KEYNAME_UPARROW("Up")
        , KEYNAME_USER("User")
        , L(76)
        , LEFT(37)
        , LEFTBRACKET(219)
        , M(77)
        , MINUS(189)
        , N(78)
        , NUMBER_0(48)
        , NUMBER_1(49)
        , NUMBER_2(50)
        , NUMBER_3(51)
        , NUMBER_4(52)
        , NUMBER_5(53)
        , NUMBER_6(54)
        , NUMBER_7(55)
        , NUMBER_8(56)
        , NUMBER_9(57)
        , NUMPAD(21)
        , NUMPAD_0(96)
        , NUMPAD_1(97)
        , NUMPAD_2(98)
        , NUMPAD_3(99)
        , NUMPAD_4(100)
        , NUMPAD_5(101)
        , NUMPAD_6(102)
        , NUMPAD_7(103)
        , NUMPAD_8(104)
        , NUMPAD_9(105)
        , NUMPAD_ADD(107)
        , NUMPAD_DECIMAL(110)
        , NUMPAD_DIVIDE(111)
        , NUMPAD_ENTER(108)
        , NUMPAD_MULTIPLY(106)
        , NUMPAD_SUBTRACT(109)
        , O(79)
        , P(80)
        , PAGE_DOWN(34)
        , PAGE_UP(33)
        , PERIOD(190)
        , Q(81)
        , QUOTE(222)
        , R(82)
        , RIGHT(39)
        , RIGHTBRACKET(221)
        , S(83)
        , SEMICOLON(186)
        , SHIFT(16)
        , SLASH(191)
        , SPACE(32)
        , STRING_BEGIN("")
        , STRING_BREAK("")
        , STRING_CLEARDISPLAY("")
        , STRING_CLEARLINE("")
        , STRING_DELETE("")
        , STRING_DELETECHAR("")
        , STRING_DELETELINE("")
        , STRING_DOWNARROW("")
        , STRING_END("")
        , STRING_EXECUTE("")
        , STRING_F1("")
        , STRING_F10("")
        , STRING_F11("")
        , STRING_F12("")
        , STRING_F13("")
        , STRING_F14("")
        , STRING_F15("")
        , STRING_F16("")
        , STRING_F17("")
        , STRING_F18("")
        , STRING_F19("")
        , STRING_F2("")
        , STRING_F20("")
        , STRING_F21("")
        , STRING_F22("")
        , STRING_F23("")
        , STRING_F24("")
        , STRING_F25("")
        , STRING_F26("")
        , STRING_F27("")
        , STRING_F28("")
        , STRING_F29("")
        , STRING_F3("")
        , STRING_F30("")
        , STRING_F31("")
        , STRING_F32("")
        , STRING_F33("")
        , STRING_F34("")
        , STRING_F35("")
        , STRING_F4("")
        , STRING_F5("")
        , STRING_F6("")
        , STRING_F7("")
        , STRING_F8("")
        , STRING_F9("")
        , STRING_FIND("")
        , STRING_HELP("")
        , STRING_HOME("")
        , STRING_INSERT("")
        , STRING_INSERTCHAR("")
        , STRING_INSERTLINE("")
        , STRING_LEFTARROW("")
        , STRING_MENU("")
        , STRING_MODESWITCH("")
        , STRING_NEXT("")
        , STRING_PAGEDOWN("")
        , STRING_PAGEUP("")
        , STRING_PAUSE("")
        , STRING_PREV("")
        , STRING_PRINT("")
        , STRING_PRINTSCREEN("")
        , STRING_REDO("")
        , STRING_RESET("")
        , STRING_RIGHTARROW("")
        , STRING_SCROLLLOCK("")
        , STRING_SELECT("")
        , STRING_STOP("")
        , STRING_SYSREQ("")
        , STRING_SYSTEM("")
        , STRING_UNDO("")
        , STRING_UPARROW("")
        , STRING_USER("")
        , T(84)
        , TAB(9)
        , U(85)
        , UP(38)
        , V(86)
        , W(87)
        , X(88)
        , Y(89)
        , Z(90)
    {
    }
}}
#pragma pop_macro("DELETE")
#pragma pop_macro("ALTERNATE")

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b7c40
    Mouse::Mouse(VM& vm)
        : Traits(vm, AS3::fl_ui::MouseCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::MouseCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::Mouse(*this)));
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b7d20
    Mouse::Mouse(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b7d50
    MouseCursor::MouseCursor(VM& vm)
        : Traits(vm, AS3::fl_ui::MouseCursorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::MouseCursorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::MouseCursor(*this)));
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b7e70
    MouseCursor::MouseCursor(ClassTraits::Traits& t)
        : Class(t)
        , ARROW("arrow")
        , AUTO("auto")
        , BUTTON("button")
        , HAND("hand")
        , IBEAM("ibeam")
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b7ed0
    Multitouch::Multitouch(VM& vm)
        : Traits(vm, AS3::fl_ui::MultitouchCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::MultitouchCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::Multitouch(*this)));
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b7fb0
    Multitouch::Multitouch(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_ui
{
    // @0x1424b7fe0
    MultitouchInputMode::MultitouchInputMode(VM& vm)
        : Traits(vm, AS3::fl_ui::MultitouchInputModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_ui::MultitouchInputModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_ui::MultitouchInputMode(*this)));
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b80e0
    MultitouchInputMode::MultitouchInputMode(ClassTraits::Traits& t)
        : Class(t)
        , GESTURE("gesture")
        , NONE("none")
        , TOUCH_POINT("touchPoint")
    {
    }
}}

namespace InstanceTraits { namespace fl_ui
{
    // @0x1424b8ce0
    Pickable<ContextMenu::InstanceType> ContextMenu::MakeInstance(ContextMenu& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424b8d50
    Pickable<ContextMenuBuiltInItems::InstanceType> ContextMenuBuiltInItems::MakeInstance(ContextMenuBuiltInItems& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424b8dd0
    Pickable<ContextMenuClipboardItems::InstanceType> ContextMenuClipboardItems::MakeInstance(ContextMenuClipboardItems& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424b8e50
    void ContextMenu::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ContextMenu&>(t)));
    }

    // @0x1424b8eb0
    void ContextMenuBuiltInItems::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ContextMenuBuiltInItems&>(t)));
    }

    // @0x1424b8f20
    void ContextMenuClipboardItems::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ContextMenuClipboardItems&>(t)));
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.ui natives ================================================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_ui
{
    // @0x1424b90e0
    SPtr<Instances::fl_ui::ContextMenuBuiltInItems> ContextMenu::builtInItemsGet()
    {
        SPtr<Instances::fl_ui::ContextMenuBuiltInItems> result;
        builtInItemsGet(result);
        return result;
    }

    // @0x1424b9120
    void ContextMenu::builtInItemsGet(SPtr<Instances::fl_ui::ContextMenuBuiltInItems>& result)
    {
        result = NULL;
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::builtInItemsGet() is not implemented\n");
    }

    // @0x1424b9270
    void ContextMenu::customItemsGet(SPtr<Instances::fl::Array>& result)
    {
        result = GetVM().MakeArray();
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::customItemsGet() is not implemented\n");
    }

    // MS2-FUNCTIONAL: our compiler inlines the native into this wrapper; the exe calls it
    // @0x1424b9250
    SPtr<Instances::fl::Array> ContextMenu::customItemsGet()
    {
        SPtr<Instances::fl::Array> result;
        customItemsGet(result);
        return result;
    }
}}

namespace Classes { namespace fl_ui
{
    // @0x1424b91b0
    void Keyboard::capsLockGet(bool& result)
    {
        KeyModifiers mods = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetKeyboardState(0)->GetKeyModifiers();
        result = mods.IsCapsToggled();
    }

    // @0x1424b95b0
    void Keyboard::numLockGet(bool& result)
    {
        KeyModifiers mods = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetKeyboardState(0)->GetKeyModifiers();
        result = mods.IsNumToggled();
    }

    // @0x1424b9320
    void Mouse::hide(const Value& result)
    {
        SF_UNUSED(result);
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (pmovie->pUserEventHandler)
            pmovie->pUserEventHandler->HandleEvent(pmovie->AsMovie(), MouseCursorEvent(Event::DoHideMouse, 0));
        else if (pmovie->GetStateBag()->GetLogState())
            pmovie->GetStateBag()->GetLogState()->LogScriptWarning("No user event handler interface is installed; Mouse.hide failed.");
    }

    // The exe logs the Mouse.hide message here too.
    // @0x1424b95f0
    void Mouse::show(const Value& result)
    {
        SF_UNUSED(result);
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (pmovie->pUserEventHandler)
            pmovie->pUserEventHandler->HandleEvent(pmovie->AsMovie(), MouseCursorEvent(Event::DoShowMouse, 0));
        else if (pmovie->GetStateBag()->GetLogState())
            pmovie->GetStateBag()->GetLogState()->LogScriptWarning("No user event handler interface is installed; Mouse.hide failed.");
    }

    // @0x1424b9400
    void Multitouch::inputModeGet(ASString& result)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        switch (vm.GetMovieImpl()->GetMultitouchInputMode())
        {
        case MovieImpl::MTI_TouchPoint:
            result = vm.GetStringManager().CreateConstString("touchPoint");
            break;
        case MovieImpl::MTI_Gesture:
            result = vm.GetStringManager().CreateConstString("gesture");
            break;
        case MovieImpl::MTI_Mixed:
            result = vm.GetStringManager().CreateConstString("mixed");
            break;
        default:
            result = vm.GetStringManager().CreateConstString("none");
        }
    }

    // @0x1424b94c0
    void Multitouch::inputModeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        ASVM& vm = static_cast<ASVM&>(GetVM());
        MovieImpl::MultitouchInputMode mode = MovieImpl::MTI_None;
        if (!strcmp(value.ToCStr(), "touchPoint"))
            mode = MovieImpl::MTI_TouchPoint;
        else if (!strcmp(value.ToCStr(), "gesture"))
            mode = MovieImpl::MTI_Gesture;
        else if (!strcmp(value.ToCStr(), "mixed"))
            mode = MovieImpl::MTI_Mixed;
        vm.GetMovieImpl()->SetMultitouchInputMode(mode);
    }

    // @0x1424b9580
    void Multitouch::maxTouchPointsGet(SInt32& result)
    {
        result = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetMaxTouchPoints();
    }

    // @0x1424b97d0
    void Multitouch::supportsGestureEventsGet(bool& result)
    {
        result = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetSupportedGesturesMask() != 0;
    }

    // @0x1424b9800
    void Multitouch::supportsTouchEventsGet(bool& result)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.GetMovieImpl()->GetMaxTouchPoints() > 0 && (vm.GetMovieImpl()->GetMultitouchInputMode() & MovieImpl::MTI_TouchPoint))
            result = true;
        else
            result = false;
    }
}}

}}} // namespace Scaleform::GFx::AS3


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
// MS2-PIN: ??_7ContextMenu@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316ed50
// MS2-PIN: ??_7ContextMenuBuiltInItems@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316e878
// MS2-PIN: ??_7ContextMenuClipboardItems@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316eaa8
// MS2-PIN: ??_7ContextMenuItem@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316eb48
// MS2-PIN: ??_7KeyLocation@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316f3b8
// MS2-PIN: ??_7Keyboard@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316efc0
// MS2-PIN: ??_7Mouse@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316f538
// MS2-PIN: ??_7MouseCursor@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316f6f8
// MS2-PIN: ??_7Multitouch@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316f898
// MS2-PIN: ??_7MultitouchInputMode@fl_ui@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316fa38
// MS2-PIN: ??_7ContextMenu@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316eca8
// MS2-PIN: ??_7ContextMenuBuiltInItems@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316e7c8
// MS2-PIN: ??_7ContextMenuClipboardItems@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316e9f0
// MS2-PIN: ??_7ContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@6B@ 0x14316ebe0
// MS2-PIN: ??_7ContextMenuBuiltInItems@fl_ui@Instances@AS3@GFx@Scaleform@@6B@ 0x14316e6f0
// MS2-PIN: ??_7ContextMenuClipboardItems@fl_ui@Instances@AS3@GFx@Scaleform@@6B@ 0x14316e918
// MS2-PIN: ??_7KeyLocation@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316f450
// MS2-PIN: ??_7Keyboard@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316f050
// MS2-PIN: ??_7Mouse@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316f5c8
// MS2-PIN: ??_7MouseCursor@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316f790
// MS2-PIN: ??_7Multitouch@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316f928
// MS2-PIN: ??_7MultitouchInputMode@fl_ui@Classes@AS3@GFx@Scaleform@@6B@ 0x14316fad8
// MS2-PIN: ??_GContextMenu@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8130
// MS2-PIN: ??_GContextMenuBuiltInItems@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8280
// MS2-PIN: ??_GContextMenuClipboardItems@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b83d0
// MS2-PIN: ??_GContextMenuItem@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8520
// MS2-PIN: ??_GKeyLocation@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b85b0
// MS2-PIN: ??_GKeyboard@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b86a0
// MS2-PIN: ??_GMouse@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b87c0
// MS2-PIN: ??_GMouseCursor@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b88b0
// MS2-PIN: ??_GMultitouch@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b89a0
// MS2-PIN: ??_GMultitouchInputMode@fl_ui@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8a90
// MS2-PIN: ??_GContextMenu@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b81c0
// MS2-PIN: ??_GContextMenuBuiltInItems@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8310
// MS2-PIN: ??_GContextMenuClipboardItems@fl_ui@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8460
// MS2-PIN: ??_GContextMenu@fl_ui@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8220
// MS2-PIN: ??_GContextMenuBuiltInItems@fl_ui@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8370
// MS2-PIN: ??_GContextMenuClipboardItems@fl_ui@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b84c0
// MS2-PIN: ??_GKeyLocation@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8640
// MS2-PIN: ??_GKeyboard@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8730
// MS2-PIN: ??_GMouse@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8850
// MS2-PIN: ??_GMouseCursor@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8940
// MS2-PIN: ??_GMultitouch@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8a30
// MS2-PIN: ??_GMultitouchInputMode@fl_ui@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424b8b20
