// Recovered Scaleform GFx 4.1.18 AS3: the AS3 movie root's SetVariable value waiting for its target. 0x40 bytes: the
// MovieImpl node (Name, pNext, Permanent) and the AS3 value at +0x20. vftable 0x14317d8c8 (??_G 0x1424e3ac0,
// Assign 0x1424ed890); MovieRoot::AddStickyVariable 0x1424eab60 and MovieRoot::SetVariable 0x14252a700 build it
// inline.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_STICKYVARNODE_H
#define MS2_SF_GFX_AS3_STICKYVARNODE_H

#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_stickyvarnode.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x1424e3ac0: the exe's ??_G inlines the weak-reference release of mValue, ours calls it.
struct MovieRoot::StickyVarNode : public GFx::MovieImpl::StickyVarNode
{
    Value mValue;               // +0x20

    StickyVarNode(const ASString& name, const Value& value, bool permanent)
        : GFx::MovieImpl::StickyVarNode(name, permanent), mValue(value) {}

    virtual void Assign(const GFx::MovieImpl::StickyVarNode& node)
    {
        GFx::MovieImpl::StickyVarNode::Assign(node);
        mValue.Assign(static_cast<const StickyVarNode&>(node).mValue);
    }
};
static_assert(sizeof(MovieRoot::StickyVarNode) == 0x40, "AS3 MovieRoot::StickyVarNode size");

}}} // namespace Scaleform::GFx::AS3

#endif
