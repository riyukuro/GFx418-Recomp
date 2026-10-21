// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the DDS reader TU
// (DDS_ImageReader): signature check, the DDSURFACEDESC2 parse into a file image source and the per-mip decode
// (uncompressed RGB channels are reordered by their masks).
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader, 02e DDS reader).
// MS2-UNIT: sfr_render_02e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a16c0-0x1425a2100 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_dds.h"
#include "ms2/scaleform/include/render/render_imagefileutil.h"

namespace Scaleform { namespace Render { namespace DDS {

// DDSURFACEDESC2 flags.
enum DDSFlags
{
    DDSF_CAPS            = 0x00000001,
    DDSF_HEIGHT          = 0x00000002,
    DDSF_WIDTH           = 0x00000004,
    DDSF_PITCH           = 0x00000008,
    DDSF_BACKBUFFERCOUNT = 0x00000020,
    DDSF_ZBUFFERBITDEPTH = 0x00000040,
    DDSF_ALPHABITDEPTH   = 0x00000080,
    DDSF_LPSURFACE       = 0x00000800,
    DDSF_PIXELFORMAT     = 0x00001000,
    DDSF_CKDESTOVERLAY   = 0x00002000,
    DDSF_CKDESTBLT       = 0x00004000,
    DDSF_CKSRCOVERLAY    = 0x00008000,
    DDSF_CKSRCBLT        = 0x00010000,
    DDSF_MIPMAPCOUNT     = 0x00020000,
    DDSF_REFRESHRATE     = 0x00040000,
    DDSF_LINEARSIZE      = 0x00080000,
    DDSF_TEXTURESTAGE    = 0x00100000,
    DDSF_FVF             = 0x00200000,
    DDSF_SRCVBHANDLE     = 0x00400000,
    DDSF_DEPTH           = 0x00800000
};

// DDPIXELFORMAT flags.
enum DDSPixelFormat
{
    DDSPF_ALPHAPIXELS       = 0x00000001,
    DDSPF_ALPHA             = 0x00000002,
    DDSPF_FOURCC            = 0x00000004,
    DDSPF_PALETTEINDEXED4   = 0x00000008,
    DDSPF_PALETTEINDEXEDTO8 = 0x00000010,
    DDSPF_PALETTEINDEXED8   = 0x00000020,
    DDSPF_RGB               = 0x00000040,
    DDSPF_COMPRESSED        = 0x00000080
};

#define SF_DDS_FOURCC(c0, c1, c2, c3) \
    ((unsigned)(UByte)(c0) | ((unsigned)(UByte)(c1) << 8) | ((unsigned)(UByte)(c2) << 16) | ((unsigned)(UByte)(c3) << 24))

// Channel masks of an uncompressed surface and the shift that brings each channel down to bit 0.
struct DDSDescr
{
    UInt32 RGBBitCount;     // +0x00
    UInt32 RBitMask;        // +0x04
    UInt32 GBitMask;        // +0x08
    UInt32 BBitMask;        // +0x0c
    UInt32 ABitMask;        // +0x10
    bool   HasAlpha;        // +0x14
    UByte  ShiftR, ShiftG, ShiftB, ShiftA;

    inline DDSDescr()
    {
        RGBBitCount = RBitMask = GBitMask = BBitMask = ABitMask = 0;
        ShiftR = ShiftG = ShiftB = ShiftA;  // as shipped: the shifts are only valid after CalcShifts
        HasAlpha = false;
    }

    static UByte CalcShiftByMask(UInt32 mask)
    {
        unsigned shifts = 0;
        if (mask == 0)
            return 0;
        if ((mask & 0xFFFFFFu) == 0)
        {
            mask >>= 24;
            shifts += 24;
        }
        else if ((mask & 0xFFFFu) == 0)
        {
            mask >>= 16;
            shifts += 16;
        }
        else if ((mask & 0xFFu) == 0)
        {
            mask >>= 8;
            shifts += 8;
        }
        while ((mask & 1) == 0)
        {
            mask >>= 1;
            ++shifts;
        }
        return UByte(shifts);
    }

    void CalcShifts()
    {
        ShiftR = CalcShiftByMask(RBitMask);
        ShiftG = CalcShiftByMask(GBitMask);
        ShiftB = CalcShiftByMask(BBitMask);
        ShiftA = CalcShiftByMask(ABitMask);
    }
};

struct DDSHeaderInfo
{
    UInt32      Width;          // +0x00
    UInt32      Height;         // +0x04
    UInt32      Pitch;          // +0x08
    ImageFormat Format;         // +0x0c
    UInt32      MipmapCount;    // +0x10
    DDSDescr    DDSFmt;         // +0x14
    bool        OppositeEndian; // +0x30

    DDSHeaderInfo()
        : Width(0), Height(0), Pitch(0), Format(Image_None), MipmapCount(1), DDSFmt(), OppositeEndian(false) {}
};

// Image source over an open DDS file (0x78 bytes).
class DDSFileImageSource : public FileImageSource
{
    UByte         ImageDesc;    // +0x40
    DDSHeaderInfo HeaderInfo;   // +0x44

public:
    DDSFileImageSource(File* file, ImageFormat format) : FileImageSource(file, format), ImageDesc(0) {}
    virtual ~DDSFileImageSource() {}

    bool             ReadHeader();
    virtual bool     Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
    virtual unsigned GetMipmapCount() const { return HeaderInfo.MipmapCount; }
};

static const UByte* ParseUInt32(const UByte* buf, UInt32* pval)
{
    *pval = *(const UInt32*)buf;    // little endian on the PC build
    return buf + 4;
}

// buf points past the "DDS " tag and the header size.
// @0x1425a1eb0
bool Image_ParseDDSHeader(DDSHeaderInfo* pinfo, const UByte* buf, const UByte** pdata)
{
    UInt32 flags;
    UInt32 v;

    buf = ParseUInt32(buf, &flags);
    buf = ParseUInt32(buf, &v);
    if (flags & DDSF_HEIGHT)
        pinfo->Height = v;
    buf = ParseUInt32(buf, &v);
    if (flags & DDSF_WIDTH)
        pinfo->Width = v;
    buf = ParseUInt32(buf, &v);
    if (flags & DDSF_PITCH)
        pinfo->Pitch = v;
    else if (flags & DDSF_LINEARSIZE)
        pinfo->Pitch = v / pinfo->Height * 4;
    buf = ParseUInt32(buf, &v);     // depth
    buf = ParseUInt32(buf, &v);
    if (flags & DDSF_MIPMAPCOUNT)
        pinfo->MipmapCount = v;

    buf += 11 * 4;  // alpha bit depth + reserved

    if (flags & DDSF_PIXELFORMAT)
    {
        buf = ParseUInt32(buf, &v);         // dwSize
        if (v != 32)
            return false;
        UInt32 pfflags;
        buf = ParseUInt32(buf, &pfflags);   // dwFlags
        buf = ParseUInt32(buf, &v);         // dwFourCC

        if (pfflags & DDSPF_FOURCC)
        {
            if (v == SF_DDS_FOURCC('D', 'X', 'T', '5'))
                pinfo->Format = Image_DXT5;
            else if (v == SF_DDS_FOURCC('D', 'X', 'T', '3'))
                pinfo->Format = Image_DXT3;
            else if (v == SF_DDS_FOURCC('D', 'X', 'T', '1'))
                pinfo->Format = Image_DXT1;
            else
                return false;   // DXT2/DXT4 and anything else
            buf += 20;          // rest of the pixel format
        }
        else if ((pfflags & DDSPF_RGB) || (pfflags & DDSPF_ALPHA))
        {
            // Uncompressed: 32/24-bit RGB or alpha-only A8.
            UInt32 bitCount;
            buf = ParseUInt32(buf, &bitCount);
            pinfo->DDSFmt.RGBBitCount = bitCount;
            switch (bitCount)
            {
            case 32: pinfo->Format = Image_R8G8B8A8; break;
            case 24: pinfo->Format = Image_R8G8B8;   break;
            case 8:
                if (pfflags & DDSPF_ALPHA)
                {
                    pinfo->Format = Image_A8;
                    break;
                }
            default:
                return false;
            }
            if (!(flags & DDSF_PITCH))
                pinfo->Pitch = pinfo->Width * (bitCount / 8);

            buf = ParseUInt32(buf, &v);
            pinfo->DDSFmt.RBitMask = v;
            buf = ParseUInt32(buf, &v);
            pinfo->DDSFmt.GBitMask = v;
            buf = ParseUInt32(buf, &v);
            pinfo->DDSFmt.BBitMask = v;
            buf = ParseUInt32(buf, &v);
            if (pfflags & DDSPF_ALPHAPIXELS)
            {
                pinfo->DDSFmt.ABitMask = v;
                pinfo->DDSFmt.HasAlpha = true;
            }
        }
        if (pinfo->Format == Image_None)
            return false;
    }
    else
        buf += 32;

    buf += 16;  // ddsCaps
    buf += 4;   // reserved
    if (pdata)
        *pdata = buf;
    return true;
}

// Moves the masked channels of an uncompressed scanline into R, G, B(, A) byte order.
static bool ProcessUDDSData(UByte* buffer, UPInt size, ImageFormat format, const DDSDescr& ddsFmt)
{
    if (format == Image_R8G8B8)
    {
        for (unsigned x = 0; x < size; x += 3)
        {
            UInt32 val = buffer[x + 0] | (UInt32(buffer[x + 1]) << 8) | (UInt32(buffer[x + 2]) << 16);
            buffer[x + 2] = UByte((val >> ddsFmt.ShiftB) & 0xFF);
            buffer[x + 1] = UByte((val >> ddsFmt.ShiftG) & 0xFF);
            buffer[x + 0] = UByte((val >> ddsFmt.ShiftR) & 0xFF);
        }
    }
    else if (format == Image_R8G8B8A8)
    {
        for (unsigned x = 0; x < size; x += 4)
        {
            UInt32 val = buffer[x + 0] | (UInt32(buffer[x + 1]) << 8) |
                         (UInt32(buffer[x + 2]) << 16) | (UInt32(buffer[x + 3]) << 24);
            buffer[x + 2] = UByte((val >> ddsFmt.ShiftB) & 0xFF);
            buffer[x + 1] = UByte((val >> ddsFmt.ShiftG) & 0xFF);
            buffer[x + 0] = UByte((val >> ddsFmt.ShiftR) & 0xFF);
            if (ddsFmt.HasAlpha)
                buffer[x + 3] = UByte((val >> ddsFmt.ShiftA) & 0xFF);
            else
                buffer[x + 3] = 0xFF;
        }
    }
    return true;
}

// @0x1425a1b10
bool DDSFileImageSource::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    if (!seekFileToDecodeStart())
        return false;

    unsigned mipWidth  = Size.Width;
    unsigned mipHeight = Size.Height;

    for (unsigned m = 0; m < pdest->GetMipLevelCount(); m++)
    {
        ImagePlane mipPlane;
        if (pdest->HasSeparateMipmaps())
            pdest->GetMipLevelPlane(m, 0, &mipPlane);
        else
            pdest->GetPlaneRef().GetMipLevel(pdest->GetFormat(), m, &mipPlane);

        ImageScanlineBuffer<1024 * 4> scanline(HeaderInfo.Format, mipWidth, Format);
        int readSize = (int)scanline.GetReadSize();
        if (!scanline.IsValid())
            return false;

        for (unsigned y = 0; y < ImageData::GetFormatScanlineCount(Format, mipHeight); y++)
        {
            if (pFile->Read(scanline.GetReadBuffer(), readSize) != readSize)
                return false;
            if (Format == Image_R8G8B8A8 || Format == Image_R8G8B8)
                ProcessUDDSData(scanline.GetReadBuffer(), readSize, Format, HeaderInfo.DDSFmt);

            UByte* destScanline = mipPlane.GetScanline(y);
            scanline.ConvertReadBuffer(destScanline, 0, copyScanline, arg);
        }
        mipWidth  = Alg::Max(1u, mipWidth / 2);
        mipHeight = Alg::Max(1u, mipHeight / 2);
    }
    return true;
}

bool DDSFileImageSource::ReadHeader()
{
    UInt32 fourcc;
    bool   oppEndian = false;

    pFile->Read((UByte*)&fourcc, sizeof(UInt32));
    if (fourcc != SF_DDS_FOURCC('D', 'D', 'S', ' '))
    {
        // byte-swapped on a big endian platform; a no-op here
        oppEndian = true;
    }
    if (fourcc != SF_DDS_FOURCC('D', 'D', 'S', ' '))
        return false;

    UInt32 sz = pFile->ReadUInt32();
    if (sz != 124)
        return false;

    UByte buf[256];
    if (pFile->Read(buf, 120) != 120)
        return false;
    if (!Image_ParseDDSHeader(&HeaderInfo, buf, 0))
        return false;

    HeaderInfo.OppositeEndian = oppEndian;
    HeaderInfo.DDSFmt.CalcShifts();
    if (Format == Image_None)
        Format = HeaderInfo.Format;
    Size    = ImageSize(HeaderInfo.Width, HeaderInfo.Height);
    FilePos = pFile->LTell();
    return true;
}

// @0x1425a1700
bool FileReader::MatchFormat(File* file, UByte* headerArg, UPInt headerArgSize) const
{
    FileHeaderReader<4> header(file, headerArg, headerArgSize);
    if (!header)
        return false;
    if ((header[0] != 'D') || (header[1] != 'D') || (header[2] != 'S') || (header[3] != ' '))
        return false;
    return true;
}

// @0x1425a1780
ImageSource* FileReader::ReadImageSource(File* file, const ImageCreateArgs& args) const
{
    if (!file || !file->IsValid())
        return 0;
    DDSFileImageSource* source = SF_NEW DDSFileImageSource(file, args.Format);
    if (source && !source->ReadHeader())
    {
        source->Release();
        return 0;
    }
    return source;
}

FileReader FileReader::Instance;

}}} // namespace Scaleform::Render::DDS

// MS2-PIN: ?CalcShifts@DDSDescr@DDS@Render@Scaleform@@QEAAXXZ 0x1425a19d0
// MS2-PIN: ??_G?$ImageFileReader_Mixin@VFileReader@DDS@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@UEAAPEAXI@Z 0x1425a16c0
// MS2-PIN: ??_GFileReader@DDS@Render@Scaleform@@UEAAPEAXI@Z 0x1425a1920
// MS2-PIN: ??_GDDSFileImageSource@DDS@Render@Scaleform@@UEAAPEAXI@Z 0x1425a1960
// MS2-PIN: ??_7?$ImageFileReader_Mixin@VFileReader@DDS@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@6B@ 0x143185828
// MS2-PIN: ??_7FileReader@DDS@Render@Scaleform@@6B@ 0x143185860
// MS2-PIN: ??_7DDSFileImageSource@DDS@Render@Scaleform@@6B@ 0x143185898
// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// MS2-PIN: ??_7ImageFileReader@Render@Scaleform@@6B@ 0x143184f40
