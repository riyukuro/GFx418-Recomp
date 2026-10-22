// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the glyph hinter
// (Render_GlyphFitter) the glyph cache runs on small outlines before rasterizing them.
// Queue unit sfr_render_07 is split along its original sources (07c Render_GlyphFitter).
// MS2-UNIT: sfr_render_07c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426ebe90-0x1426ecf70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_glyphfitter.h"

namespace Scaleform { namespace Render {

// @0x1426ebe90
GlyphFitter::GlyphFitter(MemoryHeap* heap, int nominalFontHeight)
    : NominalFontHeight(nominalFontHeight),
      LHeap(heap),
      Contours(&LHeap),
      Vertices(&LHeap),
      Events(&LHeap),
      LerpPairs(&LHeap),
      LerpRampX(&LHeap),
      LerpRampY(&LHeap),
      StartX(0),
      StartY(0),
      LastXf(0),
      LastYf(0)
{
}

void GlyphFitter::Clear()
{
    Contours.ClearAndRelease();
    Vertices.ClearAndRelease();
    Events.ClearAndRelease();
    LerpPairs.ClearAndRelease();
    LerpRampX.ClearAndRelease();
    LerpRampY.ClearAndRelease();
    LHeap.ClearAndRelease();
}

// every MoveTo opens a contour with its first vertex
// @0x1426ec3e0
void GlyphFitter::MoveTo(float x, float y)
{
    ContourType contour;
    VertexType  v;
    contour.NumVertices = 1;
    contour.StartVertex = (unsigned)Vertices.GetSize();
    v.x = SInt16(x);
    v.y = SInt16(y);
    Contours.PushBack(contour);
    Vertices.PushBack(v);
    StartX = x;
    StartY = y;
    LastXf = x;
    LastYf = y;
}

// a vertex that rounds to the previous one is dropped
// @0x1426ec330
void GlyphFitter::LineTo(float x, float y)
{
    const VertexType& last = Vertices.Back();
    VertexType        v;
    v.x = SInt16(x);
    v.y = SInt16(y);
    if (v.x != last.x || v.y != last.y)
    {
        Vertices.PushBack(v);
        ++Contours.Back().NumVertices;
    }
    LastXf = x;
    LastYf = y;
}

void GlyphFitter::ClosePath()
{
    if (LastXf != StartX || LastYf != StartY)
        LineTo(StartX, StartY);
}

// a closed contour that repeats its first vertex at the end loses the copy
// @0x1426ecec0
void GlyphFitter::removeDuplicateClosures()
{
    for (unsigned i = 0; i < Contours.GetSize(); ++i)
    {
        ContourType& contour = Contours[i];
        if (contour.NumVertices > 2)
        {
            const VertexType& first = Vertices[contour.StartVertex];
            const VertexType& last  = Vertices[contour.StartVertex + contour.NumVertices - 1];
            if (first.x == last.x && first.y == last.y)
                --contour.NumVertices;
        }
    }
}

// The bounds come from the contours seen so far; whenever a contour grows them, its winding (the sign of the
// shoelace sum) becomes the glyph's direction, so the direction is the one of the outermost contour.
// @0x1426ec630
void GlyphFitter::computeBounds()
{
    SInt16 minX = 32767;
    SInt16 minY = 32767;
    SInt16 maxX = -32767;
    SInt16 maxY = -32767;

    MinX = 32767;
    MinY = 32767;
    MaxX = -32767;
    MaxY = -32767;

    for (UPInt i = 0; i < Contours.GetSize(); ++i)
    {
        const ContourType& contour = Contours[i];
        if (contour.NumVertices > 2)
        {
            VertexType prev = Vertices[contour.StartVertex + contour.NumVertices - 1];
            int        sum  = 0;
            for (UPInt j = 0; j < contour.NumVertices; ++j)
            {
                const VertexType& v = Vertices[contour.StartVertex + j];
                if (v.x < minX) minX = v.x;
                if (v.y < minY) minY = v.y;
                if (v.x > maxX) maxX = v.x;
                if (v.y > maxY) maxY = v.y;
                sum += prev.x * v.y - prev.y * v.x;
                prev = v;
            }

            if (minX < MinX || minY < MinY || maxX > MaxX || maxY > MaxY)
            {
                MinX      = minX;
                MinY      = minY;
                MaxX      = maxX;
                MaxY      = maxY;
                Direction = (sum > 0) ? DirCCW : DirCW;
            }
        }
    }
}

// Marks per row (FitY) or column (FitX) whether a bottom (DirCW) or top (DirCCW) edge turns there: at local
// extremes of the outline and at flat shoulders. For FitX the vertices are meant to be turned by 90 degrees; the
// shipped code writes all three rotated x values into the first vertex, which is kept.
// @0x1426ecc20
void GlyphFitter::detectEvents(FitDir dir)
{
    int minCoord = (dir == FitX) ? MinX : MinY;

    Events.Resize((dir == FitX) ? MaxX - MinX + 1 : MaxY - MinY + 1);
    Events.Zero();

    for (unsigned i = 0; i < (unsigned)Contours.GetSize(); ++i)
    {
        const ContourType& contour = Contours[i];
        if (contour.NumVertices > 2)
        {
            Events[0] = DirCW | DirCCW;

            for (unsigned j = 0; j < contour.NumVertices; ++j)
            {
                VertexType v1 = Vertices[contour.StartVertex + j];
                VertexType v2 = Vertices[contour.StartVertex + (j + 1) % contour.NumVertices];
                VertexType v3 = Vertices[contour.StartVertex + (j + 2) % contour.NumVertices];

                if (dir == FitX)
                {
                    SInt16 t;
                    t = v1.x; v1.x = -v1.y; v1.y = t;
                    t = v2.x; v1.x = -v2.y; v2.y = t;
                    t = v3.x; v1.x = -v3.y; v3.y = t;
                }

                int  idx;
                bool done = false;
                if ((v1.y >= v2.y && v3.y >= v2.y) || (v1.y <= v2.y && v3.y <= v2.y))
                {
                    // an extreme: the side it opens to tells bottom from top
                    idx = v2.y - minCoord;
                    if (v1.x <= v2.x && v2.x <= v3.x)
                    {
                        Events[idx] |= (Direction == DirCW) ? DirCCW : DirCW;
                        done = true;
                    }
                    if (v1.x >= v2.x && v2.x >= v3.x)
                    {
                        Events[idx] |= (Direction == DirCW) ? DirCW : DirCCW;
                        done = true;
                    }
                }

                if (!done && v1.y == v2.y)
                {
                    // a flat shoulder
                    idx = v2.y - minCoord;
                    if (v1.x < v2.x)
                        Events[idx] |= (Direction == DirCW) ? DirCCW : DirCW;
                    if (v1.x > v2.x)
                        Events[idx] |= (Direction == DirCW) ? DirCW : DirCCW;
                }
            }
        }
    }
}

// Builds the pairs (original coordinate, snapped coordinate) from the events, bracketed by two far away fixed
// points, and interpolates the ramp between them. Below middle (and always for FitX) bottom edges snap down to the
// nearest pixel; above it top edges snap up, the x height / cap height tops to their own snapped values. A pair
// closer than a pixel to the previous one replaces it.
// @0x1426ec820
void GlyphFitter::computeLerpRamp(FitDir dir, int unitsPerPixel, int middle, int lowerCaseTop, int upperCaseTop)
{
    LerpPairs.Clear();
    VertexType pair;

    pair.x = SInt16(-SnappedHeight * 4);
    pair.y = SInt16(-SnappedHeight * 4);
    LerpPairs.PushBack(pair);

    int prev     = -32767;
    int top1     = lowerCaseTop;
    int top2     = upperCaseTop;
    int top1s    = snapToPixel(top1 + unitsPerPixel, unitsPerPixel);
    int top2s    = snapToPixel(top2 + unitsPerPixel, unitsPerPixel);
    int minCoord = (dir == FitX) ? MinX : MinY;
    int minDist  = unitsPerPixel + 1;
    int y, snapped;
    UByte event;
    unsigned i;

    for (i = 0; i < Events.GetSize(); ++i)
    {
        y     = int(i) + minCoord;
        event = Events[i];

        if (y <= middle || dir == FitX)
        {
            if (event & DirCW)
            {
                if (y > prev + minDist)
                {
                    snapped = snapToPixel(y + unitsPerPixel / 2 + 1, unitsPerPixel);
                    if (LerpPairs.Back().y != snapped)
                    {
                        pair.x = (SInt16)y;
                        pair.y = (SInt16)snapped;
                        LerpPairs.PushBack(pair);
                    }
                    prev = y;
                }
            }
        }
        else if (event & DirCCW)
        {
            bool done = false;
            if (top2)
            {
                if (y >= top2 && y < top2 + minDist)
                {
                    if (y <= prev + minDist || LerpPairs.Back().y + unitsPerPixel >= top2s)
                        LerpPairs.PopBack();
                    pair.x = (SInt16)y;
                    pair.y = (SInt16)top2s;
                    LerpPairs.PushBack(pair);
                    prev = y;
                    done = true;
                }
                else if (y >= top1 && y < top1 + minDist)
                {
                    if (y <= prev + minDist || LerpPairs.Back().y + unitsPerPixel >= top1s)
                        LerpPairs.PopBack();
                    pair.x = (SInt16)y;
                    pair.y = (SInt16)top1s;
                    LerpPairs.PushBack(pair);
                    prev = y;
                    done = true;
                }
            }
            if (!done)
            {
                snapped = snapToPixel(y + unitsPerPixel, unitsPerPixel);
                if (y <= prev + minDist || LerpPairs.Back().y + unitsPerPixel >= snapped)
                    LerpPairs.PopBack();
                pair.x = (SInt16)y;
                pair.y = (SInt16)snapped;
                LerpPairs.PushBack(pair);
                prev = y;
            }
        }
    }

    pair.x = SInt16(SnappedHeight * 4);
    pair.y = SInt16(SnappedHeight * 4);
    LerpPairs.PushBack(pair);

    ArrayUnsafe<SInt16>& ramp = (dir == FitX) ? LerpRampX : LerpRampY;
    ramp.Resize(Events.GetSize());

    VertexType lo   = LerpPairs[0];
    VertexType hi   = LerpPairs[1];
    unsigned   next = 2;
    for (i = 0; i < Events.GetSize(); ++i)
    {
        y = int(i) + minCoord;
        if (y >= hi.x && next < LerpPairs.GetSize())
        {
            lo = hi;
            hi = LerpPairs[next++];
        }
        ramp[i] = SInt16(lo.y + (y - lo.x) * (hi.y - lo.y) / (hi.x - lo.x) - minCoord);
    }
}

// A zero size leaves that direction unhinted. The x pass is gated on the vertical extent, as shipped.
// @0x1426ec090
void GlyphFitter::FitGlyph(int heightInPixels, int widthInPixels, int lowerCaseTop, int upperCaseTop)
{
    UnitsPerPixelX = widthInPixels ? NominalFontHeight / widthInPixels : 1;
    UnitsPerPixelY = heightInPixels ? NominalFontHeight / heightInPixels : 1;
    SnappedHeight  = NominalFontHeight / UnitsPerPixelY * UnitsPerPixelY;

    if (heightInPixels || widthInPixels)
    {
        removeDuplicateClosures();
        computeBounds();
        if (heightInPixels && MaxY > MinY)
        {
            detectEvents(FitY);
            computeLerpRamp(FitY, UnitsPerPixelY, MinY + (MaxY - MinY) / 3, lowerCaseTop, upperCaseTop);
        }
        if (widthInPixels && MaxY > MinY)
        {
            detectEvents(FitX);
            computeLerpRamp(FitX, UnitsPerPixelX, MinX + (MaxX - MinX) / 3, 0, 0);
        }
    }
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7GlyphFitter@Render@Scaleform@@6B@ 0x143193ff0
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
