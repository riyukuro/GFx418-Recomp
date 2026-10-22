// Recovered Scaleform 4.1.18 Render: twips (1/20 pixel) conversions.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TWIPS_H
#define MS2_SF_RENDER_TWIPS_H

namespace Scaleform { namespace Render {

inline float TwipsToPixels(float x) { return x * 0.05f; }
inline float PixelsToTwips(float x) { return x * 20.0f; }

// (appended for the display objects, sfr_gfx_06) the double versions the AS property getters use
inline double TwipsToPixels(double x) { return x * 0.05; }
inline double PixelsToTwips(double x) { return x * 20.0; }

}} // namespace Scaleform::Render

// (appended for flash.geom, sfr_as3_11) a point, coordinate by coordinate
#include "ms2/scaleform/include/render/render_types2d.h"
namespace Scaleform { namespace Render {
// (a template without inline, taking the point by value, scaled as a point times the point (20, 20))
template<class T> Point<T> PixelsToTwips(Point<T> p) { return Point<T>(p * Point<T>(T(20.))); }

}} // namespace Scaleform::Render

#endif
