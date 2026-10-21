// Recovered Scaleform 4.1.18 Render: scale9 grids (Render_Scale9Grid, sfr_render_05e). Scale9GridInfo turns a grid
// rectangle, the shape bounds and the grid / shape matrices into one matrix per grid cell (corners keep their size,
// edges stretch one way, the middle both); Scale9GridTess cuts an image fill rectangle along the grid lines into a
// small fan-triangulated mesh and maps its vertices through those cell matrices.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout of Scale9GridInfo (0x1c0 bytes, vftable 0x1431922a0) from its ctor 0x1426910c0.
#ifndef MS2_SF_RENDER_SCALE9GRID_H
#define MS2_SF_RENDER_SCALE9GRID_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_arraystaticbuff.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_vertex.h"

namespace Scaleform { namespace Render {

class Scale9GridData;

struct Scale9GridInfo : public RefCountBase<Scale9GridInfo, Stat_Default_Mem>
{
    RectF    Scale9;                  // +0x10 the grid rectangle (shape space)
    Matrix2F S9gMatrix;               // +0x20
    Matrix2F ShapeMatrix;             // +0x40
    RectF    Bounds;                  // +0x60 the shape bounds
    RectF    ResultingGrid;           // +0x70
    Matrix2F InverseMatrix;           // +0x80 back from grid space
    Matrix2F ResultingMatrices[9];    // +0xa0 one per cell, bottom row first

    Scale9GridInfo() {}
    Scale9GridInfo(const Scale9GridData* s9g, const Matrix2F& viewMtx);

    // maps the point through the matrix of the cell it falls in; returns the cell's area code
    unsigned Transform(float* x, float* y) const;
    // the mean scale of the nine cell matrices
    float    GetScale() const;
    // bit 0: right of the grid, 1: above, 2: left, 3: below
    unsigned GetAreaCode(float x, float y) const;
    RectF    AdjustBounds(const RectF& bounds) const;
};

struct Image9GridVertex
{
    float x, y;
    float u, v;

    void Set(float x_, float y_, float u_, float v_)
    {
        x = x_;
        y = y_;
        u = u_;
        v = v_;
    }

    static VertexElement Elements[3];
    static VertexFormat  Format;
};

struct Scale9GridTess
{
    struct TmpVertexType
    {
        unsigned AreaCode;
        unsigned VerIdx;
        float    Slope;
    };
    typedef ArrayStaticBuffPOD<TmpVertexType, 8 * 9> TmpVertices;

public:
    Scale9GridTess(MemoryHeap* heap, const Scale9GridInfo& info, const RectF& imgRect, const Matrix2F& uvMatrix,
                   const Matrix2F& fillMatrix);

    unsigned          GetVertexCount() const { return VerCount; }
    Image9GridVertex* GetVertices()          { return Vertices; }
    unsigned          GetIndexCount() const  { return (unsigned)Indices.GetSize(); }
    UInt16*           GetIndices()           { return &Indices[0]; }

private:
    unsigned getAreaCode(const RectF& r, float x, float y) const;
    void addVertex(TmpVertices& ver, float x, float y, float u, float v, unsigned areaCode);
    void addVertices(TmpVertices& ver, const Matrix2F& toUV, float x, float y, unsigned code1, unsigned code2);
    void addCorner(TmpVertices& ver, const float* coord, float x, float y, const Matrix2F& toUV, unsigned code1,
                   unsigned code2, unsigned code3, unsigned code4);
    void transformVertex(const Scale9GridInfo& s9g, Image9GridVertex& v) const;
    void tessellateArea(TmpVertices& ver, unsigned i1, unsigned i2);

    static bool cmpCodes(const TmpVertexType& a, const TmpVertexType& b) { return a.AreaCode < b.AreaCode; }
    static bool cmpSlopes(const TmpVertexType& a, const TmpVertexType& b) { return a.Slope < b.Slope; }

    Image9GridVertex                  Vertices[24];
    unsigned                          VerCount;
    ArrayStaticBuffPOD<UInt16, 8 * 9> Indices;
};

}} // namespace Scaleform::Render

#endif
