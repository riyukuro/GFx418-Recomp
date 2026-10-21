// Recovered Scaleform GFx 4.1.18: the "MH" heap (small-footprint heap for many small heaps; the exe's default is PT,
// MH is linked in but only used when a SysAlloc-based System is set up). 0xd8 bytes: MemoryHeap + engine + debug
// storage pointer.
#ifndef MS2_SF_KERNEL_HEAPMH_MEMORYHEAP_H
#define MS2_SF_KERNEL_HEAPMH_MEMORYHEAP_H

#include "ms2/scaleform/kernel/sf_memoryheap.h"

namespace Scaleform {

namespace HeapMH {
class  RootMH;
class  AllocEngineMH;
class  DebugStorageMH;
struct PageMH;
struct NodeMH;
struct PageInfoMH;
}

class MemoryHeapMH : public MemoryHeap
{
private:
    friend class HeapMH::RootMH;

    MemoryHeapMH();
    virtual ~MemoryHeapMH() { }

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

    void* allocMem(UPInt size, const AllocInfo* info, bool globalLocked);
    void* allocMem(UPInt size, UPInt align, const AllocInfo* info, bool globalLocked);
    void* allocMem(HeapMH::PageInfoMH* parentInfo, const void* thisPtr, UPInt size, const AllocInfo* info,
                   bool globalLocked);
    void* allocMem(HeapMH::PageInfoMH* parentInfo, const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info,
                   bool globalLocked);
    void* reallocMem(HeapMH::PageMH* page, void* oldPtr, UPInt newSize, bool globalLocked);
    void* reallocMem(HeapMH::NodeMH* node, void* oldPtr, UPInt newSize, bool globalLocked);
    void  freeLocked(void* ptr, bool globalLocked);
    void  freeMem(HeapMH::PageMH* page, void* ptr, bool globalLocked);
    void  freeMem(HeapMH::NodeMH* node, void* ptr, bool globalLocked);

    HeapMH::AllocEngineMH*  pEngine;         // +0xc8
    HeapMH::DebugStorageMH* pDebugStorage;   // +0xd0
};

}  // namespace Scaleform

#endif
