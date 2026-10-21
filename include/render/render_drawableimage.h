// Recovered Scaleform 4.1.18 Render: DrawableImage, an image the renderer can draw into. Only the part the
// Render_Image unit needs; the rest lands with its own unit.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_DRAWABLEIMAGE_H
#define MS2_SF_RENDER_DRAWABLEIMAGE_H

#include "ms2/scaleform/include/render/render_image.h"

namespace Scaleform { namespace Render {

class DrawableImage : public Image
{
    friend class Texture;
protected:
    void unmapTextureRT();   // exe 0x1425f0590 (Render_DrawableImage)
};

}} // namespace Scaleform::Render

#endif
