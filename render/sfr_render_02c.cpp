// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the filter TU
// (Render_Filters): Clone and IsContributing of the blur-family and color matrix filters, and the FilterSet list.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters).
// MS2-UNIT: sfr_render_02c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e7930-0x1425e8420 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_filters.h"

namespace Scaleform { namespace Render {

// @0x1425e7d20
Filter* BlurFilter::Clone(MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    return SF_HEAP_NEW(heap) BlurFilter(Params);
}

// @0x1425e82a0
bool BlurFilter::IsContributing() const
{
    return Params.BlurX > 20 || Params.BlurY > 20;
}

// @0x1425e8110
Filter* ShadowFilter::Clone(MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    return SF_HEAP_NEW(heap) ShadowFilter(Params, Angle, TwipsToPixels(Distance));
}

// @0x1425e8370
bool ShadowFilter::IsContributing() const
{
    return Params.Colors[0].GetAlpha() > 0;
}

// @0x1425e8050
Filter* GlowFilter::Clone(MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    return SF_HEAP_NEW(heap) GlowFilter(Params);
}

// @0x1425e8360
bool GlowFilter::IsContributing() const
{
    return Params.Colors[0].GetAlpha() > 0;
}

// @0x1425e7be0
Filter* BevelFilter::Clone(MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    return SF_HEAP_NEW(heap) BevelFilter(Params, Angle, TwipsToPixels(Distance));
}

// @0x1425e8280
bool BevelFilter::IsContributing() const
{
    return Params.Colors[0].GetAlpha() > 0 || Params.Colors[1].GetAlpha() > 0;
}

// Row-major 4x5: RGBA multipliers, then the offsets.
static float ColorMatrix_Identity[ColorMatrixFilter::ColorMatrixEntries] =
{
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.0f, 0.0f
};

// @0x1425e7930
ColorMatrixFilter::ColorMatrixFilter() : Filter(Filter_ColorMatrix)
{
    memcpy(MatrixData, ColorMatrix_Identity, sizeof(MatrixData));
}

// @0x1425e82d0
bool ColorMatrixFilter::IsContributing() const
{
    return memcmp(MatrixData, ColorMatrix_Identity, sizeof(ColorMatrix_Identity)) != 0;
}

// @0x1425e7de0
Filter* ColorMatrixFilter::Clone(MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    ColorMatrixFilter* f = SF_HEAP_NEW(heap) ColorMatrixFilter();
    if (f)
        memcpy(f->MatrixData, MatrixData, sizeof(MatrixData));
    return f;
}

// ---------------------------------------------------------------------------------------------------------------
// FilterSet

// @0x1425e79a0
FilterSet::FilterSet(Filter* filter) : Frozen(false)
{
    if (filter)
        AddFilter(filter);
}

// Drops every occurrence of filter.
// @0x1425e8380
void FilterSet::RemoveFilter(Filter* filter)
{
    for (UPInt i = 0; i < Filters.GetSize(); i++)
    {
        if (Filters[i] == filter)
        {
            Filters.RemoveAt(i);
            i--;
        }
    }
}

// @0x1425e7eb0
FilterSet* FilterSet::Clone(bool deepCopy, MemoryHeap* heap) const
{
    if (!heap)
        heap = Memory::GetHeapByAddress(this);
    FilterSet* set = SF_HEAP_NEW(heap) FilterSet;
    if (!set)
        return 0;

    for (UPInt i = 0; i < Filters.GetSize(); i++)
    {
        if (deepCopy)
        {
            Ptr<Filter> copy = *Filters[i]->Clone(heap);
            set->AddFilter(copy);
        }
        else
        {
            set->AddFilter(Filters[i]);
        }
    }
    return set;
}

// @0x1425e8300
bool FilterSet::IsContributing() const
{
    for (unsigned f = 0; f < Filters.GetSize(); ++f)
    {
        const Filter* filter = Filters[f];
        if (filter && filter->IsContributing())
            return true;
    }
    return false;
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1425e7aa0
// MS2-PIN: ??_G?$RefCountBase@VFilter@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1425e7aa0
// MS2-PIN: ??_G?$RefCountBase@VFilterSet@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1425e7aa0
// MS2-PIN: ??_7?$RefCountBase@VFilter@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7?$RefCountBase@VFilterSet@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7Filter@Render@Scaleform@@6B@ 0x14315ac78
// MS2-PIN: ??_7BlurFilterImpl@Render@Scaleform@@6B@ 0x14315ac90
// MS2-PIN: ??_7BlurFilter@Render@Scaleform@@6B@ 0x14315aca8
// MS2-PIN: ??_7ShadowFilter@Render@Scaleform@@6B@ 0x14315acc0
// MS2-PIN: ??_7GlowFilter@Render@Scaleform@@6B@ 0x14315acd8
// MS2-PIN: ??_7BevelFilter@Render@Scaleform@@6B@ 0x14315acf0
// MS2-PIN: ??_7ColorMatrixFilter@Render@Scaleform@@6B@ 0x14318ccc0
// MS2-PIN: ??_7FilterSet@Render@Scaleform@@6B@ 0x14318cce0
