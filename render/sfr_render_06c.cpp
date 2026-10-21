// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the curve flattening TU
// (Render_TessCurves). Quadratic and cubic Bezier segments are cut into line segments fed to a TessBase: a quad
// that is (nearly) straight is emitted directly, otherwise both curves are halved recursively until the control
// points sit within the tolerance of the chord (cubic: the AGG distance / angle tests), at most 12 levels deep.
// Queue unit sfr_render_06 is split along its original sources (06c Render_TessCurves).
// MS2-UNIT: sfr_render_06c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426b7f90-0x1426b8f00 .text$mn

#include "ms2/scaleform/include/render/render_tessdefs.h"

#include <math.h>

namespace Scaleform { namespace Render {

void TessellateQuadRecursively(TessBase* con, CoordType tolSq, CoordType x1, CoordType y1, CoordType x2,
                               CoordType y2, CoordType x3, CoordType y3, int level);              // 0x1426b8a50
void TessellateCubicRecursively(TessBase* con, CoordType tolSq, CoordType x1, CoordType y1, CoordType x2,
                                CoordType y2, CoordType x3, CoordType y3, CoordType x4, CoordType y4,
                                int level);                                                        // 0x1426b8060

namespace {

const int       MaxDepth       = 12;
const CoordType MaxTurn        = 0.25f;     // radians a flat enough cubic may still turn
const CoordType StraightEps    = 1e-10f;
const CoordType PiF            = 3.14159265358979323846f;

inline CoordType SqDist(CoordType ax, CoordType ay, CoordType bx, CoordType by)
{
    CoordType dx = bx - ax;
    CoordType dy = by - ay;
    return dx * dx + dy * dy;
}

inline CoordType Dist(CoordType ax, CoordType ay, CoordType bx, CoordType by)
{
    CoordType dx = bx - ax;
    CoordType dy = by - ay;
    return sqrtf(dx * dx + dy * dy);
}

// |cross(b - a, p - b)|: twice the area of the triangle a b p.
inline CoordType AbsCross(CoordType ax, CoordType ay, CoordType bx, CoordType by, CoordType px, CoordType py)
{
    CoordType c = (px - bx) * (by - ay) - (py - by) * (bx - ax);
    return (c < 0.0f) ? -c : c;
}

} // namespace

// Flattens the cubic from the sink's last point through (x2,y2), (x3,y3) to (x4,y4).
void TessellateCubicCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                          CoordType x3, CoordType y3, CoordType x4, CoordType y4)
{
    CoordType x1 = con->GetLastX();
    CoordType y1 = con->GetLastY();
    CoordType tolSq = (param.CurveTolerance / 4) * (param.CurveTolerance / 4);
    TessellateCubicRecursively(con, tolSq, x1, y1, x2, y2, x3, y3, x4, y4, 0);
}

// Halves the cubic at t = 0.5 until both control points are close enough to the chord and the curve barely turns.
// The four cases split on which control points are off the line p1-p4.
void TessellateCubicRecursively(TessBase* con, CoordType tolSq, CoordType x1, CoordType y1, CoordType x2,
                                CoordType y2, CoordType x3, CoordType y3, CoordType x4, CoordType y4, int level)
{
    if (level > MaxDepth)
        return;

    // de Casteljau midpoints
    CoordType x12   = (x1 + x2) / 2;
    CoordType y12   = (y1 + y2) / 2;
    CoordType x23   = (x2 + x3) / 2;
    CoordType y23   = (y2 + y3) / 2;
    CoordType x34   = (x3 + x4) / 2;
    CoordType y34   = (y3 + y4) / 2;
    CoordType x123  = (x12 + x23) / 2;
    CoordType y123  = (y12 + y23) / 2;
    CoordType x234  = (x23 + x34) / 2;
    CoordType y234  = (y23 + y34) / 2;
    CoordType x1234 = (x123 + x234) / 2;
    CoordType y1234 = (y123 + y234) / 2;

    // distances of the control points from the chord (times its length)
    CoordType dx = x4 - x1;
    CoordType dy = y4 - y1;
    CoordType d2 = fabsf((x2 - x4) * dy - (y2 - y4) * dx);
    CoordType d3 = fabsf((x3 - x4) * dy - (y3 - y4) * dx);
    CoordType a1, a2, k;

    switch ((int(d2 > StraightEps) << 1) + int(d3 > StraightEps))
    {
    case 0:
        // everything on one line, or a closed loop p1 == p4
        k = dx * dx + dy * dy;
        if (k == 0)
        {
            d2 = SqDist(x1, y1, x2, y2);
            d3 = SqDist(x4, y4, x3, y3);
        }
        else
        {
            k  = 1 / k;
            a1 = x2 - x1;
            a2 = y2 - y1;
            d2 = k * (a1 * dx + a2 * dy);
            a1 = x3 - x1;
            a2 = y3 - y1;
            d3 = k * (a1 * dx + a2 * dy);
            if (d2 > 0 && d2 < 1 && d3 > 0 && d3 < 1)
            {
                // both control points inside the chord: a plain segment
                con->AddVertex(x4, y4);
                return;
            }
            if (d2 <= 0)
                d2 = SqDist(x2, y2, x1, y1);
            else if (d2 >= 1)
                d2 = SqDist(x2, y2, x4, y4);
            else
                d2 = SqDist(x2, y2, x1 + d2 * dx, y1 + d2 * dy);
            if (d3 <= 0)
                d3 = SqDist(x3, y3, x1, y1);
            else if (d3 >= 1)
                d3 = SqDist(x3, y3, x4, y4);
            else
                d3 = SqDist(x3, y3, x1 + d3 * dx, y1 + d3 * dy);
        }
        if (d2 < tolSq || d3 < tolSq)
        {
            con->AddVertex(x4, y4);
            return;
        }
        break;

    case 1:
        // only p3 off the line
        if (d3 * d3 <= tolSq * (dx * dx + dy * dy))
        {
            a1 = fabsf(atan2f(y4 - y3, x4 - x3) - atan2f(y3 - y2, x3 - x2));
            if (a1 >= PiF) a1 = 2 * PiF - a1;
            if (a1 < MaxTurn)
            {
                con->AddVertex(x4, y4);
                return;
            }
        }
        break;

    case 2:
        // only p2 off the line
        if (d2 * d2 <= tolSq * (dx * dx + dy * dy))
        {
            a1 = fabsf(atan2f(y3 - y2, x3 - x2) - atan2f(y2 - y1, x2 - x1));
            if (a1 >= PiF) a1 = 2 * PiF - a1;
            if (a1 < MaxTurn)
            {
                con->AddVertex(x4, y4);
                return;
            }
        }
        break;

    case 3:
        // the general case: flat enough and turning little at both joints
        if ((d2 + d3) * (d2 + d3) <= tolSq * (dx * dx + dy * dy))
        {
            k  = atan2f(y3 - y2, x3 - x2);
            a1 = fabsf((CoordType)(k - atan2((double)(y2 - y1), (double)(x2 - x1))));   // double atan2 here
            a2 = fabsf((CoordType)(atan2((double)(y4 - y3), (double)(x4 - x3)) - k));
            if (a1 >= PiF) a1 = 2 * PiF - a1;
            if (a2 >= PiF) a2 = 2 * PiF - a2;
            if (a1 + a2 < MaxTurn)
            {
                con->AddVertex(x4, y4);
                return;
            }
        }
        break;
    }

    TessellateCubicRecursively(con, tolSq, x1, y1, x12, y12, x123, y123, x1234, y1234, level + 1);
    TessellateCubicRecursively(con, tolSq, x1234, y1234, x234, y234, x34, y34, x4, y4, level + 1);
}

// Flattens the quad from the sink's last point through (x2,y2) to (x3,y3).
void TessellateQuadCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                         CoordType x3, CoordType y3)
{
    CoordType x1 = con->GetLastX();
    CoordType y1 = con->GetLastY();
    if (!TestQuadCollinearity(con, param, x1, y1, x2, y2, x3, y3))
    {
        CoordType tolSq = (param.CurveTolerance / 4) * (param.CurveTolerance / 4);
        TessellateQuadRecursively(con, tolSq, x1, y1, x2, y2, x3, y3, 0);
    }
}

// Halves the quad at t = 0.5 until the control point is within the tolerance of the chord.
void TessellateQuadRecursively(TessBase* con, CoordType tolSq, CoordType x1, CoordType y1, CoordType x2,
                               CoordType y2, CoordType x3, CoordType y3, int level)
{
    CoordType d = AbsCross(x1, y1, x3, y3, x2, y2);
    if (d == 0 || d * d <= tolSq * SqDist(x1, y1, x3, y3) || level >= MaxDepth)
    {
        con->AddVertex(x3, y3);
        return;
    }
    CoordType x12  = (x1 + x2) / 2;
    CoordType y12  = (y1 + y2) / 2;
    CoordType x23  = (x2 + x3) / 2;
    CoordType y23  = (y2 + y3) / 2;
    CoordType x123 = (x12 + x23) / 2;
    CoordType y123 = (y12 + y23) / 2;
    TessellateQuadRecursively(con, tolSq, x1, y1, x12, y12, x123, y123, level + 1);
    TessellateQuadRecursively(con, tolSq, x123, y123, x23, y23, x3, y3, level + 1);
}

// A quad whose control point lies (nearly) on the chord is emitted as its end point; when the control point lies
// outside the chord (the curve doubles back) the turning point is emitted first.
bool TestQuadCollinearity(TessBase* con, const ToleranceParams& param, CoordType x1, CoordType y1,
                          CoordType x2, CoordType y2, CoordType x3, CoordType y3)
{
    CoordType chordSq = SqDist(x1, y1, x3, y3);
    CoordType d       = AbsCross(x1, y1, x3, y3, x2, y2);
    CoordType tol     = param.CollinearityTolerance / 4;
    if (d * d <= tol * tol * chordSq)
    {
        // where the control point projects onto the chord (0..1 = between the ends)
        if (chordSq == 0)
            d = 2;
        else
            d = ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1)) / chordSq;
        if (d < 0 || d > 1)
        {
            CoordType d1 = Dist(x1, y1, x2, y2);
            CoordType d2 = Dist(x2, y2, x3, y3) + d1;
            if (d2 != 0)
            {
                // the point of maximal curvature, at t = |p1 p2| / (|p1 p2| + |p2 p3|)
                CoordType t   = d1 / d2;
                CoordType x12 = x1 + t * (x2 - x1);
                CoordType y12 = y1 + t * (y2 - y1);
                CoordType x23 = x2 + t * (x3 - x2);
                CoordType y23 = y2 + t * (y3 - y2);
                con->AddVertex(x12 + t * (x23 - x12), y12 + t * (y23 - y12));
            }
        }
        con->AddVertex(x3, y3);
        return true;
    }
    return false;
}

}} // namespace Scaleform::Render

// MS2-PIN: ?TessellateCubicRecursively@Render@Scaleform@@YAXPEAVTessBase@12@MMMMMMMMMH@Z 0x1426b8060
// MS2-PIN: ?TessellateQuadCurve@Render@Scaleform@@YAXPEAVTessBase@12@AEBUToleranceParams@12@MMMM@Z 0x1426b8790
// MS2-PIN: ?TestQuadCollinearity@Render@Scaleform@@YA_NPEAVTessBase@12@AEBUToleranceParams@12@MMMMMM@Z 0x1426b8c90
