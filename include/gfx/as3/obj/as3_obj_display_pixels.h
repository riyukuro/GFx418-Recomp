// Recovered Scaleform GFx 4.1.18 AS3: the pixel providers BitmapData's getPixels / setPixels (ByteArray) and
// getVector / setVector (Vector.<uint>) hand to Render::DrawableImage::GetPixels / SetPixels. Our own declarations.
// Bodies: GetLength / ReadNextPixel in sfr_as3_06, WriteNextPixel in sfr_as3_07 (the deleting dtors are COMDATs).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_DISPLAY_PIXELS_H
#define MS2_SF_GFX_AS3_OBJ_DISPLAY_PIXELS_H

#include "ms2/scaleform/include/render/render_dipixelprovider.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_utils.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_vec.h"

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_display {

// Pixels read from / written to a ByteArray at its position, one UInt32 each in the array's byte order.
// 0x10 bytes; vftable 0x14314a930 (deleting dtor 0x14243dc70).
class ByteArrayPixelProvider : public Render::DIPixelProvider
{
public:
    ByteArrayPixelProvider(Instances::fl_utils::ByteArray* pbytes) : pBytes(pbytes) {}

    virtual UPInt  GetLength() const;               // 0x1424442e0
    virtual UInt32 ReadNextPixel();                 // 0x142445f30
    virtual void   WriteNextPixel(UInt32 v);        // 0x142447390

    Instances::fl_utils::ByteArray* pBytes;         // +0x08
};

// Pixels read from / written to a Vector.<uint> from index 0 on (writes append past the end).
// 0x18 bytes; vftable 0x14314a950 (deleting dtor 0x14243dca0).
class VectorPixelProvider : public Render::DIPixelProvider
{
public:
    VectorPixelProvider(Instances::fl_vec::Vector_uint* pvector) : Index(0), pVector(pvector) {}

    virtual UPInt  GetLength() const;               // 0x1424442f0
    virtual UInt32 ReadNextPixel();                 // 0x142445f50
    virtual void   WriteNextPixel(UInt32 v);        // 0x1424473c0

    UInt32                            Index;        // +0x08
    Instances::fl_vec::Vector_uint*   pVector;      // +0x10
};

}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_display

#endif
