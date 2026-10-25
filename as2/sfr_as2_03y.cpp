// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GenericDisplayObj constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03y
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291cc90-0x14291cd00 .text$mn
// MS2-RANGE: 0x14294a030-0x14294a035 .text$mn
// MS2-RANGE: 0x142954c30-0x142954ca4 .text$mn
// MS2-RANGE: 0x14296efb0-0x14296efc5 .text$mn

#include "../include/gfx/as2/as2_genericdisplayobj.h"
#include "../include/gfx/gfx_rendertree.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14291cc90
GenericDisplayObj::GenericDisplayObj(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent,
                                     ResourceId id)
    : DisplayObjectBase(pasRoot, pparent, id), pDef(pdef)
{
}

// @0x14294a030
CharacterDef* GenericDisplayObj::GetCharacterDef() const
{
    return pDef;
}

// The morph ratio of a shape node, 0 for any other node.
// MS2-FUNCTIONAL: the exe indexes the snapshot page by the in-page offset and does not reuse the first lookup's
// division; the shared Entry::GetReadOnlyDataBase inline subtracts the page base and is CSE'd
// @0x142954c30
float GenericDisplayObj::GetRatio() const
{
    if (pRenNode && pRenNode->GetReadOnlyDataBase()->Type == Render::ContextImpl::EntryData::ET_Shape)
        return static_cast<Render::TreeShape*>(pRenNode.GetPtr())->GetReadOnlyData()->MorphRatio;
    return 0;
}

// @0x14296efb0
bool GenericDisplayObj::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    return pDef->DefPointTestLocal(pt, (hitTestMask & HitTest_TestShape) != 0, this);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7GenericDisplayObj@AS2@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x143215cf0
// MS2-PIN: ??_7GenericDisplayObj@AS2@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x143215f50
