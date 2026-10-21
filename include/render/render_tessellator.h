// Recovered Scaleform 4.1.18 Render: the compound shape tessellator (Render_Tessellator, sfr_render_05c). Paths with
// a style on each side go in; a sweep over the y-sorted vertices cuts the shape into y-monotone polygons, which are
// triangulated into one mesh per style (or style pair, for complex fills). With edge anti-aliasing on (the default)
// every outline vertex gets an outer copy half a pixel away and the gap is filled with blended triangles; in stroker
// mode the outline is widened instead.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The exe is built with edge AA and the "mountain" triangulation. Layout from the ctor 0x142698b20 and Clear
// 0x142699100.
#ifndef MS2_SF_RENDER_TESSELLATOR_H
#define MS2_SF_RENDER_TESSELLATOR_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessdefs.h"
#include "ms2/scaleform/include/render/render_math2d.h"

namespace Scaleform { namespace Render {

class Tessellator : public TessBase
{
public:
    enum FillRuleType
    {
        FillNonZero,
        FillEvenOdd,
        FillStroker     // non-zero, and every non-empty style becomes style 1
    };

    struct SrcVertexType
    {
        CoordType x, y;
        SrcVertexType() {}
        SrcVertexType(CoordType x_, CoordType y_) : x(x_), y(y_) {}
    };

    // a vertex of a monotone polygon, chained bottom to top
    struct MonoVertexType
    {
        unsigned        srcVer;     // mesh vertex, LeftFlag for the left side
        unsigned        aaVer;      // its anti-aliased copy
        MonoVertexType* next;
    };

    // while triangulating with AA the corners are monotone vertices, afterwards mesh vertex indices
    struct TriangleType
    {
        union
        {
            struct { MonoVertexType *v1, *v2, *v3; } m;
            struct { unsigned v1, v2, v3; } t;
        } d;
    };

private:
    enum
    {
        EndChainFlag    = 0x02,
        VisibleChain    = 0x04,
        EventFlag       = 0x08,
        HasIntersection = 0x10
    };
    enum
    {
        InsertEdgesFlag = 1,
        RemoveEdgesFlag = 2
    };
    enum
    {
        ChainContinuesAtScanline = 1,
        ChainStartsAtScanline    = 2,
        ChainEndsAtScanline      = 3
    };
    enum
    {
        LeftFlag    = 0x80000000U,
        VisitedFlag = 0x40000000U
    };

    static bool     isLeft(unsigned v)      { return (v & LeftFlag) != 0; }
    static bool     isRight(unsigned v)     { return (v & LeftFlag) == 0; }
    static unsigned verIdx(unsigned v)      { return v & 0x0FFFFFFF; }
    static UInt16   styleIdx(unsigned v)    { return UInt16(v & 0x7FFF); }
    static unsigned styleIsLeft(unsigned v) { return v & 0x8000; }

    struct PathType
    {
        unsigned start;
        unsigned end;
        unsigned leftStyle;
        unsigned rightStyle;
    };

    struct EdgeType
    {
        unsigned  lower;    // source vertex at the bottom
        CoordType slope;    // dx / dy
    };

    // a y-monotone run of edges of one path
    struct MonoChainType
    {
        unsigned  edge;         // the current edge during the sweep
        unsigned  end;          // the last edge
        CoordType ySort;
        CoordType xb;           // x at the bottom / top of the current scan beam
        CoordType xt;
        SInt16    dir;          // +1 the path goes up, -1 down
        UInt16    flags;
        UInt16    leftStyle;
        UInt16    rightStyle;
        UInt16    leftBelow;    // the styles seen on each side under / over the scan line
        UInt16    leftAbove;
        UInt16    rightBelow;
        UInt16    rightAbove;
        unsigned  posIntr;      // slot in ActiveChains at the bottom of the beam, before the crossings
        unsigned  posScan;      // slot in the scan line being swept
    };

    struct IntersectionType
    {
        unsigned  pos1;
        unsigned  pos2;
        CoordType y;
    };

    // a scan line where chains end or start, waiting to be joined to a monotone
    struct BaseLineType
    {
        CoordType y;
        unsigned  styleLeft;
        unsigned  vertexLeft;
        unsigned  vertexRight;
        unsigned  firstChain;
        unsigned  numChains;
        unsigned  leftAbove;
    };

    struct MonotoneType
    {
        MonoVertexType* start;
        union
        {
            struct { unsigned lastIdx, prevIdx1, prevIdx2; } m;             // while building
            struct { unsigned startTriangle, numTriangles, meshIdx; } t;    // once triangulated
        } d;
        unsigned      style;
        BaseLineType* lowerBase;
    };

    struct ScanChainType
    {
        MonoChainType* chain;
        MonotoneType*  monotone;
        unsigned       vertex;
    };

    struct PendingEndType
    {
        unsigned      vertex;
        MonotoneType* monotone;
    };

    // one ray of the fan of edges around a vertex (edge AA)
    struct EdgeAAType
    {
        MonoVertexType* cntVer;
        MonoVertexType* rayVer;
        UInt16          style;
        UInt16          slope;  // rank of the direction in the fan
    };
    struct TmpEdgeAAType
    {
        MonoVertexType* cntVer;
        MonoVertexType* rayVer;
        CoordType       slope;
        unsigned        style;
    };
    struct InnerQuadType
    {
        EdgeAAType* e1;
        EdgeAAType* e2;
    };
    struct OuterEdgeType
    {
        EdgeAAType* edge;
        unsigned    outVer;
    };
    struct StrokerEdgeType
    {
        unsigned node1, node2;
    };
    struct StarVertexType
    {
        unsigned cntVer;
        unsigned starVer;
    };

public:
    Tessellator(LinearHeap* heap1, LinearHeap* heap2);

    void     SetFillRule(FillRuleType f);
    void     SetToleranceParam(const ToleranceParams& param);
    void     SetEdgeAAWidth(CoordType w);
    void     EnableInvasiveMerge(bool m)  { InvasiveMerge = m; }
    void     SetVertexLimit(unsigned lim) { VertexLimit = lim; }
    unsigned GetVertexLimit() const       { return VertexLimit; }

    virtual void      Clear();
    virtual CoordType GetLastX() const { return SrcVertices.Back().x; }
    virtual CoordType GetLastY() const { return SrcVertices.Back().y; }
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();
    virtual void      FinalizePath(unsigned leftStyle, unsigned rightStyle, bool leftComplex, bool rightComplex);

    void GetSrcBounds(CoordType* x1, CoordType* y1, CoordType* x2, CoordType* y2) const;
    void Tessellate(bool autoSplitMeshes = false);
    void SplitMeshes();

    virtual void     Transform(const Matrix2F& m);
    virtual Matrix2F StretchTo(float x1, float y1, float x2, float y2);
    virtual unsigned GetMeshCount() const                          { return (unsigned)Meshes.GetSize(); }
    virtual unsigned GetMeshVertexCount(unsigned meshIdx) const    { return Meshes[meshIdx].VertexCount; }
    virtual unsigned GetMeshTriangleCount(unsigned meshIdx) const  { return (unsigned)MeshTriangles.GetSize(meshIdx); }
    virtual void     GetMesh(unsigned meshIdx, TessMesh* mesh) const;
    virtual unsigned GetVertices(TessMesh* mesh, TessVertex* vertices, unsigned num) const;
    virtual void     GetTrianglesI16(unsigned meshIdx, UInt16* idx, unsigned start, unsigned num) const;

    void SortTrianglesByVertex1(unsigned meshIdx);

    virtual unsigned    GetVertexCount() const                    { return (unsigned)MeshVertices.GetSize(); }
    const TessVertex&   GetVertex(unsigned i) const               { return MeshVertices[i]; }
    const TriangleType& GetTriangle(unsigned i, unsigned j) const { return MeshTriangles.At(i, j); }
    TriangleType&       GetTriangle(unsigned i, unsigned j)       { return MeshTriangles.At(i, j); }
    unsigned             GetSrcVertexCount() const                { return (unsigned)SrcVertices.GetSize(); }
    const SrcVertexType& GetSrcVertex(unsigned i) const           { return SrcVertices[i]; }

private:
    typedef ArrayPaged<SrcVertexType, 4, 16>  SrcVertexArray;
    typedef ArrayPaged<TessVertex, 4, 16>     MeshVertexArray;
    typedef ArrayPaged<MonoChainType*, 4, 8>  ChainPtrArray;
    typedef ArrayPaged<ScanChainType, 4, 8>   ScanChainArray;
    typedef ArrayPaged<PendingEndType, 4, 4>  PendingEndArray;
    typedef ArrayPaged<MonoVertexType*, 4, 8> ChainVertexArray;
    typedef ArrayJagged<TriangleType, 4, 16>  TriangleArray;
    typedef ArrayUnsafe<EdgeAAType>           EdgeFanArray;

    // orders vertex indices by y
    struct CmpScanbeams
    {
        const SrcVertexArray& Ver;
        CmpScanbeams(const SrcVertexArray& v) : Ver(v) {}
        bool operator()(unsigned a, unsigned b) const { return Ver[a].y < Ver[b].y; }

    private:
        void operator=(CmpScanbeams&);
    };
    // orders triangles by their first vertex, y then x
    struct CmpVer1
    {
        const MeshVertexArray& Ver;
        CmpVer1(const MeshVertexArray& v) : Ver(v) {}
        bool operator()(const TriangleType& a, const TriangleType& b) const
        {
            const TessVertex& va = Ver[a.d.t.v1];
            const TessVertex& vb = Ver[b.d.t.v1];
            if (va.y != vb.y)
                return va.y < vb.y;
            return va.x < vb.x;
        }

    private:
        void operator=(CmpVer1&);
    };

    void clearHeap1();
    void monotonize();

    UInt32 isComplex(unsigned a, unsigned b) const;

    static bool cmpMonoChains(const MonoChainType* a, const MonoChainType* b);
    static bool cmpActiveChains(const MonoChainType* a, const MonoChainType* b);
    static bool cmpIntersectionY(const IntersectionType& a, const IntersectionType& b);

    bool forwardMin(int idx, int start) const;
    bool reverseMin(int idx, int end) const;
    bool forwardMax(int idx, int end) const;
    bool reverseMax(int idx, int start) const;

    void   buildEdgeList(unsigned start, unsigned numEdges, int step, unsigned leftStyle, unsigned rightStyle);
    void   decomposePath(const PathType& path);
    void   addStyle(unsigned style, bool complex);
    void   incStyles(const MonoChainType* mc);
    UInt16 findElderStyle() const;
    void   perceiveStyles(const ChainPtrArray& aet);

    CoordType calcX(const EdgeType* edge, CoordType y) const;
    unsigned  nextScanbeam(CoordType yb, CoordType yt, unsigned startMc, unsigned numMc);
    void      setupIntersections();

    unsigned addEventVertex(const SrcVertexType& v);
    unsigned addEventVertex(const MonoChainType* mc, CoordType yb, bool enforceFlag);
    void     addPendingEnd(ScanChainType* dst, ScanChainType* pending, CoordType y);

    unsigned lastMonoVertex(const MonotoneType* m) const;
    void     removeLastMonoVertex(MonotoneType* m);

    static void   resetMonotone(MonotoneType* m, unsigned style);
    MonotoneType* startMonotone(unsigned style);
    void          startMonotone(ScanChainType* chain, unsigned vertex);
    void          replaceMonotone(ScanChainType* chain, unsigned style);
    void          replaceMonotone(PendingEndType* pe, unsigned style);

    static int pendingMonotoneStyle(const PendingEndType* pe) { return pe->monotone ? pe->monotone->style : 0; }
    static int startingMonotoneStyle(const ScanChainType* chain) { return chain->chain->rightAbove; }

    void connectPendingToLeft(ScanChainType* chain, unsigned targetVertex);
    void connectPendingToRight(ScanChainType* chain, unsigned targetVertex);
    void connectStartingToPending(ScanChainType* chain, BaseLineType* upperBase);
    void connectStartingToLeft(ScanChainType* chain, BaseLineType* upperBase, unsigned targetVertex);
    void connectStartingToRight(ScanChainType* chain, BaseLineType* upperBase, unsigned targetVertex);
    void connectStarting(ScanChainType* chain, BaseLineType* upperBase);

    void growMonotone(MonotoneType* m, unsigned vertex);
    void growMonotone(MonotoneType* m, unsigned left, unsigned right);
    void growMonotone(ScanChainType* chain, unsigned vertex);

    unsigned nextChainInBundle(unsigned below, unsigned above, unsigned vertex) const;
    void     sweepScanbeam(const ChainPtrArray& aet, CoordType yb);
    void     swapChains(unsigned startIn, unsigned endIn);
    void     processInterior(CoordType yb, CoordType yTop, unsigned perceiveFlag);

    unsigned setMesh(unsigned style);
    unsigned setMesh(unsigned style1, unsigned style2);
    unsigned emitVertex(unsigned meshIdx, unsigned ver, unsigned style, unsigned flags);
    void     splitMesh(TessMesh* mesh);

    static bool cmpEdgeAA(const TmpEdgeAAType& a, const TmpEdgeAAType& b);
    static bool cmpOuterEdges(const OuterEdgeType& a, const OuterEdgeType& b);
    static bool cmpStrokerEdges(const StrokerEdgeType& a, const StrokerEdgeType& b);
    static bool cmpStrokerNode1(const StrokerEdgeType& e, unsigned node);

    void     collectFanEdges(const ChainVertexArray& chain, const ChainVertexArray& oppos, unsigned style);
    unsigned countFanEdges(MonotoneType* m);
    void     collectFanEdges(MonotoneType* m);
    bool     computeMiter(const TessVertex& v1, const TessVertex& v2, const TessVertex& v3, TessVertex* newVer1,
                          TessVertex* newVer2);
    void     processFan(unsigned start, unsigned end);
    unsigned emitVertex(unsigned meshIdx, unsigned ver, unsigned style1, unsigned style2, unsigned flags,
                        bool strictStyle = false);
    void     emitTriangles();

    unsigned addStrokerJoin(const StrokerEdgeType* e1, const StrokerEdgeType* e2);
    void     emitStrokerVertex(CoordType x, CoordType y);
    void     emitStrokerTrapezoid(const StrokerEdgeType* edge, unsigned v1, unsigned v2);
    void     addStrokerEdge(unsigned v1, unsigned v2);
    void     processStrokerEdges();
    void     processEdgeAA();

    void      moveVertexAA(const TessVertex& refVer, TessVertex* aaVer, const TessVertex& v2, const TessVertex& v3);
    void      addTriangleAA(MonoVertexType* v1, MonoVertexType* v2, MonoVertexType* v3, CoordType cp);
    CoordType triangleRatio(MonoVertexType* v1, MonoVertexType* v2, MonoVertexType* v3) const;
    void      triangulateMountainAA();
    void      triangulateMonotoneAA(MonotoneType* m);
    void      unflipTriangles();

    LinearHeap*                         pHeap1;         // sweep data, dropped after Tessellate
    LinearHeap*                         pHeap2;         // the results
    FillRuleType                        FillRule;
    CoordType                           Epsilon;
    bool                                HasEpsilon;
    bool                                StrokerMode;
    bool                                InvasiveMerge;
    bool                                HasComplexFill;
    unsigned                            VertexLimit;
    ArrayUnsafe<UInt32>                 ComplexFlags;   // one bit per style
    unsigned                            MaxStyle;
    ArrayPaged<PathType, 4, 4>          Paths;
    SrcVertexArray                      SrcVertices;
    unsigned                            LastVertex;
    ArrayPaged<EdgeType, 4, 16>         Edges;
    ArrayPaged<MonoChainType, 4, 16>    MonoChains;
    ArrayUnsafe<MonoChainType*>         MonoChainsSorted;
    ArrayPaged<unsigned, 4, 16>         Scanbeams;
    ChainPtrArray                       ActiveChains;
    ChainPtrArray                       InteriorChains;
    ArrayPaged<unsigned, 4, 16>         ValidChains;
    ArrayPaged<unsigned, 4, 16>         InteriorOrder;
    ArrayPaged<IntersectionType, 4, 4>  Intersections;
    ArrayUnsafe<int>                    StyleCounts;
    CoordType                           LastX;
    CoordType                           MinX;
    CoordType                           MinY;
    CoordType                           MaxX;
    CoordType                           MaxY;
    ScanChainArray                      ChainsBelow;
    ScanChainArray                      ChainsAbove;
    ArrayPaged<BaseLineType, 4, 4>      BaseLines;
    PendingEndArray                     PendingEnds;
    ArrayPaged<MonotoneType, 4, 16>     Monotones;
    ArrayPaged<MonoVertexType, 4, 16>   MonoVertices;
    MeshVertexArray                     MeshVertices;
    ArrayMatrix<UInt16>                 StyleMatrix;    // style pair -> mesh, 0xFFFF unset
    ArrayPaged<TessMesh, 4, 4>          Meshes;
    TriangleArray                       MeshTriangles;
    unsigned                            MonoStyle;
    unsigned                            MeshIdx;
    unsigned                            FactorOneFlag;
    CoordType                           EdgeAAWidth;
    bool                                EdgeAAFlag;
    CoordType                           IntersectionEpsilon;
    ChainVertexArray                    LeftChain;
    ChainVertexArray                    RightChain;
    ArrayPaged<TmpEdgeAAType, 3, 4>     TmpEdgeFan;
    EdgeFanArray                        EdgeFans;
    ArrayPaged<unsigned, 3, 4>          StartFan;
    ArrayPaged<unsigned, 3, 4>          EndFan;
    ArrayPaged<OuterEdgeType, 4, 16>    OuterEdges;
    ArrayPaged<StrokerEdgeType, 4, 16>  StrokerEdges;
    ArrayPaged<MonoVertexType*, 4, 2>   MonoStack;
    ArrayPaged<InnerQuadType, 4, 16>    InnerQuads;
    ArrayPaged<StarVertexType, 4, 16>   StarVertices;
    int                                 FakeVar;
};

}} // namespace Scaleform::Render

#endif
