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
class MeshProvider;
class PrimitiveFill;

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

// what a key's data is and how it is counted
struct SortKeyInterface
{
    SortKeyType Type;
    unsigned    Flags;

    virtual ~SortKeyInterface() {}
    virtual void AddRef(SortKeyData) {}
    virtual void Release(SortKeyData) {}
};

class SortKey
{
protected:
    SortKeyInterface* pImpl;
    SortKeyData       Data;

    void addRef() const  { pImpl->AddRef(Data); }
    void release() const { pImpl->Release(Data); }

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
};

// a group of consecutive entries with one key; vslot 3 refreshes an entry's mesh
class Bundle : public RefCountBaseNTS<Bundle, StatRender_RenderBatch_Mem>
{
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
};

// one leaf's place in the sorted bundle lists (0x40 bytes)
class BundleEntry
{
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

    void         SetNextPattern(BundleEntry* next) { pNextPattern = next; }
    BundleEntry* GetNextPattern() const            { return pNextPattern; }
    bool         HasNextPattern() const            { return pNextPattern != 0; }
};

// The bundle of simple shapes sharing one fill (Render_PrimitiveBundle); only the primitive's fill pointer is laid
// out.
class PrimitiveBundle : public Bundle
{
    UByte          Unk_Drawable[0x68 - 0x38];   // DrawableBundle, the head of the Primitive
public:
    PrimitiveFill* pFill;                       // +0x68

    PrimitiveFill* GetFill() const { return pFill; }
};

}} // namespace Scaleform::Render

#endif
