// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_09
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424653f0-0x142473710 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/kernel/sf_std.h"

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
// Object::FindProperty: the slot or dynamic value of this object named mn (0x142502360).
void FUN_142502360(Scaleform::GFx::AS3::Object* obj, Scaleform::GFx::AS3::PropRef& result,
                   const Scaleform::GFx::AS3::Multiname& mn, int attr);
// The gesture phase names, by GestureEvent::Phase (0: none).
extern const char* const DAT_143a2d158[];
// SPtr<Instances::fl::Object>::operator=, out of line (0x14243d870).
void* FUN_14243d870(void* self, void* p);
// VM::MakeObject: a new plain Object (0x142516600).
void FUN_142516600(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>& result);
// VM::GetValueTraits: the traits of a value (0x14250ffc0).
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);

namespace Scaleform { namespace GFx {

// The script error channel of a log state, only with verbose action errors.
// @0x14246a960
template<>
void LogBase<LogState>::LogScriptError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    LogState* p = (LogState*)this;
    if (p->P_IsVerboseActionErrors())
    {
        Log* plog = p->GetLog();
        if (p->IsLogNotNull() || plog)
            plog->LogMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    }
    va_end(argList);
}

}} // namespace Scaleform::GFx

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
            AS3::Object* pobj = argv[3].GetObject();
            if (pobj && FUN_1425145d0(GetVM(), argv[3], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(pobj);
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
    void GestureEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        Event::AS3Constructor(argc, argv);
        if (argc >= 4)
        {
            Value r;
            phaseSet(r, argv[3].AsString());
        }
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
            AS3::Object* pobj = argv[5].GetObject();
            if (pobj && FUN_1425145d0(GetVM(), argv[5], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(pobj);
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
        {
            SInt32 v;
            argv[10].Convert2Int32(v);
            Delta = v;
        }
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
        {
            Value r;
            phaseSet(r, argv[3].AsString());
        }
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
            argv[9].Convert2Number(Pressure);
        if (argc >= 11)
        {
            RelatedObj = NULL;
            // The exe takes the object from argv[5] and type-tests argv[10].
            AS3::Object* pobj = argv[5].GetObject();
            if (pobj && FUN_1425145d0(GetVM(), argv[10], "flash.display.InteractiveObject"))
                RelatedObj = static_cast<Instances::fl_display::InteractiveObject*>(pobj);
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
    void TransformGestureEvent::AS3Constructor(unsigned argc, const Value* argv)
    {
        GestureEvent::AS3Constructor(argc, argv);
        if (argc >= 4)
        {
            Value r;
            phaseSet(r, argv[3].AsString());
        }
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
        {
            Value::Number v;
            argv[6].Convert2Number(v);
            ScaleX = v;
        }
        if (argc >= 8)
        {
            Value::Number v;
            argv[7].Convert2Number(v);
            ScaleY = v;
        }
        if (argc >= 9)
        {
            Value::Number v;
            argv[8].Convert2Number(v);
            Rotation = v;
        }
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
    // MS2-FUNCTIONAL: the exe keeps this in rbp (rsi here); same blocks and dispatch order
    void EventDispatcher::Dispatch(Instances::fl_events::Event* evt, GFx::DisplayObject* dobj)
    {
        if (dobj)
        {
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
        else
            DispatchSingleEvent(evt, false);
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

    // @0x142469fa0
    AS3::Object* AppLifecycleEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).AppLifecycleEventClass; }
    // @0x142469fb0
    AS3::Object* Event::GetEventClass() const { return static_cast<ASVM&>(GetVM()).EventClass; }
    // @0x142469fc0
    AS3::Object* FocusEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).FocusEventClass; }
    // @0x142469fd0
    AS3::Object* GestureEvent::GetEventClass() const { return NULL; }
    // @0x14246a010
    AS3::Object* KeyboardEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).KeyboardEventClass; }
    // @0x14246a020
    AS3::Object* MouseEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).MouseEventClass; }
    // @0x14246a060
    AS3::Object* PressAndTapGestureEvent::GetEventClass() const { return NULL; }
    // @0x14246a070
    AS3::Object* ProgressEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).ProgressEventClass; }
    // @0x14246a080
    AS3::Object* StageOrientationEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).StageOrientationEventClass; }
    // @0x14246a090
    AS3::Object* TextEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).TextEventClass; }
    // @0x14246a0a0
    AS3::Object* TimerEvent::GetEventClass() const { return static_cast<ASVM&>(GetVM()).TimerEventClass; }
    // @0x14246a0b0
    AS3::Object* TouchEvent::GetEventClass() const { return NULL; }
    // @0x14246a0c0
    AS3::Object* TransformGestureEvent::GetEventClass() const { return NULL; }
    // @0x14246a0d0
    const char* Event::GetEventName() const { return "Event"; }
    // @0x14246a0e0
    const char* NetStatusEvent::GetEventName() const { return "NetStatusEvent"; }
    // @0x14246a0f0
    const char* TimerEvent::GetEventName() const { return "TimerEvent"; }

    // ---- EventDispatcher listener queries ----------------------------------------------------------------------------

    // @0x14246c230
    bool EventDispatcher::MayHaveActivateHandler() const
    {
        return pImpl ? pImpl->HasActivate : false;
    }
    // @0x14246c250
    bool EventDispatcher::MayHaveDeactivateHandler() const
    {
        return pImpl ? pImpl->HasDeactivate : false;
    }
    // @0x14246c270
    bool EventDispatcher::MayHaveEnterFrameHandler() const
    {
        return pImpl ? pImpl->HasEnterFrame : false;
    }
    // @0x14246c290
    bool EventDispatcher::MayHaveExitFrameHandler() const
    {
        return pImpl ? pImpl->HasExitFrame : false;
    }
    // @0x14246c2b0
    bool EventDispatcher::MayHaveFrameConstructedHandler() const
    {
        return pImpl ? pImpl->HasFrameConstructed : false;
    }
    // @0x14246c2d0
    bool EventDispatcher::MayHaveRenderHandler() const
    {
        return pImpl ? pImpl->HasRender : false;
    }

    // @0x14246a140
    bool EventDispatcher::HasButtonHandlers() const
    {
        return pImpl && (pImpl->CaptureButtonHandlersCnt > 0 || pImpl->ButtonHandlersCnt > 0);
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
        return (unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <=
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
        // Runs inside a collection, where the collector has set the mark bit of pTraits.
        const Traits* ptraits = reinterpret_cast<const Traits*>(reinterpret_cast<UPInt>(&d->GetTraits()) & ~UPInt(1));
        ASVM& vm = static_cast<ASVM&>(ptraits->GetVM());
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
    // the display object is fetched before the matrix; the point is assigned (Point's operator= reads the result)
    void GestureEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            GFx::DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj;
            Render::Matrix2F m;
            pdisp->GetWorldMatrix(&m);
            Render::PointF p;
            p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
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
    // the display object is fetched before the matrix; the point is assigned (Point's operator= reads the result)
    void MouseEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            GFx::DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj;
            Render::Matrix2F m;
            pdisp->GetWorldMatrix(&m);
            Render::PointF p;
            p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
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
    // the display object is fetched before the matrix; the point is assigned (Point's operator= reads the result)
    void PressAndTapGestureEvent::InitTapLocalCoords()
    {
        if (TapLocalInitialized)
            return;
        if (Unk_a9 && Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            GFx::DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj;
            Render::Matrix2F m;
            pdisp->GetWorldMatrix(&m);
            Render::PointF p;
            p = m.TransformByInverse(Render::PointF(float(TapStageX), float(TapStageY)));
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
    // the display object is fetched before the matrix; the point is assigned (Point's operator= reads the result)
    void TouchEvent::InitLocalCoords()
    {
        if (LocalInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            GFx::DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj;
            Render::Matrix2F m;
            pdisp->GetWorldMatrix(&m);
            Render::PointF p;
            p = m.TransformByInverse(Render::PointF(float(StageX), float(StageY)));
            LocalX = p.x;
            LocalY = p.y;
            Render::PointF s;
            s = m.TransformByInverse(Render::PointF(float(SizeX), float(SizeY)));
            SizeX = s.x;
            SizeY = s.y;
        }
        else
        {
            LocalY = 0;
            LocalX = 0;
            SizeX = 0;
            SizeY = 0;
        }
        LocalInitialized = true;
    }

    // @0x14246a780
    // the parent is fetched before the matrix; the points are assigned (Point's operator= reads the result)
    void TransformGestureEvent::InitLocalOffset()
    {
        if (LocalOffsetInitialized)
            return;
        if (Target && FUN_1425145d0(GetVM(), Value(Target), "flash.display.DisplayObject"))
        {
            // the offset is relative to the target's parent
            GFx::InteractiveObject* parent =
                static_cast<Instances::fl_display::DisplayObject*>(Target.GetPtr())->pDispObj->GetParent();
            Render::Matrix2F m;
            if (parent)
            {
                Render::Matrix2F pm;
                parent->GetWorldMatrix(&pm);
                m = pm;
            }
            Value::Number x = StageX, y = StageY;
            Render::PointF p0;
            p0 = m.TransformByInverse(Render::PointF(float(x), float(y)));
            Render::PointF p1;
            p1 = m.TransformByInverse(Render::PointF(float(x + OffsetX), float(y + OffsetY)));
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

    // ---- property accessors and stubs -------------------------------------------------------------------------------

    // @0x14246d0d0
    void Event::bubblesGet(bool& result) { result = Bubbles; }
    // @0x14246d1d0
    void Event::cancelableGet(bool& result) { result = Cancelable; }
    // @0x14246dfb0
    void Event::eventPhaseGet(UInt32& result) { result = Phase; }
    // @0x14246e960
    void Event::isDefaultPrevented(bool& result) { result = DefaultPrevented; }
    // @0x14246efa0
    void Event::preventDefault(const Value& result) { SF_UNUSED(result); if (Cancelable) DefaultPrevented = true; }
    // @0x14246f720
    void Event::stopImmediatePropagation(const Value& result) { SF_UNUSED(result); ImmPropagationStopped = true; }
    // @0x14246f730
    void Event::stopPropagation(const Value& result) { SF_UNUSED(result); PropagationStopped = true; }

    // The AppLifecycleEvent status: the status object, if one was set.
    // @0x14246f700
    void AppLifecycleEvent::statusGet(SPtr<Instances::fl::Object>& result)
    {
        if (Status.IsObject())
            FUN_14243d870(&result, Status.GetObject());
    }

    // @0x14246d200
    void MouseEvent::clickCountGet(SInt32& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method MouseEvent::clickCountGet() is not implemented\n");
    }
    // @0x14246de90
    void FocusEvent::directionGet(ASString& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method FocusEvent::directionGet() is not implemented\n");
    }
    // @0x14246deb0
    void FocusEvent::directionSet(const Value& result, const ASString& v)
    {
        SF_UNUSED2(result, v);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method FocusEvent::directionSet() is not implemented\n");
    }
    // @0x14246df90
    void ErrorEvent::errorIDGet(SInt32& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method ErrorEvent::errorIDGet() is not implemented\n");
    }
    // @0x14246fc30
    void ErrorEvent::toString(ASString& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method ErrorEvent::toString() is not implemented\n");
    }
    // @0x142472d60
    void GestureEvent::updateAfterEvent(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::GestureEvent::updateAfterEvent() is not implemented\n");
    }
    // @0x142472d80
    void KeyboardEvent::updateAfterEvent(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method KeyboardEvent::updateAfterEvent() is not implemented\n");
    }
    // @0x142472da0
    void MouseEvent::updateAfterEvent(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method MouseEvent::updateAfterEvent() is not implemented\n");
    }
    // @0x142472dc0
    void TimerEvent::updateAfterEvent(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method TimerEvent::updateAfterEvent() is not implemented\n");
    }
    // @0x142472de0
    void TouchEvent::updateAfterEvent(const Value& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::TouchEvent::updateAfterEvent() is not implemented\n");
    }
    // @0x142470690
    void IMEEvent::toString(ASString& result) { SF_UNUSED(result); }
    // @0x142472090
    void TimerEvent::toString(ASString& result) { Event::toString(result); }

    // Gesture/Touch modifier keys by offset: +0x58 alt, +0x59 ctrl, +0x5a shift, +0x5b command, +0x5c control (the
    // header names +0x59..+0x5c CommandKey/ControlKey/CtrlKey/ShiftKey; the constructors store by the same offsets).
    // @0x14246cff0
    void GestureEvent::altKeyGet(bool& result) { result = AltKey; }
    // @0x14246d030
    void GestureEvent::altKeySet(const Value& result, bool v) { SF_UNUSED(result); AltKey = v; }
    // @0x14246dd80
    void GestureEvent::ctrlKeyGet(bool& result) { result = CommandKey; }
    // @0x14246ddc0
    void GestureEvent::ctrlKeySet(const Value& result, bool v) { SF_UNUSED(result); CommandKey = v; }
    // @0x14246f4b0
    void GestureEvent::shiftKeyGet(bool& result) { result = ControlKey; }
    // @0x14246f500
    void GestureEvent::shiftKeySet(const Value& result, bool v) { SF_UNUSED(result); ControlKey = v; }
    // @0x14246dc60
    void GestureEvent::commandKeyGet(bool& result) { result = CtrlKey; }
    // @0x14246dca0
    void GestureEvent::commandKeySet(const Value& result, bool v) { SF_UNUSED(result); CtrlKey = v; }
    // @0x14246dcf0
    void GestureEvent::controlKeyGet(bool& result) { result = ShiftKey; }
    // @0x14246dd30
    void GestureEvent::controlKeySet(const Value& result, bool v) { SF_UNUSED(result); ShiftKey = v; }
    // @0x14246d020
    void TouchEvent::altKeyGet(bool& result) { result = AltKey; }
    // @0x14246d070
    void TouchEvent::altKeySet(const Value& result, bool v) { SF_UNUSED(result); AltKey = v; }
    // @0x14246ddb0
    void TouchEvent::ctrlKeyGet(bool& result) { result = CommandKey; }
    // @0x14246de00
    void TouchEvent::ctrlKeySet(const Value& result, bool v) { SF_UNUSED(result); CommandKey = v; }
    // @0x14246f4e0
    void TouchEvent::shiftKeyGet(bool& result) { result = ControlKey; }
    // @0x14246f540
    void TouchEvent::shiftKeySet(const Value& result, bool v) { SF_UNUSED(result); ControlKey = v; }
    // @0x14246dc90
    void TouchEvent::commandKeyGet(bool& result) { result = CtrlKey; }
    // @0x14246dce0
    void TouchEvent::commandKeySet(const Value& result, bool v) { SF_UNUSED(result); CtrlKey = v; }
    // @0x14246dd20
    void TouchEvent::controlKeyGet(bool& result) { result = ShiftKey; }
    // @0x14246dd70
    void TouchEvent::controlKeySet(const Value& result, bool v) { SF_UNUSED(result); ShiftKey = v; }

    // MouseEvent keeps one ctrl flag for ctrlKey, commandKey and controlKey.
    // @0x14246d010
    void MouseEvent::altKeyGet(bool& result) { result = AltKey; }
    // @0x14246d060
    void MouseEvent::altKeySet(const Value& result, bool v) { SF_UNUSED(result); AltKey = v; }
    // @0x14246dda0
    void MouseEvent::ctrlKeyGet(bool& result) { result = CtrlKey; }
    // @0x14246ddf0
    void MouseEvent::ctrlKeySet(const Value& result, bool v) { SF_UNUSED(result); CtrlKey = v; }
    // @0x14246dc80
    void MouseEvent::commandKeyGet(bool& result) { result = CtrlKey; }
    // @0x14246dcd0
    void MouseEvent::commandKeySet(const Value& result, bool v) { SF_UNUSED(result); CtrlKey = v; }
    // @0x14246dd10
    void MouseEvent::controlKeyGet(bool& result) { result = CtrlKey; }
    // @0x14246dd60
    void MouseEvent::controlKeySet(const Value& result, bool v) { SF_UNUSED(result); CtrlKey = v; }
    // @0x14246f4d0
    void MouseEvent::shiftKeyGet(bool& result) { result = ShiftKey; }
    // @0x14246f530
    void MouseEvent::shiftKeySet(const Value& result, bool v) { SF_UNUSED(result); ShiftKey = v; }
    // @0x14246d0e0
    void MouseEvent::buttonDownGet(bool& result) { result = (ButtonsMask & 1) != 0; }
    // @0x14246d0f0
    void MouseEvent::buttonDownSet(const Value& result, bool v) { SF_UNUSED(result); if (v) ButtonsMask |= 1; else ButtonsMask &= ~1u; }
    // @0x14246de70
    void MouseEvent::deltaGet(SInt32& result) { result = Delta; }
    // @0x14246de80
    void MouseEvent::deltaSet(const Value& result, SInt32 v) { SF_UNUSED(result); Delta = v; }

    // KeyboardEvent modifiers are the event id's KeyModifiers bits; ctrlKey, commandKey and controlKey share the ctrl bit.
    // @0x14246d000
    void KeyboardEvent::altKeyGet(bool& result) { result = (EvtId.KeysState & KeyModifiers::Key_AltPressed) != 0; }
    // @0x14246d040
    void KeyboardEvent::altKeySet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        if (v) EvtId.KeysState |= KeyModifiers::Key_AltPressed;
        else   EvtId.KeysState &= ~KeyModifiers::Key_AltPressed;
    }
    // @0x14246dd90
    void KeyboardEvent::ctrlKeyGet(bool& result) { result = (EvtId.KeysState & KeyModifiers::Key_CtrlPressed) != 0; }
    // @0x14246ddd0
    void KeyboardEvent::ctrlKeySet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        if (v) EvtId.KeysState |= KeyModifiers::Key_CtrlPressed;
        else   EvtId.KeysState &= ~KeyModifiers::Key_CtrlPressed;
    }
    // @0x14246dc70
    void KeyboardEvent::commandKeyGet(bool& result) { result = (EvtId.KeysState & KeyModifiers::Key_CtrlPressed) != 0; }
    // @0x14246dcb0
    void KeyboardEvent::commandKeySet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        if (v) EvtId.KeysState |= KeyModifiers::Key_CtrlPressed;
        else   EvtId.KeysState &= ~KeyModifiers::Key_CtrlPressed;
    }
    // @0x14246dd00
    void KeyboardEvent::controlKeyGet(bool& result) { result = (EvtId.KeysState & KeyModifiers::Key_CtrlPressed) != 0; }
    // @0x14246dd40
    void KeyboardEvent::controlKeySet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        if (v) EvtId.KeysState |= KeyModifiers::Key_CtrlPressed;
        else   EvtId.KeysState &= ~KeyModifiers::Key_CtrlPressed;
    }
    // @0x14246f4c0
    void KeyboardEvent::shiftKeyGet(bool& result) { result = (EvtId.KeysState & KeyModifiers::Key_ShiftPressed) != 0; }
    // @0x14246f510
    void KeyboardEvent::shiftKeySet(const Value& result, bool v)
    {
        SF_UNUSED(result);
        if (v) EvtId.KeysState |= KeyModifiers::Key_ShiftPressed;
        else   EvtId.KeysState &= ~KeyModifiers::Key_ShiftPressed;
    }
    // @0x14246d1e0
    void KeyboardEvent::charCodeGet(UInt32& result) { result = EvtId.AsciiCode; }
    // @0x14246d1f0
    void KeyboardEvent::charCodeSet(const Value& result, UInt32 v) { SF_UNUSED(result); EvtId.AsciiCode = (UByte)v; }
    // @0x14246e9c0
    void KeyboardEvent::keyCodeGet(UInt32& result) { result = EvtId.KeyCode; }
    // @0x14246e9e0
    void KeyboardEvent::keyCodeSet(const Value& result, UInt32 v) { SF_UNUSED(result); EvtId.KeyCode = v; }
    // The key location, worked out on first use: a modifier key is left (1) or, extended, right (2); others standard (0).
    // @0x14246e9f0
    void KeyboardEvent::keyLocationGet(UInt32& result)
    {
        if (KeyLocation < 0)
        {
            if (EvtId.KeysState & (KeyModifiers::Key_ShiftPressed | KeyModifiers::Key_CtrlPressed | KeyModifiers::Key_AltPressed))
                KeyLocation = (EvtId.KeysState & KeyModifiers::Key_ExtendedKey) ? 2 : 1;
            else
                KeyLocation = 0;
        }
        result = KeyLocation;
    }
    // @0x14246ea20
    void KeyboardEvent::keyLocationSet(const Value& result, UInt32 v) { SF_UNUSED(result); KeyLocation = v; }

    // @0x14246f4a0
    void FocusEvent::shiftKeyGet(bool& result) { result = ShiftKey; }
    // @0x14246f4f0
    void FocusEvent::shiftKeySet(const Value& result, bool v) { SF_UNUSED(result); ShiftKey = v; }
    // @0x14246e9b0
    void FocusEvent::keyCodeGet(UInt32& result) { result = KeyCode; }
    // @0x14246e9d0
    void FocusEvent::keyCodeSet(const Value& result, UInt32 v) { SF_UNUSED(result); KeyCode = v; }

    // @0x14246d110
    void ProgressEvent::bytesLoadedGet(Value::Number& result) { result = (Value::Number)BytesLoaded; }
    // @0x14246d130
    void ProgressEvent::bytesLoadedSet(const Value& result, Value::Number v) { SF_UNUSED(result); BytesLoaded = (UInt64)v; }
    // @0x14246d170
    void ProgressEvent::bytesTotalGet(Value::Number& result) { result = (Value::Number)BytesTotal; }
    // @0x14246d190
    void ProgressEvent::bytesTotalSet(const Value& result, Value::Number v) { SF_UNUSED(result); BytesTotal = (UInt64)v; }

    // @0x14246f640
    void GestureEvent::stageXGet(Value::Number& result) { result = Render::TwipsToPixels(StageX); }
    // @0x14246f6a0
    void GestureEvent::stageYGet(Value::Number& result) { result = Render::TwipsToPixels(StageY); }
    // @0x14246f660
    void MouseEvent::stageXGet(Value::Number& result) { result = Render::TwipsToPixels(StageX); }
    // @0x14246f6c0
    void MouseEvent::stageYGet(Value::Number& result) { result = Render::TwipsToPixels(StageY); }
    // @0x14246f680
    void TouchEvent::stageXGet(Value::Number& result) { result = Render::TwipsToPixels(StageX); }
    // @0x14246f6e0
    void TouchEvent::stageYGet(Value::Number& result) { result = Render::TwipsToPixels(StageY); }
    // @0x14246f840
    void PressAndTapGestureEvent::tapStageXGet(Value::Number& result) { result = Render::TwipsToPixels(TapStageX); }
    // @0x14246f860
    void PressAndTapGestureEvent::tapStageYGet(Value::Number& result) { result = Render::TwipsToPixels(TapStageY); }

    // @0x14246e970
    void TouchEvent::isPrimaryTouchPointGet(bool& result) { result = IsPrimaryTouchPoint; }
    // @0x14246e980
    void TouchEvent::isPrimaryTouchPointSet(const Value& result, bool v) { SF_UNUSED(result); IsPrimaryTouchPoint = v; }
    // @0x14246e990
    void TouchEvent::isRelatedObjectInaccessibleGet(bool& result) { result = false; }
    // @0x14246e9a0
    void TouchEvent::isRelatedObjectInaccessibleSet(const Value& result, bool v) { SF_UNUSED2(result, v); }
    // @0x14246ef80
    void TouchEvent::pressureGet(Value::Number& result) { result = Pressure; }
    // @0x14246ef90
    void TouchEvent::pressureSet(const Value& result, Value::Number v) { SF_UNUSED(result); Pressure = v; }
    // @0x142472d00
    void TouchEvent::touchPointIDGet(SInt32& result) { result = TouchPointID; }
    // @0x142472d10
    void TouchEvent::touchPointIDSet(const Value& result, SInt32 v) { SF_UNUSED(result); TouchPointID = v; }

    // @0x14246f2b0
    void TransformGestureEvent::rotationGet(Value::Number& result) { result = Rotation; }
    // @0x14246f2c0
    void TransformGestureEvent::rotationSet(const Value& result, Value::Number v) { SF_UNUSED(result); Rotation = v; }
    // @0x14246f2d0
    void TransformGestureEvent::scaleXGet(Value::Number& result) { result = ScaleX; }
    // @0x14246f2e0
    void TransformGestureEvent::scaleXSet(const Value& result, Value::Number v) { SF_UNUSED(result); ScaleX = v; }
    // @0x14246f2f0
    void TransformGestureEvent::scaleYGet(Value::Number& result) { result = ScaleY; }
    // @0x14246f300
    void TransformGestureEvent::scaleYSet(const Value& result, Value::Number v) { SF_UNUSED(result); ScaleY = v; }

}} // namespace Instances::fl_events


// ---- instance makers: a new instance of the traits' class ----------------------------------------------------------
// Inline copies of the instance ctors (their out-of-line copies are in sfr_as3_08). The exe builds the event
// classes in one TU, so the MakeObject/MakeInstance functions below inline them.
namespace Instances { namespace fl_events {
    inline Event::Event(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Type(GetVM().GetStringManager().CreateEmptyString())
        , CurrentTarget(NULL)
        , Target(NULL)
        , Phase(2)
    {
        Bubbles = false;
        Cancelable = false;
        DefaultPrevented = false;
        PropagationStopped = false;
        ImmPropagationStopped = false;
    }

    inline EventDispatcher::EventDispatcher(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pVM(&t.GetVM())
        , pImpl()
    {
    }

    inline ErrorEvent::ErrorEvent(InstanceTraits::Traits& t)
        : TextEvent(t)
    {
    }

    inline IMEEvent::IMEEvent(InstanceTraits::Traits& t)
        : TextEvent(t)
    {
    }

    inline AsyncErrorEvent::AsyncErrorEvent(InstanceTraits::Traits& t)
        : ErrorEvent(t)
    {
    }

    inline IOErrorEvent::IOErrorEvent(InstanceTraits::Traits& t)
        : ErrorEvent(t)
        , ErrorText(GetVM().GetStringManager().GetBuiltin(AS3Builtin_empty_))
    {
    }

    inline PressAndTapGestureEvent::PressAndTapGestureEvent(InstanceTraits::Traits& t)
        : GestureEvent(t)
    {
        TapLocalX = TapLocalY = 0;
        TapStageX = TapStageY = 0;
        TapLocalInitialized = Unk_a9 = false;
    }

    inline TimerEvent::TimerEvent(InstanceTraits::Traits& t)
        : Event(t)
    {
    }

    inline TransformGestureEvent::TransformGestureEvent(InstanceTraits::Traits& t)
        : GestureEvent(t)
    {
        ScaleX = ScaleY = 1.0;
        OffsetX = OffsetY = LocalOffsetX = LocalOffsetY = 0;
        Rotation = 0;
        LocalOffsetInitialized = false;
    }

    inline ProgressEvent::ProgressEvent(InstanceTraits::Traits& t)
        : Event(t)
        , BytesLoaded(0)
        , BytesTotal(0)
    {
    }

    inline FocusEvent::FocusEvent(InstanceTraits::Traits& t)
        : Event(t)
        , ShiftKey(false)
        , KeyCode(0)
        , RelatedObj(NULL)
    {
    }

    inline KeyboardEvent::KeyboardEvent(InstanceTraits::Traits& t)
        : Event(t)
        , KeyLocation(-1)
    {
    }

    inline MouseEvent::MouseEvent(InstanceTraits::Traits& t)
        : Event(t)
        , RelatedObj(NULL)
    {
        AltKey = CtrlKey = ShiftKey = false;
        Delta = 0;
        LocalX = LocalY = 0;
        StageX = StageY = 0;
        LocalInitialized = false;
        ButtonsMask = 0;
    }

    inline AppLifecycleEvent::AppLifecycleEvent(InstanceTraits::Traits& t)
        : Event(t)
    {
        Status.SetNull();
    }

    inline NetStatusEvent::NetStatusEvent(InstanceTraits::Traits& t)
        : Event(t)
        , Code(GetVM().GetStringManager().CreateEmptyString())
        , Level(GetVM().GetStringManager().CreateEmptyString())
    {
    }

    inline TouchEvent::TouchEvent(InstanceTraits::Traits& t)
        : Event(t)
        , RelatedObj(NULL)
    {
        AltKey = CommandKey = ControlKey = CtrlKey = ShiftKey = false;
        LocalX = LocalY = SizeX = SizeY = 0;
        StageX = StageY = 0;
        Pressure = 1.0;
        TouchPointID = 0;
        IsPrimaryTouchPoint = LocalInitialized = false;
    }

    inline StageOrientationEvent::StageOrientationEvent(InstanceTraits::Traits& t)
        : Event(t)
    {
        BeforeOrientation.SetNull();
        AfterOrientation.SetNull();
    }
}} // namespace Instances::fl_events

namespace InstanceTraits { namespace fl_events {
    // @0x14246a9e0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<AppLifecycleEvent::InstanceType> AppLifecycleEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246aad0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<AsyncErrorEvent::InstanceType> AsyncErrorEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ab50
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<ErrorEvent::InstanceType> ErrorEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246abc0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<Event::InstanceType> Event::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ac60
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<EventDispatcher::InstanceType> EventDispatcher::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ace0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<FocusEvent::InstanceType> FocusEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ad90
    Pickable<GestureEvent::InstanceType> GestureEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ade0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<IMEEvent::InstanceType> IMEEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246ae50
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<IOErrorEvent::InstanceType> IOErrorEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246aed0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<KeyboardEvent::InstanceType> KeyboardEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246af90
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<MouseEvent::InstanceType> MouseEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b070
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<NetStatusEvent::InstanceType> NetStatusEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b160
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<PressAndTapGestureEvent::InstanceType> PressAndTapGestureEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b1f0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<ProgressEvent::InstanceType> ProgressEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b2a0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<StageOrientationEvent::InstanceType> StageOrientationEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b3f0
    Pickable<TextEvent::InstanceType> TextEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b440
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<TimerEvent::InstanceType> TimerEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b4f0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<TouchEvent::InstanceType> TouchEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b5e0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    Pickable<TransformGestureEvent::InstanceType> TransformGestureEvent::MakeInstance(Traits& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
    // @0x14246b8e0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void EventDispatcher::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b690
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void AppLifecycleEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b780
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void AsyncErrorEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b7e0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void ErrorEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b840
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void Event::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b950
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void FocusEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246b9f0
    void GestureEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246ba30
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void IMEEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246ba90
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void IOErrorEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bb00
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void KeyboardEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bbb0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void MouseEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bc80
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void NetStatusEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bd60
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void PressAndTapGestureEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bde0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void ProgressEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246be80
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void StageOrientationEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246bfc0
    void TextEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246c000
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void TimerEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246c0a0
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void TouchEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
    // @0x14246c190
    // MS2-FUNCTIONAL: the exe inlines the instance constructor; cl calls it
    void TransformGestureEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(Pickable<InstanceType>(new(t.Alloc()) InstanceType(t)));
    }
}} // namespace InstanceTraits::fl_events

// ---- event object factories: new events of the VM's event classes ---------------------------------------------------
namespace Classes { namespace fl_events {
    namespace
    {
        // the builtin string a MouseCursorEvent is made with (MovieRoot builtin 45)
        enum { BI_mouseCursorChange = 45 };
        // the event ids a mouse event reports the buttons held before the event for
        enum { EV_RollOver = 0x2000, EV_RollOut = 0x4000, EV_MouseIdA = 0x100000a, EV_MouseIdB = 0x100000b };

        // MovieImpl keeps one MouseState per mouse (4, 0x50 bytes each) at +0x1260; gfx_movieimpl.h has not
        // recovered the field. NULL past the last mouse.
        const MouseState* GetMouseState(MovieImpl* movie, unsigned mouseIdx)
        {
            if (mouseIdx >= 4)
                return 0;
            return reinterpret_cast<const MouseState*>(reinterpret_cast<const UByte*>(movie) + 0x1260) + mouseIdx;
        }
    }

    // @0x142466be0
    // MS2-FUNCTIONAL: the argument Values are set up in another order
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateEventObject(const ASString& type, bool bubbles, bool cancelable)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::Event> result;
        Value argv[3] = { Value(type), Value(bubbles), Value(cancelable) };
        vm.ConstructInstance(result, vm.EventClass, 3, argv);
        return result;
    }

    // @0x142466d20
    SPtr<Instances::fl_events::FocusEvent> EventDispatcher::CreateFocusEventObject(const ASString& type,
                                                                                   Instances::fl::Object* relatedObj,
                                                                                   unsigned controllerIdx, bool shiftKey,
                                                                                   UInt32 keyCode)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::FocusEvent> result;
        Value argv[6] = { Value(type), Value(true), Value(false), Value(relatedObj), Value(shiftKey), Value(keyCode) };
        vm.ConstructInstance(result, vm.ExtensionsEnabled ? vm.FocusEventExClass : vm.FocusEventClass, 6, argv);
        if (vm.ExtensionsEnabled)
            static_cast<Instances::fl_gfx::FocusEventEx*>(result.GetPtr())->controllerIdx = controllerIdx;
        return result;
    }

    // @0x142466ff0
    // MS2-FUNCTIONAL: the argument Values are set up in another order
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateIOErrorEventObject(const char* errText)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::Event> result;
        StringManager& sm = vm.GetStringManager();
        Value argv[4] = { Value(sm.CreateConstString("ioError")), Value(false), Value(false),
                          Value(sm.CreateString(errText)) };
        vm.ConstructInstance(result, GetVM().GetClass(StringDataPtr("flash.events.IOErrorEvent")), 4, argv);
        return result;
    }

    // @0x142467340
    // MS2-FUNCTIONAL: the exe copies the EventId byte by byte (skipping the padding); cl copies the whole struct
    SPtr<Instances::fl_events::KeyboardEvent> EventDispatcher::CreateKeyboardEventObject(const EventId& evtId,
                                                                                         const ASString& type,
                                                                                         Instances::fl::Object* target)
    {
        SPtr<Instances::fl_events::KeyboardEvent> result;
        Value argv[1] = { Value(type) };
        ASVM& vm = static_cast<ASVM&>(GetVM());
        vm.ConstructInstance(result, vm.ExtensionsEnabled ? vm.KeyboardEventExClass : vm.KeyboardEventClass, 1, argv);
        result->Target = target;
        result->EvtId = evtId;
        if (!result->EvtId.AsciiCode)
            result->EvtId.AsciiCode = result->EvtId.ConvertKeyCodeToAscii();
        result->Bubbles = true;
        result->Cancelable = false;
        if (vm.ExtensionsEnabled)
            static_cast<Instances::fl_gfx::KeyboardEventEx*>(result.GetPtr())->controllerIdx = evtId.KeyboardIndex;
        return result;
    }

    // @0x1424674c0
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateMouseCursorEventObject(const ASString& cursor, unsigned mouseIdx)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::Event> result;
        Value argv[3] = { Value(vm.GetBuiltin(BuiltinType(BI_mouseCursorChange))), Value(false), Value(true) };
        if (Class* cls = GetVM().GetClass(StringDataPtr("scaleform.gfx.MouseCursorEvent")))
        {
            vm.ConstructInstance(result, cls, 3, argv);
            static_cast<Instances::fl_gfx::MouseCursorEvent*>(result.GetPtr())->mouseIdx = mouseIdx;
            static_cast<Instances::fl_gfx::MouseCursorEvent*>(result.GetPtr())->cursor = cursor;
        }
        return result;
    }

    // @0x142467790
    // MS2-FUNCTIONAL: register allocation and the order of the flag stores differ
    SPtr<Instances::fl_events::MouseEvent> EventDispatcher::CreateMouseEventObject(const EventId& evtId,
                                                                                   const ASString& type,
                                                                                   Instances::fl::Object* target)
    {
        SPtr<Instances::fl_events::MouseEvent> result;
        Value argv[1] = { Value(type) };
        ASVM& vm = static_cast<ASVM&>(GetVM());
        vm.ConstructInstance(result, vm.ExtensionsEnabled ? vm.MouseEventExClass : vm.MouseEventClass, 1, argv);
        result->Target = target;
        // roll over/out do not bubble
        result->Bubbles = !(evtId.Id == EV_RollOver || evtId.Id == EV_RollOut);
        result->Cancelable = false;
        result->AltKey = (evtId.KeysState >> 2) & 1;
        result->CtrlKey = (evtId.KeysState >> 1) & 1;
        result->ShiftKey = evtId.KeysState & 1;
        result->Delta = evtId.MouseWheelDelta;
        if (vm.ExtensionsEnabled)
        {
            Instances::fl_gfx::MouseEventEx* ex = static_cast<Instances::fl_gfx::MouseEventEx*>(result.GetPtr());
            ex->mouseIdx = evtId.MouseIndex;
            ex->nestingIdx = evtId.RollOverCnt;
            ex->buttonIdx = evtId.ButtonId;
        }
        const MouseState* ms = GetMouseState(static_cast<ASVM&>(GetVM()).GetMovieImpl(), evtId.MouseIndex);
        result->StageX = ms->GetLastPosition().x;
        result->StageY = ms->GetLastPosition().y;
        UInt32 id = evtId.Id;
        if (id == EV_RollOver || id == EV_RollOut || id == EV_MouseIdA || id == EV_MouseIdB)
            result->ButtonsMask = ms->GetPrevButtonsState();
        else
            result->ButtonsMask = ms->GetButtonsState();
        return result;
    }

    // @0x1424679d0
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateNetStatusEventObject(const ASString& code, const ASString& level)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::Event> result;
        Class* cls = GetVM().GetClass(StringDataPtr("flash.events.NetStatusEvent"));
        Value argv[5] = { Value(vm.GetStringManager().CreateConstString("netStatus")), Value(false), Value(false),
                          Value(code), Value(level) };
        vm.ConstructInstance(result, cls, 5, argv);
        return result;
    }

    // @0x142467ce0
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateProgressEventObject(const ASString& type)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_events::Event> result;
        Value argv[3] = { Value(type), Value(false), Value(false) };
        vm.ConstructInstance(result, vm.ProgressEventClass, 3, argv);
        return result;
    }
}} // namespace Classes::fl_events

namespace Instances { namespace fl_events {
    // The dispatcher's class object (Classes::fl_events::EventDispatcher or a subclass).
    static Classes::fl_events::EventDispatcher& GetDispatcherClass(const EventDispatcher& d)
    {
        return static_cast<Classes::fl_events::EventDispatcher&>(d.GetTraits().GetConstructor());
    }

    // @0x142466cd0
    // MS2-FUNCTIONAL: cl keeps the result pointer in another register
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateEventObject(const ASString& type, bool bubbles, bool cancelable)
    {
        return GetDispatcherClass(*this).CreateEventObject(type, bubbles, cancelable);
    }
    // @0x142466e80
    // MS2-FUNCTIONAL: the exe inlines the class object's factory; cl calls it
    SPtr<Instances::fl_events::FocusEvent> EventDispatcher::CreateFocusEventObject(const ASString& type,
                                                                                   Instances::fl::Object* relatedObj,
                                                                                   unsigned controllerIdx, bool shiftKey,
                                                                                   UInt32 keyCode)
    {
        return GetDispatcherClass(*this).CreateFocusEventObject(type, relatedObj, controllerIdx, shiftKey, keyCode);
    }
    // @0x142467190
    // MS2-FUNCTIONAL: the exe inlines the class object's factory; cl calls it
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateIOErrorEventObject(const char* errText)
    {
        return GetDispatcherClass(*this).CreateIOErrorEventObject(errText);
    }
    // @0x142467620
    // MS2-FUNCTIONAL: the exe inlines the class object's factory; cl calls it
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateMouseCursorEventObject(const ASString& cursor, unsigned mouseIdx)
    {
        return GetDispatcherClass(*this).CreateMouseCursorEventObject(cursor, mouseIdx);
    }
    // @0x142467b50
    // MS2-FUNCTIONAL: the exe inlines the class object's factory; cl calls it
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateNetStatusEventObject(const ASString& code, const ASString& level)
    {
        return GetDispatcherClass(*this).CreateNetStatusEventObject(code, level);
    }
    // @0x142467dc0
    // MS2-FUNCTIONAL: the exe inlines the class object's factory; cl calls it
    SPtr<Instances::fl_events::Event> EventDispatcher::CreateProgressEventObject(const ASString& type)
    {
        return GetDispatcherClass(*this).CreateProgressEventObject(type);
    }
}} // namespace Instances::fl_events

// ---- collector visits ---------------------------------------------------------------------------------------------

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
SF_INLINE void CallGcOp(ASRefCountBaseType::GcOp op, RefCountCollector<StatMV_ActionScript_Mem>* prcc,
                        const ASRefCountBaseType** pchild, const ASRefCountBaseType& owner)
{
    reinterpret_cast<GcOpWithOwner>(op)(prcc, pchild, owner);
}

// Visits a counted pointer member.
template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (p.GetPtr())
        CallGcOp(op, prcc, const_cast<const ASRefCountBaseType**>(reinterpret_cast<ASRefCountBaseType**>(p.GetRawPtr())), owner);
}

namespace Instances { namespace fl_events {

    // @0x142469380
    void Event::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        AS3::Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, CurrentTarget, op, *this);
        AS3::ForEachChild_GC(prcc, Target, op, *this);
    }

    // @0x142469300
    void AppLifecycleEvent::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Event::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Status, op, *this);
    }

    // @0x1424694b0
    void FocusEvent::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        AS3::Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, RelatedObj, op, *this);
    }

    // @0x1424697a0
    void MouseEvent::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        AS3::Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, RelatedObj, op, *this);
    }

    // @0x1424697e0
    void StageOrientationEvent::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Event::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, BeforeOrientation, op, *this);
        AS3::ForEachChild_GC(prcc, AfterOrientation, op, *this);
    }

    // @0x142469880
    void TouchEvent::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        AS3::Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, RelatedObj, op, *this);
    }

    // The listener functions of one table. Outside the VM's destructor, weak listeners whose function was collected
    // are dropped here (with the event chain and button count bookkeeping of removeEventListener).
    // @0x1424694f0
    // MS2-FUNCTIONAL: register allocation and block layout of the two listener loops
    static __declspec(noinline) void ForEachListener_GC(EventDispatcher::ListenersHash& hash,
                                                        RefCountCollector<StatMV_ActionScript_Mem>* prcc,
                                                        ASRefCountBaseType::GcOp op, const VM& vm,
                                                        EventDispatcher& owner, bool useCapture)
    {
        for (EventDispatcher::ListenersHash::Iterator it = hash.Begin(); it != hash.End(); ++it)
        {
            ArrayLH<EventDispatcher::Listener>* listeners = (*it).Second;
            if (!listeners)
                continue;
            UPInt n = listeners->GetSize();
            if (!vm.InDestructor)
            {
                for (UPInt i = 0; i < n; )
                {
                    if ((*listeners)[i].Function.IsValidWeakRef())
                    {
                        AS3::ForEachChild_GC(prcc, (*listeners)[i].Function, op, owner);
                        ++i;
                    }
                    else
                    {
                        listeners->RemoveAt(i);
                        --n;
                        OnListenerRemoved(&owner, (*it).First, useCapture, n);
                    }
                }
            }
            else
            {
                for (UPInt i = 0; i < n; ++i)
                    if ((*listeners)[i].Function.IsValidWeakRef())
                        AS3::ForEachChild_GC(prcc, (*listeners)[i].Function, op, owner);
            }
        }
    }

    // @0x142469440
    void EventDispatcher::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        AS3::Object::ForEachChild_GC(prcc, op);
        if (pImpl)
        {
            EventDispatcher& self = const_cast<EventDispatcher&>(*this);
            ForEachListener_GC(pImpl->CaptureListeners, prcc, op, *pVM, self, true);
            ForEachListener_GC(pImpl->Listeners, prcc, op, *pVM, self, false);
        }
    }

}} // namespace Instances::fl_events

namespace Classes { namespace fl_events {
    // @0x1424693e0
    void EventDispatcher::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Class::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Unk50, op, *this);
        AS3::ForEachChild_GC(prcc, Unk58, op, *this);
    }
}} // namespace Classes::fl_events

namespace Instances { namespace fl_events {
    // ---- dispatch helpers -------------------------------------------------------------------------------------------

    // @0x142468740
    bool EventDispatcher::DispatchEventObject(Instances::fl_events::Event* evt, GFx::DisplayObject* dobj)
    {
        evt->Target = this;
        Dispatch(evt, dobj);
        return !evt->DefaultPrevented;
    }

    // The log of the VM's movie (0x14246a100).
    // @0x14246a100
    static __declspec(noinline) LogState* GetVMLogState(VM& vm)
    {
        return static_cast<ASVM&>(vm).GetMovieImpl()->GetStateBag()->GetLogState();
    }

    // @0x142468e60
    // MS2-FUNCTIONAL: cl keeps the new event in another register; the same calls and tests
    bool EventDispatcher::DispatchTypeToTarget(const ASString& type, Instances::fl::Object* target, bool inCapturePhase,
                                               GFx::DisplayObject* dobj)
    {
        if (!pImpl)
            return true;
        VM& vm = GetVM();
        if (vm.HandleException)
        {
            if (static_cast<ASVM&>(vm).GetMovieImpl()->GetStateBag()->GetLogState())
                GetVMLogState(vm)->LogScriptError("Can't dispatch '%s' - exception is not cleared", type.ToCStr());
            return true;
        }
        SPtr<Instances::fl_events::Event> evt = GetDispatcherClass(*this).CreateEventObject(type, false, false);
        evt->Target = target;
        evt->CurrentTarget = target;
        if (!DispatchSingleEvent(evt.GetPtr(), inCapturePhase) && dobj)
            dobj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
        return !evt->DefaultPrevented;
    }

    // @0x1424691d0
    bool EventDispatcher::ExecuteBubblePhase(Instances::fl_events::Event* evt,
                                             ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain)
    {
        evt->Phase = 3;
        for (UPInt i = 0, n = chain.GetSize(); i < n; ++i)
        {
            if (!chain[i]->DispatchSingleEvent(evt, false))
            {
                if (chain[i]->pDispObj)
                    chain[i]->pDispObj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
                return false;
            }
            if (evt->PropagationStopped || evt->ImmPropagationStopped)
                return false;
        }
        return true;
    }

    // @0x142469260
    bool EventDispatcher::ExecuteCapturePhase(Instances::fl_events::Event* evt,
                                              ArrayStaticBuff<SPtr<Instances::fl_display::DisplayObject>, 32>& chain)
    {
        evt->Phase = 1;
        for (SPInt i = (SPInt)chain.GetSize() - 1; i >= 0; --i)
        {
            if (!chain[i]->DispatchSingleEvent(evt, true))
            {
                if (chain[i]->pDispObj)
                    chain[i]->pDispObj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
                return false;
            }
            if (evt->PropagationStopped || evt->ImmPropagationStopped)
                return false;
        }
        return true;
    }

    // ---- simple properties ------------------------------------------------------------------------------------------

    // @0x14246f880
    // MS2-FUNCTIONAL: the exe's counted pointer assignment releases the old value inline (leaf); cl calls out
    void Event::targetGet(SPtr<Instances::fl::Object>& result)
    {
        result = Target;
    }

    // @0x142472d20
    void Event::typeGet(ASString& result)
    {
        result = Type;
    }

    // @0x14246f920
    void TextEvent::textGet(ASString& result)
    {
        result = Text;
    }

    // @0x14246f9a0
    void TextEvent::textSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        Text = value;
    }

    // @0x14246f8e0
    void IOErrorEvent::textGet(ASString& result)
    {
        result = ErrorText;
    }

    // @0x14246f960
    void IOErrorEvent::textSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        ErrorText = value;
    }

    // A property lookup that found something: a set This, not the tagged null value or the tagged null object.
    static inline bool PropRefFound(const PropRef& prop)
    {
        const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
        if (prop.This.GetKind() == Value::kUndefined || bits == 1)
            return false;
        return !((bits & 2) != 0 && (bits & ~UPInt(2)) == 0);
    }

    // "[<argv0> name=value ...]": argv[0] is the class name, the rest are property names of this event, string
    // values quoted. A missing property throws ReferenceError 1069 and leaves result unset.
    // @0x14246dfc0
    // MS2-FUNCTIONAL: written from behaviour
    void Event::formatToString(Value& result, unsigned argc, const Value* argv)
    {
        VM& vm = GetVM();
        if (argc == 0)
        {
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Event::formatToString", 1, 1, argc));
            return;
        }
        StringBuffer buf(vm.GetMemoryHeap());
        char tmp[1024];
        ASString name = static_cast<ASVM&>(vm).GetBuiltin(AS3Builtin_empty_);
        argv[0].Convert2String(name).DoNotCheck();
        SFsprintf(tmp, sizeof(tmp), "[%s", name.ToCStr());
        buf.AppendString(tmp);
        for (unsigned i = 1; i < argc; ++i)
        {
            argv[i].Convert2String(name).DoNotCheck();
            Multiname mn(vm.GetPublicNamespace(), Value(name));
            PropRef prop;
            FUN_142502360(this, prop, mn, 0);
            if (!PropRefFound(prop))
            {
                SFsprintf(tmp, sizeof(tmp),
                          "Property %s not found on flash.events.Event and there is no default value.", name.ToCStr());
                vm.ThrowReferenceError(VM::Error(VM::ErrorID(1069), vm, tmp));
                return;
            }
            Value v;
            if (!prop.GetSlotValueUnsafe(vm, v, SlotInfo::valGet))
                return;
            SFsprintf(tmp, sizeof(tmp), " %s=", name.ToCStr());
            buf.AppendString(tmp);
            const bool quote = v.GetKind() == Value::kString;
            v.Convert2String(name).DoNotCheck();
            if (quote)
                buf.AppendChar('"');
            SFsprintf(tmp, sizeof(tmp), "%s", name.ToCStr());
            buf.AppendString(tmp);
            if (quote)
                buf.AppendChar('"');
        }
        buf.AppendString("]", 2);
        result.Assign(vm.GetStringManager().CreateString(buf.ToCStr()));
    }

    // toString of the event classes: formatToString of the class name and the listed properties.
    static void FormatEventString(Event& e, ASString& result, const char* className, const char* const* props,
                                  unsigned count)
    {
        StringManager& sm = e.GetVM().GetStringManager();
        Value argv[20];
        argv[0].Assign(sm.CreateConstString(className));
        for (unsigned i = 0; i < count; ++i)
            argv[i + 1].Assign(sm.CreateConstString(props[i]));
        Value r;
        e.formatToString(r, count + 1, argv);
        r.Convert2String(result).DoNotCheck();
    }

    // @0x14246fc50
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    // Not inlined: TimerEvent::toString tail-calls it in the exe.
    SF_NOINLINE void Event::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase" };
        FormatEventString(*this, result, GetEventName(), props, 4);
    }

    // @0x14246f9e0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void AppLifecycleEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "status" };
        FormatEventString(*this, result, "AppLifecycleEvent", props, 4);
    }

    // @0x14246feb0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void FocusEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "relatedObject",
                                             "shiftKey", "keyCode" };
        FormatEventString(*this, result, "FocusEvent", props, 7);
    }

    // @0x1424701d0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void GestureEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "phase", "localX", "localY", "stageX",
                                             "stageY", "ctrlKey", "altKey", "shiftKey", "commandKey", "controlKey" };
        FormatEventString(*this, result, "GestureEvent", props, 13);
    }

    // @0x1424706a0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void IOErrorEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "text" };
        FormatEventString(*this, result, "IOErrorEvent", props, 3);
    }

    // @0x142470890
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void KeyboardEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "charCode", "keyCode",
                                             "keyLocation", "ctrlKey", "altKey", "shiftKey" };
        FormatEventString(*this, result, "KeyboardEvent", props, 10);
    }

    // @0x142470c80
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void MouseEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "localX", "localY",
                                             "stageX", "stageY", "relatedObject", "ctrlKey", "altKey", "shiftKey",
                                             "delta" };
        FormatEventString(*this, result, "MouseEvent", props, 13);
    }

    // @0x142471140
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void NetStatusEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "info", "target" };
        FormatEventString(*this, result, GetEventName(), props, 5);
    }

    // @0x1424713e0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void PressAndTapGestureEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "phase", "localX", "localY",
                                             "tapLocalX", "tapLocalY", "ctrlKey", "altKey", "shiftKey", "commandKey",
                                             "controlKey" };
        FormatEventString(*this, result, "PressAndTapGestureEvent", props, 13);
    }

    // @0x1424718a0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void ProgressEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "bytesLoaded",
                                             "bytesTotal" };
        FormatEventString(*this, result, "ProgressEvent", props, 6);
    }

    // @0x142471b70
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void StageOrientationEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "beforeOrientation",
                                             "afterOrientation" };
        FormatEventString(*this, result, "StageOrientationEvent", props, 5);
    }

    // @0x142471e00
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void TextEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "text" };
        FormatEventString(*this, result, "TextEvent", props, 5);
    }

    // @0x1424720a0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void TouchEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "eventPhase", "touchPointID",
                                             "isPrimaryTouchPoint", "localX", "localY", "stageX", "stageY", "sizeX",
                                             "sizeY", "relatedObject", "ctrlKey", "altKey", "shiftKey", "commandKey",
                                             "controlKey" };
        FormatEventString(*this, result, "TouchEvent", props, 18);
    }

    // @0x1424726d0
    // MS2-FUNCTIONAL: the exe builds the argument array inline
    void TransformGestureEvent::toString(ASString& result)
    {
        static const char* const props[] = { "type", "bubbles", "cancelable", "phase", "localX", "localY", "stageX",
                                             "stageY", "scaleX", "scaleY", "rotation", "offsetX", "offsetY",
                                             "ctrlKey", "altKey", "shiftKey", "commandKey", "controlKey" };
        FormatEventString(*this, result, "TransformGestureEvent", props, 18);
    }

    // A new Object {code, level}.
    // @0x14246e560
    // MS2-FUNCTIONAL: written from behaviour
    void NetStatusEvent::infoGet(SPtr<Instances::fl::Object>& result)
    {
        VM& vm = GetVM();
        SPtr<Instances::fl::Object> o;
        FUN_142516600(vm, o);
        StringManager& sm = vm.GetStringManager();
        o->AddDynamicSlotValuePair(sm.CreateString("code"), Value(Code));
        o->AddDynamicSlotValuePair(sm.CreateString("level"), Value(Level));
        result = o;
    }

    // Code and level from the object's properties of those names, when it has them.
    // @0x14246e710
    // MS2-FUNCTIONAL: written from behaviour
    void NetStatusEvent::infoSet(const Value& result, const Value& value)
    {
        SF_UNUSED(result);
        AS3::Object* o = value.GetObject();
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        Multiname mnCode(vm.GetPublicNamespace(), Value(sm.CreateString("code")));
        Multiname mnLevel(vm.GetPublicNamespace(), Value(sm.CreateString("level")));
        Value v;
        if (o->GetProperty(mnCode, v))
            v.Convert2String(Code).DoNotCheck();
        if (o->GetProperty(mnLevel, v))
            v.Convert2String(Level).DoNotCheck();
    }

    // @0x14246edd0
    void GestureEvent::phaseGet(ASString& result)
    {
        const char* name = DAT_143a2d158[Phase];
        if (name)
            result = GetVM().GetStringManager().CreateConstString(name);
        else
            result.SetNull();
    }

    // @0x14246ee90
    // MS2-FUNCTIONAL: written from behaviour
    void GestureEvent::phaseSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        if (value.GetNode() != value.GetManager()->GetNullStringNode())
        {
            const char* s = value.ToCStr();
            if (strcmp(s, "all") == 0)
            {
                Phase = 1;
                return;
            }
            if (strcmp(s, "begin") == 0)
            {
                Phase = 2;
                return;
            }
            if (strcmp(s, "end") == 0)
            {
                Phase = 3;
                return;
            }
            if (strcmp(s, "update") == 0)
            {
                Phase = 4;
                return;
            }
        }
        Phase = 0;
    }

    // @0x14246c8d0
    // the exe copies the fields through a reference to EvtId (one byte of the AsciiCode union, not the SDK's
    // EvtId = eid), then tests the stored AsciiCode
    void KeyboardEvent::SetEventId(const EventId& id)
    {
        EventId& e = EvtId;
        e.Id              = id.Id;
        e.WcharCode       = id.WcharCode;
        e.KeyCode         = id.KeyCode;
        e.AsciiCode       = id.AsciiCode;
        e.RollOverCnt     = id.RollOverCnt;
        e.KeyboardIndex   = id.KeyboardIndex;
        e.KeysState       = id.KeysState;
        e.MouseWheelDelta = id.MouseWheelDelta;
        if (EvtId.AsciiCode == 0)
            EvtId.AsciiCode = EvtId.ConvertKeyCodeToAscii();
    }

    // @0x14246c930
    void TextEvent::SetText(wchar_t ch)
    {
        Text = ASString(GetVM().GetStringManager().GetStringManager()->CreateStringNode(&ch, 1));
    }

    // @0x14246c9a0
    // MS2-FUNCTIONAL: cl inlines the listener table lookup (0x1424698c0) that the exe calls
    bool EventDispatcher::WillTrigger(const ASString& type, bool useCapture) const
    {
        if (pImpl)
        {
            const ListenersHash& h = useCapture ? pImpl->CaptureListeners : pImpl->Listeners;
            ArrayLH<Listener>* const* pa = h.Get(type);
            if (pa && *pa && (*pa)->GetSize() != 0)
                return true;
        }
        if (!IsDisplayObjectInstance(GetTraits()))
            return false;
        GFx::DisplayObject* dobj = static_cast<const Instances::fl_display::DisplayObject*>(this)->pDispObj;
        if (!dobj)
            return false;
        for (InteractiveObject* p = dobj->GetParent(); p; p = p->GetParent())
        {
            // the AS3 object of the parent, as in GetParentChain
            const UPInt* avm = reinterpret_cast<const UPInt*>(p->GetAvmObjImpl());
            UPInt raw = avm[2] ? avm[2] : avm[1];
            const EventDispatcher* o = reinterpret_cast<const EventDispatcher*>(raw & ~UPInt(1));
            if (o && o->HasEventHandler(type, useCapture))
                return true;
        }
        return false;
    }

    // The abc file a listener function comes from keeps the MovieDefImpl of its movie: VMAbcFile +0x28 is the
    // file data, which holds the definition at +0x188.
    static inline GFx::MovieDefImpl* GetFileMovieDef(const VMAbcFile* file)
    {
        const char* abc = *reinterpret_cast<const char* const*>(reinterpret_cast<const char*>(file) + 0x28);
        return *reinterpret_cast<GFx::MovieDefImpl* const*>(abc + 0x188);
    }

    // Removes from hash the listeners whose function was loaded from pdef.
    // @0x14246c530
    // MS2-FUNCTIONAL: cl lays out the table walk differently; the same lookups and removals
    static void RemoveMovieDefListeners(EventDispatcher& d, GFx::MovieDefImpl* pdef,
                                        EventDispatcher::ListenersHash& hash)
    {
        for (EventDispatcher::ListenersHash::Iterator it = hash.Begin(); it != hash.End(); ++it)
        {
            ArrayLH<EventDispatcher::Listener>& a = *(*it).Second;
            for (UPInt i = 0; i < a.GetSize();)
            {
                const Value& f = a[i].Function;
                if (f.IsValidWeakRef())
                {
                    const Traits* tr;
                    if (f.GetKind() == Value::kVTableInd)
                        tr = &f.GetTraits();
                    else if (f.GetKind() == Value::kVTableIndClosure)
                        tr = &f.GetClosure()->GetTraits();
                    else
                        tr = &FUN_14250ffc0(d.GetVM(), f);
                    VMAbcFile* file = tr->GetFilePtr();
                    if (file && GetFileMovieDef(file) == pdef)
                    {
                        a.RemoveAt(i);
                        continue;
                    }
                }
                ++i;
            }
        }
    }

    // @0x14246c700
    void EventDispatcher::RemoveListenersForMovieDef(GFx::MovieDefImpl* pdef)
    {
        if (pImpl)
        {
            RemoveMovieDefListeners(*this, pdef, pImpl->CaptureListeners);
            RemoveMovieDefListeners(*this, pdef, pImpl->Listeners);
        }
    }

    // The AS3 movie root keeps a 0xe0-byte state per mouse from +0x360; +0x18 of it is the display object the mouse
    // was over before. Its AS3 object, or NULL.
    static Instances::fl_display::InteractiveObject* GetLastMouseOverObject(ASVM& vm, int mouseIdx)
    {
        if ((unsigned)mouseIdx >= 4)
            return NULL;
        const char* state = reinterpret_cast<const char*>(vm.GetMovieRoot()) + 0x360 + mouseIdx * 0xe0;
        GFx::DisplayObject* dobj = *reinterpret_cast<GFx::DisplayObject* const*>(state + 0x18);
        if (!dobj)
            return NULL;
        const UPInt* avm = reinterpret_cast<const UPInt*>(dobj->GetAvmObjImpl());
        UPInt raw = avm[2] ? avm[2] : avm[1];
        return reinterpret_cast<Instances::fl_display::InteractiveObject*>(raw & ~UPInt(1));
    }

    // @0x142467ec0
    // MS2-FUNCTIONAL: the exe repeats the create/dispatch/release sequence per case; cl shares it
    bool EventDispatcher::Dispatch(const EventId& evtId, GFx::DisplayObject* dobj)
    {
        enum
        {
            BI_mouseMove = 49, BI_mouseWheel = 53, BI_keyDown = 56, BI_keyUp = 57
        };
        enum
        {
            EV_MouseOver = 0x100000a, EV_MouseOut, EV_Click, EV_DoubleClick, EV_MouseWheel
        };
        ASVM& vm = static_cast<ASVM&>(GetVM());
        Classes::fl_events::EventDispatcher& cls = GetDispatcherClass(*this);
        SPtr<Instances::fl_events::Event> evt;
        switch (evtId.Id)
        {
        case EventId::Event_EnterFrame:
        case EV_Activate:
        case EV_Deactivate:
        case EV_Render:
        case EV_Resize:
        {
            // to this dispatcher's listeners only
            BuiltinType bt = BuiltinType(evtId.Id == EventId::Event_EnterFrame ? BI_enterFrame :
                                         evtId.Id == EV_Activate ? BI_activate :
                                         evtId.Id == EV_Deactivate ? BI_deactivate :
                                         evtId.Id == EV_Render ? BI_render : BI_resize);
            evt = cls.CreateEventObject(vm.GetBuiltin(bt), false, false);
            evt->Target = this;
            if (!DispatchSingleEvent(evt, false) && dobj)
                dobj->Flags |= GFx::DisplayObject::Mask_ExecutionAborted;
            return !evt->DefaultPrevented;
        }
        case EventId::Event_KeyDown:
            evt = cls.CreateKeyboardEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_keyDown)), this);
            break;
        case EventId::Event_KeyUp:
            evt = cls.CreateKeyboardEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_keyUp)), this);
            break;
        case EventId::Event_MouseMove:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_mouseMove)), this);
            break;
        case EventId::Event_MouseDown:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_mouseDown)), this);
            break;
        case EventId::Event_MouseUp:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_mouseUp)), this);
            break;
        case EventId::Event_RollOver:
        case EventId::Event_RollOut:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(
                      evtId.Id == EventId::Event_RollOver ? BI_rollOver : BI_rollOut)), this);
            evt->Bubbles = false;
            break;
        case EV_MouseOver:
        case EV_MouseOut:
        {
            SPtr<Instances::fl_events::MouseEvent> mevt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(
                evtId.Id == EV_MouseOver ? BI_mouseOver : BI_mouseOut)), this);
            mevt->RelatedObj = GetLastMouseOverObject(vm, evtId.MouseIndex);
            // the object the mouse leaves is not its own related object
            if (evtId.Id == EV_MouseOut && mevt->RelatedObj && (void*)mevt->RelatedObj.GetPtr() == (void*)this)
                mevt->RelatedObj = NULL;
            evt = mevt.GetPtr();
            break;
        }
        case EV_Click:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_click)), this);
            break;
        case EV_DoubleClick:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_doubleClick)), this);
            break;
        case EV_MouseWheel:
            evt = cls.CreateMouseEventObject(evtId, vm.GetBuiltin(BuiltinType(BI_mouseWheel)), this);
            break;
        default:
            return true;
        }
        Dispatch(evt, dobj);
        return !evt->DefaultPrevented;
    }
}} // namespace Instances::fl_events

// ==== flash.external.ExternalInterface: class traits ==================================================================

namespace fl_external
{
    extern const ClassInfo ExternalInterfaceCI;
}

namespace Classes { namespace fl_external
{
    // @0x142473570
    ExternalInterface::ExternalInterface(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_external
{
    // @0x142473490
    ExternalInterface::ExternalInterface(VM& vm)
        : Traits(vm, AS3::fl_external::ExternalInterfaceCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_external::ExternalInterfaceCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_external::ExternalInterface(*this)));
    }

    // @0x142473350
    Pickable<Traits> ExternalInterface::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ExternalInterface(vm));
    }
}}

}}} // namespace Scaleform::GFx::AS3

// The general warning channel of a log state.
// @0x1424736b0
template void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(const char* pfmt, ...) const;

// The listener table lookup and growth, out of line in the exe.
// @0x1424698c0
// MS2-FUNCTIONAL: register allocation of the probe loop
template Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener>**
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::BaseType::BaseType::Get(
        const Scaleform::GFx::ASString& key);
// @0x14246f310
template void decltype(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::BaseType::BaseType::mHash)
    ::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);

// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142472fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473020
// MS2-PIN: ?Func@?$ThunkFunc1@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473080
// MS2-PIN: ?Func@?$ThunkFunc0@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424730e0
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$03$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473150
// MS2-PIN: ?Func@?$ThunkFunc2@VExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@$04VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473330
// MS2-PIN: ??_GExternalInterface@fl_external@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424735a0
// MS2-PIN: ??_GExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142473630
// MS2-PIN: ??_7ExternalInterface@fl_external@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143158a20
// MS2-PIN: ??_7ExternalInterface@fl_external@Classes@AS3@GFx@Scaleform@@6B@ 0x143158ab8
// MS2-PIN: ?Get@?$Hash@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@3@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@3@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@3@V?$HashSet@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@3@@Scaleform@@QEAAPEAPEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@2@AEBVASString@GFx@2@@Z 0x1424698c0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14246f310
// MS2-PIN: ??_7AppLifecycleEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143158048
// MS2-PIN: ??_7AsyncErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143153e40
// MS2-PIN: ??_7ErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143153b38
// MS2-PIN: ??_7Event@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x1431533b8
// MS2-PIN: ??_7EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x1431542f0
// MS2-PIN: ??_7FocusEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143156030
// MS2-PIN: ??_7IMEEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143157028
// MS2-PIN: ??_7IOErrorEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143156338
// MS2-PIN: ??_7KeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143155a10
// MS2-PIN: ??_7MouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143154a88
// MS2-PIN: ??_7NetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143156648
// MS2-PIN: ??_7PressAndTapGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x1431556d8
// MS2-PIN: ??_7ProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143155d20
// MS2-PIN: ??_7StageOrientationEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143158380
// MS2-PIN: ??_7TimerEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x1431579d0
// MS2-PIN: ??_7TouchEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x143154d90
// MS2-PIN: ??_7TransformGestureEvent@fl_events@Instances@AS3@GFx@Scaleform@@6B@ 0x1431553a8
