// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the HAL base (Render_HAL):
// the frame / scene / display brackets, the queueing of draw items behind an open scene, the blend and filter
// stacks, and the matrix state of the current viewport with its lazily rebuilt user * view * projection matrix.
// Queue unit sfr_render_06 is split along its original sources (06g Render_HAL).
// MS2-UNIT: sfr_render_06g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426beaf0-0x1426c21b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_drawableimage.h"

#include <math.h>

namespace Scaleform { namespace Render {

// ----- Matrix2x4

// @0x1426bf710
const Matrix2x4<float> operator*(const Matrix2x4<float>& m1, const Matrix2x4<float>& m2)
{
    return Matrix2x4<float>(m1).Prepend(m2);
}

// ----- MatrixState

// @0x1426bf130
MatrixState::MatrixState() : S3DDisplay(StereoCenter)
{
    UVPOChanged    = 0;
    OrientationSet = 0;
}

// @0x1426c13d0
void MatrixState::SetUserMatrix(const Matrix2F& user)
{
    UVPOChanged = 1;
    User        = user;
    UserView    = View2D * (User * Orient2D);
    // the 3D path applies the view scale itself: keep the translation in view units
    User3D = User;
    User3D.M[0][3] *= View2D.M[0][0] / User.M[0][0];
    User3D.M[1][3] *= View2D.M[1][1] / User.M[1][1];
}

// @0x1426c1510
void MatrixState::SetViewportMatrix(const Matrix2F& vp)
{
    View2D   = vp;
    UserView = View2D * (User * Orient2D);
}

// @0x1426c0cf0
Viewport MatrixState::SetOrientation(const Viewport& vp)
{
    OrientationSet = 0;
    UVPOChanged    = 1;

    switch (vp.Flags & Viewport::View_Orientation_Mask)
    {
    case Viewport::View_Orientation_Normal:
        Orient2D.SetIdentity();
        Orient3D.SetIdentity();
        break;
    case Viewport::View_Orientation_R90:
    case Viewport::View_Orientation_L90:
    {
        // a quarter turn one way or the other, moved back into the buffer
        OrientationSet = 1;
        float s = ((vp.Flags & Viewport::View_Orientation_Mask) == Viewport::View_Orientation_L90) ? -1.0f : 1.0f;
        Orient2D.SetMatrix(0, -s, s < 0 ? 0 : (float)vp.BufferWidth,
                           s, 0, s < 0 ? (float)vp.BufferHeight : 0);
        Orient3D.M[0][0] = 0;
        Orient3D.M[0][1] = s;
        Orient3D.M[1][1] = 0;
        Orient3D.M[1][0] = -s;
        break;
    }
    }

    UserView = View2D * (User * Orient2D);

    // the turned corners give the new rectangle
    Viewport r;
    float x1 = (float)vp.Left, y1 = (float)vp.Top;
    float x2 = (float)(vp.Left + vp.Width), y2 = (float)(vp.Top + vp.Height);
    Orient2D.Transform(&x1, &y1);
    Orient2D.Transform(&x2, &y2);
    r.Flags  = vp.Flags;
    r.Left   = (int)ceilf(x1 < x2 ? x1 : x2);
    r.Top    = (int)ceilf(y1 < y2 ? y1 : y2);
    r.Width  = (int)ceilf((float)fabs(x1 - x2));
    r.Height = (int)ceilf((float)fabs(y1 - y2));
    if (r.Flags & Viewport::View_UseScissorRect)
    {
        float sx1 = (float)vp.ScissorLeft, sy1 = (float)vp.ScissorTop;
        float sx2 = (float)(vp.ScissorLeft + vp.ScissorWidth), sy2 = (float)(vp.ScissorTop + vp.ScissorHeight);
        Orient2D.Transform(&sx1, &sy1);
        Orient2D.Transform(&sx2, &sy2);
        r.Flags         = vp.Flags;
        r.ScissorLeft   = (int)ceilf(sx1 < sx2 ? sx1 : sx2);
        r.ScissorTop    = (int)ceilf(sy1 < sy2 ? sy1 : sy2);
        r.ScissorWidth  = (int)ceilf((float)fabs(sx1 - sx2));
        r.ScissorHeight = (int)ceilf((float)fabs(sy1 - sy2));
    }
    r.BufferWidth  = vp.BufferWidth;
    r.BufferHeight = vp.BufferHeight;
    return r;
}

// @0x1426c1d40
void MatrixState::recalculateUVPOC() const
{
    if (!UVPOChanged)
        return;

    // a view rect moved or resized against the original one is compensated in clip space
    if (ViewRect != ViewRectOriginal && !ViewRectOriginal.IsNull())
    {
        Point<int> dc = ViewRect.Center() - ViewRectOriginal.Center();
        float sx = (float)ViewRectOriginal.Width() / ViewRect.Width();
        float sy = (float)ViewRectOriginal.Height() / ViewRect.Height();
        float ox = 2.0f * dc.x / ViewRect.Width();
        float oy = 2.0f * dc.y / ViewRect.Height();
        ViewRectCompensated3D.MultiplyMatrix(Matrix4F::Translation(-ox, oy, 0), Matrix4F::Scaling(sx, sy, 1));
    }
    else
        ViewRectCompensated3D = Matrix4F::Identity;

    const Matrix4F& proj = updateStereoProjection();
    Matrix4F        uo(User3D, ViewRectCompensated3D);
    Matrix4F        vrp(Orient3D, proj);
    UVPO        = Matrix4F(Matrix4F(uo, vrp), View3D);
    UVPOChanged = 0;
}

// @0x1426c2120
const Matrix4F& MatrixState::updateStereoProjection(float factor) const
{
    if (S3DDisplay != StereoCenter)
    {
        float eyeZ = -View3D.M[2][3];
        if (S3DDisplay == StereoLeft)
        {
            getStereoProjectionMatrix(&Proj3DLeft, 0, Proj3D, eyeZ, factor);
            return Proj3DLeft;
        }
        if (S3DDisplay == StereoRight)
        {
            getStereoProjectionMatrix(0, &Proj3DRight, Proj3D, eyeZ, factor);
            return Proj3DRight;
        }
    }
    return Proj3D;
}

// The eye projections are the mono one moved sideways: before the projection by the eye offset scaled to the
// screen distance, after it by the eye separation over the display width.
// @0x1426c1a90
void MatrixState::getStereoProjectionMatrix(Matrix4F* left, Matrix4F* right, const Matrix4F& original,
                                            float screenDist, float factor) const
{
    Matrix4F post;
    Matrix4F pre;
    Matrix4F t;

    float postShift = S3DParams.Distortion * factor * S3DParams.EyeSeparationCm / S3DParams.DisplayWidthCm;
    float preShift  = -postShift * screenDist * original.M[3][2] / original.M[0][0];
    if (preShift < 0)
        preShift = -preShift;

    if (left)
    {
        post.M[0][3] = -postShift;
        pre.M[0][3]  = preShift;
        t     = Matrix4F(original, pre);
        *left = Matrix4F(post, t);
    }
    if (right)
    {
        post.M[0][3] = postShift;
        pre.M[0][3]  = -preShift;
        t     = Matrix4F(original, pre);
        *right = Matrix4F(post, t);
    }
}

// ----- Viewport

// @0x1426c1240
void Viewport::SetStereoViewport(unsigned display)
{
    switch (Flags & View_Stereo_AnySplit)
    {
    case View_Stereo_SplitV:
        Height >>= 1;
        Top >>= 1;
        if (display == StereoRight)
            Top += BufferHeight >> 1;
        break;
    case View_Stereo_SplitH:
        Width >>= 1;
        Left >>= 1;
        if (display == StereoRight)
            Left += BufferWidth >> 1;
        break;
    }
}

// ----- the display brackets queued behind an open scene

class HALBeginDisplayItem : public RenderQueueItem::Interface
{
public:
    static HALBeginDisplayItem Instance;

    virtual void EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
    {
        qp.GetHAL()->beginDisplay((HAL::BeginDisplayData*)item.GetData());
    }
};

class HALEndDisplayItem : public RenderQueueItem::Interface
{
public:
    static HALEndDisplayItem Instance;

    virtual void EmitToHAL(RenderQueueItem&, RenderQueueProcessor& qp) { qp.GetHAL()->endDisplay(); }
};

HALBeginDisplayItem HALBeginDisplayItem::Instance;
HALEndDisplayItem   HALEndDisplayItem::Instance;

// ----- HAL

// @0x1426beb60
HAL::HAL(ThreadCommandQueue* commandQueue)
    : HALState(0), CurrentPass(Display_All), VMCFlags(0), RenderThreadID(0), pHeap(0),
      pRTCommandQueue(commandQueue), QueueProcessor(Queue, this), MaskStackTop(0), CachedFilterIndex(-1),
      CachedFilterPrepIndex(-1), NextProfileMode(0)
{
    pHeap = Memory::pGlobalHeap;
    Link_RenderStats();
}

// The destructor is implicit: the exe's deleting destructor (0x1426bf870) tears the members down without storing
// the HAL vtable again.

// @0x1426c1cf0
bool HAL::initHAL(const HALInitParams& params)
{
    VMCFlags       = params.ConfigFlags;
    RenderThreadID = params.RenderThreadId;
    if (!RenderThreadID)
        RenderThreadID = GetCurrentThreadId();
    return Queue.Initialize(params.RenderQueueSize);
}

// @0x1426c20a0
bool HAL::shutdownHAL()
{
    if (!(HALState & HS_ModeSet))
        return true;

    // the listeners may unlink themselves
    HALNotify* next;
    for (HALNotify* p = NotifyList.GetFirst(); !NotifyList.IsNull(p); p = next)
    {
        next = NotifyList.GetNext(p);
        p->OnHALEvent(HAL_Shutdown);
    }
    Queue.Shutdown();
    HALState = 0;
    return true;
}

// @0x1426bfb80
bool HAL::BeginFrame()
{
    GetEvent(Event_Frame).Begin(__FUNCTION__);
    if (!(HALState & HS_ModeSet))
        return false;
    // a lost device waits for its reset
    if (HALState & HS_ReadyForReset)
        return false;

    HALState |= HS_InFrame;
    GetRQProcessor().BeginFrame();
    GetMeshCache().BeginFrame();
    GetTextureManager()->BeginFrame();
    return true;
}

// @0x1426c0080
void HAL::EndFrame()
{
    ScopedRenderEvent ev(GetEvent(Event_Frame), 0, false);
    if ((HALState & (HS_ModeSet | HS_InFrame)) != (HS_ModeSet | HS_InFrame))
        return;

    if (RenderBufferManager* rbm = GetRenderBufferManager())
        rbm->EndFrame();
    GetMeshCache().EndFrame();
    HALState &= ~HS_InFrame;
}

// @0x1426bf9f0
void HAL::BeginDisplay(Color backgroundColor, const Viewport& viewport)
{
    if (!(HALState & HS_InFrame))
        return;

    BeginDisplayData* data = BeginDisplayDataList.Alloc(BeginDisplayData(backgroundColor, viewport));
    if (!(HALState & HS_InScene))
        beginDisplay(data);
    else
        Draw(RenderQueueItem(&HALBeginDisplayItem::Instance, data));
}

// @0x1426c0030
void HAL::EndDisplay()
{
    if (!(HALState & HS_SceneInDisplay))
        Draw(RenderQueueItem(&HALEndDisplayItem::Instance, 0));
    else
    {
        Flush();
        endDisplay();
    }
}

// MS2-FUNCTIONAL: the exe frame carries a /GS cookie (0x88 bytes) that this build does not emit
// @0x1426c15c0
void HAL::beginDisplay(BeginDisplayData* data)
{
    GetEvent(Event_Display).Begin(__FUNCTION__);
    if (!(HALState & HS_InFrame))
        return;

    HALState |= HS_InDisplay;
    // the exe keeps reading the viewport after the node went back to the free list (only its first qword, the
    // link, is overwritten)
    Color           bg = data->BackgroundColor;
    const Viewport& vp = data->VP;
    BeginDisplayDataList.Free(data);

    // a display outside of a scene opens its own
    if (!(HALState & HS_InScene))
    {
        BeginScene();
        HALState |= HS_SceneInDisplay;
    }

    applyBlendMode(Blend_None, false, false);
    beginMaskDisplay();

    VP = Matrices.SetOrientation(vp);
    if (VP.GetClippedRect(&ViewRect))
        HALState |= HS_ViewValid;
    else
        HALState &= ~HS_ViewValid;
    updateViewport();

    if (bg.GetAlpha() > 0)
        clearSolidRectangle(Rect<int>(0, 0, vp.Width, vp.Height), bg);
}

// @0x1426c1920
void HAL::endDisplay()
{
    ScopedRenderEvent ev(GetEvent(Event_Display), 0, false);
    if (!(HALState & HS_InDisplay))
        return;

    endMaskDisplay();
    if (HALState & HS_SceneInDisplay)
    {
        EndScene();
        HALState &= ~HS_SceneInDisplay;
    }
    HALState &= ~HS_InDisplay;
}

// @0x1426c01f0
void HAL::Flush()
{
    GetRQProcessor().Flush();
}

// @0x1426bfc40
bool HAL::BeginScene()
{
    GetEvent(Event_Scene).Begin(__FUNCTION__);
    if (!(HALState & HS_InFrame))
        return false;

    if (GetTextureManager())
        GetTextureManager()->BeginScene();
    HALState |= HS_InScene;
    return true;
}

// @0x1426c0130
bool HAL::EndScene()
{
    ScopedRenderEvent ev(GetEvent(Event_Scene), 0, false);
    if ((HALState & (HS_InFrame | HS_InScene)) != (HS_InFrame | HS_InScene))
        return false;

    Flush();
    if (GetTextureManager())
        GetTextureManager()->EndScene();
    HALState &= ~HS_InScene;
    return true;
}

// @0x1426c17a0
void HAL::destroyRenderBuffers()
{
    // the default targets the HAL made itself go, with their depth stencils
    unsigned count = (unsigned)RenderTargetStack.GetSize();
    for (unsigned i = 0; i < count; i++)
    {
        RenderTarget*       rt = 0;
        DepthStencilBuffer* ds = 0;
        {
            RenderTargetEntry e = RenderTargetStack.Pop();
            if (e.pRenderTarget && e.pRenderTarget->GetType() == RBuffer_Default)
            {
                rt                    = e.pRenderTarget;
                RenderTargetData* rtd = rt->GetRenderTargetData();
                if (rtd && rtd->pDepthStencilBuffer)
                {
                    ds = rtd->pDepthStencilBuffer;
                    rtd->pDepthStencilBuffer.Clear();
                }
            }
        }
        if (rt)
            delete rt;
        if (ds)
            delete ds;
    }
    RenderTargetStack.Resize(0);
}

// @0x1426bfd80
void HAL::DrawBundleEntries(BundleIterator ibundles, Renderer2DImpl* r2d)
{
    if (CurrentPass == Display_All && IsPrepassRequired())
    {
        // the filters first, then everything
        SetDisplayPass(Display_Prepass);
        DrawBundleEntries(ibundles, r2d);
        SetDisplayPass(Display_Final);
        DrawBundleEntries(ibundles, r2d);
        SetDisplayPass(Display_All);
        return;
    }

    // the prepass only emits the filter items; the final and single passes emit everything
    switch (CurrentPass)
    {
    case Display_Prepass:
        GetRQProcessor().SetQueueEmitFilter(RenderQueueProcessor::QPF_Filters);
        GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_Filters);
        break;
    case Display_Final:
    case Display_All:
        GetRQProcessor().SetQueueEmitFilter(RenderQueueProcessor::QPF_All);
        GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_All);
        break;
    }
    while (ibundles)
    {
        ibundles->DrawBundleEntry(r2d);
        ibundles++;
    }
}

// @0x1426bfce0
void HAL::Draw(const RenderQueueItem& item)
{
    if (item.GetInterface() != &HALBeginDisplayItem::Instance && !(HALState & HS_InDisplay))
        return;

    RenderQueueProcessor& qp = GetRQProcessor();
    RenderQueueItem*      p  = Queue.ReserveHead();
    if (!p)
    {
        qp.ProcessQueue(RenderQueueProcessor::QPM_One);
        p = Queue.ReserveHead();
    }
    *p = item;
    Queue.AdvanceHead();
    qp.ProcessQueue(RenderQueueProcessor::QPM_Any);
}

// @0x1426c0850
void HAL::PushBlendMode(BlendMode mode)
{
    if (!(HALState & HS_InDisplay))
        return;
    BlendModeStack.PushBack(mode);
    applyBlendMode(mode, false, (HALState & HS_InRenderTarget) != 0);
}

// @0x1426c03b0
void HAL::PopBlendMode()
{
    if (!(HALState & HS_InDisplay))
        return;
    UPInt n = BlendModeStack.GetSize();
    BlendModeStack.PopBack();
    applyBlendMode(n > 1 ? BlendModeStack[n - 2] : Blend_Normal, false, (HALState & HS_InRenderTarget) != 0);
}

// @0x1426c06a0
void HAL::PrepareFilters(FilterPrimitive* prim)
{
    if (!(HALState & HS_InDisplay) || !prim)
        return;

    if (prim->GetFilters())
    {
        if (prim->GetCacheState() == FilterPrimitive::Cache_Uncached)
        {
            if (CurrentPass == Display_Prepass)
                GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_All);
            return;
        }

        // cached: the results must still be there and still be this primitive's
        RenderTarget* results[FilterPrimitive::MaximumCachedResults];
        prim->GetCacheResults(results, FilterPrimitive::MaximumCachedResults);
        bool valid = true;
        for (unsigned i = 0; i < FilterPrimitive::MaximumCachedResults; i++)
        {
            if (!results[i])
            {
                valid = (i != 0);
                break;
            }
            if (results[i]->GetStatus() == RTS_Lost || results[i]->GetStatus() == RTS_Unresolved ||
                results[i]->GetRenderTargetData()->CacheID != (UPInt)prim)
            {
                valid = false;
                break;
            }
        }

        CachedFilterPrepIndex++;
        if (!valid)
        {
            prim->SetCacheResults(FilterPrimitive::Cache_Uncached, 0, 0);
            return;
        }
        // the outermost cached filter: nothing inside it needs preparing
        if (CachedFilterPrepIndex == 0)
        {
            for (unsigned i = 0; i < FilterPrimitive::MaximumCachedResults; i++)
            {
                if (results[i])
                    results[i]->SetInUse(true);
            }
            GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_Filters);
        }
    }
    else
    {
        // no filters: the end of a filtered range being prepared
        if (CachedFilterPrepIndex < 0)
            return;
        if (CachedFilterPrepIndex == 0)
        {
            if (CurrentPass != Display_Prepass)
                GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_All);
            else
                GetRQProcessor().SetQueuePrepareFilter(RenderQueueProcessor::QPF_Filters);
        }
        CachedFilterPrepIndex--;
    }
}

// @0x1426c0470
void HAL::PopFilters()
{
    FilterStackEntry e;
    e = FilterStack.Pop();

    // a cached filter is drawn once its own level is popped
    if ((HALState & HS_CachedFilter) && CachedFilterIndex < (int)FilterStack.GetSize())
        return;

    CachedFilterIndex = -1;
    if (HALState & HS_CachedFilter)
    {
        drawCachedFilter(e.pPrimitive);
        GetRQProcessor().SetQueueEmitFilter(RenderQueueProcessor::QPF_All);
        HALState &= ~HS_CachedFilter;
    }
    else
        drawUncachedFilter(e);

    if (FilterStack.GetSize() == 0)
        HALState &= ~HS_DrawingFilter;
}

// @0x1426bff00
unsigned HAL::DrawableCommandGetFlags(const DICommand* command) const
{
    if (!command)
        return 0;
    switch (command->GetType())
    {
    case DICommandType_Map:
    case DICommandType_Unmap:
    case DICommandType_CreateTexture:
        return DICommand::RC_GPU | DICommand::RC_GPU_NoRT;

    case DICommandType_Clear:
    case DICommandType_ApplyFilter:
    case DICommandType_Draw:
    case DICommandType_CopyChannel:
    case DICommandType_CopyPixels:
    case DICommandType_ColorTransform:
    case DICommandType_Compare:
    case DICommandType_FillRect:
        return DICommand::RC_GPU | DICommand::RC_GPUPreference;
    case DICommandType_FloodFill:
        return 0;
    case DICommandType_Merge:
        return DICommand::RC_GPU | DICommand::RC_GPUPreference;
    case DICommandType_Noise:
        return 0;
    case DICommandType_PaletteMap:
        return DICommand::RC_GPU | DICommand::RC_GPUPreference;
    case DICommandType_PerlinNoise:
        return 0;
    case DICommandType_Scroll:
        return DICommand::RC_GPU | DICommand::RC_GPUPreference;
    case DICommandType_Threshold:
        return DICommand::RC_GPU;

    default:
        return 0;
    }
}

// MS2-FUNCTIONAL: the exe builds the static RenderEvent with a guarded run-time vtable store; ours is constant-initialised
// @0x1426c0240
RenderEvent& HAL::GetEvent(EventType)
{
    static RenderEvent defaultEvent;
    return defaultEvent;
}

// @0x1426c1290
void HAL::SetUserMatrix(const Matrix2F& userMatrix)
{
    Matrices.SetUserMatrix(userMatrix);
}

// @0x1426c11b0
void HAL::SetStereoParams(StereoParams sParams)
{
    // derive the width from the diagonal: width^2 * (1 + aspect^2) = diagonal^2
    if (sParams.DisplayWidthCm == 0)
        sParams.DisplayWidthCm = (float)(sParams.DisplayDiagInches /
                                         sqrt((double)(1.0f / sParams.DisplayAspectRatio / sParams.DisplayAspectRatio + 1.0f)) *
                                         2.54f);
    Matrices.S3DParams = sParams;
}

// @0x1426c19d0
void HAL::endMaskDisplay()
{
    MaskStackTop = 0;
    MaskStack.Clear();
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EB@@Scaleform@@6B@ 0x143183fa8
// MS2-PIN: ??_7?$RefCountBase@VHAL@Render@Scaleform@@$0EB@@Scaleform@@6B@ 0x143192ab8
// MS2-PIN: ??_7HAL@Render@Scaleform@@6B@ 0x143192ac0
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-PIN: ??_7HALBeginDisplayItem@Render@Scaleform@@6B@ 0x143192a68
// MS2-PIN: ??_7HALEndDisplayItem@Render@Scaleform@@6B@ 0x143192a80
// MS2-PIN: ??_7RenderEvent@Render@Scaleform@@6B@ 0x143192a98
// MS2-PIN: ??_GHALBeginDisplayItem@Render@Scaleform@@UEAAPEAXI@Z 0x1426beaf0
// MS2-PIN: ??_GHALEndDisplayItem@Render@Scaleform@@UEAAPEAXI@Z 0x1426beb30
