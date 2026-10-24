// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the button events of a mouse (press, release, drag, roll over / out) from its state of the frame.
// MS2-UNIT: sfr_as2_05u
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429488b0-0x142948eae .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieImpl::GetMouseState: the states of the four mice (the movie is the layout mirror here).
inline MouseState* GmMouseState(MovieImpl* pmovie, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return 0;
    return reinterpret_cast<MouseState*>(reinterpret_cast<UByte*>(pmovie) + 0x1260) + mouseIndex;
}

// InteractiveObject::IncrementRollOverCnt: the count before.
inline UByte GmIncrementRollOverCnt(InteractiveObject* pch)
{
    return pch->RollOverCnt++;
}

// InteractiveObject::DecrementRollOverCnt: the count after, 0xff when it was already 0.
inline UByte GmDecrementRollOverCnt(InteractiveObject* pch)
{
    return (pch->RollOverCnt == 0) ? UByte(0xff) : --pch->RollOverCnt;
}

// A button event (ButtonEventId) of the mouse with its roll-over count and button.
inline EventId GmButtonEvent(UInt32 id, unsigned mouseIndex, UByte rollOverCnt = 0, UByte buttonIdx = 0)
{
    EventId ev(id);
    ev.ButtonId    = buttonIdx;
    ev.RollOverCnt = rollOverCnt;
    ev.MouseIndex  = SByte(mouseIndex);
    return ev;
}

} // namespace

// The buttons that changed give press / release (outside), the held ones drag over / out (and the trackAsMenu
// transfer); with no button down before, a change of the entity under the mouse gives roll out / over. With the
// GFx extensions all 16 buttons count, the others as Aux events.
// MS2-FUNCTIONAL: the roll out / over test takes all the previous buttons (the exe compares the whole state to 0);
// the mouse state lookup, the WeakPtr locks and the level list search are inlined in the exe
// @0x1429488b0
void MovieRoot::GenerateMouseEvents(unsigned mouseIndex)
{
    Environment* penv       = ToAvmCharacter(GetLevelMovie(0))->GetASEnvironment();
    UByte        checkCount = penv->CheckExtensions() ? 16 : 1;

    MouseState& ms = *GmMouseState(pMovieImpl, mouseIndex);
    Ptr<InteractiveObject> ActiveEntity  = ms.GetActiveEntity();
    Ptr<InteractiveObject> TopmostEntity = ms.GetTopmostEntity();

    if (ActiveEntity && ActiveEntity->IsUnloaded())
        ActiveEntity = NULL;
    if (TopmostEntity && TopmostEntity->IsUnloaded())
        TopmostEntity = NULL;
    Ptr<InteractiveObject> newActiveEntity = ActiveEntity;

    unsigned changeMask      = ms.GetPrevButtonsState() ^ ms.GetButtonsState();
    bool     suppressRollOut = false;
    bool     miel            = ms.IsMouseInsideEntityLast();
    for (UByte buttonIdx = 0; buttonIdx < checkCount; ++buttonIdx)
    {
        bool     genAuxEvent = buttonIdx != 0;
        unsigned buttonMask  = 1u << buttonIdx;

        if (((changeMask >> buttonIdx) & 1) != 0)
        {
            // down before, up now: release, or release outside
            if ((ms.GetPrevButtonsState() & buttonMask) && (ms.GetButtonsState() & buttonMask) == 0 && ActiveEntity)
            {
                if (ms.IsMouseInsideEntityLast())
                {
                    ActiveEntity->OnMouseEvent(GmButtonEvent(
                        genAuxEvent ? EventId::Event_ReleaseAux : EventId::Event_Release, mouseIndex, 0, buttonIdx));
                }
                else
                {
                    if (!ActiveEntity->GetTrackAsMenu())
                        ActiveEntity->OnMouseEvent(GmButtonEvent(
                            genAuxEvent ? EventId::Event_ReleaseOutsideAux : EventId::Event_ReleaseOutside,
                            mouseIndex, 0, buttonIdx));
                    // no roll out below
                    suppressRollOut = true;
                }
            }
            // up before, down now: press
            if ((ms.GetPrevButtonsState() & buttonMask) == 0 && (ms.GetButtonsState() & buttonMask))
            {
                newActiveEntity = TopmostEntity;
                if (newActiveEntity)
                    newActiveEntity->OnMouseEvent(GmButtonEvent(
                        genAuxEvent ? EventId::Event_PressAux : EventId::Event_Press, mouseIndex, 0, buttonIdx));
                miel = true;
            }
        }
        else if (ms.GetButtonsState() & buttonMask)
        {
            // held: drag over / out
            if (!ms.IsMouseInsideEntityLast())
            {
                if (TopmostEntity == ActiveEntity)
                {
                    if (ActiveEntity)
                        ActiveEntity->OnMouseEvent(GmButtonEvent(
                            genAuxEvent ? EventId::Event_DragOverAux : EventId::Event_DragOver, mouseIndex,
                            GmIncrementRollOverCnt(ActiveEntity), buttonIdx));
                    miel = true;
                }
            }
            else if (TopmostEntity != ActiveEntity)
            {
                if (ActiveEntity)
                    ActiveEntity->OnMouseEvent(GmButtonEvent(
                        genAuxEvent ? EventId::Event_DragOutAux : EventId::Event_DragOut, mouseIndex,
                        GmDecrementRollOverCnt(ActiveEntity), buttonIdx));
                miel = false;
            }
            // trackAsMenu: the drag goes over to the menu item under the mouse
            if (!ActiveEntity || ActiveEntity->GetTrackAsMenu())
            {
                if (TopmostEntity && TopmostEntity != ActiveEntity && TopmostEntity->GetTrackAsMenu())
                {
                    newActiveEntity = TopmostEntity;
                    newActiveEntity->OnMouseEvent(GmButtonEvent(
                        genAuxEvent ? EventId::Event_DragOverAux : EventId::Event_DragOver, mouseIndex,
                        GmIncrementRollOverCnt(newActiveEntity), buttonIdx));
                    miel = true;
                }
            }
        }
    }

    // no button down before: the entity under the mouse becomes the active one
    if (ms.GetPrevButtonsState() == 0 && TopmostEntity != ActiveEntity)
    {
        if (!suppressRollOut && ActiveEntity)
            ActiveEntity->OnMouseEvent(
                GmButtonEvent(EventId::Event_RollOut, mouseIndex, GmDecrementRollOverCnt(ActiveEntity)));

        newActiveEntity = TopmostEntity;
        if (newActiveEntity)
            newActiveEntity->OnMouseEvent(
                GmButtonEvent(EventId::Event_RollOver, mouseIndex, GmIncrementRollOverCnt(newActiveEntity)));
        miel = true;
    }

    ms.SetMouseInsideEntityLast(miel);
    ms.SetActiveEntity(newActiveEntity);
}

}}} // namespace Scaleform::GFx::AS2
