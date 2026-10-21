// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, images (Render_Image).
// Queue unit sfr_render_01 is split along its original sources: this file is Render_Image, sfr_render_01b holds
// Render_Context / Renderer2D, sfr_render_01c Text_StyledText. The remaining ranges (Filters, ImageFile, and
// FontResource::GetName at 0x14259d950) stay here until their own files are written.
// MS2-UNIT: sfr_render_01
// MS2-FLAGS: scaleform
// The Render_Image TU starts at 0x1425792d0 (TextureImage / TextureManager ctors), inside the queue range of
// sfr_gfx_01, and runs to 0x14257db40; 0x14257db40-0x14257dc30 are the out-of-line SF_RefCount dtors (SF_RefCount
// starts there, sfr_kernel_01).
// MS2-RANGE: 0x1425792d0-0x14257db40 .text$mn
// MS2-RANGE: 0x1424789e0-0x142478f10 .text$mn
// MS2-RANGE: 0x142479130-0x14247a8f0 .text$mn
// MS2-RANGE: 0x142591050-0x142591e10 .text$mn
// MS2-RANGE: 0x14259d950-0x14259d960 .text$mn

#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_drawableimage.h"

namespace Scaleform { namespace Render {

// ---------------------------------------------------------------- image sizes

// @0x14257c590
ImageSize SF_STDCALL ImageSize_RoundUpPow2(ImageSize sz)
{
    ImageSize result(1);
    while (result.Width < sz.Width)
        result.Width <<= 1;
    while (result.Height < sz.Height)
        result.Height <<= 1;
    return result;
}

ImageSize SF_STDCALL ImageSize_NextMipSize(ImageSize sz)
{
    sz.Width  = Alg::Max<UInt32>(1, sz.Width / 2);
    sz.Height = Alg::Max<UInt32>(1, sz.Height / 2);
    return sz;
}

// @0x14257c520
unsigned SF_STDCALL ImageSize_MipLevelCount(ImageSize sz)
{
    unsigned count = 1;
    while (sz.Width > 1 && sz.Height > 1)
    {
        sz = ImageSize_NextMipSize(sz);
        count++;
    }
    return count;
}

// ---------------------------------------------------------------- planes and palettes

// @0x14257ba90
void ImagePlane::GetMipLevel(ImageFormat format, unsigned level, ImagePlane* p, unsigned plane) const
{
    *p = *this;
    UPInt levelSize = 0, skipped = 0;

    for (unsigned i = level; i != 0; i--)
    {
        UPInt size = ImageData::GetMipLevelSize(format, p->GetSize(), plane);
        p->pData += size;
        p->SetNextMipSize();
        p->Pitch = ImageData::GetFormatPitch(format, p->Width, plane);
        skipped += size;
    }
    p->DataSize = DataSize - skipped + levelSize;
}

// @0x14257a4a0
Palette* SF_STDCALL Palette::Create(unsigned colorCount, bool hasAlpha, MemoryHeap* heap)
{
    if (!heap)
        heap = Memory::GetGlobalHeap();
    Palette* palette = (Palette*)SF_HEAP_ALLOC(heap, sizeof(Palette) + (colorCount - 1) * sizeof(Color),
                                               Stat_Default_Mem);
    if (palette)
    {
        palette->RefCount     = 1;
        palette->ColorCount   = (UInt16)colorCount;
        palette->HasAlphaFlag = hasAlpha;
        memset(palette->Colors, 0, sizeof(Color) * colorCount);
    }
    return palette;
}

// ---------------------------------------------------------------- ImageData

// @0x14257d860
bool ImageData::allocPlanes(ImageFormat format, unsigned mipLevelCount, bool separateMipmaps)
{
    unsigned formatPlanes = GetFormatPlaneCount(format);
    unsigned planeCount   = formatPlanes * (separateMipmaps ? mipLevelCount : 1);

    if (planeCount > 1)
    {
        MemoryHeap* heap = (Flags & Flag_LocalHeap) ? Memory::GetHeapByAddress(this) : Memory::GetGlobalHeap();
        pPlanes = (ImagePlane*)SF_HEAP_ALLOC(heap, sizeof(ImagePlane) * planeCount, Stat_Default_Mem);
        if (!pPlanes)
        {
            RawPlaneCount = 1;
            pPlanes       = &Plane0;
            return false;
        }
        memset(pPlanes, 0, sizeof(ImagePlane) * planeCount);
        Flags |= Flag_AllocPlanes;
    }

    Format        = format;
    RawPlaneCount = (UInt16)planeCount;
    LevelCount    = (UByte)mipLevelCount;
    if (separateMipmaps)
        Flags |= Flag_SeparateMipmaps;
    return true;
}

// @0x14257d9d0
void ImageData::freePlanes()
{
    if (Flags & Flag_AllocPlanes)
    {
        Flags &= ~Flag_AllocPlanes;
        SF_FREE(pPlanes);
    }
    pPlanes = &Plane0;
}

// @0x142579610
ImageData& ImageData::operator=(const ImageData& rhs)
{
    freePlanes();

    Format        = rhs.Format;
    Use           = rhs.Use;
    Flags         = rhs.Flags;
    LevelCount    = rhs.LevelCount;
    RawPlaneCount = rhs.RawPlaneCount;
    pPalette      = rhs.pPalette;
    Plane0        = rhs.Plane0;

    if (rhs.Flags & Flag_AllocPlanes)
    {
        // the copy owns its own plane table; the pixel memory stays shared
        Flags &= ~Flag_AllocPlanes;
        allocPlanes(Format, LevelCount, (Flags & Flag_SeparateMipmaps) != 0);
        for (UInt16 i = 0; i < rhs.RawPlaneCount; i++)
        {
            const ImagePlane& src = rhs.pPlanes[i];
            SetPlane(i, ImageSize(src.Width, src.Height), src.Pitch, src.DataSize, src.pData);
        }
    }
    else
    {
        pPlanes = &Plane0;
    }
    return *this;
}

// @0x14257a0e0
void ImageData::Clear()
{
    freePlanes();
    Format        = Image_None;
    Use           = 0;
    Flags         = (UByte)(Flags & ~Flag_LocalHeap);
    LevelCount    = 0;
    RawPlaneCount = 1;
    pPalette.Clear();
    Plane0.SetData(0, 0, 0);
}

// Points this at levels [levelIndex, levelIndex + levelCount) of source. Separate mipmaps (or the base level)
// share the source's planes; packed mipmaps get planes of their own pointing into the source data.
// @0x14257c5c0
bool ImageData::Initialize(const ImageData& source, unsigned levelIndex, unsigned levelCount)
{
    if (levelCount == 0)
        levelCount = source.LevelCount - levelIndex;

    if (levelIndex == 0 || (source.Flags & Flag_SeparateMipmaps))
    {
        unsigned formatPlanes = GetFormatPlaneCount(source.Format);
        unsigned planeCount   = ((source.Flags & Flag_SeparateMipmaps) ? levelCount : 1) * formatPlanes;
        Initialize(source.Format, levelCount, source.pPlanes + levelIndex * formatPlanes, planeCount,
                   (source.Flags & Flag_SeparateMipmaps) != 0);
        return true;
    }

    if (!Initialize(source.Format, levelCount, false))
        return false;

    for (unsigned i = 0; i < source.RawPlaneCount; i++)
        source.GetPlaneRef(i).GetMipLevel(source.Format, levelIndex, &GetPlaneRef(i), i);
    return true;
}

// @0x14257c0c0
unsigned ImageData::GetPlaneCount() const
{
    return RawPlaneCount * ((Flags & Flag_SeparateMipmaps) ? LevelCount : 1);
}

// Plane indexes past RawPlaneCount address the mip levels packed into the raw planes.
// @0x14257c050
void ImageData::GetPlane(unsigned index, ImagePlane* plane) const
{
    if (index < RawPlaneCount)
    {
        *plane = GetPlaneRef(index);
        return;
    }
    unsigned level    = index / RawPlaneCount;
    unsigned rawPlane = index % RawPlaneCount;
    GetPlaneRef(rawPlane).GetMipLevel(Format, level, plane, rawPlane);
}

// @0x14257d240
void ImageData::SetPixelARGB(unsigned x, unsigned y, UInt32 color)
{
    if (x >= GetWidth() || y >= GetHeight() || Format >= Image_Compressed_Start)
        return;
    SetPixelInScanline(GetScanline(y), x, color);
}

// @0x14257d390
void ImageData::SetPixelInScanline(UByte* line, unsigned x, UInt32 color)
{
    switch (Format)
    {
    case Image_B8G8R8A8:
        *(line + x * 4 + 0) = (UByte)color;
        *(line + x * 4 + 1) = (UByte)(color >> 8);
        *(line + x * 4 + 2) = (UByte)(color >> 16);
        *(line + x * 4 + 3) = (UByte)(color >> 24);
        break;
    case Image_R8G8B8A8:
        *(line + x * 4 + 0) = (UByte)(color >> 16);
        *(line + x * 4 + 1) = (UByte)(color >> 8);
        *(line + x * 4 + 2) = (UByte)color;
        *(line + x * 4 + 3) = (UByte)(color >> 24);
        break;
    case Image_R8G8B8:
        // packed 24-bit RGB whatever the CPU byte order
        *(line + x * 3 + 0) = (UByte)(color >> 16);
        *(line + x * 3 + 1) = (UByte)(color >> 8);
        *(line + x * 3 + 2) = (UByte)color;
        break;
    case Image_B8G8R8:
        *(line + x * 3 + 0) = (UByte)color;
        *(line + x * 3 + 1) = (UByte)(color >> 8);
        *(line + x * 3 + 2) = (UByte)(color >> 16);
        break;
    case Image_A8:
        *(line + x) = (UByte)(color >> 24);
        break;
    default:
        break;
    }
}

// @0x14257be60
Color ImageData::GetPixel(unsigned x, unsigned y) const
{
    if (x >= GetWidth() || y >= GetHeight() || Format >= Image_Compressed_Start)
        return 0;
    return GetPixelInScanline(GetScanline(y), x);
}

// The 24-bit cases step by 4 bytes and B8G8R8 runs on into A8: kept as the exe has them.
// @0x14257bf70
Color ImageData::GetPixelInScanline(const UByte* line, unsigned x) const
{
    Color color;
    switch (Format)
    {
    case Image_B8G8R8A8:
        color.SetRGBA(*(line + x * 4 + 2), *(line + x * 4 + 1), *(line + x * 4 + 0), *(line + x * 4 + 3));
        break;
    case Image_R8G8B8A8:
        color.SetRGBA(*(line + x * 4 + 0), *(line + x * 4 + 1), *(line + x * 4 + 2), *(line + x * 4 + 3));
        break;
    case Image_R8G8B8:
        color.SetRGBA(*(line + x * 4 + 0), *(line + x * 4 + 1), *(line + x * 4 + 2), 0xFF);
        break;
    case Image_B8G8R8:
        color.SetRGBA(*(line + x * 4 + 2), *(line + x * 4 + 1), *(line + x * 4 + 0), 0xFF);
    case Image_A8:
        color.SetRGBA(0xFF, 0xFF, 0xFF, *(line + x * 4 + 0));
        break;
    default:
        break;
    }
    return color;
}

// Plane memory read here belongs to the caller.
// @0x14257cd00
void ImageData::Read(File& file, UInt32 version)
{
    SF_UNUSED(version);
    freePlanes();

    Format        = (ImageFormat)file.ReadSInt32();
    Use           = file.ReadUInt32();
    Flags         = (UByte)(file.ReadUByte() & ~Flag_AllocPlanes);
    LevelCount    = file.ReadUByte();
    RawPlaneCount = file.ReadUInt16();

    allocPlanes(Format, LevelCount, (Flags & Flag_SeparateMipmaps) != 0);
    for (UInt16 i = 0; i < RawPlaneCount; i++)
    {
        UInt32    width  = file.ReadUInt32();
        UInt32    height = file.ReadUInt32();
        ImageSize size(width, height);
        UInt32    pitch    = file.ReadUInt32();
        UInt32    dataSize = file.ReadUInt32();
        UByte*    data     = (UByte*)SF_ALLOC(dataSize, Stat_Image_Mem);
        pPlanes[i].SetData(size.Width, size.Height, pitch, dataSize, data);
        for (UPInt j = 0; j < pPlanes[i].DataSize; j++)
            pPlanes[i].pData[j] = file.ReadUByte();
    }

    UInt16 colorCount = file.ReadUInt16();
    if (colorCount > 0)
    {
        bool hasAlpha = file.ReadUByte() != 0;
        pPalette = Palette::Create(colorCount, hasAlpha);
        for (UInt16 i = 0; i < colorCount; i++)
            (*pPalette)[i] = Color(file.ReadUInt32());
    }
    else
    {
        pPalette = 0;
    }
}

// @0x14257d620
void ImageData::Write(File& file, UInt32 version) const
{
    SF_UNUSED(version);

    file.WriteSInt32(Format);
    file.WriteUInt32(Use);
    file.WriteUByte(Flags);
    file.WriteUByte(LevelCount);
    file.WriteUInt16(RawPlaneCount);
    for (UInt16 i = 0; i < RawPlaneCount; i++)
    {
        file.WriteUInt32(pPlanes[i].Width);
        file.WriteUInt32(pPlanes[i].Height);
        file.WriteUInt32((UInt32)pPlanes[i].Pitch);
        file.WriteUInt32((UInt32)pPlanes[i].DataSize);
        for (UPInt j = 0; j < pPlanes[i].DataSize; j++)
            file.WriteUByte(pPlanes[i].pData[j]);
    }

    if (pPalette)
    {
        file.WriteUInt16((UInt16)pPalette->GetColorCount());
        file.WriteUByte(pPalette->HasAlpha() ? 1 : 0);
        for (unsigned i = 0; i < pPalette->GetColorCount(); i++)
            file.WriteUInt32((*pPalette)[i].ToColor32());
    }
    else
    {
        file.WriteUInt16(0);
    }
}

// Bernstein's string hash run backwards over a buffer.
static SF_INLINE UPInt ImageData_Hash(const void* dataIn, UPInt size, UPInt seed = 5381)
{
    const UByte* data = (const UByte*)dataIn;
    UPInt        h    = seed;
    while (size > 0)
    {
        size--;
        h = ((h << 5) + h) ^ (unsigned)data[size];
    }
    return h;
}

// Hash of the layout and pixel bytes; 0 if a plane has no data.
// @0x14257a180
UPInt ImageData::ComputeHash() const
{
    UPInt h = ImageData_Hash(&RawPlaneCount, sizeof(RawPlaneCount));
    for (unsigned i = 0; i < RawPlaneCount; i++)
    {
        ImagePlane& plane = pPlanes[i];
        h = ImageData_Hash(&plane.Width, sizeof(plane.Width), h);
        h = ImageData_Hash(&plane.Height, sizeof(plane.Height), h);
        h = ImageData_Hash(&plane.Pitch, sizeof(plane.Pitch), h);
        h = ImageData_Hash(&plane.DataSize, sizeof(plane.DataSize), h);
        if (!plane.pData)
            return 0;
        h = ImageData_Hash(plane.pData, plane.DataSize, h);
    }
    return h;
}

// Flags are not compared.
// @0x142579780
bool ImageData::operator==(const ImageData& other) const
{
    if (Format != other.Format || Use != other.Use || LevelCount != other.LevelCount ||
        RawPlaneCount != other.RawPlaneCount)
        return false;

    unsigned i;
    if (pPalette)
    {
        if (!other.pPalette || *pPalette != *other.pPalette)
            return false;
    }
    else
    {
        if (other.pPalette)
            return false;
    }

    for (i = 0; i < RawPlaneCount; i++)
    {
        if (!pPlanes[i].MatchSizes(other.pPlanes[i]))
            return false;
    }
    // pixel bytes last
    for (i = 0; i < RawPlaneCount; i++)
    {
        if (memcmp(pPlanes[i].pData, other.pPlanes[i].pData, pPlanes[i].DataSize))
            return false;
    }
    return true;
}

// @0x14257b8a0
unsigned ImageData::GetFormatPlaneCount(ImageFormat fmt)
{
    switch (fmt & ImageFormat_Mask)
    {
    case Image_None:
        return 0;
    case Image_Y8_U2_V2:
        return 3;
    case Image_Y8_U2_V2_A8:
        return 4;
    default:
        return 1;
    }
}

// @0x14257b600
unsigned ImageData::GetFormatBitsPerPixel(ImageFormat fmt, unsigned plane)
{
    SF_UNUSED(plane);
    switch (fmt & ImageFormat_Mask)
    {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
        return 32;
    case Image_R8G8B8:
    case Image_B8G8R8:
        return 24;
    case Image_DXT1:
        return 16;
    case Image_A8:
    case Image_P8:
    case Image_Y8_U2_V2:
    case Image_Y8_U2_V2_A8:
        return 8;
    case Image_DXT3:
    case Image_DXT5:
        return 32;
    case Image_PVRTC_RGB_2BPP:
    case Image_PVRTC_RGBA_2BPP:
        return 2;
    case Image_PVRTC_RGB_4BPP:
    case Image_PVRTC_RGBA_4BPP:
    case Image_ETC1_RGB_4BPP:
        return 4;
    default:
        break;
    }
    return 0;
}

// Formats without a linear pitch return 0.
// No ATC cases in 4.1.18: those formats fall to the zero pitch.
// @0x14257b740
UPInt ImageData::GetFormatPitch(ImageFormat fmt, UInt32 width, unsigned plane)
{
    SF_UNUSED(plane);
    switch (fmt & ImageFormat_Mask)
    {
    case Image_A8:
    case Image_P8:
    case Image_Y8_U2_V2:
    case Image_Y8_U2_V2_A8:
        return width;
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
        return width * 4;
    case Image_R8G8B8:
    case Image_B8G8R8:
        return (width * 3 + 3) & ~3;
    case Image_DXT1:
        return 8 * ((width + 3) / 4);    // 64 bits per 4x4 block
    case Image_DXT3:
    case Image_DXT5:
        return 16 * ((width + 3) / 4);   // 128 bits per 4x4 block
    case Image_PVRTC_RGB_2BPP:
    case Image_PVRTC_RGBA_2BPP:
        return width / 4;
    case Image_PVRTC_RGB_4BPP:
    case Image_PVRTC_RGBA_4BPP:
    case Image_ETC1_RGB_4BPP:
        return width / 2;
    default:
        break;
    }
    return 0;
}

// @0x14257b910
UPInt ImageData::GetFormatScanlineCount(ImageFormat fmt, UInt32 height, unsigned plane)
{
    SF_UNUSED(plane);
    switch (fmt & ImageFormat_Mask)
    {
    case Image_DXT1:
    case Image_DXT3:
    case Image_DXT5:
        return (height + 3) / 4;
    default:
        break;
    }
    return height;
}

// The chroma planes of the YUV formats are half size.
// @0x14257b8d0
ImageSize ImageData::GetFormatPlaneSize(ImageFormat fmt, const ImageSize& sz, unsigned plane)
{
    switch (fmt & ImageFormat_Mask)
    {
    case Image_Y8_U2_V2:
    case Image_Y8_U2_V2_A8:
        if (plane == 1 || plane == 2)
            return ImageSize(sz.Width / 2, sz.Height / 2);
        break;
    default:
        break;
    }
    return sz;
}

// @0x14257bc00
UPInt ImageData::GetMipLevelSize(ImageFormat format, const ImageSize& sz, unsigned plane)
{
    UPInt    size;
    unsigned fmt = unsigned(format) & ImageFormat_Mask;
    if (fmt == Image_DXT1)
        size = Alg::Max<UInt32>(1u, (sz.Width + 3) / 4) * Alg::Max<UInt32>(1u, (sz.Height + 3) / 4) * 8;
    else if (fmt >= Image_DXT3 && fmt <= Image_DXT5)
        size = Alg::Max<UInt32>(1u, (sz.Width + 3) / 4) * Alg::Max<UInt32>(1u, (sz.Height + 3) / 4) * 16;
    else
        size = GetFormatPitch(format, sz.Width, plane) * sz.Height;
    return size;
}

// @0x14257bc90
UPInt ImageData::GetMipLevelsSize(ImageFormat format, const ImageSize& sz, unsigned levels, unsigned plane)
{
    UPInt     total = 0;
    ImageSize size(sz);
    for (unsigned i = levels; i != 0; i--)
    {
        total += GetMipLevelSize(format, size, plane);
        size = ImageSize_NextMipSize(size);
    }
    return total;
}

// ---------------------------------------------------------------- ImageBase / Image

// @0x14257a330
void SF_STDCALL ImageBase::CopyScanlineDefault(UByte* dst, const UByte* src, UPInt size, Palette*, void*)
{
    memcpy(dst, src, size);
}

// @0x14257b4f0
UPInt ImageBase::GetBytes(int* memRegion) const
{
    if (memRegion)
        *memRegion = 0;
    return ImageData::GetMipLevelSize(GetFormat(), GetSize());
}

// @0x14257bdc0
UInt32 SF_STDCALL ImageBase::GetNextImageId()
{
    static Lock   idLock;
    static UInt32 nextId = 0;

    Lock::Locker guard(&idLock);
    return ++nextId;
}

// @0x142579470
Image::~Image()
{
    releaseTexture();
    if (pInverseMatrix)
        SF_FREE(pInverseMatrix);
}

// @0x14257db10
void Image::releaseTexture()
{
    Texture* texture = pTexture.Exchange_NoSync(0);
    if (texture)
    {
        texture->ImageLost();
        texture->Release();
    }
}

// @0x14257da20
void Image::initTexture_NoAddRef(Texture* texture)
{
    pTexture = texture;
}

// A texture-only image when the manager can create init-only textures with matching map flags, otherwise a
// RawImage; the texture is created right away when the manager allows it on this thread.
// @0x14257a340
Image* SF_STDCALL Image::Create(ImageFormat format, unsigned mipLevels, const ImageSize& size, unsigned use,
                                MemoryHeap* heap, TextureManager* manager, ImageUpdateSync* updateSync)
{
    if (!heap)
        heap = Memory::GetGlobalHeap();
    if (!updateSync)
        updateSync = manager;

    Image* image = 0;

    if (use & ImageUse_GenMipmaps)
    {
        if (mipLevels != 1)
            return 0;
    }

    if (manager && !manager->CanCreateTextureCurrentThread())
        manager = 0;

    if (manager)
    {
        unsigned caps = manager->GetTextureUseCaps(format);
        if ((caps & ImageUse_InitOnly) && ((use & ImageUse_Map_Mask) == (caps & ImageUse_Map_Mask)))
            image = SF_HEAP_NEW(heap) TextureImage(format, size, use, 0, updateSync);
    }

    if (!image)
    {
        image = RawImage::Create(format, mipLevels, size, use, heap, updateSync);
        if (!image)
            return 0;
    }

    if (manager)
    {
        Texture* texture = manager->CreateTexture(format, mipLevels, size, use, image);
        if (!texture)
        {
            image->Release();
            return 0;
        }
        image->initTexture_NoAddRef(texture);
    }
    return image;
}

// @0x14257aa60
Image* Image::CreateSubImage(const ImageRect& rect, MemoryHeap* heap)
{
    return SF_HEAP_NEW(heap) SubImage(this, rect);
}

// The image stores the inverse; SetMatrix inverts on the way in.
// @0x14257d120
void Image::SetMatrix(const Matrix2F& mat, MemoryHeap* heap)
{
    if (!pInverseMatrix)
    {
        pInverseMatrix = (Matrix2F*)SF_HEAP_MEMALIGN(heap ? heap : Memory::GetHeapByAddress(this),
                                                     sizeof(Matrix2F), 16, Stat_Image_Mem);
    }
    *pInverseMatrix = mat;
    pInverseMatrix->Invert();
}

// @0x14257d1b0
void Image::SetMatrixInverse(const Matrix2F& mat, MemoryHeap* heap)
{
    if (!pInverseMatrix)
    {
        pInverseMatrix = (Matrix2F*)SF_HEAP_MEMALIGN(heap ? heap : Memory::GetHeapByAddress(this),
                                                     sizeof(Matrix2F), 16, Stat_Image_Mem);
    }
    *pInverseMatrix = mat;
}

// @0x14257b9b0
void Image::GetMatrix(Matrix2F* mat) const
{
    if (pInverseMatrix)
    {
        *mat = *pInverseMatrix;
        mat->Invert();
    }
    else
    {
        mat->SetIdentity();
    }
}

// @0x14257ba20
void Image::GetMatrixInverse(Matrix2F* mat) const
{
    if (pInverseMatrix)
        *mat = *pInverseMatrix;
    else
        mat->SetIdentity();
}

// @0x14257c210
void Image::GetUVGenMatrix(Matrix2F* mat, TextureManager* manager)
{
    Texture* texture = GetTexture(manager);
    if (texture)
    {
        if (pInverseMatrix)
        {
            Matrix2F uvGen(NoInit);
            texture->GetUVGenMatrix(&uvGen);
            mat->SetToAppend(*pInverseMatrix, uvGen);
        }
        else
        {
            texture->GetUVGenMatrix(mat);
        }
        ImageRect r = GetRect();
        mat->PrependTranslation((float)r.x1, (float)r.y1);
    }
    else
    {
        mat->SetIdentity();
    }
}

// MS2-FUNCTIONAL: the exe has a /GS cookie and a 0xa0 frame here that this source does not produce; the arithmetic is the same
// @0x14257c310
void Image::GetUVNormMatrix(Matrix2F* mat, TextureManager* manager)
{
    Texture* texture = GetTexture(manager);
    if (texture)
    {
        texture->GetUVGenMatrix(mat);
        ImageRect r = GetRect();
        mat->PrependTranslation((float)r.x1, (float)r.y1);
    }
    else
    {
        mat->SetIdentity();
    }

    ImageSize s = GetRect().GetSize();
    mat->PrependScaling((float)s.Width, (float)s.Height);
}

// ---------------------------------------------------------------- ImageSource

// True when the decoded image must stay in memory: no init-only texture can take the data, or the caller
// asked for mapping.
// @0x14257c830
bool ImageSource::IsDecodeOnlyImageCompatible(const ImageCreateArgs& args)
{
    if (args.pManager)
    {
        unsigned caps = args.pManager->GetTextureUseCaps(GetFormat());
        if ((args.Use & ImageUse_Map_Mask) == (args.Use & caps & ImageUse_Map_Mask))
        {
            if (caps & ImageUse_NoDataLoss)
                return false;
        }
    }
    if (args.Use & ImageUse_Map_Mask)
        return false;
    return true;
}

// MS2-FUNCTIONAL: register allocation only (this/args in rsi/r14 and format/heap in rbp/r15 swapped against the exe)
// @0x14257a7e0
Image* ImageSource::CreateCompatibleImage(const ImageCreateArgs& args)
{
    ImageFormat      format     = (args.Format == Image_None) ? GetFormat() : args.Format;
    ImageUpdateSync* updateSync = args.GetUpdateSync();
    MemoryHeap*      heap       = args.pHeap ? args.pHeap : Memory::GetGlobalHeap();

    unsigned imageUse    = args.Use;
    unsigned mipmapCount = GetMipmapCount();
    if (mipmapCount > 1)
        imageUse &= ~ImageUse_GenMipmaps;

    if (args.pManager)
    {
        unsigned caps = args.pManager->GetTextureUseCaps(format);
        if ((args.Use & ImageUse_Map_Mask) == (args.Use & caps & ImageUse_Map_Mask))
        {
            if (caps & ImageUse_NoDataLoss)
            {
                // init-only either way: created now, or the RawImage below frees its data once the render
                // thread has made the texture
                imageUse |= ImageUse_InitOnly;
                if (args.pManager->CanCreateTextureCurrentThread())
                {
                    Ptr<Texture> texture =
                        *args.pManager->CreateTexture(format, mipmapCount, GetSize(), imageUse, this);
                    if (texture)
                        return SF_HEAP_NEW(heap) TextureImage(format, GetSize(), imageUse, texture, updateSync);
                    return 0;
                }
            }
        }
    }

    RawImage* rawImage = RawImage::Create(format, mipmapCount, GetSize(), imageUse, heap, updateSync);
    if (!rawImage)
        return 0;

    ImageData rawData;
    rawImage->GetImageData(&rawData);
    if (!Decode(&rawData, &Image::CopyScanlineDefault))
    {
        rawImage->Release();
        return 0;
    }
    return rawImage;
}

// ---------------------------------------------------------------- RawImage

// @0x142579550
RawImage::~RawImage()
{
    // also runs for the half-built image of a failed Create
    freeData();
}

// @0x14257d960
void RawImage::freeData()
{
    for (unsigned i = 0; i < Data.RawPlaneCount; i++)
    {
        if (Data.pPlanes[i].pData)
        {
            SF_FREE(Data.pPlanes[i].pData);
            Data.pPlanes[i].pData = 0;
        }
    }
}

// MS2-FUNCTIONAL: same code, but MSVC shrink-wraps the rbx/rbp/r14 saves past the early returns (the exe saves all eight registers in the prolog)
// @0x14257a520
RawImage* SF_STDCALL RawImage::Create(ImageFormat format, unsigned mipLevelCount, const ImageSize& size, unsigned use,
                                      MemoryHeap* heap, ImageUpdateSync* updateSync)
{
    if (!heap)
        heap = Memory::GetGlobalHeap();

    if (use & ImageUse_GenMipmaps)
    {
        if (mipLevelCount != 1)
            return 0;
    }

    RawImage* image = SF_HEAP_NEW(heap) RawImage;
    if (!image)
        return 0;

    if (!image->Data.Initialize(format, mipLevelCount))
    {
        image->Release();
        return 0;
    }

    image->Data.Use    = (UInt16)use;
    image->pUpdateSync = updateSync;

    for (unsigned plane = 0; plane < image->Data.RawPlaneCount; plane++)
    {
        ImageSize planeSize = ImageData::GetFormatPlaneSize(format, size, plane);
        UPInt     pitch     = ImageData::GetFormatPitch(format, planeSize.Width, plane);
        UPInt     dataSize  = ImageData::GetMipLevelsSize(format, planeSize, mipLevelCount, plane);
        UByte*    data      = (UByte*)SF_HEAP_ALLOC(heap, dataSize, Stat_Image_Mem);
        if (!data)
        {
            image->Release();
            return 0;
        }
        image->Data.pPlanes[plane].SetData(planeSize.Width, planeSize.Height, pitch, dataSize, data);
    }
    return image;
}

// @0x14257b930
bool RawImage::GetImageData(ImageData* data)
{
    *data = Data;
    return true;
}

// @0x14257d0f0
void RawImage::SetImageData(ImageData* data)
{
    freeData();
    Data = *data;
}

// @0x14257c980
bool RawImage::Map(ImageData* data, unsigned levelIndex, unsigned levelCount)
{
    if (data->Initialize(Data, levelIndex, levelCount))
    {
        Data.Flags |= ImageData::Flag_ImageMapped;
        return true;
    }
    return false;
}

bool RawImage::Unmap()
{
    Data.Flags &= ~ImageData::Flag_ImageMapped;
    return true;
}

// Hardware formats copy plane by plane; the others go scanline by scanline through copyScanline.
// @0x14257ab20
bool RawImage::Decode(ImageData* dest, CopyScanlineFunc copyScanline, void* arg) const
{
    ImagePlane  splane, dplane;
    ImageFormat format         = Data.GetFormat();
    unsigned    formatPlanes   = ImageData::GetFormatPlaneCount(format);
    unsigned    planeCount     = Data.GetPlaneCount(),
                destPlaneCount = dest->GetPlaneCount();
    unsigned    i;

    if (Data.IsHWSpecific())
    {
        for (i = 0; i < planeCount; i++)
        {
            Data.GetPlane(i, &splane);
            dest->GetPlane(i, &dplane);
            memcpy(dplane.pData, splane.pData, splane.DataSize);
        }
        return true;
    }

    planeCount = Alg::Min(planeCount, destPlaneCount);

    for (i = 0; i < planeCount; i++)
    {
        unsigned planeIndex = planeCount % formatPlanes;

        if ((Data.HasSeparateMipmaps() || Data.GetMipLevelCount() == 1) &&
            (dest->HasSeparateMipmaps() || dest->GetMipLevelCount() == 1))
        {
            Data.GetPlane(i, &splane);
            dest->GetPlane(i, &dplane);

            UByte*   src       = splane.pData;
            UByte*   dst       = dplane.pData;
            UPInt    scanlines = ImageData::GetFormatScanlineCount(format, splane.Height, planeIndex);
            unsigned lineSize  = (splane.Width * Data.GetBitsPerPixel()) / 8;

            for (UPInt j = 0; j < scanlines; j++, src += splane.Pitch, dst += dplane.Pitch)
                copyScanline(dst, src, lineSize, Data.pPalette.GetPtr(), arg);
        }
        else
        {
            UByte* src = 0;
            UByte* dst = 0;

            // packed mip levels: walk the levels both images have
            for (unsigned level = 0; level < Alg::Min(Data.LevelCount, dest->LevelCount); level++)
            {
                if (Data.HasSeparateMipmaps())
                {
                    Data.GetPlane(planeIndex + formatPlanes * level, &splane);
                    src = src ? src : splane.pData;
                }
                else
                {
                    Data.GetPlane(formatPlanes * level + i, &splane);
                    src = splane.pData;
                }

                if (dest->HasSeparateMipmaps())
                {
                    dest->GetPlane(planeIndex + formatPlanes * level, &dplane);
                    dst = dst ? dst : dplane.pData;
                }
                else
                {
                    dest->GetPlane(formatPlanes * level + i, &dplane);
                    dst = dplane.pData;
                }

                UPInt    scanlines = ImageData::GetFormatScanlineCount(format, splane.Height, planeIndex);
                unsigned lineSize  = (splane.Width * Data.GetBitsPerPixel()) / 8;
                for (UPInt j = 0; j < scanlines; j++, src += splane.Pitch, dst += dplane.Pitch)
                    copyScanline(dst, src, lineSize, Data.pPalette.GetPtr(), arg);
            }
        }
    }
    return true;
}

// The texture is made on demand for the asking manager; map flags stay with the RawImage.
// @0x14257c150
Texture* RawImage::GetTexture(TextureManager* manager)
{
    if (pTexture && pTexture->GetTextureManager() == manager)
        return pTexture;

    if (!manager)
        return 0;

    pTexture = 0;
    Texture* texture = manager->CreateTexture(Data.Format, Data.LevelCount, Data.GetSize(),
                                              (Data.Use & ~ImageUse_Map_Mask), this);
    initTexture_NoAddRef(texture);
    return texture;
}

// ---------------------------------------------------------------- TextureImage

// @0x1425792d0
TextureImage::TextureImage(ImageFormat format, const ImageSize& size, unsigned use, Texture* texture,
                           ImageUpdateSync* sync)
    : Image(texture, sync), Format(format), Size(size), Use(use)
{
    ImageId = ImageBase::GetNextImageId();
}

// @0x14257b550
UPInt TextureImage::GetBytes(int* memRegion) const
{
    if (memRegion)
        *memRegion = 0;
    if (pTexture)
        return pTexture->GetBytes(memRegion);
    return ImageBase::GetBytes(memRegion);
}

bool TextureImage::Decode(ImageData* dest, CopyScanlineFunc, void*) const
{
    if (!pTexture)
        return false;
    return pTexture->Copy(dest);
}

bool TextureImage::Map(ImageData* data, unsigned mipLevel, unsigned levelCount)
{
    return pTexture->Map(data, mipLevel, levelCount);
}

bool TextureImage::Unmap()
{
    return pTexture->Unmap();
}

// ---------------------------------------------------------------- update queue

ImageUpdate::ImageUpdate(Image* image) : pImage(image)
{
}

// @0x1425794d0
ImageUpdateQueue::~ImageUpdateQueue()
{
    for (unsigned i = 0; i < Queue.GetSize(); i++)
    {
        if (Queue[i] & 1)
        {
            Image* image = (Image*)(Queue[i] & ~(UpdateRef)1);
            image->Release();
        }
        else
        {
            ImageUpdate* update = (ImageUpdate*)Queue[i];
            update->Release();
        }
    }
}

// @0x14257cc20
void ImageUpdateQueue::ProcessUpdates(TextureManager* manager)
{
    for (unsigned i = 0; i < Queue.GetSize(); i++)
    {
        if (Queue[i] & 1)
        {
            Image*   image   = (Image*)(Queue[i] & ~(UpdateRef)1);
            Texture* texture = image->GetTexture(manager);
            if (texture)
                texture->Update();
            image->Release();
        }
        else
        {
            ImageUpdate* update = (ImageUpdate*)Queue[i];
            update->HandleUpdate(manager);
            update->Release();
        }
    }
    Queue.Clear();
}

// @0x142579fb0
void ImageUpdateQueue::Add(Image* image)
{
    Queue.PushBack(((UpdateRef)image) | 1);
    image->AddRef();
}

// @0x14257a040
void ImageUpdateQueue::Add(ImageUpdate* update)
{
    Queue.PushBack((UpdateRef)update);
    update->AddRef();
}

// ---------------------------------------------------------------- TextureManager / Texture

// @0x142579370
TextureManager::TextureManager() : ServiceCommandInstance(getThis()), pLocks(0)
{
    pLocks = *SF_HEAP_AUTO_NEW(this) TextureManagerLocks(this);
}

// @0x14257d4d0
void TextureManager::UpdateImage(Image* image)
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    ImageUpdates.Add(image);
}

// @0x14257d580
void TextureManager::UpdateImage(ImageUpdate* update)
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    ImageUpdates.Add(update);
}

// @0x14257cb20
void TextureManager::ProcessQueues()
{
    Mutex::Locker guard(&pLocks->TextureMutex);
    processTextureKillList();
    processInitTextures();
    processImageUpdates();
}

// @0x14257da30
const TextureFormat* TextureManager::precreateTexture(ImageFormat format, unsigned use, ImageBase* image)
{
    if (image)
    {
        if ((format & ImageFormat_Mask) != (image->GetFormat() & ImageFormat_Mask))
            return 0;
        if (image->GetImageType() == Image::Type_ImageBase && !(use & ImageUse_InitOnly))
            return 0;
    }
    else
    {
        if (!(use & (ImageUse_ReadOnly_Mask | ImageUse_RenderTarget)))
            return 0;
    }

    const TextureFormat* texFormat = getTextureFormat(format);
    if (!texFormat)
        return 0;
    if (ImageData::IsFormatCompressed(format) &&
        (use & (ImageUse_GenMipmaps | ImageUse_Map_Mask | ImageUse_PartialUpdate | ImageUse_RenderTarget)))
        return 0;
    if ((use & ImageUse_Map_Mask) && !isMappable(texFormat))
        return 0;
    return texFormat;
}

// @0x14257c8b0
void Texture::LoseManager()
{
    Lock::Locker guard(&pManagerLocks->ImageLock);

    RemoveNode();
    pNext = pPrev = 0;

    ReleaseHWTextures();
    State = State_Dead;

    if (pImage)
    {
        // TextureLost may release this texture, so it goes last
        Image* image = (Image*)pImage;
        pImage = 0;
        image->TextureLost(Image::TLR_ManagerDestroyed);
    }
}

// @0x14257c940
void Texture::LoseTextureData()
{
    if (pImage && pImage->GetImageType() == Image::Type_DrawableImage)
        ((DrawableImage*)pImage)->unmapTextureRT();
}

}} // namespace Scaleform::Render

// Vftables of this TU (no RTTI under /GR-, so paired by hand) and the COMDAT deleting destructors they hold.
// ThreadCommand's has two slots (destructor, pure Execute), RefCountBase<ThreadCommand>'s one.
// MS2-PIN: ??_7ThreadCommand@Render@Scaleform@@6B@ 0x143183928
// MS2-PIN: ??_7?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@6B@ 0x143183980
// MS2-PIN: ??_GThreadCommand@Render@Scaleform@@UEAAPEAXI@Z 0x142579f50
// MS2-PIN: ??_G?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142579940
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1425798e0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EL@@Scaleform@@UEAAPEAXI@Z 0x1425799a0
// MS2-PIN: ??_7?$RefCountBase@VTextureManagerLocks@Render@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183920
// MS2-PIN: ??_G?$RefCountBase@VTextureManagerLocks@Render@Scaleform@@$0EL@@Scaleform@@UEAAPEAXI@Z 0x142579a00
// MS2-PIN: ??_7TextureManagerLocks@Render@Scaleform@@6B@ 0x143183948
// MS2-PIN: ??_GTextureManagerLocks@Render@Scaleform@@UEAAPEAXI@Z 0x142579ec0
// MS2-PIN: ??_7?$RefCountBase@VImageUpdate@Render@Scaleform@@$01@Scaleform@@6B@ 0x143183938
// MS2-PIN: ??_G?$RefCountBase@VImageUpdate@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142579a60
// MS2-PIN: ??_7ImageUpdate@Render@Scaleform@@6B@ 0x143183970
// MS2-PIN: ??_7ImageUpdateSync@Render@Scaleform@@6B@ 0x143183950
// MS2-PIN: ??_7ServiceCommand@TextureManager@Render@Scaleform@@6B@ 0x143183988
// MS2-PIN: ??_GServiceCommand@TextureManager@Render@Scaleform@@UEAAPEAXI@Z 0x142579c60
// MS2-PIN: ??_7TextureManager@Render@Scaleform@@6B?$RefCountBase@VTextureManager@Render@Scaleform@@$0EL@@2@@ 0x143183998
// MS2-PIN: ??_7TextureManager@Render@Scaleform@@6BImageUpdateSync@12@@ 0x143183a28
// MS2-PIN: ??_ETextureManager@Render@Scaleform@@WBA@EAAPEAXI@Z 0x1425798d0
// MS2-PIN: ??_7TextureImage@Render@Scaleform@@6B@ 0x143183b28
// MS2-PIN: ??_7SubImage@Render@Scaleform@@6B@ 0x143183c10
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7RawImage@Render@Scaleform@@6B@ 0x143183a40
// MS2-PIN: ?BeginScene@TextureManager@Render@Scaleform@@UEAAXXZ 0x14257a0c0
