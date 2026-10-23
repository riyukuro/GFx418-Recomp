// Recovered Scaleform 4.1.18 Render: ToleranceParams, the screen-space tolerances the tessellator, stroker and
// curve flattening work with (0x40 bytes of floats).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TOLERANCEPARAMS_H
#define MS2_SF_RENDER_TOLERANCEPARAMS_H

namespace Scaleform { namespace Render {

struct ToleranceParams
{
    float Epsilon;                  // +0x00
    float CurveTolerance;           // +0x04 curve flattening (1.0 ~ half a pixel either way)
    float CollinearityTolerance;    // +0x08 when a curve counts as a straight segment
    float IntersectionEpsilon;      // +0x0c
    float FillLowerScale;           // +0x10 the scale ranges a cached mesh stays valid in
    float FillUpperScale;
    float FillAliasedLowerScale;
    float FillAliasedUpperScale;
    float StrokeLowerScale;
    float StrokeUpperScale;
    float HintedStrokeLowerScale;
    float HintedStrokeUpperScale;
    float Scale9LowerScale;
    float Scale9UpperScale;
    float EdgeAAScale;              // +0x38
    float MorphTolerance;           // +0x3c

    // (appended for sfr_render_04p) the renderer's defaults, as the Renderer2DImpl ctor stores them
    ToleranceParams()
        : Epsilon(1e-5f), CurveTolerance(1.0f), CollinearityTolerance(1.0f), IntersectionEpsilon(1e-3f),
          FillLowerScale(0.7071f), FillUpperScale(1.4142f), FillAliasedLowerScale(0.5f), FillAliasedUpperScale(2.0f),
          StrokeLowerScale(0.99f), StrokeUpperScale(1.01f), HintedStrokeLowerScale(0.999f),
          HintedStrokeUpperScale(1.001f), Scale9LowerScale(0.995f), Scale9UpperScale(1.005f), EdgeAAScale(0.95f),
          MorphTolerance(1e-4f)
    {
    }
};

}} // namespace Scaleform::Render

#endif
