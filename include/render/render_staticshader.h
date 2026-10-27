// Recovered Scaleform 4.1.18 Render: the static shader manager a HAL with precompiled shaders builds on (D3D9_HAL
// section of sfr_d3d9_01, unit sfr_d3d9_01e). Written from the exe; names from the SDK headers.
// It picks the shader type of a fill and maps a mesh's source vertex format to the formats the shaders read (single,
// batched and instanced draws), keeping every computed mapping in a hash. Layout (0x30 bytes): VFormats +0x00,
// Profiler* +0x20, VertexFormatComputedHash +0x28.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_STATICSHADER_H
#define MS2_SF_RENDER_STATICSHADER_H

#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_filters.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"

namespace Scaleform { namespace Render {

// MapVertexFormat flags
enum MapVertexFormatFlags
{
    MVF_Align             = 0x01,   // the format size is a multiple of its largest component
    MVF_AlignVertexAttrs  = 0x02,   // every attribute starts on 4 bytes
    MVF_ReverseColor      = 0x04,   // colors are stored ARGB (a D3DCOLOR) instead of RGBA
    MVF_HasInstancing     = 0x08,   // make an instanced format too
    MVF_EndianSwapFactors = 0x10,   // the factor bytes are stored in the reverse order
};

template<class FragShaderDesc, class VertexShaderDesc, class Uniform, class ShaderInterface, class NativeTexture>
class StaticShaderManager
{
public:
    // a mapping already made: the fill, the source format and the flags it was made with
    struct SourceFormatHash
    {
        PrimitiveFillType   FillType;       // +0x00
        const VertexFormat* SourceFormat;   // +0x08
        unsigned            FormatFlags;    // +0x10

        SourceFormatHash() {}
        SourceFormatHash(PrimitiveFillType fill, const VertexFormat* source, unsigned flags)
            : FillType(fill), SourceFormat(source), FormatFlags(flags) {}

        bool operator==(const SourceFormatHash& o) const
        {
            return FillType == o.FillType && SourceFormat == o.SourceFormat && FormatFlags == o.FormatFlags;
        }
    };

    struct ResultFormat
    {
        const VertexFormat* SingleFormat;
        const VertexFormat* BatchFormat;
        const VertexFormat* InstancedFormat;
    };

    StaticShaderManager(HAL::ProfileViews* profiler) : Profiler(profiler) {}

    // the fragment shader type of a fill; fillFlags picks the variants (bit 0 multiply cxform, bit 2 eaddalpha, bit 3
    // instanced cxform) and is updated for the fills that need them
    unsigned StaticShaderForFill(PrimitiveFillType fill, unsigned& fillFlags, unsigned batchType) const   // 0x142736880 (a member: rcx = this, unused)
    {
        unsigned shader;
        switch (fill)
        {
        case PrimFill_VColor:                 shader = 0x41;   break;
        case PrimFill_VColor_EAlpha:          shader = 0x61;   break;
        case PrimFill_Texture:                shader = 0x1;    break;
        case PrimFill_Texture_EAlpha:         shader = 0x21;   break;
        case PrimFill_Texture_VColor:         shader = 0x4001; break;
        case PrimFill_Texture_VColor_EAlpha:  shader = 0x4021; break;
        case PrimFill_2Texture:               shader = 0x81;   break;
        case PrimFill_2Texture_EAlpha:        shader = 0xa1;   break;
        case PrimFill_UVTexture:              shader = 0x8403; break;
        case PrimFill_UVTextureAlpha_VColor:
            fillFlags |= 4;
            shader = 0x9003;
            break;
        case PrimFill_UVTextureDFAlpha_VColor:
            fillFlags |= 4;
            return 0;
        default:
            fillFlags &= ~4u;
            shader = 0x8003;
            break;
        }
        if ((fillFlags & 4) && shader != 0x9003)
            shader += 0x10;
        if (batchType == PrimitiveBatch::DP_Batch)
            shader += 2;
        else if (batchType == PrimitiveBatch::DP_Instanced)
            shader += 4;
        if (fillFlags & 1)
            shader += 1;
        if (fillFlags & 8)
            shader += 8;
        return shader;
    }

    // the stored format with these elements, made on first use
    const VertexFormat* GetVertexFormat(VertexElement* elements, unsigned count, unsigned size, unsigned align)   // 0x142732130
    {
        VertexFormat* format = VFormats.Find(elements, count);
        if (format)
            return format;

        VertexElement* newElements = 0;
        format = VFormats.Add(&newElements, elements, count);
        if (!format)
            return 0;
        format->Size      = (size + align - 1) & ~(align - 1);
        format->pElements = newElements;
        return format;
    }

    // the formats the shaders of a fill read for a source format: the shader's attributes in its order, each taken
    // from the source (the factors attribute is made up); the batch format adds the instance index argument, the
    // instanced one a per-instance index stream. All three are 0 when the source lacks an attribute.
    void MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat, const VertexFormat** single,
                         const VertexFormat** batch, const VertexFormat** instanced, unsigned flags)   // 0x142732210
    {
        SourceFormatHash key(fill, sourceFormat, flags);
        ResultFormat     result;
        if (VertexFormatComputedHash.Get(key, &result))
        {
            *single    = result.SingleFormat;
            *batch     = result.BatchFormat;
            *instanced = result.InstancedFormat;
            return;
        }

        unsigned                vflags = 0;
        const VertexShaderDesc* vdesc  =
            VertexShaderDesc::GetDesc((typename VertexShaderDesc::ShaderType)StaticShaderForFill(fill, vflags, 0));

        VertexElement outf[8];
        unsigned      maxalign     = 4;
        int           batchOffset  = -1;
        int           batchElement = -1;
        unsigned      size         = 0;
        int           j            = 0;
        for (int i = 0; i < vdesc->NumAttribs; i++)
        {
            unsigned attr = vdesc->Attributes[i].Attr;
            if ((attr & 0xff0f) == (VET_Color | VET_Index1 | 4))
            {
                // the factors: a weight and an alpha byte, with the batch index between them
                bool swap            = (flags & MVF_EndianSwapFactors) != 0;
                outf[j].Offset       = size;
                outf[j].Attribute    = swap ? VET_FactorAlpha8 : VET_T0Weight8;
                outf[j + 1].Offset   = size + 3;
                outf[j + 1].Attribute = swap ? VET_T0Weight8 : VET_FactorAlpha8;
                batchOffset          = size + (swap ? 1 : 2);
                batchElement         = ++j;
                size += 4;
                j++;
                continue;
            }

            const VertexElement* src = sourceFormat->pElements;
            for (; src->Attribute; src++)
                if ((src->Attribute & VET_Usage_Mask) == (attr & VET_Usage_Mask) &&
                    (src->Attribute & VET_Index_Mask) == (attr & VET_Index_Mask))
                    break;
            if (!src->Attribute)
            {
                *instanced = 0;
                *single    = 0;
                *batch     = 0;
                return;
            }

            outf[j]        = *src;
            outf[j].Offset = size;
            unsigned type  = src->Attribute & VET_Type_Mask & 0xfff;
            if (flags & MVF_ReverseColor)
            {
                if (type == VET_ColorRGBA8)
                    outf[j].Attribute = (src->Attribute & ~0xfffu) | VET_ColorARGB8;
            }
            else if (type == VET_ColorARGB8)
                outf[j].Attribute = (src->Attribute & ~0xfffu) | VET_ColorRGBA8;
            if (src->CompSize() > maxalign)
                maxalign = src->CompSize();
            size += outf[j].Size();
            if (flags & MVF_AlignVertexAttrs)
                size = (size + 3) & ~3u;
            j++;
        }

        unsigned align = (flags & MVF_Align) ? maxalign : 1;
        outf[j].Offset    = 0;
        outf[j].Attribute = 0;
        *single = GetVertexFormat(outf, j + 1, size, align);

        if (flags & MVF_HasInstancing)
        {
            outf[j].Offset        = 0;
            outf[j].Attribute     = VET_Instance | VET_I8 | 1 | VET_Argument_Flag;
            outf[j + 1].Offset    = 0;
            outf[j + 1].Attribute = 0;
            *instanced = GetVertexFormat(outf, j + 2, size, align);
        }
        else
            *instanced = 0;

        if (batchOffset >= 0)
        {
            for (int i = j - 1; i >= batchElement; i--)
                outf[i + 1] = outf[i];
            outf[batchElement].Offset    = batchOffset;
            outf[batchElement].Attribute = VET_Instance8;
        }
        else
        {
            outf[j].Offset    = (flags & MVF_EndianSwapFactors) ? size + 3 : size;
            outf[j].Attribute = VET_Instance8;
            size += outf[j].Size();
        }
        outf[j + 1].Offset    = 0;
        outf[j + 1].Attribute = 0;
        *batch = GetVertexFormat(outf, j + 2, size, align);

        result.SingleFormat    = *single;
        result.BatchFormat     = *batch;
        result.InstancedFormat = *instanced;
        VertexFormatComputedHash.Set(key, result);
    }

    // the fragment shaders of a filter's passes, the last one last; the pass count
    unsigned GetFilterPasses(const Filter* filter, unsigned fillFlags, unsigned* passes) const   // 0x142731f10
    {
        if (filter->GetFilterType() > Filter_Blur_End)
        {
            passes[0] = 0xa207;
            if (fillFlags & 1)
                passes[0]++;
            return 1;
        }

        const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();
        bool     box2      = params.BlurY * params.BlurX < 12800.0f;   // small blurs take one 2D pass
        unsigned passCount = box2 ? params.Passes : params.Passes * 2;
        unsigned last      = passCount - 1;
        for (unsigned i = 0; i < last; i++)
            passes[i] = box2 ? 0xa449 : 0xa249;

        switch (params.Mode & BlurFilterParams::Mode_FilterMask)
        {
        case Filter_Shadow:
        case Filter_Glow:
        case Filter_Bevel:
            if (params.Mode & BlurFilterParams::Mode_Inner)
                passes[last] = 0xae4b;
            else if ((params.Mode & (BlurFilterParams::Mode_Knockout | BlurFilterParams::Mode_HideObject)) ==
                     BlurFilterParams::Mode_HideObject)
                passes[last] = 0xb64b;
            else
                passes[last] = 0xa64b;
            if (fillFlags & 1)
                passes[last]++;
            if (params.Mode & BlurFilterParams::Mode_Knockout)
                passes[last] += 0x100;
            if (params.Mode & BlurFilterParams::Mode_Highlight)
                passes[last] += 0x400;
            break;
        default:
            passes[last] = box2 ? 0xa449 : 0xa249;
            if (fillFlags & 1)
                passes[last]++;
            break;
        }
        return passCount;
    }

    MultiKeyCollection<VertexElement, VertexFormat, 32, 8> VFormats;                   // +0x00
    HAL::ProfileViews*                                     Profiler;                   // +0x20
    HashLH<SourceFormatHash, ResultFormat>                 VertexFormatComputedHash;   // +0x28
};

}} // namespace Scaleform::Render

#endif
