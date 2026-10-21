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
    Point(T px, T py) : x(px), y(py) {}
    Point(const Point& p) { SetPoint(p.x, p.y); }

    void SetPoint(T px, T py) { x = px; y = py; }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    bool operator!=(const Point& p) const { return x != p.x || y != p.y; }
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
    bool    IsEmpty() const { return x1 == x2 || y1 == y2; }

    void SetRect(T left, T top, T right, T bottom) { x1 = left; y1 = top; x2 = right; y2 = bottom; }

    bool operator==(const Rect& r) const { return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2; }
    bool operator!=(const Rect& r) const { return !(*this == r); }
};

typedef Point<float>  PointF;
typedef Size<float>   SizeF;
typedef Rect<float>   RectF;
typedef Rect<int>     RectI;

}} // namespace Scaleform::Render

#endif
