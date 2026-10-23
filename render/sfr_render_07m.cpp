// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the texture helpers
// (Render_TextureUtil): scanline converters between the 8-bit-per-channel formats and their lookup table, plane /
// image conversion, the bilinear mip level generator and the rescale entry points the HALs call.
// Queue unit sfr_render_07 is split along its original sources (07m Render_TextureUtil).
// MS2-UNIT: sfr_render_07m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d4e40-0x1426d5e40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_textureutil.h"
#include "ms2/scaleform/include/render/render_resizeimage.h"

namespace Scaleform { namespace Render {

// Scanline converters: size is the byte count of the 3- or 4-byte side as named by the loop step.

// @0x1426d4e40
void SF_STDCALL Image_CopyScanline24_SwapBR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 3, ps += 3)
    {
        pd[0] = ps[2];
        pd[1] = ps[1];
        pd[2] = ps[0];
    }
}

// @0x1426d4ea0
void SF_STDCALL Image_CopyScanline32_SwapBR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 4, pd += 4, ps += 4)
    {
        pd[0] = ps[2];
        pd[1] = ps[1];
        pd[2] = ps[0];
        pd[3] = ps[3];
    }
}

// @0x1426d4ef0
void SF_STDCALL Image_CopyScanline24_Extend_RGB_RGBA(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 4, ps += 3)
    {
        pd[0] = ps[0];
        pd[1] = ps[1];
        pd[2] = ps[2];
        pd[3] = 0xFF;
    }
}

// @0x1426d4f50
void SF_STDCALL Image_CopyScanline24_Extend_RGB_BGRA(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 4, ps += 3)
    {
        pd[0] = ps[2];
        pd[1] = ps[1];
        pd[2] = ps[0];
        pd[3] = 0xFF;
    }
}

// @0x1426d4fb0
void SF_STDCALL Image_CopyScanline_BGRA_BGR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 4, pd += 3, ps += 4)
    {
        pd[0] = ps[0];
        pd[1] = ps[1];
        pd[2] = ps[2];
    }
}

// @0x1426d5000
void SF_STDCALL Image_CopyScanline_BGRA_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 4, pd += 3, ps += 4)
    {
        pd[0] = ps[2];
        pd[1] = ps[1];
        pd[2] = ps[0];
    }
}

// @0x1426d5050
void SF_STDCALL Image_CopyScanline_BGRA_A(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 4, pd++, ps += 4)
        pd[0] = ps[3];
}

// gray from the channel average
// @0x1426d5080
void SF_STDCALL Image_CopyScanline_BGR_A_Avg(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd++, ps += 3)
        pd[0] = UByte((unsigned(ps[0]) + ps[1] + ps[2]) / 3);
}

// @0x1426d50e0
void SF_STDCALL Image_CopyScanline_A_BGRA(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 4, ps++)
    {
        pd[0] = 0xFF;
        pd[1] = 0xFF;
        pd[2] = 0xFF;
        pd[3] = ps[0];
    }
}

// @0x1426d5110
void SF_STDCALL Image_CopyScanline_A_BGR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 3, ps++)
    {
        pd[0] = ps[0];
        pd[1] = ps[0];
        pd[2] = ps[0];
    }
}

// Palette lookups. The 4-byte forms store the alpha over the third channel and leave the fourth byte untouched,
// as the exe does.

// @0x1426d5150
void SF_STDCALL Image_CopyScanline_P_BGRA(UByte* pd, const UByte* ps, UPInt size, Palette* colorMap, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 4, ps++)
    {
        Color c = (*colorMap)[ps[0]];
        pd[0] = c.GetBlue();
        pd[1] = c.GetGreen();
        pd[2] = c.GetRed();
        pd[2] = c.GetAlpha();
    }
}

// @0x1426d5190
void SF_STDCALL Image_CopyScanline_P_RGBA(UByte* pd, const UByte* ps, UPInt size, Palette* colorMap, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 4, ps++)
    {
        Color c = (*colorMap)[ps[0]];
        pd[0] = c.GetRed();
        pd[1] = c.GetGreen();
        pd[2] = c.GetBlue();
        pd[2] = c.GetAlpha();
    }
}

// @0x1426d51e0
void SF_STDCALL Image_CopyScanline_P_BGR(UByte* pd, const UByte* ps, UPInt size, Palette* colorMap, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 3, ps++)
    {
        Color c = (*colorMap)[ps[0]];
        pd[0] = c.GetBlue();
        pd[1] = c.GetGreen();
        pd[2] = c.GetRed();
    }
}

// @0x1426d5220
void SF_STDCALL Image_CopyScanline_P_RGB(UByte* pd, const UByte* ps, UPInt size, Palette* colorMap, void*)
{
    for (UPInt i = 0; i < size; i++, pd += 3, ps++)
    {
        Color c = (*colorMap)[ps[0]];
        pd[0] = c.GetRed();
        pd[1] = c.GetGreen();
        pd[2] = c.GetBlue();
    }
}

// alpha of the entry, or its gray level when the palette has no alpha
// @0x1426d5260
void SF_STDCALL Image_CopyScanline_P_A(UByte* pd, const UByte* ps, UPInt size, Palette* colorMap, void*)
{
    for (UPInt i = 0; i < size; i++, pd++, ps++)
    {
        Color c = (*colorMap)[ps[0]];
        if (colorMap->HasAlpha())
            pd[0] = c.GetAlpha();
        else
            pd[0] = UByte((unsigned(c.GetRed()) + unsigned(c.GetGreen()) + unsigned(c.GetBlue())) / 3);
    }
}

// The plane index passed on is planeCount % formatPlaneCount (not the plane's own index), as in the exe.
// @0x1426d52c0
void SF_STDCALL ConvertImageData(ImageData& dest, ImageData& src, Image::CopyScanlineFunc copyScanline,
                                 void* scanlineArg)
{
    ImageFormat format           = src.GetFormat();
    unsigned    formatPlaneCount = ImageData::GetFormatPlaneCount(format);
    unsigned    planeCount       = src.GetPlaneCount();

    for (unsigned iplane = 0; iplane < planeCount; iplane++)
    {
        ImagePlane splane, dplane;
        src.GetPlane(iplane, &splane);
        dest.GetPlane(iplane, &dplane);
        ConvertImagePlane(dplane, splane, format, planeCount % formatPlaneCount, copyScanline,
                          dest.GetColorMap(), scanlineArg);
    }
}

// @0x1426d5420
void SF_STDCALL ConvertImagePlane(const ImagePlane& dplane, const ImagePlane& splane, ImageFormat format,
                                  unsigned formatPlaneIndex, Image::CopyScanlineFunc copyScanline,
                                  Palette* pcolorMap, void* scanlineArg)
{
    // compressed formats have fewer scanlines than rows
    UPInt bitsPerPixel  = ImageData::GetFormatBitsPerPixel(format, formatPlaneIndex);
    UPInt scanlineCount = ImageData::GetFormatScanlineCount(format, splane.Height, formatPlaneIndex);

    UByte* ps = splane.pData;
    UByte* pd = dplane.pData;
    for (UPInt line = 0; line < scanlineCount; line++, ps += splane.Pitch, pd += dplane.Pitch)
        copyScanline(pd, ps, (bitsPerPixel * splane.Width) / 8, pcolorMap, scanlineArg);
}

// The next mip level of splane into dplane (they may be the same plane): bilinear samples in 10-bit fixed point,
// starting a quarter step in so the second sample never runs past the last pixel.
// @0x1426d54e0
void SF_STDCALL GenerateMipLevel(ImagePlane& dplane, ImagePlane& splane, ImageFormat format, unsigned)
{
    enum
    {
        Shift = 10,
        One   = 1 << Shift,
        Mask  = One - 1
    };
    UPInt    spitch = splane.Pitch;
    UPInt    dpitch = dplane.Pitch;
    unsigned dx     = (splane.Width * One) / dplane.Width;
    unsigned dy     = (splane.Height * One) / dplane.Height;
    unsigned x, y, fx, fy;

    if (splane.Width != 1 && splane.Height != 1)
    {
        for (y = 0, fy = (dy - 1) / 4; y < dplane.Height; y++, fy += dy)
        {
            UByte*   out  = dplane.pData + y * dpitch;
            UByte*   row  = splane.pData + (fy >> Shift) * spitch;
            unsigned wy   = fy & Mask;
            unsigned wy1  = Mask - wy;

            switch (format & ~ImageFormat_Convertible)
            {
            case Image_R8G8B8A8:
            case Image_B8G8R8A8:
                for (x = 0, fx = (dx - 1) / 4; x < dplane.Width; x++, fx += dx)
                {
                    unsigned wx  = fx & Mask;
                    unsigned wx1 = Mask - wx;
                    UByte*   in  = row + (fx >> Shift) * 4;

                    unsigned c0 = (in[0] * wx + in[4] * wx1) * wy + (in[0 + spitch] * wx + in[4 + spitch] * wx1) * wy1;
                    unsigned c1 = (in[1] * wx + in[5] * wx1) * wy + (in[1 + spitch] * wx + in[5 + spitch] * wx1) * wy1;
                    unsigned c2 = (in[2] * wx + in[6] * wx1) * wy + (in[2 + spitch] * wx + in[6 + spitch] * wx1) * wy1;
                    unsigned c3 = (in[3] * wx + in[7] * wx1) * wy + (in[3 + spitch] * wx + in[7 + spitch] * wx1) * wy1;

                    out[0] = UByte(c0 >> (Shift * 2));
                    out[1] = UByte(c1 >> (Shift * 2));
                    out[2] = UByte(c2 >> (Shift * 2));
                    out[3] = UByte(c3 >> (Shift * 2));
                    out += 4;
                }
                break;

            case Image_A8:
            case Image_Y8_U2_V2:
            case Image_Y8_U2_V2_A8:
                for (x = 0, fx = (dx - 1) / 4; x < dplane.Width; x++, fx += dx)
                {
                    unsigned wx  = fx & Mask;
                    unsigned wx1 = Mask - wx;
                    UByte*   in  = row + (fx >> Shift);

                    unsigned c = (in[0] * wx + in[1] * wx1) * wy + (in[0 + spitch] * wx + in[1 + spitch] * wx1) * wy1;
                    out[0] = UByte(c >> (Shift * 2));
                    out++;
                }
                break;
            }
        }
    }
    else if (splane.Width != 1)
    {
        // a single row: horizontal samples only
        UByte* out = dplane.pData;
        UByte* row = splane.pData;

        switch (format & ~ImageFormat_Convertible)
        {
        case Image_R8G8B8A8:
        case Image_B8G8R8A8:
            for (x = 0, fx = (dx - 1) / 4; x < dplane.Width; x++, fx += dx)
            {
                unsigned wx  = fx & Mask;
                unsigned wx1 = Mask - wx;
                UByte*   in  = row + (fx >> Shift) * 4;

                unsigned c0 = in[0] * wx + in[4] * wx1;
                unsigned c1 = in[1] * wx + in[5] * wx1;
                unsigned c2 = in[2] * wx + in[6] * wx1;
                unsigned c3 = in[3] * wx + in[7] * wx1;

                out[0] = UByte(c0 >> Shift);
                out[1] = UByte(c1 >> Shift);
                out[2] = UByte(c2 >> Shift);
                out[3] = UByte(c3 >> Shift);
                out += 4;
            }
            break;

        case Image_A8:
        case Image_Y8_U2_V2:
        case Image_Y8_U2_V2_A8:
            for (x = 0, fx = (dx - 1) / 4; x < dplane.Width; x++, fx += dx)
            {
                unsigned wx  = fx & Mask;
                unsigned wx1 = Mask - wx;
                UByte*   in  = row + (fx >> Shift);
                unsigned c   = in[0] * wx + in[1] * wx1;
                out[0] = UByte(c >> Shift);
                out++;
            }
            break;
        }
    }
    else if (splane.Height != 1)
    {
        // a single column: vertical samples only
        UByte* out = dplane.pData;
        UByte* col = splane.pData;

        switch (format & ~ImageFormat_Convertible)
        {
        case Image_R8G8B8A8:
        case Image_B8G8R8A8:
            for (y = 0, fy = (dy - 1) / 4; y < dplane.Height; y++, fy += dy)
            {
                UByte*   in  = col + (fy >> Shift) * spitch;
                unsigned wy  = fy & Mask;
                unsigned wy1 = Mask - wy;

                unsigned c0 = in[0] * wy + in[0 + spitch] * wy1;
                unsigned c1 = in[1] * wy + in[1 + spitch] * wy1;
                unsigned c2 = in[2] * wy + in[2 + spitch] * wy1;
                unsigned c3 = in[3] * wy + in[3 + spitch] * wy1;

                out[0] = UByte(c0 >> Shift);
                out[1] = UByte(c1 >> Shift);
                out[2] = UByte(c2 >> Shift);
                out[3] = UByte(c3 >> Shift);
                out += dpitch;
            }
            break;

        case Image_A8:
        case Image_Y8_U2_V2:
        case Image_Y8_U2_V2_A8:
            for (y = 0, fy = (dy - 1) / 4; y < dplane.Height; y++, fy += dy)
            {
                UByte*   in  = col + (fy >> Shift) * spitch;
                unsigned wy  = fy & Mask;
                unsigned wy1 = Mask - wy;

                unsigned c = in[0] * wy + in[0 + spitch] * wy1;
                out[0] = UByte(c >> Shift);
                out += dpitch;
            }
            break;
        }
    }
}

// source / dest format pairs the converters handle; ends with Image_None
struct ScanlineConvert
{
    ImageFormat             Source;
    ImageFormat             Dest;
    Image::CopyScanlineFunc CopyFunc;
};

static ScanlineConvert ImageScanlineConvertTable[] =
{
    { Image_R8G8B8A8, Image_B8G8R8A8, Image_CopyScanline32_SwapBR },
    { Image_R8G8B8A8, Image_R8G8B8,   Image_CopyScanline_BGRA_BGR },
    { Image_R8G8B8A8, Image_R8G8B8,   Image_CopyScanline_BGRA_RGB },
    { Image_R8G8B8A8, Image_A8,       Image_CopyScanline_BGRA_A },

    { Image_B8G8R8A8, Image_R8G8B8A8, Image_CopyScanline32_SwapBR },
    { Image_B8G8R8A8, Image_B8G8R8,   Image_CopyScanline_BGRA_BGR },
    { Image_B8G8R8A8, Image_R8G8B8,   Image_CopyScanline_BGRA_RGB },
    { Image_B8G8R8A8, Image_A8,       Image_CopyScanline_BGRA_A },

    { Image_R8G8B8,   Image_B8G8R8A8, Image_CopyScanline24_Extend_RGB_BGRA },
    { Image_R8G8B8,   Image_R8G8B8A8, Image_CopyScanline24_Extend_RGB_RGBA },
    { Image_R8G8B8,   Image_A8,       Image_CopyScanline_BGR_A_Avg },
    { Image_R8G8B8,   Image_B8G8R8,   Image_CopyScanline24_SwapBR },

    { Image_B8G8R8,   Image_B8G8R8A8, Image_CopyScanline24_Extend_RGB_RGBA },
    { Image_B8G8R8,   Image_R8G8B8A8, Image_CopyScanline24_Extend_RGB_BGRA },
    { Image_B8G8R8,   Image_A8,       Image_CopyScanline_BGR_A_Avg },
    { Image_B8G8R8,   Image_R8G8B8,   Image_CopyScanline24_SwapBR },

    { Image_A8,       Image_B8G8R8A8, Image_CopyScanline_A_BGRA },
    { Image_A8,       Image_R8G8B8A8, Image_CopyScanline_A_BGRA },
    { Image_A8,       Image_B8G8R8,   Image_CopyScanline_A_BGR },
    { Image_A8,       Image_R8G8B8,   Image_CopyScanline_A_BGR },

    { Image_P8,       Image_B8G8R8A8, Image_CopyScanline_P_BGRA },
    { Image_P8,       Image_R8G8B8A8, Image_CopyScanline_P_RGBA },
    { Image_P8,       Image_B8G8R8,   Image_CopyScanline_P_BGR },
    { Image_P8,       Image_R8G8B8,   Image_CopyScanline_P_RGB },
    { Image_P8,       Image_A8,       Image_CopyScanline_P_A },

    { Image_None,     Image_None,     0 }
};

// the converter from sourceFormat scanlines to destFormat ones, 0 when there is none
// @0x1426d5aa0
Image::CopyScanlineFunc SF_STDCALL GetImageConvertFunc(ImageFormat destFormat, ImageFormat sourceFormat)
{
    if (destFormat == sourceFormat)
        return &Image::CopyScanlineDefault;

    for (ScanlineConvert* entry = ImageScanlineConvertTable; entry->Source != Image_None; entry++)
    {
        if (entry->Source == sourceFormat && entry->Dest == destFormat)
            return entry->CopyFunc;
    }
    return 0;
}

// @0x1426d5ae0
ImageRescaleType SF_STDCALL GetImageFormatRescaleType(ImageFormat format)
{
    switch (format)
    {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
        return ResizeRgbaToRgba;
    case Image_R8G8B8:
    case Image_B8G8R8:
        return ResizeRgbToRgb;
    case Image_A8:
        return ResizeGray;
    default:
        break;
    }
    return ResizeNone;
}

// Converters to and from the alpha-first layouts (unused by the table).

// @0x1426d5b10
void SF_STDCALL Image_CopyScanline24_Extend_RGB_ABGR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 4, ps += 3)
    {
        pd[0] = 0xFF;
        pd[1] = ps[2];
        pd[2] = ps[1];
        pd[3] = ps[0];
    }
}

// @0x1426d5b70
void SF_STDCALL Image_CopyScanline24_Extend_RGB_ARGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 4, ps += 3)
    {
        pd[0] = 0xFF;
        pd[1] = ps[0];
        pd[2] = ps[1];
        pd[3] = ps[2];
    }
}

// @0x1426d5bd0
void SF_STDCALL Image_CopyScanline32_RGBA_ARGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 4, pd += 4, ps += 4)
    {
        pd[0] = ps[3];
        pd[1] = ps[0];
        pd[2] = ps[1];
        pd[3] = ps[2];
    }
}

// The retracting forms step by the 3-byte destination.

// @0x1426d5c20
void SF_STDCALL Image_CopyScanline32_Retract_ARGB_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 3, ps += 4)
    {
        pd[0] = ps[1];
        pd[1] = ps[2];
        pd[2] = ps[3];
    }
}

// @0x1426d5c80
void SF_STDCALL Image_CopyScanline32_Retract_BGRA_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 3, ps += 4)
    {
        pd[0] = ps[2];
        pd[1] = ps[1];
        pd[2] = ps[0];
    }
}

// @0x1426d5ce0
void SF_STDCALL Image_CopyScanline32_Retract_RGBA_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*)
{
    for (UPInt i = 0; i < size; i += 3, pd += 3, ps += 4)
    {
        pd[0] = ps[0];
        pd[1] = ps[1];
        pd[2] = ps[2];
    }
}

// @0x1426d5d40
void SF_STDCALL RescaleImageData(ImageData& dest, ImageData& src, ResizeImageType resizeType)
{
    unsigned planeCount = src.GetPlaneCount();
    for (unsigned iplane = 0; iplane < planeCount; iplane++)
    {
        ImagePlane splane, dplane;
        src.GetPlane(iplane, &splane);
        dest.GetPlane(iplane, &dplane);
        ResizeImageBilinear(dplane.pData, dplane.Width, dplane.Height, (int)dplane.Pitch,
                            splane.pData, splane.Width, splane.Height, (int)splane.Pitch, resizeType);
    }
}

}} // namespace Scaleform::Render
