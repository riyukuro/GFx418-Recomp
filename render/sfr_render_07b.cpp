// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the rect packer
// (Render_RectPacker) and the anti-aliased scanline rasterizer (Render_Rasterizer) the glyph cache uses to draw
// glyph shapes into its textures.
// Queue unit sfr_render_07 is split along its original sources (07b Render_RectPacker + Render_Rasterizer).
// MS2-UNIT: sfr_render_07b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d6f60-0x1426d9510 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?allocatePage@?$ArrayPagedBase@UPackType@RectPacker@Render@Scaleform@@$03$0BA@U?$AllocatorPagedLH_POD@UPackType@RectPacker@Render@Scaleform@@$01@4@@Scaleform@@AEAAX_K@Z 0x1426d7840 ; unique
// MS2-PIN: ??$QuickSortSliced@V?$ArrayAdaptor@PEAUCell@Rasterizer@Render@Scaleform@@@Alg@Scaleform@@P6A_NPEBUCell@Rasterizer@Render@3@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayAdaptor@PEAUCell@Rasterizer@Render@Scaleform@@@01@_K1P6A_NPEBUCell@Rasterizer@Render@1@2@Z@Z 0x1426d7dd0 ; unique
// MS2-PIN: ??_GRasterizer@Render@Scaleform@@UEAAPEAXI@Z 0x1426d8170 ; unique
// MS2-PIN: ?AddVertex@Rasterizer@Render@Scaleform@@UEAAXMM@Z 0x1426d81c0 ; unique
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_rectpacker.h"
#include "ms2/scaleform/include/render/render_rasterizer.h"
#include "ms2/scaleform/kernel/sf_alg.h"

#include <math.h>
#include <string.h>

namespace Scaleform { namespace Render {

// ---------------------------------------------------------------------------------------------------------------
// RectPacker

// @0x1426d7460
RectPacker::RectPacker() : Width(1024), Height(1024)
{
}

// Pages are filled one after another until every source rect is placed; a page that places nothing new would
// loop forever, so it is not emitted (AddRect keeps such rects out).
// @0x1426d7540
void RectPacker::Pack()
{
    PackedRects.Clear();
    Packs.Clear();
    PackTree.Clear();
    if (SrcRects.GetSize() == 0)
        return;

    Alg::QuickSort(SrcRects, cmpRects);
    // the last rect is the smallest: free areas below its size are not worth a look
    MinWidth  = SrcRects[SrcRects.GetSize() - 1].x;
    MinHeight = SrcRects[SrcRects.GetSize() - 1].y;
    NumPacked = 0;

    do
    {
        unsigned packedBefore = NumPacked;
        PackTree.Clear();

        NodeType page;
        page.x      = 0;
        page.y      = 0;
        page.Width  = Width;
        page.Height = Height;
        page.Id     = ~0U;
        page.Node1  = ~0U;
        page.Node2  = ~0U;
        PackTree.PushBack(page);
        packRects(0, 0);

        if (NumPacked > packedBefore)
        {
            PackType pack;
            pack.StartRect = (unsigned)PackedRects.GetSize();
            emitPacked();
            pack.NumRects = (unsigned)PackedRects.GetSize() - pack.StartRect;
            Packs.PushBack(pack);
        }
    } while (NumPacked < SrcRects.GetSize());
}

// Places the first unplaced rect from start on that fits the free area, then recurses into the two areas left.
// @0x1426d79c0
void RectPacker::packRects(unsigned nodeIdx, unsigned start)
{
    const NodeType& node = PackTree[nodeIdx];
    if (node.Width < MinWidth || node.Height < MinHeight)
        return;

    for (UPInt i = start; i < SrcRects.GetSize(); ++i)
    {
        RectType& rect = SrcRects[i];
        if ((rect.Id & Packed) == 0 && rect.x <= node.Width && rect.y <= node.Height)
        {
            splitSpace(nodeIdx, rect);
            rect.Id |= Packed;
            ++NumPacked;
            packRects(node.Node1, (unsigned)i);
            packRects(node.Node2, (unsigned)i);
            return;
        }
    }
}

// The node becomes the placed rect; its children are the strip to the right of it (as tall as the rect) and the
// whole width below it.
// @0x1426d7c30
void RectPacker::splitSpace(unsigned nodeIdx, const RectType& rect)
{
    NodeType& node  = PackTree[nodeIdx];
    NodeType  right = node;
    NodeType  below = node;

    right.x      += rect.x;
    right.Height  = rect.y;
    right.Width  -= rect.x;
    below.y      += rect.y;
    below.Height -= rect.y;
    PackTree.PushBack(right);
    PackTree.PushBack(below);

    node.Width  = rect.x;
    node.Height = rect.y;
    node.Id     = rect.Id;
    node.Node1  = (unsigned)PackTree.GetSize() - 2;
    node.Node2  = (unsigned)PackTree.GetSize() - 1;
}

// @0x1426d78f0
void RectPacker::emitPacked()
{
    RectType rect;
    for (UPInt i = 0; i < PackTree.GetSize(); ++i)
    {
        const NodeType& node = PackTree[i];
        if (node.Id != ~0U)
        {
            rect.x  = node.x;
            rect.y  = node.y;
            rect.Id = node.Id;
            PackedRects.PushBack(rect);
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Rasterizer

// @0x1426d8050
Rasterizer::Rasterizer(MemoryHeap* heap)
    : LHeap(heap),
      FillRule(FillNonZero),
      Gamma1(1.0f),
      Gamma2(1.0f),
      Cells(&LHeap),
      SortedCells(&LHeap),
      SortedYs(&LHeap),
      CurrCell(),
      MinX(0x7FFFFFFF),
      MinY(0x7FFFFFFF),
      MaxX(-0x7FFFFFFF),
      MaxY(-0x7FFFFFFF),
      StartX(0),
      StartY(0),
      LastX(0),
      LastY(0),
      LastXf(0),
      LastYf(0)
{
    CurrCell.x     = 0x7FFFFFFF;
    CurrCell.y     = 0x7FFFFFFF;
    CurrCell.Cover = 0;
    CurrCell.Area  = 0;
    SetGamma1(1.0f);
    SetGamma2(1.0f);
}

// @0x1426d8230
void Rasterizer::Clear()
{
    Cells.ClearAndRelease();
    SortedCells.ClearAndRelease();
    SortedYs.ClearAndRelease();
    LHeap.ClearAndRelease();
    CurrCell.x     = 0x7FFFFFFF;
    CurrCell.y     = 0x7FFFFFFF;
    CurrCell.Cover = 0;
    CurrCell.Area  = 0;
    MinX   = 0x7FFFFFFF;
    MinY   = 0x7FFFFFFF;
    MaxX   = -0x7FFFFFFF;
    MaxY   = -0x7FFFFFFF;
    StartX = 0;
    StartY = 0;
    LastX  = 0;
    LastY  = 0;
    LastXf = 0;
    LastYf = 0;
}

// coverage i/255 raised to g, rounded back to a byte
// @0x1426d9460
void Rasterizer::setGamma(int idx, float g)
{
    for (int i = 0; i < AntiAliasScale; i++)
        GammaLut[idx][i] = UByte(pow(float(i) / AntiAliasMask, g) * AntiAliasMask + float(0.5));
}

// @0x1426d8590
void Rasterizer::SetGamma1(float g)
{
    setGamma(0, g);
    Gamma1 = g;
}

// @0x1426d85c0
void Rasterizer::SetGamma2(float g)
{
    setGamma(1, g);
    Gamma2 = g;
}

// @0x1426d8460
void Rasterizer::MoveTo(float x, float y)
{
    LastXf = x;
    LastYf = y;
    StartX = LastX = int(x * SubpixelScale);
    StartY = LastY = int(y * SubpixelScale);
}

// @0x1426d83f0
void Rasterizer::LineTo(float x, float y)
{
    LastXf = x;
    LastYf = y;
    int xi = int(x * SubpixelScale);
    int yi = int(y * SubpixelScale);
    line(LastX, LastY, xi, yi);
    LastX = xi;
    LastY = yi;
}

// @0x1426d82f0
void Rasterizer::ClosePath()
{
    if (LastX != StartX || LastY != StartY)
    {
        line(LastX, LastY, StartX, StartY);
        LastX = StartX;
        LastY = StartY;
    }
}

// The part of a line inside one pixel row ey: x1 / x2 in subpixels, y1 / y2 the subpixel heights inside the row.
// Each crossed cell gets the height the line spends in it (cover) and twice the area left of it.
// @0x1426d8c80
void Rasterizer::horLine(int ey, int x1, int y1, int x2, int y2)
{
    int ex1 = x1 >> SubpixelShift;
    int ex2 = x2 >> SubpixelShift;
    int fx1 = x1 & SubpixelMask;
    int fx2 = x2 & SubpixelMask;

    int delta, p, first, dx;
    int incr, lift, mod, rem;

    // horizontal: no cover, only the cell moves
    if (y1 == y2)
    {
        setCurrCell(ex2, ey);
        return;
    }

    // both ends in one cell
    if (ex1 == ex2)
    {
        delta = y2 - y1;
        CurrCell.Cover += delta;
        CurrCell.Area  += (fx1 + fx2) * delta;
        return;
    }

    // a run of cells: the height is shared out by x, with the remainder carried Bresenham style
    p     = (SubpixelScale - fx1) * (y2 - y1);
    first = SubpixelScale;
    incr  = 1;
    dx    = x2 - x1;
    if (dx < 0)
    {
        p     = fx1 * (y2 - y1);
        first = 0;
        incr  = -1;
        dx    = -dx;
    }

    delta = p / dx;
    mod   = p % dx;
    if (mod < 0)
    {
        delta--;
        mod += dx;
    }

    CurrCell.Cover += delta;
    CurrCell.Area  += (fx1 + first) * delta;

    ex1 += incr;
    setCurrCell(ex1, ey);
    y1 += delta;

    if (ex1 != ex2)
    {
        p    = SubpixelScale * (y2 - y1 + delta);
        lift = p / dx;
        rem  = p % dx;
        if (rem < 0)
        {
            lift--;
            rem += dx;
        }
        mod -= dx;

        while (ex1 != ex2)
        {
            delta = lift;
            mod  += rem;
            if (mod >= 0)
            {
                mod -= dx;
                delta++;
            }

            CurrCell.Cover += delta;
            CurrCell.Area  += SubpixelScale * delta;
            y1  += delta;
            ex1 += incr;
            setCurrCell(ex1, ey);
        }
    }

    delta = y2 - y1;
    CurrCell.Cover += delta;
    CurrCell.Area  += (fx2 + SubpixelScale - first) * delta;
}

// A line in subpixels: it grows the bounds and is cut into one horLine per pixel row it crosses.
// @0x1426d8f90
void Rasterizer::line(int x1, int y1, int x2, int y2)
{
    int dx  = x2 - x1;
    int dy  = y2 - y1;
    int ex1 = x1 >> SubpixelShift;
    int ey1 = y1 >> SubpixelShift;
    int ex2 = x2 >> SubpixelShift;
    int ey2 = y2 >> SubpixelShift;
    int fy1 = y1 & SubpixelMask;
    int fy2 = y2 & SubpixelMask;

    int xFrom, xTo;
    int p, rem, mod, lift, delta, first, incr;

    if (ex1 < MinX) MinX = ex1;
    if (ex1 > MaxX) MaxX = ex1;
    if (ey1 < MinY) MinY = ey1;
    if (ey1 > MaxY) MaxY = ey1;
    if (ex2 < MinX) MinX = ex2;
    if (ex2 > MaxX) MaxX = ex2;
    if (ey2 < MinY) MinY = ey2;
    if (ey2 > MaxY) MaxY = ey2;

    setCurrCell(ex1, ey1);

    // inside one row
    if (ey1 == ey2)
    {
        horLine(ey1, x1, fy1, x2, fy2);
        return;
    }

    incr = 1;

    // vertical: one cell per row, the middle rows all get the full cover
    if (dx == 0)
    {
        int ex    = x1 >> SubpixelShift;
        int twoFx = (x1 - (ex << SubpixelShift)) << 1;
        int area;

        first = SubpixelScale;
        if (dy < 0)
        {
            first = 0;
            incr  = -1;
        }

        delta = first - fy1;
        CurrCell.Cover += delta;
        CurrCell.Area  += twoFx * delta;

        ey1 += incr;
        setCurrCell(ex, ey1);

        delta = first + first - SubpixelScale;
        area  = twoFx * delta;
        while (ey1 != ey2)
        {
            CurrCell.Cover = delta;
            CurrCell.Area  = area;
            ey1 += incr;
            setCurrCell(ex, ey1);
        }

        delta = fy2 - SubpixelScale + first;
        CurrCell.Cover += delta;
        CurrCell.Area  += twoFx * delta;
        return;
    }

    // several rows: the x where the line leaves each row, stepped with a carried remainder
    p     = (SubpixelScale - fy1) * dx;
    first = SubpixelScale;
    if (dy < 0)
    {
        p     = fy1 * dx;
        first = 0;
        incr  = -1;
        dy    = -dy;
    }

    delta = p / dy;
    mod   = p % dy;
    if (mod < 0)
    {
        delta--;
        mod += dy;
    }

    xFrom = x1 + delta;
    horLine(ey1, x1, fy1, xFrom, first);

    ey1 += incr;
    setCurrCell(xFrom >> SubpixelShift, ey1);

    if (ey1 != ey2)
    {
        p    = SubpixelScale * dx;
        lift = p / dy;
        rem  = p % dy;
        if (rem < 0)
        {
            lift--;
            rem += dy;
        }
        mod -= dy;

        while (ey1 != ey2)
        {
            delta = lift;
            mod  += rem;
            if (mod >= 0)
            {
                mod -= dy;
                delta++;
            }

            xTo = xFrom + delta;
            horLine(ey1, xFrom, SubpixelScale - first, xTo, first);
            xFrom = xTo;

            ey1 += incr;
            setCurrCell(xFrom >> SubpixelShift, ey1);
        }
    }
    horLine(ey1, xFrom, SubpixelScale - first, x2, fy2);
}

// Flushes the current cell and orders the cells by row (a counting sort into SortedYs / SortedCells), then every
// row by x. Sorting twice is a no-op.
// @0x1426d85f0
bool Rasterizer::SortCells()
{
    if (CurrCell.Area | CurrCell.Cover)
        Cells.PushBack(CurrCell);
    CurrCell.x     = 0x7FFFFFFF;
    CurrCell.y     = 0x7FFFFFFF;
    CurrCell.Cover = 0;
    CurrCell.Area  = 0;

    if (Cells.GetSize() == 0)
        return false;
    if (SortedYs.GetSize())
        return true;

    SortedCells.Resize(Cells.GetSize());
    SortedYs.Resize(MaxY - MinY + 1);
    SortedYs.Zero();

    unsigned i;
    // cells per row ...
    for (i = 0; i < Cells.GetSize(); i++)
        SortedYs[Cells[i].y - MinY].Start++;

    // ... to the first index of each row ...
    unsigned start = 0;
    for (i = 0; i < SortedYs.GetSize(); i++)
    {
        unsigned n = SortedYs[i].Start;
        SortedYs[i].Start = start;
        start += n;
    }

    // ... and the cells dropped into their rows
    for (i = 0; i < Cells.GetSize(); i++)
    {
        Cell*    cell = &Cells[i];
        SortedY& row  = SortedYs[cell->y - MinY];
        SortedCells[row.Start + row.Count] = cell;
        ++row.Count;
    }

    for (i = 0; i < SortedYs.GetSize(); i++)
    {
        const SortedY& row = SortedYs[i];
        if (row.Count)
        {
            Alg::ArrayAdaptor<Cell*> rowCells(&SortedCells[row.Start], row.Count);
            Alg::QuickSort(rowCells, cellXLess);
        }
    }
    return true;
}

// Writes one row of coverage (numChannels bytes per pixel, from MinX on): cells of the same x are summed, the
// edge pixel gets its partial coverage and the span up to the next cell the full accumulated cover.
// @0x1426d8910
void Rasterizer::SweepScanline(unsigned scanline, unsigned char* raster, unsigned numChannels, int gammaIdx) const
{
    if (scanline >= SortedYs.GetSize())
        return;

    unsigned           numCells = SortedYs[scanline].Count;
    const Cell* const* cells    = &SortedCells[SortedYs[scanline].Start];
    int                cover    = 0;

    while (numCells)
    {
        const Cell* cell = *cells;
        int         x    = cell->x;
        int         area = cell->Area;
        unsigned    alpha;

        cover += cell->Cover;
        while (--numCells)
        {
            cell = *++cells;
            if (cell->x != x)
                break;
            area  += cell->Area;
            cover += cell->Cover;
        }

        if (area)
        {
            alpha = calcAlpha((cover << (SubpixelShift + 1)) - area, gammaIdx);
            UByte* p = raster + (x - MinX) * numChannels;
            for (unsigned j = 0; j < numChannels; j++)
                *p++ = UByte(alpha);
            x++;
        }

        if (numCells && cell->x > x)
        {
            alpha = calcAlpha(cover << (SubpixelShift + 1), gammaIdx);
            if (alpha)
                memset(raster + (x - MinX) * numChannels, alpha, (cell->x - x) * numChannels);
        }
    }
}

// SweepScanline with a hard edge: coverage above threshold is opaque, the rest is left untouched.
// @0x1426d8ad0
void Rasterizer::SweepScanlineThreshold(unsigned scanline, unsigned char* raster, unsigned numChannels,
                                        unsigned threshold) const
{
    if (scanline >= SortedYs.GetSize())
        return;

    unsigned           numCells = SortedYs[scanline].Count;
    const Cell* const* cells    = &SortedCells[SortedYs[scanline].Start];
    int                cover    = 0;

    while (numCells)
    {
        const Cell* cell = *cells;
        int         x    = cell->x;
        int         area = cell->Area;
        unsigned    alpha;

        cover += cell->Cover;
        while (--numCells)
        {
            cell = *++cells;
            if (cell->x != x)
                break;
            area  += cell->Area;
            cover += cell->Cover;
        }

        if (area)
        {
            alpha = calcAlpha((cover << (SubpixelShift + 1)) - area, threshold);
            if (alpha)
            {
                UByte* p = raster + (x - MinX) * numChannels;
                for (unsigned j = 0; j < numChannels; j++)
                    *p++ = UByte(alpha);
            }
            x++;
        }

        if (numCells && cell->x > x)
        {
            alpha = calcAlpha(cover << (SubpixelShift + 1), threshold);
            if (alpha)
                memset(raster + (x - MinX) * numChannels, alpha, (cell->x - x) * numChannels);
        }
    }
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7Rasterizer@Render@Scaleform@@6B@ 0x143193b20
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
