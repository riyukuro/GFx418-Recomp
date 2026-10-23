// Plain-C type vocabulary for the CRI vendor-code units that are transcribed from the decompile (sfr_cri_04..07).
#ifndef MS2_CRI_DECOMP_H
#define MS2_CRI_DECOMP_H

typedef unsigned char cri_u8;
typedef unsigned short cri_u16;
typedef unsigned int cri_u32;
typedef unsigned __int64 cri_u64;
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned __int64 undefined8;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int dword;
typedef __int64 longlong;
typedef unsigned __int64 ulonglong;
typedef unsigned __int64 code(...);

// Argument wrapper for callees whose Ghidra-inferred parameter types disagree with their call sites: any pointer or
// integer converts to one 64-bit register slot (what the x64 convention passes anyway).
struct Any {
    unsigned __int64 v;
    template <class T> Any(T* p) : v((unsigned __int64)p) {}
    Any(char x) : v((unsigned __int64)(__int64)x) {}
    Any(unsigned char x) : v(x) {}
    Any(short x) : v((unsigned __int64)(__int64)x) {}
    Any(unsigned short x) : v(x) {}
    Any(int x) : v((unsigned __int64)(__int64)x) {}
    Any(unsigned int x) : v(x) {}
    Any(long x) : v((unsigned __int64)(__int64)x) {}
    Any(unsigned long x) : v(x) {}
    Any(__int64 x) : v((unsigned __int64)x) {}
    Any(unsigned __int64 x) : v(x) {}
};

#include <emmintrin.h>

// Ghidra's SSE/MMX vocabulary: 128-bit values addressed by byte offset, CONCATnm and the packed shifts.
struct V16 { unsigned char b[16]; };
struct V8 { unsigned char b[8]; };
static inline V16 psraw(V16 v, int n) { V16 r; _mm_storeu_si128((__m128i*)r.b, _mm_srai_epi16(_mm_loadu_si128((const __m128i*)v.b), n)); return r; }

// Field of type T at byte offset off inside the object p points to (p may be a pointer or an address integer).
template <class T, class P> static inline T& CriAt(P p, __int64 off) { return *(T*)((char*)(unsigned __int64)p + off); }

template <class T> struct cri_nr { typedef T t; };
template <class T> struct cri_nr<T&> { typedef T t; };

#define CONCAT11(a, b) ((unsigned short)(((unsigned short)(unsigned char)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) ((unsigned int)(((unsigned int)(unsigned char)(a) << 16) | (unsigned short)(b)))
#define CONCAT13(a, b) ((unsigned int)(((unsigned int)(unsigned char)(a) << 24) | ((unsigned int)(b) & 0xffffff)))
#define CONCAT21(a, b) ((unsigned int)(((unsigned int)(unsigned short)(a) << 8) | (unsigned char)(b)))
#define CONCAT22(a, b) ((unsigned int)(((unsigned int)(unsigned short)(a) << 16) | (unsigned short)(b)))
#define CONCAT31(a, b) ((unsigned int)(((unsigned int)(a) << 8) | (unsigned char)(b)))
#define CONCAT71(a, b) ((unsigned __int64)(((unsigned __int64)(a) << 8) | (unsigned char)(b)))
#define CONCAT44(a, b) ((unsigned __int64)(((unsigned __int64)(unsigned int)(a) << 32) | (unsigned int)(b)))

#endif
