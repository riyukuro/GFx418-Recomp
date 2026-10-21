// Recovered Scaleform 4.1.18 Render: primitive fills. Only what the recovered units call so far: the fill manager
// keeps a cache of gradient images and a GradientImage unregisters itself on destruction.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVE_H
#define MS2_SF_RENDER_PRIMITIVE_H

#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/render/render_fillmode.h"

namespace Scaleform { namespace Render {

// (appended for the shape cache nodes, sfr_render_03f)
class PrimitiveFill;
class TextureManager;

enum FillType
{
    Fill_None,
    Fill_Mask,
    Fill_SolidColor,
    Fill_VColor,
    Fill_Image,
    Fill_Gradient,
    Fill_VColor_TestKey
};

class Image;
struct VertexFormat;

// the shader input a fill needs (FillData::PrimFill)
enum PrimitiveFillType
{
    PrimFill_None,
    PrimFill_Mask,
    PrimFill_SolidColor,
    PrimFill_VColor,
    PrimFill_VColor_EAlpha,
    PrimFill_Texture,
    PrimFill_Texture_EAlpha,
    PrimFill_Texture_VColor,
    PrimFill_Texture_VColor_EAlpha,
    PrimFill_2Texture,
    PrimFill_2Texture_EAlpha,
    PrimFill_UVTexture,
    PrimFill_UVTextureAlpha_VColor,
    PrimFill_UVTextureDFAlpha_VColor
};

// what a provider reports for one fill: its type, color or image / gradient, and vertex format (0x20 bytes)
class FillData
{
public:
    FillType     Type;          // +0x00
    union                       // +0x08: Color for a solid fill, else the image / gradient
    {
        UInt32        Color;
        GradientData* pGradient;
        Image*        pImage;
    };
    unsigned      PrimFill;     // +0x10 (4 by default, 1 for a solid fill)
    ImageFillMode FillMode;     // +0x14
    const VertexFormat* pVFormat; // +0x18

    FillData(FillType type);    // 0x14266bc00 (Render_Primitive)
    // (appended for sfr_render_03d) Render_Primitive: 0x14266bba0, 0x14266bbd0
    FillData(GradientData* gradient);
    FillData(Image* image, ImageFillMode fillMode);
};

// (appended for sfr_render_03d) the vertex layouts a shape mesh fill names
struct VertexXY16iCF32
{
    static VertexFormat Format;   // 0x143a2fbe8
};
struct Image9GridVertex
{
    static VertexFormat Format;   // 0x143a2f968
};

class PrimitiveFillManager
{
    friend class GradientImage;
    void removeGradient(GradientImage* img);    // 0x14266f380 (Render_Primitive)

public:
    // the shared fill for fillData (0x14266d170); a gradient fill reports its image through gradientImage
    PrimitiveFill* CreateFill(const FillData& fillData, Ptr<Image>* gradientImage, TextureManager* textureManager,
                              float morphRatio);
};

}} // namespace Scaleform::Render

#endif
