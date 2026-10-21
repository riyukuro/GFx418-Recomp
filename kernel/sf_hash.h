// Recovered Scaleform GFx 4.1.18: open hash sets/maps. One allocation holds {EntryCount, SizeMask} followed by
// SizeMask+1 entries; collisions are chained through NextInChain (-2 empty, -1 end of chain) inside the table, an
// entry always sits at its natural slot or in the chain starting there, and the table doubles at 80% load.
#ifndef MS2_SF_KERNEL_HASH_H
#define MS2_SF_KERNEL_HASH_H

#include "ms2/scaleform/kernel/sf_allocator.h"
#include "ms2/scaleform/kernel/sf_alg.h"

namespace Scaleform {

template<class C>
class IdentityHash
{
public:
    UPInt operator()(const C& data) const { return (UPInt)data; }
};

// SDBM hash over the bytes of a value, walked back to front
template<class C>
class FixedSizeHash
{
public:
    static SF_INLINE UPInt SDBM_Hash(const void* dataIn, UPInt size, UPInt seed = 5381)
    {
        const UByte* data = (const UByte*)dataIn;
        UPInt        h = seed;
        while (size > 0)
        {
            size--;
            h = (h << 16) + (h << 6) - h + (UPInt)data[size];
        }
        return h;
    }
    UPInt operator()(const C& data) const
    {
        unsigned char* p = (unsigned char*)&data;
        int size = sizeof(C);
        return SDBM_Hash(p, size);
    }
};

// ---- entries: plain (hash recomputed) or with the hash cached ----
template<class C, class HashF>
class HashsetEntry
{
public:
    SPInt NextInChain;
    C     Value;

    HashsetEntry() : NextInChain(-2) { }
    HashsetEntry(const HashsetEntry& e) : NextInChain(e.NextInChain), Value(e.Value) { }
    HashsetEntry(const C& key, SPInt next) : NextInChain(next), Value(key) { }

    bool  IsEmpty() const { return NextInChain == -2; }
    bool  IsEndOfChain() const { return NextInChain == -1; }
    UPInt GetCachedHash(UPInt maskValue) const { return HashF()(Value) & maskValue; }
    void  SetCachedHash(UPInt) { }
    void  Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

template<class C, class HashF>
class HashsetCachedEntry
{
public:
    SPInt NextInChain;
    UPInt HashValue;
    C     Value;

    HashsetCachedEntry() : NextInChain(-2) { }
    HashsetCachedEntry(const HashsetCachedEntry& e) : NextInChain(e.NextInChain), HashValue(e.HashValue), Value(e.Value) { }
    HashsetCachedEntry(const C& key, SPInt next) : NextInChain(next), Value(key) { }

    bool  IsEmpty() const { return NextInChain == -2; }
    bool  IsEndOfChain() const { return NextInChain == -1; }
    UPInt GetCachedHash(UPInt maskValue) const { SF_UNUSED(maskValue); return HashValue; }
    void  SetCachedHash(UPInt hashValue) { HashValue = hashValue; }
    void  Clear()
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

    HashSetBase() : pTable(NULL) { }
    HashSetBase(int sizeHint) : pTable(NULL) { SetCapacity(this, sizeHint); }
    explicit HashSetBase(void* memAddr) : pTable(NULL) { SF_UNUSED(memAddr); }
    HashSetBase(void* memAddr, int sizeHint) : pTable(NULL) { SetCapacity(memAddr, sizeHint); }
    HashSetBase(const SelfType& src) : pTable(NULL) { Assign(this, src); }
    ~HashSetBase()
    {
        if (pTable)
        {
            for (UPInt i = 0, n = pTable->SizeMask; i <= n; i++)
            {
                Entry* e = &E(i);
                if (!e->IsEmpty())
                    e->Free();
            }
            Allocator::Free(pTable);
            pTable = NULL;
        }
    }

    void Assign(void* memAddr, const SelfType& src)
    {
        Clear();
        if (src.IsEmpty() == false)
        {
            SetCapacity(memAddr, src.GetSize());
            for (ConstIterator it = src.Begin(); it != src.End(); ++it)
                Add(memAddr, *it);
        }
    }

    void Clear()
    {
        if (pTable)
        {
            for (UPInt i = 0, n = pTable->SizeMask; i <= n; i++)
            {
                Entry* e = &E(i);
                if (!e->IsEmpty())
                    e->Clear();
            }
            Allocator::Free(pTable);
            pTable = NULL;
        }
    }

    bool IsEmpty() const { return pTable == NULL || pTable->EntryCount == 0; }

    // insert or overwrite
    template<class CRef>
    void Set(void* memAddr, const CRef& key)
    {
        UPInt hashValue = HashF()(key);
        SPInt index = (SPInt)-1;
        if (pTable != NULL)
            index = findIndexCore(key, hashValue & pTable->SizeMask);
        if (index >= 0)
            E(index).Value = key;
        else
            add(memAddr, key, hashValue);
    }

    // insert without looking for an existing equal key
    template<class CRef>
    inline void Add(void* memAddr, const CRef& key)
    {
        UPInt hashValue = HashF()(key);
        add(memAddr, key, hashValue);
    }

    template<class K>
    void RemoveAlt(const K& key)
    {
        if (pTable == NULL)
            return;
        UPInt  hashValue = AltHashF()(key);
        SPInt  index = hashValue & pTable->SizeMask;
        Entry* e = &E(index);

        // the natural slot is empty or owned by another chain: not present
        if (e->IsEmpty() || (e->GetCachedHash(pTable->SizeMask) != (UPInt)index))
            return;

        SPInt naturalIndex = index;
        SPInt prevIndex = -1;
        while ((e->GetCachedHash(pTable->SizeMask) != (UPInt)naturalIndex) || !(e->Value == key))
        {
            prevIndex = index;
            index = e->NextInChain;
            if (index == -1)
                return;
            e = &E(index);
        }

        if (naturalIndex == index)
        {
            // removing the chain head: pull the next entry into the natural slot
            if (!e->IsEndOfChain())
            {
                Entry* enext = &E(e->NextInChain);
                e->Clear();
                new (e) Entry(*enext);
                e = enext;
            }
        }
        else
        {
            E(prevIndex).NextInChain = e->NextInChain;
        }
        e->Clear();
        pTable->EntryCount--;
    }

    template<class CRef>
    void Remove(const CRef& key) { RemoveAlt(key); }

    template<class K>
    C* Get(const K& key)
    {
        SPInt index = findIndex(key);
        if (index >= 0)
            return &E(index).Value;
        return 0;
    }
    template<class K>
    const C* Get(const K& key) const
    {
        SPInt index = findIndex(key);
        if (index >= 0)
            return &E(index).Value;
        return 0;
    }
    template<class K>
    const C* GetAlt(const K& key) const
    {
        SPInt index = findIndexAlt(key);
        if (index >= 0)
            return &E(index).Value;
        return 0;
    }
    template<class K>
    C* GetAlt(const K& key)
    {
        SPInt index = findIndexAlt(key);
        if (index >= 0)
            return &E(index).Value;
        return 0;
    }
    template<class K>
    bool GetAlt(const K& key, C* val) const
    {
        SPInt index = findIndexAlt(key);
        if (index >= 0)
        {
            if (val)
                *val = E(index).Value;
            return true;
        }
        return false;
    }

    UPInt GetSize() const { return pTable == NULL ? 0 : (UPInt)pTable->EntryCount; }

    void CheckExpand(void* memAddr)
    {
        if (pTable == NULL)
            setRawCapacity(memAddr, HashMinSize);
        else if (pTable->EntryCount * 5 > (pTable->SizeMask + 1) * 4)
            setRawCapacity(memAddr, (pTable->SizeMask + 1) * 2);
    }

    void Resize(void* memAddr, UPInt n) { SetCapacity(memAddr, n); }

    void SetCapacity(void* memAddr, UPInt newSize)
    {
        UPInt newRawSize = (newSize * 5) / 4;
        if (newRawSize <= GetSize())
            return;
        setRawCapacity(memAddr, newRawSize);
    }

    struct ConstIterator
    {
        const C& operator*() const { return pHash->E(Index).Value; }
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
        bool operator==(const ConstIterator& it) const
        {
            if (IsEnd() && it.IsEnd())
                return true;
            else
                return (pHash == it.pHash) && (Index == it.Index);
        }
        bool operator!=(const ConstIterator& it) const { return !(*this == it); }
        bool IsEnd() const
        {
            return (pHash == NULL) || (pHash->pTable == NULL) || (Index > (SPInt)pHash->pTable->SizeMask);
        }
        ConstIterator() : pHash(NULL), Index(0) { }

    public:
        ConstIterator(const SelfType* h, SPInt index) : pHash(h), Index(index) { }
        const SelfType* GetContainer() const { return pHash; }
        SPInt GetIndex() const { return Index; }

    protected:
        friend class HashSetBase<C, HashF, AltHashF, Allocator, Entry>;
        const SelfType* pHash;
        SPInt           Index;
    };
    friend struct ConstIterator;

    struct Iterator : public ConstIterator
    {
        C& operator*() const { return const_cast<SelfType*>(ConstIterator::pHash)->E(ConstIterator::Index).Value; }
        C* operator->() const { return &(operator*()); }
        Iterator() : ConstIterator(NULL, 0) { }

        // remove the current entry; the iterator stays valid for ++
        void Remove() { RemoveAlt(operator*()); }
        template<class K>
        void RemoveAlt(const K& key)
        {
            SelfType* hash = const_cast<SelfType*>(ConstIterator::pHash);
            UPInt     hashValue = AltHashF()(key);
            SPInt     index = hashValue & hash->pTable->SizeMask;
            Entry*    e = &hash->E(index);

            if (e->IsEmpty() || (e->GetCachedHash(hash->pTable->SizeMask) != (UPInt)index))
                return;

            SPInt naturalIndex = index;
            SPInt prevIndex = -1;
            while ((e->GetCachedHash(hash->pTable->SizeMask) != (UPInt)naturalIndex) || !(e->Value == key))
            {
                prevIndex = index;
                index = e->NextInChain;
                if (index == -1)
                    return;
                e = &hash->E(index);
            }

            if (index == (SPInt)ConstIterator::Index)
            {
                if (naturalIndex == index)
                {
                    if (!e->IsEndOfChain())
                    {
                        Entry* enext = &hash->E(e->NextInChain);
                        e->Clear();
                        new (e) Entry(*enext);
                        e = enext;
                        --ConstIterator::Index;
                    }
                }
                else
                {
                    hash->E(prevIndex).NextInChain = e->NextInChain;
                }
                e->Clear();
                hash->pTable->EntryCount--;
            }
        }

    public:
        Iterator(const SelfType* h, SPInt index) : ConstIterator(h, index) { }
    };
    friend struct Iterator;

    Iterator Begin()
    {
        if (pTable == 0)
            return Iterator(NULL, 0);
        UPInt i0 = 0;
        while (i0 <= pTable->SizeMask && E(i0).IsEmpty())
            i0++;
        return Iterator(this, i0);
    }
    Iterator      End() { return Iterator(NULL, 0); }
    ConstIterator Begin() const { return const_cast<SelfType*>(this)->Begin(); }
    ConstIterator End() const { return const_cast<SelfType*>(this)->End(); }

    template<class K>
    Iterator Find(const K& key)
    {
        SPInt index = findIndex(key);
        if (index >= 0)
            return Iterator(this, index);
        return Iterator(NULL, 0);
    }
    template<class K>
    Iterator FindAlt(const K& key)
    {
        SPInt index = findIndexAlt(key);
        if (index >= 0)
            return Iterator(this, index);
        return Iterator(NULL, 0);
    }
    template<class K>
    ConstIterator Find(const K& key) const { return const_cast<SelfType*>(this)->Find(key); }
    template<class K>
    ConstIterator FindAlt(const K& key) const { return const_cast<SelfType*>(this)->FindAlt(key); }

private:
    template<class K>
    SPInt findIndex(const K& key) const
    {
        if (pTable == NULL)
            return -1;
        UPInt hashValue = HashF()(key) & pTable->SizeMask;
        return findIndexCore(key, hashValue);
    }
    template<class K>
    SPInt findIndexAlt(const K& key) const
    {
        if (pTable == NULL)
            return -1;
        UPInt hashValue = AltHashF()(key) & pTable->SizeMask;
        return findIndexCore(key, hashValue);
    }
    template<class K>
    SPInt findIndexCore(const K& key, UPInt hashValue) const
    {
        UPInt        index = hashValue;
        const Entry* e = &E(index);
        if (e->IsEmpty() || (e->GetCachedHash(pTable->SizeMask) != index))
            return -1;
        while (1)
        {
            if (e->GetCachedHash(pTable->SizeMask) == hashValue && e->Value == key)
                return index;
            index = e->NextInChain;
            if (index == (UPInt)-1)
                break;
            e = &E(index);
        }
        return -1;
    }

    template<class CRef>
    void add(void* memAddr, const CRef& key, UPInt hashValue)
    {
        CheckExpand(memAddr);
        hashValue &= pTable->SizeMask;
        pTable->EntryCount++;

        SPInt  index = hashValue;
        Entry* naturalEntry = &(E(index));
        if (naturalEntry->IsEmpty())
        {
            new (naturalEntry) Entry(key, -1);
        }
        else
        {
            // linear probe for a free slot
            SPInt blankIndex = index;
            do {
                blankIndex = (blankIndex + 1) & pTable->SizeMask;
            } while (!E(blankIndex).IsEmpty());
            Entry* blankEntry = &E(blankIndex);

            if (naturalEntry->GetCachedHash(pTable->SizeMask) == (UPInt)index)
            {
                // same chain: the old head moves to the blank slot, the new key becomes the head
                new (blankEntry) Entry(*naturalEntry);
                naturalEntry->Value = key;
                naturalEntry->NextInChain = blankIndex;
            }
            else
            {
                // the slot holds a guest of another chain: move it out, relink its predecessor
                SPInt collidedIndex = naturalEntry->GetCachedHash(pTable->SizeMask);
                for (;;)
                {
                    Entry* e = &E(collidedIndex);
                    if (e->NextInChain == index)
                    {
                        new (blankEntry) Entry(*naturalEntry);
                        e->NextInChain = blankIndex;
                        break;
                    }
                    collidedIndex = e->NextInChain;
                }
                naturalEntry->Value = key;
                naturalEntry->NextInChain = -1;
            }
        }
        naturalEntry->SetCachedHash(hashValue);
    }

    Entry& E(UPInt index) { return *(((Entry*)(pTable + 1)) + index); }
    const Entry& E(UPInt index) const { return *(((Entry*)(pTable + 1)) + index); }

    // rehash into a power-of-two table of at least newSize entries
    void setRawCapacity(void* heapAddr, UPInt newSize)
    {
        if (newSize == 0)
        {
            Clear();
            return;
        }
        if (newSize < HashMinSize)
            newSize = HashMinSize;
        else
        {
            int bits = Alg::UpperBit(newSize - 1) + 1;
            newSize = UPInt(1) << bits;
        }

        SelfType newHash;
        newHash.pTable = (TableType*)Allocator::Alloc(heapAddr, sizeof(TableType) + sizeof(Entry) * newSize, __FILE__,
                                                     __LINE__);
        newHash.pTable->EntryCount = 0;
        newHash.pTable->SizeMask = newSize - 1;
        UPInt i, n;
        for (i = 0; i < newSize; i++)
            newHash.E(i).NextInChain = -2;

        if (pTable)
        {
            for (i = 0, n = pTable->SizeMask; i <= n; i++)
            {
                Entry* e = &E(i);
                if (e->IsEmpty() == false)
                {
                    newHash.Add(heapAddr, e->Value);
                    e->Clear();
                }
            }
            Allocator::Free(pTable);
        }
        pTable = newHash.pTable;
        newHash.pTable = NULL;
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

    HashSet() { }
    HashSet(int sizeHint) : BaseType(sizeHint) { }
    explicit HashSet(void* heap) : BaseType(heap) { }
    HashSet(void* heap, int sizeHint) : BaseType(heap, sizeHint) { }
    HashSet(const SelfType& src) : BaseType(src) { }
    ~HashSet() { }

    void operator=(const SelfType& src) { BaseType::Assign(this, src); }
    template<class CRef> void Set(const CRef& key) { BaseType::Set(this, key); }
    template<class CRef> inline void Add(const CRef& key) { BaseType::Add(this, key); }
    void CheckExpand() { BaseType::CheckExpand(this); }
    void Resize(UPInt n) { BaseType::SetCapacity(this, n); }
    void SetCapacity(UPInt newSize) { BaseType::SetCapacity(this, newSize); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSetLH : public HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, Entry>
{
public:
    typedef HashSetLH<C, HashF, AltHashF, SID, Entry>                SelfType;
    typedef HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, Entry>  BaseType;

    HashSetLH() { }
    HashSetLH(int sizeHint) : BaseType(sizeHint) { }
    HashSetLH(const SelfType& src) : BaseType(src) { }
    ~HashSetLH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem,
         class Entry = HashsetCachedEntry<C, HashF> >
class HashSetDH : public HashSetBase<C, HashF, AltHashF, AllocatorDH<C, SID>, Entry>
{
    void* pHeap;
public:
    typedef HashSetDH<C, HashF, AltHashF, SID, Entry>                    SelfType;
    typedef HashSetBase<C, HashF, AltHashF, AllocatorDH<C, SID>, Entry>  BaseType;

    explicit HashSetDH(void* heap) : pHeap(heap) { }
    HashSetDH(void* heap, int sizeHint) : BaseType(heap, sizeHint), pHeap(heap) { }
    HashSetDH(const SelfType& src) : BaseType(src), pHeap(src.pHeap) { }
    ~HashSetDH() { }

    void operator=(const SelfType& src)
    {
        BaseType::Assign(src.pHeap, src);
        pHeap = src.pHeap;
    }
    template<class CRef> void Set(const CRef& key) { BaseType::Set(pHeap, key); }
    template<class CRef> inline void Add(const CRef& key) { BaseType::Add(pHeap, key); }
    void CheckExpand() { BaseType::CheckExpand(this); }
    void Resize(UPInt n) { BaseType::SetCapacity(pHeap, n); }
    void SetCapacity(UPInt newSize) { BaseType::SetCapacity(pHeap, newSize); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, class Allocator = AllocatorGH<C> >
class HashSetUncached : public HashSet<C, HashF, AltHashF, Allocator, HashsetEntry<C, HashF> >
{
public:
    typedef HashSetUncached<C, HashF, AltHashF, Allocator>                  SelfType;
    typedef HashSet<C, HashF, AltHashF, Allocator, HashsetEntry<C, HashF> > BaseType;

    HashSetUncached() { }
    HashSetUncached(int sizeHint) : BaseType(sizeHint) { }
    HashSetUncached(const SelfType& src) : BaseType(src) { }
    ~HashSetUncached() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem>
class HashSetUncachedLH : public HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, HashsetEntry<C, HashF> >
{
public:
    typedef HashSetUncachedLH<C, HashF, AltHashF, SID>                                SelfType;
    typedef HashSet<C, HashF, AltHashF, AllocatorLH<C, SID>, HashsetEntry<C, HashF> > BaseType;

    HashSetUncachedLH() { }
    HashSetUncachedLH(int sizeHint) : BaseType(sizeHint) { }
    HashSetUncachedLH(const SelfType& src) : BaseType(src) { }
    ~HashSetUncachedLH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class HashF = FixedSizeHash<C>, class AltHashF = HashF, int SID = Stat_Default_Mem>
class HashSetUncachedDH : public HashSetDH<C, HashF, AltHashF, SID, HashsetEntry<C, HashF> >
{
public:
    typedef HashSetUncachedDH<C, HashF, AltHashF, SID>                  SelfType;
    typedef HashSetDH<C, HashF, AltHashF, SID, HashsetEntry<C, HashF> > BaseType;

    explicit HashSetUncachedDH(void* heap) : BaseType(heap) { }
    HashSetUncachedDH(void* heap, int sizeHint) : BaseType(heap, sizeHint) { }
    HashSetUncachedDH(const SelfType& src) : BaseType(src) { }
    ~HashSetUncachedDH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

// ---- maps: a hash set of {First, Second} nodes keyed on First ----
template<class C, class U, class HashF>
struct HashNode
{
    typedef HashNode<C, U, HashF> SelfType;
    typedef C                     FirstType;
    typedef U                     SecondType;

    C First;
    U Second;

    // a key/value pair by reference, so Set/Add need no temporary node
    struct NodeRef
    {
        const C* pFirst;
        const U* pSecond;
        NodeRef(const C& f, const U& s) : pFirst(&f), pSecond(&s) { }
        NodeRef(const NodeRef& src) : pFirst(src.pFirst), pSecond(src.pSecond) { }
        inline UPInt GetHash() const { return HashF()(*pFirst); }
        operator const C&() const { return *pFirst; }
    };

    HashNode(const HashNode& src) : First(src.First), Second(src.Second) { }
    HashNode(const NodeRef& src) : First(*src.pFirst), Second(*src.pSecond) { }
    void operator=(const NodeRef& src)
    {
        First = *src.pFirst;
        Second = *src.pSecond;
    }

    template<class K> bool operator==(const K& src) const { return (First == src); }
    template<class K> static UPInt CalcHash(const K& data) { return HashF()(data); }
    inline UPInt GetHash() const { return HashF()(First); }

    struct NodeHashF
    {
        template<class K> UPInt operator()(const K& data) const { return data.GetHash(); }
    };
    struct NodeAltHashF
    {
        template<class K> UPInt operator()(const K& data) const { return HashNode<C, U, HashF>::CalcHash(data); }
    };
};

template<class C, class HashF>
class HashsetNodeEntry
{
public:
    SPInt NextInChain;
    C     Value;

    HashsetNodeEntry() : NextInChain(-2) { }
    HashsetNodeEntry(const HashsetNodeEntry& e) : NextInChain(e.NextInChain), Value(e.Value) { }
    HashsetNodeEntry(const C& key, SPInt next) : NextInChain(next), Value(key) { }
    HashsetNodeEntry(const typename C::NodeRef& keyRef, SPInt next) : NextInChain(next), Value(keyRef) { }

    bool  IsEmpty() const { return NextInChain == -2; }
    bool  IsEndOfChain() const { return NextInChain == -1; }
    UPInt GetCachedHash(UPInt maskValue) const { return HashF()(Value) & maskValue; }
    void  SetCachedHash(UPInt hashValue) { SF_UNUSED(hashValue); }
    void  Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

template<class C, class HashF>
class HashsetCachedNodeEntry
{
public:
    SPInt NextInChain;
    UPInt HashValue;
    C     Value;

    HashsetCachedNodeEntry() : NextInChain(-2) { }
    HashsetCachedNodeEntry(const HashsetCachedNodeEntry& e)
        : NextInChain(e.NextInChain), HashValue(e.HashValue), Value(e.Value) { }
    HashsetCachedNodeEntry(const C& key, SPInt next) : NextInChain(next), Value(key) { }
    HashsetCachedNodeEntry(const typename C::NodeRef& keyRef, SPInt next) : NextInChain(next), Value(keyRef) { }

    bool  IsEmpty() const { return NextInChain == -2; }
    bool  IsEndOfChain() const { return NextInChain == -1; }
    UPInt GetCachedHash(UPInt maskValue) const { SF_UNUSED(maskValue); return HashValue; }
    void  SetCachedHash(UPInt hashValue) { HashValue = hashValue; }
    void  Clear()
    {
        Value.~C();
        NextInChain = -2;
    }
    void Free() { Clear(); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, class Allocator = AllocatorGH<C>,
         class HashNode = Scaleform::HashNode<C, U, HashF>,
         class Entry = HashsetCachedNodeEntry<HashNode, typename HashNode::NodeHashF>,
         class Container = HashSet<HashNode, typename HashNode::NodeHashF, typename HashNode::NodeAltHashF, Allocator,
                                   Entry> >
class Hash
{
public:
    SF_MEMORY_REDEFINE_NEW(Hash, Allocator::StatId)

    typedef U                                                        ValueType;
    typedef Hash<C, U, HashF, Allocator, HashNode, Entry, Container> SelfType;

    Container mHash;

public:
    Hash() { }
    Hash(int sizeHint) : mHash(sizeHint) { }
    explicit Hash(void* heap) : mHash(heap) { }
    Hash(void* heap, int sizeHint) : mHash(heap, sizeHint) { }
    Hash(const SelfType& src) : mHash(src.mHash) { }
    ~Hash() { }

    void operator=(const SelfType& src) { mHash = src.mHash; }

    inline void Clear() { mHash.Clear(); }
    inline bool IsEmpty() const { return mHash.IsEmpty(); }

    inline void Set(const C& key, const U& value)
    {
        typename HashNode::NodeRef e(key, value);
        mHash.Set(e);
    }
    inline void Add(const C& key, const U& value)
    {
        typename HashNode::NodeRef e(key, value);
        mHash.Add(e);
    }
    inline void Remove(const C& key) { mHash.RemoveAlt(key); }
    template<class K> inline void RemoveAlt(const K& key) { mHash.RemoveAlt(key); }

    bool Get(const C& key, U* value) const
    {
        const HashNode* p = mHash.GetAlt(key);
        if (p)
        {
            if (value)
                *value = p->Second;
            return true;
        }
        return false;
    }
    template<class K>
    bool GetAlt(const K& key, U* value) const
    {
        const HashNode* p = mHash.GetAlt(key);
        if (p)
        {
            if (value)
                *value = p->Second;
            return true;
        }
        return false;
    }
    inline U* Get(const C& key)
    {
        HashNode* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    inline const U* Get(const C& key) const
    {
        const HashNode* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    template<class K>
    inline U* GetAlt(const K& key)
    {
        HashNode* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }
    template<class K>
    inline const U* GetAlt(const K& key) const
    {
        const HashNode* p = mHash.GetAlt(key);
        return p ? &p->Second : 0;
    }

    inline UPInt GetSize() const { return mHash.GetSize(); }
    inline void  Resize(UPInt n) { mHash.Resize(n); }
    inline void  SetCapacity(UPInt newSize) { mHash.SetCapacity(newSize); }

    typedef typename Container::ConstIterator ConstIterator;
    typedef typename Container::Iterator      Iterator;

    inline Iterator      Begin() { return mHash.Begin(); }
    inline Iterator      End() { return mHash.End(); }
    inline ConstIterator Begin() const { return mHash.Begin(); }
    inline ConstIterator End() const { return mHash.End(); }

    Iterator      Find(const C& key) { return mHash.FindAlt(key); }
    ConstIterator Find(const C& key) const { return mHash.FindAlt(key); }
    template<class K> Iterator      FindAlt(const K& key) { return mHash.FindAlt(key); }
    template<class K> ConstIterator FindAlt(const K& key) const { return mHash.FindAlt(key); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, int SID = Stat_Default_Mem,
         class HashNode = Scaleform::HashNode<C, U, HashF>,
         class Entry = HashsetCachedNodeEntry<HashNode, typename HashNode::NodeHashF> >
class HashLH : public Hash<C, U, HashF, AllocatorLH<C, SID>, HashNode, Entry>
{
public:
    typedef HashLH<C, U, HashF, SID, HashNode, Entry>               SelfType;
    typedef Hash<C, U, HashF, AllocatorLH<C, SID>, HashNode, Entry> BaseType;

    HashLH() { }
    HashLH(int sizeHint) : BaseType(sizeHint) { }
    HashLH(const SelfType& src) : BaseType(src) { }
    ~HashLH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, int SID = Stat_Default_Mem,
         class HashNode = Scaleform::HashNode<C, U, HashF>,
         class Entry = HashsetCachedNodeEntry<HashNode, typename HashNode::NodeHashF> >
class HashDH : public Hash<C, U, HashF, AllocatorDH<C, SID>, HashNode, Entry,
                           HashSetDH<HashNode, typename HashNode::NodeHashF, typename HashNode::NodeAltHashF, SID, Entry> >
{
public:
    typedef HashDH<C, U, HashF, SID, HashNode, Entry> SelfType;
    typedef Hash<C, U, HashF, AllocatorDH<C, SID>, HashNode, Entry,
                 HashSetDH<HashNode, typename HashNode::NodeHashF, typename HashNode::NodeAltHashF, SID, Entry> >
        BaseType;

    explicit HashDH(void* heap) : BaseType(heap) { }
    HashDH(void* heap, int sizeHint) : BaseType(heap, sizeHint) { }
    HashDH(const SelfType& src) : BaseType(src) { }
    ~HashDH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

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

    HashUncached() { }
    HashUncached(int sizeHint) : BaseType(sizeHint) { }
    HashUncached(const SelfType& src) : BaseType(src) { }
    ~HashUncached() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, int StatId = Stat_Default_Mem>
class HashUncachedLH
    : public HashLH<C, U, HashF, StatId, HashNode<C, U, HashF>,
                    HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
{
public:
    typedef HashUncachedLH<C, U, HashF, StatId> SelfType;
    typedef HashLH<C, U, HashF, StatId, HashNode<C, U, HashF>,
                   HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
        BaseType;

    HashUncachedLH() { }
    HashUncachedLH(int sizeHint) : BaseType(sizeHint) { }
    HashUncachedLH(const SelfType& src) : BaseType(src) { }
    ~HashUncachedLH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, class HashF = FixedSizeHash<C>, int StatId = Stat_Default_Mem>
class HashUncachedDH
    : public HashDH<C, U, HashF, StatId, HashNode<C, U, HashF>,
                    HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
{
public:
    typedef HashUncachedDH<C, U, HashF, StatId> SelfType;
    typedef HashDH<C, U, HashF, StatId, HashNode<C, U, HashF>,
                   HashsetNodeEntry<HashNode<C, U, HashF>, typename HashNode<C, U, HashF>::NodeHashF> >
        BaseType;

    explicit HashUncachedDH(void* heap) : BaseType(heap) { }
    HashUncachedDH(void* heap, int sizeHint) : BaseType(heap, sizeHint) { }
    HashUncachedDH(const SelfType& src) : BaseType(src) { }
    ~HashUncachedDH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, class Allocator = AllocatorGH<C>, class HashF = IdentityHash<C> >
class HashIdentity : public HashUncached<C, U, HashF, Allocator>
{
public:
    typedef HashIdentity<C, U, Allocator, HashF> SelfType;
    typedef HashUncached<C, U, HashF, Allocator> BaseType;

    HashIdentity() { }
    HashIdentity(int sizeHint) : BaseType(sizeHint) { }
    HashIdentity(const SelfType& src) : BaseType(src) { }
    ~HashIdentity() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, int SID = Stat_Default_Mem, class HashF = IdentityHash<C> >
class HashIdentityLH : public HashUncachedLH<C, U, HashF, SID>
{
public:
    typedef HashIdentityLH<C, U, SID, HashF> SelfType;
    typedef HashUncachedLH<C, U, HashF, SID> BaseType;

    HashIdentityLH() { }
    HashIdentityLH(int sizeHint) : BaseType(sizeHint) { }
    HashIdentityLH(const SelfType& src) : BaseType(src) { }
    ~HashIdentityLH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

template<class C, class U, int SID = Stat_Default_Mem, class HashF = IdentityHash<C> >
class HashIdentityDH : public HashUncachedDH<C, U, HashF, SID>
{
public:
    typedef HashIdentityDH<C, U, SID, HashF> SelfType;
    typedef HashUncachedDH<C, U, HashF, SID> BaseType;

    explicit HashIdentityDH(void* heap) : BaseType(heap) { }
    HashIdentityDH(void* heap, int sizeHint) : BaseType(heap, sizeHint) { }
    HashIdentityDH(const SelfType& src) : BaseType(src) { }
    ~HashIdentityDH() { }
    void operator=(const SelfType& src) { BaseType::operator=(src); }
};

}  // namespace Scaleform

#endif
