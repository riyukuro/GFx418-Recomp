// Recovered Scaleform 4.1.18 Render: HAL, the hardware abstraction a Renderer2D draws through. Only the vftable
// prefix the DrawableImage unit calls through (CreateRenderTarget 15, Push/PopRenderTarget 18/19, DrawableCopyback 49);
// the rest lands with the HAL units.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_HAL_H
#define MS2_SF_RENDER_HAL_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_buffer.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_events.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/include/render/render_constants.h"
#include "ms2/scaleform/include/render/render_cxform.h"

namespace Scaleform { namespace Render {

class Viewport;
class RenderBufferManager;
class DepthStencilBuffer;
class PrimitiveFill;
struct PrimitiveFillData;
class MeshCache;
class FilterPrimitive;
// (appended for sfr_render_07p)
class Primitive;
class PrimitiveBatch;
struct DICommand;
// (appended for sfr_render_07q)
class RenderQueueItem;
class MaskPrimitive;

class HAL : public RefCountBase<HAL, StatRender_Mem>
{
public:
    virtual ~HAL() {}                                                                              // 0
    virtual bool IsInitialized() const = 0;                                                        // 1
    virtual bool BeginFrame() = 0;                                                                 // 2
    virtual void EndFrame() = 0;                                                                   // 3
    virtual void Flush() = 0;                                                                      // 4
    virtual bool BeginScene() = 0;                                                                 // 5
    virtual bool EndScene() = 0;                                                                   // 6
    virtual void beginDisplay(Color backgroundColor, const Viewport& viewport) = 0;                // 7
    virtual void endDisplay() = 0;                                                                 // 8
    virtual void SetUserMatrix(const Matrix2F& userMatrix) = 0;                                    // 9
    virtual void GetOrientationMatrix(Matrix2F* m) const = 0;                                      // 10
    virtual void updateViewport() = 0;                                                             // 11
    virtual void clearSolidRectangle(const Rect<int>& r, Color color) = 0;                         // 12
    virtual RenderBufferManager* GetRenderBufferManager() const = 0;                               // 13
    virtual RenderTarget* GetDefaultRenderTarget() = 0;                                            // 14
    virtual RenderTarget* CreateRenderTarget(Texture* texture, bool needsStencil) = 0;              // 15
    virtual RenderTarget* CreateTempRenderTarget(const ImageSize& size, bool needsStencil) = 0;    // 16
    virtual bool SetRenderTarget(RenderTarget* target, bool setState = 1) = 0;                     // 17
    virtual void PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags = 0) = 0;  // 18
    virtual void PopRenderTarget() = 0;                                                            // 19 (no flags in this build)
    // slots 20-48 are not called from the recovered units yet (placeholders keep the slot numbers)
    virtual void halSlot20() = 0;                                                                 // 20
    virtual void halSlot21() = 0;                                                                 // 21
    virtual PrimitiveFill* CreatePrimitiveFill(const PrimitiveFillData& data) = 0;                 // 22
    virtual void halSlot23() = 0;                                                                 // 23
    virtual void halSlot24() = 0;                                                                 // 24
    virtual void halSlot25() = 0;                                                                 // 25
    virtual void halSlot26() = 0;                                                                 // 26
    // (named for sfr_render_07q) queues the item for drawing
    virtual void Draw(const RenderQueueItem& item) = 0;                                           // 27
    // (named for sfr_render_07p) draws the prepared batches [start, end) of a primitive
    virtual void DrawProcessedPrimitive(Primitive* p, PrimitiveBatch* start, PrimitiveBatch* end) = 0;   // 28
    virtual void halSlot29() = 0;                                                                 // 29
    // (named for sfr_render_07q) a mask: push it and draw its areas into the stencil, then draw clipped by it
    virtual void PushMask_BeginSubmit(MaskPrimitive* primitive) = 0;                              // 30
    virtual void EndMaskSubmit() = 0;                                                             // 31
    virtual void PopMask() = 0;                                                                   // 32
    virtual void halSlot33() = 0;                                                                 // 33
    virtual void halSlot34() = 0;                                                                 // 34
    virtual void applyBlendMode(BlendMode mode, bool sourceAc = false, bool forceAc = false) = 0;  // 35
    virtual void PrepareFilters(FilterPrimitive* primitive) = 0;                                  // 36
    virtual void PushFilters(FilterPrimitive* primitive) = 0;                                     // 37
    virtual void PopFilters() = 0;                                                                // 38
    virtual void halSlot39() = 0;                                                                 // 39
    virtual void halSlot40() = 0;                                                                 // 40
    virtual unsigned DrawableCommandGetFlags(const DICommand* command) const = 0;                 // 41
    // the DrawableImage operations drawn through the HAL (sources in tex, their texture matrices in texgen)
    virtual void DrawableCxform(Texture** tex, const Matrix2F* texgen, const Cxform* cx) = 0;       // 42
    virtual void DrawableCompare(Texture** tex, const Matrix2F* texgen) = 0;                        // 43
    virtual void DrawableCopyChannel(Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul) = 0;   // 44
    virtual void DrawableMerge(Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul) = 0;   // 45
    virtual void DrawableCopyPixels(Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp,
                                    bool mergeAlpha, bool destAlpha) = 0;                          // 46
    virtual void halSlot47() = 0;                                                                 // 47
    virtual void halSlot48() = 0;                                                                 // 48
    virtual void DrawableCopyback(Texture* tex, const Matrix2F& mvp, const Matrix2F& texgen) = 0;   // 49
    // (appended for the shape cache nodes, sfr_render_03f)
    virtual void halSlot50() = 0;                                                                 // 50
    virtual RenderEvent& GetEvent(EventType type) = 0;                                            // 51
    virtual TextureManager* GetTextureManager() = 0;                                              // 52
    // (appended for sfr_render_04f)
    virtual MeshCache& GetMeshCache() = 0;                                                        // 53
    virtual void halSlot54() = 0;                                                                 // 54
    virtual void halSlot55() = 0;                                                                 // 55
    // the hardware vertex formats a fill is drawn with: plain, batched and instanced
    virtual void MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                                 const VertexFormat** single, const VertexFormat** batch,
                                 const VertexFormat** instanced, unsigned meshType) = 0;          // 56
    // (appended for sfr_render_04h)
    virtual void halSlot57() = 0;                                                                 // 57
    virtual void halSlot58() = 0;                                                                 // 58
    virtual void halSlot59() = 0;                                                                 // 59
    // the y scale of a render target pass (the HALs differ in the direction of y)
    virtual float GetViewportScaling() const = 0;                                                 // 60

    // (appended for sfr_render_04f) the 3D view and projection, with the stacks the queue items push them on
    // (appended for sfr_render_04g) the state bits, and the display bracket around a viewport's drawing
    enum HALStateFlags
    {
        HS_ModeSet   = 0x01,
        HS_InFrame   = 0x02,   // between BeginFrame and EndFrame
        HS_InScene   = 0x04,   // between BeginScene and EndScene
        HS_InDisplay = 0x08
    };
    unsigned GetHALState() const { return HALState; }
    void     BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void     EndDisplay();

    unsigned          HALState;                  // +0x10
protected:
    UByte             Unk_Members[0x50 - 0x14];
public:
    Matrix3F          View3D;                    // +0x50
    Matrix4F          Proj3D;                    // +0x80
protected:
    UByte             Unk_Members2[0x2a0 - 0xc0];
public:
    bool              UVPOChanged;               // +0x2a0, the combined matrices need rebuilding
protected:
    UByte             Unk_Members3[0x468 - 0x2a1];
public:
    ArrayLH<Matrix3F, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> > ViewMatrix3DStack;         // +0x468
    ArrayLH<Matrix4F, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> > ProjectionMatrix3DStack;   // +0x480
    // (appended for sfr_render_04h)
protected:
    UByte             Unk_Members4[0x530 - 0x498];
public:
    Viewport          VP;                        // +0x530, the viewport of the current display

    void PushView3D(const Matrix3F& m)
    {
        View3D.Set(&m.M[0][0], 12);
        UVPOChanged = 1;
        ViewMatrix3DStack.PushBack(m);
    }
    void PopView3D()
    {
        ViewMatrix3DStack.PopBack();
        const Matrix3F& top = ViewMatrix3DStack.GetSize() ? ViewMatrix3DStack.Back() : Matrix3F::Identity;
        View3D.Set(&top.M[0][0], 12);
        UVPOChanged = 1;
    }
    void PushProj3D(const Matrix4F& m)
    {
        Proj3D      = m;
        UVPOChanged = 1;
        ProjectionMatrix3DStack.PushBack(m);
    }
    void PopProj3D()
    {
        ProjectionMatrix3DStack.PopBack();
        Proj3D      = ProjectionMatrix3DStack.GetSize() ? ProjectionMatrix3DStack.Back() : Matrix4F::Identity;
        UVPOChanged = 1;
    }
};

}} // namespace Scaleform::Render

#endif
