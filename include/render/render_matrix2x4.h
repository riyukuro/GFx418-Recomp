// Recovered Scaleform 4.1.18 Render: Matrix2x4<T>, the 2D affine transform (two rows of [sx shx 0 tx]).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The members without a body here are the SSE float versions in the Render_Matrix2x4 unit (sfr_render_02):
// Append 0x1425e5250, EncloseTransform 0x1425e52d0, SetToAppend(3) 0x1425e5340, SetToAppend(2) 0x1425e5430. The inline ones show up as COMDATs wherever they were not inlined.
#ifndef MS2_SF_RENDER_MATRIX2X4_H
#define MS2_SF_RENDER_MATRIX2X4_H

#include <math.h>
#include "ms2/scaleform/include/render/render_types2d.h"

namespace Scaleform { namespace Render {

enum NoInitType { NoInit };
template<class T> class Matrix3x4;

// The element storage sits in a base so the float matrix can be 16-byte aligned for SSE (the exe allocates
// Matrix2F with 16-byte alignment and treats a local one as a /GS buffer).
template<class T>
class Matrix2x4Data
{
public:
    // row 0: Sx Shx 0 Tx, row 1: Shy Sy 0 Ty
    T M[2][4];
};

template<>
class Matrix2x4Data<float>
{
public:
    __declspec(align(16)) float M[2][4];
};

template<class T>
class Matrix2x4 : public Matrix2x4Data<T>
{
public:
    using Matrix2x4Data<T>::M;

    Matrix2x4() { SetIdentity(); }
    Matrix2x4(NoInitType) {}
    Matrix2x4(const Matrix2x4& m) { *this = m; }
    Matrix2x4(T sx, T shx, T tx, T shy, T sy, T ty)
    {
        M[0][0] = sx;  M[0][1] = shx; M[0][2] = 0; M[0][3] = tx;
        M[1][0] = shy; M[1][1] = sy;  M[1][2] = 0; M[1][3] = ty;
    }
    Matrix2x4(const Matrix2x4& m0, const Matrix2x4& m1) { SetToAppend(m0, m1); }

    Matrix2x4& operator=(const Matrix2x4& m)
    {
        M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = m.M[0][3];
        M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = m.M[1][3];
        return *this;
    }

    T& Sx()  { return M[0][0]; }
    T& Shx() { return M[0][1]; }
    T& Tx()  { return M[0][3]; }
    T& Shy() { return M[1][0]; }
    T& Sy()  { return M[1][1]; }
    T& Ty()  { return M[1][3]; }
    T  Sx() const  { return M[0][0]; }
    T  Shx() const { return M[0][1]; }
    T  Tx() const  { return M[0][3]; }
    T  Shy() const { return M[1][0]; }
    T  Sy() const  { return M[1][1]; }
    T  Ty() const  { return M[1][3]; }

    void SetIdentity()
    {
        M[0][0] = 1; M[0][1] = 0; M[0][2] = 0; M[0][3] = 0;
        M[1][0] = 0; M[1][1] = 1; M[1][2] = 0; M[1][3] = 0;
    }

    // this = m1 * m0 (m0 applied first)
    void SetToAppend(const Matrix2x4& m0, const Matrix2x4& m1);
    void SetToAppend(const Matrix2x4& m0, const Matrix2x4& m1, const Matrix2x4& m2);
    Matrix2x4& Append(const Matrix2x4& m);

    // this = this * m (m applied first); works on a full copy of this (the exe keeps it on the stack)
    Matrix2x4& Prepend(const Matrix2x4& m)
    {
        Matrix2x4 t(*this);
        M[0][0] = t.M[0][0] * m.M[0][0] + t.M[0][1] * m.M[1][0];
        M[1][0] = t.M[1][0] * m.M[0][0] + t.M[1][1] * m.M[1][0];
        M[0][1] = t.M[0][0] * m.M[0][1] + t.M[0][1] * m.M[1][1];
        M[1][1] = t.M[1][0] * m.M[0][1] + t.M[1][1] * m.M[1][1];
        M[0][2] = M[1][2] = 0;
        M[0][3] = t.M[0][0] * m.M[0][3] + t.M[0][1] * m.M[1][3] + t.M[0][3];
        M[1][3] = t.M[1][0] * m.M[0][3] + t.M[1][1] * m.M[1][3] + t.M[1][3];
        return *this;
    }
    Matrix2x4& PrependScaling(T sx, T sy) { return Prepend(Scaling(sx, sy)); }

    Matrix2x4& PrependTranslation(T x, T y)
    {
        M[0][3] = M[0][0] * x + M[0][1] * y + M[0][3];
        M[1][3] = M[1][0] * x + M[1][1] * y + M[1][3];
        return *this;
    }

    // Inverse of m; a singular m only gets its translation negated.
    void SetInverse(const Matrix2x4& m)
    {
        T det = m.M[0][0] * m.M[1][1] - m.M[0][1] * m.M[1][0];
        if (det == 0)
        {
            SetIdentity();
            M[0][3] = -m.M[0][3];
            M[1][3] = -m.M[1][3];
        }
        else
        {
            T inv = 1 / det;
            M[0][0] =  m.M[1][1] * inv;
            M[1][1] =  m.M[0][0] * inv;
            M[0][1] = -m.M[0][1] * inv;
            M[1][0] = -m.M[1][0] * inv;
            M[0][3] = -(M[0][0] * m.M[0][3] + M[0][1] * m.M[1][3]);
            M[1][3] = -(M[1][0] * m.M[0][3] + M[1][1] * m.M[1][3]);
        }
    }
    Matrix2x4& Invert()
    {
        SetInverse(Matrix2x4(*this));
        return *this;
    }

    void EncloseTransform(Rect<T>* dest, const Rect<T>& src) const;

    void SetMatrix(T sx, T shx, T tx, T shy, T sy, T ty)
    {
        M[0][0] = sx;  M[0][1] = shx; M[0][2] = 0; M[0][3] = tx;
        M[1][0] = shy; M[1][1] = sy;  M[1][2] = 0; M[1][3] = ty;
    }

    // Maps the parallelogram src (three corners: x0 y0 x1 y1 x2 y2) onto dst; defined outside the class (no inline
    // hint), as the exe keeps most calls to it (0x1425e74a0). SetRectToParl in turn is always expanded, also where
    // the call it wraps stays (TextMeshProvider::calcHeightRatio).
    Matrix2x4& SetParlToParl(const T* src, const T* dst);
    __forceinline Matrix2x4& SetRectToParl(T x1, T y1, T x2, T y2, const T* parl)
    {
        T src[6] = { x1, y1, x2, y1, x2, y2 };
        return SetParlToParl(src, parl);
    }
    Matrix2x4& SetParlToRect(const T* parl, T x1, T y1, T x2, T y2)
    {
        T dst[6] = { x1, y1, x2, y1, x2, y2 };
        return SetParlToParl(parl, dst);
    }
    // (appended for the tessellator, sfr_render_05c) maps the rectangle x1 y1 x2 y2 onto the rectangle dx1 dy1 dx2 dy2
    Matrix2x4& SetRectToRect(T x1, T y1, T x2, T y2, T dx1, T dy1, T dx2, T dy2)
    {
        T src[6];
        T dst[6];
        src[0] = x1;  src[1] = y1;  src[2] = x2;  src[3] = y1;  src[4] = x2;  src[5] = y2;
        dst[0] = dx1; dst[1] = dy1; dst[2] = dx2; dst[3] = dy1; dst[4] = dx2; dst[5] = dy2;
        return SetParlToParl(src, dst);
    }

    static Matrix2x4 Scaling(T sx, T sy)    { return Matrix2x4(sx, 0, 0, 0, sy, 0); }

    // this = Scaling(sx, sy) * this
    Matrix2x4& AppendScaling(T sx, T sy)
    {
        M[0][0] *= sx; M[0][1] *= sx; M[0][2] *= sx; M[0][3] *= sx;
        M[1][0] *= sy; M[1][1] *= sy; M[1][2] *= sy; M[1][3] *= sy;
        return *this;
    }
    static Matrix2x4 Translation(T x, T y)  { return Matrix2x4(1, 0, x, 0, 1, y); }

    // (appended for the shape cache nodes, sfr_render_03f)
    T GetDeterminant() const { return Sx() * Sy() - Shx() * Shy(); }
    // length of the image of the unit diagonal
    T GetScale() const
    {
        const T d = (T)0.707106781f;
        T x = Sx() * d + Shx() * d;
        T y = Shy() * d + Sy() * d;
        return sqrtf(x * x + y * y);
    }
    static Matrix2x4 Scaling(T s) { return Matrix2x4(s, 0, 0, 0, s, 0); }

    // (appended for the shape mesh provider, sfr_render_03d)
    static Matrix2x4 Identity;      // Matrix2F: 0x143aee520

    // the image of (1, 0) leaves both axes: neither a pure scale nor a quarter turn
    bool IsFreeRotation(T epsilon = 1e-6f) const
    {
        Matrix2x4 m(*this);
        m.M[0][3] = 0;
        m.M[1][3] = 0;
        T x = m.M[0][0] * 1 + m.M[0][1] * 0 + m.M[0][3];
        T y = m.M[1][0] * 1 + m.M[1][1] * 0 + m.M[1][3];
        return T(fabs(x)) > epsilon && T(fabs(y)) > epsilon;
    }

    // (appended for the shape bounds, sfr_render_03d) maps the point in place
    void Transform(T* x, T* y) const
    {
        T tx = *x;
        T ty = *y;
        *x   = M[0][0] * tx + M[0][1] * ty + M[0][3];
        *y   = M[1][0] * tx + M[1][1] * ty + M[1][3];
    }
    // lengths of the images of the unit axes
    T GetXScale() const { return sqrtf(Sx() * Sx() + Shy() * Shy()); }
    T GetYScale() const { return sqrtf(Shx() * Shx() + Sy() * Sy()); }

    // (appended for the display objects, sfr_gfx_06)
    static Matrix2x4 Rotation(T radians)
    {
        T c = cosf(radians);
        T s = sinf(radians);
        return Matrix2x4(c, -s, 0, s, c, 0);
    }
    // this = Rotation(radians) * this; out of line in GFx_DisplayObject (0x1425f0ec0)
    Matrix2x4& AppendRotation(T radians) { return Append(Rotation(radians)); }
    // all six coefficients finite (0x142515710)
    bool IsValid() const;
    // the axis scales and the rotation of the x axis, in double precision (the AS properties)
    double GetXScaleDouble() const   { return sqrt(double(Sx()) * double(Sx()) + double(Shy()) * double(Shy())); }
    double GetYScaleDouble() const   { return sqrt(double(Shx()) * double(Shx()) + double(Sy()) * double(Sy())); }
    double GetRotationDouble() const { return atan2(double(Shy()), double(Sx())); }
    // p mapped through the inverse (out of line, 0x1424471c0)
    void TransformByInverse(Point<T>* result, const Point<T>& p) const;
    // the x and y rows of a 3D matrix
    explicit Matrix2x4(const Matrix3x4<T>& m)
    {
        M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = m.M[0][3];
        M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = m.M[1][3];
    }

    // (appended for the containers, sfr_gfx_06d) p mapped through the inverse, by value (its COMDAT: 0x142447090)
    Point<T> TransformByInverse(const Point<T>& p) const
    {
        Matrix2x4 m(*this);
        m.Invert();
        return Point<T>(m.M[0][0] * p.x + m.M[0][1] * p.y + m.M[0][3], m.M[1][0] * p.x + m.M[1][1] * p.y + m.M[1][3]);
    }

    // (appended for the bitmap fills, sfr_gfx_06e)
    Matrix2x4 GetInverse() const
    {
        Matrix2x4 m;
        m.SetInverse(*this);
        return m;
    }
    Matrix2x4& AppendScaling(T s) { return AppendScaling(s, s); }
    // (appended for sfr_render_04h) this = Translation(x, y) * this
    Matrix2x4& AppendTranslation(T x, T y)
    {
        M[0][3] += x;
        M[1][3] += y;
        return *this;
    }
    Matrix2x4& AppendScaling(Size<T> scale) { return AppendScaling(scale.Width, scale.Height); }

    // (appended for the static text, sfr_gfx_05d) the rotation of the x axis (its COMDAT: 0x1425e1560)
    T GetRotation() const { return atan2f(Shy(), Sx()); }
    // (appended for the mesh keys, sfr_render_05d) x y through the 2x2 part only (no translation)
    void Transform2x2(T* x, T* y) const
    {
        T tx = *x;
        T ty = *y;
        *x   = M[0][0] * tx + M[0][1] * ty;
        *y   = M[1][0] * tx + M[1][1] * ty;
    }

    // (appended for flash.geom, sfr_as3_11) the class-scope spelling of the no-init tag
    typedef Render::NoInitType NoInitType;
    static const NoInitType NoInit = Render::NoInit;
    // this = m * this, the portable product (Append is the SSE one for float; Matrix2x4<double>: 0x142484280)
    Matrix2x4& Append_NonOpt(const Matrix2x4& m)
    {
        Matrix2x4 t(*this);
        M[0][0] = m.M[0][0] * t.M[0][0] + m.M[0][1] * t.M[1][0];
        M[1][0] = m.M[1][0] * t.M[0][0] + m.M[1][1] * t.M[1][0];
        M[0][1] = m.M[0][0] * t.M[0][1] + m.M[0][1] * t.M[1][1];
        M[1][1] = m.M[1][0] * t.M[0][1] + m.M[1][1] * t.M[1][1];
        M[0][2] = 0;
        M[1][2] = 0;
        M[0][3] = m.M[0][0] * t.M[0][3] + m.M[0][1] * t.M[1][3] + m.M[0][3];
        M[1][3] = m.M[1][0] * t.M[0][3] + m.M[1][1] * t.M[1][3] + m.M[1][3];
        return *this;
    }
};

template<class T>
Matrix2x4<T>& Matrix2x4<T>::SetParlToParl(const T* src, const T* dst)
{
    SetMatrix(src[2] - src[0], src[4] - src[0], src[0], src[3] - src[1], src[5] - src[1], src[1]);
    Matrix2x4 d(dst[2] - dst[0], dst[4] - dst[0], dst[0], dst[3] - dst[1], dst[5] - dst[1], dst[1]);
    Invert();
    Append(d);
    return *this;
}

typedef Matrix2x4<float> Matrix2F;

// The double matrix (flash.geom.Matrix keeps one): Append is the portable product and Rotation uses the double
// cos / sin.
template<> inline Matrix2x4<double>& Matrix2x4<double>::Append(const Matrix2x4<double>& m) { return Append_NonOpt(m); }
template<> inline Matrix2x4<double> Matrix2x4<double>::Rotation(double radians)
{
    double c = cos(radians);
    double s = sin(radians);
    return Matrix2x4<double>(c, -s, 0.0, s, c, 0.0);
}

// m1 * m2: m2 applied first (out of line in sfr_render_06g, 0x1426bf710)
const Matrix2x4<float> operator*(const Matrix2x4<float>& m1, const Matrix2x4<float>& m2);

}} // namespace Scaleform::Render

#endif
