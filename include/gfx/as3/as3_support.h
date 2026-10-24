// Recovered Scaleform GFx 4.1.18 AS3: the pieces of the AS3 player the loader side needs (GFx_AS3Support): the per-movie
// memory context, ABC data blocks and the DoAbc execute tag, plus the AS3 MovieRoot constructor.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS3_SUPPORT_H
#define MS2_SF_GFX_AS3_SUPPORT_H

#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"
#include "ms2/scaleform/include/gfx/gfx_assupport.h"
#include "ms2/scaleform/include/gfx/gfx_asimemanager.h"
#include "ms2/scaleform/include/gfx/gfx_loadproc.h"
#include "ms2/scaleform/include/render/text_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_gc.h"

namespace Scaleform { namespace GFx {

class PlaceObject2Tag;
class PlaceObject3Tag;
class RemoveObjectTag;
class RemoveObject2Tag;

// The AS3 support state (LoadStates::pAS3Support): creates AS3 movies, their memory contexts and characters.
class AS3Support : public ASSupport
{
public:
    AS3Support();

    virtual MovieImpl*        CreateMovie(MemoryContext* memContext);
    virtual Ptr<ASIMEManager> CreateASIMEManager();
    virtual MemoryContext*    CreateMemoryContext(const char* heapName, const MemoryParams& memParams, bool debugHeap);
    virtual DisplayObjectBase* CreateCharacterInstance(MovieImpl* proot, const CharacterCreateInfo& ccinfo,
                                                       InteractiveObject* pparent, ResourceId rid,
                                                       CharacterDef::CharacterDefType type = CharacterDef::Unknown);
    virtual void  DoActions();
    virtual UByte GetAVMVersion() const { return 2; }

    virtual PlaceObject2Tag*  AllocPlaceObject2Tag(LoadProcess* p, UPInt dataSz, UInt8 swfVer);
    virtual PlaceObject3Tag*  AllocPlaceObject3Tag(LoadProcess* p, UPInt dataSz);
    virtual RemoveObjectTag*  AllocRemoveObjectTag(LoadProcess* p);
    virtual RemoveObject2Tag* AllocRemoveObject2Tag(LoadProcess* p);

    // AS3 movies have no DoAction / button action records.
    virtual void DoActionLoader(LoadProcess*, const TagInfo&) {}
    virtual void DoInitActionLoader(LoadProcess*, const TagInfo&) {}
    virtual void ReadButtonActions(LoadProcess*, ButtonDef*, TagType) {}
    virtual void ReadButton2ActionConditions(LoadProcess*, ButtonDef*, TagType) {}
};

namespace AS3 {

// The AS3 IME manager (0xe0 bytes). Opaque until the IME units are recovered.
// The AS3 IME manager (sfr_as3_20): loads the candidate list movie into the stage and sends the IME events to the
// language bar and status window. 0xe0 bytes; vftable 0x14317fce8.
class IMEManager : public ASIMEManager
{
public:
    IMEManager();
    bool GetIMEMoviePath(Scaleform::String& path);

    // (sfr19) the ASIMEManager overrides
    virtual ~IMEManager();
    virtual void ShutDown();
    virtual void ASRootMovieCreated(Ptr<Sprite> spr);
    virtual void IMECommand(Movie* pmovie, const char* pcommand, const char* pparams);
    virtual void BroadcastIMEConversion(const wchar_t* pstr);
    virtual void BroadcastSwitchLanguage(const char* pstr);
    virtual void BroadcastSetSupportedLanguages(const char* pstr);
    virtual void BroadcastSetSupportedIMEs(const char* pstr);
    virtual void BroadcastSetCurrentInputLanguage(const char* pstr);
    virtual void BroadcastSetIMEName(const char* pstr);
    virtual void BroadcastSetConversionStatus(const char* pstr);
    virtual void BroadcastRemoveStatusWindow(const char* pstr);
    virtual void BroadcastDisplayStatusWindow(const char* pstr);
    virtual bool IsCandidateListLoaded() const;
    virtual bool IsTextFieldFocused() const;
    virtual bool Invoke(const char* pmethodName, GFx::Value* presult, const GFx::Value* pargs, unsigned numArgs);
    virtual InteractiveObject* HandleFocus(Movie* pmovie, InteractiveObject* poldFocus, InteractiveObject* pnewFocus,
                                           InteractiveObject* ptopMostItem);
    virtual void OnOpenCandidateList();
    virtual bool AcquireCandidateList();
    virtual void SetIMEMoviePath(const char* pcandidateSwfPath);
    virtual void SetActiveMovie(Movie* pmovie);
    virtual void SetIMEManager(IMEManagerBase* pimeMgr);
    // (sfr19) its own slots 22..27
    virtual bool Init(Log* plog);                                                       // 22
    virtual bool SetCompositionString(const char* pcompString);                         // 23
    virtual bool IsCandidateList(const char* ppath);                                    // 24
    virtual bool IsStatusWindow(const char* ppath);                                     // 25
    virtual bool IsLangBar(const char* ppath);                                          // 26
    virtual void OnShutdown();                                                          // 27

    // Whether pfocusedChar (or the movie's focused character) is a text field taking IME input.
    bool IsTextFieldFocused(InteractiveObject* pfocusedChar) const;                     // 0x142544e10
    // The candidate list movie's root, once loaded.
    DisplayObject* GetCandidateListSprite() const;                                      // 0x142543e70
    // Sends the IME event messageType (message attached) to the "LangBar" or "StatusWindow" context.
    void DispatchEvent(const char* message, const char* messageType, const char* type); // 0x142543b80

    unsigned                UnsupportedIMEWindowsFlag;  // +0xa0
    Log*                    pLog;                       // +0xa8
    SInt32                  CandidateListState;         // +0xb0 0 none, 1 loading, 2 loaded
    GFx::Value              CandListVal;                // +0xb8 the candidate list movie's content
    Ptr<IMEFuncHandler>     pCustomFunc;                // +0xd8
};

// Per-movie memory: the movie heap with its string manager and garbage collector. 0x68 bytes; the heap limit
// handler sits at +0x30.
class MemoryContextImpl : public MemoryContext
{
public:
    // Heap limit handler: collects garbage before letting the movie heap grow. LimitHandler::AllocCount (+0x08,
    // +0x38 in the context) is nonzero while collections must not run from inside the allocator; then OnExceedLimit
    // only schedules one.
    class HeapLimit : public MemoryHeap::LimitHandler
    {
        friend class MemoryContextImpl;

        MemoryContextImpl*  MemContext;                 // +0x10
        UPInt               UserLevelLimit;             // +0x18
        UPInt               LastCollectionFootprint;    // +0x20
        UPInt               CurrentLimit;               // +0x28
        float               HeapLimitMultiplier;        // +0x30
    public:
        HeapLimit() : MemContext(0), UserLevelLimit(0), LastCollectionFootprint(0), CurrentLimit(0),
                      HeapLimitMultiplier(0.25f) { }
        virtual ~HeapLimit() { }
        virtual bool OnExceedLimit(MemoryHeap* heap, UPInt overLimit);
        virtual void OnFreeSegment(MemoryHeap* heap, UPInt freeingSize);

        void SetMemoryContext(MemoryContextImpl* memContext) { MemContext = memContext; }
        void SetUserLevelLimit(UPInt lim)   { UserLevelLimit = lim; }
        void SetHeapLimitMultiplier(float m){ HeapLimitMultiplier = m; }
    };

    MemoryHeap*                         Heap;           // +0x10
    Ptr<ASStringManager>                StringMgr;      // +0x18
    Ptr<ASRefCountCollector>            ASGC;           // +0x20
    Ptr<Render::Text::Allocator>        TextAllocator;  // +0x28
    HeapLimit                           LimHandler;     // +0x30

    MemoryContextImpl() { LimHandler.SetMemoryContext(this); }
    virtual ~MemoryContextImpl() { Heap->SetLimitHandler(0); }
};

// One DoABC tag's byte code. Allocated with the data inline (sizeof - 1 + DataSize).
class AbcDataBuffer : public RefCountBase<AbcDataBuffer, StatMD_ASBinaryData_Mem>
{
public:
    String      Name;           // +0x10
    unsigned    DataSize;       // +0x18
    UByte       Flags;          // +0x1c
    void*       pReserved;      // +0x20
    StringLH    FileName;       // +0x28
    UByte       Data[1];        // +0x30

    AbcDataBuffer(const String& name, unsigned dataSize, UByte flags)
        : Name(name), DataSize(dataSize), Flags(flags), pReserved(0) { }
};

// Execute tag created by DoAbcLoader: runs the ABC block when its frame is reached.
class DoAbc : public ExecuteTag
{
public:
    Ptr<AbcDataBuffer> pAbc;    // +0x08

    DoAbc(AbcDataBuffer* pabc) : pAbc(pabc) { }

    virtual void Execute(DisplayObjContainer* m);
    virtual void ExecuteWithPriority(DisplayObjContainer* m, ActionPriority::Priority priority);
    virtual bool IsActionTag() const { return true; }
    virtual void Trace(const char* str);
};

// The AS3 side of a movie (0x6f8 bytes). Opaque until recovered: the loader side only constructs it and runs ABC
// blocks; it is used through its ASMovieRootBase part (at offset 0). (sfr19) Units that need its members include
// as3_asvm.h first, which declares it instead.
#ifndef MS2_SF_GFX_AS3_ASVM_H
class MovieRoot
{
public:
    MovieRoot(MemoryContextImpl* memContext, MovieImpl* pmovie, ASSupport* pas);

    // Executes one ABC block for the given sprite; false when the VM refused it.
    bool ExecuteAbc(const AbcDataBuffer* pabc, DisplayObjContainer* pspr);

    ASMovieRootBase* GetBase() { return reinterpret_cast<ASMovieRootBase*>(this); }

    void* operator new(UPInt, void* p) { return p; }
    void  operator delete(void*, void*) { }

private:
    UByte Data[0x6f8];
};
#endif

void SF_STDCALL SymbolClassLoader(LoadProcess* p, const TagInfo& tagInfo);
void SF_STDCALL DoAbcLoader(LoadProcess* p, const TagInfo& tagInfo);

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::IMEManager) == 0xe0, "IMEManager size");

#endif
