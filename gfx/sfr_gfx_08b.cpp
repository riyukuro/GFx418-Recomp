// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_FilterDesc (the SWF filter list
// of PlaceObject3 and button records, read from a Stream or from a StreamContext over memory).
// Second source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142663400-0x142664b70 .text$mn

#include "../include/gfx/gfx_stream.h"
#include "../include/kernel/sf_memory.h"
#include "../include/render/render_color.h"
#include "../include/render/render_filters.h"

namespace Scaleform { namespace GFx {

using Render::BlurFilterParams;
using Render::Filter;
using Render::FilterSet;
using Render::FilterType;

// SWF filter ids.
enum SwfFilterId
{
    SwfFilter_DropShadow    = 0,
    SwfFilter_Blur          = 1,
    SwfFilter_Glow          = 2,
    SwfFilter_Bevel         = 3,
    SwfFilter_GradientGlow  = 4,
    SwfFilter_Convolution   = 5,
    SwfFilter_ColorMatrix   = 6,
    SwfFilter_GradientBevel = 7
};

// Which optional fields a blur-family record carries.
enum BlurFilterFields
{
    BlurField_Color     = 0x1,
    BlurField_Highlight = 0x2, // a second color (only with BlurField_Color)
    BlurField_Offset    = 0x4, // angle and distance
    BlurField_Strength  = 0x8
};

// Reads the blur-family record fields into params. passesMask selects the bits of the flags byte that hold the
// pass count; 0xf8 marks the blur record, whose count sits above three reserved bits and which has no other flags.
template<class S>
void ReadBlurFilter(S* ps, BlurFilterParams* params, float* angle, float* distance, unsigned fields, FilterType type,
                    unsigned passesMask)
{
    if (fields & BlurField_Color)
    {
        ps->ReadRgba(&params->Colors[0]);
        if (fields & BlurField_Highlight)
            ps->ReadRgba(&params->Colors[1]);
    }

    // 16.16 fixed point pixels.
    params->BlurX = Render::PixelsToTwips((float)ps->ReadU32() * (1.0f / 65536.0f));
    params->BlurY = Render::PixelsToTwips((float)ps->ReadU32() * (1.0f / 65536.0f));

    if (fields & BlurField_Offset)
    {
        *angle    = (float)ps->ReadU32() * (1.0f / 65536.0f);
        *distance = (float)ps->ReadU32() * (1.0f / 65536.0f);
    }
    if (fields & BlurField_Strength)
        params->Strength = (float)ps->ReadU16() * (1.0f / 256.0f);

    unsigned flags = ps->ReadU8();
    unsigned mode  = 0;
    if (passesMask == 0xf8)
    {
        params->Passes = flags >> 3;
    }
    else
    {
        mode = (flags & 0x80) ? BlurFilterParams::Mode_Inner : 0;
        if (flags & 0x40)
            mode |= BlurFilterParams::Mode_Knockout;
        if (!(flags & 0x20))
            mode |= BlurFilterParams::Mode_HideObject;
        if (passesMask <= 0xf && (flags & 0x10))
            mode |= BlurFilterParams::Mode_Highlight;
        params->Passes = flags & passesMask;
    }
    params->Mode = type | mode;
}

// The SWF matrix is 4 rows of 4 multipliers and an offset; the filter keeps the 16 multipliers first.
static const UByte ColorMatrixOrder[Render::ColorMatrixFilter::ColorMatrixEntries] = {
    0, 1, 2, 3, 16, 4, 5, 6, 7, 17, 8, 9, 10, 11, 18, 12, 13, 14, 15, 19
};

// Reads a filter list and appends the supported filters to filters (when given). Returns the count added.
template<class S>
unsigned LoadFilters(S* ps, FilterSet* filters)
{
    UByte    filterCount = ps->ReadU8();
    unsigned numFilters  = 0;
    float    angle       = 0;
    float    distance    = 0;

    MemoryHeap* heap = filters ? Memory::GetHeapByAddress(filters) : Memory::GetGlobalHeap();

    while (filterCount--)
    {
        UByte            filterId  = ps->ReadU8();
        unsigned         skipBytes = 0;
        Ptr<Filter>      filter    = 0;
        BlurFilterParams params;

        switch (filterId)
        {
        case SwfFilter_DropShadow:
            ReadBlurFilter(ps, &params, &angle, &distance, BlurField_Color | BlurField_Offset | BlurField_Strength,
                           Render::Filter_Shadow, 0x1f);
            filter = *SF_HEAP_NEW(heap) Render::ShadowFilter(params, angle, distance);
            break;

        case SwfFilter_Blur:
            ReadBlurFilter(ps, &params, (float*)0, (float*)0, 0, Render::Filter_Blur, 0xf8);
            filter = *SF_HEAP_NEW(heap) Render::BlurFilter(params);
            break;

        case SwfFilter_Glow:
            ReadBlurFilter(ps, &params, (float*)0, (float*)0, BlurField_Color | BlurField_Strength,
                           Render::Filter_Glow, 0x1f);
            filter = *SF_HEAP_NEW(heap) Render::GlowFilter(params);
            break;

        case SwfFilter_Bevel:
            ReadBlurFilter(ps, &params, &angle, &distance,
                           BlurField_Color | BlurField_Highlight | BlurField_Offset | BlurField_Strength,
                           Render::Filter_Bevel, 0xf);
            filter = *SF_HEAP_NEW(heap) Render::BevelFilter(params, angle, distance);
            break;

        case SwfFilter_Convolution:
        {
            // Not supported: skipped (matrix of x * y floats, divisor, bias, color, flags).
            unsigned matrixX = ps->ReadU8();
            unsigned matrixY = ps->ReadU8();
            skipBytes        = matrixX * matrixY * 4 + 13;
            break;
        }

        case SwfFilter_ColorMatrix:
        {
            Ptr<Render::ColorMatrixFilter> cm = *SF_HEAP_NEW(heap) Render::ColorMatrixFilter();
            filter                            = cm;
            for (unsigned i = 0; i < Render::ColorMatrixFilter::ColorMatrixEntries; i++)
                (*cm)[ColorMatrixOrder[i]] = ps->ReadFloat();
            // The offsets are 0..255 in the file.
            for (unsigned i = 16; i < 20; i++)
                (*cm)[i] *= 1.0f / 255.0f;
            numFilters++;
            break;
        }

        case SwfFilter_GradientGlow:
        case SwfFilter_GradientBevel:
        {
            // Not supported: skipped (count colors and ratios, then the blur fields).
            unsigned numColors = ps->ReadU8();
            skipBytes          = numColors * 5 + 19;
            break;
        }
        }

        if (filters && filter)
        {
            filters->AddFilter(filter);
            numFilters++;
        }
        while (skipBytes--)
            ps->ReadU8();
    }
    return numFilters;
}

// Both readers are instantiated here (exe: StreamContext 0x142663400, Stream 0x142663c60; ReadBlurFilter
// 0x142664290 / 0x142664640, the out-of-line BevelFilter / ShadowFilter ctors 0x1426649a0 / 0x142664a90).
template unsigned LoadFilters<StreamContext>(StreamContext* ps, FilterSet* filters);
template unsigned LoadFilters<Stream>(Stream* ps, FilterSet* filters);

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7?$RefCountBase@VFilter@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7Filter@Render@Scaleform@@6B@ 0x14315ac78
// MS2-PIN: ??_7BlurFilterImpl@Render@Scaleform@@6B@ 0x14315ac90
// MS2-PIN: ??_7BlurFilter@Render@Scaleform@@6B@ 0x14315aca8
// MS2-PIN: ??_7ShadowFilter@Render@Scaleform@@6B@ 0x14315acc0
// MS2-PIN: ??_7GlowFilter@Render@Scaleform@@6B@ 0x14315acd8
// MS2-PIN: ??_7BevelFilter@Render@Scaleform@@6B@ 0x14315acf0
