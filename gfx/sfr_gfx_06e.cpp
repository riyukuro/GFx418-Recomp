// Recovered Scaleform 4.1.18 GFx_DrawingContext: the shape the AS drawing API of a clip draws into (moveTo, lineTo,
// curveTo, beginFill / beginBitmapFill, lineStyle), packed into a byte container and shown through a tree container
// of shape nodes; plus the fill hit test of a shape (Render::HitTestFill) its point test uses.
// Scaleform GFx 4.1.18, recovered from the exe; the SDK sources served only as a reference.
// MS2-UNIT: sfr_gfx_06e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425fd750-0x142602c20 .text$mn
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEC@@Scaleform@@6B@ 0x14318e730
// MS2-PIN: ??_7?$RefCountBaseNTS@VDrawingContext@GFx@Scaleform@@$0BEC@@Scaleform@@6B@ 0x14318e738
// MS2-PIN: ??_7?$ShapeDataPacked@V?$ArrayDH@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14318e750
// MS2-PIN: ??_7PackedShape@DrawingContext@GFx@Scaleform@@6B@ 0x14318e7a8
// MS2-PIN: ??_7DrawingContext@GFx@Scaleform@@6B@ 0x14318e800
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
#include <float.h>
#include "../kernel/sf_log.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_drawingcontext.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_state.h"
#include "../include/render/render_meshprovider.h"
#include "../include/render/render_gradients.h"
#include "../include/render/render_math2d.h"

namespace Scaleform {

void LogDebugMessage(LogMessageId id, const char* fmt, ...);

namespace Render {

inline ComplexFill::ComplexFill() : BindIndex(~0u) {}

inline void TreeShape::SetShape(ShapeMeshProvider* pshape)
{
    NodeData* data = GetWritableData(Change_Shape);
    if (pshape)
        pshape->AddRef();
    if (data->pMeshProvider)
        data->pMeshProvider->Release();
    data->pMeshProvider = pshape;
    AddToPropagate();
}

// The fill hit test: the even-odd crossings of a ray from (x, y) with the outer paths of the shape (the ones with
// the empty fill on one side), layer by layer.
template<class Transformer>
bool HitTestFill(const ShapeDataInterface& shape, const Transformer& trans, float x, float y)
{
    ShapePosInfo  pos(shape.GetStartingPos());
    ShapePathType pathType;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    int           styleCount = 0;

    while ((pathType = shape.ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (pathType == Shape_NewLayer)
        {
            if (styleCount)
                return true;
            styleCount = 0;
        }

        if ((styles[0] == 0) != (styles[1] == 0))
        {
            trans.Transform(&coord[0], &coord[1]);
            float lastX = coord[0];
            float lastY = coord[1];
            float x1, y1, x2, y2;
            PathEdgeType edgeType;
            while ((edgeType = shape.ReadEdge(&pos, coord)) != Edge_EndPath)
            {
                if (edgeType == Edge_LineTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    x1 = lastX;
                    y1 = lastY;
                    x2 = coord[0];
                    y2 = coord[1];
                    if (y1 > y2)
                    {
                        Alg::Swap(x1, x2);
                        Alg::Swap(y1, y2);
                    }
                    if (y >= y1 && y < y2 && Math2D::CrossProduct(x1, y1, x2, y2, x, y) > 0)
                        styleCount ^= 1;
                    lastX = coord[0];
                    lastY = coord[1];
                }
                else if (edgeType == Edge_QuadTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    trans.Transform(&coord[2], &coord[3]);
                    styleCount = Math2D::CheckQuadraticIntersection(styleCount, lastX, lastY, coord[0], coord[1],
                                                                    coord[2], coord[3], x, y);
                    lastX = coord[2];
                    lastY = coord[3];
                }
                else if (edgeType == Edge_CubicTo)
                {
                    trans.Transform(&coord[0], &coord[1]);
                    trans.Transform(&coord[2], &coord[3]);
                    trans.Transform(&coord[4], &coord[5]);
                    styleCount = Math2D::CheckCubicIntersection(styleCount, lastX, lastY, coord[0], coord[1],
                                                                coord[2], coord[3], coord[4], coord[5], x, y);
                    lastX = coord[4];
                    lastY = coord[5];
                }
            }
        }
        else
        {
            shape.SkipPathData(&pos);
        }
    }
    return styleCount != 0;
}

// @0x1425fd750
template bool HitTestFill<Matrix2F>(const ShapeDataInterface&, const Matrix2F&, float, float);

} // namespace Render

namespace GFx {

using Render::ComplexFill;
using Render::Matrix2F;
using Render::FillStyleType;
using Render::StrokeStyleType;
using Render::ShapePosInfo;
using Render::ShapePathType;
using Render::TreeContainer;
using Render::TreeShape;
using Render::ShapeMeshProvider;

// What an image creator is asked to make (0x38 bytes).
class ImageCreateInfo
{
public:
    enum { Create_SourceImage = 3 };

    ImageCreateInfo(int type, MemoryHeap* pheap, unsigned use, Resource::ResourceUse ruse)
        : Type(type), pHeap(pheap), Use(use), RUse(ruse), pLog(0), pFileOpener(0), pIFHRegistry(0), pMovie(0)
    {
    }

    int                   Type;          // +0
    MemoryHeap*           pHeap;         // +8
    unsigned              Use;           // +0x10
    Resource::ResourceUse RUse;          // +0x14
    void*                 pLog;          // +0x18
    void*                 pFileOpener;   // +0x20
    void*                 pIFHRegistry;  // +0x28
    void*                 pMovie;        // +0x30
};
struct ImageCreateExportInfo;

// Turns image files and sources into images (vftable 0x143184c60).
class ImageCreator : public State
{
public:
    virtual Render::Image* LoadProtocolImage(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadImageFile(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadExportedImage(const ImageCreateExportInfo& info, const String& url);
    virtual Render::Image* CreateImage(const ImageCreateInfo& info, Render::ImageSource* source);
};

// Lines narrower than a twip are drawn a twip wide.
static inline float TwipsToPixels(float x) { return x / 20.0f; }

// @0x1425fdc60
DrawingContext::DrawingContext(MemoryHeap* pheap, Render::ContextImpl::Context& renContext, ImageCreator* imgCreator)
    : pHeap(pheap), RenContext(renContext), ImgCreator(imgCreator), mFillStyle(), mLineStyle(), PosInfo(0),
      States(State_NewShapeFlag)
{
    pNext = pPrev = 0;
    pTreeContainer = *RenContext.CreateEntry<TreeContainer>();
    Clear();
}

// @0x1425fde80
DrawingContext::~DrawingContext()
{
    if (pPrev && pNext)
        RemoveNode();
}

// @0x1425fe1c0
bool DrawingContext::AcquirePath(bool newShapeFlag)
{
    if (!IsEmpty())
    {
        States |= State_Dirty;
        if (newShapeFlag && (States & State_NeedClosePath))
            FinishPath();
        if (States & State_NeedEndPath)
        {
            Shapes->EndPath();
            States &= ~State_NeedEndPath;
        }
        if (newShapeFlag)
            States |= State_NewShapeFlag;
        else
            States &= ~State_NewShapeFlag;
        return true;
    }
    return false;
}

// @0x1425fe480
void DrawingContext::BeginBitmapFill(FillType fillType, ImageResource* pimageRes, const Render::Matrix2F& mtx)
{
    unsigned styleIdx = SetNewFill();
    if (!styleIdx)
        return;

    FillStyleType fs;
    Shapes->GetFillStyle(styleIdx, &fs);
    fs.pFill = *SF_HEAP_NEW(pHeap) ComplexFill();

    Matrix2F m(mtx);
    m.AppendScaling(20);
    Matrix2F textureMatrix(m.GetInverse());
    fs.pFill->ImageMatrix = textureMatrix;

    Ptr<Render::Image> img;
    if (pimageRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
        img = (Render::Image*)pimageRes->GetImage();
    else if (!ImgCreator)
        LogDebugMessage(Log_Warning, "ImageCreator is null in BeginBitmapFill");
    else
    {
        ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(this), 1,
                              Resource::Use_Bitmap);
        img = *ImgCreator->CreateImage(cinfo, (Render::ImageSource*)pimageRes->GetImage());
    }
    fs.pFill->pImage = img;

    using namespace Render;
    switch (fillType)
    {
    case Fill_TiledSmoothImage:   fs.pFill->FillMode.Fill = UByte(Wrap_Repeat | Sample_Linear); break;
    case Fill_ClippedSmoothImage: fs.pFill->FillMode.Fill = UByte(Wrap_Clamp | Sample_Linear);  break;
    case Fill_TiledImage:         fs.pFill->FillMode.Fill = UByte(Wrap_Repeat | Sample_Point);  break;
    case Fill_ClippedImage:       fs.pFill->FillMode.Fill = UByte(Wrap_Clamp | Sample_Point);   break;
    }
    Shapes->UpdateFillStyle(styleIdx, fs);
    BeginFill();
}

// @0x1425fe860
void DrawingContext::BeginFill()
{
    if (States & State_NeedClosePath)
        EndFill();
    States |= State_NeedClosePath | State_FreshFillStyle;
}

// @0x1425fe8f0
void DrawingContext::BeginSolidFill(unsigned rgba)
{
    mFillStyle.Color = rgba;
    mFillStyle.pFill = 0;
    FillStyle0       = Shapes->AddFillStyle(mFillStyle);
    FillStyle1       = 0;
    BeginFill();
}

// @0x1425fe950
void DrawingContext::ChangeLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                                     unsigned joins, float miterLimit)
{
    if (rgba & 0xFF000000)
    {
        if (lineWidth <= 0)
            lineWidth = TwipsToPixels(1.0f);
        if (!SameLineStyle(lineWidth, rgba, hinting, scaling, caps, joins, miterLimit))
        {
            AcquirePath(false);
            SetLineStyle(lineWidth, rgba, hinting, scaling, caps, joins, miterLimit);
        }
    }
    else if (!NoLine())
    {
        AcquirePath(false);
        SetNoLine();
    }
}

// @0x1425feb50
// MS2-FUNCTIONAL: register allocation (this in rbx, the zero in rdi; the exe swaps them)
void DrawingContext::Clear()
{
    Shapes      = *SF_HEAP_NEW(pHeap) PackedShape(pHeap);
    States      = State_NewShapeFlag;
    Ex = Ey     = 0;
    StX = StY   = FLT_MIN;
    StrokeStyle = FillStyle0 = 0;
    FillStyle1 = 0;
    UPInt n     = pTreeContainer->GetSize();
    pTreeContainer->Remove(0, n);
    States |= State_Dirty;
}

// @0x1425fec60
// MS2-FUNCTIONAL: the exe guards the frame with a /GS cookie
void DrawingContext::ComputeBound(RectF* pRect) const
{
    UpdateRenderNode();
    UPInt n = pTreeContainer->GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        TreeShape* tsh = (TreeShape*)pTreeContainer->GetAt(i);
        RectF      b   = tsh->GetShape()->GetIdentityBounds();
        if (i == 0)
            *pRect = b;
        else
            pRect->Union(b);
    }
}

// @0x1425fee30
ComplexFill* DrawingContext::CreateLineComplexFill()
{
    if (!(States & State_FreshLineStyle))
        StrokeStyle = Shapes->AddStrokeStyle(mLineStyle);

    Ptr<ComplexFill> cf = *SF_HEAP_NEW(pHeap) ComplexFill();
    StrokeStyleType  ls;
    Shapes->GetStrokeStyle(StrokeStyle, &ls);
    ls.pFill = cf;
    Shapes->UpdateStrokeStyle(StrokeStyle, ls);
    return cf;
}

// @0x1425feff0
ComplexFill* DrawingContext::CreateNewComplexFill()
{
    unsigned         styleIdx = SetNewFill();
    Ptr<ComplexFill> cf       = *SF_HEAP_NEW(pHeap) ComplexFill();
    FillStyleType    fs;
    Shapes->GetFillStyle(styleIdx, &fs);
    fs.pFill = cf;
    Shapes->UpdateFillStyle(styleIdx, fs);
    return cf;
}

// @0x1425ff150
void DrawingContext::CurveTo(float cx, float cy, float ax, float ay)
{
    if (!(States & State_NeedEndPath))
        NewPath(Ex, Ey);
    Shapes->QuadTo(&PosInfo, cx, cy, ax, ay);
    States &= ~State_FreshLineStyle;
    Ex = ax;
    Ey = ay;
    States |= State_Dirty;
}

// @0x1425ff270
// MS2-FUNCTIONAL: the exe guards the frame with a /GS cookie
bool DrawingContext::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase*) const
{
    UpdateRenderNode();
    UPInt n = pTreeContainer->GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        TreeShape*                 tsh       = (TreeShape*)pTreeContainer->GetAt(i);
        Render::ShapeMeshProvider* pmeshProv = tsh->GetShape();
        RectF                      b         = pmeshProv->GetIdentityBounds();
        if (b.Contains(pt))
        {
            if (testShape)
                return Render::HitTestFill<Matrix2F>(*pmeshProv->GetShapeData(), Matrix2F::Identity, pt.x, pt.y);
            return true;
        }
    }
    return false;
}

// @0x1425ff3e0
void DrawingContext::EndFill()
{
    FinishPath();
    FillStyle0 = FillStyle1 = 0;
    StX = StY  = FLT_MIN;
}

// @0x1425ff460
void DrawingContext::FinishPath()
{
    if (States & State_NeedClosePath)
    {
        States &= ~State_NeedClosePath;
        if (Ex != StX || Ey != StY)
            LineTo(StX, StY);
    }
}

// @0x1425ff570
bool DrawingContext::IsSolidFill(unsigned rgba) const
{
    return !mFillStyle.pFill && mFillStyle.Color == rgba;
}

// @0x1425ff590
void DrawingContext::LineTo(float x, float y)
{
    if (!(States & State_NeedEndPath))
        NewPath(Ex, Ey);
    Shapes->LineTo(&PosInfo, x, y);
    States &= ~State_FreshLineStyle;
    Ex = x;
    Ey = y;
    States |= State_Dirty;
}

// @0x1425ff680
void DrawingContext::MoveTo(float x, float y)
{
    PosInfo = ShapePosInfo(0);
    if (!(States & State_FreshFillStyle) && (States & State_NeedClosePath) && (Ex != StX || Ey != StY))
        LineTo(StX, StY);
    NewPath(x, y);
    StX = x;
    StY = y;
    States &= ~State_FreshFillStyle;
}

// @0x1425ff780
void DrawingContext::NewPath(float x, float y)
{
    AcquirePath((States & State_NewShapeFlag) != 0);
    if (States & State_NewShapeFlag)
        Shapes->StartPath(&PosInfo, Render::Shape_NewLayer, FillStyle0, FillStyle1, StrokeStyle, x, y);
    else
        Shapes->StartPath(&PosInfo, Render::Shape_NewPath, FillStyle0, FillStyle1, StrokeStyle, x, y);
    States &= ~State_NewShapeFlag;
    States |= State_NeedEndPath;
    Ex = x;
    Ey = y;
    States |= State_Dirty;
}

// @0x1425ff820
bool DrawingContext::NoLine() const
{
    return Shapes->GetStrokeStyleCount() == 0 || StrokeStyle == 0;
}

// The DrawingContext helpers: inlined everywhere, their own copies are never called.
// @0x1426003e0
bool DrawingContext::SameLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                                   unsigned joins, float miterLimit) const
{
    if (!Shapes->GetStrokeStyleCount() || !StrokeStyle)
        return false;
    StrokeStyleType ls;
    Shapes->GetStrokeStyle(StrokeStyle, &ls);
    if (ls.pFill)
        return false;
    return ls.Color == rgba && int(ls.Width * 20) == int(lineWidth * 20) &&
           ls.Flags == (unsigned(hinting) | scaling | caps | joins) && int(ls.Miter * 20) == int(miterLimit * 20);
}

// @0x1426004f0
void DrawingContext::SetLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                                  unsigned joins, float miterLimit)
{
    mLineStyle.Flags = unsigned(hinting) | scaling | caps | joins;
    mLineStyle.Width = lineWidth;
    mLineStyle.Miter = miterLimit;
    mLineStyle.Color = rgba;
    mLineStyle.Units = TwipsToPixels(1.0f);
    StrokeStyle      = Shapes->AddStrokeStyle(mLineStyle);
    States |= State_FreshLineStyle;
}

// @0x142600550
unsigned DrawingContext::SetNewFill()
{
    mFillStyle.Color = 0;
    mFillStyle.pFill = 0;
    FillStyle0       = Shapes->AddFillStyle(mFillStyle);
    FillStyle1       = 0;
    return FillStyle0;
}

// @0x1426005b0
void DrawingContext::SetNoFill()
{
    FillStyle0 = FillStyle1 = 0;
}

// @0x1426005c0
void DrawingContext::SetNoLine()
{
    StrokeStyle = 0;
    States &= ~State_FreshLineStyle;
}

// @0x1426006a0
// MS2-FUNCTIONAL: scheduling (the exe reloads pTreeContainer for Insert and stores the node's pMeshProvider after
// its vftable; same operations)
void DrawingContext::UpdateRenderNode() const
{
    // Const for the hit tests and bounds; the shape drawn so far moves into a node of its own.
    DrawingContext* self = const_cast<DrawingContext*>(this);
    self->States &= ~State_Dirty;
    if (!IsEmpty())
    {
        unsigned stroke = StrokeStyle, fill0 = FillStyle0;
        self->AcquirePath(true);
        Shapes->EndShape();

        Ptr<ShapeMeshProvider> meshProv = *SF_HEAP_NEW(pHeap) ShapeMeshProvider(Shapes);
        Ptr<TreeShape>         tshp     = *RenContext.CreateEntry<TreeShape>();
        tshp->SetShape(meshProv);
        pTreeContainer->Add(tshp);

        self->Shapes = *SF_HEAP_NEW(pHeap) PackedShape(pHeap);

        // a fill or line style still open goes on in the new shape
        if (fill0)
        {
            self->FillStyle0 = Shapes->AddFillStyle(mFillStyle);
            self->BeginFill();
        }
        if (stroke)
        {
            self->StrokeStyle = Shapes->AddStrokeStyle(mLineStyle);
            self->States |= State_FreshLineStyle;
        }
    }
}

}} // namespace Scaleform::GFx
