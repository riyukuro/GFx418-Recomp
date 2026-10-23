// Recovered Scaleform 4.1.18 Render: the cache effects (Render_CacheEffect, sfr_render_07h). A cache node whose
// tree node carries a filter, mask, blend mode or 3D view / projection state wraps the bundle entries of its subtree
// in start / end marker entries; the markers' sort keys make the renderer push and pop the effect around them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The chain (CacheEffectChain, render_treecachenode.h) keeps the effects in the fixed order filter, mask, blend
// mode, view, projection; Length counts the entries of the wrapped range including the markers.
#ifndef MS2_SF_RENDER_CACHEEFFECT_H
#define MS2_SF_RENDER_CACHEEFFECT_H

#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_states.h"

namespace Scaleform { namespace Render {

using MatrixPoolImpl::HMatrix;

// vftable 0x143193cd0; 0x18 bytes
class CacheEffect : public NewOverrideBase<StatRender_TreeCache_Mem>
{
    friend class CacheEffectChain;

protected:
    CacheEffect* pNext;
    UInt32       Length;   // entries of the range this effect (and the ones inside it) wraps

public:
    CacheEffect(CacheEffect* next) : pNext(next), Length(0) { }
    virtual ~CacheEffect() { }

    virtual StateType      GetType() const       = 0;
    virtual TreeCacheNode* GetSourceNode() const = 0;
    // true when the parent's pattern must be rebuilt
    virtual bool           Update(const State* state) = 0;
    // wraps chain (the subtree's entries) in this effect's markers; a mask also splices in its mask's chain
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain = 0) = 0;
    virtual void           GetRange(BundleEntryRange* result) = 0;

    typedef CacheEffect* (*CreateFunc)(TreeCacheNode* node, const State* state, CacheEffect* next);

protected:
    // start, the chain, end
    void ChainNextDefault(BundleEntryRange* chain, BundleEntry& start, BundleEntry& end)
    {
        start.SetNextPattern(chain->GetFirst());
        start.pChain      = 0;
        start.ChainHeight = 0;
        chain->GetLast()->SetNextPattern(&end);
        end.pChain      = 0;
        end.ChainHeight = 0;
        Length = chain->GetLength() + 2;
        chain->Init(&start, &end, Length);
    }
};

// A mask: push (clipped or not), the mask's own chain, end, the masked chain, pop. vftable 0x143193d00; 0xe8 bytes.
class MaskEffect : public CacheEffect
{
public:
    MaskEffect(TreeCacheNode* node, MaskEffectState mes, const HMatrix& areaMatrix, CacheEffect* next);

    BundleEntry     StartEntry;     // +0x18
    BundleEntry     EndEntry;       // +0x58
    BundleEntry     PopEntry;       // +0x98
    MaskEffectState MES;            // +0xd8
    HMatrix         BoundsMatrix;   // +0xe0

    // true when the clip state changed
    bool UpdateMatrix(MaskEffectState mes, const Matrix2F& areaMatrix);

    virtual StateType      GetType() const       { return State_MaskNode; }
    virtual TreeCacheNode* GetSourceNode() const { return StartEntry.pSourceNode; }
    virtual bool           Update(const State* state);
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain);
    virtual void           GetRange(BundleEntryRange* result);

    static CacheEffect* Create(TreeCacheNode* node, const State* state, CacheEffect* next);
};

// vftable 0x143193d30; 0x98 bytes
class BlendModeEffect : public CacheEffect
{
public:
    BlendModeEffect(TreeCacheNode* node, const BlendState& state, CacheEffect* next);
    ~BlendModeEffect();

    BundleEntry StartEntry;   // +0x18
    BundleEntry EndEntry;     // +0x58

    virtual StateType      GetType() const       { return State_BlendMode; }
    virtual TreeCacheNode* GetSourceNode() const { return StartEntry.pSourceNode; }
    virtual bool           Update(const State* state);
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain);
    virtual void           GetRange(BundleEntryRange* result);

    static CacheEffect* Create(TreeCacheNode* node, const State* state, CacheEffect* next);
};

// A filter; a filter set that changes nothing leaves the chain unwrapped. vftable 0x143193d60; 0xa8 bytes.
class FilterEffect : public CacheEffect
{
public:
    FilterEffect(TreeCacheNode* node, const HMatrix& m, const FilterState& state, CacheEffect* next);
    ~FilterEffect();

    bool        Contributing;   // +0x18
    BundleEntry StartEntry;     // +0x20
    BundleEntry EndEntry;       // +0x60
    HMatrix     BoundsMatrix;   // +0xa0

    void UpdateMatrix(const Matrix2F& boundsMatrix);
    void UpdateCxform(const Cxform& cx);

    virtual StateType      GetType() const       { return State_Filter; }
    virtual TreeCacheNode* GetSourceNode() const { return StartEntry.pSourceNode; }
    virtual bool           Update(const State* state);
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain);
    virtual void           GetRange(BundleEntryRange* result);

    static CacheEffect* Create(TreeCacheNode* node, const State* state, CacheEffect* next);
};

// vftable 0x143193d90; 0x98 bytes
class ViewMatrix3DEffect : public CacheEffect
{
public:
    ViewMatrix3DEffect(TreeCacheNode* node, const ViewMatrix3DState& state, CacheEffect* next);
    ~ViewMatrix3DEffect();

    BundleEntry StartEntry;   // +0x18
    BundleEntry EndEntry;     // +0x58

    virtual StateType      GetType() const       { return State_ViewMatrix3D; }
    virtual TreeCacheNode* GetSourceNode() const { return StartEntry.pSourceNode; }
    virtual bool           Update(const State* state);
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain);
    virtual void           GetRange(BundleEntryRange* result);

    static CacheEffect* Create(TreeCacheNode* node, const State* state, CacheEffect* next);
};

// vftable 0x143193dc0; 0x98 bytes
class ProjectionMatrix3DEffect : public CacheEffect
{
public:
    ProjectionMatrix3DEffect(TreeCacheNode* node, const ProjectionMatrix3DState& state, CacheEffect* next);
    ~ProjectionMatrix3DEffect();

    BundleEntry StartEntry;   // +0x18
    BundleEntry EndEntry;     // +0x58

    virtual StateType      GetType() const       { return State_ProjectionMatrix3D; }
    virtual TreeCacheNode* GetSourceNode() const { return StartEntry.pSourceNode; }
    virtual bool           Update(const State* state);
    virtual void           ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain);
    virtual void           GetRange(BundleEntryRange* result);

    static CacheEffect* Create(TreeCacheNode* node, const State* state, CacheEffect* next);
};

// (appended for sfr_render_06e)
inline CacheEffect* CacheEffectChain::GetEffect(StateType type) const
{
    CacheEffect* e = pEffect;
    while (e && e->GetType() != type)
        e = e->pNext;
    return e;
}

// (appended for sfr_render_05j)
inline bool CacheEffectChain::GetRange(BundleEntryRange* range)
{
    if (!pEffect)
        return false;
    pEffect->GetRange(range);
    return true;
}

}} // namespace Scaleform::Render

#endif
