// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 button events of sfr_as2_06
// (gap recovery, lane sfr24): the mouse and key events of a button queue its condition actions and its handler.
// MS2-UNIT: sfr_as2_06f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14296b2b0-0x14296b470 .text$mn
// MS2-RANGE: 0x14296c430-0x14296c8c0 .text$mn
// MS2-RANGE: 0x142969250-0x14296944f .text$mn
// MS2-RANGE: 0x142961540-0x14296170d .text$mn
// MS2-RANGE: 0x1429694e0-0x1429696c1 .text$mn
// MS2-RANGE: 0x14296a0a0-0x14296a2f8 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The script side of a button (partial local copy; the other units carry their own). The AvmButtonBase
// subobject is at +0x30.
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual bool OnMouseEvent(const EventId& event);
    virtual bool OnButtonKeyEvent(const EventId& id, int* pkeyMask);
};

namespace {

// MouseState::IsMouseMoved (the MouseMoved bit of the flags byte at +0x4c).
SF_FORCEINLINE bool BeMouseMoved(const MouseState& ms)
{
    return (reinterpret_cast<const UByte*>(&ms)[0x4c] & 8) != 0;
}

// The AS2 button action (ButtonActionBase of the AS2 support): the conditions word (the mouse transition bits,
// the key code in bits 9..15) and the action blocks run on it.
struct BeButtonActionView
{
    void*                                                     pVTable;    // +0x00
    int                                                       RefCount;   // +0x08
    UInt32                                                    Conditions; // +0x10
    ArrayLH<Ptr<ActionBufferData>, StatMD_ASBinaryData_Mem>   Actions;    // +0x18
};

// Data bytes of an action block (protected in ActionBufferData).
SF_FORCEINLINE const UByte* BeBufferBytes(const ActionBufferData* pdata)
{
    return *reinterpret_cast<UByte* const*>(reinterpret_cast<const UByte*>(pdata) + 0x10);
}

// The handler of the event is queued as an event action on pch.
SF_FORCEINLINE void BeQueueEvent(MovieRoot* proot, InteractiveObject* pch, const EventId& event)
{
    MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Frame);
    if (pe)
    {
        EventId evt      = event;
        pe->Type          = MovieRoot::ActionEntry::Entry_Event;
        pe->pCharacter    = pch;
        pe->pActionBuffer = 0;
        pe->mEventId      = evt;
    }
}

} // namespace

// A key of the button: its keyPress-like handler (onKeyDown / onKeyUp) runs when the button has the keyboard focus.
// MS2-FUNCTIONAL: register allocation differs.
// @0x14296b2b0
bool AvmButton::OnButtonKeyEvent(const EventId& id, int* pkeyMask)
{
    SF_UNUSED(pkeyMask);
    Environment* penv  = GetASEnvironment();
    ASString     methodName(penv->GetBuiltin(EventId_GetFunctionNameBuiltinType(id)));
    MovieImpl*   proot = pDispObj->GetMovieImpl();
    if (methodName.GetSize() > 0)
    {
        Value method;
        if ((id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp) &&
            GetMemberRaw(penv->GetSC(), methodName, &method) && penv->GetVersion() >= 6 &&
            proot->IsKeyboardFocused(pDispObj, id.KeyboardIndex))
            BeQueueEvent(GetAS2Root(), pDispObj, id);
    }
    return true;
}

// A mouse transition of the button: the parent clip runs the button actions whose conditions match it (or the key
// of a keyPress), then the button's own handler of the event is queued. True when either was found.
// MS2-FUNCTIONAL: register allocation differs.
// @0x14296c430
bool AvmButton::OnMouseEvent(const EventId& event)
{
    bool handlerFound = false;
    if (!event.RollOverCnt)
    {
        int c = 0, kc = 0;
        if (event.Id == EventId::Event_RollOver)
            c = 0x01; // idle to over up
        else if (event.Id == EventId::Event_RollOut)
            c = 0x02; // over up to idle
        else if (event.Id == EventId::Event_Press)
            c = 0x04; // over up to over down
        else if (event.Id == EventId::Event_Release)
            c = 0x08; // over down to over up
        else if (event.Id == EventId::Event_DragOut)
            c = 0x10; // over down to out down
        else if (event.Id == EventId::Event_DragOver)
            c = 0x20; // out down to over down
        else if (event.Id == EventId::Event_ReleaseOutside)
            c = 0x40; // out down to idle
        else if (event.Id == EventId::Event_KeyPress)
            kc = event.ConvertToButtonKeyCode();

        Button*            pbutton = static_cast<Button*>(pDispObj);
        InteractiveObject* pparent = pbutton->GetParent();
        InteractiveObject* psprite = (pparent && pparent->IsSprite()) ? pparent : 0;
        if (psprite)
        {
            ButtonDef* pdef = pbutton->GetButtonDef();
            for (UPInt i = 0, n = pdef->GetButtonActionsCount(); i < n; ++i)
            {
                const BeButtonActionView& ba =
                    *reinterpret_cast<const BeButtonActionView*>(pdef->GetButtonAction(i));
                if ((ba.Conditions & c) || (kc > 0 && ((ba.Conditions >> 9) & 0x7f) == (unsigned)kc))
                {
                    AvmCharacter* pavmParent = AS2::ToAvmCharacter(psprite);
                    Environment*  penv       = pavmParent->GetASEnvironment();
                    const UPInt   nactions   = ba.Actions.GetSize();
                    for (UPInt j = 0; j < nactions; ++j)
                    {
                        ActionBufferData* pdata = ba.Actions[j];
                        if (pdata->GetLength() >= 1 && *BeBufferBytes(pdata))
                        {
                            Ptr<ActionBuffer> pbuff =
                                *new (penv->GetSC()->GetHeap()) ActionBuffer(penv->GetSC(), pdata);
                            MovieRoot::ActionEntry* pe =
                                pavmParent->GetAS2Root()->InsertEmptyAction(ActionPriority::AP_Frame);
                            if (pe)
                            {
                                pe->Type          = MovieRoot::ActionEntry::Entry_Buffer;
                                pe->pCharacter    = pavmParent->GetDispObj();
                                pe->pActionBuffer = pbuff;
                                pe->mEventId.Id   = 0;
                            }
                        }
                    }
                    handlerFound = handlerFound || nactions > 0;
                }
            }
        }
    }

    // The button's own handler of the event (onPress, onRelease, ...).
    Environment* penv = GetASEnvironment();
    if (penv)
    {
        ASString methodName(penv->GetBuiltin(EventId_GetFunctionNameBuiltinType(event)));
        if (methodName.GetSize() > 0)
        {
            Value method;
            if (GetMemberRaw(penv->GetSC(), methodName, &method))
            {
                handlerFound = true;
                BeQueueEvent(GetAS2Root(), pDispObj, event);
            }
        }
    }
    return handlerFound;
}

// The key of a controller goes into its state, then the handler (onKeyDown/onKeyUp) is broadcast to the Key
// listeners in _level0's environment, with the controller index when the extensions are on.
// MS2-FUNCTIONAL: the exe inlines MovieRoot::GetLevelMovie(0) and AsBroadcaster::BroadcastMessage.
// @0x142969250
void KeyCtorFunction::NotifyListeners(InteractiveObject*, const EventId& evt)
{
    States[evt.KeyboardIndex].LastKeyCode   = evt.KeyCode;
    States[evt.KeyboardIndex].LastAsciiCode = evt.AsciiCode;
    States[evt.KeyboardIndex].LastWcharCode = evt.WcharCode;

    ASString handlerName(static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(
        EventId_GetFunctionNameBuiltinType(EventId(evt.Id))));
    if (!pMovieRoot)
        return;
    MovieImpl*         pmovie = static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetMovieImpl();
    InteractiveObject* plevel0 = 0;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == 0)
        {
            plevel0 = pmovie->pMovieLevels[i].pSprite;
            break;
        }
    }
    if (!plevel0)
        return;
    Environment* penv = AS2::ToAvmCharacter(plevel0)->GetASEnvironment();
    if (!penv)
        return;
    int nargs = 0;
    if (penv->CheckExtensions())
    {
        penv->Push(Value(int(evt.KeyboardIndex)));
        nargs = 1;
    }
    AsBroadcaster::BroadcastMessage(penv, static_cast<ObjectInterface*>(this), handlerName, nargs,
                                    penv->GetTopIndex());
    penv->Drop(nargs);
}

// The movie's global context, the container node every level's tree goes under, and _level0 (made from the
// movie's own timeline), with the aux classes registered and the sticky variables set on it.
// MS2-FUNCTIONAL: the call arguments of CreateCharacterInstance are stored in another order.
// @0x142961540
bool MovieRoot::Init(MovieDefImpl* pmovieDef)
{
    pGlobalContext = *new (pMovieImpl->GetMovieHeap()) GlobalContext(pMovieImpl);

    Ptr<Render::TreeContainer>& topNode = *reinterpret_cast<Ptr<Render::TreeContainer>*>(Unrecovered_28);
    topNode = *reinterpret_cast<Render::ContextImpl::Context*>(pMovieImpl->RenderContext)
                   ->CreateEntry<Render::TreeContainer>();
    static_cast<Render::TreeContainer*>(pMovieImpl->pRenderRoot)->Insert(0, topNode);

    // CreateSprite inline.
    CharacterCreateInfo ccinfo;
    ccinfo.pCharDef     = reinterpret_cast<CharacterDef*>(pmovieDef->GetDataDef());
    ccinfo.pBindDefImpl = pmovieDef;
    ccinfo.pResource    = 0;
    Ptr<Sprite> prootMovie = *static_cast<Sprite*>(
        pASSupport->CreateCharacterInstance(pMovieImpl, ccinfo, 0, ResourceId(), CharacterDef::Sprite));
    prootMovie->SetLoadedSeparately(true);
    if (!prootMovie)
        return false;

    AvmSprite::FromSprite(prootMovie)->SetLevel(0);
    pMovieImpl->SetLevelMovie(0, prootMovie);
    RegisterAuxASClasses();
    ResolveStickyVariables(prootMovie);
    prootMovie->SetFOV(55.0);
    return true;
}

// A mouse move, wheel or button change goes to the Mouse class's listeners (in _level0's environment); a wheel or
// button event only when the topmost character under the mouse is an AS2 one. Without the extensions only the
// first button is reported.
// MS2-FUNCTIONAL: register allocation and block layout differ.
// @0x1429694e0
void MovieRoot::NotifyMouseEvent(const GFx::InputEventsQueueEntry* qe, const GFx::MouseState& ms, int mi)
{
    InteractiveObject* plevel0 = 0;
    for (unsigned i = 0; i < pMovieImpl->MovieLevelsSize; i++)
    {
        if (pMovieImpl->pMovieLevels[i].Level == 0)
        {
            plevel0 = pMovieImpl->pMovieLevels[i].pSprite;
            break;
        }
    }
    Environment* penv =
        static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(plevel0->GetAvmObjImpl()))->GetASEnvironment();
    const InputEventsQueueEntry::MouseEntry& me = qe->GetMouseEntry();
    if (!pMouseListener || pMouseListener->IsEmpty() ||
        !(BeMouseMoved(ms) || me.IsButtonsStateChanged() || me.IsMouseWheel()))
        return;

    bool extensions = penv->CheckExtensions();
    if (BeMouseMoved(ms))
        pMouseListener->OnMouseMove(penv, mi);
    if (!me.IsMouseWheel() && !me.IsButtonsStateChanged())
        return;

    Ptr<InteractiveObject> ptopMouseCharacter = pMovieImpl->GetTopMostEntity(me.GetPosition(), mi, true);
    if (ptopMouseCharacter && ptopMouseCharacter->GetAVMVersion() != 1)
        return;
    if (me.IsMouseWheel())
        pMouseListener->OnMouseWheel(penv, mi, me.WheelScrollDelta, ptopMouseCharacter);
    if (me.IsButtonsStateChanged())
    {
        unsigned buttonId = 1;
        for (UInt16 mask = 1; mask; mask <<= 1, ++buttonId)
        {
            if (me.ButtonsState & mask)
            {
                if (!(me.Flags & (InputEventsQueueEntry::MouseButton_Move | InputEventsQueueEntry::MouseButton_Released)) &&
                    me.ButtonsState)
                    pMouseListener->OnMouseDown(penv, mi, buttonId, ptopMouseCharacter);
                else
                    pMouseListener->OnMouseUp(penv, mi, buttonId, ptopMouseCharacter);
            }
            if (!extensions)
                break;
        }
    }
}

// Records the byte counts of ptarget's movie (by its absolute path) and broadcasts onLoadProgress(target, loaded,
// total) to the loader's listeners.
// MS2-FUNCTIONAL: the exe inlines AsBroadcaster::BroadcastMessage (a BroadcastMessageWithCallback call).
// @0x14296a0a0
void MovieClipLoader::NotifyOnLoadProgress(Environment* penv, InteractiveObject* ptarget, int loadedBytes,
                                           int totalBytes)
{
    if (ptarget)
    {
        String path;
        ptarget->GetAbsolutePath(&path);
        ProgressDesc* pprogress = ProgressInfo.Get(path);
        if (pprogress)
        {
            pprogress->LoadedBytes = loadedBytes;
            pprogress->TotalBytes  = totalBytes;
        }
        else
            ProgressInfo.Add(path, ProgressDesc(loadedBytes, totalBytes));
    }
    penv->Push(Value(totalBytes));
    penv->Push(Value(loadedBytes));
    penv->Push(Value(ptarget));
    ASString eventName = penv->CreateConstString("onLoadProgress");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 3, penv->GetTopIndex());
    penv->Drop(3);
}

}}} // namespace Scaleform::GFx::AS2
