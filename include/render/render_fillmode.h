// Recovered Scaleform 4.1.18 Render: how an image fill is wrapped and sampled (one byte, passed by address since it
// has a user copy constructor; Texture::ApplyTexture reads it as [r8]). Names from the SDK headers.
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_RENDER_FILLMODE_H
#define MS2_SF_RENDER_FILLMODE_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Render {

enum WrapMode
{
    Wrap_Repeat = 0x00,
    Wrap_Clamp  = 0x01,
    Wrap_Mask   = 0x01,
    Wrap_Count  = 2
};

enum SampleMode
{
    Sample_Point  = 0x00,
    Sample_Linear = 0x02,
    Sample_Mask   = 0x02,
    Sample_Count  = 2,
    Sample_Shift  = 1
};

// bit 0 the wrap mode, bit 1 the sample mode
struct ImageFillMode
{
    UByte Fill;

    ImageFillMode() : Fill(Wrap_Repeat | Sample_Point) {}
    ImageFillMode(WrapMode wrap, SampleMode sample) : Fill((UByte)(wrap | sample)) {}
    ImageFillMode(const ImageFillMode& o) : Fill(o.Fill) {}
    void operator=(const ImageFillMode& o) { Fill = o.Fill; }
    bool operator==(const ImageFillMode& o) const { return Fill == o.Fill; }
    bool operator!=(const ImageFillMode& o) const { return Fill != o.Fill; }

    WrapMode   GetWrapMode() const   { return (WrapMode)(Fill & Wrap_Mask); }
    SampleMode GetSampleMode() const { return (SampleMode)(Fill & Sample_Mask); }
};

}} // namespace Scaleform::Render

#endif
