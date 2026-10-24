// Recovered Scaleform 4.1.18 Render: PerlinGenerator, the integer lattice noise behind BitmapData.perlinNoise
// (DICommand_PerlinNoise::ExecuteSW picks one of eight generators per channel and interpolates SmoothNoise).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PERLIN_H
#define MS2_SF_RENDER_PERLIN_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Render { class ImageData; } }

// DICommand_PerlinNoise::ExecuteSW (sfr_as3_22).
extern "C" void FUN_142677740(void* operation, void*, Scaleform::Render::ImageData* image);

namespace Scaleform { namespace Render {

// The lattice hash: row stride and the three polynomial coefficients.
class PerlinGenerator
{
    friend void ::FUN_142677740(void*, void*, ImageData*);

    int Stride; // +0x0
    int A;      // +0x4
    int B;      // +0x8
    int C;      // +0xc

    float noise(int x, int y) const
    {
        int n = y * Stride + x;
        n = (n << 13) ^ n;
        return 1.0f - (float)(((A * n * n + B) * n + C) & 0x7fffffff) * (1.0f / 1073741824.0f);
    }

    float SmoothNoise(int x, int y);
};
static_assert(sizeof(PerlinGenerator) == 0x10, "PerlinGenerator size");

}} // namespace Scaleform::Render

#endif
