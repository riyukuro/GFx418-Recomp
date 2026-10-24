// Recovered Scaleform 4.1.18 Render: vertex format conversion (Render_Vertex). Vertices are converted element by
// element: each destination element either has a converter registered for its usage (position, colour, instance
// argument) or is copied from the source element with the same usage. Index buffers are copied with a bias added,
// through SSE2 streaming stores where the buffers allow it.
// MS2-UNIT: sfr_render_06j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426b8f00-0x1426b90b0 .text$mn
// MS2-RANGE: 0x1426b90b0-0x1426b9130 .text$mn
// MS2-RANGE: 0x1426b9130-0x1426b9cb0 .text$mn
// MS2-TPLPIN-BEGIN
// MS2-TPLPIN-END

#include "ms2/scaleform/include/render/render_vertex.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include <string.h>

namespace Scaleform { namespace SIMD {

// SSE2 integer support query. On x64 SSE2 is always there, but the answer is still cached in a guarded
// function-local static.
struct IS
{
    static bool HasSSE2Support() { return true; }
    static bool SupportsIntegerIntrinsics()
    {
        static bool HasSSE2 = HasSSE2Support();
        return HasSSE2;
    }
};

}} // namespace Scaleform::SIMD

namespace Scaleform { namespace Render {

// The abstract buffer-side format: the destructor only restores the vptr and chains to ~RefCountImplCore.
// @0x1426b90b0
SystemVertexFormat::~SystemVertexFormat() {}

// bytes per component, indexed by component type - 1 (U8N, U8, S16, U16, U32, F32)
static unsigned VertexTypeSizes[] = { 1, 1, 2, 2, 4, 4 };

static inline unsigned ElementSize(const VertexElement* e)
{
    return (e->Attribute & VET_Components_Mask) *
           VertexTypeSizes[((e->Attribute & VET_CompType_Mask) >> VET_CompType_Shift) - 1];
}

// 16-bit integer position to 32-bit float position
// @0x1426b8f00
void ConvertVertexData_XY16i_XY32f(const VertexElement*, const VertexElement*,
                                   UByte* src, unsigned srcSize, unsigned srcOffset,
                                   UByte* dest, unsigned destSize, unsigned destOffset,
                                   unsigned count, const void*)
{
    UByte* srcEnd = src + srcSize * count;
    while (src < srcEnd)
    {
        SInt16* s = (SInt16*)(src + srcOffset);
        float*  d = (float*)(dest + destOffset);
        d[0] = (float)s[0];
        d[1] = (float)s[1];
        dest += destSize;
        src  += srcSize;
    }
}

// 16-bit XY to 16-bit XYZ with z = 0
// @0x1426b8f80
void ConvertVertexData_XY16i_XYZ16i(const VertexElement*, const VertexElement*,
                                    UByte* src, unsigned srcSize, unsigned srcOffset,
                                    UByte* dest, unsigned destSize, unsigned destOffset,
                                    unsigned count, const void*)
{
    UByte* srcEnd = src + srcSize * count;
    while (src < srcEnd)
    {
        SInt16* s = (SInt16*)(src + srcOffset);
        SInt16* d = (SInt16*)(dest + destOffset);
        d[0] = s[0];
        d[1] = s[1];
        d[2] = 0;
        dest += destSize;
        src  += srcSize;
    }
}

// swaps the red and blue bytes (the same swap serves both directions)
// @0x1426b8ff0
void ConvertVertexData_ARGB_RGBA(const VertexElement*, const VertexElement*,
                                 UByte* src, unsigned srcSize, unsigned srcOffset,
                                 UByte* dest, unsigned destSize, unsigned destOffset,
                                 unsigned count, const void*)
{
    UByte* srcEnd = src + srcSize * count;
    while (src < srcEnd)
    {
        UInt32* s = (UInt32*)(src + srcOffset);
        UInt32* d = (UInt32*)(dest + destOffset);
        *d = (*s & 0xff00ff00) | ((*s >> 16) & 0xff) | ((*s & 0xff) << 16);
        dest += destSize;
        src  += srcSize;
    }
}

// fills a byte element of every vertex with the argument byte; there is no source
// @0x1426b9070
void InitVertexData_U8(const VertexElement*, const VertexElement*,
                       UByte*, unsigned, unsigned,
                       UByte* dest, unsigned destSize, unsigned destOffset,
                       unsigned count, const void* arg)
{
    UByte* destEnd = dest + destSize * count;
    UByte  value   = *(const UByte*)arg;
    while (dest < destEnd)
    {
        dest[destOffset] = value;
        dest += destSize;
    }
}

typedef void (*ConvertVertexDataFunc)(const VertexElement* srcElement, const VertexElement* destElement,
                                      UByte* src, unsigned srcSize, unsigned srcOffset,
                                      UByte* dest, unsigned destSize, unsigned destOffset,
                                      unsigned count, const void* arg);

// one converter: applies when the source attribute is SourceType (or the destination takes an argument) and the
// masked destination attribute is TargetType; a VET_None target ends the list
struct ConvertTarget
{
    VertexElementType     SourceType;
    VertexElementType     TargetType;
    unsigned              TargetMask;
    ConvertVertexDataFunc Func;
};

ConvertTarget Convert_None[] =
{
    { VET_None, VET_None, VET_Type_Mask, 0 }
};
ConvertTarget Convert_Pos[] =
{
    { VET_XY16i, VET_XYZ16i, VET_Type_Mask, ConvertVertexData_XY16i_XYZ16i },
    { VET_XY16i, VET_XY32f,  VET_Type_Mask, ConvertVertexData_XY16i_XY32f },
    { VET_None,  VET_None,   VET_Type_Mask, 0 }
};
ConvertTarget Convert_Color[] =
{
    { VET_ColorARGB8, VET_ColorRGBA8, VET_CompType_Mask | VET_Usage_Mask | VET_Components_Mask, ConvertVertexData_ARGB_RGBA },
    { VET_ColorRGBA8, VET_ColorARGB8, VET_CompType_Mask | VET_Usage_Mask | VET_Components_Mask, ConvertVertexData_ARGB_RGBA },
    { VET_None,       VET_None,       VET_Type_Mask, 0 }
};
ConvertTarget Convert_Instance[] =
{
    { VET_Instance, VET_Instance8, VET_Type_Mask | VET_Argument_Flag, InitVertexData_U8 },
    { VET_None,     VET_None,      VET_Type_Mask, 0 }
};

// converter lists by usage (none, position, colour, texcoord, instance, unused)
static ConvertTarget* VertexConvertTable[] =
{
    Convert_None, Convert_Pos, Convert_Color, Convert_None, Convert_Instance, Convert_None
};

// strided copy of one element per vertex; the common element sizes get their own loops
// @0x1426b9af0
void CopyVertexElements(UByte* src, UPInt srcStride, UByte* dest, UPInt destStride, UPInt elementSize, UPInt count)
{
    UByte* srcEnd = src + srcStride * count;
    switch (elementSize)
    {
    case 1:
        for (; src < srcEnd; dest += destStride, src += srcStride)
            *dest = *src;
        break;
    case 2:
        for (; src < srcEnd; dest += destStride, src += srcStride)
            *(UInt16*)dest = *(UInt16*)src;
        break;
    case 4:
        for (; src < srcEnd; dest += destStride, src += srcStride)
            *(UInt32*)dest = *(UInt32*)src;
        break;
    default:
        for (; src < srcEnd; dest += destStride, src += srcStride)
            memcpy(dest, src, elementSize);
        break;
    }
}

// @0x1426b94b0
void ConvertVertices(const VertexFormat& srcFormat, void* src, const VertexFormat& destFormat, void* dest,
                     unsigned count, void** args)
{
    for (const VertexElement* de = destFormat.pElements; de->Attribute != VET_None; de++)
    {
        unsigned usage = de->Attribute & (VET_Usage_Mask | VET_Index_Mask);
        unsigned type  = de->Attribute & VET_CompType_Mask;

        // batch index channels are not vertex data
        if (type == VET_I8 || type == VET_I16)
            continue;

        ConvertTarget* conv = VertexConvertTable[(de->Attribute & VET_Usage_Mask) >> VET_Usage_Shift];

        // the source element with the same usage (or the terminator)
        const VertexElement* se = srcFormat.pElements;
        for (; se->Attribute != VET_None; se++)
            if ((se->Attribute & (VET_Usage_Mask | VET_Index_Mask)) == usage)
                break;

        bool converted = false;
        for (; conv->TargetType != VET_None; conv++)
        {
            VertexElementType srcAttr = (VertexElementType)se->Attribute;
            if (((de->Attribute & VET_Argument_Flag) || srcAttr == conv->SourceType) &&
                (de->Attribute & conv->TargetMask) == (unsigned)conv->TargetType)
            {
                conv->Func(se, de, (UByte*)src, srcFormat.Size, se->Offset,
                           (UByte*)dest, destFormat.Size, de->Offset, count, args ? *args : 0);
                converted = true;
                break;
            }
        }
        if (converted)
            continue;

        // same layout on both sides: plain copy
        CopyVertexElements((UByte*)src + se->Offset, srcFormat.Size, (UByte*)dest + de->Offset, destFormat.Size,
                           ElementSize(se), count);
    }
}

// @0x1426b9730
void ConvertVertices_Buffered(const VertexFormat& srcFormat, void* src, const VertexFormat& destFormat, void* dest,
                              unsigned count, void** args)
{
    // converted into an 8 KB stack buffer first, then copied out in one block (the destination is usually a
    // locked hardware buffer)
    union
    {
        UByte Buffer[8 * 1024];
        UPInt Align;
    };

    unsigned destSize = destFormat.Size;
    unsigned batch    = sizeof(Buffer) / destSize;
    UByte*   s        = (UByte*)src;
    UByte*   d        = (UByte*)dest;
    while (count)
    {
        if (batch > count)
            batch = count;
        ConvertVertices(srcFormat, s, destFormat, Buffer, batch, args);
        memcpy(d, Buffer, batch * destSize);
        s     += batch * srcFormat.Size;
        d     += batch * destSize;
        count -= batch;
    }
}

// converts as many vertices as fit into destBufferSize bytes, advances *src and *count past them, returns the bytes
// written
// @0x1426b9a70
UPInt ConvertVertices_Buffered(const VertexFormat& srcFormat, UByte** src, const VertexFormat& destFormat, UByte* dest,
                               UPInt destBufferSize, unsigned* count, void** args)
{
    unsigned destSize = destFormat.Size;
    unsigned n        = (unsigned)(destBufferSize / destSize);
    if (n > *count)
        n = *count;
    ConvertVertices(srcFormat, *src, destFormat, dest, n, args);
    *src   += n * srcFormat.Size;
    *count -= n;
    return n * destSize;
}

// fills the argument channels (elements flagged VET_Argument_Flag) of count vertices
// @0x1426b9bd0
void InitializeVertices(const VertexFormat& format, void* vertices, unsigned count, void** args)
{
    for (const VertexElement* e = format.pElements; e->Attribute != VET_None; e++)
    {
        if (!(e->Attribute & VET_Argument_Flag))
            continue;
        for (ConvertTarget* conv = VertexConvertTable[(e->Attribute & VET_Usage_Mask) >> VET_Usage_Shift];
             conv->SourceType != VET_None; conv++)
        {
            if ((e->Attribute & conv->TargetMask) == (unsigned)conv->TargetType)
            {
                conv->Func(0, e, 0, 0, 0, (UByte*)vertices, format.Size, e->Offset, count, *args);
                break;
            }
        }
    }
}

void ConvertIndices_NonOpt(UInt16* dest, UInt16* src, unsigned count, UInt16 delta);

// SSE2 path: the aligned middle goes through non-temporal 16-byte stores; head and tail one index at a time.
// Needs both buffers equally misaligned.
// @0x1426b92a0
void ConvertIndices_SIMD(UInt16* dest, UInt16* src, unsigned count, UInt16 delta)
{
    if (((size_t)dest & 15) != ((size_t)src & 15))
    {
        ConvertIndices_NonOpt(dest, src, count, delta);
        return;
    }

    UInt16* srcEnd     = src + count;
    UPInt   alignBegin = ((UPInt)dest + 15) & ~(UPInt)15;
    UPInt   alignEnd   = ((UPInt)(dest + count)) & ~(UPInt)15;

    if (alignBegin < alignEnd)
    {
        while (dest < (UInt16*)alignBegin)
            *dest++ = *src++ + delta;

        SIMD::Vector4i vdelta = _mm_set1_epi16((short)delta);
        do
        {
            SIMD::Vector4i v = _mm_loadu_si128((const SIMD::Vector4i*)src);
            _mm_stream_si128((SIMD::Vector4i*)dest, _mm_add_epi16(v, vdelta));
            src  += 8;
            dest += 8;
        } while (dest < (UInt16*)alignEnd);
    }

    while (src < srcEnd)
        *dest++ = *src++ + delta;
}

// plain path, unrolled by four after the leftover count & 3
// @0x1426b91e0
void ConvertIndices_NonOpt(UInt16* dest, UInt16* src, unsigned count, UInt16 delta)
{
    switch (count & 3)
    {
    case 3: *dest++ = *src++ + delta;
    case 2: *dest++ = *src++ + delta;
    case 1: *dest++ = *src++ + delta;
    }
    count &= ~3u;
    for (UInt16* srcEnd = src + count; src < srcEnd; src += 4, dest += 4)
    {
        dest[0] = src[0] + delta;
        dest[1] = src[1] + delta;
        dest[2] = src[2] + delta;
        dest[3] = src[3] + delta;
    }
}

// @0x1426b9130
void ConvertIndices(UInt16* dest, UInt16* src, unsigned count, UInt16 delta)
{
    if (SIMD::IS::SupportsIntegerIntrinsics())
        ConvertIndices_SIMD(dest, src, count, delta);
    else
        ConvertIndices_NonOpt(dest, src, count, delta);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7SystemVertexFormat@Render@Scaleform@@6B@ 0x1431925f8
