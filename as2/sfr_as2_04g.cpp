// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose members are not recovered; member releases are written out against raw offsets (gap recovery of sfr_as2_03/04).
// MS2-UNIT: sfr_as2_04g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142928f30-0x142928fab .text$mn
// MS2-RANGE: 0x142929ec0-0x142929f36 .text$mn
// MS2-RANGE: 0x14292a400-0x14292a476 .text$mn
// MS2-RANGE: 0x14292c2c0-0x14292c336 .text$mn
// MS2-RANGE: 0x142929f40-0x142929fde .text$mn
// MS2-RANGE: 0x14292a480-0x14292a51e .text$mn
// MS2-RANGE: 0x14292c340-0x14292c3de .text$mn
// MS2-RANGE: 0x14292d120-0x14292d1b2 .text$mn
// MS2-RANGE: 0x14292d0b0-0x14292d11a .text$mn
// MS2-RANGE: 0x14292a050-0x14292a0d5 .text$mn
// MS2-RANGE: 0x14292af30-0x14292afa1 .text$mn
// MS2-RANGE: 0x14292d4b0-0x14292d54c .text$mn
// MS2-RANGE: 0x14292c5a0-0x14292c61f .text$mn
// MS2-RANGE: 0x14292afe0-0x14292b0b5 .text$mn
// MS2-RANGE: 0x14292b390-0x14292b465 .text$mn
// MS2-RANGE: 0x14292b0c0-0x14292b1dc .text$mn
// MS2-RANGE: 0x14292beb0-0x14292bfbd .text$mn
// MS2-RANGE: 0x14292d330-0x14292d43a .text$mn
// MS2-RANGE: 0x14292dae0-0x14292dc04 .text$mn
// MS2-RANGE: 0x14292ad40-0x14292add0 .text$mn
// MS2-RANGE: 0x14292c750-0x14292c783 .text$mn
// MS2-RANGE: 0x14292ce00-0x14292ce56 .text$mn

#include <intrin.h>
#include "../include/gfx/as2/as2_action.h"

namespace Scaleform { namespace GFx { namespace AS2 {

void FUN_142925cf0(void*);
void FUN_142925750(void*);
void FUN_142925dd0(void*);
void FUN_14257db40(void*);
void FUN_14257db50(void*);
void FUN_14257dcb0(void*);
void FUN_1425c14e0(void*);
void FUN_1425925f0(void*);
void FUN_1425f0900(void*);

static inline void rs(void* n) // ASString release
{
    unsigned* c = (unsigned*)((char*)n + 0x18);
    if (--*c == 0) FUN_1425c14e0(n);
}
static inline void rg(void* n) // Ptr<RefCountBaseGC> release
{
    unsigned* c = (unsigned*)((char*)n + 0x18);
    if (n && (*c & 0x3ffffff)) { --*c; FUN_1425925f0(n); }
}
static inline void rc(void* h) // Ptr<CharacterHandle> release
{
    int* c = (int*)h;
    if (h && --*c <= 0) { FUN_1425f0900(h); Memory::Free(h); }
}
static inline void ra(unsigned long long tagged) // atomic shared string-data release
{
    int* c = (int*)((tagged & ~3ull) + 8);
    if (_InterlockedExchangeAdd((volatile long*)c, -1) == 1) Memory::Free((void*)(tagged & ~3ull));
}
// The base vftables the inlined destructors store.
extern const void* DAT_14317c9d8[];
extern const void* DAT_143188d98[];
extern const void* DAT_143215370[];
extern const void* DAT_1432153b8[];
extern const void* DAT_1432155c0[];
extern const void* DAT_143215648[];
extern const void* DAT_143216730[];
extern const void* DAT_143216778[];
extern const void* DAT_143216820[];
extern const void* DAT_1432172f0[];
extern const void* DAT_143217718[];
extern const void* DAT_143217d38[];
extern const void* DAT_143217d80[];
extern const void* DAT_143217e28[];
extern const void* DAT_143218490[];
extern const void* DAT_1432184d8[];
extern const void* DAT_143218990[];
extern const void* DAT_1432189d8[];
extern const void* DAT_143218a80[];
extern const void* DAT_14321aa10[];
extern const void* DAT_14321aa58[];
extern const void* DAT_14321ab00[];
extern const void* DAT_14321dd78[];
extern const void* DAT_143222848[];

// @0x142928f30
void* DeleteAs2_142928f30(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432153b8;
    if (*(void**)((char*)p+0x10)) Memory::Free(*(void**)((char*)p+0x10));
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x28);
    }
    return p;
}

// @0x142929ec0
void* DeleteAs2_142929ec0(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292a400
void* DeleteAs2_14292a400(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c2c0
void* DeleteAs2_14292c2c0(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x142929f40
void* DeleteAs2_142929f40(void* p, unsigned flags)
{
    *(const void**)p = DAT_143217d38;
    *(const void**)((char*)p+0x20) = DAT_143217d80;
    *(const void**)((char*)p+0x70) = DAT_143217e28;
    FUN_142925750((char*)p+0x70);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb0);
    }
    return p;
}

// @0x14292a480
void* DeleteAs2_14292a480(void* p, unsigned flags)
{
    *(const void**)p = DAT_143218990;
    *(const void**)((char*)p+0x20) = DAT_1432189d8;
    *(const void**)((char*)p+0x70) = DAT_143218a80;
    FUN_142925750((char*)p+0x70);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb0);
    }
    return p;
}

// @0x14292c340
void* DeleteAs2_14292c340(void* p, unsigned flags)
{
    *(const void**)p = DAT_143216730;
    *(const void**)((char*)p+0x20) = DAT_143216778;
    *(const void**)((char*)p+0x78) = DAT_143216820;
    FUN_142925750((char*)p+0x78);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb8);
    }
    return p;
}

// @0x14292d120
void* DeleteAs2_14292d120(void* p, unsigned flags)
{
    *(const void**)p = DAT_14321aa10;
    *(const void**)((char*)p+0x20) = DAT_14321aa58;
    *(const void**)((char*)p+0x70) = DAT_14321ab00;
    FUN_142925750((char*)p+0x70);
    rs(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb0);
    }
    return p;
}

// @0x14292d0b0
void* DeleteAs2_14292d0b0(void* p, unsigned flags)
{
    rs(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292a050
void* DeleteAs2_14292a050(void* p, unsigned flags)
{
    *(const void**)p = DAT_143222848;
    if (*(void**)((char*)p+0x18)) Memory::Free(*(void**)((char*)p+0x18));
    *(const void**)p = DAT_1432172f0;
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x28);
    }
    return p;
}

// @0x14292af30
void* DeleteAs2_14292af30(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x20)) Memory::Free(*(void**)((char*)p+0x20));
    FUN_14257db50(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x40);
    }
    return p;
}

// @0x14292d4b0
void* DeleteAs2_14292d4b0(void* p, unsigned flags)
{
    *(const void**)p = DAT_143218490;
    *(const void**)((char*)p+0x20) = DAT_1432184d8;
    Memory::Free(*(void**)((char*)p+0x70));
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292c5a0
void* DeleteAs2_14292c5a0(void* p, unsigned flags)
{
    ra(*(unsigned long long*)((char*)p+0x70));
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292afe0
void* DeleteAs2_14292afe0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    ((String*)((char*)p+0x28))->~String();
    ((String*)((char*)p+0x20))->~String();
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    *(const void**)p = DAT_143188d98;
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x40);
    }
    return p;
}

// @0x14292b390
void* DeleteAs2_14292b390(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    ((String*)((char*)p+0x28))->~String();
    ((String*)((char*)p+0x20))->~String();
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    *(const void**)p = DAT_143188d98;
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x40);
    }
    return p;
}

// +0x78 and +0xa0 are {Value, Ptr} pairs: their own inlined dtor is what puts the type test before the lea.
struct VP14292b0c0 { Value V; void* P; ~VP14292b0c0() { if (P) FUN_14257dcb0(P); } };

// @0x14292b0c0
void* DeleteAs2_14292b0c0(void* p, unsigned flags)
{
    ((VP14292b0c0*)((char*)p+0xa0))->~VP14292b0c0();
    ((VP14292b0c0*)((char*)p+0x78))->~VP14292b0c0();
    ((Value*)((char*)p+0x58))->~Value();
    ((Value*)((char*)p+0x38))->~Value();
    rc(*(void**)((char*)p+0x30));
    unsigned long long name = *(unsigned long long*)((char*)p+0x18);
    *(const void**)p = DAT_14317c9d8;
    ra(name);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xc8);
    }
    return p;
}

// @0x14292beb0
void* DeleteAs2_14292beb0(void* p, unsigned flags)
{
    ((FunctionRefBase*)((char*)p+0x90))->DropRefs();
    rg(*(void**)((char*)p+0x78));
    *(const void**)((char*)p+0x70) = DAT_143217718;
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb0);
    }
    return p;
}

// @0x14292d330
void* DeleteAs2_14292d330(void* p, unsigned flags)
{
    ((FunctionRefBase*)((char*)p+0x80))->DropRefs();
    rg(*(void**)((char*)p+0x70));
    rg(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x98);
    }
    return p;
}

// @0x14292dae0
void* DeleteAs2_14292dae0(void* p, unsigned flags)
{
    ((FunctionRefBase*)((char*)p+0x38))->DropRefs();
    ((FunctionRefBase*)((char*)p+0x20))->DropRefs();
    *(const void**)p = DAT_143215370;
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x50);
    }
    return p;
}

// @0x14292ad40
void* DeleteAs2_14292ad40(void* p, unsigned flags)
{
    ((FunctionRefBase*)p)->DropRefs();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// @0x14292c750
void* DeleteAs2_14292c750(void* p, unsigned flags)
{
    FUN_142925dd0(p);
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// @0x14292ce00
void* DeleteAs2_14292ce00(void* p, unsigned flags)
{
    *(const void**)p = DAT_14321dd78;
    rg(*(void**)((char*)p+0x8));
    if (flags & 1)
        ::operator delete(p, 0x10);
    return p;
}

}}} // namespace
