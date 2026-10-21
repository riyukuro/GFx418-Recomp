// Recovered Scaleform GFx 4.1.18: MH free lists. A free block keeps {Prev, Next, Page} at its start and repeats
// {Prev, Next} in its last 16 bytes; the 8-bit block count is split over the low 4 bits of Prev and Next (pointers are
// 16-byte aligned). One list per block count up to 64 (bit i of Mask: list i is non-empty).
#ifndef MS2_SF_KERNEL_HEAPMH_FREEBIN_H
#define MS2_SF_KERNEL_HEAPMH_FREEBIN_H

#include "ms2/scaleform/kernel/heapmh/sf_heapmh_root.h"

namespace Scaleform { namespace HeapMH {

struct BinNodeMH
{
    enum { MinBlocks = 2 };   // 2-block nodes have no room for Page
    UPInt   Prev;
    UPInt   Next;
    PageMH* Page;

    UPInt GetBlocks() const { return (Prev & 0xF) | ((Next & 0xF) << 4); }
    UPInt GetBytes() const { return GetBlocks() << PageMH::UnitShift; }
    UPInt GetPrevBlocks() const
    {
        const UPInt* tail = ((const UPInt*)this) - 2;
        return (tail[0] & 0xF) | ((tail[1] & 0xF) << 4);
    }
    UPInt GetPrevBytes() const { return GetPrevBlocks() << PageMH::UnitShift; }
    void SetBlocks(UPInt blocks)
    {
        UPInt  bytes = blocks << PageMH::UnitShift;
        UPInt* tail = ((UPInt*)this) + bytes / sizeof(UPInt) - 2;
        tail[0] = Prev = (Prev & ~UPInt(0xF)) | (blocks & 0xF);
        tail[1] = Next = (Next & ~UPInt(0xF)) | (blocks >> 4);
    }
    void SetBytes(UPInt bytes)
    {
        UPInt  blocks = bytes >> PageMH::UnitShift;
        UPInt* tail = ((UPInt*)this) + bytes / sizeof(UPInt) - 2;
        tail[0] = Prev = (Prev & ~UPInt(0xF)) | (blocks & 0xF);
        tail[1] = Next = (Next & ~UPInt(0xF)) | (blocks >> 4);
    }
    PageMH* GetPage() { return (GetBlocks() > MinBlocks) ? Page : 0; }
    void SetPage(PageMH* page)
    {
        if (GetBlocks() > MinBlocks)
            Page = page;
    }
    BinNodeMH* GetPrev() const { return (BinNodeMH*)(Prev & ~UPInt(0xF)); }
    BinNodeMH* GetNext() const { return (BinNodeMH*)(Next & ~UPInt(0xF)); }
    void SetPrev(BinNodeMH* prev) { Prev = UPInt(prev) | (Prev & 0xF); }
    void SetNext(BinNodeMH* next) { Next = UPInt(next) | (Next & 0xF); }

    static BinNodeMH* MakeNode(UByte* start, UPInt bytes, PageMH* page)
    {
        BinNodeMH* node = (BinNodeMH*)start;
        node->SetBytes(bytes);
        node->SetPage(page);
        return node;
    }
};

struct ListBinMH
{
    enum { BinSize = 8 * sizeof(UPInt) };

    ListBinMH();
    void Reset();

    void       Push(UByte* node);
    void       Pull(UByte* node);
    BinNodeMH* PullBest(UPInt blocks);
    BinNodeMH* PullBest(UPInt blocks, UPInt alignMask);
    void       Merge(UByte* node, UPInt bytes, bool left, bool right, PageMH* page);

    static UByte* GetAlignedPtr(UByte* start, UPInt alignMask);
    static bool   AlignmentIsOK(const BinNodeMH* node, UPInt blocks, UPInt alignMask);

private:
    void       pushNode(UPInt idx, BinNodeMH* node);
    void       pullNode(UPInt idx, BinNodeMH* node);
    BinNodeMH* findAligned(BinNodeMH* root, UPInt blocks, UPInt alignMask);
    BinNodeMH* getPrevAdjacent(UByte* node) const;
    BinNodeMH* getNextAdjacent(UByte* node) const;

    UPInt      Mask;
    BinNodeMH* Roots[BinSize];
};

}}  // namespace Scaleform::HeapMH

#endif
