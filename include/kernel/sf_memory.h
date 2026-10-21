// Recovered Scaleform 4.1.18 kernel: memory heaps, the global heap and the class-level new/delete overrides.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// MemoryHeap's vftable slot order is the exe's (verified callers: Alloc(size, info) = slot 10 +0x50, Free = slot 12
// +0x60, GetAllocHeap = slot 15 +0x78). Overloaded virtuals are declared in the original order; MSVC puts the later
// overload first, so Alloc(size, align, info) is slot 9. Slots after 15 follow the 4.x layout and are unverified.
// The data members are not recovered yet (no unit reads them).
#ifndef MS2_SF_KERNEL_MEMORY_H
#define MS2_SF_KERNEL_MEMORY_H

#include "sf_types.h"

namespace Scaleform {

// Allocation statistics ids (Stat_*, StatMV_*): only the values the recovered code uses, named after the exe's
// template arguments.
enum StatBasicValues
{
    StatGroup_Default   = 0,
    Stat_Mem            = 1,
    Stat_Default_Mem    = 2,
    StatMV_XML_Mem      = 0x146,
};

class  MemoryHeap;
class  SysAllocPaged;
class  StatBag;
struct HeapDesc;
struct RootStats;
namespace Heap { class MemVisitor; class SegVisitor; }

// Shipping build: only the stat id is kept.
struct AllocInfo
{
    unsigned StatId;

    AllocInfo() : StatId(Stat_Default_Mem) {}
    AllocInfo(unsigned statId, const char*, unsigned) : StatId(statId) {}
    AllocInfo(const AllocInfo& src) : StatId(src.StatId) {}
};

class MemoryHeap
{
public:
    class LimitHandler;
    class HeapTracer;

    virtual ~MemoryHeap() {}                                                    // 0

    virtual void        CreateArena(UPInt arena, SysAllocPaged* sysAlloc) = 0;  // 1
    virtual void        DestroyArena(UPInt arena) = 0;                          // 2
    virtual bool        ArenaIsEmpty(UPInt arena) = 0;                          // 3
    virtual MemoryHeap* CreateHeap(const char* name, const HeapDesc& desc) = 0; // 4
    virtual void        SetLimitHandler(LimitHandler* handler) = 0;             // 5
    virtual void        SetLimit(UPInt newLimit) = 0;                           // 6
    virtual void        AddRef() = 0;                                           // 7
    virtual void        Release() = 0;                                          // 8

    virtual void*       Alloc(UPInt size, const AllocInfo* info = 0) = 0;              // 10
    virtual void*       Alloc(UPInt size, UPInt align, const AllocInfo* info = 0) = 0; // 9
    virtual void*       Realloc(void* oldPtr, UPInt newSize) = 0;                       // 11
    virtual void        Free(void* ptr) = 0;                                            // 12
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, const AllocInfo* info = 0) = 0;              // 14
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info = 0) = 0; // 13
    virtual MemoryHeap* GetAllocHeap(const void* thisPtr) = 0;                          // 15
    virtual UPInt       GetUsableSize(const void* ptr) = 0;                             // 16
    virtual void*       AllocSysDirect(UPInt size) = 0;
    virtual void        FreeSysDirect(void* ptr, UPInt size) = 0;
    virtual bool        GetStats(StatBag* bag) = 0;
    virtual UPInt       GetFootprint() const = 0;
    virtual UPInt       GetTotalFootprint() const = 0;
    virtual UPInt       GetUsedSpace() const = 0;
    virtual UPInt       GetTotalUsedSpace() const = 0;
    virtual void        GetRootStats(RootStats* stats) = 0;
    virtual void        VisitMem(Heap::MemVisitor* visitor, unsigned flags) = 0;
    virtual void        VisitRootSegments(Heap::SegVisitor* visitor) = 0;
    virtual void        VisitHeapSegments(Heap::SegVisitor* visitor) const = 0;
    virtual void        SetTracer(HeapTracer* tracer) = 0;
protected:
    virtual void        destroyItself() = 0;
    virtual void        ultimateCheck() = 0;
    virtual void        releaseCachedMem() = 0;
    virtual bool        dumpMemoryLeaks() = 0;
    virtual void        checkIntegrity() const = 0;
    virtual void        getUserDebugStats(RootStats* stats) const = 0;
};

// Static front end to the global heap (Memory::pGlobalHeap, exe data).
class Memory
{
public:
    static MemoryHeap* pGlobalHeap;

    static void        SetGlobalHeap(MemoryHeap* heap) { pGlobalHeap = heap; }
    static MemoryHeap* GetGlobalHeap()                 { return pGlobalHeap; }

    static void* Alloc(UPInt size)                                       { return pGlobalHeap->Alloc(size); }
    static void* Alloc(UPInt size, UPInt align)                          { return pGlobalHeap->Alloc(size, align); }
    static void* Alloc(UPInt size, const AllocInfo& info)                { return pGlobalHeap->Alloc(size, &info); }
    static void* Alloc(UPInt size, UPInt align, const AllocInfo& info)   { return pGlobalHeap->Alloc(size, align, &info); }

    static void* AllocAutoHeap(const void* p, UPInt size)                                     { return pGlobalHeap->AllocAutoHeap(p, size); }
    static void* AllocAutoHeap(const void* p, UPInt size, UPInt align)                        { return pGlobalHeap->AllocAutoHeap(p, size, align); }
    static void* AllocAutoHeap(const void* p, UPInt size, const AllocInfo& info)              { return pGlobalHeap->AllocAutoHeap(p, size, &info); }
    static void* AllocAutoHeap(const void* p, UPInt size, UPInt align, const AllocInfo& info) { return pGlobalHeap->AllocAutoHeap(p, size, align, &info); }

    static void* AllocInHeap(MemoryHeap* heap, UPInt size)                                     { return heap->Alloc(size); }
    static void* AllocInHeap(MemoryHeap* heap, UPInt size, UPInt align)                        { return heap->Alloc(size, align); }
    static void* AllocInHeap(MemoryHeap* heap, UPInt size, const AllocInfo& info)              { return heap->Alloc(size, &info); }
    static void* AllocInHeap(MemoryHeap* heap, UPInt size, UPInt align, const AllocInfo& info) { return heap->Alloc(size, align, &info); }

    static void* Realloc(void* p, UPInt newSize)         { return pGlobalHeap->Realloc(p, newSize); }
    static void  Free(void* p)                           { pGlobalHeap->Free(p); }
    static MemoryHeap* GetHeapByAddress(const void* p)   { return pGlobalHeap->GetAllocHeap(p); }
};

// Address hint for "allocate in the heap that owns this address" placement new.
struct MemAddressStub {};
typedef MemAddressStub* MemAddressPtr;

} // namespace Scaleform

// Shipping build allocation macros (no file/line tracking).
#define SF_ALLOC(s, id)                     Scaleform::Memory::Alloc((s))
#define SF_MEMALIGN(s, a, id)               Scaleform::Memory::Alloc((s), (a))
#define SF_REALLOC(p, s, id)                Scaleform::Memory::Realloc((p), (s))
#define SF_FREE(p)                          Scaleform::Memory::Free((p))
#define SF_HEAP_ALLOC(heap, s, id)          Scaleform::Memory::AllocInHeap((heap), (s))
#define SF_HEAP_MEMALIGN(heap, s, a, id)    Scaleform::Memory::AllocInHeap((heap), (s), (a))
#define SF_HEAP_AUTO_ALLOC(addr, s)         Scaleform::Memory::AllocAutoHeap((addr), (s))
#define SF_HEAP_FREE(heap, p)               Scaleform::Memory::Free((p))

#define SF_HEAP_NEW(pheap)                  new(pheap)
#define SF_HEAP_NEW_ID(pheap, id)           new(pheap, id)
#define SF_HEAP_AUTO_NEW(paddr)             new((Scaleform::MemAddressPtr)((void*)(paddr)))
#define SF_NEW                              new

// Class-level operator new/delete set: every allocation goes through the Scaleform heaps. check_delete(cls, p) is a
// debug hook (empty in shipping builds).
#define SF_MEMORY_REDEFINE_NEW_IMPL(class_name, check_delete, StatType)                                              \
    void* operator new(Scaleform::UPInt sz)                                                                          \
    { return Scaleform::Memory::Alloc(sz); }                                                                         \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemoryHeap* heap)                                             \
    { return Scaleform::Memory::AllocInHeap(heap, sz); }                                                             \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemoryHeap* heap, int)                                        \
    { return Scaleform::Memory::AllocInHeap(heap, sz); }                                                             \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemAddressPtr adr)                                            \
    { return Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(StatType, 0, 0)); }                      \
    void* operator new(Scaleform::UPInt sz, const char* file, int line)                                              \
    { return Scaleform::Memory::Alloc(sz, Scaleform::AllocInfo(StatType, file, line)); }                             \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemoryHeap* heap, const char* file, int line)                 \
    { return Scaleform::Memory::AllocInHeap(heap, sz, Scaleform::AllocInfo(StatType, file, line)); }                 \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemAddressPtr adr, const char* file, int line)                \
    { return Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(StatType, file, line)); }                \
    void* operator new(Scaleform::UPInt sz, int id, const char* file, int line)                                      \
    { return Scaleform::Memory::Alloc(sz, Scaleform::AllocInfo(id, file, line)); }                                   \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemoryHeap* heap, int id, const char* file, int line)         \
    { return Scaleform::Memory::AllocInHeap(heap, sz, Scaleform::AllocInfo(id, file, line)); }                       \
    void* operator new(Scaleform::UPInt sz, Scaleform::MemAddressPtr adr, int id, const char* file, int line)        \
    { return Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(id, file, line)); }                      \
    void operator delete(void* p)                                                 { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, const char*, int)                               { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, int, const char*, int)                          { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemoryHeap*)                         { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemoryHeap*, int)                    { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemoryHeap*, const char*, int)       { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemoryHeap*, int, const char*, int)  { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr)                       { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr, int)                  { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr, const char*, int)     { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr, int, const char*, int){ check_delete(class_name, p); SF_FREE(p); }

#define SF_MEMORY_CHECK_DELETE_NONE(class_name, p)
#define SF_MEMORY_REDEFINE_NEW(class_name, StatType) \
    SF_MEMORY_REDEFINE_NEW_IMPL(class_name, SF_MEMORY_CHECK_DELETE_NONE, StatType)

namespace Scaleform {

// Base for small heap-allocated objects without reference counting.
template<int Stat>
class NewOverrideBase
{
public:
    enum { StatType = Stat };
    SF_MEMORY_REDEFINE_NEW(NewOverrideBase, Stat)
};

// Parameters of MemoryHeap::CreateHeap (0x40 bytes).
struct HeapDesc
{
    enum HeapFlags
    {
        Heap_FastTinyBlocks = 0x4,
        Heap_UserDebug      = 0x1000
    };

    unsigned Flags;        // +0
    UPInt    MinAlign;     // +8
    UPInt    Granularity;  // +0x10
    UPInt    Reserve;      // +0x18
    UPInt    Threshold;    // +0x20
    UPInt    Limit;        // +0x28
    UPInt    HeapId;       // +0x30
    UPInt    Arena;        // +0x38

    HeapDesc(unsigned flags = 0, UPInt minAlign = 16, UPInt granularity = 8 * 1024, UPInt reserve = 8 * 1024,
             UPInt threshold = ~UPInt(0), UPInt limit = 0, UPInt heapId = 0, UPInt arena = 0)
        : Flags(flags), MinAlign(minAlign), Granularity(granularity), Reserve(reserve), Threshold(threshold),
          Limit(limit), HeapId(heapId), Arena(arena)
    {}
};

// Heap ids passed in HeapDesc::HeapId.
enum HeapIdValues
{
    HeapId_Images = 5
};

} // namespace Scaleform

#endif
