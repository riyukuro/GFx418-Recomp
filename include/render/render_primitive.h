// Recovered Scaleform 4.1.18 Render: primitive fills. Only what the recovered units call so far: the fill manager
// keeps a cache of gradient images and a GradientImage unregisters itself on destruction.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVE_H
#define MS2_SF_RENDER_PRIMITIVE_H

#include "ms2/scaleform/include/render/render_gradients.h"

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

// what a provider reports for one fill: its type, color or image / gradient, and vertex format (0x20 bytes)
class FillData
{
public:
    FillType     Type;          // +0x00
    union                       // +0x08: Color for a solid fill, else the image / gradient
    {
        UInt32   Color;
        void*    pData;
    };
    unsigned     PrimFill;      // +0x10 (4 by default, 1 for a solid fill)
    bool         FillMode;      // +0x14
    const void*  pVFormat;      // +0x18

    FillData(FillType type);    // 0x14266bc00 (Render_Primitive)
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
