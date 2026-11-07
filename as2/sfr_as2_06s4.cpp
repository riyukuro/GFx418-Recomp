// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Selection.moveFocus of
// sfr_as2_06 (gap recovery, lane sfr24): a Tab / arrow key press replayed through the movie's focus key handling.
// MS2-UNIT: sfr_as2_06s4
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429689e0-0x142968efa .text$mn

#define SF_GFX_PLAYERIMPL
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/kernel/sf_keycodes.h"

#include <string.h>

namespace Scaleform { namespace GFx { namespace AS2 {

// Value::SetAsCharacter (0x14297fba0) with SetAsCharacterHandle, inlined in moveFocus.
static SF_FORCEINLINE void MfSetValueAsCharacter(Value* pv, InteractiveObject* pchar)
{
    CharacterHandle* phandle = pchar ? pchar->GetCharacterHandle() : 0;
    if (pv->T.Type != Value::CHARACTER || pv->V.pCharHandle != phandle)
    {
        pv->DropRefs();
        pv->T.Type        = Value::CHARACTER;
        pv->V.pCharHandle = phandle;
        if (pv->V.pCharHandle)
            pv->V.pCharHandle->AddRef();
    }
}

// Selection.moveFocus(keyName [, startFrom [, includeFocusEnabled [, controllerIdx]]]): moves the focus as the
// key would from startFrom (or the controller's focused character) and returns the newly focused character.
// @0x1429689e0
void SelectionCtorFunction::MoveFocus(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 0)
        return;

    unsigned controllerIdx = 0;
    if (fn.NArgs >= 4)
        controllerIdx = fn.Arg(3).ToUInt32(fn.Env);

    MovieImpl*             pmovie = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> startCh;
    if (fn.NArgs >= 2 && !fn.Arg(1).IsUndefined() && !fn.Arg(1).IsNull())
        startCh = fn.Arg(1).ToCharacter(fn.Env);
    else
        startCh = pmovie->GetFocusedCharacter(controllerIdx).GetPtr();

    bool includeFocusEnabled = (fn.NArgs >= 3) ? fn.Arg(2).ToBool(fn.Env) : false;

    ASString     directionStr = fn.Arg(0).ToString(fn.Env);
    short        keycode;
    KeyModifiers kmods;
    if (directionStr == "up")
        keycode = Key::Up;
    else if (directionStr == "down")
        keycode = Key::Down;
    else if (directionStr == "left")
        keycode = Key::Left;
    else if (directionStr == "right")
        keycode = Key::Right;
    else if (directionStr == "tab")
        keycode = Key::Tab;
    else if (directionStr == "shifttab")
    {
        keycode = Key::Tab;
        kmods.SetShiftPressed(true);
    }
    else
    {
        if (fn.Env->GetTarget()->GetLog())
            fn.Env->GetTarget()->GetLog()->LogWarning("moveFocus - invalid string id for key: '%s'",
                                                       directionStr.ToCStr());
        return;
    }
    ProcessFocusKeyInfo             focusInfo;
    InputEventsQueueEntry::KeyEntry ke;
    ke.KeyboardIndex = (UInt8)controllerIdx;
    ke.Code          = keycode;
    ke.KeysState     = kmods.States;
    pmovie->InitFocusKeyInfo(&focusInfo, ke, includeFocusEnabled);
    focusInfo.CurFocused  = startCh;
    focusInfo.ManualFocus = true;
    pmovie->ProcessFocusKey(Event::KeyDown, ke, &focusInfo);
    pmovie->FinalizeProcessFocusKey(&focusInfo);
    MfSetValueAsCharacter(fn.Result, focusInfo.CurFocused);
}

}}} // namespace Scaleform::GFx::AS2
