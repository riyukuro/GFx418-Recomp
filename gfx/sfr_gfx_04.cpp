// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_MovieDef (the parsed movie data
// shared by every binding of a file: MovieDataDef with its load-time data LoadTaskData and the tag memory allocator;
// the bound movie MovieDefImpl with its BindTaskData and the MovieBindProcess that binds frame by frame).
// MS2-UNIT: sfr_gfx_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c92b0-0x1425d51d0 .text$mn
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7ResourceReport@GFx@Scaleform@@6B@ 0x14318b2b0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BAJ@@Scaleform@@6B@ 0x14318b470
// MS2-PIN: ??_7?$RefCountBase@VLoadUpdateSync@GFx@Scaleform@@$0BAJ@@Scaleform@@6B@ 0x14318b478
// MS2-PIN: ??_7LoadUpdateSync@GFx@Scaleform@@6B@ 0x14318b480
// MS2-PIN: ??_7?$RefCountBase@VLoadTaskDataBase@MovieDataDef@GFx@Scaleform@@$0BAJ@@Scaleform@@6B@ 0x14318b488
// MS2-PIN: ??_7LoadTaskDataBase@MovieDataDef@GFx@Scaleform@@6B@ 0x14318b490
// MS2-PIN: ??_7LoadTaskData@MovieDataDef@GFx@Scaleform@@6B@ 0x14318b498
// MS2-PIN: ??_7MovieDataDef@GFx@Scaleform@@6BTimelineDef@12@@ 0x14318b4b8
// MS2-PIN: ??_7MovieDataDef@GFx@Scaleform@@6BResourceReport@12@@ 0x14318b558

#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/kernel/sf_file.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_std.h"
#include <string.h>

namespace Scaleform { namespace GFx {

// Allocation stat of the shape data.
enum { StatMD_ShapeData_Mem = 0x104 };

// Page allocator of the shape paths of a movie (GFx_Shape).
class PathAllocator : public NewOverrideBase<StatMD_ShapeData_Mem>
{
public:
    PathAllocator(unsigned pageSize = 0x2000); // exe 0x142636190
    ~PathAllocator();                          // exe 0x1426361b0

private:
    UByte Data[0x18];
};

// The character definitions a movie creates empty ones of (bodies in their own units; only what is used here).
class SpriteDef : public CharacterDef
{
    UByte Data[0x68 - sizeof(CharacterDef)];

public:
    SpriteDef(MovieDataDef* pmd); // exe 0x1425d5320
    virtual CharacterDefType GetType() const;
    void InitEmptyClipDef();      // exe 0x1425d80c0
};

class TextFieldDef : public CharacterDef
{
    UByte Data[0x90 - sizeof(CharacterDef)];

public:
    TextFieldDef();          // exe 0x14258d550
    virtual CharacterDefType GetType() const;
    void InitEmptyTextDef(); // exe 0x14258e070
};

class ShapeDataBase : public RefCountBase<ShapeDataBase, StatMD_ShapeData_Mem>
{
    UByte Data[0x20 - 0x10];

public:
    enum EmptyShape
    {
        Empty_Shape
    };
    ShapeDataBase(EmptyShape); // exe 0x142659740
};

class SwfShapeCharacterDef : public CharacterDef
{
    UByte Data[0x30 - sizeof(CharacterDef)];

public:
    SwfShapeCharacterDef(ShapeDataBase* pshapeData); // exe 0x1426597e0
    virtual CharacterDefType GetType() const;
};

extern "C" const void* const MS2_SF_ConstShapeNoStyles_vftable[]; // ??_7ConstShapeNoStyles@GFx@Scaleform@@6B@ 0x14318b708
extern "C" const void* const MS2_SF_Resource_vftable[];           // ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
extern "C" const void* const MS2_SF_VideoCharacterDef_vftable[];  // ??_7VideoCharacterDef@Video@GFx@Scaleform@@6B@ 0x14318b778

// The shape data without styles of the empty shape (GFx_ShapeSwf): the base with the exe's vtable.
class ConstShapeNoStyles : public ShapeDataBase
{
public:
    ConstShapeNoStyles() : ShapeDataBase(Empty_Shape) { *(const void* const**)this = MS2_SF_ConstShapeNoStyles_vftable; }
};

// The image of an empty video definition (Video_VideoCharacter, 0x30 bytes) with its inline construction.
struct EmptyVideoDefImage
{
    const void* const* vfptr;
    volatile int       RefCount;
    void*              pLib;
    UInt32             Id;
    UInt32             Width;
    UInt32             Height;
    UInt32             NumFrames;
    UByte              Smoothing;
    UByte              Deblocking;
    UByte              Codec;

    EmptyVideoDefImage()
    {
        pLib      = 0;
        vfptr     = MS2_SF_Resource_vftable;
        RefCount  = 1;
        Id        = ResourceId::InvalidId;
        vfptr     = MS2_SF_VideoCharacterDef_vftable;
        Width     = 0;
        Height    = 0;
        NumFrames = 0;
        Smoothing = 0;
        Deblocking = 0;
        Codec     = 2;
    }
    void* operator new(UPInt sz, MemoryHeap* pheap) { return pheap->Alloc(sz); }
    void  operator delete(void* p, MemoryHeap*) { Memory::Free(p); }
    Resource* GetResource() { return (Resource*)this; }
};

// Ids of the empty characters of every movie.
enum
{
    CharId_EmptyMovieClip = ResourceId::IdType_InternalConstant | 1,
    CharId_EmptyTextField,
    CharId_EmptyButton,
    CharId_EmptyShape,
    CharId_EmptyVideo
};

// *** DataAllocator

// @0x1425cbc90
DataAllocator::~DataAllocator()
{
    while (pAllocations)
    {
        Block* pnext = pAllocations->pNext;
        SF_FREE(pAllocations);
        pAllocations = pnext;
    }
}

// @0x1425d1c00
// MS2-FUNCTIONAL: block list linking scheduled differently
void* DataAllocator::OverflowAlloc(UPInt bytes)
{
    // Big requests get a block of their own; the current block keeps serving the small ones.
    if (bytes > (BlockSize - sizeof(Block)) / 2)
        return AllocIndividual(bytes);

    UByte* pmem;
    if (bytes > BytesLeft)
    {
        Block* pblock = (Block*)SF_HEAP_ALLOC(pHeap, BlockSize, StatMD_Other_Mem);
        if (!pblock)
            return 0;
        pblock->pNext = pAllocations;
        pAllocations  = pblock;
        pmem          = (UByte*)(pblock + 1);
        BytesLeft     = BlockSize - sizeof(Block);
    }
    else
        pmem = pCurrent;
    pCurrent = pmem + bytes;
    BytesLeft -= bytes;
    return pmem;
}

// @0x1425cd810
void* DataAllocator::AllocIndividual(UPInt bytes)
{
    Block* pblock = (Block*)SF_HEAP_ALLOC(pHeap, bytes + sizeof(Block), StatMD_Other_Mem);
    if (!pblock)
        return 0;
    pblock->pNext = pAllocations;
    pAllocations  = pblock;
    return pblock + 1;
}

// *** MovieDataDef

// @0x1425cb000
// MS2-FUNCTIONAL: HeapDesc member store order and the heap-name String release differ
MovieDataDef::MovieDataDef(const ResourceKey& creationKey, MovieDataType mtype, const char* purl,
                           MemoryHeap* pargHeap, bool debugHeap, UPInt memoryArena)
    : mResourceKey(creationKey), MovieType(mtype)
{
    MemoryHeap* pheap = pargHeap;
    if (!pheap)
    {
        String   heapName("MovieData \"", GetShortFilename(purl), "\"");
        HeapDesc desc((debugHeap << 12) | HeapDesc::Heap_FastTinyBlocks, 16, 8 * 1024, 0, ~UPInt(0), 0,
                      HeapId_MovieData, memoryArena);
        pheap = Memory::GetGlobalHeap()->CreateHeap(heapName.ToCStr(), desc);
    }

    pData = *new (pheap) LoadTaskData(this, purl, pheap);

    // A heap of our own goes away with the load data.
    if (!pargHeap)
        pheap->ReleaseOnFree(pData);
}

// @0x1425cc1f0
MovieDataDef::~MovieDataDef()
{
    // A loading thread still running sees the cancel flag and stops.
    pData->OnMovieDataDefRelease();
}

// @0x1425d1110
// MS2-FUNCTIONAL: register allocation differs
String MovieDataDef::GetResourceName() const
{
    return String(GetShortFilename(pData->GetFileURL()));
}

// *** MovieDataDef::DefBindingData

// @0x1425cbce0
MovieDataDef::DefBindingData::~DefBindingData()
{
    // The nodes live in the tag memory: only what they reference is released here.
    FrameBindData* pframe = pFrameData;
    pFrameData = 0;
    while (pframe)
        pframe = pframe->pNextFrame;

    while (pImports)
    {
        ImportData* pimport = pImports;
        pImports = pImports->pNext;
        pimport->~ImportData();
    }
    while (pResourceNodes)
    {
        ResourceDataNode* pnode = pResourceNodes;
        pResourceNodes = pResourceNodes->pNext;
        pnode->~ResourceDataNode();
    }
    while (pFonts)
    {
        FontDataUseNode* pfont = pFonts;
        pFonts = pFonts->pNext;
        pfont->~FontDataUseNode();
    }
}

// *** MovieDataDef::LoadTaskData

// @0x1425ca980
MovieDataDef::LoadTaskData::LoadTaskData(MovieDataDef* pdataDef, const char* purl, MemoryHeap* pheap)
    : LoadTaskDataBase(pheap), pHeap(pheap), FileURL(purl), GradientIdGenerator(ResourceId::IdType_GradientImage),
      pSoundStream(0), Scenes(0)
{
    FileAttributes = 0;
    pMetadata      = 0;
    MetadataSize   = 0;

    pPathAllocator = SF_HEAP_NEW(pHeap) PathAllocator();

    LoadingCanceled = false;
    LoadState       = LS_Uninitialized;
    LoadingFrame    = 0;
    TagCount        = 0;
    ResIndexCounter = 0;
    InitActionsCnt  = 0;

    pFrameUpdate = *SF_NEW LoadUpdateSync();

    // The empty characters of createEmptyMovieClip and friends.
    Ptr<SpriteDef> pspriteDef = *SF_HEAP_NEW(pHeap) SpriteDef(pdataDef);
    pspriteDef->InitEmptyClipDef();
    AddResource(ResourceId(CharId_EmptyMovieClip), pspriteDef);

    Ptr<TextFieldDef> ptextDef = *SF_HEAP_NEW(pHeap) TextFieldDef();
    ptextDef->InitEmptyTextDef();
    AddResource(ResourceId(CharId_EmptyTextField), ptextDef);

    Ptr<ButtonDef> pbuttonDef = *SF_HEAP_NEW(pHeap) ButtonDef();
    AddResource(ResourceId(CharId_EmptyButton), pbuttonDef);

    Ptr<SwfShapeCharacterDef> pshapeDef =
        *SF_HEAP_NEW(pHeap) SwfShapeCharacterDef(Ptr<ShapeDataBase>(*SF_HEAP_NEW(pHeap) ConstShapeNoStyles()));
    AddResource(ResourceId(CharId_EmptyShape), pshapeDef);

    EmptyVideoDefImage* pvideoDef = new (pHeap) EmptyVideoDefImage();
    AddResource(ResourceId(CharId_EmptyVideo), pvideoDef->GetResource());
    pvideoDef->GetResource()->Release();
}

// @0x1425cbe00
// MS2-FUNCTIONAL: member hash/array destructors are inlined here, the exe calls them out of line
MovieDataDef::LoadTaskData::~LoadTaskData()
{
    ResourceLocker lock(this);

    // The tags have their destructors run; their memory goes with the tag allocator.
    for (unsigned i = 0; i < Playlist.GetSize(); i++)
        Playlist[i].DestroyTags();
    for (unsigned i = 0; i < InitActionList.GetSize(); i++)
        InitActionList[i].DestroyTags();

    delete pPathAllocator;

    if (pMetadata)
    {
        SF_FREE(pMetadata);
        pMetadata = 0;
    }
    if (pSoundStream)
        pSoundStream->Release();
}

// @0x1425d1b40
void MovieDataDef::LoadTaskData::OnMovieDataDefRelease()
{
    if (LoadState <= LS_LoadingFrames)
        LoadingCanceled = true;
}

// @0x1425d0590
// MS2-FUNCTIONAL: HeapDesc Arena store order differs
MemoryHeap* MovieDataDef::LoadTaskData::GetImageHeap()
{
    if (!pImageHeap)
    {
        HeapDesc desc(HeapDesc::Heap_FastTinyBlocks, 32, 4 * 1024, 0, ~UPInt(0), 0, HeapId_Images);
        pImageHeap = *pHeap->CreateHeap("_Images", desc);
    }
    return pImageHeap;
}

// @0x1425cd850
// MS2-FUNCTIONAL: store order of the copied header fields differs
void MovieDataDef::LoadTaskData::BeginSWFLoading(const MovieHeaderData& header)
{
    Header.FileLength = header.FileLength;
    Header.Version    = header.Version;
    Header.FrameRect  = header.FrameRect;
    Header.FPS        = header.FPS;
    Header.FrameCount = header.FrameCount;
    Header.SWFFlags   = header.SWFFlags;

    const ExporterInfo* pei = &header.mExporterInfo.GetData();
    Header.mExporterInfo.SetData(pei->Version, pei->Format, pei->pSWFName, pei->pPrefix, pei->ExportFlags);

    UpdateLoadState(LoadingFrame, LS_LoadingFrames);
}

// @0x1425cf360
bool MovieDataDef::LoadTaskData::FinishLoadingFrame(LoadProcess* plp, bool finished)
{
    plp->CommitFrameTags();

    bool           frameOk = true;
    FrameBindData* pframe  = plp->CreateFrameBindData();
    if (pframe)
    {
        pframe->Frame       = LoadingFrame;
        pframe->BytesLoaded = plp->GetBytesLoaded();
    }

    LoadUpdateSync* psync = pFrameUpdate;
    Mutex::Locker   lock(&psync->GetMutex());

    if (pframe)
    {
        if (!BindData.pFrameData)
            BindData.pFrameData = pframe;
        else
            BindData.pFrameDataLast->pNextFrame = pframe;
        LoadingFrame++;
        BindData.pFrameDataLast = pframe;
        if (finished)
            LoadState = LS_LoadFinished;
    }
    else
    {
        frameOk   = false;
        LoadState = LS_LoadError;
    }

    if (finished || !frameOk)
        pFrameUpdate->UpdateNotify();
    return frameOk;
}

// @0x1425d31c0
void MovieDataDef::LoadTaskData::UpdateLoadState(unsigned loadingFrame, MovieLoadState loadState)
{
    LoadUpdateSync* psync = pFrameUpdate;
    Mutex::Locker   lock(&psync->GetMutex());
    LoadingFrame = loadingFrame;
    LoadState    = loadState;
    pFrameUpdate->UpdateNotify();
}

// @0x1425d3c40
void MovieDataDef::LoadTaskData::WaitForLoadFinish()
{
    if (LoadState <= LS_LoadingFrames)
        pFrameUpdate->WaitForLoadFinished();
}

// @0x1425d3b20
void MovieDataDef::LoadTaskData::WaitForFrame(unsigned frame)
{
    if (LoadState <= LS_LoadingFrames && LoadingFrame <= frame)
    {
        LoadUpdateSync* psync = pFrameUpdate;
        Mutex::Locker   lock(&psync->GetMutex());
        while (LoadState <= LS_LoadingFrames && LoadingFrame <= frame)
            pFrameUpdate->WaitForNotify();
    }
}

// @0x1425d0ab0
unsigned MovieDataDef::LoadTaskData::GetMetadata(char* pbuff, unsigned buffSize) const
{
    unsigned size = MetadataSize;
    if (pbuff)
    {
        if (buffSize < size)
            size = buffSize;
        if (pMetadata)
            memcpy(pbuff, pMetadata, size);
    }
    return size;
}

// @0x1425d2d80
void MovieDataDef::LoadTaskData::SetMetadata(UByte* pdata, unsigned size)
{
    pMetadata = (UByte*)SF_HEAP_ALLOC(pHeap, size, StatMD_Other_Mem);
    if (pMetadata)
    {
        MetadataSize = size;
        memcpy(pMetadata, pdata, size);
    }
}

// @0x1425cd370
void MovieDataDef::LoadTaskData::AddResource(ResourceId rid, Resource* pres)
{
    ResourceLocker lock(this);
    Resources.Add(rid, ResourceHandle(pres));
}

// @0x1425cd2c0
ResourceHandle MovieDataDef::LoadTaskData::AddNewResourceHandle(ResourceId rid)
{
    ResourceHandle hres(ResourceHandle::RH_Index, ResIndexCounter);
    ResIndexCounter++;

    ResourceLocker lock(this);
    Resources.Add(rid, hres);
    return hres;
}

// @0x1425d0f90
bool MovieDataDef::LoadTaskData::GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const
{
    ResourceLocker lock(this);

    ResourceHash::ConstIterator it = Resources.Find(rid);
    if (it == Resources.End())
        return false;
    *phandle = it->Second;
    return true;
}

// @0x1425cfba0
Render::Font* MovieDataDef::LoadTaskData::GetFontData(ResourceId rid)
{
    for (FontDataUseNode* pfont = BindData.pFonts; pfont; pfont = pfont->pNext)
    {
        if (pfont->Id == rid)
            return pfont->pFontData;
    }
    return 0;
}

// @0x1425cd1e0
void MovieDataDef::LoadTaskData::AddFrameName(const String& name, LogState*)
{
    Lock::Locker lock(&PlaylistLock);
    NamedFrames.SetCaseInsensitive(name, LoadingFrame);
}

// @0x1425d2d20
void MovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(const Frame& frame, LogState*)
{
    Lock::Locker lock(&PlaylistLock);
    Playlist[LoadingFrame] = frame;
}

// @0x1425d2cb0
void MovieDataDef::LoadTaskData::SetLoadingInitActionFrame(const Frame& frame, LogState*)
{
    Lock::Locker lock(&PlaylistLock);
    InitActionList[LoadingFrame] = frame;
    InitActionsCnt++;
}

// @0x1425d0cd0
const TimelineDef::Frame MovieDataDef::LoadTaskData::GetPlaylist(int frameNumber) const
{
    // Once loading is over nobody writes the playlist any more.
    if (LoadState >= LS_LoadFinished)
        return Playlist[frameNumber];

    Lock::Locker lock(&PlaylistLock);
    return Playlist[frameNumber];
}

// @0x1425d0750
bool MovieDataDef::LoadTaskData::GetInitActions(Frame* pframe, int frameNumber) const
{
    Lock::Locker lock(&PlaylistLock);
    if ((unsigned)frameNumber >= InitActionList.GetSize())
        return false;
    *pframe = InitActionList[frameNumber];
    return true;
}

// @0x1425d0710
unsigned MovieDataDef::LoadTaskData::GetInitActionListSize() const
{
    Lock::Locker lock(&PlaylistLock);
    return (unsigned)InitActionList.GetSize();
}

// @0x1425d0940
bool MovieDataDef::LoadTaskData::GetLabeledFrame(const char* label, unsigned* frameNumber,
                                                 bool translateNumbers) const
{
    if (LoadState >= LS_LoadFinished)
        return TranslateFrameString(NamedFrames, label, frameNumber, translateNumbers);

    Lock::Locker lock(&PlaylistLock);
    return TranslateFrameString(NamedFrames, label, frameNumber, translateNumbers);
}

// @0x1425d0150
const String* MovieDataDef::LoadTaskData::GetFrameLabel(unsigned frameNumber, unsigned* exactFrameNumberForLabel) const
{
    if (LoadState >= LS_LoadFinished)
        return TranslateNumberToFrameString(NamedFrames, frameNumber, exactFrameNumberForLabel);

    Lock::Locker lock(&PlaylistLock);
    return TranslateNumberToFrameString(NamedFrames, frameNumber, exactFrameNumberForLabel);
}

// @0x1425d11e0
const MovieDataDef::SceneInfo* MovieDataDef::LoadTaskData::GetScene(UPInt index) const
{
    if (Scenes && index < Scenes->GetSize())
        return &(*Scenes)[index];
    return 0;
}

// @0x1425d1220
const MovieDataDef::SceneInfo* MovieDataDef::LoadTaskData::GetScenes(UPInt* count) const
{
    if (Scenes)
    {
        *count = Scenes->GetSize();
        return &(*Scenes)[0];
    }
    *count = 0;
    return 0;
}

// @0x1425d2ef0
void MovieDataDef::LoadTaskData::SetSoundStream(SoundStreamDef* psoundStream)
{
    if (pSoundStream)
        pSoundStream->Release();
    if (psoundStream)
        psoundStream->AddRef();
    pSoundStream = psoundStream;
}

// @0x1425cef30
void MovieDataDef::LoadTaskData::ExportResource(const String& symbol, ResourceId rid, const ResourceHandle& hres)
{
    ResourceLocker lock(this);

    Exports.SetCaseInsensitive(symbol, hres);
    // The inverse map shares the key string of the export.
    StringHashLH<ResourceHandle>::Iterator it = Exports.FindCaseInsensitive(symbol);
    const StringLH* pname = (it != Exports.End()) ? &it->First : 0;
    InvExports.Set(rid, *pname);
}

// @0x1425cd480
// MS2-FUNCTIONAL: ArrayLH<SceneInfo> PushBack/reserve inlined differently
void MovieDataDef::LoadTaskData::AddScene(const String& name, unsigned off)
{
    if (!Scenes)
        Scenes.Reset(SF_HEAP_NEW(pHeap) ArrayLH<SceneInfo>, true);
    Scenes->PushBack(SceneInfo(pHeap, name, off));
}

// @0x1425d0260
Array<String>* MovieDataDef::LoadTaskData::GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const
{
    bool locked = false;
    if (LoadState < LS_LoadFinished)
    {
        PlaylistLock.DoLock();
        locked = true;
    }
    unsigned n = 0;
    for (StringHashLH<unsigned>::ConstIterator it = NamedFrames.Begin(); it != NamedFrames.End(); ++it)
    {
        if (it->Second == frameNumber)
        {
            destArr->PushBack(it->First);
            ++n;
        }
    }
    if (locked)
        PlaylistLock.Unlock();
    return n ? destArr : 0;
}

// @0x1425d2f70
// MS2-FUNCTIONAL: findIndexAlt inlined here, out of line in the exe
bool MovieDataDef::TranslateFrameString(const StringHashLH<unsigned>& namedFrames, const char* label,
                                        unsigned* frameNumber, bool translateNumbers)
{
    if (!label || !label[0])
        return false;

    if (translateNumbers)
    {
        // A label made of digits (with an optional sign and blanks) is a 1-based frame number.
        bool digitFound = false;
        const char* p;
        for (p = label; *p; p++)
        {
            char c = *p;
            if (c >= '0' && c <= '9')
            {
                digitFound = true;
                continue;
            }
            if ((c == '+' || c == '-') && !digitFound)
                continue;
            if (c == ' ' || c == '\t')
                continue;
            break;
        }
        if (!*p)
        {
            char*    tail = 0;
            unsigned num  = (unsigned)SFstrtod(label, &tail);
            if (tail == label || *tail)
                return false;
            *frameNumber = num - 1;
            return true;
        }
    }
    return namedFrames.GetCaseInsensitive(String(label), frameNumber);
}

// @0x1425d30b0
// MS2-FUNCTIONAL: hash iterator loop shaped differently
const String* MovieDataDef::TranslateNumberToFrameString(const StringHashLH<unsigned>& namedFrames,
                                                         unsigned frameNumber, unsigned* exactFrameNumberForLabel)
{
    // The closest label at or before the frame.
    const String* plabel     = 0;
    unsigned      labelFrame = 0;
    for (StringHashLH<unsigned>::ConstIterator it = namedFrames.Begin(); it != namedFrames.End(); ++it)
    {
        unsigned f = it->Second;
        if (f <= frameNumber && f >= labelFrame)
        {
            labelFrame = f;
            plabel     = &it->First;
        }
    }
    if (exactFrameNumberForLabel)
        *exactFrameNumberForLabel = labelFrame;
    return plabel;
}

}} // namespace Scaleform::GFx
