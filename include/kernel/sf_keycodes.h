// Recovered Scaleform 4.1.18 Kernel: key codes (Windows virtual-key values) and the modifier-key byte passed with
// key events. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_KEYCODES_H
#define MS2_SF_KERNEL_KEYCODES_H

#include "sf_types.h"

namespace Scaleform {

// Key codes used by the player (the keyboard state keeps one bit per code below KeyCount).
struct Key
{
    enum Code
    {
        VoidSymbol = 0,
        Backspace  = 8,
        Tab        = 9,
        Clear      = 12,
        Return     = 13,
        Shift      = 16,
        Control    = 17,
        Alt        = 18,
        Pause      = 19,
        CapsLock   = 20,
        Escape     = 27,
        Space      = 32,
        PageUp     = 33,
        PageDown   = 34,
        End        = 35,
        Home       = 36,
        Left       = 37,
        Up         = 38,
        Right      = 39,
        Down       = 40,
        Insert     = 45,
        Delete     = 46,
        Help       = 47,
        A          = 65,
        C          = 67,
        V          = 86,
        X          = 88,
        Z          = 90,
        NumLock    = 144,
        ScrollLock = 145,

        KeyCount   = 229 // codes 0..228 (the state checks code > 228)
    };
};

// Modifier keys held with a key event, one byte of flags. Bit 7 marks an explicitly initialized value.
class KeyModifiers
{
public:
    enum
    {
        Key_ShiftPressed  = 0x01,
        Key_CtrlPressed   = 0x02,
        Key_AltPressed    = 0x04,
        Key_CapsToggled   = 0x08,
        Key_NumToggled    = 0x10,
        Key_ScrollToggled = 0x20,
        Key_ExtendedKey   = 0x40,

        Initialized_Bit   = 0x80,
        Initialized_Mask  = 0xFF
    };

    UInt8 States;

    KeyModifiers() : States(0) {}
    KeyModifiers(UInt8 st) : States(UInt8(st | Initialized_Bit)) {}

    void Reset() { States = 0; }

    bool IsShiftPressed() const      { return (States & Key_ShiftPressed) != 0; }
    bool IsCtrlPressed() const       { return (States & Key_CtrlPressed) != 0; }
    bool IsAltPressed() const        { return (States & Key_AltPressed) != 0; }
    bool IsCapsToggled() const       { return (States & Key_CapsToggled) != 0; }
    bool IsNumToggled() const        { return (States & Key_NumToggled) != 0; }
    bool IsScrollToggled() const     { return (States & Key_ScrollToggled) != 0; }
    bool IsExtendedKey() const       { return (States & Key_ExtendedKey) != 0; }
    bool IsSpecialKeyPressed() const { return (States & (Key_ShiftPressed | Key_CtrlPressed | Key_AltPressed)) != 0; }

    void SetFlag(UInt8 flag, bool on)
    {
        if (on)
            States |= flag;
        else
            States &= ~flag;
    }
    void SetShiftPressed(bool v = true)  { SetFlag(Key_ShiftPressed, v); }
    void SetCtrlPressed(bool v = true)   { SetFlag(Key_CtrlPressed, v); }
    void SetAltPressed(bool v = true)    { SetFlag(Key_AltPressed, v); }
    void SetCapsToggled(bool v = true)   { SetFlag(Key_CapsToggled, v); }
    void SetNumToggled(bool v = true)    { SetFlag(Key_NumToggled, v); }
    void SetScrollToggled(bool v = true) { SetFlag(Key_ScrollToggled, v); }
    void SetExtendedKey(bool v = true)   { SetFlag(Key_ExtendedKey, v); }

    bool IsInitialized() const { return (States & Initialized_Bit) != 0; }
};

} // namespace Scaleform

#endif
