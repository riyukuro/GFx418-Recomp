// Recovered Scaleform 4.1.18 Render: 2D value types (Point, Size, Rect). Written from the exe's use of them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TYPES2D_H
#define MS2_SF_RENDER_TYPES2D_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"

namespace Scaleform { namespace Render {

template<class T>
class Point
{
public:
    T x, y;

    Point() : x(0), y(0) {}
    enum NoInitType { NoInit };
    Point(NoInitType) {}
    Point(T px, T py) : x(px), y(py) {}
    Point(const Point& p) { SetPoint(p.x, p.y); }

    void SetPoint(T px, T py) { x = px; y = py; }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    bool operator!=(const Point& p) const { return x != p.x || y != p.y; }
    // (appended for the line buffer, sfr_render_04d)
    Point& operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
    Point& operator-=(const Point& p) { x -= p.x; y -= p.y; return *this; }
};

template<class T>
class Size
{
public:
    T Width, Height;

    Size() : Width(0), Height(0) {}
    enum NoInitType { NoInit };
    Size(NoInitType) {}
    explicit Size(T s) : Width(s), Height(s) {}
    Size(T w, T h) : Width(w), Height(h) {}
    // user-declared copy: the exe passes Size by address (ImageSize_MipLevelCount takes a pointer to the copy)
    // (both fields are read before either is stored, as through SetSize(w, h))
    Size(const Size& sz) { SetSize(sz.Width, sz.Height); }
    Size& operator=(const Size& sz) { SetSize(sz.Width, sz.Height); return *this; }

    void SetSize(T w, T h) { Width = w; Height = h; }
    bool IsEmpty() const   { return Width == 0 || Height == 0; }
    // (appended for sfr_render_04h) the same size in another type, each field cast
    template<class S> operator Size<S>() const { return Size<S>((S)Width, (S)Height); }
    T    Area() const      { return Width * Height; }

    bool operator==(const Size& s) const { return Width == s.Width && Height == s.Height; }
    bool operator!=(const Size& s) const { return Width != s.Width || Height != s.Height; }
};

// Edges are stored (x1, y1, x2, y2); x2/y2 are exclusive for integer rects.
template<class T>
class Rect
{
public:
    T x1, y1, x2, y2;

    Rect() : x1(0), y1(0), x2(0), y2(0) {}
    Rect(T left, T top, T right, T bottom) : x1(left), y1(top), x2(right), y2(bottom) {}
    Rect(T left, T top, const Size<T>& sz) : x1(left), y1(top), x2(left + sz.Width), y2(top + sz.Height) {}
    Rect(const Size<T>& sz) : x1(0), y1(0), x2(sz.Width), y2(sz.Height) {}
    // copies read all four edges before storing any (SubImage keeps a copy of its rect)
    Rect(const Rect& r) { SetRect(r.x1, r.y1, r.x2, r.y2); }

    T       Width() const   { return x2 - x1; }
    T       Height() const  { return y2 - y1; }
    Size<T> GetSize() const { return Size<T>(Width(), Height()); }
    // empty or inverted
    bool    IsEmpty() const { return x1 >= x2 || y1 >= y2; }

    void SetRect(T left, T top, T right, T bottom) { x1 = left; y1 = top; x2 = right; y2 = bottom; }

    bool operator==(const Rect& r) const { return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2; }
    bool operator!=(const Rect& r) const { return !(*this == r); }
    // (appended for sfr_render_04h) the same rectangle in another type, each edge cast
    template<class S> operator Rect<S>() const { return Rect<S>((S)x1, (S)y1, (S)x2, (S)y2); }

    // (appended for the tree nodes, sfr_render_03)
    explicit Rect(T v) : x1(v), y1(v), x2(v), y2(v) {}
    // assignment reads all four edges first, like the copy constructor
    Rect& operator=(const Rect& r) { SetRect(r.x1, r.y1, r.x2, r.y2); return *this; }
    enum NoInitType { NoInit };
    Rect(NoInitType) {}
    void SetRect(const Point<T>& tl, const Point<T>& br) { SetRect(tl.x, tl.y, br.x, br.y); }

    Point<T> TopLeft() const     { return Point<T>(x1, y1); }
    Point<T> TopRight() const    { return Point<T>(x2, y1); }
    Point<T> BottomLeft() const  { return Point<T>(x1, y2); }
    Point<T> BottomRight() const { return Point<T>(x2, y2); }

    Rect& Expand(T l, T t, T r, T b) { x1 -= l; x2 += r; y1 -= t; y2 += b; return *this; }
    Rect& Expand(T h, T v)           { return Expand(h, v, h, v); }
    Rect& HExpand(T l, T r)          { x1 -= l; x2 += r; return *this; }
    Rect& VExpand(T t, T b)          { y1 -= t; y2 += b; return *this; }
    Rect& Contract(T l, T t, T r, T b) { x1 += l; x2 -= r; y1 += t; y2 -= b; return *this; }
    Rect& Contract(T h, T v)           { return Contract(h, v, h, v); }
    Rect& HContract(T l, T r)          { x1 += l; x2 -= r; return *this; }
    Rect& VContract(T t, T b)          { y1 += t; y2 -= b; return *this; }

    Rect& ExpandToPoint(const Point<T>& p)
    {
        x1 = Alg::Min<T>(x1, p.x);
        y1 = Alg::Min<T>(y1, p.y);
        x2 = Alg::Max<T>(x2, p.x);
        y2 = Alg::Max<T>(y2, p.y);
        return *this;
    }
    void UnionRect(Rect* dest, const Rect& r) const
    {
        dest->x1 = (x1 > r.x1) ? r.x1 : x1;
        dest->x2 = (x2 > r.x2) ? x2 : r.x2;
        dest->y1 = (y1 > r.y1) ? r.y1 : y1;
        dest->y2 = (y2 > r.y2) ? y2 : r.y2;
    }

    // (appended for the AS2 Rectangle, sfr_as2_01) edges count as inside
    bool Contains(T x, T y) const         { return x <= x2 && x >= x1 && y <= y2 && y >= y1; }
    bool Contains(const Point<T>& p) const { return p.x <= x2 && p.x >= x1 && p.y <= y2 && p.y >= y1; }
    bool Contains(const Rect& r) const     { return x2 >= r.x2 && y2 >= r.y2 && x1 <= r.x1 && y1 <= r.y1; }
    bool Intersects(const Rect& r) const   { return y2 >= r.y1 && r.y2 >= y1 && r.x2 >= x1 && x2 >= r.x1; }
    // Overlap of the two into dest; false (dest untouched) when they are apart.
    bool IntersectRect(Rect* dest, const Rect& r) const
    {
        if (!Intersects(r))
            return false;
        dest->x1 = (x1 > r.x1) ? x1 : r.x1;
        dest->x2 = (x2 > r.x2) ? r.x2 : x2;
        dest->y1 = (y1 > r.y1) ? y1 : r.y1;
        dest->y2 = (y2 > r.y2) ? r.y2 : y2;
        return true;
    }

    // (appended for the shape bounds, sfr_render_03d)
    Rect& ExpandToPoint(T x, T y)
    {
        x1 = Alg::Min<T>(x1, x);
        y1 = Alg::Min<T>(y1, y);
        x2 = Alg::Max<T>(x2, x);
        y2 = Alg::Max<T>(y2, y);
        return *this;
    }
    // not inverted (an empty bound box starts out inverted)
    bool IsNormal() const { return x1 <= x2 && y1 <= y2; }

    // (appended for the display list, sfr_gfx_06c) grows this to cover the other rect
    Rect& Union(T left, T top, T right, T bottom)
    {
        Rect u;
        UnionRect(&u, Rect(left, top, right, bottom));
        SetRect(u.x1, u.y1, u.x2, u.y2);
        return *this;
    }
    Rect& Union(const Rect& r) { return Union(r.x1, r.y1, r.x2, r.y2); }

    // (appended for the line buffer, sfr_render_04d) sizes move the right / bottom edge
    void Clear()           { x1 = 0; y1 = 0; x2 = 0; y2 = 0; }
    void SetWidth(T w)     { x2 = x1 + w; }
    void SetHeight(T h)    { y2 = y1 + h; }
    Rect& Offset(T dx, T dy)              { x1 += dx; x2 += dx; y1 += dy; y2 += dy; return *this; }
    Rect& operator+=(const Point<T>& p)   { return Offset(p.x, p.y); }
    Rect& operator-=(const Point<T>& p)   { return Offset(-p.x, -p.y); }

    // (appended for the buttons, sfr_gfx_05c) a point rect (the zero rect included)
    bool IsNull() const { return x2 == x1 && y2 == y1; }
};

typedef Point<float>  PointF;
typedef Size<float>   SizeF;
typedef Rect<float>   RectF;
typedef Rect<int>     RectI;
// (appended for the display objects, sfr_gfx_06)
typedef Rect<double>  RectD;

}} // namespace Scaleform::Render

#endif
