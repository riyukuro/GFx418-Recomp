// Recovered Scaleform 4.1.18 Render: the DDS image file reader (DXT1/3/5 and uncompressed 32/24-bit RGB, A8).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// FileReader::Instance sits in .data at 0x143a2efd0 (vftable 0x143185860). Bodies live in sfr_render_02e
// (DDS_ImageReader).
#ifndef MS2_SF_RENDER_DDS_H
#define MS2_SF_RENDER_DDS_H

#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render { namespace DDS {

class FileReader : public ImageFileReader_Mixin<FileReader>
{
public:
    virtual ImageFileFormat GetFormat() const { return ImageFile_DDS; }

    virtual bool         MatchFormat(File* file, UByte* header, UPInt headerSize) const;
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const;

    static FileReader Instance;
};

}}} // namespace Scaleform::Render::DDS

#endif
