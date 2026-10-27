// Recovered Scaleform 4.1.18 GFx: the loader implementation and the per-load state set
// (only the parts used by recovered units so far; layouts from the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Out-of-line members not recovered yet bind to the exe:
//   LoaderImpl::CreateMovie_LoadState(LoadStates*, MovieDataDef*, unsigned, UPInt) 0x1425aa390,
//   LoadStates::LoadStates(LoaderImpl*, StateBag*, MovieDefBindStates*) 0x142636ed0,
//   StateBagImpl::SetState 0x142576570, GetStateAddRef 0x14256faa0, GetStatesAddRef 0x14256fc10,
//   StateBag::SetLog 0x1425b39d0.
#ifndef MS2_SF_GFX_LOADERIMPL_H
#define MS2_SF_GFX_LOADERIMPL_H

#include "gfx_moviedef.h"
#include "gfx_log.h"
#include "gfx_taskmanager.h"
#include "ms2/scaleform/kernel/sf_exedata.h"
#include "../render/render_imagefileformat.h"
#include "../kernel/sf_hash.h"
#include "../kernel/sf_file.h"
#include "../../kernel/sf_list.h"

extern "C" int GFx_Compile_with_SF_BUILD_DEBUG;

namespace Scaleform {
class File;
class MemoryHeap;
namespace Render { class ImageSource; }
namespace GFx {

class ParseControl;
class ProgressHandler;
class ImageFileHandlerRegistry;
class ZlibSupportBase;
class VideoBase;
class AudioBase;
class ASSupport;
class LoaderTask;
class MovieBindProcess;
struct MovieInfo;
class Stream;
class LoadProcess;
struct TagInfo;

class ImagePacker;
class ImageCreateInfo;

// Parse options of a loader (state; vftable 0x143109480).
class ParseControl : public State
{
public:
    enum ParseFlagConstants
    {
        VerboseParseNone = 0x00,
        VerboseParse     = 0x01
    };

    ParseControl(unsigned parseFlags = VerboseParseNone) : State(State_ParseControl), ParseFlags(parseFlags) {}

    bool IsVerboseParse() const { return (ParseFlags & VerboseParse) != 0; }

    unsigned ParseFlags; // +0x18
};

// Opens the files a loader reads (state; vftable 0x143109430).
class FileOpenerBase : public State
{
public:
    // the store is the SDK build-config link check (a shipping lib defines the symbol; exe 0x143b16008)
    FileOpenerBase() : State(State_FileOpener) { GFx_Compile_with_SF_BUILD_DEBUG = 0; }

    virtual File*  OpenFile(const char* purl, int flags = FileConstants::Open_Read | FileConstants::Open_Buffered,
                            int mode = FileConstants::Mode_ReadWrite) = 0;          // +8
    virtual SInt64 GetFileModifyTime(const char* purl) = 0;                         // +0x10
    // OpenFile plus the error check; logs to plog and returns 0 on failure.
    virtual File*  OpenFileEx(const char* purl, Log* plog,
                              int flags = FileConstants::Open_Read | FileConstants::Open_Buffered,
                              int mode = FileConstants::Mode_ReadWrite) = 0;        // +0x18
};

// The default opener: plain system files (vftable 0x143109458).
class FileOpener : public FileOpenerBase
{
public:
    virtual File*  OpenFile(const char* purl, int flags = FileConstants::Open_Read | FileConstants::Open_Buffered,
                            int mode = FileConstants::Mode_ReadWrite);
    virtual SInt64 GetFileModifyTime(const char* purl);
    virtual File*  OpenFileEx(const char* purl, Log* plog,
                              int flags = FileConstants::Open_Read | FileConstants::Open_Buffered,
                              int mode = FileConstants::Mode_ReadWrite);
};

// Inflates compressed SWF data (state; vftable 0x143109490).
class ZlibSupportBase : public State
{
public:
    ZlibSupportBase() : State(State_ZlibSupport) {}

    virtual File* CreateZlibFile(File* in) = 0;                                  // +8
    virtual void  InflateWrapper(Stream* pin, void* buffer, int bufferBytes) = 0; // +0x10
};

// The zlib implementation linked into the player (vftable 0x1431094b0).
class ZlibSupport : public ZlibSupportBase
{
public:
    virtual File* CreateZlibFile(File* in);
    virtual void  InflateWrapper(Stream* pin, void* buffer, int bufferBytes);
};

// Texture packing options of the image packer states.
class ImagePackParamsBase : public State
{
public:
    // Size of the textures images are packed into (0x10 bytes).
    struct TextureConfig
    {
        int      TextureWidth;
        int      TextureHeight;
        unsigned SizeOptions;
        bool     SquareOnly;
    };

    void SetTextureConfig(const TextureConfig& config);

    // Slot 1 is not called by the recovered units; slot 2 starts packing the images of one binding.
    virtual void         Slot01() const = 0;
    virtual ImagePacker* Begin(ResourceId* pidGen, ImageCreator* pic, ImageCreateInfo* pici) const = 0;

protected:
    TextureConfig PackTextureConfig; // +0x18
};

// The public loader: a state bag over a LoaderImpl plus the resource library it keeps alive (0x20 bytes,
// vftable 0x1431843d8).
class Loader : public StateBag
{
public:
    enum LoadConstants
    {
        LoadWaitCompletion = 0x01,
        LoadWaitFrame1     = 0x02,
        LoadOrdered        = 0x10, // bind after loading instead of interleaved
        LoadOnThread       = 0x40, // CreateMovie runs on a loader thread: load threaded regardless of the task manager
        LoadImageFiles     = 0x10000,
        LoadDisableSWF     = 0x80000,
        LoadDisableImports = 0x100000,
        LoadDebugHeap      = 0x10000000,
        // (appended for sfr_gfx_07e) no load-time image creation; no error log when the file does not open
        LoadKeepBindData   = 0x80,
        LoadQuietOpen      = 0x200000
    };

    // What a loader is made with.
    struct LoaderConfig
    {
        unsigned             DefLoadFlags; // +0
        Ptr<FileOpenerBase>  pFileOpener;  // +8
        Ptr<ZlibSupportBase> pZLibSupport; // +0x10

        LoaderConfig(unsigned loadFlags = 0, const Ptr<FileOpenerBase>& pfileOpener = 0,
                     const Ptr<ZlibSupportBase>& pzlib = 0)
            : DefLoadFlags(loadFlags), pFileOpener(pfileOpener), pZLibSupport(pzlib)
        {
        }
    };

    Loader(const LoaderConfig& config);
    Loader(const Ptr<FileOpenerBase>& pfileOpener, const Ptr<ZlibSupportBase>& pzlib);
    Loader(const Loader& src);
    virtual ~Loader();

    virtual StateBag* GetStateBagImpl() const;
    // True if a loader for SWF/GFX tag tagType is installed.
    virtual bool      CheckTagLoader(int tagType) const;

    void         SetResourceLib(ResourceLib* plib);
    ResourceLib* GetResourceLib() const;
    bool         GetMovieInfo(const char* pfilename, MovieInfo* pinfo, bool getTagCount = false,
                              unsigned loadConstants = 0);
    MovieDef*    CreateMovie(const char* pfilename, unsigned loadConstants = 0, UPInt memoryArena = 0);
    void         UnpinAll();
    void         CancelLoading();

private:
    void InitLoader(const LoaderConfig& cfg);

    LoaderImpl*  pImpl;              // +8
    ResourceLib* pStrongResourceLib; // +0x10
    unsigned     DefLoadFlags;       // +0x18
};

// Turns movie relative URLs into file paths (state).
class URLBuilder : public State
{
public:
    enum FileUse
    {
        File_Regular,
        File_Import,
        File_ImageImport,
        File_LoadMovie,
        File_LoadImage,
        File_LoadXML,
        File_LoadCSS,
        File_Sound,
        // (appended for sfr_gfx_07f) loadVariables / loadBinary files use 4, the value named File_LoadImage above
        File_LoadVars = 4
    };

    // A file to open and what it is for (0x18 bytes).
    struct LocationInfo
    {
        FileUse Use;        // +0
        String  FileName;   // +8
        String  ParentPath; // +0x10

        LocationInfo(FileUse use, const char* pfilename) : Use(use), FileName(pfilename) {}
        LocationInfo(FileUse use, const String& filename, const String& path)
            : Use(use), FileName(filename), ParentPath(path) {}
    };

    // (appended, sfr19) a default builder made where none is set (vftable 0x14317fbe8, ??_G in sfr_as3_20)
    URLBuilder() : State(State_URLBuilder) {}

    virtual void BuildURL(String* ppath, const LocationInfo& loc);

    static void SF_STDCALL DefaultBuildURL(String* ppath, const LocationInfo& loc);
    static bool SF_STDCALL IsPathAbsolute(const char* putf8str);
    static bool SF_STDCALL ExtractFilePath(String* ppath);
};


class FontPackParams;

// Told about load progress: per bound frame and per tag read (state).
class ProgressHandler : public State
{
public:
    // Progress of one bound frame.
    struct Info
    {
        String   URL;          // +0
        UInt32   BytesLoaded;  // +8
        UInt32   TotalBytes;   // +0xc
        unsigned FrameLoading; // +0x10
        unsigned TotalFrames;  // +0x14

        Info(const String& url, UInt32 bytesLoaded, UInt32 totalBytes, unsigned frameLoading, unsigned totalFrames)
            : URL(url), BytesLoaded(bytesLoaded), TotalBytes(totalBytes), FrameLoading(frameLoading),
              TotalFrames(totalFrames)
        {
        }
    };
    // One tag read from the file.
    struct TagInfo
    {
        String FileURL;       // +0
        int    TagType;       // +8
        int    TagOffset;     // +0xc
        int    TagLength;     // +0x10
        int    TagDataOffset; // +0x14

        TagInfo(const String& url, int tagType, int tagOffset, int tagLength, int tagDataOffset)
            : FileURL(url), TagType(tagType), TagOffset(tagOffset), TagLength(tagLength), TagDataOffset(tagDataOffset)
        {
        }
    };

    virtual void ProgressUpdate(const Info& info) = 0;                            // +8
    virtual void LoadTagUpdate(const TagInfo& info, bool calledFromDefSprite) {} // +0x10
};

// States captured for one load (0xa0 bytes).
class LoadStates : public RefCountBase<LoadStates, Stat_Default_Mem>
{
public:
    Ptr<MovieDefBindStates>       pBindStates;          // +0x10
    Ptr<LogState>                 pLog;                 // +0x18
    Ptr<ParseControl>             pParseControl;        // +0x20
    Ptr<ProgressHandler>          pProgressHandler;     // +0x28
    Ptr<TaskManager>              pTaskManager;         // +0x30
    Ptr<ImageFileHandlerRegistry> pImageFileHandlerRegistry; // +0x38
    Ptr<ZlibSupportBase>          pZlibSupport;         // +0x40
    Ptr<VideoBase>                pVideoState;          // +0x48
    Ptr<AudioBase>                pAudioState;          // +0x50
    Ptr<ASSupport>                pAS2Support;          // +0x58
    Ptr<ASSupport>                pAS3Support;          // +0x60
    Ptr<ResourceWeakLib>          pWeakResourceLib;     // +0x68
    Ptr<LoaderImpl>               pLoaderImpl;          // +0x70
    String                        RelativePathForImports; // +0x78
    bool                          ThreadedLoading;      // +0x80
    Array<Ptr<MovieDefImpl> >     SubstituteFontMovieDefs; // +0x88

    LoadStates(LoaderImpl* ploader, StateBag* pstates = 0, MovieDefBindStates* pbindStates = 0);
    ~LoadStates();

    void SetRelativePathForDataDef(MovieDataDef* pdef);

    MovieDefBindStates* GetBindStates() const { return pBindStates; }
    // The URL of loc as the URLBuilder state (or the default rules) makes it.
    void          BuildURL(String* pdest, const URLBuilder::LocationInfo& loc) const;
    // The image creator that is part of the file key under loadConstants, if any.
    ImageCreator* GetLoadTimeImageCreator(unsigned loadConstants) const;
    // Opens pfilename through the file opener state; logs and returns 0 on failure.
    File*         OpenFile(const char* pfilename, unsigned loadConstants);

    ImageFileHandlerRegistry* GetImageFileHandlerRegistry() const { return pImageFileHandlerRegistry; }

    // The states of a file imported by this one: the bind states are copied, the rest shared (exe 0x1426382f0).
    LoadStates* CloneForImport() const;

    LogState*        GetLogState() const        { return pLog; }
    Log*             GetLog() const             { return pLog ? pLog->GetLog() : 0; }
    ProgressHandler* GetProgressHandler() const { return pProgressHandler; }
    const String&    GetRelativePath() const    { return RelativePathForImports; }
    FontPackParams*  GetFontPackParams() const  { return (FontPackParams*)pBindStates->pFontPackParams.GetPtr(); }
    bool             IsThreadedLoading() const  { return ThreadedLoading || pTaskManager; }

    // Hands ptask to the task manager; false when there is none (the caller runs it).
    bool SubmitBackgroundTask(LoaderTask* ptask);

    // (appended for sfr_gfx_07e) empty states, filled by CloneForImport (exe 0x142637290); the image creator of the
    // bind states (exe 0x142639340)
    LoadStates();
    ImageCreator* GetImageCreator() const;
};

// The state bag of a loader or movie: a hash of states by type, falling back to a delegate (0x58 bytes).
class StateBagImpl : public RefCountBase<StateBagImpl, Stat_Default_Mem>, public StateBag, public LogBase<StateBagImpl>
{
protected:
    Ptr<StateBagImpl> pDelegate; // +0x20
public:
    // (appended, sfr_gfx_01i) the states asked when this bag has none (MovieImpl::SetLevelMovie)
    void SetDelegate(StateBagImpl* pdelegate) { pDelegate = pdelegate; }
protected:

    struct StatePtr
    {
        Ptr<State> pState;

        StatePtr() {}
        StatePtr(State* pstate) : pState(pstate) {}
        StatePtr(const StatePtr& other) : pState(other.pState) {}

        bool operator==(State::StateType stype) const { return pState->GetStateType() == stype; }
        bool operator==(const StatePtr& other) const
        {
            return pState->GetStateType() == other.pState->GetStateType();
        }
    };

    struct StatePtrHashOp
    {
        UPInt operator()(const StatePtr& pstate) const { return (UPInt)pstate.pState->GetStateType(); }
        UPInt operator()(const State* pstate) const    { return (UPInt)pstate->GetStateType(); }
        UPInt operator()(State::StateType stype) const { return (UPInt)stype; }
    };

    typedef HashSet<StatePtr, StatePtrHashOp> StateHash;

    StateHash    States;    // +0x28
    mutable Lock StateLock; // +0x30

public:
    StateBagImpl(StateBagImpl* pdelegate) { pDelegate = pdelegate; }
    StateBagImpl* GetDelegate() const { return pDelegate; }
    // Inline: the exe has no out-of-line copy (it is folded into the deleting destructor 0x14256bb20).
    virtual ~StateBagImpl() {}

    virtual void   SetState(State::StateType state, State* pstate);
    virtual State* GetStateAddRef(State::StateType state) const;
    virtual void   GetStatesAddRef(State** pstates, const State::StateType* pstateTypes, unsigned count) const;

    // Replaces this bag's states with those of pother (the delegate is kept).
    void CopyStatesFrom(StateBagImpl* pother);

    Log* GetLog() const;
};

// One running load task, chained in LoaderImpl::LoadProcesses (0x18 bytes).
struct LoadProcessNode : public ListNode<LoadProcessNode>, public NewOverrideBase<Stat_Default_Mem>
{
    LoadProcessNode(LoaderTask* ptask) : pTask(ptask) {}
    LoaderTask* pTask; // +0x10
};

// Shared loader state behind Loader (0x70 bytes).
class LoaderImpl : public RefCountBase<LoaderImpl, Stat_Default_Mem>, public StateBag, public LogBase<LoaderImpl>
{
public:
    Ptr<StateBagImpl>     pStateBag;         // +0x20
    Ptr<ResourceWeakLib>  pWeakResourceLib;  // +0x28
    List<LoadProcessNode> LoadProcesses;     // +0x30
    Lock                  LoadProcessesLock; // +0x40
    bool                  DebugHeap;         // +0x68

    // One movie on the import chain, used to detect recursive imports.
    struct LoadStackItem
    {
        MovieDefImpl*  pDefImpl; // +0
        LoadStackItem* pNext;    // +8
    };

    LoaderImpl(ResourceLib* plib, bool debugHeap = false);
    LoaderImpl(LoaderImpl* psource);
    LoaderImpl(StateBag* pstates, ResourceLib* plib, bool debugHeap = false);
    ~LoaderImpl();

    virtual StateBag* GetStateBagImpl() const { return pStateBag; }

    MovieDef* CreateMovie(const char* pfilename, unsigned loadConstants, UPInt memoryArena = 0);
    bool      GetMovieInfo(const char* pfilename, MovieInfo* pinfo, bool getTagCount = false,
                           unsigned loadConstants = 0);

    static FileFormatType SF_STDCALL DetectFileFormat(File* pfile);
    static Render::ImageFileFormat FileFormat2RenderImageFile(FileFormatType format);

    // "img://" / "simg://" (bilinear) and "imgps://" / "simgps://" (point sampled) URLs name user images;
    // the "s" prefix asks for a synchronous load.
    static bool SF_STDCALL IsProtocolImage(const String& url, bool* pbilinear = 0, bool* psync = 0);

    // Decodes an image file with the registry's reader for its format; 0 (logged) on failure.
    static Render::ImageSource* SF_STDCALL LoadBuiltinImage(File* pfile, FileFormatType format,
                                                         Resource::ResourceUse use, LoadStates* pls, Log* plog,
                                                         MemoryHeap* pimageHeap);

    // The SWF (tags 0..0x5b) and GFX (tags 1000..1009) tag loader tables (exe data 0x143a2efe0, 0x143a2f2c0).
    typedef void (*LoaderFunction)(LoadProcess* p, const TagInfo& tagInfo);
    static bool GetTagLoader(unsigned tagType, LoaderFunction* plf);
    bool        CheckTagLoader(unsigned tagType) const
    {
        LoaderFunction lf;
        return GetTagLoader(tagType, &lf);
    }

    void SetWeakResourceLib(ResourceWeakLib* plib) { pWeakResourceLib = plib; }

    void RegisterLoadProcess(LoaderTask* ptask);
    void UnRegisterLoadProcess(LoaderTask* ptask);
    void CancelLoading();

    static MovieDefImpl* SF_STDCALL CreateMovie_LoadState(LoadStates* pls, const URLBuilder::LocationInfo& loc,
                                                          unsigned loadConstants, LoadStackItem* ploadStack = 0,
                                                          UPInt memoryArena = 0);
    static MovieDefImpl* SF_STDCALL CreateMovie_LoadState(LoadStates* pls, MovieDataDef* pmd, unsigned loadConstants,
                                                          UPInt memoryArena = 0);
    // Loads the movie in bytes (keyed under a made-up name, so never shared).
    static MovieDefImpl* SF_STDCALL CreateMovie_LoadState(LoadStates* pls, const ArrayPOD<UByte>& bytes,
                                                          unsigned loadConstants, LoadStackItem* ploadStack = 0,
                                                          UPInt memoryArena = 0);

    // Waits for the bind of pm to finish (or runs it here when loading is not threaded).
    static MovieDefImpl* SF_STDCALL BindMovieAndWait(MovieDefImpl* pm, MovieBindProcess* pbp, LoadStates* pls,
                                                     unsigned loadConstants, LoadStackItem* ploadStack = 0);

private:
    static MovieDefImpl* SF_STDCALL CreateMovieDefImpl(LoadStates* pls, MovieDataDef* pmd, unsigned loadConstants,
                                                       MovieBindProcess** ppbindProcess, bool checkCreate = false,
                                                       LoadStackItem* ploadStack = 0, UPInt memoryArena = 0);
};

// Task that keeps its loader informed while it runs (0x20 bytes, vftable 0x143188db0).
class LoaderTask : public Task
{
protected:
    Ptr<LoadStates> pLoadStates; // +0x18

public:
    LoaderTask(LoadStates* pls, TaskId id = Id_Unknown);
    ~LoaderTask();
};

extern LoaderImpl::LoaderFunction SWF_TagLoaderTable[];
extern LoaderImpl::LoaderFunction GFx_GFX_TagLoaderTable[];

inline bool LoaderImpl::GetTagLoader(unsigned tagType, LoaderFunction* plf)
{
    if (tagType < 0x5c)
        *plf = SF_EXE_DATA(SWF_TagLoaderTable)[tagType];          // exe data: see SF_EXE_DATA
    else if (tagType >= 1000 && tagType < 1010)
        *plf = SF_EXE_DATA(GFx_GFX_TagLoaderTable)[tagType - 1000];
    else
        *plf = 0;
    return *plf ? true : false;
}

inline Ptr<FileOpenerBase> StateBag::GetFileOpener() const
{
    return *(FileOpenerBase*)GetStateAddRef(State::State_FileOpener);
}
inline void StateBag::SetFileOpener(FileOpenerBase* ptr)   { SetState(State::State_FileOpener, ptr); }
inline void StateBag::SetParseControl(ParseControl* ptr)   { SetState(State::State_ParseControl, ptr); }
inline void StateBag::SetZlibSupport(ZlibSupportBase* ptr) { SetState(State::State_ZlibSupport, ptr); }

class ImagePacker;
struct TempBindData;

// The loader task that binds a MovieDefImpl frame by frame as its data loads (0x60 bytes, vftable 0x14318b698).
class MovieBindProcess : public LoaderTask
{
    typedef MovieDefImpl::BindTaskData BindTaskData;

    FrameBindData*             pFrameBindData;    // +0x20 last frame bound
    ResourceId                 GlyphTextureIdGen; // +0x28
    Ptr<ImagePacker>           pImagePacker;      // +0x30
    Ptr<BindTaskData>          pBindData;         // +0x38
    MovieDataDef*              pDataDef;          // +0x40
    bool                       Stripped;          // +0x48
    LoaderImpl::LoadStackItem* pLoadStack;        // +0x50
    TempBindData*              pTempBindData;     // +0x58

public:
    MovieBindProcess(LoadStates* pls, MovieDefImpl* pdefImpl, LoaderImpl::LoadStackItem* ploadStack = 0);
    ~MovieBindProcess();

    typedef MovieDefImpl::BindStateType BindStateType;

    // Binds the next loaded frame; BS_InProgress while frames remain.
    BindStateType BindNextFrame();

    void          SetBindState(unsigned newState);
    unsigned      GetBindState() const      { return pBindData->GetBindState(); }
    BindStateType GetBindStateType() const  { return pBindData->GetBindStateType(); }
    unsigned      GetBindStateFlags() const { return pBindData->GetBindStateFlags(); }

    FrameBindData* GetNextFrameBindData()
    {
        if (pFrameBindData)
            return pFrameBindData->pNextFrame;
        return pDataDef->pData->GetFirstFrameBindData();
    }

    void          FinishBinding();
    void          SetTempBindData(TempBindData* ptempdata) { pTempBindData = ptempdata; }
    TempBindData* GetTempBindData() const                  { return pTempBindData; }

    virtual void Execute()
    {
        while (BindNextFrame() == MovieDefImpl::BS_InProgress)
        {
        }
    }
    virtual void OnAbandon(bool started);

    // (appended for sfr_gfx_07e) the binding state the load process cancels
    BindTaskData* GetBindData() const { return pBindData; }
};

// (appended for the font manager, sfr_gfx_07g)
inline ResourceWeakLib* MovieDefImpl::GetWeakLib() const { return pLoaderImpl->pWeakResourceLib; }

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::LoadStates) == 0xa0, "LoadStates size");
static_assert(sizeof(Scaleform::GFx::LoaderImpl) == 0x70, "LoaderImpl size");
static_assert(sizeof(Scaleform::GFx::MovieBindProcess) == 0x60, "MovieBindProcess size");

#endif
