// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Selection.findFocus of
// sfr_as2_05 (gap recovery, lane sfr36): the character a Tab / arrow key would move the focus to, found without
// moving it.
// MS2-UNIT: sfr_as2_05n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142943ce0-0x142944689 .text$mn

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

#include <float.h>
#include <string.h>

namespace Scaleform { namespace GFx { namespace AS2 {

// Selection.findFocus(keyName [, parentMovie [, loop [, startFrom [, includeFocusEnabled [, controllerIdx]]]]]):
// the character the key would focus from startFrom (or the controller's focused character), kept within
// parentMovie (null: the modal clip). With loop, when the key leads nowhere the first / last tabable character
// (Tab) or the one at the far edge (arrows) is returned instead; otherwise null.
// MS2-FUNCTIONAL: register allocation and stack layout differ.
// @0x142943ce0
void SelectionCtorFunction::FindFocus(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 0)
        return;

    unsigned controllerIdx = 0;
    if (fn.NArgs >= 6)
        controllerIdx = fn.Arg(5).ToUInt32(fn.Env);

    MovieImpl*             proot = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<InteractiveObject> startChar;
    if (fn.NArgs >= 4 && !fn.Arg(3).IsUndefined() && !fn.Arg(3).IsNull())
        startChar = fn.Arg(3).ToCharacter(fn.Env);
    else
        startChar = Ptr<InteractiveObject>(proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused);

    bool includeFocusEnabled = false;
    if (fn.NArgs >= 5)
        includeFocusEnabled = fn.Arg(4).ToBool(fn.Env);

    ASString    directionStr = fn.Arg(0).ToString(fn.Env);
    const char* pkey         = directionStr.ToCStr();
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
        return;

    Ptr<InteractiveObject> panelChar;
    if (fn.NArgs >= 2)
    {
        Value context = fn.Arg(1);
        if (!context.IsNull() && !context.IsUndefined())
            panelChar = context.ToCharacter(fn.Env);
        else
            panelChar = proot->GetModalClip(controllerIdx);
    }

    bool looping = false;
    if (fn.NArgs >= 3)
        looping = fn.Arg(2).ToBool(fn.Env);

    ProcessFocusKeyInfo             focusInfo;
    InputEventsQueueEntry::KeyEntry ke;
    ke.KeyboardIndex = (UInt8)controllerIdx;
    ke.Code          = keycode;
    ke.KeysState     = shift;
    FocusGroupDescr focusGroup(fn.Env->GetHeap());
    focusGroup.ModalClip   = panelChar ? panelChar->GetCharacterHandle() : NULL;
    focusGroup.LastFocused = startChar;
    proot->InitFocusKeyInfo(&focusInfo, ke, includeFocusEnabled, &focusGroup);
    focusInfo.ManualFocus = true;
    proot->ProcessFocusKey(Event::KeyDown, ke, &focusInfo);
    if (focusInfo.CurFocused && focusInfo.CurFocused != startChar)
        fn.Result->SetAsCharacter(focusInfo.CurFocused);
    else if (!looping || focusGroup.TabableArray.GetSize() == 0)
        fn.Result->SetNull();
    else if ((UInt16)keycode == Key::Tab)
    {
        if (!shift)
            fn.Result->SetAsCharacter(focusGroup.TabableArray[0]);
        else
            fn.Result->SetAsCharacter(focusGroup.TabableArray[focusGroup.TabableArray.GetSize() - 1]);
    }
    else
    {
        float lastV = FLT_MIN;
        UPInt index = 0;
        for (UPInt i = 0, n = focusGroup.TabableArray.GetSize(); i < n; ++i)
        {
            Ptr<InteractiveObject> b = focusGroup.TabableArray[i];
            if ((!focusInfo.InclFocusEnabled && !b->IsTabable()) ||
                !b->IsFocusAllowed(proot, focusInfo.KeyboardIndex))
                continue;
            DisplayObject::Matrix mb;
            b->GetLevelMatrix(&mb);
            RectF bRect = mb.EncloseTransform(b->GetFocusRect());
            switch ((UInt16)keycode)
            {
            case Key::Down: // the topmost
                if (lastV == FLT_MIN || bRect.y1 < lastV)
                {
                    lastV = bRect.y1;
                    index = i;
                }
                break;
            case Key::Up: // the bottommost
                if (lastV == FLT_MIN || bRect.y2 > lastV)
                {
                    lastV = bRect.y2;
                    index = i;
                }
                break;
            case Key::Left: // the rightmost
                if (lastV == FLT_MIN || bRect.x2 > lastV)
                {
                    lastV = bRect.x2;
                    index = i;
                }
                break;
            case Key::Right: // the leftmost
                if (lastV == FLT_MIN || bRect.x1 < lastV)
                {
                    lastV = bRect.x1;
                    index = i;
                }
                break;
            default:
                break;
            }
        }
        fn.Result->SetAsCharacter(focusGroup.TabableArray[index]);
    }
}

}}} // namespace Scaleform::GFx::AS2
