// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP server support (third part):
// the Array<Ptr>/Array<record> resizes, the Hash Set instances, the scope field setters and the hash set Grow
// (resize) instances of the AMP server state tables. Raw-layout free functions under the exe's own FUN_<va> names.
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142624020-0x142625920 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.
// MS2-FUNCTIONAL 0x142624840: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624af0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624d70: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624f80: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x1426251d0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x1426255e0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624190: same HashSetBase::Set (one FixedSizeHash, findIndexCore, assign or add); the exe keeps the self and value pointers in rbx/rdi and tail-jumps the found assign (12-14 bytes longer)
// MS2-FUNCTIONAL 0x142624300: same HashSetBase::Set (one FixedSizeHash, findIndexCore, assign or add); the exe keeps the self and value pointers in rbx/rdi and tail-jumps the found assign (12-14 bytes longer)

#define MS2_RAW_INLINE __forceinline
#include "sfr_gfx_07raw.h"
#include "../include/kernel/sf_hash.h"

#include <new>
#include <string.h>
#include <windows.h>

namespace Scaleform { namespace GFx {

namespace {
// Scoped lock on a raw CRITICAL_SECTION field (the exe's Lock::Locker keeps the pointer for the release).
struct RawLocker
{
    LPCRITICAL_SECTION pLock;
    explicit RawLocker(char* lock) : pLock((LPCRITICAL_SECTION)lock) { EnterCriticalSection(pLock); }
    ~RawLocker() { LeaveCriticalSection(pLock); }
};
}

char FUN_1422fe440(U);                            // index of the highest set bit
void FUN_142623b10(U*, void*, U);                 // Array<0x18-byte record>::Reserve
void FUN_142623ee0(U*, void*, U);                 // Array<Ptr>::Reserve
void FUN_14261ee70(U**, void*, NodeRef*, U);
void FUN_14261f070(U**, void*, KeyStringOps::Ref*, U);
void FUN_14261e7a0(U**, void*, const char*, U);
void FUN_14261e940(U**, void*, const char*, U);
U FUN_14261fc40(void*, const unsigned char*);
U FUN_14261fd80(void*, const unsigned char*);
void FUN_1426207e0(U*);
void FUN_142620840(U*);

// One 0x18-byte record whose first word is a counted pointer (ViewStats::CallInfo).
struct AmpPtrRecord
{
    void* pObject;
    U Pad[2];
    ~AmpPtrRecord() { if (pObject) FUN_14257dcb0(pObject); }
};

// A counted pointer element.
struct AmpPtrElem
{
    void* pObject;
    ~AmpPtrElem() { if (pObject) FUN_14257dcb0(pObject); }
};

// ArrayDataBase::ResizeNoConstruct over {Data, Size, Capacity}.
template<class T>
static __forceinline void RawResizeNoConstruct(U* array, void* pheapAddr, U newSize, void (*reserve)(U*, void*, U))
{
    U oldSize = array[1];

    if (newSize < oldSize)
    {
        T* p = (T*)array[0] + newSize;
        UPInt count = oldSize - newSize;
        p += count - 1;
        for (UPInt i = 0; i < count; ++i, --p)
            p->~T();
        if (newSize < (array[2] >> 1))
        {
            reserve(array, pheapAddr, newSize);
        }
    }
    else if (newSize >= array[2])
    {
        reserve(array, pheapAddr, newSize + (newSize >> 2));
    }
    array[1] = newSize;
}

// Array<CallInfo>::ResizeNoConstruct.
// @0x142624020
void FUN_142624020(U* array, void* owner, U n)
{
    RawResizeNoConstruct<AmpPtrRecord>(array, owner, n, FUN_142623b10);
}

// Array<Ptr>::ResizeNoConstruct.
// @0x1426240f0
void FUN_1426240f0(U* array, void* owner, U n)
{
    RawResizeNoConstruct<AmpPtrElem>(array, owner, n, FUN_142623ee0);
}

// HashSetBase::findIndexCore over an eight-byte key cached-hash set (link +0, hash +8, key +0x10).
static __forceinline SPInt RawFindIndexCore8(U* table, const U* key, U hashValue, U stride)
{
    UPInt index = hashValue;
    const char* e = RawEntry(table, index, stride);

    // If empty or occupied by a collider, not found.
    if (*(const SPInt*)e == -2 || *(const U*)(e + 8) != index)
        return -1;

    while (1)
    {
        if (*(const U*)(e + 8) == hashValue && RawField<U>(e, 0x10) == *key)
        {
            // Found it.
            return index;
        }

        // Keep looking through the chain.
        index = *(const U*)e;
        if (index == (UPInt)-1)
            break; // end of chain

        e = RawEntry(table, index, stride);
    }
    return -1;
}

// HashNode<UInt64, Ptr<...>>: operator=(NodeRef) copies the key, then the Ptr (AddRef new, Release old).
struct AmpPtrNode
{
    U First;
    void* Second;
    void operator=(const NodeRef& src)
    {
        First = *src.Key;
        if (*src.Value)
            FUN_14257dc30(*src.Value);
        if (Second)
            FUN_14257dcb0(Second);
        Second = *src.Value;
    }
};

// HashNode<UInt64, String>.
struct AmpStringNode
{
    U First;
    String Second;
    void operator=(const KeyStringOps::Ref& src)
    {
        First = *src.Key;
        Second = *src.Value;
    }
};

// HashSetBase::Set(pmemAddr, NodeRef) for a Hash<UInt64, Ptr<...>>.
// @0x142624190
void FUN_142624190(U** self, const U* key, void* const* value)
{
    NodeRef ref = { key, value };
    UPInt hashValue = FixedSizeHash<U>()(*ref.Key);
    SPInt index = (SPInt)-1;

    if (*self != NULL)
        index = RawFindIndexCore8(*self, ref.Key, hashValue & (*self)[1], 0x20);

    if (index >= 0)
    {
        RawField<AmpPtrNode>(RawEntry(*self, (U)index, 0x20), 0x10) = ref;
    }
    else
    {
        // Entry under key doesn't exist.
        FUN_14261ee70(self, self, &ref, hashValue);
    }
}

// HashSetBase::Set(pmemAddr, NodeRef) for a Hash<UInt64, String>.
// @0x142624300
void FUN_142624300(U** self, const U* key, const String* value)
{
    KeyStringOps::Ref ref = { key, value };
    UPInt hashValue = FixedSizeHash<U>()(*ref.Key);
    SPInt index = (SPInt)-1;

    if (*self != NULL)
        index = RawFindIndexCore8(*self, ref.Key, hashValue & (*self)[1], 0x20);

    if (index >= 0)
    {
        RawField<AmpStringNode>(RawEntry(*self, (U)index, 0x20), 0x10) = ref;
    }
    else
    {
        // Entry under key doesn't exist.
        FUN_14261f070(self, self, &ref, hashValue);
    }
}

// ViewStats::CallInfo, one 0x18 entry of the call stack at +0x30.
struct AmpCallInfo
{
    void* FunctionInfo;
    U FileId;
    UInt32 LineNumber;
};

// ArrayLH<CallInfo>: Data, Size, Policy.
struct AmpCallstack
{
    AmpCallInfo* Data;
    U Size;
    U Policy;
    bool IsEmpty() const { return Size == 0; }
    AmpCallInfo& Back() { return Data[Size - 1]; }
};

// ViewStats::RefreshActiveLine: copies the top call's file and line under ActiveLock (+0x78).
static inline void RawRefreshActiveLine(char* self)
{
    AmpCallstack& callstack = RawField<AmpCallstack>(self, 0x30);
    if (!callstack.IsEmpty())
    {
        AmpCallInfo& back = callstack.Back();
        RawLocker lock(self + 0x78);
        RawField<U>(self, 0x68) = back.FileId;
        RawField<UInt32>(self, 0x70) = back.LineNumber;
    }
}

// The ViewStats fields these setters touch.
struct AmpViewStatsView
{
    char Pad0[0x30];
    AmpCallstack Callstack;            // +0x30
    char Pad48[0x20];
    U ActiveFileId;                    // +0x68
    UInt32 ActiveLineNumber;           // +0x70
    CRITICAL_SECTION ActiveLock;       // +0x78

    void RefreshActiveLine()
    {
        if (!Callstack.IsEmpty())
        {
            AmpCallInfo& back = Callstack.Back();
            RawLocker lock((char*)&ActiveLock);
            ActiveFileId = back.FileId;
            ActiveLineNumber = back.LineNumber;
        }
    }
};

// ViewStats::SetActiveFile.
// @0x142624450
void FUN_142624450(char* self, U fileId)
{
    AmpViewStatsView* vs = (AmpViewStatsView*)self;
    if (!vs->Callstack.IsEmpty())
    {
        vs->Callstack.Back().FileId = fileId;
        vs->RefreshActiveLine();
    }
    else
    {
        RawLocker lock((char*)&vs->ActiveLock);
        vs->ActiveFileId = fileId;
    }
}

// ViewStats::SetActiveLine.
// @0x1426244e0
void FUN_1426244e0(char* self, int lineNumber)
{
    AmpViewStatsView* vs = (AmpViewStatsView*)self;
    if (!vs->Callstack.IsEmpty())
    {
        vs->Callstack.Back().LineNumber = lineNumber;
        vs->RefreshActiveLine();
    }
    else
    {
        RawLocker lock((char*)&vs->ActiveLock);
        vs->ActiveLineNumber = lineNumber;
    }
}

// @0x142624570
void FUN_142624570(char* self, int v)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    RawField<int>(self, 0x118) = v;
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Copies five capability values out of an interface object (vtable slots +0x20/+0x30/+0x38/+0x48/+0x40);
// the middle three are floats.
// @0x1426245c0
void FUN_1426245c0(char* self, void** obj)
{
    typedef int (*IntFn)(void*);
    typedef float (*FloatFn)(void*);
    RawLocker lock(self + 0xe0);
    if (obj)
    {
        RawField<int>(self, 0x11c) = (*(IntFn**)obj)[0x20 / 8](obj);
        RawField<float>(self, 0x120) = (*(FloatFn**)obj)[0x30 / 8](obj);
        RawField<float>(self, 0x124) = (*(FloatFn**)obj)[0x38 / 8](obj);
        RawField<float>(self, 0x128) = (*(FloatFn**)obj)[0x48 / 8](obj);
        RawField<int>(self, 0x12c) = (*(IntFn**)obj)[0x40 / 8](obj);
    }
}

// ViewStats::SetName: stores the movie path, reduced to the part after the last path separator.
// @0x142624660
void FUN_142624660(char* self, const char* name)
{
    String& viewName = RawField<String>(self, 0x110);
    viewName = name;

    // Remove the path, if any
    UPInt nameLength = viewName.GetLength();
    for (UPInt i = 0; i < nameLength; ++i)
    {
        UPInt index = nameLength - i - 1;
        if (viewName[index] == '/' || viewName[index] == '\\')
        {
            viewName = viewName.Substring(index + 1, nameLength);
            break;
        }
    }
}

// Accumulates a size delta into the per-kind byte counters of a stats snapshot.
// @0x142624700
void FUN_142624700(U self, U id, int delta, int count, U stats)
{
    char* st = (char*)stats;
    if ((int)(id >> 32) != 1)
        return;
#define ADD(off, v) (*(int*)(st + (off)) += (v))
    switch ((unsigned)id)
    {
    case 0: ADD(0x1c, delta); break;
    case 1: ADD(0x24, delta); break;
    case 2: ADD(0x20, delta); break;
    case 3: ADD(0x28, delta); break;
    case 4: ADD(0x2c, delta); break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x1a:
    case 0x1f:
    case 0x21:
    case 0x2f: ADD(0x4c, delta); ADD(0x30, delta); break;
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x1b:
    case 0x20:
    case 0x22:
    case 0x2e: ADD(0x4c, delta); ADD(0x34, delta); break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x1c: ADD(0x4c, delta); ADD(0x38, delta); break;
    case 5:
    case 6:
    case 7: ADD(0x3c, delta); break;
    case 8: ADD(0x40, delta); break;
    case 9: ADD(0x44, delta); break;
    case 10: ADD(0x7c, count); break;
    case 0xb: ADD(0x48, delta); break;
    case 0xc:
    case 0xd: ADD(0x8c, count); break;
    default: break;
    }
#undef ADD
}

// ---- hash set Grow (resize) instances: new power-of-two table, rehash every live entry, free the old table ----

static inline U RawGrowSize(U n) { return n < 8 ? 8 : 1ULL << ((FUN_1422fe440(n - 1) + 1) & 0x3f); }

template<U Stride>
static inline U* RawNewTable(void* owner, U size)
{
    U* t = (U*)Memory::AllocAutoHeap(owner, size * Stride + 0x10, AllocInfo(2, 0, 0));
    t[0] = 0;
    t[1] = size - 1;
    for (U i = 0; i < size; i++)
        *(SPInt*)RawEntry(t, i, Stride) = -2;
    return t;
}

// Plain payload words copied from an old entry.
template<int Words>
struct RawWordsOps
{
    static void Copy(char* d, const char* s) { Construct(d, s); }
    static void Construct(char* d, const char* s)
    {
        for (int i = 0; i < Words; i++)
            ((U*)d)[i] = ((const U*)s)[i];
    }
    static void Assign(char* d, const char* s) { Construct(d, s); }
};

// @0x142624840
void FUN_142624840(U** self, void* owner, U n)
{
    if (n == 0)
    {
        RawClearPlainSet((U*)self, 0x28);
        return;
    }
    U* nt = RawNewTable<0x28>(owner, RawGrowSize(n));
    if (U* old = *self)
    {
        for (U i = 0; i <= old[1]; i++)
        {
            char* e = RawEntry(old, i, 0x28);
            if (*(SPInt*)e != -2)
            {
                RawHashAdd<0x28, RawWordsOps<3> >(&nt, RawFieldPtr<const char>(e, 0x10), FUN_14261fc40(0, RawFieldPtr<const unsigned char>(e, 0x10)));
                *(SPInt*)e = -2;
            }
        }
        Memory::Free(old);
    }
    *self = nt;
}

// @0x142624af0
void FUN_142624af0(U** self, void* owner, U n)
{
    if (n == 0)
    {
        FUN_1426207e0((U*)self);
        return;
    }
    U* nt = RawNewTable<0x30>(owner, RawGrowSize(n));
    if (U* old = *self)
    {
        for (U i = 0; i <= old[1]; i++)
        {
            char* e = RawEntry(old, i, 0x30);
            if (*(SPInt*)e != -2)
            {
                RawHashAdd<0x30, RawWordsOps<4> >(&nt, RawFieldPtr<const char>(e, 0x10), FUN_14261fd80(0, RawFieldPtr<const unsigned char>(e, 0x10)));
                *(SPInt*)e = -2;
            }
        }
        Memory::Free(old);
    }
    *self = nt;
}

// Movie* -> counted pointer sets; the entries are re-added through the set's add and the old value released.
template<void (*Add)(U**, void*, const char*, U)>
static inline void RawGrowMoviePtr(U** self, void* owner, U n)
{
    if (n == 0)
    {
        FUN_142620840((U*)self);
        return;
    }
    U* nt = RawNewTable<0x20>(owner, RawGrowSize(n));
    if (U* old = *self)
    {
        for (U i = 0; i <= old[1]; i++)
        {
            char* e = RawEntry(old, i, 0x20);
            if (*(SPInt*)e != -2)
            {
                Add(&nt, owner, e + 0x10, RawKey8Hash(RawField<U>(e, 0x10)));
                if (RawField<void*>(e, 0x18))
                    FUN_14257dcb0(RawField<void*>(e, 0x18));
                *(SPInt*)e = -2;
            }
        }
        Memory::Free(old);
    }
    *self = nt;
}

// @0x142624d70
void FUN_142624d70(U** self, void* owner, U n) { RawGrowMoviePtr<FUN_14261e7a0>(self, owner, n); }
// @0x142624f80
void FUN_142624f80(U** self, void* owner, U n) { RawGrowMoviePtr<FUN_14261e940>(self, owner, n); }

// {key, String} entries.
// @0x1426251d0
void FUN_1426251d0(U** self, void* owner, U n)
{
    if (n == 0)
    {
        RawClearStringSet((U*)self, 0x18);
        return;
    }
    U* nt = RawNewTable<0x20>(owner, RawGrowSize(n));
    if (U* old = *self)
    {
        for (U i = 0; i <= old[1]; i++)
        {
            char* e = RawEntry(old, i, 0x20);
            if (*(SPInt*)e != -2)
            {
                KeyStringOps::Ref ref = { RawFieldPtr<const U>(e, 0x10), RawFieldPtr<const String>(e, 0x18) };
                RawHashAdd<0x20, KeyStringOps>(&nt, ref, RawKey8Hash(RawField<U>(e, 0x10)));
                (RawFieldPtr<String>(e, 0x18))->~String();
                *(SPInt*)e = -2;
            }
        }
        Memory::Free(old);
    }
    *self = nt;
}

// {String, UInt32} entries hashed case-insensitively.
// @0x1426255e0
void FUN_1426255e0(U** self, void* owner, U n)
{
    if (n == 0)
    {
        RawClearStringSet((U*)self, 0x10);
        return;
    }
    U* nt = RawNewTable<0x20>(owner, RawGrowSize(n));
    if (U* old = *self)
    {
        for (U i = 0; i <= old[1]; i++)
        {
            char* e = RawEntry(old, i, 0x20);
            if (*(SPInt*)e != -2)
            {
                const String* key = RawFieldPtr<const String>(e, 0x10);
                U hash = String::BernsteinHashFunctionCIS(key->ToCStr(), key->GetSize(), 0x1505);
                StringKeyOps::Ref ref = { key, RawFieldPtr<const UInt32>(e, 0x18) };
                RawHashAdd<0x20, StringKeyOps>(&nt, ref, hash);
                (RawFieldPtr<String>(e, 0x10))->~String();
                *(SPInt*)e = -2;
            }
        }
        Memory::Free(old);
    }
    *self = nt;
}

}} // namespace Scaleform::GFx
