// Recovered Scaleform 4.1.18 Render: RenderBuffer / RenderTarget / DepthStencilBuffer, the GPU surfaces a HAL renders
// into, and the RenderBufferManager interface that hands them out (implemented by Render_BufferGeneric, sfr_render_07i).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_BUFFER_H
#define MS2_SF_RENDER_BUFFER_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_image.h"

namespace Scaleform { namespace Render {

class RenderBufferManager;
class DepthStencilSurface;
// (appended for sfr_render_06g)
class RenderBuffer;
class DepthStencilBuffer;

// per-HAL surfaces attached to a render buffer; the buffer owns it
class RenderTargetData : public NewOverrideBase<StatRender_TextureManager_Mem>
{
public:
    // (inline: the exe expands it into D3D9::RenderTargetData's ctor)
    RenderTargetData(RenderBuffer* buffer, DepthStencilBuffer* pdsb)
        : pBuffer(buffer), pDepthStencilBuffer(pdsb), CacheID(0)
    {
    }
    virtual ~RenderTargetData();

    // (appended for sfr_render_06g) the buffer this data belongs to and the depth stencil drawn with it
    RenderBuffer*           pBuffer;               // +0x08
    Ptr<DepthStencilBuffer> pDepthStencilBuffer;   // +0x10
    UPInt                   CacheID;               // +0x18
};

// (values as the exe compares them: temporary 3, depth stencil 5)
enum RenderBufferType
{
    RBuffer_None,
    RBuffer_Default,
    RBuffer_User,
    RBuffer_Temporary,     // CreateTempRenderTarget
    RBuffer_Texture,       // wraps a user texture
    RBuffer_DepthStencil   // CreateDepthStencilBuffer
};

// vftable: dtor 0, AddRef 1, Release 2; the base reference counting does nothing, the managed buffers override it
class RenderBuffer : public NewOverrideBase<StatRender_TextureManager_Mem>, public RefCountVImpl
{
protected:
    RenderBufferType     Type;                // +0x10
    RenderBufferManager* pManager;            // +0x18
    RenderTargetData*    pRenderTargetData;   // +0x20
    ImageSize            BufferSize;          // +0x28

    void destroyRenderTargetData()
    {
        if (pRenderTargetData)
        {
            delete pRenderTargetData;
            pRenderTargetData = 0;
        }
    }

public:
    RenderBuffer(RenderBufferManager* manager, RenderBufferType type, const ImageSize& bufferSize)
        : RefCountVImpl(), Type(type), pManager(manager), pRenderTargetData(0), BufferSize(bufferSize) { }
    virtual ~RenderBuffer() { destroyRenderTargetData(); }

    virtual void AddRef()  { }
    virtual void Release() { }

    RenderBufferType     GetType() const              { return Type; }
    RenderBufferManager* GetManager() const           { return pManager; }
    RenderTargetData*    GetRenderTargetData() const  { return pRenderTargetData; }
    const ImageSize&     GetBufferSize() const        { return BufferSize; }
    // (appended for sfr_d3d9_01e) the HAL attaches its surfaces on first use
    void                 SetRenderTargetData(RenderTargetData* data) { pRenderTargetData = data; }
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
    RTS_InUse,        // holds content this frame renders with
    RTS_Available,    // allocated, may hold earlier content
    RTS_Unresolved,   // in video memory, not resolved to a texture
    RTS_Lost          // evicted; must be recreated
};

class RenderTarget : public RenderBuffer
{
protected:
    Rect<int> ViewRect;   // +0x30: the drawable area inside the buffer

public:
    RenderTarget(RenderBufferManager* manager, RenderBufferType type, const ImageSize& bufferSize)
        : RenderBuffer(manager, type, bufferSize), ViewRect(0, 0, bufferSize.Width, bufferSize.Height) { }

    const Rect<int>& GetRect() const { return ViewRect; }
    const ImageSize  GetSize() const { return ImageSize(ViewRect.Width(), ViewRect.Height()); }

    // (appended for sfr_render_04h) vftable after RenderBuffer's: GetTexture 3, GetStatus 4, SetInUse 5 / 6; the
    // base forms (0x142732110 / 0x1427320f0 / 0x1427359c0 / 0x1427359b0) forward each SetInUse to the other
    virtual Texture*           GetTexture() const { return 0; }
    virtual RenderTargetStatus GetStatus() const  { return RTS_Lost; }
    virtual void               SetInUse(RenderTargetUse use) { SetInUse(use == RTUse_InUse); }   // 6 (cl orders the overloads last first)
    virtual void               SetInUse(bool inUse) { SetInUse(inUse ? RTUse_InUse : RTUse_Unused); }   // 5
};

// vftable 0x14319d730: RenderBuffer's, GetSurface 3. The HAL makes plain ones around foreign depth surfaces
// (D3D9::HAL::CreateRenderTarget), so it has a vftable of its own.
class DepthStencilBuffer : public RenderBuffer
{
public:
    DepthStencilBuffer(RenderBufferManager* manager, const ImageSize& bufferSize)
        : RenderBuffer(manager, RBuffer_DepthStencil, bufferSize) { }

    virtual DepthStencilSurface* GetSurface() const { return 0; }
};

class TextureManager;

// Hands out the render targets and depth stencil buffers the HAL renders filters / cached results into.
// vftable: dtor 0, Initialize 1, Destroy 2, EndFrame 3, Reset 4, CreateRenderTarget 5, CreateTempRenderTarget 6,
// CreateDepthStencilBuffer 7
class RenderBufferManager : public RefCountBase<RenderBufferManager, StatRender_TextureManager_Mem>
{
public:
    virtual ~RenderBufferManager() { }

    virtual bool Initialize(TextureManager* manager, ImageFormat format, const ImageSize& screenSize = ImageSize(0)) = 0;
    virtual void Destroy() = 0;
    virtual void EndFrame() = 0;
    virtual void Reset() = 0;

    virtual RenderTarget*       CreateRenderTarget(const ImageSize& size, RenderBufferType type, ImageFormat format,
                                                   Texture* texture = 0) = 0;
    virtual RenderTarget*       CreateTempRenderTarget(const ImageSize& size) = 0;
    virtual DepthStencilBuffer* CreateDepthStencilBuffer(const ImageSize& size) = 0;
};

}} // namespace Scaleform::Render

#endif
