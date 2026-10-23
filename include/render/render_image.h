// Recovered Scaleform 4.1.18 Render: images, image data and the texture manager interface.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts and vftable orders are the exe's (MapleStory2 KMS2_DEV x64). This build keeps the AMP accounting virtuals
// (GetBytes / GetImageId / GetBaseImageId) and the per-image ids, so:
//   Image vftable (29 slots): ImageBase 0-13, CreateSubImage 14, GetUse 15, Set/GetMatrix 16-17,
//     Set/GetMatrixInverse 18-19, Map 20, Unmap 21, Update(ImageUpdate*) 22, Update() 23, GetTexture 24,
//     GetUVGenMatrix 25, GetUVNormMatrix 26, TextureLost 27, GetAsMemoryImage 28.
//   Texture (16 slots), TextureManager primary (18 slots, processTextureKillList at 14), ImageUpdateSync (3 slots).
// Sizes: Image 0x28, RawImage 0x70, TextureImage 0x40, SubImage 0x48, ImageData 0x40, Texture 0x48.
// Bodies live in sfr_render_01 (Render_Image section) unless noted.
#ifndef MS2_SF_RENDER_IMAGE_H
#define MS2_SF_RENDER_IMAGE_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_file.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_threadcommand.h"

namespace Scaleform { namespace Render {

class TextureManagerLocks;
class TextureManager;
class MemoryBufferImage;
class DepthStencilBuffer;
class DepthStencilSurface;
class RenderTargetData;
class MemoryManager;
class HAL;
class Texture;
class ImageBase;
class Image;
class ImageUpdate;

// Image format ids. Only the PC formats matter to this build; console ids keep their numeric slots.
enum ImageFormat
{
    Image_None          = 0,
    Image_R8G8B8A8      = 1,
    Image_B8G8R8A8      = 2,
    Image_R8G8B8        = 3,
    Image_B8G8R8        = 4,
    Image_A8            = 9,
    Image_R4G4B4A4      = 20,
    Image_DXT1          = 50,
    Image_DXT3          = 51,
    Image_DXT5          = 52,
    Image_PVRTC_RGB_4BPP,
    Image_PVRTC_RGBA_4BPP,
    Image_PVRTC_RGB_2BPP,
    Image_PVRTC_RGBA_2BPP,
    Image_ETC1_RGB_4BPP,
    Image_ETC1_RGBA_8BPP,
    Image_ATCIC,
    Image_ATCICA,
    Image_ATCICI,
    Image_Compressed_Start = Image_DXT1,
    Image_Compressed_End   = Image_ATCICI,
    Image_P8            = 100,
    Image_Y8_U2_V2      = 200,
    Image_Y8_U2_V2_A8   = 201,
    ImageFormat_Mask    = 0xFFF,
    Image_Begin_HWSpecific  = 0x1000,
    ImageFormat_Convertible = 0x100000
};

enum ImageFormatSupport
{
    ImageFormats_Standard = 0x0000,
    ImageFormats_DXT      = 0x0001
};

typedef Size<UInt32> ImageSize;
typedef Rect<UInt32> ImageRect;

ImageSize SF_STDCALL ImageSize_RoundUpPow2(ImageSize sz);
ImageSize SF_STDCALL ImageSize_NextMipSize(ImageSize sz);
unsigned  SF_STDCALL ImageSize_MipLevelCount(ImageSize sz);

// One plane of image memory (a mip level or a YUV component).
struct ImagePlane
{
    UInt32 Width, Height;
    UPInt  Pitch;
    UPInt  DataSize;
    UByte* pData;

    ImagePlane() : Width(0), Height(0), Pitch(0), DataSize(0), pData(0) {}
    ImagePlane(UInt32 w, UInt32 h, UPInt pitch, UPInt dataSize = 0, UByte* data = 0)
        : Width(w), Height(h), Pitch(pitch), DataSize(dataSize), pData(data) {}
    ImagePlane(const ImagePlane& o)
        : Width(o.Width), Height(o.Height), Pitch(o.Pitch), DataSize(o.DataSize), pData(o.pData) {}

    void SetData(UInt32 w, UInt32 h, UPInt pitch, UPInt dataSize = 0, UByte* data = 0)
    {
        Width = w; Height = h; Pitch = pitch; DataSize = dataSize; pData = data;
    }
    void SetData(const ImageSize& sz, UPInt pitch, UPInt dataSize = 0, UByte* data = 0)
    {
        Width = sz.Width; Height = sz.Height; Pitch = pitch; DataSize = dataSize; pData = data;
    }
    void operator=(const ImagePlane& o)
    {
        Width = o.Width; Height = o.Height; Pitch = o.Pitch; DataSize = o.DataSize; pData = o.pData;
    }
    ImageSize GetSize() const               { return ImageSize(Width, Height); }
    void      SetSize(const ImageSize& sz)  { Width = sz.Width; Height = sz.Height; }
    void      SetNextMipSize()
    {
        Width  = Alg::Max<UInt32>(1, Width / 2);
        Height = Alg::Max<UInt32>(1, Height / 2);
    }

    bool MatchSizes(const ImagePlane& o) const
    {
        return Width == o.Width && Height == o.Height && Pitch == o.Pitch && DataSize == o.DataSize;
    }

    void         GetMipLevel(ImageFormat format, unsigned level, ImagePlane* p, unsigned plane = 0) const;
    UByte*       GetScanline(unsigned y)       { return pData + Pitch * y; }
    const UByte* GetScanline(unsigned y) const { return pData + Pitch * y; }
};

enum ImageUse
{
    ImageUse_Wrap            = 0x0001,
    ImageUse_GenMipmaps      = 0x0002,
    ImageUse_Update          = 0x0010,
    ImageUse_PartialUpdate   = 0x0020,
    ImageUse_MapSimThread    = 0x0040,
    ImageUse_MapRenderThread = 0x0080,
    ImageUse_Map_Mask        = ImageUse_MapSimThread | ImageUse_MapRenderThread,
    ImageUse_ReadOnly_Mask   = ImageUse_Update | ImageUse_PartialUpdate | ImageUse_Map_Mask,
    ImageUse_InitOnly        = 0x0100,
    ImageUse_NoDataLoss      = ImageUse_InitOnly,
    ImageUse_RenderTarget    = 0x0400
};

// Color table of a palettized image; allocated with the colors inline.
class Palette
{
    mutable AtomicInt<int> RefCount;
protected:
    UInt16 ColorCount;
    bool   HasAlphaFlag;
    Color  Colors[1];
public:
    bool         HasAlpha() const      { return HasAlphaFlag; }
    unsigned     GetColorCount() const { return ColorCount; }
    const Color* GetColors() const     { return Colors; }
    Color&       operator[](unsigned i)       { return Colors[i]; }
    const Color& operator[](unsigned i) const { return Colors[i]; }

    void AddRef()  { RefCount.Increment_Sync(); }
    void Release() { if ((RefCount.ExchangeAdd_NoSync(-1) - 1) == 0) SF_FREE(this); }

    bool operator==(const Palette& o) const
    {
        return ColorCount == o.ColorCount && HasAlpha() == o.HasAlpha() &&
               memcmp(Colors, o.Colors, ColorCount * sizeof(Color)) == 0;
    }
    bool operator!=(const Palette& o) const { return !operator==(o); }

    static Palette* SF_STDCALL Create(unsigned colorCount, bool hasAlpha, MemoryHeap* heap = 0);
};

// Image memory description: format plus one or more planes (Plane0 inline for the single-plane case).
class ImageData
{
public:
    ImageFormat  Format;
    unsigned     Use;
    UByte        Flags;
    UByte        LevelCount;
    UInt16       RawPlaneCount;
    ImagePlane*  pPlanes;
    Ptr<Palette> pPalette;

    enum
    {
        Flag_SeparateMipmaps = 0x01,
        Flag_AllocPlanes     = 0x02,
        Flag_LocalHeap       = 0x04,
        Flag_ImageMapped     = 0x10
    };

private:
    ImagePlane Plane0;

    bool allocPlanes(ImageFormat format, unsigned mipLevelCount, bool separateMipmaps = false);
    void freePlanes();

public:
    ImageData() : Format(Image_None), Use(0), Flags(0), LevelCount(0), RawPlaneCount(1), pPlanes(&Plane0) {}
    ~ImageData() { freePlanes(); }

    ImageData& operator=(const ImageData& rhs);
    void       Clear();

    bool Initialize(ImageFormat format, unsigned mipLevels, bool separateMipmaps = false)
    {
        Clear();
        return allocPlanes(format, mipLevels, separateMipmaps);
    }
    void Initialize(ImageFormat format, unsigned mipLevels, ImagePlane* planes, unsigned planeCount,
                    bool separateMipmaps = false)
    {
        Clear();
        Format        = format;
        LevelCount    = (UByte)mipLevels;
        pPlanes       = planes;
        RawPlaneCount = (UInt16)planeCount;
        if (separateMipmaps)
            Flags |= Flag_SeparateMipmaps;
        if (planes && planeCount == 1)
            Plane0 = planes[0];
    }
    bool Initialize(const ImageData& source, unsigned levelIndex, unsigned levelCount);

    Palette*          GetColorMap() const                  { return pPalette.GetPtr(); }
    unsigned          GetPlaneCount() const;
    void              GetPlane(unsigned index, ImagePlane* plane) const;
    ImagePlane&       GetPlaneRef(unsigned plane = 0)       { return pPlanes[plane]; }
    const ImagePlane& GetPlaneRef(unsigned plane = 0) const { return pPlanes[plane]; }
    void SetPlane(unsigned plane, const ImageSize& sz, UPInt pitch, UPInt dataSize = 0, UByte* data = 0)
    {
        pPlanes[plane].SetData(sz, pitch, dataSize, data);
    }
    unsigned          GetMipLevelCount() const              { return LevelCount; }
    ImageFormat       GetFormat() const                     { return Format; }
    ImageFormat       GetFormatNoConv() const { return (ImageFormat)(Format & ~ImageFormat_Convertible); }
    bool              HasSeparateMipmaps() const            { return (Flags & Flag_SeparateMipmaps) != 0; }
    void              GetMipLevelPlane(unsigned level, unsigned plane, ImagePlane* p) const
    {
        GetPlane(level * GetFormatPlaneCount(Format) + plane, p);
    }
    bool              IsHWSpecific() const   { return GetFormatNoConv() >= Image_Begin_HWSpecific; }
    unsigned          GetBitsPerPixel(unsigned plane = 0) const { return GetFormatBitsPerPixel(Format, plane); }
    UPInt             GetPitch() const                      { return pPlanes[0].Pitch; }
    UInt32            GetWidth() const                      { return pPlanes[0].Width; }
    UInt32            GetHeight() const                     { return pPlanes[0].Height; }
    ImageSize         GetSize() const                       { return pPlanes[0].GetSize(); }
    UByte*            GetDataPtr() const                    { return pPlanes[0].pData; }
    UByte*            GetScanline(unsigned y)               { return pPlanes[0].GetScanline(y); }
    const UByte*      GetScanline(unsigned y) const         { return pPlanes[0].GetScanline(y); }

    UPInt ComputeHash() const;
    bool  operator==(const ImageData& other) const;

    void  SetPixelARGB(unsigned x, unsigned y, UInt32 color);
    void  SetPixelInScanline(UByte* line, unsigned x, UInt32 color);
    Color GetPixel(unsigned x, unsigned y) const;
    Color GetPixelInScanline(const UByte* line, unsigned x) const;

    void Read(File& file, UInt32 version);
    void Write(File& file, UInt32 version) const;

    static bool IsFormatCompressed(ImageFormat format)
    {
        unsigned base = format & ImageFormat_Mask;
        return base >= Image_Compressed_Start && base <= Image_Compressed_End;
    }
    static unsigned  SF_STDCALL GetFormatPlaneCount(ImageFormat fmt);
    static unsigned  SF_STDCALL GetFormatBitsPerPixel(ImageFormat fmt, unsigned plane = 0);
    static UPInt     SF_STDCALL GetFormatPitch(ImageFormat fmt, UInt32 width, unsigned plane = 0);
    static UPInt     SF_STDCALL GetFormatScanlineCount(ImageFormat fmt, UInt32 height, unsigned plane = 0);
    static ImageSize SF_STDCALL GetFormatPlaneSize(ImageFormat fmt, const ImageSize& sz, unsigned plane = 0);
    static UPInt     SF_STDCALL GetMipLevelSize(ImageFormat format, const ImageSize& sz, unsigned plane = 0);
    static UPInt     SF_STDCALL GetMipLevelsSize(ImageFormat format, const ImageSize& sz, unsigned levels,
                                                 unsigned plane = 0);
};

struct ImageSwizzlerContext;

// Pixel access for tiled/swizzled storage; the PC build only uses the linear default.
class ImageSwizzler
{
public:
    virtual ~ImageSwizzler() {}
    virtual void  Initialize(ImageSwizzlerContext&) {}
    virtual void  CacheScanline(ImageSwizzlerContext& ctx, unsigned y);
    virtual void  SetPixelInScanline(ImageSwizzlerContext& ctx, unsigned x, Color c);
    virtual void  SetPixelInScanline(ImageSwizzlerContext& ctx, unsigned x, UInt32 c);
    virtual Color GetPixelInScanline(ImageSwizzlerContext& ctx, unsigned x);
};

// Locks shared by a texture manager and its textures; outlives the manager while textures hold it.
class TextureManagerLocks : public RefCountBase<TextureManagerLocks, StatRender_TextureManager_Mem>
{
public:
    TextureManager* pManager;
    Lock            ImageLock;      // +0x18
    Mutex           TextureMutex;   // +0x40
    WaitCondition   TextureInitWC;

    TextureManagerLocks(TextureManager* manager) : pManager(manager) {}
    ~TextureManagerLocks() {}
};

// HAL-specific texture format description (opaque here).
struct TextureFormat
{
};

class Texture : public RefCountBase<Texture, StatRender_TextureManager_Mem>, public ListNode<Texture>
{
public:
    enum CreateState
    {
        State_InitPending,
        State_InitFailed,
        State_Valid,
        State_Lost,
        State_Dead
    };

    // (sfr_d3d9_01b) out of line in the exe, its HAL texture ctors call it
    SF_NOINLINE Texture(TextureManagerLocks* locks, const ImageSize& size, UByte mipLevels, UInt16 use, ImageBase* image)
        : ListNode<Texture>(), pManagerLocks(locks), pImage(image), ImgSize(size), State(State_InitPending), MipLevels(mipLevels),
          TextureCount(1), Use(use), TextureFlags(0)
    {
    }

    TextureManager* GetTextureManager() const { return pManagerLocks ? pManagerLocks->pManager : 0; }

    virtual Image*      GetImage() const = 0;
    virtual ImageFormat GetFormat() const = 0;
    ImageSize           GetSize() const              { return ImgSize; }
    unsigned            GetMipmapCount() const       { return (Use & ImageUse_GenMipmaps) ? 1 : MipLevels; }
    unsigned            GetTextureStageCount() const { return TextureCount; }

    virtual void GetUVGenMatrix(Matrix2F* mat) const
    {
        ImageSize sz = GetSize();
        *mat = Matrix2F::Scaling(1.0f / (float)sz.Width, 1.0f / (float)sz.Height);
    }
    virtual void ImageLost()
    {
        Lock::Locker guard(&pManagerLocks->ImageLock);
        pImage = 0;
    }
    virtual void LoseManager();
    virtual void LoseTextureData();
    virtual void ReleaseHWTextures(bool staging = true) = 0;
    virtual bool Map(ImageData* data, unsigned mipLevel = 0, unsigned levelCount = 0) = 0;
    virtual bool Unmap() = 0;
    virtual bool Copy(ImageData*) { return false; }
    virtual bool UpdateRenderTargetData(RenderTargetData*, HAL* = 0) { return false; }
    virtual bool UpdateStagingData(RenderTargetData*) { return false; }

    struct UpdateDesc
    {
        ImagePlane SourcePlane;
        ImageRect  DestRect;
        unsigned   PlaneIndex;
    };
    // declared (desc, ()) so the vftable holds Update() at 13 and Update(desc) at 14
    virtual bool Update(const UpdateDesc* updates, unsigned count = 1, unsigned mipLevel = 0) = 0;
    virtual bool Update() = 0;
    virtual UPInt GetBytes(int* memRegion) const
    {
        if (memRegion)
            *memRegion = 1;
        return ImageData::GetMipLevelSize(GetFormat(), GetSize());
    }

protected:
    Ptr<TextureManagerLocks> pManagerLocks;  // +0x20
public:
    ImageBase*  pImage;                      // +0x28
    ImageSize   ImgSize;                     // +0x30
    CreateState State;                       // +0x38
    UByte       MipLevels;
    UByte       TextureCount;
    UInt16      Use;
    UByte       TextureFlags;                // +0x40
};

class ImageUpdateSync
{
public:
    virtual ~ImageUpdateSync() {}
    virtual void UpdateImage(Image* image) = 0;
    virtual void UpdateImage(ImageUpdate* update) = 0;
};

class ImageUpdate : public RefCountBase<ImageUpdate, Stat_Default_Mem>
{
protected:
    Ptr<Image> pImage;
public:
    ImageUpdate(Image* image);
    Image*       GetImage() { return pImage; }
    virtual void HandleUpdate(TextureManager*) {}
};

// Pending image updates: Image* entries are tagged with bit 0, ImageUpdate* entries are not.
struct ImageUpdateQueue
{
    typedef ArrayConstPolicy<4, 4, false> UpdateShrinkPolicy;
    typedef UPInt                         UpdateRef;

    ArrayLH<UpdateRef, StatRender_TextureManager_Mem, UpdateShrinkPolicy> Queue;

    void Add(Image* image);
    void Add(ImageUpdate* update);
    ~ImageUpdateQueue();
    void ProcessUpdates(TextureManager* manager);
};

class TextureManager : public RefCountBase<TextureManager, StatRender_TextureManager_Mem>, public ImageUpdateSync
{
public:
    TextureManager();

    virtual Texture* CreateTexture(ImageFormat format, unsigned mipLevels, const ImageSize& size, unsigned use,
                                   ImageBase* image = 0, MemoryManager* manager = 0) = 0;          // 1
    virtual unsigned GetTextureFormatSupport() const { return ImageFormats_Standard; }               // 2
    virtual unsigned GetTextureUseCaps(ImageFormat format) = 0;                                      // 3
    virtual bool     IsNonPow2Supported(ImageFormat, UInt16) { return true; }                        // 4
    virtual DepthStencilSurface* CreateDepthStencilSurface(const ImageSize& size,
                                                           MemoryManager* manager = 0) = 0;          // 5
    virtual DepthStencilBuffer*  CreateDSBuffer(const ImageSize&, MemoryManager* = 0) { return 0; }  // 6
    virtual bool     CanCreateTextureCurrentThread() { return true; }                                // 7
    virtual void     ProcessQueues();                                                                // 8
    virtual void     BeginFrame() { ProcessQueues(); }                                               // 9
    virtual void     BeginScene() {}                                                                 // 10
    virtual void     EndScene() {}                                                                   // 11
    virtual void     UpdateImage(Image* image);
    virtual void     UpdateImage(ImageUpdate* update);
    virtual ImageFormat GetDrawableImageFormat() const { return Image_R8G8B8A8; }                    // 12
    virtual bool     IsDrawableImageFormat(ImageFormat format) const { return format == Image_R8G8B8A8; } // 13

protected:
    class ServiceCommand : public ThreadCommand
    {
        TextureManager* pManager;
    public:
        ServiceCommand(TextureManager* manager) : pManager(manager) {}
        virtual void Execute() { pManager->ProcessQueues(); }
    };

    ServiceCommand ServiceCommandInstance;      // +0x18

    TextureManager* getThis() { return this; }
    void            processImageUpdates() { ImageUpdates.ProcessUpdates(this); }
    virtual void    processTextureKillList() {}                                                      // 14
    virtual void    processInitTextures() {}                                                         // 15
    virtual const TextureFormat* getTextureFormat(ImageFormat format) const = 0;                     // 16
    const TextureFormat*         precreateTexture(ImageFormat format, unsigned use, ImageBase* image);
    virtual bool    isMappable(const TextureFormat* format) = 0;                                     // 17

    Ptr<TextureManagerLocks> pLocks;            // +0x30
    ImageUpdateQueue         ImageUpdates;      // +0x38
};

class ImageBase : public RefCountBaseV<Image, Stat_Image_Mem>
{
public:
    enum ImageType
    {
        Type_ImageBase,
        Type_Image,
        Type_RawImage,
        Type_GradientImage,
        Type_TextureImage,
        Type_SubImage,
        Type_DrawableImage,
        Type_Other
    };

    virtual ImageType   GetImageType() const { return Type_ImageBase; }                              // 3
    virtual ImageFormat GetFormat() const = 0;                                                       // 4
    virtual ImageSize   GetSize() const = 0;                                                         // 5
    virtual ImageRect   GetRect() const { return ImageRect(0, 0, GetSize()); }                       // 6
    virtual unsigned    GetMipmapCount() const = 0;                                                  // 7
    ImageFormat         GetFormatNoConv() const { return (ImageFormat)(GetFormat() & ~ImageFormat_Convertible); }

    typedef void (SF_STDCALL* CopyScanlineFunc)(UByte* dst, const UByte* src, UPInt size, Palette* colorMap,
                                                void* arg);
    static void SF_STDCALL CopyScanlineDefault(UByte* dst, const UByte* src, UPInt size, Palette*, void*);

    virtual bool   Decode(ImageData*, CopyScanlineFunc = CopyScanlineDefault, void* = 0) const { return false; } // 8
    virtual Image* GetAsImage() = 0;                                                                 // 9
    virtual bool   IsDelegate() const { return false; }                                              // 10
    virtual UPInt  GetBytes(int* memRegion) const;                                                   // 11
    virtual UInt32 GetImageId() const { return 0; }                                                  // 12
    virtual UInt32 GetBaseImageId() const { return 0; }                                              // 13

    static UInt32 SF_STDCALL GetNextImageId();
};

class Image : public ImageBase
{
protected:
    AtomicPtr<Texture> pTexture;        // +0x10
    ImageUpdateSync*   pUpdateSync;     // +0x18
    Matrix2F*          pInverseMatrix;  // +0x20

    void releaseTexture();
    void initTexture_NoAddRef(Texture* texture);

public:
    Image(Texture* texture = 0, ImageUpdateSync* sync = 0)
        : pTexture(texture), pUpdateSync(sync), pInverseMatrix(0)
    {
        if (texture)
            texture->AddRef();
    }
    virtual ~Image();

    static Image* SF_STDCALL Create(ImageFormat format, unsigned mipLevels, const ImageSize& size, unsigned use,
                                    MemoryHeap* heap = 0, TextureManager* manager = 0,
                                    ImageUpdateSync* updateSync = 0);

    virtual Image*      CreateSubImage(const ImageRect& rect, MemoryHeap* heap = Memory::GetGlobalHeap()); // 14
    virtual ImageType   GetImageType() const { return Type_Image; }
    virtual ImageFormat GetFormat() const = 0;
    virtual unsigned    GetUse() const = 0;                                                          // 15
    virtual ImageSize   GetSize() const = 0;
    virtual ImageRect   GetRect() const { return ImageRect(0, 0, GetSize()); }
    virtual void SetMatrix(const Matrix2F& mat, MemoryHeap* heap = 0);                               // 16
    virtual void GetMatrix(Matrix2F* mat) const;                                                     // 17
    virtual void SetMatrixInverse(const Matrix2F& mat, MemoryHeap* heap = 0);                        // 18
    virtual void GetMatrixInverse(Matrix2F* mat) const;                                              // 19
    virtual bool Map(ImageData*, unsigned = 0, unsigned = 0) { return false; }                       // 20
    virtual bool Unmap() { return false; }                                                           // 21
    virtual bool Decode(ImageData*, CopyScanlineFunc = CopyScanlineDefault, void* = 0) const { return false; }
    // declared ((), ImageUpdate*) so the vftable holds Update(ImageUpdate*) at 22 and Update() at 23
    virtual bool Update()
    {
        if (pUpdateSync)
        {
            pUpdateSync->UpdateImage(this);
            return true;
        }
        return false;
    }
    virtual bool Update(ImageUpdate* update)
    {
        if (pUpdateSync)
        {
            pUpdateSync->UpdateImage(update);
            return true;
        }
        return false;
    }
    virtual Texture* GetTexture(TextureManager*) { return pTexture; }                                // 24
    virtual void     GetUVGenMatrix(Matrix2F* mat, TextureManager* manager);                         // 25
    virtual void     GetUVNormMatrix(Matrix2F* mat, TextureManager* manager);                        // 26

    enum TextureLossReason
    {
        TLR_ManagerDestroyed,
        TLR_DeviceLost,
        TLR_SwappedOut
    };
    virtual void TextureLost(TextureLossReason reason)                                               // 27
    {
        if (reason == TLR_ManagerDestroyed)
            releaseTexture();
    }
    virtual MemoryBufferImage* GetAsMemoryImage() { return 0; }                                      // 28
};

struct ImageCreateArgs
{
    unsigned         Use;
    MemoryHeap*      pHeap;
    TextureManager*  pManager;
    ImageUpdateSync* pUpdateSync;
    ImageFormat      Format;

    ImageCreateArgs(ImageFormat format = Image_None, unsigned use = 0, MemoryHeap* heap = 0,
                    TextureManager* manager = 0, ImageUpdateSync* updateSync = 0)
        : Use(use), pHeap(heap), pManager(manager), pUpdateSync(updateSync), Format(format)
    {
    }
    MemoryHeap*      GetHeap() const       { return pHeap ? pHeap : Memory::GetGlobalHeap(); }
    ImageUpdateSync* GetUpdateSync() const { return pUpdateSync ? pUpdateSync : pManager; }
};

// An image that can only be decoded (file readers, wrappers); turned into a real Image on demand.
class ImageSource : public ImageBase
{
public:
    virtual bool   IsDecodeOnlyImageCompatible(const ImageCreateArgs& args);
    virtual Image* CreateCompatibleImage(const ImageCreateArgs& args);
};

// Image held in system memory.
class RawImage : public Image
{
    ImageData Data;     // +0x28
    UInt32    ImageId;  // +0x68
protected:
    RawImage() { ImageId = ImageBase::GetNextImageId(); }
public:
    ~RawImage();
    void freeData();

    static RawImage* SF_STDCALL Create(ImageFormat format, unsigned mipLevels, const ImageSize& size, unsigned use,
                                       MemoryHeap* heap = 0, ImageUpdateSync* updateSync = 0);

    bool GetImageData(ImageData* data);
    void SetImageData(ImageData* data);

    virtual ImageType   GetImageType() const   { return Type_RawImage; }
    virtual ImageFormat GetFormat() const      { return Data.Format; }
    virtual unsigned    GetUse() const         { return Data.Use; }
    virtual ImageSize   GetSize() const        { return Data.GetSize(); }
    virtual unsigned    GetMipmapCount() const { return Data.GetMipLevelCount(); }
    virtual bool        Map(ImageData* data, unsigned levelIndex = 0, unsigned levelCount = 0);
    virtual bool        Unmap();
    virtual bool        Decode(ImageData* dest, CopyScanlineFunc copyScanline = CopyScanlineDefault,
                               void* arg = 0) const;
    virtual Texture*    GetTexture(TextureManager* manager);
    virtual Image*      GetAsImage()           { return this; }
    virtual UInt32      GetImageId() const     { return ImageId; }
    virtual UInt32      GetBaseImageId() const { return 0; }
};

// Image whose only storage is a texture.
class TextureImage : public Image
{
    ImageFormat Format;   // +0x28
    ImageSize   Size;     // +0x2c
    unsigned    Use;      // +0x34
    UInt32      ImageId;  // +0x38
public:
    TextureImage(ImageFormat format, const ImageSize& size, unsigned use, Texture* texture = 0,
                 ImageUpdateSync* sync = 0);

    void RefreshCachedFormat()
    {
        if (pTexture)
        {
            Format = pTexture->GetFormat();
            Size   = pTexture->GetSize();
        }
    }

    virtual ImageType   GetImageType() const   { return Type_TextureImage; }
    virtual ImageFormat GetFormat() const      { return Format; }
    virtual unsigned    GetUse() const         { return Use; }
    virtual ImageSize   GetSize() const        { return Size; }
    virtual unsigned    GetMipmapCount() const { return pTexture ? pTexture->GetMipmapCount() : 1; }
    virtual bool        Map(ImageData* data, unsigned mipLevel, unsigned levelCount);
    virtual bool        Unmap();
    virtual void        TextureLost(TextureLossReason) { releaseTexture(); }
    virtual Image*      GetAsImage()           { return this; }
    virtual bool        Decode(ImageData* dest, CopyScanlineFunc copyScanline = CopyScanlineDefault,
                               void* arg = 0) const;
    virtual UPInt       GetBytes(int* memRegion) const;
    virtual UInt32      GetImageId() const     { return ImageId; }
    virtual UInt32      GetBaseImageId() const { return 0; }
};

// A rectangle of another image (shares its texture).
class SubImage : public Image
{
    Ptr<Image> pImage;    // +0x28
    ImageRect  SubRect;   // +0x30
    UInt32     ImageId;   // +0x40
public:
    SubImage(Image* image, const ImageRect& rect) : pImage(image), SubRect(rect)
    {
        ImageId = ImageBase::GetNextImageId();
    }

    virtual ImageType   GetImageType() const   { return Type_SubImage; }
    virtual ImageFormat GetFormat() const      { return pImage->GetFormat(); }
    virtual unsigned    GetUse() const         { return pImage->GetUse(); }
    virtual ImageSize   GetSize() const        { return pImage->GetSize(); }
    virtual unsigned    GetMipmapCount() const { return pImage->GetMipmapCount(); }
    virtual ImageRect   GetRect() const        { return SubRect; }
    virtual bool        Map(ImageData*, unsigned, unsigned) { return false; }
    virtual bool        Unmap()                { return false; }
    virtual bool        Decode(ImageData* dest, CopyScanlineFunc csf = CopyScanlineDefault, void* arg = 0) const
    {
        return pImage->Decode(dest, csf, arg);
    }
    virtual Texture*    GetTexture(TextureManager* manager)   { return pImage->GetTexture(manager); }
    virtual void        TextureLost(TextureLossReason reason) { pImage->TextureLost(reason); }
    Image*              GetBaseImage()         { return pImage; }
    virtual Image*      GetAsImage()           { return this; }
    virtual UPInt       GetBytes(int* memRegion) const { if (memRegion) *memRegion = 0; return 0; }
    virtual UInt32      GetImageId() const     { return ImageId; }
    virtual UInt32      GetBaseImageId() const { return pImage ? pImage->GetImageId() : 0; }
};


// An image source that hands out an existing image (0x18 bytes, vftable 0x143185228): everything forwards to
// pDelegate, and a compatible image is the delegate itself.
class WrapperImageSource : public ImageSource
{
protected:
    Ptr<Image> pDelegate;   // +0x10
public:
    WrapperImageSource(Image* pdelegate) : pDelegate(pdelegate) {}

    virtual ImageType   GetImageType() const   { return pDelegate->GetImageType(); }
    virtual ImageFormat GetFormat() const      { return pDelegate->GetFormat(); }
    virtual ImageSize   GetSize() const        { return pDelegate->GetSize(); }
    virtual unsigned    GetMipmapCount() const { return pDelegate->GetMipmapCount(); }
    virtual bool        Decode(ImageData* pdest, CopyScanlineFunc copyScanline = CopyScanlineDefault,
                               void* arg = 0) const
    {
        return pDelegate->Decode(pdest, copyScanline, arg);
    }
    virtual Image* CreateCompatibleImage(const ImageCreateArgs& args)
    {
        if (IsDecodeOnlyImageCompatible(args))
        {
            pDelegate->AddRef();
            return pDelegate;
        }
        return ImageSource::CreateCompatibleImage(args);
    }
    virtual Image*      GetAsImage()                   { return pDelegate; }
    virtual UPInt       GetBytes(int* memRegion) const { return pDelegate->GetBytes(memRegion); }
    virtual UInt32      GetImageId() const             { return pDelegate->GetImageId(); }
    virtual UInt32      GetBaseImageId() const         { return pDelegate->GetBaseImageId(); }
};

// An image that forwards everything to another image (pImage, +0x28); GetImageType answers for the wrapped image,
// IsDelegate tells the two apart. Its inline members are emitted with the AS2 units (0x142442..0x142447).
class ImageDelegate : public Image
{
public:
    Ptr<Image> pImage;  // +0x28

    ImageDelegate() {}
    ImageDelegate(Image* img) : pImage(img) {}

    virtual ImageType   GetImageType() const   { return pImage->GetImageType(); }
    virtual ImageFormat GetFormat() const      { return pImage->GetFormat(); }
    virtual ImageSize   GetSize() const        { return pImage->GetSize(); }
    virtual ImageRect   GetRect() const        { return pImage->GetRect(); }
    virtual unsigned    GetMipmapCount() const { return pImage->GetMipmapCount(); }

    virtual void SetMatrix(const Matrix2F& mat, MemoryHeap* heap = 0)        { pImage->SetMatrix(mat, heap); }
    virtual void GetMatrix(Matrix2F* mat) const                              { pImage->GetMatrix(mat); }
    virtual void SetMatrixInverse(const Matrix2F& mat, MemoryHeap* heap = 0) { pImage->SetMatrixInverse(mat, heap); }
    virtual void GetMatrixInverse(Matrix2F* mat) const                       { pImage->GetMatrixInverse(mat); }
    virtual void GetUVGenMatrix(Matrix2F* mat, TextureManager* manager)      { pImage->GetUVGenMatrix(mat, manager); }
    virtual void GetUVNormMatrix(Matrix2F* mat, TextureManager* manager)     { pImage->GetUVNormMatrix(mat, manager); }

    virtual bool Decode(ImageData* pdest, CopyScanlineFunc copyScanline = CopyScanlineDefault, void* arg = 0) const
    {
        return pImage->Decode(pdest, copyScanline, arg);
    }

    virtual unsigned GetUse() const { return pImage->GetUse(); }
    virtual Image*   CreateSubImage(const ImageRect& rect, MemoryHeap* heap = Memory::GetGlobalHeap())
    {
        return pImage->CreateSubImage(rect, heap);
    }
    virtual bool Map(ImageData* data, unsigned levelIndex = 0, unsigned levelCount = 0)
    {
        return pImage->Map(data, levelIndex, levelCount);
    }
    virtual bool     Unmap()                               { return pImage->Unmap(); }
    virtual Texture* GetTexture(TextureManager* manager)   { return pImage->GetTexture(manager); }
    virtual void     TextureLost(TextureLossReason reason) { pImage->TextureLost(reason); }
    virtual bool     Update()                              { return pImage->Update(); }
    virtual bool     Update(ImageUpdate* update)           { return pImage->Update(update); }

    virtual Image*             GetAsImage()       { return pImage; }
    virtual MemoryBufferImage* GetAsMemoryImage() { return pImage->GetAsMemoryImage(); }
    virtual bool               IsDelegate() const { return true; }

    virtual UPInt  GetBytes(int* memRegion) const { return pImage->GetBytes(memRegion); }
    virtual UInt32 GetImageId() const             { return pImage->GetImageId(); }
    virtual UInt32 GetBaseImageId() const         { return pImage->GetBaseImageId(); }
};

}} // namespace Scaleform::Render

#endif
