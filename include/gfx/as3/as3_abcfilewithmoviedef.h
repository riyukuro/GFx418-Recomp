// Recovered Scaleform GFx 4.1.18 AS3: the parsed ABC file of one DoABC tag, which keeps the movie definition and the
// tag's byte code alive while the VM uses the file. 0x198 bytes, vftable 0x14317d8a8 (only the deleting destructor
// 0x1424e2390). MovieRoot::ExecuteAbc 0x1424f9d60 builds it inline.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_ABCFILEWITHMOVIEDEF_H
#define MS2_SF_GFX_AS3_ABCFILEWITHMOVIEDEF_H

#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#include "ms2/scaleform/include/gfx/gfx_moviedef.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class ASVM::AbcFileWithMovieDef : public Abc::File
{
public:
    Ptr<MovieDefImpl>  pDefImpl;    // +0x188
    Ptr<AbcDataBuffer> pAbcData;    // +0x190

    AbcFileWithMovieDef(MovieDefImpl* pdefImpl, AbcDataBuffer* data) : pDefImpl(pdefImpl), pAbcData(data) {}
    virtual ~AbcFileWithMovieDef() {}
};
static_assert(sizeof(ASVM::AbcFileWithMovieDef) == 0x198, "AbcFileWithMovieDef size");

}}} // namespace Scaleform::GFx::AS3

#endif
