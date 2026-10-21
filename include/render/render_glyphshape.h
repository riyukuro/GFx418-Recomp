// Recovered Scaleform 4.1.18 Render: what a font hands the glyph cache for one glyph at one hinted size, either an
// 8-bit coverage bitmap (GlyphRaster) or an outline in the packed integer path format (GlyphShape).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_GLYPHSHAPE_H
#define MS2_SF_RENDER_GLYPHSHAPE_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_shapedata.h"

namespace Scaleform { namespace Render {

// Width x Height coverage bytes; the origin is the pen position inside the bitmap.
class GlyphRaster : public RefCountBaseNTS<GlyphRaster, StatRender_Text_Mem>
{
public:
    GlyphRaster() : Width(0), Height(0), OriginX(0), OriginY(0), HintedSize(0) {}

    ArrayLH_POD<UByte> Raster;       // +0x10
    int                Width;        // +0x28
    int                Height;       // +0x2c
    int                OriginX;      // +0x30
    int                OriginY;      // +0x34
    unsigned           HintedSize;   // +0x38
};

// An outline the shape writer fills through the ShapeDataPacked path calls (multiplier 1, data of its own).
class GlyphShape : public ShapeDataPacked<ArrayLH_POD<UByte> >
{
    typedef ShapeDataPacked<ArrayLH_POD<UByte> > BaseType;

public:
    GlyphShape() : BaseType(&Data, 0, 1.0f), HintedSize(0) {}

    virtual bool IsEmpty() const { return Data.GetSize() == 0; }

    void     Clear() { Data.Resize(0); }
    void     SetHintedSize(unsigned size) { HintedSize = size; }
    unsigned GetHintedSize() const { return HintedSize; }

private:
    ArrayLH_POD<UByte> Data;         // +0x60
    unsigned           HintedSize;   // +0x78, in twips, 0 for an unhinted outline
    RectF              Bounds;       // +0x7c
};

}} // namespace Scaleform::Render

#endif
