// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx core, the last range of queue
// unit sfr_gfx_07: the shape path allocator, the resource binding table, the load process and load states, the
// player tasks and the font manager.
// MS2-UNIT: sfr_gfx_07e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142636190-0x1426395f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AddRef@DataInterface@ResourceData@GFx@Scaleform@@UEAAXPEAX@Z 0x1426369e0 ; unique
// MS2-PIN: ?Release@DataInterface@ResourceData@GFx@Scaleform@@UEAAXPEAX@Z 0x1426369f0 ; unique
// MS2-PIN: ??0ImageResource@GFx@Scaleform@@QEAA@PEAVImage@Render@2@W4ResourceUse@Resource@12@@Z 0x142636be0 ; unique
// MS2-PINS-END tplpin

// MS2-PIN: ??_7FontResourceCreator@GFx@Scaleform@@6B@ 0x14318f528
// MS2-PIN: ??_7DataInterface@ResourceData@GFx@Scaleform@@6B@ 0x14318f548
// MS2-PIN: ??_7SubImageResource@GFx@Scaleform@@6B@ 0x14318f568
// MS2-PIN: ??_7LoadStates@GFx@Scaleform@@6B@ 0x14318f5a0
// MS2-PIN: ??_7?$LogBase@VLoadProcess@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x14318f5a8
// MS2-PIN: ??_7LoadProcess@GFx@Scaleform@@6BLoaderTask@12@@ 0x14318f5b8
// MS2-PIN: ??_7LoadProcess@GFx@Scaleform@@6B?$LogBase@VLoadProcess@GFx@Scaleform@@@12@@ 0x14318f5d0
// MS2-PIN: ??_7ImageFileResourceCreator@GFx@Scaleform@@6B@ 0x14318f5e0
// MS2-PIN: ??_7ImageResourceCreator@GFx@Scaleform@@6B@ 0x14318f600
// MS2-PIN: ??_7SubImageResourceCreator@GFx@Scaleform@@6B@ 0x14318f620
// MS2-PIN: ??_GFontResourceCreator@GFx@Scaleform@@UEAAPEAXI@Z 0x142636b90
// MS2-PIN: ??_GImageFileResourceCreator@GFx@Scaleform@@UEAAPEAXI@Z 0x1426378c0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142637830
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7ImageFileInfo@GFx@Scaleform@@6B@ 0x14318a268
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBase@VMovieDefBindStates@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431891a8
// MS2-PIN: ??_7MovieDefBindStates@GFx@Scaleform@@6B@ 0x1431891b0
// MS2-PIN: ??_7?$RefCountBase@VLoadStates@GFx@Scaleform@@$01@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageSource@Render@Scaleform@@6B@ 0x1431851a8
// MS2-PIN: ??_7SubImage@Render@Scaleform@@6B@ 0x143183c10
// MS2-PIN: ??_7WrapperImageSource@Render@Scaleform@@6B@ 0x143185228
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8

#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_fontlib.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/gfx/gfx_taskmanager.h"
#include "../include/gfx/gfx_shape.h"
#include "../include/gfx/gfx_shapedef.h"
#include "../include/kernel/sf_allocator.h"

namespace Scaleform { namespace GFx {

// ---------------------------------------------------------------------------------------------------------------------
// PathAllocator

// @0x142636190
PathAllocator::PathAllocator(unsigned pageSize)
    : pFirstPage(0), pLastPage(0), FreeBytes(0), DefaultPageSize((UInt16)pageSize)
{
}

// @0x1426361b0
PathAllocator::~PathAllocator()
{
    Clear();
}

// @0x142636200
// MS2-FUNCTIONAL: register allocation of the page size (the exe compares in ecx, cmovbe)
UByte* PathAllocator::AllocMemoryBlock(UInt32 sizeForCurrentPage, UInt32 sizeInNewPage)
{
    UInt32 freeBytes = FreeBytes;
    UInt32 size      = sizeInNewPage;
    if (pLastPage && freeBytes >= sizeForCurrentPage)
        size = sizeForCurrentPage;
    else
    {
        UInt32 pageSize = (sizeInNewPage > DefaultPageSize) ? sizeInNewPage : DefaultPageSize;
        Page* pnewPage = (Page*)SF_HEAP_AUTO_ALLOC(this, pageSize + sizeof(Page));
        if (!pnewPage)
            return 0;
        pnewPage->pNext    = 0;
        pnewPage->PageSize = pageSize;
        if (pLastPage)
        {
            pLastPage->pNext = pnewPage;
            pLastPage->PageSize -= FreeBytes;
        }
        pLastPage = pnewPage;
        if (!pFirstPage)
            pFirstPage = pnewPage;
        freeBytes = pageSize;
    }
    UByte* ptr = pLastPage->Buffer + pLastPage->PageSize - freeBytes;
    FreeBytes  = UInt16(freeBytes - size);
    return ptr;
}

// @0x1426362c0
// MS2-FUNCTIONAL: register allocation and block order (the exe shares one tail call for the edge-less path)
UByte* PathAllocator::AllocPath(unsigned edgesDataSize, unsigned pathSize, unsigned edgeSize)
{
    unsigned size = edgesDataSize + 1 + pathSize * 3;
    unsigned sizeForCurrentPage = size;
    unsigned pad = 0;
    if (edgesDataSize)
    {
        if (pLastPage)
        {
            // the record starts at the next free byte of the current page
            UInt32 pos   = UInt32(UPInt(pLastPage->Buffer + (pLastPage->PageSize - FreeBytes))) + 1;
            UInt32 a     = pos & (pathSize - 1);
            pad          = ((a + pathSize - 1) & ~(pathSize - 1)) - a;
            UInt32 epos  = (pos + pathSize * 3 + pad) & (edgeSize - 1);
            pad         += ((epos + edgeSize - 1) & ~(edgeSize - 1)) - epos;
        }
        sizeForCurrentPage = size + pad;
        if (!pLastPage || FreeBytes < sizeForCurrentPage)
        {
            // a new page: the record starts at its (aligned) data
            UInt32 pathPos  = (1 + pathSize - 1) & ~(pathSize - 1);
            UInt32 edgesPos = (pathPos + pathSize * 3 + edgeSize - 1) & ~(edgeSize - 1);
            pad             = edgesPos - (1 + pathSize * 3);
        }
    }
    return AllocMemoryBlock(sizeForCurrentPage, size + pad);
}

// @0x1426363b0
UByte* PathAllocator::AllocRawPath(UInt32 sizeInBytes)
{
    return AllocMemoryBlock(sizeInBytes, sizeInBytes);
}

// @0x1426363c0
void PathAllocator::Clear()
{
    Page* ppage = pFirstPage;
    while (ppage)
    {
        Page* pnext = ppage->pNext;
        SF_FREE(ppage);
        ppage = pnext;
    }
    pFirstPage = 0;
    pLastPage  = 0;
    FreeBytes  = 0;
}

// ---------------------------------------------------------------------------------------------------------------------
// ShapeBaseCharacterDef

// A shape without images uses its own provider; one with image fills uses the provider bound for this movie, made
// and cached in the movie's bind data on first use.
// @0x142636410
Ptr<Render::TreeNode> ShapeBaseCharacterDef::CreateTreeShape(Render::Context& context, MovieDefImpl* defImpl) const
{
    Ptr<Render::TreeShape> tshp = *context.CreateEntry<Render::TreeShape>();
    if (NeedsResolving())
    {
        Ptr<Render::ShapeMeshProvider> shMeshProv = defImpl->pBindData->GetShapeMeshProvider(pShapeMeshProvider);
        if (!shMeshProv)
        {
            shMeshProv = BindResourcesInStyles(defImpl->GetResourceBinding());
            defImpl->pBindData->AddShapeMeshProvider(pShapeMeshProvider, shMeshProv);
        }
        tshp->SetShape(shMeshProv);
    }
    else
        tshp->SetShape(pShapeMeshProvider);
    return tshp.GetPtr();
}

// ---------------------------------------------------------------------------------------------------------------------
// PathAllocator (continued)

// Only the last block of the page can shrink; the freed bytes go back to the page. (4.1.18 reports false either way.)
// @0x142636580
// MS2-FUNCTIONAL: the exe computes the block offset twice (keeping this in rbx)
bool PathAllocator::ReallocLastBlock(UByte* ptr, UInt32 oldSize, UInt32 newSize)
{
    if (newSize < oldSize && pLastPage)
    {
        SPInt off = ptr - pLastPage->Buffer;
        if (off < SPInt(SInt32(pLastPage->PageSize)) && UPInt(pLastPage->PageSize) - oldSize - off == FreeBytes)
        {
            UPInt newFree = UPInt(pLastPage->PageSize) - newSize - off;
            if (newFree < 0x10000)
                FreeBytes = UInt16(newFree);
        }
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// ResourceBinding

// @0x142636600
ResourceBinding::ResourceBinding(MemoryHeap* pheap)
    : pHeap(pheap)
{
    pResources    = 0;
    ResourceCount = 0;
    Frozen        = 0;
    pOwnerDefImpl = 0;
}

// @0x142636630
ResourceBinding::~ResourceBinding()
{
    Destroy();
}

// @0x1426366b0
void ResourceBinding::Destroy()
{
    if (pResources)
    {
        DestructArray(pResources, ResourceCount);
        SF_FREE(pResources);
        pResources = 0;
    }
}

// An index past the table reads as an empty entry.
// @0x142636720
void ResourceBinding::GetResourceData_Locked(ResourceBindData* pdata, unsigned index) const
{
    Lock::Locker lock(&ResourceLock);
    *pdata = (index < ResourceCount) ? pResources[index] : ResourceBindData();
}

// The table grows in steps of 16 entries.
// @0x142636820
// MS2-FUNCTIONAL: register allocation (the new count lives in rbp / the new table in r12 in the exe)
void ResourceBinding::SetBindData(unsigned index, const ResourceBindData& rdata)
{
    Lock::Locker lock(&ResourceLock);
    unsigned newCount = (index + 16) & ~15;
    if (newCount > ResourceCount)
    {
        if (!pResources)
        {
            pResources = (ResourceBindData*)SF_HEAP_ALLOC(pHeap, sizeof(ResourceBindData) * newCount, StatMD_Other_Mem);
            ConstructArray<ResourceBindData>(pResources, newCount);
        }
        else
        {
            ResourceBindData* pnew =
                (ResourceBindData*)SF_HEAP_ALLOC(pHeap, sizeof(ResourceBindData) * newCount, StatMD_Other_Mem);
            ConstructArray<ResourceBindData>(pnew, newCount);
            for (unsigned i = 0; i < ResourceCount; i++)
                pnew[i] = pResources[i];
            DestructArray(pResources, ResourceCount);
            SF_FREE(pResources);
            pResources = pnew;
        }
        ResourceCount = newCount;
    }
    pResources[index] = rdata;
}

// ---------------------------------------------------------------------------------------------------------------------
// LoadStates

// The states the load states keep that no shared header defines yet (only their reference counts are used here).
class ImageFileHandlerRegistry : public State
{
};
class VideoBase : public State
{
};

// @0x142636ed0
LoadStates::LoadStates(LoaderImpl* ploader, StateBag* pstates, MovieDefBindStates* pbindStates)
    : ThreadedLoading(false)
{
    pLoaderImpl      = ploader;
    pWeakResourceLib = ploader->pWeakResourceLib.GetPtr();
    if (!pstates)
        pstates = &static_cast<StateBag&>(*ploader);

    pBindStates = *(pbindStates ? SF_NEW MovieDefBindStates(pbindStates) : SF_NEW MovieDefBindStates(pstates));

    pLog                      = pstates->GetLogState();
    pParseControl             = Ptr<ParseControl>(*(ParseControl*)pstates->GetStateAddRef(State::State_ParseControl));
    pProgressHandler          = Ptr<ProgressHandler>(*(ProgressHandler*)pstates->GetStateAddRef(State::State_ProgressHandler));
    pTaskManager              = Ptr<TaskManager>(*(TaskManager*)pstates->GetStateAddRef(State::State_TaskManager));
    pImageFileHandlerRegistry = Ptr<ImageFileHandlerRegistry>(
        *(ImageFileHandlerRegistry*)pstates->GetStateAddRef(State::State_ImageFileHandlerRegistry));
    pZlibSupport = Ptr<ZlibSupportBase>(*(ZlibSupportBase*)pstates->GetStateAddRef(State::State_ZlibSupport));
    pAS2Support  = Ptr<ASSupport>(*(ASSupport*)pstates->GetStateAddRef(State::State_AS2Support));
    pAS3Support  = Ptr<ASSupport>(*(ASSupport*)pstates->GetStateAddRef(State::State_AS3Support));
    pVideoState  = Ptr<VideoBase>(*(VideoBase*)pstates->GetStateAddRef(State::State_Video));
    pAudioState  = Ptr<AudioBase>(*(AudioBase*)pstates->GetStateAddRef(State::State_Audio));
}

// @0x142637290
LoadStates::LoadStates()
    : ThreadedLoading(false)
{
}

// @0x142637330
MovieDefBindStates::MovieDefBindStates(MovieDefBindStates* pother)
{
    pFileOpener          = pother->pFileOpener;
    pURLBuilder          = pother->pURLBuilder;
    pImageCreator        = pother->pImageCreator;
    pImportVisitor       = pother->pImportVisitor;
    pFontPackParams      = pother->pFontPackParams;
    pBindState23         = pother->pBindState23;
    pFontCompactorParams = pother->pFontCompactorParams;
    pImagePackParams     = pother->pImagePackParams;
}

// @0x1426376e0
LoadStates::~LoadStates()
{
}

// @0x142638170
void LoadStates::BuildURL(String* pdest, const URLBuilder::LocationInfo& loc) const
{
    URLBuilder* pbuilder = (URLBuilder*)pBindStates->pURLBuilder.GetPtr();
    if (!pbuilder)
        URLBuilder::DefaultBuildURL(pdest, loc);
    else
        pbuilder->BuildURL(pdest, loc);
}

// The bind states and the loader share everything else.
// @0x1426382f0
LoadStates* LoadStates::CloneForImport() const
{
    Ptr<MovieDefBindStates> pbindStates = *SF_NEW MovieDefBindStates(pBindStates);
    LoadStates*             pstates     = SF_NEW LoadStates;
    if (pstates)
    {
        pstates->pBindStates               = pbindStates;
        pstates->pLoaderImpl               = pLoaderImpl;
        pstates->pLog                      = pLog;
        pstates->pProgressHandler          = pProgressHandler;
        pstates->pTaskManager              = pTaskManager;
        pstates->pParseControl             = pParseControl;
        pstates->pWeakResourceLib          = pWeakResourceLib;
        pstates->pImageFileHandlerRegistry = pImageFileHandlerRegistry;
        pstates->pZlibSupport              = pZlibSupport;
        pstates->pAS2Support               = pAS2Support;
        pstates->pAS3Support               = pAS3Support;
        pstates->pAudioState               = pAudioState;
        pstates->pVideoState               = pVideoState;
    }
    return pstates;
}

// @0x142639340
ImageCreator* LoadStates::GetImageCreator() const
{
    return (ImageCreator*)pBindStates->pImageCreator.GetPtr();
}

// Load-time image creation is off for files loaded with LoadKeepBindData.
// @0x142639350
ImageCreator* LoadStates::GetLoadTimeImageCreator(unsigned loadConstants) const
{
    ImageCreator* pcreator = 0;
    if (!(loadConstants & Loader::LoadKeepBindData))
    {
        ImageCreator* p = GetImageCreator();
        if (p)
            pcreator = p;
    }
    return pcreator;
}

// @0x1426393d0
File* LoadStates::OpenFile(const char* pfilename, unsigned loadConstants)
{
    if (!pBindStates->pFileOpener)
    {
        if (pLog && !(loadConstants & Loader::LoadQuietOpen))
            pLog->LogError("Loader failed to open '%s', FileOpener not installe", pfilename);
        return 0;
    }
    return ((FileOpenerBase*)pBindStates->pFileOpener.GetPtr())
        ->OpenFileEx(pfilename, (loadConstants & Loader::LoadQuietOpen) ? 0 : pLog->GetLog());
}

// Imports are looked up relative to the directory of the file.
// @0x1426394a0
void LoadStates::SetRelativePathForDataDef(MovieDataDef* pdef)
{
    RelativePathForImports = pdef->GetFileURL();
    if (!URLBuilder::ExtractFilePath(&RelativePathForImports))
        RelativePathForImports.Clear();
}

// @0x1426394f0
bool LoadStates::SubmitBackgroundTask(LoaderTask* ptask)
{
    if (pTaskManager && pTaskManager->AddTask(ptask))
        return true;
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// LoadProcess

// The SWF stream and file header at the start of a load process (0x310 bytes; Initialize is GFx_LoaderImpl's).
struct SWFProcessInfo
{
    GFx::Stream     Stream;          // +0
    UInt32          FileStartPos;    // +0x270
    UInt32          FileEndPos;      // +0x274
    UInt32          NextActionBlock; // +0x278
    MovieHeaderData Header;          // +0x280
    UInt16          FileAttributes;  // +0x300

    bool Initialize(File* pin, LogState* plog, ZlibSupportBase* zlib, ParseControl* pparseControl, bool parseMsg);
};

// @0x142636cc0
// MS2-FUNCTIONAL: register allocation (same stores; the exe keeps this in rsi and saves one more register)
LoadProcess::LoadProcess(MovieDataDef* pdataDef, LoadStates* pstates, unsigned loadFlags)
    : LoaderTask(pstates, Id_MovieDataLoad), ProcessStream(0, pdataDef->pData->GetHeap(), 0, 0), SWFFileAttributes(0)
{
    ParseFlags      = pstates->pParseControl ? pstates->pParseControl->ParseFlags : 0;
    pLoadData       = pdataDef->pData.GetPtr();
    pDataDef_Unsafe = pdataDef;
    pTimelineDef    = 0;
    LoadFlags       = loadFlags;
    LoadState       = LS_LoadingRoot;

    ImportIndex       = 0;
    ImportDataCount   = 0;
    ResourceDataCount = 0;
    FontDataCount     = 0;
    pImportDataLast   = 0;
    pImportData       = 0;
    pResourceDataLast = 0;
    pResourceData     = 0;
    pFontDataLast     = 0;
    pFontData         = 0;

    pAltStream          = 0;
    pTempBindData       = 0;
    ASInitActionTagsNum = 0;
}

// Wakes up whoever waits for the movie data.
// @0x142637560
LoadProcess::~LoadProcess()
{
    pJpegTables = 0;
    Ptr<LoadUpdateSync> pupdateSync = pLoadData->GetFrameUpdateSync();
    ProcessStream.ShutDown();
    pLoadData    = 0;
    pBindProcess = 0;
    if (pupdateSync)
        pupdateSync->NotifyLoadFinished();
}

// @0x142639320
void LoadProcess::Execute()
{
    pLoadData->Read(this, pBindProcess);
}

// @0x142639380
void LoadProcess::OnAbandon(bool started)
{
    if (started)
        pLoadData->OnMovieDataDefRelease();
    if (pBindProcess && !started)
    {
        if (MovieDefImpl::BindTaskData* pbindData = pBindProcess->GetBindData())
            pbindData->SetBindState(MovieDefImpl::BS_Canceled);
    }
}

// @0x142637b60
SF_NOINLINE ResourceHandle LoadProcess::AddDataResource(ResourceId rid, const ResourceData& resData)
{
    ResourceHandle               rh    = pLoadData->AddNewResourceHandle(rid);
    MovieDataDef::LoadTaskData*  pld   = pLoadData;
    ResourceDataNode*            pnode = pld->AllocMovieDefClass<ResourceDataNode>();
    pnode->Data      = resData;
    pnode->BindIndex = rh.GetBindIndex();
    if (!pResourceData)
        pResourceData = pnode;

    MovieDataDef::DefBindingData& bindData = pld->BindData;
    if (!bindData.pResourceNodes)
        bindData.pResourceNodes = pnode;
    else
        bindData.pResourceNodesLast->pNext = pnode;
    bindData.pResourceNodesLast = pnode;
    ResourceDataCount++;
    return rh;
}

// Creates the FontResource of a movie font per binding (vftable 0x14318f528).
class FontResourceCreator : public ResourceData::DataInterface
{
public:

    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const;
};

// A font of a substitute font movie with the same name and style stands in for the movie's own; otherwise the movie
// font becomes a FontResource of the binding (an empty one is resolved later through the font manager).
// The one creator of all fonts (exe 0x143a2f430; constant-initialized).
static FontResourceCreator FontResourceCreator_Static;

// @0x142636a00
// MS2-FUNCTIONAL: the exe calls ResourceBinding::GetResourceData out of line (0x1425d0f20); here it is inlined
bool FontResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                         MemoryHeap* pheap) const
{
    Render::Font* pfontData = (Render::Font*)hdata;

    for (unsigned i = 0; i < pls->SubstituteFontMovieDefs.GetSize(); i++)
    {
        MovieDefImpl* pdefImpl = pls->SubstituteFontMovieDefs[i];
        for (FontDataUseNode* pfont = pdefImpl->GetDataDef()->GetFirstFont(); pfont; pfont = pfont->pNext)
        {
            Render::Font* psubFont = pfont->pFontData;
            if (psubFont->GetGlyphShapeCount() && pfontData->MatchSubstituteFont(psubFont))
            {
                pdefImpl->GetResourceBinding().GetResourceData(pbindData, pfont->BindIndex);
                return true;
            }
        }
    }

    if (!pfontData->HasVectorOrRasterGlyphs() && pfontData->GetName())
        pfontData->SetNotResolvedFlag();
    if (!pbindData->pResource)
        pbindData->pResource = *SF_HEAP_NEW(pheap) FontResource(pfontData, pbindData->pBinding);
    return pbindData->pResource != 0;
}

// @0x142637c60
ResourceHandle LoadProcess::AddFontDataResource(ResourceId rid, Render::Font* pfontData)
{
    ResourceData   fontData(&FontResourceCreator_Static, pfontData);
    ResourceHandle rh = AddDataResource(rid, fontData);

    FontDataUseNode* pfontNode = pLoadData->AllocMovieDefClass<FontDataUseNode>();
    MovieDataDef::DefBindingData& bindData = pLoadData->BindData;
    pfontNode->Id        = rid;
    pfontNode->pFontData = pfontData;
    pfontNode->BindIndex = rh.GetBindIndex();
    if (!pFontData)
        pFontData = pfontNode;

    if (!bindData.pFonts)
        bindData.pFonts = pfontNode;
    else
        bindData.pFontsLast->pNext = pfontNode;
    bindData.pFontsLast = pfontNode;
    FontDataCount++;
    return rh;
}

// What the loader passes along with an image request (0x38 bytes; sfr_gfx_04 has the same layout).
class ImageCreateInfo
{
public:
    enum CreateType
    {
        Create_FileImage = 1
    };

    int                       Type;         // +0
    MemoryHeap*               pHeap;        // +8
    unsigned                  Use;          // +0x10 Render::ImageUse
    Resource::ResourceUse     RUse;         // +0x14
    Log*                      pLog;         // +0x18
    State*                    pFileOpener;  // +0x20
    ImageFileHandlerRegistry* pIFHRegistry; // +0x28
    void*                     pMovie;       // +0x30

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

// An image the exporter extracted from the movie (0x58 bytes).
struct ImageCreateExportInfo : public ImageCreateInfo
{
    enum
    {
        Create_ExportImage = 2
    };

    Render::ImageFileFormat Format;        // +0x38
    const ExporterInfo*     pExporterInfo; // +0x40
    String                  ExportName;    // +0x48
    unsigned                TargetWidth;   // +0x50
    unsigned                TargetHeight;  // +0x54

    ImageCreateExportInfo(MemoryHeap* pheap, unsigned imageUse, Resource::ResourceUse resourceUse)
        : ImageCreateInfo((CreateType)Create_ExportImage, pheap, imageUse, resourceUse)
    {
    }
};

// Turns image sources into images (vftable 0x143184c60, 0x20 bytes; the members are sfr_gfx_02e's).
class ImageCreator : public State
{
protected:
    Ptr<RefCountImpl> pTextureManager; // +0x18 Ptr<Render::TextureManager>

public:
    ImageCreator(Render::TextureManager* textureManager = 0);

    virtual Render::Image* LoadProtocolImage(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadImageFile(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadExportedImage(const ImageCreateExportInfo& info, const String& url);
    virtual Render::Image* CreateImage(const ImageCreateInfo& info, Render::ImageSource* source);
};

// Creates the image of a movie bitmap per binding when no image creator was there at load time (vftable
// 0x14318f600).
class ImageResourceCreator : public ResourceData::DataInterface
{
public:
    static ResourceData CreateImageResourceData(Render::ImageSource* pimage);

    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const;
};

// @0x1426387f0
ResourceData ImageResourceCreator::CreateImageResourceData(Render::ImageSource* pimage)
{
    static ImageResourceCreator static_inst;
    if (pimage)
        return ResourceData(&static_inst, pimage);
    return ResourceData();
}

struct ImageFileInfo;

// Loads the image files a movie refers to per binding, through the resource library (vftable 0x14318f5e0).
class ImageFileResourceCreator : public ResourceData::DataInterface
{
    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const; // exe 0x1426388b0

public:
    static ResourceData CreateImageFileResourceData(ImageFileInfo* prfi);
};

// @0x142638750
ResourceData ImageFileResourceCreator::CreateImageFileResourceData(ImageFileInfo* prfi)
{
    static ImageFileResourceCreator static_inst;
    return ResourceData(&static_inst, prfi);
}

// The image file through the image creator of the binding (scaled to the size the movie asks for), shared through
// the resource library: the first binding loads it, the others wait for it.
// @0x1426388b0
bool ImageFileResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                              MemoryHeap* pheap) const
{
    SF_UNUSED(pheap);
    ImageFileInfo*     prfi           = (ImageFileInfo*)hdata;
    Ptr<ImageFileInfo> pimageFileInfo = *SF_NEW ImageFileInfo(*prfi);
    if (pimageFileInfo->Format == FileTypeConstants::File_Original && pimageFileInfo->pExporterInfo)
        pimageFileInfo->Format = pimageFileInfo->pExporterInfo->Format;

    URLBuilder::LocationInfo loc(URLBuilder::File_ImageImport, prfi->FileName, pls->GetRelativePath());
    pls->BuildURL(&pimageFileInfo->FileName, loc);

    MemoryHeap* pimageHeap = pls->pWeakResourceLib->GetImageHeap();
    ResourceKey imageKey   = ImageResource::CreateImageFileKey(
        pimageFileInfo, (FileOpener*)pls->GetBindStates()->pFileOpener.GetPtr(),
        (ImageCreator*)pls->GetBindStates()->pImageCreator.GetPtr(), pimageHeap);

    String                  errorMessage;
    ResourceLib::BindHandle bh;
    Ptr<ImageResource>      pimageRes;

    if (pls->pWeakResourceLib->BindResourceKey(&bh, imageKey) == ResourceLib::RS_NeedsResolve)
    {
        Ptr<Render::Image> pimage;
        ImageCreator*      pcreator = (ImageCreator*)pls->GetBindStates()->pImageCreator.GetPtr();
        if (pcreator)
        {
            if (prfi->pExporterInfo)
            {
                ImageCreateExportInfo cinfo(pimageHeap, 0, (Resource::ResourceUse)prfi->Use);
                cinfo.SetStates(pls->GetLog(), pls->GetBindStates()->pFileOpener,
                                pls->GetImageFileHandlerRegistry());
                cinfo.pExporterInfo = prfi->pExporterInfo;
                cinfo.Format        = LoaderImpl::FileFormat2RenderImageFile(prfi->Format);
                cinfo.TargetWidth   = prfi->TargetWidth;
                cinfo.TargetHeight  = prfi->TargetHeight;
                cinfo.ExportName    = prfi->ExportName;
                pimage = *pcreator->LoadExportedImage(cinfo, pimageFileInfo->FileName);
            }
            else
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_FileImage, pimageHeap, 0,
                                      (Resource::ResourceUse)prfi->Use);
                cinfo.SetStates(pls->GetLog(), pls->GetBindStates()->pFileOpener,
                                pls->GetImageFileHandlerRegistry());
                pimage = *pcreator->LoadImageFile(cinfo, pimageFileInfo->FileName);
            }
        }

        if (pimage)
        {
            Render::Matrix2F m;
            Render::ImageSize sz = pimage->GetSize();
            m.AppendScaling(float(prfi->TargetWidth) / float(sz.Width), float(prfi->TargetHeight) / float(sz.Height));
            pimage->SetMatrix(m);
            pimageRes = *SF_HEAP_NEW(pimageHeap) ImageResource(pimage, imageKey, (Resource::ResourceUse)prfi->Use);
        }

        if (pimageRes)
            bh.ResolveResource(pimageRes);
        else
        {
            errorMessage = "Failed to load image '";
            errorMessage += pimageFileInfo->FileName;
            errorMessage += "'";
            bh.CancelResolve(errorMessage.ToCStr());
        }
    }
    else
    {
        pimageRes = *(ImageResource*)bh.WaitForResolve();
        if (!pimageRes)
            errorMessage = bh.GetResolveError();
    }

    if (!pimageRes)
    {
        pls->GetLogState()->LogError("%s", errorMessage.ToCStr());
        return false;
    }
    pbindData->pResource = pimageRes;
    return true;
}

// The image of the source through the image creator of the binding, as an ImageResource.
// @0x142638ee0
// MS2-FUNCTIONAL: register allocation (the exe keeps the heap in rbx, here rdi)
bool ImageResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                          MemoryHeap* pheap) const
{
    ImageCreateInfo cinfo(ImageCreateInfo::Create_FileImage, 0, 0, Resource::Use_None);
    cinfo.SetStates(pls->GetLog(), pls->GetBindStates()->pFileOpener, pls->GetImageFileHandlerRegistry());
    cinfo.pHeap = pheap;

    ImageCreator* pimageCreator = pls->GetImageCreator();
    if (!pimageCreator)
        return false;
    Ptr<Render::Image> pimage = *pimageCreator->CreateImage(cinfo, (Render::ImageSource*)hdata);
    if (!pimage)
        return false;
    Ptr<ImageResource> pres = *SF_HEAP_NEW(pheap) ImageResource(pimage, Resource::Use_Bitmap);
    if (!pres)
        return false;
    pbindData->pResource = pres;
    return true;
}

// A rectangle of another image of the movie, as a resource (0x80 bytes, vftable 0x14318f568).
class SubImageResource : public ImageResource
{
    Render::ImageRect Rect;        // +0x68
    ResourceId        BaseImageId; // +0x78

public:
    SubImageResource(ImageResource* pbase, ResourceId baseId, const Render::ImageRect& rect)
        : ImageResource(Ptr<Render::Image>(*SF_HEAP_AUTO_NEW(pbase->GetImage())
                                               Render::SubImage(static_cast<Render::Image*>(pbase->GetImage()), rect))),
          Rect(rect), BaseImageId(baseId)
    {
    }

    virtual ResourceId GetBaseImageId() { return BaseImageId; }
};

// What a sub-image request holds: the base image, by resource or by id, and the rectangle.
struct SubImageResourceInfo : public RefCountImpl
{
    ResourceId         ImageId;        // +0x10
    Ptr<ImageResource> pImageResource; // +0x18
    Render::ImageRect  Rect;           // +0x20
};

// Creates the sub-images per binding (vftable 0x14318f620).
class SubImageResourceCreator : public ResourceData::DataInterface
{
public:
    static ResourceData CreateSubImageResourceData(SubImageResourceInfo* pinfo);

    virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                MemoryHeap* pheap) const;
};

// The base image comes from the info or, by id, from the binding.
// @0x142639000
// MS2-FUNCTIONAL: the exe inlines ResourceBinding::GetResourceData (the frozen fast path) here; cl keeps it out of line
bool SubImageResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                             MemoryHeap* pheap) const
{
    SubImageResourceInfo* pinfo     = (SubImageResourceInfo*)hdata;
    ImageResource*        pimageRes = pinfo->pImageResource;
    if (!pimageRes)
    {
        ResourceHandle rh;
        pbindData->pBinding->GetOwnerDefImpl()->GetDataDef()->GetResourceHandle(&rh, pinfo->ImageId);
        Resource* pres;
        if (rh.GetHandleType() == ResourceHandle::RH_Pointer)
            pres = rh.GetResourcePtr();
        else
        {
            ResourceBindData rbd;
            pbindData->pBinding->GetResourceData(&rbd, rh.GetBindIndex());
            pres = rbd.pResource;
        }
        if (pres && pres->GetResourceType() == Resource::RT_Image)
            pimageRes = (ImageResource*)pres;
    }
    if (pimageRes)
    {
        pbindData->pResource = *SF_HEAP_NEW(pheap) SubImageResource(pimageRes, ResourceId(0), pinfo->Rect);
        return true;
    }
    return false;
}

// @0x142639280
ResourceData SubImageResourceCreator::CreateSubImageResourceData(SubImageResourceInfo* pinfo)
{
    static SubImageResourceCreator static_inst;
    return ResourceData(&static_inst, pinfo);
}

// A bitmap of the file: an ImageResource right away when the load states have an image creator, otherwise image
// data the bindings turn into resources.
// @0x142637da0
void LoadProcess::AddImageResource(ResourceId rid, Render::ImageSource* pimage)
{
    if (!pimage)
        return;

    ImageCreator* pimageCreator = pLoadStates->GetLoadTimeImageCreator(LoadFlags);
    if (pimageCreator)
    {
        ImageCreateInfo    cinfo(ImageCreateInfo::Create_FileImage, pLoadData->GetHeap());
        Ptr<Render::Image> pimg = *pimageCreator->CreateImage(cinfo, pimage);
        Ptr<ImageResource> pres = *SF_HEAP_NEW(cinfo.pHeap) ImageResource(pimg, Resource::Use_Bitmap);
        AddResource(rid, pres);
    }
    else
    {
        ImageCreateInfo    cinfo(ImageCreateInfo::Create_FileImage, pLoadData->GetHeap());
        ImageCreator       imageCreator;
        Ptr<Render::Image> pimg = *imageCreator.CreateImage(cinfo, pimage);
        Ptr<Render::WrapperImageSource> pwrapper = *SF_HEAP_NEW(cinfo.pHeap) Render::WrapperImageSource(pimg);
        AddDataResource(rid, ImageResourceCreator::CreateImageResourceData(pwrapper));
    }
}

// @0x1426380b0
void LoadProcess::AddImportData(ImportData* pimportData)
{
    pimportData->ImportIndex = ImportIndex++;
    if (!pImportData)
        pImportData = pimportData;

    MovieDataDef::DefBindingData& bindData = pLoadData->BindData;
    if (!bindData.pImports)
    {
        bindData.pImports     = pimportData;
        bindData.pImportsLast = pimportData;
    }
    else
    {
        bindData.pImportsLast->pNext = pimportData;
        bindData.pImportsLast        = pimportData;
    }
    ImportDataCount++;
}

// @0x142638110
bool LoadProcess::BeginSWFLoading(File* pfile)
{
    if (!reinterpret_cast<SWFProcessInfo*>(&ProcessStream)
             ->Initialize(pfile, pLoadStates->pLog, pLoadStates->pZlibSupport, pLoadStates->pParseControl, true))
        return false;
    pLoadData->FileAttributes = SWFFileAttributes;
    pLoadData->BeginSWFLoading(Header);
    return true;
}

// Destroys the tags of the frame that was being loaded (the tag memory itself stays the movie's).
// @0x1426381a0
void LoadProcess::CleanupFrameTags()
{
    UPInt i;
    for (i = 0; i < FrameTags[LS_LoadingSprite].GetSize(); i++)
        FrameTags[LS_LoadingSprite][i]->~ExecuteTag();
    for (i = 0; i < FrameTags[LS_LoadingRoot].GetSize(); i++)
        FrameTags[LS_LoadingRoot][i]->~ExecuteTag();
    for (i = 0; i < InitActionTags.GetSize(); i++)
        InitActionTags[i]->~ExecuteTag();

    FrameTags[LS_LoadingSprite].Clear();
    FrameTags[LS_LoadingRoot].Clear();
    InitActionTags.Clear();
}

// @0x1426385d0
// MS2-FUNCTIONAL: the exe's SetLoadingPlaylistFrame / SetLoadingInitActionFrame take no log argument (our headers declare one)
void LoadProcess::CommitFrameTags()
{
    if (LoadState == LS_LoadingSprite)
    {
        pTimelineDef->SetLoadingPlaylistFrame(TagArrayToFrame(FrameTags[LoadState]), 0);
    }
    else
    {
        pLoadData->SetLoadingPlaylistFrame(TagArrayToFrame(FrameTags[LoadState]), 0);
        pLoadData->SetLoadingInitActionFrame(TagArrayToFrame(InitActionTags), 0);
    }
}

// @0x142638690
FrameBindData* LoadProcess::CreateFrameBindData()
{
    FrameBindData* pdata = pLoadData->AllocMovieDefClass<FrameBindData>();
    pdata->ImportCount   = ImportDataCount;
    pdata->pImportData   = pImportData;
    pdata->FontCount     = FontDataCount;
    pdata->pFontData     = pFontData;
    pdata->ResourceCount = ResourceDataCount;
    pdata->pResourceData = pResourceData;

    ImportDataCount   = 0;
    ResourceDataCount = 0;
    FontDataCount     = 0;
    pImportData       = 0;
    pResourceData     = 0;
    pFontData         = 0;
    return pdata;
}

// @0x142639470
void LoadProcess::ReadRgbaTag(Render::Color* pc, TagType tagType)
{
    if (tagType <= Tag_DefineShape2)
        GetStream()->ReadRgb(pc);
    else
        GetStream()->ReadRgba(pc);
}

// @0x142639520
TimelineDef::Frame LoadProcess::TagArrayToFrame(
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> >& tagArray)
{
    TimelineDef::Frame frame;
    if (tagArray.GetSize())
    {
        UPInt memSize     = sizeof(ExecuteTag*) * tagArray.GetSize();
        frame.pTagPtrList = (ExecuteTag**)pLoadData->AllocTagMemory(memSize);
        if (frame.pTagPtrList)
        {
            memcpy(frame.pTagPtrList, &tagArray[0], memSize);
            frame.TagCount = (unsigned)tagArray.GetSize();
        }
        tagArray.Clear();
    }
    return frame;
}

}} // namespace Scaleform::GFx
