// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 hash-set COMDATs folded into the
// video sound block: RemoveAlt of an eight-byte-keyed set whose values are pointer arrays, and three add() instances
// (array values from a node, plain {word, word, int} values and array values from a node reference). Raw-layout free
// functions under the exe's own FUN_<va> names. Our own source, written from the exe.
// Sub-unit of queue unit sfr_d3d9_01.
// MS2-UNIT: sfr_d3d9_01g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142742830-0x142742ed0 .text$mn

#define MS2_RAW_INLINE __forceinline
#include "../gfx/sfr_gfx_07raw.h"

void* FUN_142742ed0(void*, const Scaleform::UPInt*);                       // ArrayBase<ArrayData<VideoPlayerImpl*>> copy ctor (sfr_video_03)
Scaleform::UPInt* FUN_142742f70(Scaleform::UPInt*, const Scaleform::UPInt*); // set entry copy (link, hash, key, array) (sfr_video_03)

namespace Scaleform { void CheckExpandAS3CachedSet(void** set, void* owner); }   // CheckExpand of the array-valued set (sfr_as3_22)

namespace Scaleform { namespace GFx {

U* FUN_142743900(U* self, const U* source);                 // ArrayBase<ArrayData<VideoPlayerImpl*>>::operator= (sfr_kernel_03o)
extern "C" void FUN_142747530(U**, void*, U);               // setRawCapacity of the {word, word, int} set
extern "C" void FUN_1427478c0(U**, void*, U);               // setRawCapacity of the array-valued set

// RawKey8Hash read byte by byte from the key in memory.
static __forceinline U RawKey8HashAt(const void* p)
{
    const unsigned char* k = (const unsigned char*)p;
    U                    n = 8;
    U                    h = 5381;
    while (n > 0)
    {
        n--;
        h = (h << 16) + (h << 6) - h + (U)k[n];
    }
    return h;
}

// HashSetBase<HashNode<Class*, ...>>::RemoveAlt (0x30-byte entries; the value's array buffer is at entry +0x18).
// @0x142742830
void FUN_142742830(U** self, const U* key)
{
    if (!*self)
        return;
    U hash = RawKey8HashAt(key);
    U* table = *self;
    U index = hash & table[1];
    char* e = RawEntry(table, index, 0x30);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != index)
        return;
    U home = index;
    U prev = (U)-1;
    while (RawField<U>(e, 8) != home || RawField<U>(e, 0x10) != *key)
    {
        prev = index;
        index = *(U*)e;
        if ((SPInt)index == -1)
            return;
        e = RawEntry(table, index, 0x30);
    }
    U next = *(U*)e;
    if (home == index)
    {
        if ((SPInt)next != -1)
        {
            char* n = RawEntry(table, next, 0x30);
            if (RawField<void*>(e, 0x18))
                Memory::Free(RawField<void*>(e, 0x18));
            *(SPInt*)e = -2;
            FUN_142742f70((U*)e, (const U*)n);
            e = n;
        }
    }
    else
        *(U*)RawEntry(table, prev, 0x30) = next;
    if (RawField<void*>(e, 0x18))
        Memory::Free(RawField<void*>(e, 0x18));
    *(SPInt*)e = -2;
    --**self;
}

// Payload {U key, Array} built from a node {key, Array}.
struct KeyArrayOps
{
    static void Copy(char* d, const char* s)
    {
        *(U*)d = *(const U*)s;
        FUN_142742ed0(d + 8, (const U*)(s + 8));
    }
    static void Construct(char* d, const U* node)
    {
        *(U*)d = node[0];
        FUN_142742ed0(d + 8, node + 1);
    }
    static void Assign(char* d, const U* node)
    {
        *(U*)d = node[0];
        FUN_142743900((U*)(d + 8), node + 1);
    }
};

// Payload {U key, Array} built from a node reference {&key, &Array}.
struct KeyArrayRefOps
{
    static void Copy(char* d, const char* s) { KeyArrayOps::Copy(d, s); }
    static void Construct(char* d, const NodeRef& r)
    {
        *(U*)d = *r.Key;
        FUN_142742ed0(d + 8, (const U*)r.Value);
    }
    static void Assign(char* d, const NodeRef& r)
    {
        *(U*)d = *r.Key;
        FUN_142743900((U*)(d + 8), (const U*)r.Value);
    }
};

// Payload {U key, twelve bytes} built from a node reference {&key, &value}.
struct Word12
{
    UInt32 Words[3];
};

struct KeyWordIntRefOps
{
    static void Copy(char* d, const char* s)
    {
        *(U*)d = *(const U*)s;
        RawField<Word12>(d, 8) = RawField<Word12>(s, 8);
    }
    static void Construct(char* d, const NodeRef& r)
    {
        *(U*)d = *r.Key;
        RawField<Word12>(d, 8) = *(const Word12*)r.Value;
    }
    static void Assign(char* d, const NodeRef& r) { Construct(d, r); }
};

// HashSetBase::add body, written in the row so the hash parameter itself takes the mask.
#define RAW_HASH_ADD_BODY(Stride, Ops, arg)                                 \
    hash &= (*self)[1];                                                     \
    (*self)[0]++;                                                           \
    U* table = *self;                                                       \
    char* e = RawEntry(table, hash, Stride);                                \
    if (*(SPInt*)e == -2)                                                   \
    {                                                                       \
        *(SPInt*)e = -1;                                                    \
        Ops::Construct(e + 0x10, arg);                                      \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        U blank = hash;                                                     \
        do                                                                  \
            blank = (blank + 1) & table[1];                                 \
        while (*(SPInt*)RawEntry(table, blank, Stride) != -2);              \
        char* b = RawEntry(table, blank, Stride);                           \
        if (*(U*)(e + 8) == hash)                                           \
        {                                                                   \
            *(SPInt*)b = *(SPInt*)e;                                        \
            *(U*)(b + 8) = *(U*)(e + 8);                                    \
            Ops::Copy(b + 0x10, e + 0x10);                                  \
            Ops::Assign(e + 0x10, arg);                                     \
            *(U*)e = blank;                                                 \
        }                                                                   \
        else                                                                \
        {                                                                   \
            U* link = (U*)RawEntry(table, *(U*)(e + 8), Stride);            \
            while (*link != hash)                                           \
                link = (U*)RawEntry(table, *link, Stride);                  \
            *(SPInt*)b = *(SPInt*)e;                                        \
            *(U*)(b + 8) = *(U*)(e + 8);                                    \
            Ops::Copy(b + 0x10, e + 0x10);                                  \
            *link = blank;                                                  \
            Ops::Assign(e + 0x10, arg);                                     \
            *(SPInt*)e = -1;                                                \
        }                                                                   \
    }                                                                       \
    *(U*)(e + 8) = hash;

// HashSetBase::add over the array-valued set, node passed by value.
// @0x1427429d0
void FUN_1427429d0(U** self, void* heap, const U* node, U hash)
{
    CheckExpandAS3CachedSet((void**)self, heap);
    RAW_HASH_ADD_BODY(0x30, KeyArrayOps, node)
}

// HashSetBase::add over the {word, twelve-byte value} set, node reference.
// @0x142742b50
void FUN_142742b50(U** self, void* heap, const NodeRef* node, U hash)
{
    RawCheckExpand<FUN_142747530>(self, heap);
    RAW_HASH_ADD_BODY(0x28, KeyWordIntRefOps, *node)
}

// HashSetBase::add over the array-valued set, node reference.
// @0x142742d10
void FUN_142742d10(U** self, void* heap, const NodeRef* node, U hash)
{
    RawCheckExpand<FUN_1427478c0>(self, heap);
    RAW_HASH_ADD_BODY(0x30, KeyArrayRefOps, *node)
}

}} // namespace Scaleform::GFx
