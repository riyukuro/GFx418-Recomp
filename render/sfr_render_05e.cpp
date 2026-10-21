// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the scale9 grid TU
// (Render_Scale9Grid). Scale9GridInfo computes the nine cell matrices of a grid; Scale9GridTess cuts an image fill
// along the grid lines and maps the pieces through them.
// Queue unit sfr_render_05 is split along its original sources (05e Render_Scale9Grid).
// MS2-UNIT: sfr_render_05e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142690d10-0x142695030 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_scale9grid.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_math2d.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>

namespace Scaleform { namespace Render {

// the key of a scale9 mesh: grid, bounds, the scale key of the view matrix and the shape translation
// @0x142693fd0
void Scale9GridData::MakeMeshKey(float* keyData) const
{
    *keyData++ = S9Rect.x1;
    *keyData++ = S9Rect.y1;
    *keyData++ = S9Rect.x2;
    *keyData++ = S9Rect.y2;
    *keyData++ = Bounds.x1;
    *keyData++ = Bounds.y1;
    *keyData++ = Bounds.x2;
    *keyData++ = Bounds.y2;
    MeshKey::CalcMatrixKey(ViewMtx, keyData, 0);
    keyData += 3;
    *keyData++ = ShapeMtx.Tx();
    *keyData++ = ShapeMtx.Ty();
}

// The grid and the shape bounds are taken through the grid matrix; the bounds become a parallelogram whose margins
// (bounds minus grid, as fractions of its pseudo width / height) keep their shape-space size. Each of the nine cells
// gets the matrix mapping its shape-space rectangle onto its piece of the parallelogram.
// @0x1426910c0
Scale9GridInfo::Scale9GridInfo(const Scale9GridData* s9g, const Matrix2F& viewMtx)
{
    Scale9        = s9g->S9Rect;
    S9gMatrix     = s9g->Scale9Mtx;
    ShapeMatrix   = s9g->ShapeMtx;
    Bounds        = s9g->Bounds;
    InverseMatrix = S9gMatrix.GetInverse();
    InverseMatrix.Append(ShapeMatrix.GetInverse());
    InverseMatrix.Append(viewMtx);

    float gx1 = Scale9.x1;
    float gy1 = Scale9.y1;
    float gx2 = Scale9.x2;
    float gy2 = Scale9.y2;

    float bx1 = Bounds.x1;
    float by1 = Bounds.y1;
    float bx2 = Bounds.x2;
    float by2 = Bounds.y2;

    // the bounds must reach past the grid on every side, or the margin matrices degenerate
    if (bx1 >= gx1) bx1 = gx1 - 0.9f;
    if (by1 >= gy1) by1 = gy1 - 0.9f;
    if (bx2 <= gx2) bx2 = gx1 + 0.9f;
    if (by2 <= gy2) by2 = gy1 + 0.9f;

    // the bounds corners, counter-clockwise from bottom left
    float tx1 = bx1, ty1 = by1;
    float tx2 = bx2, ty2 = by1;
    float tx3 = bx2, ty3 = by2;
    float tx4 = bx1, ty4 = by2;
    S9gMatrix.Transform(&tx1, &ty1);
    S9gMatrix.Transform(&tx2, &ty2);
    S9gMatrix.Transform(&tx3, &ty3);
    S9gMatrix.Transform(&tx4, &ty4);

    float w = Math2D::Distance(tx1, ty1, tx2, ty2);
    float h = Math2D::Distance(tx2, ty2, tx3, ty3);
    if (w == 0) w = 0.001f;
    if (h == 0) h = 0.001f;

    // margins as fractions of the transformed sides
    float kx1 = (gx1 - bx1) / w;
    float ky1 = (gy1 - by1) / h;
    float kx2 = (bx2 - gx2) / w;
    float ky2 = (by2 - gy2) / h;

    // margins that would overlap are shrunk to fit
    float d = kx1 + kx2;
    if (d > 1)
    {
        d += 0.05f;
        kx1 /= d;
        kx2 /= d;
    }
    d = ky1 + ky2;
    if (d > 1)
    {
        d += 0.05f;
        ky1 /= d;
        ky2 /= d;
    }

    // the eight points where the grid lines meet the outline, counter-clockwise from the bottom edge
    float ox1 = tx1 + (tx2 - tx1) * kx1;
    float oy1 = ty1 + (ty2 - ty1) * kx1;
    float ox2 = tx2 - (tx2 - tx1) * kx2;
    float oy2 = ty2 - (ty2 - ty1) * kx2;
    float ox3 = tx2 + (tx3 - tx2) * ky1;
    float oy3 = ty2 + (ty3 - ty2) * ky1;
    float ox4 = tx3 - (tx3 - tx2) * ky2;
    float oy4 = ty3 - (ty3 - ty2) * ky2;
    float ox5 = tx3 - (tx3 - tx4) * kx2;
    float oy5 = ty3 - (ty3 - ty4) * kx2;
    float ox6 = tx4 + (tx3 - tx4) * kx1;
    float oy6 = ty4 + (ty3 - ty4) * kx1;
    float ox7 = tx4 - (tx4 - tx1) * ky2;
    float oy7 = ty4 - (ty4 - ty1) * ky2;
    float ox8 = tx1 + (tx4 - tx1) * ky1;
    float oy8 = ty1 + (ty4 - ty1) * ky1;

    // the four inner crossings
    float ix1 = ox8 + (tx2 - tx1) * kx1;
    float iy1 = oy8 + (ty2 - ty1) * kx1;
    float ix2 = ox3 - (tx2 - tx1) * kx2;
    float iy2 = oy3 - (ty2 - ty1) * kx2;
    float ix3 = ox4 - (tx3 - tx4) * kx2;
    float iy3 = oy4 - (ty3 - ty4) * kx2;
    float ix4 = ox7 + (tx3 - tx4) * kx1;
    float iy4 = oy7 + (ty3 - ty4) * kx1;

    // cell matrices: 0..2 bottom row, 3..5 middle, 6..8 top; each maps a rectangle onto three parallelogram points
    float p[6];
#define S9_PARL(a, b, c, d_, e, f) { p[0] = a; p[1] = b; p[2] = c; p[3] = d_; p[4] = e; p[5] = f; }
    S9_PARL(tx1, ty1, ox1, oy1, ix1, iy1); ResultingMatrices[0].SetRectToParl(bx1, by1, gx1, gy1, p);
    S9_PARL(ox1, oy1, ox2, oy2, ix2, iy2); ResultingMatrices[1].SetRectToParl(gx1, by1, gx2, gy1, p);
    S9_PARL(ox2, oy2, tx2, ty2, ox3, oy3); ResultingMatrices[2].SetRectToParl(gx2, by1, bx2, gy1, p);
    S9_PARL(ox8, oy8, ix1, iy1, ix4, iy4); ResultingMatrices[3].SetRectToParl(bx1, gy1, gx1, gy2, p);
    S9_PARL(ix1, iy1, ix2, iy2, ix3, iy3); ResultingMatrices[4].SetRectToParl(gx1, gy1, gx2, gy2, p);
    S9_PARL(ix2, iy2, ox3, oy3, ox4, oy4); ResultingMatrices[5].SetRectToParl(gx2, gy1, bx2, gy2, p);
    S9_PARL(ox7, oy7, ix4, iy4, ox6, oy6); ResultingMatrices[6].SetRectToParl(bx1, gy2, gx1, by2, p);
    S9_PARL(ix4, iy4, ix3, iy3, ox5, oy5); ResultingMatrices[7].SetRectToParl(gx1, gy2, gx2, by2, p);
    S9_PARL(ix3, iy3, ox4, oy4, tx3, ty3); ResultingMatrices[8].SetRectToParl(gx2, gy2, bx2, by2, p);
#undef S9_PARL

    ResultingGrid.x1 = gx1;
    ResultingGrid.y1 = gy1;
    ResultingGrid.x2 = gx2;
    ResultingGrid.y2 = gy2;
}

// @0x1426941d0
unsigned Scale9GridInfo::Transform(float* x, float* y) const
{
    // area code -> cell matrix (codes 5, 7, 10 and 11 cannot happen)
    static const UByte codeToMtx[] = { 4, 5, 7, 8, 3, 0, 6, 0, 1, 2, 0, 0, 0 };

    ShapeMatrix.Transform(x, y);
    unsigned areaCode = (*x > ResultingGrid.x2) | ((*y > ResultingGrid.y2) << 1) | ((*x < ResultingGrid.x1) << 2) |
                        ((*y < ResultingGrid.y1) << 3);
    ResultingMatrices[codeToMtx[areaCode]].Transform(x, y);
    InverseMatrix.Transform(x, y);
    return areaCode;
}

// @0x142693cd0
float Scale9GridInfo::GetScale() const
{
    float scale = 0;
    for (int i = 0; i < 9; ++i)
        scale += ResultingMatrices[i].GetScale();
    return scale / 9.0f;
}

// the bounding box of the four transformed corners
// @0x142693b30
RectF Scale9GridInfo::AdjustBounds(const RectF& bounds) const
{
    float x1 = bounds.x1, y1 = bounds.y1;
    float x2 = bounds.x2, y2 = bounds.y1;
    float x3 = bounds.x2, y3 = bounds.y2;
    float x4 = bounds.x1, y4 = bounds.y2;
    Transform(&x1, &y1);
    Transform(&x2, &y2);
    Transform(&x3, &y3);
    Transform(&x4, &y4);

    float minX = x1, minY = y1, maxX = x1, maxY = y1;
    if (x2 < minX) minX = x2;
    if (y2 < minY) minY = y2;
    if (x2 > maxX) maxX = x2;
    if (y2 > maxY) maxY = y2;
    if (x3 < minX) minX = x3;
    if (y3 < minY) minY = y3;
    if (x3 > maxX) maxX = x3;
    if (y3 > maxY) maxY = y3;
    if (x4 < minX) minX = x4;
    if (y4 < minY) minY = y4;
    if (x4 > maxX) maxX = x4;
    if (y4 > maxY) maxY = y4;
    return RectF(minX, minY, maxX, maxY);
}

// where segment a-b crosses the line through c-d (false when parallel or outside the segment)
inline bool SegmentLineIntersection(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy,
                                    float* x, float* y, float epsilon)
{
    float num = (ay - cy) * (dx - cx) - (ax - cx) * (dy - cy);
    float den = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (fabsf(den) < epsilon)
        return false;

    float t = num / den;
    if (t < -0.00001f || t > 1.00001f)
        return false;

    *x = ax + t * (bx - ax);
    *y = ay + t * (by - ay);
    return true;
}

// bit 0: right of the grid, 1: above, 2: left, 3: below (folded into its callers in the exe)
unsigned Scale9GridTess::getAreaCode(const RectF& r, float x, float y) const
{
    return (x > r.x2) | ((y > r.y2) << 1) | ((x < r.x1) << 2) | ((y < r.y1) << 3);
}

// @0x1426945b0
void Scale9GridTess::addVertex(TmpVertices& ver, float x, float y, float u, float v, unsigned areaCode)
{
    TmpVertexType tv = { areaCode, VerCount, 0 };
    ver.PushBack(tv);
    Vertices[VerCount].Set(x, y, u, v);
    VerCount++;
}

// a vertex on a grid line belongs to the cells on both sides of it
// @0x142694640
void Scale9GridTess::addVertices(TmpVertices& ver, const Matrix2F& toUV, float x, float y, unsigned code1,
                                 unsigned code2)
{
    float u = x;
    float v = y;
    toUV.Transform(&u, &v);
    TmpVertexType tv1 = { code1, VerCount, 0 };
    TmpVertexType tv2 = { code2, VerCount, 0 };
    ver.PushBack(tv1);
    ver.PushBack(tv2);
    Vertices[VerCount].Set(x, y, u, v);
    VerCount++;
}

// a grid corner inside the image quad (same side of all four edges) belongs to its four cells
// @0x142694300
void Scale9GridTess::addCorner(TmpVertices& ver, const float* c, float x, float y, const Matrix2F& toUV,
                               unsigned code1, unsigned code2, unsigned code3, unsigned code4)
{
    float c1 = Math2D::CrossProduct(c[0], c[1], c[2], c[3], x, y);
    float c2 = Math2D::CrossProduct(c[2], c[3], c[4], c[5], x, y);
    float c3 = Math2D::CrossProduct(c[4], c[5], c[6], c[7], x, y);
    float c4 = Math2D::CrossProduct(c[6], c[7], c[0], c[1], x, y);

    bool n1 = c1 <= 0, n2 = c2 <= 0, n3 = c3 <= 0, n4 = c4 <= 0;
    bool p1 = c1 >= 0, p2 = c2 >= 0, p3 = c3 >= 0, p4 = c4 >= 0;

    if ((n1 == n2 && n2 == n3 && n3 == n4) || (p1 == p2 && p2 == p3 && p3 == p4))
    {
        float u = x;
        float v = y;
        toUV.Transform(&u, &v);
        TmpVertexType tv1 = { code1, VerCount, 0 };
        TmpVertexType tv2 = { code2, VerCount, 0 };
        TmpVertexType tv3 = { code3, VerCount, 0 };
        TmpVertexType tv4 = { code4, VerCount, 0 };
        ver.PushBack(tv1);
        ver.PushBack(tv2);
        ver.PushBack(tv3);
        ver.PushBack(tv4);
        Vertices[VerCount].Set(x, y, u, v);
        VerCount++;
    }
}

// the vertices of one cell (ver[i1..i2)) are sorted around their centre and emitted as a triangle fan
// MS2-FUNCTIONAL: register allocation (the array pointer lives in r15 instead of r14); same code otherwise
// @0x1426947c0
void Scale9GridTess::tessellateArea(TmpVertices& ver, unsigned i1, unsigned i2)
{
    if (i1 + 3 <= i2)
    {
        unsigned i;
        float    cx = 0;
        float    cy = 0;
        for (i = i1; i < i2; ++i)
        {
            TmpVertexType& v = ver[i];
            cx += Vertices[v.VerIdx].x;
            cy += Vertices[v.VerIdx].y;
        }
        cx /= (i2 - i1);
        cy /= (i2 - i1);

        for (i = i1; i < i2; ++i)
        {
            TmpVertexType& v = ver[i];
            v.Slope = Math2D::SlopeRatio(cx, cy, Vertices[v.VerIdx].x, Vertices[v.VerIdx].y);
        }

        Alg::QuickSortSliced(ver, i1, i2, cmpSlopes);

        for (i = i1 + 2; i < i2; ++i)
        {
            Indices.PushBack((UInt16)ver[i1].VerIdx);
            Indices.PushBack((UInt16)ver[i - 1].VerIdx);
            Indices.PushBack((UInt16)ver[i].VerIdx);
        }
    }
}

// MS2-FUNCTIONAL: register allocation and scheduling of the float math from the uv matrix setup on (same calls, same
// operations)
// @0x142691df0
Scale9GridTess::Scale9GridTess(MemoryHeap* heap, const Scale9GridInfo& s9g, const RectF& imgRect,
                               const Matrix2F& uvMatrix, const Matrix2F& fillMatrix)
    : VerCount(0), Indices(heap)
{
    // the image quad in grid space
    float c[8] = { imgRect.x1, imgRect.y1, imgRect.x2, imgRect.y1, imgRect.x2, imgRect.y2, imgRect.x1, imgRect.y2 };
    s9g.ShapeMatrix.Transform(&c[0], &c[1]);
    s9g.ShapeMatrix.Transform(&c[2], &c[3]);
    s9g.ShapeMatrix.Transform(&c[4], &c[5]);
    s9g.ShapeMatrix.Transform(&c[6], &c[7]);

    // the fill matrix is reduced to its flips and quarter turns (about the texture centre) before it is applied,
    // so pieces of one bitmap can be reused mirrored or rotated
    Matrix2F uv = uvMatrix;
    Matrix2F fm1 = fillMatrix;
    Matrix2F fm2;
    float    em = 0.00001f;
    if (fm1.Sx() <= -em)  fm1.Sx() = -1;
    if (fm1.Sx() >= +em)  fm1.Sx() = +1;
    if (fm1.Sy() <= -em)  fm1.Sy() = -1;
    if (fm1.Sy() >= +em)  fm1.Sy() = +1;
    if (fm1.Shx() <= -em) fm1.Shx() = -1;
    if (fm1.Shx() >= +em) fm1.Shx() = +1;
    if (fm1.Shy() <= -em) fm1.Shy() = -1;
    if (fm1.Shy() >= +em) fm1.Shy() = +1;
    fm1.Tx() = 0;
    fm1.Ty() = 0;
    fm2.AppendTranslation(-0.5f, -0.5f);
    fm2.Append(fm1);
    fm2.AppendTranslation(0.5f, 0.5f);
    uv.Prepend(fm2);

    Matrix2F toUV;
    toUV.SetParlToRect(c, 0, 0, 1, 1);
    toUV.Append(uv);

    RectF       r = s9g.ResultingGrid;
    TmpVertices tmpVer(heap);

    // the four image corners
    float x1 = 0, y1 = 0;
    float x2 = 1, y2 = 0;
    float x3 = 1, y3 = 1;
    float x4 = 0, y4 = 1;
    uv.Transform(&x1, &y1);
    uv.Transform(&x2, &y2);
    uv.Transform(&x3, &y3);
    uv.Transform(&x4, &y4);
    addVertex(tmpVer, c[0], c[1], x1, y1, getAreaCode(r, c[0], c[1]));
    addVertex(tmpVer, c[2], c[3], x2, y2, getAreaCode(r, c[2], c[3]));
    addVertex(tmpVer, c[4], c[5], x3, y3, getAreaCode(r, c[4], c[5]));
    addVertex(tmpVer, c[6], c[7], x4, y4, getAreaCode(r, c[6], c[7]));

    // where each image edge crosses each grid line; the vertex goes to the cells on both sides of the line
    float x, y;
    float eps = 0.001f;
    float ex  = (r.x2 - r.x1) / 2;
    float ey  = (r.y2 - r.y1) / 2;
    // edge 0 -> 1
    if (SegmentLineIntersection(c[0], c[1], c[2], c[3], r.x1, r.y1, r.x2, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[0], c[1], c[2], c[3], r.x2, r.y1, r.x2, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    if (SegmentLineIntersection(c[0], c[1], c[2], c[3], r.x2, r.y2, r.x1, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[0], c[1], c[2], c[3], r.x1, r.y2, r.x1, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    // edge 1 -> 2
    if (SegmentLineIntersection(c[2], c[3], c[4], c[5], r.x1, r.y1, r.x2, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[2], c[3], c[4], c[5], r.x2, r.y1, r.x2, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    if (SegmentLineIntersection(c[2], c[3], c[4], c[5], r.x2, r.y2, r.x1, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[2], c[3], c[4], c[5], r.x1, r.y2, r.x1, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    // edge 2 -> 3
    if (SegmentLineIntersection(c[4], c[5], c[6], c[7], r.x1, r.y1, r.x2, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[4], c[5], c[6], c[7], r.x2, r.y1, r.x2, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    if (SegmentLineIntersection(c[4], c[5], c[6], c[7], r.x2, r.y2, r.x1, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[4], c[5], c[6], c[7], r.x1, r.y2, r.x1, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    // edge 3 -> 0
    if (SegmentLineIntersection(c[6], c[7], c[0], c[1], r.x1, r.y1, r.x2, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[6], c[7], c[0], c[1], r.x2, r.y1, r.x2, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));
    if (SegmentLineIntersection(c[6], c[7], c[0], c[1], r.x2, r.y2, r.x1, r.y2, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x, y + ey), getAreaCode(r, x, y - ey));
    if (SegmentLineIntersection(c[6], c[7], c[0], c[1], r.x1, r.y2, r.x1, r.y1, &x, &y, eps))
        addVertices(tmpVer, toUV, x, y, getAreaCode(r, x + ex, y), getAreaCode(r, x - ex, y));

    // grid corners inside the image
    addCorner(tmpVer, c, r.x1, r.y1, toUV, 0, 4, 12, 8);
    addCorner(tmpVer, c, r.x2, r.y1, toUV, 1, 0, 8, 9);
    addCorner(tmpVer, c, r.x2, r.y2, toUV, 3, 2, 0, 1);
    addCorner(tmpVer, c, r.x1, r.y2, toUV, 2, 6, 4, 0);

    // group by cell, fan each group
    Alg::QuickSort(tmpVer, cmpCodes);
    unsigned i1 = 0;
    unsigned i2;
    for (i2 = 1; i2 < tmpVer.GetSize(); ++i2)
    {
        if (tmpVer[i2].AreaCode != tmpVer[i1].AreaCode)
        {
            tessellateArea(tmpVer, i1, i2);
            i1 = i2;
        }
    }
    tessellateArea(tmpVer, i1, i2);

    for (i1 = 0; i1 < VerCount; ++i1)
        transformVertex(s9g, Vertices[i1]);
}

// @0x142694f30
SF_NOINLINE void Scale9GridTess::transformVertex(const Scale9GridInfo& s9g, Image9GridVertex& v) const
{
    static const UByte codeToMtx[] = { 4, 5, 7, 8, 3, 0, 6, 0, 1, 2, 0, 0, 0 };

    unsigned areaCode = (v.x > s9g.ResultingGrid.x2) | ((v.y > s9g.ResultingGrid.y2) << 1) |
                        ((v.x < s9g.ResultingGrid.x1) << 2) | ((v.y < s9g.ResultingGrid.y1) << 3);
    s9g.ResultingMatrices[codeToMtx[areaCode]].Transform(&v.x, &v.y);
    s9g.InverseMatrix.Transform(&v.x, &v.y);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142693a70
// MS2-PIN: ??_7?$RefCountBase@UScale9GridInfo@Render@Scaleform@@$01@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7Scale9GridInfo@Render@Scaleform@@6B@ 0x1431922a0
// MS2-FUNCTIONAL ??$QuickSortSliced@V?$ArrayStaticBuffPOD@UTmpVertexType@Scale9GridTess@Render@Scaleform@@$0EI@$01@Scaleform@@P6A_NAEBUTmpVertexType@Scale9GridTess@Render@2@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayStaticBuffPOD@UTmpVertexType@Scale9GridTess@Render@Scaleform@@$0EI@$01@1@_K1P6A_NAEBUTmpVertexType@Scale9GridTess@Render@1@2@Z@Z: callee-saved register choice (rbp/r12 for r14/r15, end spilled one slot lower); same sort
// MS2-PIN: ??$QuickSortSliced@V?$ArrayStaticBuffPOD@UTmpVertexType@Scale9GridTess@Render@Scaleform@@$0EI@$01@Scaleform@@P6A_NAEBUTmpVertexType@Scale9GridTess@Render@2@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayStaticBuffPOD@UTmpVertexType@Scale9GridTess@Render@Scaleform@@$0EI@$01@1@_K1P6A_NAEBUTmpVertexType@Scale9GridTess@Render@1@2@Z@Z 0x142690d10
