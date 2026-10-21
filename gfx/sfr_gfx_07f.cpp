// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_PlayerTasks: the loader-thread
// side of loadMovie / loadVariables / loadBinary (the preload task, the file reading tasks and the queue entries
// the movie polls).
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426395f0-0x14263a9d0 .text$mn

// MS2-PIN: ??_7LoadQueueEntryMT@GFx@Scaleform@@6B@ 0x14318f690
// MS2-PIN: ??_7MoviePreloadTask@GFx@Scaleform@@6B@ 0x14318f6a8
// MS2-PIN: ??_7LoadVarsTask@GFx@Scaleform@@6B@ 0x14318f6c0
// MS2-PIN: ??_7LoadQueueEntryMT_LoadVars@GFx@Scaleform@@6B@ 0x14318f6d8
// MS2-PIN: ??_7LoadBinaryTask@GFx@Scaleform@@6B@ 0x14318f6f0
// MS2-PIN: ??_7LoadQueueEntryMT_LoadBinary@GFx@Scaleform@@6B@ 0x14318f708
// MS2-PIN: ??_7Task@GFx@Scaleform@@6B@ 0x143188d98
// MS2-PIN: ??_7?$RefCountBase@VTask@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143188dc8
// MS2-PIN: ??_GMoviePreloadTask@GFx@Scaleform@@UEAAPEAXI@Z 0x14263a180
// MS2-PIN: ??_GLoadVarsTask@GFx@Scaleform@@UEAAPEAXI@Z 0x14263a090
// MS2-PIN: ??_GLoadBinaryTask@GFx@Scaleform@@UEAAPEAXI@Z 0x142639df0
// MS2-PIN: ?IsPreloadingFinished@LoadQueueEntryMT@GFx@Scaleform@@UEAA_NXZ 0x14263a800

#include "../include/gfx/gfx_playertasks.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_displayobject.h"

#include <string.h>

namespace Scaleform { namespace GFx {

// The AVM root as the queue entries see it: the read data goes back through vftable slots 27 / 28.
class ASMovieRootLoadSink : public RefCountImpl
{
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;

public:
    virtual void ProcessLoadVarsMT(LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                   bool succeeded) = 0;                                                    // 27
    virtual void ProcessLoadBinaryMT(LoadQueueEntry* pentry, LoadStates* pls, const ArrayPOD<UByte>& data,
                                     UPInt fileLen, bool succeeded) = 0;                                   // 28
};

static inline ASMovieRootLoadSink* GetLoadSink(MovieImpl* pmovieImpl)
{
    return (ASMovieRootLoadSink*)pmovieImpl->pASMovieRoot;
}

// @0x14263a750
String GetUrlStrGfx(const String& url)
{
    String gfxUrl;
    if (url.GetSize() > 4 && String::CompareNoCase(url.ToCStr() + (url.GetSize() - 4), ".swf") == 0)
    {
        gfxUrl.Clear();
        gfxUrl.AppendString(url.ToCStr(), url.GetSize() - 4);
        gfxUrl += ".gfx";
    }
    return gfxUrl;
}

// ---------------------------------------------------------------------------------------------------------------------
// MoviePreloadTask

// MS2-FUNCTIONAL the exe loads the StateBag vftable straight from the movie (+0x10) before the loader pointer; the MovieImpl bases are placeholders here. The GetUrlStrGfx temporary's release tests (count - 1) == 0 in the exe
// @0x142639b20
MoviePreloadTask::MoviePreloadTask(MovieImpl* pmovieImpl, const String& url, bool stripped, bool quietOpen)
    : Task(Task::Id_MovieDataLoad), Url(url), Done(0)
{
    pLoadStates = *new LoadStates(pmovieImpl->pMainMovieDef->pLoaderImpl, pmovieImpl->GetStateBag()->GetStateBagImpl());
    LoadFlags   = pmovieImpl->pMainMovieDef->GetLoadFlags() | Loader::LoadImageFiles;
    LoadFlags  &= ~(Loader::LoadWaitFrame1 | Loader::LoadWaitCompletion);
    if (quietOpen)
        LoadFlags |= Loader::LoadQuietOpen;
    pmovieImpl->GetMainMoviePath(&Level0Path);
    if (stripped)
        UrlStrGfx = GetUrlStrGfx(Url);
}

// The ".gfx" name first, then the URL as given.
// @0x14263a4b0
void MoviePreloadTask::Execute()
{
    if (UrlStrGfx.GetLength() > 0)
    {
        URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, UrlStrGfx, Level0Path);
        pDefImpl = *LoaderImpl::CreateMovie_LoadState(pLoadStates, loc, LoadFlags);
    }
    if (!pDefImpl)
    {
        URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, Url, Level0Path);
        pDefImpl = *LoaderImpl::CreateMovie_LoadState(pLoadStates, loc, LoadFlags);
    }
    Done = 1;
}

// @0x14263a7f0
bool MoviePreloadTask::IsDone() const
{
    unsigned done = Done;
    return done == 1;
}

// @0x14263a740
MovieDefImpl* MoviePreloadTask::GetMoiveDefImpl()
{
    return pDefImpl;
}

// ---------------------------------------------------------------------------------------------------------------------
// LoadQueueEntryMT

// @0x1426396b0
LoadQueueEntryMT::LoadQueueEntryMT(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl)
    : pNext(0), pPrev(0), pMovieImpl(pmovieImpl), pQueueEntry(pqueueEntry)
{
}

// @0x142639d10
LoadQueueEntryMT::~LoadQueueEntryMT()
{
    delete pQueueEntry;
}

// @0x14263a280
void LoadQueueEntryMT::Cancel()
{
    pQueueEntry->Canceled = true;
}

// ---------------------------------------------------------------------------------------------------------------------
// loadVariables

// @0x142639a70
LoadVarsTask::LoadVarsTask(LoadStates* pls, const String& level0Path, const String& url)
    : Task(Task::Id_MovieDataLoad), pLoadStates(pls), Level0Path(level0Path), Url(url), FileLen(0), Done(0),
      Succeeded(false)
{
}

// @0x14263a3a0
void LoadVarsTask::Execute()
{
    URLBuilder::LocationInfo loc(URLBuilder::File_LoadVars, Url, Level0Path);
    String                   fileName;
    pLoadStates->BuildURL(&fileName, loc);

    Ptr<File> pfile;
    pfile = *pLoadStates->OpenFile(fileName.ToCStr(), 0);
    if (pfile)
        Succeeded = MovieImpl::ReadTextData(&Data, pfile, &FileLen, false);
    else
        Succeeded = false;
    Done = 1;
}

// @0x14263a6e0
bool LoadVarsTask::GetData(String* data, int* fileLen, bool* succeeded) const
{
    unsigned done = Done;
    if (done != 1)
        return false;
    *data      = Data;
    *fileLen   = FileLen;
    *succeeded = Succeeded;
    return true;
}

// MS2-FUNCTIONAL the exe loads the movie's StateBag vftable before pMainMovieDef->pLoaderImpl (MovieImpl bases are placeholders)
// @0x1426398a0
LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl)
    : LoadQueueEntryMT(pqueueEntry, pmovieImpl)
{
    pLoadStates = *new LoadStates(pMovieImpl->pMainMovieDef->pLoaderImpl, pMovieImpl->GetStateBag()->GetStateBagImpl());
    String level0Path;
    pMovieImpl->GetMainMoviePath(&level0Path);
    pTask = *SF_NEW LoadVarsTask(pLoadStates, level0Path, pqueueEntry->URL);
    Ptr<TaskManager> ptaskManager = *(TaskManager*)pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager);
    ptaskManager->AddTask(pTask);
}

// @0x142639d90
LoadQueueEntryMT_LoadVars::~LoadQueueEntryMT_LoadVars()
{
}

// A canceled request still waits for its task before it goes.
// @0x14263a900
bool LoadQueueEntryMT_LoadVars::LoadFinished()
{
    String data;
    int    fileLen;
    bool   succeeded;

    bool taskDone = pTask->GetData(&data, &fileLen, &succeeded);
    if (pQueueEntry->Canceled && taskDone)
        return true;
    if (!taskDone)
        return false;
    GetLoadSink(pMovieImpl)->ProcessLoadVarsMT(pQueueEntry, pLoadStates, data, fileLen, succeeded);
    return true;
}

// ---------------------------------------------------------------------------------------------------------------------
// loadBinary

// @0x1426395f0
LoadBinaryTask::LoadBinaryTask(LoadStates* pls, const String& level0Path, const String& url)
    : Task(Task::Id_MovieDataLoad), pLoadStates(pls), Level0Path(level0Path), Url(url), FileLen(0), Done(0),
      Succeeded(false)
{
}

// @0x14263a290
void LoadBinaryTask::Execute()
{
    URLBuilder::LocationInfo loc(URLBuilder::File_LoadVars, Url, Level0Path);
    String                   fileName;
    pLoadStates->BuildURL(&fileName, loc);

    Ptr<File> pfile;
    pfile = *pLoadStates->OpenFile(fileName.ToCStr(), 0);
    if (pfile)
        Succeeded = MovieImpl::ReadBinaryData(&Data, pfile, &FileLen);
    else
        Succeeded = false;
    Done = 1;
}

// @0x14263a630
bool LoadBinaryTask::GetData(ArrayPOD<UByte>* data, int* fileLen, bool* succeeded) const
{
    unsigned done = Done;
    if (done != 1)
        return false;
    data->Resize(Data.GetSize());
    memcpy(data->GetDataPtr(), Data.GetDataPtr(), Data.GetSize());
    *fileLen   = FileLen;
    *succeeded = Succeeded;
    return true;
}

// MS2-FUNCTIONAL the exe loads the movie's StateBag vftable before pMainMovieDef->pLoaderImpl (MovieImpl bases are placeholders)
// @0x1426396d0
LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl)
    : LoadQueueEntryMT(pqueueEntry, pmovieImpl)
{
    pLoadStates = *new LoadStates(pMovieImpl->pMainMovieDef->pLoaderImpl, pMovieImpl->GetStateBag()->GetStateBagImpl());
    String level0Path;
    pMovieImpl->GetMainMoviePath(&level0Path);
    pTask = *SF_NEW LoadBinaryTask(pLoadStates, level0Path, pqueueEntry->URL);
    Ptr<TaskManager> ptaskManager = *(TaskManager*)pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager);
    ptaskManager->AddTask(pTask);
}

// @0x142639d30
LoadQueueEntryMT_LoadBinary::~LoadQueueEntryMT_LoadBinary()
{
}

// @0x14263a810
bool LoadQueueEntryMT_LoadBinary::LoadFinished()
{
    ArrayPOD<UByte> data;
    int             fileLen;
    bool            succeeded;

    bool taskDone = pTask->GetData(&data, &fileLen, &succeeded);
    if (pQueueEntry->Canceled && taskDone)
        return true;
    if (!taskDone)
        return false;
    GetLoadSink(pMovieImpl)->ProcessLoadBinaryMT(pQueueEntry, pLoadStates, data, fileLen, succeeded);
    return true;
}

}} // namespace Scaleform::GFx

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GLoadQueueEntryMT_LoadBinary@GFx@Scaleform@@UEAAPEAXI@Z 0x142639f50 ; prop
// MS2-PIN: ??_GLoadQueueEntryMT_LoadVars@GFx@Scaleform@@UEAAPEAXI@Z 0x142639ff0 ; prop
// MS2-PINS-END tplpin
