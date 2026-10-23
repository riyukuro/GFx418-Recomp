// Recovered Scaleform 4.1.18 Render: vertex layouts (Render_Vertex). A VertexFormat is a byte size plus a list of
// (offset, attribute) elements closed by a VET_None attribute; the attribute packs component count, component type,
// usage and usage index. Only what the recovered units use so far.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_VERTEX_H
#define MS2_SF_RENDER_VERTEX_H

#include "ms2/scaleform/kernel/sf_refcount.h"

namespace Scaleform { namespace Render {

enum VertexElementType
{
    VET_Argument_Flag   = 0x10000,   // every vertex gets the same value, taken from the argument list
    VET_Type_Mask       = 0xffff,
    VET_Components_Mask = 0xf,
    VET_CompType_Mask   = 0xf0,
    VET_CompType_Shift  = 4,
    VET_Usage_Mask      = 0xf00,
    VET_Usage_Shift     = 8,
    VET_Index_Mask      = 0xf000,
    VET_Index_Shift     = 12,

    // component types
    VET_U8N             = 0x10,
    VET_U8              = 0x20,
    VET_S16             = 0x30,
    VET_U16             = 0x40,
    VET_U32             = 0x50,
    VET_F32             = 0x60,
    VET_I8              = 0x70,      // I8 / I16 are batch indices, not part of the buffer layout
    VET_I16             = 0x80,

    // usages
    VET_None            = 0,
    VET_Pos             = 0x100,
    VET_Color           = 0x200,
    VET_TexCoord        = 0x300,
    VET_Instance        = 0x400,

    VET_Index1          = 0x1000,
    VET_Index2          = 0x2000,

    VET_XY16i           = VET_Pos      | VET_S16 | 2,
    VET_XYZ16i          = VET_Pos      | VET_S16 | 3,
    VET_XY32f           = VET_Pos      | VET_F32 | 2,
    VET_XYZ32f          = VET_Pos      | VET_F32 | 3,
    VET_UV32f           = VET_TexCoord | VET_F32 | 2,
    VET_ColorRGBA8      = VET_Color    | VET_U8N | 4,
    VET_ColorARGB8      = VET_Color    | VET_U32 | 1,
    VET_FactorAlpha8    = VET_Color    | VET_U8N | 1 | VET_Index1,
    VET_T0Weight8       = VET_Color    | VET_U8N | 1 | VET_Index2,
    VET_IndexedFactors  = VET_Color    | VET_I8  | 2 | VET_Index1,
    VET_Instance8       = VET_Instance | VET_U8  | 1 | VET_Argument_Flag
};

struct VertexElement
{
    unsigned Offset;
    unsigned Attribute;

    bool operator==(const VertexElement& o) const { return Offset == o.Offset && Attribute == o.Attribute; }
    bool operator!=(const VertexElement& o) const { return !operator==(o); }
};

// The renderer's buffer-side description of a format (built lazily by the HAL).
class SystemVertexFormat : public RefCountBase<SystemVertexFormat, Stat_Default_Mem>
{
public:
    virtual ~SystemVertexFormat();
};

struct VertexFormat
{
    unsigned                Size;         // +0x00 bytes per vertex
    VertexElement*          pElements;    // +0x08
    Ptr<SystemVertexFormat> pSysFormat;   // +0x10

    // Same buffer layout: the index elements (I8 / I16) are skipped on both sides.
    bool operator==(const VertexFormat& o) const
    {
        const VertexElement* a = pElements;
        const VertexElement* b = o.pElements;
        for (;; a++, b++)
        {
            if ((a->Attribute & VET_CompType_Mask) == VET_I8 || (a->Attribute & VET_CompType_Mask) == VET_I16)
                a++;
            if ((b->Attribute & VET_CompType_Mask) == VET_I8 || (b->Attribute & VET_CompType_Mask) == VET_I16)
                b++;
            if (a->Attribute == VET_None || b->Attribute == VET_None)
                break;
            if (*a != *b)
                return false;
        }
        return *a == *b;
    }

    // The first element whose masked attribute equals value; 0 when there is none.
    const VertexElement* GetElement(unsigned value, unsigned mask) const
    {
        const VertexElement* e = pElements;
        for (; e->Attribute != VET_None; e++)
            if ((e->Attribute & mask) == value)
                return e;
        return 0;
    }
    bool HasUsage(VertexElementType usage) const { return GetElement(usage, VET_Usage_Mask) != 0; }
};

// positions only, 16-bit integer
struct VertexXY16i
{
    SInt16 x, y;
    static VertexFormat Format;   // 0x143a2fb70
};

// (appended for the D3D9 HAL, sfr_d3d9_01f) positions plus a per-vertex alpha factor
struct VertexXY16iAlpha
{
    SInt16 x, y;
    UByte  Alpha[4];
    static VertexFormat Format;   // 0x143a2fbd0
};

// (appended for the mesh cache, sfr_render_07g) converts count vertices between formats through a stack buffer
// (0x1426b9730)
void ConvertVertices_Buffered(const VertexFormat& srcFormat, void* src, const VertexFormat& destFormat, void* dest,
                              unsigned count, void** convertArgs = 0);

}} // namespace Scaleform::Render

#endif
