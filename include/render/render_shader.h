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
