// Recovered Scaleform 4.1.18 Render: the pixel source/sink interface of DrawableImage::GetPixels / SetPixels, on its
// own so the AS3 BitmapData units (which see DrawableImage opaque) can implement it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// Base vftable 0x143149c28 (deleting dtor 0x14243e4f0, three pure slots).
#ifndef MS2_SF_RENDER_DIPIXELPROVIDER_H
#define MS2_SF_RENDER_DIPIXELPROVIDER_H

#include "ms2/scaleform/include/kernel/sf_types.h"

namespace Scaleform { namespace Render {

// Pixel source/sink for GetPixels / SetPixels (ARGB values in scan order).
class DIPixelProvider
{
public:
    virtual ~DIPixelProvider() {}
    virtual UPInt  GetLength() const = 0;
    virtual UInt32 ReadNextPixel() = 0;
    virtual void   WriteNextPixel(UInt32 v) = 0;
};

}} // namespace Scaleform::Render

#endif
