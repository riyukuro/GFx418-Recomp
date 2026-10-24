// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP server support (third part):
// the Array<Ptr>/Array<record> resizes, the Hash Set instances, the scope field setters and the hash set Grow
// (resize) instances of the AMP server state tables. Raw-layout free functions under the exe's own FUN_<va> names.
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142624020-0x142625920 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.
// MS2-FUNCTIONAL 0x142624020: same Array resize (release the dropped counted pointers, shrink/grow the buffer, store the size); register allocation and frame differ
// MS2-FUNCTIONAL 0x1426240f0: same Array resize (release the dropped counted pointers, shrink/grow the buffer, store the size); register allocation and frame differ
// MS2-FUNCTIONAL 0x142624840: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624af0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624d70: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624f80: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x1426251d0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x1426255e0: same rehash (new table of -2 entries, re-add of every live entry with its hash, old entry dtor + free); the exe and ours inline different helpers (RawNewTable / RawHashAdd / clear), so frames differ
// MS2-FUNCTIONAL 0x142624190: same Set (find, assign or add) of a raw hash instance; helper inlining differs, so the frame differs
// MS2-FUNCTIONAL 0x142624300: same Set (find, assign or add) of a raw hash instance; helper inlining differs, so the frame differs

#include "sfr_gfx_07raw.h"

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

// Array of 0x18-byte records whose first word is a counted pointer.
// @0x142624020
void FUN_142624020(U* array, void* owner, U n)
{
    U size = array[1];
    if (n < size)
    {
        void** p = (void**)((char*)array[0] + (size * 3 - 3) * 8);
        for (U k = size - n; k != 0; k--)
        {
            if (*p)
                FUN_14257dcb0(*p);
            p -= 3;
        }
        if (n < (array[2] >> 1))
            FUN_142623b10(array, owner, n);
        array[1] = n;
        return;
    }
    if (n < array[2])
    {
        array[1] = n;
        return;
    }
    FUN_142623b10(array, owner, (n >> 2) + n);
    array[1] = n;
}

// Array of counted pointers.
// @0x1426240f0
void FUN_1426240f0(U* array, void* owner, U n)
{
    U size = array[1];
    U want;
    if (n < size)
    {
        void** p = (void**)array[0] + (size - 1);
        for (U k = size - n; k != 0; k--)
        {
            if (*p)
                FUN_14257dcb0(*p);
            p--;
        }
        want = n;
        if ((array[2] >> 1) <= n)
        {
            array[1] = n;
            return;
        }
    }
    else
    {
        if (n < array[2])
        {
            array[1] = n;
            return;
        }
        want = (n >> 2) + n;
    }
    FUN_142623ee0(array, owner, want);
    array[1] = n;
}

// @0x142624190
void FUN_142624190(U** self, const U* key, void* const* value)
{
    U hash = RawKey8Hash(*key);
    NodeRef ref = { key, value };
    SPInt idx = RawFindKey8(*self, *key, 0x20);
    if (idx >= 0)
    {
        char* e = RawEntry(*self, (U)idx, 0x20);
        RawField<U>(e, 0x10) = *key;
        if (*value)
            FUN_14257dc30(*value);
        if (RawField<void*>(e, 0x18))
            FUN_14257dcb0(RawField<void*>(e, 0x18));
        RawField<void*>(e, 0x18) = *value;
        return;
    }
    FUN_14261ee70(self, self, &ref, hash);
}

// @0x142624300
void FUN_142624300(U** self, const U* key, const String* value)
{
    U hash = RawKey8Hash(*key);
    KeyStringOps::Ref ref = { key, value };
    SPInt idx = RawFindKey8(*self, *key, 0x20);
    if (idx >= 0)
    {
        char* e = RawEntry(*self, (U)idx, 0x20);
        RawField<U>(e, 0x10) = *key;
        RawField<String>(e, 0x18) = *value;
        return;
    }
    FUN_14261f070(self, self, &ref, hash);
}

// Mirrors the top scope's (record, count) pair into the locked statistics fields.
static inline void RawPublishTop(char* self)
{
    if (RawField<U>(self, 0x38) == 0)
        return;
    char* slot = (char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18;
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
    RawField<U>(self, 0x68) = *(U*)(slot - 0x10);
    RawField<int>(self, 0x70) = *(int*)(slot - 8);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
}

// @0x142624450
void FUN_142624450(char* self, U v)
{
    if (RawField<U>(self, 0x38) != 0)
    {
        *(U*)((char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18 - 0x10) = v;
        RawPublishTop(self);
    }
    else
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
        RawField<U>(self, 0x68) = v;
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
    }
}

// @0x1426244e0
void FUN_1426244e0(char* self, int v)
{
    if (RawField<U>(self, 0x38) != 0)
    {
        *(int*)((char*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) * 0x18 - 8) = v;
        RawPublishTop(self);
    }
    else
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
        RawField<int>(self, 0x70) = v;
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
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

// Stores the movie path, reduced to the part after the last path separator.
// @0x142624660
void FUN_142624660(char* self, const char* path)
{
    String* s = RawFieldPtr<String>(self, 0x110);
    *s = path;
    UPInt len = s->GetLength();
    for (UPInt k = 0; k < len; k++)
    {
        char c = s->ToCStr()[len - k - 1];
        if (c == '/' || c == '\\')
        {
            *s = s->Substring(len - k, len);
            return;
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
