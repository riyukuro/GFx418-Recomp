// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ShapeSwf, part 2 (lane sfr24): the
// DefineShape parser (styles, path records copied into the path allocator) and the decoder that walks the path
// records again for the tessellator, with the template copies they use.
// MS2-UNIT: sfr_gfx_08s2
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426589f0-0x142658b6c .text$mn
// MS2-RANGE: 0x142658cb0-0x142658dec .text$mn
// MS2-RANGE: 0x1426598a0-0x142659c1d .text$mn
// MS2-RANGE: 0x142659c60-0x142659d4a .text$mn
// MS2-RANGE: 0x142659e40-0x142659e7b .text$mn
// MS2-RANGE: 0x14265a960-0x14265aa67 .text$mn
// MS2-RANGE: 0x14265ab80-0x14265abd9 .text$mn
// MS2-RANGE: 0x14265adf0-0x14265c6ed .text$mn
// MS2-RANGE: 0x14265c730-0x14265d007 .text$mn
// MS2-RANGE: 0x14265d210-0x14265d69a .text$mn
// MS2-RANGE: 0x14265d900-0x14265da79 .text$mn
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_shapeswf.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}} // namespace Scaleform::Alg
#include "../include/kernel/sf_hash.h"
#include "../include/render/render_gradients.h"
#include "../include/render/render_image.h"

namespace Scaleform { namespace Render {

// No source yet, identity placement, not bound.
inline ComplexFill::ComplexFill() : BindIndex(~0u) {}

// Out of line in the exe; the gradient and bitmap fills call it.
// @0x14265a960
template Matrix2x4<float> Matrix2x4<float>::GetInverse() const;

}} // namespace Scaleform::Render

namespace Scaleform { void LogDebugMessage(LogMessageId id, const char* fmt, ...); }

namespace Scaleform {

// The set of the bind indices of the wrapping image fills.
// @0x1426589f0
template void HashSetBase<unsigned, FixedSizeHash<unsigned>, FixedSizeHash<unsigned>, AllocatorLH<unsigned, 2>,
                          HashsetCachedEntry<unsigned, FixedSizeHash<unsigned> > >::Add<unsigned>(void*,
                                                                                                   const unsigned&);
// @0x142658cb0
template void HashSetBase<unsigned, FixedSizeHash<unsigned>, FixedSizeHash<unsigned>, AllocatorLH<unsigned, 2>,
                          HashsetCachedEntry<unsigned, FixedSizeHash<unsigned> > >::add<unsigned>(void*,
                                                                                                   const unsigned&,
                                                                                                   UPInt);
// @0x14265d900
template void HashSetBase<unsigned, FixedSizeHash<unsigned>, FixedSizeHash<unsigned>, AllocatorLH<unsigned, 2>,
                          HashsetCachedEntry<unsigned, FixedSizeHash<unsigned> > >::setRawCapacity(void*, UPInt);
// @0x142659e40
template class FixedSizeHash<unsigned>;

// The style arrays of the reader.
// @0x142659c60
template ArrayDataBase<Render::FillStyleType, AllocatorGH<Render::FillStyleType, 0x103>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x142659cd0
template ArrayDataBase<Render::StrokeStyleType, AllocatorGH<Render::StrokeStyleType, 0x103>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x14265d560
template void ArrayDataBase<Render::FillStyleType, AllocatorGH<Render::FillStyleType, 0x103>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14265d600
template void ArrayDataBase<Render::StrokeStyleType, AllocatorGH<Render::StrokeStyleType, 0x103>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);

} // namespace Scaleform

namespace Scaleform { namespace GFx {

using Render::FillStyleType;
using Render::StrokeStyleType;
using Render::ShapePosInfo;

// Shape record trace of the parse channel.
// @0x14265ab80
template void LogBase<Stream>::LogParseShape(const char* pfmt, ...) const;

// The binding data shared by the readers of one file (allocated by the bind process, sfr_gfx_04).
struct TempBindData : public NewOverrideBase<Stat_Default_Mem>
{
    HashSetLH<unsigned> FillStyleImageWrap;
};

// SWF tags of the shapes with an extra edge bounds rectangle and the fonts in 1/20 twips.
enum
{
    ShapeSwfTag_DefineFont3  = 75,
    ShapeSwfTag_DefineShape4 = 83
};

// --------------------------------------------------------------------------------------------------------------------
// Walking the path records the reader left in the path allocator. The position packs the byte index, the two style
// index widths and the bit index, so that a reader can stop after any record and go on later.

struct SwfShapeDecoder
{
    StreamContext Stream;
    ShapePosInfo* Pos;

    // An edge as decoded: the control point (curves only) and the anchor, in absolute twips.
    struct Edge
    {
        int  Cx, Cy, Ax, Ay;
        bool Curve;
    };

    SF_NOINLINE SwfShapeDecoder(ShapePosInfo* pos, const UByte* pdata, float sfactor);
    ~SwfShapeDecoder()
    {
        Pos->Pos = (((((UInt32)Stream.CurByteIndex << 4) | (Pos->NumFillBits & 0xF)) << 4 | (Pos->NumStrokeBits & 0xF)) << 3) |
                   (Stream.CurBitIndex & 7);
    }

    bool IsEdgeNext() const { return (Stream.pData[Stream.CurByteIndex] & (1 << (7 - Stream.CurBitIndex))) != 0; }

    Render::PathEdgeType  ReadEdge(Edge* edge);
    Render::ShapePathType ReadNonEdgeRec(Render::ShapePathType retVal);
};

// The first decoder of a shape sets up the state: the style widths come from the start of the records, or from the
// packed position when the reader resumes from GetStartingPos. Later ones go on from the packed position.
// @0x1426598a0
SwfShapeDecoder::SwfShapeDecoder(ShapePosInfo* pos, const UByte* pdata, float sfactor) : Stream(pdata), Pos(pos)
{
    if (!Pos->Initialized)
    {
        Pos->Sfactor    = sfactor;
        Pos->StrokeBase = 0;
        Pos->FillBase   = 0;
        if (pos->Pos == 0)
        {
            Pos->NumFillBits   = Stream.ReadUInt4();
            Pos->NumStrokeBits = Stream.ReadUInt4();
        }
        else
        {
            Pos->NumFillBits   = (pos->Pos >> 7) & 0xF;
            Pos->NumStrokeBits = (pos->Pos >> 3) & 0xF;
            Stream.CurByteIndex       = pos->Pos >> 11;
            Stream.CurBitIndex        = pos->Pos & 7;
        }
        Pos->LastY       = 0;
        Pos->LastX       = 0;
        Pos->Stroke      = 0;
        Pos->Fill1       = 0;
        Pos->Fill0       = 0;
        Pos->Initialized = true;
    }
    else
    {
        Stream.CurByteIndex = pos->Pos >> 11;
        Stream.CurBitIndex  = pos->Pos & 7;
    }
}

// A curve or a line from the last point; lines are general or axis aligned.
// @0x14265c280
Render::PathEdgeType SwfShapeDecoder::ReadEdge(Edge* edge)
{
    bool typeFlag = Stream.ReadUInt1(); // the edge flag, known to be set
    SF_UNUSED(typeFlag);

    int edgeFlag = Stream.ReadUInt1();
    if (edgeFlag == 0)
    {
        unsigned numbits = 2 + Stream.ReadUInt4();

        int cx = Stream.ReadSInt(numbits);
        int cy = Stream.ReadSInt(numbits);
        int ax = Stream.ReadSInt(numbits);
        int ay = Stream.ReadSInt(numbits);

        edge->Cx = cx + Pos->LastX;
        edge->Cy = cy + Pos->LastY;
        Pos->LastX += cx + ax;
        Pos->LastY += cy + ay;
        edge->Ax    = Pos->LastX;
        edge->Ay    = Pos->LastY;
        edge->Curve = true;
        return Render::Edge_QuadTo;
    }
    else
    {
        unsigned numbits  = 2 + Stream.ReadUInt4();
        int      lineFlag = Stream.ReadUInt1();
        edge->Curve       = false;
        int dx = 0, dy = 0;
        if (lineFlag)
        {
            dx = Stream.ReadSInt(numbits);
            dy = Stream.ReadSInt(numbits);
        }
        else
        {
            int vertFlag = Stream.ReadUInt1();
            if (vertFlag == 0)
                dx = Stream.ReadSInt(numbits);
            else
                dy = Stream.ReadSInt(numbits);
        }

        edge->Ax = dx + Pos->LastX;
        edge->Ay = dy + Pos->LastY;
        Pos->LastX += dx;
        Pos->LastY += dy;
        return Render::Edge_LineTo;
    }
}

// A style change record: a move, new style indices (offset by the styles of the earlier layers) or a new set of
// styles, which the reader left behind as their 24-bit bases. retVal is passed on unless the record ends the shape or
// starts a layer.
// @0x14265c9a0
Render::ShapePathType SwfShapeDecoder::ReadNonEdgeRec(Render::ShapePathType retVal)
{
    do
    {
        bool typeFlag = Stream.ReadUInt1(); // the edge flag, known to be clear
        SF_UNUSED(typeFlag);

        int flags = Stream.ReadUInt5();
        if (flags == 0)
        {
            retVal = Render::Shape_EndShape;
            break;
        }
        if (flags & 0x01)
        {
            unsigned numMoveBits = Stream.ReadUInt5();
            Pos->LastX           = Stream.ReadSInt(numMoveBits);
            Pos->LastY           = Stream.ReadSInt(numMoveBits);
        }
        if ((flags & 0x02) && Pos->NumFillBits > 0)
        {
            unsigned style = Stream.ReadUInt(Pos->NumFillBits);
            if (style > 0)
                style += Pos->FillBase;
            Pos->Fill0 = style;
        }
        if ((flags & 0x04) && Pos->NumFillBits > 0)
        {
            int style = Stream.ReadUInt(Pos->NumFillBits);
            if (style > 0)
                style += Pos->FillBase;
            Pos->Fill1 = style;
        }
        if ((flags & 0x08) && Pos->NumStrokeBits > 0)
        {
            int style = Stream.ReadUInt(Pos->NumStrokeBits);
            if (style > 0)
                style += Pos->StrokeBase;
            Pos->Stroke = style;
        }
        if (flags & 0x10)
        {
            retVal = Render::Shape_NewLayer;

            Pos->Fill0 = Pos->Fill1 = Pos->Stroke = 0;

            Stream.Align();

            unsigned fsn = Stream.ReadU8();
            if (fsn != 0)
            {
                fsn = unsigned(Stream.ReadU8()) << 16;
                fsn |= unsigned(Stream.ReadU8()) << 8;
                fsn |= unsigned(Stream.ReadU8());
            }
            unsigned lsn = Stream.ReadU8();
            if (lsn == 0xFF)
            {
                lsn = unsigned(Stream.ReadU8()) << 16;
                lsn |= unsigned(Stream.ReadU8()) << 8;
                lsn |= unsigned(Stream.ReadU8());
            }
            Pos->FillBase   = fsn;
            Pos->StrokeBase = lsn;

            Pos->NumFillBits   = Stream.ReadUInt4();
            Pos->NumStrokeBits = Stream.ReadUInt4();
        }
        break;
    } while (0);
    return retVal;
}

// The next path: style changes up to its first edge, then its styles and start point.
// @0x14265d210
Render::ShapePathType ShapeDataBase::ReadPathInfo(ShapePosInfo* pos, float* coord, unsigned* styles) const
{
    SwfShapeDecoder       dec(pos, Paths, (Flags & Flags_Sfactor20) ? 1.0f / 20.0f : 1.0f);
    Render::ShapePathType ret = Render::Shape_NewPath;
    while (!dec.IsEdgeNext() && (ret = dec.ReadNonEdgeRec(ret)) != Render::Shape_EndShape)
        ;
    if (ret)
    {
        styles[0] = pos->Fill0;
        styles[1] = pos->Fill1;
        styles[2] = pos->Stroke;
        coord[0]  = pos->LastX * pos->Sfactor;
        coord[1]  = pos->LastY * pos->Sfactor;
    }
    return ret;
}

// The next edge of the path, scaled; the path ends at the first style change record.
// @0x14265c150
Render::PathEdgeType ShapeDataBase::ReadEdge(ShapePosInfo* pos, float* coord) const
{
    SwfShapeDecoder      dec(pos, Paths, (Flags & Flags_Sfactor20) ? 1.0f / 20.0f : 1.0f);
    Render::PathEdgeType ret = Render::Edge_EndPath;
    if (dec.IsEdgeNext())
    {
        SwfShapeDecoder::Edge edge;
        ret = dec.ReadEdge(&edge);
        if (ret == Render::Edge_QuadTo)
        {
            coord[0] = edge.Cx * pos->Sfactor;
            coord[1] = edge.Cy * pos->Sfactor;
            coord[2] = edge.Ax * pos->Sfactor;
            coord[3] = edge.Ay * pos->Sfactor;
        }
        else
        {
            coord[0] = edge.Ax * pos->Sfactor;
            coord[1] = edge.Ay * pos->Sfactor;
        }
    }
    return ret;
}

// --------------------------------------------------------------------------------------------------------------------
// Styles

// Reads one FILLSTYLE record into the style it was made for.
class FillStyleSwfReader
{
public:
    FillStyleType& FillStyle;

    FillStyleSwfReader(FillStyleType& fs) : FillStyle(fs) {}

    bool HasTextureFill() const { return FillStyle.pFill && (FillStyle.pFill->pImage || FillStyle.pFill->BindIndex != ~0u); }
    bool NeedsResolving() const { return FillStyle.pFill && FillStyle.pFill->BindIndex != ~0u; }
    void Read(LoadProcess* p, TagType tagType);

private:
    FillStyleSwfReader& operator=(const FillStyleSwfReader&);
};

// A solid colour, a gradient (its matrix maps the 32768-twip gradient square onto the unit square the renderer
// samples) or a bitmap. A bitmap that is not loaded yet keeps its bind index for the binding, and is remembered as
// wrapping for the repeating kinds; a missing one shows as the debug green.
// @0x14265adf0
void FillStyleSwfReader::Read(LoadProcess* p, TagType tagType)
{
    UInt8    type      = p->ReadU8();
    unsigned fillFlags = 0;

    p->LogParse("  FillStyle read type = 0x%X\n", type);

    if (type == 0x00)
    {
        Render::Color color;
        p->ReadRgbaTag(&color, tagType);
        p->LogParse("  color: ");
        p->GetStream()->LogParseClass(color);

        if (color.GetAlpha() < 255)
            fillFlags |= 0x1;

        FillStyle.Color = color.Raw;
        FillStyle.pFill = 0;
    }
    else if (type & 0x10)
    {
        Render::Matrix2F imageMatrix;
        p->GetStream()->ReadMatrix(&imageMatrix);

        Render::Matrix2F textureMatrix;
        if (type == 0x10)
        {
            textureMatrix.AppendScaling(1.0f / 32768.F);
            textureMatrix.AppendTranslation(0.5F, 0.F);
        }
        else
        {
            textureMatrix.AppendScaling(1.0f / 32768.F);
            textureMatrix.AppendTranslation(0.5F, 0.5F);
        }

        textureMatrix.Prepend(imageMatrix.GetInverse());

        UInt16 numGradients = p->ReadU8();
        if (numGradients & 0x10)
            fillFlags |= 0x2;
        numGradients &= 0xF;

        p->LogParse("  gradients: numGradients = %d\n", numGradients);

        FillStyle.pFill = *SF_NEW Render::ComplexFill();
        Render::GradientType gradType;
        switch (type)
        {
        case 0x10: gradType = Render::GradientLinear; break;
        case 0x12: gradType = Render::GradientRadial; break;
        case 0x13: gradType = Render::GradientFocalPoint; break;
        default:   gradType = Render::GradientLinear;
        }
        FillStyle.pFill->pGradient = *SF_NEW Render::GradientData(gradType, numGradients, (fillFlags & 0x2) != 0);

        for (int i = 0; i < numGradients; i++)
        {
            UInt8         ratio = p->ReadU8();
            Render::Color color;
            p->ReadRgbaTag(&color, tagType);

            FillStyle.pFill->pGradient->At(i).ColorV = color;
            FillStyle.pFill->pGradient->At(i).Ratio  = ratio;
            if (color.GetAlpha() < 255)
                fillFlags |= 0x1;
        }

        if (type == 0x13)
            FillStyle.pFill->pGradient->SetFocalRatio((float)(p->GetStream()->ReadS16()) / 256.0f);

        FillStyle.pFill->ImageMatrix = textureMatrix;
    }
    else if (type & 0x40)
    {
        ResourceId bitmapResourceId = ResourceId(p->ReadU16());
        p->LogParse("  BitmapChar = %d\n", bitmapResourceId.GetIdIndex());

        Render::Matrix2F imageMatrix;
        p->GetStream()->ReadMatrix(&imageMatrix);

        fillFlags |= 0x1;
        p->GetStream()->LogParseClass(imageMatrix);

        ResourceHandle imageRes;
        Render::ImageBase* pimage = 0;
        Render::Matrix2F textureMatrix(imageMatrix.GetInverse());
        FillStyle.pFill              = *SF_NEW Render::ComplexFill();
        FillStyle.pFill->ImageMatrix = textureMatrix;
        switch (type)
        {
        case 0x40: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Repeat | Render::Sample_Linear); break;
        case 0x42: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Repeat | Render::Sample_Linear); break;
        case 0x41: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Clamp | Render::Sample_Linear); break;
        case 0x43: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Clamp | Render::Sample_Linear); break;
        }

        if (!p->GetResourceHandle(&imageRes, bitmapResourceId) || !imageRes.GetResourcePtr())
        {
            FillStyle.Color = 0xFFA7DD39;

            if (imageRes.IsIndex())
            {
                FillStyle.pFill->BindIndex = imageRes.GetBindIndex();
                TempBindData* bd           = (TempBindData*)p->GetTempBindData();
                if (bd && (type == 0x40 || type == 0x42))
                    bd->FillStyleImageWrap.Add(FillStyle.pFill->BindIndex);
            }
            else
            {
                FillStyle.pFill = 0;
                if (bitmapResourceId.GetIdValue() != 0xFFFF)
                {
                    LogDebugMessage(Log_Warning, "An image with resource id %d is not found in resource table.",
                                    bitmapResourceId.GetIdValue());
                }
            }
        }
        else
        {
            if (imageRes.GetResourcePtr() && imageRes.GetResourcePtr()->GetResourceType() == Resource::RT_Image)
            {
                pimage = static_cast<ImageResource*>(imageRes.GetResourcePtr())->GetImage();
                FillStyle.pFill->pImage = pimage;
            }
        }
    }
}

// Reads one LINESTYLE / LINESTYLE2 record into the style it was made for.
class StrokeStyleSwfReader
{
public:
    StrokeStyleType& StrokeStyle;

    StrokeStyleSwfReader(StrokeStyleType& ss) : StrokeStyle(ss) {}

    bool HasTextureFill() const { return StrokeStyle.pFill && (StrokeStyle.pFill->pImage || StrokeStyle.pFill->BindIndex != ~0u); }
    bool NeedsResolving() const { return StrokeStyle.pFill && StrokeStyle.pFill->BindIndex != ~0u; }
    void Read(LoadProcess* p, TagType tagType);

private:
    StrokeStyleSwfReader& operator=(const StrokeStyleSwfReader&);
};

// ConvertSwfLineStyles, as the stroke reader has it inlined.
static SF_FORCEINLINE unsigned SwfLineStyleFlags(unsigned swfFlags)
{
    unsigned flags = 0;
    if (swfFlags & 0x001) flags |= 0x001;
    if (swfFlags & 0x002) flags |= 0x002;
    if (swfFlags & 0x004) flags |= 0x004;
    if ((swfFlags & 0x006) == 0x006) flags = 0x006;
    if (swfFlags & 0x010) flags |= 0x010;
    if (swfFlags & 0x020) flags |= 0x020;
    if (swfFlags & 0x040) flags |= 0x040;
    if (swfFlags & 0x080) flags |= 0x080;
    if (swfFlags & 0x100) flags |= 0x100;
    if (swfFlags & 0x200) flags |= 0x200;
    if (swfFlags & 0x008) flags |= 0x008;
    return flags;
}

// The width in twips; DefineShape4 adds the style flags, the miter limit and, instead of the colour, a fill (whose
// first gradient colour stands in as the colour).
// @0x14265bf10
void StrokeStyleSwfReader::Read(LoadProcess* p, TagType tagType)
{
    unsigned width    = p->ReadU16();
    float  miter      = 3.0f;
    UInt16 styleFlags = 0;
    if (tagType == ShapeSwfTag_DefineShape4)
    {
        styleFlags = p->ReadU16();
        if (styleFlags & 0x20)
            miter = p->ReadU16() / 256.0f;
    }
    unsigned flags = SwfLineStyleFlags(styleFlags);

    if (flags & 0x08)
    {
        FillStyleType fill;
        FillStyleSwfReader(fill).Read(p, tagType);
        StrokeStyle.Color = fill.Color;
        StrokeStyle.Miter = miter;
        StrokeStyle.Width = (float)width;
        StrokeStyle.pFill = fill.pFill;
        if (!fill.pFill)
            StrokeStyle.Color = fill.Color;
        else if (fill.pFill->pGradient && fill.pFill->pGradient->GetRecordCount() > 0)
            StrokeStyle.Color = fill.pFill->pGradient->At(0).ColorV.Raw;
    }
    else
    {
        Render::Color color;
        p->ReadRgbaTag(&color, tagType);
        StrokeStyle.Color = color.Raw;
        StrokeStyle.Miter = miter;
        StrokeStyle.pFill = 0;
        StrokeStyle.Width = (float)width;
    }
    StrokeStyle.Units = 0.05f;
    StrokeStyle.Flags = flags;
}

// --------------------------------------------------------------------------------------------------------------------
// ShapeSwfReader

// The stream the style records are read from (the shape's own while its records are walked).
static SF_FORCEINLINE Stream* StyleStream(LoadProcess* p)
{
    return p->GetStream();
}

// A FILLSTYLEARRAY appended to the fill styles; the shape notes image fills and fills still to be bound. Returns the
// stream position after the count.
// @0x14265c730
int ShapeSwfReader::ReadFillStyles(LoadProcess* p, TagType tagType)
{
    unsigned count = p->ReadU8();
    if (tagType > Tag_DefineShape2 - 20 && count == 0xFF)
        count = p->ReadU16();
    int stylesPos = p->Tell();
    p->LogParse("  GFx_ReadFillStyles: count = %d\n", count);

    unsigned base = (unsigned)FillStyles.GetSize();
    if (count)
        FillStyles.Resize(base + count);
    for (unsigned i = 0; i < count; i++)
    {
        StyleStream(p)->Align();
        FillStyleSwfReader reader(FillStyles[base + i]);
        reader.Read(p, tagType);
        if (reader.HasTextureFill())
            Shape.Flags |= ShapeDataBase::Flags_TexturedFill;
        if (reader.NeedsResolving())
            Shape.Flags |= ShapeDataBase::Flags_NeedsResolving;
    }
    return stylesPos;
}

// A LINESTYLEARRAY appended to the stroke styles, as ReadFillStyles.
// @0x14265d320
int ShapeSwfReader::ReadStrokeStyles(LoadProcess* p, TagType tagType)
{
    unsigned count = p->ReadU8();
    p->LogParse("  GFx_ReadStrokeStyles: count = %d\n", count);
    if (count == 0xFF)
    {
        count = p->ReadU16();
        p->LogParse("  GFx_ReadStrokeStyles: count2 = %d\n", count);
    }
    int stylesPos = p->Tell();

    unsigned base = (unsigned)StrokeStyles.GetSize();
    StrokeStyles.Resize(base + count);
    for (unsigned i = 0; i < count; i++)
    {
        StyleStream(p)->Align();
        StrokeStyleSwfReader reader(StrokeStyles[base + i]);
        reader.Read(p, tagType);
        if (reader.HasTextureFill())
            Shape.Flags |= ShapeDataBase::Flags_TexturedFill;
        if (reader.NeedsResolving())
            Shape.Flags |= ShapeDataBase::Flags_NeedsResolving;
    }
    return stylesPos;
}

// The tag's styles go to the style arrays and its path records to one block of the path allocator. The records are
// walked once to check them: the styles of a new layer are parsed into the arrays too, and their bytes in the block
// are replaced by the bases the decoder expects. Records that run out of the tag, or more than 2 MB of them, leave an
// empty shape and a warning.
// MS2-FUNCTIONAL: one lea operand order differs (moveY + (ay + cy) in the curved-edge log); source order and first-reference swaps did not move it.
// @0x14265b620
bool ShapeSwfReader::Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle)
{
    PathAllocator* ppathAllocator = pAllocator ? pAllocator : p->GetLoadTaskData()->GetPathAllocator();
    Stream*        in             = p->GetStream();

    Shape.Flags = 0;
    int stylesLen;
    if (withStyle)
    {
        int curOffset = in->Tell();
        Shape.Flags |= ShapeDataBase::Flags_ValidBounds;
        RectF bounds(0, 0, 0, 0);
        in->ReadRect(&bounds);
        if ((tagType == ShapeSwfTag_DefineShape4) || (tagType == ShapeSwfTag_DefineFont3))
        {
            // The edge bounds and the fill rule flags of DefineShape4 are not kept.
            RectF rectBound(0, 0, 0, 0);
            in->ReadRect(&rectBound);
            in->ReadU8();
        }
        ReadFillStyles(p, tagType);
        ReadStrokeStyles(p, tagType);
        stylesLen = in->Tell() - curOffset;
    }
    else
        stylesLen = 0;

    unsigned shapeLen         = (unsigned)lenInBytes - stylesLen;
    unsigned memBlockSize     = shapeLen;
    unsigned originalShapeLen = shapeLen;

    UByte* pmemBlock = ppathAllocator->AllocRawPath(memBlockSize);
    if (!pmemBlock)
    {
        in->LogWarning("Corrupted shape detected in file %s", in->GetFileName().ToCStr());
        return false;
    }
    UByte* ptr = pmemBlock;

    in->Align();
    in->ReadToBuffer(ptr, shapeLen);

    float sfactor = 1.0f;
    if (tagType == ShapeSwfTag_DefineFont3)
    {
        sfactor = 1.0f / 20.0f;
        Shape.Flags |= ShapeDataBase::Flags_Sfactor20;
    }

    Stream* poriginalStream = in;
    Stream  ss(ptr, shapeLen, p->GetLoadHeap(), in->GetLog(), in->GetParseControl());
    in = &ss;
    p->SetAltStream(in);

    in->Align();
    int numFillBits = in->ReadUInt(4);
    int numLineBits = in->ReadUInt(4);
    if (withStyle)
        in->LogParse("  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n", numFillBits, numLineBits);

    int      fillBase = 0;
    int      lineBase = 0;
    int      moveX = 0, moveY = 0;
    int      numMoveBits      = 0;
    unsigned totalPathsCount  = 0;
    unsigned totalShapesCount = 0;
    int      curEdgesCount    = 0;
    int      curPathsCount    = 0;
    bool     shapeIsCorrupted = false;

    while (!shapeIsCorrupted)
    {
        int typeFlag = in->ReadUInt1();
        if (typeFlag == 0)
        {
            int flags = in->ReadUInt(5);
            if (flags == 0)
            {
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }
                break;
            }
            if (flags & 0x01)
            {
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }
                numMoveBits = in->ReadUInt(5);
                moveX       = in->ReadSInt(numMoveBits);
                moveY       = in->ReadSInt(numMoveBits);
                if (in->IsVerboseParseShape())
                    in->LogParseShape("  ShapeCharacter read: moveto %4g %4g\n", (float)moveX * sfactor,
                                      (float)moveY * sfactor);
            }
            if ((flags & 0x02) && numFillBits > 0)
            {
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }
                int style = in->ReadUInt(numFillBits);
                if (in->IsVerboseParseShape())
                {
                    if (style > 0)
                    {
                        style += fillBase;
                    }
                    in->LogParseShape("  ShapeCharacter read: fill0 = %d\n", style);
                }
            }
            if ((flags & 0x04) && numFillBits > 0)
            {
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }
                int style = in->ReadUInt(numFillBits);
                if (in->IsVerboseParseShape())
                {
                    if (style > 0)
                    {
                        style += fillBase;
                    }
                    in->LogParseShape("  ShapeCharacter read: fill1 = %d\n", style);
                }
            }
            if ((flags & 0x08) && numLineBits > 0)
            {
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }
                int style = in->ReadUInt(numLineBits);
                if (style > 0)
                {
                    style += lineBase;
                }
                if (in->IsVerboseParseShape())
                    in->LogParseShape("  ShapeCharacter read: line = %d\n", style);
            }
            if (flags & 0x10)
            {
                in->LogParse("  ShapeCharacter read: more fill styles\n");
                if (curPathsCount > 0)
                {
                    ++totalShapesCount;
                    curPathsCount = 0;
                }
                if (curEdgesCount > 0)
                {
                    ++totalPathsCount;
                    curEdgesCount = 0;
                    ++curPathsCount;
                }

                fillBase  = (int)FillStyles.GetSize();
                lineBase  = (int)StrokeStyles.GetSize();
                int fsoff = in->Tell();
                int foff  = ReadFillStyles(p, tagType);
                int moff  = in->Tell();
                int loff  = ReadStrokeStyles(p, tagType);
                int eoff  = in->Tell();

                if (moff != foff)
                {
                    if (foff > moff || unsigned(moff) > originalShapeLen)
                    {
                        shapeIsCorrupted = true;
                        break;
                    }
                    else
                    {
                        // An added fill style array stores its base: 0xFF and the 24-bit index.
                        if ((int)FillStyles.GetSize() > fillBase)
                        {
                            *(ptr + fsoff)     = 0xFF;
                            *(ptr + fsoff + 1) = UByte((fillBase >> 16) & 0xFF);
                            *(ptr + fsoff + 2) = UByte((fillBase >> 8) & 0xFF);
                            *(ptr + fsoff + 3) = UByte((fillBase) & 0xFF);
                            foff += 4 - (foff - fsoff);
                        }
                        memmove(ptr + foff, ptr + moff, loff - moff);
                        loff -= moff - foff;
                        moff = foff;
                    }
                }
                if (loff != eoff)
                {
                    if (loff > eoff || unsigned(eoff) > originalShapeLen)
                    {
                        shapeIsCorrupted = true;
                        break;
                    }
                    else
                    {
                        if ((int)StrokeStyles.GetSize() > lineBase)
                        {
                            *(ptr + moff)     = 0xFF;
                            *(ptr + moff + 1) = UByte((lineBase >> 16) & 0xFF);
                            *(ptr + moff + 2) = UByte((lineBase >> 8) & 0xFF);
                            *(ptr + moff + 3) = UByte((lineBase) & 0xFF);
                            loff += 4 - (loff - moff);
                        }
                        memmove(ptr + loff, ptr + eoff, shapeLen - eoff);
                        shapeLen -= eoff - loff;
                    }
                }
                in->SetPosition(loff);
                numFillBits = in->ReadUInt(4);
                numLineBits = in->ReadUInt(4);
            }
        }
        else
        {
            int edgeFlag = in->ReadUInt1();
            ++curEdgesCount;

            if (edgeFlag == 0)
            {
                unsigned numbits = 2 + in->ReadUInt(4);
                int      cx      = in->ReadSInt(numbits);
                int      cy      = in->ReadSInt(numbits);
                int      ax      = in->ReadSInt(numbits);
                int      ay      = in->ReadSInt(numbits);
                if (in->IsVerboseParseShape())
                {
                    in->LogParseShape("  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n",
                                      (float)moveX * sfactor, (float)moveY * sfactor, (float)(moveX + cx) * sfactor,
                                      (float)(moveY + cy) * sfactor, (float)(moveX + cx + ax) * sfactor,
                                      (float)(moveY + cy + ay) * sfactor);
                }
                moveX += ax + cx;
                moveY += ay + cy;
            }
            else
            {
                unsigned numbits  = 2 + in->ReadUInt(4);
                int      lineFlag = in->ReadUInt1();
                int      dx = 0, dy = 0;
                if (lineFlag)
                {
                    dx = in->ReadSInt(numbits);
                    dy = in->ReadSInt(numbits);
                }
                else
                {
                    int vertFlag = in->ReadUInt1();
                    if (vertFlag == 0)
                    {
                        dx = in->ReadSInt(numbits);
                    }
                    else
                    {
                        dy = in->ReadSInt(numbits);
                    }
                }
                if (in->IsVerboseParseShape())
                {
                    in->LogParseShape("  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n",
                                      (float)moveX * sfactor, (float)moveY * sfactor, (float)(moveX + dx) * sfactor,
                                      (float)(moveY + dy) * sfactor);
                }
                moveX += dx;
                moveY += dy;
            }
        }
        shapeIsCorrupted = ((unsigned)in->Tell() > originalShapeLen);
    }

    // The styles moved out of the records shrink the block.
    unsigned newMemBlockSize = memBlockSize - (originalShapeLen - shapeLen);
    if (!shapeIsCorrupted && newMemBlockSize < (1L << 21))
    {
        if (memBlockSize > newMemBlockSize)
        {
            ppathAllocator->ReallocLastBlock(pmemBlock, memBlockSize, newMemBlockSize);
        }
    }
    else
    {
        shapeIsCorrupted = true;
        in->LogWarning("Corrupted shape detected in file %s", poriginalStream->GetFileName().ToCStr());
        unsigned offset          = 0;
        unsigned newMemBlockSize = 1 + 1;
        pmemBlock[offset++]      = 0;
        pmemBlock[offset++]      = 0;
        if (memBlockSize > newMemBlockSize)
        {
            ppathAllocator->ReallocLastBlock(pmemBlock, memBlockSize, newMemBlockSize);
        }
    }
    Shape.Paths = pmemBlock;
    p->SetAltStream(NULL);
    return !shapeIsCorrupted;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
