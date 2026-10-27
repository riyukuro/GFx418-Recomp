// Recovered Scaleform 4.1.18 Render: the viewport a tree root renders into (buffer size, view rectangle in buffer
// pixels, optional scissor rectangle), 0x2c bytes.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_VIEWPORT_H
#define MS2_SF_RENDER_VIEWPORT_H

#include "ms2/scaleform/include/render/render_types2d.h"

namespace Scaleform { namespace Render {

class Viewport
{
public:
    int      BufferWidth, BufferHeight;
    int      Left, Top;
    int      Width, Height;
    int      ScissorLeft, ScissorTop;
    int      ScissorWidth, ScissorHeight;
    unsigned Flags;

    enum
    {
        View_IsRenderTexture    = 0x01,
        View_AlphaComposite     = 0x02,
        View_UseScissorRect     = 0x04,
        View_NoSetState         = 0x08,
        View_Orientation_Normal = 0x00,
        View_Orientation_R90    = 0x10,
        View_Orientation_180    = 0x20,
        View_Orientation_L90    = 0x30,
        View_Orientation_Mask   = 0x30,
        View_RenderTextureAlpha = View_IsRenderTexture | View_AlphaComposite,
        // (appended for sfr_render_06g) the half of a side-by-side / top-bottom stereo buffer drawn into
        View_Stereo_SplitV      = 0x40,
        View_Stereo_SplitH      = 0x80,
        View_Stereo_AnySplit    = 0xc0,
        View_FirstHalFlag       = 0x100
    };

    // assigned in the body, the height before the width (the exe's store order; an initializer list lets the
    // compiler merge the stores into vector writes)
    Viewport()
    {
        BufferWidth  = 0;
        BufferHeight = 0;
        Left = Top   = 0;
        Width = Height = 1;
        ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
        Flags        = 0;
    }

    // a view rectangle inside a buffer, no scissor (the game's /Od COMDAT 0x14127c490: the flags after the rectangle,
    // then the scissor zeroed from the height down)
    Viewport(int bufw, int bufh, int left, int top, int w, int h, unsigned flags = 0)
    {
        BufferWidth  = bufw;
        BufferHeight = bufh;
        Left         = left;
        Top          = top;
        Width        = w;
        Height       = h;
        Flags        = flags;
        ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
    }

    // (appended for sfr_render_04g) a view rectangle inside a buffer of the given size, no scissor
    Viewport(const Size<UInt32>& bufferSize, const Rect<int>& view, unsigned flags = 0)
    {
        BufferWidth  = (int)bufferSize.Width;
        BufferHeight = (int)bufferSize.Height;
        Left         = view.x1;
        Top          = view.y1;
        Width        = view.x2 - view.x1;
        Height       = view.y2 - view.y1;
        Flags        = flags;
        ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
    }

    // (appended for sfr_render_04h) a field-by-field copy, the flags taken right after the view rectangle
    Viewport(const Viewport& o)
    {
        BufferWidth   = o.BufferWidth;
        BufferHeight  = o.BufferHeight;
        Left          = o.Left;
        Top           = o.Top;
        Width         = o.Width;
        Height        = o.Height;
        Flags         = o.Flags;
        ScissorLeft   = o.ScissorLeft;
        ScissorTop    = o.ScissorTop;
        ScissorWidth  = o.ScissorWidth;
        ScissorHeight = o.ScissorHeight;
    }

    bool IsValid() const { return BufferWidth != 0 && BufferHeight != 0; }

    // every field, in declaration order
    bool operator==(const Viewport& o) const
    {
        return BufferWidth == o.BufferWidth && BufferHeight == o.BufferHeight &&
               Left == o.Left && Top == o.Top && Width == o.Width && Height == o.Height &&
               ScissorLeft == o.ScissorLeft && ScissorTop == o.ScissorTop &&
               ScissorWidth == o.ScissorWidth && ScissorHeight == o.ScissorHeight && Flags == o.Flags;
    }
    bool operator!=(const Viewport& o) const { return !(*this == o); }

    // (appended for sfr_render_06g) the visible part of the view inside the buffer (and the scissor when asked);
    // false when nothing is left
    template<class T>
    bool GetClippedRect(Rect<T>* prect, bool useScissor = false) const;
    // narrows the view to one eye's half of a split stereo buffer (StereoDisplay value)
    void SetStereoViewport(unsigned display);

    // (appended for sfr_render_05j) the clipped view relative to its own top-left corner (sfr_render_05j,
    // 0x1426814b0)
    bool GetCullRectF(RectF* prect, bool orient = true) const;

    // clip-space bounds ([-1, 1], y up) to pixels of a width x height view (y down, so the y bounds swap)
    template<class T>
    static RectF ScaleToViewport(T left, T top, T width, T height, RectF& bounds)
    {
        RectF r;
        r.x1 = scaleX((int)left, (int)width, bounds.x1);
        r.y1 = scaleY((int)top, (int)height, bounds.y2);
        r.x2 = scaleX((int)left, (int)width, bounds.x2);
        r.y2 = scaleY((int)top, (int)height, bounds.y1);
        return r;
    }

private:
    static float scaleX(int, int width, float x) { return width * (x + 1) / 2.f; }
    static float scaleY(int, int height, float y) { return height * (-y + 1) / 2.f; }
};

}} // namespace Scaleform::Render

#endif
