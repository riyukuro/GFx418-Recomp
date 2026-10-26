// Recovered Scaleform 4.1.18 GFx: ImageCreator, the state that turns image requests (protocol urls such as
// "img://", image files, exported images and decoded sources) into Render::Images, and the ImageCreateInfo that goes
// along with each request. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts from MovieImpl::GetImageResourceByLinkageId (exe 0x14256f370) and the loader (sfr_gfx_07e):
//   ImageCreateInfo 0x38, ImageCreateExportInfo 0x58, ImageCreator 0x20 (vftable 0x143184c60).
// sfr_gfx_02e / 06e / 07e / 08c still carry local copies of these classes; a unit includes either this header or
// its local copy, never both.
#ifndef MS2_SF_GFX_IMAGECREATOR_H
#define MS2_SF_GFX_IMAGECREATOR_H

#include "gfx_state.h"
#include "gfx_resource.h"   // Resource, String
#include "../render/render_image.h"
#include "../render/render_imagefileformat.h"

namespace Scaleform {
class Log;
namespace Render { class TextureManager; class ImageSource; }
namespace GFx {

class ImageFileHandlerRegistry;
struct ExporterInfo;

// What the requester passes along with an image request.
class ImageCreateInfo
{
public:
    enum CreateType
    {
        Create_ProtocolImage = 0,   // a url the host resolves (img://, imgps://)
        Create_FileImage     = 1,   // an image file loaded as a movie or by the loader
        Create_ExportImage   = 2,   // an image the exporter wrote out of the SWF (ImageCreateExportInfo)
        Create_SourceImage   = 3    // a decoded Render::ImageSource
    };

    int                       Type;         // +0    CreateType
    MemoryHeap*               pHeap;        // +8
    unsigned                  Use;          // +0x10 Render::ImageUse
    Resource::ResourceUse     RUse;         // +0x14
    Log*                      pLog;         // +0x18
    State*                    pFileOpener;  // +0x20
    ImageFileHandlerRegistry* pIFHRegistry; // +0x28
    void*                     pMovie;       // +0x30 the MovieImpl that asks (protocol images)

    ImageCreateInfo(CreateType type, MemoryHeap* pheap = 0, unsigned imageUse = Render::ImageUse_Wrap,
                    Resource::ResourceUse resourceUse = Resource::Use_Bitmap)
        : Type(type), pHeap(pheap), Use(imageUse), RUse(resourceUse), pLog(0), pFileOpener(0), pIFHRegistry(0),
          pMovie(0)
    {
    }

    void SetStates(Log* plog, State* popener, ImageFileHandlerRegistry* pregistry)
    {
        pFileOpener  = popener;
        pLog         = plog;
        pIFHRegistry = pregistry;
    }
};

// An image the exporter extracted from the movie.
class ImageCreateExportInfo : public ImageCreateInfo
{
public:
    Render::ImageFileFormat Format;        // +0x38
    const ExporterInfo*     pExporterInfo; // +0x40
    String                  ExportName;    // +0x48
    unsigned                TargetWidth;   // +0x50
    unsigned                TargetHeight;  // +0x54

    ImageCreateExportInfo(MemoryHeap* pheap, unsigned imageUse, Resource::ResourceUse resourceUse)
        : ImageCreateInfo(Create_ExportImage, pheap, imageUse, resourceUse)
    {
    }
};

// Turns image sources into images.
class ImageCreator : public State
{
protected:
    Ptr<RefCountImpl> pTextureManager; // +0x18 Ptr<Render::TextureManager>

public:
    ImageCreator(Render::TextureManager* textureManager = 0);

    virtual Render::Image* LoadProtocolImage(const ImageCreateInfo& info, const String& url);              // +0x8
    virtual Render::Image* LoadImageFile(const ImageCreateInfo& info, const String& url);                  // +0x10
    virtual Render::Image* LoadExportedImage(const ImageCreateExportInfo& info, const String& url);        // +0x18
    virtual Render::Image* CreateImage(const ImageCreateInfo& info, Render::ImageSource* source);          // +0x20

    // (appended, sfr22) the exe table has a sixth slot, 0x1422eee80: an inline returning null for either stage
    // (its COMDAT landed in the game's gfximageloader TU, so it is unoptimized there)
    enum LoadStage
    {
        Stage_Load,
        Stage_Bind
    };
    virtual RefCountImpl* GetBindKey(LoadStage) { return 0; }                                                // +0x28
};

#if defined(_WIN64)
static_assert(sizeof(ImageCreateInfo) == 0x38, "ImageCreateInfo size");
static_assert(sizeof(ImageCreateExportInfo) == 0x58, "ImageCreateExportInfo size");
static_assert(sizeof(ImageCreator) == 0x20, "ImageCreator size");
#endif

}} // namespace Scaleform::GFx

#endif
