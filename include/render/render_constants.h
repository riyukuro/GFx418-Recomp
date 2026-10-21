// Recovered Scaleform 4.1.18 Render: tree node flags and change-tracking bits (Render_Constants). Only the values the
// recovered units use so far.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_CONSTANTS_H
#define MS2_SF_RENDER_CONSTANTS_H

namespace Scaleform { namespace Render {

// flags kept in TreeNode data (EntryData::Flags) and copied into the cache nodes
enum TreeNodeFlags
{
    NF_Visible               = 0x0001,
    NF_Culled                = 0x0002,     // cache nodes only
    NF_EdgeAA_Mask           = 0x000C,
    NF_HasMask               = 0x0010,
    NF_MaskNode              = 0x0020,
    NF_PartOfMask            = 0x0040,     // cache nodes only: NF_MaskNode << 1
    NF_PartOfScale9          = 0x0080,     // cache nodes only
    NF_ExpandedBounds        = 0x0100,     // cache nodes only
    NF_3D                    = 0x0200,
    NF_HasFilter             = 0x0400,
    NF_HasViewMatrix3D       = 0x0800,
    NF_HasProjectionMatrix3D = 0x1000
};

// change bits of Context::EntryChange (the context's own bit is the top one)
enum TreeChangeConstants
{
    Change_Context_NewNode = 0x80000000,
    Change_Context_Mask    = Change_Context_NewNode
};

// blend modes of a tree node / DrawableImage::Draw (the SWF modes first)
enum BlendMode
{
    Blend_None,
    Blend_Normal,
    Blend_Layer,
    Blend_Multiply,
    Blend_Screen,
    Blend_Lighten,
    Blend_Darken,
    Blend_Difference,
    Blend_Add,
    Blend_Subtract,
    Blend_Invert,
    Blend_Alpha,
    Blend_Erase,
    Blend_Overlay,
    Blend_HardLight,
    Blend_Overwrite,
    Blend_OverwriteAll,
    Blend_FullAdditive,
    Blend_FilterBlend,
    Blend_Ignore,
    Blend_Count
};

}} // namespace Scaleform::Render

#endif
