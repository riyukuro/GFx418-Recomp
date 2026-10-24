// Recovered Scaleform 4.1.18 GFx AS2: GenericDisplayObj, the display object of a plain shape character.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_GENERICDISPLAYOBJ_H
#define MS2_SF_GFX_AS2_GENERICDISPLAYOBJ_H

#include "../gfx_displayobject.h"
#include "../gfx_characterdef.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The exe vftables are 0x143215cf0 (primary) and 0x143215f50 (LogBase); its own slots are the scalar deleting dtor
// 0x14292b470, CreateRenderNode 0x142937ca0 and GetTopMostMouseEntity 0x142956ad0, the rest is not modeled yet.
class GenericDisplayObj : public DisplayObjectBase
{
public:
    Ptr<CharacterDef> pDef; // +0x70

    GenericDisplayObj(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id); // exe 0x14291cc90

    // (appended, sfr31) the definition's local bounds taken to the space of t.
    virtual RectF         GetBounds(const Matrix& t) const;                              // exe 0x1429498a0
    virtual RectF         GetRectBounds(const Matrix& t) const;                          // exe 0x142954cb0
    virtual TopMostResult GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr); // exe 0x142956ad0
};

}}} // namespace Scaleform::GFx::AS2

#endif
