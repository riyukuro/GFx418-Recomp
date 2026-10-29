// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmSprite::FillTabableArray, gap
// function of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142941b40-0x142941d64 .text$mn

#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Appends the tabable children to the focus group's tab order: the clip's own tabChildren (or the prototype's,
// looked up once per call chain) can switch its subtree off.
// MS2-FUNCTIONAL: Ptr/array push scheduling
// @0x142941b40
void AvmSprite::FillTabableArray(InteractiveObject::FillTabableParams* params)
{
    Sprite* psprite = GetSprite();
    UPInt   n       = psprite->mDisplayList.GetCount();
    if (n == 0)
        return;
    if (Unrecovered_1f8 == 0 && params->TabChildrenInProto == 0 && pProto)
    {
        Value value;
        // raw lookup (vtable +0x58); a null value still counts (ToBool gives false)
        if (pProto->GetMemberRaw(&Env.StringContext, Env.CreateConstString("tabChildren"), &value) &&
            !value.IsUndefined())
            params->TabChildrenInProto = value.ToBool(&Env) ? 1 : 2;
    }
    if (Unrecovered_1f8 == 2 || params->TabChildrenInProto == 2)
        return;
    for (UPInt i = 0; i < n; ++i)
    {
        DisplayObjectBase* ch = psprite->mDisplayList.GetDisplayObject(i);
        if (ch && ch->IsInteractiveObject() && ch->GetVisible())
        {
            InteractiveObject* pio = static_cast<InteractiveObject*>(ch);
            if (pio->TabIndex > 0 && !params->TabIndexed)
            {
                params->Array->Resize(0);
                params->TabIndexed = true;
            }
            // focusEnabled counts as moved by keyboard (0x142941cd6 mov edx,2)
            if ((pio->IsTabable() || (params->InclFocusEnabled && pio->IsFocusEnabled(GFx_FocusMovedByKeyboard))) &&
                (!params->TabIndexed || pio->TabIndex > 0))
            {
                params->Array->PushBack(Ptr<InteractiveObject>(pio));
            }
            if (ch->IsDisplayObjContainer())
                static_cast<DisplayObjContainer*>(ch)->FillTabableArray(params);
        }
    }
}

} } }
