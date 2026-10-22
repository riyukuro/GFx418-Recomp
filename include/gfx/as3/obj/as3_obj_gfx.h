// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_GFX_H
#define MS2_SF_GFX_AS3_OBJ_GFX_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_gfx {
    // 0x70 bytes, vftable 0x1431752e8.
    class FocusEventEx : public Instances::fl_events::FocusEvent
    {
    public:
        FocusEventEx(InstanceTraits::Traits& t);                            // 0x1424c5430
        // @0x1424c8d40
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::FocusEventEx"; }
        virtual AS3::Object* GetEventClass() const;                         // 0x1424c9090
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x1424c8ae0

        UInt32 controllerIdx;   // +0x68
    };

    // 0x70 bytes, vftable 0x143174fb0.
    class GamePadAnalogEvent : public Instances::fl_events::Event
    {
    public:
        GamePadAnalogEvent(InstanceTraits::Traits& t);                      // 0x1424c6060
        // @0x1424c8dc0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::GamePadAnalogEvent"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x1424c8a20
        virtual AS3::Object* GetEventClass() const;                         // 0x1424c90a0
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x1424c8b30

        UInt32          Code;           // +0x58
        UInt32          ControllerIdx;  // +0x5c
        Value::Number   XValue;         // +0x60
        Value::Number   YValue;         // +0x68

        // @0x1424c9d30
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x1424c9dc0
        void codeGet(UInt32& result);
        // @0x1424c9dd0
        void codeSet(const Value& result, UInt32);
        // @0x1424c9de0
        void controllerIdxGet(UInt32& result);
        // @0x1424c9df0
        void controllerIdxSet(const Value& result, UInt32);
        // @0x1424cc0f0
        void toString(ASString& result);
        // @0x1424cca00
        void xvalueGet(Value::Number& result);
        // @0x1424cca10
        void xvalueSet(const Value& result, Value::Number);
        // @0x1424cca20
        void yvalueGet(Value::Number& result);
        // @0x1424cca30
        void yvalueSet(const Value& result, Value::Number);
    };

    // 0x60 bytes, vftable 0x143175be8. Every style value starts at -1 (unset).
    class IMECandidateListStyle : public Instances::fl::Object
    {
    public:
        IMECandidateListStyle(InstanceTraits::Traits& t);                   // 0x1424c61c0
        // @0x1424c8df0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::IMECandidateListStyle"; }

        SInt32 textColor;                       // +0x38
        SInt32 selectedTextColor;               // +0x3c
        SInt32 fontSize;                        // +0x40
        SInt32 backgroundColor;                 // +0x44
        SInt32 selectedBackgroundColor;         // +0x48
        SInt32 indexBackgroundColor;            // +0x4c
        SInt32 selectedIndexBackgroundColor;    // +0x50
        SInt32 readingWindowTextColor;          // +0x54
        SInt32 readingWindowBackgroundColor;    // +0x58
        SInt32 readingWindowFontSize;           // +0x5c
    };

    // 0x60 bytes, vftable 0x143175830.
    class IMEEventEx : public Instances::fl_events::Event
    {
    public:
        IMEEventEx(InstanceTraits::Traits& t);                              // 0x1424c6420
        // @0x1424c8e30
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::IMEEventEx"; }

        ASString message;       // +0x58
    };

    // 0x78 bytes, vftable 0x143174c10.
    class KeyboardEventEx : public Instances::fl_events::KeyboardEvent
    {
    public:
        KeyboardEventEx(InstanceTraits::Traits& t);                         // 0x1424c67b0
        // @0x1424c8ea0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::KeyboardEventEx"; }
        virtual AS3::Object* GetEventClass() const;                         // 0x1424c90b0
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x1424c8b70

        UInt32 controllerIdx;   // +0x70
    };

    // 0x68 bytes, vftable 0x1431741e8. Bubbles off, cancelable.
    class MouseCursorEvent : public Instances::fl_events::Event
    {
    public:
        MouseCursorEvent(InstanceTraits::Traits& t);                        // 0x1424c6950
        // @0x1424c8ee0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::MouseCursorEvent"; }

        ASString cursor;        // +0x58
        UInt32   mouseIdx;      // +0x60
    };

    // 0xa0 bytes, vftable 0x143174908.
    class MouseEventEx : public Instances::fl_events::MouseEvent
    {
    public:
        MouseEventEx(InstanceTraits::Traits& t);                            // 0x1424c6b20
        // @0x1424c8f20
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::MouseEventEx"; }
        virtual AS3::Object* GetEventClass() const;                         // 0x1424c90c0
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x1424c8bf0

        UInt32 mouseIdx;        // +0x90
        UInt32 buttonIdx;       // +0x94
        UInt32 nestingIdx;      // +0x98
    };

    // 0x68 bytes, vftable 0x143175508.
    class TextEventEx : public Instances::fl_events::TextEvent
    {
    public:
        TextEventEx(InstanceTraits::Traits& t);                             // 0x1424c6e10
        // @0x1424c8f80
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_gfx::TextEventEx"; }
        virtual AS3::Object* GetEventClass() const;                         // 0x1424c90d0
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x1424c8ca0

        UInt32 controllerIdx;   // +0x60
        UInt32 buttonIdx;       // +0x64
    };

}}

namespace Classes { namespace fl_gfx {
    // 0x60 bytes, vftable 0x143174100.
    class Extensions : public Class
    {
    public:
        Extensions(ClassTraits::Traits& t);                             // 0x1424c52c0
        // @0x1424c8d10
        virtual const char* GetAS3ObjectType() const { return "Classes::Extensions"; }

        const UInt32 EDGEAA_INHERIT;            // +0x50
        const UInt32 EDGEAA_ON;                 // +0x54
        const UInt32 EDGEAA_OFF;                // +0x58
        const UInt32 EDGEAA_DISABLE;            // +0x5c

        // @0x1424c9ef0
        void enabledGet(bool& result);
        // @0x1424c9f10
        void enabledSet(const Value& result, bool);
        // @0x1424ca900
        void getEdgeAAMode(UInt32& result, Instances::fl_display::DisplayObject*);
        // @0x1424cadf0
        void getMouseCursorType(ASString& result, UInt32);
        // @0x1424cae10
        void getMouseTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, bool, UInt32);
        // @0x1424cb000
        void getTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, Value::Number, Value::Number, bool);
        // @0x1424cb2b0
        void isScaleformGet(bool& result);
        // @0x1424cb610
        void noInvisibleAdvanceGet(bool& result);
        // @0x1424cb640
        void noInvisibleAdvanceSet(const Value& result, bool);
        // @0x1424cb680
        void numControllersGet(UInt32& result);
        // @0x1424cb7c0
        void setEdgeAAMode(const Value& result, Instances::fl_display::DisplayObject*, UInt32);
        // @0x1424cbd90
        void setMouseCursorType(const Value& result, const ASString&, UInt32);
        // @0x1424cc860
        void visibleRectGet(SPtr<Instances::fl_geom::Rectangle>& result);
    };

    // 0x50 bytes, vftable 0x143173f38.
    class FocusManager : public Class
    {
    public:
        FocusManager(ClassTraits::Traits& t);                           // 0x1424c5540
        // @0x1424c8d60
        virtual const char* GetAS3ObjectType() const { return "Classes::FocusManager"; }

        // @0x1424c9b20
        void alwaysEnableArrowKeysGet(bool& result);
        // @0x1424c9b70
        void alwaysEnableArrowKeysSet(const Value& result, bool);
        // @0x1424c9e60
        void disableFocusKeysGet(bool& result);
        // @0x1424c9eb0
        void disableFocusKeysSet(const Value& result, bool);
        // @0x1424c9f20
        void findFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString&, Instances::fl_display::DisplayObjectContainer*, bool, Instances::fl_display::InteractiveObject*, bool, UInt32);
        // @0x1424ca860
        void getControllerFocusGroup(UInt32& result, UInt32);
        // @0x1424ca8b0
        void getControllerMaskByFocusGroup(UInt32& result, UInt32);
        // @0x1424ca9b0
        void getFocus(SPtr<Instances::fl_display::InteractiveObject>& result, UInt32);
        // @0x1424cab30
        void getFocusGroupMask(UInt32& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cad40
        void getModalClip(SPtr<Instances::fl_display::Sprite>& result, UInt32);
        // @0x1424cb2c0
        void moveFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString&, Instances::fl_display::InteractiveObject*, bool, UInt32);
        // @0x1424cb6c0
        void numFocusGroupsGet(UInt32& result);
        // @0x1424cb770
        void setControllerFocusGroup(bool& result, UInt32, UInt32);
        // @0x1424cb810
        void setFocus(const Value& result, Instances::fl_display::InteractiveObject*, UInt32);
        // @0x1424cb910
        void setFocusGroupMask(const Value& result, Instances::fl_display::InteractiveObject*, UInt32);
        // @0x1424cbd50
        void setModalClip(const Value& result, Instances::fl_display::Sprite*, UInt32);
    };

    // 0x3f0 bytes, vftable 0x143174ec8.
    class GamePad : public Class
    {
    public:
        GamePad(ClassTraits::Traits& t);                                // 0x1424c5650
        ~GamePad();                                                     // 0x1424c7230
        // @0x1424c8d80
        virtual const char* GetAS3ObjectType() const { return "Classes::GamePad"; }

        Value PAD_NONE;                         // +0x50
        Value PAD_BACK;                         // +0x70
        Value PAD_START;                        // +0x90
        Value PAD_A;                            // +0xb0
        Value PAD_B;                            // +0xd0
        Value PAD_X;                            // +0xf0
        Value PAD_Y;                            // +0x110
        Value PAD_R1;                           // +0x130
        Value PAD_L1;                           // +0x150
        Value PAD_R2;                           // +0x170
        Value PAD_L2;                           // +0x190
        Value PAD_UP;                           // +0x1b0
        Value PAD_DOWN;                         // +0x1d0
        Value PAD_RIGHT;                        // +0x1f0
        Value PAD_LEFT;                         // +0x210
        Value PAD_PLUS;                         // +0x230
        Value PAD_MINUS;                        // +0x250
        Value PAD_1;                            // +0x270
        Value PAD_2;                            // +0x290
        Value PAD_H;                            // +0x2b0
        Value PAD_C;                            // +0x2d0
        Value PAD_Z;                            // +0x2f0
        Value PAD_O;                            // +0x310
        Value PAD_T;                            // +0x330
        Value PAD_S;                            // +0x350
        Value PAD_SELECT;                       // +0x370
        Value PAD_HOME;                         // +0x390
        Value PAD_RT;                           // +0x3b0
        Value PAD_LT;                           // +0x3d0

        // @0x1424cc0e0
        void supportsAnalogEvents(bool& result);
    };

    // 0x50 bytes, vftable 0x143175ea0.
    class IMEEx : public Class
    {
    public:
        IMEEx(ClassTraits::Traits& t);                                  // 0x1424c6540
        // @0x1424c8e50
        virtual const char* GetAS3ObjectType() const { return "Classes::IMEEx"; }

        // @0x1424c8fb0
        void GetCompositionString(ASString& result);
        // @0x1424c9120
        void GetOSVersion(ASString& result);
        // @0x1424c9a20
        void SendLangBarMessage(const Value& result, Instances::fl_display::Sprite*, const ASString&, const ASString&);
        // @0x1424cab90
        void getIMECandidateListStyle(SPtr<Instances::fl_gfx::IMECandidateListStyle>& result);
        // @0x1424cb980
        void setIMECandidateListStyle(const Value& result, Instances::fl_gfx::IMECandidateListStyle*);
    };

    // 0x50 bytes, vftable 0x1431745c0.
    class InteractiveObjectEx : public Class
    {
    public:
        InteractiveObjectEx(ClassTraits::Traits& t);                    // 0x1424c6650
        // @0x1424c8e70
        virtual const char* GetAS3ObjectType() const { return "Classes::InteractiveObjectEx"; }

        // @0x1424cab60
        void getHitTestDisable(bool& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cb1a0
        void getTopmostLevel(bool& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cb940
        void setHitTestDisable(const Value& result, Instances::fl_display::InteractiveObject*, bool);
        // @0x1424cbef0
        void setTopmostLevel(const Value& result, Instances::fl_display::InteractiveObject*, bool);
    };

    // 0x60 bytes, vftable 0x143173db8.
    class SystemEx : public Class
    {
    public:
        SystemEx(ClassTraits::Traits& t);                               // 0x1424c6c50
        // @0x1424c8f40
        virtual const char* GetAS3ObjectType() const { return "Classes::SystemEx"; }

        const UInt32 REPORT_SHORT_FILENAMES;    // +0x50
        const UInt32 REPORT_NO_CIRCULAR_REFERENCES;// +0x54
        const UInt32 REPORT_SUPPRESS_OVERALL_STATS;// +0x58
        const UInt32 REPORT_ONLY_ANON_OBJ_ADDRESSES;// +0x5c

        // @0x1424c9aa0
        void actionVerboseGet(bool& result);
        // @0x1424c9ad0
        void actionVerboseSet(const Value& result, bool);
        // @0x1424c9e00
        void describeType(ASString& result, const Value&);
        // @0x1424ca6a0
        void getCodeFileName(ASString& result);
        // @0x1424ca6b0
        void getCodeFileNames(SPtr<Instances::fl::Array>& result);
        // @0x1424caf20
        void getStackTrace(ASString& result);
        // @0x1424cb6e0
        void printObjectsReport(const Value& result, bool, UInt32, const ASString&);
        // @0x1424cb740
        void setBackgroundAlpha(const Value& result, Value::Number);
    };

    // 0x88 bytes, vftable 0x143174748.
    class TextFieldEx : public Class
    {
    public:
        TextFieldEx(ClassTraits::Traits& t);                            // 0x1424c6f70
        // @0x1424c8fa0
        virtual const char* GetAS3ObjectType() const { return "Classes::TextFieldEx"; }

        const char* VALIGN_NONE;                // +0x50
        const char* VALIGN_TOP;                 // +0x58
        const char* VALIGN_CENTER;              // +0x60
        const char* VALIGN_BOTTOM;              // +0x68
        const char* TEXTAUTOSZ_NONE;            // +0x70
        const char* TEXTAUTOSZ_SHRINK;          // +0x78
        const char* TEXTAUTOSZ_FIT;             // +0x80

        // @0x1424c9bb0
        void appendHtml(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424caf40
        void getTextAutoSize(ASString& result, Instances::fl_text::TextField*);
        // @0x1424cb1d0
        void getVerticalAlign(ASString& result, Instances::fl_text::TextField*);
        // @0x1424cbab0
        void setIMEEnabled(const Value& result, Instances::fl_text::TextField*, bool);
        // @0x1424cbb40
        void setImageSubstitutions(const Value& result, Instances::fl_text::TextField*, const Value&);
        // @0x1424cbdb0
        void setTextAutoSize(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424cbf60
        void setVerticalAlign(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424cc450
        void updateImageSubstitution(const Value& result, Instances::fl_text::TextField*, const ASString&, Instances::fl_display::BitmapData*);
    };

    // 0x58 bytes, vftable 0x1431751e0.
    class GamePadAnalogEvent : public Class
    {
    public:
        GamePadAnalogEvent(ClassTraits::Traits& t);                     // 0x1424c6000
        // @0x1424c8da0
        virtual const char* GetAS3ObjectType() const { return "Classes::GamePadAnalogEvent"; }

        const char* CHANGE;                     // +0x50
    };

    // 0x90 bytes, vftable 0x143175a48.
    class IMEEventEx : public Class
    {
    public:
        IMEEventEx(ClassTraits::Traits& t);                             // 0x1424c6370
        // @0x1424c8e10
        virtual const char* GetAS3ObjectType() const { return "Classes::IMEEventEx"; }

        const char* SET_CURRENT_INPUT_LANGUAGE; // +0x50
        const char* SET_SUPPORTED_LANGUAGES;    // +0x58
        const char* SET_SUPPORTED_IMENAMES;     // +0x60
        const char* SET_IMENAME;                // +0x68
        const char* SET_CURRENT_LANGUAGE;       // +0x70
        const char* REMOVE_STATUS_WINDOW;       // +0x78
        const char* DISPLAY_STATUS_WINDOW;      // +0x80
        const char* SET_CONVERSION_STATUS;      // +0x88
    };

    // 0x58 bytes, vftable 0x143174418.
    class MouseCursorEvent : public Class
    {
    public:
        MouseCursorEvent(ClassTraits::Traits& t);                       // 0x1424c68f0
        // @0x1424c8ec0
        virtual const char* GetAS3ObjectType() const { return "Classes::MouseCursorEvent"; }

        const char* CURSOR_CHANGE;              // +0x50
    };

    // 0x60 bytes, vftable 0x143174b28.
    class MouseEventEx : public Class
    {
    public:
        MouseEventEx(ClassTraits::Traits& t);                           // 0x1424c6ab0
        // @0x1424c8f00
        virtual const char* GetAS3ObjectType() const { return "Classes::MouseEventEx"; }

        const UInt32 LEFT_BUTTON;               // +0x50
        const UInt32 RIGHT_BUTTON;              // +0x54
        const UInt32 MIDDLE_BUTTON;             // +0x58
    };

    // 0x60 bytes, vftable 0x143175728.
    class TextEventEx : public Class
    {
    public:
        TextEventEx(ClassTraits::Traits& t);                            // 0x1424c6da0
        // @0x1424c8f60
        virtual const char* GetAS3ObjectType() const { return "Classes::TextEventEx"; }

        const char* LINK_MOUSE_OVER;            // +0x50
        const char* LINK_MOUSE_OUT;             // +0x58
    };

}}

namespace InstanceTraits { namespace fl_gfx {
    // The MakeObject overrides (slot 14) follow the unit's range: 0x1424c96a0 lies in sfr_as2_01's, the rest in sfr_as3_15's.
    // 0x70 bytes per instance, vftable 0x1431753c8.
    class FocusEventEx : public CTraits
    {
    public:
        typedef Instances::fl_gfx::FocusEventEx InstanceType;

        FocusEventEx(VM& vm, const ClassInfo& ci);                      // 0x1424c5400
        // @0x1424c8d30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::FocusEventEx"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c96a0
    };

    // 0x70 bytes per instance, vftable 0x143175098.
    class GamePadAnalogEvent : public CTraits
    {
    public:
        typedef Instances::fl_gfx::GamePadAnalogEvent InstanceType;

        GamePadAnalogEvent(VM& vm, const ClassInfo& ci);                // 0x1424c6030
        // @0x1424c8db0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::GamePadAnalogEvent"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c9700
    };

    // 0x60 bytes per instance, vftable 0x143175cc0.
    class IMECandidateListStyle : public CTraits
    {
    public:
        typedef Instances::fl_gfx::IMECandidateListStyle InstanceType;

        IMECandidateListStyle(VM& vm, const ClassInfo& ci);             // 0x1424c6190
        // @0x1424c8de0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::IMECandidateListStyle"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c9760
    };

    // 0x60 bytes per instance, vftable 0x143175910.
    class IMEEventEx : public CTraits
    {
    public:
        typedef Instances::fl_gfx::IMEEventEx InstanceType;

        IMEEventEx(VM& vm, const ClassInfo& ci);                        // 0x1424c63f0
        // @0x1424c8e20
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::IMEEventEx"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c97e0
    };

    // 0x78 bytes per instance, vftable 0x143174cf8.
    class KeyboardEventEx : public CTraits
    {
    public:
        typedef Instances::fl_gfx::KeyboardEventEx InstanceType;

        KeyboardEventEx(VM& vm, const ClassInfo& ci);                   // 0x1424c6780
        // @0x1424c8e90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::KeyboardEventEx"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c9860
    };

    // 0x68 bytes per instance, vftable 0x1431742d0.
    class MouseCursorEvent : public CTraits
    {
    public:
        typedef Instances::fl_gfx::MouseCursorEvent InstanceType;

        MouseCursorEvent(VM& vm, const ClassInfo& ci);                  // 0x1424c6920
        // @0x1424c8ed0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::MouseCursorEvent"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c98c0
    };

    // 0xa0 bytes per instance, vftable 0x1431749e8.
    class MouseEventEx : public CTraits
    {
    public:
        typedef Instances::fl_gfx::MouseEventEx InstanceType;

        MouseEventEx(VM& vm, const ClassInfo& ci);                      // 0x1424c6af0
        // @0x1424c8f10
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::MouseEventEx"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c9950
    };

    // 0x68 bytes per instance, vftable 0x1431755e8.
    class TextEventEx : public CTraits
    {
    public:
        typedef Instances::fl_gfx::TextEventEx InstanceType;

        TextEventEx(VM& vm, const ClassInfo& ci);                       // 0x1424c6de0
        // @0x1424c8f70
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextEventEx"; }
        virtual void MakeObject(Value& result, Traits& t);                  // 0x1424c99c0
    };

}}

namespace ClassTraits { namespace fl_gfx {
    // vftable 0x143174070.
    class Extensions : public Traits
    {
    public:
        Extensions(VM& vm);                                             // 0x1424c51c0
        // @0x1424c8d00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Extensions"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143175470.
    class FocusEventEx : public Traits
    {
    public:
        FocusEventEx(VM& vm);                                           // 0x1424c5300
        // @0x1424c8d20
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FocusEventEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143173ea0.
    class FocusManager : public Traits
    {
    public:
        FocusManager(VM& vm);                                           // 0x1424c5460
        // @0x1424c8d50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FocusManager"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143174e38.
    class GamePad : public Traits
    {
    public:
        GamePad(VM& vm);                                                // 0x1424c5570
        // @0x1424c8d70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GamePad"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143175148.
    class GamePadAnalogEvent : public Traits
    {
    public:
        GamePadAnalogEvent(VM& vm);                                     // 0x1424c5ef0
        // @0x1424c8d90
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GamePadAnalogEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143175d70.
    class IMECandidateListStyle : public Traits
    {
    public:
        IMECandidateListStyle(VM& vm);                                  // 0x1424c6090
        // @0x1424c8dd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IMECandidateListStyle"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x1431759b8.
    class IMEEventEx : public Traits
    {
    public:
        IMEEventEx(VM& vm);                                             // 0x1424c6210
        // @0x1424c8e00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IMEEventEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143175e10.
    class IMEEx : public Traits
    {
    public:
        IMEEx(VM& vm);                                                  // 0x1424c6460
        // @0x1424c8e40
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IMEEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143174520.
    class InteractiveObjectEx : public Traits
    {
    public:
        InteractiveObjectEx(VM& vm);                                    // 0x1424c6570
        // @0x1424c8e60
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::InteractiveObjectEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143174da0.
    class KeyboardEventEx : public Traits
    {
    public:
        KeyboardEventEx(VM& vm);                                        // 0x1424c6680
        // @0x1424c8e80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::KeyboardEventEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143174380.
    class MouseCursorEvent : public Traits
    {
    public:
        MouseCursorEvent(VM& vm);                                       // 0x1424c67e0
        // @0x1424c8eb0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MouseCursorEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143174a90.
    class MouseEventEx : public Traits
    {
    public:
        MouseEventEx(VM& vm);                                           // 0x1424c69a0
        // @0x1424c8ef0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MouseEventEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143173d28.
    class SystemEx : public Traits
    {
    public:
        SystemEx(VM& vm);                                               // 0x1424c6b50
        // @0x1424c8f30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SystemEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x143175690.
    class TextEventEx : public Traits
    {
    public:
        TextEventEx(VM& vm);                                            // 0x1424c6c90
        // @0x1424c8f50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextEventEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    // vftable 0x1431746b0.
    class TextFieldEx : public Traits
    {
    public:
        TextFieldEx(VM& vm);                                            // 0x1424c6e40
        // @0x1424c8f90
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextFieldEx"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
