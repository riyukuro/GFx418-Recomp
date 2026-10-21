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

namespace Scaleform { namespace GFx { namespace AS2 {

class MovieClipLoader;

// Ids of the strings every AS2 movie creates up front (index into StringManager::Builtins).
enum ASBuiltinType : int
{
    ASBuiltin_empty_ = 0, // ""
    ASBuiltin_Object = 1,
    ASBuiltin_Array  = 2,
    ASBuiltin_String = 3,
    ASBuiltin_Number  = 4,
    ASBuiltin_Boolean = 5,
    ASBuiltin_AsBroadcaster = 19,
    ASBuiltin_Date          = 20,
    ASBuiltin_Selection     = 21,
    ASBuiltin_Mouse         = 27,
    ASBuiltin_MovieClipLoader = 29,
    ASBuiltin_DropShadowFilter = 38,
    ASBuiltin_GlowFilter       = 39,
    ASBuiltin_BlurFilter       = 40,
    ASBuiltin_unknown_         = 46,
    ASBuiltin_undefined        = 51,
    ASBuiltin_prototype        = 77,
    ASBuiltin___proto__        = 78,
    ASBuiltin_constructor      = 79,
    ASBuiltin___constructor__  = 80,
    ASBuiltin__listeners       = 81, // "_listeners"
    ASBuiltin___resolve        = 82,
    ASBuiltin_typeFunction_    = 83, // "[type Function]"
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
    ASBuiltin_x      = 129,
    ASBuiltin_y      = 130,
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

    const ASString& GetBuiltin(int btype) const { return (const ASString&)Builtins[btype]; }
    ASString        CreateString(const char* pstr, UPInt length) const
    {
        return pStringManager->CreateString(pstr, length);
    }
    ASString CreateString(const char* pstr) const { return ASString(pStringManager->CreateStringNode(pstr)); }
};

// Memory of an AS2 movie (heap, string manager, collector); only the collector is read so far.
class MemoryContextImpl : public MemoryContext
{
public:
    UByte                Unrecovered_10[0x10]; // +0x10
    ASRefCountCollector* ASGC;                 // +0x20
};

// AS2 half of a movie.
class MovieRoot : public ASMovieRootBase
{
public:
    UByte              Unrecovered_28[0x10];  // +0x28
    MemoryContextImpl* MemContext;            // +0x38
    UByte              Unrecovered_40[0xf8];  // +0x40
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

    StringManager* GetStringManager() { return &BuiltinsMgr; }

    // The number of a "<n>" or "_level<n>" name (the word case-insensitive unless asked), *ptail set past the
    // digits; -1 if it is neither (exe 0x14296e790).
    static int ParseLevelName(const char* pname, const char** ptail, bool caseSensitive);

    bool SetLevelMovie(int level, Sprite* psprite); // exe 0x142981d80

    // Queues a load of purl into ptarget, an empty url unloads it (exe 0x14292f740).
    void AddLoadQueueEntry(InteractiveObject* ptarget, const char* purl,
                           LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None,
                           MovieClipLoader* pmovieClipLoader = 0);

    struct ActionEntry;

    // The queued actions per priority (only the members used so far).
    struct ActionQueueType
    {
        void AddToFreeList(ActionEntry* pentry); // exe 0x142930910
        // Drops every queued action (exe 0x142934390).
        void Clear();
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

inline ASString Environment::CreateString(const char* pstr) const
{
    return StringContext.CreateString(pstr);
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
