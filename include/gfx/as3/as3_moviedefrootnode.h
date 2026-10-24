// Recovered Scaleform GFx 4.1.18 AS3: the root node of a movie loaded under the AS3 movie root, the GFx node plus
// the ABC files the movie brought (they live as long as the movie). 0x58 bytes; vftable 0x14317d8c0 (1 slot:
// ??_G 0x1424e3290); MovieRoot::CreateMovieDefRootNode 0x1424f3910 builds it in the movie's heap. The destructor
// 0x1424de580 releases the files from the last one down, then runs the GFx node's.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_MOVIEDEFROOTNODE_H
#define MS2_SF_GFX_AS3_MOVIEDEFROOTNODE_H

#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class MovieDefRootNode : public GFx::MovieDefRootNode
{
public:
    ArrayLH<SPtr<VMAbcFile> > AbcFiles;     // +0x40

    MovieDefRootNode(MovieDefImpl* pdefImpl, bool importFlag) : GFx::MovieDefRootNode(pdefImpl, importFlag) {}
    virtual ~MovieDefRootNode();            // 0x1424de580
};
static_assert(sizeof(MovieDefRootNode) == 0x58, "AS3 MovieDefRootNode size");

}}} // namespace Scaleform::GFx::AS3

#endif
