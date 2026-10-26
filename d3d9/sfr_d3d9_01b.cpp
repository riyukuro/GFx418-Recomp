// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 texture TU
// (D3D9_Texture): the per-plane D3D textures with their mapping, rescaling and software mip generation, the depth
// stencil surfaces, and the D3D9 texture manager (format table probe, kill lists, init queues for textures created off
// the render thread, sampler state cache).
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01b D3D9_Texture).
// MS2-UNIT: sfr_d3d9_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142729eb0-0x142729f68 .text$mn
// MS2-RANGE: 0x142729f70-0x14272d9c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <string.h>
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/render_textureutil.h"

namespace Scaleform { namespace Render { namespace D3D9 {

// ==== Texture ========================================================================================================

// @0x14272a130
// MS2-FUNCTIONAL: register allocation and scheduling of the plane-array setup
Texture::Texture(TextureManagerLocks* plocks, const TextureFormat* pformat, unsigned mipLevels, const ImageSize& size,
                 unsigned use, ImageBase* pimage)
    : Render::Texture(plocks, size, (UByte)mipLevels, (UInt16)use, pimage), pFormat(pformat), Type(Type_Managed),
      pMap(0)
{
    TextureCount = (UByte)pformat->GetPlaneCount();
    if (TextureCount > 1)
        pTextures = (HWTextureDesc*)SF_HEAP_AUTO_ALLOC(this, sizeof(HWTextureDesc) * TextureCount);
    else
        pTextures = &Texture0;
    memset(pTextures, 0, sizeof(HWTextureDesc) * TextureCount);
}

// @0x14272a090
// MS2-FUNCTIONAL: the exe drops the Texture0.Size zeroing and allocates registers differently
Texture::Texture(TextureManagerLocks* plocks, IDirect3DTexture9* ptexture, const ImageSize& size, ImageBase* pimage)
    : Render::Texture(plocks, size, 0, 0, pimage), pFormat(0), Type(Type_Normal), pMap(0)
{
    TextureFlags |= TF_UserAlloc;
    ptexture->AddRef();
    pTextures = &Texture0;
    pTextures[0].pStagingTexture = 0;
    pTextures[0].pTexture        = ptexture;
    pTextures[0].Size            = size;
}

// @0x14272a4a0
Texture::~Texture()
{
    Mutex::Locker guard(&pManagerLocks->TextureMutex);
    if (State == State_Valid || State == State_Lost)
    {
        RemoveNode();
        pNext = pPrev = 0;
        ReleaseHWTextures();
    }
    if (pTextures != &Texture0 && pTextures)
        SF_FREE(pTextures);
}

// @0x14272b6a0
void Texture::GetUVGenMatrix(Matrix2F* mat) const
{
    const ImageSize& sz = (TextureFlags & TF_Rescale) ? ImgSize : pTextures[0].Size;
    *mat = Matrix2F::Scaling(1.0f / (float)sz.Width, 1.0f / (float)sz.Height);
}

// @0x14272beb0
void Texture::LoseManager()
{
    Ptr<Texture> keep = this;   // LoseManager may drop the last outside reference
    Render::Texture::LoseTextureData();
    Render::Texture::LoseManager();
    pFormat = 0;
}

// @0x14272bef0
void Texture::LoseTextureData()
{
    Render::Texture::LoseTextureData();
    Lock::Locker guard(&pManagerLocks->ImageLock);
    ReleaseHWTextures();
    State = State_Lost;
    if (pImage)
        ((Image*)pImage)->TextureLost(Image::TLR_DeviceLost);
}

// D3D sampler values by sample mode and by wrap mode.
static const D3DTEXTUREFILTERTYPE Texture_FilterLookup[Sample_Count] = {D3DTEXF_POINT, D3DTEXF_LINEAR};
static const D3DTEXTUREADDRESS    Texture_AddressLookup[Wrap_Count]  = {D3DTADDRESS_WRAP, D3DTADDRESS_CLAMP};

// @0x14272ab80
void Texture::ApplyTexture(DWORD stageIndex, ImageFillMode fm)
{
    D3DTEXTUREFILTERTYPE filter  = Texture_FilterLookup[fm.GetSampleMode() >> Sample_Shift];
    D3DTEXTUREADDRESS    address = Texture_AddressLookup[fm.GetWrapMode()];
    for (unsigned i = 0; i < TextureCount; i++, stageIndex++)
        GetManager()->SetSamplerState(stageIndex, pTextures[i].pTexture, filter, address);
}

// The formats the box rescaler can work in directly.
static bool IsD3DFormatRescaleCompatible(D3DFORMAT format, ImageFormat* ptargetFormat, ResizeImageType* presizeType)
{
    switch (format)
    {
    case D3DFMT_A8R8G8B8:
        *ptargetFormat = Image_B8G8R8A8;
        *presizeType   = ResizeRgbaToRgba;
        return true;
    case D3DFMT_A8B8G8R8:
        *ptargetFormat = Image_R8G8B8A8;
        *presizeType   = ResizeRgbaToRgba;
        return true;
    case D3DFMT_A8:
        *ptargetFormat = Image_A8;
        *presizeType   = ResizeGray;
        return true;
    default:
        break;
    }
    return false;
}

// The formats the software mip generator can write directly.
static bool IsD3DFormatMipGenCompatible(D3DFORMAT format)
{
    switch (format)
    {
    case D3DFMT_A8R8G8B8:
    case D3DFMT_A8B8G8R8:
    case D3DFMT_A8:
        return true;
    default:
        break;
    }
    return false;
}

// @0x14272b960
// MS2-FUNCTIONAL: one jump displacement in the tail differs (block layout)
bool Texture::Initialize()
{
    if (TextureFlags & TF_UserAlloc)
        return Initialize(pTextures[0].pTexture);

    bool            resize   = false;
    ImageFormat     format   = GetImageFormat();
    TextureManager* pmanager = GetManager();
    unsigned        itex;

    if (State != State_Lost)
    {
        for (itex = 0; itex < TextureCount; itex++)
        {
            HWTextureDesc& tdesc = pTextures[itex];
            tdesc.Size = ImageData::GetFormatPlaneSize(format, ImgSize, itex);
            if (!pmanager->Caps.NonPow2Supported(Use))
            {
                ImageSize rounded = ImageSize_RoundUpPow2(tdesc.Size);
                if (rounded != tdesc.Size)
                {
                    tdesc.Size = rounded;
                    resize     = true;
                }
            }
        }
        if (resize && (Use & ImageUse_Wrap))
        {
            if (ImageData::IsFormatCompressed(format))
            {
                State = State_InitFailed;
                return false;
            }
            TextureFlags |= TF_Rescale;
        }
    }

    unsigned allocMipLevels = MipLevels;
    DWORD    d3dUsage       = 0;
    D3DPOOL  d3dPool        = (Type == Type_Managed) ? D3DPOOL_MANAGED : D3DPOOL_DEFAULT;

    if (Use & ImageUse_GenMipmaps)
    {
        if (!pFormat->CanAutoGenMipmaps())
        {
            TextureFlags |= TF_SWMipGen;
            allocMipLevels = 31;
            for (itex = 0; itex < TextureCount; itex++)
                allocMipLevels = Alg::Min(allocMipLevels, ImageSize_MipLevelCount(pTextures[itex].Size));
            MipLevels = (UByte)allocMipLevels;
        }
        else
        {
            d3dUsage |= D3DUSAGE_AUTOGENMIPMAP;
            allocMipLevels = 0;
        }
    }

    // Without mapping access the smallest level is never touched.
    if (allocMipLevels > 1 && (Use & ImageUse_Map_Mask) == 0)
    {
        allocMipLevels--;
        MipLevels--;
    }

    bool dynamic = (Use & ImageUse_InitOnly) != 0 && (Use & (ImageUse_PartialUpdate | ImageUse_Map_Mask)) != 0;
    if (!pmanager->Caps.DynamicTexAllowed())
        dynamic = false;
    if (pmanager->Caps.IsD3D9Ex())
        dynamic = true;
    if (dynamic)
    {
        d3dUsage |= D3DUSAGE_DYNAMIC;
        d3dPool   = D3DPOOL_DEFAULT;
        Type      = Type_Dynamic;
    }
    if (Use & ImageUse_RenderTarget)
    {
        d3dUsage = D3DUSAGE_RENDERTARGET;
        d3dPool  = D3DPOOL_DEFAULT;
        Type     = (Use & ImageUse_Map_Mask) ? Type_StagingBacked : Type_Dynamic;
    }

    for (itex = 0; itex < TextureCount; itex++)
    {
        HWTextureDesc& tdesc = pTextures[itex];
        if (pmanager->pDevice->CreateTexture(tdesc.Size.Width, tdesc.Size.Height, allocMipLevels, d3dUsage,
                                             pFormat->GetD3DFormat(), d3dPool, &tdesc.pTexture, 0) != S_OK)
            goto init_failed;
        if (Type == Type_StagingBacked && State == State_InitPending)
        {
            if (pmanager->pDevice->CreateTexture(tdesc.Size.Width, tdesc.Size.Height, allocMipLevels,
                                                 d3dUsage & ~D3DUSAGE_RENDERTARGET, pFormat->GetD3DFormat(),
                                                 D3DPOOL_SYSTEMMEM, &tdesc.pStagingTexture, 0) != S_OK)
                goto init_failed;
        }
    }

    if (State == State_Lost && Type == Type_StagingBacked)
        UpdateRenderTargetData(0);

    if (pImage && !Update())
        goto init_failed;

    State = State_Valid;
    return true;

init_failed:
    ReleaseHWTextures();
    if (State != State_Lost)
        State = State_InitFailed;
    return false;
}

// @0x14272b7f0
bool Texture::Initialize(IDirect3DTexture9* ptexture)
{
    if (!ptexture)
        return false;
    if (pTextures[0].pTexture != ptexture)
    {
        ReleaseHWTextures();
        pTextures[0].pTexture = ptexture;
        pTextures[0].pTexture->AddRef();
    }

    MipLevels = (UByte)ptexture->GetLevelCount();
    D3DSURFACE_DESC desc;
    ptexture->GetLevelDesc(0, &desc);
    switch (desc.Pool)
    {
    case D3DPOOL_MANAGED: Type = Type_Managed; break;
    case D3DPOOL_DEFAULT: Type = Type_Dynamic; break;
    default:              return false;
    }

    pFormat = 0;
    TextureManager* pmanager = GetManager();
    if (pImage)
        pFormat = (const TextureFormat*)pmanager->getTextureFormat(pImage->GetFormatNoConv());
    if (!pFormat)
    {
        for (TextureFormat::Mapping* pmapping = D3D9TextureFormatMapping; pmapping->Format != Image_None; pmapping++)
        {
            if (pmapping->D3DFormat == desc.Format)
            {
                pFormat = (const TextureFormat*)pmanager->getTextureFormat(pmapping->Format);
                break;
            }
        }
    }
    if (!pFormat)
    {
        State = State_InitFailed;
        return false;
    }

    pTextures[0].Size.SetSize(desc.Width, desc.Height);
    if (ImgSize == ImageSize(0))
        ImgSize = pTextures[0].Size;
    State = State_Valid;
    return true;
}

// @0x14272cc20
bool Texture::Update()
{
    ImageFormat     format   = GetImageFormat();
    TextureManager* pmanager = GetManager();
    bool            rescale  = (TextureFlags & TF_Rescale) != 0;
    bool            swMipGen = (TextureFlags & TF_SWMipGen) != 0;
    bool            convert  = false;
    ImageData*      psource;
    ImageData*      pdecodeTarget  = 0;
    ImageData*      prescaleTarget = 0;
    ImageData       imageData1, imageData2;
    Ptr<RawImage>   pimage1, pimage2;
    unsigned        sourceMipLevels = GetMipmapCount();
    ImageFormat     rescaleFormat   = format;
    ResizeImageType rescaleType     = ResizeNone;

    if (rescale && !IsD3DFormatRescaleCompatible(pFormat->pMapping->D3DFormat, &rescaleFormat, &rescaleType))
        convert = true;
    if (swMipGen && !IsD3DFormatMipGenCompatible(pFormat->pMapping->D3DFormat))
        convert = true;

    Lock::Locker guard(&pManagerLocks->ImageLock);
    if (!pImage || (TextureFlags & TF_UserAlloc))
        return false;

    if (!(pImage->GetImageType() == Image::Type_RawImage && rescale))
    {
        if (rescale || convert)
        {
            pimage1 = *RawImage::Create(rescaleFormat, sourceMipLevels, ImgSize, 0);
            if (!pimage1)
                return false;
            pimage1->GetImageData(&imageData1);
            imageData1.Format = (ImageFormat)(format | ImageFormat_Convertible);
            pdecodeTarget = &imageData1;
        }
        else
        {
            if (!pmanager->mapTexture(this))
                return false;
            pdecodeTarget = &pMap->Data;
        }
        pImage->Decode(pdecodeTarget, convert ? &Image::CopyScanlineDefault : pFormat->pMapping->CopyFunc);
        psource = pdecodeTarget;
    }
    else
    {
        ((RawImage*)pImage->GetAsImage())->GetImageData(&imageData1);
        psource = &imageData1;
    }

    if (rescale)
    {
        if (convert)
        {
            pimage2 = *RawImage::Create(format, sourceMipLevels, pTextures[0].Size, 0);
            if (!pimage2)
                return false;
            pimage2->GetImageData(&imageData2);
            prescaleTarget = &imageData2;
        }
        else
        {
            if (!pmanager->mapTexture(this))
                return false;
            prescaleTarget = &pMap->Data;
        }
        if (rescaleType == ResizeNone)
            rescaleType = GetImageFormatRescaleType(format);
        RescaleImageData(*prescaleTarget, *psource, rescaleType);
        psource = prescaleTarget;
    }

    if (convert)
    {
        if (!pmanager->mapTexture(this))
            return false;
        ConvertImageData(pMap->Data, *psource, pFormat->pMapping->CopyFunc);
    }

    if (swMipGen)
    {
        unsigned planeCount = ImageData::GetFormatPlaneCount(format);
        for (unsigned iplane = 0; iplane < planeCount; iplane++)
        {
            ImagePlane splane, tplane;
            psource->GetMipLevelPlane(0, iplane, &splane);
            for (unsigned level = 1; level < MipLevels; level++)
            {
                pMap->Data.GetMipLevelPlane(level, iplane, &tplane);
                if (!convert)
                {
                    GenerateMipLevel(tplane, splane, format, iplane);
                    splane = tplane;
                }
                else
                {
                    ImagePlane dplane(splane);
                    dplane.SetNextMipSize();
                    GenerateMipLevel(dplane, splane, format, iplane);
                    ConvertImagePlane(tplane, dplane, format, iplane, pFormat->pMapping->CopyFunc,
                                      psource->GetColorMap());
                    splane.Width  = dplane.Width;
                    splane.Height = dplane.Height;
                }
            }
        }
    }

    pmanager->unmapTexture(this);
    return true;
}

// @0x14272c340
void Texture::ReleaseHWTextures(bool staging)
{
    TextureManager* pmanager    = GetManager();
    bool            useKillList = !pmanager->Caps.IsMultiThreaded() && GetCurrentThreadId() != pmanager->RenderThreadId;

    for (unsigned itex = 0; itex < TextureCount; itex++)
    {
        IDirect3DTexture9* ptexture = pTextures[itex].pTexture;
        IDirect3DTexture9* pstaging = staging ? pTextures[itex].pStagingTexture : 0;
        if (useKillList)
        {
            if (ptexture)
                pmanager->D3DTextureKillList.PushBack(ptexture);
            if (pstaging)
                pmanager->D3DTextureKillList.PushBack(pstaging);
        }
        else
        {
            if (ptexture)
                ptexture->Release();
            if (pstaging)
                pstaging->Release();
        }
        pTextures[itex].pTexture = 0;
        if (staging)
            pTextures[itex].pStagingTexture = 0;
    }
}

// @0x14272c1e0
bool Texture::Map(ImageData* pdata, unsigned mipLevel, unsigned levelCount)
{
    if (levelCount == 0)
        levelCount = MipLevels - mipLevel;
    if (!GetManager()->mapTexture(this, mipLevel, levelCount))
        return false;
    pdata->Initialize(GetImageFormat(), levelCount, pMap->Data.pPlanes, pMap->Data.RawPlaneCount, true);
    pdata->Use = Use;
    return true;
}

// @0x14272ca20
bool Texture::Unmap()
{
    if (!pMap)
        return false;
    GetManager()->unmapTexture(this);
    return true;
}

// @0x14272d210
bool Texture::UpdateRenderTargetData(RenderTargetData*, HAL*)
{
    unsigned count  = TextureCount;
    bool     result = false;
    for (unsigned itex = 0; itex < count; itex++)
    {
        HWTextureDesc& tdesc = pTextures[itex];
        if (Type == Type_StagingBacked)
        {
            IDirect3DDevice9* pdevice = ((TextureManager*)GetTextureManager())->GetDevice();
            pdevice->UpdateTexture(tdesc.pStagingTexture, tdesc.pTexture);
            result = true;
        }
    }
    return result;
}

// @0x14272d2a0
bool Texture::UpdateStagingData(RenderTargetData*)
{
    if (Type != Type_StagingBacked)
        return false;
    Ptr<IDirect3DSurface9> src, dest;
    IDirect3DDevice9* pdevice = GetManager()->GetDevice();
    pTextures[0].pTexture->GetSurfaceLevel(0, &src.GetRawRef());
    pTextures[0].pStagingTexture->GetSurfaceLevel(0, &dest.GetRawRef());
    return SUCCEEDED(pdevice->GetRenderTargetData(src, dest));
}

// @0x14272ca50
bool Texture::Update(const UpdateDesc* updates, unsigned count, unsigned mipLevel)
{
    if (!GetManager()->mapTexture(this, mipLevel, 1))
        return false;

    ImageFormat format = GetImageFormat();
    ImagePlane  dplane;
    for (unsigned i = 0; i < count; i++)
    {
        const UpdateDesc& desc = updates[i];
        ImagePlane        splane(desc.SourcePlane);
        pMap->Data.GetPlane(desc.PlaneIndex, &dplane);
        dplane.pData += desc.DestRect.y1 * dplane.Pitch + desc.DestRect.x1 * pFormat->pMapping->BytesPerPixel;
        splane.SetSize(desc.DestRect.GetSize());
        dplane.SetSize(desc.DestRect.GetSize());
        ConvertImagePlane(dplane, splane, format, desc.PlaneIndex, pFormat->pMapping->CopyFunc, 0);
    }

    GetManager()->unmapTexture(this);
    return true;
}

// @0x14272ace0
bool Texture::Copy(ImageData* pdata)
{
    Image::CopyScanlineFunc uncopy = pFormat->pMapping->UncopyFunc;
    if (!GetManager() || pFormat->pMapping->Format != pdata->Format || !uncopy)
        return false;

    bool     mapped   = pMap != 0;
    unsigned mipCount = GetMipmapCount();
    if (!mapped && !GetManager()->mapTexture(this, 0, mipCount))
        return false;

    for (int ip = 0; ip < pdata->RawPlaneCount; ip++)
    {
        ImagePlane splane, dplane;
        pdata->GetPlane(ip, &dplane);
        pMap->Data.GetPlane(ip, &splane);
        ConvertImagePlane(dplane, splane, GetFormat(), ip, uncopy, 0);
    }

    if (!mapped)
        GetManager()->unmapTexture(this);
    return true;
}

// ==== DepthStencilSurface ============================================================================================

// @0x142729f70
DepthStencilSurface::DepthStencilSurface(TextureManagerLocks* plocks, const ImageSize& size)
    : Render::DepthStencilSurface(plocks), Size(size), pDepthStencilSurface(0), State(Texture::State_InitPending)
{
}

// @0x14272a460
DepthStencilSurface::~DepthStencilSurface()
{
    if (pDepthStencilSurface)
        pDepthStencilSurface->Release();
}

// @0x14272b780
bool DepthStencilSurface::Initialize()
{
    TextureManager* pmanager = (TextureManager*)GetTextureManager();
    if (FAILED(pmanager->pDevice->CreateDepthStencilSurface(Size.Width, Size.Height, D3DFMT_D24S8,
                                                            D3DMULTISAMPLE_NONE, 0, FALSE,
                                                            &pDepthStencilSurface, 0)))
        State = Texture::State_InitFailed;
    else
        State = Texture::State_Valid;
    return State == Texture::State_Valid;
}

// ==== MappedTexture ==================================================================================================

// @0x14272bf50
// MS2-FUNCTIONAL: the exe's ImageData::Initialize/plane loop is laid out differently (290 vs 251 bytes)
bool MappedTexture::Map(Texture* ptexture, unsigned mipLevel, unsigned levelCount)
{
    if (levelCount <= PlaneReserveSize)
        Data.Initialize(ptexture->GetImageFormat(), levelCount, Planes, ptexture->GetPlaneCount(), true);
    else if (!Data.Initialize(ptexture->GetImageFormat(), levelCount, true))
        return false;

    pTexture      = ptexture;
    StartMipLevel = mipLevel;
    LevelCount    = levelCount;

    bool     failed = false;
    unsigned count  = ptexture->TextureCount;
    for (unsigned itex = 0; itex < count; itex++)
    {
        Texture::HWTextureDesc& tdesc  = pTexture->pTextures[itex];
        IDirect3DTexture9*      locked = (pTexture->Type == Texture::Type_StagingBacked) ? tdesc.pStagingTexture
                                                                                       : tdesc.pTexture;
        ImagePlane plane;
        plane.SetSize(tdesc.Size);
        for (unsigned i = 0; i < StartMipLevel; i++)
            plane.SetNextMipSize();

        for (unsigned level = 0; level < levelCount; level++)
        {
            D3DLOCKED_RECT lr;
            if (!failed && locked->LockRect(level + StartMipLevel, &lr, 0, 0) == D3D_OK)
            {
                plane.Pitch    = lr.Pitch;
                plane.pData    = (UByte*)lr.pBits;
                plane.DataSize = ImageData::GetMipLevelSize(Data.GetFormat(), plane.GetSize(), level);
            }
            else
            {
                plane.Pitch    = 0;
                plane.pData    = 0;
                plane.DataSize = 0;
                failed         = true;
            }
            Data.GetPlaneRef(level * count + itex) = plane;
            plane.SetNextMipSize();
        }
    }

    if (failed)
    {
        Unmap();
        return false;
    }
    pTexture->pMap = this;
    return true;
}

// @0x14272c910
void MappedTexture::Unmap()
{
    unsigned count = pTexture->TextureCount;
    for (unsigned itex = 0; itex < count; itex++)
    {
        Texture::HWTextureDesc& tdesc  = pTexture->pTextures[itex];
        IDirect3DTexture9*      locked = (pTexture->Type == Texture::Type_StagingBacked) ? tdesc.pStagingTexture
                                                                                       : tdesc.pTexture;
        ImagePlane plane;
        for (int level = 0; level < LevelCount; level++)
        {
            Data.GetPlane(level * count + itex, &plane);
            if (plane.pData)
            {
                locked->UnlockRect(level + StartMipLevel);
                plane.pData = 0;
            }
        }
    }
    pTexture->pMap = 0;
    pTexture       = 0;
    StartMipLevel  = 0;
    LevelCount     = 0;
}

// ==== TextureManager =================================================================================================

// @0x14272a280
TextureManager::TextureManager(IDirect3DDevice9* pdevice, D3DCapFlags capFlags, ThreadId renderThreadId,
                               ThreadCommandQueue* commandQueue)
    : Render::TextureManager(), pDevice(pdevice), Caps(capFlags), pRTCommandQueue(commandQueue)
{
    if (renderThreadId)
        RenderThreadId = renderThreadId;
    else
        RenderThreadId = Caps.IsMultiThreaded() ? 0 : GetCurrentThreadId();
    initTextureFormats();
}

// @0x14272a550
TextureManager::~TextureManager()
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    Reset();
    pLocks->pManager = 0;
}

// @0x14272c6f0
void TextureManager::Reset()
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    while (!Textures.IsEmpty())
        Textures.GetFirst()->LoseManager();
    processTextureKillList();
    pDevice = 0;
}

// @0x14272c2b0
void TextureManager::PrepareForReset()
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    Texture* p = Textures.GetFirst();
    while (!Textures.IsNull(p))
    {
        Texture* next = Textures.GetNext(p);
        if (p->Type != Texture::Type_Managed)
            p->LoseTextureData();
        p = next;
    }
    processTextureKillList();
}

// @0x14272c780
void TextureManager::RestoreAfterReset()
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    Texture* p = Textures.GetFirst();
    while (!Textures.IsNull(p))
    {
        if (p->State == Texture::State_Lost)
            p->Initialize();
        p = Textures.GetNext(p);
    }
}

// @0x14272d3b0
void TextureManager::initTextureFormats()
{
    Ptr<IDirect3D9>               pd3d9;
    D3DCAPS9                      caps;
    D3DDEVICE_CREATION_PARAMETERS cp;
    D3DDISPLAYMODE                mode;

    pDevice->GetDirect3D(&pd3d9.GetRawRef());
    pDevice->GetCreationParameters(&cp);
    pDevice->GetDeviceCaps(&caps);
    pd3d9->GetAdapterDisplayMode(cp.AdapterOrdinal, &mode);

    for (TextureFormat::Mapping* pmapping = D3D9TextureFormatMapping; pmapping->Format != Image_None; pmapping++)
    {
        if (pd3d9->CheckDeviceFormat(cp.AdapterOrdinal, cp.DeviceType, mode.Format, 0, D3DRTYPE_TEXTURE,
                                     pmapping->D3DFormat) != D3D_OK)
            continue;

        TextureFormat tf;
        tf.pMapping = pmapping;
        tf.D3DUsage = 0;
        if ((caps.Caps2 & D3DCAPS2_CANAUTOGENMIPMAP) &&
            pd3d9->CheckDeviceFormat(cp.AdapterOrdinal, cp.DeviceType, mode.Format, D3DUSAGE_AUTOGENMIPMAP,
                                     D3DRTYPE_TEXTURE, pmapping->D3DFormat) == D3D_OK)
            tf.D3DUsage |= D3DUSAGE_AUTOGENMIPMAP;
        if ((caps.Caps2 & D3DCAPS2_DYNAMICTEXTURES) &&
            pd3d9->CheckDeviceFormat(cp.AdapterOrdinal, cp.DeviceType, mode.Format, D3DUSAGE_DYNAMIC,
                                     D3DRTYPE_TEXTURE, pmapping->D3DFormat) == D3D_OK)
            tf.D3DUsage |= D3DUSAGE_DYNAMIC;
        TextureFormats.PushBack(tf);

        // the first supported D3D format wins for an image format
        while ((pmapping + 1)->Format == pmapping->Format)
            pmapping++;
    }
}

// @0x14272d360
const Render::TextureFormat* TextureManager::getTextureFormat(ImageFormat format) const
{
    for (unsigned i = 0; i < TextureFormats.GetSize(); i++)
        if (TextureFormats[i].GetImageFormat() == format)
            return &TextureFormats[i];
    return 0;
}

// @0x14272d600
// MS2-FUNCTIONAL: the exe inlines MappedTexture construction/destruction differently (234 vs 217 bytes)
MappedTexture* TextureManager::mapTexture(Texture* ptexture, unsigned mipLevel, unsigned levelCount)
{
    MappedTexture* pmap;
    if (MappedTexture0.Reserve())
        pmap = &MappedTexture0;
    else
    {
        pmap = SF_HEAP_AUTO_NEW(this) MappedTexture;
        if (!pmap)
            return 0;
    }
    if (pmap->Map(ptexture, mipLevel, levelCount))
        return pmap;
    if (pmap != &MappedTexture0)
        delete pmap;
    return 0;
}

// @0x14272d950
void TextureManager::unmapTexture(Texture* ptexture)
{
    MappedTexture* pmap = ptexture->pMap;
    pmap->Unmap();
    if (pmap != &MappedTexture0)
        delete pmap;
}

// @0x14272d860
void TextureManager::processTextureKillList()
{
    for (unsigned i = 0; i < D3DTextureKillList.GetSize(); i++)
        D3DTextureKillList[i]->Release();
    for (unsigned i = 0; i < D3DDepthStencilKillList.GetSize(); i++)
        D3DDepthStencilKillList[i]->Release();
    D3DDepthStencilKillList.Clear();
    D3DTextureKillList.Clear();
}

// @0x14272d6f0
void TextureManager::processInitTextures()
{
    if (TextureInitQueue.IsEmpty() && DepthStencilInitQueue.IsEmpty())
        return;

    while (!TextureInitQueue.IsEmpty())
    {
        Texture* ptexture = TextureInitQueue.GetFirst();
        ptexture->RemoveNode();
        ptexture->pPrev = ptexture->pNext = 0;
        if (ptexture->Initialize())
            Textures.PushBack(ptexture);
    }
    while (!DepthStencilInitQueue.IsEmpty())
    {
        DepthStencilSurface* pdss = DepthStencilInitQueue.GetFirst();
        pdss->RemoveNode();
        pdss->pPrev = pdss->pNext = 0;
        pdss->Initialize();
    }
    pLocks->TextureInitWC.NotifyAll();
}

// @0x14272c800
void TextureManager::SetSamplerState(unsigned stage, IDirect3DTexture9* d3dtex, D3DTEXTUREFILTERTYPE filter,
                                     D3DTEXTUREADDRESS address)
{
    if (AddressMode[stage] != address)
    {
        pDevice->SetSamplerState(stage, D3DSAMP_ADDRESSU, address);
        pDevice->SetSamplerState(stage, D3DSAMP_ADDRESSV, address);
        AddressMode[stage] = address;
    }
    if (FilterType[stage] != filter)
    {
        pDevice->SetSamplerState(stage, D3DSAMP_MINFILTER, filter);
        pDevice->SetSamplerState(stage, D3DSAMP_MAGFILTER, filter);
        pDevice->SetSamplerState(stage, D3DSAMP_MIPFILTER, filter);
        FilterType[stage] = filter;
    }
    if (CurrentTextures[stage] != d3dtex)
    {
        pDevice->SetTexture(stage, d3dtex);
        CurrentTextures[stage] = d3dtex;
    }
}

// @0x14272acb0
bool TextureManager::CanCreateTextureCurrentThread()
{
    return GetCurrentThreadId() == RenderThreadId || Caps.IsMultiThreaded();
}

// @0x14272b300
// MS2-FUNCTIONAL: inlined format ctor and lock sequence scheduled differently
Render::Texture* TextureManager::CreateTexture(ImageFormat format, unsigned mipLevels, const ImageSize& size,
                                               unsigned use, ImageBase* pimage, MemoryManager*)
{
    if (!pDevice)
        return 0;

    const TextureFormat* ptformat = (const TextureFormat*)precreateTexture(format, use, pimage);
    if (!ptformat)
        return 0;

    Texture* ptexture = SF_HEAP_AUTO_NEW(this) Texture(pLocks, ptformat, mipLevels, size, use, pimage);
    if (!ptexture)
        return 0;
    if (!ptexture->IsValid())
    {
        ptexture->Release();
        return 0;
    }

    Mutex::Locker guard(&pLocks->TextureMutex);
    if (Caps.IsMultiThreaded() || GetCurrentThreadId() == RenderThreadId)
    {
        if (!Caps.IsMultiThreaded())
        {
            processTextureKillList();
            processInitTextures();
        }
        if (ptexture->Initialize())
            Textures.PushBack(ptexture);
    }
    else
    {
        // created off the render thread: the render thread initializes it
        TextureInitQueue.PushBack(ptexture);
        if (pRTCommandQueue)
        {
            pLocks->TextureMutex.Unlock();
            pRTCommandQueue->PushThreadCommand(&ServiceCommandInstance);
            pLocks->TextureMutex.DoLock();
        }
        while (ptexture->State == Texture::State_InitPending)
            pLocks->TextureInitWC.Wait(&pLocks->TextureMutex);
    }

    if (use & ImageUse_InitOnly)
    {
        if (ptexture->pImage && ptexture->pImage->GetImageType() == Image::Type_RawImage)
            ((RawImage*)ptexture->pImage)->freeData();
        ptexture->pImage = 0;
    }

    if (ptexture->State == Texture::State_InitFailed)
    {
        ptexture->Release();
        return 0;
    }
    return ptexture;
}

// @0x14272ac20
void TextureManager::BeginScene()
{
    for (int i = 0; i < MaximumStages; i++)
    {
        AddressMode[i]     = D3DTADDRESS_FORCE_DWORD;
        FilterType[i]      = D3DTEXF_FORCE_DWORD;
        CurrentTextures[i] = 0;
        pDevice->SetTexture(i, 0);
    }
}

// @0x14272b0f0
// MS2-FUNCTIONAL: inlined user-texture ctor: the exe drops the Texture0.Size zeroing
Render::Texture* TextureManager::CreateTexture(IDirect3DTexture9* pd3dtexture, ImageSize imgSize, Image* pimage)
{
    if (!pd3dtexture)
        return 0;

    Texture* ptexture = SF_HEAP_AUTO_NEW(this) Texture(pLocks, pd3dtexture, imgSize, pimage);
    if (!ptexture)
        return 0;
    if (!ptexture->IsValid())
    {
        ptexture->Release();
        return 0;
    }

    Mutex::Locker guard(&pLocks->TextureMutex);
    if (Caps.IsMultiThreaded() || GetCurrentThreadId() == RenderThreadId)
    {
        if (!Caps.IsMultiThreaded())
        {
            processTextureKillList();
            processInitTextures();
        }
        if (ptexture->Initialize())
            Textures.PushBack(ptexture);
    }
    else
    {
        TextureInitQueue.PushBack(ptexture);
        if (pRTCommandQueue)
        {
            pLocks->TextureMutex.Unlock();
            pRTCommandQueue->PushThreadCommand(&ServiceCommandInstance);
            pLocks->TextureMutex.DoLock();
        }
        while (ptexture->State == Texture::State_InitPending)
            pLocks->TextureInitWC.Wait(&pLocks->TextureMutex);
    }

    if (ptexture->State == Texture::State_InitFailed)
    {
        ptexture->Release();
        return 0;
    }
    return ptexture;
}

// @0x14272b630
unsigned TextureManager::GetTextureUseCaps(ImageFormat format)
{
    unsigned use = ImageUse_InitOnly | ImageUse_Update;
    if (!ImageData::IsFormatCompressed(format))
        use |= ImageUse_PartialUpdate | ImageUse_GenMipmaps;

    const Render::TextureFormat* ptformat = getTextureFormat(format);
    if (!ptformat)
        return 0;
    if (isMappable(ptformat))
        use |= ImageUse_MapRenderThread;
    return use;
}

// @0x14272ae60
Render::DepthStencilSurface* TextureManager::CreateDepthStencilSurface(const ImageSize& size, MemoryManager*)
{
    if (!pDevice)
        return 0;

    DepthStencilSurface* pdss = SF_HEAP_AUTO_NEW(this) DepthStencilSurface(pLocks, size);
    if (!pdss)
        return 0;

    Mutex::Locker guard(&pLocks->TextureMutex);
    if (Caps.IsMultiThreaded() || GetCurrentThreadId() == RenderThreadId)
    {
        if (!Caps.IsMultiThreaded())
        {
            processTextureKillList();
            processInitTextures();
        }
        pdss->Initialize();
    }
    else
    {
        DepthStencilInitQueue.PushBack(pdss);
        if (pRTCommandQueue)
        {
            pLocks->TextureMutex.Unlock();
            pRTCommandQueue->PushThreadCommand(&ServiceCommandInstance);
            pLocks->TextureMutex.DoLock();
        }
        while (pdss->State == Texture::State_InitPending)
            pLocks->TextureInitWC.Wait(&pLocks->TextureMutex);
    }
    return pdss;
}

// @0x14272afe0
Render::DepthStencilSurface* TextureManager::CreateDepthStencilSurface(IDirect3DSurface9* psurface)
{
    if (!psurface)
        return 0;
    psurface->AddRef();
    D3DSURFACE_DESC desc;
    psurface->GetDesc(&desc);
    DepthStencilSurface* pdss = SF_HEAP_AUTO_NEW(this) DepthStencilSurface(pLocks, ImageSize(desc.Width, desc.Height));
    pdss->pDepthStencilSurface = psurface;
    pdss->State                = Texture::State_Valid;
    return pdss;
}

}}} // namespace Scaleform::Render::D3D9

// MS2-PIN: ??_7DepthStencilSurface@Render@Scaleform@@6B@ 0x14319d568
// MS2-PIN: ??_7Texture@D3D9@Render@Scaleform@@6B@ 0x14319d580
// MS2-PIN: ??_7DepthStencilSurface@D3D9@Render@Scaleform@@6B@ 0x14319d600
// MS2-PIN: ??_7TextureManager@D3D9@Render@Scaleform@@6B?$RefCountBase@VTextureManager@Render@Scaleform@@$0EL@@3@@ 0x14319d618
// MS2-PIN: ??_7TextureManager@D3D9@Render@Scaleform@@6BImageUpdateSync@23@@ 0x14319d6c0
// MS2-PIN: ?GetTextureManager@DepthStencilSurface@Render@Scaleform@@UEBAPEAVTextureManager@23@XZ 0x14272b610
// MS2-PIN: ?GetTextureManager@Texture@Render@Scaleform@@QEBAPEAVTextureManager@23@XZ 0x14272b620
// MS2-PIN: ??_7Texture@Render@Scaleform@@6B@ 0x14319d4e0
// MS2-PIN: ??_7ImageUpdateSync@Render@Scaleform@@6B@ 0x143183950
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_7?$RefCountBase@VTexture@Render@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_7?$RefCountBase@VDepthStencilSurface@Render@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940

// ---- full-exe unresolved: the 8-bit <-> 16-bit two-channel scanline converters of the format table (no .pdata;
// data tables take them as ?FUN_<va>@@YAXXZ). n is the pixel count.

// MS2-FUNCTIONAL: one channel -> {0xff, c} pairs.
// @0x142729eb0
void FUN_142729eb0(unsigned char* dst, const unsigned char* src, size_t n)
{
    for (; n; --n, dst += 2)
    {
        dst[0] = 0xff;
        dst[1] = *src++;
    }
}

// MS2-FUNCTIONAL: one channel -> {0xff, c | 0x0f} pairs.
// @0x142729ee0
void FUN_142729ee0(unsigned char* dst, const unsigned char* src, size_t n)
{
    for (; n; --n, dst += 2)
    {
        dst[0] = 0xff;
        dst[1] = (unsigned char)(*src++ | 0x0f);
    }
}

// MS2-FUNCTIONAL: the second byte of each pair.
// @0x142729f10
void FUN_142729f10(unsigned char* dst, const unsigned char* src, size_t n)
{
    for (src += 1; n; --n, src += 2)
        *dst++ = *src;
}

// MS2-FUNCTIONAL: the second byte of each pair, low nibble cleared.
// @0x142729f40
void FUN_142729f40(unsigned char* dst, const unsigned char* src, size_t n)
{
    for (src += 1; n; --n, src += 2)
        *dst++ = (unsigned char)(*src & 0xf0);
}
