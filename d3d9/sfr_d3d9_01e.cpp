// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 HAL TU (D3D9_HAL):
// construction / destruction, the debug events, the static shader manager's format mapping and filter passes, and
// the uniform upload of the shader interface.
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01e D3D9_HAL).
// MS2-UNIT: sfr_d3d9_01e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14272d9c0-0x142738e60 .text$mn
// MS2-RANGE: 0x142cc9910-0x142cc99b2 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin


#include <stdlib.h>
#include <new>
#include <d3d9.h>
#include "ms2/scaleform/include/render/d3d9_hal.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/render_events.h"

// a HAL call made in the wrong state calls Render::HAL::checkState_EmitWarnings (render_hal.h; empty in this build)

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
                   const Scaleform::Render::Matrix2F& mvp, int op, Scaleform::UInt32 threshold,
                   Scaleform::UInt32 color, Scaleform::UInt32 mask, bool copySource,
                   const Scaleform::Render::VertexFormat* format, Scaleform::Render::D3D9::ShaderInterface* psi,
                   unsigned flags);
// StaticShaderManager::SetFilterFill (sfr_d3d9_01e, below)
bool FUN_142734e10(Scaleform::Render::D3D9::ShaderManager* sm, const Scaleform::Render::Matrix2F& mvp,
                   const Scaleform::Render::Cxform& cx, const Scaleform::Render::Filter* filter,
                   Scaleform::Ptr<Scaleform::Render::RenderTarget>* targets, unsigned* shaders, unsigned pass,
                   unsigned passCount, const Scaleform::Render::VertexFormat* format,
                   Scaleform::Render::D3D9::ShaderInterface* psi);
// MaskStack's ArrayData::Resize (sfr_d3d9_01e, below); PushMask_BeginSubmit calls it out of line
typedef Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,
                             Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry, Scaleform::Stat_Default_Mem>,
                             Scaleform::ArrayConstPolicy<0, 8, true> >
    MaskStackData;
SF_NOINLINE void FUN_142733ef0(MaskStackData* a, Scaleform::UPInt newSize);

namespace Scaleform {
typedef ArrayDataBase<Render::HAL::FilterStackEntry, AllocatorLH<Render::HAL::FilterStackEntry, Stat_Default_Mem>,
                      ArrayConstPolicy<0, 8, true> >
    FilterStackData;
}
__declspec(noinline) void FUN_142732e40(Scaleform::FilterStackData* a, const Scaleform::Render::HAL::FilterStackEntry& e);

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

// written from the decompile
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
    memset(MappedXY16iAlphaTexture, 0, sizeof(MappedXY16iAlphaTexture));
    memset(MappedXY16iAlphaSolid, 0, sizeof(MappedXY16iAlphaSolid));
}

// written from the decompile
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

// written from the decompile
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

// written from the decompile
// @0x1427327c0
void HAL::MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat, const VertexFormat** single,
                          const VertexFormat** batch, const VertexFormat** instanced, unsigned)
{
    SManager.MapVertexFormat(fill, sourceFormat, single, batch, instanced,
                             (SManager.HasInstancingSupport() ? MVF_HasInstancing : 0) |
                                 MVF_Align | MVF_AlignVertexAttrs | MVF_ReverseColor);
}

// written from the decompile
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
            case D3DFMT_D24S8:
            case D3DFMT_D24X4S4:
            case D3DFMT_D24FS8:
                MultiBitStencil  = true;
                // fall through
            case D3DFMT_D15S1:
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
// cl inlines setLinearStreamSource here, the exe calls it
// @0x142737f10
void HAL::drawScreenQuad()
{
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, sizeof(VertexXY16iAlpha));
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}

// written from the decompile
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
        if (!FragShaderDesc::Descs[i])
            continue;
        // the dynamic looping shaders only where the device runs them
        if ((FragShaderDesc::Descs[i]->Flags & 4) && !SManager.HasDynamicLoopingSupport())
            continue;
        if (!StaticFShaders[i].Init(this, FragShaderDesc::Descs[i]))
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

// written from the decompile
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

// written from the decompile
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
        if (surface)
            *pdss = surface->pDepthStencilSurface;
    }
    return pdsb;
}

// SDK form: the surface reference is released unconditionally, the depth stencil buffer is a Ptr
// @0x14272fab0
RenderTarget* HAL::CreateRenderTarget(Render::Texture* texture, bool needsStencil)
{
    D3D9::Texture* pt = (D3D9::Texture*)texture;
    if (!pt || pt->TextureCount != 1)
        return 0;

    IDirect3DSurface9 *prenderSurface = 0, *pdsSurface = 0;
    RenderTarget* prt = pRenderBufferManager->CreateRenderTarget(texture->GetSize(), RBuffer_Texture,
                                                                 texture->GetFormat(), texture);
    if (!prt)
        return 0;
    pt->pTextures[0].pTexture->GetSurfaceLevel(0, &prenderSurface);

    Ptr<DepthStencilBuffer> pdsb;
    if (needsStencil)
    {
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(texture->GetSize());
        if (pdsb)
        {
            DepthStencilSurface* surf = (DepthStencilSurface*)pdsb->GetSurface();
            if (surf)
                pdsSurface = surf->pDepthStencilSurface;
        }
    }
    RenderTargetData::UpdateData(prt, prenderSurface, pdsb, pdsSurface);
    prenderSurface->Release();

    return prt;
}

// written from the decompile
// @0x14272fbe0
RenderTarget* HAL::CreateTempRenderTarget(const ImageSize& size, bool needsStencil)
{
    RenderTarget* prt = pRenderBufferManager->CreateTempRenderTarget(size);
    if (!prt)
        return 0;
    RenderTargetData* data = (RenderTargetData*)prt->GetRenderTargetData();
    if (data && (!needsStencil || data->pDSSurface))
        return prt;

    IDirect3DSurface9* surf = 0;
    D3D9::Texture*     pt   = (D3D9::Texture*)prt->GetTexture();
    pt->pTextures[0].pTexture->GetSurfaceLevel(0, &surf);
    IDirect3DSurface9*  pdss = 0;
    DepthStencilBuffer* pdsb = 0;
    if (needsStencil)
        pdsb = createTargetDepthStencil(pRenderBufferManager, size, &pdss);
    RenderTargetData::UpdateData(prt, surf, pdsb, pdss);
    if (pdsb)
        pdsb->Release();
    if (surf)
        surf->Release();
    return prt;
}

// written from the decompile
// @0x142731c80
void HAL::EndMaskSubmit()
{
    ScopedRenderEvent evt(GetEvent(Event_Mask), 0, false);
    if ((HALState & (HS_InDisplay | HS_DrawingMask)) != (HS_InDisplay | HS_DrawingMask))
    {
        checkState_EmitWarnings(HS_InDisplay | HS_DrawingMask, __FUNCTION__);
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

    RenderTargetStack.PopBack();
    RenderTargetData* phd = 0;
    if (RenderTargetStack.GetSize() > 0)
        phd = (RenderTargetData*)RenderTargetStack.Back().pRenderTarget->GetRenderTargetData();
    if (RenderTargetStack.GetSize() == 1)
        HALState &= ~HS_InRenderTarget;

    pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pDevice->SetRenderTarget(0, phd->pRenderSurface);
    if (phd->pDSSurface)
        pDevice->SetDepthStencilSurface(phd->pDSSurface);
    else
        pDevice->SetDepthStencilSurface(0);

    ++AccumulatedStats.RTChanges;
    HALState |= HS_ViewValid;
    updateViewport();
}

// SDK form; the base ctor (buffer, pdsb) expands in place
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

// @0x142736d60
void HAL::beginMaskDisplay()
{
    Render::HAL::beginMaskDisplay();
    StencilChecked       = false;
    StencilAvailable     = false;
    MultiBitStencil      = false;
    DepthBufferAvailable = false;
}

// SDK form (early PushBack for a null target); the depth surface is read into a local
// @0x142733b90
void HAL::PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags)
{
    // ended by the scope in PopRenderTarget
    GetEvent(Event_RenderTarget).Begin(__FUNCTION__);
    HALState |= HS_InRenderTarget;
    RenderTargetEntry entry = { prt, Matrices, ViewRect, VP };
    Matrices.SetUserMatrix(Matrix2F::Identity);

    if (!prt)
    {
        RenderTargetStack.PushBack(entry);
        return;
    }

    pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
    RenderTargetData* phd = (RenderTargetData*)prt->GetRenderTargetData();
    pDevice->SetRenderTarget(0, phd->pRenderSurface);
    IDirect3DSurface9* pds = phd->pDSSurface;
    if (pds)
        pDevice->SetDepthStencilSurface(pds);
    else
        pDevice->SetDepthStencilSurface(0);
    ++AccumulatedStats.RTChanges;

    // bit 0: keep the target's contents
    if (!(flags & 1))
        pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);

    // the view is the target's rectangle; the frame rectangle maps onto it
    VP          = Viewport(prt->GetBufferSize(), prt->GetRect());
    ViewRect.x1 = (int)frameRect.x1;
    ViewRect.y1 = (int)frameRect.y1;
    ViewRect.x2 = (int)frameRect.x2;
    ViewRect.y2 = (int)frameRect.y2;
    Matrices.ViewRectOriginal.Offset(-entry.OldViewport.Left, -entry.OldViewport.Top);
    Matrices.UVPOChanged = true;
    HALState |= HS_ViewValid;
    updateViewport();

    RenderTargetStack.PushBack(entry);
}

// MS2-FUNCTIONAL: SDK form; the bottom entry is assigned member-wise (the exe copies the rect field by field and
// keeps the target in a register). Left: the exe sinks the entry's Rect/Viewport ctor stores past the surface
// load and hoists the viewport loads above the rect stores (scheduling).
// @0x142736240
bool HAL::SetRenderTarget(RenderTarget* target, bool setState)
{
    // the bottom target cannot change while a display draws into it; a scene draws what it queued first
    if (HALState & HS_InDisplay)
        return false;
    if (HALState & HS_InScene)
        Flush();

    D3DSURFACE_DESC    desc;
    RenderTargetEntry  entry;
    RenderTargetData*  phd     = (RenderTargetData*)target->GetRenderTargetData();
    IDirect3DSurface9* surface = phd->pRenderSurface;
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
    {
        RenderTargetEntry& bottom = RenderTargetStack[0];
        bottom.pRenderTarget  = entry.pRenderTarget.GetPtr();
        bottom.OldMatrixState = entry.OldMatrixState;
        bottom.OldViewRect.x1 = entry.OldViewRect.x1;
        bottom.OldViewRect.y1 = entry.OldViewRect.y1;
        bottom.OldViewRect.x2 = entry.OldViewRect.x2;
        bottom.OldViewRect.y2 = entry.OldViewRect.y2;
        bottom.OldViewport    = entry.OldViewport;
    }
    else
        RenderTargetStack.PushBack(entry);
    return true;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x1427372c0
bool HAL::createDefaultRenderBuffer()
{
    ImageSize rtSize;

    if (GetDefaultRenderTarget())
    {
        RenderTarget* prt = GetDefaultRenderTarget();
        rtSize = prt->GetSize();
    }
    else
    {
        // wrap the device's current color / depth stencil surfaces in the default target
        IDirect3DSurface9* prenderTarget;
        IDirect3DSurface9* pdsTarget;
        D3DSURFACE_DESC    rtDesc;
        if (FAILED(pDevice->GetRenderTarget(0, &prenderTarget)) || FAILED(prenderTarget->GetDesc(&rtDesc)))
        {
            return false;
        }
        rtSize = ImageSize(rtDesc.Width, rtDesc.Height);

        Ptr<DepthStencilBuffer> pdsb = 0;
        D3DSURFACE_DESC         dsDesc;
        ImageSize               dsSize(0);
        if (SUCCEEDED(pDevice->GetDepthStencilSurface(&pdsTarget)) && SUCCEEDED(pdsTarget->GetDesc(&dsDesc)))
        {
            dsSize.SetSize(dsDesc.Width, dsDesc.Height);
            pdsb = *SF_HEAP_AUTO_NEW(this) DepthStencilBuffer(0, dsSize);
        }
        Ptr<RenderTarget> ptarget = *SF_HEAP_AUTO_NEW(this) RenderTarget(0, RBuffer_Default, rtSize);
        RenderTargetData::UpdateData(ptarget, prenderTarget, pdsb, pdsTarget);

        if (pdsTarget)
            pdsTarget->Release();
        prenderTarget->Release();

        if (!SetRenderTarget(ptarget, true))
            return false;
    }

    return pRenderBufferManager->Initialize(pTextureManager, Image_B8G8R8A8, rtSize);
}

// written from the decompile
// @0x1427329c0
void HAL::PopMask()
{
    ScopedRenderEvent evt(GetEvent(Event_PopMask), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        checkState_EmitWarnings(HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!StencilAvailable && !DepthBufferAvailable)
        return;

    // a clipped mask gives back the view it narrowed
    MaskStackTop--;
    if (MaskStack[MaskStackTop].pPrimitive->IsClipped())
    {
        ViewRect = MaskStack[MaskStackTop].OldViewRect;
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


// written from the decompile
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

// MS2-FUNCTIONAL: written from the decompile; left: the lea order of the &ShaderData / &Matrices / &fillFlags args
// of FUN_1427359d0 (the exe calls it as a member of SManager)
// @0x1427307e0
void HAL::DrawProcessedPrimitive(Primitive* prim, PrimitiveBatch* start, PrimitiveBatch* end)
{
    ScopedRenderEvent evt(GetEvent(Event_DrawPrimitive), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        checkState_EmitWarnings(HS_InDisplay, __FUNCTION__);
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
            if (batch->Type != PrimitiveBatch::DP_Instanced)
            {
                AccumulatedStats.Meshes += item->MeshCount;
                AccumulatedStats.Triangles += item->IndexCount / 3;
                setLinearStreamSource(batch->Type);
            }
            else
            {
                AccumulatedStats.Meshes += count;
                AccumulatedStats.Triangles += item->IndexCount / 3 * count;
                setInstancedStreamSource(batch->GetMeshCount());
            }
            UPInt startIndex = item->IBAllocOffset >> 1;
            pDevice->SetIndices(((IndexBuffer*)item->pIndexBuffer)->pBuffer);
            pDevice->SetStreamSource(0, ((VertexBuffer*)item->pVertexBuffer)->pBuffer, (UINT)item->VBAllocOffset,
                                     batch->pFormat->Size);
            pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, (UINT)(item->VBAllocSize / batch->pFormat->Size),
                                          (UINT)startIndex, item->IndexCount / 3);
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

// @0x142736ac0
void HAL::applyBlendMode(BlendMode mode, bool sourceAc, bool forceAc)
{
    ScopedRenderEvent evt(GetEvent(Event_ApplyBlend), __FUNCTION__);
    if (!pDevice)
        return;
    int m = ((unsigned)mode < Blend_Count) ? (int)mode : 0;

    // device flag bit 1: multiply / darken draw through the multiply shaders
    if (m == Blend_Multiply || m == Blend_Darken)
        DeviceFlags |= 1;
    else
        DeviceFlags &= ~1;

    // (the exe reads the source argument from the alpha table in both branches)
    if (!(VP.Flags & Viewport::View_AlphaComposite) && !forceAc)
    {
        pDevice->SetRenderState(D3DRS_BLENDOP, BlendModeTable[m].Op);
        pDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
        if (sourceAc && BlendModeTableAlpha[m].SrcArg == D3DBLEND_SRCALPHA)
            pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
        else
            pDevice->SetRenderState(D3DRS_SRCBLEND, BlendModeTableAlpha[m].SrcArg);
        pDevice->SetRenderState(D3DRS_DESTBLEND, BlendModeTable[m].DestArg);
    }
    else
    {
        pDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
        pDevice->SetRenderState(D3DRS_BLENDOP, BlendModeTableAlpha[m].Op);
        pDevice->SetRenderState(D3DRS_BLENDOPALPHA, BlendModeTableAlpha[m].Op);
        pDevice->SetRenderState(D3DRS_SRCBLEND, (sourceAc && BlendModeTableAlpha[m].SrcArg == D3DBLEND_SRCALPHA)
                                                    ? D3DBLEND_ONE
                                                    : BlendModeTableAlpha[m].SrcArg);
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

// written from the decompile
// @0x142731150
void HAL::DrawableCxform(Render::Texture** tex, const Matrix2F* texgen, const Cxform* cx)
{
    ScopedRenderEvent evt(GetEvent(Event_DICxform), __FUNCTION__);
    ShaderInterface* psi = &ShaderData;
    Size<int> size = drawableTargetSize(this);
    if (setDrawableShader(psi, 0x11, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(psi);
        psi->SetCxform(psi->GetCurrentShaders(), *cx);
        FUN_142731310(&SManager, 1, tex, texgen, size, drawableQuadMVP(), psi, 1);
    }
    drawScreenQuad();
}

// written from the decompile
// @0x142730b60
void HAL::DrawableCompare(Render::Texture** tex, const Matrix2F* texgen)
{
    ScopedRenderEvent evt(GetEvent(Event_DICompare), __FUNCTION__);
    ShaderInterface* psi = &ShaderData;
    Size<int> size = drawableTargetSize(this);
    if (setDrawableShader(psi, 0x1a651, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(psi);
        FUN_142731310(&SManager, 2, tex, texgen, size, drawableQuadMVP(), psi, 1);
    }
    drawScreenQuad();
}

// Copying channels is a merge with the channel matrices.
// @0x142730d00
void HAL::DrawableCopyChannel(Render::Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul)
{
    DrawableMerge(tex, texgen, cxmul);
}

// written from the decompile
// @0x1427315c0
void HAL::DrawableMerge(Render::Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul)
{
    ScopedRenderEvent evt(GetEvent(Event_DIMerge), __FUNCTION__);
    Size<int> size = drawableTargetSize(this);
    FUN_142734410(&SManager, tex, texgen, size, cxmul, MappedXY16iAlphaTexture[0], &ShaderData, 1);
    drawScreenQuad();
}

// written from the decompile
// @0x142730d10
void HAL::DrawableCopyPixels(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, bool mergeAlpha,
                             bool destAlpha)
{
    ScopedRenderEvent evt(GetEvent(Event_DICopyPixels), __FUNCTION__);
    ShaderInterface* psi = &ShaderData;
    Size<int> size = drawableTargetSize(this);
    // a third texture is the alpha source
    unsigned shader = 0x1264d;
    if (tex[2])
        shader = 0x12a4d;
    if (mergeAlpha)
        shader += 0x1000;
    if (!destAlpha)
        shader += 0x4000;
    shader += 0x80;
    if (setDrawableShader(psi, shader, MappedXY16iAlphaTexture[0]))
    {
        ShaderInterfaceAccess::BeginPrimitive(psi);
        FUN_142731310(&SManager, tex[2] ? 3 : 2, tex, texgen, size, mvp, psi, 1);
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
    ImageData data;
    Ptr<Render::Texture> ptex =
        *pTextureManager->CreateTexture(Image_B8G8R8A8, 1, ImageSize(256, 4), ImageUse_Map_Mask, 0, 0);
    if (ptex->Map(&data, 0, 1))
    {
        for (int c = 0; c < 4; c++)
        {
            UInt32* row = (UInt32*)data.GetScanline(c);
            if (channelMask & (1u << c))
                memcpy(row, values + c * 256, 256 * sizeof(UInt32));
            else
                for (unsigned i = 0; i < 256; i++)
                    *row++ = i << (c * 8);
        }
        if (ptex->Unmap())
        {
            applyBlendMode(Blend_OverwriteAll, true, true);
            Size<int> size = drawableTargetSize(this);
            ShaderInterface* psi = &ShaderData;
            if (setDrawableShader(psi, 0x1a653, MappedXY16iAlphaTexture[0]))
            {
                ShaderInterfaceAccess::BeginPrimitive(psi);
                psi->SetTexture(psi->GetCurrentShaders(), Uniform::SU_paletteMap, ptex,
                                      ImageFillMode(Wrap_Clamp, Sample_Point), 0);
                FUN_142731310(&SManager, 1, tex, texgen, size, mvp, psi, 1);
            }
            drawScreenQuad();
        }
    }
}

// written from the decompile
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

// @0x142730ec0
void HAL::DrawableCopyback(Render::Texture* tex, const Matrix2F& mvpIn, const Matrix2F& texgen)
{
    ScopedRenderEvent evt(GetEvent(Event_DICopyback), __FUNCTION__);
    ShaderInterface* psi = &ShaderData;
    setDrawableShader(psi, 1, MappedXY16iAlphaTexture[0]);
    ShaderInterfaceAccess::BeginPrimitive(psi);

    // shifted a pixel of the clip space: D3D9 samples pixel centers
    Matrix2F mvp = mvpIn;
    mvp.Tx() -= 1.0f / RenderTargetStack.Back().pRenderTarget->GetSize().Width;
    mvp.Ty() += 1.0f / RenderTargetStack.Back().pRenderTarget->GetSize().Height;
    const ShaderPair& cur = psi->GetCurrentShaders();
    psi->SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8);
    psi->SetUniform(cur, Uniform::SU_texgen, &texgen.M[0][0], 8);
    psi->SetTexture(cur, Uniform::SU_tex, tex, ImageFillMode());
    psi->Finish(1);
    drawScreenQuad();
}

// SDK form; the area Cxform is read with the Format byte loaded before operator*.
// @0x142737f70
void HAL::drawUncachedFilter(const FilterStackEntry& e)
{
    const FilterSet* filters     = e.pPrimitive->GetFilters();
    unsigned         filterCount = filters->GetFilterCount();
    const Filter*    filter      = 0;
    unsigned         pass = 0, passes = 0;

    // invalid primitive or render target
    if (!e.pPrimitive || !e.pRenderTarget)
        return;
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
        passes = SManager.GetFilterPasses(filter, DeviceFlags, shaders);

        // shadows and glows not hiding the object draw it over their result: keep the source
        bool requireSource = false;
        if (type >= Filter_Shadow && type <= Filter_Blur_End &&
            !(((const BlurFilterImpl*)filter)->GetParams().Mode & 0x40))
        {
            temporaries[2] = temporaries[0];
            requireSource  = true;
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

            RenderTarget*    prt      = temporaries[1];
            const Rect<int>& viewRect = prt->GetRect();
            const ImageSize& bs       = prt->GetBufferSize();
            VP       = Viewport(bs.Width, bs.Height, viewRect.x1, viewRect.y1, viewRect.Width(), viewRect.Height());
            ViewRect = Rect<int>(viewRect.x1, viewRect.y1, viewRect.x2, viewRect.y2);
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
    {
        const MatrixPoolImpl::HMatrix& area = e.pPrimitive->GetFilterAreaMatrix();
        MatrixPoolImpl::DataHeader*    header = area.pHandle->pHeader;
        // the exe keeps the Format byte read before operator* for the Cxform test and lookup
        typedef MatrixPoolImpl::HMatrixConstants HMC;
        const unsigned format = header->Format;
        Matrix2F       mvp = Matrices.UserView * *header->GetMatrixPtr();
        const Cxform&  cx  = (format & (1 << HMC::Element_Cxform))
            ? *reinterpret_cast<Cxform*>(header->GetDataStart()
                + HMC::MatrixElementSizeTable[format & HMC::Has_TableMask].Offsets[HMC::Element_Cxform] * MatrixPoolImpl::Pool_DataUnitSize)
            : Cxform::Identity;
        FUN_142734e10(&SManager, mvp, cx, filter, temporaries, shaders, pass, passes,
                      MappedXY16iAlphaTexture[0], &ShaderData);
    }
    applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, true, true);
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
    applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, false, (HALState & HS_InRenderTarget) != 0);
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

// @0x142737550
void HAL::drawCachedFilter(FilterPrimitive* primitive)
{
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);

    switch (primitive->GetCacheState())
    {
    case FilterPrimitive::Cache_PreTarget:
    {
        // one pass short of the result: draw the last pass into a new target, cache that, then draw it
        const FilterSet* filters = primitive->GetFilters();
        const Filter*    filter  = filters->GetFilter(filters->GetFilterCount() - 1);
        unsigned         shaders[8];
        unsigned         passes = SManager.GetFilterPasses(filter, DeviceFlags, shaders);

        Ptr<RenderTarget> temporaries[3];
        memset(temporaries, 0, sizeof temporaries);
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
        mvp.M[0][3] = -1.0f;
        mvp.M[1][0] = 0.0f;
        mvp.M[1][1] = -2.0f;
        mvp.M[1][2] = 0.0f;
        mvp.M[1][3] = 1.0f;
        const MatrixPoolImpl::HMatrix& area = primitive->GetFilterAreaMatrix();
        const Cxform* cx;
        if (!area.pHandle->HasElement(MatrixPoolImpl::HMatrixConstants::Element_Cxform))
            cx = &Cxform::Identity;
        else
            cx = area.pHandle->GetCxformPtr();
        mvp.Tx() -= 1.0f / size.Width;
        mvp.Ty() += 1.0f / size.Height;
        FUN_142734e10(&SManager, mvp, *cx, filter, temporaries, shaders, passes - 1, passes,
                      MappedXY16iAlphaTexture[0], &ShaderData);
        applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, true, true);
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
        break;
    }

    case FilterPrimitive::Cache_Target:
    {
        // Cache_Target: the result as a textured quad over the filtered area
        unsigned fillFlags = DeviceFlags;
        unsigned shader = 1 | ((fillFlags & 4) << 2);
        if (fillFlags & 1)
            shader += 1;
        if (fillFlags & 8)
            shader += 8;
        ShaderInterface* psi = &ShaderData;
        setDrawableShader(psi, shader, MappedXY16iAlphaTexture[0]);
        ShaderInterfaceAccess::BeginPrimitive(psi);
        const ShaderPair& pso = psi->GetCurrentShaders();

        RenderTarget* results;
        primitive->GetCacheResults(&results, 1);
        Render::Texture* ptexture = results->GetTexture();
        Matrix2F mvp = Matrices.UserView * primitive->GetFilterAreaMatrix().GetMatrix2D();

        // the result's rectangle within its texture
        const Rect<int>& srect = results->GetRect();
        Matrix2F texgen;
        texgen.AppendTranslation((float)srect.x1, (float)srect.y1);
        texgen.AppendScaling((float)srect.Width() / ptexture->ImgSize.Width, (float)srect.Height() / ptexture->ImgSize.Height);

        psi->SetUniform(pso, Uniform::SU_mvp, &mvp.M[0][0], 8);
        psi->SetUniform(pso, Uniform::SU_texgen, &texgen.M[0][0], 8);
        psi->SetTexture(pso, Uniform::SU_tex, ptexture, ImageFillMode(Wrap_Clamp, Sample_Linear));
        psi->Finish(1);

        applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, true, true);
        pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
        applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, false,
                       (HALState & HS_InRenderTarget) != 0);
        pTextureManager->SetSamplerState(0, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        pTextureManager->SetSamplerState(1, 0, D3DTEXF_POINT, D3DTADDRESS_CLAMP);
        results->SetInUse(false);
        break;
    }

    default:
        break;
    }
}

// SDK form; the frame rectangle reads the matrix through T& accessors (the SDK's const ones return const T&)
// @0x142732ec0
void HAL::PushFilters(FilterPrimitive* prim)
{
    GetEvent(Event_Filter).Begin(__FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        checkState_EmitWarnings(HS_InDisplay, __FUNCTION__);
        return;
    }

    FilterStackEntry e = { prim, 0 };

    // filters the profile cannot draw: the content draws unfiltered
    if (!shouldRenderFilters(prim))
    {
        FilterStack.PushBack(e);
        return;
    }

    if (!(HALState & HS_CachedFilter))
    {
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
            const Matrix2F& m = e.pPrimitive->GetFilterAreaMatrix().GetMatrix2D();
            e.pRenderTarget   = *CreateTempRenderTarget(ImageSize((UInt32)(SInt64)m.Sx(), (UInt32)(SInt64)m.Sy()),
                                                      prim->GetMaskPresent());
            // the SDK's const accessors return const T&
            Matrix2F& mr = const_cast<Matrix2F&>(m);
            RectF frameRect(mr.Tx(), mr.Ty(), mr.Tx() + mr.Sx(), mr.Ty() + mr.Sy());
            PushRenderTarget(frameRect, e.pRenderTarget);
            applyBlendMode(BlendModeStack.GetSize() >= 1 ? BlendModeStack.Back() : Blend_Normal, false, true);

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
    }
    // out of line here, inlined above; the exe keeps e in memory for this call
    ::FUN_142732e40(reinterpret_cast<FilterStackData*>(&FilterStack), e);
}

// written from the decompile
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

// @0x142736e50
void HAL::clearSolidRectangle(const Rect<int>& r, Color color)
{
    ScopedRenderEvent GPUEvent(GetEvent(Event_Clear), __FUNCTION__);
    color = Profiler.GetClearColor(color);
    if (color.GetAlpha() == 0xFF && !(VP.Flags & Viewport::View_Stereo_AnySplit))
    {
        // Do more efficient HW clear. Device::Clear expects render-target coordinates.
        D3DRECT  cr = { r.x1 + VP.Left, r.y1 + VP.Top,
                        r.x2 + VP.Left, r.y2 + VP.Top };
        D3DCOLOR d3dc = D3DCOLOR_XRGB(color.GetRed(), color.GetGreen(), color.GetBlue());
        pDevice->Clear(1, &cr, D3DCLEAR_TARGET, d3dc, 1.0f,  0);
    }
    else
    {
        float colorf[4];
        color.GetRGBAFloat(colorf, colorf+1, colorf+2, colorf+3);
        Matrix2F m((float)r.Width(), 0.0f, (float)r.x1,
            0.0f, (float)r.Height(), (float)r.y1);

        Matrix2F  mvp(m, Matrices.UserView);

        ShaderInterface* psi = &ShaderData;
        setDrawableShader(psi, 0x8003, MappedXY16iAlphaSolid[0]);
        ShaderInterfaceAccess::BeginPrimitive(psi);
        const ShaderPair& cur = psi->GetCurrentShaders();
        psi->SetUniform(cur, Uniform::SU_mvp, &mvp.M[0][0], 8);
        psi->SetUniformInline(cur, Uniform::SU_cxmul, colorf, 4);
        psi->Finish(1);

        setLinearStreamSource(PrimitiveBatch::DP_Batch);
        pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);
        pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
    }
}

// the SDK ShaderInterface::SetMatrix(sd, var, m1, HMatrix, Matrices, index, batch)
static __forceinline void DmcSetMatrix(ShaderInterface* psi, const ShaderPair& sd, const Matrix2F& m1,
                                       const MatrixPoolImpl::HMatrix& m2, const MatrixState* Matrices, unsigned batch)
{
    if (m2.Has3D())
    {
        Matrix3F t(Matrix3F::NoInit);
        t.MultiplyMatrix(m2.GetMatrix3D(), m1);
        Matrix4F m(Matrix4F::NoInit);
        m.MultiplyMatrix(Matrices->GetUVPO(), t);
        psi->SetUniform(sd, Uniform::SU_mvp, &m.M[0][0], 16, 0, batch);
    }
    else
    {
        Matrix2F m(Matrix2F::NoInit);
        m.SetToAppend(m1, m2.GetMatrix2D(), Matrices->UserView);
        psi->SetUniform(sd, Uniform::SU_mvp, &m.M[0][0], 8, 0, batch);
    }
}
// SDK form: the shader pair is read once and SetMatrix is the SDK inline
// @0x142737c40
void HAL::drawMaskClearRectangles(const MatrixPoolImpl::HMatrix* matrices, UPInt count)
{
    ScopedRenderEvent evt(GetEvent(Event_MaskClear), __FUNCTION__);
    ShaderInterface* psi = &ShaderData;
    setDrawableShader(psi, 0x8005, MappedXY16iAlphaSolid[PrimitiveBatch::DP_Batch]);
    ShaderInterfaceAccess::BeginPrimitive(psi);
    setLinearStreamSource(PrimitiveBatch::DP_Batch);
    pDevice->SetStreamSource(0, Cache.pMaskEraseBatchVertexBuffer.GetPtr(), 0, 8);

    // the erase buffer holds 30 quads
    const ShaderPair& pso = psi->GetCurrentShaders();
    unsigned drawRangeCount = 0;
    for (UPInt i = 0; i < count; i += (UPInt)drawRangeCount)
    {
        drawRangeCount = Alg::Min<unsigned>((unsigned)count - (unsigned)i, 30);
        for (unsigned j = 0; j < drawRangeCount; j++)
            DmcSetMatrix(psi, pso, Matrix2F::Identity, matrices[i + j], &Matrices, j);
        psi->Finish(drawRangeCount);
        pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, drawRangeCount * 2);
        AccumulatedStats.Meshes += drawRangeCount;
        AccumulatedStats.Triangles += drawRangeCount * 2;
        AccumulatedStats.Primitives++;
    }
}
// written from the decompile
// @0x142733240
void HAL::PushMask_BeginSubmit(MaskPrimitive* prim)
{
    ScopedRenderEvent evt(GetEvent(Event_Mask), __FUNCTION__);
    if (!(HALState & HS_InDisplay))
    {
        checkState_EmitWarnings(HS_InDisplay, __FUNCTION__);
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
    if (MaskStackTop && MaskStack.GetSize() > MaskStackTop && viewportValid && StencilAvailable && MultiBitStencil &&
        StencilOpInc != D3DSTENCILOP_REPLACE)
    {
        pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop);
        pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL);
        pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
        MaskPrimitive* old = MaskStack[MaskStackTop].pPrimitive;
        drawMaskClearRectangles(old->GetMaskAreaMatrices(), old->GetMaskCount());
    }

    FUN_142733ef0((MaskStackData*)&MaskStack, MaskStackTop + 1);
    MaskStackEntry& e  = MaskStack[MaskStackTop];
    e.pPrimitive       = prim;
    e.OldViewportValid = viewportValid;
    e.OldViewRect      = ViewRect;
    MaskStackTop++;

    HALState |= HS_DrawingMask;

    if (prim->IsClipped() && viewportValid)
    {
        // a clipped mask narrows the view to its bounds
        Rect<int> boundClip;
        if (!Matrices.OrientationSet)
        {
            // clipped matrices are in view space, unrotated
            const Matrix2F& m = prim->GetMaskAreaMatrices()[0].GetMatrix2D();
            boundClip = Rect<int>(VP.Left + (int)m.Tx(), VP.Top + (int)m.Ty(),
                                  VP.Left + (int)(m.Tx() + m.Sx()), VP.Top + (int)(m.Ty() + m.Sy()));
        }
        else
        {
            Matrix2F m = prim->GetMaskAreaMatrices()[0].GetMatrix2D();
            m.Append(Matrices.Orient2D);
            RectF rect = m.EncloseTransform(RectF(0, 0, 1, 1));
            boundClip = Rect<int>(VP.Left + (int)rect.x1, VP.Top + (int)rect.y1,
                                  VP.Left + (int)rect.x2, VP.Top + (int)rect.y2);
        }
        if (!ViewRect.IntersectRect(&ViewRect, boundClip))
        {
            ViewRect.Clear();
            HALState &= ~HS_ViewValid;
            viewportValid = false;
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
        if (StencilAvailable)
        {
            pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
            pDevice->SetRenderState(D3DRS_STENCILREF, 0);
            pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
            pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
            drawMaskClearRectangles(prim->GetMaskAreaMatrices(), prim->GetMaskCount());
            pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);   // the exe resets STENCILFAIL here and leaves STENCILZFAIL at REPLACE
        }
        else
        {
            UPInt maskCount = prim->GetMaskCount();
            for (UPInt i = 0; i < maskCount; i++)
            {
                const Matrix2F& m = prim->GetMaskAreaMatrices()[i].GetMatrix2D();
                RectF     bounds(m.EncloseTransform(RectF(0, 0, 1, 1)));
                Rect<int> boundClip((int)bounds.x1, (int)bounds.y1, (int)bounds.x2, (int)bounds.y2);
                boundClip.Offset(VP.Left, VP.Top);
                if (boundClip.IntersectRect(&boundClip, ViewRect))
                {
                    D3DRECT r = { boundClip.x1, boundClip.y1, boundClip.x2, boundClip.y2 };
                    pDevice->Clear(1, &r, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
                }
            }
        }
    }

    if (StencilAvailable)
    {
        bool canIncDec = (MultiBitStencil && (StencilOpInc != D3DSTENCILOP_REPLACE));
        if (canIncDec)
        {
            // inside the masks below, count one up
            pDevice->SetRenderState(D3DRS_STENCILREF, MaskStackTop - 1);
            pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
            pDevice->SetRenderState(D3DRS_STENCILPASS, StencilOpInc);
        }
        else if (MaskStackTop == 1)
        {
            // one stencil bit: only the first mask writes
            pDevice->SetRenderState(D3DRS_STENCILREF, 1);
            pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
            pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
        }
        else
            pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
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

}}} // namespace Scaleform::Render::D3D9
// the fe8 helpers below (defined after this function)
namespace SR = Scaleform::Render;
static __forceinline const SR::Cxform& SpfGetCxform(const SR::MatrixPoolImpl::HMatrix& m);
static __forceinline SR::Cxform SpfProfileCxform(const SR::Cxform& cx);
static __forceinline void SpfSetCxform(SR::D3D9::ShaderInterface* psi, const SR::D3D9::ShaderPair& sd,
                                       const SR::Cxform& cx, unsigned index, unsigned batch);
static __forceinline unsigned SpfGetPlaneCount(const SR::Texture* t);
static __forceinline Scaleform::UByte SpfGetTextureCount(const SR::PrimitiveFillData& d);
static __forceinline const SR::PrimitiveFillData& SpfData(const SR::PrimitiveFill* fill);
namespace Scaleform { namespace Render { namespace D3D9 {

// MS2-FUNCTIONAL: the SDK 4.1.19 body; left: register allocation (fillFlags in a register, fill-record pointer IV) and block order (the exe puts the loop tail before the instanced draw)
// @0x14272fcf0
void HAL::DrawProcessedComplexMeshes(ComplexMesh* complexMesh, const StrideArray<MatrixPoolImpl::HMatrix>& matrices)
{
    ScopedRenderEvent evt(GetEvent(Event_DrawComplex), __FUNCTION__);
    D3D9::MeshCacheItem* pmesh = (D3D9::MeshCacheItem*)complexMesh->pCacheMeshItem;
    if (!(HALState & HS_InDisplay))
    {
        checkState_EmitWarnings(HS_InDisplay, __FUNCTION__);
        return;
    }
    if (!pmesh)
        return;

    const ComplexMesh::FillRecord* fillRecords       = complexMesh->FillRecords.GetDataPtr();
    unsigned                       fillCount         = (unsigned)complexMesh->FillRecords.GetSize();
    unsigned                       instanceCount     = (unsigned)matrices.GetSize();
    PrimitiveBatch::BatchType      batchType         = PrimitiveBatch::DP_Single;
    unsigned                       formatIndex;
    unsigned                       maxDrawCount      = 1;
    unsigned                       vertexBaseIndex   = 0;
    unsigned                       vertexSize        = 0;
    unsigned                       indexBufferOffset = (unsigned)(pmesh->IBAllocOffset / sizeof(UInt16));

    if (instanceCount > 1 && SManager.HasInstancingSupport())
    {
        maxDrawCount = Alg::Min(instanceCount, Cache.GetParams().MaxBatchInstances);
        batchType    = PrimitiveBatch::DP_Instanced;
        formatIndex  = 1;
    }
    else
    {
        batchType   = PrimitiveBatch::DP_Single;
        formatIndex = 0;
        setLinearStreamSource(batchType);
    }

    const Matrix2F* textureMatrices = complexMesh->FillMatrixCache.GetDataPtr();
    pDevice->SetIndices(((IndexBuffer*)pmesh->pIndexBuffer)->pBuffer);
    for (unsigned fillIndex = 0; fillIndex < fillCount; fillIndex++)
    {
        const ComplexMesh::FillRecord& fr = fillRecords[fillIndex];

        unsigned fillFlags  = DeviceFlags;
        unsigned startIndex = 0;
        if (instanceCount > 0)
        {
            const MatrixPoolImpl::HMatrix& hm = matrices[0];
            fillFlags |= hm.Has3D() ? 8 : 0;

            for (unsigned i = 0; i < instanceCount; i++)
            {
                const MatrixPoolImpl::HMatrix& hm = matrices[startIndex + i];
                if (!(::SpfProfileCxform(::SpfGetCxform(hm)) == Cxform::Identity))
                    fillFlags |= 4;
            }
        }

        // Apply fill (the SDK StaticShaderManager::SetFill).
        PrimitiveFillType fillType = fr.pFill->GetType();
        unsigned (ShaderManager::*const sff)(PrimitiveFillType, unsigned&, unsigned) const = &ShaderManager::StaticShaderForFill;
        unsigned          shader   = (SManager.*sff)(fillType, fillFlags, batchType);   // out of line in the exe
        ShaderData.SetStaticShader((VertexShaderDesc::ShaderType)shader, (FragShaderDesc::ShaderType)shader,
                                   fr.pFormats[formatIndex]);
        ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
        const ShaderPair& pso = ShaderData.GetCurrentShaders();

        // Optimization: Modify stream source only when VertexSize changes.
        if (fr.pFormats[formatIndex]->Size != vertexSize)
        {
            vertexSize = fr.pFormats[formatIndex]->Size;
            pDevice->SetStreamSource(0, ((VertexBuffer*)pmesh->pVertexBuffer)->pBuffer,
                                     (UINT)(fr.VertexByteOffset + pmesh->VBAllocOffset), vertexSize);
            vertexBaseIndex = 0;
        }

        UByte textureCount = ::SpfGetTextureCount(::SpfData(fr.pFill));
        bool  solid = (fillType == PrimFill_None || fillType == PrimFill_Mask || fillType == PrimFill_SolidColor);

        for (unsigned i = 0; i < instanceCount; i++)
        {
            const MatrixPoolImpl::HMatrix& hm = matrices[startIndex + i];

            DmcSetMatrix(&ShaderData, pso, complexMesh->VertexMatrix, hm, &Matrices, i % maxDrawCount);
            if (solid)
                ShaderData.SetColor(pso, Uniform::SU_cxmul, fr.pFill->GetSolidColor(), 0, i % maxDrawCount);
            else if (fillFlags & 4)
                ::SpfSetCxform(&ShaderData, pso, ::SpfProfileCxform(::SpfGetCxform(hm)), 0, i % maxDrawCount);

            for (unsigned tm = 0, stage = 0; tm < textureCount; tm++)
            {
                ShaderData.SetUniform(pso, Uniform::SU_texgen, &textureMatrices[fr.FillMatrixIndex[tm]].M[0][0], 8,
                                      tm * 2, i % maxDrawCount);
                Render::Texture* ptex = fr.pFill->GetTexture(tm);
                ShaderData.SetTexture(pso, Uniform::SU_tex, ptex, fr.pFill->GetFillMode(tm), stage);
                stage += ::SpfGetPlaneCount(ptex);
            }

            bool lastPrimitive = (i == instanceCount - 1);
            if (batchType != PrimitiveBatch::DP_Instanced)
            {
                ShaderData.Finish(1);
                pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, vertexBaseIndex, 0, fr.VertexCount,
                                              fr.IndexOffset + indexBufferOffset, fr.IndexCount / 3);
                AccumulatedStats.Primitives++;
                if (!lastPrimitive)
                    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
            }
            else if (((i + 1) % maxDrawCount == 0 && i != 0) || lastPrimitive)
            {
                unsigned drawCount = maxDrawCount;
                if (lastPrimitive && (i + 1) % maxDrawCount != 0)
                    drawCount = (i + 1) % maxDrawCount;
                setInstancedStreamSource(drawCount);
                ShaderData.Finish(drawCount);
                pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, vertexBaseIndex, 0, fr.VertexCount,
                                              fr.IndexOffset + indexBufferOffset, fr.IndexCount / 3);
                AccumulatedStats.Primitives++;
                if (!lastPrimitive)
                    ShaderInterfaceAccess::BeginPrimitive(&ShaderData);
            }
        }
        AccumulatedStats.Meshes += instanceCount;
        AccumulatedStats.Triangles += (fr.IndexCount / 3) * instanceCount;
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
// written from the decompile
// @0x14272e5e0
void FUN_14272e5e0(RenderBuffer* p)
{
    p->RenderBuffer::~RenderBuffer();
}

template<class T> inline void Sfr01eDestroy(T& x) { x.~T(); }
// an ArrayLH's destruction written out (the exe inlines these three)
template<class A> inline void Sfr01eDestroyArray(A& a)
{
    A::AllocatorType::DestructArray(a.GetDataPtr(), a.GetSize());
    A::AllocatorType::Free(a.GetDataPtr());
}

// Render::HAL::~HAL (implicit), the base's member destruction the D3D9 dtor calls: the members in reverse
// declaration order, then the RefCountBase base
// @0x14272e730
void FUN_14272e730(Render::HAL* hal)
{
    Sfr01eDestroy(hal->BeginDisplayDataList);
    Sfr01eDestroyArray(hal->FilterStack);
    Sfr01eDestroyArray(hal->RenderTargetStack);
    Sfr01eDestroyArray(hal->MaskStack);
    Sfr01eDestroy(hal->BlendModeStack);
    Sfr01eDestroy(hal->ProjectionMatrix3DStack);
    Sfr01eDestroy(hal->ViewMatrix3DStack);
    Sfr01eDestroy(hal->QueueProcessor);
    Sfr01eDestroy(hal->pRenderBufferManager);
    Sfr01eDestroy(hal->Queue);
    hal->RefCountBase<Render::HAL, StatRender_Mem>::~RefCountBase();
}

// RenderBuffer::~RenderBuffer, a second copy
// written from the decompile
// @0x14272e8f0
void FUN_14272e8f0(RenderBuffer* p)
{
    p->RenderBuffer::~RenderBuffer();
}

void FUN_14015b310(void*, UPInt);   // sized operator delete (__empty_global_delete)

// a RefCountNTSImplCore deleting dtor
// written from the decompile
// @0x14272efd0
void* FUN_14272efd0(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            FUN_14015b310(p, 0x10);
    }
    return p;
}

// a RefCountNTSImplCore deleting dtor, a second copy
// written from the decompile
// @0x14272f030
void* FUN_14272f030(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            FUN_14015b310(p, 0x10);
    }
    return p;
}

// DepthStencilBuffer's deleting dtor
// written from the decompile
// @0x14272f090
void* FUN_14272f090(DepthStencilBuffer* p, unsigned flags)
{
    p->DepthStencilBuffer::~DepthStencilBuffer();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            FUN_14015b310(p, 0x30);
    }
    return p;
}

// ConstructorMov<RenderTargetEntry>::Construct: the render target stack's copy construction, member by member
// @0x14272f730
void FUN_14272f730(void* p, const Render::HAL::RenderTargetEntry& source)
{
    Render::HAL::RenderTargetEntry* d = (Render::HAL::RenderTargetEntry*)p;
    ::new (&d->pRenderTarget) Ptr<RenderTarget>(source.pRenderTarget);
    ::new (&d->OldMatrixState) MatrixState(source.OldMatrixState);
    ::new (&d->OldViewRect) Rect<int>(source.OldViewRect);
    ::new (&d->OldViewport) Viewport(source.OldViewport);
}

// Color::GetRGBAFloat, out of line
// @0x142732050
void FUN_142732050(const Color* c, float* r, float* g, float* b, float* a)
{
    *r = (c->Channels.Red   == 0) ? 0.0f : c->Channels.Red   / 255.0f;
    *g = (c->Channels.Green == 0) ? 0.0f : c->Channels.Green / 255.0f;
    *b = (c->Channels.Blue  == 0) ? 0.0f : c->Channels.Blue  / 255.0f;
    *a = (c->Channels.Alpha == 0) ? 0.0f : c->Channels.Alpha / 255.0f;
}

// FilterStack's ArrayDataBase::ResizeNoConstruct, out of line (Reserve stays a call)
// @0x142733fd0
SF_NOINLINE void FUN_142733fd0(FilterStackData* a, const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = a->Size;
    if (newSize < oldSize)
    {
        FilterStackData::AllocatorType::DestructArray(a->Data + newSize, oldSize - newSize);
        if (newSize < (a->Policy.GetCapacity() >> 1))
            a->Reserve(pheapAddr, newSize);
    }
    else if (newSize >= a->Policy.GetCapacity())
    {
        a->Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    a->Size = newSize;
}

// FilterStack's PushBack
// written from the decompile
// @0x142732e40
void FUN_142732e40(FilterStackData* a, const Render::HAL::FilterStackEntry& e)
{
    FUN_142733fd0(a, a, a->Size + 1);
    ::new (&a->Data[a->Size - 1]) Render::HAL::FilterStackEntry(e);
}

// MaskStack's ArrayData::Resize, out of line with ResizeNoConstruct inlined (Reserve stays a call)
// @0x142733ef0
void FUN_142733ef0(MaskStackData* a, UPInt newSize)
{
    UPInt oldSize = a->Size;
    if (newSize < oldSize)
    {
        MaskStackData::AllocatorType::DestructArray(a->Data + newSize, oldSize - newSize);
        if (newSize < (a->Policy.GetCapacity() >> 1))
            a->MaskStackData::BaseType::Reserve(a, newSize);
    }
    else if (newSize >= a->Policy.GetCapacity())
    {
        a->MaskStackData::BaseType::Reserve(a, newSize + (newSize >> 2));
    }
    a->Size = newSize;
    if (newSize > oldSize)
        MaskStackData::AllocatorType::ConstructArray(a->Data + oldSize, newSize - oldSize);
}

// the SDK PrimitiveFill::RequiresBlend
// (PrimitiveFill keeps its PrimitiveFillData private at +0x10; the SDK fill derives from it)
static __forceinline bool SpfRequiresBlend(const PrimitiveFillData& d)
{
    switch (d.Type)
    {
    case PrimFill_None:
    case PrimFill_Mask:
        return false;
    case PrimFill_SolidColor:
        return (d.SolidColor.GetAlpha() != 255);

    case PrimFill_Texture:
    case PrimFill_UVTexture:
    case PrimFill_2Texture:
        for (int i = 0; i < 2; i++)
            if (d.Textures[i])
                switch (d.Textures[i]->GetFormat())
                {
                case Image_R8G8B8:
                case Image_B8G8R8:
                case Image_PVRTC_RGB_2BPP:
                case Image_PVRTC_RGB_4BPP:
                case Image_ATCIC:
                case Image_Y8_U2_V2:
                    break;
                default:
                    return true;
                }
        return false;

    default:
        return true;
    }
}
// the SDK HMatrix::GetCxform / GetTextureMatrix
static __forceinline const Cxform& SpfGetCxform(const MatrixPoolImpl::HMatrix& m)
{
    typedef MatrixPoolImpl::HMatrixConstants HC;
    return !m.pHandle->pHeader->HasElement(HC::Element_Cxform) ? Cxform::Identity : *m.pHandle->pHeader->GetCxformPtr();
}
static __forceinline const Matrix2F& SpfGetTextureMatrix(const MatrixPoolImpl::HMatrix& m, unsigned index)
{
    typedef MatrixPoolImpl::HMatrixConstants HC;
    HC::ElementIndex e = (HC::ElementIndex)(HC::Element_T0 + index);
    return !m.pHandle->pHeader->HasElement(e) ? Matrix2F::Identity : *m.pHandle->pHeader->GetTextureMatrixPtr(e);
}
// the SDK Texture::GetPlaneCount
static __forceinline unsigned SpfGetPlaneCount(const Render::Texture* t)
{
    return ImageData::GetFormatPlaneCount((ImageFormat)t->GetFormat()) * t->GetMipmapCount();
}
// the SDK PrimitiveFillData::GetTextureCount
static __forceinline UByte SpfGetTextureCount(const PrimitiveFillData& d)
{
    if ((d.Type >= PrimFill_Texture) && (d.Type <= PrimFill_2Texture_EAlpha))
        return (d.Type >= PrimFill_2Texture) ? 2 : 1;
    return 0;
}
// PrimitiveFill::GetData (the fill's PrimitiveFillData is private at +0x10)
static __forceinline const PrimitiveFillData& SpfData(const PrimitiveFill* fill)
{
    return *(const PrimitiveFillData*)((const char*)fill + 0x10);
}
// the SDK StaticShaderManager::StaticShaderForFill(PrimitiveFill*, ...)
static __forceinline unsigned SpfStaticShaderForFill(D3D9::ShaderManager* sm, PrimitiveFill* pfill, unsigned& fillflags,
                                                     unsigned batchType)
{
    switch (pfill->GetType())
    {
    case PrimFill_Texture:
    case PrimFill_Texture_EAlpha:
        if (SpfGetTextureCount(SpfData(pfill)) == 1 &&
            ImageData::GetFormatPlaneCount((ImageFormat)pfill->GetTexture(0)->GetFormat()) >= 3)
        {
            unsigned shader = pfill->GetType() == PrimFill_Texture_EAlpha ? 0xa025 : 0xa005;

            if (ImageData::GetFormatPlaneCount((ImageFormat)pfill->GetTexture(0)->GetFormat()) == 4)
                shader += 0x100;

            if (fillflags & 4)
                shader += 0x10;

            switch (batchType)
            {
            case PrimitiveBatch::DP_Batch:
                shader += 2;
                break;

            case PrimitiveBatch::DP_Instanced:
                shader += 4;
                break;
            default: break;
            }

            if (fillflags & 1)
                shader += 1;

            if (fillflags & 8)
                shader += 8;

            return shader;
        }
        break;

    default: break;
    }
    return sm->StaticShaderForFill(pfill->GetType(), fillflags, batchType);
}
// ProfileViews::GetCxform (this build returns the cxform unchanged, by value)
static __forceinline Cxform SpfProfileCxform(const Cxform& cx)
{
    return cx;
}
// the SDK ShaderInterface::SetCxform
static __forceinline void SpfSetCxform(D3D9::ShaderInterface* psi, const D3D9::ShaderPair& sd, const Cxform& cx,
                                       unsigned index = 0, unsigned batch = 0)
{
    const float(*rows)[4] = &cx.M[0];
    psi->SetUniform(sd, D3D9::Uniform::SU_cxmul, rows[0], 4, index, batch);
    psi->SetUniform(sd, D3D9::Uniform::SU_cxadd, rows[1], 4, index, batch);
}
// the SDK ShaderInterfaceBase::GetParameterStage
static __forceinline unsigned SpfGetParameterStage(const D3D9::ShaderPair& sd, unsigned var, int index = 0)
{
    if (sd->pVDesc->BatchUniforms[var].Offset >= 0 && index < sd->pVDesc->BatchUniforms[var].Size)
        return 0x10000 | sd->pVDesc->BatchUniforms[var].Size;
    else if (sd->pVDesc->Uniforms[var].Location >= 0 && index < sd->pVDesc->Uniforms[var].Size)
        return 0x10000 | sd->pVDesc->Uniforms[var].Size / sd->pVDesc->Uniforms[var].ElementSize;
    else if (sd->pFDesc->BatchUniforms[var].Offset >= 0 && index < sd->pFDesc->BatchUniforms[var].Size)
        return 0x20000 | sd->pFDesc->BatchUniforms[var].Size;
    else if (sd->pFDesc->Uniforms[var].Location >= 0 && index < sd->pFDesc->Uniforms[var].Size)
        return 0x20000 | sd->pFDesc->Uniforms[var].Size / sd->pVDesc->Uniforms[var].ElementSize;
    else
        return 0;
}
// StaticShaderManager::SetPrimitiveFill: picks the shader of a batch and sets its meshes' uniforms
// SDK 4.1.19 form (this build has no Profiler)
// @0x1427359d0
const D3D9::ShaderPair* FUN_1427359d0(D3D9::ShaderManager* sm, PrimitiveFill* pfill, unsigned* pfillFlags,
                                      unsigned batchType, const VertexFormat* pvf, unsigned meshCount,
                                      MatrixState* Matrices, const Primitive::MeshEntry* pmeshes,
                                      D3D9::ShaderInterface* psi)
{
    unsigned& fillFlags = *pfillFlags;
    PrimitiveFillType fillType = pfill->GetType();

    if ((fillFlags & 0x10) == 0 && SpfRequiresBlend(SpfData(pfill)))
        fillFlags |= 0x10;

    for (unsigned i = 0; i < meshCount; i++)
    {
        Cxform finalCx = SpfProfileCxform(SpfGetCxform(pmeshes[i].M));
        if (!(finalCx == Cxform::Identity))
        {
            fillFlags |= 4;
            if (finalCx.M[0][3] < 1.0f)
                fillFlags |= 0x10;
            break;
        }
    }

    unsigned shader = SpfStaticShaderForFill(sm, pfill, fillFlags, batchType);

    psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)shader, (D3D9::FragShaderDesc::ShaderType)shader, pvf);
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    const D3D9::ShaderPair& pso = psi->GetCurrentShaders();
    bool solid = (fillType == PrimFill_None || fillType == PrimFill_Mask || fillType == PrimFill_SolidColor);

    if (solid)
        psi->SetColor(pso, D3D9::Uniform::SU_cxmul, pfill->GetSolidColor());
    else if (fillType >= PrimFill_Texture)
    {
        Render::Texture* pt0 = pfill->GetTexture(0);
        ImageFillMode    fm0 = pfill->GetFillMode(0);

        psi->SetTexture(pso, D3D9::Uniform::SU_tex, pt0, fm0);
        if ((fillType == PrimFill_2Texture) || (fillType == PrimFill_2Texture_EAlpha))
        {
            Render::Texture* pt1 = pfill->GetTexture(1);
            ImageFillMode    fm1 = pfill->GetFillMode(1);

            psi->SetTexture(pso, D3D9::Uniform::SU_tex, pt1, fm1, SpfGetPlaneCount(pt0));
        }
    }

    if (fillType == PrimFill_UVTextureDFAlpha_VColor)
    {
        for (unsigned i = 0; i < meshCount; i++)
        {
            psi->SetUserUniforms(pso, pmeshes[i].M, i);
        }
    }

    unsigned tmCount = (SpfGetParameterStage(pso, D3D9::Uniform::SU_texgen) & 0xffff) >> 1;

    for (unsigned i = 0; i < meshCount; i++)
    {
        DmcSetMatrix(psi, pso, pmeshes[i].pMesh->VertexMatrix, pmeshes[i].M, Matrices, i);

        if (fillType == PrimFill_Mask)
            psi->SetColor(pso, D3D9::Uniform::SU_cxmul, Color(128, 0, 0, 128));
        else if (fillFlags & 4)
            SpfSetCxform(psi, pso, SpfProfileCxform(SpfGetCxform(pmeshes[i].M)), 0, i);

        for (unsigned tm = 0; tm < tmCount; tm++)
        {
            Matrix2F m(pmeshes[i].pMesh->VertexMatrix);
            m.Append(SpfGetTextureMatrix(pmeshes[i].M, tm));
            const float* rows = &m.M[0][0];
            psi->SetUniform(pso, D3D9::Uniform::SU_texgen, rows, 8, tm * 2, i);
        }
    }

    if (!(fillFlags & 0x20))
        psi->Finish(meshCount);

    return &pso;
}

#pragma strict_gs_check(push, on)
// the SDK ShaderInterface::SetMatrix(sd, var, m, index, batch)
static __forceinline void DfSetMatrix(D3D9::ShaderInterface* psi, const D3D9::ShaderPair& sd, unsigned var,
                                      const Matrix2F& m, unsigned index = 0, unsigned batch = 0)
{
    const float* rows = &m.M[0][0];
    psi->SetUniform(sd, var, rows, 8, index * 2, batch);
}
// StaticShaderManager::DrawableFinish: the uniforms every drawable shader takes, then the upload
// SDK form (SetMatrix, Tx()/Ty()); the exe's /GS cookie over mvp comes from strict_gs_check
// @0x142731310
bool FUN_142731310(D3D9::ShaderManager* sm, unsigned srcCount, Render::Texture** tex, const Matrix2F* texgen,
                   Size<int> texsize, const Matrix2F& mvpIn, D3D9::ShaderInterface* psi, unsigned flags)
{
    SF_UNUSED(sm);
    const D3D9::ShaderPair& pso = psi->GetCurrentShaders();
    Matrix2F mvp(mvpIn);
    // bit 1: the viewport is upside down
    if (flags & 2)
    {
        mvp.PrependTranslation(0.0f, 1.0f);
        mvp.PrependScaling(1.0f, -1.0f);
    }
    // bit 0: a pixel's offset (D3D9 samples pixel centers)
    if (flags & 1)
    {
        mvp.Tx() -= 1.0f / texsize.Width;
        mvp.Ty() += 1.0f / texsize.Height;
    }
    DfSetMatrix(psi, pso, D3D9::Uniform::SU_mvp, mvp);
    for (unsigned i = 0; i < srcCount; i++)
    {
        psi->SetTexture(pso, D3D9::Uniform::SU_tex, tex[i],
                        ImageFillMode(Wrap_Clamp, Sample_Point), i);
        DfSetMatrix(psi, pso, D3D9::Uniform::SU_texgen, texgen[i], i);
    }
    psi->Finish(1);
    return true;
}

#pragma strict_gs_check(pop)

// StaticShaderManager::SetDrawableMergeFill
// written from the decompile
// @0x142734410
bool FUN_142734410(D3D9::ShaderManager* sm, Render::Texture** tex, const Matrix2F* texgen, Size<int> texsize,
                   const Matrix4F* cxmul, const VertexFormat* format, D3D9::ShaderInterface* psi, unsigned flags)
{
    if (!psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)0x1a64f, (D3D9::FragShaderDesc::ShaderType)0x1a64f,
                              format))
        return false;
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    for (int i = 0; i < 2; i++)
        psi->SetUniformInline(psi->GetCurrentShaders(), D3D9::Uniform::SU_cxmul, &cxmul[i].M[0][0], 16, i);
    Matrix2F mvp;
    mvp.M[0][0] = 2.0f; mvp.M[0][1] = 0.0f;  mvp.M[0][2] = 0.0f; mvp.M[0][3] = -1.0f;
    mvp.M[1][0] = 0.0f; mvp.M[1][1] = -2.0f; mvp.M[1][2] = 0.0f; mvp.M[1][3] = 1.0f;
    return FUN_142731310(sm, 2, tex, texgen, texsize, mvp, psi, flags);
}

// StaticShaderManager::SetDrawableThreshold: the comparison picks the shader variant
// SDK form (Render_Shader.h, the #else body)
// @0x142734790
bool FUN_142734790(D3D9::ShaderManager* sm, Render::Texture** tex, const Matrix2F* texgen, Size<int> texsize,
                   const Matrix2F& mvp, int op, UInt32 threshold, UInt32 color, UInt32 mask, bool copySource,
                   const VertexFormat* format, D3D9::ShaderInterface* psi, unsigned flags)
{
    unsigned shader = 0x1a64d;
    if (copySource)
    {
        shader += 0x40;
        shader += 9;
    }
    else
        shader += 8;
    switch (op)
    {
    case 0: shader += 0; break;
    case 1: shader += 0x20; break;
    case 2: shader += 0x10; break;
    case 3: shader += 8; break;
    case 4: shader += 4; break;
    case 5: shader += 2; break;
    }
    if (!psi->SetStaticShader((D3D9::VertexShaderDesc::ShaderType)shader, (D3D9::FragShaderDesc::ShaderType)shader,
                              format))
        return false;
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    const D3D9::ShaderPair& pso = psi->GetCurrentShaders();

    Color maskedThreshold = threshold & mask;
    float rgba[4];
    maskedThreshold.GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniformInline(pso, D3D9::Uniform::SU_threshold, rgba, 4);
    Color maskC = mask;
    maskC.GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniformInline(pso, D3D9::Uniform::SU_mask, rgba, 4);
    Color col = color;
    col.GetRGBAFloat(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
    psi->SetUniformInline(pso, D3D9::Uniform::SU_color, rgba, 4);
    return FUN_142731310(sm, copySource ? 2 : 1, tex, texgen, texsize, mvp, psi, flags);
}

// ShaderInterfaceBase::SetUniform0 as a forceinline copy: with the header's member (inlined on its own) cl puts the
// pVDesc batch branch's UniformSet store as [index+this]; this copy gives the exe's [this+index] in SetFilterFill
struct SffSI : D3D9::ShaderInterface
{
    static __forceinline void SetU0(SffSI* psi, const D3D9::ShaderPair& sd, unsigned var, const float* v, unsigned n,
                                    unsigned index)
    {
        if (sd->pVDesc->Uniforms[var].Size)
            memcpy(psi->UniformData + sd->pVDesc->Uniforms[var].ShadowOffset +
                       sd->pVDesc->Uniforms[var].ElementSize * index,
                   v, n * sizeof(float));
        if (sd->pFDesc->Uniforms[var].Size)
            memcpy(psi->UniformData + sd->pFDesc->Uniforms[var].ShadowOffset +
                       sd->pFDesc->Uniforms[var].ElementSize * index,
                   v, n * sizeof(float));
        psi->UniformSet[var] = true;
    }
};

// the SDK ShaderInterfaceBase::SetUniform body inlined: SetUniform0 takes the desc's Array, not the bvar local
static __forceinline void SffSetUniform(D3D9::ShaderInterface* psi, const D3D9::ShaderPair& sd, unsigned var,
                                        const float* v, unsigned n, unsigned index = 0, unsigned batch = 0)
{
    if (sd->pVDesc->BatchUniforms[var].Offset >= 0)
    {
        unsigned bvar = sd->pVDesc->BatchUniforms[var].Array;
        SffSI::SetU0((SffSI*)psi, sd, sd->pVDesc->BatchUniforms[var].Array, v, n,
                     batch * sd->pVDesc->Uniforms[bvar].BatchSize + sd->pVDesc->BatchUniforms[var].Offset + index);
    }
    else if (sd->pFDesc->BatchUniforms[var].Offset >= 0)
    {
        unsigned bvar = sd->pFDesc->BatchUniforms[var].Array;
        psi->SetUniform0(sd, sd->pFDesc->BatchUniforms[var].Array, v, n,
                         batch * sd->pFDesc->Uniforms[bvar].BatchSize + sd->pFDesc->BatchUniforms[var].Offset + index);
    }
    else
        psi->SetUniform0(sd, var, v, n, index, batch);
}

// StaticShaderManager::SetFilterFill: the SDK body. The first target is the texture to be filtered; a blur pass takes
// its kernel size, a shadow pass its colors, offset and the source, a color matrix its matrix with the cxform folded in
// @0x142734e10
bool FUN_142734e10(D3D9::ShaderManager* sm, const Matrix2F& mvp, const Cxform& cx, const Filter* filter,
                   Ptr<RenderTarget>* targets, unsigned* shaders, unsigned pass, unsigned passCount,
                   const VertexFormat* format, D3D9::ShaderInterface* psi)
{
    SF_UNUSED(sm);
    // D3D9 VShaderForFShader is the identity
    D3D9::VertexShaderDesc::ShaderType vshader = (D3D9::VertexShaderDesc::ShaderType)shaders[pass];

    if (!psi->SetStaticShader(vshader, (D3D9::FragShaderDesc::ShaderType)shaders[pass], format))
        return false;
    D3D9::ShaderInterfaceAccess::BeginPrimitive(psi);
    const D3D9::ShaderPair& pso = psi->GetCurrentShaders();

    // Apply the mvp
    DfSetMatrix(psi, pso, D3D9::Uniform::SU_mvp, mvp);

    // Apply the source texture (FS_start_shadows .. FS_end_shadows).
    bool             shadowPass = shaders[pass] >= 0xa64b && shaders[pass] <= 0xa64b + 0x4501;
    Render::Texture* ptexture   = targets[0]->GetTexture();
    psi->SetTexture(pso, D3D9::Uniform::SU_tex, ptexture, ImageFillMode(Wrap_Clamp, Sample_Linear));

    // Apply the texture matrix.
    Matrix2F         texgen;
    const Rect<int>& srect = targets[0]->GetRect();
    texgen.AppendTranslation((float)srect.x1, (float)srect.y1);
    texgen.AppendScaling((float)srect.Width() / ptexture->GetSize().Width,
                         (float)srect.Height() / ptexture->GetSize().Height);
    psi->SetUniform(pso, D3D9::Uniform::SU_texgen, &(texgen.M[0][0]), 8);

    // Apply the remainder of the uniforms.
    if (filter->GetFilterType() <= Filter_Blur_End)
    {
        const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();

        // Common parameters.
        psi->SetCxform(pso, cx);

        float texscale[2];
        texscale[0] = 1.0f / ptexture->GetSize().Width;
        texscale[1] = 1.0f / ptexture->GetSize().Height;

        float fsize[4];
        float blurx = Alg::Max(1.0f, floorf(TwipsToPixels(params.BlurX)));
        float blury = Alg::Max(1.0f, floorf(TwipsToPixels(params.BlurY)));
        // FS_FBox1Blur, FS_FBox1BlurMul
        if (shaders[pass] == 0xa249 || shaders[pass] == 0xa24a)
        {
            // On even passes, do the X blur, on odd passes, do the Y blur.
            if ((pass & 1) == 0)
            {
                fsize[0]    = (blurx - 1) * 0.5f;
                fsize[1]    = 0;
                fsize[3]    = 1.0f / (blurx);
                texscale[1] = 0;
            }
            else
            {
                fsize[0]    = (blury - 1) * 0.5f;
                fsize[1]    = 0;
                fsize[3]    = 1.0f / (blury);
                texscale[0] = 0;
            }
        }
        else if (pass == passCount - 1 && pass != 0)
        {
            fsize[0] = 0.0f;
            fsize[1] = (blury - 1) * 0.5f;
            fsize[3] = 1.0f / (blury);
        }
        else
        {
            fsize[0] = (blurx - 1) * 0.5f;
            fsize[1] = (blury - 1) * 0.5f;
            fsize[3] = 1.0f / (blurx * blury);
        }

        // fsize.z = strength, only used on the last pass.
        fsize[2] = (pass == passCount - 1) ? params.Strength : 1.0f;

        SffSetUniform(psi, pso, D3D9::Uniform::SU_fsize, fsize, 4);
        SffSetUniform(psi, pso, D3D9::Uniform::SU_texscale, texscale, 2);

        if (shadowPass)
        {
            float scolors[2][4];
            float srctexscale[2];
            float offset[2];
            params.Colors[0].GetRGBAFloat(&scolors[0][0], &scolors[0][1], &scolors[0][2], &scolors[0][3]);
            params.Colors[1].GetRGBAFloat(&scolors[1][0], &scolors[1][1], &scolors[1][2], &scolors[1][3]);
            offset[0] = -TwipsToPixels(params.Offset.x);
            offset[1] = -TwipsToPixels(params.Offset.y);

            if (!(params.Mode & BlurFilterParams::Mode_HideObject && !(params.Mode & BlurFilterParams::Mode_Knockout)) &&
                targets[2])
            {
                Render::Texture* psrctex = targets[2]->GetTexture();
                srctexscale[0]           = 1.0f / (psrctex->GetSize().Width * texscale[0]);
                srctexscale[1]           = 1.0f / (psrctex->GetSize().Height * texscale[1]);
                psi->SetUniform(pso, D3D9::Uniform::SU_srctexscale, srctexscale, 2);
                psi->SetTexture(pso, D3D9::Uniform::SU_srctex, psrctex, ImageFillMode(Wrap_Clamp, Sample_Linear));
            }

            psi->SetUniform(pso, D3D9::Uniform::SU_scolor, scolors[0], 4);
            SffSetUniform(psi, pso, D3D9::Uniform::SU_offset, offset, 2);

            if (params.Mode & BlurFilterParams::Mode_Highlight)
                psi->SetUniform(pso, D3D9::Uniform::SU_scolor2, scolors[1], 4);
        }
    }
    else
    {
        ColorMatrixFilter& matrixFilter = *(ColorMatrixFilter*)filter;

        // If there is a color transform, in addition to the filter, embed that directly into the matrix.
        float matrixData[20];
        memcpy(matrixData, &matrixFilter[0], sizeof(matrixData));
        for (unsigned i = 0; i < 5; i++)
        {
            matrixData[i * 4 + 0] = matrixData[i * 4 + 0] * cx.M[0][0] * cx.M[0][3];
            matrixData[i * 4 + 1] = matrixData[i * 4 + 1] * cx.M[0][1] * cx.M[0][3];
            matrixData[i * 4 + 2] = matrixData[i * 4 + 2] * cx.M[0][2] * cx.M[0][3];
            matrixData[i * 4 + 3] = matrixData[i * 4 + 3] * cx.M[0][3];
        }
        matrixData[16] = (matrixData[16] + cx.M[1][0] * 1.f / 255.f) * cx.M[0][3];
        matrixData[17] = (matrixData[17] + cx.M[1][1] * 1.f / 255.f) * cx.M[0][3];
        matrixData[18] = (matrixData[18] + cx.M[1][2] * 1.f / 255.f) * cx.M[0][3];
        matrixData[19] = (matrixData[19] + cx.M[1][3] * 1.f / 255.f) * cx.M[0][3];

        // Now apply the data.
        psi->SetUniform(pso, D3D9::Uniform::SU_cxadd, &(matrixData[16]), 4);
        psi->SetUniform(pso, D3D9::Uniform::SU_cxmul, &(matrixData[0]), 16);
    }

    psi->Finish(0);

    return true;
}


// MS2-PIN: ??0HAL@D3D9@Render@Scaleform@@QEAA@PEAVThreadCommandQueue@23@@Z 0x14272dc10
// MS2-PIN: ?GetFilterPasses@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEBAIPEBVFilter@23@IPEAI@Z 0x142731f10
// MS2-PIN: ?GetVertexFormat@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEAAPEBUVertexFormat@23@PEAUVertexElement@23@III@Z 0x142732130
// MS2-PIN: ?MapVertexFormat@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEAAXW4PrimitiveFillType@23@PEBUVertexFormat@23@PEAPEBU523@22I@Z 0x142732210
// MS2-PIN: ?StaticShaderForFill@?$StaticShaderManager@UFragShaderDesc@D3D9@Render@Scaleform@@UVertexShaderDesc@234@UUniform@234@VShaderInterface@234@VTexture@234@@Render@Scaleform@@QEBAIW4PrimitiveFillType@23@AEAII@Z 0x142736880
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
// MS2-PIN: ??_7DepthStencilBuffer@Render@Scaleform@@6B@ 0x14319d730
// MS2-PIN: ??__Fevents@?1??GetEvent@HAL@D3D9@Render@Scaleform@@UEAAAEAVRenderEvent@34@W4EventType@34@@Z@YAXXZ 0x142cc9910
