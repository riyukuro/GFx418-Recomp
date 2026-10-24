// Recovered Scaleform 4.1.18 Render: the depth stencil surface interface and the D3D9 textures and texture manager
// (D3D9_Texture section of sfr_d3d9_01, 0x142729f70-0x14272da60). Written from the exe; names from the SDK headers.
// Shared header of the src/ms2/scaleform units: append, do not reorder.
//
// Layouts (exe): Render::DepthStencilSurface 0x28 (vftable 0x14319d568, 3 slots), D3D9::DepthStencilSurface 0x40
// (0x14319d600), D3D9::Texture 0x80 (0x14319d580, 16 slots), MappedTexture 0xd0, D3D9::TextureManager 0x210
// (0x14319d618, 21 slots: SetSamplerState 18, CreateTexture(IDirect3DTexture9*) 19,
// CreateDepthStencilSurface(IDirect3DSurface9*) 20; ImageUpdateSync vftable 0x14319d6c0).
#ifndef MS2_SF_RENDER_D3D9_TEXTURE_H
#define MS2_SF_RENDER_D3D9_TEXTURE_H

#include <d3d9.h>
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_fillmode.h"

namespace Scaleform { namespace Render {

// A depth stencil surface a render target can use (base of the HAL implementations).
class DepthStencilSurface : public RefCountBase<DepthStencilSurface, StatRender_TextureManager_Mem>,
                            public ListNode<DepthStencilSurface>
{
public:
    DepthStencilSurface(TextureManagerLocks* plocks) : pManagerLocks(plocks) {}

    virtual TextureManager* GetTextureManager() const { return pManagerLocks ? pManagerLocks->pManager : 0; } // 1
    virtual ImageSize       GetSize() const = 0;                                                             // 2

    Ptr<TextureManagerLocks> pManagerLocks;     // +0x20
};

namespace D3D9 {

// A D3D format an ImageFormat can be stored in (entries of D3D9TextureFormatMapping, 0x20 bytes each).
struct TextureFormat : public Render::TextureFormat
{
    struct Mapping
    {
        ImageFormat             Format;         // +0x00
        D3DFORMAT               D3DFormat;      // +0x04
        UByte                   BytesPerPixel;  // +0x08
        bool                    Mappable;       // +0x09
        Image::CopyScanlineFunc CopyFunc;       // +0x10 image -> texture
        Image::CopyScanlineFunc UncopyFunc;     // +0x18 texture -> image
    };

    const Mapping* pMapping;                    // +0x00
    DWORD          D3DUsage;                    // +0x08 usage bits the device accepts for the format

    ImageFormat GetImageFormat() const    { return pMapping->Format; }
    D3DFORMAT   GetD3DFormat() const      { return pMapping->D3DFormat; }
    unsigned    GetPlaneCount() const     { return ImageData::GetFormatPlaneCount(GetImageFormat()); }
    bool        CanAutoGenMipmaps() const { return (D3DUsage & D3DUSAGE_AUTOGENMIPMAP) != 0; }
    bool        CanBeDynamic() const      { return (D3DUsage & D3DUSAGE_DYNAMIC) != 0; }
};

// The format table (.data 0x143a303c0), terminated by an Image_None entry.
extern TextureFormat::Mapping D3D9TextureFormatMapping[];

class MappedTexture;
class TextureManager;

// A texture made of one D3D texture per plane of its image format.
class Texture : public Render::Texture
{
public:
    enum AllocType
    {
        Type_Normal,
        Type_Managed,
        Type_Dynamic,
        Type_StagingBacked
    };
    enum TextureFlagBits
    {
        TF_Rescale   = 0x01,
        TF_SWMipGen  = 0x02,
        TF_UserAlloc = 0x04
    };

    struct HWTextureDesc
    {
        ImageSize          Size;
        IDirect3DTexture9* pTexture;
        IDirect3DTexture9* pStagingTexture;     // system memory copy of a staging backed render target
    };

    const TextureFormat* pFormat;               // +0x48
    AllocType            Type;                  // +0x50
    MappedTexture*       pMap;                  // +0x58
    HWTextureDesc*       pTextures;             // +0x60
    HWTextureDesc        Texture0;              // +0x68

    Texture(TextureManagerLocks* plocks, const TextureFormat* pformat, unsigned mipLevels, const ImageSize& size,
            unsigned use, ImageBase* pimage);
    Texture(TextureManagerLocks* plocks, IDirect3DTexture9* ptexture, const ImageSize& size, ImageBase* pimage);
    ~Texture();

    TextureManager* GetManager() const     { return (TextureManager*)pManagerLocks->pManager; }
    bool            IsValid() const        { return pTextures != 0; }
    ImageFormat     GetImageFormat() const { return pFormat->GetImageFormat(); }
    unsigned        GetPlaneCount() const  { return pFormat->GetPlaneCount(); }

    bool            Initialize();
    bool            Initialize(IDirect3DTexture9* ptexture);
    void            ApplyTexture(DWORD stageIndex, ImageFillMode fm);

    virtual Image*      GetImage() const { return (Image*)pImage; }
    virtual ImageFormat GetFormat() const { return GetImageFormat(); }
    virtual void        GetUVGenMatrix(Matrix2F* mat) const;
    virtual void        LoseManager();
    virtual void        LoseTextureData();
    virtual void        ReleaseHWTextures(bool staging = true);
    virtual bool        Map(ImageData* pdata, unsigned mipLevel, unsigned levelCount);
    virtual bool        Unmap();
    virtual bool        Copy(ImageData* pdata);
    virtual bool        UpdateRenderTargetData(RenderTargetData* prt, HAL* = 0);
    virtual bool        UpdateStagingData(RenderTargetData* prt);
    virtual bool        Update(const UpdateDesc* updates, unsigned count = 1, unsigned mipLevel = 0);
    virtual bool        Update();
};

class DepthStencilSurface : public Render::DepthStencilSurface
{
public:
    DepthStencilSurface(TextureManagerLocks* plocks, const ImageSize& size);
    ~DepthStencilSurface();

    virtual ImageSize GetSize() const { return Size; }
    bool              Initialize();

    ImageSize             Size;                     // +0x28
    IDirect3DSurface9*    pDepthStencilSurface;     // +0x30
    Texture::CreateState  State;                    // +0x38
};

// A texture's levels locked into memory (Texture::Map and the updates).
class MappedTexture : public NewOverrideBase<StatRender_TextureManager_Mem>
{
    friend class Texture;
public:
    enum { PlaneReserveSize = 4 };

    Texture*   pTexture;                        // +0x00
    unsigned   StartMipLevel;                   // +0x08
    int        LevelCount;                      // +0x0c
    ImageData  Data;                            // +0x10
    ImagePlane Planes[PlaneReserveSize];        // +0x50

    MappedTexture() : pTexture(0), StartMipLevel(0), LevelCount(0) {}

    bool IsMapped() const { return pTexture != 0; }
    bool Reserve()
    {
        if (IsMapped())
            return false;
        return true;
    }
    bool Map(Texture* ptexture, unsigned mipLevel, unsigned levelCount);
    void Unmap();
};

// What the device can do (D3D9::HAL fills it from the device caps).
struct D3DCapFlags
{
    enum
    {
        Cap_MultiThreaded  = 0x001,
        Cap_Managed        = 0x002,
        Cap_DynamicTex     = 0x004,
        Cap_AutoGenMipmaps = 0x010,
        Cap_NonPow2Tex     = 0x040,
        Cap_NonPow2TexWrap = 0x080,
        Cap_D3D9Ex         = 0x100
    };

    UInt32 Flags;

    bool IsMultiThreaded() const   { return (Flags & Cap_MultiThreaded) != 0; }
    bool IsManaged() const         { return (Flags & Cap_Managed) != 0; }
    bool DynamicTexAllowed() const { return (Flags & Cap_DynamicTex) != 0; }
    bool IsD3D9Ex() const          { return (Flags & Cap_D3D9Ex) != 0; }
    bool NonPow2Supported(unsigned use) const
    {
        UInt32 bit = (use & ImageUse_Wrap) ? Cap_NonPow2TexWrap : Cap_NonPow2Tex;
        return (Flags & bit) != 0;
    }
};

class TextureManager : public Render::TextureManager
{
    friend class Texture;
    friend class DepthStencilSurface;
public:
    typedef ArrayConstPolicy<8, 8, false>                                               KillListArrayPolicy;
    typedef ArrayLH<IDirect3DTexture9*, StatRender_TextureManager_Mem, KillListArrayPolicy> D3DTextureArray;
    typedef ArrayLH<IDirect3DSurface9*, StatRender_TextureManager_Mem, KillListArrayPolicy> D3DDepthStencilArray;
    typedef List<Texture, Render::Texture>                                              TextureList;
    typedef List<DepthStencilSurface, Render::DepthStencilSurface>                      DepthStencilList;
    enum { MaximumStages = 4 };

    IDirect3DDevice9*       pDevice;                    // +0x50
    D3DCapFlags             Caps;                       // +0x58
    ThreadId                RenderThreadId;             // +0x60
    MappedTexture           MappedTexture0;             // +0x68
    ThreadCommandQueue*     pRTCommandQueue;            // +0x138
    TextureList             Textures;                   // +0x140
    TextureList             TextureInitQueue;           // +0x150
    DepthStencilList        DepthStencilInitQueue;      // +0x160
    D3DTextureArray         D3DTextureKillList;         // +0x170
    D3DDepthStencilArray    D3DDepthStencilKillList;    // +0x188
    ImageUpdateQueue        ImageUpdates;               // +0x1a0
    ArrayLH<TextureFormat>  TextureFormats;             // +0x1b8
    D3DTEXTUREADDRESS       AddressMode[MaximumStages]; // +0x1d0
    D3DTEXTUREFILTERTYPE    FilterType[MaximumStages];  // +0x1e0
    IDirect3DTexture9*      CurrentTextures[MaximumStages]; // +0x1f0

    TextureManager(IDirect3DDevice9* pdevice, D3DCapFlags capFlags, ThreadId renderThreadId = 0,
                   ThreadCommandQueue* commandQueue = 0);
    ~TextureManager();

    IDirect3DDevice9* GetDevice() const { return pDevice; }

    void PrepareForReset();
    void RestoreAfterReset();
    void Reset();

    // new slot 18 (declared first: MSVC places the CreateTexture/CreateDepthStencilSurface overloads after it)
    virtual void             SetSamplerState(unsigned stage, IDirect3DTexture9* d3dtex,
                                             D3DTEXTUREFILTERTYPE filter = D3DTEXF_LINEAR,
                                             D3DTEXTUREADDRESS address = D3DTADDRESS_CLAMP);
    virtual Render::Texture* CreateTexture(ImageFormat format, unsigned mipLevels, const ImageSize& size,
                                           unsigned use, ImageBase* pimage = 0, MemoryManager* manager = 0);
    virtual unsigned         GetTextureFormatSupport() const { return ImageFormats_DXT; }
    virtual unsigned         GetTextureUseCaps(ImageFormat format);
    virtual Render::DepthStencilSurface* CreateDepthStencilSurface(const ImageSize& size,
                                                                   MemoryManager* manager = 0);
    virtual bool             CanCreateTextureCurrentThread();
    virtual void             BeginScene();
    virtual ImageFormat      GetDrawableImageFormat() const { return Image_B8G8R8A8; }
    virtual bool             IsDrawableImageFormat(ImageFormat format) const { return format == Image_B8G8R8A8; }

protected:
    virtual void             processTextureKillList();
    virtual void             processInitTextures();
    virtual const Render::TextureFormat* getTextureFormat(ImageFormat format) const;
    virtual bool             isMappable(const Render::TextureFormat* ptformat)
    {
        return ((const TextureFormat*)ptformat)->pMapping->Mappable;
    }

public:
    virtual Render::Texture* CreateTexture(IDirect3DTexture9* pd3dtexture, ImageSize imgSize = ImageSize(0),
                                           Image* pimage = 0);
    virtual Render::DepthStencilSurface* CreateDepthStencilSurface(IDirect3DSurface9* psurface);

protected:
    void            initTextureFormats();
    MappedTexture*  mapTexture(Texture* p, unsigned mipLevel, unsigned levelCount);
    MappedTexture*  mapTexture(Texture* p) { return mapTexture(p, 0, p->MipLevels); }
    void            unmapTexture(Texture* ptexture);
};

}}} // namespace Scaleform::Render::D3D9

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::D3D9::MappedTexture) == 0xd0, "MappedTexture size");
static_assert(sizeof(Scaleform::Render::D3D9::TextureManager) == 0x210, "TextureManager size");

#endif
