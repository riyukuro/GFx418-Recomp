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
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_taskmanager.h"
#include "../include/kernel/sf_file.h"
#include "../include/kernel/sf_stackmempool.h"
#include "../include/render/render_imagefile.h"
#include "sfr_gfx_07raw.h"

namespace Scaleform { namespace GFx {

extern "C" char DAT_143184f20[];          // ??_7ImageFileHandler@Render@Scaleform@@6B@
void FUN_14257dc30(void*);                // RefCountImpl::AddRef
void FUN_14257dcb0(void*);                // RefCountImpl::Release

// XML::Support::ParseString: hands the text to the installed parser (+0x18, its slot 2).
// MS2-FUNCTIONAL: raw-layout forwarder (the XML support classes are not declared here)
// @0x14259d960
bool FUN_14259d960(void* self, const char* pdata, UPInt len, void* phandler)
{
    typedef bool (*ParseFn)(void*, const char*, UPInt, void*);
    void* pparser = RawField<void*>(self, 0x18);
    return (*(ParseFn**)pparser)[2](pparser, pdata, len, phandler);
}

// Render::ImageFileHandler scalar deleting destructor (8 bytes, vftable only).
// MS2-FUNCTIONAL: raw-layout COMDAT (the handler's destructor is implicit in our headers)
// @0x14259dc90
void* FUN_14259dc90(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_143184f20;
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

// Reads the image file with the registry's reader for its format, wraps it in an ImageResource and turns the
// movie data into a one-frame image movie; the binding is marked finished (or failed).
// MS2-FUNCTIONAL: the registry is read through its Render base at +0x18 and refcounted by hand
// @0x1425aa720
void MovieImageLoadTask::Execute()
{
    MemoryHeap*       pheap = pLoadStates->pWeakResourceLib->GetImageHeap();
    Log*              plog  = pLoadStates->GetLog();
    Render::Image*    pimage = 0;
    Render::ImageFileFormat format;
    const char*       path = pImageFile->GetFilePath();

    switch (ImageFormat)
    {
    case FileTypeConstants::File_JPEG: format = Render::ImageFile_JPEG; break;
    case FileTypeConstants::File_PNG:  format = Render::ImageFile_PNG; break;
    case FileTypeConstants::File_TGA:  format = Render::ImageFile_TGA; break;
    case FileTypeConstants::File_DDS:  format = Render::ImageFile_DDS; break;
    case FileTypeConstants::File_PVR:  format = Render::ImageFile_PVR; break;
    case FileTypeConstants::File_SIF:  format = Render::ImageFile_SIF; break;
    case FileTypeConstants::File_GXT:  format = Render::ImageFile_GXT; break;
    default:
        if (plog)
            plog->LogMessage("Default image loader failed to load '%s'", path);
        format = Render::ImageFile_Unknown;
        break;
    }

    if (format != Render::ImageFile_Unknown)
    {
        void* pregistry = pLoadStates->GetImageFileHandlerRegistry();
        if (!pregistry)
        {
            if (plog)
                plog->LogError("Image file handler registry is not installed - can't load image data");
        }
        else
        {
            FUN_14257dc30(pregistry);
            Render::ImageFileReader* preader =
                RawFieldPtr<Render::ImageFileHandlerRegistry>(pregistry, 0x18)->GetReader(format);
            if (!preader)
            {
                if (plog)
                    plog->LogError("Can't load image %s - appropriate reader is not installed.", path);
            }
            else
            {
                Render::ImageCreateArgs args;
                args.pHeap = pheap;
                pimage = preader->Read(pImageFile, args);
            }
            FUN_14257dcb0(pregistry);
        }

        if (pimage)
            pImageRes = *SF_HEAP_NEW(pheap) ImageResource(pimage, Resource::Use_Bitmap);
    }

    unsigned bindState;
    if (pImageRes)
    {
        File*         pfile = pImageFile;
        Log*          pimageLog = pLoadStates->GetLog();
        ImageCreator* pcreator  = (ImageCreator*)pDefImpl->GetStateAddRef(State::State_ImageCreator);
        bool ok = pDef->pData->InitImageFileMovieDef(pfile->GetLength(), pImageRes, pcreator, pimageLog, true);
        if (pcreator)
            FUN_14257dcb0(pcreator);
        if (!ok)
        {
            pDefImpl->pBindData->SetBindState(MovieDefImpl::BS_Error);
            pImageRes = 0;
            if (pimage)
                pimage->Release();
            return;
        }
        pDefImpl->pBindData->UpdateBindingFrame(pDef->GetLoadingFrame(), pDef->GetFileBytes());
        bindState = MovieDefImpl::BS_Finished | MovieDefImpl::BSF_Frame1Loaded | MovieDefImpl::BSF_LastFrameLoaded;
    }
    else
        bindState = MovieDefImpl::BS_Error;
    pDefImpl->pBindData->SetBindState(bindState);
    if (pimage)
        pimage->Release();
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
