// Recovered Scaleform 4.1.18 GFx: input and player events passed to Movie::HandleEvent and to the user event
// handler. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Only the base event, the mouse cursor event and the user event handler are recovered so far.
#ifndef MS2_SF_GFX_EVENT_H
#define MS2_SF_GFX_EVENT_H

#include "gfx_state.h"

namespace Scaleform { namespace GFx {

class Movie;

// 0x08 bytes.
class Event : public NewOverrideBase<Stat_Default_Mem>
{
public:
    enum EventType
    {
        Unknown,
        MouseMove,
        MouseDown,
        MouseUp,
        MouseWheel,
        KeyDown,
        KeyUp,
        SceneResize,
        SetFocus,
        KillFocus,
        TouchBegin,
        TouchEnd,
        TouchMove,
        TouchTap,
        GestureBegin,
        Gesture,
        GestureEnd,
        GestureSimple,
        GamePadAnalog,
        OrientationChanged,
        AppLifecycle,
        // Requests from scripts to the application.
        DoShowMouse,
        DoHideMouse,
        DoSetMouseCursor,
        Char
    };

    EventType Type;      // +0x00
    UByte     Modifiers; // +0x04 KeyModifiers

    Event(EventType eventType = Unknown) : Modifiers(0) { Type = eventType; }
};

// Show / hide / shape requests for the cursor of one mouse. 0x10 bytes.
class MouseCursorEvent : public Event
{
public:
    enum CursorShapeType
    {
        ARROW,
        HAND,
        IBEAM,
        BUTTON
    };

    unsigned mCursorShape; // +0x08
    unsigned MouseIndex;   // +0x0c

    MouseCursorEvent(EventType eventType, unsigned mouseIndex)
        : Event(eventType), mCursorShape(ARROW), MouseIndex(mouseIndex) {}
    // A DoSetMouseCursor request.
    MouseCursorEvent(CursorShapeType cursorShape, unsigned mouseIndex)
        : Event(DoSetMouseCursor), mCursorShape(cursorShape), MouseIndex(mouseIndex) {}
};

// Application hook for the requests of the scripts (cursor, ...).
class UserEventHandler : public State
{
public:
    virtual void HandleEvent(Movie* pmovie, const Event& event) = 0;
};

}} // namespace Scaleform::GFx

#endif
