// Recovered Scaleform 4.1.18 GFx AS2: flash.geom.ColorTransform (the transform is kept natively in the object).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_COLORTRANSFORM_H
#define MS2_SF_GFX_AS2_COLORTRANSFORM_H

#include "as2_movieroot.h"
#include "as2_objectproto.h"
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
    ColorTransformObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954210: Object_ColorTransform
    // exe 0x1429858c0 / 0x14294e940
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    // The transform with the factors clamped (exe 0x14294a580).
    const Render::Cxform GetCxform();
};

// The ColorTransform class.
class ColorTransformCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) Inlined into Register in the exe.
    ColorTransformCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936c00

    // new ColorTransform(8 numbers) sets the multipliers and offsets (exe 0x142959bc0).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "ColorTransform" (exe 0x142976900).
    static FunctionRef Register(GlobalContext* pgc);
};

// ColorTransform.prototype methods; the eight channels and rgb are added as plain members.
class ColorTransformProto : public Prototype<ColorTransformObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213010

    ColorTransformProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291af50

    static void Concat(const FnCall& fn);
    static void ToString(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS2::ColorTransformObject) == 0x90, "ColorTransformObject size");

#endif
