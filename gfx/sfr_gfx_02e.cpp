// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 image creator state (loads image
// files and turns image sources into images for the player).
// Fifth source of queue unit sfr_gfx_02 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_02e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142592bf0-0x142593170 .text$mn
//
// The Render image classes are only declared as far as this file calls them; the out-of-line Render members bind
// to the exe (ImageFileHandlerRegistry::AddHandler 0x142591120, DetectFormat 0x142591190, SysFile::GetFileStat
// 0x1425a5840).

#include "../include/gfx/gfx_state.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/render/render_imagefileformat.h"

namespace Scaleform {

class MemoryHeap;

// Reference counted file (only the count is used here).
class File : public RefCountBase<File, Stat_Default_Mem>
{
};

// Times and size of a file on disk (0x18 bytes).
struct FileStat
{
    SInt64 ModifyTime;
    SInt64 AccessTime;
    SInt64 FileSize;
};

class SysFile
{
public:
    static bool SF_STDCALL GetFileStat(FileStat* pfileStats, const String& path);
};

namespace Render {

class Image;
class ImageUpdateSync;

enum ImageFormat
{
    Image_None = 0,
    Image_A8   = 9
};

// Texture formats a manager can take directly (GetTextureFormatSupport bits).
enum ImageFormatSupport
{
    ImageFormats_DXT = 0x01,
    ImageFormats_PVR = 0x08,
    ImageFormats_ETC = 0x20
};

class TextureManager : public RefCountBase<TextureManager, Stat_Default_Mem>
{
public:
    virtual ~TextureManager();
    virtual void*    CreateTexture();
    virtual unsigned GetTextureFormatSupport() const;
};

// How an image is created out of a source (0x28 bytes).
struct ImageCreateArgs
{
    unsigned         Use;
    MemoryHeap*      pHeap;
    TextureManager*  pManager;
    ImageUpdateSync* pUpdateSync;
    ImageFormat      Format;

    ImageCreateArgs() : Use(0), pHeap(0), pManager(0), pUpdateSync(0), Format(Image_None) {}
};

// Decodable image data that can produce a texture or memory image (only the slots called here).
class ImageSource
{
public:
    virtual ~ImageSource();
    virtual void   AddRef();
    virtual void   Release();
    virtual void   Slot3();
    virtual void   Slot4();
    virtual void   Slot5();
    virtual void   Slot6();
    virtual void   Slot7();
    virtual void   Slot8();
    virtual void   Slot9();
    virtual void   Slot10();
    virtual void   Slot11();
    virtual void   Slot12();
    virtual void   Slot13();
    virtual void   Slot14();
    virtual Image* CreateCompatibleImage(const ImageCreateArgs& args); // +0x78
};

class ImageFileReader
{
public:
    virtual ~ImageFileReader();
    virtual void         Slot1();
    virtual void         Slot2();
    virtual void         Slot3();
    virtual void         Slot4();
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args); // +0x28
};

class ImageFileHandler;

class ImageFileHandlerRegistry
{
public:
    virtual ~ImageFileHandlerRegistry();
    virtual Image* ReadImage(File* file, const ImageCreateArgs& args);

    void            AddHandler(ImageFileHandler* handler);
    ImageFileFormat DetectFormat(ImageFileReader** preader, File* file, UByte* header = 0, UPInt headerSize = 0);
};

} // namespace Render

namespace GFx {

using Render::Image;
using Render::ImageSource;
using Render::ImageFileHandler;
using Render::TextureManager;

class Log;

class FileOpenerBase : public State
{
public:
    virtual File* OpenFile(const char* purl, int flags = 0x21, int mode = 0666);
};

class ImageFileHandlerRegistry;

// What a loader passes along with an image request.
class ImageCreateInfo
{
public:
    int                       Type;         // +0
    MemoryHeap*               pHeap;        // +8
    unsigned                  Use;          // +0x10
    Resource::ResourceUse     RUse;         // +0x14
    Log*                      pLog;         // +0x18
    FileOpenerBase*           pFileOpener;  // +0x20
    ImageFileHandlerRegistry* pIFHRegistry; // +0x28
};

struct ImageCreateExportInfo : public ImageCreateInfo
{
};

// Turns image files and sources into images (vftable 0x143184c60, 0x20 bytes).
class ImageCreator : public State
{
protected:
    Ptr<TextureManager> pTextureManager; // +0x18

public:
    ImageCreator(TextureManager* textureManager = 0);

    virtual Image* LoadProtocolImage(const ImageCreateInfo& info, const String& url);
    virtual Image* LoadImageFile(const ImageCreateInfo& info, const String& url);
    virtual Image* LoadExportedImage(const ImageCreateExportInfo& info, const String& url);
    virtual Image* CreateImage(const ImageCreateInfo& info, ImageSource* source);
};

// The image file readers a loader may use.
class ImageFileHandlerRegistry : public State, public Render::ImageFileHandlerRegistry
{
public:
    void AddHandler(ImageFileHandler* handler);
};

// @0x142592bf0
ImageCreator::ImageCreator(TextureManager* textureManager)
    : State(State_ImageCreator), pTextureManager(textureManager)
{
}

// No "img://" images of its own.
// @0x142593140
Image* ImageCreator::LoadProtocolImage(const ImageCreateInfo&, const String&)
{
    return 0;
}

// A name without extension is tried as the texture format the manager supports, then as ".tga".
// @0x142592ec0
// MS2-FUNCTIONAL: same code as the exe with rbx, rsi and rdi permuted (url, the -1 constant, the source pointer)
Image* ImageCreator::LoadImageFile(const ImageCreateInfo& info, const String& url)
{
    ImageFileHandlerRegistry* registry = info.pIFHRegistry;
    if (!registry || !info.pFileOpener)
        return 0;

    String path = url;
    if (!url.HasExtension())
    {
        if (pTextureManager)
        {
            FileStat tmp;
            unsigned fs = pTextureManager->GetTextureFormatSupport();
            if (fs & Render::ImageFormats_DXT)
            {
                path = url + ".dds";
                if (SysFile::GetFileStat(&tmp, path))
                    goto file_detected;
            }
            else if (fs & (Render::ImageFormats_PVR | Render::ImageFormats_ETC))
            {
                path = url + ".pvr";
                if (SysFile::GetFileStat(&tmp, path))
                    goto file_detected;
            }
        }
        path = url + ".tga";
    }
file_detected:
    Ptr<File> file = *info.pFileOpener->OpenFile(path.ToCStr());

    Render::ImageFileReader* reader;
    Render::ImageCreateArgs  args;
    if (registry->DetectFormat(&reader, file) != Render::ImageFile_Unknown)
    {
        args.pHeap    = info.pHeap;
        args.Use      = info.Use;
        args.pManager = pTextureManager;
        if (info.RUse == Resource::Use_FontTexture)
            args.Format = Render::Image_A8;

        Ptr<ImageSource> source = *reader->ReadImageSource(file, args);
        if (source)
            return CreateImage(info, source);
    }
    return registry->ReadImage(file, args);
}

// An exported name that fails is retried with ".dds" in place of its extension.
// @0x142592d40
// MS2-FUNCTIONAL: same code as the exe except the register pair of the ".dds" compare loop and a cmp esi,1 where the
// exe tests esi-1 when url2 is released
Image* ImageCreator::LoadExportedImage(const ImageCreateExportInfo& info, const String& url)
{
    Image* result = LoadImageFile(info, url);

    if (!result && url.HasExtension())
    {
        if (url.GetExtension().ToLower() != ".dds")
        {
            String url2 = url;
            url2.StripExtension();
            url2 += ".dds";
            result = LoadImageFile(info, url2);
        }
    }
    return result;
}

// @0x142592cf0
Image* ImageCreator::CreateImage(const ImageCreateInfo& info, ImageSource* source)
{
    Render::ImageCreateArgs args;
    args.pHeap    = info.pHeap;
    args.Use      = info.Use;
    args.pManager = pTextureManager;
    if (info.RUse == Resource::Use_FontTexture)
        args.Format = Render::Image_A8;

    return source->CreateCompatibleImage(args);
}

// @0x142592ce0
void ImageFileHandlerRegistry::AddHandler(ImageFileHandler* handler)
{
    Render::ImageFileHandlerRegistry::AddHandler(handler);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ImageCreator@GFx@Scaleform@@6B@ 0x143184c60
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
