// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the stroker TU
// (Render_Stroker). Stroker offsets a polyline by half the stroke width on both sides, with miter / round / bevel
// joins and butt / square / round caps, and feeds the outline to a TessBase. StrokeSorter gathers stroke paths,
// chains paths whose ends meet (sorted by start point, binary searched), snaps, offsets and dashes them.
// Queue unit sfr_render_05 is split along its original sources (05b Render_Stroker).
// MS2-UNIT: sfr_render_05b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426a9270-0x1426aa240 .text$mn
// MS2-RANGE: 0x1426aa250-0x1426aa2f0 .text$mn
// MS2-RANGE: 0x1426aa2f0-0x1426aa310 .text$mn
// MS2-RANGE: 0x1426aa310-0x1426ad030 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_stroker.h"
#include "ms2/scaleform/include/render/render_shapedata.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

namespace Scaleform { namespace Render {

// @0x1426a9c70
void StrokePath::AddVertex(const StrokeVertex& v)
{
    if (Path.GetSize() == 0 || Path.Back().Distance(v))
        Path.PushBack(v);
}

// Clear keeps the pages for reuse, ClearAndRelease frees them.
void StrokePath::Clear()
{
    Path.Clear();
}

// @0x1426aa2f0
void StrokePath::ClearAndRelease()
{
    Path.ClearAndRelease();
}

// @0x1426aa310
bool StrokePath::ClosePath()
{
    if (Path.GetSize() > 1 && !Path.Back().Distance(Path[0]))
    {
        // the last vertex repeats the first one
        Path.PopBack();
        return Path.GetSize() > 2;
    }
    return false;
}

// @0x1426a98e0
Stroker::Stroker(LinearHeap* heap)
    : pHeap(heap), Path(heap), Width(1.0f), LineJoin(RoundJoin), StartLineCap(RoundCap), EndLineCap(RoundCap),
      MiterLimit(3.0f), CurveTolerance(1.0f), IntersectionEpsilon(0.01f), Closed(false)
{
}

// @0x1426ab510
void Stroker::SetToleranceParam(const ToleranceParams& param)
{
    CurveTolerance      = param.CurveTolerance;
    IntersectionEpsilon = param.IntersectionEpsilon;
}

// @0x1426a9df0
void Stroker::AddVertex(CoordType x, CoordType y)
{
    Path.AddVertex(StrokeVertex(x, y));
}

// @0x1426aa3d0
void Stroker::ClosePath()
{
    Path.ClosePath();
    Closed = true;
}

// @0x1426aab80
void Stroker::GenerateStroke(TessBase* tess)
{
    if (!Closed)
        Closed = Path.ClosePath();

    if (Path.GetVertexCount() > 1)
    {
        UPInt i;
        if (Closed)
        {
            // two closed outlines, one per side
            for (i = 0; i < Path.GetVertexCount(); ++i)
                calcJoin(tess, Path.GetVertexPrev(i), Path.GetVertex(i), Path.GetVertexNext(i),
                         Path.GetVertexPrev(i).dist, Path.GetVertex(i).dist);
            tess->ClosePath();
            tess->FinalizePath(0, 1, false, false);

            for (i = Path.GetVertexCount(); i > 0; --i)
                calcJoin(tess, Path.GetVertexNext(i - 1), Path.GetVertex(i - 1), Path.GetVertexPrev(i - 1),
                         Path.GetVertex(i - 1).dist, Path.GetVertexPrev(i - 1).dist);
            tess->ClosePath();
            tess->FinalizePath(0, 1, false, false);
        }
        else
        {
            // one outline: start cap, forward side, end cap, backward side
            calcCap(tess, Path.GetVertex(0), Path.GetVertex(1), Path.GetVertex(0).dist, StartLineCap);

            for (i = 1; i + 1 < Path.GetVertexCount(); ++i)
                calcJoin(tess, Path.GetVertexPrev(i), Path.GetVertex(i), Path.GetVertexNext(i),
                         Path.GetVertexPrev(i).dist, Path.GetVertex(i).dist);

            calcCap(tess, Path.GetVertex(Path.GetVertexCount() - 1), Path.GetVertex(Path.GetVertexCount() - 2),
                    Path.GetVertex(Path.GetVertexCount() - 2).dist, EndLineCap);

            for (i = Path.GetVertexCount() - 2; i > 0; --i)
                calcJoin(tess, Path.GetVertexNext(i), Path.GetVertex(i), Path.GetVertexPrev(i),
                         Path.GetVertex(i).dist, Path.GetVertexPrev(i).dist);
            tess->ClosePath();
            tess->FinalizePath(0, 1, false, false);
        }
    }
    Path.Clear();
    Closed = false;
}

// @0x1426aa000
void Stroker::CalcEquidistant(TessBase* tess, EquidistantDir dir)
{
    if (Path.GetVertexCount() > 2)
    {
        UPInt i;
        if (dir == DirForward)
        {
            for (i = 0; i < Path.GetVertexCount(); ++i)
                calcJoin(tess, Path.GetVertexPrev(i), Path.GetVertex(i), Path.GetVertexNext(i),
                         Path.GetVertexPrev(i).dist, Path.GetVertex(i).dist);
        }
        else
        {
            for (i = Path.GetVertexCount(); i > 0; --i)
                calcJoin(tess, Path.GetVertexNext(i - 1), Path.GetVertex(i - 1), Path.GetVertexPrev(i - 1),
                         Path.GetVertex(i - 1).dist, Path.GetVertexPrev(i - 1).dist);
        }
        tess->ClosePath();
        tess->FinalizePath(0, 1, false, false);
    }
    Path.Clear();
}

// Round join: the arc around (x y) from offset (dx1 dy1) to (dx2 dy2), the step angle chosen so the chord stays
// within a quarter of the curve tolerance.
// @0x1426ac170
void Stroker::calcArc(TessBase* tess, CoordType x, CoordType y, CoordType dx1, CoordType dy1, CoordType dx2,
                      CoordType dy2)
{
    CoordType a1   = atan2f(dy1, dx1);
    CoordType a2   = atan2f(dy2, dx2);
    CoordType step = acosf(Width / (Width + 0.25f * CurveTolerance)) * 2;

    tess->AddVertex(x + dx1, y + dy1);
    if (a1 > a2)
        a2 += 2 * Math2D::Pi;
    int n = int((a2 - a1) / step);
    step  = (a2 - a1) / (n + 1);
    a1 += step;
    for (int k = 0; k < n; ++k)
    {
        tess->AddVertex(x + cosf(a1) * Width, y + sinf(a1) * Width);
        a1 += step;
    }
    tess->AddVertex(x + dx2, y + dy2);
}

// Miter join at v1 between the offset segments v0 v1 and v1 v2. Past the limit: a bevel (MiterBevelJoin) or the
// miter cut back to the limit.
// @0x1426acae0
void Stroker::calcMiter(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, const StrokeVertex& v2,
                        CoordType dx1, CoordType dy1, CoordType dx2, CoordType dy2, LineJoinType lineJoin,
                        CoordType miterLimit, CoordType epsilon, CoordType dbevel)
{
    CoordType xi      = v1.x;
    CoordType yi      = v1.y;
    CoordType di      = 1;
    CoordType lim     = Width * miterLimit;
    bool      tooLong = true;
    bool      noCross = true;

    if (Math2D::Intersection(v0.x + dx1, v0.y + dy1, v1.x + dx1, v1.y + dy1, v1.x + dx2, v1.y + dy2, v2.x + dx2,
                             v2.y + dy2, &xi, &yi, epsilon))
    {
        di = Math2D::Distance(v1.x, v1.y, xi, yi);
        if (di <= lim)
        {
            tess->AddVertex(xi, yi);
            tooLong = false;
        }
        noCross = false;
    }
    else
    {
        // parallel offsets: a straight continuation when v0 and v2 are on different sides of the normal at v1
        CoordType px = v1.x + dx1;
        CoordType py = v1.y + dy1;
        if (((v0.x - px) * dy1 - (v0.y - py) * dx1 < 0.0) != ((v2.x - px) * dy1 - (v2.y - py) * dx1 < 0.0))
        {
            tess->AddVertex(v1.x + dx1, v1.y + dy1);
            tooLong = false;
        }
    }

    if (tooLong)
    {
        switch (lineJoin)
        {
        case MiterBevelJoin:
            tess->AddVertex(v1.x + dx1, v1.y + dy1);
            tess->AddVertex(v1.x + dx2, v1.y + dy2);
            break;

        default:
            if (noCross)
            {
                tess->AddVertex(v1.x + dx1 - dy1 * miterLimit, v1.y + dy1 + dx1 * miterLimit);
                tess->AddVertex(v1.x + dx2 + dy2 * miterLimit, v1.y + dy2 - dx2 * miterLimit);
            }
            else
            {
                CoordType x1 = v1.x + dx1;
                CoordType y1 = v1.y + dy1;
                CoordType x2 = v1.x + dx2;
                CoordType y2 = v1.y + dy2;
                di           = (lim - dbevel) / (di - dbevel);
                tess->AddVertex(x1 + (xi - x1) * di, y1 + (yi - y1) * di);
                tess->AddVertex(x2 + (xi - x2) * di, y2 + (yi - y2) * di);
            }
            break;
        }
    }
}

// The cap at v0 of the segment v0 v1 (len long).
// @0x1426ac330
void Stroker::calcCap(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, CoordType len,
                      LineCapType cap)
{
    if (Width == 0)
    {
        tess->AddVertex(v0.x, v0.y);
        return;
    }

    CoordType dx1 = (v1.y - v0.y) / len;
    CoordType dy1 = (v0.x - v1.x) / len;
    CoordType dx2 = 0;
    CoordType dy2 = 0;
    dx1 *= Width;
    dy1 *= Width;

    if (cap != RoundCap)
    {
        if (cap == SquareCap)
        {
            dx2 = dy1;
            dy2 = dx1;
        }
        tess->AddVertex(v0.x - dx1 + dx2, v0.y - dy1 - dy2);
        tess->AddVertex(v0.x + dx1 + dx2, v0.y + dy1 - dy2);
    }
    else
    {
        CoordType a1   = atan2f(-dy1, -dx1);
        CoordType a2   = a1 + Math2D::Pi;
        CoordType step = acosf(Width / (Width + 0.25f * CurveTolerance)) * 2;
        int       n    = int((a2 - a1) / step);
        step           = (a2 - a1) / (n + 1);
        a1 += step;

        tess->AddVertex(v0.x - dx1, v0.y - dy1);
        for (int k = 0; k < n; ++k)
        {
            tess->AddVertex(v0.x + cosf(a1) * Width, v0.y + sinf(a1) * Width);
            a1 += step;
        }
        tess->AddVertex(v0.x + dx1, v0.y + dy1);
    }
}

// The join at v1 between v0 v1 (len1 long) and v1 v2 (len2 long).
// @0x1426ac5c0
void Stroker::calcJoin(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, const StrokeVertex& v2,
                       CoordType len1, CoordType len2)
{
    if (Width == 0)
    {
        tess->AddVertex(v1.x, v1.y);
        return;
    }

    CoordType epsilon = (len1 + len2) * IntersectionEpsilon;
    CoordType dx1     = Width * (v1.y - v0.y) / len1;
    CoordType dy1     = Width * (v0.x - v1.x) / len1;
    CoordType dx2     = Width * (v2.y - v1.y) / len2;
    CoordType dy2     = Width * (v1.x - v2.x) / len2;

    if (Math2D::CrossProduct(v0, v1, v2) > 0)
    {
        // inside of the turn: miter, bevel once the shorter segment is exceeded
        CoordType shorter = (len1 < len2) ? len1 : len2;
        calcMiter(tess, v0, v1, v2, dx1, dy1, dx2, dy2, MiterBevelJoin, shorter / Width, epsilon, 0);
    }
    else
    {
        // outside of the turn
        CoordType    dx     = (dx1 + dx2) / 2;
        CoordType    dy     = (dy1 + dy2) / 2;
        CoordType    dbevel = sqrtf(dx * dx + dy * dy);
        LineJoinType join   = LineJoin;
        if (join == RoundJoin || join == BevelJoin)
        {
            // nearly straight: the bevel would not show, one miter point is enough
            if (Width - dbevel < CurveTolerance * (0.25f / 2))
            {
                if (Math2D::Intersection(v0.x + dx1, v0.y + dy1, v1.x + dx1, v1.y + dy1, v1.x + dx2, v1.y + dy2,
                                         v2.x + dx2, v2.y + dy2, &dx, &dy, epsilon))
                    tess->AddVertex(dx, dy);
                else
                    tess->AddVertex(v1.x + dx1, v1.y + dy1);
                return;
            }
        }

        switch (join)
        {
        case MiterJoin:
        case MiterBevelJoin:
            calcMiter(tess, v0, v1, v2, dx1, dy1, dx2, dy2, join, MiterLimit, epsilon, dbevel);
            break;

        case RoundJoin:
            calcArc(tess, v1.x, v1.y, dx1, dy1, dx2, dy2);
            break;

        default:
            tess->AddVertex(v1.x + dx1, v1.y + dy1);
            tess->AddVertex(v1.x + dx2, v1.y + dy2);
            break;
        }
    }
}

// @0x1426a9840
StrokeSorter::StrokeSorter(LinearHeap* heap)
    : pHeap(heap), SrcVertices(heap), SrcPaths(heap), SortedPaths(heap), OutVertices(heap), OutPaths(heap),
      LastVertex(0)
{
}

// @0x1426a9f40
void StrokeSorter::AddVertexNV(CoordType x, CoordType y, unsigned segType)
{
    if (SrcVertices.GetSize() == LastVertex && SrcVertices.GetSize() && SrcVertices.Back().x == x &&
        SrcVertices.Back().y == y)
    {
        // a path starting where the previous one ended: reopen and extend that one
        LastVertex = SrcPaths.Back().start;
        SrcPaths.PopBack();
    }
    else
    {
        VertexType v = { x, y, 0, (UInt8)segType, false, false };
        SrcVertices.PushBack(v);
    }
}

// @0x1426a9db0
void StrokeSorter::AddVertex(CoordType x, CoordType y)
{
    VertexType v = { x, y, 0, Math2D::Seg_LineTo, false, false };
    SrcVertices.PushBack(v);
}

// @0x1426a9c30
void StrokeSorter::AddQuad(CoordType x2, CoordType y2, CoordType x3, CoordType y3)
{
    AddVertexNV(x2, y2, Math2D::Seg_QuadTo);
    AddVertexNV(x3, y3, Math2D::Seg_QuadTo);
}

// @0x1426a99a0
void StrokeSorter::AddCubic(CoordType x2, CoordType y2, CoordType x3, CoordType y3, CoordType x4, CoordType y4)
{
    AddVertexNV(x2, y2, Math2D::Seg_CubicTo);
    AddVertexNV(x3, y3, Math2D::Seg_CubicTo);
    AddVertexNV(x4, y4, Math2D::Seg_CubicTo);
}

// @0x1426aa3f0
void StrokeSorter::FinalizePath(unsigned closeFlag, unsigned, bool, bool)
{
    if (SrcVertices.GetSize() > LastVertex + 1)
    {
        PathType p = { LastVertex, (unsigned)SrcVertices.GetSize() - LastVertex };
        if (closeFlag)
            p.numVer |= ClosedFlag;
        SrcPaths.PushBack(p);
        LastVertex = (unsigned)SrcVertices.GetSize();
    }
    else
        SrcVertices.CutAt(LastVertex); // a single vertex is no path
}

// Appends the vertices of src to dst (the first one only when dst is empty: it repeats dst's last vertex).
// @0x1426abfd0
void StrokeSorter::appendPath(PathType* dst, PathType* src)
{
    if (dst->numVer == 0)
    {
        dst->start = (unsigned)OutVertices.GetSize();
        OutVertices.PushBack(SrcVertices[src->start]);
        ++dst->numVer;
    }
    unsigned n = src->numVer & NumVerMask;
    for (unsigned i = 1; i < n; ++i)
    {
        OutVertices.PushBack(SrcVertices[src->start + i]);
        ++dst->numVer;
    }
}

// The first unvisited sorted path starting where outPath ends, ~0 if none.
// @0x1426acf30
unsigned StrokeSorter::findNext(const PathType& outPath) const
{
    const VertexType& last = OutVertices[outPath.start + (outPath.numVer & NumVerMask) - 1];
    SortedPathType    key  = { last.x, last.y };
    UPInt             idx  = Alg::LowerBound(SortedPaths, key, cmpPaths);

    for (; idx < SortedPaths.GetSize(); ++idx)
    {
        const SortedPathType& sp = SortedPaths[idx];
        if (sp.x != key.x || sp.y != key.y)
            break;
        if ((sp.thisPath->numVer & VisitedFlag) == 0)
            return (unsigned)idx;
    }
    return ~0U;
}

// @0x1426ab8b0
void StrokeSorter::Sort()
{
    UPInt i;
    UPInt n = SrcPaths.GetSize();

    for (i = 0; i < n; ++i)
    {
        PathType p = SrcPaths[i];
        SrcPaths.PushBack(p);
    }

    SortedPaths.Resize(n);
    for (i = 0; i < n; ++i)
    {
        const PathType&   p  = SrcPaths[i];
        const VertexType& v  = SrcVertices[p.start];
        SortedPathType&   sp = SortedPaths[i];
        sp.x        = v.x;
        sp.y        = v.y;
        sp.thisPath = &SrcPaths[i];
    }
    Alg::QuickSort(SortedPaths, cmpPaths);

    // chain paths end to start until the chain closes or nothing continues it
    for (i = 0; i < SortedPaths.GetSize(); ++i)
    {
        if (SortedPaths[i].thisPath->numVer & VisitedFlag)
            continue;

        unsigned          next  = (unsigned)i;
        const VertexType* first;
        const VertexType* last;
        PathType          chain = { 0, 0 };
        do
        {
            SortedPathType* sp = &SortedPaths[next & NumVerMask];
            sp->thisPath->numVer |= VisitedFlag;
            appendPath(&chain, SortedPaths[next & NumVerMask].thisPath);
            first = &OutVertices[chain.start];
            last  = &OutVertices[chain.start + (chain.numVer & NumVerMask) - 1];
            if (first->x == last->x && first->y == last->y)
                break;
        } while ((next = findNext(chain)) != ~0U);

        first = &OutVertices[chain.start];
        last  = &OutVertices[chain.start + (chain.numVer & NumVerMask) - 1];
        if (first->x == last->x && first->y == last->y)
            chain.numVer |= ClosedFlag;
        OutPaths.PushBack(chain);
    }
}

// @0x1426a9a00
void StrokeSorter::AddOffset(CoordType offsetX, CoordType offsetY)
{
    for (unsigned i = 0; i < OutPaths.GetSize(); ++i)
    {
        unsigned start = OutPaths[i].start;
        unsigned n     = OutPaths[i].numVer & NumVerMask;
        for (unsigned j = 0; j < n; ++j)
        {
            OutVertices[start + j].x += offsetX;
            OutVertices[start + j].y += offsetY;
        }
    }
}

// Rounds a path's x (y) to whole pixels plus the offset when it has a vertical (horizontal) segment.
// @0x1426ab520
void StrokeSorter::Snap(CoordType offsetX, CoordType offsetY)
{
    for (unsigned i = 0; i < OutPaths.GetSize(); ++i)
    {
        unsigned start  = OutPaths[i].start;
        unsigned n      = OutPaths[i].numVer & NumVerMask;
        unsigned closed = OutPaths[i].numVer & ClosedFlag;

        bool        snapX = false;
        bool        snapY = false;
        unsigned    j     = 1;
        VertexType* prev  = &OutVertices[start];
        if (closed)
        {
            j    = 0;
            prev = &OutVertices[start + n - 1];
        }
        for (; j < n; ++j)
        {
            VertexType* v = &OutVertices[start + j];
            if (prev->x == v->x && prev->y != v->y)
                snapX = true;
            if (prev->y == v->y && prev->x != v->x)
                snapY = true;
            prev = v;
        }
        if (snapX)
        {
            for (j = 0; j < n; ++j)
            {
                CoordType x            = OutVertices[start + j].x;
                OutVertices[start + j].x = floorf((x < 0) ? x - 0.5f : x + 0.5f) + offsetX;
            }
        }
        if (snapY)
        {
            for (j = 0; j < n; ++j)
            {
                CoordType y            = OutVertices[start + j].y;
                OutVertices[start + j].y = floorf((y < 0) ? y - 0.5f : y + 0.5f) + offsetY;
            }
        }
    }
}

// @0x1426abf40
void StrokeSorter::Transform(const TransformerBase* tr)
{
    for (UPInt i = 0; i < OutVertices.GetSize(); ++i)
    {
        VertexType& v = OutVertices[i];
        tr->Transform(&v.x, &v.y);
    }
}

// Flattens the sorted paths back into the source arrays (curves at the tolerance divided by scale), then replaces
// the output with the dash pieces.
// MS2-FUNCTIONAL: stack layout only (the exe puts the scaled ToleranceParams copy below the DashGenerator, ours above)
// @0x1426aa470
void StrokeSorter::GenerateDashes(const DashArray* da, const ToleranceParams& param, float scale)
{
    SrcVertices.ClearAndRelease();
    SrcPaths.ClearAndRelease();
    LastVertex = 0;

    scale              = 1 / scale;
    ToleranceParams tp = param;
    tp.CollinearityTolerance *= scale;
    tp.CurveTolerance *= scale;

    unsigned i, j;
    for (i = 0; i < GetPathCount(); ++i)
    {
        unsigned n = GetVertexCount(i);
        for (j = 0; j < n;)
        {
            const VertexType& v1 = GetVertex(i, j++);
            switch (v1.segType)
            {
            case Math2D::Seg_LineTo:
                AddVertex(v1.x, v1.y);
                break;

            case Math2D::Seg_QuadTo:
            {
                const VertexType& v2 = GetVertex(i, j++);
                TessellateQuadCurve(this, tp, v1.x, v1.y, v2.x, v2.y);
                break;
            }

            case Math2D::Seg_CubicTo:
            {
                const VertexType& v2 = GetVertex(i, j++);
                const VertexType& v3 = GetVertex(i, j++);
                TessellateCubicCurve(this, tp, v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
                break;
            }
            }
        }
        FinalizePath(IsClosed(i), 0, false, false);
    }

    OutVertices.ClearAndRelease();
    OutPaths.ClearAndRelease();

    // an odd dash list is used twice so dashes and gaps alternate
    unsigned dashCount = 0;
    float    dashes[16 * 2];
    for (i = 0; i < da->DashCount; ++i)
        dashes[dashCount++] = da->Dashes[i];
    if (dashCount & 1)
    {
        for (i = 0; i < da->DashCount; ++i)
            dashes[dashCount++] = da->Dashes[i];
    }

    unsigned start = 0;
    for (i = 0; i < SrcPaths.GetSize(); ++i)
    {
        VertexType*   ver    = &SrcVertices[SrcPaths[i].start];
        unsigned      count  = SrcPaths[i].numVer & NumVerMask;
        bool          closed = (SrcPaths[i].numVer & ClosedFlag) != 0;
        DashGenerator dash(dashes, dashCount, da->DashStart, ver, count, closed);

        for (;;)
        {
            float    x, y;
            unsigned cmd = dash.GetVertex(&x, &y);
            if (cmd == Math2D::Seg_EndPath)
                break;
            if (cmd == Math2D::Seg_MoveTo)
            {
                PathType path = { start, 0 };
                OutPaths.PushBack(path);
            }
            VertexType v = { x, y, 0, Math2D::Seg_LineTo, false, false };
            OutVertices.PushBack(v);
            OutPaths.Back().numVer++;
            ++start;
        }
    }
}

// @0x1426a9670
DashGenerator::DashGenerator(const float* dashArray, unsigned dashCount, float dashStart,
                             StrokeSorter::VertexType* ver, unsigned verCount, bool closed)
    : pDashArray(dashArray), DashCount(dashCount), DashStart(dashStart), CurrDash(0), CurrRest(0), CurrDashStart(0),
      Vertices(ver), VerCount(verCount), Ver1(0), Ver2(0), Closed(closed), Status(Status_Ready), SrcVertex(0)
{
    if (DashStart > 0)
    {
        // skip whole dashes until the start offset falls inside one
        float rest    = DashStart;
        CurrDash      = 0;
        CurrDashStart = 0.0;
        while (rest > 0)
        {
            if (rest > pDashArray[CurrDash])
            {
                rest -= pDashArray[CurrDash];
                ++CurrDash;
                CurrDashStart = 0;
                if (CurrDash >= DashCount)
                    CurrDash = 0;
            }
            else
            {
                CurrDashStart = rest;
                rest          = 0.0;
            }
        }
    }

    // segment lengths, dropping coinciding vertices
    unsigned out = 0;
    float    len;
    for (unsigned k = 1; k < VerCount; ++k)
    {
        len = Math2D::Distance(Vertices[k - 1], Vertices[k]);
        if (len > 1e-10f)
        {
            if (out < k - 1)
                Vertices[out] = Vertices[k - 1];
            Vertices[out++].Dist = len;
        }
    }
    Vertices[out].Dist = 1e10f;
    VerCount           = out + 1;
    if (Closed && VerCount > 2)
    {
        // closing segment
        len = Math2D::Distance(Vertices[0], Vertices[VerCount - 1]);
        if (len > 1e-10f)
            Vertices[VerCount - 1].Dist = len;
        else
        {
            VerCount--;
            Vertices[VerCount - 1].Dist = Math2D::Distance(Vertices[0], Vertices[VerCount - 1]);
        }
    }
}

// @0x1426ab150
unsigned DashGenerator::GetVertex(float* x, float* y)
{
    unsigned cmd = Math2D::Seg_MoveTo;
    while (cmd != Math2D::Seg_EndPath)
    {
        switch (Status)
        {
        case Status_Ready:
            if (DashCount < 2 || VerCount < 2)
            {
                cmd = Math2D::Seg_EndPath;
                break;
            }
            Status    = Status_Polyline;
            SrcVertex = 1;
            Ver1      = &Vertices[0];
            Ver2      = &Vertices[1];
            CurrRest  = Ver1->Dist;
            *x        = Ver1->x;
            *y        = Ver1->y;
            return Math2D::Seg_MoveTo;

        case Status_Polyline:
        {
            float dashRest = pDashArray[CurrDash] - CurrDashStart;
            // odd entries are gaps: their end starts the next dash
            cmd = (CurrDash & 1) ? Math2D::Seg_MoveTo : Math2D::Seg_LineTo;
            if (CurrRest > dashRest)
            {
                CurrRest -= dashRest;
                ++CurrDash;
                if (CurrDash >= DashCount)
                    CurrDash = 0;
                CurrDashStart = 0;
                *x = Ver2->x - (Ver2->x - Ver1->x) * CurrRest / Ver1->Dist;
                *y = Ver2->y - (Ver2->y - Ver1->y) * CurrRest / Ver1->Dist;
            }
            else
            {
                CurrDashStart += CurrRest;
                *x = Ver2->x;
                *y = Ver2->y;
                ++SrcVertex;
                Ver1     = Ver2;
                CurrRest = Ver1->Dist;
                if (Closed)
                {
                    if (SrcVertex > VerCount)
                        Status = Status_Stop;
                    else
                        Ver2 = &Vertices[(SrcVertex >= VerCount) ? 0 : SrcVertex];
                }
                else
                {
                    if (SrcVertex >= VerCount)
                        Status = Status_Stop;
                    else
                        Ver2 = &Vertices[SrcVertex];
                }
            }
            return cmd;
        }

        case Status_Stop:
            cmd = Math2D::Seg_EndPath;
            break;
        }
    }
    return Math2D::Seg_EndPath;
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
// MS2-PIN: ??_7Stroker@Render@Scaleform@@6B@ 0x1431923f0
// MS2-PIN: ??_7StrokeSorter@Render@Scaleform@@6B@ 0x143192470
