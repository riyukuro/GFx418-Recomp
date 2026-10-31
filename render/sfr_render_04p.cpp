// MS2-UNIT: sfr_render_04p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14263dfa0-0x14263fb00 .text$mn
// Recovered Scaleform 4.1.18 Render: Renderer2DImpl (Render_Renderer2DImpl), the 2D renderer behind Renderer2D. It
// owns the mesh/stroke generators, the fill manager, matrix pool, mesh key manager and glyph cache, hears HAL device
// events, keeps one TreeCacheRoot per drawn TreeRoot and feeds the context's change buffers into the cache trees.
// Also Viewport::GetClippedRect<int>, which this TU instantiates out of line.

#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_glyphcache.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_meshcache.h"

namespace Scaleform { namespace Render {

// ***** Viewport

// the view (its size turned for a 90-degree orientation when orient is set) clipped to the buffer, then to the
// scissor rectangle when the viewport uses one; an empty rectangle and false when nothing is left
// @0x14263dfa0
template<class T>
bool Viewport::GetClippedRect(Rect<T>* prect, bool orient) const
{
    T w, h;
    if (orient)
    {
        switch (Flags & View_Orientation_Mask)
        {
        case View_Orientation_R90:
        case View_Orientation_L90:
            w = Height;
            h = Width;
            break;
        default:
            w = Width;
            h = Height;
            break;
        }
    }
    else
    {
        w = Width;
        h = Height;
    }

    Rect<T> view(Left, Top, Left + w, Top + h);
    if (!view.IntersectRect(prect, Rect<T>(0, 0, BufferWidth, BufferHeight)))
    {
        prect->Clear();
        return false;
    }
    if (Flags & View_UseScissorRect)
    {
        Rect<T> scissor(ScissorLeft, ScissorTop, ScissorLeft + ScissorWidth, ScissorTop + ScissorHeight);
        if (!prect->IntersectRect(prect, scissor))
        {
            prect->Clear();
            return false;
        }
    }
    return true;
}

template bool Viewport::GetClippedRect<int>(Rect<int>* prect, bool orient) const;

// the clipped view relative to its own corner; Viewport::GetCullRectF (sfr_render_05j) inlined into Draw
static inline bool getViewCullRect(const Viewport& vp, RectF* prect)
{
    Rect<int> clipRect;
    if (!vp.GetClippedRect(&clipRect, true))
        return false;
    prect->SetRect((float)(clipRect.x1 - vp.Left), (float)(clipRect.y1 - vp.Top), (float)(clipRect.x2 - vp.Left),
                   (float)(clipRect.y2 - vp.Top));
    return true;
}

// ***** Renderer2DImpl

// the changes a cache node handles itself (morph, edge AA, children, shape, viewport, 3D)
enum
{
    Change_HandleChanges_Mask = Change_MorphRatio | Change_EdgeAAMode | Change_ChildInsert | Change_ChildRemove |
                                Change_Shape | Change_Viewport | Change_3D
};

// @0x14263e0f0
Renderer2DImpl::Renderer2DImpl(HAL* hal)
    : Context::RenderNotify(hal->pRTCommandQueue), pHal(hal), MeshGen(Memory::GetHeapByAddress(getThis())),
      StrokeGen(Memory::GetHeapByAddress(getThis())), FillManager(hal),
      MPool(Memory::GetHeapByAddress(getThis()))
{
    hal->NotifyList.PushBack(this);

    // the key manager lives in the global heap (shutdown synchronizes on it); its key data uses the renderer's
    MemoryHeap* heap = Memory::GetHeapByAddress(getThis());
    pMeshKeyManager  = *SF_NEW MeshKeyManager(heap);
    pGlyphCache      = *SF_HEAP_NEW(heap) GlyphCache(heap);
    pGlyphCache->Initialize(hal, &FillManager);
}

// @0x14263e740
Renderer2DImpl::~Renderer2DImpl()
{
    ReleaseAllContextData();
    pMeshKeyManager->DestroyAllKeys();
    HALNotify::RemoveNode();
}

// @0x14263edc0
void Renderer2DImpl::AddComplexMeshToUpdateList(ComplexMesh::UpdateNode& node)
{
    if (!node.pPrev)
        mComplexMeshUpdateList.PushBack(&node);
}

// @0x14263edf0
void Renderer2DImpl::BeginDisplay(Color backgroundColor, const Viewport& viewport)
{
    pHal->BeginDisplay(backgroundColor, viewport);
    VP = viewport;
}

// @0x14263ee50
bool Renderer2DImpl::BeginFrame()
{
    pMeshKeyManager->ProcessKillList();
    if (pGlyphCache)
        pGlyphCache->OnBeginFrame();
    return pHal->BeginFrame();
}

// draws a root's cache tree, building it on first use; a root with its own viewport also sets the HAL's full view
// @0x14263ee90
void Renderer2DImpl::Draw(TreeRoot* node)
{
    TreeCacheRoot*            rootCache = (TreeCacheRoot*)node->GetRenderData();
    const TreeRoot::NodeData* data      = node->GetDisplayData();
    bool                      hasVP     = data->HasViewport();
    const Viewport&           vp        = hasVP ? data->VP : VP;

    if (hasVP)
    {
        switch (vp.Flags & Viewport::View_Orientation_Mask)
        {
        default:
        {
            Rect<int> viewRect(vp.Left, vp.Top, vp.Left + vp.Width, vp.Top + vp.Height);
            // GetHAL()->SetFullViewRect(viewRect)
            HAL* hal                       = pHal;
            hal->Matrices.ViewRectOriginal = viewRect;
            hal->Matrices.UVPOChanged      = 1;
            break;
        }
        case Viewport::View_Orientation_L90:
        case Viewport::View_Orientation_R90:
        {
            Rect<int> viewRect(vp.Left, vp.Top, vp.Left + vp.Height, vp.Top + vp.Width);
            HAL*      hal                  = pHal;
            hal->Matrices.ViewRectOriginal = viewRect;
            hal->Matrices.UVPOChanged      = 1;
            break;
        }
        }
    }

    RectF viewCullRect;
    bool  viewValid = getViewCullRect(vp, &viewCullRect);
    if (!vp.IsValid())
        return;

    if (!rootCache)
    {
        unsigned flags = data->IsVisible() ? NF_Visible : 0;
        flags |= TreeCacheNode::CalcEdgeAAMode(data);

        rootCache = SF_HEAP_AUTO_NEW(this) TreeCacheRoot(this, pHal, flags, node);
        if (!rootCache)
            return;
        node->SetRenderData(rootCache);
        RenderRoots.PushBack(rootCache);

        rootCache->ViewValid    = viewValid;
        rootCache->ViewCullRect = viewCullRect;

        rootCache->UpdateChildSubtree(node->GetDisplayData(), 1);
        rootCache->AddToUpdate(rootCache, Change_Matrix | Change_CxForm | Update_Pattern);
        rootCache->ChainUpdatesByDepth();
        rootCache->UpdateTreeData();
    }
    else if (viewValid != rootCache->ViewValid || viewCullRect != rootCache->ViewCullRect)
    {
        rootCache->ViewValid    = viewValid;
        rootCache->ViewCullRect = viewCullRect;
        rootCache->AddToUpdate(rootCache, Change_Matrix);
        rootCache->UpdateTreeData();
    }

    if (viewValid)
        rootCache->Draw();
}

// @0x14263f460
void Renderer2DImpl::EndDisplay()
{
    pHal->EndDisplay();
    MPool.MemorySqueeze(MatrixPoolImpl::MatrixPool::Squeeze_Incremental);
}

// @0x14263f490
void Renderer2DImpl::EndFrame()
{
    pHal->EndFrame();
    EndFrameContextNotify();
    if (pGlyphCache)
        pGlyphCache->OnEndFrame();
}

// routes a context's recorded changes into the cache trees, then runs every root's pending updates
// @0x14263f4d0
void Renderer2DImpl::EntryChanges(Context& context, Context::ChangeBuffer& cb, bool forceUpdateImages)
{
    for (Context::ChangeBuffer::Page* page = cb.GetFirstPage(); page; page = page->pNext)
    {
        for (unsigned i = 0; i < page->GetSize(); i++)
        {
            Context::EntryChange& change = page->GetItem(i);
            TreeNode*             tnode  = (TreeNode*)change.pNode;
            if (!tnode)
                continue;
            TreeCacheNode* cache = tnode->GetRenderData();
            if (!cache)
                continue;

            if (change.ChangeBits & Change_HandleChanges_Mask)
                cache->HandleChanges(change.ChangeBits);

            TreeCacheRoot* root = cache->pRoot;

            if (change.ChangeBits & (Change_AproxBounds | Change_Visible | Change_IsMask | Change_State_Effect_Mask))
            {
                unsigned updateFlags = 0;
                if (change.ChangeBits & Change_Visible)
                {
                    updateFlags |= Update_Pattern;
                    cache->ApplyFlags(NF_Visible, cache->GetNodeData()->GetFlags() & NF_Visible);
                }
                if (change.ChangeBits & Change_State_MaskNode)
                    cache->updateMaskCache(cache->GetNodeData(), cache->Depth + 1, false);
                if (change.ChangeBits & Change_AproxBounds)
                    updateFlags |= Update_PatternBounds;
                if (change.ChangeBits & Change_State_Effect_Mask)
                {
                    cache->UpdateFlags |= change.ChangeBits & Change_State_Effect_Mask;
                    updateFlags |= Update_Pattern;
                }
                if (root && updateFlags && cache->GetParent())
                    root->AddToUpdate(cache->GetParent(), updateFlags);
            }

            if (!root)
                continue;

            const unsigned copyMask = Change_Matrix | Change_CxForm | Change_State_Scale9 | Change_3D;
            if (change.ChangeBits & copyMask)
            {
                root->AddToUpdate(cache, change.ChangeBits & copyMask);
                // a mask's matrix moves its parent's bounds
                if ((change.ChangeBits & Change_Matrix) && cache->IsMaskNode())
                    root->AddToUpdate(cache->pParent, Change_Matrix | Update_PatternBounds);
            }
        }
    }

    if (forceUpdateImages)
        UpdateComplexMeshes();

    for (TreeCacheRoot* root = (TreeCacheRoot*)RenderRoots.GetFirst(); !RenderRoots.IsNull(root);
         root = (TreeCacheRoot*)root->pNext)
    {
        if (forceUpdateImages && root->pNode->getContext() == &context)
            root->forceUpdateImages();
        root->ChainUpdatesByDepth();
        root->UpdateTreeData();
    }
}

// @0x14263f7e0
void Renderer2DImpl::EntryDestroy(Context::Entry* p)
{
    TreeCacheNode* cache = p->GetRenderData();
    if (cache)
    {
        delete cache;
        // the context checks the render data for node validity when it finishes rendering
        p->SetRenderData(0);
    }
}

void Renderer2DImpl::EntryFlush(Context::Entry* p)
{
    EntryDestroy(p);
}

// @0x14263f830
void Renderer2DImpl::ForceUpdateImages(Context* context)
{
    UpdateComplexMeshes();

    for (TreeCacheRoot* root = (TreeCacheRoot*)RenderRoots.GetFirst(); !RenderRoots.IsNull(root);
         root = (TreeCacheRoot*)root->pNext)
    {
        if (context && context != root->pNode->getContext())
            continue;
        root->forceUpdateImages();
        root->ChainUpdatesByDepth();
        root->UpdateTreeData();
    }
}

// @0x14263f920
MeshCacheConfig* Renderer2DImpl::GetMeshCacheConfig() const
{
    MeshCache* cache = &pHal->GetMeshCache();
    return cache;
}

// @0x14263f9b0
void Renderer2DImpl::OnHALEvent(HALNotifyType type)
{
    switch (type)
    {
    case HAL_Initialize:
    case HAL_RestoreAfterReset:
        pGlyphCache->Initialize(pHal, &FillManager);
        break;
    case HAL_Shutdown:
    case HAL_PrepareForReset:
        pGlyphCache->Destroy();
        break;
    default:
        break;
    }
}

// @0x14263f9f0
void Renderer2DImpl::SetGlyphCacheParam(const GlyphCacheParams& param)
{
    mGlyphCacheParam = param;
    if (pHal->IsInitialized())
        pGlyphCache->Initialize(pHal, &FillManager);
}

// re-resolves the image fills of the listed complex meshes; the key set lock keeps their providers alive
// @0x14263fa90
void Renderer2DImpl::UpdateComplexMeshes()
{
    Lock::Locker locker(pMeshKeyManager->getLock());
    for (ComplexMesh::UpdateNode* cur = mComplexMeshUpdateList.GetFirst(); !mComplexMeshUpdateList.IsNull(cur);
         cur = cur->pNext)
    {
        ComplexMesh* mesh = (ComplexMesh*)((UByte*)cur - offsetof(ComplexMesh, UpdateListNode));
        mesh->updateFills();
    }
}

}} // namespace Scaleform::Render

// out-of-line implicit/inline members emitted here, and the vftables (no RTTI; laid out 0x14318fb38-0x14318fd30)
// MS2-PIN: ??1PrimitiveFillManager@Render@Scaleform@@UEAA@XZ 0x14263e670
// MS2-PIN: ??_GTreeCacheRoot@Render@Scaleform@@UEAAPEAXI@Z 0x14263ece0
// MS2-PIN: ??_7ServiceCommand@RenderNotify@ContextImpl@Render@Scaleform@@6B@ 0x14318fb38
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EF@@Scaleform@@6B@ 0x14318fb48
// MS2-PIN: ??_7?$RefCountBase@VPrimitiveFillManager@Render@Scaleform@@$0EF@@Scaleform@@6B@ 0x14318fb50
// MS2-PIN: ??_7PrimitiveFillManager@Render@Scaleform@@6B@ 0x14318fb58
// MS2-PIN: ??_7HALNotify@Render@Scaleform@@6B@ 0x14318fb60
// MS2-PIN: ??_7TreeCacheRoot@Render@Scaleform@@6B@ 0x14318fb70
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
// MS2-PIN: ??_7VertexPath@Render@Scaleform@@6B@ 0x14318fc58
// MS2-PIN: ??_7?$RefCountBase@VMeshKeyManager@Render@Scaleform@@$0EB@@Scaleform@@6B@ 0x14318fcd8
// MS2-PIN: ??_7MeshKeyManager@Render@Scaleform@@6B@ 0x14318fce0
// MS2-PIN: ??_7Renderer2DImpl@Render@Scaleform@@6BRenderNotify@ContextImpl@12@@ 0x14318fce8
// MS2-PIN: ??_7Renderer2DImpl@Render@Scaleform@@6BHALNotify@12@@ 0x14318fd20
// MS2-PIN: ??_7ThreadCommand@Render@Scaleform@@6B@ 0x143183928
// MS2-PIN: ??_7RenderNotify@ContextImpl@Render@Scaleform@@6B@ 0x143183f48
// MS2-PIN: ??_7TreeCacheContainer@Render@Scaleform@@6B@ 0x14318ebc8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EB@@Scaleform@@6B@ 0x143183fa8
// MS2-PIN: ??_7?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@6B@ 0x143183980
