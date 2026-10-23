// Recovered Scaleform 4.1.18 Render: the generic RenderBufferManager (Render_BufferGeneric, sfr_render_07i). Temporary
// render targets and depth stencil buffers are textures / surfaces from the TextureManager, kept in LRU lists by the
// frame they were last used in so later frames reuse them instead of recreating them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_BUFFERGENERIC_H
#define MS2_SF_RENDER_BUFFERGENERIC_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/include/render/render_buffer.h"

namespace Scaleform { namespace Render {

namespace RBGenericImpl {

// the list a buffer sits in (index of RenderBufferManager::BufferCache)
enum RBCacheListType
{
    RBCL_Uncached,
    RBCL_InUse,             // handed out, being rendered to
    RBCL_ThisFrame,         // released this frame, contents may be reused
    RBCL_PrevFrame,
    RBCL_LRU,
    RBCL_Reuse_ThisFrame,   // no longer referenced; reusable for anything
    RBCL_Reuse_LRU,
    RBCL_ItemCount
};

class RenderTarget;
class DepthStencilBuffer;

// The cache bookkeeping of a managed buffer (a second base of the buffer classes). 0x30 bytes.
class CacheData : public ListNode<CacheData>
{
public:
    RenderBuffer*   pBuffer;    // +0x10: the buffer this is a base of
    RBCacheListType ListType;   // +0x18
    ImageFormat     Format;     // +0x1c
    UPInt           DataSize;   // +0x20: bytes counted in the manager's AllocSize

    CacheData(RenderBuffer* buffer)
        : ListNode<CacheData>(), pBuffer(buffer), ListType(RBCL_Uncached), Format(Image_None), DataSize(0) { }

    RenderTarget*       GetRenderTarget() const       { return (RenderTarget*)pBuffer; }
    DepthStencilBuffer* GetDepthStencilBuffer() const { return (DepthStencilBuffer*)pBuffer; }

    // a cached buffer serves a request when type and format agree and it is the exact size (exact) or at least the
    // size without wasting more than 5/32 of its area
    bool Match(const ImageSize& size, bool exact, RenderBufferType type, ImageFormat format) const;
};

// vftable 0x143224718; 0xb0 bytes
class RenderBufferManager : public Render::RenderBufferManager
{
    friend class RenderTarget;
    friend class DepthStencilBuffer;

public:
    enum
    {
        ReuseLimit_Zero       = 0,
        ReuseLimit_ScreenSize = ~(UPInt)0   // 8 bytes per screen pixel
    };

    RenderBufferManager(bool requireExactDepthStencil = false, UPInt memReuseLimit = ReuseLimit_ScreenSize,
                        UPInt memAbsoluteLimit = 0);   // 0x1429a3670
    virtual ~RenderBufferManager();

    virtual bool Initialize(TextureManager* manager, ImageFormat format, const ImageSize& screenSize = ImageSize(0));
    virtual void Destroy();
    virtual void EndFrame();
    virtual void Reset();

    virtual Render::RenderTarget*       CreateRenderTarget(const ImageSize& size, RenderBufferType type,
                                                           ImageFormat format, Texture* texture = 0)
    {
        if (!pTextureManager)
            return 0;
        return (Render::RenderTarget*)createRenderTarget(size, type, format, texture);
    }
    virtual Render::RenderTarget*       CreateTempRenderTarget(const ImageSize& size);
    virtual Render::DepthStencilBuffer* CreateDepthStencilBuffer(const ImageSize& size);

protected:
    enum ReserveSpaceResult
    {
        RS_Match,
        RS_Alloc,
        RS_Fail
    };

    RenderTarget* createRenderTarget(const ImageSize& size, RenderBufferType type, ImageFormat format,
                                     Texture* texture = 0);

    // power-of-two sizes when the texture manager needs them, else multiples of 32 (at least 32)
    ImageSize RoundUpImageSize(const ImageSize& size) const
    {
        if (RequirePow2)
        {
            ImageSize rounded(1, 1);
            while (rounded.Width < size.Width)
                rounded.Width <<= 1;
            while (rounded.Height < size.Height)
                rounded.Height <<= 1;
            return rounded;
        }
        return ImageSize(Alg::Max<UInt32>(32, (size.Width + 31) & ~31), Alg::Max<UInt32>(32, (size.Height + 31) & ~31));
    }

    ReserveSpaceResult reserveSpace(CacheData** pdata, const ImageSize& size, RenderBufferType type,
                                    ImageFormat format, UPInt requestSize);
    CacheData*         findMatch(RBCacheListType ltype, const ImageSize& size, RenderBufferType type,
                                 ImageFormat format);

    void pushFront(RBCacheListType ltype, CacheData* p)
    {
        p->ListType = ltype;
        BufferCache[ltype].PushFront(p);
    }
    void moveToFront(RBCacheListType ltype, CacheData* p)
    {
        p->RemoveNode();
        pushFront(ltype, p);
    }
    void moveListToFront(RBCacheListType to, RBCacheListType from)
    {
        BufferCache[to].PushListToFront(BufferCache[from]);
    }

    void evict(CacheData* p);
    void evictAll(RBCacheListType ltype);
    void evictOverReuseLimit(RBCacheListType ltype);
    bool evictUntilAvailable(RBCacheListType ltype, UPInt requestSize);

    Ptr<TextureManager> pTextureManager;            // +0x10
    UPInt               CtorReuseLimit;             // +0x18
    UPInt               ReuseLimit;                 // +0x20
    UPInt               AbsoluteLimit;              // +0x28
    UPInt               AllocSize;                  // +0x30
    ImageFormat         DefImageFormat;             // +0x38
    bool                RequirePow2;                // +0x3c
    bool                RequireExactDepthStencil;   // +0x3d
    List<CacheData>     BufferCache[RBCL_ItemCount];   // +0x40
};

// vftable 0x143224758; 0x78 bytes
class RenderTarget : public Render::RenderTarget, public CacheData
{
    friend class RenderBufferManager;

public:
    RenderTarget(RenderBufferManager* manager, RenderBufferType type, const ImageSize& bufferSize)
        : Render::RenderTarget(manager, type, bufferSize), CacheData(getThis()), RTStatus(RTS_InUse) { }

    RenderTarget* getThis() { return this; }

    virtual Texture*           GetTexture() const { return pTexture; }
    virtual RenderTargetStatus GetStatus() const  { return RTStatus; }
    virtual void               SetInUse(bool inUse);
    virtual void               AddRef() { RefCount++; }
    virtual void               Release();

    void onEvict();

protected:
    RenderBufferManager* getManager() const { return (RenderBufferManager*)pManager; }
    void initTexture(Texture* texture)            { pTexture = texture; }
    void initViewRect(const Rect<int>& viewRect)  { ViewRect = viewRect; }

    Ptr<Texture>       pTexture;   // +0x68
    RenderTargetStatus RTStatus;   // +0x70
};

// vftable 0x143224790; 0x60 bytes
class DepthStencilBuffer : public Render::DepthStencilBuffer, public CacheData
{
    friend class RenderBufferManager;

public:
    DepthStencilBuffer(RenderBufferManager* manager, const ImageSize& bufferSize)
        : Render::DepthStencilBuffer(manager, bufferSize), CacheData(getThis()) { }

    DepthStencilBuffer* getThis() { return this; }

    virtual DepthStencilSurface* GetSurface() const { return pSurface; }
    virtual void                 AddRef() { RefCount++; }
    virtual void                 Release();

    void onEvict();

protected:
    RenderBufferManager* getManager() const { return (RenderBufferManager*)pManager; }
    void initSurface(DepthStencilSurface* surface) { pSurface = surface; }

    Ptr<DepthStencilSurface> pSurface;   // +0x58
};

} // namespace RBGenericImpl

typedef RBGenericImpl::RenderBufferManager RenderBufferManagerGeneric;

}} // namespace Scaleform::Render

#endif
