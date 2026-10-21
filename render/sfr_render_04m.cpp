// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the image file helper TU
// (Render_ImageFileUtil): the header peek, the file-backed image source, the in-memory compressed image and the
// scanline read / convert buffer the image file readers decode through.
// MS2-UNIT: sfr_render_04m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264cb80-0x14264d350 .text$mn

#include "ms2/scaleform/include/render/render_imagefileutil.h"
#include <string.h>

namespace Scaleform { namespace Render {

// the format converter from src to dest, null when there is none (Render_ImageConvert)
Image::CopyScanlineFunc GetImageConvertFunc(ImageFormat destFormat, ImageFormat sourceFormat);

// @0x14264cb80
FileHeaderReaderImpl::FileHeaderReaderImpl(File* file, UByte* header, UPInt headerSize, UByte* tempBuffer,
                                           UByte sizeNeeded)
{
    pHeader = 0;
    if (!file || !file->IsValid())
        return;

    if (header && headerSize >= sizeNeeded)
    {
        pHeader = header;
        return;
    }

    // peek through the temp buffer and put the file position back
    SInt64 pos  = file->LTell();
    int    read = file->Read(tempBuffer, sizeNeeded);
    file->LSeek(pos);
    if (read >= sizeNeeded)
        pHeader = tempBuffer;
}

// ***** FileImageSource

// @0x14264cc50
FileImageSource::FileImageSource(File* file, ImageFormat format, UInt64 len)
    : Format(format), Size(ImageSize::NoInit), Use(0), pFile(file), FileLen(len)
{
    // the size is left to the reader's header parse
    FilePos = pFile->LTell();
    ImageId = ImageBase::GetNextImageId();
}

// @0x14264cf80
FileImageSource::~FileImageSource()
{
}

// @0x14264d310
bool FileImageSource::seekFileToDecodeStart() const
{
    return pFile && pFile->LSeek(FilePos) == FilePos;
}

// ***** ImageScanlineBufferImpl

// @0x14264ccd0
ImageScanlineBufferImpl::ImageScanlineBufferImpl(ImageFormat readFormat, unsigned width,
                                                 ImageFormat convertSourceFormat, UByte* tempBuffer,
                                                 UPInt tempBufferSize)
    : ReadFormat(readFormat), ConvertSourceFormat(convertSourceFormat ? convertSourceFormat : readFormat),
      Width(width), pReadScanline(0), pConvertScanline(0)
{
    ReadScanlineSize    = (ImageData::GetFormatBitsPerPixel(ReadFormat) * width) / 8;
    ConvertScanlineSize = 0;
    pConvertFunc        = 0;
    BuffersAllocated    = false;

    if (ReadFormat != ConvertSourceFormat)
    {
        ConvertScanlineSize = (ImageData::GetFormatBitsPerPixel(ConvertSourceFormat) * width) / 8;
        pConvertFunc        = GetImageConvertFunc(ConvertSourceFormat, ReadFormat);
        if (!pConvertFunc)
            return;
    }

    // one block: the read scanline (16 byte aligned), then the converted one
    UPInt readSize  = (ReadScanlineSize + 16) & ~(UPInt)15;
    UPInt totalSize = readSize + ConvertScanlineSize;
    if (totalSize <= tempBufferSize)
        pReadScanline = tempBuffer;
    else
    {
        pReadScanline    = (UByte*)SF_ALLOC(totalSize, Stat_Image_Mem);
        BuffersAllocated = true;
    }
    if (pConvertFunc)
        pConvertScanline = pReadScanline + readSize;
}

// @0x14264cfb0
ImageScanlineBufferImpl::~ImageScanlineBufferImpl()
{
    if (BuffersAllocated)
        SF_FREE(pReadScanline);
}

// @0x14264d0f0
void ImageScanlineBufferImpl::ConvertReadBuffer(UByte* dest, Palette* pal, CopyFunc copyScanline, void* scanlineArg)
{
    if (pConvertFunc)
    {
        pConvertFunc(pConvertScanline, pReadScanline, ReadScanlineSize, pal, 0);
        copyScanline(dest, pConvertScanline, ConvertScanlineSize, 0, scanlineArg);
    }
    else
        copyScanline(dest, pReadScanline, ReadScanlineSize, pal, scanlineArg);
}

// ***** MemoryBufferImage

// @0x14264cdb0
MemoryBufferImage::MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync,
                                     File* file, SInt64 filePos, UPInt length)
    : Image(0, sync), Format(format), Size(size), Use(use)
{
    if (file)
    {
        if (!length)
            length = (UPInt)(file->LGetLength() - filePos);
        FileData.Resize(length);
        if (FileData.GetSize() == length)
        {
            file->LSeek(filePos);
            if (file->Read(FileData.GetDataPtr(), (int)length) >= (int)length)
            {
                FilePath = file->GetFilePath();
                ImageId  = ImageBase::GetNextImageId();
                return;
            }
        }
    }
    // unreadable: an image without a format
    Format = Image_None;
}

// @0x14264ced0
MemoryBufferImage::MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync,
                                     const UByte* data, UPInt dataSize)
    : Image(0, sync), Format(format), Size(size), Use(use)
{
    FileData.Resize(dataSize);
    memcpy(FileData.GetDataPtr(), data, dataSize);
    ImageId = ImageBase::GetNextImageId();
}

// @0x14264d160
Texture* MemoryBufferImage::GetTexture(TextureManager* manager)
{
    if (pTexture && pTexture->GetTextureManager() == manager)
        return pTexture;

    pTexture = 0;
    Texture* texture = manager->CreateTexture(Format, 1, Size, Use, this);
    initTexture_NoAddRef(texture);
    return texture;
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_GFileImageSource@Render@Scaleform@@UEAAPEAXI@Z 0x14264cfd0
// MS2-PIN: ??_GMemoryBufferImage@Render@Scaleform@@UEAAPEAXI@Z 0x14264d050
// MS2-PIN: ??_7FileImageSource@Render@Scaleform@@6B@ 0x1431903c0
// MS2-PIN: ??_7MemoryBufferImage@Render@Scaleform@@6B@ 0x143190448
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageSource@Render@Scaleform@@6B@ 0x1431851a8
