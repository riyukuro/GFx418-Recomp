// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_EVENTS_H
#define MS2_SF_GFX_AS3_OBJ_EVENTS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/gfx_eventid.h"
#include "ms2/scaleform/include/gfx/gfx_asstringhash.h"
#include "ms2/scaleform/include/kernel/sf_arraystaticbuff.h"

namespace Scaleform { namespace GFx { class DisplayObject; } }

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_events {
    // 0x58 bytes. The constructor, destructor and the virtuals below are bound to the exe; the GC visitor is not
    // declared (the vftables are pinned to the exe).
    class Event : public Instances::fl::Object
    {
    public:
        Event(InstanceTraits::Traits& t);                                   // 0x14245f450
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::Event"; }
        ~Event();                                                           // 0x142462440

        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x142469380
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465470
        // slots 21..23
        virtual const char* GetEventName() const;                           // 0x14246a0d0
        // The class object new events of this type are made with (the VM's Event class).
        virtual AS3::Object* GetEventClass() const;                         // 0x142469fb0
        // A new event of the same traits with the Event fields copied.
        virtual SPtr<Instances::fl_events::Event> Clone() const;            // 0x142466520

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

        ASString                        Type;           // +0x38
        SPtr<Instances::fl::Object>     CurrentTarget;  // +0x40
        SPtr<Instances::fl::Object>     Target;         // +0x48
        UInt32                          Phase;          // +0x50
        bool                            Bubbles : 1;    // +0x54
        bool                            Cancelable : 1;
        bool                            DefaultPrevented : 1;
        bool                            PropagationStopped : 1;
        bool                            ImmPropagationStopped : 1;
    };

    // 0x78 bytes. The constructor is defined in sfr_as3_08.
    class AppLifecycleEvent : public Instances::fl_events::Event
    {
    public:
        AppLifecycleEvent(InstanceTraits::Traits& t);     // 0x14245e850
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::AppLifecycleEvent"; }
        Value           Status;             // +0x58: the event's status object (null until set)

        // @0x14246d240
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f700
        void statusGet(SPtr<Instances::fl::Object>& result);
        // @0x14246f9e0
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d220
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424664e0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x1424653f0
        // (appended, sfr_as3_09) the Event children and Status
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x142469300
    };

    // 0x60 bytes. The constructor is bound to the exe.
    class TextEvent : public Instances::fl_events::Event
    {
    public:
        TextEvent(InstanceTraits::Traits& t);                               // 0x142461a00
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::TextEvent"; }

        ASString Text;      // +0x58

        // @0x14246da40
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f920
        void textGet(ASString& result);
        // @0x14246f9a0
        void textSet(const Value& result, const ASString&);
        // @0x142471e00
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246da20
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466a40
    };

    // 0x60 bytes. The constructor is defined in sfr_as3_08.
    class ErrorEvent : public Instances::fl_events::TextEvent
    {
    public:
        ErrorEvent(InstanceTraits::Traits& t);            // 0x14245eec0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::ErrorEvent"; }

        // @0x14246d310
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246df90
        void errorIDGet(SInt32& result);
        // @0x14246fc30
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d2d0
        SPtr<Instances::fl_events::Event> clone();
    };

    // 0x50 bytes. The constructor and destructor are defined in sfr_as3_08; the GC visitor is bound to the exe.
    class EventDispatcher : public Instances::fl::Object
    {
    public:
        EventDispatcher(InstanceTraits::Traits& t);     // 0x14245f780
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::EventDispatcher"; }
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

        // Dispatches evt to this dispatcher's listeners only (no capture/bubble chain).
        bool DispatchSingleEvent(Instances::fl_events::Event* evt, bool inCapturePhase);   // 0x1424687d0

        struct Listener;
        struct ListenersHash;
        struct EventDispatcherImpl;

        VM*                             pVM;            // +0x38: the traits' VM
        Scaleform::AutoPtr<EventDispatcherImpl> pImpl;           // +0x40: listener tables, made on the first addEventListener

        // (appended, sfr_as3_09) whether a listener of a frame/activation event may be registered (pImpl's Flags)
        bool MayHaveActivateHandler() const;            // 0x14246c230
        bool MayHaveDeactivateHandler() const;          // 0x14246c250
        bool MayHaveEnterFrameHandler() const;          // 0x14246c270
        bool MayHaveExitFrameHandler() const;           // 0x14246c290
        bool MayHaveFrameConstructedHandler() const;    // 0x14246c2b0
        bool MayHaveRenderHandler() const;              // 0x14246c2d0
        // (appended, sfr_as3_09) whether this dispatcher has a listener of type in the capture or target/bubble table
        bool HasEventHandler(const ASString& type, bool useCapture) const;   // 0x14246a160
        // (appended, sfr_as3_09) evt through the capture, target and bubble phases along dobj's display parents
        // (dobj NULL: this dispatcher only)
        void Dispatch(Instances::fl_events::Event* evt, GFx::DisplayObject* dobj);   // 0x142468fa0
        // the AS3 objects of dobj's display parents, nearest first
        void GetParentChain(GFx::DisplayObject* dobj,
                            ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain);   // 0x142466270
        // (appended, sfr_as3_09) new event objects, made by the class object of this dispatcher's traits
        SPtr<Instances::fl_events::Event> CreateEventObject(const ASString& type, bool bubbles, bool cancelable);  // 0x142466cd0
        SPtr<Instances::fl_events::FocusEvent> CreateFocusEventObject(const ASString& type, Instances::fl::Object* relatedObj,
                                                                      unsigned controllerIdx, bool shiftKey,
                                                                      UInt32 keyCode);        // 0x142466e80
        SPtr<Instances::fl_events::Event> CreateIOErrorEventObject(const char* errText);      // 0x142467190
        SPtr<Instances::fl_events::Event> CreateMouseCursorEventObject(const ASString& cursor,
                                                                       unsigned mouseIdx);    // 0x142467620
        SPtr<Instances::fl_events::Event> CreateNetStatusEventObject(const ASString& code,
                                                                     const ASString& level);  // 0x142467b50
        SPtr<Instances::fl_events::Event> CreateProgressEventObject(const ASString& type);    // 0x142467dc0
        // (appended, sfr_as3_09) evt with this dispatcher as its target through Dispatch; false if it was prevented
        bool DispatchEventObject(Instances::fl_events::Event* evt, GFx::DisplayObject* dobj);  // 0x142468740
        // (appended, sfr_as3_09) a new plain event of type at target, to this dispatcher's listeners only; false if
        // it was prevented. With an exception pending nothing is dispatched (logged).
        bool DispatchTypeToTarget(const ASString& type, Instances::fl::Object* target, bool inCapturePhase,
                                  GFx::DisplayObject* dobj);                                  // 0x142468e60
        // (appended, sfr_as3_09) the bubble (parent up) and capture (root down) phases over a parent chain; false
        // when a listener aborted or the propagation was stopped
        bool ExecuteBubblePhase(Instances::fl_events::Event* evt,
                                ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain);   // 0x1424691d0
        bool ExecuteCapturePhase(Instances::fl_events::Event* evt,
                                 ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain);  // 0x142469260
    };

    // One registered listener (0x28 bytes): the function value and the addEventListener options.
    struct EventDispatcher::Listener
    {
        SInt32  Priority;       // +0x00
        bool    UseWeakRef;     // +0x04
        Value   Function;       // +0x08 (the array destructor 0x142462140 releases it at +8)
    };

    // Event type -> listeners of that type. The listener arrays are owned by the table (0x1424624f0).
    struct EventDispatcher::ListenersHash
        : public HashUncachedLH<ASString, ArrayLH<EventDispatcher::Listener>*, ASStringHashFunctor, StatMV_ASString_Mem>
    {
        // MS2-FUNCTIONAL: the exe calls the listener array destructor (0x142462140) out of line; cl inlines it here
        ~ListenersHash()
        {
            for (Iterator it = Begin(); it != End(); ++it)
                delete (*it).Second;
        }
    };

    // The listener tables of a dispatcher, made on the first addEventListener.
    struct EventDispatcher::EventDispatcherImpl : public NewOverrideBase<StatMV_ActionScript_Mem>
    {
        ListenersHash   CaptureListeners;   // +0x0: useCapture listeners
        ListenersHash   Listeners;          // +0x8
        // (appended, sfr_as3_09) which frame/activation events have a listener (+0x10)
        UInt16          HasEnterFrame : 1;
        UInt16          HasActivate : 1;
        UInt16          HasDeactivate : 1;
        UInt16          HasRender : 1;
        UInt16          HasResize : 1;
        UInt16          HasFrameConstructed : 1;
        UInt16          HasExitFrame : 1;
        UInt8           CaptureButtonHandlersCnt;   // +0x12
        UInt8           ButtonHandlersCnt;          // +0x13
    };

    // 0x68 bytes. The constructor is bound to the exe.
    class FocusEvent : public Instances::fl_events::Event
    {
    public:
        FocusEvent(InstanceTraits::Traits& t);                              // 0x14245fac0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::FocusEvent"; }
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x1424694b0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465540

        bool                                            ShiftKey;   // +0x58
        UInt32                                          KeyCode;    // +0x5c
        SPtr<Instances::fl_display::InteractiveObject>  RelatedObj; // +0x60

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d3d0
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) relatedObject returned by value
        // @0x14246efb0
        SPtr<Instances::fl_display::InteractiveObject> relatedObjectGet();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466680
    };

    // 0x88 bytes. The constructor is defined in sfr_as3_08.
    class GestureEvent : public Instances::fl_events::Event
    {
    public:
        GestureEvent(InstanceTraits::Traits& t);          // 0x14245fde0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::GestureEvent"; }
        bool            AltKey;             // +0x58
        bool            CommandKey;         // +0x59
        bool            ControlKey;         // +0x5a
        bool            CtrlKey;            // +0x5b
        bool            ShiftKey;           // +0x5c
        Value::Number   LocalX;             // +0x60
        Value::Number   LocalY;             // +0x68
        Value::Number   StageX;             // +0x70
        Value::Number   StageY;             // +0x78
        UInt32          Phase;              // +0x80: 1 at construction
        bool            LocalInitialized;   // +0x84

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d480
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) LocalX/LocalY from the stage point, once
        // @0x14246a1a0
        void InitLocalCoords();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424666d0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465610
    };

    // 0x60 bytes. The constructor is defined in sfr_as3_08.
    class IMEEvent : public Instances::fl_events::TextEvent
    {
    public:
        IMEEvent(InstanceTraits::Traits& t);              // 0x142460370
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::IMEEvent"; }

        // @0x14246d540
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142470690
        void toString(ASString& result);
    };

    // 0x68 bytes. The constructor is defined in sfr_as3_08.
    class IOErrorEvent : public Instances::fl_events::ErrorEvent
    {
    public:
        IOErrorEvent(InstanceTraits::Traits& t);          // 0x142460510
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::IOErrorEvent"; }
        ASString        ErrorText;          // +0x60

        // @0x14246d570
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246f8e0
        void textGet(ASString& result);
        // @0x14246f960
        void textSet(const Value& result, const ASString&);
        // @0x1424706a0
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d550
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 22: the VM's flash.events.IOErrorEvent class
        virtual AS3::Object* GetEventClass() const;  // 0x142469fe0
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466760
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465770
    };

    // 0x70 bytes. The constructor is bound to the exe.
    class KeyboardEvent : public Instances::fl_events::Event
    {
    public:
        KeyboardEvent(InstanceTraits::Traits& t);                           // 0x1424606d0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::KeyboardEvent"; }

        EventId     EvtId;          // +0x58: KeysState (+0x6a) bit 0 shift, bit 1 ctrl, bit 2 alt
        SInt32      KeyLocation;    // +0x6c
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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d600
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424667b0
    };

    // 0x90 bytes. The constructor is bound to the exe.
    class MouseEvent : public Instances::fl_events::Event
    {
    public:
        MouseEvent(InstanceTraits::Traits& t);                              // 0x142460a60
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::MouseEvent"; }
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x1424697a0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x1424657c0

        bool            AltKey;             // +0x58
        bool            CtrlKey;            // +0x59
        bool            ShiftKey;           // +0x5a
        SInt32          Delta;              // +0x5c
        SPtr<Instances::fl_display::InteractiveObject> RelatedObj;  // +0x60
        Value::Number   LocalX;             // +0x68
        Value::Number   LocalY;             // +0x70
        Value::Number   StageX;             // +0x78
        Value::Number   StageY;             // +0x80
        UInt32          ButtonsMask;        // +0x88: bit 0 left, bit 1 right, bit 2 middle
        bool            LocalInitialized;   // +0x8c: LocalX/LocalY computed from the stage point
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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d6b0
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) LocalX/LocalY from the stage point, once
        // @0x14246a2f0
        void InitLocalCoords();
        // (appended, sfr_as3_09) relatedObject returned by value
        // @0x14246eff0
        SPtr<Instances::fl_display::InteractiveObject> relatedObjectGet();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466820
    };

    // 0x68 bytes. The constructor is defined in sfr_as3_08.
    class NetStatusEvent : public Instances::fl_events::Event
    {
    public:
        NetStatusEvent(InstanceTraits::Traits& t);        // 0x142460c60
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::NetStatusEvent"; }
        ASString        Code;               // +0x58
        ASString        Level;              // +0x60

        // @0x14246d780
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x14246e560
        void infoGet(SPtr<Instances::fl::Object>& result);
        // @0x14246e710
        void infoSet(const Value& result, const Value&);
        // @0x142471140
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d760
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 22: the VM's flash.events.NetStatusEvent class
        virtual AS3::Object* GetEventClass() const;  // 0x14246a030
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424668c0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465950
    };

    // 0xb0 bytes. The constructor is defined in sfr_as3_08.
    class PressAndTapGestureEvent : public Instances::fl_events::GestureEvent
    {
    public:
        PressAndTapGestureEvent(InstanceTraits::Traits& t); // 0x142460e70
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::PressAndTapGestureEvent"; }
        Value::Number   TapLocalX;          // +0x88
        Value::Number   TapLocalY;          // +0x90
        Value::Number   TapStageX;          // +0x98
        Value::Number   TapStageY;          // +0xa0
        bool            TapLocalInitialized; // +0xa8
        bool            Unk_a9;             // +0xa9

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d810
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) TapLocalX/TapLocalY from the tap stage point, once
        // @0x14246a450
        void InitTapLocalCoords();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466930
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x1424659b0
    };

    // 0x68 bytes. The constructor is defined in sfr_as3_08.
    class ProgressEvent : public Instances::fl_events::Event
    {
    public:
        ProgressEvent(InstanceTraits::Traits& t);         // 0x142461040
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::ProgressEvent"; }
        Value::Number   BytesLoaded;        // +0x58
        Value::Number   BytesTotal;         // +0x60

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d8c0
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424669b0
    };

    // 0x98 bytes. The constructor is defined in sfr_as3_08.
    class StageOrientationEvent : public Instances::fl_events::Event
    {
    public:
        StageOrientationEvent(InstanceTraits::Traits& t); // 0x1424614f0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::StageOrientationEvent"; }
        Value           BeforeOrientation;  // +0x58
        Value           AfterOrientation;   // +0x78

        // @0x14246cf90
        void afterOrientationGet(ASString& result);
        // @0x14246d080
        void beforeOrientationGet(ASString& result);
        // @0x14246d990
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142471b70
        void toString(ASString& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246d970
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x1424669f0
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465c10
        // (appended, sfr_as3_09) the Event children and both orientations
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x1424697e0
    };

    // 0x58 bytes. The constructor is defined in sfr_as3_08.
    class TimerEvent : public Instances::fl_events::Event
    {
    public:
        TimerEvent(InstanceTraits::Traits& t);            // 0x142461c00
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::TimerEvent"; }

        // @0x14246daf0
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x142472090
        void toString(ASString& result);
        // @0x142472dc0
        void updateAfterEvent(const Value& result);
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246dad0
        SPtr<Instances::fl_events::Event> clone();
    };

    // 0xa8 bytes. The constructor is defined in sfr_as3_08.
    class TouchEvent : public Instances::fl_events::Event
    {
    public:
        TouchEvent(InstanceTraits::Traits& t);            // 0x142461e70
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::TouchEvent"; }
        bool            AltKey;             // +0x58
        bool            CommandKey;         // +0x59
        bool            ControlKey;         // +0x5a
        bool            CtrlKey;            // +0x5b
        bool            ShiftKey;           // +0x5c
        SPtr<Instances::fl_display::InteractiveObject> RelatedObj;  // +0x60
        Value::Number   LocalX;             // +0x68
        Value::Number   LocalY;             // +0x70
        Value::Number   SizeX;              // +0x78: mapped into the target's space with the local point
        Value::Number   SizeY;              // +0x80
        Value::Number   StageX;             // +0x88
        Value::Number   StageY;             // +0x90
        Value::Number   Pressure;           // +0x98: 1.0 at construction
        SInt32          TouchPointID;       // +0xa0
        bool            IsPrimaryTouchPoint; // +0xa4
        bool            LocalInitialized;   // +0xa5: LocalX/LocalY and SizeX/SizeY mapped into the target's space

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246db00
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) LocalX/LocalY and SizeX/SizeY from the stage point and size, once
        // @0x14246a5c0
        void InitLocalCoords();
        // (appended, sfr_as3_09) relatedObject returned by value
        // @0x14246f030
        SPtr<Instances::fl_display::InteractiveObject> relatedObjectGet();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466a90
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465cd0
        // (appended, sfr_as3_09) RelatedObj (the Event children are not visited)
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x142469880
    };

    // 0xc8 bytes. The constructor is defined in sfr_as3_08.
    class TransformGestureEvent : public Instances::fl_events::GestureEvent
    {
    public:
        TransformGestureEvent(InstanceTraits::Traits& t); // 0x1424620d0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::TransformGestureEvent"; }
        Value::Number   OffsetX;            // +0x88: the offset in stage space
        Value::Number   OffsetY;            // +0x90
        Value::Number   LocalOffsetX;       // +0x98: the offset in the target's parent space (offsetX/offsetY)
        Value::Number   LocalOffsetY;       // +0xa0
        Value::Number   ScaleX;             // +0xa8: 1.0 at construction
        Value::Number   ScaleY;             // +0xb0: 1.0 at construction
        Value::Number   Rotation;           // +0xb8
        bool            LocalOffsetInitialized; // +0xc0

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
        // (appended, sfr_as3_09) clone() returning the new event
        // @0x14246dbb0
        SPtr<Instances::fl_events::Event> clone();
        // (appended, sfr_as3_09) LocalOffsetX/Y from the stage offset, in the target's parent space, once
        // @0x14246a780
        void InitLocalOffset();
        // (appended, sfr_as3_09) slot 23: Event::Clone plus this class's fields
        virtual SPtr<Instances::fl_events::Event> Clone() const;  // 0x142466b70
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x142465f00
    };

    // 0x68 bytes. The constructor is defined in sfr_as3_08.
    class AsyncErrorEvent : public Instances::fl_events::ErrorEvent
    {
    public:
        AsyncErrorEvent(InstanceTraits::Traits& t);                         // 0x14245ea80
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_events::AsyncErrorEvent"; }
        ~AsyncErrorEvent();                                                 // 0x1424623e0

        SPtr<Instances::fl::Object> ErrorObj;   // +0x60: the error the event reports
    };

}}

namespace InstanceTraits { namespace fl_events {
    // The instance traits of flash.events.EventDispatcher, also used by classes whose instances are plain dispatchers
    // (flash.system.IME). The constructor is defined in sfr_as3_08.
    class EventDispatcher : public CTraits
    {
    public:
        typedef Instances::fl_events::EventDispatcher InstanceType;

        EventDispatcher(VM& vm, const ClassInfo& ci);   // 0x14245f5d0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::EventDispatcher"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b8e0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ac60
    };
}}


namespace InstanceTraits { namespace fl_events {
    // The instance traits of flash.events.AppLifecycleEvent (instances 0x78 bytes).
    class AppLifecycleEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::AppLifecycleEvent InstanceType;

        AppLifecycleEvent(VM& vm, const ClassInfo& ci);                       // 0x14245e820
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::AppLifecycleEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b690
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246a9e0
    };

    // The instance traits of flash.events.AsyncErrorEvent (instances 0x68 bytes).
    class AsyncErrorEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::AsyncErrorEvent InstanceType;

        AsyncErrorEvent(VM& vm, const ClassInfo& ci);                         // 0x14245ea50
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::AsyncErrorEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b780
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246aad0
    };

    // The instance traits of flash.events.ErrorEvent (instances 0x60 bytes).
    class ErrorEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::ErrorEvent InstanceType;

        ErrorEvent(VM& vm, const ClassInfo& ci);                              // 0x14245ee90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ErrorEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b7e0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ab50
    };

    // The instance traits of flash.events.Event (instances 0x58 bytes).
    class Event : public CTraits
    {
    public:
        typedef Instances::fl_events::Event InstanceType;

        Event(VM& vm, const ClassInfo& ci);                                   // 0x14245f420
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Event"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b840
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246abc0
    };

    // The instance traits of flash.events.FocusEvent (instances 0x68 bytes).
    class FocusEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::FocusEvent InstanceType;

        FocusEvent(VM& vm, const ClassInfo& ci);                              // 0x14245fa90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::FocusEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b950
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ace0
    };

    // The instance traits of flash.events.GestureEvent (instances 0x88 bytes).
    class GestureEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::GestureEvent InstanceType;

        GestureEvent(VM& vm, const ClassInfo& ci);                            // 0x14245fdb0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::GestureEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246b9f0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ad90
    };

    // The instance traits of flash.events.IMEEvent (instances 0x60 bytes).
    class IMEEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::IMEEvent InstanceType;

        IMEEvent(VM& vm, const ClassInfo& ci);                                // 0x142460340
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::IMEEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246ba30
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ade0
    };

    // The instance traits of flash.events.IOErrorEvent (instances 0x68 bytes).
    class IOErrorEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::IOErrorEvent InstanceType;

        IOErrorEvent(VM& vm, const ClassInfo& ci);                            // 0x1424604e0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::IOErrorEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246ba90
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246ae50
    };

    // The instance traits of flash.events.KeyboardEvent (instances 0x70 bytes).
    class KeyboardEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::KeyboardEvent InstanceType;

        KeyboardEvent(VM& vm, const ClassInfo& ci);                           // 0x1424606a0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::KeyboardEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bb00
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246aed0
    };

    // The instance traits of flash.events.MouseEvent (instances 0x90 bytes).
    class MouseEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::MouseEvent InstanceType;

        MouseEvent(VM& vm, const ClassInfo& ci);                              // 0x142460a30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::MouseEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bbb0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246af90
    };

    // The instance traits of flash.events.NetStatusEvent (instances 0x68 bytes).
    class NetStatusEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::NetStatusEvent InstanceType;

        NetStatusEvent(VM& vm, const ClassInfo& ci);                          // 0x142460c30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::NetStatusEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bc80
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b070
    };

    // The instance traits of flash.events.PressAndTapGestureEvent (instances 0xb0 bytes).
    class PressAndTapGestureEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::PressAndTapGestureEvent InstanceType;

        PressAndTapGestureEvent(VM& vm, const ClassInfo& ci);                 // 0x142460e40
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::PressAndTapGestureEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bd60
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b160
    };

    // The instance traits of flash.events.ProgressEvent (instances 0x68 bytes).
    class ProgressEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::ProgressEvent InstanceType;

        ProgressEvent(VM& vm, const ClassInfo& ci);                           // 0x142461010
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ProgressEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bde0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b1f0
    };

    // The instance traits of flash.events.StageOrientationEvent (instances 0x98 bytes).
    class StageOrientationEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::StageOrientationEvent InstanceType;

        StageOrientationEvent(VM& vm, const ClassInfo& ci);                   // 0x1424614c0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::StageOrientationEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246be80
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b2a0
    };

    // The instance traits of flash.events.TextEvent (instances 0x60 bytes).
    class TextEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::TextEvent InstanceType;

        TextEvent(VM& vm, const ClassInfo& ci);                               // 0x1424619d0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246bfc0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b3f0
    };

    // The instance traits of flash.events.TimerEvent (instances 0x58 bytes).
    class TimerEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::TimerEvent InstanceType;

        TimerEvent(VM& vm, const ClassInfo& ci);                              // 0x142461bd0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TimerEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246c000
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b440
    };

    // The instance traits of flash.events.TouchEvent (instances 0xa8 bytes).
    class TouchEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::TouchEvent InstanceType;

        TouchEvent(VM& vm, const ClassInfo& ci);                              // 0x142461e40
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TouchEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246c0a0
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b4f0
    };

    // The instance traits of flash.events.TransformGestureEvent (instances 0xc8 bytes).
    class TransformGestureEvent : public CTraits
    {
    public:
        typedef Instances::fl_events::TransformGestureEvent InstanceType;

        TransformGestureEvent(VM& vm, const ClassInfo& ci);                   // 0x1424620a0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TransformGestureEvent"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x14246c190
        // (appended, sfr_as3_09) a new instance (the exe's MakeObject inlines it)
        Pickable<InstanceType> MakeInstance(Traits& t);         // 0x14246b5e0
    };

}}

namespace Classes { namespace fl_events {
    // 0x58 bytes.
    class ActivityEvent : public Class
    {
    public:
        ActivityEvent(ClassTraits::Traits& t);                           // 0x14245e6a0
        virtual const char* GetAS3ObjectType() const { return "Classes::ActivityEvent"; }

        const char* Activity;               // +0x50
    };

    // 0x60 bytes.
    class AppLifecycleEvent : public Class
    {
    public:
        AppLifecycleEvent(ClassTraits::Traits& t);                       // 0x14245e7e0
        virtual const char* GetAS3ObjectType() const { return "Classes::AppLifecycleEvent"; }

        const char* OnPause;                // +0x50
        const char* OnResume;               // +0x58
    };

    // 0x58 bytes.
    class AsyncErrorEvent : public Class
    {
    public:
        AsyncErrorEvent(ClassTraits::Traits& t);                         // 0x14245ea20
        virtual const char* GetAS3ObjectType() const { return "Classes::AsyncErrorEvent"; }

        const char* AsyncError;             // +0x50
    };

    // 0x60 bytes.
    class ContextMenuEvent : public Class
    {
    public:
        ContextMenuEvent(ClassTraits::Traits& t);                        // 0x14245ebc0
        virtual const char* GetAS3ObjectType() const { return "Classes::ContextMenuEvent"; }

        const char* MenuItemSelect;         // +0x50
        const char* MenuSelect;             // +0x58
    };

    // 0x60 bytes.
    class DataEvent : public Class
    {
    public:
        DataEvent(ClassTraits::Traits& t);                               // 0x14245ed10
        virtual const char* GetAS3ObjectType() const { return "Classes::DataEvent"; }

        const char* Data;                   // +0x50
        const char* UploadCompleteData;     // +0x58
    };

    // 0x58 bytes.
    class ErrorEvent : public Class
    {
    public:
        ErrorEvent(ClassTraits::Traits& t);                              // 0x14245ee60
        virtual const char* GetAS3ObjectType() const { return "Classes::ErrorEvent"; }

        const char* Error;                  // +0x50
    };

    // 0x180 bytes.
    class Event : public Class
    {
    public:
        Event(ClassTraits::Traits& t);                                   // 0x14245f1f0
        virtual const char* GetAS3ObjectType() const { return "Classes::Event"; }

        const char* Activate;               // +0x50
        const char* Added;                  // +0x58
        const char* AddedToStage;           // +0x60
        const char* Cancel;                 // +0x68
        const char* Change;                 // +0x70
        const char* Close;                  // +0x78
        const char* Closing;                // +0x80
        const char* Complete;               // +0x88
        const char* Connect;                // +0x90
        const char* Deactivate;             // +0x98
        const char* Displaying;             // +0xa0
        const char* EnterFrame;             // +0xa8
        const char* Exiting;                // +0xb0
        const char* ExitFrame;              // +0xb8
        const char* FrameConstructed;       // +0xc0
        const char* FullScreen;             // +0xc8
        const char* HtmlBoundsChange;       // +0xd0
        const char* HtmlDOMInitialize;      // +0xd8
        const char* HtmlRender;             // +0xe0
        const char* Id3;                    // +0xe8
        const char* Init;                   // +0xf0
        const char* LocationChange;         // +0xf8
        const char* MouseLeave;             // +0x100
        const char* NetworkChange;          // +0x108
        const char* Open;                   // +0x110
        const char* Removed;                // +0x118
        const char* RemovedFromStage;       // +0x120
        const char* Render;                 // +0x128
        const char* Resize;                 // +0x130
        const char* Scroll;                 // +0x138
        const char* Select;                 // +0x140
        const char* SoundComplete;          // +0x148
        const char* TabChildrenChange;      // +0x150
        const char* TabEnabledChange;       // +0x158
        const char* TabIndexChange;         // +0x160
        const char* Unload;                 // +0x168
        const char* UserIdle;               // +0x170
        const char* UserPresent;            // +0x178
    };

    // 0x60 bytes.
    class EventDispatcher : public Class
    {
    public:
        EventDispatcher(ClassTraits::Traits& t);                         // 0x14245f5a0
        virtual const char* GetAS3ObjectType() const { return "Classes::EventDispatcher"; }

        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;      // 0x1424693e0

        SPtr<AS3::Object> Unk50;            // +0x50: purpose not recovered (visited by the GC)
        SPtr<AS3::Object> Unk58;            // +0x58

        // (appended, sfr_as3_09) new event objects of the VM's event classes ("Ex" classes when the VM has them on)
        SPtr<Instances::fl_events::Event> CreateEventObject(const ASString& type, bool bubbles, bool cancelable);  // 0x142466be0
        SPtr<Instances::fl_events::FocusEvent> CreateFocusEventObject(const ASString& type, Instances::fl::Object* relatedObj,
                                                                      unsigned controllerIdx, bool shiftKey,
                                                                      UInt32 keyCode);        // 0x142466d20
        SPtr<Instances::fl_events::Event> CreateIOErrorEventObject(const char* errText);      // 0x142466ff0
        SPtr<Instances::fl_events::KeyboardEvent> CreateKeyboardEventObject(const EventId& evtId, const ASString& type,
                                                                            Instances::fl::Object* target);  // 0x142467340
        SPtr<Instances::fl_events::Event> CreateMouseCursorEventObject(const ASString& cursor,
                                                                       unsigned mouseIdx);    // 0x1424674c0
        SPtr<Instances::fl_events::MouseEvent> CreateMouseEventObject(const EventId& evtId, const ASString& type,
                                                                      Instances::fl::Object* target);  // 0x142467790
        SPtr<Instances::fl_events::Event> CreateNetStatusEventObject(const ASString& code,
                                                                     const ASString& level);  // 0x1424679d0
        SPtr<Instances::fl_events::Event> CreateProgressEventObject(const ASString& type);    // 0x142467ce0
    };

    // 0x60 bytes.
    class EventPhase : public Class
    {
    public:
        EventPhase(ClassTraits::Traits& t);                              // 0x14245f8d0
        virtual const char* GetAS3ObjectType() const { return "Classes::EventPhase"; }

        UInt32      AtTarget;               // +0x50: 2
        UInt32      BubblingPhase;          // +0x54: 3
        UInt32      CapturingPhase;         // +0x58: 1
    };

    // 0x70 bytes.
    class FocusEvent : public Class
    {
    public:
        FocusEvent(ClassTraits::Traits& t);                              // 0x14245fa40
        virtual const char* GetAS3ObjectType() const { return "Classes::FocusEvent"; }

        const char* FocusIn;                // +0x50
        const char* FocusOut;               // +0x58
        const char* KeyFocusChange;         // +0x60
        const char* MouseFocusChange;       // +0x68
    };

    // 0x58 bytes.
    class FullScreenEvent : public Class
    {
    public:
        FullScreenEvent(ClassTraits::Traits& t);                         // 0x14245fc40
        virtual const char* GetAS3ObjectType() const { return "Classes::FullScreenEvent"; }

        const char* FullScreen;             // +0x50
    };

    // 0x58 bytes.
    class GestureEvent : public Class
    {
    public:
        GestureEvent(ClassTraits::Traits& t);                            // 0x14245fd80
        virtual const char* GetAS3ObjectType() const { return "Classes::GestureEvent"; }

        const char* GestureTwoFingerTap;    // +0x50
    };

    // 0x70 bytes.
    class GesturePhase : public Class
    {
    public:
        GesturePhase(ClassTraits::Traits& t);                            // 0x14245ff80
        virtual const char* GetAS3ObjectType() const { return "Classes::GesturePhase"; }

        const char* All;                    // +0x50
        const char* Begin;                  // +0x58
        const char* End;                    // +0x60
        const char* Update;                 // +0x68
    };

    // 0x60 bytes.
    class HTTPStatusEvent : public Class
    {
    public:
        HTTPStatusEvent(ClassTraits::Traits& t);                         // 0x1424600e0
        virtual const char* GetAS3ObjectType() const { return "Classes::HTTPStatusEvent"; }

        const char* HttpResponseStatus;     // +0x50
        const char* HttpStatus;             // +0x58
    };

    // 0x58 bytes.
    class IMEEvent : public Class
    {
    public:
        IMEEvent(ClassTraits::Traits& t);                                // 0x142460310
        virtual const char* GetAS3ObjectType() const { return "Classes::IMEEvent"; }

        const char* ImeComposition;         // +0x50
    };

    // 0x58 bytes.
    class IOErrorEvent : public Class
    {
    public:
        IOErrorEvent(ClassTraits::Traits& t);                            // 0x1424604b0
        virtual const char* GetAS3ObjectType() const { return "Classes::IOErrorEvent"; }

        const char* IoError;                // +0x50
    };

    // 0x60 bytes.
    class KeyboardEvent : public Class
    {
    public:
        KeyboardEvent(ClassTraits::Traits& t);                           // 0x142460660
        virtual const char* GetAS3ObjectType() const { return "Classes::KeyboardEvent"; }

        const char* KeyDown;                // +0x50
        const char* KeyUp;                  // +0x58
    };

    // 0xd8 bytes.
    class MouseEvent : public Class
    {
    public:
        MouseEvent(ClassTraits::Traits& t);                              // 0x142460930
        virtual const char* GetAS3ObjectType() const { return "Classes::MouseEvent"; }

        const char* Click;                  // +0x50
        const char* ContextMenu;            // +0x58
        const char* DoubleClick;            // +0x60
        const char* MiddleClick;            // +0x68
        const char* MiddleMouseDown;        // +0x70
        const char* MiddleMouseUp;          // +0x78
        const char* MouseDown;              // +0x80
        const char* MouseMove;              // +0x88
        const char* MouseOut;               // +0x90
        const char* MouseOver;              // +0x98
        const char* MouseUp;                // +0xa0
        const char* MouseWheel;             // +0xa8
        const char* RightClick;             // +0xb0
        const char* RightMouseDown;         // +0xb8
        const char* RightMouseUp;           // +0xc0
        const char* RollOut;                // +0xc8
        const char* RollOver;               // +0xd0
    };

    // 0x58 bytes.
    class NetStatusEvent : public Class
    {
    public:
        NetStatusEvent(ClassTraits::Traits& t);                          // 0x142460c00
        virtual const char* GetAS3ObjectType() const { return "Classes::NetStatusEvent"; }

        const char* NetStatus;              // +0x50
    };

    // 0x58 bytes.
    class PressAndTapGestureEvent : public Class
    {
    public:
        PressAndTapGestureEvent(ClassTraits::Traits& t);                 // 0x142460e10
        virtual const char* GetAS3ObjectType() const { return "Classes::PressAndTapGestureEvent"; }

        const char* GesturePressAndTap;     // +0x50
    };

    // 0x60 bytes.
    class ProgressEvent : public Class
    {
    public:
        ProgressEvent(ClassTraits::Traits& t);                           // 0x142460fd0
        virtual const char* GetAS3ObjectType() const { return "Classes::ProgressEvent"; }

        const char* Progress;               // +0x50
        const char* SocketData;             // +0x58
    };

    // 0x58 bytes.
    class SecurityErrorEvent : public Class
    {
    public:
        SecurityErrorEvent(ClassTraits::Traits& t);                      // 0x1424611c0
        virtual const char* GetAS3ObjectType() const { return "Classes::SecurityErrorEvent"; }

        const char* SecurityError;          // +0x50
    };

    // 0x78 bytes.
    class StageOrientation : public Class
    {
    public:
        StageOrientation(ClassTraits::Traits& t);                        // 0x142461310
        virtual const char* GetAS3ObjectType() const { return "Classes::StageOrientation"; }

        const char* Default;                // +0x50
        const char* RotatedLeft;            // +0x58
        const char* RotatedRight;           // +0x60
        const char* Unknown;                // +0x68
        const char* UpsideDown;             // +0x70
    };

    // 0x60 bytes.
    class StageOrientationEvent : public Class
    {
    public:
        StageOrientationEvent(ClassTraits::Traits& t);                   // 0x142461480
        virtual const char* GetAS3ObjectType() const { return "Classes::StageOrientationEvent"; }

        const char* OrientationChange;      // +0x50
        const char* OrientationChanging;    // +0x58
    };

    // 0x58 bytes.
    class StatusEvent : public Class
    {
    public:
        StatusEvent(ClassTraits::Traits& t);                             // 0x142461710
        virtual const char* GetAS3ObjectType() const { return "Classes::StatusEvent"; }

        const char* Status;                 // +0x50
    };

    // 0x58 bytes.
    class SyncEvent : public Class
    {
    public:
        SyncEvent(ClassTraits::Traits& t);                               // 0x142461850
        virtual const char* GetAS3ObjectType() const { return "Classes::SyncEvent"; }

        const char* Sync;                   // +0x50
    };

    // 0x60 bytes.
    class TextEvent : public Class
    {
    public:
        TextEvent(ClassTraits::Traits& t);                               // 0x142461990
        virtual const char* GetAS3ObjectType() const { return "Classes::TextEvent"; }

        const char* Link;                   // +0x50
        const char* TextInput;              // +0x58
    };

    // 0x60 bytes.
    class TimerEvent : public Class
    {
    public:
        TimerEvent(ClassTraits::Traits& t);                              // 0x142461b90
        virtual const char* GetAS3ObjectType() const { return "Classes::TimerEvent"; }

        const char* Timer;                  // +0x50
        const char* TimerComplete;          // +0x58
    };

    // 0x90 bytes.
    class TouchEvent : public Class
    {
    public:
        TouchEvent(ClassTraits::Traits& t);                              // 0x142461dc0
        virtual const char* GetAS3ObjectType() const { return "Classes::TouchEvent"; }

        const char* TouchBegin;             // +0x50
        const char* TouchEnd;               // +0x58
        const char* TouchMove;              // +0x60
        const char* TouchOut;               // +0x68
        const char* TouchOver;              // +0x70
        const char* TouchRollOut;           // +0x78
        const char* TouchRollOver;          // +0x80
        const char* TouchTap;               // +0x88
    };

    // 0x70 bytes.
    class TransformGestureEvent : public Class
    {
    public:
        TransformGestureEvent(ClassTraits::Traits& t);                   // 0x142462050
        virtual const char* GetAS3ObjectType() const { return "Classes::TransformGestureEvent"; }

        const char* GesturePan;             // +0x50
        const char* GestureRotate;          // +0x58
        const char* GestureSwipe;           // +0x60
        const char* GestureZoom;            // +0x68
    };

}}

namespace ClassTraits { namespace fl_events {
    class ActivityEvent : public Traits
    {
    public:
        ActivityEvent(VM& vm);                                   // 0x14245e590
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ActivityEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245bd20
    };

    class AppLifecycleEvent : public Traits
    {
    public:
        AppLifecycleEvent(VM& vm);                               // 0x14245e6d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AppLifecycleEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245d350
    };

    class AsyncErrorEvent : public Traits
    {
    public:
        AsyncErrorEvent(VM& vm);                                 // 0x14245e910
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AsyncErrorEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ContextMenuEvent : public Traits
    {
    public:
        ContextMenuEvent(VM& vm);                                // 0x14245eab0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ContextMenuEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class DataEvent : public Traits
    {
    public:
        DataEvent(VM& vm);                                       // 0x14245ec00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::DataEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245ada0
    };

    class ErrorEvent : public Traits
    {
    public:
        ErrorEvent(VM& vm);                                      // 0x14245ed50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ErrorEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Event : public Traits
    {
    public:
        Event(VM& vm);                                           // 0x14245eef0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Event"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245b8b0
    };

    class EventDispatcher : public Traits
    {
    public:
        EventDispatcher(VM& vm);                                 // 0x14245f4b0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EventDispatcher"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x142459920
    };

    class EventPhase : public Traits
    {
    public:
        EventPhase(VM& vm);                                      // 0x14245f7d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EventPhase"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245a120
    };

    class FocusEvent : public Traits
    {
    public:
        FocusEvent(VM& vm);                                      // 0x14245f910
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FocusEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FullScreenEvent : public Traits
    {
    public:
        FullScreenEvent(VM& vm);                                 // 0x14245fb30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FullScreenEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245b180
    };

    class GestureEvent : public Traits
    {
    public:
        GestureEvent(VM& vm);                                    // 0x14245fc70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GestureEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class GesturePhase : public Traits
    {
    public:
        GesturePhase(VM& vm);                                    // 0x14245fe70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GesturePhase"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245cd30
    };

    class HTTPStatusEvent : public Traits
    {
    public:
        HTTPStatusEvent(VM& vm);                                 // 0x14245ffd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::HTTPStatusEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245b4c0
    };

    class IEventDispatcher : public Traits
    {
    public:
        IEventDispatcher(VM& vm);                                // 0x142460120
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IEventDispatcher"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245cc10
    };

    class IMEEvent : public Traits
    {
    public:
        IMEEvent(VM& vm);                                        // 0x142460200
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IMEEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245cea0
    };

    class IOErrorEvent : public Traits
    {
    public:
        IOErrorEvent(VM& vm);                                    // 0x1424603a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IOErrorEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class KeyboardEvent : public Traits
    {
    public:
        KeyboardEvent(VM& vm);                                   // 0x142460550
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::KeyboardEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MouseEvent : public Traits
    {
    public:
        MouseEvent(VM& vm);                                      // 0x142460750
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MouseEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245d120
    };

    class NetStatusEvent : public Traits
    {
    public:
        NetStatusEvent(VM& vm);                                  // 0x142460af0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::NetStatusEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class PressAndTapGestureEvent : public Traits
    {
    public:
        PressAndTapGestureEvent(VM& vm);                         // 0x142460d00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::PressAndTapGestureEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ProgressEvent : public Traits
    {
    public:
        ProgressEvent(VM& vm);                                   // 0x142460ec0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ProgressEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SecurityErrorEvent : public Traits
    {
    public:
        SecurityErrorEvent(VM& vm);                              // 0x1424610b0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SecurityErrorEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageOrientation : public Traits
    {
    public:
        StageOrientation(VM& vm);                                // 0x1424611f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageOrientation"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageOrientationEvent : public Traits
    {
    public:
        StageOrientationEvent(VM& vm);                           // 0x142461370
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageOrientationEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245dcb0
    };

    class StatusEvent : public Traits
    {
    public:
        StatusEvent(VM& vm);                                     // 0x142461600
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StatusEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SyncEvent : public Traits
    {
    public:
        SyncEvent(VM& vm);                                       // 0x142461740
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SyncEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextEvent : public Traits
    {
    public:
        TextEvent(VM& vm);                                       // 0x142461880
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TimerEvent : public Traits
    {
    public:
        TimerEvent(VM& vm);                                      // 0x142461a80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TimerEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x1424592a0
    };

    class TouchEvent : public Traits
    {
    public:
        TouchEvent(VM& vm);                                      // 0x142461c60
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TouchEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);                // 0x14245da30
    };

    class TransformGestureEvent : public Traits
    {
    public:
        TransformGestureEvent(VM& vm);                           // 0x142461f20
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TransformGestureEvent"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
