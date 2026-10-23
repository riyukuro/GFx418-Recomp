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
// (filled in for sfr_render_06h, Render_Hairliner) the hairline mesh: the source paths are swept scan beam by scan
// beam into a planar graph of output vertices and edges; every closed contour of that graph is then widened into a
// strip of AA triangles towards transparent outer vertices (0x2a0 bytes).
class Hairliner : public TessBase
{
public:
    struct SrcVertexType
    {
        CoordType x, y;
    };
    struct OutVertexType
    {
        CoordType x, y;
        unsigned  alpha;   // 1 on the line, 0 at the outer AA edge
    };
    struct TriangleType
    {
        unsigned v1, v2, v3;
    };

private:
    // MonoChainType::flags
    enum
    {
        EndChainFlag     = 1,
        EventFlag        = 2,
        IntersectionFlag = 4
    };
    // what nextScanbeam did to the active chains
    enum
    {
        InsertEdgesFlag = 1,
        RemoveEdgesFlag = 2
    };

    struct PathType
    {
        unsigned start, end;   // first and last source vertex
    };
    // one edge of a monotone chain, lower end first; next continues the chain at the upper end
    struct SrcEdgeType
    {
        unsigned     lower, upper;
        CoordType    slope;   // dx per unit of y
        SrcEdgeType* next;
    };
    // a y-monotone chain while it is swept: the current edge and its x at the beam bottom / top
    struct MonoChainType
    {
        SrcEdgeType* edge;
        CoordType    ySort;
        CoordType    xb, xt;
        unsigned     flags;
        unsigned     prevVertex;   // last output vertex emitted on the chain
    };
    // two chains swapping places inside the beam
    struct IntersectionType
    {
        MonoChainType* mc1;
        MonoChainType* mc2;
        CoordType      y;
    };
    struct HorizontalEdgeType
    {
        CoordType x1, x2, y;
        unsigned  lv, rv;   // leftmost / rightmost output vertex on it so far
    };
    // a directed graph edge; the top bit of node1 marks it walked
    struct FanEdgeType
    {
        enum { Visited = 0x80000000U };
        unsigned  node1, node2;
        CoordType slope;
    };

public:
    Hairliner(LinearHeap* heap);   // 0x1426b3500

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
    typedef ArrayPaged<MonoChainType*, 4, 8> ChainPtrArray;
    typedef ArrayPaged<SrcVertexType, 4, 16> SrcVertexArray;

    // orders source vertex indices by y
    struct CmpScanbeams
    {
        const SrcVertexArray& Ver;
        CmpScanbeams(const SrcVertexArray& v) : Ver(v) {}
        bool operator()(unsigned a, unsigned b) const { return Ver[a].y < Ver[b].y; }
    private:
        void operator=(CmpScanbeams&);
    };

    static bool cmpMonoChains(const MonoChainType* a, const MonoChainType* b);
    static bool cmpActiveChains(const MonoChainType* a, const MonoChainType* b);
    static bool cmpHorizontalEdges(const HorizontalEdgeType& a, const HorizontalEdgeType& b);
    static bool cmpEdges(const FanEdgeType& a, const FanEdgeType& b);
    static bool cmpNode1(const FanEdgeType& a, unsigned b);

    bool forwardMin(int idx, int start) const;
    bool reverseMin(int idx, int end) const;
    bool forwardMax(int idx, int end) const;
    bool reverseMax(int idx, int start) const;

    void      decomposePath(const PathType& path);
    void      buildEdgeList(unsigned start, unsigned numEdges, int step);
    CoordType calcX(const SrcEdgeType* edge, CoordType y) const;
    unsigned  nextScanbeam(CoordType yb, CoordType yt, unsigned startMc, unsigned numMc);
    unsigned  addEventVertex(const SrcVertexType& v);
    unsigned  addEventVertex(const MonoChainType* mc, CoordType yb, bool enforce);
    unsigned  processHorizontalEdges(MonoChainType* mc, unsigned vertex, CoordType yb);
    void      sweepScanbeam(const ChainPtrArray& aet, CoordType yb);
    void      buildGraph();
    void      emitEdge(unsigned v1, unsigned v2);
    void      emitEdge(MonoChainType* mc, unsigned vertex);
    void      emitEdge(HorizontalEdgeType* he, unsigned vertex);
    void      processInterior(CoordType yb);
    unsigned  addJoin(unsigned refVertex, const OutVertexType& v1, const OutVertexType& v2, const OutVertexType& v3,
                      CoordType len1, CoordType len2, CoordType width);
    void      generateTriangles(CoordType width);
    void      generateContourAA(unsigned startEdgeIdx);

    LinearHeap*                          pHeap;                 // +0x08
    CoordType                            Epsilon;               // +0x10
    CoordType                            IntersectionEpsilon;   // +0x14
    CoordType                            Width;                 // +0x18
    ArrayPaged<PathType, 4, 4>           Paths;                 // +0x20
    SrcVertexArray                       SrcVertices;           // +0x48
    ArrayPaged<OutVertexType, 4, 16>     OutVertices;           // +0x70
    ArrayPaged<TriangleType, 4, 16>      Triangles;             // +0x98
    unsigned                             LastVertex;            // +0xc0
    ArrayPaged<SrcEdgeType, 4, 16>       SrcEdges;              // +0xc8
    ArrayPaged<MonoChainType, 4, 8>      MonoChains;            // +0xf0
    ChainPtrArray                        MonoChainsSorted;      // +0x118
    ArrayPaged<unsigned, 4, 16>          Scanbeams;             // +0x140
    ArrayPaged<HorizontalEdgeType, 2, 4> HorizontalEdges;       // +0x168
    unsigned                             StartHorizontals;      // +0x190
    unsigned                             NumHorizontals;        // +0x194
    CoordType                            LastX, LastY;          // +0x198
    CoordType                            MinX, MinY;            // +0x1a0
    CoordType                            MaxX, MaxY;            // +0x1a8
    ChainPtrArray                        ActiveChains;          // +0x1b0
    ChainPtrArray                        ChainsAtBottom;        // +0x1d8
    ArrayPaged<unsigned, 4, 16>          ValidChains;           // +0x200
    ArrayPaged<IntersectionType, 4, 4>   Intersections;         // +0x228
    ArrayPaged<unsigned, 4, 16>          ContourNodes;          // +0x250
    ArrayPaged<FanEdgeType, 4, 16>       FanEdges;              // +0x278
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
    void SetSolidWidth(CoordType w)  { SolidWidthL = SolidWidthR = w; }
    void SetEdgeAAWidth(CoordType w) { EdgeAAWidthL = EdgeAAWidthR = w; }
    void SetLineJoin(StrokerTypes::LineJoinType lj)   { LineJoin = lj; }
    void SetStartLineCap(StrokerTypes::LineCapType lc) { StartLineCap = lc; }
    void SetEndLineCap(StrokerTypes::LineCapType lc)   { EndLineCap = lc; }
    void SetMiterLimit(CoordType ml)  { MiterLimit = ml; }
    void SetToleranceParam(const ToleranceParams& param);   // 0x1426ae280
    // (appended for sfr_render_07o: the text underlines) the fill styles left and right of the next path
    void SetStyleLeft(unsigned s)  { StyleLeft = s; }
    void SetStyleRight(unsigned s) { StyleRight = s; }

private:
    StrokerTypes::LineJoinType LineJoin;       // +0x08
    StrokerTypes::LineCapType  StartLineCap;   // +0x0c
    StrokerTypes::LineCapType  EndLineCap;     // +0x10
    CoordType                  MiterLimit;     // +0x14
    unsigned                   StyleLeft;      // +0x18
    unsigned                   StyleRight;     // +0x1c
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
