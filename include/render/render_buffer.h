// Recovered Scaleform 4.1.18 Render: RenderBuffer / RenderTarget, the GPU surfaces a HAL renders into. Only the
// part the DrawableImage unit needs (layout prefix and the accessors it inlines); the rest lands with the HAL units.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_BUFFER_H
#define MS2_SF_RENDER_BUFFER_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_image.h"

namespace Scaleform { namespace Render {

class RenderBufferManager;

class RenderTargetData;   // per-HAL surfaces attached to a render buffer

enum RenderBufferType
{
    RBuffer_Default,
    RBuffer_User,
    RBuffer_Texture,
    RBuffer_Temporary,
    RBuffer_DepthStencil
};

// vftable: dtor 0, AddRef 1, Release 2 (RefCountVImpl)
class RenderBuffer : public RefCountBaseV<RenderBuffer, StatRender_Mem>
{
protected:
    RenderBufferType     Type;                // +0x10
    RenderBufferManager* pManager;            // +0x18
    RenderTargetData*    pRenderTargetData;   // +0x20
    ImageSize            BufferSize;          // +0x28

public:
    RenderBufferType     GetType() const              { return Type; }
    RenderBufferManager* GetManager() const           { return pManager; }
    RenderTargetData*    GetRenderTargetData() const  { return pRenderTargetData; }
    const ImageSize&     GetBufferSize() const        { return BufferSize; }
};

// (appended for sfr_render_04h) whether a render target is still needed, or can be reused
enum RenderTargetUse
{
    RTUse_Unused,             // free, nothing worth keeping
    RTUse_InUse,              // being rendered to or read
    RTUse_Unused_Cacheable    // free, but the contents may serve as a cached result
};

enum RenderTargetStatus
{
    RTS_Available,
    RTS_Lost,
    RTS_Unresolved
};

class RenderTarget : public RenderBuffer
{
protected:
    Rect<int> ViewRect;   // +0x30: the drawable area inside the buffer

public:
    const Rect<int>& GetRect() const { return ViewRect; }
    const ImageSize  GetSize() const { return ImageSize(ViewRect.Width(), ViewRect.Height()); }

    // (appended for sfr_render_04h) vftable after RenderBuffer's: GetTexture 3, GetStatus 4, SetInUse 5 / 6
    virtual Texture*           GetTexture() const = 0;
    virtual RenderTargetStatus GetStatus() const = 0;
    virtual void               SetInUse(RenderTargetUse use) = 0;   // 6 (cl orders the overloads last first)
    virtual void               SetInUse(bool inUse) = 0;            // 5
};

}} // namespace Scaleform::Render

#endif
