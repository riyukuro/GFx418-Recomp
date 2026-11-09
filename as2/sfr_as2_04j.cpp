// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 load queue: the AddLoadQueueEntry
// family of MovieRoot, the loader-thread entries and tasks they start, package creation and the shared object loader.
// MS2-UNIT: sfr_as2_04j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292e880-0x14292ea43 .text$mn
// MS2-RANGE: 0x14292f960-0x14292fc83 .text$mn
// MS2-RANGE: 0x14292fc90-0x14292ff44 .text$mn
// MS2-RANGE: 0x142930090-0x1429301c5 .text$mn
// MS2-RANGE: 0x1429301d0-0x14293047b .text$mn
// MS2-RANGE: 0x142930480-0x142930692 .text$mn
// MS2-RANGE: 0x142930c30-0x142930db3 .text$mn
// MS2-RANGE: 0x142930dc0-0x142931131 .text$mn
// MS2-RANGE: 0x142931140-0x142931300 .text$mn
// MS2-RANGE: 0x14291c240-0x14291c314 .text$mn
// MS2-RANGE: 0x14291c400-0x14291c68f .text$mn
// MS2-RANGE: 0x14291c690-0x14291c909 .text$mn
// MS2-RANGE: 0x14291c910-0x14291cba8 .text$mn
// MS2-RANGE: 0x14291cbb0-0x14291cc84 .text$mn

#include <string.h>
#include <stdlib.h>
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_std.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_playertasks.h"

void FUN_14257dc30(void* p);  // RefCountImpl::AddRef (a global FUN_ in the exe)
void FUN_14257dcb0(void* p);  // RefCountImpl::Release (a global FUN_ in the exe)

extern "C" void __cdecl __report_rangecheckfailure(void);
// MS2-PIN: ??_7?$RefCountBase@VTask@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143188dc8

namespace Scaleform { namespace GFx { namespace AS2 {

// Vftables of the loader-thread entries and file tasks (their members are only reached as raw words here).
// MS2-PIN: ??_7Task@GFx@Scaleform@@6B@ 0x143188d98
#ifdef MS2_HOOK_DLL
extern const void* DAT_143217750[]; // GFxAS2LoadQueueEntryMT_LoadMovie
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7GFxAS2LoadQueueEntryMT_LoadMovie@AS2@GFx@Scaleform@@6B@")[]; // GFxAS2LoadQueueEntryMT_LoadMovie
#define DAT_143217750 __identifier("??_7GFxAS2LoadQueueEntryMT_LoadMovie@AS2@GFx@Scaleform@@6B@")
#endif
extern const void* DAT_143217768[]; // XML file task
#ifdef MS2_HOOK_DLL
extern const void* DAT_143217780[]; // GFxAS2LoadQueueEntryMT_LoadXML
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7GFxAS2LoadQueueEntryMT_LoadXML@AS2@GFx@Scaleform@@6B@")[]; // GFxAS2LoadQueueEntryMT_LoadXML
#define DAT_143217780 __identifier("??_7GFxAS2LoadQueueEntryMT_LoadXML@AS2@GFx@Scaleform@@6B@")
#endif
extern const void* DAT_143217798[]; // CSS file task
#ifdef MS2_HOOK_DLL
extern const void* DAT_1432177b0[]; // GFxAS2LoadQueueEntryMT_LoadCSS
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7GFxAS2LoadQueueEntryMT_LoadCSS@AS2@GFx@Scaleform@@6B@")[]; // GFxAS2LoadQueueEntryMT_LoadCSS
#define DAT_1432177b0 __identifier("??_7GFxAS2LoadQueueEntryMT_LoadCSS@AS2@GFx@Scaleform@@6B@")
#endif

typedef GFxAS2LoadQueueEntry::HolderType HolderType;

// A file task: loader thread work of XML.load / StyleSheet.load. 0x40 bytes.
// The RefCountImplCore and Task constructors store their vftables before the task's own.
static SF_FORCEINLINE void* ConstructFileTask(void* self, const void** pvftable, LoadStates* pls,
                                              const String& level0Path, const String& url, const HolderType& holder)
{
    UPInt*          w  = static_cast<UPInt*>(self);
    volatile UPInt* vw = w;
    static_cast<Task*>(self)->Task::Task(Task::Id_MovieDataLoad);   // RefCount 1, TaskId 0x20001, CurrentState 0
    *reinterpret_cast<const void***>(self) = pvftable;
    (void)vw;
    //
    //
    //
    if (pls)
        FUN_14257dc30(pls);
    w[3] = reinterpret_cast<UPInt>(pls);
    new (w + 4) String(level0Path);
    new (w + 5) String(url);
    if (holder.Loader)
        FUN_14257dc30(holder.Loader.GetPtr());
    w[6]                           = reinterpret_cast<UPInt>(holder.Loader.GetPtr());
    *reinterpret_cast<unsigned*>(w + 7) = 0;
    return self;
}

// @0x14291c240
void* FUN_14291c240(void* self, LoadStates* pls, const String& level0Path, const String& url, HolderType holder)
{
    return ConstructFileTask(self, DAT_143217798, pls, level0Path, url, holder);
}

// @0x14291cbb0
void* FUN_14291cbb0(void* self, LoadStates* pls, const String& level0Path, const String& url, HolderType holder)
{
    return ConstructFileTask(self, DAT_143217768, pls, level0Path, url, holder);
}

// Hands a task to the task manager of the movie.
static SF_FORCEINLINE void StartTask(MovieImpl* pmovie, void* ptask)
{
    Ptr<TaskManager> ptm = *static_cast<TaskManager*>(pmovie->GetStateBag()->GetStateAddRef(State::State_TaskManager));
    ptm->AddTask(static_cast<Task*>(ptask));
}

// MovieRoot::GetLevel0Path through the AS2 root of the movie, inlined in the exe.
static SF_FORCEINLINE void GetEntryLevel0Path(MovieImpl* pmovie, String* ppath)
{
    MovieImpl* pmain = static_cast<MovieRoot*>(pmovie->pASMovieRoot)->pMovieImpl;
    for (unsigned i = 0; i < pmain->MovieLevelsSize; i++)
        if (pmain->pMovieLevels[i].Level == 0)
        {
            if (pmain->pMovieLevels[i].pSprite)
            {
                *ppath = ((MovieDef*)pmain->pMainMovieDef)->GetFileURL();
                if (URLBuilder::ExtractFilePath(ppath))
                    return;
            }
            break;
        }
    ppath->Clear();
}

// The file task of an entry, built over a copy of the holder of the entry.
static SF_FORCEINLINE void* ConstructEntryTask(void* self, const void** pvftable, LoadStates* pls,
                                               const String& level0Path, const String& url, HolderType holder)
{
    return ConstructFileTask(self, pvftable, pls, level0Path, url, holder);
}

// The file entries: the pLoadStates and the file task of the entry go in words 6 and 5.
// MS2-FUNCTIONAL: raw words over the entry; the task constructor is inlined with a copy of the holder
static void* ConstructFileEntry(void* self, const void** pvftable, LoadQueueEntry* pentry, MovieRoot* proot,
                                const void** ptaskVftable, UPInt taskSize, const HolderType& holder)
{
    UPInt* w = static_cast<UPInt*>(self);
    static_cast<LoadQueueEntryMT*>(self)->LoadQueueEntryMT::LoadQueueEntryMT(pentry, proot->pMovieImpl);
    w[0] = reinterpret_cast<UPInt>(pvftable);
    w[5] = 0;
    w[6] = 0;
    return w;
}

// The load states, the level-0 path, the task and the task start are all inlined in the exe, and each use re-reads
// the movie from word 3.
// MS2-FUNCTIONAL: raw words over the entry; the exe keeps the holder copy's Loader in rdi with a 0x60 frame; register
// choice differs
// @0x14291c400
void* FUN_14291c400(void* self, LoadQueueEntry* pentry, MovieRoot* proot)
{
    UPInt*           w     = static_cast<UPInt*>(self);
    GFxAS2LoadQueueEntry* pas2 = static_cast<GFxAS2LoadQueueEntry*>(pentry);
    static_cast<LoadQueueEntryMT*>(self)->LoadQueueEntryMT::LoadQueueEntryMT(pentry, proot->pMovieImpl);
    w[0] = reinterpret_cast<UPInt>(DAT_1432177b0);
    w[5] = 0;
    w[6] = 0;
    LoadStates* pls = SF_NEW LoadStates(reinterpret_cast<MovieImpl*>(w[3])->pMainMovieDef->pLoaderImpl,
                                        reinterpret_cast<MovieImpl*>(w[3])->GetStateBag()->GetStateBagImpl());
    if (w[6])
        FUN_14257dcb0(reinterpret_cast<void*>(w[6]));
    w[6] = reinterpret_cast<UPInt>(pls);
    String level0Path;
    GetEntryLevel0Path(reinterpret_cast<MovieImpl*>(w[3]), &level0Path);
    void* ptask = 0;
    if (void* pmem = Memory::pGlobalHeap->Alloc(0x40))
        ptask = ConstructEntryTask(pmem, DAT_143217798, reinterpret_cast<LoadStates*>(w[6]), level0Path, pentry->URL, pas2->CSSHolder);
    if (w[5])
        FUN_14257dcb0(reinterpret_cast<void*>(w[5]));
    w[5] = reinterpret_cast<UPInt>(ptask);
    StartTask(reinterpret_cast<MovieImpl*>(w[3]), reinterpret_cast<void*>(w[5]));
    return self;
}

// The load states, the level-0 path, the task and the task start are all inlined in the exe, and each use re-reads
// the movie from word 3.
// MS2-FUNCTIONAL: raw words over the entry; the exe keeps the holder copy's Loader in rdi with a 0x60 frame; register
// choice differs
// @0x14291c910
void* FUN_14291c910(void* self, LoadQueueEntry* pentry, MovieRoot* proot)
{
    UPInt*           w     = static_cast<UPInt*>(self);
    GFxAS2LoadQueueEntry* pas2 = static_cast<GFxAS2LoadQueueEntry*>(pentry);
    static_cast<LoadQueueEntryMT*>(self)->LoadQueueEntryMT::LoadQueueEntryMT(pentry, proot->pMovieImpl);
    w[0] = reinterpret_cast<UPInt>(DAT_143217780);
    w[5] = 0;
    w[6] = 0;
    w[7] = reinterpret_cast<UPInt>(proot);
    LoadStates* pls = SF_NEW LoadStates(reinterpret_cast<MovieImpl*>(w[3])->pMainMovieDef->pLoaderImpl,
                                        reinterpret_cast<MovieImpl*>(w[3])->GetStateBag()->GetStateBagImpl());
    if (w[6])
        FUN_14257dcb0(reinterpret_cast<void*>(w[6]));
    w[6] = reinterpret_cast<UPInt>(pls);
    String level0Path;
    GetEntryLevel0Path(reinterpret_cast<MovieImpl*>(w[3]), &level0Path);
    void* ptask = 0;
    if (void* pmem = Memory::pGlobalHeap->Alloc(0x40))
        ptask = ConstructEntryTask(pmem, DAT_143217768, reinterpret_cast<LoadStates*>(w[6]), level0Path, pentry->URL, pas2->XMLHolder);
    if (w[5])
        FUN_14257dcb0(reinterpret_cast<void*>(w[5]));
    w[5] = reinterpret_cast<UPInt>(ptask);
    StartTask(reinterpret_cast<MovieImpl*>(w[3]), reinterpret_cast<void*>(w[5]));
    return self;
}

// MovieRoot::GetLevelMovie, inlined in the exe.
static SF_FORCEINLINE InteractiveObject* EntryLevelMovie(const MovieRoot* proot, int level)
{
    MovieImpl* pmovie = proot->pMovieImpl;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The movie load: a MoviePreloadTask reads the file while the movie polls LoadFinished. 0x58 bytes.
// MS2-FUNCTIONAL: scheduling only: the exe loads the queue entry (word 4) between the NewCharId and CharSwitched stores; ours loads it after the FirstFrameLoaded store
// @0x14291c690
void* FUN_14291c690(void* self, LoadQueueEntry* pentry, MovieImpl* pmovie)
{
    UPInt*                w    = static_cast<UPInt*>(self);
    UByte*                b    = static_cast<UByte*>(self);
    static_cast<LoadQueueEntryMT*>(self)->LoadQueueEntryMT::LoadQueueEntryMT(pentry, pmovie);
    w[0]                                    = reinterpret_cast<UPInt>(DAT_143217750);
    w[5]                                    = 0;
    w[6]                                    = 0;
    w[8]                                    = 0;
    *reinterpret_cast<unsigned*>(b + 0x48)  = 0x10001;
    b[0x4c]                                 = 0;
    *reinterpret_cast<unsigned*>(b + 0x50)  = 0;
    b[0x54]                                 = 0;
    bool stripped = false;
    GFxAS2LoadQueueEntry* pas2 = reinterpret_cast<GFxAS2LoadQueueEntry*>(w[4]);
    if (pas2->pCharacter)
    {
        Ptr<DisplayObject> poldChar = pas2->pCharacter->ResolveCharacter(reinterpret_cast<MovieImpl*>(w[3]));
        if (poldChar)
            stripped = (poldChar->GetResourceMovieDef()->GetSWFFlags() >> 4 & 1) != 0;
    }
    else if (pas2->Level != -1)
    {
        const MovieRoot* as2mr = static_cast<MovieRoot*>(reinterpret_cast<MovieImpl*>(w[3])->pASMovieRoot);
        if (EntryLevelMovie(as2mr, pas2->Level))
            stripped = (EntryLevelMovie(as2mr, pas2->Level)->GetResourceMovieDef()->GetSWFFlags() >> 4 & 1) != 0;
        else if (EntryLevelMovie(as2mr, 0))
            stripped = (EntryLevelMovie(as2mr, 0)->GetResourceMovieDef()->GetSWFFlags() >> 4 & 1) != 0;
    }
    MoviePreloadTask* ptask = 0;
    if (void* pmem = Memory::pGlobalHeap->Alloc(0x50))
        ptask = ::new (pmem) MoviePreloadTask(reinterpret_cast<MovieImpl*>(w[3]), pas2->URL, stripped, pentry->QuietOpen);
    // The SDK: pPreloadTask = *SF_NEW ...; GetTaskManager()->AddTask(pPreloadTask), with the task re-read after the call.
    reinterpret_cast<Ptr<MoviePreloadTask>&>(w[5]) = *ptask;
    Ptr<TaskManager> ptm = *static_cast<TaskManager*>(
        reinterpret_cast<MovieImpl*>(w[3])->GetStateBag()->GetStateAddRef(State::State_TaskManager));
    ptm->AddTask(reinterpret_cast<Task*>(w[5]));
    return self;
}

// Hands the load to the loader thread entry of its kind and cancels the pending entries it replaces.
// @0x14292fc90
void MovieRoot::AddLoadQueueEntryMT(LoadQueueEntry* pentry)
{
    LoadQueueEntryMT* pentryMT = NULL;
    if (pentry->Type & LoadQueueEntry::LTF_VarsFlag)
    {
        pentryMT = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntryMT_LoadVars(pentry, pMovieImpl);
    }
    else if (pentry->Type & LoadQueueEntry::LTF_XMLFlag)
    {
        if (pentry->URL.GetLength())
        {
            void* pmem = pMovieImpl->GetMovieHeap()->Alloc(0x40);
            pentryMT   = pmem ? static_cast<LoadQueueEntryMT*>(FUN_14291c910(pmem, pentry, this)) : 0;
            GFxAS2LoadQueueEntry* as2entry = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            if (pentryMT && as2entry->XMLHolder.ASObj.ToObject(NULL))
            {
                Object*           pxmlobj = as2entry->XMLHolder.ASObj.ToObject(NULL);
                LoadQueueEntryMT* ptail   = pMovieImpl->pLoadQueueMTHead;
                while (ptail)
                {
                    GFxAS2LoadQueueEntry* as2tail = static_cast<GFxAS2LoadQueueEntry*>(ptail->GetQueueEntry());
                    if (!as2tail->XMLHolder.ASObj.IsUndefined() && pxmlobj == as2tail->XMLHolder.ASObj.ToObject(0))
                        as2tail->Canceled = true;
                    ptail = ptail->GetNext();
                }
            }
        }
    }
    else if (pentry->Type & LoadQueueEntry::LTF_CSSFlag)
    {
        if (pentry->URL.GetLength())
        {
            void* pmem = pMovieImpl->GetMovieHeap()->Alloc(0x38);
            pentryMT   = pmem ? static_cast<LoadQueueEntryMT*>(FUN_14291c400(pmem, pentry, this)) : 0;
            GFxAS2LoadQueueEntry* as2entry = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            if (pentryMT && as2entry->CSSHolder.ASObj.ToObject(NULL))
            {
                Object*           pxmlobj = as2entry->CSSHolder.ASObj.ToObject(NULL);
                LoadQueueEntryMT* ptail   = pMovieImpl->pLoadQueueMTHead;
                while (ptail)
                {
                    GFxAS2LoadQueueEntry* as2tail = static_cast<GFxAS2LoadQueueEntry*>(ptail->GetQueueEntry());
                    if (!as2tail->CSSHolder.ASObj.IsUndefined() && pxmlobj == as2tail->CSSHolder.ASObj.ToObject(0))
                        as2tail->Canceled = true;
                    ptail = ptail->GetNext();
                }
            }
        }
    }
    else
    {
        void* pmem = pMovieImpl->GetMovieHeap()->Alloc(0x58);
        pentryMT   = pmem ? static_cast<LoadQueueEntryMT*>(FUN_14291c690(pmem, pentry, pMovieImpl)) : 0;
        if (pentryMT)
        {
            GFxAS2LoadQueueEntry* as2entry = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            LoadQueueEntryMT*     ptail    = pMovieImpl->pLoadQueueMTHead;
            while (ptail)
            {
                GFxAS2LoadQueueEntry* as2tail = static_cast<GFxAS2LoadQueueEntry*>(ptail->GetQueueEntry());
                if (as2entry->pCharacter)
                {
                    if (as2tail->pCharacter && as2tail->pCharacter->NamePath == as2entry->pCharacter->NamePath)
                        as2tail->Canceled = true;
                }
                else if (as2tail->Level != -1 && as2tail->Level == as2entry->Level)
                    as2tail->Canceled = true;
                ptail = ptail->GetNext();
            }
        }
    }
    if (!pentryMT)
    {
        delete pentry;
        return;
    }
    pMovieImpl->AddLoadQueueEntryMT(pentryMT);
}

// MovieRoot::GetLevelMovie, inlined in the exe.
static SF_FORCEINLINE InteractiveObject* LoadLevelMovie(const MovieRoot* proot, int level)
{
    MovieImpl* pmovie = proot->pMovieImpl;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// Appends the load to the queue of the movie, or hands it to the loader thread when the movie has a task manager.
static SF_FORCEINLINE void QueueLoad(MovieRoot* proot, LoadQueueEntry* pentry)
{
    if (Ptr<State>(*proot->pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager)))
        proot->AddLoadQueueEntryMT(pentry);
    else
        proot->pMovieImpl->AddLoadQueueEntry(pentry);
}

// Queues a style sheet load of purl into pstyleSheet, read by ploader.
// @0x14292e880
void MovieRoot::AddCssLoadQueueEntry(Object* pstyleSheet, ASCSSFileLoader* ploader, const char* purl,
                                     LoadQueueEntry::LoadMethod method)
{
    GFxAS2LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
        GFxAS2LoadQueueEntry(purl, method, false, false, LoadQueueEntry::InlineCtorTag());
    if (pentry)
    {
        pentry->Type = LoadQueueEntry::LT_LoadCSS;
        pentry->CSSHolder.ASObj.SetAsObject(pstyleSheet);
        pentry->CSSHolder.Loader = reinterpret_cast<RefCountImpl*>(ploader);
        QueueLoad(this, pentry);
    }
}

// Queues an XML load of purl into pxml, read by ploader.
// @0x142931140
void MovieRoot::AddXmlLoadQueueEntry(Object* pxml, XMLFileLoader* ploader, const char* purl,
                                     LoadQueueEntry::LoadMethod method)
{
    GFxAS2LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
        GFxAS2LoadQueueEntry(purl, method, false, false, LoadQueueEntry::InlineCtorTag());
    if (pentry)
    {
        pentry->Type = LoadQueueEntry::LT_LoadXML;
        pentry->XMLHolder.ASObj.SetAsObject(pxml);
        pentry->XMLHolder.Loader = reinterpret_cast<RefCountImpl*>(ploader);
        QueueLoad(this, pentry);
    }
}

// Queues a variables load of purl into a LoadVars object.
// @0x142930c30
void MovieRoot::AddVarLoadQueueEntry(LoadVarsObject* ploadVars, const char* purl, LoadQueueEntry::LoadMethod method)
{
    GFxAS2LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
        GFxAS2LoadQueueEntry(purl, method, true, false, LoadQueueEntry::InlineCtorTag());
    if (pentry)
    {
        pentry->LoadVarsHolder.SetAsObject(reinterpret_cast<Object*>(ploadVars));
        QueueLoad(this, pentry);
    }
}

// Queues a load of purl into the clip or level named ptargetName.
// MS2-FUNCTIONAL: register allocation (the exe gives the penv arm's name string the first slot and keeps it in rbx)
// @0x14292f960
void MovieRoot::AddLoadQueueEntry(const char* ptargetName, const char* purl, Environment* penv,
                                  LoadQueueEntry::LoadMethod method, MovieClipLoader* pmovieClipLoader)
{
    GFxAS2LoadQueueEntry* pentry  = 0;
    int                   level   = -1;
    InteractiveObject*    ptarget = penv ? penv->FindTarget(BuiltinsMgr.CreateString(ptargetName), 0)
                                         : FindTarget(BuiltinsMgr.CreateString(ptargetName));
    Sprite*               psprite = ptarget ? (ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0) : 0;
    if (psprite && (level = static_cast<AvmSpriteBase&>(*AvmSprite::FromSprite(psprite)).GetLevel()) != -1)
        ptarget = 0;
    if (ptarget)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), purl, method, false, false,
                                 LoadQueueEntry::InlineCtorTag());
    else
    {
        if (level == -1)
        {
            const char* ptail = "";
            level = ParseLevelName(ptargetName, &ptail, LoadLevelMovie(this, 0)->GetVersion() > 6);
            if (*ptail != 0)
                level = -1;
        }
        if (level != -1)
            pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) GFxAS2LoadQueueEntry(level, purl, method);
    }
    if (pentry)
    {
        pentry->MovieClipLoaderHolder.SetAsObject(reinterpret_cast<Object*>(pmovieClipLoader));
        AddMovieLoadQueueEntry(pentry);
    }
}

// Queues a variables load of purl into the clip or level named ptargetName.
// @0x142930dc0
void MovieRoot::AddVarLoadQueueEntry(const char* ptargetName, const char* purl, LoadQueueEntry::LoadMethod method)
{
    GFxAS2LoadQueueEntry* pentry  = 0;
    int                   level   = -1;
    InteractiveObject*    ptarget = FindTarget(BuiltinsMgr.CreateString(ptargetName));
    Sprite*               psprite = ptarget ? (ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0) : 0;
    if (psprite && (level = static_cast<AvmSpriteBase&>(*AvmSprite::FromSprite(psprite)).GetLevel()) != -1)
        ptarget = 0;
    if (ptarget)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), purl, method, true, false,
                                 LoadQueueEntry::InlineCtorTag());
    else
    {
        if (level == -1)
        {
            const char* ptail = "";
            level = ParseLevelName(ptargetName, &ptail, LoadLevelMovie(this, 0)->GetVersion() > 6);
            if (*ptail != 0)
                level = -1;
        }
        if (level != -1)
            pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
                GFxAS2LoadQueueEntry(level, purl, method, true, false, LoadQueueEntry::InlineCtorTag());
    }
    if (pentry)
        QueueLoad(this, pentry);
}

// A movie load goes to the image decoder at once when its url is a synchronous protocol image, to the loader
// thread when the movie has a task manager, else into the queue of the movie.
// The exe calls this out of line from AddLoadQueueEntry.
// @0x142930090
SF_NOINLINE void MovieRoot::AddMovieLoadQueueEntry(LoadQueueEntry* pentry)
{
    if (!pentry)
        return;
    bool sync;
    bool isImage = LoaderImpl::IsProtocolImage(pentry->URL, 0, &sync);
    if (isImage && sync)
    {
        Ptr<LoadStates> pls = *SF_NEW LoadStates(pMovieImpl->pMainMovieDef->pLoaderImpl,
                                                 pMovieImpl->GetStateBag()->GetStateBagImpl());
        ProcessLoadQueueEntry(pentry, pls);
        delete pentry;
        return;
    }
    if (pentry->URL.GetLength() > 0 && !isImage && pMovieImpl->GetStateBag()->GetTaskManager())
        AddLoadQueueEntryMT(pentry);
    else
        pMovieImpl->AddLoadQueueEntry(pentry);
}

// Rebuilds a value of the shared object and puts it in the object or array on top of the stack.
// @0x142930480
void GASSharedObjectLoader::AddProperty(const String& name, const String& value, GFx::Value::ValueType type)
{
    Object* ptop = ObjectStack.Back();
    Value   v;
    switch (type)
    {
    case GFx::Value::VT_Number:
        v.SetNumber(atof(value.ToCStr()));
        break;
    case GFx::Value::VT_String:
        v.SetString(pEnv->CreateString(value));
        break;
    case GFx::Value::VT_Boolean:
        v.SetBool(!strncmp(value.ToCStr(), "true", 4));
        break;
    case GFx::Value::VT_Undefined:
        v.SetUndefined();
        break;
    case GFx::Value::VT_Null:
        v.SetNull();
        break;
    default:;
    }
    if (bArrayIsTop)
        static_cast<ArrayObject*>(ptop)->PushBack(v);
    else
        ptop->SetMember(pEnv, pEnv->CreateString(name), v);
}

// Creates the objects of a dotted package path under pparent and returns the last one.
// @0x1429301d0
Object* GlobalContext::AddPackage(ASStringContext* psc, Object* pparent, Object* objProto, const char* const packageName)
{
    char        buf[256];
    UPInt       nameSz = strlen(packageName) + 1;
    const char* pname  = packageName;
    Ptr<Object> parent = pparent;

    while (pname)
    {
        const char* p = strchr(pname, '.');
        UPInt       sz;
        if (p)
            sz = p++ - pname + 1;
        else
            sz = nameSz - (pname - packageName);

        if (sz > sizeof(buf))
            sz = sizeof(buf);

        memcpy(buf, pname, sz - 1);
        buf[sz - 1] = '\0';

        pname = p;

        Value       pkgObjVal;
        Ptr<Object> pkgObj;
        ASString    memberName(psc->CreateString(buf));

        if (parent->GetMemberRaw(psc, memberName, &pkgObjVal))
        {
            pkgObj = pkgObjVal.ToObject(NULL);
        }
        else
        {
            pkgObj = *SF_HEAP_NEW(psc->GetHeap()) Object(psc, objProto);
            parent->SetMemberRaw(psc, memberName, Value(pkgObj.GetPtr()));
        }
        parent = pkgObj;
    }
    return parent;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7GFxAS2LoadQueueEntry@AS2@GFx@Scaleform@@6B@ 0x143217748
