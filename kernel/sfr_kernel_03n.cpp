// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 COMDAT leftovers of the memory
// report (MemItem) and the AMP movie image objects that sfr_as3_22 builds: the deleting destructors behind the
// one-slot vftables 0x143192160-0x1431921e0, and the per-movie summary that groups a movie's image records by key.
// Raw-layout free functions under the exe's own FUN_<va> names (the exe's COMDATs are RTTI-less). Our own source,
// written from the exe.
// Sub-unit of queue unit sfr_kernel_03.
// MS2-UNIT: sfr_kernel_03n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142688f50-0x1426899e0 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include <intrin.h>
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_hash.h"
void __empty_global_delete(void*, size_t);   // the sized operator delete the compiler pairs with ::new

namespace Scaleform { namespace GFx {

extern "C" void* const DAT_143192190[1];   // vftable of the summary object (defined below its deleting destructor)

void FUN_14261f8b0(U*);                             // Hash<key8, 0x20-byte value>::Clear
void FUN_14261f940(U*);                             // Hash<ResourceId, StringLH>::Clear
extern "C" void FUN_142687170(void*);               // ~ the record's hash at +0x40
// Name-only views of the AMP types (Amp_ProfileFrame.h): the full SDK classes (RefCountBase types with inline ctors)
// make cl define __empty_global_delete in this TU and fold the deleting destructors' sized-delete calls.
namespace AMP {
struct MovieFunctionStats { struct FuncStats { UInt64 FunctionId; UInt64 CallerId; UInt32 TimesCalled; UInt64 TotalTime; }; };
struct FunctionDesc;
struct FunctionTreeVisitor;
class FuncTreeItem { public: template<typename T> void Visit(T& visitor); };
}
} // namespace GFx
// The AMP hash COMDATs of MovieFunctionTreeStats::Accumulate, defined in sfr_as3_22 (FunctionTreeVisitor::FuncMap,
// MovieFunctionTreeStats::FunctionInfo).
typedef Hash<UInt64, GFx::AMP::MovieFunctionStats::FuncStats> Sfr03nFuncStatsHash;
typedef decltype(Sfr03nFuncStatsHash::mHash)::BaseType Sfr03nFuncStatsSet;
typedef decltype(HashLH<UInt64, Ptr<GFx::AMP::FunctionDesc> >::mHash)::BaseType Sfr03nFunctionDescSet;
template<> void Sfr03nFunctionDescSet::Assign(void* pmemAddr, const Sfr03nFunctionDescSet& src);    // 0x142689aa0
template<> template<> Sfr03nFuncStatsSet::Iterator Sfr03nFuncStatsSet::FindAlt<UInt64>(const UInt64& key);   // 0x14268a450
template<> void Sfr03nFuncStatsHash::Add(const UInt64& key, const GFx::AMP::MovieFunctionStats::FuncStats& value); // 0x1426899e0
template<> Sfr03nFuncStatsSet::~HashSetBase();                                                       // 0x1426871f0
template<> void GFx::AMP::FuncTreeItem::Visit<GFx::AMP::FunctionTreeVisitor>(GFx::AMP::FunctionTreeVisitor& visitor); // 0x142686440
namespace GFx {
typedef ArrayDataBase<AMP::MovieFunctionStats::FuncStats, AllocatorLH<AMP::MovieFunctionStats::FuncStats, 2>, ArrayDefaultPolicy> Sfr03nFuncStatsArr; } template<> void GFx::Sfr03nFuncStatsArr::Reserve(const void*, UPInt); namespace GFx { static __forceinline void FUN_142623bc0(U* a, void* o, U n) { reinterpret_cast<Sfr03nFuncStatsArr*>(a)->Reserve(o, n); }   // (C3) = Array<FuncStats>::Reserve (0x142623bc0, sfr_gfx_07i; name-only view of FuncStats)

// The RefCount base calls, made directly as the exe makes them.
static inline void RawRefCountRelease(void* p)
{
    static_cast<RefCountImpl*>(p)->Release();
}

static inline void RawDeleteBranch(void* self, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            __empty_global_delete(self, size);
    }
}

// ArrayLH<Ptr<T>> at off: released back to front, then the buffer.
static inline void RawReleasePtrArray(void* self, UPInt off)
{
    U n = RawField<U>(self, off + 8);
    void** p = RawField<void**>(self, off) + n - 1;
    for (U i = 0; i < n; ++i, --p)
    {
        if (*p)
            RawRefCountRelease(*p);
    }
    Memory::Free(RawField<void*>(self, off));
}

static inline void RawReleasePtr(void* self, UPInt off)
{
    if (RawField<void*>(self, off))
        RawRefCountRelease(RawField<void*>(self, off));
}

// String/StringLH at off: counted buffer (low two bits are tag bits, count at +8 of the buffer).
static inline void RawReleaseString(void* self, UPInt off)
{
    char* buffer = (char*)(RawField<U>(self, off) & ~(U)3);
    if (_InterlockedDecrement((volatile long*)(buffer + 8)) == 0)
        Memory::Free(buffer);
}

// MemItem: Children +0x30, ImageExtraData +0x28, Name +0x10.
// @0x142688f50
void* FUN_142688f50(void* self, unsigned flags)
{
    RawReleasePtrArray(self, 0x30);
    RawReleasePtr(self, 0x28);
    RawReleaseString(self, 0x10);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x48);
    return self;
}

// Summary object (vftable 0x143192190): entries array +0x10, keyed hash +0x28.
// @0x142689030
void* FUN_142689030(void* self, unsigned flags)
{
    FUN_14261f8b0(RawFieldPtr<U>(self, 0x28));
    Memory::Free(RawField<void*>(self, 0x10));
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x30);
    return self;
}

// The summary object's one-slot vftable (RTTI-less, packed with the MemItem ones 0x143192160-0x1431921e0); no
// recovered class emits it, so it is defined here (the hook DLL binds the name to the exe's table).
extern "C" void* const DAT_143192190[1] = { (void*)&FUN_142689030 };

// Tree node (vftable 0x143192180): name +0x10, children +0x18, keyed hash +0x30.
// @0x1426890b0
void* FUN_1426890b0(void* self, unsigned flags)
{
    FUN_14261f8b0(RawFieldPtr<U>(self, 0x30));
    RawReleasePtrArray(self, 0x18);
    RawReleaseString(self, 0x10);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x38);
    return self;
}

// Pointer list (vftable 0x143192170): array +0x10.
// @0x142689180
void* FUN_142689180(void* self, unsigned flags)
{
    RawReleasePtrArray(self, 0x10);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x28);
    return self;
}

// Image record (vftable 0x1431921b0): name +0x20, children +0x40, four counted pointers +0x58-+0x70.
// @0x142689230
void* FUN_142689230(void* self, unsigned flags)
{
    RawReleasePtr(self, 0x70);
    RawReleasePtr(self, 0x68);
    RawReleasePtr(self, 0x60);
    RawReleasePtr(self, 0x58);
    RawReleasePtrArray(self, 0x40);
    RawReleaseString(self, 0x20);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x78);
    return self;
}

// Name set (vftable 0x1431921a0): array +0x10, Hash<ResourceId, StringLH> +0x28.
// @0x142689330
void* FUN_142689330(void* self, unsigned flags)
{
    FUN_14261f940(RawFieldPtr<U>(self, 0x28));
    Memory::Free(RawField<void*>(self, 0x10));
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x30);
    return self;
}

// Movie record (vftable 0x1431921d0).
// @0x1426893b0
void* FUN_1426893b0(void* self, unsigned flags)
{
    RawReleasePtrArray(self, 0x140);
    RawReleasePtr(self, 0x138);
    RawReleasePtr(self, 0x130);
    RawReleasePtr(self, 0x128);
    Memory::Free(RawField<void*>(self, 0x110));
    Memory::Free(RawField<void*>(self, 0xf8));
    RawReleasePtr(self, 0xf0);
    RawReleasePtr(self, 0xe8);
    RawReleasePtrArray(self, 0xd0);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x158);
    return self;
}

// Text record (vftable 0x1431921e0): five strings +0x18-+0x38 and a hash +0x40.
// @0x142689520
void* FUN_142689520(void* self, unsigned flags)
{
    FUN_142687170(RawFieldPtr<void>(self, 0x40));
    RawField<String>(self, 0x38).~String();
    RawField<String>(self, 0x30).~String();
    RawField<String>(self, 0x28).~String();
    RawField<String>(self, 0x20).~String();
    RawField<String>(self, 0x18).~String();
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x78);
    return self;
}

// The other one-slot vftables sfr_as3_22 stores (RTTI-less, same pack as 0x143192190): defined here beside their
// deleting destructors so the full exe has them (the hook DLL binds the names to the exe's tables). 0x1431921c0's
// slot is the counted-buffer record destructor in sfr_render_05l.
void* FUN_142688ed0(void* self, unsigned flags);
extern "C" void* const DAT_143192160[1] = { (void*)&FUN_142688f50 };
extern "C" void* const DAT_143192170[1] = { (void*)&FUN_142689180 };
extern "C" void* const DAT_143192180[1] = { (void*)&FUN_1426890b0 };
extern "C" void* const DAT_1431921a0[1] = { (void*)&FUN_142689330 };
extern "C" void* const DAT_1431921b0[1] = { (void*)&FUN_142689230 };
extern "C" void* const DAT_1431921c0[1] = { (void*)&FUN_142688ed0 };
extern "C" void* const DAT_1431921d0[1] = { (void*)&FUN_1426893b0 };
extern "C" void* const DAT_1431921e0[1] = { (void*)&FUN_142689520 };

// The grouping the child visitor (0x142686440) also fills: the hash and whether every record counts.
struct Sfr21ImageGrouping
{
    U*   Table;
    bool All;
};

// Value of a grouping entry (0x20 bytes, copied out as is): the key, a zero word, the record count, the bytes.
struct Sfr21ImageGroup
{
    U      Key;
    U      Zero;
    UInt32 Count;
    U      Bytes;
};

// Groups the records of a movie (array +0x18, each with a key at +0x10, data [+0x18, +0x20) and children +0x30) by
// key, counting them and summing their sizes; records whose key's high word is not 1 count only when `all` is set.
// Returns a new summary object (vftable 0x143192190) holding the groups and a copy of the movie's hash +0x30.
// MS2-FUNCTIONAL: same calls and loop; the exe saves its registers late (166-byte prolog) and its frame is larger.
// @0x142689640
__declspec(noinline) void* FUN_142689640(void* movie, bool all)
{
    AllocInfo info(0x242, 0, 0);
    char* summary = (char*)Memory::AllocAutoHeap(movie, 0x30, info);
    if (summary)
    {
        RawField<void* const*>(summary, 0) = DAT_143192190;
        RawField<UInt32>(summary, 8) = 1;
        RawField<U>(summary, 0x10) = 0;
        RawField<U>(summary, 0x18) = 0;
        RawField<U>(summary, 0x20) = 0;
        RawField<U>(summary, 0x28) = 0;
    }
    reinterpret_cast<Sfr03nFunctionDescSet*>(summary + 0x28)->Assign(summary + 0x28, *RawFieldPtr<const Sfr03nFunctionDescSet>(movie, 0x30));

    Sfr21ImageGrouping grouping;
    grouping.Table = 0;
    grouping.All = all;
    for (U i = 0; i < RawField<U>(movie, 0x20); i++)
    {
        char* record = RawField<char**>(movie, 0x18)[i];
        if (grouping.All || (RawField<U>(record, 0x10) >> 32) == 1)
        {
            Sfr03nFuncStatsSet::Iterator found = reinterpret_cast<Sfr03nFuncStatsSet*>(&grouping)->FindAlt(RawField<UInt64>(record, 0x10));
            struct { U** Hash; SPInt Index; }& it = reinterpret_cast<decltype(it)>(found);
            U bytes = RawField<U>(record, 0x20) - RawField<U>(record, 0x18);
            if (it.Hash && *it.Hash && it.Index <= (SPInt)(*it.Hash)[1])
            {
                Sfr21ImageGroup* g = (Sfr21ImageGroup*)(RawEntry(*it.Hash, (U)it.Index, 0x38) + 0x18);
                g->Count++;
                g->Bytes += bytes;
            }
            else
            {
                Sfr21ImageGroup g;
                g.Key = RawField<U>(record, 0x10);
                g.Zero = 0;
                g.Count = 1;
                g.Bytes = bytes;
                reinterpret_cast<Sfr03nFuncStatsHash*>(&grouping)->Add(RawField<UInt64>(record, 0x10), reinterpret_cast<const AMP::MovieFunctionStats::FuncStats&>(g));
            }
        }
        for (U j = 0; j < RawField<U>(record, 0x38); j++)
            RawField<AMP::FuncTreeItem**>(record, 0x30)[j]->Visit(reinterpret_cast<AMP::FunctionTreeVisitor&>(grouping));
    }

    if (U* table = grouping.Table)
    {
        U i = 0;
        while (i <= table[1] && *(SPInt*)RawEntry(table, i, 0x38) == -2)
            i++;
        while (i <= table[1])
        {
            char* slot = RawArrayPush<FUN_142623bc0>(RawFieldPtr<U>(summary, 0x10), 0x20);
            memcpy(slot, RawEntry(table, i, 0x38) + 0x18, 0x20);
            for (i++; i <= table[1] && *(SPInt*)RawEntry(table, i, 0x38) == -2; i++)
                ;
        }
    }
    reinterpret_cast<Sfr03nFuncStatsSet*>(&grouping)->Sfr03nFuncStatsSet::~Sfr03nFuncStatsSet();
    return summary;
}

// Rebuilds the summaries of a movie list: each movie's (+0xd0, the summary +0x60 from its records +0x70) and the
// root's (+0xe8 from +0xf0).
// @0x142689920
void FUN_142689920(void* self, bool all)
{
    for (U i = 0; i < RawField<U>(self, 0xd8); i++)
    {
        char* movie = RawField<char**>(self, 0xd0)[i];
        if (RawField<void*>(movie, 0x70))
        {
            void* summary = FUN_142689640(RawField<void*>(movie, 0x70), all);
            RawReleasePtr(movie, 0x60);
            RawField<void*>(movie, 0x60) = summary;
        }
    }
    if (RawField<void*>(self, 0xf0))
    {
        void* summary = FUN_142689640(RawField<void*>(self, 0xf0), all);
        RawReleasePtr(self, 0xe8);
        RawField<void*>(self, 0xe8) = summary;
    }
}

}} // namespace Scaleform::GFx
