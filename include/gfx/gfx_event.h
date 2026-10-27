// Recovered Scaleform 4.1.18 GFx: input and player events passed to Movie::HandleEvent and to the user event
// handler. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Recovered so far: the base event, the mouse / key / char / focus / IME input events, the mouse cursor event and
// the user event handler.
#ifndef MS2_SF_GFX_EVENT_H
#define MS2_SF_GFX_EVENT_H

#include "gfx_state.h"
#include "../kernel/sf_keycodes.h"

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
        Char,
        IME
    };

    EventType Type;      // +0x00
    KeyModifiers Modifiers; // +0x04

    // /Od callers keep these as COMDATs (gfxmovieugc 0x14127df60): Modifiers is default-constructed, then both are stored.
    Event(EventType eventType = Unknown) { Type = eventType; }
    Event(EventType eventType, KeyModifiers mods) { Type = eventType; Modifiers = mods; }
};

// A mouse move, press, release or wheel turn in viewport pixels (HandleEvent maps it onto the stage). 0x1c bytes.
class MouseEvent : public Event
{
public:
    float    x;           // +0x08
    float    y;           // +0x0c
    float    ScrollDelta; // +0x10 wheel lines
    unsigned Button;      // +0x14 button number (0 left)
    unsigned MouseIndex;  // +0x18

    MouseEvent() : Event(), x(0), y(0), ScrollDelta(0), Button(0), MouseIndex(0) {}
    MouseEvent(EventType eventType, unsigned button, float xpos, float ypos, float scrollVal = 0,
               unsigned mouseIndex = 0)
        : Event(eventType)
    {
        Button = button;
        x = xpos;
        y = ypos;
        ScrollDelta = scrollVal;
        MouseIndex = mouseIndex;
    }
};

// A key going down or up; a key down with a printable character also types it. 0x18 bytes.
class KeyEvent : public Event
{
public:
    unsigned KeyCode;       // +0x08 Key::Code
    UByte    AsciiCode;     // +0x0c
    UInt32   WcharCode;     // +0x10
    UInt8    KeyboardIndex; // +0x14

    KeyEvent(EventType eventType = Unknown, Key::Code code = Key::VoidSymbol, UByte asciiCode = 0, UInt32 wcharCode = 0,
             KeyModifiers mods = KeyModifiers(), UInt8 keyboardIndex = 0)
        : Event(eventType, mods), KeyCode(code), AsciiCode(asciiCode), WcharCode(wcharCode), KeyboardIndex(keyboardIndex)
    {
    }
};

// A typed character. 0x10 bytes.
class CharEvent : public Event
{
public:
    UInt32 WcharCode;     // +0x08
    UInt8  KeyboardIndex; // +0x0c

    CharEvent(UInt32 wcharCode, UInt8 keyboardIndex = 0)
        : Event(Char), WcharCode(wcharCode), KeyboardIndex(keyboardIndex) {}
};

// The movie gains or loses the focus; a focus gain carries the toggle keys of each keyboard. 0x0c bytes.
class SetFocusEvent : public Event
{
public:
    KeyModifiers KeysStates[4]; // +0x08 one per keyboard, unset ones are skipped

    SetFocusEvent(EventType eventType = SetFocus) : Event(eventType) {}
    SetFocusEvent(KeyModifiers mods) : Event(SetFocus, mods) {}   // 0x14127dfb0
};

// An IME window message handed to the IME manager (the platform event classes derive from it).
class IMEEvent : public Event
{
public:
    enum IMEEventType
    {
        IME_Default,
        IME_PreProcessKeyboard,
    };

    unsigned IMEEvtType; // +0x08

    IMEEvent(unsigned imeEvtType = 0) : Event(IME), IMEEvtType(imeEvtType) {}
    IMEEvent(IMEEventType imeEvtType) : Event(IME), IMEEvtType(imeEvtType) {}   // the game's COMDAT takes the enum
};

// A Win32 IME window message (GFxMovieEventHandler vfunc_15 / vfunc_37). 0x30 bytes.
class IMEWin32Event : public IMEEvent
{
public:
    unsigned Message; // +0x0c
    UPInt    WParam;  // +0x10
    UPInt    LParam;  // +0x18
    UPInt    Wnd;     // +0x20
    int      Options; // +0x28

    IMEWin32Event(IMEEventType imeEvtType, UPInt wnd, unsigned message, UPInt wParam, UPInt lParam, int options = 0)
        : IMEEvent(imeEvtType), Message(message), WParam(wParam), LParam(lParam), Wnd(wnd), Options(options) {}
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
