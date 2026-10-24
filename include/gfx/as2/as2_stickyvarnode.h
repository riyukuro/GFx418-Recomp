// Recovered Scaleform GFx 4.1.18 AS2: the AS2 movie root's SetVariable value waiting for its target. 0x40 bytes: the
// MovieImpl node (Name, pNext, Permanent) and the AS2 value at +0x20. vftable 0x1432177c8 (??_G 0x14292cfc0,
// Assign 0x142931870); MovieRoot::AddStickyVariable 0x1429306a0 builds it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS2_STICKYVARNODE_H
#define MS2_SF_GFX_AS2_STICKYVARNODE_H

#include "as2_movieroot.h"
#include "../gfx_stickyvarnode.h"

namespace Scaleform { namespace GFx { namespace AS2 {

struct MovieRoot::StickyVarNode : public GFx::MovieImpl::StickyVarNode
{
    Value mValue; // +0x20

    StickyVarNode(const ASString& name, const Value& value, bool permanent)
        : GFx::MovieImpl::StickyVarNode(name, permanent), mValue(value) {}

    virtual void Assign(const GFx::MovieImpl::StickyVarNode& node); // exe 0x142931870
};
static_assert(sizeof(MovieRoot::StickyVarNode) == 0x40, "AS2 MovieRoot::StickyVarNode size");

}}} // namespace Scaleform::GFx::AS2

#endif
