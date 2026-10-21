// Recovered Scaleform 4.1.18 Render: gradient fills - the gradient record list (GradientData), the image that
// renders it into a ramp or radial texture (GradientImage), and the parallelogram-to-matrix helpers.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64): GradientData 0x30, GradientImage 0x48 (AMP build: the image id
// sits at +0x44). Bodies live in sfr_render_02b (Render_Gradients).
#ifndef MS2_SF_RENDER_GRADIENTS_H
#define MS2_SF_RENDER_GRADIENTS_H

#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"

namespace Scaleform { namespace Render {

class GradientRecord
{
public:
    GradientRecord() : Ratio(0) {}
    GradientRecord(UByte r, Color c) : Ratio(r), ColorV(c) {}

    UByte Ratio;
    Color ColorV;

    GradientRecord LerpTo(const GradientRecord& r2, float t) const
    {
        return GradientRecord((UByte)Alg::Lerp((float)Ratio, (float)r2.Ratio, t), Color::Blend(ColorV, r2.ColorV, t));
    }
    unsigned GetHashValue() const { return Ratio ^ (ColorV.Raw ^ (ColorV.Raw >> 16)); }

    bool operator==(const GradientRecord& o) const { return Ratio == o.Ratio && ColorV == o.ColorV; }
    bool operator!=(const GradientRecord& o) const { return !(*this == o); }
};

enum GradientType
{
    GradientLinear,
    GradientRadial,
    GradientFocalPoint      // radial, focus moved along x
};

class GradientData : public RefCountBase<GradientData, StatGroup_GFxMovieData + 1>
{
    enum { DefaultImageSize = 64 };
public:
    GradientData(GradientType type, UInt16 recordCount = 0, bool linearRgb = false);
    ~GradientData();

    void                SetMorphTo(const GradientData* morphTo) { pMorphTo = morphTo; }
    const GradientData* GetMorphTo() const                      { return pMorphTo; }

    bool                  SetRecordCount(UInt16 count, bool tmpHeap = false);
    UInt16                GetRecordCount() const     { return RecordCount; }
    const GradientRecord* GetRecords() const         { return pRecords; }
    void                  SetFocalRatio(float ratio) { FocalRatio = ratio; }
    float                 GetFocalRatio() const      { return FocalRatio; }
    bool                  IsLinearRGB() const        { return LinearRGB; }
    void                  SetLinearRGB(bool v)       { LinearRGB = v; }
    GradientType          GetGradientType() const    { return (GradientType)Type; }

    void     SetLerp(const GradientData* from, const GradientData* to, float t);
    unsigned CalcImageSize() const;

    GradientRecord&       At(unsigned i)       { return pRecords[i]; }
    const GradientRecord& At(unsigned i) const { return pRecords[i]; }

    UPInt GetHashValue(float morphRatio) const;
    bool  operator==(const GradientData& o) const;

private:
    bool                LinearRGB;      // +0x10
    UByte               Type;           // +0x11
    UInt16              RecordCount;    // +0x12
    GradientRecord*     pRecords;       // +0x18
    float               FocalRatio;     // +0x20
    const GradientData* pMorphTo;       // +0x28

    static const unsigned ImageSizeTable[];
};

struct GradientKey
{
    GradientKey(const GradientData* data, float morphRatio) : pData(data), MorphRatio(morphRatio) {}
    UPInt operator()() const { return pData->GetHashValue(MorphRatio); }
    bool  operator==(const GradientKey& o)
    {
        return *pData == *o.pData && (pData->GetMorphTo() == 0 || MorphRatio == o.MorphRatio);
    }

    const GradientData* pData;
    float               MorphRatio;
};

class PrimitiveFillManager;

class GradientImage : public Image
{
    enum { MaxImageSize = 256 };
public:
    GradientImage(PrimitiveFillManager* mng, GradientData* data = 0, float morphRatio = 0);
    virtual ~GradientImage();

    virtual ImageType   GetImageType() const   { return Type_GradientImage; }
    virtual ImageFormat GetFormat() const      { return Image_R8G8B8A8; }
    virtual ImageSize   GetSize() const        { return Size; }
    virtual unsigned    GetUse() const         { return 0; }
    virtual unsigned    GetMipmapCount() const { return 1; }
    virtual bool        Decode(ImageData* pdest, CopyScanlineFunc copyScanline = CopyScanlineDefault,
                               void* arg = 0) const;
    virtual Texture*    GetTexture(TextureManager* manager);

    const GradientData* GetGradientData() const { return pData; }
    float               GetMorphRatio() const   { return MorphRatio; }

    struct PtrHashFunctor
    {
        UPInt operator()(const GradientImage* g) const
        {
            return g->GetGradientData()->GetHashValue(g->GetMorphRatio());
        }
        UPInt operator()(const GradientKey& k) const { return k.pData->GetHashValue(k.MorphRatio); }
    };
    bool operator==(const GradientImage& o) const { return *pData == *o.pData && MorphRatio == o.MorphRatio; }

    virtual Image*  GetAsImage()                   { return this; }
    virtual UPInt   GetBytes(int* memRegion) const { if (memRegion) *memRegion = 0; return 4 * Size.Area(); }
    virtual UInt32  GetImageId() const             { return ImageId; }
    virtual UInt32  GetBaseImageId() const         { return 0; }

private:
    PrimitiveFillManager* pManager;     // +0x28
    Ptr<GradientData>     pData;        // +0x30
    ImageSize             Size;         // +0x38
    float                 MorphRatio;   // +0x40
    UInt32                ImageId;      // +0x44
};

inline bool operator==(const GradientImage* img, const GradientKey& key)
{
    return *img->GetGradientData() == *key.pData &&
           (key.pData->GetMorphTo() == 0 || img->GetMorphRatio() == key.MorphRatio);
}

Matrix2F LineToMatrix2D(float x1, float y1, float x2, float y2);
Matrix2F ParlToMatrix2D(float x1, float y1, float x2, float y2, float x3, float y3);

}} // namespace Scaleform::Render

#endif
