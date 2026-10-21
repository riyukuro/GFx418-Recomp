// Recovered Scaleform 4.1.18 Render Text: TextFilter, the blur / drop shadow settings of a text field (0x50 bytes,
// vftable 0x1431899f8). SetDefaultShadow (0x14264e3d0) belongs to Text_FilterDesc (unit sfr_render_04).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_FILTERDESC_H
#define MS2_SF_RENDER_TEXT_FILTERDESC_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_filters.h"

namespace Scaleform { namespace Render { namespace Text {

struct TextFilter : public RefCountBaseNTS<TextFilter, StatRender_Text_Mem>
{
    float            BlurX, BlurY;      // +0x10
    float            BlurStrength;      // +0x18
    BlurFilterParams ShadowParams;      // +0x1c
    unsigned         ShadowFlags;       // +0x40 GlyphParam flags; bit 0: shadow off
    float            ShadowAngle;       // +0x44
    float            ShadowDistance;    // +0x48
    UInt8            ShadowAlpha;       // +0x4c

    TextFilter() { SetDefaultShadow(); }

    void SetDefaultShadow();
    void UpdateShadowOffset()
    {
        ShadowParams.Offset = BlurFilterParams::CalcOffsetByAngleDistance(ShadowAngle, ShadowDistance);
    }

    // (appended for the static text, sfr_gfx_05d) takes the blur / drop shadow of a display filter (0x14264e2b0)
    void LoadFilterDesc(const Filter* filter);

    // (appended for sfr_render_04l) every setting
    bool operator==(const TextFilter& f) const
    {
        return BlurX == f.BlurX && BlurY == f.BlurY && BlurStrength == f.BlurStrength &&
               ShadowParams.EqualsAll(f.ShadowParams) && ShadowFlags == f.ShadowFlags &&
               ShadowAlpha == f.ShadowAlpha && ShadowAngle == f.ShadowAngle && ShadowDistance == f.ShadowDistance;
    }
};

}}} // namespace Scaleform::Render::Text

#endif
