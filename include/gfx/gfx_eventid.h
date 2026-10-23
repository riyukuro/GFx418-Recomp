// Recovered Scaleform 4.1.18 GFx: EventId, the description of a clip/button event (frame, mouse, key and the
// load/socket/XML notifications) passed to the AVM event handlers.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout is the exe's: Id +0, WcharCode +4, KeyCode +8, AsciiCode/ButtonId +0xc (a 4-byte union), RollOverCnt +0x10,
// ControllerIndex +0x11, KeysState +0x12, MouseWheelDelta +0x13 (an event built from an id stores 0xff00 at +0x10).
#ifndef MS2_SF_GFX_EVENTID_H
#define MS2_SF_GFX_EVENTID_H

#include "../kernel/sf_types.h"

namespace Scaleform { namespace GFx {

class EventId
{
public:
    enum IdCode
    {
        Event_Invalid = 0,

        // Clip events; these are bit flags so that one handler may react to several of them.
        Event_Load              = 0x000001,
        Event_EnterFrame        = 0x000002,
        Event_Unload            = 0x000004,
        Event_MouseMove         = 0x000008,
        Event_MouseDown         = 0x000010,
        Event_MouseUp           = 0x000020,
        Event_KeyDown           = 0x000040,
        Event_KeyUp             = 0x000080,
        Event_Data              = 0x000100,
        Event_Initialize        = 0x000200,
        // Button events.
        Event_Press             = 0x000400,
        Event_Release           = 0x000800,
        Event_ReleaseOutside    = 0x001000,
        Event_RollOver          = 0x002000,
        Event_RollOut           = 0x004000,
        Event_DragOver          = 0x008000,
        Event_DragOut           = 0x010000,
        Event_KeyPress          = 0x020000,
        Event_Construct         = 0x040000,
        // The same button events from a non-primary mouse button.
        Event_PressAux          = 0x080000,
        Event_ReleaseAux        = 0x100000,
        Event_ReleaseOutsideAux = 0x200000,
        Event_DragOverAux       = 0x400000,
        Event_DragOutAux        = 0x800000,

        Event_AuxEventMask      = 0xf80000,
        Event_ButtonEventsMask  = 0xfbfc00,

        // Plain (non flag) ids from here on.
        Event_LoadStart         = 0x1000000,
        Event_LoadError,
        Event_LoadProgress,     // 0x1000002
        Event_LoadInit,
        Event_SockClose,
        Event_SockConnect,
        Event_SockData,
        Event_SockXML           // 0x1000007
    };

    UInt32 Id;
    UInt32 WcharCode;
    UInt32 KeyCode;
    union
    {
        UByte    AsciiCode;
        UByte    ButtonId;
        unsigned TouchID;
    };
    UByte RollOverCnt;
    union
    {
        SByte ControllerIndex;
        SByte MouseIndex;
        SByte KeyboardIndex;
    };
    UByte KeysState;
    SByte MouseWheelDelta;

    EventId() : Id(Event_Invalid), WcharCode(0), KeyCode(0), AsciiCode(0), RollOverCnt(0), KeysState(0),
                MouseWheelDelta(0)
    {
        ControllerIndex = -1;
    }
    EventId(UInt32 id) : Id(id), WcharCode(0), KeyCode(0), AsciiCode(0), RollOverCnt(0), KeysState(0),
                         MouseWheelDelta(0)
    {
        ControllerIndex = -1;
    }

    bool IsButtonEvent() const { return (Id & Event_ButtonEventsMask) != 0; }

    // (appended for Sprite::OnKeyEvent, sfr_gfx_05b) a key event of keyboard keyboardIndex
    EventId(UInt32 id, short keyCode, UByte asciiCode, UInt32 wcharCode = 0, UByte keyboardIndex = 0)
        : Id(id), WcharCode(wcharCode), KeyCode(keyCode), AsciiCode(asciiCode), RollOverCnt(0), KeysState(0),
          MouseWheelDelta(0)
    {
        KeyboardIndex = keyboardIndex;
    }
    // The button key code (on(keyPress)) of a key down event, 0 when the key has none (0x142603da0).
    int ConvertToButtonKeyCode() const;

    // (appended for the AS2 event handler tables, sfr_as2_02) key press events also compare the key code.
    bool operator==(const EventId& id) const
    {
        return Id == id.Id && (!(Id & Event_KeyPress) || KeyCode == id.KeyCode);
    }

    // (appended for GFx_Input, sfr_gfx_06f) the character a US keyboard types for KeyCode under the shift and
    // caps lock states of KeysState, 0 for none (0x142603d20).
    UByte ConvertKeyCodeToAscii() const;
};

// Hash of an event id: key press events mix in the key code.
struct EventIdHashFunctor
{
    UPInt operator()(const EventId& data) const
    {
        UPInt hash = data.Id;
        if (data.Id & EventId::Event_KeyPress)
            hash ^= data.KeyCode;
        return hash;
    }
};

}} // namespace Scaleform::GFx

#endif
