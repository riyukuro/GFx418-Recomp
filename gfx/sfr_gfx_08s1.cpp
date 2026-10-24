// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ShapeSwf, part 1 (lane sfr24): the
// shape data classes and the shape character definitions around them (construction, copies, styles, bounds, hit
// tests, binding of the image fills).
// MS2-UNIT: sfr_gfx_08s1
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142658b70-0x142658cad .text$mn
// MS2-RANGE: 0x142658df0-0x142659733 .text$mn
// MS2-RANGE: 0x142659740-0x142659897 .text$mn
// MS2-RANGE: 0x142659d50-0x142659e37 .text$mn
// MS2-RANGE: 0x142659e80-0x14265a01a .text$mn
// MS2-RANGE: 0x14265a020-0x14265a95c .text$mn
// MS2-RANGE: 0x14265aa70-0x14265aaa8 .text$mn
// MS2-RANGE: 0x14265ab20-0x14265ab76 .text$mn
// MS2-RANGE: 0x14265ac00-0x14265adec .text$mn
// MS2-RANGE: 0x14265d6a0-0x14265d8f2 .text$mn
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_shapeswf.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}} // namespace Scaleform::Alg
#include "../include/render/render_gradients.h"
#include "../include/render/render_image.h"
#include "../include/render/render_shapedatafloatmp.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace Render {

// in other parts of the renderer (HitTestFill 0x1425fd750, sfr_render_03d)
template<class Transformer>
bool HitTestFill(const ShapeDataInterface& shape, const Transformer& trans, float x, float y);

// No source yet, identity placement, not bound.
inline ComplexFill::ComplexFill() : BindIndex(~0u) {}

// A copy holds its own references to the image and the gradient; the count starts over.
inline ComplexFill::ComplexFill(const ComplexFill& o)
    : RefCountBase<ComplexFill, Stat_Default_Mem>(), pImage(o.pImage), pGradient(o.pGradient),
      ImageMatrix(o.ImageMatrix), FillMode(o.FillMode), BindIndex(o.BindIndex)
{
}

// Not called in the exe (kept out of line); ComputeBound has it inlined.
// @0x142658b70
template RectF ComputeBoundsFill<Matrix2F>(const ShapeDataInterface&, const Matrix2F&, BoundEdges);

}} // namespace Scaleform::Render

namespace Scaleform { void LogDebugMessage(LogMessageId id, const char* fmt, ...); }

namespace Scaleform { namespace GFx {

using Render::FillStyleType;
using Render::StrokeStyleType;

// The path data of an empty shape: an end-of-shape record.
static const UByte EmptyShapePaths[] = { 0, 0, 0, 0 };

// @0x142658ea0
ConstShapeWithStyles::ConstShapeWithStyles(const ConstShapeWithStyles& o) : ShapeDataBase(o), Styles(0)
{
    SetStyles(o.FillStylesNum, o.GetFills(), o.StrokeStylesNum, o.GetStrokes());
}

// The bitmap as one rectangle the size of the image in twips, filled with the image at a twentieth scale, clamped,
// smoothed when bilinear. Without an image, or when no image can be made from its source, the shape stays empty and
// a warning is logged. A first mesh provider is made from the shape data and dropped again; the one kept is made from
// pShape.
// MS2-FUNCTIONAL: register allocation differs; the Ptr<ShapeMeshProvider> assignment is not inlined.
// @0x142658f20
ImageShapeCharacterDef::ImageShapeCharacterDef(ImageResource* pimage, ImageCreator* imgCreator, bool bilinear)
{
    Ptr<Render::ShapeDataFloat> shapeData = *SF_HEAP_AUTO_NEW(this) Render::ShapeDataFloat();
    FillStyleType               fill;
    fill.pFill = *SF_HEAP_AUTO_NEW(this) Render::ComplexFill();
    if (pimage)
    {
        Ptr<Render::Image> img;
        if (pimage->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
            img = static_cast<Render::Image*>(pimage->GetImage());
        else if (!imgCreator)
            LogDebugMessage(Log_Warning, "ImageCreator is null in ImageShapeCharacterDef ctor");
        else
        {
            ImageCreateInfo info(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(this));
            img = *imgCreator->CreateImage(info, static_cast<Render::ImageSource*>(pimage->GetImage()));
        }
        fill.pFill->pImage = img.GetPtr();
        if (!img)
        {
            LogDebugMessage(Log_Warning, "Image is not created.");
            return;
        }
        fill.pFill->ImageMatrix.SetIdentity();
        fill.pFill->ImageMatrix.AppendScaling(0.05f);
        fill.pFill->FillMode.Fill = Render::Wrap_Clamp;
        if (bilinear)
            fill.pFill->FillMode.Fill |= Render::Sample_Linear;
        else
            fill.pFill->FillMode.Fill |= Render::Sample_Point;

        Render::ImageRect irect = img->GetRect();
        Render::Matrix2F  m;
        img->GetMatrix(&m);
        RectF bounds;
        m.EncloseTransform(&bounds, RectF(float(irect.x1), float(irect.y1), float(irect.x2), float(irect.y2)));

        shapeData->AddFillStyle(fill);
        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(0, 0);
        shapeData->LineTo(Render::PixelsToTwips(bounds.Width()), 0);
        shapeData->LineTo(Render::PixelsToTwips(bounds.Width()), Render::PixelsToTwips(bounds.Height()));
        shapeData->LineTo(0, Render::PixelsToTwips(bounds.Height()));
        shapeData->ClosePath();
        shapeData->EndPath();
        shapeData->EndShape();

        Ptr<Render::ShapeMeshProvider> provider = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(shapeData);
        pShape             = shapeData.GetPtr();
        pShapeMeshProvider = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(pShape);
    }
    else
        LogDebugMessage(Log_Warning, "Image is null in ImageShapeCharacterDef ctor.");
}

// @0x142659740
ShapeDataBase::ShapeDataBase(EmptyShape) : Paths(EmptyShapePaths), Flags(0)
{
}

// @0x1426597e0
SwfShapeCharacterDef::SwfShapeCharacterDef(ShapeDataBase* shp) : pShape(shp)
{
    pShapeMeshProvider = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(pShape, 0);
}

// @0x142659d50
ConstShapeWithStyles::~ConstShapeWithStyles()
{
    FillStyleType* pfill = GetFills();
    for (unsigned i = 0; i < FillStylesNum; i++, pfill++)
        pfill->~FillStyleType();
    StrokeStyleType* pstroke = (StrokeStyleType*)pfill;
    for (unsigned i = 0; i < StrokeStylesNum; i++, pstroke++)
        pstroke->~StrokeStyleType();
    SF_FREE(Styles);
}

// @0x142659e00
ShapeBaseCharacterDef::~ShapeBaseCharacterDef()
{
}

// An image fill bound through the movie's resources takes the image of its resource; a fill whose resource is
// missing or not an image turns into a solid placeholder color.
// @0x14265a020
void ConstShapeWithStyles::BindResourcesInStyles(const ResourceBinding& resourceBinding)
{
    FillStyleType*   pfills = GetFills();
    ResourceBindData resData;
    for (unsigned i = 0; i < FillStylesNum; i++)
    {
        if (pfills[i].pFill && pfills[i].pFill->BindIndex != ~0u)
        {
            resourceBinding.GetResourceData(&resData, pfills[i].pFill->BindIndex);
            if (resData.pResource && resData.pResource->GetResourceType() == Resource::RT_Image)
            {
                pfills[i].pFill->pImage    = static_cast<ImageResource*>(resData.pResource.GetPtr())->GetImage();
                pfills[i].pFill->BindIndex = ~0u;
            }
            else
            {
                pfills[i].pFill = 0;
                pfills[i].Color = 0xffa7dd39;
            }
        }
    }
    StrokeStyleType* pstrokes = (StrokeStyleType*)(pfills + FillStylesNum);
    for (UPInt i = 0; i < StrokeStylesNum; i++)
    {
        StrokeStyleType& stroke = pstrokes[i];
        if (stroke.pFill && stroke.pFill->BindIndex != ~0u)
        {
            resourceBinding.GetResourceData(&resData, stroke.pFill->BindIndex);
            if (resData.pResource && resData.pResource->GetResourceType() == Resource::RT_Image)
            {
                stroke.pFill->pImage    = static_cast<ImageResource*>(resData.pResource.GetPtr())->GetImage();
                stroke.pFill->BindIndex = ~0u;
            }
            else
            {
                stroke.pFill = 0;
                stroke.Color = 0xffa7dd39;
            }
        }
    }
}

// The unbound shape uses the shared provider.
// @0x14265a2c0
Ptr<Render::ShapeMeshProvider> ShapeBaseCharacterDef::BindResourcesInStyles(const ResourceBinding&) const
{
    return pShapeMeshProvider;
}

// The image fills are bound in a copy of the shape data, which gets a provider of its own.
// @0x14265a310
Ptr<Render::ShapeMeshProvider> SwfShapeCharacterDef::BindResourcesInStyles(const ResourceBinding& resourceBinding) const
{
    Ptr<ShapeDataBase> shape = *pShape->Clone();
    shape->BindResourcesInStyles(resourceBinding);
    return *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(shape, 0);
}

// @0x14265a3b0
ShapeDataBase* ConstShapeNoStyles::Clone() const
{
    return SF_HEAP_AUTO_NEW(this) ConstShapeNoStyles(*this);
}

// @0x14265a430
ShapeDataBase* ConstShapeWithStyles::Clone() const
{
    return SF_HEAP_AUTO_NEW(this) ConstShapeWithStyles(*this);
}

// @0x14265a4f0
void ShapeDataBase::ComputeBound(RectF* r) const
{
    *r = Render::ComputeBoundsFill(*this, Render::Matrix2F(), Render::Bound_OuterEdges);
}

// The stroke flags of a SWF LINESTYLE2 record in the renderer's encoding: scaling, hinting, caps, joins and fill
// close all keep their bits.
// @0x14265a640
unsigned ConvertSwfLineStyles(unsigned swfFlags)
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

// @0x14265a6e0
bool ImageShapeCharacterDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase*) const
{
    RectF bounds = pShapeMeshProvider->GetIdentityBounds();
    if (!bounds.Contains(pt))
        return false;
    if (testShape)
        return Render::HitTestFill(*pShape, Render::Matrix2F::Identity, pt.x, pt.y);
    return true;
}

// @0x14265a790
bool ShapeDataBase::DefPointTestLocal(Render::ShapeMeshProvider* provider, const PointF& pt, bool testShape,
                                      const DisplayObjectBase*) const
{
    RectF bounds = provider->GetIdentityBounds();
    if (!bounds.Contains(pt))
        return false;
    if (testShape)
        return Render::HitTestFill(*this, Render::Matrix2F::Identity, pt.x, pt.y);
    return true;
}

// @0x14265a820
bool SwfShapeCharacterDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const
{
    return pShape->DefPointTestLocal(pShapeMeshProvider, pt, testShape, pinst);
}

// @0x14265a910
void ConstShapeWithStyles::GetFillStyle(unsigned idx, FillStyleType* p) const
{
    *p = GetFills()[idx - 1];
}

// Not called in the exe (SwfShapeCharacterDef::IsEqualGeometry has it inlined). The argument is evaluated as an
// unused one.
// @0x14265ab20
bool ShapeDataBase::IsEqualGeometry(const ShapeBaseCharacterDef& cmpWith) const
{
    cmpWith;
    return false;
}

// MS2-FUNCTIONAL: instruction scheduling of the reader setup differs.
// @0x14265ac00
bool ConstShapeNoStyles::Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle)
{
    ShapeSwfReader reader(*this, p->GetLoadTaskData()->GetPathAllocator());
    return reader.Read(p, tagType, lenInBytes, withStyle);
}

// The styles read go to one block of the load heap.
// MS2-FUNCTIONAL: register allocation and the fill loop induction differ.
// @0x14265ac70
bool ConstShapeWithStyles::Read(LoadProcess* p, TagType tagType, unsigned lenInBytes, bool withStyle)
{
    ShapeSwfReader reader(*this, p->GetLoadTaskData()->GetPathAllocator());
    if (!reader.Read(p, tagType, lenInBytes, withStyle))
        return false;

    FillStylesNum     = reader.GetFillStyleCount();
    StrokeStylesNum   = reader.GetStrokeStyleCount();
    MemoryHeap* pheap = p->GetLoadHeap();
    if (FillStylesNum || StrokeStylesNum)
    {
        Styles = pheap->Alloc(sizeof(FillStyleType) * FillStylesNum + sizeof(StrokeStyleType) * StrokeStylesNum);
        FillStyleType* pfill = GetFills();
        for (unsigned i = 0; i < FillStylesNum; i++, pfill++)
            Construct<FillStyleType>(pfill, *reader.GetFillStyle(i));
        StrokeStyleType* pstroke = (StrokeStyleType*)pfill;
        for (unsigned i = 0; i < StrokeStylesNum; i++)
            Construct<StrokeStyleType>(&pstroke[i], *reader.GetStrokeStyle(i));
    }
    else
        Styles = 0;
    return true;
}

// Each image or gradient fill gets a copy of its own.
// MS2-FUNCTIONAL: register allocation and loop induction differ.
// @0x14265d6a0
void ConstShapeWithStyles::SetStyles(unsigned fillStyleCount, const FillStyleType* fillStyles,
                                     unsigned strokeStyleCount, const StrokeStyleType* strokeStyles)
{
    if (Styles)
        SF_FREE(Styles);
    FillStylesNum   = fillStyleCount;
    StrokeStylesNum = strokeStyleCount;
    if (fillStyleCount == 0 && strokeStyleCount == 0)
    {
        Styles = 0;
        return;
    }
    Styles = SF_HEAP_AUTO_ALLOC(this, sizeof(FillStyleType) * fillStyleCount + sizeof(StrokeStyleType) * strokeStyleCount);
    FillStyleType* pfill = GetFills();
    for (unsigned i = 0; i < FillStylesNum; i++, pfill++)
    {
        Construct<FillStyleType>(pfill, fillStyles[i]);
        if (pfill->pFill)
            pfill->pFill = *SF_HEAP_AUTO_NEW(this) Render::ComplexFill(*pfill->pFill);
    }
    StrokeStyleType* pstroke = (StrokeStyleType*)pfill;
    for (UPInt i = 0; i < StrokeStylesNum; i++, pstroke++)
    {
        Construct<StrokeStyleType>(pstroke, strokeStyles[i]);
        if (pstroke->pFill)
            pstroke->pFill = *SF_HEAP_AUTO_NEW(this) Render::ComplexFill(*pstroke->pFill);
    }
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??0ComplexFill@Render@Scaleform@@QEAA@AEBV012@@Z 0x142658df0
// MS2-PIN: ??0StrokeStyleType@Render@Scaleform@@QEAA@AEBU012@@Z 0x142659770
// MS2-PIN: ??_GImageShapeCharacterDef@GFx@Scaleform@@UEAAPEAXI@Z 0x142659e80
// MS2-PIN: ??_GShapeBaseCharacterDef@GFx@Scaleform@@UEAAPEAXI@Z 0x142659f10
// MS2-PIN: ??_GSwfShapeCharacterDef@GFx@Scaleform@@UEAAPEAXI@Z 0x142659f90
// MS2-PIN: ?GetBoundsLocal@ImageShapeCharacterDef@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@M@Z 0x14265a8d0
// MS2-PIN: ?GetBoundsLocal@SwfShapeCharacterDef@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@M@Z 0x14265a8f0
// MS2-PIN: ?GetRectBoundsLocal@ImageShapeCharacterDef@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@M@Z 0x14265aa70
// MS2-PIN: ?GetRectBoundsLocal@SwfShapeCharacterDef@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@M@Z 0x14265aa90
// MS2-PIN: ?IsEqualGeometry@SwfShapeCharacterDef@GFx@Scaleform@@UEBA_NAEBVShapeBaseCharacterDef@23@@Z 0x14265ab50
// MS2-PIN: ??_7ShapeDataBase@GFx@Scaleform@@6B@ 0x14318a3b0
// MS2-PIN: ??_7ConstShapeWithStyles@GFx@Scaleform@@6B@ 0x14318a420
// MS2-PIN: ??_7ConstShapeNoStyles@GFx@Scaleform@@6B@ 0x14318b708
// MS2-PIN: ??_7ShapeBaseCharacterDef@GFx@Scaleform@@6B@ 0x143190fe8
// MS2-PIN: ??_7SwfShapeCharacterDef@GFx@Scaleform@@6B@ 0x143191060
// MS2-PIN: ??_7ImageShapeCharacterDef@GFx@Scaleform@@6B@ 0x1431910d8
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
// MS2-PIN: ??_7?$ShapeDataFloatTempl@V?$Array@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14317bb40
// MS2-PIN: ??_7ShapeDataFloat@Render@Scaleform@@6B@ 0x14317bb98
