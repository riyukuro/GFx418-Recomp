// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_EVENTS_H
#define MS2_SF_GFX_AS3_OBJ_EVENTS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_events {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Event : public Instances::fl::Object
    {
    public:
        // @0x14246d0d0
        void bubblesGet(bool& result);
        // @0x14246d1d0
        void cancelableGet(bool& result);
        // @0x14246d330
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246de10
        void currentTargetGet(SPtr<Instances::fl::Object>& result);
        // @0x14246dfb0
        void eventPhaseGet(UInt32& result);
        // @0x14246dfc0
        void formatToString(Value& result, unsigned, const Value*);
        // @0x14246e960
        void isDefaultPrevented(bool& result);
        // @0x14246efa0
        void preventDefault(const Value& result);
        // @0x14246f720
        void stopImmediatePropagation(const Value& result);
        // @0x14246f730
        void stopPropagation(const Value& result);
        // @0x14246f880
        void targetGet(SPtr<Instances::fl::Object>& result);
        // @0x14246fc50
        void toString(ASString& result);
        // @0x142472d20
        void typeGet(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class AppLifecycleEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d240
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f700
        void statusGet(SPtr<Instances::fl::Object>& result);
        // @0x14246f9e0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TextEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246da40
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f920
        void textGet(ASString& result);
        // @0x14246f9a0
        void textSet(const Value& result, const ASString&);
        // @0x142471e00
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ErrorEvent : public Instances::fl_events::TextEvent
    {
    public:
        // @0x14246d310
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246df90
        void errorIDGet(SInt32& result);
        // @0x14246fc30
        void toString(ASString& result);
    };

    // 0x50 bytes. The constructor, destructor and GC visitor are not recovered yet (bound to the exe).
    class EventDispatcher : public Instances::fl::Object
    {
    public:
        EventDispatcher(InstanceTraits::Traits& t);     // 0x14245f780
        ~EventDispatcher();                             // 0x1424624c0

    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;  // 0x142469440

    public:
        // @0x14246caa0
        void addEventListener(const Value& result, const ASString&, const Value&, bool, SInt32, bool);
        // @0x14246ded0
        void dispatchEvent(bool& result, Instances::fl_events::Event*);
        // @0x14246e490
        void hasEventListener(bool& result, const ASString&);
        // @0x14246f1c0
        void removeEventListener(const Value& result, const ASString&, const Value&, bool);
        // @0x142472e00
        void willTrigger(bool& result, const ASString&);

        struct EventDispatcherImpl;

        VM*                             pVM;            // +0x38: the traits' VM
        AutoPtr<EventDispatcherImpl>    pImpl;          // +0x40: listener tables, made on the first addEventListener
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class FocusEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d3f0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246de90
        void directionGet(ASString& result);
        // @0x14246deb0
        void directionSet(const Value& result, const ASString&);
        // @0x14246e9b0
        void keyCodeGet(UInt32& result);
        // @0x14246e9d0
        void keyCodeSet(const Value& result, UInt32);
        // @0x14246efe0
        void relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result);
        // @0x14246f070
        void relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject*);
        // @0x14246f4a0
        void shiftKeyGet(bool& result);
        // @0x14246f4f0
        void shiftKeySet(const Value& result, bool);
        // @0x14246feb0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GestureEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246cff0
        void altKeyGet(bool& result);
        // @0x14246d030
        void altKeySet(const Value& result, bool);
        // @0x14246d4a0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246dc60
        void commandKeyGet(bool& result);
        // @0x14246dca0
        void commandKeySet(const Value& result, bool);
        // @0x14246dcf0
        void controlKeyGet(bool& result);
        // @0x14246dd30
        void controlKeySet(const Value& result, bool);
        // @0x14246dd80
        void ctrlKeyGet(bool& result);
        // @0x14246ddc0
        void ctrlKeySet(const Value& result, bool);
        // @0x14246ea30
        void localXGet(Value::Number& result);
        // @0x14246eaf0
        void localXSet(const Value& result, Value::Number);
        // @0x14246eb80
        void localYGet(Value::Number& result);
        // @0x14246ec40
        void localYSet(const Value& result, Value::Number);
        // @0x14246edd0
        void phaseGet(ASString& result);
        // @0x14246ee90
        void phaseSet(const Value& result, const ASString&);
        // @0x14246f4b0
        void shiftKeyGet(bool& result);
        // @0x14246f500
        void shiftKeySet(const Value& result, bool);
        // @0x14246f640
        void stageXGet(Value::Number& result);
        // @0x14246f6a0
        void stageYGet(Value::Number& result);
        // @0x1424701d0
        void toString(ASString& result);
        // @0x142472d60
        void updateAfterEvent(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class IMEEvent : public Instances::fl_events::TextEvent
    {
    public:
        // @0x14246d540
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142470690
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class IOErrorEvent : public Instances::fl_events::ErrorEvent
    {
    public:
        // @0x14246d570
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f8e0
        void textGet(ASString& result);
        // @0x14246f960
        void textSet(const Value& result, const ASString&);
        // @0x1424706a0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class KeyboardEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d000
        void altKeyGet(bool& result);
        // @0x14246d040
        void altKeySet(const Value& result, bool);
        // @0x14246d1e0
        void charCodeGet(UInt32& result);
        // @0x14246d1f0
        void charCodeSet(const Value& result, UInt32);
        // @0x14246d620
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246dc70
        void commandKeyGet(bool& result);
        // @0x14246dcb0
        void commandKeySet(const Value& result, bool);
        // @0x14246dd00
        void controlKeyGet(bool& result);
        // @0x14246dd40
        void controlKeySet(const Value& result, bool);
        // @0x14246dd90
        void ctrlKeyGet(bool& result);
        // @0x14246ddd0
        void ctrlKeySet(const Value& result, bool);
        // @0x14246e9c0
        void keyCodeGet(UInt32& result);
        // @0x14246e9e0
        void keyCodeSet(const Value& result, UInt32);
        // @0x14246e9f0
        void keyLocationGet(UInt32& result);
        // @0x14246ea20
        void keyLocationSet(const Value& result, UInt32);
        // @0x14246f4c0
        void shiftKeyGet(bool& result);
        // @0x14246f510
        void shiftKeySet(const Value& result, bool);
        // @0x142470890
        void toString(ASString& result);
        // @0x142472d80
        void updateAfterEvent(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class MouseEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d010
        void altKeyGet(bool& result);
        // @0x14246d060
        void altKeySet(const Value& result, bool);
        // @0x14246d0e0
        void buttonDownGet(bool& result);
        // @0x14246d0f0
        void buttonDownSet(const Value& result, bool);
        // @0x14246d200
        void clickCountGet(SInt32& result);
        // @0x14246d6d0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246dc80
        void commandKeyGet(bool& result);
        // @0x14246dcd0
        void commandKeySet(const Value& result, bool);
        // @0x14246dd10
        void controlKeyGet(bool& result);
        // @0x14246dd60
        void controlKeySet(const Value& result, bool);
        // @0x14246dda0
        void ctrlKeyGet(bool& result);
        // @0x14246ddf0
        void ctrlKeySet(const Value& result, bool);
        // @0x14246de70
        void deltaGet(SInt32& result);
        // @0x14246de80
        void deltaSet(const Value& result, SInt32);
        // @0x14246ea70
        void localXGet(Value::Number& result);
        // @0x14246eb20
        void localXSet(const Value& result, Value::Number);
        // @0x14246ebc0
        void localYGet(Value::Number& result);
        // @0x14246ec70
        void localYSet(const Value& result, Value::Number);
        // @0x14246f020
        void relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result);
        // @0x14246f0e0
        void relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject*);
        // @0x14246f4d0
        void shiftKeyGet(bool& result);
        // @0x14246f530
        void shiftKeySet(const Value& result, bool);
        // @0x14246f660
        void stageXGet(Value::Number& result);
        // @0x14246f6c0
        void stageYGet(Value::Number& result);
        // @0x142470c80
        void toString(ASString& result);
        // @0x142472da0
        void updateAfterEvent(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NetStatusEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d780
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246e560
        void infoGet(SPtr<Instances::fl::Object>& result);
        // @0x14246e710
        void infoSet(const Value& result, const Value&);
        // @0x142471140
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class PressAndTapGestureEvent : public Instances::fl_events::GestureEvent
    {
    public:
        // @0x14246d830
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f740
        void tapLocalXGet(Value::Number& result);
        // @0x14246f780
        void tapLocalXSet(const Value& result, Value::Number);
        // @0x14246f7c0
        void tapLocalYGet(Value::Number& result);
        // @0x14246f800
        void tapLocalYSet(const Value& result, Value::Number);
        // @0x14246f840
        void tapStageXGet(Value::Number& result);
        // @0x14246f860
        void tapStageYGet(Value::Number& result);
        // @0x1424713e0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ProgressEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d110
        void bytesLoadedGet(Value::Number& result);
        // @0x14246d130
        void bytesLoadedSet(const Value& result, Value::Number);
        // @0x14246d170
        void bytesTotalGet(Value::Number& result);
        // @0x14246d190
        void bytesTotalSet(const Value& result, Value::Number);
        // @0x14246d8e0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x1424718a0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class StageOrientationEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246cf90
        void afterOrientationGet(ASString& result);
        // @0x14246d080
        void beforeOrientationGet(ASString& result);
        // @0x14246d990
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142471b70
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TimerEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246daf0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142472090
        void toString(ASString& result);
        // @0x142472dc0
        void updateAfterEvent(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TouchEvent : public Instances::fl_events::Event
    {
    public:
        // @0x14246d020
        void altKeyGet(bool& result);
        // @0x14246d070
        void altKeySet(const Value& result, bool);
        // @0x14246db20
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246dc90
        void commandKeyGet(bool& result);
        // @0x14246dce0
        void commandKeySet(const Value& result, bool);
        // @0x14246dd20
        void controlKeyGet(bool& result);
        // @0x14246dd70
        void controlKeySet(const Value& result, bool);
        // @0x14246ddb0
        void ctrlKeyGet(bool& result);
        // @0x14246de00
        void ctrlKeySet(const Value& result, bool);
        // @0x14246e970
        void isPrimaryTouchPointGet(bool& result);
        // @0x14246e980
        void isPrimaryTouchPointSet(const Value& result, bool);
        // @0x14246e990
        void isRelatedObjectInaccessibleGet(bool& result);
        // @0x14246e9a0
        void isRelatedObjectInaccessibleSet(const Value& result, bool);
        // @0x14246eab0
        void localXGet(Value::Number& result);
        // @0x14246eb50
        void localXSet(const Value& result, Value::Number);
        // @0x14246ec00
        void localYGet(Value::Number& result);
        // @0x14246eca0
        void localYSet(const Value& result, Value::Number);
        // @0x14246ef80
        void pressureGet(Value::Number& result);
        // @0x14246ef90
        void pressureSet(const Value& result, Value::Number);
        // @0x14246f060
        void relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result);
        // @0x14246f150
        void relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject*);
        // @0x14246f4e0
        void shiftKeyGet(bool& result);
        // @0x14246f540
        void shiftKeySet(const Value& result, bool);
        // @0x14246f550
        void sizeXGet(Value::Number& result);
        // @0x14246f590
        void sizeXSet(const Value& result, Value::Number);
        // @0x14246f5c0
        void sizeYGet(Value::Number& result);
        // @0x14246f600
        void sizeYSet(const Value& result, Value::Number);
        // @0x14246f680
        void stageXGet(Value::Number& result);
        // @0x14246f6e0
        void stageYGet(Value::Number& result);
        // @0x1424720a0
        void toString(ASString& result);
        // @0x142472d00
        void touchPointIDGet(SInt32& result);
        // @0x142472d10
        void touchPointIDSet(const Value& result, SInt32);
        // @0x142472de0
        void updateAfterEvent(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TransformGestureEvent : public Instances::fl_events::GestureEvent
    {
    public:
        // @0x14246dbd0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246ecd0
        void offsetXGet(Value::Number& result);
        // @0x14246ed10
        void offsetXSet(const Value& result, Value::Number);
        // @0x14246ed50
        void offsetYGet(Value::Number& result);
        // @0x14246ed90
        void offsetYSet(const Value& result, Value::Number);
        // @0x14246f2b0
        void rotationGet(Value::Number& result);
        // @0x14246f2c0
        void rotationSet(const Value& result, Value::Number);
        // @0x14246f2d0
        void scaleXGet(Value::Number& result);
        // @0x14246f2e0
        void scaleXSet(const Value& result, Value::Number);
        // @0x14246f2f0
        void scaleYGet(Value::Number& result);
        // @0x14246f300
        void scaleYSet(const Value& result, Value::Number);
        // @0x1424726d0
        void toString(ASString& result);
    };

}}

namespace InstanceTraits { namespace fl_events {
    // The instance traits of flash.events.EventDispatcher, also used by classes whose instances are plain dispatchers
    // (flash.system.IME). Only the constructor is declared so far.
    class EventDispatcher : public CTraits
    {
    public:
        EventDispatcher(VM& vm, const ClassInfo& ci);   // 0x14245f5d0
    };
}}

}}} // namespace Scaleform::GFx::AS3

#endif
