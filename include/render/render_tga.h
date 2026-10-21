// Recovered Scaleform 4.1.18 Render: the TGA image file reader (uncompressed true-color and color-mapped images).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// FileReader::Instance sits in .data at 0x143a2efb0 (vftable 0x143184fb0). Bodies live in sfr_render_02d
// (TGA_ImageReader).
#ifndef MS2_SF_RENDER_TGA_H
#define MS2_SF_RENDER_TGA_H

#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render { namespace TGA {

class FileReader : public ImageFileReader_Mixin<FileReader>
{
public:
    virtual ImageFileFormat GetFormat() const { return ImageFile_TGA; }

    virtual bool         MatchFormat(File* file, UByte* header, UPInt headerSize) const;
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const;

    static FileReader Instance;
};

enum TGAColorMapType
{
    TGAColorMap_NotIncluded = 0,
    TGAColorMap_Included    = 1
};

enum TGAImageType
{
    TGAImage_NoData            = 0,
    TGAImage_ColorMapped       = 1,
    TGAImage_TrueColor         = 2,
    TGAImage_BlackAndWhite     = 3,
    TGAImage_RLE_ColorMapped   = 9,
    TGAImage_RLE_TrueColor     = 10,
    TGAImage_RLE_BlackAndWhite = 11
};

enum TGAImageDescBits
{
    TGAImageDesc_TopToBottom  = 0x20,
    TGAImageDesc_LeftToRight  = 0x10,
    TGAImageDesc_ZeroMaskBits = 0xC0    // reserved, must be 0
};

}}} // namespace Scaleform::Render::TGA

#endif
