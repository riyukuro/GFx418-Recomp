// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP / IME support tables. The
// open-addressed hash sets (stride 0x20 / 0x28 / 0x30 entries: chain link, hash, payload) behind the ASIME manager
// map and the AMP server state, written as raw-layout free functions under the exe's own FUN_<va> names.
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14261e1c0-0x14261ff80 .text$mn
// MS2-RANGE: 0x14261ffe0-0x142620040 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#include "sfr_gfx_07raw.h"

#include <new>
#include <string.h>
#include <windows.h>

namespace Scaleform { namespace GFx {

extern char DAT_14318ec30[];
extern char DAT_14318ee08[];
extern void* DAT_143b16080;
extern char DAT_14318f068[];
extern char DAT_14318f030[];
extern char DAT_14318efe8[];
extern int DAT_143a2f428;

void FUN_14257db40(void*);
void FUN_14015b310(void*, UPInt);
void FUN_142624700(U, U, int, int, U);
void FUN_142624840(U**, void*, U);
void FUN_142624d70(U**, void*, U);
void FUN_142624f80(U**, void*, U);
void FUN_1426251d0(U**, void*, U);
void FUN_1426255e0(U**, void*, U);
void FUN_14258d030(void*, unsigned);              // Lock::Lock(spinCount)
void FUN_14258d0b0(void*);                        // Lock::~Lock
void FUN_14258a350(void*, bool, bool);            // Mutex::Mutex(recursive, lockNow)
void FUN_14258a720(void*);                        // Mutex::~Mutex
void FUN_1425e4f80(void*);                        // Alg::Random::Generator::Generator
void FUN_142582300(void*, bool, bool);            // Event::Event(manualReset, initialState)
void FUN_142582530(void*);                        // Event::~Event
void FUN_1425842b0(void*);                        // Event::SetEvent
void FUN_142622160(void*, U*, const U*);          // Hash::Find(iterator out, key)
void FUN_142624190(void*, const U*, void*);       // Hash::Set(key, Ptr)
void FUN_1426206a0(U**, void*);
void FUN_1426206f0(U**, void*);

// @0x14261e1c0
void* FUN_14261e1c0(void* self, unsigned long long flags)
{
    *(void**)self = DAT_14318ec30;
    if (flags & 1)
        ::operator delete(self, 8);
    return self;
}

// @0x14261e1f0
void* FUN_14261e1f0(void* self, unsigned long long flags)
{
    *(void**)self = DAT_14318ec30;
    if (flags & 1)
        ::operator delete(self, 8);
    return self;
}

struct Sfr31StaticState
{
    void* VTable;
    Sfr31StaticState() { VTable = DAT_14318ee08; }
    ~Sfr31StaticState() { VTable = DAT_14318ec30; }
};

// The shared empty state, made on first use.
// @0x14261e310
void FUN_14261e310()
{
    if (!DAT_143b16080)
    {
        static Sfr31StaticState state;
        DAT_143b16080 = &state;
    }
}

// @0x14261e3d0
String* FUN_14261e3d0(void*, String* result)
{
    new (result) String("");
    return result;
}

// @0x14261e400
String* FUN_14261e400(void*, String* result)
{
    new (result) String("");
    return result;
}

// @0x14261e460
void FUN_14261e460()
{
    static Sfr31StaticState state;
    DAT_143b16080 = &state;
}

// Walks a tree of nodes (children array at +0x30, count at +0x38), reporting each node's span.
// @0x14261e730
void FUN_14261e730(char* node, U* ctx)
{
    FUN_142624700(ctx[1], *(U*)(node + 0x10), *(int*)(node + 0x20) - *(int*)(node + 0x18), 1, ctx[0]);
    for (U i = 0; i < *(U*)(node + 0x38); i++)
        FUN_14261e730(*(char**)(*(char**)(node + 0x30) + i * 8), ctx);
}

// @0x14261e7a0
void FUN_14261e7a0(U** self, void* ctx, const char* node, U hash)
{
    FUN_1426206a0(self, ctx);
    RawHashAdd<0x20, MoviePtrOps>(self, node, hash);
}

// @0x14261e940
void FUN_14261e940(U** self, void* ctx, const char* node, U hash)
{
    FUN_1426206f0(self, ctx);
    RawHashAdd<0x20, MoviePtrOps>(self, node, hash);
}

// @0x14261eae0
void FUN_14261eae0(U** self, void* ctx, WordsRefOps::Ref* ref, U hash)
{
    RawCheckExpand<FUN_142624840>(self, ctx);
    RawHashAdd<0x28, WordsRefOps>(self, *ref, hash);
}

// @0x14261ec70
void FUN_14261ec70(U** self, void* ctx, NodeRef* ref, U hash)
{
    RawCheckExpand<FUN_142624d70>(self, ctx);
    RawHashAdd<0x20, MoviePtrRefOps>(self, *ref, hash);
}

// @0x14261ee70
void FUN_14261ee70(U** self, void* ctx, NodeRef* ref, U hash)
{
    RawCheckExpand<FUN_142624f80>(self, ctx);
    RawHashAdd<0x20, MoviePtrRefOps>(self, *ref, hash);
}

// @0x14261f070
void FUN_14261f070(U** self, void* ctx, KeyStringOps::Ref* ref, U hash)
{
    RawCheckExpand<FUN_1426251d0>(self, ctx);
    RawHashAdd<0x20, KeyStringOps>(self, *ref, hash);
}

// @0x14261f220
void FUN_14261f220(U** self, void* ctx, StringKeyOps::Ref* ref, U hash)
{
    RawCheckExpand<FUN_1426255e0>(self, ctx);
    RawHashAdd<0x20, StringKeyOps>(self, *ref, hash);
}

// A hash entry's copy constructor (link, hash, key and a counted pointer).
// @0x14261f3e0
char* FUN_14261f3e0(char* self, const char* src)
{
    MoviePtrOps::Copy(self + 0x10, src + 0x10);
    *(U*)self = *(const U*)src;
    *(U*)(self + 8) = *(const U*)(src + 8);
    return self;
}

// @0x14261f440
char* FUN_14261f440(char* self, const char* src)
{
    MoviePtrOps::Copy(self + 0x10, src + 0x10);
    *(U*)self = *(const U*)src;
    *(U*)(self + 8) = *(const U*)(src + 8);
    return self;
}

// An array of counted pointers (stride 0x18, pointer at +0): release each from the back, free the block.
// @0x14261f7b0
void FUN_14261f7b0(U* array)
{
    U count = array[1];
    char* data = (char*)array[0];
    for (U i = count; i; i--)
    {
        void* p = *(void**)(data + (i - 1) * 0x18);
        if (p)
            FUN_14257dcb0(p);
    }
    Memory::Free(data);
}

// Frees a set whose payload at +0x18 of each live entry is a counted pointer.
static inline void RawClearPtrSet(U* self)
{
    if (!*self)
        return;
    U* table = (U*)*self;
    for (U i = 0; i < table[1] + 1; i++)
    {
        char* e = RawEntry(table, i, 0x20);
        if (*(SPInt*)e != -2)
        {
            void* p = *(void**)(e + 0x18);
            if (p)
                FUN_14257dcb0(p);
            *(SPInt*)e = -2;
        }
    }
    Memory::Free(table);
    *self = 0;
}

// @0x14261f820
void FUN_14261f820(U* self) { RawClearPtrSet(self); }

// @0x14261f8b0
void FUN_14261f8b0(U* self) { RawClearPtrSet(self); }

// Frees a set whose payload at +0x18 (or +0x10) of each live entry is a String.
static inline void RawClearStringSet(U* self, U payload)
{
    if (!*self)
        return;
    U* table = (U*)*self;
    for (U i = 0; i < table[1] + 1; i++)
    {
        char* e = RawEntry(table, i, 0x20);
        if (*(SPInt*)e != -2)
        {
            ((String*)(e + payload))->~String();
            *(SPInt*)e = -2;
        }
    }
    Memory::Free(table);
    *self = 0;
}

// @0x14261f940
void FUN_14261f940(U* self) { RawClearStringSet(self, 0x18); }

// @0x14261f9e0
void FUN_14261f9e0(U* self) { RawClearStringSet(self, 0x10); }

// FixedSizeHash of an AbcMultinameHash key (sixteen bytes mixed with per-position multipliers).
static inline U RawMultinameKeyHash(const unsigned char* k)
{
    return (((U)k[3] * 0x1003f + (U)k[2]) * 0x1003f + (U)k[1]) * 0x1003f + (U)k[10] * (U)-0xd284be79967327fLL +
           (U)k[0xd] * (U)-0x5b36ed498d7fdcc1LL + (U)k[9] * 0x5950f7eab156c23fULL +
           (U)k[0xe] * (U)-0x5fcdf299af38537fLL + (U)k[0xb] * 0x772db89a0d1b92bfULL + (U)k[4] * 0xfc5d1543ec5f01ULL +
           (U)k[5] * (U)-0x64cfd3d7e9d39ec1LL + (U)k[0xc] * 0xcda7b04cc881d01ULL +
           (U)k[7] * (U)-0x283c1b695cee4e41LL + (U)k[0xf] * 0x79b79cf58da473bfULL +
           (U)k[6] * 0x5d02f409d62aee81ULL + (U)k[8] * (U)-0x2341bdc2ce641ffLL + (U)-0x1d7e9924e6be7efbLL + (U)k[0];
}

// @0x14261fc40
U FUN_14261fc40(void*, const unsigned char* key) { return RawMultinameKeyHash(key); }

// @0x14261fd80
U FUN_14261fd80(void*, const unsigned char* key) { return RawMultinameKeyHash(key); }

// Scalar deleting destructors of 0x10-byte ref-counted bases.
static inline void* RawDeletingDtor(void* self, unsigned long long flags)
{
    FUN_14257db40(self);
    if (flags & 1)
    {
        if (!(flags & 4))
        {
            Memory::Free(self);
            return self;
        }
        FUN_14015b310(self, 0x10);
    }
    return self;
}

// @0x14261fec0
void* FUN_14261fec0(void* self, unsigned long long flags) { return RawDeletingDtor(self, flags); }

// @0x14261ff20
void* FUN_14261ff20(void* self, unsigned long long flags) { return RawDeletingDtor(self, flags); }

// @0x14261ffe0
void* FUN_14261ffe0(void* self, unsigned long long flags) { return RawDeletingDtor(self, flags); }

// The AMP server state: counters, locks, the message-type / resource tables, and the default "Object Interface"
// message type (id 0xe) registered in both the id table and the name table.
// @0x14261f4a0
void* FUN_14261f4a0(char* self)
{
    *(void**)self = DAT_14318f068;
    *(int*)(self + 8) = 1;
    *(U*)(self + 0x10) = 0;
    *(U*)(self + 0x18) = 0;
    *(U*)(self + 0x20) = 0;
    *(int*)(self + 0x28) = 0x38;
    for (int i = 0x30; i <= 0x58; i += 8)
        *(U*)(self + i) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = -1;
    *(U*)(self + 0x68) = 0;
    *(int*)(self + 0x70) = 0;
    FUN_14258d030(self + 0x78, 0);
    *(U*)(self + 0xa0) = 0;
    FUN_14258a350(self + 0xa8, true, false);
    *(U*)(self + 0xd0) = 0;
    *(U*)(self + 0xd8) = 0;
    FUN_14258d030(self + 0xe0, 0);
    *(int*)(self + 0x108) = 0;
    new (self + 0x110) StringLH();
    *(U*)(self + 0x118) = 0;
    *(U*)(self + 0x120) = 0;
    *(U*)(self + 0x128) = 0;
    FUN_1425e4f80(self + 0x130);
    *(int*)(self + 0x158) = 0;
    *(U*)(self + 0x160) = 0;
    *(U*)(self + 0x168) = 0;
    *(U*)(self + 0x170) = 0;
    FUN_142582300(self + 0x178, false, false);
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    *(int*)(self + 0x108) = DAT_143a2f428;
    DAT_143a2f428 = DAT_143a2f428 + 1;
    FUN_1425842b0(self + 0x178);

    U key = 0x10000000eULL;
    U found[2];
    FUN_142622160(self + 0x18, found, &key);
    U* hash = (U*)found[0];
    if (hash && *(U**)hash && (*(U**)hash)[1] >= found[1])
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x78));
    }
    else
    {
        char* type = (char*)Memory::AllocAutoHeap(self, 0x30, AllocInfo(0x242, 0, 0));
        if (type)
        {
            memset(type + 8, 0, 0x28);
            *(void**)type = DAT_14318f030;
            *(int*)(type + 8) = 1;
            new (type + 0x10) StringLH();
        }
        *(String*)(type + 0x10) = "Object Interface";
        *(int*)(type + 0x18) = 0;
        *(U*)(type + 0x28) = 0;
        *(U*)(type + 0x20) = 0;
        void* ref = type;
        FUN_142624190(self + 0x18, &key, &ref);
        if (ref)
            FUN_14257dcb0(ref);
    }
    UInt32 id = 0xe;
    String name("Object Interface");
    StringKeyOps::Ref ref = { &name, &id };
    FUN_14261f220((U**)(self + 0x20), self + 0x20, &ref,
                  String::BernsteinHashFunctionCIS(name.ToCStr(), name.GetSize(), 0x1505));
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    return self;
}

// Frees a stride-0x28 / 0x30 set whose entries own nothing.
static inline void RawClearPlainSet(U* self, U stride)
{
    if (!*self)
        return;
    U* table = (U*)*self;
    for (U i = 0; i < table[1] + 1; i++)
    {
        char* e = RawEntry(table, i, stride);
        if (*(SPInt*)e != -2)
            *(SPInt*)e = -2;
    }
    Memory::Free(table);
    *self = 0;
}

// The AMP server state's destructor body.
// @0x14261fa90
void FUN_14261fa90(char* self)
{
    FUN_142582530(self + 0x178);
    FUN_14261f9e0((U*)(self + 0x168));
    ((String*)(self + 0x110))->~String();
    FUN_14258d0b0(self + 0xe0);
    FUN_14261f940((U*)(self + 0xd8));
    RawClearPlainSet((U*)(self + 0xd0), 0x28);
    FUN_14258a720(self + 0xa8);
    FUN_14261f820((U*)(self + 0xa0));
    FUN_14258d0b0(self + 0x78);
    U count = *(U*)(self + 0x50);
    char* data = *(char**)(self + 0x48);
    for (U i = count; i; i--)
    {
        void* p = *(void**)(data + (i - 1) * 8);
        if (p)
            FUN_14257dcb0(p);
    }
    Memory::Free(data);
    FUN_14261f7b0((U*)(self + 0x30));
    FUN_14261f9e0((U*)(self + 0x20));
    FUN_14261f8b0((U*)(self + 0x18));
    RawClearPlainSet((U*)(self + 0x10), 0x30);
    *(void**)self = DAT_14318efe8;
    FUN_14257db40(self);
}

}} // namespace Scaleform::GFx
