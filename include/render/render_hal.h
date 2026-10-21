// Recovered Scaleform 4.1.18 Render: HAL, the hardware abstraction a Renderer2D draws through. Only the vftable
// prefix the DrawableImage unit calls through (CreateRenderTarget 15, Push/PopRenderTarget 18/19, DrawableCopyback 49);
// the rest lands with the HAL units.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_HAL_H
#define MS2_SF_RENDER_HAL_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_buffer.h"

namespace Scaleform { namespace Render {

class Viewport;
class RenderBufferManager;
class DepthStencilBuffer;

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
    virtual void PopRenderTarget(unsigned flags = 0) = 0;                                          // 19
    // slots 20-48 are not called from the recovered units yet (placeholders keep the slot numbers)
    virtual void halSlot20() = 0;                                                                 // 20
    virtual void halSlot21() = 0;                                                                 // 21
    virtual void halSlot22() = 0;                                                                 // 22
    virtual void halSlot23() = 0;                                                                 // 23
    virtual void halSlot24() = 0;                                                                 // 24
    virtual void halSlot25() = 0;                                                                 // 25
    virtual void halSlot26() = 0;                                                                 // 26
    virtual void halSlot27() = 0;                                                                 // 27
    virtual void halSlot28() = 0;                                                                 // 28
    virtual void halSlot29() = 0;                                                                 // 29
    virtual void halSlot30() = 0;                                                                 // 30
    virtual void halSlot31() = 0;                                                                 // 31
    virtual void halSlot32() = 0;                                                                 // 32
    virtual void halSlot33() = 0;                                                                 // 33
    virtual void halSlot34() = 0;                                                                 // 34
    virtual void halSlot35() = 0;                                                                 // 35
    virtual void halSlot36() = 0;                                                                 // 36
    virtual void halSlot37() = 0;                                                                 // 37
    virtual void halSlot38() = 0;                                                                 // 38
    virtual void halSlot39() = 0;                                                                 // 39
    virtual void halSlot40() = 0;                                                                 // 40
    virtual void halSlot41() = 0;                                                                 // 41
    virtual void halSlot42() = 0;                                                                 // 42
    virtual void halSlot43() = 0;                                                                 // 43
    virtual void halSlot44() = 0;                                                                 // 44
    virtual void halSlot45() = 0;                                                                 // 45
    virtual void halSlot46() = 0;                                                                 // 46
    virtual void halSlot47() = 0;                                                                 // 47
    virtual void halSlot48() = 0;                                                                 // 48
    virtual void DrawableCopyback(Texture* tex, const Matrix2F& mvp, const Matrix2F& texgen) = 0;   // 49
};

}} // namespace Scaleform::Render

#endif
