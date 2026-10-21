// Recovered Scaleform 4.1.18 Render: HAL, the hardware abstraction a Renderer2D draws through. Only the vftable
// prefix the DrawableImage unit calls through (CreateRenderTarget, slot 15); the rest lands with the HAL units.
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
};

}} // namespace Scaleform::Render

#endif
