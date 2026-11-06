// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 leftovers of the loader range:
// the XML support's parse forwarder, the ImageFileHandler deleting destructor, the background image file load
// (MovieImageLoadTask::Execute) and the StackMemPool<512, 8> placement new.
// Gap recovery of queue unit sfr_gfx_02.
// MS2-UNIT: sfr_gfx_02y
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14259d960-0x14259d96b .text$mn
// MS2-RANGE: 0x14259dc90-0x14259dcbb .text$mn
// MS2-RANGE: 0x1425aa720-0x1425aaa78 .text$mn
// MS2-RANGE: 0x1425ae790-0x1425ae804 .text$mn

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_imagefilehandlerregistry.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_taskmanager.h"
#include "../include/gfx/xml/xml_support.h"
#include "../include/kernel/sf_file.h"
#include "../include/kernel/sf_stackmempool.h"
#include "../include/render/render_imagefile.h"
#include "sfr_gfx_07raw.h"

namespace Scaleform { namespace GFx {

// XML::Support::ParseString: hands the text to the installed parser.
// @0x14259d960
bool XML::Support::ParseString(const char* pdata, UPInt len, XML::ParserHandler* pdb)
{
    return pParser->ParseString(pdata, len, pdb);
}

// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// Render::ImageFileHandler scalar deleting destructor (8 bytes, vftable only).
// @0x14259dc90
void* FUN_14259dc90(void* self, unsigned flags)
{
    static_cast<Render::ImageFileHandler*>(self)->Render::ImageFileHandler::~ImageFileHandler();
    if (flags & 1)
        ::operator delete(self, 8);             // the CRT sized delete (0x142749444)
    return self;
}

// The task class of sfr_gfx_02f (same definition; its vftable there binds to this Execute).
class MovieImageLoadTask : public LoaderTask
{
    Ptr<MovieDataDef>                 pDef;        // +0x20
    Ptr<MovieDefImpl>                 pDefImpl;    // +0x28
    Ptr<File>                         pImageFile;  // +0x30
    FileTypeConstants::FileFormatType ImageFormat; // +0x38
    Ptr<ImageResource>                pImageRes;   // +0x40

public:
    MovieImageLoadTask(MovieDataDef* pdef, MovieDefImpl* pdefImpl, File* pimageFile,
                       FileTypeConstants::FileFormatType format, LoadStates* pls);

    virtual void Execute();
    virtual void OnAbandon(bool started) {}

    bool LoadingSucceeded() const { return pImageRes.GetPtr() != 0; }
};

// LoaderImpl::FileFormat2RenderImageFile and LoaderImpl::LoadBuiltinImage (sfr_gfx_02f), inlined here by the exe.
static __forceinline Render::ImageFileFormat MS2_FileFormat2RenderImageFile(FileTypeConstants::FileFormatType format)
{
    switch (format)
    {
    case Loader::File_TGA:  return Render::ImageFile_TGA;
    case Loader::File_DDS:  return Render::ImageFile_DDS;
    case Loader::File_JPEG: return Render::ImageFile_JPEG;
    case Loader::File_PNG:  return Render::ImageFile_PNG;
    case Loader::File_SIF:  return Render::ImageFile_SIF;
    case Loader::File_GXT:  return Render::ImageFile_GXT;
    case Loader::File_PVR:  return Render::ImageFile_PVR;
    default:
        return Render::ImageFile_Unknown;
    }
}

static __forceinline Render::ImageSource* MS2_LoadBuiltinImage(File* pfile, FileTypeConstants::FileFormatType format,
                                                               LoadStates* pls, Log* plog, MemoryHeap* pimageHeap)
{
    Render::ImageSource*    pimageSrc = 0;
    const char*             pfilePath = pfile->GetFilePath();
    Render::ImageFileFormat imageFmt  = MS2_FileFormat2RenderImageFile(format);

    if (imageFmt == Render::ImageFile_Unknown)
    {
        if (plog)
            plog->LogMessage("Default image loader failed to load '%s'", pfilePath);
        return 0;
    }

    Ptr<ImageFileHandlerRegistry> pregistry = pls->GetImageFileHandlerRegistry();
    if (!pregistry)
    {
        if (plog)
            plog->LogError("Image file handler registry is not installed - can't load image data");
    }
    else
    {
        Render::ImageFileReader* preader = pregistry->GetReader(imageFmt);
        if (!preader)
        {
            if (plog)
                plog->LogError("Can't load image %s - appropriate reader is not installed.", pfilePath);
        }
        else
        {
            Render::ImageCreateArgs args;
            args.pHeap = pimageHeap;
            pimageSrc  = preader->ReadImageSource(pfile, args);
        }
    }
    return pimageSrc;
}

// StateBag::GetImageCreator.
static __forceinline Ptr<ImageCreator> MS2_GetImageCreator(MovieDefImpl* pdefImpl)
{
    return *(ImageCreator*)pdefImpl->GetStateAddRef(State::State_ImageCreator);
}

// Reads the image file's source with the registry's reader for its format, wraps it in an ImageResource and turns the
// movie data into a one-frame image movie; the binding is marked finished (or failed).
// @0x1425aa720
void MovieImageLoadTask::Execute()
{
    Ptr<Render::ImageSource> pimage;
    MemoryHeap*              pimageHeap = pLoadStates->pWeakResourceLib->GetImageHeap();

    pimage = *MS2_LoadBuiltinImage(pImageFile, ImageFormat, pLoadStates, pLoadStates->GetLog(), pimageHeap);

    if (pimage)
        pImageRes = *SF_HEAP_NEW(pimageHeap) ImageResource(pimage, Resource::Use_Bitmap);

    if (pImageRes)
    {
        if (pDef->InitImageFileMovieDef(pImageFile->GetLength(), pImageRes, MS2_GetImageCreator(pDefImpl),
                                        pLoadStates->GetLog()))
        {
            unsigned fileBytes = pDef->GetFileBytes();
            pDefImpl->pBindData->UpdateBindingFrame(pDef->GetLoadingFrame(), fileBytes);
            pDefImpl->pBindData->SetBindState(MovieDefImpl::BS_Finished | MovieDefImpl::BSF_Frame1Loaded |
                                              MovieDefImpl::BSF_LastFrameLoaded);
        }
        else
        {
            pDefImpl->pBindData->SetBindState(MovieDefImpl::BS_Error);
            pImageRes = NULL;
        }
    }
    else
        pDefImpl->pBindData->SetBindState(MovieDefImpl::BS_Error);
}

}} // namespace Scaleform::GFx

// @0x1425ae790
template void* operator new<512, 8>(Scaleform::UPInt nbytes, Scaleform::StackMemPool<512, 8>& pool);

// MS2-PIN: ??$?2$0CAA@$07@@YAPEAX_KAEAV?$StackMemPool@$0CAA@$07UMemPoolImmediateFree@Scaleform@@@Scaleform@@@Z 0x1425ae790
// The ImageResource construction emits its base chain's vftables here.
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
