// Recovered Scaleform 4.1.18 Render: the D3D9 HAL (D3D9_HAL / D3D9_HALSetup sections of sfr_d3d9_01). Written from the
// exe; names from the SDK headers.
// Layout (0xa790 bytes) from the ctor 0x14272dc10 and the dtor 0x14272e650; vftable 0x14319d760 (69 slots: the base's
// 0-62, then InitHAL .. drawScreenQuad). Setup / reset / scene / viewport: sfr_d3d9_01f; shaders: sfr_d3d9_01d.
#ifndef MS2_SF_RENDER_D3D9_HAL_H
#define MS2_SF_RENDER_D3D9_HAL_H

#include <d3d9.h>
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/d3d9_meshcache.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/d3d9_shader.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"

namespace Scaleform { namespace Render { namespace D3D9 {

// What a D3D9 HAL is initialized with: the device and the presentation parameters it was created with.
struct HALInitParams : public Render::HALInitParams
{
    IDirect3DDevice9*     pD3DDevice;      // +0x30
    D3DPRESENT_PARAMETERS PresentParams;   // +0x38
};

class HAL : public Render::HAL
{
public:
    HAL(ThreadCommandQueue* commandQueue = 0);   // 0x14272dc10
    virtual ~HAL();                              // 0x14272e650

    // overrides, by base slot
    virtual bool BeginScene();                                                                   // 5
    virtual bool EndScene();                                                                     // 6
    virtual void updateViewport();                                                               // 11
    virtual void clearSolidRectangle(const Rect<int>& r, Color color);                           // 12
    virtual RenderTarget* CreateRenderTarget(Render::Texture* texture, bool needsStencil);       // 15
    virtual RenderTarget* CreateTempRenderTarget(const ImageSize& size, bool needsStencil);      // 16
    virtual bool SetRenderTarget(RenderTarget* target, bool setState = 1);                       // 17
    virtual void PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags = 0);   // 18
    virtual void PopRenderTarget();                                                              // 19
    virtual bool createDefaultRenderBuffer();                                                    // 20
    virtual PrimitiveFill* CreatePrimitiveFill(const PrimitiveFillData& data);                   // 22
    virtual void DrawProcessedPrimitive(Primitive* p, PrimitiveBatch* start, PrimitiveBatch* end);   // 28
    virtual void DrawProcessedComplexMeshes(ComplexMesh* p,
                                            const StrideArray<MatrixPoolImpl::HMatrix>& matrices);   // 29
    virtual void PushMask_BeginSubmit(MaskPrimitive* primitive);                                 // 30
    virtual void EndMaskSubmit();                                                                // 31
    virtual void PopMask();                                                                      // 32
    virtual void applyBlendMode(BlendMode mode, bool sourceAc = false, bool forceAc = false);    // 35
    virtual void PushFilters(FilterPrimitive* primitive);                                        // 37
    virtual void PopFilters();                                                                   // 38
    virtual void drawUncachedFilter(const FilterStackEntry& e);                                  // 39
    virtual void drawCachedFilter(FilterPrimitive* primitive);                                   // 40
    virtual void DrawableCxform(Render::Texture** tex, const Matrix2F* texgen, const Cxform* cx);             // 42
    virtual void DrawableCompare(Render::Texture** tex, const Matrix2F* texgen);                              // 43
    virtual void DrawableCopyChannel(Render::Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul);   // 44
    virtual void DrawableMerge(Render::Texture** tex, const Matrix2F* texgen, const Matrix4F* cxmul);         // 45
    virtual void DrawableCopyPixels(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp,
                                    bool mergeAlpha, bool destAlpha);                                         // 46
    virtual void DrawablePaletteMap(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp,
                                    unsigned channelMask, const UInt32* values);                              // 47
    virtual void DrawableThreshold(Render::Texture** tex, const Matrix2F* texgen, const Matrix2F& mvp, unsigned op,
                                   UInt32 threshold, UInt32 color, UInt32 mask, bool copySource);             // 48
    virtual void DrawableCopyback(Render::Texture* tex, const Matrix2F& mvp, const Matrix2F& texgen);         // 49
    virtual RenderEvent& GetEvent(EventType type);                                               // 51
    virtual Render::TextureManager* GetTextureManager();                                         // 52
    virtual Render::MeshCache& GetMeshCache();                                                   // 53
    virtual void MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                                 const VertexFormat** single, const VertexFormat** batch,
                                 const VertexFormat** instanced, unsigned meshType);             // 56
    virtual void beginMaskDisplay();                                                             // 61

    // new slots 63-68
    virtual bool InitHAL(const D3D9::HALInitParams& params);                                     // 63
    virtual bool ShutdownHAL();                                                                  // 64
    // around IDirect3DDevice9::Reset: drop the default pool resources, then make them again
    virtual void PrepareForReset();                                                              // 65
    virtual bool RestoreAfterReset();                                                            // 66
    virtual RenderTarget* CreateRenderTarget(IDirect3DSurface9* colorSurface, IDirect3DSurface9* depthSurface);   // 67
    virtual void drawScreenQuad();                                                               // 68

    // the clip-space matrix of a view rectangle, offset by (dx, dy) pixels and shifted half a pixel (D3D9 samples
    // pixel centers)
    void CalcHWViewMatrix(Matrix2F* matrix, const Rect<int>& viewRect, int dx, int dy);   // 0x142741d60

protected:
    bool initializeShaders(bool force);   // 0x1427387f0

public:
    IDirect3DDevice9*        pDevice;                                       // +0x578
    UInt16                   DeviceFlags;                                   // +0x580, this build only
    D3DPRESENT_PARAMETERS    PresentParams;                                 // +0x588
    MeshCache                Cache;                                         // +0x5c8
    ShaderManager            SManager;                                      // +0x8a8
    Ptr<TextureManager>      pTextureManager;                               // +0x8e8
    FragShader               StaticFShaders[FragShaderDesc::FSI_Count];     // +0x8f0
    VertexShader             StaticVShaders[VertexShaderDesc::VSI_Count];   // +0x7370
    ShaderInterface          ShaderData;                                    // +0x95d0
    PrimitiveBatch::BatchType PrevBatchType;                                // +0xa750
    bool                     StencilChecked;                                // +0xa754
    bool                     StencilAvailable;                              // +0xa755
    bool                     MultiBitStencil;                               // +0xa756
    bool                     DepthBufferAvailable;                          // +0xa757
    D3DSTENCILOP             StencilOpInc;                                  // +0xa758
    // the hardware formats of VertexXY16iAlpha for textured / solid fills (single, batch, instanced)
    const VertexFormat*      MappedXY16iAlphaTexture[PrimitiveBatch::DP_DrawableCount];   // +0xa760
    const VertexFormat*      MappedXY16iAlphaSolid[PrimitiveBatch::DP_DrawableCount];     // +0xa778
};

static_assert(sizeof(ShaderInterface) == 0x1180, "D3D9::ShaderInterface size");
static_assert(sizeof(VertexShaderDesc) == 0x140 && sizeof(FragShaderDesc) == 0x100, "D3D9 shader desc size");
static_assert(sizeof(VertexShader) == 0x58 && sizeof(FragShader) == 0x80, "D3D9 shader size");
static_assert(sizeof(SysVertexFormat) == 0x58, "D3D9::SysVertexFormat size");
static_assert(sizeof(ShaderManager) == 0x40, "D3D9::ShaderManager size");
// cl places HAL's own members at the base's unpadded size (0x578); clang-cl rounds the 16-aligned base up to 0x580, so
// the HAL offsets only hold for cl
#if !defined(__clang__)
static_assert(offsetof(HAL, pDevice) == 0x578 && offsetof(HAL, Cache) == 0x5c8, "D3D9::HAL layout");
static_assert(offsetof(HAL, SManager) == 0x8a8 && offsetof(HAL, StaticFShaders) == 0x8f0, "D3D9::HAL layout");
static_assert(offsetof(HAL, StaticVShaders) == 0x7370 && offsetof(HAL, ShaderData) == 0x95d0, "D3D9::HAL layout");
static_assert(offsetof(HAL, PrevBatchType) == 0xa750 && offsetof(HAL, MappedXY16iAlphaSolid) == 0xa778, "D3D9::HAL layout");
static_assert(sizeof(HAL) == 0xa790, "D3D9::HAL size");
static_assert(offsetof(HALInitParams, pD3DDevice) == 0x30 && offsetof(HALInitParams, PresentParams) == 0x38,
              "D3D9::HALInitParams layout");
#endif

}}} // namespace Scaleform::Render::D3D9

#endif
