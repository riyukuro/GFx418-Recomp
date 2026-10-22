// Recovered Scaleform 4.1.18 Render: GlyphFitter, hints a glyph outline (in nominal font units) to the pixel grid
// before it is rasterized: the outline is collected as integer contours, the rows where an edge turns (local min / max,
// flat shoulders) are marked as events, and a piecewise linear ramp maps every row (and column) so that the bottom
// edges, the x height and the cap height land on pixel boundaries.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctor 0x1426ebe90: NominalFontHeight +0x08, LinearHeap +0x10, Contours +0x38, Vertices
// +0x60, Events +0x88, LerpPairs +0xa0, LerpRampX / Y +0xc8 / +0xe0, the bounds +0xf8, Direction +0x100, the units
// per pixel +0x104, SnappedHeight +0x10c, the start / last points +0x110 (0x120 bytes).
#ifndef MS2_SF_RENDER_GLYPHFITTER_H
#define MS2_SF_RENDER_GLYPHFITTER_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessdefs.h"

namespace Scaleform { namespace Render {

class GlyphFitter : public TessBase
{
    // winding of the outermost contour; also the event bits (a bottom edge / a top edge)
    enum DirType
    {
        DirCW  = 1,
        DirCCW = 2
    };

    enum FitDir
    {
        FitX = 1,
        FitY = 2
    };

public:
    struct VertexType
    {
        SInt16 x, y;
    };

    struct ContourType
    {
        unsigned StartVertex;
        unsigned NumVertices;
    };

    GlyphFitter(MemoryHeap* heap, int nominalFontHeight = 1024);   // 0x1426ebe90

    void SetNominalFontHeight(int height) { NominalFontHeight = height; }

    virtual void      Clear();
    void              MoveTo(float x, float y);           // 0x1426ec3e0
    void              LineTo(float x, float y);           // 0x1426ec330
    virtual void      AddVertex(CoordType x, CoordType y) { LineTo(x, y); }
    virtual CoordType GetLastX() const { return LastXf; }
    virtual CoordType GetLastY() const { return LastYf; }
    virtual void      ClosePath();
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

    int  ComputeTopY() { computeBounds(); return MaxY; }
    void FitGlyph(int heightInPixels, int widthInPixels, int lowerCaseTop, int upperCaseTop);   // 0x1426ec090

    int                GetNominalFontHeight() const { return NominalFontHeight; }
    int                GetUnitsPerPixelX() const    { return UnitsPerPixelX; }
    int                GetUnitsPerPixelY() const    { return UnitsPerPixelY; }
    int                GetSnappedHeight() const     { return SnappedHeight; }
    UPInt              GetNumContours() const       { return Contours.GetSize(); }
    const ContourType& GetContour(unsigned i) const { return Contours[i]; }
    const VertexType&  GetVertex(const ContourType& c, unsigned i) const { return Vertices[c.StartVertex + i]; }

    // moves a vertex along the ramps (coordinates outside the glyph bounds stay)
    void SnapVertex(VertexType& v)
    {
        int i = v.y - MinY;
        if (i >= 0 && i < (int)LerpRampY.GetSize())
            v.y = LerpRampY[i] + MinY;
        i = v.x - MinX;
        if (i >= 0 && i < (int)LerpRampX.GetSize())
            v.x = LerpRampX[i] + MinX;
    }

private:
    void removeDuplicateClosures();                       // 0x1426ecec0
    void computeBounds();                                 // 0x1426ec630
    void detectEvents(FitDir dir);                        // 0x1426ecc20
    void computeLerpRamp(FitDir dir, int unitsPerPixel, int middle, int lowerCaseTop,
                         int upperCaseTop);               // 0x1426ec820
    int  snapToPixel(int x, int unitsPerPixel)
    {
        return (x + SnappedHeight) / unitsPerPixel * unitsPerPixel - SnappedHeight;
    }

    int                           NominalFontHeight;     // +0x08
    LinearHeap                    LHeap;                 // +0x10
    ArrayPaged<ContourType, 2, 4> Contours;              // +0x38
    ArrayPaged<VertexType, 4, 16> Vertices;              // +0x60
    ArrayUnsafe<UByte>            Events;                // +0x88
    ArrayPaged<VertexType, 4, 16> LerpPairs;             // +0xa0
    ArrayUnsafe<SInt16>           LerpRampX;             // +0xc8
    ArrayUnsafe<SInt16>           LerpRampY;             // +0xe0
    SInt16                        MinX, MinY;            // +0xf8
    SInt16                        MaxX, MaxY;
    DirType                       Direction;             // +0x100
    int                           UnitsPerPixelX;
    int                           UnitsPerPixelY;
    int                           SnappedHeight;
    float                         StartX, StartY;        // +0x110
    float                         LastXf, LastYf;
};

}} // namespace Scaleform::Render

#endif
