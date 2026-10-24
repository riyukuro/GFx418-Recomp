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

// Selection.moveFocus(keyName [, startFrom [, includeFocusEnabled [, controllerIdx]]]): moves the focus as the
// key would from startFrom (or the controller's focused character) and returns the newly focused character.
// MS2-FUNCTIONAL: register allocation and stack layout differ.
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
        startCh = Ptr<InteractiveObject>(pmovie->FocusGroups[pmovie->FocusGroupIndexes[controllerIdx]].LastFocused);

    bool includeFocusEnabled = false;
    if (fn.NArgs >= 3)
        includeFocusEnabled = fn.Arg(2).ToBool(fn.Env);

    ASString    keyStr = fn.Arg(0).ToString(fn.Env);
    const char* pkey   = keyStr.ToCStr();
    UInt32      keycode;
    bool        shift = false;
    if (strcmp(pkey, "up") == 0)
        keycode = Key::Up;
    else if (strcmp(pkey, "down") == 0)
        keycode = Key::Down;
    else if (strcmp(pkey, "left") == 0)
        keycode = Key::Left;
    else if (strcmp(pkey, "right") == 0)
        keycode = Key::Right;
    else if (strcmp(pkey, "tab") == 0)
        keycode = Key::Tab;
    else if (strcmp(pkey, "shifttab") == 0)
    {
        keycode = Key::Tab;
        shift   = true;
    }
    else
    {
        if (fn.Env->GetTarget()->GetLog())
            fn.Env->GetTarget()->GetLog()->LogWarning("moveFocus - invalid string id for key: '%s'", pkey);
        return;
    }

    InputEventsQueueEntry::KeyEntry ke;
    ke.Code          = keycode;
    ke.KeysState     = shift;
    ke.KeyboardIndex = (UInt8)controllerIdx;

    ProcessFocusKeyInfo focusInfo;
    pmovie->InitFocusKeyInfo(&focusInfo, ke, includeFocusEnabled);
    focusInfo.CurFocused  = startCh;
    focusInfo.ManualFocus = true;
    pmovie->ProcessFocusKey(Event::KeyDown, ke, &focusInfo);
    pmovie->FinalizeProcessFocusKey(&focusInfo);
    fn.Result->SetAsCharacter(focusInfo.CurFocused);
}

}}} // namespace Scaleform::GFx::AS2
