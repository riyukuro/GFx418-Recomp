// Recovered Scaleform GFx 4.1.18 video glue from the executable (own source, SDK material is reference only): the AS2
// and AS3 video support objects (CreateInstance, CreateASCharacter, RegisterASClasses, scalar deleting destructors) and
// the handful of ASString-keyed hash / GC pointer helpers their registration code instantiates.
// The Video add-on lib was built with VS2012 Update 4, and so is this unit (MS2-TOOLSET: vc11,
// cmake/ms2-unit-profiles.cmake): no alias `using` (so ExeDecl is a struct), explicit conversion operators or variadic
// templates. clang-cl compiles it as before.
// MS2-UNIT: sfr_video_04
// MS2-TOOLSET: vc11
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140001690-0x140002780 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/gfx/gfx_input.h"
#include "../include/video/video_video.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_hash.h"
#include "../include/render/render_font.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_asstring.h"
#include "../include/gfx/gfx_resource.h"
#include <cstdint>
#include <new>

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> struct ExeDecl { typedef T type; };

using namespace Scaleform;
using namespace Scaleform::GFx;
using namespace Scaleform::GFx::Video;

// ---- exe callees outside this unit ----
ExeDecl<void(void*)>::type FUN_1425925f0;                       // GC object: release tail
ExeDecl<char(void*, std::uint64_t)>::type FUN_142592950;        // ArrayPaged: grow to hold a page index
ExeDecl<void(void*, void*, void*, unsigned)>::type FUN_142591a00;   // hash: add {key, value} at a hash code
ExeDecl<void(void*, void*, void*)>::type FUN_1425916c0;        // registers the first builtin
ExeDecl<char*(void*)>::type FUN_1429561c0;                          // GlobalContext::GetStringManager(this = context): the builtin name table
ExeDecl<void(void*)>::type FUN_1429260b0;                       // AS2 value destructor
ExeDecl<InteractiveObject*(void*, void*, MovieDefImpl*, ASMovieRootBase*, InteractiveObject*, const ResourceId*)>::type FUN_140010000;   // the video character constructor
ExeDecl<void*(void*, InteractiveObject*)>::type FUN_14000e2b0;          // the AVM video character constructor
ExeDecl<void*(void*, InteractiveObject*)>::type FUN_14001af70;     // the AS3 AVM video character constructor
#define FUN_14001af70_ctor FUN_14001af70
ExeDecl<void*(void*, void*)>::type FUN_1400126f0;
ExeDecl<void*(void*, void*)>::type FUN_14000cf20;
ExeDecl<void*(void*, void*)>::type FUN_14000ed60;
ExeDecl<void(void*, void*, void*)>::type FUN_140001270;           // AS2VideoSupport::AttachAudio
#ifndef MS2_HOOK_DLL   // the hook DLL's ms2sym.obj already maps this name to the exe address (alternatename conflict)
#pragma comment(linker, "/alternatename:?FUN_140001270@@YAXPEAX00@Z=?AttachAudio@AS2VideoSupportImpl@@UEAAXPEAVObject@AS2@GFx@Scaleform@@PEAVSprite@45@@Z")   // sfr36: full-exe link
#endif
ExeDecl<void(void*, void*)>::type FUN_1425210d0;                   // AS3 class registration
extern ExeDecl<void*>::type DAT_1431b7b50;                             // AS3 ClassInfo (data_rdata_sf_video)
extern ExeDecl<void*>::type DAT_1431b7160;                             // AS3 ClassInfo (data_rdata_sf_video)
// The module's null-terminated AS3 class info table the VM registers (exe .data 0x143a462f0: { &DAT_1431b7b50,
// &DAT_1431b7160, 0 }). Filled at run time: the hook DLL cannot take exe addresses in static data.
const void* DAT_143a462f0[3];

namespace
{
// GC counted script object (the AS2 / AS3 collector keeps a 26 bit count at +0x18 and the collector flags above it).
struct Video04GcObject
{
    unsigned char Reserved[0x18];
    unsigned      RefCount;
};

inline void Video04GcAddRef(Video04GcObject* p)
{
    if (p)
        p->RefCount = (p->RefCount + 1) & 0x8fffffff;
}

inline void Video04GcRelease(Video04GcObject* p)
{
    if (p && (p->RefCount & 0x3ffffff) != 0)
    {
        p->RefCount = p->RefCount - 1;
        FUN_1425925f0(p);
    }
}

// Entry of an ASString keyed hash with a GC value: chain link, key string node, value (0x20 bytes, table header 0x10).
struct Video04HashEntry
{
    std::int64_t    NextInChain;   // -2 empty, -1 end of chain
    ASStringNode*   Key;
    std::uint64_t   Reserved;
    Video04GcObject* Value;
};

struct Video04HashTable
{
    std::uint64_t    EntryCount;
    std::uint64_t    SizeMask;
    Video04HashEntry Entries[1];
};

typedef Video04HashTable* Video04Hash;   // the hash object is the one table pointer

// A GC value slot with its key: Ptr<GcObject> + ASString kept together (assignment helper of the registration code).
struct Video04Pair
{
    ASStringNode*    Key;
    Video04GcObject* Value;
};

// The AS2 global context: the class hash at +0x20, the global object at +0x60.
struct Video04Member
{
    void** VTable;
};

struct Video04Global
{
    unsigned char Reserved[0x20];
    Video04Member Members;         // +0x20 the global object's member table (object with a vtable)
};

struct Video04Context
{
    unsigned char Reserved[0x20];
    Video04Hash   Classes;         // +0x20
    unsigned char Reserved2[0x38];
    Video04Global* Global;         // +0x60
};

struct Video04ArrayPaged
{
    unsigned char Reserved[8];
    std::uint64_t Size;            // +0x08 element count
    std::uint64_t PageCount;       // +0x10
    unsigned char Reserved2[8];
    void***       Pages;           // +0x20
};
}

// ---- the AS2 / AS3 video support objects ----

// The AS2 side: a bare ref counted object (0x10 bytes) whose vtable is built in this unit.
class AS2VideoSupportImpl : public AS2VideoSupport
{
public:
    virtual ~AS2VideoSupportImpl() {}
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl);
    virtual void               RegisterASClasses(AS2::GlobalContext& gc, ASStringContext& sc);
    virtual void               AttachAudio(AS2::Object* pnetStream, Sprite* pchar);
};

// The AS3 side.
class AS3VideoSupportImpl : public AS3VideoSupport
{
public:
    virtual ~AS3VideoSupportImpl() {}
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl);
    virtual void               RegisterASClasses(AS3::VM* pvm);
};

// MS2-FUNCTIONAL: creates the AS2 video support object in the global heap.
// @0x1400019f0
AS2VideoSupport* AS2VideoSupport::CreateInstance()
{
    return SF_HEAP_NEW(Memory::pGlobalHeap) AS2VideoSupportImpl;
}

// MS2-FUNCTIONAL: creates the AS3 video support object in the global heap.
// @0x140002730
AS3VideoSupport* AS3VideoSupport::CreateInstance()
{
    return SF_HEAP_NEW(Memory::pGlobalHeap) AS3VideoSupportImpl;
}

// MS2-FUNCTIONAL: allocates the 0x160 byte AS2 video character in the movie heap and constructs it and its AVM part.
// @0x140001690
DisplayObjectBase* AS2VideoSupportImpl::CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef,
                                                          InteractiveObject* pparent, ResourceId rid,
                                                          MovieDefImpl* pbindDefImpl)
{
    char* pmem = (char*)proot->pHeap->Alloc(0x160, (const AllocInfo*)0);
    InteractiveObject* pobj = 0;
    if (pmem)
    {
        ResourceId localId = rid;
        pobj = FUN_140010000(pmem, pcharDef, pbindDefImpl, proot->pASMovieRoot, pparent, &localId);
    }
    if (pmem + 0x110 != 0)
        FUN_14000e2b0(pmem + 0x110, pobj);
    return (DisplayObjectBase*)pobj;
}

// MS2-FUNCTIONAL: allocates the 0x168 byte AS3 video character in the movie heap and constructs it and its AVM part.
// @0x140002560
DisplayObjectBase* AS3VideoSupportImpl::CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef,
                                                          InteractiveObject* pparent, ResourceId rid,
                                                          MovieDefImpl* pbindDefImpl)
{
    char* pmem = (char*)proot->pHeap->Alloc(0x168, (const AllocInfo*)0);
    InteractiveObject* pobj = 0;
    if (pmem)
    {
        ResourceId localId = rid;
        pobj = FUN_140010000(pmem, pcharDef, pbindDefImpl, proot->pASMovieRoot, pparent, &localId);
    }
    if (pmem + 0x110 != 0)
        FUN_14001af70_ctor(pmem + 0x110, pobj);
    return (DisplayObjectBase*)pobj;
}

// MS2-FUNCTIONAL: the AS3 registration is one call that hands the VM this module's class info table
// (lea rdx, 0x143a462f0: the table's address, not a pointer stored there).
void AS3VideoSupportImpl::RegisterASClasses(AS3::VM* pvm)
{
    DAT_143a462f0[0] = &DAT_1431b7b50;
    DAT_143a462f0[1] = &DAT_1431b7160;
    FUN_1425210d0(pvm, (void*)DAT_143a462f0);
}

// MS2-FUNCTIONAL: AttachAudio is the exe's 0x140001270 (forwards to the video object).
void AS2VideoSupportImpl::AttachAudio(AS2::Object* pnetStream, Sprite* pchar)
{
    FUN_140001270(this, pnetStream, pchar);
}

// ---- GC pointer and ASString hash helpers ----

// MS2-FUNCTIONAL: slot of an ArrayPaged (page of 1024 pointers): returns the element address, growing the page table.
// @0x140001870
void* FUN_140001870(Video04ArrayPaged* array)
{
    std::uint64_t index = array->Size >> 10;
    if (array->PageCount <= index)
    {
        if (!FUN_142592950(array, index))
            return 0;
    }
    return (char*)array->Pages[index] + (std::uint64_t)(array->Size & 0x3ff) * 8;
}

// MS2-FUNCTIONAL: finds the entry holding the key in a hash with GC values; returns its index or -1.
// @0x140001a30
std::uint64_t FUN_140001a30(Video04Hash* hash, ASStringNode** key, std::uint64_t index)
{
    Video04HashTable* table = *hash;
    Video04HashEntry* entry = &table->Entries[index];
    if (entry->NextInChain != -2 && (std::uint64_t)(entry->Key->HashFlags & table->SizeMask) == index)
    {
        std::uint64_t at = index;
        for (;;)
        {
            if ((std::uint64_t)(entry->Key->HashFlags & table->SizeMask) == index && entry->Key == *key)
                return at;
            at = (std::uint64_t)entry->NextInChain;
            if (at == 0xffffffffffffffffull)
                break;
            entry = &table->Entries[at];
        }
    }
    return 0xffffffffffffffffull;
}

// MS2-FUNCTIONAL: returns the address of the pair stored for the key, or 0.
// @0x140001ad0
void* FUN_140001ad0(Video04Hash* hash, ASStringNode** key)
{
    Video04HashTable* table = *hash;
    if (table)
    {
        std::int64_t at = (std::int64_t)FUN_140001a30(hash, key, (*key)->HashFlags & table->SizeMask);
        if (-1 < at)
            return (char*)table + at * 0x20 + 0x18;
    }
    return 0;
}

// MS2-FUNCTIONAL: assigns a GC pointer (adds the new reference, releases the old one).
// @0x140001b10
Video04GcObject** FUN_140001b10(Video04GcObject** dst, Video04GcObject** src)
{
    Video04GcAddRef(*src);
    Video04GcRelease(*dst);
    *dst = *src;
    return dst;
}

// MS2-FUNCTIONAL: releases a GC pointer.
// @0x140001b70
void FUN_140001b70(Video04GcObject** p)
{
    Video04GcRelease(*p);
}

// MS2-FUNCTIONAL: releases the GC pointer held in the second word of a pair.
// @0x140001ba0
void FUN_140001ba0(char* pair)
{
    Video04GcRelease(*(Video04GcObject**)(pair + 8));
}

// MS2-FUNCTIONAL: returns the value part (the address 8 bytes into the pair) stored for the key, or 0.
// The parameters are plain pointers so the definition has external linkage: the AS2 units call it as
// ASStringHash<ClassRegEntry>::Get (hash, const ASString& key).
// @0x140001bd0
void* FUN_140001bd0(void* phash, void* pkey)
{
    Video04Hash*      hash  = static_cast<Video04Hash*>(phash);
    ASStringNode**    key   = static_cast<ASStringNode**>(pkey);
    Video04HashTable* table = *hash;
    if (table)
    {
        std::int64_t at = (std::int64_t)FUN_140001a30(hash, key, (*key)->HashFlags & table->SizeMask);
        if (-1 < at)
        {
            char* pair = (char*)table + at * 0x20 + 0x18;
            if (pair != 0)
                return pair + 8;
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: assigns a {key node, GC value} pair.
// @0x140001c20
Video04Pair* FUN_140001c20(Video04Pair* dst, Video04Pair* src)
{
    dst->Key = src->Key;
    Video04GcAddRef(src->Value);
    Video04GcRelease(dst->Value);
    dst->Value = src->Value;
    return dst;
}

// MS2-FUNCTIONAL: destroys a pair held as {key node, ?, GC value}.
// @0x140001c80
void FUN_140001c80(std::int64_t* p)
{
    Video04GcRelease((Video04GcObject*)p[2]);
    ((ASStringNode*)p[0])->Release();
}

// MS2-FUNCTIONAL: scalar deleting form of the above.
// @0x140001cf0
std::int64_t* FUN_140001cf0(std::int64_t* p, unsigned flags)
{
    Video04GcRelease((Video04GcObject*)p[2]);
    ((ASStringNode*)p[0])->Release();
    if (flags & 1)
        operator delete(p);
    return p;
}

// MS2-FUNCTIONAL: frees a hash slot: drops the GC value and key and marks the slot freed (-2 stored as 0xff..fe).
// @0x140001de0
void FUN_140001de0(std::int64_t* slot)
{
    Video04GcRelease((Video04GcObject*)slot[3]);
    ((ASStringNode*)slot[1])->Release();
    slot[0] = -2;
}

// @0x140001e30
void FUN_140001e30(std::int64_t* slot)
{
    Video04GcRelease((Video04GcObject*)slot[3]);
    ((ASStringNode*)slot[1])->Release();
    slot[0] = -2;
}

// MS2-FUNCTIONAL: clears a hash with GC values: frees every used slot, then returns the table to the global heap.
// @0x140001f40
void FUN_140001f40(Video04Hash* hash)
{
    Video04HashTable* table = *hash;
    if (table)
    {
        std::int64_t count = (std::int64_t)table->SizeMask + 1;
        for (std::int64_t i = 0; count != 0; ++i, --count)
        {
            Video04HashEntry* entry = &(*hash)->Entries[i];
            if (entry->NextInChain != -2)
            {
                Video04GcRelease(entry->Value);
                entry->Key->Release();
                entry->NextInChain = -2;
            }
        }
        Memory::pGlobalHeap->Free(*hash);
        *hash = 0;
    }
}

// @0x140001ff0
void FUN_140001ff0(Video04Hash* hash)
{
    FUN_140001f40(hash);
}

// MS2-FUNCTIONAL: adds {key, value} to the hash at the key's hash code.
// @0x1400020d0
void FUN_1400020d0(void* hash, ASStringNode** key, void* value)
{
    struct { ASStringNode** Key; void* Value; } pair = {key, value};
    FUN_142591a00(hash, hash, &pair, (*key)->HashFlags);
}

// MS2-FUNCTIONAL: registers one builtin: looks the builtin's name up in the context's class hash and, when it is not
// registered yet, builds its prototype with the supplied callback and stores it on the global object.
static void Video04RegisterBuiltin(Video04Context* context, void* sc, Video04Global* global, size_t nameOffset, void* (*builder)(void*, void*))
{
    char* builtins = FUN_1429561c0(context);
    Video04Hash* hash = &context->Classes;
    ASStringNode** name = (ASStringNode**)(builtins + nameOffset);
    if (*hash)
    {
        std::int64_t at = (std::int64_t)FUN_140001a30(hash, name, (*name)->HashFlags & (*hash)->SizeMask);
        if (-1 < at)
        {
            char* pair = (char*)*hash + at * 0x20 + 0x18;
            if (pair != 0 && pair != (char*)-8)
                return;
        }
    }
    struct { void* Builder; Video04GcObject* Value; } proto = {(void*)builder, 0};
    struct { ASStringNode** Key; void* Value; } keyValue = {name, &proto};
    FUN_142591a00(hash, hash, &keyValue, (*name)->HashFlags);
    Video04GcRelease(proto.Value);
    unsigned char flags = 0;
    struct { std::uint64_t Tag; ASStringNode* Name; } member;
    member.Tag = 0xb;
    member.Name = *name;
    ((unsigned*)((char*)member.Name + 0x18))[0] += 1;
    void** vtable = global->Members.VTable;
    ((void (*)(void*, void*, void*, void*, void*))vtable[10])(&global->Members, sc, name, &member, &flags);
    FUN_1429260b0(&member);
}

// @0x140002100
void FUN_140002100(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x110, &FUN_1400126f0);
}

// @0x140002240
void FUN_140002240(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x118, &FUN_14000cf20);
}

// @0x140002380
void FUN_140002380(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x120, &FUN_14000ed60);
}

// MS2-FUNCTIONAL: the AS2 registration: the base builtin and the three video builtins on the global object.
// @0x1400024c0
void AS2VideoSupportImpl::RegisterASClasses(AS2::GlobalContext& gc, ASStringContext& sc)
{
    Video04Context* context = (Video04Context*)&gc;
    Video04Global* global = context->Global;
    FUN_1425916c0(context, &sc, global);
    FUN_140002100(context, &sc, global);
    FUN_140002240(context, &sc, global);
    FUN_140002380(context, &sc, global);
}

// MS2-FUNCTIONAL: the exe's scalar deleting destructors of the video support classes skip the vptr stores and the
// intermediate base destructors (one RefCountNTSImplCore destructor call, then the heap free); ours go through the chain.
// MS2-PIN: ??_G?$RefCountBaseNTS@VAS2VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x140001750
// MS2-FUNCTIONAL 0x140001750: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_GAS2VideoSupport@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x140001930
// MS2-FUNCTIONAL 0x140001930: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_GAS2VideoSupportImpl@@UEAAPEAXI@Z 0x1400019b0
// MS2-FUNCTIONAL 0x1400019b0: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_G?$RefCountBaseNTS@VAS3VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x140002620
// MS2-FUNCTIONAL 0x140002620: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_GAS3VideoSupport@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x140002680
// MS2-FUNCTIONAL 0x140002680: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_GAS3VideoSupportImpl@@UEAAPEAXI@Z 0x1400026f0
// MS2-FUNCTIONAL 0x1400026f0: the exe's deleting destructor skips the vptr stores and the base destructor chain (one RefCountNTSImplCore dtor call, then the heap free); ours runs the chain
// MS2-PIN: ??_7?$RefCountBaseNTS@VAS2VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4a88
// MS2-PIN: ??_7AS2VideoSupport@Video@GFx@Scaleform@@6B@ 0x1431b4a90
// MS2-PIN: ??_7AS2VideoSupportImpl@@6B@ 0x1431b4ab0
// MS2-PIN: ??_7?$RefCountBaseNTS@VAS3VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4ad0
// MS2-PIN: ??_7AS3VideoSupport@Video@GFx@Scaleform@@6B@ 0x1431b4ad8
// MS2-PIN: ??_7AS3VideoSupportImpl@@6B@ 0x1431b4af0
