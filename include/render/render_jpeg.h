// Recovered Scaleform 4.1.18 Render: the JPEG image file reader (IJG jpeg-6b underneath) and the JPEG data a SWF
// loader keeps (the separate encoding tables of DefineBits).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// AbstractReader vftable 0x143185070, ImageFileReader_Mixin<FileReader, AbstractReader> 0x1431850d8, FileReader
// 0x143185140: ImageFileReader 0-6, CreateImageSource 7, CreateMemoryBufferImage 8, CreateWrapperImageSource 9,
// CreateInput 10, CreateSwfJpeg2HeaderOnly(buffer) 11, CreateSwfJpeg2HeaderOnly(File*) 12.
// FileReader::Instance sits in .data at 0x143a2efb8.
// Input vftable 0x1431852a8 (11 slots, below). MemoryBufferImage 0x68 bytes (vftable 0x143185300).
// Bodies live in sfr_render_02g (JPEG_ImageReader); JpegErrorHandler's with JPEG_ImageCommon (0x14264d350..).
#ifndef MS2_SF_RENDER_JPEG_H
#define MS2_SF_RENDER_JPEG_H

#include "ms2/scaleform/include/render/render_imagefile.h"
#include "ms2/scaleform/include/render/render_imagefileutil.h"

namespace Scaleform { namespace Render { namespace JPEG {

class Input;
struct ExtraData;

class AbstractReader : public ImageFileReader
{
public:
    virtual ImageFileFormat GetFormat() const { return ImageFile_JPEG; }
    virtual ImageSource* CreateImageSource(File* file, const ImageCreateArgs& args, ExtraData* hdr, UInt64 len,
                                           bool withHeaders = false) const = 0;
    virtual Render::MemoryBufferImage* CreateMemoryBufferImage(File* file, const ImageCreateArgs& args,
                                                               const ImageSize& sz, UInt64 length) = 0;
    virtual ImageSource* CreateWrapperImageSource(Render::Image* memImage) const = 0;
    virtual Input*       CreateInput(File* pin) const = 0;
    virtual Input*       CreateSwfJpeg2HeaderOnly(File* pin) const = 0;
    virtual Input*       CreateSwfJpeg2HeaderOnly(const UByte* pbuffer, UPInt bufSize) const = 0;
};

// Extra JPEG data kept next to an image: the encoding tables when IsTableHeader.
struct ExtraData : public RefCountBase<ExtraData, Stat_Default_Mem>
{
    UByte* Data;    // +0x10
    UPInt  Size;    // +0x18

    ExtraData() : Data(0), Size(0) {}
    ExtraData(MemoryHeap* heap, UPInt sz) : Size(sz)
    {
        Data = (UByte*)SF_HEAP_ALLOC(heap, sz, Stat_Default_Mem);
    }
    virtual ~ExtraData()
    {
        SF_FREE(Data);
    }

    bool         IsEmpty() const { return Size == 0; }
    virtual bool IsTableHeader() const { return false; }
};

struct TablesHeader : public ExtraData
{
    TablesHeader(MemoryHeap* heap, UPInt sz) : ExtraData(heap, sz) {}

    virtual bool IsTableHeader() const { return true; }
};

class FileReader : public ImageFileReader_Mixin<FileReader, AbstractReader>
{
public:
    virtual bool         MatchFormat(File* file, UByte* header, UPInt headerSize) const;
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args) const;

    virtual ImageSource* CreateImageSource(File* file, const ImageCreateArgs& args, ExtraData* hdr, UInt64 len,
                                           bool withHeaders = false) const;
    virtual Render::MemoryBufferImage* CreateMemoryBufferImage(File* file, const ImageCreateArgs& args,
                                                               const ImageSize& sz, UInt64 length);
    virtual ImageSource* CreateWrapperImageSource(Render::Image* memImage) const;
    virtual Input*       CreateInput(File* pin) const;
    virtual Input*       CreateSwfJpeg2HeaderOnly(File* pin) const;
    virtual Input*       CreateSwfJpeg2HeaderOnly(const UByte* pbuffer, UPInt bufSize) const;

    static FileReader Instance;
};

// A decoder over one JPEG stream (or over the tables alone, with the image data supplied later).
class Input : public NewOverrideBase<Stat_Default_Mem>
{
public:
    virtual ~Input() {}

    virtual void      DiscardPartialBuffer() = 0;
    virtual bool      StartImage() = 0;
    virtual bool      StartRawImage() = 0;
    virtual bool      FinishImage() = 0;
    virtual bool      AbortImage() = 0;
    virtual ImageSize GetSize() const = 0;
    virtual bool      ReadScanline(UByte* prgbData) = 0;
    virtual bool      ReadRawData(void** pprawData) = 0;
    virtual void*     GetCInfo() = 0;
    virtual bool      HasError() const = 0;
};

// A JPEG kept compressed in memory. The low 2 bits of the ExtraData pointer are flags (bit 0: the image data
// relies on separate tables).
class MemoryBufferImage : public Render::MemoryBufferImage
{
    enum
    {
        Flag_Headers = 0x1,
        Mask_Flags   = 0x3
    };
    union
    {
        ExtraData* pExtraData;
        UPInt      Flags;
    };  // +0x60

    ExtraData* GetExtraData() const
    {
        union
        {
            ExtraData* pExtraData;
            UPInt      Flags;
        } u;
        u.Flags = (Flags & (~(UPInt)Mask_Flags));
        return u.pExtraData;
    }
    unsigned GetFlags() const { return unsigned(Flags) & Mask_Flags; }

public:
    MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync, File* file,
                      SInt64 filePos, UPInt length = 0, bool headers = false);
    MemoryBufferImage(ExtraData* exd, ImageFormat format, const ImageSize& size, unsigned use,
                      ImageUpdateSync* sync, File* file, SInt64 filePos, UPInt length = 0);
    MemoryBufferImage(ExtraData* exd, ImageFormat format, const ImageSize& size, unsigned use,
                      ImageUpdateSync* sync, const UByte* data, UPInt len);
    ~MemoryBufferImage();

    virtual bool Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
};

}}} // namespace Scaleform::Render::JPEG

#endif
