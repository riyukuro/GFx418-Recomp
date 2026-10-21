// Recovered Scaleform GFx 4.1.18: the PT general allocator (HeapPT_AllocBitSet2, exe 0x1426f1520..). Two bits per
// block encode busy runs and their sizes; the free runs go to a FreeBin. 0x630 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_ALLOCBITSET2_H
#define MS2_SF_KERNEL_HEAPPT_ALLOCBITSET2_H

#include "ms2/scaleform/kernel/sf_heapbitset2.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_freebin.h"

namespace Scaleform { namespace HeapPT {

class AllocBitSet2
{
public:
    AllocBitSet2(UPInt minAlignShift);

    void Reset() { Bin.Reset(); }

    static UInt32* GetBitSet(const HeapSegment* seg) { return (UInt32*)(((UByte*)seg) + sizeof(HeapSegment)); }

    UPInt GetBitSetWords(UPInt dataSize) const { return Heap::BitSet2::GetBitSetSize(dataSize, MinAlignShift); }
    UPInt GetBitSetBytes(UPInt dataSize) const { return GetBitSetWords(dataSize) * sizeof(UInt32); }

    void  InitSegment(HeapSegment* seg);
    void  ReleaseSegment(HeapSegment* seg);

    void* Alloc(UPInt size, HeapSegment** allocSeg);
    void* Alloc(UPInt size, UPInt alignSize, HeapSegment** allocSeg);
    void  Free(HeapSegment* seg, void* ptr);
    void* ReallocInPlace(HeapSegment* seg, void* oldPtr, UPInt newSize, UPInt* oldSize);

    UPInt GetUsableSize(const HeapSegment* seg, const void* ptr) const;
    UPInt GetAlignShift(const HeapSegment* seg, const void* ptr, UPInt size) const;

    UPInt GetTotalFreeSpace() const { return Bin.GetTotalFreeSpace(MinAlignShift); }
    void  VisitMem(MemVisitor* visitor, MemVisitor::Category cat) const { Bin.VisitMem(visitor, MinAlignShift, cat); }
    void  VisitUnused(SegVisitor* visitor, unsigned cat) const { Bin.VisitUnused(visitor, MinAlignShift, cat); }
    void  CheckIntegrity() const { Bin.CheckIntegrity(MinAlignShift); }

private:
    UPInt   MinAlignShift;
    UPInt   MinAlignMask;
    FreeBin Bin;
};

}}  // namespace Scaleform::HeapPT

#endif
