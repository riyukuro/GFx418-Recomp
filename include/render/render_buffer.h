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

class RenderTarget : public RenderBuffer
{
};

}} // namespace Scaleform::Render

#endif
