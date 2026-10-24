// Recovered Scaleform 4.1.18 Render: shape data definitions (fill/stroke styles, the path reading interface) and the
// float shape builder ShapeDataFloat that DrawableImage::Draw(Image*) fills with one textured rectangle.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64): FillStyleType 0x10, ShapeDataFloatTempl: vftable +0, RefCount +8,
// Status +0x10, Fills +0x18, Strokes +0x30, Data +0x48 (the path byte stream).
// Bodies: StartLayer and PathDataEncoder::WriteChar instances in sfr_gfx_05f (linked into the 0x1425eeef0 gap); the
// ArrayLH_POD<UByte> instance (the morph shapes of ShapeMeshProvider) in sfr_render_03d.
#ifndef MS2_SF_RENDER_SHAPEDATA_H
#define MS2_SF_RENDER_SHAPEDATA_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_fillmode.h"

namespace Scaleform { namespace Render {

class ComplexFill;
struct DashArray;
class ImageBase;
class GradientData;

// Reader state while walking the paths of a shape.
struct ShapePosInfo
{
    unsigned Pos;
    int      StartX, StartY;
    int      LastX, LastY;
    unsigned FillBase, StrokeBase;
    unsigned NumFillBits, NumStrokeBits;
    unsigned Fill0, Fill1, Stroke;
    float    Sfactor;
    bool     Initialized;

    // (appended for sfr_render_03d) a reader positioned at pos, nothing decoded yet
    ShapePosInfo(unsigned pos)
        : Pos(pos), StartX(0), StartY(0), LastX(0), LastY(0), FillBase(0), StrokeBase(0), NumFillBits(0),
          NumStrokeBits(0), Fill0(0), Fill1(0), Stroke(0), Sfactor(1.0f), Initialized(false)
    {
    }
};

enum ShapePathType
{
    Shape_EndShape = 0,
    Shape_NewPath  = 1,
    Shape_NewLayer = 2   // a new path that also starts a layer
};

enum PathEdgeType
{
    Edge_EndPath  = 0,
    Edge_LineTo   = 1,
    Edge_QuadTo   = 2,
    Edge_CubicTo  = 3,
    Edge_MaxCoord = 6    // coordinates one ReadEdge may return
};

struct FillStyleType
{
    UInt32           Color;
    Ptr<ComplexFill> pFill;
};

struct StrokeStyleType
{
    float            Width;
    float            Units;   // 1 for pixels, 1/20 for twips
    unsigned         Flags;
    float            Miter;
    UInt32           Color;
    Ptr<ComplexFill> pFill;
    Ptr<DashArray>   pDashes;
};

// Source of fill/stroke styles and path data for the tessellator.
class ShapeDataInterface : public RefCountBase<ShapeDataInterface, Stat_Default_Mem>
{
public:
    virtual bool          IsEmpty() const { return false; }
    virtual unsigned      GetFillStyleCount() const                                       = 0;
    virtual unsigned      GetStrokeStyleCount() const                                     = 0;
    virtual void          GetFillStyle(unsigned idx, FillStyleType* p) const              = 0;   // idx 1-based
    virtual void          GetStrokeStyle(unsigned idx, StrokeStyleType* p) const          = 0;   // idx 1-based
    virtual unsigned      GetStartingPos() const                                          = 0;
    virtual void          Rewind() const {}
    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const = 0;
    virtual PathEdgeType  ReadEdge(ShapePosInfo* pos, float* coord) const                 = 0;
    virtual void          SkipPathData(ShapePosInfo* pos) const
    {
        float coords[Edge_MaxCoord];
        while (ReadEdge(pos, coords) != Edge_EndPath)
            ;
    }

    // (appended for sfr_render_03d) reads the rest of the current path, returning its edge count
    unsigned CountPathEdges(ShapePosInfo* pos) const
    {
        float    coords[Edge_MaxCoord];
        unsigned count = 0;
        while (ReadEdge(pos, coords) != Edge_EndPath)
            ++count;
        return count;
    }
};

// Appends path records to a byte container.
template<class ContainerType>
class PathDataEncoder
{
public:
    PathDataEncoder(ContainerType& data) : Data(&data) {}

    void WriteChar(char v) { Data->PushBack(UByte(v)); }

    // (appended for sfr_render_03d)
    // An unsigned of up to 30 bits: the low two bits of the first byte give the count of bytes that follow,
    // the value is stored above them, low bits first.
    unsigned WriteUInt30(unsigned v)
    {
        if (v <= (1u << 6) - 1)
        {
            Data->PushBack(UByte(v << 2));
            return 1;
        }
        if (v <= (1u << 14) - 1)
        {
            Data->PushBack(UByte((v << 2) | 1));
            Data->PushBack(UByte(v >> 6));
            return 2;
        }
        if (v <= (1u << 22) - 1)
        {
            Data->PushBack(UByte((v << 2) | 2));
            Data->PushBack(UByte(v >> 6));
            Data->PushBack(UByte(v >> 14));
            return 3;
        }
        Data->PushBack(UByte((v << 2) | 3));
        Data->PushBack(UByte(v >> 6));
        Data->PushBack(UByte(v >> 14));
        Data->PushBack(UByte(v >> 22));
        return 4;
    }

    // the four bytes of v in memory order
    void WriteFloat(float v)
    {
        const UByte* bytes = (const UByte*)&v;
        Data->PushBack(bytes[0]);
        Data->PushBack(bytes[1]);
        Data->PushBack(bytes[2]);
        Data->PushBack(bytes[3]);
    }

    // (appended for sfr_gfx_06e) the packed path records of ShapeDataPacked; the ArrayDH<UByte> instances follow
    // GFx_DrawingContext (sfr_gfx_06e): WriteHLine 0x1426009c0, WriteLine 0x142600be0, WriteQuad 0x142601200,
    // WriteVLine 0x142602a00
    unsigned WriteUInt15(unsigned v);
    unsigned WriteHLine(int x);
    unsigned WriteVLine(int y);
    unsigned WriteLine(int x, int y);
    unsigned WriteQuad(int cx, int cy, int ax, int ay);
    unsigned WriteEndPath();
    // (appended for the path headers, sfr_gfx_06e) the signed counterpart of WriteUInt30 (0x142602240)
    unsigned WriteSInt30(int v);

private:
    ContainerType* Data;
};

// (appended for sfr_render_03d) reads back what PathDataEncoder wrote
template<class ContainerType>
class PathDataDecoder
{
public:
    PathDataDecoder(const ContainerType& data) : Data(&data) {}

    char ReadChar(unsigned pos) const { return (char)Data->ValueAt(pos); }

    // returns the number of bytes used
    unsigned ReadUInt30(unsigned pos, unsigned* v) const
    {
        unsigned lead = UByte(Data->ValueAt(pos));
        unsigned r;
        switch (lead & 3)
        {
        case 0:
            *v = lead >> 2;
            return 1;
        case 1:
            r  = lead >> 2;
            *v = r | (Data->ValueAt(pos + 1) << 6);
            return 2;
        case 2:
            r  = lead >> 2;
            r |= Data->ValueAt(pos + 1) << 6;
            *v = r | (Data->ValueAt(pos + 2) << 14);
            return 3;
        }
        r  = lead >> 2;
        r |= Data->ValueAt(pos + 1) << 6;
        r |= Data->ValueAt(pos + 2) << 14;
        *v = r | (Data->ValueAt(pos + 3) << 22);
        return 4;
    }

    float ReadFloat(unsigned pos) const
    {
        float v = 0;
        UByte* bytes = (UByte*)&v;
        bytes[0] = Data->ValueAt(pos);
        bytes[1] = Data->ValueAt(pos + 1);
        bytes[2] = Data->ValueAt(pos + 2);
        bytes[3] = Data->ValueAt(pos + 3);
        return v;
    }

    // (appended for sfr_gfx_06e) the packed path records
    unsigned ReadUInt15(unsigned pos, unsigned* v) const
    {
        unsigned lead = UByte(Data->ValueAt(pos));
        if (!(lead & 1))
        {
            *v = lead >> 1;
            return 1;
        }
        *v = (lead >> 1) | (UByte(Data->ValueAt(pos + 1)) << 7);
        return 2;
    }
    unsigned ReadSInt30(unsigned pos, int* v) const;
    // one edge into data[0] (PathDataPackerTypes::EdgeType) and data[1..4] (the deltas); returns the bytes used
    unsigned ReadEdge(unsigned pos, int* data) const;


private:
    const ContainerType* Data;
    // the bytes that follow the first one of an edge, by PathDataPackerTypes::RawEdgeType
    static const UByte Sizes[16];
};

// Shape built from float coordinates: layers of paths, each a tag byte followed by its data.
template<class ContainerType>
class ShapeDataFloatTempl : public ShapeDataInterface
{
    enum DataStatus
    {
        Status_Clean,
        Status_StartLayer,
        Status_StartPath,
        Status_MoveTo,
        Status_EdgeTo,
        Status_EndPath,
        Status_EndShape
    };
    enum DataTags
    {
        Tag_NewLayer,
        Tag_NewPath,
        Tag_MoveTo,
        Tag_LineTo,
        Tag_QuadTo,
        Tag_CubicTo,
        Tag_EndPath,
        Tag_EndShape
    };

public:
    void StartLayer()
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_NewLayer);
        Status = Status_StartLayer;
    }

    // (appended for sfr_render_03d: the morph shapes of ShapeMeshProvider, ContainerType ArrayLH_POD<UByte>)
    ShapeDataFloatTempl(ContainerType* data, unsigned startingPos)
        : Status(Status_Clean), Data(data), StartingPos(startingPos), StartX(0), StartY(0), LastX(0), LastY(0)
    {
    }

    unsigned AddFillStyle(const FillStyleType& fill)
    {
        Fills.PushBack(fill);
        return (unsigned)Fills.GetSize();
    }
    unsigned AddStrokeStyle(const StrokeStyleType& stroke)
    {
        Strokes.PushBack(stroke);
        return (unsigned)Strokes.GetSize();
    }

    // a path record: tag, the three styles, then the MoveTo
    void StartPath(unsigned fill0, unsigned fill1, unsigned stroke)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        if (Status == Status_Clean)
            StartLayer();
        encoder.WriteChar(Tag_NewPath);
        encoder.WriteUInt30(fill0);
        encoder.WriteUInt30(fill1);
        encoder.WriteUInt30(stroke);
        Status = Status_StartPath;
    }
    void MoveTo(float x, float y)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_MoveTo);
        encoder.WriteFloat(x);
        encoder.WriteFloat(y);
        StartX = x;
        StartY = y;
        LastX  = x;
        LastY  = y;
        Status = Status_MoveTo;
    }
    void LineTo(float x, float y)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_LineTo);
        encoder.WriteFloat(x);
        encoder.WriteFloat(y);
        Status = Status_EdgeTo;
        LastX = x;
        LastY = y;
    }
    void QuadTo(float cx, float cy, float ax, float ay)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_QuadTo);
        encoder.WriteFloat(cx);
        encoder.WriteFloat(cy);
        encoder.WriteFloat(ax);
        encoder.WriteFloat(ay);
        Status = Status_EdgeTo;
        LastX = ax;
        LastY = ay;
    }
    void CubicTo(float c1x, float c1y, float c2x, float c2y, float ax, float ay)
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_CubicTo);
        encoder.WriteFloat(c1x);
        encoder.WriteFloat(c1y);
        encoder.WriteFloat(c2x);
        encoder.WriteFloat(c2y);
        encoder.WriteFloat(ax);
        encoder.WriteFloat(ay);
        Status = Status_EdgeTo;
        LastX = ax;
        LastY = ay;
    }
    // drops the styles and the recorded path data (the container itself stays)
    void Clear()
    {
        Status = Status_Clean;
        Fills.Clear();
        Strokes.Clear();
        Data->Clear();
        StartX = StartY = 0;
        LastX = LastY = 0;
    }
    void EndPath()
    {
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_EndPath);
        Status = Status_EndPath;
    }
    // (appended, sfr24: the focus rectangles of sfr_gfx_01i) the edge back to the MoveTo point, unless the path
    // already ends there
    void ClosePath()
    {
        if (LastX != StartX || LastY != StartY)
            LineTo(StartX, StartY);
    }
    // closes the open path and terminates the data (once; an empty shape gets nothing)
    void EndShape()
    {
        if (Status == Status_EndShape || Status == Status_Clean)
            return;
        if (Status != Status_EndPath)
            EndPath();
        PathDataEncoder<ContainerType> encoder(*Data);
        encoder.WriteChar(Tag_EndShape);
        Status = Status_EndShape;
    }

    virtual unsigned GetFillStyleCount() const   { return (unsigned)Fills.GetSize(); }
    virtual unsigned GetStrokeStyleCount() const { return (unsigned)Strokes.GetSize(); }
    virtual void     GetFillStyle(unsigned idx, FillStyleType* p) const     { *p = Fills[idx - 1]; }
    virtual void     GetStrokeStyle(unsigned idx, StrokeStyleType* p) const { *p = Strokes[idx - 1]; }
    virtual unsigned GetStartingPos() const      { return StartingPos; }

    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
    {
        if (pos->Pos >= Data->GetSize())
            return Shape_EndShape;

        ShapePathType type = Shape_NewPath;
        PathDataDecoder<ContainerType> reader(*Data);
        char tag = reader.ReadChar(pos->Pos);
        pos->Pos++;
        if (tag == Tag_EndShape)
            return Shape_EndShape;
        if (tag == Tag_NewLayer)
        {
            type = Shape_NewLayer;
            tag  = reader.ReadChar(pos->Pos);   // the Tag_NewPath that follows
            pos->Pos++;
        }
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[0]);
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[1]);
        pos->Pos += reader.ReadUInt30(pos->Pos, &styles[2]);
        tag = reader.ReadChar(pos->Pos);        // Tag_MoveTo
        pos->Pos++;
        coord[0] = reader.ReadFloat(pos->Pos);
        pos->Pos += 4;
        coord[1] = reader.ReadFloat(pos->Pos);
        pos->Pos += 4;
        return type;
    }

    virtual PathEdgeType ReadEdge(ShapePosInfo* pos, float* coord) const
    {
        PathDataDecoder<ContainerType> reader(*Data);
        PathEdgeType edge = Edge_EndPath;
        char tag = reader.ReadChar(pos->Pos);
        pos->Pos++;
        if (tag != Tag_EndPath)
        {
            // the end point, then the control point(s) of a curve
            edge = Edge_LineTo;
            coord[0] = reader.ReadFloat(pos->Pos);
            pos->Pos += 4;
            coord[1] = reader.ReadFloat(pos->Pos);
            pos->Pos += 4;
            if (tag == Tag_QuadTo || tag == Tag_CubicTo)
            {
                edge = Edge_QuadTo;
                coord[2] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
                coord[3] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
            }
            if (tag == Tag_CubicTo)
            {
                edge = Edge_CubicTo;
                coord[4] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
                coord[5] = reader.ReadFloat(pos->Pos);
                pos->Pos += 4;
            }
        }
        return edge;
    }

    float GetLastX() const { return LastX; }
    float GetLastY() const { return LastY; }

private:
    DataStatus               Status;        // +0x10
    ArrayLH<FillStyleType>   Fills;         // +0x18
    ArrayLH<StrokeStyleType> Strokes;       // +0x30
    ContainerType*           Data;          // +0x48
    unsigned                 StartingPos;   // +0x50
    float                    StartX, StartY;
    float                    LastX, LastY;
};

// (appended for the shape cache nodes, sfr_render_03f) StrokeStyleType::Flags
enum StrokeStyleFlags
{
    StrokeFlag_StrokeHinting = 0x01,
    StrokeScaling_Normal     = 0x00,
    StrokeScaling_Horizontal = 0x02,
    StrokeScaling_Vertical   = 0x04,
    StrokeScaling_None       = 0x06,
    StrokeScaling_Mask       = 0x06
};

// (appended for the shape cache nodes, sfr_render_03f; members from the shape mesh provider, sfr_render_03d)
// An image or gradient fill: the source, its placement and how it is sampled.
class ComplexFill : public RefCountBase<ComplexFill, Stat_Default_Mem>
{
public:
    Ptr<ImageBase>    pImage;        // +0x10
    Ptr<GradientData> pGradient;     // +0x18
    Matrix2F          ImageMatrix;   // +0x20
    ImageFillMode     FillMode;      // +0x40
    unsigned          BindIndex;     // +0x44

    // (appended for the drawing API, sfr_gfx_06e) no source yet, identity placement, not bound; defined inline
    // where GradientData is complete (sfr_gfx_06e)
    inline ComplexFill();
};
// dash and gap lengths of a dashed stroke
struct DashArray : public RefCountBase<DashArray, Stat_Default_Mem>
{
    float    Dashes[16];
    float    DashStart;
    unsigned DashCount;
};


// (appended for the drawing API, sfr_gfx_06e) the packed integer path format of ShapeDataPacked.
// A path is a header (UInt15 path type, the three UInt30 styles, the SInt30 start point) and then edges, each a
// tag nibble in the low four bits of its first byte with the coordinate deltas packed in the bits that follow.
struct PathDataPackerTypes
{
    // the edge records as stored (the number is the bit width of each delta)
    enum RawEdgeType
    {
        Edge_H12, Edge_H28,                 // horizontal line
        Edge_V12, Edge_V28,                 // vertical line
        Edge_L6,  Edge_L10, Edge_L14, Edge_L30,
        Edge_C5,  Edge_C7,  Edge_C9,  Edge_C11, Edge_C13, Edge_C15, Edge_C31,   // quadratic curve
        EndPath
    };
    // the edges as decoded
    enum EdgeType
    {
        Edge_HLine,
        Edge_VLine,
        Edge_Line,
        Edge_Quad,
        Edge_EndPath
    };
};

// (appended for sfr_gfx_06e) the packed records of PathDataEncoder
template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteUInt15(unsigned v)
{
    if (v <= (1u << 7) - 1)
    {
        Data->PushBack(UByte(v << 1));
        return 1;
    }
    Data->PushBack(UByte((v << 1) | 1));
    Data->PushBack(UByte(v >> 7));
    return 2;
}
template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteEndPath()
{
    Data->PushBack(UByte(PathDataPackerTypes::EndPath));
    return 1;
}

// (appended for the path records, sfr_gfx_06e; the instances follow GFx_DrawingContext in the exe)
// A signed of up to 30 bits, stored like WriteUInt30 (two count bits, then the value low bits first).
template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteSInt30(int v)
{
    if (v >= -(1 << 5) && v < (1 << 5))
    {
        Data->PushBack(UByte(v << 2));
        return 1;
    }
    if (v >= -(1 << 13) && v < (1 << 13))
    {
        Data->PushBack(UByte((v << 2) | 1));
        Data->PushBack(UByte(v >> 6));
        return 2;
    }
    if (v >= -(1 << 21) && v < (1 << 21))
    {
        Data->PushBack(UByte((v << 2) | 2));
        Data->PushBack(UByte(v >> 6));
        Data->PushBack(UByte(v >> 14));
        return 3;
    }
    Data->PushBack(UByte((v << 2) | 3));
    Data->PushBack(UByte(v >> 6));
    Data->PushBack(UByte(v >> 14));
    Data->PushBack(UByte(v >> 22));
    return 4;
}

// Edges: the record tag in the low nibble of the first byte, the deltas packed from bit 4 on, each one as narrow
// as the largest of them allows. The 28-bit line records return 3 although they write four bytes (as in the exe).
template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteHLine(int x)
{
    typedef PathDataPackerTypes T;
    if (x >= -(1 << 11) && x < (1 << 11))
    {
        Data->PushBack(UByte((x << 4) | T::Edge_H12));
        Data->PushBack(UByte(x >> 4));
        return 2;
    }
    Data->PushBack(UByte((x << 4) | T::Edge_H28));
    Data->PushBack(UByte(x >> 4));
    Data->PushBack(UByte(x >> 12));
    Data->PushBack(UByte(x >> 20));
    return 3;
}

template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteVLine(int y)
{
    typedef PathDataPackerTypes T;
    if (y >= -(1 << 11) && y < (1 << 11))
    {
        Data->PushBack(UByte((y << 4) | T::Edge_V12));
        Data->PushBack(UByte(y >> 4));
        return 2;
    }
    Data->PushBack(UByte((y << 4) | T::Edge_V28));
    Data->PushBack(UByte(y >> 4));
    Data->PushBack(UByte(y >> 12));
    Data->PushBack(UByte(y >> 20));
    return 3;
}

template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteLine(int x, int y)
{
    typedef PathDataPackerTypes T;
    if (x >= -(1 << 5) && x < (1 << 5) && y >= -(1 << 5) && y < (1 << 5))
    {
        Data->PushBack(UByte((x << 4) | T::Edge_L6));
        Data->PushBack(UByte(((x >> 4) & 0x03) | (y << 2)));
        return 2;
    }
    if (x >= -(1 << 9) && x < (1 << 9) && y >= -(1 << 9) && y < (1 << 9))
    {
        Data->PushBack(UByte((x << 4) | T::Edge_L10));
        Data->PushBack(UByte(((x >> 4) & 0x3F) | (y << 6)));
        Data->PushBack(UByte(y >> 2));
        return 3;
    }
    if (x >= -(1 << 13) && x < (1 << 13) && y >= -(1 << 13) && y < (1 << 13))
    {
        Data->PushBack(UByte((x << 4) | T::Edge_L14));
        Data->PushBack(UByte(x >> 4));
        Data->PushBack(UByte(((x >> 12) & 0x03) | (y << 2)));
        Data->PushBack(UByte(y >> 6));
        return 4;
    }
    Data->PushBack(UByte((x << 4) | T::Edge_L30));
    Data->PushBack(UByte(x >> 4));
    Data->PushBack(UByte(x >> 12));
    Data->PushBack(UByte(x >> 20));
    Data->PushBack(UByte(((x >> 28) & 0x03) | (y << 2)));
    Data->PushBack(UByte(y >> 6));
    Data->PushBack(UByte(y >> 14));
    Data->PushBack(UByte(y >> 22));
    return 8;
}

template<class ContainerType>
unsigned PathDataEncoder<ContainerType>::WriteQuad(int cx, int cy, int ax, int ay)
{
    typedef PathDataPackerTypes T;
    // the record width comes from the widest of the four deltas
    int lo = cx, hi = cx;
    if (cy < lo) lo = cy;
    if (cy > hi) hi = cy;
    if (ax < lo) lo = ax;
    if (ax > hi) hi = ax;
    if (ay < lo) lo = ay;
    if (ay > hi) hi = ay;

    if (lo >= -(1 << 4) && hi <= (1 << 4) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C5));
        Data->PushBack(UByte(((cx >> 4) & 0x01) | ((cy << 1) & 0x3F) | (ax << 6)));
        Data->PushBack(UByte(((ax >> 2) & 0x07) | (ay << 3)));
        return 3;
    }
    if (lo >= -(1 << 6) && hi <= (1 << 6) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C7));
        Data->PushBack(UByte(((cx >> 4) & 0x07) | (cy << 3)));
        Data->PushBack(UByte(((cy >> 5) & 0x03) | (ax << 2)));
        Data->PushBack(UByte(((ax >> 6) & 0x01) | (ay << 1)));
        return 4;
    }
    if (lo >= -(1 << 8) && hi <= (1 << 8) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C9));
        Data->PushBack(UByte(((cx >> 4) & 0x1F) | (cy << 5)));
        Data->PushBack(UByte(((cy >> 3) & 0x3F) | (ax << 6)));
        Data->PushBack(UByte(((ax >> 2) & 0x7F) | (ay << 7)));
        Data->PushBack(UByte(ay >> 1));
        return 5;
    }
    if (lo >= -(1 << 10) && hi <= (1 << 10) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C11));
        Data->PushBack(UByte(((cx >> 4) & 0x7F) | (cy << 7)));
        Data->PushBack(UByte(cy >> 1));
        Data->PushBack(UByte(((cy >> 9) & 0x03) | (ax << 2)));
        Data->PushBack(UByte(((ax >> 6) & 0x1F) | (ay << 5)));
        Data->PushBack(UByte(ay >> 3));
        return 6;
    }
    if (lo >= -(1 << 12) && hi <= (1 << 12) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C13));
        Data->PushBack(UByte(cx >> 4));
        Data->PushBack(UByte(((cx >> 12) & 0x01) | (cy << 1)));
        Data->PushBack(UByte(((cy >> 7) & 0x3F) | (ax << 6)));
        Data->PushBack(UByte(ax >> 2));
        Data->PushBack(UByte(((ax >> 10) & 0x07) | (ay << 3)));
        Data->PushBack(UByte(ay >> 5));
        return 7;
    }
    if (lo >= -(1 << 14) && hi <= (1 << 14) - 1)
    {
        Data->PushBack(UByte((cx << 4) | T::Edge_C15));
        Data->PushBack(UByte(cx >> 4));
        Data->PushBack(UByte(((cx >> 12) & 0x07) | (cy << 3)));
        Data->PushBack(UByte(cy >> 5));
        Data->PushBack(UByte(((cy >> 13) & 0x03) | (ax << 2)));
        Data->PushBack(UByte(ax >> 6));
        Data->PushBack(UByte(((ax >> 14) & 0x01) | (ay << 1)));
        Data->PushBack(UByte(ay >> 7));
        return 8;
    }
    Data->PushBack(UByte((cx << 4) | T::Edge_C31));
    Data->PushBack(UByte(cx >> 4));
    Data->PushBack(UByte(cx >> 12));
    Data->PushBack(UByte(cx >> 20));
    Data->PushBack(UByte(((cx >> 28) & 0x07) | (cy << 3)));
    Data->PushBack(UByte(cy >> 5));
    Data->PushBack(UByte(cy >> 13));
    Data->PushBack(UByte(cy >> 21));
    Data->PushBack(UByte(((cy >> 29) & 0x03) | (ax << 2)));
    Data->PushBack(UByte(ax >> 6));
    Data->PushBack(UByte(ax >> 14));
    Data->PushBack(UByte(ax >> 22));
    Data->PushBack(UByte(((ax >> 30) & 0x01) | (ay << 1)));
    Data->PushBack(UByte(ay >> 7));
    Data->PushBack(UByte(ay >> 15));
    Data->PushBack(UByte(ay >> 23));
    return 16;
}

template<class ContainerType>
const UByte PathDataDecoder<ContainerType>::Sizes[16] = { 1, 3, 1, 3, 1, 2, 3, 7, 2, 3, 4, 5, 6, 7, 15, 0 };


// signed: the top byte is sign extended
template<class ContainerType>
unsigned PathDataDecoder<ContainerType>::ReadSInt30(unsigned pos, int* v) const
{
    int r = SByte(Data->ValueAt(pos));
    switch (r & 3)
    {
    case 0:
        *v = r >> 2;
        return 1;
    case 1:
        r  = (r >> 2) & 0x3F;
        *v = r | (SByte(Data->ValueAt(pos + 1)) << 6);
        return 2;
    case 2:
        r  = (r >> 2) & 0x3F;
        r  = r | (UByte(Data->ValueAt(pos + 1)) << 6);
        *v = r | (SByte(Data->ValueAt(pos + 2)) << 14);
        return 3;
    }
    r  = (r >> 2) & 0x3F;
    r  = r | (UByte(Data->ValueAt(pos + 1)) << 6);
    r  = r | (UByte(Data->ValueAt(pos + 2)) << 14);
    *v = r | (SByte(Data->ValueAt(pos + 3)) << 22);
    return 4;
}

// Each delta is gathered low bits first; the byte that holds its top bits is read signed so the value comes out
// sign extended (a byte shared with the next delta is first shifted so that delta's top bit lands in bit 7).
template<class ContainerType>
unsigned PathDataDecoder<ContainerType>::ReadEdge(unsigned pos, int* data) const
{
    UByte b[16];
    b[0] = Data->ValueAt(pos++);
    unsigned extra = Sizes[b[0] & 0xF];
    UByte* p = b + 1;
    for (unsigned i = 0; i < extra; i++)
        *p++ = Data->ValueAt(pos++);

    typedef PathDataPackerTypes T;
    switch (b[0] & 0xF)
    {
    case T::Edge_H12:
        data[0] = T::Edge_HLine;
        data[1] = int(b[0] >> 4) | (SByte(b[1]) << 4);
        break;
    case T::Edge_H28:
        data[0] = T::Edge_HLine;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | (SByte(b[2]) << 12) | (SByte(b[3]) << 20);
        break;
    case T::Edge_V12:
        data[0] = T::Edge_VLine;
        data[1] = int(b[0] >> 4) | (SByte(b[1]) << 4);
        break;
    case T::Edge_V28:
        data[0] = T::Edge_VLine;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | (SByte(b[2]) << 12) | (SByte(b[3]) << 20);
        break;
    case T::Edge_L6:
        data[0] = T::Edge_Line;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 6) >> 2);
        data[2] = SByte(b[1]) >> 2;
        break;
    case T::Edge_L10:
        data[0] = T::Edge_Line;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 2) << 2);
        data[2] = int(b[1] >> 6) | (SByte(b[2]) << 2);
        break;
    case T::Edge_L14:
        data[0] = T::Edge_Line;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | (SByte(b[2] << 6) << 6);
        data[2] = int(b[2] >> 2) | (SByte(b[3]) << 6);
        break;
    case T::Edge_L30:
        data[0] = T::Edge_Line;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | int(b[2] << 12) | int(b[3] << 20) | (SByte(b[4] << 6) << 22);
        data[2] = int(b[4] >> 2) | int(b[5] << 6) | int(b[6] << 14) | (SByte(b[7]) << 22);
        break;
    case T::Edge_C5:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 7) >> 3);
        data[2] = SByte(b[1] << 2) >> 3;
        data[3] = int(b[1] >> 6) | (SByte(b[2] << 5) >> 3);
        data[4] = SByte(b[2]) >> 3;
        break;
    case T::Edge_C7:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 5) >> 1);
        data[2] = int(b[1] >> 3) | (SByte(b[2] << 6) >> 1);
        data[3] = int(b[2] >> 2) | (SByte(b[3] << 7) >> 1);
        data[4] = SByte(b[3]) >> 1;
        break;
    case T::Edge_C9:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 3) << 1);
        data[2] = int(b[1] >> 5) | (SByte(b[2] << 2) << 1);
        data[3] = int(b[2] >> 6) | (SByte(b[3] << 1) << 1);
        data[4] = int(b[3] >> 7) | (SByte(b[4]) << 1);
        break;
    case T::Edge_C11:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | (SByte(b[1] << 1) << 3);
        data[2] = int(b[1] >> 7) | int(b[2] << 1) | (SByte(b[3] << 6) << 3);
        data[3] = int(b[3] >> 2) | (SByte(b[4] << 3) << 3);
        data[4] = int(b[4] >> 5) | (SByte(b[5]) << 3);
        break;
    case T::Edge_C13:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | (SByte(b[2] << 7) << 5);
        data[2] = int(b[2] >> 1) | (SByte(b[3] << 2) << 5);
        data[3] = int(b[3] >> 6) | int(b[4] << 2) | (SByte(b[5] << 5) << 5);
        data[4] = int(b[5] >> 3) | (SByte(b[6]) << 5);
        break;
    case T::Edge_C15:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4) | int(b[1] << 4) | (SByte(b[2] << 5) << 7);
        data[2] = int(b[2] >> 3) | int(b[3] << 5) | (SByte(b[4] << 6) << 7);
        data[3] = int(b[4] >> 2) | int(b[5] << 6) | (SByte(b[6] << 7) << 7);
        data[4] = int(b[6] >> 1) | (SByte(b[7]) << 7);
        break;
    case T::Edge_C31:
        data[0] = T::Edge_Quad;
        data[1] = int(b[0] >> 4)  | int(b[1] << 4)  | int(b[2] << 12)  | int(b[3] << 20)  | (SByte(b[4] << 5) << 23);
        data[2] = int(b[4] >> 3)  | int(b[5] << 5)  | int(b[6] << 13)  | int(b[7] << 21)  | (SByte(b[8] << 6) << 23);
        data[3] = int(b[8] >> 2)  | int(b[9] << 6)  | int(b[10] << 14) | int(b[11] << 22) | (SByte(b[12] << 7) << 23);
        data[4] = int(b[12] >> 1) | int(b[13] << 7) | int(b[14] << 15) | (SByte(b[15]) << 23);
        break;
    case T::EndPath:
        data[0] = T::Edge_EndPath;
        break;
    }
    return extra + 1;
}

// Writes packed path data: coordinates scaled by Multiplier, kept as deltas to the last point (0x10 bytes).
template<class ContainerType>
class ShapeDataPackedEncoder
{
public:
    ShapeDataPackedEncoder(ContainerType* c, float multiplier) : Encoder(*c), Multiplier(multiplier) {}

    void LineTo(ShapePosInfo* pos, float x, float y)
    {
        int dx = int(x * Multiplier) - pos->LastX;
        int dy = int(y * Multiplier) - pos->LastY;
        if (dy == 0)
            Encoder.WriteHLine(dx);
        else if (dx == 0)
            Encoder.WriteVLine(dy);
        else
            Encoder.WriteLine(dx, dy);
        pos->LastX += dx;
        pos->LastY += dy;
    }
    void QuadTo(ShapePosInfo* pos, float cx, float cy, float ax, float ay)
    {
        int dcx = int(cx * Multiplier) - pos->LastX;
        int dcy = int(cy * Multiplier) - pos->LastY;
        int dax = int(ax * Multiplier) - pos->LastX;
        int day = int(ay * Multiplier) - pos->LastY;
        Encoder.WriteQuad(dcx, dcy, dax, day);
        pos->LastX += dax;
        pos->LastY += day;
    }
    void EndPath()  { Encoder.WriteEndPath(); }
    void EndShape() { Encoder.WriteUInt15(Shape_EndShape); }
    // (appended for the path headers) the path type, its styles and the start point
    void StartPath(ShapePosInfo* pos, ShapePathType type, unsigned fill0, unsigned fill1, unsigned stroke, float x,
                   float y)
    {
        Encoder.WriteUInt15(type);
        Encoder.WriteUInt30(fill0);
        Encoder.WriteUInt30(fill1);
        Encoder.WriteUInt30(stroke);
        pos->StartX = pos->LastX = int(x * Multiplier);
        Encoder.WriteSInt30(pos->StartX);
        pos->StartY = pos->LastY = int(y * Multiplier);
        Encoder.WriteSInt30(pos->StartY);
    }
    // (appended for sfr_render_04o) a closing line back to the start point when the path ends elsewhere
    void ClosePath(ShapePosInfo* pos)
    {
        if (pos->LastX != pos->StartX || pos->LastY != pos->StartY)
        {
            int dx = pos->StartX - pos->LastX;
            int dy = pos->StartY - pos->LastY;
            if (dy == 0)
                Encoder.WriteHLine(dx);
            else if (dx == 0)
                Encoder.WriteVLine(dy);
            else
                Encoder.WriteLine(dx, dy);
            pos->LastX = pos->StartX;
            pos->LastY = pos->StartY;
        }
    }

private:
    PathDataEncoder<ContainerType> Encoder;      // +0
    float                          Multiplier;   // +8
};

// Reads packed path data back: the integer reader and the scale back to floats (0x10 bytes).
template<class ContainerType>
class ShapeDataPackedDecoder
{
public:
    ShapeDataPackedDecoder(const ContainerType* c, float multiplier) : Reader(*c), OneOverMultiplier(1.0f / multiplier)
    {
    }

    ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
    {
        unsigned type;
        pos->Pos += Reader.ReadUInt15(pos->Pos, &type);
        if (type != Shape_EndShape)
        {
            pos->Pos += Reader.ReadUInt30(pos->Pos, &styles[0]);
            pos->Pos += Reader.ReadUInt30(pos->Pos, &styles[1]);
            pos->Pos += Reader.ReadUInt30(pos->Pos, &styles[2]);
            pos->Pos += Reader.ReadSInt30(pos->Pos, &pos->StartX);
            pos->Pos += Reader.ReadSInt30(pos->Pos, &pos->StartY);
            pos->LastX = pos->StartX;
            pos->LastY = pos->StartY;
            coord[0]   = float(pos->StartX) * OneOverMultiplier;
            coord[1]   = float(pos->StartY) * OneOverMultiplier;
        }
        return ShapePathType(type);
    }

    // lines come back as Edge_LineTo to the new end point, curves as Edge_QuadTo (control, then anchor)
    PathEdgeType ReadEdge(ShapePosInfo* pos, float* coord) const
    {
        int d[5];
        pos->Pos += Reader.ReadEdge(pos->Pos, d);
        switch (d[0])
        {
        case PathDataPackerTypes::Edge_HLine:
            pos->LastX += d[1];
            coord[0] = float(pos->LastX) * OneOverMultiplier;
            coord[1] = float(pos->LastY) * OneOverMultiplier;
            return Edge_LineTo;
        case PathDataPackerTypes::Edge_VLine:
            pos->LastY += d[1];
            coord[0] = float(pos->LastX) * OneOverMultiplier;
            coord[1] = float(pos->LastY) * OneOverMultiplier;
            return Edge_LineTo;
        case PathDataPackerTypes::Edge_Line:
            pos->LastX += d[1];
            pos->LastY += d[2];
            coord[0] = float(pos->LastX) * OneOverMultiplier;
            coord[1] = float(pos->LastY) * OneOverMultiplier;
            return Edge_LineTo;
        case PathDataPackerTypes::Edge_Quad:
            d[1] += pos->LastX;
            d[2] += pos->LastY;
            d[3] += pos->LastX;
            d[4] += pos->LastY;
            coord[0]   = float(d[1]) * OneOverMultiplier;
            coord[1]   = float(d[2]) * OneOverMultiplier;
            coord[2]   = float(d[3]) * OneOverMultiplier;
            coord[3]   = float(d[4]) * OneOverMultiplier;
            pos->LastX = d[3];
            pos->LastY = d[4];
            return Edge_QuadTo;
        }
        return Edge_EndPath;
    }

private:
    PathDataDecoder<ContainerType> Reader;              // +0
    float                          OneOverMultiplier;   // +8
};

// Shape data stored as packed integers: coordinates are multiplied by Multiplier and kept as deltas.
template<class ContainerType>
class ShapeDataPacked : public ShapeDataInterface
{
public:
    ShapeDataPacked(ContainerType* c, unsigned startingPos, float multiplier)
        : pContainer(c), Decoder(c, multiplier), StartingPos(startingPos), Multiplier(multiplier)
    {
    }

    unsigned AddFillStyle(const FillStyleType& fill)
    {
        FillStyles.PushBack(fill);
        return (unsigned)FillStyles.GetSize();
    }
    unsigned AddStrokeStyle(const StrokeStyleType& stroke)
    {
        StrokeStyles.PushBack(stroke);
        return (unsigned)StrokeStyles.GetSize();
    }
    void UpdateFillStyle(unsigned idx, const FillStyleType& fill)       { FillStyles[idx - 1] = fill; }
    void UpdateStrokeStyle(unsigned idx, const StrokeStyleType& stroke) { StrokeStyles[idx - 1] = stroke; }

    // a path header: type, styles and the start point (0x1426005f0, sfr_gfx_06e)
    void StartPath(ShapePosInfo* pos, ShapePathType type, unsigned fill0, unsigned fill1, unsigned stroke,
                   float x, float y);
    void LineTo(ShapePosInfo* pos, float x, float y)
    {
        ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
        encoder.LineTo(pos, x, y);
    }
    void QuadTo(ShapePosInfo* pos, float cx, float cy, float ax, float ay)
    {
        ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
        encoder.QuadTo(pos, cx, cy, ax, ay);
    }
    void EndPath()
    {
        ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
        encoder.EndPath();
    }
    void EndShape()
    {
        ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
        encoder.EndShape();
    }
    // (appended for sfr_render_04o)
    void ClosePath(ShapePosInfo* pos)
    {
        ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
        encoder.ClosePath(pos);
    }

    virtual bool     IsEmpty() const             { return !pContainer || pContainer->GetSize() <= StartingPos; }
    virtual unsigned GetFillStyleCount() const   { return (unsigned)FillStyles.GetSize(); }
    virtual unsigned GetStrokeStyleCount() const { return (unsigned)StrokeStyles.GetSize(); }
    virtual void     GetFillStyle(unsigned idx, FillStyleType* p) const     { *p = FillStyles[idx - 1]; }
    virtual void     GetStrokeStyle(unsigned idx, StrokeStyleType* p) const { *p = StrokeStyles[idx - 1]; }
    virtual unsigned GetStartingPos() const      { return StartingPos; }

    virtual ShapePathType ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
    {
        return Decoder.ReadPathInfo(pos, coord, styles);
    }
    virtual PathEdgeType ReadEdge(ShapePosInfo* pos, float* coord) const { return Decoder.ReadEdge(pos, coord); }

protected:
    ContainerType*                        pContainer;     // +0x10
    ShapeDataPackedDecoder<ContainerType> Decoder;        // +0x18
    unsigned                              StartingPos;    // +0x28
    float                                 Multiplier;     // +0x2c
    ArrayLH<FillStyleType>                FillStyles;     // +0x30
    ArrayLH<StrokeStyleType>              StrokeStyles;   // +0x48
};

template<class ContainerType>
void ShapeDataPacked<ContainerType>::StartPath(ShapePosInfo* pos, ShapePathType type, unsigned fill0, unsigned fill1,
                                               unsigned stroke, float x, float y)
{
    ShapeDataPackedEncoder<ContainerType> encoder(pContainer, Multiplier);
    encoder.StartPath(pos, type, fill0, fill1, stroke, x, y);
}


// (appended for sfr_render_03d) the join and cap bits of StrokeStyleType::Flags
enum StrokeStyleJoinCapFlags
{
    StrokeJoin_Round    = 0x00,
    StrokeJoin_Bevel    = 0x10,
    StrokeJoin_Miter    = 0x20,
    StrokeJoin_Mask     = 0x30,
    StrokeCap_Round     = 0x00,
    StrokeCap_None      = 0x40,
    StrokeCap_Square    = 0x80,
    StrokeCap_Mask      = 0xC0,
    StrokeEndCap_Round  = 0x000,
    StrokeEndCap_None   = 0x100,
    StrokeEndCap_Square = 0x200,
    StrokeEndCap_Mask   = 0x300
};

}} // namespace Scaleform::Render

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::ComplexFill) == 0x50, "ComplexFill size");

#endif
