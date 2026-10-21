// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the PNG reader/writer TU
// (PNG_ImageReader): the libpng input (signature check, header transforms to 8-bit RGB(A), row or whole-image
// decode), the file image source and in-memory image built on it, and the RGB(A) writer.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader, 02e DDS reader, 02f PNG reader).
// MS2-UNIT: sfr_render_02f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a0300-0x1425a16c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <setjmp.h>
#include "ms2/scaleform/include/render/render_png.h"
#include "ms2/scaleform/include/render/render_imagefileutil.h"
#include "ms2/scaleform/kernel/sf_memoryfile.h"

#pragma warning(disable:4611)   // setjmp and C++ object destruction

// The part of the libpng 1.6.17 API used here; the library in the exe is linked as C (lib_png).
struct png_struct_def;
struct png_info_def;
typedef png_struct_def  png_struct;
typedef png_info_def    png_info;
typedef png_struct*     png_structp;
typedef png_struct**    png_structpp;
typedef png_info*       png_infop;
typedef png_info**      png_infopp;
typedef unsigned int    png_uint_32;
typedef size_t          png_size_t;
typedef unsigned char   png_byte;
typedef png_byte*       png_bytep;
typedef png_byte**      png_bytepp;
typedef void*           png_voidp;
typedef const char*     png_const_charp;

typedef void (__cdecl* png_error_ptr)(png_structp, png_const_charp);
typedef void (__cdecl* png_rw_ptr)(png_structp, png_bytep, png_size_t);
typedef void (__cdecl* png_flush_ptr)(png_structp);
typedef void (__cdecl* png_longjmp_ptr)(jmp_buf, int);

extern "C" {
png_structp png_create_read_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn,
                                   png_error_ptr warn_fn);
png_structp png_create_write_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn,
                                    png_error_ptr warn_fn);
png_infop   png_create_info_struct(const png_struct* png_ptr);
void        png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr);
jmp_buf*    png_set_longjmp_fn(png_structp png_ptr, png_longjmp_ptr longjmp_fn, size_t jmp_buf_size);
__declspec(noreturn) void png_longjmp(const png_struct* png_ptr, int val);
__declspec(noreturn) void png_error(const png_struct* png_ptr, png_const_charp error_message);
png_voidp   png_get_error_ptr(const png_struct* png_ptr);
png_voidp   png_get_io_ptr(const png_struct* png_ptr);
void        png_set_read_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);
void        png_set_write_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr write_data_fn,
                             png_flush_ptr output_flush_fn);
void        png_set_sig_bytes(png_structp png_ptr, int num_bytes);
int         png_sig_cmp(const png_byte* sig, png_size_t start, png_size_t num_to_check);
void        png_read_info(png_structp png_ptr, png_infop info_ptr);
void        png_read_update_info(png_structp png_ptr, png_infop info_ptr);
void        png_read_row(png_structp png_ptr, png_bytep row, png_bytep display_row);
void        png_read_image(png_structp png_ptr, png_bytepp image);
void        png_read_end(png_structp png_ptr, png_infop info_ptr);
png_uint_32 png_get_IHDR(const png_struct* png_ptr, const png_info* info_ptr, png_uint_32* width,
                         png_uint_32* height, int* bit_depth, int* color_type, int* interlace_method,
                         int* compression_method, int* filter_method);
png_uint_32 png_get_valid(const png_struct* png_ptr, const png_info* info_ptr, png_uint_32 flag);
png_uint_32 png_get_gAMA(const png_struct* png_ptr, const png_info* info_ptr, double* file_gamma);
png_size_t  png_get_rowbytes(const png_struct* png_ptr, const png_info* info_ptr);
void        png_set_strip_16(png_structp png_ptr);
void        png_set_palette_to_rgb(png_structp png_ptr);
void        png_set_expand_gray_1_2_4_to_8(png_structp png_ptr);
void        png_set_tRNS_to_alpha(png_structp png_ptr);
void        png_set_gray_to_rgb(png_structp png_ptr);
void        png_set_gamma(png_structp png_ptr, double screen_gamma, double override_file_gamma);
void        png_set_IHDR(const png_struct* png_ptr, png_infop info_ptr, png_uint_32 width, png_uint_32 height,
                         int bit_depth, int color_type, int interlace_method, int compression_method,
                         int filter_method);
void        png_write_info(png_structp png_ptr, const png_info* info_ptr);
void        png_write_image(png_structp png_ptr, png_bytepp image);
void        png_write_end(png_structp png_ptr, png_infop info_ptr);
}

#define PNG_LIBPNG_VER_STRING       "1.6.17"
#define png_jmpbuf(png_ptr)         (*png_set_longjmp_fn((png_ptr), longjmp, sizeof(jmp_buf)))
#define png_check_sig(sig, n)       !png_sig_cmp((sig), 0, (n))

enum
{
    PNG_COLOR_TYPE_GRAY       = 0,
    PNG_COLOR_TYPE_PALETTE    = 3,
    PNG_COLOR_TYPE_RGB        = 2,
    PNG_COLOR_TYPE_RGB_ALPHA  = 6,
    PNG_COLOR_TYPE_GRAY_ALPHA = 4,
    PNG_INTERLACE_NONE        = 0,
    PNG_COMPRESSION_TYPE_BASE = 0,
    PNG_FILTER_TYPE_BASE      = 0,
    PNG_INFO_tRNS             = 0x10
};

namespace Scaleform { namespace Render { namespace PNG {

// The decode state handed to libpng as its error pointer (0x190 bytes).
struct PngContext
{
    png_structp png_ptr;            // +0x00
    png_infop   info_ptr;           // +0x08
    png_uint_32 width, height;      // +0x10
    int         bitDepth;           // +0x18
    int         colorType;          // +0x1c
    int         interlaceType;      // +0x20
    png_uint_32 ulRowBytes;         // +0x24
    char        errorMessage[100];  // +0x28
    char        filePath[256];      // +0x8c
};

// Keeps the message and unwinds to the caller's setjmp.
// @0x1425a1590
void png_error_handler(png_structp png_ptr, png_const_charp msg)
{
    UPInt mlen = SFstrlen(msg);

    PngContext* pcontext = (PngContext*)png_get_error_ptr(png_ptr);
    if (mlen < sizeof(pcontext->errorMessage))
        SFstrcpy(pcontext->errorMessage, sizeof(pcontext->errorMessage), msg);
    else
    {
        SFstrncpy(pcontext->errorMessage, sizeof(pcontext->errorMessage), msg, sizeof(pcontext->errorMessage) - 1);
        pcontext->errorMessage[sizeof(pcontext->errorMessage) - 1] = 0;
    }
    png_longjmp(png_ptr, 1);
}

// @0x1425a1600
void png_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
    File* pfile = reinterpret_cast<File*>(png_get_io_ptr(png_ptr));
    int   check = pfile->Read(data, (int)length);
    if (check < 0 || (png_size_t)check != length)
        png_error(png_ptr, "Read Error.");
}

// Reads the header and sets up the transforms to 8-bit RGB or RGBA; 0 on a libpng error.
// @0x1425a11f0
int GFxPngReadInfo(PngContext* context)
{
    double gamma;

    if (setjmp(png_jmpbuf(context->png_ptr)))
        return 0;

    png_set_sig_bytes(context->png_ptr, 8);
    png_read_info(context->png_ptr, context->info_ptr);
    png_get_IHDR(context->png_ptr, context->info_ptr, &context->width, &context->height, &context->bitDepth,
                 &context->colorType, &context->interlaceType, NULL, NULL);

    if (context->bitDepth == 16)
        png_set_strip_16(context->png_ptr);
    if (context->colorType == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(context->png_ptr);
    if (context->bitDepth < 8)
        png_set_expand_gray_1_2_4_to_8(context->png_ptr);
    if (png_get_valid(context->png_ptr, context->info_ptr, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(context->png_ptr);
    if (context->colorType == PNG_COLOR_TYPE_GRAY || context->colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(context->png_ptr);

    if (png_get_gAMA(context->png_ptr, context->info_ptr, &gamma))
        png_set_gamma(context->png_ptr, 2.2, gamma);

    png_read_update_info(context->png_ptr, context->info_ptr);
    png_get_IHDR(context->png_ptr, context->info_ptr, &context->width, &context->height, &context->bitDepth,
                 &context->colorType, &context->interlaceType, NULL, NULL);
    context->ulRowBytes = (png_uint_32)png_get_rowbytes(context->png_ptr, context->info_ptr);
    return 1;
}

// The libpng decoder of one file (0x1a8 bytes).
class LibPNGInput : public Input
{
    PngContext Context;     // +0x08
    Ptr<File>  pFile;       // +0x198
public:
    bool       IsInitialized;   // +0x1a0

    LibPNGInput(File* pin) : pFile(pin), IsInitialized(false)
    {
        png_byte sig[8];

        if (!pin || !pin->IsValid())
            return;

        memset(&Context, 0, sizeof(Context));
        SFstrcpy(Context.filePath, sizeof(Context.filePath), pin->GetFilePath());

        if (pin->Read(sig, 8) != 8 || !png_check_sig(sig, 8))
            return;
        StartImage();
    }
    virtual ~LibPNGInput();

    virtual int       ReadData(void** ppData);
    virtual int       ReadScanline(UByte* prgbData);
    virtual bool      Decode(ImageFormat format, ImageData* pdest, Image::CopyScanlineFunc copyScanline, void* arg);
    virtual ImageSize GetSize() const { return ImageSize(Context.width, Context.height); }

    bool IsValid() const { return IsInitialized; }
    bool StartImage();
};

// @0x1425a13a0
int LibPNGInput::ReadData(void** ppData)
{
    png_read_image(Context.png_ptr, (png_bytepp)ppData);
    return 1;
}

// @0x1425a1420
int LibPNGInput::ReadScanline(UByte* prgbData)
{
    png_read_row(Context.png_ptr, prgbData, NULL);
    return 1;
}

// Creates the libpng structures past the signature and reads the header; true once done.
// @0x1425a1480
bool LibPNGInput::StartImage()
{
    if (IsInitialized)
        return true;
    pFile->SeekToBegin();
    pFile->SkipBytes(8);

    Context.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, (png_voidp)&Context, png_error_handler, NULL);
    if (!Context.png_ptr)
        return false;

    Context.info_ptr = png_create_info_struct(Context.png_ptr);
    if (!Context.info_ptr)
    {
        png_destroy_read_struct(&Context.png_ptr, NULL, NULL);
        return false;
    }
    png_set_read_fn(Context.png_ptr, (png_voidp)pFile, png_read_data);

    if (!GFxPngReadInfo(&Context))
    {
        png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
        return false;
    }
    IsInitialized = true;
    return true;
}

// Non-interlaced images are read and converted a row at a time, interlaced ones whole first.
// @0x1425a0d20
bool LibPNGInput::Decode(ImageFormat format, ImageData* pdest, Image::CopyScanlineFunc copyScanline, void* arg)
{
    unsigned    srcScanLineSize = 0;
    bool        success = true;
    ImageFormat readFormat;

    if (!StartImage())
    {
        IsInitialized = false;
        return false;
    }
    switch (Context.colorType)
    {
    case PNG_COLOR_TYPE_RGB:       readFormat = Image_R8G8B8;   srcScanLineSize = Context.width * 3; break;
    case PNG_COLOR_TYPE_RGB_ALPHA: readFormat = Image_R8G8B8A8; srcScanLineSize = Context.width * 4; break;
    default:                       readFormat = Image_None; break;
    }
    if (Context.ulRowBytes != 0)
        srcScanLineSize = Context.ulRowBytes;
    srcScanLineSize = (srcScanLineSize + 3) & ~3u;

    if (readFormat != Image_None)
    {
        ImageScanlineBuffer<1024 * 4> scanline(readFormat, Context.width, format);
        png_bytepp rows = NULL;

        if (setjmp(png_jmpbuf(Context.png_ptr)))
        {
            png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
            SF_FREE(rows);
            IsInitialized = false;
            return false;
        }

        if (!Context.interlaceType)
        {
            for (unsigned y = 0; y < Context.height; y++)
            {
                if (!ReadScanline(scanline.GetReadBuffer()))
                {
                    success = false;
                    break;
                }
                scanline.ConvertReadBuffer(pdest->GetScanline(y), 0, copyScanline, arg);
            }
        }
        else
        {
            rows = (png_bytepp)SF_ALLOC(Context.height * sizeof(png_bytep) + Context.height * srcScanLineSize,
                                        Stat_Default_Mem);
            rows[0] = (png_bytep)(rows + Context.height);
            if (!rows)
            {
                png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
                IsInitialized = false;
                return false;
            }
            for (unsigned i = 1; i < Context.height; i++)
                rows[i] = rows[i - 1] + srcScanLineSize;

            if (!ReadData((void**)rows))
            {
                SF_FREE(rows);
                png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
                IsInitialized = false;
                return false;
            }

            ImageScanlineBuffer<1024 * 4> scanline(readFormat, Context.width, format);
            for (unsigned y = 0; y < Context.height; y++)
            {
                memcpy(scanline.GetReadBuffer(), rows[y], scanline.GetReadSize());
                scanline.ConvertReadBuffer(pdest->GetScanline(y), 0, copyScanline, arg);
            }
            SF_FREE(rows);
        }

        png_read_end(Context.png_ptr, NULL);
    }
    png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
    IsInitialized = false;
    return success;
}

// @0x1425a0940
LibPNGInput::~LibPNGInput()
{
    if (IsInitialized)
        png_destroy_read_struct(&Context.png_ptr, &Context.info_ptr, NULL);
}

// A PNG kept compressed in memory, decoded through a memory file on each request.
class MemoryBufferImage : public Render::MemoryBufferImage
{
public:
    MemoryBufferImage(ImageFormat format, const ImageSize& size, unsigned use, ImageUpdateSync* sync, File* file,
                      SInt64 filePos, UPInt length = 0)
        : Render::MemoryBufferImage(format, size, use, sync, file, filePos, length) {}

    virtual bool Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
};

// MS2-FUNCTIONAL: the exe inlines ~MemoryFile; here it binds to the game code's out-of-line copy
// @0x1425a1080
bool MemoryBufferImage::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    MemoryFile file(FilePath, &FileData[0], (int)FileData.GetSize());
    Input*     pin = FileReader::Instance.CreateInput(&file);
    if (!pin)
        return false;

    bool success = pin->Decode(Format, pdest, copyScanline, arg);
    delete pin;
    return success;
}

class PNGFileImageSource : public FileImageSource
{
    mutable Input* pOriginalInput;  // +0x40
public:
    PNGFileImageSource(File* file, ImageFormat format) : FileImageSource(file, format), pOriginalInput(0) {}
    virtual ~PNGFileImageSource();

    virtual bool     Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const;
    virtual Image*   CreateCompatibleImage(const ImageCreateArgs& args);
    virtual unsigned GetMipmapCount() const { return 1; }

    bool ReadHeader();
};

// @0x1425a0990
PNGFileImageSource::~PNGFileImageSource()
{
    if (pOriginalInput)
        delete pOriginalInput;
}

// @0x1425a11b0
bool PNGFileImageSource::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    return pOriginalInput ? pOriginalInput->Decode(Format, pdest, copyScanline, arg) : false;
}

// @0x1425a13c0
bool PNGFileImageSource::ReadHeader()
{
    pOriginalInput = FileReader::Instance.CreateInput(pFile);
    if (!pOriginalInput)
        return false;
    Size = pOriginalInput->GetSize();
    if (Format == Image_None)
        Format = Image_R8G8B8A8;
    return true;
}

// @0x1425a0be0
Image* PNGFileImageSource::CreateCompatibleImage(const ImageCreateArgs& args)
{
    if (IsDecodeOnlyImageCompatible(args))
    {
        return SF_HEAP_NEW(args.GetHeap())
            MemoryBufferImage(GetFormat(), GetSize(), args.Use, args.GetUpdateSync(), pFile, FilePos);
    }
    return ImageSource::CreateCompatibleImage(args);
}

// ---------------------------------------------------------------------------------------------------------------
// FileReader

// @0x1425a0490
bool FileReader::MatchFormat(File* file, UByte* headerArg, UPInt headerArgSize) const
{
    FileHeaderReader<8> header(file, headerArg, headerArgSize);
    if (!header)
        return false;
    if (!png_check_sig(header.GetPtr(), 8))
        return false;
    return true;
}

// @0x1425a0500
ImageSource* FileReader::ReadImageSource(File* file, const ImageCreateArgs& args) const
{
    if (!file || !file->IsValid())
        return 0;
    PNGFileImageSource* source = SF_NEW PNGFileImageSource(file, args.Format);
    if (source && !source->ReadHeader())
    {
        source->Release();
        source = 0;
    }
    return source;
}

// @0x1425a0370
Input* FileReader::CreateInput(File* pin) const
{
    if (!pin || !pin->IsValid())
        return 0;
    LibPNGInput* input = SF_NEW LibPNGInput(pin);
    if (input && input->IsValid())
        return input;
    delete input;
    return 0;
}

FileReader FileReader::Instance;

// ---------------------------------------------------------------------------------------------------------------
// FileWriter

// @0x1425a1660
void png_write_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
    File* pfile = reinterpret_cast<File*>(png_get_io_ptr(png_ptr));
    int   check = pfile->Write(data, (int)length);
    if (check < 0 || (png_size_t)check != length)
        png_error(png_ptr, "Write Error.");
}

// Writes 8-bit RGB or RGBA, non-interlaced.
// @0x1425a0670
bool FileWriter::Write(File* file, const ImageData& imageData, const ImageWriteArgs* args) const
{
    SF_UNUSED(args);
    if (!file || !file->IsValid())
        return false;

    PngContext context;
    png_bytep* rows = 0;

    SFstrcpy(context.filePath, sizeof(context.filePath), file->GetFilePath());
    context.width  = imageData.GetWidth();
    context.height = imageData.GetHeight();

    switch (imageData.Format)
    {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
        context.colorType = PNG_COLOR_TYPE_RGB_ALPHA;
        break;
    case Image_R8G8B8:
    case Image_B8G8R8:
        context.colorType = PNG_COLOR_TYPE_RGB;
        break;
    default:
        return false;
    }
    context.bitDepth = 8;
    context.png_ptr  = png_create_write_struct(PNG_LIBPNG_VER_STRING, (png_voidp)&context, png_error_handler, NULL);
    if (!context.png_ptr)
        return false;

    context.info_ptr = png_create_info_struct(context.png_ptr);
    if (!context.info_ptr)
        return false;

    png_set_write_fn(context.png_ptr, (png_voidp)file, png_write_data, NULL);

    if (setjmp(png_jmpbuf(context.png_ptr)))
        return false;

    png_set_IHDR(context.png_ptr, context.info_ptr, imageData.GetWidth(), imageData.GetHeight(), context.bitDepth,
                 context.colorType, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(context.png_ptr, context.info_ptr);

    if (setjmp(png_jmpbuf(context.png_ptr)))
    {
        if (rows)
            SF_FREE(rows);
        return false;
    }

    rows = (png_bytep*)SF_ALLOC(sizeof(png_bytep) * imageData.GetHeight(), Stat_Default_Mem);
    for (unsigned i = 0; i < context.height; i++)
        rows[i] = (png_bytep)imageData.GetScanline(i);
    png_write_image(context.png_ptr, rows);
    SF_FREE(rows);

    if (setjmp(png_jmpbuf(context.png_ptr)))
        return false;

    png_write_end(context.png_ptr, NULL);
    return true;
}

FileWriter FileWriter::Instance;

}}} // namespace Scaleform::Render::PNG

// MS2-PIN: ??_GImageFileWriter@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0300
// MS2-PIN: ??_G?$ImageFileReader_Mixin@VFileReader@PNG@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0330
// MS2-PIN: ??_GFileReader@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0600
// MS2-PIN: ??_G?$ImageFileWriter_Mixin@VFileWriter@PNG@Render@Scaleform@@VImageFileWriter@34@@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0630
// MS2-PIN: ??_GFileWriter@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0900
// MS2-PIN: ??_GInput@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a09d0
// MS2-PIN: ??_GLibPNGInput@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0a20
// MS2-PIN: ??_GMemoryBufferImage@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0ac0
// MS2-PIN: ??_GPNGFileImageSource@PNG@Render@Scaleform@@UEAAPEAXI@Z 0x1425a0b60
// MS2-PIN: ?GetMipmapCount@PNGFileImageSource@PNG@Render@Scaleform@@UEBAIXZ 0x1425a1380
// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// MS2-PIN: ??_7ImageFileReader@Render@Scaleform@@6B@ 0x143184f40
// MS2-PIN: ??_7ImageFileWriter@Render@Scaleform@@6B@ 0x143185548
// MS2-PIN: ??_7?$ImageFileReader_Mixin@VFileReader@PNG@Render@Scaleform@@VImageFileReader@34@@Render@Scaleform@@6B@ 0x143185570
// MS2-PIN: ??_7FileReader@PNG@Render@Scaleform@@6B@ 0x1431855a8
// MS2-PIN: ??_7?$ImageFileWriter_Mixin@VFileWriter@PNG@Render@Scaleform@@VImageFileWriter@34@@Render@Scaleform@@6B@ 0x1431855e8
// MS2-PIN: ??_7FileWriter@PNG@Render@Scaleform@@6B@ 0x143185610
// MS2-PIN: ??_7Input@PNG@Render@Scaleform@@6B@ 0x143185638
// MS2-PIN: ??_7LibPNGInput@PNG@Render@Scaleform@@6B@ 0x143185670
// MS2-PIN: ??_7MemoryBufferImage@PNG@Render@Scaleform@@6B@ 0x1431856a0
// MS2-PIN: ??_7PNGFileImageSource@PNG@Render@Scaleform@@6B@ 0x143185788
