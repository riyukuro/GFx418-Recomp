// Recovered Scaleform 4.1.18 Render: TreeCacheText, the render-side cache of a TreeText (Render_TreeCacheText).
// It owns the TextMeshProvider that turns the node's TextLayout into meshes (unit sfr_render_07n).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x1a0 bytes.
#ifndef MS2_SF_RENDER_TREECACHETEXT_H
#define MS2_SF_RENDER_TREECACHETEXT_H

#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_treetext.h"
#include "ms2/scaleform/include/render/render_textmeshprovider.h"

namespace Scaleform { namespace Render {

class TreeCacheText : public TreeCacheMeshBase
{
public:
    TreeCacheText(TreeText* node, Renderer2DImpl* renderer2D, unsigned flags);
    ~TreeCacheText();

    TreeText*                 GetNode() const     { return (TreeText*)pNode; }
    const TreeText::NodeData* GetNodeData() const { return GetNode()->GetDisplayData(); }

    void UpdateCache(TreeCacheContainer* parent, UInt16 depth);

    virtual void      HandleChanges(unsigned changeBits);
    virtual void      UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth);
    virtual void      UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags);
    virtual void      propagateMaskFlag(unsigned partOfMask);
    virtual void      propagateEdgeAA(EdgeAAMode parentEdgeAA);
    virtual void      forceUpdateImages();
    virtual MeshBase* GetMesh();
    virtual void      RemoveMesh();
    // the distance field shadow of the text filter, handed to the shader as the matrix user data (vslot 16)
    virtual void      UpdateDistanceFieldUniforms();

    TextMeshProvider* GetMeshProvider();
    TextMeshProvider* CreateMeshProvider();
    Bundle*           GetBundle() const { return SorterShapeNode.pBundle; }

    TreeCacheText*   pNextNoBatch;   // +0xb8
    TextMeshProvider TMProvider;     // +0xc0

private:
    void     getMatrix4F(Matrix4F* m4, const Matrix4F& viewProj) const;
    unsigned calcMeshGenFlags() const;
};

}} // namespace Scaleform::Render

#endif
