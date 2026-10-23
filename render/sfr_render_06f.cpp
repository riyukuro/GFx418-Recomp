// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the bundle bookkeeping
// (Render_Bundle): a Bundle owns the array of entries chained under its top entry; ranges of entries are matched
// against each other key by key so that equal keys of sibling subtrees get chained into one bundle.
// Queue unit sfr_render_06 is split along its original sources (06f Render_Bundle).
// MS2-UNIT: sfr_render_06f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426bdf50-0x1426be790 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_treecachenode.h"

namespace Scaleform { namespace Render {

// ----- Bundle

// @0x1426bdf50
void Bundle::InsertEntry(UPInt index, BundleEntry* entry)
{
    Entries.InsertAt(index, entry);
}

// @0x1426be220
void Bundle::RemoveEntries(UPInt index, UPInt count)
{
    for (unsigned i = 0; i < count; i++)
    {
        BundleEntry* e = Entries[index + i];
        e->pBundle.Clear();
        e->IndexHint = 0;
    }
    Entries.RemoveMultipleAt(index, count);
}

// @0x1426be2e0
void Bundle::RemoveEntry(BundleEntry* entry)
{
    UPInt index;
    if (findEntryIndex(&index, entry))
        RemoveEntries(index, 1);
}

// (Bundle::UpdateMesh 0x1426be700: nothing for a plain bundle, defined with the vftable users below)

// @0x1426be590
void Bundle::UpdateChain(BundleEntry* newTop)
{
    NeedUpdate = false;

    UPInt i = 0;
    for (BundleEntry* e = newTop; e; e = e->pChain, i++)
    {
        if (i < Entries.GetSize() && Entries[i] == e)
            continue;

        // already ours further down: drop the entries in between
        if (e->pBundle == this)
        {
            UPInt j = i;
            while (j < Entries.GetSize() && Entries[j] != e)
                j++;
            if (j > i)
                RemoveEntries(i, j - i);
            if (i < Entries.GetSize() && Entries[i] == e)
                continue;
        }

        e->SetBundle(this, i);
        InsertEntry(i, e);
    }

    if (i < Entries.GetSize())
        RemoveEntries(i, Entries.GetSize() - i);
    pTop = newTop;
}

// @0x1426be700
void Bundle::UpdateMesh(BundleEntry*)
{
}

// @0x1426be740
bool Bundle::findEntryIndex(UPInt* pindex, BundleEntry* entry)
{
    UPInt hint = entry->IndexHint;
    if (hint < Entries.GetSize() && Entries[hint] == entry)
    {
        *pindex = hint;
        return true;
    }
    for (UPInt i = 0; i < Entries.GetSize(); i++)
    {
        if (Entries[i] == entry)
        {
            entry->IndexHint = (UInt16)i;
            *pindex          = i;
            return true;
        }
    }
    return false;
}

// ----- BundleEntry

// @0x1426be520
bool BundleEntry::UpdateBundleEntry(TreeCacheRoot* tr, Renderer2DImpl* r, const BundleIterator& ib)
{
    Key.UpdateBundleEntry(this, tr, r, ib);
    if (pBundle)
    {
        Ptr<Bundle> bundle = pBundle;
        if (bundle->NeedUpdate)
            bundle->UpdateChain(this);
    }
    return true;
}

// ----- BundleEntryRange

// @0x1426be450
void BundleEntryRange::StripChains()
{
    for (BundleEntry* e = pFirst; e; e = e->pNextPattern)
    {
        if (e->pBundle)
            e->pBundle->NeedUpdate = true;
        e->pChain      = 0;
        e->ChainHeight = 0;
        if (e == pLast)
            break;
    }
}

// @0x1426be490
void BundleEntryRange::StripChainsByDepth(unsigned topDepth)
{
    for (BundleEntry* e = pFirst; e; e = e->pNextPattern)
    {
        BundleEntry* p = e;
        if (e->pBundle)
            e->pBundle->NeedUpdate = true;

        // keep the links that stay within the depth, cut the chain at the first one that does not
        while (p->pChain)
        {
            if ((unsigned)p->ChainHeight > (unsigned)p->pSourceNode->Depth - topDepth)
                break;
            if (!(p = p->pChain))
                goto next;
        }
        p->pChain      = 0;
        p->ChainHeight = 0;
    next:
        if (e == pLast)
            break;
    }
}

// @0x1426be710
void BundleEntryRange::VerifyValidChildDepth()
{
    for (BundleEntry* e = pFirst;; e = e->pNextPattern)
    {
        BundleEntry* p = e;
        while (p->pChain)
            p = p->pChain;
        if (e == pLast)
            break;
    }
}

// ----- BundleEntryRangeMatcher

// @0x1426bdfc0
bool BundleEntryRangeMatcher::Match(BundleEntryRange& other, unsigned* pmergeDepth) const
{
    if (other.GetLength() > GetLength())
        return false;

    BundleEntry* pentry = pFirst;
    BundleEntry* oentry = other.pFirst;
    if (pentry && oentry)
    {
    // the open range-start keys of our side, and how many of them other matched too
    enum { KeyStackLimit = 6 };
    SortKey* keyStack[KeyStackLimit];
    unsigned stackDepth = 0;
    unsigned stackMatch = 0;
    UPInt    i          = 0;

    do
    {
        bool matched = false;

        if (stackMatch == stackDepth && pentry->Key.MatchNoOverlap(oentry->Key))
        {
            if (pmergeDepth)
            {
                // append other's entry to the tail of our chain
                BundleEntry* tail = (i < LastEntryCount) ? pLastEntries[i] : 0;
                if (!tail)
                    tail = pentry;
                while (tail->pChain)
                    tail = tail->pChain;
                TreeCacheNode* tailNode = tail->pSourceNode;
                tail->pChain      = oentry;
                tail->ChainHeight = (UInt16)(tailNode->Depth - *pmergeDepth);

                if (i < LastEntryCount)
                    pLastEntries[i] = oentry;
                else if (i < MergeLengthLimit)
                {
                    while (LastEntryCount < i)
                        pLastEntries[LastEntryCount++] = 0;
                    LastEntryCount++;
                    pLastEntries[i] = oentry;
                }
            }
            oentry  = (oentry != other.pLast) ? oentry->pNextPattern : 0;
            matched = true;
        }

        if (pentry->Key.IsRangeStartKey())
        {
            if (stackDepth == KeyStackLimit)
                return false;
            keyStack[stackDepth++] = &pentry->Key;
            if (matched)
                stackMatch++;
        }
        else if (stackDepth)
        {
            unsigned          top        = stackDepth - 1;
            SortKeyTransition transition = keyStack[top]->GetRangeTransition(pentry->Key);
            if (transition != SKT_Skip)
            {
                if (stackMatch == stackDepth && !matched)
                    return false;
                if (transition == SKT_End)
                {
                    if (stackMatch == stackDepth)
                        stackMatch--;
                    stackDepth = top;
                }
                else
                    keyStack[top] = &pentry->Key;
            }
        }

        if (pentry == pLast)
            break;
        pentry = pentry->pNextPattern;
        i++;
    } while (oentry);
    }
    return oentry == 0;
}

}} // namespace Scaleform::Render
