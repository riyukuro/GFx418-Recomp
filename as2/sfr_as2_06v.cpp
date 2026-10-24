// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr36): GenericDisplayObj::SetRatio.
// MS2-UNIT: sfr_as2_06v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298a5a0-0x14298a61d .text$mn

#include "../include/gfx/as2/as2_genericdisplayobj.h"
#include "../include/gfx/gfx_rendertree.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The morph ratio only applies when the render node is a shape node.
// @0x14298a5a0
void GenericDisplayObj::SetRatio(float ratio)
{
    Render::TreeNode* node = GetRenderNode();
    if (node && node->GetReadOnlyDataBase()->Type == Render::ContextImpl::EntryData::ET_Shape)
    {
        Render::TreeShape* shape = static_cast<Render::TreeShape*>(pRenNode.GetPtr());
        shape->GetWritableData(Render::Change_MorphRatio)->MorphRatio = ratio;
    }
}

}}} // namespace Scaleform::GFx::AS2
