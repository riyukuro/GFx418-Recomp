// Recovered Scaleform GFx 4.1.18: global-heap allocation front end (Memory::pGlobalHeap), the allocation macros of the
// shipping build (no file/line info) and the class-level operator new/delete set (SF_MEMORY_REDEFINE_NEW).
#ifndef MS2_SF_KERNEL_MEMORY_H
#define MS2_SF_KERNEL_MEMORY_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"

#define SF_ALLOC(s, id)                   Scaleform::Memory::Alloc((s))
#define SF_MEMALIGN(s, a, id)             Scaleform::Memory::Alloc((s), (a))
#define SF_REALLOC(p, s, id)              Scaleform::Memory::Realloc((p), (s))
#define SF_FREE(p)                        Scaleform::Memory::Free((p))
#define SF_FREE_ALIGN(s)                  Scaleform::Memory::Free((s))
#define SF_HEAP_ALLOC(heap, s, id)        Scaleform::Memory::AllocInHeap((heap), (s))
#define SF_HEAP_MEMALIGN(heap, s, a, id)  Scaleform::Memory::AllocInHeap((heap), (s), (a))
#define SF_HEAP_AUTO_ALLOC(addr, s)       Scaleform::Memory::AllocAutoHeap((addr), (s))
#define SF_HEAP_AUTO_ALLOC_ID(addr, s, id) Scaleform::Memory::AllocAutoHeap((addr), (s))
#define SF_HEAP_FREE(heap, p)             Scaleform::Memory::Free((p))

namespace Scaleform {

class Memory
{
public:
    static MemoryHeap* pGlobalHeap;

    static void SF_STDCALL SetGlobalHeap(MemoryHeap* heap) { pGlobalHeap = heap; }
    static MemoryHeap* SF_STDCALL GetGlobalHeap() { return pGlobalHeap; }

    static void SF_STDCALL CreateArena(UPInt arena, SysAllocPaged* a) { pGlobalHeap->CreateArena(arena, a); }
    static void SF_STDCALL DestroyArena(UPInt arena) { pGlobalHeap->DestroyArena(arena); }
    static bool SF_STDCALL ArenaIsEmpty(UPInt arena) { return pGlobalHeap->ArenaIsEmpty(arena); }

    static void* SF_STDCALL Alloc(UPInt size) { return pGlobalHeap->Alloc(size); }
    static void* SF_STDCALL Alloc(UPInt size, UPInt align) { return pGlobalHeap->Alloc(size, align); }
    static void* SF_STDCALL Alloc(UPInt size, const AllocInfo& info) { return pGlobalHeap->Alloc(size, &info); }
    static void* SF_STDCALL Alloc(UPInt size, UPInt align, const AllocInfo& info)
    { return pGlobalHeap->Alloc(size, align, &info); }

    static void* SF_STDCALL AllocAutoHeap(const void* p, UPInt size) { return pGlobalHeap->AllocAutoHeap(p, size); }
    static void* SF_STDCALL AllocAutoHeap(const void* p, UPInt size, UPInt align)
    { return pGlobalHeap->AllocAutoHeap(p, size, align); }
    static void* SF_STDCALL AllocAutoHeap(const void* p, UPInt size, const AllocInfo& info)
    { return pGlobalHeap->AllocAutoHeap(p, size, &info); }
    static void* SF_STDCALL AllocAutoHeap(const void* p, UPInt size, UPInt align, const AllocInfo& info)
    { return pGlobalHeap->AllocAutoHeap(p, size, align, &info); }

    static void* SF_STDCALL AllocInHeap(MemoryHeap* heap, UPInt size) { return heap->Alloc(size); }
    static void* SF_STDCALL AllocInHeap(MemoryHeap* heap, UPInt size, UPInt align) { return heap->Alloc(size, align); }
    static void* SF_STDCALL AllocInHeap(MemoryHeap* heap, UPInt size, const AllocInfo& info)
    { return heap->Alloc(size, &info); }
    static void* SF_STDCALL AllocInHeap(MemoryHeap* heap, UPInt size, UPInt align, const AllocInfo& info)
    { return heap->Alloc(size, align, &info); }

    static void* SF_STDCALL Realloc(void* p, UPInt newSize) { return pGlobalHeap->Realloc(p, newSize); }
    static void SF_STDCALL Free(void* p) { return pGlobalHeap->Free(p); }
    static MemoryHeap* SF_STDCALL GetHeapByAddress(const void* p) { return pGlobalHeap->GetAllocHeap(p); }
    static bool SF_STDCALL DetectMemoryLeaks() { return pGlobalHeap->DumpMemoryLeaks(); }
};

// Placement-style tag for "allocate in the heap that owns this address".
struct MemAddressStub { };
typedef MemAddressStub* MemAddressPtr;

// Class-scope new/delete: every overload the SDK headers spell (heap, heap+id, owner address, file/line variants);
// deletes go back to the global heap front end, which finds the owning heap itself.
#define SF_MEMORY_REDEFINE_NEW_IMPL(class_name, check_delete, StatType)                                              \
    void* operator new(UPInt sz) { void* p = SF_ALLOC(sz, StatType); return p; }                                     \
    void* operator new(UPInt sz, Scaleform::MemoryHeap* heap) { void* p = SF_HEAP_ALLOC(heap, sz, StatType); return p; } \
    void* operator new(UPInt sz, Scaleform::MemoryHeap* heap, int blocktype)                                        \
    { SF_UNUSED(blocktype); void* p = SF_HEAP_ALLOC(heap, sz, blocktype); return p; }                               \
    void* operator new(UPInt sz, Scaleform::MemAddressPtr adr)                                                      \
    { void* p = Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(StatType, __FILE__, __LINE__)); return p; } \
    void* operator new(UPInt sz, const char* f, int l)                                                              \
    { void* p = Scaleform::Memory::Alloc(sz, Scaleform::AllocInfo(StatType, f, l)); return p; }                      \
    void* operator new(UPInt sz, Scaleform::MemoryHeap* heap, const char* f, int l)                                 \
    { void* p = Scaleform::Memory::AllocInHeap(heap, sz, Scaleform::AllocInfo(StatType, f, l)); return p; }          \
    void* operator new(UPInt sz, Scaleform::MemAddressPtr adr, const char* f, int l)                                \
    { void* p = Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(StatType, f, l)); return p; }         \
    void* operator new(UPInt sz, int blocktype, const char* f, int l)                                               \
    { void* p = Scaleform::Memory::Alloc(sz, Scaleform::AllocInfo(blocktype, f, l)); return p; }                     \
    void* operator new(UPInt sz, Scaleform::MemoryHeap* heap, int blocktype, const char* f, int l)                  \
    { void* p = Scaleform::Memory::AllocInHeap(heap, sz, Scaleform::AllocInfo(blocktype, f, l)); return p; }         \
    void* operator new(UPInt sz, Scaleform::MemAddressPtr adr, int blocktype, const char* f, int l)                 \
    { void* p = Scaleform::Memory::AllocAutoHeap(adr, sz, Scaleform::AllocInfo(blocktype, f, l)); return p; }        \
    void operator delete(void* p) { check_delete(class_name, p); SF_FREE(p); }                                       \
    void operator delete(void* p, const char*, int) { check_delete(class_name, p); SF_FREE(p); }                     \
    void operator delete(void* p, int, const char*, int) { check_delete(class_name, p); SF_FREE(p); }                \
    void operator delete(void* p, Scaleform::MemoryHeap*) { check_delete(class_name, p); SF_FREE(p); }               \
    void operator delete(void* p, Scaleform::MemoryHeap*, int) { check_delete(class_name, p); SF_FREE(p); }          \
    void operator delete(void* p, Scaleform::MemoryHeap*, const char*, int) { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemoryHeap*, int, const char*, int) { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr) { check_delete(class_name, p); SF_FREE(p); }            \
    void operator delete(void* p, Scaleform::MemAddressPtr, int) { check_delete(class_name, p); SF_FREE(p); }       \
    void operator delete(void* p, Scaleform::MemAddressPtr, const char*, int) { check_delete(class_name, p); SF_FREE(p); } \
    void operator delete(void* p, Scaleform::MemAddressPtr, int, const char*, int) { check_delete(class_name, p); SF_FREE(p); }

#define SF_MEMORY_DEFINE_PLACEMENT_NEW                                        \
    void* operator new(UPInt n, void* ptr) { SF_UNUSED(n); return ptr; }      \
    void operator delete(void* ptr, void* ptr2) { SF_UNUSED2(ptr, ptr2); }

#define SF_MEMORY_CHECK_DELETE_NONE(class_name, p)
#define SF_MEMORY_REDEFINE_NEW(class_name, StatType) \
    SF_MEMORY_REDEFINE_NEW_IMPL(class_name, SF_MEMORY_CHECK_DELETE_NONE, StatType)

template<int Stat>
class NewOverrideBase
{
public:
    enum { StatType = Stat };
    SF_MEMORY_REDEFINE_NEW(NewOverrideBase, Stat)
};

}  // namespace Scaleform

#define SF_HEAP_NEW(pheap)       new(pheap)
#define SF_HEAP_NEW_ID(pheap, id) new(pheap, id)
#define SF_HEAP_AUTO_NEW(paddr)  new((Scaleform::MemAddressPtr)((void*)paddr))
#define SF_NEW                   new

#endif
