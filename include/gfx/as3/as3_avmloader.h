// Recovered Scaleform GFx 4.1.18 AS3: the display object behind an AS3 Loader, a plain container with no character
// definition of its own. 0x158 bytes: DisplayObjContainer (0x110) then the AvmDisplayObjContainer part at +0x110.
// The ctor 0x1424d6500 builds it; the deleting destructor 0x1424e28e0 frees 0x158 bytes. Over DisplayObjContainer's
// vftable 0x14318e318 its primary vftable 0x14317de60 (121 slots) overrides only 0 and 59; the AvmDisplayObj
// (0x14317e238), AvmInteractiveObjBase (0x14317e330) and AvmDisplayObjContainerBase (0x14317e3e8) vftables only
// redirect the deleting destructor.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Units that define a local class AvmLoader of their own (sfr_as3_15) must not include this header.
#ifndef MS2_SF_GFX_AS3_AVMLOADER_H
#define MS2_SF_GFX_AS3_AVMLOADER_H

#include "ms2/scaleform/include/gfx/as3/as3_avm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class AvmLoader : public DisplayObjContainer, public AvmDisplayObjContainer
{
public:
    AvmLoader(ASMovieRootBase* pasRoot, MovieDefImpl* pdefImpl, InteractiveObject* pparent, ResourceId id); // 0x1424d6500
    // Body: AvmObjOffset = 0 (the AS3 part is a base here, not one DisplayObjectBase destroys). Exact, with the
    // inline ~AvmInteractiveObj, for 0x1424ddc40 and ??_G 0x1424e28e0 (the TU defining it emits both).
    virtual ~AvmLoader();

    virtual CharacterDef* GetCharacterDef() const { return NULL; }                  // 59 0x142507b40
};
static_assert(sizeof(AvmLoader) == 0x158, "AvmLoader size");

}}} // namespace Scaleform::GFx::AS3

#endif
