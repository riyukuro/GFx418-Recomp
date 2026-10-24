// Recovered Scaleform 4.1.18 Render: the platform-neutral shader plumbing the HALs share (Render_Shader). Written from
// the exe; names from the SDK headers.
//   ShaderInterfaceBase<U, Shader> the uniform shadow store a HAL fills before a draw: U::SU_TotalSize floats, a
//                                  set flag per uniform, and the textures bound for the draw.
//   BuildVertexArray<Builder>      walks a VertexFormat and hands each attribute to a platform builder; packed factor
//                                  pairs (and factors split by a batch index) become one four-component attribute.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_SHADER_H
#define MS2_SF_RENDER_SHADER_H

#include <string.h>
#include "ms2/scaleform/include/render/render_vertex.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"

namespace Scaleform { namespace Render {

class Texture;

template<class U, class Shader>
class ShaderInterfaceBase
{
public:
    ShaderInterfaceBase()
    {
        memset(Textures, 0, sizeof(Textures));
        memset(UniformSet, 0, sizeof(UniformSet));
    }

    // (appended for the D3D9 HAL, sfr_d3d9_01e) uniform upload. A uniform lives in the shadow store at the offset
    // each stage's desc gives it; batched uniforms are slots of a per-instance array uniform instead.
    void SetUniform0(const Shader& sd, unsigned var, const float* v, unsigned n, unsigned index = 0,
                     unsigned batch = 0)
    {
        SF_UNUSED(batch);
        if (sd->pVDesc->Uniforms[var].Size)
            memcpy(UniformData + sd->pVDesc->Uniforms[var].ShadowOffset +
                       sd->pVDesc->Uniforms[var].ElementSize * index,
                   v, n * sizeof(float));
        if (sd->pFDesc->Uniforms[var].Size)
            memcpy(UniformData + sd->pFDesc->Uniforms[var].ShadowOffset +
                       sd->pFDesc->Uniforms[var].ElementSize * index,
                   v, n * sizeof(float));
        UniformSet[var] = true;
    }

    void SetUniform(const Shader& sd, unsigned var, const float* v, unsigned n, unsigned index = 0,
                    unsigned batch = 0)
    {
        if (sd->pVDesc->BatchUniforms[var].Offset >= 0)
        {
            int array = sd->pVDesc->BatchUniforms[var].Array;
            SetUniform0(sd, array, v, n,
                        index + sd->pVDesc->BatchUniforms[var].Offset + batch * sd->pVDesc->Uniforms[array].BatchSize, 0);
        }
        else if (sd->pFDesc->BatchUniforms[var].Offset >= 0)
        {
            int array = sd->pFDesc->BatchUniforms[var].Array;
            SetUniform0(sd, array, v, n,
                        index + sd->pFDesc->BatchUniforms[var].Offset + batch * sd->pFDesc->Uniforms[array].BatchSize, 0);
        }
        else
            SetUniform0(sd, var, v, n, index, batch);
    }

    // a Color stores B, G, R, A; the shaders take R, G, B, A in 0..1
    void SetColor(const Shader& sd, unsigned var, Color c, unsigned index = 0, unsigned batch = 0)
    {
        const float mult = 1.0f / 255.0f;
        float rgba[4] = { c.GetRed() * mult, c.GetGreen() * mult, c.GetBlue() * mult, c.GetAlpha() * mult };
        SetUniform(sd, var, rgba, 4, index, batch);
    }

    void SetCxform(const Shader& sd, const Cxform& cx, unsigned index = 0, unsigned batch = 0)
    {
        SetUniform(sd, U::SU_cxmul, cx.M[0], 4, index, batch);
        SetUniform(sd, U::SU_cxadd, cx.M[1], 4, index, batch);
    }

    // the uniforms a user shader reads, packed in the matrix's user data in uniform order; with the TexScale flag
    // a small uniform's first two components are given in pixels of the first texture
    void SetUserUniforms(const Shader& sd, const MatrixPoolImpl::HMatrix& m, int batch = 0)
    {
        const float* pdata = (const float*)m.pHandle->GetUserDataPtr();
        for (int i = 0; i < U::SU_Count; i++)
        {
            UByte flags = U::UniformFlags[i];
            if (flags & U::Uniform_Builtin)
                continue;

            int size;
            if ((sd->pVDesc->BatchUniforms[i].Array) < U::SU_Count)   // (parenthesized: clang reads ".Array <" as a template)
                size = sd->pVDesc->BatchUniforms[i].Size * sd->pVDesc->Uniforms[sd->pVDesc->BatchUniforms[i].Array].ElementSize;
            else if (sd->pVDesc->Uniforms[i].Location >= 0)
                size = sd->pVDesc->Uniforms[i].Size;
            else if ((sd->pFDesc->BatchUniforms[i].Array) < U::SU_Count)
                size = sd->pFDesc->BatchUniforms[i].Size * sd->pFDesc->Uniforms[sd->pFDesc->BatchUniforms[i].Array].ElementSize;
            else if (sd->pFDesc->Uniforms[i].Location >= 0)
                size = sd->pFDesc->Uniforms[i].Size;
            else
                continue;
            if (!size)
                continue;

            if ((flags & U::Uniform_TexScale) && size <= 4 && Textures[0])
            {
                ImageSize sz = Textures[0]->ImgSize;
                float scaled[4];
                scaled[0] = (1.0f / sz.Width) * pdata[0];
                scaled[1] = (1.0f / sz.Height) * pdata[1];
                scaled[2] = pdata[2];
                scaled[3] = pdata[3];
                SetUniform(sd, i, scaled, size, 0, batch);
            }
            else
                SetUniform(sd, i, pdata, size, 0, batch);
            pdata += size;
        }
    }

protected:
    float    UniformData[U::SU_TotalSize];
    bool     UniformSet[U::SU_Count];
    Texture* Textures[4];
};

// Builder::Add(index, attribute, components, offset) per attribute, Builder::Finish(count) at the end.
template<class Builder>
void BuildVertexArray(const VertexFormat* format, Builder& out)
{
    // a factor in the color usage with index 3 is the second half of a packed pair
    const unsigned pairKey = VET_Color | (3 << VET_Index_Shift);
    const VertexElement* e = format->pElements;
    int n = 0;
    while (e->Attribute != VET_None)
    {
        unsigned at    = e->Offset;
        int      comps = e->Attribute & VET_Components_Mask;

        if (((e[0].Attribute | e[1].Attribute) & (VET_Usage_Mask | VET_Index_Mask)) == pairKey)
        {
            comps = 4;
            e += 1;
        }
        else if ((e[1].Attribute & VET_Usage_Mask) == VET_Instance &&
                 ((e[0].Attribute | e[2].Attribute) & (VET_Usage_Mask | VET_Index_Mask)) == pairKey)
        {
            comps = 4;
            e += 2;
        }
        out.Add(n, e->Attribute, comps, at);
        e++;
        n++;
    }
    out.Finish(n);
}

}} // namespace Scaleform::Render

#endif
