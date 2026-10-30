// Recovered Scaleform 4.1.18 GFx: the 9-slice scaling grid of a button or sprite definition.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_SCALE9GRID_H
#define MS2_SF_GFX_SCALE9GRID_H

#include "../kernel/sf_memory.h"
#include "../render/render_types2d.h"

namespace Scaleform { namespace GFx {

using Render::RectF;

// Allocated under StatMD_CharDefs_Mem (0x102, gfx_characterdef.h), as in the SDK and the exe's DefineScalingGrid loader.
struct Scale9Grid : public NewOverrideBase<0x102>
{
    RectF Rect;

    Scale9Grid() : Rect(0) {}
    Scale9Grid(const RectF& r) : Rect(r) {}

    Scale9Grid& operator=(const RectF& r) { Rect = r; return *this; }
};

}} // namespace Scaleform::GFx

#endif
