// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 HAL TU (D3D9_HAL):
// construction / destruction, the debug events, the static shader manager's format mapping and filter passes, and
// the uniform upload of the shader interface.
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01e D3D9_HAL).
// MS2-UNIT: sfr_d3d9_01e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14272d9c0-0x142738e60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin


#include <stdlib.h>
#include <new>
#include <d3d9.h>
#include "ms2/scaleform/include/render/d3d9_hal.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/render_events.h"

// the warning a HAL call made in the wrong state would print; empty in this build
void FUN_1426c1790(Scaleform::Render::HAL* hal, unsigned stateFlags, const char* funcName);

// StaticShaderManager::SetPrimitiveFill (0x1427359d0): picks the shader of a batch and sets its meshes' uniforms
const Scaleform::Render::D3D9::ShaderPair* FUN_1427359d0(
    Scaleform::Render::D3D9::ShaderManager* sm, Scaleform::Render::PrimitiveFill* fill, unsigned* fillFlags,
    unsigned batchType, const Scaleform::Render::VertexFormat* format, unsigned meshCount,
    Scaleform::Render::MatrixState* matrices, const Scaleform::Render::Primitive::MeshEntry* meshes,
    Scaleform::Render::D3D9::ShaderInterface* psi);

// StaticShaderManager's drawable fills (sfr_d3d9_01e, below)
bool FUN_142731310(Scaleform::Render::D3D9::ShaderManager* sm, unsigned srcCount, Scaleform::Render::Texture** tex,
                   const Scaleform::Render::Matrix2F* texgen, Scaleform::Render::Size<int> texsize,
                   const Scaleform::Render::Matrix2F& mvp, Scaleform::Render::D3D9::ShaderInterface* psi,
                   unsigned flags);
bool FUN_142734410(Scaleform::Render::D3D9::ShaderManager* sm, Scaleform::Render::Texture** tex,
                   const Scaleform::Render::Matrix2F* texgen, Scaleform::Render::Size<int> texsize,
                   const Scaleform::Render::Matrix4F* cxmul, const Scaleform::Render::VertexFormat* format,
                   Scaleform::Render::D3D9::ShaderInterface* psi, unsigned flags);
bool FUN_142734790(Scaleform::Render::D3D9::ShaderManager* sm, Scaleform::Render::Texture** tex,
                   const Scaleform::Render::Matrix2F* texgen, Scaleform::Render::Size<int> texsize,
                   const Scaleform::Render::Matrix2F& mvp, unsigned op, Scaleform::UInt32 threshold,
                   Scaleform::UInt32 color, Scaleform::UInt32 mask, bool copySource,
                   const Scaleform::Render::VertexFormat* format, Scaleform::Render::D3D9::ShaderInterface* psi,
                   unsigned flags);
// StaticShaderManager::SetFilterFill (sfr_d3d9_01e, below)
void FUN_142734e10(Scaleform::Render::D3D9::ShaderManager* sm, const Scaleform::Render::Matrix2F& mvp,
                   const Scaleform::Render::Cxform& cx, const Scaleform::Render::Filter* filter,
                   Scaleform::Ptr<Scaleform::Render::RenderTarget>* targets, unsigned* shaders, unsigned pass,
                   unsigned passCount, const Scaleform::Render::VertexFormat* format,
                   Scaleform::Render::D3D9::ShaderInterface* psi);

namespace Scaleform { namespace Render {

// the data's buffer and depth stencil reference go with it
RenderTargetData::~RenderTargetData()
{
}

namespace D3D9 {

// every uniform of this build is builtin-free: user data never feeds them
const UByte Uniform::UniformFlags[Uniform::SU_Count] = { 0 };

// the mesh cache sizes of the PC build
static inline MeshCacheParams pcMeshCacheParams()
{
    MeshCacheParams p;
    p.MemReserve                   = 0x300000;
    p.MemLimit                     = 0x1000000;
    p.MemGranularity               = 0x300000;
    p.LRUTailSize                  = 0xa00000;
    p.StagingBufferSize            = 0x200000;
    p.VBLockEvictSizeLimit         = 0x40000;
    p.MaxBatchInstances            = 24;
    p.InstancingThreshold          = 5;
    p.NoBatchVerticesSizeThreshold = 0x2000;
    p.MaxVerticesSizeInBatch       = 0x4000;
    p.MaxIndicesInBatch            = 0x1800;
    return p;
}

// MS2-FUNCTIONAL: written from the decompile; the mesh cache params are built the same way, store order may differ
// @0x14272dc10
HAL::HAL(ThreadCommandQueue* commandQueue)
    : Render::HAL(commandQueue),
      pDevice(0),
      DeviceFlags(0),
      Cache(Memory::GetGlobalHeap(), pcMeshCacheParams()),
      SManager(&Profiler),
      ShaderData(this),
      PrevBatchType(PrimitiveBatch::DP_None),
      StencilChecked(false),
      StencilAvailable(false),
      MultiBitStencil(false),
      DepthBufferAvailable(false),
      StencilOpInc(D3DSTENCILOP_REPLACE)
{
    for (unsigned i = 0; i < PrimitiveBatch::DP_DrawableCount; i++)
    {
        MappedXY16iAlphaTexture[i] = 0;
        MappedXY16iAlphaSolid[i]   = 0;
    }
}

// MS2-FUNCTIONAL: written from the decompile
// @0x14272e650
HAL::~HAL()
{
    ShutdownHAL();
}

// @0x14272f640
void RenderEvent::Begin(String eventName)
{
    wchar_t wideName[256];
    size_t  converted;
    mbstowcs_s(&converted, wideName, 256, eventName.ToCStr(), 256);
    D3DPERF_BeginEvent(D3DCOLOR_ARGB(0xff, 0, 0, 0), wideName);
}

// @0x142731c70
void RenderEvent::End()
{
    D3DPERF_EndEvent();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142731df0
Render::RenderEvent& HAL::GetEvent(EventType type)
{
    static D3D9::RenderEvent events[Event_Count];
    return events[type];
}

// @0x142732040
Render::MeshCache& HAL::GetMeshCache()
{
    return Cache;
}

// @0x142732120
Render::TextureManager* HAL::GetTextureManager()
{
    return pTextureManager.GetPtr();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427327c0
void HAL::MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat, const VertexFormat** single,
                          const VertexFormat** batch, const VertexFormat** instanced, unsigned)
{
    unsigned flags = MVF_Align | MVF_AlignVertexAttrs | MVF_ReverseColor;
    if (SManager.HasInstancingSupport())
        flags |= MVF_HasInstancing;
    SManager.MapVertexFormat(fill, sourceFormat, single, batch, instanced, flags);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142736d70
bool HAL::checkMaskBufferCaps()
{
    if (!StencilChecked)
    {
        IDirect3DSurface9* depthStencil = 0;
        pDevice->GetDepthStencilSurface(&depthStencil);
        if (depthStencil)
        {
            D3DSURFACE_DESC desc;
            depthStencil->GetDesc(&desc);
            switch (desc.Format)
            {
            case D3DFMT_D15S1:
                StencilAvailable = true;
                break;
            case D3DFMT_D24S8:
            case D3DFMT_D24X4S4:
            case D3DFMT_D24FS8:
                MultiBitStencil  = true;
                StencilAvailable = true;
                break;
            default:
                break;
            }
            depthStencil->Release();
            DepthBufferAvailable = true;
        }
        else
            StencilAvailable = false;
        StencilChecked = true;
    }
    return StencilAvailable || DepthBufferAvailable;
}

// a full-viewport quad (two triangles) from the mask erase vertices
// MS2-FUNCTIONAL: cl inlines setLinearStreamSource here, the exe calls it
// @0x142737f10
void HAL::drawScreenQuad()
{
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, sizeof(VertexXY16iAlpha));
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427387f0
bool HAL::initializeShaders(bool)
{
    for (unsigned i = 0; i < VertexShaderDesc::VSI_Count; i++)
    {
        if (VertexShaderDesc::Descs[i] && !StaticVShaders[i].Init(this, VertexShaderDesc::Descs[i]))
            return false;
    }
    for (unsigned i = 0; i < FragShaderDesc::FSI_Count; i++)
    {
        const FragShaderDesc* desc = FragShaderDesc::Descs[i];
        if (!desc)
            continue;
        // the dynamic looping shaders only where the device runs them
        if ((desc->Flags & 4) && !SManager.HasDynamicLoopingSupport())
            continue;
        if (!StaticFShaders[i].Init(this, desc))
            return false;
    }
    return true;
}

// @0x1427388b0
void HAL::setInstancedStreamSource(unsigned instanceCount)
{
    if (PrevBatchType != PrimitiveBatch::DP_Instanced)
    {
        pDevice->SetStreamSource(1, Cache.pInstancingVertexBuffer.GetPtr(), 0, 4);
        pDevice->SetStreamSourceFreq(1, D3DSTREAMSOURCE_INSTANCEDATA | 1);
        PrevBatchType = PrimitiveBatch::DP_Instanced;
    }
    pDevice->SetStreamSourceFreq(0, D3DSTREAMSOURCE_INDEXEDDATA | instanceCount);
}

// @0x142738940
void HAL::setLinearStreamSource(PrimitiveBatch::BatchType type)
{
    if (PrevBatchType >= PrimitiveBatch::DP_Instanced)
    {
        pDevice->SetStreamSource(1, 0, 0, 0);
        pDevice->SetStreamSourceFreq(0, 1);
        pDevice->SetStreamSourceFreq(1, 1);
    }
    PrevBatchType = type;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142738de0
bool HAL::shouldRenderFilters(const FilterPrimitive* prim) const
{
    if (SManager.HasDynamicLoopingSupport())
        return true;
    // without loops in the shaders only the color matrix filters draw
    const FilterSet* filters = prim->GetFilters();
    for (unsigned i = 0; i < filters->GetFilterCount(); i++)
    {
        if (filters->GetFilter(i)->GetFilterType() == Filter_ColorMatrix)
            return true;
    }
    return false;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x14272f910
RenderTarget* HAL::CreateRenderTarget(IDirect3DSurface9* colorSurface, IDirect3DSurface9* depthSurface)
{
    D3DSURFACE_DESC desc;
    ImageSize       dsSize(0), bufferSize(0);
    if (SUCCEEDED(colorSurface->GetDesc(&desc)))
        bufferSize.SetSize(desc.Width, desc.Height);

    Ptr<RenderTarget>       target = pRenderBufferManager->CreateRenderTarget(bufferSize, RBuffer_User, Image_R8G8B8A8, 0);
    Ptr<DepthStencilBuffer> dsb;
    if (depthSurface && SUCCEEDED(depthSurface->GetDesc(&desc)))
    {
        dsSize.SetSize(desc.Width, desc.Height);
        dsb = *SF_HEAP_AUTO_NEW(this) DepthStencilBuffer(0, dsSize);
    }
    RenderTargetData::UpdateData(target, colorSurface, dsb, depthSurface);
    return target;
}

// the depth stencil buffer a render target is drawn with, and its D3D surface (0 when it could not be made)
static DepthStencilBuffer* createTargetDepthStencil(RenderBufferManager* manager, const ImageSize& size,
                                                    IDirect3DSurface9** pdss)
{
    DepthStencilBuffer* pdsb = manager->CreateDepthStencilBuffer(size);
    if (pdsb)
    {
        DepthStencilSurface* surface = (DepthStencilSurface*)pdsb->GetSurface();
        *pdss = surface->pDepthStencilSurface;
    }
    return pdsb;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x14272fab0
RenderTarget* HAL::CreateRenderTarget(Render::Texture* texture, bool needsStencil)
{
    D3D9::Texture* pt = (D3D9::Texture*)texture;
    if (!pt || pt->TextureCount != 1)
        return 0;

    ImageSize     size = pt->ImgSize;
    RenderTarget* prt  = pRenderBufferManager->CreateRenderTarget(size, RBuffer_Texture, pt->GetFormat(), texture);
    if (!prt)
        return 0;

    IDirect3DSurface9* surf = 0;
    pt->pTextures[0].pTexture->GetSurfaceLevel(0, &surf);
    DepthStencilBuffer* pdsb = 0;
    IDirect3DSurface9*  pdss = 0;
    if (needsStencil)
        pdsb = createTargetDepthStencil(pRenderBufferManager, size, &pdss);
    RenderTargetData::UpdateData(prt, surf, pdsb, pdss);
    if (surf)
        surf->Release();
    if (pdsb)
        pdsb->Release();
    return prt;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x14272fbe0
RenderTarget* HAL::CreateTempRenderTarget(const ImageSize& size, bool needsStencil)
{
    RenderTarget* prt = pRenderBufferManager->CreateTempRenderTarget(size);
    if (!prt)
        return 0;
    RenderTargetData* data = (RenderTargetData*)prt->GetRenderTargetData();
    if (data && (!needsStencil || data->pDSSurface))
        return prt;

    D3D9::Texture*     pt   = (D3D9::Texture*)prt->GetTexture();
    IDirect3DSurface9* surf = 0;
    pt->pTextures[0].pTexture->GetSurfaceLevel(0, &surf);
    DepthStencilBuffer* pdsb = 0;
    IDirect3DSurface9*  pdss = 0;
    if (needsStencil)
        pdsb = createTargetDepthStencil(pRenderBufferManager, size, &pdss);
    RenderTargetData::UpdateData(prt, surf, pdsb, pdss);
    if (pdsb)
        pdsb->Release();
    if (surf)
        surf->Release();
    return prt;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142731c80
void HAL::EndMaskSubmit()
{
    ScopedRenderEvent evt(GetEvent(Event_Mask), 0, false);
    if ((HALState & (HS_InDisplay | HS_DrawingMask)) != (HS_InDisplay | HS_DrawingMask))
    {
        FUN_1426c1790(this, HS_InDisplay | HS_DrawingMask, __FUNCTION__);
        return;
    }
    HALState &= ~HS_DrawingMask;
    pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xf);
    if (StencilAvailable)
    {
        // draw where the stencil reached the mask depth
        pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL);
        pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
        pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop);
        pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);
    }
    else if (DepthBufferAvailable)
    {
        pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
        pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
        pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_EQUAL);
    }
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142732ba0
void HAL::PopRenderTarget()
{
    ScopedRenderEvent evt(GetEvent(Event_RenderTarget), __FUNCTION__, false);

    RenderTargetEntry& entry = RenderTargetStack.Back();
    RenderTarget*      prt   = entry.pRenderTarget;
    prt->SetInUse(false);
    if (prt->GetType() == RBuffer_Temporary)
    {
        // temporary targets give their depth stencil back
        RenderTargetData* data = (RenderTargetData*)prt->GetRenderTargetData();
        if (data->pDSSurface)
        {
            data->pDSSurface->Release();
            data->pDSSurface = 0;
        }
        data->pDepthStencilBuffer = 0;
    }

    Matrices = entry.OldMatrixState;
    ViewRect = entry.OldViewRect;
    VP       = entry.OldViewport;
    Matrices.ViewRectOriginal.Offset(entry.OldViewport.Left, entry.OldViewport.Top);
    Matrices.UVPOChanged = true;

    RenderTargetStack.Pop();
    RenderTargetData* phd = 0;
    if (RenderTargetStack.GetSize() > 0)
        phd = (RenderTargetData*)RenderTargetStack.Back().pRenderTarget->GetRenderTargetData();
    if (RenderTargetStack.GetSize() == 1)
        HALState &= ~HS_InRenderTarget;

    pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pDevice->SetRenderTarget(0, phd->pRenderSurface);
    pDevice->SetDepthStencilSurface(phd->pDSSurface);

    ++AccumulatedStats.RTChanges;
    HALState |= HS_ViewValid;
    updateViewport();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142736970
void RenderTargetData::UpdateData(RenderBuffer* buffer, IDirect3DSurface9* prt, DepthStencilBuffer* pdsb,
                                  IDirect3DSurface9* pdss)
{
    if (!buffer)
        return;
    RenderTargetData* data = (RenderTargetData*)buffer->GetRenderTargetData();
    if (!data)
    {
        buffer->SetRenderTargetData(new RenderTargetData(buffer, prt, pdsb, pdss));
        return;
    }
    if (prt)
        prt->AddRef();
    if (pdss)
        pdss->AddRef();
    if (data->pRenderSurface)
        data->pRenderSurface->Release();
    if (data->pDSSurface)
        data->pDSSurface->Release();
    data->pDepthStencilBuffer = pdsb;
    data->pDSSurface          = pdss;
    data->pRenderSurface      = prt;
    data->CacheID             = 0;
}

// MS2-FUNCTIONAL: the base beginMaskDisplay is inlined in the exe (no separate body size); same effect
// @0x142736d60
void HAL::beginMaskDisplay()
{
    Render::HAL::beginMaskDisplay();
    StencilChecked = false;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142733b90
void HAL::PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags)
{
    ScopedRenderEvent evt(GetEvent(Event_RenderTarget), __FUNCTION__);
    HALState |= HS_InRenderTarget;

    RenderTargetEntry entry = { prt, Matrices, ViewRect, VP };
    Matrices.SetUserMatrix(Matrix2F::Identity);

    if (prt)
    {
        RenderTargetData* phd = (RenderTargetData*)prt->GetRenderTargetData();
        pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        pDevice->SetRenderTarget(0, phd->pRenderSurface);
        pDevice->SetDepthStencilSurface(phd->pDSSurface);
        ++AccumulatedStats.RTChanges;

        // bit 0: keep the target's contents
        if (!(flags & 1))
            pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);

        // the view is the target's rectangle; the frame rectangle maps onto it
        VP         = Viewport(prt->GetBufferSize(), prt->GetRect());
        ViewRect.x1 = (int)frameRect.x1;
        ViewRect.y1 = (int)frameRect.y1;
        ViewRect.x2 = (int)frameRect.x2;
        ViewRect.y2 = (int)frameRect.y2;
        Matrices.ViewRectOriginal.Offset(-entry.OldViewport.Left, -entry.OldViewport.Top);
        HALState |= HS_ViewValid;
        Matrices.UVPOChanged = true;
        updateViewport();
    }
    RenderTargetStack.PushBack(entry);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142736240
bool HAL::SetRenderTarget(RenderTarget* target, bool setState)
{
    // the bottom target cannot change while a display draws into it; a scene draws what it queued first
    if (HALState & HS_InDisplay)
        return false;
    if (HALState & HS_InScene)
        Flush();

    RenderTargetEntry  entry;
    RenderTargetData*  phd     = (RenderTargetData*)target->GetRenderTargetData();
    IDirect3DSurface9* surface = phd->pRenderSurface;
    D3DSURFACE_DESC    desc;
    if (FAILED(surface->GetDesc(&desc)))
        return false;
    if (setState)
    {
        pDevice->SetRenderTarget(0, surface);
        if (phd->pDSSurface)
            pDevice->SetDepthStencilSurface(phd->pDSSurface);
        ++AccumulatedStats.RTChanges;
    }

    // the target replaces the bottom of the stack
    entry.pRenderTarget = target;
    if (RenderTargetStack.GetSize() > 0)
        RenderTargetStack[0] = entry;
    else
        RenderTargetStack.PushBack(entry);
    return true;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427372c0
bool HAL::createDefaultRenderBuffer()
{
    ImageSize screenSize;
    if (GetDefaultRenderTarget())
        screenSize = GetDefaultRenderTarget()->GetSize();
    else
    {
        // wrap the device's current color / depth stencil surfaces in the default target
        IDirect3DSurface9* colorSurface = 0;
        D3DSURFACE_DESC    desc;
        if (FAILED(pDevice->GetRenderTarget(0, &colorSurface)) || FAILED(colorSurface->GetDesc(&desc)))
            return false;
        screenSize.SetSize(desc.Width, desc.Height);

        IDirect3DSurface9*      depthSurface = 0;
        Ptr<DepthStencilBuffer> pdsb;
        if (SUCCEEDED(pDevice->GetDepthStencilSurface(&depthSurface)) && SUCCEEDED(depthSurface->GetDesc(&desc)))
            pdsb = *SF_HEAP_AUTO_NEW(this) DepthStencilBuffer(0, ImageSize(desc.Width, desc.Height));
        Ptr<RenderTarget> ptarget = *SF_HEAP_AUTO_NEW(this) RenderTarget(0, RBuffer_Default, screenSize);
        RenderTargetData::UpdateData(ptarget, colorSurface, pdsb, depthSurface);
        if (depthSurface)
            depthSurface->Release();
        colorSurface->Release();
        if (!SetRenderTarget(ptarget, true))
            return false;
    }
    pRenderBufferManager->Initialize(pTextureManager, Image_R8G8B8A8, screenSize);
    return true;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427329c0
void HAL::PopMask()
{
    ScopedRenderEvent evt(GetEvent(Event_PopMask), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        FUN_1426c1790(this, HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!StencilAvailable && !DepthBufferAvailable)
        return;

    // a clipped mask gives back the view it narrowed
    MaskStackTop--;
    MaskStackEntry& e = MaskStack[MaskStackTop];
    if (e.pPrimitive->IsClipped())
    {
        ViewRect = e.OldViewRect;
        if (MaskStack[MaskStackTop].OldViewportValid)
            HALState |= HS_ViewValid;
        else
            HALState &= ~HS_ViewValid;
        updateViewport();
    }

    if (StencilAvailable)
    {
        if (MaskStackTop == 0)
            pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
        else
        {
            pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop);
            pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
        }
    }
    else if (DepthBufferAvailable)
    {
        pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
        pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
    }
}


// MS2-FUNCTIONAL: written from the decompile
// @0x14272f830
PrimitiveFill* HAL::CreatePrimitiveFill(const PrimitiveFillData& data)
{
    return SF_HEAP_NEW(pHeap) PrimitiveFill(data);
}

// the shader interface's per-primitive reset: no uniforms set, no textures bound
struct ShaderInterfaceAccess : public ShaderInterface
{
    static void BeginPrimitive(ShaderInterface* psi)
    {
        ShaderInterfaceAccess* s = (ShaderInterfaceAccess*)psi;
        memset(s->UniformSet, 0, sizeof(s->UniformSet));
        memset(s->Textures, 0, sizeof(s->Textures));
    }
};

// MS2-FUNCTIONAL: written from the decompile
// @0x1427307e0
void HAL::DrawProcessedPrimitive(Primitive* prim, PrimitiveBatch* start, PrimitiveBatch* end)
{
    ScopedRenderEvent evt(GetEvent(Event_DrawPrimitive), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        FUN_1426c1790(this, HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!prim->GetMeshCount())
        return;
    if (!start)
        start = prim->Batches.GetFirst();
    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);

    for (PrimitiveBatch* batch = start; batch != end; batch = batch->pNext)
    {
        D3D9::MeshCacheItem* item  = (D3D9::MeshCacheItem*)batch->MeshNode.pMeshItem;
        unsigned             count = batch->GetMeshCount();
        if (!item)
            continue;

        // bit 3: the first mesh is 3D
        unsigned fillFlags = DeviceFlags;
        if (count)
            fillFlags |= (prim->Meshes[0].M.GetFormatBits() >> 1) & 8;
        unsigned          meshIndex = *(const unsigned*)((const UByte*)batch + 0x4c);   // PrimitiveBatch::MeshIndex
        const ShaderPair* pso       = FUN_1427359d0(&SManager, prim->pFill, &fillFlags, batch->Type, batch->pFormat,
                                                    count, &Matrices, &prim->Meshes[meshIndex], &ShaderData);

        if ((HALState & HS_ViewValid) && pso->pVS && pso->pFS && pso->pVS->pProg && pso->pFS->pProg &&
            pso->pVFormat)
        {
            if (batch->Type == PrimitiveBatch::DP_Instanced)
            {
                AccumulatedStats.Meshes += count;
                AccumulatedStats.Triangles += item->IndexCount / 3 * count;
                setInstancedStreamSource(batch->GetMeshCount());
            }
            else
            {
                AccumulatedStats.Meshes += item->MeshCount;
                AccumulatedStats.Triangles += item->IndexCount / 3;
                setLinearStreamSource(batch->Type);
            }
            pDevice->SetIndices(((IndexBuffer*)item->pIndexBuffer)->pBuffer);
            pDevice->SetStreamSource(0, ((VertexBuffer*)item->pVertexBuffer)->pBuffer, (UINT)item->VBAllocOffset,
                                     batch->pFormat->Size);
            pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, (UINT)(item->VBAllocSize / batch->pFormat->Size),
                                          (UINT)(item->IBAllocOffset >> 1), item->IndexCount / 3);
            AccumulatedStats.Primitives++;
        }
        item->GPUFence = Cache.GetRenderSync()->InsertFence();
        item->MoveToCacheListFront(MCL_ThisFrame);
    }
}

// the blend states of each BlendMode: color only, and color with separate alpha (alpha composite targets)
struct BlendModeDesc
{
    D3DBLENDOP Op;
    D3DBLEND   SrcArg, DestArg;
};
struct BlendModeDescAlpha
{
    D3DBLENDOP Op;
    D3DBLEND   SrcArg, DestArg, SrcAlphaArg, DestAlphaArg;
};

#define SFR_BM(op, s, d)          { (D3DBLENDOP)op, (D3DBLEND)s, (D3DBLEND)d }
#define SFR_BMA(op, s, d, sa, da) { (D3DBLENDOP)op, (D3DBLEND)s, (D3DBLEND)d, (D3DBLEND)sa, (D3DBLEND)da }
static const BlendModeDesc BlendModeTable[Blend_Count] = {
    SFR_BM(1, 5, 6), SFR_BM(1, 5, 6), SFR_BM(1, 5, 6), SFR_BM(1, 9, 1), SFR_BM(1, 5, 6), SFR_BM(5, 5, 2),
    SFR_BM(4, 5, 2), SFR_BM(1, 5, 6), SFR_BM(1, 5, 2), SFR_BM(3, 5, 2), SFR_BM(1, 5, 6), SFR_BM(1, 1, 2),
    SFR_BM(1, 1, 2), SFR_BM(1, 5, 6), SFR_BM(1, 5, 6), SFR_BM(1, 5, 1), SFR_BM(1, 5, 1), SFR_BM(1, 2, 2),
};
static const BlendModeDescAlpha BlendModeTableAlpha[Blend_Count] = {
    SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 9, 1, 9, 1),
    SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(5, 5, 2, 5, 2), SFR_BMA(4, 5, 2, 5, 2), SFR_BMA(1, 5, 6, 2, 6),
    SFR_BMA(1, 5, 2, 1, 2), SFR_BMA(3, 5, 2, 1, 2), SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 1, 1, 2, 2),
    SFR_BMA(1, 1, 1, 2, 2), SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 5, 6, 2, 6), SFR_BMA(1, 2, 1, 1, 2),
    SFR_BMA(1, 2, 1, 2, 1), SFR_BMA(1, 2, 2, 2, 2),
};
#undef SFR_BM
#undef SFR_BMA

// MS2-FUNCTIONAL: written from the decompile
// @0x142736ac0
void HAL::applyBlendMode(BlendMode mode, bool sourceAc, bool forceAc)
{
    ScopedRenderEvent evt(GetEvent(Event_ApplyBlend), __FUNCTION__);
    if (!pDevice)
        return;
    unsigned m = ((unsigned)mode < Blend_Count) ? (unsigned)mode : 0;

    // device flag bit 1: multiply / darken draw through the multiply shaders
    if (m == Blend_Multiply || m == Blend_Darken)
        DeviceFlags |= 1;
    else
        DeviceFlags &= ~1;

    // (the exe reads the source argument from the alpha table in both branches)
    D3DBLEND src = (sourceAc && BlendModeTableAlpha[m].SrcArg == D3DBLEND_SRCALPHA) ? D3DBLEND_ONE
                                                                                     : BlendModeTableAlpha[m].SrcArg;
    if (!(VP.Flags & Viewport::View_AlphaComposite) && !forceAc)
    {
        pDevice->SetRenderState(D3DRS_BLENDOP, BlendModeTable[m].Op);
        pDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
        pDevice->SetRenderState(D3DRS_SRCBLEND, src);
        pDevice->SetRenderState(D3DRS_DESTBLEND, BlendModeTable[m].DestArg);
    }
    else
    {
        pDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
        pDevice->SetRenderState(D3DRS_BLENDOP, BlendModeTableAlpha[m].Op);
        pDevice->SetRenderState(D3DRS_BLENDOPALPHA, BlendModeTableAlpha[m].Op);
        pDevice->SetRenderState(D3DRS_SRCBLEND, src);
        pDevice->SetRenderState(D3DRS_DESTBLEND, BlendModeTableAlpha[m].DestArg);
        pDevice->SetRenderState(D3DRS_SRCBLENDALPHA, BlendModeTableAlpha[m].SrcAlphaArg);
        pDevice->SetRenderState(D3DRS_DESTBLENDALPHA, BlendModeTableAlpha[m].DestAlphaArg);
    }
}
// the clip-space matrix of a drawable's full-target quad: (0,0)-(1,1) onto the target, y down
static Matrix2F drawableQuadMVP()
{
    Matrix2F m;
    m.M[0][0] = 2.0f; m.M[0][1] = 0.0f;  m.M[0][2] = 0.0f; m.M[0][3] = -1.0f;
    m.M[1][0] = 0.0f; m.M[1][1] = -2.0f; m.M[1][2] = 0.0f; m.M[1][3] = 1.0f;
    return m;
}

// the size of the render target on top of the stack, which a drawable draws into
static Size<int> drawableTargetSize(const Render::HAL* hal)
{
    const Rect<int>& r = hal->RenderTargetStack.Back().pRenderTarget->GetRect();
    return Size<int>(r.x2 - r.x1, r.y2 - r.y1);
}

static bool setDrawableShader(ShaderInterface* psi, unsigned shader, const VertexFormat* format)
{
    return psi->SetStaticShader((VertexShaderDesc::ShaderType)shader, (FragShaderDesc::ShaderType)shader, format);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142731150
void HAL::DrawableCxform(Render::Texture** tex, const Matrix2F* texgen, const Cxform* cx)
{
    ScopedRenderEvent evt(GetEvent(Event_DICxform), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    if (setDrawableShader(&ShaderData, 0x11, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
        ShaderData.SetCxform(ShaderData.GetCurrentShaders(), *cx);
        FUN_142731310(&SManager, 1, tex, texgen, size, drawableQuadMVP(), &ShaderData, 1);
    }
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142730b60
void HAL::DrawableCompare(Render::Texture** tex, const Matrix2F* texgen)
{
    ScopedRenderEvent evt(GetEvent(Event_DICompare), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    if (setDrawableShader(&ShaderData, 0x1a651, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
        FUN_142731310(&SManager, 2, tex, texgen, size, drawableQuadMVP(), &ShaderData, 1);
    }
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427315c0
void HAL::DrawableMerge(Render::Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul)
{
    ScopedRenderEvent evt(GetEvent(Event_DIMerge), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    FUN_142734410(&SManager, tex, texgen, size, cxmul, MappedXY16iAlphaTexture[0], &ShaderData, 1);
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142730d10
void HAL::DrawableCopyPixels(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, bool mergeAlpha,
                             bool destAlpha)
{
    ScopedRenderEvent evt(GetEvent(Event_DICopyPixels), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    // a third texture is the alpha source
    unsigned shader = tex[2] ? 0x12a4d : 0x1264d;
    if (mergeAlpha)
        shader += 0x1000;
    if (!destAlpha)
        shader += 0x4000;
    shader += 0x80;
    if (setDrawableShader(&ShaderData, shader, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
        FUN_142731310(&SManager, tex[2] ? 3 : 2, tex, texgen, size, mvp, &ShaderData, 1);
    }
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427316f0
void HAL::DrawablePaletteMap(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, unsigned channelMask,
                             const UInt32* values)
{
    ScopedRenderEvent evt(GetEvent(Event_DIPaletteMap), __FUNCTION__);

    // the palette: a 256x4 texture, one row per channel; a channel not mapped keeps its identity ramp
    Ptr<Render::Texture> ptex =
        *pTextureManager->CreateTexture(Image_B8G8R8A8, 1, ImageSize(256, 4), ImageUse_Map_Mask, 0, 0);
    ImageData data;
    if (ptex->Map(&data, 0, 1))
    {
        for (unsigned c = 0; c < 4; c++)
        {
            UInt32* row = (UInt32*)data.GetScanline(c);
            if (channelMask & (1u << c))
                memcpy(row, values + c * 256, 256 * sizeof(UInt32));
            else
                for (unsigned i = 0; i < 256; i++)
                    row[i] = i << (c * 8);
        }
        if (ptex->Unmap())
        {
            applyBlendMode(Blend_OverwriteAll, true, true);
            Size<int> size = drawableTargetSize(this);
            if (setDrawableShader(&ShaderData, 0x1a653, MappedXY16iAlphaTexture[0]))
            {
                ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
                ShaderData.SetTexture(ShaderData.GetCurrentShaders(), Uniform::SU_paletteMap, ptex,
                                      ImageFillMode(Wrap_Clamp, Sample_Point), 0);
                FUN_142731310(&SManager, 1, tex, texgen, size, mvp, &ShaderData, 1);
            }
            drawScreenQuad();
        }
    }
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142731b00
void HAL::DrawableThreshold(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, unsigned op,
                            UInt32 threshold, UInt32 color, UInt32 mask, bool copySource)
{
    ScopedRenderEvent evt(GetEvent(Event_DIThreshold), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    FUN_142734790(&SManager, tex, texgen, size, mvp, op, threshold, color, mask, copySource,
                  MappedXY16iAlphaTexture[0], &ShaderData, 1);
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142730ec0
void HAL::DrawableCopyback(Render::Texture* tex, const Matrix2F& mvpIn, const Matrix2F& texgen)
{
    ScopedRenderEvent evt(GetEvent(Event_DICopyback), __FUNCTION__);
    setDrawableShader(&ShaderData, 1, MappedXY16iAlphaTexture[0]);
    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);

    // shifted a pixel of the clip space: D3D9 samples pixel centers
    Size<int> size = drawableTargetSize(this);
    Matrix2F  mvp(mvpIn);
    mvp.M[0][3] -= 1.0f / (float)(unsigned)size.Width;
    mvp.M[1][3] += 1.0f / (float)(unsigned)size.Height;
    const ShaderPair& cur = ShaderData.GetCurrentShaders();
    ShaderData.SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8);
    ShaderData.SetUniform(cur, Uniform::SU_texgen, &texgen.M[0][0], 8);
    ShaderData.SetTexture(cur, Uniform::SU_tex, tex, ImageFillMode());
    ShaderData.Finish(1);
    drawScreenQuad();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142737f70
void HAL::drawUncachedFilter(const FilterStackEntry& e)
{
    const FilterSet* filters     = e.pPrimitive->GetFilters();
    unsigned         filterCount = filters->GetFilterCount();
    const Filter*    filter      = 0;
    unsigned         pass = 0, passes = 0;
    ImageSize        size = e.pRenderTarget->GetSize();

    // 0: the source of a pass, 1: its destination, 2: the unfiltered source the last pass of a shadow reads
    Ptr<RenderTarget> temporaries[3];
    temporaries[0] = e.pRenderTarget;
    unsigned shaders[8];

    // one full-target quad from the cache's vertex buffer per pass
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);
    pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xf);
    applyBlendMode(Blend_Overlay, true);

    for (unsigned i = 0; i < filterCount; i++)
    {
        filter = filters->GetFilter(i);
        FilterType type = filter->GetFilterType();
        if (type <= Filter_Blur_End)
        {
            const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();
            float area   = params.BlurX * params.BlurY;
            bool  box    = area < 12800.0f;
            passes = box ? params.Passes : params.Passes * 2;
            for (unsigned j = 0; j + 1 < passes; j++)
                shaders[j] = box ? 0xa449 : 0xa249;
            unsigned last;
            unsigned mode = params.Mode;
            if ((mode & 7) - 1 < 3)
            {
                if (mode & 0x20)
                    last = 0xae4b;
                else
                    last = ((mode & 0x50) != 0x40) ? 0xa64b : 0xb64b;
                if (DeviceFlags & 1)
                    last += 1;
                if (mode & 0x10)
                    last += 0x100;
                if (mode & 0x80)
                    last += 0x400;
            }
            else
                last = (box ? 0xa449 : 0xa249) + (DeviceFlags & 1);
            shaders[passes - 1] = last;
        }
        else
        {
            passes     = 1;
            shaders[0] = 0xa207 + (DeviceFlags & 1);
        }

        // shadows and glows not hiding the object draw it over their result: keep the source
        bool requireSource = false;
        if ((unsigned)type - 1 < 5 && !(((const BlurFilterImpl*)filter)->GetParams().Mode & 0x40))
        {
            requireSource  = true;
            temporaries[2] = temporaries[0];
        }

        for (pass = 0; pass < passes; pass++)
        {
            // the last pass of the last filter draws to the target below
            if (pass == passes - 1 && i == filterCount - 1)
                break;

            if (!temporaries[1])
                temporaries[1] = *CreateTempRenderTarget(size, false);

            RenderTargetData* phd = (RenderTargetData*)temporaries[1]->GetRenderTargetData();
            pDevice->SetRenderTarget(0, phd->pRenderSurface);
            pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
            ++AccumulatedStats.RTChanges;

            VP       = Viewport(temporaries[1]->GetBufferSize(), temporaries[1]->GetRect());
            ViewRect = temporaries[1]->GetRect();
            HALState |= HS_ViewValid;
            updateViewport();

            // the whole target, half a pixel over for the pixel centers
            Matrix2F mvp;
            mvp.M[0][0] = 2.0f;
            mvp.M[0][1] = 0.0f;
            mvp.M[0][2] = 0.0f;
            mvp.M[0][3] = -1.0f - 1.0f / (float)size.Width;
            mvp.M[1][0] = 0.0f;
            mvp.M[1][1] = -2.0f;
            mvp.M[1][2] = 0.0f;
            mvp.M[1][3] = 1.0f / (float)size.Height + 1.0f;
            FUN_142734e10(&SManager, mvp, Cxform::Identity, filter, temporaries, shaders, pass, passes,
                          MappedXY16iAlphaTexture[0], &ShaderData);
            pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

            pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
            pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);

            // the kept source must not be drawn over: the first pass's result goes to a new target
            if (requireSource && pass == 0)
                temporaries[0] = *CreateTempRenderTarget(size, false);
            Alg::Swap(temporaries[0], temporaries[1]);
        }
        AccumulatedStats.Primitives += passes;
        AccumulatedStats.Meshes += passes;
    }

    // cache the step before the final pass
    if (temporaries[0])
    {
        RenderTarget* cacheResults[2] = { temporaries[0], temporaries[2] };
        e.pPrimitive->SetCacheResults(FilterPrimitive::Cache_PreTarget, cacheResults, 2);
        ((RenderTargetData*)cacheResults[0]->GetRenderTargetData())->CacheID = (UPInt)e.pPrimitive.GetPtr();
        if (cacheResults[1])
            ((RenderTargetData*)cacheResults[1]->GetRenderTargetData())->CacheID = (UPInt)e.pPrimitive.GetPtr();
    }

    PopRenderTarget();
    if (MaskStackTop)
    {
        if (StencilAvailable)
            pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
        else if (DepthBufferAvailable)
            pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
    }

    // the last pass draws the filtered area into the target below
    const MatrixPoolImpl::HMatrix& area = e.pPrimitive->GetFilterAreaMatrix();
    Matrix2F       mvp = Matrices.UserView * area.GetMatrix2D();
    const Cxform*  cx  = &Cxform::Identity;
    if (area.pHandle->HasElement(MatrixPoolImpl::HMatrixConstants::Element_Cxform))
        cx = area.pHandle->GetCxformPtr();
    FUN_142734e10(&SManager, mvp, *cx, filter, temporaries, shaders, pass, passes, MappedXY16iAlphaTexture[0],
                  &ShaderData);

    BlendMode blend = BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal;
    applyBlendMode(blend, true, true);
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
    blend = BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal;
    applyBlendMode(blend, false, (HALState & HS_InRenderTarget) != 0);
    if (HALState & HS_DrawingMask)
        pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0);

    for (unsigned t = 0; t < 3; t++)
    {
        pTextureManager->SetSamplerState(t, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        if (temporaries[t])
            temporaries[t]->SetInUse(false);
    }
    AccumulatedStats.Filters += filters->GetFilterCount();
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142737550
void HAL::drawCachedFilter(FilterPrimitive* primitive)
{
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);

    if (primitive->GetCacheState() == FilterPrimitive::Cache_PreTarget)
    {
        // one pass short of the result: draw the last pass into a new target, cache that, then draw it
        const FilterSet* filters = primitive->GetFilters();
        const Filter*    filter  = filters->GetFilter(filters->GetFilterCount() - 1);
        unsigned         shaders[8];
        unsigned         passes = SManager.GetFilterPasses(filter, DeviceFlags, shaders);

        Ptr<RenderTarget> temporaries[3];
        RenderTarget*     cacheResults[2];
        primitive->GetCacheResults(cacheResults, 2);
        temporaries[0] = cacheResults[0];
        ImageSize size = temporaries[0]->GetSize();
        temporaries[1] = *CreateTempRenderTarget(size, false);
        temporaries[2] = cacheResults[1];
        PushRenderTarget(RectF(0, 0, (float)size.Width, (float)size.Height), temporaries[1]);

        Matrix2F mvp;
        mvp.M[0][0] = 2.0f;
        mvp.M[0][1] = 0.0f;
        mvp.M[0][2] = 0.0f;
        mvp.M[0][3] = -1.0f - 1.0f / (float)size.Width;
        mvp.M[1][0] = 0.0f;
        mvp.M[1][1] = -2.0f;
        mvp.M[1][2] = 0.0f;
        mvp.M[1][3] = 1.0f / (float)size.Height + 1.0f;
        const MatrixPoolImpl::HMatrix& area = primitive->GetFilterAreaMatrix();
        const Cxform* cx = &Cxform::Identity;
        if (area.pHandle->HasElement(MatrixPoolImpl::HMatrixConstants::Element_Cxform))
            cx = area.pHandle->GetCxformPtr();
        FUN_142734e10(&SManager, mvp, *cx, filter, temporaries, shaders, passes - 1, passes,
                      MappedXY16iAlphaTexture[0], &ShaderData);
        applyBlendMode(BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal, true);
        pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
        pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        PopRenderTarget();

        if (MaskStackTop)
        {
            if (StencilAvailable)
                pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
            else if (DepthBufferAvailable)
                pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
        }
        if (HALState & HS_DrawingMask)
            pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0);

        // now the final result is cached: draw it as such
        RenderTarget* newTarget = temporaries[1];
        primitive->SetCacheResults(FilterPrimitive::Cache_Target, &newTarget, 1);
        ((RenderTargetData*)newTarget->GetRenderTargetData())->CacheID = (UPInt)primitive;
        drawCachedFilter(primitive);

        for (unsigned t = 0; t < 3; t++)
            if (temporaries[t])
                temporaries[t]->SetInUse(false);
        return;
    }

    // Cache_Target: the result as a textured quad over the filtered area
    unsigned shader = 1 | ((DeviceFlags & 4) << 2);
    if (DeviceFlags & 1)
        shader += 1;
    if (DeviceFlags & 8)
        shader += 8;
    setDrawableShader(&ShaderData, shader, MappedXY16iAlphaTexture[0]);
    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);

    RenderTarget* results;
    primitive->GetCacheResults(&results, 1);
    Render::Texture* ptexture = results->GetTexture();
    Matrix2F mvp = Matrices.UserView * primitive->GetFilterAreaMatrix().GetMatrix2D();

    // the result's rectangle within its texture
    const Rect<int>& srect = results->GetRect();
    float    sx = (float)srect.Width() / (float)ptexture->ImgSize.Width;
    float    sy = (float)srect.Height() / (float)ptexture->ImgSize.Height;
    Matrix2F texgen;
    texgen.M[0][0] = sx;
    texgen.M[0][1] = 0.0f * sx;
    texgen.M[0][2] = 0.0f * sx;
    texgen.M[0][3] = ((float)srect.x1 + 0.0f) * sx;
    texgen.M[1][0] = 0.0f * sy;
    texgen.M[1][1] = sy;
    texgen.M[1][2] = 0.0f * sy;
    texgen.M[1][3] = ((float)srect.y1 + 0.0f) * sy;

    const ShaderPair& cur = ShaderData.GetCurrentShaders();
    ShaderData.SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8);
    ShaderData.SetUniform(cur, Uniform::SU_texgen, &texgen.M[0][0], 8);
    ShaderData.SetTexture(cur, Uniform::SU_tex, ptexture, ImageFillMode());
    ShaderData.Finish(1);

    applyBlendMode(BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal, true);
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
    applyBlendMode(BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal, false,
                   (HALState & HS_InRenderTarget) != 0);
    pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    results->SetInUse(false);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142732ec0
void HAL::PushFilters(FilterPrimitive* prim)
{
    ScopedRenderEvent evt(GetEvent(Event_Filter), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        FUN_1426c1790(this, HS_InDisplay, __FUNCTION__);
        return;
    }

    FilterStackEntry e = { prim, 0 };

    // filters the profile cannot draw: the content draws unfiltered
    if (!shouldRenderFilters(prim) || (HALState & HS_CachedFilter))
    {
        FilterStack.PushBack(e);
        return;
    }

    // masks of the target below do not apply inside a filter without its own
    if (MaskStackTop != 0 && !prim->GetMaskPresent() && prim->GetCacheState() != FilterPrimitive::Cache_Target)
    {
        if (StencilAvailable)
            pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
        else if (DepthBufferAvailable)
            pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xf);
    }

    HALState |= HS_DrawingFilter;

    if (prim->GetCacheState() == FilterPrimitive::Cache_Uncached)
    {
        // draw the content into a target of the filtered area's size
        const Matrix2F& m = prim->GetFilterAreaMatrix().GetMatrix2D();
        e.pRenderTarget   = *CreateTempRenderTarget(ImageSize((UInt32)(SInt64)m.Sx(), (UInt32)(SInt64)m.Sy()),
                                                  prim->GetMaskPresent());
        RectF frameRect(m.Tx(), m.Ty(), m.Tx() + m.Sx(), m.Ty() + m.Sy());
        PushRenderTarget(frameRect, e.pRenderTarget);
        applyBlendMode(BlendModeStack.GetSize() ? BlendModeStack.Back() : Blend_Normal, false, true);

        // the new depth stencil surface does not hold the mask: fill it with the current level
        if (prim->GetMaskPresent())
        {
            if (StencilAvailable)
                pDevice->Clear(0, 0, D3DCLEAR_STENCIL, 0, 0.0f, MaskStackTop);
            else if (DepthBufferAvailable)
                pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        }
    }
    else
    {
        // a cached result: skip what is queued up to the matching PopFilters
        HALState |= HS_CachedFilter;
        CachedFilterIndex = (int)FilterStack.GetSize();
        GetRQProcessor().SetQueueEmitFilter(RenderQueueProcessor::QPF_Filters);
    }
    FilterStack.PushBack(e);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142732830
void HAL::PopFilters()
{
    ScopedRenderEvent evt(GetEvent(Event_Filter), __FUNCTION__, false);
    if (!shouldRenderFilters(FilterStack.Back().pPrimitive))
    {
        FilterStack.Pop();
        return;
    }
    Render::HAL::PopFilters();
}

// a channel in 0..1, zero kept exact
static float clearChannel(UByte c)
{
    return c ? (float)c / 255.0f : 0.0f;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142736e50
void HAL::clearSolidRectangle(const Rect<int>& r, Color color)
{
    ScopedRenderEvent evt(GetEvent(Event_Clear), __FUNCTION__);
    if (color.GetAlpha() == 0xff && !(VP.Flags & Viewport::View_Stereo_AnySplit))
    {
        // opaque: the device clears it
        D3DRECT dr = { r.x1 + VP.Left, r.y1 + VP.Top, r.x2 + VP.Left, r.y2 + VP.Top };
        pDevice->Clear(1, &dr, D3DCLEAR_TARGET, color.ToColor32(), 1.0f, 0);
        return;
    }

    // blended: a solid quad over the rectangle
    float colorf[4] = { clearChannel(color.GetRed()), clearChannel(color.GetGreen()), clearChannel(color.GetBlue()),
                        clearChannel(color.GetAlpha()) };
    Matrix2F m;
    m.M[0][0] = (float)(r.x2 - r.x1);
    m.M[0][1] = 0.0f;
    m.M[0][2] = 0.0f;
    m.M[0][3] = (float)r.x1;
    m.M[1][0] = 0.0f;
    m.M[1][1] = (float)(r.y2 - r.y1);
    m.M[1][2] = 0.0f;
    m.M[1][3] = (float)r.y1;
    Matrix2F mvp;
    mvp.SetToAppend(m, Matrices.UserView);

    setDrawableShader(&ShaderData, 0x8003, MappedXY16iAlphaSolid[0]);
    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
    const ShaderPair& cur = ShaderData.GetCurrentShaders();
    ShaderData.SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8);
    ShaderData.SetUniform(cur, Uniform::SU_cxmul, colorf, 4);
    ShaderData.Finish(1);
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x142737c40
void HAL::drawMaskClearRectangles(const MatrixPoolImpl::HMatrix* matrices, UPInt count)
{
    ScopedRenderEvent evt(GetEvent(Event_MaskClear), __FUNCTION__);
    setDrawableShader(&ShaderData, 0x8005, MappedXY16iAlphaSolid[PrimitiveBatch::DP_Batch]);
    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);

    // the erase buffer holds 30 quads
    for (UPInt i = 0; i < count;)
    {
        unsigned batch = (unsigned)Alg::Min<UPInt>(count - i, 30);
        for (unsigned j = 0; j < batch; j++)
        {
            const MatrixPoolImpl::HMatrix& m = matrices[i + j];
            const ShaderPair& cur = ShaderData.GetCurrentShaders();
            if (!m.Has3D())
            {
                Matrix2F mvp;
                mvp.SetToAppend(Matrix2F::Identity, m.GetMatrix2D(), Matrices.UserView);
                ShaderData.SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8, 0, j);
            }
            else
            {
                Matrix3F t;
                t.MultiplyMatrix(m.GetMatrix3D(), Matrix2F::Identity);
                Matrix4F mvp;
                mvp.MultiplyMatrix(Matrices.GetUVPO(), t);
                ShaderData.SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 16, 0, j);
            }
        }
        ShaderData.Finish(batch);
        pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, batch * 2);
        AccumulatedStats.Meshes += batch;
        AccumulatedStats.Triangles += batch * 2;
        AccumulatedStats.Primitives++;
        i += batch;
    }
}
// MS2-FUNCTIONAL: written from the decompile
// @0x142733240
void HAL::PushMask_BeginSubmit(MaskPrimitive* prim)
{
    ScopedRenderEvent evt(GetEvent(Event_Mask), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        FUN_1426c1790(this, HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!StencilAvailable && !DepthBufferAvailable)
    {
        checkMaskBufferCaps();
        if (!StencilAvailable && !DepthBufferAvailable)
            return;
    }

    if (StencilAvailable)
    {
        pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0);
        pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
        pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);
        pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
        pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
    }

    bool viewportValid = (HALState & HS_ViewValid) != 0;

    // masks left above the top of the stack from an earlier pop are erased back to the top's depth
    if (MaskStackTop && MaskStackTop < MaskStack.GetSize() && viewportValid && StencilAvailable && MultiBitStencil &&
        StencilOpInc != D3DSTENCILOP_REPLACE)
    {
        pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop);
        pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL);
        pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
        MaskPrimitive* old = MaskStack[MaskStackTop].pPrimitive;
        drawMaskClearRectangles(old->GetMaskAreaMatrices(), old->GetMaskCount());
    }

    MaskStack.Resize(MaskStackTop + 1);
    MaskStackEntry& e  = MaskStack[MaskStackTop];
    e.pPrimitive       = prim;
    e.OldViewportValid = viewportValid;
    e.OldViewRect      = ViewRect;
    HALState |= HS_DrawingMask;
    MaskStackTop++;

    if (prim->IsClipped() && viewportValid)
    {
        // a clipped mask narrows the view to its bounds
        const Matrix2F& m = prim->GetMaskAreaMatrices()[0].GetMatrix2D();
        RectF bounds;
        if (!Matrices.OrientationSet)
        {
            // clipped matrices are in view space, unrotated
            bounds.x1 = m.Tx();
            bounds.y1 = m.Ty();
            bounds.x2 = m.Tx() + m.Sx();
            bounds.y2 = m.Ty() + m.Sy();
        }
        else
        {
            Matrix2F om(m);
            om.Append(Matrices.Orient2D);
            om.EncloseTransform(&bounds, RectF(0, 0, 1, 1));
        }
        int bx1 = (int)bounds.x1 + VP.Left;
        int by1 = (int)bounds.y1 + VP.Top;
        int bx2 = (int)bounds.x2 + VP.Left;
        int by2 = (int)bounds.y2 + VP.Top;
        if (ViewRect.y2 < by1 || by2 < ViewRect.y1 || bx2 < ViewRect.x1 || ViewRect.x2 < bx1)
        {
            ViewRect.x1 = ViewRect.y1 = ViewRect.x2 = ViewRect.y2 = 0;
            HALState &= ~HS_ViewValid;
            viewportValid = false;
        }
        else
        {
            ViewRect.x1 = Alg::Max(ViewRect.x1, bx1);
            ViewRect.x2 = Alg::Min(ViewRect.x2, bx2);
            ViewRect.y1 = Alg::Max(ViewRect.y1, by1);
            ViewRect.y2 = Alg::Min(ViewRect.y2, by2);
        }
        updateViewport();

        // the first mask clears the whole (narrowed) view
        if (MaskStackTop == 1 && viewportValid)
        {
            if (StencilAvailable)
                pDevice->Clear(0, 0, D3DCLEAR_STENCIL, 0, 0.0f, 0);
            else if (DepthBufferAvailable)
                pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        }
    }
    else if (MaskStackTop == 1 && viewportValid)
    {
        // the first mask clears the areas it covers
        if (!StencilAvailable)
        {
            UPInt count = prim->GetMaskCount();
            for (UPInt i = 0; i < count; i++)
            {
                RectF bounds;
                prim->GetMaskAreaMatrices()[i].GetMatrix2D().EncloseTransform(&bounds, RectF(0, 0, 1, 1));
                int bx1 = (int)bounds.x1 + VP.Left;
                int by1 = (int)bounds.y1 + VP.Top;
                int bx2 = (int)bounds.x2 + VP.Left;
                int by2 = (int)bounds.y2 + VP.Top;
                if (ViewRect.y1 <= by2 && by1 <= ViewRect.y2 && bx1 <= ViewRect.x2 && ViewRect.x1 <= bx2)
                {
                    D3DRECT r;
                    r.x1 = Alg::Max(ViewRect.x1, bx1);
                    r.y1 = Alg::Max(ViewRect.y1, by1);
                    r.x2 = Alg::Min(ViewRect.x2, bx2);
                    r.y2 = Alg::Min(ViewRect.y2, by2);
                    pDevice->Clear(1, &r, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
                }
            }
        }
        else
        {
            pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
            pDevice->SetRenderState(D3DRS_STENCILREF, 0);
            pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
            pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
            drawMaskClearRectangles(prim->GetMaskAreaMatrices(), prim->GetMaskCount());
            pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
        }
    }

    if (StencilAvailable)
    {
        if (!MultiBitStencil || StencilOpInc == D3DSTENCILOP_REPLACE)
        {
            // one stencil bit: only the first mask writes
            if (MaskStackTop != 1)
                pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
            else
            {
                pDevice->SetRenderState(D3DRS_STENCILREF, 1);
                pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
                pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
            }
        }
        else
        {
            // inside the masks below, count one up
            pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop - 1);
            pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
            pDevice->SetRenderState(D3DRS_STENCILPASS, StencilOpInc);
        }
    }
    else if (DepthBufferAvailable)
    {
        if (MaskStackTop == 1)
        {
            pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
            pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
            pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
            pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
        }
        else
        {
            // depth masks do not nest
            pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0);
            pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
            pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        }
    }
    ++AccumulatedStats.Masks;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x14272fcf0
void HAL::DrawProcessedComplexMeshes(ComplexMesh* complexMesh, const StrideArray<MatrixPoolImpl::HMatrix>& matrices)
{
    ScopedRenderEvent evt(GetEvent(Event_DrawComplex), __FUNCTION__);
    D3D9::MeshCacheItem* pmesh = (D3D9::MeshCacheItem*)complexMesh->pCacheMeshItem;
    if (!(HALState & HS_InDisplay))
    {
        FUN_1426c1790(this, HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!pmesh)
        return;

    const ComplexMesh::FillRecord* fillRecords = complexMesh->FillRecords.GetDataPtr();
    unsigned  fillCount     = (unsigned)complexMesh->FillRecords.GetSize();
    unsigned  matrixCount   = (unsigned)matrices.GetSize();
    unsigned  startIndex    = (unsigned)(pmesh->IBAllocOffset >> 1);
    unsigned  maxDrawCount  = 1;
    unsigned  vertexBaseIndex = 0;
    unsigned  prevStride    = 0;

    // several instances of the mesh draw instanced when the device can
    PrimitiveBatch::BatchType batchType = PrimitiveBatch::DP_Single;
    unsigned                  formatIndex = 0;
    if (matrixCount > 1 && SManager.HasInstancingSupport())
    {
        batchType    = PrimitiveBatch::DP_Instanced;
        formatIndex  = 1;
        maxDrawCount = Alg::Min(matrixCount, Cache.GetParams().MaxBatchInstances);
    }
    else
        setLinearStreamSource(PrimitiveBatch::DP_Single);

    const Matrix2F* textureMatrices = complexMesh->FillMatrixCache.GetDataPtr();
    pDevice->SetIndices(((IndexBuffer*)pmesh->pIndexBuffer)->pBuffer);

    for (unsigned fillIndex = 0; fillIndex < fillCount; fillIndex++)
    {
        const ComplexMesh::FillRecord& fr = fillRecords[fillIndex];

        // bit 3: 3D meshes; bit 2: some instance has a color transform
        unsigned fillFlags = DeviceFlags;
        if (matrixCount)
        {
            fillFlags |= (matrices[0].GetFormatBits() >> 1) & 8;
            for (unsigned i = 0; i < matrixCount; i++)
            {
                const MatrixPoolImpl::HMatrix& hm = matrices[i];
                const Cxform& cx = (hm.GetFormatBits() & MatrixPoolImpl::HMatrixConstants::Has_Cxform)
                                       ? *hm.pHandle->GetCxformPtr() : Cxform::Identity;
                if (!(cx == Cxform::Identity))
                    fillFlags |= 4;
            }
        }

        PrimitiveFillType fillType = fr.pFill->GetType();
        unsigned          shader   = ShaderManager::StaticShaderForFill(fillType, fillFlags, batchType);
        ShaderData.SetStaticShader((VertexShaderDesc::ShaderType)shader, (FragShaderDesc::ShaderType)shader,
                                   fr.pFormats[formatIndex]);
        ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
        const ShaderPair& cur = ShaderData.GetCurrentShaders();

        // a new vertex size restarts the stream at the fill's vertices
        if (fr.pFormats[formatIndex]->Size != prevStride)
        {
            prevStride = fr.pFormats[formatIndex]->Size;
            pDevice->SetStreamSource(0, ((VertexBuffer*)pmesh->pVertexBuffer)->pBuffer,
                                     (UINT)(fr.VertexByteOffset + pmesh->VBAllocOffset), prevStride);
            vertexBaseIndex = 0;
        }

        unsigned fillTextureCount = 0;
        if ((unsigned)fillType - PrimFill_Texture < 6)
            fillTextureCount = (fillType > PrimFill_Texture_VColor_EAlpha) + 1;   // the 2Texture fills take two

        for (unsigned i = 0; i < matrixCount; i++)
        {
            unsigned                       drawIndex = i % maxDrawCount;
            const MatrixPoolImpl::HMatrix& hm        = matrices[i];

            if (!hm.Has3D())
            {
                Matrix2F m;
                m.SetToAppend(complexMesh->VertexMatrix, hm.GetMatrix2D(), Matrices.UserView);
                ShaderData.SetUniform(cur, Uniform::SU_mvp, &m.M[0][0], 8, 0, drawIndex);
            }
            else
            {
                Matrix3F t;
                t.MultiplyMatrix(hm.GetMatrix3D(), complexMesh->VertexMatrix);
                Matrix4F m;
                m.MultiplyMatrix(Matrices.GetUVPO(), t);
                ShaderData.SetUniform(cur, Uniform::SU_mvp, &m.M[0][0], 16, 0, drawIndex);
            }

            if (fillType <= PrimFill_SolidColor)
                ShaderData.SetColor(cur, Uniform::SU_cxmul, fr.pFill->GetSolidColor(), 0, drawIndex);
            else if (fillFlags & 4)
            {
                const Cxform& cx = (hm.GetFormatBits() & MatrixPoolImpl::HMatrixConstants::Has_Cxform)
                                       ? *hm.pHandle->GetCxformPtr() : Cxform::Identity;
                ShaderData.SetCxform(cur, cx, 0, drawIndex);
            }

            unsigned stageIndex = 0;
            for (unsigned tm = 0; tm < fillTextureCount; tm++)
            {
                ShaderData.SetUniform(cur, Uniform::SU_texgen, &textureMatrices[fr.FillMatrixIndex[tm]].M[0][0], 8,
                                      tm * 2, drawIndex);
                Render::Texture* ptex = fr.pFill->GetTexture(tm);
                ShaderData.SetTexture(cur, Uniform::SU_tex, ptex, fr.pFill->GetFillMode(tm), stageIndex);
                // (the exe reads +0x3e bit 1 and the byte at +0x3c)
                unsigned stages = (ptex->Use & 2) ? 1 : ptex->MipLevels;
                stageIndex += ImageData::GetFormatPlaneCount((ImageFormat)ptex->GetFormat()) * stages;
            }

            if (batchType == PrimitiveBatch::DP_Instanced)
            {
                unsigned next = (i + 1) % maxDrawCount;
                if ((next == 0 && i != 0) || i == matrixCount - 1)
                {
                    unsigned drawCount = maxDrawCount;
                    if (i == matrixCount - 1 && next != 0)
                        drawCount = next;
                    setInstancedStreamSource(drawCount);
                    ShaderData.Finish(drawCount);
                    pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, vertexBaseIndex, 0, fr.VertexCount,
                                                  startIndex + fr.IndexOffset, fr.IndexCount / 3);
                    AccumulatedStats.Primitives++;
                }
            }
            else
            {
                ShaderData.Finish(1);
                pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, vertexBaseIndex, 0, fr.VertexCount,
                                              startIndex + fr.IndexOffset, fr.IndexCount / 3);
                AccumulatedStats.Primitives++;
                if (i != matrixCount - 1)
                    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
            }
        }

        AccumulatedStats.Meshes += matrixCount;
        AccumulatedStats.Triangles += (fr.IndexCount / 3) * matrixCount;
        vertexBaseIndex += fr.VertexCount;
    }

    pmesh->GPUFence = Cache.GetRenderSync()->InsertFence();
    pmesh->MoveToCacheListFront(MCL_ThisFrame);
}

} // namespace D3D9

// the template members this TU emits
template class StaticShaderManager<D3D9::FragShaderDesc, D3D9::VertexShaderDesc, D3D9::Uniform, D3D9::ShaderInterface,
                                   D3D9::Texture>;
template class ShaderInterfaceBase<D3D9::Uniform, D3D9::ShaderPair>;
}} // namespace Scaleform::Render

using namespace Scaleform;
using namespace Scaleform::Render;

// FragShader's ctor, as the HAL ctor's array construction calls it
// MS2-FUNCTIONAL: written from the decompile
// @0x14272dbd0
D3D9::FragShader* FUN_14272dbd0(D3D9::FragShader* p)
{
    return ::new (p) D3D9::FragShader();
}

// RenderBuffer::~RenderBuffer, a copy the HAL dtor calls
// MS2-FUNCTIONAL: written from the decompile
// @0x14272e5e0
void FUN_14272e5e0(RenderBuffer* p)
{
    p->RenderBuffer::~RenderBuffer();
}

// Render::HAL::~HAL, the base's member destruction the D3D9 dtor calls
// MS2-FUNCTIONAL: written from the decompile
// @0x14272e730
void FUN_14272e730(Render::HAL* hal)
{
    hal->Render::HAL::~HAL();
}

// RenderBuffer::~RenderBuffer, a second copy
// MS2-FUNCTIONAL: written from the decompile
// @0x14272e8f0
void FUN_14272e8f0(RenderBuffer* p)
{
    p->RenderBuffer::~RenderBuffer();
}

// a RefCountNTSImplCore deleting dtor
// MS2-FUNCTIONAL: written from the decompile
// @0x14272efd0
void* FUN_14272efd0(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// a RefCountNTSImplCore deleting dtor, a second copy
// MS2-FUNCTIONAL: written from the decompile
// @0x14272f030
void* FUN_14272f030(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// DepthStencilBuffer's deleting dtor
// MS2-FUNCTIONAL: written from the decompile
// @0x14272f090
void* FUN_14272f090(DepthStencilBuffer* p, unsigned flags)
{
    p->DepthStencilBuffer::~DepthStencilBuffer();
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// ConstructorMov<RenderTargetEntry>::Construct: the render target stack's copy construction
// MS2-FUNCTIONAL: written from the decompile
// @0x14272f730
void FUN_14272f730(void* p, const Render::HAL::RenderTargetEntry& source)
{
    ::new (p) Render::HAL::RenderTargetEntry(source);
}

// Color::GetRGBAFloat
// MS2-FUNCTIONAL: written from the decompile
// @0x142732050
void FUN_142732050(const Color* c, float* r, float* g, float* b, float* a)
{
    c->GetRGBAFloat(r, g, b, a);
}

typedef ArrayDataBase<Render::HAL::FilterStackEntry, AllocatorLH<Render::HAL::FilterStackEntry, Stat_Default_Mem>,
                      ArrayConstPolicy<0, 8, true> >
    FilterStackData;
typedef ArrayData<Render::HAL::MaskStackEntry, AllocatorLH<Render::HAL::MaskStackEntry, Stat_Default_Mem>,
                  ArrayConstPolicy<0, 8, true> >
    MaskStackData;

// FilterStack's ArrayDataBase::ResizeNoConstruct
// MS2-FUNCTIONAL: written from the decompile
// @0x142733fd0
void FUN_142733fd0(FilterStackData* a, const void* pheapAddr, UPInt newSize)
{
    a->ResizeNoConstruct(pheapAddr, newSize);
}

// FilterStack's PushBack
// MS2-FUNCTIONAL: written from the decompile
// @0x142732e40
void FUN_142732e40(FilterStackData* a, const Render::HAL::FilterStackEntry& e)
{
    FUN_142733fd0(a, a, a->Size + 1);
    ::new (&a->Data[a->Size - 1]) Render::HAL::FilterStackEntry(e);
}

// MaskStack's ArrayData::Resize
// MS2-FUNCTIONAL: written from the decompile
// @0x142733ef0
void FUN_142733ef0(MaskStackData* a, UPInt newSize)
{
    a->Resize(newSize);
}

// StaticShaderManager::SetPrimitiveFill: picks the shader of a batch and sets its meshes' uniforms
// MS2-FUNCTIONAL: written from the decompile
// @0x1427359d0
const D3D9::ShaderPair* FUN_1427359d0(D3D9::ShaderManager* sm, PrimitiveFill* fill, unsigned* fillFlags,
                                      unsigned batchType, const VertexFormat* format, unsigned meshCount,
                                      MatrixState* matrices, const Primitive::MeshEntry* meshes,
                                      D3D9::ShaderInterface* psi)
{
    SF_UNUSED(sm);
    typedef MatrixPoolImpl::HMatrixConstants HC;
    PrimitiveFillType type = fill->GetType();

    // bit 4: the fill is transparent (a solid color with alpha, a texture format with alpha)
    if (!(*fillFlags & 0x10))
    {
        switch (type)
        {
        case PrimFill_None:
        case PrimFill_Mask:
        case PrimFill_SolidColor:
            if (fill->GetSolidColor().GetAlpha() != 0xff)
                *fillFlags |= 0x10;
            break;
        case PrimFill_Texture:
        case PrimFill_2Texture:
        case PrimFill_UVTexture:
            for (unsigned i = 0; i < 2; i++)
            {
                Render::Texture* tex = fill->GetTexture(i);
                if (!tex)
                    continue;
                unsigned f = tex->GetFormat();
                if (f != 3 && f != 4 && f != 0x35 && f != 0x37 && f != 0x3b && f != 200)
                    *fillFlags |= 0x10;
            }
            break;
        default:
            *fillFlags |= 0x10;
            break;
        }
    }

    // bit 2: some mesh has a cxform (bit 4 too when it fades)
    for (unsigned i = 0; i < meshCount; i++)
    {
        const MatrixPoolImpl::HMatrix& m = meshes[i].M;
        const Cxform& cx = m.pHandle->pHeader->HasElement(HC::Element_Cxform) ? *m.pHandle->pHeader->GetCxformPtr()
                                                                              : Cxform::Identity;
        if (!(cx == Cxform::Identity))
        {
            *fillFlags |= 4;
            if (cx.M[0][3] < 1.0f)
                *fillFlags |= 0x10;
            break;
        }
    }

    // YUV video fills have their own shaders
    unsigned shader;
    unsigned planes = 0;
    if ((type == PrimFill_Texture || type == PrimFill_Texture_EAlpha) && fill->GetTexture(0) &&
        (planes = ImageData::GetFormatPlaneCount((ImageFormat)fill->GetTexture(0)->GetFormat())) >= 3)
    {
        shader = (type == PrimFill_Texture_EAlpha) ? 0xa025 : 0xa005;
        if (planes == 4)
            shader += 0x100;
        if (*fillFlags & 4)
            shader += 0x10;
        if (batchType == 1)
            shader += 2;
        else if (batchType == 2)
            shader += 4;
        if (*fillFlags & 1)
            shader += 1;
        if (*fillFlags & 8)
            shader += 8;
    }
    else
        shader = D3D9::ShaderManager::StaticShaderForFill(type, *fillFlags, batchType);

    psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)shader, (D3D9::FragShaderDesc::ShaderType)shader, format);
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    const D3D9::ShaderPair& cur = psi->GetCurrentShaders();

    if (type <= PrimFill_SolidColor)
        psi->SetColor(cur, D3D9::Uniform::SU_cxmul, fill->GetSolidColor());
    else if (type > 4)
    {
        psi->SetTexture(cur, D3D9::Uniform::SU_tex, fill->GetTexture(0), fill->GetFillMode(0));
        if (type == PrimFill_2Texture || type == PrimFill_2Texture_EAlpha)
            psi->SetTexture(cur, D3D9::Uniform::SU_tex, fill->GetTexture(1), fill->GetFillMode(1),
                            ImageData::GetFormatPlaneCount((ImageFormat)fill->GetTexture(0)->GetFormat()));
    }

    // (fill 13: this build's user shader fill)
    if (type == 13)
        for (unsigned i = 0; i < meshCount; i++)
            psi->SetUserUniforms(cur, meshes[i].M, i);

    // the number of texgen matrices the shader takes
    unsigned n = 0;
    const unsigned tg = D3D9::Uniform::SU_texgen;
    if (cur.pVDesc->BatchUniforms[tg].Array >= 0 && cur.pVDesc->BatchUniforms[tg].Size)
        n = cur.pVDesc->BatchUniforms[tg].Size;
    else if (cur.pVDesc->Uniforms[tg].Location >= 0 && cur.pVDesc->Uniforms[tg].Size > 0)
        n = cur.pVDesc->Uniforms[tg].Size / cur.pVDesc->Uniforms[tg].ElementSize;
    else if (cur.pFDesc->BatchUniforms[tg].Array >= 0 && cur.pFDesc->BatchUniforms[tg].Size)
        n = cur.pFDesc->BatchUniforms[tg].Size;
    else if (cur.pFDesc->Uniforms[tg].Location >= 0 && cur.pFDesc->Uniforms[tg].Size > 0)
        n = cur.pFDesc->Uniforms[tg].Size / cur.pFDesc->Uniforms[tg].ElementSize;
    unsigned texgenCount = (n >> 1) & 0x7fff;

    for (unsigned i = 0; i < meshCount; i++)
    {
        const MatrixPoolImpl::HMatrix& m      = meshes[i].M;
        const Matrix2F&                vertex = meshes[i].pMesh->VertexMatrix;

        if (!m.Has3D())
        {
            Matrix2F mvp;
            mvp.SetToAppend(vertex, m.GetMatrix2D(), matrices->UserView);
            psi->SetUniform(cur, D3D9::Uniform::SU_mvp, &mvp.M[0][0], 8, 0, i);
        }
        else
        {
            Matrix3F t;
            t.MultiplyMatrix(m.GetMatrix3D(), vertex);
            Matrix4F mvp;
            mvp.MultiplyMatrix(matrices->GetUVPO(), t);
            psi->SetUniform(cur, D3D9::Uniform::SU_mvp, &mvp.M[0][0], 16, 0, i);
        }

        if (type == PrimFill_Mask)
            psi->SetColor(cur, D3D9::Uniform::SU_cxmul, Color(0x80800000), 0, i);
        else if (*fillFlags & 4)
        {
            const Cxform& cx = m.pHandle->pHeader->HasElement(HC::Element_Cxform)
                                   ? *m.pHandle->pHeader->GetCxformPtr()
                                   : Cxform::Identity;
            psi->SetUniform(cur, D3D9::Uniform::SU_cxmul, cx.M[0], 4, 0, i);
            psi->SetUniform(cur, D3D9::Uniform::SU_cxadd, cx.M[1], 4, 0, i);
        }

        for (unsigned t = 0; t < texgenCount; t++)
        {
            Matrix2F tm(vertex);
            HC::ElementIndex e = (HC::ElementIndex)(HC::Element_T0 + t);
            tm.Append(m.pHandle->pHeader->HasElement(e) ? *m.pHandle->pHeader->GetTextureMatrixPtr(e)
                          : Matrix2F::Identity);
            psi->SetUniform(cur, tg, &tm.M[0][0], 8, t * 2, i);
        }
    }

    if (!(*fillFlags & 0x20))
        psi->Finish(meshCount);
    return &psi->CurShaders;
}

// StaticShaderManager::DrawableFinish: the uniforms every drawable shader takes, then the upload
// MS2-FUNCTIONAL: written from the decompile
// @0x142731310
bool FUN_142731310(D3D9::ShaderManager* sm, unsigned srcCount, Render::Texture** tex, const Matrix2F* texgen,
                   Size<int> texsize, const Matrix2F& mvpIn, D3D9::ShaderInterface* psi, unsigned flags)
{
    SF_UNUSED(sm);
    Matrix2F mvp(mvpIn);
    // bit 1: the viewport is upside down
    if (flags & 2)
    {
        mvp.M[0][3] += mvp.M[0][1];
        mvp.M[0][1] = -mvp.M[0][1];
        mvp.M[0][2] = 0.0f;
        mvp.M[1][3] += mvp.M[1][1];
        mvp.M[1][1] = -mvp.M[1][1];
        mvp.M[1][2] = 0.0f;
    }
    // bit 0: a pixel's offset (D3D9 samples pixel centers)
    if (flags & 1)
    {
        mvp.M[0][3] -= 1.0f / (float)texsize.Width;
        mvp.M[1][3] += 1.0f / (float)texsize.Height;
    }
    psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_mvp, &mvp.M[0][0], 8);
    for (unsigned i = 0; i < srcCount; i++)
    {
        psi->SetTexture(psi->GetCurrentShaders(), D3D9::Uniform::SU_tex, tex[i],
                        ImageFillMode(Wrap_Clamp, Sample_Point), i);
        psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_texgen, &texgen[i].M[0][0], 8, i * 2);
    }
    psi->Finish(1);
    return true;
}

// StaticShaderManager::SetDrawableMergeFill
// MS2-FUNCTIONAL: written from the decompile
// @0x142734410
bool FUN_142734410(D3D9::ShaderManager* sm, Render::Texture** tex, const Matrix2F* texgen, Size<int> texsize,
                   const Matrix4F* cxmul, const VertexFormat* format, D3D9::ShaderInterface* psi, unsigned flags)
{
    psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)0x1a64f, (D3D9::FragShaderDesc::ShaderType)0x1a64f,
                         format);
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    for (unsigned i = 0; i < 2; i++)
        psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_cxmul, &cxmul[i].M[0][0], 16, i);
    Matrix2F mvp;
    mvp.M[0][0] = 2.0f; mvp.M[0][1] = 0.0f;  mvp.M[0][2] = 0.0f; mvp.M[0][3] = -1.0f;
    mvp.M[1][0] = 0.0f; mvp.M[1][1] = -2.0f; mvp.M[1][2] = 0.0f; mvp.M[1][3] = 1.0f;
    return FUN_142731310(sm, 2, tex, texgen, texsize, mvp, psi, flags);
}

// StaticShaderManager::SetDrawableThreshold: the comparison picks the shader variant
// MS2-FUNCTIONAL: written from the decompile
// @0x142734790
bool FUN_142734790(D3D9::ShaderManager* sm, Render::Texture** tex, const Matrix2F* texgen, Size<int> texsize,
                   const Matrix2F& mvp, unsigned op, UInt32 threshold, UInt32 color, UInt32 mask, bool copySource,
                   const VertexFormat* format, D3D9::ShaderInterface* psi, unsigned flags)
{
    unsigned shader = copySource ? 0x1a696 : 0x1a655;
    switch (op)
    {
    case 1: shader += 0x20;
    case 2: shader += 0x10;
    case 3: shader += 8;
    case 4: shader += 4;
    case 5: shader += 2;
    }
    psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)shader, (D3D9::FragShaderDesc::ShaderType)shader, format);
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);

    float rgba[4];
    Color(threshold & mask).GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_threshold, rgba, 4);
    Color(mask).GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_mask, rgba, 4);
    Color(color).GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniform(psi->GetCurrentShaders(), D3D9::Uniform::SU_color, rgba, 4);
    return FUN_142731310(sm, copySource ? 2 : 1, tex, texgen, texsize, mvp, psi, flags);
}

// StaticShaderManager::SetFilterFill: the uniforms of one filter pass, drawn from the first target's texture; a blur
// pass takes its kernel size, a shadow pass its colors, offset and the source, a color matrix its matrix
// MS2-FUNCTIONAL: written from the decompile
// @0x142734e10
void FUN_142734e10(D3D9::ShaderManager* sm, const Matrix2F& mvp, const Cxform& cx, const Filter* filter,
                   Ptr<RenderTarget>* targets, unsigned* shaders, unsigned pass, unsigned passCount,
                   const VertexFormat* format, D3D9::ShaderInterface* psi)
{
    SF_UNUSED(sm);
    psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)shaders[pass],
                         (D3D9::FragShaderDesc::ShaderType)shaders[pass], format);
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    const D3D9::ShaderPair& cur = psi->GetCurrentShaders();
    psi->SetUniform(cur, D3D9::Uniform::SU_mvp, &mvp.M[0][0], 8);

    unsigned         shader = shaders[pass];
    Render::Texture* ptex   = targets[0]->GetTexture();
    psi->SetTexture(cur, D3D9::Uniform::SU_tex, ptex, ImageFillMode(Wrap_Clamp, Sample_Linear));

    // the target's rectangle inside its texture
    const Rect<int>& r  = targets[0]->GetRect();
    float            sx = (float)(r.x2 - r.x1) / (float)ptex->ImgSize.Width;
    float            sy = (float)(r.y2 - r.y1) / (float)ptex->ImgSize.Height;
    float texgen[8] = { sx, sx * 0.0f, sx * 0.0f, ((float)r.x1 + 0.0f) * sx,
                        sy * 0.0f, sy, sy * 0.0f, ((float)r.y1 + 0.0f) * sy };
    psi->SetUniform(cur, D3D9::Uniform::SU_texgen, texgen, 8);

    if (filter->GetFilterType() <= Filter_Blur_End)
    {
        const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();
        psi->SetCxform(cur, cx);

        float texscale[2] = { 1.0f / (float)ptex->ImgSize.Width, 1.0f / (float)ptex->ImgSize.Height };
        float blurx       = floorf(params.BlurX * 0.05f);
        float blury       = floorf(params.BlurY * 0.05f);
        if (blurx < 1.0f)
            blurx = 1.0f;
        if (blury < 1.0f)
            blury = 1.0f;

        // the box blur shaders run x and y in turn
        float fsize[4];
        float samples;
        if (shader - 0xa249 < 2)
        {
            if (!(pass & 1))
            {
                fsize[0]    = (blurx - 1.0f) * 0.5f;
                fsize[1]    = 0.0f;
                texscale[1] = 0.0f;
                samples     = blurx;
            }
            else
            {
                fsize[0]    = (blury - 1.0f) * 0.5f;
                fsize[1]    = 0.0f;
                texscale[0] = 0.0f;
                samples     = blury;
            }
        }
        else if (pass == passCount - 1 && pass != 0)
        {
            fsize[0] = 0.0f;
            fsize[1] = (blury - 1.0f) * 0.5f;
            samples  = blury;
        }
        else
        {
            fsize[0] = (blurx - 1.0f) * 0.5f;
            fsize[1] = (blury - 1.0f) * 0.5f;
            samples  = blury * blurx;
        }
        fsize[2] = (pass == passCount - 1) ? params.Strength : 1.0f;
        fsize[3] = 1.0f / samples;
        psi->SetUniform(cur, D3D9::Uniform::SU_fsize, fsize, 4);
        psi->SetUniform(cur, D3D9::Uniform::SU_texscale, texscale, 2);

        // the shadow shaders
        if (shader - 0xa64b > 0x4501)
        {
            psi->Finish(0);
            return;
        }
        float scolor[4], scolor2[4];
        params.Colors[0].GetRGBAFloat(&scolor[0], &scolor[1], &scolor[2], &scolor[3]);
        params.Colors[1].GetRGBAFloat(&scolor2[0], &scolor2[1], &scolor2[2], &scolor2[3]);
        float offset[2] = { params.Offset.x * 0.05f, params.Offset.y * 0.05f };

        // the source drawn under the shadow (not for a hidden object without knockout)
        if ((params.Mode & (BlurFilterParams::Mode_Knockout | BlurFilterParams::Mode_HideObject)) !=
                BlurFilterParams::Mode_HideObject &&
            targets[2])
        {
            Render::Texture* psrc = targets[2]->GetTexture();
            float srctexscale[2]  = { 1.0f / ((float)psrc->ImgSize.Width * texscale[0]),
                                      1.0f / ((float)psrc->ImgSize.Height * texscale[1]) };
            psi->SetUniform(cur, D3D9::Uniform::SU_srctexscale, srctexscale, 2);
            psi->SetTexture(cur, D3D9::Uniform::SU_srctex, psrc, ImageFillMode(Wrap_Clamp, Sample_Linear));
        }
        psi->SetUniform(cur, D3D9::Uniform::SU_scolor, scolor, 4);
        psi->SetUniform(cur, D3D9::Uniform::SU_offset, offset, 2);
        if (params.Mode & BlurFilterParams::Mode_Highlight)
            psi->SetUniform(cur, D3D9::Uniform::SU_scolor2, scolor2, 4);
    }
    else
    {
        // the color matrix with the cxform folded in, premultiplied by the cxform's alpha
        const ColorMatrixFilter& m = *(const ColorMatrixFilter*)filter;
        const float*             mul = cx.M[0];
        const float*             add = cx.M[1];
        float                    a   = mul[3];
        float                    cxmul[16];
        float                    cxadd[4];
        for (unsigned i = 0; i < 4; i++)
        {
            cxmul[i * 4 + 0] = mul[0] * m[i * 4 + 0] * a;
            cxmul[i * 4 + 1] = mul[1] * m[i * 4 + 1] * a;
            cxmul[i * 4 + 2] = mul[2] * m[i * 4 + 2] * a;
            cxmul[i * 4 + 3] = m[i * 4 + 3] * a;
        }
        cxadd[0] = (mul[0] * m[16] * a + add[0] / 255.0f) * a;
        cxadd[1] = (mul[1] * m[17] * a + add[1] / 255.0f) * a;
        cxadd[2] = (mul[2] * m[18] * a + add[2] / 255.0f) * a;
        cxadd[3] = (a * m[19] + add[3] / 255.0f) * a;
        psi->SetUniform(cur, D3D9::Uniform::SU_cxadd, cxadd, 4);
        psi->SetUniform(cur, D3D9::Uniform::SU_cxmul, cxmul, 16);
    }
    psi->Finish(0);
}


// MS2-PIN: ??0HAL@D3D9@Render@Scaleform@@QEAA@PEAVThreadCommandQueue@23@@Z 0x14272dc10
// MS2-PIN: ?GetFilterPasses@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEBAIPEBVFilter@23@IPEAI@Z 0x142731f10
// MS2-PIN: ?GetVertexFormat@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEAAPEBUVertexFormat@23@PEAUVertexElement@23@III@Z 0x142732130
// MS2-PIN: ?MapVertexFormat@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEAAXW4PrimitiveFillType@23@PEBUVertexFormat@23@PEAPEBU523@22I@Z 0x142732210
// MS2-PIN: ?StaticShaderForFill@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@SAIW4PrimitiveFillType@23@AEAII@Z 0x142736880
// MS2-PIN: ?SetColor@?$ShaderInterfaceBase@UUniform@D3D9@Render@Scaleform@@UShaderPair@234@@Render@Scaleform@@QEAAXAEBUShaderPair@D3D9@23@IVColor@23@II@Z 0x142734160
// MS2-PIN: ?SetUniform@?$ShaderInterfaceBase@UUniform@D3D9@Render@Scaleform@@UShaderPair@234@@Render@Scaleform@@QEAAXAEBUShaderPair@D3D9@23@IPEBMIII@Z 0x142736560
// MS2-PIN: ?SetUserUniforms@?$ShaderInterfaceBase@UUniform@D3D9@Render@Scaleform@@UShaderPair@234@@Render@Scaleform@@QEAAXAEBUShaderPair@D3D9@23@AEBVHMatrix@MatrixPoolImpl@23@H@Z 0x142736610
// MS2-PIN: ??_7HAL@D3D9@Render@Scaleform@@6B@ 0x14319d760
// MS2-PIN: ??_7RenderEvent@D3D9@Render@Scaleform@@6B@ 0x14319d990
// MS2-PIN: ??_7RenderEvent@Render@Scaleform@@6B@ 0x143192a98
// MS2-PIN: ??_7RenderTargetData@D3D9@Render@Scaleform@@6B@ 0x14319d988
// MS2-PIN: ??_7RenderTargetData@Render@Scaleform@@6B@ 0x14319d6d8
// MS2-PIN: ??_7RenderBuffer@Render@Scaleform@@6B@ 0x14319d6e0
// MS2-PIN: ??_7RenderTarget@Render@Scaleform@@6B@ 0x14319d6f8
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7PrimitiveFill@Render@Scaleform@@6B@ 0x143191988
// MS2-PIN: ??_7?$RefCountBaseNTS@VPrimitiveFill@Render@Scaleform@@$0EF@@Scaleform@@6B@ 0x143191988
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EF@@Scaleform@@6B@ 0x143191988
