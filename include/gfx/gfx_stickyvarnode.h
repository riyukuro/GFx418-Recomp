// Recovered Scaleform GFx 4.1.18: MovieImpl's SetVariable value waiting for its target. A header of its own because
// gfx_movieimpl.h does not need ASString complete.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_STICKYVARNODE_H
#define MS2_SF_GFX_STICKYVARNODE_H

#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"

namespace Scaleform { namespace GFx {

// A SetVariable value waiting for its target: the chain of values set under one path (MovieImpl's
// StickyVariables). 0x20 bytes, vftable 0x14317ca50 (??_G 0x1424e3a50, Assign 0x1424ed840); the AS2 and AS3 movie
// roots derive their nodes, which add the value, from it (AS3: as3_stickyvarnode.h).
struct MovieImpl::StickyVarNode : public NewOverrideBase<0x147>   // StatMV_Other_Mem
{
    ASString       Name;        // +0x08
    StickyVarNode* pNext;       // +0x10
    bool           Permanent;   // +0x18

    StickyVarNode(const ASString& name, bool permanent) : Name(name), pNext(0), Permanent(permanent) {}
    virtual ~StickyVarNode() {}
    // The derived nodes also copy the value.
    virtual void Assign(const StickyVarNode& node) { Name = node.Name; Permanent = node.Permanent; }
};
static_assert(sizeof(MovieImpl::StickyVarNode) == 0x20, "MovieImpl::StickyVarNode size");

}} // namespace Scaleform::GFx

#endif
