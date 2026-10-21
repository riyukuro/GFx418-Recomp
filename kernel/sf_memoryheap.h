// Recovered Scaleform GFx 4.1.18: the abstract memory heap. Concrete engines: MemoryHeapMH (HeapMH, the exe's global
// heap engine) and MemoryHeapPT (HeapPT). Slot order checked against the exe vftable of MemoryHeapMH (0x1431840c8):
// dtor, CreateArena, DestroyArena, ArenaIsEmpty, CreateHeap, SetLimitHandler, SetLimit, AddRef, Release, Alloc(size,
// align, info), Alloc(size, info), Realloc, Free, AllocAutoHeap x2, GetAllocHeap, GetUsableSize, AllocSysDirect,
// FreeSysDirect, GetStats, GetFootprint, GetTotalFootprint, GetUsedSpace, GetTotalUsedSpace, GetRootStats, VisitMem,
// VisitRootSegments, VisitHeapSegments, SetTracer, destroyItself, ultimateCheck, releaseCachedMem, dumpMemoryLeaks,
// checkIntegrity, getUserDebugStats.
#ifndef MS2_SF_KERNEL_MEMORYHEAP_H
#define MS2_SF_KERNEL_MEMORYHEAP_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_stats.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_sysalloc.h"
#include "ms2/scaleform/kernel/sf_allocinfo.h"

namespace Scaleform {

enum StatHeap
{
    StatHeap_Summary = StatHeap_Start,
    StatHeap_TotalFootprint,
    StatHeap_LocalFootprint,
    StatHeap_ChildFootprint,
    StatHeap_ChildHeaps,
    StatHeap_LocalUsedSpace,
    StatHeap_SysDirectSpace,
    StatHeap_Bookkeeping,
    StatHeap_DebugInfo,
    StatHeap_Segments,
    StatHeap_Granularity,
    StatHeap_DynamicGranularity,
    StatHeap_Reserve
};

namespace HeapPT { class HeapRoot; }
namespace HeapMH { class RootMH; }
namespace Heap { class MemVisitor; class SegVisitor; }
class StringBuffer;
struct MemItem;

class MemoryHeap : public ListNode<MemoryHeap>
{
    friend class MemoryHeapPT;
    friend class MemoryHeapMH;
public:
    enum MemReportType { MemReportBrief, MemReportFull, MemReportFileSummary, MemReportHeapDetailed };

    enum HeapFlags
    {
        Heap_ThreadUnsafe     = 0x0001,
        Heap_FastTinyBlocks   = 0x0002,
        Heap_FixedGranularity = 0x0004,
        Heap_Root             = 0x0008,
        Heap_NoDebugInfo      = 0x0010,
        Heap_UserDebug        = 0x1000
    };

    enum RootHeapParameters
    {
        RootHeap_MinAlign    = 16,
        RootHeap_Granularity = 16 * 1024,
        RootHeap_Reserve     = 16 * 1024,
        RootHeap_Threshold   = 256 * 1024,
        RootHeap_Limit       = 0
    };

    struct HeapDesc
    {
        unsigned Flags;
        UPInt    MinAlign;
        UPInt    Granularity;
        UPInt    Reserve;
        UPInt    Threshold;
        UPInt    Limit;
        UPInt    HeapId;
        UPInt    Arena;

        HeapDesc(unsigned flags = 0, UPInt minAlign = 16, UPInt granularity = 8 * 1024, UPInt reserve = 8 * 1024,
                 UPInt threshold = ~UPInt(0), UPInt limit = 0, UPInt heapId = 0, UPInt arena = 0)
            : Flags(flags), MinAlign(minAlign), Granularity(granularity), Reserve(reserve), Threshold(threshold),
              Limit(limit), HeapId(heapId), Arena(arena)
        { }
        void Clear()
        {
            Flags = 0;
            Granularity = 0;
            MinAlign = 16;
            Reserve = 0;
            Threshold = ~UPInt(0);
            Limit = 0;
            HeapId = 0;
            Arena = 0;
        }
    };

    struct RootHeapDesc : public HeapDesc
    {
        RootHeapDesc()
            : HeapDesc(0, RootHeap_MinAlign, RootHeap_Granularity, RootHeap_Reserve, RootHeap_Threshold, RootHeap_Limit,
                       HeapId_Global)
        { }
    };

    struct HeapInfo
    {
        HeapDesc    Desc;
        MemoryHeap* pParent;
        char*       pName;
    };

    struct HeapVisitor
    {
        virtual ~HeapVisitor() { }
        virtual void Visit(MemoryHeap* parentHeap, MemoryHeap* childHeap) = 0;
    };

    // 4.1.18 carries a counter after the vfptr (+8; the heap code of the exe never touches it, the GFx users do)
    struct LimitHandler
    {
        LimitHandler() : AllocCount(0) { }
        virtual ~LimitHandler() { }
        virtual bool OnExceedLimit(MemoryHeap* heap, UPInt overLimit) = 0;
        virtual void OnFreeSegment(MemoryHeap* heap, UPInt freeingSize) = 0;

        int AllocCount;     // nonzero while inside an allocation of the heap
    };

    struct HeapTracer
    {
        virtual ~HeapTracer() { }
        virtual void OnCreateHeap(const MemoryHeap* heap) = 0;
        virtual void OnDestroyHeap(const MemoryHeap* heap) = 0;
        virtual void OnAlloc(const MemoryHeap* heap, UPInt size, UPInt align, unsigned sid, const void* ptr) = 0;
        virtual void OnRealloc(const MemoryHeap* heap, const void* oldPtr, UPInt newSize, const void* newPtr) = 0;
        virtual void OnFree(const MemoryHeap* heap, const void* ptr) = 0;
    };

    struct RootStats
    {
        UPInt SysMemFootprint;
        UPInt SysMemUsedSpace;
        UPInt PageMapFootprint;
        UPInt PageMapUsedSpace;
        UPInt BookkeepingFootprint;
        UPInt BookkeepingUsedSpace;
        UPInt DebugInfoFootprint;
        UPInt DebugInfoUsedSpace;
        UPInt UserDebugFootprint;
        UPInt UserDebugUsedSpace;
    };

protected:
    MemoryHeap();
    virtual ~MemoryHeap() { }

public:
    static void SF_STDCALL InitPT(SysAllocPaged* sysAlloc);
    static void SF_STDCALL InitMH(SysAlloc* sysAllocMH);
    static void SF_STDCALL CleanUpPT();
    static void SF_STDCALL CleanUpMH();
    static MemoryHeap* SF_STDCALL CreateRootHeapPT();
    static MemoryHeap* SF_STDCALL CreateRootHeapMH();
    static MemoryHeap* SF_STDCALL CreateRootHeapPT(const HeapDesc& desc);
    static MemoryHeap* SF_STDCALL CreateRootHeapMH(const HeapDesc& desc);
    static bool SF_STDCALL ReleaseRootHeapPT();
    static bool SF_STDCALL ReleaseRootHeapMH();

    virtual void CreateArena(UPInt arena, SysAllocPaged* sysAlloc) = 0;
    virtual void DestroyArena(UPInt arena) = 0;
    virtual bool ArenaIsEmpty(UPInt arena) = 0;

    virtual MemoryHeap* CreateHeap(const char* name, const HeapDesc& desc) = 0;
    MemoryHeap* CreateHeap(const char* name, unsigned flags = 0, UPInt minAlign = 16, UPInt granularity = 16 * 1024,
                           UPInt reserve = 16 * 1024, UPInt threshold = ~UPInt(0), UPInt limit = 0, UPInt heapId = 0,
                           UPInt arena = 0)
    {
        HeapDesc desc(flags, minAlign, granularity, reserve, threshold, limit, heapId, arena);
        return CreateHeap(name, desc);
    }

    void        GetHeapInfo(HeapInfo* infoPtr) const;
    const char* GetName() const        { return Info.pName; }
    UPInt       GetId() const          { return Info.Desc.HeapId; }
    MemoryHeap* GetParentHeap() const  { return Info.pParent; }
    unsigned    GetFlags() const       { return Info.Desc.Flags; }
    UPInt       GetGranularity() const { return Info.Desc.Granularity; }

    virtual void SetLimitHandler(LimitHandler* handler) = 0;
    virtual void SetLimit(UPInt newLimit) = 0;
    UPInt        GetLimit() const { return Info.Desc.Limit; }
    bool         IsThreadSafe() const { return (Info.Desc.Flags & Heap_ThreadUnsafe) == 0; }

    virtual void AddRef() = 0;
    virtual void Release() = 0;
    void         ReleaseOnFree(void* ptr);
    void         AssignToCurrentThread();

    virtual void*       Alloc(UPInt size, const AllocInfo* info = 0) = 0;
    virtual void*       Alloc(UPInt size, UPInt align, const AllocInfo* info = 0) = 0;
    virtual void*       Realloc(void* oldPtr, UPInt newSize) = 0;
    virtual void        Free(void* ptr) = 0;
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, const AllocInfo* info = 0) = 0;
    virtual void*       AllocAutoHeap(const void* thisPtr, UPInt size, UPInt align, const AllocInfo* info = 0) = 0;
    virtual MemoryHeap* GetAllocHeap(const void* thisPtr) = 0;
    virtual UPInt       GetUsableSize(const void* ptr) = 0;
    virtual void*       AllocSysDirect(UPInt size) = 0;
    virtual void        FreeSysDirect(void* ptr, UPInt size) = 0;

    virtual bool  GetStats(StatBag* bag) = 0;
    virtual UPInt GetFootprint() const = 0;
    virtual UPInt GetTotalFootprint() const = 0;
    virtual UPInt GetUsedSpace() const = 0;
    virtual UPInt GetTotalUsedSpace() const = 0;
    virtual void  GetRootStats(RootStats* stats) = 0;
    virtual void  VisitMem(Heap::MemVisitor* visitor, unsigned flags) = 0;
    virtual void  VisitRootSegments(Heap::SegVisitor* visitor) = 0;
    virtual void  VisitHeapSegments(Heap::SegVisitor* visitor) const = 0;
    virtual void  SetTracer(HeapTracer* tracer) = 0;

    void MemReport(StringBuffer& buffer, MemReportType detailed, bool xmlFormat = false);
    void MemReport(MemItem* rootItem, MemReportType detailed);
    bool DumpMemoryLeaks();
    void UltimateCheck();
    void VisitChildHeaps(HeapVisitor* visitor);
    void LockAndVisit(HeapVisitor* visitor);
    void CheckIntegrity();
    void ReleaseCachedMem();
    int  CheckRead(int p) const;

protected:
    virtual void destroyItself() = 0;
    virtual void ultimateCheck() = 0;
    virtual void releaseCachedMem() = 0;
    virtual bool dumpMemoryLeaks() = 0;
    virtual void checkIntegrity() const = 0;
    virtual void getUserDebugStats(RootStats* stats) const = 0;

    typedef List<MemoryHeap> ChildListType;

    UPInt             SelfSize;        // +0x18
    volatile unsigned RefCount;        // +0x20
    UPInt             OwnerThreadId;   // +0x28
    void*             pAutoRelease;    // +0x30
    HeapInfo          Info;            // +0x38
    ChildListType     ChildHeaps;      // +0x88
    mutable Lock      HeapLock;        // +0x98
    bool              UseLocks;        // +0xc0
    bool              TrackDebugInfo;  // +0xc1
};

}  // namespace Scaleform

#endif
