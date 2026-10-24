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

struct SwfShapeDecoder : public StreamContext
{
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
        Pos->Pos = (((((UInt32)CurByteIndex << 4) | (Pos->NumFillBits & 0xF)) << 4 | (Pos->NumStrokeBits & 0xF)) << 3) |
                   (CurBitIndex & 7);
    }

    bool IsEdgeNext() const { return (pData[CurByteIndex] & (1 << (7 - CurBitIndex))) != 0; }

    Render::PathEdgeType  ReadEdge(Edge* pedge);
    Render::ShapePathType ReadNonEdgeRec(Render::ShapePathType retVal);
};

// The first decoder of a shape sets up the state: the style widths come from the start of the records, or from the
// packed position when the reader resumes from GetStartingPos. Later ones go on from the packed position.
// MS2-FUNCTIONAL: load order and register allocation differ.
// @0x1426598a0
SwfShapeDecoder::SwfShapeDecoder(ShapePosInfo* pos, const UByte* pdata, float sfactor) : StreamContext(pdata), Pos(pos)
{
    if (!Pos->Initialized)
    {
        Pos->Sfactor    = sfactor;
        Pos->StrokeBase = 0;
        Pos->FillBase   = 0;
        if (pos->Pos == 0)
        {
            Pos->NumFillBits   = ReadUInt4();
            Pos->NumStrokeBits = ReadUInt4();
        }
        else
        {
            Pos->NumFillBits   = (pos->Pos >> 7) & 0xF;
            Pos->NumStrokeBits = (pos->Pos >> 3) & 0xF;
            CurByteIndex       = pos->Pos >> 11;
            CurBitIndex        = pos->Pos & 7;
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
        CurByteIndex = pos->Pos >> 11;
        CurBitIndex  = pos->Pos & 7;
    }
}

// A curve or a line from the last point; lines are general or axis aligned.
// MS2-FUNCTIONAL: load order and register allocation differ.
// @0x14265c280
Render::PathEdgeType SwfShapeDecoder::ReadEdge(Edge* pedge)
{
    ReadUInt1(); // the edge flag, known to be set
    unsigned straight = ReadUInt1();
    if (!straight)
    {
        unsigned nbits = ReadUInt4() + 2;
        int      cx    = ReadSInt(nbits);
        int      cy    = ReadSInt(nbits);
        int      ax    = ReadSInt(nbits);
        int      ay    = ReadSInt(nbits);
        pedge->Cx      = Pos->LastX + cx;
        pedge->Cy      = Pos->LastY + cy;
        Pos->LastX += cx + ax;
        Pos->LastY += cy + ay;
        pedge->Ax    = Pos->LastX;
        pedge->Ay    = Pos->LastY;
        pedge->Curve = true;
        return Render::Edge_QuadTo;
    }

    unsigned nbits   = ReadUInt4() + 2;
    unsigned general = ReadUInt1();
    pedge->Curve     = false;
    int dx = 0, dy = 0;
    if (general)
    {
        dx = ReadSInt(nbits);
        dy = ReadSInt(nbits);
    }
    else
    {
        unsigned vertical = ReadUInt1();
        int      d        = ReadSInt(nbits);
        if (vertical)
            dy = d;
        else
            dx = d;
    }
    pedge->Ax = Pos->LastX + dx;
    pedge->Ay = Pos->LastY + dy;
    Pos->LastX += dx;
    Pos->LastY += dy;
    return Render::Edge_LineTo;
}

// A style change record: a move, new style indices (offset by the styles of the earlier layers) or a new set of
// styles, which the reader left behind as their 24-bit bases. retVal is passed on unless the record ends the shape or
// starts a layer.
// MS2-FUNCTIONAL: load order and register allocation differ.
// @0x14265c9a0
Render::ShapePathType SwfShapeDecoder::ReadNonEdgeRec(Render::ShapePathType retVal)
{
    ReadUInt1(); // the edge flag, known to be clear
    unsigned flags = ReadUInt5();
    if (flags == 0)
        return Render::Shape_EndShape;

    if (flags & 0x01)
    {
        unsigned nbits = ReadUInt5();
        Pos->LastX     = ReadSInt(nbits);
        Pos->LastY     = ReadSInt(nbits);
    }
    if ((flags & 0x02) && Pos->NumFillBits)
    {
        unsigned style = ReadUInt(Pos->NumFillBits);
        if (style)
            style += Pos->FillBase;
        Pos->Fill0 = style;
    }
    if ((flags & 0x04) && Pos->NumFillBits)
    {
        int style = ReadUInt(Pos->NumFillBits);
        if (style > 0)
            style += Pos->FillBase;
        Pos->Fill1 = style;
    }
    if ((flags & 0x08) && Pos->NumStrokeBits)
    {
        int style = ReadUInt(Pos->NumStrokeBits);
        if (style > 0)
            style += Pos->StrokeBase;
        Pos->Stroke = style;
    }
    if (flags & 0x10)
    {
        Pos->Stroke = 0;
        Pos->Fill1  = 0;
        Pos->Fill0  = 0;
        Align();
        unsigned fillBase = ReadU8();
        if (fillBase != 0)
        {
            fillBase = ReadU8() << 16;
            fillBase |= ReadU8() << 8;
            fillBase |= ReadU8();
        }
        unsigned strokeBase = ReadU8();
        if (strokeBase == 0xFF)
        {
            strokeBase = ReadU8() << 16;
            strokeBase |= ReadU8() << 8;
            strokeBase |= ReadU8();
        }
        Pos->FillBase      = fillBase;
        Pos->StrokeBase    = strokeBase;
        Pos->NumFillBits   = ReadUInt4();
        Pos->NumStrokeBits = ReadUInt4();
        return Render::Shape_NewLayer;
    }
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
    void Read(LoadProcess* p, TagType tagType);

private:
    FillStyleSwfReader& operator=(const FillStyleSwfReader&);
};

// A solid colour, a gradient (its matrix maps the 32768-twip gradient square onto the unit square the renderer
// samples) or a bitmap. A bitmap that is not loaded yet keeps its bind index for the binding, and is remembered as
// wrapping for the repeating kinds; a missing one shows as the debug green.
// MS2-FUNCTIONAL: register allocation and the inlined HashSet::Add / ComplexFill setup differ.
// @0x14265adf0
void FillStyleSwfReader::Read(LoadProcess* p, TagType tagType)
{
    unsigned type = p->ReadU8();
    p->LogParse("  FillStyle read type = 0x%X\n", type);

    if (type == 0x00)
    {
        Render::Color color;
        p->ReadRgbaTag(&color, tagType);
        p->LogParse("  color: ");
        p->GetStream()->LogParseClass(color);
        FillStyle.Color = color.Raw;
        FillStyle.pFill = 0;
    }
    else if (type & 0x10)
    {
        Render::Matrix2F matrix;
        p->GetStream()->ReadMatrix(&matrix);

        Render::Matrix2F gradientMatrix;
        gradientMatrix.AppendScaling(1.0f / 32768.0f);
        gradientMatrix.Tx() += 0.5f;
        gradientMatrix.Ty() += (type == 0x10) ? 0.0f : 0.5f;
        gradientMatrix.Prepend(matrix.GetInverse());

        unsigned spec         = p->ReadU8();
        UInt16   linearRGB    = (UInt16)(spec & 0x10);
        UInt16   numGradients = (UInt16)(spec & 0xF);
        p->LogParse("  gradients: numGradients = %d\n", numGradients);

        FillStyle.pFill = *SF_NEW Render::ComplexFill();
        Render::GradientType gradType;
        switch (type)
        {
        case 0x12: gradType = Render::GradientRadial; break;
        case 0x13: gradType = Render::GradientFocalPoint; break;
        default:   gradType = Render::GradientLinear; break;
        }
        FillStyle.pFill->pGradient = *SF_NEW Render::GradientData(gradType, numGradients, linearRGB != 0);

        for (int i = 0; i < numGradients; i++)
        {
            UByte         ratio = p->ReadU8();
            Render::Color color;
            p->ReadRgbaTag(&color, tagType);
            FillStyle.pFill->pGradient->At(i).ColorV = color;
            FillStyle.pFill->pGradient->At(i).Ratio  = ratio;
        }
        if (type == 0x13)
            FillStyle.pFill->pGradient->SetFocalRatio((SInt16)p->ReadU16() / 256.0f);

        FillStyle.pFill->ImageMatrix = gradientMatrix;
    }
    else if (type & 0x40)
    {
        UInt16 bitmapId = p->ReadU16();
        p->LogParse("  BitmapChar = %d\n", bitmapId);

        Render::Matrix2F matrix;
        p->GetStream()->ReadMatrix(&matrix);
        p->GetStream()->LogParseClass(matrix);

        ResourceHandle   handle;
        Render::Matrix2F imageMatrix = matrix.GetInverse();

        FillStyle.pFill              = *SF_NEW Render::ComplexFill();
        FillStyle.pFill->ImageMatrix = imageMatrix;
        switch (type)
        {
        case 0x40:
        case 0x42: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Repeat | Render::Sample_Linear); break;
        case 0x41:
        case 0x43: FillStyle.pFill->FillMode.Fill = UByte(Render::Wrap_Clamp | Render::Sample_Linear); break;
        }

        if (p->GetResourceHandle(&handle, ResourceId(bitmapId)) && handle.GetResourcePtr())
        {
            Resource* pres = handle.GetResourcePtr();
            if (pres->GetResourceType() == Resource::RT_Image)
                FillStyle.pFill->pImage = static_cast<ImageResource*>(pres)->GetImage();
        }
        else
        {
            FillStyle.Color = 0xFFA7DD39;
            if (handle.IsIndex())
            {
                FillStyle.pFill->BindIndex = handle.GetBindIndex();
                TempBindData* pbindData    = (TempBindData*)p->GetTempBindData();
                if (pbindData && (type == 0x40 || type == 0x42))
                    pbindData->FillStyleImageWrap.Add(FillStyle.pFill->BindIndex);
            }
            else
            {
                FillStyle.pFill = 0;
                if (bitmapId != 0xFFFF)
                    LogDebugMessage(Log_Warning, "An image with resource id %d is not found in resource table.",
                                    bitmapId);
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
// MS2-FUNCTIONAL: register allocation and the inlined Array::Resize differ; LoadProcess::ReadU16 is inline here.
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
    {
        FillStyles.Resize(base + count);
        for (unsigned i = 0; i < count; i++)
        {
            StyleStream(p)->Align();
            FillStyleSwfReader reader(FillStyles[base + i]);
            reader.Read(p, tagType);
            Render::ComplexFill* pfill = reader.FillStyle.pFill;
            if (pfill && (pfill->pImage || pfill->BindIndex != ~0u))
                Shape.Flags |= ShapeDataBase::Flags_TexturedFill;
            pfill = reader.FillStyle.pFill;
            if (pfill && pfill->BindIndex != ~0u)
                Shape.Flags |= ShapeDataBase::Flags_NeedsResolving;
        }
    }
    return stylesPos;
}

// A LINESTYLEARRAY appended to the stroke styles, as ReadFillStyles.
// MS2-FUNCTIONAL: register allocation and the inlined Array::Resize differ; LoadProcess::ReadU16 is inline here.
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
        Render::ComplexFill* pfill = reader.StrokeStyle.pFill;
        if (pfill && (pfill->pImage || pfill->BindIndex != ~0u))
            Shape.Flags |= ShapeDataBase::Flags_TexturedFill;
        pfill = reader.StrokeStyle.pFill;
        if (pfill && pfill->BindIndex != ~0u)
            Shape.Flags |= ShapeDataBase::Flags_NeedsResolving;
    }
    return stylesPos;
}

// Marks the styles of a new layer in the path records: 0xFF and the 24-bit index of its first style.
static SF_FORCEINLINE void PutStyleBase(UByte* pdest, int base)
{
    pdest[1] = UByte(base >> 16);
    pdest[2] = UByte(base >> 8);
    pdest[0] = 0xFF;
    pdest[3] = UByte(base);
}

// The tag's styles go to the style arrays and its path records to one block of the path allocator. The records are
// walked once to check them: the styles of a new layer are parsed into the arrays too, and their bytes in the block
// are replaced by the bases the decoder expects. Records that run out of the tag, or more than 2 MB of them, leave an
// empty shape and a warning.
// MS2-FUNCTIONAL: register allocation and spills differ; the counters of the record walk are kept as in the exe.
// @0x14265b620
bool ShapeSwfReader::Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle)
{
    PathAllocator* pallocator = pAllocator ? pAllocator : p->GetLoadTaskData()->GetPathAllocator();
    Stream*        in         = p->GetStream();

    Shape.Flags   = 0;
    int stylesLen = 0;
    if (withStyle)
    {
        int startPos = in->Tell();
        Shape.Flags |= ShapeDataBase::Flags_ValidBounds;
        RectF bound(0, 0, 0, 0);
        in->ReadRect(&bound);
        if (tagType == ShapeSwfTag_DefineFont3 || tagType == ShapeSwfTag_DefineShape4)
        {
            // The edge bounds and the fill rule flags of DefineShape4 are not kept.
            RectF edgeBound(0, 0, 0, 0);
            in->ReadRect(&edgeBound);
            in->ReadU8();
        }
        ReadFillStyles(p, tagType);
        ReadStrokeStyles(p, tagType);
        stylesLen = in->Tell() - startPos;
    }

    unsigned pathsLen  = lenInBytes - stylesLen;
    unsigned readLen   = pathsLen;
    unsigned dataLen   = pathsLen;
    unsigned allocLen  = pathsLen;
    unsigned shapeSize = pathsLen;
    UByte*   pmem      = pallocator->AllocRawPath(pathsLen);
    if (!pmem)
    {
        in->LogWarning("Corrupted shape detected in file %s", in->GetFileName().ToCStr());
        return false;
    }
    in->Align();
    in->ReadToBuffer(pmem, pathsLen);

    float sfactor = 1.0f;
    if (tagType == ShapeSwfTag_DefineFont3)
    {
        sfactor = 1.0f / 20.0f;
        Shape.Flags |= ShapeDataBase::Flags_Sfactor20;
    }

    Stream ss(pmem, pathsLen, p->GetLoadHeap(), in->GetLog(), in->GetParseControl());
    ss.Align();
    p->SetAltStream(&ss);

    int numFillBits   = ss.ReadUInt(4);
    int numStrokeBits = ss.ReadUInt(4);
    if (withStyle)
        ss.LogParse("  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n", numFillBits, numStrokeBits);

    int  fillBase = 0, strokeBase = 0;
    int  numEdges = 0, numPaths = 0;
    int  x = 0, y = 0;
    bool corrupted = false;
    for (;;)
    {
        if (!ss.ReadUInt1())
        {
            unsigned flags = ss.ReadUInt(5);
            if (flags == 0)
                break;

            if (flags & 0x01)
            {
                if (numEdges > 0)
                {
                    ++numPaths;
                    numEdges = 0;
                }
                int nbits = ss.ReadUInt(5);
                x         = ss.ReadSInt(nbits);
                y         = ss.ReadSInt(nbits);
                if (ss.IsVerboseParseShape())
                    ss.LogParseShape("  ShapeCharacter read: moveto %4g %4g\n", x * sfactor, y * sfactor);
            }
            if ((flags & 0x02) && numFillBits > 0)
            {
                if (numEdges > 0)
                {
                    ++numPaths;
                    numEdges = 0;
                }
                int style = ss.ReadUInt(numFillBits);
                if (ss.IsVerboseParseShape())
                {
                    if (style > 0)
                        style += fillBase;
                    ss.LogParseShape("  ShapeCharacter read: fill0 = %d\n", style);
                }
            }
            if ((flags & 0x04) && numFillBits > 0)
            {
                if (numEdges > 0)
                {
                    ++numPaths;
                    numEdges = 0;
                }
                int style = ss.ReadUInt(numFillBits);
                if (ss.IsVerboseParseShape())
                {
                    if (style > 0)
                        style += fillBase;
                    ss.LogParseShape("  ShapeCharacter read: fill1 = %d\n", style);
                }
            }
            if ((flags & 0x08) && numStrokeBits > 0)
            {
                if (numEdges > 0)
                {
                    ++numPaths;
                    numEdges = 0;
                }
                int style = ss.ReadUInt(numStrokeBits);
                if (style > 0)
                    style += strokeBase;
                if (ss.IsVerboseParseShape())
                    ss.LogParseShape("  ShapeCharacter read: line = %d\n", style);
            }
            if (flags & 0x10)
            {
                ss.LogParse("  ShapeCharacter read: more fill styles\n");
                if (numPaths > 0)
                    numPaths = 0;
                if (numEdges > 0)
                {
                    ++numPaths;
                    numEdges = 0;
                }
                fillBase      = (int)FillStyles.GetSize();
                strokeBase    = (int)StrokeStyles.GetSize();
                int recordPos = ss.Tell();

                int fillsStart   = ReadFillStyles(p, tagType);
                int fillsEnd     = ss.Tell();
                int strokesStart = ReadStrokeStyles(p, tagType);
                int strokesEnd   = ss.Tell();

                // The fill styles become their base.
                if (fillsEnd != fillsStart)
                {
                    if (fillsEnd < fillsStart || (unsigned)fillsEnd > shapeSize)
                        goto corrupted_shape;
                    int dest = recordPos;
                    if ((int)FillStyles.GetSize() > fillBase)
                    {
                        PutStyleBase(pmem + dest, fillBase);
                        dest += 4;
                    }
                    memmove(pmem + dest, pmem + fillsEnd, strokesStart - fillsEnd);
                    strokesStart = dest + (strokesStart - fillsEnd);
                    fillsEnd     = dest;
                }
                // The stroke styles too, with the rest of the records moved up.
                if (strokesStart != strokesEnd)
                {
                    if (strokesStart > strokesEnd || (unsigned)strokesEnd > shapeSize)
                        goto corrupted_shape;
                    if ((int)StrokeStyles.GetSize() > strokeBase)
                    {
                        PutStyleBase(pmem + fillsEnd, strokeBase);
                        strokesStart = fillsEnd + 4;
                    }
                    memmove(pmem + strokesStart, pmem + strokesEnd, dataLen - strokesEnd);
                    dataLen += strokesStart - strokesEnd;
                }
                ss.SetPosition(strokesStart);
                numFillBits   = ss.ReadUInt(4);
                numStrokeBits = ss.ReadUInt(4);
            }
        }
        else
        {
            ++numEdges;
            unsigned straight = ss.ReadUInt1();
            int      nbits    = ss.ReadUInt(4) + 2;
            if (!straight)
            {
                int cx = ss.ReadSInt(nbits);
                int cy = ss.ReadSInt(nbits);
                int ax = ss.ReadSInt(nbits);
                int ay = ss.ReadSInt(nbits);
                int nx = x + cx + ax;
                int ny = y + cy + ay;
                if (ss.IsVerboseParseShape())
                    ss.LogParseShape("  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n",
                                     x * sfactor, y * sfactor, (x + cx) * sfactor, (y + cy) * sfactor,
                                     nx * sfactor, ny * sfactor);
                x = nx;
                y = ny;
            }
            else
            {
                int dx = 0, dy = 0;
                if (ss.ReadUInt1())
                {
                    dx = ss.ReadSInt(nbits);
                    dy = ss.ReadSInt(nbits);
                }
                else
                {
                    unsigned vertical = ss.ReadUInt1();
                    int      d        = ss.ReadSInt(nbits);
                    if (vertical)
                        dy = d;
                    else
                        dx = d;
                }
                int nx = x + dx;
                int ny = y + dy;
                if (ss.IsVerboseParseShape())
                    ss.LogParseShape("  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n", x * sfactor,
                                     y * sfactor, nx * sfactor, ny * sfactor);
                x = nx;
                y = ny;
            }
        }

        unsigned pos = ss.Tell();
        corrupted    = pos > shapeSize;
        if (pos > readLen)
            break;
    }

    if (corrupted || dataLen >= 0x200000)
    {
    corrupted_shape:
        corrupted = true;
        ss.LogWarning("Corrupted shape detected in file %s", in->GetFileName().ToCStr());
        pmem[0] = 0;
        pmem[1] = 0;
        if (allocLen > 2)
            pallocator->ReallocLastBlock(pmem, allocLen, 2);
    }
    else if (allocLen > dataLen)
        pallocator->ReallocLastBlock(pmem, allocLen, dataLen);

    Shape.Paths = pmem;
    p->SetAltStream(0);
    return !corrupted;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
