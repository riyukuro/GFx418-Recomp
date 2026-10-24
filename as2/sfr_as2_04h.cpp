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
void FUN_142939780(void*);
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
    int* c = (int*)((char*)n + 0x18);
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
    if (h && --*c < 1) { FUN_1425f0900(h); Memory::Free(h); }
}
static inline void ra(unsigned long long tagged) // atomic shared string-data release
{
    int* c = (int*)((tagged & ~3ull) + 8);
    if (_InterlockedDecrement((volatile long*)c) == 0) Memory::Free((void*)(tagged & ~3ull));
}
static inline void rv(char* c, int a, int b, int fl) // FunctionRef-style pair release
{
    unsigned char f = (unsigned char)c[fl];
    if (!(f & 2) && *(void**)(c + a)) { rg(*(void**)(c + a)); f = (unsigned char)c[fl]; }
    *(void**)(c + a) = 0;
    if (!(f & 1) && *(void**)(c + b)) rg(*(void**)(c + b));
    *(void**)(c + b) = 0;
}

// @0x142928c70
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142928c70(void* p, unsigned flags)
{
    FUN_142592200(p, 0);
    FUN_1429343f0((char*)p+0x10);
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928dc0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142928dc0(void* p, unsigned flags)
{
    FUN_142592200(p, 0);
    FUN_1429343f0((char*)p+0x10);
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928e90
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142928e90(void* p, unsigned flags)
{
    rs(*(void**)((char*)p+0x30));
    FUN_14256a8e0((char*)p+0x18);
    if (*(void**)((char*)p+0x10)) FUN_14257dcb0(*(void**)((char*)p+0x10));
    FUN_14257db50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929400
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142929400(void* p, unsigned flags)
{
    rs(*(void**)((char*)p+0xc0));
    FUN_142924180((char*)p+0xa0);
    Memory::Free(*(void**)((char*)p+0x80));
    if (*(void**)((char*)p+0x78)) FUN_14257dcd0(*(void**)((char*)p+0x78));
    rc(*(void**)((char*)p+0x70));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x1429294f0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_1429294f0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x38));
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    if ((flags & 5) == 5)
        Memory::Free(p);
    return p;
}

// @0x142929590
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142929590(void* p, unsigned flags)
{
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    if ((flags & 5) == 5)
        Memory::Free(p);
    return p;
}

// @0x142929600
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142929600(void* p, unsigned flags)
{
    Memory::Free(*(void**)((char*)p+0x1e0));
    rg(*(void**)((char*)p+0x1d8));
    FUN_142925680((char*)p+0x38);
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    if ((flags & 5) == 5)
        Memory::Free(p);
    return p;
}

// @0x1429296e0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_1429296e0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x60));
    if (*(unsigned char*)((char*)p+0x40) > 4) FUN_142939780((char*)p+0x40);
    rs(*(void**)((char*)p+0x38));
    FUN_142924a20((char*)p+0x28);
    FUN_142925dd0((char*)p+0x8);
    if ((flags & 5) == 5)
        Memory::Free(p);
    return p;
}

// @0x14292a0e0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292a0e0(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x40));
    FUN_1424a9ed0((char*)p+0x8);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b4e0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292b4e0(void* p, unsigned flags)
{
    FUN_142924580((char*)p+0x70);
    rg(*(void**)((char*)p+0x60));
    FUN_140001f40((char*)p+0x20);
    FUN_142924770((char*)p+0x18);
    FUN_14000b080((char*)p+0x10);
    FUN_14257db50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ba00
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292ba00(void* p, unsigned flags)
{
    if (*(unsigned char*)((char*)p+0x68) > 4) FUN_142939780((char*)p+0x68);
    if (*(unsigned char*)((char*)p+0x48) > 4) FUN_142939780((char*)p+0x48);
    rg(*(void**)((char*)p+0x28));
    FUN_142924960((char*)p+0x20);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292c3e0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292c3e0(void* p, unsigned flags)
{
    { long long n=*(long long*)((char*)p+0x630); void** a=*(void***)((char*)p+0x628); for (long long i=n-1; i>=0; --i) if (a[i]) FUN_14257dcd0(a[i]); }
    Memory::Free(*(void**)((char*)p+0x628));
    FUN_1425c1350(*(void**)((char*)p+0x618), (char*)p+0x138, 0x9c);
    FUN_142925250((char*)p+0x80);
    if (*(unsigned char*)((char*)p+0x58) > 4) FUN_142939780((char*)p+0x58);
    if (*(void**)((char*)p+0x50)) FUN_14257dcd0(*(void**)((char*)p+0x50));
    if (*(void**)((char*)p+0x38)) FUN_14257dcb0(*(void**)((char*)p+0x38));
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    { char* e=*(char**)((char*)p+0x28); if (e && --*(long long*)(e+8)==0) FUN_142581700(e); }
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

}}} // namespace
