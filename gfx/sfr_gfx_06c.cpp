// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 GFx_DisplayList: the depth-sorted
// children of a container. Every entry holds a reference to its object and the object's index in the owner's render
// container; objects masked by a clip (ClipDepth != 0) sit in the mask's own container, MaskTreeIndex counting inside
// it. Objects with an onUnload handler are moved to the negative depth -1 - depth until the handler ran. AS3 lists can
// hold entries out of depth order (MayContainForeignElems), so their depth lookups go through a rebuilt depth map.
// MS2-UNIT: sfr_gfx_06c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425f8b20-0x1425fbbf0 .text$mn
// MS2-PIN: ?Resize@?$ArrayData@UDepthToIndexMapElem@DisplayList@GFx@Scaleform@@U?$AllocatorLH@UDepthToIndexMapElem@DisplayList@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x1425fb150
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_alg.h"

namespace Scaleform {
namespace Alg {

typedef GFx::DisplayList::DepthToIndexContainer DepthMap;
typedef GFx::DisplayList::DepthToIndexMapElem   DepthMapElem;
typedef GFx::DisplayList::DisplayEntry          DisplayEntry;
typedef ArrayLH<DisplayEntry, Stat_Default_Mem> DisplayEntryArray;

// The binary searches of FindDisplayIndex, emitted out of line in this unit.
template UPInt LowerBound<DepthMap, int, int (*)(const DepthMapElem&, int)>(
    const DepthMap&, const int&, int (*)(const DepthMapElem&, int));
template UPInt LowerBound<DisplayEntryArray, int, int (*)(const DisplayEntry&, int)>(
    const DisplayEntryArray&, const int&, int (*)(const DisplayEntry&, int));
template UPInt LowerBoundSliced<DepthMap, int, int (*)(const DepthMapElem&, int)>(
    const DepthMap&, UPInt, UPInt, const int&, int (*)(const DepthMapElem&, int));
template UPInt LowerBoundSliced<DisplayEntryArray, int, int (*)(const DisplayEntry&, int)>(
    const DisplayEntryArray&, UPInt, UPInt, const int&, int (*)(const DisplayEntry&, int));

} // namespace Alg

namespace GFx {

using Render::TreeNode;
using Render::TreeContainer;

// @0x1425f8d80
DisplayList::DisplayList()
    : DepthToIndexMap(0), pCachedChar(0), Flags(0)
{
}

// @0x1425f8da0
void DisplayList::DisplayEntry::operator=(const DisplayEntry& e)
{
    SetDisplayObject(e.GetDisplayObject());
    TreeIndex     = e.TreeIndex;
    MaskTreeIndex = e.MaskTreeIndex;
}

// ---------------------------------------------------------------------------------------------------------------------
// Lookups

// @0x1425f9200
SPInt DisplayList::FindDisplayIndex(const DisplayObjectBase* pch) const
{
    for (UPInt i = 0; i < DisplayObjectArray.GetSize(); i++)
    {
        if (DisplayObjectArray[i].GetDisplayObject() == pch)
            return (SPInt)i;
    }
    return -1;
}

// @0x1425f9230
UPInt DisplayList::FindDisplayIndex(int depth) const
{
    if ((Flags & Flags_DepthToIndexInvalid) != 0)
    {
        // Rebuild the depth map (only worth it for longer lists), answering the query on the way.
        SPInt found = -1;
        if (DisplayObjectArray.GetSize() > THRESHOLD_CNT)
        {
            UPInt mapped = 0;
            if (!DepthToIndexMap)
                DepthToIndexMap = SF_HEAP_AUTO_NEW(this) DepthToIndexContainer();
            for (UPInt i = 0, n = DisplayObjectArray.GetSize(); i < n; ++i)
            {
                const DisplayEntry& e = DisplayObjectArray[i];
                if (found == -1 && e.GetDepth() >= depth)
                    found = (SPInt)i;
                if (e.GetDepth() != INVALID_DEPTH)
                {
                    DepthToIndexMap->SetElement(mapped, e.GetDepth(), unsigned(i));
                    ++mapped;
                }
            }
            DepthToIndexMap->SetSize(mapped);
        }
        else
        {
            if (DepthToIndexMap)
                DepthToIndexMap->SetSize(0);
        }
        Flags &= ~Flags_DepthToIndexInvalid;
        if (found != -1)
            return (UPInt)found;
    }

    UPInt index;
    if (!(Flags & Flags_MayContainForeignElems))
    {
        index = Alg::LowerBound(DisplayObjectArray, depth, DepthLess);
    }
    else if (DepthToIndexMap && DisplayObjectArray.GetSize() > THRESHOLD_CNT)
    {
        UPInt i = Alg::LowerBound(*DepthToIndexMap, depth, DepthLess1);
        if (i == DepthToIndexMap->GetSize())
            return DisplayObjectArray.GetSize();
        index = (*DepthToIndexMap)[i].Index;
    }
    else
    {
        // Short list: linear search.
        UPInt n = index = DisplayObjectArray.GetSize();
        for (UPInt i = 0; i < n; ++i)
        {
            if (DisplayObjectArray[i].GetDepth() >= depth)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

// @0x1425f97c0
UPInt DisplayList::GetDisplayIndex(int depth)
{
    UPInt index = FindDisplayIndex(depth);
    if (index >= DisplayObjectArray.GetSize() || GetDisplayEntry(index).GetDepth() != depth)
        return SF_MAX_UPINT;
    return index;
}

// @0x1425f9800
DisplayObjectBase* DisplayList::GetDisplayObjectAtDepth(int depth, bool* pisMarkedForRemove)
{
    UPInt index = GetDisplayIndex(depth);
    if (index != SF_MAX_UPINT)
    {
        DisplayObjectBase* ch = DisplayObjectArray[index].GetDisplayObject();
        if (ch->Depth == depth)
        {
            if (pisMarkedForRemove)
                *pisMarkedForRemove = DisplayObjectArray[index].IsMarkedForRemove();
            return ch;
        }
    }
    return 0;
}

// @0x1425f9880
DisplayObjectBase* DisplayList::GetDisplayObjectAtDepthAndUnmark(DisplayObjectBase* powner, int depth)
{
    UPInt index = GetDisplayIndex(depth);
    if (index != SF_MAX_UPINT)
    {
        DisplayObjectBase* ch = DisplayObjectArray[index].GetDisplayObject();
        if (ch->Depth == depth)
        {
            if (DisplayObjectArray[index].IsMarkedForRemove())
            {
                // back into the render tree
                InsertIntoRenderTree(powner, index);
                DisplayObjectArray[index].ClearMarkForRemove();
            }
            return ch;
        }
    }
    return 0;
}

// @0x1425f9920
DisplayObject* DisplayList::GetDisplayObjectByName(const ASString& name, bool caseSensitive) const
{
    if (name.GetSize() == 0)
        return 0;
    DisplayObjectBase* pch = 0;

    if (caseSensitive)
    {
        if (pCachedChar && pCachedChar->GetName() == name)
            return pCachedChar;

        for (UPInt i = 0, n = GetCount(); i < n; i++)
        {
            DisplayObjectBase* p = GetDisplayObject(i);
            if (p && p->IsScriptableObject() && static_cast<DisplayObject*>(p)->GetName() == name)
            {
                pch = p;
                break;
            }
        }
    }
    else
    {
        name.ResolveLowercase();
        if (pCachedChar && ASStringCompareNoCaseResolved(name, pCachedChar->GetName()))
            return pCachedChar;

        for (UPInt i = 0, n = GetCount(); i < n; i++)
        {
            DisplayObjectBase* p = GetDisplayObject(i);
            if (p && p->IsScriptableObject() &&
                ASStringCompareNoCaseResolved(name, static_cast<DisplayObject*>(p)->GetName()))
            {
                pch = p;
                break;
            }
        }
    }
    // only scriptable objects have names
    if (pch)
        pCachedChar = static_cast<DisplayObject*>(pch);
    else
        pCachedChar = 0;
    return pCachedChar;
}

// @0x1425f9b70
int DisplayList::GetLargestDepthInUse() const
{
    // sorted by depth: the last entry is the deepest
    UPInt size = DisplayObjectArray.GetSize();
    return size ? DisplayObjectArray[size - 1].GetDepth() : -1;
}

// ---------------------------------------------------------------------------------------------------------------------
// Adding, moving and replacing

// @0x1425f8df0
void DisplayList::AddDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos, DisplayObjectBase* ch,
                                   UInt32 addFlags)
{
    int   depth = pos.Depth;
    UPInt size  = DisplayObjectArray.GetSize();
    UPInt index = FindDisplayIndex(depth);
    pCachedChar = 0;

    if (addFlags & Flags_ReplaceIfDepthIsOccupied)
    {
        // Unload what is in the way; it may move or vanish, so look the index up again.
        if (index < size && DisplayObjectArray[index].GetDepth() == depth)
        {
            UnloadDisplayObjectAtIndex(powner, index);
            index = FindDisplayIndex(depth);
        }
    }

    ch->Depth = depth;
    ch->SetCxform(pos.ColorTransform);
    ch->SetMatrix(pos.Matrix_1);
    ch->SetRatio(pos.Ratio);
    ch->ClipDepth = pos.ClipDepth;
    ch->SetBlendMode((Render::BlendMode)pos.BlendMode);
    ch->SetFilters(pos.pFilters.GetPtr());

    AddDisplayObject(powner, index, ch);
}

// @0x1425f8f70
void DisplayList::AddDisplayObject(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch)
{
    AddEntryAtIndex(powner, index, ch);
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    // frame 1 actions and the load event
    ch->OnEventLoad();
}

// @0x1425f9040
void DisplayList::AddEntryAtIndex(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch)
{
    DisplayEntry e;
    e.SetDisplayObject(ch);
    DisplayObjectArray.InsertAt(index, e);
    InsertIntoRenderTree(powner, index);
    CheckAndInvalidateDepthMappings();
}

// @0x1425fa410
void DisplayList::MoveDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos)
{
    int   depth = pos.Depth;
    UPInt size  = DisplayObjectArray.GetSize();
    UPInt index = FindDisplayIndex(depth);
    if (index >= size)
        return;

    DisplayEntry&      e  = DisplayObjectArray[index];
    DisplayObjectBase* ch = e.GetDisplayObject();
    if (ch->Depth != depth)
        return;

    // placed again: no longer up for removal
    e.ClearMarkForRemove();
    if (!e.IsInRenderTree())
        InsertIntoRenderTree(powner, index);

    if (!ch->GetAcceptAnimMoves())
    {
        // ActionScript took over this object; the timeline only moves it again when asked to continue.
        if (ch->GetContinueAnimationFlag())
            ch->SetAcceptAnimMoves(true);
        else
            return;
    }

    if (pos.HasCxform())
        ch->SetCxform(pos.ColorTransform);
    if (pos.HasMatrix())
        ch->SetMatrix(pos.Matrix_1);
    if (pos.Flags.HasBlendMode())
        ch->SetBlendMode((Render::BlendMode)pos.BlendMode);
    ch->SetFilters(pos.pFilters.GetPtr());
    ch->SetRatio(pos.Ratio);
    // the clip depth stays
}

// Puts ch in place of the object at pos.Depth; what pos does not specify is taken over from the old object.
// @0x1425fab10
void DisplayList::ReplaceDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos, DisplayObjectBase* ch)
{
    UPInt size  = DisplayObjectArray.GetSize();
    int   depth = pos.Depth;
    UPInt index = FindDisplayIndex(depth);

    if (index >= size)
    {
        AddDisplayObject(powner, pos, ch, Flags_ReplaceIfDepthIsOccupied);
        return;
    }
    DisplayEntry& e = DisplayObjectArray[index];
    if (e.GetDepth() != depth)
    {
        // seeking back: the old object is gone already
        AddDisplayObject(powner, pos, ch, Flags_ReplaceIfDepthIsOccupied);
        return;
    }

    Ptr<DisplayObjectBase> pold = e.GetDisplayObject();

    ch->Depth = depth;
    ch->Restart();

    e.ClearMarkForRemove();
    if (!e.IsInRenderTree())
        InsertIntoRenderTree(powner, index);
    e.SetDisplayObject(ch);

    ch->SetCxform(pos.HasCxform() ? pos.ColorTransform : pold->GetCxform());
    ch->SetMatrix(pos.HasMatrix() ? pos.Matrix_1 : pold->GetMatrix());
    ch->SetBlendMode(pos.Flags.HasBlendMode() ? (Render::BlendMode)pos.BlendMode : pold->GetBlendMode());
    ch->SetRatio(pos.Ratio);
    ch->ClipDepth = pos.ClipDepth;
    ch->SetFilters(pos.pFilters.GetPtr());

    ReplaceRenderTreeNode(powner, index);
    CheckAndInvalidateDepthMappings();

    pCachedChar = 0;
    pold->OnEventUnload();
    ch->OnEventLoad();
}

// @0x1425facd0
void DisplayList::ReplaceDisplayObjectAtIndex(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch)
{
    if (index >= DisplayObjectArray.GetSize())
        return;

    pCachedChar = 0;
    DisplayEntry& e = GetDisplayEntry(index);
    e.SetDisplayObject(ch);
    if (e.IsInRenderTree())
        ReplaceRenderTreeNode(powner, index);
    else
        InsertIntoRenderTree(powner, index);
    CheckAndInvalidateDepthMappings();
}

// ---------------------------------------------------------------------------------------------------------------------
// Removing

// @0x1425fa6f0
void DisplayList::RemoveDisplayObject(DisplayObjectBase* powner, int depth, ResourceId id)
{
    UPInt size  = DisplayObjectArray.GetSize();
    UPInt index = FindDisplayIndex(depth);
    if (index >= size)
        return;

    Ptr<DisplayObjectBase> ch = GetDisplayObject(index);
    if (ch->Depth != depth)
        return;

    pCachedChar = 0;
    if (id != ResourceId::InvalidId)
    {
        // several objects may share the depth: find the one with the id
        for (;;)
        {
            if (GetDisplayObject(index)->Id == id.GetIdValue())
                break;
            if (index + 1 >= size || GetDisplayObject(index + 1)->Depth != depth)
                return;
            index++;
        }
    }
    UnloadDisplayObjectAtIndex(powner, index);
}

// @0x1425fa7c0
bool DisplayList::RemoveDisplayObject(DisplayObjectBase* powner, const DisplayObjectBase* ch)
{
    SPInt index = FindDisplayIndex(ch);
    if (index >= 0)
    {
        UnloadDisplayObjectAtIndex(powner, UPInt(index));
        pCachedChar = 0;
    }
    return false;
}

// @0x1425fa820
void DisplayList::RemoveEntryAtIndex(DisplayObjectBase* powner, UPInt index)
{
    RemoveFromRenderTree(powner, index);
    DisplayObjectArray.RemoveAt(index);
    pCachedChar = 0;
    CheckAndInvalidateDepthMappings();
}

// @0x1425f9100
void DisplayList::Clear(DisplayObjectBase* powner)
{
    // the render thread may still hold nodes from the owner's heap
    powner->GetMovieImpl()->AddMovieDefToKillList(powner->GetResourceMovieDef());
    while (DisplayObjectArray.GetSize() != 0)
    {
        pCachedChar = 0;
        DisplayEntry& e = DisplayObjectArray[0];
        // the unload can change the list, so remove one by one
        e.GetDisplayObject()->OnEventUnload();
        RemoveFromRenderTree(powner, 0);
        // children may outlive the parent for a while
        e.GetDisplayObject()->pParent = 0;
        DisplayObjectArray.RemoveAt(0);
    }
    pCachedChar = 0;
    DisplayObjectArray.Clear();
}

// @0x1425fb940
bool DisplayList::UnloadDisplayObjectAtIndex(DisplayObjectBase* powner, UPInt index)
{
    const DisplayEntry& e = DisplayObjectArray[index];
    RemoveFromRenderTree(powner, index);

    // already marked: UnloadMarkedObjects deals with it
    if (e.IsMarkedForRemove())
        return false;

    DisplayObjectBase* pch = e.GetDisplayObject();
    if (pch)
    {
        // unloading already (called again for the same object)
        if (pch->IsUnloading())
            return false;

        // OnUnloading queues the onUnload event; false when there is one to wait for
        bool mayRemove = pch->OnUnloading();
        pch->SetUnloading(true);
        if (mayRemove)
        {
            pch->OnEventUnload();
            // (the parent stays set in this build)
            DisplayObjectArray.RemoveAt(index);
        }
        else if (e.GetDepth() >= 0)
        {
            // Park it at depth -1 - depth until its onUnload ran (a negative depth is being removed already).
            int          newDepth = -1 - e.GetDepth();
            DisplayEntry moved(e);
            DisplayObjectArray.RemoveAt(index);
            moved.GetDisplayObject()->Depth = newDepth;
            UPInt index2 = FindDisplayIndex(newDepth);
            DisplayObjectArray.InsertAt(index2, moved);
        }
        pCachedChar = 0;
        CheckAndInvalidateDepthMappings();
        return mayRemove;
    }
    DisplayObjectArray.RemoveAt(index);
    pCachedChar = 0;
    CheckAndInvalidateDepthMappings();
    return true;
}

// @0x1425fb780
bool DisplayList::UnloadAll(DisplayObjectBase* powner)
{
    pCachedChar = 0;
    bool mayRemove = true;
    // the size changes as entries go
    for (UPInt i = 0; i < DisplayObjectArray.GetSize();)
    {
        // a removed entry leaves i at the next one; one waiting for its onUnload moved to the front
        if (!UnloadDisplayObjectAtIndex(powner, i))
        {
            ++i;
            mayRemove = false;
        }
    }
    return mayRemove;
}

// Marks the timeline objects for removal before a frame jump re-places them; objects created by ActionScript (depth
// outside 0..16383) and those created on targetFrame or before stay.
// @0x1425fa360
void DisplayList::MarkAllEntriesForRemoval(DisplayObjectBase* powner, unsigned targetFrame)
{
    for (UPInt i = 0, n = DisplayObjectArray.GetSize(); i < n; i++)
    {
        DisplayEntry&          e  = DisplayObjectArray[i];
        Ptr<DisplayObjectBase> ch = e.GetDisplayObject();

        int depth = ch->Depth;
        if (!ch || (depth >= 0 && depth < 16384 && ch->CreateFrame > targetFrame))
        {
            e.MarkForRemove(true);
            RemoveFromRenderTree(powner, i);
        }
    }
}

// @0x1425fba90
void DisplayList::UnloadMarkedObjects(DisplayObjectBase* powner)
{
    pCachedChar = 0;
    // first to last; the size changes as entries go
    for (UPInt i = 0; i < DisplayObjectArray.GetSize(); i++)
    {
        if (DisplayObjectArray[i].IsMarkedForRemove())
        {
            DisplayObjectArray[i].ClearMarkForRemove();
            // removed: the next entry is at i now
            if (UnloadDisplayObjectAtIndex(powner, i))
                i--;
        }
    }
    pCachedChar = 0;
}

// ---------------------------------------------------------------------------------------------------------------------
// Depth swaps

// @0x1425fb1e0
bool DisplayList::SwapDepths(DisplayObjectBase* powner, int depth1, int depth2, unsigned frame)
{
    if (depth1 == depth2)
        return true;

    UPInt index1 = GetDisplayIndex(depth1);
    if (index1 == SF_MAX_UPINT)
        return false;
    UPInt index2 = FindDisplayIndex(depth2);

    // objects with an indirect transform are not swapped
    if ((index1 < DisplayObjectArray.GetSize() && GetDisplayObject(index1)->HasIndirectTransform()) ||
        (index2 < DisplayObjectArray.GetSize() && GetDisplayObject(index2)->HasIndirectTransform()))
        return false;

    pCachedChar = 0;
    if (index2 >= DisplayObjectArray.GetSize() || GetDisplayEntry(index2).GetDepth() != depth2)
    {
        // depth2 is free: move the entry there
        DisplayEntry e(DisplayObjectArray[index1]);
        RemoveFromRenderTree(powner, index1);
        DisplayObjectArray.RemoveAt(index1);
        if (index1 < index2)
            index2--;
        DisplayObjectArray.InsertAt(index2, e);
        InsertIntoRenderTree(powner, index2);
    }
    else
    {
        Alg::Swap(DisplayObjectArray[index1], DisplayObjectArray[index2]);
        SwapRenderTreeNodes(powner, index1, index2);
        DisplayObjectBase* ch1 = DisplayObjectArray[index1].GetDisplayObject();
        if (ch1)
        {
            ch1->Depth = depth1;
            // moved by script: the timeline removes it on its next loop
            ch1->CreateFrame = frame + 1;
        }
    }

    DisplayObjectBase* ch2 = DisplayObjectArray[index2].GetDisplayObject();
    if (ch2)
    {
        ch2->Depth       = depth2;
        ch2->CreateFrame = frame + 1;
    }
    CheckAndInvalidateDepthMappings();
    return true;
}

// @0x1425fb480
bool DisplayList::SwapEntriesAtIndexes(DisplayObjectBase* powner, UPInt index1, UPInt index2)
{
    if (index1 == index2)
        return true;
    DisplayEntry e = DisplayObjectArray[index1];

    if (e.GetDisplayObject()->HasIndirectTransform() ||
        (index2 < DisplayObjectArray.GetSize() && GetDisplayObject(index2)->HasIndirectTransform()))
        return false;

    DisplayObjectArray[index1] = DisplayObjectArray[index2];
    DisplayObjectArray[index2] = e;
    return SwapRenderTreeNodes(powner, index1, index2);
}

// ---------------------------------------------------------------------------------------------------------------------
// Render tree

// Puts the node of a replaced entry in place of the old one; the entry still has the old tree indices.
// @0x1425fad70
void DisplayList::ReplaceRenderTreeNode(DisplayObjectBase* powner, UPInt index)
{
    DisplayEntry& e = DisplayObjectArray[index];

    if (e.GetDisplayObject()->HasIndirectTransform())
    {
        powner->GetMovieImpl()->UpdateTransformParent(e.GetDisplayObject(), powner);
        return;
    }

    TreeContainer* pcontainer = powner->GetRenderContainer();
    // keep the heap of a foreign movie alive while the render thread may use its nodes
    if (e.GetDisplayObject()->GetResourceMovieDef() != powner->GetResourceMovieDef())
        e.GetDisplayObject()->GetMovieImpl()->AddMovieDefToKillList(e.GetDisplayObject()->GetResourceMovieDef());

    TreeNode* node = pcontainer->GetAt(e.TreeIndex);
    if (e.MaskTreeIndex == ~0u)
    {
        if (node->HasMask())
        {
            // a mask: swap the mask node only
            node->SetMaskNode(e.GetDisplayObject()->GetRenderNode());
        }
        else
        {
            pcontainer->Remove(e.TreeIndex, 1);
            pcontainer->Insert(e.TreeIndex, e.GetDisplayObject()->GetRenderNode());
        }
    }
    else
    {
        // masked: replace inside the mask's container
        TreeContainer* pmaskNode = static_cast<TreeContainer*>(node);
        pmaskNode->Remove(e.MaskTreeIndex, 1);
        pmaskNode->Insert(e.MaskTreeIndex, e.GetDisplayObject()->GetRenderNode());
    }
}

// @0x1425fa860
void DisplayList::RemoveFromRenderTree(DisplayObjectBase* powner, UPInt index)
{
    DisplayEntry& e = DisplayObjectArray[index];
    if (e.TreeIndex == ~0u)
    {
        // an indirect transform node lives elsewhere: detach its transform parent
        if (e.GetDisplayObject()->HasIndirectTransform())
            powner->GetMovieImpl()->UpdateTransformParent(e.GetDisplayObject(), 0);
        return;
    }

    if (e.GetDisplayObject()->GetResourceMovieDef() != powner->GetResourceMovieDef())
        e.GetDisplayObject()->GetMovieImpl()->AddMovieDefToKillList(e.GetDisplayObject()->GetResourceMovieDef());

    TreeContainer* pcontainer = powner->GetRenderContainer();
    if (e.MaskTreeIndex == ~0u)
    {
        TreeNode* node = pcontainer->GetAt(e.TreeIndex);
        int treeIndexDelta = -1;
        if (node->HasMask())
        {
            // Removing a mask: its masked nodes go back into the container in its place.
            TreeContainer* pmaskNode = static_cast<TreeContainer*>(node);
            for (UPInt i = index + 1;
                 i < DisplayObjectArray.GetSize() &&
                 ((DisplayObjectArray[i].TreeIndex == e.TreeIndex && DisplayObjectArray[i].MaskTreeIndex != ~0u) ||
                  !DisplayObjectArray[i].IsInRenderTree());
                 ++i)
            {
                DisplayEntry& ce = DisplayObjectArray[i];
                ++index;
                if (!ce.IsInRenderTree())
                    continue;
                Ptr<TreeNode> pmasked = pmaskNode->GetAt(0);
                pmaskNode->Remove(0, 1);
                ce.TreeIndex     = e.TreeIndex + ce.MaskTreeIndex;
                ce.MaskTreeIndex = ~0u;
                pcontainer->Insert(ce.TreeIndex, pmasked);
                ++treeIndexDelta;
            }
        }
        pcontainer->Remove(e.TreeIndex + treeIndexDelta + 1, 1);

        // shift the tree indices of the entries after it
        for (UPInt i = index + 1; i < DisplayObjectArray.GetSize(); ++i)
        {
            DisplayEntry& ce = DisplayObjectArray[i];
            if (ce.TreeIndex != ~0u)
                ce.TreeIndex += treeIndexDelta;
        }
    }
    else
    {
        // masked: remove from the mask's container
        TreeContainer* pmaskNode = static_cast<TreeContainer*>(pcontainer->GetAt(e.TreeIndex));
        pmaskNode->Remove(e.MaskTreeIndex, 1);
        for (UPInt i = index + 1; i < DisplayObjectArray.GetSize(); ++i)
        {
            if (DisplayObjectArray[i].TreeIndex == ~0u)
                continue;
            if (DisplayObjectArray[i].TreeIndex != e.TreeIndex)
                break;
            --DisplayObjectArray[i].MaskTreeIndex;
        }
    }
    e.TreeIndex = e.MaskTreeIndex = ~0u;
}

// @0x1425f9e70
void DisplayList::InsertIntoRenderTree(DisplayObjectBase* powner, UPInt index)
{
    DisplayEntry& e = DisplayObjectArray[index];
    if (e.GetDisplayObject()->HasIndirectTransform())
    {
        powner->GetMovieImpl()->UpdateTransformParent(e.GetDisplayObject(), powner);
        return;
    }

    TreeContainer*     pcontainer = powner->GetRenderContainer();
    DisplayObjectBase* ch         = e.GetDisplayObject();
    Ptr<TreeNode>      prenNode   = ch->GetRenderNode();

    bool masked = false;
    if (index == 0)
        e.TreeIndex = 0;
    else
    {
        // the closest earlier entry that is in the tree
        SPInt prevIdx = (SPInt)Alg::Min<UPInt>(index - 1, DisplayObjectArray.GetSize() - 1);
        while (prevIdx >= 0 && !DisplayObjectArray[prevIdx].IsInRenderTree())
            --prevIdx;
        if (prevIdx < 0)
            e.TreeIndex = 0;
        else
        {
            const DisplayEntry& prev = DisplayObjectArray[prevIdx];
            if (prev.GetClipDepth() != 0 || prev.MaskTreeIndex != ~0u)
            {
                // After a mask or a masked entry: find the mask, counting the masked entries before us.
                UPInt maskIdx       = prevIdx;
                UPInt alreadyMasked = 0;
                while (maskIdx > 0 &&
                       (DisplayObjectArray[maskIdx].IsMaskedTreeNode() || !DisplayObjectArray[maskIdx].IsInRenderTree()))
                {
                    if (DisplayObjectArray[maskIdx].IsInRenderTree())
                        ++alreadyMasked;
                    --maskIdx;
                }
                const DisplayEntry& maskEntry = DisplayObjectArray[maskIdx];

                if (ch->Depth <= maskEntry.GetClipDepth() && ch->Depth > maskEntry.GetDepth())
                {
                    masked          = true;
                    e.TreeIndex     = maskEntry.TreeIndex;
                    e.MaskTreeIndex = (unsigned)alreadyMasked;

                    TreeContainer* pmaskNode = static_cast<TreeContainer*>(pcontainer->GetAt(maskEntry.TreeIndex));
                    if (ch->ClipDepth == 0)
                        pmaskNode->Insert(e.MaskTreeIndex, prenNode);
                    else
                    {
                        // a mask inside a mask (after swapDepths): give it an empty container of its own
                        Ptr<TreeContainer> pnode = *powner->GetRenderContext().CreateEntry<TreeContainer>();
                        pnode->SetMaskNode(prenNode);
                        pmaskNode->Insert(e.MaskTreeIndex, pnode);
                    }

                    // the masked entries after it move one up inside the mask
                    for (UPInt i = index + 1;
                         i < DisplayObjectArray.GetSize() &&
                         DisplayObjectArray[i].GetDepth() <= maskEntry.GetClipDepth() &&
                         DisplayObjectArray[i].GetDepth() > maskEntry.GetDepth();
                         ++i)
                    {
                        if (DisplayObjectArray[i].IsInRenderTree())
                            ++DisplayObjectArray[i].MaskTreeIndex;
                    }
                }
            }
            if (!masked)
                e.TreeIndex = prev.TreeIndex + 1;
        }
    }

    int treeIndexDelta = 1;
    if (!masked)
    {
        UPInt updateFrom = index + 1;
        if (ch->ClipDepth != 0)
        {
            // A mask: a new container holds it and the entries it masks.
            Ptr<TreeContainer> pmaskNode = *powner->GetRenderContext().CreateEntry<TreeContainer>();
            pmaskNode->SetMaskNode(prenNode);

            if (index + 1 < DisplayObjectArray.GetSize())
            {
                // skip the entries not in the tree
                unsigned tidx = DisplayObjectArray[index + 1].TreeIndex;
                while (!DisplayObjectArray[index + 1].IsInRenderTree())
                {
                    ++updateFrom;
                    ++index;
                    if (index + 1 < DisplayObjectArray.GetSize())
                        tidx = DisplayObjectArray[index + 1].TreeIndex;
                    else
                        break;
                }
                if (tidx != ~0u)
                {
                    for (UPInt i = index + 1, j = 0;
                         i < DisplayObjectArray.GetSize() && DisplayObjectArray[i].GetDepth() <= ch->ClipDepth &&
                         DisplayObjectArray[i].GetDepth() > ch->Depth;
                         ++i)
                    {
                        DisplayEntry& de = DisplayObjectArray[i];
                        ++updateFrom;
                        if (!de.IsInRenderTree())
                            continue;
                        // a mask inside the new mask (swapDepths): stop there
                        if (de.GetClipDepth() != 0)
                            break;
                        Ptr<TreeNode> ptnode = pcontainer->GetAt(tidx);
                        pcontainer->Remove(tidx, 1);
                        de.TreeIndex     = e.TreeIndex;
                        de.MaskTreeIndex = (unsigned)j;
                        pmaskNode->Insert(de.MaskTreeIndex, ptnode);
                        --treeIndexDelta;
                        ++j;
                    }
                }
            }
            pcontainer->Insert(e.TreeIndex, pmaskNode);
        }
        else
            pcontainer->Insert(e.TreeIndex, prenNode);

        // shift the tree indices of the entries after it
        for (UPInt i = updateFrom; i < DisplayObjectArray.GetSize(); ++i)
        {
            DisplayEntry& de = DisplayObjectArray[i];
            if (de.TreeIndex != ~0u)
                de.TreeIndex += treeIndexDelta;
        }
    }
}

// @0x1425fb590
bool DisplayList::SwapRenderTreeNodes(DisplayObjectBase* powner, UPInt index1, UPInt index2)
{
    DisplayEntry& e1 = DisplayObjectArray[index1];
    DisplayEntry& e2 = DisplayObjectArray[index2];

    if (e1.GetDisplayObject()->HasIndirectTransform() || e2.GetDisplayObject()->HasIndirectTransform())
        return false;

    TreeNode*      n1     = e1.GetDisplayObject()->GetRenderNode();
    UPInt          ti1    = (e1.MaskTreeIndex == ~0u) ? e1.TreeIndex : e1.MaskTreeIndex;
    TreeContainer* par1   = static_cast<TreeContainer*>(n1->GetParent());
    TreeNode*      n2     = e2.GetDisplayObject()->GetRenderNode();
    UPInt          ti2    = (e2.MaskTreeIndex == ~0u) ? e2.TreeIndex : e2.MaskTreeIndex;
    TreeContainer* par2   = static_cast<TreeContainer*>(n2->GetParent());

    if (e1.GetClipDepth() == 0 && e2.GetClipDepth() == 0)
    {
        if (par1 == par2)
        {
            // same container: remove the later one with the shifted index
            if (ti1 < ti2)
            {
                par1->Remove(ti1, 1);
                par2->Remove(ti2 - 1, 1);
                par1->Insert(ti1, n2);
                par2->Insert(ti2, n1);
            }
            else
            {
                par2->Remove(ti2, 1);
                par1->Remove(ti1 - 1, 1);
                par2->Insert(ti2, n1);
                par1->Insert(ti1, n2);
            }
        }
        else
        {
            par1->Remove(ti1, 1);
            par2->Remove(ti2, 1);
            par1->Insert(ti1, n2);
            par2->Insert(ti2, n1);
        }
        Alg::Swap(e1.TreeIndex, e2.TreeIndex);
        Alg::Swap(e1.MaskTreeIndex, e2.MaskTreeIndex);
    }
    else
    {
        // masks involved: take both out and put them back
        Alg::Swap(e1.TreeIndex, e2.TreeIndex);
        Alg::Swap(e1.MaskTreeIndex, e2.MaskTreeIndex);
        RemoveFromRenderTree(powner, index1);
        RemoveFromRenderTree(powner, index2);
        InsertIntoRenderTree(powner, index1);
        InsertIntoRenderTree(powner, index2);
    }
    return true;
}

// ---------------------------------------------------------------------------------------------------------------------
// Events, visits and bounds

// Mouse events go from the top (the end of the list) down.
// @0x1425fa5e0
void DisplayList::PropagateMouseEvent(const EventId& id)
{
    for (SPInt i = (SPInt)(DisplayObjectArray.GetSize() - 1); i >= 0; i--)
    {
        DisplayObjectBase* ch = DisplayObjectArray[i].GetDisplayObject();
        if (!ch->GetVisible())
            continue;
        if (ch->IsInteractiveObject())
            static_cast<InteractiveObject*>(ch)->PropagateMouseEvent(id);
        // the handlers may have shortened the list
        if (i >= (SPInt)DisplayObjectArray.GetSize())
            i = (SPInt)DisplayObjectArray.GetSize();
    }
}

// Key events go from the bottom up.
// @0x1425fa540
void DisplayList::PropagateKeyEvent(const EventId& id, int* pkeyMask)
{
    for (UPInt i = 0; i < DisplayObjectArray.GetSize(); ++i)
    {
        // the handler may release the object
        Ptr<DisplayObjectBase> ch = DisplayObjectArray[i].GetDisplayObject();
        if (!ch->GetVisible())
            continue;
        if (ch->IsInteractiveObject())
            static_cast<InteractiveObject*>(ch.GetPtr())->PropagateKeyEvent(id, pkeyMask);
    }
}

// @0x1425fbb50
void DisplayList::VisitMembers(MemberVisitor* pvisitor) const
{
    for (UPInt i = 0, n = DisplayObjectArray.GetSize(); i < n; ++i)
    {
        DisplayObjectBase* ch = DisplayObjectArray[i].GetDisplayObject();
        // named members only
        if (ch->IsInteractiveObject())
        {
            const ASString& name = static_cast<InteractiveObject*>(ch)->GetName();
            if (name.GetSize() != 0)
                pvisitor->Visit(name, static_cast<InteractiveObject*>(ch));
        }
    }
}

// Union of the children's bounds; transform maps the owner's space (child matrices are applied here).
// @0x1425f9580
// MS2-FUNCTIONAL: the exe gives the matrix copy and the returned bounds the other stack slots, which reorders the inlined Prepend
RectF DisplayList::GetBounds(const Matrix2F& transform) const
{
    UPInt    n = GetCount();
    RectF    r(0);
    RectF    temp;
    Matrix2F m;

    for (UPInt i = 0; i < n; i++)
    {
        DisplayObjectBase* ch = GetDisplayObject(i);
        if (ch)
        {
            m = transform;
            m.Prepend(ch->GetMatrix());
            temp = ch->GetBounds(m);
            if (!temp.IsEmpty())
            {
                if (!r.IsEmpty())
                    r.Union(temp);
                else
                    r = temp;
            }
        }
    }
    return r;
}

// The same with the shapes' outline rectangles (strokes ignored).
// @0x1425f9ba0
// MS2-FUNCTIONAL: the exe gives the matrix copy and the returned bounds the other stack slots, which reorders the inlined Prepend
RectF DisplayList::GetRectBounds(const Matrix2F& transform) const
{
    UPInt    n = GetCount();
    RectF    r(0);
    RectF    temp;
    Matrix2F m;

    for (UPInt i = 0; i < n; i++)
    {
        DisplayObjectBase* ch = GetDisplayObject(i);
        if (ch)
        {
            m = transform;
            m.Prepend(ch->GetMatrix());
            temp = ch->GetRectBounds(m);
            if (!temp.IsEmpty())
            {
                if (!r.IsEmpty())
                    r.Union(temp);
                else
                    r = temp;
            }
        }
    }
    return r;
}

}} // namespace Scaleform::GFx
