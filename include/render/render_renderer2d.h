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

namespace Scaleform { namespace Render {

class HAL;
class TreeRoot;
class Viewport;
class MeshCacheConfig;
struct ToleranceParams;
struct GlyphCacheParams;
class Renderer2DImpl;

// a cache whose buffers the renderer unlocks after a frame (Render_Primitive)
class CacheBase
{
public:
    virtual ~CacheBase() {}
    virtual void UnlockBuffers() = 0;
};

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
    UByte           Unk_Members[0xdd0 - 0x58];
    Ptr<GlyphCache> pGlyphCache;                                // +0xdd0
    // mGlyphCacheParam, the complex mesh update list, VP, RenderRoots
    UByte           Unk_Members2[0xe60 - 0xdd8];

public:
    Renderer2DImpl(HAL* hal);
    ~Renderer2DImpl();

    HAL*        GetHAL() const        { return pHal; }
    GlyphCache* GetGlyphCache() const { return pGlyphCache; }

    MeshCacheConfig* GetMeshCacheConfig() const;

    bool BeginFrame();
    void EndFrame();
    void BeginDisplay(Color backgroundColor, const Viewport& viewport);
    void EndDisplay();
    void Draw(TreeRoot* root);

protected:
    virtual void EntryDestroy(Context::Entry*);
    virtual void EntryFlush(Context::Entry*);
    virtual void EntryChanges(Context& context, Context::ChangeBuffer&, bool forceUpdateImages = false);
    virtual void OnHALEvent(HALNotifyType type);
};

}} // namespace Scaleform::Render

#endif
