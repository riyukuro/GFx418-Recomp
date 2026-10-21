// Recovered Scaleform 4.1.18 Render: image file handlers (readers/writers of one file format) and the registry the
// loader asks for a handler.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//   ImageFileHandler vftable: dtor 0, GetFormat 1, IsReader 2, IsWriter 3;
//   ImageFileReader adds MatchFormat 4, ReadImageSource 5, Read 6; ImageFileWriter adds Write 4.
//   ImageFileHandlerRegistry (0x20 bytes, vftable 0x1431094d0): dtor 0, ReadImage 1; handler array at +0x8.
#ifndef MS2_SF_RENDER_IMAGEFILE_H
#define MS2_SF_RENDER_IMAGEFILE_H

#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_imagefileformat.h"

namespace Scaleform { class File; }

namespace Scaleform { namespace Render {

// What an image writer is asked to produce.
struct ImageWriteArgs
{
    ImageFileFormat FileFormat;

    ImageWriteArgs(ImageFileFormat format = ImageFile_Unknown) : FileFormat(format) {}
};

// One file format; a handler can read it, write it, or both.
class ImageFileHandler
{
public:
    virtual ~ImageFileHandler() {}
    virtual ImageFileFormat GetFormat() const { return ImageFile_Unknown; }
    virtual bool            IsReader() const  { return false; }
    virtual bool            IsWriter() const  { return false; }
};

class ImageFileReader : public ImageFileHandler
{
public:
    virtual bool IsReader() const { return true; }

    // Checks the file signature (header bytes may be passed in when already read).
    virtual bool         MatchFormat(File* file, UByte* header = 0, UPInt headerSize = 0) const = 0;
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const = 0;
    virtual Image*       Read(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const;
};

class ImageFileWriter : public ImageFileHandler
{
    friend class ImageFileHandlerRegistry;

protected:
    // Writes any image through writer: raw images directly, mappable ones mapped, the rest decoded into a copy.
    static bool writeImage(File* file, const ImageFileWriter* writer, Image* image, const ImageWriteArgs* args);

public:
    virtual bool IsWriter() const { return true; }
    virtual bool Write(File* file, const ImageData& imageData, const ImageWriteArgs* args = 0) const = 0;
};

// The set of handlers a loader searches, in registration order.
class ImageFileHandlerRegistry
{
    Array<ImageFileHandler*> Handlers;

public:
    // handlerCount handler pointers follow; null ones are skipped.
    ImageFileHandlerRegistry(unsigned handlerCount, ...);
    virtual ~ImageFileHandlerRegistry() {}

    void             AddHandler(ImageFileHandler* handler);
    ImageFileReader* GetReader(ImageFileFormat format);
    ImageFileWriter* GetWriter(ImageFileFormat format);
    ImageFileFormat  DetectFormat(ImageFileReader** preader, File* file, UByte* header = 0, UPInt headerSize = 0);

    virtual Image* ReadImage(File* file, const ImageCreateArgs& args = ImageCreateArgs()) const;
};

// Format handlers derive through these: D::Instance is the format's singleton.
template<class D, class B = ImageFileReader>
class ImageFileReader_Mixin : public B
{
public:
    static inline Image* ReadImage(File* file, const ImageCreateArgs& args = ImageCreateArgs())
    {
        return D::Instance.Read(file, args);
    }
};

template<class D, class B = ImageFileWriter>
class ImageFileWriter_Mixin : public B
{
public:
    static inline bool WriteImage(File* file, const ImageData& imageData, const ImageWriteArgs* args = 0)
    {
        return D::Instance.Write(file, imageData, args);
    }
};

}} // namespace Scaleform::Render

#endif
