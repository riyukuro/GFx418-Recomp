// Recovered Scaleform 4.1.18 kernel: the SSE vector helpers the x64 build uses for its 2D math (Matrix2F, Cxform).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INC_KERNEL_SIMD_H
#define MS2_SF_INC_KERNEL_SIMD_H

#include <xmmintrin.h>
#include <emmintrin.h>

namespace Scaleform { namespace SIMD {

typedef __m128  Vector4f;
typedef __m128i Vector4i;

// Bit-pattern vector (lanes a, b, c, d); each pattern is one writable function-local static in the exe (.data).
template<unsigned a, unsigned b, unsigned c, unsigned d>
inline Vector4f BitMask()
{
#if defined(__clang__)
    // clang's __m128i is two 64-bit lanes
    static Vector4i bits = { (long long)(a | ((unsigned long long)b << 32)), (long long)(c | ((unsigned long long)d << 32)) };
#else
    static Vector4i bits = {
        (char)(a & 0xFF), (char)((a >> 8) & 0xFF), (char)((a >> 16) & 0xFF), (char)(a >> 24),
        (char)(b & 0xFF), (char)((b >> 8) & 0xFF), (char)((b >> 16) & 0xFF), (char)(b >> 24),
        (char)(c & 0xFF), (char)((c >> 8) & 0xFF), (char)((c >> 16) & 0xFF), (char)(c >> 24),
        (char)(d & 0xFF), (char)((d >> 8) & 0xFF), (char)((d >> 16) & 0xFF), (char)(d >> 24)
    };
#endif
    return _mm_load_ps(reinterpret_cast<const float*>(&bits));
}

// Broadcasts lane i of v.
template<int i>
inline Vector4f Splat(Vector4f v) { return _mm_shuffle_ps(v, v, _MM_SHUFFLE(i, i, i, i)); }

inline Vector4f Add(Vector4f a, Vector4f b) { return _mm_add_ps(a, b); }
inline Vector4f Mul(Vector4f a, Vector4f b) { return _mm_mul_ps(a, b); }
inline Vector4f MulAdd(Vector4f a, Vector4f b, Vector4f c) { return _mm_add_ps(_mm_mul_ps(a, b), c); }

}} // namespace Scaleform::SIMD

#endif
