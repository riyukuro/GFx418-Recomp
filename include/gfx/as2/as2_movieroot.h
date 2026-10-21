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
};

// Builtin strings of a movie plus the manager that makes new ones.
class StringManager
{
public:
    ASStringManager*   pStringManager; // +0x00
    ASStringNodeHolder Builtins[1];    // +0x08 one per ASBuiltinType (count not recovered)

    const ASString& GetBuiltin(int btype) const { return (const ASString&)Builtins[btype]; }
};

// AS2 half of a movie.
class MovieRoot : public ASMovieRootBase
{
public:
    UByte         Unrecovered_28[0x108]; // +0x28
    StringManager BuiltinsMgr;           // +0x130

    StringManager* GetStringManager() { return &BuiltinsMgr; }
};

inline const ASString& ASStringContext::GetBuiltin(int btype) const
{
    return ((MovieRoot*)pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(btype);
}

}}} // namespace Scaleform::GFx::AS2

#endif
