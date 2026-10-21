// Recovered Scaleform 4.1.18 GFx: DrawingContext, the shape a script draws into (the AS drawing API of clips, and
// the mask shape of a scrollRect). Bodies: GFx_DrawingContext (queue unit sfr_gfx_06, file 06e).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout is the exe's (0xd8 bytes, vftable 0x14318e800): pHeap +0x20, pTreeContainer +0x28, RenContext +0x30,
// ImgCreator +0x38, Shapes +0x40, mFillStyle +0x48, mLineStyle +0x58, StrokeStyle +0x80, FillStyle0 / 1 +0x84,
// PosInfo +0x8c, Ex / Ey +0xc4, StX / StY +0xcc, States +0xd4. PackedShape is 0x80 bytes (vftable 0x14318e7a8).
#ifndef MS2_SF_GFX_DRAWINGCONTEXT_H
#define MS2_SF_GFX_DRAWINGCONTEXT_H

#include "../kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "gfx_characterdef.h"
#include "../render/render_shapedata.h"

namespace Scaleform { namespace Render {
class TreeContainer;
namespace ContextImpl { class Context; }
}}

namespace Scaleform { namespace GFx {

class DisplayObjectBase;
namespace AS2 { class AvmSprite; }
class ImageCreator;
class ImageResource;

// The fill kinds of beginBitmapFill (the SWF fill style codes).
enum FillType
{
    Fill_TiledSmoothImage   = 0x40,
    Fill_ClippedSmoothImage = 0x41,
    Fill_TiledImage         = 0x42,
    Fill_ClippedImage       = 0x43
};

class DrawingContext : public RefCountBaseNTS<DrawingContext, 322>, public ListNode<DrawingContext>
{
public:
    // Bounds of everything drawn so far, in the clip's space (0x1425fec60).
    void ComputeBound(RectF* pRect) const;
    // Hit test of the drawn shapes, testShape asking for the exact outline instead of the bounds (0x1425ff270).
    bool DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const;

    // (appended for the scrollRect of the display objects, sfr_gfx_06) the container node of the drawn shapes
    Render::TreeContainer* GetTreeNode() const { return pTreeContainer; }

    void BeginSolidFill(unsigned rgba);   // 0x1425fe8f0
    void MoveTo(float x, float y);        // 0x1425ff680
    void LineTo(float x, float y);        // 0x1425ff590
    void EndFill();                       // 0x1425ff3e0
    void UpdateRenderNode() const;        // 0x1426006a0

    MemoryHeap*                pHeap;            // +0x20
    Ptr<Render::TreeContainer> pTreeContainer;   // +0x28

    // (appended for the drawing API, sfr_gfx_06e)
    typedef ArrayDH<UByte>                         ContainerType;
    typedef Render::ShapeDataPacked<ContainerType> BaseShapeType;

    // The shape being drawn: packed path data in a container of its own.
    class PackedShape : public BaseShapeType
    {
    public:
        PackedShape(MemoryHeap* heap) : BaseShapeType(&Container, 0, 1.0f), Container(heap) {}

    private:
        ContainerType Container;   // +0x60
    };

    DrawingContext(MemoryHeap* pheap, Render::ContextImpl::Context& renContext, ImageCreator* imgCreator);
    ~DrawingContext();

    // Ends the open path into the shape; false when nothing was drawn yet.
    bool AcquirePath(bool newShapeFlag);
    void BeginFill();
    bool IsSolidFill(unsigned rgba) const;
    void BeginBitmapFill(FillType fillType, ImageResource* pimageRes, const Render::Matrix2F& mtx);
    void Clear();
    // A new fill / line style whose complex fill the caller fills in (beginGradientFill, lineGradientStyle).
    Render::ComplexFill* CreateNewComplexFill();
    Render::ComplexFill* CreateLineComplexFill();
    // Coordinates in twips.
    void CurveTo(float cx, float cy, float ax, float ay);
    void SetNoLine();
    // lineWidth in pixels
    void ChangeLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                         unsigned joins, float miterLimit);
    bool NoLine() const;
    bool IsEmpty() const { return !Shapes || Shapes->IsEmpty(); }

protected:
    enum
    {
        State_NewShapeFlag   = 0x01,
        State_FreshLineStyle = 0x02,
        State_FreshFillStyle = 0x04,
        State_NeedEndPath    = 0x08,
        State_NeedClosePath  = 0x10,
        State_Dirty          = 0x80
    };

    unsigned SetNewFill();
    void     NewPath(float x, float y);
    void     FinishPath();
    // lineWidth in twips
    void     SetLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                          unsigned joins, float miterLimit);
    bool     SameLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                           unsigned joins, float miterLimit) const;
    // (appended for the drawing API, sfr_gfx_06e) no fill on either side
    void     SetNoFill();

    Render::ContextImpl::Context& RenContext;    // +0x30
    Ptr<ImageCreator>             ImgCreator;    // +0x38
    Ptr<PackedShape>              Shapes;        // +0x40
    Render::FillStyleType         mFillStyle;    // +0x48
    Render::StrokeStyleType       mLineStyle;    // +0x58
    unsigned                      StrokeStyle;   // +0x80
    unsigned                      FillStyle0;    // +0x84
    unsigned                      FillStyle1;    // +0x88
    Render::ShapePosInfo          PosInfo;       // +0x8c
    float                         Ex, Ey;        // +0xc4 the pen
    float                         StX, StY;      // +0xcc where the fill started
    UByte                         States;        // +0xd4

    friend class AS2::AvmSprite; // (appended for sfr_as2_07) SetNoFill
};

}} // namespace Scaleform::GFx

#endif
