// Recovered Scaleform 4.1.18 Render: TessBase, the vertex sink curve flattening and the tessellators feed.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the leading virtuals are declared so far (slots checked against the exe callers in Render_TessCurves:
// GetLastX +0x10, GetLastY +0x18, AddVertex +0x20). A class implementing TessBase must append the rest in order
// (ClosePath, FinalizePath, Transform, StretchTo, vertex / mesh queries).
#ifndef MS2_SF_RENDER_TESSDEFS_H
#define MS2_SF_RENDER_TESSDEFS_H

#include "ms2/scaleform/include/render/render_toleranceparams.h"

namespace Scaleform { namespace Render {

typedef float CoordType;

class TessBase
{
public:
    virtual ~TessBase() {}
    virtual void      Clear() = 0;
    virtual CoordType GetLastX() const = 0;
    virtual CoordType GetLastY() const = 0;
    virtual void      AddVertex(CoordType x, CoordType y) = 0;
};

// Render_TessCurves (sfr_render_06c)
bool TestQuadCollinearity(TessBase* con, const ToleranceParams& param, CoordType x1, CoordType y1,
                          CoordType x2, CoordType y2, CoordType x3, CoordType y3);                    // 0x1426b8c90
void TessellateQuadCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                         CoordType x3, CoordType y3);                                                 // 0x1426b8790
void TessellateCubicCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                          CoordType x3, CoordType y3, CoordType x4, CoordType y4);                    // 0x1426b7f90

}} // namespace Scaleform::Render

#endif
