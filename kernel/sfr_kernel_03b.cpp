// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapPT_AllocEngine (the
// per-heap PT engine: tiny-block lists, bit-set segments, direct system segments, the footprint limit and the
// segment caches). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426cf7a0-0x1426d1d10 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_memoryheap.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_root.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_allocengine.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

AllocEngine::AllocEngine(SysAllocPaged* sysAlloc, MemoryHeapPT* heap, unsigned allocFlags, UPInt minAlignSize,
                         UPInt granularity, UPInt reserve, UPInt threshold, UPInt limit)
    : pHeap(heap),
      pSysAlloc(sysAlloc),
      pBookkeeper(GlobalRoot->GetBookkeeper()),
      MinAlignShift(Alg::UpperBit(minAlignSize)),
      MinAlignMask((UPInt(1) << MinAlignShift) - 1),
      Allocator(MinAlignShift),
      AllowTinyBlocks((allocFlags & Heap_AllowTinyBlocks) != 0),
      AllowDynaSize((allocFlags & Heap_AllowDynaSize) != 0),
      Valid(false),
      HasRealloc(false),
      SysGranularity(Heap_PageSize),
      Granularity((granularity + Heap_PageMask) & ~UPInt(Heap_PageMask)),
      Reserve((reserve + Granularity - 1) / Granularity * Granularity),
      Threshold(threshold),
      SysDirectThreshold(0),
      Footprint(0),
      TinyFreeSpace(0),
      SysDirectSpace(0),
      pCachedBSeg(0),
      pCachedTSeg(0),
      Limit(limit),
      pLimHandler(0)
{
    // the caller holds the root lock
    SysAllocPaged::Info i;
    memset(&i, 0, sizeof(SysAllocPaged::Info));
    pSysAlloc->GetInfo(&i);
    HasRealloc = i.HasRealloc;
    if (i.Granularity < Heap_PageSize)
        i.Granularity = Heap_PageSize;
    SysGranularity     = i.Granularity;
    SysDirectThreshold = i.SysDirectThreshold;
    Granularity        = (Granularity + i.Granularity - 1) / i.Granularity * i.Granularity;
    if (i.MaxHeapGranularity)
    {
        i.MaxHeapGranularity = (i.MaxHeapGranularity + Heap_PageMask) & ~UPInt(Heap_PageMask);
        if (Granularity > i.MaxHeapGranularity)
        {
            Granularity     = i.MaxHeapGranularity;
            AllowTinyBlocks = false;
            AllowDynaSize   = false;
        }
    }

    // direct system requests far below the granularity waste memory: keep at least 32 system granules
    // (zero still means "everything goes to the system")
    if (Threshold < 32 * SysGranularity && Threshold)
        Threshold = 32 * SysGranularity;

    if (SysDirectThreshold)
    {
        if (Threshold > SysDirectThreshold)
            Threshold = SysDirectThreshold;
        if (Threshold < Heap_PageSize && Threshold)
            Threshold = Heap_PageSize;
        if (Granularity > SysDirectThreshold)
        {
            Granularity = SysDirectThreshold;
            Granularity = (Granularity + Heap_PageMask) & ~UPInt(Heap_PageMask);
        }
        if (SysGranularity > SysDirectThreshold)
        {
            SysGranularity = SysDirectThreshold;
            SysGranularity = (SysGranularity + Heap_PageMask) & ~UPInt(Heap_PageMask);
        }
        if (Reserve > SysDirectThreshold)
            Reserve = SysDirectThreshold;
        AllowDynaSize = false;
    }

    bool t;
    Valid = Reserve ? allocSegmentBitSet(Reserve, minAlignSize, Granularity, &t) != 0 : true;
}

AllocEngine::~AllocEngine()
{
    FreeAll();
}

// drops every segment; the heap stays usable but empty (heap destruction, under the root lock)
void AllocEngine::FreeAll()
{
    HeapSegment* seg;
    while (!SegmentList.IsNull(seg = SegmentList.GetFirst()))
        freeSegment(seg);
    Allocator.Reset();
}

UPInt AllocEngine::SetLimit(UPInt lim)
{
    UPInt segSize = calcDynaSize();
    return Limit = (lim + segSize - 1) / segSize * segSize;
}

// the caller holds the root lock; the limit handler runs with it released
HeapSegment* AllocEngine::allocSegment(unsigned segType, UPInt dataSize, UPInt alignSize, UPInt bookkeepingSize,
                                       bool* limHandlerOK)
{
    if (Limit && Footprint + dataSize > Limit && pLimHandler)
    {
        LockSafe::TmpUnlocker unlocker(GlobalRoot->GetLock());
        *limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                        OnExceedLimit(pHeap, Footprint + dataSize - Limit);
        return 0;
    }
    *limHandlerOK = false;

    UPInt        totalSegSize = (sizeof(HeapSegment) + bookkeepingSize + Heap_MinMask) & ~UPInt(Heap_MinMask);
    HeapSegment* seg          = (HeapSegment*)pBookkeeper->Alloc(totalSegSize);
    if (seg)
    {
        seg->SelfSize  = totalSegSize;
        seg->SegType   = UPIntHalf(segType);
        seg->Alignment = Alg::UpperBit(UInt32(alignSize));
        seg->UseCount  = 0;
        seg->pHeap     = pHeap;
        seg->DataSize  = dataSize;
        seg->pData     = 0;
        if (dataSize)
        {
            // the system block is at least page aligned; the segment keeps the requested alignment
            if (alignSize < Heap_PageSize)
                alignSize = Heap_PageSize;
            seg->pData = (UByte*)pSysAlloc->Alloc(dataSize, alignSize);
            if (seg->pData == 0)
            {
                pBookkeeper->Free(seg, totalSegSize);
                return 0;
            }
            if (!GlobalPageTable->MapRange(seg->pData, seg->DataSize))
            {
                pSysAlloc->Free(seg->pData, dataSize, alignSize);
                pBookkeeper->Free(seg, totalSegSize);
                return 0;
            }
            GlobalPageTable->SetSegmentInRange(UPInt(seg->pData), seg->DataSize, seg);
        }
        SegmentList.PushFront(seg);
        Footprint += seg->DataSize;
        *limHandlerOK = true;
        return seg;
    }
    return 0;
}

// a block taken from the system allocator as is (above its SysDirectThreshold); the head bytes skipped to reach page
// alignment are kept in UseCount with the top bit set
HeapSegment* AllocEngine::allocSegmentNoGranulator(UPInt dataSize, UPInt alignSize, bool* limHandlerOK)
{
    if (Limit && Footprint + dataSize > Limit && pLimHandler)
    {
        *limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                        OnExceedLimit(pHeap, Footprint + dataSize - Limit);
        return 0;
    }
    *limHandlerOK = false;

    LockSafe::Locker lock(GlobalRoot->GetLock());
    HeapSegment*     seg = (HeapSegment*)pBookkeeper->Alloc(sizeof(HeapSegment));
    if (seg)
    {
        seg->SelfSize  = sizeof(HeapSegment);
        seg->SegType   = UPIntHalf(Heap_SegmentSystem);
        seg->Alignment = 0;
        seg->UseCount  = 0;
        seg->pHeap     = pHeap;
        seg->DataSize  = 0;
        seg->pData     = 0;
        if (dataSize)
        {
            UPInt actualSize, actualAlign;
            seg->pData = (UByte*)pSysAlloc->AllocSysDirect(dataSize, alignSize, &actualSize, &actualAlign);
            if (seg->pData == 0)
            {
                pBookkeeper->Free(seg, seg->SelfSize);
                return 0;
            }
            UPInt pageAlign = (alignSize > Heap_PageSize) ? alignSize : Heap_PageSize;
            UPInt headBytes = ((UPInt(seg->pData) + pageAlign - 1) & ~(pageAlign - 1)) - UPInt(seg->pData);
            seg->Alignment  = Alg::UpperBit(UInt32(actualAlign));
            seg->UseCount   = 0x80000000 | headBytes;
            seg->DataSize   = actualSize - headBytes;
            seg->pData     += headBytes;
            if (!GlobalPageTable->MapRange(seg->pData, seg->DataSize))
            {
                pSysAlloc->FreeSysDirect(seg->pData - headBytes, seg->DataSize + headBytes,
                                         UPInt(1) << seg->Alignment);
                pSysAlloc->FreeSysDirect(seg->pData, dataSize, alignSize);
                pBookkeeper->Free(seg, seg->SelfSize);
                return 0;
            }
            GlobalPageTable->SetSegmentInRange(UPInt(seg->pData), seg->DataSize, seg);
        }
        SegmentList.PushFront(seg);
        Footprint += seg->DataSize + (seg->UseCount & 0x7FFFFFFF);
        *limHandlerOK = true;
        return seg;
    }
    return 0;
}

HeapSegment* AllocEngine::allocSegmentLocked(unsigned segType, UPInt dataSize, UPInt alignSize,
                                             UPInt bookkeepingSize, bool* limHandlerOK)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    return allocSegment(segType, dataSize, alignSize, bookkeepingSize, limHandlerOK);
}

HeapSegment* AllocEngine::allocSegmentBitSet(UPInt size, UPInt alignSize, UPInt granularity, bool* limHandlerOK)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    UPInt alignment = (alignSize > MinAlignMask + 1) ? alignSize : MinAlignMask + 1;
    UPInt extraTail = (alignment > Heap_PageSize) ? alignment : 0;
    UPInt segSize   = (size + extraTail + alignment - 1) & ~(alignment - 1);
    segSize         = (segSize + granularity - 1) / granularity * granularity;

    HeapSegment* seg = allocSegment(Heap_SegmentBitSet, segSize, Heap_PageSize, Allocator.GetBitSetBytes(segSize),
                                    limHandlerOK);
    if (seg)
        Allocator.InitSegment(seg);
    return seg;
}

// the caller holds the root lock
void AllocEngine::freeSegment(HeapSegment* seg)
{
    UPInt freeingSize = seg->DataSize;
    if (pLimHandler)
        ((MemoryHeap::LimitHandler*)pLimHandler)->OnFreeSegment(pHeap, freeingSize);

    Footprint -= freeingSize;
    GlobalPageTable->UnmapRange(seg->pData, freeingSize);
    UPInt alignSize = UPInt(1) << seg->Alignment;
    if (seg->UseCount & 0x80000000)
    {
        Footprint -= (seg->UseCount & 0x7FFFFFFF);
        pSysAlloc->FreeSysDirect(seg->pData - (seg->UseCount & 0x7FFFFFFF),
                                 freeingSize + (seg->UseCount & 0x7FFFFFFF), alignSize);
    }
    else
    {
        pSysAlloc->Free(seg->pData, freeingSize, (alignSize > Heap_PageSize) ? alignSize : Heap_PageSize);
    }
    SegmentListType::Remove(seg);
    pBookkeeper->Free(seg, seg->SelfSize);
}

void AllocEngine::freeSegmentLocked(HeapSegment* seg)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    freeSegment(seg);
}

// an emptied bit-set segment is cached (one at a time) unless the heap is empty, or released when above the reserve
void AllocEngine::freeSegmentBitSet(HeapSegment* seg)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    if (pCachedBSeg && pCachedBSeg != seg && pCachedBSeg->UseCount == 0)
    {
        Allocator.ReleaseSegment(pCachedBSeg);
        freeSegment(pCachedBSeg);
    }
    pCachedBSeg = 0;

    if (GetUsedSpace() && seg->DataSize <= 4 * Granularity)
    {
        pCachedBSeg = seg;
    }
    else
    {
        if (Footprint >= Reserve + seg->DataSize)
        {
            Allocator.ReleaseSegment(seg);
            freeSegment(seg);
        }
    }
}

void* AllocEngine::allocSysDirect(UPInt dataSize, UPInt alignSize)
{
    bool         limHandlerOK = false;
    HeapSegment* seg;
    if (SysDirectThreshold && dataSize >= SysDirectThreshold)
    {
        do
        {
            seg = allocSegmentNoGranulator(dataSize, alignSize, &limHandlerOK);
            if (seg)
            {
                SysDirectSpace += seg->DataSize;
                return seg->pData;
            }
        } while (limHandlerOK);
    }

    // no direct block: a whole-granule system segment
    dataSize     = (dataSize + (alignSize - 1)) & ~(alignSize - 1);
    dataSize     = (dataSize + SysGranularity - 1) / SysGranularity * SysGranularity;
    limHandlerOK = false;
    do
    {
        seg = allocSegmentLocked(Heap_SegmentSystem, dataSize, alignSize, 0, &limHandlerOK);
        if (seg)
        {
            SysDirectSpace += seg->DataSize;
            return seg->pData;
        }
    } while (limHandlerOK);
    return 0;
}

// dynamic granularity: 1/16 of the used space rounded up to the granularity, then down to a power of two, clamped
// to [1, 4] granules
UPInt AllocEngine::calcDynaSize() const
{
    if (AllowDynaSize)
    {
        UPInt dynaSize = (((GetUsedSpace() + 16) / 16) + Granularity - 1) / Granularity * Granularity;
        dynaSize       = UPInt(1) << Alg::UpperBit(dynaSize);
        if (dynaSize < Granularity)
            dynaSize = Granularity;
        if (dynaSize > 4 * Granularity)
            dynaSize = 4 * Granularity;
        return dynaSize;
    }
    return Granularity;
}

HeapSegment* AllocEngine::allocSegmentBitSet(UPInt size, UPInt alignSize, bool* limHandlerOK)
{
    HeapSegment* seg = allocSegmentBitSet(size, alignSize, calcDynaSize(), limHandlerOK);
    if (seg)
        return seg;
    return *limHandlerOK ? allocSegmentBitSet(size, alignSize, Granularity, limHandlerOK) : 0;
}

void* AllocEngine::allocBitSet(UPInt size)
{
    void*        ptr;
    HeapSegment* seg;
    bool         limHandlerOK = false;
    do
    {
        ptr = Allocator.Alloc(size, &seg);
        if (ptr)
        {
            ++seg->UseCount;
            return ptr;
        }
        allocSegmentBitSet(size, MinAlignMask + 1, &limHandlerOK);
    } while (limHandlerOK);
    return 0;
}

void* AllocEngine::allocBitSet(UPInt size, UPInt alignSize)
{
    void*        ptr;
    HeapSegment* seg;
    bool         limHandlerOK = false;
    do
    {
        ptr = Allocator.Alloc(size, alignSize, &seg);
        if (ptr)
        {
            ++seg->UseCount;
            return ptr;
        }
        allocSegmentBitSet(size, alignSize, &limHandlerOK);
    } while (limHandlerOK);
    return 0;
}

// a fresh tiny segment (room for at least 4 blocks, whole pages), all of it pushed on the size's free list
void* AllocEngine::allocSegmentTiny(unsigned sizeIdx)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    bool  limHandlerOK;
    UPInt blockSize = (sizeIdx + 1) << MinAlignShift;
    UPInt segSize   = (blockSize * 4 > Heap_PageSize) ? blockSize * 4 : Heap_PageSize;
    segSize         = (segSize + Heap_PageMask) & ~UPInt(Heap_PageMask);

    HeapSegment* seg = allocSegment(sizeIdx, segSize, Heap_PageSize, 0, &limHandlerOK);
    if (seg)
    {
        UPInt         numBlocks = seg->DataSize / blockSize;
        UByte*        ptr       = seg->pData;
        TinyListType& lst       = TinyBlocks[sizeIdx];
        UPInt         i;
        for (i = 0; i < numBlocks; ++i, ptr += blockSize)
        {
            ((TinyBlock*)ptr)->pSegment = seg;
            lst.PushBack((TinyBlock*)ptr);
        }
        TinyFreeSpace += seg->DataSize;
        return seg->pData;
    }
    return 0;
}

void AllocEngine::releaseSegmentTiny(HeapSegment* seg)
{
    UPInt  i;
    UPInt  blockSize = (seg->SegType + 1) << MinAlignShift;
    UPInt  numBlocks = seg->DataSize / blockSize;
    UByte* ptr       = seg->pData;
    for (i = 0; i < numBlocks; ++i, ptr += blockSize)
        TinyListType::Remove((TinyBlock*)ptr);
    TinyFreeSpace -= seg->DataSize;
    freeSegment(seg);
}

void AllocEngine::freeSegmentTiny(HeapSegment* seg)
{
    LockSafe::Locker lock(GlobalRoot->GetLock());
    if (pCachedTSeg && pCachedTSeg != seg && pCachedTSeg->UseCount == 0)
        releaseSegmentTiny(pCachedTSeg);
    pCachedTSeg = 0;

    if (GetUsedSpace())
    {
        pCachedTSeg = seg;
    }
    else
    {
        if (Footprint >= Reserve + seg->DataSize)
            releaseSegmentTiny(seg);
    }
}

inline void* AllocEngine::allocTiny(unsigned sizeIdx)
{
    TinyBlock* ptr = TinyBlocks[sizeIdx].GetFirst();
    if (TinyBlocks[sizeIdx].IsNull(ptr))
    {
        ptr = (TinyBlock*)allocSegmentTiny(sizeIdx);
        if (ptr == 0)
            return 0;
    }
    TinyListType::Remove(ptr);
    ++ptr->pSegment->UseCount;
    TinyFreeSpace -= (sizeIdx + 1) << MinAlignShift;
    return ptr;
}

inline void AllocEngine::freeTiny(HeapSegment* seg, TinyBlock* ptr)
{
    ptr->pSegment = seg;
    TinyBlocks[seg->SegType].PushFront(ptr);
    TinyFreeSpace += (seg->SegType + 1) << MinAlignShift;
    if (--seg->UseCount == 0)
        freeSegmentTiny(seg);
}

inline void* AllocEngine::reallocGeneral(HeapSegment* seg, void* oldPtr, UPInt oldSize, UPInt newSize,
                                         UPInt alignShift)
{
    void* newPtr = Alloc(newSize, UPInt(1) << alignShift);
    if (newPtr)
    {
        memcpy(newPtr, oldPtr, (oldSize < newSize) ? oldSize : newSize);
        Free(seg, oldPtr);
    }
    return newPtr;
}

void* AllocEngine::reallocSysDirect(HeapSegment* seg, void* oldPtr, UPInt newSize)
{
    if (seg->UseCount & 0x80000000)
    {
        // a block straight from the system allocator: no in-place growth
        return reallocGeneral(seg, oldPtr, seg->DataSize, newSize, seg->Alignment);
    }

    UPInt alignSize = UPInt(1) << seg->Alignment;
    newSize         = (newSize + (alignSize - 1)) & ~(alignSize - 1);
    newSize         = (newSize + SysGranularity - 1) / SysGranularity * SysGranularity;
    UPInt oldSize   = seg->DataSize;
    if (newSize == oldSize)
        return seg->pData;

    // shrunk below the direct threshold: move it into a regular segment
    if (newSize < seg->DataSize && 2 * newSize < Threshold)
        return reallocGeneral(seg, oldPtr, seg->DataSize, newSize, seg->Alignment);

    bool ok = false;
    if (newSize > oldSize)
    {
        if (Limit && Footprint + newSize - oldSize > Limit && pLimHandler)
        {
            bool limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                                OnExceedLimit(pHeap, Footprint + newSize - oldSize - Limit);
            if (!limHandlerOK || Footprint + newSize - oldSize > Limit)
                return reallocGeneral(seg, oldPtr, oldSize, newSize, seg->Alignment);
        }
    }

    {
        LockSafe::Locker lock(GlobalRoot->GetLock());
        if (HasRealloc && pSysAlloc->ReallocInPlace(seg->pData, oldSize, newSize, alignSize))
        {
            if (newSize > oldSize)
            {
                if (!GlobalPageTable->RemapRange(seg->pData, newSize, oldSize))
                {
                    // could not map the grown part: shrink the block back
                    ok = pSysAlloc->ReallocInPlace(seg->pData, newSize, oldSize, alignSize);
                    return 0;
                }
            }
            else
            {
                ok = GlobalPageTable->RemapRange(seg->pData, newSize, oldSize);
            }
            Footprint      -= oldSize;
            Footprint      += newSize;
            SysDirectSpace -= oldSize;
            SysDirectSpace += newSize;
            seg->DataSize   = newSize;
            return seg->pData;
        }
    }
    return reallocGeneral(seg, oldPtr, oldSize, newSize, seg->Alignment);
}

void* AllocEngine::Alloc(UPInt size)
{
    // malloc semantics: zero and tiny sizes get the smallest block
    if (size < Heap_MinSize)
        size = Heap_MinSize;
    size = (size + MinAlignMask) & ~MinAlignMask;

    if (AllowTinyBlocks && size <= (UPInt(Heap_TinyBinSize) << MinAlignShift))
    {
        // a second try after the limit handler may have freed something; then fall through to a bit-set block
        void* ptr;
        ptr = allocTiny(unsigned((size - 1) >> MinAlignShift));
        if (ptr)
            return ptr;
        ptr = allocTiny(unsigned((size - 1) >> MinAlignShift));
        if (ptr)
            return ptr;
    }
    if (size < Threshold)
        return allocBitSet(size);
    return allocSysDirect(size, Heap_PageSize);
}

// tiny bin used for a block size when the alignment must be the size rounded up to a power of two
static const unsigned TinyPow2AllocType[Heap_TinyBinSize] = { 0, 1, 3, 3, 7, 7, 7, 7 };

void* AllocEngine::Alloc(UPInt size, UPInt alignSize)
{
    if ((alignSize - 1) <= MinAlignMask)
        return Alloc(size);

    if (size < Heap_MinSize)
        size = Heap_MinSize;
    if (alignSize < MinAlignMask + 1)
        alignSize = MinAlignMask + 1;
    if (size < alignSize)
        size = alignSize;
    size = (size + alignSize - 1) & ~(alignSize - 1);

    if (AllowTinyBlocks && size <= (UPInt(Heap_TinyBinSize) << MinAlignShift))
    {
        void* ptr;
        ptr = allocTiny(TinyPow2AllocType[(size - 1) >> MinAlignShift]);
        if (ptr)
            return ptr;
        ptr = allocTiny(TinyPow2AllocType[(size - 1) >> MinAlignShift]);
        if (ptr)
            return ptr;
    }
    if (size < Threshold)
        return allocBitSet(size, alignSize);
    return allocSysDirect(size, alignSize);
}

void* AllocEngine::Realloc(HeapSegment* seg, void* oldPtr, UPInt newSize)
{
    void* newPtr  = 0;
    UPInt oldSize = 0;

    if (newSize < Heap_MinSize)
        newSize = Heap_MinSize;
    newSize = (newSize + MinAlignMask) & ~MinAlignMask;

    if (seg->SegType <= Heap_SegmentTiny8)
    {
        oldSize = (seg->SegType + 1) << MinAlignShift;
        if (newSize <= oldSize)
            return oldPtr;
        return reallocGeneral(seg, oldPtr, oldSize, newSize, MinAlignShift + TinyPow2AllocType[seg->SegType]);
    }
    if (seg->SegType == Heap_SegmentBitSet)
    {
        newPtr = Allocator.ReallocInPlace(seg, oldPtr, newSize, &oldSize);
        if (newPtr)
            return newPtr;
        return reallocGeneral(seg, oldPtr, oldSize, newSize, Allocator.GetAlignShift(seg, oldPtr, oldSize));
    }
    return reallocSysDirect(seg, oldPtr, newSize);
}

void AllocEngine::Free(HeapSegment* seg, void* ptr)
{
    if (seg->SegType <= Heap_SegmentTiny8)
    {
        freeTiny(seg, (TinyBlock*)ptr);
        return;
    }
    if (seg->SegType == Heap_SegmentBitSet)
    {
        Allocator.Free(seg, ptr);
        if (--seg->UseCount == 0)
            freeSegmentBitSet(seg);
        return;
    }
    SysDirectSpace -= seg->DataSize;
    freeSegmentLocked(seg);
}

void* AllocEngine::Realloc(void* oldPtr, UPInt newSize)
{
    return Realloc(GlobalPageTable->GetSegment(UPInt(oldPtr)), oldPtr, newSize);
}

void AllocEngine::Free(void* ptr)
{
    Free(GlobalPageTable->GetSegment(UPInt(ptr)), ptr);
}

UPInt AllocEngine::GetUsableSize(HeapSegment* seg, const void* ptr)
{
    if (seg->SegType <= Heap_SegmentTiny8)
        return UPInt(seg->SegType + 1) << MinAlignShift;
    if (seg->SegType == Heap_SegmentBitSet)
        return Allocator.GetUsableSize(seg, ptr);
    return seg->DataSize;
}

UPInt AllocEngine::GetUsableSize(const void* ptr)
{
    return GetUsableSize(GlobalPageTable->GetSegment(UPInt(ptr)), ptr);
}

UPInt AllocEngine::GetFootprint() const
{
    return Footprint;
}

UPInt AllocEngine::GetUsedSpace() const
{
    return Footprint - Allocator.GetTotalFreeSpace() - TinyFreeSpace;
}

// the caller holds the root lock
void AllocEngine::ReleaseCachedMem()
{
    if (pCachedBSeg && pCachedBSeg->UseCount == 0)
    {
        Allocator.ReleaseSegment(pCachedBSeg);
        freeSegment(pCachedBSeg);
    }
    if (pCachedTSeg && pCachedTSeg->UseCount == 0)
        freeSegmentTiny(pCachedTSeg);
    pCachedBSeg = 0;
    pCachedTSeg = 0;
}

void AllocEngine::VisitMem(MemVisitor* visitor, unsigned flags) const
{
    if (flags & MemVisitor::VF_SysAlloc)
        pSysAlloc->VisitMem(visitor);
    if (flags & MemVisitor::VF_Starter)
        GlobalPageTable->VisitMem(visitor);
    if (flags & MemVisitor::VF_Bookkeeper)
        pBookkeeper->VisitMem(visitor, flags);
    if (flags & MemVisitor::VF_Heap)
    {
        const HeapSegment* seg = SegmentList.GetFirst();
        while (!SegmentList.IsNull(seg))
        {
            switch (seg->SegType)
            {
            case Heap_SegmentTiny1:
            case Heap_SegmentTiny2:
            case Heap_SegmentTiny3:
            case Heap_SegmentTiny4:
            case Heap_SegmentTiny5:
            case Heap_SegmentTiny6:
            case Heap_SegmentTiny7:
            case Heap_SegmentTiny8:
                visitor->Visit(seg, UPInt(seg->pData), seg->DataSize, MemVisitor::Cat_AllocTiny);
                {
                    // the tail that never makes a whole block stays free
                    UPInt tinySize = (seg->SegType + 1) << MinAlignShift;
                    UPInt tailSize = seg->DataSize % tinySize;
                    if (tailSize)
                    {
                        UPInt tail = UPInt(seg->pData) + seg->DataSize / tinySize * tinySize;
                        visitor->Visit(seg, tail, tailSize, MemVisitor::Cat_AllocTinyFree);
                    }
                }
                break;
            case Heap_SegmentBookkeeper:   // bookkeeper segments never sit in a heap list
                break;
            case Heap_SegmentSystem:
                visitor->Visit(seg, UPInt(seg->pData), seg->DataSize, MemVisitor::Cat_SystemDirect);
                break;
            case Heap_SegmentBitSet:
                visitor->Visit(seg, UPInt(seg->pData), seg->DataSize, MemVisitor::Cat_AllocBitSet);
                break;
            }
            seg = seg->pNext;
        }
        if (flags & MemVisitor::VF_HeapFree)
        {
            Allocator.VisitMem(visitor, MemVisitor::Cat_AllocBitSetFree);
            UPInt i;
            for (i = 0; i < Heap_TinyBinSize; ++i)
            {
                const TinyListType& lst   = TinyBlocks[i];
                const TinyBlock*    block = lst.GetFirst();
                while (!lst.IsNull(block))
                {
                    visitor->Visit(block->pSegment, UPInt(block), (i + 1) << MinAlignShift,
                                   MemVisitor::Cat_AllocTinyFree);
                    block = block->pNext;
                }
            }
        }
    }
}

void AllocEngine::VisitSegments(SegVisitor* visitor) const
{
    const HeapSegment* seg = SegmentList.GetFirst();
    while (!SegmentList.IsNull(seg))
    {
        visitor->Visit(SegVisitor::Seg_Heap, seg->pHeap, UPInt(seg->pData),
                       (seg->DataSize + Heap_PageMask) & ~UPInt(Heap_PageMask));
        seg = seg->pNext;
    }
    Allocator.VisitUnused(visitor, SegVisitor::Seg_HeapUnused);
}

void AllocEngine::GetHeapOtherStats(HeapOtherStats* otherStats) const
{
    otherStats->Segments           = 0;
    otherStats->Bookkeeping        = 0;
    otherStats->DynamicGranularity = calcDynaSize();
    otherStats->SysDirectSpace     = SysDirectSpace;
    const HeapSegment* seg = SegmentList.GetFirst();
    while (!SegmentList.IsNull(seg))
    {
        otherStats->Segments++;
        otherStats->Bookkeeping += seg->SelfSize;
        seg = seg->pNext;
    }
}

}}  // namespace Scaleform::HeapPT
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocEngine@HeapPT@Scaleform@@QEAA@PEAVSysAllocPaged@2@PEAVMemoryHeapPT@2@I_K2222@Z 0x1426cf7b0
// MS2-PIN: ??1AllocEngine@HeapPT@Scaleform@@QEAA@XZ 0x1426cfb00
// MS2-PIN: ?Alloc@AllocEngine@HeapPT@Scaleform@@QEAAPEAX_K0@Z 0x1426cfb50
// MS2-PIN: ?Alloc@AllocEngine@HeapPT@Scaleform@@QEAAPEAX_K@Z 0x1426cfe00
// MS2-PIN: ?Free@AllocEngine@HeapPT@Scaleform@@QEAAXPEAUHeapSegment@Heap@3@PEAX@Z 0x1426cff50
// MS2-PIN: ?FreeAll@AllocEngine@HeapPT@Scaleform@@QEAAXXZ 0x1426d0180
// MS2-PIN: ?GetFootprint@AllocEngine@HeapPT@Scaleform@@QEBA_KXZ 0x1426d02b0
// MS2-PIN: ?GetHeapOtherStats@AllocEngine@HeapPT@Scaleform@@QEBAXPEAUHeapOtherStats@23@@Z 0x1426d02c0
// MS2-PIN: ?GetUsableSize@AllocEngine@HeapPT@Scaleform@@QEAA_KPEAUHeapSegment@Heap@3@PEBX@Z 0x1426d0340
// MS2-PIN: ?GetUsedSpace@AllocEngine@HeapPT@Scaleform@@QEBA_KXZ 0x1426d0400
// MS2-PIN: ?Realloc@AllocEngine@HeapPT@Scaleform@@QEAAPEAXPEAUHeapSegment@Heap@3@PEAX_K@Z 0x1426d0430
// MS2-PIN: ?Realloc@AllocEngine@HeapPT@Scaleform@@QEAAPEAXPEAX_K@Z 0x1426d0550
// MS2-PIN: ?ReleaseCachedMem@AllocEngine@HeapPT@Scaleform@@QEAAXXZ 0x1426d06d0
// MS2-PIN: ?SetLimit@AllocEngine@HeapPT@Scaleform@@QEAA_K_K@Z 0x1426d0740
// MS2-PIN: ?VisitMem@AllocEngine@HeapPT@Scaleform@@QEBAXPEAVMemVisitor@Heap@3@I@Z 0x1426d0780
// MS2-PIN: ?VisitSegments@AllocEngine@HeapPT@Scaleform@@QEBAXPEAVSegVisitor@Heap@3@@Z 0x1426d0940
// MS2-PIN: ?allocBitSet@AllocEngine@HeapPT@Scaleform@@AEAAPEAX_K0@Z 0x1426d09d0
// MS2-PIN: ?allocBitSet@AllocEngine@HeapPT@Scaleform@@AEAAPEAX_K@Z 0x1426d0a90
// MS2-PIN: ?allocSegment@AllocEngine@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@I_K00PEA_N@Z 0x1426d0b50
// MS2-PIN: ?allocSegmentBitSet@AllocEngine@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@_K00PEA_N@Z 0x1426d0d20
// MS2-PIN: ?allocSegmentBitSet@AllocEngine@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@_K0PEA_N@Z 0x1426d0e20
// MS2-PIN: ?allocSegmentLocked@AllocEngine@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@I_K00PEA_N@Z 0x1426d0ea0
// MS2-PIN: ?allocSegmentNoGranulator@AllocEngine@HeapPT@Scaleform@@AEAAPEAUHeapSegment@Heap@3@_K0PEA_N@Z 0x1426d0f30
// MS2-PIN: ?allocSegmentTiny@AllocEngine@HeapPT@Scaleform@@AEAAPEAXI@Z 0x1426d1180
// MS2-PIN: ?allocSysDirect@AllocEngine@HeapPT@Scaleform@@AEAAPEAX_K0@Z 0x1426d1290
// MS2-PIN: ?allocTiny@AllocEngine@HeapPT@Scaleform@@AEAAPEAXI@Z 0x1426d13d0
// MS2-PIN: ?calcDynaSize@AllocEngine@HeapPT@Scaleform@@AEBA_KXZ 0x1426d1550
// MS2-PIN: ?freeSegment@AllocEngine@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426d1600
// MS2-PIN: ?freeSegmentBitSet@AllocEngine@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426d16f0
// MS2-PIN: ?freeSegmentLocked@AllocEngine@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426d17e0
// MS2-PIN: ?freeSegmentTiny@AllocEngine@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426d1840
// MS2-PIN: ?reallocGeneral@AllocEngine@HeapPT@Scaleform@@AEAAPEAXPEAUHeapSegment@Heap@3@PEAX_K22@Z 0x1426d1900
// MS2-PIN: ?reallocSysDirect@AllocEngine@HeapPT@Scaleform@@AEAAPEAXPEAUHeapSegment@Heap@3@PEAX_K@Z 0x1426d1990
// MS2-PIN: ?releaseSegmentTiny@AllocEngine@HeapPT@Scaleform@@AEAAXPEAUHeapSegment@Heap@3@@Z 0x1426d1bd0
// MS2-PIN: ??0?$List@UHeapSegment@Heap@Scaleform@@U123@@Scaleform@@QEAA@XZ 0x1426cf7a0
