// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the colour TU
// (Render_Color): the floating-point Blend and the colour model conversions of Render::Color (integer and
// float HSV, HSI through the trigonometric RGB <-> HSI pair).
// Queue unit sfr_render_04 is split along its original sources (04e Render_Color).
// MS2-UNIT: sfr_render_04e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14266a500-0x14266b500 .text$mn

#include <math.h>
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/kernel/sf_alg.h"

namespace Scaleform { namespace Render {

// The angles of the HSI sectors. The "two pi" the hue is folded with is 2 / pi, as in the shipped build.
static const Double Color_TwoOverPi   = 0.63661977236758134;
static const Double Color_PiOver3     = 1.0471975511965976;
static const Double Color_TwoPiOver3  = 2.0943951023931953;
static const Double Color_Pi          = 3.1415926535897931;
static const Double Color_FourPiOver3 = 4.1887902047863905;
static const Double Color_FivePiOver3 = 5.2359877559829887;

// @0x14266a500
Color Color::Blend(Color c1, Color c2, float f)
{
    Color c;
    c.Channels.Red   = (UByte)Alg::URound(Alg::Lerp((float)c1.Channels.Red,   (float)c2.Channels.Red,   f));
    c.Channels.Green = (UByte)Alg::URound(Alg::Lerp((float)c1.Channels.Green, (float)c2.Channels.Green, f));
    c.Channels.Blue  = (UByte)Alg::URound(Alg::Lerp((float)c1.Channels.Blue,  (float)c2.Channels.Blue,  f));
    c.Channels.Alpha = (UByte)Alg::URound(Alg::Lerp((float)c1.Channels.Alpha, (float)c2.Channels.Alpha, f));
    return c;
}

// Integer HSV: hue 0..359, saturation and value 0..255; a zero saturation or a negative hue is grey.
// @0x14266b2a0
void Color::SetHSV(int h, int s, int v)
{
    int r = v, g = v, b = v;
    if (s != 0 && h > -1)
    {
        if (h >= 360)
            h %= 360;
        unsigned f = h % 60;
        h /= 60;
        unsigned p = (unsigned)(2 * v * (255 - s) + 255) / 510;
        if (h & 1)
        {
            unsigned q = (unsigned)(2 * v * (15300 - s * f) + 15300) / 30600;
            switch (h)
            {
            case 1: r = (int)q; g = v;      b = (int)p; break;
            case 3: r = (int)p; g = (int)q; b = v;      break;
            case 5: r = v;      g = (int)p; b = (int)q; break;
            }
        }
        else
        {
            unsigned t = (unsigned)(2 * v * (15300 - s * (60 - f)) + 15300) / 30600;
            switch (h)
            {
            case 0: r = v;      g = (int)t; b = (int)p; break;
            case 2: r = (int)p; g = v;      b = (int)t; break;
            case 4: r = (int)t; g = (int)p; b = v;      break;
            }
        }
    }
    SetRGB(UByte(r), UByte(g), UByte(b));
}

// Float HSV, all three 0..1.
// @0x14266b3f0
void Color::SetHSV(float h, float s, float v)
{
    float r, g, b;
    if (s == 0)
    {
        r = g = b = v;
    }
    else
    {
        if (h == 1.0)
            h = 0.0;
        else
            h *= 6.0;
        float f = h - (int)h;
        float p = v * (1.0f - s);
        float q = v * (1.0f - s * f);
        float t = v * (1.0f - s * (1.0f - f));
        switch ((int)h)
        {
        case 0:  r = v; g = t; b = p; break;
        case 1:  r = q; g = v; b = p; break;
        case 2:  r = p; g = v; b = t; break;
        case 3:  r = p; g = q; b = v; break;
        case 4:  r = t; g = p; b = v; break;
        default: r = v; g = p; b = q; break;
        }
    }
    SetRGBFloat(r, g, b);
}

// @0x14266ad00
void Color::GetHSV(int* ph, int* ps, int* pv) const
{
    UByte br, bg, bb;
    GetRGB(&br, &bg, &bb);
    int r = br, g = bg, b = bb;

    enum { MaxRed, MaxGreen, MaxBlue };
    unsigned maxColor = r;
    int      maxType  = MaxRed;
    if ((unsigned)g > maxColor) { maxColor = g; maxType = MaxGreen; }
    if ((unsigned)b > maxColor) { maxColor = b; maxType = MaxBlue; }

    unsigned minColor = r;
    if ((unsigned)g < minColor) minColor = g;
    if ((unsigned)b < minColor) minColor = b;

    int delta = maxColor - minColor;
    *pv = maxColor;
    *ps = maxColor ? (510 * delta + maxColor) / (2 * maxColor) : 0;

    if (*ps == 0)
        *ph = 0;
    else
    {
        switch (maxType)
        {
        case MaxRed:
            if (g >= b)
                *ph = (120 * (g - b) + delta) / (2 * delta);
            else
                *ph = (120 * (g - b + delta) + delta) / (2 * delta) + 300;
            break;
        case MaxGreen:
            if (b > r)
                *ph = 120 + (120 * (b - r) + delta) / (2 * delta);
            else
                *ph = 60 + (120 * (b - r + delta) + delta) / (2 * delta);
            break;
        case MaxBlue:
            if (r > g)
                *ph = 240 + (120 * (r - g) + delta) / (2 * delta);
            else
                *ph = 180 + (120 * (r - g + delta) + delta) / (2 * delta);
            break;
        }
    }
}

// @0x14266ae50
void Color::GetHSV(float* ph, float* ps, float* pv) const
{
    float r, g, b;
    GetRGBFloat(&r, &g, &b);

    float minColor = Alg::Min(r, Alg::Min(g, b));
    float maxColor = Alg::Max(r, Alg::Max(g, b));
    float delta    = maxColor - minColor;

    *pv = maxColor;
    if (maxColor != 0)
        *ps = delta / maxColor;
    else
    {
        // black: no saturation, the hue is undefined
        *ps = 0.0;
        *ph = 0.0;
        return;
    }

    if (*ps == 0.0)
        *ph = 0.0;
    else
    {
        if (r == maxColor)
            *ph = (g - b) / delta;
        else if (g == maxColor)
            *ph = 2 + (b - r) / delta;
        else
            *ph = 4 + (r - g) / delta;
        *ph /= 6.0;
        if (*ph < 0.0) *ph += 1.0;
        if (*ph > 1.0) *ph -= 1.0;
    }
}

// @0x14266a990
void Color::GetHSI(int* ph, int* ps, int* pi) const
{
    float h, s, i;
    GetHSI(&h, &s, &i);
    *ph = int(h * 360);
    *ps = int(s * 255);
    *pi = int(i * 255);
}

// @0x14266aff0
void Color::SetHSI(float h, float s, float i)
{
    Double r, g, b;
    ConvertHSIToRGB(h, s, i, &r, &g, &b);
    SetRGBFloat((float)r, (float)g, (float)b);
}

// @0x14266ab60
void Color::GetHSI(float* ph, float* ps, float* pi) const
{
    float r, g, b;
    GetRGBFloat(&r, &g, &b);
    Double h, s, i;
    ConvertRGBToHSI(r, g, b, &h, &s, &i);
    *ph = (float)h;
    *ps = (float)s;
    *pi = (float)i;
}

// @0x14266a860
void Color::ConvertRGBToHSI(Double r, Double g, Double b, Double* ph, Double* ps, Double* pi)
{
    Double i = (r + g + b) / 3.0;
    Double s = (i == 0.0) ? 1.0 : 1.0 - (Alg::Min(Alg::Min(r, g), b) / i);
    Double h;
    if (r == g && g == b)
        h = 0.0;
    else
    {
        Double t = acos((0.5 * (r - g + r - b)) / sqrt((r - g) * (r - g) + (r - b) * (g - b)));
        h = (g > b) ? t : Color_TwoOverPi - t;
    }
    *ph = h;
    *ps = s;
    *pi = i;
}

// @0x14266a5e0
void Color::ConvertHSIToRGB(Double h, Double s, Double i, Double* pr, Double* pg, Double* pb)
{
    Double ht, r, g, b;
    if (h == 0.0)
        r = g = b = i;
    else if (h > 0.0 && h < Color_TwoPiOver3)
    {
        ht = 1 / sqrt(3.0) * tan(h - Color_PiOver3);
        b  = (1.0 - s) * i;
        g  = (1.5 + 1.5 * ht) * i - ((0.5 + 1.5 * ht) * b);
        r  = 3.0 * i - g - b;
    }
    else if (h >= Color_TwoPiOver3 && h < Color_FourPiOver3)
    {
        ht = 1 / sqrt(3.0) * tan(h - Color_Pi);
        r  = (1.0 - s) * i;
        b  = (1.5 + 1.5 * ht) * i - ((0.5 + 1.5 * ht) * r);
        g  = 3.0 * i - b - r;
    }
    else
    {
        ht = 1 / sqrt(3.0) * tan(h - Color_FivePiOver3);
        g  = (1.0 - s) * i;
        r  = (1.5 + 1.5 * ht) * i - ((0.5 + 1.5 * ht) * g);
        b  = 3.0 * i - r - g;
    }
    *pr = r;
    *pg = g;
    *pb = b;
}

}} // namespace Scaleform::Render
