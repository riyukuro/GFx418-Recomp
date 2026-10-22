// Recovered Scaleform 4.1.18 kernel: open-addressed hash sets with in-table collision chains.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Table block: { UPInt EntryCount; UPInt SizeMask; Entry[SizeMask + 1] }. Entry.NextInChain is -2 for a free slot and
// -1 at the end of a chain. Every chain starts at its natural slot (hash & SizeMask); an entry parked in a foreign
// natural slot is moved out when that slot's owner arrives. The table doubles once it is more than 80% full and
// never has fewer than 8 slots.
#ifndef MS2_SF_KERNEL_HASH_H
#define MS2_SF_KERNEL_HASH_H

#include "sf_allocator.h"
#include "sf_alg.h"

namespace Scaleform {

template<class C>
class IdentityHash
{
public:
    UPInt operator()(const C& v) const { return (UPInt)v; }
};

// sdbm over the raw bytes, walked from the last byte to the first.
template<class C>
class FixedSizeHash
{
public:
    static inline UPInt SDBM_Hash(const void* pv, UPInt n, UPInt seed = 5381)
    {
        const UByte* bytes = (const UByte*)pv;
        UPInt        h     = seed;
        while (n > 0)
        {
            n--;
            h = (h << 16) + (h << 6) - h + (UPInt)bytes[n];
        }
        return h;
    }

    UPInt operator()(const C& v) const
    {
        unsigned char* bytes = (unsigned char*)&v;
        int            n     = sizeof(C);
        return SDBM_Hash(bytes, n);
    }
};

// Slot without a stored hash: recomputed from the value when needed.
template<class C, class HashF>
class HashsetEntry
{
public:
    SPInt NextInChain;
    C     Value;

    HashsetEntry() : NextInChain(-2) {}
    HashsetEntry(const HashsetEntry& o) : NextInChain(o.NextInChain), Value(o.Value) {}
    HashsetEntry(const C& v, SPInt next) : NextInChain(next), Value(v) {}

    bool IsEmpty() const      { return NextInChain == -2; }
    bool IsEndOfChain() const { return NextInChain == -1; }

    UPInt GetCachedHash(UPInt mask) const { return HashF()(Value) & mask; }
    void  SetCachedHash(UPInt)            {}

    void Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

// Slot that keeps the masked hash next to the value.
template<class C, class HashF>
class HashsetCachedEntry
{
public:
    SPInt NextInChain;
    UPInt HashValue;
    C     Value;

    HashsetCachedEntry() : NextInChain(-2) {}
    HashsetCachedEntry(const HashsetCachedEntry& o) : NextInChain(o.NextInChain), HashValue(o.HashValue), Value(o.Value) {}
    HashsetCachedEntry(const C& v, SPInt next) : NextInChain(next), Value(v) {}

    bool IsEmpty() const      { return NextInChain == -2; }
    bool IsEndOfChain() const { return NextInChain == -1; }

    UPInt GetCachedHash(UPInt) const { return HashValue; }
    void  SetCachedHash(UPInt h)     { HashValue = h; }

    void Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, class Allocator = AllocatorGH<C>,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSetBase
{
    enum { HashMinSize = 8 };

public:
    SF_MEMORY_REDEFINE_NEW(HashSetBase, Allocator::StatId)

    typedef HashSetBase<C, HashF, AltHashF, Allocator, Entry> SelfType;

    HashSetBase() : pTable(0) {}
    HashSetBase(int sizeHint) : pTable(0) { SetCapacity(this, sizeHint); }
    explicit HashSetBase(void*) : pTable(0) {}
    HashSetBase(void* pheapAddr, int sizeHint) : pTable(0) { SetCapacity(pheapAddr, sizeHint); }
    HashSetBase(const SelfType& o) : pTable(0) { Assign(this, o); }

    ~HashSetBase()
    {
        if (pTable)
        {
            for (UPInt i = 0, last = pTable->SizeMask; i <= last; i++)
            {
                Entry* e = &E(i);
                if (!e->IsEmpty())
                    e->Free();
            }
            Allocator::Free(pTable);
            pTable = 0;
        }
    }

    void Assign(void* pheapAddr, const SelfType& o)
    {
        Clear();
        if (o.IsEmpty() == false)
        {
            SetCapacity(pheapAddr, o.GetSize());
            for (ConstIterator it = o.Begin(); it != o.End(); ++it)
                Add(pheapAddr, *it);
        }
    }

    void Clear()
    {
        if (pTable)
        {
            for (UPInt i = 0, last = pTable->SizeMask; i <= last; i++)
            {
                Entry* e = &E(i);
                if (!e->IsEmpty())
                    e->Clear();
            }
            Allocator::Free(pTable);
            pTable = 0;
        }
    }

    bool IsEmpty() const { return pTable == 0 || pTable->EntryCount == 0; }

    template<class CRef>
    void Set(void* pheapAddr, const CRef& key)
    {
        UPInt h   = HashF()(key);
        SPInt idx = (SPInt)-1;
        if (pTable != 0)
            idx = findIndexCore(key, h & pTable->SizeMask);
        if (idx >= 0)
            E(idx).Value = key;
        else
            add(pheapAddr, key, h);
    }

    template<class CRef>
    inline void Add(void* pheapAddr, const CRef& key)
    {
        UPInt h = HashF()(key);
        add(pheapAddr, key, h);
    }

    template<class K>
    void RemoveAlt(const K& key)
    {
        if (pTable == 0)
            return;

        UPInt  h   = AltHashF()(key);
        SPInt  idx = h & pTable->SizeMask;
        Entry* e   = &E(idx);

        // Nothing chained at this natural slot.
        if (e->IsEmpty() || (e->GetCachedHash(pTable->SizeMask) != (UPInt)idx))
            return;

        SPInt home = idx;
        SPInt prev = -1;
        while ((e->GetCachedHash(pTable->SizeMask) != (UPInt)home) || !(e->Value == key))
        {
            prev = idx;
            idx  = e->NextInChain;
            if (idx == -1)
                return;
            e = &E(idx);
        }

        if (home == idx)
        {
            // Removing the chain head: pull its successor into the natural slot.
            if (!e->IsEndOfChain())
            {
                Entry* next = &E(e->NextInChain);
                e->Clear();
                new (e) Entry(*next);
                e = next;
            }
        }
        else
        {
            E(prev).NextInChain = e->NextInChain;
        }
        e->Clear();
        pTable->EntryCount--;
    }

    template<class CRef>
    void Remove(const CRef& key) { RemoveAlt(key); }

    template<class K>
    C* Get(const K& key)
    {
        SPInt idx = findIndex(key);
        if (idx >= 0)
            return &E(idx).Value;
        return 0;
    }
    template<class K>
    const C* Get(const K& key) const
    {
        SPInt idx = findIndex(key);
        if (idx >= 0)
            return &E(idx).Value;
        return 0;
    }
    template<class K>
    const C* GetAlt(const K& key) const
    {
        SPInt idx = findIndexAlt(key);
        if (idx >= 0)
            return &E(idx).Value;
        return 0;
    }
    template<class K>
    C* GetAlt(const K& key)
    {
        SPInt idx = findIndexAlt(key);
        if (idx >= 0)
            return &E(idx).Value;
        return 0;
    }
    template<class K>
    bool GetAlt(const K& key, C* pout) const
    {
        SPInt idx = findIndexAlt(key);
        if (idx >= 0)
        {
            if (pout)
                *pout = E(idx).Value;
            return true;
        }
        return false;
    }

    UPInt GetSize() const { return pTable == 0 ? 0 : (UPInt)pTable->EntryCount; }

    void CheckExpand(void* pheapAddr)
    {
        if (pTable == 0)
            setRawCapacity(pheapAddr, HashMinSize);
        else if (pTable->EntryCount * 5 > (pTable->SizeMask + 1) * 4)
            setRawCapacity(pheapAddr, (pTable->SizeMask + 1) * 2);
    }

    void Resize(void* pheapAddr, UPInt n) { SetCapacity(pheapAddr, n); }

    void SetCapacity(void* pheapAddr, UPInt n)
    {
        UPInt raw = (n * 5) / 4;
        if (raw <= GetSize())
            return;
        setRawCapacity(pheapAddr, raw);
    }

    struct ConstIterator
    {
        const C& operator*() const  { return pHash->E(Index).Value; }
        const C* operator->() const { return &pHash->E(Index).Value; }

        void operator++()
        {
            if (Index <= (SPInt)pHash->pTable->SizeMask)
            {
                Index++;
                while ((UPInt)Index <= pHash->pTable->SizeMask && pHash->E(Index).IsEmpty())
                    Index++;
            }
        }

        bool operator==(const ConstIterator& o) const
        {
            if (IsEnd() && o.IsEnd())
                return true;
            return (pHash == o.pHash) && (Index == o.Index);
        }
        bool operator!=(const ConstIterator& o) const { return !(*this == o); }

        bool IsEnd() const
        {
            return (pHash == 0) || (pHash->pTable == 0) || (Index > (SPInt)pHash->pTable->SizeMask);
        }

        ConstIterator() : pHash(0), Index(0) {}
        ConstIterator(const SelfType* h, SPInt i) : pHash(h), Index(i) {}

        const SelfType* GetContainer() const { return pHash; }
        SPInt           GetIndex() const     { return Index; }

    protected:
        friend class HashSetBase<C, HashF, AltHashF, Allocator, Entry>;
        const SelfType* pHash;
        SPInt           Index;
    };
    friend struct ConstIterator;

    struct Iterator : public ConstIterator
    {
        C& operator*() const  { return const_cast<SelfType*>(ConstIterator::pHash)->E(ConstIterator::Index).Value; }
        C* operator->() const { return &(operator*()); }

        Iterator() : ConstIterator(0, 0) {}
        Iterator(const SelfType* h, SPInt i) : ConstIterator(h, i) {}

        void Remove() { RemoveAlt(operator*()); }

        // Removes the element under the iterator; steps the iterator back when the successor moves into this slot.
        template<class K>
        void RemoveAlt(const K& key)
        {
            SelfType* hs  = const_cast<SelfType*>(ConstIterator::pHash);
            UPInt     h   = AltHashF()(key);
            SPInt     idx = h & hs->pTable->SizeMask;
            Entry*    e   = &hs->E(idx);

            if (e->IsEmpty() || (e->GetCachedHash(hs->pTable->SizeMask) != (UPInt)idx))
                return;

            SPInt home = idx;
            SPInt prev = -1;
            while ((e->GetCachedHash(hs->pTable->SizeMask) != (UPInt)home) || !(e->Value == key))
            {
                prev = idx;
                idx  = e->NextInChain;
                if (idx == -1)
                    return;
                e = &hs->E(idx);
            }

            if (idx == (SPInt)ConstIterator::Index)
            {
                if (home == idx)
                {
                    if (!e->IsEndOfChain())
                    {
                        Entry* next = &hs->E(e->NextInChain);
                        e->Clear();
                        new (e) Entry(*next);
                        e = next;
                        --ConstIterator::Index;
                    }
                }
                else
                {
                    hs->E(prev).NextInChain = e->NextInChain;
                }
                e->Clear();
                hs->pTable->EntryCount--;
            }
        }
    };
    friend struct Iterator;

    Iterator Begin()
    {
        if (pTable == 0)
            return Iterator(0, 0);
        UPInt first = 0;
        while (first <= pTable->SizeMask && E(first).IsEmpty())
            first++;
        return Iterator(this, first);
    }
    Iterator      End()         { return Iterator(0, 0); }
    ConstIterator Begin() const { return const_cast<SelfType*>(this)->Begin(); }
    ConstIterator End() const   { return const_cast<SelfType*>(this)->End(); }

    template<class K>
    Iterator Find(const K& key)
    {
        SPInt idx = findIndex(key);
        if (idx >= 0)
            return Iterator(this, idx);
        return Iterator(0, 0);
    }
    template<class K>
    Iterator FindAlt(const K& key)
    {
        SPInt idx = findIndexAlt(key);
        if (idx >= 0)
            return Iterator(this, idx);
        return Iterator(0, 0);
    }
    template<class K>
    ConstIterator Find(const K& key) const    { return const_cast<SelfType*>(this)->Find(key); }
    template<class K>
    ConstIterator FindAlt(const K& key) const { return const_cast<SelfType*>(this)->FindAlt(key); }

private:
    template<class K>
    SPInt findIndex(const K& key) const
    {
        if (pTable == 0)
            return -1;
        UPInt h = HashF()(key) & pTable->SizeMask;
        return findIndexCore(key, h);
    }

    template<class K>
    SPInt findIndexAlt(const K& key) const
    {
        if (pTable == 0)
            return -1;
        UPInt h = AltHashF()(key) & pTable->SizeMask;
        return findIndexCore(key, h);
    }

    // h is already masked; walks the chain that starts at slot h.
    template<class K>
    SPInt findIndexCore(const K& key, UPInt h) const
    {
        UPInt        idx = h;
        const Entry* e   = &E(idx);

        if (e->IsEmpty() || (e->GetCachedHash(pTable->SizeMask) != idx))
            return -1;

        for (;;)
        {
            if (e->GetCachedHash(pTable->SizeMask) == h && e->Value == key)
                return idx;
            idx = e->NextInChain;
            if (idx == (UPInt)-1)
                break;
            e = &E(idx);
        }
        return -1;
    }

    template<class CRef>
    void add(void* pheapAddr, const CRef& key, UPInt h)
    {
        CheckExpand(pheapAddr);
        h &= pTable->SizeMask;
        pTable->EntryCount++;

        SPInt  idx  = h;
        Entry* home = &(E(idx));

        if (home->IsEmpty())
        {
            new (home) Entry(key, -1);
        }
        else
        {
            // Linear probe for a free slot.
            SPInt freeIdx = idx;
            do
            {
                freeIdx = (freeIdx + 1) & pTable->SizeMask;
            } while (!E(freeIdx).IsEmpty());
            Entry* freeSlot = &E(freeIdx);

            if (home->GetCachedHash(pTable->SizeMask) == (UPInt)idx)
            {
                // Same chain: the old head moves to the free slot and the new key becomes the head.
                new (freeSlot) Entry(*home);
                home->Value       = key;
                home->NextInChain = freeIdx;
            }
            else
            {
                // The slot is borrowed by another chain: relink that chain to the free slot.
                SPInt walk = home->GetCachedHash(pTable->SizeMask);
                for (;;)
                {
                    Entry* e = &E(walk);
                    if (e->NextInChain == idx)
                    {
                        new (freeSlot) Entry(*home);
                        e->NextInChain = freeIdx;
                        break;
                    }
                    walk = e->NextInChain;
                }
                home->Value       = key;
                home->NextInChain = -1;
            }
        }
        home->SetCachedHash(h);
    }

    Entry&       E(UPInt i)       { return *(((Entry*)(pTable + 1)) + i); }
    const Entry& E(UPInt i) const { return *(((Entry*)(pTable + 1)) + i); }

    // Rounds up to a power of two (minimum 8) and rehashes every live entry into the new block.
    void setRawCapacity(void* pheapAddr, UPInt n)
    {
        if (n == 0)
        {
            Clear();
            return;
        }

        if (n < HashMinSize)
            n = HashMinSize;
        else
        {
            int bits = Alg::UpperBit(n - 1) + 1;
            n        = UPInt(1) << bits;
        }

        SelfType fresh;
        fresh.pTable = (TableType*)Allocator::Alloc(pheapAddr, sizeof(TableType) + sizeof(Entry) * n, 0, 0);
        fresh.pTable->EntryCount = 0;
        fresh.pTable->SizeMask   = n - 1;

        UPInt i, last;
        for (i = 0; i < n; i++)
            fresh.E(i).NextInChain = -2;

        if (pTable)
        {
            for (i = 0, last = pTable->SizeMask; i <= last; i++)
            {
                Entry* e = &E(i);
                if (e->IsEmpty() == false)
                {
                    fresh.Add(pheapAddr, e->Value);
                    e->Clear();
                }
            }
            Allocator::Free(pTable);
        }

        pTable       = fresh.pTable;
        fresh.pTable = 0;
    }

    struct TableType
    {
        UPInt EntryCount;
        UPInt SizeMask;
    };
    TableType* pTable;
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, class Allocator = AllocatorGH<C>,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSet : public HashSetBase<C, HashF, AltHashF, Allocator, Entry>
{
public:
    typedef HashSetBase<C, HashF, AltHashF, Allocator, Entry> BaseType;
    typedef HashSet<C, HashF, AltHashF, Allocator, Entry>     SelfType;

    HashSet() {}
    HashSet(int sizeHint) : BaseType(sizeHint) {}
    explicit HashSet(void* pheap) : BaseType(pheap) {}
    HashSet(void* pheap, int sizeHint) : BaseType(pheap, sizeHint) {}
    HashSet(const SelfType& o) : BaseType(o) {}
    ~HashSet() {}

    void operator=(const SelfType& o) { BaseType::Assign(this, o); }

    template<class CRef>
    void Set(const CRef& key) { BaseType::Set(this, key); }
    template<class CRef>
    inline void Add(const CRef& key) { BaseType::Add(this, key); }

    void CheckExpand()          { BaseType::CheckExpand(this); }
    void Resize(UPInt n)        { BaseType::SetCapacity(this, n); }
    void SetCapacity(UPInt n)   { BaseType::SetCapacity(this, n); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSetLH : public HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, Entry>
{
public:
    typedef HashSetLH<C, HashF, AltHashF, SID, Entry>                SelfType;
    typedef HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, Entry> BaseType;

    HashSetLH() {}
    HashSetLH(int sizeHint) : BaseType(sizeHint) {}
    HashSetLH(const SelfType& o) : BaseType(o) {}
    ~HashSetLH() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, class Allocator = AllocatorGH<C> >
class HashSetUncached : public HashSet<C, HashF, AltHashF, Allocator, HashsetEntry<C, HashF> >
{
public:
    typedef HashSetUncached<C, HashF, AltHashF, Allocator>                  SelfType;
    typedef HashSet<C, HashF, AltHashF, Allocator, HashsetEntry<C, HashF> > BaseType;

    HashSetUncached() {}
    HashSetUncached(int sizeHint) : BaseType(sizeHint) {}
    HashSetUncached(const SelfType& o) : BaseType(o) {}
    ~HashSetUncached() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem>
class HashSetUncachedLH : public HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, HashsetEntry<C, HashF> >
{
public:
    typedef HashSetUncachedLH<C, HashF, AltHashF, SID>                                SelfType;
    typedef HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, HashsetEntry<C, HashF> > BaseType;

    HashSetUncachedLH() {}
    HashSetUncachedLH(int sizeHint) : BaseType(sizeHint) {}
    HashSetUncachedLH(const SelfType& o) : BaseType(o) {}
    ~HashSetUncachedLH() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

// ---------------------------------------------------------------- key/value maps
//
// A Hash<K, V> is a HashSet of nodes. Lookups by key go through NodeAltHashF (hash of the bare key); inserts pass a
// NodeRef (pointers to key and value) so nothing is copied until the slot is known.

template<class C, class U, class HashF>
struct HashNode
{
    typedef HashNode<C, U, HashF> SelfType;
    typedef C                     FirstType;
    typedef U                     SecondType;

    C First;
    U Second;

    struct NodeRef
    {
        const C* pFirst;
        const U* pSecond;

        NodeRef(const C& f, const U& s) : pFirst(&f), pSecond(&s) {}
        NodeRef(const NodeRef& src) : pFirst(src.pFirst), pSecond(src.pSecond) {}

        UPInt GetHash() const { return HashF()(*pFirst); }
        operator const C&() const { return *pFirst; }
    };

    HashNode(const HashNode& src) : First(src.First), Second(src.Second) {}
    HashNode(const NodeRef& src) : First(*src.pFirst), Second(*src.pSecond) {}
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

// Slot of a node set: the node is built from whatever key form (node or NodeRef) the set was given.
template<class C, class HashF>
class HashsetCachedNodeEntry
{
public:
    SPInt NextInChain;
    UPInt HashValue;
    C     Value;

    HashsetCachedNodeEntry() : NextInChain(-2) {}
    HashsetCachedNodeEntry(const HashsetCachedNodeEntry& o) : NextInChain(o.NextInChain), HashValue(o.HashValue), Value(o.Value) {}
    template<class K>
    HashsetCachedNodeEntry(const K& key, SPInt next) : NextInChain(next), Value(key) {}

    bool IsEmpty() const      { return NextInChain == -2; }
    bool IsEndOfChain() const { return NextInChain == -1; }

    UPInt GetCachedHash(UPInt) const { return HashValue; }
    void  SetCachedHash(UPInt h)     { HashValue = h; }

    void Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, class Allocator = AllocatorGH<C>,
         class HashNodeT = HashNode<C, U, HashF>,
         class Entry     = HashsetCachedNodeEntry<HashNodeT, typename HashNodeT::NodeHashF>,
         class Container = HashSet<HashNodeT, typename HashNodeT::NodeHashF, typename HashNodeT::NodeAltHashF,
                                   Allocator, Entry> >
class Hash
{
public:
    SF_MEMORY_REDEFINE_NEW(Hash, Allocator::StatId)

    typedef C                                                         KeyType;
    typedef U                                                         ValueType;
    typedef Hash<C, U, HashF, Allocator, HashNodeT, Entry, Container> SelfType;
    typedef typename HashNodeT::NodeRef                               NodeRef;

    Container mHash;

    Hash() {}
    Hash(int sizeHint) : mHash(sizeHint) {}
    explicit Hash(void* pheap) : mHash(pheap) {}
    Hash(void* pheap, int sizeHint) : mHash(pheap, sizeHint) {}
    Hash(const SelfType& src) : mHash(src.mHash) {}
    ~Hash() {}

    void operator=(const SelfType& src) { mHash = src.mHash; }

    void Set(const C& key, const U& value)
    {
        NodeRef e(key, value);
        mHash.Set(e);
    }
    void Add(const C& key, const U& value)
    {
        NodeRef e(key, value);
        mHash.Add(e);
    }

    void Remove(const C& key) { mHash.RemoveAlt(key); }
    template<class K>
    void RemoveAlt(const K& key) { mHash.RemoveAlt(key); }

    bool Get(const C& key, U* pvalue) const
    {
        const HashNodeT* p = mHash.GetAlt(key);
        if (p == 0)
            return false;
        if (pvalue)
            *pvalue = p->Second;
        return true;
    }
    template<class K>
    bool GetAlt(const K& key, U* pvalue) const
    {
        const HashNodeT* p = mHash.GetAlt(key);
        if (p == 0)
            return false;
        if (pvalue)
            *pvalue = p->Second;
        return true;
    }

    U* Get(const C& key)
    {
        HashNodeT* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    const U* Get(const C& key) const
    {
        const HashNodeT* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    template<class K>
    U* GetAlt(const K& key)
    {
        HashNodeT* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    template<class K>
    const U* GetAlt(const K& key) const
    {
        const HashNodeT* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }

    UPInt GetSize() const { return mHash.GetSize(); }
    bool  IsEmpty() const { return mHash.IsEmpty(); }
    void  Clear()         { mHash.Clear(); }
    void  Resize(UPInt n) { mHash.Resize(n); }
    void  SetCapacity(UPInt n) { mHash.SetCapacity(n); }

    typedef typename Container::ConstIterator ConstIterator;
    typedef typename Container::Iterator      Iterator;

    Iterator      Begin()       { return mHash.Begin(); }
    Iterator      End()         { return mHash.End(); }
    ConstIterator Begin() const { return mHash.Begin(); }
    ConstIterator End() const   { return mHash.End(); }

    Iterator Find(const C& key) { return mHash.FindAlt(key); }
    ConstIterator Find(const C& key) const { return mHash.FindAlt(key); }
    template<class K>
    Iterator FindAlt(const K& key) { return mHash.FindAlt(key); }
};

// Node slot that keeps no hash: it is recomputed from the node's key whenever the table needs it.
template<class C, class HashF>
class HashsetNodeEntry
{
public:
    SPInt NextInChain;
    C     Value;

    HashsetNodeEntry() : NextInChain(-2) {}
    HashsetNodeEntry(const HashsetNodeEntry& o) : NextInChain(o.NextInChain), Value(o.Value) {}
    template<class K>
    HashsetNodeEntry(const K& key, SPInt next) : NextInChain(next), Value(key) {}

    bool IsEmpty() const      { return NextInChain == -2; }
    bool IsEndOfChain() const { return NextInChain == -1; }

    UPInt GetCachedHash(UPInt mask) const { return HashF()(Value) & mask; }
    void  SetCachedHash(UPInt)            {}

    void Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

// Map whose table lives in the heap of its owner.
template<class C, class U, class HashF = FixedSizeHash<C>, int SID = Stat_Default_Mem,
         class HashNodeT = HashNode<C, U, HashF>,
         class Entry     = HashsetCachedNodeEntry<HashNodeT, typename HashNodeT::NodeHashF> >
class HashLH : public Hash<C, U, HashF, AllocatorLH<C, SID>, HashNodeT, Entry>
{
public:
    typedef HashLH<C, U, HashF, SID, HashNodeT, Entry>               SelfType;
    typedef Hash<C, U, HashF, AllocatorLH<C, SID>, HashNodeT, Entry> BaseType;

    HashLH() {}
    HashLH(int sizeHint) : BaseType(sizeHint) {}
    HashLH(const SelfType& o) : BaseType(o) {}
    ~HashLH() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

// Map without cached hashes.
template<class C, class U, class HashF = FixedSizeHash<C>, class Allocator = AllocatorGH<C> >
class HashUncached
    : public Hash<C, U, HashF, Allocator, HashNode<C, U, HashF>,
                  HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
{
public:
    typedef HashUncached<C, U, HashF, Allocator> SelfType;
    typedef Hash<C, U, HashF, Allocator, HashNode<C, U, HashF>,
                 HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
        BaseType;

    HashUncached() {}
    HashUncached(int sizeHint) : BaseType(sizeHint) {}
    HashUncached(const SelfType& o) : BaseType(o) {}
    ~HashUncached() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

// Map without cached hashes whose table lives in the heap of its owner.
template<class C, class U, class HashF = FixedSizeHash<C>, int SID = Stat_Default_Mem>
class HashUncachedLH
    : public HashLH<C, U, HashF, SID, HashNode<C, U, HashF>,
                    HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
{
public:
    typedef HashUncachedLH<C, U, HashF, SID> SelfType;
    typedef HashLH<C, U, HashF, SID, HashNode<C, U, HashF>,
                   HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
        BaseType;

    HashUncachedLH() {}
    HashUncachedLH(int sizeHint) : BaseType(sizeHint) {}
    HashUncachedLH(const SelfType& o) : BaseType(o) {}
    ~HashUncachedLH() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

// (appended for the AS3 sparse arrays) Set and map whose table lives in a given heap, kept next to the table pointer.
template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSetDH : public HashSetBase<C, HashF, AltHashF, AllocatorDH<C, SID>, Entry>
{
    void* pHeap;

public:
    typedef HashSetDH<C, HashF, AltHashF, SID, Entry>                   SelfType;
    typedef HashSetBase<C, HashF, AltHashF, AllocatorDH<C, SID>, Entry> BaseType;

    explicit HashSetDH(void* pheap) : pHeap(pheap) {}
    HashSetDH(void* pheap, int sizeHint) : BaseType(pheap, sizeHint), pHeap(pheap) {}
    HashSetDH(const SelfType& o) : BaseType(o), pHeap(o.pHeap) {}
    ~HashSetDH() {}

    void operator=(const SelfType& o)
    {
        BaseType::Assign(o.pHeap, o);
        pHeap = o.pHeap;
    }

    template<class CRef>
    void Set(const CRef& key) { BaseType::Set(pHeap, key); }
    template<class CRef>
    inline void Add(const CRef& key) { BaseType::Add(pHeap, key); }

    void CheckExpand()          { BaseType::CheckExpand(this); }
    void Resize(UPInt n)        { BaseType::SetCapacity(pHeap, n); }
    void SetCapacity(UPInt n)   { BaseType::SetCapacity(pHeap, n); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, int SID = Stat_Default_Mem,
         class HashNodeT = HashNode<C, U, HashF>,
         class Entry     = HashsetCachedNodeEntry<HashNodeT, typename HashNodeT::NodeHashF> >
class HashDH
    : public Hash<C, U, HashF, AllocatorDH<C, SID>, HashNodeT, Entry,
                  HashSetDH<HashNodeT, typename HashNodeT::NodeHashF, typename HashNodeT::NodeAltHashF, SID, Entry> >
{
public:
    typedef HashDH<C, U, HashF, SID, HashNodeT, Entry> SelfType;
    typedef Hash<C, U, HashF, AllocatorDH<C, SID>, HashNodeT, Entry,
                 HashSetDH<HashNodeT, typename HashNodeT::NodeHashF, typename HashNodeT::NodeAltHashF, SID, Entry> >
        BaseType;

    explicit HashDH(void* pheap) : BaseType(pheap) {}
    HashDH(void* pheap, int sizeHint) : BaseType(pheap, sizeHint) {}
    HashDH(const SelfType& o) : BaseType(o) {}
    ~HashDH() {}

    void operator=(const SelfType& o) { BaseType::operator=(o); }
};

} // namespace Scaleform

#endif
