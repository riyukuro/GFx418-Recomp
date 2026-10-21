// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 loader implementation (loader
// construction, the list of running load tasks and its cancellation).
// Sixth source of queue unit sfr_gfx_02 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_02f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a8280-0x1425aa720 .text$mn
// MS2-RANGE: 0x1425aaac0-0x1425ac250 .text$mn
//
// The text states the loader installs (ImageCreator, TextClipboard, TextKeyMap) are declared here only as far as the
// constructor needs them; their members bind to the exe (ImageCreator 0x142592bf0, TextClipboard 0x14258d510,
// TextKeyMap 0x14258d600, InitWindowsKeyMap 0x14258e0c0).

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/kernel/sf_file.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_timer.h"
#include "../include/kernel/sf_utf8util.h"
#include <string.h>

namespace Scaleform {

namespace Render { class TextureManager; }

// Growable wide string (only what TranslateInfo uses).
class WStringBuffer
{
    wchar_t* pText;
    UPInt    Length;

public:
    bool     Resize(UPInt size);
    wchar_t* GetBuffer() { return pText; }
};

namespace Render {

// Axis aligned rectangle (only what the header code uses).
template<class T>
class Rect
{
public:
    T x1, y1, x2, y2;

    Rect() : x1(0), y1(0), x2(0), y2(0) {}

    T Width() const  { return x2 - x1; }
    T Height() const { return y2 - y1; }
};
typedef Rect<float> RectF;

class ImageUpdateSync;
class TextureManager;

enum ImageFormat
{
    Image_None = 0
};

// How an image is created out of a source (0x28 bytes).
struct ImageCreateArgs
{
    unsigned         Use;
    MemoryHeap*      pHeap;
    TextureManager*  pManager;
    ImageUpdateSync* pUpdateSync;
    ImageFormat      Format;

    ImageCreateArgs() : Use(0), pHeap(0), pManager(0), pUpdateSync(0), Format(Image_None) {}
};

// Decoder of one image file format (only the slot called here).
class ImageFileReader
{
public:
    virtual ~ImageFileReader();
    virtual void         Slot1();
    virtual void         Slot2();
    virtual void         Slot3();
    virtual void         Slot4();
    virtual ImageSource* ReadImageSource(File* file, const ImageCreateArgs& args); // +0x28
};

class ImageFileHandlerRegistry
{
public:
    virtual ~ImageFileHandlerRegistry();

    ImageFileReader* GetReader(ImageFileFormat format);
};

} // namespace Render

namespace GFx {

class MovieDataDef;

// Header values reported to the user for a movie file.
struct MovieInfo
{
    enum SWFFlagConstants
    {
        SWF_Compressed = 0x0001,
        SWF_Stripped   = 0x0010
    };

    unsigned Version;
    unsigned Flags;
    int      Width, Height;
    float    FPS;
    unsigned FrameCount;
    unsigned TagCount;
    UInt16   ExporterVersion;
    UInt32   ExporterFlags;

    void Clear()
    {
        Version = 0;
        Flags   = 0;
        Width = Height = 0;
        FrameCount = TagCount = 0;
        FPS = 0.0f;
        ExporterVersion = 0;
        ExporterFlags   = 0;
    }
};

// What the exporter wrote about a stripped .gfx file (0x20 bytes).
struct ExporterInfo
{
    FileTypeConstants::FileFormatType Format;      // +0
    const char*                       pPrefix;     // +8
    const char*                       pSWFName;    // +0x10
    UInt16                            Version;     // +0x18
    unsigned                          ExportFlags; // +0x1c
};

// ExporterInfo plus the strings it points into (0x48 bytes).
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
        SI.pPrefix     = 0;
        SI.pSWFName    = 0;
        SI.Version     = 0;
        SI.ExportFlags = 0;
    }
    ~ExporterInfoImpl();

    void SetData(UInt16 version, FileTypeConstants::FileFormatType format, const char* pname, const char* pprefix,
                 unsigned flags = 0, const Array<UInt32>* codeOffsets = 0);

    const ExporterInfo* GetExporterInfo() const { return (SI.Format == FileTypeConstants::File_Unopened) ? 0 : &SI; }

    void ReadExporterInfoTag(Stream* pin, TagType tagType);
};

// SWF/GFX header of a movie.
struct MovieHeaderData
{
    UInt32           FileLength;    // +0
    int              Version;       // +4
    UInt32           Unknown8[2];   // +8
    Render::RectF    FrameRect;     // +0x10
    float            FPS;           // +0x20
    unsigned         FrameCount;    // +0x24
    unsigned         SWFFlags;      // +0x28
    ExporterInfoImpl mExporterInfo; // +0x30

    // FrameCount starts at 1: image and empty movies rely on it.
    MovieHeaderData() : FileLength(0), Version(-1), FPS(1.0f), SWFFlags(0)
    {
        FrameCount = 1;
    }

    void GetMovieInfo(MovieInfo* pinfo) const;
};

// The stream of a movie file positioned after its header (0x310 bytes).
struct SWFProcessInfo
{
    GFx::Stream     Stream;          // +0
    UInt32          FileStartPos;    // +0x270
    UInt32          FileEndPos;      // +0x274
    UInt32          NextActionBlock; // +0x278
    MovieHeaderData Header;          // +0x280
    UByte           Unknown2f8[8];   // +0x2f8
    UInt16          FileAttributes;  // +0x300

    SWFProcessInfo(MemoryHeap* pheap) : Stream(0, pheap, 0, 0), FileAttributes(0) {}

    // Reads and checks the header of pin; false (logged) when it is not a usable SWF/GFX file.
    bool Initialize(File* pin, LogState* plog, ZlibSupportBase* zlib, ParseControl* pparseControl, bool parseMsg);
};

// Binds a MovieDataDef into a MovieDefImpl (0x60 bytes; only construction is used here).
class MovieBindProcess : public LoaderTask
{
    UByte Data20[0x38];

public:
    void* pTempBindData; // +0x58

    MovieBindProcess(LoadStates* pls, MovieDefImpl* pdefImpl, LoaderImpl::LoadStackItem* ploadStack = 0);

    virtual void Execute();
};

// Parses one SWF file (0x430 bytes; only what the loader calls is declared here).
class LoadProcess : public LoaderTask
{
    UByte                 Pad20[0x10];
    Ptr<MovieBindProcess> pBindProcess;  // +0x30
    UByte                 Pad38[0x338];
    void*                 pTempBindData; // +0x370
    UByte                 Pad378[0xb8];

public:
    LoadProcess(MovieDataDef* pdataDef, LoadStates* pstates, unsigned loadFlags);

    // Reads and checks the file header; false if pin is not a usable SWF/GFX file.
    bool BeginSWFLoading(File* pin);

    void SetBindProcess(MovieBindProcess* pbindProcess);
    void SetTempBindData(void* ptempdata) { pTempBindData = ptempdata; }

    virtual void Execute();
};

// Word wrapping rules shared by the text engine.
class WordWrapHelper
{
public:
    // Where to break a line of lineLen characters at lineStartPos under the wwMode rules; SF_MAX_UPINT for "keep".
    static UPInt SF_STDCALL FindWordWrapPos(UInt32 wwMode, UPInt wordWrapPos, const wchar_t* pparaText, UPInt paraLen,
                                           UPInt lineStartPos, UPInt lineLen);

    static bool IsVowel(wchar_t c)
    {
        wchar_t lc = (wchar_t)SFtowlower(c);
        return lc == L'a' || lc == L'e' || lc == L'i' || lc == L'o' || lc == L'u';
    }
};

// Text replacement and custom word wrapping hook (state).
class Translator : public State
{
public:
    enum WordWrappingTypes
    {
        WWT_Default      = 0,
        WWT_Asian        = 0x1,
        WWT_Prohibition  = 0x2,
        WWT_NoHangulWrap = 0x4,
        WWT_Hyphenation  = 0x8
    };

    // One line the text engine is about to wrap.
    struct LineFormatDesc
    {
        const wchar_t* pParaText;               // +0
        UPInt          ParaTextLen;             // +8
        const float*   pWidths;                 // +0x10 width of the line up to each character
        UPInt          LineStartPos;            // +0x18
        UPInt          NumCharsInLine;          // +0x20
        float          VisibleRectWidth;        // +0x28
        float          CurrentLineWidth;        // +0x2c
        float          LineWidthBeforeWordWrap; // +0x30
        float          DashSymbolWidth;         // +0x34
        unsigned       Alignment;               // +0x38
        UPInt          ProposedWordWrapPoint;   // +0x40
        bool           UseHyphenation;          // +0x48
    };

    unsigned WWMode; // +0x18

    virtual unsigned GetCaps() const;
    virtual void     Translate(void* ptranslateInfo);
    virtual bool     OnWordWrapping(LineFormatDesc* pdesc);

    class TranslateInfo
    {
    public:
        enum { Flag_Translated = 1 };

        const wchar_t* pKey;          // +0
        WStringBuffer* pResult;       // +8
        const char*    pInstanceName; // +0x10
        UByte          Flags;         // +0x18

        void SetResult(const wchar_t* presultText, UPInt resultLen = SF_MAX_UPINT);
        void SetResult(const char* presultTextUTF8, UPInt resultUTF8Len = SF_MAX_UPINT);
    };
};

// The image file readers a loader may use.
class ImageFileHandlerRegistry : public State, public Render::ImageFileHandlerRegistry
{
};

class ImageResource : public Resource
{
};

// Creates images for the loader (0x20 bytes).
class ImageCreator : public State
{
    void* pTextureManager; // +0x18

public:
    ImageCreator(Render::TextureManager* textureManager = 0);
};

// Clipboard shared by the text fields of a loader (0x40 bytes).
class TextClipboard : public State
{
    UByte Data[0x28]; // +0x18

public:
    TextClipboard();
};

// Key bindings of the text editor (0x30 bytes).
class TextKeyMap : public State
{
    UByte Data[0x18]; // +0x18

public:
    TextKeyMap();
    TextKeyMap* InitWindowsKeyMap();
};

inline void StateBag::SetImageCreator(ImageCreator* ptr)   { SetState(State::State_ImageCreator, ptr); }
inline void StateBag::SetTextClipboard(TextClipboard* ptr) { SetState(State::State_TextClipboard, ptr); }
inline void StateBag::SetTextKeyMap(TextKeyMap* ptr)       { SetState(State::State_TextKeyMap, ptr); }

// Background load of one image file of a movie (0x48 bytes, vftable 0x143188fa8).
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

// @0x1425a8280
LoaderImpl::LoaderImpl(LoaderImpl* psource)
    : pWeakResourceLib(psource->pWeakResourceLib), DebugHeap(psource->DebugHeap)
{
    if ((pStateBag = *new StateBagImpl(0)))
    {
        if (psource->pStateBag)
            pStateBag->CopyStatesFrom(psource->pStateBag);
        else
            pStateBag->SetLog(0);
    }
}

// @0x1425a83d0
LoaderImpl::LoaderImpl(ResourceLib* plib, bool debugHeap) : DebugHeap(debugHeap)
{
    if (plib)
        pWeakResourceLib = plib->GetWeakLib();

    if ((pStateBag = *new StateBagImpl(0)))
    {
        pStateBag->SetLog(0);
        pStateBag->SetImageCreator(Ptr<ImageCreator>(*new ImageCreator));
        pStateBag->SetTextClipboard(Ptr<TextClipboard>(*new TextClipboard));
        pStateBag->SetTextKeyMap(Ptr<TextKeyMap>(*(new TextKeyMap)->InitWindowsKeyMap()));
    }
}

// @0x1425a8610
LoaderImpl::LoaderImpl(StateBag* pstates, ResourceLib* plib, bool debugHeap) : DebugHeap(debugHeap)
{
    if (plib)
        pWeakResourceLib = plib->GetWeakLib();

    pStateBag = static_cast<StateBagImpl*>(pstates);
}

// @0x1425a8980
LoaderImpl::~LoaderImpl()
{
    CancelLoading();
}

// @0x1425abe30
void LoaderImpl::RegisterLoadProcess(LoaderTask* ptask)
{
    Lock::Locker guard(&LoadProcessesLock);
    LoadProcesses.PushBack(new LoadProcessNode(ptask));
}

// @0x1425ac1d0
void LoaderImpl::UnRegisterLoadProcess(LoaderTask* ptask)
{
    Lock::Locker     guard(&LoadProcessesLock);
    LoadProcessNode* pnode = LoadProcesses.GetFirst();
    while (!LoadProcesses.IsNull(pnode))
    {
        if (pnode->pTask == ptask)
        {
            LoadProcesses.Remove(pnode);
            delete pnode;
            break;
        }
        pnode = pnode->pNext;
    }
}

// Abandons every task still registered with the task manager.
// @0x1425a90e0
void LoaderImpl::CancelLoading()
{
    Ptr<TaskManager> ptm = *(TaskManager*)pStateBag->GetStateAddRef(State::State_TaskManager);
    if (!ptm)
        return;

    Lock::Locker     guard(&LoadProcessesLock);
    LoadProcessNode* pnode = LoadProcesses.GetFirst();
    while (!LoadProcesses.IsNull(pnode))
    {
        LoadProcesses.Remove(pnode);
        ptm->AbandonTask(pnode->pTask);
        delete pnode;
        pnode = LoadProcesses.GetFirst();
    }
}

// @0x1425a8700
LoaderTask::LoaderTask(LoadStates* pls, TaskId id) : Task(id), pLoadStates(pls)
{
    pLoadStates->pLoaderImpl->RegisterLoadProcess(this);
}

// @0x1425a8ab0
LoaderTask::~LoaderTask()
{
    pLoadStates->pLoaderImpl->UnRegisterLoadProcess(this);
}

// The header of a file already in the library comes from its MovieDataDef; any other file is opened and its header
// read (and its tags counted when asked). False when there is no library or the file cannot be read.
// @0x1425aab50
// MS2-FUNCTIONAL: same flow, calls and stores as the exe; pfilename / pinfo / the -1 swap rsi, rdi and rbx
bool LoaderImpl::GetMovieInfo(const char* pfilename, MovieInfo* pinfo, bool getTagCount, unsigned loadConstants)
{
    if (!pinfo)
        return 0;
    pinfo->Clear();

    Ptr<LoadStates> pls = *new LoadStates(this);
    if (!pls->pWeakResourceLib)
        return 0;

    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, pfilename);
    String                   fileName;
    pls->BuildURL(&fileName, loc);

    Ptr<Resource> pmovieDataResource;
    {
        ImageCreator* pkeyImageCreator = pls->GetLoadTimeImageCreator(loadConstants);
        FileOpener*   pfileOpener      = (FileOpener*)pls->GetBindStates()->pFileOpener.GetPtr();
        SInt64        modifyTime       = pfileOpener ? pfileOpener->GetFileModifyTime(fileName.ToCStr()) : 0;

        ResourceKey fileDataKey = MovieDataDef::CreateMovieFileKey(fileName.ToCStr(), modifyTime, pfileOpener,
                                                                   pkeyImageCreator,
                                                                   pls->GetBindStates()->pBindState23);
        pmovieDataResource = *pls->pWeakResourceLib->GetResource(fileDataKey);
    }

    if (pmovieDataResource)
    {
        MovieDataDef* pmd = (MovieDataDef*)pmovieDataResource.GetPtr();
        ((const MovieHeaderData*)pmd->pData->GetHeaderData())->GetMovieInfo(pinfo);
        if (getTagCount)
            pinfo->TagCount = pmd->pData->GetTagCount();
    }
    else
    {
        Ptr<File> pin = *pls->OpenFile(fileName.ToCStr(), 0);
        if (!pin)
            return 0;

        SWFProcessInfo pi(Memory::pGlobalHeap);
        if (!pi.Initialize(pin, pls->pLog, pls->pZlibSupport, pls->pParseControl, false))
            return 0;

        pi.Header.GetMovieInfo(pinfo);

        if (getTagCount)
        {
            while ((UInt32)pi.Stream.Tell() < pi.FileEndPos)
            {
                pi.Stream.OpenTag();
                pi.Stream.CloseTag();
                pinfo->TagCount++;
            }
        }
    }
    return 1;
}

// Never inlined in the exe.
// @0x1425a87c0
SF_NOINLINE MovieImageLoadTask::MovieImageLoadTask(MovieDataDef* pdef, MovieDefImpl* pdefImpl, File* pimageFile,
                                       FileTypeConstants::FileFormatType format, LoadStates* pls)
    : LoaderTask(pls, Id_MovieImageLoad), pDef(pdef), pDefImpl(pdefImpl), pImageFile(pimageFile), ImageFormat(format)
{
}

// @0x1425ac010
void ExporterInfoImpl::SetData(UInt16 version, FileTypeConstants::FileFormatType format, const char* pname,
                               const char* pprefix, unsigned flags, const Array<UInt32>* codeOffsets)
{
    SI.Version  = version;
    SI.Format   = format;
    Prefix      = pprefix ? pprefix : "";
    SWFName     = pname ? pname : "";
    SI.pSWFName = SWFName.ToCStr();
    SI.pPrefix  = Prefix.ToCStr();
    SI.ExportFlags = flags;
    if (codeOffsets)
        CodeOffsets = *codeOffsets;
    else
        CodeOffsets.Clear();
}

// Sizes are in twips (1/20 pixel), rounded.
// @0x1425aaf40
void MovieHeaderData::GetMovieInfo(MovieInfo* pinfo) const
{
    pinfo->Version    = Version;
    pinfo->Flags      = SWFFlags;
    pinfo->FPS        = FPS;
    pinfo->FrameCount = FrameCount;
    pinfo->Width      = int(FrameRect.Width() / 20.0f + 0.5f);
    pinfo->Height     = int(FrameRect.Height() / 20.0f + 0.5f);

    const ExporterInfo* pexi = mExporterInfo.GetExporterInfo();
    if (pexi)
    {
        pinfo->ExporterVersion = pexi->Version;
        pinfo->ExporterFlags   = pexi->ExportFlags;
    }
    else
    {
        pinfo->ExporterVersion = 0;
        pinfo->ExporterFlags   = 0;
    }
}

// Sniffs the first bytes of the file; TGA has no signature, so it is told by its extension.
// @0x1425aa430
FileTypeConstants::FileFormatType LoaderImpl::DetectFileFormat(File* pfile)
{
    if (!pfile)
        return File_Unopened;

    int            pos       = pfile->Tell();
    FileFormatType format    = File_Unknown;
    UByte          buffer[4] = {0, 0, 0, 0};

    if (pfile->Read(buffer, 4) <= 0)
        return File_Unknown;

    switch (buffer[0])
    {
    case 'C':
    case 'F':
        if ((buffer[1] == 'W') && (buffer[2] == 'S'))
            format = File_SWF;
        else if ((buffer[1] == 'F') && (buffer[2] == 'X'))
            format = File_GFX;
        break;

    case 0xFF:
        if (buffer[1] == 0xD8)
            format = File_JPEG;
        break;

    case 0x89:
        if ((buffer[1] == 'P') && (buffer[2] == 'N') && (buffer[3] == 'G'))
            format = File_PNG;
        break;

    case 'G':
        if ((buffer[1] == 'I') && (buffer[2] == 'F') && (buffer[3] == '8'))
            format = File_GIF;
        else if ((buffer[1] == 'F') && (buffer[2] == 'X'))
            format = File_GFX;
        else if ((buffer[1] == 'X') && (buffer[2] == 'T') && (buffer[3] == 0))
            format = File_GXT;
        break;

    case 'D':
        if ((buffer[1] == 'D') && (buffer[2] == 'S'))
            format = File_DDS;
        break;

    case 52:
        // A PVR v2 header starts with its own size (52) and has the "PVR" tag at offset 44.
        pfile->Seek(44, File::Seek_Set);
        if (pfile->Read(buffer, 3) != 3)
            break;
        if ((buffer[0] == 'P') && (buffer[1] == 'V') && (buffer[2] == 'R'))
            format = File_PVR;
        break;
    }

    pfile->Seek(pos);
    if (format == File_Unknown)
    {
        const char* ppath = pfile->GetFilePath();
        if (ppath)
        {
            const char* pext = strrchr(ppath, '.');
            if (pext && (String::CompareNoCase(pext, ".tga") == 0))
                format = File_TGA;
        }
    }
    return format;
}

// @0x1425a91b0
void StateBagImpl::CopyStatesFrom(StateBagImpl* pother)
{
    Lock::Locker lock(&StateLock);
    Lock::Locker lockOther(&pother->StateLock);
    States = pother->States;
}

// Never inlined in the exe (three call sites, all calls).
// @0x1425a8f60
SF_NOINLINE MovieDefImpl* LoaderImpl::BindMovieAndWait(MovieDefImpl* pm, MovieBindProcess* pbp, LoadStates* pls,
                                           unsigned loadConstants, LoadStackItem* ploadStack)
{
    // Bind now when asked to wait or when nothing can run it in the background.
    if (pbp)
    {
        if ((loadConstants & Loader::LoadWaitCompletion) || !pls->SubmitBackgroundTask(pbp))
            pbp->Execute();
    }

    bool waitSucceeded = true;
    bool needWait      = true;

    // pm already on the import stack: waiting would never end.
    for (LoadStackItem* pstack = ploadStack; pstack; pstack = pstack->pNext)
    {
        if (pstack->pDefImpl == pm)
        {
            // Self import is harmless; a longer cycle is an error.
            if (pstack->pNext)
            {
                waitSucceeded = false;
                if (pls->pLog)
                {
                    StringBuffer buffer;
                    for (; ploadStack; ploadStack = ploadStack->pNext)
                    {
                        buffer.AppendString(ploadStack->pDefImpl->GetFileURL());
                        buffer.AppendChar('\n');
                    }
                    buffer.AppendString(pm->GetFileURL());
                    pls->pLog->LogError("Recursive import detected. Import stack:\n%s", buffer.ToCStr());
                }
            }
            needWait = false;
            break;
        }
    }

    if (needWait && (loadConstants & Loader::LoadWaitCompletion))
        waitSucceeded = pm->pBindData->WaitForBindStateFlags(MovieDefImpl::BSF_LastFrameLoaded);
    else if (needWait && (loadConstants & Loader::LoadWaitFrame1))
        waitSucceeded = pm->pBindData->WaitForBindStateFlags(MovieDefImpl::BSF_Frame1Loaded);

    if (!waitSucceeded)
    {
        pm->Release();
        pm = 0;
    }
    return pm;
}

// @0x1425a9320
// MS2-FUNCTIONAL: this/loadConstants swap rbx/rdi; every other byte matches
MovieDef* LoaderImpl::CreateMovie(const char* pfilename, unsigned loadConstants, UPInt memoryArena)
{
    Ptr<LoadStates> pls = *new LoadStates(this);
    // Started from a loader thread: load threaded even without a task manager.
    if (loadConstants & Loader::LoadOnThread)
        pls->ThreadedLoading = true;

    if (!pls->pWeakResourceLib)
        return 0;

    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, pfilename);
    return CreateMovie_LoadState(pls, loc, loadConstants, 0, memoryArena);
}

// Finds or loads the data of the file loc names, then finds or binds its MovieDefImpl. A file nobody loads yet is
// opened and parsed here (or on a task), images through MovieImageLoadTask.
// @0x1425a9680
// MS2-FUNCTIONAL: same flow and calls as the exe; pls / loadConstants live in other registers and stack slots
MovieDefImpl* LoaderImpl::CreateMovie_LoadState(LoadStates* pls, const URLBuilder::LocationInfo& loc,
                                                unsigned loadConstants, LoadStackItem* ploadStack, UPInt memoryArena)
{
    String fileName;
    pls->BuildURL(&fileName, loc);

    ResourceLib::BindHandle     bh;
    Ptr<MovieDataDef>           pmd;
    MovieDefImpl*               pm                = 0;
    LogState*                   plog              = pls->pLog;
    bool                        movieNeedsLoading = 0;
    MovieDataDef::MovieDataType mtype             = MovieDataDef::MT_Empty;
    Ptr<MovieBindProcess>       pbp;
    Ptr<LoadProcess>            plp;
    Ptr<File>                   pin;
    FileFormatType              format = File_Unopened;

    // Packing images needs the whole file first.
    if (pls->GetBindStates()->pImagePackParams)
        loadConstants |= Loader::LoadOrdered | Loader::LoadWaitCompletion;

    // Interleaved: imports and images are bound while the file is still loading.
    bool interleavedLoading = !(loadConstants & Loader::LoadOrdered);

    ImageCreator* pkeyImageCreator = pls->GetLoadTimeImageCreator(loadConstants);
    FileOpener*   pfileOpener      = (FileOpener*)pls->GetBindStates()->pFileOpener.GetPtr();
    SInt64        modifyTime       = pfileOpener ? pfileOpener->GetFileModifyTime(fileName.ToCStr()) : 0;

    ResourceKey fileDataKey = MovieDataDef::CreateMovieFileKey(fileName.ToCStr(), modifyTime, pfileOpener,
                                                               pkeyImageCreator,
                                                               pls->GetBindStates()->pBindState23);

    if (pls->pWeakResourceLib->BindResourceKey(&bh, fileDataKey) == ResourceLib::RS_NeedsResolve)
    {
        pin = *pls->OpenFile(fileName.ToCStr(), loadConstants);
        if (!pin)
        {
            String s("Loader failed to open \"", fileName.ToCStr(), "\"\n");
            bh.CancelResolve(s.ToCStr());
            return 0;
        }

        format = DetectFileFormat(pin);

        switch (format)
        {
        case File_SWF:
            if (loadConstants & Loader::LoadDisableSWF)
            {
                String s("Failed loading SWF file \"", fileName.ToCStr(), "\" - GFX file format expected");
                if (plog)
                    plog->LogError("%s", s.ToCStr());
                bh.CancelResolve(s.ToCStr());
                return 0;
            }
            // fall through
        case File_GFX:
            mtype = MovieDataDef::MT_Flash;
            break;

        case File_JPEG:
        case File_PNG:
        case File_GIF:
        case File_TGA:
        case File_DDS:
        case File_HDR:
        case File_BMP:
        case File_DIB:
        case File_PFM:
        case File_TIFF:
        case File_PVR:
        case File_ETC:
        case File_SIF:
        case File_GXT:
            if (loadConstants & Loader::LoadImageFiles)
            {
                mtype = MovieDataDef::MT_Image;
                break;
            }
            // fall through
        default:
            {
                String s("Unknown file format at URL \"", fileName.ToCStr(), "\"");
                if (plog)
                    plog->LogError("%s", s.ToCStr());
                bh.CancelResolve(s.ToCStr());
            }
            return 0;
        }

        pmd = *new MovieDataDef(fileDataKey, mtype, fileName.ToCStr(), 0,
                                (loadConstants & Loader::LoadDebugHeap) ? true : false, memoryArena);
        if (pmd)
        {
            pls->SetRelativePathForDataDef(pmd);

            // Flash files get their loader now (it checks the header); images load later.
            if (mtype == MovieDataDef::MT_Flash)
            {
                plp = *new LoadProcess(pmd, pls, loadConstants);
                if (!plp || !plp->BeginSWFLoading(pin))
                {
                    plp = 0;
                    pmd = 0;
                }
            }
        }

        if (pmd)
        {
            // Create the binding before resolving so no other thread starts binding it first.
            if ((mtype != MovieDataDef::MT_Flash) || interleavedLoading)
                pm = CreateMovieDefImpl(pls, pmd, loadConstants,
                                        (mtype == MovieDataDef::MT_Flash) ? &pbp.GetRawRef() : 0, true, ploadStack,
                                        memoryArena);

            bh.ResolveResource(pmd.GetPtr());
        }
        else
        {
            String s("Failed to load SWF file \"", fileName.ToCStr(), "\"\n");
            bh.CancelResolve(s.ToCStr());
            return 0;
        }

        movieNeedsLoading = 1;
    }
    else
    {
        // Loaded or being loaded by another thread.
        if ((pmd = *(MovieDataDef*)bh.WaitForResolve()).GetPtr() == 0)
        {
            if (plog)
                plog->LogError("%s", bh.GetResolveError());
            return 0;
        }

        mtype = pmd->MovieType;
        pls->SetRelativePathForDataDef(pmd);
    }

    if (!movieNeedsLoading || !interleavedLoading)
    {
        if (!pm)
            pm = CreateMovieDefImpl(pls, pmd, loadConstants, (mtype == MovieDataDef::MT_Flash) ? &pbp.GetRawRef() : 0,
                                    false, ploadStack, memoryArena);
    }
    if (!pm)
        return 0;

    if (movieNeedsLoading)
    {
        if (mtype == MovieDataDef::MT_Flash)
        {
            // Interleaved: the load task runs the bind process as it goes.
            MovieBindProcess* ploadBind = (loadConstants & Loader::LoadOrdered) ? 0 : pbp.GetPtr();
            if (ploadBind)
                plp->SetBindProcess(ploadBind);

            if (pbp)
                plp->SetTempBindData(pbp->pTempBindData);

            if (loadConstants & Loader::LoadWaitCompletion || !pls->SubmitBackgroundTask(plp))
                plp->Execute();

            if (ploadBind)
                pbp = 0;

            plp = 0;
            pin = 0;
        }
        else
        {
            Ptr<MovieImageLoadTask> ptask = *new MovieImageLoadTask(pmd, pm, pin, format, pls);

            if ((loadConstants & (Loader::LoadWaitCompletion | Loader::LoadOrdered)) ||
                !pls->SubmitBackgroundTask(ptask))
            {
                ptask->Execute();

                if (!ptask->LoadingSucceeded())
                {
                    if (pm)
                        pm->Release();
                    return 0;
                }
            }
        }
    }

    return BindMovieAndWait(pm, pbp, pls, loadConstants, ploadStack);
}

// Loads a movie from bytes in memory. The data is keyed under a made-up file name, so it is never shared with an
// earlier load; otherwise like loading a file.
// @0x1425a9db0
MovieDefImpl* LoaderImpl::CreateMovie_LoadState(LoadStates* pls, const ArrayPOD<UByte>& bytes, unsigned loadConstants,
                                                LoadStackItem* ploadStack, UPInt memoryArena)
{
    char   fileName[128];
    UInt64 modifyTime = Timer::GetProfileTicks();
    SFsprintf(fileName, sizeof(fileName), "*Bytes@%p*", (UPInt)modifyTime);

    ResourceLib::BindHandle     bh;
    Ptr<MovieDataDef>           pmd;
    MovieDefImpl*               pm    = 0;
    LogState*                   plog  = pls->pLog;
    MovieDataDef::MovieDataType mtype = MovieDataDef::MT_Empty;
    Ptr<MovieBindProcess>       pbp;
    Ptr<LoadProcess>            plp;
    Ptr<File>                   pin;
    FileFormatType              format = File_Unopened;

    if (pls->GetBindStates()->pImagePackParams)
        loadConstants |= Loader::LoadOrdered | Loader::LoadWaitCompletion;

    ResourceKey fileDataKey = MovieDataDef::CreateMovieFileKey(fileName, modifyTime, 0, 0,
                                                               pls->GetBindStates()->pBindState23);

    pls->pWeakResourceLib->BindResourceKey(&bh, fileDataKey);

    pin = *new MemoryFile(fileName, bytes.GetDataPtr(), int(bytes.GetSize()));

    format = DetectFileFormat(pin);

    switch (format)
    {
    case File_SWF:
        if (loadConstants & Loader::LoadDisableSWF)
        {
            String s("Failed loading SWF file \"", fileName, "\" - GFX file format expected");
            if (plog)
                plog->LogError("%s", s.ToCStr());
            bh.CancelResolve(s.ToCStr());
            return 0;
        }
        // fall through
    case File_GFX:
        mtype = MovieDataDef::MT_Flash;
        break;

    case File_JPEG:
    case File_PNG:
    case File_GIF:
    case File_TGA:
    case File_DDS:
    case File_HDR:
    case File_BMP:
    case File_DIB:
    case File_PFM:
    case File_TIFF:
    case File_PVR:
    case File_ETC:
    case File_SIF:
    case File_GXT:
        if (loadConstants & Loader::LoadImageFiles)
        {
            mtype = MovieDataDef::MT_Image;
            break;
        }
        // fall through
    default:
        {
            String s("Unknown file format at URL \"", fileName, "\"");
            if (plog)
                plog->LogError("%s", s.ToCStr());
            bh.CancelResolve(s.ToCStr());
        }
        return 0;
    }

    pmd = *new MovieDataDef(fileDataKey, mtype, fileName, 0, (loadConstants & Loader::LoadDebugHeap) ? true : false,
                            memoryArena);
    if (pmd)
    {
        pls->SetRelativePathForDataDef(pmd);

        if (mtype == MovieDataDef::MT_Flash)
        {
            plp = *new LoadProcess(pmd, pls, loadConstants);
            if (!plp || !plp->BeginSWFLoading(pin))
            {
                plp = 0;
                pmd = 0;
            }
        }
    }

    if (pmd)
    {
        // Nothing else can know the made-up key, so the binding is always created here.
        pm = CreateMovieDefImpl(pls, pmd, loadConstants, (mtype == MovieDataDef::MT_Flash) ? &pbp.GetRawRef() : 0,
                                true, ploadStack, memoryArena);
        bh.ResolveResource(pmd.GetPtr());
    }
    else
    {
        String s("Failed to load SWF file \"", fileName, "\"\n");
        bh.CancelResolve(s.ToCStr());
        return 0;
    }

    if (!pm)
        return 0;

    if (mtype == MovieDataDef::MT_Flash)
    {
        MovieBindProcess* ploadBind = (loadConstants & Loader::LoadOrdered) ? 0 : pbp.GetPtr();
        if (ploadBind)
            plp->SetBindProcess(ploadBind);

        if (pbp)
            plp->SetTempBindData(pbp->pTempBindData);

        if (loadConstants & Loader::LoadWaitCompletion || !pls->SubmitBackgroundTask(plp))
            plp->Execute();

        if (ploadBind)
            pbp = 0;

        plp = 0;
        pin = 0;
    }
    else
    {
        Ptr<MovieImageLoadTask> ptask = *new MovieImageLoadTask(pmd, pm, pin, format, pls);

        if ((loadConstants & (Loader::LoadWaitCompletion | Loader::LoadOrdered)) || !pls->SubmitBackgroundTask(ptask))
        {
            ptask->Execute();

            if (!ptask->LoadingSucceeded())
            {
                if (pm)
                    pm->Release();
                return 0;
            }
        }
    }

    return BindMovieAndWait(pm, pbp, pls, loadConstants, ploadStack);
}

// Looks up the binding of pmd under the load's bind states, creating it (and its bind process) on first use.
// @0x1425a9440
MovieDefImpl* LoaderImpl::CreateMovieDefImpl(LoadStates* pls, MovieDataDef* pmd, unsigned loadConstants,
                                             MovieBindProcess** ppbindProcess, bool checkCreate,
                                             LoadStackItem* ploadStack, UPInt memoryArena)
{
    SF_UNUSED(checkCreate);

    ResourceLib::BindHandle bh;
    MovieDefImpl*           pm          = 0;
    MovieDefBindStates*     pbindStates = pls->pBindStates;
    ResourceKey             key         = MovieDefImpl::CreateMovieKey(pmd, pbindStates);

    if (pls->pWeakResourceLib->BindResourceKey(&bh, key) == ResourceLib::RS_NeedsResolve)
    {
        // Non-binding states (log, renderer...) come from the loader's bag.
        pm = new MovieDefImpl(pmd, pbindStates, pls->pLoaderImpl, loadConstants, pls->pLoaderImpl->pStateBag,
                              Memory::pGlobalHeap, false, memoryArena);
        if (ppbindProcess)
        {
            *ppbindProcess = new MovieBindProcess(pls, pm, ploadStack);
            if (!*ppbindProcess && pm)
            {
                pm->Release();
                pm = 0;
            }
        }

        if (pm)
            bh.ResolveResource(pm);
        else
        {
            String s("Failed to bind SWF file \"", pmd->GetFileURL(), "\"\n");
            bh.CancelResolve(s.ToCStr());
            return 0;
        }
    }
    else
    {
        // Available or being resolved by another thread; the result is AddRef-ed for us.
        if ((pm = (MovieDefImpl*)bh.WaitForResolve()) == 0)
        {
            if (pls->pLog)
                pls->pLog->LogError("%s", bh.GetResolveError());
            return 0;
        }
    }
    return pm;
}

// @0x1425aa390
MovieDefImpl* LoaderImpl::CreateMovie_LoadState(LoadStates* pls, MovieDataDef* pmd, unsigned loadConstants,
                                                UPInt memoryArena)
{
    if (pmd)
        pls->SetRelativePathForDataDef(pmd);

    // The bind process reference CreateMovieDefImpl hands out is ours.
    Ptr<MovieBindProcess> pbp;
    MovieDefImpl*         pm = CreateMovieDefImpl(pls, pmd, loadConstants, &pbp.GetRawRef(), false, 0, memoryArena);
    if (!pm)
        return 0;
    return BindMovieAndWait(pm, pbp, pls, loadConstants);
}

// @0x1425ab490
bool LoaderImpl::IsProtocolImage(const String& url, bool* pbilinear, bool* psync)
{
    if (url.GetLength() > 6)
    {
        int firstChar = SFtolower(url.ToCStr()[0]);
        if (firstChar == 'i' || firstChar == 's')
        {
            String lower = url.ToLower();
            UPInt  idx   = (firstChar == 's') ? 1 : 0;
            if (lower.Substring(idx, idx + 6) == "img://")
            {
                if (pbilinear)
                    *pbilinear = true;
                if (psync)
                    *psync = (idx != 0);
                return true;
            }
            if (lower.Substring(idx, idx + 8) == "imgps://")
            {
                if (pbilinear)
                    *pbilinear = false;
                if (psync)
                    *psync = (idx != 0);
                return true;
            }
        }
    }
    return false;
}

// @0x1425ab660
Render::ImageSource* LoaderImpl::LoadBuiltinImage(File* pfile, FileFormatType format, Resource::ResourceUse,
                                                  LoadStates* pls, Log* plog, MemoryHeap* pimageHeap)
{
    Render::ImageSource*    pimageSrc = 0;
    const char*             pfilePath = pfile->GetFilePath();
    Render::ImageFileFormat imageFmt  = FileFormat2RenderImageFile(format);

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

// The SWF signature (FWS, CWS, GFX, CFX) and version come first, then the 32-bit file length; a compressed body is
// read through the zlib state. Stripped (GFX) files must start with the exporter info tag; for SWF 9+ the file
// attributes tag is peeked so the caller can tell AS2 from AS3.
// @0x1425aaff0
bool SWFProcessInfo::Initialize(File* pin, LogState* plog, ZlibSupportBase* zlib, ParseControl* pparseControl,
                                bool parseMsg)
{
    UInt32 header;
    bool   compressed;

    FileStartPos      = pin->Tell();
    header            = pin->ReadUInt32();
    Header.FileLength = pin->ReadUInt32();
    FileEndPos        = FileStartPos + Header.FileLength;
    NextActionBlock   = 0;
    Header.Version    = (header >> 24) & 255;
    Header.SWFFlags   = 0;
    compressed        = (header & 255) == 'C';
    FileAttributes    = 0;

    if (((header & 0x0FFFFFF) != 0x00535746) && ((header & 0x0FFFFFF) != 0x00535743) &&
        ((header & 0x0FFFFFF) != 0x00584647) && ((header & 0x0FFFFFF) != 0x00584643))
    {
        if (plog)
            plog->LogError("Loader read failed - file does not start with a SWF header");
        return 0;
    }
    if (((header >> 16) & 0xFF) == 'X')
        Header.SWFFlags |= MovieInfo::SWF_Stripped;
    if (compressed)
        Header.SWFFlags |= MovieInfo::SWF_Compressed;

    if (!plog || !pparseControl || !pparseControl->IsVerboseParse())
        parseMsg = false;

    if (parseMsg)
        plog->LogMessageByType(LogChannel_Parse | LogMessage_Text, "SWF File version = %d, File length = %d\n",
                               Header.Version, Header.FileLength);

    Ptr<File> pfileIn = pin;
    if (compressed)
    {
        if (!zlib)
        {
            if (plog)
                plog->LogError("Loader - unable to read compressed SWF data; GFxZlibState is not set.");
            return 0;
        }
        if (parseMsg)
            plog->LogMessageByType(LogChannel_Parse | LogMessage_Text, "SWF file is compressed.\n");

        pfileIn = *zlib->CreateZlibFile(pfileIn);
        // The 8 header bytes are not part of the compressed length.
        FileEndPos = Header.FileLength - 8;
    }

    Stream.Initialize(pfileIn, plog->GetLog(), pparseControl);

    Stream.ReadRect(&Header.FrameRect);
    Header.FPS        = Stream.ReadU16() / 256.0f;
    Header.FrameCount = Stream.ReadU16();

    if (Header.SWFFlags & MovieInfo::SWF_Stripped)
    {
        if ((UInt32)Stream.Tell() < FileEndPos)
        {
            if (Stream.OpenTag() == Tag_ExporterInfo)
            {
                Header.mExporterInfo.ReadExporterInfoTag(&Stream, Tag_ExporterInfo);
            }
            else
            {
                if (plog)
                    plog->LogError("Loader read failed - no mExporterInfo tag in GFX file header");
                return 0;
            }
            Stream.CloseTag();
        }

        // Skip the exporter tags up to the file attributes, then go back.
        if (Header.Version >= 9 && (UInt32)Stream.Tell() < FileEndPos)
        {
            int     off = Stream.Tell();
            TagInfo tagInfo;
            while (Stream.OpenTag(&tagInfo) >= Tag_GFX_TagTableBegin)
                Stream.CloseTag();
            if (tagInfo.TagType == Tag_FileAttributes)
                FileAttributes = Stream.ReadU16();
            Stream.CloseTag();
            Stream.SetPosition(off);
        }
    }
    else
    {
        if (Header.Version >= 9 && (UInt32)Stream.Tell() < FileEndPos)
        {
            TagInfo tagInfo;
            if (Stream.OpenTag(&tagInfo) == Tag_FileAttributes)
                FileAttributes = Stream.ReadU16();
            Stream.CloseTag();
            Stream.SetPosition(tagInfo.TagOffset);
        }
    }
    return 1;
}

// Tag 1000: exporter version (and flags from 1.10 on), image format, prefix and SWF name, and from 4.1 on the
// offsets of the code blocks.
// @0x1425ab9f0
void ExporterInfoImpl::ReadExporterInfoTag(Stream* pin, TagType tagType)
{
    UInt32 flags   = 0;
    UInt16 version = pin->ReadU16();
    if (version >= 0x10A)
        flags = pin->ReadU32();
    UInt16 bitmapFormat = pin->ReadU16();

    String prefix, swfName;
    pin->ReadStringWithLength(&prefix);
    pin->ReadStringWithLength(&swfName);

    Array<UInt32> codeOffsets;
    if (version >= 0x401)
    {
        UInt16 numCodeOffsets = pin->ReadU16();
        for (UInt16 i = 0; i < numCodeOffsets; i++)
            codeOffsets.PushBack(pin->ReadU32());
    }

    pin->LogParse("  ExportInfo: tagType = %d, tool ver = %d.%d, imgfmt = %d, prefix = '%s', swfname = '%s', "
                  "flags = 0x%X\n",
                  tagType, version >> 8, version & 0xFF, bitmapFormat, prefix.ToCStr(), swfName.ToCStr(), flags);

    SetData(version, (FileTypeConstants::FileFormatType)bitmapFormat, swfName.ToCStr(), prefix.ToCStr(), flags,
            &codeOffsets);
}

// @0x1425a8900
ExporterInfoImpl::~ExporterInfoImpl()
{
}

// @0x1425aaac0
Render::ImageFileFormat LoaderImpl::FileFormat2RenderImageFile(FileFormatType format)
{
    switch (format)
    {
    case File_TGA:  return Render::ImageFile_TGA;
    case File_DDS:  return Render::ImageFile_DDS;
    case File_JPEG: return Render::ImageFile_JPEG;
    case File_PNG:  return Render::ImageFile_PNG;
    case File_SIF:  return Render::ImageFile_SIF;
    case File_GXT:  return Render::ImageFile_GXT;
    case File_PVR:  return Render::ImageFile_PVR;
    default:
        return Render::ImageFile_Unknown;
    }
}

// @0x1425abfd0
void LoadProcess::SetBindProcess(MovieBindProcess* pbindProcess)
{
    pBindProcess = pbindProcess;
}

// Asian / prohibition rules go to the shared helper; hyphenation breaks after the last vowel that leaves room for
// the dash.
// @0x1425ab880
bool Translator::OnWordWrapping(LineFormatDesc* pdesc)
{
    if (WWMode == WWT_Default)
        return false;

    if ((WWMode & (WWT_Asian | WWT_NoHangulWrap | WWT_Prohibition)) && pdesc->NumCharsInLine > 0)
    {
        UPInt wordWrapPos = WordWrapHelper::FindWordWrapPos(WWMode, pdesc->ProposedWordWrapPoint, pdesc->pParaText,
                                                            pdesc->ParaTextLen, pdesc->LineStartPos,
                                                            pdesc->NumCharsInLine);
        if (wordWrapPos != SF_MAX_UPINT)
        {
            pdesc->ProposedWordWrapPoint = wordWrapPos;
            return true;
        }
        return false;
    }
    else if (WWMode & WWT_Hyphenation)
    {
        if (pdesc->ProposedWordWrapPoint == 0)
            return false;

        const wchar_t* pstr      = pdesc->pParaText + pdesc->LineStartPos;
        UPInt          hyphenPos = pdesc->NumCharsInLine;
        // Breaking at a space: search back to it only; otherwise to the line start.
        UPInt endPos = SFiswspace(pstr[pdesc->ProposedWordWrapPoint - 1]) ? pdesc->ProposedWordWrapPoint : 0;
        for (; hyphenPos > endPos; --hyphenPos)
        {
            if (WordWrapHelper::IsVowel(pstr[hyphenPos - 1]))
            {
                float lineW = pdesc->pWidths[hyphenPos - 1];
                lineW += pdesc->DashSymbolWidth;
                if (lineW < pdesc->VisibleRectWidth)
                {
                    pdesc->ProposedWordWrapPoint = hyphenPos;
                    pdesc->UseHyphenation        = true;
                    return true;
                }
            }
        }
    }
    return false;
}

// @0x1425ac160
void Translator::TranslateInfo::SetResult(const wchar_t* presultText, UPInt resultLen)
{
    if (!presultText)
        return;

    if (resultLen == SF_MAX_UPINT)
        resultLen = SFwcslen(presultText);
    pResult->Resize(resultLen + 1);
    SFwcsncpy(pResult->GetBuffer(), resultLen + 1, presultText, resultLen);
    Flags |= Flag_Translated;
}

// The buffer is sized in characters, the copy is bounded in bytes.
// @0x1425ac0f0
void Translator::TranslateInfo::SetResult(const char* presultTextUTF8, UPInt resultUTF8Len)
{
    if (!presultTextUTF8)
        return;

    if (resultUTF8Len == SF_MAX_UPINT)
        resultUTF8Len = strlen(presultTextUTF8);
    int nchars = (int)UTF8Util::GetLength(presultTextUTF8);
    pResult->Resize(nchars + 1);
    UTF8Util::DecodeString(pResult->GetBuffer(), presultTextUTF8, resultUTF8Len);
    Flags |= Flag_Translated;
}

// @0x1425ab800
template void LogBase<LogState>::LogError(const char* pfmt, ...) const;

}} // namespace Scaleform::GFx

// MS2-PIN: ??_GLoaderImpl@GFx@Scaleform@@UEAAPEAXI@Z 0x1425a8c80
// MS2-PIN: ??_GLoaderTask@GFx@Scaleform@@UEAAPEAXI@Z 0x1425a8df0
// MS2-PIN: ??_GMovieImageLoadTask@GFx@Scaleform@@UEAAPEAXI@Z 0x1425a8e50
// MS2-PIN: ??_GTask@GFx@Scaleform@@UEAAPEAXI@Z 0x1425a8ef0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1425a8bc0
// MS2-PIN: ??_G?$LogBase@VLoaderImpl@GFx@Scaleform@@@GFx@Scaleform@@UEAAPEAXI@Z 0x1425a8b90
// MS2-PIN: ??_7StateBag@GFx@Scaleform@@6B@ 0x143183208
// MS2-PIN: ??_7Task@GFx@Scaleform@@6B@ 0x143188d98
// MS2-PIN: ??_7?$RefCountBase@VTask@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143188dc8
// MS2-PIN: ??_7LoaderTask@GFx@Scaleform@@6B@ 0x143188db0
// MS2-PIN: ??_7MovieImageLoadTask@GFx@Scaleform@@6B@ 0x143188fa8
// MS2-PIN: ??_7?$RefCountBase@VLoaderImpl@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143188dc8
// MS2-PIN: ??_7?$LogBase@VLoaderImpl@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x143188dd0
// MS2-PIN: ??_7LoaderImpl@GFx@Scaleform@@6B?$RefCountBase@VLoaderImpl@GFx@Scaleform@@$01@2@@ 0x143188de0
// MS2-PIN: ??_7LoaderImpl@GFx@Scaleform@@6BStateBag@12@@ 0x143188de8
// MS2-PIN: ??_7LoaderImpl@GFx@Scaleform@@6B?$LogBase@VLoaderImpl@GFx@Scaleform@@@12@@ 0x143188e10
// MS2-PIN: ??_7?$RefCountBase@VStateBagImpl@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431835a8
// MS2-PIN: ??_7?$LogBase@VStateBagImpl@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431835b0
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6B?$RefCountBase@VStateBagImpl@GFx@Scaleform@@$01@2@@ 0x1431835c0
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6BStateBag@12@@ 0x1431835c8
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6B?$LogBase@VStateBagImpl@GFx@Scaleform@@@12@@ 0x1431835f0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
