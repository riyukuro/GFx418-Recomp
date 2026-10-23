// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the shape mesh provider TU
// (Render_ShapeMeshProvider): ShapeMeshProvider (the draw layers of a shape and the fills / strokes they tessellate
// to), MorphShapeData and the MorphInterpolator that blends the two ends of a morph shape, the float shape data
// instance it records them in, and the bound / hit-test templates over ShapeDataInterface.
// MS2-UNIT: sfr_render_03d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142620040-0x1426202f0 .text$mn
// MS2-RANGE: 0x142623c60-0x142624020 .text$mn
// MS2-RANGE: 0x142626190-0x142633210 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_boundbox.h"
#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/kernel/sf_alg.h"

namespace Scaleform { namespace Render {

typedef ArrayLH_POD<UByte>                MorphContainer;
typedef ShapeDataFloatTempl<MorphContainer> MorphShapeFloat;

// ***** MorphInterpolator

// A shape whose styles and coordinates sit between a shape and its morph target. With morph data the paths come
// from the re-encoded pair (ShapeData1 read through the caller's position, ShapeData2 through Pos2, kept here),
// without it everything is passed through to the shape. 0x98 bytes, vftable 0x14318f320.
class MorphInterpolator : public ShapeDataInterface
{
public:
    MorphInterpolator(ShapeDataInterface* shape, MorphShapeData* morph, float ratio, const ShapePosInfo& pos2)
        : pShapeData(shape), pMorphData(morph), MorphRatio(ratio), Pos2(pos2), Pos2s(pos2)
    {
    }

    virtual unsigned      GetFillStyleCount() const { return pShapeData->GetFillStyleCount(); }
    virtual unsigned      GetStrokeStyleCount() const { return pShapeData->GetStrokeStyleCount(); }
    virtual void          GetFillStyle(unsigned idx, FillStyleType* p) const;
    virtual void          GetStrokeStyle(unsigned idx, StrokeStyleType* p) const;
    virtual unsigned      GetStartingPos() const;
    virtual void          Rewind() const;
    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const;
    virtual PathEdgeType  ReadEdge(ShapePosInfo* pos, float* coord) const;
    virtual void          SkipPathData(ShapePosInfo* pos) const;

private:
    Ptr<ShapeDataInterface> pShapeData;   // +0x10
    Ptr<MorphShapeData>     pMorphData;   // +0x18
    float                   MorphRatio;   // +0x20
    mutable ShapePosInfo    Pos2;         // +0x24: reader of ShapeData2
    ShapePosInfo            Pos2s;        // +0x5c: where Rewind puts it back
};

// A solid color moves toward the target's; complex fills are left to the fill matrix.
// @0x14262bae0
void MorphInterpolator::GetFillStyle(unsigned idx, FillStyleType* p) const
{
    pShapeData->GetFillStyle(idx, p);
    if (!pMorphData || MorphRatio == 0)
        return;

    FillStyleType target;
    pMorphData->pMorphTo->GetFillStyle(idx, &target);
    if (!p->pFill)
        p->Color = Color::Blend(Color(p->Color), Color(target.Color), MorphRatio).Raw;
}

// @0x14262be50
void MorphInterpolator::GetStrokeStyle(unsigned idx, StrokeStyleType* p) const
{
    pShapeData->GetStrokeStyle(idx, p);
    if (!pMorphData || MorphRatio == 0)
        return;

    StrokeStyleType target;
    pMorphData->pMorphTo->GetStrokeStyle(idx, &target);
    p->Width = Alg::Lerp(p->Width, target.Width, MorphRatio);
    if (!p->pFill)
        p->Color = Color::Blend(Color(p->Color), Color(target.Color), MorphRatio).Raw;
}

// @0x14262bd80
unsigned MorphInterpolator::GetStartingPos() const
{
    const ShapeDataInterface* shape =
        pMorphData ? Ptr<ShapeDataInterface>(&pMorphData->ShapeData1) : pShapeData;
    return shape->GetStartingPos();
}

// @0x14262cd60
void MorphInterpolator::Rewind() const
{
    Pos2 = Pos2s;
}

// @0x14262ca10
ShapePathType MorphInterpolator::ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
{
    if (!pMorphData)
        return pShapeData->ReadPathInfo(pos, coord, styles);

    float    coord2[Edge_MaxCoord];
    unsigned styles2[3];
    ShapePathType type = pMorphData->ShapeData1.ReadPathInfo(pos, coord, styles);
    pMorphData->ShapeData2.ReadPathInfo(&Pos2, coord2, styles2);
    if (type != Shape_EndShape)
    {
        coord[0] = Alg::Lerp(coord[0], coord2[0], MorphRatio);
        coord[1] = Alg::Lerp(coord[1], coord2[1], MorphRatio);
    }
    return type;
}

// @0x14262c600
PathEdgeType MorphInterpolator::ReadEdge(ShapePosInfo* pos, float* coord) const
{
    if (!pMorphData)
        return pShapeData->ReadEdge(pos, coord);

    float coord2[Edge_MaxCoord];
    PathEdgeType type = pMorphData->ShapeData1.ReadEdge(pos, coord);
    pMorphData->ShapeData2.ReadEdge(&Pos2, coord2);
    if (type != Edge_EndPath)
    {
        coord[0] = Alg::Lerp(coord[0], coord2[0], MorphRatio);
        coord[1] = Alg::Lerp(coord[1], coord2[1], MorphRatio);
        if (type == Edge_QuadTo || type == Edge_CubicTo)
        {
            coord[2] = Alg::Lerp(coord[2], coord2[2], MorphRatio);
            coord[3] = Alg::Lerp(coord[3], coord2[3], MorphRatio);
        }
        if (type == Edge_CubicTo)
        {
            coord[4] = Alg::Lerp(coord[4], coord2[4], MorphRatio);
            coord[5] = Alg::Lerp(coord[5], coord2[5], MorphRatio);
        }
    }
    return type;
}

// @0x14262cfb0
void MorphInterpolator::SkipPathData(ShapePosInfo* pos) const
{
    if (!pMorphData)
    {
        pShapeData->SkipPathData(pos);
        return;
    }
    pMorphData->ShapeData1.SkipPathData(pos);
    pMorphData->ShapeData2.SkipPathData(&Pos2);
}

// ***** MorphShapeData

// @0x142629e70
MorphShapeData::MorphShapeData(ShapeDataInterface* morphTo)
    : pMorphTo(morphTo), ShapeData1(&Container1, 0), ShapeData2(&Container2, 0)
{
}

// ***** ShapeMeshProvider

// @0x142629fa0
ShapeMeshProvider::ShapeMeshProvider(ShapeDataInterface* shape, ShapeDataInterface* shapeMorph)
    : pShapeData(shape), pMorphData(0), IdentityBounds(), GradientMorph(false), Strokes(false)
{
    if (shapeMorph)
    {
        pMorphData = *SF_HEAP_AUTO_NEW(this) MorphShapeData(shapeMorph);
        createMorphData();
    }
    acquireShapeData();
}

// @0x14262a650
void ShapeMeshProvider::AttachShape(ShapeDataInterface* shape, ShapeDataInterface* shapeMorph)
{
    pShapeData = shape;
    if (shapeMorph)
    {
        pMorphData = *SF_HEAP_AUTO_NEW(this) MorphShapeData(shapeMorph);
        createMorphData();
    }
    acquireShapeData();
}
// Re-encodes the two ends of the morph so that they have the same path records. Both ends always have the same
// number of edges, but a path may end earlier on one side: then the other side's path is split there and the
// short side continues from where its path started. An edge kind mismatch (line against quad) promotes the line
// to a quad with its control point at the midpoint. Gradients that differ between the ends are linked for
// morphing.
// @0x142630260
// MS2-FUNCTIONAL: the exe tail-duplicates the final EndPath/EndShape blocks; tag-byte store operand order differs
void ShapeMeshProvider::createMorphData()
{
    ShapeDataInterface* from = pShapeData;
    ShapeDataInterface* to   = pMorphData->pMorphTo;

    unsigned i;
    for (i = 0; i < from->GetFillStyleCount(); ++i)
    {
        FillStyleType fill1;
        from->GetFillStyle(i + 1, &fill1);
        if (fill1.pFill && fill1.pFill->pGradient)
        {
            FillStyleType fill2;
            to->GetFillStyle(i + 1, &fill2);
            if (!(*fill1.pFill->pGradient == *fill2.pFill->pGradient))
            {
                fill1.pFill->pGradient->SetMorphTo(fill2.pFill->pGradient);
                GradientMorph = true;
            }
        }
    }
    for (i = 0; i < from->GetStrokeStyleCount(); ++i)
    {
        StrokeStyleType stroke1;
        from->GetStrokeStyle(i + 1, &stroke1);
        if (stroke1.pFill && stroke1.pFill->pGradient)
        {
            StrokeStyleType stroke2;
            to->GetStrokeStyle(i + 1, &stroke2);
            if (!(*stroke1.pFill->pGradient == *stroke2.pFill->pGradient))
            {
                stroke1.pFill->pGradient->SetMorphTo(stroke2.pFill->pGradient);
                GradientMorph = true;
            }
        }
    }

    unsigned     startPos1 = from->GetStartingPos();
    unsigned     startPos2 = to->GetStartingPos();
    ShapePosInfo pos1(startPos1);
    ShapePosInfo pos2(startPos2);

    ShapePathType path1, path2;
    PathEdgeType  edge1, edge2;
    float         coord1[Edge_MaxCoord];
    float         coord2[Edge_MaxCoord];
    float         last1[2];
    float         last2[2];
    unsigned      styles1[3];
    unsigned      styles2[3];

    pMorphData->ShapeData1.Clear();
    pMorphData->ShapeData2.Clear();

    bool finished = false;
    bool firstPath = true;
    while (!finished)
    {
        path1 = from->ReadPathInfo(&pos1, coord1, styles1);
        path2 = to->ReadPathInfo(&pos2, coord2, styles2);
        if (path1 == Shape_EndShape || path2 == Shape_EndShape)
        {
            pMorphData->ShapeData1.EndShape();
            pMorphData->ShapeData2.EndShape();
            break;
        }
        if (path1 == Shape_NewLayer || firstPath)
        {
            pMorphData->ShapeData1.StartLayer();
            pMorphData->ShapeData2.StartLayer();
            firstPath = false;
        }
        // both ends take the styles of the first one
        pMorphData->ShapeData1.StartPath(styles1[0], styles1[1], styles1[2]);
        pMorphData->ShapeData2.StartPath(styles1[0], styles1[1], styles1[2]);
        pMorphData->ShapeData1.MoveTo(coord1[0], coord1[1]);
        pMorphData->ShapeData2.MoveTo(coord2[0], coord2[1]);
        last1[0] = coord1[0];
        last1[1] = coord1[1];
        last2[0] = coord2[0];
        last2[1] = coord2[1];

        for (;;)
        {
            ShapePosInfo before1 = pos1;
            ShapePosInfo before2 = pos2;
            edge1 = from->ReadEdge(&pos1, coord1);
            edge2 = to->ReadEdge(&pos2, coord2);

            if (edge1 == Edge_EndPath && edge2 == Edge_EndPath)
            {
                pMorphData->ShapeData1.EndPath();
                pMorphData->ShapeData2.EndPath();
                break;
            }
            else if (edge1 == Edge_EndPath)
            {
                // the first end starts a new path here; the second one's edge is read again
                pos2 = before2;
                pMorphData->ShapeData1.EndPath();
                pMorphData->ShapeData2.EndPath();
                path1 = from->ReadPathInfo(&pos1, coord1, styles1);
                if (path1 == Shape_EndShape)
                {
                    pMorphData->ShapeData1.EndShape();
                    pMorphData->ShapeData2.EndShape();
                    finished = true;
                    break;
                }
                pMorphData->ShapeData1.StartPath(styles1[0], styles1[1], styles1[2]);
                pMorphData->ShapeData2.StartPath(styles1[0], styles1[1], styles1[2]);
                pMorphData->ShapeData1.MoveTo(coord1[0], coord1[1]);
                pMorphData->ShapeData2.MoveTo(last2[0], last2[1]);
                last1[0] = coord1[0];
                last1[1] = coord1[1];
            }
            else if (edge2 == Edge_EndPath)
            {
                pos1 = before1;
                pMorphData->ShapeData1.EndPath();
                pMorphData->ShapeData2.EndPath();
                path2 = to->ReadPathInfo(&pos2, coord2, styles2);
                if (path2 == Shape_EndShape)
                {
                    pMorphData->ShapeData1.EndShape();
                    pMorphData->ShapeData2.EndShape();
                    finished = true;
                    break;
                }
                pMorphData->ShapeData1.StartPath(styles1[0], styles1[1], styles1[2]);
                pMorphData->ShapeData2.StartPath(styles1[0], styles1[1], styles1[2]);
                pMorphData->ShapeData1.MoveTo(last1[0], last1[1]);
                pMorphData->ShapeData2.MoveTo(coord2[0], coord2[1]);
                last2[0] = coord2[0];
                last2[1] = coord2[1];
            }
            else
            {
                if (edge1 != edge2)
                {
                    if (edge1 == Edge_LineTo && edge2 == Edge_QuadTo)
                    {
                        coord1[2] = coord1[0];
                        coord1[3] = coord1[1];
                        coord1[0] = (last1[0] + coord1[2]) / 2;
                        coord1[1] = (last1[1] + coord1[3]) / 2;
                        edge1     = Edge_QuadTo;
                    }
                    if (edge1 == Edge_QuadTo && edge2 == Edge_LineTo)
                    {
                        coord2[2] = coord2[0];
                        coord2[3] = coord2[1];
                        coord2[0] = (last2[0] + coord2[2]) / 2;
                        coord2[1] = (last2[1] + coord2[3]) / 2;
                        edge2     = Edge_QuadTo;
                    }
                }
                if (edge1 == Edge_LineTo)
                {
                    pMorphData->ShapeData1.LineTo(coord1[0], coord1[1]);
                    pMorphData->ShapeData2.LineTo(coord2[0], coord2[1]);
                    last1[0] = coord1[0];
                    last1[1] = coord1[1];
                    last2[0] = coord2[0];
                    last2[1] = coord2[1];
                }
                else if (edge1 == Edge_QuadTo)
                {
                    pMorphData->ShapeData1.QuadTo(coord1[0], coord1[1], coord1[2], coord1[3]);
                    pMorphData->ShapeData2.QuadTo(coord2[0], coord2[1], coord2[2], coord2[3]);
                    last1[0] = coord1[2];
                    last1[1] = coord1[3];
                    last2[0] = coord2[2];
                    last2[1] = coord2[3];
                }
                else if (edge1 == Edge_CubicTo)
                {
                    pMorphData->ShapeData1.CubicTo(coord1[0], coord1[1], coord1[2], coord1[3], coord1[4], coord1[5]);
                    pMorphData->ShapeData2.CubicTo(coord2[0], coord2[1], coord2[2], coord2[3], coord2[4], coord2[5]);
                    last1[0] = coord1[4];
                    last1[1] = coord1[5];
                    last2[0] = coord2[4];
                    last2[1] = coord2[5];
                }
            }
        }
    }
}

// A bit per style index, the first 32 in the object; setting or clearing past the end grows it (at least doubling)
// in the heap it was given.
class BitSet
{
public:
    BitSet(MemoryHeap* heap) : NumBits(sizeof(Static) * 8), Static(0), Data(&Static), pHeap(heap) {}
    ~BitSet()
    {
        if (Data != &Static)
            pHeap->Free(Data);
    }

    unsigned operator[](unsigned i) const { return (i < NumBits) ? (Data[i >> 5] & (1 << (i & 31))) : 0; }

    void Set(unsigned i)
    {
        grow(i);
        Data[i >> 5] |= 1 << (i & 31);
    }
    void Clr(unsigned i)
    {
        grow(i);
        Data[i >> 5] &= ~(1 << (i & 31));
    }

private:
    void grow(unsigned i)
    {
        if (i >= NumBits)
        {
            unsigned words    = (NumBits + 31) >> 5;
            unsigned newWords = Alg::Max(words * 2, (i + 1 + 31) >> 5);
            if (newWords > words)
            {
                if (Data == &Static)
                {
                    Data    = (UInt32*)pHeap->Alloc(newWords * sizeof(UInt32));
                    Data[0] = Static;
                }
                else
                    Data = (UInt32*)pHeap->Realloc(Data, newWords * sizeof(UInt32));
                memset(Data + words, 0, (newWords - words) * sizeof(UInt32));
                NumBits = newWords << 5;
            }
        }
    }

    unsigned    NumBits;
    UInt32      Static;   // the first 32 bits
    UInt32*     Data;
    MemoryHeap* pHeap;
};

// ***** Stroke bounds through a stroke generator (joins, caps and miters as they will be drawn)

// Collects the paths of one shape layer drawn with strokeStyle in the generator's stroke sorter (in the transformed
// space) and sorts them into chains; pos ends at the start of the next layer. Returns the path type it stopped at.
template<class Transformer>
ShapePathType AddStrokeToSorter(const ShapeDataInterface& shape, ShapePosInfo* pos, unsigned strokeStyle,
                                const Transformer& trans, StrokeGenerator* gen)
{
    ShapePathType pathType;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;

    gen->mStrokeSorter.Clear();
    for (;;)
    {
        ShapePosInfo last = *pos;
        pathType          = shape.ReadPathInfo(pos, coord, styles);
        if (pathType == Shape_EndShape || (pathType == Shape_NewLayer && !first))
        {
            *pos = last;
            break;
        }
        if (styles[2] == strokeStyle)
        {
            trans.Transform(&coord[0], &coord[1]);
            gen->mStrokeSorter.AddVertexNV(coord[0], coord[1]);
            PathEdgeType edge;
            while ((edge = shape.ReadEdge(pos, coord)) != Edge_EndPath)
            {
                if (edge == Edge_LineTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    gen->mStrokeSorter.AddVertexNV(coord[0], coord[1]);
                }
                else if (edge == Edge_QuadTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    trans.Transform(&coord[2], &coord[3]);
                    gen->mStrokeSorter.AddQuad(coord[0], coord[1], coord[2], coord[3]);
                }
                else if (edge == Edge_CubicTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    trans.Transform(&coord[2], &coord[3]);
                    trans.Transform(&coord[4], &coord[5]);
                    gen->mStrokeSorter.AddCubic(coord[0], coord[1], coord[2], coord[3], coord[4], coord[5]);
                }
            }
            gen->mStrokeSorter.FinalizePath(0, 0, false, false);
        }
        else
            shape.SkipPathData(pos);
        first = false;
    }
    gen->mStrokeSorter.Sort();
    return pathType;
}

// A round joined and capped stroke covers its sorted paths (curves included up to their extremes) grown by half
// the width, so it needs no outline.
template<class Transformer>
RectF ComputeBoundsRoundStrokeSorter(const ShapeDataInterface& shape, ShapePosInfo* pos, unsigned strokeStyle,
                                     const Transformer& trans, float width, StrokeGenerator* gen)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    AddStrokeToSorter(shape, pos, strokeStyle, trans, gen);

    const StrokeSorter& sorter = gen->mStrokeSorter;
    for (unsigned i = 0; i < sorter.GetPathCount(); ++i)
    {
        unsigned n  = sorter.GetVertexCount(i);
        float    x0 = 0;
        float    y0 = 0;
        for (unsigned j = 0; j < n;)
        {
            const StrokeSorter::VertexType& p1 = sorter.GetVertex(i, j++);
            if (p1.segType == Math2D::Seg_MoveTo || p1.segType == Math2D::Seg_LineTo)
            {
                x0 = p1.x;
                y0 = p1.y;
                bounds.ExpandToPoint(x0, y0);
            }
            else if (p1.segType == Math2D::Seg_QuadTo)
            {
                const StrokeSorter::VertexType& p2 = sorter.GetVertex(i, j++);
                float x, y;
                float t = Math2D::QuadCurveExtremum(x0, p1.x, p2.x);
                if (t > 0 && t < 1)
                {
                    Math2D::PointOnQuadCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, t, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                t = Math2D::QuadCurveExtremum(y0, p1.y, p2.y);
                if (t > 0 && t < 1)
                {
                    Math2D::PointOnQuadCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, t, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                bounds.ExpandToPoint(p2.x, p2.y);
                x0 = p2.x;
                y0 = p2.y;
            }
            else if (p1.segType == Math2D::Seg_CubicTo)
            {
                const StrokeSorter::VertexType& p2 = sorter.GetVertex(i, j++);
                const StrokeSorter::VertexType& p3 = sorter.GetVertex(i, j++);
                float x, y, t1, t2;
                Math2D::CubicCurveExtremum(x0, p1.x, p2.x, p3.x, &t1, &t2);
                if (t1 > 0 && t1 < 1)
                {
                    Math2D::PointOnCubicCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, t1, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                if (t2 > 0 && t2 < 1)
                {
                    Math2D::PointOnCubicCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, t2, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                Math2D::CubicCurveExtremum(y0, p1.y, p2.y, p3.y, &t1, &t2);
                if (t1 > 0 && t1 < 1)
                {
                    Math2D::PointOnCubicCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, t1, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                if (t2 > 0 && t2 < 1)
                {
                    Math2D::PointOnCubicCurve(x0, y0, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, t2, &x, &y);
                    bounds.ExpandToPoint(x, y);
                }
                bounds.ExpandToPoint(p3.x, p3.y);
                x0 = p3.x;
                y0 = p3.y;
            }
        }
    }
    if (bounds.IsNormal())
    {
        width /= 2;
        bounds.x1 -= width;
        bounds.y1 -= width;
        bounds.x2 += width;
        bounds.y2 += width;
    }
    return bounds;
}

// the stroke width in the transformed space
template<class Transformer>
SF_INLINE float scaledStrokeWidth(const StrokeStyleType& style, const Transformer& trans)
{
    float scale = 1.0f;
    switch (style.Flags & StrokeScaling_Mask)
    {
    case StrokeScaling_Normal:     scale = trans.GetScale(); break;
    case StrokeScaling_Horizontal: scale = trans.GetXScale(); break;
    case StrokeScaling_Vertical:   scale = trans.GetYScale(); break;
    case StrokeScaling_None:       break;
    }
    return style.Width * scale;
}

// sets the generator's stroker up for the style's joins and caps at width
SF_INLINE void setupStroker(Stroker* stroker, const StrokeStyleType& style, float width, const ToleranceParams& param)
{
    StrokerTypes::LineJoinType join     = StrokerTypes::RoundJoin;
    StrokerTypes::LineCapType  startCap = StrokerTypes::RoundCap;
    StrokerTypes::LineCapType  endCap   = StrokerTypes::RoundCap;
    switch (style.Flags & StrokeJoin_Mask)
    {
    case StrokeJoin_Round: break;
    case StrokeJoin_Bevel: join = StrokerTypes::BevelJoin; break;
    case StrokeJoin_Miter: join = StrokerTypes::MiterJoin; break;
    }
    switch (style.Flags & StrokeCap_Mask)
    {
    case StrokeCap_Round:  break;
    case StrokeCap_None:   startCap = StrokerTypes::ButtCap; break;
    case StrokeCap_Square: startCap = StrokerTypes::SquareCap; break;
    }
    switch (style.Flags & StrokeEndCap_Mask)
    {
    case StrokeEndCap_Round:  break;
    case StrokeEndCap_None:   endCap = StrokerTypes::ButtCap; break;
    case StrokeEndCap_Square: endCap = StrokerTypes::SquareCap; break;
    }
    stroker->SetWidth(width);
    stroker->SetLineJoin(join);
    stroker->SetStartLineCap(startCap);
    stroker->SetEndLineCap(endCap);
    stroker->SetMiterLimit(style.Miter);
    stroker->SetToleranceParam(param);
}

// feeds sorted path i into sink, flattening its curves
SF_INLINE void addSortedPath(TessBase* sink, const StrokeSorter& sorter, unsigned i, unsigned n,
                             const ToleranceParams& param)
{
    for (unsigned j = 0; j < n;)
    {
        const StrokeSorter::VertexType& p1 = sorter.GetVertex(i, j++);
        if (p1.segType == Math2D::Seg_MoveTo || p1.segType == Math2D::Seg_LineTo)
            sink->AddVertex(p1.x, p1.y);
        else if (p1.segType == Math2D::Seg_QuadTo)
        {
            const StrokeSorter::VertexType& p2 = sorter.GetVertex(i, j++);
            TessellateQuadCurve(sink, param, p1.x, p1.y, p2.x, p2.y);
        }
        else if (p1.segType == Math2D::Seg_CubicTo)
        {
            const StrokeSorter::VertexType& p2 = sorter.GetVertex(i, j++);
            const StrokeSorter::VertexType& p3 = sorter.GetVertex(i, j++);
            TessellateCubicCurve(sink, param, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
        }
    }
}
SF_INLINE void addSortedPath(TessBase* sink, const StrokeSorter& sorter, unsigned i, const ToleranceParams& param)
{
    addSortedPath(sink, sorter, i, sorter.GetVertexCount(i), param);
}

// The bounds of one stroke style over one shape layer: round strokes from their paths, the others from the
// generated outlines.
template<class Transformer>
RectF ComputeBoundsSingleStroke(const ShapeDataInterface& shape, ShapePosInfo* pos, unsigned strokeStyle,
                                const Transformer& trans, StrokeGenerator* gen, const ToleranceParams& param)
{
    StrokeStyleType style;
    shape.GetStrokeStyle(strokeStyle, &style);
    float width = scaledStrokeWidth(style, trans);
    if ((style.Flags & StrokeJoin_Mask) == StrokeJoin_Round && (style.Flags & StrokeCap_Mask) == StrokeCap_Round)
        return ComputeBoundsRoundStrokeSorter(shape, pos, strokeStyle, trans, width, gen);

    setupStroker(&gen->mStroker, style, width, param);
    AddStrokeToSorter(shape, pos, strokeStyle, trans, gen);

    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    gen->mStroker.Clear();
    for (unsigned i = 0; i < gen->mStrokeSorter.GetPathCount(); ++i)
    {
        gen->mPath.Clear();
        addSortedPath(&gen->mStroker, gen->mStrokeSorter, i, param);
        gen->mStroker.GenerateStroke(&gen->mPath);
        for (unsigned j = 0; j < gen->mPath.GetNumVertices(); ++j)
        {
            const VertexPath::VertexType& v = gen->mPath.GetVertex(j);
            bounds.ExpandToPoint(v.x, v.y);
        }
    }
    return bounds;
}

// The strokes of one shape layer, each stroke style once (it is generated over all its paths of the layer);
// pos ends at the start of the next layer.
template<class Transformer>
void ExpandBoundsToLayerStrokes(const ShapeDataInterface& shape, ShapePosInfo* pos, const Transformer& trans,
                                StrokeGenerator* gen, const ToleranceParams& param, RectF* bounds)
{
    BitSet        done(gen->Heap1.GetMemoryHeap());
    ShapePosInfo  start = *pos;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    ShapePathType pathType;
    while ((pathType = shape.ReadPathInfo(pos, coord, styles)) != Shape_EndShape)
    {
        if (pathType == Shape_NewLayer && !first)
            break;
        if (styles[2] && !done[styles[2]])
        {
            RectF b = ComputeBoundsSingleStroke(shape, &start, styles[2], trans, gen, param);
            if (b.IsNormal())
            {
                bounds->ExpandToPoint(b.x1, b.y1);
                bounds->ExpandToPoint(b.x2, b.y2);
            }
            done.Set(styles[2]);
        }
        shape.SkipPathData(pos);
        start = *pos;
        first = false;
    }
    *pos = start;
}

template<class Transformer>
void ExpandBoundsToStrokes(const ShapeDataInterface& shape, const Transformer& trans, StrokeGenerator* gen,
                           const ToleranceParams& param, RectF* bounds)
{
    ShapePosInfo pos(shape.GetStartingPos());
    float        coord[Edge_MaxCoord];
    unsigned     styles[3];
    for (;;)
    {
        ShapePosInfo layerPos = pos;
        if (shape.ReadPathInfo(&pos, coord, styles) == Shape_EndShape)
            break;
        pos = layerPos;
        ExpandBoundsToLayerStrokes(shape, &pos, trans, gen, param, bounds);
    }
}

template<class Transformer>
RectF ComputeBoundsFillAndStrokes(const ShapeDataInterface& shape, const Transformer& trans, StrokeGenerator* gen,
                                  const ToleranceParams& param, BoundEdges edges = Bound_OuterEdges)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    ExpandBoundsToFill(shape, trans, &bounds, edges);
    if (shape.GetStrokeStyleCount())
    {
        shape.Rewind();
        ExpandBoundsToStrokes(shape, trans, gen, param, &bounds);
    }
    return bounds;
}

// ***** Hit tests

// in other parts of the renderer (HitTestFill 0x1425fd750)
template<class Transformer>
bool HitTestFill(const ShapeDataInterface& shape, const Transformer& trans, float x, float y);

// A round joined and capped stroke is hit within half its width of its flattened paths.
template<class Transformer>
bool HitTestRoundJoinStroke(const ShapeDataInterface& shape, ShapePosInfo* pos, unsigned strokeStyle,
                            const Transformer& trans, float width, float x, float y, StrokeGenerator* gen,
                            const ToleranceParams& param)
{
    AddStrokeToSorter(shape, pos, strokeStyle, trans, gen);
    for (unsigned i = 0; i < gen->mStrokeSorter.GetPathCount(); ++i)
    {
        unsigned n = gen->mStrokeSorter.GetVertexCount(i);
        gen->mPath.Clear();
        addSortedPath(&gen->mPath, gen->mStrokeSorter, i, n, param);
        if (HitTestRoundStroke(gen->mPath, width, x, y))
            return true;
    }
    return false;
}

// Tests one stroke style over one shape layer: round strokes against their paths, the others against the
// generated outlines.
template<class Transformer>
bool HitTestSingleStroke(const ShapeDataInterface& shape, ShapePosInfo* pos, unsigned strokeStyle,
                         const Transformer& trans, float x, float y, StrokeGenerator* gen,
                         const ToleranceParams& param)
{
    StrokeStyleType style;
    shape.GetStrokeStyle(strokeStyle, &style);
    float width = scaledStrokeWidth(style, trans);
    if ((style.Flags & StrokeJoin_Mask) == StrokeJoin_Round && (style.Flags & StrokeCap_Mask) == StrokeCap_Round)
        return HitTestRoundJoinStroke(shape, pos, strokeStyle, trans, width, x, y, gen, param);

    setupStroker(&gen->mStroker, style, width, param);
    AddStrokeToSorter(shape, pos, strokeStyle, trans, gen);

    gen->mStroker.Clear();
    for (unsigned i = 0; i < gen->mStrokeSorter.GetPathCount(); ++i)
    {
        gen->mPath.Clear();
        addSortedPath(&gen->mStroker, gen->mStrokeSorter, i, param);
        gen->mStroker.GenerateStroke(&gen->mPath);
        if (HitTestGeneralStroke(gen->mPath, x, y))
            return true;
    }
    return false;
}

// Tests the strokes of one shape layer, each stroke style once; on a miss pos ends at the start of the next layer.
template<class Transformer>
bool HitTestLayerStrokes(const ShapeDataInterface& shape, ShapePosInfo* pos, const Transformer& trans, float x,
                         float y, StrokeGenerator* gen, const ToleranceParams& param)
{
    BitSet        done(gen->Heap1.GetMemoryHeap());
    ShapePosInfo  start = *pos;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    ShapePathType pathType;
    while ((pathType = shape.ReadPathInfo(pos, coord, styles)) != Shape_EndShape)
    {
        if (pathType == Shape_NewLayer && !first)
            break;
        if (styles[2] && !done[styles[2]])
        {
            if (HitTestSingleStroke(shape, &start, styles[2], trans, x, y, gen, param))
                return true;
            done.Set(styles[2]);
        }
        shape.SkipPathData(pos);
        start = *pos;
        first = false;
    }
    *pos = start;
    return false;
}

template<class Transformer>
bool HitTestShapeStrokes(const ShapeDataInterface& shape, const Transformer& trans, float x, float y,
                         StrokeGenerator* gen, const ToleranceParams& param)
{
    ShapePosInfo pos(shape.GetStartingPos());
    float        coord[Edge_MaxCoord];
    unsigned     styles[3];
    for (;;)
    {
        ShapePosInfo layerPos = pos;
        if (shape.ReadPathInfo(&pos, coord, styles) == Shape_EndShape)
            break;
        pos = layerPos;
        if (HitTestLayerStrokes(shape, &pos, trans, x, y, gen, param))
            return true;
    }
    return false;
}

template<class Transformer>
bool HitTestFillAndStrokes(const ShapeDataInterface& shape, const Transformer& trans, float x, float y,
                           StrokeGenerator* gen, const ToleranceParams& param)
{
    if (HitTestFill(shape, trans, x, y))
        return true;
    if (shape.GetStrokeStyleCount())
    {
        shape.Rewind();
        return HitTestShapeStrokes(shape, trans, x, y, gen, param);
    }
    return false;
}

// Collects the shape's paths, drops the empty ones and builds the draw layers of each shape layer from them; a
// morph shape uses its re-encoded first end.
// @0x14262d430
// MS2-FUNCTIONAL: same code, the exe frame is 0x10 larger (path / bounds slot after the reader, 16-aligned)
void ShapeMeshProvider::acquireShapeData()
{
    const ShapeDataInterface* shape = pMorphData ? &pMorphData->ShapeData1 : pShapeData;

    unsigned      startPos = shape->GetStartingPos();
    ShapePosInfo  pos(startPos);
    ShapePathType type;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first      = true;
    unsigned      shapeLayer = 0;

    TmpPathsArray paths(Memory::GetGlobalHeap());
    Strokes = false;

    for (;;)
    {
        unsigned pathPos = pos.Pos;
        type             = shape->ReadPathInfo(&pos, coord, styles);
        if (type == Shape_EndShape)
            break;
        if (type == Shape_NewLayer && !first)
            ++shapeLayer;

        TmpPathInfoType path;
        path.ShapeLayer = shapeLayer;
        path.Pos        = pathPos;
        path.Styles[0]  = styles[0];
        path.Styles[1]  = styles[1];
        path.Styles[2]  = styles[2];
        path.EdgeCount  = shape->CountPathEdges(&pos);
        paths.PushBack(path);
        first = false;
    }

    // keep the paths that have edges and some style
    UPInt i;
    UPInt kept = 0;
    for (i = 0; i < paths.GetSize(); ++i)
    {
        const TmpPathInfoType& path = paths[i];
        if (path.EdgeCount && (path.Styles[0] || path.Styles[1] || path.Styles[2]))
            paths[kept++] = paths[i];
    }
    paths.CutAt(kept);

    DrawLayers.Clear();
    FillToStyleTable.Clear();

    shapeLayer         = 0;
    UPInt layerStart   = 0;
    for (i = 0; i < paths.GetSize(); ++i)
    {
        if (paths[i].ShapeLayer != shapeLayer)
        {
            createDrawLayers(paths, layerStart, i);
            layerStart = i;
            shapeLayer = paths[i].ShapeLayer;
        }
    }
    createDrawLayers(paths, layerStart, paths.GetSize());

    IdentityBounds = GetBounds(Matrix2F());

    if (checkI9gMergedSlice())
    {
        DrawLayers.Resize(1);
        DrawLayers[0].Image9GridType = I9gMergedSlice;
    }
    else
        perceiveImage9GridLayers();
}

// The fill table entries of a fill layer over paths [i1, i2): each distinct fill style once, in path order, with the
// solid colour fills sharing entry 0.
// @0x14262fac0
void ShapeMeshProvider::countComplexFills(const TmpPathsArray& paths, UPInt i1, UPInt i2, DrawLayerType* layer)
{
    BitSet seen(Memory::GetGlobalHeap());
    layer->StartFill = (unsigned)FillToStyleTable.GetSize();
    layer->FillCount = 0;
    for (UPInt i = i1; i < i2; ++i)
    {
        if (paths[i].Styles[0] != paths[i].Styles[1])
        {
            FillStyleType fill;
            unsigned      style = paths[i].Styles[0];
            if (style)
            {
                pShapeData->GetFillStyle(style, &fill);
                unsigned entry = fill.pFill ? style : 0;
                if (seen[entry] == 0)
                {
                    FillToStyleTable.PushBack(entry);
                    layer->FillCount++;
                    seen.Set(entry);
                }
            }
            style = paths[i].Styles[1];
            if (style)
            {
                pShapeData->GetFillStyle(style, &fill);
                unsigned entry = fill.pFill ? style : 0;
                if (seen[entry] == 0)
                {
                    FillToStyleTable.PushBack(entry);
                    layer->FillCount++;
                    seen.Set(entry);
                }
            }
        }
    }
}

// The draw layers of one shape layer (paths [i1, i2)): one fill layer if any path fills, then one layer per distinct
// stroke style in order of first use.
// @0x14262fe10
void ShapeMeshProvider::createDrawLayers(const TmpPathsArray& paths, UPInt i1, UPInt i2)
{
    if (i2 > i1)
    {
        DrawLayerType layer;
        BitSet        styles(Memory::GetGlobalHeap());   // bit 0: the fill layer is in
        unsigned      startPos = paths[i1].Pos;
        UPInt         i;

        for (i = i1; i < i2; ++i)
        {
            if (paths[i].Styles[0] != paths[i].Styles[1] && styles[0] == 0)
            {
                countComplexFills(paths, i1, i2, &layer);
                layer.StartPos       = startPos;
                layer.StrokeStyle    = 0;
                layer.Image9GridType = I9gNone;
                DrawLayers.PushBack(layer);
                styles.Set(0);
            }
            if (paths[i].Styles[2])
                styles.Set(paths[i].Styles[2]);
        }

        for (i = i1; i < i2; ++i)
        {
            unsigned style = paths[i].Styles[2];
            if (style && styles[style])
            {
                // a stroke layer has its one fill computed from the stroke style
                layer.StartPos       = startPos;
                layer.StartFill      = 0;
                layer.FillCount      = 1;
                layer.StrokeStyle    = style;
                layer.Image9GridType = I9gNone;
                DrawLayers.PushBack(layer);
                styles.Clr(style);
                Strokes = true;
            }
        }
    }
}

// Bounds of fills and strokes under m (strokes as round joined); a morph covers both of its ends.
// @0x14262aac0
// MS2-FUNCTIONAL: the exe inlines the two morph-end bound computations (fill loop included); ours calls them
RectF ShapeMeshProvider::GetBounds(const Matrix2F& m) const
{
    if (pMorphData)
    {
        RectF b1 = ComputeBoundsFillAndStrokesSimplified(pMorphData->ShapeData1, m);
        RectF b2 = ComputeBoundsFillAndStrokesSimplified(pMorphData->ShapeData2, m);
        RectF bounds(RectF::NoInit);
        b1.UnionRect(&bounds, b2);
        return bounds;
    }
    return ComputeBoundsFillAndStrokesSimplified(*pShapeData, m);
}

// The point (x, y) against the shape at the given morph ratio; strokes are only tested with a stroke generator.
// @0x14262c040
bool ShapeMeshProvider::HitTestShape(const Matrix2F& m, float x, float y, float morphRatio, StrokeGenerator* gen,
                                     const ToleranceParams* tol) const
{
    MorphInterpolator shape(pShapeData, pMorphData, morphRatio, ShapePosInfo(pShapeData->GetStartingPos()));
    if (gen)
        return HitTestFillAndStrokes(shape, m, x, y, gen, *tol);
    return HitTestFill(shape, m, x, y);
}

// Bounds at the given morph ratio; with a stroke generator the strokes are measured as generated.
// @0x14262ad40
RectF ShapeMeshProvider::GetCorrectBounds(const Matrix2F& m, float morphRatio, StrokeGenerator* gen,
                                          const ToleranceParams* tol) const
{
    MorphInterpolator shape(pShapeData, pMorphData, morphRatio, ShapePosInfo(pShapeData->GetStartingPos()));
    if (gen)
        return ComputeBoundsFillAndStrokes(shape, m, gen, *tol);
    return ComputeBoundsFillAndStrokesSimplified(shape, m);
}

// @0x14262bb90
void ShapeMeshProvider::GetFillStyle(unsigned idx, FillStyleType* style, float morphRatio) const
{
    pShapeData->GetFillStyle(idx, style);
    if (!pMorphData || morphRatio == 0)
        return;

    FillStyleType target;
    pMorphData->pMorphTo->GetFillStyle(idx, &target);
    if (!style->pFill)
        style->Color = Color::Blend(Color(style->Color), Color(target.Color), morphRatio).Raw;
}

// @0x14262bf30
void ShapeMeshProvider::GetStrokeStyle(unsigned idx, StrokeStyleType* style, float morphRatio) const
{
    pShapeData->GetStrokeStyle(idx, style);
    if (!pMorphData || morphRatio == 0)
        return;

    StrokeStyleType target;
    pMorphData->pMorphTo->GetStrokeStyle(idx, &target);
    style->Width = Alg::Lerp(style->Width, target.Width, morphRatio);
    if (!style->pFill)
        style->Color = Color::Blend(Color(style->Color), Color(target.Color), morphRatio).Raw;
}

// The scale9 slicing of nine image rectangles (as a slicing tool lays them out): no morph, nine layers over nine
// image fill styles of one image and no strokes.
// @0x14262f650
bool ShapeMeshProvider::checkI9gMergedSlice() const
{
    if (pMorphData)
        return false;

    unsigned imageFills = 0;
    if (DrawLayers.GetSize() == 9 && GetFillStyleCount() == 9 && GetStrokeStyleCount() == 0)
    {
        const ImageBase* image = 0;
        for (unsigned i = 0; i < 9; ++i)
        {
            FillStyleType fill;
            pShapeData->GetFillStyle(i + 1, &fill);
            if (!fill.pFill)
                return false;
            if (fill.pFill->pImage && (!image || image == fill.pFill->pImage))
                ++imageFills;
            image = fill.pFill->pImage;
        }
    }
    if (imageFills != 9)
        return false;
    return true;
}

// A layer qualifies for image scale9 when it is one path filled on one side only with a clamped, axis aligned
// image and nothing else follows in the layer.
// @0x14262f4b0
bool ShapeMeshProvider::checkI9gLayer(const DrawLayerType& layer) const
{
    if (pMorphData)
        return false;

    ShapePosInfo  pos(layer.StartPos);
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    ShapePathType type = pShapeData->ReadPathInfo(&pos, coord, styles);
    if ((type == Shape_NewPath || type == Shape_NewLayer) && (styles[0] == 0) != (styles[1] == 0) &&
        styles[2] == 0)
    {
        FillStyleType fill;
        pShapeData->GetFillStyle(styles[0] ? styles[0] : styles[1], &fill);
        if (fill.pFill && fill.pFill->pImage && !fill.pFill->ImageMatrix.IsFreeRotation() &&
            fill.pFill->FillMode.GetWrapMode() == Wrap_Clamp)
        {
            pShapeData->SkipPathData(&pos);
            type = pShapeData->ReadPathInfo(&pos, coord, styles);
            if (type == Shape_EndShape || type == Shape_NewLayer)
                return true;
        }
    }
    return false;
}

// @0x142632800
void ShapeMeshProvider::perceiveImage9GridLayers()
{
    for (UPInt i = 0; i < DrawLayers.GetSize(); ++i)
    {
        DrawLayerType& layer = DrawLayers[i];
        if (layer.StrokeStyle == 0 && checkI9gLayer(layer))
            layer.Image9GridType = I9gNormalSlice;
    }
}

// whether fill style `style` (0: none) is an image or gradient
// @0x142631fe0
bool fillStyleIsComplex(const ShapeDataInterface* shape, unsigned style)
{
    if (style)
    {
        FillStyleType fill;
        shape->GetFillStyle(style, &fill);
        return fill.pFill != 0;
    }
    return false;
}

// The image / gradient of fill fillIndex of a layer (of its stroke for a stroke layer); imgFillStyle receives the
// fill style it came from.
// @0x1426324b0
__declspec(noinline) ComplexFill* ShapeMeshProvider::getComplexFill(unsigned layer, unsigned fillIndex, unsigned* imgFillStyle) const
{
    unsigned     strokeStyle = GetLayerStroke(layer);
    ComplexFill* fill        = 0;
    if (strokeStyle == 0)
    {
        unsigned fillStyle = GetStyleByFillIdx(layer, fillIndex);
        if (fillStyle)
        {
            FillStyleType style;
            pShapeData->GetFillStyle(fillStyle, &style);
            fill = style.pFill;
            if (imgFillStyle)
                *imgFillStyle = fillStyle;
        }
    }
    else
    {
        StrokeStyleType stroke;
        pShapeData->GetStrokeStyle(strokeStyle, &stroke);
        fill = stroke.pFill;
    }
    return fill;
}

// @0x1426325a0
RectF ShapeMeshProvider::getLayerBounds(unsigned layer) const
{
    ShapePosInfo pos(DrawLayers[layer].StartPos);
    unsigned     styles[3];
    float        coord[Edge_MaxCoord];
    RectF        bounds(1e30f, 1e30f, -1e30f, -1e30f);
    Matrix2F     m;
    bool         first = true;
    ShapePathType pathType;
    while ((pathType = pShapeData->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;
        // paths with only a stroke add nothing to the fill area
        if (styles[0] == 0 && styles[1] == 0)
            pShapeData->SkipPathData(&pos);
        else
            ExpandBoundsToPath(*pShapeData, m, &pos, coord, &bounds);
    }
    return bounds;
}

// @0x1426326d0
// MS2-FUNCTIONAL: ours loads the morph-to shape once ahead of the branch; the exe loads it in each branch
Matrix2F ShapeMeshProvider::getMorphMatrix(unsigned layer, unsigned fillIndex) const
{
    unsigned strokeStyle = GetLayerStroke(layer);
    if (strokeStyle == 0)
    {
        FillStyleType style;
        pMorphData->pMorphTo->GetFillStyle(GetStyleByFillIdx(layer, fillIndex), &style);
        return style.pFill->ImageMatrix;
    }
    StrokeStyleType stroke;
    pMorphData->pMorphTo->GetStrokeStyle(strokeStyle, &stroke);
    if (stroke.pFill)
        return stroke.pFill->ImageMatrix;
    return Matrix2F();
}

// @0x14262b3e0
void ShapeMeshProvider::GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags)
{
    if (meshGenFlags & Mesh_Mask)
    {
        *data = FillData(Fill_Mask);
        data->pVFormat = &VertexXY16iCF32::Format;
        return;
    }

    ComplexFill* fill = getComplexFill(layer, fillIndex, 0);
    if (fill)
    {
        if (fill->pGradient)
            *data = FillData(fill->pGradient);
        else
        {
            *data = FillData(fill->pImage->GetAsImage(), fill->FillMode);
            if (DrawLayers[layer].Image9GridType != I9gNone && (meshGenFlags & Mesh_Scale9))
            {
                data->PrimFill = PrimFill_UVTexture;
                data->pVFormat = &Image9GridVertex::Format;
            }
        }
    }
    else
        *data = FillData(Fill_VColor);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7MorphInterpolator@Render@Scaleform@@6B@ 0x14318f320
// MS2-PIN: ??_7MorphShapeData@Render@Scaleform@@6B@ 0x14318f2a0
// MS2-PIN: ??_7?$ShapeDataFloatTempl@V?$ArrayLH_POD@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14318f248
// MS2-PIN: ??_7ShapeMeshProvider@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f2a8
// MS2-PIN: ??_7ShapeMeshProvider@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f2b0
// MS2-PIN: ??_7MeshProvider_KeySupport@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f1b0
// MS2-PIN: ??_7MeshProvider_KeySupport@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f1b8
// MS2-PIN: ??_7MeshProvider@Render@Scaleform@@6B@ 0x14318f0c0
// MS2-PIN: ??_7?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f010
// MS2-PIN: ??_7MeshProvider_RCImpl@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f138
// MS2-PIN: ??_7MeshProvider_RCImpl@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f140
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7?$RefCountBase@UMorphShapeData@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f038
// MS2-PIN: ??_G?$RefCountBase@UMorphShapeData@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142620040
// MS2-PIN: ??_G?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1426200a0
// MS2-PIN: ??_GShapeDataInterface@Render@Scaleform@@UEAAPEAXI@Z 0x142620100
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14262a100
// MS2-PIN: ??_G?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14262a160
// MS2-PIN: ??_GShapeMeshProvider@Render@Scaleform@@UEAAPEAXI@Z 0x14262a520
// MS2-PIN: ?ReadEdge@?$ShapeDataFloatTempl@V?$ArrayLH_POD@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@UEBA?AW4PathEdgeType@23@PEAUShapePosInfo@23@PEAM@Z 0x14262c3f0
// MS2-PIN: ?ReadPathInfo@?$ShapeDataFloatTempl@V?$ArrayLH_POD@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@UEBA?AW4ShapePathType@23@PEAUShapePosInfo@23@PEAMPEAI@Z 0x14262c730
// MS2-PIN: ??$ComputeBoundsFillAndStrokesSimplified@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AV?$Rect@M@01@AEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@W4BoundEdges@01@@Z 0x1426267b0
// MS2-PIN: ??$ExpandBoundsToStrokesSimplified@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YAXAEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@PEAV?$Rect@M@01@@Z 0x142628df0
// MS2-PIN: ??$ComputeBoundsRoundStroke@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AV?$Rect@M@01@AEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@PEAUShapePosInfo@01@PEAMPEAI@Z 0x142626830
// MS2-PIN: ??_GMorphInterpolator@Render@Scaleform@@UEAAPEAXI@Z 0x14262a3c0
// MS2-PIN: ?GetStrokeStyleCount@MorphInterpolator@Render@Scaleform@@UEBAIXZ 0x14262c020
// MS2-PIN: ??$ExpandBoundsToLayerStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YAXAEBVShapeDataInterface@01@PEAUShapePosInfo@01@AEBV?$Matrix2x4@M@01@PEAUStrokeGenerator@01@AEBUToleranceParams@01@PEAV?$Rect@M@01@@Z 0x142627c90
// MS2-PIN: ??$ExpandBoundsToStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YAXAEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@PEAUStrokeGenerator@01@AEBUToleranceParams@01@PEAV?$Rect@M@01@@Z 0x142628ca0
// MS2-PIN: ??$ComputeBoundsFillAndStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AV?$Rect@M@01@AEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@PEAUStrokeGenerator@01@AEBUToleranceParams@01@W4BoundEdges@01@@Z 0x1426265f0
// MS2-PIN: ??$HitTestLayerStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA_NAEBVShapeDataInterface@01@PEAUShapePosInfo@01@AEBV?$Matrix2x4@M@01@MMPEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x1426292d0
// MS2-PIN: ??$HitTestShapeStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA_NAEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@MMPEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x142629810
// MS2-PIN: ??$HitTestFillAndStrokes@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA_NAEBVShapeDataInterface@01@AEBV?$Matrix2x4@M@01@MMPEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x1426290f0
// MS2-FUNCTIONAL: same code, the exe saves xmm10-13 in the prologue; ours sinks the saves below the first ReadPathInfo
// MS2-PIN: ??$AddStrokeToSorter@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AW4ShapePathType@01@AEBVShapeDataInterface@01@PEAUShapePosInfo@01@IAEBV?$Matrix2x4@M@01@PEAUStrokeGenerator@01@@Z 0x142626190
// MS2-PIN: ??$ComputeBoundsRoundStrokeSorter@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AV?$Rect@M@01@AEBVShapeDataInterface@01@PEAUShapePosInfo@01@IAEBV?$Matrix2x4@M@01@MPEAUStrokeGenerator@01@@Z 0x1426269d0
// MS2-FUNCTIONAL: same code, register allocation differs (ours pushes r12)
// MS2-PIN: ??$ComputeBoundsSingleStroke@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA?AV?$Rect@M@01@AEBVShapeDataInterface@01@PEAUShapePosInfo@01@IAEBV?$Matrix2x4@M@01@PEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x142627650
// MS2-FUNCTIONAL: same code, ours keeps the ToleranceParams pointer in r13; the exe reloads it per path
// MS2-PIN: ??$HitTestRoundJoinStroke@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA_NAEBVShapeDataInterface@01@PEAUShapePosInfo@01@IAEBV?$Matrix2x4@M@01@MMMPEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x142629590
// MS2-PIN: ??$HitTestSingleStroke@V?$Matrix2x4@M@Render@Scaleform@@@Render@Scaleform@@YA_NAEBVShapeDataInterface@01@PEAUShapePosInfo@01@IAEBV?$Matrix2x4@M@01@MMPEAUStrokeGenerator@01@AEBUToleranceParams@01@@Z 0x1426299a0
