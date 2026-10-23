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

    // (appended for sfr_render_04p: Renderer2DImpl's ctor) both heaps on the renderer's heap
    StrokeGenerator(MemoryHeap* heap)
        : Heap1(heap), Heap2(heap), mStroker(&Heap1), mStrokeSorter(&Heap2), mPath(&Heap1)
    {
    }
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

class StrokerAA : public StrokerTypes, public TessBase
{
public:
    // an output vertex: the fill style it belongs to and 1 on the solid part, 0 at the faded AA edge
    struct VertexType
    {
        CoordType x, y;
        UInt16    style;
        UInt16    alpha;

        VertexType() {}
        VertexType(CoordType x_, CoordType y_, unsigned style_, unsigned alpha_ = 0)
            : x(x_), y(y_), style((UInt16)style_), alpha((UInt16)alpha_)
        {
        }
    };
    struct TriangleType
    {
        unsigned v1, v2, v3;
    };

    StrokerAA(LinearHeap* heap);   // 0x1426ad030

    // (appended for sfr_render_03d: the shape mesh provider's solid AA strokes) left and right of the path alike
    void SetSolidWidth(CoordType w)  { WidthLeft = WidthRight = w; }
    void SetEdgeAAWidth(CoordType w) { AaWidthLeft = AaWidthRight = w; }
    void SetLineJoin(LineJoinType lj)   { LineJoin = lj; }
    void SetStartLineCap(LineCapType lc) { StartLineCap = lc; }
    void SetEndLineCap(LineCapType lc)   { EndLineCap = lc; }
    void SetMiterLimit(CoordType ml)  { MiterLimit = ml; }
    void SetToleranceParam(const ToleranceParams& param);   // 0x1426ae280
    // (appended for sfr_render_07o: the text underlines) the fill styles left and right of the next path
    void SetStyleLeft(unsigned s)  { StyleLeft = s; }
    void SetStyleRight(unsigned s) { StyleRight = s; }

    virtual void      Clear();
    virtual CoordType GetLastX() const { return Path.GetLastX(); }
    virtual CoordType GetLastY() const { return Path.GetLastY(); }
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();
    virtual void      FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex);
    virtual void      Transform(const Matrix2F& m);
    virtual Matrix2F  StretchTo(float x1, float y1, float x2, float y2);
    virtual unsigned  GetVertexCount() const { return (unsigned)Vertices.GetSize(); }
    virtual unsigned  GetMeshCount() const { return Triangles.GetSize() != 0; }
    virtual unsigned  GetMeshVertexCount(unsigned) const { return (unsigned)Vertices.GetSize(); }
    virtual unsigned  GetMeshTriangleCount(unsigned) const { return (unsigned)Triangles.GetSize(); }
    virtual void      GetMesh(unsigned meshIdx, TessMesh* mesh) const;
    virtual unsigned  GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const;
    virtual void      GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const;

private:
    // placeholder indices the triangle list may carry for the current edge vertices
    enum VertexMarkers
    {
        MarkerSolidL = 0xFFFFFFFC,
        MarkerSolidR = 0xFFFFFFFD,
        MarkerTotalL = 0xFFFFFFFE,
        MarkerTotalR = 0xFFFFFFFF
    };

    // the per-path widths: solid = the opaque core, total = core plus the AA fringe
    struct WidthsType
    {
        CoordType solidWidthL, solidWidthR, solidWidth;   // solidWidth = average of both sides
        CoordType totalWidthL, totalWidthR, totalWidth;   // totalWidth = average of both sides
        CoordType widthCoeff;                             // narrower total side over the wider one
        CoordType solidCoeffL, solidCoeffR;               // solid over total, per side
        CoordType solidLimitL, solidLimitR;               // miter limits scaled by the widths
        CoordType totalLimitL, totalLimitR;
        bool      solidFlagL, solidFlagR;
        bool      aaFlagL, aaFlagR;
        bool      solidFlag;
        bool      rightSideCalc;                          // miters are computed on the wider (right) side

        WidthsType()
            : solidWidthL(0), solidWidthR(0), solidWidth(0), totalWidthL(0), totalWidthR(0), totalWidth(0),
              widthCoeff(0), solidCoeffL(0), solidCoeffR(0), solidLimitL(0), solidLimitR(0), totalLimitL(0),
              totalLimitR(0), solidFlagL(0), solidFlagR(0), aaFlagL(0), aaFlagR(0), solidFlag(0), rightSideCalc(0)
        {
        }
    };

    // the sliding window over three consecutive segments (1 = previous, 2 = this, 3 = next) and their joins
    struct JoinParamType
    {
        CoordType dx1SolidL, dy1SolidL, dx1TotalL, dy1TotalL;   // +0x00
        CoordType dx2SolidL, dy2SolidL, dx2TotalL, dy2TotalL;
        CoordType dx3SolidL, dy3SolidL, dx3TotalL, dy3TotalL;
        CoordType dx1SolidR, dy1SolidR, dx1TotalR, dy1TotalR;   // +0x30
        CoordType dx2SolidR, dy2SolidR, dx2TotalR, dy2TotalR;
        CoordType dx3SolidR, dy3SolidR, dx3TotalR, dy3TotalR;
        CoordType dbSolidL, dbTotalL, dbSolidR, dbTotalR;       // +0x60 bevel midpoint distances
        CoordType xMiterPrevL, yMiterPrevL, xMiterPrevR, yMiterPrevR, dMiterPrevL, dMiterPrevR;
        CoordType xMiterThisL, yMiterThisL, xMiterThisR, yMiterThisR, dMiterThisL, dMiterThisR;
        CoordType xMiterNextL, yMiterNextL, xMiterNextR, yMiterNextR, dMiterNextL, dMiterNextR;
        CoordType xSolidMiterL, ySolidMiterL, xSolidMiterR, ySolidMiterR, dSolidMiterL, dSolidMiterR;
        bool      badMiterPrevL, badMiterPrevR;                 // +0xd0
        bool      badMiterThisL, badMiterThisR;
        bool      badMiterNextL, badMiterNextR;
        bool      rightTurnPrev, rightTurnThis, rightTurnNext;
        bool      overlapPrev, overlapThis;

        JoinParamType()
            : dx1SolidL(0), dy1SolidL(0), dx1TotalL(0), dy1TotalL(0), dx2SolidL(0), dy2SolidL(0), dx2TotalL(0),
              dy2TotalL(0), dx3SolidL(0), dy3SolidL(0), dx3TotalL(0), dy3TotalL(0), dx1SolidR(0), dy1SolidR(0),
              dx1TotalR(0), dy1TotalR(0), dx2SolidR(0), dy2SolidR(0), dx2TotalR(0), dy2TotalR(0), dx3SolidR(0),
              dy3SolidR(0), dx3TotalR(0), dy3TotalR(0), dbSolidL(0), dbTotalL(0), dbSolidR(0), dbTotalR(0),
              xMiterPrevL(0), yMiterPrevL(0), xMiterPrevR(0), yMiterPrevR(0), dMiterPrevL(0), dMiterPrevR(0),
              xMiterThisL(0), yMiterThisL(0), xMiterThisR(0), yMiterThisR(0), dMiterThisL(0), dMiterThisR(0),
              xMiterNextL(0), yMiterNextL(0), xMiterNextR(0), yMiterNextR(0), dMiterNextL(0), dMiterNextR(0),
              xSolidMiterL(0), ySolidMiterL(0), xSolidMiterR(0), ySolidMiterR(0), dSolidMiterL(0), dSolidMiterR(0),
              badMiterPrevL(0), badMiterPrevR(0), badMiterThisL(0), badMiterThisR(0), badMiterNextL(0),
              badMiterNextR(0), rightTurnPrev(0), rightTurnThis(0), rightTurnNext(0), overlapPrev(0), overlapThis(0)
        {
        }
    };

    // inline; the exe keeps out-of-line copies at 0x1426ae7d0 / 0x1426ae6b0 for the calls it does not inline
    unsigned addVertex(CoordType x, CoordType y, unsigned style, unsigned alpha = 1)
    {
        Vertices.PushBack(VertexType(x, y, style, alpha));
        return (unsigned)Vertices.GetSize() - 1;
    }
    void addTriangle(unsigned v1, unsigned v2, unsigned v3)
    {
        TriangleType tri;
        tri.v1 = v1;
        tri.v2 = v2;
        tri.v3 = v3;
        Triangles.PushBack(tri);
    }

    void calcWidths(WidthsType& w) const;
    void calcButtCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w, bool endFlag);
    void calcRoundCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w, bool endFlag);
    void calcCap(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w, bool endFlag);
    void calcRoundJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p);
    void calcBevelJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p, LineJoinType lineJoin);
    void calcMiterJoin(const StrokeVertex& v1, const WidthsType& w, const JoinParamType& p, LineJoinType lineJoin);
    static bool MitersIntersect(CoordType ax, CoordType ay, CoordType bx, CoordType by, CoordType cx, CoordType cy,
                                CoordType dx, CoordType dy, CoordType epsilon);
    void calcJoinParam(const StrokeVertex& v1, const StrokeVertex& v2, const StrokeVertex& v3, const WidthsType& w,
                       JoinParamType& p);
    void calcInitialJoinParam(const StrokeVertex& v1, const StrokeVertex& v2, const WidthsType& w, JoinParamType& p);
    void calcJoin(const StrokeVertex& v1, const StrokeVertex& v2, const StrokeVertex& v3, const WidthsType& w,
                  JoinParamType& p);
    void calcButtJoin(const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, const WidthsType& w);

    LineJoinType                    LineJoin;              // +0x08
    LineCapType                     StartLineCap;          // +0x0c
    LineCapType                     EndLineCap;            // +0x10
    CoordType                       MiterLimit;            // +0x14
    unsigned                        StyleLeft;             // +0x18
    unsigned                        StyleRight;            // +0x1c
    CoordType                       WidthLeft;             // +0x20 half solid widths
    CoordType                       WidthRight;            // +0x24
    CoordType                       AaWidthLeft;           // +0x28 AA fringe widths
    CoordType                       AaWidthRight;          // +0x2c
    CoordType                       Tolerance;             // +0x30
    CoordType                       IntersectionEpsilon;   // +0x34
    bool                            Closed;                // +0x38
    StrokePath                      Path;                  // +0x40
    ArrayPaged<VertexType, 4, 16>   Vertices;              // +0x68
    ArrayPaged<TriangleType, 4, 16> Triangles;             // +0x90
    unsigned                        SolidL;                // +0xb8 current edge vertices
    unsigned                        SolidR;                // +0xbc
    unsigned                        TotalL;                // +0xc0
    unsigned                        TotalR;                // +0xc4
    CoordType                       MinX;                  // +0xc8
    CoordType                       MinY;                  // +0xcc
    CoordType                       MaxX;                  // +0xd0
    CoordType                       MaxY;                  // +0xd4
};

inline void StrokerAA::AddVertex(CoordType x, CoordType y)
{
    Path.AddVertex(StrokeVertex(x, y));
}

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

    // (appended for sfr_render_04p: Renderer2DImpl's ctor) the tessellator works in the first two heaps, the
    // strokers in the third, the stroke sorter in the fourth
    MeshGenerator(MemoryHeap* heap)
        : Heap1(heap), Heap2(heap), Heap3(heap), Heap4(heap), mTess(&Heap1, &Heap2), mStroker(&Heap3),
          mStrokeSorter(&Heap4), mHairliner(&Heap3), mStrokerAA(&Heap3)
    {
    }

    // clears the tessellator and the strokers, then the heaps
    void Clear();        // 0x14262a890
};

}} // namespace Scaleform::Render

#endif
