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
#include <d3d9.h>
#include "ms2/scaleform/include/render/d3d9_hal.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/render_events.h"

// the warning a HAL call made in the wrong state would print; empty in this build
void FUN_1426c1790(Scaleform::Render::HAL* hal, unsigned stateFlags, const char* funcName);

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

} // namespace D3D9

// the template members this TU emits
template class StaticShaderManager<D3D9::FragShaderDesc, D3D9::VertexShaderDesc, D3D9::Uniform, D3D9::ShaderInterface,
                                   D3D9::Texture>;
template class ShaderInterfaceBase<D3D9::Uniform, D3D9::ShaderPair>;
}} // namespace Scaleform::Render

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
