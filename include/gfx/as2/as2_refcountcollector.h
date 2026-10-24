// Recovered Scaleform 4.1.18 GFx AS2: the cycle collector of the AS2 heap objects (RefCountBaseGC children).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Only the work-list and root-buffer operations the ForEachChild_GC visitors inline are recovered so far.
#ifndef MS2_SF_GFX_AS2_REFCOUNTCOLLECTOR_H
#define MS2_SF_GFX_AS2_REFCOUNTCOLLECTOR_H

#include "as2_actiontypes.h"

namespace Scaleform { namespace GFx { namespace AS2 {

template<int Stat>
class RefCountCollector : public RefCountBase<RefCountCollector<Stat>, Stat>
{
    friend class RefCountBaseGC<Stat>;

    typedef RefCountBaseGC<Stat> BaseType;

    // Root of the circular work list.
    class Root : public RefCountBaseGC<Stat>
    {
    public:
        Root() : RefCountBaseGC<Stat>(0) {}
        virtual void Finalize_GC() {}
    };

    // Buffer of the possible cycle roots: pages of 1024 pointers (ArrayPagedLH_POD<RefCountBaseGC*, 10, 5>). A free
    // slot holds (next free index << 1) | 1. 0x28 bytes.
    struct RootArray
    {
        UPInt       Reserved0; // +0x00
        UPInt       Size;      // +0x08
        UPInt       NumPages;  // +0x10
        UPInt       MaxPages;  // +0x18
        BaseType*** Pages;     // +0x20

        UPInt      GetSize() const       { return Size; }
        BaseType*& operator[](UPInt i)   { return Pages[i >> 10][i & 0x3ff]; }
        // Grows by whole pages or shrinks (exe 0x142592860 for Stat 0x143).
        void       Resize(UPInt newSize);
        // Frees the pages and the page table (exe 0x1429343f0 for Stat 0x143).
        void       ClearAndRelease();
    };

public:
    RootArray Roots;              // +0x10
    UPInt     FirstFreeRootIndex; // +0x38
    Root      ListRoot;           // +0x40
    BaseType* pLastPtr;           // +0x60 work list insertion point
    UByte     Flags;              // +0x68 bit 0: a collection is running

    // Counters of one collection. 8 bytes.
    struct Stats
    {
        unsigned RootsNumber;
        unsigned RootsFreedTotal;

        Stats() : RootsNumber(0), RootsFreedTotal(0) {}
    };

    unsigned GetRootsCount() const { return (unsigned)Roots.GetSize(); }
    bool     IsCollecting() const  { return (Flags & 1) != 0; }
    // Frees the unreachable cycles among the buffered roots (exe 0x142592200 for Stat 0x143).
    bool     Collect(Stats* pstats = 0);

    // Takes a buffered root out of the root buffer: the last slot is cut off, any other one goes to the free list.
    // Inline as in the exe, which also has an out-of-line copy (0x1425927d0 for Stat 0x143).
    void RemoveFromRoots(BaseType* root);

    // Links pchild in right after pLastPtr, which then points at it.
    void AddToList(BaseType* pchild)
    {
        if (!pchild->IsInList())
        {
            pchild->pPrev          = pLastPtr->pNext->pPrev;
            pchild->pNext          = pLastPtr->pNext;
            pLastPtr->pNext->pPrev = pchild;
            pLastPtr->pNext        = pchild;
            pLastPtr               = pchild;
            pchild->SetInList();
        }
    }
    // Moves a listed pchild right after pLastPtr (pLastPtr stays).
    void ReinsertToList(BaseType* pchild)
    {
        if (pchild->IsInList())
        {
            pchild->pPrev->pNext   = pchild->pNext;
            pchild->pNext->pPrev   = pchild->pPrev;
            pchild->pPrev          = pLastPtr->pNext->pPrev;
            pchild->pNext          = pLastPtr->pNext;
            pLastPtr->pNext->pPrev = pchild;
            pLastPtr->pNext        = pchild;
        }
    }
};

template<int Stat>
void RefCountCollector<Stat>::RemoveFromRoots(BaseType* root)
{
    if (root->IsBuffered() && !root->IsInList())
    {
        if (root->RootIndex + 1 != Roots.GetSize())
        {
            Roots[root->RootIndex] = (BaseType*)((FirstFreeRootIndex << 1) | 1);
            FirstFreeRootIndex     = root->RootIndex;
        }
        else
            Roots.Resize(root->RootIndex);
        root->ClearBuffered();
    }
}

// Collector of an AS2 movie: collects when the root buffer outgrows its limit or after a number of frames.
class ASRefCountCollector : public RefCountCollector<StatMV_ActionScript_Mem>
{
public:
    unsigned FrameCnt;               // +0x70 frames since the last collection
    unsigned MaxRootCount;           // +0x74 current root limit
    unsigned PeakRootCount;          // +0x78
    unsigned LastRootCount;          // +0x7c roots before the last collection
    unsigned RootsLeftLast;          // +0x80 roots left by the last collection
    unsigned PeakRootCountLast;      // +0x84 peak at the last collection
    unsigned FrameCountTotal;        // +0x88 number of AdvanceFrame calls that reached the frame limit
    unsigned CollectCount;           // +0x8c value of FrameCountTotal at the last collection
    unsigned PresetMaxRootCount;     // +0x90 configured root limit
    unsigned PresetFramesBetween;    // +0x94 configured frames between collections

    // Counts a frame of a movie and collects when the limits say so (exe 0x142931300). pframeCnt and pseenCount are
    // the movie's GCFrameCnt and GCSeenCollectCount.
    void AdvanceFrame(unsigned* pframeCnt, unsigned* pseenCount);
    // A full collection now (exe 0x142945c60).
    void ForceCollect();
    // A full collection that also frees an emptied root buffer and resets the limits (exe 0x142945d00).
    void ForceEmergencyCollect();
};

}}} // namespace Scaleform::GFx::AS2

#endif
