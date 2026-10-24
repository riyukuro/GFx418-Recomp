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

// MS2-FUNCTIONAL: the exe inlines ~ShapeBaseCharacterDef, which is out of line here.
// @0x14265ecf0
MorphCharacterDef::~MorphCharacterDef() {}
// MS2-FUNCTIONAL 0x14265ed50: the compiler-generated deleting destructor; the exe inlines the destructor chain into it, here it calls ~MorphCharacterDef.

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
// MS2-FUNCTIONAL: the exe loads the provider's vftable in each branch; register allocation differs.
// @0x14265eec0
bool MorphCharacterDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const
{
    Render::Matrix2F matrix;
    if (!testShape)
    {
        RectF bounds = pShapeMeshProvider->GetCorrectBounds(matrix, 0, 0, 0);
        return bounds.Contains(pt);
    }
    return pShapeMeshProvider->HitTestShape(matrix, pt.x, pt.y, pinst->GetRatio(), 0, 0);
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
// MS2-FUNCTIONAL: register allocation and the inlined Array::PushBack / stream reads differ.
// @0x14265f0b0
void MorphCharacterDef::Read(LoadProcess* p, const TagInfo& tagInfo, bool withStyle)
{
    SF_UNUSED(withStyle);
    Stream* in = p->GetStream();

    RectF bound1(0, 0, 0, 0), bound2(0, 0, 0, 0), edgeBound1(0, 0, 0, 0), edgeBound2(0, 0, 0, 0);
    in->ReadRect(&bound1);
    in->ReadRect(&bound2);
    if (tagInfo.TagType == MorphTag_DefineMorphShape2)
    {
        in->ReadRect(&edgeBound1);
        in->ReadRect(&edgeBound2);
        in->ReadU8();
    }
    else
    {
        edgeBound1 = bound1;
        edgeBound2 = bound2;
    }

    UInt32 offset        = in->ReadU32();
    int    endShapeStart = in->Tell();

    unsigned fillCount = in->ReadU8();
    if (fillCount == 0xFF)
        fillCount = in->ReadU16();

    bool                 needResolve = false;
    Array<FillStyleType> fills1, fills2;
    for (unsigned i = 0; i < fillCount; i++)
    {
        FillStyleType fs1, fs2;
        fs1.pFill = 0;
        fs2.pFill = 0;
        ReadMorphFillStyle(p, tagInfo.TagType, fs1, fs2, &needResolve);
        fills1.PushBack(fs1);
        fills2.PushBack(fs2);
    }

    unsigned lineCount = in->ReadU8();
    if (lineCount == 0xFF)
        lineCount = in->ReadU16();

    Array<StrokeStyleType> lines1, lines2;
    lines1.Resize(lineCount);
    lines2.Resize(lineCount);
    for (unsigned i = 0; i < lineCount; i++)
    {
        StrokeStyleType& ls1 = lines1[i];
        StrokeStyleType& ls2 = lines2[i];
        ls1.Width = (float)in->ReadU16();
        ls2.Width = (float)in->ReadU16();
        ls1.Flags = ls2.Flags = 0;
        ls1.Units = ls2.Units = 0.05f;
        ls1.Miter = ls2.Miter = 3.0f;
        if (tagInfo.TagType == MorphTag_DefineMorphShape2)
        {
            ls1.Flags = ls2.Flags = ConvertSwfLineStyles(in->ReadU16());
            if (ls1.Flags & 0x20)
                ls1.Miter = ls2.Miter = in->ReadU16() / 256.0f;
        }

        if (ls1.Flags & 0x08)
        {
            FillStyleType fs1, fs2;
            fs1.pFill = 0;
            fs2.pFill = 0;
            ReadMorphFillStyle(p, tagInfo.TagType, fs1, fs2, &needResolve);
            ls1.Color = fs1.Color;
            ls1.pFill = fs1.pFill;
            ls2.Color = fs2.Color;
            ls2.pFill = fs2.pFill;
            // The first gradient colour stands in for the colour.
            if (fs1.pFill->pGradient && fs1.pFill->pGradient->GetRecordCount() > 0)
                ls1.Color = fs1.pFill->pGradient->At(0).ColorV.Raw;
            if (fs2.pFill->pGradient && fs2.pFill->pGradient->GetRecordCount() > 0)
                ls2.Color = fs2.pFill->pGradient->At(0).ColorV.Raw;
        }
        else
        {
            Render::Color color1, color2;
            p->ReadRgbaTag(&color1, tagInfo.TagType);
            p->ReadRgbaTag(&color2, tagInfo.TagType);
            ls1.Color = color1.Raw;
            ls2.Color = color2.Raw;
        }
    }

    int endShapePos = endShapeStart + offset;
    int pos         = in->Tell();
    if ((unsigned)endShapePos >= (unsigned)pos)
    {
        in->LogParseShape("MorphCharacterDef, first shape:\n");
        pShape1 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles();
        pShape1->Read(p, tagInfo.TagType, endShapePos - pos, false);
        pShape1->SetStyles(fillCount, fills1.GetDataPtr(), lineCount, lines1.GetDataPtr());
        if (needResolve)
            pShape1->Flags |= ShapeDataBase::Flags_NeedsResolving;

        in->LogParseShape("MorphCharacterDef, second shape:\n");
        in->SetPosition(endShapePos);
        pShape2 = *SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles();
        pShape2->Read(p, tagInfo.TagType, tagInfo.TagDataOffset + tagInfo.TagLength - endShapePos, false);
        pShape2->SetStyles(fillCount, fills2.GetDataPtr(), lineCount, lines2.GetDataPtr());
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

// A solid colour pair, a gradient pair (same kind and count, own matrices and records) or a bitmap pair (one image,
// own matrices). A bitmap not loaded yet keeps its bind index for the binding; a missing one shows as the debug green.
// MS2-FUNCTIONAL: register allocation and the inlined stream reads / ComplexFill setup differ.
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
            linearRGB = (spec & 0x10) != 0;
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
            Resource* pres = handle.GetResourcePtr();
            if (pres->GetResourceType() == Resource::RT_Image)
            {
                Render::ImageBase* pimage = static_cast<ImageResource*>(pres)->GetImage();
                fs1.pFill->pImage = pimage;
                fs2.pFill->pImage = pimage;
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
