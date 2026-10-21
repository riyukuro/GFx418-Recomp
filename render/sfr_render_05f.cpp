// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the Matrix4x4 TU
// (Render_Matrix4x4): the SSE forms of the 4x4 float matrix products and of the projected rectangle helpers. The
// rows are read and written unaligned (movups).
// Queue unit sfr_render_05 is split along its original sources (05f Render_Matrix4x4).
// MS2-UNIT: sfr_render_05f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426787e0-0x142679360 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"

namespace Scaleform { namespace Render {

using namespace SIMD;

namespace {

SF_INLINE Vector4f LoadRow(const float* p) { return _mm_loadu_ps(p); }
SF_INLINE void     StoreRow(float* p, Vector4f v) { _mm_storeu_ps(p, v); }

// the x y z dot product in every lane
SF_INLINE Vector4f Dot3(Vector4f a, Vector4f b)
{
    Vector4f p = _mm_mul_ps(a, b);
    return _mm_add_ps(_mm_add_ps(Splat<0>(p), Splat<1>(p)), Splat<2>(p));
}

} // namespace

// rows of the result: each row of m1 spreads over the rows of m2
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142678b10
template<> void Matrix4F::MultiplyMatrix(const Matrix4F& m1, const Matrix4F& m2)
{
    Vector4f a0 = LoadRow(m1.M[0]);
    Vector4f a1 = LoadRow(m1.M[1]);
    Vector4f a2 = LoadRow(m1.M[2]);
    Vector4f a3 = LoadRow(m1.M[3]);

    Vector4f b0 = LoadRow(m2.M[0]);
    Vector4f b1 = LoadRow(m2.M[1]);
    Vector4f b2 = LoadRow(m2.M[2]);
    Vector4f b3 = LoadRow(m2.M[3]);

    Vector4f r0 = Mul(Splat<0>(a0), b0);
    Vector4f r1 = Mul(Splat<0>(a1), b0);
    Vector4f r2 = Mul(Splat<0>(a2), b0);
    Vector4f r3 = Mul(Splat<0>(a3), b0);

    r0 = MulAdd(Splat<1>(a0), b1, r0);
    r1 = MulAdd(Splat<1>(a1), b1, r1);
    r2 = MulAdd(Splat<1>(a2), b1, r2);
    r3 = MulAdd(Splat<1>(a3), b1, r3);

    r0 = MulAdd(Splat<2>(a0), b2, r0);
    r1 = MulAdd(Splat<2>(a1), b2, r1);
    r2 = MulAdd(Splat<2>(a2), b2, r2);
    r3 = MulAdd(Splat<2>(a3), b2, r3);

    r0 = MulAdd(Splat<3>(a0), b3, r0);
    r1 = MulAdd(Splat<3>(a1), b3, r1);
    r2 = MulAdd(Splat<3>(a2), b3, r2);
    r3 = MulAdd(Splat<3>(a3), b3, r3);

    StoreRow(M[0], r0);
    StoreRow(M[1], r1);
    StoreRow(M[2], r2);
    StoreRow(M[3], r3);
}

// a 3x4 on the left: its missing row (0 0 0 1) copies row 3 of m2
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142678f10
template<> void Matrix4F::MultiplyMatrix(const Matrix3F& m1, const Matrix4F& m2)
{
    Vector4f a0 = LoadRow(m1.M[0]);
    Vector4f a1 = LoadRow(m1.M[1]);
    Vector4f a2 = LoadRow(m1.M[2]);

    Vector4f b0 = LoadRow(m2.M[0]);
    Vector4f b1 = LoadRow(m2.M[1]);
    Vector4f b2 = LoadRow(m2.M[2]);
    Vector4f b3 = LoadRow(m2.M[3]);

    Vector4f r0 = Mul(Splat<0>(a0), b0);
    Vector4f r1 = Mul(Splat<0>(a1), b0);
    Vector4f r2 = Mul(Splat<0>(a2), b0);

    r0 = MulAdd(Splat<1>(a0), b1, r0);
    r1 = MulAdd(Splat<1>(a1), b1, r1);
    r2 = MulAdd(Splat<1>(a2), b1, r2);

    r0 = MulAdd(Splat<2>(a0), b2, r0);
    r1 = MulAdd(Splat<2>(a1), b2, r1);
    r2 = MulAdd(Splat<2>(a2), b2, r2);

    r0 = MulAdd(Splat<3>(a0), b3, r0);
    r1 = MulAdd(Splat<3>(a1), b3, r1);
    r2 = MulAdd(Splat<3>(a2), b3, r2);

    StoreRow(M[0], r0);
    StoreRow(M[1], r1);
    StoreRow(M[2], r2);
    StoreRow(M[3], b3);
}

// a 3x4 on the right: the w column of m1 passes through (its missing row is 0 0 0 1)
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142678d20
template<> void Matrix4F::MultiplyMatrix(const Matrix4F& m1, const Matrix3F& m2)
{
    Vector4f wOnly = Constant<0, 0, 0, 0xFFFFFFFF>();

    Vector4f a0 = LoadRow(m1.M[0]);
    Vector4f a1 = LoadRow(m1.M[1]);
    Vector4f a2 = LoadRow(m1.M[2]);
    Vector4f a3 = LoadRow(m1.M[3]);

    Vector4f b0 = LoadRow(m2.M[0]);
    Vector4f b1 = LoadRow(m2.M[1]);
    Vector4f b2 = LoadRow(m2.M[2]);

    Vector4f r0 = Mul(Splat<0>(a0), b0);
    Vector4f r1 = Mul(Splat<0>(a1), b0);
    Vector4f r2 = Mul(Splat<0>(a2), b0);
    Vector4f r3 = Mul(Splat<0>(a3), b0);

    r0 = MulAdd(Splat<1>(a0), b1, r0);
    r1 = MulAdd(Splat<1>(a1), b1, r1);
    r2 = MulAdd(Splat<1>(a2), b1, r2);
    r3 = MulAdd(Splat<1>(a3), b1, r3);

    r0 = MulAdd(Splat<2>(a0), b2, r0);
    r1 = MulAdd(Splat<2>(a1), b2, r1);
    r2 = MulAdd(Splat<2>(a2), b2, r2);
    r3 = MulAdd(Splat<2>(a3), b2, r3);

    r0 = Add(r0, _mm_and_ps(a0, wOnly));
    r1 = Add(r1, _mm_and_ps(a1, wOnly));
    r2 = Add(r2, _mm_and_ps(a2, wOnly));
    r3 = Add(r3, _mm_and_ps(a3, wOnly));

    StoreRow(M[0], r0);
    StoreRow(M[1], r1);
    StoreRow(M[2], r2);
    StoreRow(M[3], r3);
}

// a 2x4 on the left: rows 2 and 3 of m2 are kept
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142678e50
template<> void Matrix4F::MultiplyMatrix(const Matrix2F& m1, const Matrix4F& m2)
{
    Vector4f a0 = LoadRow(m1.M[0]);
    Vector4f a1 = LoadRow(m1.M[1]);

    Vector4f b0 = LoadRow(m2.M[0]);
    Vector4f b1 = LoadRow(m2.M[1]);
    Vector4f b2 = LoadRow(m2.M[2]);
    Vector4f b3 = LoadRow(m2.M[3]);

    Vector4f r0 = Mul(Splat<0>(a0), b0);
    Vector4f r1 = Mul(Splat<0>(a1), b0);

    r0 = MulAdd(Splat<1>(a0), b1, r0);
    r1 = MulAdd(Splat<1>(a1), b1, r1);

    r0 = MulAdd(Splat<2>(a0), b2, r0);
    r1 = MulAdd(Splat<2>(a1), b2, r1);

    r0 = MulAdd(Splat<3>(a0), b3, r0);
    r1 = MulAdd(Splat<3>(a1), b3, r1);

    StoreRow(M[0], r0);
    StoreRow(M[1], r1);
    StoreRow(M[2], b2);
    StoreRow(M[3], b3);
}

// a 2x4 on the right: the z and w columns of m1 pass through
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142678c50
template<> void Matrix4F::MultiplyMatrix(const Matrix4F& m1, const Matrix2F& m2)
{
    Vector4f zwOnly = Constant<0, 0, 0xFFFFFFFF, 0xFFFFFFFF>();

    Vector4f a0 = LoadRow(m1.M[0]);
    Vector4f a1 = LoadRow(m1.M[1]);
    Vector4f a2 = LoadRow(m1.M[2]);
    Vector4f a3 = LoadRow(m1.M[3]);

    Vector4f b0 = LoadRow(m2.M[0]);
    Vector4f b1 = LoadRow(m2.M[1]);

    Vector4f r0 = Mul(Splat<0>(a0), b0);
    Vector4f r1 = Mul(Splat<0>(a1), b0);
    Vector4f r2 = Mul(Splat<0>(a2), b0);
    Vector4f r3 = Mul(Splat<0>(a3), b0);

    r0 = MulAdd(Splat<1>(a0), b1, r0);
    r1 = MulAdd(Splat<1>(a1), b1, r1);
    r2 = MulAdd(Splat<1>(a2), b1, r2);
    r3 = MulAdd(Splat<1>(a3), b1, r3);

    r0 = Add(r0, _mm_and_ps(a0, zwOnly));
    r1 = Add(r1, _mm_and_ps(a1, zwOnly));
    r2 = Add(r2, _mm_and_ps(a2, zwOnly));
    r3 = Add(r3, _mm_and_ps(a3, zwOnly));

    StoreRow(M[0], r0);
    StoreRow(M[1], r1);
    StoreRow(M[2], r2);
    StoreRow(M[3], r3);
}

// the four corners of r projected (divided by w); pr gets their x / y bounds
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x1426787e0
template<> void Matrix4F::EncloseTransformHomogeneous(RectF* pr, const RectF& r) const
{
    Vector4f zero = Constant<0, 0, 0, 0>();

    Vector4f rc = LoadRow(&r.x1);
    Vector4f m0 = LoadRow(M[0]);
    Vector4f m1 = LoadRow(M[1]);
    Vector4f m2 = LoadRow(M[2]);
    Vector4f m3 = LoadRow(M[3]);

    // the translation column as one vector
    Vector4f t01  = _mm_shuffle_ps(m0, m1, _MM_SHUFFLE(3, 3, 3, 3));
    Vector4f t23  = _mm_shuffle_ps(m2, m3, _MM_SHUFFLE(3, 3, 3, 3));
    Vector4f tcol = _mm_shuffle_ps(t01, t23, _MM_SHUFFLE(2, 0, 2, 0));

    Vector4f c0 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 1, 0));   // x1 y1
    Vector4f c1 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 1, 2));   // x2 y1
    Vector4f c2 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 3, 2));   // x2 y2
    Vector4f c3 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 3, 0));   // x1 y2

    Vector4f x, y, z, w;
    Vector4f p0, p1, p2, p3;

    x  = Dot3(c0, m0);
    y  = Dot3(c0, m1);
    z  = Dot3(c0, m2);
    w  = Dot3(c0, m3);
    w  = Add(w, Splat<3>(tcol));
    p0 = _mm_unpacklo_ps(x, y);
    p0 = _mm_shuffle_ps(p0, z, _MM_SHUFFLE(0, 0, 1, 0));
    p0 = Add(p0, tcol);
    p0 = _mm_div_ps(p0, w);

    x  = Dot3(c1, m0);
    y  = Dot3(c1, m1);
    z  = Dot3(c1, m2);
    w  = Dot3(c1, m3);
    w  = Add(w, Splat<3>(tcol));
    p1 = _mm_unpacklo_ps(x, y);
    p1 = _mm_shuffle_ps(p1, z, _MM_SHUFFLE(0, 0, 1, 0));
    p1 = Add(p1, tcol);
    p1 = _mm_div_ps(p1, w);

    x  = Dot3(c2, m0);
    y  = Dot3(c2, m1);
    z  = Dot3(c2, m2);
    w  = Dot3(c2, m3);
    w  = Add(w, Splat<3>(tcol));
    p2 = _mm_unpacklo_ps(x, y);
    p2 = _mm_shuffle_ps(p2, z, _MM_SHUFFLE(0, 0, 1, 0));
    p2 = Add(p2, tcol);
    p2 = _mm_div_ps(p2, w);

    x  = Dot3(c3, m0);
    y  = Dot3(c3, m1);
    z  = Dot3(c3, m2);
    w  = Dot3(c3, m3);
    w  = Add(w, Splat<3>(tcol));
    p3 = _mm_unpacklo_ps(x, y);
    p3 = _mm_shuffle_ps(p3, z, _MM_SHUFFLE(0, 0, 1, 0));
    p3 = Add(p3, tcol);
    p3 = _mm_div_ps(p3, w);

    Vector4f lo = _mm_min_ps(p0, p1);
    lo = _mm_min_ps(lo, p2);
    lo = _mm_min_ps(lo, p3);
    Vector4f hi = _mm_max_ps(p0, p1);
    hi = _mm_max_ps(hi, p2);
    hi = _mm_max_ps(hi, p3);

    StoreRow(&pr->x1, _mm_shuffle_ps(lo, hi, _MM_SHUFFLE(1, 0, 1, 0)));
}

// three corners of r projected and mapped from clip space (-1..1, y up) to a w x h viewport (y down); dest gets
// x1y1, x2y1, x2y2 as pairs (the last pair is padding)
// MS2-FUNCTIONAL: SSE register save scheduling (xmm6+ saved at another point in the prolog; same instructions)
// @0x142679010
template<> void Matrix4F::TransformHomogeneousAndScaleCorners(const RectF& r, float sx, float sy, float* dest) const
{
    __declspec(align(16)) float scale[4];
    scale[0] = sx;
    scale[1] = sy;
    Vector4f sxsy = _mm_load_ps(scale);
    sxsy = _mm_shuffle_ps(sxsy, sxsy, _MM_SHUFFLE(1, 0, 1, 0));

    Vector4f zero   = Constant<0, 0, 0, 0>();
    Vector4f flipY  = Constant<0x3F800000, 0xBF800000, 0x3F800000, 0xBF800000>();
    Vector4f ones   = Constant<0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000>();
    Vector4f halves = Constant<0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000>();

    Vector4f rc = LoadRow(&r.x1);
    Vector4f m0 = LoadRow(M[0]);
    Vector4f m1 = LoadRow(M[1]);
    Vector4f m2 = LoadRow(M[2]);
    Vector4f m3 = LoadRow(M[3]);

    Vector4f t01  = _mm_shuffle_ps(m0, m1, _MM_SHUFFLE(3, 3, 3, 3));
    Vector4f t23  = _mm_shuffle_ps(m2, m3, _MM_SHUFFLE(3, 3, 3, 3));
    Vector4f tcol = _mm_shuffle_ps(t01, t23, _MM_SHUFFLE(2, 0, 2, 0));

    Vector4f c0 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 1, 0));
    Vector4f c1 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 1, 2));
    Vector4f c2 = _mm_shuffle_ps(rc, zero, _MM_SHUFFLE(0, 0, 3, 2));

    Vector4f x, y, z, w;
    Vector4f p0, p1, p2;

    Vector4f tw = Splat<3>(tcol);
    x  = Dot3(c0, m0);
    y  = Dot3(c0, m1);
    z  = Dot3(c0, m2);
    w  = Dot3(c0, m3);
    w  = Add(w, tw);
    p0 = _mm_unpacklo_ps(x, y);
    p0 = _mm_shuffle_ps(p0, z, _MM_SHUFFLE(0, 0, 1, 0));
    p0 = Add(p0, tcol);
    p0 = _mm_div_ps(p0, w);

    x  = Dot3(c1, m0);
    y  = Dot3(c1, m1);
    z  = Dot3(c1, m2);
    w  = Dot3(c1, m3);
    w  = Add(w, tw);
    p1 = _mm_unpacklo_ps(x, y);
    p1 = _mm_shuffle_ps(p1, z, _MM_SHUFFLE(0, 0, 1, 0));
    p1 = Add(p1, tcol);
    p1 = _mm_div_ps(p1, w);

    x  = Dot3(c2, m0);
    y  = Dot3(c2, m1);
    z  = Dot3(c2, m2);
    w  = Dot3(c2, m3);
    w  = Add(w, tw);
    p2 = _mm_unpacklo_ps(x, y);
    p2 = _mm_shuffle_ps(p2, z, _MM_SHUFFLE(0, 0, 1, 0));
    p2 = Add(p2, tcol);
    p2 = _mm_div_ps(p2, w);

    Vector4f half = Mul(sxsy, halves);
    Vector4f out0 = Mul(Add(Mul(_mm_shuffle_ps(p0, p1, _MM_SHUFFLE(1, 0, 1, 0)), flipY), ones), half);
    Vector4f out1 = Mul(Add(Mul(p2, flipY), ones), half);

    StoreRow(dest, out0);
    StoreRow(dest + 4, out1);
}

}} // namespace Scaleform::Render
