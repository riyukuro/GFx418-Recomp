// Recovered Scaleform 4.1.18 Render: the kinds of text layers (split out of render_textmeshprovider.h so the glyph
// cache outline in render_renderer2d.h can declare GetFill with it).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXTLAYERTYPE_H
#define MS2_SF_RENDER_TEXTLAYERTYPE_H

namespace Scaleform { namespace Render {

// The kinds of text layers, in drawing order.
enum TextLayerType
{
    TextLayer_Background,
    TextLayer_Selection,
    TextLayer_Shadow,
    TextLayer_ShadowText,
    TextLayer_RasterText,
    TextLayer_PackedText,
    TextLayer_PackedDFAText,
    TextLayer_Images,
    TextLayer_Shapes,
    TextLayer_Underline,
    TextLayer_Cursor,
    TextLayer_Mask,
    TextLayer_Shapes_Masked,
    TextLayer_Underline_Masked
};

}} // namespace Scaleform::Render

#endif
