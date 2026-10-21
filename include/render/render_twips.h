// Recovered Scaleform 4.1.18 Render: twips (1/20 pixel) conversions.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TWIPS_H
#define MS2_SF_RENDER_TWIPS_H

namespace Scaleform { namespace Render {

inline float TwipsToPixels(float x) { return x * 0.05f; }
inline float PixelsToTwips(float x) { return x * 20.0f; }

}} // namespace Scaleform::Render

#endif
