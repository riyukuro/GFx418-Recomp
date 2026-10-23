// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424abbe0-0x1424ad030 .text$mn
// MS2-RANGE: 0x1424ad870-0x1424bb1f0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_assupport.h"
#include "ms2/scaleform/include/gfx/gfx_fontlib.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/kernel/sf_utf8util.h"
#include "ms2/scaleform/include/render/render_twips.h"

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
// Bodies of the exe called here (not recovered yet), by their addresses.
// VM: the instance traits of Vector.<String>.
Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String& FUN_14250a6c0(Scaleform::GFx::AS3::VM& vm);

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

    // A Vector.<String> of the gestures the movie supports: only panning is reported.
    // @0x1424b96b0
    // MS2-FUNCTIONAL: the exe calls an out-of-line CheckFixed copy (0x14255b2d0); ours inlines it
    void Multitouch::supportedGesturesGet(SPtr<Instances::fl_vec::Vector_String>& result)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        UInt32 mask = vm.GetMovieImpl()->GetSupportedGesturesMask();
        InstanceTraits::fl_vec::Vector_String& itr = FUN_14250a6c0(vm);
        SPtr<Instances::fl_vec::Vector_String> v(itr.MakeInstanceS(itr));
        result.Pick(v.GetPtr());
        *v.GetRawPtr() = NULL;
        if (mask & 1)
        {
            ASString pan = vm.GetStringManager().CreateConstString("pan");
            Ptr<ASStringNode> node(pan.GetNode());
            VectorBase<Ptr<ASStringNode> >& v = result->V;
            if (v.CheckFixed())
                v.V.PushBack(node);
        }
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

// ---- fl_text: Font, TextLineMetrics ----
// Bodies of the exe called here (not recovered yet), by their addresses.
// The movie whose library an AS3 object's class came from.
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* pobj);
// MovieImpl::FindExportedResource.
bool FUN_14256ec50(Scaleform::GFx::MovieImpl* pmovie, Scaleform::GFx::MovieDefImpl* pdef, Scaleform::GFx::ResourceBindData* pdata,
                   const Scaleform::String& symbol);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // @0x1424abe80
    // MS2-FUNCTIONAL: written from the exe's control flow
    bool Font::AttachLibraryFont()
    {
        if (pFont)
            return false;
        ASVM& vm = static_cast<ASVM&>(GetVM());
        MovieDefImpl* pobjDef = FUN_14250d8f0(vm, this);
        if (!pobjDef || !GetTraits().IsAbcObject())
            return false;
        ASString name = GetTraits().GetQualifiedName(Traits::qnfWithDot);
        MovieImpl* pmovie = vm.GetMovieImpl();
        ResourceBindData data;
        if (!FUN_14256ec50(pmovie, pobjDef, &data, String(name.ToCStr())))
        {
            if (pmovie->GetStateBag()->GetLogState())
                pmovie->GetStateBag()->GetLogState()->LogScriptWarning("Attaching a font with class '%s' failed", name.ToCStr());
            return false;
        }
        if (data.pResource &&
            (data.pResource->GetResourceTypeCode() & Resource::RT_TypeCode_Mask) == Resource::MakeTypeCode(Resource::RT_Font))
            pFont = static_cast<FontResource*>(data.pResource.GetPtr())->GetFont();
        return false;
    }

    // @0x1424aced0
    void Font::InitInstance(bool extCall)
    {
        if (!extCall)
            AttachLibraryFont();
    }

    // @0x1424b08d0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Font::fontNameGet(Value& result)
    {
        if (pFont)
            result = GetVM().GetStringManager().CreateString(pFont->GetName());
        else if (fontName.GetLength())
            result = fontName;
        else
            result.SetNull();
    }

    // @0x1424b09c0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Font::fontStyleGet(Value& result)
    {
        if (!pFont)
        {
            if (fontStyle.GetLength())
                result = fontStyle;
            else
                result.SetNull();
            return;
        }
        const char* pstyle;
        if (pFont->IsBold() && pFont->IsItalic())
            pstyle = "boldItalic";
        else if (pFont->IsBold())
            pstyle = "bold";
        else if (pFont->IsItalic())
            pstyle = "italic";
        else
            pstyle = "regular";
        result = GetVM().GetStringManager().CreateConstString(pstyle);
    }

    // @0x1424b0af0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Font::fontTypeGet(Value& result)
    {
        if (!pFont)
        {
            if (fontType.GetLength())
                result = fontType;
            else
                result.SetNull();
            return;
        }
        result = GetVM().GetStringManager().CreateConstString(pFont->IsDeviceFont() ? "device" : "embedded");
    }

    // @0x1424b2e80
    // MS2-FUNCTIONAL: written from the exe's control flow
    void Font::hasGlyphs(bool& result, const ASString& str)
    {
        if (!pFont)
        {
            result = false;
            return;
        }
        const char* p = str.ToCStr();
        const char* pend = p + str.GetSize();
        result = true;
        while (p < pend)
        {
            UInt32 ch = UTF8Util::DecodeNextChar(&p);
            if (pFont->GetGlyphIndex((UInt16)ch) < 0)
            {
                result = false;
                return;
            }
        }
    }

    // The exe converts the arguments and drops them: the metrics stay zero.
    // @0x1424abd70
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextLineMetrics::AS3Constructor(unsigned argc, const Value* argv)
    {
        Value::Number n;
        for (unsigned i = 0; i < argc && i < 6; ++i)
            argv[i].Convert2Number(n);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// ---- fl_text: TextField stage object ----
// Bodies of the exe called here (not recovered yet), by their addresses.
// AvmDisplayObj::AssignAS3Obj: makes pinst the AS3 object of pavm.
void FUN_1424edca0(Scaleform::GFx::AvmDisplayObjBase* pavm, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* pinst);
// MovieDefImpl::GetCharacterCreateInfo(rid) with its hidden return slot spelled out.
Scaleform::GFx::CharacterCreateInfo* FUN_1425cf500(Scaleform::GFx::MovieDefImpl* pdef, Scaleform::GFx::CharacterCreateInfo* pret,
                                                   const Scaleform::GFx::ResourceId* prid);
// TextField::SetText(text, html, notify).
void FUN_1425bd9a0(Scaleform::GFx::DisplayObject* ptf, const char* ptext, bool html, bool notify);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // ASVM::pMovieRoot: the AS3 movie root, used through its ASMovieRootBase part.
    static ASMovieRootBase* GetASRoot(VM& vm)
    {
        return *reinterpret_cast<ASMovieRootBase**>(reinterpret_cast<UByte*>(&vm) + 0x2d8);
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

    // @0x1424ac040
    GFx::DisplayObject* TextField::CreateStageObject()
    {
        if (!pDispObj)
        {
            ASMovieRootBase* proot = GetASRoot(GetVM());
            CharacterCreateInfo ccinfo;
            {
                ResourceId emptyTextId(0x10002);
                FUN_1425cf500(proot->GetMovieImpl()->pMainMovieDef, &ccinfo, &emptyTextId);
            }
            ccinfo.pBindDefImpl = GetCallerDefImpl(GetVM());
            DisplayObjectBase* pch = proot->pASSupport->CreateCharacterInstance(proot->GetMovieImpl(), ccinfo, NULL,
                                                                                 ResourceId(0x10002), CharacterDef::Unknown);
            if (pDispObj)
                pDispObj->Release();
            pDispObj.GetRawRef() = static_cast<GFx::DisplayObject*>(pch);
            FUN_1424edca0(pDispObj ? pDispObj->GetAvmObjImpl() : NULL, this);
        }
        return pDispObj;
    }

    // A text field made from script starts 100 x 100 pixels and empty.
    // @0x1424acee0
    void TextField::InitInstance(bool extCall)
    {
        if (extCall)
            return;
        TextField::CreateStageObject();
        GFx::DisplayObject* ptf = pDispObj;
        ptf->SetWidth(100);
        ptf->SetHeight(100);
        FUN_1425bd9a0(ptf, "", true, true);
    }
}}

}}} // namespace Scaleform::GFx::AS3



// ---- fl_text: TextField / TextSnapshot natives forwarding to the display side ----
// Bodies of the exe called here (not recovered yet), by their addresses. The display TextField, its document view
// (TextField+0xe0) and the static text snapshot data (TextSnapshot+0x38) are opaque here.
int      FUN_1425b7e70(void* ptf);                      // TextField::GetCaretIndex
bool     FUN_1425b9b50(void* ptf);                      // TextField::IsSelectable
int      FUN_1425b7df0(void* ptf);                      // TextField::GetBeginIndex
int      FUN_1425b8220(void* ptf);                      // TextField::GetEndIndex
Scaleform::UInt32 FUN_1425b9360(void* ptf);                      // TextField::GetTextColor32
double   FUN_1425b93d0(void* ptf);                      // TextField::GetTextHeight
double   FUN_1425b9400(void* ptf);                      // TextField::GetTextWidth
void     FUN_1425bc060(void* ptf);                      // TextField::SetDirtyFlag
unsigned FUN_142611f40(void* pdoc);                     // DocView::GetBottomVScroll
unsigned FUN_1426130f0(void* pdoc);                     // DocView::GetMaxVScroll
unsigned FUN_142613550(void* pdoc);                     // DocView::GetVScrollOffset
unsigned FUN_142613000(void* pdoc);                     // DocView::GetLinesCount
unsigned FUN_142613030(void* pdoc);                     // DocView::GetMaxHScroll (twips)
unsigned FUN_142612b50(void* pdoc);                     // DocView::GetHScrollOffset (twips)
bool     FUN_142615390(void* pdoc, unsigned long long twips);  // DocView::SetHScrollOffset
bool     FUN_142615670(void* pdoc, unsigned line);      // DocView::SetVScrollOffset
unsigned long long FUN_142613290(void* pdoc, unsigned long long pos);       // DocView::GetParagraphLength
unsigned long long FUN_142612af0(void* pdoc, unsigned long long pos);       // DocView::GetFirstCharInParagraph
unsigned FUN_142612c50(void* pdoc, unsigned long long pos);                 // DocView::GetLineIndexOfChar
unsigned long long FUN_142612cb0(void* pdoc, unsigned line, bool* phasNewLine);  // DocView::GetLineLength
unsigned long long FUN_142612e80(void* pdoc, unsigned line);                // DocView::GetLineOffset
unsigned long long FUN_142612240(void* pdoc, float x, float y);             // DocView::GetCharIndexAtPoint
unsigned FUN_142612bd0(void* pdoc, float x, float y);                       // DocView::GetLineIndexAtPoint
bool     FUN_142611ff0(void* pdoc, Scaleform::Render::RectF* prect, unsigned long long pos);  // DocView::GetCharBoundaries
unsigned long long FUN_142598a50(void* ptext);          // StyledText::GetLength
unsigned long long FUN_1425e1360(void* psnap);          // StaticTextSnapshotData::GetCharCount
bool     FUN_1425e1bc0(void* psnap, unsigned long long start, unsigned long long end);  // ::IsSelected
int      FUN_1425e1840(void* psnap, float x, float y, float closeDist);              // ::HitTestTextNearPos
void     FUN_1425e2b40(void* psnap, const Scaleform::UInt32* pcolor);                         // ::SetSelectColor

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // Display text field, its document view and that view's styled text.
    static inline void* DisplayTextField(Instances::fl_display::DisplayObject* p) { return p->pDispObj.GetPtr(); }
    static inline void* DocViewOf(void* ptf)                { return *(void**)((UByte*)ptf + 0xe0); }
    // Pixels <-> twips.
    static const double TwipsPerPixel = 20.0;
    static const double PixelsPerTwip = 0.05;

    // @0x1424afe10
    void TextField::bottomScrollVGet(SInt32& result)
    {
        result = (SInt32)FUN_142611f40(DocViewOf(DisplayTextField(this))) + 1;
    }

    // @0x1424afe60
    void TextField::caretIndexGet(SInt32& result)
    {
        result = FUN_1425b7e70(DisplayTextField(this));
    }

    // @0x1424b0df0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getCharIndexAtPoint(SInt32& result, Value::Number x, Value::Number y)
    {
        UPInt pos = (UPInt)FUN_142612240(DocViewOf(DisplayTextField(this)), (float)(x * TwipsPerPixel),
                                         (float)(y * TwipsPerPixel));
        result = (pos == SF_MAX_UPINT) ? -1 : (SInt32)pos;
    }

    // @0x1424b0e40
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getFirstCharInParagraph(SInt32& result, SInt32 charIndex)
    {
        if (charIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt pos = (UPInt)FUN_142612af0(DocViewOf(DisplayTextField(this)), (unsigned)charIndex);
        result = (pos == SF_MAX_UPINT) ? -1 : (SInt32)pos;
    }

    // @0x1424b0ef0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getLineIndexAtPoint(SInt32& result, Value::Number x, Value::Number y)
    {
        unsigned line = FUN_142612bd0(DocViewOf(DisplayTextField(this)), (float)(x * TwipsPerPixel),
                                      (float)(y * TwipsPerPixel));
        result = (line == ~0u) ? -1 : (SInt32)line;
    }

    // @0x1424b0f40
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getLineIndexOfChar(SInt32& result, SInt32 charIndex)
    {
        if (charIndex < 0)
        {
            result = -1;
            return;
        }
        unsigned line = FUN_142612c50(DocViewOf(DisplayTextField(this)), (unsigned)charIndex);
        result = (line == ~0u) ? -1 : (SInt32)line;
    }

    // @0x1424b0f90
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getLineLength(SInt32& result, SInt32 lineIndex)
    {
        if (lineIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt len = (UPInt)FUN_142612cb0(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex, NULL);
        result = (len == SF_MAX_UPINT) ? -1 : (SInt32)len;
    }

    // @0x1424b1330
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getLineOffset(SInt32& result, SInt32 lineIndex)
    {
        if (lineIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt pos = (UPInt)FUN_142612e80(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex);
        result = (pos == SF_MAX_UPINT) ? -1 : (SInt32)pos;
    }

    // @0x1424b0c00
    // MS2-FUNCTIONAL: the exe builds each Number Value through a 16-byte union temp; ours stores it directly
    void TextField::getCharBoundaries(SPtr<Instances::fl_geom::Rectangle>& result, SInt32 charIndex)
    {
        Render::RectF bounds(0, 0, 0, 0);
        if (FUN_142611ff0(DocViewOf(DisplayTextField(this)), &bounds, (SPInt)charIndex))
        {
            Value params[] = {
                Value((Value::Number)Alg::IRound(TwipsToPixels(bounds.x1))),
                Value((Value::Number)Alg::IRound(TwipsToPixels(bounds.y1))),
                Value((Value::Number)Alg::IRound(TwipsToPixels(bounds.Width()))),
                Value((Value::Number)Alg::IRound(TwipsToPixels(bounds.Height())))
            };
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            asvm.ConstructInstance(result, asvm.RectangleClass, 4, params);
        }
    }

    // @0x1424b14d0
    void TextField::getParagraphLength(SInt32& result, SInt32 charIndex)
    {
        result = (SInt32)FUN_142613290(DocViewOf(DisplayTextField(this)), (SPInt)charIndex);
    }

    // @0x1424b30e0
    void TextField::lengthGet(SInt32& result)
    {
        result = (SInt32)FUN_142598a50(*(void**)((UByte*)DocViewOf(DisplayTextField(this)) + 0x10));
    }

    // @0x1424b3190
    void TextField::maxScrollHGet(SInt32& result)
    {
        result = (SInt32)(FUN_142613030(DocViewOf(DisplayTextField(this))) * PixelsPerTwip);
    }

    // @0x1424b31d0
    void TextField::maxScrollVGet(SInt32& result)
    {
        result = (SInt32)FUN_1426130f0(DocViewOf(DisplayTextField(this))) + 1;
    }

    // @0x1424b32c0
    void TextField::numLinesGet(SInt32& result)
    {
        result = (SInt32)FUN_142613000(DocViewOf(DisplayTextField(this)));
    }

    // @0x1424b3f70
    void TextField::scrollHGet(SInt32& result)
    {
        result = (SInt32)(FUN_142612b50(DocViewOf(DisplayTextField(this))) * PixelsPerTwip);
    }

    // @0x1424b3fb0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::scrollHSet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        FUN_142615390(DocViewOf(ptf), (unsigned long long)(SInt64)((value < 0 ? 0 : value) * TwipsPerPixel));
        FUN_1425bc060(ptf);
    }

    // @0x1424b4000
    void TextField::scrollVGet(SInt32& result)
    {
        result = (SInt32)FUN_142613550(DocViewOf(DisplayTextField(this))) + 1;
    }

    // @0x1424b4030
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::scrollVSet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        FUN_142615670(DocViewOf(ptf), (unsigned)((value < 1 ? 1 : value) - 1));
        FUN_1425bc060(ptf);
    }

    // @0x1424b4070
    void TextField::selectableGet(bool& result)
    {
        result = FUN_1425b9b50(DisplayTextField(this));
    }

    // @0x1424b40a0
    void TextField::selectionBeginIndexGet(SInt32& result)
    {
        result = FUN_1425b7df0(DisplayTextField(this));
    }

    // @0x1424b40c0
    void TextField::selectionEndIndexGet(SInt32& result)
    {
        result = FUN_1425b8220(DisplayTextField(this));
    }

    // @0x1424b4cd0
    void TextField::textColorGet(UInt32& result)
    {
        result = FUN_1425b9360(DisplayTextField(this));
    }

    // @0x1424b4e80
    void TextField::textHeightGet(Value::Number& result)
    {
        result = FUN_1425b93d0(DisplayTextField(this));
    }

    // @0x1424b4f00
    void TextField::textWidthGet(Value::Number& result)
    {
        result = FUN_1425b9400(DisplayTextField(this));
    }

    // @0x1424afe80
    void TextSnapshot::charCountGet(SInt32& result)
    {
        result = (SInt32)FUN_1425e1360(&SnapshotData);
    }

    // An empty or reversed range tests the single character at start.
    // @0x1424b1500
    void TextSnapshot::getSelected(bool& result, SInt32 start, SInt32 end)
    {
        if (end <= start)
            end = start + 1;
        result = FUN_1425e1bc0(&SnapshotData, (SPInt)start, (SPInt)end);
    }

    // @0x1424b2f20
    void TextSnapshot::hitTestTextNearPos(Value::Number& result, Value::Number x, Value::Number y, Value::Number closeDist)
    {
        result = FUN_1425e1840(&SnapshotData, (float)(x * TwipsPerPixel), (float)(y * TwipsPerPixel),
                               (float)(closeDist * TwipsPerPixel));
    }

    // The selection colour is always opaque.
    // @0x1424b4330
    void TextSnapshot::setSelectColor(const Value& result, UInt32 color)
    {
        SF_UNUSED(result);
        UInt32 c = color;
        ((UByte*)&c)[3] = 0xff;
        FUN_1425e2b40(&SnapshotData, &c);
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- fl_text: TextFormat string properties, TextField text and settings ----
void* FUN_1425b91e0(void* ptf, void* ptext, bool html);    // TextField::GetText (builds an ASString in *ptext)
void  FUN_1425bd9a0(void* ptf, const char* ptext, bool html, bool notifyVariable);  // TextField::SetTextValue
bool  FUN_1425b9b10(void* ptf);                             // TextField::IsReadOnly
bool  FUN_1425b9730(void* ptf);                             // TextField::HasStyleSheet
void  FUN_1424ae6b0(void* pobj, const void* ppara, const void* pfmt);  // fl_text::TextFormat::SetTextFormat (from Render::Text formats)
void  FUN_1424ac700(void* pobj, void* ppara, void* pfmt);              // fl_text::TextFormat::GetTextFormat (into Render::Text formats)
void  FUN_142584fc0(void* pstr, void* pheap);                          // StringDH::StringDH(MemoryHeap*)
void  FUN_1424aa0f0(void* pfmt);                                       // Render::Text::TextFormat destructor
void  FUN_142606690(void* ppara);                                      // Render::Text::ParagraphFormat destructor (FreeTabStops)
void* FUN_142607870(const void* pfmt, void* presult, const void* pother);   // Render::Text::TextFormat::Merge
void* FUN_1426076a0(const void* ppara, void* presult, const void* pother);  // Render::Text::ParagraphFormat::Merge
void  FUN_14259c250(void* pdoc, const void* pfmt);                     // StyledText::SetDefaultTextFormat
void  FUN_14259c170(void* pdoc, const void* ppara);                    // StyledText::SetDefaultParagraphFormat
bool  FUN_142612d50(void* pdoc, unsigned line, void* pmetrics);       // DocView::GetLineMetrics (LineMetrics in twips)
const wchar_t* FUN_142612f00(void* pdoc, unsigned line, unsigned long long* plen);  // DocView::GetLineText
void  FUN_1425bbd10(void* ptf, void* pcss);                            // TextField::SetCSSData
void  FUN_1425b72a0(void* ptf);                                        // TextField: rebuilds the style sheet's url zones
void  FUN_1425bec30(void* ptf);                                        // TextField::UpdateUrlStyles
namespace Scaleform { namespace GFx { namespace AS3 {
// vftable of AvmTextField::CSSHolder (the AS3 side's style sheet holder; deleting destructor exe 0x1424aa770)
extern void* const AvmTextFieldCSSHolder_vftable[];
}}}
void  FUN_14260df50(void* pdoc, const char* ptext, unsigned long long length);      // DocView::AppendText
void  FUN_1426150b0(void* pdoc);                            // DocView::SetAutoSizeX
void  FUN_1426150d0(void* pdoc);                            // DocView::SetAutoSizeY
void  FUN_142615910(void* pdoc);                            // DocView::SetWordWrap
void  FUN_14260e350(void* pdoc);                            // DocView::ClearWordWrap

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // TextFormat keeps its properties as Values; a string property reads back null while it is unset.
    static inline void GetStringProperty(ASString& result, const Instances::fl::Object* pobj, UPInt offset)
    {
        const Value& v = *(const Value*)((const UByte*)pobj + offset);
        if (v.IsNull())
            result.SetNull();
        else
            result = v.AsString();
    }

    // @0x1424af820
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextFormat::alignGet(ASString& result)
    {
        GetStringProperty(result, this, 0x38);
    }

    // @0x1424b0870
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextFormat::fontGet(ASString& result)
    {
        GetStringProperty(result, this, 0xd8);
    }

    // @0x1424b4c60
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextFormat::targetGet(ASString& result)
    {
        GetStringProperty(result, this, 0x200);
    }

    // @0x1424b5330
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextFormat::urlGet(ASString& result)
    {
        GetStringProperty(result, this, 0x240);
    }

    // The display field's flags (TextField+0xfc) and its document view's format flags (DocView+0x149).
    static inline UInt32& FieldFlags(void* ptf)  { return *(UInt32*)((UByte*)ptf + 0xfc); }
    static inline UByte&  ViewFlags(void* pdoc)  { return *((UByte*)pdoc + 0x149); }

    // The view's styled text (DocView+0x10, opaque here; its default paragraph and text formats at +0x30 / +0x38),
    // and the movie heap (MovieImpl vftable +0x178).
    static inline void* DocumentOf(void* ptf)   { return *(void**)((UByte*)DocViewOf(ptf) + 0x10); }
    static inline void* DefaultParaFormat(void* pdoc) { return *(void**)((UByte*)pdoc + 0x30); }
    static inline void* DefaultTextFormat(void* pdoc) { return *(void**)((UByte*)pdoc + 0x38); }
    static inline MemoryHeap* MovieHeapOf(MovieImpl* pmovie)
    {
        typedef MemoryHeap* (*GetHeapFn)(MovieImpl*);
        return ((GetHeapFn)(*(void***)pmovie)[0x178 / 8])(pmovie);
    }

    // Render::Text::TextFormat (0x48) and ParagraphFormat (0x20) as raw storage: their headers use the render-side
    // kernel, which does not mix with the AS3 one.
    struct TextFormatStorage
    {
        unsigned RefCount;
        void*    FontList;
        void*    FontListHeap;
        void*    Url;
        void*    UrlHeap;
        void*    pImageDesc;
        void*    pFontHandle;
        UInt32   ColorV;
        SInt16   LetterSpacing;
        UInt16   FontSize;
        UInt8    FormatFlags;
        UInt16   PresentMask;
    };
    struct ParagraphFormatStorage
    {
        unsigned  RefCount;
        unsigned* pTabStops;
        UInt16    BlockIndent;
        SInt16    Indent;
        SInt16    Leading;
        UInt16    LeftMargin;
        UInt16    RightMargin;
        UInt16    PresentMask;
    };
    static inline void InitTextFormat(TextFormatStorage& f, MemoryHeap* pheap)
    {
        f.RefCount = 1;
        FUN_142584fc0(&f.FontList, pheap);
        FUN_142584fc0(&f.Url, pheap);
        f.pImageDesc = NULL;
        f.pFontHandle = NULL;
        f.ColorV = 0xFF000000u;
        f.LetterSpacing = 0;
        f.FontSize = 0;
        f.FormatFlags = 0;
        f.PresentMask = 0;
    }
    static inline void InitParagraphFormat(ParagraphFormatStorage& p)
    {
        p.RefCount = 1;
        p.pTabStops = NULL;
        p.BlockIndent = 0;
        p.Indent = 0;
        p.Leading = 0;
        p.LeftMargin = 0;
        p.RightMargin = 0;
        p.PresentMask = 0;
    }

    // @0x1424affb0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::defaultTextFormatGet(SPtr<Instances::fl_text::TextFormat>& result)
    {
        void* pdoc = DocumentOf(DisplayTextField(this));
        void* ppara = DefaultParaFormat(pdoc);
        void* pfmt = DefaultTextFormat(pdoc);
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        asvm.ConstructInstance(result, asvm.TextFormatClass, 0, NULL);
        FUN_1424ae6b0(result.GetPtr(), ppara, pfmt);
    }

    // @0x1424b0020
    // MS2-FUNCTIONAL: written from the exe's control flow (format storage opaque; the exe inlines the destructors)
    void TextField::defaultTextFormatSet(const Value& result, Instances::fl_text::TextFormat* value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (FUN_1425b9730(ptf))
            return;
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        TextFormatStorage fmt;
        InitTextFormat(fmt, MovieHeapOf(asvm.GetMovieImpl()));
        ParagraphFormatStorage para;
        InitParagraphFormat(para);
        FUN_1424ac700(value, &para, &fmt);

        TextFormatStorage mergedFmt;
        FUN_14259c250(DocumentOf(ptf), FUN_142607870(DefaultTextFormat(DocumentOf(ptf)), &mergedFmt, &fmt));
        FieldFlags(ptf) |= 0x10000;
        FUN_1424aa0f0(&mergedFmt);

        ParagraphFormatStorage mergedPara;
        FUN_14259c170(DocumentOf(ptf), FUN_1426076a0(DefaultParaFormat(DocumentOf(ptf)), &mergedPara, &para));
        FieldFlags(ptf) |= 0x10000;
        FUN_142606690(&mergedPara);
        FUN_142606690(&para);
        FUN_1424aa0f0(&fmt);
    }

    // DocView::LineMetrics, in twips.
    struct DocLineMetrics
    {
        unsigned Width, Height;
        unsigned Ascent, Descent;
        int      FirstCharXOff;
        int      Leading;
    };
    // Whole pixels from twips: the integer division first, then rounded as a double.
    static inline Value::Number TwipsToWholePixels(unsigned twips) { return (Value::Number)Alg::IRound((double)(twips / 20)); }
    static inline Value::Number TwipsToWholePixels(int twips)      { return (Value::Number)Alg::IRound((double)(twips / 20)); }

    // @0x1424b1000
    // MS2-FUNCTIONAL: the exe builds each Number Value through a 16-byte union temp; ours stores it directly
    void TextField::getLineMetrics(SPtr<Instances::fl_text::TextLineMetrics>& result, SInt32 lineIndex)
    {
        DocLineMetrics metrics;
        if (FUN_142612d50(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex, &metrics))
        {
            Value params[] = {
                Value(TwipsToWholePixels(metrics.Ascent)),
                Value(TwipsToWholePixels(metrics.Descent)),
                Value(TwipsToWholePixels(metrics.Height)),
                Value(TwipsToWholePixels(metrics.Leading)),
                Value(TwipsToWholePixels(metrics.Width)),
                Value(TwipsToWholePixels(metrics.FirstCharXOff))
            };
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            SPtr<Class> cls = asvm.GetClass(StringDataPtr("flash.text.TextLineMetrics"));
            asvm.ConstructInstance(result, cls, 6, params);
        }
    }

    // @0x1424b1380
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::getLineText(ASString& result, SInt32 lineIndex)
    {
        unsigned long long len = 0;
        const wchar_t* ptext = FUN_142612f00(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex, &len);
        if (ptext)
        {
            String str;
            str.AppendString(ptext, (SPInt)len);
            result = GetVM().GetStringManager().CreateString(str.ToCStr(), str.GetSize());
        }
        else
            result = GetVM().GetStringManager().CreateConstString("");
    }

    // The display field's style sheet holder (TextField+0x108); the AS3 holder keeps the StyleSheet object at +0x40.
    struct AvmCSSHolder
    {
        void* const*                         vfptr;
        UByte                                Base[0x38];     // CSSHolderBase: url zones, styles flag
        SPtr<Instances::fl_text::StyleSheet> pASStyleSheet;  // +0x40
    };
    static inline AvmCSSHolder*& CSSDataOf(void* ptf) { return *(AvmCSSHolder**)((UByte*)ptf + 0x108); }

    // @0x1424b49a0
    // MS2-FUNCTIONAL: the exe reaches the field through its AvmTextField (same object)
    void TextField::styleSheetGet(SPtr<Instances::fl_text::StyleSheet>& result)
    {
        void* ptf = DisplayTextField(this);
        if (CSSDataOf(ptf) && CSSDataOf(ptf)->pASStyleSheet)
            result = CSSDataOf(ptf)->pASStyleSheet;
    }

    // @0x1424b4a50
    // MS2-FUNCTIONAL: written from the exe's control flow (the exe calls SPtr's assignment out of line)
    void TextField::styleSheetSet(const Value& result, Instances::fl_text::StyleSheet* value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (value)
        {
            if (!CSSDataOf(ptf))
            {
                AvmCSSHolder* pcss = (AvmCSSHolder*)Memory::Alloc(sizeof(AvmCSSHolder));
                if (pcss)
                {
                    memset(pcss, 0, sizeof(AvmCSSHolder));
                    pcss->vfptr = AvmTextFieldCSSHolder_vftable;
                }
                FUN_1425bbd10(ptf, pcss);
            }
            CSSDataOf(ptf)->pASStyleSheet = value;
            void* pkit = *(void**)((UByte*)DocViewOf(ptf) + 0xd8);
            if (pkit)
                *(UInt16*)((UByte*)pkit + 0xa0) |= 1;
            FUN_1425bc060(ptf);
        }
        else if (CSSDataOf(ptf) && CSSDataOf(ptf)->pASStyleSheet)
            CSSDataOf(ptf)->pASStyleSheet = NULL;
        FUN_1425b72a0(ptf);
        FUN_1425bec30(ptf);
        FieldFlags(ptf) |= 0x10000;
    }


    // Re-applies the auto-size mode to the document view after a layout setting changed; horizontal auto-sizing is
    // off while the text wraps.
    // @0x1424af5f0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextFieldUpdateAutoSize(TextField* pthis)
    {
        void* ptf = DisplayTextField(pthis);
        bool autoSize = (FieldFlags(ptf) & 1) != 0;
        void* pdoc = DocViewOf(ptf);
        if (autoSize && !(ViewFlags(pdoc) & 8))
            FUN_1426150b0(pdoc);
        else
            ViewFlags(pdoc) &= ~1;
        pdoc = DocViewOf(ptf);
        if (autoSize)
            FUN_1426150d0(pdoc);
        else
            ViewFlags(pdoc) &= ~2;
        FieldFlags(ptf) |= 0x2000;
        FUN_1425bc060(ptf);
    }

    // @0x1424af960
    void TextField::antiAliasTypeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (value == "normal")
            ViewFlags(DocViewOf(ptf)) &= ~0x40;
        else if (value == "advanced")
            ViewFlags(DocViewOf(ptf)) |= 0x40;
        FUN_1425bc060(ptf);
    }

    // A field with a style sheet ignores appended text.
    // @0x1424af9e0
    void TextField::appendText(const Value& result, const ASString& newText)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (FUN_1425b9730(ptf))
            return;
        FUN_14260df50(DocViewOf(ptf), newText.ToCStr(), SF_MAX_UPINT);
        FieldFlags(ptf) |= 0x10000;
        FUN_1425bc060(ptf);
    }

    // @0x1424b2f80
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::htmlTextGet(ASString& result)
    {
        void* text;
        FUN_1425b91e0(DisplayTextField(this), &text, true);
        ASString& s = *reinterpret_cast<ASString*>(&text);
        result = s;
        s.~ASString();
    }

    // @0x1424b3270
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::multilineSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        UByte& flags = ViewFlags(DocViewOf(ptf));
        if (((flags & 4) != 0) != value)
        {
            if (value)
                flags |= 4;
            else
                flags &= ~4;
            TextFieldUpdateAutoSize(this);
        }
        FUN_1425bc060(ptf);
    }

    // @0x1424b4e30
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::textGet(ASString& result)
    {
        void* text;
        FUN_1425b91e0(DisplayTextField(this), &text, false);
        ASString& s = *reinterpret_cast<ASString*>(&text);
        result = s;
        s.~ASString();
    }

    // @0x1424b4ea0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::textSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        FieldFlags(ptf) &= ~2u;
        ASString text(value);
        FUN_1425bd9a0(ptf, text.ToCStr(), false, true);
    }

    // @0x1424b51a0
    void TextField::typeGet(ASString& result)
    {
        result = GetVM().GetStringManager().CreateConstString(FUN_1425b9b10(DisplayTextField(this)) ? "dynamic" : "input");
    }

    // @0x1424b5440
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::wordWrapSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        void* pdoc = DocViewOf(ptf);
        if (((ViewFlags(pdoc) & 8) != 0) != value)
        {
            if (value)
                FUN_142615910(pdoc);
            else
                FUN_14260e350(pdoc);
            TextFieldUpdateAutoSize(this);
        }
        FUN_1425bc060(ptf);
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- fl_text: TextField / TextSnapshot string queries ----
const void* FUN_1425b90a0(void* ptf);                       // TextField::GetRestrict (its first member is the String)
void FUN_1425e1570(void* psnap, void* ptext);               // StaticTextSnapshotData::GetSelectedText (builds a String)
int  FUN_1425e1020(void* psnap, unsigned long long start, const char* ptext, bool caseSensitive);  // ::FindText

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // @0x1424af8d0
    void TextField::antiAliasTypeGet(ASString& result)
    {
        result = GetVM().GetStringManager().CreateConstString(
            (ViewFlags(DocViewOf(DisplayTextField(this))) & 0x40) ? "advanced" : "normal");
    }

    // An auto-sized field reports its alignment; an unknown alignment leaves the result alone.
    // @0x1424afa40
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::autoSizeGet(ASString& result)
    {
        void* ptf = DisplayTextField(this);
        const char* pmode;
        UPInt length;
        if (!(FieldFlags(ptf) & 1))
        {
            pmode = "none";
            length = 4;
        }
        else
        {
            switch (*((UByte*)DocViewOf(ptf) + 0x148) & 3)
            {
            case 0: pmode = "left"; length = 4; break;
            case 1: pmode = "right"; length = 5; break;
            case 2: pmode = "center"; length = 6; break;
            default: return;
            }
        }
        result = GetVM().GetStringManager().GetStringManager()->CreateConstString(pmode, length);
    }

    // @0x1424b3e70
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::restrictGet(ASString& result)
    {
        const String* prestrict = (const String*)FUN_1425b90a0(DisplayTextField(this));
        if (prestrict)
            result = GetVM().GetStringManager().CreateString(prestrict->ToCStr(), prestrict->GetSize());
        else
            result.SetNull();
    }

    // @0x1424b07e0
    void TextSnapshot::findText(SInt32& result, SInt32 beginIndex, const ASString& textToFind, bool caseSensitive)
    {
        String text(textToFind.ToCStr(), textToFind.GetSize());
        result = FUN_1425e1020(&SnapshotData, (SPInt)beginIndex, text.ToCStr(), caseSensitive);
    }

    // The exe ignores includeLineEndings.
    // @0x1424b1530
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextSnapshot::getSelectedText(ASString& result, bool includeLineEndings)
    {
        SF_UNUSED(includeLineEndings);
        void* buf;
        FUN_1425e1570(&SnapshotData, &buf);
        String& text = *reinterpret_cast<String*>(&buf);
        result = GetVM().GetStringManager().CreateString(text.ToCStr(), text.GetSize());
        text.~String();
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- fl_text: StyleSheet::parseCSS, TextFormat::tabStopsSet, TextSnapshot::getText ----
bool FUN_14260b7f0(void* pstyles, const char* pcss, unsigned length);   // Text::StyleManager::ParseCSS
void FUN_1425e1740(void* psnap, void* ptext, unsigned long long start, unsigned long long end, bool includeLineEndings);  // ::GetSubString (builds a String)
void* FUN_1425e0400(void* psnap);                           // StaticTextSnapshotData::StaticTextSnapshotData (0x28 bytes)
void  FUN_1425e0720(void* psnap, void* pstatic);            // StaticTextSnapshotData::Add (a StaticTextCharacter)
void  FUN_1424aa050(void* psnap);                           // StaticTextSnapshotData::~StaticTextSnapshotData

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // The style manager lives at +0x50; +0x78 records how the last load went (2 parsed, 3 failed).
    // @0x1424b32f0
    void StyleSheet::parseCSS(const Value& result, const ASString& css)
    {
        SF_UNUSED(result);
        if (FUN_14260b7f0((UByte*)this + 0x50, css.ToCStr(), css.GetSize()))
        {
            *(UInt32*)((UByte*)this + 0x78) = 2;
            static_cast<ASVM&>(GetVM()).GetMovieImpl()->Flags |= 0x80000;
        }
        else
            *(UInt32*)((UByte*)this + 0x78) = 3;
    }

    // @0x1424b4bf0
    void TextFormat::tabStopsSet(const Value& result, Instances::fl::Array* value)
    {
        SF_UNUSED(result);
        *(SPtr<Instances::fl::Array>*)((UByte*)this + 0x1f8) = value;
    }

    // An empty or reversed range reads the single character at beginIndex.
    // @0x1424b29e0
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextSnapshot::getText(ASString& result, SInt32 beginIndex, SInt32 endIndex, bool includeLineEndings)
    {
        if (endIndex <= beginIndex)
            endIndex = beginIndex + 1;
        void* buf;
        FUN_1425e1740(&SnapshotData, &buf, (SPInt)beginIndex, (SPInt)endIndex, includeLineEndings);
        String& text = *reinterpret_cast<String*>(&buf);
        result = GetVM().GetStringManager().GetStringManager()->CreateString(text.ToCStr(), text.GetSize());
        text.~String();
    }

    // @0x1424b4d00
    // MS2-FUNCTIONAL: written from the exe's control flow (snapshot data opaque)
    void StaticText::textGet(ASString& result)
    {
        void* pdispObj = pDispObj.GetPtr();
        void* pmem = GetVM().GetMemoryHeap()->Alloc(0x28, (const AllocInfo*)0);
        void* psnap = pmem ? FUN_1425e0400(pmem) : NULL;
        FUN_1425e0720(psnap, pdispObj);
        void* buf;
        FUN_1425e1740(psnap, &buf, 0, FUN_1425e1360(psnap), true);
        String& text = *reinterpret_cast<String*>(&buf);
        result = GetVM().GetStringManager().GetStringManager()->CreateString(text.ToCStr(), text.GetSize());
        text.~String();
        if (psnap)
        {
            FUN_1424aa050(psnap);
            Memory::Free(psnap);
        }
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- fl_text: TextField::autoSizeSet, typeSet ----
void* FUN_1425b7840(void* ptf, void** pkit);                // TextField::CreateEditorKit (returns a Ptr in *pkit)
void  FUN_14257dcb0(void* pkit);                            // drops a reference to the editor kit

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // Document view alignment bits (DocView+0x148, 0 left, 1 right, 2 center) and its reformat request
    // (DocView+0x14b bit 0).
    static inline UByte& ViewAlign(void* pdoc)    { return *((UByte*)pdoc + 0x148); }
    static inline void   RequestReformat(void* pdoc) { *((UByte*)pdoc + 0x14b) |= 1; }

    // An unknown mode turns auto-sizing on and keeps the alignment.
    // @0x1424afb10
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextField::autoSizeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        void* pdoc = DocViewOf(ptf);
        UInt32 oldFlags = FieldFlags(ptf);
        UByte oldAlign = ViewAlign(pdoc);
        if (value == "none")
        {
            FieldFlags(ptf) &= ~1u;
            ViewAlign(pdoc) &= ~3;
            RequestReformat(pdoc);
        }
        else
        {
            FieldFlags(ptf) |= 1;
            if (value == "left")
            {
                ViewAlign(pdoc) &= ~3;
                RequestReformat(pdoc);
            }
            else if (value == "right")
            {
                ViewAlign(pdoc) = (ViewAlign(pdoc) & ~2) | 1;
                RequestReformat(pdoc);
            }
            else if (value == "center")
            {
                ViewAlign(pdoc) = (ViewAlign(pdoc) & ~1) | 2;
                RequestReformat(pdoc);
            }
        }
        if ((oldAlign & 3) != (ViewAlign(DocViewOf(ptf)) & 3) || (oldFlags & 1) != (FieldFlags(ptf) & 1))
            TextFieldUpdateAutoSize(this);
        FUN_1425bc060(ptf);
    }

    // "dynamic" makes an existing editor read-only; "input" creates the editor (unless a style sheet is set) and makes
    // it writable.
    // @0x1424b5230
    void TextField::typeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (value == "dynamic")
        {
            void* pkit = *(void**)((UByte*)DocViewOf(ptf) + 0xd8);
            if (pkit)
                *(UInt16*)((UByte*)pkit + 0xa0) |= 1;
        }
        else if (value == "input" && !FUN_1425b9730(ptf))
        {
            void* ptmp;
            void* pkit = *(void**)FUN_1425b7840(ptf, &ptmp);
            if (ptmp)
                FUN_14257dcb0(ptmp);
            *(UInt16*)((UByte*)pkit + 0xa0) &= ~1;
        }
        RequestReformat(DocViewOf(ptf));
    }
}}

}}} // namespace Scaleform::GFx::AS3

// ---- fl_text: by-value overloads of the result-reference natives ----
// Each makes an empty result, fills it through the reference form and returns it.

// SPtr<Array>::operator=(const SPtr<Array>&), kept out of line by the exe.
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>& FUN_1424aa450(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>& dst, const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>& src);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // @0x1424b0be0
    SPtr<Instances::fl_geom::Rectangle> TextField::getCharBoundaries(SInt32 charIndex)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getCharBoundaries(result, charIndex);
        return result;
    }

    // At 0x1424b0ed0 (not in the function list).
    void TextField::getImageReference(SPtr<Instances::fl_display::DisplayObject>& result, const ASString& id)
    {
        SF_UNUSED2(result, id);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::getImageReference() is not implemented\n");
    }

    // @0x1424b0e90
    SPtr<Instances::fl_display::DisplayObject> TextField::getImageReference(const ASString& id)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        getImageReference(result, id);
        return result;
    }

    // @0x1424b0fe0
    SPtr<Instances::fl_text::TextLineMetrics> TextField::getLineMetrics(SInt32 lineIndex)
    {
        SPtr<Instances::fl_text::TextLineMetrics> result;
        getLineMetrics(result, lineIndex);
        return result;
    }

    // @0x1424b2ab0
    SPtr<Instances::fl_text::TextFormat> TextField::getTextFormat(SInt32 beginIndex, SInt32 endIndex)
    {
        SPtr<Instances::fl_text::TextFormat> result;
        getTextFormat(result, beginIndex, endIndex);
        return result;
    }

    // @0x1424b2ce0
    SPtr<Instances::fl::Array> TextSnapshot::getTextRunInfo(SInt32 beginIndex, SInt32 endIndex)
    {
        SPtr<Instances::fl::Array> result;
        getTextRunInfo(result, beginIndex, endIndex);
        return result;
    }

    // @0x1424b46f0
    SPtr<Instances::fl::Array> StyleSheet::styleNamesGet()
    {
        SPtr<Instances::fl::Array> result;
        styleNamesGet(result);
        return result;
    }

    // MS2-FUNCTIONAL: our styleSheetGet(result) is smaller than the exe's and gets inlined here; the exe calls it
    // @0x1424b4980
    SPtr<Instances::fl_text::StyleSheet> TextField::styleSheetGet()
    {
        SPtr<Instances::fl_text::StyleSheet> result;
        styleSheetGet(result);
        return result;
    }

    // At 0x1424b4bd0 (not in the function list).
    void TextFormat::tabStopsGet(SPtr<Instances::fl::Array>& result)
    {
        FUN_1424aa450(result, tabStops);
    }

    // @0x1424b4ba0
    SPtr<Instances::fl::Array> TextFormat::tabStopsGet()
    {
        SPtr<Instances::fl::Array> result;
        tabStopsGet(result);
        return result;
    }

    // @0x1424b4f60
    SPtr<Instances::fl_text::TextFormat> StyleSheet::transform(const Value& value)
    {
        SPtr<Instances::fl_text::TextFormat> result;
        transform(result, value);
        return result;
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
