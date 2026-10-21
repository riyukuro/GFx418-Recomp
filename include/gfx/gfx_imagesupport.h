// Recovered Scaleform 4.1.18 GFx: the images of the SWF bitmap tags that need zlib - the lossless DefineBitsLossless
// images (a file-backed source and an in-memory copy) and the JPEG images with a zlib-compressed alpha plane
// (DefineBitsJPEG3). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's:
//   MemoryBufferJpegImageWithZlibAlphas 0x48 (vftable 0x143190670): ImageDelegate, ZLib +0x30, JpegReader +0x38,
//     ZlibAlphaOffset +0x40, Format +0x44.
//   ZlibImageSource 0x50 (vftable 0x143190758): FileImageSource, Zlib +0x40, ColorTableSize +0x48, BitmapFormatId +0x4c.
//   MemoryBufferZlibImage 0x70 (vftable 0x1431907e0): MemoryBufferImage, Zlib +0x60, ColorTableSize +0x68,
//     BitmapFormatId +0x6c.
// Bodies: GFx_ImageSupport (sfr_gfx_08h).
//
// Built on the render include tree (ms2/scaleform/kernel, render_image.h), which cannot be mixed with the GFx tree of
// gfx_loaderimpl.h; ZlibSupportBase is therefore seen here through its own minimal declaration (same name, base
// layout and slots as the State declared in gfx_loaderimpl.h), so do not include both headers in one source.
#ifndef MS2_SF_GFX_IMAGESUPPORT_H
#define MS2_SF_GFX_IMAGESUPPORT_H

#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_imagefileutil.h"
#include "ms2/scaleform/include/render/render_jpeg.h"
#include "ms2/scaleform/kernel/sf_refcount.h"

namespace Scaleform { namespace GFx {

class Stream;

// Inflates compressed SWF data (a loader state, vftable 0x143109490): RefCountImpl, then the state type at +0x10.
class ZlibSupportBase : public RefCountBase<ZlibSupportBase, Stat_Default_Mem>
{
    unsigned SType; // +0x10 State::StateType

public:
    virtual File* CreateZlibFile(File* in)                                       = 0; // +8
    virtual void  InflateWrapper(Stream* pin, void* buffer, int bufferBytes) = 0; // +0x10
};

using Render::ImageData;
using Render::ImageFormat;
using Render::ImageSize;
using Render::ImageUpdateSync;

// A JPEG kept compressed in memory (the wrapped image) followed by its zlib-compressed alpha plane; decoding joins
// the two.
class MemoryBufferJpegImageWithZlibAlphas : public Render::ImageDelegate
{
    Ptr<ZlibSupportBase>          ZLib;            // +0x30
    Render::JPEG::AbstractReader* JpegReader;      // +0x38
    unsigned                      ZlibAlphaOffset; // +0x40 start of the alpha data in the memory buffer
    ImageFormat                   Format;          // +0x44

public:
    MemoryBufferJpegImageWithZlibAlphas(ZlibSupportBase* zlib, Render::JPEG::AbstractReader* reader,
                                        unsigned alphaPos, ImageFormat format, const ImageSize& size, unsigned use,
                                        ImageUpdateSync* sync, File* file, UPInt length = 0);

    virtual ImageFormat      GetFormat() const { return Format; }
    virtual Render::Texture* GetTexture(Render::TextureManager* manager);
    virtual bool             Decode(ImageData* pdest, CopyScanlineFunc copyScanline = CopyScanlineDefault,
                                    void* arg = 0) const;

    virtual Render::Image*             GetAsImage() { return this; }
    virtual Render::MemoryBufferImage* GetAsMemoryImage()
    {
        return static_cast<Render::MemoryBufferImage*>(pImage.GetPtr());
    }
};

// A lossless bitmap decoded straight from the (zlib-compressed) SWF data.
class ZlibImageSource : public Render::FileImageSource
{
public:
    // Layout of the inflated bitmap data.
    enum SourceBitmapDataFormat
    {
        ColorMappedRGB,
        RGB16,
        RGB24,
        ColorMappedRGBA,
        RGBA
    };

protected:
    Ptr<ZlibSupportBase>   Zlib;           // +0x40
    UInt16                 ColorTableSize; // +0x48
    SourceBitmapDataFormat BitmapFormatId; // +0x4c

public:
    ZlibImageSource(ZlibSupportBase* zlib, File* file, const ImageSize& size, SourceBitmapDataFormat bmpFormatId,
                    ImageFormat format = Render::Image_None, UInt16 colorTableSize = 0, UInt64 uncompressedLen = 0);
    ~ZlibImageSource() {}

    virtual bool           Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
    virtual Render::Image* CreateCompatibleImage(const Render::ImageCreateArgs& args);
    virtual unsigned       GetMipmapCount() const { return 1; }
};

// A lossless bitmap whose compressed data was copied into memory.
class MemoryBufferZlibImage : public Render::MemoryBufferImage
{
public:
    typedef ZlibImageSource::SourceBitmapDataFormat SourceBitmapDataFormat;

protected:
    Ptr<ZlibSupportBase>   Zlib;           // +0x60
    UInt16                 ColorTableSize; // +0x68
    SourceBitmapDataFormat BitmapFormatId; // +0x6c

public:
    MemoryBufferZlibImage(ZlibSupportBase* zlib, ImageFormat format, const ImageSize& size,
                          SourceBitmapDataFormat bmpFormatId, UInt16 colorTableSize, unsigned use,
                          ImageUpdateSync* sync, File* file, SInt64 filePos, UPInt length = 0)
        : Render::MemoryBufferImage(format, size, use, sync, file, filePos, length), Zlib(zlib),
          ColorTableSize(colorTableSize), BitmapFormatId(bmpFormatId)
    {
    }

    virtual bool Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
};

}} // namespace Scaleform::GFx

#endif
