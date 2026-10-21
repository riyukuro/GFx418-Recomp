// Recovered Scaleform 4.1.18 Render: helpers shared by the image file readers - the file-backed image source, the
// in-memory compressed image, the header peek and the scanline read/convert buffer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64, AMP build):
//   FileImageSource 0x40 (vftable 0x1431903c0): Format +0x10, Size +0x14, Use +0x1c, pFile +0x20, FilePos +0x28,
//     FileLen +0x30, ImageId +0x38.
//   MemoryBufferImage 0x60 (vftable 0x143190448): Image, then Format +0x28, Size +0x2c, Use +0x34, FileData +0x38,
//     FilePath +0x50, ImageId +0x58.
//   ImageScanlineBufferImpl 0x40, the inline temp buffer of ImageScanlineBuffer<N> follows at +0x40.
// Bodies live with Render_ImageFileUtil (0x14264cb80.., queue unit sfr_render_04).
#ifndef MS2_SF_RENDER_IMAGEFILEUTIL_H
#define MS2_SF_RENDER_IMAGEFILEUTIL_H

#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render {

// An image source that decodes from an open file, starting at the position it was created at.
class FileImageSource : public ImageSource
{
public:
    FileImageSource(File* file, ImageFormat format = Image_None, UInt64 len = 0);
    ~FileImageSource();

    virtual ImageFormat GetFormat() const { return Format; }
    virtual unsigned    GetUse() const    { return Use; }
    virtual ImageSize   GetSize() const   { return Size; }
    virtual Image*      GetAsImage()      { return 0; }
    virtual UInt32      GetImageId() const     { return ImageId; }
    virtual UInt32      GetBaseImageId() const { return 0; }

protected:
    bool seekFileToDecodeStart() const;

    ImageFormat Format;     // +0x10
    ImageSize   Size;       // +0x14
    unsigned    Use;        // +0x1c
    Ptr<File>   pFile;      // +0x20
    SInt64      FilePos;    // +0x28
    UInt64      FileLen;    // +0x30
    UInt32      ImageId;    // +0x38
};

// A compressed image kept in memory (read whole from a file or copied from a buffer); decoded on demand by the
// format's subclass.
class MemoryBufferImage : public Image
{
public:
    MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync,
                      File* file, SInt64 filePos, UPInt length = 0);
    MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync,
                      const UByte* data, UPInt dataSize);

    virtual ImageFormat GetFormat() const      { return Format; }
    virtual unsigned    GetUse() const         { return Use; }
    virtual ImageSize   GetSize() const        { return Size; }
    virtual Texture*    GetTexture(TextureManager* manager);
    virtual unsigned    GetMipmapCount() const { return 1; }
    virtual bool        Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const = 0;

    virtual Image*             GetAsImage()       { return this; }
    virtual MemoryBufferImage* GetAsMemoryImage() { return this; }

    bool GetImageDataBits(const UByte** pdata, UPInt* pdataLen)
    {
        *pdata    = &FileData[0];
        *pdataLen = FileData.GetSize();
        return true;
    }
    void SetImageSize(ImageSize size) { Size = size; }
    void SetFormat(ImageFormat f)     { Format = f; }

    virtual UInt32 GetImageId() const     { return ImageId; }
    virtual UInt32 GetBaseImageId() const { return 0; }

protected:
    ImageFormat    Format;      // +0x28
    ImageSize      Size;        // +0x2c
    unsigned       Use;         // +0x34
    ArrayLH<UByte> FileData;    // +0x38
    StringLH       FilePath;    // +0x50
    UInt32         ImageId;     // +0x58
};

// Gives the first sizeNeeded bytes of a file: the caller's header if long enough, else read into tempBuffer
// (the file position is restored). pHeader stays null when the file is short or invalid.
class FileHeaderReaderImpl
{
protected:
    UByte* pHeader;
public:
    FileHeaderReaderImpl(File* file, UByte* header, UPInt headerSize, UByte* tempBuffer, UByte sizeNeeded);
    UByte* GetPtr() const { return pHeader; }
};

template<int SZ>
class FileHeaderReader : public FileHeaderReaderImpl
{
    UByte Buffer[SZ];
public:
    FileHeaderReader(File* file, UByte* header = 0, UPInt headerSize = 0)
        : FileHeaderReaderImpl(file, header, headerSize, Buffer, SZ) {}

    UByte operator[](unsigned i) const { return pHeader[i]; }
    operator bool() const              { return pHeader != 0; }
    bool  operator!() const            { return pHeader == 0; }
};

// One scanline as read from the file plus, when the formats differ, the converted copy handed to copyScanline.
class ImageScanlineBufferImpl
{
    typedef Image::CopyScanlineFunc CopyFunc;

    ImageFormat ReadFormat;             // +0x00
    ImageFormat ConvertSourceFormat;    // +0x04
    unsigned    Width;                  // +0x08
    UByte*      pReadScanline;          // +0x10
    UByte*      pConvertScanline;       // +0x18
    UPInt       ReadScanlineSize;       // +0x20
    UPInt       ConvertScanlineSize;    // +0x28
    CopyFunc    pConvertFunc;           // +0x30
    bool        BuffersAllocated;       // +0x38

public:
    ImageScanlineBufferImpl(ImageFormat readFormat, unsigned width, ImageFormat convertSourceFormat,
                            UByte* tempBuffer = 0, UPInt tempBufferSize = 0);
    ~ImageScanlineBufferImpl();

    bool   IsValid() const       { return ReadFormat != Image_None && Width && pReadScanline; }
    UByte* GetReadBuffer() const { return pReadScanline; }
    UPInt  GetReadSize() const   { return ReadScanlineSize; }

    void ConvertReadBuffer(UByte* dest, Palette* pal, CopyFunc copyScanline = &Image::CopyScanlineDefault,
                           void* scanlineArg = 0);
};

template<int SZ>
class ImageScanlineBuffer : public ImageScanlineBufferImpl
{
    UByte TempBuffer[SZ];
public:
    ImageScanlineBuffer(ImageFormat readFormat, unsigned width, ImageFormat convertSourceFormat)
        : ImageScanlineBufferImpl(readFormat, width, convertSourceFormat, TempBuffer, SZ) {}
};

}} // namespace Scaleform::Render

#endif
