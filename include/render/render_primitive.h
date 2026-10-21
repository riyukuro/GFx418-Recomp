// Recovered Scaleform 4.1.18 Render: primitive fills. Only what the recovered units call so far: the fill manager
// keeps a cache of gradient images and a GradientImage unregisters itself on destruction.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVE_H
#define MS2_SF_RENDER_PRIMITIVE_H

#include "ms2/scaleform/include/render/render_gradients.h"

namespace Scaleform { namespace Render {

class PrimitiveFillManager
{
    friend class GradientImage;
    void removeGradient(GradientImage* img);    // 0x14266f380 (Render_Primitive)
};

}} // namespace Scaleform::Render

#endif
