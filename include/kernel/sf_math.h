// Recovered Scaleform 4.1.18 kernel: math constants and the degree/radian conversions (sfr lane, sfr12).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_KERNEL_MATH_H
#define MS2_SF_KERNEL_MATH_H

#include "sf_types.h"
#include <math.h>

#define SF_MATH_PI          ((double)3.14159265358979323846)
#define SF_DEGTORAD(d)      ((d) * (SF_MATH_PI) / ((double)180.0))
#define SF_RADTODEG(r)      ((r) * ((double)180.0) / (SF_MATH_PI))

#endif
