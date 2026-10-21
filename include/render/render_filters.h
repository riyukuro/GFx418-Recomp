// Recovered Scaleform 4.1.18 Render: display-object filters (blur, drop shadow, glow, bevel, color matrix) and the
// filter list a display object carries.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// This build predates the cache-as-bitmap filter: Filter has three virtual slots (??_G, Clone, IsContributing),
// FilterSet is the array plus a frozen flag (0x30 bytes). BlurFilterImpl and its subclasses are 0x48 bytes.
// Bodies live in sfr_render_02c (Render_Filters); the blur-family ??_G and vftables were emitted with the AS3
// filter classes (0x14315ac78..).
#ifndef MS2_SF_RENDER_FILTERS_H
#define MS2_SF_RENDER_FILTERS_H

#include <math.h>
#include <string.h>
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_twips.h"

namespace Scaleform { namespace Render {

enum FilterType
{
    Filter_Blur            = 0,
    Filter_Shadow          = 1,
    Filter_Glow            = 2,     // a shadow without offset
    Filter_Bevel           = 3,
    Filter_GradientGlow    = 4,
    Filter_GradientBevel   = 5,
    Filter_Blur_End        = Filter_GradientBevel,
    Filter_ColorMatrix     = 8,
    Filter_Convolution     = 9,
    Filter_DisplacementMap = 10
};

struct BlurFilterParams
{
    enum ModeConstants
    {
        Mode_FilterMask = 0x07,
        Mode_Knockout   = 0x10,
        Mode_Inner      = 0x20,
        Mode_HideObject = 0x40,
        Mode_Highlight  = 0x80,
        Mode_FlagsMask  = 0xF0
    };

    unsigned Mode;          // +0x00 FilterType | ModeConstants flags
    unsigned Passes;        // +0x04
    float    BlurX, BlurY;  // +0x08 twips
    PointF   Offset;        // +0x10
    float    Strength;      // +0x18
    Color    Colors[2];     // +0x1c shadow, highlight

    BlurFilterParams() : Mode(0), Passes(1), BlurX(100), BlurY(100), Offset(0, 0), Strength(1)
    {
        Colors[0].SetRGBA(0, 0, 0, 0xFF);
        Colors[1].SetRGBA(0, 0, 0, 0);
    }
    BlurFilterParams(unsigned mode, float x, float y, unsigned passes = 1, float strength = 1)
        : Mode(mode), Passes(passes), BlurX(x), BlurY(y), Offset(0, 0), Strength(strength)
    {
        Colors[0].SetRGBA(0, 0, 0, 0xFF);
        Colors[1].SetRGBA(0, 0, 0, 0);
    }
    // member-wise, the offset one coordinate at a time (the exe never moves it as one 8-byte value)
    BlurFilterParams(const BlurFilterParams& o)
        : Mode(o.Mode), Passes(o.Passes), BlurX(o.BlurX), BlurY(o.BlurY), Offset(o.Offset.x, o.Offset.y),
          Strength(o.Strength)
    {
        Colors[0] = o.Colors[0];
        Colors[1] = o.Colors[1];
    }

    bool operator==(const BlurFilterParams& b) const
    {
        return Mode == b.Mode && BlurX == b.BlurX && BlurY == b.BlurY && Passes == b.Passes;
    }
    FilterType GetFilterType() const { return (FilterType)(Mode & Mode_FilterMask); }

    static PointF CalcOffsetByAngleDistance(float angle, float distance)
    {
        return PointF(cosf(angle) * distance, sinf(angle) * distance);
    }
};

class Filter : public RefCountBase<Filter, Stat_Default_Mem>
{
public:
    Filter(FilterType type) : Type(type), Frozen(false) {}

    FilterType GetFilterType() const { return Type; }
    bool       IsFrozen() const      { return Frozen; }
    void       Freeze()              { Frozen = true; }

    virtual Filter* Clone(MemoryHeap* heap = 0) const = 0;
    virtual bool    IsContributing() const = 0;

protected:
    FilterType Type;        // +0x10
    bool       Frozen;      // +0x14
};

class BlurFilterImpl : public Filter
{
public:
    BlurFilterImpl(FilterType type) : Filter(type), Distance(0), Angle(0)
    {
        Params.Mode &= ~BlurFilterParams::Mode_FilterMask;
        Params.Mode |= type;
    }
    BlurFilterImpl(FilterType type, const BlurFilterParams& params)
        : Filter(type), Params(params), Distance(0), Angle(0) {}

    const BlurFilterParams& GetParams() const              { return Params; }
    BlurFilterParams&       GetParams()                    { return Params; }
    void                    SetParams(const BlurFilterParams& p) { Params = p; }

    void     SetFlags(unsigned mode) { Params.Mode = (Params.Mode & ~BlurFilterParams::Mode_FlagsMask) | mode; }
    unsigned GetFlags() const        { return Params.Mode & BlurFilterParams::Mode_FlagsMask; }

    float  GetDistance() const { return Distance; }
    float  GetAngle() const    { return Angle; }
    PointF GetOffset() const   { return Params.Offset; }

    void SetAngleDistance(float angle, float distance)
    {
        Angle         = angle;
        Distance      = distance;
        Params.Offset = BlurFilterParams::CalcOffsetByAngleDistance(angle, distance);
    }

protected:
    BlurFilterParams Params;    // +0x18
    float            Distance;  // +0x3c twips
    float            Angle;     // +0x40 radians
};

class BlurFilter : public BlurFilterImpl
{
public:
    BlurFilter(float blurx = 4.0f, float blury = 4.0f, unsigned passes = 1) : BlurFilterImpl(Filter_Blur)
    {
        Params.BlurX  = PixelsToTwips(blurx);
        Params.BlurY  = PixelsToTwips(blury);
        Params.Passes = passes;
    }
    BlurFilter(const BlurFilterParams& params) : BlurFilterImpl(Filter_Blur, params) {}

    virtual Filter* Clone(MemoryHeap* heap = 0) const;
    virtual bool    IsContributing() const;
};

class ShadowFilter : public BlurFilterImpl
{
public:
    ShadowFilter(const BlurFilterParams& params, float angle, float dist) : BlurFilterImpl(Filter_Shadow, params)
    {
        SetAngleDistance(angle, PixelsToTwips(dist));
    }

    virtual Filter* Clone(MemoryHeap* heap = 0) const;
    virtual bool    IsContributing() const;
};

class GlowFilter : public BlurFilterImpl
{
public:
    GlowFilter(const BlurFilterParams& params) : BlurFilterImpl(Filter_Glow, params) {}

    virtual Filter* Clone(MemoryHeap* heap = 0) const;
    virtual bool    IsContributing() const;
};

class BevelFilter : public BlurFilterImpl
{
public:
    BevelFilter(const BlurFilterParams& params, float angle, float dist) : BlurFilterImpl(Filter_Bevel, params)
    {
        Params.Mode |= BlurFilterParams::Mode_Highlight;
        SetAngleDistance(angle, PixelsToTwips(dist));
    }

    virtual Filter* Clone(MemoryHeap* heap = 0) const;
    virtual bool    IsContributing() const;
};

class ColorMatrixFilter : public Filter
{
public:
    enum { ColorMatrixEntries = 20 };

    ColorMatrixFilter();
    ~ColorMatrixFilter() {}

    float  operator[](unsigned i) const { return i < ColorMatrixEntries ? MatrixData[i] : 0.0f; }
    float& operator[](unsigned i)       { return MatrixData[i]; }

    virtual Filter* Clone(MemoryHeap* heap = 0) const;
    virtual bool    IsContributing() const;

protected:
    float MatrixData[ColorMatrixEntries];   // +0x18, 4x4 multipliers then 4 offsets
};

class FilterSet : public RefCountBase<FilterSet, Stat_Default_Mem>
{
public:
    FilterSet(Filter* filter = 0);
    ~FilterSet() {}

    bool IsFrozen() const { return Frozen; }

    unsigned      GetFilterCount() const        { return (unsigned)Filters.GetSize(); }
    const Filter* GetFilter(UPInt index) const  { return Filters[index].GetPtr(); }
    void          SetFilter(UPInt index, Filter* f) { Filters[index] = f; }
    void          AddFilter(Filter* f)          { Filters.PushBack(f); }
    void          InsertFilterAt(UPInt index, Filter* f) { Filters.InsertAt(index, f); }
    void          RemoveFilterAt(UPInt index)   { Filters.RemoveAt(index); }
    void          RemoveFilter(Filter* f);

    const Array<Ptr<Filter> >& GetFilters() const { return Filters; }

    FilterSet* Clone(bool deepCopy = true, MemoryHeap* heap = 0) const;
    bool       IsContributing() const;

protected:
    Array<Ptr<Filter> > Filters;    // +0x10
    bool                Frozen;     // +0x28
};

}} // namespace Scaleform::Render

#endif
