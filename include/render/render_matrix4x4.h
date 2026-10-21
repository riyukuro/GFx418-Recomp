// Recovered Scaleform 4.1.18 Render: Point3<T>, Matrix3x4<T> (the 3D affine transform, three rows of [x y z t])
// and Matrix4x4<T> (the projection matrix, four rows; translation in column 3 of rows 0..2).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Matrix3x4<float>::MultiplyMatrix 0x142604370 sits in sfr_render_03; Matrix4x4<float>::GetInverse 0x142602c20 is
// the COMDAT kept by Render_ScreenToWorld (sfr_render_02h).
#ifndef MS2_SF_RENDER_MATRIX4X4_H
#define MS2_SF_RENDER_MATRIX4X4_H

#include <string.h>
#include "ms2/scaleform/include/render/render_types2d.h"

namespace Scaleform { namespace Render {

template<class T>
class Point3
{
public:
    T x, y, z;

    Point3() {}
    Point3(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}
};
typedef Point3<float> Point3F;

// Element storage in a base so the float matrices are 16-byte aligned for SSE.
template<class T>
class Matrix3x4Data
{
public:
    T M[3][4];
};

template<>
class Matrix3x4Data<float>
{
public:
    __declspec(align(16)) float M[3][4];
};

template<class T>
class Matrix3x4 : public Matrix3x4Data<T>
{
public:
    using Matrix3x4Data<T>::M;

    Matrix3x4() { SetIdentity(); }
    Matrix3x4(const Matrix3x4& a, const Matrix3x4& b) { MultiplyMatrix(a, b); }

    void Clear() { memset(M, 0, sizeof(M)); }
    void SetIdentity()
    {
        Clear();
        M[0][0] = 1;
        M[1][1] = 1;
        M[2][2] = 1;
    }

    // this = a * b (b applied first)
    void MultiplyMatrix(const Matrix3x4& a, const Matrix3x4& b);
};
typedef Matrix3x4<float> Matrix3F;

template<class T>
class Matrix4x4Data
{
public:
    T M[4][4];
};

template<>
class Matrix4x4Data<float>
{
public:
    __declspec(align(16)) float M[4][4];
};

template<class T>
class Matrix4x4 : public Matrix4x4Data<T>
{
public:
    using Matrix4x4Data<T>::M;

    Matrix4x4() { SetIdentity(); }
    Matrix4x4(const Matrix4x4& m) { *this = m; }
    const Matrix4x4& operator=(const Matrix4x4& m)
    {
        Set(m);
        return *this;
    }
    Matrix4x4(T a00, T a01, T a02, T a03, T a10, T a11, T a12, T a13,
              T a20, T a21, T a22, T a23, T a30, T a31, T a32, T a33)
    {
        M[0][0] = a00; M[0][1] = a01; M[0][2] = a02; M[0][3] = a03;
        M[1][0] = a10; M[1][1] = a11; M[1][2] = a12; M[1][3] = a13;
        M[2][0] = a20; M[2][1] = a21; M[2][2] = a22; M[2][3] = a23;
        M[3][0] = a30; M[3][1] = a31; M[3][2] = a32; M[3][3] = a33;
    }
    // The affine 3x4 with the projective row (0 0 0 1) appended.
    Matrix4x4(const Matrix3x4<T>& m)
    {
        M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = m.M[0][3];
        M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = m.M[1][3];
        M[2][0] = m.M[2][0]; M[2][1] = m.M[2][1]; M[2][2] = m.M[2][2]; M[2][3] = m.M[2][3];
        M[3][0] = 0;         M[3][1] = 0;         M[3][2] = 0;         M[3][3] = 1.0f;
    }

    operator T*() { return &M[0][0]; }
    operator const T*() const { return &M[0][0]; }

    void Set(const T* p, int count) { memcpy(M, p, count * sizeof(T)); }
    void Set(const Matrix4x4& m) { Set(&m.M[0][0], 16); }

    void Clear() { memset(M, 0, sizeof(M)); }
    void SetIdentity()
    {
        Clear();
        M[0][0] = 1;
        M[1][1] = 1;
        M[2][2] = 1;
        M[3][3] = 1;
    }

    T&       Tx() { return M[0][3]; }
    T&       Ty() { return M[1][3]; }
    T&       Tz() { return M[2][3]; }
    const T& Tx() const { return M[0][3]; }
    const T& Ty() const { return M[1][3]; }
    const T& Tz() const { return M[2][3]; }

    inline Matrix4x4 GetInverse() const;
    void SetInverse(const Matrix4x4& m) { *this = m.GetInverse(); }
};
typedef Matrix4x4<float> Matrix4F;

// Inverse through the adjugate: 2x2 sub-determinants of the lower rows, cofactors, then the determinant along
// row 0. A singular matrix gives the identity with the translation negated.
// @0x142602c20
template<class T>
inline Matrix4x4<T> Matrix4x4<T>::GetInverse() const
{
    T a00 = M[0][0], a01 = M[0][1], a02 = M[0][2], a03 = M[0][3];
    T a10 = M[1][0], a11 = M[1][1], a12 = M[1][2], a13 = M[1][3];
    T a20 = M[2][0], a21 = M[2][1], a22 = M[2][2], a23 = M[2][3];
    T a30 = M[3][0], a31 = M[3][1], a32 = M[3][2], a33 = M[3][3];

    T s0 = a20 * a31 - a21 * a30;
    T s1 = a20 * a32 - a22 * a30;
    T s2 = a20 * a33 - a23 * a30;
    T s3 = a21 * a32 - a22 * a31;
    T s4 = a21 * a33 - a23 * a31;
    T s5 = a22 * a33 - a23 * a32;

    T c00 = + (s5 * a11 - s4 * a12 + s3 * a13);
    T c10 = - (s5 * a10 - s2 * a12 + s1 * a13);
    T c20 = + (s4 * a10 - s2 * a11 + s0 * a13);
    T c30 = - (s3 * a10 - s1 * a11 + s0 * a12);

    T det = (c00 * a00 + c10 * a01 + c20 * a02 + c30 * a03);
    if (det == 0)
    {
        Matrix4x4<T> r;
        r.Tx() = -Tx();
        r.Ty() = -Ty();
        r.Tz() = -Tz();
        return r;
    }
    T inv = 1 / det;

    T r00 = c00 * inv;
    T r10 = c10 * inv;
    T r20 = c20 * inv;
    T r30 = c30 * inv;

    T r01 = - (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    T r11 = + (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    T r21 = - (s4 * a00 - s2 * a01 + s0 * a03) * inv;
    T r31 = + (s3 * a00 - s1 * a01 + s0 * a02) * inv;

    s0 = a10 * a31 - a11 * a30;
    s1 = a10 * a32 - a12 * a30;
    s2 = a10 * a33 - a13 * a30;
    s3 = a11 * a32 - a12 * a31;
    s4 = a11 * a33 - a13 * a31;
    s5 = a12 * a33 - a13 * a32;

    T r02 = + (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    T r12 = - (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    T r22 = + (s4 * a00 - s2 * a01 + s0 * a03) * inv;
    T r32 = - (s3 * a00 - s1 * a01 + s0 * a02) * inv;

    s0 = a21 * a10 - a20 * a11;
    s1 = a22 * a10 - a20 * a12;
    s2 = a23 * a10 - a20 * a13;
    s3 = a22 * a11 - a21 * a12;
    s4 = a23 * a11 - a21 * a13;
    s5 = a23 * a12 - a22 * a13;

    T r03 = - (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    T r13 = + (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    T r23 = - (s4 * a00 - s2 * a01 + s0 * a03) * inv;
    T r33 = + (s3 * a00 - s1 * a01 + s0 * a02) * inv;

    return Matrix4x4<T>(r00, r01, r02, r03,
                        r10, r11, r12, r13,
                        r20, r21, r22, r23,
                        r30, r31, r32, r33);
}

}} // namespace Scaleform::Render

#endif
