// Recovered Scaleform 4.1.18 GFx AS2: the AS2 movie root, as far as the recovered units read it (the builtin
// string table), and the builtin string ids. Shared header of the src/ms2/scaleform units (sfr lane): append,
// do not reorder members or enumerators.
#ifndef MS2_SF_GFX_AS2_MOVIEROOT_H
#define MS2_SF_GFX_AS2_MOVIEROOT_H

#include "as2_action.h"
#include "../gfx_displayobject.h"
#include "../gfx_moviedef.h"
#include "../gfx_movieimpl.h"
#include "../gfx_playertasks.h"
#include "../gfx_loadproc.h"

namespace Scaleform { namespace GFx { class Value; class FunctionHandler; } }
namespace Scaleform { namespace GFx { struct ProcessFocusKeyInfo; } }
namespace Scaleform { namespace Render { namespace Text { class Allocator; } } }

namespace Scaleform { namespace GFx { namespace AS2 {

class MovieClipLoader;
class MouseListener;

// Ids of the strings every AS2 movie creates up front (index into StringManager::Builtins).
enum ASBuiltinType : int
{
    ASBuiltin_empty_ = 0, // ""
    ASBuiltin_Object = 1,
    ASBuiltin_Array  = 2,
    ASBuiltin_String = 3,
    ASBuiltin_Number  = 4,
    ASBuiltin_Boolean = 5,
    ASBuiltin_MovieClip = 6,
    ASBuiltin_Function = 7,
    ASBuiltin_Button   = 9,
    ASBuiltin_TextField = 10,
    ASBuiltin_Color    = 11,
    ASBuiltin_Transform = 12,
    ASBuiltin_Matrix   = 13,
    ASBuiltin_Point    = 14,
    ASBuiltin_Rectangle = 15,
    ASBuiltin_ColorTransform = 16,
    ASBuiltin_Capabilities  = 17,
    ASBuiltin_Stage         = 18,
    ASBuiltin_AsBroadcaster = 19,
    ASBuiltin_Date          = 20,
    ASBuiltin_Selection     = 21,
    ASBuiltin_Math          = 25,
    ASBuiltin_Mouse         = 27,
    ASBuiltin_ExternalInterface = 28,
    ASBuiltin_MovieClipLoader = 29,
    ASBuiltin_BitmapData      = 30,
    ASBuiltin_LoadVars        = 31,
    ASBuiltin_TextFormat       = 32,
    ASBuiltin_StyleSheet       = 33,
    ASBuiltin_NetStream        = 35,
    ASBuiltin_Video            = 36,
    ASBuiltin_BitmapFilter     = 37,
    ASBuiltin_DropShadowFilter = 38,
    ASBuiltin_GlowFilter       = 39,
    ASBuiltin_BlurFilter       = 40,
    ASBuiltin_BevelFilter      = 41,
    ASBuiltin_ColorMatrixFilter = 42,
    ASBuiltin_TextSnapshot     = 43,
    ASBuiltin_SharedObject     = 44,
    ASBuiltin_unknown_         = 46,
    ASBuiltin_dot_             = 49, // "."
    ASBuiltin_dotdot_          = 50, // ".."
    ASBuiltin_undefined        = 51,
    ASBuiltin_this             = 61,
    ASBuiltin_super            = 62,
    ASBuiltin__root            = 64, // "_root"
    ASBuiltin__parent          = 65, // "_parent"
    ASBuiltin_arguments        = 68,
    ASBuiltin_prototype        = 77,
    ASBuiltin___proto__        = 78,
    ASBuiltin_constructor      = 79,
    ASBuiltin___constructor__  = 80,
    ASBuiltin__listeners       = 81, // "_listeners"
    ASBuiltin___resolve        = 82,
    ASBuiltin_typeFunction_    = 83, // "[type Function]"
    ASBuiltin_typeObject_      = 84, // "[type Object]"
    ASBuiltin_objectObject_    = 85, // "[object Object]"
    ASBuiltin_INVALID          = 90,
    ASBuiltin_onPress          = 91,
    ASBuiltin_onRelease        = 92,
    ASBuiltin_onReleaseOutside = 93,
    ASBuiltin_onRollOver       = 94,
    ASBuiltin_onRollOut        = 95,
    ASBuiltin_onDragOver       = 96,
    ASBuiltin_onDragOut        = 97,
    ASBuiltin_akeyPressa_      = 98,
    ASBuiltin_ainitializea_    = 99,
    ASBuiltin_onLoad           = 100,
    ASBuiltin_onUnload         = 101,
    ASBuiltin_onEnterFrame     = 102,
    ASBuiltin_onMouseDown      = 103,
    ASBuiltin_onMouseUp        = 104,
    ASBuiltin_onMouseMove      = 105,
    ASBuiltin_onMouseWheel     = 106,
    ASBuiltin_onKeyDown        = 107,
    ASBuiltin_onKeyUp          = 108,
    ASBuiltin_onData           = 109,
    ASBuiltin_onConstruct      = 110,
    ASBuiltin_onLoadStart      = 111,
    ASBuiltin_onLoadError      = 112,
    ASBuiltin_onLoadProgress   = 113,
    ASBuiltin_onLoadInit       = 114,
    ASBuiltin_onSockClose      = 115,
    ASBuiltin_onSockConnect    = 116,
    ASBuiltin_onSockData       = 117,
    ASBuiltin_onSockXML        = 118,
    ASBuiltin_onXMLLoad        = 119,
    ASBuiltin_onXMLData        = 120,
    ASBuiltin_onPressAux       = 121,
    ASBuiltin_onReleaseAux     = 122,
    ASBuiltin_onReleaseOutsideAux = 123,
    ASBuiltin_onDragOverAux    = 124,
    ASBuiltin_onDragOutAux     = 125,
    ASBuiltin_width  = 126,
    ASBuiltin_height = 127,
    ASBuiltin_useHandCursor = 128,
    ASBuiltin_x      = 129,
    ASBuiltin_y      = 130,
    ASBuiltin_xMin   = 131, // getBounds / getRect result members
    ASBuiltin_xMax   = 132,
    ASBuiltin_yMin   = 133,
    ASBuiltin_yMax   = 134,
    ASBuiltin_hitArea       = 135,
    ASBuiltin_setCursorType = 136, // Mouse extension members
    ASBuiltin_LEFT   = 137,
    ASBuiltin_RIGHT  = 138,
    ASBuiltin_MIDDLE = 139,
    ASBuiltin_ARROW  = 140,
    ASBuiltin_HAND   = 141,
    ASBuiltin_IBEAM  = 142,
    ASBuiltin_0      = 143, // "0" .. "7" follow
    ASBuiltin_rendererString = 151, // movie clip renderer hints
    ASBuiltin_rendererFloat  = 152,
    ASBuiltin_rendererMatrix = 153,
    ASBuiltin_Amp            = 154,
    ASBuiltin_length = 155,
};
// The last digit with a builtin name.
enum { ASBuiltinConst_DigitMax_ = 7 };

class StringManager;

// The builtin name of the handler method of an event (onPress, onEnterFrame, ...) (exe 0x142939c60).
ASBuiltinType EventId_GetFunctionNameBuiltinType(const EventId& evt);
// Its string (exe 0x142939c20).
ASString EventId_GetFunctionName(StringManager* psm, const EventId& evt);

// Builtin strings of a movie plus the manager that makes new ones. 0x4f0 bytes.
class StringManager
{
public:
    enum { BuiltinCount = 156 };

    ASStringNodeHolder Builtins[BuiltinCount]; // +0x000 one per ASBuiltinType
    ASStringManager*   pStringManager;         // +0x4e0
    const char**       pStaticStrings;         // +0x4e8

    // The builtins come from the static name table (exe 0x142920e10).
    StringManager(ASStringManager* pmgr);

    // The names of the ASBuiltinType values (exe 0x143a51c30).
    static const char* BuiltinStrings[BuiltinCount];

    const ASString& GetBuiltin(int btype) const { return (const ASString&)Builtins[btype]; }
    ASString        CreateString(const char* pstr, UPInt length) const
    {
        return pStringManager->CreateString(pstr, length);
    }
    ASString CreateString(const char* pstr) const { return ASString(pStringManager->CreateStringNode(pstr)); }
    ASString CreateString(const wchar_t* pwstr) const { return ASString(pStringManager->CreateStringNode(pwstr)); }
    // A string over the literal itself (not copied).
    ASString CreateConstString(const char* pstr) const
    {
        return pStringManager->CreateConstString(pstr, strlen(pstr));
    }
};

// Memory of an AS2 movie (heap, string manager, collector, text allocator).
class MemoryContextImpl : public MemoryContext
{
public:
    // The heap's emergency collection handler (embedded at +0x30 in the executable context).
    class HeapLimit : public MemoryHeap::LimitHandler
    {
    public:
        MemoryContextImpl* MemContext;             // +0x10
        UPInt UserLevelLimit;                      // +0x18
        UPInt CurrentLimit;                        // +0x20
        UPInt LastCollectionFootprint;             // +0x28
        float HeapLimitMultiplier;                 // +0x30

        bool OnExceedLimit(MemoryHeap* heap, UPInt overLimit); // exe 0x14296bbf0
        void Reset(MemoryHeap* heap);              // exe 0x14297df30
    };

    MemoryHeap*                   Heap;                 // +0x10 the movie's heap
    UByte                         Unrecovered_18[0x08]; // +0x18
    ASRefCountCollector*          ASGC;                 // +0x20
    Ptr<Render::Text::Allocator> TextAllocator;        // +0x28 created on first use (MovieRoot::GetTextAllocator)
};

// AS2 half of a movie.
class MovieRoot : public ASMovieRootBase
{
public:
    UByte              Unrecovered_28[0x10];  // +0x28
    MemoryContextImpl* MemContext;            // +0x38
    UByte              Unrecovered_40[0x8];   // +0x40
    MouseListener*     pMouseListener;        // +0x48 the Mouse class (set by its constructor)
    Ptr<GlobalContext> pGlobalContext;        // +0x50
    Value              ExternalIntfRetVal;    // +0x58 set by the host handler of ExternalInterface.call
    UByte              Unrecovered_78[0xc0];  // +0x78
    StringManager      BuiltinsMgr;           // +0x138

    ASRefCountCollector* GetASGC() const { return MemContext->ASGC; }

    // A script function the host can call by name (ExternalInterface.addCallback). 0x28 bytes.
    struct InvokeAliasInfo
    {
        Ptr<Object>          ThisObject; // +0x00
        Ptr<CharacterHandle> ThisChar;   // +0x08
        FunctionRef          Function;   // +0x10

        ~InvokeAliasInfo(); // exe 0x142925ae0
    };
    // Registers (or replaces) the alias the host calls by name (exe 0x14292f430).
    void AddInvokeAlias(const ASString& alias, CharacterHandle* pthisChar, Object* pthisObj, const FunctionRef& func);

    StringManager* GetStringManager() { return &BuiltinsMgr; }

    // The number of a "<n>" or "_level<n>" name (the word case-insensitive unless asked), *ptail set past the
    // digits; -1 if it is neither (exe 0x14296e790).
    static int ParseLevelName(const char* pname, const char** ptail, bool caseSensitive);

    bool SetLevelMovie(int level, Sprite* psprite); // exe 0x142981d80
    // The directory of _level0's URL (exe 0x14294b090).
    bool GetLevel0Path(String* ppath) const;
    // (appended for sfr_as2_05) the clip loaded as _level<level>, 0 if none (exe 0x14294b120).
    Sprite* GetLevelMovie(int level) const;
    // A new empty movie clip loaded as _level<level> (loadVariables into a missing level) (exe 0x1429360e0).
    Sprite* CreateEmptyLevelMovie(LoadStates* pls, int level);

    // Attaches the movie and gives it a new global context (exe 0x1429891c0).
    virtual void SetMovie(MovieImpl* pmovie);

    // A host value holding the string, converted through the _level0 environment.
    virtual void CreateString(GFx::Value* pvalue, const char* pstring);      // exe 0x142937d60
    virtual void CreateStringW(GFx::Value* pvalue, const wchar_t* pstring);  // exe 0x142937ea0
    // A new Array object as a host value (exe 0x142935dc0).
    virtual void CreateArray(GFx::Value* pvalue);
    // A host function object calling pfc with puserData (exe 0x142936360).
    virtual void CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData);
    // Converts v into a host value (exe 0x14292dc70).
    void ASValue2GFxValue(Environment* penv, const Value& v, GFx::Value* pdestVal) const;

    // Queues a load of purl into ptarget, an empty url unloads it (exe 0x14292f740).
    void AddLoadQueueEntry(InteractiveObject* ptarget, const char* purl,
                           LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None,
                           MovieClipLoader* pmovieClipLoader = 0);
    // Queues a variables load of purl into ptarget (exe 0x142930a10).
    void AddVarLoadQueueEntry(InteractiveObject* ptarget, const char* purl,
                              LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None);
    // Appends the load to the movie's queue (exe 0x142930090).
    void AddMovieLoadQueueEntry(LoadQueueEntry* pentry);
    // Hands the load to a loader thread task (exe 0x14292fc90).
    void AddLoadQueueEntryMT(LoadQueueEntry* pentry);

    // A queued action: a frame's action buffer, a clip event, or a function call on the character. 0x78 bytes.
    struct ActionEntry
    {
        enum EntryType
        {
            Entry_None,
            Entry_Buffer,    // ActionBuffer
            Entry_Event,     // EventId
            Entry_Function,  // Function(FunctionParams)
            Entry_CFunction  // CFunction(FunctionParams)
        };

        ActionEntry*           pNextEntry;     // +0x00
        EntryType              Type;           // +0x08
        Ptr<InteractiveObject> pCharacter;     // +0x10
        Ptr<ActionBuffer>      pActionBuffer;  // +0x18
        EventId                mEventId;       // +0x20
        FunctionRef            Function;       // +0x38
        CFunctionPtr           CFunction;      // +0x50
        Array<Value>           FunctionParams; // +0x58
        unsigned               SessionId;      // +0x70 the DoActionsForSession batch it belongs to

        // (appended for sfr_as2_06) An empty entry (inline in sfr_as2_06).
        inline ActionEntry();
        // Exe 0x142925190, defined in sfr_as2_04.
        ~ActionEntry();

        // Runs the action on its character (exe 0x14293fbe0).
        void Execute(MovieRoot* proot) const;
    };
    // A new empty entry queued at prio (exe 0x1429620d0).
    ActionEntry* InsertEmptyAction(ActionPriority::Priority prio = ActionPriority::AP_Frame);

    // The queued actions per priority (only the members used so far).
    struct ActionQueueType
    {
        // A priority level: the queued entries, from pActionRoot to pLastEntry.
        struct Level
        {
            ActionEntry* pActionRoot;  // +0x00
            ActionEntry* pInsertEntry; // +0x08
            ActionEntry* pLastEntry;   // +0x10
        };
        enum { AL_Count = 6, FreeEntriesLimit = 50 };

        Level        Levels[AL_Count];  // +0x00
        int          ModId;             // +0x90 bumped when the queue changes under an iterator
        ActionEntry* pFreeEntry;        // +0x98 the recycled entries
        unsigned     Field_a0;          // +0xa0 (not identified yet)
        unsigned     FreeEntriesCount;  // +0xa4

        // Clears pentry and keeps it for reuse (up to FreeEntriesLimit), deletes it otherwise (exe 0x142930910).
        void AddToFreeList(ActionEntry* pentry);
        // Drops every queued action (exe 0x142934390).
        void Clear();

        // (appended for sfr_as2_06)
        void*       Field_a8; // +0xa8 (not identified yet)
        MemoryHeap* pHeap;    // +0xb0 where new entries are allocated

        // A recycled entry, or a new one from the heap (inline in sfr_as2_06).
        inline ActionEntry* GetNewEntry();
        // A recycled or new entry linked in after the level's insert point, for the current session (Field_a0)
        // (exe 0x1429621f0); 0 if out of memory.
        ActionEntry* InsertEntry(ActionPriority::Priority prio);
    };

    // Walks the queue in priority order; entries handed out go back to the free list.
    struct ActionQueueIterator
    {
        int              ModId;        // +0x00
        ActionQueueType* pActionQueue; // +0x08
        ActionEntry*     pLastEntry;   // +0x10
        int              CurrentPrio;  // +0x18

        ActionQueueIterator(ActionQueueType* pactionQueue)
        {
            pActionQueue = pactionQueue;
            ModId        = 0;
            CurrentPrio  = 0;
            pLastEntry   = 0;
        }
        ~ActionQueueIterator()
        {
            if (pLastEntry)
                pActionQueue->AddToFreeList(pLastEntry);
        }

        const ActionEntry* getNext(); // exe 0x142995180
    };

    // The action queue (+0x80, inside the unrecovered block).
    ActionQueueType& GetActionQueue() { return *reinterpret_cast<ActionQueueType*>(Unrecovered_78 + 0x08); }
    // Runs every queued action (exe 0x142938bd0).
    virtual void DoActions();
    // Runs the queued actions of one session only, the others stay queued (exe 0x142938c40).
    void DoActionsForSession(unsigned sessionId);

    // The text allocator of the movie's memory context, created on first use (exe 0x142956380).
    virtual Render::Text::Allocator* GetTextAllocator();
    // The value of a variable path from _level0 as a host value; false without a _level0 or if not found
    // (exe 0x142957100).
    virtual bool GetVariable(GFx::Value* pval, const char* ppathToVar) const;
    // The length of the Array a variable path from _level0 names, 0 otherwise (exe 0x1429579a0).
    virtual unsigned GetVariableArraySize(const char* ppathToVar);
    // (appended for sfr_as2_02) a new sprite of the timeline, with an added reference (exe 0x142937cf0).
    Sprite* CreateSprite(TimelineDef* ptimelineDef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                         ResourceId id, bool loadedSeparately = false);
    // (appended for sfr_as2_06) focus changes reach Selection through the _level0 environment.
    virtual void NotifyQueueSetFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt); // exe 0x14296a850
    virtual void NotifyTransferFocus(InteractiveObject* curFocused, InteractiveObject* pnewFocus,
                                     unsigned controllerIdx);                                          // exe 0x14296a8f0
    // A mouse focus change needs one of the two characters to take mouse focus (exe 0x1429697f0).
    virtual bool NotifyOnFocusChange(InteractiveObject* curFocused, InteractiveObject* toBeFocused,
                                     unsigned controllerIdx, FocusMovedType fmt, ProcessFocusKeyInfo* pfocusKeyInfo);
    // (appended for sfr_as2_06) host calls of a script method of pmovie (or _level0): through the invoke alias of
    // that name when there is one (exe 0x1429635f0, 0x142963a10).
    virtual bool Invoke(InteractiveObject* pmovie, const char* pmethodName, GFx::Value* presult,
                        const GFx::Value* pargs, unsigned numArgs);
    virtual bool Invoke(const char* pmethodName, GFx::Value* presult, const GFx::Value* pargs, unsigned numArgs);
    // Converts a host value into a script value (exe 0x142992ee0).
    void Value2ASValue(const GFx::Value& gfxVal, Value* pdestVal);
    // The alias registered under pstr, 0 if none (exe 0x14297ed30).
    InvokeAliasInfo* ResolveInvokeAlias(const char* pstr) const;
    // Calls the alias with the numArgs arguments on the _level0 stack (exe 0x142963b90).
    bool InvokeAlias(const char* pmethodName, const InvokeAliasInfo& iai, Value* presult, unsigned numArgs);
    // Queues Stage.onResize on _level0 (exe 0x14296a450).
    virtual void NotifyOnResize();
};

// The AS2 root of a character of an AS2 movie.
inline MovieRoot* ToAS2Root(DisplayObjectBase* pchar)
{
    return static_cast<MovieRoot*>(pchar->GetASMovieRoot());
}

inline const ASString& ASStringContext::GetBuiltin(int btype) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(btype);
}

inline void ASStringContext::InvalidateOptAdvanceList() const
{
    if (pContext)
        pContext->pMovieRoot->Flags |= MovieImpl::Flag_OptAdvListInvalid;
}

inline ASString ASStringContext::CreateString(const char* pstr) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateString(pstr);
}

inline ASString ASStringContext::CreateString(const wchar_t* pwstr) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateString(pwstr);
}

inline ASString Environment::CreateString(const char* pstr) const
{
    return StringContext.CreateString(pstr);
}

inline ASString Environment::CreateConstString(const char* pstr) const
{
    return ((MovieRoot*)StringContext.pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateConstString(pstr);
}

// (appended for sfr_video_01)
inline ASString ASStringContext::CreateConstString(const char* pstr) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateConstString(pstr);
}

// The collector of the movie, or 0 without a context or a movie.
inline ASRefCountCollector* ASStringContext::GetGC()
{
    if (pContext && pContext->pMovieRoot)
        return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetASGC();
    return 0;
}

inline ASString ASStringContext::CreateString(const char* pstr, UPInt length) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateString(pstr, length);
}

inline ASString ASStringContext::CreateString(const String& str) const
{
    return CreateString(str.ToCStr(), str.GetSize());
}

inline ASString Environment::CreateString(const String& str) const
{
    return StringContext.CreateString(str);
}

}}} // namespace Scaleform::GFx::AS2

#endif
