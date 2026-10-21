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
    ASBuiltin_Array  = 2,
    ASBuiltin_Number  = 4,
    ASBuiltin_Boolean = 5,
    ASBuiltin_DropShadowFilter = 38,
    ASBuiltin_GlowFilter       = 39,
    ASBuiltin_BlurFilter       = 40,
    ASBuiltin_undefined        = 51,
    ASBuiltin_typeFunction_    = 83, // "[type Function]"
    ASBuiltin_objectObject_    = 85, // "[object Object]"
    ASBuiltin_x      = 129,
    ASBuiltin_y      = 130,
};

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

    // Queues a load of purl into ptarget, an empty url unloads it (exe 0x14292f740).
    void AddLoadQueueEntry(InteractiveObject* ptarget, const char* purl,
                           LoadQueueEntry::LoadMethod method = LoadQueueEntry::LM_None,
                           MovieClipLoader* pmovieClipLoader = 0);
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
