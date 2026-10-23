// Recovered Scaleform 4.1.18 Render: the stroke generator the bound / hit-test templates take (Render_TessGen), only
// as far as the recovered units use it: its two linear heaps (the stroker, the stroke sorter and the vertex path that
// follow them come with the stroker units).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TESSGEN_H
#define MS2_SF_RENDER_TESSGEN_H

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessellator.h"

namespace Scaleform { namespace Render {

// Scratch state for turning strokes into outlines; Heap1 serves the stroker and the path, Heap2 the sorter.
struct StrokeGenerator
{
    LinearHeap Heap1;   // +0x00
    LinearHeap Heap2;   // +0x28
};

// (appended for sfr_render_07o) the renderer's shared tessellation scratch (Renderer2DImpl +0x58): four linear
// heaps, then the tessellator; the stroker, stroke sorter, hairliner and AA stroker that follow it (+0x608, +0x660,
// +0x730, +0x9d0) stay opaque until their units.
struct MeshGenerator
{
    LinearHeap  Heap1;   // +0x00
    LinearHeap  Heap2;   // +0x28
    LinearHeap  Heap3;   // +0x50
    LinearHeap  Heap4;   // +0x78
    Tessellator mTess;   // +0xa0

    // clears the tessellator and the strokers, then the heaps
    void Clear();        // 0x14262a890
};

}} // namespace Scaleform::Render

#endif
