// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the hairliner TU
// (Render_Hairliner). The source paths are cut into y-monotone chains and swept scan beam by scan beam; every chain
// crossing, horizontal edge and beam event becomes an output vertex, joined by a pair of directed graph edges. Each
// closed walk of that graph is a contour, which is widened outwards into a strip of triangles fading to alpha 0.
// Queue unit sfr_render_06 is split along its original sources (06h Render_Hairliner).
// MS2-UNIT: sfr_render_06h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426b2000-0x1426b7f90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/include/render/render_math2d.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

namespace Scaleform { namespace Render {

// ----------------------------------------------------------------------------------------------------------------
// setup

// @0x1426b3500
Hairliner::Hairliner(LinearHeap* heap)
    : pHeap(heap),
      Epsilon(0),
      IntersectionEpsilon(0.01f),
      Width(0.5f),
      Paths(heap),
      SrcVertices(heap),
      OutVertices(heap),
      Triangles(heap),
      LastVertex(0),
      SrcEdges(heap),
      MonoChains(heap),
      MonoChainsSorted(heap),
      Scanbeams(heap),
      HorizontalEdges(heap),
      StartHorizontals(0),
      NumHorizontals(0),
      LastX(MinCoord),
      LastY(MinCoord),
      MinX(MaxCoord),
      MinY(MaxCoord),
      MaxX(MinCoord),
      MaxY(MinCoord),
      ActiveChains(heap),
      ChainsAtBottom(heap),
      ValidChains(heap),
      Intersections(heap),
      ContourNodes(heap),
      FanEdges(heap)
{
}

// drops every array and the bounds, then the heap behind them
// @0x1426b37c0
void Hairliner::Clear()
{
    Paths.ClearAndRelease();
    SrcVertices.ClearAndRelease();
    OutVertices.ClearAndRelease();
    Triangles.ClearAndRelease();
    LastVertex = 0;
    SrcEdges.ClearAndRelease();
    MonoChains.ClearAndRelease();
    MonoChainsSorted.ClearAndRelease();
    Scanbeams.ClearAndRelease();
    HorizontalEdges.ClearAndRelease();
    StartHorizontals = 0;
    NumHorizontals   = 0;
    ActiveChains.ClearAndRelease();
    ChainsAtBottom.ClearAndRelease();
    ValidChains.ClearAndRelease();
    Intersections.ClearAndRelease();
    ContourNodes.ClearAndRelease();
    FanEdges.ClearAndRelease();
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    pHeap->ClearAndRelease();
}

// @0x1426b4360
void Hairliner::SetToleranceParam(const ToleranceParams& param)
{
    Epsilon             = param.Epsilon;
    IntersectionEpsilon = param.IntersectionEpsilon;
}

// @0x1426b3b50
CoordType Hairliner::GetLastX() const
{
    return SrcVertices.Back().x;
}

// @0x1426b3b80
CoordType Hairliner::GetLastY() const
{
    return SrcVertices.Back().y;
}

// @0x1426b3790
void Hairliner::AddVertex(CoordType x, CoordType y)
{
    SrcVertexType v = { x, y };
    SrcVertices.PushBack(v);
}

// ----------------------------------------------------------------------------------------------------------------
// orderings (passed to the sorts by address)

// by the bottom y, then by the x at the bottom and at the top
// @0x1426b5760
inline bool Hairliner::cmpMonoChains(const MonoChainType* a, const MonoChainType* b)
{
    if (a->ySort != b->ySort)
        return a->ySort < b->ySort;
    if (a->xb != b->xb)
        return a->xb < b->xb;
    return a->xt < b->xt;
}

inline bool Hairliner::cmpActiveChains(const MonoChainType* a, const MonoChainType* b)
{
    if (a->xb != b->xb)
        return a->xb < b->xb;
    return a->xt < b->xt;
}

// @0x1426b5750
inline bool Hairliner::cmpHorizontalEdges(const HorizontalEdgeType& a, const HorizontalEdgeType& b)
{
    return a.y < b.y;
}

// by the start node, the edges of one node by their slope
// @0x1426b5730
inline bool Hairliner::cmpEdges(const FanEdgeType& a, const FanEdgeType& b)
{
    if (a.node1 != b.node1)
        return a.node1 < b.node1;
    return a.slope < b.slope;
}

// @0x1426b57a0
inline bool Hairliner::cmpNode1(const FanEdgeType& a, unsigned b)
{
    return (a.node1 & ~FanEdgeType::Visited) < b;
}

// ----------------------------------------------------------------------------------------------------------------
// paths

// local minima and maxima of a path, walked forwards (ties go to the later vertex) and backwards
inline bool Hairliner::forwardMin(int idx, int start) const
{
    CoordType y = SrcVertices[idx].y;
    if (idx <= start)
        return SrcVertices[idx + 1].y > y;
    return SrcVertices[idx - 1].y >= y && SrcVertices[idx + 1].y > y;
}

inline bool Hairliner::reverseMin(int idx, int end) const
{
    CoordType y = SrcVertices[idx].y;
    if (idx >= end)
        return SrcVertices[idx - 1].y > y;
    return SrcVertices[idx - 1].y > y && SrcVertices[idx + 1].y >= y;
}

inline bool Hairliner::forwardMax(int idx, int end) const
{
    if (idx >= end)
        return true;
    return SrcVertices[idx + 1].y <= SrcVertices[idx].y;
}

inline bool Hairliner::reverseMax(int idx, int start) const
{
    if (idx <= start)
        return true;
    return SrcVertices[idx - 1].y <= SrcVertices[idx].y;
}

// links numEdges edges from start on (step +1 or -1) into one chain and adds the chain
// @0x1426b4e00
void Hairliner::buildEdgeList(unsigned start, unsigned numEdges, int step)
{
    SrcEdgeType e;
    unsigned    i;
    unsigned    firstEdge = (unsigned)SrcEdges.GetSize();

    for (i = 0; i < numEdges; ++i)
    {
        e.lower = start;
        start += step;
        e.upper = start;
        const SrcVertexType& lo = SrcVertices[e.lower];
        const SrcVertexType& up = SrcVertices[e.upper];
        e.slope = (up.x - lo.x) / (up.y - lo.y);
        e.next  = 0;
        SrcEdges.PushBack(e);
        if (i)
            SrcEdges[SrcEdges.GetSize() - 2].next = &SrcEdges.Back();
    }

    MonoChainType mc;
    mc.edge       = &SrcEdges[firstEdge];
    mc.ySort      = SrcVertices[mc.edge->lower].y;
    mc.xb         = SrcVertices[mc.edge->lower].x;
    mc.xt         = mc.edge->slope;   // only a sort key until the chain gets active
    mc.flags      = 0;
    mc.prevVertex = ~0U;
    MonoChains.PushBack(mc);
}

// repeats the first vertex of the open path
// @0x1426b3a10
void Hairliner::ClosePath()
{
    SrcVertices.PushBack(SrcVertices[LastVertex]);
}

// keeps the path when it has at least one edge; the styles do not matter for hairlines
// @0x1426b3a40
void Hairliner::FinalizePath(unsigned, unsigned, bool, bool)
{
    if ((unsigned)SrcVertices.GetSize() < LastVertex + 2)
    {
        SrcVertices.CutAt(LastVertex);
        return;
    }
    PathType path;
    path.start = LastVertex;
    path.end   = (unsigned)SrcVertices.GetSize() - 1;
    Paths.PushBack(path);
    LastVertex = (unsigned)SrcVertices.GetSize();
}

// records the horizontal edges of the path and cuts the rest into monotone chains, first walking forwards from
// every local minimum, then backwards
// @0x1426b57b0
void Hairliner::decomposePath(const PathType& path)
{
    int      start = path.start;
    int      end   = path.end;
    unsigned i;

    CoordType y1 = SrcVertices[start].y;
    Scanbeams.PushBack(start);
    for (i = start + 1; i <= (unsigned)end; ++i)
    {
        const SrcVertexType& v1 = SrcVertices[i - 1];
        const SrcVertexType& v2 = SrcVertices[i];
        if (v2.y != y1)
        {
            Scanbeams.PushBack(i);
            y1 = v2.y;
        }
        else if (v1.x != v2.x)
        {
            HorizontalEdgeType he;
            he.x1 = v1.x;
            he.x2 = v2.x;
            he.y  = v2.y;
            he.lv = ~0U;
            he.rv = ~0U;
            if (he.x1 > he.x2)
                Alg::Swap(he.x1, he.x2);
            HorizontalEdges.PushBack(he);
        }
    }

    int min, max;
    int numEdges;
    for (min = start; min < end; ++min)
    {
        if (forwardMin(min, start))
        {
            numEdges = 1;
            max      = min + 1;
            while (!forwardMax(max, end))
            {
                ++numEdges;
                ++max;
            }
            buildEdgeList(min, numEdges, +1);
            min += numEdges - 1;
        }
    }
    for (min = end; min > start; --min)
    {
        if (reverseMin(min, end))
        {
            numEdges = 1;
            max      = min - 1;
            while (!reverseMax(max, start))
            {
                ++numEdges;
                --max;
            }
            buildEdgeList(min, numEdges, -1);
            min -= numEdges - 1;
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------
// the sweep

inline CoordType Hairliner::calcX(const SrcEdgeType* edge, CoordType y) const
{
    const SrcVertexType& lo = SrcVertices[edge->lower];
    return lo.x + (y - lo.y) * edge->slope;
}

// moves the active chains to the beam yb..yt: chains whose edge ends at yb step to the next edge or end, the numMc
// chains from startMc on are merged in by their x, and the chains that cross inside the beam are swapped (bubble
// order) with the crossings recorded
// @0x1426b6640
unsigned Hairliner::nextScanbeam(CoordType yb, CoordType yt, unsigned startMc, unsigned numMc)
{
    UPInt                i, j;
    MonoChainType*       mc;
    const SrcVertexType* lower;
    const SrcVertexType* upper;
    IntersectionType     in;
    unsigned             retFlags = 0;

    if (numMc)
        retFlags = InsertEdgesFlag;

    ValidChains.Clear();
    for (i = 0; i < ActiveChains.GetSize(); ++i)
    {
        mc = ActiveChains[i];
        mc->flags &= ~EventFlag;
        if (SrcVertices[mc->edge->upper].y == yb)
        {
            if (mc->edge->next)
            {
                mc->edge = mc->edge->next;
                lower    = &SrcVertices[mc->edge->lower];
                upper    = &SrcVertices[mc->edge->upper];
                mc->xb   = lower->x;
                mc->xt   = (upper->y == yt) ? upper->x : calcX(mc->edge, yt);
                ValidChains.PushBack((unsigned)i);
            }
            else
            {
                mc->xb = mc->xt;
                mc->flags |= EndChainFlag;
                retFlags |= RemoveEdgesFlag;
            }
            mc->flags |= EventFlag;
        }
        else
        {
            lower  = &SrcVertices[mc->edge->lower];
            upper  = &SrcVertices[mc->edge->upper];
            mc->xb = mc->xt;
            mc->xt = (upper->y == yt) ? upper->x : calcX(mc->edge, yt);
            ValidChains.PushBack((unsigned)i);
        }
    }

    if (numMc)
    {
        for (i = 0; i < numMc; ++i)
        {
            mc    = MonoChainsSorted[startMc + i];
            lower = &SrcVertices[mc->edge->lower];
            // (as in the exe: the top test reads the lower end too, so the top x is always computed)
            upper     = &SrcVertices[mc->edge->lower];
            mc->xb    = lower->x;
            mc->flags = EventFlag;
            mc->xt    = (upper->y == yt) ? upper->x : calcX(mc->edge, yt);
            ActiveChains.PushBack(0);
        }
        // merge from the back: the new chains are sorted, the old ones too
        i = ActiveChains.GetSize();
        j = ActiveChains.GetSize() - numMc;
        while (numMc)
        {
            if (j == 0 || cmpActiveChains(ActiveChains[j - 1], MonoChainsSorted[startMc + numMc - 1]))
                ActiveChains[--i] = MonoChainsSorted[startMc + (--numMc)];
            else
                ActiveChains[--i] = ActiveChains[--j];
        }
    }

    Intersections.Clear();
    if (retFlags & InsertEdgesFlag)
    {
        ValidChains.Clear();
        for (i = 0; i < ActiveChains.GetSize(); ++i)
        {
            if ((ActiveChains[i]->flags & EndChainFlag) == 0)
                ValidChains.PushBack((unsigned)i);
        }
    }

    CoordType height = yt - yb;
    for (i = 1; i < ValidChains.GetSize(); ++i)
    {
        int k;
        for (k = (int)i - 1; k >= 0; --k)
        {
            in.mc1 = ActiveChains[ValidChains[k]];
            in.mc2 = ActiveChains[ValidChains[k + 1]];
            if (in.mc1->xt <= in.mc2->xt)
                break;

            // the first crossing keeps the order at the beam bottom
            if (Intersections.GetSize() == 0)
            {
                ChainsAtBottom.Clear();
                for (UPInt n = 0; n < ActiveChains.GetSize(); ++n)
                    ChainsAtBottom.PushBack(ActiveChains[n]);
            }

            CoordType nom = in.mc1->xb - in.mc2->xb;
            CoordType den = in.mc2->xt - in.mc2->xb - in.mc1->xt + in.mc1->xb;
            in.y          = (den == 0) ? yb : yb + height * nom / den;
            if (in.y < yb)
                in.y = yb;
            if (in.y > yt)
                in.y = yt;
            Intersections.PushBack(in);
            Alg::Swap(ActiveChains[ValidChains[k]], ActiveChains[ValidChains[k + 1]]);
        }
    }
    return retFlags;
}

// the output vertex at v, reusing the last one when it is the same point
// @0x1426b4940
inline unsigned Hairliner::addEventVertex(const SrcVertexType& v)
{
    if (v.y != LastY || v.x != LastX)
    {
        LastX             = v.x;
        LastY             = v.y;
        OutVertexType out = { v.x, v.y, 1 };
        OutVertices.PushBack(out);
    }
    return (unsigned)OutVertices.GetSize() - 1;
}

// the output vertex of chain mc at yb: without enforce only when the chain starts there, with enforce always (at
// an end or start vertex of the edge, else at the x of the edge, merged with the last vertex within Epsilon)
inline unsigned Hairliner::addEventVertex(const MonoChainType* mc, CoordType yb, bool enforce)
{
    if (!enforce)
    {
        if ((mc->flags & EventFlag) != 0 && SrcVertices[mc->edge->lower].y == yb)
            return addEventVertex(SrcVertices[mc->edge->lower]);
        else
            return ~0U;
    }
    else
    {
        if ((mc->flags & EndChainFlag) != 0 && SrcVertices[mc->edge->upper].y == yb)
            return addEventVertex(SrcVertices[mc->edge->upper]);
        if (SrcVertices[mc->edge->lower].y == yb)
            return addEventVertex(SrcVertices[mc->edge->lower]);

        CoordType x = calcX(mc->edge, yb);
        if (yb != LastY)
        {
            LastX             = x;
            LastY             = yb;
            OutVertexType out = { x, yb, 1 };
            OutVertices.PushBack(out);
        }
        else if (fabsf(x - LastX) > Epsilon)
        {
            LastX             = x;
            LastY             = yb;
            OutVertexType out = { x, yb, 1 };
            OutVertices.PushBack(out);
        }
    }
    return (unsigned)OutVertices.GetSize() - 1;
}

// both directions of the graph edge v1 v2; the slope ratio of the way back is the forward one turned half around
// @0x1426b5c80
inline void Hairliner::emitEdge(unsigned v1, unsigned v2)
{
    FanEdgeType e;
    e.node1 = v1;
    e.node2 = v2;
    e.slope = Math2D::SlopeRatio(OutVertices[v1], OutVertices[v2]);
    FanEdges.PushBack(e);
    e.node1 = v2;
    e.node2 = v1;
    e.slope -= 1;
    if (e.slope < -1.0f)
        e.slope += 2.0f;
    FanEdges.PushBack(e);
}

inline void Hairliner::emitEdge(MonoChainType* mc, unsigned vertex)
{
    if (mc->prevVertex != ~0U && mc->prevVertex != vertex)
        emitEdge(mc->prevVertex, vertex);
    mc->prevVertex = vertex;
}

inline void Hairliner::emitEdge(HorizontalEdgeType* he, unsigned vertex)
{
    if (he->rv != ~0U && he->rv != vertex)
        emitEdge(he->rv, vertex);
    he->rv = vertex;
}

// connects chain mc at yb with the horizontal edges of the beam bottom it touches; returns its vertex there (made
// when an edge needs one)
// @0x1426b71e0
unsigned Hairliner::processHorizontalEdges(MonoChainType* mc, unsigned vertex, CoordType yb)
{
    unsigned  i;
    bool      haveX = false;
    CoordType x     = 0;

    for (i = 0; i < NumHorizontals; ++i)
    {
        HorizontalEdgeType* he = &HorizontalEdges[StartHorizontals + i];
        if (vertex != ~0U && he->rv == ~0U && he->x1 == OutVertices[vertex].x)
        {
            he->lv = vertex;
            he->rv = vertex;
        }
        else if (vertex != ~0U && he->x2 == OutVertices[vertex].x)
        {
            emitEdge(he, vertex);
            if (he->lv == ~0U)
                he->lv = vertex;
        }
        else
        {
            if (!haveX)
            {
                const SrcVertexType& lo = SrcVertices[mc->edge->lower];
                const SrcVertexType& up = SrcVertices[mc->edge->upper];
                if (yb == lo.y)
                    x = lo.x;
                else if (yb == up.y)
                    x = up.x;
                else
                    x = calcX(mc->edge, yb);
                haveX = true;
            }
            if (x == he->x1)
            {
                SrcVertexType v = { x, yb };
                if (vertex == ~0U)
                    vertex = addEventVertex(v);
                he->rv = vertex;
            }
            else if (x >= he->x1 && x <= he->x2)
            {
                SrcVertexType v = { x, yb };
                if (vertex == ~0U)
                    vertex = addEventVertex(v);
                emitEdge(he, vertex);
                if (he->lv == ~0U)
                    he->lv = vertex;
            }
        }
    }
    return vertex;
}

// emits the events of the chains aet at yb, then closes the horizontal edges of the beam bottom at their ends
// @0x1426b77d0
void Hairliner::sweepScanbeam(const ChainPtrArray& aet, CoordType yb)
{
    UPInt i;
    for (i = 0; i < aet.GetSize(); ++i)
    {
        MonoChainType* mc     = aet[i];
        unsigned       vertex = addEventVertex(mc, yb, (mc->flags & EndChainFlag) != 0);
        if (NumHorizontals)
            vertex = processHorizontalEdges(mc, vertex, yb);
        if (vertex != ~0U)
            emitEdge(mc, vertex);
    }

    for (i = 0; i < NumHorizontals; ++i)
    {
        HorizontalEdgeType* he = &HorizontalEdges[StartHorizontals + i];
        if (he->lv != ~0U)
        {
            const OutVertexType& lv = OutVertices[he->lv];
            if (lv.x != he->x1)
            {
                SrcVertexType v = { he->x1, yb };
                emitEdge(he->lv, addEventVertex(v));
            }
        }
        if (he->rv != ~0U)
        {
            const OutVertexType& rv = OutVertices[he->rv];
            if (rv.x != he->x2)
            {
                SrcVertexType v = { he->x2, yb };
                emitEdge(he->rv, addEventVertex(v));
            }
        }
        if (he->lv == ~0U && he->rv == ~0U)
        {
            SrcVertexType v1 = { he->x1, yb };
            SrcVertexType v2 = { he->x2, yb };
            emitEdge(addEventVertex(v1), addEventVertex(v2));
        }
    }
}

// a beam with crossings: the bottom events in the bottom order, then a vertex on both chains of every crossing
// @0x1426b7490
void Hairliner::processInterior(CoordType yb)
{
    UPInt i;
    sweepScanbeam(ChainsAtBottom, yb);
    for (i = 0; i < Intersections.GetSize(); ++i)
    {
        const IntersectionType& in = Intersections[i];
        if (in.y > yb)
        {
            emitEdge(in.mc1, addEventVertex(in.mc1, in.y, true));
            emitEdge(in.mc2, addEventVertex(in.mc2, in.y, true));
        }
    }
}

// sorts the vertex ys into beams (snapping ys within Epsilon), builds the chains of all paths and sweeps them
// @0x1426b5160
void Hairliner::buildGraph()
{
    UPInt i, j;

    if (SrcVertices.GetSize() == 0)
        return;

    for (i = 0; i < SrcVertices.GetSize(); ++i)
        Scanbeams.PushBack((unsigned)i);

    CmpScanbeams byY(SrcVertices);
    Alg::QuickSort(Scanbeams, byY);

    CoordType y1 = MinCoord;
    for (i = j = 0; i < Scanbeams.GetSize(); ++i)
    {
        SrcVertexType& v = SrcVertices[Scanbeams[i]];
        if (v.y - y1 > fabsf(v.y) * Epsilon)
        {
            Scanbeams[j++] = Scanbeams[i];
            y1             = v.y;
        }
        else
            v.y = y1;
    }
    Scanbeams.CutAt(j);

    for (i = 0; i < Paths.GetSize(); ++i)
        decomposePath(Paths[i]);

    for (i = 0; i < MonoChains.GetSize(); ++i)
        MonoChainsSorted.PushBack(&MonoChains[i]);

    Alg::QuickSort(HorizontalEdges, cmpHorizontalEdges);
    Alg::QuickSort(MonoChainsSorted, cmpMonoChains);

    unsigned  sb = 0;   // next beam
    unsigned  mc = 0;   // next chain to start
    unsigned  he = 0;   // next horizontal edge
    CoordType yb, yt;
    yb = yt = SrcVertices[Scanbeams[0]].y;
    LastX   = MinCoord;
    LastY   = MinCoord;

    while (sb < Scanbeams.GetSize())
    {
        if (++sb < Scanbeams.GetSize())
            yt = SrcVertices[Scanbeams[sb]].y;

        unsigned startMc = mc;
        while (mc < MonoChainsSorted.GetSize() && MonoChainsSorted[mc]->ySort <= yb)
            ++mc;

        StartHorizontals = he;
        while (he < HorizontalEdges.GetSize() && HorizontalEdges[he].y <= yb)
            ++he;
        NumHorizontals = he - StartHorizontals;

        unsigned flags = nextScanbeam(yb, yt, startMc, mc - startMc);
        if (Intersections.GetSize())
            processInterior(yb);
        else
            sweepScanbeam(ActiveChains, yb);

        if (flags & RemoveEdgesFlag)
        {
            unsigned k, pos;
            for (k = pos = 0; k < ActiveChains.GetSize(); ++k)
            {
                MonoChainType* chain = ActiveChains[k];
                if ((chain->flags & EndChainFlag) == 0)
                    ActiveChains[pos++] = chain;
            }
            ActiveChains.CutAt(pos);
        }
        yb = yt;
    }
}

// ----------------------------------------------------------------------------------------------------------------
// contours

// walks the graph from edge startEdgeIdx, always taking the next edge of the fan at the far node after the way
// back, and collects the contour nodes (repeated points once)
// @0x1426b5db0
void Hairliner::generateContourAA(unsigned startEdgeIdx)
{
    FanEdgeType* startEdge = &FanEdges[startEdgeIdx];
    FanEdgeType* edge      = startEdge;
    CoordType    prevX     = MinCoord;
    CoordType    prevY     = MinCoord;

    ContourNodes.Clear();
    do
    {
        if (edge->node1 & FanEdgeType::Visited)
            break;

        unsigned             thisNode = edge->node1 & ~FanEdgeType::Visited;
        const OutVertexType& v        = OutVertices[thisNode];
        if (v.x != prevX || v.y != prevY)
        {
            ContourNodes.PushBack(thisNode);
            prevX = v.x;
            prevY = v.y;
        }
        edge->node1 |= FanEdgeType::Visited;

        UPInt startFan = Alg::LowerBound(FanEdges, edge->node2, cmpNode1);
        if (startFan >= FanEdges.GetSize())
            break;

        UPInt fanSize = 0;
        while (startFan + fanSize < FanEdges.GetSize())
        {
            const FanEdgeType& e = FanEdges[startFan + fanSize];
            if ((e.node1 & ~FanEdgeType::Visited) != edge->node2)
                break;
            ++fanSize;
        }

        if (fanSize == 1)
        {
            edge = &FanEdges[startFan];
        }
        else if (fanSize == 2)
        {
            FanEdgeType* e1 = &FanEdges[startFan];
            FanEdgeType* e2 = &FanEdges[startFan + 1];
            if (e1->node2 == e2->node2)
                edge = (e1->node1 & FanEdgeType::Visited) ? e2 : e1;
            else
                edge = (e1->node2 == thisNode) ? e2 : e1;
        }
        else
        {
            unsigned i;
            for (i = 0; i < fanSize; ++i)
            {
                const FanEdgeType& back = FanEdges[startFan + i];
                if (back.node2 == thisNode)
                {
                    unsigned n;
                    for (n = 0; n < fanSize; ++n)
                    {
                        ++i;
                        if (i >= fanSize)
                            i = 0;
                        edge = &FanEdges[startFan + i];
                        if (edge == startEdge || (edge->node1 & FanEdgeType::Visited) == 0)
                            break;
                    }
                    break;
                }
            }
        }
    } while (edge != startEdge);

    if (ContourNodes.GetSize())
    {
        const OutVertexType& first = OutVertices[ContourNodes[0]];
        const OutVertexType& last  = OutVertices[ContourNodes.Back()];
        if (first.x == last.x && first.y == last.y)
            ContourNodes.PopBack();
    }
}

// the outer vertices of the corner v1 v2 v3 at distance width: one for a nearly straight corner or a miter that is
// short enough, otherwise two (with a filling triangle on the outside of a sharp turn); returns how many
// @0x1426b49b0
unsigned Hairliner::addJoin(unsigned refVertex, const OutVertexType& v1, const OutVertexType& v2,
                            const OutVertexType& v3, CoordType len1, CoordType len2, CoordType width)
{
    CoordType turn    = Math2D::TurnRatio(v1, v2, v3, len1, len2);
    CoordType epsilon = (len1 + len2) * IntersectionEpsilon;
    CoordType dx1     = width * (v1.y - v2.y) / len1;
    CoordType dy1     = width * (v2.x - v1.x) / len1;
    CoordType dx2     = width * (v2.y - v3.y) / len2;
    CoordType dy2     = width * (v3.x - v2.x) / len2;
    CoordType xi      = v2.x;
    CoordType yi      = v2.y;

    OutVertexType o1, o2;
    TriangleType  tri;
    unsigned      nv = 1;

    o1.alpha = o2.alpha = 0;
    if (fabsf(turn) < 0.125f)
    {
        if (len1 > len2)
        {
            o1.x = v2.x + dx1;
            o1.y = v2.y + dy1;
        }
        else
        {
            o1.x = v2.x + dx2;
            o1.y = v2.y + dy2;
        }
        OutVertices.PushBack(o1);
    }
    else
    {
        if (Math2D::Intersection(v1.x + dx1, v1.y + dy1, v2.x + dx1, v2.y + dy1,
                                 v2.x + dx2, v2.y + dy2, v3.x + dx2, v3.y + dy2, &xi, &yi, epsilon))
        {
            CoordType d1 = Math2D::Distance(v2.x, v2.y, xi, yi);
            CoordType lim;
            if (turn > 0)
            {
                lim = ((len1 < len2) ? len1 : len2) / turn;
                if (d1 > lim)
                {
                    o1.x = v2.x + dx1;
                    o1.y = v2.y + dy1;
                    o2.x = v2.x + dx2;
                    o2.y = v2.y + dy2;
                    OutVertices.PushBack(o1);
                    OutVertices.PushBack(o2);
                    nv = 2;
                }
                else
                {
                    o1.x = xi;
                    o1.y = yi;
                    OutVertices.PushBack(o1);
                }
            }
            else
            {
                lim = -width * 4;
                if (d1 <= lim)
                {
                    o1.x = xi;
                    o1.y = yi;
                    OutVertices.PushBack(o1);
                }
                else
                {
                    o1.x = v2.x + dx1 - 2 * dy1;
                    o1.y = v2.y + dy1 + 2 * dx1;
                    o2.x = v2.x + dx2 + 2 * dy2;
                    o2.y = v2.y + dy2 - 2 * dx2;
                    OutVertices.PushBack(o1);
                    OutVertices.PushBack(o2);
                    tri.v1 = refVertex;
                    tri.v2 = (unsigned)OutVertices.GetSize() - 2;
                    tri.v3 = (unsigned)OutVertices.GetSize() - 1;
                    Triangles.PushBack(tri);
                    nv = 2;
                }
            }
        }
        else
        {
            // parallel offsets of a reversal: square it off
            o1.x = v2.x + dx1 - dy1;
            o1.y = v2.y + dy1 + dx1;
            o2.x = v2.x + dx2 + dy2;
            o2.y = v2.y + dy2 - dx2;
            OutVertices.PushBack(o1);
            OutVertices.PushBack(o2);
            tri.v1 = refVertex;
            tri.v2 = (unsigned)OutVertices.GetSize() - 2;
            tri.v3 = (unsigned)OutVertices.GetSize() - 1;
            Triangles.PushBack(tri);
            nv = 2;
        }
    }
    return nv;
}

// the AA strip of the collected contour: each node gets its outer vertices, consecutive nodes two triangles
// @0x1426b61a0
void Hairliner::generateTriangles(CoordType width)
{
    if (ContourNodes.GetSize() < 2)
        return;

    TriangleType         tri;
    unsigned             i;
    unsigned             thisRef = ContourNodes.Back();
    const OutVertexType* v1      = &OutVertices[ContourNodes[ContourNodes.GetSize() - 2]];
    const OutVertexType* v2      = &OutVertices[thisRef];
    const OutVertexType* v3;
    CoordType            len1 = Math2D::Distance(*v1, *v2);
    CoordType            len2;
    unsigned             prevRef  = ~0U;
    unsigned             prevAA   = ~0U;
    unsigned             startRef = ~0U;
    unsigned             startAA  = ~0U;

    for (i = 0; i < ContourNodes.GetSize(); ++i)
    {
        v3          = &OutVertices[ContourNodes[i]];
        len2        = Math2D::Distance(*v2, *v3);
        unsigned nv = addJoin(thisRef, *v1, *v2, *v3, len1, len2, width);
        if (prevRef == ~0U)
        {
            startRef = thisRef;
            startAA  = (unsigned)OutVertices.GetSize() - nv;
        }
        else
        {
            tri.v1 = prevRef;
            tri.v2 = prevAA;
            tri.v3 = (unsigned)OutVertices.GetSize() - nv;
            Triangles.PushBack(tri);
            tri.v1 = prevRef;
            tri.v2 = (unsigned)OutVertices.GetSize() - nv;
            tri.v3 = thisRef;
            Triangles.PushBack(tri);
        }
        v1      = v2;
        v2      = v3;
        len1    = len2;
        prevRef = thisRef;
        thisRef = ContourNodes[i];
        prevAA  = (unsigned)OutVertices.GetSize() - 1;
    }

    if (prevRef != ~0U)
    {
        tri.v1 = prevRef;
        tri.v2 = prevAA;
        tri.v3 = startAA;
        Triangles.PushBack(tri);
        tri.v1 = prevRef;
        tri.v2 = startAA;
        tri.v3 = startRef;
        Triangles.PushBack(tri);
    }
}

// builds the graph, drops the duplicate edges and widens every contour not yet walked
// @0x1426b4660
void Hairliner::Tessellate()
{
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    Triangles.Clear();
    buildGraph();
    if (FanEdges.GetSize() < 2)
        return;

    Alg::QuickSort(FanEdges, cmpEdges);

    UPInt i, j;
    for (i = 1, j = 1; i < FanEdges.GetSize(); ++i)
    {
        const FanEdgeType& prev = FanEdges[i - 1];
        const FanEdgeType& e    = FanEdges[i];
        if (prev.node1 != e.node1 || prev.node2 != e.node2)
            FanEdges[j++] = e;
    }
    FanEdges.CutAt(j);

    for (i = 0; i < FanEdges.GetSize(); ++i)
    {
        FanEdgeType& e = FanEdges[i];
        if ((e.node1 & FanEdgeType::Visited) == 0)
        {
            generateContourAA((unsigned)i);
            generateTriangles(-Width);
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------
// output

// maps the output vertices by m and recomputes their bounds
// @0x1426b4810
void Hairliner::Transform(const Matrix2F& m)
{
    UPInt i;
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    for (i = 0; i < OutVertices.GetSize(); ++i)
    {
        OutVertexType& v = OutVertices[i];
        m.Transform(&v.x, &v.y);
        if (v.x < MinX) MinX = v.x;
        if (v.y < MinY) MinY = v.y;
        if (v.x > MaxX) MaxX = v.x;
        if (v.y > MaxY) MaxY = v.y;
    }
}

// fits the vertices into the rectangle x1 y1 x2 y2 (bounds recomputed when empty); returns the way back
// @0x1426b4370
Matrix2F Hairliner::StretchTo(float x1, float y1, float x2, float y2)
{
    Matrix2F m;
    UPInt    i;
    if (MinX >= MaxX || MinY >= MaxY)
    {
        MinX = MaxCoord;
        MinY = MaxCoord;
        MaxX = MinCoord;
        MaxY = MinCoord;
        for (i = 0; i < OutVertices.GetSize(); ++i)
        {
            OutVertexType v = OutVertices[i];
            if (v.x < MinX) MinX = v.x;
            if (v.y < MinY) MinY = v.y;
            if (v.x > MaxX) MaxX = v.x;
            if (v.y > MaxY) MaxY = v.y;
        }
    }
    if (MinX < MaxX && MinY < MaxY)
    {
        m.SetRectToRect(MinX, MinY, MaxX, MaxY, x1, y1, x2, y2);
        for (i = 0; i < OutVertices.GetSize(); ++i)
        {
            OutVertexType& v = OutVertices[i];
            m.Transform(&v.x, &v.y);
        }
        m.Invert();
    }
    return m;
}

// @0x1426b3c80
unsigned Hairliner::GetVertexCount() const
{
    return (unsigned)OutVertices.GetSize();
}

// @0x1426b3bd0
unsigned Hairliner::GetMeshCount() const
{
    return Triangles.GetSize() != 0;
}

// @0x1426b3bf0
unsigned Hairliner::GetMeshVertexCount(unsigned) const
{
    return (unsigned)OutVertices.GetSize();
}

// @0x1426b3be0
unsigned Hairliner::GetMeshTriangleCount(unsigned) const
{
    return (unsigned)Triangles.GetSize();
}

// the single mesh: style 1 on the left, all vertices
// @0x1426b3bb0
void Hairliner::GetMesh(unsigned, TessMesh* mesh) const
{
    mesh->MeshIdx     = 0;
    mesh->Style1      = 1;
    mesh->Style2      = 0;
    mesh->Flags1      = 0;
    mesh->Flags2      = 0;
    mesh->StartVertex = 0;
    mesh->VertexCount = (unsigned)OutVertices.GetSize();
}

// copies up to num vertices from mesh->StartVertex on (advancing it); the line vertices are opaque
// @0x1426b3c90
unsigned Hairliner::GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const
{
    unsigned i = 0;
    for (i = 0; i < num && mesh->StartVertex < OutVertices.GetSize(); ++mesh->StartVertex)
    {
        const OutVertexType& v = OutVertices[mesh->StartVertex];
        vertices->x            = v.x;
        vertices->y            = v.y;
        vertices->Idx          = 0;
        vertices->Styles[0]    = 1;
        vertices->Styles[1]    = 0;
        vertices->Flags        = UInt16(v.alpha ? TessStyleOpaque : 0);
        ++vertices;
        ++i;
    }
    return i;
}

// @0x1426b3c00
void Hairliner::GetTrianglesI16(unsigned, UInt16* idx, unsigned start, unsigned num) const
{
    for (unsigned j = 0; j < num; ++j)
    {
        const TriangleType& t = Triangles[start + j];
        *idx++                = (UInt16)t.v1;
        *idx++                = (UInt16)t.v2;
        *idx++                = (UInt16)t.v3;
    }
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7Hairliner@Render@Scaleform@@6B@ 0x143192578
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
// MS2-PIN: ??_GHairliner@Render@Scaleform@@UEAAPEAXI@Z 0x1426b3760
// MS2-PIN: ??$QuickSort@V?$ArrayPaged@I$03$0BA@@Render@Scaleform@@UCmpScanbeams@Hairliner@23@@Alg@Scaleform@@YAXAEAV?$ArrayPaged@I$03$0BA@@Render@1@UCmpScanbeams@Hairliner@31@@Z 0x1426b2160
// MS2-PIN: ??$QuickSort@V?$ArrayPaged@PEAUMonoChainType@Hairliner@Render@Scaleform@@$03$07@Render@Scaleform@@P6A_NPEBUMonoChainType@Hairliner@23@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayPaged@PEAUMonoChainType@Hairliner@Render@Scaleform@@$03$07@Render@1@P6A_NPEBUMonoChainType@Hairliner@31@1@Z@Z 0x1426b2170
// MS2-PIN: ??$QuickSort@V?$ArrayPaged@UFanEdgeType@Hairliner@Render@Scaleform@@$03$0BA@@Render@Scaleform@@P6A_NAEBUFanEdgeType@Hairliner@23@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayPaged@UFanEdgeType@Hairliner@Render@Scaleform@@$03$0BA@@Render@1@P6A_NAEBUFanEdgeType@Hairliner@31@1@Z@Z 0x1426b2180
// MS2-PIN: ??$QuickSort@V?$ArrayPaged@UHorizontalEdgeType@Hairliner@Render@Scaleform@@$01$03@Render@Scaleform@@P6A_NAEBUHorizontalEdgeType@Hairliner@23@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayPaged@UHorizontalEdgeType@Hairliner@Render@Scaleform@@$01$03@Render@1@P6A_NAEBUHorizontalEdgeType@Hairliner@31@1@Z@Z 0x1426b2190
