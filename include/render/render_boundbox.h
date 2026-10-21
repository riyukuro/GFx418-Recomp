// Recovered Scaleform 4.1.18 Render: bound boxes of shape data under a transform (Render_BoundBox), as far as the
// recovered units use them (the shape mesh provider, sfr_render_03d). The templates take any transformer with
// Transform(x*, y*) and GetScale / GetXScale / GetYScale; MS2 instantiates them for Matrix2F.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_BOUNDBOX_H
#define MS2_SF_RENDER_BOUNDBOX_H

#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_shapedata.h"
#include "ms2/scaleform/include/render/render_math2d.h"

namespace Scaleform { namespace Render {

// which paths count toward the fill bounds
enum BoundEdges
{
    Bound_OuterEdges,   // filled on exactly one side (the outline of a well formed shape)
    Bound_FillEdges,    // filled differently on the two sides
    Bound_AllEdges      // every path, strokes too
};

// Grows bounds by the path whose first point is in coord (the rest is read from pos), curve extrema included.
template<class Transformer>
void ExpandBoundsToPath(const ShapeDataInterface& shape, const Transformer& trans, ShapePosInfo* pos, float* coord,
                        RectF* bounds)
{
    trans.Transform(&coord[0], &coord[1]);
    bounds->ExpandToPoint(coord[0], coord[1]);
    float lastX = coord[0];
    float lastY = coord[1];

    PathEdgeType edge;
    while ((edge = shape.ReadEdge(pos, coord)) != Edge_EndPath)
    {
        if (edge == Edge_LineTo)
        {
            trans.Transform(&coord[0], &coord[1]);
            bounds->ExpandToPoint(coord[0], coord[1]);
            lastX = coord[0];
            lastY = coord[1];
        }
        else if (edge == Edge_QuadTo)
        {
            trans.Transform(&coord[0], &coord[1]);
            trans.Transform(&coord[2], &coord[3]);

            float x, y;
            float t = Math2D::QuadCurveExtremum(lastX, coord[0], coord[2]);
            if (t > 0 && t < 1)
            {
                Math2D::PointOnQuadCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], t, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            t = Math2D::QuadCurveExtremum(lastY, coord[1], coord[3]);
            if (t > 0 && t < 1)
            {
                Math2D::PointOnQuadCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], t, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            bounds->ExpandToPoint(coord[2], coord[3]);
            lastX = coord[2];
            lastY = coord[3];
        }
        else if (edge == Edge_CubicTo)
        {
            // (4.1.18 maps the pair (3, 4) for the last control point and leaves coord[5] as read)
            trans.Transform(&coord[0], &coord[1]);
            trans.Transform(&coord[2], &coord[3]);
            trans.Transform(&coord[3], &coord[4]);

            float x, y, t1, t2;
            Math2D::CubicCurveExtremum(lastX, coord[0], coord[2], coord[4], &t1, &t2);
            if (t1 > 0 && t1 < 1)
            {
                Math2D::PointOnCubicCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], coord[4], coord[5],
                                          t1, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            if (t2 > 0 && t2 < 1)
            {
                Math2D::PointOnCubicCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], coord[4], coord[5],
                                          t2, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            Math2D::CubicCurveExtremum(lastY, coord[1], coord[3], coord[5], &t1, &t2);
            if (t1 > 0 && t1 < 1)
            {
                Math2D::PointOnCubicCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], coord[4], coord[5],
                                          t1, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            if (t2 > 0 && t2 < 1)
            {
                Math2D::PointOnCubicCurve(lastX, lastY, coord[0], coord[1], coord[2], coord[3], coord[4], coord[5],
                                          t2, &x, &y);
                bounds->ExpandToPoint(x, y);
            }
            bounds->ExpandToPoint(coord[4], coord[5]);
            lastX = coord[4];
            lastY = coord[5];
        }
    }
}

// Grows bounds by the fill paths the edge mode selects.
template<class Transformer>
void ExpandBoundsToFill(const ShapeDataInterface& shape, const Transformer& trans, RectF* bounds,
                        BoundEdges edges = Bound_OuterEdges)
{
    ShapePosInfo pos(shape.GetStartingPos());
    float        coord[Edge_MaxCoord];
    unsigned     styles[3];

    while (shape.ReadPathInfo(&pos, coord, styles) != Shape_EndShape)
    {
        bool use = false;
        switch (edges)
        {
        case Bound_OuterEdges: use = (styles[0] == 0) != (styles[1] == 0); break;
        case Bound_FillEdges:  use = styles[0] != styles[1]; break;
        case Bound_AllEdges:   use = true; break;
        }
        if (use)
            ExpandBoundsToPath(shape, trans, &pos, coord, bounds);
        else
            shape.SkipPathData(&pos);
    }
}

// Bounds of one stroked path taken as round joined and capped: the path bounds grown by half the scaled width.
template<class Transformer>
RectF ComputeBoundsRoundStroke(const ShapeDataInterface& shape, const Transformer& trans, ShapePosInfo* pos,
                               float* coord, unsigned* styles)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);

    StrokeStyleType stroke;
    shape.GetStrokeStyle(styles[2], &stroke);

    float scale = 1.0f;
    switch (stroke.Flags & StrokeScaling_Mask)
    {
    case StrokeScaling_Normal:     scale = trans.GetScale(); break;
    case StrokeScaling_Horizontal: scale = trans.GetXScale(); break;
    case StrokeScaling_Vertical:   scale = trans.GetYScale(); break;
    case StrokeScaling_None:       break;
    }
    float width = stroke.Width * scale;

    ExpandBoundsToPath(shape, trans, pos, coord, &bounds);
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

// Grows bounds by every stroked path, each taken as round joined and capped.
template<class Transformer>
void ExpandBoundsToStrokesSimplified(const ShapeDataInterface& shape, const Transformer& trans, RectF* bounds)
{
    ShapePosInfo pos(shape.GetStartingPos());
    float        coord[Edge_MaxCoord];
    unsigned     styles[3];

    while (shape.ReadPathInfo(&pos, coord, styles) != Shape_EndShape)
    {
        if (styles[2])
        {
            RectF stroke = ComputeBoundsRoundStroke(shape, trans, &pos, coord, styles);
            if (stroke.IsNormal())
            {
                bounds->ExpandToPoint(stroke.x1, stroke.y1);
                bounds->ExpandToPoint(stroke.x2, stroke.y2);
            }
        }
        else
            shape.SkipPathData(&pos);
    }
}

// Fill and stroke bounds without a stroke generator (strokes taken as round joined and capped).
template<class Transformer>
RectF ComputeBoundsFillAndStrokesSimplified(const ShapeDataInterface& shape, const Transformer& trans,
                                            BoundEdges edges = Bound_OuterEdges)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    ExpandBoundsToFill(shape, trans, &bounds, edges);
    if (shape.GetStrokeStyleCount())
    {
        shape.Rewind();
        ExpandBoundsToStrokesSimplified(shape, trans, &bounds);
    }
    return bounds;
}

}} // namespace Scaleform::Render

#endif
