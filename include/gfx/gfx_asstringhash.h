// Recovered Scaleform 4.1.18 GFx: hashing of ActionScript strings as hash keys (exact and case-insensitive).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Equal text shares one node, so an exact match is a node compare; a case-insensitive match compares the lowercase
// twins of the nodes.
#ifndef MS2_SF_GFX_ASSTRINGHASH_H
#define MS2_SF_GFX_ASSTRINGHASH_H

#include "gfx_asstring.h"

namespace Scaleform { namespace GFx {

// Case-insensitive lookup key: resolves the lowercase twin of the looked up string on construction.
struct ASStringNoCaseKey
{
    const ASString* pStr;

    ASStringNoCaseKey(const ASString& str) : pStr(&str) { str.ResolveLowercase(); }
};

inline bool operator==(const ASString& a, const ASString& b)
{
    return a.GetNode() == b.GetNode();
}

// keystr has its lowercase twin resolved already.
inline bool ASStringCompareNoCaseResolved(const ASString& keystr, const ASString& str)
{
    str.ResolveLowercase();
    return keystr.GetNode()->pLower == str.GetNode()->pLower;
}

inline bool operator==(const ASString& str, const ASStringNoCaseKey& key)
{
    return ASStringCompareNoCaseResolved(*key.pStr, str);
}

// The full hash-and-flags word is the hash: the table mask drops the flag bits.
struct ASStringHashFunctor
{
    UPInt operator()(const ASString& str) const          { return str.GetHashFlags(); }
    UPInt operator()(const ASStringNoCaseKey& key) const { return key.pStr->GetHashFlags(); }
};

}} // namespace Scaleform::GFx

#endif
