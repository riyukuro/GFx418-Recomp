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
#include "../render/render_imagefileformat.h"
#include "../kernel/sf_hash.h"
#include "../../kernel/sf_list.h"

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

// Load option bits of Loader::CreateMovie.
class Loader
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
        LoadDebugHeap      = 0x10000000
    };
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
        File_Sound
    };

    // A file to open and what it is for (0x18 bytes).
    struct LocationInfo
    {
        FileUse Use;        // +0
        String  FileName;   // +8
        String  ParentPath; // +0x10

        LocationInfo(FileUse use, const char* pfilename) : Use(use), FileName(pfilename) {}
    };
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

    // Hands ptask to the task manager; false when there is none (the caller runs it).
    bool SubmitBackgroundTask(LoaderTask* ptask);
};

// The state bag of a loader or movie: a hash of states by type, falling back to a delegate (0x58 bytes).
class StateBagImpl : public RefCountBase<StateBagImpl, Stat_Default_Mem>, public StateBag, public LogBase<StateBagImpl>
{
protected:
    Ptr<StateBagImpl> pDelegate; // +0x20

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

}} // namespace Scaleform::GFx

#endif
