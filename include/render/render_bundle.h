// Recovered Scaleform 4.1.18 Render: sort keys and bundles (Render_Bundle). Leaf cache nodes carry a BundleEntry
// keyed by a SortKey; runs of entries with equal keys are drawn together as one Bundle. Only what the shape cache
// nodes use is declared here.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Out of line elsewhere: SortKey(MeshProvider*, bool) 0x1426bc870, SortKey(PrimitiveFill*, bool) 0x1426bc8c0,
// Bundle::RemoveEntry 0x1426be2e0. BundleEntry::ClearBundle is a COMDAT (0x142633750 in the shape TU).
#ifndef MS2_SF_RENDER_BUNDLE_H
#define MS2_SF_RENDER_BUNDLE_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_states.h"   // (appended for sfr_render_07h)

namespace Scaleform { namespace Render {

class BundleEntry;
class TreeCacheNode;
// (appended for sfr_render_07q)
class TreeCacheRoot;
class Renderer2DImpl;
class BundleIterator;
class MeshProvider;
class PrimitiveFill;
class SortKey;

enum SortKeyType
{
    SortKey_None          = 0,
    SortKey_PrimitiveFill = 1,
    SortKey_MeshProvider  = 2,
    SortKey_Text          = 3,
    // (appended for sfr_render_07h) the start / end markers of the cache effects
    SortKey_MaskStart                = 4,
    SortKey_MaskStartClipped         = 5,
    SortKey_MaskEnd                  = 6,   // a mask's end and pop entries
    SortKey_BlendModeStart           = 7,
    SortKey_BlendModeEnd             = 8,
    SortKey_FilterStart              = 9,
    SortKey_FilterEnd                = 10,
    SortKey_ViewMatrix3DStart        = 11,
    SortKey_ViewMatrix3DEnd          = 12,
    SortKey_ProjectionMatrix3DStart  = 13,
    SortKey_ProjectionMatrix3DEnd    = 14
};

// (appended for sfr_render_07h) the four mask markers
enum SortKeyMaskType
{
    SortKeyMask_Push,
    SortKeyMask_PushClipped,
    SortKeyMask_End,
    SortKeyMask_Pop
};

typedef void* SortKeyData;

// (appended for sfr_render_07n) selects the text key constructor
enum SortKeyTextType { SortKeyText };

// (appended for sfr_render_07q) key flags; equal keys with SKF_MatchNoOverlap share a bundle
enum SortKeyFlags
{
    SKF_MatchNoOverlap = 0x2000,
    // (appended for sfr_render_06f) the key opens a nested range (a mask / filter / blend start); the other end
    // keys close or swap it through GetRangeTransition
    SKF_RangeStart         = 0x1000,
    SKF_MatchSingleOverlap = 0x4000
};

// (appended for sfr_render_07q) how a key changes the range being matched; only the default is used so far
enum SortKeyTransition
{
    SKT_Skip,
    // (appended for sfr_render_06f) the key takes the open range's place / closes it
    SKT_Replace,
    SKT_End
};

// what a key's data is and how it is counted
struct SortKeyInterface
{
    SortKeyType Type;
    unsigned    Flags;

    virtual ~SortKeyInterface() {}
    virtual void AddRef(SortKeyData) {}
    virtual void Release(SortKeyData) {}
    // (appended for sfr_render_07q) slots 3-5: the range transition, creating / refreshing the entry's bundle, and
    // drawing it
    virtual SortKeyTransition GetRangeTransition(SortKeyData, const SortKey&) { return SKT_Skip; }
    virtual bool UpdateBundleEntry(SortKeyData, BundleEntry*, TreeCacheRoot*, Renderer2DImpl*,
                                   const BundleIterator&) { return false; }
    virtual void DrawBundleEntry(SortKeyData, BundleEntry*, Renderer2DImpl*) {}

    SortKeyInterface(SortKeyType type, unsigned flags = 0) : Type(type), Flags(flags) {}
};

class SortKey
{
protected:
    SortKeyInterface* pImpl;
    SortKeyData       Data;

    void addRef() const  { pImpl->AddRef(Data); }
    void release() const { pImpl->Release(Data); }
    // (appended for sfr_render_06e) the key constructors: take the interface and data, count through the new interface
    void setKey(SortKeyInterface* impl, SortKeyData data)
    {
        pImpl = impl;
        Data  = data;
        impl->AddRef(data);
    }

public:
    SortKey(const SortKey& src) : pImpl(src.pImpl), Data(src.Data) { addRef(); }
    ~SortKey() { release(); }
    SortKey(PrimitiveFill* fill, bool is3D = false);
    SortKey(MeshProvider* provider, bool is3D = false);

    SortKeyType GetType() const { return pImpl->Type; }
    SortKeyData GetData() const { return Data; }

    // (appended for sfr_render_07h) the effect keys: 0x1426bc910, 0x1426bca60, 0x1426bca00, 0x1426bc940, 0x1426bc9a0
    SortKey(SortKeyMaskType maskType);
    SortKey(SortKeyType blendKeyType, BlendMode mode);
    SortKey(SortKeyType filterKeyType, const FilterSet* filters);
    SortKey(SortKeyType viewKeyType, const Matrix3FRef* viewMatrix);
    SortKey(SortKeyType projKeyType, const Matrix4FRef* projMatrix);
    // the blend keys carry the mode itself, not a counted object
    void SetData(SortKeyData data) { Data = data; }
    // (appended for sfr_render_07n) the key all text of one 2D / 3D pass shares (0x1426f25f0)
    SortKey(SortKeyTextType, bool is3D);

    SortKey& operator=(const SortKey& src)
    {
        src.addRef();
        release();
        pImpl = src.pImpl;
        Data  = src.Data;
        return *this;
    }
    bool operator==(const SortKey& o) const { return pImpl == o.pImpl && Data == o.Data; }
    bool operator!=(const SortKey& o) const { return !operator==(o); }

    // (appended for sfr_render_06f) forwarders to the key interface
    unsigned GetFlags() const          { return pImpl->Flags; }
    bool     IsRangeStartKey() const   { return (pImpl->Flags & SKF_RangeStart) != 0; }
    bool     MatchNoOverlap() const    { return (pImpl->Flags & SKF_MatchNoOverlap) != 0; }
    // equal keys that may share a bundle
    bool     MatchNoOverlap(const SortKey& o) const
    {
        return Data == o.Data && pImpl == o.pImpl && (pImpl->Flags & SKF_MatchNoOverlap);
    }
    SortKeyTransition GetRangeTransition(const SortKey& key) const { return pImpl->GetRangeTransition(Data, key); }
    bool UpdateBundleEntry(BundleEntry* p, TreeCacheRoot* tr, Renderer2DImpl* r, const BundleIterator& ib)
    {
        return pImpl->UpdateBundleEntry(Data, p, tr, r, ib);
    }
    void DrawBundleEntry(BundleEntry* p, Renderer2DImpl* r) { pImpl->DrawBundleEntry(Data, p, r); }
    // (appended for sfr_render_05j) equal keys that may share a bundle even when one-entry patterns overlap
    bool MatchSingleItemOverlap(const SortKey& o) const
    {
        return Data == o.Data && pImpl == o.pImpl && (pImpl->Flags & SKF_MatchSingleOverlap);
    }
};

// a group of consecutive entries with one key; vslot 3 refreshes an entry's mesh
class Bundle : public RefCountBaseNTS<Bundle, StatRender_RenderBatch_Mem>
{
    // (appended for sfr_render_06f) StripChains / UpdateBundleEntry read and mark NeedUpdate
    friend class BundleEntryRange;
    friend class BundleEntry;
protected:
    ArrayLH<BundleEntry*> Entries;
    BundleEntry*          pTop;
    bool                  NeedUpdate;

public:
    unsigned FrameId;

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);
    virtual void UpdateMesh(BundleEntry* entry);

    void RemoveEntry(BundleEntry* entry);

    // (appended for sfr_render_07q) the chain is set up before the bundle counts as needing an update
    Bundle(BundleEntry* top) : NeedUpdate(true), FrameId(0)
    {
        UpdateChain(top);
        NeedUpdate = true;
    }
    // user-declared: the destructor stores the Bundle vtable again (TextPrimitiveBundle dtor 0x1426f2740)
    ~Bundle() {}
    void UpdateChain(BundleEntry* newTop);   // 0x1426be590

    // the position of entry in Entries, starting at its IndexHint (0x1426be740); public in the exe (QEAA)
    bool findEntryIndex(UPInt* pindex, BundleEntry* entry);
    // (appended for sfr_render_05j) a leaf's chain changed: re-check the bundle
    void SetNeedsUpdate() { NeedUpdate = true; }
};

// one leaf's place in the sorted bundle lists (0x40 bytes)
class BundleEntry
{
    // (appended for sfr_render_06f)
    friend class Bundle;
    friend class BundleIterator;
    friend class BundleEntryRange;
    friend class BundleEntryRangeMatcher;

    BundleEntry* pNextPattern;

public:
    BundleEntry*   pChain;
    UInt16         ChainHeight;
    UInt16         IndexHint;
    SortKey        Key;
    Ptr<Bundle>    pBundle;
    bool           Removed;
    TreeCacheNode* pSourceNode;

    void ClearBundle()
    {
        if (pBundle)
        {
            Ptr<Bundle> held = pBundle;
            held->RemoveEntry(this);
        }
        pBundle.Clear();
        IndexHint = 0;
    }

    // (appended for sfr_render_07h)
    BundleEntry(TreeCacheNode* node, const SortKey& key)
        : pNextPattern(0), pChain(0), ChainHeight(0), IndexHint(0), Key(key)
    {
        pSourceNode = node;
        Removed     = false;
    }
    ~BundleEntry()
    {
        if (pBundle)
        {
            Ptr<Bundle> held = pBundle;
            held->RemoveEntry(this);
        }
    }

    // (appended for sfr_render_07q) moves the entry into bundle, leaving its old one
    void SetBundle(Bundle* bundle, UPInt index)
    {
        if (pBundle && pBundle != bundle)
        {
            Ptr<Bundle> held = pBundle;
            held->RemoveEntry(this);
        }
        pBundle   = bundle;
        IndexHint = (UInt16)index;
    }

    void         SetNextPattern(BundleEntry* next) { pNextPattern = next; }
    BundleEntry* GetNextPattern() const            { return pNextPattern; }
    bool         HasNextPattern() const            { return pNextPattern != 0; }

    // (appended for sfr_render_06f) lets the key build / refresh the entry's bundle, then re-chains it (0x1426be520)
    bool UpdateBundleEntry(TreeCacheRoot* tr, Renderer2DImpl* r, const BundleIterator& ib);
    void DrawBundleEntry(Renderer2DImpl* r) { Key.DrawBundleEntry(this, r); }
};

// (appended for sfr_render_06f) walks a range's entries along pNextPattern up to and including its last one
class BundleIterator
{
    BundleEntry* pFirst;
    BundleEntry* pLast;

public:
    BundleIterator() : pFirst(0), pLast(0) {}
    BundleIterator(BundleEntry* first, BundleEntry* last) : pFirst(first), pLast(last) {}
    // (appended for sfr_render_06e) copied member by member, so a local copy stays in registers
    BundleIterator(const BundleIterator& o) : pFirst(o.pFirst), pLast(o.pLast) {}

    BundleEntry* operator->() const   { return pFirst; }
    operator bool() const             { return pFirst != 0; }
    BundleEntry* GetEntry() const     { return pFirst; }
    Bundle*      GetBundle() const    { return pFirst->pBundle; }

    void operator++(int)
    {
        if (pFirst == pLast)
            pFirst = pLast = 0;
        else
            pFirst = pFirst->pNextPattern;
    }
};

// (sfr_render_06e) PrimitiveBundle and the other drawable bundles are in render_primitivebundle.h

}} // namespace Scaleform::Render

#endif
