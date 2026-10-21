// Recovered Scaleform GFx 4.1.18: the PT heap root (HeapPT_Root, exe 0x1426ce850..0x1426cf7b0): the system allocator
// wrapper, the bootstrap Starter, the Bookkeeper, the root lock and the arena table. One instance lives in static
// memory (MemoryHeap::InitPT); 0x8c0 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_ROOT_H
#define MS2_SF_KERNEL_HEAPPT_ROOT_H

#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_bookkeeper.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

// a SysAllocPaged on top of another one that rounds requests up to its granularity (a Granulator in PrivateData);
// requests above SysDirectThreshold go to the source allocator directly
class SysAllocGranulator : public SysAllocPaged
{
public:
    SysAllocGranulator();
    SysAllocGranulator(SysAllocPaged* sysAlloc);
    void Init(SysAllocPaged* sysAlloc);

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt alignment);
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignment);
    virtual bool  Free(void* ptr, UPInt size, UPInt alignment);
    virtual void* AllocSysDirect(UPInt size, UPInt alignment, UPInt* actualSize, UPInt* actualAlign);
    virtual bool  FreeSysDirect(void* ptr, UPInt size, UPInt alignment);
    virtual UPInt GetFootprint() const;
    virtual UPInt GetUsedSpace() const;
    virtual void  VisitMem(MemVisitor* visitor) const;
    virtual void  VisitSegments(SegVisitor* visitor, UPInt catSeg, UPInt catUnused) const;
    virtual UPInt GetBase() const;
    virtual UPInt GetSize() const;

private:
    Granulator* pGranulator;          // +0x08, points into PrivateData or 0
    UPInt       SysDirectThreshold;
    UPInt       MaxHeapGranularity;
    UPInt       MinAlign;
    UPInt       MaxAlign;
    UPInt       SysDirectFootprint;
    UPInt       PrivateData[32];      // +0x38
};

// what the root hands to the engines: either the user allocator itself (it already has a granularity) or a
// SysAllocGranulator over it; also counts the used space
class SysAllocWrapper : public SysAllocPaged
{
public:
    SysAllocWrapper(SysAllocPaged* sysAlloc);

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt align);
    virtual bool  Free(void* ptr, UPInt size, UPInt align);
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align);
    virtual void* AllocSysDirect(UPInt size, UPInt alignment, UPInt* actualSize, UPInt* actualAlign);
    virtual bool  FreeSysDirect(void* ptr, UPInt size, UPInt alignment);
    virtual void  VisitMem(MemVisitor*) const;
    virtual void  VisitSegments(Heap::SegVisitor* visitor, UPInt catSeg, UPInt catUnused) const;
    virtual UPInt GetFootprint() const;
    virtual UPInt GetUsedSpace() const;

    void* AllocSysDirect(UPInt size);
    void  FreeSysDirect(void* ptr, UPInt size);

private:
    SysAllocGranulator Allocator;        // +0x08
    SysAllocPaged*     pSrcAlloc;        // +0x140
    SysAllocPaged*     pSysAlloc;        // +0x148
    UPInt              SysGranularity;   // for AllocSysDirect
    UPInt              MinAlign;         // for AllocSysDirect
    UPInt              UsedSpace;        // +0x160
};

class HeapRoot
{
public:
    HeapRoot(SysAllocPaged* sysAlloc);
    ~HeapRoot();

    void           CreateArena(UPInt arena, SysAllocPaged* sysAlloc);
    int            DestroyArena(UPInt arena);
    void           DestroyAllArenas();
    bool           ArenaIsEmpty(UPInt arena);
    SysAllocPaged* GetSysAlloc(UPInt arena);

    Starter*    GetStarter() { return &AllocStarter; }
    Bookkeeper* GetBookkeeper() { return &AllocBookkeeper; }

    MemoryHeapPT* CreateHeap(const char* name, MemoryHeapPT* parent, const MemoryHeap::HeapDesc& desc);
    void          DestroyHeap(MemoryHeapPT* heap);

    LockSafe* GetLock() { return &RootLock; }

    void  VisitSegments(Heap::SegVisitor* visitor) const;
    void* AllocSysDirect(UPInt size);
    void  FreeSysDirect(void* ptr, UPInt size);
    void  GetStats(MemoryHeap::RootStats* stats) const;

private:
    SysAllocWrapper  AllocWrapper;      // +0x000
    Starter          AllocStarter;      // +0x168
    Bookkeeper       AllocBookkeeper;   // +0x230
    mutable LockSafe RootLock;          // +0x888
    SysAllocPaged**  pArenas;           // +0x8b0
    UPInt            NumArenas;         // +0x8b8
};

extern HeapRoot* GlobalRoot;

}}  // namespace Scaleform::HeapPT

#endif
