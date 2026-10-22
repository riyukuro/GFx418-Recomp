// Recovered Scaleform 4.1.18 Render: GlyphQueue, the slot allocator of the dynamic glyph cache textures. Every
// texture is cut into horizontal bands of MaxSlotHeight; a band is cut into slots (vertical strips, kept in a
// least-recently-used queue); a slot holds a binary tree of glyph rectangles (pNext / pNex2 are the two children).
// Allocation tries the active (not full) slots, then a fresh slot at the right end of the last band, then evicts
// the oldest unpinned slots, merging neighbours when one is too narrow.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctor 0x1426e9140 (0x148 bytes): Slots +0x20, SlotQueue +0x48, ActiveSlots +0x60
// (its root is a whole GlyphSlot), Glyphs +0xc8, Bands +0xf0, GlyphHTable +0x108, Notifiers +0x118,
// pEvictNotifier +0x140.
#ifndef MS2_SF_RENDER_GLYPHQUEUE_H
#define MS2_SF_RENDER_GLYPHQUEUE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_listalloc.h"
#include "ms2/scaleform/kernel/sf_arrayunsafe.h"
#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_textlayout.h"
#include "ms2/scaleform/include/render/render_sync.h"

namespace Scaleform { namespace Render {

class FontCacheHandle;
class TextMeshProvider;
struct GlyphNode;
struct GlyphBand;
struct GlyphSlot;

// a texture rectangle in texels
struct GlyphRect
{
    UInt16 x, y, w, h;

    GlyphRect() {}
    GlyphRect(unsigned x0, unsigned y0, unsigned w0, unsigned h0)
        : x(UInt16(x0)), y(UInt16(y0)), w(UInt16(w0)), h(UInt16(h0)) {}
};

// told when a slot is taken away from the text meshes that use it
class GlyphEvictNotifier
{
public:
    virtual ~GlyphEvictNotifier() {}
    virtual void Evict(TextMeshProvider* tm) = 0;
    virtual void ApplyInUseList() = 0;
    virtual bool UpdatePinList() = 0;
};

// one text mesh that uses a slot (linked into GlyphSlot::TextFields)
struct TextNotifier : public ListNode<TextNotifier>
{
    TextMeshProvider* pText;   // +0x10
    GlyphSlot*        pSlot;   // +0x18
};

struct GlyphSlot : ListNode<GlyphSlot>
{
    enum
    {
        FullFlag = 0x8000U,    // in TextureId: taken out of the active list
        Mask     = 0x8000U
    };

    GlyphNode*         pRoot;         // +0x10
    GlyphSlot*         pPrevInBand;   // +0x18
    GlyphSlot*         pNextInBand;
    GlyphSlot*         pPrevActive;   // +0x28
    GlyphSlot*         pNextActive;
    GlyphBand*         pBand;         // +0x38
    UInt16             TextureId;     // +0x40
    UInt16             x, w;          // +0x42
    UInt16             Failures;      // +0x46
    unsigned           PinCount;      // +0x48
    List<TextNotifier> TextFields;    // +0x50
    Ptr<Fence>         SlotFence;     // +0x60 the last fence that drew from this slot
};

// the links of the slots of one band
struct GlyphSlot_Band
{
    static void             SetPrev(GlyphSlot* s, GlyphSlot* v) { s->pPrevInBand = v; }
    static void             SetNext(GlyphSlot* s, GlyphSlot* v) { s->pNextInBand = v; }
    static const GlyphSlot* GetPrev(const GlyphSlot* s)         { return s->pPrevInBand; }
    static const GlyphSlot* GetNext(const GlyphSlot* s)         { return s->pNextInBand; }
    static GlyphSlot*       GetPrev(GlyphSlot* s)               { return s->pPrevInBand; }
    static GlyphSlot*       GetNext(GlyphSlot* s)               { return s->pNextInBand; }
};

// the links of the slots that still take glyphs
struct GlyphSlot_Active
{
    static void             SetPrev(GlyphSlot* s, GlyphSlot* v) { s->pPrevActive = v; }
    static void             SetNext(GlyphSlot* s, GlyphSlot* v) { s->pNextActive = v; }
    static const GlyphSlot* GetPrev(const GlyphSlot* s)         { return s->pPrevActive; }
    static const GlyphSlot* GetNext(const GlyphSlot* s)         { return s->pNextActive; }
    static GlyphSlot*       GetPrev(GlyphSlot* s)               { return s->pPrevActive; }
    static GlyphSlot*       GetNext(GlyphSlot* s)               { return s->pNextActive; }
};

// a glyph (Param.pFont set) or free space (pFont 0) of a slot tree
struct GlyphNode
{
    GlyphParam    Param;    // +0x00
    GlyphSlot*    pSlot;    // +0x18
    GlyphNode*    pNext;    // +0x20 first child
    GlyphNode*    pNex2;    // +0x28 second child
    GlyphRect     mRect;    // +0x30
    Point<SInt16> Origin;   // +0x38
    float         Scale;    // +0x3c
};

struct GlyphBand
{
    UInt16                           TextureId;
    UInt16                           y, h;
    UInt16                           RightSpace;   // width not given to any slot yet
    List2<GlyphSlot, GlyphSlot_Band> Slots;        // +0x08
};

class GlyphQueueVisitor
{
public:
    enum RectType
    {
        Rect_Slot,
        Rect_SlotPinned,
        Rect_Glyph
    };

    virtual ~GlyphQueueVisitor() {}
    virtual void Visit(const GlyphParam* param, const RectF& rect, RectType type) = 0;
};

// key of the glyph table: points at the GlyphNode's own Param
struct GlyphParamHash
{
    const GlyphParam* Param;

    GlyphParamHash() : Param(0) {}
    GlyphParamHash(const GlyphParam* p) : Param(p) {}

    UPInt operator()(const GlyphParamHash& k) const
    {
        const GlyphParam* p = k.Param;
        UPInt             f = (UPInt)p->pFont;
        return (f >> 6) ^ f ^ (UPInt)p->GlyphIndex ^ (UPInt)p->FontSize ^
               (UPInt)p->Flags ^ (UPInt)p->BlurX ^ ((UPInt)p->BlurY << 1) ^ (UPInt)p->BlurStrength;
    }
    bool operator==(const GlyphParamHash& k) const
    {
        return Param->pFont == k.Param->pFont && Param->GlyphIndex == k.Param->GlyphIndex &&
               Param->FontSize == k.Param->FontSize && Param->Flags == k.Param->Flags &&
               Param->BlurX == k.Param->BlurX && Param->BlurY == k.Param->BlurY &&
               Param->BlurStrength == k.Param->BlurStrength;
    }
};

class GlyphQueue
{
public:
    enum { SID = StatRender_Font_Mem };
    enum { MaxSlotFailures = 16 };

    GlyphQueue();                                                  // 0x1426e9140

    void Clear();                                                  // 0x1426e9870
    void Init(GlyphEvictNotifier* notifier, unsigned firstTexture, unsigned numTextures,
              unsigned textureWidth, unsigned textureHeight, unsigned maxSlotHeight,
              bool fenceWaitOnFull);                               // 0x1426e9de0

    unsigned GetMaxSlotHeight() const { return MaxSlotHeight; }
    unsigned GetNumPacked() const     { return (unsigned)GlyphHTable.GetSize(); }

    static void PinSlot(GlyphSlot* slot);                          // 0x1426ea080
    static void UnpinSlot(GlyphSlot* slot, Fence* fence);          // 0x1426ea310

    // 4.1.18: with waitOn the fence is only waited on when it is no longer pending; a pending fence pins
    static bool IsPinned(GlyphSlot* slot, bool waitOn = false)
    {
        if (slot->PinCount > 0)
            return true;
        if (waitOn && slot->SlotFence && !slot->SlotFence->IsPending(FenceType_Fragment))
            slot->SlotFence->WaitFence(FenceType_Fragment);
        else if (slot->SlotFence && slot->SlotFence->IsPending(FenceType_Fragment))
            return true;
        slot->SlotFence.Clear();
        return false;
    }

    TextNotifier* CreateNotifier(GlyphNode* node, TextMeshProvider* tm);   // 0x1426e9ab0
    void          RemoveNotifier(TextNotifier* notifier);                  // 0x1426ea220

    void UnpinAllSlots();                                          // 0x1426ea250
    void CleanUpTexture(unsigned textureId);                       // 0x1426e95e0
    void CleanUpFont(const FontCacheHandle* font);                 // 0x1426e9480
    void MergeEmptySlots();                                        // 0x1426e9eb0

    void SendGlyphToBack(GlyphNode* g) { SlotQueue.SendToBack(g->pSlot); }

    GlyphNode* FindGlyph(const GlyphParam& gp);                    // 0x1426e9bc0
    GlyphNode* AllocateGlyph(const GlyphParam& gp, unsigned w, unsigned h);   // 0x1426e9280

    unsigned ComputeUsedArea() const;                              // 0x1426e9a10
    void     VisitGlyphs(GlyphQueueVisitor* visitor) const;        // 0x1426ea390

    UPInt GetBytes() const
    {
        return Slots.GetNumBytes() + Glyphs.GetNumBytes() + Notifiers.GetNumBytes() + Bands.GetNumBytes();
    }

private:
    typedef HashLH<GlyphParamHash, GlyphNode*, GlyphParamHash, SID> CachedGlyphsType;
    typedef List2<GlyphSlot, GlyphSlot_Active>                      ActiveSlotsType;

    GlyphNode* packGlyph(unsigned w, unsigned h, GlyphNode* glyph);           // 0x1426eb400
    GlyphNode* packGlyph(unsigned w, unsigned h, GlyphSlot* slot);            // 0x1426eb5a0
    GlyphNode* findSpaceInSlots(unsigned w, unsigned h);                      // 0x1426ead70
    GlyphSlot* initNewSlot(GlyphBand* band, unsigned x, unsigned w);          // 0x1426eafe0
    GlyphNode* allocateNewSlot(unsigned w, unsigned h);                       // 0x1426ea670
    void       splitSlot(GlyphSlot* slot, unsigned w);                        // 0x1426ebdf0
    void       splitGlyph(GlyphSlot* slot, bool left, unsigned w);            // 0x1426ebd00
    bool       checkDistance(GlyphSlot* slot) const;
    GlyphSlot* mergeSlotWithNeighbor(GlyphSlot* slot);                        // 0x1426eb120
    void       mergeSlots(GlyphSlot* from, GlyphSlot* to, unsigned w);        // 0x1426eb2e0
    GlyphNode* evictOldSlot(unsigned w, unsigned h, unsigned pass);           // 0x1426ea8f0
    GlyphNode* evictOldSlot(unsigned w, unsigned h);                          // 0x1426ea880
    void       releaseGlyphTree(GlyphNode* glyph);                            // 0x1426eb7f0
    void       releaseSlot(GlyphSlot* slot);                                  // 0x1426eb860
    void       computeGlyphArea(const GlyphNode* glyph, unsigned* used) const;   // 0x1426ea820
    static const GlyphNode* findFontInSlot(GlyphNode* glyph, const FontCacheHandle* font);   // 0x1426ead20
    static bool slotIsEmpty(const GlyphSlot* slot);
    static bool slotsAreEmpty(const GlyphSlot* a, const GlyphSlot* b);

    unsigned                                MinSlotSpace;        // +0x00
    unsigned                                FirstTexture;
    unsigned                                NumTextures;
    unsigned                                TextureWidth;
    unsigned                                TextureHeight;       // +0x10
    unsigned                                MaxSlotHeight;
    unsigned                                NumBandsInTexture;
    bool                                    FenceWaitOnFullCache;
    ListAllocLH_POD<GlyphSlot, 127, SID>    Slots;               // +0x20
    List<GlyphSlot>                         SlotQueue;           // +0x48 oldest first
    unsigned                                SlotQueueSize;       // +0x58
    ActiveSlotsType                         ActiveSlots;         // +0x60
    ListAllocLH_POD<GlyphNode, 127, SID>    Glyphs;              // +0xc8
    ArrayUnsafeLH_POD<GlyphBand, SID>       Bands;               // +0xf0
    CachedGlyphsType                        GlyphHTable;         // +0x108
    unsigned                                NumUsedBands;        // +0x110
    ListAllocLH_POD<TextNotifier, 127, SID> Notifiers;           // +0x118
    GlyphEvictNotifier*                     pEvictNotifier;      // +0x140
};

}} // namespace Scaleform::Render

#endif
