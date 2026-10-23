// Recovered Scaleform 4.1.18 Render: the stroker (Render_Stroker, sfr_render_05b). Stroker turns a polyline into the
// outline of a stroke of a given width (joins, caps); StrokeSorter collects stroke paths, chains the ones that meet
// end to start and can dash them (DashGenerator).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts from the ctors 0x1426a98e0 (Stroker, vftable 0x1431923f0) and 0x1426a9840 (StrokeSorter, vftable
// 0x143192470, 0xd0 bytes); both vftables follow the TessBase slot order.
#ifndef MS2_SF_RENDER_STROKER_H
#define MS2_SF_RENDER_STROKER_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessdefs.h"
#include "ms2/scaleform/include/render/render_math2d.h"

namespace Scaleform { namespace Render {

struct DashArray;

// a polyline vertex; dist is the length of the segment to the next vertex
struct StrokeVertex
{
    CoordType x;
    CoordType y;
    CoordType dist;

    StrokeVertex() {}
    StrokeVertex(CoordType x_, CoordType y_) : x(x_), y(y_), dist(0) {}

    // stores the distance to v, false when the two coincide
    bool Distance(const StrokeVertex& v)
    {
        dist = Math2D::Distance(*this, v);
        return dist > 0;
    }
};

// the polyline being stroked; coinciding consecutive vertices are dropped as they come in
class StrokePath
{
public:
    typedef ArrayPaged<StrokeVertex, 4, 16> ContainerType;

    StrokePath(LinearHeap* heap) : Path(heap) {}

    void      Clear();             // 0x1426aa240 (out of line, as the stroker TUs call it)
    void      ClearAndRelease();   // 0x1426aa2f0
    CoordType GetLastX() const  { return Path.Back().x; }
    CoordType GetLastY() const  { return Path.Back().y; }
    void      AddVertex(const StrokeVertex& v);
    bool      ClosePath();

    UPInt GetVertexCount() const { return Path.GetSize(); }

    // neighbours with wrap-around (closed paths)
    const StrokeVertex& GetVertexPrev(UPInt i) const
    {
        if (i == 0)
            i += Path.GetSize();
        return Path[i - 1];
    }
    const StrokeVertex& GetVertex(UPInt i) const { return Path[i]; }
    StrokeVertex&       GetVertex(UPInt i)       { return Path[i]; }
    const StrokeVertex& GetVertexNext(UPInt i) const
    {
        if (++i >= Path.GetSize())
            i -= Path.GetSize();
        return Path[i];
    }

private:
    StrokePath(const StrokePath&);
    void operator=(StrokePath&);

    ContainerType Path;
};

class StrokerTypes
{
public:
    enum LineCapType
    {
        ButtCap,
        SquareCap,
        RoundCap
    };
    enum LineJoinType
    {
        MiterJoin,          // over the miter limit: cut the miter at the limit
        MiterBevelJoin,     // over the miter limit: bevel
        RoundJoin,
        BevelJoin
    };
    enum EquidistantDir
    {
        DirForward,
        DirBackward
    };
};

class Stroker : public StrokerTypes, public TessBase
{
public:
    Stroker(LinearHeap* heap);

    void SetToleranceParam(const ToleranceParams& param);
    void SetWidth(CoordType w)           { Width = w / 2; }
    void SetLineJoin(LineJoinType j)     { LineJoin = j; }
    void SetLineCap(LineCapType c)       { StartLineCap = EndLineCap = c; }
    void SetStartLineCap(LineCapType c)  { StartLineCap = c; }
    void SetEndLineCap(LineCapType c)    { EndLineCap = c; }
    void SetMiterLimit(CoordType v)      { MiterLimit = v; }

    virtual void      Clear()
    {
        Path.ClearAndRelease();
        Closed = false;
        pHeap->ClearAndRelease();
    }
    virtual CoordType GetLastX() const { return Path.GetLastX(); }
    virtual CoordType GetLastY() const { return Path.GetLastY(); }
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      ClosePath();

    // emits the outline of the collected path into tess and empties the path
    void GenerateStroke(TessBase* tess);

    // the stroker is only a source, the sink slots do nothing
    virtual void      FinalizePath(unsigned, unsigned, bool, bool) {}
    virtual void      Transform(const Matrix2F&) {}
    virtual Matrix2F  StretchTo(float, float, float, float) { return Matrix2F(); }
    virtual unsigned  GetVertexCount() const { return 0; }
    virtual unsigned  GetMeshCount() const { return 0; }
    virtual unsigned  GetMeshVertexCount(unsigned) const { return 0; }
    virtual unsigned  GetMeshTriangleCount(unsigned) const { return 0; }
    virtual void      GetMesh(unsigned, TessMesh*) const {}
    virtual unsigned  GetVertices(TessMesh*, TessVertex*, unsigned) const { return 0; }
    virtual void      GetTrianglesI16(unsigned, UInt16*, unsigned, unsigned) const {}

    // one side of the stroke of a closed path only
    void CalcEquidistant(TessBase* tess, EquidistantDir dir);

private:
    Stroker(const Stroker&);
    void operator=(Stroker&);

    void calcArc(TessBase* tess, CoordType x, CoordType y, CoordType dx1, CoordType dy1, CoordType dx2,
                 CoordType dy2);
    void calcMiter(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, const StrokeVertex& v2,
                   CoordType dx1, CoordType dy1, CoordType dx2, CoordType dy2, LineJoinType lineJoin,
                   CoordType miterLimit, CoordType epsilon, CoordType dbevel);
    void calcCap(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, CoordType len, LineCapType cap);
    void calcJoin(TessBase* tess, const StrokeVertex& v0, const StrokeVertex& v1, const StrokeVertex& v2,
                  CoordType len1, CoordType len2);

    LinearHeap*  pHeap;                 // +0x08
    StrokePath   Path;                  // +0x10
    CoordType    Width;                 // +0x38 half the stroke width
    LineJoinType LineJoin;              // +0x3c
    LineCapType  StartLineCap;          // +0x40
    LineCapType  EndLineCap;            // +0x44
    CoordType    MiterLimit;            // +0x48
    CoordType    CurveTolerance;        // +0x4c
    CoordType    IntersectionEpsilon;   // +0x50
    bool         Closed;                // +0x54
};

class StrokeSorter : public TessBase
{
    enum
    {
        NumVerMask  = 0x0FFFFFFF,
        VisitedFlag = 0x40000000,
        ClosedFlag  = 0x20000000
    };
    // numVer carries the flags above in its high bits
    struct PathType
    {
        unsigned start;
        unsigned numVer;
    };
    // a path keyed by its first vertex
    struct SortedPathType
    {
        CoordType x, y;
        PathType* thisPath;
    };

public:
    struct VertexType
    {
        CoordType x, y;
        CoordType Dist;
        UInt8     segType;  // Math2D::SegmentType
        bool      snapX;
        bool      snapY;
    };
    typedef ArrayPaged<VertexType, 4, 16> VertexArrayType;
    typedef ArrayPaged<PathType, 4, 16>   PathArrayType;

    StrokeSorter(LinearHeap* heap);

    virtual void      Clear()
    {
        SrcVertices.ClearAndRelease();
        SrcPaths.ClearAndRelease();
        SortedPaths.ClearAndRelease();
        OutVertices.ClearAndRelease();
        OutPaths.ClearAndRelease();
        LastVertex = 0;
        pHeap->ClearAndRelease();
    }
    virtual CoordType GetLastX() const { return SrcVertices.Back().x; }
    virtual CoordType GetLastY() const { return SrcVertices.Back().y; }
    virtual void      AddVertex(CoordType x, CoordType y);
    virtual void      FinalizePath(unsigned closeFlag, unsigned, bool, bool);

    virtual void      ClosePath() {}
    virtual void      Transform(const Matrix2F&) {}
    virtual Matrix2F  StretchTo(float, float, float, float) { return Matrix2F(); }
    virtual unsigned  GetVertexCount() const { return 0; }
    virtual unsigned  GetMeshCount() const { return 0; }
    virtual unsigned  GetMeshVertexCount(unsigned) const { return 0; }
    virtual unsigned  GetMeshTriangleCount(unsigned) const { return 0; }
    virtual void      GetMesh(unsigned, TessMesh*) const {}
    virtual unsigned  GetVertices(TessMesh*, TessVertex*, unsigned) const { return 0; }
    virtual void      GetTrianglesI16(unsigned, UInt16*, unsigned, unsigned) const {}

    void AddVertexNV(CoordType x, CoordType y, unsigned segType = Math2D::Seg_LineTo);
    void AddQuad(CoordType x2, CoordType y2, CoordType x3, CoordType y3);
    void AddCubic(CoordType x2, CoordType y2, CoordType x3, CoordType y3, CoordType x4, CoordType y4);

    void Sort();
    void AddOffset(CoordType offsetX, CoordType offsetY);
    void Transform(const TransformerBase* tr);
    void Snap(CoordType offsetX, CoordType offsetY);
    void GenerateDashes(const DashArray* da, const ToleranceParams& param, float scale);

    // the sorted output paths
    unsigned GetPathCount() const               { return (unsigned)OutPaths.GetSize(); }
    bool     IsClosed(unsigned pathIdx) const       { return (OutPaths[pathIdx].numVer & ClosedFlag) != 0; }
    unsigned GetVertexCount(unsigned pathIdx) const { return OutPaths[pathIdx].numVer & NumVerMask; }
    // verIdx may run one lap past the end (closed paths)
    const VertexType& GetVertex(unsigned pathIdx, unsigned verIdx) const
    {
        const PathType& p = OutPaths[pathIdx];
        unsigned        n = p.numVer & NumVerMask;
        return OutVertices[p.start + ((verIdx < n) ? verIdx : verIdx - n)];
    }

private:
    static bool cmpPaths(const SortedPathType& a, const SortedPathType& b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
    void     appendPath(PathType* dst, PathType* src);
    unsigned findNext(const PathType& outPath) const;

    LinearHeap*                 pHeap;          // +0x08
    VertexArrayType             SrcVertices;    // +0x10
    PathArrayType               SrcPaths;       // +0x38
    ArrayUnsafe<SortedPathType> SortedPaths;    // +0x60
    VertexArrayType             OutVertices;    // +0x78
    PathArrayType               OutPaths;       // +0xa0
    unsigned                    LastVertex;     // +0xc8
};

// walks a polyline and returns the dash pieces of it as MoveTo / LineTo commands
class DashGenerator
{
    enum DashStatus
    {
        Status_Ready,
        Status_Polyline,
        Status_Stop
    };

public:
    DashGenerator(const float* dashArray, unsigned dashCount, float dashStart, StrokeSorter::VertexType* ver,
                  unsigned verCount, bool closed);

    // the next command (Math2D::SegmentType), Seg_EndPath at the end
    unsigned GetVertex(float* x, float* y);

private:
    DashGenerator(const DashGenerator&);
    const DashGenerator& operator=(const DashGenerator&);

    const float*                    pDashArray;
    unsigned                        DashCount;
    float                           DashStart;
    unsigned                        CurrDash;
    float                           CurrRest;
    float                           CurrDashStart;
    StrokeSorter::VertexType*       Vertices;
    unsigned                        VerCount;
    const StrokeSorter::VertexType* Ver1;
    const StrokeSorter::VertexType* Ver2;
    bool                            Closed;
    DashStatus                      Status;
    unsigned                        SrcVertex;
};

}} // namespace Scaleform::Render

#endif
