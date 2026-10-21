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

    bool operator==(const Color& c) const { return Raw == c.Raw; }
    bool operator!=(const Color& c) const { return Raw != c.Raw; }
};

}} // namespace Scaleform::Render

#endif
