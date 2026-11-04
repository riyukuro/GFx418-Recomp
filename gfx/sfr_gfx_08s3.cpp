// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_MorphCharacter (lane sfr24): the
// DefineMorphShape character, its MORPHFILLSTYLE / MORPHLINESTYLE parser and the style array copies it uses.
// MS2-UNIT: sfr_gfx_08s3
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14265ebc0-0x1426607c2 .text$mn
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_morphcharacter.h"
#include "../include/gfx/gfx_displayobject.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}} // namespace Scaleform::Alg
#include "../include/render/render_gradients.h"
#include "../include/render/render_image.h"

namespace Scaleform { namespace Render {

// No source yet, identity placement, not bound.
inline ComplexFill::ComplexFill() : BindIndex(~0u) {}

}} // namespace Scaleform::Render

namespace Scaleform { void LogDebugMessage(LogMessageId id, const char* fmt, ...); }

namespace Scaleform {

using Render::FillStyleType;
using Render::StrokeStyleType;

// The style arrays the parser fills before the shapes take copies.
// @0x14265ec00
template ArrayDataBase<FillStyleType, AllocatorGH<FillStyleType, Stat_Default_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x14265ec70
template ArrayDataBase<StrokeStyleType, AllocatorGH<StrokeStyleType, Stat_Default_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1426605a0
template void ArrayDataBase<FillStyleType, AllocatorGH<FillStyleType, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x142660640
template void ArrayDataBase<StrokeStyleType, AllocatorGH<StrokeStyleType, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x1426606e0
template void ArrayData<StrokeStyleType, AllocatorGH<StrokeStyleType, Stat_Default_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);

namespace GFx {

// DefineMorphShape2: the edge bounds, the stroke flags and the miter limits.
enum { MorphTag_DefineMorphShape2 = 84 };

// @0x14265ebc0
MorphCharacterDef::MorphCharacterDef() {}

// @0x14265ecf0
MorphCharacterDef::~MorphCharacterDef() {}

// Both shapes are copied so the binding's images do not reach the shared definition.
// @0x14265ee00
Ptr<Render::ShapeMeshProvider> MorphCharacterDef::BindResourcesInStyles(const ResourceBinding& resourceBinding) const
{
    Ptr<ShapeDataBase> shape1 = *pShape1->Clone();
    Ptr<ShapeDataBase> shape2 = *pShape2->Clone();
    shape1->BindResourcesInStyles(resourceBinding);
    shape2->BindResourcesInStyles(resourceBinding);
    return *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(shape1, shape2);
}

// Morph shapes are never merged.
// @0x14265eeb0
UInt32 MorphCharacterDef::ComputeGeometryHash() const { return 0; }

// Without testShape only the bounds count; otherwise the fill at the instance's ratio.
// @0x14265eec0
bool MorphCharacterDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const
{
    if (!testShape)
    {
        RectF bnd = pShapeMeshProvider->GetCorrectBounds(Render::Matrix2F(), 0, 0, 0);
        return bnd.Contains(pt);
    }
    else
    {
        return pShapeMeshProvider->HitTestShape(Render::Matrix2F(), pt.x, pt.y, pinst->GetRatio(), 0, 0);
    }
}

// The bounds of the start shape, whatever the ratio.
// @0x14265efc0
RectF MorphCharacterDef::GetBoundsLocal(float) const
{
    return pShapeMeshProvider->GetCorrectBounds(Render::Matrix2F(), 0, 0, 0);
}

// @0x14265f030
RectF MorphCharacterDef::GetRectBoundsLocal(float morphRatio) const { return GetBoundsLocal(morphRatio); }

// @0x14265f050
Render::ShapeDataInterface* MorphCharacterDef::GetShape() { return pShape1; }

// @0x14265f060
bool MorphCharacterDef::IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const
{
    SF_UNUSED(cmpWith);
    return false;
}

// @0x14265f090
bool MorphCharacterDef::NeedsResolving() const
{
    return (pShape1->GetFlags() & ShapeDataBase::Flags_NeedsResolving) ||
           (pShape2->GetFlags() & ShapeDataBase::Flags_NeedsResolving);
}

// The bounds (DefineMorphShape2 adds the edge bounds and a flags byte, all unused), the offset of the end shape, the
// paired fill and line styles, then the two shapes; a bad offset leaves both empty.
// MS2-FUNCTIONAL: the dead rbound = bound copies differ: the exe copies each rect with a movaps load/store pair, ours loads both and stores them with movdqa (a trivial 16-byte copy does the same).
// @0x14265f0b0
void MorphCharacterDef::Read(LoadProcess* p, const TagInfo& tagInfo, bool withStyle)
{
    SF_UNUSED(withStyle);

    Stream* in = p->GetStream();

    RectF bound1, bound2;
    RectF rbound1, rbound2;
    in->ReadRect(&bound1);
    in->ReadRect(&bound2);

    if (tagInfo.TagType == MorphTag_DefineMorphShape2)
    {
        in->ReadRect(&rbound1);
        in->ReadRect(&rbound2);
        in->ReadU8();
    }
    else
    {
        rbound1 = bound1;
        rbound2 = bound2;
    }

    Array<FillStyleType> shape1FillStyles, shape2FillStyles;

    unsigned endShapeOffset = in->ReadU32();
    int      endShapeBase   = in->Tell();

    unsigned fillStyleCount = in->ReadU8();
    if (fillStyleCount == 0xFF)
        fillStyleCount = in->ReadU16();

    bool     needResolve = false;
    unsigned i;
    for (i = 0; i < fillStyleCount; i++)
    {
        FillStyleType fs1, fs2;

        ReadMorphFillStyle(p, tagInfo.TagType, fs1, fs2, &needResolve);

        shape1FillStyles.PushBack(fs1);
        shape2FillStyles.PushBack(fs2);
    }

    Array<StrokeStyleType> shape1LineStyles, shape2LineStyles;
    unsigned               lineStyleCount = in->ReadU8();
    if (lineStyleCount == 0xFF)
        lineStyleCount = in->ReadU16();
    shape1LineStyles.Resize(lineStyleCount);
    shape2LineStyles.Resize(lineStyleCount);
    for (i = 0; i < lineStyleCount; i++)
    {
        StrokeStyleType& ls1 = shape1LineStyles[i];
        StrokeStyleType& ls2 = shape2LineStyles[i];

        ls1.Width = in->ReadU16();
        ls2.Width = in->ReadU16();
        ls1.Flags = ls2.Flags = 0;
        ls1.Units = ls2.Units = 0.05f;
        ls1.Miter = ls2.Miter = 3;

        if (tagInfo.TagType == MorphTag_DefineMorphShape2)
        {
            unsigned styleFlags = in->ReadU16();

            ls1.Flags = ls2.Flags = ConvertSwfLineStyles(styleFlags);

            if (ls1.Flags & Render::StrokeJoin_Miter)
            {
                ls1.Miter = ls2.Miter = (float)(in->ReadU16()) / 256.0f;
            }
        }

        if (ls1.Flags & 0x08)
        {
            FillStyleType fs1, fs2;
            ReadMorphFillStyle(p, tagInfo.TagType, fs1, fs2, &needResolve);

            ls1.Color = fs1.Color;
            ls1.pFill = fs1.pFill;

            ls2.Color = fs2.Color;
            ls2.pFill = fs2.pFill;

            // The first gradient colour stands in for the colour.
            if (fs1.pFill->pGradient)
            {
                Render::GradientData* pgdata = fs1.pFill->pGradient;
                if (pgdata && pgdata->GetRecordCount() > 0)
                    ls1.Color = pgdata->At(0).ColorV.ToColor32();
            }
            if (fs2.pFill->pGradient)
            {
                Render::GradientData* pgdata = fs2.pFill->pGradient;
                if (pgdata && pgdata->GetRecordCount() > 0)
                    ls2.Color = pgdata->At(0).ColorV.ToColor32();
            }
        }
        else
        {
            Render::Color c1, c2;
            p->ReadRgbaTag(&c1, tagInfo.TagType);
            p->ReadRgbaTag(&c2, tagInfo.TagType);
            ls1.Color = c1.ToColor32();
            ls2.Color = c2.ToColor32();
        }
    }
    unsigned beginShapeAbsOffset = (unsigned)in->Tell();
    unsigned endShapeAbsOffset   = (unsigned)(endShapeBase + endShapeOffset);

    if (endShapeAbsOffset >= beginShapeAbsOffset)
    {
        in->LogParseShape("MorphCharacterDef, first shape:\n");

        pShape1 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles();
        pShape1->Read(p, tagInfo.TagType, endShapeAbsOffset - beginShapeAbsOffset, false);
        pShape1->SetStyles(fillStyleCount, shape1FillStyles.GetDataPtr(), lineStyleCount, shape1LineStyles.GetDataPtr());
        if (needResolve)
            pShape1->Flags |= ShapeDataBase::Flags_NeedsResolving;

        in->LogParseShape("MorphCharacterDef, second shape:\n");

        in->SetPosition(endShapeAbsOffset);
        pShape2 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles();
        pShape2->Read(p, tagInfo.TagType, tagInfo.TagDataOffset + tagInfo.TagLength - endShapeAbsOffset, false);
        pShape2->SetStyles(fillStyleCount, shape2FillStyles.GetDataPtr(), lineStyleCount, shape2LineStyles.GetDataPtr());
        if (needResolve)
            pShape2->Flags |= ShapeDataBase::Flags_NeedsResolving;
    }
    else
    {
        pShape1 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles(ShapeDataBase::Empty_Shape);
        pShape2 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles(ShapeDataBase::Empty_Shape);
    }
    pShapeMeshProvider = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(pShape1, pShape2);
}

// Ptr<ImageBase>::operator=(ImageBase*), which the exe inlines here and ours calls out of line.
static SF_INLINE void SetFillImage(Ptr<Render::ImageBase>& dst, Render::ImageBase* pimage)
{
    Render::ImageBase*& pobject = reinterpret_cast<Render::ImageBase*&>(dst);
    if (pimage)
        pimage->AddRef();
    if (pobject)
        pobject->Release();
    pobject = pimage;
}

// A solid colour pair, a gradient pair (same kind and count, own matrices and records) or a bitmap pair (one image,
// own matrices). A bitmap not loaded yet keeps its bind index for the binding; a missing one shows as the debug green.
// MS2-FUNCTIONAL 0x14265fbb0: register allocation, the gradient-type switch's last compare and the missing-image
// Ptr clears differ.
// @0x14265fbb0
void MorphCharacterDef::ReadMorphFillStyle(LoadProcess* p, TagType tagType, FillStyleType& fs1, FillStyleType& fs2,
                                           bool* needResolve)
{
    Stream* in   = p->GetStream();
    UByte   type = in->ReadU8();
    in->LogParse("morph fill style type = 0x%X\n", type);

    if (type == 0x00)
    {
        Render::Color color1, color2;
        in->ReadRgba(&color1);
        in->ReadRgba(&color2);
        fs1.Color = color1.Raw;
        fs2.Color = color2.Raw;
        in->LogParse("morph fill style begin color: ");
        in->LogParseClass(color1);
        in->LogParse("morph fill style end color: ");
        in->LogParseClass(color2);
    }
    else if (type & 0x10)
    {
        Render::Matrix2F matrix1, matrix2;
        in->ReadMatrix(&matrix1);
        in->ReadMatrix(&matrix2);

        // The 32768-twip gradient square onto the unit square, as for a plain fill.
        Render::Matrix2F gradientMatrix1, gradientMatrix2;
        gradientMatrix1.AppendScaling(1.0f / 32768.0f);
        gradientMatrix1.Tx() += 0.5f;
        gradientMatrix2.AppendScaling(1.0f / 32768.0f);
        gradientMatrix2.Tx() += 0.5f;
        if (type == 0x10)
        {
            gradientMatrix1.Ty() = 0.0f;
            gradientMatrix2.Ty() = 0.0f;
        }
        else
        {
            gradientMatrix1.Ty() = 0.5f;
            gradientMatrix2.Ty() = 0.5f;
        }
        gradientMatrix1.Prepend(matrix1.GetInverse());
        gradientMatrix2.Prepend(matrix2.GetInverse());

        UByte spec      = in->ReadU8();
        bool  linearRGB = false;
        if (tagType == MorphTag_DefineMorphShape2 || type == 0x13)
        {
            if (spec & 0x10)
                linearRGB = true;
            spec &= 0xF;
        }

        fs1.pFill = *SF_NEW Render::ComplexFill();
        fs2.pFill = *SF_NEW Render::ComplexFill();
        Render::GradientType gradType;
        switch (type)
        {
        case 0x10: gradType = Render::GradientLinear; break;
        case 0x12: gradType = Render::GradientRadial; break;
        case 0x13: gradType = Render::GradientFocalPoint; break;
        default:   gradType = Render::GradientLinear; break;
        }
        fs1.pFill->pGradient = *SF_NEW Render::GradientData(gradType, (UInt16)spec, linearRGB);
        fs2.pFill->pGradient = *SF_NEW Render::GradientData(gradType, (UInt16)spec, linearRGB);

        for (unsigned i = 0; i < spec; i++)
        {
            UByte         ratio1 = p->ReadU8();
            Render::Color color1;
            p->ReadRgbaTag(&color1, tagType);
            fs1.pFill->pGradient->At(i).ColorV = color1;
            fs1.pFill->pGradient->At(i).Ratio  = ratio1;

            UByte         ratio2 = p->ReadU8();
            Render::Color color2;
            p->ReadRgbaTag(&color2, tagType);
            fs2.pFill->pGradient->At(i).ColorV = color2;
            fs2.pFill->pGradient->At(i).Ratio  = ratio2;
        }
        in->LogParse("morph fsr: numGradients = %d\n", spec);

        if (type == 0x13)
        {
            fs1.pFill->pGradient->SetFocalRatio((SInt16)in->ReadU16() / 256.0f);
            fs2.pFill->pGradient->SetFocalRatio((SInt16)in->ReadU16() / 256.0f);
        }

        fs1.pFill->ImageMatrix = gradientMatrix1;
        fs2.pFill->ImageMatrix = gradientMatrix2;
    }
    else if (type & 0x40)
    {
        unsigned bitmapId = in->ReadU16();
        in->LogParse("morph fsr BitmapChar = %d\n", bitmapId);

        Render::Matrix2F matrix1, matrix2;
        in->ReadMatrix(&matrix1);
        in->ReadMatrix(&matrix2);

        ResourceHandle   handle;
        Render::Matrix2F imageMatrix1 = matrix1.GetInverse();
        Render::Matrix2F imageMatrix2 = matrix2.GetInverse();

        fs1.pFill              = *SF_NEW Render::ComplexFill();
        fs1.pFill->ImageMatrix = imageMatrix1;
        switch (type)
        {
        case 0x40: fs1.pFill->FillMode.Fill = UByte(Render::Wrap_Repeat | Render::Sample_Linear); break;
        case 0x41: fs1.pFill->FillMode.Fill = UByte(Render::Wrap_Clamp | Render::Sample_Linear); break;
        case 0x42: fs1.pFill->FillMode.Fill = UByte(Render::Wrap_Repeat | Render::Sample_Point); break;
        case 0x43: fs1.pFill->FillMode.Fill = UByte(Render::Wrap_Clamp | Render::Sample_Point); break;
        }
        fs2.pFill              = *SF_NEW Render::ComplexFill();
        fs2.pFill->ImageMatrix = imageMatrix2;
        fs2.pFill->FillMode    = fs1.pFill->FillMode;

        if (p->GetResourceHandle(&handle, ResourceId(bitmapId)) && handle.GetResourcePtr())
        {
            if (handle.GetResourcePtr()->GetResourceType() == Resource::RT_Image)
            {
                Render::ImageBase* pimage = static_cast<ImageResource*>(handle.GetResourcePtr())->GetImage();
                SetFillImage(fs1.pFill->pImage, pimage);
                SetFillImage(fs2.pFill->pImage, pimage);
            }
        }
        else
        {
            fs2.Color = fs1.Color = 0xFFA7DD39;
            if (handle.IsIndex())
            {
                fs1.pFill->BindIndex = handle.GetBindIndex();
                fs2.pFill->BindIndex = handle.GetBindIndex();
                *needResolve         = true;
            }
            else
            {
                fs2.pFill = 0;
                fs1.pFill = 0;
                if (bitmapId != 0xFFFF)
                    LogDebugMessage(Log_Warning, "An image with resource id %d is not found in resource table.",
                                    bitmapId);
            }
        }
    }
}

} // namespace GFx
} // namespace Scaleform

// MS2-PIN: ??_7MorphCharacterDef@GFx@Scaleform@@6B@ 0x143191688
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
// MS2-PIN: ??_GMorphCharacterDef@GFx@Scaleform@@UEAAPEAXI@Z 0x14265ed50
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7ShapeBaseCharacterDef@GFx@Scaleform@@6B@ 0x143190fe8
// MS2-PIN: ??_7ShapeDataBase@GFx@Scaleform@@6B@ 0x14318a3b0
// MS2-PIN: ??_7ConstShapeWithStyles@GFx@Scaleform@@6B@ 0x14318a420
