// Recovered Scaleform 4.1.18 Render: the render-thread cache nodes mirroring the TreeNode tree (Render_TreeCacheNode),
// as much as the tree node TU needs: the base layout, TreeCacheContainer's inline constructor and its vftable
// (13 slots, 0x14318ebc8; the TU constructing it emits the deleting destructor).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
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

namespace Scaleform { namespace Render {

class TreeCacheRoot;
class Renderer2DImpl;
class BundleEntry;
struct TransformArgs;

enum TransformFlags
{
    TF_None   = 0,
    TF_Matrix = Change_Matrix,
    TF_Cxform = Change_CxForm
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
};

// the cache effects of a node (mask, blend, filters): a single chain head here
class CacheEffectChain
{
public:
    void* pEffect;
};

// the 8 bytes between the vftable pointer and the list links (+0x08; neither the constructor nor the destructor
// touches them)
struct TreeCacheNodeHead
{
    void* pReserved;
};

// 0x70 bytes, list links at +0x10
class TreeCacheNode : public NewOverrideBase<StatRender_TreeCache_Mem>, public TreeCacheNodeHead,
                      public ListNode<TreeCacheNode>
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
};

}} // namespace Scaleform::Render

#endif
