// Recovered Scaleform 4.1.18 Render: the 2D curve helpers of Render_Math2D, as far as the recovered units use them
// (the shape bound boxes, sfr_render_03d). All inline.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_MATH2D_H
#define MS2_SF_RENDER_MATH2D_H

#include <math.h>

namespace Scaleform { namespace Render { namespace Math2D {

typedef float CoordType;

// the point at parameter t of the quadratic curve (x1 y1) (x2 y2) (x3 y3), by de Casteljau
inline void PointOnQuadCurve(CoordType x1, CoordType y1, CoordType x2, CoordType y2, CoordType x3, CoordType y3,
                             CoordType t, CoordType* x, CoordType* y)
{
    CoordType ax = x1 + t * (x2 - x1);
    CoordType ay = y1 + t * (y2 - y1);
    CoordType bx = x2 + t * (x3 - x2);
    CoordType by = y2 + t * (y3 - y2);
    *x           = ax + t * (bx - ax);
    *y           = ay + t * (by - ay);
}

// the same for the cubic curve over four points
inline void PointOnCubicCurve(CoordType x1, CoordType y1, CoordType x2, CoordType y2, CoordType x3, CoordType y3,
                              CoordType x4, CoordType y4, CoordType t, CoordType* x, CoordType* y)
{
    CoordType ax  = x1 + t * (x2 - x1);
    CoordType ay  = y1 + t * (y2 - y1);
    CoordType bx  = x2 + t * (x3 - x2);
    CoordType by  = y2 + t * (y3 - y2);
    CoordType cx  = x3 + t * (x4 - x3);
    CoordType cy  = y3 + t * (y4 - y3);
    CoordType abx = ax + t * (bx - ax);
    CoordType aby = ay + t * (by - ay);
    CoordType bcx = bx + t * (cx - bx);
    CoordType bcy = by + t * (cy - by);
    *x            = abx + t * (bcx - abx);
    *y            = aby + t * (bcy - aby);
}

// parameter of the extremum of one coordinate of a quadratic curve; -1 when it has none
inline CoordType QuadCurveExtremum(CoordType x1, CoordType x2, CoordType x3)
{
    CoordType den = 2 * x2 - x1 - x3;
    return (den == 0) ? -1 : (x2 - x1) / den;
}

// parameters of the (up to two) extrema of one coordinate of a cubic curve, -1 for a missing one
inline void CubicCurveExtremum(CoordType x1, CoordType x2, CoordType x3, CoordType x4, CoordType* t1, CoordType* t2)
{
    CoordType a   = x4 - 3 * x3 + 3 * x2 - x1;
    CoordType b   = x3 - 2 * x2 + x1;
    CoordType c   = x2 - x1;
    CoordType eps = 0.001f;
    *t1           = -1;
    *t2           = -1;
    if (fabsf(a) > eps)
    {
        CoordType disc = b * b - a * c;
        if (disc > 0)
        {
            disc = sqrtf(disc);
            *t1  = -(b - disc) / a;
            *t2  = -(b + disc) / a;
        }
        else if (disc == 0)
            *t1 = -b / a;
    }
    else if (fabsf(b) > eps)
        *t1 = -c / (2 * b);   // the derivative degenerates to a line
}

// (appended for the fill hit test, sfr_gfx_06e) which side of the line (x1 y1) (x2 y2) the point (x y) is on, and
// the ray crossings of a curve (Render_Math2D, out of line): styleCount toggled per crossing
inline CoordType CrossProduct(CoordType x1, CoordType y1, CoordType x2, CoordType y2, CoordType x, CoordType y)
{
    return (x - x2) * (y2 - y1) - (y - y2) * (x2 - x1);
}
int CheckQuadraticIntersection(int styleCount, float x1, float y1, float x2, float y2, float x3, float y3, float x,
                               float y);
int CheckCubicIntersection(int styleCount, float x1, float y1, float x2, float y2, float x3, float y3, float x4,
                           float y4, float x, float y);

}}} // namespace Scaleform::Render::Math2D

#endif
