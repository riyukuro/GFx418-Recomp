// Recovered Scaleform 4.1.18 Render: TreeCacheText, the render-side cache of a TreeText (Render_TreeCacheText).
// Outline only: what TreeText::NodeData::updateCache needs to create one (the size and the constructor, exe
// 0x1426d5e40). The members land with the Render_TreeCacheText unit.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x1a0 bytes.
#ifndef MS2_SF_RENDER_TREECACHETEXT_H
#define MS2_SF_RENDER_TREECACHETEXT_H

#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_treetext.h"

namespace Scaleform { namespace Render {

class TreeCacheText : public TreeCacheMeshBase
{
public:
    TreeCacheText(TreeText* node, Renderer2DImpl* renderer2D, unsigned flags);
    ~TreeCacheText();

    virtual void      HandleChanges(unsigned changeBits);
    virtual void      UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags);
    virtual MeshBase* GetMesh();
    virtual void      RemoveMesh();

protected:
    UByte Unk_Members[0x1a0 - 0xb8];   // +0xb8
};

}} // namespace Scaleform::Render

#endif
