// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ImageSupport (decoders of the
// SWF bitmaps that need zlib: the lossless DefineBitsLossless / DefineBitsLossless2 formats and the JPEG images with
// a zlib-compressed alpha plane of DefineBitsJPEG3; colour bleeding into the transparent pixels when the stored
// premultiplied alpha is undone).
// Eighth source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426519d0-0x1426535f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/gfx_imagesupport.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_memoryfile.h"

#include <string.h>

namespace Scaleform { namespace GFx {

using Render::Image;
using Render::ImageScanlineBuffer;
using Render::JPEG::Input;

// 0xff00 / a (0xff00 for a = 0): scales a premultiplied channel back up by 1 / alpha, in 8.8 fixed point.
static const UInt16 GFx_UndoPremultiplyTable[256] = {
    65280, 65280, 32640, 21760, 16320, 13056, 10880,  9325,  8160,  7253,  6528,  5934,  5440,  5021,  4662,  4352,
    4080,  3840,  3626,  3435,  3264,  3108,  2967,  2838,  2720,  2611,  2510,  2417,  2331,  2251,  2176,  2105,
    2040,  1978,  1920,  1865,  1813,  1764,  1717,  1673,  1632,  1592,  1554,  1518,  1483,  1450,  1419,  1388,
    1360,  1332,  1305,  1280,  1255,  1231,  1208,  1186,  1165,  1145,  1125,  1106,  1088,  1070,  1052,  1036,
    1020,  1004,   989,   974,   960,   946,   932,   919,   906,   894,   882,   870,   858,   847,   836,   826,
    816,   805,   796,   786,   777,   768,   759,   750,   741,   733,   725,   717,   709,   701,   694,   687,
    680,   672,   666,   659,   652,   646,   640,   633,   627,   621,   615,   610,   604,   598,   593,   588,
    582,   577,   572,   567,   562,   557,   553,   548,   544,   539,   535,   530,   526,   522,   518,   514,
    510,   506,   502,   498,   494,   490,   487,   483,   480,   476,   473,   469,   466,   462,   459,   456,
    453,   450,   447,   444,   441,   438,   435,   432,   429,   426,   423,   421,   418,   415,   413,   410,
    408,   405,   402,   400,   398,   395,   393,   390,   388,   386,   384,   381,   379,   377,   375,   373,
    370,   368,   366,   364,   362,   360,   358,   356,   354,   352,   350,   349,   347,   345,   343,   341,
    340,   338,   336,   334,   333,   331,   329,   328,   326,   324,   323,   321,   320,   318,   316,   315,
    313,   312,   310,   309,   307,   306,   305,   303,   302,   300,   299,   298,   296,   295,   294,   292,
    291,   290,   288,   287,   286,   285,   283,   282,   281,   280,   278,   277,   276,   275,   274,   273,
    272,   270,   269,   268,   267,   266,   265,   264,   263,   262,   261,   260,   259,   258,   257,   256,
};

static inline void UndoPremultiplyAlpha(UByte* prgb, UByte a)
{
    // A premultiplied channel never exceeds alpha; clamp before scaling so bad data cannot overflow.
    unsigned scale = GFx_UndoPremultiplyTable[a];
    prgb[0] = UByte((scale * (prgb[0] <= a ? prgb[0] : a)) >> 8);
    prgb[1] = UByte((scale * (prgb[1] <= a ? prgb[1] : a)) >> 8);
    prgb[2] = UByte((scale * (prgb[2] <= a ? prgb[2] : a)) >> 8);
}

namespace {

// Scanline state of the decoders that undo the premultiplied alpha: a ring of three RGBA lines (with a transparent
// pixel of padding on each side) so that each line can see its neighbours above and below.
struct Params
{
    ImageScanlineBuffer<0x800>   SourceScanline;     // +0       RGB of the JPEG
    ImageScanlineBuffer<0x400>   AlphaScanline;      // +0x840   A8 of the zlib plane
    ImageScanlineBuffer<0x800>   ScanlineWithAlpha0; // +0xc80
    ImageScanlineBuffer<0x800>   ScanlineWithAlpha1; // +0x14c0
    ImageScanlineBuffer<0x800>   ScanlineWithAlpha2; // +0x1d00
    ImageScanlineBuffer<0x800>*  ScanlineWithAlphas[3]; // +0x2540 previous, current, next
    ImageScanlineBuffer<0x1000>  FinalScanline;      // +0x2558
    Ptr<File>                    ZlibFile;           // +0x3598
    Input*                       Jin;                // +0x35a0
    unsigned                     Width;              // +0x35a8
    bool                         Success;            // +0x35ac

    // @0x142651af0
    Params(Input* jin, unsigned width, ImageFormat format)
        : SourceScanline(Render::Image_R8G8B8, width, Render::Image_R8G8B8),
          AlphaScanline(Render::Image_A8, width, Render::Image_A8),
          ScanlineWithAlpha0(Render::Image_R8G8B8A8, width + 2, Render::Image_R8G8B8A8),
          ScanlineWithAlpha1(Render::Image_R8G8B8A8, width + 2, Render::Image_R8G8B8A8),
          ScanlineWithAlpha2(Render::Image_R8G8B8A8, width + 2, Render::Image_R8G8B8A8),
          FinalScanline(Render::Image_R8G8B8A8, width, format), Jin(jin), Width(width), Success(true)
    {
        ScanlineWithAlphas[0] = &ScanlineWithAlpha0;
        ScanlineWithAlphas[1] = &ScanlineWithAlpha1;
        ScanlineWithAlphas[2] = &ScanlineWithAlpha2;
        // The line above the first one is fully transparent.
        memset(ScanlineWithAlpha0.GetReadBuffer(), 0, ScanlineWithAlpha0.GetReadSize());
    }

    // Moves the ring one line down: the current line becomes the previous one.
    void Rotate()
    {
        ImageScanlineBuffer<0x800>* t = ScanlineWithAlphas[0];
        ScanlineWithAlphas[0]         = ScanlineWithAlphas[2];
        ScanlineWithAlphas[2]         = t;
        t                             = ScanlineWithAlphas[0];
        ScanlineWithAlphas[0]         = ScanlineWithAlphas[1];
        ScanlineWithAlphas[1]         = t;
    }
};

// What the lossless decoders need to know about the bitmap.
struct ZlibDecodeParams
{
    ImageFormat                             Format;         // +0
    ZlibImageSource::SourceBitmapDataFormat SrcFormat;      // +4
    ImageSize                               Size;           // +8
    Ptr<File>                               ZlibFile;       // +0x10
    unsigned                                ColorTableSize; // +0x18
};

} // namespace

// Writes the current (middle) line of the ring to FinalScanline with its alpha undone. Nearly transparent pixels
// lost their colour to the premultiplication; they take the alpha-weighted mean colour of their 3x3 neighbourhood
// instead, so that filtering the image does not pull black in at the edges.
// @0x142652790
static void UndoPremultiplyAlphaScanline(Params& params)
{
    UByte*       out   = params.FinalScanline.GetReadBuffer();
    const UByte* above = params.ScanlineWithAlphas[0]->GetReadBuffer();
    const UByte* cur   = params.ScanlineWithAlphas[1]->GetReadBuffer();
    const UByte* below = params.ScanlineWithAlphas[2]->GetReadBuffer();
    memcpy(out, cur + 4, params.FinalScanline.GetReadSize());

    for (unsigned x = 0; x < params.Width; ++x)
    {
        const UByte* row = cur + x * 4 + 4;
        const UByte* c   = row;
        UByte*       po  = out + x * 4;
        if (po[3] < 16)
        {
            // The 3x3 block centred on the pixel; the padding pixels make x - 1 and x + 1 always valid.
            const UByte* rowAbove = above + x * 4 + 4;
            const UByte* rowBelow = below + x * 4 + 4;
            const UByte* nw       = rowAbove - 4;
            const UByte* n        = rowAbove;
            const UByte* ne       = rowAbove + 4;
            const UByte* w        = row - 4;
            const UByte* e        = row + 4;
            const UByte* sw       = rowBelow - 4;
            const UByte* s        = rowBelow;
            const UByte* se       = rowBelow + 4;

            unsigned weight = unsigned(nw[3]) + n[3] + ne[3] + w[3] + c[3] + e[3] + sw[3] + s[3] + se[3];
            if (weight)
            {
                // The channels are premultiplied already, so their plain sum is the alpha-weighted sum.
                unsigned r  = ((nw[0] + n[0] + ne[0] + w[0] + c[0] + e[0] + sw[0] + s[0] + se[0]) << 8) / weight;
                unsigned g  = ((nw[1] + n[1] + ne[1] + w[1] + c[1] + e[1] + sw[1] + s[1] + se[1]) << 8) / weight;
                unsigned bl = ((nw[2] + n[2] + ne[2] + w[2] + c[2] + e[2] + sw[2] + s[2] + se[2]) << 8) / weight;
                po[0] = UByte(r <= 255 ? r : 255);
                po[1] = UByte(g <= 255 ? g : 255);
                po[2] = UByte(bl <= 255 ? bl : 255);
            }
        }
        else
        {
            UndoPremultiplyAlpha(po, po[3]);
        }
    }
}

// Reads one JPEG line and one alpha line and interleaves them as RGBA into fullData.
static bool ReadAndUniteScanline(Params& params, UByte* fullData)
{
    UByte* rgb   = params.SourceScanline.GetReadBuffer();
    UByte* alpha = params.AlphaScanline.GetReadBuffer();

    if (!params.Jin->ReadScanline(rgb))
    {
        params.Success = false;
        return false;
    }
    if (params.ZlibFile->Read(alpha, (int)params.AlphaScanline.GetReadSize()) <= 0)
    {
        params.Success = false;
        return false;
    }

    // src steps over RGB, dst over RGBA.
    for (unsigned src = 0, dst = 0, x = 0; x < params.Width; src += 3, dst += 4, ++x)
    {
        fullData[dst]     = rgb[src];
        fullData[dst + 1] = rgb[src + 1];
        fullData[dst + 2] = rgb[src + 2];
        fullData[dst + 3] = alpha[x];
    }
    return true;
}

// Decodes a JPEG (jin, owned and deleted here) together with its zlib-compressed alpha plane into pdest. The ring
// runs one line ahead: line y - 1 is written once line y has been read (an extra transparent line closes the image).
// @0x1426523c0
// MS2-FUNCTIONAL: the exe inlines ~MemoryFile; here it binds to the game code's out-of-line copy
static bool JpegAlphaDecodeHelper(ImageFormat format, Input* jin, ZlibSupportBase* zlib, const UByte* alphaData,
                                  UPInt alphaDataSize, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                                  void* arg)
{
    ImageSize  size = jin->GetSize();
    MemoryFile alphaFile("", alphaData, (int)alphaDataSize);

    Params params(jin, size.Width, format);
    params.ZlibFile = *zlib->CreateZlibFile(&alphaFile);

    if (jin->HasError())
    {
        params.Success = false;
    }
    else
    {
        unsigned ringIndex = 1;
        unsigned linesRead = 0;
        for (unsigned y = 0; y < size.Height + 1; ++y)
        {
            UByte* line = params.ScanlineWithAlphas[ringIndex]->GetReadBuffer();
            ((UInt32*)line)[0]              = 0;
            ((UInt32*)line)[size.Width + 1] = 0;
            if (y < size.Height)
            {
                if (!ReadAndUniteScanline(params, line + 4))
                    break;
            }
            else
            {
                memset(line, 0, params.ScanlineWithAlphas[ringIndex]->GetReadSize());
            }

            if (++linesRead >= 2)
            {
                UndoPremultiplyAlphaScanline(params);
                params.FinalScanline.ConvertReadBuffer(pdest->GetScanline(y - 1), 0, copyScanline, arg);
            }

            if (ringIndex == 2)
                params.Rotate();
            else
                ++ringIndex;
        }
    }

    delete jin;
    return params.Success;
}

// @0x1426519d0
MemoryBufferJpegImageWithZlibAlphas::MemoryBufferJpegImageWithZlibAlphas(
    ZlibSupportBase* zlib, Render::JPEG::AbstractReader* reader, unsigned alphaPos, ImageFormat format,
    const ImageSize& size, unsigned use, ImageUpdateSync* sync, File* file, UPInt length)
    : ZLib(zlib), JpegReader(reader), ZlibAlphaOffset(alphaPos), Format(format)
{
    // The whole tag data (JPEG, then the alpha plane) is kept by a plain RGB memory JPEG image.
    Render::ImageCreateArgs args;
    args.Use         = use;
    args.pUpdateSync = sync;
    args.Format      = Render::Image_R8G8B8;
    args.pHeap       = Memory::GetHeapByAddress(this);
    pImage           = *reader->CreateMemoryBufferImage(file, args, size, length);
}

// @0x142652030
bool MemoryBufferJpegImageWithZlibAlphas::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    const UByte* data;
    UPInt        dataSize;
    static_cast<Render::MemoryBufferImage*>(pImage.GetPtr())->GetImageDataBits(&data, &dataSize);

    Input* jin = JpegReader->CreateSwfJpeg2HeaderOnly(data, dataSize);
    if (!jin)
        return false;
    jin->StartImage();
    return JpegAlphaDecodeHelper(Format, jin, ZLib, data + ZlibAlphaOffset, dataSize - ZlibAlphaOffset, pdest,
                                 copyScanline, arg);
}

// @0x1426522f0
Render::Texture* MemoryBufferJpegImageWithZlibAlphas::GetTexture(Render::TextureManager* manager)
{
    if (pTexture && pTexture->GetTextureManager() == manager)
        return pTexture;

    // A texture of another manager is dropped; this image decodes into a new one.
    pTexture                  = 0;
    Render::Texture* ptexture = manager->CreateTexture(GetFormat(), 1, GetSize(), GetUse(), this);
    initTexture_NoAddRef(ptexture);
    return ptexture;
}

// 8-bit palette indices into an RGB colour table.
// @0x142652a80
static bool ZlibDecodeColorMapped(const ZlibDecodeParams& params, ImageData* pdest,
                                  Image::CopyScanlineFunc copyScanline, void* arg)
{
    ImageScanlineBuffer<256 * 3> colorMap(Render::Image_R8G8B8, params.ColorTableSize, Render::Image_R8G8B8);
    ImageScanlineBuffer<0x400>   indices(Render::Image_A8, params.Size.Width, Render::Image_A8);
    ImageScanlineBuffer<0x800>   rgb(Render::Image_R8G8B8, params.Size.Width, params.Format);
    int colorMapBytes = (int)params.ColorTableSize * 3;
    // Rows are padded to 4 bytes.
    const int pitch = (params.Size.Width + 3) & ~3;

    if (params.ZlibFile->Read(colorMap.GetReadBuffer(), colorMapBytes) != colorMapBytes)
        return false;

    UByte* in    = indices.GetReadBuffer();
    UByte* out   = rgb.GetReadBuffer();
    UByte* table = colorMap.GetReadBuffer();

    for (unsigned y = 0; y < params.Size.Height; ++y)
    {
        if (params.ZlibFile->Read(in, pitch) != pitch)
            return false;

        for (unsigned x = 0; x < params.Size.Width; ++x)
        {
            UByte index    = in[x];
            out[x * 3]     = table[index * 3];
            out[x * 3 + 1] = table[index * 3 + 1];
            out[x * 3 + 2] = table[index * 3 + 2];
        }
        rgb.ConvertReadBuffer(pdest->GetScanline(y), 0, copyScanline, arg);
    }
    return true;
}

// 8-bit palette indices into a premultiplied RGBA colour table.
// @0x142652c90
static bool ZlibDecodeColorMappedAlpha(const ZlibDecodeParams& params, ImageData* pdest,
                                       Image::CopyScanlineFunc copyScanline, void* arg)
{
    ImageScanlineBuffer<256 * 4> colorMap(Render::Image_R8G8B8A8, params.ColorTableSize, Render::Image_R8G8B8A8);
    Params   data(0, params.Size.Width, params.Format);
    unsigned ringIndex = 1;
    unsigned linesRead = 0;

    UByte* table         = colorMap.GetReadBuffer();
    int    colorMapBytes = (int)params.ColorTableSize * 4;
    const int pitch      = (params.Size.Width + 3) & ~3;

    if (params.ZlibFile->Read(colorMap.GetReadBuffer(), colorMapBytes) != colorMapBytes)
        return false;

    for (unsigned y = 0; y < params.Size.Height + 1; ++y)
    {
        UByte* line = data.ScanlineWithAlphas[ringIndex]->GetReadBuffer();
        ((UInt32*)line)[0]                     = 0;
        ((UInt32*)line)[params.Size.Width + 1] = 0;
        if (y < params.Size.Height)
        {
            UByte* in = data.AlphaScanline.GetReadBuffer();
            if (params.ZlibFile->Read(in, pitch) != pitch)
                return false;
            UByte* out = line + 4;
            for (unsigned x = 0; x < params.Size.Width; ++x)
            {
                UByte index    = in[x];
                out[x * 4]     = table[index * 4];
                out[x * 4 + 1] = table[index * 4 + 1];
                out[x * 4 + 2] = table[index * 4 + 2];
                out[x * 4 + 3] = table[index * 4 + 3];
            }
        }
        else
        {
            memset(line, 0, data.ScanlineWithAlphas[ringIndex]->GetReadSize());
        }

        if (++linesRead >= 2)
        {
            UndoPremultiplyAlphaScanline(data);
            data.FinalScanline.ConvertReadBuffer(pdest->GetScanline(y - 1), 0, copyScanline, arg);
        }

        if (ringIndex == 2)
            data.Rotate();
        else
            ++ringIndex;
    }
    return true;
}

// 15-bit RGB, little-endian 0RRRRRGG GGGBBBBB.
// @0x142653160
static bool ZlibDecodeRGB16(const ZlibDecodeParams& params, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                            void* arg)
{
    ImageScanlineBuffer<0x800>  source(Render::Image_A8, params.Size.Width * 2, Render::Image_A8);
    ImageScanlineBuffer<0x1000> rgba(Render::Image_R8G8B8A8, params.Size.Width, params.Format);

    UByte*    in    = source.GetReadBuffer();
    const int pitch = (params.Size.Width * 2 + 3) & ~3;
    UByte*    out   = rgba.GetReadBuffer();

    for (unsigned y = 0; y < params.Size.Height; ++y)
    {
        if (params.ZlibFile->Read(in, pitch) != pitch)
            return false;

        for (unsigned x = 0; x < params.Size.Width; ++x)
        {
            UInt16 pixel   = in[x * 2] | (in[x * 2 + 1] << 8);
            out[x * 4]     = UByte((pixel >> 7) & 0xf8);
            out[x * 4 + 1] = UByte((pixel >> 2) & 0xf8);
            out[x * 4 + 2] = UByte((pixel << 3) & 0xf8);
            out[x * 4 + 3] = 0xff;
        }
        rgba.ConvertReadBuffer(pdest->GetScanline(y), 0, copyScanline, arg);
    }
    return true;
}

// 24-bit RGB stored as XRGB.
static bool ZlibDecodeRGB24(const ZlibDecodeParams& params, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                            void* arg)
{
    ImageScanlineBuffer<0x1000> line(Render::Image_R8G8B8A8, params.Size.Width, params.Format);

    UByte*    p     = line.GetReadBuffer();
    const int pitch = (params.Size.Width * 4 + 3) & ~3;

    for (unsigned y = 0; y < params.Size.Height; ++y)
    {
        if (params.ZlibFile->Read(p, pitch) != pitch)
            return false;

        for (unsigned x = 0; x < params.Size.Width; ++x)
        {
            UByte r      = p[x * 4 + 1];
            UByte g      = p[x * 4 + 2];
            UByte b      = p[x * 4 + 3];
            p[x * 4]     = r;
            p[x * 4 + 1] = g;
            p[x * 4 + 2] = b;
            p[x * 4 + 3] = 0xff;
        }
        line.ConvertReadBuffer(pdest->GetScanline(y), 0, copyScanline, arg);
    }
    return true;
}

// 32-bit premultiplied ARGB.
// @0x142653320
static bool ZlibDecodeRGBA(const ZlibDecodeParams& params, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                           void* arg)
{
    Params   data(0, params.Size.Width, params.Format);
    unsigned ringIndex = 1;
    unsigned linesRead = 0;

    for (unsigned y = 0; y < params.Size.Height + 1; ++y)
    {
        UByte* line = data.ScanlineWithAlphas[ringIndex]->GetReadBuffer();
        ((UInt32*)line)[0]                     = 0;
        ((UInt32*)line)[params.Size.Width + 1] = 0;
        if (y < params.Size.Height)
        {
            int    bytes = params.Size.Width * 4;
            UByte* p     = line + 4;
            if (params.ZlibFile->Read(p, bytes) != bytes)
                return false;
            for (unsigned x = 0; x < params.Size.Width; ++x)
            {
                UByte a      = p[x * 4];
                UByte r      = p[x * 4 + 1];
                UByte g      = p[x * 4 + 2];
                UByte b      = p[x * 4 + 3];
                p[x * 4]     = r;
                p[x * 4 + 1] = g;
                p[x * 4 + 2] = b;
                p[x * 4 + 3] = a;
            }
        }
        else
        {
            memset(line, 0, data.ScanlineWithAlphas[ringIndex]->GetReadSize());
        }

        if (++linesRead >= 2)
        {
            UndoPremultiplyAlphaScanline(data);
            data.FinalScanline.ConvertReadBuffer(pdest->GetScanline(y - 1), 0, copyScanline, arg);
        }

        if (ringIndex == 2)
            data.Rotate();
        else
            ++ringIndex;
    }
    return true;
}

// @0x142652fa0
static bool ZlibDecodeHelper(const ZlibDecodeParams& params, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                             void* arg)
{
    switch (params.SrcFormat)
    {
    case ZlibImageSource::ColorMappedRGB:
        return ZlibDecodeColorMapped(params, pdest, copyScanline, arg);
    case ZlibImageSource::ColorMappedRGBA:
        return ZlibDecodeColorMappedAlpha(params, pdest, copyScanline, arg);
    case ZlibImageSource::RGB16:
        return ZlibDecodeRGB16(params, pdest, copyScanline, arg);
    case ZlibImageSource::RGB24:
        return ZlibDecodeRGB24(params, pdest, copyScanline, arg);
    case ZlibImageSource::RGBA:
        return ZlibDecodeRGBA(params, pdest, copyScanline, arg);
    }
    return false;
}

// @0x142651c90
ZlibImageSource::ZlibImageSource(ZlibSupportBase* zlib, File* file, const ImageSize& size,
                                 SourceBitmapDataFormat bmpFormatId, ImageFormat format, UInt16 colorTableSize,
                                 UInt64 uncompressedLen)
    : Render::FileImageSource(file, format, uncompressedLen), Zlib(zlib), ColorTableSize(colorTableSize),
      BitmapFormatId(bmpFormatId)
{
    Size = size;
}

// @0x142652210
bool ZlibImageSource::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    ZlibDecodeParams params;
    params.Format         = Format;
    params.SrcFormat      = BitmapFormatId;
    params.Size           = Size;
    params.ZlibFile       = *Zlib->CreateZlibFile(pFile);
    params.ColorTableSize = ColorTableSize;
    return ZlibDecodeHelper(params, pdest, copyScanline, arg);
}

// @0x142651eb0
Render::Image* ZlibImageSource::CreateCompatibleImage(const Render::ImageCreateArgs& args)
{
    if (IsDecodeOnlyImageCompatible(args))
    {
        // Keep the compressed data in memory; it is decoded when a texture is made.
        return SF_HEAP_NEW(args.GetHeap()) MemoryBufferZlibImage(Zlib, GetFormat(), GetSize(), BitmapFormatId,
                                                                ColorTableSize, args.Use, args.GetUpdateSync(),
                                                                pFile, FilePos, (UPInt)FileLen);
    }
    return Render::ImageSource::CreateCompatibleImage(args);
}

// @0x1426520e0
// MS2-FUNCTIONAL: the exe inlines ~MemoryFile; here it binds to the game code's out-of-line copy
bool MemoryBufferZlibImage::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    ZlibDecodeParams params;
    params.Format    = Format;
    params.SrcFormat = BitmapFormatId;
    params.Size      = Size;
    MemoryFile data("", &FileData[0], (int)FileData.GetSize());
    params.ZlibFile       = *Zlib->CreateZlibFile(&data);
    params.ColorTableSize = ColorTableSize;
    bool ok               = ZlibDecodeHelper(params, pdest, copyScanline, arg);
    // The zlib file reads from data: release it first.
    params.ZlibFile = 0;
    return ok;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7MemoryBufferJpegImageWithZlibAlphas@GFx@Scaleform@@6B@ 0x143190670
// MS2-PIN: ??_7ZlibImageSource@GFx@Scaleform@@6B@ 0x143190758
// MS2-PIN: ??_7MemoryBufferZlibImage@GFx@Scaleform@@6B@ 0x1431907e0
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@UEAAPEAXI@Z 0x14243dbb0
// MS2-PIN: ??_G?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@UEAAPEAXI@Z 0x14243dc10
