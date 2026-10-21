// Recovered Scaleform 4.1.18 Render: TessBase, the vertex sink curve flattening and the tessellators feed.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Slots checked against the exe callers in Render_TessCurves (GetLastX +0x10, GetLastY +0x18, AddVertex +0x20) and
// the stroker vftables (the rest).
#ifndef MS2_SF_RENDER_TESSDEFS_H
#define MS2_SF_RENDER_TESSDEFS_H

#include "ms2/scaleform/include/render/render_toleranceparams.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"

namespace Scaleform { namespace Render {

typedef float CoordType;

// (appended for the tessellator, sfr_render_05c) coordinate sentinels and the TessVertex::Flags / TessMesh flag bits
const CoordType MinCoord = -1e30f;
const CoordType MaxCoord =  1e30f;
enum TessStyleFlags
{
    TessStyleTranslucent = 0x0001,
    TessStyleOpaque      = 0x0002,
    TessStyleFactorHalf  = 0x0004,
    TessStyleFactorOne   = 0x0008,
    TessStyleMixColors   = 0x0010,
    TessStyleUseColor2   = 0x0020,
    TessStyleComplex     = 0x8000
};
inline unsigned TessStyleIsComplex(unsigned flags) { return flags & TessStyleComplex; }

// (appended for the stroker, sfr_render_05b) one output mesh of a tessellator (0x1c bytes) and one output vertex
// (0x14 bytes): the two styles on its sides, the style flags and the mesh it went to
struct TessMesh
{
    unsigned MeshIdx;       // +0x00
    unsigned Style1;        // +0x04
    unsigned Style2;        // +0x08
    unsigned Flags1;        // +0x0c
    unsigned Flags2;        // +0x10
    unsigned StartVertex;   // +0x14
    unsigned VertexCount;   // +0x18
};
struct TessVertex
{
    CoordType x, y;         // +0x00
    unsigned  Idx;          // +0x08
    UInt16    Styles[2];    // +0x0c
    UInt16    Flags;        // +0x10
    UInt16    Mesh;         // +0x12
};

class TessBase
{
public:
    virtual ~TessBase() {}
    virtual void      Clear() = 0;
    virtual CoordType GetLastX() const = 0;
    virtual CoordType GetLastY() const = 0;
    virtual void      AddVertex(CoordType x, CoordType y) = 0;
    // (appended for the stroker, sfr_render_05b; slots +0x28 .. +0x78 checked against the Stroker / StrokeSorter
    // vftables 0x1431923f0 / 0x143192470)
    virtual void      ClosePath() = 0;
    virtual void      FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex) = 0;
    virtual void      Transform(const Matrix2F& m) = 0;
    virtual Matrix2F  StretchTo(float x1, float y1, float x2, float y2) = 0;
    virtual unsigned  GetVertexCount() const = 0;
    virtual unsigned  GetMeshCount() const = 0;
    virtual unsigned  GetMeshVertexCount(unsigned meshIdx) const = 0;
    virtual unsigned  GetMeshTriangleCount(unsigned meshIdx) const = 0;
    virtual void      GetMesh(unsigned meshIdx, TessMesh* mesh) const = 0;
    virtual unsigned  GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const = 0;
    virtual void      GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const = 0;
};

// (appended for the stroker, sfr_render_05b) maps shape coordinates in place (the stroke sorter, hit tests)
class TransformerBase
{
public:
    virtual ~TransformerBase() {}
    virtual void  Transform(float* x, float* y) const = 0;
    virtual float GetScale() const = 0;
    virtual float GetXScale() const = 0;
    virtual float GetYScale() const = 0;
};

// Render_TessCurves (sfr_render_06c)
bool TestQuadCollinearity(TessBase* con, const ToleranceParams& param, CoordType x1, CoordType y1,
                          CoordType x2, CoordType y2, CoordType x3, CoordType y3);                    // 0x1426b8c90
void TessellateQuadCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                         CoordType x3, CoordType y3);                                                 // 0x1426b8790
void TessellateCubicCurve(TessBase* con, const ToleranceParams& param, CoordType x2, CoordType y2,
                          CoordType x3, CoordType y3, CoordType x4, CoordType y4);                    // 0x1426b7f90

}} // namespace Scaleform::Render

#endif
