// Recovered Scaleform GFx 4.1.18 video glue from the executable (own source, SDK material is reference only): the AS2
// and AS3 video support objects (CreateInstance, CreateASCharacter, RegisterASClasses, scalar deleting destructors) and
// the handful of ASString-keyed hash / GC pointer helpers their registration code instantiates.
// The exe links these from VS2008 objs, so this unit is built with the VS2008 SP1 cl and the vc11 options (MS2-TOOLSET:
// vc9v, cmake/ms2-unit-profiles.cmake): C++03 with compat.h, no alias `using` (so ExeDecl is a struct), explicit
// conversion operators or variadic templates. clang-cl compiles it as before.
// MS2-UNIT: sfr_video_04
// MS2-TOOLSET: vc9v
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
#include "../include/gfx/as2/as2_actiontypes.h"
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
namespace Scaleform { namespace GFx { namespace AS2 {
class AvmCharacter; class FunctionRef; class StringManager;
class GlobalContext { public: StringManager* GetStringManager() const; };
AvmCharacter* FUN_14000e2b0(AvmCharacter* character, InteractiveObject* displayObject);
FunctionRef FUN_14000cf20(GlobalContext* global);
} } }
struct Video04GcAccess : AS2::RefCountBaseGC<323> { using AS2::RefCountBaseGC<323>::ReleaseInternal; };
namespace Scaleform { namespace GFx { class Video02Character { public: Video02Character(void*, MovieDefImpl*, ASMovieRootBase*, InteractiveObject*, const ResourceId&); }; }}   // the video display object (sfr_video_02, an InteractiveObject); ctor 0x140010000
AS2::FunctionRef* FUN_1400126f0(AS2::FunctionRef* result, AS2::GlobalContext* context);
AS2::FunctionRef* FUN_14000ed60(AS2::FunctionRef* result, AS2::GlobalContext* context);
namespace Scaleform { namespace GFx {
void FUN_142591a00(UPInt** table, void* heapOwner, const void* keyValue, UPInt hashCode);   // hash: add {key, value} at a hash code
void FUN_1425916c0(void* context, void* sc, void* global);       // registers the first builtin
namespace AS3 { class VM; struct ClassInfo; void FUN_1425210d0(VM& vm, const ClassInfo* table[]); }   // AS3 class registration
} }
namespace Scaleform { namespace GFx { namespace AS2 {
class Value { public: ~Value(); };
template <int Stat> class RefCountCollector
{
public:
    struct RootArray { bool allocatePageSafe(UPInt index); };
};
} } }
namespace Scaleform { namespace GFx { namespace AS3 {   // ctor-only view of sfr_video_03's AS3 AVM video character
class AvmVideoCharacter { public: AvmVideoCharacter(InteractiveObject* pdispObj); }; }}}   // 0x14001af70
namespace Scaleform { namespace GFx { namespace AS2 {
class NetStream;
void FUN_140006ba0(NetStream* pnetStream, Sprite* pchar);         // sfr_video_01: NetStream's provider->SetAudioTarget
} } }
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
        reinterpret_cast<Video04GcAccess*>(p)->ReleaseInternal();
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
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl);
    virtual void               RegisterASClasses(AS2::GlobalContext& gc, ASStringContext& sc);
    virtual void               AttachAudio(AS2::Object* pnetStream, Sprite* pchar);
};

// The AS3 side.
class AS3VideoSupportImpl : public AS3VideoSupport
{
public:
    virtual DisplayObjectBase* CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef, InteractiveObject* pparent,
                                                 ResourceId rid, MovieDefImpl* pbindDefImpl);
    virtual void               RegisterASClasses(AS3::VM* pvm);
};

// creates the AS2 video support object in the global heap.
// @0x1400019f0
AS2VideoSupport* AS2VideoSupport::CreateInstance()
{
    return SF_HEAP_NEW(Memory::pGlobalHeap) AS2VideoSupportImpl;
}

// creates the AS3 video support object in the global heap.
// @0x140002730
AS3VideoSupport* AS3VideoSupport::CreateInstance()
{
    return SF_HEAP_NEW(Memory::pGlobalHeap) AS3VideoSupportImpl;
}

// allocates the 0x160 byte AS2 video character in the movie heap and constructs it and its AVM part.
// @0x140001690
DisplayObjectBase* AS2VideoSupportImpl::CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef,
                                                          InteractiveObject* pparent, ResourceId rid,
                                                          MovieDefImpl* pbindDefImpl)
{
    char* pmem = (char*)proot->pHeap->Alloc(0x160, (const AllocInfo*)0);
    InteractiveObject* pobj;
    if (pmem)
    {
        ResourceId localId = rid;
        pobj = reinterpret_cast<InteractiveObject*>(::new (pmem) Video02Character(pcharDef, pbindDefImpl, proot->pASMovieRoot, pparent, localId));
    }
    else
        pobj = 0;
    if (pmem + 0x110 != 0)
        AS2::FUN_14000e2b0(reinterpret_cast<AS2::AvmCharacter*>(pmem + 0x110), pobj);
    return (DisplayObjectBase*)pobj;
}

// allocates the 0x168 byte AS3 video character in the movie heap and constructs it and its AVM part.
// @0x140002560
DisplayObjectBase* AS3VideoSupportImpl::CreateASCharacter(MovieImpl* proot, CharacterDef* pcharDef,
                                                          InteractiveObject* pparent, ResourceId rid,
                                                          MovieDefImpl* pbindDefImpl)
{
    char* pmem = (char*)proot->pHeap->Alloc(0x168, (const AllocInfo*)0);
    InteractiveObject* pobj;
    if (pmem)
    {
        ResourceId localId = rid;
        pobj = reinterpret_cast<InteractiveObject*>(::new (pmem) Video02Character(pcharDef, pbindDefImpl, proot->pASMovieRoot, pparent, localId));
    }
    else
        pobj = 0;
    ::new (pmem + 0x110) AS3::AvmVideoCharacter(pobj);
    //
    return (DisplayObjectBase*)pobj;
}

// MS2-FUNCTIONAL: the AS3 registration is one call that hands the VM this module's class info table
// (lea rdx, 0x143a462f0: the table's address, not a pointer stored there).
void AS3VideoSupportImpl::RegisterASClasses(AS3::VM* pvm)
{
    DAT_143a462f0[0] = &DAT_1431b7b50;
    DAT_143a462f0[1] = &DAT_1431b7160;
    AS3::FUN_1425210d0(*pvm, (const AS3::ClassInfo**)DAT_143a462f0);
}

// forwards to the NetStream's video provider (exe 0x140006ba0).
void AS2VideoSupportImpl::AttachAudio(AS2::Object* pnetStream, Sprite* pchar)
{
    AS2::FUN_140006ba0(reinterpret_cast<AS2::NetStream*>(pnetStream), pchar);
}

// ---- GC pointer and ASString hash helpers ----

// slot of an ArrayPaged (page of 1024 pointers): returns the element address, growing the page table.
// @0x140001870
void* FUN_140001870(Video04ArrayPaged* array)
{
    std::uint64_t index = array->Size >> 10;
    if (index >= array->PageCount)
    {
        if (!reinterpret_cast<Scaleform::GFx::AS2::RefCountCollector<323>::RootArray*>(array)->allocatePageSafe(index))
            return 0;
    }
    return (char*)array->Pages[index] + (std::uint64_t)(array->Size & 0x3ff) * 8;
}

// finds the entry holding the key in a hash with GC values; returns its index or -1. As in SDK findIndexCore, the
// incoming index is also the hash value the chain entries are compared against, and the walk uses its own index
// @0x140001a30
std::uint64_t FUN_140001a30(Video04Hash* hash, ASStringNode** key, std::uint64_t index)
{
    Video04HashTable* table = *hash;
    std::uint64_t at = index;
    const Video04HashEntry* entry = &table->Entries[at];
    if (entry->NextInChain == -2 || (std::uint64_t)(entry->Key->HashFlags & table->SizeMask) != index)
        return 0xffffffffffffffffull;
    for (;;)
    {
        if ((std::uint64_t)(entry->Key->HashFlags & table->SizeMask) == index && entry->Key == *key)
            return at;
        at = (std::uint64_t)entry->NextInChain;
        if (at == 0xffffffffffffffffull)
            break;
        entry = &table->Entries[at];
    }
    return 0xffffffffffffffffull;
}

// returns the address of the pair stored for the key, or 0.
// @0x140001ad0
void* FUN_140001ad0(Video04Hash* hash, ASStringNode** key)
{
    Video04HashTable* table = *hash;
    if (table)
    {
        std::int64_t at = (std::int64_t)FUN_140001a30(hash, key, (*key)->HashFlags & table->SizeMask);
        if (at >= 0)
            return (char*)&table->Entries[at].Key;
    }
    return 0;
}

// assigns a GC pointer (adds the new reference, releases the old one).
// @0x140001b10
Video04GcObject** FUN_140001b10(Video04GcObject** dst, Video04GcObject** src)
{
    Video04GcAddRef(*src);
    Video04GcRelease(*dst);
    *dst = *src;
    return dst;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases a GC pointer.
// @0x140001b70
void FUN_140001b70(Video04GcObject** p)
{
    Video04GcRelease(*p);
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the GC pointer held in the second word of a pair.
// @0x140001ba0
void FUN_140001ba0(char* pair)
{
    Video04GcRelease(*(Video04GcObject**)(pair + 8));
}
#pragma optimize("", on)

// returns the value part (the address 8 bytes into the pair) stored for the key, or 0.
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
        if (at >= 0)
        {
            char* pair = (char*)&table->Entries[at].Key;
            if (pair != 0)
                return pair + 8;
        }
    }
    return 0;
}

// assigns a {key node, GC value} pair.
// @0x140001c20
Video04Pair* FUN_140001c20(Video04Pair* dst, Video04Pair* src)
{
    dst->Key = src->Key;
    Video04GcAddRef(src->Value);
    Video04GcRelease(dst->Value);
    dst->Value = src->Value;
    return dst;
}

// destroys a pair held as {key node, ?, GC value}.
// @0x140001c80
void FUN_140001c80(std::int64_t* p)
{
    Video04GcRelease((Video04GcObject*)p[2]);
    ((ASStringNode*)p[0])->Release();
}

// scalar deleting form of the above.
// @0x140001cf0
std::int64_t* FUN_140001cf0(std::int64_t* p, unsigned flags)
{
    Video04GcRelease((Video04GcObject*)p[2]);
    ((ASStringNode*)p[0])->Release();
    if (flags & 1)
        operator delete(p);
    return p;
}

// frees a hash slot: drops the GC value and key and marks the slot freed (-2 stored as 0xff..fe).
// @0x140001de0
void FUN_140001de0(std::int64_t* slot)
{
    Video04GcRelease((Video04GcObject*)slot[3]);
    ((ASStringNode*)slot[1])->Release();
    slot[0] = -2;
}

// same as 0x140001de0.
// @0x140001e30
void FUN_140001e30(std::int64_t* slot)
{
    Video04GcRelease((Video04GcObject*)slot[3]);
    ((ASStringNode*)slot[1])->Release();
    slot[0] = -2;
}

// clears a hash with GC values: frees every used slot, then returns the table to the global heap.
// The SDK form (i <= SizeMask) is what lets cl count down from SizeMask+1 with no zero test.
__forceinline void Video04ClearHash(Video04Hash* hash)
{
    Video04HashTable* table = *hash;
    if (table)
    {
        UPInt n = table->SizeMask;
        for (UPInt i = 0; i <= n; i++)
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

// clears the hash above. The parameter is a plain pointer so the definition has external linkage: the AS2 units
// call it on their own hash members.
// @0x140001f40
void FUN_140001f40(void* phash)
{
    Video04ClearHash(static_cast<Video04Hash*>(phash));
}

// same body as the above (the exe carries a second full copy).
// @0x140001ff0
void FUN_140001ff0(Video04Hash* hash)
{
    Video04ClearHash(hash);
}

// adds {key, value} to the hash at the key's hash code.
// @0x1400020d0
void FUN_1400020d0(void* hash, ASStringNode** key, void* value)
{
    struct { ASStringNode** Key; void* Value; } pair;
    pair.Value = value;
    pair.Key = key;
    FUN_142591a00((UPInt**)hash, hash, &pair, (*key)->HashFlags);
}

// registers one builtin: looks the builtin's name up in the context's class hash and, when it is not
// registered yet, builds its prototype with the supplied callback and stores it on the global object.
// The builtin name is fetched again at every use (GetStringManager is the context's builtin table getter).
#define VIDEO04_NAME(context, nameOffset) ((ASStringNode**)((char*)reinterpret_cast<AS2::GlobalContext*>(context)->GetStringManager() + (nameOffset)))

// A Value holding a string (tag byte 0xb, the node at +8).
struct Video04StringValue
{
    unsigned char Tag;
    ASStringNode* Name;
    Video04StringValue(ASStringNode** name) : Tag(0xb), Name(*name) { Name->RefCount++; }
};

__forceinline void* Video04HashGet(Video04Hash* hash, ASStringNode** key)
{
    Video04HashTable* table = *hash;
    if (table)
    {
        std::int64_t at = (std::int64_t)FUN_140001a30(hash, key, (*key)->HashFlags & table->SizeMask);
        if (at >= 0)
        {
            char* pair = (char*)&table->Entries[at].Key;
            if (pair != 0)
                return pair + 8;
        }
    }
    return 0;
}

__forceinline void Video04RegisterBuiltin(Video04Context* context, void* sc, Video04Global* global, size_t nameOffset, void* (*builder)(void*, void*))
{
    if (Video04HashGet(&context->Classes, VIDEO04_NAME(context, nameOffset)))
        return;
    {
        struct { void* Builder; Video04GcObject* Value; } proto = {(void*)builder, 0};
        struct { ASStringNode** Key; void* Value; } keyValue = {VIDEO04_NAME(context, nameOffset), &proto};
        FUN_142591a00((UPInt**)&context->Classes, &context->Classes, &keyValue, (*keyValue.Key)->HashFlags);
        Video04GcRelease(proto.Value);
    }
    unsigned char flags = 0;
    Video04StringValue member(VIDEO04_NAME(context, nameOffset));
    void** vtable = global->Members.VTable;
    ((void (*)(void*, void*, void*, void*, void*))vtable[10])(&global->Members, sc, VIDEO04_NAME(context, nameOffset), &member, &flags);
    reinterpret_cast<Scaleform::GFx::AS2::Value*>(&member)->~Value();
}

// MS2-FUNCTIONAL: registers the video builtin (exe codegen is cl 15: r12 for sc, null-tested &Entries[at], shared
// stack slot for the key pair and the member value; cl 17 does not emit it).
// @0x140002100
void FUN_140002100(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x110, reinterpret_cast<void*(*)(void*, void*)>(&FUN_1400126f0));
}

// MS2-FUNCTIONAL: as 0x140002100 for the next builtin.
// @0x140002240
void FUN_140002240(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x118, reinterpret_cast<void*(*)(void*, void*)>(&AS2::FUN_14000cf20));
}

// MS2-FUNCTIONAL: as 0x140002100 for the next builtin.
// @0x140002380
void FUN_140002380(Video04Context* context, void* sc, Video04Global* global)
{
    Video04RegisterBuiltin(context, sc, global, 0x120, reinterpret_cast<void*(*)(void*, void*)>(&FUN_14000ed60));
}

// the AS2 registration: the base builtin and the three video builtins on the global object (gc.Global reread for each).
// @0x1400024c0
void AS2VideoSupportImpl::RegisterASClasses(AS2::GlobalContext& gc, ASStringContext& sc)
{
    Video04Context* context = (Video04Context*)&gc;
    FUN_1425916c0(context, &sc, context->Global);
    FUN_140002100(context, &sc, context->Global);
    FUN_140002240(context, &sc, context->Global);
    FUN_140002380(context, &sc, context->Global);
}

// The scalar deleting destructors are implicit (no vptr stores in the exe).
// MS2-PIN: ??_G?$RefCountBaseNTS@VAS2VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x140001750
// MS2-PIN: ??_GAS2VideoSupport@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x140001930
// MS2-PIN: ??_GAS2VideoSupportImpl@@UEAAPEAXI@Z 0x1400019b0
// MS2-PIN: ??_G?$RefCountBaseNTS@VAS3VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x140002620
// MS2-PIN: ??_GAS3VideoSupport@Video@GFx@Scaleform@@UEAAPEAXI@Z 0x140002680
// MS2-PIN: ??_GAS3VideoSupportImpl@@UEAAPEAXI@Z 0x1400026f0
// MS2-PIN: ??_7?$RefCountBaseNTS@VAS2VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4a88
// MS2-PIN: ??_7AS2VideoSupport@Video@GFx@Scaleform@@6B@ 0x1431b4a90
// MS2-PIN: ??_7AS2VideoSupportImpl@@6B@ 0x1431b4ab0
// MS2-PIN: ??_7?$RefCountBaseNTS@VAS3VideoSupport@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4ad0
// MS2-PIN: ??_7AS3VideoSupport@Video@GFx@Scaleform@@6B@ 0x1431b4ad8
// MS2-PIN: ??_7AS3VideoSupportImpl@@6B@ 0x1431b4af0
