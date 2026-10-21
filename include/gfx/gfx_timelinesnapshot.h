// Recovered Scaleform 4.1.18 GFx: TimelineSnapshot, the state of a timeline's display list collected over a run of
// frames, so that a frame jump places each character once instead of replaying every tag on the way.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x68 bytes) from the exe's Sprite::GotoFrame, which builds one on the stack: node pool +0, sorted element
// array +0x28, element list +0x48, owner +0x58, direction +0x60. Bodies: GFx_SpriteDef (sfr_gfx_05), the destructor
// 0x1425d9b70 (sfr_gfx_05b).
#ifndef MS2_SF_GFX_TIMELINESNAPSHOT_H
#define MS2_SF_GFX_TIMELINESNAPSHOT_H

#include "../kernel/sf_array.h"
#include "../kernel/sf_memory.h"
#include "../../kernel/sf_list.h"
#include "../kernel/sf_alg.h"
#include "gfx_placeobject.h"

namespace Scaleform { namespace GFx {

class TimelineDef;
class DisplayObjContainer;
class InteractiveObject;
class GFxPlaceObjectBase;

// Fixed-size nodes carved out of pages of PageSize; released nodes are chained through their first pointer and reused.
template<class T, int PageSize>
class ListAllocDH
{
public:
    struct Page
    {
        UByte Data[sizeof(T) * PageSize];
        Page* pNext;
    };

    ListAllocDH(MemoryHeap* heap)
        : pFirstPage(0), pLastPage(0), LastPageUsed(PageSize), pFirstEmptySlot(0), pHeap(heap)
    {
    }
    ~ListAllocDH()
    {
        Page* page = pFirstPage;
        while (page)
        {
            Page* next = page->pNext;
            SF_FREE(page);
            page = next;
        }
    }

    void Free(T* p)
    {
        *(T**)p         = pFirstEmptySlot;
        pFirstEmptySlot = p;
    }

    // (appended for the timeline snapshot, sfr_gfx_05) a default-constructed node: a released one, the next one of
    // the last page, or the first one of a new page
    T* Alloc()
    {
        T* p;
        if (pFirstEmptySlot)
        {
            p               = pFirstEmptySlot;
            pFirstEmptySlot = *(T**)p;
        }
        else if (LastPageUsed < PageSize)
        {
            p = (T*)pLastPage->Data + LastPageUsed;
            ++LastPageUsed;
        }
        else
        {
            Page* page  = (Page*)AllocatorBaseDH<Stat_Default_Mem>::Alloc(pHeap, sizeof(Page), 0, 0);
            page->pNext = 0;
            if (pLastPage)
                pLastPage->pNext = page;
            else
                pFirstPage = page;
            pLastPage    = page;
            LastPageUsed = 1;
            p            = (T*)page->Data;
        }
        return Construct<T>(p);
    }

private:
    Page*       pFirstPage;      // +0x00
    Page*       pLastPage;       // +0x08
    unsigned    LastPageUsed;    // +0x10 nodes taken from the last page (full: the next Alloc adds a page)
    T*          pFirstEmptySlot; // +0x18
    MemoryHeap* pHeap;           // +0x20
};

class TimelineSnapshot
{
public:
    enum Direction
    {
        Direction_Forward  = 0,
        Direction_Backward = 1
    };
    // (appended for the timeline snapshot, sfr_gfx_05) what ExecuteSnapshot does with an element
    enum PlaceType
    {
        Place_Add          = GFxPlaceObjectBase::Place_Add,
        Place_Move         = GFxPlaceObjectBase::Place_Move,
        Place_Replace      = GFxPlaceObjectBase::Place_Replace,
        Place_Remove,
        Place_RemoveAndAdd,

        Place_Unknown = 255
    };
    enum FlagsType
    {
        Flags_NoReplaceAllowed = 0x1,
        Flags_DeadOnArrival    = 0x2   // removed in the same run: created, run its events, then removed again
    };

    // The place tags that last set each property of the character at one depth.
    struct SourceTags
    {
        GFxPlaceObjectBase* pMainTag;
        GFxPlaceObjectBase* pMatrixTag;
        GFxPlaceObjectBase* pCxFormTag;
        GFxPlaceObjectBase* pFiltersTag;
        GFxPlaceObjectBase* pBlendModeTag;
        GFxPlaceObjectBase* pDepthTag;
        GFxPlaceObjectBase* pClipDepthTag;
        GFxPlaceObjectBase* pRatioTag;
        GFxPlaceObjectBase* pCharIdTag;
        GFxPlaceObjectBase* pClassNameTag;

        // (appended for the timeline snapshot, sfr_gfx_05)
        SourceTags()
            : pMainTag(0), pMatrixTag(0), pCxFormTag(0), pFiltersTag(0), pBlendModeTag(0), pDepthTag(0),
              pClipDepthTag(0), pRatioTag(0), pCharIdTag(0), pClassNameTag(0)
        {
        }
        // Every property comes from ptag.
        void Assign(GFxPlaceObjectBase* ptag)
        {
            pMainTag = pMatrixTag = pCxFormTag = pFiltersTag = pBlendModeTag = pDepthTag = pClipDepthTag =
                pRatioTag = pCharIdTag = pClassNameTag = ptag;
        }
        // The properties ptag sets come from it.
        __forceinline void Union(GFxPlaceObjectBase* ptag)
        {
            CharPosInfoFlags flags = ptag->GetFlags();
            if (flags.HasMatrix())
                pMatrixTag = ptag;
            if (flags.HasCxform())
                pCxFormTag = ptag;
            if (flags.HasFilters())
                pFiltersTag = ptag;
            if (flags.HasBlendMode())
                pBlendModeTag = ptag;
            if (flags.HasDepth())
                pDepthTag = ptag;
            if (flags.HasClipDepth())
                pClipDepthTag = ptag;
            if (flags.HasRatio())
                pRatioTag = ptag;
            if (flags.HasCharacterId())
                pCharIdTag = ptag;
            if (flags.HasClassName())
                pClassNameTag = ptag;
        }
        bool HasMainTag() const { return pMainTag != 0; }

        // The main tag's placement with the properties of the other tags laid over it.
        void Unpack(GFxPlaceObjectBase::UnpackedData& data) const;
    };

    // One depth of the snapshot (0x70 bytes, pages of 50).
    struct SnapshotElement : public ListNode<SnapshotElement>
    {
        unsigned   CreateFrame;
        int        Depth;
        SourceTags Tags;
        UByte      PlaceType;
        UByte      Flags;

        ~SnapshotElement();   // 0x1425dcf10, empty

        // (appended for the timeline snapshot, sfr_gfx_05)
        SnapshotElement() : CreateFrame(~0u), PlaceType(Place_Unknown), Flags(0) {}
    };

    TimelineSnapshot(Direction dir, MemoryHeap* heap, InteractiveObject* powner)
        : SnapshotHeap(heap), SnapshotSortedArray(heap), pOwnerSprite(powner), Dir(dir)
    {
    }
    ~TimelineSnapshot();

    // Collects the place/remove tags of frames startFrame..endFrame (0x1425d80e0).
    void MakeSnapshot(TimelineDef* pdef, unsigned startFrame, unsigned endFrame);
    // Applies the collected state to the display list of pdispObj (0x1425d78a0).
    void ExecuteSnapshot(DisplayObjContainer* pdispObj);

    // (appended for the timeline snapshot, sfr_gfx_05)
    // A new element at depth, sorted after the ones already there (0x1425d5610).
    SnapshotElement* Add(int depth);
    // Drops the last element at depth (0x1425d8610).
    void Remove(int depth);

    static int DepthLess(int depth, const SnapshotElement* pe) { return depth < pe->Depth; }

    // The last element at depth, or null.
    SnapshotElement* FindDepth(int depth, UPInt* pindex = 0) const
    {
        UPInt i = Alg::UpperBound(SnapshotSortedArray, depth, DepthLess);
        if (i != 0)
        {
            --i;
            if (SnapshotSortedArray[i]->Depth == depth)
            {
                if (pindex)
                    *pindex = i;
                // Loaded again: the callers keep their null test.
                return SnapshotSortedArray[i];
            }
        }
        return 0;
    }
    void RemoveAtIndex(UPInt index)
    {
        SnapshotElement* pe = SnapshotSortedArray[index];
        SnapshotList.Remove(pe);
        SnapshotSortedArray.RemoveAt(index);
        SnapshotHeap.Free(pe);
    }

    ListAllocDH<SnapshotElement, 50> SnapshotHeap;        // +0x00
    ArrayDH_POD<SnapshotElement*>    SnapshotSortedArray; // +0x28 by depth
    List<SnapshotElement>            SnapshotList;        // +0x48
    InteractiveObject*               pOwnerSprite;        // +0x58
    Direction                        Dir;                 // +0x60
};

}} // namespace Scaleform::GFx

#endif
