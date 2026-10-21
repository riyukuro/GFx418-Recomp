// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text filter TU
// (Text_FilterDesc): TextFilter's default drop shadow and its import of a display filter's blur / shadow / glow.
// MS2-UNIT: sfr_render_04k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264e2b0-0x14264e460 .text$mn

#include "ms2/scaleform/include/render/text_filterdesc.h"
#include "ms2/scaleform/include/render/render_textlayout.h"
#include <math.h>

namespace Scaleform { namespace Render { namespace Text {

// ***** TextFilter (Text_FilterDesc)

// @0x14264e2b0
void TextFilter::LoadFilterDesc(const Filter* filter)
{
    FilterType type = filter->GetFilterType();

    if (type == Filter_Blur)
    {
        const BlurFilterParams& params = ((const BlurFilter*)filter)->GetParams();
        BlurX        = params.BlurX;
        BlurY        = params.BlurY;
        BlurStrength = params.Strength;
        return;
    }
    // a shadow or glow is only taken while the current one is not set
    if ((type == Filter_Shadow || type == Filter_Glow) && (ShadowParams.Colors[0] == 0 || ShadowDistance == 0))
    {
        const BlurFilterImpl*   blur   = (const BlurFilterImpl*)filter;
        const BlurFilterParams& params = blur->GetParams();

        ShadowFlags = 0;
        if (params.Mode & BlurFilterParams::Mode_Knockout)
            ShadowFlags |= GlyphParam::KnockOut;
        if (params.Mode & BlurFilterParams::Mode_HideObject)
            ShadowFlags |= GlyphParam::HideObject;
        if (params.Passes >= 1)
            ShadowFlags |= GlyphParam::FineBlur;

        ShadowParams.Mode      = 0;
        ShadowParams.BlurX     = params.BlurX;
        ShadowParams.BlurY     = params.BlurY;
        ShadowParams.Strength  = params.Strength;
        ShadowParams.Colors[0] = params.Colors[0];
        ShadowParams.Colors[1] = params.Colors[1];

        ShadowAlpha    = ShadowParams.Colors[0].GetAlpha();
        ShadowAngle    = blur->GetAngle();
        ShadowDistance = blur->GetDistance();
        UpdateShadowOffset();
    }
}

// @0x14264e3d0
void TextFilter::SetDefaultShadow()
{
    BlurX        = 0;
    BlurY        = 0;
    BlurStrength = 1.0f;

    ShadowParams.Mode      = 0;
    ShadowParams.BlurX     = 0;
    ShadowParams.BlurY     = 0;
    ShadowParams.Strength  = 1.0f;
    ShadowParams.Colors[0] = 0;

    // a fine-blurred shadow 4 twips down-right at full alpha
    ShadowFlags    = GlyphParam::FineBlur;
    ShadowAlpha    = 255;
    ShadowAngle    = 3.1415926535897932f / 4.0f;
    ShadowDistance = 4.0f;
    UpdateShadowOffset();
}

} // namespace Text

}} // namespace Scaleform::Render
