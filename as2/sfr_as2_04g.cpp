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
void FUN_142939780(void*);
void FUN_14257db40(void*);
void FUN_14257db50(void*);
void FUN_14257dcb0(void*);
void FUN_1425c14e0(void*);
void FUN_1425925f0(void*);
void FUN_1425f0900(void*);

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

// @0x142928f30
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142928f30(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x10)) Memory::Free(*(void**)((char*)p+0x10));
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929ec0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142929ec0(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a400
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292a400(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292c2c0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292c2c0(void* p, unsigned flags)
{
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929f40
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_142929f40(void* p, unsigned flags)
{
    FUN_142925750((char*)p+0x70);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a480
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292a480(void* p, unsigned flags)
{
    FUN_142925750((char*)p+0x70);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292c340
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292c340(void* p, unsigned flags)
{
    FUN_142925750((char*)p+0x78);
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292d120
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292d120(void* p, unsigned flags)
{
    FUN_142925750((char*)p+0x70);
    rs(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292d0b0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292d0b0(void* p, unsigned flags)
{
    rs(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a050
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292a050(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x18)) Memory::Free(*(void**)((char*)p+0x18));
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292af30
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292af30(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x20)) Memory::Free(*(void**)((char*)p+0x20));
    FUN_14257db50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292d4b0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292d4b0(void* p, unsigned flags)
{
    Memory::Free(*(void**)((char*)p+0x70));
    { int* r=*(int**)((char*)p+0x68); if (r && --*r==0) Memory::Free(r); }
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292c5a0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292c5a0(void* p, unsigned flags)
{
    ra(*(unsigned long long*)((char*)p+0x70));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292afe0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292afe0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    ra(*(unsigned long long*)((char*)p+0x28));
    ra(*(unsigned long long*)((char*)p+0x20));
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b390
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292b390(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    ra(*(unsigned long long*)((char*)p+0x28));
    ra(*(unsigned long long*)((char*)p+0x20));
    if (*(void**)((char*)p+0x18)) FUN_14257dcb0(*(void**)((char*)p+0x18));
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b0c0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292b0c0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0xc0)) FUN_14257dcb0(*(void**)((char*)p+0xc0));
    if (*(unsigned char*)((char*)p+0xa0) > 4) FUN_142939780((char*)p+0xa0);
    if (*(void**)((char*)p+0x98)) FUN_14257dcb0(*(void**)((char*)p+0x98));
    if (*(unsigned char*)((char*)p+0x78) > 4) FUN_142939780((char*)p+0x78);
    if (*(unsigned char*)((char*)p+0x58) > 4) FUN_142939780((char*)p+0x58);
    if (*(unsigned char*)((char*)p+0x38) > 4) FUN_142939780((char*)p+0x38);
    rc(*(void**)((char*)p+0x30));
    ra(*(unsigned long long*)((char*)p+0x18));
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292beb0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292beb0(void* p, unsigned flags)
{
    rv((char*)p,0x90,0x98,0xa0);
    rg(*(void**)((char*)p+0x78));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292d330
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292d330(void* p, unsigned flags)
{
    rv((char*)p,0x80,0x88,0x90);
    rg(*(void**)((char*)p+0x70));
    rg(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292dae0
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292dae0(void* p, unsigned flags)
{
    rv((char*)p,0x38,0x40,0x48);
    rv((char*)p,0x20,0x28,0x30);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ad40
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292ad40(void* p, unsigned flags)
{
    rv((char*)p,0x0,0x8,0x10);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292c750
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292c750(void* p, unsigned flags)
{
    FUN_142925dd0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ce00
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
void* DeleteAs2_14292ce00(void* p, unsigned flags)
{
    rg(*(void**)((char*)p+0x8));
    if (flags & 1)
        Memory::Free(p);
    return p;
}

}}} // namespace
