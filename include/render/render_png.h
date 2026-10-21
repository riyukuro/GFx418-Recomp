// Recovered Scaleform 4.1.18 Render: the PNG image file reader and writer (libpng 1.6.17 underneath).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Input vftable: dtor 0, ReadData 1, ReadScanline 2, Decode 3, GetSize 4 (0x143185638, the libpng input's 0x143185670).
// FileReader adds CreateInput at slot 7 (vftable 0x1431855a8); FileWriter vftable 0x143185610.
// FileReader::Instance sits in .data at 0x143a2efc0, FileWriter::Instance at 0x143a2efc8.
// Bodies live in sfr_render_02f (PNG_ImageReader).
#ifndef MS2_SF_RENDER_PNG_H
#define MS2_SF_RENDER_PNG_H

#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render { namespace PNG {

// A decoder over one open PNG file.
class Input : public NewOverrideBase<Stat_Default_Mem>
{
public:
    virtual ~Input() {}
    virtual int       ReadData(void** ppData) = 0;
    virtual int       ReadScanline(UByte* prgbData) = 0;
    virtual bool      Decode(ImageFormat format, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                             void* arg) = 0;
    virtual ImageSize GetSize() const = 0;
};

class FileReader : public ImageFileReader_Mixin<FileReader>
{
public:
    virtual ImageFileFormat GetFormat() const { return ImageFile_PNG; }
    virtual Input*          CreateInput(File* pin) const;
    virtual bool            MatchFormat(File* file, UByte* header, UPInt headerSize) const;
    virtual ImageSource*    ReadImageSource(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const;

    static FileReader Instance;
};

class FileWriter : public ImageFileWriter_Mixin<FileWriter>
{
public:
    virtual ImageFileFormat GetFormat() const { return ImageFile_PNG; }
    virtual bool            Write(File* file, const ImageData& imageData, const ImageWriteArgs* args = 0) const;

    static FileWriter Instance;
};

}}} // namespace Scaleform::Render::PNG

#endif
