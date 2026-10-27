// Recovered Scaleform 4.1.18 GFx: state bags, movie definitions and their resource bindings
// (only the parts used by recovered units so far; layouts from the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Bodies: MovieDataDef and its LoadTaskData, MovieDefImpl and its BindTaskData, MovieBindProcess (sfr_gfx_04). Out-of-line members not recovered yet bind to the exe:
//   ResourceBinding::GetResourceData_Locked 0x142636720, LoadTaskData::GetSoundStream 0x1425d1460.
#ifndef MS2_SF_GFX_MOVIEDEF_H
#define MS2_SF_GFX_MOVIEDEF_H

#include "gfx_characterdef.h"
#include "gfx_resource.h"
#include "gfx_state.h"
#include "gfx_stream.h"
#include "../kernel/sf_hash.h"
#include "../kernel/sf_lock.h"
#include "../kernel/sf_stringhash.h"
#include "../render/render_fontprovider.h"
#include "../render/render_meshprovider.h"

namespace Scaleform {
class Log;
class File;
namespace Render { template<class T> class Rect; class ThreadCommandQueue; }
namespace GFx {

class StateBagImpl;
class LoaderImpl;
class ImageCreator;
class FileOpener;
class TextClipboard;
class TextKeyMap;
class MovieDefImpl;
class ResourceBinding;
class FileOpenerBase;
class ParseControl;
class LogState;
class ZlibSupportBase;
class Movie;
class MemoryContext;
struct MemoryParams;
namespace Video { class VideoBase; }
class ActionControl;
struct ExporterInfo;
class FontResource;
class FontLib;

// Something that hands out states by type; MovieDef, Loader and the movie instances are state bags.
class StateBag : public FileTypeConstants
{
public:
    virtual StateBag* GetStateBagImpl() const;
    virtual ~StateBag() {}
    virtual void      SetState(State::StateType state, State* pstate);
    virtual State*    GetStateAddRef(State::StateType state) const;
    // Fills pstates[i] with an AddRef'ed state of type pstateTypes[i] (or null) under one lock.
    virtual void      GetStatesAddRef(State** pstates, const State::StateType* pstateTypes, unsigned count) const;

    // Typed setters (exe: SetLog 0x1425b39d0). The inline ones need the state class complete: they are defined
    // after it (ImageCreator, TextClipboard, TextKeyMap: in the unit that defines the loader constructors).
    void        SetLog(Log* plog);
    inline void SetImageCreator(ImageCreator* ptr);
    inline void SetTextClipboard(TextClipboard* ptr);
    inline void SetTextKeyMap(TextKeyMap* ptr);

    // The log state (exe 0x1425b38b0).
    Ptr<Log> GetLog() const;
    // exe 0x1425b3910.
    Ptr<LogState> GetLogState() const;
    // Opens pfilename through the file opener state, logging failures to the bag's log / plog.
    File*    OpenFile(const char* pfilename);
    File*    OpenFileEx(const char* pfilename, Log* plog);

    // Defined in gfx_loaderimpl.h after the state classes.
    inline Ptr<FileOpenerBase> GetFileOpener() const;
    inline void                SetFileOpener(FileOpenerBase* ptr);
    inline void                SetParseControl(ParseControl* ptr);
    inline void                SetZlibSupport(ZlibSupportBase* ptr);
    // Defined in gfx_fontlib.h.
    inline Ptr<FontLib>        GetFontLib() const;
    // Defined in video/video_statebag.h.
    inline Ptr<Video::VideoBase> GetVideo() const;
    // (appended for the player, sfr_gfx_01i)
    Ptr<MultitouchInterface> GetMultitouchInterface() const
    {
        return *(MultitouchInterface*)GetStateAddRef(State::State_MultitouchInterface);
    }
    Ptr<TestStream> GetTestStream() const
    {
        return *(TestStream*)GetStateAddRef(State::State_TestStream);
    }
    // Defined in gfx_textclipboard.h (gfxmovieeventhandler keeps it as a COMDAT).
    inline Ptr<TextClipboard> GetTextClipboard() const;
};

// Loaded movie as seen by the user: Resource at +0, StateBag at +0x18. The exe has no vftable of its own for it
// (MovieDefImpl's destructor goes straight to the StateBag / Resource ones), hence novtable.
class __declspec(novtable) MovieDef : public Resource, public StateBag
{
public:
    // Primary vftable after the Resource slots (MovieDefImpl: 0x14318b588).
    virtual unsigned            GetVersion() const      = 0; // +0x20
    virtual unsigned            GetLoadingFrame() const = 0; // +0x28
    virtual float               GetWidth() const        = 0; // +0x30
    virtual float               GetHeight() const       = 0; // +0x38
    virtual unsigned            GetFrameCount() const   = 0; // +0x40
    virtual float               GetFrameRate() const    = 0; // +0x48
    virtual Render::Rect<float> GetFrameRect() const    = 0; // +0x50
    virtual unsigned            GetSWFFlags() const     = 0; // +0x58
    virtual const char*         GetFileURL() const      = 0; // +0x60

    virtual void                WaitForLoadFinish(bool cancel = false) const               = 0; // +0x68
    virtual void                WaitForFrame(unsigned frame) const                         = 0; // +0x70
    virtual unsigned            GetFileAttributes() const                                  = 0; // +0x78
    virtual unsigned            GetMetadata(char* pbuff, unsigned buffSize) const          = 0; // +0x80
    virtual MemoryHeap*         GetLoadDataHeap() const                                    = 0; // +0x88
    virtual MemoryHeap*         GetBindDataHeap() const                                    = 0; // +0x90
    virtual MemoryHeap*         GetImageHeap() const                                       = 0; // +0x98
    virtual Resource*           GetMovieDataResource() const                               = 0; // +0xa0
    virtual const ExporterInfo* GetExporterInfo() const                                    = 0; // +0xa8
    virtual MemoryContext*      CreateMemoryContext(const char* heapName, const MemoryParams& memParams,
                                                    bool debugHeap)                        = 0; // +0xb0
    // MSVC places the overloads in reverse: the MemoryContext one at +0xb8, this one at +0xc0.
    virtual Movie*              CreateInstance(const MemoryParams& memParams, bool initFirstFrame,
                                               ActionControl* actionControl, Render::ThreadCommandQueue* queue) = 0;
    virtual Movie*              CreateInstance(MemoryContext* memContext, bool initFirstFrame,
                                               ActionControl* actionControl, Render::ThreadCommandQueue* queue) = 0;

    // Called back for each movie this one imports from.
    struct ImportVisitor
    {
        virtual ~ImportVisitor() {}
        virtual void Visit(MovieDef* pparentDef, MovieDef* pimportDef, const char* pimportedMovieFilename) = 0;
    };
    // Called back for each resource of the kinds a VisitResources mask selects.
    struct ResourceVisitor : public FileTypeConstants
    {
        virtual ~ResourceVisitor() {}
        virtual void Visit(MovieDef* pmovieDef, Resource* presource, ResourceId rid, const char* pexportName) = 0;
    };
    enum VisitResourceMask
    {
        ResVisit_NestedMovies   = 0x8000,
        ResVisit_Fonts          = 0x01,
        ResVisit_Bitmaps        = 0x02,
        ResVisit_GradientImages = 0x04,
        ResVisit_EditTextFields = 0x08,
        ResVisit_Sounds         = 0x10,
        ResVisit_Sprite         = 0x20,
        ResVisit_AllLocalImages = ResVisit_Bitmaps | ResVisit_GradientImages,
        ResVisit_AllImages      = ResVisit_Bitmaps | ResVisit_GradientImages | ResVisit_NestedMovies
    };

    virtual void      VisitImportedMovies(ImportVisitor* visitor)                                      = 0; // +0xc8
    virtual void      VisitResources(ResourceVisitor* pvisitor, unsigned visitMask = ResVisit_AllImages) = 0; // +0xd0
    virtual Resource* GetResource(const char* pexportName) const                                       = 0; // +0xd8
};

// One font a movie defines, chained in load order.
struct FontDataUseNode
{
    ResourceId                 Id;         // +0
    Ptr<Render::Font>          pFontData;  // +8
    unsigned                   BindIndex;  // +0x10
    FontDataUseNode* volatile  pNext;      // +0x18

    // (appended for sfr_gfx_07e) the font and the binding index are set by LoadProcess::AddFontDataResource
    FontDataUseNode() : BindIndex(0), pNext(0) {}
};

class SoundStreamDef;
class ImageResource;
class LoadProcess;
class PathAllocator;
class MovieBindProcess;
class ASSupport;
using StatBag = ::Scaleform::StatBag;
struct MovieInfo;

// What the gfxexport tool recorded about a converted file (0x20 bytes).
struct ExporterInfo
{
    FileTypeConstants::FileFormatType Format;      // +0 format of the extracted images
    const char*                       pPrefix;     // +8 prefix of the extracted image files
    const char*                       pSWFName;    // +0x10 the SWF the file was made from
    UInt16                            Version;     // +0x18 version of the tool
    unsigned                          ExportFlags; // +0x1c

    enum ExportFlagConstants
    {
        EXF_GlyphTexturesExported   = 0x01,
        EXF_GradientTexturesExported = 0x02,
        EXF_GlyphsStripped          = 0x10
    };
};

// The exporter info of a file with the strings it points to (0x48 bytes; SetData / ReadExporterInfoTag are
// GFx_LoaderImpl's, the destructor GFx_LoadProcess').
class ExporterInfoImpl
{
    ExporterInfo SI;      // +0
    String       Prefix;  // +0x20
    String       SWFName; // +0x28

public:
    Array<UInt32> CodeOffsets; // +0x30

    ExporterInfoImpl()
    {
        SI.Format      = FileTypeConstants::File_Unopened;
        SI.pSWFName    = 0;
        SI.pPrefix     = 0;
        SI.ExportFlags = 0;
        SI.Version     = 0;
    }
    ~ExporterInfoImpl();

    void SetData(UInt16 version, FileTypeConstants::FileFormatType format, const char* pname, const char* pprefix,
                 unsigned flags = 0, const Array<UInt32>* codeOffsets = 0);

    // Null until the file has an exporter info tag.
    const ExporterInfo* GetExporterInfo() const
    {
        return (SI.Format == FileTypeConstants::File_Unopened) ? 0 : &SI;
    }

    // The info even when it was never set.
    const ExporterInfo& GetData() const { return SI; }

    // Reads an ExporterInfo tag (1000) into this.
    void ReadExporterInfoTag(Stream* pin, TagType tagType);
};

// The SWF / GFX header of a file (0x80 bytes: the frame rectangle is 16-byte aligned).
struct MovieHeaderData
{
    UInt32                       FileLength; // +0
    int                          Version;    // +4
    __declspec(align(16)) RectF  FrameRect;  // +0x10 in twips
    float                        FPS;        // +0x20
    unsigned                     FrameCount; // +0x24
    unsigned                     SWFFlags;   // +0x28
    ExporterInfoImpl             mExporterInfo; // +0x30

    // Image and empty movie data rely on FrameCount starting at 1.
    MovieHeaderData() : FileLength(0), Version(-1), FPS(1.0f), SWFFlags(0) { FrameCount = 1; }

    void GetMovieInfo(MovieInfo* pinfo) const;
};

// The symbols one ImportAssets tag takes from another file; chained in load order.
class ImportData
{
public:
    struct Symbol
    {
        String   SymbolName;
        int      CharacterId;
        unsigned BindIndex;
    };

    ArrayLH<Symbol>        Imports;     // +0
    StringLH               SourceUrl;   // +0x18
    unsigned               Frame;       // +0x20
    unsigned               ImportIndex; // +0x24 index of the import in the file (MovieDefImpl import table)
    AtomicPtr<ImportData>  pNext;       // +0x28

    ImportData() : Frame(0), ImportIndex(0) {}
    ImportData(const char* source, unsigned frame) : SourceUrl(source), Frame(frame), ImportIndex(0) {}

    void AddSymbol(const char* psymbolName, int characterId, unsigned bindIndex)
    {
        Symbol s;
        s.SymbolName  = psymbolName;
        s.CharacterId = characterId;
        s.BindIndex   = bindIndex;
        Imports.PushBack(s);
    }
};

// Data a resource is created from at bind time, at its binding index; chained in load order.
struct ResourceDataNode
{
    ResourceData                Data;      // +0
    unsigned                    BindIndex; // +0x10
    AtomicPtr<ResourceDataNode> pNext;     // +0x18

    ResourceDataNode() {}
};

// What a frame adds to the binding: counted runs of the import / font / resource data lists (0x38 bytes).
struct FrameBindData
{
    unsigned                 Frame;         // +0
    unsigned                 BytesLoaded;   // +4
    unsigned                 FontCount;     // +8
    unsigned                 ImportCount;   // +0xc
    unsigned                 ResourceCount; // +0x10
    ImportData*              pImportData;   // +0x18
    FontDataUseNode*         pFontData;     // +0x20
    ResourceDataNode*        pResourceData; // +0x28
    AtomicPtr<FrameBindData> pNextFrame;    // +0x30 set under the frame update mutex

    FrameBindData()
        : Frame(0), BytesLoaded(0), FontCount(0), ImportCount(0), ResourceCount(0), pImportData(0), pFontData(0),
          pResourceData(0)
    {
    }
};

// Heap and garbage collector settings of a new movie instance (MovieDef::CreateInstance / CreateMemoryContext;
// 0x50 bytes, AS3Support::CreateMemoryContext reads them).
struct MemoryParams
{
    HeapDesc    Desc;                       // +0x00 the movie heap; Limit is the user level limit
    float       HeapLimitMultiplier;        // +0x40
    unsigned    MaxCollectionRoots;         // +0x44
    unsigned    FramesBetweenCollections;   // +0x48
    unsigned    InitialDynamicLimit;        // +0x4c
};

// Allocation stat of the movie data internals.
enum { StatMD_ASBinaryData_Mem = 0x108 }; // action / ABC byte code (AS2 has its own copy in as2_action.h)
enum { StatMD_Other_Mem = 0x109 };

// Bump allocator of the tags and frame arrays of a loading movie; the memory lives as long as the movie data
// (OverflowAlloc 0x1425d1c00 starts a new block).
class DataAllocator
{
    struct Block
    {
        Block* pNext;
    };

    enum AllocConstants
    {
        BlockSize = 8192 - 8 // bytes of one block allocation, the Block header included
    };

    UByte*      pCurrent;     // +0
    UPInt       BytesLeft;    // +8
    Block*      pAllocations; // +0x10
    MemoryHeap* pHeap;        // +0x18

    void* OverflowAlloc(UPInt bytes);

public:
    DataAllocator(MemoryHeap* pheap) : pCurrent(0), BytesLeft(0), pAllocations(0), pHeap(pheap) {}
    ~DataAllocator();

    void* Alloc(UPInt bytes)
    {
        bytes = (bytes + (sizeof(void*) - 1)) & ~(sizeof(void*) - 1);
        if (bytes <= BytesLeft)
        {
            void* pmem = pCurrent;
            pCurrent += bytes;
            BytesLeft -= bytes;
            return pmem;
        }
        return OverflowAlloc(bytes);
    }

    // A chunk outside the pool, freed with it.
    void* AllocIndividual(UPInt bytes);
};

// Mutex + condition the loading thread signals frame progress through (0x48 bytes from the global heap, vftable
// 0x14318b480). Kept separate so that the waiting side can outlive every other reference to the loaded memory.
class LoadUpdateSync : public RefCountBase<LoadUpdateSync, StatMD_Other_Mem>
{
    Mutex         mMutex;       // +0x10
    WaitCondition WC;           // +0x38
    bool          LoadFinished; // +0x40

public:
    LoadUpdateSync() : LoadFinished(false) {}

    Mutex& GetMutex()      { return mMutex; }
    void   UpdateNotify()  { WC.NotifyAll(); }
    void   WaitForNotify() { WC.Wait(&mMutex); }

    void NotifyLoadFinished()
    {
        Mutex::Locker l(&mMutex);
        LoadFinished = true;
        WC.NotifyAll();
    }

    bool IsLoadFinished() const { return LoadFinished; }

    void WaitForLoadFinished()
    {
        Mutex::Locker lock(&mMutex);
        while (!IsLoadFinished())
            WaitForNotify();
    }
};

// Owning pointer with an ownership flag.
template<class T>
class AutoPtr
{
    T*   pObject;
    bool Owner;

public:
    AutoPtr(T* p = 0, bool owner = true) : pObject(p), Owner(owner) {}
    ~AutoPtr() { Reset(); }

    void Reset(T* p = 0, bool owner = true)
    {
        if (p != pObject)
        {
            if (Owner)
                delete pObject;
            pObject = p;
        }
        Owner = owner;
    }
    AutoPtr& operator=(T* p)
    {
        Reset(p);
        return *this;
    }

    T*   operator->() const { return pObject; }
    T&   operator*() const  { return *pObject; }
    T*   GetPtr() const     { return pObject; }
    operator bool() const   { return pObject != 0; }
};

// Parsed SWF data shared by every binding of the same file (vftable 0x14318b4b8, ResourceReport 0x14318b558).
class MovieDataDef : public TimelineDef, public ResourceReport
{
public:
    enum MovieDataType
    {
        MT_Empty,
        MT_Flash,
        MT_Image
    };

    // Lists the LoadProcess appends to and the bind process reads; the nodes live in the tag memory.
    struct DefBindingData
    {
        AtomicPtr<FrameBindData>    pFrameData;         // +0 written under the frame update mutex
        FrameBindData*              pFrameDataLast;     // +8
        AtomicPtr<ImportData>       pImports;           // +0x10
        ImportData*                 pImportsLast;       // +0x18
        AtomicPtr<FontDataUseNode>  pFonts;             // +0x20
        FontDataUseNode*            pFontsLast;         // +0x28
        AtomicPtr<ResourceDataNode> pResourceNodes;     // +0x30 kept for the destructors
        ResourceDataNode*           pResourceNodesLast; // +0x38

        DefBindingData() : pFrameDataLast(0), pImportsLast(0), pFontsLast(0), pResourceNodesLast(0) {}
        ~DefBindingData();
    };

    enum MovieLoadState
    {
        LS_Uninitialized,
        LS_LoadingFrames,
        LS_LoadFinished,
        LS_LoadCanceled,
        LS_LoadError
    };

    // Base of LoadTaskData that owns the tag memory, so that it is released after every tag (vftable 0x14318b490).
    class LoadTaskDataBase : public RefCountBase<LoadTaskDataBase, StatMD_Other_Mem>
    {
    protected:
        DataAllocator  TagMemAllocator; // +0x10
        PathAllocator* pPathAllocator;  // +0x30 shape path storage

        LoadTaskDataBase(MemoryHeap* pheap) : TagMemAllocator(pheap), pPathAllocator(0) {}
    };

    typedef HashUncachedLH<ResourceId, ResourceHandle, ResourceId::HashOp> ResourceHash;

    struct FrameLabelInfo
    {
        StringDH Name;   // +0
        UInt32   Number; // +0x10

        FrameLabelInfo(MemoryHeap* heap, const String& name, UInt32 num) : Name(heap, name), Number(num) {}
    };
    struct SceneInfo
    {
        StringDH                Name;      // +0
        UInt32                  Offset;    // +0x10
        UInt32                  NumFrames; // +0x14
        ArrayDH<FrameLabelInfo> Labels;    // +0x18

        SceneInfo(MemoryHeap* heap, const String& n, UInt32 off)
            : Name(heap, n), Offset(off), NumFrames(0), Labels(heap)
        {
        }
        void AddFrameLabel(const String& n, UInt32 num) { Labels.PushBack(FrameLabelInfo(Name.GetHeap(), n, num)); }
    };

    // Load-time data (frames, resources, exports): AddRef'ed apart from the MovieDataDef so that the loading thread
    // can see the definition die and cancel (0x220 bytes, vftable 0x14318b498).
    class LoadTaskData : public LoadTaskDataBase
    {
        friend class MovieDataDef;
        friend class LoadProcess;
        friend class MovieDefImpl;
        friend class MovieBindProcess;

    public:
        LoadTaskData(MovieDataDef* pdataDef, const char* purl, MemoryHeap* pheap);
        ~LoadTaskData();

        // The MovieDataDef is going away: cancels a load in progress.
        void OnMovieDataDefRelease();

        void InitEmptyMovieDef();
        bool InitImageFileMovieDef(unsigned fileLength, ImageResource* pimageResource, ImageCreator* imgCreator,
                                   Log* plog, bool bilinear = 1);

        MemoryHeap* GetHeap() const { return pHeap; }
        // Heap of the image data; created on first use.
        MemoryHeap* GetImageHeap();
        PathAllocator* GetPathAllocator() { return pPathAllocator; }

        const char*         GetFileURL() const      { return FileURL.ToCStr(); }
        unsigned            GetTotalFrames() const  { return Header.FrameCount; }
        unsigned            GetVersion() const      { return Header.Version; }
        const ExporterInfo* GetExporterInfo() const { return Header.mExporterInfo.GetExporterInfo(); }
        LoadUpdateSync*     GetFrameUpdateSync() const { return pFrameUpdate; }

        UInt32   GetTagCount() const     { return TagCount; }
        unsigned GetLoadingFrame() const { return LoadingFrame; }
        const MovieHeaderData* GetHeaderData() const { return &Header; }

        void BeginSWFLoading(const MovieHeaderData& header);
        void Read(LoadProcess* plp, MovieBindProcess* pbp = 0);
        // Publishes the frame's bind data and advances LoadingFrame; false on a load error.
        bool FinishLoadingFrame(LoadProcess* plp, bool finished = 0);
        void UpdateLoadState(unsigned loadingFrame, MovieLoadState loadState);
        void NotifyFrameUpdated();
        void WaitForLoadFinish();
        void WaitForFrame(unsigned frame);

        unsigned GetMetadata(char* pbuff, unsigned buffSize) const;
        void     SetMetadata(UByte* pdata, unsigned size);
        void     SetFileAttributes(unsigned attrs) { FileAttributes = attrs; }
        unsigned GetFileAttributes() const         { return FileAttributes; }

        void* AllocTagMemory(UPInt bytes) { return TagMemAllocator.Alloc(bytes); }
        template<class T>
        T* AllocMovieDefClass() { return new (AllocTagMemory(sizeof(T))) T; }

        ResourceId GetNextGradientId() { return GradientIdGenerator.GenerateNextId(); }

        // A handle with a new binding index, for data bound later.
        ResourceHandle AddNewResourceHandle(ResourceId rid);
        void           AddResource(ResourceId rid, Resource* pres);
        void           AddCharacter(ResourceId rid, CharacterDef* c)
        {
            c->SetId(rid);
            AddResource(rid, c);
        }
        void ExportResource(const String& symbol, ResourceId rid, const ResourceHandle& hres);
        bool GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const;
        Render::Font* GetFontData(ResourceId rid);

        FrameBindData*   GetFirstFrameBindData() const { return BindData.pFrameData; }
        FontDataUseNode* GetFirstFont() const          { return BindData.pFonts; }
        ImportData*      GetFirstImport() const        { return BindData.pImports; }

        // Labels the frame being loaded.
        virtual void AddFrameName(const String& name, LogState* plog);
        virtual void SetLoadingPlaylistFrame(const Frame& frame, LogState* plog);
        virtual void SetLoadingInitActionFrame(const Frame& frame, LogState* plog);

        bool           GetLabeledFrame(const char* label, unsigned* frameNumber, bool translateNumbers = 1) const;
        const String*  GetFrameLabel(unsigned frameNumber, unsigned* exactFrameNumberForLabel = 0) const;
        Array<String>* GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const;

        void             AddScene(const String& name, unsigned off);
        bool             HasScenes() const { return Scenes; }
        const SceneInfo* GetScene(UPInt index) const;
        const SceneInfo* GetScenes(UPInt* count) const;

        const Frame GetPlaylist(int frameNumber) const;
        bool        GetInitActions(Frame* pframe, int frameNumber) const;
        unsigned    GetInitActionListSize() const;
        bool        HasInitActions() const { return InitActionsCnt > 0; }

        // The streaming sound of the main timeline (exe: GetSoundStream folded with another field getter).
        SoundStreamDef* GetSoundStream() const;
        void            SetSoundStream(SoundStreamDef* psoundStream);

        void   SetSwdHandle(UInt32 swdHandle) { SwdHandle = swdHandle; }
        UInt32 GetSwdHandle() const           { return SwdHandle; }

        // Locks Resources / Exports / InvExports while the file is still loading.
        struct ResourceLocker
        {
            const LoadTaskData* pLoadData;

            ResourceLocker(const LoadTaskData* ploadData)
            {
                pLoadData = 0;
                if (ploadData->LoadState < LS_LoadFinished)
                {
                    pLoadData = ploadData;
                    pLoadData->ResourceLock.DoLock();
                }
            }
            ~ResourceLocker()
            {
                if (pLoadData)
                    pLoadData->ResourceLock.Unlock();
            }
        };

        void SetExtMovieDef(MovieDef* m) { pExtMovieDef = m; }

    private:
        MemoryHeap*                pHeap;          // +0x38 heap of this and of the MovieDataDef
        Ptr<MemoryHeap>            pImageHeap;     // +0x40
        StringLH                   FileURL;        // +0x48
        MovieHeaderData            Header;         // +0x50
        unsigned                   FileAttributes; // +0xd0 SWF FileAttributes tag flags
        UByte*                     pMetadata;      // +0xd8
        unsigned                   MetadataSize;   // +0xe0
        MovieLoadState             LoadState;      // +0xe4
        unsigned                   LoadingFrame;   // +0xe8 frame being loaded
        volatile bool              LoadingCanceled; // +0xec
        unsigned                   TagCount;       // +0xf0
        Ptr<LoadUpdateSync>        pFrameUpdate;   // +0xf8
        DefBindingData             BindData;       // +0x100
        unsigned                   ResIndexCounter; // +0x140
        mutable Lock               ResourceLock;   // +0x148 Resources, Exports, InvExports (while loading)
        Ptr<MovieDef>              pExtMovieDef;   // +0x170 owner of resources taken from another movie
        ResourceHash               Resources;      // +0x178
        StringHashLH<ResourceHandle>                             Exports;    // +0x180
        HashLH<ResourceId, StringLH, FixedSizeHash<ResourceId> > InvExports; // +0x188
        mutable Lock               PlaylistLock;   // +0x190 Playlist, InitActionList, NamedFrames (while loading)
        ArrayLH<Frame>             Playlist;       // +0x1b8
        ArrayLH<Frame>             InitActionList; // +0x1d0
        int                        InitActionsCnt; // +0x1e8
        StringHashLH<unsigned>     NamedFrames;    // +0x1f0 0-based frame numbers
        ResourceId                 GradientIdGenerator; // +0x1f8
        SoundStreamDef*            pSoundStream;   // +0x200
        UInt32                     SwdHandle;      // +0x208
        AutoPtr<ArrayLH<SceneInfo> > Scenes;       // +0x210
    };

    MovieDataDef(const ResourceKey& creationKey, MovieDataType mtype, const char* purl, MemoryHeap* pargHeap = 0,
                 bool debugHeap = false, UPInt memoryArena = 0);
    ~MovieDataDef();

    virtual CharacterDefType GetType() const { return MovieData; }

    // Library key of the data of file purl (exe 0x1425ceaa0); 4.1.18 keys on one more binding state than later SDKs.
    static ResourceKey SF_STDCALL CreateMovieFileKey(const char* purl, SInt64 modifyTime, FileOpener* pfileOpener,
                                                     ImageCreator* pimageCreator, State* pbindState23);

    MemoryHeap* GetHeap() const { return pData->GetHeap(); }
    MemoryHeap* GetImageHeap()  { return pData->GetImageHeap(); }

    void InitEmptyMovieDef() { pData->InitEmptyMovieDef(); }
    bool InitImageFileMovieDef(unsigned fileLength, ImageResource* pimageResource, ImageCreator* imgCreator,
                               Log* plog, bool bilinear = 1)
    {
        return pData->InitImageFileMovieDef(fileLength, pimageResource, imgCreator, plog, bilinear);
    }

    void WaitForLoadFinish(bool cancel = false) const
    {
        if (cancel)
            pData->OnMovieDataDefRelease();
        pData->WaitForLoadFinish();
    }
    void WaitForFrame(unsigned frame) const { pData->WaitForFrame(frame); }

    float        GetFrameRate() const        { return pData->Header.FPS; }
    const RectF& GetFrameRectInTwips() const { return pData->Header.FrameRect; }
    virtual unsigned GetVersion() const      { return pData->GetVersion(); }
    virtual unsigned GetLoadingFrame() const { return pData->LoadingFrame; }
    virtual unsigned GetSWFFlags() const     { return pData->Header.SWFFlags; }

    MovieLoadState      GetLoadState() const    { return pData->LoadState; }
    UInt32              GetFileBytes() const    { return pData->Header.FileLength; }
    unsigned            GetTagCount() const     { return pData->TagCount; }
    const char*         GetFileURL() const      { return pData->GetFileURL(); }
    virtual unsigned    GetFrameCount() const   { return pData->Header.FrameCount; }
    const ExporterInfo* GetExporterInfo() const { return pData->GetExporterInfo(); }

    Ptr<ASSupport> GetASSupport() const;
    unsigned       GetFileAttributes() const { return pData->FileAttributes; }
    unsigned       GetMetadata(char* pbuff, unsigned buffSize) const { return pData->GetMetadata(pbuff, buffSize); }

    virtual bool GetLabeledFrame(const char* label, unsigned* frameNumber, bool translateNumbers = 1) const
    {
        return pData->GetLabeledFrame(label, frameNumber, translateNumbers);
    }
    virtual const String* GetFrameLabel(unsigned frameNumber, unsigned* exactFrameNumberForLabel = 0) const
    {
        return pData->GetFrameLabel(frameNumber, exactFrameNumberForLabel);
    }
    virtual Array<String>* GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const
    {
        return pData->GetFrameLabels(frameNumber, destArr);
    }

    const SceneInfo* GetScenes(UPInt* count) const { return pData->GetScenes(count); }

    bool GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const
    {
        return pData->GetResourceHandle(phandle, rid);
    }

    FontDataUseNode* GetFirstFont() const   { return pData->GetFirstFont(); }
    ImportData*      GetFirstImport() const { return pData->GetFirstImport(); }

    // Label lookup / frame number parsing shared with the sprites.
    static bool          TranslateFrameString(const StringHashLH<unsigned>& namedFrames, const char* label,
                                              unsigned* frameNumber, bool translateNumbers);
    static const String* TranslateNumberToFrameString(const StringHashLH<unsigned>& namedFrames,
                                                      unsigned frameNumber, unsigned* exactFrameNumberForLabel = 0);

    virtual const Frame GetPlaylist(int frame) const { return pData->GetPlaylist(frame); }
    unsigned            GetInitActionListSize() const { return pData->GetInitActionListSize(); }
    bool                HasInitActions() const        { return pData->HasInitActions(); }
    virtual bool        GetInitActions(Frame* pframe, int frame) const { return pData->GetInitActions(pframe, frame); }

    virtual SoundStreamDef* GetSoundStream() const           { return pData->GetSoundStream(); }
    virtual void            SetSoundStream(SoundStreamDef* pdef) { pData->SetSoundStream(pdef); }

    virtual ResourceKey     GetKey()                    { return mResourceKey; }
    virtual unsigned        GetResourceTypeCode() const { return MakeTypeCode(RT_MovieDataDef); }
    virtual ResourceReport* GetResourceReport()         { return this; }

    virtual String      GetResourceName() const;
    virtual MemoryHeap* GetResourceHeap() const { return GetHeap(); }
    virtual void        GetStats(StatBag*, bool = true) {}

    ResourceKey       mResourceKey; // +0x28
    MovieDataType     MovieType;    // +0x38
    Ptr<LoadTaskData> pData;        // +0x40
};

// Resource bound at one index of a movie binding.
struct ResourceBindData
{
    Ptr<Resource>    pResource;
    ResourceBinding* pBinding;

    ResourceBindData() : pBinding(0) {}
    ResourceBindData& operator=(const ResourceBindData& src)
    {
        pResource = src.pResource;
        pBinding  = src.pBinding;
        return *this;
    }
};

// Index -> resource table of a MovieDefImpl. Once Frozen it is read without the lock (0x50 bytes).
class ResourceBinding
{
    MemoryHeap*                pHeap;          // +0
    volatile unsigned          ResourceCount;  // +8
    ResourceBindData* volatile pResources;     // +0x10
    mutable Lock               ResourceLock;   // +0x18
    volatile bool              Frozen;         // +0x40
    MovieDefImpl*              pOwnerDefImpl;  // +0x48 not AddRef'ed; cleared when the MovieDefImpl dies

public:
    ResourceBinding(MemoryHeap* pheap); // exe 0x142636600
    ~ResourceBinding();                 // exe 0x142636630

    // Releases every bound resource (exe 0x1426366b0).
    void Destroy();

    void GetResourceData_Locked(ResourceBindData* pdata, unsigned index) const;

    void GetResourceData(ResourceBindData* pdata, unsigned index) const
    {
        if (Frozen && (index < ResourceCount))
            *pdata = pResources[index];
        else
            GetResourceData_Locked(pdata, index);
    }

    void SetOwnerDefImpl(MovieDefImpl* powner)
    {
        Lock::Locker lock(&ResourceLock);
        pOwnerDefImpl = powner;
    }
    MovieDefImpl* GetOwnerDefImpl() const { return pOwnerDefImpl; }

    // Binds index to rdata, growing the table (exe 0x142636820).
    void SetBindData(unsigned index, const ResourceBindData& rdata);
    // No more bindings: readers stop taking the lock.
    void Freeze() { Frozen = true; }

    // (appended for the static text, sfr_gfx_05d) the resource and binding a definition's reference resolves to
    template<class C>
    ResourceBindData GetResourceData(const ResourcePtr<C>& ptr)
    {
        ResourceBindData rbd;
        if (ptr.IsIndex())
        {
            GetResourceData(&rbd, ptr.GetBindIndex());
        }
        else
        {
            rbd.pBinding  = this;
            rbd.pResource = ptr.GetResourcePtr();
        }
        return rbd;
    }
};

inline Resource* ResourceHandle::GetResource(ResourceBinding* pbinding) const
{
    if (IsIndex())
    {
        ResourceBindData rbd;
        pbinding->GetResourceData(&rbd, BindIndex);
        return rbd.pResource;
    }
    return pResource;
}

inline Resource* ResourceHandle::GetResourceAndBinding(ResourceBinding* pbinding, ResourceBinding** presBinding) const
{
    if (IsIndex())
    {
        ResourceBindData rbd;
        pbinding->GetResourceData(&rbd, BindIndex);
        *presBinding = rbd.pBinding;
        return rbd.pResource;
    }
    *presBinding = pbinding;
    return pResource;
}

// The states a binding depends on: a movie bound under different values of these is a different MovieDefImpl.
class MovieDefBindStates : public RefCountBase<MovieDefBindStates, Stat_Default_Mem>
{
public:
    Ptr<State> pFileOpener;               // +0x10
    Ptr<State> pURLBuilder;               // +0x18
    Ptr<State> pImageCreator;             // +0x20
    Ptr<State> pImageFileHandlerRegistry; // +0x28 (not taken from the bag)
    Ptr<State> pImportVisitor;            // +0x30
    Ptr<State> pFontPackParams;           // +0x38
    Ptr<State> pBindState23;              // +0x40
    Ptr<State> pFontCompactorParams;      // +0x48
    Ptr<State> pImagePackParams;          // +0x50

    MovieDefBindStates(StateBag* psharedState)
    {
        static const State::StateType queried[8] = {
            State::State_FileOpener,     State::State_URLBuilder,     State::State_ImageCreator,
            State::State_ImportVisitor,  State::State_FontPackParams, State::State_BindState23,
            State::State_FontCompactorParams, State::State_ImagePackerParams};
        State* pstates[8] = {0, 0, 0, 0, 0, 0, 0, 0};

        psharedState->GetStatesAddRef(pstates, queried, 8);
        pFileOpener          = *pstates[0];
        pURLBuilder          = *pstates[1];
        pImageCreator        = *pstates[2];
        pImportVisitor       = *pstates[3];
        pFontPackParams      = *pstates[4];
        pBindState23         = *pstates[5];
        pFontCompactorParams = *pstates[6];
        pImagePackParams     = *pstates[7];
    }

    // Hash and equality of the key of a MovieDefImpl (the image file handler registry is not part of it).
    UPInt GetHashCode() const; // exe 0x1425d04f0
    bool  operator==(MovieDefBindStates& other) const
    {
        return pFileOpener == other.pFileOpener && pURLBuilder == other.pURLBuilder &&
               pImageCreator == other.pImageCreator && pImportVisitor == other.pImportVisitor &&
               pFontPackParams == other.pFontPackParams && pBindState23 == other.pBindState23 &&
               pFontCompactorParams == other.pFontCompactorParams && pImagePackParams == other.pImagePackParams;
    }

    // (appended for the load states, sfr_gfx_07e) a copy of the states of pother except the image file handler
    // registry (exe 0x142637330)
    MovieDefBindStates(MovieDefBindStates* pother);
};

// What CreateCharacterInstance needs of a character id.
struct CharacterCreateInfo
{
    CharacterDef* pCharDef;
    MovieDefImpl* pBindDefImpl;
    Resource*     pResource;
};

// The heaps and collectors one movie instance is created in (made by the ActionScript support, owned by the movie).
class MemoryContext : public RefCountBase<MemoryContext, Stat_Default_Mem>
{
public:
    virtual ~MemoryContext() {}
};

// A MovieDataDef bound under one set of binding states (0x40 bytes, vftables 0x14318b588 and StateBag 0x14318b670).
class MovieDefImpl : public MovieDef
{
public:
    enum BindStateType
    {
        BS_NotStarted = 0,
        BS_InProgress = 1,
        BS_Finished   = 2,
        BS_Canceled   = 3,
        BS_Error      = 4,
        BS_StateMask  = 0x0F
    };
    enum BindStateFlags
    {
        BSF_Frame1Loaded    = 0x100,
        BSF_LastFrameLoaded = 0x200
    };

    // Binding produced by the bind process (0x100 bytes, vftable 0x14318b580).
    class BindTaskData : public RefCountBase<BindTaskData, Stat_Default_Mem>
    {
        friend class MovieDefImpl;
        friend class MovieBindProcess;

        MemoryHeap*       pHeap;            // +0x10
        Ptr<MovieDataDef> pDataDef;         // +0x18
        MovieDefImpl*     pDefImpl_Unsafe;  // +0x20 cleared under ImportSourceLock when the MovieDefImpl dies
        unsigned          LoadFlags;        // +0x28
        ResourceBinding   ResourceBinding;  // +0x30

        ArrayLH<Ptr<MovieDefImpl>, StatMD_Other_Mem> ImportSourceMovies; // +0x80 by import index
        Lock                                         ImportSourceLock;   // +0x98
        ArrayLH<Ptr<MovieDefImpl>, StatMD_Other_Mem> ResourceImports;    // +0xc0 movies resources came from
        HashLH<Render::ShapeMeshProvider*, Ptr<Render::ShapeMeshProvider>, FixedSizeHash<Render::ShapeMeshProvider*> >
                                                     BoundShapeMeshProviders; // +0xd8

        volatile unsigned   BindState;       // +0xe0 BindStateType | BindStateFlags
        Ptr<LoadUpdateSync> pBindUpdate;     // +0xe8
        volatile unsigned   BindingFrame;    // +0xf0
        volatile UInt32     BytesLoaded;     // +0xf4
        volatile bool       BindingCanceled; // +0xf8

    public:
        BindTaskData(MemoryHeap* pheap, MovieDataDef* pdataDef, MovieDefImpl* pdefImpl, unsigned loadFlags,
                     bool fullyLoaded);
        ~BindTaskData();

        // The MovieDefImpl is going away: drop the pointers to it and cancel a bind in progress.
        void          OnMovieDefRelease();
        MovieDefImpl* GetMovieDefImplAddRef();

        MovieDataDef* GetDataDef() const      { return pDataDef; }
        MemoryHeap*   GetBindDataHeap() const { return pHeap; }

        unsigned      GetBindState() const      { return BindState; }
        BindStateType GetBindStateType() const  { return (BindStateType)(BindState & BS_StateMask); }
        unsigned      GetBindStateFlags() const { return BindState & ~BS_StateMask; }
        void          SetBindState(unsigned newState);
        // Blocks until all BindStateFlags bits in flags are set; false if binding failed.
        bool          WaitForBindStateFlags(unsigned flags);
        LoadUpdateSync* GetBindUpdateSync() const { return pBindUpdate; }

        unsigned GetLoadingFrame() const { return BindingFrame; }
        UInt32   GetBytesLoaded() const  { return BytesLoaded; }
        void     UpdateBindingFrame(unsigned frame, UInt32 bytesLoaded);

        MovieDefImpl* GetImportSourceMovie(unsigned importIndex);
        void          AddResourceImportMovie(MovieDefImpl* pdefImpl);
        void          ResolveImport(ImportData* pimport, MovieDefImpl* pdefImpl, LoadStates* pls, bool recursive);
        bool          ResolveImportThroughFontLib(ImportData* pimport);

        bool SetResourceBindData(ResourceId rid, ResourceBindData& bindData, const char* pimportSymbolName);
        bool SetResourceBindData(ResourceDataNode* presnode, Resource* pres);

        Ptr<Render::ShapeMeshProvider> GetShapeMeshProvider(Render::ShapeMeshProvider* defMeshProv);
        void AddShapeMeshProvider(Render::ShapeMeshProvider* defMeshProv, Render::ShapeMeshProvider* meshProv);
    };

    Ptr<StateBagImpl>       pStateBag;    // +0x20
    Ptr<LoaderImpl>         pLoaderImpl;  // +0x28
    Ptr<MovieDefBindStates> pBindStates;  // +0x30
    Ptr<BindTaskData>       pBindData;    // +0x38

    MovieDefImpl(MovieDataDef* pdataDef, MovieDefBindStates* pstates, LoaderImpl* ploaderImpl, unsigned loadConstants,
                 StateBagImpl* pdelegateState = 0, MemoryHeap* pargHeap = 0, bool fullyLoaded = false,
                 UPInt memoryArena = 0);
    ~MovieDefImpl();

    // Resource
    virtual ResourceKey     GetKey();
    virtual unsigned        GetResourceTypeCode() const { return MakeTypeCode(RT_MovieDef); }

    // MovieDef
    virtual unsigned            GetVersion() const      { return GetDataDef()->GetVersion(); }
    virtual unsigned            GetLoadingFrame() const { return pBindData->GetLoadingFrame(); }
    virtual float               GetWidth() const;
    virtual float               GetHeight() const;
    virtual unsigned            GetFrameCount() const   { return GetDataDef()->GetFrameCount(); }
    virtual float               GetFrameRate() const    { return GetDataDef()->GetFrameRate(); }
    virtual Render::Rect<float> GetFrameRect() const;
    virtual unsigned            GetSWFFlags() const     { return GetDataDef()->GetSWFFlags(); }
    virtual const char*         GetFileURL() const      { return GetDataDef()->GetFileURL(); }

    virtual void                WaitForLoadFinish(bool cancel = false) const;
    virtual void                WaitForFrame(unsigned frame) const;
    virtual unsigned            GetFileAttributes() const { return GetDataDef()->GetFileAttributes(); }
    virtual unsigned            GetMetadata(char* pbuff, unsigned buffSize) const;
    virtual MemoryHeap*         GetLoadDataHeap() const { return GetDataDef()->GetHeap(); }
    virtual MemoryHeap*         GetBindDataHeap() const { return pBindData->GetBindDataHeap(); }
    virtual MemoryHeap*         GetImageHeap() const;
    virtual Resource*           GetMovieDataResource() const { return GetDataDef(); }
    virtual const ExporterInfo* GetExporterInfo() const { return GetDataDef()->GetExporterInfo(); }
    virtual MemoryContext*      CreateMemoryContext(const char* heapName, const MemoryParams& memParams,
                                                    bool debugHeap);
    virtual Movie*              CreateInstance(const MemoryParams& memParams, bool initFirstFrame,
                                               ActionControl* actionControl, Render::ThreadCommandQueue* queue);
    virtual Movie*              CreateInstance(MemoryContext* memContext, bool initFirstFrame,
                                               ActionControl* actionControl, Render::ThreadCommandQueue* queue);
    virtual void                VisitImportedMovies(ImportVisitor* visitor);
    virtual void                VisitResources(ResourceVisitor* pvisitor, unsigned visitMask = ResVisit_AllImages);
    virtual Resource*           GetResource(const char* pexportName) const;

    struct SearchInfo;
    // A font this movie defines, by name and style (+0xe0).
    virtual FontResource* GetFontResource(const char* pfontName, unsigned styleFlags, SearchInfo* psearchInfo);

    // StateBag (exe 0x1425d1480)
    virtual StateBag* GetStateBagImpl() const;

    // Library key of the binding of pdataDef under pstates.
    static ResourceKey SF_STDCALL CreateMovieKey(MovieDataDef* pdataDef, MovieDefBindStates* pstates);

    MovieDataDef*    GetDataDef() const         { return pBindData->GetDataDef(); }
    unsigned         GetLoadFlags() const       { return pBindData->LoadFlags; }
    ResourceBinding& GetResourceBinding() const { return pBindData->ResourceBinding; }

    // The exported resource symbol, searched in this movie, then in the movies it imports (but ignoreDef).
    bool          GetExportedResource(ResourceBindData* pdata, const String& symbol, MovieDefImpl* ignoreDef = 0);
    bool          DoesDirectlyImport(const MovieDefImpl* import);
    const String* GetNameOfExportedResource(ResourceId rid) const;
    ResourceId    GetExportedResourceIdByName(const String& name) const;
    Ptr<ASSupport> GetASSupport() const;
    CharacterCreateInfo GetCharacterCreateInfo(ResourceId rid);

    // (appended for the font manager, sfr_gfx_07g) the loader's weak resource library; defined in gfx_loaderimpl.h
    inline ResourceWeakLib* GetWeakLib() const;
};

// What a GetFontResource search found and where: the import files it looked through and the one the font came from.
struct MovieDefImpl::SearchInfo
{
    enum SearchStatus
    {
        NotFound = 0,
        FoundInResources,
        FoundInResourcesNoGlyphs,
        FoundInResourcesNeedFaux,
        FoundInImports,
        FoundInImportsFontLib,
        FoundInExports
    };
    typedef HashSet<String, String::NoCaseHashFunctor> StringSet;

    SearchStatus Status;           // +0
    StringSet    ImportSearchUrls; // +8
    String       ImportFoundUrl;   // +0x10
};

// The loader allocates 0x48 bytes for a MovieDataDef and 0x40 for a MovieDefImpl.
static_assert(sizeof(MovieDataDef) == 0x48, "MovieDataDef size");
static_assert(sizeof(MovieDefImpl) == 0x40, "MovieDefImpl size");

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::MovieDefBindStates) == 0x58, "MovieDefBindStates size");

#endif
