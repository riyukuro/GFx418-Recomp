// Recovered Scaleform 4.1.18 GFx AS2: flash.filters objects (the render filter is held natively).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BITMAPFILTER_H
#define MS2_SF_GFX_AS2_BITMAPFILTER_H

#include "as2_movieroot.h"
#include "../../render/render_filters.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Common base of the filter objects.
class BitmapFilterObject : public Object
{
public:
    Render::Filter* GetFilter() const { return pFilter; }
    void            SetFilter(Render::Filter* pfilter) { pFilter = pfilter; }

    Ptr<Render::Filter> pFilter; // +0x68
};

// The prototypes only add clone().
class DropShadowFilterProto
{
public:
    static void Clone(const FnCall& fn);
};

class GlowFilterProto
{
public:
    static void Clone(const FnCall& fn);
};

class BlurFilterProto
{
public:
    static void Clone(const FnCall& fn);
};

// The instance classes of the filters (0x70 bytes, all state in the render filter).
class BevelFilterObject : public BitmapFilterObject {};
class BlurFilterObject : public BitmapFilterObject {};
class ColorMatrixFilterObject : public BitmapFilterObject {};
class DropShadowFilterObject : public BitmapFilterObject {};
class GlowFilterObject : public BitmapFilterObject {};

}}} // namespace Scaleform::GFx::AS2

#endif
