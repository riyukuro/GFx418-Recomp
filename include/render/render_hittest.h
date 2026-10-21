// Recovered Scaleform 4.1.18 Render: shape hit testing (Render_HitTest, sfr_render_05g). The fill test counts ray
// crossings of the path edges (curves are split into y-monotone pieces, cubics approximated by quadratics first);
// the stroke tests run on a flattened VertexPath: a round stroke is "near a segment or a vertex", any other stroke
// is a winding test on its already generated outline.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// VertexPath belongs to Render_TessDefs; it lives here until that unit is recovered. Layout from the stroke hit
// tests (0x14267a920 / 0x14267ad80): the vertices at +0x08 (pages of 16), the paths at +0x30 (pages of 4).
#ifndef MS2_SF_RENDER_HITTEST_H
#define MS2_SF_RENDER_HITTEST_H

#include "ms2/scaleform/include/render/render_tessdefs.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_math2d.h"

namespace Scaleform { namespace Render {

struct VertexBasic
{
    float x, y;
};

struct PathBasic
{
    unsigned Start, Count;
};

class VertexPath : public TessBase
{
public:
    typedef float       CoordType;
    typedef VertexBasic VertexType;

    VertexPath(LinearHeap* heap) : Vertices(heap), Paths(heap) {}

    virtual void      Clear();
    virtual CoordType GetLastX() const { return Vertices.Back().x; }
    virtual CoordType GetLastY() const { return Vertices.Back().y; }
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();
    virtual void      FinalizePath(unsigned, unsigned, bool, bool);

    virtual void      Transform(const Matrix2F&) {}
    virtual Matrix2F  StretchTo(float, float, float, float) { return Matrix2F(); }

    virtual unsigned  GetVertexCount() const { return 0; }
    virtual unsigned  GetMeshCount() const { return 0; }
    virtual unsigned  GetMeshVertexCount(unsigned) const { return 0; }
    virtual unsigned  GetMeshTriangleCount(unsigned) const { return 0; }
    virtual void      GetMesh(unsigned, TessMesh*) const {}
    virtual unsigned  GetVertices(TessMesh*, TessVertex*, unsigned) const { return 0; }
    virtual void      GetTrianglesI16(unsigned, UInt16*, unsigned, unsigned) const {}

    UPInt             GetNumPaths() const             { return Paths.GetSize(); }
    const PathBasic&  GetPath(unsigned i) const       { return Paths[i]; }
    UPInt             GetNumVertices() const          { return Vertices.GetSize(); }
    const VertexType& GetVertex(unsigned i) const     { return Vertices[i]; }

private:
    ArrayPaged<VertexBasic, 4, 16> Vertices;   // +0x08
    ArrayPaged<PathBasic, 2, 4>    Paths;      // +0x30
    unsigned                       LastVertex; // +0x58
};

namespace Math2D {

// a quadratic curve as six coordinates (the halves of SubdivideQuadCurve)
struct QuadCoordType
{
    float x1, y1, x2, y2, x3, y3;
};

// splits the quadratic curve at t into c1 (start .. t) and c2 (t .. end)
template<class CurveType>
void SubdivideQuadCurve(float x1, float y1, float x2, float y2, float x3, float y3, float t, CurveType* c1,
                        CurveType* c2)
{
    float x12  = x1 + t * (x2 - x1);
    float y12  = y1 + t * (y2 - y1);
    float x23  = x2 + t * (x3 - x2);
    float y23  = y2 + t * (y3 - y2);
    float x123 = x12 + t * (x23 - x12);
    float y123 = y12 + t * (y23 - y12);
    c1->x1 = x1;
    c1->y1 = y1;
    c1->x2 = x12;
    c1->y2 = y12;
    c1->x3 = x123;
    c1->y3 = y123;
    c2->x1 = x123;
    c2->y1 = y123;
    c2->x2 = x23;
    c2->y2 = y23;
    c2->x3 = x3;
    c2->y3 = y3;
}

// one coordinate of the quadratic curve at t
inline float CalcPointOnQuadCurve1D(float x1, float x2, float x3, float t)
{
    x1 += t * (x2 - x1);
    x2 += t * (x3 - x2);
    return x1 + t * (x2 - x1);
}

// the unsigned distance of (x, y) from the line (x1 y1) (x2 y2)
inline float LinePointDistanceAbs(float x1, float y1, float x2, float y2, float x, float y)
{
    float d = LinePointDistance(x1, y1, x2, y2, x, y);
    return (d < 0) ? -d : d;
}

} // namespace Math2D

// (x, y) within half the width w of a segment or a vertex of the path
bool HitTestRoundStroke(const VertexPath& path, float w, float x, float y);   // 0x14267ad80
// (x, y) inside the generated stroke outline (non-zero winding)
bool HitTestGeneralStroke(const VertexPath& path, float x, float y);         // 0x14267a920

}} // namespace Scaleform::Render

#endif
