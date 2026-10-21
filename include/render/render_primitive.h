// Recovered Scaleform 4.1.18 Render: primitive fills. Only what the recovered units call so far: the fill manager
// keeps a cache of gradient images and a GradientImage unregisters itself on destruction.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVE_H
#define MS2_SF_RENDER_PRIMITIVE_H

#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/render/render_fillmode.h"
#include "ms2/scaleform/include/render/render_vertex.h"
#include "ms2/scaleform/kernel/sf_hash.h"

namespace Scaleform { namespace Render {

// (appended for the shape cache nodes, sfr_render_03f)
class PrimitiveFill;
class TextureManager;

enum FillType
{
    Fill_None,
    Fill_Mask,
    Fill_SolidColor,
    Fill_VColor,
    Fill_Image,
    Fill_Gradient,
    Fill_VColor_TestKey
};

class Image;
struct VertexFormat;

// the shader input a fill needs (FillData::PrimFill)
enum PrimitiveFillType
{
    PrimFill_None,
    PrimFill_Mask,
    PrimFill_SolidColor,
    PrimFill_VColor,
    PrimFill_VColor_EAlpha,
    PrimFill_Texture,
    PrimFill_Texture_EAlpha,
    PrimFill_Texture_VColor,
    PrimFill_Texture_VColor_EAlpha,
    PrimFill_2Texture,
    PrimFill_2Texture_EAlpha,
    PrimFill_UVTexture,
    PrimFill_UVTextureAlpha_VColor,
    PrimFill_UVTextureDFAlpha_VColor
};

// what a provider reports for one fill: its type, color or image / gradient, and vertex format (0x20 bytes)
class FillData
{
public:
    FillType     Type;          // +0x00
    union                       // +0x08: Color for a solid fill, else the image / gradient
    {
        UInt32        Color;
        GradientData* pGradient;
        Image*        pImage;
    };
    unsigned      PrimFill;     // +0x10 (4 by default, 1 for a solid fill)
    ImageFillMode FillMode;     // +0x14
    const VertexFormat* pVFormat; // +0x18

    FillData(FillType type = Fill_VColor);    // 0x14266bc00 (Render_Primitive)
    // (appended for sfr_render_03d) Render_Primitive: 0x14266bba0, 0x14266bbd0
    FillData(GradientData* gradient);
    FillData(Image* image, ImageFillMode fillMode);
};

// (appended for sfr_render_03d) the vertex layouts a shape mesh fill names
struct VertexXY16iCF32
{
    static VertexFormat Format;   // 0x143a2fbe8
};
struct Image9GridVertex
{
    static VertexFormat Format;   // 0x143a2f968
};

class HAL;
class PrimitiveFillManager;

// (appended for sfr_render_04f) what the tessellator recorded into the vertices of a merged fill
enum FillMergeFlags
{
    FillMerge_None          = 0x00,
    FillMerge_EAlpha        = 0x01,   // edge alpha
    FillMerge_Weight        = 0x02,   // blend weight between the two fills
    FillMerge_EAlpha_Weight = FillMerge_EAlpha | FillMerge_Weight
};

// (appended for sfr_render_04f) What a hardware fill is made of: the shader input, a solid colour and up to two
// textures with their fill modes, and the vertex format (0x28 bytes). Fills are shared through the manager, keyed
// on these values.
struct PrimitiveFillData
{
    PrimitiveFillType   Type;           // +0x00
    Color               SolidColor;     // +0x04
    ImageFillMode       FillModes[2];   // +0x08
    Ptr<Texture>        Textures[2];    // +0x10
    const VertexFormat* pFormat;        // +0x20

    PrimitiveFillData(PrimitiveFillType type, const VertexFormat* format)
        : Type(type), SolidColor(0), pFormat(format) {}
    PrimitiveFillData(PrimitiveFillType type, const VertexFormat* format, Color c)
        : Type(type), SolidColor(c), pFormat(format) {}
    PrimitiveFillData(PrimitiveFillType type, const VertexFormat* format, Texture* texture0,
                      ImageFillMode fm0 = ImageFillMode(), Texture* texture1 = 0, ImageFillMode fm1 = ImageFillMode())
        : Type(type), SolidColor(0), pFormat(format)
    {
        FillModes[0] = fm0;
        FillModes[1] = fm1;
        Textures[0]  = texture0;
        Textures[1]  = texture1;
    }
    PrimitiveFillData(const PrimitiveFillData& o)
        : Type(o.Type), SolidColor(o.SolidColor), pFormat(o.pFormat)
    {
        FillModes[0] = o.FillModes[0];
        FillModes[1] = o.FillModes[1];
        Textures[0]  = o.Textures[0];
        Textures[1]  = o.Textures[1];
    }

    bool operator==(const PrimitiveFillData& o) const;
    bool operator!=(const PrimitiveFillData& o) const { return !operator==(o); }

    UPInt GetHashValue() const
    {
        return Type ^ SolidColor.ToColor32() ^ (FillModes[0].Fill << 2) ^ (FillModes[1].Fill << 4) ^
               (((UPInt)Textures[0].GetPtr()) >> 2) ^ ((UPInt)Textures[1].GetPtr()) ^ pFormat->Size;
    }

    // The format carries the channels the fill type reads (positions always).
    static bool CheckVertexFormat(PrimitiveFillType fill, const VertexFormat* format);
};

// A shared hardware fill; equal data always maps to the same object, so fills compare by pointer.
class PrimitiveFill : public RefCountBaseNTS<PrimitiveFill, StatRender_Fill_Mem>
{
    void operator=(const PrimitiveFill&);
protected:
    const PrimitiveFillData Data;       // +0x10
    PrimitiveFillManager*   pManager;   // +0x38
public:
    PrimitiveFill(const PrimitiveFillData& data, PrimitiveFillManager* manager = 0)
        : Data(data), pManager(manager) {}
    ~PrimitiveFill();

    PrimitiveFillType        GetType() const                     { return Data.Type; }
    Color                    GetSolidColor() const               { return Data.SolidColor; }
    Texture*                 GetTexture(unsigned i = 0) const    { return Data.Textures[i]; }
    ImageFillMode            GetFillMode(unsigned i = 0) const   { return Data.FillModes[i]; }
    const VertexFormat*      GetVertexFormat() const             { return Data.pFormat; }
    UPInt                    GetHashValue() const                { return Data.GetHashValue(); }
    const PrimitiveFillData& GetData() const                     { return Data; }
    void                     SetManager(PrimitiveFillManager* m) { pManager = m; }
    PrimitiveFillManager*    GetManager() const                  { return pManager; }

    struct PtrHashFunctor
    {
        UPInt operator()(const PrimitiveFill* fill) const        { return fill->GetHashValue(); }
        UPInt operator()(const PrimitiveFillData& data) const    { return data.GetHashValue(); }
    };
};

inline bool operator==(const PrimitiveFill* fill, const PrimitiveFillData& data)
{
    return fill->GetData() == data;
}

// The live fills and gradient images, so equal ones are shared (fill pointers are batch sort keys).
class PrimitiveFillManager : public RefCountBase<PrimitiveFillManager, StatRender_Fill_Mem>
{
    friend class PrimitiveFill;
    friend class GradientImage;

    typedef HashSetLH<PrimitiveFill*, PrimitiveFill::PtrHashFunctor> FillHashSet;
    typedef HashSetLH<GradientImage*, GradientImage::PtrHashFunctor> GradientHashSet;

public:
    PrimitiveFillManager(HAL* hal) : pHAL(hal) {}

    PrimitiveFill* CreateFill(const PrimitiveFillData& data);
    // the shared fill for fillData (0x14266d170); a gradient fill reports its image through gradientImage
    PrimitiveFill* CreateFill(const FillData& fillData, Ptr<Image>* gradientImage, TextureManager* textureManager,
                              float morphRatio);
    // A fill merging fd0 and fd1 as the tessellator laid them into the vertices (mergeFlags: FillMergeFlags).
    PrimitiveFill* CreateMergedFill(unsigned mergeFlags, const VertexFormat* format, const FillData* fd0,
                                    const FillData* fd1, Ptr<Image>* gradientImage0, Ptr<Image>* gradientImage1,
                                    TextureManager* textureManager, float morphRatio);

    HAL* GetHAL() const { return pHAL; }

private:
    void   removeFill(PrimitiveFill* fill);
    void   removeGradient(GradientImage* img);    // 0x14266f380 (Render_Primitive)
    // The registered image for (data, morphRatio), created when missing; the caller owns the reference.
    Image* createGradientImage(GradientData* data, float morphRatio);

    HAL*            pHAL;        // +0x10
    FillHashSet     FillSet;     // +0x18
    GradientHashSet Gradients;   // +0x20
};

}} // namespace Scaleform::Render

#endif
