// Recovered Scaleform 4.1.18 Render: memory stat ids of the renderer group (StatGroup_Renderer = 64). The values
// are the template arguments seen in the exe's RefCountBase<..., N> instantiations (Renderer2D 65, Context 72,
// TextureManager 75).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_STATS_H
#define MS2_SF_RENDER_STATS_H

#include "ms2/scaleform/kernel/sf_stats.h"

namespace Scaleform { namespace Render {

enum RenderStatId
{
    StatRender_Default = StatGroup_Renderer,
    StatRender_Mem,
    StatRender_Buffers_Mem,
    StatRender_RenderBatch_Mem,
    StatRender_Primitive_Mem,
    StatRender_Fill_Mem,
    StatRender_Mesh_Mem,
    StatRender_MeshBatch_Mem,
    StatRender_Context_Mem,
    StatRender_NodeData_Mem,
    StatRender_TreeCache_Mem,
    StatRender_TextureManager_Mem,
    StatRender_MatrixPool_Mem,
    StatRender_MatrixPoolHandle_Mem,
    StatRender_Text_Mem,
    StatRender_Font_Mem
};

}} // namespace Scaleform::Render

#endif
