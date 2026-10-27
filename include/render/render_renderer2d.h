// Recovered Scaleform 4.1.18 Render: Renderer2D, the public front end of the 2D renderer (Renderer2D), and
// Renderer2DImpl it forwards to, with its full member layout (size 0xe60, the allocation in Renderer2D::Renderer2D);
// Renderer2DImpl's own members are recovered in unit sfr_render_04p.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_RENDERER2D_H
#define MS2_SF_RENDER_RENDERER2D_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_context.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_textlayertype.h"
// (appended for sfr_render_04p: Renderer2DImpl's members)
#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_toleranceparams.h"
#include "ms2/scaleform/include/render/render_viewport.h"

namespace Scaleform { namespace Render {

class HAL;
class TreeRoot;
class Viewport;
class MeshCacheConfig;
struct ToleranceParams;
class PrimitiveFillManager;
class MeshKeyManager;
class FontCacheHandle;
struct GlyphCacheParams;
class Renderer2DImpl;
// (appended for sfr_render_07o) the glyph cache's text side
class Font;
class GlyphRaster;
class Image;
class PrimitiveFill;
class TextureManager;
class TextMeshProvider;
struct GlyphParam;
struct GlyphNode;
struct GlyphRunData;
struct VectorGlyphShape;
class GlyphQueue;
namespace MatrixPoolImpl { class MatrixPool; }
struct MeshGenerator;

// a cache whose buffers the renderer unlocks after a frame (Render_Primitive)
class CacheBase
{
public:
    virtual ~CacheBase() {}
    virtual void UnlockBuffers() = 0;
};

// (appended for sfr_render_04f) mesh cache sizing; only the batching limit is read so far
struct MeshCacheParams
{
    UPInt    MemReserve;
    UPInt    MemLimit;
    UPInt    MemGranularity;
    UPInt    LRUTailSize;
    UPInt    StagingBufferSize;
    UPInt    VBLockEvictSizeLimit;
    unsigned MaxBatchInstances;      // +0x30, meshes one instanced batch may hold
    unsigned InstancingThreshold;
    unsigned NoBatchVerticesSizeThreshold;
    unsigned MaxVerticesSizeInBatch;
    unsigned MaxIndicesInBatch;

    MeshCacheParams() { }
    // copied field by field, as the exe's MeshCache ctor does
    MeshCacheParams(const MeshCacheParams& o)
        : MemReserve(o.MemReserve), MemLimit(o.MemLimit), MemGranularity(o.MemGranularity),
          LRUTailSize(o.LRUTailSize), StagingBufferSize(o.StagingBufferSize),
          VBLockEvictSizeLimit(o.VBLockEvictSizeLimit), MaxBatchInstances(o.MaxBatchInstances),
          InstancingThreshold(o.InstancingThreshold), NoBatchVerticesSizeThreshold(o.NoBatchVerticesSizeThreshold),
          MaxVerticesSizeInBatch(o.MaxVerticesSizeInBatch), MaxIndicesInBatch(o.MaxIndicesInBatch)
    {
    }
};

class MeshCacheConfig
{
public:
    virtual ~MeshCacheConfig() {}
    virtual bool                   SetParams(const MeshCacheParams& params) = 0;
    virtual const MeshCacheParams& GetParams() const = 0;
    virtual void                   ClearCache() = 0;
};

// the HAL's mesh cache (CacheBase at +0, MeshCacheConfig at +8), recovered in render_meshcache.h
class MeshCache;

}} // namespace Scaleform::Render

// the glyph cache's settings and GlyphCacheConfig (shared with the gfx tree)
#include "ms2/scaleform/include/render/render_glyphcacheconfig.h"

namespace Scaleform { namespace Render {

// the glyph cache (Render_GlyphCache, unit sfr_render_06d) is recovered in render_glyphcache.h; its GlyphCacheConfig
// sits at +0x18
class GlyphCache;

enum DisplayPass
{
    Display_Prepass = 0x0001,
    Display_Final   = 0x0002,
    Display_All     = 0x0003
};

enum HALNotifyType
{
    HAL_Initialize,
    HAL_Shutdown,
    HAL_PrepareForReset,
    HAL_RestoreAfterReset,
    HAL_FinalPassBegin
};

// Installed on a HAL to hear about device events (overridden by Renderer2DImpl).
class HALNotify : public ListNode<HALNotify>
{
public:
    HALNotify() { pPrev = pNext = 0; }
    virtual ~HALNotify() {}
    virtual void OnHALEvent(HALNotifyType type) = 0;
};

class Renderer2D : public RefCountBase<Renderer2D, StatRender_Mem>
{
    Renderer2DImpl* pImpl;
    void* getThis() { return this; }

public:
    Renderer2D(HAL* hal);
    ~Renderer2D();

    Renderer2DImpl*        GetImpl() const { return pImpl; }
    Context::RenderNotify* GetContextNotify() const;
    HAL*                   GetHAL() const;
    MeshCacheConfig*       GetMeshCacheConfig() const;
    GlyphCacheConfig*      GetGlyphCacheConfig() const;
    const ToleranceParams& GetToleranceParams() const;
    void                   SetToleranceParams(const ToleranceParams& params);

    bool BeginFrame();
    void EndFrame();
    bool BeginScene();
    void EndScene();
    void BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void EndDisplay();
    void Display(TreeRoot* root);
    void Display(const DisplayHandle<TreeRoot>& root) { Display(root.GetRenderEntry()); }
};

class Renderer2DImpl : public NewOverrideBase<StatRender_Mem>, public Context::RenderNotify, public HALNotify
{
    // (filled in for sfr_render_04p, Renderer2DImpl) the members the ctor at 0x14263e0f0 builds
    friend class ComplexMesh;

    Ptr<HAL>                      pHal;                     // +0x50
    MeshGenerator                 MeshGen;                  // +0x58
    StrokeGenerator               StrokeGen;                // +0xb00
    ToleranceParams               Tolerances;               // +0xcd8
    PrimitiveFillManager          FillManager;              // +0xd18
    MatrixPoolImpl::MatrixPool    MPool;                    // +0xd40
    Ptr<MeshKeyManager>           pMeshKeyManager;          // +0xdc8
    Ptr<GlyphCache>               pGlyphCache;              // +0xdd0
    GlyphCacheParams              mGlyphCacheParam;         // +0xdd8
    List<ComplexMesh::UpdateNode> mComplexMeshUpdateList;   // +0xe10

    void* getThis() { return this; }

public:
    Renderer2DImpl(HAL* hal);
    ~Renderer2DImpl();

    HAL*        GetHAL() const        { return pHal; }
    // (appended for sfr_render_03f)
    const ToleranceParams& GetToleranceParams() const { return Tolerances; }
    PrimitiveFillManager&  GetPrimitiveFillManager()  { return FillManager; }
    MeshKeyManager*        GetMeshKeyManager() const  { return pMeshKeyManager; }
    // (appended for sfr_render_04h)
    MatrixPoolImpl::MatrixPool& GetMatrixPool() { return MPool; }
    GlyphCache* GetGlyphCache() const { return pGlyphCache; }
    // (appended for sfr_render_07o)
    MeshGenerator* GetMeshGen() { return &MeshGen; }
    // (appended for sfr_render_04p)
    StrokeGenerator* GetStrokeGen() { return &StrokeGen; }
    void SetToleranceParams(const ToleranceParams& params) { Tolerances = params; }

    MeshCacheConfig* GetMeshCacheConfig() const;
    void SetGlyphCacheParam(const GlyphCacheParams& param);

    bool BeginFrame();
    void EndFrame();
    void BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void EndDisplay();
    void Draw(TreeRoot* root);
    // refreshes image fills of every root (or only those of context)
    void ForceUpdateImages(Context* context = 0);

protected:
    Viewport            VP;            // +0xe20, the viewport of the open display
    List<TreeCacheNode> RenderRoots;   // +0xe50

    // (appended for sfr_render_04f) complex meshes with image fills, refreshed when textures change
    void AddComplexMeshToUpdateList(ComplexMesh::UpdateNode& node);   // 0x14263edc0
    void UpdateComplexMeshes();

    virtual void EntryDestroy(Context::Entry*);
    virtual void EntryFlush(Context::Entry*);
    virtual void EntryChanges(Context& context, Context::ChangeBuffer&, bool forceUpdateImages = false);
    virtual void OnHALEvent(HALNotifyType type);
};

}} // namespace Scaleform::Render

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::Renderer2DImpl) == 0xe60, "Renderer2DImpl size");

#endif
