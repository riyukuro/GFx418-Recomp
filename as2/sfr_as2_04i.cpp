// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose members are not recovered; member releases are written out against raw offsets (gap recovery of sfr_as2_03/04).
// MS2-UNIT: sfr_as2_04i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142927640-0x142927688 .text$mn
// MS2-RANGE: 0x1429276e0-0x14292770a .text$mn
// MS2-RANGE: 0x142927710-0x14292773a .text$mn
// MS2-RANGE: 0x142928fb0-0x142928fda .text$mn
// MS2-RANGE: 0x142925850-0x14292588b .text$mn
// MS2-RANGE: 0x1429258e0-0x14292591b .text$mn

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
void FUN_142639d10(void*);
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

// The vftables the inlined destructors store.
extern const void* DAT_143215370[]; // RefCountBaseGC<323>
extern const void* DAT_143215ab0[];
extern const void* DAT_143215ad0[];
extern const void* DAT_1432177b0[]; // GFxAS2LoadQueueEntryMT_LoadCSS
extern const void* DAT_143217780[]; // GFxAS2LoadQueueEntryMT_LoadXML


// @0x142927640
void* DeleteAs2_142927640(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215370;
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x20);
    }
    return p;
}

// @0x1429276e0
void* DeleteAs2_1429276e0(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215ab0;
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// @0x142927710
void* DeleteAs2_142927710(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215ad0;
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// The derived class (vftable 0x143215ac0) adds nothing to destroy; the base dtor stores 0x143215ab0.
// @0x142928fb0
void* DeleteAs2_142928fb0(void* p, unsigned flags)
{
    *(const void**)p = DAT_143215ab0;
    if (flags & 1)
        ::operator delete(p, 0x20);
    return p;
}

// GFxAS2LoadQueueEntryMT_LoadCSS::~GFxAS2LoadQueueEntryMT_LoadCSS: pLoadStates, pTask, then ~LoadQueueEntryMT.
// @0x142925850
void DtorAs2_142925850(void* p)
{
    *(const void**)p = DAT_1432177b0;
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    if (*(void**)((char*)p+0x28)) FUN_14257dcb0(*(void**)((char*)p+0x28));
    FUN_142639d10(p);
}

// GFxAS2LoadQueueEntryMT_LoadXML::~GFxAS2LoadQueueEntryMT_LoadXML: pLoadStates, pTask, then ~LoadQueueEntryMT.
// @0x1429258e0
void DtorAs2_1429258e0(void* p)
{
    *(const void**)p = DAT_143217780;
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    if (*(void**)((char*)p+0x28)) FUN_14257dcb0(*(void**)((char*)p+0x28));
    FUN_142639d10(p);
}

}}} // namespace
