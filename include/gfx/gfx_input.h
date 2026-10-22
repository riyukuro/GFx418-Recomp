// Recovered Scaleform 4.1.18 GFx: the input event queue a movie fills from Movie::HandleEvent and drains once per
// Advance, and the per-mouse state (bodies in sfr_gfx_06f, GFx_Input).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout is the exe's: a queue entry is 0x28 bytes (type + a 0x24-byte union), the queue is a ring of 100 entries
// followed by StartPos +0xfa0, UsedEntries +0xfa8, the last mouse positions +0xfb0 and their mask +0xfd0;
// MouseState is 0x50 bytes.
#ifndef MS2_SF_GFX_INPUT_H
#define MS2_SF_GFX_INPUT_H

#include "../kernel/sf_types.h"
#include "../kernel/sf_refcount.h"
#include "../kernel/sf_array.h"
#include "../render/render_types2d.h"

namespace Scaleform {
// The sized byte types gfx_textclipboard.h uses (repeated typedefs of the kernel's).
typedef unsigned char UInt8;
typedef signed char   SInt8;
}

#include "gfx_textclipboard.h"

namespace Scaleform { namespace GFx {

class InteractiveObject;

// Mouse events of up to four mice are tracked.
enum { MaxMiceSupported = 4 };

// One queued input event: a mouse button / move / wheel or a key event.
class InputEventsQueueEntry
{
public:
    typedef UInt16 ButtonsStateType;

    enum MouseButtonMask
    {
        MouseButton_Left    = 1,
        MouseButton_Right   = 2,
        MouseButton_Middle  = 4,
        MouseButton_AllMask = 0xFFFF
    };
    // Entry flags (MouseEntry::Flags).
    enum MouseButtonFlags
    {
        MouseButton_Wheel    = 0x20,
        MouseButton_Move     = 0x40,
        MouseButton_Released = 0x80
    };
    enum QueueEntryType
    {
        QE_Mouse,
        QE_Key
    };

    struct MouseEntry
    {
        float            PosX, PosY;        // +0x04 twips
        ButtonsStateType ButtonsState;      // +0x0c the buttons the event is about
        SInt8            WheelScrollDelta;  // +0x0e
        UInt8            Flags;             // +0x0f MouseButtonFlags
        UInt8            MouseIndex;        // +0x10

        Render::PointF GetPosition() const { return Render::PointF(PosX, PosY); }
        bool IsButtonsStateChanged() const { return ButtonsState != 0; }
        bool IsAnyButtonReleased() const
        {
            return !(Flags & MouseButton_Move) && (Flags & MouseButton_Released) && ButtonsState != 0;
        }
        bool IsMouseWheel() const { return (Flags & MouseButton_Wheel) != 0; }
    };
    struct KeyEntry
    {
        UInt32 WcharCode;       // +0x04
        UInt32 Code;            // +0x08
        UByte  AsciiCode;       // +0x0c
        UInt8  KeysState;       // +0x0d KeyModifiers
        UInt8  KeyboardIndex;   // +0x0e
        bool   KeyIsDown;       // +0x0f
    };

    QueueEntryType t;           // +0x00
    union
    {
        MouseEntry mouseEntry;
        KeyEntry   keyEntry;
        UInt32     Unused[9];   // the touch / gesture entries of the build, never queued by MS2
    } u;

    MouseEntry&       GetMouseEntry()       { return u.mouseEntry; }
    const MouseEntry& GetMouseEntry() const { return u.mouseEntry; }
    KeyEntry&         GetKeyEntry()         { return u.keyEntry; }
};

class InputEventsQueue
{
public:
    typedef InputEventsQueueEntry QueueEntry;

    InputEventsQueue();

    // The oldest event, or null when the queue is empty; mouse moves noted since are queued first.
    const QueueEntry* GetEntry();

    void AddMouseMove(unsigned mouseIndex, const Render::PointF& pos);
    void AddMouseButtonEvent(unsigned mouseIndex, const Render::PointF& pos, unsigned buttonsSt, unsigned flags);
    void AddMouseWheel(unsigned mouseIndex, const Render::PointF& pos, int delta);
    void AddKeyEvent(UInt32 code, UByte ascii, UInt32 wcharCode, bool isKeyDown, KeyModifiers specialKeysState,
                     UInt8 keyboardIndex);

protected:
    enum { Queue_Length = 100 };

    // The next free slot; a full queue drops its oldest event.
    QueueEntry* AddEmptyQueueEntry()
    {
        if (UsedEntries == Queue_Length)
        {
            ++StartPos;
            --UsedEntries;
            if (StartPos == Queue_Length)
                StartPos = 0;
        }
        UPInt idx = StartPos + UsedEntries;
        if (idx >= Queue_Length)
            idx -= Queue_Length;
        ++UsedEntries;
        return &Queue[idx];
    }

    QueueEntry     Queue[Queue_Length];               // +0x000
    UPInt          StartPos;                          // +0xfa0
    UPInt          UsedEntries;                       // +0xfa8
    struct MousePos { float x, y; };                  // left uninitialized until a move is noted
    MousePos       LastMousePos[MaxMiceSupported];    // +0xfb0 moves not queued yet
    UInt32         LastMousePosMask;                  // +0xfd0 which LastMousePos are pending
};

// What one mouse is over, pressed on and pointing with.
class MouseState
{
public:
    MouseState();

    void ResetState();
    void UpdateState(const InputEventsQueueEntry& qe);

    void                   SetMouseButtonDownEntity(unsigned buttonIdx, InteractiveObject* pch);
    Ptr<InteractiveObject> GetMouseButtonDownEntity(unsigned buttonIdx) const;

protected:
    enum { Cursor_Arrow = 0 };

    mutable WeakPtr<InteractiveObject>           TopmostEntity;           // +0x00
    mutable WeakPtr<InteractiveObject>           PrevTopmostEntity;       // +0x08
    mutable WeakPtr<InteractiveObject>           ActiveEntity;            // +0x10
    mutable ArrayLH<WeakPtr<InteractiveObject> > MouseButtonDownEntities; // +0x18 one per button

    unsigned       CurButtonsState;                 // +0x30
    unsigned       PrevButtonsState;                // +0x34
    Render::PointF LastPosition;                    // +0x38
    unsigned       PresetCursorType;                // +0x40 ~0u: none
    unsigned       CursorType;                      // +0x44
    int            WheelDelta;                      // +0x48

    bool TopmostEntityIsNull      : 1;              // +0x4c
    bool PrevTopmostEntityWasNull : 1;
    bool MouseInsideEntityLast    : 1;
    bool MouseMoved               : 1;
    bool Activated                : 1;

    // (appended for Button::OnMouseEvent, sfr_gfx_05c)
public:
    enum
    {
        MouseButton_Left = 1
    };
    unsigned GetButtonsState() const     { return CurButtonsState; }
    unsigned GetPrevButtonsState() const { return PrevButtonsState; }
    // (appended for the AS3 mouse event factory, sfr_as3_09)
    const Render::PointF& GetLastPosition() const { return LastPosition; }
};

}} // namespace Scaleform::GFx

#endif
