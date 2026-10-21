// Recovered Scaleform 4.1.18 GFx_Input: the input event queue (a ring of 100 events plus the pending mouse moves),
// the per-mouse state and the key code conversions of EventId.
// Scaleform GFx 4.1.18, recovered from the exe; the SDK sources served only as a reference.
// MS2-UNIT: sfr_gfx_06f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142603a30-0x142604370 .text$mn
#include <float.h>
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx {

// A position of FLT_MIN means the event carries none.
static const float NoPosition = FLT_MIN;

// The key codes on(keyPress) knows by name (Windows virtual key values).
enum
{
    KeyCode_Backspace = 8,
    KeyCode_Tab       = 9,
    KeyCode_Return    = 13,
    KeyCode_Escape    = 27,
    KeyCode_PageUp    = 33,
    KeyCode_PageDown  = 34,
    KeyCode_End       = 35,
    KeyCode_Home      = 36,
    KeyCode_Left      = 37,
    KeyCode_Up        = 38,
    KeyCode_Right     = 39,
    KeyCode_Down      = 40,
    KeyCode_Insert    = 45,
    KeyCode_Delete    = 46
};

// @0x142603a30
InputEventsQueue::InputEventsQueue() : StartPos(0), UsedEntries(0), LastMousePosMask(0)
{
}

// @0x142603a50
MouseState::MouseState()
{
    ResetState();
}

// @0x142603af0
void InputEventsQueue::AddKeyEvent(UInt32 code, UByte ascii, UInt32 wcharCode, bool isKeyDown,
                                   KeyModifiers specialKeysState, UInt8 keyboardIndex)
{
    QueueEntry* pqe = AddEmptyQueueEntry();
    pqe->t          = QueueEntry::QE_Key;
    QueueEntry::KeyEntry& key = pqe->GetKeyEntry();
    key.Code          = code;
    key.AsciiCode     = ascii;
    key.WcharCode     = wcharCode;
    key.KeysState     = specialKeysState.States;
    key.KeyboardIndex = keyboardIndex;
    key.KeyIsDown     = isKeyDown;
}

// @0x142603b80
void InputEventsQueue::AddMouseButtonEvent(unsigned mouseIndex, const Render::PointF& pos, unsigned buttonsSt,
                                           unsigned flags)
{
    // The event's own position supersedes a pending move.
    if (pos.x != NoPosition)
        LastMousePosMask &= ~(1 << mouseIndex);

    QueueEntry* pqe = AddEmptyQueueEntry();
    pqe->t          = QueueEntry::QE_Mouse;
    QueueEntry::MouseEntry& mouse = pqe->GetMouseEntry();
    mouse.MouseIndex   = (UInt8)mouseIndex;
    mouse.PosX         = pos.x;
    mouse.PosY         = pos.y;
    mouse.ButtonsState = (QueueEntry::ButtonsStateType)buttonsSt;
    mouse.Flags        = (UInt8)flags;
}

// @0x142603c30
void InputEventsQueue::AddMouseMove(unsigned mouseIndex, const Render::PointF& pos)
{
    // Moves are only noted; GetEntry queues the last one when the queue runs dry.
    if (mouseIndex < MaxMiceSupported)
    {
        LastMousePosMask |= (1 << mouseIndex);
        LastMousePos[mouseIndex].x = pos.x;
        LastMousePos[mouseIndex].y = pos.y;
    }
}

// @0x142603c70
void InputEventsQueue::AddMouseWheel(unsigned mouseIndex, const Render::PointF& pos, int delta)
{
    if (pos.x != NoPosition)
        LastMousePosMask &= ~(1 << mouseIndex);

    QueueEntry* pqe = AddEmptyQueueEntry();
    pqe->t          = QueueEntry::QE_Mouse;
    QueueEntry::MouseEntry& mouse = pqe->GetMouseEntry();
    mouse.MouseIndex       = (UInt8)mouseIndex;
    mouse.PosX             = pos.x;
    mouse.PosY             = pos.y;
    mouse.WheelScrollDelta = (SInt8)delta;
    mouse.ButtonsState     = 0;
    mouse.Flags            = QueueEntry::MouseButton_Wheel;
}

// @0x142603d20
UByte EventId::ConvertKeyCodeToAscii() const
{
    // Key codes 32..111: space, digits, letters and the numeric pad.
    static const UByte lower1[] =
    {
        ' ', 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 0,   0,   0,   0,   0,   0,
        0,   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 0,   0,   0,   0,   0,
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '+', 0,   '-', '.', '/'
    };
    static const UByte upper1[] =
    {
        ' ', 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        ')', '!', '@', '#', '$', '%', '^', '&', '*', '(', 0,   0,   0,   0,   0,   0,
        0,   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 0,   0,   0,   0,   0,
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '+', 0,   '-', '.', '/'
    };
    // Key codes 186..222: the punctuation keys.
    static const UByte lower2[] =
    {
        ';', '=', ',', '-', '.', '/', '`', 0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   '[', '\\', ']', '\''
    };
    static const UByte upper2[] =
    {
        ':', '+', '<', '_', '>', '?', '~', 0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   '{', '|', '}', '"'
    };

    UByte asciiCode = 0;
    bool  shift     = (KeysState & KeyModifiers::Key_ShiftPressed) != 0;
    if (KeysState & KeyModifiers::Key_CapsToggled)
        shift = !shift;

    // Both range checks use the size of the first table (the second one reads into the padding after it).
    if (KeyCode >= 32 && KeyCode <= sizeof(lower1) + 32)
    {
        if (!shift)
            asciiCode = lower1[KeyCode - 32];
        else
            asciiCode = upper1[KeyCode - 32];
    }
    else if (KeyCode >= 186 && KeyCode <= sizeof(lower1) + 186)
    {
        if (!shift)
            asciiCode = lower2[KeyCode - 186];
        else
            asciiCode = upper2[KeyCode - 186];
    }
    return asciiCode;
}

// @0x142603da0
int EventId::ConvertToButtonKeyCode() const
{
    int kc = 0;
    switch (KeyCode)
    {
    case KeyCode_Left:      kc = 1; break;
    case KeyCode_Right:     kc = 2; break;
    case KeyCode_Home:      kc = 3; break;
    case KeyCode_End:       kc = 4; break;
    case KeyCode_Insert:    kc = 5; break;
    case KeyCode_Delete:    kc = 6; break;
    case KeyCode_Backspace: kc = 8; break;
    case KeyCode_Return:    kc = 13; break;
    case KeyCode_Up:        kc = 14; break;
    case KeyCode_Down:      kc = 15; break;
    case KeyCode_PageUp:    kc = 16; break;
    case KeyCode_PageDown:  kc = 17; break;
    case KeyCode_Tab:       kc = 18; break;
    case KeyCode_Escape:    kc = 19; break;
    default:
        // Printable characters are their own code.
        if (AsciiCode >= 32)
            kc = AsciiCode;
    }
    return kc;
}

// @0x142603ed0
const InputEventsQueue::QueueEntry* InputEventsQueue::GetEntry()
{
    if (UsedEntries == 0)
    {
        // Out of events: the pending moves become events of their own.
        for (unsigned i = 0, mask = 1; i < MaxMiceSupported; ++i, mask <<= 1)
        {
            if (LastMousePosMask & mask)
            {
                QueueEntry* pqe = AddEmptyQueueEntry();
                pqe->t          = QueueEntry::QE_Mouse;
                QueueEntry::MouseEntry& mouse = pqe->GetMouseEntry();
                mouse.MouseIndex   = (UInt8)i;
                mouse.PosX         = LastMousePos[i].x;
                mouse.PosY         = LastMousePos[i].y;
                mouse.ButtonsState = 0;
                mouse.Flags        = QueueEntry::MouseButton_Move;
                LastMousePosMask  &= ~mask;
            }
        }
        if (UsedEntries == 0)
            return 0;
    }
    UPInt idx = StartPos;
    ++StartPos;
    --UsedEntries;
    if (StartPos == Queue_Length)
        StartPos = 0;
    return &Queue[idx];
}

// @0x142603ff0
Ptr<InteractiveObject> MouseState::GetMouseButtonDownEntity(unsigned buttonIdx) const
{
    if (buttonIdx >= MouseButtonDownEntities.GetSize())
        return 0;
    return MouseButtonDownEntities[buttonIdx];
}

// @0x142604170
void MouseState::ResetState()
{
    PresetCursorType = ~0u;
    CursorType       = Cursor_Arrow;
    CurButtonsState = PrevButtonsState = 0;
    LastPosition.x = LastPosition.y = 0;
    MouseInsideEntityLast = false;
    TopmostEntityIsNull = PrevTopmostEntityWasNull = false;
    Activated = MouseMoved = false;
    WheelDelta = 0;
}

// @0x142604190
void MouseState::SetMouseButtonDownEntity(unsigned buttonIdx, InteractiveObject* pch)
{
    if (buttonIdx >= MouseButtonDownEntities.GetSize())
        MouseButtonDownEntities.Resize(buttonIdx + 1);
    MouseButtonDownEntities[buttonIdx] = pch;
}

// @0x1426042e0
void MouseState::UpdateState(const InputEventsQueueEntry& qe)
{
    Activated        = true;
    PrevButtonsState = CurButtonsState;
    const InputEventsQueueEntry::MouseEntry& mouse = qe.GetMouseEntry();
    if (mouse.IsButtonsStateChanged())
    {
        if (mouse.IsAnyButtonReleased())
            CurButtonsState &= ~(mouse.ButtonsState & InputEventsQueueEntry::MouseButton_AllMask);
        else
            CurButtonsState |= (mouse.ButtonsState & InputEventsQueueEntry::MouseButton_AllMask);
    }

    if (mouse.IsMouseWheel())
        WheelDelta = mouse.WheelScrollDelta;
    else
        WheelDelta = 0;

    // Moved means moved by at least a whole twip.
    if ((int)mouse.GetPosition().x != (int)LastPosition.x || (int)mouse.GetPosition().y != (int)LastPosition.y)
        MouseMoved = true;
    else
        MouseMoved = false;
    LastPosition = mouse.GetPosition();
}

}} // namespace Scaleform::GFx
