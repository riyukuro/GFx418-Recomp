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

void FUN_14257dc30(void* p);  // RefCountImpl::AddRef (a global FUN_ in the exe)
void FUN_14257dcb0(void* p);  // RefCountImpl::Release (a global FUN_ in the exe)

extern "C" void __cdecl __report_rangecheckfailure(void);
extern char DAT_142dc9d48[]; // RefCountImplCore vftable

namespace Scaleform { namespace GFx { namespace AS2 {

// Vftables of the loader-thread entries and file tasks (their members are only reached as raw words here).
extern const void* DAT_143188d98[]; // Task
extern const void* DAT_143217750[]; // GFxAS2LoadQueueEntryMT_LoadMovie
extern const void* DAT_143217768[]; // XML file task
extern const void* DAT_143217780[]; // GFxAS2LoadQueueEntryMT_LoadXML
extern const void* DAT_143217798[]; // CSS file task
extern const void* DAT_1432177b0[]; // GFxAS2LoadQueueEntryMT_LoadCSS

void FUN_1426396b0(void* self, LoadQueueEntry* pentry, MovieImpl* pmovie); // LoadQueueEntryMT::LoadQueueEntryMT

typedef GFxAS2LoadQueueEntry::HolderType HolderType;

// A file task: loader thread work of XML.load / StyleSheet.load. 0x40 bytes.
// The RefCountImplCore and Task constructors store their vftables before the task's own.
static SF_FORCEINLINE void* ConstructFileTask(void* self, const void** pvftable, LoadStates* pls,
                                              const String& level0Path, const String& url, const HolderType& holder)
{
    UPInt*          w  = static_cast<UPInt*>(self);
    volatile UPInt* vw = w;
    vw[0]                                        = reinterpret_cast<UPInt>(DAT_142dc9d48);
    vw[0]                                        = reinterpret_cast<UPInt>(DAT_143188d98);
    *reinterpret_cast<volatile unsigned*>(w + 1) = 1; // RefCount
    *reinterpret_cast<unsigned*>(w + 2)          = 0x20001;
    vw[0]                                        = reinterpret_cast<UPInt>(pvftable);
    *reinterpret_cast<volatile unsigned*>(reinterpret_cast<UByte*>(w) + 0x14) = 0; // CurrentState
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
    FUN_1426396b0(self, pentry, proot->pMovieImpl);
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
    FUN_1426396b0(self, pentry, proot->pMovieImpl);
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
    FUN_1426396b0(self, pentry, proot->pMovieImpl);
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

// The movie of a level or of _level0 when the level has none, the loader asks whether its file is stripped.
static InteractiveObject* GetLevelOrLevel0(const MovieImpl* pmovie, int level)
{
    InteractiveObject* plevel0 = 0;
    InteractiveObject* pfound  = 0;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
        if (pmovie->pMovieLevels[i].Level == level)
        {
            pfound = pmovie->pMovieLevels[i].pSprite;
            break;
        }
    if (pfound)
        return pfound;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
        if (pmovie->pMovieLevels[i].Level == 0)
        {
            plevel0 = pmovie->pMovieLevels[i].pSprite;
            break;
        }
    return plevel0;
}

// The movie load: a MoviePreloadTask reads the file while the movie polls LoadFinished. 0x58 bytes.
// MS2-FUNCTIONAL: raw words over the entry (the exe reads the level movies with its own loops)
// @0x14291c690
void* FUN_14291c690(void* self, LoadQueueEntry* pentry, MovieImpl* pmovie)
{
    UPInt*                w    = static_cast<UPInt*>(self);
    UByte*                b    = static_cast<UByte*>(self);
    GFxAS2LoadQueueEntry* pas2 = static_cast<GFxAS2LoadQueueEntry*>(pentry);
    FUN_1426396b0(self, pentry, pmovie);
    w[0]                                    = reinterpret_cast<UPInt>(DAT_143217750);
    w[5]                                    = 0;
    w[6]                                    = 0;
    w[8]                                    = 0;
    *reinterpret_cast<unsigned*>(b + 0x48)  = 0x10001;
    b[0x4c]                                 = 0;
    *reinterpret_cast<unsigned*>(b + 0x50)  = 0;
    b[0x54]                                 = 0;
    bool stripped = false;
    if (CharacterHandle* pchar = pas2->pCharacter)
    {
        if (DisplayObject* pch = pchar->ResolveCharacter(pmovie))
        {
            Ptr<DisplayObject> pholder = pch;
            stripped                   = (pch->GetResourceMovieDef()->GetSWFFlags() >> 4 & 1) != 0;
        }
    }
    else if (pas2->Level != -1)
    {
        if (InteractiveObject* pmain = GetLevelOrLevel0(pmovie, pas2->Level))
            stripped = (pmain->GetResourceMovieDef()->GetSWFFlags() >> 4 & 1) != 0;
    }
    MoviePreloadTask* ptask = 0;
    if (void* pmem = Memory::pGlobalHeap->Alloc(0x50))
        ptask = ::new (pmem) MoviePreloadTask(pmovie, pentry->URL, stripped, pentry->QuietOpen);
    if (w[5])
        FUN_14257dcb0(reinterpret_cast<void*>(w[5]));
    w[5] = reinterpret_cast<UPInt>(ptask);
    StartTask(pmovie, ptask);
    return self;
}

// Hands the load to the loader thread entry of its kind and cancels the pending entries it replaces.
// MS2-FUNCTIONAL: the entry constructors are the raw FUN_ functions above (no recovered classes)
// @0x14292fc90
void MovieRoot::AddLoadQueueEntryMT(LoadQueueEntry* pentry)
{
    MemoryHeap*           pheap = pMovieImpl->GetMovieHeap();
    LoadQueueEntryMT*     pentryMT = 0;
    GFxAS2LoadQueueEntry* pas2     = static_cast<GFxAS2LoadQueueEntry*>(pentry);
    if (pentry->Type & LoadQueueEntry::LTF_VarsFlag)
        pentryMT = SF_HEAP_NEW(pheap) LoadQueueEntryMT_LoadVars(pentry, pMovieImpl);
    else if (pentry->Type & LoadQueueEntry::LTF_XMLFlag)
    {
        if (pentry->URL.GetLength() != 0)
            if (void* pmem = pheap->Alloc(0x40))
                pentryMT = static_cast<LoadQueueEntryMT*>(FUN_14291c910(pmem, pentry, this));
        if (pentryMT)
        {
            GFxAS2LoadQueueEntry* pnew = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            if (Object* pobj = pnew->XMLHolder.ASObj.ToObject(0))
            {
                for (LoadQueueEntryMT* p = pMovieImpl->pLoadQueueMTHead; p; p = p->GetNext())
                {
                    GFxAS2LoadQueueEntry* pother = static_cast<GFxAS2LoadQueueEntry*>(p->GetQueueEntry());
                    if (!pother->XMLHolder.ASObj.IsUndefined() && pobj == pother->XMLHolder.ASObj.ToObject(0))
                        pother->Canceled = true;
                }
            }
        }
    }
    else if (pentry->Type & LoadQueueEntry::LTF_CSSFlag)
    {
        if (pentry->URL.GetLength() != 0)
            if (void* pmem = pheap->Alloc(0x38))
                pentryMT = static_cast<LoadQueueEntryMT*>(FUN_14291c400(pmem, pentry, this));
        if (pentryMT)
        {
            GFxAS2LoadQueueEntry* pnew = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            if (Object* pobj = pnew->CSSHolder.ASObj.ToObject(0))
            {
                for (LoadQueueEntryMT* p = pMovieImpl->pLoadQueueMTHead; p; p = p->GetNext())
                {
                    GFxAS2LoadQueueEntry* pother = static_cast<GFxAS2LoadQueueEntry*>(p->GetQueueEntry());
                    if (!pother->CSSHolder.ASObj.IsUndefined() && pobj == pother->CSSHolder.ASObj.ToObject(0))
                        pother->Canceled = true;
                }
            }
        }
    }
    else
    {
        if (void* pmem = pheap->Alloc(0x58))
            pentryMT = static_cast<LoadQueueEntryMT*>(FUN_14291c690(pmem, pentry, pMovieImpl));
        if (pentryMT)
        {
            GFxAS2LoadQueueEntry* pnew = static_cast<GFxAS2LoadQueueEntry*>(pentryMT->GetQueueEntry());
            for (LoadQueueEntryMT* p = pMovieImpl->pLoadQueueMTHead; p; p = p->GetNext())
            {
                GFxAS2LoadQueueEntry* pother = static_cast<GFxAS2LoadQueueEntry*>(p->GetQueueEntry());
                if (!pnew->pCharacter)
                {
                    if (pother->Level != -1 && pother->Level == pnew->Level)
                        pother->Canceled = true;
                }
                else if (pother->pCharacter && pother->pCharacter->NamePath == pnew->pCharacter->NamePath)
                    pother->Canceled = true;
            }
        }
    }
    if (pentryMT)
        pMovieImpl->AddLoadQueueEntryMT(pentryMT);
    else
        delete pentry;
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
// MS2-FUNCTIONAL: register allocation (the exe calls CreateString in each arm of the penv test, ours hoists it)
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
// @0x142930090
void MovieRoot::AddMovieLoadQueueEntry(LoadQueueEntry* pentry)
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
// MS2-FUNCTIONAL: the value is built with the AS2 value setters
// @0x142930480
void GASSharedObjectLoader::AddProperty(const String& name, const String& value, GFx::Value::ValueType type)
{
    Object* ptop = ObjectStack[ObjectStack.GetSize() - 1];
    Value   v;
    switch (type)
    {
    case GFx::Value::VT_Undefined:
        break;
    case GFx::Value::VT_Null:
        v.SetNull();
        break;
    case GFx::Value::VT_Boolean:
        v.SetBool(strncmp(value.ToCStr(), "true", 4) == 0);
        break;
    case GFx::Value::VT_Number:
        v.SetNumber(atof(value.ToCStr()));
        break;
    case GFx::Value::VT_String:
        v.SetString(pEnv->CreateString(value.ToCStr(), value.GetSize()));
        break;
    default:
        break;
    }
    if (!bArrayIsTop)
        ptop->SetMember(pEnv, pEnv->CreateString(name.ToCStr(), name.GetSize()), v);
    else
        static_cast<ArrayObject*>(ptop)->PushBack(v);
}

// Creates the objects of a dotted package path under pparent and returns the last one.
// MS2-FUNCTIONAL: the segment buffer and its checks follow the exe, the reference counting is the Ptr's
// @0x1429301d0
Object* GlobalContext::AddPackage(ASStringContext* psc, Object* pparent, Object* pproto, const char* ppath)
{
    Ptr<Object> pcur = pparent;
    while (ppath)
    {
        const char* pdot  = strchr(ppath, '.');
        UPInt       count = pdot ? UPInt(pdot - ppath) : strlen(ppath);
        char        segment[0x101];
        if (count > 0xff)
            __report_rangecheckfailure();
        memcpy(segment, ppath, count);
        segment[count] = '\0';
        ppath          = pdot ? pdot + 1 : 0;

        ASString name = psc->CreateString(segment);
        Value    member;
        Ptr<Object> pnext;
        if (pcur->GetMemberRaw(psc, name, &member))
            pnext = member.ToObject(0);
        else
        {
            pnext = *SF_HEAP_NEW(psc->GetHeap()) Object(psc, pproto);
            pcur->SetMemberRaw(psc, name, Value(pnext.GetPtr()));
        }
        pcur = pnext;
    }
    return pcur;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7GFxAS2LoadQueueEntry@AS2@GFx@Scaleform@@6B@ 0x143217748
