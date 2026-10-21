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
typedef unsigned int        UInt32;
typedef signed int          SInt32;
typedef unsigned __int64    UInt64;
typedef signed __int64      SInt64;
typedef size_t              UPInt;
typedef ptrdiff_t           SPInt;

} // namespace Scaleform

#define SF_INLINE           inline
#define SF_STDCALL
#define SF_CDECL            __cdecl
#define SF_ASSERT(x)        ((void)0)
#define SF_UNUSED(a)        ((void)(a))
#define SF_UNUSED2(a, b)    ((void)(a), (void)(b))

#endif
