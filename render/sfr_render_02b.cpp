// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the gradient TU
// (Render_Gradients): gradient record lists, the 256-entry color ramp, the gradient image that renders linear,
// radial and focal ramps into a texture, and the parallelogram-to-matrix helpers of the gradient fills.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients).
// MS2-UNIT: sfr_render_02b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e5970-0x1425e7930 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <math.h>
#include <string.h>
#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/render/render_primitive.h"

namespace Scaleform { namespace Render {

// Ramp sizes by steepness bucket (see CalcImageSize).
const unsigned GradientData::ImageSizeTable[] =
{
    16, 32, 32, 64, 64, 64, 64, 128, 128, 128, 128, 128, 128, 256, 256, 256, 256, 256
};

// @0x1425e5970
GradientData::GradientData(GradientType type, UInt16 recordCount, bool linearRgb)
    : LinearRGB(linearRgb), Type(UByte(type)), RecordCount(0), pRecords(0), FocalRatio(0), pMorphTo(0)
{
    SetRecordCount(recordCount);
}

// @0x1425e60d0
GradientData::~GradientData()
{
    if (pRecords)
        SF_FREE(pRecords);
}

// Resizes the record array, keeping the common prefix. Temporary (morph) data goes to the global heap, the rest
// to the heap that owns this object.
// @0x1425e7850
bool GradientData::SetRecordCount(UInt16 count, bool tmpHeap)
{
    if (count == RecordCount)
        return true;

    GradientRecord* recs = tmpHeap ? (GradientRecord*)SF_ALLOC(sizeof(GradientRecord) * count, Stat_Default_Mem)
                                   : (GradientRecord*)SF_HEAP_AUTO_ALLOC(this, sizeof(GradientRecord) * count);
    if (!recs)
        return false;

    if (pRecords)
    {
        UInt16 keep = Alg::Min(count, RecordCount);
        for (UInt16 i = 0; i < keep; i++)
            recs[i] = pRecords[i];
        SF_FREE(pRecords);
    }
    pRecords    = recs;
    RecordCount = count;
    return true;
}

// @0x1425e73a0
void GradientData::SetLerp(const GradientData* from, const GradientData* to, float t)
{
    Type = (UByte)from->GetGradientType();
    SetRecordCount(from->GetRecordCount(), true);
    for (UInt16 i = 0; i < RecordCount; i++)
        pRecords[i] = from->At(i).LerpTo(to->At(i), t);
    FocalRatio = Alg::Lerp(from->GetFocalRatio(), to->GetFocalRatio(), t);
}

// @0x1425e7000
UPInt GradientData::GetHashValue(float morphRatio) const
{
    UPInt hash = Type;
    for (UInt16 i = 0; i < RecordCount; i++)
        hash ^= pRecords[i].GetHashValue();
    if (pMorphTo)
    {
        UInt32 bits;
        memcpy(&bits, &morphRatio, 4);
        hash ^= (bits & 0xFFFF) ^ (bits >> 16);
    }
    return hash;
}

// @0x1425e6150
bool GradientData::operator==(const GradientData& o) const
{
    if (RecordCount != o.RecordCount || Type != o.Type || FocalRatio != o.FocalRatio || LinearRGB != o.LinearRGB)
        return false;
    for (unsigned i = 0; i < RecordCount; i++)
        if (pRecords[i] != o.pRecords[i])
            return false;
    return true;
}

// Picks the ramp texture size from the steepest channel change between neighbouring records.
// @0x1425e6390
unsigned GradientData::CalcImageSize() const
{
    float maxSlope = 0;
    for (unsigned i = 1; i < GetRecordCount(); i++)
    {
        const GradientRecord& a = pRecords[i - 1];
        const GradientRecord& b = pRecords[i];
        float dx = (float)b.Ratio - (float)a.Ratio;
        if (dx > 0)
        {
            float s;
            s = abs((int)a.ColorV.GetRed()   - (int)b.ColorV.GetRed())   / dx; if (s > maxSlope) maxSlope = s;
            s = abs((int)a.ColorV.GetGreen() - (int)b.ColorV.GetGreen()) / dx; if (s > maxSlope) maxSlope = s;
            s = abs((int)a.ColorV.GetBlue()  - (int)b.ColorV.GetBlue())  / dx; if (s > maxSlope) maxSlope = s;
            s = abs((int)a.ColorV.GetAlpha() - (int)b.ColorV.GetAlpha()) / dx; if (s > maxSlope) maxSlope = s;
        }
    }
    if (maxSlope == 0)
        return DefaultImageSize;

    if (LinearRGB)
        maxSlope *= 1.5f;
    if (Type == GradientFocalPoint)
    {
        float r = (float)fabs(FocalRatio);
        if (r > 0.5f)
            maxSlope /= 1.01f - r;
    }
    if (maxSlope < 0)
        maxSlope = 0;

    unsigned idx = (unsigned)sqrtf((maxSlope + 0.18f) * 5);
    if (idx >= sizeof(ImageSizeTable) / sizeof(ImageSizeTable[0]))
        idx = sizeof(ImageSizeTable) / sizeof(ImageSizeTable[0]) - 1;
    return ImageSizeTable[idx];
}

// ---------------------------------------------------------------------------------------------------------------
// GradientRamp: 256 RGBA entries interpolated between the records, optionally in a gamma-corrected space
// (16-bit per channel while blending).

class GradientRamp
{
public:
    enum { RampSize = 256, R = 0, G = 1, B = 2, A = 3 };

    GradientRamp(const GradientRecord* records, unsigned recordCount, float gamma = 1);

    void         WriteRGBA(unsigned i, UByte* rgba) const { memcpy(rgba, Ramp + i * 4, 4); }
    const UByte* GetRampBytes() const                     { return Ramp; }

private:
    struct Color16
    {
        UInt16 r, g, b, a;
        Color16() {}
        Color16(UInt16 r_, UInt16 g_, UInt16 b_, UInt16 a_) : r(r_), g(g_), b(b_), a(a_) {}
    };

    static UInt16 toLinear(UByte v, float gamma)
    {
        return (UInt16)floor(pow(v / 255.0f, gamma) * 65535.0f + 0.5f);
    }
    static UByte fromLinear(UInt16 v, float gamma)
    {
        return (UByte)floor(pow(v / 65535.0f, gamma) * 255.0f + 0.5f);
    }
    static Color16 toLinear(const Color& c, float gamma)
    {
        int a = c.GetAlpha();
        return Color16(toLinear(c.GetRed(), gamma), toLinear(c.GetGreen(), gamma), toLinear(c.GetBlue(), gamma),
                       UInt16((a << 8) | a));
    }

    // c1 + (c2 - c1) * ratio / maxRatio, color channels through the inverse gamma
    static void blend(UByte* c, const Color16& c1, const Color16& c2, int ratio, int maxRatio, float gammaInv)
    {
        int alphaDiv = (maxRatio << 8) | maxRatio;
        c[R] = fromLinear(UInt16(c1.r + int(c2.r - c1.r) * ratio / maxRatio), gammaInv);
        c[G] = fromLinear(UInt16(c1.g + int(c2.g - c1.g) * ratio / maxRatio), gammaInv);
        c[B] = fromLinear(UInt16(c1.b + int(c2.b - c1.b) * ratio / maxRatio), gammaInv);
        c[A] = UByte(c1.a + int(c2.a - c1.a) * ratio / alphaDiv);
    }
    // gamma 1: the 16-bit channels are byte-doubled, so divide by the doubled range
    static void blend(UByte* c, const Color16& c1, const Color16& c2, int ratio, int maxRatio)
    {
        maxRatio = (maxRatio << 8) | maxRatio;
        c[R] = UByte(c1.r + int(c2.r - c1.r) * ratio / maxRatio);
        c[G] = UByte(c1.g + int(c2.g - c1.g) * ratio / maxRatio);
        c[B] = UByte(c1.b + int(c2.b - c1.b) * ratio / maxRatio);
        c[A] = UByte(c1.a + int(c2.a - c1.a) * ratio / maxRatio);
    }

    UByte Ramp[RampSize * 4];
};

// @0x1425e5a90
GradientRamp::GradientRamp(const GradientRecord* records, unsigned recordCount, float gamma)
{
    unsigned i;
    if (recordCount == 0 || records == 0)
    {
        GradientRecord black;
        black.Ratio  = 0;
        black.ColorV = 0xFF000000;
        recordCount  = 1;
        records      = &black;
    }

    UByte c[4];
    c[R] = records[0].ColorV.GetRed();
    c[G] = records[0].ColorV.GetGreen();
    c[B] = records[0].ColorV.GetBlue();
    c[A] = records[0].ColorV.GetAlpha();

    if (recordCount > 1)
    {
        unsigned start    = records[0].Ratio;
        unsigned end      = 0;
        float    gammaInv = 1 / gamma;

        for (i = 0; i < start; i++)
            memcpy(Ramp + i * 4, c, 4);

        for (i = 1; i < recordCount; i++)
        {
            end = records[i].Ratio;
            if (end < start)
                end = start;

            Color16  c1 = toLinear(records[i - 1].ColorV, gamma);
            Color16  c2 = toLinear(records[i].ColorV, gamma);
            unsigned x0 = start;
            unsigned dx = end - start;

            if (gamma == 1)
            {
                for (; start < end; ++start)
                {
                    blend(c, c1, c2, start - x0 + 1, dx);
                    memcpy(Ramp + start * 4, c, 4);
                }
            }
            else
            {
                for (; start < end; ++start)
                {
                    blend(c, c1, c2, start - x0 + 1, dx, gammaInv);
                    memcpy(Ramp + start * 4, c, 4);
                }
            }
            c[R] = UByte(c2.r >> 8);
            c[G] = UByte(c2.g >> 8);
            c[B] = UByte(c2.b >> 8);
            c[A] = UByte(c2.a >> 8);
        }
        for (; end < RampSize; end++)
            memcpy(Ramp + end * 4, c, 4);
    }
    else
    {
        for (i = 0; i < RampSize; i++)
            memcpy(Ramp + i * 4, c, 4);
    }
}

// ---------------------------------------------------------------------------------------------------------------
// FocalRadialGradient: ratio of a point inside a circle whose gradient origin is moved off center.

class FocalRadialGradient
{
public:
    void  Init(float r, float fx, float fy);
    float Calculate(float x, float y) const;

private:
    float Radius;
    float FocusX;
    float FocusY;
    float Radius2;
    float Multiplier;
};

// A focus exactly on the circle would divide by zero: pull it one unit inwards.
// @0x1425e7180
void FocalRadialGradient::Init(float r, float fx, float fy)
{
    Radius = r;
    FocusX = fx;
    FocusY = fy;
    float fx2 = FocusX * FocusX;
    float fy2 = FocusY * FocusY;
    Radius2   = Radius * Radius;
    float d   = Radius2 - (fx2 + fy2);
    if (d == 0)
    {
        if (FocusX != 0) { if (FocusX < 0) FocusX += 1; else FocusX -= 1; }
        if (FocusY != 0) { if (FocusY < 0) FocusY += 1; else FocusY -= 1; }
        fx2 = FocusX * FocusX;
        fy2 = FocusY * FocusY;
        d   = Radius2 - (fx2 + fy2);
    }
    Multiplier = Radius / d;
}

// @0x1425e6820
float FocalRadialGradient::Calculate(float x, float y) const
{
    float dx = x - FocusX;
    float dy = y - FocusY;
    float d2 = dx * FocusY - dy * FocusX;
    float d3 = Radius2 * (dx * dx + dy * dy) - d2 * d2;
    return (dx * FocusX + dy * FocusY + sqrtf((float)fabs(d3))) * Multiplier;
}

// ---------------------------------------------------------------------------------------------------------------
// GradientImage

// @0x1425e59d0
GradientImage::GradientImage(PrimitiveFillManager* mng, GradientData* data, float morphRatio)
    : pManager(mng), pData(data), Size(1, 1), MorphRatio(morphRatio)
{
    if (data)
    {
        if (data->GetGradientType() == GradientLinear)
        {
            Size.Width  = MaxImageSize;
            Size.Height = 1;
        }
        else
        {
            Size.Width = Size.Height = data->CalcImageSize();
        }
    }
    ImageId = ImageBase::GetNextImageId();
}

// @0x1425e6110
GradientImage::~GradientImage()
{
    if (pManager)
        pManager->removeGradient(this);
}

// Linear gradients are one ramp row; radial ones a square whose border is the last ramp color.
// @0x1425e68e0
bool GradientImage::Decode(ImageData* pdest, CopyScanlineFunc copyScanline, void* arg) const
{
    ImagePlane dplane;
    pdest->GetPlane(0, &dplane);
    UByte* dst = dplane.pData;
    UByte  src[4 * MaxImageSize];

    if (pData.GetPtr() == 0)
    {
        src[0] = src[1] = src[2] = src[3] = 0;
        copyScanline(dst, src, 4, 0, arg);
        return true;
    }

    const GradientData* data  = pData;
    const GradientData* morph = pData->GetMorphTo();
    GradientData        tmpData(GradientLinear);
    if (morph)
    {
        tmpData.SetLerp(data, morph, MorphRatio);
        data = &tmpData;
    }

    GradientRamp ramp(data->GetRecords(), data->GetRecordCount(), data->IsLinearRGB() ? 2.17f : 1.0f);

    float    center, radius, x, y;
    int      ratio;
    UByte    last[4];
    UPInt    toLast = dplane.Pitch * (Size.Height - 1);
    unsigned i, j, size;

    if (data->GetGradientType() == GradientLinear)
    {
        for (i = 0; i < Size.Height; ++i)
            copyScanline(dst, ramp.GetRampBytes(), 4 * Size.Width, 0, arg);
    }
    else
    {
        ramp.WriteRGBA(255, last);
        for (i = 0; i < Size.Width; ++i)
            memcpy(src + 4 * i, last, 4);
        copyScanline(dst, src, 4 * Size.Width, 0, arg);
        copyScanline(dst + toLast, src, 4 * Size.Width, 0, arg);

        center = Size.Width / 2.0f;
        radius = center - 1;
        size   = Size.Width - 1;
        memcpy(src, last, 4);
        memcpy(src + Size.Width * 4 - 4, last, 4);

        FocalRadialGradient gr;
        if (data->GetGradientType() == GradientFocalPoint)
            gr.Init(radius, data->GetFocalRatio() * radius, 0);

        dst += dplane.Pitch;
        for (j = 1; j < size; j++)
        {
            if (data->GetGradientType() == GradientRadial)
            {
                for (i = 1; i < size; i++)
                {
                    y     = j - center + 0.5f;
                    x     = i - center + 0.5f;
                    ratio = (int)floorf((float)sqrt(x * x + y * y) * 256 / radius + 0.5f);
                    if (ratio > 255)
                        ratio = 255;
                    ramp.WriteRGBA(ratio, src + i * 4);
                }
            }
            else
            {
                for (i = 1; i < size; i++)
                {
                    y     = j - center + 0.5f;
                    x     = i - center + 0.5f;
                    ratio = (int)floorf(gr.Calculate(x, y) * 256 / radius + 0.5f);
                    if (ratio > 255)
                        ratio = 255;
                    ramp.WriteRGBA(ratio, src + i * 4);
                }
            }
            copyScanline(dst, src, 4 * Size.Width, 0, arg);
            dst += dplane.Pitch;
        }
    }
    return true;
}

// @0x1425e70b0
Texture* GradientImage::GetTexture(TextureManager* manager)
{
    if (pTexture && pTexture->GetTextureManager() == manager)
        return pTexture;
    if (!manager)
        return 0;

    pTexture = 0;
    Texture* tex = manager->CreateTexture(GetFormat(), 1, Size, ImageUse_Wrap, this);
    initTexture_NoAddRef(tex);
    return tex;
}

// ---------------------------------------------------------------------------------------------------------------
// Gradient fill matrices: map the unit square onto a line's band or onto a parallelogram.

// @0x1425e7230
Matrix2F LineToMatrix2D(float x1, float y1, float x2, float y2)
{
    Matrix2F m;
    float dx = (x2 - x1) / 2;
    float dy = (y2 - y1) / 2;
    float parl[6] = { x1 - dy, y1 + dx, x1 + dy, y1 - dx, x2 + dy, y2 - dx };
    m.SetParlToRect(parl, 0, 0, 1, 1);
    return m;
}

// @0x1425e7310
Matrix2F ParlToMatrix2D(float x1, float y1, float x2, float y2, float x3, float y3)
{
    Matrix2F m;
    float parl[6] = { x1, y1, x2, y2, x3, y3 };
    m.SetParlToRect(parl, 0, 0, 1, 1);
    return m;
}

template Matrix2F& Matrix2F::SetParlToParl(const float* src, const float* dst);
template Matrix2F& Matrix2F::SetParlToRect(const float* parl, float x1, float y1, float x2, float y2);

}} // namespace Scaleform::Render

// MS2-PIN: ?SetParlToParl@?$Matrix2x4@M@Render@Scaleform@@QEAAAEAV123@PEBM0@Z 0x1425e74a0
// MS2-PIN: ?SetParlToRect@?$Matrix2x4@M@Render@Scaleform@@QEAAAEAV123@PEBMMMMM@Z 0x1425e7690
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7GradientData@Render@Scaleform@@6B@ 0x14318cbb8
// MS2-PIN: ??_7GradientImage@Render@Scaleform@@6B@ 0x14318cbc0
