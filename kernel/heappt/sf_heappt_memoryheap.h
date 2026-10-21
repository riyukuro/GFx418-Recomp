// Recovered Scaleform GFx 4.1.18: the "PT" heap, the exe's default MemoryHeap (HeapPT_MemoryHeap, exe
// 0x142641be0..0x142642f90). Every heap owns an AllocEngine; segments are found through the global page table.
// 0xd8 bytes: MemoryHeap + engine + debug storage pointer (always 0, no debug info in this build).
#ifndef MS2_SF_KERNEL_HEAPPT_MEMORYHEAP_H
#define MS2_SF_KERNEL_HEAPPT_MEMORYHEAP_H

#include "ms2/scaleform/kernel/sf_memoryheap.h"

namespace Scaleform {

namespace HeapPT {
class HeapRoot;
class AllocEngine;
class DebugStorage;
}
namespace Heap {
struct HeapSegment;
class MemVisitor;
class SegVisitor;
}
namespace HeapMH { class RootMH; }

class MemoryHeapPT : public MemoryHeap
{
private:
    friend class HeapPT::HeapRoot;
    friend class HeapMH::RootMH;

    MemoryHeapPT();   // heaps are made and destroyed only by HeapRoot
    virtual ~MemoryHeapPT() { }

public:
    virtual void CreateArena(UPInt arena, SysAllocPaged* sysAlloc);
    virtual void DestroyArena(UPInt arena);
    virtual bool ArenaIsEmpty(UPInt arena);

    virtual MemoryHeap* CreateHeap(const char* name, const HeapDesc& desc);

    virtual void SetLimitHandler(LimitHandler* handler);
    virtual void SetLimit(UPInt newLimit);
    virtual void AddRef();
    virtual void Release();

    virtual void*       Alloc(UPInt size, const AllocInfo* info = 0);
    virtual void*       Alloc(UPInt size, UPInt align, const AllocInfo* info = 0);
    virtual void*       Realloc(void* oldPtr, UPInt newSize);
    virtual void        Free(void* ptr);
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, const AllocInfo* info = 0);
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info = 0);
    virtual MemoryHeap* GetAllocHeap(const void* thisPtr);
    virtual UPInt       GetUsableSize(const void* ptr);
    virtual void*       AllocSysDirect(UPInt size);
    virtual void        FreeSysDirect(void* ptr, UPInt size);

    virtual bool  GetStats(StatBag* bag);
    virtual UPInt GetFootprint() const;
    virtual UPInt GetTotalFootprint() const;
    virtual UPInt GetUsedSpace() const;
    virtual UPInt GetTotalUsedSpace() const;
    virtual void  GetRootStats(RootStats* stats);
    virtual void  VisitMem(Heap::MemVisitor* visitor, unsigned flags);
    virtual void  VisitRootSegments(Heap::SegVisitor* visitor);
    virtual void  VisitHeapSegments(Heap::SegVisitor* visitor) const;
    virtual void  SetTracer(HeapTracer* tracer);

private:
    virtual void destroyItself();
    virtual void ultimateCheck();
    virtual void releaseCachedMem();
    virtual bool dumpMemoryLeaks();
    virtual void checkIntegrity() const;
    virtual void getUserDebugStats(RootStats* stats) const;

    void* allocMem(UPInt size, const AllocInfo* info);
    void* allocMem(UPInt size, UPInt align, const AllocInfo* info);
    void* allocMem(const void* thisPtr, UPInt size, const AllocInfo* info);
    void* allocMem(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info);
    void* reallocMem(Heap::HeapSegment* seg, void* oldPtr, UPInt newSize);

    HeapPT::AllocEngine*  pEngine;         // +0xc8
    HeapPT::DebugStorage* pDebugStorage;   // +0xd0
};

}  // namespace Scaleform

#endif
