// Recovered Scaleform 4.1.18 Render: TreeShape, the display tree node of a Flash shape (Render_TreeShape). Its
// NodeData holds the shape's mesh provider and morph ratio; the render side caches it as one TreeCacheShapeLayer per
// draw layer (under a TreeCacheShape when there is more than one layer).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// TreeShape::NodeData is 0xa0 bytes: pMeshProvider +0x90, MorphRatio +0x98; vftable 0x14317bc40. Bodies in
// sfr_render_03f.
#ifndef MS2_SF_RENDER_TREESHAPE_H
#define MS2_SF_RENDER_TREESHAPE_H

#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"

namespace Scaleform { namespace Render {

class TreeShape : public TreeNode
{
public:
    class NodeData : public ContextData_ImplMixin<NodeData, TreeNode::NodeData>
    {
        typedef ContextData_ImplMixin<NodeData, TreeNode::NodeData> BaseClass;

    public:
        NodeData() : BaseClass(ET_Shape), MorphRatio(0) {}
        NodeData(NonlocalCloneArg<NodeData> src)
            : BaseClass(NonlocalCloneArg<BaseClass>(*src.pC)), pMeshProvider(src->pMeshProvider),
              MorphRatio(src->MorphRatio)
        {
        }

        Ptr<ShapeMeshProvider> pMeshProvider;   // +0x90
        float                  MorphRatio;      // +0x98

        virtual bool PropagateUp(Entry* entry) const;

        virtual TreeCacheNode* updateCache(TreeCacheNode* parent, TreeCacheNode* insert,
                                           TreeNode* node, UInt16 depth) const;

        virtual TreeNode* CloneCreate(Context* context) const;
    };

    SF_RENDER_CONTEXT_ENTRY_INLINES(NodeData)
};

}} // namespace Scaleform::Render

#endif
