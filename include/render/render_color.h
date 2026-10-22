// Recovered Scaleform 4.1.18 Render: Color, a 32-bit ARGB value (B, G, R, A bytes in memory).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_COLOR_H
#define MS2_SF_RENDER_COLOR_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Render {

class Color
{
public:
    union
    {
        struct
        {
            UByte Blue, Green, Red, Alpha;
        } Channels;
        UInt32 Raw;
    };

    Color() {}   // uninitialized: GetPixelInScanline leaves unknown formats unwritten
    Color(const Color& c) { SetColor(c); }   // user-declared: Color travels by address (the exe copies it to a temp)
    Color(UInt32 argb) : Raw(argb) {}
    Color(UByte r, UByte g, UByte b, UByte a = 0xFF)
    {
        Channels.Red = r; Channels.Green = g; Channels.Blue = b; Channels.Alpha = a;
    }

    UByte  GetRed() const     { return Channels.Red; }
    UByte  GetGreen() const   { return Channels.Green; }
    UByte  GetBlue() const    { return Channels.Blue; }
    UByte  GetAlpha() const   { return Channels.Alpha; }
    UInt32 ToColor32() const  { return Raw; }

    void SetRed(UByte v)   { Channels.Red = v; }
    void SetGreen(UByte v) { Channels.Green = v; }
    void SetBlue(UByte v)  { Channels.Blue = v; }
    void SetAlpha(UByte v) { Channels.Alpha = v; }
    void SetRGBA(UByte r, UByte g, UByte b, UByte a)
    {
        Channels.Red = r; Channels.Green = g; Channels.Blue = b; Channels.Alpha = a;
    }

    void SetColor(const Color& c) { Raw = c.Raw; }
    const Color& operator=(const Color& c) { Raw = c.Raw; return *this; }

    bool operator==(const Color& c) const { return Raw == c.Raw; }
    bool operator!=(const Color& c) const { return Raw != c.Raw; }

    // per-channel c1 * (1 - f) + c2 * f (Render_Color, 0x14266a500)
    static Color SF_STDCALL Blend(Color c1, Color c2, float f);

    // channels as 0..255 bytes / as 0..1 floats
    void SetRGB(UByte r, UByte g, UByte b)
    {
        Channels.Red = r; Channels.Green = g; Channels.Blue = b;
    }
    void GetRGB(UByte* r, UByte* g, UByte* b) const
    {
        *r = Channels.Red; *g = Channels.Green; *b = Channels.Blue;
    }
    void SetRGBFloat(float r, float g, float b)
    {
        Channels.Red   = UByte(r * 255.0f);
        Channels.Green = UByte(g * 255.0f);
        Channels.Blue  = UByte(b * 255.0f);
    }
    void GetRGBFloat(float* r, float* g, float* b) const
    {
        *r = (Channels.Red   == 0) ? 0.0f : Channels.Red   / 255.0f;
        *g = (Channels.Green == 0) ? 0.0f : Channels.Green / 255.0f;
        *b = (Channels.Blue  == 0) ? 0.0f : Channels.Blue  / 255.0f;
    }

    // Colour model conversions (Render_Color, 0x14266a5e0..0x14266b500): HSV as 0..360 / 0..255 integers or
    // 0..1 floats, HSI through the trigonometric RGB <-> HSI pair (hue in radians).
    void SetHSV(int h, int s, int v);
    void SetHSV(float h, float s, float v);
    void GetHSV(int* h, int* s, int* v) const;
    void GetHSV(float* h, float* s, float* v) const;
    void SetHSI(float h, float s, float i);
    void GetHSI(int* h, int* s, int* i) const;
    void GetHSI(float* h, float* s, float* i) const;
    static void SF_STDCALL ConvertRGBToHSI(double r, double g, double b, double* h, double* s, double* i);
    static void SF_STDCALL ConvertHSIToRGB(double h, double s, double i, double* r, double* g, double* b);

    // (appended for the AS3 filters, sfr12) the RGB part with a zero alpha; a raw ARGB value with its alpha replaced
    Color GetColorRGB() const              { return Color(Raw & 0x00FFFFFF); }
    void  SetColor(UInt32 raw, UByte a8)   { Raw = raw; SetAlpha(a8); }
};

}} // namespace Scaleform::Render

#endif
