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

    // Alpha of the first filter color, 0..1 (exe 0x1429497f0).
    float GetAlpha() const;

    // The filter itself, cloned first when it is shared (frozen).
    Render::Filter* writableFilter()
    {
        if (pFilter && pFilter->IsFrozen())
            pFilter = *pFilter->Clone(Memory::GetHeapByAddress(this));
        return pFilter;
    }
    // Shadow angle in radians; the offset follows (exe 0x14297fac0).
    void SetAngle(float a);
    // Shadow distance in twips (exe 0x142981320).
    void SetDistance(float d);

protected:
    // The blur parameters of the filter (exe 0x142995370).
    const Render::BlurFilterParams& readonlyFilterParams() const;
    // The same after writableFilter; a shared dummy for a non-blur filter (exe 0x142996690).
    Render::BlurFilterParams& writableFilterParams();

    virtual void Finalize_GC(); // exe 0x142942cf0
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
class ColorMatrixFilterObject : public BitmapFilterObject
{
public:
    ColorMatrixFilterObject(Environment* penv); // exe 0x14291ab70
};
class DropShadowFilterObject : public BitmapFilterObject {};
class GlowFilterObject : public BitmapFilterObject {};

// The ColorMatrixFilter class.
class ColorMatrixFilterCtorFunction : public CFunctionObject
{
public:
    ColorMatrixFilterCtorFunction(ASStringContext* psc); // exe 0x14291aaf0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936bc0

    static void GlobalCtor(const FnCall& fn); // exe 0x1429598b0
};

// The classes of the other filters.
class BevelFilterCtorFunction : public CFunctionObject
{
public:
    BevelFilterCtorFunction(ASStringContext* psc); // exe 0x142918d10

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429368c0

    static void GlobalCtor(const FnCall& fn); // exe 0x142958720
};

class BlurFilterCtorFunction : public CFunctionObject
{
public:
    BlurFilterCtorFunction(ASStringContext* psc); // exe 0x1429197b0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936940

    static void GlobalCtor(const FnCall& fn); // exe 0x1429591e0
};

class DropShadowFilterCtorFunction : public CFunctionObject
{
public:
    DropShadowFilterCtorFunction(ASStringContext* psc); // exe 0x14291b750

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936c80

    static void GlobalCtor(const FnCall& fn); // exe 0x14295a4b0
};

class GlowFilterCtorFunction : public CFunctionObject
{
public:
    GlowFilterCtorFunction(ASStringContext* psc); // exe 0x14291cd60

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e90

    static void GlobalCtor(const FnCall& fn); // exe 0x14295b480
};

}}} // namespace Scaleform::GFx::AS2

#endif
