// Recovered Scaleform 4.1.18 Render: HAL, the hardware abstraction a Renderer2D draws through (Render_HAL, unit
// sfr_render_06g). The base keeps the frame / scene / display state bits, the matrix state of the current viewport,
// the render queue with its processor, and the blend / mask / render target / filter stacks; the D3D9 HAL fills in
// the device work.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x580 bytes) checked against the ctor 0x1426beb60 and the deleting dtor 0x1426bf870; vftable 0x143192ac0.
#ifndef MS2_SF_RENDER_HAL_H
#define MS2_SF_RENDER_HAL_H

// the queue embeds RenderQueueItems and includes this header at its end: pull it in first
#include "ms2/scaleform/include/render/render_queue.h"

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_listalloc.h"
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_buffer.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_events.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/include/render/render_constants.h"
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_bundle.h"

namespace Scaleform { namespace Render {

class Viewport;
class RenderBufferManager;
class DepthStencilBuffer;
class PrimitiveFill;
struct PrimitiveFillData;
class MeshCache;
class RQCacheInterface;
class FilterPrimitive;
// (appended for sfr_render_07p)
class Primitive;
class PrimitiveBatch;
struct DICommand;
// (appended for sfr_render_07q)
class RenderQueueItem;
class MaskPrimitive;
// (appended for sfr_render_06e)
class ComplexMesh;
template<class T> struct StrideArray;
namespace MatrixPoolImpl { class HMatrix; }
// (appended for sfr_render_06g)
class ThreadCommandQueue;
class Renderer2DImpl;
class MemoryManager;

// pulls the render stat registrations into the link (an empty function, 0x1426dffe0)
void Link_RenderStats();

// Which eye a stereo display is drawn for.
enum StereoDisplay
{
    StereoCenter,
    StereoLeft,
    StereoRight
};

// The physical setup the stereo projections are derived from (0x14 bytes).
struct StereoParams
{
    float DisplayWidthCm;       // 0: derived from the diagonal and the aspect ratio
    float Distortion;
    float DisplayDiagInches;
    float DisplayAspectRatio;   // height / width
    float EyeSeparationCm;

    StereoParams()
        : DisplayWidthCm(0), Distortion(0.75f), DisplayDiagInches(52.f), DisplayAspectRatio(9.f / 16.f),
          EyeSeparationCm(6.4f) {}
};

// The matrices of the current viewport and what they combine into (0x290 bytes, no vftable in this build). The
// combined user * view * projection matrix is rebuilt lazily, the first time it is asked for after a change.
class MatrixState
{
public:
    MatrixState();   // 0x1426bf130

    // the viewport turned by its orientation flags; the orientation matrices follow
    Viewport SetOrientation(const Viewport& vp);
    void     SetUserMatrix(const Matrix2F& user);
    void     SetViewportMatrix(const Matrix2F& vp);

    const Matrix4F& GetUVPO() const
    {
        recalculateUVPOC();
        return UVPO;
    }

    Matrix2F          View2D;                  // +0x000
    Matrix3F          View3D;                  // +0x020
    Matrix4F          Proj3D;                  // +0x050
    mutable Matrix4F  Proj3DLeft;              // +0x090
    mutable Matrix4F  Proj3DRight;             // +0x0d0
    Matrix2F          User;                    // +0x110
    Matrix2F          User3D;                  // +0x130: User with its translation in view units
    Matrix2F          Orient2D;                // +0x150
    Matrix4F          Orient3D;                // +0x170
    Rect<int>         ViewRectOriginal;        // +0x1b0
    Rect<int>         ViewRect;                // +0x1c0
    Matrix2F          UserView;                // +0x1d0: View2D * User * Orient2D
    mutable Matrix4F  UVPO;                    // +0x1f0
    mutable Matrix4F  ViewRectCompensated3D;   // +0x230
    mutable bool      UVPOChanged;             // +0x270
    bool              OrientationSet;          // +0x271
    StereoParams      S3DParams;               // +0x274
    StereoDisplay     S3DDisplay;              // +0x288

protected:
    void            recalculateUVPOC() const;
    const Matrix4F& updateStereoProjection(float factor = 1.0f) const;
    void            getStereoProjectionMatrix(Matrix4F* left, Matrix4F* right, const Matrix4F& original,
                                              float screenDist, float factor = 1.0f) const;
};

// What a HAL is initialized with (only the fields the base reads are named).
struct HALInitParams
{
    MemoryManager*       pMemoryManager;         // +0x00
    unsigned             ConfigFlags;            // +0x08
    ThreadId             RenderThreadId;         // +0x10
    TextureManager*      pTextureManager;        // +0x18
    RenderBufferManager* pRenderBufferManager;   // +0x20
    unsigned             RenderQueueSize;        // +0x28
};

class HAL : public RefCountBase<HAL, StatRender_Mem>
{
public:
    // the state bits of HALState
    enum HALStateFlags
    {
        HS_ModeSet         = 0x0001,
        HS_InFrame         = 0x0002,   // between BeginFrame and EndFrame
        HS_InScene         = 0x0004,   // between BeginScene and EndScene
        HS_InDisplay       = 0x0008,
        HS_InRenderTarget  = 0x0010,
        HS_ViewValid       = 0x0020,   // the clipped viewport is not empty
        HS_DrawingMask     = 0x0040,
        HS_DrawingFilter   = 0x0080,
        HS_CachedFilter    = 0x0100,   // drawing a filter from its cached results
        HS_SceneInDisplay  = 0x0200,   // the scene was begun by the display and ends with it
        HS_ReadyForReset   = 0x2000
    };

    // per-frame counters (0x18 bytes)
    struct Stats
    {
        unsigned Primitives, Meshes, Triangles, Masks, RTChanges, Filters;

        Stats() { Clear(); }
        void Clear()
        {
            Primitives = 0; Meshes = 0; Triangles = 0;
            Masks = 0; RTChanges = 0; Filters = 0;
        }
    };

    // a mask on the stack, with the view it replaced (0x20 bytes)
    struct MaskStackEntry
    {
        Ptr<MaskPrimitive> pPrimitive;
        bool               OldViewportValid;
        Rect<int>          OldViewRect;
    };
    // a render target on the stack, with the matrices and viewport to go back to (0x2e0 bytes)
    struct RenderTargetEntry
    {
        Ptr<RenderTarget> pRenderTarget;
        MatrixState       OldMatrixState;   // +0x10
        Rect<int>         OldViewRect;      // +0x2a0
        Viewport          OldViewport;      // +0x2b0
    };
    // a filter on the stack and the target its contents go to (0x10 bytes)
    struct FilterStackEntry
    {
        Ptr<FilterPrimitive> pPrimitive;
        Ptr<RenderTarget>    pRenderTarget;
    };
    // a BeginDisplay queued while a scene is open (0x40 bytes)
    struct BeginDisplayData : public ListNode<BeginDisplayData>
    {
        BeginDisplayData(Color bg, const Viewport& vp) : BackgroundColor(bg), VP(vp) {}

        Color    BackgroundColor;   // +0x10
        Viewport VP;                // +0x14
    };
    // the empty profile mode state of this build
    struct ProfileViews
    {
        Color GetClearColor(Color c) const { return c; }   // the SDK's non-profiling build
    };

    HAL(ThreadCommandQueue* commandQueue = 0);   // 0x1426beb60
    // slot 0: the implicit virtual destructor (no vtable re-store; deleting dtor 0x1426bf870)
    virtual bool IsInitialized() const { return (HALState & HS_ModeSet) != 0; }                    // 1
    virtual bool BeginFrame();                                                                     // 2
    virtual void EndFrame();                                                                       // 3
    virtual void Flush();                                                                          // 4
    virtual bool BeginScene();                                                                     // 5
    virtual bool EndScene();                                                                       // 6
    virtual void beginDisplay(BeginDisplayData* data);                                             // 7
    virtual void endDisplay();                                                                     // 8
    virtual void SetUserMatrix(const Matrix2F& userMatrix);                                        // 9
    virtual Matrix2F GetOrientationMatrix() const { return Matrices.Orient2D; }                    // 10
    virtual void updateViewport() = 0;                                                             // 11
    virtual void clearSolidRectangle(const Rect<int>& r, Color color) = 0;                         // 12
    virtual RenderBufferManager* GetRenderBufferManager() const { return pRenderBufferManager; }   // 13
    virtual RenderTarget* GetDefaultRenderTarget()                                                 // 14
    {
        return RenderTargetStack.GetSize() ? RenderTargetStack[0].pRenderTarget.GetPtr() : 0;
    }
    virtual RenderTarget* CreateRenderTarget(Texture* texture, bool needsStencil) = 0;              // 15
    virtual RenderTarget* CreateTempRenderTarget(const ImageSize& size, bool needsStencil) = 0;    // 16
    virtual bool SetRenderTarget(RenderTarget* target, bool setState = 1) = 0;                     // 17
    virtual void PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags = 0) = 0;  // 18
    virtual void PopRenderTarget() = 0;                                                            // 19 (no flags in this build)
    virtual bool createDefaultRenderBuffer() = 0;                                                  // 20
    virtual void destroyRenderBuffers();                                                           // 21
    virtual PrimitiveFill* CreatePrimitiveFill(const PrimitiveFillData& data) = 0;                 // 22
    virtual bool IsPrepassRequired() const { return false; }                                       // 23
    virtual void SetDisplayPass(DisplayPass pass) { CurrentPass = pass; }                          // 24
    virtual DisplayPass GetDisplayPass() const { return CurrentPass; }                             // 25
    virtual void DrawBundleEntries(BundleIterator ibundles, Renderer2DImpl* r2d);                  // 26
    // (named for sfr_render_07q) queues the item for drawing
    virtual void Draw(const RenderQueueItem& item);                                                // 27
    // (named for sfr_render_07p) draws the prepared batches [start, end) of a primitive
    virtual void DrawProcessedPrimitive(Primitive* p, PrimitiveBatch* start, PrimitiveBatch* end) = 0;   // 28
    virtual void DrawProcessedComplexMeshes(ComplexMesh* p,
                                            const StrideArray<MatrixPoolImpl::HMatrix>& matrices) = 0;   // 29
    // (named for sfr_render_07q) a mask: push it and draw its areas into the stencil, then draw clipped by it
    virtual void PushMask_BeginSubmit(MaskPrimitive* primitive) = 0;                              // 30
    virtual void EndMaskSubmit() = 0;                                                             // 31
    virtual void PopMask() = 0;                                                                   // 32
    virtual void PushBlendMode(BlendMode mode);                                                   // 33
    virtual void PopBlendMode();                                                                  // 34
    virtual void applyBlendMode(BlendMode mode, bool sourceAc = false, bool forceAc = false) = 0;  // 35
    virtual void PrepareFilters(FilterPrimitive* primitive);                                      // 36
    virtual void PushFilters(FilterPrimitive* primitive) { SF_UNUSED(primitive); }                // 37
    virtual void PopFilters();                                                                    // 38
    virtual void drawUncachedFilter(const FilterStackEntry& e) { SF_UNUSED(e); }                  // 39
    virtual void drawCachedFilter(FilterPrimitive* primitive) { SF_UNUSED(primitive); }           // 40
    virtual unsigned DrawableCommandGetFlags(const DICommand* command) const;                     // 41
    // the DrawableImage operations drawn through the HAL (sources in tex, their texture matrices in texgen); the
    // base draws nothing
    virtual void DrawableCxform(Texture** tex, const Matrix2F* texgen, const Cxform* cx) {}                 // 42
    virtual void DrawableCompare(Texture** tex, const Matrix2F* texgen) {}                                  // 43
    virtual void DrawableCopyChannel(Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul) {}       // 44
    virtual void DrawableMerge(Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul) {}             // 45
    virtual void DrawableCopyPixels(Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp,
                                    bool mergeAlpha, bool destAlpha) {}                                     // 46
    virtual void DrawablePaletteMap(Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp,
                                    unsigned channelMask, const UInt32* values) {}                          // 47
    // op is a DrawableImage::OperationType
    virtual void DrawableThreshold(Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, unsigned op,
                                   UInt32 threshold, UInt32 color, UInt32 mask, bool copySource) {}        // 48
    virtual void DrawableCopyback(Texture* tex, const Matrix2F& mvp, const Matrix2F& texgen) {}             // 49
    virtual void GetStats(Stats* pstats, bool clear = true)                                       // 50
    {
        *pstats = AccumulatedStats;
        if (clear)
            AccumulatedStats.Clear();
    }
    virtual RenderEvent& GetEvent(EventType type);                                                // 51
    virtual TextureManager* GetTextureManager() = 0;                                              // 52
    virtual MeshCache& GetMeshCache() = 0;                                                        // 53
    virtual RQCacheInterface& GetRQCacheInterface() { return QueueProcessor.GetQueueCachesRef(); }  // 54
    virtual RenderQueueProcessor& GetRQProcessor() { return QueueProcessor; }                     // 55
    // the hardware vertex formats a fill is drawn with: plain, batched and instanced
    virtual void MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                                 const VertexFormat** single, const VertexFormat** batch,
                                 const VertexFormat** instanced, unsigned meshType) = 0;          // 56
    virtual void SetProfileViews(UInt64 modes) { NextProfileMode = modes; }                       // 57
    virtual void SetStereoParams(StereoParams sParams);                                           // 58
    virtual void SetStereoDisplay(StereoDisplay sDisplay, bool setstate = 0)                      // 59
    {
        SF_UNUSED(setstate);
        Matrices.S3DDisplay  = sDisplay;
        Matrices.UVPOChanged = 1;
    }
    // the y scale of a render target pass (the HALs differ in the direction of y)
    virtual float GetViewportScaling() const { return -1.0f; }                                    // 60
    virtual void beginMaskDisplay() { HALState &= ~HS_DrawingMask; }                              // 61
    virtual void endMaskDisplay();                                                                // 62

    unsigned GetHALState() const { return HALState; }
    // brackets a viewport's drawing; queued behind the open scene's items when called inside one
    void     BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void     EndDisplay();

    void PushView3D(const Matrix3F& m)
    {
        Matrices.View3D.Set(&m.M[0][0], 12);
        Matrices.UVPOChanged = 1;
        ViewMatrix3DStack.PushBack(m);
    }
    void PopView3D()
    {
        ViewMatrix3DStack.PopBack();
        const Matrix3F& top = ViewMatrix3DStack.GetSize() ? ViewMatrix3DStack.Back() : Matrix3F::Identity;
        Matrices.View3D.Set(&top.M[0][0], 12);
        Matrices.UVPOChanged = 1;
    }
    void PushProj3D(const Matrix4F& m)
    {
        Matrices.Proj3D      = m;
        Matrices.UVPOChanged = 1;
        ProjectionMatrix3DStack.PushBack(m);
    }
    void PopProj3D()
    {
        ProjectionMatrix3DStack.PopBack();
        Matrices.Proj3D      = ProjectionMatrix3DStack.GetSize() ? ProjectionMatrix3DStack.Back() : Matrix4F::Identity;
        Matrices.UVPOChanged = 1;
    }

protected:
    bool initHAL(const HALInitParams& params);
    bool shutdownHAL();
    // tells every registered HALNotify of a HAL event (0x142742580)
    void notifyHandlers(HALNotifyType type);

public:
    unsigned                     HALState;              // +0x010
    DisplayPass                  CurrentPass;           // +0x014
    List<HALNotify>              NotifyList;            // +0x018
    MatrixState                  Matrices;              // +0x030
    ProfileViews                 Profiler;              // +0x2c0
    Stats                        AccumulatedStats;      // +0x2c4
    unsigned                     VMCFlags;              // +0x2dc
    ThreadId                     RenderThreadID;        // +0x2e0
    MemoryHeap*                  pHeap;                 // +0x2e8
    ThreadCommandQueue*          pRTCommandQueue;       // +0x2f0
    RenderQueue                  Queue;                 // +0x2f8
    Ptr<RenderBufferManager>     pRenderBufferManager;  // +0x318
    RenderQueueProcessor         QueueProcessor;        // +0x320
    ArrayLH<Matrix3F, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> >          ViewMatrix3DStack;         // +0x468
    ArrayLH<Matrix4F, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> >          ProjectionMatrix3DStack;   // +0x480
    ArrayLH<BlendMode, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> >         BlendModeStack;            // +0x498
    ArrayLH<MaskStackEntry, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> >    MaskStack;                 // +0x4b0
    unsigned                     MaskStackTop;          // +0x4c8
    ArrayLH<RenderTargetEntry, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> > RenderTargetStack;         // +0x4d0
    ArrayLH<FilterStackEntry, Stat_Default_Mem, ArrayConstPolicy<0, 8, true> >  FilterStack;               // +0x4e8
    int                          CachedFilterIndex;     // +0x500
    int                          CachedFilterPrepIndex; // +0x504
    ListAllocLH_POD<BeginDisplayData, 127>              BeginDisplayDataList;      // +0x508
    Viewport                     VP;                    // +0x530, the viewport of the current display
    Rect<int>                    ViewRect;              // +0x55c, VP clipped
    UInt64                       NextProfileMode;       // +0x570
};

}} // namespace Scaleform::Render

#endif
