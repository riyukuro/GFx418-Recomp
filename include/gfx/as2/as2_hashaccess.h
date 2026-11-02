// Access to the string tables' findIndexAlt. HashSetBase keeps it private and the exe calls it out of
// line, so this goes through member pointers, which an explicit instantiation may name.
#ifndef MS2_SF_GFX_AS2_HASHACCESS_H
#define MS2_SF_GFX_AS2_HASHACCESS_H

#include "as2_object.h"

namespace Scaleform { namespace GFx { namespace AS2 {

template <class H, class K, SPInt (H::SetType::*Fn)(const K&) const>
struct HashFindIndexAccess
{
    friend SPInt HashFindIndex(const H* phash, const K& key)
    {
        return (reinterpret_cast<const typename H::SetType*>(phash)->*Fn)(key);
    }
};

#define MS2_AS2_HASH_FINDINDEX(T)                                                                     \
    inline SPInt HashFindIndex(const ASStringHash_GC<T>* phash, const ASString& key);                 \
    inline SPInt HashFindIndex(const ASStringHash_GC<T>* phash, const ASStringNoCaseKey& key);        \
    template struct HashFindIndexAccess<ASStringHash_GC<T>, ASString,                                 \
        &ASStringHash_GC<T>::SetType::findIndexAlt<ASString> >;                             \
    template struct HashFindIndexAccess<ASStringHash_GC<T>, ASStringNoCaseKey,                        \
        &ASStringHash_GC<T>::SetType::findIndexAlt<ASStringNoCaseKey> >;

}}} // namespace Scaleform::GFx::AS2

#endif
