// Recovered Scaleform 4.1.18 GFx: queued movie load requests (loadMovie / unloadMovie / loadVariables).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Only the request kinds are recovered so far.
#ifndef MS2_SF_GFX_PLAYERTASKS_H
#define MS2_SF_GFX_PLAYERTASKS_H

#include "../kernel/sf_string.h"
#include "../kernel/sf_array.h"
#include "gfx_taskmanager.h"

namespace Scaleform { namespace GFx {

class MovieImpl;
class MovieDefImpl;
class LoadStates;

// One queued load / unload request of the movie (0x28 bytes, StatMV_Other_Mem).
class LoadQueueEntry : public NewOverrideBase<327>
{
    friend class MovieImpl;

    LoadQueueEntry* pNext; // +0x08

public:
    // How the variables of the requesting clip go along with the request.
    enum LoadMethod
    {
        LM_None,
        LM_Get,
        LM_Post
    };

    // (sfr_gfx_07f) what the request does: flag bits.
    enum LoadTypeFlags
    {
        LTF_None       = 0x00,
        LTF_UnloadFlag = 0x01,
        LTF_LevelFlag  = 0x02,
        LTF_VarsFlag   = 0x04,
        LTF_XMLFlag    = 0x08,
        LTF_CSSFlag    = 0x10,
        LTF_BinaryFlag = 0x20
    };
    enum LoadType
    {
        LT_LoadMovie   = LTF_None,
        LT_UnloadMovie = LTF_UnloadFlag,
        LT_LoadLevel   = LTF_LevelFlag,
        LT_UnloadLevel = LTF_UnloadFlag | LTF_LevelFlag,
        LT_LoadXML     = LTF_XMLFlag,
        LT_LoadCSS     = LTF_CSSFlag,
        LT_LoadText    = LTF_VarsFlag,
        LT_LoadBinary  = LTF_BinaryFlag
    };

    LoadType   Type;      // +0x10
    LoadMethod Method;    // +0x14
    String     URL;       // +0x18
    UInt32     EntryTime; // +0x20
    bool       QuietOpen; // +0x24
    bool       Canceled;  // +0x25

    // A load of url (an unload when it is empty), or a variables load (exe 0x14291dcf0).
    LoadQueueEntry(const String& url, LoadMethod method, bool loadingVars, bool quietOpen);
    virtual ~LoadQueueEntry() {}

    LoadQueueEntry* GetNext() const { return pNext; }
};

// A request whose file is read by a task on a loader thread; the movie polls LoadFinished (0x28 bytes,
// StatMV_Other_Mem).
class LoadQueueEntryMT : public NewOverrideBase<327>
{
protected:
    friend class MovieImpl;

    LoadQueueEntryMT* pNext;       // +0x08
    LoadQueueEntryMT* pPrev;       // +0x10
    MovieImpl*        pMovieImpl;  // +0x18
    LoadQueueEntry*   pQueueEntry; // +0x20 owned

public:
    LoadQueueEntryMT(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl);
    virtual ~LoadQueueEntryMT();

    void Cancel();

    // True once the request is done (its result handed to the movie) or dropped.
    virtual bool LoadFinished() = 0;
    virtual bool IsPreloadingFinished() { return true; }

    LoadQueueEntry*   GetQueueEntry() const { return pQueueEntry; }
    LoadQueueEntryMT* GetNext() const       { return pNext; }
    LoadQueueEntryMT* GetPrev() const       { return pPrev; }
};

// Loads a movie ahead of a loadMovie request; a stripped player tries the ".gfx" name of a ".swf" URL first
// (0x50 bytes).
class MoviePreloadTask : public Task
{
public:
    MoviePreloadTask(MovieImpl* pmovieImpl, const String& url, bool stripped, bool quietOpen);

    virtual void Execute();

    MovieDefImpl* GetMoiveDefImpl();
    bool          IsDone() const;

private:
    Ptr<LoadStates>   pLoadStates; // +0x18
    unsigned          LoadFlags;   // +0x20
    String            Level0Path;  // +0x28
    String            Url;         // +0x30
    String            UrlStrGfx;   // +0x38
    Ptr<MovieDefImpl> pDefImpl;    // +0x40
    volatile unsigned Done;        // +0x48
};

// Reads the text of a loadVariables request (0x48 bytes).
class LoadVarsTask : public Task
{
public:
    LoadVarsTask(LoadStates* pls, const String& level0Path, const String& url);

    virtual void Execute();

    // False while the task runs; then the text, the file length and whether the read worked.
    bool GetData(String* data, int* fileLen, bool* succeeded) const;

private:
    Ptr<LoadStates>   pLoadStates; // +0x18
    String            Level0Path;  // +0x20
    String            Url;         // +0x28
    String            Data;        // +0x30
    int               FileLen;     // +0x38
    volatile unsigned Done;        // +0x3c
    bool              Succeeded;   // +0x40
};

// A loadVariables request (0x38 bytes).
class LoadQueueEntryMT_LoadVars : public LoadQueueEntryMT
{
    Ptr<LoadVarsTask> pTask;       // +0x28
    Ptr<LoadStates>   pLoadStates; // +0x30

public:
    LoadQueueEntryMT_LoadVars(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl);
    ~LoadQueueEntryMT_LoadVars();

    bool LoadFinished();
};

// Reads the bytes of a loadBinary request (0x58 bytes).
class LoadBinaryTask : public Task
{
public:
    LoadBinaryTask(LoadStates* pls, const String& level0Path, const String& url);

    virtual void Execute();

    bool GetData(ArrayPOD<UByte>* data, int* fileLen, bool* succeeded) const;

private:
    Ptr<LoadStates>   pLoadStates; // +0x18
    String            Level0Path;  // +0x20
    String            Url;         // +0x28
    ArrayPOD<UByte>   Data;        // +0x30
    int               FileLen;     // +0x48
    volatile unsigned Done;        // +0x4c
    bool              Succeeded;   // +0x50
};

// A loadBinary request (0x38 bytes).
class LoadQueueEntryMT_LoadBinary : public LoadQueueEntryMT
{
    Ptr<LoadBinaryTask> pTask;       // +0x28
    Ptr<LoadStates>     pLoadStates; // +0x30

public:
    LoadQueueEntryMT_LoadBinary(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl);
    ~LoadQueueEntryMT_LoadBinary();

    bool LoadFinished();
};

// url with a ".swf" ending replaced by ".gfx"; empty when it has no such ending.
String GetUrlStrGfx(const String& url);

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::LoadQueueEntryMT_LoadBinary) == 0x38, "LoadQueueEntryMT_LoadBinary size");
static_assert(sizeof(Scaleform::GFx::LoadQueueEntryMT_LoadVars) == 0x38, "LoadQueueEntryMT_LoadVars size");
static_assert(sizeof(Scaleform::GFx::MoviePreloadTask) == 0x50, "MoviePreloadTask size");

#endif
