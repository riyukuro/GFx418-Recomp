// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx core, the last range of queue
// unit sfr_gfx_07: the shape path allocator, the resource binding table, the load process and load states, the
// player tasks and the font manager.
// MS2-UNIT: sfr_gfx_07e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142636190-0x14263dfa0 .text$mn

#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/gfx/gfx_taskmanager.h"
#include "../include/gfx/gfx_shape.h"
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

}} // namespace Scaleform::GFx
