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

    // Key() called as a function: null (exe 0x14295bbe0).
    static void GlobalCtor(const FnCall& fn);

    virtual void Finalize_GC();                                  // exe 0x142942da0: drops the movie, then Object's

public:
    static const NameFunction FunctionTable[]; // exe 0x143213a70: getAscii ...

    KeyCtorFunction(ASStringContext* psc, MovieImpl* pmovie); // exe 0x14291d1e0

    virtual Object* CreateNewObject(Environment*) const { return 0; } // exe 0x142936f00

    // KeyboardState::IListener (declared only; the exe's slots are 0x14296c180, 0x14296c1d0 (adjusting thunks) and
    // 0x142992840, which records the key in States).
    virtual void OnKeyDown(InteractiveObject* pmovie, const EventId& evt, int keyMask);
    virtual void OnKeyUp(InteractiveObject* pmovie, const EventId& evt, int keyMask);
    virtual void Update(const EventId& evt);

    // (appended, sfr24) records the key of evt's controller and broadcasts its handler (onKeyDown/onKeyUp) to the
    // listeners in _level0's environment; OnKeyDown and OnKeyUp are this body (exe 0x142969250).
    void NotifyListeners(InteractiveObject* pmovie, const EventId& evt);

    int GetLastKeyCode(unsigned controllerIdx) const   { return States[controllerIdx].LastKeyCode; }
    int GetLastAsciiCode(unsigned controllerIdx) const { return States[controllerIdx].LastAsciiCode; }

    static void KeyGetAscii(const FnCall& fn);
    static void KeyGetCode(const FnCall& fn);
    static void KeyIsDown(const FnCall& fn);
    static void KeyIsToggled(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS2::KeyCtorFunction) == 0x140, "KeyCtorFunction size");

#endif
