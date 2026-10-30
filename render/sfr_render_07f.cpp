// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the glyph cache slot
// allocator (Render_GlyphQueue): bands / slots / glyph rectangle trees, the LRU slot queue, eviction and merging.
// Queue unit sfr_render_07 is split along its original sources (07f Render_GlyphQueue).
// MS2-UNIT: sfr_render_07f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426e8fc0-0x1426ebe90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_glyphqueue.h"

namespace Scaleform { namespace Render {

// @0x1426e9140
GlyphQueue::GlyphQueue()
    : MinSlotSpace(10), FirstTexture(0), NumTextures(0), TextureWidth(0), TextureHeight(0), MaxSlotHeight(0),
      NumBandsInTexture(0), SlotQueueSize(0), NumUsedBands(0), pEvictNotifier(0)
{
}

// @0x1426e9870
void GlyphQueue::Clear()
{
    // every text mesh still using a slot gets evicted (Evict unlinks its notifier)
    for (GlyphSlot* slot = SlotQueue.GetFirst(); !SlotQueue.IsNull(slot); slot = slot->pNext)
    {
        while (!slot->TextFields.IsEmpty())
            pEvictNotifier->Evict(slot->TextFields.GetFirst()->pText);
    }
    GlyphHTable.Clear();
    SlotQueue.Clear();
    ActiveSlots.Clear();
    for (unsigned i = 0; i < NumUsedBands; ++i)
        Bands[i].Slots.Clear();
    Slots.ClearAndRelease();
    Glyphs.ClearAndRelease();
    SlotQueueSize = 0;
    NumUsedBands  = 0;
}

// @0x1426e9de0
void GlyphQueue::Init(GlyphEvictNotifier* notifier, unsigned firstTexture, unsigned numTextures,
                      unsigned textureWidth, unsigned textureHeight, unsigned maxSlotHeight, bool fenceWaitOnFull)
{
    Clear();
    FirstTexture         = firstTexture;
    NumTextures          = numTextures;
    TextureWidth         = textureWidth;
    TextureHeight        = textureHeight;
    MaxSlotHeight        = maxSlotHeight;
    NumBandsInTexture    = textureHeight / maxSlotHeight;
    FenceWaitOnFullCache = fenceWaitOnFull;
    Bands.Resize(NumBandsInTexture * NumTextures);
    pEvictNotifier = notifier;
}

// @0x1426ea080
void GlyphQueue::PinSlot(GlyphSlot* slot)
{
    ++slot->PinCount;
}

// keeps the latest pending fence
// @0x1426ea310
void GlyphQueue::UnpinSlot(GlyphSlot* slot, Fence* fence)
{
    if (fence && fence->IsPending(FenceType_Fragment))
    {
        if (!slot->SlotFence || *fence > *slot->SlotFence)
            slot->SlotFence = fence;
    }
    --slot->PinCount;
}

// first fit in the tree; a fitting free node is cut down to w x h, the rest of it split off as up to two free
// children (the larger leftover keeps the full length)
// @0x1426eb400
GlyphNode* GlyphQueue::packGlyph(unsigned w, unsigned h, GlyphNode* glyph)
{
    if (glyph->Param.pFont)
    {
        GlyphNode* found = 0;
        if (glyph->pNext)
            found = packGlyph(w, h, glyph->pNext);
        if (found)
            return found;
        if (glyph->pNex2)
            found = packGlyph(w, h, glyph->pNex2);
        return found;
    }
    if (w > glyph->mRect.w || h > glyph->mRect.h)
        return 0;

    unsigned dw = glyph->mRect.w - w;
    unsigned dh = glyph->mRect.h - h;
    if (dw >= MinSlotSpace || dh >= MinSlotSpace)
    {
        if (dw > dh)
        {
            glyph->pNext          = Glyphs.Alloc(*glyph);
            glyph->pNext->mRect.x = UInt16(glyph->mRect.x + w);
            glyph->pNext->mRect.w = UInt16(dw);
            if (dh >= MinSlotSpace)
            {
                glyph->pNex2          = Glyphs.Alloc(*glyph);
                glyph->pNex2->pNext   = 0;
                glyph->pNex2->mRect.y = UInt16(glyph->mRect.y + h);
                glyph->pNex2->mRect.h = UInt16(dh);
                glyph->pNex2->mRect.w = UInt16(w);
            }
        }
        else
        {
            glyph->pNext          = Glyphs.Alloc(*glyph);
            glyph->pNext->mRect.y = UInt16(glyph->mRect.y + h);
            glyph->pNext->mRect.h = UInt16(dh);
            if (dw >= MinSlotSpace)
            {
                glyph->pNex2          = Glyphs.Alloc(*glyph);
                glyph->pNex2->pNext   = 0;
                glyph->pNex2->mRect.x = UInt16(glyph->mRect.x + w);
                glyph->pNex2->mRect.w = UInt16(dw);
                glyph->pNex2->mRect.h = UInt16(h);
            }
        }
    }
    glyph->mRect.w = UInt16(w);
    glyph->mRect.h = UInt16(h);
    return glyph;
}

// an empty slot wider than needed gives its right part to a new slot
// @0x1426ebdf0
void GlyphQueue::splitSlot(GlyphSlot* slot, unsigned w)
{
    GlyphSlot* ns        = initNewSlot(slot->pBand, slot->x + w, slot->w - w);
    slot->w              = UInt16(w);
    slot->pRoot->mRect.w = UInt16(w);
    SlotQueue.PushFront(ns);
    SlotQueueSize++;
    slot->pBand->Slots.InsertAfter(slot, ns);
    ActiveSlots.PushFront(ns);
}

// the free full-height root rect at one end of the slot gives all but w to a new slot on that side
// @0x1426ebd00
void GlyphQueue::splitGlyph(GlyphSlot* slot, bool left, unsigned w)
{
    GlyphNode* root = slot->pRoot;
    GlyphSlot* ns;
    unsigned   nw = root->mRect.w - w;
    if (left)
    {
        ns = initNewSlot(slot->pBand, root->mRect.x, nw);
        slot->pBand->Slots.InsertBefore(slot, ns);
        slot->x       = UInt16(slot->x + nw);
        root->mRect.x = slot->x;
    }
    else
    {
        ns = initNewSlot(slot->pBand, root->mRect.x + w, nw);
        slot->pBand->Slots.InsertAfter(slot, ns);
    }
    root->mRect.w = UInt16(w);
    slot->w       = UInt16(slot->w - nw);
    SlotQueue.PushFront(ns);
    SlotQueueSize++;
    ActiveSlots.PushFront(ns);
}

// a slot that keeps failing leaves the active list
// @0x1426eb5a0
GlyphNode* GlyphQueue::packGlyph(unsigned w, unsigned h, GlyphSlot* slot)
{
    GlyphNode* glyph = slot->pRoot;
    if (glyph->Param.pFont == 0 && slot->w > 2 * w)
    {
        if (glyph->pNext == 0 && glyph->pNex2 == 0)
            splitSlot(slot, w);
        else if (glyph->pNex2 == 0 && glyph->mRect.h == slot->pBand->h && glyph->mRect.w > w)
        {
            bool left  = glyph->mRect.x == slot->x;
            bool right = glyph->mRect.x + glyph->mRect.w == slot->x + slot->w;
            if (left != right)
                splitGlyph(slot, left, w);
        }
    }
    glyph = packGlyph(w, h, slot->pRoot);
    if (glyph == 0)
        slot->Failures++;
    if (slot->Failures > MaxSlotFailures)
    {
        ActiveSlots.Remove(slot);
        slot->TextureId |= GlyphSlot::FullFlag;
    }
    else if (slot->Failures && glyph)
        slot->Failures--;
    return glyph;
}

// @0x1426ead70
GlyphNode* GlyphQueue::findSpaceInSlots(unsigned w, unsigned h)
{
    GlyphSlot* slot = ActiveSlots.GetFirst();
    while (!ActiveSlots.IsNull(slot))
    {
        GlyphSlot* next  = ActiveSlots.GetNext(slot);
        GlyphNode* glyph = packGlyph(w, h, slot);
        if (glyph)
            return glyph;
        slot = next;
    }
    return 0;
}

// @0x1426eafe0
GlyphSlot* GlyphQueue::initNewSlot(GlyphBand* band, unsigned x, unsigned w)
{
    GlyphSlot* slot = Slots.Alloc();
    GlyphNode* root = Glyphs.Alloc();
    slot->pRoot     = root;
    slot->pBand     = band;
    slot->TextureId = band->TextureId;
    slot->x         = UInt16(x);
    slot->w         = UInt16(w);
    slot->Failures  = 0;
    slot->PinCount  = 0;
    slot->TextFields.Clear();
    slot->SlotFence.NullWithoutRelease();
    root->Param.Clear();
    root->pSlot    = slot;
    root->pNext    = 0;
    root->pNex2    = 0;
    root->mRect    = GlyphRect(slot->x, band->y, slot->w, band->h);
    root->Origin.x = 0;
    root->Origin.y = 0;
    return slot;
}

// opens the next band when the last one has no room; the last band of a texture takes the remaining height
// @0x1426ea670
GlyphNode* GlyphQueue::allocateNewSlot(unsigned w, unsigned h)
{
    if (NumUsedBands == 0 || Bands[NumUsedBands - 1].RightSpace < w)
    {
        if (NumUsedBands < Bands.GetSize())
        {
            unsigned   inTex = NumUsedBands % NumBandsInTexture;
            GlyphBand& nb    = Bands[NumUsedBands];
            nb.TextureId     = UInt16(FirstTexture + NumUsedBands / NumBandsInTexture);
            nb.y             = UInt16(inTex * MaxSlotHeight);
            nb.h             = UInt16((inTex + 1 == NumBandsInTexture) ? TextureHeight - nb.y : MaxSlotHeight);
            nb.RightSpace    = UInt16(TextureWidth);
            nb.Slots.Clear();
            ++NumUsedBands;
        }
    }
    GlyphBand& band = Bands[NumUsedBands - 1];
    if (w <= band.RightSpace)
    {
        // a leftover narrower than the glyph goes to this slot too
        unsigned   dw   = band.RightSpace - w;
        unsigned   sw   = (dw < w) ? band.RightSpace : w;
        GlyphSlot* slot = initNewSlot(&band, TextureWidth - band.RightSpace, sw);
        band.RightSpace = UInt16(band.RightSpace - slot->w);
        SlotQueue.PushBack(slot);
        SlotQueueSize++;
        band.Slots.PushBack(slot);
        ActiveSlots.PushFront(slot);
        return packGlyph(w, h, slot);
    }
    return 0;
}

// @0x1426eb7f0
void GlyphQueue::releaseGlyphTree(GlyphNode* glyph)
{
    if (!glyph)
        return;
    releaseGlyphTree(glyph->pNext);
    releaseGlyphTree(glyph->pNex2);
    if (glyph->Param.pFont)
    {
        GlyphParamHash key(&glyph->Param);
        GlyphHTable.Remove(key);
    }
    glyph->Param.pFont = 0;
    Glyphs.Free(glyph);
}

// empties a slot back to one free root rect (4.1.18 does not test the pin here; the callers do)
// @0x1426eb860
void GlyphQueue::releaseSlot(GlyphSlot* slot)
{
    releaseGlyphTree(slot->pRoot->pNext);
    releaseGlyphTree(slot->pRoot->pNex2);
    while (!slot->TextFields.IsEmpty())
        pEvictNotifier->Evict(slot->TextFields.GetFirst()->pText);
    if (slot->pRoot->Param.pFont)
    {
        GlyphParamHash key(&slot->pRoot->Param);
        GlyphHTable.Remove(key);
    }
    GlyphBand* band = slot->pBand;
    if (band->RightSpace && band->Slots.IsLast(slot))
    {
        slot->w          = UInt16(slot->w + band->RightSpace);
        band->RightSpace = 0;
    }
    slot->pRoot->Param.pFont = 0;
    slot->pRoot->mRect       = GlyphRect(slot->x, slot->pBand->y, slot->w, slot->pBand->h);
    slot->pRoot->pNext       = 0;
    slot->pRoot->pNex2       = 0;
    slot->Failures           = 0;
    slot->SlotFence.Clear();
    if (slot->TextureId & GlyphSlot::FullFlag)
    {
        slot->TextureId &= ~GlyphSlot::FullFlag;
        ActiveSlots.PushFront(slot);
    }
}

// from .. to (one band, left to right) become the single slot from of width w
// @0x1426eb2e0
void GlyphQueue::mergeSlots(GlyphSlot* from, GlyphSlot* to, unsigned w)
{
    GlyphSlot* slot = from;
    GlyphBand* band = slot->pBand;
    for (;;)
    {
        GlyphSlot* next = band->Slots.GetNext(slot);
        releaseSlot(slot);
        if (slot != from)
        {
            Glyphs.Free(slot->pRoot);
            SlotQueue.Remove(slot);
            SlotQueueSize--;
            if ((slot->TextureId & GlyphSlot::FullFlag) == 0)
                ActiveSlots.Remove(slot);
            band->Slots.Remove(slot);
            Slots.Free(slot);
        }
        if (slot == to)
            break;
        slot = next;
    }
    from->w              = UInt16(w);
    from->pRoot->mRect.w = UInt16(w);
    SlotQueue.BringToFront(from);
}

// gives the (emptied) slot to its right neighbour, or its left one at the band end, when that one is not wider;
// the freed width joins the neighbour's root rect when they touch, else becomes a new free root above it
// @0x1426eb120
GlyphSlot* GlyphQueue::mergeSlotWithNeighbor(GlyphSlot* slot)
{
    GlyphBand* band    = slot->pBand;
    GlyphSlot* target  = band->Slots.GetNext(slot);
    bool       toRight = true;
    if (band->Slots.IsNull(target))
    {
        target  = band->Slots.GetPrev(slot);
        toRight = false;
    }
    if (band->Slots.IsNull(target) || target->w > slot->w)
        return 0;

    GlyphNode* slotRoot   = slot->pRoot;
    GlyphNode* targetRoot = target->pRoot;
    releaseSlot(slot);
    unsigned x = slot->x;
    unsigned w = slot->w;
    SlotQueue.Remove(slot);
    SlotQueueSize--;
    if ((slot->TextureId & GlyphSlot::FullFlag) == 0)
        ActiveSlots.Remove(slot);
    band->Slots.Remove(slot);
    Slots.Free(slot);

    bool joinRect = false;
    if (targetRoot->Param.pFont == 0 && targetRoot->pNex2 == 0 && targetRoot->mRect.h == band->h)
    {
        joinRect = toRight ? (x + w == unsigned(targetRoot->mRect.x))
                           : (unsigned(targetRoot->mRect.x + targetRoot->mRect.w) == x);
    }
    if (joinRect)
    {
        Glyphs.Free(slotRoot);
        if (toRight)
            targetRoot->mRect.x = UInt16(x);
        targetRoot->mRect.w = UInt16(targetRoot->mRect.w + w);
    }
    else
    {
        slotRoot->pNext = targetRoot;
        slotRoot->pNex2 = 0;
        slotRoot->pSlot = target;
        slotRoot->mRect = GlyphRect(x, band->y, w, band->h);
        target->pRoot   = slotRoot;
    }
    if (toRight)
        target->x = UInt16(x);
    target->w = UInt16(target->w + w);
    if (target->TextureId & GlyphSlot::FullFlag)
    {
        target->Failures = 0;
        target->TextureId &= ~GlyphSlot::FullFlag;
        ActiveSlots.PushFront(target);
    }
    return target;
}

// true when slot is in the older half of the queue (walking out from it, the front is reached first)
inline bool GlyphQueue::checkDistance(GlyphSlot* slot) const
{
    GlyphSlot* back = slot;
    GlyphSlot* fwd  = slot;
    for (;;)
    {
        if (SlotQueue.IsNull(back))
            return true;
        if (SlotQueue.IsNull(fwd))
            break;
        back = SlotQueue.GetPrev(back);
        fwd  = SlotQueue.GetNext(fwd);
    }
    return false;
}

// pass 0 looks at the older half of the queue only; then runs of unpinned neighbours in a band are merged
// @0x1426ea8f0
GlyphNode* GlyphQueue::evictOldSlot(unsigned w, unsigned h, unsigned pass)
{
    GlyphSlot* slot  = SlotQueue.GetFirst();
    unsigned   limit = pass ? SlotQueueSize : (SlotQueueSize / 2);
    for (unsigned i = 0; i <= limit && !SlotQueue.IsNull(slot); ++i)
    {
        if (!IsPinned(slot, FenceWaitOnFullCache))
        {
            if (unsigned(slot->w) >= w)
            {
                releaseSlot(slot);
                return packGlyph(w, h, slot);
            }
            GlyphSlot* merged = mergeSlotWithNeighbor(slot);
            if (merged)
            {
                if (merged->pRoot->mRect.w >= w)
                    return packGlyph(w, h, merged);
                break;
            }
        }
        slot = SlotQueue.GetNext(slot);
    }

    for (slot = SlotQueue.GetFirst(); !SlotQueue.IsNull(slot); slot = SlotQueue.GetNext(slot))
    {
        if (IsPinned(slot, FenceWaitOnFullCache))
            continue;
        unsigned   sum  = 0;
        GlyphSlot* to   = slot;
        GlyphBand* band = slot->pBand;
        while (!band->Slots.IsNull(to) && !IsPinned(to, FenceWaitOnFullCache))
        {
            bool goOn = (pass == 0) ? checkDistance(to) : true;
            if (to != slot && !goOn)
                break;
            if (to->w >= w)
            {
                releaseSlot(to);
                return packGlyph(w, h, to);
            }
            sum += to->w;
            if (band->RightSpace && band->Slots.IsLast(to) && sum + band->RightSpace >= w)
            {
                sum += band->RightSpace;
                band->RightSpace = 0;
            }
            if (sum >= w)
            {
                mergeSlots(slot, to, sum);
                return packGlyph(w, h, slot);
            }
            to = band->Slots.GetNext(to);
        }
    }
    return 0;
}

// @0x1426ea880
GlyphNode* GlyphQueue::evictOldSlot(unsigned w, unsigned h)
{
    pEvictNotifier->ApplyInUseList();
    GlyphNode* glyph = evictOldSlot(w, h, 0);
    if (glyph == 0)
    {
        pEvictNotifier->UpdatePinList();
        glyph = evictOldSlot(w, h, 1);
    }
    return glyph;
}

// one notifier per (slot, text mesh); consecutive glyphs of the same mesh reuse the last one
// @0x1426e9ab0
TextNotifier* GlyphQueue::CreateNotifier(GlyphNode* node, TextMeshProvider* tm)
{
    GlyphSlot*    slot = node->pSlot;
    TextNotifier* last = slot->TextFields.GetLast();
    if (!slot->TextFields.IsNull(last) && tm == last->pText)
        return 0;
    TextNotifier* n = Notifiers.Alloc();
    n->pText = tm;
    n->pSlot = slot;
    slot->TextFields.PushBack(n);
    return n;
}

// @0x1426ea220
void GlyphQueue::RemoveNotifier(TextNotifier* notifier)
{
    notifier->RemoveNode();
    Notifiers.Free(notifier);
}

// @0x1426e9bc0
GlyphNode* GlyphQueue::FindGlyph(const GlyphParam& gp)
{
    GlyphParamHash key(&gp);
    GlyphNode**    found = GlyphHTable.Get(key);
    if (found)
    {
        GlyphNode* glyph = *found;
        SlotQueue.SendToBack(glyph->pSlot);
        return glyph;
    }
    return 0;
}

// @0x1426e9280
GlyphNode* GlyphQueue::AllocateGlyph(const GlyphParam& gp, unsigned w, unsigned h)
{
    if (h < MinSlotSpace)
        MinSlotSpace = h;
    if (w < MinSlotSpace)
        MinSlotSpace = w;

    GlyphNode* glyph = findSpaceInSlots(w, h);
    if (glyph == 0)
    {
        glyph = allocateNewSlot(w, h);
        if (glyph == 0)
            glyph = evictOldSlot(w, h);
    }
    if (glyph == 0)
        return 0;

    glyph->Param    = gp;
    glyph->Origin.x = 0;
    glyph->Origin.y = 0;
    SlotQueue.SendToBack(glyph->pSlot);
    GlyphParamHash key(&glyph->Param);
    if (!GlyphHTable.Get(key))
        GlyphHTable.Add(key, glyph);
    return glyph;
}

// @0x1426ea250
void GlyphQueue::UnpinAllSlots()
{
    for (GlyphSlot* slot = SlotQueue.GetFirst(); !SlotQueue.IsNull(slot); slot = SlotQueue.GetNext(slot))
    {
        slot->PinCount = 0;
        IsPinned(slot, true);
    }
}

// @0x1426ea820
void GlyphQueue::computeGlyphArea(const GlyphNode* glyph, unsigned* used) const
{
    if (!glyph)
        return;
    if (glyph->Param.pFont)
        *used += glyph->mRect.w * glyph->mRect.h;
    computeGlyphArea(glyph->pNext, used);
    computeGlyphArea(glyph->pNex2, used);
}

// @0x1426e9a10
unsigned GlyphQueue::ComputeUsedArea() const
{
    unsigned total = 0;
    for (const GlyphSlot* slot = SlotQueue.GetFirst(); !SlotQueue.IsNull(slot); slot = SlotQueue.GetNext(slot))
    {
        unsigned used = 0;
        computeGlyphArea(slot->pRoot, &used);
        total += used;
    }
    return total;
}

inline bool GlyphQueue::slotIsEmpty(const GlyphSlot* slot)
{
    return (UPInt(slot->pRoot->pNext) | UPInt(slot->pRoot->pNex2)) == 0;
}

inline bool GlyphQueue::slotsAreEmpty(const GlyphSlot* a, const GlyphSlot* b)
{
    return (UPInt(a->pRoot->pNext) | UPInt(a->pRoot->pNex2) | UPInt(b->pRoot->pNext) | UPInt(b->pRoot->pNex2)) == 0;
}

// joins every pair of neighbouring empty slots of a band
// @0x1426e9eb0
void GlyphQueue::MergeEmptySlots()
{
    for (UPInt i = 0; i < NumUsedBands; ++i)
    {
        GlyphBand& band = Bands[i];
        GlyphSlot* slot = band.Slots.GetFirst();
        while (!band.Slots.IsNull(slot))
        {
            GlyphSlot* next = band.Slots.GetNext(slot);
            if (band.Slots.IsNull(next))
                break;
            if (slotsAreEmpty(slot, next))
            {
                releaseSlot(slot);
                releaseSlot(next);
                unsigned w = slot->w + next->w;
                Glyphs.Free(next->pRoot);
                SlotQueue.Remove(next);
                SlotQueueSize--;
                if ((next->TextureId & GlyphSlot::FullFlag) == 0)
                    ActiveSlots.Remove(next);
                band.Slots.Remove(next);
                Slots.Free(next);
                slot->w              = UInt16(w);
                slot->pRoot->mRect.x = slot->x;
                slot->pRoot->mRect.y = slot->pBand->y;
                slot->pRoot->mRect.w = UInt16(w);
                slot->pRoot->mRect.h = slot->pBand->h;
                SlotQueue.BringToFront(slot);
            }
            else
                slot = next;
        }
    }
}

// @0x1426e95e0
void GlyphQueue::CleanUpTexture(unsigned textureId)
{
    GlyphSlot* slot = SlotQueue.GetFirst();
    while (!SlotQueue.IsNull(slot))
    {
        GlyphSlot* next = SlotQueue.GetNext(slot);
        if (unsigned(slot->TextureId & ~GlyphSlot::Mask) == textureId)
        {
            releaseSlot(slot);
            SlotQueue.BringToFront(slot);
        }
        slot = next;
    }
    MergeEmptySlots();
}

// @0x1426ead20
const GlyphNode* GlyphQueue::findFontInSlot(GlyphNode* glyph, const FontCacheHandle* font)
{
    if (!glyph)
        return 0;
    if (glyph->Param.pFont == font)
        return glyph;
    const GlyphNode* found = findFontInSlot(glyph->pNext, font);
    if (found)
        return found;
    return findFontInSlot(glyph->pNex2, font);
}

// @0x1426e9480
void GlyphQueue::CleanUpFont(const FontCacheHandle* font)
{
    GlyphSlot* slot = SlotQueue.GetFirst();
    while (!SlotQueue.IsNull(slot))
    {
        GlyphSlot* next = SlotQueue.GetNext(slot);
        if (findFontInSlot(slot->pRoot, font))
        {
            IsPinned(slot, true);
            releaseSlot(slot);
            SlotQueue.BringToFront(slot);
        }
        slot = next;
    }
}

// every slot (pinned or not), then every cached glyph
// @0x1426ea390
void GlyphQueue::VisitGlyphs(GlyphQueueVisitor* visitor) const
{
    RectF r;
    for (const GlyphSlot* slot = SlotQueue.GetFirst(); !SlotQueue.IsNull(slot); slot = slot->pNext)
    {
        r.x1 = float(slot->x);
        r.y1 = float(slot->pBand->y);
        r.x2 = float(slot->x + slot->w);
        r.y2 = float(slot->pBand->y + slot->pBand->h);
        visitor->Visit(0, r, (slot->PinCount || slot->SlotFence) ? GlyphQueueVisitor::Rect_SlotPinned
                                                                 : GlyphQueueVisitor::Rect_Slot);
    }
    for (CachedGlyphsType::ConstIterator it = GlyphHTable.Begin(); it != GlyphHTable.End(); ++it)
    {
        const GlyphNode* node = it->Second;
        r.x1 = float(node->mRect.x);
        r.y1 = float(node->mRect.y);
        r.x2 = float(node->mRect.x + node->mRect.w);
        r.y2 = float(node->mRect.y + node->mRect.h);
        visitor->Visit(it->First.Param, r, GlyphQueueVisitor::Rect_Glyph);
    }
}

}} // namespace Scaleform::Render
// MS2-PIN: ?Get@?$Hash@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@U?$AllocatorLH@UGlyphParamHash@Render@Scaleform@@$0EP@@3@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@3@V?$HashsetCachedNodeEntry@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@@3@V?$HashSet@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UGlyphParamHash@Render@Scaleform@@$0EP@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@@2@@3@@Scaleform@@QEAAPEAPEAUGlyphNode@Render@2@AEBUGlyphParamHash@42@@Z 0x1426e9c30
// MS2-FUNCTIONAL ??$RemoveAlt@UGlyphParamHash@Render@Scaleform@@@?$HashSetBase@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UGlyphParamHash@Render@Scaleform@@$0EP@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXAEBUGlyphParamHash@Render@1@@Z: same key-field register allocation as GetAlt in the inlined findIndexCore probe
// MS2-PIN: ??$RemoveAlt@UGlyphParamHash@Render@Scaleform@@@?$HashSetBase@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UGlyphParamHash@Render@Scaleform@@$0EP@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UGlyphParamHash@Render@Scaleform@@PEAUGlyphNode@23@U123@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXAEBUGlyphParamHash@Render@1@@Z 0x1426ea0a0
