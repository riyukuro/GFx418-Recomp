// Recovered Scaleform 4.1.18 Render: the D3D9 HAL (D3D9_HAL / D3D9_HALSetup sections of sfr_d3d9_01). Written from the
// exe; names from the SDK headers.
// Layout (0xa790 bytes) from the ctor 0x14272dc10 and the dtor 0x14272e650; vftable 0x14319d760. So far only the data
// the shader unit (sfr_d3d9_01d) reads is typed; the HAL's own methods come with its unit.
#ifndef MS2_SF_RENDER_D3D9_HAL_H
#define MS2_SF_RENDER_D3D9_HAL_H

#include <d3d9.h>
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/d3d9_meshcache.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"
#include "ms2/scaleform/include/render/d3d9_shader.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"

namespace Scaleform { namespace Render { namespace D3D9 {

class HAL : public Render::HAL
{
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
    VertexFormat*            MappedXY16iAlphaTexture[PrimitiveBatch::DP_DrawableCount];   // +0xa760
    VertexFormat*            MappedXY16iAlphaSolid[PrimitiveBatch::DP_DrawableCount];     // +0xa778
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
#endif

}}} // namespace Scaleform::Render::D3D9

#endif
