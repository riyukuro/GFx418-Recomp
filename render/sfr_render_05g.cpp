// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the hit test TU
// (Render_HitTest). Ray crossing counts for the quadratic and cubic edges of a fill, and the two stroke tests on a
// flattened path.
// Queue unit sfr_render_05 is split along its original sources (05g Render_HitTest).
// MS2-UNIT: sfr_render_05g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142679360-0x14267b120 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_hittest.h"
#include "ms2/scaleform/kernel/sf_arraystaticbuff.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

namespace Scaleform { namespace Render { namespace Math2D {

// a cubic curve as eight coordinates
struct CubicCurveCoord
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
};

// the quadratic pieces a cubic is approximated by: control and end point of each, the start being the previous end
class QuadCurvePath
{
public:
    struct QuadCoord
    {
        float cx, cy, ax, ay;
    };

    QuadCurvePath() : Quads(Memory::GetGlobalHeap()) {}

    void QuadTo(float cx, float cy, float ax, float ay)
    {
        QuadCoord q = { cx, cy, ax, ay };
        Quads.PushBack(q);
    }
    unsigned         GetQuadCount() const     { return (unsigned)Quads.GetSize(); }
    const QuadCoord& GetQuad(unsigned i) const { return Quads[i]; }

private:
    ArrayStaticBuffPOD<QuadCoord, 32> Quads;
};

// splits the cubic curve at t into c1 (start .. t) and c2 (t .. end)
// @0x142679700
template<class CurveType>
void SubdivideCubic(const CurveType& c, float t, CurveType* c1, CurveType* c2)
{
    // c1 or c2 may be c itself: everything is read before the first store
    float sx    = c.x1;
    float sy    = c.y1;
    float x12   = c.x1 + t * (c.x2 - c.x1);
    float y12   = c.y1 + t * (c.y2 - c.y1);
    float x23   = c.x2 + t * (c.x3 - c.x2);
    float y23   = c.y2 + t * (c.y3 - c.y2);
    float x34   = c.x3 + t * (c.x4 - c.x3);
    float y34   = c.y3 + t * (c.y4 - c.y3);
    float x123  = x12 + t * (x23 - x12);
    float y123  = y12 + t * (y23 - y12);
    float x234  = x23 + t * (x34 - x23);
    float y234  = y23 + t * (y34 - y23);
    float x1234 = x123 + t * (x234 - x123);
    float y1234 = y123 + t * (y234 - y123);
    float ex    = c.x4;
    float ey    = c.y4;
    c1->x1 = sx;
    c1->y1 = sy;
    c1->x2 = x12;
    c1->y2 = y12;
    c1->x3 = x123;
    c1->y3 = y123;
    c1->x4 = x1234;
    c1->y4 = y1234;
    c2->x1 = x1234;
    c2->y1 = y1234;
    c2->x2 = x234;
    c2->y2 = y234;
    c2->x3 = x34;
    c2->y3 = y34;
    c2->x4 = ex;
    c2->y4 = ey;
}

// approximates a cubic without inflections by quadratics: one quadratic whose control point is where the end
// tangents cross (their midpoint when nearly parallel), kept when it stays close to the cubic's midpoint, otherwise
// both halves of the cubic again
// @0x1426798f0
template<class PathType>
void SubdivideCubicToQuads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,
                           PathType& path)
{
    // the allowed error grows with the length of the control polygon
    float tol = Distance(x1, y1, x2, y2) + Distance(x2, y2, x3, y3) + Distance(x3, y3, x4, y4);
    tol *= 0.005f;

    float cx, cy;
    if (!Intersection(x1, y1, x2, y2, x3, y3, x4, y4, &cx, &cy, tol))
    {
        cx = (x2 + x3) / 2;
        cy = (y2 + y3) / 2;
    }

    // the quadratic's midpoint
    float ax = (x1 + cx) / 2;
    float ay = (y1 + cy) / 2;
    float bx = (cx + x4) / 2;
    float by = (cy + y4) / 2;
    float qx = (ax + bx) / 2;
    float qy = (ay + by) / 2;

    // the cubic's halves
    ax          = (x1 + x2) / 2;
    ay          = (y1 + y2) / 2;
    bx          = (x2 + x3) / 2;
    by          = (y2 + y3) / 2;
    float x34   = (x3 + x4) / 2;
    float y34   = (y3 + y4) / 2;
    float x123  = (ax + bx) / 2;
    float y123  = (ay + by) / 2;
    float x234  = (bx + x34) / 2;
    float y234  = (by + y34) / 2;
    float x1234 = (x123 + x234) / 2;
    float y1234 = (y123 + y234) / 2;

    // how far the quadratic strays from the cubic, judged at both midpoints
    float d = fabsf(fabsf(LinePointDistance(x1, y1, x4, y4, qx, qy)) -
                    fabsf(LinePointDistance(x1, y1, x4, y4, x1234, y1234))) +
              fabsf(LinePointDistance(x123, y123, x234, y234, qx, qy));
    if (d < tol)
    {
        path.QuadTo(cx, cy, x4, y4);
        return;
    }
    SubdivideCubicToQuads(x1, y1, ax, ay, x123, y123, x1234, y1234, path);
    SubdivideCubicToQuads(x1234, y1234, x234, y234, x34, y34, x4, y4, path);
}

// cuts the cubic at its inflection points (the roots of the cross product of the first and second derivatives
// inside 0 .. 1) and approximates each piece
// @0x142679360
template<class PathType>
void CubicToQuadratic(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, PathType& path)
{
    // the power basis: a t^3 + b t^2 + c t + start
    float ax  = -x1 + 3 * x2 - 3 * x3 + x4;
    float ay  = -y1 + 3 * y2 - 3 * y3 + y4;
    float bx  = 3 * x1 - 6 * x2 + 3 * x3;
    float by  = 3 * y1 - 6 * y2 + 3 * y3;
    float cx  = -3 * x1 + 3 * x2;
    float cy  = -3 * y1 + 3 * y2;
    float den = ay * bx - ax * by;

    float t1 = -1;
    float t2 = -1;
    if (den != 0)
    {
        float tc = -0.5f * (ay * cx - ax * cy) / den;
        float sq = sqrtf(tc * tc - (by * cx - bx * cy) / (3 * den));
        t1       = tc - sq;
        t2       = tc + sq;
    }

    unsigned        n = 1;
    CubicCurveCoord c;
    CubicCurveCoord parts[3];
    c.x1 = x1;
    c.y1 = y1;
    c.x2 = x2;
    c.y2 = y2;
    c.x3 = x3;
    c.y3 = y3;
    c.x4 = x4;
    c.y4 = y4;

    switch (int(t2 > 0 && t2 < 1) * 2 + int(t1 > 0 && t1 < 1))
    {
    case 0:
        parts[0] = c;
        n        = 1;
        break;
    case 1:
        SubdivideCubic(c, t1, &parts[0], &parts[1]);
        n = 2;
        break;
    case 2:
        SubdivideCubic(c, t2, &parts[0], &parts[1]);
        n = 2;
        break;
    case 3:
        if (t2 < t1)
        {
            float t = t1;
            t1      = t2;
            t2      = t;
        }
        SubdivideCubic(c, t1, &parts[0], &parts[1]);
        SubdivideCubic(parts[1], (t2 - t1) / (1 - t1), &parts[1], &parts[2]);
        n = 3;
        break;
    }

    for (unsigned i = 0; i < n; ++i)
    {
        const CubicCurveCoord& p = parts[i];
        SubdivideCubicToQuads(p.x1, p.y1, p.x2, p.y2, p.x3, p.y3, p.x4, p.y4, path);
    }
}

// a curve with y1 <= y2 <= y3: whether the ray from (x, y) to the left crosses it
// @0x14267a1d0
bool CheckMonoQuadIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{
    if (y >= y1 && y < y3)
    {
        // right of all three sides of the control triangle: crossed; left of all: not (bitwise, no branches)
        unsigned r1 = CrossProduct(x1, y1, x2, y2, x, y) > 0;
        unsigned r2 = CrossProduct(x2, y2, x3, y3, x, y) > 0;
        unsigned r3 = CrossProduct(x1, y1, x3, y3, x, y) > 0;
        if (r1 & r2 & r3)
            return true;
        if ((r1 ^ 1) & (r2 ^ 1) & (r3 ^ 1))
            return false;

        // otherwise the curve's x at y decides: t of the curve point at height y
        float den = y1 - 2 * y2 + y3;
        float t   = -1;
        if (den == 0)
        {
            // degenerates to a line
            den = y3 - y1;
            if (den != 0)
                t = (y - y1) / den;
        }
        else
        {
            // the root's discriminant, clamped against rounding
            t = -y1 * (y3 - y) + y2 * y2 - 2 * y * y2 + y * y3;
            t = (t > 0) ? sqrtf(t) : 0;
            t = (t + y1 - y2) / den;
        }
        return CalcPointOnQuadCurve1D(x1, x2, x3, t) < x;
    }
    return false;
}

// any quadratic with y1 <= y3: split at its y extremum into two monotonic halves
// @0x14267a420
bool CheckQuadIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{
    if (y2 >= y1 && y3 >= y2)
        return CheckMonoQuadIntersection(x1, y1, x2, y2, x3, y3, x, y);

    float den = 2 * y2 - y1 - y3;
    float t   = (den == 0) ? -1.0f : (y2 - y1) / den;

    QuadCoordType c1, c2;
    SubdivideQuadCurve(x1, y1, x2, y2, x3, y3, t, &c1, &c2);
    if (c1.y1 > c1.y3)
    {
        Alg::Swap(c1.x1, c1.x3);
        Alg::Swap(c1.y1, c1.y3);
    }
    if (c2.y1 > c2.y3)
    {
        Alg::Swap(c2.x1, c2.x3);
        Alg::Swap(c2.y1, c2.y3);
    }
    return CheckMonoQuadIntersection(c1.x1, c1.y1, c1.x2, c1.y2, c1.x3, c1.y3, x, y) ^
           CheckMonoQuadIntersection(c2.x1, c2.y1, c2.x2, c2.y2, c2.x3, c2.y3, x, y);
}

// @0x14267a680
int CheckQuadraticIntersection(int styleCount, float x1, float y1, float x2, float y2, float x3, float y3, float x,
                               float y)
{
    if (y1 > y3)
    {
        Alg::Swap(x1, x3);
        Alg::Swap(y1, y3);
    }
    if (CheckQuadIntersection(x1, y1, x2, y2, x3, y3, x, y))
        styleCount ^= 1;
    return styleCount;
}

// @0x142679fe0
int CheckCubicIntersection(int styleCount, float x1, float y1, float x2, float y2, float x3, float y3, float x4,
                           float y4, float x, float y)
{
    QuadCurvePath path;
    CubicToQuadratic(x1, y1, x2, y2, x3, y3, x4, y4, path);
    unsigned n = path.GetQuadCount();
    for (unsigned i = 0; i < n; ++i)
    {
        const QuadCurvePath::QuadCoord& q = path.GetQuad(i);
        styleCount = CheckQuadraticIntersection(styleCount, x1, y1, q.cx, q.cy, q.ax, q.ay, x, y);
        x1         = q.ax;
        y1         = q.ay;
    }
    return styleCount;
}

// out-of-line copy of the split (its callers here inline it)
// @0x142679ec0
template void SubdivideQuadCurve<QuadCoordType>(float, float, float, float, float, float, float, QuadCoordType*,
                                                QuadCoordType*);

} // namespace Math2D

// @0x14267ad80
bool HitTestRoundStroke(const VertexPath& path, float w, float x, float y)
{
    float    hw = w * 0.5f;
    unsigned i, j;
    for (i = 0; i < path.GetNumPaths(); ++i)
    {
        const PathBasic& p = path.GetPath(i);
        for (j = 1; j < p.Count; ++j)
        {
            const VertexBasic& v1 = path.GetVertex(p.Start + j - 1);
            const VertexBasic& v2 = path.GetVertex(p.Start + j);
            float              dx = v2.x - v1.x;
            float              dy = v2.y - v1.y;
            // the perpendiculars at both ends bound the band of the segment
            VertexBasic n1 = { v1.x - dy, v1.y + dx };
            VertexBasic n2 = { v2.x - dy, v2.y + dx };
            if (Math2D::CrossProduct(v1.x, v1.y, n1.x, n1.y, x, y) >= 0 &&
                Math2D::CrossProduct(v2.x, v2.y, n2.x, n2.y, x, y) <= 0 &&
                Math2D::LinePointDistanceAbs(v1.x, v1.y, v2.x, v2.y, x, y) <= hw)
                return true;
        }
    }
    // the round joins and caps
    hw *= hw;
    for (i = 0; i < path.GetNumVertices(); ++i)
    {
        const VertexBasic& v = path.GetVertex(i);
        if (Math2D::SqDistance(v.x, v.y, x, y) <= hw)
            return true;
    }
    return false;
}

// @0x14267a920
bool HitTestGeneralStroke(const VertexPath& path, float x, float y)
{
    int      winding = 0;
    unsigned i, j;
    for (i = 0; i < path.GetNumPaths(); ++i)
    {
        const PathBasic& p = path.GetPath(i);
        for (j = 1; j < p.Count; ++j)
        {
            VertexBasic v1 = path.GetVertex(p.Start + j - 1);
            VertexBasic v2 = path.GetVertex(p.Start + j);
            if (v1.y != v2.y)
            {
                // upward edges count +1, downward ones -1
                int dir = 1;
                if (v1.y > v2.y)
                {
                    Alg::Swap(v1, v2);
                    dir = -1;
                }
                if (y >= v1.y && y < v2.y && Math2D::CrossProduct(v1.x, v1.y, v2.x, v2.y, x, y) > 0)
                    winding += dir;
            }
        }
    }
    return winding != 0;
}

}} // namespace Scaleform::Render
