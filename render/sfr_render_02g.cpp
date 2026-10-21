// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the JPEG reader TU
// (JPEG_ImageReader): the jpeglib decoder over a File or over SWF encoding tables, the file image source, the
// in-memory JPEG (with the tables kept aside) and the wrapper source of an existing memory image.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader, 02e DDS reader, 02f PNG reader, 02g JPEG reader).
// MS2-UNIT: sfr_render_02g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14259e560-0x1425a0300 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <setjmp.h>
#include "ms2/scaleform/include/render/render_jpeg.h"
#include "ms2/scaleform/kernel/sf_memoryfile.h"

#pragma warning(disable:4611)   // setjmp and C++ object destruction

// IJG jpeg-6b, linked as C in the exe (lib_jpeg), Windows configuration.
#include "../third_party/src/jpeg-6b/jconfig.vc"
#define JCONFIG_INCLUDED
#if defined(_BASETSD_H_)
#define XMD_H   // INT16/INT32 come from the Windows headers
#endif
extern "C" {
#include "../third_party/src/jpeg-6b/jpeglib.h"
}

namespace Scaleform { namespace Render { namespace JPEG {

enum GJPEGUtilConstants
{
    JPEG_BufferSize = 2048
};

// jpeglib error manager that longjmps back to the caller instead of exiting (0x178 bytes).
struct JpegErrorHandler
{
    struct jpeg_error_mgr pub;                      // +0x000
    char                  errorMessage[JMSG_LENGTH_MAX];  // +0x0a8
    jmp_buf*              psetjmp_buffer;           // +0x170

    JpegErrorHandler();
    ~JpegErrorHandler();
};

jpeg_error_mgr* SetupJpegErr(JpegErrorHandler* jerr);

#define SF_JPEG_SET_JMP(pcinfo, pjerr, rv)              \
    do {                                                \
        if (setjmp(*(pjerr)->psetjmp_buffer))           \
        {                                               \
            jpeg_destroy_decompress(pcinfo);            \
            return rv;                                  \
        }                                               \
    } while (0)

#define SF_JPEG_SET_JMP1(_this, rv)                     \
    do {                                                \
        if (setjmp(*(_this)->JErr.psetjmp_buffer))      \
        {                                               \
            jpeg_destroy_decompress(&(_this)->CInfo);   \
            (_this)->CompressorOpened = false;          \
            (_this)->ErrorOccurred = true;              \
            return rv;                                  \
        }                                               \
    } while (0)

static void GJPEGUtil_SetupRwSource(jpeg_decompress_struct* pcinfo, File* pinstream);
static void GJPEGUtil_ReplaceRwSource(jpeg_decompress_struct* pcinfo, File* pinstream);

// A jpeglib source manager reading from a File (0x848 bytes).
class JPEGRwSource : public NewOverrideBase<Stat_Default_Mem>
{
public:
    struct jpeg_source_mgr SMgr;                    // +0x00
    Ptr<File>              pInStream;               // +0x38
    bool                   StartOfFile;             // +0x40
    JOCTET                 Buffer[JPEG_BufferSize]; // +0x41

    // @0x14259ed60
    JPEGRwSource(File* pin)
    {
        pInStream   = pin;
        StartOfFile = 1;

        SMgr.init_source       = InitSource;
        SMgr.fill_input_buffer = FillInputBuffer;
        SMgr.skip_input_data   = SkipInputData;
        SMgr.resync_to_restart = jpeg_resync_to_restart;
        SMgr.term_source       = TermSource;
        SMgr.bytes_in_buffer   = 0;
        SMgr.next_input_byte   = NULL;
    }

    JPEGRwSource(const struct jpeg_source_mgr& smgr)
    {
        pInStream   = 0;
        StartOfFile = 1;
        SMgr        = smgr;
    }

    // @0x14259fe10
    static void InitSource(j_decompress_ptr cinfo)
    {
        JPEGRwSource* psrc = (JPEGRwSource*)cinfo->src;
        psrc->StartOfFile  = true;
    }

    // Refills the buffer; an empty stream past the start gets a fake EOI marker.
    // @0x14259fb00
    static boolean FillInputBuffer(j_decompress_ptr cinfo)
    {
        JPEGRwSource* psrc = (JPEGRwSource*)cinfo->src;

        UPInt bytesRead = psrc->pInStream->Read(psrc->Buffer, JPEG_BufferSize);

        if (bytesRead <= 0)
        {
            if (psrc->StartOfFile)
                return 0;

            psrc->Buffer[0] = (JOCTET)0xFF;
            psrc->Buffer[1] = (JOCTET)JPEG_EOI;
            bytesRead       = 2;
        }

        // Some SWF data starts with FFD9FFD8 instead of FFD8FFD9.
        if (psrc->StartOfFile && bytesRead >= 4)
        {
            if (psrc->Buffer[0] == 0xFF && psrc->Buffer[1] == 0xD9 && psrc->Buffer[2] == 0xFF &&
                psrc->Buffer[3] == 0xD8)
            {
                psrc->Buffer[1] = 0xD8;
                psrc->Buffer[3] = 0xD9;
            }
        }

        psrc->SMgr.next_input_byte = psrc->Buffer;
        psrc->SMgr.bytes_in_buffer = bytesRead;
        psrc->StartOfFile          = 0;
        return TRUE;
    }

    // @0x1425a0100
    static void SkipInputData(j_decompress_ptr cinfo, long numBytes)
    {
        JPEGRwSource* psrc = (JPEGRwSource*)cinfo->src;

        if (numBytes > 0)
        {
            while (numBytes > (long)psrc->SMgr.bytes_in_buffer)
            {
                numBytes -= (long)psrc->SMgr.bytes_in_buffer;
                FillInputBuffer(cinfo);
            }
            psrc->SMgr.next_input_byte += (UPInt)numBytes;
            psrc->SMgr.bytes_in_buffer -= (UPInt)numBytes;
        }
    }

    // @0x1425a02e0
    static void TermSource(j_decompress_ptr cinfo)
    {
        SF_UNUSED(cinfo);
    }

    void DiscardPartialBuffer()
    {
        SMgr.bytes_in_buffer = 0;
        SMgr.next_input_byte = NULL;
    }
};

void GJPEGUtil_SetupRwSource(jpeg_decompress_struct* cinfo, File* pinstream)
{
    cinfo->src = (jpeg_source_mgr*)SF_NEW JPEGRwSource(pinstream);
}

// @0x14259fc00
void GJPEGUtil_ReplaceRwSource(jpeg_decompress_struct* cinfo, File* pinstream)
{
    JPEGRwSource* psrc = (JPEGRwSource*)cinfo->src;
    delete psrc;
    cinfo->src = (jpeg_source_mgr*)SF_NEW JPEGRwSource(pinstream);
}

// The jpeglib decompressor (0x3e0 bytes).
class JPEGInputImpl_jpeglib : public Input
{
public:
    struct jpeg_decompress_struct CInfo;    // +0x008
    struct JpegErrorHandler       JErr;     // +0x260

private:
    static int JpegCreateDecompress(jpeg_decompress_struct* pcinfo, JpegErrorHandler* pjerr);
    static int JpegReadHeader(jpeg_decompress_struct* pcinfo, JpegErrorHandler* pjerr, bool require_image);

    // @0x14259fe00
    static void InitSource(j_decompress_ptr) {}
    // @0x1425a02d0
    static void TermSource(j_decompress_ptr) {}

public:
    bool CompressorOpened;  // +0x3d8
    bool ErrorOccurred;     // +0x3d9

    enum SWF_DEFINE_BITS_JPEG2_HEADER_ONLY { SWF_JPEG2_HEADER_ONLY };

    // Reads the header and starts decompressing.
    JPEGInputImpl_jpeglib(File* pin)
    {
        CompressorOpened = ErrorOccurred = false;

        CInfo.err = SetupJpegErr(&JErr);
        if (!JpegCreateDecompress(&CInfo, &JErr))
            return;

        GJPEGUtil_SetupRwSource(&CInfo, pin);
        StartImage();
    }

    // Reads the encoding tables only; StartImage reads the image later.
    JPEGInputImpl_jpeglib(SWF_DEFINE_BITS_JPEG2_HEADER_ONLY e, File* pin)
    {
        SF_UNUSED(e);
        CompressorOpened = ErrorOccurred = false;

        CInfo.err = SetupJpegErr(&JErr);
        if (!JpegCreateDecompress(&CInfo, &JErr))
            return;

        GJPEGUtil_SetupRwSource(&CInfo, pin);
        JpegReadHeader(&CInfo, &JErr, FALSE);
    }

    JPEGInputImpl_jpeglib(SWF_DEFINE_BITS_JPEG2_HEADER_ONLY e, const UByte* pbuf, UPInt bufSize)
    {
        SF_UNUSED(e);
        struct jpeg_source_mgr smgr;
        memset(&smgr, 0, sizeof(smgr));
        smgr.bytes_in_buffer = bufSize;
        smgr.next_input_byte = pbuf;
        smgr.init_source     = InitSource;
        smgr.term_source     = TermSource;

        CompressorOpened = ErrorOccurred = false;

        CInfo.err = SetupJpegErr(&JErr);
        if (!JpegCreateDecompress(&CInfo, &JErr))
            return;

        CInfo.src = (jpeg_source_mgr*)SF_NEW JPEGRwSource(smgr);
        JpegReadHeader(&CInfo, &JErr, FALSE);
    }

    ~JPEGInputImpl_jpeglib()
    {
        FinishImage();

        JPEGRwSource* psrc = (JPEGRwSource*)CInfo.src;
        delete psrc;
        CInfo.src = NULL;

        jpeg_destroy_decompress(&CInfo);
    }

    bool HasError() const { return ErrorOccurred; }

    void DiscardPartialBuffer()
    {
        JPEGRwSource* psrc = (JPEGRwSource*)CInfo.src;
        if (psrc)
            psrc->DiscardPartialBuffer();
    }

    bool StartImage();
    bool StartRawImage();
    bool FinishImage();
    bool AbortImage();

    ImageSize GetSize() const { return ImageSize(CInfo.output_width, CInfo.output_height); }

    bool ReadScanline(unsigned char* prgbData);
    bool ReadRawData(void** pprawData);

    void* GetCInfo() { return &CInfo; }
};

// A stream already past its header (global state DSTATE_READY, 202) is not read again.
// @0x1425a01e0
bool JPEGInputImpl_jpeglib::StartImage()
{
    if (ErrorOccurred)
        return false;
    SF_JPEG_SET_JMP1(this, false);

    if (CInfo.global_state != 202)
        jpeg_read_header(&CInfo, TRUE);
    jpeg_start_decompress(&CInfo);
    CompressorOpened = true;
    return true;
}

// @0x1425a0260
bool JPEGInputImpl_jpeglib::StartRawImage()
{
    if (ErrorOccurred)
        return false;
    SF_JPEG_SET_JMP1(this, false);

    if (CInfo.global_state != 202)
        jpeg_read_header(&CInfo, TRUE);
    CompressorOpened = true;
    return true;
}

// @0x14259fb90
bool JPEGInputImpl_jpeglib::FinishImage()
{
    if (ErrorOccurred)
        return false;
    if (CompressorOpened)
    {
        SF_JPEG_SET_JMP1(this, false);
        jpeg_finish_decompress(&CInfo);
        CompressorOpened = false;
    }
    return true;
}

// @0x14259f420
bool JPEGInputImpl_jpeglib::AbortImage()
{
    if (ErrorOccurred)
        return false;
    if (CompressorOpened)
    {
        SF_JPEG_SET_JMP1(this, false);
        jpeg_abort_decompress(&CInfo);
        CompressorOpened = false;
    }
    return true;
}

// @0x1425a0090
bool JPEGInputImpl_jpeglib::ReadScanline(unsigned char* prgbData)
{
    if (ErrorOccurred)
        return false;
    SF_JPEG_SET_JMP1(this, false);

    jpeg_read_scanlines(&CInfo, &prgbData, 1);
    return true;
}

// @0x1425a0020
bool JPEGInputImpl_jpeglib::ReadRawData(void** pprawData)
{
    if (ErrorOccurred)
        return false;
    SF_JPEG_SET_JMP1(this, false);

    jvirt_barray_ptr* src_coef_arrays = jpeg_read_coefficients(&CInfo);
    *pprawData = src_coef_arrays;
    return true;
}

// @0x14259fe20
int JPEGInputImpl_jpeglib::JpegCreateDecompress(jpeg_decompress_struct* pcinfo, JpegErrorHandler* pjerr)
{
    SF_JPEG_SET_JMP(pcinfo, pjerr, 0);
    jpeg_create_decompress(pcinfo);
    return 1;
}

// @0x14259fe70
int JPEGInputImpl_jpeglib::JpegReadHeader(jpeg_decompress_struct* pcinfo, JpegErrorHandler* pjerr,
                                          bool require_image)
{
    SF_JPEG_SET_JMP(pcinfo, pjerr, 0);
    jpeg_read_header(pcinfo, require_image);
    return 1;
}

// Reads the image as RGB a scanline at a time, converting into pdest; deletes jin.
// @0x14259f9a0
static bool DecodeHelper(ImageFormat format, Input* jin, ImageData* pdest, Image::CopyScanlineFunc copyScanline,
                         void* arg)
{
    ImageSize                     size    = jin->GetSize();
    bool                          success = false;
    ImageScanlineBuffer<1024 * 4> scanline(Image_R8G8B8, size.Width, format);

    if (scanline.IsValid() && !jin->HasError())
    {
        success = true;
        for (unsigned y = 0; y < size.Height; y++)
        {
            if (!jin->ReadScanline(scanline.GetReadBuffer()))
            {
                success = false;
                break;
            }
            UByte* destScanline = pdest->GetScanline(y);
            scanline.ConvertReadBuffer(destScanline, 0, copyScanline, arg);
        }
    }

    delete jin;
    return success;
}

// ---------------------------------------------------------------------------------------------------------------
// JPEG::ImageSource

// A JPEG file, or SWF image data whose tables are in exd or (withHeaders) at the start of the data (0x58 bytes).
class ImageSource : public FileImageSource
{
    mutable Input* pOriginalInput;  // +0x40
    Ptr<ExtraData> pExtraData;      // +0x48
    bool           WithHeaders;     // +0x50

public:
    // @0x14259ed00
    ImageSource(File* file, ImageFormat format = Image_None, ExtraData* exd = 0, UInt64 len = 0,
                bool withHeaders = false)
        : FileImageSource(file, format, len), pOriginalInput(0), pExtraData(exd), WithHeaders(withHeaders)
    {
    }

    ~ImageSource()
    {
        if (pOriginalInput)
        {
            pOriginalInput->AbortImage();
            delete pOriginalInput;
        }
    }

    bool ReadHeader();

    virtual bool     Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
    virtual Image*   CreateCompatibleImage(const ImageCreateArgs& args);
    virtual unsigned GetMipmapCount() const { return 1; }
};

// @0x14259fec0
bool ImageSource::ReadHeader()
{
    if (!pExtraData || !pExtraData->IsTableHeader())
    {
        if (!WithHeaders)
            pOriginalInput = FileReader::Instance.CreateInput(pFile);
        else
        {
            pOriginalInput = FileReader::Instance.CreateSwfJpeg2HeaderOnly(pFile);
            pOriginalInput->StartImage();
        }
    }
    else
    {
        // The tables come from the extra data, the image from the file.
        pOriginalInput = FileReader::Instance.CreateSwfJpeg2HeaderOnly(pExtraData->Data, pExtraData->Size);
        struct jpeg_decompress_struct* cinfo =
            static_cast<struct jpeg_decompress_struct*>(pOriginalInput->GetCInfo());
        GJPEGUtil_ReplaceRwSource(cinfo, pFile);
        pOriginalInput->StartImage();
    }
    if (!pOriginalInput)
        return false;
    Size = pOriginalInput->GetSize();
    if (Format == Image_None)
        Format = Image_R8G8B8;
    return true;
}

// The input left over from ReadHeader is used once, saving a second header read on load.
// @0x14259f700
bool ImageSource::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    Input* jin = pOriginalInput;

    if (jin)
        pOriginalInput = 0;
    else
    {
        if (!seekFileToDecodeStart())
            return false;
        jin = FileReader::Instance.CreateInput(pFile);
        if (!jin)
            return 0;
    }
    return DecodeHelper(Format, jin, pdest, copyScanline, arg);
}

// ---------------------------------------------------------------------------------------------------------------
// JPEG::MemoryBufferImage

// @0x14259ef40
MemoryBufferImage::MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync,
                                     File* file, SInt64 filePos, UPInt length, bool headers)
    : Render::MemoryBufferImage(format, size, use, sync, file, filePos, length), pExtraData(0)
{
    if (headers)
        Flags |= Flag_Headers;
}

// @0x14259edf0
MemoryBufferImage::MemoryBufferImage(ExtraData* exd, ImageFormat format, const ImageSize& size, unsigned use,
                                     ImageUpdateSync* sync, File* file, SInt64 filePos, UPInt length)
    : Render::MemoryBufferImage(format, size, use, sync, file, filePos, length), pExtraData(exd)
{
    if (pExtraData)
    {
        pExtraData->AddRef();
        if (pExtraData->IsTableHeader())
            Flags |= Flag_Headers;
    }
}

// @0x14259eea0
MemoryBufferImage::MemoryBufferImage(ExtraData* exd, ImageFormat format, const ImageSize& size, unsigned use,
                                     ImageUpdateSync* sync, const UByte* data, UPInt len)
    : Render::MemoryBufferImage(format, size, use, sync, data, len), pExtraData(exd)
{
    if (pExtraData)
    {
        pExtraData->AddRef();
        if (pExtraData->IsTableHeader())
            Flags |= Flag_Headers;
    }
}

// Only a tables header is released (the other extra data is not held).
// @0x14259efc0
MemoryBufferImage::~MemoryBufferImage()
{
    if ((Flags & Mask_Flags) && GetExtraData())
        GetExtraData()->Release();
}

// MS2-FUNCTIONAL: the exe inlines ~MemoryFile; here it binds to the game code's out-of-line copy
// @0x14259f780
bool MemoryBufferImage::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    MemoryFile file(FilePath, &FileData[0], (int)FileData.GetSize());
    Input*     jin;
    if (GetExtraData() == 0)
    {
        jin = FileReader::Instance.CreateSwfJpeg2HeaderOnly(&file);
        jin->StartImage();
    }
    else
    {
        jin = FileReader::Instance.CreateSwfJpeg2HeaderOnly(GetExtraData()->Data, GetExtraData()->Size);
        struct jpeg_decompress_struct* cinfo = static_cast<struct jpeg_decompress_struct*>(jin->GetCInfo());
        GJPEGUtil_ReplaceRwSource(cinfo, &file);
        jin->StartImage();
    }
    return DecodeHelper(Format, jin, pdest, copyScanline, arg);
}

// @0x14259f490
Image* ImageSource::CreateCompatibleImage(const ImageCreateArgs& args)
{
    if (IsDecodeOnlyImageCompatible(args))
    {
        if (pExtraData)
            return SF_HEAP_NEW(args.GetHeap())
                MemoryBufferImage(pExtraData, GetFormat(), GetSize(), args.Use, args.GetUpdateSync(), pFile, FilePos,
                                  (UPInt)FileLen);
        else
            return SF_HEAP_NEW(args.GetHeap())
                MemoryBufferImage(GetFormat(), GetSize(), args.Use, args.GetUpdateSync(), pFile, FilePos,
                                  (UPInt)FileLen, WithHeaders);
    }
    return Render::ImageSource::CreateCompatibleImage(args);
}

// ---------------------------------------------------------------------------------------------------------------
// JPEG::WrapperImageSource

// A memory JPEG image handed out as a source; its header is read when wrapped (0x20 bytes).
class WrapperImageSource : public Render::WrapperImageSource
{
    mutable Input* pOriginalInput;  // +0x18
public:
    WrapperImageSource(Image* pdelegate) : Render::WrapperImageSource(pdelegate), pOriginalInput(0) {}
    ~WrapperImageSource()
    {
        if (pOriginalInput)
        {
            pOriginalInput->AbortImage();
            delete pOriginalInput;
        }
    }

    bool ReadHeader();
};

// @0x14259ff90
bool WrapperImageSource::ReadHeader()
{
    Render::MemoryBufferImage* img = pDelegate->GetAsMemoryImage();
    if (img)
    {
        const UByte* fileData;
        UPInt        fileSz;
        img->GetImageDataBits(&fileData, &fileSz);

        pOriginalInput = FileReader::Instance.CreateSwfJpeg2HeaderOnly(fileData, fileSz);
        pOriginalInput->StartImage();
        if (!pOriginalInput)
            return false;

        img->SetImageSize(pOriginalInput->GetSize());
        if (img->GetFormat() == Image_None)
            img->SetFormat(Image_R8G8B8);
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// FileReader

// @0x14259e5c0
bool FileReader::MatchFormat(File* file, UByte* headerArg, UPInt headerArgSize) const
{
    FileHeaderReader<2> header(file, headerArg, headerArgSize);
    if (!header || (header[0] != 0xFF) || (header[1] != 0xD8))
        return false;
    return true;
}

// @0x14259e6e0
Render::ImageSource* FileReader::CreateImageSource(File* file, const ImageCreateArgs& args, ExtraData* exd,
                                                   UInt64 len, bool withHeaders) const
{
    if (!file || !file->IsValid())
        return 0;
    JPEG::ImageSource* source = SF_NEW JPEG::ImageSource(file, args.Format, exd, len, withHeaders);
    if (source && !source->ReadHeader())
    {
        source->Release();
        source = 0;
    }
    return source;
}

// @0x14259e790
Render::MemoryBufferImage* FileReader::CreateMemoryBufferImage(File* file, const ImageCreateArgs& args,
                                                               const ImageSize& sz, UInt64 length)
{
    return SF_HEAP_NEW(args.GetHeap())
        MemoryBufferImage(Image_None, sz, args.Use, args.GetUpdateSync(), file, file->LTell(), (UPInt)length);
}

// @0x14259e860
Render::ImageSource* FileReader::CreateWrapperImageSource(Render::Image* memImage) const
{
    JPEG::WrapperImageSource* source = SF_NEW JPEG::WrapperImageSource(memImage);
    if (source && !source->ReadHeader())
    {
        source->Release();
        source = 0;
    }
    return source;
}

// @0x14259e630
Render::ImageSource* FileReader::ReadImageSource(File* file, const ImageCreateArgs& args) const
{
    if (!file || !file->IsValid())
        return 0;
    JPEG::ImageSource* source = SF_NEW JPEG::ImageSource(file, args.Format);
    if (source && !source->ReadHeader())
    {
        source->Release();
        source = 0;
    }
    return source;
}

// @0x14259e960
Input* FileReader::CreateInput(File* pin) const
{
    if (!pin || !pin->IsValid())
        return 0;
    return SF_NEW JPEGInputImpl_jpeglib(pin);
}

// @0x14259ea80
Input* FileReader::CreateSwfJpeg2HeaderOnly(File* pin) const
{
    if (!pin || !pin->IsValid())
        return 0;
    return SF_NEW JPEGInputImpl_jpeglib(JPEGInputImpl_jpeglib::SWF_JPEG2_HEADER_ONLY, pin);
}

// @0x14259eb80
Input* FileReader::CreateSwfJpeg2HeaderOnly(const UByte* pbuffer, UPInt bufSize) const
{
    return SF_NEW JPEGInputImpl_jpeglib(JPEGInputImpl_jpeglib::SWF_JPEG2_HEADER_ONLY, pbuffer, bufSize);
}

FileReader FileReader::Instance;

}}} // namespace Scaleform::Render::JPEG

// MS2-PIN: ??_GAbstractReader@JPEG@Render@Scaleform@@UEAAPEAXI@Z 0x14259e560
// MS2-PIN: ??_G?$ImageFileReader_Mixin@VFileReader@JPEG@Render@Scaleform@@VAbstractReader@234@@Render@Scaleform@@UEAAPEAXI@Z 0x14259e590
// MS2-PIN: ??_GFileReader@JPEG@Render@Scaleform@@UEAAPEAXI@Z 0x14259ecd0
// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// MS2-PIN: ??_7ImageFileReader@Render@Scaleform@@6B@ 0x143184f40
// MS2-PIN: ??_7AbstractReader@JPEG@Render@Scaleform@@6B@ 0x143185070
// MS2-PIN: ??_7?$ImageFileReader_Mixin@VFileReader@JPEG@Render@Scaleform@@VAbstractReader@234@@Render@Scaleform@@6B@ 0x1431850d8
// MS2-PIN: ??_7FileReader@JPEG@Render@Scaleform@@6B@ 0x143185140
// MS2-PIN: ??_7ImageSource@Render@Scaleform@@6B@ 0x1431851a8
// MS2-PIN: ??_7WrapperImageSource@Render@Scaleform@@6B@ 0x143185228
// MS2-PIN: ??_7Input@JPEG@Render@Scaleform@@6B@ 0x1431852a8
// MS2-PIN: ??_7MemoryBufferImage@JPEG@Render@Scaleform@@6B@ 0x143185300
// MS2-PIN: ??_7JPEGInputImpl_jpeglib@JPEG@Render@Scaleform@@6B@ 0x1431853e8
// MS2-PIN: ??_7ImageSource@JPEG@Render@Scaleform@@6B@ 0x143185440
// MS2-PIN: ??_7WrapperImageSource@JPEG@Render@Scaleform@@6B@ 0x1431854c8
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
