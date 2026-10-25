// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424abbe0-0x1424ad030 .text$mn
// MS2-RANGE: 0x1424ad870-0x1424bb1f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_assupport.h"
#include "ms2/scaleform/include/gfx/gfx_fontlib.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/kernel/sf_utf8util.h"
#include "ms2/scaleform/include/render/render_twips.h"
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/render/text_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"
#include "ms2/scaleform/include/gfx/gfx_fontprovider.h"
#include "ms2/scaleform/include/kernel/sf_stringhash.h"

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
        , STRING_BEGIN("\xEF\x9C\xAA")
        , STRING_BREAK("\xEF\x9C\xB2")
        , STRING_CLEARDISPLAY("\xEF\x9C\xBA")
        , STRING_CLEARLINE("\xEF\x9C\xB9")
        , STRING_DELETE("\xEF\x9C\xA8")
        , STRING_DELETECHAR("\xEF\x9C\xBE")
        , STRING_DELETELINE("\xEF\x9C\xBC")
        , STRING_DOWNARROW("\xEF\x9C\x81")
        , STRING_END("\xEF\x9C\xAB")
        , STRING_EXECUTE("\xEF\x9D\x82")
        , STRING_F1("\xEF\x9C\x84")
        , STRING_F10("\xEF\x9C\x8D")
        , STRING_F11("\xEF\x9C\x8E")
        , STRING_F12("\xEF\x9C\x8F")
        , STRING_F13("\xEF\x9C\x90")
        , STRING_F14("\xEF\x9C\x91")
        , STRING_F15("\xEF\x9C\x92")
        , STRING_F16("\xEF\x9C\x93")
        , STRING_F17("\xEF\x9C\x94")
        , STRING_F18("\xEF\x9C\x95")
        , STRING_F19("\xEF\x9C\x96")
        , STRING_F2("\xEF\x9C\x85")
        , STRING_F20("\xEF\x9C\x97")
        , STRING_F21("\xEF\x9C\x98")
        , STRING_F22("\xEF\x9C\x99")
        , STRING_F23("\xEF\x9C\x9A")
        , STRING_F24("\xEF\x9C\x9B")
        , STRING_F25("\xEF\x9C\x9C")
        , STRING_F26("\xEF\x9C\x9D")
        , STRING_F27("\xEF\x9C\x9E")
        , STRING_F28("\xEF\x9C\x9F")
        , STRING_F29("\xEF\x9C\xA0")
        , STRING_F3("\xEF\x9C\x86")
        , STRING_F30("\xEF\x9C\xA1")
        , STRING_F31("\xEF\x9C\xA2")
        , STRING_F32("\xEF\x9C\xA3")
        , STRING_F33("\xEF\x9C\xA4")
        , STRING_F34("\xEF\x9C\xA5")
        , STRING_F35("\xEF\x9C\xA6")
        , STRING_F4("\xEF\x9C\x87")
        , STRING_F5("\xEF\x9C\x88")
        , STRING_F6("\xEF\x9C\x89")
        , STRING_F7("\xEF\x9C\x8A")
        , STRING_F8("\xEF\x9C\x8B")
        , STRING_F9("\xEF\x9C\x8C")
        , STRING_FIND("\xEF\x9D\x85")
        , STRING_HELP("\xEF\x9D\x86")
        , STRING_HOME("\xEF\x9C\xA9")
        , STRING_INSERT("\xEF\x9C\xA7")
        , STRING_INSERTCHAR("\xEF\x9C\xBD")
        , STRING_INSERTLINE("\xEF\x9C\xBB")
        , STRING_LEFTARROW("\xEF\x9C\x82")
        , STRING_MENU("\xEF\x9C\xB5")
        , STRING_MODESWITCH("\xEF\x9D\x87")
        , STRING_NEXT("\xEF\x9D\x80")
        , STRING_PAGEDOWN("\xEF\x9C\xAD")
        , STRING_PAGEUP("\xEF\x9C\xAC")
        , STRING_PAUSE("\xEF\x9C\xB0")
        , STRING_PREV("\xEF\x9C\xBF")
        , STRING_PRINT("\xEF\x9C\xB8")
        , STRING_PRINTSCREEN("\xEF\x9C\xAE")
        , STRING_REDO("\xEF\x9D\x84")
        , STRING_RESET("\xEF\x9C\xB3")
        , STRING_RIGHTARROW("\xEF\x9C\x83")
        , STRING_SCROLLLOCK("\xEF\x9C\xAF")
        , STRING_SELECT("\xEF\x9D\x81")
        , STRING_STOP("\xEF\x9C\xB4")
        , STRING_SYSREQ("\xEF\x9C\xB1")
        , STRING_SYSTEM("\xEF\x9C\xB7")
        , STRING_UNDO("\xEF\x9D\x83")
        , STRING_UPARROW("\xEF\x9C\x80")
        , STRING_USER("\xEF\x9C\xB6")
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
    // The exe tests the whole style mask first, so a bold-only or italic-only font reads "boldItalic" as well.
    void Font::fontStyleGet(Value& result)
    {
        if (pFont)
        {
            unsigned style = pFont->GetFontFlags();
            if (style & Render::Font::FF_Style_Mask)
                result = GetVM().GetStringManager().CreateConstString("boldItalic");
            else if (style & Render::Font::FF_Bold)
                result = GetVM().GetStringManager().CreateConstString("bold");
            else if (style & Render::Font::FF_Italic)
                result = GetVM().GetStringManager().CreateConstString("italic");
            else
                result = GetVM().GetStringManager().CreateConstString("regular");
        }
        else if (fontStyle.GetLength())
            result = fontStyle;
        else
            result.SetNull();
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
    // @0x1424abc10
    void TextFormat::AS3Constructor(unsigned argc, const Value* argv)
    {
        Instances::fl::Object::AS3Constructor(argc, argv);
        if (argc >= 1)  font.Assign(argv[0]);
        if (argc >= 2)  size.Assign(argv[1]);
        if (argc >= 3)  color.Assign(argv[2]);
        if (argc >= 4)  bold.Assign(argv[3]);
        if (argc >= 5)  italic.Assign(argv[4]);
        if (argc >= 6)  underline.Assign(argv[5]);
        if (argc >= 7)  url.Assign(argv[6]);
        if (argc >= 8)  target.Assign(argv[7]);
        if (argc >= 9)  align.Assign(argv[8]);
        if (argc >= 10) leftMargin.Assign(argv[9]);
        if (argc >= 11) rightMargin.Assign(argv[10]);
        if (argc >= 12) indent.Assign(argv[11]);
        if (argc >= 13) leading.Assign(argv[12]);
    }

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
    // written from the exe's control flow
    void TextField::getCharIndexAtPoint(SInt32& result, Value::Number x, Value::Number y)
    {
        UPInt pos = (UPInt)FUN_142612240(DocViewOf(DisplayTextField(this)), (float)(x * TwipsPerPixel),
                                         (float)(y * TwipsPerPixel));
        SInt32 index = -1;
        if (pos != SF_MAX_UPINT)
            index = (SInt32)pos;
        result = index;
    }

    // @0x1424b0e40
    // written from the exe's control flow
    void TextField::getFirstCharInParagraph(SInt32& result, SInt32 charIndex)
    {
        if (charIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt pos = (UPInt)FUN_142612af0(DocViewOf(DisplayTextField(this)), (unsigned)charIndex);
        SInt32 index = -1;
        if (pos != SF_MAX_UPINT)
            index = (SInt32)pos;
        result = index;
    }

    // @0x1424b0ef0
    // written from the exe's control flow
    void TextField::getLineIndexAtPoint(SInt32& result, Value::Number x, Value::Number y)
    {
        unsigned line = FUN_142612bd0(DocViewOf(DisplayTextField(this)), (float)(x * TwipsPerPixel),
                                      (float)(y * TwipsPerPixel));
        SInt32 index = -1;
        if (line != ~0u)
            index = (SInt32)line;
        result = index;
    }

    // @0x1424b0f40
    // written from the exe's control flow
    void TextField::getLineIndexOfChar(SInt32& result, SInt32 charIndex)
    {
        if (charIndex < 0)
        {
            result = -1;
            return;
        }
        unsigned line = FUN_142612c50(DocViewOf(DisplayTextField(this)), (unsigned)charIndex);
        SInt32 index = -1;
        if (line != ~0u)
            index = (SInt32)line;
        result = index;
    }

    // @0x1424b0f90
    // written from the exe's control flow
    void TextField::getLineLength(SInt32& result, SInt32 lineIndex)
    {
        if (lineIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt len = (UPInt)FUN_142612cb0(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex, NULL);
        SInt32 index = -1;
        if (len != SF_MAX_UPINT)
            index = (SInt32)len;
        result = index;
    }

    // @0x1424b1330
    // written from the exe's control flow
    void TextField::getLineOffset(SInt32& result, SInt32 lineIndex)
    {
        if (lineIndex < 0)
        {
            result = -1;
            return;
        }
        UPInt pos = (UPInt)FUN_142612e80(DocViewOf(DisplayTextField(this)), (unsigned)lineIndex);
        SInt32 index = -1;
        if (pos != SF_MAX_UPINT)
            index = (SInt32)pos;
        result = index;
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
const Scaleform::String& FUN_142606750(const void* pfmt);              // Render::Text::TextFormat::GetFontList
const unsigned* FUN_142606b20(const void* ppara, unsigned* pcount);    // Render::Text::ParagraphFormat::GetTabStops
void  FUN_142607d90(void* pfmt, bool v);                               // Render::Text::TextFormat::SetBold
void  FUN_1426082a0(void* pfmt, bool v);                               // Render::Text::TextFormat::SetItalic
void  FUN_1426084d0(void* pfmt, bool v);                               // Render::Text::TextFormat::SetUnderline
void  FUN_142608330(void* pfmt, bool v);                               // Render::Text::TextFormat::SetKerning
void  FUN_142607f40(void* pfmt, const char* pstr, unsigned long long len);  // Render::Text::TextFormat::SetFontList
void  FUN_142608530(void* pfmt, const char* pstr, unsigned long long len);  // Render::Text::TextFormat::SetUrl
void  FUN_142605c10(void* ppara, unsigned n);                          // Render::Text::ParagraphFormat::AllocTabStops
void  FUN_1426084b0(void* ppara, unsigned i, unsigned v);              // Render::Text::ParagraphFormat::SetTabStopsElement
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

    // Render::Text::ParagraphFormat present bits (+0x1a), alignment in bits 9-10 and bullet in bit 15.
    enum
    {
        Para_Alignment = 0x01, Para_BlockIndent = 0x02, Para_Indent = 0x04, Para_Leading = 0x08,
        Para_LeftMargin = 0x10, Para_RightMargin = 0x20, Para_TabStops = 0x40, Para_Bullet = 0x80,
        Para_AlignMask = 0x600, Para_AlignShift = 9, Para_BulletOn = 0x8000
    };
    enum { Align_Left, Align_Right, Align_Justify, Align_Center };
    // Render::Text::TextFormat present bits (+0x42) and format flags (+0x40).
    enum
    {
        Fmt_Color = 0x01, Fmt_LetterSpacing = 0x02, Fmt_FontList = 0x04, Fmt_FontSize = 0x08, Fmt_Bold = 0x10,
        Fmt_Italic = 0x20, Fmt_Underline = 0x40, Fmt_Kerning = 0x80, Fmt_Url = 0x100, Fmt_FontHandle = 0x1000
    };
    enum { Flag_Bold = 0x01, Flag_Italic = 0x02, Flag_Underline = 0x04, Flag_Kerning = 0x08 };

    static SF_INLINE void SetParaAlignment(ParagraphFormatStorage& p, unsigned a)
    {
        p.PresentMask = (UInt16)((p.PresentMask & ~Para_AlignMask) | (a << Para_AlignShift) | Para_Alignment);
    }
    // A twips value of a pixel count kept within 0..720 (lo = 0) or -720..720 (lo = -720).
    static SF_INLINE SInt16 ClampPixels(SInt32 v, SInt32 lo)
    {
        if (v < lo)
            return (SInt16)lo;
        if (v > 720)
            return 720;
        return (SInt16)v;
    }

    // MS2-FUNCTIONAL: written from the exe's control flow (render formats kept as raw storage here)
    // @0x1424ac700
    void TextFormat::GetTextFormat(Render::Text::ParagraphFormat* parafmt, Render::Text::TextFormat* fmt)
    {
        ParagraphFormatStorage& para = *reinterpret_cast<ParagraphFormatStorage*>(parafmt);
        TextFormatStorage& tf = *reinterpret_cast<TextFormatStorage*>(fmt);
        StringManager& sm = GetVM().GetStringManager();
        SInt32 iv;
        UInt32 uv;
        Value::Number nv;

        if (!align.IsNullOrUndefined())
        {
            ASString str = sm.CreateEmptyString();
            align.Convert2String(str);
            const char* s = str.ToCStr();
            if (!strcmp(s, "left"))
                SetParaAlignment(para, Align_Left);
            else if (!strcmp(s, "right"))
                SetParaAlignment(para, Align_Right);
            else if (!strcmp(s, "center"))
                SetParaAlignment(para, Align_Center);
            else if (!strcmp(s, "justify"))
                SetParaAlignment(para, Align_Justify);
            else
                para.PresentMask &= ~(Para_AlignMask | Para_Alignment);
        }

        if (blockIndent.IsNullOrUndefined())
        {
            para.PresentMask &= ~Para_BlockIndent;
            para.BlockIndent = 0;
        }
        else
        {
            blockIndent.Convert2Int32(iv);
            para.PresentMask |= Para_BlockIndent;
            para.BlockIndent = (UInt16)ClampPixels(iv, 0);
        }

        if (bold.IsNullOrUndefined())
        {
            tf.FormatFlags &= ~Flag_Bold;
            tf.PresentMask &= ~Fmt_Bold;
        }
        else
            FUN_142607d90(fmt, bold.Convert2Boolean());
        if (italic.IsNullOrUndefined())
        {
            tf.FormatFlags &= ~Flag_Italic;
            tf.PresentMask &= ~Fmt_Italic;
        }
        else
            FUN_1426082a0(fmt, italic.Convert2Boolean());
        if (underline.IsNullOrUndefined())
        {
            tf.FormatFlags &= ~Flag_Underline;
            tf.PresentMask &= ~Fmt_Underline;
        }
        else
            FUN_1426084d0(fmt, underline.Convert2Boolean());

        if (bullet.IsNullOrUndefined())
            para.PresentMask &= ~(Para_BulletOn | Para_Bullet);
        else
        {
            if (bullet.Convert2Boolean())
                para.PresentMask |= Para_BulletOn;
            else
                para.PresentMask &= ~Para_BulletOn;
            para.PresentMask |= Para_Bullet;
        }

        if (color.IsNullOrUndefined())
        {
            tf.PresentMask &= ~Fmt_Color;
            tf.ColorV = 0xFF000000u;
        }
        else
        {
            color.Convert2UInt32(uv);
            tf.PresentMask |= Fmt_Color;
            tf.ColorV = (tf.ColorV & 0xFF000000u) | (uv & 0xFFFFFFu);
        }

        if (font.IsNullOrUndefined())
            tf.PresentMask &= ~(Fmt_FontList | Fmt_FontHandle);
        else
        {
            ASString str = sm.CreateEmptyString();
            font.Convert2String(str);
            FUN_142607f40(fmt, str.ToCStr(), ~0ull);
        }

        if (indent.IsNullOrUndefined())
        {
            para.Indent = 0;
            para.PresentMask &= ~Para_Indent;
        }
        else
        {
            indent.Convert2Int32(iv);
            para.PresentMask |= Para_Indent;
            para.Indent = ClampPixels(iv, -720);
        }
        if (leading.IsNullOrUndefined())
        {
            para.Leading = 0;
            para.PresentMask &= ~Para_Leading;
        }
        else
        {
            leading.Convert2Int32(iv);
            para.PresentMask |= Para_Leading;
            para.Leading = ClampPixels(iv, -720);
        }
        if (leftMargin.IsNullOrUndefined())
        {
            para.LeftMargin = 0;
            para.PresentMask &= ~Para_LeftMargin;
        }
        else
        {
            leftMargin.Convert2Int32(iv);
            para.PresentMask |= Para_LeftMargin;
            para.LeftMargin = (UInt16)ClampPixels(iv, 0);
        }
        if (rightMargin.IsNullOrUndefined())
        {
            para.RightMargin = 0;
            para.PresentMask &= ~Para_RightMargin;
        }
        else
        {
            rightMargin.Convert2Int32(iv);
            para.PresentMask |= Para_RightMargin;
            para.RightMargin = (UInt16)ClampPixels(iv, 0);
        }

        if (size.IsNullOrUndefined())
        {
            tf.FontSize = 0;
            tf.PresentMask &= ~Fmt_FontSize;
        }
        else
        {
            // pixels to twips; sizes of 128 and more are 127
            size.Convert2Int32(iv);
            if (iv >= 0)
            {
                tf.PresentMask |= Fmt_FontSize;
                if (iv >= 128)
                    tf.FontSize = 127 * 20;
                else if ((float)iv >= 3276.8f)
                    tf.FontSize = 0xFFFF;
                else
                    tf.FontSize = (UInt16)(int)((float)iv * 20.0f);
            }
        }

        if (url.IsNullOrUndefined())
        {
            reinterpret_cast<String*>(&tf.Url)->Clear();
            tf.PresentMask &= ~Fmt_Url;
        }
        else
        {
            ASString str = sm.CreateEmptyString();
            url.Convert2String(str);
            FUN_142608530(fmt, str.ToCStr(), ~0ull);
        }

        if (letterSpacing.IsNullOrUndefined())
        {
            tf.PresentMask &= ~Fmt_LetterSpacing;
            tf.LetterSpacing = 0;
        }
        else
        {
            letterSpacing.Convert2NumberInline(nv);
            if (nv < -720.0 || nv > 720.0)
                nv = nv < -720.0 ? -720.0 : 720.0;
            tf.PresentMask |= Fmt_LetterSpacing;
            tf.LetterSpacing = (SInt16)(int)((float)nv * 20.0f);
        }

        if (kerning.IsNullOrUndefined())
        {
            tf.FormatFlags &= ~Flag_Kerning;
            tf.PresentMask &= ~Fmt_Kerning;
        }
        else
            FUN_142608330(fmt, kerning.Convert2Boolean());

        if (!tabStops)
        {
            FUN_142606690(parafmt);
            para.PresentMask &= ~Para_TabStops;
        }
        else
        {
            UPInt n = tabStops->GetSize();
            FUN_142605c10(parafmt, (unsigned)n);
            para.PresentMask |= Para_TabStops;
            for (UPInt i = 0; i < n; ++i)
            {
                tabStops->At(i).Convert2NumberInline(nv);
                FUN_1426084b0(parafmt, (unsigned)i, (unsigned)(SInt64)nv);
            }
        }
    }

    // MS2-FUNCTIONAL: written from the exe's control flow (render formats kept as raw storage here)
    // @0x1424ae6b0
    void TextFormat::SetTextFormat(const Render::Text::ParagraphFormat* parafmt, const Render::Text::TextFormat* fmt)
    {
        const ParagraphFormatStorage& para = *reinterpret_cast<const ParagraphFormatStorage*>(parafmt);
        const TextFormatStorage& tf = *reinterpret_cast<const TextFormatStorage*>(fmt);
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        ASString nullStr = sm.CreateNullString();
        Value nullValue = Value::GetNull();

        if (para.PresentMask & Para_Alignment)
        {
            const char* palign = "left";
            switch ((para.PresentMask & Para_AlignMask) >> Para_AlignShift)
            {
            case Align_Right:   palign = "right"; break;
            case Align_Justify: palign = "justify"; break;
            case Align_Center:  palign = "center"; break;
            }
            align = sm.CreateString(palign);
        }
        else
            align = nullStr;

        blockIndent = (para.PresentMask & Para_BlockIndent) ? Value((UInt32)para.BlockIndent) : nullValue;
        bold = (tf.PresentMask & Fmt_Bold) ? Value((tf.FormatFlags & Flag_Bold) != 0) : nullValue;
        italic = (tf.PresentMask & Fmt_Italic) ? Value((tf.FormatFlags & Flag_Italic) != 0) : nullValue;
        underline = (tf.PresentMask & Fmt_Underline) ? Value((tf.FormatFlags & Flag_Underline) != 0) : nullValue;
        bullet = (para.PresentMask & Para_Bullet)
            ? Value((para.PresentMask & (Para_BulletOn | Para_Bullet)) == (Para_BulletOn | Para_Bullet)) : nullValue;
        color = (tf.PresentMask & Fmt_Color) ? Value((Value::Number)(tf.ColorV & 0xFFFFFFu)) : nullValue;
        if (tf.PresentMask & Fmt_FontList)
        {
            const String& fonts = FUN_142606750(fmt);
            font = sm.CreateString(fonts.ToCStr(), fonts.GetSize());
        }
        else
            font = nullStr;
        indent = (para.PresentMask & Para_Indent) ? Value((Value::Number)para.Indent) : nullValue;
        kerning = (tf.PresentMask & Fmt_Kerning) ? Value((tf.FormatFlags & Flag_Kerning) != 0) : nullValue;
        leading = (para.PresentMask & Para_Leading) ? Value((Value::Number)para.Leading) : nullValue;
        leftMargin = (para.PresentMask & Para_LeftMargin) ? Value((Value::Number)para.LeftMargin) : nullValue;
        letterSpacing = (tf.PresentMask & Fmt_LetterSpacing)
            ? Value((Value::Number)(SInt16)(tf.LetterSpacing / 20)) : nullValue;
        rightMargin = (para.PresentMask & Para_RightMargin) ? Value((Value::Number)para.RightMargin) : nullValue;
        size = (tf.PresentMask & Fmt_FontSize) ? Value((Value::Number)((float)tf.FontSize * 0.05f)) : nullValue;
        target = nullStr;
        const String& purl = *reinterpret_cast<const String*>(&tf.Url);
        if ((tf.PresentMask & Fmt_Url) && purl.GetLength() != 0)
            url = sm.CreateString(purl.ToCStr(), purl.GetSize());
        else
            url = nullStr;

        if (para.PresentMask & Para_TabStops)
        {
            unsigned n = 0;
            const unsigned* pstops = FUN_142606b20(parafmt, &n);
            SPtr<Instances::fl::Array> arr = vm.MakeArray();
            arr->Resize(n);
            for (unsigned i = 0; i < n; ++i)
                arr->Set(i, Value((Value::Number)pstops[i]));
            tabStops = arr;
        }
        else
            tabStops = NULL;
    }

    // @0x1424affb0
    void TextField::defaultTextFormatGet(SPtr<Instances::fl_text::TextFormat>& result)
    {
        void* pdoc = DocumentOf(DisplayTextField(this));
        void* pfmt = DefaultTextFormat(pdoc);
        void* ppara = DefaultParaFormat(pdoc);
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        asvm.ConstructInstance(result, asvm.TextFormatClass, 0, NULL);
        result->SetTextFormat(reinterpret_cast<const Render::Text::ParagraphFormat*>(ppara),
                              reinterpret_cast<const Render::Text::TextFormat*>(pfmt));
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
        value->GetTextFormat(reinterpret_cast<Render::Text::ParagraphFormat*>(&para),
                             reinterpret_cast<Render::Text::TextFormat*>(&fmt));

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
void FUN_1425e1570(void* psnap, void* ptext, bool includeLineEndings);           // StaticTextSnapshotData::GetSelectedText (builds a String)
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

    // @0x1424b1530
    // MS2-FUNCTIONAL: written from the exe's control flow
    void TextSnapshot::getSelectedText(ASString& result, bool includeLineEndings)
    {
        void* buf;
        FUN_1425e1570(&SnapshotData, &buf, includeLineEndings);
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

    // Writes the dynamic properties of a style object as CSS declarations: "name:value;" each, with the
    // camel-cased TextFormat names spelled the CSS way.
    // MS2-FUNCTIONAL: register allocation and loop shape differ (the exe keeps the slot index in edi across the property reads)
    // @0x1424ae370
    void AppendCSSDeclarations(String& css, AS3::Object* pstyle)
    {
        for (GlobalSlotIndex ind = pstyle->GetNextDynPropIndex(GlobalSlotIndex(0)); ind.IsValid();
             ind = pstyle->GetNextDynPropIndex(ind))
        {
            Value name, value;
            pstyle->GetNextPropertyName(name, ind);
            pstyle->GetNextPropertyValue(value, ind);
            if (!name.IsString())
                continue;

            ASString    nameStr = name.AsString();
            const char* pname   = nameStr.ToCStr();
            const char* pcss;
            if (!strcmp(pname, "fontFamily"))           pcss = "font-family";
            else if (!strcmp(pname, "fontSize"))        pcss = "font-size";
            else if (!strcmp(pname, "fontStyle"))       pcss = "font-style";
            else if (!strcmp(pname, "fontWeight"))      pcss = "font-weight";
            else if (!strcmp(pname, "letterSpacing"))   pcss = "letter-spacing";
            else if (!strcmp(pname, "marginLeft"))      pcss = "margin-left";
            else if (!strcmp(pname, "marginRight"))     pcss = "margin-right";
            else if (!strcmp(pname, "textAlign"))       pcss = "text-align";
            else if (!strcmp(pname, "textDecoration"))  pcss = "text-decoration";
            else if (!strcmp(pname, "textIndent"))      pcss = "text-indent";
            else                                        pcss = pname;
            css.AppendString(pcss);
            css.AppendString(":");
            StringBuffer buf;
            value.Convert2String(buf);
            css.AppendString(buf.ToCStr());
            css.AppendString(";");
        }
    }

    // One property of the getStyle result object, named in the public namespace.
    static SF_INLINE void SetStyleProperty(Instances::fl::Object* pobj, Instances::Namespace& ns, const ASString& name,
                                           const Value& v)
    {
        pobj->SetProperty(Multiname(ns, Value(name)), v);
    }

    // The style named by name (".name" a class, else a tag) as an object of CSS property strings and numbers,
    // or null when there is none.
    // MS2-FUNCTIONAL: written from the exe's control flow; temporaries are released in a different order
    // @0x1424b15e0
    void StyleSheet::getStyle(SPtr<Instances::fl::Object>& result, const ASString& name)
    {
        const char* pname = name.ToCStr();
        const Render::Text::Style* pstyle;
        if (name.GetSize() != 0 && pname[0] == '.')
            pstyle = CSS.GetStyle(Text::StyleManager::CSS_Class, pname + 1, name.GetSize() - 1);
        else
            pstyle = CSS.GetStyle(Text::StyleManager::CSS_Tag, pname);
        if (!pstyle)
        {
            result = NULL;
            return;
        }

        VM& vm = GetVM();
        SPtr<Instances::fl::Object> pobj = vm.MakeObject();
        StringManager& sm = vm.GetStringManager();
        Instances::Namespace& ns = vm.GetPublicNamespace();
        const TextFormatStorage& tf = *reinterpret_cast<const TextFormatStorage*>(pstyle);
        const ParagraphFormatStorage& para =
            *reinterpret_cast<const ParagraphFormatStorage*>(reinterpret_cast<const UByte*>(pstyle) + 0x48);

        if (tf.PresentMask & Fmt_Color)
        {
            static const char hex[] = "0123456789ABCDEF";
            String color;
            color.AppendChar('#');
            const UInt32 c = tf.ColorV;
            color.AppendChar(hex[((c >> 16) & 0xFF) >> 4]);
            color.AppendChar(hex[(c >> 16) & 0xF]);
            color.AppendChar(hex[((c >> 8) & 0xFF) >> 4]);
            color.AppendChar(hex[(c >> 8) & 0xF]);
            color.AppendChar(hex[(c & 0xFF) >> 4]);
            color.AppendChar(hex[c & 0xF]);
            SetStyleProperty(pobj, ns, sm.CreateString("color"),
                             Value(sm.CreateString(color.ToCStr(), color.GetSize())));
        }
        if (tf.PresentMask & Fmt_FontList)
        {
            const String& fonts = FUN_142606750(&tf);
            SetStyleProperty(pobj, ns, sm.CreateString("fontFamily"),
                             Value(sm.CreateString(fonts.ToCStr(), fonts.GetSize())));
        }
        if (tf.PresentMask & Fmt_FontSize)
            SetStyleProperty(pobj, ns, sm.CreateString("fontSize"),
                             Value((Value::Number)((float)tf.FontSize * 0.05f)));
        if (tf.PresentMask & Fmt_Italic)
            SetStyleProperty(pobj, ns, sm.CreateString("fontStyle"),
                             Value(sm.CreateString((tf.FormatFlags & Flag_Italic) ? "italic" : "normal")));
        if (tf.PresentMask & Fmt_Bold)
            SetStyleProperty(pobj, ns, sm.CreateString("fontWeight"),
                             Value(sm.CreateString((tf.FormatFlags & Flag_Bold) ? "bold" : "normal")));
        if (tf.PresentMask & Fmt_Kerning)
            SetStyleProperty(pobj, ns, sm.CreateString("kerning"),
                             Value(sm.CreateString((tf.FormatFlags & Flag_Kerning) ? "true" : "false")));
        if (para.PresentMask & Para_Leading)
            SetStyleProperty(pobj, ns, sm.CreateString("leading"), Value((SInt32)para.Leading));
        if (tf.PresentMask & Fmt_LetterSpacing)
            SetStyleProperty(pobj, ns, sm.CreateString("letterSpacing"),
                             Value((Value::Number)(SInt16)(tf.LetterSpacing / 20)));
        if (para.PresentMask & Para_LeftMargin)
            SetStyleProperty(pobj, ns, sm.CreateString("marginLeft"), Value((UInt32)para.LeftMargin));
        if (para.PresentMask & Para_RightMargin)
            SetStyleProperty(pobj, ns, sm.CreateString("marginRight"), Value((UInt32)para.RightMargin));
        if (para.PresentMask & Para_Alignment)
        {
            const char* align;
            switch (para.PresentMask & Para_AlignMask)
            {
            case 0:      align = "left"; break;
            case 0x600:  align = "center"; break;
            case 0x200:  align = "right"; break;
            default:     align = "justify"; break;
            }
            SetStyleProperty(pobj, ns, sm.CreateString("textAlign"), Value(sm.CreateString(align)));
        }
        if (tf.PresentMask & Fmt_Underline)
            SetStyleProperty(pobj, ns, sm.CreateString("textDecoration"),
                             Value(sm.CreateString((tf.FormatFlags & Flag_Underline) ? "underline" : "none")));
        if (para.PresentMask & Para_Indent)
            SetStyleProperty(pobj, ns, sm.CreateString("textIndent"), Value((SInt32)para.Indent));
        result = pobj;
    }

    // A null style object removes the style; otherwise the object is written out as a CSS rule and parsed in.
    // MS2-FUNCTIONAL: the exe tail-calls ClearStyle on two paths (ours selects the key type with sete); register allocation differs
    // @0x1424b43a0
    void StyleSheet::setStyle(const Value& result, const ASString& styleName, const Value& styleObject)
    {
        SF_UNUSED(result);
        if (styleName.IsEmpty())
            return;
        if (styleObject.IsObject() && !styleObject.GetObject())
        {
            if (!styleName.IsEmpty())
            {
                const char* pname = styleName.ToCStr();
                if (pname[0] == '.')
                    CSS.ClearStyle(Text::StyleManager::CSS_Class, pname);
                else
                    CSS.ClearStyle(Text::StyleManager::CSS_Tag, pname);
            }
            return;
        }
        if (!styleObject.IsObject())
            return;
        String css;
        css.AppendString(styleName.ToCStr());
        css.AppendChar('{');
        AppendCSSDeclarations(css, styleObject.GetObject());
        css.AppendChar('}');
        CSS.ParseCSS(css.ToCStr(), css.GetSize());
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

// ---- fl_text: TextField::replaceSelectedText, replaceText ----
unsigned long long FUN_1425bb810(void* ptf, const wchar_t* pstr, unsigned long long start, unsigned long long end,
                                 unsigned long long len);                       // TextField::ReplaceText
bool  FUN_1425996b0(void* ptext, const Scaleform::Render::Text::TextFormat** ppfmt,
                    const Scaleform::Render::Text::ParagraphFormat** pppara, unsigned long long pos);  // StyledText::GetTextAndParagraphFormat
void  FUN_142615410(void* pdoc, const Scaleform::Render::Text::ParagraphFormat* ppara,
                    unsigned long long start, unsigned long long end);          // DocView::SetParagraphFormat
void  FUN_142615640(void* pdoc, const Scaleform::Render::Text::TextFormat* pfmt,
                    unsigned long long start, unsigned long long end);          // DocView::SetTextFormat
unsigned long long FUN_142617990(void* pek);                                    // EditorKit::GetCursorPos
void  FUN_142619b80(void* pek, unsigned long long pos, bool selectionChange);   // EditorKit::SetCursorPos
bool  FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& base,
                    const Scaleform::GFx::AS3::ClassTraits::Traits& t);       // ClassTraits: t is base or derives from it
bool  FUN_142573d60(Scaleform::GFx::MovieImpl* pmovie, Scaleform::GFx::MovieDefImpl* pdef,
                    Scaleform::GFx::FontResource* pfont);                      // MovieImpl::RegisterFont
void  FUN_1425990d0(void* ptext, Scaleform::Render::Text::TextFormat* pdestFmt,
                    Scaleform::Render::Text::ParagraphFormat* pdestPara, unsigned long long start,
                    unsigned long long end);                                    // StyledText::GetTextAndParagraphFormat (range, merged)

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text
{
    // The styled text's default formats and the view's editor kit.
    static inline void* StyledTextOf(void* ptf) { return *(void**)((UByte*)DocViewOf(ptf) + 0x10); }
    static inline void* EditorKitOf(void* ptf)  { return *(void**)((UByte*)DocViewOf(ptf) + 0xd8); }

    // Replaces [begin, end) with the wide form of str, decoded into a stack buffer when it fits.
    static __forceinline void ReplaceTextUTF8(void* ptf, const ASString& str, unsigned len, UPInt begin, UPInt end)
    {
        wchar_t buf[0x400];
        if (len < 0x400)
        {
            UTF8Util::DecodeString(buf, str.ToCStr());
            FUN_1425bb810(ptf, buf, begin, end, SF_MAX_UPINT);
        }
        else
        {
            wchar_t* pbuf = (wchar_t*)Memory::Alloc((len + 1) * sizeof(wchar_t));
            UTF8Util::DecodeString(pbuf, str.ToCStr());
            FUN_1425bb810(ptf, pbuf, begin, end, SF_MAX_UPINT);
            Memory::Free(pbuf);
        }
    }

    // @0x1424b3a00
    void TextField::replaceSelectedText(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (FUN_1425b9730(ptf))
            return;
        const Render::Text::TextFormat*      pfmt  = *(const Render::Text::TextFormat**)((UByte*)StyledTextOf(ptf) + 0x38);
        const Render::Text::ParagraphFormat* ppara = *(const Render::Text::ParagraphFormat**)((UByte*)StyledTextOf(ptf) + 0x30);
        unsigned len = value.GetLength();
        void* pview = *(void**)((UByte*)EditorKitOf(ptf) + 0x10);
        UPInt selEnd = *(UPInt*)((UByte*)pview + 0x40);
        UPInt selBegin = *(UPInt*)((UByte*)pview + 0x38);
        UPInt begin = Alg::Min(selBegin, selEnd);
        UPInt end   = Alg::Max(selBegin, selEnd);
        ReplaceTextUTF8(ptf, value, len, begin, end);
        UPInt newEnd = begin + len;
        FUN_142619b80(EditorKitOf(ptf), newEnd, false);
        if (ppara)
            FUN_142615410(DocViewOf(ptf), ppara, begin, newEnd);
        if (pfmt)
            FUN_142615640(DocViewOf(ptf), pfmt, begin, newEnd);
        FUN_1425bc060(ptf);
    }

    // @0x1424b3bf0
    // MS2-FUNCTIONAL: register allocation differs (the view pointer lands in r8 instead of rcx/r10); same logic.
    void TextField::replaceText(const Value& result, SInt32 beginIndex, SInt32 endIndex, const ASString& newText)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (FUN_1425b9730(ptf))
            return;
        unsigned len = newText.GetLength();
        if (beginIndex < 0 || endIndex < 0 || (unsigned)beginIndex > (unsigned)endIndex)
            return;
        UPInt begin = (unsigned)beginIndex;
        UPInt docLen = FUN_142598a50(StyledTextOf(ptf));
        void* pdoc = DocViewOf(ptf);
        UPInt newLen = len - (UPInt)(unsigned)(endIndex - beginIndex) + docLen;
        void* ptext = *(void**)((UByte*)pdoc + 0x10);
        const Render::Text::TextFormat*      pfmt;
        const Render::Text::ParagraphFormat* ppara;
        if (begin >= docLen)
        {
            pfmt  = *(const Render::Text::TextFormat**)((UByte*)ptext + 0x38);
            ppara = *(const Render::Text::ParagraphFormat**)(*(UByte**)((UByte*)pdoc + 0x10) + 0x30);
        }
        else
            FUN_1425996b0(ptext, &pfmt, &ppara, begin);
        if (pfmt)
            pfmt->AddRef();
        if (ppara)
            ppara->AddRef();
        ReplaceTextUTF8(ptf, newText, len, begin, (unsigned)endIndex);
        void* pek = EditorKitOf(ptf);
        if (pek && FUN_142617990(pek) > newLen)
            FUN_142619b80(EditorKitOf(ptf), newLen, false);
        unsigned newEnd = (unsigned)beginIndex + len;
        if (ppara)
            FUN_142615410(DocViewOf(ptf), ppara, begin, newEnd);
        if (pfmt)
            FUN_142615640(DocViewOf(ptf), pfmt, begin, newEnd);
        if (pfmt)
            pfmt->Release();
        if (ppara)
            ppara->Release();
        FUN_1425bc060(ptf);
    }

    // @0x1424b2ad0
    void TextField::getTextFormat(SPtr<Instances::fl_text::TextFormat>& result, SInt32 beginIndex, SInt32 endIndex)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SInt32 begin = (beginIndex != -1) ? beginIndex : 0;
        SInt32 end   = (endIndex != -1) ? endIndex : 0x7FFFFFFF;
        SPtr<Instances::fl_text::TextFormat> pformat;
        asvm.ConstructInstance(pformat, asvm.TextFormatClass, 0, NULL);
        if (begin <= end)
        {
            Render::Text::TextFormat      fmt(MovieHeapOf(asvm.GetMovieImpl()));
            Render::Text::ParagraphFormat para;
            FUN_1425990d0(DocumentOf(DisplayTextField(this)), &fmt, &para, (SPInt)begin, (SPInt)end);
            pformat->SetTextFormat(reinterpret_cast<const Render::Text::ParagraphFormat*>(&para),
                                   reinterpret_cast<const Render::Text::TextFormat*>(&fmt));
        }
        result = pformat;
    }

    // @0x1424b44d0
    void TextField::setTextFormat(const Value& result, Instances::fl_text::TextFormat* format, SInt32 beginIndex,
                                  SInt32 endIndex)
    {
        SF_UNUSED(result);
        if (!format)
            return;
        SInt32 begin = (beginIndex != -1) ? beginIndex : 0;
        SInt32 end   = (endIndex != -1) ? endIndex : 0x7FFFFFFF;
        if (begin > end)
            return;
        void* ptf = DisplayTextField(this);
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        Render::Text::TextFormat      fmt(MovieHeapOf(asvm.GetMovieImpl()));
        Render::Text::ParagraphFormat para;
        format->GetTextFormat(reinterpret_cast<Render::Text::ParagraphFormat*>(&para),
                              reinterpret_cast<Render::Text::TextFormat*>(&fmt));
        FUN_142615640(DocViewOf(ptf), &fmt, (unsigned)begin, (unsigned)end);
        FUN_142615410(DocViewOf(ptf), &para, (unsigned)begin, (unsigned)end);
        FUN_1425bc060(ptf);
    }
}} // namespace Instances::fl_text

namespace Classes { namespace fl_text
{
    // @0x1424b3810
    void Font::registerFont(const Value& result, Class* font)
    {
        SF_UNUSED(result);
        if (font && FUN_1425149a0(GetClassTraits(), font->GetClassTraits()))
        {
            ASVM& vm = static_cast<ASVM&>(GetVM());
            ASString name = font->GetClassTraits().GetInstanceTraits().GetQualifiedName(Traits::qnfWithDot);
            VMAbcFile* pfile = font->GetClassTraits().GetFilePtr();
            if (pfile)
            {
                // The movie the class's ABC came from (the GFx ABC file keeps it past the Abc::File tables).
                MovieDefImpl* pdef = *(MovieDefImpl**)((UByte*)&pfile->GetAbcFile() + 0x188);
                ResourceBindData data;
                bool found;
                {
                    String symbol(name.ToCStr());
                    found = FUN_14256ec50(vm.GetMovieImpl(), pdef, &data, symbol);
                }
                if (found && data.pResource &&
                    (data.pResource->GetResourceTypeCode() & Resource::MakeTypeCode(Resource::RT_Font)))
                    FUN_142573d60(vm.GetMovieImpl(), pdef, static_cast<FontResource*>(data.pResource.GetPtr()));
            }
            return;
        }
        String className("unknown");
        if (font)
        {
            VMAbcFile* pfile = font->GetClassTraits().GetFilePtr();
            if (pfile)
                className = pfile->GetAbcFile().Source;
        }
        VM& vm = GetVM();
        vm.ThrowArgumentError(VM::Error((VM::ErrorID)2136, vm, className.ToCStr()));
    }
}} // namespace Classes::fl_text

}}} // namespace Scaleform::GFx::AS3

// ---- fl_text: TextSnapshot::getTextRunInfo and its glyph visitor ----

namespace Scaleform { namespace GFx { namespace AS3 {

// Turns each visited glyph into an object of its run info (index, selection, font, color, size, matrix and
// corners in pixels) pushed onto the result array. 0x80 bytes; its vftable 0x14316be60 has no RTTI.
class TextSnapshotGlyphVisitor : public StaticTextSnapshotData::GlyphVisitor
{
public:
    TextSnapshotGlyphVisitor(VM* vm, Instances::fl::Array* parr) : pVM(vm), pArray(parr) {}

    // @0x1424ad870
    // MS2-FUNCTIONAL: register allocation (the matrix entries are scaled before the value is released)
    void OnVisit()
    {
        SPtr<Instances::fl::Object> pobj = pVM->MakeObject();

        StringManager& sm = pVM->GetStringManager();
        Value val;

        val.SetUInt32((UInt32)GetRunIndex());
        pobj->AddDynamicSlotValuePair(sm.CreateString("indexInRun"), val);

        val.SetBool(IsSelected());
        pobj->AddDynamicSlotValuePair(sm.CreateConstString("selected"), val);

        pobj->AddDynamicSlotValuePair(sm.CreateString("font"), sm.CreateString(GetFont()->GetName()));

        val.SetNumber((float)GetColor().ToColor32());
        pobj->AddDynamicSlotValuePair(sm.CreateConstString("color"), val);

        val.SetNumber(GetHeight());
        pobj->AddDynamicSlotValuePair(sm.CreateConstString("height"), val);

        const Render::Matrix2F& mat = GetMatrix();
        val.SetNumber(TwipsToPixels(mat.Sx()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_a"), val);
        val.SetNumber(TwipsToPixels(mat.Shy()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_b"), val);
        val.SetNumber(TwipsToPixels(mat.Shx()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_c"), val);
        val.SetNumber(TwipsToPixels(mat.Sy()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_d"), val);
        val.SetNumber(TwipsToPixels(mat.Tx()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_tx"), val);
        val.SetNumber(TwipsToPixels(mat.Ty()));
        pobj->AddDynamicSlotValuePair(sm.CreateString("matrix_ty"), val);

        const Render::PointF& bl = GetCorners().BottomLeft();
        const Render::PointF& br = GetCorners().BottomRight();
        const Render::PointF& tl = GetCorners().TopLeft();
        const Render::PointF& tr = GetCorners().TopRight();
        val.SetNumber(TwipsToPixels(bl.x));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner0x"), val);
        val.SetNumber(TwipsToPixels(bl.y));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner0y"), val);
        val.SetNumber(TwipsToPixels(br.x));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner1x"), val);
        val.SetNumber(TwipsToPixels(br.y));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner1y"), val);
        val.SetNumber(TwipsToPixels(tr.x));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner2x"), val);
        val.SetNumber(TwipsToPixels(tr.y));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner2y"), val);
        val.SetNumber(TwipsToPixels(tl.x));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner3x"), val);
        val.SetNumber(TwipsToPixels(tl.y));
        pobj->AddDynamicSlotValuePair(sm.CreateString("corner3y"), val);

        pArray->SA.PushBack(Value(pobj));
    }

private:
    VM*                   pVM;      // +0x68
    Instances::fl::Array* pArray;   // +0x70
};

namespace Instances { namespace fl_text
{
    // @0x1424b2d00
    SF_NOINLINE void TextSnapshot::getTextRunInfo(SPtr<Instances::fl::Array>& result, SInt32 beginIndex, SInt32 endIndex)
    {
        VM& vm = GetVM();
        SPtr<Instances::fl::Array> parr = vm.MakeArray();
        TextSnapshotGlyphVisitor visitor(&vm, parr);
        SnapshotData.Visit(&visitor, beginIndex, endIndex);
        result = parr;
    }

    // MS2-FUNCTIONAL: the loop's end test (iterator != End()) keeps a materialized bool the exe folds away.
    // @0x1424b4710
    SF_NOINLINE void StyleSheet::styleNamesGet(SPtr<Instances::fl::Array>& result)
    {
        Pickable<Instances::fl::Array> parr = GetVM().MakeArray();
        StringManager& sm = GetVM().GetStringManager();
        String temp;
        typedef GFx::Text::StyleManager::StyleHash StyleHash;
        for (StyleHash::ConstIterator it = CSS.GetStyles().Begin(); it != CSS.GetStyles().End(); ++it)
        {
            temp.Clear();
            if (it->First.Type == GFx::Text::StyleManager::CSS_Class)
                temp.AppendChar('.');
            temp += it->First.Value;
            ASString name = sm.CreateString(temp);
            Value v(name);
            parr->SA.PushBack(v);
        }
        result = parr;
    }

    // Fills a TextFormat from the dynamic properties of a CSS-style object (StyleSheet.transform).
    class CSSTextFormatLoader
    {
    public:
        static void Process(TextFormat* tf, AS3::Object* pobj)
        {
            GlobalSlotIndex slotIdx(0);
            while ((slotIdx = pobj->GetNextDynPropIndex(slotIdx)).IsValid())
            {
                Value name, value;
                pobj->GetNextPropertyName(name, slotIdx);
                pobj->GetNextPropertyValue(value, slotIdx);
                if (name.IsString())
                    processSub(tf, name.AsString(), value);
            }
        }

    protected:
        static void processSub(TextFormat* tf, const ASString& name, const Value& val);
    };

    // @0x1424b3350
    SF_NOINLINE void CSSTextFormatLoader::processSub(TextFormat* tf, const ASString& name, const Value& val)
    {
        StringBuffer buff;
        val.Convert2String(buff).DoNotCheck();
        const char* pstr = buff.ToCStr();
        char* temp = NULL;
        UPInt sz = buff.GetSize();

        if (name == "color")
        {
            UInt32 colval = strtol(pstr + 1, &temp, 16);
            tf->color.SetUInt32(colval);
        }
        else if (name == "display")
        {
            // not supported
        }
        else if (name == "fontFamily")
            tf->font = val;
        else if (name == "fontSize")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->size.SetNumber(num);
        }
        else if (name == "fontStyle")
        {
            if (!strncmp("normal", pstr, (sz < 4) ? sz : 4))
                tf->italic.SetBool(false);
            else if (!strncmp("italic", pstr, (sz < 9) ? sz : 9))
                tf->italic.SetBool(true);
        }
        else if (name == "fontWeight")
        {
            if (!strncmp("normal", pstr, (sz < 6) ? sz : 6))
                tf->bold.SetBool(false);
            else if (!strncmp("bold", pstr, (sz < 4) ? sz : 4))
                tf->bold.SetBool(true);
        }
        else if (name == "kerning")
        {
            if (!strncmp("false", pstr, (sz < 5) ? sz : 5))
                tf->kerning.SetBool(false);
            else if (!strncmp("true", pstr, (sz < 4) ? sz : 4))
                tf->kerning.SetBool(true);
        }
        else if (name == "leading")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->leading.SetNumber(num);
        }
        else if (name == "letterSpacing")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->letterSpacing.SetNumber(num);
        }
        else if (name == "marginLeft")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->leftMargin.SetNumber(num);
        }
        else if (name == "marginRight")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->rightMargin.SetNumber(num);
        }
        else if (name == "textAlign")
            tf->align = val;
        else if (name == "textDecoration")
        {
            if (!strncmp("none", pstr, (sz < 4) ? sz : 4))
                tf->underline.SetBool(false);
            else if (!strncmp("underline", pstr, (sz < 9) ? sz : 9))
                tf->underline.SetBool(true);
        }
        else if (name == "textIndent")
        {
            float num = (float)SFstrtod(pstr, &temp);
            tf->indent.SetNumber(num);
        }
    }

    // A non-object format yields no result.
    // @0x1424b4f80
    SF_NOINLINE void StyleSheet::transform(SPtr<Instances::fl_text::TextFormat>& result, const Value& formatObject)
    {
        if (!formatObject.IsObject() || !formatObject.GetObject())
            return;
        AS3::Object* pobj = formatObject.GetObject();

        SPtr<TextFormat> textFormat;
        GetVM().ConstructBuiltinObject(textFormat, "flash.text.TextFormat").DoNotCheck();
        CSSTextFormatLoader::Process(textFormat, pobj);
        result = textFormat;
    }
}} // namespace Instances::fl_text

}}} // namespace Scaleform::GFx::AS3

// ---- fl_text: Font.enumerateFonts and its font resource visitor ----

// MovieImpl::LoadRegisteredFonts: adds the fonts registered with Font.registerFont.
void FUN_1425711a0(Scaleform::GFx::MovieImpl* pmovie, Scaleform::HashSet<Scaleform::Ptr<Scaleform::Render::Font> >& fonts);

namespace Scaleform { namespace GFx { namespace AS3 {

// The movie's state bag (MovieImpl's StateBag base at +0x10; our MovieImpl is not polymorphic).
static inline StateBag* MovieStateBag(MovieImpl* pmovie)
{
    return reinterpret_cast<StateBag*>((UByte*)pmovie + 0x10);
}

// The movie's font provider state.
static inline Ptr<GFx::FontProvider> MovieFontProvider(MovieImpl* pmovie)
{
    return *(GFx::FontProvider*)MovieStateBag(pmovie)->GetStateAddRef(State::State_FontProvider);
}

// Collects the fonts among a movie's resources. 0x10 bytes; vftable 0x14316a058.
class FontsVisitor : public MovieDef::ResourceVisitor
{
public:
    FontsVisitor(HashSet<Ptr<Render::Font> >& fonts) : Fonts(fonts) {}

    // @0x1424af670
    virtual void Visit(MovieDef*, Resource* presource, ResourceId, const char*)
    {
        if (presource->GetResourceType() == Resource::RT_Font)
        {
            FontResource* pfontResource = static_cast<FontResource*>(presource);
            Fonts.Set(pfontResource->GetFont());
        }
    }

private:
    FontsVisitor& operator=(const FontsVisitor&) { return *this; }

    HashSet<Ptr<Render::Font> >& Fonts;     // +0x08
};

namespace Classes { namespace fl_text
{
    // The fonts of the movie's resources, the registered fonts and the font library's, as Font objects; with
    // enumerateDeviceFonts also the system fonts by name.
    // @0x1424b02f0
    void Font::enumerateFonts(SPtr<Instances::fl::Array>& result, bool enumerateDeviceFonts)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        MovieImpl* proot = asvm.GetMovieImpl();
        MovieDef* pmoviedef = AsMovieSlots(proot)->GetMovieDef();

        HashSet<Ptr<Render::Font> > fonts;
        FontsVisitor fontsVisitor(fonts);
        pmoviedef->VisitResources(&fontsVisitor, MovieDef::ResVisit_Fonts);

        FUN_1425711a0(proot, fonts);

        FontLib* pfontlib = MovieStateBag(proot)->GetFontLib();
        if (pfontlib)
            pfontlib->LoadFonts(fonts);

        Class* fontClass = asvm.GetClass(StringDataPtr("flash.text.Font"));
        Pickable<Instances::fl::Array> retVal = asvm.MakeArray();

        for (HashSet<Ptr<Render::Font> >::ConstIterator iter = fonts.Begin(); iter != fonts.End(); ++iter)
        {
            SPtr<Instances::fl_text::Font> font;
            asvm.ConstructInstance(font, fontClass, 0, NULL);
            font->pFont = *iter;
            retVal->SA.PushBack(Value(font));
        }

        if (enumerateDeviceFonts)
        {
            GFx::FontProvider* pfontprovider = MovieFontProvider(proot);
            if (pfontprovider)
            {
                StringHash<String> deviceFontNames;
                pfontprovider->LoadFontNames(deviceFontNames);
                for (StringHash<String>::ConstIterator iter = deviceFontNames.Begin(); iter != deviceFontNames.End();
                     ++iter)
                {
                    SPtr<Instances::fl_text::Font> font;
                    asvm.ConstructInstance(font, fontClass, 0, NULL);
                    font->fontName = font->fontName.GetManager()->CreateString(iter->First.ToCStr(), iter->First.GetSize());
                    retVal->SA.PushBack(Value(font));
                }
            }
        }

        result = retVal;
    }
}} // namespace Classes::fl_text

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

    // @0x1424aff40
    SPtr<Instances::fl_text::TextFormat> TextField::defaultTextFormatGet()
    {
        SPtr<Instances::fl_text::TextFormat> result;
        defaultTextFormatGet(result);
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

// ---- fl_text: TextFormat collector visit ----

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

template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (p.GetPtr())
        reinterpret_cast<GcOpWithOwner>(op)(prcc,
            const_cast<const ASRefCountBaseType**>(reinterpret_cast<ASRefCountBaseType**>(p.GetRawPtr())), owner);
}

namespace Instances { namespace fl_text {
    // @0x1424ac140
    void TextFormat::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, align, op, *this);
        AS3::ForEachChild_GC(prcc, blockIndent, op, *this);
        AS3::ForEachChild_GC(prcc, bullet, op, *this);
        AS3::ForEachChild_GC(prcc, bold, op, *this);
        AS3::ForEachChild_GC(prcc, color, op, *this);
        AS3::ForEachChild_GC(prcc, font, op, *this);
        AS3::ForEachChild_GC(prcc, italic, op, *this);
        AS3::ForEachChild_GC(prcc, indent, op, *this);
        AS3::ForEachChild_GC(prcc, kerning, op, *this);
        AS3::ForEachChild_GC(prcc, leading, op, *this);
        AS3::ForEachChild_GC(prcc, leftMargin, op, *this);
        AS3::ForEachChild_GC(prcc, rightMargin, op, *this);
        AS3::ForEachChild_GC(prcc, letterSpacing, op, *this);
        AS3::ForEachChild_GC(prcc, size, op, *this);
        AS3::ForEachChild_GC(prcc, tabStops, op, *this);
        AS3::ForEachChild_GC(prcc, target, op, *this);
        AS3::ForEachChild_GC(prcc, underline, op, *this);
        AS3::ForEachChild_GC(prcc, url, op, *this);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// ---- full-exe fl_text / fl_ui accessors: display-side bodies of the exe called here, by their addresses ----
void FUN_1425bbc10(void* ptf, Scaleform::UInt32 c);          // TextField::SetBackgroundColor
void FUN_1425bbb90(void* ptf, bool b);                       // TextField::SetBackground
void FUN_1425bbcd0(void* ptf, Scaleform::UInt32 c);          // TextField::SetBorderColor
void FUN_1425bbc50(void* ptf, bool b);                       // TextField::SetBorder
void FUN_1425bd630(void* ptf, Scaleform::UInt32 c);          // TextField::SetTextColor
void FUN_1425bcf10(void* ptf, bool f);                       // TextField::SetSelectable
void FUN_1425bcfc0(void* ptf, Scaleform::SPInt beginIndex, Scaleform::SPInt endIndex);  // TextField::SetSelection
bool FUN_1425bce30(void* ptf, const Scaleform::GFx::ASString& restrStr);                 // TextField::SetRestrict
void FUN_1425b7280(void* ptf);                               // TextField::ClearRestrict
void FUN_142609630(void* pstyleManager);                     // Text::StyleManager::Clear
void FUN_1425e2bb0(const void* psnap, Scaleform::UPInt start, Scaleform::UPInt end, bool selected);  // StaticTextSnapshotData::SetSelected
void FUN_14250bad0(void* proot, Scaleform::GFx::ASString& result, Scaleform::UInt32 mouseIndex);     // MovieRoot::GetMouseCursorType

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- fl_text / fl_ui: accessors and stubs the exe keeps out of line ----
namespace Classes { namespace fl_ui
{
    // @0x1424b9210
    void Mouse::cursorGet(ASString& result)
    {
        FUN_14250bad0(static_cast<ASVM&>(GetVM()).GetMovieRoot(), result, 0);
    }

    // @0x1424b9230
    void Mouse::cursorSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        static_cast<ASVM&>(GetVM()).GetMovieRoot()->SetMouseCursorType(v, 0);
    }

    // @0x1424b9570
    void Keyboard::isAccessible(bool& result)
    {
        result = false;
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424af870
    void TextFormat::alignSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        align.Assign(v);
    }

    // @0x1424af880
    void TextField::alwaysShowSelectionGet(bool& result)
    {
        result = ((FieldFlags(DisplayTextField(this)) >> 9) & 1) != 0;
    }

    // @0x1424af8a0
    void TextField::alwaysShowSelectionSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        UInt32& flags = FieldFlags(DisplayTextField(this));
        if (v)
            flags |= 0x200;
        else
            flags &= ~0x200u;
    }

    // @0x1424afd00
    void TextField::backgroundColorGet(UInt32& result)
    {
        result = *(UInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0x13c) & 0xffffff;
    }

    // @0x1424afd20
    void TextField::backgroundColorSet(const Value& result, UInt32 v)
    {
        SF_UNUSED(result);
        FUN_1425bbc10(DisplayTextField(this), v);
    }

    // @0x1424afd30
    void TextField::backgroundGet(bool& result)
    {
        result = (*(UInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0x13c) >> 24) != 0;
    }

    // @0x1424afd50
    void TextField::backgroundSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        FUN_1425bbb90(DisplayTextField(this), v);
    }

    // @0x1424afd60
    void TextFormat::blockIndentGet(Value& result)
    {
        result.Assign(blockIndent);
    }

    // @0x1424afd70
    void TextFormat::blockIndentSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        blockIndent.Assign(v);
    }

    // @0x1424afd80
    void TextFormat::boldGet(Value& result)
    {
        result.Assign(bold);
    }

    // @0x1424afda0
    void TextFormat::boldSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        bold.Assign(v);
    }

    // @0x1424afdb0
    void TextField::borderColorGet(UInt32& result)
    {
        result = *(UInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0x138) & 0xffffff;
    }

    // @0x1424afdd0
    void TextField::borderColorSet(const Value& result, UInt32 v)
    {
        SF_UNUSED(result);
        FUN_1425bbcd0(DisplayTextField(this), v);
    }

    // @0x1424afde0
    void TextField::borderGet(bool& result)
    {
        result = (*(UInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0x138) >> 24) != 0;
    }

    // @0x1424afe00
    void TextField::borderSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        FUN_1425bbc50(DisplayTextField(this), v);
    }

    // @0x1424afe40
    void TextFormat::bulletGet(Value& result)
    {
        result.Assign(bullet);
    }

    // @0x1424afe50
    void TextFormat::bulletSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        bullet.Assign(v);
    }

    // @0x1424afea0
    void StyleSheet::clear(const Value& result)
    {
        SF_UNUSED(result);
        FUN_142609630(&CSS);
    }

    // @0x1424afeb0
    void TextFormat::colorGet(Value& result)
    {
        result.Assign(color);
    }

    // @0x1424afed0
    void TextFormat::colorSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        color.Assign(v);
    }

    // @0x1424afee0
    void TextField::condenseWhiteGet(bool& result)
    {
        result = ((FieldFlags(DisplayTextField(this)) >> 4) & 1) != 0;
    }

    // @0x1424aff00
    void TextField::condenseWhiteSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        UInt32& flags = FieldFlags(DisplayTextField(this));
        if (v)
            flags |= 0x10;
        else
            flags &= ~0x10u;
    }

    // @0x1424b0230
    void TextField::displayAsPasswordGet(bool& result)
    {
        result = ((FieldFlags(DisplayTextField(this)) >> 2) & 1) != 0;
    }

    // @0x1424b0250
    void TextField::displayAsPasswordSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        UInt32 flags = FieldFlags(ptf);
        if ((((flags >> 2) & 1) != 0) != v)
        {
            if (v)
                flags |= 4;
            else
                flags &= ~4u;
            void* pdoc = DocViewOf(ptf);
            FieldFlags(ptf) = flags;
            // The view's password mode, and its reformat request.
            if (v)
                ViewFlags(pdoc) |= 0x10;
            else
                ViewFlags(pdoc) &= ~0x10;
            *((UByte*)DocViewOf(ptf) + 0x14b) |= 2;
        }
        FUN_1425bc060(ptf);
    }

    // @0x1424b02b0
    void TextField::embedFontsGet(bool& result)
    {
        result = (ViewFlags(DocViewOf(DisplayTextField(this))) & 0x20) == 0;
    }

    // @0x1424b02d0
    void TextField::embedFontsSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        UByte& flags = ViewFlags(DocViewOf(DisplayTextField(this)));
        if (v)
            flags &= ~0x20;
        else
            flags |= 0x20;
    }

    // @0x1424b09b0
    void TextFormat::fontSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        font.Assign(v);
    }

    // @0x1424b2fd0
    void TextField::htmlTextSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        FieldFlags(ptf) |= 2u;
        FUN_1425bd9a0(ptf, v.ToCStr(), true, true);
    }

    // @0x1424b2ff0
    void TextFormat::indentGet(Value& result)
    {
        result.Assign(indent);
    }

    // @0x1424b3010
    void TextFormat::indentSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        indent.Assign(v);
    }

    // @0x1424b3020
    void TextFormat::italicGet(Value& result)
    {
        result.Assign(italic);
    }

    // @0x1424b3040
    void TextFormat::italicSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        italic.Assign(v);
    }

    // @0x1424b3050
    void TextFormat::kerningGet(Value& result)
    {
        result.Assign(kerning);
    }

    // @0x1424b3070
    void TextFormat::kerningSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        kerning.Assign(v);
    }

    // @0x1424b3080
    void TextFormat::leadingGet(Value& result)
    {
        result.Assign(leading);
    }

    // @0x1424b30a0
    void TextFormat::leadingSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        leading.Assign(v);
    }

    // @0x1424b30b0
    void TextFormat::leftMarginGet(Value& result)
    {
        result.Assign(leftMargin);
    }

    // @0x1424b30d0
    void TextFormat::leftMarginSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        leftMargin.Assign(v);
    }

    // @0x1424b3110
    void TextFormat::letterSpacingGet(Value& result)
    {
        result.Assign(letterSpacing);
    }

    // @0x1424b3130
    void TextFormat::letterSpacingSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        letterSpacing.Assign(v);
    }

    // @0x1424b3140
    void TextField::maxCharsGet(SInt32& result)
    {
        // The view's character limit (+0xc8), 0 when unlimited.
        result = 0;
        SInt32 maxChars = *(SInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0xc8);
        if (maxChars)
            result = maxChars;
    }

    // @0x1424b3170
    void TextField::maxCharsSet(const Value& result, SInt32 v)
    {
        SF_UNUSED(result);
        if (v >= 0)
            *(SInt32*)((UByte*)DocViewOf(DisplayTextField(this)) + 0xc8) = v;
    }

    // @0x1424b3200
    void TextField::mouseWheelEnabledGet(bool& result)
    {
        result = ((FieldFlags(DisplayTextField(this)) >> 7) & 1) != 0;
    }

    // @0x1424b3220
    void TextField::mouseWheelEnabledSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        UInt32& flags = FieldFlags(DisplayTextField(this));
        if (v)
            flags |= 0x80;
        else
            flags &= ~0x80u;
    }

    // @0x1424b3250
    void TextField::multilineGet(bool& result)
    {
        result = (ViewFlags(DocViewOf(DisplayTextField(this))) & 4) != 0;
    }

    // @0x1424b3f20
    void TextField::restrictSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        if (v.GetNode() == v.GetManager()->GetNullStringNode())
            FUN_1425b7280(ptf);
        else
            FUN_1425bce30(ptf, v);
    }

    // @0x1424b3f40
    void TextFormat::rightMarginGet(Value& result)
    {
        result.Assign(rightMargin);
    }

    // @0x1424b3f60
    void TextFormat::rightMarginSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        rightMargin.Assign(v);
    }

    // @0x1424b4090
    void TextField::selectableSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        FUN_1425bcf10(DisplayTextField(this), v);
    }

    // @0x1424b4360
    void TextSnapshot::setSelected(const Value& result, SInt32 v1, SInt32 v2, bool v3)
    {
        SF_UNUSED(result);
        if (v2 <= v1)
            v2 = v1 + 1;
        FUN_1425e2bb0(&SnapshotData, (SPInt)v1, (SPInt)v2, v3);
    }

    // @0x1424b4390
    void TextField::setSelection(const Value& result, SInt32 v1, SInt32 v2)
    {
        SF_UNUSED(result);
        FUN_1425bcfc0(DisplayTextField(this), (SPInt)v1, (SPInt)v2);
    }

    // @0x1424b46c0
    void TextFormat::sizeGet(Value& result)
    {
        result.Assign(size);
    }

    // @0x1424b46e0
    void TextFormat::sizeSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        size.Assign(v);
    }

    // @0x1424b4cc0
    void TextFormat::targetSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        target.Assign(v);
    }

    // @0x1424b4cf0
    void TextField::textColorSet(const Value& result, UInt32 v)
    {
        SF_UNUSED(result);
        FUN_1425bd630(DisplayTextField(this), v);
    }

    // @0x1424b5300
    void TextFormat::underlineGet(Value& result)
    {
        result.Assign(underline);
    }

    // @0x1424b5320
    void TextFormat::underlineSet(const Value& result, const Value& v)
    {
        SF_UNUSED(result);
        underline.Assign(v);
    }

    // @0x1424b5390
    void TextFormat::urlSet(const Value& result, const ASString& v)
    {
        SF_UNUSED(result);
        url.Assign(v);
    }

    // @0x1424b53a0
    void TextField::useRichTextClipboardGet(bool& result)
    {
        result = ((FieldFlags(DisplayTextField(this)) >> 8) & 1) != 0;
    }

    // @0x1424b53c0
    void TextField::useRichTextClipboardSet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        void* ptf = DisplayTextField(this);
        UInt32 flags = FieldFlags(ptf);
        if (v)
            flags |= 0x100;
        else
            flags &= ~0x100u;
        void* pdoc = DocViewOf(ptf);
        FieldFlags(ptf) = flags;
        // The view's editor kit (+0xd8) keeps its own rich-clipboard flag.
        void* pkit = *(void**)((UByte*)pdoc + 0xd8);
        if (pkit)
        {
            if ((flags >> 8) & 1)
                *(UInt16*)((UByte*)pkit + 0xa0) |= 4;
            else
                *(UInt16*)((UByte*)pkit + 0xa0) &= 0xfffb;
        }
    }

    // @0x1424b5420
    void TextField::wordWrapGet(bool& result)
    {
        result = (ViewFlags(DocViewOf(DisplayTextField(this))) & 8) != 0;
    }

    // Not implemented in this build: a warning, nothing else.
    // @0x1424aff20
    void TextField::contextMenuGet(SPtr<Instances::fl_display::NativeMenu>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::TextField::contextMenuGet() is not implemented\n");
    }

    // @0x1424b2e40
    void TextField::gridFitTypeGet(ASString& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::gridFitTypeGet() is not implemented\n");
    }

    // @0x1424b2e60
    void TextField::gridFitTypeSet(const Value& result, const ASString& v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::gridFitTypeSet() is not implemented\n");
    }

    // @0x1424b4680
    void TextField::sharpnessGet(Value::Number& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::sharpnessGet() is not implemented\n");
    }

    // @0x1424b46a0
    void TextField::sharpnessSet(const Value& result, Value::Number v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::sharpnessSet() is not implemented\n");
    }

    // @0x1424b4f20
    void TextField::thicknessGet(Value::Number& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::thicknessGet() is not implemented\n");
    }

    // @0x1424b4f40
    void TextField::thicknessSet(const Value& result, Value::Number v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TextField::thicknessSet() is not implemented\n");
    }
}}

namespace Instances { namespace fl_ui
{
    // Not implemented in this build: a warning, nothing else.
    // @0x1424b9190
    void ContextMenu::builtInItemsSet(const Value& result, Instances::fl_ui::ContextMenuBuiltInItems* v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::builtInItemsSet() is not implemented\n");
    }

    // @0x1424b91f0
    void ContextMenu::clone(SPtr<Instances::fl_display::NativeMenu>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::clone() is not implemented\n");
    }

    // @0x1424b9300
    void ContextMenu::customItemsSet(const Value& result, Instances::fl::Array* v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::customItemsSet() is not implemented\n");
    }

    // @0x1424b93e0
    void ContextMenu::hideBuiltInItems(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::ContextMenu::hideBuiltInItems() is not implemented\n");
    }
}}

// Vtable-slot leaves without pdata; data_rdata_sf_a's vtable image reaches them by VA.

// MS2-FUNCTIONAL: returns the address of the +0x50 member of the object held at +0x40, or null.
// @0x1424aceb0
void* FUN_1424aceb0(void* self)
{
    UByte* p = *(UByte**)((UByte*)self + 0x40);
    return p ? p + 0x50 : nullptr;
}

// MS2-FUNCTIONAL: reports whether the object at +0x40 is set.
// @0x1424acec0
bool FUN_1424acec0(void* self)
{
    return *(void**)((UByte*)self + 0x40) != nullptr;
}


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
// MS2-PIN: ??_7TextSnapshotGlyphVisitor@AS3@GFx@Scaleform@@6B@ 0x14316be60
// MS2-PIN: ??_7GlyphVisitor@StaticTextSnapshotData@GFx@Scaleform@@6B@ 0x14316a500
// MS2-PIN: ?Release@ParagraphFormat@Text@Render@Scaleform@@QEBAXXZ 0x1424ae650 ; prop
// MS2-PIN: ?Release@TextFormat@Text@Render@Scaleform@@QEBAXXZ 0x1424ae680 ; prop
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@U?$AllocatorDH@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1424b8f90 ; unique
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@U?$AllocatorDH@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1424b9030 ; unique
// MS2-PIN: ??_7FontsVisitor@AS3@GFx@Scaleform@@6B@ 0x14316a058
// MS2-PIN: ??_7ResourceVisitor@MovieDef@GFx@Scaleform@@6B@ 0x143169d08
