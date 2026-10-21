// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the 2D math TUs
// (Render_Matrix2x4: the SSE Matrix2F products and bounds, Render_CxForm: color transforms).
// MS2-UNIT: sfr_render_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e5250-0x1425e5970 .text$mn
// MS2-RANGE: 0x1425e8420-0x1425eeef0 .text$mn
// MS2-RANGE: 0x1425ef560-0x1425f0690 .text$mn
// MS2-RANGE: 0x142600340-0x142602c20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_cxform.h"

namespace Scaleform { namespace Render {

using namespace SIMD;

// ---------------------------------------------------------------------------------------------------------------
// Matrix2F: rows are (sx, shx, 0, tx) and (shy, sy, 0, ty), one SSE register each. Products keep the
// translation lane of the right-hand matrix (masked by lane 3) and clear lane 2.

// @0x1425e5250
template<>
Matrix2F& Matrix2F::Append(const Matrix2F& m)
{
    Vector4f transOnly = BitMask<0, 0, 0, 0xFFFFFFFF>();
    Vector4f noZLane   = BitMask<0xFFFFFFFF, 0xFFFFFFFF, 0, 0xFFFFFFFF>();
    Vector4f b0 = _mm_load_ps(m.M[0]);
    Vector4f b1 = _mm_load_ps(m.M[1]);
    Vector4f a0 = _mm_load_ps(M[0]);
    Vector4f a1 = _mm_load_ps(M[1]);
    Vector4f t0 = _mm_and_ps(b0, transOnly);
    Vector4f t1 = _mm_and_ps(b1, transOnly);
    Vector4f r0 = MulAdd(a1, Splat<1>(b0), _mm_mul_ps(a0, Splat<0>(b0)));
    Vector4f r1 = MulAdd(a1, Splat<1>(b1), _mm_mul_ps(a0, Splat<0>(b1)));
    _mm_store_ps(M[0], _mm_and_ps(_mm_add_ps(t0, r0), noZLane));
    _mm_store_ps(M[1], _mm_and_ps(_mm_add_ps(t1, r1), noZLane));
    return *this;
}

// The axis-aligned bounds of r after the transform: all four corners are transformed, then min/max per axis.
// @0x1425e52d0
template<>
void Matrix2F::EncloseTransform(RectF* pr, const RectF& r) const
{
    Vector4f rect = _mm_load_ps(&r.x1);
    Vector4f m0   = _mm_load_ps(M[0]);
    Vector4f m1   = _mm_load_ps(M[1]);
    Vector4f lo   = _mm_unpacklo_ps(rect, rect);                          // x1 x1 y1 y1
    Vector4f hi   = _mm_unpackhi_ps(rect, rect);                          // x2 x2 y2 y2
    Vector4f tr   = _mm_shuffle_ps(m0, m1, _MM_SHUFFLE(3, 3, 3, 3));      // tx tx ty ty
    Vector4f cols = _mm_unpacklo_ps(m0, m1);                              // sx shy shx sy
    Vector4f p1   = _mm_mul_ps(lo, cols);
    Vector4f p2   = _mm_mul_ps(hi, cols);
    Vector4f xs   = _mm_unpacklo_ps(p1, p2);
    Vector4f ys   = _mm_unpackhi_ps(p1, p2);
    Vector4f xsSw = _mm_shuffle_ps(xs, xs, _MM_SHUFFLE(2, 3, 0, 1));
    Vector4f c1   = _mm_add_ps(xs, ys);
    Vector4f c2   = _mm_add_ps(xsSw, ys);
    Vector4f mn0  = _mm_min_ps(c1, c2);
    Vector4f mx0  = _mm_max_ps(c1, c2);
    Vector4f mn   = _mm_min_ps(mn0, _mm_shuffle_ps(mn0, mn0, _MM_SHUFFLE(2, 3, 0, 1)));
    Vector4f mx   = _mm_max_ps(mx0, _mm_shuffle_ps(mx0, mx0, _MM_SHUFFLE(2, 3, 0, 1)));
    Vector4f box  = _mm_shuffle_ps(mn, mx, _MM_SHUFFLE(2, 0, 2, 0));
    Vector4f off  = _mm_shuffle_ps(tr, tr, _MM_SHUFFLE(2, 0, 2, 0));
    _mm_store_ps(&pr->x1, _mm_add_ps(box, off));
}

// this = m0 followed by m1
// @0x1425e5430
template<>
void Matrix2F::SetToAppend(const Matrix2F& m0, const Matrix2F& m1)
{
    Vector4f transOnly = BitMask<0, 0, 0, 0xFFFFFFFF>();
    Vector4f noZLane   = BitMask<0xFFFFFFFF, 0xFFFFFFFF, 0, 0xFFFFFFFF>();
    Vector4f b0 = _mm_load_ps(m1.M[0]);
    Vector4f b1 = _mm_load_ps(m1.M[1]);
    Vector4f a0 = _mm_load_ps(m0.M[0]);
    Vector4f a1 = _mm_load_ps(m0.M[1]);
    Vector4f t0 = _mm_and_ps(b0, transOnly);
    Vector4f t1 = _mm_and_ps(b1, transOnly);
    Vector4f r0 = MulAdd(a1, Splat<1>(b0), _mm_mul_ps(a0, Splat<0>(b0)));
    Vector4f r1 = MulAdd(a1, Splat<1>(b1), _mm_mul_ps(a0, Splat<0>(b1)));
    _mm_store_ps(M[0], _mm_and_ps(_mm_add_ps(t0, r0), noZLane));
    _mm_store_ps(M[1], _mm_and_ps(_mm_add_ps(t1, r1), noZLane));
}

// this = m0, then m1, then m2 (m1 * m2 is formed first)
// @0x1425e5340
template<>
void Matrix2F::SetToAppend(const Matrix2F& m0, const Matrix2F& m1, const Matrix2F& m2)
{
    Vector4f transOnly = BitMask<0, 0, 0, 0xFFFFFFFF>();
    Vector4f noZLane   = BitMask<0xFFFFFFFF, 0xFFFFFFFF, 0, 0xFFFFFFFF>();
    Vector4f a0 = _mm_load_ps(m0.M[0]);
    Vector4f a1 = _mm_load_ps(m0.M[1]);
    Vector4f b0 = _mm_load_ps(m1.M[0]);
    Vector4f b1 = _mm_load_ps(m1.M[1]);
    Vector4f c0 = _mm_load_ps(m2.M[0]);
    Vector4f c1 = _mm_load_ps(m2.M[1]);

    Vector4f bc0 = _mm_add_ps(_mm_and_ps(c0, transOnly), MulAdd(b1, Splat<1>(c0), _mm_mul_ps(b0, Splat<0>(c0))));
    Vector4f bc1 = _mm_add_ps(_mm_and_ps(c1, transOnly), MulAdd(b1, Splat<1>(c1), _mm_mul_ps(b0, Splat<0>(c1))));

    Vector4f t0 = _mm_and_ps(bc0, transOnly);
    Vector4f t1 = _mm_and_ps(bc1, transOnly);
    Vector4f r0 = MulAdd(a1, Splat<1>(bc0), _mm_mul_ps(a0, Splat<0>(bc0)));
    Vector4f r1 = MulAdd(a1, Splat<1>(bc1), _mm_mul_ps(a0, Splat<0>(bc1)));
    _mm_store_ps(M[0], _mm_and_ps(_mm_add_ps(t0, r0), noZLane));
    _mm_store_ps(M[1], _mm_and_ps(_mm_add_ps(t1, r1), noZLane));
}

// ---------------------------------------------------------------------------------------------------------------
// Cxform

// @0x1425e54b0
Cxform::Cxform()
{
    SetIdentity();
}

// @0x1425e57b0
void Cxform::SetIdentity()
{
    M[0][0] = 1; M[0][1] = 1; M[0][2] = 1; M[0][3] = 1;
    M[1][0] = 0; M[1][1] = 0; M[1][2] = 0; M[1][3] = 0;
}

// @0x1425e5670
bool Cxform::IsIdentity() const
{
    return M[0][0] == 1 && M[0][1] == 1 && M[0][2] == 1 && M[0][3] == 1 &&
           M[1][0] == 0 && M[1][1] == 0 && M[1][2] == 0 && M[1][3] == 0;
}

// @0x1425e54e0
bool Cxform::operator==(const Cxform& x) const
{
    return M[0][0] == x.M[0][0] && M[0][1] == x.M[0][1] && M[0][2] == x.M[0][2] && M[0][3] == x.M[0][3] &&
           M[1][0] == x.M[1][0] && M[1][1] == x.M[1][1] && M[1][2] == x.M[1][2] && M[1][3] == x.M[1][3];
}

// @0x1425e5700
void Cxform::Prepend(const Cxform& c)
{
    Vector4f c0 = _mm_load_ps(c.M[0]);
    Vector4f m0 = _mm_load_ps(M[0]);
    Vector4f c1 = _mm_load_ps(c.M[1]);
    Vector4f m1 = _mm_load_ps(M[1]);
    Vector4f mul = _mm_mul_ps(m0, c0);
    Vector4f add = Add(Mul(c1, m0), m1);
    _mm_store_ps(M[0], mul);
    _mm_store_ps(M[1], add);
}

// @0x1425e5550
void Cxform::Append(const Cxform& c)
{
    Vector4f c0 = _mm_load_ps(c.M[0]);
    Vector4f m0 = _mm_load_ps(M[0]);
    Vector4f c1 = _mm_load_ps(c.M[1]);
    Vector4f m1 = _mm_load_ps(M[1]);
    Vector4f mul = _mm_mul_ps(m0, c0);
    Vector4f add = Add(Mul(m1, c0), c1);
    _mm_store_ps(M[0], mul);
    _mm_store_ps(M[1], add);
}

// @0x1425e57e0
void Cxform::SetToAppend(const Cxform& c0, const Cxform& c1)
{
    Vector4f a0 = _mm_load_ps(c0.M[0]);
    Vector4f b0 = _mm_load_ps(c1.M[0]);
    Vector4f a1 = _mm_load_ps(c0.M[1]);
    Vector4f b1 = _mm_load_ps(c1.M[1]);
    Vector4f mul = _mm_mul_ps(a0, b0);
    Vector4f add = Add(Mul(a1, b0), b1);
    _mm_store_ps(M[0], mul);
    _mm_store_ps(M[1], add);
}

// @0x1425e56e0
void Cxform::Normalize()
{
    _mm_store_ps(M[1], _mm_mul_ps(_mm_load_ps(M[1]), _mm_set1_ps(1.0f / 255.0f)));
}

}} // namespace Scaleform::Render
