// Recovered Scaleform 4.1.18 Render: Rasterizer, the anti-aliased scanline rasterizer of the glyph cache (an AGG
// style cell rasterizer: every line adds cover / area to the 1/256 pixel cells it crosses; the cells are then sorted
// by row and column and swept into 8-bit coverage with a gamma table).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctor 0x1426d8050: LinearHeap +0x08, FillRule +0x30, the gammas +0x34 / +0x38, the two
// gamma tables +0x3c, Cells +0x240, SortedCells +0x268, SortedYs +0x280, CurrCell +0x298, bounds +0x2a8, the
// start / last points +0x2b8 (0x2d0 bytes).
#ifndef MS2_SF_RENDER_RASTERIZER_H
#define MS2_SF_RENDER_RASTERIZER_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessdefs.h"

namespace Scaleform { namespace Render {

class Rasterizer : public TessBase
{
public:
    enum
    {
        SubpixelShift   = 8,
        SubpixelScale   = 1 << SubpixelShift,
        SubpixelMask    = SubpixelScale - 1,
        AntiAliasShift  = 8,
        AntiAliasScale  = 1 << AntiAliasShift,
        AntiAliasMask   = AntiAliasScale - 1,
        AntiAliasScale2 = AntiAliasScale * 2,
        AntiAliasMask2  = AntiAliasScale2 - 1
    };

    enum FillRuleType
    {
        FillNonZero,
        FillEvenOdd
    };

    Rasterizer(MemoryHeap* heap);                         // 0x1426d8050

    void         SetFillRule(FillRuleType rule) { FillRule = rule; }
    FillRuleType GetFillRule() const            { return FillRule; }
    void         SetGamma1(float g);                      // 0x1426d8590
    float        GetGamma1() const              { return Gamma1; }
    void         SetGamma2(float g);                      // 0x1426d85c0
    float        GetGamma2() const              { return Gamma2; }

    virtual void      Clear();                            // 0x1426d8230
    void              MoveTo(float x, float y);           // 0x1426d8460
    void              LineTo(float x, float y);           // 0x1426d83f0
    virtual void      AddVertex(CoordType x, CoordType y) { LineTo(x, y); }
    virtual CoordType GetLastX() const { return LastXf; }
    virtual CoordType GetLastY() const { return LastYf; }
    virtual void      ClosePath();                        // 0x1426d82f0
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

    int   GetMinX() const         { return MinX; }
    int   GetMinY() const         { return MinY; }
    int   GetMaxX() const         { return MaxX; }
    int   GetMaxY() const         { return MaxY; }
    UPInt GetNumScanlines() const { return SortedYs.GetSize(); }

    // false when nothing was drawn
    bool SortCells();                                     // 0x1426d85f0
    void SweepScanline(unsigned scanline, unsigned char* raster, unsigned numChannels = 1,
                       int gammaIdx = 0) const;           // 0x1426d8910
    void SweepScanlineThreshold(unsigned scanline, unsigned char* raster, unsigned numChannels = 1,
                                unsigned threshold = AntiAliasMask / 2) const;   // 0x1426d8ad0

    // one touched pixel: its position, the summed cover and the doubled area left of the edges inside it
    struct Cell
    {
        int x, y, Cover, Area;
    };
    // the cells of one row: their first index in SortedCells and how many
    struct SortedY
    {
        unsigned Start, Count;
    };

private:
    void setGamma(int idx, float g);                      // 0x1426d9460
    void line(int x1, int y1, int x2, int y2);            // 0x1426d8f90
    void horLine(int ey, int x1, int y1, int x2, int y2); // 0x1426d8c80

    // moving to another pixel stores the current cell if it got anything
    SF_INLINE void setCurrCell(int x, int y)
    {
        if ((CurrCell.x - x) | (CurrCell.y - y))
        {
            if (CurrCell.Area | CurrCell.Cover)
                Cells.PushBack(CurrCell);
            CurrCell.x     = x;
            CurrCell.y     = y;
            CurrCell.Cover = 0;
            CurrCell.Area  = 0;
        }
    }

    SF_INLINE static bool cellXLess(const Cell* a, const Cell* b) { return a->x < b->x; }

    // area (in subpixel units) to coverage: even-odd folds every second winding back; then through the gamma table
    SF_INLINE unsigned calcAlpha(int area, int gammaIdx) const
    {
        int cov = area >> (SubpixelShift * 2 + 1 - AntiAliasShift);
        if (cov < 0)
            cov = -cov;
        if (FillRule == FillEvenOdd)
        {
            cov &= AntiAliasMask2;
            if (cov > AntiAliasScale)
                cov = AntiAliasScale2 - cov;
        }
        if (cov > AntiAliasMask)
            cov = AntiAliasMask;
        return GammaLut[gammaIdx][cov];
    }
    // the same coverage, cut at threshold to fully off / fully on
    SF_INLINE unsigned calcAlpha(int area, unsigned threshold) const
    {
        int cov = area >> (SubpixelShift * 2 + 1 - AntiAliasShift);
        if (cov < 0)
            cov = -cov;
        if (FillRule == FillEvenOdd)
        {
            cov &= AntiAliasMask2;
            if (cov > AntiAliasScale)
                cov = AntiAliasScale2 - cov;
        }
        return (cov <= int(threshold)) ? 0 : AntiAliasMask;
    }

    LinearHeap               LHeap;            // +0x08
    FillRuleType             FillRule;         // +0x30
    float                    Gamma1;           // +0x34
    float                    Gamma2;           // +0x38
    UByte                    GammaLut[2][256]; // +0x3c
    ArrayPaged<Cell, 4, 16>  Cells;            // +0x240
    ArrayUnsafe<Cell*>       SortedCells;      // +0x268
    ArrayUnsafe<SortedY>     SortedYs;         // +0x280
    Cell                     CurrCell;         // +0x298
    int                      MinX, MinY;       // +0x2a8
    int                      MaxX, MaxY;
    int                      StartX, StartY;   // +0x2b8
    int                      LastX, LastY;
    float                    LastXf, LastYf;
};

}} // namespace Scaleform::Render

#endif
