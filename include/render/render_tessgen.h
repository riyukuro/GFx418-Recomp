// Recovered Scaleform 4.1.18 Render: the stroke generator the bound / hit-test templates take (Render_TessGen), only
// as far as the recovered units use it: its two linear heaps (the stroker, the stroke sorter and the vertex path that
// follow them come with the stroker units).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TESSGEN_H
#define MS2_SF_RENDER_TESSGEN_H

#include "ms2/scaleform/include/render/render_containers.h"

namespace Scaleform { namespace Render {

// Scratch state for turning strokes into outlines; Heap1 serves the stroker and the path, Heap2 the sorter.
struct StrokeGenerator
{
    LinearHeap Heap1;   // +0x00
    LinearHeap Heap2;   // +0x28
};

}} // namespace Scaleform::Render

#endif
