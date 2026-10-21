// Recovered Scaleform GFx 4.1.18: the PT global page table (HeapPT_PageTable, exe 0x1426cc8f0..). Maps every 4K page
// to the HeapSegment that owns it through a 5-level table (52/40/28/20/12 address bits on Win64); the lower levels are
// allocated from the Starter and reference counted.
#ifndef MS2_SF_KERNEL_HEAPPT_PAGETABLE_H
#define MS2_SF_KERNEL_HEAPPT_PAGETABLE_H

#include "ms2/scaleform/kernel/sf_heaptypes.h"
#include "ms2/scaleform/kernel/heappt/sf_heappt_starter.h"

namespace Scaleform { namespace HeapPT {

using namespace Heap;

#define SF_HEAPPT_LVMASK(shift) ((UPInt(1) << (shift)) - 1)

// one table level: N entries of T, created on first use
template<class T, UPInt N>
class HeapHeader
{
    T*    pTable;
    UPInt RefCount;

public:
    HeapHeader() : pTable(0), RefCount(0) { }

    T* GetTable() const { return pTable; }
    T* GetTable(UPInt i) const { return &pTable[i]; }

    SF_INLINE bool HasTable(UPInt address) const;

    bool AddRef(Starter* starter)
    {
        if (!pTable)
        {
            pTable = (T*)starter->Alloc(sizeof(T) * N, sizeof(void*) * N);
            if (!pTable)
                return false;
            memset(pTable, 0, sizeof(T) * N);
        }
        RefCount++;
        return true;
    }
    void Release(Starter* starter)
    {
        if (--RefCount == 0)
        {
            starter->Free((UByte*)pTable, sizeof(T) * N, sizeof(void*) * N);
            pTable = 0;
        }
    }
};

struct HeapHeader1
{
    HeapSegment* pSegment;
};
typedef HeapHeader<HeapHeader1, Heap_Lv1_TableSize> HeapHeader2;
typedef HeapHeader<HeapHeader2, Heap_Lv2_TableSize> HeapHeader3;
typedef HeapHeader<HeapHeader3, Heap_Lv3_TableSize> HeapHeader4;
typedef HeapHeader<HeapHeader4, Heap_Lv4_TableSize> HeapHeader5;
typedef HeapHeader5 HeapHeaderRoot;

// is the whole chain below this root entry present for the address
template<class T, UPInt N>
inline bool HeapHeader<T, N>::HasTable(UPInt address) const
{
    UPInt i4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
    UPInt i3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
    UPInt i2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
    HeapHeader4* table4 = this->GetTable();
    if (table4)
    {
        HeapHeader3* table3 = table4[i4].GetTable();
        if (table3)
        {
            HeapHeader2* table2 = table3[i3].GetTable();
            if (table2)
            {
                if (table2[i2].GetTable())
                    return true;
            }
        }
    }
    return false;
}

class PageTable
{
public:
    PageTable();
    static void Init();

    void     SetStarter(Starter* s) { pStarter = s; }
    Starter* GetStarter() { return pStarter; }

    SF_INLINE HeapSegment* GetSegment(UPInt address) const
    {
        UPInt i5 = address >> Heap_Lv5_PageShift;
        UPInt i4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        UPInt i3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
        UPInt i2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
        UPInt i1 = (address & SF_HEAPPT_LVMASK(Heap_Lv2_PageShift)) >> Heap_Lv1_PageShift;
        const HeapHeaderRoot* root = RootTable + i5;
        return root->GetTable(i4)->GetTable(i3)->GetTable(i2)->GetTable(i1)->pSegment;
    }
    // same walk, 0 where a level is missing
    SF_INLINE HeapSegment* GetSegmentSafe(UPInt address) const
    {
        UPInt i5 = address >> Heap_Lv5_PageShift;
        UPInt i4 = (address & SF_HEAPPT_LVMASK(Heap_Lv5_PageShift)) >> Heap_Lv4_PageShift;
        UPInt i3 = (address & SF_HEAPPT_LVMASK(Heap_Lv4_PageShift)) >> Heap_Lv3_PageShift;
        UPInt i2 = (address & SF_HEAPPT_LVMASK(Heap_Lv3_PageShift)) >> Heap_Lv2_PageShift;
        UPInt i1 = (address & SF_HEAPPT_LVMASK(Heap_Lv2_PageShift)) >> Heap_Lv1_PageShift;
        const HeapHeaderRoot* table5 = RootTable + i5;
        if (table5)
        {
            const HeapHeader4* table4 = table5->GetTable(i4);
            if (table4)
            {
                const HeapHeader3* table3 = table4->GetTable(i3);
                if (table3)
                {
                    const HeapHeader2* table2 = table3->GetTable(i2);
                    if (table2)
                    {
                        const HeapHeader1* table1 = table2->GetTable(i1);
                        if (table1)
                            return table1->pSegment;
                    }
                }
            }
        }
        return 0;
    }

    bool MapRange(void* address, UPInt size);
    void UnmapRange(void* address, UPInt size);
    bool RemapRange(void* address, UPInt newSize, UPInt oldSize);
    void SetSegmentInRange(UPInt address, UPInt size, HeapSegment* seg);

    void VisitMem(MemVisitor* visitor) { pStarter->VisitMem(visitor); }

private:
    Starter*       pStarter;
    HeapHeaderRoot RootTable[Heap_Root_TableSize];
};

extern PageTable* GlobalPageTable;

}}  // namespace Scaleform::HeapPT

#endif
