// Recovered Scaleform 4.1.18 Render: the image resizer (Render_ResizeImage) the texture code uses to rescale image
// data that a HAL cannot take at its size: nearest pixel (box), bilinear, and a separable filtered resize through a
// weight table (ImageFilterLut). Coordinates are fixed point with 8 fraction bits, filter weights with 14.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_RESIZEIMAGE_H
#define MS2_SF_RENDER_RESIZEIMAGE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_arrayunsafe.h"
#include "ms2/scaleform/include/render/render_textureutil.h"

namespace Scaleform { namespace Render {

// Steps y1 -> y2 in count integer steps without division per step (Bresenham style carry).
class LinearInterpolator
{
public:
    LinearInterpolator() {}
    LinearInterpolator(int y1, int y2, int count)
        : Cnt(count), Lft((y2 - y1) / count), Rem((y2 - y1) % count), Y(y1)
    {
        Mod = Rem;
        if (Mod <= 0)
        {
            Mod += count;
            Rem += count;
            Lft--;
        }
        Mod -= count;
    }

    void operator++()
    {
        Mod += Rem;
        Y   += Lft;
        if (Mod > 0)
        {
            Mod -= Cnt;
            Y++;
        }
    }

    int y() const { return Y; }

private:
    int Cnt;
    int Lft;
    int Rem;
    int Mod;
    int Y;
};

enum ImageFilterConstants
{
    ImgSubpixelShift   = 8,
    ImgSubpixelShift2  = ImgSubpixelShift * 2,
    ImgSubpixelScale   = 1 << ImgSubpixelShift,
    ImgSubpixelMask    = ImgSubpixelScale - 1,
    ImgSubpixelOffset  = ImgSubpixelScale / 2,
    ImgSubpixelInitial = ImgSubpixelScale * ImgSubpixelScale / 2,

    ImgFilterShift = 14,
    ImgFilterScale = 1 << ImgFilterShift,
    ImgFilterMask  = ImgFilterScale - 1,

    ImgMaxFilterRadius = 8
};

// The weights of a symmetric filter, sampled at 1/256 pixel over its whole diameter.
class ImageFilterLut
{
public:
    ImageFilterLut() : Radius(0), Diameter(0), Start(0) {}

    template<class FilterF> ImageFilterLut(const FilterF& filter, bool normalization = true)
    {
        Calculate(filter, normalization);
    }

    template<class FilterF> void Calculate(const FilterF& filter, bool normalization = true)
    {
        reallocLut(filter.GetRadius());
        unsigned pivot = GetDiameter() << (ImgSubpixelShift - 1);
        for (unsigned i = 0; i < pivot; i++)
        {
            float w = filter.GetWeight(float(i) / float(ImgSubpixelScale));
            WeightArray[pivot + i] = WeightArray[pivot - i] = SInt16(Alg::IRound(w * ImgFilterScale));
        }
        WeightArray[0] = WeightArray[(GetDiameter() << ImgSubpixelShift) - 1];
        if (normalization)
            Normalize();
    }

    float         GetRadius() const      { return Radius; }
    unsigned      GetDiameter() const    { return Diameter; }
    int           GetStart() const       { return Start; }
    const SInt16* GetWeightArray() const { return &WeightArray[0]; }
    void          Normalize();                            // 0x1426eeb00

private:
    void reallocLut(float radius);                        // 0x1426efa60
    ImageFilterLut(const ImageFilterLut&);
    const ImageFilterLut& operator=(const ImageFilterLut&);

    float                         Radius;
    unsigned                      Diameter;
    int                           Start;
    Scaleform::ArrayUnsafe<SInt16> WeightArray;
};

struct ImageFilterBilinear
{
    float GetRadius() const        { return 1.0f; }
    float GetWeight(float x) const { return 1.0f - x; }
};

void SF_STDCALL ResizeImageBox(UByte* pDst, int dstWidth, int dstHeight, int dstPitch, const UByte* pSrc,
                               int srcWidth, int srcHeight, int srcPitch, ResizeImageType type);        // 0x1426ef900
void SF_STDCALL ResizeImageBilinear(UByte* pDst, int dstWidth, int dstHeight, int dstPitch, const UByte* pSrc,
                                    int srcWidth, int srcHeight, int srcPitch, ResizeImageType type);   // 0x1426ef7a0
void SF_STDCALL ResizeImage(UByte* pDst, int dstWidth, int dstHeight, int dstPitch, const UByte* pSrc,
                            int srcWidth, int srcHeight, int srcPitch, ResizeImageType type,
                            const ImageFilterLut& filter);                                             // 0x1426ef220

}} // namespace Scaleform::Render

#endif
