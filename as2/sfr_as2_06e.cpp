// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 movie clip events: the clip
// event dispatch and the load / unload events of AvmSprite, the class natives a registered clip runs when it is
// made, and the replacement of a child clip by a loaded movie.
// MS2-UNIT: sfr_as2_06e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142961a40-0x142961b40 .text$mn
// MS2-RANGE: 0x142961d80-0x142961ef0 .text$mn
// MS2-RANGE: 0x14296b490-0x14296b820 .text$mn
// MS2-RANGE: 0x14296b860-0x14296ba60 .text$mn
// MS2-RANGE: 0x142969080-0x142969250 .text$mn
// MS2-RANGE: 0x14296c8c0-0x14296cb80 .text$mn
// MS2-RANGE: 0x14296ce90-0x14296d120 .text$mn
// MS2-RANGE: 0x14296d140-0x14296d310 .text$mn
// MS2-RANGE: 0x14297d330-0x14297d460 .text$mn
// MS2-RANGE: 0x14296bd60-0x14296c0d0 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_broadcastlocal.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_spritedef.h"
#include "../include/render/text_core.h"
#include <string.h>

namespace Scaleform {
// sfr_as2_06 defines this as an explicit specialization; without the declaration this unit instantiates the
// header body and the two clash in the DLL link.
template <>
void ArrayBase<ArrayData<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                         ArrayDefaultPolicy> >::RemoveAt(UPInt index);
}


namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// The clips with a hit area, kept by the movie root at +0x628 (not in the MovieRoot header yet).
typedef ArrayLH<Ptr<Sprite>, StatMV_Other_Mem> HitAreaArray;
SF_FORCEINLINE HitAreaArray& LeHitAreas(MovieRoot* proot)
{
    return *reinterpret_cast<HitAreaArray*>(reinterpret_cast<UByte*>(proot) + 0x628);
}

// AvmCharacter::HasClipEventHandler, inlined in the exe: key down / up handlers are found by the event alone.
SF_FORCEINLINE bool LeHasClipEventHandler(const AvmCharacter* pch, const EventId& id)
{
    EventId key = (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp) ? EventId(id.Id) : id;
    return pch->EventHandlers.Get(key) != 0;
}

// MovieImpl::IsKeyboardFocused, inlined in the exe.
SF_FORCEINLINE bool LeIsKeyboardFocused(const MovieImpl* pmovie, const InteractiveObject* ch, unsigned controllerIdx)
{
    const unsigned         group   = pmovie->FocusGroupIndexes[controllerIdx];
    Ptr<InteractiveObject> focused = pmovie->FocusGroups[group].LastFocused;
    return focused.GetPtr() == ch && pmovie->FocusGroups[group].FocusRectShown;
}

// AvmSprite::GetHitAreaIndex, inlined in the exe: the index of the clip in the hit area array of the movie root, -1
// when it has no hit area or is not there. The array is read again on each pass.
SF_FORCEINLINE int LeHitAreaIndex(const AvmSprite* pavm)
{
    UPInt spriteArraySize = LeHitAreas(pavm->GetAS2Root()).GetSize();
    if (pavm->GetSprite()->pHitAreaHandle)
    {
        for (unsigned i = 0; i < spriteArraySize; i++)
            if (LeHitAreas(pavm->GetAS2Root())[i] == pavm->GetSprite())
                return i;
    }
    return -1;
}

// ActionEntry::SetAction for an event (inlined in the exe).
SF_FORCEINLINE void LeSetEventAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, const EventId& id)
{
    pe->Type = MovieRoot::ActionEntry::Entry_Event;
    if (pch)
        pch->AddRef();
    if (pe->pCharacter)
        pe->pCharacter->Release();
    pe->pCharacter.GetRawRef() = pch;
    if (pe->pActionBuffer)
        pe->pActionBuffer->Release();
    pe->pActionBuffer.GetRawRef() = 0;
    pe->mEventId = id;
}
// The same for an event built from its id alone: EventId(id) is constructed in place after the releases.
SF_FORCEINLINE void LeSetEventAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, UInt32 id)
{
    pe->Type = MovieRoot::ActionEntry::Entry_Event;
    pe->pCharacter = pch;
    if (pe->pActionBuffer)
        pe->pActionBuffer->Release();
    pe->pActionBuffer.GetRawRef() = 0;
    EventId& eid = pe->mEventId;
    eid.Id = id;
    eid.WcharCode = 0;
    eid.KeyCode = 0;
    eid.AsciiCode = 0;
    eid.RollOverCnt = 0;
    eid.KeysState = 0;
    eid.MouseWheelDelta = 0;
    eid.ControllerIndex = -1;
}

// DisplayObjectBase::IsJustLoaded, inlined in the exe.
SF_FORCEINLINE bool LeIsJustLoaded(const DisplayObjectBase* pch)
{
    return (pch->Flags & DisplayObjectBase::Mask_JustLoaded) != 0;
}

// DocView::GetStyledText (pDocument +0x10) and StyledText::MayHaveUrl (RTFlags +0x40 bit 0), inlined in the exe.
SF_FORCEINLINE void* LeStyledText(Render::Text::DocView* pdoc)
{
    return *reinterpret_cast<void**>(reinterpret_cast<UByte*>(pdoc) + 0x10);
}
SF_FORCEINLINE bool LeMayHaveUrl(Render::Text::DocView* pdoc)
{
    return (*(reinterpret_cast<const UByte*>(LeStyledText(pdoc)) + 0x40) & 1) != 0;
}

} // namespace

// Sets each member of the initializer object on the clip.
struct InitObjectVisitor : public ObjectInterface::MemberVisitor
{
    Environment*       pEnv;
    InteractiveObject* pCharacter;

    InitObjectVisitor(Environment* penv, InteractiveObject* pch) : pEnv(penv), pCharacter(pch) {}
    virtual void Visit(const ASString& name, const Value& val, UByte flags)
    {
        // as the exe's copy (0x142993f60): no character, no script side
        static_cast<AvmCharacter*>(!pCharacter ? 0 : pCharacter->GetAvmIntObj())->SetMember(pEnv, name, val);
    }
};

// The members of the object in Arg(0) are set on this clip (the init object of attachMovie / duplicateMovieClip).
// @0x142961a40
void AvmSprite::InitObjectMembers(const FnCall& fn)
{
    Ptr<Sprite> psprite = fn.ThisPtr->ToSprite();
    if (!psprite)
        return;
    ObjectInterface*  pinitSource = fn.Arg(0).ToObjectInterface(fn.Env);
    InitObjectVisitor visitor(fn.Env, psprite);
    pinitSource->VisitMembers(visitor.pEnv->GetSC(), &visitor);
}

// ObjectInterface::ToAvmSprite (0x142990e70, sfr_as2_07), which the exe inlines here.
static SF_FORCEINLINE AvmSprite* MS2_ToAvmSprite(ObjectInterface* po)
{
    return po->GetObjectType() == ObjectInterface::Object_Sprite ? static_cast<AvmSprite*>(po) : 0;
}

// FunctionRefBase::SetLocalFrame (0x142981e70, sfr_as2_07) and the FunctionRef copy around it, which the exe inlines
// into the ToFunction copy here. Local copies: an inline redefinition of the member would emit a second COMDAT.
static SF_FORCEINLINE void MS2_SetLocalFrame(FunctionRefBase& r, LocalFrame* localFrame, bool weakRef)
{
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->Release();
    r.pLocalFrame = localFrame;
    if (weakRef)
        r.Flags |= FunctionRefBase::FuncRef_Weak;
    else
        r.Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (r.pLocalFrame && !(r.Flags & FunctionRefBase::FuncRef_Weak))
        r.pLocalFrame->AddRef();
}

static SF_FORCEINLINE FunctionRef MS2_CopyFuncRef(const FunctionRefBase& orig)
{
    FunctionRef r;
    r.Flags    = 0;
    r.Function = orig.Function;
    if (!(r.Flags & FunctionRefBase::FuncRef_Internal) && r.Function)
        r.Function->AddRef();
    r.pLocalFrame = 0;
    if (orig.pLocalFrame)
        MS2_SetLocalFrame(r, orig.pLocalFrame, (orig.Flags & FunctionRefBase::FuncRef_Weak) != 0);
    return r;
}

// Value::ToFunction as the SDK writes it (a switch); the exe inlines it here. The derived view reaches the protected
// ResolveFunctionName.
struct MS2_FuncValue : Value
{
    SF_FORCEINLINE FunctionRef ToFunctionSw(const Environment* penv) const
    {
        switch (T.Type)
        {
        case FUNCTIONNAME:
            return ResolveFunctionName(penv);
        case FUNCTION:
            return MS2_CopyFuncRef(V.FunctionValue);
        default:;
        }
        return FunctionRef();
    }
};

// This clip takes the prototype of the constructor in Arg(0).
// @0x142961d80
void AvmSprite::InitializeClassInstance(const FnCall& fn)
{
    AvmSprite* pscriptCh = MS2_ToAvmSprite(fn.ThisPtr);
    FunctionRef ctorFunc = static_cast<const MS2_FuncValue&>(fn.Arg(0)).ToFunctionSw(fn.Env);
    pscriptCh->SetProtoToPrototypeOf(ctorFunc.GetObjectPtr());
}

// A clip event: the clip shows its _up / _down / _over frame for a button event, then the event is queued when
// the clip has an onClipEvent handler or a method of the event's name (onKeyDown / onKeyUp only from SWF 6, and
// only while the clip has the keyboard focus).
// MS2-FUNCTIONAL: register allocation and block layout differ.
// @0x14296b490
bool AvmSprite::OnEvent(const EventId& id)
{
    Sprite*    psprite = GetSprite();
    SpriteDef* pdef    = (psprite->Flags & Sprite::Flags_SpriteDef) ? static_cast<SpriteDef*>(psprite->pDef.GetPtr()) : 0;
    if (pdef && (pdef->Flags & SpriteDef::Flags_HasSpecialFrames))
    {
        switch (id.Id)
        {
        case EventId::Event_Release:
        case EventId::Event_RollOver:
        case EventId::Event_DragOut:
            if (pdef->Flags & SpriteDef::Flags_Has_Frame_over)
                psprite->GotoLabeledFrame("_over", 0);
            break;
        case EventId::Event_Press:
            if (pdef->Flags & SpriteDef::Flags_Has_Frame_down)
                psprite->GotoLabeledFrame("_down", 0);
            break;
        case EventId::Event_ReleaseOutside:
        case EventId::Event_RollOut:
            if (pdef->Flags & SpriteDef::Flags_Has_Frame_up)
                psprite->GotoLabeledFrame("_up", 0);
            break;
        default:
            break;
        }
    }

    if (!LeHasClipEventHandler(this, id))
    {
        ASString methodName(GetASEnvironment()->GetSC()->GetBuiltin(EventId_GetFunctionNameBuiltinType(id)));
        if (methodName.IsEmpty())
            return false;
        bool    hasMethod = false;
        Value   method;
        Object* pobj = pMovieClipObj ? static_cast<Object*>(pMovieClipObj.GetPtr()) : Get__proto__();
        if (pobj && pobj->GetMemberRaw(Env.GetSC(), methodName, &method))
            hasMethod = true;
        if (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp)
        {
            if (Env.GetVersion() >= 6)
            {
                if (!LeIsKeyboardFocused(GetSprite()->GetMovieImpl(), GetSprite(), id.KeyboardIndex))
                    hasMethod = false;
            }
            else
                hasMethod = false;
        }
        if (!hasMethod)
            return false;
    }

    MovieRoot::ActionEntry* pe = GetAS2Root()->InsertEmptyAction(ActionPriority::AP_Frame);
    if (pe)
        LeSetEventAction(pe, GetSprite(), id);
    return true;
}

// The load event is queued (at frame priority when the clip has an onClipEvent(load), so that it comes before an
// unload right after attachMovie), frame 0's InitActions run, and a clip that is the hit area of another one is set
// again on it.
// MS2-FUNCTIONAL: the exe inlines ExecuteInitActionFrameTags(0); register allocation differs.
// @0x14296b860
void AvmSprite::OnEventLoad()
{
    ActionPriority::Priority prio = LeHasClipEventHandler(this, EventId(EventId::Event_Load))
                                        ? ActionPriority::AP_Frame : ActionPriority::AP_Load;
    LeSetEventAction(GetAS2Root()->InsertEmptyAction(prio), GetSprite(), EventId(EventId::Event_Load));
    GetSprite()->DisplayObjectBase::Flags |= DisplayObjectBase::Mask_JustLoaded;

    AvmSprite::ExecuteInitActionFrameTags(0);
    GetSprite()->DefaultOnEventLoad();

    UPInt n = LeHitAreas(GetAS2Root()).GetSize();
    for (unsigned i = 0; i < n; i++)
    {
        if (GetSprite() == LeHitAreas(GetAS2Root())[i]->GetHitArea())
            LeHitAreas(GetAS2Root())[i]->SetHitArea(GetSprite());
    }
}

// The clip leaves the hit area array. It may go at once only when mayRemove and it has no unload handler;
// otherwise its unload event is queued (after a load event, for a clip from attachMovie whose load has not run).
// @0x14296d140
bool AvmSprite::OnUnloading(bool mayRemove)
{
    int haIndex = LeHitAreaIndex(this);
    if (haIndex > -1)
        LeHitAreas(GetAS2Root()).RemoveAt(haIndex);

    if (mayRemove && HasEventHandler(EventId(EventId::Event_Unload)))
        mayRemove = false;
    if (!mayRemove)
    {
        if (LeIsJustLoaded(GetSprite()) && !GetSprite()->IsAcceptAnimMovesFlagSet())
        {
            MovieRoot::ActionEntry* pe = GetAS2Root()->InsertEmptyAction();
            if (pe)
                LeSetEventAction(pe, pDispObj, EventId::Event_Load);
        }
        MovieRoot::ActionEntry* pe = GetAS2Root()->InsertEmptyAction();
        if (pe)
            LeSetEventAction(pe, pDispObj, EventId::Event_Unload);
    }
    pDispObj->RemoveFromPlayList();
    return mayRemove;
}

// pnewChar takes the place, the properties and the name of poldChar, which gets its unload event first. False
// when poldChar is not (or no longer, after the queued actions ran) on the display list.
// @0x14297d330
bool AvmSprite::ReplaceChildCharacter(InteractiveObject* poldChar, InteractiveObject* pnewChar)
{
    poldChar->SetMask(0);
    if (poldChar->HasIndirectTransform())
        GetSprite()->GetMovieImpl()->RemoveTopmostLevelCharacter(poldChar);

    UPInt index = GetSprite()->mDisplayList.GetDisplayIndex(poldChar->Depth);
    if (index == SF_MAX_UPINT)
        return false;

    pnewChar->CopyPhysicalProperties(poldChar);
    if (pnewChar->IsSprite() && poldChar->IsSprite())
    {
        Sprite* pnew = static_cast<Sprite*>(pnewChar);
        pnew->Flags = static_cast<Sprite*>(poldChar)->IsLockRoot() ? (pnew->Flags | Sprite::Flags_LockRoot)
                                                                    : (pnew->Flags & ~Sprite::Flags_LockRoot);
    }

    poldChar->OnUnloading();
    GetAS2Root()->DoActions();
    pnewChar->MoveNameHandle(poldChar);

    index = GetSprite()->mDisplayList.GetDisplayIndex(poldChar->Depth);
    if (index == SF_MAX_UPINT)
        return false;
    GetSprite()->mDisplayList.ReplaceDisplayObjectAtIndex(GetSprite(), index, pnewChar);
    return true;
}

// The text changed: onChanged goes to the field's listeners with the field (and, with the extensions on, the
// controller that has the focus on it).
// @0x142969080
void AvmTextField::NotifyChanged()
{
    Environment* penv  = GetASEnvironment();
    int          nargs = 1;
    if (penv->CheckExtensions())
    {
        const int controllerIdx = *reinterpret_cast<const int*>(reinterpret_cast<const UByte*>(pDispObj) + 0x128);
        if (controllerIdx != -1)
        {
            penv->Push(controllerIdx);
            nargs = 2;
        }
    }
    penv->Push(Value(pDispObj));
    BroadcastMessageLocal(penv, static_cast<ObjectInterface*>(static_cast<AvmCharacter*>(this)),
                          penv->CreateConstString("onChanged"), nargs, penv->GetTopIndex());
    penv->Stack.Pop(nargs);
}

// A click on an "asfunction:name,arg" link calls the method name (with the text after the comma) on the field's
// parent clip, or on _level0 when the parent is not a sprite.
// MS2-FUNCTIONAL: register allocation and block layout differ.
// @0x14296c8c0
bool AvmTextField::OnMouseEvent(const EventId& event)
{
    if (event.Id != EventId::Event_Release)
        return false;
    TextField* ptf = reinterpret_cast<TextField*>(pDispObj);
    if (ptf->IsHtml() && LeMayHaveUrl(ptf->GetDocument()))
    {
        Render::PointF p;
        if (ptf->IsUrlUnderMouseCursor(event.MouseIndex, &p))
        {
            UPInt pos = ptf->GetDocument()->GetCharIndexAtPoint(p.x, p.y);
            if (pos != SF_MAX_UPINT)
            {
                const Render::Text::TextFormat* ptextFmt;
                if (reinterpret_cast<Render::Text::StyledText*>(LeStyledText(ptf->GetDocument()))->GetTextAndParagraphFormat(&ptextFmt, NULL, pos) && ptextFmt->IsUrlSet())
                {
                    const String& url    = ptextFmt->GetUrl();
                    MovieImpl*    pmovie = pDispObj->GetMovieImpl();
                    if (pmovie && String::CompareNoCase(url.ToCStr(), "asfunction:", 11) == 0)
                    {
                        const char* pstr   = url.ToCStr() + 11;
                        const char* pcomma = strchr(pstr, ',');
                        String      funcName;
                        GFx::Value  param;
                        unsigned    nargs = 0;
                        if (pcomma)
                        {
                            funcName.AppendString(pstr, pcomma - pstr);
                            param.SetString(pcomma + 1);
                            nargs = 1;
                        }
                        else
                            funcName = pstr;
                        GFx::Value             result;
                        Ptr<InteractiveObject> pparent = pDispObj->GetParent();
                        MovieRoot*             proot   = static_cast<MovieRoot*>(pmovie->pASMovieRoot);
                        if (pparent && pparent->IsSprite())
                            proot->Invoke(pparent, funcName.ToCStr(), &result, &param, nargs);
                        else
                            proot->Invoke(funcName.ToCStr(), &result, &param, nargs);
                    }
                }
            }
        }
    }
    return true;
}

// The field scrolled: onScroller (with the field) goes to its listeners from the frame actions, queued once.
// MS2-FUNCTIONAL: the exe compares against a whole local ActionEntry; register allocation differs.
// @0x14296ce90
void AvmTextField::OnScroll()
{
    Environment*       penv = GetASEnvironment();
    InteractiveObject* pch  = pDispObj;
    Ptr<InteractiveObject> holder(pch);
    for (MovieRoot::ActionEntry* pe = GetAS2Root()->GetActionQueue().Levels[ActionPriority::AP_Frame].pActionRoot; pe;
         pe = pe->pNextEntry)
    {
        if (pe->Type == MovieRoot::ActionEntry::Entry_CFunction && !pe->pActionBuffer && pe->pCharacter == pch &&
            pe->CFunction == AvmTextField::BroadcastMessage && !pe->Function.Function && pe->mEventId.Id == 0)
            return;
    }
    Array<Value> params;
    params.PushBack(Value(penv->CreateConstString("onScroller")));
    params.PushBack(Value(pch));
    MovieRoot::ActionEntry* pe = GetAS2Root()->InsertEmptyAction(ActionPriority::AP_Frame);
    pe->Type       = MovieRoot::ActionEntry::Entry_CFunction;
    pe->pCharacter = pch;
    pe->pActionBuffer = 0;
    pe->CFunction      = AvmTextField::BroadcastMessage;
    pe->FunctionParams = params;
}

// The character got or lost the focus: its onSetFocus/onKillFocus handler runs with the other character (null
// without one), the controller index first with the extensions on.
// MS2-FUNCTIONAL: the this of the call is passed as the object, not as Value(pDispObj); registers differ.
// @0x14296bd60
void AvmCharacter::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                           unsigned controllerIdx, FocusMovedType fmt)
{
    SF_UNUSED(fmt);
    Value        method;
    Environment* penv = GetASEnvironment();
    if (!penv)
        return;
    ASString eventName(penv->GetBuiltin(event == InteractiveObject::SetFocus ? ASBuiltin_onSetFocus
                                                                               : ASBuiltin_onKillFocus));
    if (!GetMemberRaw(penv->GetSC(), eventName, &method))
        return;
    FunctionRef func = method.IsFunctionObject() ? method.ToFunction(penv) : FunctionRef();
    if (func.Function)
    {
        int nargs = 1;
        if (penv->CheckExtensions())
        {
            penv->Push(Value(Number(controllerIdx)));
            nargs = 2;
        }
        if (oldOrNewFocusCh)
            penv->Push(Value(oldOrNewFocusCh));
        else
            penv->Push(Value(Value::NULLTYPE));
        Value result;
        // The exe builds the call from Value(pDispObj) (the FnCall value constructor), which resolves to this.
        func.Invoke(FnCall(&result, static_cast<ObjectInterface*>(this), penv, nargs, penv->GetTopIndex()));
        penv->Drop(nargs);
    }
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7InitObjectVisitor@AS2@GFx@Scaleform@@6B@ 0x143221988
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7SetFocusInvokeCallback@AS2@GFx@Scaleform@@6B@ 0x143221850
