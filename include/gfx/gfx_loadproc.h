// Recovered Scaleform 4.1.18 GFx: LoadProcess, the loader task that parses one SWF file into a MovieDataDef, as seen
// by the tag readers and the AS3 tag loaders. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x420 bytes) from the exe's tag readers; only the members the recovered units use are named.
#ifndef MS2_SF_GFX_LOADPROC_H
#define MS2_SF_GFX_LOADPROC_H

#include "gfx_characterdef.h"
#include "gfx_loaderimpl.h"
#include "gfx_log.h"
#include "gfx_moviedef.h"
#include "gfx_stream.h"
#include "../kernel/sf_array.h"

namespace Scaleform { namespace GFx {

class SoundStreamDef;

class LogState;

// The timeline a sprite definition is loaded into.
class TimelineIODef : public TimelineDef
{
public:
    // Hands the tags of a loaded frame to the timeline (the tag memory stays the movie data's).
    virtual void SetLoadingPlaylistFrame(const Frame& frame, LogState* plog) = 0;
    virtual void AddFrameName(const String& name, LogState* plog)            = 0;
};

class DisplayObjContainer;
class TimelineSnapshot;

struct ActionPriority
{
    enum Priority
    {
        AP_Highest = 0,
        AP_Initialize = 1,   // onClipEvent(initialize)
        AP_InitClip,         // the movie's own initclips
        AP_Construct,
        AP_Frame,
        AP_Normal = AP_Frame,
        AP_Load,
        AP_Lowest = AP_Load
    };
};

// A tag run when its frame is reached (placed in the loader's tag memory; vftable 0x14313ba68).
class ExecuteTag
{
public:
    virtual ~ExecuteTag() {}

    virtual void Execute(DisplayObjContainer*) {}
    virtual void ExecuteWithPriority(DisplayObjContainer* m, ActionPriority::Priority) { Execute(m); }
    virtual bool IsRemoveTag() const { return false; }
    virtual bool IsActionTag() const { return false; }
    virtual bool IsInitImportActionsTag() const { return false; }
    virtual void AddToTimelineSnapshot(TimelineSnapshot*, unsigned) {}
    virtual void Trace(const char*) {}
};

class MovieDefImpl;

// The InitActions of an imported movie, run in the context of the importing movie's sprite.
class GFxInitImportActions : public ExecuteTag
{
public:
    // exe 0x1425cee70
    void ExecuteInContext(DisplayObjContainer* m, MovieDefImpl* pbindDef, bool recursiveCheck = 1);

    // Runs in the binding context of the target sprite's own movie (exe 0x1425ced90).
    virtual void Execute(DisplayObjContainer* m);

    unsigned ImportIndex; // +8 index into the binding's import source movies
};

class LoadProcess : public LoaderTask, public LogBase<LoadProcess>
{
public:
    enum LoadStateType
    {
        LS_LoadingRoot   = 0,
        LS_LoadingSprite = 1 // between DefineSprite and its end tag
    };

    // The stream of the tag being read: the SWF stream, or another one while a nested block is parsed.
    Stream* GetStream() { return pAltStream ? pAltStream : &ProcessStream; }

    unsigned GetLoadingFrame() const { return pLoadData->GetLoadingFrame(); }
    // A streaming sound block belongs to the frame of the timeline being loaded.
    unsigned GetLoadingFrameForStreamSound() const
    {
        if (LoadState == LS_LoadingSprite)
            return pTimelineDef->GetLoadingFrame();
        return GetLoadingFrame();
    }

    Log* GetLog() const { return pLoadStates->pLog ? pLoadStates->pLog->GetLog() : 0; }

    LoadStates*          GetLoadStates() const { return pLoadStates; }
    MemoryHeap*          GetLoadHeap() const   { return pLoadData->GetHeap(); }
    const ExporterInfo*  GetExporterInfo() const { return pLoadData->GetExporterInfo(); }

    // Byte-aligned readers of the current stream (exe 0x14258ec50, 0x1425c8c20).
    UInt16 ReadU16() { return GetStream()->ReadU16(); }
    UInt32 ReadU32() { return GetStream()->ReadU32(); }

    bool GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const
    {
        return pLoadData->GetResourceHandle(phandle, rid);
    }

    // Adds a resource created per binding from resData (exe 0x142637b60).
    ResourceHandle AddDataResource(ResourceId rid, const ResourceData& resData);

    // The streaming sound of the timeline being loaded.
    SoundStreamDef* GetSoundStream() const
    {
        if (LoadState == LS_LoadingSprite)
            return pTimelineDef->GetSoundStream();
        return pLoadData->GetSoundStream();
    }
    void SetSoundStream(SoundStreamDef* pdef)
    {
        if (LoadState == LS_LoadingSprite)
            pTimelineDef->SetSoundStream(pdef);
        else
            pLoadData->SetSoundStream(pdef);
    }

    // A tag constructed in the tag memory of the movie.
    template<class T>
    T* AllocTag()
    {
        return new (pLoadData->AllocTagMemory(sizeof(T))) T;
    }
    void AddExecuteTag(ExecuteTag* ptag) { FrameTags[LoadState].PushBack(ptag); }

    // SWF FileAttributes flags of the file.
    enum FileAttrFlags
    {
        FileAttr_UseNetwork        = 0x01,
        FileAttr_UseActionScript3  = 0x08,
        FileAttr_HasMetadata       = 0x10
    };
    unsigned GetFileAttributes() const { return pLoadData->GetFileAttributes(); }

    // exe 0x1425c8ca0
    UByte ReadU8()            { return GetStream()->ReadU8(); }
    int   Tell()              { return GetStream()->Tell(); }
    void  SetPosition(int pos) { GetStream()->SetPosition(pos); }

    // Bytes of the SWF data read so far.
    unsigned GetBytesLoaded() { return GetStream()->Tell() - FileStartPos; }

    // Hands the tags of the finished frame to the timeline being loaded (exe 0x1426385d0).
    void           CommitFrameTags();
    // The bind data of the finished frame, in the tag memory (exe 0x142638690).
    FrameBindData* CreateFrameBindData();

    // Drops the tags of an unfinished frame when loading is canceled (exe 0x1426381a0).
    void CleanupFrameTags();
    // Tags wait for a frame end (the root timeline also counts its InitAction tags).
    bool FrameTagsAvailable() const
    {
        return FrameTags[LoadState].GetSize() > 0 || (LoadState == LS_LoadingRoot && InitActionTags.GetSize() > 0);
    }

    // End of the SWF data in the file.
    UInt32 GetFileEndPos() const { return FileEndPos; }

    // Tells the progress handler about the tag just opened.
    void ReportProgress(const String& fileURL, const TagInfo& tagInfo, bool calledFromDefSprite)
    {
        if (ProgressHandler* phandler = pLoadStates->GetProgressHandler())
            phandler->LoadTagUpdate(ProgressHandler::TagInfo(fileURL, tagInfo.TagType, tagInfo.TagOffset,
                                                             tagInfo.TagLength, tagInfo.TagDataOffset),
                                    calledFromDefSprite);
    }

    // The AMP debug-file handle of the movie.
    void SetSwdHandle(UInt32 swdHandle) { pLoadData->SetSwdHandle(swdHandle); }

private:
    // +0x20 LogBase<LoadProcess>
    unsigned                        ParseFlags;      // +0x28
    Ptr<MovieBindProcess>           pBindProcess;    // +0x30
    Ptr<MovieDataDef::LoadTaskData> pLoadData;       // +0x38
    MovieDataDef*                   pDataDef_Unsafe; // +0x40
    UByte                           Unknown48[8];    // +0x48
    Stream                          ProcessStream;   // +0x50 first member of the SWF process info
    UInt32                          FileStartPos;    // +0x2c0 process info: offset of the SWF data in the file
    UInt32                          FileEndPos;      // +0x2c4 process info: end of the SWF data
    UInt32                          NextActionBlock; // +0x2c8 process info
    MovieHeaderData                 Header;          // +0x2d0 process info: the file header
    UInt16                          SWFFileAttributes; // +0x350 process info: FileAttributes tag flags
    UByte                           Unknown352[0xe];   // +0x352 (the process info is 16-byte aligned)
    Ptr<RefCountImpl>               pJpegTables;     // +0x360 Ptr<Render::JPEG::TablesHeader>
    unsigned                        LoadFlags;       // +0x368 Loader::LoadConstants
    unsigned                        ImportIndex;     // +0x36c imports so far
    void*                           pTempBindData;   // +0x370
    // The import / resource / font data the frame being loaded adds to the binding (FrameBindData).
    unsigned                        ImportDataCount;   // +0x378
    unsigned                        ResourceDataCount; // +0x37c
    unsigned                        FontDataCount;     // +0x380
    ImportData*                     pImportDataLast;   // +0x388
    ImportData*                     pImportData;       // +0x390
    ResourceDataNode*               pResourceData;     // +0x398
    ResourceDataNode*               pResourceDataLast; // +0x3a0
    FontDataUseNode*                pFontData;         // +0x3a8
    FontDataUseNode*                pFontDataLast;     // +0x3b0
    LoadStateType                   LoadState;       // +0x3b8
    TimelineIODef*                  pTimelineDef;    // +0x3c0
    // Tags of the frame being loaded, of the root timeline [0] and of the sprite being loaded [1].
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > FrameTags[2]; // +0x3c8
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > InitActionTags; // +0x3f8
    unsigned                        ASInitActionTagsNum; // +0x410
    Stream*                         pAltStream;      // +0x418
    Ptr<RefCountImpl>               pUnknown420;     // +0x420 (released before the frame tag arrays; 0x430 bytes)

public:
    // (appended for the sprite definitions, sfr_gfx_05) the frame tags go to the sprite between DefineSprite and its
    // end tag
    void EnterSpriteDef(TimelineIODef* psprite)
    {
        LoadState    = LS_LoadingSprite;
        pTimelineDef = psprite;
    }
    void LeaveSpriteDef()
    {
        LoadState    = LS_LoadingRoot;
        pTimelineDef = 0;
    }
    const char* GetFileURL() const { return pLoadData->GetFileURL(); }

    // (appended for the static text, sfr_gfx_05d) a root-level definition; sprite-level ones are not kept here
    void AddResource(ResourceId rid, Resource* pres)
    {
        if (LoadState == LS_LoadingRoot)
            pLoadData->AddResource(rid, pres);
    }

    // (appended for sfr_gfx_07e) the load task itself; exe 0x142636cc0 / 0x142637560, vftable 0x14318f5b8
    LoadProcess(MovieDataDef* pdataDef, LoadStates* pstates, unsigned loadFlags);
    virtual ~LoadProcess();
    virtual void Execute();
    virtual void OnAbandon(bool started);

    // Reads and checks the file header and hands it to the movie data.
    bool BeginSWFLoading(File* pfile);
    // An ImportAssets tag, numbered in file order.
    void AddImportData(ImportData* pimportData);
    // A font / image of the file, created per binding.
    ResourceHandle AddFontDataResource(ResourceId rid, Render::Font* pfontData);
    void           AddImageResource(ResourceId rid, Render::ImageSource* pimage);
    // RGB before DefineShape3, RGBA from then on.
    void ReadRgbaTag(Render::Color* pc, TagType tagType);
    // The tags of a frame copied into the tag memory.
    TimelineDef::Frame TagArrayToFrame(Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> >& tagArray);

    // (appended for the tag loaders, sfr_gfx_04b)
    LogState*                   GetLogState() const       { return pLoadStates->GetLogState(); }
    unsigned                    GetVersion() const        { return pLoadData->GetVersion(); }
    MovieDataDef*               GetDataDef_Unsafe() const { return pDataDef_Unsafe; }
    MovieDataDef::LoadTaskData* GetLoadTaskData() const   { return pLoadData; }
    Render::Font*               GetFontData(ResourceId rid) { return pLoadData->GetFontData(rid); }
    void AddCharacter(ResourceId rid, CharacterDef* c) { pLoadData->AddCharacter(rid, c); }
    // Labels the frame of the timeline being loaded.
    void AddFrameName(const String& name, LogState* plog)
    {
        if (LoadState == LS_LoadingSprite)
            pTimelineDef->AddFrameName(name, plog);
        else
            pLoadData->AddFrameName(name, plog);
    }
    // A tag followed by dataSize bytes of tag data (the tag's own one-byte pData included in the size).
    template<class T>
    T* AllocTag(UPInt dataSize)
    {
        return new (pLoadData->AllocTagMemory(sizeof(T) + dataSize - 1)) T;
    }

    // (appended for the AS3 tag loaders, sfr_as3_01)
    bool  IsVerboseParse() const       { return (ParseFlags & ParseControl::VerboseParse) != 0; }
    void* AllocTagMemory(UPInt bytes)  { return pLoadData->AllocTagMemory(bytes); }
    void  ExportResource(const String& symbol, ResourceId rid, const ResourceHandle& hres)
    {
        pLoadData->ExportResource(symbol, rid, hres);
    }
    // An init action of the root timeline (DoInitAction / DoAbc); the AS3 ones are counted.
    void     AddInitAction(ExecuteTag* ptag)
    {
        InitActionTags.PushBack(ptag);
        ++ASInitActionTagsNum;
    }
    unsigned GetASInitActionTagsNum() const { return ASInitActionTagsNum; }

    // (appended, sfr_gfx_04x) the file of the tag stream at its read position (exe 0x1425c8b50)
    File* GetUnderlyingFile();

    // (appended, sfr_gfx_08s2) the shape reader parses the shape records from a stream of its own
    void  SetAltStream(Stream* pstream) { pAltStream = pstream; }
    void* GetTempBindData() const { return pTempBindData; }
};

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::LoadProcess) == 0x430, "LoadProcess size");

#endif
