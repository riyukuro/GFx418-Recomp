// Recovered Scaleform 4.1.18 Render: TextPrimitiveBundle, the bundle that batches the layers of text meshes
// (Render_TextPrimitiveBundle, 0x1426f2460-0x1426f3f20 in sfr_render_07). Outline only so far: what the text mesh
// provider calls when it drops its entry.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXTPRIMITIVEBUNDLE_H
#define MS2_SF_RENDER_TEXTPRIMITIVEBUNDLE_H

#include "ms2/scaleform/include/render/render_bundle.h"

namespace Scaleform { namespace Render {

class TextMeshProvider;

class TextPrimitiveBundle : public Bundle
{
    friend class TextMeshProvider;

    // takes the entry's meshes out of every text layer of the bundle
    void removeEntryFromLayers(BundleEntry* e);   // 0x1426f3bf0
};

}} // namespace Scaleform::Render

#endif
