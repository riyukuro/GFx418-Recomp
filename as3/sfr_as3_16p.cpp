// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the TreeNode snapshot payload copy used by AS3 display objects.
// MS2-UNIT: sfr_as3_16p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424e0a70-0x1424e0b40 .text$mn
#include "ms2/scaleform/include/render/render_treenode.h"

#include <cstring>

// @0x1424e0a70
Scaleform::Render::TreeNode::NodeData&
Scaleform::Render::TreeNode::NodeData::operator=(const NodeData& src)
{
    ContextImpl::EntryData::operator=(src);
    M34 = src.M34;
    States = src.States;
    Cx = src.Cx;
    AproxLocalBounds = src.AproxLocalBounds;
    AproxParentBounds = src.AproxParentBounds;
    return *this;
}
