// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose members are not recovered; member releases are written out against raw offsets (gap recovery of sfr_as2_03/04).
// MS2-UNIT: sfr_as2_04h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142928c70-0x142928cf0 .text$mn
// MS2-RANGE: 0x142928dc0-0x142928e40 .text$mn
// MS2-RANGE: 0x142928e90-0x142928f2a .text$mn
// MS2-RANGE: 0x142929400-0x1429294e7 .text$mn
// MS2-RANGE: 0x1429294f0-0x142929588 .text$mn
// MS2-RANGE: 0x142929590-0x1429295fd .text$mn
// MS2-RANGE: 0x142929600-0x1429296d8 .text$mn
// MS2-RANGE: 0x1429296e0-0x142929796 .text$mn
// MS2-RANGE: 0x14292a0e0-0x14292a163 .text$mn
// MS2-RANGE: 0x14292b4e0-0x14292b586 .text$mn
// MS2-RANGE: 0x14292ba00-0x14292baaa .text$mn
// MS2-RANGE: 0x14292c3e0-0x14292c520 .text$mn

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
void FUN_142592200(void*, void*);
void FUN_1429343f0(void*);
void FUN_14256a8e0(void*);
void FUN_142924180(void*);
void FUN_14257dcd0(void*);
void FUN_142924a20(void*);
void FUN_142925680(void*);
void FUN_1424a9ed0(void*);
void FUN_142924580(void*);
void FUN_140001f40(void*);
void FUN_142924770(void*);
void FUN_14000b080(void*);
void FUN_142924960(void*);
void FUN_1425c1350(void*, void*, int);
void FUN_142925250(void*);
void FUN_142581700(void*);

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
extern const void* DAT_143215b00[];
extern const void* DAT_143215c48[];
extern const void* DAT_14317bf80[];
extern const void* DAT_143216338[];
extern const void* DAT_143216480[];
extern const void* DAT_143216528[];
extern const void* DAT_1432177d8[];
extern const void* DAT_14317bde0[];
extern const void* DAT_143215370[];
extern const void* DAT_1432153c8[];
extern const void* DAT_1432155c0[];
extern const void* DAT_143215648[];
extern const void* DAT_143215a98[];
extern const void* DAT_143215af8[];
extern const void* DAT_14316afc0[];
extern const void* DAT_1432153a0[];

// @0x142928c70
void* DeleteAs2_142928c70(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432153a0;
    FUN_142592200(p, 0);
    *(const void**)((char*)p+0x40) = DAT_143215370;
    FUN_1429343f0((char*)p+0x10);
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x142928dc0
void* DeleteAs2_142928dc0(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432153a0;
    FUN_142592200(p, 0);
    *(const void**)((char*)p+0x40) = DAT_143215370;
    FUN_1429343f0((char*)p+0x10);
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x98);
    }
    return p;
}

// MS2-FUNCTIONAL 0x142928e90: the exe also saves and restores rsi, which it never uses
// @0x142928e90
void* DeleteAs2_142928e90(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432153c8;
    rs(*(void**)((char*)p+0x30));
    FUN_14256a8e0((char*)p+0x18);
    if (*(void**)((char*)p+0x10)) FUN_14257dcb0(*(void**)((char*)p+0x10));
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

// @0x142929400
void* DeleteAs2_142929400(void* p, unsigned flags)
{
    rs(*(void**)((char*)p+0xc0));
    FUN_142924180((char*)p+0xa0);
    Memory::Free(*(void**)((char*)p+0x80));
    if (*(void**)((char*)p+0x78)) FUN_14257dcd0(*(void**)((char*)p+0x78));
    rc(*(void**)((char*)p+0x70));
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xd0);
    }
    return p;
}

// @0x1429294f0
void* DeleteAs2_1429294f0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x38));
    *(const void**)p = DAT_143215b00;
    *(const void**)((char*)p+0x30) = DAT_14317bf80;
    *(const void**)((char*)p+0x8) = DAT_143215c48;
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    *(const void**)p = DAT_14317bf80;
    if ((flags & 5) == 5)
        ::operator delete(p, 0x40);
    return p;
}

// @0x142929590
void* DeleteAs2_142929590(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215b00;
    *(const void**)((char*)p+0x8) = DAT_143215c48;
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    *(const void**)p = DAT_14317bf80;
    if ((flags & 5) == 5)
        ::operator delete(p, 0x30);
    return p;
}

// MS2-FUNCTIONAL 0x142929600: scheduling only (the exe loads the heap pointer before the +0x1e0 block)
// @0x142929600
void* DeleteAs2_142929600(void* p, unsigned flags)
{
    *(const void**)p = DAT_143216338;
    *(const void**)((char*)p+0x8) = DAT_143216480;
    *(const void**)((char*)p+0x30) = DAT_143216528;
    Memory::Free(*(void**)((char*)p+0x1e0));
    rg(*(void**)((char*)p+0x1d8));
    FUN_142925680((char*)p+0x38);
    *(const void**)p = DAT_143215b00;
    *(const void**)((char*)p+0x30) = DAT_14317bf80;
    *(const void**)((char*)p+0x8) = DAT_143215c48;
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    *(const void**)p = DAT_14317bf80;
    if ((flags & 5) == 5)
        ::operator delete(p, 0x200);
    return p;
}

// @0x1429296e0
void* DeleteAs2_1429296e0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x60));
    ((Value*)((char*)p+0x40))->~Value();
    rs(*(void**)((char*)p+0x38));
    *(const void**)p = DAT_143215b00;
    *(const void**)((char*)p+0x30) = DAT_14317bf80;
    *(const void**)((char*)p+0x8) = DAT_143215c48;
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    *(const void**)p = DAT_14317bf80;
    if ((flags & 5) == 5)
        ::operator delete(p, 0x68);
    return p;
}

// @0x14292a0e0
void* DeleteAs2_14292a0e0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x40));
    *(const void**)p = DAT_14316afc0;
    FUN_1424a9ed0((char*)p+0x8);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x48);
    }
    return p;
}

// @0x14292b4e0
void* DeleteAs2_14292b4e0(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215af8;
    FUN_142924580((char*)p+0x70);
    rg(*(void**)((char*)p+0x60));
    FUN_140001f40((char*)p+0x20);
    FUN_142924770((char*)p+0x18);
    FUN_14000b080((char*)p+0x10);
    FUN_14257db50(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292ba00
void* DeleteAs2_14292ba00(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215a98;
    ((Value*)((char*)p+0x68))->~Value();
    ((Value*)((char*)p+0x48))->~Value();
    rg(*(void**)((char*)p+0x28));
    FUN_142924960((char*)p+0x20);
    *(const void**)p = DAT_143215370;
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x88);
    }
    return p;
}

// MS2-FUNCTIONAL 0x14292c3e0: register allocation and scheduling only (the exe swaps the loop count and cursor registers)
// @0x14292c3e0
void* DeleteAs2_14292c3e0(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432177d8;
    {
        unsigned long long n = *(unsigned long long*)((char*)p+0x630);
        void** e = *(void***)((char*)p+0x628) + (n - 1);
        for (; n; --n, --e)
            if (*e) FUN_14257dcd0(*e);
    }
    Memory::Free(*(void**)((char*)p+0x628));
    FUN_1425c1350(*(void**)((char*)p+0x618), (char*)p+0x138, 0x9c);
    FUN_142925250((char*)p+0x80);
    ((Value*)((char*)p+0x58))->~Value();
    if (*(void**)((char*)p+0x50)) FUN_14257dcd0(*(void**)((char*)p+0x50));
    if (*(void**)((char*)p+0x38)) FUN_14257dcb0(*(void**)((char*)p+0x38));
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    { char* e=*(char**)((char*)p+0x28); if (e && --*(long long*)(e+8)==0) FUN_142581700(e); }
    *(const void**)p = DAT_14317bde0;
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    FUN_14257db40(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x640);
    }
    return p;
}

}}} // namespace
