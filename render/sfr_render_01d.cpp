// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 Render: image file handlers - the
// default ImageFileReader::Read, the any-image path of ImageFileWriter, and the handler registry the loader uses to
// pick a reader or writer by format or by file signature.
// Queue unit sfr_render_01 is split along its original sources (sfr_render_01 Render_Image, 01b Render_Context +
// Renderer2D, 01c Text_StyledText, 01d Render_ImageFile).
// MS2-UNIT: sfr_render_01d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142591050-0x1425916c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <stdarg.h>
#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render {

// Readers only produce an image source; the image itself is made compatible with what the caller asked for.
// @0x142591340
Image* ImageFileReader::Read(File* file, const ImageCreateArgs& args) const
{
    Ptr<ImageSource> source = *ReadImageSource(file);
    return source ? source->CreateCompatibleImage(args) : 0;
}

// @0x142591500
bool ImageFileWriter::writeImage(File* file, const ImageFileWriter* writer, Image* image, const ImageWriteArgs* args)
{
    Ptr<RawImage> decoded;
    ImageData     data;
    bool          mapped = false;

    if (image->GetImageType() == Image::Type_RawImage)
    {
        ((RawImage*)image->GetAsImage())->GetImageData(&data);
    }
    else if (image->GetUse() & ImageUse_MapSimThread)
    {
        if (!image->Map(&data))
            return false;
        mapped = true;
    }
    else
    {
        // neither raw nor mappable: decode into a system-memory copy first
        decoded = *RawImage::Create(image->GetFormat(), 1, image->GetSize(), 0);
        if (!decoded)
            return false;
        decoded->GetImageData(&data);
        if (!image->Decode(&data))
            return false;
    }

    bool ok = writer->Write(file, data, args);
    if (mapped)
        image->Unmap();
    return ok;
}

// @0x142591050
ImageFileHandlerRegistry::ImageFileHandlerRegistry(unsigned handlerCount, ...)
{
    va_list handlers;
    va_start(handlers, handlerCount);
    for (unsigned i = 0; i < handlerCount; i++)
    {
        ImageFileHandler* handler = va_arg(handlers, ImageFileHandler*);
        if (handler)
            Handlers.PushBack(handler);
    }
    va_end(handlers);
}

// @0x142591120
void ImageFileHandlerRegistry::AddHandler(ImageFileHandler* handler)
{
    Handlers.PushBack(handler);
}

// @0x142591240
ImageFileReader* ImageFileHandlerRegistry::GetReader(ImageFileFormat format)
{
    for (UPInt i = 0; i < Handlers.GetSize(); i++)
        if (Handlers[i]->IsReader() && Handlers[i]->GetFormat() == format)
            return (ImageFileReader*)Handlers[i];
    return 0;
}

// @0x1425912c0
ImageFileWriter* ImageFileHandlerRegistry::GetWriter(ImageFileFormat format)
{
    for (UPInt i = 0; i < Handlers.GetSize(); i++)
        if (Handlers[i]->IsWriter() && Handlers[i]->GetFormat() == format)
            return (ImageFileWriter*)Handlers[i];
    return 0;
}

// The first reader that recognizes the signature wins; preader may be null.
// @0x142591190
ImageFileFormat ImageFileHandlerRegistry::DetectFormat(ImageFileReader** preader, File* file, UByte* header,
                                                       UPInt headerSize)
{
    ImageFileReader* unused = 0;
    if (!preader)
        preader = &unused;

    for (UPInt i = 0; i < Handlers.GetSize(); i++)
    {
        if (Handlers[i]->IsReader())
        {
            ImageFileReader* reader = (ImageFileReader*)Handlers[i];
            if (reader->MatchFormat(file, header, headerSize))
            {
                *preader = reader;
                return (*preader)->GetFormat();
            }
        }
    }
    *preader = 0;
    return ImageFile_Unknown;
}

// @0x1425913c0
Image* ImageFileHandlerRegistry::ReadImage(File* file, const ImageCreateArgs& args) const
{
    for (UPInt i = 0; i < Handlers.GetSize(); i++)
    {
        if (Handlers[i]->IsReader())
        {
            ImageFileReader* reader = (ImageFileReader*)Handlers[i];
            if (reader->MatchFormat(file))
                return reader->Read(file, args);
        }
    }
    return 0;
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7ImageFileHandlerRegistry@Render@Scaleform@@6B@ 0x1431094d0
