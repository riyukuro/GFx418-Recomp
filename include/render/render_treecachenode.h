// Recovered Scaleform 4.1.18 Render: the render-thread cache nodes mirroring the TreeNode tree (Render_TreeCacheNode),
// as much as the tree node TU needs: the base layout, TreeCacheContainer's inline constructor and its vftable
// (13 slots, 0x14318ebc8; the TU constructing it emits the deleting destructor).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The shape cache nodes (sfr_render_03f) add TransformArgs, the cache node helpers they call, TreeCacheMeshBase and
// the TreeCacheRoot update lists.
//
// Render_TreeCacheNode itself is not recovered yet: the out-of-line members are symbols-manual rows
// (TreeCacheNode ctor 0x142680100, UpdateInsertIntoParent 0x142682de0, ~TreeCacheContainer 0x142680150 and the
// container's virtuals).
#ifndef MS2_SF_RENDER_TREECACHENODE_H
#define MS2_SF_RENDER_TREECACHENODE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_constants.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"

namespace Scaleform { namespace Render {

class TreeCacheRoot;
class Renderer2DImpl;
class BundleEntry;
struct TransformArgs;
class HAL;
class MeshBase;
class PrimitiveFillManager;

enum TransformFlags
{
    TF_None   = 0,
    TF_Matrix = Change_Matrix,
    TF_Cxform = Change_CxForm,
    // (appended for sfr_render_03f)
    TF_NeedCull     = 0x10,
    TF_CullCxform   = 0x20,   // only leaf shapes cull on the color transform
    TF_Has2D        = 0x40,
    TF_Has3D        = 0x80,
    TF_ParentFilter = 0x100
};

// update bits of TreeCacheNode::UpdateFlags beyond the change bits
enum
{
    Update_Pattern = 0x01000000,
    Update_InList  = 0x80000000,
    // (appended for sfr_render_05j)
    Update_PatternBounds = 0x02000000,   // a child's bounds moved: verify the pattern
    Update_Pattern_Mask  = Update_Pattern | Update_PatternBounds,
    // the state changes the cache effects (blend, mask, 3D view / projection, filter) follow
    Change_State_Effect_Mask = Change_State_BlendMode | Change_State_MaskNode | Change_State_ViewMatrix3D |
                               Change_State_ProjectionMatrix3D | Change_State_Filter
};

// What UpdateTransform hands down the cache tree: the cull rectangle, the accumulated 2D / 3D matrices and color
// transform, and the view-projection of the nearest 3D states (computed on first use). 0xe0 bytes.
struct TransformArgs
{
    RectF CullRect;

private:
    Matrix3F                       Mat3D;        // +0x10
    const ViewMatrix3DState*       viewState;    // +0x40
    const ProjectionMatrix3DState* projState;    // +0x48
    mutable Matrix4F               ViewProj;     // +0x50
    mutable bool                   bRecomputeViewProj;

public:
    Matrix2F Mat;    // +0xa0
    Cxform   Cx;     // +0xc0

    TransformArgs(const TransformArgs& src, const Matrix2F& mat)
        : CullRect(src.CullRect), Mat3D(Matrix3F::NoInit), ViewProj(Matrix4F::NoInit), Mat(mat), Cx(src.Cx)
    {
        copyViewProj(src);
    }

    void            SetMatrix3D(const Matrix3F& m) { Mat3D = m; }
    const Matrix3F& GetMat3DDirect() const         { return Mat3D; }

    const Matrix4F& GetViewProj() const
    {
        if (bRecomputeViewProj)
        {
            if (viewState && projState)
                ViewProj = Matrix4F(Matrix4F(projState->GetProjectionMatrix3D()->M),
                                    Matrix3F(viewState->GetViewMatrix3D()->M));
            else
                ViewProj.SetIdentity();
            bRecomputeViewProj = false;
        }
        return ViewProj;
    }

private:
    void copyViewProj(const TransformArgs& src)
    {
        viewState          = src.viewState;
        projState          = src.projState;
        bRecomputeViewProj = src.bRecomputeViewProj;
        ViewProj           = src.ViewProj;
    }

public:
    // (appended for sfr_render_05j) the cull rectangle and view-projection only
    TransformArgs(const TransformArgs& src)
        : CullRect(src.CullRect), Mat3D(Matrix3F::NoInit), ViewProj(Matrix4F::NoInit), Mat(Matrix2F::NoInit),
          Cx(Cxform::NoInit)
    {
        copyViewProj(src);
    }
    // a 3D transform; the 2D matrix starts as the identity
    TransformArgs(const TransformArgs& src, const Matrix3F& mat)
        : CullRect(src.CullRect), Mat3D(mat), ViewProj(Matrix4F::NoInit), Mat(Matrix2F::Identity), Cx(src.Cx)
    {
        copyViewProj(src);
    }
    // what the root hands its children: no 3D states yet
    TransformArgs(const RectF& cullRect, const Matrix2F& mat2D, const Matrix3F& mat3D, const Cxform& cx)
        : CullRect(cullRect), Mat3D(mat3D), viewState(0), projState(0), ViewProj(Matrix4F::NoInit),
          bRecomputeViewProj(false), Mat(mat2D), Cx(cx)
    {
    }

    void SetMatrix3D(const Matrix3F& m1, const Matrix3F& m2) { Mat3D.MultiplyMatrix(m1, m2); }
    void PrependMatrix3D(const Matrix3F& m)                  { Mat3D.Prepend(m); }

    // the 3D matrix, with the 2D one applied first when both are in use (0x142681550)
    void GetMatrix3D(TransformFlags flags, Matrix3F* m) const
    {
        if (flags & TF_Has3D)
        {
            if (flags & TF_Has2D)
                m->MultiplyMatrix(Mat3D, Mat);
            else
                *m = Mat3D;
        }
        else
            *m = Mat;
    }

    // a new view or projection state forces the product to be recomputed
    void SetViewProj(const ViewMatrix3DState* view, const ProjectionMatrix3DState* proj)
    {
        if (view)
        {
            viewState          = view;
            bRecomputeViewProj = true;
        }
        if (proj)
        {
            projState          = proj;
            bRecomputeViewProj = true;
        }
    }
    // the states of src (when given), then the node's own
    void SetViewProj(const TreeNode::NodeData* data, const TransformArgs* src)
    {
        if (src)
            copyViewProj(*src);
        if (data)
        {
            const ViewMatrix3DState* view =
                data->HasViewMatrix3D() ? data->GetState<ViewMatrix3DState>() : 0;
            const ProjectionMatrix3DState* proj =
                data->HasProjectionMatrix3D() ? data->GetState<ProjectionMatrix3DState>() : 0;
            SetViewProj(view, proj);
        }
    }
};

enum BundleEntryRangeType
{
    Range_Empty   = 0,
    Range_Invalid = 0x80000000
};

// a run of bundle entries (Length is a count, or one of the BundleEntryRangeType markers)
class BundleEntryRange
{
public:
    BundleEntry* pFirst;
    BundleEntry* pLast;
    UInt32       Length;

    BundleEntryRange(BundleEntryRangeType type) : pFirst(0), pLast(0), Length(type) {}

    // (appended for sfr_render_07h)
    void Init(BundleEntry* first, BundleEntry* last, UInt32 length)
    {
        pFirst = first;
        pLast  = last;
        Length = length;
    }
    BundleEntry* GetFirst() const  { return pFirst; }
    BundleEntry* GetLast() const   { return pLast; }
    UInt32       GetLength() const { return Length & ~(UInt32)Range_Invalid; }

    // (appended for sfr_render_06f)
    bool           IsEmpty() const     { return pFirst == 0; }
    bool           IsValid() const     { return Length != (UInt32)Range_Invalid; }
    BundleIterator GetIterator() const { return BundleIterator(pFirst, pLast); }
    // (appended for sfr_render_05j)
    void Clear(BundleEntryRangeType type)
    {
        pFirst = pLast = 0;
        Length = type;
    }
    void SetToEntry(BundleEntry* entry)
    {
        pFirst = pLast = entry;
        Length = 1;
    }
    // walks every chain to its end; checks only (0x1426be710)
    void VerifyValidChildDepth();
    // cuts each entry's chain where it reaches below topDepth (0x1426be490)
    void StripChainsByDepth(unsigned topDepth);
    // cuts every chain, for the leaves (0x1426be450)
    void StripChains();
    SortKey& GetFirstKey() const { return pFirst->Key; }
    // next's entries go after ours, linked through the last entry's next-pattern pointer
    void Append(BundleEntryRange& next)
    {
        if (next.IsEmpty())
            return;
        if (!IsEmpty())
            pLast->pNextPattern = next.pFirst;
        else
            pFirst = next.pFirst;
        pLast = next.pLast;
        Length += next.Length;
    }
};

// (appended for sfr_render_06f) a range that remembers the chain tails it last extended (up to 8), so merging the
// child ranges into it does not walk the chains again
class BundleEntryRangeMatcher : public BundleEntryRange
{
    enum { MergeLengthLimit = 8 };
    mutable BundleEntry* pLastEntries[MergeLengthLimit];   // +0x18
    mutable UPInt        LastEntryCount;                   // +0x58

public:
    BundleEntryRangeMatcher(BundleEntryRangeType type) : BundleEntryRange(type), LastEntryCount(0) {}

    void operator=(const BundleEntryRange& src)
    {
        BundleEntryRange::operator=(src);
        LastEntryCount = 0;
    }

    // true when other's keys are a sub-sequence of ours; with pmergeDepth, other's entries are also chained onto
    // the matching ones (0x1426bdfc0)
    bool Match(BundleEntryRange& other, unsigned* pmergeDepth = 0) const;
    void MergeMatchingChains(BundleEntryRange& other, unsigned mergeDepth) { Match(other, &mergeDepth); }
};

// (appended for sfr_render_07h) how a mask clips its content, from TreeCacheNode::calcMaskBounds
enum MaskEffectState
{
    MES_NoMask,
    MES_Culled,
    MES_Clipped,
    MES_Combinable
};

class CacheEffect;

// The cache effects of a node (filter, mask, blend mode, 3D view / projection; render_cacheeffect.h), a singly
// linked list in a fixed order. ~CacheEffectChain 0x1426dd330, UpdateEffects 0x1426de4e0, updateBundleChain
// 0x1426de6c0.
class CacheEffectChain
{
public:
    CacheEffect* pEffect;

    CacheEffectChain() : pEffect(0) { }
    ~CacheEffectChain();

    bool IsEmpty() const { return pEffect == 0; }
    // (appended for sfr_render_06e) the first effect of the kind, 0 when there is none (render_cacheeffect.h)
    inline CacheEffect* GetEffect(StateType type) const;

    // re-reads the node's states for the changed kinds; true when the parent's pattern must be rebuilt
    bool UpdateEffects(TreeCacheNode* node, unsigned changeFlags);

    void UpdateBundleChain(BundleEntryRange* chain, BundleEntryRange* maskChain)
    {
        if (pEffect)
            updateBundleChain(pEffect, chain, maskChain);
    }
    // (appended for sfr_render_05j) the outermost effect's range; false without effects
    inline bool GetRange(BundleEntryRange* range);

private:
    void updateBundleChain(CacheEffect* effect, BundleEntryRange* chain, BundleEntryRange* maskChain);
};

// 0x70 bytes, list links at +0x10: the class is 16-aligned (SortParentBounds), so the vftable pointer takes a
// 16-byte slot and +0x08 is padding
class TreeCacheNode : public NewOverrideBase<StatRender_TreeCache_Mem>, public ListNode<TreeCacheNode>
{
public:
    TreeCacheRoot*   pRoot;         // +0x20
    TreeNode*        pNode;         // +0x28
    Renderer2DImpl*  pRenderer2D;   // +0x30
    TreeCacheNode*   pParent;       // +0x38
    CacheEffectChain Effects;       // +0x40
    TreeCacheNode*   pMask;         // +0x48
    UInt16           Depth;         // +0x50
    UInt16           Flags;         // +0x52
    unsigned         UpdateFlags;   // +0x54
    TreeCacheNode*   pNextUpdate;   // +0x58
    RectF            SortParentBounds;

    TreeCacheNode(TreeNode* node, Renderer2DImpl* renderer2D, unsigned flags);
    virtual ~TreeCacheNode();

    unsigned GetFlags() const { return Flags; }

    static EdgeAAMode CalcEdgeAAMode(const TreeNode::NodeData* node, TreeCacheNode* parent)
    {
        return CalcEdgeAAMode(node, (EdgeAAMode)(parent ? (parent->GetFlags() & NF_EdgeAA_Mask) : EdgeAA_On));
    }
    static EdgeAAMode CalcEdgeAAMode(const TreeNode::NodeData* node, EdgeAAMode parentMode = EdgeAA_On)
    {
        if (parentMode == EdgeAA_Disable)
            return EdgeAA_Disable;
        EdgeAAMode nodeMode = node->GetEdgeAAMode();
        return nodeMode == EdgeAA_Inherit ? parentMode : nodeMode;
    }

    virtual void HandleChanges(unsigned changeBits) = 0;
    void         UpdateInsertIntoParent(TreeCacheNode* parent, TreeCacheNode* insert,
                                        const TreeNode::NodeData* nodeData, UInt16 depth);
    virtual void UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth);
    virtual void HandleRemoveNode();
    virtual void UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags) = 0;
    virtual void propagateMaskFlag(unsigned partOfMask);
    virtual void propagateScale9Flag(unsigned partOfScale9);
    virtual void propagateEdgeAA(EdgeAAMode parentEdgeAA);
    virtual void propagate3DFlag(unsigned parent3D);
    virtual void UpdateBundlePattern(unsigned flags);
    virtual bool GetPatternChain(BundleEntryRange* range, unsigned flags);
    virtual bool IsPatternChainValid() const;
    virtual void forceUpdateImages();

    // (appended for sfr_render_03f)
    TreeCacheNode*            GetParent() const { return pParent; }
    void                      SetFlags(unsigned flags) { Flags = (UInt16)flags; }
    const TreeNode::NodeData* GetNodeData() const { return pNode->GetDisplayData(); }

    HAL*                  GetHAL() const;
    PrimitiveFillManager& GetPrimitiveFillManager() const;
    Matrix4F              GetViewProj() const;

    void updateMaskCache(const TreeNode::NodeData* data, UInt16 depth, bool updateSubtree);
    // culls against cullRect (narrowed by a mask) and sets NF_Culled; 0x142685210. Returns flags, without
    // TF_NeedCull once the node is culled (its children need no culling).
    TransformFlags updateCulling(const TreeNode::NodeData* data, const TransformArgs& t, RectF* cullRect,
                                 TransformFlags flags);

    // (appended for sfr_render_07h)
    MatrixPoolImpl::MatrixPool& GetMatrixPool() const;                       // 0x1426815d0
    void CalcViewMatrix(Matrix3F* view, Matrix4F* viewProj) const;          // 0x142680d30
    bool CalcFilterFlag() const;                                            // 0x142680bd0
    // the node's bounds and the matrix mapping the unit square onto them
    MaskEffectState calcMaskBounds(RectF* bounds, Matrix2F* boundAreaMatrix, const Matrix3F& viewMatrix,
                                   const Matrix4F& viewProj, MaskEffectState oldState, unsigned flags);   // 0x142684500
    bool calcFilterBounds(RectF* bounds, Matrix2F* boundAreaMatrix, const Matrix3F& viewMatrix,
                          const Matrix4F& viewProj, RectF* cullRect = 0);                       // 0x142683f80

    // (appended for sfr_render_05j)
    TreeNode*      GetNode() const                  { return pNode; }
    void           SetParent(TreeCacheNode* parent) { pParent = parent; }
    void           ApplyFlags(unsigned clearMask, unsigned setMask) { Flags = (UInt16)((Flags & ~clearMask) | setMask); }
    bool           IsMaskNode() const               { return (Flags & NF_MaskNode) != 0; }
    // visible and not culled
    bool           IsDrawn() const                  { return (Flags & (NF_Visible | NF_Culled)) == NF_Visible; }
    bool           HasMask() const                  { return pMask != 0; }
    TreeCacheNode* GetMask() const                  { return pMask; }
    void           SetMask(TreeCacheNode* mask)
    {
        pMask = mask;
        SetFlags(GetFlags() | NF_HasMask);
    }
    void ClearMask()
    {
        pMask = 0;
        SetFlags(GetFlags() & ~NF_HasMask);
    }

    // the parent's pattern is rebuilt in the depth pass (never inlined: out of line at 0x142683c00)
    inline void addParentToDepthPatternUpdate();

    // unlinks from the parent's children (or mask slot) and detaches the subtree from the root
    void RemoveFromParent();
    // the mask's matrix prepended to t, then the mask's own transform update
    void updateMaskTransform(TransformArgs& t, TransformFlags flags);
    // re-wraps contentChain in the effect chain, with the mask's pattern when there is a mask
    void updateEffectChain(BundleEntryRange* contentChain);
    // a child's (or mask's) bounds in this node's space; false when empty
    bool calcChildMaskBounds(RectF* bounds, TreeCacheNode* child);
    // the node's matrix appended with every ancestor's
    void CalcViewMatrix(Matrix2F* view) const;
};

// 0xa0 bytes
class TreeCacheContainer : public TreeCacheNode
{
public:
    List<TreeCacheNode> Children;             // +0x70
    BundleEntryRange    CachedChildPattern;   // +0x80
    UPInt               Reserved98;           // +0x98 (the exe allocates 0xa0 bytes)

    TreeCacheContainer(TreeNode* node, Renderer2DImpl* renderer2D, unsigned flags)
        : TreeCacheNode(node, renderer2D, flags), CachedChildPattern(Range_Invalid)
    {
    }
    ~TreeCacheContainer();

    virtual void HandleChanges(unsigned changeBits);
    virtual void UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth);
    virtual void HandleRemoveNode();
    virtual void UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags);
    virtual void propagateMaskFlag(unsigned partOfMask);
    virtual void propagateScale9Flag(unsigned partOfScale9);
    virtual void propagateEdgeAA(EdgeAAMode parentEdgeAA);
    virtual void propagate3DFlag(unsigned parent3D);
    virtual void UpdateBundlePattern(unsigned flags);
    virtual bool GetPatternChain(BundleEntryRange* range, unsigned flags);
    virtual bool IsPatternChainValid() const;
    virtual void forceUpdateImages();

    // (appended for sfr_render_05j)
    enum { Pattern_DisableMatch = 1 };
    const TreeContainer::NodeData* GetNodeData() const { return ((TreeContainer*)pNode)->GetDisplayData(); }
    // the children's chains merged into one pattern range
    void BuildChildPattern(BundleEntryRange* pattern);
};

// (appended for sfr_render_03f)

// The root of a cache tree: the nodes waiting for an update, as one list or bucketed by depth.
// pHAL is the container's +0x98 slot.
class TreeCacheRoot : public TreeCacheContainer
{
public:
    RectF                               ViewCullRect;          // +0xa0
    bool                                ViewValid;             // +0xb0
    TreeCacheNode*                      pUpdateList;           // +0xb8
    bool                                DepthUpdatesChained;   // +0xc0
    DepthUpdateArrayPOD<TreeCacheNode*> DepthUpdates;          // +0xc8

    const TreeRoot::NodeData* GetNodeData() const { return ((TreeRoot*)pNode)->GetDisplayData(); }

    // (appended for sfr_render_04p) built by Renderer2DImpl::Draw (vftable 0x14318fb70); the HAL goes in the
    // container's +0x98 slot
    TreeCacheRoot(Renderer2DImpl* renderer2D, HAL* hal, unsigned flags, TreeNode* node)
        : TreeCacheContainer(node, renderer2D, flags), pUpdateList(0), DepthUpdatesChained(false),
          DepthUpdates(Memory::GetHeapByAddress(getThis()), 0)
    {
        Reserved98 = (UPInt)hal;
        pRoot      = this;
        CachedChildPattern.Clear(Range_Empty);
    }
    ~TreeCacheRoot()
    {
        if (pPrev)
        {
            RemoveNode();
            pPrev = pNext = 0;
        }
    }
    void* getThis() { return this; }

    void AddToUpdate(TreeCacheNode* node, unsigned flags)
    {
        if (!(node->UpdateFlags & Update_InList))
        {
            node->pNextUpdate = pUpdateList;
            pUpdateList       = node;
            flags |= Update_InList;
        }
        node->UpdateFlags |= flags;
    }

    // straight into the depth buckets once the updates were chained by depth
    void AddToDepthUpdate(TreeCacheNode* node, unsigned flags)
    {
        if (!(node->UpdateFlags & Update_InList))
        {
            if (DepthUpdatesChained)
                DepthUpdates.Link(node->Depth, &node->pNextUpdate, node);
            else
            {
                node->pNextUpdate = pUpdateList;
                pUpdateList       = node;
            }
            flags |= Update_InList;
        }
        node->UpdateFlags |= flags;
    }

    // (appended for sfr_render_05j)
    // moves the update list into the depth buckets
    void ChainUpdatesByDepth();
    void ClearDepthUpdates()
    {
        DepthUpdates.Clear();
        DepthUpdatesChained = false;
    }
    virtual void HandleChanges(unsigned changeBits);
    // runs the pending updates: changes, transforms and patterns, in depth order
    void UpdateTreeData();
    void Draw();
};

__declspec(noinline) inline void TreeCacheNode::addParentToDepthPatternUpdate()
{
    if (pRoot && GetParent())
        pRoot->AddToDepthUpdate(GetParent(), Update_Pattern);
}

// A leaf drawn through a bundle: its bundle entry and pooled matrix. 0xb8 bytes; ctor 0x142680040, dtor
// 0x1426801d0, ComputeFinalMatrix 0x142681200, UpdateBundlePattern 0x1426829e0, GetPatternChain 0x142681710.
class TreeCacheMeshBase : public TreeCacheNode
{
protected:
    virtual void ComputeFinalMatrix(const TransformArgs& t, TransformFlags flags);   // 13

public:
    BundleEntry SorterShapeNode;   // +0x70
    HMatrix     M;                 // +0xb0

    TreeCacheMeshBase(TreeNode* node, const SortKey& key, Renderer2DImpl* renderer2D, unsigned flags);
    ~TreeCacheMeshBase();

    virtual MeshBase* GetMesh()    = 0;   // 14
    virtual void      RemoveMesh() = 0;   // 15

    // @0x1426340a0
    virtual void HandleRemoveNode()
    {
        TreeCacheNode::HandleRemoveNode();
        SorterShapeNode.Removed = true;
    }
    // a leaf's chain is its own entry
    // @0x1426340c0
    virtual bool IsPatternChainValid() const { return true; }

    virtual bool GetPatternChain(BundleEntryRange* range, unsigned flags);
    virtual void UpdateBundlePattern(unsigned flags);

    // (appended for sfr_render_05j)
    virtual void HandleChanges(unsigned changeBits);
};

}} // namespace Scaleform::Render

#endif
