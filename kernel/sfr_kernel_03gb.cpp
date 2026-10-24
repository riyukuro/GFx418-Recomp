// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the generic render buffer
// manager's constructor (Render_BufferGeneric; the rest is sfr_render_07i), which the map places in sfr_kernel_03.
// MS2-UNIT: sfr_kernel_03gb
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a3670-0x1429a36fe .text$mn

#include "ms2/scaleform/include/render/render_buffergeneric.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"

namespace Scaleform { namespace Render { namespace RBGenericImpl {

// No texture manager yet; the reuse limit is worked out from the screen size at Initialize. Every cache list starts
// empty.
// @0x1429a3670
RenderBufferManager::RenderBufferManager(bool requireExactDepthStencil, UPInt memReuseLimit, UPInt memAbsoluteLimit)
    : pTextureManager(0), CtorReuseLimit(memReuseLimit), ReuseLimit(0), AbsoluteLimit(memAbsoluteLimit),
      AllocSize(0), DefImageFormat(Image_None), RequirePow2(false), RequireExactDepthStencil(requireExactDepthStencil)
{
}

}}} // namespace Scaleform::Render::RBGenericImpl

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_7?$RefCountBase@VRenderBufferManager@Render@Scaleform@@$0EL@@Scaleform@@6B@ 0x143183940
// MS2-PIN: ??_7RenderBufferManager@Render@Scaleform@@6B@ 0x1432246d8
// MS2-PIN: ??_7RenderBufferManager@RBGenericImpl@Render@Scaleform@@6B@ 0x143224718
