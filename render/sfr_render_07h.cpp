// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the cache effects
// (Render_CacheEffect): the effect chain of a cache node and the mask, blend mode, filter and 3D view / projection
// effects wrapping a subtree's bundle entries in marker entries.
// Queue unit sfr_render_07 is split along its original sources (07h Render_CacheEffect).
// MS2-UNIT: sfr_render_07h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426dc560-0x1426de710 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GProjectionMatrix3DEffect@Render@Scaleform@@UEAAPEAXI@Z 0x1426dd9f0 ; prop
// MS2-PIN: ??_GViewMatrix3DEffect@Render@Scaleform@@UEAAPEAXI@Z 0x1426ddb00 ; prop
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_cacheeffect.h"

namespace Scaleform { namespace Render {

// ----- MaskEffect

// @0x1426dc560
CacheEffect* MaskEffect::Create(TreeCacheNode* node, const State*, CacheEffect* next)
{
    RectF    bounds(0.0f, 0.0f, 0.0f, 0.0f);
    Matrix2F areaMatrix;
    Matrix3F viewMatrix;
    Matrix4F viewProj;

    node->CalcViewMatrix(&viewMatrix, &viewProj);
    MaskEffectState mes = node->calcMaskBounds(&bounds, &areaMatrix, viewMatrix, viewProj, MES_NoMask,
                                               node->CalcFilterFlag() ? TF_ParentFilter : 0);
    HMatrix m = node->GetMatrixPool().CreateMatrix(areaMatrix);
    return SF_HEAP_AUTO_NEW(node) MaskEffect(node, mes, m, next);
}

// @0x1426dc6f0
CacheEffect* BlendModeEffect::Create(TreeCacheNode* node, const State* state, CacheEffect* next)
{
    return SF_HEAP_AUTO_NEW(node) BlendModeEffect(node, *(const BlendState*)state, next);
}

// @0x1426dc810
CacheEffect* FilterEffect::Create(TreeCacheNode* node, const State* state, CacheEffect* next)
{
    RectF    bounds(0.0f, 0.0f, 0.0f, 0.0f);
    Matrix2F areaMatrix;
    Matrix3F viewMatrix;
    Matrix4F viewProj;

    node->CalcViewMatrix(&viewMatrix, &viewProj);
    node->calcFilterBounds(&bounds, &areaMatrix, viewMatrix, viewProj);
    HMatrix m = node->GetMatrixPool().CreateMatrix(areaMatrix);
    m.SetCxform(node->GetNodeData()->Cx);
    return SF_HEAP_AUTO_NEW(node) FilterEffect(node, m, *(const FilterState*)state, next);
}

// @0x1426dcac0
CacheEffect* ViewMatrix3DEffect::Create(TreeCacheNode* node, const State* state, CacheEffect* next)
{
    const ViewMatrix3DState* viewState = (const ViewMatrix3DState*)state;
    return SF_HEAP_AUTO_NEW(node) ViewMatrix3DEffect(node, *viewState, next);
}

// @0x1426dcbe0
CacheEffect* ProjectionMatrix3DEffect::Create(TreeCacheNode* node, const State* state, CacheEffect* next)
{
    const ProjectionMatrix3DState* projState = (const ProjectionMatrix3DState*)state;
    return SF_HEAP_AUTO_NEW(node) ProjectionMatrix3DEffect(node, *projState, next);
}

// ----- constructors

// @0x1426dcd00
BlendModeEffect::BlendModeEffect(TreeCacheNode* node, const BlendState& state, CacheEffect* next)
    : CacheEffect(next),
      StartEntry(node, SortKey(SortKey_BlendModeStart, state.GetBlendMode())),
      EndEntry(node, SortKey(SortKey_BlendModeEnd, Blend_None))
{
}

// @0x1426dcde0
FilterEffect::FilterEffect(TreeCacheNode* node, const HMatrix& m, const FilterState& state, CacheEffect* next)
    : CacheEffect(next), Contributing(true),
      StartEntry(node, SortKey(SortKey_FilterStart, state.GetFilters())),
      EndEntry(node, SortKey(SortKey_FilterEnd, (const FilterSet*)0)),
      BoundsMatrix(m)
{
}

// @0x1426dcf00
MaskEffect::MaskEffect(TreeCacheNode* node, MaskEffectState mes, const HMatrix& areaMatrix, CacheEffect* next)
    : CacheEffect(next),
      StartEntry(node, SortKey(mes == MES_Clipped ? SortKeyMask_PushClipped : SortKeyMask_Push)),
      EndEntry(node, SortKey(SortKeyMask_End)),
      PopEntry(node, SortKey(SortKeyMask_Pop)),
      MES(mes), BoundsMatrix(areaMatrix)
{
}

// @0x1426dd090
ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(TreeCacheNode* node, const ProjectionMatrix3DState& state,
                                                   CacheEffect* next)
    : CacheEffect(next),
      StartEntry(node, SortKey(SortKey_ProjectionMatrix3DStart, state.GetProjectionMatrix3D())),
      EndEntry(node, SortKey(SortKey_ProjectionMatrix3DEnd, (const Matrix4FRef*)0))
{
}

// @0x1426dd170
ViewMatrix3DEffect::ViewMatrix3DEffect(TreeCacheNode* node, const ViewMatrix3DState& state, CacheEffect* next)
    : CacheEffect(next),
      StartEntry(node, SortKey(SortKey_ViewMatrix3DStart, state.GetViewMatrix3D())),
      EndEntry(node, SortKey(SortKey_ViewMatrix3DEnd, (const Matrix3FRef*)0))
{
}

// ----- destructors

// @0x1426dd250
BlendModeEffect::~BlendModeEffect()
{
}

// @0x1426dd330
CacheEffectChain::~CacheEffectChain()
{
    CacheEffect* effect = pEffect;
    while (effect)
    {
        CacheEffect* dead = effect;
        effect = effect->pNext;
        delete dead;
    }
}

// @0x1426dd360
FilterEffect::~FilterEffect()
{
}

// @0x1426dd450
ProjectionMatrix3DEffect::~ProjectionMatrix3DEffect()
{
}

// @0x1426dd520
ViewMatrix3DEffect::~ViewMatrix3DEffect()
{
}

// ----- ChainNext / GetRange

void BlendModeEffect::ChainNext(BundleEntryRange* chain, BundleEntryRange*)
{
    ChainNextDefault(chain, StartEntry, EndEntry);
}

// a set of filters that changes nothing draws its chain as is
// @0x1426ddc60
void FilterEffect::ChainNext(BundleEntryRange* chain, BundleEntryRange*)
{
    const FilterSet* filters = (const FilterSet*)StartEntry.Key.GetData();
    Contributing = filters && filters->IsContributing();
    StartEntry.SetNextPattern(chain->GetFirst());
    if (Contributing)
    {
        StartEntry.pChain      = 0;
        StartEntry.ChainHeight = 0;
        chain->GetLast()->SetNextPattern(&EndEntry);
        EndEntry.pChain      = 0;
        EndEntry.ChainHeight = 0;
        Length = chain->GetLength() + 2;
        chain->Init(&StartEntry, &EndEntry, Length);
    }
    else
    {
        EndEntry.SetNextPattern(chain->GetLast());
        Length = chain->GetLength();
    }
}

// Without a mask chain the start entry is left unlinked and the end / pop entries remember the unwrapped chain.
// @0x1426ddd00
void MaskEffect::ChainNext(BundleEntryRange* chain, BundleEntryRange* maskChain)
{
    if (MES == MES_NoMask || !maskChain || maskChain->GetLength() == 0)
    {
        StartEntry.SetNextPattern(0);
        EndEntry.SetNextPattern(chain->GetFirst());
        PopEntry.SetNextPattern(chain->GetLast());
        Length = chain->GetLength();
    }
    else
    {
        StartEntry.SetNextPattern(maskChain->GetFirst());
        StartEntry.pChain      = 0;
        StartEntry.ChainHeight = 0;
        maskChain->GetLast()->SetNextPattern(&EndEntry);
        EndEntry.SetNextPattern(chain->GetFirst());
        EndEntry.pChain      = 0;
        EndEntry.ChainHeight = 0;
        chain->GetLast()->SetNextPattern(&PopEntry);
        PopEntry.pChain      = 0;
        PopEntry.ChainHeight = 0;
        Length = chain->GetLength() + maskChain->GetLength() + 3;
        chain->Init(&StartEntry, &PopEntry, Length);
    }
}

void ProjectionMatrix3DEffect::ChainNext(BundleEntryRange* chain, BundleEntryRange*)
{
    ChainNextDefault(chain, StartEntry, EndEntry);
}

void ViewMatrix3DEffect::ChainNext(BundleEntryRange* chain, BundleEntryRange*)
{
    ChainNextDefault(chain, StartEntry, EndEntry);
}

void BlendModeEffect::GetRange(BundleEntryRange* result)
{
    result->Init(&StartEntry, &EndEntry, Length);
}

void FilterEffect::GetRange(BundleEntryRange* result)
{
    if (Contributing)
        result->Init(&StartEntry, &EndEntry, Length);
    else
        result->Init(StartEntry.GetNextPattern(), EndEntry.GetNextPattern(), Length);
}

void MaskEffect::GetRange(BundleEntryRange* result)
{
    if (StartEntry.HasNextPattern())
        result->Init(&StartEntry, &PopEntry, Length);
    else
        result->Init(EndEntry.GetNextPattern(), PopEntry.GetNextPattern(), Length);
}

void ProjectionMatrix3DEffect::GetRange(BundleEntryRange* result)
{
    result->Init(&StartEntry, &EndEntry, Length);
}

void ViewMatrix3DEffect::GetRange(BundleEntryRange* result)
{
    result->Init(&StartEntry, &EndEntry, Length);
}

// ----- Update

// the blend key holds the mode itself
bool BlendModeEffect::Update(const State* state)
{
    SortKeyData mode = (SortKeyData)(SPInt)((const BlendState*)state)->GetBlendMode();
    if (StartEntry.Key.GetData() != mode)
    {
        StartEntry.Key.SetData(mode);
        return true;
    }
    return false;
}

// @0x1426ddff0
bool FilterEffect::Update(const State* state)
{
    StartEntry.ClearBundle();
    EndEntry.ClearBundle();
    StartEntry.Key = SortKey(SortKey_FilterStart, ((const FilterState*)state)->GetFilters());
    EndEntry.Key   = SortKey(SortKey_FilterEnd, (const FilterSet*)0);
    return true;
}

// a change between clipped and unclipped needs the other push key
// @0x1426de170
bool MaskEffect::Update(const State*)
{
    TreeCacheNode* node = StartEntry.pSourceNode;
    bool           updateParent = false;
    RectF          bounds(0.0f, 0.0f, 0.0f, 0.0f);
    Matrix2F       areaMatrix;
    Matrix3F       viewMatrix;
    Matrix4F       viewProj;

    node->CalcViewMatrix(&viewMatrix, &viewProj);
    MaskEffectState mes = node->calcMaskBounds(&bounds, &areaMatrix, viewMatrix, viewProj, MES,
                                               node->CalcFilterFlag() ? TF_ParentFilter : 0);

    SortKeyType     keyType;
    SortKeyMaskType maskType = SortKeyMask_Push;
    if (mes == MES_Clipped)
    {
        keyType  = SortKey_MaskStartClipped;
        maskType = SortKeyMask_PushClipped;
    }
    else
        keyType = SortKey_MaskStart;
    if (keyType != StartEntry.Key.GetType())
    {
        StartEntry.ClearBundle();
        StartEntry.Key = SortKey(maskType);
        updateParent   = true;
    }

    MES = mes;
    BoundsMatrix.SetMatrix2D(areaMatrix);
    return updateParent;
}

// @0x1426de330
bool ProjectionMatrix3DEffect::Update(const State* state)
{
    StartEntry.ClearBundle();
    StartEntry.Key = SortKey(SortKey_ProjectionMatrix3DStart,
                             ((const ProjectionMatrix3DState*)state)->GetProjectionMatrix3D());
    return true;
}

// @0x1426de400
bool ViewMatrix3DEffect::Update(const State* state)
{
    StartEntry.ClearBundle();
    StartEntry.Key = SortKey(SortKey_ViewMatrix3DStart, ((const ViewMatrix3DState*)state)->GetViewMatrix3D());
    return true;
}

// @0x1426de4d0
void FilterEffect::UpdateCxform(const Cxform& cx)
{
    BoundsMatrix.SetCxform(cx);
}

// ----- CacheEffectChain

// the order effects nest in, outermost first, with the change bit and factory of each
struct ChainOrderRecord
{
    StateType               Type;
    unsigned                ChangeFlag;
    CacheEffect::CreateFunc Factory;
};

static ChainOrderRecord ChainOrderSequence[] =
{
    { State_Filter,             Change_State_Filter,             FilterEffect::Create },
    { State_MaskNode,           Change_State_MaskNode,           MaskEffect::Create },
    { State_BlendMode,          Change_State_BlendMode,          BlendModeEffect::Create },
    { State_ViewMatrix3D,       Change_State_ViewMatrix3D,       ViewMatrix3DEffect::Create },
    { State_ProjectionMatrix3D, Change_State_ProjectionMatrix3D, ProjectionMatrix3DEffect::Create }
};

// Walks the fixed order: an existing effect of the kind is updated, or deleted once its state is gone; a missing
// one is created when its state appeared.
// @0x1426de4e0
bool CacheEffectChain::UpdateEffects(TreeCacheNode* node, unsigned changeFlags)
{
    bool updateParent = false;
    if (!node->pNode)
        return false;

    const StateBag& states = node->pNode->GetDisplayData()->States;
    CacheEffect**   prev   = &pEffect;
    CacheEffect*    effect = pEffect;
    if (!effect && states.IsEmpty())
        return false;

    for (UPInt i = 0; i < sizeof(ChainOrderSequence) / sizeof(ChainOrderSequence[0]); i++)
    {
        const ChainOrderRecord& r = ChainOrderSequence[i];

        if (effect && effect->GetType() == r.Type)
        {
            CacheEffect* next = effect->pNext;
            if (changeFlags & r.ChangeFlag)
            {
                const State* state = states.GetState(r.Type);
                if (!state)
                {
                    delete effect;
                    *prev        = next;
                    updateParent = true;
                    effect       = next;
                    continue;
                }
                updateParent |= effect->Update(state);
            }
            prev   = &effect->pNext;
            effect = next;
        }
        else if (changeFlags & r.ChangeFlag)
        {
            const State* state = states.GetState(r.Type);
            if (state)
            {
                CacheEffect* created = r.Factory(node, state, effect);
                if (created)
                {
                    *prev = created;
                    prev  = &created->pNext;
                }
            }
        }
    }
    return updateParent;
}

// @0x1426de670
void FilterEffect::UpdateMatrix(const Matrix2F& boundsMatrix)
{
    BoundsMatrix.SetMatrix2D(boundsMatrix);
}

// @0x1426de680
bool MaskEffect::UpdateMatrix(MaskEffectState mes, const Matrix2F& areaMatrix)
{
    BoundsMatrix.SetMatrix2D(areaMatrix);
    return mes != MES;
}

// innermost first: each effect wraps what the ones after it built
// @0x1426de6c0
void CacheEffectChain::updateBundleChain(CacheEffect* effect, BundleEntryRange* chain, BundleEntryRange* maskChain)
{
    if (effect->pNext)
        updateBundleChain(effect->pNext, chain, maskChain);
    effect->ChainNext(chain, maskChain);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7CacheEffect@Render@Scaleform@@6B@ 0x143193cd0
// MS2-PIN: ??_7MaskEffect@Render@Scaleform@@6B@ 0x143193d00
// MS2-PIN: ??_7BlendModeEffect@Render@Scaleform@@6B@ 0x143193d30
// MS2-PIN: ??_7FilterEffect@Render@Scaleform@@6B@ 0x143193d60
// MS2-PIN: ??_7ViewMatrix3DEffect@Render@Scaleform@@6B@ 0x143193d90
// MS2-PIN: ??_7ProjectionMatrix3DEffect@Render@Scaleform@@6B@ 0x143193dc0
