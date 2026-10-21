// Recovered Scaleform 4.1.18 GFx AS2: the Key class (constructor function keeping the last key of every
// controller). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_KEYOBJECT_H
#define MS2_SF_GFX_AS2_KEYOBJECT_H

#include "as2_action.h"
#include "../gfx_keyboardstate.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// IListener at +0x70, States +0x78, the movie +0x138.
class KeyCtorFunction : public CFunctionObject, public KeyboardState::IListener
{
protected:
    // Last key of one controller. 0x0c bytes.
    struct State
    {
        int    LastKeyCode;   // +0x00
        UByte  LastAsciiCode; // +0x04
        UInt32 LastWcharCode; // +0x08
    };
    State      States[16];  // +0x78
    MovieImpl* pMovieRoot;  // +0x138

public:
    int GetLastKeyCode(unsigned controllerIdx) const   { return States[controllerIdx].LastKeyCode; }
    int GetLastAsciiCode(unsigned controllerIdx) const { return States[controllerIdx].LastAsciiCode; }

    static void KeyGetAscii(const FnCall& fn);
    static void KeyGetCode(const FnCall& fn);
    static void KeyIsDown(const FnCall& fn);
    static void KeyIsToggled(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
