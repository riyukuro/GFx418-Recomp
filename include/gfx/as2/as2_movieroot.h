// Recovered Scaleform 4.1.18 GFx AS2: the AS2 movie root, as far as the recovered units read it (the builtin
// string table), and the builtin string ids. Shared header of the src/ms2/scaleform units (sfr lane): append,
// do not reorder members or enumerators.
#ifndef MS2_SF_GFX_AS2_MOVIEROOT_H
#define MS2_SF_GFX_AS2_MOVIEROOT_H

#include "as2_action.h"
#include "../gfx_displayobject.h"
#include "../gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Ids of the strings every AS2 movie creates up front (index into StringManager::Builtins).
enum ASBuiltinType : int
{
    ASBuiltin_empty_ = 0, // ""
    ASBuiltin_Array  = 2,
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
};

// AS2 half of a movie.
class MovieRoot : public ASMovieRootBase
{
public:
    UByte         Unrecovered_28[0x110]; // +0x28
    StringManager BuiltinsMgr;           // +0x138

    StringManager* GetStringManager() { return &BuiltinsMgr; }
};

inline const ASString& ASStringContext::GetBuiltin(int btype) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(btype);
}

inline ASString ASStringContext::CreateString(const char* pstr, UPInt length) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->CreateString(pstr, length);
}

}}} // namespace Scaleform::GFx::AS2

#endif
