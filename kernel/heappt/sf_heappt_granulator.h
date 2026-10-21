// Recovered Scaleform GFx 4.1.18: the PT segment granulator (HeapPT_Granulator, exe 0x1426f01d0..). Takes big segments
// from a SysAllocPaged and hands out smaller aligned pieces through an AllocLite; segment headers (TreeSeg) are kept on
// dedicated header pages. 0xc8 bytes.
#ifndef MS2_SF_KERNEL_HEAPPT_GRANULATOR_H
#define MS2_SF_KERNEL_HEAPPT_GRANULATOR_H

#include "ms2/scaleform/kernel/sf_sysalloc.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_alloclite.h"

namespace Scaleform { namespace HeapPT {

struct HdrPage : ListNode<HdrPage>
{
    UPInt UseCount;
    UPInt Filler[5];   // pads the page header to sizeof(TreeSeg)
};

class Granulator
{
    typedef TreeSeg Segment;

public:
    // the free list reuses the two address-tree child links
    struct SegListAccessor
    {
        static void           SetPrev(Segment* self, Segment* what) { self->AddrChild[0] = what; }
        static void           SetNext(Segment* self, Segment* what) { self->AddrChild[1] = what; }
        static const Segment* GetPrev(const Segment* self) { return self->AddrChild[0]; }
        static const Segment* GetNext(const Segment* self) { return self->AddrChild[1]; }
        static Segment*       GetPrev(Segment* self) { return self->AddrChild[0]; }
        static Segment*       GetNext(Segment* self) { return self->AddrChild[1]; }
    };
    // used segments keyed by buffer address
    struct SegTreeAccessor
    {
        static UPInt          GetKey(const Segment* n) { return UPInt(n->Buffer); }
        static Segment*       GetChild(Segment* n, UPInt i) { return n->AddrChild[i]; }
        static const Segment* GetChild(const Segment* n, UPInt i) { return n->AddrChild[i]; }
        static Segment**      GetChildPtr(Segment* n, UPInt i) { return &n->AddrChild[i]; }
        static Segment*       GetParent(Segment* n) { return n->AddrParent; }
        static const Segment* GetParent(const Segment* n) { return n->AddrParent; }
        static void           SetParent(Segment* n, Segment* p) { n->AddrParent = p; }
        static void           SetChild(Segment* n, UPInt i, Segment* c) { n->AddrChild[i] = c; }
        static void           ClearLinks(Segment* n) { n->AddrParent = n->AddrChild[0] = n->AddrChild[1] = 0; }
    };

    typedef List<HdrPage>                       HdrListType;
    typedef List2<Segment, SegListAccessor>     SegListType;
    typedef RadixTree<Segment, SegTreeAccessor> SegTreeType;

    Granulator(SysAllocPaged* sysAlloc, UPInt minSize = 256, UPInt granularity = 64 * 1024,
               UPInt hdrPageSize = Heap_PageSize);

    SysAllocPaged* GetSysAlloc() { return pSysAlloc; }
    UPInt          GetGranularity() { return Granularity; }

    void* Alloc(UPInt size, UPInt alignSize);
    bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt alignSize);
    bool  Free(void* ptr, UPInt size, UPInt alignSize);

    UPInt GetFootprint() const { return Footprint; }
    UPInt GetUsedSpace() const { return Footprint - Allocator.GetFreeBytes(); }
    UPInt GetBase() const { return pSysAlloc->GetBase(); }
    UPInt GetSize() const { return pSysAlloc->GetSize(); }

    const TreeSeg* GetAllocSegment(const void* ptr) const;

    void  VisitMem(MemVisitor* visitor, MemVisitor::Category catSegm, MemVisitor::Category catFree) const;
    void  VisitSegments(SegVisitor* visitor, unsigned catSeg, unsigned catUnused) const;
    UPInt GetMinBase() const;

private:
    bool  allocSegment(UPInt size, UPInt alignSize);
    bool  freeSegment(Segment* seg);
    void* alloc(UPInt size, UPInt alignSize);

    // a segment whose header lives on its own first page
    bool hasHeaders(const Segment* seg) const { return (UByte*)seg->Headers + HdrPageSize == seg->Buffer; }
    UByte* getSegBase(Segment* seg)
    {
        UPInt hdrSize = hasHeaders(seg) ? HdrPageSize : 0;
        return seg->Buffer - hdrSize - seg->HeadBytes;
    }
    UPInt getSegSize(const Segment* seg) const
    {
        UPInt hdrSize   = hasHeaders(seg) ? HdrPageSize : 0;
        UPInt tailBytes = seg->HeadBytes ? Allocator.GetMinSize() - seg->HeadBytes : 0;
        return seg->Size + hdrSize + seg->HeadBytes + tailBytes;
    }
    void visitSegments(const Segment* node, SegVisitor* visitor, unsigned cat) const;

    SysAllocPaged* pSysAlloc;     // +0x00
    UPInt          Granularity;
    UPInt          HdrPageSize;
    UPInt          HdrCapacity;
    UPInt          MinAlign;
    UPInt          MaxAlign;
    bool           HasRealloc;    // +0x30
    HdrListType    HdrList;       // +0x38
    SegListType    FreeSeg;       // +0x48
    SegTreeType    UsedSeg;       // +0x88
    UPInt          Footprint;     // +0x90
    AllocLite      Allocator;     // +0x98
};

}}  // namespace Scaleform::HeapPT

#endif
