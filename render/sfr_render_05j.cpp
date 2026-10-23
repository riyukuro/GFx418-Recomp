// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the cache node TU
// (Render_TreeCacheNode): the render-thread mirror of the TreeNode tree. TreeCacheNode (parent / mask links, the
// flags pushed down a subtree, culling, mask and filter bounds), TreeCacheContainer (child pattern building,
// transform and change propagation), TreeCacheRoot (the update lists by depth, Draw) and TreeCacheMeshBase.
// MS2-UNIT: sfr_render_05j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142680040-0x142681810 .text$mn
// MS2-RANGE: 0x142681840-0x142682420 .text$mn
// MS2-RANGE: 0x142682510-0x142685df0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7TreeCacheNode@Render@Scaleform@@6B@ 0x143191f50
// MS2-PIN: ??_7TreeCacheContainer@Render@Scaleform@@6B@ 0x14318ebc8
// MS2-PIN: ??_7TreeCacheMeshBase@Render@Scaleform@@6B@ 0x143191fb8

#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_cacheeffect.h"
#include "ms2/scaleform/include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include <math.h>
#include <string.h>

// the CRT printf the pattern check reports through
int FUN_140ccaae0(const char* fmt, ...);

namespace Scaleform { namespace Render {
class TreeCacheNode;
}}

// the node being updated, kept where a crash dump can find it
extern volatile const Scaleform::Render::TreeCacheNode*      TCN_This;
extern volatile const Scaleform::Render::TreeNode::NodeData* TCN_ThisData;
extern volatile const Scaleform::Render::TreeNode*           TCN_ChildNode;
// bumped once per pattern update pass
extern unsigned BundlePatternFrameId;
// child patterns built so far
extern unsigned BuildPatternCount;

namespace Scaleform { namespace Render {

// ***** TreeCacheNode

// @0x142680100
TreeCacheNode::TreeCacheNode(TreeNode* node, Renderer2DImpl* renderer2D, unsigned flags)
    : pRoot(0), pNode(node), pRenderer2D(renderer2D), pParent(0), pMask(0), Depth(0), Flags((UInt16)flags),
      UpdateFlags(Change_State_Effect_Mask), pNextUpdate(0)
{
    // no list links: the parent is not a container (yet)
    pPrev = pNext = 0;
}

// @0x142680280
TreeCacheNode::~TreeCacheNode()
{
    // leave the parent, which may still send changes here
    if (pPrev)
        RemoveNode();
    else if (pParent)
        pParent->ClearMask();

    // a mask moved along into an invisible subtree must not be left pointing back here
    if (pMask)
        pMask->RemoveFromParent();
}

// @0x142681540
HAL* TreeCacheNode::GetHAL() const
{
    return pRenderer2D->GetHAL();
}

// @0x142681800
PrimitiveFillManager& TreeCacheNode::GetPrimitiveFillManager() const
{
    return pRenderer2D->GetPrimitiveFillManager();
}

// @0x1426815d0
MatrixPoolImpl::MatrixPool& TreeCacheNode::GetMatrixPool() const
{
    return pRenderer2D->GetMatrixPool();
}

// @0x142682de0
void TreeCacheNode::UpdateInsertIntoParent(TreeCacheNode* parent, TreeCacheNode* insert,
                                           const TreeNode::NodeData* nodeData, UInt16 depth)
{
    TreeCacheNode* oldParent = GetParent();
    // a new parent, or the same one with the node moving between its children and its mask slot
    if (oldParent != parent || (insert && parent->GetMask() == this) || (!insert && parent->GetMask() != this))
    {
        if (oldParent)
        {
            RemoveFromParent();
            if (oldParent->pRoot && oldParent->IsPatternChainValid())
                oldParent->pRoot->AddToUpdate(oldParent, Update_Pattern);
        }

        if (insert)
            insert->InsertNodeAfter(this);
        // shape layers have no node data
        if (nodeData)
        {
            if (nodeData->IsMaskNode())
            {
                // the parent's previous mask goes
                if (parent->GetMask() && parent->GetMask() != this)
                    parent->GetMask()->RemoveFromParent();
                parent->SetMask(this);
                SetFlags(GetFlags() | NF_MaskNode);
                propagateMaskFlag(NF_PartOfMask);
            }

            unsigned scale9 = parent->GetFlags() & NF_PartOfScale9;
            if (nodeData->GetState<Scale9State>())
                scale9 = NF_PartOfScale9;
            propagateScale9Flag(scale9);
            propagateEdgeAA((EdgeAAMode)(parent->GetFlags() & NF_EdgeAA_Mask));
        }
        SetParent(parent);
    }

    // the depth is kept without a root too, so cached bounds still propagate
    Depth = depth;
    pRoot = parent->pRoot;
    // containers build their children here
    UpdateChildSubtree(nodeData, depth + 1);
}

// @0x142682660
void TreeCacheNode::RemoveFromParent()
{
    if (pPrev)
        RemoveNode();
    else if (pParent)
    {
        pParent->ClearMask();
        SetFlags(GetFlags() & ~NF_MaskNode);
    }
    pNext = pPrev = 0;
    pParent = 0;
    Depth   = 0;

    if (GetFlags() & NF_PartOfMask)
        propagateMaskFlag(0);
    if (GetFlags() & NF_PartOfScale9)
        propagateScale9Flag(0);

    // no root below here: matrix, color and pattern updates stop
    HandleRemoveNode();
}

// @0x1426820d0
void TreeCacheNode::HandleRemoveNode()
{
    pRoot = 0;
    if (HasMask())
        GetMask()->HandleRemoveNode();
}

// @0x142682c70
void TreeCacheNode::UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth)
{
    // a mask node's subtree is part of a mask
    unsigned newFlags = (GetFlags() & ~NF_PartOfMask) | ((GetFlags() << 1) & NF_PartOfMask);
    if (data->GetState<Scale9State>())
        newFlags |= NF_PartOfScale9;
    if (GetParent())
        newFlags |= GetParent()->GetFlags() & (NF_PartOfMask | NF_PartOfScale9);
    if (data->Is3D())
        newFlags |= NF_3D;
    SetFlags(newFlags);

    updateMaskCache(data, depth, true);
}

// @0x142685a80
void TreeCacheNode::updateMaskCache(const TreeNode::NodeData* data, UInt16 depth, bool updateSubtree)
{
    TCN_This     = this;
    TCN_ThisData = data;

    if (data->HasMask())
    {
        TreeNode* maskNode = data->GetState<MaskNodeState>()->GetNode();
        TCN_ChildNode      = maskNode;

        if (updateSubtree)
        {
            // the plain root / depth refresh of UpdateChildSubtree
            maskNode->GetDisplayData()->updateCache(this, 0, maskNode, depth);
        }
        else
        {
            // the mask state changed
            TreeCacheNode* newMask = (TreeCacheNode*)maskNode->GetRenderData();
            if (newMask != GetMask() || !GetMask())
            {
                // replaces (removes) the old mask
                maskNode->GetDisplayData()->updateCache(this, 0, maskNode, depth);
                goto update_on_mask_change;
            }
        }
    }
    else if (HasMask())
    {
        GetMask()->RemoveFromParent();

    update_on_mask_change:
        if (pRoot && IsPatternChainValid())
            pRoot->AddToUpdate(this, Update_Pattern);
    }
}

// @0x142685c00
void TreeCacheNode::updateMaskTransform(TransformArgs& t, TransformFlags flags)
{
    if (HasMask())
    {
        const TreeNode::NodeData* data = GetMask()->GetNodeData();
        if (!(flags & TF_Has3D))
            t.Mat.Prepend(data->M2D());
        else
            t.PrependMatrix3D(data->M3D());
        GetMask()->UpdateTransform(data, t, flags);
    }
}

// MS2-FUNCTIONAL: the exe passes no flags to the mask's GetPatternChain (r8 left holding the mask pointer)
// @0x142685a10
void TreeCacheNode::updateEffectChain(BundleEntryRange* contentChain)
{
    if (HasMask())
    {
        BundleEntryRange maskPattern(Range_Empty);
        GetMask()->GetPatternChain(&maskPattern, 0);
        Effects.UpdateBundleChain(contentChain, &maskPattern);
    }
    else
        Effects.UpdateBundleChain(contentChain, 0);
}

void TreeCacheNode::propagateMaskFlag(unsigned partOfMask)
{
    ApplyFlags(NF_PartOfMask, partOfMask);
}

// @0x142685190
void TreeCacheNode::propagateScale9Flag(unsigned partOfScale9)
{
    if (GetNodeData()->GetState<Scale9State>())
        partOfScale9 |= NF_PartOfScale9;
    ApplyFlags(NF_PartOfScale9, partOfScale9);
}

// @0x142684fc0
void TreeCacheNode::propagateEdgeAA(EdgeAAMode parentEdgeAA)
{
    EdgeAAMode edgeAA = CalcEdgeAAMode(GetNodeData(), parentEdgeAA);
    ApplyFlags(NF_EdgeAA_Mask, edgeAA);
}

// only the node made 3D itself carries the flag
void TreeCacheNode::propagate3DFlag(unsigned)
{
}

// a mask's pattern is built by the owner, which knows the chain
void TreeCacheNode::UpdateBundlePattern(unsigned)
{
}

bool TreeCacheNode::GetPatternChain(BundleEntryRange*, unsigned)
{
    return false;
}

void TreeCacheNode::forceUpdateImages()
{
}

static inline RectF EnclosedBounds(const Matrix2F& m, const RectF& r)
{
    RectF result(RectF::NoInit);
    m.EncloseTransform(&result, r);
    return result;
}

// the bounds of a child's mask in our space (in 3D, the whole viewport); false for an invisible or empty mask
// @0x142683c80
bool TreeCacheNode::calcChildMaskBounds(RectF* bounds, TreeCacheNode* child)
{
    TreeCacheNode*            maskCache = child->pMask;
    const TreeNode::NodeData* maskData  = maskCache->GetNodeData();
    if (!maskData->IsVisible() || maskData->AproxParentBounds.IsEmpty())
        return false;

    // anything 3D up the tree: the bounds are not meaningful, use the viewport
    bool           has3d  = maskData->Is3D();
    TreeCacheNode* parent = this;
    while (parent && !has3d)
    {
        has3d |= parent->GetNodeData()->Is3D();
        parent = parent->GetParent();
    }

    if (has3d)
    {
        const Viewport& vp = pRoot->GetNodeData()->VP;
        RectF           clipSpace(-1, -1, 1, 1);
        switch (vp.Flags & Viewport::View_Orientation_Mask)
        {
        default:
            *bounds = Viewport::ScaleToViewport(vp.Left, vp.Top, vp.Width, vp.Height, clipSpace);
            break;
        case Viewport::View_Orientation_L90:
        case Viewport::View_Orientation_R90:
            *bounds = Viewport::ScaleToViewport(vp.Left, vp.Top, vp.Height, vp.Width, clipSpace);
            break;
        }
        return true;
    }

    const TreeNode::NodeData* childData = child->GetNodeData();

    // the mask's matrix into our space: a sibling's is fine as is, a child's mask goes through the child
    Matrix2F m(maskData->M2D());
    if (maskCache->GetParent() != this)
    {
        if (maskCache->GetParent() == child)
            m.Append(childData->M2D());
        else
        {
            maskCache->CalcViewMatrix(&m);
            Matrix2F view;
            CalcViewMatrix(&view);
            m.Append(view);
        }
    }

    *bounds = EnclosedBounds(m, maskData->AproxLocalBounds);
    return true;
}

// @0x142680c40
void TreeCacheNode::CalcViewMatrix(Matrix2F* view) const
{
    const TreeCacheNode* p = this;
    *view = GetNodeData()->M2D();
    while (p->GetParent())
    {
        p = p->GetParent();
        view->Append(p->GetNodeData()->M2D());
    }
}

// @0x142680d30
void TreeCacheNode::CalcViewMatrix(Matrix3F* view, Matrix4F* viewProj) const
{
    const TreeNode::NodeData* data = GetNode() ? GetNodeData() : 0;

    // the node's own view / projection, else the nearest ancestor's
    const ViewMatrix3DState* viewState =
        data && data->HasViewMatrix3D() ? data->GetState<ViewMatrix3DState>() : 0;
    const ProjectionMatrix3DState* projState =
        data && data->HasProjectionMatrix3D() ? data->GetState<ProjectionMatrix3DState>() : 0;

    const TreeCacheNode* p = this;
    *view = data->M3D();
    while (p->GetParent())
    {
        p = p->GetParent();
        view->Append(p->GetNodeData()->M3D());

        if (!viewState && p->GetNodeData()->HasViewMatrix3D())
            viewState = p->GetNodeData()->GetState<ViewMatrix3DState>();
        if (!projState && p->GetNodeData()->HasProjectionMatrix3D())
            projState = p->GetNodeData()->GetState<ProjectionMatrix3DState>();
    }

    if (viewState && projState)
        *viewProj = Matrix4F(Matrix4F(projState->GetProjectionMatrix3D()->M),
                             Matrix3F(viewState->GetViewMatrix3D()->M));
    else
        // a renderer-only tree need not have a view-projection
        *viewProj = Matrix4F::Identity;
}

// @0x142680bd0
bool TreeCacheNode::CalcFilterFlag() const
{
    const TreeCacheNode* p = this;
    while (p->GetParent())
    {
        if (p->GetNodeData()->HasFilter())
            return true;
        p = p->GetParent();
    }
    return false;
}

// the nearest view and projection states up the tree; walking every ancestor, so TransformArgs::GetViewProj is
// the cheaper route
// @0x142681990
Matrix4F TreeCacheNode::GetViewProj() const
{
    const TreeNode::NodeData* data = GetNode() ? GetNodeData() : 0;

    const ViewMatrix3DState* viewState =
        data && data->HasViewMatrix3D() ? data->GetState<ViewMatrix3DState>() : 0;
    const ProjectionMatrix3DState* projState =
        data && data->HasProjectionMatrix3D() ? data->GetState<ProjectionMatrix3DState>() : 0;

    const TreeCacheNode* p = this;
    while (p->GetParent() && !(viewState && projState))
    {
        p = p->GetParent();
        if (!viewState && p->GetNodeData()->HasViewMatrix3D())
            viewState = p->GetNodeData()->GetState<ViewMatrix3DState>();
        if (!projState && p->GetNodeData()->HasProjectionMatrix3D())
            projState = p->GetNodeData()->GetState<ProjectionMatrix3DState>();
    }

    if (viewState && projState)
        return Matrix4F(Matrix4F(projState->GetProjectionMatrix3D()->M), Matrix3F(viewState->GetViewMatrix3D()->M));
    return Matrix4F::Identity;
}

// clip-space bounds of inputBounds under viewproj * viewMatrix, in pixels of the viewport (its sides swapped for
// a rotated orientation when orient is set)
// @0x142682760
RectF TransformBounds3D(const Matrix4F& viewproj, const Viewport& vp, const Matrix3F& viewMatrix,
                        const RectF& inputBounds, bool orient = false)
{
    RectF    clipBounds;
    Matrix4F wvp(viewproj, viewMatrix);
    wvp.EncloseTransformHomogeneous(&clipBounds, inputBounds);
    switch (vp.Flags & Viewport::View_Orientation_Mask)
    {
    default:
        break;
    case Viewport::View_Orientation_L90:
    case Viewport::View_Orientation_R90:
        if (orient)
            return Viewport::ScaleToViewport(0, 0, vp.Height, vp.Width, clipBounds);
        break;
    }
    return Viewport::ScaleToViewport(0, 0, vp.Width, vp.Height, clipBounds);
}

// noinline: TreeCacheRoot::HandleChanges calls it out of line.
// @0x1426814b0
__declspec(noinline) bool Viewport::GetCullRectF(RectF* prect, bool orient) const
{
    Rect<int> clipRect;
    if (!GetClippedRect(&clipRect, orient))
        return false;
    prect->SetRect((float)(clipRect.x1 - Left), (float)(clipRect.y1 - Top), (float)(clipRect.x2 - Left),
                   (float)(clipRect.y2 - Top));
    return true;
}

// widens twips bounds to whole pixels plus half a pixel each side
// @0x1426826f0
void SnapRectToPixels(RectF& rect)
{
    rect.x1 = floorf(rect.x1 - 10.0f);
    rect.y1 = floorf(rect.y1 - 10.0f);
    rect.x2 = ceilf(rect.x2 + 10.0f);
    rect.y2 = ceilf(rect.y2 + 10.0f);
}

// the pixel area a filter on this node renders into: its view bounds kept inside the cull rectangle (grown by the
// filter's reach, at most 32 pixels), returned as a matrix over the unit square; false when nothing is left.
// bounds gets the local bounds in 2D only.
// MS2-FUNCTIONAL: same code, the exe keeps cullRect and the node data in other saved registers
// @0x142683f80
bool TreeCacheNode::calcFilterBounds(RectF* bounds, Matrix2F* boundAreaMatrix, const Matrix3F& viewMatrix,
                                     const Matrix4F& viewProj, RectF* cullRect)
{
    const TreeNode::NodeData* data = GetNodeData();
    if (!pRoot)
        return false;

    bool           has3d  = data->Is3D();
    TreeCacheNode* parent = this;
    while (parent && !has3d)
    {
        has3d |= parent->GetNodeData()->Is3D();
        parent = parent->GetParent();
    }

    RectF cullRectTemp, viewClipRect;
    if (!has3d)
    {
        Matrix2F view2D;
        memcpy(view2D.M, viewMatrix.M, sizeof(view2D.M));   // its top two rows
        *bounds = data->AproxLocalBounds;
        view2D.EncloseTransform(&viewClipRect, *bounds);
    }
    else
        viewClipRect = TransformBounds3D(viewProj, pRoot->GetNodeData()->VP, viewMatrix, data->AproxLocalBounds);

    // no cull rectangle given: the visible view
    const Viewport& vp = pRoot->GetNodeData()->VP;
    {
        Rect<int> visible;
        if (vp.GetClippedRect(&visible, true))
            cullRectTemp.SetRect((float)(visible.x1 - vp.Left), (float)(visible.y1 - vp.Top),
                                 (float)(visible.x2 - vp.Left), (float)(visible.y2 - vp.Top));
    }
    if (!cullRect)
        cullRect = &cullRectTemp;
    RectF orientCullRect = *cullRect;
    switch (vp.Flags & Viewport::View_Orientation_Mask)
    {
    case Viewport::View_Orientation_L90:
    case Viewport::View_Orientation_R90:
        orientCullRect.SetRect(cullRectTemp.y1, cullRectTemp.x1, cullRectTemp.y2, cullRectTemp.x2);
        break;
    }

    RectF expandedCullRect = orientCullRect;
    data->expandByFilterBounds(&expandedCullRect, false);
    RectF limitRect = orientCullRect;
    limitRect.Expand(32.0f, 32.0f);
    expandedCullRect.IntersectRect(&expandedCullRect, limitRect);

    RectF area(RectF::NoInit);
    if (!expandedCullRect.IntersectRect(&area, viewClipRect))
        return false;
    float x1 = floorf(area.x1), y1 = floorf(area.y1);
    float x2 = ceilf(area.x2), y2 = ceilf(area.y2);
    boundAreaMatrix->SetMatrix(x2 - x1, 0, x1, 0, y2 - y1, y1);
    return true;
}

// view pixel area outside the mask above which it clips instead of being drawn with its content, by the previous
// state (a lower bar to stay clipped, a higher one to stay combined)
static const float MaskClipAreasThresholds[] = { 23500.0f, 23500.0f, 17000.0f, 30000.0f };

// how the mask of this node applies: culled when it misses the content, else clipped to their overlap (a large
// uncovered area, no filter above) or combined over their union. bounds gets the mask bounds, boundAreaMatrix the
// area to clear as a matrix over the unit square.
// MS2-FUNCTIONAL: same code, the exe allocates the bounds registers and stack slots differently
// @0x142684500
MaskEffectState TreeCacheNode::calcMaskBounds(RectF* bounds, Matrix2F* boundAreaMatrix, const Matrix3F& viewMatrix,
                                              const Matrix4F& viewProj, MaskEffectState oldState, unsigned flags)
{
    const TreeNode::NodeData* data     = GetNodeData();
    const TreeNode::NodeData* maskData = GetMask()->GetNodeData();
    if (!maskData->IsVisible() || !pRoot)
        return MES_NoMask;

    bool           has3d  = maskData->Is3D();
    TreeCacheNode* parent = this;
    while (parent && !has3d)
    {
        has3d |= parent->GetNodeData()->Is3D();
        parent = parent->GetParent();
    }

    if (!has3d)
    {
        Matrix2F view2D;
        memcpy(view2D.M, viewMatrix.M, sizeof(view2D.M));   // its top two rows

        // the mask in our space
        Matrix2F m(maskData->M2D());
        *bounds = EnclosedBounds(m, maskData->AproxLocalBounds);

        RectF intersect, boundsUnion;
        if (!bounds->IntersectRect(&intersect, data->AproxLocalBounds))
            return MES_Culled;
        bounds->UnionRect(&boundsUnion, data->AproxLocalBounds);
        SnapRectToPixels(boundsUnion);

        RectF viewUnionBounds = EnclosedBounds(view2D, boundsUnion);
        float fraction        = (intersect.Width() * intersect.Height()) / (boundsUnion.Width() * boundsUnion.Height());
        float viewArea        = viewUnionBounds.Width() * viewUnionBounds.Height();
        float uncoveredArea   = viewArea * (1.0f - fraction);

        if (uncoveredArea > MaskClipAreasThresholds[oldState] && (flags & TF_ParentFilter) == 0)
        {
            // the overlap in view pixels (the matrix keeps no rotation, so a unit square clears it exactly)
            RectF viewClipRect;
            viewMatrix.EncloseTransform(&viewClipRect, intersect);
            SnapRectToPixels(viewClipRect);
            boundAreaMatrix->SetMatrix(viewClipRect.Width(), 0, viewClipRect.x1, 0, viewClipRect.Height(),
                                       viewClipRect.y1);
            return MES_Clipped;
        }

        // the whole union, cleared in local space
        boundAreaMatrix->SetMatrix(boundsUnion.Width(), 0, boundsUnion.x1, 0, boundsUnion.Height(), boundsUnion.y1);
        boundAreaMatrix->Append(view2D);
        return MES_Combinable;
    }

    // 3D: both in viewport pixels, the view and projection from the root
    Matrix4F maskViewProj;
    Matrix3F maskView;
    GetMask()->CalcViewMatrix(&maskView, &maskViewProj);
    const Viewport& vp            = pRoot->GetNodeData()->VP;
    *bounds                       = TransformBounds3D(maskViewProj, vp, maskView, maskData->AproxLocalBounds);
    RectF           contentBounds = TransformBounds3D(viewProj, vp, viewMatrix, data->AproxLocalBounds);

    RectF intersect;
    if (!bounds->IntersectRect(&intersect, contentBounds))
        return MES_Culled;
    *bounds = bounds->Union(contentBounds);

    RectF viewClipRect = *bounds;
    SnapRectToPixels(viewClipRect);
    boundAreaMatrix->SetMatrix(viewClipRect.Width(), 0, viewClipRect.x1, 0, viewClipRect.Height(), viewClipRect.y1);
    return MES_Combinable;
}

// Mask bounds narrow cullRect (and update the mask effect), the filter effect follows the node's matrix and color
// transform, and the node is culled when transparent or outside cullRect; a culled node clears TF_NeedCull for
// its children. 4.1.18 has no 3D culling exception: a 3D node outside the view stays culled.
// MS2-FUNCTIONAL: same code, the exe calls GetMatrix3D and TransformBounds3D out of line in the 3D view cull
// @0x142685210
TransformFlags TreeCacheNode::updateCulling(const TreeNode::NodeData* data, const TransformArgs& t, RectF* cullRect,
                                            TransformFlags flags)
{
    bool culled = false;
    bool is3d   = (flags & TF_Has3D) != 0;
    if (flags & TF_NeedCull)
    {
        RectF    bounds;
        Matrix3F m3(Matrix3F::NoInit);
        if (HasMask() || data->HasFilter())
            t.GetMatrix3D(flags, &m3);

        if (HasMask())
        {
            Matrix2F        maskAreaMatrix;
            MaskEffect*     maskEffect = (MaskEffect*)Effects.GetEffect(State_MaskNode);
            MaskEffectState mes;
            if (maskEffect)
            {
                mes = calcMaskBounds(&bounds, &maskAreaMatrix, m3, t.GetViewProj(), maskEffect->MES, flags);
                if (maskEffect->UpdateMatrix(mes, maskAreaMatrix))
                {
                    UpdateFlags |= Change_State_MaskNode;
                    addParentToDepthPatternUpdate();
                }
            }
            else
                mes = calcMaskBounds(&bounds, &maskAreaMatrix, m3, t.GetViewProj(), MES_NoMask, flags);

            if (mes != MES_NoMask)
            {
                if (mes == MES_Culled)
                    culled = true;
                else
                {
                    if (!is3d)
                        t.Mat.EncloseTransform(&bounds, bounds);
                    else
                        TransformBounds3D(t.GetViewProj(), pRoot->GetNodeData()->VP, m3, bounds);

                    // the mask bounds are not oriented: an oriented 3D view keeps the whole cullRect
                    if (!is3d || !(pRoot->GetNodeData()->VP.Flags & Viewport::View_Orientation_Mask))
                    {
                        if (!cullRect->IntersectRect(cullRect, bounds))
                            culled = true;
                    }
                }
            }
        }

        // the filter area and color transform follow the node's matrix and color changes
        if (data->HasFilter() && (flags & (TF_Matrix | TF_Cxform)))
        {
            Matrix2F      m;
            RectF         filterBounds;
            FilterEffect* filterEffect = (FilterEffect*)Effects.GetEffect(State_Filter);
            if (filterEffect && calcFilterBounds(&filterBounds, &m, m3, t.GetViewProj(), cullRect))
            {
                filterEffect->UpdateMatrix(m);
                Cxform cx = t.Cx;
                cx.Append(data->Cx);
                filterEffect->UpdateCxform(cx);
                filterEffect->Update(data->GetState<FilterState>());
            }
        }

        // under a filter: flag the ancestors up to the filtered one so its pattern is rebuilt
        if (flags & TF_ParentFilter)
        {
            TreeCacheNode* p = this;
            unsigned       marked;
            for (;;)
            {
                unsigned updateFlags = p->UpdateFlags;
                marked               = updateFlags & Change_State_Filter;
                TreeCacheNode* parent = p->GetParent();
                if (marked || !parent || parent->GetNodeData()->HasFilter())
                    break;
                p->UpdateFlags = updateFlags | Change_State_Filter;
                p              = parent;
            }
            if (!marked)
            {
                if (p->GetParent())
                    p->GetParent()->UpdateFlags |= Change_State_Filter | Update_Pattern;
                p->addParentToDepthPatternUpdate();
            }
        }

        // an (almost) transparent leaf is culled, unless it draws a mask
        if ((flags & TF_CullCxform) && !culled)
        {
            if (fabs((double)t.Cx.M[0][3]) < 0.001f && fabs((double)t.Cx.M[1][3]) < 1.0f / 255.0f &&
                !(GetFlags() & NF_PartOfMask))
                culled = true;
        }

        if (!culled && pRoot)
        {
            if (!is3d)
            {
                t.Mat.EncloseTransform(&bounds, data->AproxLocalBounds);
                if (!cullRect->Intersects(bounds))
                    culled = true;
            }
            else
            {
                Matrix3F m3d(Matrix3F::NoInit);
                t.GetMatrix3D(flags, &m3d);
                RectF viewportBounds =
                    TransformBounds3D(t.GetViewProj(), pRoot->GetNodeData()->VP, m3d, data->AproxLocalBounds, true);
                if (!cullRect->Intersects(viewportBounds))
                    culled = true;
            }
        }
    }

    // no culling while the view is rotated
    if (pRoot && (pRoot->GetNodeData()->VP.Flags & Viewport::View_Orientation_Mask))
        culled = false;

    // the root always draws (the stage color)
    if (culled && this != pRoot)
    {
        if (!(GetFlags() & NF_Culled))
        {
            SetFlags(GetFlags() | NF_Culled);
            addParentToDepthPatternUpdate();
        }
        flags = (TransformFlags)(flags & ~TF_NeedCull);
    }
    else if (GetFlags() & NF_Culled)
    {
        SetFlags(GetFlags() & ~NF_Culled);
        addParentToDepthPatternUpdate();
    }

    if (HasMask())
    {
        if (!(flags & TF_Has3D))
        {
            TransformArgs args(t, t.Mat);
            updateMaskTransform(args, flags);
        }
        else
        {
            Matrix3F m3(Matrix3F::NoInit);
            t.GetMatrix3D(flags, &m3);
            TransformArgs args(t, m3);
            args.Mat = Matrix2F::Identity;
            updateMaskTransform(args, flags);
        }
    }
    return flags;
}

// ***** The child bounds a pattern merge must not overlap

// a stack array of 32 items that moves to the heap when it outgrows them (temporary storage only)
template<class C>
class FixedSizeArray
{
protected:
    enum { DefSize = 32 };
    UByte DataReserve[sizeof(C) * DefSize + 16];   // 16-aligned inside
    UPInt Size;
    UPInt Reserve;
    C*    pData;

    C* reserveData() { return (C*)(((UPInt)DataReserve + 15) & ~(UPInt)15); }

    bool grow(UPInt reserve)
    {
        UPInt newReserve = (reserve + DefSize - 1) & ~(UPInt)(DefSize - 1);
        C*    p          = (C*)SF_MEMALIGN(newReserve * sizeof(C), 16, Stat_Default_Mem);
        if (!p)
            return false;
        memcpy(p, pData, Size * sizeof(C));
        if (pData != reserveData())
            SF_FREE(pData);
        pData   = p;
        Reserve = newReserve;
        return true;
    }

public:
    FixedSizeArray() : Size(0), Reserve(DefSize) { pData = reserveData(); }
    ~FixedSizeArray()
    {
        Clear();
        if (pData != reserveData())
            SF_FREE(pData);
    }

    UPInt    GetSize() const          { return Size; }
    C&       operator[](UPInt i)       { return pData[i]; }
    const C& operator[](UPInt i) const { return pData[i]; }
    void     Clear()                  { Size = 0; }
};

// two rectangles per item, as (x1, y1) pairs and (x2, y2) pairs, so one SSE compare tests both
struct Rect2F
{
    __m128 r0;
    __m128 r1;
};

class FixedSizeArrayRect2F : private FixedSizeArray<Rect2F>
{
    bool HalfRect;   // the last item holds one rectangle

public:
    FixedSizeArrayRect2F() : HalfRect(false) {}
    void PushBack(const RectF& r);
    bool Intersects(const RectF& bounds);
    void Clear()
    {
        FixedSizeArray<Rect2F>::Clear();
        HalfRect = false;
    }
};

// @0x142682510
void FixedSizeArrayRect2F::PushBack(const RectF& r)
{
    if (HalfRect)
    {
        // the second slot of the last item
        Rect2F& t  = pData[Size - 1];
        __m128  rv = _mm_loadu_ps(&r.x1);
        t.r0       = _mm_shuffle_ps(t.r0, rv, _MM_SHUFFLE(1, 0, 1, 0));
        t.r1       = _mm_shuffle_ps(t.r1, rv, _MM_SHUFFLE(3, 2, 1, 0));
        HalfRect   = false;
    }
    else
    {
        // doubling is fine for temporary storage
        if (Size == Reserve)
            grow(Size * 2);
        Rect2F& t = pData[Size];
        Size++;

        __m128 rv = _mm_loadu_ps(&r.x1);
        t.r0      = _mm_shuffle_ps(rv, t.r0, _MM_SHUFFLE(3, 2, 1, 0));
        t.r1      = _mm_shuffle_ps(rv, t.r1, _MM_SHUFFLE(3, 2, 3, 2));
        HalfRect  = true;
    }
}

// true when bounds overlaps any stored rectangle (touching edges do not count)
// MS2-FUNCTIONAL: the init-guard epoch sits at another thread-local offset in the exe (4, here 0)
// @0x142682170
bool FixedSizeArrayRect2F::Intersects(const RectF& bounds)
{
    if (bounds.IsEmpty())
        return false;

    static __m128 zero    = SIMD::Constant<0, 0, 0, 0>();
    static __m128 lowHalf = SIMD::Constant<0xFFFFFFFF, 0xFFFFFFFF, 0, 0>();
    static __m128 highHalf = SIMD::Constant<0, 0, 0xFFFFFFFF, 0xFFFFFFFF>();

    __m128 b      = _mm_loadu_ps(&bounds.x1);
    __m128 bTopLeft  = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 0, 1, 0));
    __m128 bBotRight = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 2, 3, 2));

    UPInt i     = 0;
    UPInt count = GetSize();
    if (HalfRect)
        count--;

    for (; i < count; i++)
    {
        Rect2F* pr = &operator[](i);
        // apart when a top-left reaches past the other's bottom-right
        __m128 apart = _mm_or_ps(_mm_cmple_ps(bBotRight, pr->r0), _mm_cmple_ps(pr->r1, bTopLeft));
        if ((_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(apart, lowHalf), zero)) & 0xF) == 0xF ||
            (_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(apart, highHalf), zero)) & 0xF) == 0xF)
            return true;
    }

    if (HalfRect)
    {
        Rect2F* pr    = &operator[](i);
        __m128  apart = _mm_or_ps(_mm_cmple_ps(bBotRight, pr->r0), _mm_cmple_ps(pr->r1, bTopLeft));
        if ((_mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(apart, lowHalf), zero)) & 0xF) == 0xF)
            return true;
    }
    return false;
}

// ***** TreeCacheContainer

// @0x142680150
TreeCacheContainer::~TreeCacheContainer()
{
    // the children that outlive us lose their parent, and their subtree its root
    TreeCacheNode* p = Children.GetFirst();
    while (!Children.IsNull(p))
    {
        TreeCacheNode* next = p->pNext;
        p->SetParent(0);
        p->pPrev = p->pNext = 0;
        if (p->pRoot)
            p->HandleRemoveNode();
        p = next;
    }
}

// syncs the cached children with the node's child array after inserts/removals
// @0x142681c20
void TreeCacheContainer::HandleChanges(unsigned changeBits)
{
    if (changeBits & Change_EdgeAAMode)
        propagateEdgeAA(CalcEdgeAAMode(GetNodeData(), GetParent()));

    if (!(changeBits & (Change_ChildInsert | Change_ChildRemove)))
        return;

    bool                  change     = false;
    const TreeContainer::NodeData* data = GetNodeData();
    UPInt                 childCount = data->Children.GetSize();
    unsigned              index;
    TreeCacheNode*        cached     = Children.GetFirst();

    for (index = 0; index < childCount; index++)
    {
        TreeNode*      node      = data->Children.GetAt(index);
        TreeCacheNode* nodeCache = node->GetRenderData();

        // in place already
        if (nodeCache == cached)
        {
            cached = cached->pNext;
            continue;
        }

        // ours and in the child list (masks are not, pPrev == 0): the cached entries before it went away or moved
        if (nodeCache && nodeCache->GetParent() == this && nodeCache->pPrev)
        {
            do
            {
                TreeCacheNode* next = cached->pNext;
                cached->RemoveFromParent();
                cached = next;
            } while (cached != nodeCache && !Children.IsNull(cached));

            change = true;
            // this index again, now as an insert
            index--;
            continue;
        }

        // moved here from elsewhere in the tree: detach it from the old parent first
        if (nodeCache && nodeCache->GetParent())
        {
            TreeCacheNode* oldParent = nodeCache->GetParent();
            nodeCache->RemoveFromParent();
            if (oldParent->pRoot)
                oldParent->pRoot->AddToUpdate(oldParent, Update_Pattern);
        }

        TreeCacheNode* inserted = node->GetDisplayData()->updateCache(this, cached->pPrev, node, Depth + 1);
        if (inserted && inserted->pRoot)
            inserted->pRoot->AddToUpdate(inserted, Change_Matrix | Change_CxForm);
        change = true;

        // the insert can (rarely) move our next cached child into its subtree: start over
        if (!Children.IsNull(cached) && cached->GetParent() != this)
        {
            cached = Children.GetFirst();
            index  = (unsigned)-1;
        }
    }

    // whatever is left has no node any more
    while (!Children.IsNull(cached))
    {
        TreeCacheNode* next = cached->pNext;
        cached->RemoveFromParent();
        cached = next;
        change = true;
    }

    if (change && IsPatternChainValid())
        pRoot->AddToUpdate(this, Update_Pattern);
}

// Culls the container, then hands each child the accumulated transform: 2D matrices append while the chain is
// 2D, a 3D child folds the 2D part into the 3D matrix. Under a contributing filter the children start from the
// identity color transform (the filter applies the parent's). The cache list is walked, not the data's children:
// while the tree is being destroyed some of those have no cache node.
// @0x142682f60
void TreeCacheContainer::UpdateTransform(const TreeNode::NodeData* data, const TransformArgs& t, TransformFlags flags)
{
    TransformArgs args(t);
    flags = updateCulling(data, t, &args.CullRect, flags);

    SortParentBounds = data->AproxParentBounds;
    SetFlags(GetFlags() & ~NF_ExpandedBounds);

    TreeCacheNode* child = Children.GetFirst();
    while (!Children.IsNull(child))
    {
        const TreeNode::NodeData* childData  = child->GetNodeData();
        TransformFlags            childFlags =
            (TransformFlags)(flags | (child->UpdateFlags & (Change_CxForm | Change_Matrix)));
        child->UpdateFlags &= ~(Change_Matrix | Change_CxForm);

        if (!childData->Is3D())
        {
            if (flags & TF_Has2D)
                args.Mat.SetToAppend(childData->M2D(), t.Mat);
            else
                args.Mat = childData->M2D();
            childFlags = (TransformFlags)(childFlags | TF_Has2D);
            if (flags & TF_Has3D)
                args.SetMatrix3D(t.GetMat3DDirect());
        }
        else
        {
            if (flags & TF_Has2D)
            {
                Matrix3F m3(Matrix3F::NoInit);
                t.GetMatrix3D(flags, &m3);
                args.SetMatrix3D(m3, childData->M3D());
                childFlags = (TransformFlags)(childFlags & ~TF_Has2D);
            }
            else if (flags & TF_Has3D)
            {
                Matrix3F m3(Matrix3F::NoInit);
                t.GetMatrix3D(flags, &m3);
                args.SetMatrix3D(m3, childData->M3D());
            }
            childFlags = (TransformFlags)(childFlags | TF_Has3D);
        }

        args.SetViewProj(childData, &t);

        bool accumulateCxform = true;
        if (data->HasFilter())
        {
            const FilterState* filterState = data->GetState<FilterState>();
            if (filterState)
            {
                const FilterSet* filters = filterState->GetFilters();
                if (filters && filters->IsContributing())
                    accumulateCxform = false;
            }
            childFlags = (TransformFlags)(childFlags | TF_ParentFilter);
        }
        if (accumulateCxform)
            args.Cx.SetToAppend(childData->Cx, t.Cx);
        else
            args.Cx.SetIdentity();

        child->UpdateTransform(childData, args, childFlags);
        child = child->pNext;
    }
}

// @0x142682050
void TreeCacheContainer::HandleRemoveNode()
{
    TreeCacheNode::HandleRemoveNode();
    CachedChildPattern.Clear(Range_Invalid);

    TreeCacheNode* p = Children.GetFirst();
    while (!Children.IsNull(p))
    {
        p->HandleRemoveNode();
        p = p->pNext;
    }
}

// @0x142682a70
void TreeCacheContainer::UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth)
{
    TreeCacheNode::UpdateChildSubtree(data, depth);

    // new children go in after the previous one
    TreeCacheNode*       insert   = Children.GetFirst()->pPrev;
    const TreeNodeArray& children = static_cast<const TreeContainer::NodeData*>(data)->Children;
    for (UPInt i = 0; i < children.GetSize(); i++)
    {
        TreeNode* child = children[i];
        insert          = child->GetDisplayData()->updateCache(this, insert, child, depth);
    }
}

// @0x142685040
void TreeCacheContainer::propagateMaskFlag(unsigned partOfMask)
{
    ApplyFlags(NF_PartOfMask, partOfMask);

    TreeCacheNode* child = Children.GetFirst();
    while (!Children.IsNull(child))
    {
        // a mask node's branch keeps its own state
        if (!child->IsMaskNode())
            child->propagateMaskFlag(partOfMask);
        child = child->pNext;
    }
}

// @0x1426850c0
void TreeCacheContainer::propagateScale9Flag(unsigned partOfScale9)
{
    if (GetNodeData()->GetState<Scale9State>())
        partOfScale9 |= NF_PartOfScale9;
    if ((GetFlags() & NF_PartOfScale9) == partOfScale9)
        return;
    ApplyFlags(NF_PartOfScale9, partOfScale9);

    TreeCacheNode* child = Children.GetFirst();
    while (!Children.IsNull(child))
    {
        child->propagateScale9Flag(partOfScale9);
        child = child->pNext;
    }
}

// @0x142684ef0
void TreeCacheContainer::propagateEdgeAA(EdgeAAMode parentEdgeAA)
{
    EdgeAAMode edgeAA = CalcEdgeAAMode(GetNodeData(), parentEdgeAA);
    if ((GetFlags() & NF_EdgeAA_Mask) == (unsigned)edgeAA)
        return;
    ApplyFlags(NF_EdgeAA_Mask, edgeAA);

    TreeCacheNode* child = Children.GetFirst();
    while (!Children.IsNull(child))
    {
        child->propagateEdgeAA(edgeAA);
        child = child->pNext;
    }
}

// @0x142684e70
void TreeCacheContainer::propagate3DFlag(unsigned parent3D)
{
    unsigned is3D = GetFlags() & NF_3D;
    // already 3D under a 3D parent: nothing changes below
    if (parent3D == NF_3D && is3D)
        return;
    parent3D |= is3D;

    TreeCacheNode* child = Children.GetFirst();
    while (!Children.IsNull(child))
    {
        child->propagate3DFlag(parent3D);
        child = child->pNext;
    }
}

// MS2-FUNCTIONAL: the exe passes no flags to the children's GetPatternChain (dropped argument) and keeps the child bounds in registers
// the children's chains in order; runs of children whose patterns match (and do not overlap an earlier member of
// the run) are merged so their entries chain into shared bundles
// @0x142680440
void TreeCacheContainer::BuildChildPattern(BundleEntryRange* pattern)
{
    FixedSizeArrayRect2F prevRects;

    pattern->Clear(Range_Empty);
    BundleEntryRangeMatcher prevPattern(Range_Empty);
    bool                    expandBounds = false;
    RectF                   expandedBounds;

    TreeCacheNode* child = Children.GetFirst();
    for (; !Children.IsNull(child); child = child->pNext)
    {
        BundleEntryRange childPattern(Range_Empty);
        if (!child->GetPatternChain(&childPattern, 0))
            continue;

        // long patterns are not matched
        if (childPattern.GetLength() > 8)
        {
            pattern->Append(prevPattern);
            pattern->Append(childPattern);
            prevPattern.Clear(Range_Empty);
            prevRects.Clear();
            continue;
        }

        RectF bounds;
        bool  match = false;
        if (child->pNode)
            bounds = child->SortParentBounds;

        // a mask widens what the child covers
        if (child->GetFlags() & (NF_ExpandedBounds | NF_HasMask))
        {
            if (child->HasMask())
            {
                RectF maskBounds;
                if (calcChildMaskBounds(&maskBounds, child))
                {
                    if (expandBounds)
                        expandedBounds = maskBounds;
                    else
                    {
                        expandBounds = true;
                        expandedBounds.UnionRect(&expandedBounds, maskBounds);
                    }
                    if (!bounds.IsEmpty())
                        bounds.UnionRect(&bounds, maskBounds);
                    else
                        bounds = maskBounds;
                }
            }

            if (expandBounds)
                expandedBounds = bounds;
            else
            {
                expandBounds = true;
                expandedBounds.UnionRect(&expandedBounds, bounds);
            }
        }

        if (!prevPattern.IsEmpty())
        {
            // overlaps are not tested in 3D (the 2D bounds say nothing there)
            bool matchNotAllowed = !(child->GetFlags() & NF_3D) && prevRects.Intersects(bounds);
            if (!matchNotAllowed)
                match = prevPattern.Match(childPattern);
            else if (prevPattern.GetLength() == 1 && childPattern.GetLength() == 1 &&
                     prevPattern.GetFirstKey().MatchSingleItemOverlap(childPattern.GetFirstKey()))
                // single entries with a key that allows it may overlap
                match = true;
        }

        if (match)
            prevPattern.MergeMatchingChains(childPattern, Depth);
        else
        {
            pattern->Append(prevPattern);
            prevPattern = childPattern;
            prevRects.Clear();
        }

        if (!bounds.IsEmpty())
            prevRects.PushBack(bounds);
    }

    pattern->Append(prevPattern);

    // sort by the widened bounds from now on
    if (expandBounds)
    {
        const TreeNode::NodeData* data = pNode->GetDisplayData();
        if (!data->AproxLocalBounds.IsEmpty())
            expandedBounds.UnionRect(&expandedBounds, data->AproxLocalBounds);
        data->M2D().EncloseTransform(&expandedBounds, expandedBounds);

        if (expandedBounds != SortParentBounds)
        {
            SortParentBounds = expandedBounds;
            SetFlags(GetFlags() | NF_ExpandedBounds);
        }
    }

    BuildPatternCount++;
}

// @0x142682870
void TreeCacheContainer::UpdateBundlePattern(unsigned flags)
{
    // invalid patterns are rebuilt top-down later
    if (!IsPatternChainValid())
        return;

    BundleEntryRange pattern(Range_Invalid);
    BuildChildPattern(&pattern);

    // the effect chain is always rebuilt: a child moved deeper gives the same pattern with stale links
    if (!Effects.IsEmpty() && !pattern.IsEmpty())
    {
        BundleEntryRange chain(pattern);
        updateEffectChain(&chain);
    }

    // hidden nodes contribute no bundles; the parent hears of visibility changes elsewhere
    if (IsDrawn())
    {
        if (CachedChildPattern.GetLength() <= 8 || pattern.GetLength() <= 8 ||
            CachedChildPattern.GetFirst() != pattern.GetFirst() || CachedChildPattern.GetLast() != pattern.GetLast())
        {
            addParentToDepthPatternUpdate();
        }
        else if (CachedChildPattern.GetLength() != pattern.GetLength())
        {
            // a long pattern changed length only (rare)
            if (GetParent() && GetParent()->IsPatternChainValid() &&
                !(GetParent()->UpdateFlags & Update_Pattern_Mask))
                addParentToDepthPatternUpdate();
        }
    }

    CachedChildPattern = pattern;
}

// @0x1426815e0
bool TreeCacheContainer::GetPatternChain(BundleEntryRange* range, unsigned flags)
{
    // hidden or culled: nothing for the parent
    if (!IsDrawn())
    {
        range->Clear(Range_Empty);
        return false;
    }

    bool     oldChainValid     = CachedChildPattern.IsValid();
    unsigned updateEffectsMask = UpdateFlags & Change_State_Effect_Mask;

    if (oldChainValid && !updateEffectsMask)
    {
        if (!CachedChildPattern.IsEmpty())
        {
            if (!Effects.GetRange(range))
                *range = CachedChildPattern;
            range->StripChainsByDepth(Depth);
        }
    }
    else
    {
        if (oldChainValid)
            CachedChildPattern.StripChainsByDepth(Depth);
        else
            BuildChildPattern(&CachedChildPattern);
        *range = CachedChildPattern;

        if (updateEffectsMask)
        {
            Effects.UpdateEffects(this, updateEffectsMask);
            UpdateFlags &= ~Change_State_Effect_Mask;
        }
        if (!CachedChildPattern.IsEmpty())
            updateEffectChain(range);
    }
    return range->GetLength() != 0;
}

bool TreeCacheContainer::IsPatternChainValid() const
{
    return CachedChildPattern.IsValid();
}

// @0x142684e20
void TreeCacheContainer::forceUpdateImages()
{
    for (TreeCacheNode* child = Children.GetFirst(); !Children.IsNull(child); child = child->pNext)
        child->forceUpdateImages();
}

// a debugging check: every entry still rooted, and linked to the next one
// @0x142683ac0
void VerifyPattern(BundleEntryRange& pattern)
{
    unsigned       count  = 0;
    BundleIterator ientry = pattern.GetIterator();

    while (ientry)
    {
        BundleEntry*   chain     = ientry.GetEntry();
        TreeCacheNode* cacheNode = ientry->pSourceNode;
        if (!cacheNode->pRoot)
            FUN_140ccaae0("Null pRoot in %p - %p node\n", ientry.GetEntry(), cacheNode);

        unsigned chainCount = 0;
        while (chain->pChain)
        {
            if (!chain->pSourceNode->pRoot)
                FUN_140ccaae0("Null pRoot in %p - %p node - at chain loop %d\n", ientry.GetEntry(),
                              ientry->pSourceNode, chainCount);
            chain = chain->pChain;
            chainCount++;
        }

        if (ientry.GetEntry() != pattern.GetLast() && !ientry->HasNextPattern())
        {
            FUN_140ccaae0("Frame %d: Null NextPattern after %p, count = %d\n", BundlePatternFrameId,
                          ientry.GetEntry(), count);
            TreeCacheNode* parent = cacheNode->GetParent();
            FUN_140ccaae0("SourceNode = %p, parent = %p\n", cacheNode, parent);
            while (parent)
            {
                FUN_140ccaae0("%p Depth = %d\n", parent, parent->Depth);
                parent = parent->GetParent();
            }
        }

        ientry++;
        count++;
    }
}

// ***** TreeCacheRoot

// @0x142681070
void TreeCacheRoot::ChainUpdatesByDepth()
{
    TreeCacheNode* p = pUpdateList;
    pUpdateList      = 0;
    while (p)
    {
        TreeCacheNode* next = p->pNextUpdate;
        DepthUpdates.Link(p->Depth, &p->pNextUpdate, p);
        p = next;
    }
    DepthUpdatesChained = true;
}

// @0x142681fc0
void TreeCacheRoot::HandleChanges(unsigned changeBits)
{
    if ((changeBits & Change_Viewport) && GetNodeData())
        ViewValid = GetNodeData()->VP.GetCullRectF(&ViewCullRect, false);
    TreeCacheContainer::HandleChanges(changeBits & ~Change_Viewport);
}

// @0x1426813d0
void TreeCacheRoot::Draw()
{
    if (!IsDrawn())
        return;

    const TreeRoot::NodeData* data = GetNodeData();
    if (data->HasViewport())
        pRenderer2D->GetHAL()->BeginDisplay(data->BGColor, data->VP);

    pRenderer2D->GetHAL()->DrawBundleEntries(CachedChildPattern.GetIterator(), pRenderer2D);

    if (data->HasViewport())
        pRenderer2D->GetHAL()->EndDisplay();
}

// ***** TreeCacheMeshBase

// @0x142680040
TreeCacheMeshBase::TreeCacheMeshBase(TreeNode* node, const SortKey& key, Renderer2DImpl* renderer2D,
                                     unsigned flags)
    : TreeCacheNode(node, renderer2D, flags), SorterShapeNode(this, key)
{
}

// @0x1426801d0
TreeCacheMeshBase::~TreeCacheMeshBase()
{
}

// the pooled matrix for t: allocated on first use (with a color transform only when one is set), else updated
// @0x142681200
void TreeCacheMeshBase::ComputeFinalMatrix(const TransformArgs& t, TransformFlags flags)
{
    if (M.IsNull())
    {
        unsigned formatBits = HMatrix::Has_2D;
        if (!(t.Cx == Cxform::Identity))
            formatBits |= HMatrix::Has_Cxform;

        if (flags & TF_Has3D)
        {
            Matrix3F m3(Matrix3F::NoInit);
            t.GetMatrix3D(flags, &m3);
            formatBits |= HMatrix::Has_3D;
            M = GetMatrixPool().CreateMatrix(m3, t.Cx, formatBits);
        }
        else
            M = GetMatrixPool().CreateMatrix(t.Mat, t.Cx, formatBits);
    }
    else
    {
        if (flags & TF_Has3D)
        {
            Matrix3F m3(Matrix3F::NoInit);
            t.GetMatrix3D(flags, &m3);
            M.SetMatrix3D(m3);
        }
        else
            M.SetMatrix2D(t.Mat);
        if (flags & TF_Cxform)
            M.SetCxform(t.Cx);
    }
}

void TreeCacheMeshBase::HandleChanges(unsigned)
{
}

// @0x142681710
bool TreeCacheMeshBase::GetPatternChain(BundleEntryRange* range, unsigned)
{
    if (!IsDrawn())
    {
        range->Clear(Range_Empty);
        return false;
    }

    range->SetToEntry(&SorterShapeNode);
    SorterShapeNode.Removed = false;

    // asked for while a bundle is rebuilt: have it re-checked
    if (Effects.IsEmpty() && !(UpdateFlags & Change_State_Effect_Mask))
    {
        // the one-entry chain strip; the next-pattern link stays
        if (SorterShapeNode.pBundle)
            SorterShapeNode.pBundle->SetNeedsUpdate();
        SorterShapeNode.pChain      = 0;
        SorterShapeNode.ChainHeight = 0;
    }
    else
    {
        if (UpdateFlags & Change_State_Effect_Mask)
        {
            Effects.UpdateEffects(this, UpdateFlags & Change_State_Effect_Mask);
            updateEffectChain(range);
            UpdateFlags &= ~Change_State_Effect_Mask;
        }
        else
            Effects.GetRange(range);
        // a leaf: every chain is cut
        range->StripChainsByDepth(Depth);
    }
    return true;
}

// MS2-FUNCTIONAL: the inlined updateEffectChain passes no flags to the mask's GetPatternChain in the exe
// @0x1426829e0
void TreeCacheMeshBase::UpdateBundlePattern(unsigned)
{
    if (HasMask() && !Effects.IsEmpty())
    {
        BundleEntryRange chain(Range_Empty);
        chain.SetToEntry(&SorterShapeNode);
        updateEffectChain(&chain);
    }
}

}} // namespace Scaleform::Render
