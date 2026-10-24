// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_UI_H
#define MS2_SF_GFX_AS3_OBJ_UI_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_ui {
    // 0x50 bytes.
    class ContextMenu : public Instances::fl_events::EventDispatcher
    {
    public:
        ContextMenu(InstanceTraits::Traits& t);
        // @0x1424b8ba0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_ui::ContextMenu"; }

        // @0x1424b9120
        void builtInItemsGet(SPtr<Instances::fl_ui::ContextMenuBuiltInItems>& result);
        SPtr<Instances::fl_ui::ContextMenuBuiltInItems> builtInItemsGet();
        // @0x1424b9190
        void builtInItemsSet(const Value& result, Instances::fl_ui::ContextMenuBuiltInItems*);
        // @0x1424b91f0
        void clone(SPtr<Instances::fl_display::NativeMenu>& result);
        // @0x1424b9270
        void customItemsGet(SPtr<Instances::fl::Array>& result);
        SPtr<Instances::fl::Array> customItemsGet();
        // @0x1424b9300
        void customItemsSet(const Value& result, Instances::fl::Array*);
        // @0x1424b93e0
        void hideBuiltInItems(const Value& result);
    };

    // 0x40 bytes.
    class ContextMenuBuiltInItems : public Instances::fl::Object
    {
    public:
        ContextMenuBuiltInItems(InstanceTraits::Traits& t);
        // @0x1424b8bd0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_ui::ContextMenuBuiltInItems"; }

        bool forwardAndBack;            // +0x38
        bool loop;                      // +0x39
        bool play;                      // +0x3a
        bool print;                     // +0x3b
        bool quality;                   // +0x3c
        bool rewind;                    // +0x3d
        bool save;                      // +0x3e
        bool zoom;                      // +0x3f
    };

    // 0x40 bytes.
    class ContextMenuClipboardItems : public Instances::fl::Object
    {
    public:
        ContextMenuClipboardItems(InstanceTraits::Traits& t);
        // @0x1424b8c00
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_ui::ContextMenuClipboardItems"; }

        bool clear;                     // +0x38
        bool copy;                      // +0x39
        bool cut;                       // +0x3a
        bool paste;                     // +0x3b
        bool selectAll;                 // +0x3c
    };
}}

namespace Classes { namespace fl_ui {
    class KeyLocation : public Class
    {
    public:
        KeyLocation(ClassTraits::Traits& t);
        // @0x1424b8c30
        virtual const char* GetAS3ObjectType() const { return "Classes::KeyLocation"; }

        const UInt32 LEFT;              // +0x50
        const UInt32 NUM_PAD;           // +0x54
        const UInt32 RIGHT;             // +0x58
        const UInt32 STANDARD;          // +0x5c
    };

// <windows.h> defines ALTERNATE and DELETE as macros; the Keyboard constants reuse the names.
#pragma push_macro("ALTERNATE")
#pragma push_macro("DELETE")
#undef ALTERNATE
#undef DELETE
    class Keyboard : public Class
    {
    public:
        Keyboard(ClassTraits::Traits& t);
        // @0x1424b8c50
        virtual const char* GetAS3ObjectType() const { return "Classes::Keyboard"; }

        // @0x1424b91b0
        void capsLockGet(bool& result);
        // @0x1424b9570
        void isAccessible(bool& result);
        // @0x1424b95b0
        void numLockGet(bool& result);

        const UInt32 A;                 // +0x50
        const UInt32 ALTERNATE;         // +0x54
        const UInt32 B;                 // +0x58
        const UInt32 BACKQUOTE;         // +0x5c
        const UInt32 BACKSLASH;         // +0x60
        const UInt32 BACKSPACE;         // +0x64
        const UInt32 C;                 // +0x68
        const UInt32 CAPS_LOCK;         // +0x6c
        SPtr<Instances::fl::Array> CharCodeStrings; // +0x70
        const UInt32 COMMA;             // +0x78
        const UInt32 COMMAND;           // +0x7c
        const UInt32 CONTROL;           // +0x80
        const UInt32 D;                 // +0x84
        const UInt32 DELETE;            // +0x88
        const UInt32 DOWN;              // +0x8c
        const UInt32 E;                 // +0x90
        const UInt32 END;               // +0x94
        const UInt32 ENTER;             // +0x98
        const UInt32 EQUAL;             // +0x9c
        const UInt32 ESCAPE;            // +0xa0
        const UInt32 F;                 // +0xa4
        const UInt32 F1;                // +0xa8
        const UInt32 F10;               // +0xac
        const UInt32 F11;               // +0xb0
        const UInt32 F12;               // +0xb4
        const UInt32 F13;               // +0xb8
        const UInt32 F14;               // +0xbc
        const UInt32 F15;               // +0xc0
        const UInt32 F2;                // +0xc4
        const UInt32 F3;                // +0xc8
        const UInt32 F4;                // +0xcc
        const UInt32 F5;                // +0xd0
        const UInt32 F6;                // +0xd4
        const UInt32 F7;                // +0xd8
        const UInt32 F8;                // +0xdc
        const UInt32 F9;                // +0xe0
        const UInt32 G;                 // +0xe4
        const UInt32 H;                 // +0xe8
        const UInt32 HOME;              // +0xec
        const UInt32 I;                 // +0xf0
        const UInt32 INSERT;            // +0xf4
        const UInt32 J;                 // +0xf8
        const UInt32 K;                 // +0xfc
        const char* KEYNAME_BEGIN;      // +0x100
        const char* KEYNAME_BREAK;      // +0x108
        const char* KEYNAME_CLEARDISPLAY;// +0x110
        const char* KEYNAME_CLEARLINE;  // +0x118
        const char* KEYNAME_DELETE;     // +0x120
        const char* KEYNAME_DELETECHAR; // +0x128
        const char* KEYNAME_DELETELINE; // +0x130
        const char* KEYNAME_DOWNARROW;  // +0x138
        const char* KEYNAME_END;        // +0x140
        const char* KEYNAME_EXECUTE;    // +0x148
        const char* KEYNAME_F1;         // +0x150
        const char* KEYNAME_F10;        // +0x158
        const char* KEYNAME_F11;        // +0x160
        const char* KEYNAME_F12;        // +0x168
        const char* KEYNAME_F13;        // +0x170
        const char* KEYNAME_F14;        // +0x178
        const char* KEYNAME_F15;        // +0x180
        const char* KEYNAME_F16;        // +0x188
        const char* KEYNAME_F17;        // +0x190
        const char* KEYNAME_F18;        // +0x198
        const char* KEYNAME_F19;        // +0x1a0
        const char* KEYNAME_F2;         // +0x1a8
        const char* KEYNAME_F20;        // +0x1b0
        const char* KEYNAME_F21;        // +0x1b8
        const char* KEYNAME_F22;        // +0x1c0
        const char* KEYNAME_F23;        // +0x1c8
        const char* KEYNAME_F24;        // +0x1d0
        const char* KEYNAME_F25;        // +0x1d8
        const char* KEYNAME_F26;        // +0x1e0
        const char* KEYNAME_F27;        // +0x1e8
        const char* KEYNAME_F28;        // +0x1f0
        const char* KEYNAME_F29;        // +0x1f8
        const char* KEYNAME_F3;         // +0x200
        const char* KEYNAME_F30;        // +0x208
        const char* KEYNAME_F31;        // +0x210
        const char* KEYNAME_F32;        // +0x218
        const char* KEYNAME_F33;        // +0x220
        const char* KEYNAME_F34;        // +0x228
        const char* KEYNAME_F35;        // +0x230
        const char* KEYNAME_F4;         // +0x238
        const char* KEYNAME_F5;         // +0x240
        const char* KEYNAME_F6;         // +0x248
        const char* KEYNAME_F7;         // +0x250
        const char* KEYNAME_F8;         // +0x258
        const char* KEYNAME_F9;         // +0x260
        const char* KEYNAME_FIND;       // +0x268
        const char* KEYNAME_HELP;       // +0x270
        const char* KEYNAME_HOME;       // +0x278
        const char* KEYNAME_INSERT;     // +0x280
        const char* KEYNAME_INSERTCHAR; // +0x288
        const char* KEYNAME_INSERTLINE; // +0x290
        const char* KEYNAME_LEFTARROW;  // +0x298
        const char* KEYNAME_MENU;       // +0x2a0
        const char* KEYNAME_MODESWITCH; // +0x2a8
        const char* KEYNAME_NEXT;       // +0x2b0
        const char* KEYNAME_PAGEDOWN;   // +0x2b8
        const char* KEYNAME_PAGEUP;     // +0x2c0
        const char* KEYNAME_PAUSE;      // +0x2c8
        const char* KEYNAME_PREV;       // +0x2d0
        const char* KEYNAME_PRINT;      // +0x2d8
        const char* KEYNAME_PRINTSCREEN;// +0x2e0
        const char* KEYNAME_REDO;       // +0x2e8
        const char* KEYNAME_RESET;      // +0x2f0
        const char* KEYNAME_RIGHTARROW; // +0x2f8
        const char* KEYNAME_SCROLLLOCK; // +0x300
        const char* KEYNAME_SELECT;     // +0x308
        const char* KEYNAME_STOP;       // +0x310
        const char* KEYNAME_SYSREQ;     // +0x318
        const char* KEYNAME_SYSTEM;     // +0x320
        const char* KEYNAME_UNDO;       // +0x328
        const char* KEYNAME_UPARROW;    // +0x330
        const char* KEYNAME_USER;       // +0x338
        const UInt32 L;                 // +0x340
        const UInt32 LEFT;              // +0x344
        const UInt32 LEFTBRACKET;       // +0x348
        const UInt32 M;                 // +0x34c
        const UInt32 MINUS;             // +0x350
        const UInt32 N;                 // +0x354
        const UInt32 NUMBER_0;          // +0x358
        const UInt32 NUMBER_1;          // +0x35c
        const UInt32 NUMBER_2;          // +0x360
        const UInt32 NUMBER_3;          // +0x364
        const UInt32 NUMBER_4;          // +0x368
        const UInt32 NUMBER_5;          // +0x36c
        const UInt32 NUMBER_6;          // +0x370
        const UInt32 NUMBER_7;          // +0x374
        const UInt32 NUMBER_8;          // +0x378
        const UInt32 NUMBER_9;          // +0x37c
        const UInt32 NUMPAD;            // +0x380
        const UInt32 NUMPAD_0;          // +0x384
        const UInt32 NUMPAD_1;          // +0x388
        const UInt32 NUMPAD_2;          // +0x38c
        const UInt32 NUMPAD_3;          // +0x390
        const UInt32 NUMPAD_4;          // +0x394
        const UInt32 NUMPAD_5;          // +0x398
        const UInt32 NUMPAD_6;          // +0x39c
        const UInt32 NUMPAD_7;          // +0x3a0
        const UInt32 NUMPAD_8;          // +0x3a4
        const UInt32 NUMPAD_9;          // +0x3a8
        const UInt32 NUMPAD_ADD;        // +0x3ac
        const UInt32 NUMPAD_DECIMAL;    // +0x3b0
        const UInt32 NUMPAD_DIVIDE;     // +0x3b4
        const UInt32 NUMPAD_ENTER;      // +0x3b8
        const UInt32 NUMPAD_MULTIPLY;   // +0x3bc
        const UInt32 NUMPAD_SUBTRACT;   // +0x3c0
        const UInt32 O;                 // +0x3c4
        const UInt32 P;                 // +0x3c8
        const UInt32 PAGE_DOWN;         // +0x3cc
        const UInt32 PAGE_UP;           // +0x3d0
        const UInt32 PERIOD;            // +0x3d4
        const UInt32 Q;                 // +0x3d8
        const UInt32 QUOTE;             // +0x3dc
        const UInt32 R;                 // +0x3e0
        const UInt32 RIGHT;             // +0x3e4
        const UInt32 RIGHTBRACKET;      // +0x3e8
        const UInt32 S;                 // +0x3ec
        const UInt32 SEMICOLON;         // +0x3f0
        const UInt32 SHIFT;             // +0x3f4
        const UInt32 SLASH;             // +0x3f8
        const UInt32 SPACE;             // +0x3fc
        const char* STRING_BEGIN;       // +0x400
        const char* STRING_BREAK;       // +0x408
        const char* STRING_CLEARDISPLAY;// +0x410
        const char* STRING_CLEARLINE;   // +0x418
        const char* STRING_DELETE;      // +0x420
        const char* STRING_DELETECHAR;  // +0x428
        const char* STRING_DELETELINE;  // +0x430
        const char* STRING_DOWNARROW;   // +0x438
        const char* STRING_END;         // +0x440
        const char* STRING_EXECUTE;     // +0x448
        const char* STRING_F1;          // +0x450
        const char* STRING_F10;         // +0x458
        const char* STRING_F11;         // +0x460
        const char* STRING_F12;         // +0x468
        const char* STRING_F13;         // +0x470
        const char* STRING_F14;         // +0x478
        const char* STRING_F15;         // +0x480
        const char* STRING_F16;         // +0x488
        const char* STRING_F17;         // +0x490
        const char* STRING_F18;         // +0x498
        const char* STRING_F19;         // +0x4a0
        const char* STRING_F2;          // +0x4a8
        const char* STRING_F20;         // +0x4b0
        const char* STRING_F21;         // +0x4b8
        const char* STRING_F22;         // +0x4c0
        const char* STRING_F23;         // +0x4c8
        const char* STRING_F24;         // +0x4d0
        const char* STRING_F25;         // +0x4d8
        const char* STRING_F26;         // +0x4e0
        const char* STRING_F27;         // +0x4e8
        const char* STRING_F28;         // +0x4f0
        const char* STRING_F29;         // +0x4f8
        const char* STRING_F3;          // +0x500
        const char* STRING_F30;         // +0x508
        const char* STRING_F31;         // +0x510
        const char* STRING_F32;         // +0x518
        const char* STRING_F33;         // +0x520
        const char* STRING_F34;         // +0x528
        const char* STRING_F35;         // +0x530
        const char* STRING_F4;          // +0x538
        const char* STRING_F5;          // +0x540
        const char* STRING_F6;          // +0x548
        const char* STRING_F7;          // +0x550
        const char* STRING_F8;          // +0x558
        const char* STRING_F9;          // +0x560
        const char* STRING_FIND;        // +0x568
        const char* STRING_HELP;        // +0x570
        const char* STRING_HOME;        // +0x578
        const char* STRING_INSERT;      // +0x580
        const char* STRING_INSERTCHAR;  // +0x588
        const char* STRING_INSERTLINE;  // +0x590
        const char* STRING_LEFTARROW;   // +0x598
        const char* STRING_MENU;        // +0x5a0
        const char* STRING_MODESWITCH;  // +0x5a8
        const char* STRING_NEXT;        // +0x5b0
        const char* STRING_PAGEDOWN;    // +0x5b8
        const char* STRING_PAGEUP;      // +0x5c0
        const char* STRING_PAUSE;       // +0x5c8
        const char* STRING_PREV;        // +0x5d0
        const char* STRING_PRINT;       // +0x5d8
        const char* STRING_PRINTSCREEN; // +0x5e0
        const char* STRING_REDO;        // +0x5e8
        const char* STRING_RESET;       // +0x5f0
        const char* STRING_RIGHTARROW;  // +0x5f8
        const char* STRING_SCROLLLOCK;  // +0x600
        const char* STRING_SELECT;      // +0x608
        const char* STRING_STOP;        // +0x610
        const char* STRING_SYSREQ;      // +0x618
        const char* STRING_SYSTEM;      // +0x620
        const char* STRING_UNDO;        // +0x628
        const char* STRING_UPARROW;     // +0x630
        const char* STRING_USER;        // +0x638
        const UInt32 T;                 // +0x640
        const UInt32 TAB;               // +0x644
        const UInt32 U;                 // +0x648
        const UInt32 UP;                // +0x64c
        const UInt32 V;                 // +0x650
        const UInt32 W;                 // +0x654
        const UInt32 X;                 // +0x658
        const UInt32 Y;                 // +0x65c
        const UInt32 Z;                 // +0x660
    };
#pragma pop_macro("DELETE")
#pragma pop_macro("ALTERNATE")

    class Mouse : public Class
    {
    public:
        Mouse(ClassTraits::Traits& t);
        // @0x1424b8c70
        virtual const char* GetAS3ObjectType() const { return "Classes::Mouse"; }

        // @0x1424b9210
        void cursorGet(ASString& result);
        // @0x1424b9230
        void cursorSet(const Value& result, const ASString&);
        // @0x1424b9320
        void hide(const Value& result);
        // @0x1424b95f0
        void show(const Value& result);
    };

    class MouseCursor : public Class
    {
    public:
        MouseCursor(ClassTraits::Traits& t);
        // @0x1424b8c90
        virtual const char* GetAS3ObjectType() const { return "Classes::MouseCursor"; }

        const char* ARROW;              // +0x50
        const char* AUTO;               // +0x58
        const char* BUTTON;             // +0x60
        const char* HAND;               // +0x68
        const char* IBEAM;              // +0x70
    };

    class Multitouch : public Class
    {
    public:
        Multitouch(ClassTraits::Traits& t);
        // @0x1424b8cb0
        virtual const char* GetAS3ObjectType() const { return "Classes::Multitouch"; }

        // @0x1424b9400
        void inputModeGet(ASString& result);
        // @0x1424b94c0
        void inputModeSet(const Value& result, const ASString&);
        // @0x1424b9580
        void maxTouchPointsGet(SInt32& result);
        // @0x1424b96b0
        void supportedGesturesGet(SPtr<Instances::fl_vec::Vector_String>& result);
        // @0x1424b97d0
        void supportsGestureEventsGet(bool& result);
        // @0x1424b9800
        void supportsTouchEventsGet(bool& result);
    };

    class MultitouchInputMode : public Class
    {
    public:
        MultitouchInputMode(ClassTraits::Traits& t);
        // @0x1424b8cd0
        virtual const char* GetAS3ObjectType() const { return "Classes::MultitouchInputMode"; }

        const char* GESTURE;            // +0x50
        const char* NONE;               // +0x58
        const char* TOUCH_POINT;        // +0x60
    };
}}

namespace InstanceTraits { namespace fl_ui {
    class ContextMenu : public CTraits
    {
    public:
        typedef Instances::fl_ui::ContextMenu InstanceType;

        ContextMenu(VM& vm, const ClassInfo& ci);
        // @0x1424b8b90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ContextMenu"; }
        virtual void MakeObject(Value& result, Traits& t);
        Pickable<InstanceType> MakeInstance(ContextMenu& t);
    };

    class ContextMenuBuiltInItems : public CTraits
    {
    public:
        typedef Instances::fl_ui::ContextMenuBuiltInItems InstanceType;

        ContextMenuBuiltInItems(VM& vm, const ClassInfo& ci);
        // @0x1424b8bc0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ContextMenuBuiltInItems"; }
        virtual void MakeObject(Value& result, Traits& t);
        Pickable<InstanceType> MakeInstance(ContextMenuBuiltInItems& t);
    };

    class ContextMenuClipboardItems : public CTraits
    {
    public:
        typedef Instances::fl_ui::ContextMenuClipboardItems InstanceType;

        ContextMenuClipboardItems(VM& vm, const ClassInfo& ci);
        // @0x1424b8bf0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ContextMenuClipboardItems"; }
        virtual void MakeObject(Value& result, Traits& t);
        Pickable<InstanceType> MakeInstance(ContextMenuClipboardItems& t);
    };
}}

namespace ClassTraits { namespace fl_ui {
    class ContextMenu : public Traits
    {
    public:
        ContextMenu(VM& vm);
        // @0x1424b8b80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ContextMenu"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ContextMenuBuiltInItems : public Traits
    {
    public:
        ContextMenuBuiltInItems(VM& vm);
        // @0x1424b8bb0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ContextMenuBuiltInItems"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ContextMenuClipboardItems : public Traits
    {
    public:
        ContextMenuClipboardItems(VM& vm);
        // @0x1424b8be0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ContextMenuClipboardItems"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ContextMenuItem : public Traits
    {
    public:
        ContextMenuItem(VM& vm);
        // @0x1424b8c10
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ContextMenuItem"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class KeyLocation : public Traits
    {
    public:
        KeyLocation(VM& vm);
        // @0x1424b8c20
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::KeyLocation"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Keyboard : public Traits
    {
    public:
        Keyboard(VM& vm);
        // @0x1424b8c40
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Keyboard"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Mouse : public Traits
    {
    public:
        Mouse(VM& vm);
        // @0x1424b8c60
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Mouse"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MouseCursor : public Traits
    {
    public:
        MouseCursor(VM& vm);
        // @0x1424b8c80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MouseCursor"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Multitouch : public Traits
    {
    public:
        Multitouch(VM& vm);
        // @0x1424b8ca0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Multitouch"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MultitouchInputMode : public Traits
    {
    public:
        MultitouchInputMode(VM& vm);
        // @0x1424b8cc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MultitouchInputMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenu) == 0xc8, "ContextMenu size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenuBuiltInItems) == 0xc8, "ContextMenuBuiltInItems size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenuClipboardItems) == 0xc8, "ContextMenuClipboardItems size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenuItem) == 0xc8, "ContextMenuItem size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::KeyLocation) == 0xc8, "KeyLocation size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::Keyboard) == 0xc8, "Keyboard size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::Mouse) == 0xc8, "Mouse size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::MouseCursor) == 0xc8, "MouseCursor size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::Multitouch) == 0xc8, "Multitouch size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_ui::MultitouchInputMode) == 0xc8, "MultitouchInputMode size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::KeyLocation) == 0x60, "KeyLocation size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard) == 0x668, "Keyboard size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::Mouse) == 0x50, "Mouse size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor) == 0x78, "MouseCursor size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch) == 0x50, "Multitouch size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_ui::MultitouchInputMode) == 0x68, "MultitouchInputMode size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu) == 0xe8, "ContextMenu size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuBuiltInItems) == 0xe8, "ContextMenuBuiltInItems size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuClipboardItems) == 0xe8, "ContextMenuClipboardItems size");

#endif
