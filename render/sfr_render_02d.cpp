// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the TGA reader TU
// (TGA_ImageReader): format detection, the header parse into a file image source and its scanline decode.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader).
// MS2-UNIT: sfr_render_02d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14259dcd0-0x14259e560 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_tga.h"
#include "ms2/scaleform/include/render/render_imagefileutil.h"

namespace Scaleform { namespace Render { namespace TGA {

// Image source over an open TGA file; the header has been parsed, the pixels are read on Decode.
class TGAFileImageSource : public FileImageSource
{
    ImageFormat  SourceFormat;  // +0x40
    UByte        ImageDesc;     // +0x44
    Ptr<Palette> pColorMap;     // +0x48

public:
    TGAFileImageSource(File* file, ImageFormat format)
        : FileImageSource(file, format), SourceFormat(Image_None), ImageDesc(0) {}

    bool             ReadHeader(MemoryHeap* heap);
    virtual bool     Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
    virtual unsigned GetMipmapCount() const { return 1; }
};

// @0x14259e230
bool TGAFileImageSource::ReadHeader(MemoryHeap* heap)
{
    UByte           idLen        = pFile->ReadUByte();
    TGAColorMapType colorMapType = (TGAColorMapType)pFile->ReadUByte();
    TGAImageType    imageType    = (TGAImageType)pFile->ReadUByte();

    unsigned colorMapStartIndex, colorMapSize, colorMapEntrySize;
    colorMapStartIndex = pFile->ReadUInt16();   // unused
    colorMapSize       = pFile->ReadUInt16();   // entries
    colorMapEntrySize  = pFile->ReadUByte();    // bits

    if (colorMapEntrySize > 0 && colorMapEntrySize != 24 && colorMapEntrySize != 32)
        return false;   // only 24/32 bit color maps

    pFile->ReadUInt16();    // x origin
    pFile->ReadUInt16();    // y origin

    UInt16 width        = pFile->ReadUInt16();
    UInt16 height       = pFile->ReadUInt16();
    UByte  bitsPerPixel = pFile->ReadUByte();
    Size.SetSize(width, height);

    // Uncompressed true-color or color-mapped only.
    if (!((colorMapType == TGAColorMap_NotIncluded && imageType == TGAImage_TrueColor) ||
          (colorMapType == TGAColorMap_Included && imageType == TGAImage_ColorMapped)))
        return false;

    ImageDesc = pFile->ReadUByte();
    if (idLen > 0)
        pFile->SkipBytes(idLen);

    switch (bitsPerPixel)
    {
    case 8:  SourceFormat = Image_P8;       break;
    case 24: SourceFormat = Image_B8G8R8;   break;
    case 32: SourceFormat = Image_B8G8R8A8; break;
    default:
        return false;
    }

    if (Format == Image_None)
    {
        // Palettized images expand to 24 bit, or 32 when the color map has alpha.
        if (SourceFormat == Image_P8)
        {
            if (colorMapEntrySize < 32)
                Format = Image_B8G8R8;
            else
                Format = Image_B8G8R8A8;
        }
        else
        {
            Format = SourceFormat;
        }
    }

    if (colorMapType == TGAColorMap_Included)
    {
        bool colorMapHasAlpha = (colorMapEntrySize == 32);
        pColorMap = *Palette::Create(colorMapSize, colorMapHasAlpha, heap);
        if (!pColorMap)
            return false;

        // Entries are stored BGR(A).
        for (unsigned i = 0; i < colorMapSize; ++i)
        {
            Color& c = (*pColorMap)[i];
            UByte  b = pFile->ReadUByte(),
                   g = pFile->ReadUByte(),
                   r = pFile->ReadUByte();
            c.SetRGBA(r, g, b, 0xFF);
            if (colorMapHasAlpha)
                c.SetAlpha(pFile->ReadUByte());
        }
    }
    FilePos = pFile->LTell();
    return true;
}

// @0x14259dfd0
bool TGAFileImageSource::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    if (!seekFileToDecodeStart())
        return false;

    ImageScanlineBuffer<1024 * 4> scanline(SourceFormat, Size.Width, Format);
    if (!scanline.IsValid())
        return false;

    unsigned yindex, ydelta, y;
    bool     success = true;

    if (ImageDesc & TGAImageDesc_TopToBottom)
    {
        yindex = 0;
        ydelta = 1;
    }
    else
    {
        yindex = Size.Height - 1;
        ydelta = (unsigned)-1;
    }

    int readSize = (int)scanline.GetReadSize();

    for (y = 0; y < Size.Height; y++, yindex += ydelta)
    {
        if (pFile->Read(scanline.GetReadBuffer(), readSize) != readSize)
        {
            success = false;
            break;
        }
        UByte* destScanline = pdest->GetScanline(yindex);
        scanline.ConvertReadBuffer(destScanline, pColorMap.GetPtr(), copyScanline, arg);
    }

    if (Format == Image_P8)
        pdest->pPalette = pColorMap;

    return success;
}

// TGA has no signature: the 18-byte header has to look plausible and the file be long enough for the pixels.
// @0x14259dd40
bool FileReader::MatchFormat(File* file, UByte* headerArg, UPInt headerArgSize) const
{
    FileHeaderReader<18> header(file, headerArg, headerArgSize);
    if (!header)
        return false;

    TGAColorMapType colorMapType      = (TGAColorMapType)header[1];
    TGAImageType    imageType         = (TGAImageType)header[2];
    UByte           colorMapEntrySize = header[7];
    int             width             = header[12] | (((int)header[13]) << 8);
    int             height            = header[14] | (((int)header[15]) << 8);
    UByte           bitsPerPixel      = header[16];
    UByte           imageDesc         = header[17];

    if (!((colorMapType == TGAColorMap_NotIncluded && imageType == TGAImage_TrueColor) ||
          (colorMapType == TGAColorMap_Included && imageType == TGAImage_ColorMapped)))
        return false;

    if ((colorMapEntrySize != 0) && (colorMapEntrySize != 24) && (colorMapEntrySize != 32))
        return false;
    if ((bitsPerPixel != 8) && (bitsPerPixel != 24) && (bitsPerPixel != 32))
        return false;
    if ((imageDesc & TGAImageDesc_ZeroMaskBits) != 0)
        return false;

    if (file->GetLength() < (width * height * (bitsPerPixel >> 3) + 18))
        return false;
    return true;
}

// @0x14259de40
ImageSource* FileReader::ReadImageSource(File* file, const ImageCreateArgs& args) const
{
    if (!file || !file->IsValid())
        return 0;
    TGAFileImageSource* source = SF_NEW TGAFileImageSource(file, args.Format);
    if (source && !source->ReadHeader(args.GetHeap()))
    {
        source->Release();
        source = 0;
    }
    return source;
}

FileReader FileReader::Instance;

}}} // namespace Scaleform::Render::TGA

// MS2-PIN: ??_GImageFileReader@Render@Scaleform@@UEAAPEAXI@Z 0x14259dcd0
// MS2-PIN: ??_G?$ImageFileReader_Mixin@VFileReader@TGA@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@UEAAPEAXI@Z 0x14259dd00
// MS2-PIN: ??_GFileReader@TGA@Render@Scaleform@@UEAAPEAXI@Z 0x14259df10
// MS2-PIN: ??_GTGAFileImageSource@TGA@Render@Scaleform@@UEAAPEAXI@Z 0x14259df50
// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// MS2-PIN: ??_7ImageFileReader@Render@Scaleform@@6B@ 0x143184f40
// MS2-PIN: ??_7?$ImageFileReader_Mixin@VFileReader@TGA@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@6B@ 0x143184f78
// MS2-PIN: ??_7FileReader@TGA@Render@Scaleform@@6B@ 0x143184fb0
// MS2-PIN: ??_7TGAFileImageSource@TGA@Render@Scaleform@@6B@ 0x143184fe8
