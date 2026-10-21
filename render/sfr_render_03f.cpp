// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the shape node TU
// (Render_TreeShape): TreeShape::NodeData, the render-side shape cache (TreeCacheShape for multi-layer shapes, one
// TreeCacheShapeLayer per draw layer) with its sort keys, mesh keys and transform updates.
// MS2-UNIT: sfr_render_03f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142633210-0x142636190 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_treeshape.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include <math.h>

namespace Scaleform { namespace Render {

// this build tests bounds emptiness with >= and compares rectangles x1, x2, y1, y2
static inline bool isEmptyBounds(const RectF& r) { return r.x1 >= r.x2 || r.y1 >= r.y2; }
static inline bool boundsDiffer(const RectF& a, const RectF& b)
{
    return a.x1 != b.x1 || a.x2 != b.x2 || a.y1 != b.y1 || a.y2 != b.y2;
}

// ***** The shape cache nodes

// The cache of a shape with several draw layers: a container of one TreeCacheShapeLayer per layer (the layers
// have no tree node of their own). 0xa0 bytes, vftable 0x14318f440.
class TreeCacheShape : public TreeCacheContainer
{
public:
    typedef TreeShape::NodeData NodeData;

    TreeCacheShape(TreeShape* node, Renderer2DImpl* renderer2D, unsigned flags);
    ~TreeCacheShape();

    TreeShape*         GetNode() const         { return (TreeShape*)pNode; }
    const NodeData*    GetNodeData() const     { return GetNode()->GetDisplayData(); }
    ShapeMeshProvider* GetMeshProvider() const { return GetNodeData()->pMeshProvider; }
    float              GetMorphRatio() const   { return GetNodeData()->MorphRatio; }

    virtual void HandleChanges(unsigned changeBits);
    virtual void UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth);
    virtual void UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags);
};

// One draw layer of a shape: a simple mesh keyed by its primitive fill, or a complex mesh keyed by the provider.
// Lives directly in the cache tree for a single-layer shape, else under its TreeCacheShape (pNode is then 0).
// 0xd0 bytes, vftable 0x14318f4a8.
class TreeCacheShapeLayer : public TreeCacheMeshBase
{
    friend class TreeCacheShape;

public:
    TreeCacheShapeLayer(TreeShape* node, const SortKey& key, unsigned drawLayer, Renderer2DImpl* renderer2D,
                        unsigned flags);
    ~TreeCacheShapeLayer();

    bool IsComplexShape() const      { return ComplexShape; }
    bool HasParentShapeCache() const { return pNode == 0; }

    TreeShape* GetNode() const { return (TreeShape*)pNode; }

    const TreeShape::NodeData* GetShapeNodeData() const
    {
        TreeNode* node = HasParentShapeCache() ? GetParent()->pNode : pNode;
        return ((TreeShape*)node)->GetDisplayData();
    }
    ShapeMeshProvider* GetMeshProvider() const { return GetShapeNodeData()->pMeshProvider; }
    float              GetMorphRatio() const   { return GetShapeNodeData()->MorphRatio; }

    static TreeCacheNode* Create(TreeCacheNode* parent, ShapeMeshProvider* provider, unsigned drawLayer,
                                 unsigned flags, TreeShape* shapeNode, float morphRatio);
    static SortKey CreateSortKey(TreeCacheNode* refNode, ShapeMeshProvider* provider, unsigned drawLayer,
                                 unsigned flags, Ptr<Image>* gradientImage, float morphRatio);

    // a mask mesh replaces the edge AA one
    unsigned calcMeshGenFlags() const
    {
        unsigned meshGenFlags = 0;
        if (GetFlags() & NF_PartOfMask)
            meshGenFlags |= Mesh_Mask;
        else if ((GetFlags() & NF_EdgeAA_Mask) == EdgeAA_On)
            meshGenFlags |= Mesh_EdgeAA;
        if (GetFlags() & NF_PartOfScale9)
            meshGenFlags |= Mesh_Scale9;
        return meshGenFlags;
    }

    void getShapeMatrixFrom3D(const TreeShape::NodeData* nd, Matrix2F* mat, const Matrix4F& viewProj) const;

    void updateSortKey();
    void updateSortKeyGradientMorph();

    void UpdateCache(TreeCacheContainer* parent, UInt16 depth)
    {
        Depth = depth;
        pRoot = parent->pRoot;
    }

    virtual void HandleChanges(unsigned changeBits);
    virtual void UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth);
    virtual void UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags);

    virtual void propagateMaskFlag(unsigned partOfMask);
    virtual void propagateScale9Flag(unsigned partOfScale9);
    virtual void propagateEdgeAA(EdgeAAMode parentEdgeAA);
    virtual void propagate3DFlag(unsigned parent3D);

    virtual MeshBase* GetMesh();
    virtual void      RemoveMesh();

    Bundle* GetBundle() const { return SorterShapeNode.pBundle.GetPtr(); }

    virtual void forceUpdateImages();

private:
    unsigned getLayer() const { return Layer; }

    unsigned calcMeshKey(const ShapeMeshProvider* provider, const Matrix2F& m, unsigned drawLayer, float* keyData,
                         Scale9GridData* s9g, float morphRatio) const;
    bool     updateMeshKey(Renderer2DImpl* r2D, ShapeMeshProvider* provider, float morphRatio,
                           const Matrix2F& viewMatrix, unsigned meshGenFlags, unsigned* meshKeyFlags = 0);
    void     updateTexture0Matrix();

    Ptr<MeshKey> pMeshKey;       // +0xb8
    Ptr<Image>   pGradient;      // +0xc0
    bool         ComplexShape;   // +0xc8
    unsigned     Layer;          // +0xcc
};

// ***** TreeShape::NodeData

// @0x1426340d0
// MS2-FUNCTIONAL: register allocation and block order around the inlined 3D EncloseTransform differ
bool TreeShape::NodeData::PropagateUp(Entry* entry) const
{
    RectF bounds, parentBounds;

    if (isEmptyBounds(AproxLocalBounds))
    {
        // the stroke widths are not in the identity bounds
        if (pMeshProvider)
            bounds = pMeshProvider->GetIdentityBounds();
    }
    else
        bounds = AproxLocalBounds;

    if (!isEmptyBounds(bounds))
    {
        // the filters grow the local bounds before they go to the parent space
        expandByFilterBounds(&bounds, false);
        if (!Is3D())
            M2D().EncloseTransform(&parentBounds, bounds);
        else
            parentBounds = M3D().EncloseTransform(bounds);
    }

    if (boundsDiffer(bounds, AproxLocalBounds) || boundsDiffer(parentBounds, bounds))
    {
        TreeShape* shape   = (TreeShape*)entry;
        NodeData*  data    = shape->GetWritableData(Change_AproxBounds);
        data->AproxLocalBounds  = bounds;
        data->AproxParentBounds = parentBounds;
        return IsVisible();
    }
    return false;
}

// @0x142635710
TreeCacheNode* TreeShape::NodeData::updateCache(TreeCacheNode* parent, TreeCacheNode* insert, TreeNode* node,
                                                UInt16 depth) const
{
    TreeShape*     shape = (TreeShape*)node;
    TreeCacheNode* cache = node->GetRenderData();
    if (!cache)
    {
        ShapeMeshProvider* provider  = shape->GetDisplayData()->pMeshProvider;
        unsigned           numLayers = provider->GetLayerCount();

        // a mask node's layers are part of the mask from the start (the sort key depends on it)
        unsigned flags = (Flags & (NF_Visible | NF_MaskNode)) | ((Flags & NF_MaskNode) << 1) |
                         TreeCacheNode::CalcEdgeAAMode(this, parent);
        flags |= parent->GetFlags() & (NF_PartOfMask | NF_PartOfScale9);
        flags |= Flags & NF_3D;
        if (GetState<Scale9State>())
            flags |= NF_PartOfScale9;

        // one layer goes straight into the tree; none or several get a TreeCacheShape
        if (numLayers != 1)
            cache = SF_HEAP_AUTO_NEW(parent) TreeCacheShape(shape, parent->pRenderer2D, flags);
        else
            cache = TreeCacheShapeLayer::Create(parent, provider, 0, flags, shape, MorphRatio);

        if (!cache)
            return 0;
        node->SetRenderData(cache);
    }

    cache->UpdateInsertIntoParent(parent, insert, this, depth);
    return cache;
}

// @0x1426337b0
TreeNode* TreeShape::NodeData::CloneCreate(Context* context) const
{
    return context->CreateEntry<TreeShape>(NonlocalCloneArg<NodeData>(*this));
}

// ***** TreeCacheShape

// @0x142633380
TreeCacheShape::TreeCacheShape(TreeShape* node, Renderer2DImpl* renderer2D, unsigned flags)
    : TreeCacheContainer(node, renderer2D, flags)
{
}

// @0x142633450
TreeCacheShape::~TreeCacheShape()
{
    // the layers have no tree node to remove them: delete them here
    while (!Children.IsEmpty())
    {
        TreeCacheNode* p = Children.GetFirst();
        p->RemoveNode();
        p->pPrev   = 0;
        p->pParent = 0;
        delete p;
    }
}

// @0x142634740
// MS2-FUNCTIONAL: the Mat3D copy stores with movaps (exe movups)
void TreeCacheShape::UpdateTransform(const TreeNode::NodeData* shapeData, const TransformArgs& t,
                                     TransformFlags flags)
{
    TransformArgs args(t, t.Mat);
    if (flags & TF_Has3D)
        args.SetMatrix3D(t.GetMat3DDirect());

    updateCulling(shapeData, t, &args.CullRect, (TransformFlags)(flags | TF_CullCxform));

    SortParentBounds = shapeData->AproxParentBounds;
    SetFlags(GetFlags() & ~NF_ExpandedBounds);

    // the layers were culled with the shape
    flags = (TransformFlags)(flags & ~TF_NeedCull);

    TreeCacheNode* node = Children.GetFirst();
    while (!Children.IsNull(node))
    {
        TreeCacheShapeLayer* layer = (TreeCacheShapeLayer*)node;
        layer->TreeCacheShapeLayer::UpdateTransform(shapeData, args, flags);
        node = node->pNext;
    }
}

// @0x142633e60
void TreeCacheShape::HandleChanges(unsigned changeBits)
{
    if (changeBits & Change_EdgeAAMode)
        propagateEdgeAA(CalcEdgeAAMode(GetNodeData(), GetParent()));

    if ((changeBits & Change_MorphRatio) && pRoot)
    {
        // UpdateTransform picks up the new ratio when it rebuilds the meshes
        pRoot->AddToUpdate(this, Change_Matrix);

        TreeCacheNode* node = Children.GetFirst();
        while (!Children.IsNull(node))
        {
            TreeCacheShapeLayer* layer = (TreeCacheShapeLayer*)node;
            layer->TreeCacheShapeLayer::updateSortKeyGradientMorph();
            node = node->pNext;
        }
    }
}

// @0x142634540
void TreeCacheShape::UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth)
{
    TreeCacheNode::UpdateChildSubtree(data, depth);

    ShapeMeshProvider* provider   = static_cast<const NodeData*>(data)->pMeshProvider;
    unsigned           layerCount = provider->GetLayerCount();

    if (Children.IsEmpty())
    {
        TreeCacheNode* insert = Children.GetFirst()->pPrev;
        for (unsigned drawLayer = 0; drawLayer < layerCount; ++drawLayer)
        {
            unsigned       flags = (GetFlags() & NF_EdgeAA_Mask) | NF_Visible;
            TreeCacheNode* cache =
                TreeCacheShapeLayer::Create(this, provider, drawLayer, flags, 0, GetMorphRatio());
            if (cache)
            {
                cache->UpdateInsertIntoParent(this, insert, 0, depth);
                insert = cache;
            }
        }
    }
    else
    {
        TreeCacheNode* node = Children.GetFirst();
        while (!Children.IsNull(node))
        {
            ((TreeCacheShapeLayer*)node)->UpdateCache(this, depth);
            node = node->pNext;
        }
    }
}

// ***** TreeCacheShapeLayer

// @0x1426333e0
TreeCacheShapeLayer::TreeCacheShapeLayer(TreeShape* node, const SortKey& key, unsigned drawLayer,
                                         Renderer2DImpl* renderer2D, unsigned flags)
    : TreeCacheMeshBase(node, key, renderer2D, flags), ComplexShape(key.GetType() == SortKey_MeshProvider),
      Layer(drawLayer)
{
}

// @0x1426334e0
TreeCacheShapeLayer::~TreeCacheShapeLayer()
{
}

// @0x142633810
TreeCacheNode* TreeCacheShapeLayer::Create(TreeCacheNode* parent, ShapeMeshProvider* provider, unsigned drawLayer,
                                           unsigned flags, TreeShape* shapeNode, float morphRatio)
{
    Ptr<Image> gradient(0);
    SortKey    key(CreateSortKey(parent, provider, drawLayer, flags, &gradient, morphRatio));

    TreeCacheShapeLayer* cache = SF_HEAP_AUTO_NEW(parent)
        TreeCacheShapeLayer(shapeNode, key, drawLayer, parent->pRenderer2D, flags);
    if (!cache)
        return 0;

    cache->pGradient = gradient;
    return cache;
}

// @0x142633960
SortKey TreeCacheShapeLayer::CreateSortKey(TreeCacheNode* refNode, ShapeMeshProvider* provider, unsigned drawLayer,
                                           unsigned flags, Ptr<Image>* gradientImage, float morphRatio)
{
    unsigned meshGenFlags = 0;
    if ((flags & NF_EdgeAA_Mask) == EdgeAA_On)
        meshGenFlags |= Mesh_EdgeAA;
    if (flags & NF_PartOfMask)
        meshGenFlags = Mesh_Mask;
    if (flags & NF_PartOfScale9)
        meshGenFlags |= Mesh_Scale9;

    // any 3D ancestor puts the layer in the 3D bundles
    TreeCacheNode* ancestor = refNode;
    bool           is3D     = (flags & NF_3D) ? true : false;
    do
    {
        is3D |= (ancestor->GetFlags() & NF_3D) ? true : false;
        ancestor = ancestor->GetParent();
    } while (ancestor && !is3D);

    // several fills: a complex mesh keyed by the provider
    if (provider->GetFillCount(drawLayer, meshGenFlags) > 1)
        return SortKey(&static_cast<MeshProvider&>(*provider), is3D);

    // one fill: a simple mesh keyed by the shared primitive fill
    TextureManager*       textureManager = refNode->GetHAL()->GetTextureManager();
    PrimitiveFillManager& fillManager    = refNode->GetPrimitiveFillManager();
    FillData              fillData(Fill_VColor);
    provider->GetFillData(&fillData, drawLayer, 0, meshGenFlags);
    Ptr<PrimitiveFill> fill = *fillManager.CreateFill(fillData, gradientImage, textureManager, morphRatio);
    return SortKey(fill.GetPtr(), is3D);
}

// @0x142635d20
// MS2-FUNCTIONAL: the inlined AddToDepthUpdate tests UpdateFlags through a register (exe cmp mem / or mem)
void TreeCacheShapeLayer::updateSortKey()
{
    // the key follows the flags (mask, scale9, 3D)
    SorterShapeNode.ClearBundle();

    SorterShapeNode.Key = CreateSortKey(this, GetMeshProvider(), getLayer(), GetFlags(), &pGradient, GetMorphRatio());
    ComplexShape        = (SorterShapeNode.Key.GetType() == SortKey_MeshProvider);

    pMeshKey.Clear();

    if (pRoot && GetParent())
        pRoot->AddToDepthUpdate(GetParent(), Update_Pattern | Change_Matrix);
}

// @0x142636040
void TreeCacheShapeLayer::updateSortKeyGradientMorph()
{
    if (GetMeshProvider()->HasGradientMorph())
        updateSortKey();
}

// @0x1426360b0
void TreeCacheShapeLayer::updateTexture0Matrix()
{
    if (!ComplexShape && SorterShapeNode.pBundle)
    {
        PrimitiveFill* fill    = ((PrimitiveBundle*)SorterShapeNode.pBundle.GetPtr())->GetFill();
        Texture*       texture = fill->GetTexture(0);
        if (texture)
        {
            Matrix2F tm;
            GetMeshProvider()->GetFillMatrix(pMeshKey->pMesh, &tm, getLayer(), 0, calcMeshGenFlags());
            M.SetTextureMatrix(tm, 0);
        }
    }
}

// @0x142635020
void TreeCacheShapeLayer::forceUpdateImages()
{
    // a new key only if the images changed it; else just the texture matrix
    ShapeMeshProvider* provider = GetMeshProvider();
    SortKey            key      = CreateSortKey(this, provider, getLayer(), GetFlags(), &pGradient, GetMorphRatio());
    if (key != SorterShapeNode.Key)
    {
        SorterShapeNode.ClearBundle();

        SorterShapeNode.Key = key;
        ComplexShape        = (SorterShapeNode.Key.GetType() == SortKey_MeshProvider);

        pMeshKey.Clear();

        if (pRoot && GetParent())
            pRoot->AddToUpdate(GetParent(), Update_Pattern | Change_Matrix | Change_Shape);
    }
    else if (pMeshKey)
    {
        updateTexture0Matrix();
    }
}

// @0x142633fc0
void TreeCacheShapeLayer::HandleChanges(unsigned changeBits)
{
    // only a layer with its own tree node gets the edge AA change
    if (changeBits & Change_EdgeAAMode)
        propagateEdgeAA(CalcEdgeAAMode(GetNodeData(), GetParent()));

    if ((changeBits & Change_MorphRatio) && pRoot)
    {
        pRoot->AddToUpdate(this, Change_Matrix);
        updateSortKeyGradientMorph();
    }
}

// @0x142634690
void TreeCacheShapeLayer::UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth)
{
    // the flags may change the sort key
    unsigned newFlags = (GetFlags() & ~NF_PartOfMask) |
                        (GetParent()->GetFlags() & (NF_PartOfMask | NF_PartOfScale9)) |
                        ((GetFlags() & NF_MaskNode) << 1);
    if (data && data->GetState<Scale9State>())
        newFlags |= NF_PartOfScale9;
    if (data && data->Is3D())
        newFlags |= NF_3D;

    if (newFlags != GetFlags())
    {
        SetFlags(newFlags);
        updateSortKey();
    }
    if (data)
        updateMaskCache(data, depth, true);
}

// The mesh key flags for m; keyData gets the key (the matrix key, or the scale9 setup's), its last slot the morph
// ratio.
// @0x142634d00
unsigned TreeCacheShapeLayer::calcMeshKey(const ShapeMeshProvider* provider, const Matrix2F& m, unsigned drawLayer,
                                          float* keyData, Scale9GridData* s9g, float morphRatio) const
{
    unsigned flags = MeshKey::KF_Fill;

    if (GetFlags() & NF_PartOfScale9)
    {
        // up to the node with the scale9 grid, collecting the matrices in between
        const TreeCacheNode* node = this;
        if (HasParentShapeCache())
            node = GetParent();

        Matrix2F shapeMtx;
        while (node)
        {
            const TreeNode::NodeData* nd = node->GetNodeData();
            const Scale9State*        s9 = nd->GetState<Scale9State>();
            if (s9)
            {
                s9g->S9Rect    = s9->GetRect();
                s9g->Bounds    = nd->AproxLocalBounds;
                s9g->ShapeMtx  = shapeMtx;
                s9g->Scale9Mtx = nd->M2D();
                s9g->ViewMtx   = m;

                // the grid wants the bounds without the filter margins
                nd->contractByFilterBounds(&s9g->Bounds);
                flags |= MeshKey::KF_Scale9Grid;
                break;
            }
            shapeMtx.Append(nd->M2D());
            node = node->GetParent();
        }
    }

    bool validKey = true;

    if (flags & MeshKey::KF_Scale9Grid)
    {
        s9g->MakeMeshKey(keyData);
    }
    else
    {
        validKey             = MeshKey::CalcMatrixKey(m, keyData, 0);
        unsigned strokeStyle = provider->GetLayerStroke(drawLayer);
        if (strokeStyle)
        {
            flags = MeshKey::KF_Stroke;

            StrokeStyleType ss;
            provider->GetStrokeStyle(strokeStyle, &ss, 0);
            if (ss.Flags & StrokeFlag_StrokeHinting)
                flags = MeshKey::KF_StrokeHinted;

            if ((ss.Flags & StrokeScaling_Mask) == StrokeScaling_Normal)
                flags |= MeshKey::KF_NormalStroke;
        }
    }

    if (!validKey)
        flags |= MeshKey::KF_Degenerate;

    if (GetMeshProvider()->HasGradientMorph())
        flags |= MeshKey::KF_GradientMorph;

    keyData[MeshKey::GetKeySize(flags) - 1] = morphRatio;
    return flags;
}

// Points pMeshKey at a key (and mesh) for viewMatrix, creating them as needed; true if the key changed.
// @0x1426358f0
// MS2-FUNCTIONAL: code layout of the key/mesh creation differs
bool TreeCacheShapeLayer::updateMeshKey(Renderer2DImpl* r2D, ShapeMeshProvider* provider, float morphRatio,
                                        const Matrix2F& viewMatrix, unsigned meshGenFlags, unsigned* meshKeyFlags)
{
    float keyData[MeshKey::MaxKeySize];

    const ToleranceParams& cfg       = r2D->GetToleranceParams();
    unsigned               drawLayer = getLayer();
    unsigned               f2        = 0;
    if (meshGenFlags & Mesh_EdgeAA)
        f2 |= MeshKey::KF_EdgeAA;
    if (meshGenFlags & Mesh_Mask)
        f2 |= MeshKey::KF_Mask;

    Scale9GridData s9g;

    unsigned flags = calcMeshKey(provider, viewMatrix, drawLayer, keyData, &s9g, morphRatio) | f2;
    if (meshKeyFlags)
        *meshKeyFlags = flags;

    MeshKeyManager* keyManager = r2D->GetMeshKeyManager();
    MeshKey*        newKey;

    if (pMeshKey)
    {
        if (pMeshKey->Match(drawLayer, flags, keyData, cfg))
            return false;
        newKey = keyManager->CreateMatchingKey(pMeshKey->GetKeySet(), drawLayer, flags, keyData, cfg);
    }
    else
    {
        newKey = keyManager->CreateMatchingKey(provider, drawLayer, flags, keyData, cfg);
    }

    if (!newKey)
        return false;

    if (!newKey->pMesh)
    {
        if (ComplexShape)
        {
            newKey->pMesh = *SF_HEAP_AUTO_NEW(this) ComplexMesh(r2D, newKey->GetKeySet(),
                                                                &r2D->GetPrimitiveFillManager(), viewMatrix,
                                                                morphRatio, drawLayer, meshGenFlags);
        }
        else
        {
            newKey->pMesh = *SF_HEAP_AUTO_NEW(this)
                Mesh(r2D, newKey->GetKeySet(), viewMatrix, morphRatio, drawLayer, meshGenFlags);
        }

        if (!newKey->pMesh)
        {
            newKey->Release();
            return false;
        }

        if (flags & MeshKey::KF_Scale9Grid)
        {
            Ptr<Scale9GridData> p = *SF_HEAP_AUTO_NEW(this) Scale9GridData(s9g);
            newKey->pMesh->SetScale9Grid(p);
        }
    }

    pMeshKey = *newKey;
    return true;
}

// The 2D matrix to tessellate a 3D layer with: the one mapping the shape bounds onto their projected corners,
// degenerating to a uniform scale.
// @0x142635200
// MS2-FUNCTIONAL: float scheduling / register allocation differ
void TreeCacheShapeLayer::getShapeMatrixFrom3D(const TreeShape::NodeData* nd, Matrix2F* mat,
                                               const Matrix4F& viewProj) const
{
    RectF bounds = nd->pMeshProvider->GetIdentityBounds();

    Matrix4F        m(viewProj, M.GetMatrix3D());
    const Viewport& vp = pRoot->GetNodeData()->VP;

    float coord[8];
    m.TransformHomogeneousAndScaleCorners(bounds, (float)vp.Width, (float)vp.Height, coord);
    mat->SetRectToParl(bounds.x1, bounds.y1, bounds.x2, bounds.y2, coord);

    if ((float)fabs(mat->GetDeterminant()) < 0.001f)
        *mat = Matrix2F::Scaling(mat->GetScale());

    unsigned strokeStyle = nd->pMeshProvider->GetLayerStroke(getLayer());
    if (strokeStyle)
    {
        float s = mat->GetScale();
        if (s < 0.05f)
            s = 0.05f;
        *mat = Matrix2F::Scaling(s);
    }
}

// @0x1426348b0
// MS2-FUNCTIONAL: the cullRect copy sits 8 bytes lower (exe keeps it 16-aligned)
void TreeCacheShapeLayer::UpdateTransform(const TreeNode::NodeData* nodeData, const TransformArgs& t,
                                          TransformFlags flags)
{
    RectF cullRect(t.CullRect);
    updateCulling(nodeData, t, &cullRect, (TransformFlags)(flags | TF_CullCxform));
    SortParentBounds = nodeData->AproxParentBounds;
    SetFlags(GetFlags() & ~NF_ExpandedBounds);

    ComputeFinalMatrix(t, flags);

    // the meshes depend on the matrix only
    if (!(flags & TF_Matrix))
        return;

    const TreeShape::NodeData* shapeNodeData = (const TreeShape::NodeData*)nodeData;
    Bundle*                    bundle        = GetBundle();
    if (!bundle)
        return;

    unsigned meshKeyFlags = 0;
    bool     updateMesh   = false;

    Matrix2F mat(NoInit);
    if ((flags & TF_Has3D) && pRoot)
        getShapeMatrixFrom3D(shapeNodeData, &mat, t.GetViewProj());
    else
        mat = t.Mat;

    if (updateMeshKey(pRenderer2D, shapeNodeData->pMeshProvider, shapeNodeData->MorphRatio, mat, calcMeshGenFlags(),
                      &meshKeyFlags))
    {
        updateMesh = true;
        if (shapeNodeData->MorphRatio != 0)
            updateTexture0Matrix();
    }

    // hinted strokes snap to whole pixels
    if (M.Has3D() == 0 && (meshKeyFlags & MeshKey::KF_KeyTypeMask) == MeshKey::KF_StrokeHinted)
    {
        Matrix2F m2 = t.Mat;
        m2.Tx()     = floorf(m2.Tx() + ((m2.Tx() < 0) ? -0.5f : +0.5f));
        m2.Ty()     = floorf(m2.Ty() + ((m2.Ty() < 0) ? -0.5f : +0.5f));
        M.SetMatrix2D(m2);
    }

    if (updateMesh)
        bundle->UpdateMesh(&SorterShapeNode);
}

// The mesh for the bundle to draw, built on first use.
// @0x142633af0
MeshBase* TreeCacheShapeLayer::GetMesh()
{
    if (pRoot && (!pMeshKey || !pMeshKey->pMesh))
    {
        Matrix2F mat(NoInit);
        unsigned meshGenFlags = calcMeshGenFlags();

        if (M.Has3D())
        {
            Matrix4F viewProj = GetViewProj();
            getShapeMatrixFrom3D(GetShapeNodeData(), &mat, viewProj);
        }
        else
            mat = M.GetMatrix2D();

        updateMeshKey(pRenderer2D, GetMeshProvider(), GetMorphRatio(), mat, meshGenFlags);

        // only a simple shape has a fill texture
        if (!ComplexShape && SorterShapeNode.pBundle)
        {
            PrimitiveFill* fill    = ((PrimitiveBundle*)SorterShapeNode.pBundle.GetPtr())->GetFill();
            Texture*       texture = fill->GetTexture(0);
            if (texture)
            {
                Matrix2F tm;
                GetMeshProvider()->GetFillMatrix(pMeshKey->pMesh, &tm, getLayer(), 0, meshGenFlags);
                M.SetTextureMatrix(tm, 0);
            }
        }
    }

    return pMeshKey ? pMeshKey->pMesh.GetPtr() : 0;
}

// @0x142634500
void TreeCacheShapeLayer::RemoveMesh()
{
    pMeshKey = 0;
}

// @0x142635650
void TreeCacheShapeLayer::propagateMaskFlag(unsigned partOfMask)
{
    unsigned newFlags = (GetFlags() & ~NF_PartOfMask) | partOfMask;
    if (newFlags != GetFlags())
    {
        SetFlags(newFlags);
        updateSortKey();
    }
}

// @0x142635670
void TreeCacheShapeLayer::propagateScale9Flag(unsigned partOfScale9)
{
    // the scale9 flag goes to GetFillData, so it is part of the key
    if (GetNode() && GetNodeData()->GetState<Scale9State>())
        partOfScale9 |= NF_PartOfScale9;
    unsigned newFlags = (GetFlags() & ~NF_PartOfScale9) | partOfScale9;
    if (newFlags != GetFlags())
    {
        SetFlags(newFlags);
        updateSortKey();
    }
}

// @0x1426355c0
void TreeCacheShapeLayer::propagateEdgeAA(EdgeAAMode parentEdgeAA)
{
    EdgeAAMode edgeAA = parentEdgeAA;
    if (GetNode())
        edgeAA = TreeCacheNode::CalcEdgeAAMode(GetNodeData(), parentEdgeAA);
    if ((GetFlags() & NF_EdgeAA_Mask) != (unsigned)edgeAA)
    {
        SetFlags((GetFlags() & ~NF_EdgeAA_Mask) | edgeAA);
        updateSortKey();
    }
}

// the 3D bundles have their own keys
// @0x1426355b0
void TreeCacheShapeLayer::propagate3DFlag(unsigned)
{
    updateSortKey();
}

}} // namespace Scaleform::Render

// @0x142633210 TreeNode::NodeData(NonlocalCloneArg) and @0x142633300 TreeShape::NodeData(NonlocalCloneArg) come
// from the headers; @0x142634cc0 is TreeCacheShapeLayer::calcMeshGenFlags (folded with TreeCacheText's).
// MS2-PIN: ??_7TreeCacheShape@Render@Scaleform@@6B@ 0x14318f440
// MS2-PIN: ??_7TreeCacheShapeLayer@Render@Scaleform@@6B@ 0x14318f4a8
// MS2-PIN: ??_7NodeData@TreeShape@Render@Scaleform@@6B@ 0x14317bc40
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeShape@Render@Scaleform@@V1TreeNode@34@@ContextImpl@Render@Scaleform@@6B@ 0x14317bbf0
// MS2-PIN: ??_7Scale9GridData@Render@Scaleform@@6B@ 0x14318f438
// MS2-PIN: ??_GTreeCacheShape@Render@Scaleform@@UEAAPEAXI@Z 0x1426335f0
// MS2-PIN: ??_7NodeData@TreeNode@Render@Scaleform@@6B@ 0x14317b700
// MS2-PIN: ??_7EntryData@ContextImpl@Render@Scaleform@@6B@ 0x14317b6d0
// MS2-PIN: ??_7TreeCacheContainer@Render@Scaleform@@6B@ 0x14318ebc8
// MS2-PIN: ??_7?$RefCountBase@VScale9GridData@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f430
