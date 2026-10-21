// Recovered Scaleform 4.1.18 kernel: the atomic counter, the critical-section Lock and the Event (Win32 build), as
// the GFx include tree sees them. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The declarations are the kernel ones (ms2/scaleform/kernel/sf_atomic.h, sf_threads.h), so GFx sources can also
// include the render tree (render_image.h) after their GFx headers.
#ifndef MS2_SF_INC_KERNEL_LOCK_H
#define MS2_SF_INC_KERNEL_LOCK_H

#include "sf_types.h"
#include <intrin.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

// AtomicInt and Lock are the kernel sf_atomic.h ones, Event the kernel sf_threads.h one (shared with the render
// include tree).
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_threads.h"

#endif
