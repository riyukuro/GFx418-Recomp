// Recovered Scaleform 4.1.18 kernel: hash maps keyed by String (case-insensitive hash by default).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_KERNEL_STRINGHASH_H
#define MS2_SF_INC_KERNEL_STRINGHASH_H

#include "sf_hash.h"
#include "sf_string.h"

namespace Scaleform {

// String -> U map in the global heap.
template<class U, class Allocator = AllocatorGH<U> >
class StringHash : public Hash<String, U, String::NoCaseHashFunctor, Allocator>
{
public:
    typedef StringHash<U, Allocator>                                SelfType;
    typedef Hash<String, U, String::NoCaseHashFunctor, Allocator>   BaseType;

    void operator=(const SelfType& src) { BaseType::operator=(src); }

    bool GetCaseInsensitive(const String& key, U* pvalue) const
    {
        String::NoCaseKey ikey(key);
        return BaseType::GetAlt(ikey, pvalue);
    }
    U* GetCaseInsensitive(const String& key)
    {
        String::NoCaseKey ikey(key);
        return BaseType::GetAlt(ikey);
    }
    typename BaseType::Iterator FindCaseInsensitive(const String& key)
    {
        String::NoCaseKey ikey(key);
        return BaseType::FindAlt(ikey);
    }
    // Replaces the value of a key that matches regardless of case, else adds the key as given.
    void SetCaseInsensitive(const String& key, const U& value)
    {
        typename BaseType::Iterator it = FindCaseInsensitive(key);
        if (it != BaseType::End())
            (*it).Second = value;
        else
            BaseType::Add(key, value);
    }
};

// Node of a map whose key string lives in the map's own heap.
template<class U, class HashF>
struct StringLH_HashNode
{
    typedef StringLH_HashNode<U, HashF> SelfType;

    StringLH First;
    U        Second;

    struct NodeRef
    {
        const String* pFirst;
        const U*      pSecond;

        NodeRef(const String& f, const U& s) : pFirst(&f), pSecond(&s) {}
        NodeRef(const NodeRef& src) : pFirst(src.pFirst), pSecond(src.pSecond) {}

        UPInt GetHash() const { return HashF()(*pFirst); }
        operator const String&() const { return *pFirst; }
    };

    StringLH_HashNode(const StringLH_HashNode& src) : First(src.First), Second(src.Second) {}
    StringLH_HashNode(const NodeRef& src) : First(*src.pFirst), Second(*src.pSecond) {}
    void operator=(const NodeRef& src)
    {
        First  = *src.pFirst;
        Second = *src.pSecond;
    }

    template<class K>
    bool operator==(const K& src) const { return (First == src); }

    template<class K>
    static UPInt CalcHash(const K& data) { return HashF()(data); }
    UPInt GetHash() const { return HashF()(First); }

    struct NodeHashF
    {
        template<class K>
        UPInt operator()(const K& data) const { return data.GetHash(); }
    };
    struct NodeAltHashF
    {
        template<class K>
        UPInt operator()(const K& data) const { return SelfType::CalcHash(data); }
    };
};

// String -> U map allocated in the heap that holds the map.
template<class U, int SID = Stat_Default_Mem, class HashF = String::NoCaseHashFunctor,
         class HashNodeT = StringLH_HashNode<U, HashF>,
         class Entry     = HashsetCachedNodeEntry<HashNodeT, typename HashNodeT::NodeHashF> >
class StringHashLH : public Hash<StringLH, U, HashF, AllocatorLH<U, SID>, HashNodeT, Entry>
{
public:
    typedef StringHashLH<U, SID, HashF, HashNodeT, Entry>                  SelfType;
    typedef Hash<StringLH, U, HashF, AllocatorLH<U, SID>, HashNodeT, Entry> BaseType;
    typedef typename HashNodeT::NodeRef                                     NodeRef;

    void Set(const String& key, const U& value)
    {
        NodeRef e(key, value);
        BaseType::mHash.Set(e);
    }
    void Add(const String& key, const U& value)
    {
        NodeRef e(key, value);
        BaseType::mHash.Add(e);
    }

    U* Get(const String& key)
    {
        HashNodeT* p = BaseType::mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    U* GetCaseInsensitive(const String& key)
    {
        String::NoCaseKey ikey(key);
        HashNodeT*        p = BaseType::mHash.GetAlt(ikey);
        return p ? &p->Second : 0;
    }

    bool GetCaseInsensitive(const String& key, U* pvalue) const
    {
        String::NoCaseKey ikey(key);
        return BaseType::GetAlt(ikey, pvalue);
    }
    typename BaseType::Iterator FindCaseInsensitive(const String& key)
    {
        String::NoCaseKey ikey(key);
        return BaseType::mHash.FindAlt(ikey);
    }
    // Replaces the value of a key that matches regardless of case, else adds the key as given.
    void SetCaseInsensitive(const String& key, const U& value)
    {
        typename BaseType::Iterator it = FindCaseInsensitive(key);
        if (it != BaseType::End())
            (*it).Second = value;
        else
            Add(key, value);
    }
};

} // namespace Scaleform

#endif
