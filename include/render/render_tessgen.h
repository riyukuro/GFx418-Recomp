// Recovered Scaleform 4.1.18 Render: the stroke generator the bound / hit-test templates take (Render_TessGen), only
// as far as the recovered units use it: its two linear heaps (the stroker, the stroke sorter and the vertex path that
// follow them come with the stroker units).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TESSGEN_H
#define MS2_SF_RENDER_TESSGEN_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessellator.h"
// (appended for sfr_render_03d)
#include "ms2/scaleform/include/render/render_stroker.h"
#include "ms2/scaleform/include/render/render_hittest.h"

namespace Scaleform { namespace Render {

// Scratch state for turning strokes into outlines; Heap1 serves the stroker and the path, Heap2 the sorter.
struct StrokeGenerator
{
    LinearHeap Heap1;   // +0x00
    LinearHeap Heap2;   // +0x28
    // (appended for sfr_render_03d: the stroke bound / hit-test templates)
    Stroker      mStroker;        // +0x50
    StrokeSorter mStrokeSorter;   // +0xa8
    VertexPath   mPath;           // +0x178
};

// (appended for sfr_render_07o) the renderer's shared tessellation scratch (Renderer2DImpl +0x58): four linear
// heaps, then the tessellator; the stroker, stroke sorter, hairliner and AA stroker that follow it (+0x608, +0x660,
// +0x730, +0x9d0) stay opaque until their units.
// (appended for sfr_render_03d) the hairliner and the AA stroker of the mesh generator, so far only reached through
// their TessBase slots; their members come with their units
class Hairliner : public TessBase
{
public:
    virtual void      Clear();
    virtual CoordType GetLastX() const;
    virtual CoordType GetLastY() const;
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();
    virtual void      FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex);
    virtual void      Transform(const Matrix2F& m);
    virtual Matrix2F  StretchTo(float x1, float y1, float x2, float y2);
    virtual unsigned  GetVertexCount() const;
    virtual unsigned  GetMeshCount() const;
    virtual unsigned  GetMeshVertexCount(unsigned meshIdx) const;
    virtual unsigned  GetMeshTriangleCount(unsigned meshIdx) const;
    virtual void      GetMesh(unsigned meshIdx, TessMesh* mesh) const;
    virtual unsigned  GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const;
    virtual void      GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const;

    // (appended for sfr_render_03d: the shape mesh provider's hairlines) the width is kept doubled
    void SetWidth(CoordType w) { Width = w * 2; }
    void SetToleranceParam(const ToleranceParams& param);   // 0x1426b4360
    void Tessellate();                                      // 0x1426b4660

private:
    UByte     Unk_08[0x10];          // +0x08
    CoordType Width;                 // +0x18
    UByte     Unk_1c[0x2a0 - 0x1c];  // +0x1c
};

class StrokerAA : public TessBase
{
public:
    virtual void      Clear();
    virtual CoordType GetLastX() const;
    virtual CoordType GetLastY() const;
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();
    virtual void      FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex);
    virtual void      Transform(const Matrix2F& m);
    virtual Matrix2F  StretchTo(float x1, float y1, float x2, float y2);
    virtual unsigned  GetVertexCount() const;
    virtual unsigned  GetMeshCount() const;
    virtual unsigned  GetMeshVertexCount(unsigned meshIdx) const;
    virtual unsigned  GetMeshTriangleCount(unsigned meshIdx) const;
    virtual void      GetMesh(unsigned meshIdx, TessMesh* mesh) const;
    virtual unsigned  GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const;
    virtual void      GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const;
    // (the size is not recovered yet)
    // (appended for sfr_render_03d: the shape mesh provider's solid AA strokes) left and right of the path alike
    void SetSolidWidth(CoordType w)  { SolidWidthR = SolidWidthL = w; }
    void SetEdgeAAWidth(CoordType w) { EdgeAAWidthR = EdgeAAWidthL = w; }
    void SetLineJoin(StrokerTypes::LineJoinType lj)   { LineJoin = lj; }
    void SetStartLineCap(StrokerTypes::LineCapType lc) { StartLineCap = lc; }
    void SetEndLineCap(StrokerTypes::LineCapType lc)   { EndLineCap = lc; }
    void SetMiterLimit(CoordType ml)  { MiterLimit = ml; }
    void SetToleranceParam(const ToleranceParams& param);   // 0x1426ae280

private:
    StrokerTypes::LineJoinType LineJoin;       // +0x08
    StrokerTypes::LineCapType  StartLineCap;   // +0x0c
    StrokerTypes::LineCapType  EndLineCap;     // +0x10
    CoordType                  MiterLimit;     // +0x14
    UByte                      Unk_18[8];      // +0x18
    CoordType                  SolidWidthL;    // +0x20
    CoordType                  SolidWidthR;    // +0x24
    CoordType                  EdgeAAWidthL;   // +0x28
    CoordType                  EdgeAAWidthR;   // +0x2c
};

struct MeshGenerator
{
    LinearHeap  Heap1;   // +0x00
    LinearHeap  Heap2;   // +0x28
    LinearHeap  Heap3;   // +0x50
    LinearHeap  Heap4;   // +0x78
    Tessellator mTess;   // +0xa0
    // (appended for sfr_render_03d: the shape mesh provider's strokes)
    Stroker      mStroker;        // +0x608
    StrokeSorter mStrokeSorter;   // +0x660
    Hairliner    mHairliner;      // +0x730
    StrokerAA    mStrokerAA;      // +0x9d0

    // clears the tessellator and the strokers, then the heaps
    void Clear();        // 0x14262a890
};

}} // namespace Scaleform::Render

#endif
