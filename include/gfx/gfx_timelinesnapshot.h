// Recovered Scaleform 4.1.18 GFx: TimelineSnapshot, the state of a timeline's display list collected over a run of
// frames, so that a frame jump places each character once instead of replaying every tag on the way.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x68 bytes) from the exe's Sprite::GotoFrame, which builds one on the stack: node pool +0, sorted element
// array +0x28, element list +0x48, owner +0x58, direction +0x60. Bodies: MakeSnapshot 0x1425d80e0 and ExecuteSnapshot
// 0x1425d78a0 (sfr_gfx_04), the destructor 0x1425d9b70 (sfr_gfx_05b).
#ifndef MS2_SF_GFX_TIMELINESNAPSHOT_H
#define MS2_SF_GFX_TIMELINESNAPSHOT_H

#include "../kernel/sf_array.h"
#include "../kernel/sf_memory.h"
#include "../../kernel/sf_list.h"

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

    ListAllocDH<SnapshotElement, 50> SnapshotHeap;        // +0x00
    ArrayDH_POD<SnapshotElement*>    SnapshotSortedArray; // +0x28 by depth
    List<SnapshotElement>            SnapshotList;        // +0x48
    InteractiveObject*               pOwnerSprite;        // +0x58
    Direction                        Dir;                 // +0x60
};

}} // namespace Scaleform::GFx

#endif
