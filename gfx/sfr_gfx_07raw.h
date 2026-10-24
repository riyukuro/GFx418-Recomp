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

}} // namespace Scaleform::GFx

#endif
