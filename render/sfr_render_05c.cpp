// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the tessellator TU
// (Render_Tessellator). Source paths are cut into y-monotone edge chains, the chains are swept scan beam by scan
// beam (with the crossings between beams found and ordered), and the areas between chains are gathered into
// monotone polygons per style. These are triangulated into meshes; with edge AA every vertex fan gets outer copies
// and blended triangles, in stroker mode the outline gets widened.
// Queue unit sfr_render_05 is split along its original sources (05c Render_Tessellator).
// MS2-UNIT: sfr_render_05c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142696790-0x1426978d0 .text$mn
// MS2-RANGE: 0x142697d20-0x142698a90 .text$mn
// MS2-RANGE: 0x142698a90-0x142698b20 .text$mn
// MS2-RANGE: 0x142698b20-0x1426a9270 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$LowerBoundSliced@V?$ArrayPaged@UOuterEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@Scaleform@@UOuterEdgeType@Tessellator@23@P6A_NAEBU4523@0@Z@Alg@Scaleform@@YA_KAEBV?$ArrayPaged@UOuterEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@1@_K1AEBUOuterEdgeType@Tessellator@31@P6A_N22@Z@Z 0x142696d30 ; order
// MS2-PIN: ??$LowerBoundSliced@V?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@Scaleform@@IP6A_NAEBUStrokerEdgeType@Tessellator@23@I@Z@Alg@Scaleform@@YA_KAEBV?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@1@_K1AEBIP6A_NAEBUStrokerEdgeType@Tessellator@31@I@Z@Z 0x142696de0 ; order
// MS2-PIN: ??$LowerBoundSliced@V?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@Scaleform@@UStrokerEdgeType@Tessellator@23@P6A_NAEBU4523@0@Z@Alg@Scaleform@@YA_KAEBV?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@1@_K1AEBUStrokerEdgeType@Tessellator@31@P6A_N22@Z@Z 0x142696e90 ; order
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_tessellator.h"
#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

namespace Scaleform { namespace Render {

// Explicitly emits the Hairliner copy of this header-defined helper at its out-of-line exe address.
template float Math2D::TurnRatio<Hairliner::OutVertexType, Hairliner::OutVertexType, Hairliner::OutVertexType>(
    const Hairliner::OutVertexType&, const Hairliner::OutVertexType&, const Hairliner::OutVertexType&, CoordType,
    CoordType);

// ----------------------------------------------------------------------------------------------------------------
// setup

// @0x142698b20
Tessellator::Tessellator(LinearHeap* heap1, LinearHeap* heap2)
    : pHeap1(heap1)
    , pHeap2(heap2)
    , FillRule(FillNonZero)
    , Epsilon(0)
    , HasEpsilon(false)
    , StrokerMode(false)
    , InvasiveMerge(true)
    , HasComplexFill(false)
    , VertexLimit(65534)
    , ComplexFlags(heap2)
    , MaxStyle(0)
    , Paths(heap1)
    , SrcVertices(heap1)
    , LastVertex(0)
    , Edges(heap1)
    , MonoChains(heap1)
    , MonoChainsSorted(heap1)
    , Scanbeams(heap1)
    , ActiveChains(heap1)
    , InteriorChains(heap1)
    , ValidChains(heap1)
    , InteriorOrder(heap1)
    , Intersections(heap1)
    , StyleCounts(heap1)
    , LastX(MinCoord)
    , MinX(MaxCoord)
    , MinY(MaxCoord)
    , MaxX(MinCoord)
    , MaxY(MinCoord)
    , ChainsBelow(heap1)
    , ChainsAbove(heap1)
    , BaseLines(heap1)
    , PendingEnds(heap1)
    , Monotones(heap2)
    , MonoVertices(heap2)
    , MeshVertices(heap2)
    , StyleMatrix(heap2)
    , Meshes(heap2)
    , MeshTriangles(heap1)
    , MonoStyle(0)
    , MeshIdx(~0U)
    , FactorOneFlag(0)
    , EdgeAAWidth(0.5f)
    , EdgeAAFlag(true)
    , IntersectionEpsilon(0.01f)
    , LeftChain(heap1)
    , RightChain(heap1)
    , TmpEdgeFan(heap1)
    , EdgeFans(heap1)
    , StartFan(heap1)
    , EndFan(heap1)
    , OuterEdges(heap1)
    , StrokerEdges(heap1)
    , MonoStack(heap1)
    , InnerQuads(heap1)
    , StarVertices(heap1)
    , FakeVar(0)
{
}

// @0x1426990d0
void Tessellator::AddVertex(CoordType x, CoordType y)
{
    SrcVertices.PushBack(SrcVertexType(x, y));
}

// @0x142699100
void Tessellator::Clear()
{
    LastVertex     = 0;
    HasComplexFill = false;
    MaxStyle       = 0;
    LastX          = MinCoord;
    MinX           = MaxCoord;
    MinY           = MaxCoord;
    MaxX           = MinCoord;
    MaxY           = MinCoord;
    ComplexFlags.ClearAndRelease();
    Paths.ClearAndRelease();
    SrcVertices.ClearAndRelease();
    Edges.ClearAndRelease();
    MonoChains.ClearAndRelease();
    MonoChainsSorted.ClearAndRelease();
    Scanbeams.ClearAndRelease();
    ActiveChains.ClearAndRelease();
    InteriorChains.ClearAndRelease();
    ValidChains.ClearAndRelease();
    InteriorOrder.ClearAndRelease();
    Intersections.ClearAndRelease();
    StyleCounts.ClearAndRelease();
    ChainsBelow.ClearAndRelease();
    ChainsAbove.ClearAndRelease();
    BaseLines.ClearAndRelease();
    PendingEnds.ClearAndRelease();
    Monotones.ClearAndRelease();
    MonoVertices.ClearAndRelease();
    MeshVertices.ClearAndRelease();
    StyleMatrix.ClearAndRelease();
    Meshes.ClearAndRelease();
    MeshTriangles.ClearAndRelease();
    LeftChain.ClearAndRelease();
    RightChain.ClearAndRelease();
    TmpEdgeFan.ClearAndRelease();
    EdgeFans.ClearAndRelease();
    StartFan.ClearAndRelease();
    EndFan.ClearAndRelease();
    OuterEdges.ClearAndRelease();
    StrokerEdges.ClearAndRelease();
    MonoStack.ClearAndRelease();
    InnerQuads.ClearAndRelease();
    StarVertices.ClearAndRelease();
    pHeap1->ClearAndRelease();
    pHeap2->ClearAndRelease();
}

// drops the sweep data (heap 1) once the monotones are built; the results live on heap 2
// @0x14269c0f0
void Tessellator::clearHeap1()
{
    Paths.ClearAndRelease();
    SrcVertices.ClearAndRelease();
    Edges.ClearAndRelease();
    MonoChains.ClearAndRelease();
    MonoChainsSorted.ClearAndRelease();
    Scanbeams.ClearAndRelease();
    ActiveChains.ClearAndRelease();
    InteriorChains.ClearAndRelease();
    ValidChains.ClearAndRelease();
    InteriorOrder.ClearAndRelease();
    Intersections.ClearAndRelease();
    StyleCounts.ClearAndRelease();
    ChainsBelow.ClearAndRelease();
    ChainsAbove.ClearAndRelease();
    BaseLines.ClearAndRelease();
    PendingEnds.ClearAndRelease();
    MeshTriangles.ClearAndRelease();
    LeftChain.ClearAndRelease();
    RightChain.ClearAndRelease();
    EdgeFans.ClearAndRelease();
    StartFan.ClearAndRelease();
    TmpEdgeFan.ClearAndRelease();
    EndFan.ClearAndRelease();
    OuterEdges.ClearAndRelease();
    StrokerEdges.ClearAndRelease();
    MonoStack.ClearAndRelease();
    InnerQuads.ClearAndRelease();
    StarVertices.ClearAndRelease();
    pHeap1->Clear();
}

// @0x14269a3b0
void Tessellator::SetToleranceParam(const ToleranceParams& param)
{
    Epsilon             = param.Epsilon;
    HasEpsilon          = Epsilon > 0;
    IntersectionEpsilon = param.IntersectionEpsilon;
}

// @0x14269a290
void Tessellator::SetEdgeAAWidth(CoordType w)
{
    EdgeAAWidth = w;
    EdgeAAFlag  = w > 0;
}

// @0x14269a2b0
void Tessellator::SetFillRule(FillRuleType f)
{
    if (f == FillStroker)
    {
        FillRule    = FillNonZero;
        StrokerMode = true;
    }
    else
    {
        FillRule    = f;
        StrokerMode = false;
    }
}

// ----------------------------------------------------------------------------------------------------------------
// orderings (inlined into the sorts)

SF_INLINE bool Tessellator::cmpMonoChains(const MonoChainType* a, const MonoChainType* b)
{
    if (a->ySort != b->ySort)
        return a->ySort < b->ySort;
    if (a->xb != b->xb)
        return a->xb < b->xb;
    return a->xt < b->xt;
}

SF_INLINE bool Tessellator::cmpActiveChains(const MonoChainType* a, const MonoChainType* b)
{
    if (a->xb != b->xb)
        return a->xb < b->xb;
    return a->xt < b->xt;
}

SF_INLINE bool Tessellator::cmpIntersectionY(const IntersectionType& a, const IntersectionType& b)
{
    return a.y < b.y;
}

SF_INLINE bool Tessellator::cmpEdgeAA(const TmpEdgeAAType& a, const TmpEdgeAAType& b)
{
    if (a.slope != b.slope)
        return a.slope < b.slope;
    return a.style < b.style;
}

SF_INLINE bool Tessellator::cmpOuterEdges(const OuterEdgeType& a, const OuterEdgeType& b)
{
    if (a.edge->cntVer != b.edge->cntVer)
        return a.edge->cntVer < b.edge->cntVer;
    return a.edge->rayVer < b.edge->rayVer;
}

SF_INLINE bool Tessellator::cmpStrokerEdges(const StrokerEdgeType& a, const StrokerEdgeType& b)
{
    if (verIdx(a.node1) != verIdx(b.node1))
        return verIdx(a.node1) < verIdx(b.node1);
    return verIdx(a.node2) < verIdx(b.node2);
}

SF_INLINE bool Tessellator::cmpStrokerNode1(const StrokerEdgeType& e, unsigned node)
{
    return verIdx(e.node1) < verIdx(node);
}

// ----------------------------------------------------------------------------------------------------------------
// source paths -> monotone chains

// local minimum / maximum tests walking the path forward (from start) or backward (from end)
SF_INLINE bool Tessellator::forwardMin(int idx, int start) const
{
    CoordType y = SrcVertices[idx].y;
    if (idx <= start)
        return SrcVertices[idx + 1].y > y;
    return SrcVertices[idx - 1].y >= y && SrcVertices[idx + 1].y > y;
}

SF_INLINE bool Tessellator::reverseMin(int idx, int end) const
{
    CoordType y = SrcVertices[idx].y;
    if (idx >= end)
        return SrcVertices[idx - 1].y > y;
    return SrcVertices[idx - 1].y > y && SrcVertices[idx + 1].y >= y;
}

SF_INLINE bool Tessellator::forwardMax(int idx, int end) const
{
    if (idx >= end)
        return true;
    return SrcVertices[idx + 1].y <= SrcVertices[idx].y;
}

SF_INLINE bool Tessellator::reverseMax(int idx, int start) const
{
    if (idx <= start)
        return true;
    return SrcVertices[idx - 1].y <= SrcVertices[idx].y;
}

// appends numEdges edges from start (stepping by step) and one chain over them
// @0x14269bdb0
void Tessellator::buildEdgeList(unsigned start, unsigned numEdges, int step, unsigned leftStyle, unsigned rightStyle)
{
    EdgeType e;
    unsigned i;
    unsigned firstEdge = (unsigned)Edges.GetSize();
    for (i = 0; i < numEdges; ++i)
    {
        e.lower = start;
        start += step;
        const SrcVertexType& lo = SrcVertices[e.lower];
        const SrcVertexType& hi = SrcVertices[e.lower + step];
        e.slope                 = (hi.x - lo.x) / (hi.y - lo.y);
        Edges.PushBack(e);
    }

    MonoChainType        mc;
    const SrcVertexType& v = SrcVertices[Edges[firstEdge].lower];
    mc.edge       = firstEdge;
    mc.end        = (unsigned)Edges.GetSize() - 1;
    mc.ySort      = v.y;
    mc.xb         = v.x;
    mc.xt         = Edges[firstEdge].slope;     // the first sort goes by slope
    mc.dir        = (SInt16)step;
    mc.leftStyle  = (UInt16)leftStyle;
    mc.rightStyle = (UInt16)rightStyle;
    mc.leftBelow  = 0;
    mc.leftAbove  = 0;
    mc.rightBelow = 0;
    mc.rightAbove = 0;
    mc.flags      = 0;
    mc.posScan    = 0;
    mc.posIntr    = ~0U;
    MonoChains.PushBack(mc);
}

// @0x14269b9a0
void Tessellator::addStyle(unsigned style, bool complex)
{
    if (style)
    {
        while (32 * ComplexFlags.GetSize() <= style)
            ComplexFlags.Resize(ComplexFlags.GetSize() ? 2 * ComplexFlags.GetSize() : 8);
        if (complex)
        {
            ComplexFlags[style >> 5] |= 1 << (style & 31);
            HasComplexFill = true;
        }
        if (MaxStyle < style)
            MaxStyle = style;
    }
}

// repeats the first vertex of the open path at its end, unless it is there already
// @0x1426994c0
void Tessellator::ClosePath()
{
    if (SrcVertices.GetSize() > LastVertex + 2)
    {
        if (SrcVertices[LastVertex].x != SrcVertices.Back().x || SrcVertices[LastVertex].y != SrcVertices.Back().y)
            SrcVertices.PushBack(SrcVertices[LastVertex]);
    }
}

// @0x142699530
void Tessellator::FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex)
{
    if (SrcVertices.GetSize() < LastVertex + 2 || leftStyle == rightStyle)
    {
        SrcVertices.CutAt(LastVertex);
        return;
    }
    if (StrokerMode)
    {
        // only the outline counts: an edge needs a fill on exactly one side
        if ((leftStyle == 0) == (rightStyle == 0))
        {
            SrcVertices.CutAt(LastVertex);
            return;
        }
        if (leftStyle)
            leftStyle = 1;
        if (rightStyle)
            rightStyle = 1;
        leftComplex = rightComplex = false;
    }
    addStyle(leftStyle, leftComplex);
    addStyle(rightStyle, rightComplex);

    PathType path;
    path.start      = LastVertex;
    path.end        = (unsigned)SrcVertices.GetSize() - 1;
    path.leftStyle  = leftStyle;
    path.rightStyle = rightStyle;
    Paths.PushBack(path);
    LastVertex = (unsigned)SrcVertices.GetSize();
}

// @0x1426997e0
void Tessellator::GetSrcBounds(CoordType* x1, CoordType* y1, CoordType* x2, CoordType* y2) const
{
    CoordType minX = MaxCoord;
    CoordType minY = MaxCoord;
    CoordType maxX = MinCoord;
    CoordType maxY = MinCoord;
    for (UPInt i = 0; i < SrcVertices.GetSize(); ++i)
    {
        SrcVertexType v = SrcVertices[i];
        if (v.x < minX)
            minX = v.x;
        if (v.y < minY)
            minY = v.y;
        if (v.x > maxX)
            maxX = v.x;
        if (v.y > maxY)
            maxY = v.y;
    }
    *x1 = minX;
    *y1 = minY;
    *x2 = maxX;
    *y2 = maxY;
}

// cuts a path into chains going up from each local minimum, walking forward and then backward
// @0x1426a0a50
void Tessellator::decomposePath(const PathType& path)
{
    int lo, hi;
    int numEdges;
    for (lo = path.start; lo < (int)path.end; ++lo)
    {
        if (forwardMin(lo, path.start))
        {
            numEdges = 1;
            hi       = lo + 1;
            while (!forwardMax(hi, path.end))
            {
                ++numEdges;
                ++hi;
            }
            buildEdgeList(lo, numEdges, +1, path.leftStyle, path.rightStyle);
            lo += numEdges - 1;
        }
    }
    for (lo = path.end; lo > (int)path.start; --lo)
    {
        if (reverseMin(lo, path.end))
        {
            numEdges = 1;
            hi       = lo - 1;
            while (!reverseMax(hi, path.start))
            {
                ++numEdges;
                --hi;
            }
            buildEdgeList(lo, numEdges, -1, path.leftStyle, path.rightStyle);
            lo -= numEdges - 1;
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------
// styles along the scan line

SF_INLINE void Tessellator::incStyles(const MonoChainType* mc)
{
    unsigned ls = mc->leftStyle;
    unsigned rs = mc->rightStyle;
    if (FillRule == FillNonZero)
    {
        StyleCounts[ls] += mc->dir;
        StyleCounts[rs] -= mc->dir;
    }
    else
    {
        StyleCounts[ls] ^= 1;
        StyleCounts[rs] ^= 1;
    }
}

// the highest style that is currently "inside"
SF_INLINE UInt16 Tessellator::findElderStyle() const
{
    for (UPInt i = StyleCounts.GetSize(); i; --i)
    {
        if (StyleCounts[i - 1])
            return UInt16(i - 1);
    }
    return 0;
}

// works out the visible style on each side of every chain in aet, left to right
// @0x1426a35d0
void Tessellator::perceiveStyles(const ChainPtrArray& aet)
{
    StyleCounts.Zero();
    UInt16 left = 0;
    for (UPInt i = 0; i < aet.GetSize(); ++i)
    {
        MonoChainType* mc = aet[i];
        mc->flags &= ~VisibleChain;
        if ((mc->flags & EndChainFlag) == 0)
        {
            incStyles(mc);
            mc->rightAbove = findElderStyle();
            mc->leftAbove  = left;
            if (left != mc->rightAbove)
                mc->flags |= VisibleChain;
            left = mc->rightAbove;
        }
    }
}

// @0x1426a5740
void Tessellator::setupIntersections()
{
    InteriorChains.Clear();
    InteriorOrder.Clear();
    for (UPInt i = 0; i < ActiveChains.GetSize(); i++)
    {
        ActiveChains[i]->posIntr = (unsigned)i;
        InteriorChains.PushBack(ActiveChains[i]);
        InteriorOrder.PushBack((unsigned)i);
    }
}

SF_INLINE CoordType Tessellator::calcX(const EdgeType* edge, CoordType y) const
{
    const SrcVertexType& lo = SrcVertices[edge->lower];
    return lo.x + (y - lo.y) * edge->slope;
}

// advances the active chains to the beam yb..yt, merges in the numMc chains starting at yb and collects the
// crossings inside the beam (bubble sort by the top x)
// @0x1426a2930
unsigned Tessellator::nextScanbeam(CoordType yb, CoordType yt, unsigned startMc, unsigned numMc)
{
    UPInt                i, j;
    MonoChainType*       mc;
    const SrcVertexType* lo;
    const SrcVertexType* hi;
    unsigned             flags = 0;
    if (numMc)
        flags = InsertEdgesFlag;

    EdgeType* edge;
    ValidChains.Clear();
    for (i = 0; i < ActiveChains.GetSize(); ++i)
    {
        mc = ActiveChains[i];
        mc->flags &= ~EventFlag;
        edge = &Edges[mc->edge];
        if (SrcVertices[edge->lower + mc->dir].y == yb)
        {
            // the current edge ends here: next edge, or the chain ends
            if (mc->edge < mc->end)
            {
                edge   = &Edges[++mc->edge];
                lo     = &SrcVertices[edge->lower];
                hi     = &SrcVertices[edge->lower + mc->dir];
                mc->xb = lo->x;
                mc->xt = (hi->y == yt) ? hi->x : calcX(edge, yt);
                ValidChains.PushBack((unsigned)i);
            }
            else
            {
                mc->xb = mc->xt;
                mc->flags |= EndChainFlag;
                flags |= RemoveEdgesFlag;
            }
            mc->flags |= EventFlag;
        }
        else
        {
            lo     = &SrcVertices[edge->lower];
            hi     = &SrcVertices[edge->lower + mc->dir];
            mc->xb = mc->xt;
            mc->xt = (hi->y == yt) ? hi->x : calcX(edge, yt);
            ValidChains.PushBack((unsigned)i);
        }
    }

    if (numMc)
    {
        for (i = 0; i < numMc; ++i)
        {
            mc        = MonoChainsSorted[startMc + i];
            edge      = &Edges[mc->edge];
            lo        = &SrcVertices[edge->lower];
            hi        = &SrcVertices[edge->lower + mc->dir];
            mc->xb    = lo->x;
            mc->flags = EventFlag;
            mc->xt    = (hi->y == yt) ? hi->x : calcX(edge, yt);
            ActiveChains.PushBack(0);
        }
        // merge from the back
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
    if (flags & InsertEdgesFlag)
    {
        ValidChains.Clear();
        for (i = 0; i < ActiveChains.GetSize(); ++i)
        {
            if ((ActiveChains[i]->flags & EndChainFlag) == 0)
                ValidChains.PushBack((unsigned)i);
        }
    }

    CoordType        height = yt - yb;
    IntersectionType intr;
    for (i = 1; i < ValidChains.GetSize(); ++i)
    {
        SPInt k;
        for (k = i - 1; k >= 0; --k)
        {
            MonoChainType* mc1 = ActiveChains[ValidChains[k]];
            MonoChainType* mc2 = ActiveChains[ValidChains[k + 1]];
            if (mc1->xt <= mc2->xt)
                break;
            if (Intersections.GetSize() == 0)
                setupIntersections();

            CoordType num = mc1->xb - mc2->xb;
            CoordType den = mc2->xt - mc2->xb - mc1->xt + mc1->xb;
            intr.pos1     = mc1->posIntr;
            intr.pos2     = mc2->posIntr;
            intr.y        = (den == 0) ? yb : yb + height * num / den;
            if (intr.y < yb)
                intr.y = yb;
            if (intr.y > yt)
                intr.y = yt;
            Intersections.PushBack(intr);
            Alg::Swap(ActiveChains[ValidChains[k]], ActiveChains[ValidChains[k + 1]]);
        }
    }

    if (Intersections.GetSize() > 1)
    {
        Alg::InsertionSort(Intersections, cmpIntersectionY);
        if (HasEpsilon)
        {
            // snap crossings closer than epsilon onto the previous one
            CoordType y = yb;
            for (i = 0; i < Intersections.GetSize(); ++i)
            {
                if (Intersections[i].y - y < Epsilon * fabsf(y))
                    Intersections[i].y = y;
                y = Intersections[i].y;
            }
        }
    }
    return flags;
}

// ----------------------------------------------------------------------------------------------------------------
// monotone building

// a mesh vertex at v unless the last one emitted on this scan line is already there or right of it
SF_INLINE unsigned Tessellator::addEventVertex(const SrcVertexType& v)
{
    if (v.x > LastX)
    {
        TessVertex mv;
        mv.x = LastX = v.x;
        mv.y         = v.y;
        mv.Idx       = ~0U;
        mv.Styles[0] = mv.Styles[1] = 0xFFFF;
        mv.Flags     = TessStyleOpaque;
        mv.Mesh      = 0;
        MeshVertices.PushBack(mv);
    }
    return (unsigned)MeshVertices.GetSize() - 1;
}

// the mesh vertex where chain mc meets the scan line yb; ~0 when nothing happens on the chain there (unless
// enforceFlag)
// @0x14269ae70
unsigned Tessellator::addEventVertex(const MonoChainType* mc, CoordType yb, bool enforceFlag)
{
    EdgeType* edge = &Edges[mc->edge];
    if (!enforceFlag && (mc->flags & HasIntersection) == 0 && mc->leftBelow == mc->leftAbove &&
        mc->rightBelow == mc->rightAbove)
    {
        if ((mc->flags & EventFlag) != 0 && SrcVertices[edge->lower].y == yb)
            return addEventVertex(SrcVertices[edge->lower]);
        return ~0U;
    }

    if (SrcVertices[edge->lower].y == yb)
        return addEventVertex(SrcVertices[edge->lower]);
    if ((mc->flags & EndChainFlag) != 0 && SrcVertices[edge->lower + mc->dir].y == yb)
        return addEventVertex(SrcVertices[edge->lower + mc->dir]);

    CoordType x = calcX(edge, yb);
    if (x - LastX > fabsf(yb) * Epsilon)
    {
        TessVertex mv;
        mv.x = LastX = x;
        mv.y         = yb;
        mv.Idx       = ~0U;
        mv.Styles[0] = mv.Styles[1] = 0xFFFF;
        mv.Flags     = TessStyleOpaque;
        mv.Mesh      = 0;
        MeshVertices.PushBack(mv);
    }
    return (unsigned)MeshVertices.GetSize() - 1;
}

SF_INLINE void Tessellator::resetMonotone(MonotoneType* m, unsigned style)
{
    m->start        = 0;
    m->d.m.lastIdx  = ~0U;
    m->d.m.prevIdx1 = ~0U;
    m->d.m.prevIdx2 = ~0U;
    m->style        = style;
    m->lowerBase    = 0;
}

// appends a vertex to the monotone (a repeat of the last one is dropped)
SF_INLINE void Tessellator::growMonotone(MonotoneType* m, unsigned vertex)
{
    MonoVertexType mv;
    mv.next   = 0;
    mv.srcVer = vertex;
    mv.aaVer  = vertex;
    if (m->start == 0)
    {
        MonoVertices.PushBack(mv);
        m->start        = &MonoVertices.Back();
        m->d.m.prevIdx2 = ~0U;
        m->d.m.prevIdx1 = ~0U;
        m->d.m.lastIdx  = (unsigned)MonoVertices.GetSize() - 1;
    }
    else
    {
        MonoVertexType& last = MonoVertices[m->d.m.lastIdx];
        if (last.srcVer != vertex)
        {
            MonoVertices.PushBack(mv);
            last.next       = &MonoVertices.Back();
            m->d.m.prevIdx2 = m->d.m.prevIdx1;
            m->d.m.prevIdx1 = m->d.m.lastIdx;
            m->d.m.lastIdx  = (unsigned)MonoVertices.GetSize() - 1;
        }
    }
}

SF_INLINE unsigned Tessellator::lastMonoVertex(const MonotoneType* m) const
{
    return (m->d.m.lastIdx == ~0U) ? ~0U : MonoVertices[m->d.m.lastIdx].srcVer;
}

// takes back the last vertex (at most two can be undone)
void Tessellator::removeLastMonoVertex(MonotoneType* m)
{
    if (m->d.m.lastIdx != ~0U)
    {
        if (m->d.m.lastIdx == (unsigned)MonoVertices.GetSize() - 1)
            MonoVertices.PopBack();
        m->d.m.lastIdx  = m->d.m.prevIdx1;
        m->d.m.prevIdx1 = m->d.m.prevIdx2;
        m->d.m.prevIdx2 = ~0U;
        if (m->d.m.lastIdx == ~0U)
            m->start = 0;
        else
            MonoVertices[m->d.m.lastIdx].next = 0;
    }
}

SF_INLINE void Tessellator::growMonotone(MonotoneType* m, unsigned left, unsigned right)
{
    if (left != ~0U)
        growMonotone(m, left | LeftFlag);
    if (right != ~0U)
        growMonotone(m, right & ~LeftFlag);
}

// grows the monotone of a scan chain; a monotone with pending ends below gets them joined to the vertex first
SF_INLINE void Tessellator::growMonotone(ScanChainType* scan, unsigned vertex)
{
    if (scan && scan->monotone)
    {
        MonotoneType* m = scan->monotone;
        if (m->lowerBase)
        {
            if (m->lowerBase->y == MeshVertices[verIdx(vertex)].y)
                m->lowerBase->vertexRight = verIdx(vertex);
            else if (vertex & LeftFlag)
                connectPendingToLeft(scan, vertex);
            else
                connectPendingToRight(scan, vertex);
        }
        else
            growMonotone(m, vertex);
    }
}

// @0x1426a6180
Tessellator::MonotoneType* Tessellator::startMonotone(unsigned style)
{
    MonotoneType m;
    resetMonotone(&m, style);
    Monotones.PushBack(m);
    return &Monotones.Back();
}

// @0x1426a61f0
void Tessellator::startMonotone(ScanChainType* scan, unsigned vertex)
{
    scan->monotone = 0;
    if (scan->chain->rightAbove)
    {
        scan->monotone = startMonotone(scan->chain->rightAbove);
        growMonotone(scan, vertex);
    }
}

// gives the chain a monotone of the style: a new one, the current one restyled while still empty, or else a fresh
// copy that takes over the current one's vertices
// @0x1426a5320
void Tessellator::replaceMonotone(ScanChainType* scan, unsigned style)
{
    if (style)
    {
        if (scan->monotone == 0)
        {
            scan->monotone = startMonotone(style);
            return;
        }
        if (scan->monotone->style == style || scan->monotone->start == 0)
        {
            scan->monotone->style = style;
            return;
        }
        MonotoneType* m = startMonotone(style);
        *m              = *scan->monotone;
        resetMonotone(scan->monotone, style);
    }
}

// @0x1426a5290
void Tessellator::replaceMonotone(PendingEndType* pe, unsigned style)
{
    if (style)
    {
        if (pe->monotone == 0)
        {
            pe->monotone = startMonotone(style);
            return;
        }
        if (pe->monotone->style == style || pe->monotone->start == 0)
        {
            pe->monotone->style = style;
            return;
        }
        MonotoneType* m = startMonotone(style);
        *m              = *pe->monotone;
        resetMonotone(pe->monotone, style);
    }
}

// records that chain pending ends at y under the monotone of dst
// @0x14269b0b0
void Tessellator::addPendingEnd(ScanChainType* dst, ScanChainType* pending, CoordType y)
{
    if (dst && dst->monotone && dst->monotone->style)
    {
        MonotoneType* m = dst->monotone;
        if (m->lowerBase == 0)
        {
            BaseLineType base;
            base.y           = y;
            base.styleLeft   = pending->chain->leftBelow;
            base.vertexLeft  = dst->vertex;
            base.vertexRight = ~0U;
            base.firstChain  = (unsigned)PendingEnds.GetSize();
            base.numChains   = 0;
            base.leftAbove   = ~0U;
            BaseLines.PushBack(base);
            m->lowerBase = &BaseLines.Back();
        }
        PendingEndType pe;
        pe.vertex   = pending->vertex;
        pe.monotone = pending->monotone;
        PendingEnds.PushBack(pe);
        ++m->lowerBase->numChains;
    }
}

// walks the chains of a base line left to right; Chain / Style describe the area right of VertexLeft
template<class ElementsArray>
struct TessBaseLineIterator
{
    typedef typename ElementsArray::ValueType ScanChainType;

    template<class BaseLineType>
    TessBaseLineIterator(ElementsArray& e, BaseLineType* bl, ScanChainType* scanLeft)
        : Elements(e)
        , Index(bl->firstChain)
        , Num(bl->numChains)
        , VertexRightmost(bl->vertexRight)
        , Chain(scanLeft)
        , VertexLeft(bl->vertexLeft)
        , VertexRight(e[bl->firstChain].vertex)
        , Style(bl->styleLeft)
        , FlagFirst(true)
    {
    }

    template<class StyleFunction>
    bool Next(StyleFunction style)
    {
        FlagFirst = false;
        if (Num)
        {
            --Num;
            VertexLeft  = VertexRight;
            Chain       = &Elements[Index++];
            VertexRight = Num ? Elements[Index].vertex : VertexRightmost;
            Style       = style(Chain);
            return true;
        }
        return false;
    }

    bool IsFirst() const { return FlagFirst; }
    bool IsLast() const { return Num == 0; }

    ElementsArray& Elements;
    unsigned       Index;
    unsigned       Num;
    unsigned       VertexRightmost;
    ScanChainType* Chain;
    unsigned       VertexLeft;
    unsigned       VertexRight;
    unsigned       Style;
    bool           FlagFirst;

private:
    void operator=(const TessBaseLineIterator&);
};

// joins the pending ends under the monotone of scan to targetVertex on its left side
// @0x14269cd00
void Tessellator::connectPendingToLeft(ScanChainType* scan, unsigned targetVertex)
{
    BaseLineType* lowerBase  = scan->monotone->lowerBase;
    unsigned      styleAbove = scan->monotone->style;
    scan->monotone->lowerBase = 0;

    PendingEndType scanLeft;
    scanLeft.vertex   = lowerBase->vertexLeft;
    scanLeft.monotone = scan->monotone;

    TessBaseLineIterator<PendingEndArray> it(PendingEnds, lowerBase, &scanLeft);
    do
    {
        if (it.VertexLeft != it.VertexRight)
        {
            if (it.IsFirst())
            {
                growMonotone(scan->monotone, it.VertexRight);
                growMonotone(scan->monotone, targetVertex, targetVertex);
            }
            else
            {
                if (it.Style != styleAbove || it.Chain->monotone == 0)
                {
                    it.Chain->monotone = startMonotone(styleAbove);
                    growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
                }
                if (!it.IsLast())
                    growMonotone(it.Chain->monotone, targetVertex, targetVertex);
                else
                {
                    scan->monotone = it.Chain->monotone;
                    growMonotone(scan->monotone, targetVertex | LeftFlag);
                }
            }
        }
    } while (it.Next(pendingMonotoneStyle));

    if (lowerBase == &BaseLines.Back())
    {
        PendingEnds.CutAt(lowerBase->firstChain);
        BaseLines.PopBack();
    }
}

// the same with targetVertex on the right side
// @0x14269d550
void Tessellator::connectPendingToRight(ScanChainType* scan, unsigned targetVertex)
{
    BaseLineType* lowerBase  = scan->monotone->lowerBase;
    unsigned      styleAbove = scan->monotone->style;
    scan->monotone->lowerBase = 0;

    PendingEndType scanLeft;
    scanLeft.vertex   = lowerBase->vertexLeft;
    scanLeft.monotone = scan->monotone;

    TessBaseLineIterator<PendingEndArray> it(PendingEnds, lowerBase, &scanLeft);
    growMonotone(scan->monotone, it.VertexRight);
    growMonotone(scan->monotone, targetVertex);
    while (it.Next(pendingMonotoneStyle))
    {
        if (it.VertexLeft != it.VertexRight)
        {
            if (it.Style != styleAbove || it.Chain->monotone == 0)
            {
                it.Chain->monotone = startMonotone(styleAbove);
                growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
            }
            growMonotone(it.Chain->monotone, targetVertex, targetVertex);
        }
    }
    if (lowerBase == &BaseLines.Back())
    {
        PendingEnds.CutAt(lowerBase->firstChain);
        BaseLines.PopBack();
    }
}

// joins the chains starting on upperBase to targetVertex, a left vertex of the monotone of scan
// @0x14269df20
void Tessellator::connectStartingToLeft(ScanChainType* scan, BaseLineType* upperBase, unsigned targetVertex)
{
    ScanChainType* leftAbove = (upperBase->leftAbove == ~0U) ? scan : &ChainsAbove[upperBase->leftAbove];

    TessBaseLineIterator<ScanChainArray> it(ChainsAbove, upperBase, scan);
    unsigned      styleBelow = scan->monotone->style;
    MonotoneType* below      = startMonotone(0);
    *below                   = *scan->monotone;
    resetMonotone(scan->monotone, styleBelow);

    do
    {
        if (!it.IsLast())
        {
            if (it.VertexLeft != it.VertexRight)
            {
                replaceMonotone(it.Chain, styleBelow);
                growMonotone(it.Chain->monotone, targetVertex, targetVertex);
                growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
            }
        }
        else
        {
            it.Chain->monotone = below;
            growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
        }
        if (it.Style != styleBelow || it.Chain->monotone == 0)
        {
            if (!it.Style)
                it.Chain->monotone = 0;
            else
            {
                if (it.IsFirst())
                    it.Chain = leftAbove;
                replaceMonotone(it.Chain, it.Style);
                growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
            }
        }
    } while (it.Next(startingMonotoneStyle));
    upperBase->numChains = 0;
}

// the same with a right vertex
// @0x14269ffc0
void Tessellator::connectStartingToRight(ScanChainType* scan, BaseLineType* upperBase, unsigned targetVertex)
{
    ScanChainType* leftAbove = (upperBase->leftAbove == ~0U) ? scan : &ChainsAbove[upperBase->leftAbove];

    TessBaseLineIterator<ScanChainArray> it(ChainsAbove, upperBase, scan);
    unsigned styleBelow = scan->monotone->style;
    do
    {
        if (it.IsFirst())
            growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
        else if (it.VertexLeft != it.VertexRight)
        {
            replaceMonotone(it.Chain, styleBelow);
            growMonotone(it.Chain->monotone, targetVertex, targetVertex);
            growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
        }
        if (it.Style != styleBelow || it.Chain->monotone == 0)
        {
            if (!it.Style)
                it.Chain->monotone = 0;
            else
            {
                if (it.IsFirst())
                    it.Chain = leftAbove;
                replaceMonotone(it.Chain, it.Style);
                growMonotone(it.Chain->monotone, it.VertexLeft, it.VertexRight);
            }
        }
    } while (it.Next(startingMonotoneStyle));
    upperBase->numChains = 0;
}

// the chains ending below and the chains starting above meet: pair them up left to right, the extra starting
// chains go to the last pending vertex
// @0x14269e950
void Tessellator::connectStartingToPending(ScanChainType* scan, BaseLineType* upperBase)
{
    BaseLineType* lowerBase    = scan->monotone->lowerBase;
    unsigned      styleBetween = scan->monotone->style;
    scan->monotone->lowerBase  = 0;

    PendingEndType scanLeft;
    scanLeft.vertex   = lowerBase->vertexLeft;
    scanLeft.monotone = scan->monotone;

    TessBaseLineIterator<PendingEndArray> itLower(PendingEnds, lowerBase, &scanLeft);
    TessBaseLineIterator<ScanChainArray>  itUpper(ChainsAbove, upperBase, scan);
    unsigned lowerTarget = ~0U;
    unsigned stopNum     = itLower.Num < itUpper.Num;

    for (;;)
    {
        bool invalid = (itLower.VertexLeft == itLower.VertexRight &&
                        (itUpper.VertexLeft == ~0U || itUpper.VertexRight == ~0U)) ||
                       (itUpper.VertexLeft == itUpper.VertexRight &&
                        (itLower.VertexLeft == ~0U || itLower.VertexRight == ~0U));

        if (!invalid && (itLower.VertexLeft != itLower.VertexRight || itUpper.VertexLeft != itUpper.VertexRight))
        {
            if (itLower.Style != styleBetween)
            {
                replaceMonotone(itLower.Chain, styleBetween);
                growMonotone(itLower.Chain->monotone, itLower.VertexLeft, itLower.VertexRight);
            }
            growMonotone(itLower.Chain->monotone, itUpper.VertexLeft, itUpper.VertexRight);
            itUpper.Chain->monotone = itLower.Chain->monotone;
        }
        if (itUpper.Style != styleBetween || itUpper.Chain->monotone == 0)
        {
            if (!itUpper.Style)
                itUpper.Chain->monotone = 0;
            else
            {
                replaceMonotone(itUpper.Chain, itUpper.Style);
                growMonotone(itUpper.Chain->monotone, itUpper.VertexLeft, itUpper.VertexRight);
            }
        }
        if (itLower.Num == stopNum)
        {
            lowerTarget = itLower.VertexLeft;
            if (itLower.VertexRight != ~0U)
                lowerTarget = itLower.VertexRight;
            break;
        }
        itLower.Next(pendingMonotoneStyle);
        itUpper.Next(startingMonotoneStyle);
    }

    if (itUpper.Num && lowerTarget != ~0U)
    {
        MonotoneType* m = 0;
        itLower.Next(pendingMonotoneStyle);
        itUpper.Next(startingMonotoneStyle);
        if (itLower.Chain->monotone && itLower.Chain->monotone->style == styleBetween)
        {
            m  = startMonotone(styleBetween);
            *m = *itLower.Chain->monotone;
            resetMonotone(itLower.Chain->monotone, styleBetween);
        }
        do
        {
            if (itUpper.IsLast())
            {
                itUpper.Chain->monotone = m;
                if (itUpper.Chain->monotone == 0)
                {
                    itUpper.Chain->monotone = startMonotone(styleBetween);
                    growMonotone(itUpper.Chain->monotone, itLower.VertexLeft, itLower.VertexRight);
                }
                growMonotone(itUpper.Chain->monotone, itUpper.VertexLeft, itUpper.VertexRight);
            }
            else if (itUpper.VertexLeft != itUpper.VertexRight)
            {
                replaceMonotone(itUpper.Chain, styleBetween);
                growMonotone(itUpper.Chain->monotone, lowerTarget, lowerTarget);
                growMonotone(itUpper.Chain->monotone, itUpper.VertexLeft, itUpper.VertexRight);
            }
            if (itUpper.Style != styleBetween || itUpper.Chain->monotone == 0)
            {
                if (!itUpper.Style)
                    itUpper.Chain->monotone = 0;
                else
                {
                    replaceMonotone(itUpper.Chain, itUpper.Style);
                    growMonotone(itUpper.Chain->monotone, itUpper.VertexLeft, itUpper.VertexRight);
                }
            }
        } while (itUpper.Next(startingMonotoneStyle));
    }

    if (lowerBase == &BaseLines.Back())
    {
        PendingEnds.CutAt(lowerBase->firstChain);
        BaseLines.PopBack();
    }
    upperBase->numChains = 0;
}

// joins the chains starting on upperBase to the monotone of scan
// @0x14269dc40
void Tessellator::connectStarting(ScanChainType* scan, BaseLineType* upperBase)
{
    if (scan && scan->monotone)
    {
        unsigned i;
        unsigned target = lastMonoVertex(scan->monotone);

        // take back the (at most two) vertices on the scan line itself; the target is the last one below it
        upperBase->vertexLeft  = ~0U;
        upperBase->vertexRight = ~0U;
        for (i = 0; i < 2; i++)
        {
            if (target == ~0U || MeshVertices[verIdx(target)].y < upperBase->y)
                break;
            if (target & LeftFlag)
                upperBase->vertexLeft = verIdx(target);
            else
                upperBase->vertexRight = target;
            removeLastMonoVertex(scan->monotone);
            target = lastMonoVertex(scan->monotone);
        }

        if (scan->monotone->lowerBase)
        {
            connectStartingToPending(scan, upperBase);
            return;
        }

        if (target == ~0U)
        {
            // nothing below (broken input): put one of the taken vertices back
            if (upperBase->vertexRight != ~0U)
            {
                target                 = upperBase->vertexRight;
                upperBase->vertexRight = ~0U;
                growMonotone(scan->monotone, target);
            }
            else if (upperBase->vertexLeft != ~0U)
            {
                target                = upperBase->vertexLeft;
                upperBase->vertexLeft = ~0U;
                growMonotone(scan->monotone, target);
            }
        }

        if (target & LeftFlag)
            connectStartingToLeft(scan, upperBase, verIdx(target));
        else
            connectStartingToRight(scan, upperBase, target);
    }
    upperBase->numChains = 0;
}

// whether the next chain of a bundle through vertex starts or ends there (0: neither, or both)
SF_INLINE unsigned Tessellator::nextChainInBundle(unsigned below, unsigned above, unsigned vertex) const
{
    const ScanChainType* nextBelow = 0;
    const ScanChainType* nextAbove = 0;
    if (below < ChainsBelow.GetSize())
        nextBelow = &ChainsBelow[below];
    if (above < ChainsAbove.GetSize())
        nextAbove = &ChainsAbove[above];
    if (nextBelow && nextAbove && nextBelow->vertex == nextAbove->vertex)
        return 0;
    if (nextAbove && nextAbove->vertex == vertex)
        return ChainStartsAtScanline;
    if (nextBelow && nextBelow->vertex == vertex)
        return ChainEndsAtScanline;
    return 0;
}

// processes the scan line yb: the chains under it (ChainsBelow) are matched with the visible chains of aet over it
// (ChainsAbove), and the monotones between them are continued, started, ended or joined
// @0x1426a6500
void Tessellator::sweepScanbeam(const ChainPtrArray& aet, CoordType yb)
{
    UPInt          i;
    MonoChainType* mc;

    LastX = MinCoord;
    ChainsAbove.Clear();
    for (i = 0; i < aet.GetSize(); ++i)
    {
        mc          = aet[i];
        mc->posScan = (unsigned)i;
        if (mc->flags & VisibleChain)
        {
            ScanChainType scan;
            scan.chain    = mc;
            scan.monotone = 0;
            scan.vertex   = ~0U;
            ChainsAbove.PushBack(scan);
        }
    }

    unsigned below     = 0;
    unsigned above     = 0;
    unsigned prevAbove = ~0U;
    unsigned vertex;

    ScanChainType* thisBelow;
    ScanChainType* thisAbove;
    ScanChainType* leftBelow = 0;
    ScanChainType* leftAbove = 0;
    BaseLineType   upperBase;

    upperBase.y         = yb;
    upperBase.numChains = 0;

    // pass 1: the vertices on the scan line, left to right
    for (;;)
    {
        if (below < ChainsBelow.GetSize() && above < ChainsAbove.GetSize())
        {
            thisBelow = &ChainsBelow[below];
            thisAbove = &ChainsAbove[above];
            if (thisAbove->chain->posScan == thisBelow->chain->posScan)
            {
                thisBelow->vertex = thisAbove->vertex = addEventVertex(thisAbove->chain, yb, false);
                ++below;
                ++above;
            }
            else if (thisAbove->chain->posScan < thisBelow->chain->posScan)
            {
                thisAbove->vertex = addEventVertex(thisAbove->chain, yb, true);
                ++above;
            }
            else
            {
                thisBelow->vertex = addEventVertex(thisBelow->chain, yb, true);
                ++below;
            }
        }
        else if (above < ChainsAbove.GetSize())
        {
            thisAbove         = &ChainsAbove[above];
            thisAbove->vertex = addEventVertex(thisAbove->chain, yb, true);
            ++above;
        }
        else if (below < ChainsBelow.GetSize())
        {
            thisBelow         = &ChainsBelow[below];
            thisBelow->vertex = addEventVertex(thisBelow->chain, yb, true);
            ++below;
        }
        else
            break;
    }

    // pass 2: the monotones
    below = 0;
    above = 0;
    for (;;)
    {
        if (below < ChainsBelow.GetSize() && above < ChainsAbove.GetSize())
        {
            thisBelow = &ChainsBelow[below];
            thisAbove = &ChainsAbove[above];

            unsigned kind = ChainContinuesAtScanline;
            if (thisBelow->vertex != thisAbove->vertex)
            {
                kind = (thisAbove->chain->posScan < thisBelow->chain->posScan) ? ChainStartsAtScanline
                                                                               : ChainEndsAtScanline;
            }

            switch (kind)
            {
            case ChainContinuesAtScanline:
                vertex = thisBelow->vertex;
                if (vertex != ~0U)
                {
                    // the chain has a vertex here: close the area on its left
                    growMonotone(leftBelow, vertex);
                    growMonotone(leftAbove, vertex);
                    if (upperBase.numChains)
                        connectStarting(leftBelow, &upperBase);

                    // other chains through the same vertex
                    while ((kind = nextChainInBundle(below + 1, above + 1, vertex)) != 0)
                    {
                        if (kind == ChainStartsAtScanline)
                        {
                            leftAbove = thisAbove;
                            thisAbove = &ChainsAbove[++above];
                            startMonotone(leftAbove, vertex | LeftFlag);
                            growMonotone(leftAbove, vertex);
                        }
                        else
                        {
                            leftBelow = thisBelow;
                            thisBelow = &ChainsBelow[++below];
                            growMonotone(leftBelow, vertex | LeftFlag);
                            growMonotone(leftBelow, vertex);
                        }
                    }

                    // the area on the right: carried on when the style stays, a new monotone otherwise
                    growMonotone(thisBelow, vertex | LeftFlag);
                    if (thisBelow->chain->rightBelow == thisAbove->chain->rightAbove)
                    {
                        growMonotone(leftAbove, vertex);
                        thisAbove->monotone = thisBelow->monotone;
                    }
                    else
                        startMonotone(thisAbove, vertex | LeftFlag);
                }
                else
                {
                    if (upperBase.numChains)
                        connectStarting(leftBelow, &upperBase);
                    thisAbove->monotone = thisBelow->monotone;
                }
                prevAbove = above;
                leftBelow = thisBelow;
                leftAbove = thisAbove;
                ++below;
                ++above;
                break;

            case ChainStartsAtScanline:
                if (leftBelow && leftBelow->monotone && leftBelow->monotone->style)
                {
                    // starts inside a filled area: collect it on the upper base line
                    if (upperBase.numChains)
                        ++upperBase.numChains;
                    else
                    {
                        upperBase.styleLeft  = thisAbove->chain->leftAbove;
                        upperBase.firstChain = above;
                        upperBase.numChains  = 1;
                        upperBase.leftAbove  = prevAbove;
                    }
                    if (leftAbove && leftAbove->monotone && leftAbove->monotone->lowerBase &&
                        leftAbove->monotone->lowerBase->y == yb)
                    {
                        leftAbove->monotone->lowerBase->vertexRight = thisAbove->vertex;
                    }
                }
                else
                {
                    growMonotone(leftAbove, thisAbove->vertex);
                    startMonotone(thisAbove, thisAbove->vertex | LeftFlag);
                }
                leftAbove = thisAbove;
                ++above;
                break;

            case ChainEndsAtScanline:
                growMonotone(leftBelow, thisBelow->vertex);
                growMonotone(thisBelow, thisBelow->vertex | LeftFlag);
                if (upperBase.numChains)
                    connectStarting(leftBelow, &upperBase);
                addPendingEnd(leftAbove, thisBelow, yb);
                prevAbove = ~0U;
                leftBelow = thisBelow;
                ++below;
                break;
            }
        }
        else if (above < ChainsAbove.GetSize())
        {
            thisAbove = &ChainsAbove[above];
            growMonotone(leftAbove, thisAbove->vertex);
            startMonotone(thisAbove, thisAbove->vertex | LeftFlag);
            leftAbove = thisAbove;
            ++above;
        }
        else if (below < ChainsBelow.GetSize())
        {
            thisBelow = &ChainsBelow[below];
            growMonotone(leftBelow, thisBelow->vertex);
            growMonotone(thisBelow, thisBelow->vertex | LeftFlag);
            if (upperBase.numChains)
                connectStarting(leftBelow, &upperBase);
            addPendingEnd(leftAbove, thisBelow, yb);
            prevAbove = ~0U;
            leftBelow = thisBelow;
            ++below;
        }
        else
            break;
    }

    // what is above now is below the next scan line
    ChainsBelow.Clear();
    for (i = 0; i < ChainsAbove.GetSize(); ++i)
        ChainsBelow.PushBack(ChainsAbove[i]);
    for (i = 0; i < aet.GetSize(); ++i)
    {
        mc             = aet[i];
        mc->leftBelow  = mc->leftAbove;
        mc->rightBelow = mc->rightAbove;
        mc->flags &= ~HasIntersection;
    }
}

// applies the crossings startIn..endIn to the interior chain order
// @0x1426a63a0
void Tessellator::swapChains(unsigned startIn, unsigned endIn)
{
    unsigned i;
    for (i = startIn; i < endIn; i++)
    {
        const IntersectionType& in = Intersections[i];
        unsigned                i1 = InteriorOrder[in.pos1];
        unsigned                i2 = InteriorOrder[in.pos2];
        InteriorChains[i1]->flags |= HasIntersection;
        InteriorChains[i2]->flags |= HasIntersection;
        Alg::Swap(InteriorChains[i1], InteriorChains[i2]);
        Alg::Swap(InteriorOrder[in.pos1], InteriorOrder[in.pos2]);
    }
}

// sweeps the extra scan lines at the crossings inside the beam yb..yTop
// @0x1426a4c20
void Tessellator::processInterior(CoordType yb, CoordType yTop, unsigned perceiveFlag)
{
    unsigned                startIn = 0;
    unsigned                endIn   = 0;
    const IntersectionType* in;
    CoordType               yt = yb;

    // crossings right on the bottom line
    while (endIn < Intersections.GetSize())
    {
        in = &Intersections[endIn];
        yt = in->y;
        if (yt > yb)
            break;
        perceiveFlag = 1;
        ++endIn;
    }
    swapChains(startIn, endIn);
    if (perceiveFlag)
        perceiveStyles(InteriorChains);

    while (endIn < Intersections.GetSize())
    {
        CoordType yNext = yt;
        startIn         = endIn;
        while (endIn < Intersections.GetSize())
        {
            in    = &Intersections[endIn];
            yNext = in->y;
            if (yNext > yt)
                break;
            ++endIn;
        }
        perceiveStyles(InteriorChains);
        sweepScanbeam(InteriorChains, yb);
        swapChains(startIn, endIn);
        yb = yt;
        yt = yNext;
    }

    perceiveStyles(ActiveChains);
    if (yt < yTop)
        sweepScanbeam(ActiveChains, yt);
}

// the sweep: sorted distinct scan lines, the chains of all paths, then one beam at a time
// @0x1426a20a0
void Tessellator::monotonize()
{
    UPInt i, j;
    if (SrcVertices.GetSize() == 0)
        return;

    StyleCounts.Resize(MaxStyle + 1);
    for (i = 0; i < SrcVertices.GetSize(); ++i)
        Scanbeams.PushBack((unsigned)i);
    CmpScanbeams byY(SrcVertices);
    Alg::QuickSort(Scanbeams, byY);

    // merge scan lines closer than epsilon (the vertices are moved onto the lower one)
    CoordType y = MinCoord;
    for (i = j = 0; i < Scanbeams.GetSize(); ++i)
    {
        SrcVertexType& v = SrcVertices[Scanbeams[i]];
        if (v.y - y > fabsf(v.y) * Epsilon)
        {
            Scanbeams[j++] = Scanbeams[i];
            y              = v.y;
        }
        else
            v.y = y;
    }
    Scanbeams.CutAt(j);

    for (i = 0; i < Paths.GetSize(); ++i)
        decomposePath(Paths[i]);

    MonoChainsSorted.Resize(MonoChains.GetSize());
    for (i = 0; i < MonoChains.GetSize(); ++i)
        MonoChainsSorted[i] = &MonoChains[i];
    Alg::QuickSort(MonoChainsSorted, cmpMonoChains);

    unsigned  sb = 0;
    unsigned  mc = 0;
    CoordType yb, yt;
    yb = yt = SrcVertices[Scanbeams[0]].y;
    while (sb < Scanbeams.GetSize())
    {
        if (++sb < Scanbeams.GetSize())
            yt = SrcVertices[Scanbeams[sb]].y;

        unsigned startMc = mc;
        while (mc < MonoChainsSorted.GetSize() && MonoChainsSorted[mc]->ySort <= yb)
            ++mc;

        unsigned flags = nextScanbeam(yb, yt, startMc, mc - startMc);
        if (Intersections.GetSize())
            processInterior(yb, yt, flags);
        else
        {
            if (flags)
                perceiveStyles(ActiveChains);
            sweepScanbeam(ActiveChains, yb);
        }

        if (flags & RemoveEdgesFlag)
        {
            UPInt k, pos;
            for (k = pos = 0; k < ActiveChains.GetSize(); ++k)
            {
                MonoChainType* c = ActiveChains[k];
                if ((c->flags & EndChainFlag) == 0)
                    ActiveChains[pos++] = c;
            }
            ActiveChains.CutAt(pos);
        }
        yb = yt;
    }
}

// ----------------------------------------------------------------------------------------------------------------
// meshes

// the mesh of a single style (0 without complex fills)
// @0x1426a53b0
unsigned Tessellator::setMesh(unsigned style)
{
    if (!HasComplexFill)
        return 0;

    if (StyleMatrix.ValueAt(style, style) == 0xFFFF)
    {
        UInt32 cf = ComplexFlags[style >> 5] & (1 << (style & 31));
        if (cf)
        {
            StyleMatrix.At(style, style) = (UInt16)Meshes.GetSize();
            TessMesh mesh;
            mesh.MeshIdx     = (unsigned)Meshes.GetSize();
            mesh.Style1      = mesh.Style2 = style;
            mesh.Flags1      = mesh.Flags2 = cf ? TessStyleComplex : 0;
            mesh.VertexCount = 0;
            mesh.StartVertex = 0;
            Meshes.PushBack(mesh);
            MeshTriangles.AddArray();
        }
        else
            StyleMatrix.At(style, style) = 0;
    }
    return StyleMatrix.ValueAt(style, style);
}

SF_INLINE UInt32 Tessellator::isComplex(unsigned a, unsigned b) const
{
    return (ComplexFlags[a >> 5] & (1 << (a & 31))) | (ComplexFlags[b >> 5] & (1 << (b & 31)));
}

// the mesh that blends two styles; with a complex one involved it gets its own mesh (or the complex style's own)
// @0x1426a54b0
unsigned Tessellator::setMesh(unsigned style1, unsigned style2)
{
    if (!HasComplexFill)
        return 0;

    if (StyleMatrix.ValueAt(style1, style2) == 0xFFFF)
    {
        UInt32 cf1 = ComplexFlags[style1 >> 5] & (1 << (style1 & 31));
        UInt32 cf2 = ComplexFlags[style2 >> 5] & (1 << (style2 & 31));
        if (cf1 | cf2)
        {
            if (cf1)
                cf1 = TessStyleComplex;
            if (cf2)
                cf2 = TessStyleComplex;
            if (cf1 == 0)
            {
                // the complex one goes first
                Alg::Swap(style1, style2);
                Alg::Swap(cf1, cf2);
            }

            UInt16 meshIdx = (UInt16)Meshes.GetSize();
            UInt16 own     = StyleMatrix.ValueAt(style1, style1);
            if (cf2 == 0 && own != 0xFFFF && TessStyleIsComplex(Meshes[own].Flags2) == 0)
                meshIdx = own;
            else
            {
                TessMesh mesh;
                mesh.MeshIdx     = (unsigned)Meshes.GetSize();
                mesh.Style1      = style1;
                mesh.Style2      = cf2 ? style2 : 0;
                mesh.Flags1      = cf1;
                mesh.Flags2      = cf2;
                mesh.VertexCount = 0;
                mesh.StartVertex = 0;
                Meshes.PushBack(mesh);
                MeshTriangles.AddArray();
            }
            StyleMatrix.At(style1, style2) = meshIdx;
            StyleMatrix.At(style2, style1) = meshIdx;

            if (InvasiveMerge)
            {
                if (StyleMatrix.ValueAt(style1, style1) == 0xFFFF)
                    StyleMatrix.At(style1, style1) = meshIdx;
                if (StyleMatrix.ValueAt(style2, style2) == 0xFFFF)
                    StyleMatrix.At(style2, style2) = meshIdx;
            }
            else
            {
                if (StyleMatrix.ValueAt(style1, style1) == 0xFFFF && cf1 && !cf2)
                    StyleMatrix.At(style1, style1) = meshIdx;
            }
        }
        else
        {
            StyleMatrix.At(style1, style1) = 0;
            StyleMatrix.At(style2, style2) = 0;
            StyleMatrix.At(style1, style2) = 0;
            StyleMatrix.At(style2, style1) = 0;
        }
    }
    return StyleMatrix.ValueAt(style1, style2);
}

void Tessellator::GetMesh(unsigned meshIdx, TessMesh* mesh) const
{
    *mesh             = Meshes[meshIdx];
    mesh->StartVertex = 0;
}

// copies up to num vertices of the mesh; mesh->StartVertex is the resume point
// @0x142699ad0
unsigned Tessellator::GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const
{
    unsigned n = 0;
    for (n = 0; n < num && mesh->StartVertex < MeshVertices.GetSize(); ++mesh->StartVertex)
    {
        if (MeshVertices[mesh->StartVertex].Mesh == mesh->MeshIdx)
            vertices[n++] = MeshVertices[mesh->StartVertex];
    }
    return n;
}

// @0x1426999d0
void Tessellator::GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const
{
    for (unsigned j = 0; j < num; ++j)
    {
        const TriangleType& t = MeshTriangles.At(meshIdx, start + j);
        *idx++                = (UInt16)MeshVertices[t.d.t.v1].Idx;
        *idx++                = (UInt16)MeshVertices[t.d.t.v2].Idx;
        *idx++                = (UInt16)MeshVertices[t.d.t.v3].Idx;
    }
}

// the copy of vertex ver for the mesh and style: the copies of a vertex are chained through Idx (the last points to
// itself), a missing one is appended
// @0x1426a1e00
unsigned Tessellator::emitVertex(unsigned meshIdx, unsigned ver, unsigned style, unsigned flags)
{
    ver           = verIdx(ver);
    TessVertex* v = &MeshVertices[ver];
    if (v->Idx == ~0U)
    {
        v->Idx       = ver;
        v->Styles[0] = v->Styles[1] = UInt16(style);
        v->Flags     = UInt16(flags);
        v->Mesh      = UInt16(meshIdx);
        return ver;
    }
    if (v->Mesh == meshIdx && v->Styles[0] == style)
        return ver;
    while (v->Idx != ver)
    {
        ver = v->Idx;
        v   = &MeshVertices[ver];
        if (v->Mesh == meshIdx && v->Styles[0] == style)
            return ver;
    }
    ver = v->Idx = (unsigned)MeshVertices.GetSize();

    TessVertex copy = *v;
    copy.Idx        = ver;
    copy.Styles[0]  = copy.Styles[1] = UInt16(style);
    copy.Flags      = UInt16(flags);
    copy.Mesh       = UInt16(meshIdx);
    MeshVertices.PushBack(copy);
    return ver;
}

// @0x14269a3d0
void Tessellator::SortTrianglesByVertex1(unsigned meshIdx)
{
    TriangleArray::ArrayAdaptor tris = MeshTriangles.GetArrayAdaptor(meshIdx);
    CmpVer1                     byVer1(MeshVertices);
    Alg::QuickSort(tris, byVer1);
}

// cuts a mesh over the vertex limit into enough meshes (sorted by y, about a quarter spare for shared vertices);
// vertices used by more than one part are duplicated
// @0x1426a5990
void Tessellator::splitMesh(TessMesh* mesh)
{
    UPInt    i, j, n;
    unsigned limit     = VertexLimit - VertexLimit / 4;
    unsigned newMeshes = (mesh->VertexCount + limit - 1) / limit;
    unsigned triangles = (unsigned)MeshTriangles.GetSize(mesh->MeshIdx) / newMeshes;
    unsigned triIdx    = mesh->MeshIdx;

    SortTrianglesByVertex1(triIdx);

    n = MeshTriangles.GetSize(mesh->MeshIdx);
    for (i = 0; i < n; ++i)
    {
        TriangleType& tri                  = MeshTriangles.At(triIdx, i);
        MeshVertices[tri.d.t.v1].Mesh = 0xFFFF;
        MeshVertices[tri.d.t.v2].Mesh = 0xFFFF;
        MeshVertices[tri.d.t.v3].Mesh = 0xFFFF;
    }

    for (i = 1; i < newMeshes; ++i)
    {
        if (!MeshTriangles.Split(triIdx, triangles))
            break;
        Meshes[triIdx].VertexCount = ~0U;
        TessMesh part              = Meshes[triIdx];
        part.MeshIdx               = (unsigned)Meshes.GetSize();
        Meshes.PushBack(part);
        triIdx = part.MeshIdx;
    }

    for (i = 0; i < Meshes.GetSize(); ++i)
    {
        TessMesh& m = Meshes[i];
        if (m.VertexCount == ~0U)
        {
            n = MeshTriangles.GetSize(i);
            for (j = 0; j < n; ++j)
            {
                TriangleType& tri = MeshTriangles.At(i, j);
                TessVertex&   v1  = MeshVertices[tri.d.t.v1];
                TessVertex&   v2  = MeshVertices[tri.d.t.v2];
                TessVertex&   v3  = MeshVertices[tri.d.t.v3];
                if (v1.Mesh == 0xFFFF)
                    v1.Mesh = (UInt16)i;
                if (v2.Mesh == 0xFFFF)
                    v2.Mesh = (UInt16)i;
                if (v3.Mesh == 0xFFFF)
                    v3.Mesh = (UInt16)i;
                if (v1.Mesh != i)
                {
                    tri.d.t.v1 = (unsigned)MeshVertices.GetSize();
                    MeshVertices.PushBack(v1);
                    MeshVertices.Back().Mesh = (UInt16)i;
                }
                if (v2.Mesh != i)
                {
                    tri.d.t.v2 = (unsigned)MeshVertices.GetSize();
                    MeshVertices.PushBack(v2);
                    MeshVertices.Back().Mesh = (UInt16)i;
                }
                if (v3.Mesh != i)
                {
                    tri.d.t.v3 = (unsigned)MeshVertices.GetSize();
                    MeshVertices.PushBack(v3);
                    MeshVertices.Back().Mesh = (UInt16)i;
                }
            }
        }
    }
}

// @0x14269a410
void Tessellator::SplitMeshes()
{
    for (;;)
    {
        bool  done = true;
        UPInt i;
        UPInt n = Meshes.GetSize();
        for (i = 0; i < n; ++i)
        {
            if (Meshes[i].VertexCount > VertexLimit)
            {
                splitMesh(&Meshes[i]);
                done = false;
            }
        }
        if (done)
            break;

        // renumber the vertices per mesh
        for (i = 0; i < Meshes.GetSize(); ++i)
            Meshes[i].VertexCount = 0;
        for (i = 0; i < MeshVertices.GetSize(); ++i)
        {
            TessVertex& v = MeshVertices[i];
            if (v.Mesh != 0xFFFF)
                v.Idx = Meshes[v.Mesh].VertexCount++;
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------
// edge AA

// emitVertex for a two-style vertex; strictStyle also requires the same flags
// @0x1426a1f20
unsigned Tessellator::emitVertex(unsigned meshIdx, unsigned ver, unsigned style1, unsigned style2, unsigned flags,
                                 bool strictStyle)
{
    ver           = verIdx(ver);
    TessVertex* v = &MeshVertices[ver];
    if (v->Idx == ~0U)
    {
        v->Idx       = ver;
        v->Styles[0] = UInt16(style1);
        v->Styles[1] = UInt16(style2);
        v->Flags     = UInt16(flags);
        v->Mesh      = UInt16(meshIdx);
        return ver;
    }
    if (v->Mesh == meshIdx && v->Styles[0] == style1 && v->Styles[1] == style2 && (!strictStyle || v->Flags == flags))
        return ver;
    while (v->Idx != ver)
    {
        ver = v->Idx;
        v   = &MeshVertices[ver];
        if (v->Mesh == meshIdx && v->Styles[0] == style1 && v->Styles[1] == style2 &&
            (!strictStyle || v->Flags == flags))
            return ver;
    }
    ver = v->Idx = (unsigned)MeshVertices.GetSize();

    TessVertex copy = *v;
    copy.Idx        = ver;
    copy.Styles[0]  = UInt16(style1);
    copy.Styles[1]  = UInt16(style2);
    copy.Flags      = UInt16(flags);
    copy.Mesh       = UInt16(meshIdx);
    MeshVertices.PushBack(copy);
    return ver;
}

// two fan rays per vertex of one side of a monotone (to the previous and the next vertex around the polygon);
// cntVer->Idx is the vertex's first fan slot and cntVer->Mesh the slots used so far
// @0x14269c4f0
void Tessellator::collectFanEdges(const ChainVertexArray& chain, const ChainVertexArray& oppos, unsigned style)
{
    UPInt           i;
    MonoVertexType* prev = oppos.GetSize() ? oppos[0] : chain.Back();
    MonoVertexType* cur  = chain[0];
    for (i = 0; i < chain.GetSize(); ++i)
    {
        MonoVertexType* next = (i + 1 < chain.GetSize()) ? chain[i + 1] : (oppos.GetSize() ? oppos.Back() : chain[0]);

        TessVertex* cnt  = &MeshVertices[verIdx(cur->srcVer)];
        EdgeAAType* ray  = &EdgeFans[cnt->Idx + cnt->Mesh];
        ray->cntVer      = cur;
        ray->rayVer      = prev;
        ray->slope       = 0;
        ray->style       = UInt16(style);
        ++ray;
        ray->cntVer = cur;
        ray->rayVer = next;
        ray->slope  = 0;
        ray->style  = UInt16(style ^ 0x8000);
        cnt->Mesh += 2;
        prev = cur;
        cur  = next;
    }
}

// drops degenerate leading vertices and splits off the part after a repeated vertex (as a new monotone); counts
// two fan rays per remaining vertex into MeshVertices[].Mesh
// @0x1426a0910
unsigned Tessellator::countFanEdges(MonotoneType* m)
{
    unsigned        total = 0;
    MonoVertexType* prev  = m->start;
    MonoVertexType* cur   = prev ? prev->next : 0;
    if (cur == 0)
    {
        m->start = 0;
        return 0;
    }

    MonoVertexType* next = cur->next;
    while (next)
    {
        unsigned v1 = verIdx(prev->srcVer);
        unsigned v2 = verIdx(cur->srcVer);
        unsigned v3 = verIdx(next->srcVer);
        if (v1 != v2 && v2 != v3 && v3 != v1)
        {
            m->start = prev;
            break;
        }
        prev = cur;
        cur  = next;
        next = next->next;
    }
    if (next == 0)
    {
        m->start = 0;
        return 0;
    }

    prev = 0;
    cur  = m->start;
    while (cur)
    {
        if (prev && verIdx(prev->srcVer) == verIdx(cur->srcVer))
        {
            if (cur->next && cur->next->next)
            {
                MonotoneType rest = *m;
                rest.start        = cur;
                Monotones.PushBack(rest);
            }
            prev->next = 0;
            break;
        }
        MeshVertices[verIdx(cur->srcVer)].Mesh += 2;
        total += 2;
        prev = cur;
        cur  = cur->next;
    }
    return total;
}

// @0x14269c660
void Tessellator::collectFanEdges(MonotoneType* m)
{
    LeftChain.Clear();
    RightChain.Clear();
    for (MonoVertexType* v = m->start; v; v = v->next)
    {
        if (isLeft(v->srcVer))
            LeftChain.PushBack(v);
        else
            RightChain.PushBack(v);
    }
    if (LeftChain.GetSize())
        collectFanEdges(LeftChain, RightChain, m->style | 0x8000);
    if (RightChain.GetSize())
        collectFanEdges(RightChain, LeftChain, m->style);
}

// the outer AA vertex at the corner v1 v2 v3: the crossing of the two edges moved out by EdgeAAWidth, limited; with
// newVer2 a too long left miter becomes a bevel (two vertices, returns true)
// @0x14269c8e0
bool Tessellator::computeMiter(const TessVertex& v1, const TessVertex& v2, const TessVertex& v3, TessVertex* newVer1,
                               TessVertex* newVer2)
{
    CoordType xi      = v2.x;
    CoordType yi      = v2.y;
    CoordType len1    = Math2D::Distance(v1, v2);
    CoordType len2    = Math2D::Distance(v2, v3);
    CoordType turn    = Math2D::TurnRatio(v1, v2, v3, len1, len2);
    bool      left    = turn < 0;
    CoordType epsilon = (len1 + len2) * IntersectionEpsilon;
    CoordType dx1     = EdgeAAWidth * (v2.y - v1.y) / len1;
    CoordType dy1     = EdgeAAWidth * (v1.x - v2.x) / len1;
    CoordType dx2     = EdgeAAWidth * (v3.y - v2.y) / len2;
    CoordType dy2     = EdgeAAWidth * (v2.x - v3.x) / len2;
    bool      bevel   = false;

    turn = fabsf(turn);
    if (turn < 0.125f)
    {
        // nearly straight: move out along the longer edge
        if (len1 > len2)
        {
            xi = v2.x + dx1;
            yi = v2.y + dy1;
        }
        else
        {
            xi = v2.x + dx2;
            yi = v2.y + dy2;
        }
    }
    else if (Math2D::Intersection(v1.x + dx1, v1.y + dy1, v2.x + dx1, v2.y + dy1, v2.x + dx2, v2.y + dy2, v3.x + dx2,
                                  v3.y + dy2, &xi, &yi, epsilon))
    {
        CoordType dist = Math2D::Distance(v2.x, v2.y, xi, yi);
        CoordType lim;
        if (left)
            lim = EdgeAAWidth * 4.0f;
        else
            lim = ((len1 < len2) ? len1 : len2) / turn;
        if (dist > lim)
        {
            if (newVer2)
            {
                CoordType k = left ? 2.0f : 0.0f;
                xi          = v2.x + dx1 - k * dy1;
                yi          = v2.y + dy1 + k * dx1;
                newVer2->x  = v2.x + dx2 + k * dy2;
                newVer2->y  = v2.y + dy2 - k * dx2;
                bevel       = true;
            }
            else
            {
                lim /= dist;
                xi = v2.x + (xi - v2.x) * lim;
                yi = v2.y + (yi - v2.y) * lim;
            }
        }
    }
    else
    {
        xi = v2.x;
        yi = v2.y;
    }
    newVer1->x = xi;
    newVer1->y = yi;
    return bevel;
}

// the fan EdgeFans[start, end) of one vertex, sorted by direction: one AA vertex per run of rays of one style (a
// "star" around the center), inner quads between rays of different styles along the same edge, outer edges where
// the fill ends
// @0x1426a3d80
void Tessellator::processFan(unsigned start, unsigned end)
{
    if (start == end)
        return;

    UPInt       i;
    unsigned    i1;
    unsigned    i2;
    unsigned    nv = end - start;
    unsigned    ev;
    TessVertex  v1;
    EdgeAAType* e1;
    EdgeAAType* e2;

    i1 = end - 1;
    StartFan.Clear();
    EndFan.Clear();
    for (i2 = start; i2 < end; ++i2)
    {
        e1 = &EdgeFans[i1];
        e2 = &EdgeFans[i2];
        if (verIdx(e1->rayVer->srcVer) == verIdx(e2->rayVer->srcVer))
        {
            if (styleIdx(e1->style) != styleIdx(e2->style))
            {
                StartFan.PushBack(i2);
                EndFan.PushBack(i1);
            }
        }
        else if (e1->slope != e2->slope && !styleIsLeft(e1->style) && styleIsLeft(e2->style))
        {
            StartFan.PushBack(i2);
            EndFan.PushBack(i1);
        }
        i1 = i2;
    }

    if (StartFan.GetSize() == 0)
    {
        // an inner vertex: one opaque copy in place
        i2           = verIdx(EdgeFans[start].cntVer->srcVer);
        v1.x         = MeshVertices[i2].x;
        v1.y         = MeshVertices[i2].y;
        v1.Idx       = ~0U;
        v1.Styles[0] = v1.Styles[1] = styleIdx(EdgeFans[start].style);
        v1.Flags     = TessStyleOpaque;
        v1.Mesh      = 0xFFFF;
        for (i = start; i < end; ++i)
            EdgeFans[i].cntVer->aaVer = (unsigned)MeshVertices.GetSize();
        MeshVertices.PushBack(v1);
        return;
    }

    EndFan.PushBack(EndFan[0]);
    unsigned       endVer = (unsigned)StarVertices.GetSize();
    StarVertexType sv;
    sv.cntVer = verIdx(EdgeFans[start].cntVer->srcVer);
    for (i = 0; i < StartFan.GetSize(); ++i)
    {
        i1 = StartFan[i];
        i2 = EndFan[i + 1];
        e1 = &EdgeFans[i1];
        e2 = &EdgeFans[i2];

        // the inner (opaque) vertex of the run
        v1.Styles[0] = v1.Styles[1] = styleIdx(e1->style);
        if (verIdx(e1->rayVer->srcVer) != verIdx(e1->cntVer->srcVer) &&
            verIdx(e2->rayVer->srcVer) != verIdx(e1->cntVer->srcVer))
        {
            computeMiter(MeshVertices[verIdx(e1->rayVer->srcVer)], MeshVertices[verIdx(e1->cntVer->srcVer)],
                         MeshVertices[verIdx(e2->rayVer->srcVer)], &v1, 0);
        }
        else
        {
            v1.x = MeshVertices[verIdx(e1->cntVer->srcVer)].x;
            v1.y = MeshVertices[verIdx(e1->cntVer->srcVer)].y;
        }
        ev = (unsigned)MeshVertices.GetSize();
        if (i2 < i1)
            i2 += nv;
        for (; i1 <= i2; ++i1)
            EdgeFans[(i1 < end) ? i1 : i1 - nv].cntVer->aaVer = ev;

        v1.Idx       = ~0U;
        v1.Styles[0] = v1.Styles[1] = styleIdx(e1->style);
        v1.Flags     = TessStyleOpaque;
        v1.Mesh      = 0xFFFF;
        sv.starVer   = ev;
        MeshVertices.PushBack(v1);
        StarVertices.PushBack(sv);

        e2 = &EdgeFans[EndFan[i]];
        if (verIdx(e1->rayVer->srcVer) == verIdx(e2->rayVer->srcVer))
        {
            // two styles along one edge: a quad between them (once per edge)
            if ((e2->rayVer->aaVer & VisitedFlag) == 0)
            {
                InnerQuadType q;
                q.e1 = e1;
                q.e2 = e2;
                InnerQuads.PushBack(q);
                e1->cntVer->aaVer |= VisitedFlag;
            }
        }
        else
        {
            // the fill ends between e2 and e1: transparent outer vertices
            TessVertex v2;
            bool       bevel = false;
            if (verIdx(e1->rayVer->srcVer) != verIdx(e1->cntVer->srcVer) &&
                verIdx(e2->rayVer->srcVer) != verIdx(e1->cntVer->srcVer))
            {
                bevel = computeMiter(MeshVertices[verIdx(e2->rayVer->srcVer)],
                                     MeshVertices[verIdx(e1->cntVer->srcVer)],
                                     MeshVertices[verIdx(e1->rayVer->srcVer)], &v1, &v2);
            }
            else
            {
                v1.x = MeshVertices[verIdx(e1->cntVer->srcVer)].x;
                v1.y = MeshVertices[verIdx(e1->cntVer->srcVer)].y;
            }
            unsigned vi1 = (unsigned)MeshVertices.GetSize();
            unsigned vi2 = vi1;
            v1.Idx = v2.Idx = ~0U;
            v1.Styles[0] = v1.Styles[1] = styleIdx(e2->style);
            v2.Styles[0] = v2.Styles[1] = styleIdx(e1->style);
            v1.Flags = v2.Flags = 0;
            v1.Mesh = v2.Mesh = 0xFFFF;
            if (v1.Styles[0] != v2.Styles[0])
                setMesh(v1.Styles[0], v2.Styles[1]);
            MeshVertices.PushBack(v1);
            if (bevel)
            {
                vi2 = (unsigned)MeshVertices.GetSize();
                MeshVertices.PushBack(v2);
            }
            StarVertices.PushBack(StarVertices.Back());
            if (bevel)
            {
                StarVertices.PushBack(StarVertices.Back());
                StarVertices[StarVertices.GetSize() - 3].starVer = vi1;
                StarVertices[StarVertices.GetSize() - 2].starVer = vi2;
            }
            else
                StarVertices[StarVertices.GetSize() - 2].starVer = vi1;

            OuterEdgeType oe;
            oe.edge   = e1;
            oe.outVer = vi2;
            OuterEdges.PushBack(oe);
            oe.edge   = e2;
            oe.outVer = vi1 | VisitedFlag;
            OuterEdges.PushBack(oe);
        }
    }
    // a star needs at least three points
    if (endVer + 3 > StarVertices.GetSize())
        StarVertices.CutAt(endVer);
}

// writes out all AA triangles: the monotone interiors, the inner quads, the outer edge strips and the stars
// @0x1426a0d90
void Tessellator::emitTriangles()
{
    unsigned     i;
    TriangleType tri;
    unsigned     meshIdx;
    unsigned     style;
    unsigned     flags;
    unsigned     s1 = 0, s2 = 0, s3 = 0, m1 = 0, m2 = 0, m3 = 0, f1 = 0, f2 = 0, f3 = 0;

    for (i = 0; i < Monotones.GetSize(); ++i)
    {
        const MonotoneType& m = Monotones[i];
        if (m.d.t.numTriangles)
        {
            meshIdx = m.d.t.meshIdx;
            flags   = TessStyleOpaque | ((m.style == Meshes[meshIdx].Style1) ? TessStyleFactorOne : 0);
            for (unsigned j = 0; j < m.d.t.numTriangles; ++j)
            {
                TriangleType& t = MeshTriangles.At(meshIdx, m.d.t.startTriangle + j);
                t.d.m.v1->aaVer = emitVertex(meshIdx, t.d.m.v1->aaVer, m.style, flags);
                t.d.m.v2->aaVer = emitVertex(meshIdx, t.d.m.v2->aaVer, m.style, flags);
                t.d.m.v3->aaVer = emitVertex(meshIdx, t.d.m.v3->aaVer, m.style, flags);
                t.d.t.v1        = verIdx(t.d.m.v1->aaVer);
                t.d.t.v2        = verIdx(t.d.m.v2->aaVer);
                t.d.t.v3        = verIdx(t.d.m.v3->aaVer);
            }
        }
    }

    for (i = 0; i < InnerQuads.GetSize(); ++i)
    {
        EdgeAAType* e1 = InnerQuads[i].e1;
        EdgeAAType* e2 = InnerQuads[i].e2;
        s1             = styleIdx(e1->style);
        s2             = styleIdx(e2->style);
        meshIdx        = setMesh(s1, s2);
        const TessMesh& mesh = Meshes[meshIdx];
        if (mesh.Style1 && s1 != mesh.Style1)
        {
            Alg::Swap(e1, e2);
            Alg::Swap(s1, s2);
        }
        MonoVertexType* v1 = e1->cntVer;
        MonoVertexType* v2 = e1->rayVer;
        MonoVertexType* v3 = e2->cntVer;
        MonoVertexType* v4 = e2->rayVer;
        unsigned        s3 = s1;
        unsigned        f3 = 0;
        if (TessStyleIsComplex(mesh.Flags1 ^ mesh.Flags2))
        {
            s3 = s2;
            f3 = TessStyleUseColor2;
        }
        v1->aaVer  = emitVertex(meshIdx, v1->aaVer, s1, s3, TessStyleOpaque | TessStyleFactorOne | f3);
        v2->aaVer  = emitVertex(meshIdx, v2->aaVer, s1, s3, TessStyleOpaque | TessStyleFactorOne | f3);
        v3->aaVer  = emitVertex(meshIdx, v3->aaVer, s2, TessStyleOpaque);
        v4->aaVer  = emitVertex(meshIdx, v4->aaVer, s2, TessStyleOpaque);
        tri.d.t.v1 = verIdx(v1->aaVer);
        tri.d.t.v2 = verIdx(v2->aaVer);
        tri.d.t.v3 = verIdx(v3->aaVer);
        MeshTriangles.PushBack(meshIdx, tri);
        tri.d.t.v1 = verIdx(v4->aaVer);
        tri.d.t.v2 = verIdx(v3->aaVer);
        tri.d.t.v3 = verIdx(v2->aaVer);
        MeshTriangles.PushBack(meshIdx, tri);
    }

    // each outer edge with its reverse twin makes a strip of two triangles
    Alg::QuickSort(OuterEdges, cmpOuterEdges);
    for (i = 0; i < OuterEdges.GetSize(); ++i)
    {
        OuterEdgeType* e1 = &OuterEdges[i];
        if ((e1->outVer & VisitedFlag) == 0)
        {
            EdgeAAType rev;
            rev.cntVer = e1->edge->rayVer;
            rev.rayVer = e1->edge->cntVer;
            rev.slope  = 0;
            rev.style  = 0;
            OuterEdgeType key;
            key.edge     = &rev;
            key.outVer   = ~0U;
            unsigned idx = (unsigned)Alg::LowerBound(OuterEdges, key, cmpOuterEdges);
            if (idx < OuterEdges.GetSize())
            {
                OuterEdgeType* e2 = &OuterEdges[idx];
                if (e2->edge->cntVer == e1->edge->rayVer)
                {
                    meshIdx             = setMesh(style = styleIdx(e1->edge->style));
                    flags               = (style == Meshes[meshIdx].Style1) ? TessStyleFactorOne : 0;
                    MonoVertexType* mv1 = e1->edge->cntVer;
                    MonoVertexType* mv2 = e1->edge->rayVer;
                    unsigned        i1  = emitVertex(meshIdx, mv1->aaVer, style, flags | TessStyleOpaque);
                    unsigned        i2  = emitVertex(meshIdx, mv2->aaVer, style, flags | TessStyleOpaque);
                    e1->outVer          = emitVertex(meshIdx, e1->outVer, style, flags) | VisitedFlag;
                    e2->outVer          = emitVertex(meshIdx, e2->outVer, style, flags) | VisitedFlag;
                    unsigned i3         = verIdx(e1->outVer);
                    unsigned i4         = verIdx(e2->outVer);
                    tri.d.t.v1          = i1;
                    tri.d.t.v2          = i2;
                    tri.d.t.v3          = i3;
                    MeshTriangles.PushBack(meshIdx, tri);
                    tri.d.t.v1 = i4;
                    tri.d.t.v2 = i3;
                    tri.d.t.v3 = i2;
                    MeshTriangles.PushBack(meshIdx, tri);
                }
            }
        }
    }

    // the stars: a triangle when three points fit one mesh, else a fan around the center
    for (i = 0; i < StarVertices.GetSize();)
    {
        unsigned cntVer  = StarVertices[i].cntVer;
        unsigned endStar = i;
        while (++endStar < StarVertices.GetSize() && cntVer == StarVertices[endStar].cntVer)
        {
        }

        meshIdx = ~0U;
        if (i + 3 == endStar)
        {
            m1 = StarVertices[i + 0].starVer;
            m2 = StarVertices[i + 1].starVer;
            m3 = StarVertices[i + 2].starVer;
            s1 = MeshVertices[m1].Styles[0];
            s2 = MeshVertices[m2].Styles[0];
            s3 = MeshVertices[m3].Styles[0];
            f1 = MeshVertices[m1].Flags;
            f2 = MeshVertices[m2].Flags;
            f3 = MeshVertices[m3].Flags;
            m1 = setMesh(s1, s2);
            m2 = setMesh(s2, s3);
            m3 = setMesh(s3, s1);
            if (m1 == m2 || m1 == m3)
                meshIdx = m1;
            else if (m2 == m3)
                meshIdx = m2;
        }

        if (meshIdx != ~0U)
        {
            m1         = StarVertices[i + 0].starVer;
            m2         = StarVertices[i + 1].starVer;
            m3         = StarVertices[i + 2].starVer;
            tri.d.t.v1 = tri.d.t.v2 = tri.d.t.v3 = ~0U;
            if (TessStyleIsComplex(Meshes[meshIdx].Flags1 ^ Meshes[meshIdx].Flags2))
            {
                unsigned c1 = ComplexFlags[s1 >> 5] & (1 << (s1 & 31));
                unsigned c2 = ComplexFlags[s2 >> 5] & (1 << (s2 & 31));
                unsigned c3 = ComplexFlags[s3 >> 5] & (1 << (s3 & 31));
                if (c1)
                    tri.d.t.v1 = emitVertex(meshIdx, m1, s1, c2 ? s3 : s2, f1 | TessStyleUseColor2);
                if (c2)
                    tri.d.t.v2 = emitVertex(meshIdx, m2, s2, c3 ? s1 : s3, f2 | TessStyleUseColor2);
                if (c3)
                    tri.d.t.v3 = emitVertex(meshIdx, m3, s3, c1 ? s2 : s1, f3 | TessStyleUseColor2);
            }
            if (tri.d.t.v1 == ~0U)
                tri.d.t.v1 = emitVertex(meshIdx, m1, s1, f1);
            if (tri.d.t.v2 == ~0U)
                tri.d.t.v2 = emitVertex(meshIdx, m2, s2, f2);
            if (tri.d.t.v3 == ~0U)
                tri.d.t.v3 = emitVertex(meshIdx, m3, s3, f3);
            MeshTriangles.PushBack(meshIdx, tri);
        }
        else
        {
            unsigned i1 = endStar - 1;
            unsigned i2 = i;
            for (; i2 < endStar; ++i2)
            {
                m1      = StarVertices[i1].starVer;
                m2      = StarVertices[i2].starVer;
                s1      = MeshVertices[m1].Styles[0];
                s2      = MeshVertices[m2].Styles[0];
                f1      = MeshVertices[m1].Flags & TessStyleOpaque;
                f2      = MeshVertices[m2].Flags & TessStyleOpaque;
                meshIdx = setMesh(s1, s2);
                const TessMesh& mesh = Meshes[meshIdx];
                if (mesh.Style1 && s1 != mesh.Style1)
                {
                    Alg::Swap(m1, m2);
                    Alg::Swap(s1, s2);
                    Alg::Swap(f1, f2);
                }
                s3 = s1;
                f3 = f1 | TessStyleFactorOne;
                if (TessStyleIsComplex(mesh.Flags1 ^ mesh.Flags2))
                {
                    s3 = s2;
                    f3 |= TessStyleUseColor2;
                }
                tri.d.t.v1 = emitVertex(meshIdx, m1, s1, s3, f3);
                tri.d.t.v2 = emitVertex(meshIdx, m2, s2, f2);

                f3 = ((f1 & f2) & TessStyleOpaque) ? TessStyleOpaque : TessStyleTranslucent;
                if (!TessStyleIsComplex(mesh.Flags1 | mesh.Flags2))
                {
                    s3 = s2;
                    f3 |= TessStyleMixColors;
                }
                else
                {
                    f3 |= TessStyleFactorHalf | TessStyleUseColor2;
                    f3 &= ~TessStyleFactorOne;
                }
                tri.d.t.v3 = emitVertex(meshIdx, cntVer, s1, s3, f3, true);
                MeshTriangles.PushBack(meshIdx, tri);
                i1 = i2;
            }
        }
        i = endStar;
    }
}

// where the segments v1 v2 and v3 v4 cross, strictly inside v1 v2
template<class V1, class V2, class V3, class V4>
SF_INLINE static bool TessIntersection(const V1& v1, const V2& v2, const V3& v3, const V4& v4, CoordType* x,
                                    CoordType* y, CoordType epsilon)
{
    CoordType num = (v1.y - v3.y) * (v4.x - v3.x) - (v1.x - v3.x) * (v4.y - v3.y);
    CoordType den = (v2.x - v1.x) * (v4.y - v3.y) - (v2.y - v1.y) * (v4.x - v3.x);
    if (fabs(den) < epsilon)
        return false;
    CoordType u = num / den;
    if (u <= 0 || u >= 1)
        return false;
    *x = v1.x + u * (v2.x - v1.x);
    *y = v1.y + u * (v2.y - v1.y);
    return true;
}

// pulls an AA vertex that went past the opposite edge v2 v3 back to just inside it
// @0x1426a2740
void Tessellator::moveVertexAA(const TessVertex& refVer, TessVertex* aaVer, const TessVertex& v2, const TessVertex& v3)
{
    CoordType x, y;
    CoordType epsilon = (fabsf(refVer.x - aaVer->x) + fabsf(refVer.y - aaVer->y) + fabsf(v2.x - v3.x) +
                         fabsf(v2.y - v3.y)) *
                        IntersectionEpsilon;
    if (TessIntersection(refVer, *aaVer, v2, v3, &x, &y, epsilon))
    {
        aaVer->x = x + (refVer.x - x) * 0.125f;
        aaVer->y = y + (refVer.y - y) * 0.125f;
    }
    else
    {
        aaVer->x = refVer.x;
        aaVer->y = refVer.y;
    }
}

// @0x14269bac0
void Tessellator::addTriangleAA(MonoVertexType* v1, MonoVertexType* v2, MonoVertexType* v3, CoordType)
{
    TriangleType tri;
    if (EdgeAAFlag)
    {
        const TessVertex& ref1 = MeshVertices[verIdx(v1->srcVer)];
        const TessVertex& ref2 = MeshVertices[verIdx(v2->srcVer)];
        const TessVertex& ref3 = MeshVertices[verIdx(v3->srcVer)];
        TessVertex*       aa1  = &MeshVertices[verIdx(v1->aaVer)];
        TessVertex*       aa2  = &MeshVertices[verIdx(v2->aaVer)];
        TessVertex*       aa3  = &MeshVertices[verIdx(v3->aaVer)];
        if (Math2D::CrossProduct(ref2, ref3, *aa1) >= 0)
            moveVertexAA(ref1, aa1, ref2, ref3);
        if (Math2D::CrossProduct(ref3, ref1, *aa2) >= 0)
            moveVertexAA(ref2, aa2, ref3, ref1);
        if (Math2D::CrossProduct(ref1, ref2, *aa3) >= 0)
            moveVertexAA(ref3, aa3, ref1, ref2);
        tri.d.m.v1 = v1;
        tri.d.m.v2 = v2;
        tri.d.m.v3 = v3;
    }
    else
    {
        tri.d.t.v1 = emitVertex(MeshIdx, verIdx(v1->srcVer), MonoStyle, FactorOneFlag);
        tri.d.t.v2 = emitVertex(MeshIdx, verIdx(v2->srcVer), MonoStyle, FactorOneFlag);
        tri.d.t.v3 = emitVertex(MeshIdx, verIdx(v3->srcVer), MonoStyle, FactorOneFlag);
    }
    MeshTriangles.PushBack(MeshIdx, tri);
}

SF_INLINE CoordType Tessellator::triangleRatio(MonoVertexType* m1, MonoVertexType* m2, MonoVertexType* m3) const
{
    return Math2D::LinePointDistance(MeshVertices[verIdx(m1->srcVer)], MeshVertices[verIdx(m2->srcVer)],
                                     MeshVertices[verIdx(m3->srcVer)]);
}

// ear-clips the "mountain" in MonoStack (a chain plus the base edge between its ends), preferring the ears at the
// two ends that stand out furthest
// @0x1426a81a0
void Tessellator::triangulateMountainAA()
{
    if (MonoStack.GetSize() > 2)
    {
        UPInt             i;
        CoordType         s   = 0;
        unsigned          ear = ~0U;
        const TessVertex& b1  = MeshVertices[verIdx(MonoStack[0]->srcVer)];
        const TessVertex& b2  = MeshVertices[verIdx(MonoStack.Back()->srcVer)];
        for (i = 1; i + 1 < MonoStack.GetSize(); ++i)
        {
            const TessVertex& v = MeshVertices[verIdx(MonoStack[i]->srcVer)];
            s += Math2D::CrossProduct(b1, b2, v);
        }

        int      d  = (s > 0) ? +1 : -1;
        unsigned n1 = 0;
        unsigned n2 = (unsigned)MonoStack.GetSize();
        while (n2 > n1 + 3)
        {
            CoordType s1, s2, s3, s4;
            s1  = triangleRatio(MonoStack[n1 + 2], MonoStack[n1 + 0], MonoStack[n1 + 1]);
            s2  = triangleRatio(MonoStack[n1 + 3], MonoStack[n1 + 1], MonoStack[n1 + 2]);
            s3  = triangleRatio(MonoStack[n2 - 1], MonoStack[n2 - 3], MonoStack[n2 - 2]);
            s4  = triangleRatio(MonoStack[n2 - 2], MonoStack[n2 - 4], MonoStack[n2 - 3]);
            ear = ~0U;
            if (d > 0)
            {
                s = -EdgeAAWidth;
                if (s1 < 0 && s2 < 0)
                {
                    if (s1 < s)
                    {
                        s   = s1;
                        ear = n1 + 1;
                    }
                    if (s2 < s)
                    {
                        s   = s2;
                        ear = n1 + 2;
                    }
                }
                if (s2 < 0 && s4 < 0)
                {
                    if (s3 < s)
                    {
                        s   = s3;
                        ear = n2 - 2;
                    }
                    if (s4 < s)
                    {
                        s   = s4;
                        ear = n2 - 3;
                    }
                }
            }
            else
            {
                s = +EdgeAAWidth;
                if (s1 > 0 && s2 > 0)
                {
                    if (s1 > s)
                    {
                        s   = s1;
                        ear = n1 + 1;
                    }
                    if (s2 > s)
                    {
                        s   = s2;
                        ear = n1 + 2;
                    }
                }
                if (s3 > 0 && s4 > 0)
                {
                    if (s3 > s)
                    {
                        s   = s3;
                        ear = n2 - 2;
                    }
                    if (s4 > s)
                    {
                        s   = s4;
                        ear = n2 - 3;
                    }
                }
            }

            if (ear != ~0U)
            {
                addTriangleAA(MonoStack[ear - d], MonoStack[ear], MonoStack[ear + d], 0);
                if (ear == n1 + 1)
                {
                    MonoStack[n1 + 1] = MonoStack[n1 + 0];
                    ++n1;
                }
                else if (ear == n1 + 2)
                {
                    MonoStack[n1 + 2] = MonoStack[n1 + 1];
                    MonoStack[n1 + 1] = MonoStack[n1 + 0];
                    ++n1;
                }
                else if (ear == n2 - 2)
                {
                    MonoStack[n2 - 2] = MonoStack[n2 - 1];
                    --n2;
                }
                else
                {
                    MonoStack[n2 - 3] = MonoStack[n2 - 2];
                    MonoStack[n2 - 2] = MonoStack[n2 - 1];
                    --n2;
                }
            }
            else
            {
                // no good end ear: clip the furthest standing one anywhere
                s = 0;
                for (i = n1 + 1; i + 1 < n2; ++i)
                {
                    s1 = triangleRatio(MonoStack[i + 1], MonoStack[i - 1], MonoStack[i]);
                    if (d > 0)
                    {
                        if (s1 < s)
                        {
                            s   = s1;
                            ear = (unsigned)i;
                        }
                    }
                    else
                    {
                        if (s1 > s)
                        {
                            s   = s1;
                            ear = (unsigned)i;
                        }
                    }
                }
                if (ear == ~0U)
                    return;
                addTriangleAA(MonoStack[ear - d], MonoStack[ear], MonoStack[ear + d], 0);
                for (i = ear + 1; i < n2; ++i)
                    MonoStack[i - 1] = MonoStack[i];
                n2--;
            }
        }
        addTriangleAA(MonoStack[n1 + 1 - d], MonoStack[n1 + 1], MonoStack[n1 + 1 + d], 0);
    }
}

// splits the monotone into mountains at each switch of side and triangulates them
// @0x1426a7f00
void Tessellator::triangulateMonotoneAA(MonotoneType* m)
{
    MonoVertexType* vertex = m->start;
    MonoStyle              = m->style;
    MeshIdx                = setMesh(MonoStyle);
    FactorOneFlag          = TessStyleOpaque | ((MonoStyle == Meshes[MeshIdx].Style1) ? TessStyleFactorOne : 0);
    Meshes[MeshIdx].Flags1 |= FactorOneFlag & TessStyleFactorOne;

    m->d.t.startTriangle = ~0U;
    m->d.t.numTriangles  = 0;
    m->d.t.meshIdx       = MeshIdx;
    if (vertex == 0 || vertex->next == 0 || vertex->next->next == 0)
        return;

    m->d.t.startTriangle = (unsigned)MeshTriangles.GetSize(MeshIdx);
    MonoStack.Clear();
    MonoStack.PushBack(vertex);
    vertex = vertex->next;
    MonoStack.PushBack(vertex);
    vertex = vertex->next;
    while (vertex)
    {
        MonoVertexType* top  = vertex;
        MonoVertexType* prev = MonoStack.Back();
        MonoStack.PushBack(top);
        if (isLeft(top->srcVer) != isLeft(prev->srcVer))
        {
            triangulateMountainAA();
            MonoStack.Clear();
            MonoStack.PushBack(prev);
            MonoStack.PushBack(top);
        }
        vertex = vertex->next;
    }
    triangulateMountainAA();
    m->d.t.numTriangles = (unsigned)MeshTriangles.GetSize(MeshIdx) - m->d.t.startTriangle;
}

// AA triangles that came out flipped get the vertex opposite their longest edge pulled back (up to 8 passes)
// @0x1426a8af0
void Tessellator::unflipTriangles()
{
    bool     flipped = true;
    unsigned pass;
    for (pass = 0; flipped && pass < 8; ++pass)
    {
        flipped = false;
        for (UPInt i = 0; i < MeshTriangles.GetArrayCount(); ++i)
        {
            UPInt nt = MeshTriangles.GetSize(i);
            for (UPInt j = 0; j < nt; ++j)
            {
                const TriangleType& t    = MeshTriangles.At(i, j);
                const TessVertex&   ref1 = MeshVertices[verIdx(t.d.m.v1->srcVer)];
                const TessVertex&   ref2 = MeshVertices[verIdx(t.d.m.v2->srcVer)];
                const TessVertex&   ref3 = MeshVertices[verIdx(t.d.m.v3->srcVer)];
                TessVertex&         aa1  = MeshVertices[verIdx(t.d.m.v1->aaVer)];
                TessVertex&         aa2  = MeshVertices[verIdx(t.d.m.v2->aaVer)];
                TessVertex&         aa3  = MeshVertices[verIdx(t.d.m.v3->aaVer)];
                if (Math2D::CrossProduct(aa1, aa2, aa3) >= 0)
                {
                    CoordType d1      = Math2D::SqDistance(aa1.x, aa1.y, aa2.x, aa2.y);
                    CoordType d2      = Math2D::SqDistance(aa2.x, aa2.y, aa3.x, aa3.y);
                    CoordType d3      = Math2D::SqDistance(aa3.x, aa3.y, aa1.x, aa1.y);
                    CoordType epsilon = sqrtf(d1 + d2 + d3) * IntersectionEpsilon;
                    CoordType x, y;
                    int       edge = (d1 > d2) ? ((d1 > d3) ? 1 : 3) : ((d2 > d3) ? 2 : 3);
                    switch (edge)
                    {
                    case 1:
                        if (TessIntersection(aa3, ref3, aa1, aa2, &x, &y, epsilon))
                        {
                            aa3.x = x + (ref3.x - x) * 0.125f;
                            aa3.y = y + (ref3.y - y) * 0.125f;
                        }
                        else
                        {
                            aa3.x = ref3.x;
                            aa3.y = ref3.y;
                        }
                        break;
                    case 2:
                        if (TessIntersection(aa1, ref1, aa2, aa3, &x, &y, epsilon))
                        {
                            aa1.x = x + (ref1.x - x) * 0.125f;
                            aa1.y = y + (ref1.y - y) * 0.125f;
                        }
                        else
                        {
                            aa1.x = ref1.x;
                            aa1.y = ref1.y;
                        }
                        break;
                    case 3:
                        if (TessIntersection(aa2, ref2, aa3, aa1, &x, &y, epsilon))
                        {
                            aa2.x = x + (ref2.x - x) * 0.125f;
                            aa2.y = y + (ref2.y - y) * 0.125f;
                        }
                        else
                        {
                            aa2.x = ref2.x;
                            aa2.y = ref2.y;
                        }
                        break;
                    }
                    if (Math2D::CrossProduct(aa1, aa2, aa3) >= 0)
                    {
                        // still flipped: give up on AA for this triangle
                        aa1.x = ref1.x;
                        aa1.y = ref1.y;
                        aa2.x = ref2.x;
                        aa2.y = ref2.y;
                        aa3.x = ref3.x;
                        aa3.y = ref3.y;
                    }
                    flipped = true;
                }
            }
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------
// stroker mode: the outline edges of the monotones, widened into trapezoids with joins

// @0x14269b360
void Tessellator::addStrokerEdge(unsigned v1, unsigned v2)
{
    StrokerEdgeType e;
    e.node1 = verIdx(v1);
    e.node2 = verIdx(v2);
    if (e.node1 != e.node2)
        StrokerEdges.PushBack(e);
}

// @0x1426a0ce0
void Tessellator::emitStrokerTrapezoid(const StrokerEdgeType* edge, unsigned v1, unsigned v2)
{
    TriangleType tri;
    tri.d.t.v1 = verIdx(edge->node1);
    tri.d.t.v2 = v1;
    tri.d.t.v3 = v2;
    MeshTriangles.PushBack(0, tri);
    tri.d.t.v1 = verIdx(edge->node2);
    tri.d.t.v2 = verIdx(edge->node1);
    tri.d.t.v3 = v2;
    MeshTriangles.PushBack(0, tri);
}

// @0x1426a0d50
void Tessellator::emitStrokerVertex(CoordType x, CoordType y)
{
    TessVertex v;
    v.x         = x;
    v.y         = y;
    v.Idx       = ~0U;
    v.Styles[0] = v.Styles[1] = 1;
    v.Flags     = 0;
    v.Mesh      = 0;
    MeshVertices.PushBack(v);
}

// the outer vertices of the join e1 -> e2 (1, or 2 for a bevel); returns their count
// @0x14269b480
unsigned Tessellator::addStrokerJoin(const StrokerEdgeType* e1, const StrokerEdgeType* e2)
{
    unsigned          ref     = verIdx(e1->node2);
    const TessVertex& v1      = MeshVertices[verIdx(e1->node1)];
    const TessVertex& v2      = MeshVertices[ref];
    const TessVertex& v3      = MeshVertices[verIdx(e2->node2)];
    CoordType         width   = -2 * EdgeAAWidth;
    CoordType         len1    = Math2D::Distance(v1, v2);
    CoordType         len2    = Math2D::Distance(v2, v3);
    CoordType         turn    = Math2D::TurnRatio(v1, v2, v3, len1, len2);
    CoordType         epsilon = (len1 + len2) * IntersectionEpsilon;
    CoordType         dx1     = width * (v1.y - v2.y) / len1;
    CoordType         dy1     = width * (v2.x - v1.x) / len1;
    CoordType         dx2     = width * (v2.y - v3.y) / len2;
    CoordType         dy2     = width * (v3.x - v2.x) / len2;
    CoordType         xi      = v2.x;
    CoordType         yi      = v2.y;
    unsigned          nv      = 1;

    if (fabsf(turn) < 0.125f)
    {
        if (len1 > len2)
            emitStrokerVertex(v2.x + dx1, v2.y + dy1);
        else
            emitStrokerVertex(v2.x + dx2, v2.y + dy2);
    }
    else if (Math2D::Intersection(v1.x + dx1, v1.y + dy1, v2.x + dx1, v2.y + dy1, v2.x + dx2, v2.y + dy2, v3.x + dx2,
                                  v3.y + dy2, &xi, &yi, epsilon))
    {
        CoordType dist = Math2D::Distance(v2.x, v2.y, xi, yi);
        CoordType lim;
        if (turn > 0)
        {
            lim = ((len1 < len2) ? len1 : len2) / turn;
            if (dist > lim)
            {
                emitStrokerVertex(v2.x + dx1, v2.y + dy1);
                emitStrokerVertex(v2.x + dx2, v2.y + dy2);
                nv = 2;
            }
            else
                emitStrokerVertex(xi, yi);
        }
        else
        {
            lim = -width * 4;
            if (dist <= lim)
                emitStrokerVertex(xi, yi);
            else
            {
                // bevel, with the triangle filling the corner
                emitStrokerVertex(v2.x + dx1 - 2 * dy1, v2.y + dy1 + 2 * dx1);
                emitStrokerVertex(v2.x + dx2 + 2 * dy2, v2.y + dy2 - 2 * dx2);
                TriangleType tri;
                tri.d.t.v1 = ref;
                tri.d.t.v2 = (unsigned)MeshVertices.GetSize() - 2;
                tri.d.t.v3 = (unsigned)MeshVertices.GetSize() - 1;
                MeshTriangles.PushBack(0, tri);
                nv = 2;
            }
        }
    }
    else
    {
        emitStrokerVertex(v2.x + dx1, v2.y + dy1);
        emitStrokerVertex(v2.x + dx2, v2.y + dy2);
        nv = 2;
    }
    return nv;
}

// collects the monotone outlines, drops the edges shared by two monotones (inner edges) and widens the remaining
// loops
// @0x1426a4dc0
void Tessellator::processStrokerEdges()
{
    UPInt i;
    for (i = 0; i < Monotones.GetSize(); ++i)
    {
        const MonotoneType&   m = Monotones[i];
        const MonoVertexType* v = m.start;
        if (v == 0)
            continue;
        unsigned prevLeft = v->srcVer;
        v                 = v->next;
        if (v == 0)
            continue;
        unsigned prevRight = v->srcVer;
        addStrokerEdge(prevLeft, prevRight);
        while ((v = v->next) != 0)
        {
            if (isLeft(v->srcVer))
            {
                addStrokerEdge(v->srcVer, prevLeft);
                prevLeft = v->srcVer;
            }
            else
            {
                addStrokerEdge(prevRight, v->srcVer);
                prevRight = v->srcVer;
            }
        }
        addStrokerEdge(prevRight, prevLeft);
    }
    if (StrokerEdges.GetSize() < 2)
        return;

    // an edge whose reverse also exists is inside the shape
    Alg::QuickSort(StrokerEdges, cmpStrokerEdges);
    for (i = 0; i < StrokerEdges.GetSize(); ++i)
    {
        StrokerEdgeType& e1 = StrokerEdges[i];
        if ((e1.node1 & VisitedFlag) == 0)
        {
            StrokerEdgeType rev;
            rev.node1 = e1.node2;
            rev.node2 = e1.node1;
            UPInt pos = Alg::LowerBound(StrokerEdges, rev, cmpStrokerEdges);
            if (pos < StrokerEdges.GetSize())
            {
                StrokerEdgeType& e2 = StrokerEdges[pos];
                if (e1.node1 == e2.node2 && e1.node2 == e2.node1)
                {
                    e1.node1 |= VisitedFlag;
                    e2.node1 |= VisitedFlag;
                }
            }
        }
    }

    // follow each loop of outline edges
    for (i = 0; i < StrokerEdges.GetSize(); ++i)
    {
        StrokerEdgeType* first = &StrokerEdges[i];
        if ((first->node1 & VisitedFlag) == 0)
        {
            StrokerEdgeType* cur     = first;
            unsigned         firstV  = ~0U;
            unsigned         prevVer = ~0U;
            for (;;)
            {
                UPInt            pos  = Alg::LowerBound(StrokerEdges, cur->node2, cmpStrokerNode1);
                StrokerEdgeType* next = 0;
                while (pos < StrokerEdges.GetSize())
                {
                    StrokerEdgeType* e = &StrokerEdges[pos];
                    if ((e->node1 & VisitedFlag) == 0 && verIdx(e->node1) == verIdx(cur->node2))
                    {
                        next = e;
                        break;
                    }
                    ++pos;
                }
                if (next == 0)
                    break;

                unsigned nv = addStrokerJoin(cur, next);
                if (prevVer != ~0U)
                {
                    emitStrokerTrapezoid(cur, prevVer, (unsigned)MeshVertices.GetSize() - nv);
                    cur->node1 |= VisitedFlag;
                }
                else
                    firstV = (unsigned)MeshVertices.GetSize() - nv;

                if (next == first)
                {
                    emitStrokerTrapezoid(first, (unsigned)MeshVertices.GetSize() - 1, firstV);
                    first->node1 |= VisitedFlag;
                    break;
                }
                prevVer = (unsigned)MeshVertices.GetSize() - 1;
                cur     = next;
            }
        }
    }
}

// the edge AA pass: fans per vertex, sorted by direction, AA vertices, then the triangles
// @0x1426a3700
void Tessellator::processEdgeAA()
{
    UPInt    i;
    unsigned total = 0;
    for (i = 0; i < Monotones.GetSize(); ++i)
        total += countFanEdges(&Monotones[i]);
    EdgeFans.Resize(total);

    // first fan slot of each vertex
    total = 0;
    TessVertex* ver;
    for (i = 0; i < MeshVertices.GetSize(); ++i)
    {
        ver       = &MeshVertices[i];
        ver->Idx  = total;
        total    += ver->Mesh;
        ver->Mesh = 0;
    }
    for (i = 0; i < Monotones.GetSize(); ++i)
        collectFanEdges(&Monotones[i]);

    UPInt numVertices = MeshVertices.GetSize();
    for (i = 0; i < numVertices; ++i)
    {
        ver = &MeshVertices[i];
        TmpEdgeFan.Clear();
        UPInt j;
        for (j = 0; j < ver->Mesh; ++j)
        {
            const EdgeAAType& e = EdgeFans[ver->Idx + j];
            TmpEdgeAAType     te;
            te.cntVer = e.cntVer;
            te.rayVer = e.rayVer;
            te.style  = e.style;
            te.slope  = Math2D::SlopeRatio(MeshVertices[verIdx(te.cntVer->srcVer)],
                                           MeshVertices[verIdx(te.rayVer->srcVer)]);
            TmpEdgeFan.PushBack(te);
        }
        Alg::QuickSort(TmpEdgeFan, cmpEdgeAA);

        // back into the fan in order, the slope replaced by its rank
        unsigned  rank  = 0;
        CoordType slope = MinCoord;
        for (j = 0; j < TmpEdgeFan.GetSize(); ++j)
        {
            EdgeAAType&          e  = EdgeFans[ver->Idx + j];
            const TmpEdgeAAType& te = TmpEdgeFan[j];
            e.cntVer                = te.cntVer;
            e.rayVer                = te.rayVer;
            e.style                 = UInt16(te.style);
            e.slope                 = UInt16(rank);
            if (te.slope != slope)
            {
                ++rank;
                slope = te.slope;
            }
        }
        processFan(ver->Idx, ver->Idx + ver->Mesh);
        ver->Idx  = ~0U;
        ver->Mesh = 0xFFFF;
    }

    for (i = 0; i < Monotones.GetSize(); ++i)
        triangulateMonotoneAA(&Monotones[i]);
    unflipTriangles();
    emitTriangles();
}

// @0x14269a870
void Tessellator::Tessellate(bool autoSplitMeshes)
{
    UPInt i;
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    monotonize();

    // mesh 0 is the plain solid one
    TessMesh solid;
    solid.MeshIdx     = 0;
    solid.Style1      = solid.Style2 = 0;
    solid.Flags1      = solid.Flags2 = 0;
    solid.VertexCount = 0;
    solid.StartVertex = 0;
    Meshes.PushBack(solid);

    if (HasComplexFill)
    {
        StyleMatrix.Resize(MaxStyle + 1);
        for (i = 0; i < Paths.GetSize(); ++i)
        {
            const PathType& p = Paths[i];
            if (p.leftStyle && p.rightStyle)
                setMesh(p.leftStyle, p.rightStyle);
        }
        for (i = 0; i < Paths.GetSize(); ++i)
        {
            const PathType& p = Paths[i];
            if (p.leftStyle)
                setMesh(p.leftStyle);
            if (p.rightStyle)
                setMesh(p.rightStyle);
        }
    }

    clearHeap1();
    for (i = 0; i < Meshes.GetSize(); ++i)
        MeshTriangles.AddArray();

    if (EdgeAAFlag)
    {
        if (StrokerMode)
        {
            setMesh(1);
            EdgeAAFlag = false;
            for (i = 0; i < Monotones.GetSize(); ++i)
                triangulateMonotoneAA(&Monotones[i]);
            EdgeAAFlag = true;
            processStrokerEdges();
        }
        else
            processEdgeAA();
    }
    else
    {
        for (i = 0; i < Monotones.GetSize(); ++i)
            triangulateMonotoneAA(&Monotones[i]);
    }

    for (i = 0; i < MeshVertices.GetSize(); ++i)
    {
        TessVertex& v = MeshVertices[i];
        if (v.Mesh != 0xFFFF)
            v.Idx = Meshes[v.Mesh].VertexCount++;
    }
    if (autoSplitMeshes && VertexLimit && MeshVertices.GetSize() > VertexLimit)
        SplitMeshes();
}

// @0x14269ad40
void Tessellator::Transform(const Matrix2F& m)
{
    UPInt i;
    MinX = MaxCoord;
    MinY = MaxCoord;
    MaxX = MinCoord;
    MaxY = MinCoord;
    for (i = 0; i < MeshVertices.GetSize(); ++i)
    {
        TessVertex& v = MeshVertices[i];
        m.Transform(&v.x, &v.y);
        if (v.x < MinX)
            MinX = v.x;
        if (v.y < MinY)
            MinY = v.y;
        if (v.x > MaxX)
            MaxX = v.x;
        if (v.y > MaxY)
            MaxY = v.y;
    }
}

// maps the mesh bounds onto x1 y1 x2 y2 and returns the inverse mapping
// @0x14269a570
Matrix2F Tessellator::StretchTo(float x1, float y1, float x2, float y2)
{
    Matrix2F m;
    UPInt    i;
    if (MinX >= MaxX || MinY >= MaxY)
    {
        MinX = MaxCoord;
        MinY = MaxCoord;
        MaxX = MinCoord;
        MaxY = MinCoord;
        for (i = 0; i < MeshVertices.GetSize(); ++i)
        {
            TessVertex v = MeshVertices[i];
            if (v.x < MinX)
                MinX = v.x;
            if (v.y < MinY)
                MinY = v.y;
            if (v.x > MaxX)
                MaxX = v.x;
            if (v.y > MaxY)
                MaxY = v.y;
        }
    }
    if (MinX < MaxX && MinY < MaxY)
    {
        m.SetRectToRect(MinX, MinY, MaxX, MaxY, x1, y1, x2, y2);
        for (i = 0; i < MeshVertices.GetSize(); ++i)
        {
            TessVertex& v = MeshVertices[i];
            m.Transform(&v.x, &v.y);
        }
        m.Invert();
    }
    return m;
}

// the exe keeps an out-of-line copy of the rect-to-rect mapping in this TU (0x14269a2d0)
template Matrix2F& Matrix2F::SetRectToRect(float, float, float, float, float, float, float, float);

}} // namespace Scaleform::Render
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
// MS2-PIN: ??_7Tessellator@Render@Scaleform@@6B@ 0x143192370
