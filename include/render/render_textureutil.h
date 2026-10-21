// Recovered Scaleform 4.1.18 Render: the texture helper functions the HALs use to convert, rescale and mip-map image
// data (Render_TextureUtil section, 0x1426d4ea0-0x1426d5f00). Declarations only; written from the exe, names from the
// SDK headers. Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_RENDER_TEXTUREUTIL_H
#define MS2_SF_RENDER_TEXTUREUTIL_H

#include "ms2/scaleform/include/render/render_image.h"

namespace Scaleform { namespace Render {

// How the resizer treats a pixel format.
enum ResizeImageType
{
    ResizeNone,
    ResizeRgbToRgb,
    ResizeRgbaToRgba,
    ResizeRgbToRgba,
    ResizeGray
};
typedef ResizeImageType ImageRescaleType;

ImageRescaleType SF_STDCALL GetImageFormatRescaleType(ImageFormat format);
void SF_STDCALL RescaleImageData(ImageData& dest, ImageData& src, ResizeImageType resizeType);       // 0x1426d5d40
void SF_STDCALL ConvertImagePlane(const ImagePlane& dplane, const ImagePlane& splane, ImageFormat format,
                                  unsigned formatPlaneIndex, Image::CopyScanlineFunc copyScanline,
                                  Palette* pcolorMap, void* scanlineArg = 0);                          // 0x1426d5420
void SF_STDCALL ConvertImageData(ImageData& dest, ImageData& src, Image::CopyScanlineFunc copyScanline,
                                 void* scanlineArg = 0);
void SF_STDCALL GenerateMipLevel(ImagePlane& dplane, ImagePlane& splane, ImageFormat format,
                                 unsigned formatPlaneIndex);                                           // 0x1426d54e0

void SF_STDCALL Image_CopyScanline32_SwapBR(UByte* pd, const UByte* ps, UPInt size, Palette*, void*);           // 0x1426d4ea0
void SF_STDCALL Image_CopyScanline24_Extend_RGB_RGBA(UByte* pd, const UByte* ps, UPInt size, Palette*, void*);  // 0x1426d4ef0
void SF_STDCALL Image_CopyScanline24_Extend_RGB_BGRA(UByte* pd, const UByte* ps, UPInt size, Palette*, void*);  // 0x1426d4f50
void SF_STDCALL Image_CopyScanline32_Retract_BGRA_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*); // 0x1426d5c80
void SF_STDCALL Image_CopyScanline32_Retract_RGBA_RGB(UByte* pd, const UByte* ps, UPInt size, Palette*, void*); // 0x1426d5ce0

}} // namespace Scaleform::Render

#endif
