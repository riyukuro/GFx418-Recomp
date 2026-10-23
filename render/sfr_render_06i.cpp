// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the anti-aliased stroker
// TU (Render_StrokerAA): construction, the per-path driver and the mesh accessors (the part in queue unit
// sfr_render_05; one TU with the rest, since FinalizePath inlines the width/cap/join helpers), caps, joins and the
// per-segment join window. A path is widened into a solid core plus an AA fringe on each side; every cap and join emits its edge vertices and the
// triangles bridging them to the previous ones (SolidL/R, TotalL/R).
// Queue unit sfr_render_06 is split along its original sources (06i Render_StrokerAA, 0x1426ae190 onwards, plus
// 0x1426ad030-0x1426ae0a0 from queue unit sfr_render_05).
// MS2-UNIT: sfr_render_06i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426ad030-0x1426ae0a0 .text$mn
// MS2-RANGE: 0x1426ae190-0x1426b2000 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/include/render/render_math2d.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

// the round caps/joins call the CRT atan2f import thunk (0x14280f28e); the symbol table's "atan2f" is another TU's
// cmath float wrapper (0x140a4e660), so the thunk is reached under its own name (as in sfr_render_05d). noalias
// keeps the optimiser's view of it the same as of the library atan2f
extern "C" __declspec(noalias) float __cdecl sfr_atan2f_thunk(float y, float x);

namespace Scaleform { namespace Render {

// true when the segments a b and c d cross, or are too close to parallel to tell
// @0x1426ae190
bool StrokerAA::MitersIntersect(CoordType ax, CoordType ay, CoordType bx, CoordType by, CoordType cx, CoordType cy,
                                CoordType dx, CoordType dy, CoordType epsilon)
{
    CoordType na  = (ay - cy) * (dx - cx) - (ax - cx) * (dy - cy);
    CoordType nb  = (bx - ax) * (ay - cy) - (by - ay) * (ax - cx);
    CoordType den = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (fabsf(den) < epsilon)
        return true;
    CoordType ua = na / den;
    CoordType ub = nb / den;
    return ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1;
}

// @0x1426ae280
void StrokerAA::SetToleranceParam(const ToleranceParams& param)
{
    Tolerance           = param.CurveTolerance;
    IntersectionEpsilon = param.IntersectionEpsilon;
}

// fits the vertices into the rectangle x1 y1 x2 y2 (bounds recomputed when empty); returns the way back
// @0x1426ae290
Matrix2F StrokerAA::StretchTo(float x1, float y1, float x2, float y2)
{
    Matrix2F m;
    UPInt    i;
    if (MinX >= MaxX || MinY >= MaxY)
    {
        MinX = MaxCoord;
        MinY = MaxCoord;
        MaxX = MinCoord;
        MaxY = MinCoord;
        for (i = 0; i < Vertices.GetSize(); ++i)
        {
            VertexType v = Vertices[i];
            if (v.x < MinX) MinX = v.x;
            if (v.y < MinY) MinY = v.y;
            if (v.x > MaxX) MaxX = v.x;
            if (v.y > MaxY) MaxY = v.y;
        }
    }
    if (MinX < MaxX && MinY < MaxY)
    {
        m.SetRectToRect(MinX, MinY, MaxX, MaxY, x1, y1, x2, y2);
        for (i = 0; i < Vertices.GetSize(); ++i)
        {
            VertexType& v = Vertices[i];
            m.Transform(&v.x, &v.y);
        }
        m.Invert();
    }
    return m;
}

// transforms every vertex in place and refreshes the bounds
// @0x1426ae580
void StrokerAA::Transform(const Matrix2F& m)
{
    UPInt i;
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    for (i = 0; i < Vertices.GetSize(); ++i)
    {
        VertexType& v = Vertices[i];
        m.Transform(&v.x, &v.y);
        if (v.x < MinX) MinX = v.x;
        if (v.y < MinY) MinY = v.y;
        if (v.x > MaxX) MaxX = v.x;
        if (v.y > MaxY) MaxY = v.y;
    }
}

// a bevelled join; with MiterJoin (miter limit exceeded) the bevel points are pulled part way towards the miter,
// half way between the solid and the total edge, which looks close to a clipped non-AA miter
// @0x1426ae8f0
void StrokerAA::calcBevelJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p, LineJoinType lineJoin)
{
    CoordType xSolid, ySolid, kSolid = 0;
    CoordType xTotal, yTotal, kTotal;
    CoordType d2, k2, x1, y1;
    unsigned  newSolidL, newTotalL, newSolidR, newTotalR;
    bool      overlap = p.overlapPrev | p.overlapThis;

    if (p.rightTurnThis)
    {
        // turning right: the left side is outer
        xTotal = overlap ? v1.x + p.dx1TotalR : p.xMiterThisR;
        yTotal = overlap ? v1.y + p.dy1TotalR : p.yMiterThisR;
        xSolid = v1.x + (xTotal - v1.x) * w.solidCoeffR;
        ySolid = v1.y + (yTotal - v1.y) * w.solidCoeffR;

        if (lineJoin == MiterJoin)
        {
            d2 = p.dSolidMiterL - p.dbSolidL;
            if (d2 == 0) d2 = 1;
            kSolid = w.totalLimitL - p.dbSolidL - w.totalWidthL + w.solidWidthL;
            if (kSolid > d2) kSolid = d2;
            k2     = w.solidLimitL - p.dbSolidL;
            kSolid = (kSolid + k2) / (2 * d2);

            d2 = p.dMiterThisL - p.dbTotalL;
            if (d2 == 0) d2 = 1;
            kTotal = w.totalLimitL - p.dbTotalL;
            k2     = w.solidLimitL - p.dbTotalL + w.totalWidthL - w.solidWidthL;
            kTotal = (kTotal + k2) / (2 * d2);

            x1 = v1.x - p.dx1SolidL;
            y1 = v1.y - p.dy1SolidL;
            newSolidL = addVertex(x1 + (p.xSolidMiterL - x1) * kSolid, y1 + (p.ySolidMiterL - y1) * kSolid, StyleLeft);
        }
        else
        {
            newSolidL = addVertex(v1.x - p.dx1SolidL, v1.y - p.dy1SolidL, StyleLeft);
            d2 = (p.dMiterThisL - p.dbTotalL);
            if (d2 == 0) d2 = 1;
            kTotal = (p.dbSolidL + w.totalWidthL - w.solidWidthL - p.dbTotalL) / d2;
        }

        if (w.aaFlagL)
        {
            x1 = v1.x - p.dx1TotalL;
            y1 = v1.y - p.dy1TotalL;
            newTotalL = addVertex(x1 + (p.xMiterThisL - x1) * kTotal, y1 + (p.yMiterThisL - y1) * kTotal, StyleLeft, 0);
        }
        else
        {
            newTotalL = newSolidL;
        }
        newSolidR = w.solidFlag ? addVertex(xSolid, ySolid, StyleRight) : newSolidL;
        newTotalR = w.aaFlagR ? addVertex(xTotal, yTotal, StyleRight, 0) : newSolidR;

        if (w.solidFlagL || w.solidFlagR)
        {
            addTriangle(SolidL, newSolidR, newSolidL);
            addTriangle(SolidL, SolidR, newSolidR);
        }
        if (w.aaFlagL)
        {
            addTriangle(TotalL, SolidL, newSolidL);
            addTriangle(TotalL, newSolidL, newTotalL);
        }
        if (w.aaFlagR)
        {
            addTriangle(SolidR, newTotalR, newSolidR);
            addTriangle(SolidR, TotalR, newTotalR);
        }

        SolidL = newSolidL;
        TotalL = newTotalL;
        SolidR = newSolidR;
        TotalR = newTotalR;
        if (overlap)
        {
            SolidR = addVertex(v1.x + p.dx2SolidR, v1.y + p.dy2SolidR, StyleRight);
            TotalR = w.aaFlagR ? addVertex(v1.x + p.dx2TotalR, v1.y + p.dy2TotalR, StyleRight, 0) : newSolidR;
        }

        // the second bevel point, unless the bevel is too short to matter
        if (w.totalWidthL - p.dbTotalL > Tolerance * 0.25f / 4)
        {
            if (w.solidFlag)
            {
                if (lineJoin == MiterJoin)
                {
                    x1 = v1.x - p.dx2SolidL;
                    y1 = v1.y - p.dy2SolidL;
                    newSolidL = addVertex(x1 + (p.xSolidMiterL - x1) * kSolid, y1 + (p.ySolidMiterL - y1) * kSolid,
                                          StyleLeft);
                }
                else
                {
                    newSolidL = addVertex(v1.x - p.dx2SolidL, v1.y - p.dy2SolidL, StyleLeft);
                }
            }
            if (w.aaFlagL)
            {
                x1 = v1.x - p.dx2TotalL;
                y1 = v1.y - p.dy2TotalL;
                newTotalL = addVertex(x1 + (p.xMiterThisL - x1) * kTotal, y1 + (p.yMiterThisL - y1) * kTotal,
                                      StyleLeft, 0);
            }
            else
            {
                newTotalL = newSolidL;
            }

            if (w.solidFlagL)
                addTriangle(SolidR, newSolidL, SolidL);
            if (w.aaFlagL)
            {
                addTriangle(SolidL, newSolidL, TotalL);
                addTriangle(TotalL, newSolidL, newTotalL);
            }
            SolidL = newSolidL;
            TotalL = newTotalL;
        }
    }
    else
    {
        // turning left: the right side is outer
        xTotal = overlap ? v1.x - p.dx1TotalL : p.xMiterThisL;
        yTotal = overlap ? v1.y - p.dy1TotalL : p.yMiterThisL;
        xSolid = v1.x + (xTotal - v1.x) * w.solidCoeffL;
        ySolid = v1.y + (yTotal - v1.y) * w.solidCoeffL;

        if (lineJoin == MiterJoin)
        {
            d2 = p.dSolidMiterR - p.dbSolidR;
            if (d2 == 0) d2 = 1;
            kSolid = w.totalLimitR - p.dbSolidR - w.totalWidthR + w.solidWidthR;
            if (kSolid > d2) kSolid = d2;
            k2     = w.solidLimitR - p.dbSolidR;
            kSolid = (kSolid + k2) / (2 * d2);

            d2 = p.dMiterThisR - p.dbTotalR;
            if (d2 == 0) d2 = 1;
            kTotal = w.totalLimitR - p.dbTotalR;
            k2     = w.solidLimitR - p.dbTotalR + w.totalWidthR - w.solidWidthR;
            kTotal = (kTotal + k2) / (2 * d2);

            x1 = v1.x + p.dx1SolidR;
            y1 = v1.y + p.dy1SolidR;
            newSolidR = addVertex(x1 + (p.xSolidMiterR - x1) * kSolid, y1 + (p.ySolidMiterR - y1) * kSolid, StyleRight);
        }
        else
        {
            newSolidR = addVertex(v1.x + p.dx1SolidR, v1.y + p.dy1SolidR, StyleRight);
            d2 = (p.dMiterThisR - p.dbTotalR);
            if (d2 == 0) d2 = 1;
            kTotal = (p.dbSolidR + w.totalWidthR - w.solidWidthR - p.dbTotalR) / d2;
        }

        if (w.aaFlagR)
        {
            x1 = v1.x + p.dx1TotalR;
            y1 = v1.y + p.dy1TotalR;
            newTotalR = addVertex(x1 + (p.xMiterThisR - x1) * kTotal, y1 + (p.yMiterThisR - y1) * kTotal, StyleRight, 0);
        }
        else
        {
            newTotalR = newSolidR;
        }
        newSolidL = w.solidFlag ? addVertex(xSolid, ySolid, StyleLeft) : newSolidR;
        newTotalL = w.aaFlagL ? addVertex(xTotal, yTotal, StyleLeft, 0) : newSolidL;

        if (w.solidFlagL || w.solidFlagR)
        {
            addTriangle(SolidR, newSolidR, newSolidL);
            addTriangle(SolidR, newSolidL, SolidL);
        }
        if (w.aaFlagR)
        {
            addTriangle(TotalR, newSolidR, SolidR);
            addTriangle(TotalR, newTotalR, newSolidR);
        }
        if (w.aaFlagL)
        {
            addTriangle(SolidL, newSolidL, newTotalL);
            addTriangle(SolidL, newTotalL, TotalL);
        }

        SolidL = newSolidL;
        TotalL = newTotalL;
        SolidR = newSolidR;
        TotalR = newTotalR;
        if (overlap)
        {
            SolidL = addVertex(v1.x - p.dx2SolidL, v1.y - p.dy2SolidL, StyleLeft);
            TotalL = w.aaFlagL ? addVertex(v1.x - p.dx2TotalL, v1.y - p.dy2TotalL, StyleLeft, 0) : newSolidL;
        }

        if (w.totalWidthR - p.dbTotalR > Tolerance * 0.25f / 4)
        {
            if (w.solidFlag)
            {
                if (lineJoin == MiterJoin)
                {
                    x1 = v1.x + p.dx2SolidR;
                    y1 = v1.y + p.dy2SolidR;
                    newSolidR = addVertex(x1 + (p.xSolidMiterR - x1) * kSolid, y1 + (p.ySolidMiterR - y1) * kSolid,
                                          StyleRight);
                }
                else
                {
                    newSolidR = addVertex(v1.x + p.dx2SolidR, v1.y + p.dy2SolidR, StyleRight);
                }
            }
            if (w.aaFlagR)
            {
                x1 = v1.x + p.dx2TotalR;
                y1 = v1.y + p.dy2TotalR;
                newTotalR = addVertex(x1 + (p.xMiterThisR - x1) * kTotal, y1 + (p.yMiterThisR - y1) * kTotal,
                                      StyleRight, 0);
            }
            else
            {
                newTotalR = newSolidR;
            }

            if (w.solidFlagR)
                addTriangle(SolidL, SolidR, newSolidR);
            if (w.aaFlagR)
            {
                addTriangle(SolidR, TotalR, newSolidR);
                addTriangle(TotalR, newTotalR, newSolidR);
            }
            SolidR = newSolidR;
            TotalR = newTotalR;
        }
    }
}

// a flat (or square) cap at v0 of the segment v0 v1; at the end of the path the sides are mirrored
// @0x1426af390
void StrokerAA::calcButtCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w,
                            bool endFlag)
{
    CoordType solidWidthL = endFlag ? w.solidWidthR : w.solidWidthL;
    CoordType solidWidthR = endFlag ? w.solidWidthL : w.solidWidthR;
    CoordType totalWidthL = endFlag ? w.totalWidthR : w.totalWidthL;
    CoordType totalWidthR = endFlag ? w.totalWidthL : w.totalWidthR;

    CoordType dx = (v1.y - v0.y) / len;
    CoordType dy = (v0.x - v1.x) / len;

    CoordType dxSolidL = dx * solidWidthL;
    CoordType dySolidL = dy * solidWidthL;
    CoordType dxSolidR = dx * solidWidthR;
    CoordType dySolidR = dy * solidWidthR;
    CoordType dxTotalL = dx * totalWidthL;
    CoordType dyTotalL = dy * totalWidthL;
    CoordType dxTotalR = dx * totalWidthR;
    CoordType dyTotalR = dy * totalWidthR;

    // the fringe beyond the end, as wide as the average side fringe
    dx = ((dyTotalL - dySolidL) + (dyTotalR - dySolidR)) / 2;
    dy = ((dxSolidL - dxTotalL) + (dxSolidR - dxTotalR)) / 2;

    unsigned buttSolidL = 0, buttSolidR = 0;
    unsigned buttTotalL = 0, buttTotalR = 0;

    bool aaFlagL = endFlag ? w.aaFlagR : w.aaFlagL;
    bool aaFlagR = endFlag ? w.aaFlagL : w.aaFlagR;

    if (w.aaFlagL || w.aaFlagR)
    {
        buttSolidL = addVertex(v0.x - dxSolidL + dx, v0.y - dySolidL + dy, StyleLeft, 0);
        buttSolidR = w.solidFlag ? addVertex(v0.x + dxSolidR + dx, v0.y + dySolidR + dy, StyleRight, 0) : buttSolidL;
        buttTotalL = aaFlagL ? addVertex(v0.x - dxTotalL + dx, v0.y - dyTotalL + dy, StyleLeft, 0) : buttSolidL;
        buttTotalR = aaFlagR ? addVertex(v0.x + dxTotalR + dx, v0.y + dyTotalR + dy, StyleRight, 0) : buttSolidR;
    }

    if (!endFlag)
    {
        SolidL = addVertex(v0.x - dxSolidL, v0.y - dySolidL, StyleLeft);
        TotalL = w.aaFlagL ? addVertex(v0.x - dxTotalL, v0.y - dyTotalL, StyleLeft, 0) : SolidL;
        SolidR = w.solidFlag ? addVertex(v0.x + dxSolidR, v0.y + dySolidR, StyleRight) : SolidL;
        TotalR = w.aaFlagR ? addVertex(v0.x + dxTotalR, v0.y + dyTotalR, StyleRight, 0) : SolidR;
    }
    else
    {
        Alg::Swap(TotalL, TotalR);
        Alg::Swap(SolidL, SolidR);
    }

    if ((w.aaFlagL || w.aaFlagR) && (w.solidFlagL || w.solidFlagR))
    {
        addTriangle(buttSolidL, buttSolidR, SolidL);
        addTriangle(SolidL, buttSolidR, SolidR);
    }
    if (aaFlagL)
    {
        addTriangle(SolidL, TotalL, buttTotalL);
        addTriangle(SolidL, buttTotalL, buttSolidL);
    }
    if (aaFlagR)
    {
        addTriangle(SolidR, buttTotalR, TotalR);
        addTriangle(SolidR, buttSolidR, buttTotalR);
    }
}

// a plain join with no corner fill: the next segment simply restarts at v1
// @0x1426af810
void StrokerAA::calcButtJoin(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w)
{
    CoordType dx = (v1.y - v0.y) / len;
    CoordType dy = (v0.x - v1.x) / len;

    JoinParamType p;
    p.dx1SolidL = dx * w.solidWidthL;
    p.dy1SolidL = dy * w.solidWidthL;
    p.dx1SolidR = dx * w.solidWidthR;
    p.dy1SolidR = dy * w.solidWidthR;
    p.dx1TotalL = dx * w.totalWidthL;
    p.dy1TotalL = dy * w.totalWidthL;
    p.dx1TotalR = dx * w.totalWidthR;
    p.dy1TotalR = dy * w.totalWidthR;

    unsigned newSolidL, newTotalL, newSolidR, newTotalR;
    newSolidL = addVertex(v1.x - p.dx1SolidL, v1.y - p.dy1SolidL, StyleLeft);
    newTotalL = w.aaFlagL ? addVertex(v1.x - p.dx1TotalL, v1.y - p.dy1TotalL, StyleLeft, 0) : newSolidL;
    newSolidR = w.solidFlag ? addVertex(v1.x + p.dx1SolidR, v1.y + p.dy1SolidR, StyleRight) : newSolidL;
    newTotalR = w.aaFlagR ? addVertex(v1.x + p.dx1TotalR, v1.y + p.dy1TotalR, StyleRight, 0) : newSolidR;

    if (w.solidFlagL || w.solidFlagR)
    {
        addTriangle(SolidL, newSolidR, newSolidL);
        addTriangle(SolidL, SolidR, newSolidR);
    }
    if (w.aaFlagL)
    {
        addTriangle(TotalL, SolidL, newSolidL);
        addTriangle(TotalL, newSolidL, newTotalL);
    }
    if (w.aaFlagR)
    {
        addTriangle(SolidR, newTotalR, newSolidR);
        addTriangle(SolidR, TotalR, newTotalR);
    }

    SolidL = newSolidL;
    TotalL = newTotalL;
    SolidR = newSolidR;
    TotalR = newTotalR;
}

// @0x1426afa70
void StrokerAA::calcCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w,
                        bool endFlag)
{
    switch (endFlag ? EndLineCap : StartLineCap)
    {
    case ButtCap:
    case SquareCap: calcButtCap(v0, v1, len, w, endFlag); break;
    case RoundCap:  calcRoundCap(v0, v1, len, w, endFlag); break;
    }
}

// primes the join window with the first segment v1 v2 (only the "next" slots)
// @0x1426afab0
void StrokerAA::calcInitialJoinParam(const StrokeVertex& v1, const StrokeVertex& v2, const WidthsType& w,
                                     JoinParamType& p)
{
    CoordType dx = (v2.y - v1.y) / v1.dist;
    CoordType dy = (v1.x - v2.x) / v1.dist;
    p.dx3SolidL = dx * w.solidWidthL;
    p.dy3SolidL = dy * w.solidWidthL;
    p.dx3SolidR = dx * w.solidWidthR;
    p.dy3SolidR = dy * w.solidWidthR;
    p.dx3TotalL = dx * w.totalWidthL;
    p.dy3TotalL = dy * w.totalWidthL;
    p.dx3TotalR = dx * w.totalWidthR;
    p.dy3TotalR = dy * w.totalWidthR;
    p.xMiterNextL = v1.x - p.dx3TotalL;
    p.yMiterNextL = v1.y - p.dy3TotalL;
    p.xMiterNextR = v1.x + p.dx3TotalR;
    p.yMiterNextR = v1.y + p.dy3TotalR;
    p.dMiterNextL = w.totalWidthL;
    p.dMiterNextR = w.totalWidthR;
    p.badMiterNextL = p.badMiterNextR = p.rightTurnNext = p.overlapThis = false;
}

// advances the window to v1 v2 v3, then emits the join at v1 in the configured style
// @0x1426afbb0
void StrokerAA::calcJoin(const StrokeVertex& v1, const StrokeVertex& v2, const StrokeVertex& v3, const WidthsType& w,
                         JoinParamType& p)
{
    calcJoinParam(v1, v2, v3, w, p);
    switch (LineJoin)
    {
    case MiterJoin:
    case MiterBevelJoin: calcMiterJoin(v1, w, p, LineJoin); break;
    case RoundJoin:      calcRoundJoin(v1, w, p); break;
    case BevelJoin:      calcBevelJoin(v1, w, p, BevelJoin); break;
    }
}

// slides the window one segment on: offsets and miters move this -> prev and next -> this, and the new next miter
// is intersected on the wider side and mirrored to the other one
// @0x1426afc50
void StrokerAA::calcJoinParam(const StrokeVertex& v1, const StrokeVertex& v2, const StrokeVertex& v3,
                              const WidthsType& w, JoinParamType& p)
{
    p.dx1SolidL = p.dx2SolidL;
    p.dy1SolidL = p.dy2SolidL;
    p.dx1SolidR = p.dx2SolidR;
    p.dy1SolidR = p.dy2SolidR;
    p.dx1TotalL = p.dx2TotalL;
    p.dy1TotalL = p.dy2TotalL;
    p.dx1TotalR = p.dx2TotalR;
    p.dy1TotalR = p.dy2TotalR;

    p.dx2SolidL = p.dx3SolidL;
    p.dy2SolidL = p.dy3SolidL;
    p.dx2SolidR = p.dx3SolidR;
    p.dy2SolidR = p.dy3SolidR;
    p.dx2TotalL = p.dx3TotalL;
    p.dy2TotalL = p.dy3TotalL;
    p.dx2TotalR = p.dx3TotalR;
    p.dy2TotalR = p.dy3TotalR;

    CoordType dx = (v3.y - v2.y) / v2.dist;
    CoordType dy = (v2.x - v3.x) / v2.dist;
    p.dx3SolidL = dx * w.solidWidthL;
    p.dy3SolidL = dy * w.solidWidthL;
    p.dx3SolidR = dx * w.solidWidthR;
    p.dy3SolidR = dy * w.solidWidthR;
    p.dx3TotalL = dx * w.totalWidthL;
    p.dy3TotalL = dy * w.totalWidthL;
    p.dx3TotalR = dx * w.totalWidthR;
    p.dy3TotalR = dy * w.totalWidthR;

    p.xMiterPrevL = p.xMiterThisL;
    p.yMiterPrevL = p.yMiterThisL;
    p.xMiterPrevR = p.xMiterThisR;
    p.yMiterPrevR = p.yMiterThisR;
    p.dMiterPrevL = p.dMiterThisL;
    p.dMiterPrevR = p.dMiterThisR;

    p.xMiterThisL = p.xMiterNextL;
    p.yMiterThisL = p.yMiterNextL;
    p.xMiterThisR = p.xMiterNextR;
    p.yMiterThisR = p.yMiterNextR;
    p.dMiterThisL = p.dMiterNextL;
    p.dMiterThisR = p.dMiterNextR;

    p.badMiterPrevL = p.badMiterThisL;
    p.badMiterPrevR = p.badMiterThisR;
    p.badMiterThisL = p.badMiterNextL;
    p.badMiterThisR = p.badMiterNextR;

    // a rough intersection tolerance scaled by the two segment lengths
    CoordType epsilon            = (v2.dist + v3.dist) * IntersectionEpsilon;
    bool      intersectionFailed = true;

    if (w.rightSideCalc)
    {
        // db = distance from v1 to the bevel midpoint
        dx = (p.dx1TotalR + p.dx2TotalR) / 2;
        dy = (p.dy1TotalR + p.dy2TotalR) / 2;
        p.dbTotalR = sqrtf(dx * dx + dy * dy);
        p.dbSolidR = p.dbTotalR * w.solidCoeffR;
        p.dbTotalL = p.dbTotalR * w.widthCoeff;
        p.dbSolidL = p.dbTotalL * w.solidCoeffL;

        if (Math2D::Intersection(v1.x + p.dx2TotalR, v1.y + p.dy2TotalR, v2.x + p.dx2TotalR, v2.y + p.dy2TotalR,
                                 v2.x + p.dx3TotalR, v2.y + p.dy3TotalR, v3.x + p.dx3TotalR, v3.y + p.dy3TotalR,
                                 &p.xMiterNextR, &p.yMiterNextR, epsilon))
        {
            p.dMiterNextR = Math2D::Distance(v2.x, v2.y, p.xMiterNextR, p.yMiterNextR);
            p.dMiterNextL = p.dMiterNextR * w.widthCoeff;
            p.xMiterNextL = v2.x - (p.xMiterNextR - v2.x) * w.widthCoeff;
            p.yMiterNextL = v2.y - (p.yMiterNextR - v2.y) * w.widthCoeff;
            intersectionFailed = p.badMiterNextL = p.badMiterNextR = false;
        }
    }
    else
    {
        dx = (p.dx1TotalL + p.dx2TotalL) / 2;
        dy = (p.dy1TotalL + p.dy2TotalL) / 2;
        p.dbTotalL = sqrtf(dx * dx + dy * dy);
        p.dbSolidL = p.dbTotalL * w.solidCoeffL;
        p.dbTotalR = p.dbTotalL * w.widthCoeff;
        p.dbSolidR = p.dbTotalR * w.solidCoeffR;

        if (Math2D::Intersection(v1.x - p.dx2TotalL, v1.y - p.dy2TotalL, v2.x - p.dx2TotalL, v2.y - p.dy2TotalL,
                                 v2.x - p.dx3TotalL, v2.y - p.dy3TotalL, v3.x - p.dx3TotalL, v3.y - p.dy3TotalL,
                                 &p.xMiterNextL, &p.yMiterNextL, epsilon))
        {
            p.dMiterNextL = Math2D::Distance(v2.x, v2.y, p.xMiterNextL, p.yMiterNextL);
            p.dMiterNextR = p.dMiterNextL * w.widthCoeff;
            p.xMiterNextR = v2.x - (p.xMiterNextL - v2.x) * w.widthCoeff;
            p.yMiterNextR = v2.y - (p.yMiterNextL - v2.y) * w.widthCoeff;
            intersectionFailed = p.badMiterNextL = p.badMiterNextR = false;
        }
    }

    p.rightTurnPrev = p.rightTurnThis;
    p.rightTurnThis = p.rightTurnNext;
    p.rightTurnNext = Math2D::CrossProduct(v1, v2, v3) > 0;

    if (intersectionFailed)
    {
        // (nearly) collinear segments: either straight on, or a full turn back
        dx = w.rightSideCalc ? v2.x + p.dx2TotalR : v2.x - p.dx2TotalL;
        dy = w.rightSideCalc ? v2.y + p.dy2TotalR : v2.y - p.dy2TotalL;
        if ((Math2D::CrossProduct(v1.x, v1.y, v2.x, v2.y, dx, dy) < 0) ==
            (Math2D::CrossProduct(v2.x, v2.y, v3.x, v3.y, dx, dy) < 0))
        {
            p.xMiterNextL   = v2.x - p.dx2TotalL;
            p.yMiterNextL   = v2.y - p.dy2TotalL;
            p.dMiterNextL   = w.totalLimitL;
            p.xMiterNextR   = v2.x + p.dx2TotalR;
            p.yMiterNextR   = v2.y + p.dy2TotalR;
            p.dMiterNextR   = w.totalLimitR;
            p.badMiterNextL = p.badMiterNextR = false;
        }
        else
        {
            dx = v2.x - (v1.x + v3.x) / 2;
            dy = v2.y - (v1.y + v3.y) / 2;
            if (p.rightTurnNext)
            {
                p.xMiterNextR   = v2.x + p.dx2TotalR;
                p.yMiterNextR   = v2.y + p.dy2TotalR;
                p.dMiterNextR   = w.totalLimitR;
                p.badMiterNextR = true;
                p.xMiterNextL   = v2.x + dx * 1024;
                p.yMiterNextL   = v2.y + dy * 1024;
                p.dMiterNextL   = Math2D::Distance(v2.x, v2.y, p.xMiterNextL, p.yMiterNextL);
                p.badMiterNextL = false;
            }
            else
            {
                p.xMiterNextL   = v2.x - p.dx2TotalL;
                p.yMiterNextL   = v2.y - p.dy2TotalL;
                p.dMiterNextL   = w.totalLimitL;
                p.badMiterNextL = true;
                p.xMiterNextR   = v2.x + dx * 1024;
                p.yMiterNextR   = v2.y + dy * 1024;
                p.dMiterNextR   = Math2D::Distance(v2.x, v2.y, p.xMiterNextR, p.yMiterNextR);
                p.badMiterNextR = false;
            }
        }
    }

    p.overlapPrev = p.overlapThis;
    p.overlapThis = p.rightTurnThis ? p.badMiterThisR : p.badMiterThisL;
    if (!p.overlapThis)
        p.overlapThis = MitersIntersect(p.xMiterThisL, p.yMiterThisL, p.xMiterThisR, p.yMiterThisR, p.xMiterNextL,
                                        p.yMiterNextL, p.xMiterNextR, p.yMiterNextR, epsilon);

    p.xSolidMiterL = v1.x + (p.xMiterThisL - v1.x) * w.solidCoeffL;
    p.ySolidMiterL = v1.y + (p.yMiterThisL - v1.y) * w.solidCoeffL;
    p.xSolidMiterR = v1.x + (p.xMiterThisR - v1.x) * w.solidCoeffR;
    p.ySolidMiterR = v1.y + (p.yMiterThisR - v1.y) * w.solidCoeffR;
    p.dSolidMiterL = p.dMiterThisL * w.solidCoeffL;
    p.dSolidMiterR = p.dMiterThisR * w.solidCoeffR;
}

// a miter join; past the miter limit MiterJoin/MiterBevelJoin fall back to a bevel
// @0x1426b0610
void StrokerAA::calcMiterJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p, LineJoinType lineJoin)
{
    CoordType xSolidL, ySolidL, xSolidR, ySolidR;
    CoordType xTotalL, yTotalL, xTotalR, yTotalR;
    unsigned  newSolidL, newTotalL, newSolidR, newTotalR;
    bool      overlap = p.overlapPrev | p.overlapThis;

    if (p.rightTurnThis)
    {
        // outer side left
        xTotalL = p.xMiterThisL;
        yTotalL = p.yMiterThisL;
        xSolidL = v1.x + (xTotalL - v1.x) * w.solidCoeffL;
        ySolidL = v1.y + (yTotalL - v1.y) * w.solidCoeffL;
        if (p.dMiterThisL > w.totalLimitL)
        {
            switch (lineJoin)
            {
            case MiterJoin:
            case MiterBevelJoin: calcBevelJoin(v1, w, p, lineJoin); return;
            default: break;
            }
        }
        // inner side right
        xTotalR = overlap ? v1.x + p.dx1TotalR : p.xMiterThisR;
        yTotalR = overlap ? v1.y + p.dy1TotalR : p.yMiterThisR;
        xSolidR = v1.x + (xTotalR - v1.x) * w.solidCoeffR;
        ySolidR = v1.y + (yTotalR - v1.y) * w.solidCoeffR;
    }
    else
    {
        // outer side right
        xTotalR = p.xMiterThisR;
        yTotalR = p.yMiterThisR;
        xSolidR = v1.x + (xTotalR - v1.x) * w.solidCoeffR;
        ySolidR = v1.y + (yTotalR - v1.y) * w.solidCoeffR;
        if (p.dMiterThisR > w.totalLimitR)
        {
            switch (lineJoin)
            {
            case MiterJoin:
            case MiterBevelJoin: calcBevelJoin(v1, w, p, lineJoin); return;
            default: break;
            }
        }
        // inner side left
        xTotalL = overlap ? v1.x - p.dx1TotalL : p.xMiterThisL;
        yTotalL = overlap ? v1.y - p.dy1TotalL : p.yMiterThisL;
        xSolidL = v1.x + (xTotalL - v1.x) * w.solidCoeffL;
        ySolidL = v1.y + (yTotalL - v1.y) * w.solidCoeffL;
    }

    newSolidL = addVertex(xSolidL, ySolidL, StyleLeft);
    newTotalL = w.aaFlagL ? addVertex(xTotalL, yTotalL, StyleLeft, 0) : newSolidL;
    newSolidR = w.solidFlag ? addVertex(xSolidR, ySolidR, StyleRight) : newSolidL;
    newTotalR = w.aaFlagR ? addVertex(xTotalR, yTotalR, StyleRight, 0) : newSolidR;

    if (w.solidFlagL || w.solidFlagR)
    {
        addTriangle(SolidL, newSolidR, newSolidL);
        addTriangle(SolidL, SolidR, newSolidR);
    }
    if (w.aaFlagL)
    {
        addTriangle(TotalL, SolidL, newSolidL);
        addTriangle(TotalL, newSolidL, newTotalL);
    }
    if (w.aaFlagR)
    {
        addTriangle(SolidR, newTotalR, newSolidR);
        addTriangle(SolidR, TotalR, newTotalR);
    }

    SolidL = newSolidL;
    TotalL = newTotalL;
    SolidR = newSolidR;
    TotalR = newTotalR;

    if (overlap)
    {
        if (p.rightTurnThis)
        {
            SolidR = addVertex(v1.x + p.dx2SolidR, v1.y + p.dy2SolidR, StyleRight);
            TotalR = w.aaFlagR ? addVertex(v1.x + p.dx2TotalR, v1.y + p.dy2TotalR, StyleRight, 0) : newSolidR;
        }
        else
        {
            SolidL = addVertex(v1.x - p.dx2SolidL, v1.y - p.dy2SolidL, StyleLeft);
            TotalL = w.aaFlagL ? addVertex(v1.x - p.dx2TotalL, v1.y - p.dy2TotalL, StyleLeft, 0) : newSolidL;
        }
    }
}

// a half-circle cap at v0, fanned around the cap centre in steps sized by the curve tolerance
// @0x1426b0a70
void StrokerAA::calcRoundCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w,
                             bool endFlag)
{
    CoordType solidWidthL = endFlag ? w.solidWidthR : w.solidWidthL;
    CoordType solidWidthR = endFlag ? w.solidWidthL : w.solidWidthR;
    CoordType totalWidthL = endFlag ? w.totalWidthR : w.totalWidthL;
    CoordType totalWidthR = endFlag ? w.totalWidthL : w.totalWidthR;

    CoordType dx = (v1.y - v0.y) / len;
    CoordType dy = (v0.x - v1.x) / len;

    CoordType dxSolidL = dx * solidWidthL;
    CoordType dySolidL = dy * solidWidthL;
    CoordType dxSolidR = dx * solidWidthR;
    CoordType dySolidR = dy * solidWidthR;
    CoordType dxTotalL = dx * totalWidthL;
    CoordType dyTotalL = dy * totalWidthL;
    CoordType dxTotalR = dx * totalWidthR;
    CoordType dyTotalR = dy * totalWidthR;

    CoordType a1 = sfr_atan2f_thunk(-dyTotalL, -dxTotalL);
    CoordType a2 = a1 + Math2D::Pi;
    CoordType da = acosf(w.totalWidth / (w.totalWidth + 0.25f * Tolerance)) * 2;
    int       i;
    int       n = int((a2 - a1) / da) + 1;
    da = (a2 - a1) / n;
    a1 += da;

    if (endFlag)
    {
        SolidL = SolidR;
        TotalL = TotalR;
    }
    else
    {
        SolidL = SolidR = addVertex(v0.x - dxSolidL, v0.y - dySolidL, StyleLeft);
        TotalL = TotalR = (w.aaFlagL || w.aaFlagR) ? addVertex(v0.x - dxTotalL, v0.y - dyTotalL, StyleLeft, 0) : SolidL;
    }

    CoordType cxTotal = v0.x + (dxTotalR - dxTotalL) / 2;
    CoordType cyTotal = v0.y + (dyTotalR - dyTotalL) / 2;
    CoordType cxSolid = v0.x + (dxSolidR - dxSolidL) / 2;
    CoordType cySolid = v0.y + (dySolidR - dySolidL) / 2;

    for (i = 0; i < n; i++)
    {
        dx = cosf(a1);
        dy = sinf(a1);

        CoordType xTotal = cxTotal + dx * w.totalWidth;
        CoordType yTotal = cyTotal + dy * w.totalWidth;
        unsigned  newSolid, newTotal;
        CoordType xSolid = cxSolid + dx * w.solidWidth;
        CoordType ySolid = cySolid + dy * w.solidWidth;

        newSolid = w.solidFlag ? addVertex(xSolid, ySolid, endFlag ? StyleLeft : StyleRight) : SolidL;
        newTotal = (w.aaFlagL || w.aaFlagR) ? addVertex(xTotal, yTotal, endFlag ? StyleLeft : StyleRight, 0) : newSolid;

        if (endFlag)
        {
            if (w.solidFlagL || w.solidFlagR)
                addTriangle(SolidL, newSolid, SolidR);
            if (w.aaFlagL || w.aaFlagR)
            {
                addTriangle(SolidL, TotalL, newTotal);
                addTriangle(SolidL, newTotal, newSolid);
            }
            SolidL = newSolid;
            TotalL = newTotal;
        }
        else
        {
            if (w.solidFlagL || w.solidFlagR)
                addTriangle(SolidL, SolidR, newSolid);
            if (w.aaFlagL || w.aaFlagR)
            {
                addTriangle(SolidR, TotalR, newTotal);
                addTriangle(SolidR, newTotal, newSolid);
            }
            SolidR = newSolid;
            TotalR = newTotal;
        }
        a1 += da;
    }
}

// a round join: the inner side as a miter, the outer side as an arc around v1 (a plain miter when the arc would be
// shorter than the tolerance)
// MS2-FUNCTIONAL: operand-load vs sign-mask-load order before the first atan2f differs (the renamed CRT thunk extern changes scheduling)
// @0x1426b1630
void StrokerAA::calcRoundJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p)
{
    CoordType xSolid, ySolid;
    CoordType xTotal, yTotal;
    CoordType dx, dy, a1, a2, da;
    unsigned  newSolidL, newTotalL, newSolidR, newTotalR;
    int       i, n;
    bool      overlap = p.overlapPrev | p.overlapThis;

    if (p.rightTurnThis)
    {
        if ((2 * w.solidWidthR - p.dbTotalR) < Tolerance * (0.25f / 2))
        {
            calcMiterJoin(v1, w, p, MiterJoin);
            return;
        }

        xTotal = overlap ? v1.x + p.dx1TotalR : p.xMiterThisR;
        yTotal = overlap ? v1.y + p.dy1TotalR : p.yMiterThisR;
        xSolid = v1.x + (xTotal - v1.x) * w.solidCoeffR;
        ySolid = v1.y + (yTotal - v1.y) * w.solidCoeffR;

        newSolidL = addVertex(v1.x - p.dx1SolidL, v1.y - p.dy1SolidL, StyleLeft);
        newTotalL = w.aaFlagL ? addVertex(v1.x - p.dx1TotalL, v1.y - p.dy1TotalL, StyleLeft, 0) : newSolidL;
        newSolidR = w.solidFlag ? addVertex(xSolid, ySolid, StyleRight) : newSolidL;
        newTotalR = w.aaFlagR ? addVertex(xTotal, yTotal, StyleRight, 0) : newSolidR;

        if (w.solidFlagL || w.solidFlagR)
        {
            addTriangle(SolidL, newSolidR, newSolidL);
            addTriangle(SolidL, SolidR, newSolidR);
        }
        if (w.aaFlagL)
        {
            addTriangle(TotalL, SolidL, newSolidL);
            addTriangle(TotalL, newSolidL, newTotalL);
        }
        if (w.aaFlagR)
        {
            addTriangle(SolidR, newTotalR, newSolidR);
            addTriangle(SolidR, TotalR, newTotalR);
        }

        SolidL = newSolidL;
        TotalL = newTotalL;
        SolidR = newSolidR;
        TotalR = newTotalR;
        if (overlap)
        {
            SolidR = addVertex(v1.x + p.dx2SolidR, v1.y + p.dy2SolidR, StyleRight);
            TotalR = w.aaFlagR ? addVertex(v1.x + p.dx2TotalR, v1.y + p.dy2TotalR, StyleRight, 0) : newSolidR;
        }

        // the arc on the left, clockwise
        a1 = sfr_atan2f_thunk(-p.dy1TotalL, -p.dx1TotalL);
        a2 = sfr_atan2f_thunk(-p.dy2TotalL, -p.dx2TotalL);
        if (a1 < a2) a2 -= 2 * Math2D::Pi;
        da = acosf(w.totalWidthL / (w.totalWidthL + 0.25f * Tolerance)) * 2;
        n  = int((a1 - a2) / da) + 1;
        da = (a1 - a2) / n;
        a1 -= da;

        for (i = 0; i < n; i++)
        {
            dx = cosf(a1);
            dy = sinf(a1);
            if (w.solidFlag)
                newSolidL = addVertex(v1.x + dx * w.solidWidthL, v1.y + dy * w.solidWidthL, StyleLeft);
            newTotalL = w.aaFlagL ? addVertex(v1.x + dx * w.totalWidthL, v1.y + dy * w.totalWidthL, StyleLeft, 0)
                                  : newSolidL;
            if (w.solidFlagL)
                addTriangle(SolidR, newSolidL, SolidL);
            if (w.aaFlagL)
            {
                addTriangle(SolidL, newSolidL, TotalL);
                addTriangle(TotalL, newSolidL, newTotalL);
            }
            SolidL = newSolidL;
            TotalL = newTotalL;
            a1 -= da;
        }
    }
    else
    {
        if ((2 * w.solidWidthL - p.dbTotalL) < Tolerance * (0.25f / 2))
        {
            calcMiterJoin(v1, w, p, MiterJoin);
            return;
        }

        xTotal = overlap ? v1.x - p.dx1TotalL : p.xMiterThisL;
        yTotal = overlap ? v1.y - p.dy1TotalL : p.yMiterThisL;
        xSolid = v1.x + (xTotal - v1.x) * w.solidCoeffL;
        ySolid = v1.y + (yTotal - v1.y) * w.solidCoeffL;

        newSolidR = addVertex(v1.x + p.dx1SolidR, v1.y + p.dy1SolidR, StyleRight);
        newTotalR = w.aaFlagR ? addVertex(v1.x + p.dx1TotalR, v1.y + p.dy1TotalR, StyleRight, 0) : newSolidR;
        newSolidL = w.solidFlag ? addVertex(xSolid, ySolid, StyleLeft) : newSolidR;
        newTotalL = w.aaFlagL ? addVertex(xTotal, yTotal, StyleLeft, 0) : newSolidL;

        if (w.solidFlagL || w.solidFlagR)
        {
            addTriangle(SolidR, newSolidR, newSolidL);
            addTriangle(SolidR, newSolidL, SolidL);
        }
        if (w.aaFlagR)
        {
            addTriangle(TotalR, newSolidR, SolidR);
            addTriangle(TotalR, newTotalR, newSolidR);
        }
        if (w.aaFlagL)
        {
            addTriangle(SolidL, newSolidL, newTotalL);
            addTriangle(SolidL, newTotalL, TotalL);
        }

        SolidL = newSolidL;
        TotalL = newTotalL;
        SolidR = newSolidR;
        TotalR = newTotalR;
        if (overlap)
        {
            SolidL = addVertex(v1.x - p.dx2SolidL, v1.y - p.dy2SolidL, StyleLeft);
            TotalL = w.aaFlagL ? addVertex(v1.x - p.dx2TotalL, v1.y - p.dy2TotalL, StyleLeft, 0) : newSolidL;
        }

        // the arc on the right, counter-clockwise
        a1 = sfr_atan2f_thunk(p.dy1TotalR, p.dx1TotalR);
        a2 = sfr_atan2f_thunk(p.dy2TotalR, p.dx2TotalR);
        if (a1 > a2) a2 += 2 * Math2D::Pi;
        da = acosf(w.totalWidthR / (w.totalWidthR + 0.25f * Tolerance)) * 2;
        n  = int((a2 - a1) / da) + 1;
        da = (a2 - a1) / n;
        a1 += da;

        for (i = 0; i < n; i++)
        {
            dx = cosf(a1);
            dy = sinf(a1);
            if (w.solidFlag)
                newSolidR = addVertex(v1.x + dx * w.solidWidthR, v1.y + dy * w.solidWidthR, StyleRight);
            newTotalR = w.aaFlagR ? addVertex(v1.x + dx * w.totalWidthR, v1.y + dy * w.totalWidthR, StyleRight, 0)
                                  : newSolidR;
            if (w.solidFlagR)
                addTriangle(SolidL, SolidR, newSolidR);
            if (w.aaFlagR)
            {
                addTriangle(SolidR, TotalR, newSolidR);
                addTriangle(TotalR, newTotalR, newSolidR);
            }
            SolidR = newSolidR;
            TotalR = newTotalR;
            a1 += da;
        }
    }
}

// derives the per-side solid/total widths, ratios, limits and flags from the settings
// @0x1426b1e90
void StrokerAA::calcWidths(WidthsType& w) const
{
    w.solidWidthL = WidthLeft;
    w.solidWidthR = WidthRight;
    if (w.solidWidthL < 0) w.solidWidthL = 0;
    if (w.solidWidthR < 0) w.solidWidthR = 0;

    w.totalWidthL = w.solidWidthL + AaWidthLeft;
    w.totalWidthR = w.solidWidthR + AaWidthRight;

    w.solidCoeffL = (w.totalWidthL == 0) ? 1 : w.solidWidthL / w.totalWidthL;
    w.solidCoeffR = (w.totalWidthR == 0) ? 1 : w.solidWidthR / w.totalWidthR;

    w.solidLimitL = MiterLimit * w.solidWidthL;
    w.solidLimitR = MiterLimit * w.solidWidthR;
    w.totalLimitL = MiterLimit * w.totalWidthL;
    w.totalLimitR = MiterLimit * w.totalWidthR;

    w.totalWidth = (w.totalWidthL + w.totalWidthR) / 2;
    w.solidWidth = (w.solidWidthL + w.solidWidthR) / 2;

    w.solidFlagL = w.solidWidthL > 0;
    w.solidFlagR = w.solidWidthR > 0;
    w.aaFlagL    = AaWidthLeft > 0;
    w.aaFlagR    = AaWidthRight > 0;
    w.solidFlag  = w.solidFlagL || w.solidFlagR || (StyleLeft != StyleRight);

    w.rightSideCalc = w.totalWidthR > w.totalWidthL;
    w.widthCoeff    = w.rightSideCalc ? w.totalWidthL / w.totalWidthR : w.totalWidthR / w.totalWidthL;
}

// round joins and caps, the default AA fringe of half a pixel on each side and an empty bound box
// @0x1426ad030
StrokerAA::StrokerAA(LinearHeap* heap)
    : LineJoin(RoundJoin),
      StartLineCap(RoundCap),
      EndLineCap(RoundCap),
      MiterLimit(3.0f),
      StyleLeft(1),
      StyleRight(1),
      WidthLeft(0),
      WidthRight(0),
      AaWidthLeft(0.5f),
      AaWidthRight(0.5f),
      Tolerance(1),
      IntersectionEpsilon(0.01f),
      Closed(false),
      Path(heap),
      Vertices(heap),
      Triangles(heap),
      MinX(MaxCoord),
      MinY(MaxCoord),
      MaxX(MinCoord),
      MaxY(MinCoord)
{
}

// @0x1426ad170
void StrokerAA::Clear()
{
    Path.ClearAndRelease();
    Vertices.ClearAndRelease();
    Triangles.ClearAndRelease();
    Closed = false;
    MinX   = MaxCoord;
    MinY   = MaxCoord;
    MaxX   = MinCoord;
    MaxY   = MinCoord;
}

// @0x1426ad1f0
void StrokerAA::ClosePath()
{
    Path.ClosePath();
    Closed = true;
}

// strokes the collected path: a closed one is joined all the way round (the first joins are emitted before their
// predecessors exist, so their placeholder indices are patched afterwards); an open one gets its start cap, the inner
// joins, a butt join onto the last segment and the end cap. The path is consumed
// @0x1426ad210
void StrokerAA::FinalizePath(unsigned, unsigned, bool, bool)
{
    if (!Closed)
        Closed = Path.ClosePath();

    SolidL = unsigned(MarkerSolidL);
    SolidR = unsigned(MarkerSolidR);
    TotalL = unsigned(MarkerTotalL);
    TotalR = unsigned(MarkerTotalR);

    WidthsType widths;
    calcWidths(widths);

    JoinParamType joinParam;

    UPInt i;
    if (Closed)
    {
        if (Path.GetVertexCount() > 2)
        {
            calcJoinParam(Path.GetVertex(Path.GetVertexCount() - 2), Path.GetVertex(Path.GetVertexCount() - 1),
                          Path.GetVertex(0), widths, joinParam);
            calcJoinParam(Path.GetVertex(Path.GetVertexCount() - 1), Path.GetVertex(0), Path.GetVertex(1), widths,
                          joinParam);

            UPInt startTri = Triangles.GetSize();
            for (i = 0; i < Path.GetVertexCount(); i++)
            {
                // the vertex two ahead, wrapping round the closed path
                UPInt forw = i + 2;
                if (forw >= Path.GetVertexCount())
                    forw -= Path.GetVertexCount();
                calcJoin(Path.GetVertex(i), Path.GetVertexNext(i), Path.GetVertex(forw), widths, joinParam);
            }
            // only the first joins can refer to the edge vertices of the last one
            for (i = 0; i < 6 && startTri + i < Triangles.GetSize(); i++)
            {
                TriangleType& tri = Triangles[startTri + i];
                if (tri.v1 == MarkerSolidL) tri.v1 = SolidL;
                if (tri.v1 == MarkerSolidR) tri.v1 = SolidR;
                if (tri.v1 == MarkerTotalL) tri.v1 = TotalL;
                if (tri.v1 == MarkerTotalR) tri.v1 = TotalR;
                if (tri.v2 == MarkerSolidL) tri.v2 = SolidL;
                if (tri.v2 == MarkerSolidR) tri.v2 = SolidR;
                if (tri.v2 == MarkerTotalL) tri.v2 = TotalL;
                if (tri.v2 == MarkerTotalR) tri.v2 = TotalR;
                if (tri.v3 == MarkerSolidL) tri.v3 = SolidL;
                if (tri.v3 == MarkerSolidR) tri.v3 = SolidR;
                if (tri.v3 == MarkerTotalL) tri.v3 = TotalL;
                if (tri.v3 == MarkerTotalR) tri.v3 = TotalR;
            }
        }
    }
    else
    {
        if (Path.GetVertexCount() > 1)
        {
            // square caps are butt caps on a path lengthened by half the width at that end
            CoordType avrInc = (WidthLeft + WidthRight) / 2;
            if (StartLineCap == SquareCap)
            {
                StrokeVertex& v0 = Path.GetVertex(0);
                StrokeVertex& v1 = Path.GetVertex(1);
                v0.x -= (v1.x - v0.x) * avrInc / v0.dist;
                v0.y -= (v1.y - v0.y) * avrInc / v0.dist;
                v0.dist += avrInc;
            }
            if (EndLineCap == SquareCap)
            {
                StrokeVertex& v0 = Path.GetVertex(Path.GetVertexCount() - 2);
                StrokeVertex& v1 = Path.GetVertex(Path.GetVertexCount() - 1);
                v1.x += (v1.x - v0.x) * avrInc / v0.dist;
                v1.y += (v1.y - v0.y) * avrInc / v0.dist;
                v0.dist += avrInc;
            }

            calcCap(Path.GetVertex(0), Path.GetVertex(1), Path.GetVertex(0).dist, widths, false);

            if (Path.GetVertexCount() > 2)
            {
                calcInitialJoinParam(Path.GetVertex(0), Path.GetVertex(1), widths, joinParam);
                calcJoinParam(Path.GetVertex(0), Path.GetVertex(1), Path.GetVertex(2), widths, joinParam);

                UPInt end = Path.GetVertexCount() - 2;
                for (i = 1; i < end; i++)
                    calcJoin(Path.GetVertex(i), Path.GetVertex(i + 1), Path.GetVertex(i + 2), widths, joinParam);

                // the last inner join looks ahead at the last segment mirrored past the end point
                const StrokeVertex& v0 = Path.GetVertex(end);
                const StrokeVertex& v1 = Path.GetVertex(end + 1);
                StrokeVertex        vLast;
                vLast.x    = 2 * v1.x - v0.x;
                vLast.y    = 2 * v1.y - v0.y;
                vLast.dist = v0.dist;
                calcJoin(Path.GetVertex(i), Path.GetVertex(i + 1), vLast, widths, joinParam);
            }

            calcButtJoin(Path.GetVertex(Path.GetVertexCount() - 2), Path.GetVertex(Path.GetVertexCount() - 1),
                         Path.GetVertex(Path.GetVertexCount() - 2).dist, widths);
            calcCap(Path.GetVertex(Path.GetVertexCount() - 1), Path.GetVertex(Path.GetVertexCount() - 2),
                    Path.GetVertex(Path.GetVertexCount() - 2).dist, widths, true);
        }
    }
    Path.Clear();
    Closed = false;
}

// the one mesh spans every output vertex
void StrokerAA::GetMesh(unsigned, TessMesh* mesh) const
{
    mesh->MeshIdx     = 0;
    mesh->Style1      = 1;
    mesh->Style2      = 0;
    mesh->Flags1      = 0;
    mesh->Flags2      = 0;
    mesh->StartVertex = 0;
    mesh->VertexCount = (unsigned)Vertices.GetSize();
}

// copies up to num vertices from mesh->StartVertex on (advancing it); the solid core is opaque, the fringe is not
// @0x1426ade00
unsigned StrokerAA::GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const
{
    unsigned i = 0;
    for (i = 0; i < num && mesh->StartVertex < Vertices.GetSize(); ++mesh->StartVertex)
    {
        const VertexType& v = Vertices[mesh->StartVertex];
        vertices->x         = v.x;
        vertices->y         = v.y;
        vertices->Idx       = 0;
        vertices->Styles[0] = v.style;
        vertices->Styles[1] = 0;
        vertices->Flags     = UInt16(v.alpha ? TessStyleOpaque : 0);
        ++vertices;
        ++i;
    }
    return i;
}

// @0x1426add70
void StrokerAA::GetTrianglesI16(unsigned, UInt16* idx, unsigned start, unsigned num) const
{
    for (unsigned j = 0; j < num; ++j)
    {
        const TriangleType& t = Triangles[start + j];
        *idx++ = (UInt16)t.v1;
        *idx++ = (UInt16)t.v2;
        *idx++ = (UInt16)t.v3;
    }
}

}} // namespace Scaleform::Render

// MS2-PIN: ?addTriangle@StrokerAA@Render@Scaleform@@AEAAXIII@Z 0x1426ae6b0
// MS2-PIN: ?addVertex@StrokerAA@Render@Scaleform@@AEAAIMMII@Z 0x1426ae7d0
// MS2-PIN: ?AddVertex@StrokerAA@Render@Scaleform@@UEAAXMM@Z 0x1426ad140
// MS2-PIN: ??_GStrokerAA@Render@Scaleform@@UEAAPEAXI@Z 0x1426ad110
// MS2-PIN: ??_7StrokerAA@Render@Scaleform@@6B@ 0x1431924f0
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
