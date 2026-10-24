// Raw-layout helpers shared by the sfr_gfx_07h/07i/07j sub-units: the exe's open-addressed hash sets (table =
// {count, mask, entries...}) written as free functions over raw tables. Our own source, written from the exe.
#ifndef MS2_SFR_GFX_07RAW_H
#define MS2_SFR_GFX_07RAW_H

#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_string.h"

#include <new>

namespace Scaleform { namespace GFx {

typedef UPInt U;

void FUN_14257dc30(void*);   // Ptr AddRef
void FUN_14257dcb0(void*);   // Ptr Release

// An entry of a set whose table is {count, mask, entries...}: entry i starts at table + 0x10 + i * stride with the
// chain link (-2 empty, -1 end) at +0, the home hash at +8 and the payload at +0x10.
static inline char* RawEntry(U* table, U index, U stride) { return (char*)table + 0x10 + index * stride; }

// HashSetBase::CheckExpand: 8 entries first, doubled when the load passes 4/5.
template<void (*Grow)(U**, void*, U)>
static inline void RawCheckExpand(U** self, void* ctx)
{
    U* table = *self;
    if (!table)
        Grow(self, ctx, 8);
    else if (table[1] * 4 + 4 < table[0] * 5)
        Grow(self, ctx, table[1] * 2 + 2);
}

// HashSetBase::add: place a new entry at its hash's home slot, moving a squatter out to a free slot first.
template<U Stride, class Ops, class Arg>
static inline void RawHashAdd(U** self, Arg arg, U hash)
{
    U* table = *self;
    U home = hash & table[1];
    table[0]++;
    table = *self;
    char* e = RawEntry(table, home, Stride);
    if (*(SPInt*)e == -2)
    {
        *(SPInt*)e = -1;
        Ops::Construct(e + 0x10, arg);
    }
    else
    {
        U blank = home;
        do
            blank = (blank + 1) & table[1];
        while (*(SPInt*)RawEntry(table, blank, Stride) != -2);
        char* b = RawEntry(table, blank, Stride);
        if (*(U*)(e + 8) == home)
        {
            *(SPInt*)b = *(SPInt*)e;
            *(U*)(b + 8) = *(U*)(e + 8);
            Ops::Copy(b + 0x10, e + 0x10);
            Ops::Assign(e + 0x10, arg);
            *(U*)e = blank;
        }
        else
        {
            U* link = (U*)RawEntry(table, *(U*)(e + 8), Stride);
            while (*link != home)
                link = (U*)RawEntry(table, *link, Stride);
            *(SPInt*)b = *(SPInt*)e;
            *(U*)(b + 8) = *(U*)(e + 8);
            Ops::Copy(b + 0x10, e + 0x10);
            *link = blank;
            Ops::Assign(e + 0x10, arg);
            *(SPInt*)e = -1;
        }
    }
    *(U*)(e + 8) = home;
}

// Payload {Movie*, Ptr<ASIMEManager>} built from a HashNode (key, value) or from a NodeRef (&key, &value).
struct MoviePtrOps
{
    static void Copy(char* d, const char* s)
    {
        *(U*)d = *(const U*)s;
        void* p = *(void* const*)(s + 8);
        if (p)
            FUN_14257dc30(p);
        *(void**)(d + 8) = p;
    }
    static void Construct(char* d, const char* node)
    {
        *(U*)d = *(const U*)node;
        void* p = *(void* const*)(node + 8);
        if (p)
            FUN_14257dc30(p);
        *(void**)(d + 8) = p;
    }
    static void Assign(char* d, const char* node)
    {
        *(U*)d = *(const U*)node;
        void* p = *(void* const*)(node + 8);
        if (p)
            FUN_14257dc30(p);
        if (*(void**)(d + 8))
            FUN_14257dcb0(*(void**)(d + 8));
        *(void**)(d + 8) = p;
    }
};

struct NodeRef
{
    const U* Key;
    void* const* Value;
};

struct MoviePtrRefOps
{
    static void Copy(char* d, const char* s) { MoviePtrOps::Copy(d, s); }
    static void Construct(char* d, const NodeRef& r)
    {
        *(U*)d = *r.Key;
        void* p = *r.Value;
        if (p)
            FUN_14257dc30(p);
        *(void**)(d + 8) = p;
    }
    static void Assign(char* d, const NodeRef& r)
    {
        *(U*)d = *r.Key;
        void* p = *r.Value;
        if (p)
            FUN_14257dc30(p);
        if (*(void**)(d + 8))
            FUN_14257dcb0(*(void**)(d + 8));
        *(void**)(d + 8) = p;
    }
};

// Payload of three plain words, from a NodeRef whose key is two words and value one.
struct WordsRefOps
{
    struct Ref
    {
        const U* Key;
        const U* Value;
    };
    static void Copy(char* d, const char* s)
    {
        U a = *(const U*)(s + 8);
        *(U*)d = *(const U*)s;
        *(U*)(d + 8) = a;
        *(U*)(d + 16) = *(const U*)(s + 16);
    }
    static void Construct(char* d, const Ref& r)
    {
        U b = r.Key[1];
        *(U*)d = r.Key[0];
        *(U*)(d + 8) = b;
        *(U*)(d + 16) = *r.Value;
    }
    static void Assign(char* d, const Ref& r) { Construct(d, r); }
};

// Payload {U key, String}.
struct KeyStringOps
{
    struct Ref
    {
        const U* Key;
        const String* Value;
    };
    static void Copy(char* d, const char* s)
    {
        *(U*)d = *(const U*)s;
        new (d + 8) String(*(const String*)(s + 8));
    }
    static void Construct(char* d, const Ref& r)
    {
        *(U*)d = *r.Key;
        new (d + 8) String(*r.Value);
    }
    static void Assign(char* d, const Ref& r)
    {
        *(U*)d = *r.Key;
        *(String*)(d + 8) = *r.Value;
    }
};

// Payload {String, UInt32}.
struct StringKeyOps
{
    struct Ref
    {
        const String* Key;
        const UInt32* Value;
    };
    static void Copy(char* d, const char* s)
    {
        new (d) String(*(const String*)s);
        *(UInt32*)(d + 8) = *(const UInt32*)(s + 8);
    }
    static void Construct(char* d, const Ref& r)
    {
        new (d) String(*r.Key);
        *(UInt32*)(d + 8) = *r.Value;
    }
    static void Assign(char* d, const Ref& r)
    {
        *(String*)d = *r.Key;
        *(UInt32*)(d + 8) = *r.Value;
    }
};

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

// Frees a set with no per-entry payload to release (stride 0x30 entries).
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

// FixedSizeHash of an eight-byte key (bytes mixed with per-position multipliers).
static inline U RawKey8Hash(U key)
{
    const unsigned char* k = (const unsigned char*)&key;
    return (((U)k[3] * 0x1003f + (U)k[2]) * 0x1003f + (U)k[1]) * 0x1003f + (U)k[4] * 0xfc5d1543ec5f01ULL +
           (U)k[5] * (U)-0x64cfd3d7e9d39ec1LL + (U)k[7] * (U)-0x283c1b695cee4e41LL +
           (U)k[6] * 0x5d02f409d62aee81ULL + (U)-0x514d9afbc3e934fbLL + (U)k[0];
}

// Looks an eight-byte key up in a set whose entries keep it as their first payload word; -1 when absent.
static inline SPInt RawFindKey8(U* table, U key, U stride)
{
    if (!table)
        return -1;
    U home = table[1] & RawKey8Hash(key);
    U index = home;
    char* e = RawEntry(table, index, stride);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != home)
        return -1;
    for (;;)
    {
        if (*(U*)(e + 8) == home && *(U*)(e + 0x10) == key)
            return (SPInt)index;
        SPInt next = *(SPInt*)e;
        if (next == -1)
            return -1;
        index = (U)next;
        e = RawEntry(table, index, stride);
    }
}

// Appends a slot to a {data, size, capacity} array through the exe's Reserve instance; returns the new slot.
template<void (*Reserve)(U*, void*, U)>
static inline char* RawArrayPush(U* array, U elemSize)
{
    U n = array[1] + 1;
    if (array[2] <= n)
        Reserve(array, array, n + (n >> 2));
    array[1] = n;
    return (char*)array[0] + (n - 1) * elemSize;
}

}} // namespace Scaleform::GFx

#endif
