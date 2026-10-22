// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_09
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424653f0-0x142473710 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"

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

// Is a value of type `className` (its class looked up by name in the VM; 0x1425145d0).
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14246c440
void VM::OutputAndIgnoreException()
{
    HandleException = false;
    OutputError(ExceptionObj);
    ExceptionObj.SetUndefined();
}

// The movie root's per-event lists of the display objects with a listener of a frame/activation event (+0x150 of
// MovieRoot, not in as3_asvm.h yet).
class EventChains
{
public:
    void AddToChain(EventId::IdCode code, DisplayObject* dobj);
    void RemoveFromChain(EventId::IdCode code, DisplayObject* dobj);
};

namespace Instances { namespace fl_events {

    // ---- AS3Constructor: new X(type, bubbles = false, cancelable = false, ...) -------------------------------------------

    // @0x142465470
    void Event::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc < 1)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Event::AS3Constructor", 1, 1, argc));
            return;
        }
        argv[0].Convert2String(Type);
        if (argc >= 2)
            Bubbles = argv[1].Convert2Boolean();
        if (argc >= 3)
            Cancelable = argv[2].Convert2Boolean();
    }

    // @0x1424653f0
    void AppLifecycleEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        VM& vm = GetVM();
        if (argc >= 4)
        {
            Status = argv[3];
            if (!argv[3].IsNull())
                Status.ToStringValue(vm.GetStringManager());
        }
    }

    // @0x142465540
    void FocusEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
        {
            RelatedObj = NULL;
            if (argv[3].GetObject() && FUN_1425145d0(GetVM(), argv[3], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(argv[3].GetObject());
        }
        if (argc >= 5)
            ShiftKey = argv[4].Convert2Boolean();
        if (argc >= 6)
        {
            UInt32 v;
            argv[5].Convert2UInt32(v);
            KeyCode = v;
        }
    }

    // @0x142465610
    // MS2-FUNCTIONAL: the exe zeroes the phaseSet result Value before loading the phase string and saves rbp inside the branch
    void GestureEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
            phaseSet(Value(), argv[3].AsString());
        if (argc >= 5)
        {
            Value::Number v;
            argv[4].Convert2Number(v);
            LocalInitialized = true;
            LocalX = Render::PixelsToTwips(v);
        }
        if (argc >= 6)
        {
            Value::Number v;
            argv[5].Convert2Number(v);
            LocalInitialized = true;
            LocalY = Render::PixelsToTwips(v);
        }
        if (argc >= 7)
            CommandKey = argv[6].Convert2Boolean();
        if (argc >= 8)
            AltKey = argv[7].Convert2Boolean();
        if (argc >= 9)
            ControlKey = argv[8].Convert2Boolean();
        if (argc >= 10)
            CtrlKey = argv[9].Convert2Boolean();
        if (argc >= 11)
            ShiftKey = argv[10].Convert2Boolean();
    }

    // @0x142465770
    void IOErrorEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
            argv[3].Convert2String(ErrorText);
    }

    // @0x1424657c0
    void MouseEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
        {
            Value::Number v;
            argv[3].Convert2Number(v);
            LocalInitialized = true;
            LocalX = Render::PixelsToTwips(v);
        }
        if (argc >= 5)
        {
            Value::Number v;
            argv[4].Convert2Number(v);
            LocalInitialized = true;
            LocalY = Render::PixelsToTwips(v);
        }
        if (argc >= 6)
        {
            RelatedObj = NULL;
            if (argv[5].GetObject() && FUN_1425145d0(GetVM(), argv[5], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(argv[5].GetObject());
        }
        if (argc >= 7)
            CtrlKey = argv[6].Convert2Boolean();
        if (argc >= 8)
            AltKey = argv[7].Convert2Boolean();
        if (argc >= 9)
            ShiftKey = argv[8].Convert2Boolean();
        if (argc >= 10)
        {
            if (argv[9].Convert2Boolean())
                ButtonsMask |= 1;
            else
                ButtonsMask &= ~1u;
        }
        if (argc >= 11)
            argv[10].Convert2Int32(Delta);
    }

    // @0x142465950
    void NetStatusEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
            argv[3].Convert2String(Code);
        if (argc >= 5)
            argv[4].Convert2String(Level);
    }

    // @0x1424659b0
    void PressAndTapGestureEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
            phaseSet(Value(), argv[3].AsString());
        if (argc >= 5)
            localXSet(Value(), argv[4].AsNumber());
        if (argc >= 6)
            localYSet(Value(), argv[5].AsNumber());
        if (argc >= 7)
            tapLocalXSet(Value(), argv[6].AsNumber());
        if (argc >= 8)
            tapLocalYSet(Value(), argv[7].AsNumber());
        if (argc >= 9)
            CommandKey = argv[8].Convert2Boolean();
        if (argc >= 10)
            AltKey = argv[9].Convert2Boolean();
        if (argc >= 11)
            ControlKey = argv[10].Convert2Boolean();
        if (argc >= 12)
            CtrlKey = argv[11].Convert2Boolean();
        if (argc >= 13)
            ShiftKey = argv[12].Convert2Boolean();
    }

    // @0x142465c10
    // MS2-FUNCTIONAL: the exe also saves r15 around the first branch (unused); register frame differs
    void StageOrientationEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        VM& vm = GetVM();
        if (argc >= 4)
        {
            BeforeOrientation = argv[3];
            if (!argv[3].IsNull())
                BeforeOrientation.ToStringValue(vm.GetStringManager());
        }
        if (argc >= 5)
        {
            AfterOrientation = argv[4];
            // The exe tests argv[3] here.
            if (!argv[3].IsNull())
                AfterOrientation.ToStringValue(vm.GetStringManager());
        }
    }

    // @0x142465cd0
    // MS2-FUNCTIONAL: argc/argv land in rbx/rsi in the exe, rsi/rdi here
    void TouchEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
            argv[3].Convert2Int32(TouchPointID);
        if (argc >= 5)
            IsPrimaryTouchPoint = argv[4].Convert2Boolean();
        if (argc >= 6)
        {
            Value::Number v;
            argv[5].Convert2Number(v);
            LocalInitialized = true;
            LocalX = Render::PixelsToTwips(v);
        }
        if (argc >= 7)
        {
            Value::Number v;
            argv[6].Convert2Number(v);
            LocalInitialized = true;
            LocalY = Render::PixelsToTwips(v);
        }
        if (argc >= 8)
        {
            Value::Number v;
            argv[7].Convert2Number(v);
            LocalInitialized = true;
            SizeX = Render::PixelsToTwips(v);
        }
        if (argc >= 9)
        {
            Value::Number v;
            argv[8].Convert2Number(v);
            LocalInitialized = true;
            SizeY = Render::PixelsToTwips(v);
        }
        if (argc >= 10)
        {
            // pressure: converted and dropped
            Value::Number v;
            argv[9].Convert2Number(v);
        }
        if (argc >= 11)
        {
            RelatedObj = NULL;
            // The exe takes the object from argv[5] and type-tests argv[10].
            if (argv[5].GetObject() && FUN_1425145d0(GetVM(), argv[10], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(argv[5].GetObject());
        }
        if (argc >= 12)
            CommandKey = argv[11].Convert2Boolean();
        if (argc >= 13)
            AltKey = argv[12].Convert2Boolean();
        if (argc >= 14)
            ControlKey = argv[13].Convert2Boolean();
        if (argc >= 15)
            CtrlKey = argv[14].Convert2Boolean();
        if (argc >= 16)
            ShiftKey = argv[15].Convert2Boolean();
    }

    // @0x142465f00
    // MS2-FUNCTIONAL: the inlined GestureEvent::AS3Constructor is scheduled differently
    void TransformGestureEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        GestureEvent::AS3Constructor(argc, argv);
        if (argc >= 4)
            phaseSet(Value(), argv[3].AsString());
        // The exe stores localX/localY into the gesture point but flags the offset as initialized.
        if (argc >= 5)
        {
            Value::Number v;
            argv[4].Convert2Number(v);
            LocalOffsetInitialized = true;
            LocalX = Render::PixelsToTwips(v);
        }
        if (argc >= 6)
        {
            Value::Number v;
            argv[5].Convert2Number(v);
            LocalOffsetInitialized = true;
            LocalY = Render::PixelsToTwips(v);
        }
        if (argc >= 7)
            argv[6].Convert2Number(ScaleX);
        if (argc >= 8)
            argv[7].Convert2Number(ScaleY);
        if (argc >= 9)
            argv[8].Convert2Number(Rotation);
        if (argc >= 10)
        {
            Value::Number v;
            argv[9].Convert2Number(v);
            OffsetX = Render::PixelsToTwips(v);
        }
        if (argc >= 11)
        {
            Value::Number v;
            argv[10].Convert2Number(v);
            OffsetY = Render::PixelsToTwips(v);
        }
        if (argc >= 12)
            CommandKey = argv[11].Convert2Boolean();
        if (argc >= 13)
            AltKey = argv[12].Convert2Boolean();
        if (argc >= 14)
            ControlKey = argv[13].Convert2Boolean();
        if (argc >= 15)
            CtrlKey = argv[14].Convert2Boolean();
        if (argc >= 16)
            ShiftKey = argv[15].Convert2Boolean();
    }

    // ---- Dispatch: the listeners of this dispatcher, and the capture/target/bubble walk ---------------------------------

    // @0x142466270
    // MS2-FUNCTIONAL: the exe reaches the AS3 part through the AvmInteractiveObjBase slot (vslot 1) and the PushBack
    // growth is laid out inline; the same chain
    void EventDispatcher::GetParentChain(GFx::DisplayObject* dobj,
                                         ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain)
    {
        for (InteractiveObject* p = dobj->GetParent(); p; p = p->GetParent())
        {
            // the AS3 part (AS3::AvmDisplayObj, as3_avm.h) keeps the object raw at +0x10 or as a tagged SPtr at +0x08
            const UPInt* avm = reinterpret_cast<const UPInt*>(p->GetAvmObjImpl());
            UPInt raw = avm[2] ? avm[2] : avm[1];
            Instances::fl_display::DisplayObject* o =
                reinterpret_cast<Instances::fl_display::DisplayObject*>(raw & ~UPInt(1));
            SPtr<Instances::fl_display::DisplayObject> s(o);
            if (s)
                chain.PushBack(s);
        }
    }

    // @0x1424687d0
    // MS2-FUNCTIONAL: register allocation and the listener copy loop; the same calls and exception handling
    bool EventDispatcher::DispatchSingleEvent(Instances::fl_events::Event* evt, bool inCapturePhase)
    {
        if (!pImpl)
            return true;

        SPtr<EventDispatcher> self(this);
        ListenersHash& hash = inCapturePhase ? pImpl->CaptureListeners : pImpl->Listeners;
        ArrayLH<Listener>** plisteners = hash.Get(evt->Type);
        bool ok = true;
        if (plisteners)
        {
            evt->CurrentTarget = this;
            ArrayLH<Listener>& listeners = **plisteners;
            UPInt n = listeners.GetSize();
            if (n == 1)
            {
                const Listener& l = listeners[0];
                if (l.Function.IsValidWeakRef())
                {
                    Value _this;
                    Value arg(evt);
                    Value result;
                    GetVM().ExecuteInternalUnsafe(l.Function.IsWeakRef() ? Value(l.Function, StrongRefValue) : l.Function,
                                                  _this, result, 1, &arg, false);
                    VM& vm = GetVM();
                    ok = !vm.IsException();
                    if (!ok)
                        vm.OutputAndIgnoreException();
                }
            }
            else if (n > 1)
            {
                // the listeners may change while they run: call a copy (ten in the frame, more on the heap)
                UInt64 buf[10 * sizeof(Listener) / sizeof(UInt64)];
                Listener* copies = n > 10 ? (Listener*)SF_HEAP_AUTO_ALLOC(this, n * sizeof(Listener))
                                          : reinterpret_cast<Listener*>(buf);
                for (UPInt i = 0; i < n; ++i)
                    Scaleform::Construct(&copies[i], listeners[i]);

                UPInt i = 0;
                for (; i < n; ++i)
                {
                    Listener& l = copies[i];
                    if (l.Function.IsValidWeakRef())
                    {
                        Value _this;
                        Value result;
                        Value arg(evt);
                        GetVM().ExecuteInternalUnsafe(l.Function.IsWeakRef() ? Value(l.Function, StrongRefValue)
                                                                             : l.Function,
                                                      _this, result, 1, &arg, false);
                        VM& vm = GetVM();
                        if (vm.IsException())
                        {
                            vm.HandleException = false;
                            vm.OutputError(vm.ExceptionObj);
                            vm.ExceptionObj.SetUndefined();
                            ok = false;
                        }
                        if (evt->ImmPropagationStopped || !ok)
                        {
                            Destruct(&l);
                            break;
                        }
                    }
                    Destruct(&l);
                }
                for (++i; i < n; ++i)
                    Destruct(&copies[i]);
                if (copies != reinterpret_cast<Listener*>(buf))
                    SF_FREE(copies);
            }
        }
        return ok;
    }

    // @0x142468fa0
    // MS2-FUNCTIONAL: block layout of the three phase loops; the same order of dispatches and stop tests
    void EventDispatcher::Dispatch(Instances::fl_events::Event* evt, GFx::DisplayObject* dobj)
    {
        if (!dobj)
        {
            DispatchSingleEvent(evt, false);
            return;
        }

        SPtr<EventDispatcher> self(this);
        Ptr<GFx::DisplayObject> pdobj(dobj);
        ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32> chain(GetVM().GetMemoryHeap());
        GetParentChain(dobj, chain);

        // capture: from the root down to the parent
        evt->Phase = 1;
        for (SPInt i = (SPInt)chain.GetSize() - 1; i >= 0; --i)
        {
            if (!chain[i]->DispatchSingleEvent(evt, true))
            {
                if (chain[i]->pDispObj)
                    chain[i]->pDispObj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
                return;
            }
            if (evt->PropagationStopped || evt->ImmPropagationStopped)
                return;
        }

        // target
        evt->Phase = 2;
        if (!DispatchSingleEvent(evt, false))
        {
            dobj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
            return;
        }
        if (evt->PropagationStopped || evt->ImmPropagationStopped || !evt->Bubbles)
            return;

        // bubble: from the parent up to the root
        evt->Phase = 3;
        for (UPInt i = 0; i < chain.GetSize(); ++i)
        {
            if (!chain[i]->DispatchSingleEvent(evt, false))
            {
                if (chain[i]->pDispObj)
                    chain[i]->pDispObj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
                return;
            }
            if (evt->PropagationStopped || evt->ImmPropagationStopped)
                return;
        }
    }

    // ---- Clone: a new event of the same class from (type, bubbles, cancelable), with the state copied -----------------

    // @0x142466520
    // MS2-FUNCTIONAL: the flag bit copies xor the operands in the other order
    SPtr<Instances::fl_events::Event> Event::Clone() const
    {
        SPtr<Instances::fl_events::Event> result;
        Value argv[3] = { Value(Type), Value(Bubbles), Value(Cancelable) };
        static_cast<ASVM&>(GetVM()).ConstructInstance(result, GetEventClass(), 3, argv);
        result->CurrentTarget = CurrentTarget;
        result->Target = Target;
        result->DefaultPrevented = DefaultPrevented;
        result->PropagationStopped = PropagationStopped;
        result->ImmPropagationStopped = ImmPropagationStopped;
        return result;
    }

    // @0x1424664e0
    SPtr<Instances::fl_events::Event> AppLifecycleEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        AppLifecycleEvent* p = static_cast<AppLifecycleEvent*>(result.GetPtr());
        p->Status = Status;
        return result;
    }

    // @0x142466680
    SPtr<Instances::fl_events::Event> FocusEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        FocusEvent* p = static_cast<FocusEvent*>(result.GetPtr());
        p->RelatedObj = RelatedObj;
        p->ShiftKey = ShiftKey;
        p->KeyCode = KeyCode;
        return result;
    }

    // @0x1424666d0
    SPtr<Instances::fl_events::Event> GestureEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        GestureEvent* p = static_cast<GestureEvent*>(result.GetPtr());
        p->AltKey = AltKey;
        p->CommandKey = CommandKey;
        p->ControlKey = ControlKey;
        p->CtrlKey = CtrlKey;
        p->ShiftKey = ShiftKey;
        p->LocalX = LocalX;
        p->LocalY = LocalY;
        p->StageX = StageX;
        p->StageY = StageY;
        p->Phase = Phase;
        p->LocalInitialized = LocalInitialized;
        return result;
    }

    // @0x142466760
    SPtr<Instances::fl_events::Event> IOErrorEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        IOErrorEvent* p = static_cast<IOErrorEvent*>(result.GetPtr());
        p->ErrorText = ErrorText;
        return result;
    }

    // @0x1424667b0
    SPtr<Instances::fl_events::Event> KeyboardEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        KeyboardEvent* p = static_cast<KeyboardEvent*>(result.GetPtr());
        p->EvtId.Id = EvtId.Id;
        p->EvtId.WcharCode = EvtId.WcharCode;
        p->EvtId.KeyCode = EvtId.KeyCode;
        p->EvtId.AsciiCode = EvtId.AsciiCode;
        p->EvtId.RollOverCnt = EvtId.RollOverCnt;
        p->EvtId.KeyboardIndex = EvtId.KeyboardIndex;
        p->EvtId.KeysState = EvtId.KeysState;
        p->EvtId.MouseWheelDelta = EvtId.MouseWheelDelta;
        p->KeyLocation = KeyLocation;
        return result;
    }

    // @0x142466820
    SPtr<Instances::fl_events::Event> MouseEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        MouseEvent* p = static_cast<MouseEvent*>(result.GetPtr());
        p->AltKey = AltKey;
        p->CtrlKey = CtrlKey;
        p->ShiftKey = ShiftKey;
        p->Delta = Delta;
        p->RelatedObj = RelatedObj;
        p->LocalX = LocalX;
        p->LocalY = LocalY;
        p->StageX = StageX;
        p->StageY = StageY;
        p->ButtonsMask = ButtonsMask;
        p->LocalInitialized = LocalInitialized;
        return result;
    }

    // @0x1424668c0
    SPtr<Instances::fl_events::Event> NetStatusEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        NetStatusEvent* p = static_cast<NetStatusEvent*>(result.GetPtr());
        p->Code = Code;
        p->Level = Level;
        return result;
    }

    // @0x142466930
    SPtr<Instances::fl_events::Event> PressAndTapGestureEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = GestureEvent::Clone();
        PressAndTapGestureEvent* p = static_cast<PressAndTapGestureEvent*>(result.GetPtr());
        p->TapLocalX = TapLocalX;
        p->TapLocalY = TapLocalY;
        p->TapStageX = TapStageX;
        p->TapStageY = TapStageY;
        p->TapLocalInitialized = TapLocalInitialized;
        p->Unk_a9 = Unk_a9;
        return result;
    }

    // @0x1424669b0
    SPtr<Instances::fl_events::Event> ProgressEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        ProgressEvent* p = static_cast<ProgressEvent*>(result.GetPtr());
        p->BytesLoaded = BytesLoaded;
        p->BytesTotal = BytesTotal;
        return result;
    }

    // @0x1424669f0
    SPtr<Instances::fl_events::Event> StageOrientationEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        StageOrientationEvent* p = static_cast<StageOrientationEvent*>(result.GetPtr());
        p->BeforeOrientation = BeforeOrientation;
        p->AfterOrientation = AfterOrientation;
        return result;
    }

    // @0x142466a40 (also ErrorEvent, AsyncErrorEvent and IMEEvent's)
    SPtr<Instances::fl_events::Event> TextEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        TextEvent* p = static_cast<TextEvent*>(result.GetPtr());
        p->Text = Text;
        return result;
    }

    // @0x142466a90
    SPtr<Instances::fl_events::Event> TouchEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = Event::Clone();
        TouchEvent* p = static_cast<TouchEvent*>(result.GetPtr());
        p->AltKey = AltKey;
        p->CommandKey = CommandKey;
        p->ControlKey = ControlKey;
        p->CtrlKey = CtrlKey;
        p->ShiftKey = ShiftKey;
        p->Pressure = Pressure;
        p->RelatedObj = RelatedObj;
        p->LocalX = LocalX;
        p->LocalY = LocalY;
        p->StageX = StageX;
        p->StageY = StageY;
        p->SizeX = SizeX;
        p->SizeY = SizeY;
        p->TouchPointID = TouchPointID;
        p->IsPrimaryTouchPoint = IsPrimaryTouchPoint;
        p->LocalInitialized = LocalInitialized;
        return result;
    }

    // @0x142466b70
    SPtr<Instances::fl_events::Event> TransformGestureEvent::Clone() const
    {
        SPtr<Instances::fl_events::Event> result = GestureEvent::Clone();
        TransformGestureEvent* p = static_cast<TransformGestureEvent*>(result.GetPtr());
        p->OffsetX = OffsetX;
        p->OffsetY = OffsetY;
        p->ScaleX = ScaleX;
        p->ScaleY = ScaleY;
        p->Rotation = Rotation;
        return result;
    }

    // ---- event classes -----------------------------------------------------------------------------------------------

    // @0x142469fe0
    AS3::Object* IOErrorEvent::GetEventClass() const
    {
        return GetVM().GetClass(StringDataPtr("flash.events.IOErrorEvent"));
    }

    // @0x14246a030
    AS3::Object* NetStatusEvent::GetEventClass() const
    {
        return GetVM().GetClass(StringDataPtr("flash.events.NetStatusEvent"));
    }

    // ---- EventDispatcher listener queries ----------------------------------------------------------------------------

    // @0x14246c230
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveActivateHandler() const
    {
        if (pImpl)
            return pImpl->HasActivate;
        return false;
    }
    // @0x14246c250
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveDeactivateHandler() const
    {
        if (pImpl)
            return pImpl->HasDeactivate;
        return false;
    }
    // @0x14246c270
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveEnterFrameHandler() const
    {
        if (pImpl)
            return pImpl->HasEnterFrame;
        return false;
    }
    // @0x14246c290
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveExitFrameHandler() const
    {
        if (pImpl)
            return pImpl->HasExitFrame;
        return false;
    }
    // @0x14246c2b0
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveFrameConstructedHandler() const
    {
        if (pImpl)
            return pImpl->HasFrameConstructed;
        return false;
    }
    // @0x14246c2d0
    // MS2-FUNCTIONAL: cl tests the flag bit and returns 0/1 by branches; the exe shifts the flag word into eax
    bool EventDispatcher::MayHaveRenderHandler() const
    {
        if (pImpl)
            return pImpl->HasRender;
        return false;
    }

    // @0x14246a160
    // MS2-FUNCTIONAL: cl inlines the listener table lookup (0x1424698c0) that the exe calls
    bool EventDispatcher::HasEventHandler(const ASString& type, bool useCapture) const
    {
        if (pImpl)
        {
            const ListenersHash& h = useCapture ? pImpl->CaptureListeners : pImpl->Listeners;
            ArrayLH<Listener>* const* pa = h.Get(type);
            if (pa && *pa && (*pa)->GetSize() > 0)
                return true;
        }
        return false;
    }

    // A dispatcher that is a display object instance (not its class) dispatches along its display parent chain.
    static inline bool IsDisplayObjectInstance(const Traits& tr)
    {
        return (unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
                   (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
               tr.IsInstanceTraits();
    }

    // @0x14246ded0
    // MS2-FUNCTIONAL: register allocation of the display object test
    void EventDispatcher::dispatchEvent(bool& result, Instances::fl_events::Event* e)
    {
        if (!e)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, vm));
            return;
        }
        e->Target = this;
        GFx::DisplayObject* dobj = NULL;
        if (IsDisplayObjectInstance(GetTraits()))
            dobj = static_cast<Instances::fl_display::DisplayObject*>(this)->pDispObj;
        Dispatch(e, dobj);
        result = !e->DefaultPrevented;
    }

    // @0x14246e490
    // MS2-FUNCTIONAL: the exe copies the type string around the two inlined lookups
    void EventDispatcher::hasEventListener(bool& result, const ASString& type)
    {
        result = HasEventHandler(type, true);
        if (!result)
            result = HasEventHandler(type, false);
    }

    // @0x142472e00
    // MS2-FUNCTIONAL: cl lays out the inlined listener lookups differently
    void EventDispatcher::willTrigger(bool& result, const ASString& type)
    {
        result = HasEventHandler(type, true);
        if (!result)
            result = HasEventHandler(type, false);
        if (result || !IsDisplayObjectInstance(GetTraits()))
            return;
        ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32> chain(GetVM().GetMemoryHeap());
        GetParentChain(static_cast<Instances::fl_display::DisplayObject*>(this)->pDispObj, chain);
        for (UPInt i = 0; i < chain.GetSize(); ++i)
        {
            result = chain[i]->HasEventHandler(type, true) || chain[i]->HasEventHandler(type, false);
            if (result)
                break;
        }
    }

    // ---- add/removeEventListener -------------------------------------------------------------------------------------
    // The frame/activation events keep the display object in the movie root's event chain while it has a listener;
    // the button events count their listeners.

    namespace
    {
        // AS3 builtin strings and event ids of the frame/activation and button events (4.1.18 numbering)
        enum
        {
            BI_activate = 28, BI_deactivate = 33, BI_enterFrame = 34, BI_frameConstructed = 35, BI_exitFrame = 36,
            BI_render = 43, BI_resize = 44, BI_click = 46, BI_doubleClick = 47, BI_mouseDown = 48, BI_mouseOut = 50,
            BI_mouseOver = 51, BI_mouseUp = 52, BI_rollOut = 54, BI_rollOver = 55
        };
        enum
        {
            EV_Activate = 0x1000011, EV_Deactivate, EV_Render, EV_Resize, EV_FrameConstructed, EV_ExitFrame
        };

        inline EventChains& GetEventChains(ASVM& vm)
        {
            return *reinterpret_cast<EventChains*>(reinterpret_cast<UByte*>(vm.GetMovieRoot()) + 0x150);
        }

        inline bool IsButtonEvent(const StringManager& sm, const ASString& type)
        {
            return type == sm.GetBuiltin(BuiltinType(BI_mouseDown)) || type == sm.GetBuiltin(BuiltinType(BI_mouseUp)) ||
                   type == sm.GetBuiltin(BuiltinType(BI_click)) || type == sm.GetBuiltin(BuiltinType(BI_doubleClick)) ||
                   type == sm.GetBuiltin(BuiltinType(BI_mouseOver)) || type == sm.GetBuiltin(BuiltinType(BI_mouseOut)) ||
                   type == sm.GetBuiltin(BuiltinType(BI_rollOver)) || type == sm.GetBuiltin(BuiltinType(BI_rollOut));
        }
    }

    // @0x14246caa0
    // MS2-FUNCTIONAL: cl orders the duplicate scan and the builtin compares differently
    void EventDispatcher::addEventListener(const Value& result, const ASString& type, const Value& listener,
                                           bool useCapture, SInt32 priority, bool useWeakReference)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        if (!pImpl)
            pImpl = SF_HEAP_NEW(vm.GetMemoryHeap()) EventDispatcherImpl();
        ListenersHash& hash = useCapture ? pImpl->CaptureListeners : pImpl->Listeners;

        ArrayLH<Listener>* listeners;
        ArrayLH<Listener>** pa = hash.Get(type);
        if (!pa)
        {
            listeners = SF_HEAP_NEW(vm.GetMemoryHeap()) ArrayLH<Listener>();
            hash.Add(type, listeners);
        }
        else
            listeners = *pa;

        // listeners stay sorted by descending priority; the same function is registered only once
        UPInt i = 0, n = listeners->GetSize();
        for (; i < n; ++i)
        {
            Listener& l = (*listeners)[i];
            if (l.Function.IsValidWeakRef() && StrictEqual(l.Function, listener))
                return;
            if ((*listeners)[i].Priority < priority)
                break;
        }
        for (UPInt j = i; j < listeners->GetSize(); ++j)
        {
            Listener& l = (*listeners)[j];
            if (l.Function.IsValidWeakRef() && StrictEqual(l.Function, listener))
                return;
        }

        const StringManager& sm = vm.GetStringManager();
        EventId::IdCode code;
        if (type == sm.GetBuiltin(BuiltinType(BI_enterFrame)))
        {
            code = EventId::Event_EnterFrame;
            static_cast<ASVM&>(vm).GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
            pImpl->HasEnterFrame = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_frameConstructed)))
        {
            code = EventId::IdCode(EV_FrameConstructed);
            pImpl->HasFrameConstructed = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_exitFrame)))
        {
            code = EventId::IdCode(EV_ExitFrame);
            pImpl->HasExitFrame = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_activate)))
        {
            code = EventId::IdCode(EV_Activate);
            pImpl->HasActivate = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_deactivate)))
        {
            code = EventId::IdCode(EV_Deactivate);
            pImpl->HasDeactivate = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_render)))
        {
            code = EventId::IdCode(EV_Render);
            pImpl->HasRender = 1;
        }
        else if (type == sm.GetBuiltin(BuiltinType(BI_resize)))
        {
            code = EventId::IdCode(EV_Resize);
            pImpl->HasResize = 1;
        }
        else
        {
            code = EventId::Event_Invalid;
            if (IsButtonEvent(sm, type))
            {
                UInt8& cnt = useCapture ? pImpl->CaptureButtonHandlersCnt : pImpl->ButtonHandlersCnt;
                if (cnt != 0xff)
                    ++cnt;
            }
        }
        if (code != EventId::Event_Invalid && listeners->GetSize() == 0 && IsDisplayObjectInstance(GetTraits()))
            GetEventChains(static_cast<ASVM&>(vm))
                .AddToChain(code, static_cast<Instances::fl_display::DisplayObject*>(this)->pDispObj);

        Listener l;
        l.Priority = priority;
        l.Function = listener;
        listeners->InsertAt(i, l);
        if (useWeakReference)
            (*listeners)[i].Function.MakeWeakRef();
    }

    // The event chain and the button listener count after the last listener of a type was removed (0x14246c2f0).
    // @0x14246c2f0
    // MS2-FUNCTIONAL: cl lays out the builtin compares differently
    static __declspec(noinline) void OnListenerRemoved(EventDispatcher* d, const ASString& type, bool useCapture,
                                                       UPInt remaining)
    {
        ASVM& vm = static_cast<ASVM&>(d->GetVM());
        if (!vm.GetMovieRoot())
            return;
        EventId::IdCode code;
        if (type == vm.GetBuiltin(BuiltinType(BI_enterFrame)))
        {
            code = EventId::Event_EnterFrame;
            vm.GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
        }
        else if (type == vm.GetBuiltin(BuiltinType(BI_frameConstructed)))
            code = EventId::IdCode(EV_FrameConstructed);
        else if (type == vm.GetBuiltin(BuiltinType(BI_exitFrame)))
            code = EventId::IdCode(EV_ExitFrame);
        else if (type == vm.GetBuiltin(BuiltinType(BI_activate)))
            code = EventId::IdCode(EV_Activate);
        else if (type == vm.GetBuiltin(BuiltinType(BI_deactivate)))
            code = EventId::IdCode(EV_Deactivate);
        else if (type == vm.GetBuiltin(BuiltinType(BI_render)))
            code = EventId::IdCode(EV_Render);
        else
        {
            if (IsButtonEvent(vm.GetMovieRoot()->BuiltinsMgr, type))
            {
                UInt8& cnt = useCapture ? d->pImpl->CaptureButtonHandlersCnt : d->pImpl->ButtonHandlersCnt;
                if (cnt != 0xff)
                    --cnt;
            }
            return;
        }
        if (remaining == 0 && IsDisplayObjectInstance(d->GetTraits()))
            GetEventChains(vm).RemoveFromChain(code, static_cast<Instances::fl_display::DisplayObject*>(d)->pDispObj);
    }

    // @0x14246f1c0
    // MS2-FUNCTIONAL: cl keeps the listener array in a different register and frame
    void EventDispatcher::removeEventListener(const Value& result, const ASString& type, const Value& listener,
                                              bool useCapture)
    {
        SF_UNUSED(result);
        if (!pImpl)
            return;
        ListenersHash& hash = useCapture ? pImpl->CaptureListeners : pImpl->Listeners;
        ArrayLH<Listener>** pa = hash.Get(type);
        if (!pa)
            return;
        ArrayLH<Listener>* listeners = *pa;
        for (UPInt i = 0, n = listeners->GetSize(); i < n; ++i)
        {
            if ((*listeners)[i].Function.IsValidWeakRef() && StrictEqual((*listeners)[i].Function, listener))
            {
                listeners->RemoveAt(i);
                OnListenerRemoved(this, type, useCapture, listeners->GetSize());
                return;
            }
        }
    }

    // ---- local coordinates -------------------------------------------------------------------------------------------
    // The stage point of a pointer event mapped into its target's space, computed the first time a local property is
    // read or written. Without a display object target the local values are 0.

    // @0x14246a1a0
    // MS2-FUNCTIONAL: block layout of the matrix path differs from the exe (3 bytes longer)
    void GestureEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            Render::Matrix2F m;
            static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetWorldMatrix(&m);
            Render::PointF p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
            LocalX = p.x;
            LocalY = p.y;
        }
        else
        {
            LocalX = 0;
            LocalY = 0;
        }
        LocalInitialized = true;
    }

    // @0x14246a2f0
    // MS2-FUNCTIONAL: block layout of the matrix path differs from the exe
    void MouseEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            Render::Matrix2F m;
            static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetWorldMatrix(&m);
            Render::PointF p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
            LocalX = p.x;
            LocalY = p.y;
        }
        else
        {
            LocalX = 0;
            LocalY = 0;
        }
        LocalInitialized = true;
    }

    // @0x14246a450
    // MS2-FUNCTIONAL: block layout of the matrix path differs from the exe
    void PressAndTapGestureEvent::InitTapLocalCoords()
    {
        if (TapLocalInitialized)
            return;
        if (Unk_a9 && Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            Render::Matrix2F m;
            static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetWorldMatrix(&m);
            Render::PointF p = m.TransformByInverse(Render::PointF(float(TapStageX), float(TapStageY)));
            TapLocalX = p.x;
            TapLocalY = p.y;
        }
        else
        {
            TapLocalX = 0;
            TapLocalY = 0;
        }
        TapLocalInitialized = true;
    }

    // @0x14246a5c0
    // MS2-FUNCTIONAL: block layout of the matrix path differs from the exe
    void TouchEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            Render::Matrix2F m;
            static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetWorldMatrix(&m);
            Render::PointF p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
            LocalX = p.x;
            LocalY = p.y;
            Render::PointF s = m.TransformByInverse(Render::PointF(float(SizeX), float(SizeY)));
            SizeX = s.x;
            SizeY = s.y;
        }
        else
        {
            LocalX = 0;
            LocalY = 0;
            SizeX = 0;
            SizeY = 0;
        }
        LocalInitialized = true;
    }

    // @0x14246a780
    // MS2-FUNCTIONAL: block layout of the parent-matrix path differs from the exe
    void TransformGestureEvent::InitLocalOffset()
    {
        if (LocalOffsetInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            // the offset is relative to the target's parent
            Render::Matrix2F m;
            GFx::InteractiveObject* parent =
                static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetParent();
            if (parent)
            {
                Render::Matrix2F pm;
                parent->GetWorldMatrix(&pm);
                m = pm;
            }
            Value::Number x = StageX, y = StageY;
            Render::PointF p0 = m.TransformByInverse(Render::PointF(float(x), float(y)));
            Render::PointF p1 = m.TransformByInverse(Render::PointF(float(x + OffsetX), float(y + OffsetY)));
            LocalOffsetX = p1.x - p0.x;
            LocalOffsetY = p1.y - p0.y;
        }
        else
        {
            LocalOffsetX = 0;
            LocalOffsetY = 0;
        }
        LocalOffsetInitialized = true;
    }

    // ---- pixel properties --------------------------------------------------------------------------------------------
    // Stored in twips.

    // @0x14246ea30
    void GestureEvent::localXGet(Value::Number& result)     { InitLocalCoords(); result = Render::TwipsToPixels(LocalX); }
    // @0x14246eaf0
    void GestureEvent::localXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalX = Render::PixelsToTwips(v); }
    // @0x14246eb80
    void GestureEvent::localYGet(Value::Number& result)     { InitLocalCoords(); result = Render::TwipsToPixels(LocalY); }
    // @0x14246ec40
    void GestureEvent::localYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalY = Render::PixelsToTwips(v); }

    // @0x14246ea70
    void MouseEvent::localXGet(Value::Number& result)       { InitLocalCoords(); result = Render::TwipsToPixels(LocalX); }
    // @0x14246eb20
    void MouseEvent::localXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalX = Render::PixelsToTwips(v); }
    // @0x14246ebc0
    void MouseEvent::localYGet(Value::Number& result)       { InitLocalCoords(); result = Render::TwipsToPixels(LocalY); }
    // @0x14246ec70
    void MouseEvent::localYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalY = Render::PixelsToTwips(v); }

    // @0x14246eab0
    void TouchEvent::localXGet(Value::Number& result)       { InitLocalCoords(); result = Render::TwipsToPixels(LocalX); }
    // @0x14246eb50
    void TouchEvent::localXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalX = Render::PixelsToTwips(v); }
    // @0x14246ec00
    void TouchEvent::localYGet(Value::Number& result)       { InitLocalCoords(); result = Render::TwipsToPixels(LocalY); }
    // @0x14246eca0
    void TouchEvent::localYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); LocalY = Render::PixelsToTwips(v); }
    // @0x14246f550
    void TouchEvent::sizeXGet(Value::Number& result)        { InitLocalCoords(); result = Render::TwipsToPixels(SizeX); }
    // @0x14246f590
    void TouchEvent::sizeXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); SizeX = Render::PixelsToTwips(v); }
    // @0x14246f5c0
    void TouchEvent::sizeYGet(Value::Number& result)        { InitLocalCoords(); result = Render::TwipsToPixels(SizeY); }
    // @0x14246f600
    void TouchEvent::sizeYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalCoords(); SizeY = Render::PixelsToTwips(v); }

    // @0x14246ecd0
    void TransformGestureEvent::offsetXGet(Value::Number& result) { InitLocalOffset(); result = Render::TwipsToPixels(LocalOffsetX); }
    // @0x14246ed10
    void TransformGestureEvent::offsetXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalOffset(); LocalOffsetX = Render::PixelsToTwips(v); }
    // @0x14246ed50
    void TransformGestureEvent::offsetYGet(Value::Number& result) { InitLocalOffset(); result = Render::TwipsToPixels(LocalOffsetY); }
    // @0x14246ed90
    void TransformGestureEvent::offsetYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitLocalOffset(); LocalOffsetY = Render::PixelsToTwips(v); }

    // @0x14246f740
    void PressAndTapGestureEvent::tapLocalXGet(Value::Number& result) { InitTapLocalCoords(); result = Render::TwipsToPixels(TapLocalX); }
    // @0x14246f780
    void PressAndTapGestureEvent::tapLocalXSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitTapLocalCoords(); TapLocalX = Render::PixelsToTwips(v); }
    // @0x14246f7c0
    void PressAndTapGestureEvent::tapLocalYGet(Value::Number& result) { InitTapLocalCoords(); result = Render::TwipsToPixels(TapLocalY); }
    // @0x14246f800
    void PressAndTapGestureEvent::tapLocalYSet(const Value& result, Value::Number v) { SF_UNUSED(result); InitTapLocalCoords(); TapLocalY = Render::PixelsToTwips(v); }

    // ---- related objects ---------------------------------------------------------------------------------------------

    // @0x14246f070
    void FocusEvent::relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject* value) { SF_UNUSED(result); RelatedObj = value; }
    // @0x14246f0e0
    void MouseEvent::relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject* value) { SF_UNUSED(result); RelatedObj = value; }
    // @0x14246f150
    void TouchEvent::relatedObjectSet(const Value& result, Instances::fl_display::InteractiveObject* value) { SF_UNUSED(result); RelatedObj = value; }
    // @0x14246efe0
    void FocusEvent::relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result) { result = RelatedObj; }
    // @0x14246efb0
    SPtr<Instances::fl_display::InteractiveObject> FocusEvent::relatedObjectGet()
    {
        SPtr<Instances::fl_display::InteractiveObject> result;
        relatedObjectGet(result);
        return result;
    }
    // @0x14246f020
    void MouseEvent::relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result) { result = RelatedObj; }
    // @0x14246eff0
    SPtr<Instances::fl_display::InteractiveObject> MouseEvent::relatedObjectGet()
    {
        SPtr<Instances::fl_display::InteractiveObject> result;
        relatedObjectGet(result);
        return result;
    }
    // @0x14246f060
    void TouchEvent::relatedObjectGet(SPtr<Instances::fl_display::InteractiveObject>& result) { result = RelatedObj; }
    // @0x14246f030
    SPtr<Instances::fl_display::InteractiveObject> TouchEvent::relatedObjectGet()
    {
        SPtr<Instances::fl_display::InteractiveObject> result;
        relatedObjectGet(result);
        return result;
    }

    // ---- orientation -------------------------------------------------------------------------------------------------

    // @0x14246cf90
    // MS2-FUNCTIONAL: the exe loads the node before the null test and shares one ReleaseNode epilogue
    void StageOrientationEvent::afterOrientationGet(ASString& result)
    {
        ASStringNode* node = AfterOrientation.AsStringNode();
        if (AfterOrientation.IsNull())
            node = result.GetManager()->GetNullStringNode();
        result.AssignNode(node);
    }

    // @0x14246d080
    // MS2-FUNCTIONAL: the exe loads the node before the null test and shares one ReleaseNode epilogue
    void StageOrientationEvent::beforeOrientationGet(ASString& result)
    {
        ASStringNode* node = BeforeOrientation.AsStringNode();
        if (BeforeOrientation.IsNull())
            node = result.GetManager()->GetNullStringNode();
        result.AssignNode(node);
    }

    // ---- clone -------------------------------------------------------------------------------------------------------
    // The natives hand back a Clone() of the event; the result-returning forms are the call-style wrappers.

    // @0x14246d330
    // MS2-FUNCTIONAL: the exe re-reads the temporary through its stack slot and adds the reference in two memory steps
    __declspec(noinline) void Event::clone(SPtr<Instances::fl_events::Event>& result) { result = Clone(); }
    // @0x14246d240
    __declspec(noinline) void AppLifecycleEvent::clone(SPtr<Instances::fl_events::Event>& result)        { result = Clone().GetPtr(); }
    // @0x14246d310
    void ErrorEvent::clone(SPtr<Instances::fl_events::Event>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method ErrorEvent::clone() is not implemented\n");
    }
    // @0x14246d3f0
    __declspec(noinline) void FocusEvent::clone(SPtr<Instances::fl_events::Event>& result)               { result = Clone().GetPtr(); }
    // @0x14246d4a0
    __declspec(noinline) void GestureEvent::clone(SPtr<Instances::fl_events::Event>& result)             { result = Clone().GetPtr(); }
    // @0x14246d540
    __declspec(noinline) void IMEEvent::clone(SPtr<Instances::fl_events::Event>& result)                 { SF_UNUSED(result); }
    // @0x14246d570
    __declspec(noinline) void IOErrorEvent::clone(SPtr<Instances::fl_events::Event>& result)             { result = Clone().GetPtr(); }
    // @0x14246d620
    __declspec(noinline) void KeyboardEvent::clone(SPtr<Instances::fl_events::Event>& result)            { result = Clone().GetPtr(); }
    // @0x14246d6d0
    __declspec(noinline) void MouseEvent::clone(SPtr<Instances::fl_events::Event>& result)               { result = Clone().GetPtr(); }
    // @0x14246d780
    __declspec(noinline) void NetStatusEvent::clone(SPtr<Instances::fl_events::Event>& result)           { result = Clone().GetPtr(); }
    // @0x14246d830
    __declspec(noinline) void PressAndTapGestureEvent::clone(SPtr<Instances::fl_events::Event>& result)  { result = Clone().GetPtr(); }
    // @0x14246d8e0
    __declspec(noinline) void ProgressEvent::clone(SPtr<Instances::fl_events::Event>& result)            { result = Clone().GetPtr(); }
    // @0x14246d990
    __declspec(noinline) void StageOrientationEvent::clone(SPtr<Instances::fl_events::Event>& result)    { result = Clone().GetPtr(); }
    // @0x14246da40
    __declspec(noinline) void TextEvent::clone(SPtr<Instances::fl_events::Event>& result)                { result = Clone().GetPtr(); }
    // @0x14246daf0
    void TimerEvent::clone(SPtr<Instances::fl_events::Event>& result)               { Event::clone(result); }
    // @0x14246db20
    __declspec(noinline) void TouchEvent::clone(SPtr<Instances::fl_events::Event>& result)               { result = Clone().GetPtr(); }
    // @0x14246dbd0
    __declspec(noinline) void TransformGestureEvent::clone(SPtr<Instances::fl_events::Event>& result)    { result = Clone().GetPtr(); }

    // @0x14246d220
    SPtr<Instances::fl_events::Event> AppLifecycleEvent::clone()        { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d2d0
    SPtr<Instances::fl_events::Event> ErrorEvent::clone()               { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d3d0
    SPtr<Instances::fl_events::Event> FocusEvent::clone()               { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d480
    SPtr<Instances::fl_events::Event> GestureEvent::clone()             { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d550
    SPtr<Instances::fl_events::Event> IOErrorEvent::clone()             { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d600
    SPtr<Instances::fl_events::Event> KeyboardEvent::clone()            { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d6b0
    SPtr<Instances::fl_events::Event> MouseEvent::clone()               { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d760
    SPtr<Instances::fl_events::Event> NetStatusEvent::clone()           { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d810
    SPtr<Instances::fl_events::Event> PressAndTapGestureEvent::clone()  { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d8c0
    SPtr<Instances::fl_events::Event> ProgressEvent::clone()            { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246d970
    SPtr<Instances::fl_events::Event> StageOrientationEvent::clone()    { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246da20
    SPtr<Instances::fl_events::Event> TextEvent::clone()                { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246dad0
    SPtr<Instances::fl_events::Event> TimerEvent::clone()               { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246db00
    SPtr<Instances::fl_events::Event> TouchEvent::clone()               { SPtr<Instances::fl_events::Event> result; clone(result); return result; }
    // @0x14246dbb0
    SPtr<Instances::fl_events::Event> TransformGestureEvent::clone()    { SPtr<Instances::fl_events::Event> result; clone(result); return result; }

    // ---- targets -----------------------------------------------------------------------------------------------------

    // @0x14246de10
    void Event::currentTargetGet(SPtr<Instances::fl::Object>& result)  { result = CurrentTarget.GetPtr(); }

}} // namespace Instances::fl_events

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142472fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473020
// MS2-PIN: ?Func@?$ThunkFunc1@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473080
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424730e0
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$03$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473150
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$04VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473330
