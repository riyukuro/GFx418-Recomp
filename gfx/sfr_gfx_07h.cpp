// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP / IME support tables. The
// open-addressed hash sets (stride 0x20 / 0x28 / 0x30 entries: chain link, hash, payload) behind the ASIME manager
// map and the AMP server state, written as raw-layout free functions under the exe's own FUN_<va> names.
// Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14261e1c0-0x14261ff80 .text$mn
// MS2-RANGE: 0x14261ffe0-0x142620040 .text$mn
// MS2-PIN: ?FUN_14261f940@GFx@Scaleform@@YAXPEA_K@Z 0x14261f940
// MS2-PIN: ?FUN_14261f9e0@GFx@Scaleform@@YAXPEA_K@Z 0x14261f9e0
// MS2-PIN: ?FUN_14261fc40@GFx@Scaleform@@YA_KPEAXPEBE@Z 0x14261fc40
// MS2-PIN: ?FUN_14261fd80@GFx@Scaleform@@YA_KPEAXPEBE@Z 0x14261fd80
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#define MS2_RAW_INLINE __forceinline
#include "sfr_gfx_07raw.h"
#include "../include/kernel/sf_hash.h"

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

// Empty and constant virtuals of the AMP server classes (vftable slots of the exe's .rdata, data_rdata_sf_b).
// @0x14261e220
void FUN_14261e220(void*) {}
// @0x14261e230
void FUN_14261e230(void*) {}
// @0x14261e240
void FUN_14261e240(void*) {}
// @0x14261e250
void FUN_14261e250(void*) {}
// @0x14261e260
void FUN_14261e260(void*) {}
// @0x14261e270
void FUN_14261e270(void*) {}
// @0x14261e280
void FUN_14261e280(void*) {}
// @0x14261e290
void FUN_14261e290(void*) {}
// @0x14261e2a0
void FUN_14261e2a0(void*) {}
// @0x14261e2b0
void FUN_14261e2b0(void*) {}
// @0x14261e2c0
bool FUN_14261e2c0(void*) { return false; }
// @0x14261e2d0
U FUN_14261e2d0(void*) { return 0; }
// @0x14261e2e0
U FUN_14261e2e0(void*) { return 0; }
// @0x14261e2f0
U FUN_14261e2f0(void*) { return 0; }
// @0x14261e300
U FUN_14261e300(void*) { return 0; }

struct Sfr31StaticState
{
    void* VTable;
    // noinline: cl folds an inline store into a constant-initialised static, an ADDR64 to the exe's DAT_14318ee08 in
    // the hook DLL's .data (ms2symobj --check); the exe stores the vtable at run time too
    __declspec(noinline) Sfr31StaticState() { VTable = DAT_14318ee08; }
    ~Sfr31StaticState() { VTable = DAT_14318ec30; }
};

// The shared empty state, made on first use; returned (rax in the exe: the movie loader calls through it).
// MS2-FUNCTIONAL 0x14261e310: same lazy static init; cl duplicates the tail after _Init_thread_footer and the exe stores the vtable at run time (117 bytes against 148)
// @0x14261e310
void* FUN_14261e310()
{
    if (!DAT_143b16080)
    {
        static Sfr31StaticState state;
        DAT_143b16080 = &state;
    }
    return DAT_143b16080;
}

// @0x14261e3b0
U FUN_14261e3b0(void*) { return 0; }
// @0x14261e3c0
int FUN_14261e3c0(void*) { return -1; }

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

// @0x14261e430
bool FUN_14261e430(void*) { return false; }
// @0x14261e440
void FUN_14261e440(void*) {}
// @0x14261e450
void FUN_14261e450(void*) {}

// MS2-FUNCTIONAL 0x14261e460: same lazy static init; the tail after _Init_thread_footer differs as in 0x14261e310 (105 bytes against 122)
// @0x14261e460
void FUN_14261e460()
{
    static Sfr31StaticState state;
    DAT_143b16080 = &state;
}

// @0x14261e4e0
bool FUN_14261e4e0(void*) { return false; }
// @0x14261e4f0
bool FUN_14261e4f0(void*) { return false; }
// @0x14261e500
bool FUN_14261e500(void*) { return false; }
// @0x14261e510
bool FUN_14261e510(void*) { return false; }
// @0x14261e520
bool FUN_14261e520(void*) { return false; }
// @0x14261e530
bool FUN_14261e530(void*) { return false; }
// @0x14261e540
bool FUN_14261e540(void*) { return false; }
// @0x14261e550
bool FUN_14261e550(void*) { return false; }
// @0x14261e560
void FUN_14261e560(void*) {}
// @0x14261e570
void FUN_14261e570(void*) {}
// @0x14261e580
void FUN_14261e580(void*) {}
// @0x14261e590
void FUN_14261e590(void*) {}
// @0x14261e5a0
void FUN_14261e5a0(void*) {}
// @0x14261e5b0
void FUN_14261e5b0(void*) {}
// @0x14261e5c0
void FUN_14261e5c0(void*) {}
// @0x14261e5d0
void FUN_14261e5d0(void*) {}
// @0x14261e5e0
void FUN_14261e5e0(void*) {}
// @0x14261e5f0
void FUN_14261e5f0(void*) {}
// @0x14261e600
void FUN_14261e600(void*) {}
// @0x14261e610
void FUN_14261e610(void*) {}
// @0x14261e620
void FUN_14261e620(void*) {}
// @0x14261e630
void FUN_14261e630(void*) {}
// @0x14261e640
void FUN_14261e640(void*) {}
// @0x14261e650
void FUN_14261e650(void*) {}
// @0x14261e660
void FUN_14261e660(void*) {}
// @0x14261e670
void FUN_14261e670(void*) {}
// @0x14261e680
void FUN_14261e680(void*) {}
// @0x14261e690
void FUN_14261e690(void*) {}
// @0x14261e6a0
void FUN_14261e6a0(void*) {}
// Forwards to the virtual at slot 0xc8 with a zero argument.
// @0x14261e6b0
U FUN_14261e6b0(void** self)
{
    return reinterpret_cast<U (*)(void*, int)>((*reinterpret_cast<void***>(self))[0xc8 / 8])(self, 0);
}
// @0x14261e6c0
void FUN_14261e6c0(void*) {}
// @0x14261e6d0
void FUN_14261e6d0(void*) {}
// @0x14261e6e0
void FUN_14261e6e0(void*) {}
// @0x14261e6f0
void FUN_14261e6f0(void*) {}
// @0x14261e700
void FUN_14261e700(void*) {}
// @0x14261e720
void FUN_14261e720(void*) {}

// Walks a tree of nodes (children array at +0x30, count at +0x38), reporting each node's span.
// @0x14261e730
void FUN_14261e730(char* node, U* ctx)
{
    FUN_142624700(ctx[1], RawField<U>(node, 0x10), RawField<int>(node, 0x20) - RawField<int>(node, 0x18), 1, ctx[0]);
    for (U i = 0; i < RawField<U>(node, 0x38); i++)
        FUN_14261e730(*(char**)(RawField<char*>(node, 0x30) + i * 8), ctx);
}

// HashSetBase::add for the Movie* -> Ptr<ASIMEManager> sets, as the SDK writes it: the displaced natural entry
// is moved with the entry's copy constructor (FUN_14261f3e0 / FUN_14261f440), the new value assigned Ptr-style.
struct MovieEntry
{
    SPInt NextInChain;
    U HashValue;
    U Key;
    void* Value;
};

static __forceinline void MovieEntryAssign(MovieEntry* e, const U& key, void* const& value)
{
    e->Key = key;
    if (value)
        FUN_14257dc30(value);
    if (e->Value)
        FUN_14257dcb0(e->Value);
    e->Value = value;
}

char* FUN_14261f3e0(char* self, const char* src);
char* FUN_14261f440(char* self, const char* src);

template<void (*CheckExpand)(U**, void*), char* (*CopyEntry)(char*, const char*)>
static __forceinline void MovieHashAdd(U** self, void* heapAddr, const U& key, void* const& value, U hashValue)
{
    CheckExpand(self, heapAddr);
    hashValue &= (*self)[1];
    (*self)[0]++;
    SPInt index = (SPInt)hashValue;
    MovieEntry* natural = &((MovieEntry*)(*self + 2))[index];
    if (natural->NextInChain == -2)
    {
        natural->NextInChain = -1;
        natural->Key = key;
        if (value)
            FUN_14257dc30(value);
        natural->Value = value;
    }
    else
    {
        SPInt blankIndex = index;
        do
            blankIndex = (blankIndex + 1) & (*self)[1];
        while (((MovieEntry*)(*self + 2))[blankIndex].NextInChain != -2);
        MovieEntry* blank = &((MovieEntry*)(*self + 2))[blankIndex];
        if (natural->HashValue == (U)index)
        {
            CopyEntry((char*)blank, (const char*)natural);
            MovieEntryAssign(natural, key, value);
            natural->NextInChain = blankIndex;
        }
        else
        {
            SPInt collidedIndex = (SPInt)natural->HashValue;
            for (;;)
            {
                MovieEntry* e = &((MovieEntry*)(*self + 2))[collidedIndex];
                if (e->NextInChain == index)
                {
                    CopyEntry((char*)blank, (const char*)natural);
                    e->NextInChain = blankIndex;
                    break;
                }
                collidedIndex = e->NextInChain;
            }
            MovieEntryAssign(natural, key, value);
            natural->NextInChain = -1;
        }
    }
    natural->HashValue = hashValue;
}

// MS2-FUNCTIONAL 0x14261e7a0: same SDK HashSet add; register allocation and the merged final Value store differ (408 bytes against 413)
// @0x14261e7a0
void FUN_14261e7a0(U** self, void* ctx, const char* node, U hash)
{
    MovieHashAdd<FUN_1426206a0, FUN_14261f3e0>(self, ctx, *(const U*)node, *(void* const*)(node + 8), hash);
}

// MS2-FUNCTIONAL 0x14261e940: same SDK HashSet add as 0x14261e7a0 (408 bytes against 413)
// @0x14261e940
void FUN_14261e940(U** self, void* ctx, const char* node, U hash)
{
    MovieHashAdd<FUN_1426206f0, FUN_14261f440>(self, ctx, *(const U*)node, *(void* const*)(node + 8), hash);
}

// HashNode<two-word key, U>: a 0x28 entry whose key copies as one 16-byte block.
struct WordsKey { U W[2]; };
struct WordsEntry
{
    SPInt NextInChain;
    U HashValue;
    WordsKey Key;
    U Value;

    WordsEntry(const WordsRefOps::Ref& r, SPInt next)
        : NextInChain(next), Key(*(const WordsKey*)r.Key), Value(*r.Value) {}
};

static __forceinline void WordsEntryCopy(WordsEntry* d, const WordsEntry* s)
{
    d->NextInChain = s->NextInChain;
    d->HashValue = s->HashValue;
    d->Key = s->Key;
    d->Value = s->Value;
}

// MS2-FUNCTIONAL 0x14261eae0: same SDK HashSet add; cl merges the Value store of the empty-slot and moved-entry paths, the exe does not (33 bytes differ)
// @0x14261eae0
void FUN_14261eae0(U** self, void* ctx, WordsRefOps::Ref* ref, U hashValue)
{
    RawCheckExpand<FUN_142624840>(self, ctx);
    hashValue &= (*self)[1];
    (*self)[0]++;
    SPInt index = (SPInt)hashValue;
    WordsEntry* natural = &((WordsEntry*)(*self + 2))[index];
    if (natural->NextInChain == -2)
    {
        ::new (natural) WordsEntry(*ref, -1);
    }
    else
    {
        SPInt blankIndex = index;
        do
            blankIndex = (blankIndex + 1) & (*self)[1];
        while (((WordsEntry*)(*self + 2))[blankIndex].NextInChain != -2);
        WordsEntry* blank = &((WordsEntry*)(*self + 2))[blankIndex];
        if (natural->HashValue == (U)index)
        {
            WordsEntryCopy(blank, natural);
            natural->Key = *(const WordsKey*)ref->Key;
            natural->Value = *ref->Value;
            natural->NextInChain = blankIndex;
        }
        else
        {
            SPInt collidedIndex = (SPInt)natural->HashValue;
            for (;;)
            {
                WordsEntry* e = &((WordsEntry*)(*self + 2))[collidedIndex];
                if (e->NextInChain == index)
                {
                    WordsEntryCopy(blank, natural);
                    e->NextInChain = blankIndex;
                    break;
                }
                collidedIndex = e->NextInChain;
            }
            natural->Key = *(const WordsKey*)ref->Key;
            natural->Value = *ref->Value;
            natural->NextInChain = -1;
        }
    }
    natural->HashValue = hashValue;
}

// MS2-FUNCTIONAL 0x14261ec70: same SDK HashSet add; register allocation and tail merging differ (472 bytes against 497)
// @0x14261ec70
void FUN_14261ec70(U** self, void* ctx, NodeRef* ref, U hash)
{
    MovieHashAdd<RawCheckExpand<FUN_142624d70>, FUN_14261f3e0>(self, ctx, *ref->Key, *ref->Value, hash);
}

// MS2-FUNCTIONAL 0x14261ee70: same SDK HashSet add as 0x14261ec70 (472 bytes against 497)
// @0x14261ee70
void FUN_14261ee70(U** self, void* ctx, NodeRef* ref, U hash)
{
    MovieHashAdd<RawCheckExpand<FUN_142624f80>, FUN_14261f440>(self, ctx, *ref->Key, *ref->Value, hash);
}

// MS2-FUNCTIONAL 0x14261f070: same raw-layout HashSet add; scheduling differs (439 bytes against 418)
// @0x14261f070
void FUN_14261f070(U** self, void* ctx, KeyStringOps::Ref* ref, U hash)
{
    RawCheckExpand<FUN_1426251d0>(self, ctx);
    RawHashAdd<0x20, KeyStringOps>(self, *ref, hash);
}

// MS2-FUNCTIONAL 0x14261f220: same raw-layout HashSet add; scheduling differs (419 bytes against 440)
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
    U* d = (U*)self;
    const U* s = (const U*)src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    if (s[3])
        FUN_14257dc30((void*)s[3]);
    d[3] = s[3];
    return self;
}

// @0x14261f440
char* FUN_14261f440(char* self, const char* src)
{
    U* d = (U*)self;
    const U* s = (const U*)src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    if (s[3])
        FUN_14257dc30((void*)s[3]);
    d[3] = s[3];
    return self;
}

// An array of counted pointers (stride 0x18, pointer at +0): release each from the back, free the block.
// @0x14261f7b0
__declspec(noinline) void FUN_14261f7b0(U* array)
{
    U count = array[1];
    char* e = (char*)array[0] + (count - 1) * 0x18;
    for (U i = 0; i < count; i++, e -= 0x18)
    {
        void* p = *(void**)e;
        if (p)
            FUN_14257dcb0(p);
    }
    Memory::Free((void*)array[0]);
}

// @0x14261f820
__declspec(noinline) void FUN_14261f820(U* self) { RawClearPtrSet(self); }

// @0x14261f8b0
__declspec(noinline) void FUN_14261f8b0(U* self) { RawClearPtrSet(self); }

// The SDK HashSetBase::Clear over a cached entry of HashNode<8-byte key, String>; the exe's [table + offset]
// operand order comes from this shape (the flat RawClearStringSet gives [offset + table]).
struct Unk_StringNode24 { U First; String Second; };
struct Unk_StringEntry24
{
    SPInt NextInChain;
    U HashValue;
    Unk_StringNode24 Value;
    bool IsEmpty() const { return NextInChain == -2; }
    void Free() { Value.~Unk_StringNode24(); NextInChain = -2; }
};
struct Unk_StringTable24 { U EntryCount; U SizeMask; };

// @0x14261f940
__declspec(noinline) void FUN_14261f940(U* self)
{
    Unk_StringTable24*& pTable = *(Unk_StringTable24**)self;
    if (pTable)
    {
        U i, n = pTable->SizeMask;
        for (i = 0; i <= n; i++)
        {
            Unk_StringEntry24* e = &((Unk_StringEntry24*)(pTable + 1))[i];
            if (!e->IsEmpty())
                e->Free();
        }
        Memory::Free(pTable);
        pTable = 0;
    }
}

// @0x14261f9e0
__declspec(noinline) void FUN_14261f9e0(U* self) { RawClearStringSet(self, 0x10); }

// FixedSizeHash of an AbcMultinameHash key: sdbm over its sixteen bytes.
static __forceinline U RawMultinameKeyHash(const unsigned char* k)
{
    return FixedSizeHash<UByte[16]>::SDBM_Hash(k, 16);
}

// @0x14261fc40
U FUN_14261fc40(void*, const unsigned char* key) { return RawMultinameKeyHash(key); }

// @0x14261fd80
U FUN_14261fd80(void*, const unsigned char* key) { return RawMultinameKeyHash(key); }

// Scalar deleting destructors of 0x10-byte ref-counted bases.
static __forceinline void* RawDeletingDtor(void* self, unsigned flags)
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
void* FUN_14261fec0(void* self, unsigned flags) { return RawDeletingDtor(self, flags); }

// @0x14261ff20
void* FUN_14261ff20(void* self, unsigned flags) { return RawDeletingDtor(self, flags); }

// @0x14261ffe0
void* FUN_14261ffe0(void* self, unsigned flags) { return RawDeletingDtor(self, flags); }

// The AMP server state: counters, locks, the message-type / resource tables, and the default "Object Interface"
// message type (id 0xe) registered in both the id table and the name table.
// MS2-FUNCTIONAL 0x14261f4a0: same AMP state ctor field stores; scheduling differs (765 bytes against 782)
// @0x14261f4a0
void* FUN_14261f4a0(char* self)
{
    *(void**)self = DAT_14318f068;
    *(int*)(self + 8) = 1;
    RawField<U>(self, 0x10) = 0;
    RawField<U>(self, 0x18) = 0;
    RawField<U>(self, 0x20) = 0;
    RawField<int>(self, 0x28) = 0x38;
    for (int i = 0x30; i <= 0x58; i += 8)
        *(U*)(self + i) = 0;
    RawField<int>(self, 0x60) = 0;
    RawField<int>(self, 0x64) = -1;
    RawField<U>(self, 0x68) = 0;
    RawField<int>(self, 0x70) = 0;
    FUN_14258d030(self + 0x78, 0);
    RawField<U>(self, 0xa0) = 0;
    FUN_14258a350(self + 0xa8, true, false);
    RawField<U>(self, 0xd0) = 0;
    RawField<U>(self, 0xd8) = 0;
    FUN_14258d030(self + 0xe0, 0);
    RawField<int>(self, 0x108) = 0;
    new (self + 0x110) StringLH();
    RawField<U>(self, 0x118) = 0;
    RawField<U>(self, 0x120) = 0;
    RawField<U>(self, 0x128) = 0;
    FUN_1425e4f80(self + 0x130);
    RawField<int>(self, 0x158) = 0;
    RawField<U>(self, 0x160) = 0;
    RawField<U>(self, 0x168) = 0;
    RawField<U>(self, 0x170) = 0;
    FUN_142582300(self + 0x178, false, false);
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    RawField<int>(self, 0x108) = DAT_143a2f428;
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
        RawField<String>(type, 0x10) = "Object Interface";
        RawField<int>(type, 0x18) = 0;
        RawField<U>(type, 0x28) = 0;
        RawField<U>(type, 0x20) = 0;
        void* ref = type;
        FUN_142624190(self + 0x18, &key, &ref);
        if (ref)
            FUN_14257dcb0(ref);
    }
    UInt32 id = 0xe;
    String name("Object Interface");
    StringKeyOps::Ref ref = { &name, &id };
    FUN_14261f220(RawFieldPtr<U*>(self, 0x20), self + 0x20, &ref,
                  String::BernsteinHashFunctionCIS(name.ToCStr(), name.GetSize(), 0x1505));
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    return self;
}

// The AMP server state's destructor body.
// MS2-FUNCTIONAL 0x14261fa90: same dtor; base and index operand order in the inlined plain-set clear differs (4 bytes)
// @0x14261fa90
void FUN_14261fa90(char* self)
{
    FUN_142582530(self + 0x178);
    FUN_14261f9e0(RawFieldPtr<U>(self, 0x168));
    (RawFieldPtr<String>(self, 0x110))->~String();
    FUN_14258d0b0(self + 0xe0);
    FUN_14261f940(RawFieldPtr<U>(self, 0xd8));
    RawClearPlainSet(RawFieldPtr<U>(self, 0xd0), 0x28);
    FUN_14258a720(self + 0xa8);
    FUN_14261f820(RawFieldPtr<U>(self, 0xa0));
    FUN_14258d0b0(self + 0x78);
    U count = RawField<U>(self, 0x50);
    void** e = RawField<void**>(self, 0x48) + (count - 1);
    for (U i = 0; i < count; i++, e--)
    {
        if (*e)
            FUN_14257dcb0(*e);
    }
    Memory::Free(RawField<void*>(self, 0x48));
    FUN_14261f7b0(RawFieldPtr<U>(self, 0x30));
    FUN_14261f9e0(RawFieldPtr<U>(self, 0x20));
    FUN_14261f8b0(RawFieldPtr<U>(self, 0x18));
    RawClearPlainSet(RawFieldPtr<U>(self, 0x10), 0x30);
    *(void**)self = DAT_14318efe8;
    FUN_14257db40(self);
}

}} // namespace Scaleform::GFx
