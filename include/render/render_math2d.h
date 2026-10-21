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

// (appended for the static text, sfr_gfx_05d) the parameter of the projection of p on the segment p1 p2 (0 for a
// degenerate segment; out of line in GFx_StaticText, 0x1425df980), and the distance of two points
template<class PointType>
CoordType PointToSegmentPos(const PointType& p1, const PointType& p2, const PointType& p)
{
    CoordType dx = p2.x - p1.x;
    CoordType dy = p2.y - p1.y;
    if (dx == 0 && dy == 0)
        return 0;
    return (dx * (p.x - p1.x) + dy * (p.y - p1.y)) / (dx * dx + dy * dy);
}
template<class PointType>
CoordType Distance(const PointType& p1, const PointType& p2)
{
    CoordType dx = p2.x - p1.x;
    CoordType dy = p2.y - p1.y;
    return sqrtf(dx * dx + dy * dy);
}

// (appended for the stroker, sfr_render_05b) path segment commands, the side of v of the line v1 v2, and where the
// lines a b and c d cross (false when nearly parallel). Intersection is inline; the exe keeps one out-of-line copy
// at 0x1426ae0a0 (Render_Hairliner).
const CoordType Pi = CoordType(3.14159265358979323846);
enum SegmentType
{
    Seg_MoveTo,
    Seg_LineTo,
    Seg_QuadTo,
    Seg_CubicTo,
    Seg_EndPath
};
template<class V1, class V2, class V3>
inline CoordType CrossProduct(const V1& v1, const V2& v2, const V3& v)
{
    return (v.x - v2.x) * (v2.y - v1.y) - (v.y - v2.y) * (v2.x - v1.x);
}
inline bool Intersection(CoordType ax, CoordType ay, CoordType bx, CoordType by, CoordType cx, CoordType cy,
                         CoordType dx, CoordType dy, CoordType* x, CoordType* y, CoordType epsilon)
{
    // a + u (b - a) on the line c d
    CoordType num = (ay - cy) * (dx - cx) - (ax - cx) * (dy - cy);
    CoordType den = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (fabsf(den) < epsilon)
        return false;
    CoordType u = num / den;
    *x          = ax + u * (bx - ax);
    *y          = ay + u * (by - ay);
    return true;
}

// (appended for the stroker, sfr_render_05b) the distance of two points given as coordinates
inline CoordType Distance(CoordType x1, CoordType y1, CoordType x2, CoordType y2)
{
    CoordType dx = x2 - x1;
    CoordType dy = y2 - y1;
    return sqrtf(dx * dx + dy * dy);
}

// (appended for the tessellator, sfr_render_05c) squared distance; the signed distance of (x, y) from the line
// p1 p2 (positive on the right, the plain distance to p1 for a degenerate line); a monotonic stand-in for the
// direction angle of p1 p2, in [-0.5, 0.5); and a monotonic stand-in for the turn angle at v2 (0 straight, -0.5 / 0.5
// a right angle left / right, -1 going back) given the two segment lengths
inline CoordType SqDistance(CoordType x1, CoordType y1, CoordType x2, CoordType y2)
{
    CoordType dx = x2 - x1;
    CoordType dy = y2 - y1;
    return dx * dx + dy * dy;
}
inline CoordType LinePointDistance(CoordType x1, CoordType y1, CoordType x2, CoordType y2, CoordType x, CoordType y)
{
    CoordType dx  = x2 - x1;
    CoordType dy  = y2 - y1;
    CoordType len = sqrtf(dx * dx + dy * dy);
    if (len == 0)
        return Distance(x1, y1, x, y);
    return ((x - x2) * dy - (y - y2) * dx) / len;
}
template<class V1, class V2, class V3>
inline CoordType LinePointDistance(const V1& v1, const V2& v2, const V3& v)
{
    return LinePointDistance(v1.x, v1.y, v2.x, v2.y, v.x, v.y);
}
inline CoordType SlopeRatio(CoordType x1, CoordType y1, CoordType x2, CoordType y2)
{
    CoordType dx  = x2 - x1;
    CoordType dy  = y2 - y1;
    CoordType den = (CoordType)(dx * dx + dy * dy) * 2;
    if (den == 0)
        return 0;
    CoordType r = (dx * dx) / den;
    if (dx < 0)
        r = -r;
    if (dy > 0)
        r = 1 - r;
    return r - 0.5f;
}
template<class V1, class V2>
inline CoordType SlopeRatio(const V1& v1, const V2& v2)
{
    return SlopeRatio(v1.x, v1.y, v2.x, v2.y);
}
template<class V1, class V2, class V3>
inline CoordType TurnRatio(const V1& v1, const V2& v2, const V3& v3, CoordType len1, CoordType len2)
{
    CoordType ax = v2.x - v1.x;
    CoordType ay = v2.y - v1.y;
    CoordType bx = v3.x - v2.x;
    CoordType by = v3.y - v2.y;
    CoordType r  = (ax * bx + ay * by) / (len1 * len2 * 2);
    if (bx * ay > by * ax)
        r = 1 - r;
    return r - 0.5f;
}

}}} // namespace Scaleform::Render::Math2D

#endif
