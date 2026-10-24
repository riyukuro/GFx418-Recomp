// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP server support (second part):
// memory file / socket buffer deleting destructors, the hash set CheckExpand instances, set clears and the
// per-frame statistics snapshot functions of the AMP server state. Raw-layout free functions under the exe's own
// FUN_<va> names. Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426202f0-0x142623c60 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#include "sfr_gfx_07raw.h"

#include <new>
#include <string.h>
#include <windows.h>

namespace Scaleform { namespace GFx {

namespace {
// Lock::Locker over the state's critical section: entered here, left when the scope ends.
struct RawLocker
{
    LPCRITICAL_SECTION pLock;
    explicit RawLocker(char* lock) : pLock((LPCRITICAL_SECTION)lock) { EnterCriticalSection(pLock); }
    ~RawLocker() { LeaveCriticalSection(pLock); }
};

}

extern char DAT_14318f020[];
extern char DAT_14318f048[];
extern char DAT_14318f060[];
extern char DAT_14318f040[];
extern char DAT_14318f030[];

void FUN_14257db40(void*);
void FUN_14015b310(void*, UPInt);
bool FUN_14258bb00(void*);   // Mutex::TryLock
void FUN_14258bb70(void*);   // Mutex::Unlock
void FUN_14261fa90(void*);
void FUN_142624840(U**, void*, U);
void FUN_142624af0(U**, void*, U);
void FUN_142624d70(U**, void*, U);
void FUN_142624f80(U**, void*, U);
void FUN_1426251d0(U**, void*, U);
void FUN_1426255e0(U**, void*, U);
U* FUN_1426223c0(U**, U*, const String*);   // NoCase String set Find(iterator out, key)
void FUN_1426240f0(U*, void*, U);             // Array<Ptr>::Resize
void FUN_142623bc0(U*, void*, U);             // Array<0x20-byte record>::Reserve
void FUN_142623c60(U*, void*, U);             // Array<0x10-byte record>::Reserve
void FUN_142623e40(U*, void*, U);             // Array<Ptr>::Reserve
void FUN_142623d00(U*, void*, U);             // Array<0x18-byte record>::Reserve
void FUN_142623da0(U*, void*, U);             // Array<Ptr>::Reserve
void FUN_142624190(U**, const U*, void* const*);   // Hash<key, Ptr>::Set
void FUN_142624300(U**, const U*, const String*);   // Hash<key, Ptr>::Set (second value type)
void FUN_142624700(U, U, int, int, U);
void FUN_14268a570(void*, U*);                // fills a set with the keys reachable from an object
U FUN_1425e3510();                            // timer frequency
void FUN_14257dc30(void*);
void FUN_14261e730(char*, U*);
void FUN_14261f220(U**, void*, StringKeyOps::Ref*, U);
void FUN_14261ec70(U**, void*, NodeRef*, U);
void FUN_14261eae0(U**, void*, WordsRefOps::Ref*, U);
U FUN_14261fc40(void*, const unsigned char*);   // multiname key hash
void FUN_14258aca0(void*);                      // Mutex::DoLock
void FUN_142584260(void*);                      // Event::ResetEvent
void FUN_142624020(U*, void*, U);               // Array<0x18-byte record>::Resize
void FUN_142623f80(U*, void*, U);               // Array<8-byte>::Reserve
void FUN_14261ee70(U**, void*, NodeRef*, U);
SPInt FUN_1425e3560();                          // performance counter
U FUN_1425e5080(void*);                         // Alg::Random::Generator::NextRandom
void* FUN_142686d30(void*);                     // snapshot struct constructor
void FUN_142585f70(void*, int);                 // String::AppendChar
void FUN_142623820(char*, unsigned, U, const char*, int, int, char);
void FUN_142623050(char*, int, int, U);
void FUN_1426237c0(char*);

static inline void RawDelete(void* self, unsigned long long flags, UPInt size)
{
    if (flags & 1)
        ::operator delete(self, size);
}

// @0x1426202f0
void* FUN_1426202f0(char* self, unsigned flags)
{
    (RawFieldPtr<String>(self, 0x10))->~String();
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x30);
    }
    return self;
}

// @0x142620370
void* FUN_142620370(char* self, unsigned flags)
{
    (RawFieldPtr<String>(self, 0x10))->~String();
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x20);
    }
    return self;
}

// @0x1426203f0
void* FUN_1426203f0(char* self, unsigned flags)
{
    Memory::Free(RawField<void*>(self, 0x20));
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x38);
    }
    return self;
}

// @0x142620460
void* FUN_142620460(char* self, unsigned flags)
{
    FUN_14261fa90(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x1d0);
    }
    return self;
}

// Counter adjusters of the AMP stats (vftable slots in the exe's .rdata).
// @0x1426204c0
void FUN_1426204c0(char* self, int delta) { RawField<int>(self, 0x174) += delta; }
// @0x1426204d0
void FUN_1426204d0(char* self, int delta) { RawField<int>(self, 0x170) += delta; }

// Counts a named marker: bumps an existing entry or adds {name, 1}.
// MS2-FUNCTIONAL: the exe holds the found iterator in rax/rdx (rcx/rax here); same blocks
// @0x1426204e0
void FUN_1426204e0(char* self, const char* name)
{
    U found[2];
    {
        String key(name);
        FUN_1426223c0(RawFieldPtr<U*>(self, 0x168), found, &key);
    }
    if (found[0] && *(U*)found[0] && (SPInt)found[1] <= *(SPInt*)(*(U*)found[0] + 8))
    {
        (*(int*)(*(U*)found[0] + 0x10 + found[1] * 0x20 + 0x18))++;
        return;
    }
    UInt32 one = 1;
    String name2(name);
    StringKeyOps::Ref ref = { &name2, &one };
    FUN_14261f220(RawFieldPtr<U*>(self, 0x168), self + 0x168, &ref,
                  String::BernsteinHashFunctionCIS(name2.ToCStr(), name2.GetSize(), 0x1505));
}

// @0x142620600
void FUN_142620600(U** self, void* ctx) { RawCheckExpand<FUN_142624840>(self, ctx); }
// @0x142620650
void FUN_142620650(U** self, void* ctx) { RawCheckExpand<FUN_142624af0>(self, ctx); }
// @0x1426206a0
void FUN_1426206a0(U** self, void* ctx) { RawCheckExpand<FUN_142624d70>(self, ctx); }
// @0x1426206f0
void FUN_1426206f0(U** self, void* ctx) { RawCheckExpand<FUN_142624f80>(self, ctx); }
// @0x142620740
void FUN_142620740(U** self, void* ctx) { RawCheckExpand<FUN_1426251d0>(self, ctx); }
// @0x142620790
void FUN_142620790(U** self, void* ctx) { RawCheckExpand<FUN_1426255e0>(self, ctx); }

// @0x1426207e0
void FUN_1426207e0(U* self) { RawClearPlainSet(self, 0x30); }
// MS2-FUNCTIONAL: the exe shrink-wraps the callee-saved spill into the non-empty path (split .pdata chunk); same clear logic.
// @0x142620840
__declspec(noinline) void FUN_142620840(U* self) { RawClearPtrSet(self); }
// @0x1426208d0
__declspec(noinline) void FUN_1426208d0(U* self) { RawClearStringSet(self, 0x10); }

// @0x142620970
void FUN_142620970(char* self)
{
    RawLocker lock(self + 0xe0);
    RawClearPlainSet(RawFieldPtr<U>(self, 0x10), 0x30);
    FUN_1426240f0(RawFieldPtr<U>(self, 0x48), self + 0x48, 0);
    RawField<int>(self, 0x60) = 0;
}

// @0x142620a10
void FUN_142620a10(char* self)
{
    if (FUN_14258bb00(self + 0xa8))
    {
        FUN_142620840(RawFieldPtr<U>(self, 0xa0));
        FUN_14258bb70(self + 0xa8);
    }
}

// The set's ConstIterator (Begin() / IsEnd() / ++), over raw entries of the given stride.
namespace {
template<U Stride>
struct RawSetIterator
{
    U**   pHash;
    SPInt Index;
    RawSetIterator(U** hash, SPInt index) : pHash(hash), Index(index) {}
    static RawSetIterator Begin(U** hash)
    {
        if (!*hash)
            return RawSetIterator(nullptr, 0);
        U i = 0;
        while (i <= (*hash)[1] && *(SPInt*)RawEntry(*hash, i, Stride) == -2)
            ++i;
        return RawSetIterator(hash, i);
    }
    bool  IsEnd() const { return !pHash || !*pHash || Index > (SPInt)(*pHash)[1]; }
    char* Entry() const { return RawEntry(*pHash, Index, Stride); }
    void  operator++()
    {
        if (Index <= (SPInt)(*pHash)[1])
        {
            ++Index;
            while ((U)Index <= (*pHash)[1] && *(SPInt*)RawEntry(*pHash, Index, Stride) == -2)
                ++Index;
        }
    }
};
}

// Zeroes the running value of every entry of the per-name statistics set.
// @0x142620a50
void FUN_142620a50(char* self)
{
    RawLocker lock(self + 0xe0);
    for (RawSetIterator<0x28> it = RawSetIterator<0x28>::Begin(RawFieldPtr<U*>(self, 0xd0)); !it.IsEnd(); ++it)
        RawField<U>(it.Entry(), 0x20) = 0;
}

// @0x142620b10
void FUN_142620b10(char* self)
{
    RawLocker lock(self + 0xe0);
    FUN_1426208d0(RawFieldPtr<U>(self, 0x168));
}

// Copies the per-type statistics into a snapshot and the keys / objects it refers to.
// @0x142620b50
void FUN_142620b50(char* self, char* snap)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    U* table = RawField<U*>(self, 0x10);
    if (table)
    {
        for (U i = 0; i <= table[1]; i++)
        {
            char* e = RawEntry(table, i, 0x30);
            if (*(SPInt*)e == -2)
                continue;
            char* p = e + 0x10;
            int count = RawField<int>(p, 0x10);
            U total = RawField<U>(p, 0x18);
            if (!count && !total)
                continue;
            U key = *(U*)(p + 8);
            char* rec = RawArrayPush<FUN_142623bc0>((U*)(RawField<char*>(snap, 0x60) + 0x10), 0x20);
            *(U*)rec = key;
            *(U*)(rec + 8) = *(U*)p;
            RawField<int>(rec, 0x10) = count;
            RawField<U>(rec, 0x18) = total;

            U* names = RawField<U*>(self, 0x18);
            SPInt found = RawFindKey8(names, key, 0x20);
            if (found >= 0)
            {
                char* snapNames = RawField<char*>(snap, 0x60);
                if (RawFindKey8(RawField<U*>(snapNames, 0x28), key, 0x20) < 0)
                    FUN_142624190(RawFieldPtr<U*>(snapNames, 0x28), &key, (void* const*)(RawEntry(names, found, 0x20) + 0x18));
            }
        }
    }

    U keys = 0;
    U* objects = RawFieldPtr<U>(self, 0x48);
    for (U i = 0; i < objects[1]; i++)
    {
        char* list = RawField<char*>(snap, 0x70);
        void** src = (void**)(objects[0] + i * 8);
        U* array = RawFieldPtr<U>(list, 0x18);
        FUN_1426240f0(array, array, array[1] + 1);
        void* p = *src;
        if (p)
            FUN_14257dc30(p);
        ((void**)array[0])[array[1] - 1] = *src;
        FUN_14268a570(((void**)objects[0])[i], &keys);
    }
    U* keySet = (U*)keys;
    if (keySet)
    {
        for (U i = 0; i <= keySet[1]; i++)
        {
            char* e = RawEntry(keySet, i, 0x18);
            if (*(SPInt*)e == -2)
                continue;
            U* key = RawFieldPtr<U>(e, 0x10);
            U* names = RawField<U*>(self, 0x18);
            SPInt found = RawFindKey8(names, *key, 0x20);
            if (found < 0)
                continue;
            char* snapObj = RawField<char*>(snap, 0x70);
            if (RawFindKey8(RawField<U*>(snapObj, 0x30), *key, 0x20) < 0)
                FUN_142624190(RawFieldPtr<U*>(snapObj, 0x30), key, (void* const*)(RawEntry(names, found, 0x20) + 0x18));
        }
        RawClearPlainSet(&keys, 0x18);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Snapshots each histogram of the per-type table (non-empty bins scaled to microseconds) into a new object.
// @0x1426214b0
void FUN_1426214b0(char* self, char* snap)
{
    if (!FUN_14258bb00(self + 0xa8))
        return;
    U* table = RawField<U*>(self, 0xa0);
    if (table)
    {
        for (U i = 0; i <= table[1]; i++)
        {
            char* e = RawEntry(table, i, 0x20);
            if (*(SPInt*)e == -2)
                continue;
            char* hist = RawField<char*>(e, 0x18);
            U bins = RawField<U>(hist, 0x18);
            unsigned used = 0;
            for (U j = 0; j < bins; j++)
                if (((U*)RawField<U>(hist, 0x10))[j])
                    used++;
            if (!used)
                continue;
            char* obj = (char*)Memory::AllocAutoHeap(snap, 0x38, AllocInfo(0x242, 0, 0));
            if (obj)
            {
                memset(obj + 8, 0, 0x30);
                *(int*)(obj + 8) = 1;
                *(void**)obj = DAT_14318f020;
            }
            U key = RawField<U>(e, 0x10);
            RawField<int>(obj, 0x10) = (int)(key >> 32);
            RawField<int>(obj, 0x14) = (int)key;
            RawField<int>(obj, 0x18) = (int)bins;
            U* recs = RawFieldPtr<U>(obj, 0x20);
            if (recs[2] <= used)
                FUN_142623c60(recs, recs, used + (used >> 2));
            recs[1] = used;
            U n = 0;
            for (U j = 0; j < RawField<U>(hist, 0x18); j++)
            {
                U v = ((U*)RawField<U>(hist, 0x10))[j];
                if (v)
                {
                    char* rec = (char*)recs[0] + n * 0x10;
                    *(int*)rec = (int)j;
                    n++;
                    *(U*)(rec + 8) = (v * 1000000) / FUN_1425e3510();
                }
            }
            char* list = RawField<char*>(snap, 0x58);
            U* array = RawFieldPtr<U>(list, 0x10);
            U count = array[1] + 1;
            if (array[2] <= count)
                FUN_142623e40(array, array, count + (count >> 2));
            array[1] = count;
            FUN_14257dc30(obj);
            ((void**)array[0])[count - 1] = obj;
            FUN_14257dcb0(obj);
        }
    }
    FUN_14258bb70(self + 0xa8);
}

// Copies the running per-name values (scaled to microseconds) into the snapshot.
// @0x142621820
void FUN_142621820(char* self, char* snap)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    U* table = RawField<U*>(self, 0xd0);
    if (table)
    {
        for (U i = 0; i <= table[1]; i++)
        {
            char* e = RawEntry(table, i, 0x28);
            if (*(SPInt*)e == -2 || !RawField<U>(e, 0x20))
                continue;
            U key = RawField<U>(e, 0x10);
            unsigned extra = RawField<unsigned>(e, 0x18);
            U scaled = (RawField<U>(e, 0x20) * 1000000) / FUN_1425e3510();
            char* rec = RawArrayPush<FUN_142623d00>((U*)(RawField<char*>(snap, 0x68) + 0x10), 0x18);
            *(U*)rec = key;
            *(unsigned*)(rec + 8) = extra;
            RawField<U>(rec, 0x10) = scaled;

            U* names = RawField<U*>(self, 0xd8);
            SPInt found = RawFindKey8(names, key, 0x20);
            if (found >= 0)
            {
                char* snapNames = RawField<char*>(snap, 0x68);
                if (RawFindKey8(RawField<U*>(snapNames, 0x28), key, 0x20) < 0)
                    FUN_142624300(RawFieldPtr<U*>(snapNames, 0x28), &key, (const String*)(RawEntry(names, found, 0x20) + 0x18));
            }
        }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Copies the marker table into the snapshot as {name, count} objects.
// @0x142621c80
void FUN_142621c80(char* self, char* snap)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    U* table = RawField<U*>(self, 0x168);
    if (table)
    {
        for (U i = 0; i <= table[1]; i++)
        {
            char* e = RawEntry(table, i, 0x20);
            if (*(SPInt*)e == -2)
                continue;
            char* obj = (char*)Memory::AllocAutoHeap(snap, 0x20, AllocInfo(0x242, 0, 0));
            if (obj)
            {
                memset(obj + 8, 0, 0x18);
                *(int*)(obj + 8) = 1;
                *(void**)obj = DAT_14318f048;
                new (obj + 0x10) StringLH();
            }
            RawField<String>(obj, 0x10) = RawField<String>(e, 0x10);
            RawField<int>(obj, 0x18) = RawField<int>(e, 0x18);
            U* array = RawFieldPtr<U>(snap, 0x40);
            U count = array[1] + 1;
            if (array[2] <= count)
                FUN_142623da0(array, array, count + (count >> 2));
            array[1] = count;
            FUN_14257dc30(obj);
            ((void**)array[0])[count - 1] = obj;
            FUN_14257dcb0(obj);
        }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// @0x142621ed0
void FUN_142621ed0(char* self, U arg)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    U ctx[2] = { arg, (U)self };
    for (U i = 0; i < RawField<U>(self, 0x50); i++)
    {
        char* item = ((char**)RawField<U>(self, 0x48))[i];
        FUN_142624700((U)self, RawField<U>(item, 0x10), RawField<int>(item, 0x20) - RawField<int>(item, 0x18), 1, arg);
        for (U j = 0; j < RawField<U>(item, 0x38); j++)
            FUN_14261e730(((char**)RawField<U>(item, 0x30))[j], ctx);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}


// ===== accessors, finds and the scope stack of the AMP server state =====

static inline bool RawFound(const U* it) { return it[0] && *(U*)it[0] && (SPInt)it[1] <= *(SPInt*)(*(U*)it[0] + 8); }

// The find instances inline the whole lookup and hash the key through its address.
static __forceinline SPInt RawFindKey8At(U* table, const U* key)
{
    if (!table)
        return -1;
    const unsigned char* k = (const unsigned char*)key;
    U mixed = (((U)k[3] * 0x1003f + (U)k[2]) * 0x1003f + (U)k[1]) * 0x1003f + (U)k[4] * 0xfc5d1543ec5f01ULL +
              (U)k[5] * (U)-0x64cfd3d7e9d39ec1LL + (U)k[7] * (U)-0x283c1b695cee4e41LL + (U)k[6] * 0x5d02f409d62aee81ULL;
    U hash = (U)-0x514d9afbc3e934fbLL + mixed + (U)k[0];
    U home = table[1] & hash;
    U index = home;
    char* e = RawEntry(table, index, 0x20);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != home)
        return -1;
    for (;;)
    {
        if (*(U*)(e + 8) == home && RawField<U>(e, 0x10) == *key)
            return (SPInt)index;
        SPInt next = *(SPInt*)e;
        if (next == -1)
            return -1;
        index = (U)next;
        e = RawEntry(table, index, 0x20);
    }
}

static __forceinline U* RawFindMovieKey(U** self, U* out, const U* key)
{
    SPInt idx = RawFindKey8At(*self, key);
    out[0] = idx >= 0 ? (U)self : 0;
    out[1] = idx >= 0 ? (U)idx : 0;
    return out;
}

// @0x142622030
U* FUN_142622030(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }
// @0x142622160
U* FUN_142622160(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }
// @0x142622290
U* FUN_142622290(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }

// @0x1426223c0
U* FUN_1426223c0(U** self, U* out, const String* key)
{
    U* table = *self;
    SPInt found = -1;
    if (table)
    {
        const char* kd = key->ToCStr();
        U home = table[1] & String::BernsteinHashFunctionCIS(kd, key->GetSize(), 0x1505);
        U index = home;
        char* e = RawEntry(table, index, 0x20);
        if (*(SPInt*)e != -2 && *(U*)(e + 8) == home)
        {
            for (;;)
            {
                if (*(U*)(e + 8) == home && strcmp((RawFieldPtr<const String>(e, 0x10))->ToCStr(), kd) == 0)
                {
                    found = (SPInt)index;
                    break;
                }
                SPInt next = *(SPInt*)e;
                if (next == -1)
                    break;
                index = (U)next;
                e = RawEntry(table, index, 0x20);
            }
        }
    }
    if (found < 0)
    {
        found = 0;
        self = 0;
    }
    out[0] = (U)self;
    out[1] = (U)found;
    return out;
}

template<class T, unsigned Lock, unsigned Off>
static inline T RawLocked(char* self)
{
    RawLocker lock(self + Lock);
    return *(T*)(self + Off);
}

// @0x1426224d0
U FUN_1426224d0(char* self) { return RawLocked<U, 0x78, 0x68>(self); }
// @0x142622510
unsigned FUN_142622510(char* self) { return RawLocked<unsigned, 0x78, 0x70>(self); }
// @0x142622550
unsigned FUN_142622550(char* self) { return RawLocked<unsigned, 0xe0, 0x118>(self); }
// @0x142622590
unsigned FUN_142622590(char* self) { return RawLocked<unsigned, 0xe0, 0x12c>(self); }
// @0x1426225d0
float FUN_1426225d0(char* self) { return RawLocked<float, 0xe0, 0x128>(self); }
// @0x142622620
float FUN_142622620(char* self) { return RawLocked<float, 0xe0, 0x124>(self); }
// @0x142622900
unsigned FUN_142622900(char* self) { return RawLocked<unsigned, 0xe0, 0x11c>(self); }
// @0x142622940
unsigned FUN_142622940(char* self) { return RawLocked<unsigned, 0xe0, 0x108>(self); }
// @0x142622980
float FUN_142622980(char* self) { return RawLocked<float, 0xe0, 0x120>(self); }

// Timer sampling: with 0 returns the counter delta, otherwise scales the elapsed time and re-arms a random skip count.
// @0x142622670
SPInt FUN_142622670(char* self, unsigned period)
{
    SPInt elapsed = 0;
    if (period == 0)
    {
        SPInt now = FUN_1425e3560();
        SPInt prev = RawField<SPInt>(self, 0x160);
        RawField<SPInt>(self, 0x160) = now;
        return now - prev;
    }
    if (RawField<SPInt>(self, 0x160) != 0)
        elapsed = (FUN_1425e3560() - RawField<SPInt>(self, 0x160)) * (SPInt)period;
    int next;
    if (RawField<int>(self, 0x158) == 0)
    {
        RawField<SPInt>(self, 0x160) = FUN_1425e3560();
        U r = FUN_1425e5080(self + 0x130) & 0xffffffffULL;
        next = (int)((r * (U)(unsigned)(period * 2)) / 0xffffffffULL);
    }
    else
    {
        RawField<SPInt>(self, 0x160) = 0;
        next = RawField<int>(self, 0x158) - 1;
    }
    RawField<int>(self, 0x158) = next;
    return elapsed;
}

// Snapshots the open scopes into a new stats record, optionally clearing the recorded scopes.
// @0x142622740
void FUN_142622740(char* self, char* target, char clear)
{
    if (target)
    {
        void* raw = Memory::AllocAutoHeap(self, 0x158, AllocInfo(0x242, 0, 0));
        char* snap = raw ? (char*)FUN_142686d30(raw) : 0;
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
        U ctx[2] = { (U)snap, (U)self };
        for (U i = 0; i < RawField<U>(self, 0x50); i++)
        {
            char* item = ((char**)RawField<U>(self, 0x48))[i];
            FUN_142624700((U)self, RawField<U>(item, 0x10), RawField<int>(item, 0x20) - RawField<int>(item, 0x18), 1, (U)snap);
            for (U j = 0; j < RawField<U>(item, 0x38); j++)
                FUN_14261e730(((char**)RawField<U>(item, 0x30))[j], ctx);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
        if (snap)
            FUN_14257dcb0(snap);
    }
    if (clear)
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
        RawClearPlainSet(RawFieldPtr<U>(self, 0x10), 0x30);
        FUN_1426240f0(RawFieldPtr<U>(self, 0x48), self + 0x48, 0);
        RawField<int>(self, 0x60) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    }
}

// @0x1426229d0
bool FUN_1426229d0(char* self)
{
    typedef char (*Fn)(void*);
    return ((Fn*)RawField<void**>(self, 0x178))[1](self + 0x178) == 0;
}

// Returns the per-key record array for (a, b), creating it with `count` zeroed words on first use.
// @0x1426229f0
char* FUN_1426229f0(char* self, unsigned a, U b, unsigned count)
{
    FUN_14258aca0(self + 0xa8);
    U** set = RawFieldPtr<U*>(self, 0xa0);
    U key = ((U)a << 32) + (b & 0xffffffffULL);
    U it[2];
    FUN_142622030(set, it, &key);
    if (!RawFound(it))
    {
        char* rec = (char*)Memory::AllocAutoHeap(self, 0x28, AllocInfo(0x246, 0, 0));
        if (rec)
        {
            *(void**)rec = (void*)DAT_14318f060;
            *(int*)(rec + 8) = 1;
            RawField<U>(rec, 0x18) = 0;
            RawField<U>(rec, 0x10) = 0;
            RawField<U>(rec, 0x20) = 0;
            U n = (U)(SPInt)(int)count;
            if (RawField<U>(rec, 0x18) <= n)
                FUN_142623f80(RawFieldPtr<U>(rec, 0x10), rec + 0x10, n + (n >> 2));
            RawField<U>(rec, 0x18) = n;
            memset(RawField<void*>(rec, 0x10), 0, (U)count << 3);
        }
        void* value = rec;
        NodeRef ref = { &key, &value };
        SPInt idx = RawFindKey8(*set, key, 0x20);
        if (idx >= 0)
        {
            char* payload = (char*)*set + 0x10 + idx * 0x20;
            RawField<U>(payload, 0x10) = key;
            if (rec)
                FUN_14257dc30(rec);
            if (RawField<void*>(payload, 0x18))
                FUN_14257dcb0(RawField<void*>(payload, 0x18));
            RawField<void*>(payload, 0x18) = value;
        }
        else
            FUN_14261ec70(set, set, &ref, RawKey8Hash(key));
        if (value)
            FUN_14257dcb0(value);
        FUN_142622290(set, it, &key);
    }
    return *(char**)(*(U*)it[0] + 0x10 + it[1] * 0x20 + 0x18) + 0x10;
}

// Allocates a scope record (0x48 bytes, refcount 1, three empty child arrays).
static inline char* RawNewScope(char* self)
{
    char* o = (char*)Memory::AllocAutoHeap(self, 0x48, AllocInfo(2, 0, 0));
    if (o)
    {
        memset(o + 8, 0, 0x40);
        *(void**)o = (void*)DAT_14318f040;
        *(int*)(o + 8) = 1;
    }
    return o;
}

// Mirrors the top scope's (record, count) pair into the locked statistics fields.
static inline void RawPublishTopScope(char* self)
{
    if (RawField<U>(self, 0x38))
    {
        char* slot = (char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18;
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
        RawField<U>(self, 0x68) = *(U*)(slot - 0x10);
        RawField<int>(self, 0x70) = *(int*)(slot - 8);
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
    }
}

// Pushes a new scope {id, arg} onto the scope stack.
static inline void RawPushScope(char* self, U id, U arg)
{
    char* o = RawNewScope(self);
    RawField<U>(o, 0x18) = arg;
    RawField<U>(o, 0x10) = id;
    RawField<int>(self, 0x60) += 1;
    RawField<int>(o, 0x28) = RawField<int>(self, 0x60);
    FUN_14257dc30(o);
    FUN_142624020(RawFieldPtr<U>(self, 0x30), self + 0x30, RawField<U>(self, 0x38) + 1);
    char* slot = (char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18;
    FUN_14257dc30(o);
    *(char**)(slot - 0x18) = o;
    *(U*)(slot - 0x10) = 0;
    *(int*)(slot - 8) = 0;
    FUN_14257dcb0(o);
    RawPublishTopScope(self);
    FUN_14257dcb0(o);
}

// @0x142622c90
void FUN_142622c90(char* self, U arg)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    if (RawField<U>(self, 0x38))
    {
        U id = *(U*)(*(char**)((char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18 - 0x18) + 0x10);
        FUN_142623050(self, (int)(id >> 32), (int)(id & 0xffffffff), arg);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Opens a named scope: interns the name (assigning the next id) and pushes it.
// @0x142622d00
void FUN_142622d00(char* self, const char* name, unsigned id, U arg)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    if (id == 0xffffffffu)
    {
        U** names = RawFieldPtr<U*>(self, 0x20);
        U it[2];
        {
            String key(name);
            FUN_1426223c0(names, it, &key);
        }
        if (!RawFound(it))
        {
            FUN_142623820(self, 1, RawField<unsigned>(self, 0x28), name, 0, 0, 0);
            {
                String key(name);
                StringKeyOps::Ref ref = { &key, RawFieldPtr<UInt32>(self, 0x28) };
                FUN_14261f220(names, names, &ref,
                              String::BernsteinHashFunctionCIS(key.ToCStr(), key.GetSize(), 0x1505));
            }
            {
                String key(name);
                FUN_1426223c0(names, it, &key);
            }
            RawField<int>(self, 0x28) += 1;
        }
        id = *(unsigned*)(*(U*)it[0] + 0x10 + it[1] * 0x20 + 0x18);
    }
    else
        FUN_142623820(self, 1, id, name, 0, 0, 0);
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    RawPushScope(self, (U)id + 0x100000000ULL, arg);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Closes the top scope (when it matches {hi, lo}) and files it under its parent or a root scope.
// @0x142623050
void FUN_142623050(char* self, int hi, int lo, U arg)
{
    if (hi == 0)
        return;
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    U* scopes = RawFieldPtr<U>(self, 0x30);
    U* roots = RawFieldPtr<U>(self, 0x48);
    if (scopes[1])
    {
        char* recs = (char*)scopes[0];
        U off = scopes[1] * 0x18;
        U id = ((U)(unsigned)hi << 32) | (unsigned)lo;
        char* top = RawField<char*>(recs, off - 0x18);
        if (id == RawField<U>(top, 0x10))
        {
            char* done = 0;
            if (top)
            {
                FUN_14257dc30(top);
                done = RawField<char*>(recs, off - 0x18);
            }
            RawField<U>(done, 0x20) = arg + RawField<U>(done, 0x18);
            U n = scopes[1];
            FUN_142624020(scopes, scopes, n - 1);
            FUN_1426237c0(self);
            bool push_root = true;
            U* dest = 0;
            if (scopes[1] != 0)
            {
                char* parent = *(char**)((char*)scopes[0] + scopes[1] * 0x18 - 0x18);
                dest = RawFieldPtr<U>(parent, 0x30);
                push_root = false;
            }
            else if (hi == 1 && (unsigned)(lo - 0xf) <= 0x27)
            {
                for (U i = 0; i < roots[1]; i++)
                {
                    char* r = ((char**)roots[0])[i];
                    if (RawField<U>(r, 0x10) == 0x10000000eULL)
                    {
                        RawField<U>(r, 0x20) += arg;
                        dest = RawFieldPtr<U>(r, 0x30);
                        push_root = false;
                        break;
                    }
                }
                if (push_root)
                {
                    char* o = RawNewScope(self);
                    RawField<U>(o, 0x20) = arg;
                    RawField<U>(o, 0x18) = 0;
                    RawField<U>(o, 0x10) = 0x10000000eULL;
                    RawField<int>(self, 0x60) += 1;
                    RawField<int>(o, 0x28) = RawField<int>(self, 0x60);
                    FUN_1426240f0(RawFieldPtr<U>(o, 0x30), o + 0x30, RawField<U>(o, 0x38) + 1);
                    FUN_14257dc30(done);
                    ((char**)RawField<U>(o, 0x30))[RawField<U>(o, 0x38) - 1] = done;
                    FUN_1426240f0(roots, roots, roots[1] + 1);
                    FUN_14257dc30(o);
                    ((char**)roots[0])[roots[1] - 1] = o;
                    FUN_14257dcb0(o);
                    goto filed;
                }
            }
            if (push_root)
                dest = roots;
            FUN_1426240f0(dest, dest, dest[1] + 1);
            FUN_14257dc30(done);
            ((char**)dest[0])[dest[1] - 1] = done;
        filed:
            if (*(int*)(self + 100) >= 0 && (SPInt)*(int*)(self + 100) <= (SPInt)(int)scopes[1])
            {
                FUN_142584260(self + 0x178);
                *(int*)(self + 100) = -1;
            }
            FUN_14257dcb0(done);
        }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// @0x1426233e0
void FUN_1426233e0(char* self, U hi, U lo, U arg)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    RawPushScope(self, (hi << 32) + (lo & 0xffffffffULL), arg);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// Adds `delta` to the byte counter kept per (scope, count) multiname key.
// @0x142623560
void FUN_142623560(char* self, U delta)
{
    unsigned cnt = RawLocked<unsigned, 0x78, 0x70>(self);
    if (cnt == 0)
        return;
    U scope = RawLocked<U, 0x78, 0x68>(self);
    U** set = RawFieldPtr<U*>(self, 0xd0);
    unsigned char key[16];
    memset(key, 0, sizeof(key));
    *(U*)key = scope;
    *(unsigned*)(key + 8) = cnt;
    U hash = FUN_14261fc40(0, key);
    U* table = *set;
    SPInt idx = -1;
    if (table)
    {
        U home = table[1] & hash;
        U i = home;
        char* e = RawEntry(table, i, 0x28);
        if (*(SPInt*)e != -2 && *(U*)(e + 8) == home)
        {
            for (;;)
            {
                if (*(U*)(e + 8) == home && RawField<U>(e, 0x10) == scope && RawField<int>(e, 0x18) == (int)cnt)
                {
                    idx = (SPInt)i;
                    break;
                }
                SPInt next = *(SPInt*)e;
                if (next == -1)
                    break;
                i = (U)next;
                e = RawEntry(table, i, 0x28);
            }
        }
    }
    if (idx < 0)
    {
        U zero = 0;
        const void* refs[2] = { key, &zero };
        FUN_14261eae0(set, set, (WordsRefOps::Ref*)refs, hash);
        table = *set;
        idx = -1;
        if (table)
        {
            U home = table[1] & hash;
            U i = home;
            char* e = RawEntry(table, i, 0x28);
            if (*(SPInt*)e != -2 && *(U*)(e + 8) == home)
            {
                for (;;)
                {
                    if (*(U*)(e + 8) == home && RawField<U>(e, 0x10) == scope && RawField<int>(e, 0x18) == (int)cnt)
                    {
                        idx = (SPInt)i;
                        break;
                    }
                    SPInt next = *(SPInt*)e;
                    if (next == -1)
                        break;
                    i = (U)next;
                    e = RawEntry(table, i, 0x28);
                }
            }
        }
        if (idx < 0)
            idx = 0;
    }
    *(U*)((char*)*set + 0x30 + idx * 0x28) += delta;
}

// @0x1426237c0
void FUN_1426237c0(char* self) { RawPublishTopScope(self); }

// Sets (or refreshes) the cached description record for a key; with `useCurrent` stamps it with the current scope.
// @0x142623820
void FUN_142623820(char* self, unsigned hi, U lo, const char* text, int a, int b, char useCurrent)
{
    U key = ((U)hi << 32) + (lo & 0xffffffffULL);
    U it[2];
    FUN_142622290(RawFieldPtr<U*>(self, 0x18), it, &key);
    if (!RawFound(it))
    {
        char* rec = (char*)Memory::AllocAutoHeap(self, 0x30, AllocInfo(0x242, 0, 0));
        U cur = 0;
        unsigned curCount = 0;
        if (rec)
        {
            memset(rec + 8, 0, 0x28);
            *(void**)rec = (void*)DAT_14318f030;
            *(int*)(rec + 8) = 1;
            new (rec + 0x10) String();
        }
        RawField<String>(rec, 0x10) = text;
        RawField<int>(rec, 0x18) = a;
        RawField<int>(rec, 0x1c) = b;
        if (useCurrent)
            cur = RawLocked<U, 0x78, 0x68>(self);
        RawField<U>(rec, 0x20) = cur;
        if (useCurrent)
            curCount = RawLocked<unsigned, 0x78, 0x70>(self);
        RawField<unsigned>(rec, 0x28) = curCount;
        void* value = rec;
        FUN_142624190(RawFieldPtr<U*>(self, 0x18), &key, &value);
        if (value)
            FUN_14257dcb0(value);
    }
    else
    {
        char* rec = *(char**)(*(U*)it[0] + 0x10 + it[1] * 0x20 + 0x18);
        unsigned cnt = RawLocked<unsigned, 0x78, 0x70>(self);
        if (useCurrent && cnt != 0)
        {
            U cur = RawLocked<U, 0x78, 0x68>(self);
            unsigned old = RawField<unsigned>(rec, 0x28);
            RawField<U>(rec, 0x20) = cur;
            if (old != 0 && old < cnt)
                cnt = old;
            RawField<unsigned>(rec, 0x28) = cnt;
        }
    }
}

// Interns a string with ';' replaced by '\\' under the key (a, b).
// @0x142623a00
void FUN_142623a00(char* self, unsigned hi, U lo, const char* text)
{
    U key = ((U)hi << 32) + (lo & 0xffffffffULL);
    U it[2];
    FUN_142622160(RawFieldPtr<U*>(self, 0xd8), it, &key);
    if (!RawFound(it))
    {
        U len = strlen(text);
        String s;
        for (U i = 0; i < len; i++)
            FUN_142585f70(&s, text[i] == ';' ? 0x5c : (int)text[i]);
        FUN_142624300(RawFieldPtr<U*>(self, 0xd8), &key, &s);
    }
}

// @0x142623b10
void FUN_142623b10(U* array, void* heapOwner, U n)
{
    if (array[2] <= n)
    {
        if (n == 0)
        {
            if (array[0])
            {
                Memory::Free((void*)array[0]);
                array[0] = 0;
                array[2] = 0;
                return;
            }
            array[2] = 0;
            return;
        }
        U cap = (n + 3) & ~3ULL;
        if (array[0])
        {
            array[0] = (U)Memory::Realloc((void*)array[0], cap * 0x18);
            array[2] = cap;
            return;
        }
        array[0] = (U)Memory::AllocAutoHeap(heapOwner, cap * 0x18, AllocInfo(0x245, 0, 0));
        array[2] = cap;
    }
}

// @0x142623bc0
void FUN_142623bc0(U* array, void* heapOwner, U n)
{
    if (n == 0)
    {
        if (array[0])
        {
            Memory::Free((void*)array[0]);
            array[0] = 0;
            array[2] = 0;
            return;
        }
        array[2] = 0;
        return;
    }
    U cap = ((U)n + 3) & ~3ULL;
    if (array[0])
    {
        array[0] = (U)Memory::Realloc((void*)array[0], cap << 5);
        array[2] = cap;
        return;
    }
    array[0] = (U)Memory::AllocAutoHeap(heapOwner, cap << 5, AllocInfo(2, 0, 0));
    array[2] = cap;
}

}} // namespace Scaleform::GFx
