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

// Slot of the collected string hashes (ASStringHash_GC): freeing a slot drops the key and finalizes the value
// instead of destroying it, the collector owns what the value points to.
template<class C, class HashF>
class HashsetNodeEntry_GC
{
public:
    SPInt NextInChain;
    C     Value;

    HashsetNodeEntry_GC() : NextInChain(-2) {}
    HashsetNodeEntry_GC(const HashsetNodeEntry_GC& o) : NextInChain(o.NextInChain), Value(o.Value) {}
    template<class K>
    HashsetNodeEntry_GC(const K& key, SPInt next) : NextInChain(next), Value(key) {}

    bool IsEmpty() const      { return NextInChain == -2; }
    bool IsEndOfChain() const { return NextInChain == -1; }

    UPInt GetCachedHash(UPInt mask) const { return HashF()(Value) & mask; }
    void  SetCachedHash(UPInt)            {}

    void Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free()
    {
        typedef typename C::FirstType FirstType;
        Value.First.~FirstType();
        Value.Second.Finalize_GC();
        NextInChain = -2;
    }
};

// Lookups of a hash keyed by script strings, exact or ignoring case (SWF 6 and older are case-insensitive).
template<class U, class BaseType>
class ASStringHashBase : public BaseType
{
public:
    const U* GetCaseInsensitive(const ASString& key) const
    {
        ASStringNoCaseKey ikey(key);
        return BaseType::GetAlt(ikey);
    }
    U* GetCaseInsensitive(const ASString& key)
    {
        ASStringNoCaseKey ikey(key);
        return BaseType::GetAlt(ikey);
    }

    const U* GetCaseCheck(const ASString& key, bool caseSensitive) const
    {
        return caseSensitive ? BaseType::Get(key) : GetCaseInsensitive(key);
    }
    U* GetCaseCheck(const ASString& key, bool caseSensitive)
    {
        return caseSensitive ? BaseType::Get(key) : GetCaseInsensitive(key);
    }
    // Copies the value out when found (pvalue may be null).
    bool GetCaseCheck(const ASString& key, U* pvalue, bool caseSensitive) const
    {
        if (caseSensitive)
            return BaseType::Get(key, pvalue);
        ASStringNoCaseKey ikey(key);
        return BaseType::GetAlt(ikey, pvalue);
    }

    __forceinline typename BaseType::Iterator FindCaseInsensitive(const ASString& key)
    {
        ASStringNoCaseKey ikey(key);
        return BaseType::FindAlt(ikey);
    }
    __forceinline typename BaseType::Iterator FindCaseCheck(const ASString& key, bool caseSensitive)
    {
        return caseSensitive ? BaseType::Find(key) : FindCaseInsensitive(key);
    }

    // Replaces the value of the matching key, else adds the pair.
    void SetCaseCheck(const ASString& key, const U& value, bool caseSensitive)
    {
        typename BaseType::Iterator it = FindCaseCheck(key, caseSensitive);
        if (it != BaseType::End())
            it->Second = value;
        else
            BaseType::Add(key, value);
    }
};

// Hash by script string in the string heap (one table pointer).
template<class U>
class ASStringHash : public ASStringHashBase<U, HashUncachedLH<ASString, U, ASStringHashFunctor, StatMV_ASString_Mem> >
{
};

}} // namespace Scaleform::GFx

#endif
