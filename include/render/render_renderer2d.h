// Recovered Scaleform 4.1.18 Render: Renderer2D, the public front end of the 2D renderer (Renderer2D), and the
// outline of Renderer2DImpl it forwards to. Renderer2DImpl's members (mesh/stroke generators, fill manager, matrix
// pool, glyph cache, ...) are recovered with its own TU (Renderer2DImpl, unit sfr_render_04); until then the class
// carries its exact base classes and size (0xe60, the allocation in Renderer2D::Renderer2D) and the members the
// front end calls.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_RENDERER2D_H
#define MS2_SF_RENDER_RENDERER2D_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_context.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_meshkey.h"

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
namespace MatrixPoolImpl { class MatrixPool; }

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

// the glyph cache's settings interface (Render_GlyphCacheConfig)
class GlyphCacheConfig
{
public:
    virtual ~GlyphCacheConfig() {}
    virtual bool                    SetParams(const GlyphCacheParams& params) = 0;
    virtual const GlyphCacheParams& GetParams() const = 0;
    virtual void                    ClearCache() = 0;
};

// Outline of the glyph cache (Render_GlyphCache, unit sfr_render_06): its bases only, so a GlyphCache* converts to
// its GlyphCacheConfig (at +0x18).
class GlyphCache : public RefCountBase<GlyphCache, Stat_Default_Mem>, public CacheBase, public GlyphCacheConfig
{
public:
    // (appended for sfr_render_07k) drops the glyphs of a destroyed font, then merges the freed slots
    void CleanUpFont(FontCacheHandle* font);   // 0x1426c4f10
    void MergeCacheSlots();                    // 0x1426c67b0
};

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
    Ptr<HAL>        pHal;                                       // +0x50
    // MeshGen, StrokeGen, Tolerances, FillManager, MPool, pMeshKeyManager: recovered with sfr_render_04
    UByte           Unk_Members[0xcd8 - 0x58];
    // (split for the shape cache nodes, sfr_render_03f: only their offsets are known so far)
    UByte           Unk_Tolerances[0xd18 - 0xcd8];              // ToleranceParams +0xcd8
    UByte           Unk_FillManager[0xdc8 - 0xd18];             // PrimitiveFillManager +0xd18
    MeshKeyManager* pMeshKeyManager;                            // +0xdc8
    Ptr<GlyphCache> pGlyphCache;                                // +0xdd0
    // mGlyphCacheParam, the complex mesh update list, VP, RenderRoots
    UByte           Unk_Members2[0xe60 - 0xdd8];

public:
    Renderer2DImpl(HAL* hal);
    ~Renderer2DImpl();

    HAL*        GetHAL() const        { return pHal; }
    // (appended for sfr_render_03f)
    const ToleranceParams& GetToleranceParams() const { return *(const ToleranceParams*)Unk_Tolerances; }
    PrimitiveFillManager&  GetPrimitiveFillManager()  { return *(PrimitiveFillManager*)Unk_FillManager; }
    MeshKeyManager*        GetMeshKeyManager() const  { return pMeshKeyManager; }
    // (appended for sfr_render_04h) the matrix pool, +0xd40 inside the region above
    MatrixPoolImpl::MatrixPool& GetMatrixPool() { return *(MatrixPoolImpl::MatrixPool*)(Unk_FillManager + (0xd40 - 0xd18)); }
    GlyphCache* GetGlyphCache() const { return pGlyphCache; }

    MeshCacheConfig* GetMeshCacheConfig() const;

    bool BeginFrame();
    void EndFrame();
    void BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void EndDisplay();
    void Draw(TreeRoot* root);

protected:
    // (appended for sfr_render_04f) complex meshes with image fills, refreshed when textures change
    friend class ComplexMesh;
    void AddComplexMeshToUpdateList(ComplexMesh::UpdateNode& node);   // 0x14263edc0

    virtual void EntryDestroy(Context::Entry*);
    virtual void EntryFlush(Context::Entry*);
    virtual void EntryChanges(Context& context, Context::ChangeBuffer&, bool forceUpdateImages = false);
    virtual void OnHALEvent(HALNotifyType type);
};

}} // namespace Scaleform::Render

#endif
