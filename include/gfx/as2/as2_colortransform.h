// Recovered Scaleform 4.1.18 GFx AS2: flash.geom.ColorTransform (the transform is kept natively in the object).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_COLORTRANSFORM_H
#define MS2_SF_GFX_AS2_COLORTRANSFORM_H

#include "as2_movieroot.h"
#include "../../render/render_cxform.h"

namespace Scaleform { namespace GFx { namespace AS2 {

enum GFxColorTransform_Property
{
    GFxColorTransform_RedMultiplier,
    GFxColorTransform_GreenMultiplier,
    GFxColorTransform_BlueMultiplier,
    GFxColorTransform_AlphaMultiplier,
    GFxColorTransform_RedOffset,
    GFxColorTransform_GreenOffset,
    GFxColorTransform_BlueOffset,
    GFxColorTransform_AlphaOffset,
    GFxColorTransform_NumProperties
};

// The eight channel members of any object (exe 0x142948220).
void GFxObject_GetColorTransformProperties(Environment* penv, Object* pobj,
                                           Value params[GFxColorTransform_NumProperties]);

// ColorTransform instance; the transform sits 16-aligned after the object (+0x70).
class ColorTransformObject : public Object
{
public:
    Render::Cxform mColorTransform; // +0x70

    ColorTransformObject(Environment* penv); // exe 0x14291aee0

    // The transform with the factors clamped (exe 0x14294a580).
    const Render::Cxform GetCxform();
};

// The ColorTransform class.
class ColorTransformCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936c00
};

// ColorTransform.prototype methods.
class ColorTransformProto
{
public:
    static void Concat(const FnCall& fn);
    static void ToString(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
