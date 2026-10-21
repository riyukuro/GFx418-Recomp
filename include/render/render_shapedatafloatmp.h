// Recovered Scaleform 4.1.18 Render: ShapeDataFloatMP (Render_ShapeDataFloatMP), a shape mesh provider that owns the
// float shape data it draws, so code can build a shape and hand it to a TreeShape in one object.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x90 bytes: the ShapeMeshProvider part, then pData +0x88 (it takes the tail padding of the 16-aligned base).
// Constructor 0x142678490 and CountLayers 0x1426786e0 live in Render_ShapeDataFloatMP (no unit yet).
#ifndef MS2_SF_RENDER_SHAPEDATAFLOATMP_H
#define MS2_SF_RENDER_SHAPEDATAFLOATMP_H

#include "ms2/scaleform/include/render/render_meshprovider.h"

namespace Scaleform { namespace Render {

typedef ShapeDataFloatTempl<Array<UByte> > ShapeDataFloat;

class ShapeDataFloatMP : public ShapeMeshProvider
{
public:
    ShapeDataFloatMP();

    // the path building calls go straight to the owned shape data
    unsigned AddFillStyle(const FillStyleType& fill) { return pData->AddFillStyle(fill); }
    void     StartLayer()                            { pData->StartLayer(); }
    void     StartPath(unsigned fill0, unsigned fill1, unsigned stroke) { pData->StartPath(fill0, fill1, stroke); }
    void     MoveTo(float x, float y)                { pData->MoveTo(x, y); }
    void     LineTo(float x, float y)                { pData->LineTo(x, y); }
    void     EndPath()                               { pData->EndPath(); }

    // a closed axis-aligned rectangle as one path; the closing edge is skipped when the last corner is the first
    void RectanglePath(float x1, float y1, float x2, float y2)
    {
        pData->MoveTo(x1, y1);
        pData->LineTo(x2, y1);
        pData->LineTo(x2, y2);
        pData->LineTo(x1, y2);
        if (y2 != y1)
            pData->LineTo(x1, y1);
        pData->EndPath();
    }

    // builds the draw layers from the recorded data
    void CountLayers();

private:
    Ptr<ShapeDataFloat> pData;   // +0x88
};

}} // namespace Scaleform::Render

#endif
