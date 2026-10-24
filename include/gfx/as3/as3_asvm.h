// Recovered Scaleform GFx 4.1.18 AS3: the movie-side VM (ASVM) and the AS3 movie root, as the AS3 natives see them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// ASVM extends VM (as3_vm.h, which ends at +0x2d8) with the movie root and the class objects of the builtins the
// natives construct directly. MovieRoot is declared only as far as the natives reach (its movie, at +0x10 of the
// ASMovieRootBase part) and
// the external interface return value.
#ifndef MS2_SF_GFX_AS3_ASVM_H
#define MS2_SF_GFX_AS3_ASVM_H

#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimplstates.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"
#include "ms2/scaleform/include/gfx/gfx_event.h"
#include "ms2/scaleform/include/gfx/gfx_eventid.h"
#include "ms2/scaleform/include/gfx/gfx_keyboardstate.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "ms2/scaleform/include/gfx/gfx_playertasks.h"

// windows.h (through the kernel lock header) maps GetObject to GetObjectA; Value::GetObject keeps its name.
#ifdef GetObject
#undef GetObject
#endif

namespace Scaleform { namespace GFx { namespace AS3 {

class LoadQueueEntry;   // (appended, sfr19) as3_loadqueue.h
class ASVM;             // (appended, sfr19)
class MemoryContextImpl;  // (appended, sfr34) as3_support.h
namespace Instances { namespace fl_display { class DisplayObject; } }   // (appended, sfr19)

// The Loader's load-init notification, held by a load entry or an action entry while it is pending (body not
// recovered; a thread-safe counted object, released through RefCountImpl::Release). (moved here from
// as3_loadqueue.h, sfr19: the action entries hold one too)
class NotifyLoadInitC : public RefCountImpl
{
public:
    // (appended, sfr19) the Loader's open / init / error events (4.1.18 has no load-complete slot)
    virtual void OpenEventCallback() = 0;   // 1
    virtual void InitEventCallback() = 0;   // 2
    virtual void ErrorEventCallback() = 0;  // 3
};

// (sfr24) ASMovieRootBase at +0x00 (vftable 0x14317d8d8, 54 slots), FlashUI at +0x28 (vftable 0x14317da88) and
// KeyboardState::IListener at +0x38 (vftable 0x14317daa0), as the ctor 0x1424d8640 stores them.
class MovieRoot : public ASMovieRootBase, public FlashUI, public KeyboardState::IListener
{
public:
    // (appended, sfr19) the action queues, run in level order once per frame (ExecuteActionQueues runs the first
    // six; AL_Manual only on request).
    enum ActionLevel
    {
        AL_Highest = 0,
        AL_High,
        AL_EnterFrame,
        AL_Frame,
        AL_ControllerEvents,
        AL_Render,

        AL_Count_,
        AL_Lowest = AL_Count_ - 1,
        AL_Manual = AL_Count_,
        AL_Total
    };

    // (appended, sfr19) one queued action: an event fired at a display object, an AS3 function called on its AS3
    // object, or a C callback. 0x68 bytes, StatMV_ActionScript_Mem.
    struct ActionEntry : public NewOverrideBase<StatMV_ActionScript_Mem>
    {
        enum EntryType
        {
            Entry_None,
            Entry_Event,
            Entry_Function,
            Entry_CFunction
        };
        typedef void (*CFunctionPtr)(const ActionEntry&);

        ActionEntry*                                pNextEntry;     // +0x00
        EntryType                                   Type;           // +0x08
        Ptr<DisplayObject>                          pCharacter;     // +0x10
        SPtr<Instances::fl_display::DisplayObject>  pAS3Obj;        // +0x18
        EventId                                     mEventId;       // +0x20
        Value                                       Function;       // +0x38
        CFunctionPtr                                CFunction;      // +0x58
        Ptr<NotifyLoadInitC>                        pNLoadInitCL;   // +0x60

        ActionEntry() { pNextEntry = NULL; Type = Entry_None; }   // CFunction is set by SetAction/ClearAction

        void SetAction(DisplayObject* pcharacter, const EventId& id)
        {
            Type = Entry_Event;
            pCharacter = pcharacter;
            mEventId = id;
            CFunction = NULL;
            pAS3Obj = NULL;
            Function.SetUndefined();
            pNLoadInitCL = NULL;
        }
        void ClearAction()
        {
            Type = Entry_None;
            pCharacter = NULL;
            pAS3Obj = NULL;
            CFunction = NULL;
            Function.SetUndefined();
            pNLoadInitCL = NULL;
        }
        // Runs the action unless its character was unloaded. 0x1424f9b00
        void Execute(MovieRoot* proot) const;
    };

    // (appended, sfr19) a level's singly linked list: actions are added after pInsertEntry.
    struct ActionQueueEntry
    {
        ActionEntry*    pActionRoot;    // +0x00
        ActionEntry*    pInsertEntry;   // +0x08
        ActionEntry*    pLastEntry;     // +0x10

        ActionQueueEntry() { Reset(); }
        void Reset() { pActionRoot = pLastEntry = pInsertEntry = NULL; }
    };

    // (appended, sfr19) the queues of all levels plus a free list of up to 50 recycled entries. 0xc8 bytes.
    class ActionQueueType
    {
    public:
        ActionQueueEntry    Entries[AL_Total];  // +0x00
        int                 ModId;              // +0xa8 bumped on every change, for the iterators
        ActionEntry*        pFreeEntry;         // +0xb0
        unsigned            FreeEntriesCount;   // +0xb8
        MemoryHeap*         pHeap;              // +0xc0

        ActionQueueType(MemoryHeap* pheap) : ModId(1), pFreeEntry(NULL), FreeEntriesCount(0), pHeap(pheap) {}
        ~ActionQueueType();                                 // 0x1424dda00

        MemoryHeap*  GetMovieHeap() const { return pHeap; }
        ActionEntry* GetNewEntry();                         // 0x14250bd10
        ActionEntry* InsertEntry(ActionLevel lvl);          // 0x142512800
        ActionEntry* PrependEntry(ActionLevel lvl);         // 0x14251d000
        void         AddToFreeList(ActionEntry* pentry);    // 0x1424eae40
        void         Clear();                               // 0x1424ef9e0
    };

    // (appended, sfr19) walks one level's queue, taking each entry off it; the entry handed out last goes to the
    // free list on the next call. Restarts from the insert point when the queue changed under it.
    class ActionQueueIterator
    {
    public:
        int              ModId;          // +0x00
        ActionQueueType* pActionQueue;   // +0x08
        ActionEntry*     pCurEntry;      // +0x10
        ActionEntry*     pRootEntry;     // +0x18
        ActionEntry*     pLastEntry;     // +0x20
        ActionLevel      Level;          // +0x28

        // (sfr33) assigned in the body, in the exe's store order (ActionQueueType::Clear 0x1424ef9e0).
        ActionQueueIterator(ActionLevel lvl, ActionQueueType* pactionQueue, ActionEntry* rootEntry = NULL)
        {
            pActionQueue = pactionQueue;
            Level        = lvl;
            ModId        = 0;
            pLastEntry   = NULL;
            pRootEntry   = rootEntry;
            pCurEntry    = rootEntry ? rootEntry->pNextEntry : pactionQueue->Entries[lvl].pActionRoot;
        }
        ~ActionQueueIterator()
        {
            if (pLastEntry)
                pActionQueue->AddToFreeList(pLastEntry);
        }
        const ActionEntry* getNext();   // 0x142540a90
    };

    // ASMovieRootBase::GetRootMovie, vftable slot 14 (+0x70): 4.1.18 has no SuspendGC / ScheduleGC slots there, so it
    // is two slots before where the 4.1.19 SDK header puts it. ASMovieRootBase declares it now (gfx_displayobject.h).
    DisplayObjContainer* GetRootMovie418(DisplayObject* dobj = NULL) const
    {
        typedef DisplayObjContainer* (*Fn)(const MovieRoot*, DisplayObject*);
        return (*reinterpret_cast<Fn const* const*>(this))[14](this, dobj);
    }

    // Converts v into a host value for the external interface.
    void ASValue2GFxValue(const Value& v, GFx::Value* pdestVal) const;     // 0x1424e42c0
    // (appended, sfr19) the reverse: a host value as an AS3 value. 0x1425048d0
    void GFxValue2ASValue(const GFx::Value& gfxVal, Value* pdestVal);

    MemoryContextImpl*  MemContext;                 // +0x40 Ptr<MemoryContextImpl>: the movie heap's memory context (sfr34)
    ASVM*               pAVM;                       // +0x48 AutoPtr<ASVM> (sfr19)
private:
    UByte               Unrecovered50[0x58 - 0x50];
public:
    Value               ExternalIntfRetVal;         // +0x58: what the host's ExternalInterface callback returned
    unsigned            NumAdvancesSinceCollection; // +0x78 advances since the last collection (sfr24)
    unsigned            LastCollectionFrame;        // +0x7c (sfr24)
private:
    UByte               Unrecovered80[0x88 - 0x80];
public:
    ActionQueueType     ActionQueue;                // +0x88 (sfr19)
    void*               mEventChains;               // +0x150 EventChains: the objects listening to each frame event,
                                                    // one hash pointer (sfr24)
    GFx::DisplayObject* pStage;                     // +0x158 Ptr<Stage>: the stage the root movies sit on (sfr19)
    StringManager       BuiltinsMgr;                // +0x160: the AS3 builtin strings
    unsigned            ASFramesToExecute;          // +0x358 (sfr24)

    // (appended, sfr24) the AS3 side of one mouse. 0xe0 bytes; the ctor clears every field but the positions.
    struct MouseState
    {
        struct DoubleClickInfo
        {
            UInt32         PrevClickTime;
            Render::PointF PrevPosition;
        };
        void*               RolloverStack[3];       // +0x00 ArrayLH<Ptr<InteractiveObject> >: the objects under the mouse
        GFx::InteractiveObject* LastMouseOverObj;      // +0x18 Ptr<InteractiveObject>
        DoubleClickInfo     DblClick[16];           // +0x20 one per button
    };
    MouseState          mMouseState[4];             // +0x360 (sfr24)
    bool                StageInvalidated;           // +0x6e0 (sfr24)
    UInt8               MainLoaderInfoEventsState;  // +0x6e1 bit 0 init executed, bit 1 completed (sfr24)
    void*               LoadedMovieDefs;            // +0x6e8 HashIdentityLH<MovieDefImpl*, LoadedMovieDefInfo> (sfr24)
    UInt8               Flags;                      // +0x6f0 bit 0: inside a gotoAndPlay/Stop (sfr24)

    // (appended for the Loader natives, sfr17) the load queue.
    void UnloadMovie(Instances::fl_display::Loader* ploader, bool stop = false, bool gc = false);   // 0x1425305f0
    void AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_display::Loader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None); // 0x1424e9090
    void AddNewLoadQueueEntry(Instances::fl_utils::ByteArray* bytes, Instances::fl_display::Loader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None); // 0x1424e9010
    // (appended, sfr19) URLLoader.load. 0x1424e9210
    void AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_net::URLLoader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None);
    // (appended, sfr19) pentry handed to a loader-thread entry (variables, binary or movie). 0x1424e8c20
    void AddLoadQueueEntryMT(LoadQueueEntry* pentry);
    // (appended, sfr19) ASMovieRootBase::ProcessLoadQueueEntry: 4.1.18 vftable slot 26 (+0xd0).
    void ProcessLoadQueueEntry418(GFx::LoadQueueEntry* pentry, LoadStates* pls)
    {
        typedef void (*Fn)(MovieRoot*, GFx::LoadQueueEntry*, LoadStates*);
        (*reinterpret_cast<Fn const* const*>(this))[26](this, pentry, pls);
    }
    // (appended, sfr19) the directory of _level0's URL into ppath; false (ppath cleared) without one. 0x14250da50
    bool GetRootFilePath(String* ppath) const;
    // (appended, sfr19) ASMovieRootBase::GetStringManager: 4.1.18 vftable slot 50 (+0x190).
    ASStringManager* GetStringManager418() const
    {
        typedef ASStringManager* (*Fn)(const MovieRoot*);
        return (*reinterpret_cast<Fn const* const*>(this))[50](this);
    }
    // (appended, sfr19) a new action at the end of level lvl's queue. 0x142512790
    ActionEntry* InsertEmptyAction(ActionLevel lvl = AL_Frame);
    // (appended, sfr19) runs the queued actions of every level but AL_Manual. 0x1424fa450
    void ExecuteActionQueues();

    // (appended, sfr24) The overrides, vftable 0x14317d8d8 (slots 12, 13, 23 and 24 are ASMovieRootBase's empty
    // defaults). No ctor is defined here, so no unit emits the vftables.
    virtual ~MovieRoot();                                                                              // 0 0x1424e33f0
    virtual void SetMovie(MovieImpl* pmovie);                                                          // 1 0x142528740
    virtual void AdvanceFrame(bool nextFrame);                                                         // 2 0x1424eb2f0
    virtual void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType);                     // 3 0x1424eeae0
    virtual bool CheckAvm();                                                                           // 4 0x1424eecb0
    virtual void ClearDisplayList();                                                                   // 5 0x1424efb40
    virtual MovieDefRootNode* CreateMovieDefRootNode(MemoryHeap* pheap, MovieDefImpl* pdefImpl,
                                                     bool importFlag = false);                         // 6 0x1424f3910
    virtual void DoActions();                                                                          // 7 0x1424f73d0
    virtual GFx::InteractiveObject* FindTarget(const ASString& path) const;                            // 8 0x142502cf0
    virtual void ForceCollect(unsigned gcFlags);                                                       // 9 0x1425046d0
    virtual void ForceEmergencyCollect();                                                              // 10 0x142504750
    virtual void GenerateMouseEvents(unsigned mouseIndex);                                             // 11 0x142504b50
    virtual DisplayObjContainer* GetRootMovie(DisplayObject* dobj = NULL) const;                       // 14 0x14250daa0
    virtual bool Init(MovieDefImpl* pmovieDef);                                                        // 15 0x142511530
    virtual void NotifyMouseEvent(const InputEventsQueueEntry* qe, const GFx::MouseState& ms, int mi); // 16 0x142518470
    virtual void NotifyOnResize();                                                                     // 17 0x1425184f0
    virtual void NotifyQueueSetFocus(GFx::InteractiveObject* ch, unsigned controllerIdx,
                                     FocusMovedType fmt);                                              // 18 0x142518510
    virtual void NotifyTransferFocus(GFx::InteractiveObject* curFocused, GFx::InteractiveObject* pnewFocus,
                                     unsigned controllerIdx);                                          // 19 0x142518520
    virtual bool NotifyOnFocusChange(GFx::InteractiveObject* curFocused, GFx::InteractiveObject* toBeFocused,
                                     unsigned controllerIdx, FocusMovedType fmt,
                                     ProcessFocusKeyInfo* pfocusKeyInfo = NULL);                       // 20 0x142518480
    virtual void OnMovieFocus(bool set);                                                               // 21 0x14251ac40
    virtual void OnNextFrame();                                                                        // 22 0x14251ac60
    virtual void PrintObjectsReport(UInt32 flags = 0, Log* log = NULL, const char* swfName = NULL);    // 25 0x14251d060
    virtual void ProcessLoadQueueEntry(GFx::LoadQueueEntry* pentry, LoadStates* pls);                  // 26 0x14251e560
    virtual void ProcessLoadVarsMT(GFx::LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                   bool succeeded);                                                    // 27 0x14251f250
    virtual void ProcessLoadBinaryMT(GFx::LoadQueueEntry* pentry, LoadStates* pls, const ArrayPOD<UByte>& data,
                                     UPInt fileLen, bool succeeded);                                   // 28 0x14251e4b0
    virtual void RegisterAuxASClasses();                                                               // 29 0x1425210c0
    virtual void ResolveStickyVariables(GFx::InteractiveObject* pcharacter);                           // 30 0x142525500
    virtual void SetExternalInterfaceRetVal(const GFx::Value& retVal);                                 // 31 0x142527390
    virtual void SetMemoryParams(unsigned frameBetweenCollections, unsigned maxRootCount);             // 32 0x1425282c0
    virtual void Shutdown();                                                                           // 33 0x14252c4f0
    virtual void CreateString(GFx::Value* pvalue, const char* pstring);                                // 34 0x1424f41f0
    virtual void CreateStringW(GFx::Value* pvalue, const wchar_t* pstring);                            // 35 0x1424f42d0
    virtual void CreateObject(GFx::Value* pvalue, const char* className = NULL, const GFx::Value* pargs = NULL,
                              unsigned nargs = 0);                                                     // 36 0x1424f39c0
    virtual void CreateArray(GFx::Value* pvalue);                                                      // 37 0x1424f2700
    virtual void CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData = NULL);     // 38 0x1424f3780
    virtual bool SetVariable(const char* ppathToVar, const GFx::Value& value,
                             SetVarTypeArg setType = SetVarTypeArg(1));                                // 39 0x14252a700
    virtual bool GetVariable(GFx::Value* pval, const char* ppathToVar) const;                          // 40 0x142510180
    virtual bool SetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index,
                                  const void* pdata, unsigned count,
                                  SetVarTypeArg setType = SetVarTypeArg(1));                           // 41 0x14252acc0
    virtual bool SetVariableArraySize(const char* ppathToVar, unsigned count,
                                      SetVarTypeArg setType = SetVarTypeArg(1));                       // 42 0x14252b3a0
    virtual unsigned GetVariableArraySize(const char* ppathToVar);                                     // 43 0x142510770
    virtual bool GetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, void* pdata,
                                  unsigned count);                                                     // 44 0x142510240
    virtual bool IsAvailable(const char* ppathToVar) const;                                            // 45 0x142513f90
    virtual bool Invoke(const char* ppathToMethod, GFx::Value* presult, const GFx::Value* pargs,
                        unsigned numArgs);                                                             // 47 0x142513240
    virtual bool Invoke(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt, ...);     // 46 0x142513210
    virtual bool InvokeArgs(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt,
                            va_list args);                                                             // 48 0x1425136f0
    virtual MemoryContext* GetMemoryContext() const;                                                   // 49 0x14250ba00
    virtual ASStringManager* GetStringManager() const;                                                 // 50 0x14250eef0
    virtual Render::Text::Allocator* GetTextAllocator();                                               // 51 0x14250f290
    // AS3 only: the collector's suspend count ++/-- (MemContext's ASRefCountCollector +0xb1) and its
    // collect-on-next-advance flag (+0xb0); gcFlags is not read.
    virtual void SuspendGC(bool suspend);                                                              // 52 0x14252e530
    virtual void ScheduleGC(unsigned gcFlags);                                                         // 53 0x1425262d0

    // FlashUI (+0x28): the VM's trace / debugger hooks.
    virtual void Output(FlashUI::OutputMessageType type, const char* msg);                             // 1 0x14251bc40
    virtual bool OnOpCode(Abc::TCodeOffset offset);                                                    // 2 0x14251ac90 false
    // KeyboardState::IListener (+0x38).
    virtual void OnKeyDown(GFx::InteractiveObject* pmovie, const EventId& evt, int keyMask);           // 1 0x14251a1e0
    virtual void OnKeyUp(GFx::InteractiveObject* pmovie, const EventId& evt, int keyMask);             // 2 0x14251a3b0
    virtual void Update(const EventId& evt);                                                           // 3 0x142530fb0 empty
protected:
    // (appended, sfr19) the mouseCursorEvent name of a MouseCursorEvent cursor type. 0x14250bb10
    void GetMouseCursorTypeString(ASString& str, unsigned cursorType) const;
};
// The ctor 0x1424d8640 fills 0x6f8 bytes (sfr24).
static_assert(sizeof(MovieRoot) == 0x6f8, "AS3::MovieRoot size");

class ASVM : public VM
{
public:
    // (appended, sfr19) vftable 0x14317d8b0
    ASVM(MovieRoot* pmr, FlashUI& ui, FileLoader& loader, StringManager& sm, ASRefCountCollector& gc);   // 0x1424d5600
    virtual ~ASVM();                    // 0x1424dd500
    virtual void* Unk01() { return 0; } // slot 1 (its own copy, 0x1425071f0)

    MovieImpl* GetMovieImpl() const { return pMovieRoot->GetMovieImpl(); }
    MovieRoot* GetMovieRoot() const { return pMovieRoot; }
    Log*       GetLog() const;     // 0x1424c90e0
    const ASString& GetBuiltin(BuiltinType btype) const { return pMovieRoot->BuiltinsMgr.GetBuiltin(btype); }

    // Constructs an instance of the class object classObj; false when the construction threw.
    bool _constructInstance(SPtr<Object>& pobj, Object* classObj, unsigned argc, const Value* argv);   // 0x142531f40
    template <class T>
    bool ConstructInstance(SPtr<T>& pobj, Object* classObj, unsigned argc = 0, const Value* argv = 0)
    {
        return _constructInstance(reinterpret_cast<SPtr<Object>&>(pobj), classObj, argc, argv);
    }

protected:
    MovieRoot*          pMovieRoot;                 // +0x2d8
public:
    SPtr<Class>         GraphicsClass;              // +0x2e0
    SPtr<Class>         TransformClass;             // +0x2e8
    SPtr<Class>         MatrixClass;                // +0x2f0
    SPtr<Class>         Matrix3DClass;              // +0x2f8
    SPtr<Class>         PerspectiveProjectionClass; // +0x300
    SPtr<Class>         ColorTransformClass;        // +0x308
    SPtr<Class>         EventClass;                 // +0x310
    SPtr<Class>         MouseEventClass;            // +0x318
    SPtr<Class>         MouseEventExClass;          // +0x320
    SPtr<Class>         KeyboardEventClass;         // +0x328
    SPtr<Class>         KeyboardEventExClass;       // +0x330
    SPtr<Class>         FocusEventClass;            // +0x338
    SPtr<Class>         FocusEventExClass;          // +0x340
    SPtr<Class>         TextEventClass;             // +0x348
    SPtr<Class>         TextEventExClass;           // +0x350
    SPtr<Class>         TimerEventClass;            // +0x358
    SPtr<Class>         ProgressEventClass;         // +0x360
    SPtr<Class>         StageOrientationEventClass; // +0x368
    SPtr<Class>         AppLifecycleEventClass;     // +0x370
    SPtr<Class>         PointClass;                 // +0x378
    SPtr<Class>         RectangleClass;             // +0x380
    SPtr<Class>         TextFormatClass;            // +0x388
    SPtr<Class>         EventDispatcherClass;       // +0x390
    SPtr<Class>         Vector3DClass;              // +0x398
    // (appended, sfr_as3_09) the "Ex" event classes (scaleform.gfx.*EventEx: controller/mouse indices) are made in
    // place of the flash.events ones
    bool                ExtensionsEnabled;          // +0x3a0
};

}}} // namespace Scaleform::GFx::AS3

#endif
