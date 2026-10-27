// Recovered Scaleform 4.1.18 kernel: basic types and helper macros (sfr lane, written from the exe; x64 only).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_KERNEL_TYPES_H
#define MS2_SF_KERNEL_TYPES_H

#include <stddef.h>
#include <string.h>
#include <new>

namespace Scaleform {

typedef unsigned char       UByte;
typedef signed char         SByte;
typedef unsigned short      UInt16;
typedef signed short        SInt16;
typedef unsigned long       UInt32;     // Win64: long (mangles as K/J), as in the kernel/ tree
typedef signed long         SInt32;
typedef unsigned __int64    UInt64;
typedef signed __int64      SInt64;
typedef size_t              UPInt;
typedef ptrdiff_t           SPInt;

} // namespace Scaleform

#define SF_INLINE           __forceinline   // release build, as the kernel/ tree
#define SF_STDCALL
#define SF_CDECL            __cdecl
#define SF_ASSERT(x)        ((void)0)
#define SF_UNUSED(a)        ((void)(a))
#define SF_UNUSED2(a, b)    ((void)(a), (void)(b))
#define SF_MAX_UPINT        ((UPInt)~(UPInt)0)
#define SF_NOINLINE         __declspec(noinline)
#define SF_FORCEINLINE      __forceinline
// as kernel/sf_types.h: dllexport only in the game's bootstrap TU (unit_141803210, MS2_SF_EXPORT_TU)
#ifndef SF_EXPORT
#ifdef MS2_SF_EXPORT_TU
#define SF_EXPORT __declspec(dllexport)
#else
#define SF_EXPORT
#endif
#endif

// (appended for the static text, sfr_gfx_05d) the names the render text headers (ms2/scaleform/kernel tree) use
namespace Scaleform {
typedef signed char   SInt8; // as gfx_input.h repeats it
typedef unsigned char UInt8;
} // namespace Scaleform
#define SF_UNUSED3(a, b, c) ((void)(a), (void)(b), (void)(c))
#define SF_MAX_UINT         unsigned(0xFFFFFFFFu)

// (appended for the AS3 units, sfr12) 32-bit integer limits; skipped when the ms2/scaleform/kernel tree has them.
#include <limits.h>
#ifndef SF_MAX_SINT32
#define SF_MAX_SINT32 Scaleform::SInt32(INT_MAX)
#define SF_MIN_SINT32 Scaleform::SInt32(INT_MIN)
#define SF_MAX_UINT32 Scaleform::UInt32(UINT_MAX)
#endif
#ifndef SF_UNUSED4
#define SF_UNUSED4(a, b, c, d) ((void)(a), (void)(b), (void)(c), (void)(d))
#endif

#endif
