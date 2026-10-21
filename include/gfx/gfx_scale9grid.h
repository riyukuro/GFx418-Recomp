// Recovered Scaleform 4.1.18 GFx: the 9-slice scaling grid of a button or sprite definition.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_SCALE9GRID_H
#define MS2_SF_GFX_SCALE9GRID_H

#include "../kernel/sf_memory.h"
#include "../render/render_types2d.h"

namespace Scaleform { namespace GFx {

using Render::RectF;

struct Scale9Grid : public NewOverrideBase<Stat_Default_Mem>
{
    RectF Rect;
};

}} // namespace Scaleform::GFx

#endif
