// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 HAL setup TU
// (D3D9_HALSetup): device state at scene begin / end, HAL init / shutdown, the device-reset pair, the HAL event
// notification and the viewport upload.
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01f D3D9_HALSetup).
// MS2-UNIT: sfr_d3d9_01f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142741af0-0x142742830 .text$mn


#include <d3d9.h>
#include "ms2/scaleform/include/render/d3d9_hal.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/render_buffergeneric.h"
#include "ms2/scaleform/include/render/render_vertex.h"
#include "ms2/scaleform/include/render/render_events.h"

namespace Scaleform { namespace Render { namespace D3D9 {

// @0x142741af0
bool HAL::BeginScene()
{
    if (!Render::HAL::BeginScene())
        return false;

    ScopedRenderEvent evt(GetEvent(Event_BeginScene), "Scaleform::Render::D3D9::HAL::BeginScene-SetState");

    pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

    // a slight negative bias keeps scaled-down text sharp
    union
    {
        float fbias;
        DWORD d;
    } bias;
    bias.fbias = -0.75f;

    pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

    pDevice->SetSamplerState(0, D3DSAMP_MIPMAPLODBIAS, bias.d);
    pDevice->SetSamplerState(0, D3DSAMP_ELEMENTINDEX, 0);
    pDevice->SetSamplerState(1, D3DSAMP_ELEMENTINDEX, 0);

    for (unsigned i = 0; i < 8; i++)
        pDevice->SetTextureStageState(i, D3DTSS_TEXCOORDINDEX, i);
    pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DISABLE);

    pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
    pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN | D3DCOLORWRITEENABLE_BLUE |
                                                    D3DCOLORWRITEENABLE_ALPHA);
    pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
    pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

    // the device's BeginScene is the application's when it owns the scene
    if (!(VMCFlags & 1))
        pDevice->BeginScene();

    SManager.BeginScene();
    ShaderData.BeginScene();
    return true;
}

// @0x142741d60
void HAL::CalcHWViewMatrix(Matrix2F* matrix, const Rect<int>& viewRect, int dx, int dy)
{
    float vpWidth  = (float)viewRect.Width();
    float vpHeight = (float)viewRect.Height();

    // half a pixel in clip space
    float xhalfPixelAdjust = (viewRect.Width() > 0) ? (1.0f / vpWidth) : 0.0f;
    float yhalfPixelAdjust = (viewRect.Height() > 0) ? (1.0f / vpHeight) : 0.0f;

    matrix->SetIdentity();
    matrix->Sx() = 2.0f / vpWidth;
    matrix->Sy() = -2.0f / vpHeight;
    matrix->Tx() = -1.0f - matrix->Sx() * ((float)dx) - xhalfPixelAdjust;
    matrix->Ty() = 1.0f - matrix->Sy() * ((float)dy) + yhalfPixelAdjust;
}

// @0x142741e10
bool HAL::EndScene()
{
    if (!Render::HAL::EndScene())
        return false;

    SManager.EndScene();

    // instancing leaves the stream frequencies set
    pDevice->SetStreamSourceFreq(0, 1);
    pDevice->SetStreamSourceFreq(1, 1);
    PrevBatchType = PrimitiveBatch::DP_None;

    if (!(VMCFlags & 1))
        pDevice->EndScene();
    return true;
}

// @0x142741e90
bool HAL::InitHAL(const D3D9::HALInitParams& params)
{
    ScopedRenderEvent evt(GetEvent(Event_InitHAL), "Scaleform::Render::D3D9::HAL::InitHAL");

    if (!initHAL(params))
        return false;
    if (!params.pD3DDevice)
        return false;

    pDevice = params.pD3DDevice;
    pDevice->AddRef();

    D3DCAPS9 caps;
    D3DDEVICE_CREATION_PARAMETERS cparams;
    pDevice->GetDeviceCaps(&caps);
    pDevice->GetCreationParameters(&cparams);

    // ConfigFlags bit 4 asks for static mesh buffers
    if (!Cache.Initialize(pDevice, !(params.ConfigFlags & 0x10)) ||
        !SManager.Initialize(this))
    {
        ShutdownHAL();
        return false;
    }

    if (params.pTextureManager)
        pTextureManager = (D3D9::TextureManager*)params.pTextureManager;
    else
    {
        // the SDK D3DCapFlags::InitFromHWCaps
        D3DCapFlags ourCaps;
        ourCaps.Flags = 0;
        if (!(caps.TextureCaps & D3DPTEXTURECAPS_POW2))
        {
            ourCaps.Flags |= D3DCapFlags::Cap_NonPow2Tex;
            if (!(caps.TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL))
                ourCaps.Flags |= D3DCapFlags::Cap_NonPow2TexWrap;
        }
        else if (caps.TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL)
        {
            ourCaps.Flags |= D3DCapFlags::Cap_NonPow2Tex;
        }
        if (cparams.BehaviorFlags & D3DCREATE_MULTITHREADED)
        {
            ourCaps.Flags |= D3DCapFlags::Cap_MultiThreaded;
        }
        if (caps.Caps2 & D3DCAPS2_DYNAMICTEXTURES)
        {
            ourCaps.Flags |= D3DCapFlags::Cap_DynamicTex;
        }

        IDirect3DDevice9Ex* d3d9exPtr;
        if (SUCCEEDED(pDevice->QueryInterface(IID_IDirect3DDevice9Ex, (void**)&d3d9exPtr)) && d3d9exPtr)
        {
            d3d9exPtr->Release();
            ourCaps.Flags |= D3DCapFlags::Cap_D3D9Ex;
        }

        pTextureManager =
            *SF_HEAP_AUTO_NEW(this) TextureManager(pDevice, ourCaps,
                                                   params.RenderThreadId, pRTCommandQueue);
        if (!pTextureManager)
        {
            ShutdownHAL();
            return false;
        }
    }

    // the SDK's params field is a Ptr<RenderBufferManager>: assigned as a Ptr, it is read again after the Release
    if (params.pRenderBufferManager)
        pRenderBufferManager = reinterpret_cast<const Ptr<RenderBufferManager>&>(params.pRenderBufferManager);
    else
    {
        pRenderBufferManager = *SF_HEAP_AUTO_NEW(this) RenderBufferManagerGeneric(false, RBGenericImpl::RenderBufferManager::ReuseLimit_ScreenSize, 0);
        if (!pRenderBufferManager || !createDefaultRenderBuffer())
        {
            ShutdownHAL();
            return false;
        }
    }

    if (!initializeShaders(false))
    {
        ShutdownHAL();
        return false;
    }

    if (caps.StencilCaps & D3DSTENCILCAPS_INCR)
    {
        StencilOpInc = D3DSTENCILOP_INCR;
    }
    else if (caps.StencilCaps & D3DSTENCILCAPS_INCRSAT)
    {
        StencilOpInc = D3DSTENCILOP_INCRSAT;
    }
    else
    {
        StencilOpInc = D3DSTENCILOP_REPLACE;
    }

    MapVertexFormat(PrimFill_Texture, &VertexXY16iAlpha::Format, &MappedXY16iAlphaTexture[0],
                    &MappedXY16iAlphaTexture[1], &MappedXY16iAlphaTexture[2], 0);
    MapVertexFormat(PrimFill_SolidColor, &VertexXY16iAlpha::Format, &MappedXY16iAlphaSolid[0],
                    &MappedXY16iAlphaSolid[1], &MappedXY16iAlphaSolid[2], 0);

    memcpy(&PresentParams, &params.PresentParams, sizeof(D3DPRESENT_PARAMETERS));
    HALState |= HS_ModeSet;
    notifyHandlers(HAL_Initialize);
    return true;
}

// @0x1427422c0
void HAL::PrepareForReset()
{
    if (HALState & HS_ReadyForReset)
        return;

    HALNotify* p = NotifyList.GetFirst();
    while (!NotifyList.IsNull(p))
    {
        HALNotify* next = p->pNext;
        p->OnHALEvent(HAL_PrepareForReset);
        p = next;
    }

    // everything in the default pool goes before IDirect3DDevice9::Reset
    destroyRenderBuffers();
    pRenderBufferManager->Reset();
    pTextureManager->PrepareForReset();
    Cache.Reset();

    HALState |= HS_ReadyForReset;
}

// @0x142742360
bool HAL::RestoreAfterReset()
{
    if (!IsInitialized())
        return false;
    if (!(HALState & HS_ReadyForReset))
        return true;

    if (!Cache.Initialize(pDevice, Cache.UsesDynamicMeshes()))
        return false;
    pTextureManager->RestoreAfterReset();
    if (!createDefaultRenderBuffer())
        return false;

    notifyHandlers(HAL_RestoreAfterReset);
    HALState &= ~HS_ReadyForReset;
    return true;
}

// @0x1427423e0
bool HAL::ShutdownHAL()
{
    if (!(HALState & HS_ModeSet))
        return true;

    shutdownHAL();

    for (unsigned i = 0; i < VertexShaderDesc::VSI_Count; i++)
        if (VertexShaderDesc::Descs[i] && VertexShaderDesc::Descs[i]->pBinary)
            StaticVShaders[i].Shutdown();
    for (unsigned i = 0; i < FragShaderDesc::FSI_Count; i++)
        if (FragShaderDesc::Descs[i] && FragShaderDesc::Descs[i]->pBinary)
            StaticFShaders[i].Shutdown();

    destroyRenderBuffers();
    pRenderBufferManager.Clear();

    // the mapped formats own their device declarations
    for (unsigned i = 0; i < PrimitiveBatch::DP_DrawableCount; i++)
    {
        const_cast<VertexFormat*>(MappedXY16iAlphaTexture[i])->pSysFormat = 0;
        MappedXY16iAlphaTexture[i] = 0;
        const_cast<VertexFormat*>(MappedXY16iAlphaSolid[i])->pSysFormat = 0;
        MappedXY16iAlphaSolid[i] = 0;
    }

    if (pTextureManager)
        pTextureManager->Reset();
    pTextureManager.Clear();
    SManager.Reset();
    Cache.Reset();

    if (pDevice)
        pDevice->Release();
    pDevice = 0;
    return true;
}

} // namespace D3D9

// @0x142742580
void HAL::notifyHandlers(HALNotifyType type)
{
    HALNotify* p = NotifyList.GetFirst();
    while (!NotifyList.IsNull(p))
    {
        HALNotify* next = p->pNext;
        p->OnHALEvent(type);
        p = next;
    }
}

namespace D3D9 {

// @0x1427425d0
void HAL::updateViewport()
{
    D3DVIEWPORT9 vp;
    Rect<int>    vpRect;

    if (HALState & HS_ViewValid)
    {
        int dx = ViewRect.x1 - VP.Left;
        int dy = ViewRect.y1 - VP.Top;

        CalcHWViewMatrix(&Matrices.View2D, ViewRect, dx, dy);
        Matrices.SetUserMatrix(Matrices.User);
        Matrices.ViewRect    = ViewRect;
        Matrices.UVPOChanged = 1;

        if (!(HALState & HS_InRenderTarget))
        {
            Viewport hwvp = VP;
            hwvp.Left   = ViewRect.x1;
            hwvp.Top    = ViewRect.y1;
            hwvp.Width  = ViewRect.Width();
            hwvp.Height = ViewRect.Height();
            hwvp.SetStereoViewport(Matrices.S3DDisplay);
            vpRect.SetRect(hwvp.Left, hwvp.Top, hwvp.Left + hwvp.Width, hwvp.Top + hwvp.Height);
        }
        else
        {
            vpRect.SetRect(VP.Left, VP.Top, VP.Left + VP.Width, VP.Top + VP.Height);
        }
    }

    vp.X      = vpRect.x1;
    vp.Y      = vpRect.y1;
    vp.Width  = (DWORD)Alg::Max(vpRect.Width(), 1);
    vp.Height = (DWORD)Alg::Max(vpRect.Height(), 1);
    vp.MinZ   = 0.0f;
    vp.MaxZ   = 0.0f;
    pDevice->SetViewport(&vp);
}

}}} // namespace Scaleform::Render::D3D9
