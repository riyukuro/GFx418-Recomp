// Recovered Scaleform GFx 4.1.18 (MapleStory2.exe KMS2_DEV x64): basic types and compiler macros of the Kernel.
// Our own reconstruction (sfr lane, docs/RECOVERY.md section 2 "Flag profiles"); the configuration is the one the exe was
// built with: Win64, threads on, shipping build (no stats, no AMP, no debug heap info), static library.
#ifndef MS2_SF_KERNEL_TYPES_H
#define MS2_SF_KERNEL_TYPES_H

#include <stddef.h>
#include <limits.h>
#include <float.h>
#include <new>

// ---- configuration of the exe's Scaleform build --------------------------------------------------------------------
#define SF_OS_WIN32
#define SF_CPU_X86_64
#define SF_64BIT_POINTERS
#define SF_CPU_SSE
#define SF_CC_MSVC _MSC_VER
#define SF_ENABLE_THREADS
#define SF_ENABLE_SIMD
#ifndef SF_BUILD_SHIPPING
#define SF_BUILD_SHIPPING
#endif
#ifndef SF_BUILD_STATICLIB
#define SF_BUILD_STATICLIB
#endif

#define SF_LITTLE_ENDIAN 1
#define SF_BIG_ENDIAN    2
#define SF_BYTE_ORDER    SF_LITTLE_ENDIAN

#define SF_IMPORT
#define SF_EXPORT
#define SF_EXPORTC  extern "C"
#define SF_BUILD
#define SF_FASTCALL __fastcall
#define SF_STDCALL  __stdcall
#define SF_CDECL    __cdecl
#define SF_INLINE   __forceinline
#define SF_NOINLINE __declspec(noinline)

#define SF_DEBUG_BREAK ((void)0)
#define SF_ASSERT(p)   ((void)0)

#define SF_UNUSED(a)          (a)
#define SF_UNUSED1(a)         (a)
#define SF_UNUSED2(a, b)      (a); (b)
#define SF_UNUSED3(a, b, c)   (a); (b); (c)
#define SF_UNUSED4(a, b, c, d) (a); (b); (c); (d)

namespace Scaleform {

typedef size_t           UPInt;
typedef ptrdiff_t        SPInt;
typedef char             Char;
typedef char             SInt8;
typedef unsigned char    UInt8;
typedef SInt8            SByte;
typedef UInt8            UByte;
typedef short            SInt16;
typedef unsigned short   UInt16;
typedef long             SInt32;          // Win64: long (mangles as J/K)
typedef unsigned long    UInt32;
typedef __int64          SInt64;
typedef unsigned __int64 UInt64;
typedef double           Double;

namespace BaseTypes {
using Scaleform::UPInt;
using Scaleform::SPInt;
using Scaleform::UByte;
using Scaleform::SByte;
using Scaleform::UInt16;
using Scaleform::SInt16;
using Scaleform::UInt32;
using Scaleform::SInt32;
using Scaleform::UInt64;
using Scaleform::SInt64;
using Scaleform::Double;
}

}  // namespace Scaleform

#define SF_MAX_SINT32 Scaleform::SInt32(INT_MAX)
#define SF_MIN_SINT32 Scaleform::SInt32(INT_MIN)
#define SF_MAX_UINT32 Scaleform::UInt32(UINT_MAX)
#define SF_MAX_SINT   int(SF_MAX_SINT32)
#define SF_MIN_SINT   int(SF_MIN_SINT32)
#define SF_MAX_UINT   unsigned(SF_MAX_UINT32)
#define SF_MAX_SINT64 Scaleform::SInt64(0x7FFFFFFFFFFFFFFF)
#define SF_MIN_SINT64 Scaleform::SInt64(0x8000000000000000)
#define SF_MAX_UINT64 Scaleform::UInt64(0xFFFFFFFFFFFFFFFF)
#define SF_MAX_SPINT  SF_MAX_SINT64
#define SF_MIN_SPINT  SF_MIN_SINT64
#define SF_MAX_UPINT  SF_MAX_UINT64
#define SF_MIN_FLOAT  float(FLT_MIN)
#define SF_MAX_FLOAT  float(FLT_MAX)
#define SF_MIN_DOUBLE Scaleform::Double(DBL_MIN)
#define SF_MAX_DOUBLE Scaleform::Double(DBL_MAX)

#endif
