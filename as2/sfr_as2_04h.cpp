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
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_asstring.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/kernel/sf_arraypaged.h"

void FUN_14257dcd0(void* p);  // global in the exe

void FUN_1424a9ed0(void*);   // global, defined in sfr_as3_12
void FUN_14000b080(void** table);  // global, defined in sfr_video_01

namespace Scaleform {
// Out of line in the exe; the explicit-specialization declarations keep the dtors uninlined.
typedef ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, 327>, ArrayDefaultPolicy> Sfr04hArrStr;
typedef ArrayDataBase<GFx::AS2::AsFunctionObject::ArgSpec, AllocatorLH<GFx::AS2::AsFunctionObject::ArgSpec, 323>,
    ArrayDefaultPolicy> Sfr04hArrArg;
typedef HashNode<GFx::ASString, char, GFx::ASStringHashFunctor> Sfr04hHN1;
typedef HashSetBase<Sfr04hHN1, Sfr04hHN1::NodeHashF, Sfr04hHN1::NodeAltHashF, AllocatorLH<GFx::ASString, 324>,
    HashsetNodeEntry<Sfr04hHN1, Sfr04hHN1::NodeHashF> > Sfr04hHashChar;
typedef HashNode<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor> Sfr04hHN2;
typedef HashSetBase<Sfr04hHN2, Sfr04hHN2::NodeHashF, Sfr04hHN2::NodeAltHashF, AllocatorLH<GFx::ASString, 324>,
    HashsetNodeEntry<Sfr04hHN2, Sfr04hHN2::NodeHashF> > Sfr04hHashFn;
typedef HashNode<GFx::ASString, GFx::AS2::Value, GFx::ASStringHashFunctor> Sfr04hHN3;
typedef HashSetBase<Sfr04hHN3, Sfr04hHN3::NodeHashF, Sfr04hHN3::NodeAltHashF, AllocatorLH<GFx::ASString, 324>,
    GFx::HashsetNodeEntry_GC<Sfr04hHN3, Sfr04hHN3::NodeHashF> > Sfr04hHashVal;
typedef HashNode<GFx::EventId, ArrayLH<GFx::AS2::Value, 323, ArrayDefaultPolicy>, GFx::EventIdHashFunctor> Sfr04hHN4;
typedef HashSetBase<Sfr04hHN4, Sfr04hHN4::NodeHashF, Sfr04hHN4::NodeAltHashF, AllocatorLH<GFx::EventId, 323>,
    HashsetCachedNodeEntry<Sfr04hHN4, Sfr04hHN4::NodeHashF> > Sfr04hHashEv;
template<> SF_NOINLINE Sfr04hArrStr::~ArrayDataBase();   // 0x14256a8e0
template<> SF_NOINLINE Sfr04hArrArg::~ArrayDataBase();   // 0x142924180
template<> SF_NOINLINE Sfr04hHashChar::~HashSetBase();   // 0x142924580
template<> SF_NOINLINE Sfr04hHashFn::~HashSetBase();     // 0x142924770
template<> SF_NOINLINE Sfr04hHashVal::~HashSetBase();    // 0x142924960
template<> SF_NOINLINE Sfr04hHashEv::~HashSetBase();     // 0x142924a20
}

namespace Scaleform { namespace GFx { namespace AS2 {

void FUN_1425925f0(void*);
void FUN_1429343f0(ArrayPagedLH_POD<unsigned, 6, 64, 2>* proots);
void FUN_140001f40(void*);
void FUN_142581700(void*);

static inline void rs(void* n) // ASString release
{
    unsigned* c = (unsigned*)((char*)n + 0x18);
    if (--*c == 0) static_cast<ASStringNode*>(n)->ReleaseNode();
}
static inline void rg(void* n) // Ptr<RefCountBaseGC> release
{
    unsigned* c = (unsigned*)((char*)n + 0x18);
    if (n && (*c & 0x3ffffff)) { --*c; FUN_1425925f0(n); }
}
static inline void rc(void* h) // Ptr<CharacterHandle> release
{
    int* c = (int*)h;
    if (h && --*c <= 0) { static_cast<CharacterHandle*>(h)->~CharacterHandle(); Memory::Free(h); }
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
    static_cast<RefCountCollector<StatMV_ActionScript_Mem>*>(p)->Collect(0);
    *(const void**)((char*)p+0x40) = DAT_143215370;
    FUN_1429343f0((ArrayPagedLH_POD<unsigned, 6, 64, 2>*)((char*)p+0x10));
    static_cast<RefCountImplCore*>((void*)(p))->RefCountImplCore::~RefCountImplCore();
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
    static_cast<RefCountCollector<StatMV_ActionScript_Mem>*>(p)->Collect(0);
    *(const void**)((char*)p+0x40) = DAT_143215370;
    FUN_1429343f0((ArrayPagedLH_POD<unsigned, 6, 64, 2>*)((char*)p+0x10));
    static_cast<RefCountImplCore*>((void*)(p))->RefCountImplCore::~RefCountImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x98);
    }
    return p;
}

// ActionBuffer::Dictionary (an ArrayCC<ASString>): the DefaultValue release is inlined, the ArrayDataBase dtor is not.
struct B142928e90 { void* D; UPInt S; UPInt C; ~B142928e90() { reinterpret_cast<Sfr04hArrStr*>(this)->~Sfr04hArrStr(); } };
struct DCC142928e90 : B142928e90 { ASString DefaultValue; };
// @0x142928e90
void* DeleteAs2_142928e90(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432153c8;
    ((DCC142928e90*)((char*)p+0x18))->~DCC142928e90();
    if (*(void**)((char*)p+0x10)) static_cast<RefCountImpl*>(*(void**)((char*)p+0x10))->Release();
    static_cast<RefCountNTSImplCore*>((void*)(p))->RefCountNTSImplCore::~RefCountNTSImplCore();
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
    reinterpret_cast<Sfr04hArrArg*>((char*)p+0xa0)->~Sfr04hArrArg();
    Memory::Free(*(void**)((char*)p+0x80));
    if (*(void**)((char*)p+0x78)) FUN_14257dcd0(*(void**)((char*)p+0x78));
    rc(*(void**)((char*)p+0x70));
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    static_cast<Object*>((void*)(p))->Object::~Object();
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
    reinterpret_cast<Sfr04hHashEv*>((char*)p+0x28)->~Sfr04hHashEv();
    static_cast<ObjectInterface*>((void*)((char*)p+0x8))->ObjectInterface::~ObjectInterface();
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
    reinterpret_cast<Sfr04hHashEv*>((char*)p+0x28)->~Sfr04hHashEv();
    static_cast<ObjectInterface*>((void*)((char*)p+0x8))->ObjectInterface::~ObjectInterface();
    *(const void**)p = DAT_14317bf80;
    if ((flags & 5) == 5)
        ::operator delete(p, 0x30);
    return p;
}

// @0x142929600
void* DeleteAs2_142929600(void* p, unsigned flags)
{
    *(const void**)p = DAT_143216338;
    *(const void**)((char*)p+0x8) = DAT_143216480;
    *(const void**)((char*)p+0x30) = DAT_143216528;
    ((ArrayLH<UInt32>*)((char*)p+0x1e0))->~ArrayLH(); // an array of POD elements (element type not recovered)
    rg(*(void**)((char*)p+0x1d8));
    reinterpret_cast<Environment*>((char*)p+0x38)->Environment::~Environment();
    *(const void**)p = DAT_143215b00;
    *(const void**)((char*)p+0x30) = DAT_14317bf80;
    *(const void**)((char*)p+0x8) = DAT_143215c48;
    reinterpret_cast<Sfr04hHashEv*>((char*)p+0x28)->~Sfr04hHashEv();
    static_cast<ObjectInterface*>((void*)((char*)p+0x8))->ObjectInterface::~ObjectInterface();
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
    reinterpret_cast<Sfr04hHashEv*>((char*)p+0x28)->~Sfr04hHashEv();
    static_cast<ObjectInterface*>((void*)((char*)p+0x8))->ObjectInterface::~ObjectInterface();
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
    ::FUN_1424a9ed0((char*)p+0x8);
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
    reinterpret_cast<Sfr04hHashChar*>((char*)p+0x70)->~Sfr04hHashChar();
    rg(*(void**)((char*)p+0x60));
    FUN_140001f40((char*)p+0x20);
    reinterpret_cast<Sfr04hHashFn*>((char*)p+0x18)->~Sfr04hHashFn();
    ::FUN_14000b080((void**)((char*)p+0x10));
    static_cast<RefCountNTSImplCore*>((void*)(p))->RefCountNTSImplCore::~RefCountNTSImplCore();
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
    reinterpret_cast<Sfr04hHashVal*>((char*)p+0x20)->~Sfr04hHashVal();
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

struct Q14292c3e0 { void* P; ~Q14292c3e0() { if (P) static_cast<RefCountImpl*>(P)->Release(); } };
struct B14292c3e0 { void* vp; void* rc; void* x10; Q14292c3e0 q; ~B14292c3e0() { vp = (void*)DAT_14317bde0; } };
struct P14292c3e0 { void* P; ~P14292c3e0() { if (P) FUN_14257dcd0(P); } };
// @0x14292c3e0
void* DeleteAs2_14292c3e0(void* p, unsigned flags)
{
    *(const void**)p = DAT_1432177d8;
    ((ArrayLH<P14292c3e0>*)((char*)p+0x628))->~ArrayLH();
    (*(ASStringManager**)((char*)p+0x618))->ReleaseBuiltinArray((ASStringNodeHolder*)((char*)p+0x138), 0x9c);
    ((MovieRoot::ActionQueueType*)((char*)p+0x80))->~ActionQueueType();
    ((Value*)((char*)p+0x58))->~Value();
    if (*(void**)((char*)p+0x50)) FUN_14257dcd0(*(void**)((char*)p+0x50));
    if (*(void**)((char*)p+0x38)) static_cast<RefCountImpl*>(*(void**)((char*)p+0x38))->Release();
    if (*(void**)((char*)p+0x30)) static_cast<RefCountImpl*>(*(void**)((char*)p+0x30))->Release();
    { char* e=*(char**)((char*)p+0x28); if (e && --*(long long*)(e+8)==0) FUN_142581700(e); }
    ((B14292c3e0*)p)->~B14292c3e0();
    static_cast<RefCountImplCore*>((void*)(p))->RefCountImplCore::~RefCountImplCore();
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
