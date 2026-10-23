// Recovered Scaleform 4.1.18 Render: Point3<T>, Matrix3x4<T> (the 3D affine transform, three rows of [x y z t])
// and Matrix4x4<T> (the projection matrix, four rows; translation in column 3 of rows 0..2).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Matrix3x4<float>::MultiplyMatrix 0x142604370 sits in sfr_render_03; Matrix4x4<float>::GetInverse 0x142602c20 is
// the COMDAT kept by Render_ScreenToWorld (sfr_render_02h).
#ifndef MS2_SF_RENDER_MATRIX4X4_H
#define MS2_SF_RENDER_MATRIX4X4_H

#include <string.h>
#include <math.h>
#include <float.h>
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/kernel/sf_math.h"

namespace Scaleform { namespace Render {

template<class T> class Matrix2x4;
template<class T> class Matrix4x4;

template<class T>
class Point3
{
public:
    T x, y, z;

    Point3() {}
    Point3(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}
    // (appended for flash.geom, sfr_as3_11) user-declared, forced-inline copy and assignment, coordinate by
    // coordinate (never moved as one block)
    SF_INLINE Point3(const Point3& p) { SetPoint(p.x, p.y, p.z); }
    SF_INLINE const Point3& operator=(const Point3& p) { SetPoint(p.x, p.y, p.z); return *this; }
    SF_INLINE void SetPoint(T x_, T y_, T z_) { x = x_; y = y_; z = z_; }
};
typedef Point3<float> Point3F;

// Element storage in a base; the float matrices are 16-aligned (4.1.18 is built with SF_ENABLE_SIMD). Copies through
// pointers still use movups, stack copies movaps (the flash.geom Matrix3D natives' GetEulerAngles copy).
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

    // (appended for the tree nodes, sfr_render_03c)
    static Matrix3x4 Identity;      // Matrix3F: 0x143aee540

    Matrix3x4(const T m[3][4]) { Set(&m[0][0], 12); }

    void Set(const T* p, int count) { memcpy(M, p, count * sizeof(T)); }
    // (appended for flash.geom, sfr_as3_11) user-declared copy and assignment, both through Set (a 48-byte memcpy);
    // the Matrix3D natives' 4x4-to-3x4 conversions only match with them
    void Set(const Matrix3x4& m) { Set(&m.M[0][0], 12); }
    Matrix3x4(const Matrix3x4& m) { *this = m; }
    const Matrix3x4& operator=(const Matrix3x4& m) { Set(m); return *this; }

    // a 2D point taken as (x, y, 0, 1)
    Point<T> Transform(const Point<T>& p) const
    {
        T z = 1.0f;
        return Point<T>(M[0][0] * p.x + M[0][1] * p.y + M[0][2] * z + M[0][3],
                        M[1][0] * p.x + M[1][1] * p.y + M[1][2] * z + M[1][3]);
    }
    void Transform(Point<T>* dest, const Point<T>& p) const { *dest = Transform(p); }

    // bounds of the four transformed corners
    void EncloseTransform(Rect<T>* dest, const Rect<T>& r) const
    {
        Point<T> p0, p1, p2, p3;
        Transform(&p0, r.TopLeft());
        Transform(&p1, r.TopRight());
        Transform(&p2, r.BottomRight());
        Transform(&p3, r.BottomLeft());
        dest->SetRect(p0, p0);
        dest->ExpandToPoint(p1);
        dest->ExpandToPoint(p2);
        dest->ExpandToPoint(p3);
    }
    Rect<T> EncloseTransform(const Rect<T>& r) const
    {
        Rect<T> d(Rect<T>::NoInit);
        EncloseTransform(&d, r);
        return d;
    }

    // (appended for the shape cache nodes, sfr_render_03f)
    enum NoInitType { NoInit };
    Matrix3x4(NoInitType) {}

    // (appended for the display objects, sfr_gfx_06) this = a * m (m applied first; 0x142604460)
    void MultiplyMatrix(const Matrix3x4& a, const Matrix2x4<T>& m);
    Matrix3x4& Prepend(const Matrix2x4<T>& m)
    {
        MultiplyMatrix(Matrix3x4(*this), m);
        return *this;
    }
    Matrix3x4& Prepend(const Matrix3x4& m)
    {
        MultiplyMatrix(Matrix3x4(*this), m);
        return *this;
    }
    // (appended for sfr_render_05j) m applied after this
    Matrix3x4& Append(const Matrix3x4& m)
    {
        MultiplyMatrix(m, Matrix3x4(*this));
        return *this;
    }
    // the 2D matrix with the z row of the identity
    Matrix3x4(const Matrix2x4<T>& m)
    {
        M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = m.M[0][3];
        M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = m.M[1][3];
        M[2][0] = 0;         M[2][1] = 0;         M[2][2] = 1;         M[2][3] = 0;
    }
    static Matrix3x4 Translation(T x, T y, T z)
    {
        Matrix3x4 m(NoInit);
        m.M[0][0] = 1; m.M[0][1] = 0; m.M[0][2] = 0; m.M[0][3] = x;
        m.M[1][0] = 0; m.M[1][1] = 1; m.M[1][2] = 0; m.M[1][3] = y;
        m.M[2][0] = 0; m.M[2][1] = 0; m.M[2][2] = 1; m.M[2][3] = z;
        return m;
    }
    // rotations about one axis (radians)
    static Matrix3x4 RotationX(T angle)
    {
        T c = cosf(angle), s = sinf(angle);
        Matrix3x4 m(NoInit);
        m.M[0][0] = 1; m.M[0][1] = 0; m.M[0][2] = 0;  m.M[0][3] = 0;
        m.M[1][0] = 0; m.M[1][1] = c; m.M[1][2] = -s; m.M[1][3] = 0;
        m.M[2][0] = 0; m.M[2][1] = s; m.M[2][2] = c;  m.M[2][3] = 0;
        return m;
    }
    static Matrix3x4 RotationY(T angle)
    {
        T c = cosf(angle), s = sinf(angle);
        Matrix3x4 m(NoInit);
        m.M[0][0] = c;  m.M[0][1] = 0; m.M[0][2] = s; m.M[0][3] = 0;
        m.M[1][0] = 0;  m.M[1][1] = 1; m.M[1][2] = 0; m.M[1][3] = 0;
        m.M[2][0] = -s; m.M[2][1] = 0; m.M[2][2] = c; m.M[2][3] = 0;
        return m;
    }
    static Matrix3x4 RotationZ(T angle)
    {
        T c = cosf(angle), s = sinf(angle);
        Matrix3x4 m(NoInit);
        m.M[0][0] = c; m.M[0][1] = -s; m.M[0][2] = 0; m.M[0][3] = 0;
        m.M[1][0] = s; m.M[1][1] = c;  m.M[1][2] = 0; m.M[1][3] = 0;
        m.M[2][0] = 0; m.M[2][1] = 0;  m.M[2][2] = 1; m.M[2][3] = 0;
        return m;
    }
    // every element within the float range
    bool IsValid() const
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                if (!(M[i][j] >= -FLT_MAX && M[i][j] <= FLT_MAX))
                    return false;
        return true;
    }
    static Matrix3x4 Scaling(T sx, T sy, T sz)
    {
        Matrix3x4 m(NoInit);
        m.M[0][0] = sx; m.M[0][1] = 0;  m.M[0][2] = 0;  m.M[0][3] = 0;
        m.M[1][0] = 0;  m.M[1][1] = sy; m.M[1][2] = 0;  m.M[1][3] = 0;
        m.M[2][0] = 0;  m.M[2][1] = 0;  m.M[2][2] = sz; m.M[2][3] = 0;
        return m;
    }

    // (appended for sfr_render_03) this = m * b, the 2D matrix taken with the z row of the identity (0x142604500)
    void MultiplyMatrix(const Matrix2x4<T>& m, const Matrix3x4& b);

    // (appended for flash.geom, sfr_as3_11) element access, the axis scales and the Euler angles
    T*       Data() { return &M[0][0]; }
    const T* Data() const { return &M[0][0]; }
    T&       Tx() { return M[0][3]; }
    T&       Ty() { return M[1][3]; }
    T&       Tz() { return M[2][3]; }
    const T& Tx() const { return M[0][3]; }
    const T& Ty() const { return M[1][3]; }
    const T& Tz() const { return M[2][3]; }
    // the rows 0..2 of a 4x4 (its projective row dropped)
    Matrix3x4(const Matrix4x4<T>& m);
    // lengths of the column vectors
    T GetXScale() const { return sqrtf(M[0][0] * M[0][0] + M[1][0] * M[1][0] + M[2][0] * M[2][0]); }
    T GetYScale() const { return sqrtf(M[0][1] * M[0][1] + M[1][1] * M[1][1] + M[2][1] * M[2][1]); }
    T GetZScale() const { return sqrtf(M[0][2] * M[0][2] + M[1][2] * M[1][2] + M[2][2] * M[2][2]); }
    void SetXScale(T s) { s /= GetXScale(); M[0][0] *= s; M[1][0] *= s; M[2][0] *= s; }
    void SetYScale(T s) { s /= GetYScale(); M[0][1] *= s; M[1][1] *= s; M[2][1] *= s; }
    void SetZScale(T s) { s /= GetZScale(); M[0][2] *= s; M[1][2] *= s; M[2][2] *= s; }
    // Rotations about x, y and z (radians) of the unit-scaled matrix; near M[1][0] = +-1 the z angle is a
    // quarter turn and x is folded into y.
    void GetEulerAngles(T* ex, T* ey, T* ez) const
    {
        Matrix3x4 u(*this);
        u.SetXScale(1.0f);
        u.SetYScale(1.0f);
        u.SetZScale(1.0f);
        if (u.M[1][0] > 0.998f)
        {
            if (ey) *ey = atan2f(u.M[0][2], u.M[2][2]);
            if (ez) *ez = (T)SF_MATH_PI / 2.f;
            if (ex) *ex = 0;
            return;
        }
        if (u.M[1][0] < -0.998f)
        {
            if (ey) *ey = atan2f(u.M[0][2], u.M[2][2]);
            if (ez) *ez = (T)-SF_MATH_PI / 2.f;
            if (ex) *ex = 0;
            return;
        }
        if (ey) *ey = atan2f(-u.M[2][0], u.M[0][0]);
        if (ex) *ex = atan2f(-u.M[1][2], u.M[1][1]);
        if (ez) *ez = asinf(u.M[1][0]);
    }
    void GetRotation(T* ex, T* ey, T* ez) const { return GetEulerAngles(ex, ey, ez); }

    // (appended for flash.geom, sfr_as3_11) the 4x4 inverse with the implicit row (0 0 0 1); 0x1424845e0
    inline Matrix3x4 GetInverse() const;
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

    // (appended for sfr_render_04f)
    static Matrix4x4 Identity;      // Matrix4F: 0x143aee570
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

    // (appended for the tree nodes, sfr_render_03c)
    Matrix4x4(const T m[4][4]) { Set(&m[0][0], 16); }

    // (appended for the shape cache nodes, sfr_render_03f)
    enum NoInitType { NoInit };
    Matrix4x4(NoInitType) {}
    Matrix4x4(const Matrix4x4& m1, const Matrix3x4<T>& m2) { MultiplyMatrix(m1, m2); }

    // this = m1 * m2 (0x142678d20)
    void MultiplyMatrix(const Matrix4x4& m1, const Matrix3x4<T>& m2);
    // the corners of r projected and scaled to a w x h viewport: x1y1, x2y1, x2y2, x1y2 (0x142679010)
    void TransformHomogeneousAndScaleCorners(const Rect<T>& r, T w, T h, T* dest) const;

    // (appended for the display objects, sfr_gfx_06) v projected: divided by its w
    Point3<T> TransformHomogeneous(const Point3<T>& v) const
    {
        T x = M[0][0] * v.x + M[0][1] * v.y + M[0][2] * v.z + M[0][3];
        T y = M[1][0] * v.x + M[1][1] * v.y + M[1][2] * v.z + M[1][3];
        T z = M[2][0] * v.x + M[2][1] * v.y + M[2][2] * v.z + M[2][3];
        T w = M[3][0] * v.x + M[3][1] * v.y + M[3][2] * v.z + M[3][3];
        return Point3<T>(x / w, y / w, z / w);
    }

    // (appended for the Matrix4x4 TU, sfr_render_05f) the other products (this = m1 * m2; a 2x4 / 3x4 operand
    // counts as its 4x4 extension) and the bounds of a projected rectangle
    void MultiplyMatrix(const Matrix4x4& m1, const Matrix4x4& m2);
    void MultiplyMatrix(const Matrix4x4& m1, const Matrix2x4<T>& m2);
    void MultiplyMatrix(const Matrix2x4<T>& m1, const Matrix4x4& m2);
    void MultiplyMatrix(const Matrix3x4<T>& m1, const Matrix4x4& m2);
    void EncloseTransformHomogeneous(Rect<T>* pr, const Rect<T>& r) const;

    // (appended for sfr_as2_07) rows become columns (Matrix4F: 0x1429925f0)
    void Transpose();

    // (appended for flash.geom, sfr_as3_11; the Matrix3D natives work on Matrix4x4<double>)
    T*       Data() { return &M[0][0]; }
    const T* Data() const { return &M[0][0]; }
    // element i of the 16, by value (indexing goes through this, not the pointer conversion)
    T operator[](int i)       { return Data()[i]; }
    T operator[](int i) const { return Data()[i]; }
    // element-wise narrowing to the 3D float transform (rows 0..2)
    operator Matrix3F()
    {
        Matrix3F m(Matrix3F::NoInit);
        m.M[0][0] = (float)M[0][0]; m.M[0][1] = (float)M[0][1]; m.M[0][2] = (float)M[0][2]; m.M[0][3] = (float)M[0][3];
        m.M[1][0] = (float)M[1][0]; m.M[1][1] = (float)M[1][1]; m.M[1][2] = (float)M[1][2]; m.M[1][3] = (float)M[1][3];
        m.M[2][0] = (float)M[2][0]; m.M[2][1] = (float)M[2][1]; m.M[2][2] = (float)M[2][2]; m.M[2][3] = (float)M[2][3];
        return m;
    }
    Matrix4x4(const Matrix4x4& m1, const Matrix4x4& m2) { MultiplyMatrix(m1, m2); }
    // (appended for sfr_render_06g)
    Matrix4x4(const Matrix2x4<T>& m1, const Matrix4x4& m2) { MultiplyMatrix(m1, m2); }
    // this = m1 * m2, the portable product (Matrix4x4<double>: 0x142485d30)
    void MultiplyMatrix_NonOpt(const Matrix4x4& m1, const Matrix4x4& m2)
    {
        M[0][0] = m1.M[0][0] * m2.M[0][0] + m1.M[0][1] * m2.M[1][0] + m1.M[0][2] * m2.M[2][0] + m1.M[0][3] * m2.M[3][0];
        M[0][1] = m1.M[0][0] * m2.M[0][1] + m1.M[0][1] * m2.M[1][1] + m1.M[0][2] * m2.M[2][1] + m1.M[0][3] * m2.M[3][1];
        M[0][2] = m1.M[0][0] * m2.M[0][2] + m1.M[0][1] * m2.M[1][2] + m1.M[0][2] * m2.M[2][2] + m1.M[0][3] * m2.M[3][2];
        M[0][3] = m1.M[0][0] * m2.M[0][3] + m1.M[0][1] * m2.M[1][3] + m1.M[0][2] * m2.M[2][3] + m1.M[0][3] * m2.M[3][3];

        M[1][0] = m1.M[1][0] * m2.M[0][0] + m1.M[1][1] * m2.M[1][0] + m1.M[1][2] * m2.M[2][0] + m1.M[1][3] * m2.M[3][0];
        M[1][1] = m1.M[1][0] * m2.M[0][1] + m1.M[1][1] * m2.M[1][1] + m1.M[1][2] * m2.M[2][1] + m1.M[1][3] * m2.M[3][1];
        M[1][2] = m1.M[1][0] * m2.M[0][2] + m1.M[1][1] * m2.M[1][2] + m1.M[1][2] * m2.M[2][2] + m1.M[1][3] * m2.M[3][2];
        M[1][3] = m1.M[1][0] * m2.M[0][3] + m1.M[1][1] * m2.M[1][3] + m1.M[1][2] * m2.M[2][3] + m1.M[1][3] * m2.M[3][3];

        M[2][0] = m1.M[2][0] * m2.M[0][0] + m1.M[2][1] * m2.M[1][0] + m1.M[2][2] * m2.M[2][0] + m1.M[2][3] * m2.M[3][0];
        M[2][1] = m1.M[2][0] * m2.M[0][1] + m1.M[2][1] * m2.M[1][1] + m1.M[2][2] * m2.M[2][1] + m1.M[2][3] * m2.M[3][1];
        M[2][2] = m1.M[2][0] * m2.M[0][2] + m1.M[2][1] * m2.M[1][2] + m1.M[2][2] * m2.M[2][2] + m1.M[2][3] * m2.M[3][2];
        M[2][3] = m1.M[2][0] * m2.M[0][3] + m1.M[2][1] * m2.M[1][3] + m1.M[2][2] * m2.M[2][3] + m1.M[2][3] * m2.M[3][3];

        M[3][0] = m1.M[3][0] * m2.M[0][0] + m1.M[3][1] * m2.M[1][0] + m1.M[3][2] * m2.M[2][0] + m1.M[3][3] * m2.M[3][0];
        M[3][1] = m1.M[3][0] * m2.M[0][1] + m1.M[3][1] * m2.M[1][1] + m1.M[3][2] * m2.M[2][1] + m1.M[3][3] * m2.M[3][1];
        M[3][2] = m1.M[3][0] * m2.M[0][2] + m1.M[3][1] * m2.M[1][2] + m1.M[3][2] * m2.M[2][2] + m1.M[3][3] * m2.M[3][2];
        M[3][3] = m1.M[3][0] * m2.M[0][3] + m1.M[3][1] * m2.M[1][3] + m1.M[3][2] * m2.M[2][3] + m1.M[3][3] * m2.M[3][3];
    }
    // this = this * m (m applied first) / this = m * this, on a copy of this
    void Prepend(const Matrix4x4& m)
    {
        Matrix4x4 t = *this;
        MultiplyMatrix(t, m);
    }
    void Append(const Matrix4x4& m)
    {
        Matrix4x4 t = *this;
        MultiplyMatrix(m, t);
    }
    // rotation by angle (radians, taken in float) about the unit axis: identity with the 3x3 part set
    static Matrix4x4 Rotation(T angle, const Point3<T>& axis)
    {
        Matrix4x4 r;
        T c  = cosf((float)angle);
        T s  = sinf((float)angle);
        T ic = 1.0f - c;
        T xx = axis.x * axis.x, yy = axis.y * axis.y, zz = axis.z * axis.z;
        T xy = axis.x * axis.y * ic, xz = axis.x * axis.z * ic, yz = axis.y * axis.z * ic;
        T xs = axis.x * s, ys = axis.y * s, zs = axis.z * s;
        r.M[0][0] = xx * ic + c; r.M[0][1] = xy - zs;      r.M[0][2] = xz + ys;
        r.M[1][0] = xy + zs;     r.M[1][1] = yy * ic + c;  r.M[1][2] = yz - xs;
        r.M[2][0] = xz - ys;     r.M[2][1] = yz + xs;      r.M[2][2] = zz * ic + c;
        return r;
    }
    // the same about an axis through pivot (Matrix4x4<double>: 0x142486210)
    static Matrix4x4 Rotation(T angle, const Point3<T>& axis, const Point3<T>& pivot)
    {
        return Matrix4x4(Translation(-pivot.x, -pivot.y, -pivot.z),
                         Matrix4x4(Rotation(angle, axis), Translation(pivot.x, pivot.y, pivot.z)));
    }
    static Matrix4x4 Translation(T x, T y, T z)
    {
        Matrix4x4 r;
        r.M[0][3] = x;
        r.M[1][3] = y;
        r.M[2][3] = z;
        return r;
    }
    static Matrix4x4 Scaling(T sx, T sy, T sz)
    {
        Matrix4x4 r;
        r.M[0][0] = sx;
        r.M[1][1] = sy;
        r.M[2][2] = sz;
        return r;
    }
    // the affine product (row 3 ignored)
    Point3<T> Transform(const Point3<T>& p) const
    {
        return Point3<T>(M[0][0] * p.x + M[0][1] * p.y + M[0][2] * p.z + M[0][3],
                         M[1][0] * p.x + M[1][1] * p.y + M[1][2] * p.z + M[1][3],
                         M[2][0] * p.x + M[2][1] * p.y + M[2][2] * p.z + M[2][3]);
    }
    // cofactor expansion along row 0
    T GetDeterminant() const
    {
        return M[0][0] * GetMinor(*this, 1, 2, 3, 1, 2, 3) - M[0][1] * GetMinor(*this, 1, 2, 3, 0, 2, 3) +
               M[0][2] * GetMinor(*this, 1, 2, 3, 0, 1, 3) - M[0][3] * GetMinor(*this, 1, 2, 3, 0, 1, 2);
    }
    void Invert() { *this = GetInverse(); }

private:
    // determinant of the 3x3 of m on rows r0..r2, columns c0..c2 (Matrix4x4<double>: 0x142485360)
    T GetMinor(const Matrix4x4& m, const size_t r0, const size_t r1, const size_t r2,
               const size_t c0, const size_t c1, const size_t c2) const
    {
        return m.M[r0][c0] * (m.M[r1][c1] * m.M[r2][c2] - m.M[r2][c1] * m.M[r1][c2]) -
               m.M[r0][c1] * (m.M[r1][c0] * m.M[r2][c2] - m.M[r2][c0] * m.M[r1][c2]) +
               m.M[r0][c2] * (m.M[r1][c0] * m.M[r2][c1] - m.M[r2][c0] * m.M[r1][c1]);
    }
};
typedef Matrix4x4<float> Matrix4F;

template<class T>
inline Matrix3x4<T>::Matrix3x4(const Matrix4x4<T>& m)
{
    M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = m.M[0][3];
    M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = m.M[1][3];
    M[2][0] = m.M[2][0]; M[2][1] = m.M[2][1]; M[2][2] = m.M[2][2]; M[2][3] = m.M[2][3];
}

// The double 4x4 product is the portable one (the float one is the SSE code of sfr_render_05f).
template<> inline void Matrix4x4<double>::MultiplyMatrix(const Matrix4x4<double>& m1, const Matrix4x4<double>& m2)
{
    MultiplyMatrix_NonOpt(m1, m2);
}

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

// The adjugate inverse of Matrix4x4::GetInverse with the projective row taken as (0 0 0 1) (its zero products stay,
// float math). A singular matrix gives the identity with the translation negated.
// MS2-FUNCTIONAL: the exe keeps more of the zero products as live mulss against a zeroed register (1298 vs 1191 bytes)
// @0x1424845e0
template<class T>
inline Matrix3x4<T> Matrix3x4<T>::GetInverse() const
{
    T a00 = M[0][0], a01 = M[0][1], a02 = M[0][2], a03 = M[0][3];
    T a10 = M[1][0], a11 = M[1][1], a12 = M[1][2], a13 = M[1][3];
    T a20 = M[2][0], a21 = M[2][1], a22 = M[2][2], a23 = M[2][3];
    T a30 = 0, a31 = 0, a32 = 0, a33 = 1;

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
    Matrix3x4<T> r(NoInit);
    if (det == 0)
    {
        r.SetIdentity();
        r.Tx() = -Tx();
        r.Ty() = -Ty();
        r.Tz() = -Tz();
        return r;
    }
    T inv = 1 / det;

    r.M[0][0] = c00 * inv;
    r.M[1][0] = c10 * inv;
    r.M[2][0] = c20 * inv;

    r.M[0][1] = - (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    r.M[1][1] = + (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    r.M[2][1] = - (s4 * a00 - s2 * a01 + s0 * a03) * inv;

    s0 = a10 * a31 - a11 * a30;
    s1 = a10 * a32 - a12 * a30;
    s2 = a10 * a33 - a13 * a30;
    s3 = a11 * a32 - a12 * a31;
    s4 = a11 * a33 - a13 * a31;
    s5 = a12 * a33 - a13 * a32;

    r.M[0][2] = + (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    r.M[1][2] = - (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    r.M[2][2] = + (s4 * a00 - s2 * a01 + s0 * a03) * inv;

    s0 = a21 * a10 - a20 * a11;
    s1 = a22 * a10 - a20 * a12;
    s2 = a23 * a10 - a20 * a13;
    s3 = a22 * a11 - a21 * a12;
    s4 = a23 * a11 - a21 * a13;
    s5 = a23 * a12 - a22 * a13;

    r.M[0][3] = - (s5 * a01 - s4 * a02 + s3 * a03) * inv;
    r.M[1][3] = + (s5 * a00 - s2 * a02 + s1 * a03) * inv;
    r.M[2][3] = - (s4 * a00 - s2 * a01 + s0 * a03) * inv;
    return r;
}

}} // namespace Scaleform::Render

#endif
