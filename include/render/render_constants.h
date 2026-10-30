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
    Blend_Count
};

// (appended for the tree nodes, sfr_render_03c) the per-node change bits handed to Entry::getWritableData
enum TreeNodeChangeConstants
{
    Change_Matrix               = 0x00000001,
    Change_CxForm               = 0x00000002,
    Change_Visible              = 0x00000004,
    Change_AproxBounds          = 0x00000008,
    Change_MorphRatio           = 0x00000010,
    Change_EdgeAAMode           = 0x00000020,
    Change_IsMask               = 0x00000080,
    Change_ChildInsert          = 0x00000100,
    Change_ChildRemove          = 0x00000200,
    Change_Shape                = 0x00000400,
    Change_Viewport             = 0x00001000,
    Change_3D                   = 0x00002000,

    Change_State_Scale9             = 0x00010000,
    Change_State_BlendMode          = 0x00020000,
    Change_State_MaskNode           = 0x00040000,
    Change_State_ViewMatrix3D       = 0x00080000,
    Change_State_ProjectionMatrix3D = 0x00100000,
    Change_State_Filter             = 0x00200000,
    Change_State_Mask               = 0x00FF0000
};

// the NF_EdgeAA_Mask values
enum EdgeAAMode
{
    EdgeAA_Inherit = 0x0000,
    EdgeAA_On      = 0x0004,
    EdgeAA_Off     = 0x0008,
    EdgeAA_Disable = 0x000C
};

}} // namespace Scaleform::Render

#endif
