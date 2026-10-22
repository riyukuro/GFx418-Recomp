// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the generic render buffer
// manager (Render_BufferGeneric): temporary render targets and depth stencil buffers from the texture manager, kept
// in per-frame LRU lists so later frames reuse them.
// Queue unit sfr_render_07 is split along its original sources (07i Render_BufferGeneric).
// MS2-UNIT: sfr_render_07i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a3700-0x1429a4ad0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_buffergeneric.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"

namespace Scaleform { namespace Render { namespace RBGenericImpl {

// ----- CacheData

bool CacheData::Match(const ImageSize& size, bool exact, RenderBufferType type, ImageFormat format) const
{
    if (pBuffer->GetType() == type && Format == format)
    {
        const ImageSize& cached = pBuffer->GetBufferSize();
        if (exact)
            return size.Width == cached.Width && size.Height == cached.Height;
        if (size.Width > cached.Width || size.Height > cached.Height)
            return false;
        return (cached.Width * cached.Height * 27) / 32 <= size.Width * size.Height;
    }
    return false;
}

// ----- RenderBufferManager

// @0x1429a3700
RenderBufferManager::~RenderBufferManager()
{
    Destroy();
}

// @0x1429a3fd0
bool RenderBufferManager::Initialize(TextureManager* manager, ImageFormat format, const ImageSize& screenSize)
{
    pTextureManager = manager;
    DefImageFormat  = format;
    RequirePow2     = !manager->IsNonPow2Supported(format, ImageUse_RenderTarget);
    if (CtorReuseLimit == ReuseLimit_ScreenSize)
        ReuseLimit = (screenSize.Width == 0 && screenSize.Height == 0) ? 0 : screenSize.Width * screenSize.Height * 8;
    else
        ReuseLimit = CtorReuseLimit;
    return true;
}

// @0x1429a3ea0
void RenderBufferManager::Destroy()
{
    Reset();
    DefImageFormat = Image_None;
    pTextureManager.Clear();
}

// @0x1429a3ee0
void RenderBufferManager::EndFrame()
{
    evictOverReuseLimit(RBCL_Reuse_LRU);
    evictOverReuseLimit(RBCL_LRU);
    moveListToFront(RBCL_LRU, RBCL_PrevFrame);
    moveListToFront(RBCL_PrevFrame, RBCL_ThisFrame);
    moveListToFront(RBCL_Reuse_LRU, RBCL_Reuse_ThisFrame);
}

// @0x1429a41c0
void RenderBufferManager::Reset()
{
    evictAll(RBCL_ThisFrame);
    evictAll(RBCL_PrevFrame);
    evictAll(RBCL_LRU);
    evictAll(RBCL_Reuse_ThisFrame);
    evictAll(RBCL_Reuse_LRU);
}

// @0x1429a3cb0
Render::RenderTarget* RenderBufferManager::CreateTempRenderTarget(const ImageSize& size)
{
    if (!pTextureManager)
        return 0;

    RenderTarget* target = 0;
    CacheData*    data   = 0;
    ImageSize     rounded = RoundUpImageSize(size);
    ImageFormat   format  = DefImageFormat;
    UInt32        area    = rounded.Area();
    UPInt         requestSize = (UInt32)(area * ImageData::GetFormatBitsPerPixel(format, 0)) / 8;

    switch (reserveSpace(&data, rounded, RBuffer_Temporary, format, requestSize))
    {
    case RS_Match:
        target = data->GetRenderTarget();
        target->SetInUse(true);
        target->initViewRect(Rect<int>(0, 0, size.Width, size.Height));
        target->AddRef();
        break;

    case RS_Alloc:
    {
        Ptr<Texture> texture = *pTextureManager->CreateTexture(format, 1, rounded, ImageUse_RenderTarget, 0, 0);
        if (texture)
        {
            target = createRenderTarget(rounded, RBuffer_Temporary, format, texture);
            if (target)
            {
                pushFront(RBCL_InUse, target);
                target->initViewRect(Rect<int>(0, 0, size.Width, size.Height));
                target->DataSize = requestSize;
                AllocSize += requestSize;
            }
        }
        break;
    }

    default:
        break;
    }
    return target;
}

// @0x1429a3a10
Render::DepthStencilBuffer* RenderBufferManager::CreateDepthStencilBuffer(const ImageSize& size)
{
    if (!pTextureManager)
        return 0;

    DepthStencilBuffer* buffer = 0;
    CacheData*          data   = 0;
    ImageSize           rounded = RequireExactDepthStencil ? size : RoundUpImageSize(size);
    UPInt               requestSize = (UInt32)(rounded.Width * rounded.Height * 4);

    switch (reserveSpace(&data, rounded, RBuffer_DepthStencil, Image_None, requestSize))
    {
    case RS_Match:
        moveToFront(RBCL_InUse, data);
        buffer = data->GetDepthStencilBuffer();
        buffer->AddRef();
        break;

    case RS_Alloc:
    {
        Ptr<DepthStencilSurface> surface = *pTextureManager->CreateDepthStencilSurface(rounded);
        if (surface)
        {
            buffer = SF_HEAP_AUTO_NEW(this) DepthStencilBuffer(this, rounded);
            if (buffer)
            {
                buffer->initSurface(surface);
                pushFront(RBCL_InUse, buffer);
                buffer->DataSize = requestSize;
                AllocSize += requestSize;
            }
        }
        break;
    }

    default:
        break;
    }
    return buffer;
}

// @0x1429a42c0
RenderTarget* RenderBufferManager::createRenderTarget(const ImageSize& size, RenderBufferType type,
                                                      ImageFormat format, Texture* texture)
{
    RenderTarget* target = SF_HEAP_AUTO_NEW(this) RenderTarget(this, type, size);
    if (target)
    {
        target->Format = format;
        target->initTexture(texture);
        target->initViewRect(Rect<int>(0, 0, size.Width, size.Height));
    }
    return target;
}

// @0x1429a4900
RenderBufferManager::ReserveSpaceResult RenderBufferManager::reserveSpace(CacheData** pdata, const ImageSize& size,
                                                                           RenderBufferType type, ImageFormat format,
                                                                           UPInt requestSize)
{
    if (AbsoluteLimit && requestSize > AbsoluteLimit)
        return RS_Fail;

    // reusable buffers first, then evict them to make room
    if ((*pdata = findMatch(RBCL_Reuse_LRU, size, type, format)) != 0)
        return RS_Match;
    if ((*pdata = findMatch(RBCL_Reuse_ThisFrame, size, type, format)) != 0)
        return RS_Match;
    if (evictUntilAvailable(RBCL_Reuse_LRU, requestSize))
        return RS_Alloc;

    // then the frame lists, oldest first
    if ((*pdata = findMatch(RBCL_LRU, size, type, format)) != 0)
        return RS_Match;
    if (evictUntilAvailable(RBCL_LRU, requestSize))
        return RS_Alloc;
    if (evictUntilAvailable(RBCL_Reuse_ThisFrame, requestSize))
        return RS_Alloc;
    if ((*pdata = findMatch(RBCL_PrevFrame, size, type, format)) != 0)
        return RS_Match;
    if (evictUntilAvailable(RBCL_PrevFrame, requestSize))
        return RS_Alloc;
    if ((*pdata = findMatch(RBCL_ThisFrame, size, type, format)) != 0)
        return RS_Match;
    if (evictUntilAvailable(RBCL_ThisFrame, requestSize))
        return RS_Alloc;

    if (AbsoluteLimit && AllocSize + requestSize > AbsoluteLimit)
        return RS_Fail;
    return RS_Alloc;
}

// @0x1429a47a0
CacheData* RenderBufferManager::findMatch(RBCacheListType ltype, const ImageSize& size, RenderBufferType type,
                                          ImageFormat format)
{
    CacheData* p = BufferCache[ltype].GetLast();
    while (!BufferCache[ltype].IsNull(p))
    {
        if (p->Match(size, RequireExactDepthStencil && type == RBuffer_DepthStencil, type, format))
            return p;
        p = p->pPrev;
    }
    return 0;
}

// @0x1429a43f0
void RenderBufferManager::evict(CacheData* p)
{
    p->RemoveNode();
    p->ListType = RBCL_Uncached;
    AllocSize  -= p->DataSize;
    p->DataSize = 0;

    RenderBufferType type = p->pBuffer->GetType();
    if (type == RBuffer_Temporary)
        p->GetRenderTarget()->onEvict();
    else if (type == RBuffer_DepthStencil)
        p->GetDepthStencilBuffer()->onEvict();
}

// @0x1429a4490
void RenderBufferManager::evictAll(RBCacheListType ltype)
{
    while (!BufferCache[ltype].IsEmpty())
        evict(BufferCache[ltype].GetFirst());
}

// @0x1429a4580
void RenderBufferManager::evictOverReuseLimit(RBCacheListType ltype)
{
    while (AllocSize > ReuseLimit)
    {
        CacheData* p = BufferCache[ltype].GetLast();
        if (BufferCache[ltype].IsNull(p))
            break;
        evict(p);
    }
}

// @0x1429a4680
bool RenderBufferManager::evictUntilAvailable(RBCacheListType ltype, UPInt requestSize)
{
    while (AllocSize + requestSize > ReuseLimit)
    {
        CacheData* p = BufferCache[ltype].GetLast();
        if (BufferCache[ltype].IsNull(p))
            break;
        evict(p);
    }
    return AllocSize + requestSize <= ReuseLimit;
}

// ----- RenderTarget

void RenderTarget::SetInUse(bool inUse)
{
    if (inUse)
    {
        if (Type == RBuffer_Temporary)
            getManager()->moveToFront(RBCL_InUse, this);
        RTStatus = RTS_InUse;
    }
    else
    {
        if (Type == RBuffer_Temporary && ListType < RBCL_ThisFrame)
            getManager()->moveToFront(RBCL_ThisFrame, this);
        RTStatus = RTS_Available;
    }
}

void RenderTarget::Release()
{
    if (--RefCount > 0)
        return;
    if (pBuffer->GetType() != RBuffer_Temporary || RTStatus == RTS_Lost)
    {
        delete this;
        return;
    }
    // no longer referenced: reusable for anything
    getManager()->moveToFront(ListType > RBCL_ThisFrame ? RBCL_Reuse_LRU : RBCL_Reuse_ThisFrame, this);
    RTStatus = RTS_Available;
}

// @0x1429a4890
void RenderTarget::onEvict()
{
    pTexture.Clear();
    destroyRenderTargetData();
    RTStatus = RTS_Lost;
    if (RefCount == 0)
        delete this;
}

// ----- DepthStencilBuffer

void DepthStencilBuffer::Release()
{
    if (--RefCount > 0)
        return;
    getManager()->moveToFront(ListType > RBCL_ThisFrame ? RBCL_Reuse_LRU : RBCL_Reuse_ThisFrame, this);
}

void DepthStencilBuffer::onEvict()
{
    delete this;
}

}}} // namespace Scaleform::Render::RBGenericImpl

// the base of Render::RenderBufferManager; its vftable and deleting dtor land in this unit
template class Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl, Scaleform::Render::StatRender_TextureManager_Mem>;

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7RenderBuffer@Render@Scaleform@@6B@ 0x14319d6e0
// MS2-PIN: ??_7RenderTarget@Render@Scaleform@@6B@ 0x14319d6f8
// MS2-PIN: ??_7RenderBufferManager@RBGenericImpl@Render@Scaleform@@6B@ 0x143224718
// MS2-PIN: ??_7RenderBufferManager@Render@Scaleform@@6B@ 0x1432246d8
// MS2-PIN: ??_7RenderTarget@RBGenericImpl@Render@Scaleform@@6B@ 0x143224758
// MS2-PIN: ??_7DepthStencilBuffer@RBGenericImpl@Render@Scaleform@@6B@ 0x143224790
